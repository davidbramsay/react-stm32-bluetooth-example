/**
******************************************************************************
* @file    light_client.c
* @author  BLE Mesh Team
* @brief   Generic model client middleware file
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
/* Includes ------------------------------------------------------------------*/
#include "hal_common.h"
#include "mesh_cfg.h"
#include "light.h"      //Included as Light LC model is included in Lightness Group for Client
#include "light_lc.h"
#include "light_client.h"
#include "common.h"
#include "models_if.h"
#include <string.h>
#include "compiler.h"

/** @addtogroup MODEL_CLIENT_LIGHT
*  @{
*/

/** @addtogroup Light_Model_Client_Callbacks
*  @{
*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
extern Model_Tid_t Model_Tid;;
const MODEL_OpcodeTableParam_t Light_Client_Opcodes_Table[] = 
{
  /* Light Lightness Client */
  /*    MOBLEUINT32 opcode, MOBLEBOOL reliable, MOBLEUINT16 min_payload_size, 
  MOBLEUINT16 max_payload_size;
  Here in this array, Handler is not defined; */
/* model_id                         opcode                                reliable     min_payload_size max_payload_size response_opcode                      min_response_size max_response_size */
                                                                                                                                                                          
#ifdef ENABLE_LIGHT_MODEL_CLIENT_LIGHTNESS  
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_GET,                  MOBLE_TRUE,  0,               0,                LIGHT_LIGHTNESS_STATUS,             2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_SET,                  MOBLE_TRUE,  3,               5,                LIGHT_LIGHTNESS_STATUS,             2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_SET_UNACK,            MOBLE_FALSE, 3,               5,                LIGHT_LIGHTNESS_STATUS,             2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_STATUS,               MOBLE_FALSE, 2,               5,                0,                                  2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_LINEAR_GET,           MOBLE_TRUE,  0,               0,                LIGHT_LIGHTNESS_LINEAR_STATUS,      2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_LINEAR_SET,           MOBLE_TRUE,  3,               5,                LIGHT_LIGHTNESS_LINEAR_STATUS,      2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_LINEAR_SET_UNACK,     MOBLE_FALSE, 3,               5,                LIGHT_LIGHTNESS_LINEAR_STATUS,      2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_LINEAR_STATUS,        MOBLE_FALSE, 2,               5,                0,                                  2,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_LAST_GET,             MOBLE_TRUE,  0,               0,                LIGHT_LIGHTNESS_LAST_STATUS,        2,                2},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_LAST_STATUS,          MOBLE_FALSE, 2,               2,                0,                                  2,                2},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_DEFAULT_GET,          MOBLE_TRUE,  0,               0,                LIGHT_LIGHTNESS_DEFAULT_STATUS,     2,                2},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_DEFAULT_SET,           MOBLE_TRUE,  2,               2,                LIGHT_LIGHTNESS_DEFAULT_STATUS,     2,                2},                 
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_DEFAULT_SET_UNACK,     MOBLE_FALSE, 2,               2,                0,                                  2,                2}, 
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_DEFAULT_STATUS,       MOBLE_FALSE, 2,               2,                0,                                  2,                2},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_RANGE_GET,            MOBLE_TRUE,  0,               0,                LIGHT_LIGHTNESS_RANGE_STATUS,       5,                5},
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_RANGE_SET,             MOBLE_TRUE,  4,               4,                LIGHT_LIGHTNESS_RANGE_STATUS,       5,                5},    
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_RANGE_SET_UNACK,       MOBLE_FALSE, 4,               4,                0,                                  5,                5}, 
  {LIGHT_LIGHTNESS_CLIENT_MODEL_ID, LIGHT_LIGHTNESS_RANGE_STATUS,         MOBLE_FALSE, 5,               5,                0,                                  5,                5},
