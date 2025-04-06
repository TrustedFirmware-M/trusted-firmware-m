/*
 * Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** \file cc3xx_psa_aead.c
 *
 * This file contains the implementation of the entry points associated to the
 * AEAD capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "cc3xx_psa_aead.h"
#include "cc3xx_crypto_primitives_private.h"
#include "cc3xx_misc.h"
#include "cc3xx_stdlib.h"
#include "cc3xx_internal_cipher.h"
#include "cc3xx_aes.h"
#if defined(PSA_WANT_ALG_CHACHA20_POLY1305)
#include "cc3xx_poly1305.h"
#endif /* PSA_WANT_ALG_CHACHA20_POLY1305 */
#include "cc3xx_chacha.h"
#include "cc3xx_rng.h"

/* ToDo: This needs to be sorted out at TF-M level
 * To be able to include the PSA style configuration
 */
#include "mbedtls/build_info.h"

/**
 * @brief Integrated authenticated ciphering with associated data (single-part)
 *
 * @param[in] attributes              Pointer to a key attributes structure
 * @param[in] key_buffer              Buffer containing the key material
 * @param[in] key_buffer_size         Size in bytes of the \ref key_buffer buffer
 * @param[in] alg                     Algorithm to be used, PSA_ALG_IS_AEAD() is true
 * @param[in] nonce                   Buffer containing the nonce to be used
 * @param[in] nonce_length            Size in bytes of the \ref nonce buffer
 * @param[in] additional_data         Buffer containing the data to be auhenticated (AAD)
 * @param[in] additional_data_length  Size in bytes of the \ref additional_data buffer
 * @param[in] input                   Buffer containing the input data to encrypt/decrypt
 * @param[in] input_length            Size in bytes of the \ref input buffer
 * @param[out] output                 Buffer to hold the output data (encrypted or decrypted)
 * @param[in] output_size             Size in bytes of the \ref output buffer
 * @param[out] output_length          Actual size of the encrypted or decrypted data produced
 * @param[in] dir                     Ciphering direction (encryption or decryption)
 * @return psa_status_t
 */
