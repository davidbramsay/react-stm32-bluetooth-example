# react-stm32-bluetooth-example


This is an example that combines a React Native BLE application (in
ReactNativeBLETest) with an STM32 application that sends BLE packets.

In the current form, the iPhone app will list BLE devices, connect to the named
one, and will recieve notification events when the button on the dev-kit is
pressed, which capture and send the RTC clock timestamp.

The app also has a button which will toggle the LED on the dev-kit on and off,
and will pass/set the RTC timestamp to match the true current date and time.
