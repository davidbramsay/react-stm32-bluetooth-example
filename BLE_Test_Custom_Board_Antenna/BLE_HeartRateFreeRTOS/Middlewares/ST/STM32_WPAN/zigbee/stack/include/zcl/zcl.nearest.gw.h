/**
 * @file zcl.nearest.gw.h
 * @brief ZCL Nearest Gateway cluster header
 * ZCL 7 section 14.5
 * ZCL 8 section 14.5
 * @copyright Copyright [2009 - 2020] Exegin Technologies Limited. All rights reserved.
 */

#ifndef ZCL_NEAREST_GW_H
#define ZCL_NEAREST_GW_H

#include "zcl/zcl.h"

/* Nearest Gateway cluster interface definition */

/** Nearest Gateway Attribute Ids */
enum ZbZclNearestGwServerAttrT {
    ZCL_NEAREST_GW_SVR_ATTR_NEAREST_GW = 0x0000, /**< Nearest Gateway */
    ZCL_NEAREST_GW_SVR_ATTR_NEW_MOBILE_NODE = 0x0001, /**< New Mobile Node */
};

/* Nearest Gateway cluster defines */
#define ZCL_NEAREST_GW_DEFAULT_NEAREST_GW             0x0000
#define ZCL_NEAREST_GW_DEFAULT_NEW_MOBILE_NODE        0x0000

/* Nearest Gateway cluster function prototypes */
/**
 * Instantiate a new instance of the Nearest Gateway client cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclNearestGwClientAlloc(struct ZigBeeT *zb, uint8_t endpoint);

/**
 * Instantiate a new instance of the Nearest Gateway server cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclNearestGwServerAlloc(struct ZigBeeT *zb, uint8_t endpoint);

#endif
