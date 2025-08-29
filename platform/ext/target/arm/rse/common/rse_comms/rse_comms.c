/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include <string.h>
#include "rse_comms.h"
#include "rse_comms_link_hal.h"
#include "rse_comms_defs.h"
#include "rse_comms_handler_buffer.h"
#include "rse_comms_protocol_error.h"
#include "rse_comms_helpers.h"

#ifndef RSE_COMMS_MAX_NUMBER_MESSAGE_HANDLERS
#define RSE_COMMS_MAX_NUMBER_MESSAGE_HANDLERS (2)
#endif

#ifndef RSE_COMMS_MAX_NUMBER_REPLY_HANDLERS
#define RSE_COMMS_MAX_NUMBER_REPLY_HANDLERS (2)
#endif

struct rse_comms_handler_table_entry_t {
    rse_comms_handler_t handler;
    union {
        uint16_t application_id;
        uint16_t client_id;
    };
    bool in_use;
};

static struct rse_comms_handler_table_entry_t
    rse_comms_msg_handlers[RSE_COMMS_MAX_NUMBER_MESSAGE_HANDLERS];
static struct rse_comms_handler_table_entry_t
    rse_comms_reply_handlers[RSE_COMMS_MAX_NUMBER_REPLY_HANDLERS];

static inline enum rse_comms_error_t
rse_protocol_error_to_comms_error(enum rse_comms_protocol_error_t protocol_error)
{
    switch (protocol_error) {
    case RSE_COMMS_PROTOCOL_ERROR_TRY_AGAIN_LATER:
        return RSE_COMMS_ERROR_SEND_MSG_AGAIN;
    default:
        return RSE_COMMS_ERROR_PROTOCOL_ERROR;
    }
}

static inline void populate_reply_metadata(struct rse_comms_reply_metadata_t *metadata,
                                           rse_comms_node_id_t receiver, bool uses_cryptography,
                                           uint16_t client_id, uint16_t application_id,
                                           uint8_t message_id)
{
    metadata->receiver = receiver;
    metadata->uses_cryptography = uses_cryptography;
    metadata->client_id = client_id;
    metadata->application_id = application_id;
    metadata->message_id = message_id;
}

static inline void populate_msg_metadata(struct rse_comms_msg_metadata_t *metadata,
                                         rse_comms_node_id_t sender, bool uses_cryptography,
                                         uint16_t client_id, uint16_t application_id,
                                         uint8_t message_id)
{
    metadata->sender = sender;
    metadata->uses_cryptography = uses_cryptography;
    metadata->client_id = client_id;
    metadata->application_id = application_id;
    metadata->message_id = message_id;
}

enum rse_comms_error_t rse_comms_init(void)
{
    enum rse_comms_hal_error_t hal_error;

    hal_error = rse_comms_hal_init();
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    return RSE_COMMS_ERROR_SUCCESS;
}

static uint8_t get_new_message_id(rse_comms_node_id_t node)
{
    static uint8_t message_ids_per_node[RSE_COMMS_NUMBER_NODES];

    return message_ids_per_node[node]++;
}

enum rse_comms_error_t rse_comms_init_msg(uint8_t *buf, size_t buf_size,
                                          rse_comms_node_id_t receiver, uint16_t application_id,
                                          uint16_t client_id, bool needs_reply,
                                          bool uses_cryptography, uint8_t **payload,
                                          size_t *payload_len, struct rse_comms_packet_t **msg,
                                          size_t *msg_size,
                                          struct rse_comms_reply_metadata_t *metadata)
{
    bool uses_id_extension;
    struct rse_comms_packet_t *msg_ptr;
    rse_comms_node_id_t my_node_id;
    enum rse_comms_hal_error_t hal_error;
    uint8_t message_id;

    if (uses_cryptography) {
        /* TODO: Cryptography currently unsupported */
        return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
    }

