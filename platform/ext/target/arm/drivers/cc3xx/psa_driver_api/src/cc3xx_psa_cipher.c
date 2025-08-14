/*
 * Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** \file cc3xx_psa_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "cc3xx_psa_cipher.h"
#include "cc3xx_crypto_primitives_private.h"
#include "cc3xx_misc.h"
#include "cc3xx_stdlib.h"
#include "cc3xx_internal_cipher.h"
#include "cc3xx_aes.h"
#include "cc3xx_chacha.h"

/* ToDo: This needs to be sorted out at TF-M level
 * To be able to include the PSA style configuration
 */
#include "mbedtls/build_info.h"

#if defined(PSA_WANT_ALG_CBC_PKCS7)

#if defined(CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS)

static void write_ring_buffer(ring_buffer_t *acc, uint8_t byte)
{
    acc->buffer[acc->write_offset++] = byte;
    acc->write_offset = (acc->write_offset == sizeof(acc->buffer)) ? 0 : acc->write_offset;
    acc->count++;
}

static uint8_t read_ring_buffer(ring_buffer_t *acc)
{
    const uint8_t byte = acc->buffer[acc->read_offset++];
    acc->read_offset = (acc->read_offset == sizeof(acc->buffer)) ? 0 : acc->read_offset;
    acc->count--;
    return byte;
}

/* We always require to output a maximum of 2 output blocks. Note that this value
 * must be chosen accordingly to the size of the ring buffer used for buffering
 */
#define MAX_BLOCKS_STREAMABLE (2)

/**
 * @brief Streaming function that accumulates inputs in a ring buffer and emits them in chunks
 *        of size AES_BLOCK_SIZE, for a maximum of MAX_BLOCKS_STREAMABLE per call
 *
 * @param[in, out] acc            Ring buffer to accumulate the input
 * @param[in]      input          Input buffer to accumulate
 * @param[in]      input_len      Size in bytes of the \p input buffer
 * @param[out]     output_blocks  Output buffer containing blocks of AES_BLOCK_SIZE
 * @param[out]     consumed_input Number of bytes that have been consumed into the ring
 *
 * @return size_t Returns the number of blocks that have been produced into \p output_blocks
 */
static size_t streaming_accumulate(
    ring_buffer_t *acc,
    const uint8_t *input,
    size_t input_len,
    uint8_t *output_blocks,
    size_t *consumed_input)
{
    size_t written_blocks = 0;
    size_t i = 0;

    while (i < input_len) {
        /* Consume input as much as possible */
        while ((i < input_len) && (acc->count < sizeof(acc->buffer))) {
            write_ring_buffer(acc, input[i++]);
        }

        /* Extract full blocks if available */
        while ((acc->count >= AES_BLOCK_SIZE) && (written_blocks < MAX_BLOCKS_STREAMABLE)) {
            for (size_t j = 0; j < AES_BLOCK_SIZE; j++) {
                output_blocks[(written_blocks * AES_BLOCK_SIZE) + j] = read_ring_buffer(acc);
            }
            written_blocks++;
        }

        /* We have either extracted all that we can or we filled the buffer, so leave */
        if ((acc->count == sizeof(acc->buffer)) && (written_blocks == MAX_BLOCKS_STREAMABLE))
            break;
    }

    *consumed_input = i;
    return written_blocks;
}
#endif /* CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS */

/**
 * @brief A function which removes the padding bytes from the
 *        input buffer, returning the actual size of the payload
 *        data. It validates the padding is as expected for PKCS#7
 *        based on the last byte of the input buffer
 *
 * @param[in]  buf      Buffer containing the padded data
 * @param[in]  buf_size Size in bytes of the buffer passed as input
 * @param[out] out_len  Actual size in bytes of the payload without padding
 * @return psa_status_t
 */
