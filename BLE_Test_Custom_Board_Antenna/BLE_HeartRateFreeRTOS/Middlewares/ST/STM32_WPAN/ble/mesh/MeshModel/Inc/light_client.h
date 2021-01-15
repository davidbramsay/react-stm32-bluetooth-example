/**
******************************************************************************
* @file    light_client.h
* @author  BLE Mesh Team
* @brief   Header file for the user application file 
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under Ultimate Liberty license
* SLA0044, the "License"; You may not use this file except in compliance with
* the License. You may obtain a copy of the License at:
*                             www.st.com/SLA0044
*
******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LIGHT_CLIENT_H
#define __LIGHT_CLIENT_H

/* Includes ------------------------------------------------------------------*/
#include "types.h"
#include "ble_mesh.h"


/* Exported macro ------------------------------------------------------------*/
#define LIGHT_LIGHTNESS_CLIENT_MODEL_ID         0x1302
/* Variable ------------------------------------------------------------------*/
#pragma pack(1)
typedef union  {
  Light_LightnessParam_t sLight_LightnessParam;
  MOBLEUINT8 a_Lightness_param[sizeof(Light_LightnessParam_t)]; 
} _Light_LightnessParam;

  
/******************************************************************************/
/********** Following Section defines the Opcodes for the Messages ************/
/******************************************************************************/


/* Exported Functions Prototypes ---------------------------------------------*/
MOBLE_RESULT LightModelClient_GetOpcodeTableCb(const MODEL_OpcodeTableParam_t **data, 
                                               MOBLEUINT16 *length);

MOBLE_RESULT LightModelClient_GetStatusRequestCb(MODEL_MessageHeader_t* pmsgParam, 
                                                 MOBLEUINT16 opcode, 
                                                 MOBLEUINT8 *pResponsedata, 
                                                 MOBLEUINT32 *plength, 
                                                 MOBLEUINT8 const *pRxData,
                                                 MOBLEUINT32 dataLength,
                                                 MOBLEBOOL response);

MOBLE_RESULT LightModelClient_ProcessMessageCb(MODEL_MessageHeader_t* pmsgParam, 
                                               MOBLEUINT16 opcode, 
                                               MOBLEUINT8 const *pRxData, 
                                               MOBLEUINT32 dataLength, 
                                               MOBLEBOOL response);

MOBLE_RESULT LightClient_Lightness_Get(MOBLEUINT8 elementIndex); 
MOBLE_RESULT LightClient_Lightness_Set_Ack(MOBLEUINT8 elementIndex,  
                                           MOBLEUINT8 *pLightness_param, 
                                           MOBLEUINT32 length);
MOBLE_RESULT LightClient_Lightness_Set_Unack(MOBLEUINT8 elementIndex,  
                                             MOBLEUINT8 *pLightness_param, 
                                             MOBLEUINT32 length);

MOBLE_RESULT LightClient_Lightness_Linear_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Lightness_Linear_Set_Ack(MOBLEUINT8 elementIndex, 
                                                  MOBLEUINT8 *pLightnessLinear_param, 
                                                  MOBLEUINT32 length);
MOBLE_RESULT LightClient_Lightness_Linear_Set_Unack(MOBLEUINT8 elementIndex, 
                                                    MOBLEUINT8 *pLightnessLinear_param, 
                                                    MOBLEUINT32 length);

MOBLE_RESULT LightClient_Lightness_Default_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Lightness_Default_Set_Ack(MOBLEUINT8 elementIndex, 
                                                   MOBLEUINT8 *pLightnessDefault_param, 
                                                   MOBLEUINT32 length);
MOBLE_RESULT LightClient_Lightness_Default_Set_Unack(MOBLEUINT8 elementIndex, 
                                                     MOBLEUINT8 *pLightnessDefault_param, 
                                                     MOBLEUINT32 length);

MOBLE_RESULT LightClient_Lightness_Range_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Lightness_Range_Set_Ack(MOBLEUINT8 elementIndex, 
                                                 MOBLEUINT8 *pLightnessRange_param, 
                                                 MOBLEUINT32 length);
MOBLE_RESULT LightClient_Lightness_Range_Set_Unack(MOBLEUINT8 elementIndex, 
                                                   MOBLEUINT8 *pLightnessRange_param, 
                                                   MOBLEUINT32 length);

MOBLE_RESULT LightClient_Ctl_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Ctl_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtl_param, 
                                     MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Ctl_Set_Unack(MOBLEUINT8 elementIndex, 
                                       MOBLEUINT8 *pLightCtl_param,
                                       MOBLEUINT32 length);

