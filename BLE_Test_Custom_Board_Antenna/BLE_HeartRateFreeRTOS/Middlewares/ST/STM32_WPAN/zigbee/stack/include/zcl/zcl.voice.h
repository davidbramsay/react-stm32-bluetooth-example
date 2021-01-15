/**
 * @file zcl.voice.h
 * @brief ZCL Voice Over Zigbee cluster header
 * ZCL 7 section 12.4
 * ZCL 8 section 12.3
 * @copyright Copyright [2019 - 2020] Exegin Technologies Limited. All rights reserved.
 */

#ifndef ZCL_VOICE_H
#define ZCL_VOICE_H

/*--------------------------------------------------------------------------
 *  DESCRIPTION
 *      Interface definition for the Voice Over Zigbee cluster.
 *--------------------------------------------------------------------------
 */

#include "zcl/zcl.h"

/** Voice Over Zigbee Server Attribute IDs */
enum ZbZclVoiceSvrAttrT {
    ZCL_VOICE_ATTR_CODEC_TYPE = 0x0000, /**< CodecType */
    ZCL_VOICE_ATTR_SAMP_FREQ = 0x0001, /**< SamplingFrequency */
    ZCL_VOICE_ATTR_CODECRATE = 0x0002, /**< Codecrate */
    ZCL_VOICE_ATTR_ESTAB_TIMEOUT = 0x0003, /**< EstablishmentTimeout */
    ZCL_VOICE_ATTR_CODEC_TYPE_SUB_1 = 0x0004, /**< CodecTypeSub1 (Optional) */
    ZCL_VOICE_ATTR_CODEC_TYPE_SUB_2 = 0x0005, /**< CodecTypeSub2 (Optional) */
    ZCL_VOICE_ATTR_CODEC_TYPE_SUB_3 = 0x0006, /**< CodecTypeSub3 (Optional) */
    ZCL_VOICE_ATTR_COMPRESSION_TYPE = 0x0007, /**< CompressionType (Optional) */
    ZCL_VOICE_ATTR_COMPRESSION_RATE = 0x0008, /**< CompressionRate (Optional) */
    ZCL_VOICE_ATTR_OPTION_FLAGS = 0x0009, /**< OptionFlags (Optional) */
    ZCL_VOICE_ATTR_THRESHOLD = 0x000a /**< Threshold (Optional) */
};

/* Client Generated Commands */
enum {
    ZCL_VOICE_CLI_ESTAB_REQ = 0x00,
    ZCL_VOICE_CLI_VOICE_TX = 0x01,
    ZCL_VOICE_CLI_TX_COMPLETE = 0x02,
    ZCL_VOICE_CLI_CONTROL_RSP = 0x03
};

/* Server Generated Commands */
enum {
    ZCL_VOICE_SVR_ESTAB_RSP = 0x00,
    ZCL_VOICE_SVR_VOICE_TX_RSP = 0x01,
    ZCL_VOICE_SVR_CONTROL = 0x02
};

/* Voice of Zigbee Defined Values */
#define ZCL_VOICE_FLAG_CODEC_TYPE_SUB_1     0x01
#define ZCL_VOICE_FLAG_CODEC_TYPE_SUB_2     0x02
#define ZCL_VOICE_FLAG_CODEC_TYPE_SUB_3     0x04
#define ZCL_VOICE_FLAG_COMPRESSION          0x08

#define ZCL_VOICE_TX_RSP_ERROR_DECODE       0x00 /* Failure to decode voice data */
#define ZCL_VOICE_TX_RSP_ERROR_ORDER        0x01 /* Wrong order of voice data */

/* Request and Response Structures */

/** Establishment Request command structure */
struct voice_estab_req_t {
    uint8_t flag; /**< Flag */
    uint8_t codec_type; /**< Codec Type */
    uint8_t samp_freq; /**< Samp. Freq. */
    uint8_t codec_rate; /**< Codec Rate */
    uint8_t service_type; /**< Service Type */
    uint8_t codec_type_s1; /**< Codec TypeS1 */
    uint8_t codec_type_s2; /**< Codec TypeS2 */
    uint8_t codec_type_s3; /**< Codec TypeS3 */
    uint8_t comp_type; /**< Comp. Type */
    uint8_t comp_rate; /**< Comp. Rate */
};

/** Establishment Response command structure */
struct voice_estab_rsp_t {
    uint8_t ack_nak; /**< ACK=0x01 NAK=0x00 */
    uint8_t codec_type; /**< CodecType */
};

/** Voice Transmission command structure */
struct voice_voice_tx_t {
    uint8_t *voice_data; /**< Voice Data */
    uint16_t voice_data_len; /**< Voice Data Length */
};

/** Voice Transmission Response command structure */
struct voice_voice_tx_rsp_t {
    uint8_t error_flag; /**< Error Flag - e.g. ZCL_VOICE_TX_RSP_ERROR_DECODE */
};

/** Control command structure */
struct voice_control_t {
    uint8_t control_type; /**< Control Type */
};

/** Control Response command structure */
struct voice_control_rsp_t {
    uint8_t ack_nak; /**< ACK=0x01 NAK=0x00 */
};