static psa_status_t get_pkcs_padding(
        const uint8_t *buf,
        size_t buf_size,
        size_t *out_len)
{
    size_t idx, pad_idx;
    uint8_t padding_len, bad = 0;

    padding_len = buf[buf_size - 1]; /* Assume the last byte contains the pad value */
    *out_len = buf_size - padding_len; /* The value of the actual payload */

    /* Keep the flow branchless, i.e. constant time */
    bad |= padding_len > buf_size; /* Can't be greater than the buffer itself */
    bad |= padding_len == 0; /* At least 1 byte of padding */

    /* Index of the byte to start with the checking */
    pad_idx = buf_size - padding_len;
    /* Process the whole buffer to avoid revealing length info,
     * just consider the result of the XOR starting from pad_idx onwards
     */
    for (idx = 0; idx < buf_size; idx++ ) {
        bad |= (buf[idx] ^ padding_len) * (idx >= pad_idx);
    }

    return PSA_ERROR_INVALID_PADDING * (bad != 0); /* This relies on PSA_SUCCESS being 0 */
}
#endif /* PSA_WANT_ALG_CBC_PKCS7 */

/**
 * @brief Integrated ciphering operation (single-part)
 *
 * @param[in]  attributes      Structure with attributes of the key
 * @param[in]  key_buffer      Buffer containing the key material
 * @param[in]  key_buffer_size Size in bytes of the key
 * @param[in]  alg             Algorithm to be used with the key
 * @param[in]  iv              IV to be used (except for ECB alg)
 * @param[in]  iv_length       Size in bytes of the IV
 * @param[in]  input           Input data to be encrypted or decrypted
 * @param[in]  input_length    Size in bytes of the input
 * @param[out] output          Data produced as output
 * @param[in]  output_size     Size in bytes of the output buffer
 * @param[out] output_length   Actual number of bytes produced
 * @param[in]  dir             Encryption or decryption direction
 * @return psa_status_t
 */