#endif
                                                                                                                                                                        
                                                                                                                                                                        
#ifdef ENABLE_LIGHT_MODEL_CLIENT_CTL                                                                                                                                    
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_GET,                        MOBLE_TRUE,  0,               0,                LIGHT_CTL_STATUS,                   4,                9},     
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_SET,                        MOBLE_TRUE,  7,               9,                LIGHT_CTL_STATUS,                   4,                9},     
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_SET_UNACK,                  MOBLE_FALSE, 7,               9,                LIGHT_CTL_STATUS,                   4,                9},
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_STATUS,                     MOBLE_FALSE, 4,               9,                0,                                  4,                9},
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_DEFAULT_GET,                MOBLE_TRUE,  0,               0,                LIGHT_CTL_DEFAULT_STATUS,           6,                6},  
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_DEFAULT_SET,                 MOBLE_TRUE,  6,               6,                LIGHT_CTL_DEFAULT_STATUS,           6,                6},   
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_DEFAULT_SET_UNACK,           MOBLE_FALSE, 6,               6,                LIGHT_CTL_DEFAULT_STATUS,           6,                6}, 
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_DEFAULT_STATUS,             MOBLE_TRUE,  6,               6,                0,                                  6,                6},   
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_TEMPERATURE_GET,            MOBLE_TRUE,  0,               0,                LIGHT_CTL_TEMPERATURE_STATUS,       4,                9},
  {LIGHT_CTL_CLIENT_MODEL_ID, 	    LIGHT_CTL_TEMPERATURE_SET,             MOBLE_TRUE,  5,               7,                LIGHT_CTL_TEMPERATURE_STATUS,       4,                9},
  {LIGHT_CTL_CLIENT_MODEL_ID, 	    LIGHT_CTL_TEMPERATURE_SET_UNACK,       MOBLE_FALSE, 5,               7,                LIGHT_CTL_TEMPERATURE_STATUS,       4,                9},
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_TEMPERATURE_STATUS,         MOBLE_FALSE, 4,               9,                0,                                  4,                9},
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_TEMPERATURE_RANGE_GET,      MOBLE_TRUE,  0,               0,                LIGHT_CTL_TEMPERATURE_RANGE_STATUS, 5,                5},
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_TEMPERATURE_RANGE_SET,       MOBLE_TRUE,  4,               4,                LIGHT_CTL_TEMPERATURE_RANGE_STATUS, 5,                5},   
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_TEMPERATURE_RANGE_SET_UNACK, MOBLE_FALSE, 4,               4,                0,                                  5,                5},
  {LIGHT_CTL_CLIENT_MODEL_ID,       LIGHT_CTL_TEMPERATURE_RANGE_STATUS,   MOBLE_FALSE, 5,               5,                0,                                  5,                5},
#endif                                                                                                                                                                  
                                                                                                                                                                        
#ifdef ENABLE_LIGHT_MODEL_CLIENT_HSL
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_GET,                        MOBLE_TRUE,  0,               0,                LIGHT_HSL_STATUS,                   6,                7}, 
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_SET,                        MOBLE_TRUE,  7,               9,                LIGHT_HSL_STATUS,                   6,                7},   
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_SET_UNACK,                  MOBLE_FALSE, 7,               9,                LIGHT_HSL_STATUS,                   6,                7},    
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_STATUS,                     MOBLE_FALSE, 6,               7,                0,                                  6,                7},  
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_TARGET_GET,                 MOBLE_TRUE,  0,               0,                LIGHT_HSL_TARGET_STATUS,            6,                7}, 
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_TARGET_STATUS,              MOBLE_FALSE, 6,               7,                0,                                  6,                7},  
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_DEFAULT_GET,                MOBLE_TRUE,  0,               0,                LIGHT_HSL_DEFAULT_STATUS,           6,                6},  
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_DEFAULT_SET,                MOBLE_TRUE,  6,               6,                LIGHT_HSL_DEFAULT_STATUS,           6,                6},   
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_DEFAULT_SET_UNACK,          MOBLE_FALSE, 6,               6,                LIGHT_HSL_DEFAULT_STATUS,           6,                6},
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_DEFAULT_STATUS,             MOBLE_FALSE, 6,               6,                0,                                  6,                6},  
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_RANGE_GET,                  MOBLE_TRUE,  0,               0,                LIGHT_HSL_RANGE_STATUS,             9,                9},
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_RANGE_SET,                  MOBLE_TRUE,  8,               8,                LIGHT_HSL_RANGE_STATUS,             9,                9},   
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_RANGE_SET_UNACK,            MOBLE_FALSE, 8,               8,                0,                                  9,                9},  
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_RANGE_STATUS,               MOBLE_TRUE,  9,               9,                0,                                  9,                9},
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_HUE_GET,                    MOBLE_TRUE,  0,               0,                LIGHT_HSL_HUE_STATUS,               2,                5},   
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_HUE_SET,                    MOBLE_TRUE,  3,               5,                LIGHT_HSL_HUE_STATUS,               2,                5},   
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_HUE_SET_UNACK,              MOBLE_FALSE, 3,               5,                LIGHT_HSL_HUE_STATUS,               2,                5}, 
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_HUE_STATUS,                 MOBLE_FALSE, 2,               5,                0,                                  2,                5},   
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_SATURATION_GET,             MOBLE_TRUE,   0,              0,                LIGHT_HSL_SATURATION_STATUS,        2,                5},   
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_SATURATION_SET,             MOBLE_TRUE,   3,              5,                LIGHT_HSL_SATURATION_STATUS,        2,                5},    
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_SATURATION_SET_UNACK,       MOBLE_FALSE,  3,              5,                LIGHT_HSL_SATURATION_STATUS,        2,                5},    
  {LIGHT_HSL_CLIENT_MODEL_ID,       LIGHT_HSL_SATURATION_STATUS,          MOBLE_FALSE,  2,              5,                0,                                  2,                5},    
#endif

