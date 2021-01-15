/**
  ******************************************************************************
  * @file    udp.c
  * @author  MCD Application Team
  * @brief   This file contains the UDP interface shared between M0 and
  *          M4.
  ******************************************************************************
  * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "stm32wbxx_hal.h"

#include "stm32wbxx_core_interface_def.h"
#include "tl_thread_hci.h"

/* Include definition of compilation flags requested for OpenThread configuration */
#include OPENTHREAD_CONFIG_FILE

#include "udp.h"

extern otUdpReceive otUdpReceiveCb;


otMessage *otUdpNewMessage(otInstance *aInstance, bool aLinkSecurityEnabled)
{
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_UDP_NEW_MESSAGE;

    p_ot_req->Size=1;
    p_ot_req->Data[0] = (uint32_t)aLinkSecurityEnabled;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    return (otMessage*)p_ot_req->Data[0];
}

otError otUdpOpen(otInstance *aInstance, otUdpSocket *aSocket, otUdpReceive aCallback, void *aContext)
{
    Pre_OtCmdProcessing();
    otUdpReceiveCb = aCallback;
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_UDP_OPEN;

    p_ot_req->Size=2;
    p_ot_req->Data[0] = (uint32_t)aSocket;
    p_ot_req->Data[1] = (uint32_t)aContext;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    return (otError)p_ot_req->Data[0];
}

otError otUdpClose(otUdpSocket *aSocket)
{
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_UDP_CLOSE;

    p_ot_req->Size=1;
    p_ot_req->Data[0] = (uint32_t)aSocket;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    return (otError)p_ot_req->Data[0];
}

otError otUdpBind(otUdpSocket *aSocket, otSockAddr *aSockName)
{
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_UDP_BIND;

    p_ot_req->Size=2;
    p_ot_req->Data[0] = (uint32_t)aSocket;
    p_ot_req->Data[1] = (uint32_t)aSockName;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    return (otError)p_ot_req->Data[0];
}

otError otUdpConnect(otUdpSocket *aSocket, otSockAddr *aSockName)
{
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_UDP_CONNECT;

    p_ot_req->Size=2;
    p_ot_req->Data[0] = (uint32_t)aSocket;
    p_ot_req->Data[1] = (uint32_t)aSockName;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    return (otError)p_ot_req->Data[0];
}

otError otUdpSend(otUdpSocket *aSocket, otMessage *aMessage, const otMessageInfo *aMessageInfo)
{
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_UDP_SEND;

    p_ot_req->Size=3;
    p_ot_req->Data[0] = (uint32_t)aSocket;
    p_ot_req->Data[1] = (uint32_t)aMessage;
    p_ot_req->Data[2] = (uint32_t)aMessageInfo;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    return (otError)p_ot_req->Data[0];
}

void otUdpProxySetSender(otInstance *aInstance, otUdpProxySender aSender, void *aContext)
{
  Pre_OtCmdProcessing();
  /* prepare buffer */
  Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

  p_ot_req->ID = MSG_M4TOM0_OT_UDP_PROXY_SET_SENDER;

  p_ot_req->Size=2;
  p_ot_req->Data[0] = (uint32_t)aSender;
  p_ot_req->Data[1] = (uint32_t)aContext;

  Ot_Cmd_Transfer();
}

void otUdpProxyReceive(otInstance *        aInstance,
                       otMessage *         aMessage,
                       uint16_t            aPeerPort,
                       const otIp6Address *aPeerAddr,
                       uint16_t            aSockPort)
{
  Pre_OtCmdProcessing();
  /* prepare buffer */
  Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

  p_ot_req->ID = MSG_M4TOM0_OT_UDP_PROXY_RECEIVE;

  p_ot_req->Size=4;
  p_ot_req->Data[0] = (uint32_t)aMessage;
  p_ot_req->Data[1] = (uint32_t)aPeerPort;
  p_ot_req->Data[2] = (uint32_t)aPeerAddr;
  p_ot_req->Data[3] = (uint32_t)aSockPort;

  Ot_Cmd_Transfer();
}