static psa_status_t cipher_crypt(
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer,
        size_t key_buffer_size,
        psa_algorithm_t alg,
        const uint8_t *iv,
        size_t iv_length,
        const uint8_t *input,
        size_t input_length,
        uint8_t *output,
        size_t output_size,
        size_t *output_length,
        psa_encrypt_or_decrypt_t dir)
{
    psa_status_t status;
    psa_key_type_t key_type = PSA_KEY_TYPE_NONE;
    cc3xx_err_t err;
    size_t bytes_produced_on_finish;

    CC3XX_ASSERT(key_buffer != NULL);
    CC3XX_ASSERT(attributes != NULL);
    CC3XX_ASSERT(iv != NULL);
    CC3XX_ASSERT(input != NULL);
    CC3XX_ASSERT(output != NULL);
    CC3XX_ASSERT(output_length != NULL);

    key_type = psa_get_key_type(attributes);

    /* Initialize */
    *output_length = 0;

    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
    case PSA_KEY_TYPE_CHACHA20:
    {
        uint32_t initial_counter = 0;

        if (key_buffer_size != CC3XX_CHACHA_KEY_SIZE ||
            alg != PSA_ALG_STREAM_CIPHER) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        if ((iv_length != 16) && (iv_length != 12)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        if (iv_length == 16) {
            /* Read the counter value in little endian */
            initial_counter = (iv[3] << 24) | (iv[2] << 16) | (iv[1] << 8) | iv[0];
            /* Move iv and adjust iv_length */
            iv += sizeof(uint32_t);
            iv_length -= sizeof(uint32_t);
        }

        err = cc3xx_lowlevel_chacha20_init((dir == PSA_CRYPTO_DRIVER_ENCRYPT) ?
                        CC3XX_AES_DIRECTION_ENCRYPT : CC3XX_AES_DIRECTION_DECRYPT,
                        CC3XX_CHACHA_MODE_CHACHA,
                        (uint32_t *)key_buffer,
                        initial_counter,
                        (uint32_t *)iv, iv_length);

        if (err != CC3XX_ERR_SUCCESS) {
            return cc3xx_to_psa_err(err);
        }

        cc3xx_lowlevel_chacha20_set_output_buffer(output, output_size);

        err = cc3xx_lowlevel_chacha20_update(input, input_length);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_chacha20;
        }

        err = cc3xx_lowlevel_chacha20_finish(NULL, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            *output_length = 0;
            status = cc3xx_to_psa_err(err);
            goto out_chacha20;
        }

        *output_length = bytes_produced_on_finish;

        status = PSA_SUCCESS;
out_chacha20:
        cc3xx_lowlevel_chacha20_uninit();
        return status;
    }
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */
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

        switch (alg) {
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
        case PSA_ALG_CBC_NO_PADDING:
            if ((input_length % AES_BLOCK_SIZE) > 0) {
                return PSA_ERROR_INVALID_ARGUMENT;
            }
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
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        err = cc3xx_lowlevel_aes_init((dir == PSA_CRYPTO_DRIVER_ENCRYPT) ?
                        CC3XX_AES_DIRECTION_ENCRYPT : CC3XX_AES_DIRECTION_DECRYPT,
                        mode, CC3XX_AES_KEY_ID_USER_KEY,
                        (uint32_t *)key_buffer, key_size,
                        (uint32_t *)iv, iv_length);

        if (err != CC3XX_ERR_SUCCESS) {
            return cc3xx_to_psa_err(err);
        }

        cc3xx_lowlevel_aes_set_output_buffer(output, output_size);

        err = cc3xx_lowlevel_aes_update(input, input_length);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_aes;
        }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
        /* In padded modes, we need to deal with padding bytes here */
        if (alg == PSA_ALG_CBC_PKCS7 &&
            dir == PSA_CRYPTO_DRIVER_ENCRYPT) {
            uint8_t padded_bytes[AES_BLOCK_SIZE];
            size_t pad_value = sizeof(padded_bytes)  - (input_length % AES_BLOCK_SIZE);
            memset(padded_bytes, pad_value, pad_value);
            err = cc3xx_lowlevel_aes_update(padded_bytes, pad_value);
            if (err != CC3XX_ERR_SUCCESS) {
                status = cc3xx_to_psa_err(err);
                *output_length = 0;
                goto out_aes;
            }
        }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */

        err = cc3xx_lowlevel_aes_finish(NULL, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            *output_length = 0;
            goto out_aes;
        }

        *output_length = bytes_produced_on_finish;

#if defined(PSA_WANT_ALG_CBC_PKCS7)
        /* In padded modes, we need to deal with padding bytes here */
        if (alg == PSA_ALG_CBC_PKCS7 &&
            dir == PSA_CRYPTO_DRIVER_DECRYPT) {
            if (*output_length < AES_BLOCK_SIZE) {
                /* In padded mode and decryption, we should at least have decrypted 1 block */
                *output_length = 0;
                status = PSA_ERROR_INVALID_PADDING;
            } else {
                size_t last_block_length = AES_BLOCK_SIZE;
                /* Pass the last block to double check it */
                status = get_pkcs_padding(
                                &output[*output_length - last_block_length],
                                last_block_length,
                                &last_block_length);
                if (status == PSA_SUCCESS) {
                    *output_length -= (AES_BLOCK_SIZE - last_block_length);
                } else {
                    *output_length = 0;
                }
            }
            goto out_aes;
        }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */

        status = PSA_SUCCESS;
out_aes:
        cc3xx_lowlevel_aes_uninit();
        return status;
    }
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        (void)err;
        (void)bytes_produced_on_finish;
        (void)status;
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

