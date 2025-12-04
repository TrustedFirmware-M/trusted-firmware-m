/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <assert.h>
#include "sfcp_legacy_msg.h"
#include "sfcp_defs.h"
#include "sfcp_psa_protocol.h"
#include "sfcp_link_defs.h"
#include "sfcp_platform.h"
#include "sfcp_link_hal.h"
#include "tfm_log.h"

__PACKED_STRUCT legacy_sfcp_header_t {
    uint8_t protocol_ver;
    uint8_t seq_num;
    uint16_t client_id;
};

/* MHU message passed from Host to RSE to deliver a PSA client call */
__PACKED_STRUCT legacy_sfcp_msg_t {
    struct legacy_sfcp_header_t header;
    __PACKED_UNION {
        struct sfcp_embed_msg_t embed;
        struct sfcp_pointer_access_msg_t pointer_access;
    } msg;
};

/* MHU reply message to hold the PSA client reply result returned by RSE */
__PACKED_STRUCT legacy_sfcp_reply_t {
    struct legacy_sfcp_header_t header;
    __PACKED_UNION {
        struct sfcp_embed_reply_t embed;
        struct sfcp_pointer_access_reply_t pointer_access;
    } reply;
};

/* Shared buffer for converting to/from legacy message. Define
 * to be the maximum possible message size
 */
__ALIGNED(4)
uint8_t sfcp_legacy_conversion_buffer[SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) +
                                      SFCP_PAYLOAD_MAX_SIZE];

/* Buffer to keep track of whether a node is using the legacy message protocol. If we
 * we receive a message which is in the legacy message format, we assume that all messages
 * we send will make use of the legacy format until we receive something in a different format.
 *
 * Note that this requires us to receive a legacy message first in order to send a message of
 * the legacy type
 */
static bool sfcp_node_uses_legacy_format[SFCP_NUMBER_NODES];

static enum sfcp_error_t get_node_id_from_link_id(sfcp_link_id_t link_id, sfcp_node_id_t *node_id,
                                                  sfcp_node_id_t my_node_id)
{
    /* Assume point-to-point links for the case of legacy SFCP protocol */
    for (sfcp_node_id_t node = 0; node < SFCP_NUMBER_NODES; node++) {
        if (node == my_node_id) {
            continue;
        }

        if (sfcp_hal_get_route(node) == link_id) {
            *node_id = node;
            return SFCP_ERROR_SUCCESS;
        }
    }

    return SFCP_ERROR_INVALID_NODE;
}

enum sfcp_error_t sfcp_convert_from_legacy(uint8_t *msg_buf, size_t input_msg_len,
                                           uint8_t *output_msg, size_t output_msg_len,
                                           size_t *output_msg_size, sfcp_link_id_t link_id,
                                           sfcp_node_id_t my_node_id,
                                           enum sfcp_packet_type_t output_packet_type)
{
    enum sfcp_error_t sfcp_err;
    struct legacy_sfcp_header_t *input_msg_header = (struct legacy_sfcp_header_t *)msg_buf;
    struct sfcp_packet_t *output_packet = (struct sfcp_packet_t *)output_msg;
    const size_t input_payload_size = input_msg_len - sizeof(*input_msg_header);
    const size_t required_output_message_size = input_payload_size +
                                                SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(false, true) +
                                                sizeof(struct serialized_sfcp_header_t);
    uint8_t *packet_payload_ptr;
    uint8_t *output_payload_ptr;
    struct serialized_sfcp_header_t *output_header_ptr;
    uint8_t *input_message_payload;
    sfcp_link_id_t remote_node_id;

    if (input_msg_len < sizeof(*input_msg_header)) {
        return SFCP_ERROR_INVALID_PACKET_SIZE;
    }

