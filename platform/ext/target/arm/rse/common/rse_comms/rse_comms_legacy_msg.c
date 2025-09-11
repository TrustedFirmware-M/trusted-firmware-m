/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <assert.h>
#include "rse_comms_legacy_msg.h"
#include "rse_comms_defs.h"
#include "rse_comms_psa_protocol.h"
#include "rse_comms_link_defs.h"
#include "rse_comms_platform.h"
#include "rse_comms_link_hal.h"
#include "tfm_log.h"

__PACKED_STRUCT legacy_rse_comms_header_t {
    uint8_t protocol_ver;
    uint8_t seq_num;
    uint16_t client_id;
};

/* MHU message passed from Host to RSE to deliver a PSA client call */
__PACKED_STRUCT legacy_rse_comms_msg_t {
    struct legacy_rse_comms_header_t header;
    __PACKED_UNION {
        struct rse_embed_msg_t embed;
        struct rse_pointer_access_msg_t pointer_access;
    } msg;
};

/* MHU reply message to hold the PSA client reply result returned by RSE */
__PACKED_STRUCT legacy_rse_comms_reply_t {
    struct legacy_rse_comms_header_t header;
    __PACKED_UNION {
        struct rse_embed_reply_t embed;
        struct rse_pointer_access_reply_t pointer_access;
    } reply;
};

/* Shared buffer for converting to/from legacy message. Define
 * to be the maximum possible message size
 */
__ALIGNED(4)
uint8_t rse_comms_legacy_conversion_buffer[RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) +
                                           RSE_COMMS_PAYLOAD_MAX_SIZE];