/** \defgroup psa_cipher PSA driver entry points for symmetric cipher
 *
 *  Entry points for symmetric cipher encryption and decryption as described
 *  by the PSA Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t cc3xx_cipher_encrypt_setup(
        cc3xx_cipher_operation_t *operation,
        const psa_key_attributes_t *attributes,
        const uint8_t *key, size_t key_length,
        psa_algorithm_t alg)
{
    psa_status_t status;

    status = cc3xx_internal_cipher_setup_init(operation,
                        attributes, key, key_length, alg,
                        PSA_CRYPTO_DRIVER_ENCRYPT);
    return status;
}

psa_status_t cc3xx_cipher_decrypt_setup(
        cc3xx_cipher_operation_t *operation,
        const psa_key_attributes_t *attributes,
        const uint8_t *key, size_t key_length,
        psa_algorithm_t alg)
{
    psa_status_t status;

    status = cc3xx_internal_cipher_setup_init(operation,
                        attributes, key, key_length, alg,
                        PSA_CRYPTO_DRIVER_DECRYPT);
    return status;
}

psa_status_t cc3xx_cipher_set_iv(
        cc3xx_cipher_operation_t *operation,
        const uint8_t *iv, size_t iv_length)
{
    return cc3xx_internal_cipher_setup_set_iv(
                                operation, iv, iv_length);
}

psa_status_t cc3xx_cipher_update(
        cc3xx_cipher_operation_t *operation,
        const uint8_t *input, size_t input_length,
        uint8_t *output, size_t output_size, size_t *output_length)
{
    cc3xx_err_t err;
    psa_status_t status;
    size_t last_output_num_bytes = 0, current_output_size = 0;

    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(input != NULL);
    CC3XX_ASSERT(!output_size ^ (output != NULL));
    CC3XX_ASSERT(output_length != NULL);

    /* Initialize */
    *output_length = 0;

    /* This either restores the state or completes the init */
    status = cc3xx_internal_cipher_setup_complete(operation);
    if (status != PSA_SUCCESS) {
        return status;
    }

    last_output_num_bytes = operation->last_output_num_bytes;
    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
    case PSA_KEY_TYPE_CHACHA20:
    {
        size_t processed_length;

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
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

        cc3xx_lowlevel_chacha20_get_state(&(operation->chacha));

        status = PSA_SUCCESS;
out_chacha20:
        cc3xx_lowlevel_chacha20_uninit();
        return status;
    }
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:
    {
        cc3xx_lowlevel_aes_set_output_buffer(output, output_size);

#if defined(PSA_WANT_ALG_CBC_PKCS7)
        /* In padded mode and decryption, we always cache the last block */
        if (operation->alg == PSA_ALG_CBC_PKCS7 &&
            operation->aes.direction == CC3XX_AES_DIRECTION_DECRYPT) {

#if !defined(CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS)
            /* The driver supports only block aligned updates to reduce complexity in CBC_PKCS7 */
            if (input_length % AES_BLOCK_SIZE) {
                status = PSA_ERROR_INVALID_ARGUMENT;
                goto out_aes;
            }
#endif /* CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS */

            if (operation->pkcs7_last_block_size == AES_BLOCK_SIZE) {
                err = cc3xx_lowlevel_aes_update(operation->pkcs7_last_block, operation->pkcs7_last_block_size);
                if (err != CC3XX_ERR_SUCCESS) {
                    status = cc3xx_to_psa_err(err);
                    goto out_aes;
                }
                operation->pkcs7_last_block_size = 0;
            }

#if !defined(CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS)
            if (input_length) {
                /* Update the cache */
                memcpy(&operation->pkcs7_last_block, &input[input_length - AES_BLOCK_SIZE], AES_BLOCK_SIZE);
                operation->pkcs7_last_block_size = AES_BLOCK_SIZE;

                /* Reduce by the amount we have cached */
                input_length -= AES_BLOCK_SIZE;

                err = cc3xx_lowlevel_aes_update(input, input_length);
                if (err != CC3XX_ERR_SUCCESS) {
                    status = cc3xx_to_psa_err(err);
                    goto out_aes;
                }
            }
#else
            while (input_length) {
                size_t consumed_input = 0;
                /* We require at most 2 blocks to be extracted from the ring
                 * buffer in order to be able to keep at least one last block
                 * available for a call to psa_cipher_finish(). 2 blocks per call
                 * is then the number of blocks that minimises requirements on buffer
                 * sizes
                 */
                uint32_t temp[(MAX_BLOCKS_STREAMABLE * AES_BLOCK_SIZE) / sizeof(uint32_t)];
                size_t written_blocks = streaming_accumulate(
                    &operation->pkcs7_ring_buf,
                    input, input_length,
                    (uint8_t *)temp,
                    &consumed_input);

                input += consumed_input;
                input_length -= consumed_input;

                if (written_blocks == MAX_BLOCKS_STREAMABLE) {
                    err = cc3xx_lowlevel_aes_update((const uint8_t *)temp, AES_BLOCK_SIZE);
                    if (err != CC3XX_ERR_SUCCESS) {
                        status = cc3xx_to_psa_err(err);
                        goto out_aes;
                    }
                    memcpy(&operation->pkcs7_last_block, &temp[AES_BLOCK_SIZE / sizeof(uint32_t)], AES_BLOCK_SIZE);
                    operation->pkcs7_last_block_size = AES_BLOCK_SIZE;
                } else if (written_blocks == (MAX_BLOCKS_STREAMABLE - 1)) {
                    memcpy(&operation->pkcs7_last_block, &temp[0], AES_BLOCK_SIZE);
                    operation->pkcs7_last_block_size = AES_BLOCK_SIZE;
                } else {
                    operation->pkcs7_last_block_size = 0;
                }
            }
#endif /* CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS */
        } else
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
        {
            err = cc3xx_lowlevel_aes_update(input, input_length);
            if (err != CC3XX_ERR_SUCCESS) {
                status = cc3xx_to_psa_err(err);
                goto out_aes;
            }
        }

        current_output_size = cc3xx_lowlevel_aes_get_current_output_size();

        *output_length = current_output_size - last_output_num_bytes;

        operation->last_output_num_bytes = current_output_size;

        cc3xx_lowlevel_aes_get_state(&(operation->aes));

        status = PSA_SUCCESS;
out_aes:
        cc3xx_lowlevel_aes_uninit();
        return status;
    }
