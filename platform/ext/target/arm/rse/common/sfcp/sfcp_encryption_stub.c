/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "sfcp_encryption.h"

enum sfcp_error_t
sfcp_get_trusted_subnet_by_id(uint8_t trusted_subnet_id,
                              struct sfcp_trusted_subnet_config_t **trusted_subnet)
{
    (void)trusted_subnet_id;
    (void)trusted_subnet;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t
sfcp_trusted_subnet_get_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                               sfcp_node_id_t *server_node)
{
    (void)trusted_subnet;
    (void)server_node;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_trusted_subnet_state_init(void)
{
    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_trusted_subnet_get_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t *state)
{
    (void)trusted_subnet_id;
    (void)state;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_trusted_subnet_set_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t state)
{
    (void)trusted_subnet_id;
    (void)state;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_get_number_trusted_subnets(size_t *num_trusted_subnets)
{
    (void)num_trusted_subnets;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t
sfcp_get_trusted_subnet_for_node(sfcp_node_id_t node,
                                 struct sfcp_trusted_subnet_config_t **trusted_subnet)
{
    (void)node;
    (void)trusted_subnet;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t
sfcp_trusted_subnet_get_send_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                     sfcp_node_id_t remote_node, uint16_t *seq_num)
{
    (void)trusted_subnet;
    (void)remote_node;
    (void)seq_num;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_trusted_subnet_state_requires_encryption(uint8_t trusted_subnet_id,
                                                                bool *requires_encryption)
{
    (void)trusted_subnet_id;
    (void)requires_encryption;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_encryption_handshake_initiator(uint8_t trusted_subnet_id, bool block)
{
    (void)trusted_subnet_id;
    (void)block;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_encryption_handshake_responder(struct sfcp_packet_t *packet,
                                                      size_t packet_size,
                                                      sfcp_node_id_t remote_node,
                                                      uint8_t message_id, bool packet_encrypted,
                                                      uint8_t *payload, size_t payload_size,
                                                      bool *is_handshake_msg)
{
    (void)remote_node;
    (void)message_id;
    (void)payload;
    (void)payload_size;
    (void)packet_encrypted;

    *is_handshake_msg = false;
    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   uint8_t trusted_subnet_id, sfcp_node_id_t remote_node)
{
    (void)msg;
    (void)packet_size;
    (void)trusted_subnet_id;
    (void)remote_node;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_decrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   sfcp_node_id_t remote_node)
{
    (void)msg;
    (void)packet_size;
    (void)remote_node;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_encrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     uint8_t trusted_subnet_id, sfcp_node_id_t remote_node)
{
    (void)reply;
    (void)packet_size;
    (void)trusted_subnet_id;
    (void)remote_node;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}

enum sfcp_error_t sfcp_decrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     sfcp_node_id_t remote_node)
{
    (void)reply;
    (void)packet_size;
    (void)remote_node;

    return SFCP_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED;
}
