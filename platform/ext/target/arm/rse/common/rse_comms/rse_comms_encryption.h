/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_ENCRYPTION_H__
#define __RSE_COMMS_ENCRYPTION_H__

#include <stdint.h>
#include "rse_comms.h"
#include "rse_comms_defs.h"
#include "rse_comms_trusted_subnet.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Assume the maximum trusted subnet ID is the number of nodes in the system */
#define RSE_COMMS_MAX_TRUSTED_SUBNET_ID (RSE_COMMS_NUMBER_NODES)

enum rse_comms_trusted_subnet_state_t {
    RSE_COMMS_TRUSTED_SUBNET_STATE_NOT_REGISTERED = 0,

    /* RSE comms session key derivation state */
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED,

    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_INITIATOR_STARTED,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_SERVER_GET_REQUEST,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_CLIENT_REQUEST,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_REPLY,

    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID,
    RSE_COMMS_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED
};

enum rse_comms_error_t
rse_comms_get_trusted_subnet_by_id(uint8_t trusted_subnet_id,
                                   struct rse_comms_trusted_subnet_config_t **trusted_subnet);

enum rse_comms_error_t rse_comms_get_number_trusted_subnets(size_t *num_trusted_subnets);

enum rse_comms_error_t
rse_comms_trusted_subnet_get_server(struct rse_comms_trusted_subnet_config_t *trusted_subnet,
                                    rse_comms_node_id_t *server_node);

enum rse_comms_error_t rse_comms_trusted_subnet_state_init(void);

enum rse_comms_error_t
rse_comms_trusted_subnet_get_state(uint8_t trusted_subnet_id,
                                   enum rse_comms_trusted_subnet_state_t *state);

enum rse_comms_error_t
rse_comms_trusted_subnet_set_state(uint8_t trusted_subnet_id,
                                   enum rse_comms_trusted_subnet_state_t state);

enum rse_comms_error_t
rse_comms_get_trusted_subnet_for_node(rse_comms_node_id_t node,
                                      struct rse_comms_trusted_subnet_config_t **trusted_subnet);

enum rse_comms_error_t
rse_comms_trusted_subnet_get_send_seq_num(struct rse_comms_trusted_subnet_config_t *trusted_subnet,
                                          rse_comms_node_id_t remote_node, uint16_t *seq_num);

enum rse_comms_error_t rse_comms_trusted_subnet_check_recv_seq_num(
    struct rse_comms_trusted_subnet_config_t *trusted_subnet, rse_comms_node_id_t remote_node,
    uint16_t seq_num);

enum rse_comms_error_t
rse_comms_trusted_subnet_state_requires_encryption(uint8_t trusted_subnet_id,
                                                   bool *requires_encryption);

enum rse_comms_error_t rse_comms_derive_session_key_initiator(uint8_t trusted_subnet_id,
                                                              bool block);

enum rse_comms_error_t rse_comms_derive_session_key_responder(rse_comms_node_id_t remote_node,
                                                              uint8_t message_id, uint8_t *payload,
                                                              size_t payload_size,
                                                              bool *is_handshake_msg);

enum rse_comms_error_t rse_comms_encrypt_msg(struct rse_comms_packet_t *msg, size_t packet_size,
                                             uint8_t trusted_subnet_id,
                                             rse_comms_node_id_t remote_node);

enum rse_comms_error_t rse_comms_decrypt_msg(struct rse_comms_packet_t *msg, size_t packet_size,
                                             rse_comms_node_id_t remote_node);

enum rse_comms_error_t rse_comms_encrypt_reply(struct rse_comms_packet_t *reply, size_t packet_size,
                                               uint8_t trusted_subnet_id,
                                               rse_comms_node_id_t remote_node);

enum rse_comms_error_t rse_comms_decrypt_reply(struct rse_comms_packet_t *reply, size_t packet_size,
                                               rse_comms_node_id_t remote_node);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_ENCRYPTION_H__ */
