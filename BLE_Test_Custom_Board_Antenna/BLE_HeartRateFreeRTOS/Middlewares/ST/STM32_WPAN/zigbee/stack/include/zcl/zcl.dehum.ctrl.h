/**
 * @file zcl.dehum.ctrl.h
 * @brief ZCL Dehumidification Control cluster header
 * ZCL 7 section 6.5
 * ZCL 8 section 6.5
 * @copyright Copyright [2009 - 2020] Exegin Technologies Limited. All rights reserved.
 */

#ifndef ZCL_DEHUM_CTRL_H
#define ZCL_DEHUM_CTRL_H

#include "zcl/zcl.h"

/* Dehumidification Control cluster interface definition */

/** Dehumidification Control Attribute Ids */
enum ZbZclDehumCtrlServerAttrT {
    ZCL_DEHUM_CTRL_SVR_ATTR_REL_HUM = 0x0000, /**< RelativeHumidity */
    ZCL_DEHUM_CTRL_SVR_ATTR_DEHUM_COOLING = 0x0001, /**< DehumidificationCooling */
    ZCL_DEHUM_CTRL_SVR_ATTR_RHDH_SETPT = 0x0010, /**< RHDehumidificationSetpoint */
    ZCL_DEHUM_CTRL_SVR_ATTR_RH_MODE = 0x0011, /**< RelativeHumidityMode */
    ZCL_DEHUM_CTRL_SVR_ATTR_DH_LOCKOUT = 0x0012, /**< DehumidificationLockout */
    ZCL_DEHUM_CTRL_SVR_ATTR_DH_HYS = 0x0013, /**< DehumidificationHysteresis */
    ZCL_DEHUM_CTRL_SVR_ATTR_DH_MAX_COOL = 0x0014, /**< DehumidificationMaxCool */
    ZCL_DEHUM_CTRL_SVR_ATTR_RH_DISPLAY = 0x0015 /**< RelativeHumidityDisplay */
};

/* Dehumidification Control cluster defines */
#define ZCL_DEHUM_CTRL_UNKNOWN                      0xff
#define ZCL_DEHUM_CTRL_RHDH_SETPT_DEFAULT           0x32
#define ZCL_DEHUM_CTRL_DH_HYS_DEFAULT               0x02
#define ZCL_DEHUM_CTRL_DH_MAX_COOL_DEFAULT          0x14

/* Dehumidification Control cluster function prototypes */
/**
 * Instantiate a new instance of the Dehumidification Control client cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclDehumCtrlClientAlloc(struct ZigBeeT *zb, uint8_t endpoint);

/**
 * Instantiate a new instance of the Dehumidification Control server cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclDehumCtrlServerAlloc(struct ZigBeeT *zb, uint8_t endpoint);

#endif