/** Voice Over Zigbee Server callbacks configuration */
struct zcl_voice_server_callbacks_t {
    enum ZclStatusCodeT (*estab_req)(struct ZbZclClusterT *clusterPtr, struct voice_estab_req_t *cmd_req,
        struct ZbZclAddrInfoT *src_info, void *arg);
    /**< Callback to application, invoked on receipt of Establishment Request command */

    enum ZclStatusCodeT (*voice_tx)(struct ZbZclClusterT *clusterPtr, struct voice_voice_tx_t *cmd_req,
        struct ZbZclAddrInfoT *src_info, void *arg);
    /**< Callback to application, invoked on receipt of Voice Transmission command.
     * The application should return ZCL_STATUS_SUCCESS or call ZbZclVoiceServerSendVoiceTxRsp
     * to send an error response and return ZCL_STATUS_SUCCESS_NO_DEFAULT_RESPONSE
     */

    enum ZclStatusCodeT (*tx_complete)(struct ZbZclClusterT *clusterPtr,
        struct ZbZclAddrInfoT *src_info, void *arg);
    /**< Callback to application, invoked on receipt of Voice Transmission Completion command */
};

/** Voice Over Zigbee Client callbacks configuration */
struct zcl_voice_client_callbacks_t {
    enum ZclStatusCodeT (*control)(struct ZbZclClusterT *clusterPtr, struct voice_control_t *cmd_req,
        struct ZbZclAddrInfoT *src_info, void *arg);
    /**< Callback to application, invoked on receipt of Control command */
};

/* Client API */

/**
 * Create a new instance of the Voice Over Zigbee Client cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @param callbacks Structure containing any callback function pointers for this cluster
 * @param arg Pointer to application data that will later be provided back to the callback functions when invoked
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclVoiceClientAlloc(struct ZigBeeT *zb, uint8_t endpoint,
    struct zcl_voice_client_callbacks_t *callbacks, void *arg);

/**
 * Send an Establishment Request command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for request
 * @param estab_req Establishment Request command request structure
 * @param callback Callback function that will be invoked later when the response is received
 * @param arg Pointer to application data that will later be provided back to the callback function when invoked
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclVoiceClientEstabReq(struct ZbZclClusterT *cluster, const struct ZbApsAddrT *dst,
    struct voice_estab_req_t *estab_req, void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/**
 * Send a Voice Transmission command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for request
 * @param voice_tx Voice Transmission command request structure
 * @param callback Callback function that will be invoked later when the response is received
 * @param arg Pointer to application data that will later be provided back to the callback function when invoked
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclVoiceVoiceTxReq(struct ZbZclClusterT *cluster, const struct ZbApsAddrT *dst,
    struct voice_voice_tx_t *voice_tx, void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/**
 * Send a Voice Transmission Complete command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for request
 * @param callback Callback function that will be invoked later when the response is received
 * @param arg Pointer to application data that will later be provided back to the callback function when invoked
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclVoiceTxCompletedReq(struct ZbZclClusterT *cluster, const struct ZbApsAddrT *dst,
    void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/**
 * Send an Control command
 * @param cluster Cluster instance from which to send this command
 * @param dst_info Destination address for response, including sequence number and tx options
 * @param rsp Control command response structure
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclVoiceClientSendControlRsp(struct ZbZclClusterT *cluster, struct ZbZclAddrInfoT *dst_info,
    struct voice_control_rsp_t *rsp);

/* Server API */

/**
 * Create a new instance of the Voice Over Zigbee Server cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @param callbacks Structure containing any callback function pointers for this cluster
 * @param arg Pointer to application data that will later be provided back to the callback functions when invoked
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclVoiceServerAlloc(struct ZigBeeT *zb, uint8_t endpoint,
    struct zcl_voice_server_callbacks_t *callbacks, void *arg);

/**
 * Send a Control command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for request
 * @param control_cmd Control command request structure
 * @param callback Callback function that will be invoked later when the response is received
 * @param arg Pointer to application data that will later be provided back to the callback function when invoked
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclVoiceServerControlReq(struct ZbZclClusterT *cluster, const struct ZbApsAddrT *dst,
    struct voice_control_t *control_cmd, void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/**
 * Send an Establishment Response command
 * @param cluster Cluster instance from which to send this command
 * @param dst_info Destination address for response, including sequence number and tx options
 * @param rsp Establishment Response command structure
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclVoiceServerSendEstabRsp(struct ZbZclClusterT *cluster, struct ZbZclAddrInfoT *dst_info,
    struct voice_estab_rsp_t *rsp);

/**
 * Send a Voice Transmission Response command. The application calls this if it ever encounters an error
 * processing a Voice Transmission packet
 * @param cluster Cluster instance from which to send this command
 * @param dst_info Destination address for response, including sequence number and tx options
 * @param rsp Voice Transmission Response command structure
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclVoiceServerSendVoiceTxRsp(struct ZbZclClusterT *cluster, struct ZbZclAddrInfoT *dst,
    struct voice_voice_tx_rsp_t *rsp);

#endif /* ZCL_VOICE_H */
