/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_encryption.h"
#include "rse_comms_link_hal.h"
#include "rse_comms_helpers.h"
#include "rse_comms.h"
#include "cc3xx_opaque_keys.h"
#include "rse_kmu_keys.h"
#include "psa/crypto.h"
#include "bl1_random.h"

static enum rse_comms_error_t
rse_comms_mode_to_psa_alg(enum rse_comms_cryptography_mode_t comms_mode, psa_algorithm_t *psa_alg)
{
    switch (comms_mode) {
    case RSE_COMMS_CRYPTOGRAPHY_MODE_AES256_CCM:
        *psa_alg = PSA_ALG_CCM;
        return RSE_COMMS_ERROR_SUCCESS;
    default:
        return RSE_COMMS_ERROR_INVALID_CRYPTO_MODE;
    }
}

static enum rse_comms_error_t encrypt_decrypt_packet(struct rse_comms_packet_t *packet,
                                                     size_t packet_size, uint8_t trusted_subnet_id,
                                                     rse_comms_node_id_t remote_node, bool encrypt)
{
    enum rse_comms_error_t comms_err;
    struct rse_comms_cryptography_metadata_t *crypto_metadata;
    struct rse_comms_cryptography_config_t *crypto_config;
    struct rse_comms_trusted_subnet_config_t *trusted_subnet;
    bool uses_id_extension;
    size_t data_size_to_crypt;
    size_t data_size_to_auth;
    psa_aead_operation_t operation = psa_aead_operation_init();
    psa_algorithm_t psa_alg;
    psa_status_t psa_status;
    uint8_t *payload_ptr;
    size_t data_size_encrypted;
    __ALIGNED(4) uint8_t additional_encrypted_data[15];
    size_t additional_encrypted_data_size;

    if (packet == NULL) {
        return RSE_COMMS_ERROR_INVALID_POINTER;
    }

    /* We have already checked this */
    assert(GET_METADATA_FIELD(USES_CRYPTOGRAPHY, packet->header.metadata));

    crypto_metadata = &packet->cryptography_used.cryptography_metadata;
    crypto_config = &crypto_metadata->config;
    uses_id_extension = GET_METADATA_FIELD(USES_ID_EXTENSION, packet->header.metadata);
    data_size_to_auth =
        RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, uses_id_extension) - sizeof(*crypto_metadata);
    data_size_to_crypt = packet_size - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, uses_id_extension);
    payload_ptr = (uint8_t *)GET_RSE_COMMS_PAYLOAD_PTR(packet, true, uses_id_extension);

    if (!encrypt) {
        trusted_subnet_id = crypto_config->trusted_subnet_id;
    }

    comms_err = rse_comms_get_trusted_subnet_by_id(trusted_subnet_id, &trusted_subnet);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return comms_err;
    }

    if (encrypt) {
        uint16_t seq_num;

        crypto_config->trusted_subnet_id = trusted_subnet->id;
        crypto_config->mode = trusted_subnet->mode;

        comms_err =
            rse_comms_trusted_subnet_get_send_seq_num(trusted_subnet, remote_node, &seq_num);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return comms_err;
        }

        crypto_config->seq_num = seq_num;
    } else {
        comms_err = rse_comms_trusted_subnet_check_recv_seq_num(trusted_subnet, remote_node,
                                                                crypto_config->seq_num);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return comms_err;
        }
    }

    comms_err = rse_comms_mode_to_psa_alg(crypto_config->mode, &psa_alg);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return comms_err;
    }

    if (encrypt) {
        psa_status = psa_aead_encrypt_setup(&operation, trusted_subnet->key_id, psa_alg);
        if (psa_status != PSA_SUCCESS) {
            goto error_out;
        }
    } else {
        psa_status = psa_aead_decrypt_setup(&operation, trusted_subnet->key_id, psa_alg);
        if (psa_status != PSA_SUCCESS) {
            goto error_out;
        }
    }

    psa_status = psa_aead_set_lengths(&operation, data_size_to_auth, data_size_to_crypt);
    if (psa_status != PSA_SUCCESS) {
        goto error_out;
    }

    psa_status = psa_aead_set_nonce(
        &operation, (uint8_t *)packet,
        sizeof(packet->header) + sizeof(packet->cryptography_used.cryptography_metadata.config));
    if (psa_status != PSA_SUCCESS) {
        goto error_out;
    }

    psa_status = psa_aead_update_ad(&operation, (uint8_t *)&packet->header, sizeof(packet->header));
    if (psa_status != PSA_SUCCESS) {
        goto error_out;
    }

    if (uses_id_extension) {
        psa_status = psa_aead_update_ad(&operation,
                                        (uint8_t *)&GET_RSE_COMMS_CLIENT_ID(packet, true),
                                        sizeof(GET_RSE_COMMS_CLIENT_ID(packet, true)) +
                                            sizeof(GET_RSE_COMMS_APPLICATION_ID(packet, true)));
        if (psa_status != PSA_SUCCESS) {
            goto error_out;
        }
    }

    if (data_size_to_crypt != 0) {
        psa_status = psa_aead_update(&operation, payload_ptr, data_size_to_crypt, payload_ptr,
                                     data_size_to_crypt, &data_size_encrypted);
        if (psa_status != PSA_SUCCESS) {
            goto error_out;
        }
    } else {
        data_size_encrypted = 0;
    }

    if (encrypt) {
        size_t tag_length;

        psa_status = psa_aead_finish(&operation, additional_encrypted_data,
                                     sizeof(additional_encrypted_data),
                                     &additional_encrypted_data_size,
                                     (uint8_t *)crypto_metadata->tag, sizeof(crypto_metadata->tag),
                                     &tag_length);
        if (psa_status != PSA_SUCCESS) {
            goto error_out;
        }

        if (tag_length != sizeof(crypto_metadata->tag)) {
            goto error_out;
        }
    } else {
        psa_status = psa_aead_verify(&operation, additional_encrypted_data,
                                     sizeof(additional_encrypted_data),
                                     &additional_encrypted_data_size,
                                     (uint8_t *)crypto_metadata->tag, sizeof(crypto_metadata->tag));
        if (psa_status != PSA_SUCCESS) {
            goto error_out;
        }
    }

    if ((data_size_encrypted + additional_encrypted_data_size) != data_size_to_crypt) {
        goto error_out;
    }

    if (additional_encrypted_data_size > 0) {
        /* Copy the remaining bytes which have been encrypted back into the packet */
        memcpy(payload_ptr + data_size_encrypted, additional_encrypted_data,
               additional_encrypted_data_size);
    }

    return RSE_COMMS_ERROR_SUCCESS;

