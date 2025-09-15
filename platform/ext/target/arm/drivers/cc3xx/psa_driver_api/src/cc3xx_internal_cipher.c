/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** \file cc3xx_internal_cipher.c
 *
 * This file contains the implementation of internal functions
 * required by the PSA driver modules to request functionalities
 * from the low level driver ciphers that are common to multiple
 * PSA API modules, i.e. they can be shared.
 */

/* ToDo: This needs to be sorted out at TF-M level
 * To be able to include the PSA style configuration
 */
#include "mbedtls/build_info.h"

#include <string.h>
#include "psa/crypto.h"
#include "cc3xx_crypto_primitives_private.h"
#include "cc3xx_stdlib.h"
#include "cc3xx_misc.h"
#include "cc3xx_internal_cipher.h"
#include "cc3xx_aes.h"
#include "cc3xx_chacha.h"
#include "cc3xx_poly1305.h"
#ifndef CC3XX_PSA_API_CONFIG_FILE
#include "cc3xx_psa_api_config.h"
#else
#include CC3XX_PSA_API_CONFIG_FILE
#endif
#include "cc3xx_rng.h"
#include "cc3xx_opaque_keys.h"

#if defined(PSA_WANT_KEY_TYPE_AES)
/**
 * @brief Setup AES internally. This can be called either from Cipher or AEAD
 *        modules
 *
 * @param[out] state           Low level driver state object for AES
 * @param[in]  attributes      Key attributes structure
 * @param[in]  key_buffer      Buffer containing the key material
 * @param[in]  key_buffer_size Size in bytes containing the key material
 * @param[in]  alg             Algorithm to be used with AES
 * @param[in]  dir             Encrypt or decrypt direction
 * @return psa_status_t
 */
static psa_status_t cc3xx_internal_aes_setup(
    struct cc3xx_aes_state_t *state,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    psa_encrypt_or_decrypt_t dir)
{
    const psa_algorithm_t default_alg = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);
    cc3xx_aes_keysize_t key_size;
    cc3xx_aes_mode_t mode;
    cc3xx_aes_key_id_t key_id = CC3XX_AES_KEY_ID_USER_KEY;

#ifdef CC3XX_CRYPTO_OPAQUE_KEYS
    if (CC3XX_IS_OPAQUE_KEY(attributes)) {
        size_t opaque_key_id = (size_t)key_buffer;
        key_id = (cc3xx_aes_key_id_t)cc3xx_get_builtin_key(opaque_key_id);

        if (CC3XX_IS_OPAQUE_KEY_INVALID(key_id)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }
#endif /* CC3XX_CRYPTO_OPAQUE_KEYS */

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

    memset(state, 0, sizeof(struct cc3xx_aes_state_t));

    switch (alg) {
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
    case PSA_ALG_CBC_NO_PADDING:
        mode = CC3XX_AES_MODE_CBC;
        break;
#endif
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    case PSA_ALG_CBC_PKCS7:
        mode = CC3XX_AES_MODE_CBC;
        break;
#endif
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
    case PSA_ALG_ECB_NO_PADDING:
        mode = CC3XX_AES_MODE_ECB;
        break;
#endif
#if defined(PSA_WANT_ALG_CTR)
    case PSA_ALG_CTR:
        mode = CC3XX_AES_MODE_CTR;
        break;
#endif
    default:
        /* Check if this is an AEAD mode if it does not match any Cipher */
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
    }

    /* Just use the state object as a cache */
    state->mode = mode;
    state->direction = (dir == PSA_CRYPTO_DRIVER_ENCRYPT) ?
                CC3XX_AES_DIRECTION_ENCRYPT : CC3XX_AES_DIRECTION_DECRYPT;
    state->key_size = key_size;
    state->key_id = key_id;

    if (key_id == CC3XX_AES_KEY_ID_USER_KEY) {
        cc3xx_dpa_hardened_word_copy(state->key_buf, (uint32_t *)key_buffer,
                                     key_buffer_size / sizeof(uint32_t));
    }

    return PSA_SUCCESS;
}
#endif /* PSA_WANT_KEY_TYPE_AES */

