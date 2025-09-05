/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "sfcp_interrupt_handler.h"
#include "sfcp_link_hal.h"
#include "sfcp_defs.h"
#include "sfcp_protocol_error.h"
#include "sfcp_helpers.h"
#include "sfcp_legacy_msg.h"
#include "sfcp_handler_buffer.h"
#include "sfcp_encryption.h"

static inline enum sfcp_protocol_error_t allocate_error_to_protocol_error(enum sfcp_error_t error)
{
    switch (error) {
    case SFCP_ERROR_ALLOCATE_BUFFER_TOO_LARGE:
        return SFCP_PROTOCOL_ERROR_MSG_TOO_LARGE_TO_RECIEVE;
    case SFCP_ERROR_ALLOCATE_BUFFER_FAILED:
        return SFCP_PROTOCOL_ERROR_MSG_DELIVERY_TEMPORARY_FAILURE;
    default:
        return SFCP_PROTOCOL_INTERNAL_ERROR;
    }
}

static enum sfcp_error_t allocate_get_buffer(sfcp_buffer_handle_t *buffer_handle,
                                             size_t message_size, uint8_t **buffer)
{
    enum sfcp_error_t sfcp_err;
    size_t buffer_size;

    sfcp_err = sfcp_allocate_handler_buffer(buffer_handle, message_size);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    sfcp_err = sfcp_get_handler_buffer(*buffer_handle, buffer, &buffer_size);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        /* This should not fail as we know we should have a valid handle */
        assert(false);
        return sfcp_err;
    }

    /* buffer_size should match the size passed into the allocate function */
    assert(message_size == buffer_size);

    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t send_protocol_error(sfcp_node_id_t node_id, sfcp_node_id_t my_node_id,
                                             sfcp_link_id_t link_id, uint16_t client_id,
                                             uint8_t message_id, enum sfcp_protocol_error_t error)
{
    enum sfcp_hal_error_t hal_error;
    struct sfcp_packet_t packet;
    struct sfcp_packet_t *packet_ptr = &packet;
    size_t output_msg_size;

    sfcp_helpers_generate_protocol_error_packet(packet_ptr, node_id, my_node_id, link_id, client_id,
                                                message_id, error);

    output_msg_size = SFCP_PACKET_SIZE_ERROR_REPLY;

#ifdef SFCP_SUPPORT_LEGACY_MSG_PROTOCOL
    {
        enum sfcp_error_t sfcp_error;

        sfcp_error = sfcp_convert_to_legacy_error_reply(
            (uint8_t *)&packet, SFCP_PACKET_SIZE_ERROR_REPLY, sfcp_legacy_conversion_buffer,
            sizeof(sfcp_legacy_conversion_buffer), SFCP_PACKET_SIZE_ERROR_REPLY, &output_msg_size);
        if (sfcp_error != SFCP_ERROR_SUCCESS) {
            return sfcp_error;
        }

        packet_ptr = (struct sfcp_packet_t *)sfcp_legacy_conversion_buffer;
    }
#endif

    hal_error = sfcp_hal_send_message(link_id, (const uint8_t *)packet_ptr, output_msg_size);
    if (hal_error != SFCP_HAL_ERROR_SUCCESS) {
        return sfcp_hal_error_to_sfcp_error(hal_error);
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_interrupt_handler(sfcp_link_id_t link_id)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_hal_error_t hal_err;
    sfcp_buffer_handle_t buffer_handle;
    uint8_t *allocated_buffer;
    size_t message_size;
    bool needs_reply;
    struct sfcp_packet_t *packet;
    sfcp_node_id_t my_node_id;
    enum sfcp_protocol_error_t protocol_err;
    enum sfcp_packet_type_t packet_type;
    bool uses_id_extension;
    bool packet_uses_crypto;
    uint16_t packet_application_id;
    uint16_t packet_client_id;
    sfcp_node_id_t packet_sender;
    sfcp_node_id_t packet_receiver;
    sfcp_node_id_t forwarding_destination;
    uint8_t message_id;
    uint8_t *payload;
    size_t payload_len;
    sfcp_handler_t handler;
    bool is_handshake_req;
    bool buffer_allocation_failure = false;

    hal_err = sfcp_hal_get_receive_message_size(link_id, &message_size);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        return sfcp_hal_error_to_sfcp_error(hal_err);
    }

    sfcp_err = allocate_get_buffer(&buffer_handle, message_size, &allocated_buffer);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        protocol_err = allocate_error_to_protocol_error(sfcp_err);
        buffer_allocation_failure = true;
        goto out_error;
    }

    hal_err = sfcp_hal_receive_message(link_id, allocated_buffer, message_size, 0, message_size);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        return sfcp_hal_error_to_sfcp_error(hal_err);
    }

    hal_err = sfcp_hal_get_my_node_id(&my_node_id);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        return sfcp_hal_error_to_sfcp_error(hal_err);
    }

#ifdef SFCP_SUPPORT_LEGACY_MSG_PROTOCOL
    sfcp_err = sfcp_convert_from_legacy_msg(allocated_buffer, message_size,
                                            sfcp_legacy_conversion_buffer,
                                            sizeof(sfcp_legacy_conversion_buffer), &message_size,
                                            link_id, my_node_id);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    /* In the case we received a legacy message, the size of the message could have changed
     * so pop and re-allocated a buffer with the new size */
    sfcp_err = sfcp_pop_handler_buffer(buffer_handle);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        /* The buffer handle should be valid */
        assert(false);
        return sfcp_err;
    }

    sfcp_err = allocate_get_buffer(&buffer_handle, message_size, &allocated_buffer);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        protocol_err = allocate_error_to_protocol_error(sfcp_err);
        goto out_error;
    }

    memcpy(allocated_buffer, sfcp_legacy_conversion_buffer, message_size);
