//BLE.js

import React, { Component }  from 'react';
import {
  View,
  Text,
  TouchableHighlight,
} from 'react-native';

import { BleManager } from "react-native-ble-plx";


Date.prototype.stdTimezoneOffset = function () {
var jan = new Date(this.getFullYear(), 0, 1);
var jul = new Date(this.getFullYear(), 6, 1);
return Math.max(jan.getTimezoneOffset(), jul.getTimezoneOffset());
}

Date.prototype.isDstObserved = function () {
    return this.getTimezoneOffset() < this.stdTimezoneOffset();
}


export default class BLE extends Component {

  constructor() {
    super()
    this.manager = new BleManager({
            restoreStateIdentifier: 'testBleBackgroundMode',
            restoreStateFunction: bleRestoredState => {

            if (bleRestoredState == null){
                console.log('BLE null, not restored.  Starting manager for the first time.')
            } else {

               console.log('BLE should be restored-- this might factor in when backgrounded >15min or autokilled by OS. It is currently untested.')
               /*
               bleRestoredState.connectedPeripherals[0].connect()
                    .then((device) => {
                        this.info("Discovering services and characteristics")
                        let r = device.discoverAllServicesAndCharacteristics()
                        console.log(r)
                        return r
                    }
              */
            }}})
    this.state = {info: "", values: {}, running_vals: [], writeCharacteristic: null, ledState: false}
    this.ble_devices = {};
  }

  info(message) {
    this.setState({info: message})
  }

  error(message) {
    this.setState({info: "ERROR: " + message})
  }

  updateValue(key, value) {
    hexval = this.reverseBytes(this.base64ToHex(value));
    console.log('update ' + key + ' : ' + hexval)
    this.setState({values: {...this.state.values, [key]: hexval}, running_vals: [...this.state.running_vals, hexval]})
    console.log(this.state.running_vals);
  }

  getDateInBCD(format12 = true) {
    //returns DAY (1byte) MONTH (1byte) DATE (1byte) YEAR (1byte) HR (1byte)
    //MIN (1byte) SEC (1byte) 12HRFORMAT (1byte, 0=24HR) AMorPM (1byte, 0=AM) 
    //DAYLIGHTSAVINGS (1byte, 0=None 1=Add1hr) 
    //all as a string

    console.log('Constructing Date...')
    //BCD means we use 0x01-0x12, skipping 0x0A-0x0F (hex *reads* right)
    var day = ("0" + new Date().getDay()).slice(-2);          //uint8_t 0x01-0x07, Mon-Sun
    var month = ("0" + (new Date().getMonth() + 1)).slice(-2);  //uint8_t 0x01-0x12
    var date = ("0" + new Date().getDate()).slice(-2);        //uint8_t 0x01-0x31
    var year = String(new Date().getFullYear()).slice(-2);    //uint8_t 0x20

    var hour = new Date().getHours();    //uint8_t Hours 0x00-0x023 if RTC_HourFormat_24, 0x00 to 0x12 if RTC_HourFormat_12
    var min  = ("0" + new Date().getMinutes()).slice(-2); //uint8_t Min 0x00 to 0x59
    var sec  = ("0" + new Date().getSeconds()).slice(-2); //uint8_t Sec 0x00 to 0x59

    //uint8_t TimeFormat to 0x00 for FORMAT12_AM, 0x40 for FORMAT12_PM
    var formatAM = hour >= 12 ? 1 : 0;
    if (format12) { hour = hour % 12; hour = hour ? hour : 12;}
    hour = ("0" + hour).slice(-2);

    //uint32_t DayLightSavings; use RTC_DAYLIGHTSAVINGS_SUB1H, RTC_DAYLIGHTSAVINGS_ADD1H, or RTC_DAYLIGHTSAVING_NONE
    var daylight = new Date().isDstObserved() ? 1 : 0; // if 1, ADD1H; else NONE

    return day + month + date + year + hour + min + sec  + '0' + formatAM  + '0' + (format12 ? 1 :0) + '0' + daylight;

  }

  reverseBytes(str){
    //bytes are 2 chars long
    //both systems are Little Endian; transport protocol is Big Endian
    //thus, data always gets flipped in transit

    s = str.replace(/^(.(..)*)$/, "0$1"); // add a leading zero if needed
    var a = s.match(/../g);             // split number in groups of two
    a.reverse();                        // reverse the groups
    return a.join("");                // join the groups back together
  }


  base64ToHex(str) {
    const raw = atob(str);
    let result = '';
    for (let i = 0; i < raw.length; i++) {
        const hex = raw.charCodeAt(i).toString(16);
        result += (hex.length === 2 ? hex : '0' + hex);
    }
    return result.toUpperCase();
  }