    if ((buf == NULL) || (payload == NULL) || (payload_len == NULL) || (msg == NULL) ||
        (msg_size == NULL) || (metadata == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    uses_id_extension = (application_id != 0) || (client_id != 0);

    if (buf_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension)) {
        return RSE_COMMS_ERROR_BUFFER_TOO_SMALL;
    }

    hal_error = rse_comms_hal_get_my_node_id(&my_node_id);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    if ((receiver >= RSE_COMMS_NUMBER_NODES) || (receiver == my_node_id)) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    msg_ptr = (struct rse_comms_packet_t *)buf;
    message_id = get_new_message_id(receiver);

    msg_ptr->header.metadata = SET_ALL_METADATA_FIELDS(
        needs_reply ? RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY : RSE_COMMS_PACKET_TYPE_MSG_NO_REPLY,
        uses_cryptography, uses_id_extension, RSE_COMMS_PROTOCOL_VERSION);
    msg_ptr->header.receiver_id = receiver;
    msg_ptr->header.sender_id = my_node_id;
    msg_ptr->header.message_id = message_id;

    if (uses_id_extension) {
        GET_RSE_COMMS_CLIENT_ID(msg_ptr, uses_cryptography) = client_id;
        GET_RSE_COMMS_APPLICATION_ID(msg_ptr, uses_cryptography) = application_id;
    }

    *payload = (uint8_t *)GET_RSE_COMMS_PAYLOAD_PTR(msg_ptr, uses_cryptography, uses_id_extension);
    *payload_len =
        buf_size - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension);

    *msg = msg_ptr;
    *msg_size = buf_size;

    populate_reply_metadata(metadata, receiver, uses_cryptography, client_id, application_id,
                            message_id);

    return RSE_COMMS_ERROR_SUCCESS;
}

static enum rse_comms_error_t send_msg_reply(struct rse_comms_packet_t *packet, size_t packet_size,
                                             size_t payload_size, bool is_msg)
{
    bool uses_cryptography, uses_id_extension;
    rse_comms_link_id_t link_id;
    enum rse_comms_hal_error_t hal_error;

    if (packet == NULL) {
        return RSE_COMMS_ERROR_INVALID_PACKET;
    }

    if (packet_size < sizeof(struct rse_comms_header_t)) {
        return RSE_COMMS_ERROR_MESSAGE_TOO_SMALL;
    }

    uses_cryptography = GET_METADATA_FIELD(USES_CRYPTOGRAPHY, packet->header.metadata);
    uses_id_extension = GET_METADATA_FIELD(USES_ID_EXTENSION, packet->header.metadata);

    if (packet_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension)) {
        return RSE_COMMS_ERROR_MESSAGE_TOO_SMALL;
    }

    if (payload_size > (packet_size - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography,
                                                                            uses_id_extension))) {
        return RSE_COMMS_ERROR_PAYLOAD_TOO_LARGE;
    }

    link_id =
        rse_comms_hal_get_route(is_msg ? packet->header.receiver_id : packet->header.sender_id);
    if (link_id == 0) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    hal_error = rse_comms_hal_send_message(
        link_id, (const uint8_t *)packet,
        RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension) + payload_size);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    return RSE_COMMS_ERROR_SUCCESS;
}

enum rse_comms_error_t rse_comms_send_msg(struct rse_comms_packet_t *msg, size_t msg_size,
                                          size_t payload_size)
{
    return send_msg_reply(msg, msg_size, payload_size, true);
}

enum rse_comms_error_t rse_comms_init_reply(uint8_t *buf, size_t buf_size,
                                            struct rse_comms_msg_metadata_t metadata,
                                            uint8_t **payload, size_t *payload_len,
                                            struct rse_comms_packet_t **reply, size_t *reply_size)
{
    struct rse_comms_packet_t *reply_ptr;
    bool uses_id_extension, uses_cryptography;
    enum rse_comms_hal_error_t hal_error;
    rse_comms_node_id_t my_node_id;

    if ((buf == NULL) || (payload == NULL) || (payload_len == NULL) || (reply == NULL) ||
        (reply_size == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    uses_id_extension = (metadata.client_id != 0) || (metadata.application_id != 0);
    uses_cryptography = metadata.uses_cryptography;

    if (buf_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension)) {
        return RSE_COMMS_ERROR_BUFFER_TOO_SMALL;
    }

    hal_error = rse_comms_hal_get_my_node_id(&my_node_id);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    reply_ptr = (struct rse_comms_packet_t *)buf;

    reply_ptr->header.metadata = SET_ALL_METADATA_FIELDS(RSE_COMMS_PACKET_TYPE_REPLY,
                                                         uses_cryptography, uses_id_extension,
                                                         RSE_COMMS_PROTOCOL_VERSION);
    reply_ptr->header.receiver_id = my_node_id;
    reply_ptr->header.sender_id = metadata.sender;
    reply_ptr->header.message_id = metadata.message_id;

    if (uses_id_extension) {
        GET_RSE_COMMS_CLIENT_ID(reply_ptr, uses_cryptography) = metadata.client_id;
        GET_RSE_COMMS_APPLICATION_ID(reply_ptr, uses_cryptography) = metadata.application_id;
    }

    *payload =
        (uint8_t *)GET_RSE_COMMS_PAYLOAD_PTR(reply_ptr, uses_cryptography, uses_id_extension);
    *payload_len =
        buf_size - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension);