#endif

    packet = (struct sfcp_packet_t *)allocated_buffer;

    sfcp_err = sfcp_helpers_parse_packet(packet, message_size, &packet_sender, &packet_receiver,
                                         &message_id, &packet_uses_crypto, &uses_id_extension,
                                         &packet_application_id, &packet_client_id, &payload,
                                         &payload_len, &needs_reply, &packet_type);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        /* Do not have enough information about this packet to reply */
        return sfcp_err;
    }

    if (sfcp_helpers_packet_requires_forwarding_get_destination(
            packet_sender, packet_receiver, packet_type, my_node_id, &forwarding_destination)) {
        /* Forward this packet where it is meant to go */
        sfcp_link_id_t forwarding_link_id = sfcp_hal_get_route(forwarding_destination);
        if (forwarding_link_id == 0) {
            protocol_err = SFCP_PROTOCOL_ERROR_INVALID_FORWARDING_DESTINATION;
            sfcp_err = SFCP_ERROR_INVALID_NODE;
            goto out_error;
        }

        hal_err = sfcp_hal_send_message(forwarding_link_id, (uint8_t *)packet, message_size);
        if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
            protocol_err = SFCP_PROTOCOL_ERROR_FORWARDING_FAILED;
            sfcp_err = sfcp_hal_error_to_sfcp_error(hal_err);
            goto out_error;
        }

        /* Message has been successfully forwarded, nothing else to do */
        return SFCP_ERROR_SUCCESS;
    }

    sfcp_err = sfcp_encryption_handshake_responder(
        packet, message_size,
        packet_type == SFCP_PACKET_TYPE_REPLY ? packet_receiver : packet_sender, message_id,
        packet_uses_crypto, payload, payload_len, &is_handshake_req);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        protocol_err = SFCP_PROTOCOL_ERROR_HANDSHAKE_FAILED;
        goto out_error;
    }

    if (is_handshake_req) {
        /* Handshake message has been successfully handled, nothing else to do */
        return SFCP_ERROR_SUCCESS;
    }

    switch (packet_type) {
    case SFCP_PACKET_TYPE_MSG_NEEDS_REPLY:
    case SFCP_PACKET_TYPE_MSG_NO_REPLY:
        sfcp_err = sfcp_get_msg_handler(packet_application_id, &handler);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            protocol_err = SFCP_PROTOCOL_ERROR_INVALID_APPLICATION_ID;
            goto out_error;
        }

        break;
    case SFCP_PACKET_TYPE_REPLY:
    case SFCP_PACKET_TYPE_PROTOCOL_ERROR_REPLY:
        sfcp_err = sfcp_get_reply_handler(packet_client_id, &handler);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            protocol_err = SFCP_PROTOCOL_ERROR_INVALID_CLIENT_ID;
            goto out_error;
        }

        break;
    default:
        protocol_err = SFCP_PROTOCOL_ERROR_INVALID_CONTEXT;
        sfcp_err = SFCP_ERROR_INVALID_MSG;
        goto out_error;
    }

    sfcp_err = handler(buffer_handle);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        protocol_err = SFCP_PROTOCOL_ERROR_HANDLER_FAILED;
        goto out_error;
    }

    return SFCP_ERROR_SUCCESS;

out_error:
    if (buffer_allocation_failure) {
        enum sfcp_error_t buffer_allocation_failure_error;
        struct sfcp_packet_t buffer_failure_packet;
        size_t size_to_receive;

        buffer_allocation_failure = true;

        /* Only receive the header or the maximum possible size if the message is smaller */
        size_to_receive = message_size < SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) ?
                              message_size :
                              SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true);

        /* Message too large for buffer, receive just the header for error reply */
        hal_err = sfcp_hal_receive_message(link_id, (uint8_t *)&buffer_failure_packet, message_size,
                                           0, size_to_receive);
        if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
            /* Cannot receive the header so have to drop */
            return sfcp_hal_error_to_sfcp_error(hal_err);
        }

        buffer_allocation_failure_error = sfcp_helpers_parse_packet(
            &buffer_failure_packet, size_to_receive, &packet_sender, &packet_receiver, &message_id,
            &packet_uses_crypto, &uses_id_extension, &packet_application_id, &packet_client_id,
            &payload, &payload_len, &needs_reply, &packet_type);
        if (buffer_allocation_failure_error != SFCP_ERROR_SUCCESS) {
            /* Cannot parse this packet so must drop */
            return buffer_allocation_failure_error;
        }

        /* Use the packet stack buffer that we have to read out the rest of the message
         * to prevent the sender blocking */
        if (message_size > size_to_receive) {
            /* Ignore error code as we will send a protocol error reply
             * anyway */
            (void)sfcp_helpers_drop_receive_message(link_id, message_size, size_to_receive);
        }
    }

    if (needs_reply) {
        enum sfcp_error_t send_reply_error = send_protocol_error(
            packet_sender, packet_receiver, link_id, packet_client_id, message_id, protocol_err);
        if (send_reply_error != SFCP_ERROR_SUCCESS) {
            sfcp_err = send_reply_error;
        }
    }

    if (!buffer_allocation_failure) {
        enum sfcp_error_t free_buffer_failure = sfcp_pop_handler_buffer(buffer_handle);
        if (free_buffer_failure != SFCP_ERROR_SUCCESS) {
            sfcp_err = free_buffer_failure;
        }
    }

    return sfcp_err;
}
