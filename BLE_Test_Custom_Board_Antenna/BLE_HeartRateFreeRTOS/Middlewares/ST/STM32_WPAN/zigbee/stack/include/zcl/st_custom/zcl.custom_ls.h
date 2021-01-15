/*****************************************************************************
 * @file    zcl.custom_ls.h
 * @author  MCD Application Team
 * @brief   This file contains the interface of the Custom Long String cluster.
 *
 *****************************************************************************
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

#ifndef ZCL_CUSTOM_LS_H
#define ZCL_CUSTOM_LS_H

/*--------------------------------------------------------------------------
 *  DESCRIPTION
 *      Interface definition for the Custom Long String cluster.
 *--------------------------------------------------------------------------
 */

/* Custom Cluster ID */
#define ZCL_CLUSTER_LS  0x80E1

/* Attribute Identifiers */
enum {
    ZCL_CUSTOM_LS_ATTR = 0x0000,
    //ZCL_X_ATTR_TWO = 0x0001
};

/* Commands */
#define ZCL_SET_CUSTOM_LS_COMMAND_REQ          0x00
#define ZCL_CUSTOM_LS_COMMAND_RSP              0x01

/* Request structures */
struct set_custom_ls_command_req_t {
    char *string;
};


/* Response Structures */
struct custom_ls_command_rsp_t {
    uint16_t one;
};


enum ZclStatusCodeT
ZbZclSet_custom_ls_ClientCommand(struct ZbZclClusterT *cluster, struct ZbApsAddrT *dst, char *string,
    void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/* Callbacks */
struct zcl_custom_ls_server_callbacks_t {
    enum ZclStatusCodeT (*set_custom_ls_command)(struct ZbZclClusterT *clusterPtr, \
        struct set_custom_ls_command_req_t *cmd_req, struct ZbZclAddrInfoT *src_info, void *arg);
//    enum ZclStatusCodeT (*get_custom_ls_command)(struct ZbZclClusterT *clusterPtr, \
//        struct set_custom_ls_command_req_t *cmd_req, struct ZbZclAddrInfoT *src_info, void *arg);
};

/* Allocation Functions */
struct ZbZclClusterT * ZbZcl_custom_ls_ClientAlloc(struct ZigBeeT *zb, uint8_t endpoint);
struct ZbZclClusterT * ZbZcl_custom_ls_ServerAlloc(struct ZigBeeT *zb, uint8_t endpoint, \
          struct zcl_custom_ls_server_callbacks_t *callbacks, void *arg);

#endif /* ZCL_CUSTOM_LS_H */
