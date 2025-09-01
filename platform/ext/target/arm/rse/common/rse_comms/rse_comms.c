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
#include "rse_comms_legacy_msg.h"
#include "rse_comms_encryption.h"

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
                                           uint8_t message_id, uint8_t trusted_subnet_id)
{
    metadata->receiver = receiver;
    metadata->uses_cryptography = uses_cryptography;
    metadata->trusted_subnet_id = trusted_subnet_id;
    metadata->client_id = client_id;
    metadata->application_id = application_id;
    metadata->message_id = message_id;
}

static inline void populate_msg_metadata(struct rse_comms_msg_metadata_t *metadata,
                                         rse_comms_node_id_t sender, bool uses_cryptography,
                                         uint16_t client_id, uint16_t application_id,
                                         uint8_t message_id, uint8_t trusted_subnet_id)
{
    metadata->sender = sender;
    metadata->uses_cryptography = uses_cryptography;
    metadata->trusted_subnet_id = trusted_subnet_id;
    metadata->client_id = client_id;
    metadata->application_id = application_id;
    metadata->message_id = message_id;
}

enum rse_comms_error_t rse_comms_init(void)
{
    enum rse_comms_hal_error_t hal_error;
    enum rse_comms_error_t comms_err;

    hal_error = rse_comms_hal_init();
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    comms_err = rse_comms_trusted_subnet_state_init();
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return comms_err;
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
                                          bool manually_specify_ts_id, uint8_t trusted_subnet_id,
                                          uint8_t **payload, size_t *payload_len,
                                          struct rse_comms_packet_t **msg, size_t *msg_size,
                                          struct rse_comms_reply_metadata_t *metadata)
{
    enum rse_comms_error_t comms_err;
    bool uses_id_extension;
    struct rse_comms_packet_t *msg_ptr;
    rse_comms_node_id_t my_node_id;
    enum rse_comms_hal_error_t hal_error;
    uint8_t message_id;
    struct rse_comms_trusted_subnet_config_t *trusted_subnet;
    bool found_trusted_subnet = false;
    bool uses_cryptography;

    if ((buf == NULL) || (payload == NULL) || (payload_len == NULL) || (msg == NULL) ||
        (msg_size == NULL) || (metadata == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    uses_id_extension = (application_id != 0) || (client_id != 0);

    if (manually_specify_ts_id) {
        comms_err = rse_comms_get_trusted_subnet_by_id(trusted_subnet_id, &trusted_subnet);
        if (comms_err == RSE_COMMS_ERROR_SUCCESS) {
            found_trusted_subnet = true;
        } else {
            return comms_err;
        }
    } else {
        if (trusted_subnet_id != 0) {
            return RSE_COMMS_ERROR_INVALID_TRUSTED_SUBNET_ID;
        }

        comms_err = rse_comms_get_trusted_subnet_for_node(receiver, &trusted_subnet);
        if (comms_err == RSE_COMMS_ERROR_SUCCESS) {
            found_trusted_subnet = true;
        }
    }

    if (found_trusted_subnet) {
        comms_err = rse_comms_trusted_subnet_state_requires_encryption(trusted_subnet->id,
                                                                       &uses_cryptography);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return comms_err;
        }
    } else {
        uses_cryptography = false;
    }

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

    if (uses_cryptography) {
        struct rse_comms_cryptography_metadata_t *crypto_metadata =
            &msg_ptr->cryptography_used.cryptography_metadata;

        crypto_metadata->config.trusted_subnet_id = trusted_subnet->id;
    }

    *payload = (uint8_t *)GET_RSE_COMMS_PAYLOAD_PTR(msg_ptr, uses_cryptography, uses_id_extension);
    *payload_len =
        buf_size - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension);

    *msg = msg_ptr;
    *msg_size = buf_size;

    populate_reply_metadata(metadata, receiver, uses_cryptography, client_id, application_id,
                            message_id, trusted_subnet_id);

    return RSE_COMMS_ERROR_SUCCESS;
}

