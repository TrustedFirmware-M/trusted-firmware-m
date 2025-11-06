/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __SCMI_COMMON_H__
#define __SCMI_COMMON_H__

#if defined(TEST_S_SCMI_COMMS)
#include "scmi_hal_defs.h"
#else
#include "scmi_plat_defs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * SCMI protocol IDs
 */
#define SCMI_PROTOCOL_ID_POWER_DOMAIN    UINT8_C(0x11)
#define SCMI_PROTOCOL_ID_SYS_POWER_STATE UINT8_C(0x12)

/**
 * SCMI message types
 */
#define SCMI_MESSAGE_TYPE_COMMAND      UINT8_C(0)
#define SCMI_MESSAGE_TYPE_NOTIFICATION UINT8_C(3)

/**
 * SCMI message header fields
 */
#define SCMI_MESSAGE_HEADER_MESSAGE_ID_POS   0
#define SCMI_MESSAGE_HEADER_MESSAGE_ID_MASK \
    (UINT32_C(0xFF) << SCMI_MESSAGE_HEADER_MESSAGE_ID_POS)

#define SCMI_MESSAGE_HEADER_MESSAGE_TYPE_POS 8
#define SCMI_MESSAGE_HEADER_MESSAGE_TYPE_MASK \
    (UINT32_C(0x3) << SCMI_MESSAGE_HEADER_MESSAGE_TYPE_POS)

#define SCMI_MESSAGE_HEADER_PROTOCOL_ID_POS  10
#define SCMI_MESSAGE_HEADER_PROTOCOL_ID_MASK \
    (UINT32_C(0xFF) << SCMI_MESSAGE_HEADER_PROTOCOL_ID_POS)

#define SCMI_MESSAGE_HEADER_TOKEN_POS        18
#define SCMI_MESSAGE_HEADER_TOKEN_MASK \
    (UINT32_C(0x3FF) << SCMI_MESSAGE_HEADER_TOKEN_POS)

/**
 * The offset of 'message header' for the SCMI shared memory area layout, fixed
 * by the specification (SCMIv3.0, 5.1.2).
 */
#define OFFSET_SCMI_TRANSPORT_PROTOCOL 24

/**
 * TRANSPORT_MESSAGE_MAX_LENGTH is made of:
 * - Message header,  4 bytes
 * - Message payload, N bytes
 */
#define TRANSPORT_MESSAGE_MAX_LENGTH \
    ((SCP_SHARED_MEMORY_SIZE / 2) - OFFSET_SCMI_TRANSPORT_PROTOCOL)

#define TRANSPORT_MESSAGE_PAYLOAD_MAX_LENGTH \
    ((TRANSPORT_MESSAGE_MAX_LENGTH - sizeof(uint32_t)) / sizeof(uint32_t))

/**
 * \brief Structure representing an SCMI message.
 */
struct scmi_message_t {
    uint32_t header;                                          /*!< Message Header */
    uint32_t payload[TRANSPORT_MESSAGE_PAYLOAD_MAX_LENGTH];   /*!< Message Payload */
    uint32_t payload_len;                                     /*!< Payload length */
};

/*
 * Message header format as detailed by the spec
 *
 * For all protocols and all transports using standard channels,
 * messages are sent to the platform using a 32-bit message header,
 * which is described in Table 2 (v3.0 of the spec).
 */

uint32_t scmi_message_header(
    uint8_t message_id,     /*!< Message identifier */
    uint8_t message_type,   /*!< Message type */
    uint8_t protocol_id,    /*!< Protocol identifier */
    uint8_t token);         /*!< Token */

#ifdef __cplusplus
}
#endif

#endif /* __SCMI_COMMON_H__ */
