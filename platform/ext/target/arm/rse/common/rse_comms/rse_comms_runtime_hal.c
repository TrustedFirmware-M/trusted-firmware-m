/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_runtime_hal.h"

#include "mhu.h"
#include "tfm_hal_device_header.h"
#include "device_definition.h"
#include "tfm_peripherals_def.h"
#include "tfm_log_unpriv.h"
#include "tfm_pools.h"
#include "config_tfm.h"
#include "rse_comms_defs.h"
#include "rse_comms_link_hal.h"
#include "rse_comms.h"
#include "rse_comms_protocol_error.h"
#include "rse_comms_handler_buffer.h"
#include "rse_comms_encryption.h"
#include "rse_comms_helpers.h"

#ifdef RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL
#include "rse_comms_legacy_msg.h"
#endif

#include "critical_section.h"
#include "config_tfm.h"
#include <string.h>

/* Allow message size up to the largest possible PSA message size */
#define RSE_COMMS_HAL_MAX_MSG_SIZE \
    (RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) + RSE_COMMS_PAYLOAD_MAX_SIZE)

struct rse_comms_buffer_t {
    bool in_use;
    __ALIGNED(4) uint8_t buf[RSE_COMMS_HAL_MAX_MSG_SIZE];
    size_t msg_size;
};

static struct rse_comms_buffer_t rse_comms_buffer[RSE_COMMS_MAX_CONCURRENT_REQ];

/* This must be called in the interrupt context so there will be no
 concurrent access from the thread */
static bool get_free_rse_comms_buffer(rse_comms_buffer_handle_t *buf_handle)
{
    struct critical_section_t cs_assert = CRITICAL_SECTION_STATIC_INIT;
    bool found_free;

    /* Prevent potential concurrent access from higher priority interrupts */
    CRITICAL_SECTION_ENTER(cs_assert);
    for (uint8_t i = 0; i < RSE_COMMS_MAX_CONCURRENT_REQ; i++) {
        if (!rse_comms_buffer[i].in_use) {
            *buf_handle = i;
            rse_comms_buffer[i].in_use = true;
            found_free = true;
            goto out;
        }
    }

    found_free = false;

out:
    CRITICAL_SECTION_LEAVE(cs_assert);
    return found_free;
}

enum rse_comms_error_t rse_comms_get_handler_buffer(rse_comms_buffer_handle_t buffer_handle,
                                                    uint8_t **buf, size_t *msg_size)
{
    if ((buffer_handle >= RSE_COMMS_MAX_CONCURRENT_REQ) ||
        !rse_comms_buffer[buffer_handle].in_use) {
        return RSE_COMMS_ERROR_INVALID_BUFFER_HANDLE;
    }

    *buf = rse_comms_buffer[buffer_handle].buf;
    *msg_size = rse_comms_buffer[buffer_handle].msg_size;

    return RSE_COMMS_ERROR_SUCCESS;
}

enum rse_comms_error_t rse_comms_pop_handler_buffer(rse_comms_buffer_handle_t buf_handle)
{
    if (buf_handle >= RSE_COMMS_MAX_CONCURRENT_REQ) {
        return RSE_COMMS_ERROR_INVALID_BUFFER_HANDLE;
    }

    rse_comms_buffer[buf_handle].in_use = false;

    return RSE_COMMS_ERROR_SUCCESS;
}

static enum rse_comms_error_t send_protocol_error(rse_comms_node_id_t node_id,
                                                      rse_comms_node_id_t my_node_id,
                                                      rse_comms_link_id_t link_id,
                                                      uint16_t client_id, uint8_t message_id,
                                                      enum rse_comms_protocol_error_t error)
{
    enum rse_comms_hal_error_t hal_error;
    struct rse_comms_packet_t packet;
    struct rse_comms_packet_t *packet_ptr = &packet;
    size_t output_msg_size;

    rse_comms_helpers_generate_protocol_error_packet(packet_ptr, node_id, my_node_id, link_id,
                                                     client_id, message_id, error);

    output_msg_size = RSE_COMMS_PACKET_SIZE_ERROR_REPLY;

#ifdef RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL
    enum tfm_plat_err_t plat_err = rse_comms_convert_to_legacy_error_reply(
        (uint8_t *)&packet, RSE_COMMS_PACKET_SIZE_ERROR_REPLY, rse_comms_legacy_conversion_buffer,
        sizeof(rse_comms_legacy_conversion_buffer), RSE_COMMS_PACKET_SIZE_ERROR_REPLY,
        &output_msg_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return (enum rse_comms_hal_error_t)plat_err;
    }