#ifdef ENABLE_LIGHT_MODEL_CLIENT_LC    
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_MODE_GET,                    MOBLE_TRUE,   0,               0,               LIGHT_LC_MODE_STATUS  ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_MODE_SET,                    MOBLE_TRUE,   1,               1,               LIGHT_LC_MODE_STATUS  ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_MODE_SET_UNACK,              MOBLE_FALSE,  1,               1,               LIGHT_LC_MODE_STATUS  ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_MODE_STATUS,                 MOBLE_FALSE,  1,               1,               0                     ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_OM_GET,                      MOBLE_TRUE,   0,               0,               LIGHT_LC_OM_STATUS    ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_OM_SET,                      MOBLE_TRUE,   1,               1,               LIGHT_LC_OM_STATUS    ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_OM_SET_UNACK,                MOBLE_FALSE,  1,               1,               LIGHT_LC_OM_STATUS    ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_OM_STATUS,                   MOBLE_FALSE,  1,               1,               0                     ,             1,                1},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_ON_OFF_GET,                  MOBLE_TRUE,   0,               0,               LIGHT_LC_ON_OFF_STATUS,             1,                3},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_ON_OFF_SET,                  MOBLE_TRUE,   2,               4,               LIGHT_LC_ON_OFF_STATUS,             1,                3},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_ON_OFF_SET_UNACK,            MOBLE_FALSE,  2,               4,               LIGHT_LC_ON_OFF_STATUS,             1,                3},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_ON_OFF_STATUS,               MOBLE_FALSE,  1,               3,               0                     ,             1,                3},                                                                          
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_PROPERTY_GET,                MOBLE_TRUE,   2,               2,               LIGHT_LC_PROPERTY_STATUS,           2,                10},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_PROPERTY_SET,                MOBLE_TRUE,   2,               10,              LIGHT_LC_PROPERTY_STATUS,           2,                10},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_PROPERTY_SET_UNACK,          MOBLE_FALSE,  2,               10,              LIGHT_LC_PROPERTY_STATUS,           2,                10},
 {LIGHT_LC_CLIENT_MODEL_ID,         LIGHT_LC_PROPERTY_STATUS,             MOBLE_FALSE,  2,               10,              0                       ,           2,                10}, 
#endif
  
  {0}
};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/******************************************************************************/
#ifdef ENABLE_LIGHT_MODEL_CLIENT_LIGHTNESS  
/******************************************************************************/
/**
* @brief  LightClient_Lightness_Get: This function is called to send Light Lightness Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Get(MOBLEUINT8 elementIndex) 

{
  /* 6.3.1.1 Light Lightness Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Lightness_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LIGHTNESS_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}

/**
* @brief  LightClient_Lightness_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightness_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightness_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.2 Light Lightness Set
  Lightness: 2B The target value of the Light Lightness Actual state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Set_Ack Client Message \r\n");  
  pLightness_param[2] = Model_Tid.TidSend;
  msg_buff = pLightness_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LIGHTNESS_SET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}

/**
* @brief  LightClient_Lightness_Set_Unack: This function is called for Unacknowledged message
* @param  elementIndex: Index of the element
* @param  pLightness_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightness_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.3 Light Lightness Set Unacknowledged
  Lightness: 2B The target value of the Light Lightness Actual state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/ 
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Set_Unack Client Message \r\n");  
  pLightness_param[2] = Model_Tid.TidSend;
  msg_buff = pLightness_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LIGHTNESS_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Lightness_Linear_Get: This function is called to send Light Lightness Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Linear_Get(MOBLEUINT8 elementIndex) 

{
  /* 
  6.3.1.5 Light Lightness Linear Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Lightness_Linear_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LIGHTNESS_LINEAR_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Lightness_Linear_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightnessLinear_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Linear_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightnessLinear_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.6 Light Lightness Linear Set
  Lightness: 2B The target value of the Light Lightness Linear state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Linear_Set_Ack Client Message \r\n");  
  pLightnessLinear_param[2] = Model_Tid.TidSend;
  msg_buff = pLightnessLinear_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LIGHTNESS_LINEAR_SET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Lightness_Linear_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightnessLinear_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Linear_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightnessLinear_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.7 Light Lightness Linear Set Unacknowledged
  Lightness: 2B The target value of the Light Lightness Linear state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Linear_Set_Unack Client Message \r\n");  
  pLightnessLinear_param[2] = Model_Tid.TidSend;
  msg_buff = pLightnessLinear_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LIGHTNESS_LINEAR_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Lightness_Default_Get: This function is called to send Light Default Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Default_Get(MOBLEUINT8 elementIndex) 

{
  /* 
  6.3.1.11 Light Lightness Default Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Lightness_Default_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LIGHTNESS_DEFAULT_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);

  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Lightness_Default_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightnessDefault_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Default_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightnessDefault_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.12 Light Lightness Default Set
  Lightness: 2B The value of the Light Lightness Default state.
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Default_Set_Ack Client Message \r\n");  
  msg_buff = pLightnessDefault_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LIGHTNESS_DEFAULT_SET;
  
  /* 
  Manage the TID Here....
  */
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Lightness_Default_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightnessDefault_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Default_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightnessDefault_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.13 Light Lightness Default Set Unacknowledged
  Lightness: 2B The value of the Light Lightness Default state.
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Default_Set_Unack Client Message \r\n");  
  msg_buff = pLightnessDefault_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LIGHTNESS_DEFAULT_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Lightness_Range_Get: This function is called to send Light Range Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Range_Get(MOBLEUINT8 elementIndex) 