error_out:
    return encrypt ? RSE_COMMS_ERROR_ENCRYPTION_FAILED : RSE_COMMS_ERROR_DECRYPTION_FAILED;
}

enum rse_comms_error_t rse_comms_encrypt_msg(struct rse_comms_packet_t *msg, size_t packet_size,
                                             uint8_t trusted_subnet_id,
                                             rse_comms_node_id_t remote_node)
{
    return encrypt_decrypt_packet(msg, packet_size, trusted_subnet_id, remote_node, true);
}

enum rse_comms_error_t rse_comms_decrypt_msg(struct rse_comms_packet_t *msg, size_t packet_size,
                                             rse_comms_node_id_t remote_node)
{
    return encrypt_decrypt_packet(msg, packet_size, 0, remote_node, false);
}

enum rse_comms_error_t rse_comms_encrypt_reply(struct rse_comms_packet_t *reply, size_t packet_size,
                                               uint8_t trusted_subnet_id,
                                               rse_comms_node_id_t remote_node)
{
    return encrypt_decrypt_packet(reply, packet_size, trusted_subnet_id, remote_node, true);
}

enum rse_comms_error_t rse_comms_decrypt_reply(struct rse_comms_packet_t *reply, size_t packet_size,
                                               rse_comms_node_id_t remote_node)
{
    return encrypt_decrypt_packet(reply, packet_size, 0, remote_node, false);
}
