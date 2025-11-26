/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include "sfcp_encryption.h"
#include "sfcp.h"
#include "sfcp_encryption_hal.h"

static enum sfcp_error_t encrypt_decrypt_packet(struct sfcp_packet_t *packet, size_t packet_size,
                                                uint8_t trusted_subnet_id,
                                                sfcp_node_id_t remote_node, bool encrypt)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_cryptography_metadata_t *crypto_metadata;
    struct sfcp_cryptography_config_t *crypto_config;
    struct sfcp_trusted_subnet_config_t *trusted_subnet;

    if (packet == NULL) {
        return SFCP_ERROR_INVALID_POINTER;
    }

    /* We have already checked this */
    assert(GET_METADATA_FIELD(USES_CRYPTOGRAPHY, packet->header.metadata));

    crypto_metadata = &packet->cryptography_used.cryptography_metadata;
    crypto_config = &crypto_metadata->config;

    if (!encrypt) {
        trusted_subnet_id = crypto_config->trusted_subnet_id;
    }

    sfcp_err = sfcp_get_trusted_subnet_by_id(trusted_subnet_id, &trusted_subnet);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (encrypt) {
        uint16_t seq_num;

        crypto_config->trusted_subnet_id = trusted_subnet->id;
        crypto_config->mode = trusted_subnet->mode;

        sfcp_err = sfcp_trusted_subnet_get_send_seq_num(trusted_subnet, remote_node, &seq_num);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        crypto_config->seq_num = seq_num;
    } else {
        sfcp_err = sfcp_trusted_subnet_check_recv_seq_num(trusted_subnet, remote_node,
                                                          crypto_config->seq_num);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    if (encrypt) {
        return sfcp_encryption_hal_encrypt_packet(trusted_subnet->key_id, packet, packet_size);
    } else {
        return sfcp_encryption_hal_decrypt_packet(trusted_subnet->key_id, packet, packet_size);
    }
}

enum sfcp_error_t sfcp_encrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   uint8_t trusted_subnet_id, sfcp_node_id_t remote_node)
{
    return encrypt_decrypt_packet(msg, packet_size, trusted_subnet_id, remote_node, true);
}

enum sfcp_error_t sfcp_decrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   sfcp_node_id_t remote_node)
{
    return encrypt_decrypt_packet(msg, packet_size, 0, remote_node, false);
}

enum sfcp_error_t sfcp_encrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     uint8_t trusted_subnet_id, sfcp_node_id_t remote_node)
{
    return encrypt_decrypt_packet(reply, packet_size, trusted_subnet_id, remote_node, true);
}

enum sfcp_error_t sfcp_decrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     sfcp_node_id_t remote_node)
{
    return encrypt_decrypt_packet(reply, packet_size, 0, remote_node, false);
}