    packet_ptr = (struct rse_comms_packet_t *)rse_comms_legacy_conversion_buffer;
#endif

    hal_error = rse_comms_hal_send_message(link_id, (const uint8_t *)packet_ptr, output_msg_size);
    if (hal_error != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return rse_hal_error_to_comms_error(hal_error);
    }

    return RSE_COMMS_ERROR_SUCCESS;
}

enum tfm_plat_err_t tfm_multi_core_hal_receive(rse_comms_link_id_t link_id, uint32_t source)
{
    enum tfm_plat_err_t err;
    enum rse_comms_error_t comms_err;
    enum rse_comms_hal_error_t hal_err;
    rse_comms_buffer_handle_t buffer_handle;
    size_t message_size;
    bool needs_reply;
    struct rse_comms_packet_t *packet;
    rse_comms_node_id_t my_node_id;
    enum rse_comms_protocol_error_t protocol_err;
    enum rse_comms_packet_type_t packet_type;
    bool uses_id_extension;
    bool packet_uses_crypto;
    uint16_t packet_application_id;
    uint16_t packet_client_id;
    rse_comms_node_id_t packet_sender;
    rse_comms_node_id_t packet_receiver;
    rse_comms_node_id_t forwarding_destination;
    uint8_t message_id;
    uint8_t *payload;
    size_t payload_len;
    rse_comms_handler_t handler;
    bool is_handshake_req;

    hal_err = rse_comms_hal_get_receive_message_size(link_id, &message_size);
    if (hal_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)rse_hal_error_to_comms_error(hal_err);
    }

    if (message_size > RSE_COMMS_HAL_MAX_MSG_SIZE) {
        /* Message too large for buffer */
        protocol_err = RSE_COMMS_PROTOCOL_ERROR_MSG_TOO_LARGE_TO_RECIEVE;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_error_buffer_allocation;
    }

    if (!get_free_rse_comms_buffer(&buffer_handle)) {
        /* Not enough buffer space */
        protocol_err = RSE_COMMS_PROTOCOL_ERROR_MSG_DELIVERY_TEMPORARY_FAILURE;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_error_buffer_allocation;
    }

    hal_err =
        rse_comms_hal_receive_message(link_id, rse_comms_buffer[buffer_handle].buf, message_size);
    if (hal_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)rse_hal_error_to_comms_error(hal_err);
    }

    hal_err = rse_comms_hal_get_my_node_id(&my_node_id);
    if (hal_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)rse_hal_error_to_comms_error(hal_err);
    }

    rse_comms_buffer[buffer_handle].msg_size = message_size;
    packet = (struct rse_comms_packet_t *)rse_comms_buffer[buffer_handle].buf;