{
  /* 
  6.3.1.15 Light Lightness Range Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Lightness_Range_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LIGHTNESS_RANGE_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);

  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Lightness_Range_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightnessRange_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Range_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightnessRange_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.16 Light Lightness Range Set
  Range Min: 2B The value of the Lightness Range Min field of the Light Lightness Range state.
  Range Max: 2B The value of the Lightness Range Max field of the Light Lightness Range state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Range_Set_Ack Client Message \r\n");  
  msg_buff = pLightnessRange_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LIGHTNESS_RANGE_SET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
               
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Lightness_Range_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightnessRange_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Lightness_Range_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightnessRange_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.1.17 Light Lightness Range Set Unacknowledged
  Range Min: 2B The value of the Lightness Range Min field of the Light Lightness Range state.
  Range Max: 2B The value of the Lightness Range Max field of the Light Lightness Range state
*/     
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Lightness_Range_Set_Unack Client Message \r\n");  
  msg_buff = pLightnessRange_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LIGHTNESS_RANGE_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LIGHTNESS_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
               
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}



/******************************************************************************/
#endif /* ENABLE_LIGHT_MODEL_CLIENT_LIGHTNESS  */
/******************************************************************************/

/******************************************************************************/
#ifdef ENABLE_LIGHT_MODEL_CLIENT_CTL
/******************************************************************************/
/**
* @brief  LightClient_Ctl_Get: This function is called to send Light CTL Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.2.1 Light CTL Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Ctl_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_CTL_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Ctl_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtl_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtl_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.2 Light CTL Set
  CTL Lightness: 2B The target value of the Light CTL Lightness state.
  CTL Temperature: 2B The target value of the Light CTL Temperature state.
  CTL Delta UV: 2B The target value of the Light CTL Delta UV state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Set_Ack Client Message \r\n");  
  pLightCtl_param[6] = Model_Tid.TidSend;
  msg_buff = pLightCtl_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_CTL_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Ctl_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtl_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtl_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.3 Light CTL Set Unacknowleged
  CTL Lightness: 2B The target value of the Light CTL Lightness state.
  CTL Temperature: 2B The target value of the Light CTL Temperature state.
  CTL Delta UV: 2B The target value of the Light CTL Delta UV state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Set_Unack Client Message \r\n");  
  pLightCtl_param[6] = Model_Tid.TidSend;
  msg_buff = pLightCtl_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_CTL_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}
 
  
/**
* @brief  LightClient_Ctl_Temperature_Get: This function is called to send Light CTL Temperature Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Temperature_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.2.5 Light CTL Temperature Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Ctl_Temperature_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_CTL_TEMPERATURE_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Ctl_Temperature_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtlTemperature_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Temperature_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtlTemperature_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.6 Light CTL Temperature Set
  CTL Temperature: 2B The target value of the Light CTL Temperature state.
  CTL Delta UV: 2B The target value of the Light CTL Delta UV state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Temperature_Temperature_Set_Ack Client Message \r\n");  
  pLightCtlTemperature_param[4] = Model_Tid.TidSend;
  msg_buff = pLightCtlTemperature_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_CTL_TEMPERATURE_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Ctl_Temperature_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtlTemperature_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Temperature_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtlTemperature_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.7 Light CTL Temperature Set Unacknowleged
  CTL Temperature: 2B The target value of the Light CTL Temperature state.
  CTL Delta UV: 2B The target value of the Light CTL Delta UV state.
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Temperature_Set_Unack Client Message \r\n");  
  pLightCtlTemperature_param[4] = Model_Tid.TidSend;
  msg_buff = pLightCtlTemperature_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_CTL_TEMPERATURE_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Ctl_Temperature_Range_Get: This function is called to send Light CTL Temperature Range Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Temperature_Range_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.2.9 Light CTL Temperature Range Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Ctl_Temperature_Range_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_CTL_TEMPERATURE_RANGE_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Ctl_Temperature_Range_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtlTemperatureRange_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Temperature_Range_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtlTemperatureRange_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.10 Light CTL Temperature Range Set
  Range Min: 2B The value of the Temperature Range Min field of the Light CTL Temperature Range state
  Range Max 2B The value of the Temperature Range Max field of the Light CTL Temperature Range state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Temperature_Temperature_Range_Set_Ack Client Message \r\n");  
  msg_buff = pLightCtlTemperatureRange_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_CTL_TEMPERATURE_RANGE_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
              
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Ctl_Temperature_Range_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtlTemperatureRange_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Temperature_Range_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtlTemperatureRange_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.11 Light CTL Temperature Range Set Unacknowleged
  Range Min: 2B The value of the Temperature Range Min field of the Light CTL Temperature Range state
  Range Max 2B The value of the Temperature Range Max field of the Light CTL Temperature Range state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Temperature_Range_Set_Unack Client Message \r\n");  
  msg_buff = pLightCtlTemperatureRange_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_CTL_TEMPERATURE_RANGE_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Ctl_Default_Get: This function is called to send Light CTL Default Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Default_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.2.13 Light CTL Default Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Ctl_Default_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_CTL_DEFAULT_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Ctl_Default_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtlDefault_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Default_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtlDefault_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.14 Light CTL Default Set
  CTL Lightness: 2B The target value of the Light CTL Lightness Default state.
  CTL Temperature: 2B The target value of the Light CTL Temperature Default state.
  CTL Delta UV: 2B The target value of the Light CTL Delta UV Default state.
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Default_Set_Ack Client Message \r\n");  
  msg_buff = pLightCtlDefault_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_CTL_DEFAULT_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
            
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Ctl_Default_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightCtlDefault_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Ctl_Default_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightCtlDefault_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.2.15 Light CTL Default Set Unacknowleged
  CTL Lightness: 2B The target value of the Light CTL Lightness Default state.
  CTL Temperature: 2B The target value of the Light CTL Temperature Default state.
  CTL Delta UV: 2B The target value of the Light CTL Delta UV Default state.
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Ctl_Default_Set_Unack Client Message \r\n");  
  msg_buff = pLightCtlDefault_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_CTL_DEFAULT_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_CTL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
              
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/******************************************************************************/
#endif /* ENABLE_LIGHT_MODEL_CLIENT_CTL  */
/******************************************************************************/


