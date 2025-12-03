/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include "sfcp_encryption_hal.h"
#include "sfcp_defs.h"
#include "psa/crypto.h"
#include "fih.h"
#include "rse_kmu_keys.h"
#include "cc3xx_opaque_keys.h"

static psa_hash_operation_t hash_op;

static enum sfcp_error_t sfcp_mode_to_psa_alg(enum sfcp_cryptography_mode_t crypto_mode,
                                              psa_algorithm_t *psa_alg)
{
    switch (crypto_mode) {
    case SFCP_CRYPTOGRAPHY_MODE_AES256_CCM:
        *psa_alg = PSA_ALG_CCM;
        return SFCP_ERROR_SUCCESS;
    default:
        return SFCP_ERROR_INVALID_CRYPTO_MODE;
    }
}

static enum sfcp_error_t encrypt_decrypt_packet(uint32_t key_id, struct sfcp_packet_t *packet,
                                                size_t packet_size, bool encrypt)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_cryptography_metadata_t *crypto_metadata;
    struct sfcp_cryptography_config_t *crypto_config;
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

    crypto_metadata = &packet->cryptography_used.cryptography_metadata;
    crypto_config = &crypto_metadata->config;
    uses_id_extension = GET_METADATA_FIELD(USES_ID_EXTENSION, packet->header.metadata);
    data_size_to_auth =
        SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, uses_id_extension) - sizeof(*crypto_metadata);
    data_size_to_crypt = packet_size - SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, uses_id_extension);
    payload_ptr = (uint8_t *)GET_SFCP_PAYLOAD_PTR(packet, true, uses_id_extension);

    sfcp_err = sfcp_mode_to_psa_alg(crypto_config->mode, &psa_alg);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (encrypt) {
        psa_status = psa_aead_encrypt_setup(&operation, key_id, psa_alg);
        if (psa_status != PSA_SUCCESS) {
            goto error_out;
        }
    } else {
        psa_status = psa_aead_decrypt_setup(&operation, key_id, psa_alg);
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
        psa_status = psa_aead_update_ad(&operation, (uint8_t *)&GET_SFCP_CLIENT_ID(packet, true),
                                        sizeof(GET_SFCP_CLIENT_ID(packet, true)) +
                                            sizeof(GET_SFCP_APPLICATION_ID(packet, true)));
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

    return SFCP_ERROR_SUCCESS;

error_out:
    (void)psa_aead_abort(&operation);
    return encrypt ? SFCP_ERROR_ENCRYPTION_FAILED : SFCP_ERROR_DECRYPTION_FAILED;
}

enum sfcp_error_t sfcp_encryption_hal_encrypt_packet(uint32_t key_id, struct sfcp_packet_t *packet,
                                                     size_t packet_size)
{
    return encrypt_decrypt_packet(key_id, packet, packet_size, true);
}

enum sfcp_error_t sfcp_encryption_hal_decrypt_packet(uint32_t key_id, struct sfcp_packet_t *packet,
                                                     size_t packet_size)
{
    return encrypt_decrypt_packet(key_id, packet, packet_size, false);
}

uint32_t sfcp_encryption_hal_save_disable_irq(void)
{
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    return primask;
}

void sfcp_encryption_hal_enable_irq(uint32_t cookie)
{
    __set_PRIMASK(cookie);
}

enum sfcp_error_t sfcp_encryption_hal_generate_random(uint8_t *output, size_t output_size)
{
    psa_status_t status;

    status = psa_generate_random(output, output_size);
    if (status != PSA_SUCCESS) {
        return SFCP_ERROR_HANDSHAKE_GENERATE_RANDOM_FAILURE;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encryption_hal_hash_init(enum sfcp_encryption_hal_hash_alg_t alg)
{
    psa_algorithm_t psa_alg;
    psa_status_t status;

    switch (alg) {
    case SFCP_ENCRYPTION_HAL_HASH_ALG_SHA256:
        psa_alg = PSA_ALG_SHA_256;
        break;
    case SFCP_ENCRYPTION_HAL_HASH_ALG_SHA384:
        psa_alg = PSA_ALG_SHA_384;
        break;
    default:
        return SFCP_ERROR_HANDSHAKE_HASH_ALG_UNSUPPORTED;
    }

    hash_op = psa_hash_operation_init();

    status = psa_hash_setup(&hash_op, psa_alg);
    if (status != PSA_SUCCESS) {
        return SFCP_ERROR_HANDSHAKE_HASH_FAILURE;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encryption_hal_hash_update(uint8_t *data, size_t data_size)
{
    psa_status_t status;

    status = psa_hash_update(&hash_op, data, data_size);
    if (status != PSA_SUCCESS) {
        return SFCP_ERROR_HANDSHAKE_HASH_FAILURE;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encryption_hal_hash_finish(uint8_t *hash, size_t hash_len,
                                                  size_t *hash_size)
{
    psa_status_t status;

    status = psa_hash_finish(&hash_op, hash, hash_len, hash_size);
    if (status != PSA_SUCCESS) {
        return SFCP_ERROR_HANDSHAKE_HASH_FAILURE;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encryption_hal_setup_session_key(uint8_t *seed, size_t seed_len,
                                                        uint32_t *output_key_id)
{
    enum tfm_plat_err_t plat_err;

    plat_err = rse_setup_session_key(seed, seed_len, output_key_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return SFCP_ERROR_HANDSHAKE_SETUP_SESSION_KEY_FAILURE;
    }

    *output_key_id = cc3xx_get_opaque_key(*output_key_id);
    assert(!CC3XX_IS_OPAQUE_KEY_INVALID(*output_key_id));

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encryption_hal_rekey_session_key(uint8_t *seed, size_t seed_len,
                                                        uint32_t input_key_id,
                                                        uint32_t *output_key_id)
{
    enum tfm_plat_err_t plat_err;

    plat_err =
        rse_rekey_session_key(seed, seed_len, cc3xx_get_builtin_key(input_key_id), output_key_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return SFCP_ERROR_HANDSHAKE_REKEY_SESSION_KEY_FAILURE;
    }

    *output_key_id = cc3xx_get_opaque_key(*output_key_id);
    assert(!CC3XX_IS_OPAQUE_KEY_INVALID(*output_key_id));

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encryption_hal_invalidate_session_key(uint32_t key_id)
{
    enum tfm_plat_err_t plat_err;

    plat_err = rse_invalidate_session_key(cc3xx_get_builtin_key(key_id));
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return SFCP_ERROR_HANDSHAKE_INVALIDATE_SESSION_KEY_FAILURE;
    }

    return SFCP_ERROR_SUCCESS;
}