MOBLE_RESULT LightClient_Ctl_Temperature_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Ctl_Temperature_Set_Ack(MOBLEUINT8 elementIndex, 
                                                 MOBLEUINT8 *pLightCtlTemperature_param, 
                                                 MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Ctl_Temperature_Set_Unack(MOBLEUINT8 elementIndex, 
                                                   MOBLEUINT8 *pLightCtlTemperature_param,
                                                   MOBLEUINT32 length); 

MOBLE_RESULT LightClient_Ctl_Temperature_Range_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Ctl_Temperature_Range_Set_Ack(MOBLEUINT8 elementIndex, 
                                                       MOBLEUINT8 *pLightCtlTemperatureRange_param, 
                                                       MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Ctl_Temperature_Range_Set_Unack(MOBLEUINT8 elementIndex, 
                                                         MOBLEUINT8 *pLightCtlTemperatureRange_param,
                                                         MOBLEUINT32 length); 

MOBLE_RESULT LightClient_Ctl_Default_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Ctl_Default_Set_Ack(MOBLEUINT8 elementIndex, 
                                             MOBLEUINT8 *pLightCtlDefault_param, 
                                             MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Ctl_Default_Set_Unack(MOBLEUINT8 elementIndex, 
                                               MOBLEUINT8 *pLightCtlDefault_param,
                                               MOBLEUINT32 length); 

MOBLE_RESULT LightClient_Hsl_Get(MOBLEUINT8 elementIndex) ;
MOBLE_RESULT LightClient_Hsl_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHsl_param, 
                                     MOBLEUINT32 length); 

MOBLE_RESULT LightClient_Hsl_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHsl_param,
                                     MOBLEUINT32 length); 

MOBLE_RESULT LightClient_Hsl_Default_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Hsl_Default_Set_Ack(MOBLEUINT8 elementIndex, 
                                             MOBLEUINT8 *pLightHslDefault_param, 
                                             MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Hsl_Default_Set_Unack(MOBLEUINT8 elementIndex, 
                                               MOBLEUINT8 *pLightHslDefault_param,
                                               MOBLEUINT32 length); 
                                             
MOBLE_RESULT LightClient_Hsl_Range_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Hsl_Range_Set_Ack(MOBLEUINT8 elementIndex, 
                                           MOBLEUINT8 *pLightHslRange_param, 
                                           MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Hsl_Range_Set_Unack(MOBLEUINT8 elementIndex, 
                                             MOBLEUINT8 *pLightHslRange_param,
                                             MOBLEUINT32 length); 
 
MOBLE_RESULT LightClient_Hsl_Hue_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Hsl_Hue_Set_Ack(MOBLEUINT8 elementIndex, 
                                         MOBLEUINT8 *pLightHslHue_param, 
                                         MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Hsl_Hue_Set_Unack(MOBLEUINT8 elementIndex, 
                                           MOBLEUINT8 *pLightHslHue_param,
                                           MOBLEUINT32 length);

MOBLE_RESULT LightClient_Hsl_Saturation_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_Hsl_Saturation_Set_Ack(MOBLEUINT8 elementIndex, 
                                         MOBLEUINT8 *pLightHslSaturation_param, 
                                         MOBLEUINT32 length); 
MOBLE_RESULT LightClient_Hsl_Saturation_Set_Unack(MOBLEUINT8 elementIndex, 
                                           MOBLEUINT8 *pLightHslSaturation_param,
                                           MOBLEUINT32 length);

#ifdef ENABLE_LIGHT_MODEL_CLIENT_LC  
MOBLE_RESULT LightClient_LC_Mode_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_LC_Mode_Set_Ack(MOBLEUINT8 elementIndex, 
                                         MOBLEUINT8 *pLightLCMode_param, 
                                         MOBLEUINT32 length); 
MOBLE_RESULT LightClient_LC_Mode_Set_Unack(MOBLEUINT8 elementIndex, 
                                           MOBLEUINT8 *pLightLCMode_param,
                                           MOBLEUINT32 length);

MOBLE_RESULT LightClient_LC_OM_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_LC_OM_Set_Ack(MOBLEUINT8 elementIndex, 
                                       MOBLEUINT8 *pLightLCOccupancyMode_param, 
                                       MOBLEUINT32 length); 
MOBLE_RESULT LightClient_LC_OM_Set_Unack(MOBLEUINT8 elementIndex, 
                                         MOBLEUINT8 *pLightLCOccupancyMode_param,
                                         MOBLEUINT32 length);

MOBLE_RESULT LightClient_LC_OnOff_Get(MOBLEUINT8 elementIndex);
MOBLE_RESULT LightClient_LC_OnOff_Set_Ack(MOBLEUINT8 elementIndex, 
                                          MOBLEUINT8 *pLightLCOnOff_param, 
                                          MOBLEUINT32 length); 
MOBLE_RESULT LightClient_LC_OnOff_Set_Unack(MOBLEUINT8 elementIndex, 
                                            MOBLEUINT8 *pLightLCOnOff_param,
                                            MOBLEUINT32 length);

MOBLE_RESULT LightClient_LC_Property_Get(MOBLEUINT8 elementIndex, MOBLEUINT8 *pPropertyID);
MOBLE_RESULT LightClient_LC_Property_Set_Ack(MOBLEUINT8 elementIndex, 
                                             MOBLEUINT8 *pLightLCProperty_param, 
                                             MOBLEUINT32 length); 
MOBLE_RESULT LightClient_LC_Property_Set_Unack(MOBLEUINT8 elementIndex, 
                                               MOBLEUINT8 *pLightLCProperty_param,
                                               MOBLEUINT32 length);
#endif /* #ifdef ENABLE_LIGHT_MODEL_CLIENT_LC */

// Status
MOBLE_RESULT Light_Client_Lightness_Status(MOBLEUINT8 const *pLightness_status, 
                                           MOBLEUINT32 plength, 
                                           MOBLEUINT16 dstPeer, 
                                           MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_Lightness_Linear_Status(MOBLEUINT8 const *pLightnessLinear_status, 
                                                  MOBLEUINT32 pLength,
                                                  MOBLEUINT16 dstPeer,
                                                  MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_Lightness_Last_Status(MOBLEUINT8 const *pLightnessLast_status, 
                                                MOBLEUINT32 pLength,
                                                MOBLEUINT16 dstPeer,
                                                MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_Lightness_Default_Status(MOBLEUINT8 const *pLightnessDefault_status, 
                                                   MOBLEUINT32 pLength,
                                                   MOBLEUINT16 dstPeer,
                                                   MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_Lightness_Range_Status(MOBLEUINT8 const *pLightnessRange_status, 
                                                 MOBLEUINT32 pLength,
                                                 MOBLEUINT16 dstPeer,
                                                 MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_Ctl_Status(MOBLEUINT8 const *pLightCtl_status, 
                                     MOBLEUINT32 pLength,
                                     MOBLEUINT16 dstPeer,
                                     MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_CtlTemperature_Range_Status(MOBLEUINT8 const *pCtlTempRange_status, 
                                                      MOBLEUINT32 pLength,
                                                      MOBLEUINT16 dstPeer,
                                                      MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_CtlDefault_Status(MOBLEUINT8 const *pCtlDefault_status, 
                                            MOBLEUINT32 pLength,
                                            MOBLEUINT16 dstPeer,
                                            MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_CtlTemperature_Status(MOBLEUINT8 const *pLightCtlTemp_status, 
                                                MOBLEUINT32 pLength,
                                                MOBLEUINT16 dstPeer,
                                                MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_Hsl_Status(MOBLEUINT8 const *pHsl_status, 
                                     MOBLEUINT32 pLength,
                                     MOBLEUINT16 dstPeer,
                                     MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_HslDefault_Status(MOBLEUINT8 const *pHslDefault_status, 
                                            MOBLEUINT32 pLength,
                                            MOBLEUINT16 dstPeer,
                                            MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_HslRange_Status(MOBLEUINT8 const *pHslRange_status, 
                                          MOBLEUINT32 pLength,
                                          MOBLEUINT16 dstPeer,
                                          MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_HslTarget_Status(MOBLEUINT8 const *pHslTarget_status, 
                                           MOBLEUINT32 pLength,
                                           MOBLEUINT16 dstPeer,
                                           MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_HslHue_Status(MOBLEUINT8 const *pHslHue_status, 
                                        MOBLEUINT32 pLength,
                                        MOBLEUINT16 dstPeer,
                                        MOBLEUINT8 elementIndex);
MOBLE_RESULT Light_Client_HslSaturation_Status(MOBLEUINT8 const *pHslSaturation_status, 
                                               MOBLEUINT32 pLength,
                                               MOBLEUINT16 dstPeer,
                                               MOBLEUINT8 elementIndex);

MOBLE_RESULT LightLC_Client_Mode_Status(MOBLEUINT8 const *pLCMode_status, 
                                        MOBLEUINT32 plength, 
                                        MOBLEUINT16 dstPeer, 
                                        MOBLEUINT8 elementIndex);
MOBLE_RESULT LightLC_Client_OM_Status(MOBLEUINT8 const *pLCOccupancyMode_status, 
                                      MOBLEUINT32 plength, 
                                      MOBLEUINT16 dstPeer, 
                                      MOBLEUINT8 elementIndex);
MOBLE_RESULT LightLC_Client_OnOff_Status(MOBLEUINT8 const *pLCOnOff_status, 
                                         MOBLEUINT32 plength, 
                                         MOBLEUINT16 dstPeer, 
                                         MOBLEUINT8 elementIndex);
MOBLE_RESULT LightLC_Client_Property_Status(MOBLEUINT8 const *pLCProperty_status, 
                                            MOBLEUINT32 plength, 
                                            MOBLEUINT16 dstPeer, 
                                            MOBLEUINT8 elementIndex);
#endif /* __LIGHT_CLIENT_H */

/******************* (C) COPYRIGHT 2020 STMicroelectronics *****END OF FILE****/