/******************************************************************************/
#ifdef ENABLE_LIGHT_MODEL_CLIENT_HSL
/******************************************************************************/
/**
* @brief  LightClient_Hsl_Get: This function is called to send Light HSL Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.3.1 Light HSL Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Hsl_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_HSL_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Hsl_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHsl_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHsl_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.2 Light HSL Set
  HSL Lightness: 2B The target value of the Light HSL Lightness state
  HSL Hue: 2B The target value of the Light HSL Hue state
  HSL Saturation: 2B The target value of the Light HSL Saturation state
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Set_Ack Client Message \r\n");  
  pLightHsl_param[6] = Model_Tid.TidSend;
  msg_buff = pLightHsl_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_HSL_SET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHsl_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHsl_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.3 Light HSL Set Unacknowleged
  HSL Lightness: 2B The target value of the Light HSL Lightness state
  HSL Hue: 2B The target value of the Light HSL Hue state
  HSL Saturation: 2B The target value of the Light HSL Saturation state
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Set_Ack Client Message \r\n");  
  pLightHsl_param[6] = Model_Tid.TidSend;
  msg_buff = pLightHsl_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_HSL_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Default_Get: This function is called to send Light HSL Default Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Default_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.3.15 Light HSL Default Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Hsl_Default_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_HSL_DEFAULT_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_Hsl_Default_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslDefault_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Default_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslDefault_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.16 Light HSL Default Set
  Lightness: 2B The value of the Light HSL Lightness Default state
  Hue: 2B The value of the Light HSL Hue Default state
  Saturation: 2B The value of the Light HSL Saturation Default state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Default_Set_Ack Client Message \r\n");  
  msg_buff = pLightHslDefault_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_HSL_DEFAULT_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Default_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslDefault_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Default_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslDefault_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.17 Light HSL Default Set Unacknowleged
  Lightness: 2B The value of the Light HSL Lightness Default state
  Hue: 2B The value of the Light HSL Hue Default state
  Saturation: 2B The value of the Light HSL Saturation Default state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Default_Set_Unack Client Message \r\n");  
  msg_buff = pLightHslDefault_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_HSL_DEFAULT_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Range_Get: This function is called to send Light HSL Range Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Range_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.3.19 Light HSL Range Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Hsl_Range_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_HSL_RANGE_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Range_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslRange_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Range_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslRange_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.20 Light HSL Range Set
  Hue Range Min: 2B The value of the Hue Range Min field of the Light HSL Hue Range state
  Hue Range Max: 2B The value of the Hue Range Max field of the Light HSL Hue Range state
  Saturation Range Min: 2B The value of the Saturation Range Min field of the Light HSL Saturation Range state
  Saturation Range Max: 2B The value of the Saturation Range Max field of the Light HSL Saturation Range state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Range_Set_Ack Client Message \r\n");  
  msg_buff = pLightHslRange_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_HSL_RANGE_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Range_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslRange_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Range_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslRange_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.21 Light HSL Range Set Unacknowleged
  Hue Range Min: 2B The value of the Hue Range Min field of the Light HSL Hue Range state
  Hue Range Max: 2B The value of the Hue Range Max field of the Light HSL Hue Range state
  Saturation Range Min: 2B The value of the Saturation Range Min field of the Light HSL Saturation Range state
  Saturation Range Max: 2B The value of the Saturation Range Max field of the Light HSL Saturation Range state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Range_Set_Unack Client Message \r\n");  
  msg_buff = pLightHslRange_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_HSL_RANGE_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
               
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Hue_Get: This function is called to send Light HSL Hue Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Hue_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.3.7 Light HSL Hue Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Hsl_Hue_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_HSL_HUE_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Hue_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslHue_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Hue_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslHue_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.8 Light HSL Hue Set
  HSL Hue: 2B The target value of the Light HSL Hue state
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
 
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Hue_Set_Ack Client Message \r\n"); 
  pLightHslHue_param[2] = Model_Tid.TidSend;
  msg_buff = pLightHslHue_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_HSL_HUE_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Hue_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslHue_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Hue_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslHue_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.9 Light HSL Hue Set Unacknowleged
  HSL Hue: 2B The target value of the Light HSL Hue state
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Hue_Set_Unack Client Message \r\n"); 
  pLightHslHue_param[2] = Model_Tid.TidSend;
  msg_buff = pLightHslHue_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_HSL_HUE_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
               
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


 






/**
* @brief  LightClient_Hsl_Saturation_Get: This function is called to send Light HSL Saturation Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Saturation_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.3.11 Light HSL Saturation Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_Hsl_Saturation_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_HSL_SATURATION_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Saturation_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslSaturation_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Saturation_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslSaturation_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.8 Light HSL Saturation Set
  HSL Saturation: 2B The target value of the Light HSL Saturation state
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
 
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Saturation_Set_Ack Client Message \r\n"); 
  pLightHslSaturation_param[2] = Model_Tid.TidSend;
  msg_buff = pLightHslSaturation_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_HSL_SATURATION_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
   /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_Hsl_Saturation_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightHslSaturation_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_Hsl_Saturation_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightHslSaturation_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.3.9 Light HSL Saturation Set Unacknowleged
  HSL Saturation: 2B The target value of the Light HSL Saturation state
  TID :  1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3. (Optional)
  Delay:1B Message execution delay in 5 milliseconds steps (C.1)
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_Hsl_Saturation_Set_Unack Client Message \r\n"); 
  pLightHslSaturation_param[2] = Model_Tid.TidSend;
  msg_buff = pLightHslSaturation_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_HSL_SATURATION_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_HSL_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
               
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++; 
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}
 

/******************************************************************************/
#endif /* ENABLE_LIGHT_MODEL_CLIENT_HSL  */
/******************************************************************************/