    *reply = reply_ptr;
    *reply_size = buf_size;

    return RSE_COMMS_ERROR_SUCCESS;
}

enum rse_comms_error_t rse_comms_send_reply(struct rse_comms_packet_t *reply, size_t reply_size,
                                            size_t payload_size)
{
    return send_msg_reply(reply, reply_size, payload_size, false);
}

static enum rse_comms_error_t send_protocol_error(rse_comms_node_id_t sender_id,
                                                  rse_comms_node_id_t receiver_id,
                                                  rse_comms_link_id_t link_id, uint16_t client_id,
                                                  uint8_t message_id,
                                                  enum rse_comms_protocol_error_t error)
{
    struct rse_comms_packet_t packet;
    enum rse_comms_hal_error_t hal_error;

    rse_comms_helpers_generate_protocol_error_packet(&packet, sender_id, receiver_id, link_id,
                                                     client_id, message_id, error);

    hal_error = rse_comms_hal_send_message(link_id, (const uint8_t *)&packet,
                                           RSE_COMMS_PACKET_SIZE_ERROR_REPLY);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    return RSE_COMMS_ERROR_SUCCESS;
}

static enum rse_comms_error_t
receive_msg_reply(uint8_t *buf, size_t buf_size, rse_comms_node_id_t remote_id,
                  rse_comms_link_id_t *link_id, rse_comms_link_id_t *my_node_id,
                  bool uses_cryptography, bool is_msg, size_t *received_size)
{
    enum rse_comms_hal_error_t hal_error;
    bool is_available;
    size_t message_size;

    /* We do not know if the remote will use the ID extension so ensure the
     * buffer is large enough with it enabled */
    if (buf_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, true)) {
        return RSE_COMMS_ERROR_BUFFER_TOO_SMALL;
    }

    hal_error = rse_comms_hal_get_my_node_id(my_node_id);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    if (remote_id == *my_node_id) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    *link_id = rse_comms_hal_get_route(remote_id);
    if (*link_id == 0) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    hal_error = rse_comms_hal_is_message_available(*link_id, &is_available);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    if (!is_available) {
        return is_msg ? RSE_COMMS_ERROR_NO_MSG_AVAILABLE : RSE_COMMS_ERROR_NO_REPLY_AVAILABLE;
    }

    hal_error = rse_comms_hal_get_receive_message_size(*link_id, &message_size);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    if (message_size > buf_size) {
        return RSE_COMMS_ERROR_BUFFER_TOO_SMALL;
    }

    hal_error = rse_comms_hal_receive_message(*link_id, buf, message_size);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    return RSE_COMMS_ERROR_SUCCESS;
}

enum rse_comms_error_t rse_comms_receive_msg(uint8_t *buf, size_t buf_size,
                                             rse_comms_node_id_t sender, bool uses_cryptography,
                                             uint16_t application_id, uint16_t *client_id,
                                             uint8_t **payload, size_t *payload_len,
                                             struct rse_comms_msg_metadata_t *metadata)
{
    struct rse_comms_packet_t *packet;
    enum rse_comms_error_t comms_error;
    enum rse_comms_protocol_error_t protocol_error;
    enum rse_comms_packet_type_t packet_type;
    rse_comms_link_id_t link_id;
    rse_comms_node_id_t my_node_id;
    bool needs_reply;
    bool uses_id_extension;
    size_t received_size;
    bool packet_uses_crypto;
    uint16_t packet_application_id;
    uint8_t message_id;
    rse_comms_node_id_t packet_sender;
    rse_comms_node_id_t packet_receiver;
    rse_comms_node_id_t forwarding_destination;

    if (uses_cryptography) {
        /* TODO: Cryptography currently unsupported */
        return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
    }

