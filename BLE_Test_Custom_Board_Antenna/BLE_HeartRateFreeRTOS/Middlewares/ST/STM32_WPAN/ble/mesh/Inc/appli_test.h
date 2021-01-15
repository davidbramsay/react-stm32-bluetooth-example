/**
******************************************************************************
* @file    appli_test.h
* @author  BLE Mesh Team
* @brief   Header file for the serial interface file 
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
#ifndef __APPLI_TEST_H
#define __APPLI_TEST_H

/* Includes ------------------------------------------------------------------*/
#include "types.h"

/* Exported macro ------------------------------------------------------------*/
#define     TEST_1_WAIT_PERIOD          2000
#define     TEST_2_WAIT_PERIOD          100
#define     TEST_3_WAIT_PERIOD          3000
#define     TEST_READ_PERIOD            2000
#define     CLOCK_FLAG_ENABLE           1 
#define     CLOCK_FLAG_DISABLE          0 
#define     DATA_BYTE_SEND              50
/* Exported variables  ------------------------------------------------------- */
/* Exported Functions Prototypes ---------------------------------------------*/
void SerialResponse_Process(char *rcvdStringBuff, uint16_t rcvdStringSize);
MOBLE_RESULT Test_ApplicationTest_Set01(MOBLEUINT32 testCount,MOBLE_ADDRESS src ,MOBLE_ADDRESS dst);
MOBLE_RESULT Packet_ResponseTimeStamp(MOBLEUINT32 rcvTimeStamp);
MOBLE_RESULT Test_ApplicationTest_Set02(MOBLEUINT32 testCount ,MOBLE_ADDRESS src ,MOBLE_ADDRESS dst);
MOBLE_RESULT Test_ApplicationTest_Set03(MOBLE_ADDRESS src ,MOBLE_ADDRESS dst);
MOBLEUINT8 processDelay(MOBLEUINT16 waitPeriod);                                               


#endif /* __RESPONSE_TEST_H */

/******************* (C) COPYRIGHT 2020 STMicroelectronics *****END OF FILE****/