/******************************************************************************/
#ifdef ENABLE_LIGHT_MODEL_CLIENT_LC
/******************************************************************************/
/**
* @brief  LightClient_LC_Mode_Get: This function is called to send Light CTL Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_Mode_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.5.1.1 Light LC Mode Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_LC_Mode_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LC_MODE_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}



/**
* @brief  LightClient_LC_Mode_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCMode_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_Mode_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCMode_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.5.1.2 Light LC Mode Set
  Mode: 1B The target value of the Light LC Mode state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_Mode_Set_Ack Client Message \r\n");  

  msg_buff = pLightLCMode_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LC_MODE_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_Mode_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCMode_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_Mode_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCMode_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.5.1.3 Light LC Mode Set Unacknowledged
  Mode: 1B The target value of the Light LC Mode state
*/     
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_Mode_Set_Unack Client Message \r\n");  

  msg_buff = pLightLCMode_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LC_MODE_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}

/**
* @brief  LightClient_LC_OM_Get: This function is called to send Light CTL Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_OM_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.5.2.1 Light LC OM Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_LC_OM_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LC_OM_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_OM_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCOccupancyMode_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_OM_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCOccupancyMode_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.5.2.2 Light LC Mode Set
  Mode: 1B The target value of the Light LC Occupancy Mode state
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_OM_Set_Ack Client Message \r\n");  

  msg_buff = pLightLCOccupancyMode_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LC_OM_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_OM_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCOccupancyMode_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_OM_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCOccupancyMode_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.5.2.3 Light LC Mode Set Unacknowledged
  Mode: 1B The target value of the Light LC Occupancy Mode state
*/     
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_OM_Set_Unack Client Message \r\n");  

  msg_buff = pLightLCOccupancyMode_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LC_OM_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_OnOff_Get: This function is called to send Light CTL Get message
* @param  elementIndex : Index of the element
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_OnOff_Get(MOBLEUINT8 elementIndex) 
{
  /* 
  6.3.5.3.1 Light LC Light OnOff Get
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff = NULL; 
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_LC_OnOff_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LC_ON_OFF_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 0,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_OnOff_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCOnOff_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_OnOff_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCOnOff_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.5.3.2 Light LC Light OnOff Set
  Light OnOff: 1B The target value of the Light LC Light OnOff state
  TID: 1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3.
  Delay: 1B Message execution delay in 5 millisecond steps
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_OnOff_Set_Ack Client Message \r\n");  
  pLightLCOnOff_param[1] = Model_Tid.TidSend;
  msg_buff = pLightLCOnOff_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LC_ON_OFF_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++;
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }                 
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_OnOff_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCOnOff_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_OnOff_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCOnOff_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.5.3.3 Light LC Light OnOff Set Unacknowledged
  Light OnOff: 1B The target value of the Light LC Light OnOff state
  TID: 1B Transaction Identifier
  Transition Time: 1B Format as defined in Section 3.1.3.
  Delay: 1B Message execution delay in 5 millisecond steps
*/     
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_OnOff_Set_Unack Client Message \r\n");  
  pLightLCOnOff_param[1] = Model_Tid.TidSend;
  msg_buff = pLightLCOnOff_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LC_ON_OFF_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
  /* 
  Manage the TID
  */
  Model_Tid.TidSend++;
  if(Model_Tid.TidSend >= MAX_TID_VALUE)
  {
    Model_Tid.TidSend = 0;
  }              
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}

