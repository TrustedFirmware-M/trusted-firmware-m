/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "pq_crypto.h"
#include "crypto.h"
#include "mbedtls/lms.h"
#include "otp.h"
#include "psa/crypto.h"

/* Unused function defined to prevent Armclang missing symbol error */
psa_status_t psa_generate_random(uint8_t *output, size_t output_size)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_hash_setup(
    psa_hash_operation_t *operation,
    psa_algorithm_t alg)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    (void)operation;
    (void)alg;

    FIH_CALL(bl1_hash_init, fih_rc, TFM_BL1_HASH_ALG_SHA256);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        return (psa_status_t)fih_ret_decode_zero_equality(fih_rc);
    }

    return PSA_SUCCESS;
}

psa_status_t psa_hash_update(
    psa_hash_operation_t *operation,
    const uint8_t *input,
    size_t input_length)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    (void)operation;

    FIH_CALL(bl1_hash_update, fih_rc, (unsigned char *)input, input_length);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        return (psa_status_t)fih_ret_decode_zero_equality(fih_rc);
    }

    return PSA_SUCCESS;
}

psa_status_t psa_hash_finish(
    psa_hash_operation_t *operation,
    uint8_t *hash,
    size_t hash_size,
    size_t *hash_length)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    (void)operation;
    (void)hash_size;

    FIH_CALL(bl1_hash_finish, fih_rc, hash, hash_size, hash_length);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        return (psa_status_t)fih_ret_decode_zero_equality(fih_rc);
    }

    return PSA_SUCCESS;
}

psa_status_t psa_hash_abort(
    psa_hash_operation_t *operation)
{
    (void)operation;

    return PSA_SUCCESS;
}

fih_ret pq_crypto_verify(uint8_t *key, size_t key_size,
                         const uint8_t *data,
                         size_t data_length,
                         const uint8_t *signature,
                         size_t signature_length)
{
    int rc;
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    mbedtls_lms_public_t ctx;

    mbedtls_lms_public_init(&ctx);

    rc = mbedtls_lms_import_public_key(&ctx, key, key_size);

    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    rc = mbedtls_lms_verify(&ctx, data, data_length, signature, signature_length);
    fih_rc = fih_ret_encode_zero_equality(rc);

out:
    mbedtls_lms_public_free(&ctx);
    FIH_RET(fih_rc);
}

int pq_crypto_get_pub_key_hash(enum tfm_bl1_key_id_t key,
                               uint8_t *hash,
                               size_t hash_size,
                               size_t *hash_length)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    uint8_t key_buf[MBEDTLS_LMS_PUBLIC_KEY_LEN(MBEDTLS_LMS_SHA256_M32_H10)];
    size_t key_size;

    if (hash_size < 32) {
        return -1;
    }

    FIH_CALL(bl1_otp_read_key, fih_rc, key, key_buf, sizeof(key_buf), &key_size);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(bl1_hash_compute, fih_rc, TFM_BL1_HASH_ALG_SHA256, key_buf, sizeof(key_buf),
                                       hash, sizeof(hash), hash_length);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    return 0;
}