static psa_status_t aead_crypt(
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer, size_t key_buffer_size,
        psa_algorithm_t alg, const uint8_t *nonce,
        size_t nonce_length, const uint8_t *additional_data,
        size_t additional_data_length, const uint8_t *input,
        size_t input_length, uint8_t *output,
        size_t output_size, size_t *output_length,
        psa_encrypt_or_decrypt_t dir)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    cc3xx_err_t err;
    psa_key_type_t key_type;
    size_t key_bits;
    psa_algorithm_t default_alg = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);
    size_t tag_len;
    size_t bytes_produced_on_finish = 0;
    uint32_t local_tag[16 / sizeof(uint32_t)];
    size_t data_minus_tag;

    CC3XX_ASSERT(attributes != NULL);
    CC3XX_ASSERT(key_buffer != NULL);
    CC3XX_ASSERT(nonce != NULL);
    CC3XX_ASSERT(!additional_data_length ^ (additional_data != NULL));
    if (input_length != 0) {
        CC3XX_ASSERT(input != NULL);
    }
    CC3XX_ASSERT(!output_size ^ (output != NULL));
    CC3XX_ASSERT(output_length != NULL);

    key_type = psa_get_key_type(attributes);
    key_bits = psa_get_key_bits(attributes);
    tag_len = PSA_AEAD_TAG_LENGTH(key_type, key_bits, alg);

    /* In decryption the input contains data + tag */
    data_minus_tag = (dir == PSA_CRYPTO_DRIVER_DECRYPT) ? input_length - tag_len : input_length;

    /* The tag follows the input or the output based on direction */
    if (dir == PSA_CRYPTO_DRIVER_ENCRYPT) {
        if (output_size < input_length + tag_len) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
    } else {
        if (output_size < input_length - tag_len) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
        /* The input length takes into account at least the expected tag length */
        if (input_length < tag_len) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* Initialize this length to a safe value that might be overridden */
    *output_length = 0;

    /* Copy the tag into the local_tag buffer if it's a decryption flow */
    if (dir == PSA_CRYPTO_DRIVER_DECRYPT) {
        memcpy(local_tag, input + (input_length - tag_len), tag_len);
    }

    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
    case PSA_KEY_TYPE_CHACHA20:
    {
        uint32_t initial_counter = 0;

        if (default_alg != PSA_ALG_CHACHA20_POLY1305 ||
            key_buffer_size != CC3XX_CHACHA_KEY_SIZE) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        if (nonce_length == 16) {
            /* Read the counter value in little endian */
            initial_counter = (nonce[3] << 24) | (nonce[2] << 16) | (nonce[1] << 8) | nonce[0];
            /* Move iv and adjust iv_length */
            nonce += sizeof(uint32_t);
            nonce_length -= sizeof(uint32_t);
        }

        err = cc3xx_lowlevel_chacha20_init((dir == PSA_CRYPTO_DRIVER_ENCRYPT) ?
                CC3XX_CHACHA_DIRECTION_ENCRYPT : CC3XX_CHACHA_DIRECTION_DECRYPT,
                CC3XX_CHACHA_MODE_CHACHA_POLY1305, (uint32_t *)key_buffer,
                initial_counter, (uint32_t *)nonce, nonce_length);

        if (err != CC3XX_ERR_SUCCESS) {
            return cc3xx_to_psa_err(err);
        }

        /* Update AAD */
        if (additional_data_length) {
            cc3xx_lowlevel_chacha20_update_authed_data(additional_data, additional_data_length);
        }

        if (data_minus_tag) {
            /* Prepare to update inputs and produce outputs */
            cc3xx_lowlevel_chacha20_set_output_buffer(output, output_size);

            err = cc3xx_lowlevel_chacha20_update(input, data_minus_tag);
            if (err != CC3XX_ERR_SUCCESS) {
                status = cc3xx_to_psa_err(err);
                goto out;
            }
        }

        /* Finalize the output and produce the tag*/
        err = cc3xx_lowlevel_chacha20_finish(local_tag, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out;
        }
    }
    break;
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 && PSA_WANT_ALG_CHACHA20_POLY1305 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:
    {
        cc3xx_aes_keysize_t key_size;
        cc3xx_aes_mode_t mode;

        switch (key_buffer_size) {
        case 16:
            key_size = CC3XX_AES_KEYSIZE_128;
            break;
        case 24:
            key_size = CC3XX_AES_KEYSIZE_192;
            break;
        case 32:
            key_size = CC3XX_AES_KEYSIZE_256;
            break;
        default:
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        switch (default_alg) {
#if defined(PSA_WANT_ALG_GCM)
        case PSA_ALG_GCM:
            mode = CC3XX_AES_MODE_GCM;
            break;
#endif
#if defined(PSA_WANT_ALG_CCM)
        case PSA_ALG_CCM:
            mode = CC3XX_AES_MODE_CCM;
            break;
#endif
        default:
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        err = cc3xx_lowlevel_aes_init((dir == PSA_CRYPTO_DRIVER_ENCRYPT) ?
                CC3XX_AES_DIRECTION_ENCRYPT : CC3XX_AES_DIRECTION_DECRYPT,
                mode, CC3XX_AES_KEY_ID_USER_KEY,
                (uint32_t *)key_buffer, key_size,
                (uint32_t *)nonce, nonce_length);

        if (err != CC3XX_ERR_SUCCESS) {
            return cc3xx_to_psa_err(err);
        }

        /* AES modes need to have lengths set first */
        cc3xx_lowlevel_aes_set_tag_len(tag_len);

        cc3xx_lowlevel_aes_set_data_len(data_minus_tag, additional_data_length);

        /* Update AAD */
        if (additional_data_length) {
            cc3xx_lowlevel_aes_update_authed_data(additional_data, additional_data_length);
        }

        if (data_minus_tag) {
            /* Prepare to update inputs and produce outputs */
            cc3xx_lowlevel_aes_set_output_buffer(output, output_size);

            err = cc3xx_lowlevel_aes_update(input, data_minus_tag);
            if (err != CC3XX_ERR_SUCCESS) {
                status = cc3xx_to_psa_err(err);
                goto out;
            }
        }

        /* Finalize the output and produce the tag*/
        err = cc3xx_lowlevel_aes_finish(local_tag, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out;
        }
    }
    break;
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        (void)default_alg;
        (void)err;
        status = PSA_ERROR_NOT_SUPPORTED;
        goto out;
    }

    /* Bytes produced on finish will take into account all bytes up to finish, minus the tag */
    *output_length = bytes_produced_on_finish;

    if (dir == PSA_CRYPTO_DRIVER_ENCRYPT) {
        /* Put the tag in the correct place in output */
        memcpy(output + input_length, local_tag, tag_len);
        /* Add the tag */
        *output_length += tag_len;
    }

    status = PSA_SUCCESS;

out:
    memset(local_tag, 0, sizeof(local_tag));
    return status;
}

/** \defgroup psa_aead PSA driver entry points for AEAD encryption/decryption
 *
 *  Entry points for AEAD encryption and decryption as described
 *  by the PSA Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t cc3xx_aead_encrypt_setup(
        cc3xx_aead_operation_t *operation,
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer, size_t key_buffer_size,
        psa_algorithm_t alg)
{
    return cc3xx_internal_cipher_setup_init(operation,
                      attributes,
                      key_buffer, key_buffer_size,
                      alg, PSA_CRYPTO_DRIVER_ENCRYPT);
}

psa_status_t cc3xx_aead_decrypt_setup(
        cc3xx_aead_operation_t *operation,
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer, size_t key_buffer_size,
        psa_algorithm_t alg)
{
    return cc3xx_internal_cipher_setup_init(operation,
                        attributes,
                        key_buffer, key_buffer_size,
                        alg, PSA_CRYPTO_DRIVER_DECRYPT);
}

psa_status_t cc3xx_aead_set_nonce(
        cc3xx_aead_operation_t *operation,
        const uint8_t *nonce,
        size_t nonce_length)
{
    return cc3xx_internal_cipher_setup_set_iv(
                                operation, nonce, nonce_length);
}

psa_status_t cc3xx_aead_set_lengths(
        cc3xx_aead_operation_t *operation,
        size_t ad_length,
        size_t plaintext_length)
{
    CC3XX_ASSERT(operation != NULL);

    /* cc3xx_aead_operation_t is just an alias to cc3xx_cipher_operation_t */
    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
    case PSA_KEY_TYPE_CHACHA20:
        /* Chacha20-Poly1305 does not require to set the lengths
         * in advance nor setting the tag length which is fixed
         */
        return PSA_SUCCESS;
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 && PSA_WANT_ALG_CHACHA20_POLY1305 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:

#if defined(PSA_WANT_ALG_CCM)
        /* Only CCM requires this information to be set */
        if (PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(operation->alg) == PSA_ALG_CCM) {
            operation->aes.aes_to_auth_len = ad_length;
            operation->aes.aes_to_crypt_len = plaintext_length;
        }
#endif /* PSA_WANT_ALG_CCM */
        return PSA_SUCCESS;
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_aead_update_ad(
        cc3xx_aead_operation_t *operation,
        const uint8_t *input,
        size_t input_size)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    CC3XX_ASSERT(operation != NULL);

    /* This either restores the state or completes the init */
    status = cc3xx_internal_cipher_setup_complete(operation);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* cc3xx_aead_operation_t is just an alias to cc3xx_cipher_operation_t */
    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
    case PSA_KEY_TYPE_CHACHA20:

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        cc3xx_lowlevel_poly1305_update(input, input_size);
#else
        cc3xx_lowlevel_chacha20_update_authed_data(input, input_size);
#endif /* CC3XX_CONFIG_ENABLE_STREAM_CIPHER */

        cc3xx_lowlevel_chacha20_get_state(&operation->chacha);

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        /* Manually increment the authed length counter */
        operation->chacha.authed_len += input_size;
        cc3xx_lowlevel_poly1305_get_state(&(operation->chacha.poly_state));
#endif /* CC3XX_CONFIG_ENABLE_STREAM_CIPHER */

        cc3xx_lowlevel_chacha20_uninit();
        return PSA_SUCCESS;
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 && PSA_WANT_ALG_CHACHA20_POLY1305 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:

        cc3xx_lowlevel_aes_update_authed_data(input, input_size);

        cc3xx_lowlevel_aes_get_state(&operation->aes);

        cc3xx_lowlevel_aes_uninit();
        return PSA_SUCCESS;
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_aead_update(
        cc3xx_aead_operation_t *operation,
        const uint8_t *input,
        size_t input_length,
        uint8_t *output,
        size_t output_size,
        size_t *output_length)
{
    cc3xx_err_t err;
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t last_output_num_bytes = 0, current_output_size = 0;

    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(input != NULL);
    CC3XX_ASSERT(output != NULL);
    CC3XX_ASSERT(output_length != NULL);

    /* This either restores the state or completes the init */
    status = cc3xx_internal_cipher_setup_complete(operation);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* cc3xx_aead_operation_t is just an alias to cc3xx_cipher_operation_t */
    last_output_num_bytes = operation->last_output_num_bytes;
    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
    case PSA_KEY_TYPE_CHACHA20:
    {
        size_t processed_length;

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        const uint8_t *bufs[2] = {input, output};
        /* If stream cipher behaviour is enabled, process with any available keystream */
        status = cc3xx_internal_cipher_stream_pre_update(
            &(operation->stream), input, input_length,
                output, output_size, output_length);

	if (status != PSA_SUCCESS) {
            goto out_chacha20;
        }

        input += *output_length;
        input_length -= *output_length;
        output_size -= *output_length;
        output += *output_length;

        processed_length = (input_length / CC3XX_CHACHA_BLOCK_SIZE) * CC3XX_CHACHA_BLOCK_SIZE;
#else
        processed_length = input_length;
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */

        cc3xx_lowlevel_chacha20_set_output_buffer(output, output_size);

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        if ((operation->chacha.authed_len % 16) && !operation->chacha.crypted_len) {
            const uint8_t pad[15] = {0};
            cc3xx_lowlevel_poly1305_update(pad, 16 - operation->chacha.authed_len % 16);
        }
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */

        err = cc3xx_lowlevel_chacha20_update(input, processed_length);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_chacha20;
        }

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        *output_length += processed_length;

        status = cc3xx_internal_cipher_stream_post_update(
            &(operation->stream), processed_length, input, input_length,
                output, output_size, output_length);
        if (status != PSA_SUCCESS) {
            goto out_chacha20;
        }
#else
        current_output_size = cc3xx_lowlevel_chacha20_get_current_output_size();

        *output_length = current_output_size - last_output_num_bytes;

        operation->last_output_num_bytes = current_output_size;
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */

        cc3xx_lowlevel_chacha20_get_state(&operation->chacha);

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        if (operation->chacha.direction == CC3XX_CHACHA_DIRECTION_ENCRYPT) {
            cc3xx_lowlevel_poly1305_update(bufs[1], *output_length);
        } else {
            /* input_length and output_length are the same by construction */
            cc3xx_lowlevel_poly1305_update(bufs[0], *output_length);
        }
        /* Manually increment the encrypted length counter */
        operation->chacha.crypted_len += *output_length;
        cc3xx_lowlevel_poly1305_get_state(&(operation->chacha.poly_state));
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */

        status = PSA_SUCCESS;

out_chacha20:
        cc3xx_lowlevel_chacha20_uninit();
        return status;
    }
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 && PSA_WANT_ALG_CHACHA20_POLY1350 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:

        cc3xx_lowlevel_aes_set_output_buffer(output, output_size);

        err = cc3xx_lowlevel_aes_update(input, input_length);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_aes;
        }
        current_output_size = cc3xx_lowlevel_aes_get_current_output_size();

        *output_length = current_output_size - last_output_num_bytes;

        operation->last_output_num_bytes = current_output_size;

        cc3xx_lowlevel_aes_get_state(&operation->aes);

        status = PSA_SUCCESS;