static enum tfm_plat_err_t get_node_id_from_link_id(rse_comms_link_id_t link_id,
                                                    rse_comms_node_id_t *node_id,
                                                    rse_comms_node_id_t my_node_id)
{
    /* Assume point-to-point links for the case of legacy RSE comms protocol */
    for (rse_comms_node_id_t node = 0; node < RSE_COMMS_NUMBER_NODES; node++) {
        if (node == my_node_id) {
            continue;
        }

        if (rse_comms_hal_get_route(node) == link_id) {
            *node_id = node;
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    return TFM_PLAT_ERR_UNSUPPORTED;
}

static enum tfm_plat_err_t convert_from_legacy(uint8_t *msg_buf, size_t input_msg_len,
                                               uint8_t *output_msg, size_t output_msg_len,
                                               size_t *output_msg_size, rse_comms_node_id_t sender,
                                               rse_comms_node_id_t receiver,
                                               enum rse_comms_packet_type_t packet_type)
{
    struct legacy_rse_comms_header_t *input_msg_header =
        (struct legacy_rse_comms_header_t *)msg_buf;
    struct rse_comms_packet_t *output_packet = (struct rse_comms_packet_t *)output_msg;
    const size_t input_payload_size = input_msg_len - sizeof(*input_msg_header);
    const size_t required_output_message_size = input_payload_size +
                                                RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(false, true) +
                                                sizeof(struct serialized_rse_comms_header_t);
    uint8_t *packet_payload_ptr;
    uint8_t *output_payload_ptr;
    struct serialized_rse_comms_header_t *output_header_ptr;
    uint8_t *input_message_payload;

    if (input_msg_len < sizeof(*input_msg_header)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (GET_METADATA_FIELD(PROTOCOL_VERSION,
                           ((struct rse_comms_packet_t *)msg_buf)->header.metadata) ==
        RSE_COMMS_PROTOCOL_VERSION) {
        /* Already correct format */
        return TFM_PLAT_ERR_SUCCESS;
    }

    WARN("[COMMS] Received legacy message format!\n");

    if (output_msg_len < required_output_message_size) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    output_packet->header.metadata =
        SET_ALL_METADATA_FIELDS(packet_type, false, true, RSE_COMMS_PROTOCOL_VERSION);
    output_packet->header.sender_id = sender;
    output_packet->header.receiver_id = receiver;
    output_packet->header.message_id = input_msg_header->seq_num;

    GET_RSE_COMMS_CLIENT_ID(output_packet, false) = input_msg_header->client_id;
    GET_RSE_COMMS_APPLICATION_ID(output_packet, false) = 0;

    packet_payload_ptr = (uint8_t *)GET_RSE_COMMS_PAYLOAD_PTR(output_packet, false, true);
    output_header_ptr = (struct serialized_rse_comms_header_t *)packet_payload_ptr;
    output_header_ptr->protocol_ver = input_msg_header->protocol_ver;

    switch (packet_type) {
    case RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY:
        input_message_payload = (uint8_t *)&((struct legacy_rse_comms_msg_t *)msg_buf)->msg;
        output_payload_ptr = (uint8_t *)&((struct serialized_psa_msg_t *)packet_payload_ptr)->msg;
        break;
    case RSE_COMMS_PACKET_TYPE_REPLY:
        input_message_payload = (uint8_t *)&((struct legacy_rse_comms_reply_t *)msg_buf)->reply;
        output_payload_ptr =
            (uint8_t *)&((struct serialized_psa_reply_t *)packet_payload_ptr)->reply;
        break;
    default:
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    memcpy(output_payload_ptr, input_message_payload, input_payload_size);

    *output_msg_size = required_output_message_size;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t convert_to_legacy(uint8_t *msg_buf, size_t input_msg_len,
                                             uint8_t *output_msg, size_t output_msg_len,
                                             size_t *output_msg_size,
                                             enum rse_comms_packet_type_t packet_type)
{
    struct legacy_rse_comms_header_t *output_msg_header =
        (struct legacy_rse_comms_header_t *)output_msg;
    uint8_t *packet_payload;
    struct serialized_rse_comms_header_t *payload_header;
    struct rse_comms_packet_t *input_msg = (struct rse_comms_packet_t *)msg_buf;
    size_t input_payload_size;
    size_t required_output_message_size;
    uint8_t *input_payload_ptr;
    uint8_t *output_msg_payload;

    input_payload_size = input_msg_len - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(false, true) -
                         sizeof(struct serialized_rse_comms_header_t);
    required_output_message_size = sizeof(struct legacy_rse_comms_header_t) + input_payload_size;

    if (output_msg_len < required_output_message_size) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    packet_payload = (uint8_t *)GET_RSE_COMMS_PAYLOAD_PTR(input_msg, false, true);

    payload_header = (struct serialized_rse_comms_header_t *)packet_payload;
    output_msg_header->protocol_ver = payload_header->protocol_ver;
    output_msg_header->seq_num = input_msg->header.message_id;
    output_msg_header->client_id = GET_RSE_COMMS_CLIENT_ID(input_msg, false);

    switch (packet_type) {
    case RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY:
        input_payload_ptr = (uint8_t *)&((struct serialized_psa_msg_t *)packet_payload)->msg;
        output_msg_payload = (uint8_t *)&((struct legacy_rse_comms_msg_t *)output_msg)->msg;
        break;
    case RSE_COMMS_PACKET_TYPE_REPLY:
        input_payload_ptr = (uint8_t *)&((struct serialized_psa_reply_t *)packet_payload)->reply;
        output_msg_payload = (uint8_t *)&((struct legacy_rse_comms_reply_t *)output_msg)->reply;
        break;
    default:
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    memcpy(output_msg_payload, input_payload_ptr, input_payload_size);

    *output_msg_size = required_output_message_size;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_comms_convert_from_legacy_msg(uint8_t *msg_buf, size_t input_msg_len,
                                                      uint8_t *output_msg, size_t output_msg_len,
                                                      size_t *output_msg_size,
                                                      rse_comms_link_id_t link_id,
                                                      rse_comms_node_id_t my_node_id)
{
    enum tfm_plat_err_t err;
    rse_comms_node_id_t sender;

    err = get_node_id_from_link_id(link_id, &sender, my_node_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return convert_from_legacy(msg_buf, input_msg_len, output_msg, output_msg_len, output_msg_size,
                               sender, my_node_id, RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY);
}

enum tfm_plat_err_t rse_comms_convert_from_legacy_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                        uint8_t *output_msg, size_t output_msg_len,
                                                        size_t *output_msg_size,
                                                        rse_comms_link_id_t link_id,
                                                        rse_comms_node_id_t my_node_id)
{
    enum tfm_plat_err_t err;
    rse_comms_node_id_t receiver;

    err = get_node_id_from_link_id(link_id, &receiver, my_node_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return convert_from_legacy(msg_buf, input_msg_len, output_msg, output_msg_len, output_msg_size,
                               my_node_id, receiver, RSE_COMMS_PACKET_TYPE_REPLY);
}

enum tfm_plat_err_t rse_comms_convert_to_legacy_msg(uint8_t *msg_buf, size_t input_msg_len,
                                                    uint8_t *output_msg, size_t output_msg_len,
                                                    size_t *output_msg_size)
{
    return convert_to_legacy(msg_buf, input_msg_len, output_msg, output_msg_len, output_msg_size,
                             RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY);
}

enum tfm_plat_err_t rse_comms_convert_to_legacy_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                      uint8_t *output_msg, size_t output_msg_len,
                                                      size_t *output_msg_size)
{
    return convert_to_legacy(msg_buf, input_msg_len, output_msg, output_msg_len, output_msg_size,
                             RSE_COMMS_PACKET_TYPE_REPLY);
}

enum tfm_plat_err_t rse_comms_convert_to_legacy_error_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                            uint8_t *output_msg,
                                                            size_t output_msg_len,
                                                            size_t msg_buf_len,
                                                            size_t *output_msg_size)
{
    struct legacy_rse_comms_header_t *output_msg_header =
        (struct legacy_rse_comms_header_t *)output_msg;
    struct rse_comms_packet_t *input_msg = (struct rse_comms_packet_t *)msg_buf;
    struct legacy_rse_comms_reply_t *reply;

    if (input_msg_len != RSE_COMMS_PACKET_SIZE_ERROR_REPLY) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    output_msg_header->protocol_ver = 0;
    output_msg_header->client_id = GET_RSE_COMMS_ERROR_REPLY_CLIENT_ID(input_msg);
    output_msg_header->seq_num = input_msg->header.message_id;

    reply = (struct legacy_rse_comms_reply_t *)output_msg;
    reply->reply.embed.return_val = GET_RSE_COMMS_ERROR_REPLY_PROTCOL_ERROR(input_msg);

    *output_msg_size = sizeof(struct legacy_rse_comms_header_t) + sizeof(int32_t);

    return TFM_PLAT_ERR_SUCCESS;
}
