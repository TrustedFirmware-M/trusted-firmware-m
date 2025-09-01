/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_encryption.h"

enum rse_comms_error_t
rse_comms_get_trusted_subnet_by_id(uint8_t trusted_subnet_id,
                                   struct rse_comms_trusted_subnet_config_t **trusted_subnet)
{
    (void)trusted_subnet_id;
    (void)trusted_subnet;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t
rse_comms_trusted_subnet_get_server(struct rse_comms_trusted_subnet_config_t *trusted_subnet,
                                    rse_comms_node_id_t *server_node)
{
    (void)trusted_subnet;
    (void)server_node;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_trusted_subnet_state_init(void)
{
    return RSE_COMMS_ERROR_SUCCESS;
}

enum rse_comms_error_t
rse_comms_trusted_subnet_get_state(uint8_t trusted_subnet_id,
                                   enum rse_comms_trusted_subnet_state_t *state)
{
    (void)trusted_subnet_id;
    (void)state;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t
rse_comms_trusted_subnet_set_state(uint8_t trusted_subnet_id,
                                   enum rse_comms_trusted_subnet_state_t state)
{
    (void)trusted_subnet_id;
    (void)state;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_get_number_trusted_subnets(size_t *num_trusted_subnets)
{
    (void)num_trusted_subnets;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t
rse_comms_get_trusted_subnet_for_node(rse_comms_node_id_t node,
                                      struct rse_comms_trusted_subnet_config_t **trusted_subnet)
{
    (void)node;
    (void)trusted_subnet;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t
rse_comms_trusted_subnet_get_send_seq_num(struct rse_comms_trusted_subnet_config_t *trusted_subnet,
                                          rse_comms_node_id_t remote_node, uint16_t *seq_num)
{
    (void)trusted_subnet;
    (void)remote_node;
    (void)seq_num;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_trusted_subnet_state_requires_encryption(uint8_t trusted_subnet_id,
                                                                          bool *requires_encryption)
{
    (void)trusted_subnet_id;
    (void)requires_encryption;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_derive_session_key_initiator(uint8_t trusted_subnet_id, bool block)
{
    (void)trusted_subnet_id;
    (void)block;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_derive_session_key_responder(rse_comms_node_id_t remote_node,
                                                              uint8_t message_id, uint8_t *payload,
                                                              size_t payload_size,
                                                              bool *is_handshake_msg)
{
    (void)remote_node;
    (void)message_id;
    (void)payload;
    (void)payload_size;

    *is_handshake_msg = false;
    return RSE_COMMS_ERROR_SUCCESS;
}

enum rse_comms_error_t rse_comms_encrypt_msg(struct rse_comms_packet_t *msg, size_t packet_size,
                                             uint8_t trusted_subnet_id,
                                             rse_comms_node_id_t remote_node)
{
    (void)msg;
    (void)packet_size;
    (void)trusted_subnet_id;
    (void)remote_node;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_decrypt_msg(struct rse_comms_packet_t *msg, size_t packet_size,
                                             rse_comms_node_id_t remote_node)
{
    (void)msg;
    (void)packet_size;
    (void)remote_node;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_encrypt_reply(struct rse_comms_packet_t *reply, size_t packet_size,
                                               uint8_t trusted_subnet_id,
                                               rse_comms_node_id_t remote_node)
{
    (void)reply;
    (void)packet_size;
    (void)trusted_subnet_id;
    (void)remote_node;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum rse_comms_error_t rse_comms_decrypt_reply(struct rse_comms_packet_t *reply, size_t packet_size,
                                               rse_comms_node_id_t remote_node)
{
    (void)reply;
    (void)packet_size;
    (void)remote_node;

    return RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}