    sfcp_err = get_node_id_from_link_id(link_id, &remote_node_id, my_node_id);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (GET_METADATA_FIELD(PROTOCOL_VERSION, ((struct sfcp_packet_t *)msg_buf)->header.metadata) ==
        SFCP_PROTOCOL_VERSION) {
        /* If this is compiled in but we receive a valid non-legacy packet, we can support
         * both types simultaneously but warn the user as they may not need legacy message
         * handling
         */
        WARN("[SFCP] Received new message format but legacy compatibility enabled!\n");

        sfcp_node_uses_legacy_format[remote_node_id] = false;
        return SFCP_ERROR_LEGACY_FORMAT_CONVERSION_NOT_REQUIRED;
    }

    WARN("[SFCP] Received legacy message format!\n");

    if (output_msg_len < required_output_message_size) {
        return SFCP_ERROR_BUFFER_TOO_SMALL;
    }

    output_packet->header.metadata =
        SET_ALL_METADATA_FIELDS(output_packet_type, false, true, SFCP_PROTOCOL_VERSION);
    output_packet->header.message_id = input_msg_header->seq_num;

    GET_SFCP_CLIENT_ID(output_packet, false) = input_msg_header->client_id;
    GET_SFCP_APPLICATION_ID(output_packet, false) = 0;

    packet_payload_ptr = (uint8_t *)GET_SFCP_PAYLOAD_PTR(output_packet, false, true);
    output_header_ptr = (struct serialized_sfcp_header_t *)packet_payload_ptr;
    output_header_ptr->protocol_ver = input_msg_header->protocol_ver;

    switch (output_packet_type) {
    case SFCP_PACKET_TYPE_MSG_NEEDS_REPLY:
        input_message_payload = (uint8_t *)&((struct legacy_sfcp_msg_t *)msg_buf)->msg;
        output_payload_ptr = (uint8_t *)&((struct serialized_psa_msg_t *)packet_payload_ptr)->msg;
        output_packet->header.sender_id = remote_node_id;
        output_packet->header.receiver_id = my_node_id;
        break;
    case SFCP_PACKET_TYPE_REPLY:
        input_message_payload = (uint8_t *)&((struct legacy_sfcp_reply_t *)msg_buf)->reply;
        output_payload_ptr =
            (uint8_t *)&((struct serialized_psa_reply_t *)packet_payload_ptr)->reply;
        output_packet->header.sender_id = my_node_id;
        output_packet->header.receiver_id = remote_node_id;
        break;
    default:
        return SFCP_ERROR_INVALID_MSG;
    }

    memcpy(output_payload_ptr, input_message_payload, input_payload_size);

    *output_msg_size = required_output_message_size;

    sfcp_node_uses_legacy_format[remote_node_id] = true;
    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t convert_to_legacy(uint8_t *msg_buf, size_t input_msg_len,
                                           uint8_t *output_msg, size_t output_msg_len,
                                           size_t *output_msg_size, sfcp_link_id_t link_id,
                                           sfcp_node_id_t my_node_id,
                                           enum sfcp_packet_type_t input_packet_type)
{
    enum sfcp_error_t sfcp_err;
    struct legacy_sfcp_header_t *output_msg_header = (struct legacy_sfcp_header_t *)output_msg;
    uint8_t *packet_payload;
    struct serialized_sfcp_header_t *payload_header;
    struct sfcp_packet_t *input_msg = (struct sfcp_packet_t *)msg_buf;
    size_t input_payload_size;
    size_t required_output_message_size;
    uint8_t *input_payload_ptr;
    uint8_t *output_msg_payload;
    sfcp_node_id_t remote_node_id;

    sfcp_err = get_node_id_from_link_id(link_id, &remote_node_id, my_node_id);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (!sfcp_node_uses_legacy_format[remote_node_id]) {
        /* This node is not using legacy so no need for conversion */
        return SFCP_ERROR_LEGACY_FORMAT_CONVERSION_NOT_REQUIRED;
    }

    input_payload_size = input_msg_len - SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(false, true) -
                         sizeof(struct serialized_sfcp_header_t);
    required_output_message_size = sizeof(struct legacy_sfcp_header_t) + input_payload_size;