    if ((buf == NULL) || (client_id == NULL) || (payload == NULL) || (payload_len == NULL) ||
        (metadata == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    comms_error = receive_msg_reply(buf, buf_size, sender, &link_id, &my_node_id, uses_cryptography,
                                    true, &received_size);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        return comms_error;
    }

    packet = (struct rse_comms_packet_t *)buf;

    comms_error = rse_comms_helpers_parse_packet(packet, received_size, &packet_sender,
                                                 &packet_receiver, &message_id, &packet_uses_crypto,
                                                 &uses_id_extension, &packet_application_id,
                                                 client_id, payload, payload_len, &needs_reply,
                                                 &packet_type);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        /* Do not know enough about this packet to reply */
        return comms_error;
    }

    if (rse_comms_helpers_packet_requires_forwarding_get_destination(
            packet_sender, packet_receiver, packet_type, my_node_id, &forwarding_destination)) {
        protocol_error = RSE_COMMS_PROTOCOL_FORWARDING_UNSUPPORTED;
        comms_error = RSE_COMMS_ERROR_NO_MSG_AVAILABLE;
        goto error_reply;
    }

    if ((packet_type != RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY) &&
        (packet_type != RSE_COMMS_PACKET_TYPE_MSG_NO_REPLY)) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_INVALID_CONTEXT;
        comms_error = RSE_COMMS_ERROR_NO_MSG_AVAILABLE;
        goto error_reply;
    }

    if ((packet_sender != sender) || (packet_receiver != my_node_id)) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_UNSUPPORTED;
        comms_error = RSE_COMMS_ERROR_INVALID_NODE;
        goto error_reply;
    }

    if (!uses_id_extension && (application_id != 0)) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_UNSUPPORTED;
        comms_error = RSE_COMMS_ERROR_INVALID_APPLICATION_ID;
        goto error_reply;
    }

    if (uses_id_extension && (packet_application_id != application_id)) {
        /* This message is not for us so we have to drop and get the remote to
         * send it again later */
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_TRY_AGAIN_LATER;
        comms_error = RSE_COMMS_ERROR_NO_MSG_AVAILABLE;
        goto error_reply;
    }

    if (packet_uses_crypto != uses_cryptography) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_CRYPTO_UNSUPPORTED;
        comms_error = RSE_COMMS_ERROR_INVALID_CRYPTO_MODE;
        goto error_reply;
    }

    populate_msg_metadata(metadata, sender, uses_cryptography, *client_id, application_id,
                          message_id);

    return RSE_COMMS_ERROR_SUCCESS;

error_reply:
    if (needs_reply) {
        enum rse_comms_error_t send_reply_error = send_protocol_error(
            packet_sender, packet_receiver, link_id, *client_id, message_id, protocol_error);
        if (send_reply_error != RSE_COMMS_ERROR_SUCCESS) {
            return send_reply_error;
        }
    }

    return comms_error;
}

