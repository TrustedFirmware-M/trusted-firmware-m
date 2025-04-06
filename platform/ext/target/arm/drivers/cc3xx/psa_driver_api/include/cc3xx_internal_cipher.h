/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_INTERNAL_CIPHER_H__
#define __CC3XX_INTERNAL_CIPHER_H__

/** \file cc3xx_internal_cipher.h
 *
 * This file contains internal functions required by the interface
 * modules to configure AES/CHACHA functionalities on the low level driver,
 * either in unauthenticated or authenticated modes.
 *
 */

#include "cc3xx_crypto_primitives_private.h"
#include "psa/crypto.h"
#include "cc3xx_error.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief A function that takes care of collecting parameters for later initialization of the
 *        low level driver contexts for either AES based or CHACHA based encryption/decryption
 *        with or without authenticated data. To complete the initialisation
 *        the \ref cc3xx_internal_cipher_setup_complete must be called
 *
 * @param[out] operation  Pointer to a cc3xx_cipher_operation_t or cc3xx_aead_operation_t
 * @param[in]  attributes Attributes of the key to be set up on the context
 * @param[in]  key        Buffer containing the key
 * @param[in]  key_length Size in bytes of the key
 * @param[in]  alg        Algorithm to be used with the key
 * @param[in]  dir        Ciphering direction, i.e. encrypt or decrypt
 * @return psa_status_t
 */
psa_status_t cc3xx_internal_cipher_setup_init(
        cc3xx_cipher_operation_t *operation,
        const psa_key_attributes_t *attributes,
        const uint8_t *key, size_t key_length,
        psa_algorithm_t alg,
        psa_encrypt_or_decrypt_t dir);

/**
 * @brief A function that takes care of setting the IV and associated length on the context,
 *        to be used later when \ref cc3xx_internal_cipher_setup_complete to finalize the
 *        configuration of the low level driver context for either AES or CHACHA
 *
 * @param[in,out] operation Pointer to a cc3xx_cipher_operation_t or cc3xx_aead_operation_t
 * @param[in]     iv        IV or nonce to be used to complete the init
 * @param[in]     iv_length Size in bytes of the iv buffer
 * @return psa_status_t
 */
psa_status_t cc3xx_internal_cipher_setup_set_iv(
        cc3xx_cipher_operation_t *operation,
        const uint8_t *iv, size_t iv_length);

/**
 * @brief A function that takes care of completing the initialization of the low
 *        level driver, by configuring the hardware with all the information obtained so far.
 *        It must always be called as a last call before starting to update the ciphers with
 *        AAD or cipher data. It will leave the low level driver in an initialized way, i.e.
 *        ready for AAD or cipher data updates.
 *
 * @param[in,out] operation Pointer to a cc3xx_cipher_operation_t or cc3xx_aead_operation_t
 * @return psa_status_t
 */
psa_status_t cc3xx_internal_cipher_setup_complete(
        cc3xx_cipher_operation_t *operation);

/**
 * @brief When CC3XX_CONFIG_ENABLE_STREAM_CIPHER is set, this function is used to process
 *        any outstanding keystream not yet consumed before requesting another keystream
 *        block from the underlying block cipher
 *
 * @param[in, out] stream        Object containing the state of the keystream
 * @param[in]      input         Buffer containing the input to be processed
 * @param[in]      input_length  Size in bytes of the \ref input buffer
 * @param[out]     output        Buffer containing the output
 * @param[in]      output_size   Size in bytes of the \ref output buffer
 * @param[out]     output_length Size of the output produced by the pre_update step
 *
 * @return psa_status_t
 */
psa_status_t cc3xx_internal_cipher_stream_pre_update(
        struct cc3xx_internal_cipher_stream_t *stream,
        const uint8_t *input, size_t input_length,
        uint8_t *output, size_t output_size, size_t *output_length);
/**
 * @brief When CC3XX_CONFIG_ENABLE_STREAM_CIPHER is set, this function is used to process
 *        any outstanding input that was not aligned to the underlying block cipher size,
 *        and eventually requests one more keystream block to be kept as a state for the
 *        next update call
 *
 * @param[in, out] stream           Object containing the state of the keystream
 * @param[in]      processed_length The block aligned size that has been processed before this call
 * @param[in]      input            Buffer containing the input to be processed
 * @param[in]      input_length     Size in bytes of the \ref input buffer
 * @param[out]     output           Buffer containing the output
 * @param[in]      output_size      Size in bytes of the \ref output buffer
 * @param[in, out] output_length    Total size produced including the post_update. It must be
 *                                  set to the correct value of bytes produced so far before calling
 *                                  this function
 * @return psa_status_t
 */
psa_status_t cc3xx_internal_cipher_stream_post_update(
        struct cc3xx_internal_cipher_stream_t *stream,
        size_t processed_length,
        const uint8_t *input, size_t input_length,
        uint8_t *output, size_t output_size, size_t *output_length);

#ifdef __cplusplus
}
#endif
#endif /* __CC3XX_INTERNAL_CIPHER_H__ */
