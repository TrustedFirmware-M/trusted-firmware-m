/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "bl1_crypto.h"

#include <string.h>
#include "mbedtls/private/sha256.h"
#include "mbedtls/private/sha512.h"
#include "mbedtls/private/aes.h"
#include "mbedtls/md.h"
#include "mbedtls/memory_buffer_alloc.h"
#include "otp.h"

static int mbedtls_is_initialised = 0;
static uint8_t mbedtls_memory_buf[512];

static enum tfm_bl1_hash_alg_t multipart_alg = 0;
static mbedtls_sha256_context sha256_multipart_ctx;
static mbedtls_sha512_context sha384_multipart_ctx;

static void mbedtls_init(uint8_t mbedtls_memory_buf[], size_t size)
{
    mbedtls_memory_buffer_alloc_init(mbedtls_memory_buf,
                                     size);
}

fih_ret bl1_derive_key(enum tfm_bl1_key_id_t input_key, const uint8_t *label,
                       size_t label_length, const uint8_t *context,
                       size_t context_length, uint32_t *output_key,
                       size_t output_length)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    psa_status_t status;
    psa_key_derivation_operation_t op = PSA_KEY_DERIVATION_OPERATION_INIT;
    uint8_t key_buf[32] = {0};
    size_t key_size;

    FIH_CALL(bl1_otp_read_key, fih_rc, input_key, key_buf, sizeof(key_buf), &key_size);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    psa_key_attributes_t input_key_attr = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_id_t input_key_id = MBEDTLS_SVC_KEY_ID_INIT;

    psa_set_key_type(&input_key_attr, PSA_KEY_TYPE_AES);
    psa_set_key_algorithm(&input_key_attr, PSA_ALG_SP800_108_COUNTER_CMAC);
    psa_set_key_bits(&input_key_attr, (key_size * 8));
    psa_set_key_usage_flags(&input_key_attr, PSA_KEY_USAGE_DERIVE);

    status = psa_import_key(&input_key_attr, key_buf, key_size, &input_key_id);
    if (status != PSA_SUCCESS) {
        FIH_RET(FIH_FAILURE);
    }

    status = psa_key_derivation_setup(&op, PSA_ALG_SP800_108_COUNTER_CMAC);
    if (status != PSA_SUCCESS) {
        FIH_RET(FIH_FAILURE);
    }

    status = psa_key_derivation_set_capacity(&op, output_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort_op;
    }

    /* Feed inputs in the order required by PSA key -> label -> context */
    status = psa_key_derivation_input_key(&op, PSA_KEY_DERIVATION_INPUT_SECRET,
                                          input_key_id);
    if (status != PSA_SUCCESS) {
        goto psa_abort_op;
    }

    /* Supply the key label as an input to the key derivation */
    status = psa_key_derivation_input_bytes(&op, PSA_KEY_DERIVATION_INPUT_LABEL,
                                            label, label_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort_op;
    }

    /* Supply the context bytes as an input to the key derivation */
    status = psa_key_derivation_input_bytes(&op, PSA_KEY_DERIVATION_INPUT_CONTEXT,
                                            context, context_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort_op;
    }

    /* Output the required number of bytes from the derivation operation */
    status = psa_key_derivation_output_bytes(&op, output_key, output_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort_op;
    }

psa_abort_op:
    (void)psa_key_derivation_abort(&op);

    fih_rc = fih_ret_encode_zero_equality(status);
    FIH_RET(fih_rc);
}

fih_ret sha256_init()
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    int rc;

    multipart_alg = TFM_BL1_HASH_ALG_SHA256;

    mbedtls_sha256_init(&sha256_multipart_ctx);

    rc = mbedtls_sha256_starts(&sha256_multipart_ctx, 0);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    FIH_RET(FIH_SUCCESS);

out:
    mbedtls_sha256_free(&sha256_multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);

}

fih_ret sha256_finish(uint8_t *hash,
                        size_t hash_length,
                        size_t *hash_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    int rc;

    if (hash_length < 32) {
        fih_rc = FIH_FAILURE;
        goto out;
    }

    rc = mbedtls_sha256_finish(&sha256_multipart_ctx, hash);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    if (hash_size != NULL) {
        *hash_size = 32;
    }

out:
    mbedtls_sha256_free(&sha256_multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);
}

fih_ret sha256_update(const uint8_t *data,
                        size_t data_length)
{
    int rc;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    rc = mbedtls_sha256_update(&sha256_multipart_ctx, data, data_length);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    FIH_RET(FIH_SUCCESS);

out:
    mbedtls_sha256_free(&sha256_multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);
}


fih_ret sha384_init()
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    int rc;

    multipart_alg = TFM_BL1_HASH_ALG_SHA384;

    mbedtls_sha512_init(&sha384_multipart_ctx);

    rc = mbedtls_sha512_starts(&sha384_multipart_ctx, 1);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    FIH_RET(FIH_SUCCESS);

out:
    mbedtls_sha512_free(&sha384_multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);

}