#ifdef RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL
    err = rse_comms_convert_from_legacy_msg(
        rse_comms_buffer[buffer_handle].buf, rse_comms_buffer[buffer_handle].msg_size,
        rse_comms_legacy_conversion_buffer, sizeof(rse_comms_legacy_conversion_buffer),
        &rse_comms_buffer[buffer_handle].msg_size, link_id, my_node_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    memcpy(rse_comms_buffer[buffer_handle].buf, rse_comms_legacy_conversion_buffer,
           rse_comms_buffer[buffer_handle].msg_size);
#endif

    comms_err = rse_comms_helpers_parse_packet(packet, message_size, &packet_sender,
                                               &packet_receiver, &message_id, &packet_uses_crypto,
                                               &uses_id_extension, &packet_application_id,
                                               &packet_client_id, &payload, &payload_len,
                                               &needs_reply, &packet_type);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        /* Do not have enough information about this packet to reply */
        return (enum tfm_plat_err_t)comms_err;
    }

    if (rse_comms_helpers_packet_requires_forwarding_get_destination(
            packet_sender, packet_receiver, packet_type, my_node_id, &forwarding_destination)) {
        /* Forward this packet where it is meant to go */
        rse_comms_link_id_t forwarding_link_id = rse_comms_hal_get_route(forwarding_destination);
        if (forwarding_link_id == 0) {
            protocol_err = RSE_COMMS_PROTOCOL_ERROR_INVALID_FORWARDING_DESTINATION;
            err = (enum tfm_plat_err_t)RSE_COMMS_ERROR_INVALID_NODE;
            goto out_error_reply;
        }

        hal_err = rse_comms_hal_send_message(forwarding_link_id, (uint8_t *)packet, message_size);
        if (hal_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
            protocol_err = RSE_COMMS_PROTOCOL_ERROR_FORWARDING_FAILED;
            err = (enum tfm_plat_err_t)rse_hal_error_to_comms_error(hal_err);
            goto out_error_reply;
        }

        /* Message has been successfully forwarded, nothing else to do */
        return TFM_PLAT_ERR_SUCCESS;
    }

    comms_err = rse_comms_derive_session_key_responder(
        packet_type == RSE_COMMS_PACKET_TYPE_REPLY ? packet_receiver : packet_sender, message_id,
        payload, payload_len, &is_handshake_req);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        protocol_err = RSE_COMMS_PROTOCOL_ERROR_HANDSHAKE_FAILED;
        goto out_error_reply;
    }

    if (is_handshake_req) {
        /* Handshake message has been successfully handled, nothing else to do */
        return TFM_PLAT_ERR_SUCCESS;
    }

    switch (packet_type) {
    case RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY:
    case RSE_COMMS_PACKET_TYPE_MSG_NO_REPLY:
        comms_err = rse_comms_get_msg_handler(packet_application_id, &handler);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            protocol_err = RSE_COMMS_PROTOCOL_ERROR_INVALID_APPLICATION_ID;
            err = TFM_PLAT_ERR_SYSTEM_ERR;
            goto out_error_reply;
        }
        break;
    case RSE_COMMS_PACKET_TYPE_REPLY:
    case RSE_COMMS_PACKET_TYPE_PROTOCOL_ERROR_REPLY:
        comms_err = rse_comms_get_reply_handler(packet_client_id, &handler);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            protocol_err = RSE_COMMS_PROTOCOL_ERROR_INVALID_CLIENT_ID;
            err = TFM_PLAT_ERR_SYSTEM_ERR;
            goto out_error_reply;
        }
        break;
    default:
        protocol_err = RSE_COMMS_PROTOCOL_ERROR_INVALID_CONTEXT;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_error_reply;
    }

    comms_err = handler(buffer_handle);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        protocol_err = RSE_COMMS_PROTOCOL_ERROR_HANDLER_FAILED;
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_error_reply;
    }

    return TFM_PLAT_ERR_SUCCESS;

out_error_buffer_allocation: {
    enum rse_comms_error_t parse_buffer_failed_packet_error;
    struct rse_comms_packet_t buffer_failure_packet;
    size_t size_to_receive;

    /* Only receive the header or the maximum possible size if the message is smaller */
    size_to_receive = message_size < RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) ?
                          message_size :
                          RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, true);

    /* Message too large for buffer, receive just the header for error reply */
    hal_err =
        rse_comms_hal_receive_message(link_id, (uint8_t *)&buffer_failure_packet, size_to_receive);
    if (hal_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        /* Cannot receive the header so have to drop */
        return (enum tfm_plat_err_t)rse_hal_error_to_comms_error(hal_err);
    }

    parse_buffer_failed_packet_error = rse_comms_helpers_parse_packet(
        &buffer_failure_packet, size_to_receive, &packet_sender, &packet_receiver, &message_id,
        &packet_uses_crypto, &uses_id_extension, &packet_application_id, &packet_client_id,
        &payload, &payload_len, &needs_reply, &packet_type);
    if (parse_buffer_failed_packet_error != RSE_COMMS_ERROR_SUCCESS) {
        /* Cannot parse this packet so must drop */
        return (enum tfm_plat_err_t)parse_buffer_failed_packet_error;
    }

    /* Fallthrough to send error reply */
}

out_error_reply:
    if (needs_reply) {
        enum rse_comms_error_t send_reply_error = send_protocol_error(
            packet_sender, packet_receiver, link_id, packet_client_id, message_id, protocol_err);
        if (send_reply_error != RSE_COMMS_ERROR_SUCCESS) {
            err = (enum tfm_plat_err_t)send_reply_error;
        }
    }

    return err;
}

enum tfm_plat_err_t tfm_multi_core_hal_init(void)
{
    enum rse_comms_error_t comms_err;

    comms_err = rse_comms_init();
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
