/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_ENCRYPTION_H__
#define __SFCP_ENCRYPTION_H__

#include <stdint.h>
#include "sfcp.h"
#include "sfcp_defs.h"
#include "sfcp_trusted_subnet.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Assume the maximum trusted subnet ID is the number of nodes in the system */
#define SFCP_MAX_TRUSTED_SUBNET_ID (SFCP_NUMBER_NODES)

enum sfcp_trusted_subnet_state_t {
    SFCP_TRUSTED_SUBNET_STATE_NOT_REGISTERED = 0,

    /* SFCP session key derivation state */
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED,

    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_INITIATOR_STARTED,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_SERVER_GET_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_REPLY,

    /* SFCP re-keying state */
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_REQUIRED,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_INITIATOR_STARTED,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SENT_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST_SERVER_REPLY,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SEND_SEND_IVS_MSG,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_SEND_IVS_MSG,

    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED
};

enum sfcp_error_t
sfcp_get_trusted_subnet_by_id(uint8_t trusted_subnet_id,
                              struct sfcp_trusted_subnet_config_t **trusted_subnet);

enum sfcp_error_t sfcp_get_number_trusted_subnets(size_t *num_trusted_subnets);

enum sfcp_error_t
sfcp_trusted_subnet_get_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                               sfcp_node_id_t *server_node);

enum sfcp_error_t sfcp_trusted_subnet_state_init(void);

enum sfcp_error_t sfcp_trusted_subnet_get_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t *state);

enum sfcp_error_t sfcp_trusted_subnet_set_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t state);

enum sfcp_error_t
sfcp_get_trusted_subnet_for_node(sfcp_node_id_t node,
                                 struct sfcp_trusted_subnet_config_t **trusted_subnet);

enum sfcp_error_t
sfcp_trusted_subnet_get_send_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                     sfcp_node_id_t remote_node, uint16_t *seq_num);

enum sfcp_error_t
sfcp_trusted_subnet_check_recv_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                       sfcp_node_id_t remote_node, uint16_t seq_num);

enum sfcp_error_t sfcp_trusted_subnet_state_requires_encryption(uint8_t trusted_subnet_id,
                                                                bool *requires_encryption);

enum sfcp_error_t sfcp_encryption_handshake_initiator(uint8_t trusted_subnet_id, bool block);

enum sfcp_error_t sfcp_encryption_handshake_responder(struct sfcp_packet_t *packet,
                                                      size_t packet_size,
                                                      sfcp_node_id_t remote_node,
                                                      uint8_t message_id, bool packet_encrypted,
                                                      uint8_t *payload, size_t payload_size,
                                                      bool *is_handshake_msg);

enum sfcp_error_t sfcp_encrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   uint8_t trusted_subnet_id, sfcp_node_id_t remote_node);

enum sfcp_error_t sfcp_decrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   sfcp_node_id_t remote_node);

enum sfcp_error_t sfcp_encrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     uint8_t trusted_subnet_id, sfcp_node_id_t remote_node);

enum sfcp_error_t sfcp_decrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     sfcp_node_id_t remote_node);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_ENCRYPTION_H__ */
