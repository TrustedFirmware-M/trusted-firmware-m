/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_HELPERS_H__
#define __SFCP_HELPERS_H__

#include <assert.h>
#include "sfcp.h"
#include "sfcp_defs.h"
#include "sfcp_link_defs.h"
#include "sfcp_protocol_error.h"
#include "sfcp_link_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

enum sfcp_error_t sfcp_helpers_parse_packet(struct sfcp_packet_t *packet, size_t packet_size,
                                            sfcp_node_id_t *sender, sfcp_node_id_t *receiver,
                                            uint8_t *message_id, bool *uses_cryptography,
                                            bool *uses_id_extension, uint16_t *application_id,
                                            uint16_t *client_id, uint8_t **payload,
                                            size_t *payload_len, bool *needs_reply,
                                            enum sfcp_packet_type_t *packet_type);

bool sfcp_helpers_packet_requires_forwarding_get_destination(sfcp_node_id_t sender,
                                                             sfcp_node_id_t receiver,
                                                             enum sfcp_packet_type_t packet_type,
                                                             sfcp_node_id_t my_node_id,
                                                             sfcp_node_id_t *destination);

void sfcp_helpers_generate_protocol_error_packet(struct sfcp_packet_t *packet,
                                                 sfcp_node_id_t sender_id,
                                                 sfcp_node_id_t receiver_id, sfcp_link_id_t link_id,
                                                 uint16_t client_id, uint8_t message_id,
                                                 enum sfcp_protocol_error_t error);

enum sfcp_error_t sfcp_helpers_drop_receive_message(sfcp_link_id_t link_id, size_t message_size,
                                                    size_t already_received);

static inline enum sfcp_error_t sfcp_hal_error_to_sfcp_error(enum sfcp_hal_error_t hal_error)
{
    if (hal_error == SFCP_HAL_ERROR_SUCCESS) {
        return SFCP_ERROR_SUCCESS;
    } else if (hal_error == SFCP_HAL_ERROR_SEND_MESSAGE_BUS_BUSY) {
        return SFCP_ERROR_SEND_MSG_BUS_BUSY;
    } else if (hal_error >= SFCP_HAL_ERROR_MAX) {
        /* Could have error directly from HAL driver */
        return (enum sfcp_error_t)hal_error;
    } else {
        return SFCP_ERROR_HAL_ERROR_BASE + hal_error;
    }
}

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_HELPERS_H__ */