out_aes:
        cc3xx_lowlevel_aes_uninit();
        return status;
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        (void)err;
        (void)current_output_size;
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_aead_finish(
        cc3xx_aead_operation_t *operation,
        uint8_t *ciphertext,
        size_t ciphertext_size,
        size_t *ciphertext_length,
        uint8_t *tag,
        size_t tag_size,
        size_t *tag_length)
{
    cc3xx_err_t err;
    psa_status_t status;
    size_t bytes_produced_on_finish;
    uint32_t local_tag[16 / sizeof(uint32_t)];

    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(!ciphertext_size ^ (ciphertext != NULL));
    CC3XX_ASSERT(ciphertext_length != NULL);
    CC3XX_ASSERT(tag != NULL);
    CC3XX_ASSERT(tag_length != NULL);

    /* Initialize */
    *ciphertext_length = 0;
    *tag_length = 0;

    if (operation->cipher_is_initialized == false) {
        /* This means it was never updated with any data, so just exit now */
        return PSA_SUCCESS;
    }

    CC3XX_ASSERT(tag_size >= PSA_AEAD_TAG_LENGTH(operation->key_type, operation->key_bits, operation->alg));

    /* cc3xx_aead_operation_t is just an alias to cc3xx_cipher_operation_t */
    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
    case PSA_KEY_TYPE_CHACHA20:
#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        cc3xx_lowlevel_poly1305_set_state(&(operation->chacha.poly_state));

        if (operation->chacha.crypted_len % 16) {
            const uint8_t pad[15] = {0};
            cc3xx_lowlevel_poly1305_update(pad, 16 - operation->chacha.crypted_len % 16);
        }

        uint32_t last_block[16 / sizeof(uint32_t)];
        /* Assumes the size_t are LE stored */
        last_block[0] = operation->chacha.authed_len;
        last_block[1] = 0;
        last_block[2] = operation->chacha.crypted_len;
        last_block[3] = 0;

        cc3xx_lowlevel_poly1305_update((uint8_t *)last_block, sizeof(last_block));

        cc3xx_lowlevel_poly1305_finish(local_tag);

        *tag_length = POLY1305_TAG_LEN;
        memcpy(tag, local_tag, *tag_length);
        return PSA_SUCCESS;
#else
        cc3xx_lowlevel_chacha20_set_state(&(operation->chacha));

        cc3xx_lowlevel_chacha20_set_output_buffer(ciphertext, ciphertext_size);

        err = cc3xx_lowlevel_chacha20_finish(local_tag, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_chacha20;
        }

        *ciphertext_length = bytes_produced_on_finish - operation->last_output_num_bytes;

        operation->last_output_num_bytes = bytes_produced_on_finish;

        *tag_length = POLY1305_TAG_LEN;
        memcpy(tag, local_tag, *tag_length);
        return PSA_SUCCESS;

out_chacha20:
        cc3xx_lowlevel_chacha20_uninit();
#endif /* !defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
        return status;
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 && PSA_WANT_ALG_CHACHA20_POLY1305 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:

        cc3xx_lowlevel_aes_set_state(&(operation->aes));

        cc3xx_lowlevel_aes_set_output_buffer(ciphertext, ciphertext_size);

        err = cc3xx_lowlevel_aes_finish(local_tag, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_aes;
        }

        *ciphertext_length = bytes_produced_on_finish - operation->last_output_num_bytes;

        operation->last_output_num_bytes = bytes_produced_on_finish;

        *tag_length = operation->aes.aes_tag_len;
        memcpy(tag, local_tag, *tag_length);
        return PSA_SUCCESS;

out_aes:
        cc3xx_lowlevel_aes_uninit();
        return status;
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        (void)err;
        (void)local_tag;
        (void)bytes_produced_on_finish;
        (void)status;
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_aead_verify(
        cc3xx_aead_operation_t *operation,
        uint8_t *plaintext,
        size_t plaintext_size,
        size_t *plaintext_length,
        const uint8_t *tag,
        size_t tag_size)
{
    cc3xx_err_t err;
    psa_status_t status;
    size_t bytes_produced_on_finish;
    uint32_t local_tag[16 / sizeof(uint32_t)];

    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(!plaintext_size ^ (plaintext != NULL));
    CC3XX_ASSERT(plaintext_length != NULL);
    CC3XX_ASSERT(tag != NULL);
    CC3XX_ASSERT(tag_size <= 16);

    if (operation->cipher_is_initialized == false) {
        /* This means it was never updated with any data, so just exit now */
        return PSA_SUCCESS;
    }

    /* Copy the tag in a 4-byte aligned local buffer */
    memcpy(local_tag, tag, tag_size);

    /* cc3xx_aead_operation_t is just an alias to cc3xx_cipher_operation_t */
    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
    case PSA_KEY_TYPE_CHACHA20:
    {
#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        uint8_t diff, idx;
        const uint32_t tag_word_size = 4;
        uint8_t permutation_buf[tag_word_size];

        if (tag_size != POLY1305_TAG_LEN) {
            return PSA_ERROR_INVALID_SIGNATURE;
        }
        cc3xx_lowlevel_poly1305_set_state(&(operation->chacha.poly_state));

        if (operation->chacha.crypted_len % 16) {
            const uint8_t pad[15] = {0};
            cc3xx_lowlevel_poly1305_update(pad, 16 - operation->chacha.crypted_len % 16);
        }

        uint32_t last_block[16 / sizeof(uint32_t)];
        /* Assumes the size_t are LE stored */
        last_block[0] = operation->chacha.authed_len;
        last_block[1] = 0;
        last_block[2] = operation->chacha.crypted_len;
        last_block[3] = 0;

        cc3xx_lowlevel_poly1305_update((uint8_t *)last_block, sizeof(last_block));

        cc3xx_lowlevel_poly1305_finish(local_tag);

        /* Generate a random permutation */
        cc3xx_lowlevel_rng_get_random_permutation(permutation_buf, tag_word_size,
                                                  CC3XX_RNG_FAST);

        /* Check tag in "constant-time" */
        for (diff = 0, idx = 0; idx < tag_word_size; idx++) {
            diff |= ((uint32_t *)tag)[permutation_buf[idx]] ^ local_tag[permutation_buf[idx]];
        }

        if (diff != 0) {
            status = PSA_ERROR_INVALID_SIGNATURE;
        } else {
            status = PSA_SUCCESS;
        }
#else
        cc3xx_lowlevel_chacha20_set_state(&(operation->chacha));

        cc3xx_lowlevel_chacha20_set_output_buffer(plaintext, plaintext_size);

        err = cc3xx_lowlevel_chacha20_finish(local_tag, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_chacha20;
        }

        *plaintext_length = bytes_produced_on_finish - operation->last_output_num_bytes;

        operation->last_output_num_bytes = bytes_produced_on_finish;

        status = PSA_SUCCESS;

out_chacha20:
        cc3xx_lowlevel_chacha20_uninit();
#endif /* !defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
        return status;
    }
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 && PSA_WANT_ALG_CHACHA20_POLY1305 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:

        cc3xx_lowlevel_aes_set_state(&(operation->aes));

        cc3xx_lowlevel_aes_set_output_buffer(plaintext, plaintext_size);

        err = cc3xx_lowlevel_aes_finish(local_tag, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_aes;
        }

        *plaintext_length = bytes_produced_on_finish - operation->last_output_num_bytes;

        operation->last_output_num_bytes = bytes_produced_on_finish;

        status = PSA_SUCCESS;

out_aes:
        cc3xx_lowlevel_aes_uninit();
        return status;
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        (void)bytes_produced_on_finish;
        (void)err;
        (void)status;
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_aead_abort(cc3xx_aead_operation_t *operation)
{
    cc3xx_secure_erase_buffer((uint32_t *)operation, sizeof(cc3xx_aead_operation_t) / sizeof(uint32_t));
    return PSA_SUCCESS;
}

psa_status_t cc3xx_aead_encrypt(
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer, size_t key_buffer_size,
        psa_algorithm_t alg, const uint8_t *nonce,
        size_t nonce_length, const uint8_t *additional_data,
        size_t additional_data_length, const uint8_t *plaintext,
        size_t plaintext_length, uint8_t *ciphertext,
        size_t ciphertext_size, size_t *ciphertext_length)
{
    return aead_crypt(
        attributes, key_buffer, key_buffer_size, alg,
        nonce, nonce_length, additional_data, additional_data_length,
        plaintext, plaintext_length, ciphertext, ciphertext_size, ciphertext_length,
        PSA_CRYPTO_DRIVER_ENCRYPT);
}

psa_status_t cc3xx_aead_decrypt(
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer, size_t key_buffer_size,
        psa_algorithm_t alg, const uint8_t *nonce,
        size_t nonce_length, const uint8_t *additional_data,
        size_t additional_data_length, const uint8_t *ciphertext,
        size_t ciphertext_length, uint8_t *plaintext,
        size_t plaintext_size, size_t *plaintext_length)
{
    return aead_crypt(
        attributes, key_buffer, key_buffer_size, alg,
        nonce, nonce_length, additional_data, additional_data_length,
        ciphertext, ciphertext_length, plaintext, plaintext_size, plaintext_length,
        PSA_CRYPTO_DRIVER_DECRYPT);
}
/** @} */ // end of psa_aead
