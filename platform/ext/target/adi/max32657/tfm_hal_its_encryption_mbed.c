/*
 * Copyright (c) 2023 Nordic Semiconductor ASA.
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 * Copyright (C) 2025 Analog Devices, Inc.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Derived from platform/ext/target/nordic_nrf/common/core/tfm_hal_its_encryption.c
 */

#include <stdint.h>
#include <string.h>

#include "config_tfm.h"
#include "platform/include/tfm_hal_its_encryption.h"
#include "platform/include/tfm_hal_its.h"
#include "platform/include/tfm_platform_system.h"

#include "tfm_plat_crypto_keys.h"
#include "crypto_keys/tfm_builtin_key_ids.h"
#include "tfm_plat_otp.h"
#include "psa_manifest/pid.h"
#include "tfm_builtin_key_loader.h"

#ifndef ITS_CRYPTO_AEAD_ALG
#define ITS_CRYPTO_AEAD_ALG PSA_ALG_GCM
#endif

/* The PSA key type used by this implementation */
#define ITS_KEY_TYPE PSA_KEY_TYPE_AES
/* The PSA key usage required by this implementation */
#define ITS_KEY_USAGE (PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT)

/* The PSA algorithm used by this implementation */
#define ITS_CRYPTO_ALG \
    PSA_ALG_AEAD_WITH_SHORTENED_TAG(ITS_CRYPTO_AEAD_ALG, TFM_ITS_AUTH_TAG_LENGTH)

static uint8_t g_enc_nonce_seed[TFM_ITS_ENC_NONCE_LENGTH];

#if TFM_ITS_ENC_NONCE_LENGTH != 12
#error "This implementation only supports a ITS nonce of size 12"
#endif