/**
* @brief  LightClient_LC_Property_Get: This function is called to send Light CTL Get message
* @param  elementIndex : Index of the element
* @param  pPropertyID : Property ID identifying a Light LC Property
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_Property_Get(MOBLEUINT8 elementIndex, MOBLEUINT8 *pPropertyID) 
{
  /* 
  6.3.6.1 Light LC Property Get
  Light LC Property ID: 2B Property ID identifying a Light LC Property.
  */
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT16 msg_opcode;
  MOBLEUINT8 const *msg_buff;
  MOBLEBOOL ack_flag = MOBLE_TRUE;

  msg_buff = pPropertyID;
  TRACE_M(TF_LIGHT_CLIENT_M, "LightClient_LC_Property_Get Client Message \r\n");  
  
  msg_opcode = LIGHT_LC_PROPERTY_GET;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                            elementIndex ,
                                            msg_opcode , 
                                            msg_buff, 2,
                                            ack_flag, 
                                            MOBLE_FALSE);
  
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M, "Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_Property_Set_Ack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCProperty_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_Property_Set_Ack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCProperty_param, 
                                     MOBLEUINT32 length) 

{
/*  
  6.3.6.2 Light LC Property Set
  Light LC Property ID: 2B Property ID identifying a Light LC Property.
  Light LC Property Value: [Variable] Raw value for the Light LC Property
*/   
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_Property_Set_Ack Client Message \r\n");  
  msg_buff = pLightLCProperty_param;
  ack_flag = MOBLE_TRUE;
  msg_opcode = LIGHT_LC_PROPERTY_SET;

  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);
           
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}


/**
* @brief  LightClient_LC_Property_Set_Unack: This function is called for Acknowledged message
* @param  elementIndex: Index of the element
* @param  pLightLCProperty_param: pointer to the parameters received for message
* @param  length:length of the data received
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightClient_LC_Property_Set_Unack(MOBLEUINT8 elementIndex, 
                                     MOBLEUINT8 *pLightLCProperty_param,
                                     MOBLEUINT32 length) 

{
/*  
  6.3.6.3 Light LC Property Set Unacknowledged
  Light LC Property ID: 2B Property ID identifying a Light LC Property.
  Light LC Property Value: [Variable] Raw value for the Light LC Property
*/      
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
  MOBLEUINT8 const *msg_buff; 
  MOBLEUINT16 msg_opcode;
  MOBLEBOOL ack_flag;
  
  TRACE_M(TF_LIGHT_CLIENT_M,"LightClient_LC_Property_Set_Unack Client Message \r\n");  
  msg_buff = pLightLCProperty_param;
  ack_flag = MOBLE_FALSE;
  msg_opcode = LIGHT_LC_PROPERTY_SET_UNACK;
  
  result = MeshClient_SetRemotePublication((MOBLEUINT32) LIGHT_LC_CLIENT_MODEL_ID, 
                                           elementIndex,
                                           msg_opcode , 
                                           msg_buff, length,
                                           ack_flag, 
                                           MOBLE_FALSE);            
  if(result)
  {
    TRACE_M(TF_LIGHT_CLIENT_M,"Publication Error \r\n");
  }  
  
  return result;
}



/******************************************************************************/
#endif /* ENABLE_LIGHT_MODEL_CLIENT_LC  */
/******************************************************************************/


