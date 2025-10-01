/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include <string.h>
#include "sfcp_encryption.h"
#include "sfcp_link_hal.h"
#include "sfcp_helpers.h"
#include "sfcp.h"
#include "sfcp_platform.h"

static enum sfcp_trusted_subnet_state_t trusted_subnet_states[SFCP_MAX_TRUSTED_SUBNET_ID];

enum sfcp_error_t
sfcp_trusted_subnet_get_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                               sfcp_node_id_t *server_node)
{
    sfcp_node_id_t lowest_node_id;

    if (trusted_subnet == NULL || server_node == NULL) {
        return SFCP_ERROR_INVALID_POINTER;
    }

    if (trusted_subnet->node_amount == 0) {
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_ID;
    }

    lowest_node_id = (sfcp_node_id_t)-1;

    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        if (trusted_subnet->nodes[i].id < lowest_node_id) {
            lowest_node_id = trusted_subnet->nodes[i].id;
        }
    }

    *server_node = lowest_node_id;

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_trusted_subnet_state_init(void)
{
    struct sfcp_trusted_subnet_config_t *configs;
    size_t num_configs;

    sfcp_platform_get_trusted_subnets(&configs, &num_configs);

    for (size_t i = 0; i < num_configs; i++) {
        switch (configs[i].type) {
        case SFCP_TRUSTED_SUBNET_TRUSTED_LINKS:
            trusted_subnet_states[configs[i].id] =
                SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED;
            break;
        case SFCP_TRUSTED_SUBNET_INITIALLY_UNTRUSTED_LINKS:
            /* Require initial session key setup before establishing mutual authentication */
            trusted_subnet_states[configs[i].id] = SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_REQUIRED;
            break;
        default:
            /* Do not currently support mutual authentication so initially only perform handshake */
            trusted_subnet_states[configs[i].id] =
                SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED;
            break;
        }
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_trusted_subnet_get_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t *state)
{
    if (trusted_subnet_id >= SFCP_MAX_TRUSTED_SUBNET_ID) {
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_ID;
    }

    *state = trusted_subnet_states[trusted_subnet_id];
    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_trusted_subnet_set_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t state)

{
    if (trusted_subnet_id >= SFCP_MAX_TRUSTED_SUBNET_ID) {
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_ID;
    }

    trusted_subnet_states[trusted_subnet_id] = state;
    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t
sfcp_get_trusted_subnet_by_id(uint8_t trusted_subnet_id,
                              struct sfcp_trusted_subnet_config_t **trusted_subnet)
{
    struct sfcp_trusted_subnet_config_t *configs;
    size_t num_configs;

    if (trusted_subnet_id >= SFCP_MAX_TRUSTED_SUBNET_ID) {
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_ID;
    }

    sfcp_platform_get_trusted_subnets(&configs, &num_configs);

    for (size_t i = 0; i < num_configs; i++) {
        if (configs[i].id == trusted_subnet_id) {
            *trusted_subnet = &configs[i];
            return SFCP_ERROR_SUCCESS;
        }
    }

    return SFCP_ERROR_INVALID_TRUSTED_SUBNET_ID;
}

enum sfcp_error_t sfcp_get_number_trusted_subnets(size_t *num_trusted_subnets)
{
    struct sfcp_trusted_subnet_config_t *configs;

    if (num_trusted_subnets == NULL) {
        return SFCP_ERROR_INVALID_POINTER;
    }

    sfcp_platform_get_trusted_subnets(&configs, num_trusted_subnets);

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t
sfcp_get_trusted_subnet_for_node(sfcp_node_id_t node,
                                 struct sfcp_trusted_subnet_config_t **trusted_subnet)
{
    struct sfcp_trusted_subnet_config_t *configs;
    size_t num_configs;

    *trusted_subnet = NULL;

    sfcp_platform_get_trusted_subnets(&configs, &num_configs);

    for (size_t i = 0; i < num_configs; i++) {
        for (uint8_t j = 0; j < configs[i].node_amount; j++) {
            if (configs[i].nodes[j].id == node) {
                if (*trusted_subnet != NULL) {
                    return SFCP_ERROR_TRUSTED_SUBNET_MUST_BE_MANUALLY_SELECTED;
                }

                *trusted_subnet = &configs[i];
            }
        }
    }

    if (*trusted_subnet == NULL) {
        return SFCP_ERROR_INVALID_NODE;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t
sfcp_trusted_subnet_get_send_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                     sfcp_node_id_t remote_node, uint16_t *seq_num)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_trusted_subnet_node_t *trusted_subnet_node;
    enum sfcp_trusted_subnet_state_t current_state;

    if (trusted_subnet == NULL || seq_num == NULL) {
        return SFCP_ERROR_INVALID_POINTER;
    }

    trusted_subnet_node = &trusted_subnet->nodes[remote_node];

    *seq_num = trusted_subnet_node->send_seq_num++;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet->id, &current_state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if ((trusted_subnet_node->send_seq_num >= SFCP_TRUSTED_SUBNET_RE_KEY_SEQ_NUM) &&
        (current_state == SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID)) {
        /* Require re-keying */
        sfcp_err = sfcp_trusted_subnet_set_state(trusted_subnet->id,
                                                 SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_REQUIRED);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    return SFCP_ERROR_SUCCESS;
}

static inline bool is_bitfield_bit_set(uint8_t *bitfield, uint8_t index)
{
    return (bitfield[index / 8] & (1 << (index % 8))) != 0;
}

static inline void set_bitfield_bit(uint8_t *bitfield, uint8_t index)
{
    bitfield[index / 8] |= (1 << (index % 8));
}

static inline void clear_bitfield_bit(uint8_t *bitfield, uint8_t index)
{
    bitfield[index / 8] &= ~(1 << (index % 8));
}

enum sfcp_error_t
sfcp_trusted_subnet_check_recv_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                       sfcp_node_id_t remote_node, uint16_t seq_num)
{
    uint8_t bitfield_index;
    struct sfcp_trusted_subnet_node_t *trusted_subnet_node;

    if (trusted_subnet == NULL) {
        return SFCP_ERROR_INVALID_POINTER;
    }

    trusted_subnet_node = &trusted_subnet->nodes[remote_node];

    if (seq_num < trusted_subnet_node->recv_seq_num) {
        return SFCP_ERROR_MSG_ALREADY_RECEIVED;
    }

    if ((seq_num - trusted_subnet_node->recv_seq_num) > SFCP_INFLIGHT_BITFIELD_SIZE) {
        return SFCP_ERROR_MSG_OUT_OF_ORDER_TEMPORARY_FAILURE;
    }

    bitfield_index =
        (trusted_subnet_node->bitfield_start_index + seq_num - trusted_subnet_node->recv_seq_num) %
        SFCP_INFLIGHT_BITFIELD_SIZE;

    if (is_bitfield_bit_set(trusted_subnet_node->inflight_bitfield, bitfield_index)) {
        return SFCP_ERROR_MSG_ALREADY_RECEIVED;
    } else {
        set_bitfield_bit(trusted_subnet_node->inflight_bitfield, bitfield_index);
    }

    while (is_bitfield_bit_set(trusted_subnet_node->inflight_bitfield,
                               trusted_subnet_node->bitfield_start_index)) {
        clear_bitfield_bit(trusted_subnet_node->inflight_bitfield,
                           trusted_subnet_node->bitfield_start_index);

        trusted_subnet_node->bitfield_start_index++;
        if (trusted_subnet_node->bitfield_start_index >= SFCP_INFLIGHT_BITFIELD_SIZE) {
            trusted_subnet_node->bitfield_start_index = 0;
        }

        trusted_subnet_node->recv_seq_num++;
    }

    return SFCP_ERROR_SUCCESS;
}