enum rse_comms_error_t rse_comms_receive_reply(uint8_t *buf, size_t buf_size,
                                               struct rse_comms_reply_metadata_t metadata,
                                               uint8_t **payload, size_t *payload_len)
{
    struct rse_comms_packet_t *packet;
    enum rse_comms_error_t comms_error;
    enum rse_comms_protocol_error_t protocol_error;
    enum rse_comms_packet_type_t packet_type;
    rse_comms_link_id_t link_id;
    rse_comms_link_id_t my_node_id;
    bool needs_reply;
    bool uses_id_extension;
    size_t received_size;
    bool packet_uses_crypto;
    uint16_t packet_application_id;
    uint16_t packet_client_id;
    rse_comms_node_id_t packet_sender;
    rse_comms_node_id_t packet_receiver;
    rse_comms_node_id_t forwarding_destination;
    uint8_t message_id;

    if ((buf == NULL) || (payload == NULL) || (payload_len == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    comms_error = receive_msg_reply(buf, buf_size, metadata.receiver, &link_id, &my_node_id,
                                    metadata.uses_cryptography, false, &received_size);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        return comms_error;
    }

    packet = (struct rse_comms_packet_t *)buf;

    comms_error = rse_comms_helpers_parse_packet(packet, received_size, &packet_sender,
                                                 &packet_receiver, &message_id, &packet_uses_crypto,
                                                 &uses_id_extension, &packet_application_id,
                                                 &packet_client_id, payload, payload_len,
                                                 &needs_reply, &packet_type);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        /* Do not know enough about this packet to reply */
        return comms_error;
    }

    if (rse_comms_helpers_packet_requires_forwarding_get_destination(
            packet_sender, packet_receiver, packet_type, my_node_id, &forwarding_destination)) {
        protocol_error = RSE_COMMS_PROTOCOL_FORWARDING_UNSUPPORTED;
        comms_error = RSE_COMMS_ERROR_NO_REPLY_AVAILABLE;
        goto error_reply;
    }

    if ((packet_type != RSE_COMMS_PACKET_TYPE_PROTOCOL_ERROR_REPLY) &&
        (packet_type != RSE_COMMS_PACKET_TYPE_REPLY)) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_TRY_AGAIN_LATER;
        comms_error = RSE_COMMS_ERROR_NO_REPLY_AVAILABLE;
        goto error_reply;
    }

    /* Message is definitely not something we need to reply
     * to, so we can just return an error to the caller */

    if ((packet_sender != my_node_id) || (packet_receiver != metadata.receiver)) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    if (!uses_id_extension && (metadata.client_id != 0)) {
        return RSE_COMMS_ERROR_INVALID_CLIENT_ID;
    }

    if (packet_type == RSE_COMMS_PACKET_TYPE_PROTOCOL_ERROR_REPLY) {
        if (!uses_id_extension ||
            (uses_id_extension && (packet->error_reply.client_id == metadata.client_id))) {
            /* Error message for us */
            return rse_protocol_error_to_comms_error(packet->error_reply.protocol_error);
        } else {
            /* Error message for a different client ID, drop */
            return RSE_COMMS_ERROR_NO_REPLY_AVAILABLE;
        }
    }

    if (uses_id_extension && (packet_client_id != metadata.client_id)) {
        /* This reply is not for us so we have to drop it */
        return RSE_COMMS_ERROR_NO_REPLY_AVAILABLE;
    }

    if (uses_id_extension && (packet_application_id != metadata.application_id)) {
        /* Message has the client ID so it is for us, but the sender has not correctly
         * set the application ID, drop */
        return RSE_COMMS_ERROR_INVALID_APPLICATION_ID;
    }

    if (packet_uses_crypto != metadata.uses_cryptography) {
        return RSE_COMMS_ERROR_INVALID_CRYPTO_MODE;
    }

    if (message_id != metadata.message_id) {
        return RSE_COMMS_ERROR_INVALID_SEQUENCE_NUMBER;
    }

    return RSE_COMMS_ERROR_SUCCESS;

error_reply:
    if (needs_reply) {
        enum rse_comms_error_t send_reply_error = send_protocol_error(
            packet_sender, packet_receiver, link_id, packet_client_id, message_id, protocol_error);
        if (send_reply_error != RSE_COMMS_ERROR_SUCCESS) {
            return send_reply_error;
        }
    }

    return comms_error;
}

enum rse_comms_error_t rse_comms_get_msg_handler(uint16_t application_id,
                                                 rse_comms_handler_t *handler)
{
    if (handler == NULL) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    for (uint8_t i = 0; i < RSE_COMMS_MAX_NUMBER_MESSAGE_HANDLERS; i++) {
        if (rse_comms_msg_handlers[i].in_use &&
            (rse_comms_msg_handlers[i].application_id == application_id)) {
            *handler = rse_comms_msg_handlers[i].handler;
            return RSE_COMMS_ERROR_SUCCESS;
        }
    }

    return RSE_COMMS_ERROR_INVALID_APPLICATION_ID;
}

enum rse_comms_error_t rse_comms_register_msg_handler(uint16_t application_id,
                                                      rse_comms_handler_t handler)
{
    if (handler == NULL) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    for (uint8_t i = 0; i < RSE_COMMS_MAX_NUMBER_MESSAGE_HANDLERS; i++) {
        if (!rse_comms_msg_handlers[i].in_use) {
            rse_comms_msg_handlers[i].handler = handler;
            rse_comms_msg_handlers[i].application_id = application_id;
            rse_comms_msg_handlers[i].in_use = true;
            return RSE_COMMS_ERROR_SUCCESS;
        }
    }

    return RSE_COMMS_ERROR_HANDLER_TABLE_FULL;
}