/**
* @brief   LightModelClient_GetOpcodeTableCb: This function is call-back 
*          from the library to send Model Opcode Table info to library
* @param  MODEL_OpcodeTableParam_t:  Pointer to the Generic Model opcode array 
* @param  length: Pointer to the Length of Generic Model opcode array
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightModelClient_GetOpcodeTableCb(const MODEL_OpcodeTableParam_t **data, 
                                                 MOBLEUINT16 *length)
{
  *data = Light_Client_Opcodes_Table;
  *length = sizeof(Light_Client_Opcodes_Table)/sizeof(Light_Client_Opcodes_Table[0]);
  
  return MOBLE_RESULT_SUCCESS;
}

/**
* @brief  LightModelClient_GetStatusRequestCb : This function is call-back 
*         from the library to send response to the message from peer
* @param  *pmsgParam Pointer to structure of message header for parameters:
*          elementIndex, src, dst addresses, TTL, RSSI, NetKey & AppKey Offset
* @param  opcode: Received opcode of the Status message callback
* @param  pResponsedata: Pointer to the buffer to be updated with status
* @param  plength: Pointer to the Length of the data, to be updated by application
* @param  pRxData: Pointer to the data received in packet.
* @param  dataLength: length of the data in packet.
* @param  response: Value to indicate wheather message is acknowledged meassage or not.
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightModelClient_GetStatusRequestCb(MODEL_MessageHeader_t *pmsgParam, 
                                                   MOBLEUINT16 opcode, 
                                                   MOBLEUINT8 *pResponsedata, 
                                                   MOBLEUINT32 *plength, 
                                                   MOBLEUINT8 const *pRxData,
                                                   MOBLEUINT32 dataLength,
                                                   MOBLEBOOL response)

{
  TRACE_M(TF_LIGHT_CLIENT_M,"response status enable \n\r");
  
  return MOBLE_RESULT_SUCCESS;    
}

/**
* @brief LightModelClient_ProcessMessageCb: This is a callback function from
*        the library whenever a Generic Model message is received
* @param *pmsgParam Pointer to structure of message header for parameters:
*         elementIndex, src, dst addresses, TTL, RSSI, NetKey & AppKey Offset
* @param  opcode: Received opcode of the Status message callback
* @param  pData: Pointer to the buffer to be updated with status
* @param  length: Length of the parameters received 
* @param  response: if TRUE, the message is an acknowledged message
* @param  pRxData: Pointer to the data received in packet.
* @param  dataLength: length of the data in packet.
* @param  response: Value to indicate wheather message is acknowledged meassage or not.
* @retval MOBLE_RESULT
*/ 
MOBLE_RESULT LightModelClient_ProcessMessageCb(MODEL_MessageHeader_t *pmsgParam, 
                                                 MOBLEUINT16 opcode, 
                                                 MOBLEUINT8 const *pRxData, 
                                                 MOBLEUINT32 dataLength, 
                                                 MOBLEBOOL response
                                                   )
{
  
  MOBLE_RESULT result = MOBLE_RESULT_SUCCESS;
//  tClockTime delay_t = Clock_Time();
//  MOBLEUINT8 elementIndex = BLEMesh_ModelsGetElementIndex(pmsgParam->dst_peer);
 
  TRACE_M(TF_LIGHT_CLIENT_M, 
          "elementIndex = %.2x, dst_peer = %.2X , peer_add = %.2X, opcode= %.2X ,response= %.2X\r\n",
          pmsgParam->elementIndex,
          pmsgParam->dst_peer, 
          pmsgParam->peer_addr, 
          opcode, 
          response);
  
  switch(opcode)
  { 
  case LIGHT_LIGHTNESS_STATUS:
    {     
      Light_Client_Lightness_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_LIGHTNESS_LINEAR_STATUS:
    {     
      Light_Client_Lightness_Linear_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_LIGHTNESS_LAST_STATUS:
    {     
      Light_Client_Lightness_Last_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_LIGHTNESS_DEFAULT_STATUS:
    {     
      Light_Client_Lightness_Default_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_LIGHTNESS_RANGE_STATUS:
    {     
      Light_Client_Lightness_Range_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_CTL_STATUS:
    {     
      Light_Client_Ctl_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_CTL_TEMPERATURE_RANGE_STATUS:
    {     
      Light_Client_CtlTemperature_Range_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_CTL_TEMPERATURE_STATUS:
    {     
      Light_Client_CtlTemperature_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_CTL_DEFAULT_STATUS:
    {     
      Light_Client_CtlDefault_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_HSL_HUE_STATUS:
    {     
      Light_Client_HslHue_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_HSL_SATURATION_STATUS:
    {     
      Light_Client_HslSaturation_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_HSL_STATUS:
    {     
      Light_Client_Hsl_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_HSL_TARGET_STATUS:
    {     
      Light_Client_HslTarget_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_HSL_DEFAULT_STATUS:
    {     
      Light_Client_HslDefault_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_HSL_RANGE_STATUS:
    {     
      Light_Client_HslRange_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
#ifdef ENABLE_LIGHT_MODEL_CLIENT_LC  
  case LIGHT_LC_MODE_STATUS:
    {     
      LightLC_Client_Mode_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_LC_OM_STATUS:
    {     
      LightLC_Client_OM_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    }
  case LIGHT_LC_ON_OFF_STATUS:
    {     
      LightLC_Client_OnOff_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);         
      break;
    } 
  case LIGHT_LC_PROPERTY_STATUS:
    {
      LightLC_Client_Property_Status(pRxData, dataLength, pmsgParam->dst_peer, pmsgParam->elementIndex);               
      break;
    }
#endif
  default:
    {
      break;
    }
  }
  
  if((result == MOBLE_RESULT_SUCCESS) && (response == MOBLE_TRUE))
  {
    Model_SendResponse(pmsgParam, opcode, pRxData, dataLength);
  }
  
  return MOBLE_RESULT_SUCCESS;
}

/**
* @}
*/

/**
* @}
*/

/******************* (C) COPYRIGHT 2020 STMicroelectronics *****END OF FILE****/