  hexToBase64(str) {
    return btoa(str.match(/\w{2}/g).map(function(a) {
        return String.fromCharCode(parseInt(a, 16));
    }).join(""));
  }

  toggleLED(){
    console.log('toggle LED function called!')
    var newLedVal = !this.state.ledState
    if  (this.state.writeCharacteristic){
        if (newLedVal){
        var timestamp_string = this.getDateInBCD()
        this.state.writeCharacteristic.writeWithoutResponse(this.hexToBase64(this.reverseBytes('0101' + timestamp_string)))
        console.log('wrote 0x0101' + timestamp_string + ' == ' + this.hexToBase64('0101' + timestamp_string))
        }
        else {
        this.state.writeCharacteristic.writeWithoutResponse(this.hexToBase64(this.reverseBytes('010089FEDCBA76543210')))
        console.log('wrote ' + this.hexToBase64('010089FEDCBA76543210'))
        }
        this.setState({ledState: newLedVal})
    }
  }

  componentDidMount() {
    if (Platform.OS === 'ios') {
      this.manager.onStateChange((state) => {
        if (state === 'PoweredOn') this.scanAndConnect()
      })
    } else {
      this.scanAndConnect()
    }
  }

  scanAndConnect() {
    this.manager.startDeviceScan(null,
                                 null, (error, device) => {
      this.info("Scanning...")
      console.log(device)

      if (error) {
        this.error(error.message)
        return
      }

      this.ble_devices[device.id] = {
            'name': device.name,
            'rssi': device.rssi
      }

      if (device.name === 'DRAMSAY') {
        this.info("connecting to DRAMSAY")
        this.manager.stopDeviceScan()
        device.connect()
          .then((device) => {
            this.info("Discovering services and characteristics")
            let r = device.discoverAllServicesAndCharacteristics()
            console.log(r)
            return r
          })
          .then((device) => {
            console.log('services')
            device.services()
              .then((services) => {
                  console.log(services)
                  console.log('characteristics')
                  for (s in services){
                      console.log(services[s])
                      device.characteristicsForService(services[s].uuid).then((c)=> {
                          for (i in c){
                              console.log(c[i])
                              if (c[i].isNotifiable){
                                  console.log('registering notifiable!!')
                                  device.monitorCharacteristicForService(c[i].serviceUUID, c[i].uuid, (error, characteristic) => {
                                  if (error) {
                                    console.log(error.message)
                                    this.error(error.message)
                                    return
                                  }
                                  this.updateValue(characteristic.uuid, characteristic.value)
                                  });
                              }
                              if (c[i].isWritableWithoutResponse){
                                  console.log('saving characteristic that is writable!!')
                                  this.setState({writeCharacteristic: c[i]})
                              }
                          }
                      })
                }
            })
          })
          .then(() => {
              this.info("Listening")
          }, (error) => {
              this.error(error.message)
              this.info(error.message)
          })
      }
    })
  }

  render() {
    return (
      <View>
        <Text>{this.state.info}</Text>
        {Object.keys(this.ble_devices).map((key) => {
            return <View key={key}>
                <Text style={{fontWeight:'bold',color:'red'}}>
                    {this.ble_devices[key]['name'] + ' : ' + this.ble_devices[key]['rssi']}
                </Text>
                <Text key={key}>
                {key}
                </Text>
                </View>
        })}

        {Object.keys(this.state.values).map((key) => {
          return <Text key={key}>
                   {"\n" + key + ": " + (this.state.values[key])}
                 </Text>
        })}

        {this.state.values['0000fe42-8e22-4541-9d4c-21edae82ed19']=='0101'
            ?
            <Text> Button Pushed
            </Text>
            :
            <Text> Button NOT Pushed
            </Text>
        }

        {/*
        <TouchableHighlight style={ this.state.ledState ? {{borderColor:'green'}} : {{borderColor:'red'}}} onPress=toggleLED>
        */}
        <TouchableHighlight style={{borderColor: this.state.ledState ? 'green' : 'red', borderWidth: 4, borderRadius: 10, height:30, width:100, justifyContent:'center', alignItems:'center'}} onPress={this.toggleLED.bind(this)} >
            <Text>LED IS {this.state.ledState ? 'on' : 'off'}</Text>
        </TouchableHighlight>

        {this.state.running_vals.map((val) => {
          return <Text key={val}>
                   {"\n" + val}
                 </Text>
        })}
      </View>
    )

  }
};

