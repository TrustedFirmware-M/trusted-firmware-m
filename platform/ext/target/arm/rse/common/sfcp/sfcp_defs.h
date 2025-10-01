/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_DEFS_H__
#define __SFCP_DEFS_H__

#include <stdbool.h>
#include <stddef.h>
#include "cmsis_compiler.h"
#include "sfcp_trusted_subnet.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SFCP_PROTOCOL_VERSION (0b10)

/*
 * Crptography
 */
__PACKED_STRUCT sfcp_cryptography_config_t {
    uint16_t seq_num;
    enum sfcp_cryptography_mode_t mode;
    uint8_t trusted_subnet_id;
};

__PACKED_STRUCT sfcp_cryptography_metadata_t {
    struct sfcp_cryptography_config_t config;
    uint8_t tag[16];
};

/*
 * Header
 */
enum sfcp_packet_type_t {
    SFCP_PACKET_TYPE_MSG_NEEDS_REPLY = 0b00,
    SFCP_PACKET_TYPE_MSG_NO_REPLY = 0b01,
    SFCP_PACKET_TYPE_REPLY = 0b10,
    SFCP_PACKET_TYPE_PROTOCOL_ERROR_REPLY = 0b11,
};

#define METADATA_PACKET_TYPE_OFFSET (6)
#define METADATA_PACKET_TYPE_MASK (0b11)
#define METADATA_USES_CRYPTOGRAPHY_OFFSET (5)
#define METADATA_USES_CRYPTOGRAPHY_MASK (0b1)
#define METADATA_USES_ID_EXTENSION_OFFSET (4)
#define METADATA_USES_ID_EXTENSION_MASK (0b1)
#define METADATA_PROTOCOL_VERSION_OFFSET (0)
#define METADATA_PROTOCOL_VERSION_MASK (0b111)

#define GET_METADATA_FIELD(_field, _metadata) \
    (((_metadata) >> METADATA_##_field##_OFFSET) & (METADATA_##_field##_MASK))
#define SET_METADATA_FIELD(_field, _value) \
    (((_value) & METADATA_##_field##_MASK) << (METADATA_##_field##_OFFSET))
#define SET_ALL_METADATA_FIELDS(_packet_type, _uses_crypto, _uses_id, _protocol_version) \
    (SET_METADATA_FIELD(PACKET_TYPE, (_packet_type)) |                                   \
     SET_METADATA_FIELD(USES_CRYPTOGRAPHY, (_uses_crypto)) |                             \
     SET_METADATA_FIELD(USES_ID_EXTENSION, (_uses_id)) |                                 \
     SET_METADATA_FIELD(PROTOCOL_VERSION, (_protocol_version)))

__PACKED_STRUCT sfcp_header_t {
    /*
     * Metadata field consists of (in descending bit order):
     * - packet_type : 1
     * - uses_cryptography : 1
     * - uses_id_extension: 1
     * - reserved: 2
     * - protocol_version: 3
     */
    uint8_t metadata;
    uint8_t sender_id;
    uint8_t receiver_id;
    uint8_t message_id;
};

/*
 * Packet definition
 */
/*
 * C standard dictates that a fleixble array member cannot by the only element in a
 * struct and therefore we use uint8_t payload[1] to make the struct definition valid C
 */
__PACKED_STRUCT sfcp_id_extension_payload {
    __PACKED_UNION {
        __PACKED_STRUCT {
            uint16_t client_id;
            uint16_t application_id;
            uint8_t payload[1];
        } id_extension_used;
        __PACKED_STRUCT {
            uint8_t payload[1];
        } id_extension_not_used;
    };
};

__PACKED_STRUCT sfcp_packet_t {
    struct sfcp_header_t header;
    __PACKED_UNION {
        __PACKED_STRUCT {
            struct sfcp_cryptography_metadata_t cryptography_metadata;
            struct sfcp_id_extension_payload id_extension_payload;
        } cryptography_used;
        __PACKED_STRUCT {
            struct sfcp_id_extension_payload id_extension_payload;
        } cryptography_not_used;
        __PACKED_STRUCT {
            uint16_t client_id;
            uint16_t protocol_error;
        } error_reply;
    };
};

/*
 * Helper macros
 */
#define GET_SFCP_ID_EXTENSION_PAYLOAD(_packet, _uses_crypto)               \
    ((_uses_crypto) ? &(_packet)->cryptography_used.id_extension_payload : \
                      &(_packet)->cryptography_not_used.id_extension_payload)
#define GET_SFCP_GENERIC_FIELD_PTR(_packet, _uses_crypto, _uses_id_extension, _field_name)      \
    ((_uses_id_extension) ?                                                                     \
         &GET_SFCP_ID_EXTENSION_PAYLOAD(_packet, _uses_crypto)->id_extension_used._field_name : \
         &GET_SFCP_ID_EXTENSION_PAYLOAD(_packet, _uses_crypto)->id_extension_not_used._field_name)

#define GET_SFCP_PAYLOAD_PTR(_packet, _uses_crypto, _uses_id_extension) \
    GET_SFCP_GENERIC_FIELD_PTR(_packet, _uses_crypto, _uses_id_extension, payload)

#define GET_SFCP_ID_EXTENSION_FIELD(_packet, _uses_crypto, _field_name) \
    GET_SFCP_ID_EXTENSION_PAYLOAD(_packet, _uses_crypto)->id_extension_used._field_name
#define GET_SFCP_CLIENT_ID(_packet, _uses_crypto) \
    GET_SFCP_ID_EXTENSION_FIELD(_packet, _uses_crypto, client_id)
#define GET_SFCP_APPLICATION_ID(_packet, _uses_crypto) \
    GET_SFCP_ID_EXTENSION_FIELD(_packet, _uses_crypto, application_id)

#define GET_SFCP_ERROR_REPLY_FIELD(_packet, _field) ((_packet)->error_reply._field)
#define GET_SFCP_ERROR_REPLY_CLIENT_ID(_packet) GET_SFCP_ERROR_REPLY_FIELD(_packet, client_id)
#define GET_SFCP_ERROR_REPLY_PROTCOL_ERROR(_packet) \
    GET_SFCP_ERROR_REPLY_FIELD(_packet, protocol_error)

#define SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(_uses_crypto, _uses_id_extension)                      \
    ((_uses_crypto) ?                                                                           \
         ((_uses_id_extension) ?                                                                \
              offsetof(struct sfcp_packet_t,                                                    \
                       cryptography_used.id_extension_payload.id_extension_used.payload) :      \
              offsetof(struct sfcp_packet_t,                                                    \
                       cryptography_used.id_extension_payload.id_extension_not_used.payload)) : \
         ((_uses_id_extension) ?                                                                \
              offsetof(struct sfcp_packet_t,                                                    \
                       cryptography_not_used.id_extension_payload.id_extension_used.payload) :  \
              offsetof(struct sfcp_packet_t,                                                    \
                       cryptography_not_used.id_extension_payload.id_extension_not_used.payload)))
#define SFCP_PACKET_SIZE_ERROR_REPLY \
    (offsetof(struct sfcp_packet_t, error_reply) + sizeof(((struct sfcp_packet_t *)0)->error_reply))

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_DEFS_H__ */
