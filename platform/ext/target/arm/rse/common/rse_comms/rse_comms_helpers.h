/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_HELPERS_H__
#define __RSE_COMMS_HELPERS_H__

#include <assert.h>
#include "rse_comms.h"
#include "rse_comms_defs.h"
#include "rse_comms_link_defs.h"
#include "rse_comms_protocol_error.h"
#include "rse_comms_link_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

enum rse_comms_error_t rse_comms_helpers_parse_packet(
    struct rse_comms_packet_t *packet, size_t packet_size, rse_comms_node_id_t *sender,
    rse_comms_node_id_t *receiver, uint8_t *message_id, bool *uses_cryptography,
    bool *uses_id_extension, uint16_t *application_id, uint16_t *client_id, uint8_t **payload,
    size_t *payload_len, bool *needs_reply, enum rse_comms_packet_type_t *packet_type);

bool rse_comms_helpers_packet_requires_forwarding_get_destination(
    rse_comms_node_id_t sender, rse_comms_node_id_t receiver,
    enum rse_comms_packet_type_t packet_type, rse_comms_node_id_t my_node_id,
    rse_comms_node_id_t *destination);

void rse_comms_helpers_generate_protocol_error_packet(struct rse_comms_packet_t *packet,
                                                      rse_comms_node_id_t sender_id,
                                                      rse_comms_node_id_t receiver_id,
                                                      rse_comms_link_id_t link_id,
                                                      uint16_t client_id, uint8_t message_id,
                                                      enum rse_comms_protocol_error_t error);

static inline enum rse_comms_error_t
rse_hal_error_to_comms_error(enum rse_comms_hal_error_t hal_error)
{
    assert(hal_error < (RSE_COMMS_ERROR_HAL_ERROR_MAX - RSE_COMMS_ERROR_HAL_ERROR_BASE));

    return RSE_COMMS_ERROR_HAL_ERROR_BASE + hal_error;
}

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_HELPERS_H__ */