fih_ret sha384_finish(uint8_t *hash,
                        size_t hash_length,
                        size_t *hash_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    int rc;

    if (hash_length < 48) {
        fih_rc = FIH_FAILURE;
        goto out;
    }

    rc = mbedtls_sha512_finish(&sha384_multipart_ctx, hash);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    if (hash_size != NULL) {
        *hash_size = 48;
    }

out:
    mbedtls_sha512_free(&sha384_multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);
}

fih_ret sha384_update(const uint8_t *data,
                        size_t data_length)
{
    int rc;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    rc = mbedtls_sha512_update(&sha384_multipart_ctx, data, data_length);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    FIH_RET(FIH_SUCCESS);

out:
    mbedtls_sha512_free(&sha384_multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);
}

static fih_ret sha256_compute(const uint8_t *data,
                           size_t data_length,
                           uint8_t *hash, size_t hash_len, size_t *hash_size)
{
    int rc = 0;
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    mbedtls_sha256_context ctx;

    if (hash_len < 32) {
        FIH_RET(FIH_FAILURE);
    }

    if (!mbedtls_is_initialised) {
        mbedtls_init(mbedtls_memory_buf, sizeof(mbedtls_memory_buf));
        mbedtls_is_initialised = 1;
    }

    mbedtls_sha256_init(&ctx);

    rc = mbedtls_sha256_starts(&ctx, 0);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    rc = mbedtls_sha256_update(&ctx, data, data_length);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    rc = mbedtls_sha256_finish(&ctx, hash);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    if (hash_size != NULL) {
        *hash_size = 32;
    }

out:
    mbedtls_sha256_free(&ctx);
    FIH_RET(fih_rc);
}

static fih_ret sha384_compute(const uint8_t *data,
                           size_t data_length,
                           uint8_t *hash, size_t hash_len, size_t *hash_size)
{
    int rc = 0;
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    mbedtls_sha512_context ctx;

    if (hash_len < 48) {
        FIH_RET(FIH_FAILURE);
    }

    if (!mbedtls_is_initialised) {
        mbedtls_init(mbedtls_memory_buf, sizeof(mbedtls_memory_buf));
        mbedtls_is_initialised = 1;
    }

    mbedtls_sha512_init(&ctx);

    rc = mbedtls_sha512_starts(&ctx, 1);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    rc = mbedtls_sha512_update(&ctx, data, data_length);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    rc = mbedtls_sha512_finish(&ctx, hash);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    if (hash_size != NULL) {
        *hash_size = 48;
    }


out:
    mbedtls_sha512_free(&ctx);
    FIH_RET(fih_rc);
}

fih_ret bl1_hash_init(enum tfm_bl1_hash_alg_t alg)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    switch(alg) {
    case TFM_BL1_HASH_ALG_SHA256:
        FIH_CALL(sha256_init, fih_rc);
        break;
    case TFM_BL1_HASH_ALG_SHA384:
        FIH_CALL(sha384_init, fih_rc);
        break;
    default:
        fih_rc = FIH_FAILURE;
    }

    FIH_RET(fih_rc);
}

fih_ret bl1_hash_finish(uint8_t *hash,
                        size_t hash_length,
                        size_t *hash_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    switch(multipart_alg) {
    case TFM_BL1_HASH_ALG_SHA256:
        FIH_CALL(sha256_finish, fih_rc, hash, hash_length, hash_size);
        break;
    case TFM_BL1_HASH_ALG_SHA384:
        FIH_CALL(sha384_finish, fih_rc, hash, hash_length, hash_size);
        break;
    default:
        fih_rc = FIH_FAILURE;
    }

    FIH_RET(fih_rc);
}

fih_ret bl1_hash_update(const uint8_t *data,
                        size_t data_length)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    switch(multipart_alg) {
    case TFM_BL1_HASH_ALG_SHA256:
        FIH_CALL(sha256_update, fih_rc, data, data_length);
        break;
    case TFM_BL1_HASH_ALG_SHA384:
        FIH_CALL(sha384_update, fih_rc, data, data_length);
        break;
    default:
        fih_rc = FIH_FAILURE;
    }

    FIH_RET(fih_rc);
}

fih_ret bl1_hash_compute(enum tfm_bl1_hash_alg_t alg,
                         const uint8_t *data,
                         size_t data_length,
                         uint8_t *hash,
                         size_t hash_length,
                         size_t *hash_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    switch(alg) {
    case TFM_BL1_HASH_ALG_SHA256:
        FIH_CALL(sha256_compute, fih_rc, data, data_length, hash, hash_length, hash_size);
        break;
    case TFM_BL1_HASH_ALG_SHA384:
        FIH_CALL(sha384_compute, fih_rc, data, data_length, hash, hash_length, hash_size);
        break;
    default:
        fih_rc = FIH_FAILURE;
    }

    FIH_RET(fih_rc);
}

#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
psa_status_t mbedtls_psa_external_get_random(
    mbedtls_psa_external_random_context_t *context,
    uint8_t *output, size_t output_size, size_t *output_length)
{
    (void)context;

    return PSA_ERROR_NOT_SUPPORTED;
}
#endif /*MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */
