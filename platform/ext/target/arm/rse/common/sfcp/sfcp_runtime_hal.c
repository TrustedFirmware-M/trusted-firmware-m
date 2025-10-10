/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "sfcp_runtime_hal.h"

#include "mhu.h"
#include "tfm_hal_device_header.h"
#include "device_definition.h"
#include "tfm_peripherals_def.h"
#include "tfm_log_unpriv.h"
#include "tfm_pools.h"
#include "config_tfm.h"
#include "sfcp_defs.h"
#include "sfcp_link_hal.h"
#include "sfcp.h"
#include "sfcp_protocol_error.h"
#include "sfcp_handler_buffer.h"
#include "sfcp_encryption.h"
#include "sfcp_helpers.h"

#ifdef SFCP_SUPPORT_LEGACY_MSG_PROTOCOL
#include "sfcp_legacy_msg.h"
#endif

#include "critical_section.h"
#include "config_tfm.h"
#include <string.h>

/* Allow message size up to the largest possible PSA message size */
#define SFCP_HAL_MAX_MSG_SIZE (SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) + SFCP_PAYLOAD_MAX_SIZE)

struct sfcp_buffer_t {
    bool in_use;
    __ALIGNED(4) uint8_t buf[SFCP_HAL_MAX_MSG_SIZE];
    size_t msg_size;
};

static struct sfcp_buffer_t sfcp_buffer[SFCP_MAX_CONCURRENT_REQ];

/* This must be called in the interrupt context so there will be no
 concurrent access from the thread */
static bool get_free_sfcp_buffer(sfcp_buffer_handle_t *buf_handle)
{
    struct critical_section_t cs_assert = CRITICAL_SECTION_STATIC_INIT;
    bool found_free;

    /* Prevent potential concurrent access from higher priority interrupts */
    CRITICAL_SECTION_ENTER(cs_assert);
    for (uint8_t i = 0; i < SFCP_MAX_CONCURRENT_REQ; i++) {
        if (!sfcp_buffer[i].in_use) {
            *buf_handle = i;
            sfcp_buffer[i].in_use = true;
            found_free = true;
            goto out;
        }
    }

    found_free = false;

out:
    CRITICAL_SECTION_LEAVE(cs_assert);
    return found_free;
}

enum sfcp_error_t sfcp_get_handler_buffer(sfcp_buffer_handle_t buffer_handle, uint8_t **buf,
                                          size_t *msg_size)
{
    if ((buffer_handle >= SFCP_MAX_CONCURRENT_REQ) || !sfcp_buffer[buffer_handle].in_use) {
        return SFCP_ERROR_INVALID_BUFFER_HANDLE;
    }

    *buf = sfcp_buffer[buffer_handle].buf;
    *msg_size = sfcp_buffer[buffer_handle].msg_size;

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_pop_handler_buffer(sfcp_buffer_handle_t buf_handle)
{
    if (buf_handle >= SFCP_MAX_CONCURRENT_REQ) {
        return SFCP_ERROR_INVALID_BUFFER_HANDLE;
    }

    sfcp_buffer[buf_handle].in_use = false;

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
    enum tfm_plat_err_t plat_err = sfcp_convert_to_legacy_error_reply(
        (uint8_t *)&packet, SFCP_PACKET_SIZE_ERROR_REPLY, sfcp_legacy_conversion_buffer,
        sizeof(sfcp_legacy_conversion_buffer), SFCP_PACKET_SIZE_ERROR_REPLY, &output_msg_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return (enum sfcp_hal_error_t)plat_err;
    }

    packet_ptr = (struct sfcp_packet_t *)sfcp_legacy_conversion_buffer;
#endif

    hal_error = sfcp_hal_send_message(link_id, (const uint8_t *)packet_ptr, output_msg_size);
    if (hal_error != SFCP_HAL_ERROR_SUCCESS) {
        return sfcp_hal_error_to_sfcp_error(hal_error);
    }

    return SFCP_ERROR_SUCCESS;
}

enum tfm_plat_err_t tfm_multi_core_hal_receive(sfcp_link_id_t link_id, uint32_t source)
{
    enum tfm_plat_err_t err;
    enum sfcp_error_t sfcp_err;
    enum sfcp_hal_error_t hal_err;
    sfcp_buffer_handle_t buffer_handle;
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
        return (enum tfm_plat_err_t)sfcp_hal_error_to_sfcp_error(hal_err);
    }

    if (message_size > SFCP_HAL_MAX_MSG_SIZE) {
        /* Message too large for buffer */
        protocol_err = SFCP_PROTOCOL_ERROR_MSG_TOO_LARGE_TO_RECIEVE;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        buffer_allocation_failure = true;
        goto out_error;
    }

    if (!get_free_sfcp_buffer(&buffer_handle)) {
        /* Not enough buffer space */
        protocol_err = SFCP_PROTOCOL_ERROR_MSG_DELIVERY_TEMPORARY_FAILURE;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        buffer_allocation_failure = true;
        goto out_error;
    }

    hal_err = sfcp_hal_receive_message(link_id, sfcp_buffer[buffer_handle].buf, message_size);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)sfcp_hal_error_to_sfcp_error(hal_err);
    }

    hal_err = sfcp_hal_get_my_node_id(&my_node_id);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)sfcp_hal_error_to_sfcp_error(hal_err);
    }

    sfcp_buffer[buffer_handle].msg_size = message_size;
    packet = (struct sfcp_packet_t *)sfcp_buffer[buffer_handle].buf;

#ifdef SFCP_SUPPORT_LEGACY_MSG_PROTOCOL
    err = sfcp_convert_from_legacy_msg(sfcp_buffer[buffer_handle].buf,
                                       sfcp_buffer[buffer_handle].msg_size,
                                       sfcp_legacy_conversion_buffer,
                                       sizeof(sfcp_legacy_conversion_buffer),
                                       &sfcp_buffer[buffer_handle].msg_size, link_id, my_node_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    memcpy(sfcp_buffer[buffer_handle].buf, sfcp_legacy_conversion_buffer,
           sfcp_buffer[buffer_handle].msg_size);
#endif

    sfcp_err = sfcp_helpers_parse_packet(packet, message_size, &packet_sender, &packet_receiver,
                                         &message_id, &packet_uses_crypto, &uses_id_extension,
                                         &packet_application_id, &packet_client_id, &payload,
                                         &payload_len, &needs_reply, &packet_type);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        /* Do not have enough information about this packet to reply */
        return (enum tfm_plat_err_t)sfcp_err;
    }

    if (sfcp_helpers_packet_requires_forwarding_get_destination(
            packet_sender, packet_receiver, packet_type, my_node_id, &forwarding_destination)) {
        /* Forward this packet where it is meant to go */
        sfcp_link_id_t forwarding_link_id = sfcp_hal_get_route(forwarding_destination);
        if (forwarding_link_id == 0) {
            protocol_err = SFCP_PROTOCOL_ERROR_INVALID_FORWARDING_DESTINATION;
            err = (enum tfm_plat_err_t)SFCP_ERROR_INVALID_NODE;
            goto out_error;
        }

        hal_err = sfcp_hal_send_message(forwarding_link_id, (uint8_t *)packet, message_size);
        if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
            protocol_err = SFCP_PROTOCOL_ERROR_FORWARDING_FAILED;
            err = (enum tfm_plat_err_t)sfcp_hal_error_to_sfcp_error(hal_err);
            goto out_error;
        }

        /* Message has been successfully forwarded, nothing else to do */
        return TFM_PLAT_ERR_SUCCESS;
    }

    sfcp_err = sfcp_derive_session_key_responder(
        packet_type == SFCP_PACKET_TYPE_REPLY ? packet_receiver : packet_sender, message_id,
        payload, payload_len, &is_handshake_req);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        protocol_err = SFCP_PROTOCOL_ERROR_HANDSHAKE_FAILED;
        goto out_error;
    }

    if (is_handshake_req) {
        /* Handshake message has been successfully handled, nothing else to do */
        return TFM_PLAT_ERR_SUCCESS;
    }

    switch (packet_type) {
    case SFCP_PACKET_TYPE_MSG_NEEDS_REPLY:
    case SFCP_PACKET_TYPE_MSG_NO_REPLY:
        sfcp_err = sfcp_get_msg_handler(packet_application_id, &handler);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            protocol_err = SFCP_PROTOCOL_ERROR_INVALID_APPLICATION_ID;
            err = TFM_PLAT_ERR_SYSTEM_ERR;
            goto out_error;
        }

        break;
    case SFCP_PACKET_TYPE_REPLY:
    case SFCP_PACKET_TYPE_PROTOCOL_ERROR_REPLY:
        sfcp_err = sfcp_get_reply_handler(packet_client_id, &handler);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            protocol_err = SFCP_PROTOCOL_ERROR_INVALID_CLIENT_ID;
            err = TFM_PLAT_ERR_SYSTEM_ERR;
            goto out_error;
        }

        break;
    default:
        protocol_err = SFCP_PROTOCOL_ERROR_INVALID_CONTEXT;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_error;
    }

    sfcp_err = handler(buffer_handle);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        protocol_err = SFCP_PROTOCOL_ERROR_HANDLER_FAILED;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_error;
    }

    return TFM_PLAT_ERR_SUCCESS;

out_error:
    if (buffer_allocation_failure) {
        enum sfcp_error_t sfcp_parse_buffer_failed_packet_error;
        struct sfcp_packet_t buffer_failure_packet;
        size_t size_to_receive;

        /* Only receive the header or the maximum possible size if the message is smaller */
        size_to_receive = message_size < SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) ?
                              message_size :
                              SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true);

        /* Message too large for buffer, receive just the header for error reply */
        hal_err =
            sfcp_hal_receive_message(link_id, (uint8_t *)&buffer_failure_packet, size_to_receive);
        if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
            /* Cannot receive the header so have to drop */
            return (enum tfm_plat_err_t)sfcp_hal_error_to_sfcp_error(hal_err);
        }

        sfcp_parse_buffer_failed_packet_error = sfcp_helpers_parse_packet(
            &buffer_failure_packet, size_to_receive, &packet_sender, &packet_receiver, &message_id,
            &packet_uses_crypto, &uses_id_extension, &packet_application_id, &packet_client_id,
            &payload, &payload_len, &needs_reply, &packet_type);
        if (sfcp_parse_buffer_failed_packet_error != SFCP_ERROR_SUCCESS) {
            /* Cannot parse this packet so must drop */
            return (enum tfm_plat_err_t)sfcp_parse_buffer_failed_packet_error;
        }
    }

    if (needs_reply) {
        enum sfcp_error_t send_reply_error = send_protocol_error(
            packet_sender, packet_receiver, link_id, packet_client_id, message_id, protocol_err);
        if (send_reply_error != SFCP_ERROR_SUCCESS) {
            err = (enum tfm_plat_err_t)send_reply_error;
        }
    }

    if (!buffer_allocation_failure) {
        enum sfcp_error_t free_buffer_failure = sfcp_pop_handler_buffer(buffer_handle);
        if (free_buffer_failure != SFCP_ERROR_SUCCESS) {
            err = (enum tfm_plat_err_t)free_buffer_failure;
        }
    }

    return err;
}

enum tfm_plat_err_t tfm_multi_core_hal_init(void)
{
    enum sfcp_error_t sfcp_err;

    sfcp_err = sfcp_init();
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)sfcp_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