    if (output_msg_len < required_output_message_size) {
        return SFCP_ERROR_BUFFER_TOO_SMALL;
    }

    packet_payload = (uint8_t *)GET_SFCP_PAYLOAD_PTR(input_msg, false, true);

    payload_header = (struct serialized_sfcp_header_t *)packet_payload;
    output_msg_header->protocol_ver = payload_header->protocol_ver;
    output_msg_header->seq_num = input_msg->header.message_id;
    output_msg_header->client_id = GET_SFCP_CLIENT_ID(input_msg, false);

    switch (input_packet_type) {
    case SFCP_PACKET_TYPE_MSG_NEEDS_REPLY:
        input_payload_ptr = (uint8_t *)&((struct serialized_psa_msg_t *)packet_payload)->msg;
        output_msg_payload = (uint8_t *)&((struct legacy_sfcp_msg_t *)output_msg)->msg;
        break;
    case SFCP_PACKET_TYPE_REPLY:
        input_payload_ptr = (uint8_t *)&((struct serialized_psa_reply_t *)packet_payload)->reply;
        output_msg_payload = (uint8_t *)&((struct legacy_sfcp_reply_t *)output_msg)->reply;
        break;
    default:
        return SFCP_ERROR_INVALID_MSG;
    }

    memcpy(output_msg_payload, input_payload_ptr, input_payload_size);

    *output_msg_size = required_output_message_size;

    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t convert_to_legacy_error_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                       uint8_t *output_msg, size_t output_msg_len,
                                                       size_t *output_msg_size,
                                                       sfcp_link_id_t link_id,
                                                       sfcp_node_id_t my_node_id)
{
    enum sfcp_error_t sfcp_err;
    struct legacy_sfcp_header_t *output_msg_header = (struct legacy_sfcp_header_t *)output_msg;
    struct sfcp_packet_t *input_msg = (struct sfcp_packet_t *)msg_buf;
    struct legacy_sfcp_reply_t *reply;
    sfcp_node_id_t remote_node_id;

    sfcp_err = get_node_id_from_link_id(link_id, &remote_node_id, my_node_id);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (!sfcp_node_uses_legacy_format[remote_node_id]) {
        /* This node is not using legacy so no need for conversion */
        return SFCP_ERROR_LEGACY_FORMAT_CONVERSION_NOT_REQUIRED;
    }

    if (input_msg_len != SFCP_PACKET_SIZE_ERROR_REPLY) {
        return SFCP_ERROR_INVALID_PACKET_SIZE;
    }

    output_msg_header->protocol_ver = 0;
    output_msg_header->client_id = GET_SFCP_ERROR_REPLY_CLIENT_ID(input_msg);
    output_msg_header->seq_num = input_msg->header.message_id;

    reply = (struct legacy_sfcp_reply_t *)output_msg;
    reply->reply.embed.return_val = GET_SFCP_ERROR_REPLY_PROTCOL_ERROR(input_msg);

    *output_msg_size = sizeof(struct legacy_sfcp_header_t) + sizeof(int32_t);

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_convert_to_legacy(uint8_t *msg_buf, size_t input_msg_len,
                                         uint8_t *output_msg, size_t output_msg_len,
                                         size_t *output_msg_size, sfcp_link_id_t link_id,
                                         sfcp_node_id_t my_node_id,
                                         enum sfcp_packet_type_t input_packet_type)

{
    switch (input_packet_type) {
    case SFCP_PACKET_TYPE_REPLY:
    case SFCP_PACKET_TYPE_MSG_NEEDS_REPLY:
        return convert_to_legacy(msg_buf, input_msg_len, output_msg, output_msg_len,
                                 output_msg_size, link_id, my_node_id, input_packet_type);
    case SFCP_PACKET_TYPE_PROTOCOL_ERROR_REPLY:
        return convert_to_legacy_error_reply(msg_buf, input_msg_len, output_msg, output_msg_len,
                                             output_msg_size, link_id, my_node_id);
    default:
        return SFCP_ERROR_INVALID_MSG;
    }
}