/* Copy PS solution */
static psa_status_t its_crypto_setkey(psa_key_handle_t *its_key,
                                      const uint8_t *key_label,
                                      size_t key_label_len)
{
    psa_status_t status;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_derivation_operation_t op = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_handle_t seed_key = mbedtls_svc_key_id_make(TFM_SP_ITS, TFM_BUILTIN_KEY_ID_HUK);

    if (key_label_len == 0 || key_label == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Set the key attributes for the storage key */
    psa_set_key_usage_flags(&attributes, ITS_KEY_USAGE);
    psa_set_key_algorithm(&attributes, ITS_CRYPTO_ALG);
    psa_set_key_type(&attributes, ITS_KEY_TYPE);
    psa_set_key_bits(&attributes, PSA_BYTES_TO_BITS(TFM_ITS_KEY_LENGTH));

    status = psa_key_derivation_setup(&op, PSA_ALG_HKDF(PSA_ALG_SHA_256));
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Set up a key derivation operation with HUK  */
    status = psa_key_derivation_input_key(&op, PSA_KEY_DERIVATION_INPUT_SECRET,
                                          seed_key);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Supply the ITS key label as an input to the key derivation */
    status = psa_key_derivation_input_bytes(&op, PSA_KEY_DERIVATION_INPUT_INFO,
                                            key_label,
                                            key_label_len);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Create the storage key from the key derivation operation */
    status = psa_key_derivation_output_key(&attributes, &op, its_key);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Free resources associated with the key derivation operation */
    status = psa_key_derivation_abort(&op);
    if (status != PSA_SUCCESS) {
        goto err_release_key;
    }

    return PSA_SUCCESS;

err_release_key:
    (void)psa_destroy_key(*its_key);

err_release_op:
    (void)psa_key_derivation_abort(&op);

    return PSA_ERROR_GENERIC_ERROR;
}

enum tfm_hal_status_t tfm_hal_its_aead_generate_nonce(uint8_t *nonce,
                                                      const size_t nonce_size)
{
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;

    if (nonce == NULL){
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    status = psa_generate_random(&g_enc_nonce_seed[0],
                                                 sizeof(g_enc_nonce_seed));
    if (status != PSA_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    memcpy(nonce, g_enc_nonce_seed, sizeof(g_enc_nonce_seed));

    return TFM_HAL_SUCCESS;
}

static bool ctx_is_valid(struct tfm_hal_its_auth_crypt_ctx *ctx)
{
    bool ret;

    if (ctx == NULL) {
        return false;
    }

    ret = (ctx->deriv_label == NULL && ctx->deriv_label_size != 0) ||
          (ctx->aad == NULL && ctx->aad_size != 0) ||
          (ctx->nonce == NULL && ctx->nonce_size != 0);

    return !ret;
}

enum tfm_hal_status_t tfm_hal_its_aead_encrypt(
                                        struct tfm_hal_its_auth_crypt_ctx *ctx,
                                        const uint8_t *plaintext,
                                        const size_t plaintext_size,
                                        uint8_t *ciphertext,
                                        const size_t ciphertext_size,
                                        uint8_t *tag,
                                        const size_t tag_size)
{
    psa_status_t status;
    status = psa_crypto_init();
    if (status != PSA_SUCCESS) {
       return TFM_HAL_ERROR_GENERIC;
    }
    psa_key_handle_t its_key = PSA_KEY_HANDLE_INIT;
    size_t ciphertext_length;

    if (!ctx_is_valid(ctx) || tag == NULL) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if (plaintext_size > ciphertext_size) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    status = its_crypto_setkey(&its_key, ctx->deriv_label, ctx->deriv_label_size);
    if (status != PSA_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    status = psa_aead_encrypt(its_key, ITS_CRYPTO_ALG,
                              ctx->nonce, ctx->nonce_size,
                              ctx->aad, ctx->aad_size,
                              plaintext, plaintext_size,
                              ciphertext, ciphertext_size,
                              &ciphertext_length);
    if (status != PSA_SUCCESS) {
        (void)psa_destroy_key(its_key);
        return TFM_HAL_ERROR_GENERIC;
    }

    /* Copy the tag out of the output buffer */
    ciphertext_length -= TFM_ITS_AUTH_TAG_LENGTH;
    (void)memcpy(tag, (ciphertext + ciphertext_length), tag_size);

    /* Destroy the transient key */
    status = psa_destroy_key(its_key);
    if (status != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return TFM_HAL_SUCCESS;
}

enum tfm_hal_status_t tfm_hal_its_aead_decrypt(
                                        struct tfm_hal_its_auth_crypt_ctx *ctx,
                                        const uint8_t *ciphertext,
                                        const size_t ciphertext_size,
                                        uint8_t *tag,
                                        const size_t tag_size,
                                        uint8_t *plaintext,
                                        const size_t plaintext_size)
{
    psa_status_t status;
    psa_key_handle_t its_key = PSA_KEY_HANDLE_INIT;
    size_t ciphertext_and_tag_size, out_len;

    if (!ctx_is_valid(ctx) || tag == NULL) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if (plaintext_size < ciphertext_size) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    /* Copy the tag into the input buffer */
    (void)memcpy((uint8_t *)(ciphertext + ciphertext_size), tag, TFM_ITS_AUTH_TAG_LENGTH);
    ciphertext_and_tag_size = ciphertext_size + TFM_ITS_AUTH_TAG_LENGTH;

    status = its_crypto_setkey(&its_key, ctx->deriv_label, ctx->deriv_label_size);
    if (status != PSA_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    status = psa_aead_decrypt(its_key, ITS_CRYPTO_ALG,
                              ctx->nonce, ctx->nonce_size,
                              ctx->aad, ctx->aad_size,
                              ciphertext, ciphertext_and_tag_size,
                              plaintext, plaintext_size,
                              &out_len);
    if (status != PSA_SUCCESS) {
        (void)psa_destroy_key(its_key);
        return TFM_HAL_ERROR_GENERIC;
    }

    /* Destroy the transient key */
    status = psa_destroy_key(its_key);
    if (status != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return TFM_HAL_SUCCESS;
}