enum rse_comms_error_t rse_comms_pop_msg_from_buffer(rse_comms_buffer_handle_t buffer_handle,
                                                     rse_comms_node_id_t *sender,
                                                     uint16_t *client_id, bool *needs_reply,
                                                     uint8_t *payload, size_t payload_len,
                                                     size_t *payload_size,
                                                     struct rse_comms_msg_metadata_t *metadata)
{
    enum rse_comms_error_t comms_error;
    enum rse_comms_hal_error_t hal_error;
    enum rse_comms_protocol_error_t protocol_error;
    struct rse_comms_packet_t *packet;
    enum rse_comms_packet_type_t packet_type;
    rse_comms_node_id_t my_node_id;
    size_t packet_size;
    bool packet_uses_id_extension, packet_uses_crypto;
    rse_comms_node_id_t packet_receiver;
    uint8_t *packet_payload;
    size_t packet_payload_size;
    uint8_t message_id;
    uint16_t packet_application_id;

    if ((sender == NULL) || (client_id == NULL) || (needs_reply == NULL) ||
        (payload_size == NULL) || (metadata == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    if ((payload_len != 0) && (payload == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    comms_error = rse_comms_get_handler_buffer(buffer_handle, (uint8_t **)&packet, &packet_size);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        return comms_error;
    }

    comms_error = rse_comms_helpers_parse_packet(packet, packet_size, sender, &packet_receiver,
                                                 &message_id, &packet_uses_crypto,
                                                 &packet_uses_id_extension, &packet_application_id,
                                                 client_id, &packet_payload, &packet_payload_size,
                                                 needs_reply, &packet_type);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        /* Do not know enough about this packet to reply */
        return comms_error;
    }

    hal_error = rse_comms_hal_get_my_node_id(&my_node_id);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        protocol_error = RSE_COMMS_PROTOCOL_INTERNAL_ERROR;
        comms_error = rse_hal_error_to_comms_error(hal_error);
        goto error_reply;
    }

    if ((packet_type != RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY) &&
        (packet_type != RSE_COMMS_PACKET_TYPE_MSG_NO_REPLY)) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_INVALID_CONTEXT;
        comms_error = RSE_COMMS_ERROR_NO_MSG_AVAILABLE;
        goto error_reply;
    }

    if (packet_receiver != my_node_id) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_UNSUPPORTED;
        comms_error = RSE_COMMS_ERROR_INVALID_NODE;
        goto error_reply;
    }

    if (packet_uses_crypto) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_CRYPTO_UNSUPPORTED;
        comms_error = RSE_COMMS_ERROR_INVALID_CRYPTO_MODE;
        goto error_reply;
    }

    if (packet_payload_size > payload_len) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_MSG_TOO_LARGE_TO_RECIEVE;
        comms_error = RSE_COMMS_ERROR_PAYLOAD_TOO_LARGE;
        goto error_reply;
    }

    memcpy(payload, packet_payload, packet_payload_size);
    *payload_size = packet_payload_size;

    populate_msg_metadata(metadata, *sender, packet_uses_crypto, *client_id, packet_application_id,
                          message_id);

    comms_error = RSE_COMMS_ERROR_SUCCESS;
    goto pop_message;

error_reply:
    if (*needs_reply) {
        enum rse_comms_error_t send_reply_error;
        rse_comms_link_id_t link_id;

        link_id = rse_comms_hal_get_route(*sender);
        if (link_id == 0) {
            return RSE_COMMS_ERROR_INVALID_NODE;
        }

        send_reply_error = send_protocol_error(*sender, packet_receiver, link_id, *client_id,
                                               message_id, protocol_error);
        if (send_reply_error != RSE_COMMS_ERROR_SUCCESS) {
            return send_reply_error;
        }
    }

pop_message: {
    enum rse_comms_error_t pop_buffer_comms_error = rse_comms_pop_handler_buffer(buffer_handle);
    if (pop_buffer_comms_error != RSE_COMMS_ERROR_SUCCESS) {
        return pop_buffer_comms_error;
    }
}

    return comms_error;
}

enum rse_comms_error_t rse_comms_get_reply_handler(uint16_t client_id, rse_comms_handler_t *handler)
{
    for (uint8_t i = 0; i < RSE_COMMS_MAX_NUMBER_REPLY_HANDLERS; i++) {
        if (rse_comms_reply_handlers[i].in_use &&
            (rse_comms_reply_handlers[i].client_id == client_id)) {
            *handler = rse_comms_reply_handlers[i].handler;
            return RSE_COMMS_ERROR_SUCCESS;
        }
    }

    return RSE_COMMS_ERROR_INVALID_CLIENT_ID;
}