#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
/**
 * @brief Setup CHACHA internally. This can be called either from Cipher or AEAD
 *        modules
 *
 * @param[out] state           Low level driver state object for CHACHA
 * @param[in]  attributes      Key attributes structure
 * @param[in]  key_buffer      Buffer containing the key material
 * @param[in]  key_buffer_size Size in bytes containing the key material
 * @param[in]  alg             Algorithm to be used with CHACHA
 * @param[in]  dir             Encrypt or decrypt direction
 * @return psa_status_t
 */
static psa_status_t cc3xx_internal_chacha_setup(
    struct cc3xx_chacha_state_t *state,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    psa_encrypt_or_decrypt_t dir)
{
    const psa_algorithm_t default_alg = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);
    cc3xx_chacha_mode_t mode;

    if (key_buffer_size != CC3XX_CHACHA_KEY_SIZE) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    memset(state, 0, sizeof(struct cc3xx_chacha_state_t));

    switch (alg) {
#if defined(PSA_WANT_ALG_STREAM_CIPHER)
    case PSA_ALG_STREAM_CIPHER:
        mode = CC3XX_CHACHA_MODE_CHACHA;
        break;
#endif
    default:
        /* Check if this is an AEAD mode if it does not match any Cipher */
        switch (default_alg) {
#if defined(PSA_WANT_ALG_CHACHA20_POLY1305)
        case PSA_ALG_CHACHA20_POLY1305:
#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
            /* For CC3XX_CONFIG_ENABLE_STREAM_CIPHER, the low level driver
             * CHACHA module is just used in non-authenticated mode, and the
             * Poly1305 computation is called directly from the PSA API layer
             */
            mode = CC3XX_CHACHA_MODE_CHACHA;
#else
            mode = CC3XX_CHACHA_MODE_CHACHA_POLY1305;
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
            break;
#endif /* defined(PSA_WANT_ALG_CHACHA20_POLY1305) */
        default:
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* Just use the state object as a cache */
    state->mode = mode;
    state->direction = (dir == PSA_CRYPTO_DRIVER_ENCRYPT) ?
                CC3XX_CHACHA_DIRECTION_ENCRYPT : CC3XX_CHACHA_DIRECTION_DECRYPT;

    cc3xx_dpa_hardened_word_copy(state->key, (uint32_t *)key_buffer,
                                key_buffer_size / sizeof(uint32_t));
    return PSA_SUCCESS;
}

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
/**
 * @brief Generates the One Time Key for Chacha20-Poly1305 as per RFC 7539
 *
 * @param[in]  key          Key to be used for the AEAD operation
 * @param[in]  nonce        Nonce to be used in the AEAD
 * @param[in]  nonce_length Length of the nonce, must be 12 bytes
 * @param[out] poly_key_r   First 16 bytes of the state
 * @param[out] poly_key_s   Remaining 16 bytes of the state
 * @return psa_status_t
 */
static psa_status_t cc3xx_internal_chacha20_poly1305_gen_otk(
    uint32_t *key, uint32_t *nonce, size_t nonce_length,
    uint32_t *poly_key_r, uint32_t *poly_key_s)
{
    cc3xx_err_t err;
    const uint8_t all_zero_block[CC3XX_CHACHA_BLOCK_SIZE] = {0};
    uint32_t keystream[CC3XX_CHACHA_BLOCK_SIZE / sizeof(uint32_t)];

    err = cc3xx_lowlevel_chacha20_init(CC3XX_CHACHA_DIRECTION_ENCRYPT,
                                       CC3XX_CHACHA_MODE_CHACHA,
                                       key, 0UL, nonce, nonce_length);
    if (err != CC3XX_ERR_SUCCESS) {
        return cc3xx_to_psa_err(err);
    }

    cc3xx_lowlevel_chacha20_set_output_buffer((uint8_t *)keystream, sizeof(keystream));

    err = cc3xx_lowlevel_chacha20_update(all_zero_block, sizeof(all_zero_block));
    if (err != CC3XX_ERR_SUCCESS) {
        return cc3xx_to_psa_err(err);
    }

    cc3xx_dpa_hardened_word_copy(poly_key_r, &keystream[0], POLY1305_KEY_SIZE / sizeof(uint32_t));
    cc3xx_dpa_hardened_word_copy(poly_key_s, &keystream[POLY1305_KEY_SIZE / sizeof(uint32_t)], POLY1305_KEY_SIZE / sizeof(uint32_t));

    cc3xx_lowlevel_chacha20_uninit();

    return PSA_SUCCESS;
}
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */

/** \defgroup psa_internal_cipher Internal modules requires from PSA to work with AES/Chacha
 *
 *  Functions required by PSA driver API modules to request AES functionalities
 *  from the low level driver
 *
 *  @{
 */
psa_status_t cc3xx_internal_cipher_setup_init(
        cc3xx_cipher_operation_t *operation,
        const psa_key_attributes_t *attributes,
        const uint8_t *key, size_t key_length,
        psa_algorithm_t alg,
        psa_encrypt_or_decrypt_t dir)
{
    psa_key_type_t key_type = PSA_KEY_TYPE_NONE;
    size_t key_bits = 0;

    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(attributes != NULL);
    CC3XX_ASSERT(key != NULL);

    key_type = psa_get_key_type(attributes);
    key_bits = psa_get_key_bits(attributes);

    operation->key_type = key_type;
    operation->alg = alg;
    operation->key_bits = key_bits;
    operation->last_output_num_bytes = 0; /* Keeps track of bytes produced in output */
    operation->cipher_is_initialized = false; /* It will not initialize any low level module here */
    operation->iv_length = 0; /* Generic IV length passed from the PSA API layer */

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
    memset(&operation->stream, 0, sizeof(operation->stream));
    operation->stream.idx = sizeof(operation->stream.buf);
#endif /* CC3XX_CONFIG_ENABLE_STREAM_CIPHER */

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (alg == PSA_ALG_CBC_PKCS7) {
        memset(operation->pkcs7_last_block, 0, sizeof(operation->pkcs7_last_block));
        operation->pkcs7_last_block_size = 0;
#if defined(CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS)
        operation->pkcs7_ring_buf.read_offset = 0;
        operation->pkcs7_ring_buf.write_offset = 0;
        operation->pkcs7_ring_buf.count = 0;
#endif /* CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS */
    }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */

    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
    case PSA_KEY_TYPE_CHACHA20:
#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        operation->stream.update = cc3xx_lowlevel_chacha20_update;
        operation->stream.set_output_buffer = cc3xx_lowlevel_chacha20_set_output_buffer;
#endif /* CC3XX_CONFIG_ENABLE_STREAM_CIPHER */
        return cc3xx_internal_chacha_setup(&(operation->chacha),
                            attributes, key, key_length, alg, dir);
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:
        return cc3xx_internal_aes_setup(&(operation->aes),
                            attributes, key, key_length, alg, dir);
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_internal_cipher_setup_set_iv(
        cc3xx_cipher_operation_t *operation,
        const uint8_t *iv, size_t iv_length)
{
    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(!iv_length ^ (iv != NULL));

    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
    case PSA_KEY_TYPE_CHACHA20:
    {
        uint32_t initial_counter = 0;

        if ((iv_length != 16) && (iv_length != 12)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        if (operation->alg == PSA_ALG_CHACHA20_POLY1305) {
            /* RFC 7539 restricts the IV to 12 bytes and the counter to 1 */
            if (iv_length == 16) {
                return PSA_ERROR_INVALID_ARGUMENT;
            }
#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
            initial_counter = 1;
#else
            /* In this case the low level driver takes care of computing the
             * Poly-1305 key and in that case the counter must be set to 0,
             * and will be incremented to 1 after the key is computed and the
             * data starts to be processed
             */
            initial_counter = 0;
#endif /* CC3XX_CONFIG_ENABLE_STREAM_CIPHER */
        } else {

            if (iv_length == 16) {
                /* Read the counter value in little endian */
                initial_counter = (iv[3] << 24) | (iv[2] << 16) | (iv[1] << 8) | iv[0];
                /* Move iv and adjust iv_length */
                iv += sizeof(uint32_t);
                iv_length -= sizeof(uint32_t);
            }
        }

        operation->chacha.counter = initial_counter;

        cc3xx_dpa_hardened_word_copy(operation->chacha.iv, (uint32_t *)iv,
                                     sizeof(operation->chacha.iv) / sizeof(uint32_t));

        operation->iv_length = sizeof(operation->chacha.iv);
        return PSA_SUCCESS;
    }
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:
        /* At this point we assume that the mode is valid, otherwise we are in a bad state */
        if (cc3xx_lowlevel_aes_valid_iv_length(operation->aes.mode, iv_length)
                                                    == CC3XX_ERR_INVALID_IV_LENGTH) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        cc3xx_dpa_hardened_word_copy(operation->aes.iv, (uint32_t *)iv,
                                     iv_length / sizeof(uint32_t));
        /* Copy unaligned bytes */
        if (iv_length % sizeof(uint32_t)) {
            size_t words_copied = iv_length / sizeof(uint32_t);
            memcpy(&operation->aes.iv[words_copied],
                   &iv[words_copied * sizeof(uint32_t)],
                   iv_length % sizeof(uint32_t));
        }

        operation->iv_length = iv_length;

#if !defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE) && defined(PSA_WANT_ALG_CCM)
        if ((operation->key_type == PSA_KEY_TYPE_AES) &&
            (operation->aes.mode == CC3XX_AES_MODE_CCM)) {
            c3xx_lowlevel_aes_ccm_init_ctr((uint8_t *)operation->aes.ctr, iv, iv_length);
        }
#endif /* !CC3XX_CONFIG_AES_TUNNELLING_ENABLE && PSA_WANT_ALG_CCM */

        return PSA_SUCCESS;
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_internal_cipher_setup_complete(
        cc3xx_cipher_operation_t *operation)
{
    cc3xx_err_t err;

    CC3XX_ASSERT(operation != NULL);

    if (operation->cipher_is_initialized == false) {

        /* Make sure the HW is configured on the low level context now */
        switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
        case PSA_KEY_TYPE_CHACHA20:
        {
#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
            psa_status_t status;
            uint32_t poly_key_r[POLY1305_KEY_SIZE / sizeof(uint32_t)];
            uint32_t poly_key_s[POLY1305_KEY_SIZE / sizeof(uint32_t)];

            if (operation->alg == PSA_ALG_CHACHA20_POLY1305) {
                status = cc3xx_internal_chacha20_poly1305_gen_otk(
                    operation->chacha.key, operation->chacha.iv, operation->iv_length,
                        poly_key_r, poly_key_s);

                if (status != PSA_SUCCESS) {
                    return status;
                }
            }
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
            err = cc3xx_lowlevel_chacha20_init(operation->chacha.direction,
                                               operation->chacha.mode, operation->chacha.key,
                                               operation->chacha.counter, operation->chacha.iv,
                                               operation->iv_length);
            if (err != CC3XX_ERR_SUCCESS) {
                return cc3xx_to_psa_err(err);
            }

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
            if (operation->alg == PSA_ALG_CHACHA20_POLY1305) {
                cc3xx_lowlevel_poly1305_init(poly_key_r, poly_key_s);
            }
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
        {
            uint32_t *key_buf = (operation->aes.key_id == CC3XX_AES_KEY_ID_USER_KEY) ?
                                operation->aes.key_buf : NULL;

            err = cc3xx_lowlevel_aes_init(operation->aes.direction,
                                          operation->aes.mode, operation->aes.key_id,
                                          key_buf, operation->aes.key_size,
                                          operation->aes.iv, operation->iv_length);
            if (err != CC3XX_ERR_SUCCESS) {
                return cc3xx_to_psa_err(err);
            }

            cc3xx_lowlevel_aes_set_tag_len(PSA_AEAD_TAG_LENGTH(operation->key_type, operation->key_bits, operation->alg));

#if defined(PSA_WANT_ALG_CCM)
            /* The fields below, i.e. aes_to_crypt_len and aes_to_auth_len are defined only
             * if CCM is enabled in the low level driver. Enabling the low level driver for
             * CCM is then a pre-requisite for having PSA_WANT_ALG_CCM in the PSA config
             */
            if (operation->aes.mode == CC3XX_AES_MODE_CCM) {
                cc3xx_lowlevel_aes_set_data_len(operation->aes.aes_to_crypt_len, operation->aes.aes_to_auth_len);
            }
#endif /* PSA_WANT_ALG_CCM */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_AES */
        default:
            (void)err;
            return PSA_ERROR_NOT_SUPPORTED;
        }

        operation->cipher_is_initialized = true;
        return PSA_SUCCESS;

    } else {

        /* Just set the state in case initialization has happened */
        switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
        case PSA_KEY_TYPE_CHACHA20:
            cc3xx_lowlevel_chacha20_set_state(&(operation->chacha));
#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) && defined(PSA_WANT_ALG_CHACHA20_POLY1305)
            if (operation->alg == PSA_ALG_CHACHA20_POLY1305) {
                cc3xx_lowlevel_poly1305_set_state(&(operation->chacha.poly_state));
            }
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
            break;
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
            cc3xx_lowlevel_aes_set_state(&(operation->aes));
            break;
#endif /* PSA_WANT_KEY_TYPE_AES */
        default:
            return PSA_ERROR_NOT_SUPPORTED;
        }

        return PSA_SUCCESS;
    } /* operation->cipher_is_initialized */
}

psa_status_t cc3xx_internal_cipher_stream_pre_update(
        struct cc3xx_internal_cipher_stream_t *stream,
        const uint8_t *input, size_t input_length,
        uint8_t *output, size_t output_size, size_t *output_length)
{
    size_t keystream_size, size_to_pre_process, idx;

    CC3XX_ASSERT(stream != NULL);
    CC3XX_ASSERT(input != NULL);
    CC3XX_ASSERT(output != NULL);
    CC3XX_ASSERT(output_length != NULL);

    /* If there is some outstanding state we need to process that first */
    keystream_size = (sizeof(stream->buf) - stream->idx) > 0 ?
                            (sizeof(stream->buf) - stream->idx) : 0;
    size_to_pre_process = keystream_size < input_length ?
                            keystream_size : input_length;
    if (size_to_pre_process) {
        uint8_t permutation_buf[size_to_pre_process]; /* This is a VLA */

        cc3xx_lowlevel_rng_get_random_permutation(permutation_buf, size_to_pre_process);

        for (idx = 0; idx < size_to_pre_process; idx++) {
            output[permutation_buf[idx]] =
                stream->buf[stream->idx + permutation_buf[idx]] ^ input[permutation_buf[idx]];
        }

        stream->idx += size_to_pre_process;
        *output_length = size_to_pre_process;
    }

    return PSA_SUCCESS;
}

psa_status_t cc3xx_internal_cipher_stream_post_update(
        struct cc3xx_internal_cipher_stream_t *stream,
        size_t processed_length,
        const uint8_t *input, size_t input_length,
        uint8_t *output, size_t output_size, size_t *output_length)
{
    CC3XX_ASSERT(stream != NULL);
    CC3XX_ASSERT(input != NULL);
    CC3XX_ASSERT(output != NULL);
    CC3XX_ASSERT(output_length != NULL);

    /* Store the last part of the data that couldn't be processed as
     * a separate block
     */
    if (input_length - processed_length) {
        uint8_t permutation_buf[input_length - processed_length]; /* This is a VLA */
        size_t idx;
        cc3xx_err_t err;
        /* Generate a keystream block to keep as state */
        const uint8_t all_zero_input[CC3XX_CHACHA_BLOCK_SIZE] = {0};

        stream->set_output_buffer(stream->buf, sizeof(stream->buf));

        err = stream->update(all_zero_input, sizeof(all_zero_input));
        if (err != CC3XX_ERR_SUCCESS) {
            return PSA_ERROR_HARDWARE_FAILURE;
        }

        cc3xx_lowlevel_rng_get_random_permutation(permutation_buf, input_length - processed_length);

        for (idx = 0; idx < input_length - processed_length; idx++) {
            output[processed_length + permutation_buf[idx]] =
                stream->buf[permutation_buf[idx]] ^ input[processed_length + permutation_buf[idx]];
        }

        *output_length += (input_length - processed_length);

        /* Update the pointer to the start of the unprocessed keystream */
        stream->idx = (input_length - processed_length);
    }

    return PSA_SUCCESS;
}
/** @} */ // end of psa_internal_cipher