#endif /* PSA_WANT_KEY_TYPE_AES */

    default:
        (void)err;
        (void)current_output_size;
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_cipher_finish(
        cc3xx_cipher_operation_t *operation,
        uint8_t *output, size_t output_size, size_t *output_length)
{
    psa_status_t status;
    cc3xx_err_t err;
    size_t bytes_produced_on_finish;

    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(output_length != NULL);

    /* Initialize */
    *output_length = 0;

    if (output_size == 0 || output == NULL) {
        return PSA_SUCCESS;
    }

    if (operation->cipher_is_initialized == false) {
        /* This means it was never updated with any data, so just exit now */
        return PSA_SUCCESS;
    }

    switch (operation->key_type) {
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
    case PSA_KEY_TYPE_CHACHA20:

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
        return PSA_SUCCESS; /* In stream cipher mode, it's all handled in cc3xx_cipher_update() */
#else
        cc3xx_lowlevel_chacha20_set_state(&(operation->chacha));

        cc3xx_lowlevel_chacha20_set_output_buffer(output, output_size);

        err = cc3xx_lowlevel_chacha20_finish(NULL, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_chacha20;
        }

        *output_length = bytes_produced_on_finish - operation->last_output_num_bytes;

        operation->last_output_num_bytes = bytes_produced_on_finish;

        return PSA_SUCCESS;

out_chacha20:
        cc3xx_lowlevel_chacha20_uninit();
        return status;
#endif /* defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER) */
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:

#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
        if ((operation->alg == PSA_ALG_CBC_NO_PADDING) &&
            ((operation->aes.crypted_length % AES_BLOCK_SIZE) > 0)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
#endif /*PSA_WANT_ALG_CBC_NO_PADDING */

        cc3xx_lowlevel_aes_set_state(&(operation->aes));

        cc3xx_lowlevel_aes_set_output_buffer(output, output_size);

        if (output_size < operation->aes.dma_state.block_buf_size_in_use) {
            status = PSA_ERROR_BUFFER_TOO_SMALL;
            goto out_aes;
        }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
        /* When encrypting on finish, we need to encrypt the padding */
        if (operation->alg == PSA_ALG_CBC_PKCS7 &&
            operation->aes.direction == CC3XX_AES_DIRECTION_ENCRYPT) {
            uint8_t padded_bytes[AES_BLOCK_SIZE];
            size_t pad_value = AES_BLOCK_SIZE - (operation->aes.crypted_length % AES_BLOCK_SIZE);
            memset(padded_bytes, pad_value, pad_value);
            err = cc3xx_lowlevel_aes_update(padded_bytes, pad_value);
            if (err != CC3XX_ERR_SUCCESS) {
                status = cc3xx_to_psa_err(err);
                goto out_aes;
            }
        }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */

#if defined(PSA_WANT_ALG_CBC_PKCS7)
        /* When decrypting on finish, we need to process the cache which must be
         * full otherwise we are in a bad state
         */
        if (operation->alg == PSA_ALG_CBC_PKCS7 &&
            operation->aes.direction == CC3XX_AES_DIRECTION_DECRYPT) {

            if (operation->pkcs7_last_block_size != AES_BLOCK_SIZE) {
                status = PSA_ERROR_BAD_STATE;
                goto out_aes;
            }

            err = cc3xx_lowlevel_aes_update(operation->pkcs7_last_block, AES_BLOCK_SIZE);
            if (err != CC3XX_ERR_SUCCESS) {
                status = PSA_ERROR_HARDWARE_FAILURE;
                goto out_aes;
            }
        }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */

        err = cc3xx_lowlevel_aes_finish(NULL, &bytes_produced_on_finish);
        if (err != CC3XX_ERR_SUCCESS) {
            status = cc3xx_to_psa_err(err);
            goto out_aes;
        }

        *output_length = bytes_produced_on_finish - operation->last_output_num_bytes;

        operation->last_output_num_bytes = bytes_produced_on_finish;

#if defined(PSA_WANT_ALG_CBC_PKCS7)
        if (operation->alg == PSA_ALG_CBC_PKCS7 &&
            operation->aes.direction == CC3XX_AES_DIRECTION_DECRYPT) {
            status = get_pkcs_padding(output, *output_length, output_length);
            if (status != PSA_SUCCESS) {
                *output_length = 0;
                goto out_aes;
            }
        }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
        return PSA_SUCCESS;

out_aes:
        cc3xx_lowlevel_aes_uninit();
        return status;
#endif /* PSA_WANT_KEY_TYPE_AES */
    default:
        (void)err;
        (void)bytes_produced_on_finish;
        (void)status;
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_ERROR_CORRUPTION_DETECTED;
}

psa_status_t cc3xx_cipher_abort(
        cc3xx_cipher_operation_t *operation)
{
    cc3xx_secure_erase_buffer((uint32_t *)operation, sizeof(cc3xx_cipher_operation_t) / sizeof(uint32_t));
    return PSA_SUCCESS;
}

psa_status_t cc3xx_cipher_encrypt(
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer,
        size_t key_buffer_size,
        psa_algorithm_t alg,
        const uint8_t *iv,
        size_t iv_length,
        const uint8_t *input,
        size_t input_length,
        uint8_t *output,
        size_t output_size,
        size_t *output_length)
{
    return cipher_crypt(
        attributes, key_buffer, key_buffer_size, alg,
        iv, iv_length,
        input, input_length,
        output, output_size, output_length,
        PSA_CRYPTO_DRIVER_ENCRYPT);
}

psa_status_t cc3xx_cipher_decrypt(
        const psa_key_attributes_t *attributes,
        const uint8_t *key_buffer,
        size_t key_buffer_size,
        psa_algorithm_t alg,
        const uint8_t *input,
        size_t input_length,
        uint8_t *output,
        size_t output_size,
        size_t *output_length)
{
    const size_t iv_length = PSA_CIPHER_IV_LENGTH(psa_get_key_type(attributes), alg);

    if (input_length <= iv_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return cipher_crypt(
        attributes, key_buffer, key_buffer_size, alg,
        input, iv_length,
        input + iv_length, input_length - iv_length,
        output, output_size, output_length,
        PSA_CRYPTO_DRIVER_DECRYPT);
}
/** @} */ // end of psa_cipher