static enum rse_comms_error_t send_msg_reply(struct rse_comms_packet_t *packet, size_t packet_size,
                                             size_t payload_size, bool is_msg)
{
    enum rse_comms_error_t comms_err;
    bool uses_cryptography, uses_id_extension;
    rse_comms_link_id_t link_id;
    enum rse_comms_hal_error_t hal_error;
    size_t packet_transfer_size;
    rse_comms_node_id_t remote_node;

    if (packet == NULL) {
        return RSE_COMMS_ERROR_INVALID_PACKET;
    }

    if (packet_size < sizeof(struct rse_comms_header_t)) {
        return RSE_COMMS_ERROR_MESSAGE_TOO_SMALL;
    }

    uses_cryptography = GET_METADATA_FIELD(USES_CRYPTOGRAPHY, packet->header.metadata);
    uses_id_extension = GET_METADATA_FIELD(USES_ID_EXTENSION, packet->header.metadata);
    remote_node = is_msg ? packet->header.receiver_id : packet->header.sender_id;

    if (packet_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension)) {
        return RSE_COMMS_ERROR_MESSAGE_TOO_SMALL;
    }

    if (payload_size > (packet_size - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography,
                                                                            uses_id_extension))) {
        return RSE_COMMS_ERROR_PAYLOAD_TOO_LARGE;
    }

    packet_transfer_size =
        RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension) + payload_size;

    if (uses_cryptography) {
        if (is_msg) {
            comms_err = rse_comms_encrypt_msg(
                packet, packet_transfer_size,
                packet->cryptography_used.cryptography_metadata.config.trusted_subnet_id,
                remote_node);
            if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
                return comms_err;
            }
        } else {
            comms_err = rse_comms_encrypt_reply(
                packet, packet_transfer_size,
                packet->cryptography_used.cryptography_metadata.config.trusted_subnet_id,
                remote_node);
            if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
                return comms_err;
            }
        }
    }

    link_id = rse_comms_hal_get_route(remote_node);
    if (link_id == 0) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

#ifdef RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL
    {
        enum tfm_plat_err_t plat_err;

        if (is_msg) {
            plat_err = rse_comms_convert_to_legacy_msg((uint8_t *)packet, packet_transfer_size,
                                                       rse_comms_legacy_conversion_buffer,
                                                       sizeof(rse_comms_legacy_conversion_buffer),
                                                       &packet_transfer_size);
            if (plat_err != TFM_PLAT_ERR_SUCCESS) {
                return (enum rse_comms_error_t)plat_err;
            }
        } else {
            plat_err = rse_comms_convert_to_legacy_reply((uint8_t *)packet, packet_transfer_size,
                                                         rse_comms_legacy_conversion_buffer,
                                                         sizeof(rse_comms_legacy_conversion_buffer),
                                                         &packet_transfer_size);
            if (plat_err != TFM_PLAT_ERR_SUCCESS) {
                return (enum rse_comms_error_t)plat_err;
            }
        }

        packet = (struct rse_comms_packet_t *)rse_comms_legacy_conversion_buffer;
    }
#endif

    hal_error = rse_comms_hal_send_message(link_id, (const uint8_t *)packet, packet_transfer_size);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    return RSE_COMMS_ERROR_SUCCESS;
}

enum rse_comms_error_t rse_comms_send_msg(struct rse_comms_packet_t *msg, size_t msg_size,
                                          size_t payload_size)
{
    enum rse_comms_error_t comms_err;

    if (GET_METADATA_FIELD(USES_CRYPTOGRAPHY, msg->header.metadata)) {
        comms_err = rse_comms_derive_session_key_initiator(
            msg->cryptography_used.cryptography_metadata.config.trusted_subnet_id, true);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return comms_err;
        }
    }

    return send_msg_reply(msg, msg_size, payload_size, true);
}

enum rse_comms_error_t rse_comms_init_reply(uint8_t *buf, size_t buf_size,
                                            struct rse_comms_msg_metadata_t metadata,
                                            uint8_t **payload, size_t *payload_len,
                                            struct rse_comms_packet_t **reply, size_t *reply_size)
{
    enum rse_comms_error_t comms_err;
    struct rse_comms_packet_t *reply_ptr;
    bool uses_id_extension, uses_cryptography;
    enum rse_comms_hal_error_t hal_error;
    rse_comms_node_id_t my_node_id;
    struct rse_comms_trusted_subnet_config_t *trusted_subnet;

