/**
******************************************************************************
* @file    sensors_client.h
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
#ifndef __SENSORS_CLIENT_H
#define __SENSORS_CLIENT_H

/* Includes ------------------------------------------------------------------*/
#include "types.h"
#include "ble_mesh.h"


/* Exported macro ------------------------------------------------------------*/
/* Variable-------------------------------------------------------------------*/
#pragma pack(1)
typedef union  
{
  sensor_CadenceCbParam_t sSensor_CadenceParam;
  MOBLEUINT8 a_Cadence_param[sizeof(sensor_CadenceCbParam_t)]; 
} _Sensor_CadenceParam;

typedef union  
{
  sensor_SettingCbParams_t sSensor_SettingParam;
  MOBLEUINT8 a_Setting_param[sizeof(sensor_SettingCbParams_t)]; 
} _Sensor_SettingParam;


extern const sensor_server_cb_t SensorAppli_cb;

/******************************************************************************/
/********** Following Section defines the Opcodes for the Messages ************/
/******************************************************************************/


/* Exported Functions Prototypes ---------------------------------------------*/
MOBLE_RESULT SensorsModelClient_GetOpcodeTableCb(const MODEL_OpcodeTableParam_t **data, 
                                                 MOBLEUINT16 *length);

MOBLE_RESULT SensorsModelClient_GetStatusRequestCb(MODEL_MessageHeader_t *pmsgParam,
                                                   MOBLEUINT16 opcode, 
                                                   MOBLEUINT8 *pResponsedata, 
                                                   MOBLEUINT32 *plength, 
                                                   MOBLEUINT8 const *pRxData,
                                                   MOBLEUINT32 dataLength,
                                                   MOBLEBOOL response);

MOBLE_RESULT SensorsModelClient_ProcessMessageCb(MODEL_MessageHeader_t *pmsgParam,
                                                 MOBLEUINT16 opcode, 
                                                 MOBLEUINT8 const *pRxData, 
                                                 MOBLEUINT32 dataLength, 
                                                 MOBLEBOOL response);

MOBLE_RESULT SensorsClient_Descriptor_Get(MOBLEUINT8 elementIndex, 
                                          MOBLEUINT8 * ppropertyId);

MOBLE_RESULT SensorsClient_Cadence_Get(MOBLEUINT8 elementIndex, 
                                       MOBLEUINT8 * ppropertyId);

MOBLE_RESULT SensorsClient_Cadence_Set(MOBLEUINT8 elementIndex, 
                                       MOBLEUINT8 *pCadence_param, 
                                       MOBLEUINT32 length);

MOBLE_RESULT SensorsClient_Cadence_Set_Unack(MOBLEUINT8 elementIndex, 
                                             MOBLEUINT8 *pCadence_param, 
                                             MOBLEUINT32 length); 

MOBLE_RESULT SensorsClient_Settings_Get(MOBLEUINT8 elementIndex, 
                                        MOBLEUINT8 * ppropertyId);

MOBLE_RESULT SensorsClient_Setting_Get(MOBLEUINT8 elementIndex, 
                                       MOBLEUINT8 * pparam,
                                       MOBLEUINT8 length);

MOBLE_RESULT SensorsClient_Setting_Set(MOBLEUINT8 elementIndex, 
                                       MOBLEUINT8 *pSetting_param, 
                                       MOBLEUINT32 length); 

MOBLE_RESULT SensorsClient_Setting_Set_Unack(MOBLEUINT8 elementIndex, 
                                             MOBLEUINT8 *pSetting_param, 
                                             MOBLEUINT32 length); 

MOBLE_RESULT SensorsClient_Get(MOBLEUINT8 elementIndex, 
                               MOBLEUINT8 * ppropertyId);

MOBLE_RESULT SensorsClient_Column_Get(MOBLEUINT8 elementIndex, 
                               MOBLEUINT8 * pparam,
                               MOBLEUINT8 length);

MOBLE_RESULT SensorsClient_Series_Get(MOBLEUINT8 elementIndex, 
                               MOBLEUINT8 * pparam,
                               MOBLEUINT8 length);

#endif /* __SENSORS_CLIENT */

/******************* (C) COPYRIGHT 2020 STMicroelectronics *****END OF FILE****/

