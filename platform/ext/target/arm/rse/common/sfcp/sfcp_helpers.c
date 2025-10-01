/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "sfcp_helpers.h"

enum sfcp_error_t sfcp_helpers_parse_packet(struct sfcp_packet_t *packet, size_t packet_size,
                                            sfcp_node_id_t *sender, sfcp_node_id_t *receiver,
                                            uint8_t *message_id, bool *uses_cryptography,
                                            bool *uses_id_extension, uint16_t *application_id,
                                            uint16_t *client_id, uint8_t **payload,
                                            size_t *payload_len, bool *needs_reply,
                                            enum sfcp_packet_type_t *packet_type)
{
    if (GET_METADATA_FIELD(PROTOCOL_VERSION, packet->header.metadata) != SFCP_PROTOCOL_VERSION) {
        return SFCP_ERROR_INVALID_PROTOCOL_VERSION;
    }

    if (packet_size < sizeof(packet->header)) {
        return SFCP_ERROR_INVALID_PACKET_SIZE;
    }

    /* Parse header */
    *sender = packet->header.sender_id;
    *receiver = packet->header.receiver_id;
    *message_id = packet->header.message_id;
    *packet_type = GET_METADATA_FIELD(PACKET_TYPE, packet->header.metadata);
    *uses_cryptography = GET_METADATA_FIELD(USES_CRYPTOGRAPHY, packet->header.metadata);
    *uses_id_extension = GET_METADATA_FIELD(USES_ID_EXTENSION, packet->header.metadata);

    switch (*packet_type) {
    case SFCP_PACKET_TYPE_PROTOCOL_ERROR_REPLY:
        if (packet_size != SFCP_PACKET_SIZE_ERROR_REPLY) {
            return SFCP_ERROR_INVALID_PACKET_SIZE;
        }

        *client_id = packet->error_reply.client_id;
        *needs_reply = false;
        *application_id = 0;
        *payload = NULL;
        *payload_len = 0;

        return SFCP_ERROR_SUCCESS;

    case SFCP_PACKET_TYPE_MSG_NO_REPLY:
    case SFCP_PACKET_TYPE_MSG_NEEDS_REPLY:
    case SFCP_PACKET_TYPE_REPLY:
        if (packet_size <
            SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(*uses_cryptography, *uses_id_extension)) {
            return SFCP_ERROR_INVALID_PACKET_SIZE;
        }

        *needs_reply = (*packet_type == SFCP_PACKET_TYPE_MSG_NEEDS_REPLY);

        if (*uses_id_extension) {
            *client_id = GET_SFCP_CLIENT_ID(packet, *uses_cryptography);
            *application_id = GET_SFCP_APPLICATION_ID(packet, *uses_cryptography);
        } else {
            *client_id = 0;
            *application_id = 0;
        }

        *payload_len =
            packet_size - SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(*uses_cryptography, *uses_id_extension);
        if (*payload_len > 0) {
            *payload =
                (uint8_t *)GET_SFCP_PAYLOAD_PTR(packet, *uses_cryptography, *uses_id_extension);
        } else {
            *payload = NULL;
        }

        return SFCP_ERROR_SUCCESS;

    default:
        return SFCP_ERROR_INVALID_MSG_TYPE;
    }
}

bool sfcp_helpers_packet_requires_forwarding_get_destination(sfcp_node_id_t sender,
                                                             sfcp_node_id_t receiver,
                                                             enum sfcp_packet_type_t packet_type,
                                                             sfcp_node_id_t my_node_id,
                                                             sfcp_node_id_t *destination)
{
    bool msg_requires_forwarding, reply_requires_forwarding;

    msg_requires_forwarding = ((packet_type == SFCP_PACKET_TYPE_MSG_NO_REPLY) ||
                               (packet_type == SFCP_PACKET_TYPE_MSG_NEEDS_REPLY)) &&
                              (receiver != my_node_id);
    if (msg_requires_forwarding) {
        *destination = receiver;
        return true;
    }

    reply_requires_forwarding = (packet_type == SFCP_PACKET_TYPE_REPLY) && (sender != my_node_id);
    if (reply_requires_forwarding) {
        *destination = sender;
        return true;
    }

    return false;
}

void sfcp_helpers_generate_protocol_error_packet(struct sfcp_packet_t *packet,
                                                 sfcp_node_id_t sender_id,
                                                 sfcp_node_id_t receiver_id, sfcp_link_id_t link_id,
                                                 uint16_t client_id, uint8_t message_id,
                                                 enum sfcp_protocol_error_t error)
{
    packet->header.metadata = SET_ALL_METADATA_FIELDS(SFCP_PACKET_TYPE_PROTOCOL_ERROR_REPLY, false,
                                                      false, SFCP_PROTOCOL_VERSION);
    packet->header.sender_id = sender_id;
    packet->header.receiver_id = receiver_id;
    packet->header.message_id = message_id;

    packet->error_reply.client_id = client_id;
    packet->error_reply.protocol_error = error;
}