    if ((buf == NULL) || (payload == NULL) || (payload_len == NULL) || (reply == NULL) ||
        (reply_size == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    uses_id_extension = (metadata.client_id != 0) || (metadata.application_id != 0);
    uses_cryptography = metadata.uses_cryptography;

    if (buf_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(uses_cryptography, uses_id_extension)) {
        return RSE_COMMS_ERROR_BUFFER_TOO_SMALL;
    }

    if (uses_cryptography) {
        comms_err = rse_comms_get_trusted_subnet_by_id(metadata.trusted_subnet_id, &trusted_subnet);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return comms_err;
        }
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

    if (uses_cryptography) {
        struct rse_comms_cryptography_metadata_t *crypto_metadata =
            &reply_ptr->cryptography_used.cryptography_metadata;

        crypto_metadata->config.trusted_subnet_id = trusted_subnet->id;
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

static enum rse_comms_error_t receive_msg_reply_from_node(uint8_t *buf, size_t buf_size,
                                                          rse_comms_node_id_t remote_id,
                                                          rse_comms_link_id_t *link_id, bool is_msg,
                                                          size_t *received_size)
{
    enum rse_comms_hal_error_t hal_error;
    bool is_available;

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

    hal_error = rse_comms_hal_get_receive_message_size(*link_id, received_size);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    if (*received_size > buf_size) {
        return RSE_COMMS_ERROR_BUFFER_TOO_SMALL;
    }

    hal_error = rse_comms_hal_receive_message(*link_id, buf, *received_size);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    return RSE_COMMS_ERROR_SUCCESS;
}

static enum rse_comms_error_t
receive_msg_reply(uint8_t *buf, size_t buf_size, bool any_remote_id, rse_comms_node_id_t remote_id,
                  rse_comms_node_id_t *received_remote_id, rse_comms_link_id_t *link_id,
                  rse_comms_link_id_t *my_node_id, bool is_msg, size_t *received_size)
{
    enum rse_comms_hal_error_t hal_error;
    enum rse_comms_error_t comms_error;

    /* We do not know if the remote will use the ID extension so ensure the
     * buffer is large enough with it enabled */
    if (buf_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, true)) {
        return RSE_COMMS_ERROR_BUFFER_TOO_SMALL;
    }

    hal_error = rse_comms_hal_get_my_node_id(my_node_id);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    if (!any_remote_id && (remote_id == *my_node_id)) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    if (any_remote_id) {
        for (rse_comms_node_id_t node = 0; node < RSE_COMMS_NUMBER_NODES; node++) {
            if (node == *my_node_id) {
                continue;
            }

            comms_error =
                receive_msg_reply_from_node(buf, buf_size, node, link_id, is_msg, received_size);
            if (comms_error == RSE_COMMS_ERROR_SUCCESS) {
                *received_remote_id = node;
                return RSE_COMMS_ERROR_SUCCESS;
            } else if (comms_error != (is_msg ? RSE_COMMS_ERROR_NO_MSG_AVAILABLE :
                                                RSE_COMMS_ERROR_NO_REPLY_AVAILABLE)) {
                return comms_error;
            }
        }

        return is_msg ? RSE_COMMS_ERROR_NO_MSG_AVAILABLE : RSE_COMMS_ERROR_NO_REPLY_AVAILABLE;
    } else {
        comms_error =
            receive_msg_reply_from_node(buf, buf_size, remote_id, link_id, is_msg, received_size);
        if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
            return comms_error;
        }

        *received_remote_id = remote_id;
        return RSE_COMMS_ERROR_SUCCESS;
    }
}

enum rse_comms_error_t rse_comms_receive_msg(uint8_t *buf, size_t buf_size, bool any_sender,
                                             rse_comms_node_id_t sender, uint16_t application_id,
                                             uint16_t *client_id, uint8_t **payload,
                                             size_t *payload_len,
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
    rse_comms_node_id_t received_sender_id;
    bool is_handshake_req;

    if ((buf == NULL) || (client_id == NULL) || (payload == NULL) || (payload_len == NULL) ||
        (metadata == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    if (any_sender && (sender != 0)) {
        return RSE_COMMS_ERROR_INVALID_SENDER_ID;
    }

    comms_error = receive_msg_reply(buf, buf_size, any_sender, sender, &received_sender_id,
                                    &link_id, &my_node_id, true, &received_size);
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

    comms_error = rse_comms_derive_session_key_responder(
        packet_type == RSE_COMMS_PACKET_TYPE_REPLY ? packet_receiver : packet_sender, message_id,
        *payload, *payload_len, &is_handshake_req);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_HANDSHAKE_FAILED;
        goto error_reply;
    }

    if (is_handshake_req) {
        /* Handshake message has been successfully handled, nothing else to do */
        return RSE_COMMS_ERROR_NO_MSG_AVAILABLE;
    }

    if ((packet_type != RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY) &&
        (packet_type != RSE_COMMS_PACKET_TYPE_MSG_NO_REPLY)) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_INVALID_CONTEXT;
        comms_error = RSE_COMMS_ERROR_NO_MSG_AVAILABLE;
        goto error_reply;
    }

    if ((packet_sender != received_sender_id) || (packet_receiver != my_node_id)) {
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

    if (packet_uses_crypto) {
        comms_error = rse_comms_decrypt_msg(packet, received_size, received_sender_id);
        if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
            protocol_error = RSE_COMMS_PROTOCOL_ERROR_DECRYPTION_FAILED;
            goto error_reply;
        }
    }

    populate_msg_metadata(
        metadata, received_sender_id, packet_uses_crypto, *client_id, application_id, message_id,
        packet_uses_crypto ?
            packet->cryptography_used.cryptography_metadata.config.trusted_subnet_id :
            0);

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
    rse_comms_node_id_t received_receiver_id;
    uint8_t message_id;

    if ((buf == NULL) || (payload == NULL) || (payload_len == NULL)) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    comms_error = receive_msg_reply(buf, buf_size, false, metadata.receiver, &received_receiver_id,
                                    &link_id, &my_node_id, false, &received_size);
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

    if ((packet_sender != my_node_id) || (packet_receiver != received_receiver_id)) {
        return RSE_COMMS_ERROR_INVALID_NODE;
    }

    if (!uses_id_extension && (metadata.client_id != 0)) {
        return RSE_COMMS_ERROR_INVALID_CLIENT_ID;
    }

    if (packet_type == RSE_COMMS_PACKET_TYPE_PROTOCOL_ERROR_REPLY) {
        if (packet_client_id == metadata.client_id) {
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

    if (packet_uses_crypto) {
        comms_error = rse_comms_decrypt_reply(packet, received_size, received_receiver_id);
        if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
            return comms_error;
        }
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

    if (packet_payload_size > payload_len) {
        protocol_error = RSE_COMMS_PROTOCOL_ERROR_MSG_TOO_LARGE_TO_RECIEVE;
        comms_error = RSE_COMMS_ERROR_PAYLOAD_TOO_LARGE;
        goto error_reply;
    }

    if (packet_uses_crypto) {
        comms_error = rse_comms_decrypt_msg(packet, packet_size, *sender);
        if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
            protocol_error = RSE_COMMS_PROTOCOL_ERROR_DECRYPTION_FAILED;
            goto error_reply;
        }
    }

    memcpy(payload, packet_payload, packet_payload_size);
    *payload_size = packet_payload_size;

    populate_msg_metadata(
        metadata, *sender, packet_uses_crypto, *client_id, packet_application_id, message_id,
        packet_uses_crypto ?
            packet->cryptography_used.cryptography_metadata.config.trusted_subnet_id :
            0);

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

    if (packet_uses_crypto) {
        comms_error = rse_comms_decrypt_reply(packet, packet_size, packet_receiver);
        if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
            return comms_error;
        }
    }

    memcpy(payload, packet_payload, packet_payload_size);
    *payload_size = packet_payload_size;

    populate_reply_metadata(
        metadata, packet_receiver, packet_uses_crypto, packet_client_id, packet_application_id,
        message_id,
        packet_uses_crypto ?
            packet->cryptography_used.cryptography_metadata.config.trusted_subnet_id :
            0);

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