enum rse_comms_error_t rse_comms_register_reply_handler(uint16_t client_id,
                                                        rse_comms_handler_t handler)
{
    for (uint8_t i = 0; i < RSE_COMMS_MAX_NUMBER_REPLY_HANDLERS; i++) {
        if (!rse_comms_reply_handlers[i].in_use) {
            rse_comms_reply_handlers[i].handler = handler;
            rse_comms_reply_handlers[i].client_id = client_id;
            rse_comms_reply_handlers[i].in_use = true;
            return RSE_COMMS_ERROR_SUCCESS;
        }
    }

    return RSE_COMMS_ERROR_HANDLER_TABLE_FULL;
}

enum rse_comms_error_t rse_comms_pop_reply_from_buffer(rse_comms_buffer_handle_t buffer_handle,
                                                       uint8_t *payload, size_t payload_len,
                                                       size_t *payload_size,
                                                       struct rse_comms_reply_metadata_t *metadata)
{
    enum rse_comms_error_t comms_error;
    enum rse_comms_hal_error_t hal_error;
    enum rse_comms_protocol_error_t protocol_error;
    struct rse_comms_packet_t *packet;
    enum rse_comms_packet_type_t packet_type;
    rse_comms_node_id_t my_node_id;
    size_t packet_size;
    bool packet_uses_id_extension, packet_uses_crypto;
    bool needs_reply;
    rse_comms_node_id_t packet_sender, packet_receiver;
    uint8_t *packet_payload;
    size_t packet_payload_size;
    uint8_t message_id;
    uint16_t packet_application_id, packet_client_id;

    if ((payload_size == NULL) || (metadata == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    if ((payload_len != 0) && (payload == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    comms_error = rse_comms_get_handler_buffer(buffer_handle, (uint8_t **)&packet, &packet_size);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        return comms_error;
    }

    comms_error = rse_comms_helpers_parse_packet(packet, packet_size, &packet_sender,
                                                 &packet_receiver, &message_id, &packet_uses_crypto,
                                                 &packet_uses_id_extension, &packet_application_id,
                                                 &packet_client_id, &packet_payload,
                                                 &packet_payload_size, &needs_reply, &packet_type);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        /* Do not know enough about this packet to reply */
        return comms_error;
    }

    hal_error = rse_comms_hal_get_my_node_id(&my_node_id);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        protocol_error = RSE_COMMS_PROTOCOL_INTERNAL_ERROR;
        comms_error = rse_hal_error_to_comms_error(hal_error);
        goto error_reply;
    }

    if ((packet_type != RSE_COMMS_PACKET_TYPE_PROTOCOL_ERROR_REPLY) &&
        (packet_type != RSE_COMMS_PACKET_TYPE_REPLY)) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_TRY_AGAIN_LATER;
        comms_error = RSE_COMMS_ERROR_NO_REPLY_AVAILABLE;
        goto error_reply;
    }

    /* Message is definitely not something we need to reply
     * to, so we can just return an error to the caller */

    if (packet_sender != my_node_id) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    if (packet_type == RSE_COMMS_PACKET_TYPE_PROTOCOL_ERROR_REPLY) {
        return rse_protocol_error_to_comms_error(packet->error_reply.protocol_error);
    }

    if (packet_payload_size > payload_len) {
        return RSE_COMMS_ERROR_PAYLOAD_TOO_LARGE;
    }

    memcpy(payload, packet_payload, packet_payload_size);
    *payload_size = packet_payload_size;

    populate_reply_metadata(metadata, packet_receiver, packet_uses_crypto, packet_client_id,
                            packet_application_id, message_id);

    comms_error = RSE_COMMS_ERROR_SUCCESS;
    goto pop_message;

error_reply:
    if (needs_reply) {
        enum rse_comms_error_t send_reply_error;
        rse_comms_link_id_t link_id;

        link_id = rse_comms_hal_get_route(packet_sender);
        if (link_id == 0) {
            return RSE_COMMS_ERROR_INVALID_NODE;
        }

        send_reply_error = send_protocol_error(packet_sender, packet_receiver, link_id,
                                               packet_client_id, message_id, protocol_error);
        if (send_reply_error != RSE_COMMS_ERROR_SUCCESS) {
            return send_reply_error;
        }
    }

pop_message: {
    enum rse_comms_error_t pop_buffer_comms_error = rse_comms_pop_handler_buffer(buffer_handle);
    if (pop_buffer_comms_error != RSE_COMMS_ERROR_SUCCESS) {
        return pop_buffer_comms_error;
    }
}

    return comms_error;
}
