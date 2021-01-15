/**
 * @file zcl.press.meas.h
 * @brief ZCL Pressure Measurement cluster header
 * ZCL 7 section 4.5
 * ZCL 8 section 4.5
 * @copyright Copyright [2009 - 2020] Exegin Technologies Limited. All rights reserved.
 */

#ifndef ZCL_PRESS_MEAS_H
#define ZCL_PRESS_MEAS_H

#include "zcl/zcl.h"

/** Pressure Measurement Attribute IDs */
enum ZbZclPressMeasSvrAttrT {
    ZCL_PRESS_MEAS_ATTR_MEAS_VAL = 0x0000, /**< MeasuredValue */
    ZCL_PRESS_MEAS_ATTR_MIN_MEAS_VAL = 0x0001, /**< MinMeasuredValue */
    ZCL_PRESS_MEAS_ATTR_MAX_MEAS_VAL = 0x0002, /**< MaxMeasuredValue */
    ZCL_PRESS_MEAS_ATTR_TOLERANCE = 0x0003, /**< Tolerance (Optional) */
    ZCL_PRESS_MEAS_ATTR_SCALED_VAL = 0x0010, /**< ScaledValue (Optional) */
    ZCL_PRESS_MEAS_ATTR_MIN_SCALED_VAL = 0x0011, /**< MinScaledValue (Optional) */
    ZCL_PRESS_MEAS_ATTR_MAX_SCALED_VAL = 0x0012, /**< MaxScaledValue (Optional) */
    ZCL_PRESS_MEAS_ATTR_SCALED_TOL = 0x0013, /**< ScaledTolerance (Optional) */
    ZCL_PRESS_MEAS_ATTR_SCALE = 0x0014 /**< Scale (Optional) */
};

/* Pressure Measurement Defines */
#define ZCL_PRESS_MEAS_UNKNOWN                       (int16_t)0x8000
#define ZCL_PRESS_MEAS_MEAS_VAL_DEFAULT              (int16_t)0xffff
#define ZCL_PRESS_MEAS_MIN_VAL_MIN                   (int16_t)0x8001
#define ZCL_PRESS_MEAS_MIN_VAL_MAX                   (int16_t)0x7ffe
#define ZCL_PRESS_MEAS_MAX_VAL_MIN                   (int16_t)0x8002
#define ZCL_PRESS_MEAS_MAX_VAL_MAX                   (int16_t)0x7fff
#define ZCL_PRESS_MEAS_SCALE_MIN                        (int8_t)0x81
#define ZCL_PRESS_MEAS_SCALE_MAX                        (int8_t)0x7f

/**
 * Create a new instance of the Pressure Measurement Client cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclPressMeasClientAlloc(struct ZigBeeT *zb, uint8_t endpoint);

/**
 * Create a new instance of the Pressure Measurement Server cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @param min Default minimum measured value written to ZCL_PRESS_MEAS_ATTR_MIN_MEAS_VAL attribute during allocation
 * @param max Default maximum measured value written to ZCL_PRESS_MEAS_ATTR_MAX_MEAS_VAL attribute during allocation
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclPressMeasServerAlloc(struct ZigBeeT *zb, uint8_t endpoint, int16_t min, int16_t max);

#endif
