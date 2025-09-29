/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "crypto.h"

#include <stdint.h>
#include <string.h>

#include "region_defs.h"
#include "tfm_plat_defs.h"
#include "device_definition.h"
#include "otp.h"
#include "fih.h"
#include "cc3xx_drv.h"
#include "kmu_drv.h"
#include "mbedtls/asn1.h"
#include "bl1_2_config.h"
#include "fatal_error.h"

#include "mbedtls/sha512.h"

#define KEY_DERIVATION_MAX_BUF_SIZE 128

static enum tfm_bl1_hash_alg_t multipart_alg = 0;
static mbedtls_sha512_context multipart_ctx;

/**
 * @brief Computes a hash of the provided data using SHA-256. It calls into
 *        the cc3xx driver directly
 *
 * @param[in]  data        Input data
 * @param[in]  data_length Size in bytes of \p data
 * @param[out] hash        Output hash
 * @param[in]  hash_len    Size in bytes of the \p hash buffer
 * @param[out] hash_size   Size of the produced hash
 *
 * @return FIH_SUCCESS on success, non-zero otherwise
 */
static fih_ret sha256_compute(const uint8_t *data,
                              size_t data_length,
                              uint8_t *hash, size_t hash_len, size_t *hash_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    if ((data == NULL) || (hash == NULL)) {
        FATAL_ERR(TFM_PLAT_ERR_ROM_CRYPTO_SHA256_COMPUTE_INVALID_INPUT);
        FIH_RET(TFM_PLAT_ERR_ROM_CRYPTO_SHA256_COMPUTE_INVALID_INPUT);
    }

    fih_rc = fih_ret_encode_zero_equality(cc3xx_lowlevel_hash_init(CC3XX_HASH_ALG_SHA256));
    if(FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    fih_rc = fih_ret_encode_zero_equality(cc3xx_lowlevel_hash_update(data, data_length));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    cc3xx_lowlevel_hash_finish((uint32_t *)hash, hash_len);

    if (hash_size != NULL) {
        *hash_size = 32;
    }

    FIH_RET(FIH_SUCCESS);
}

/**
 * @brief Computes a hash of the provided data using SHA-384. It calls into a Mbed TLS
 *        based SW implementation of SHA-512/384 as there is no HW support in CryptoCell
 *
 * @param[in]  data        Input data
 * @param[in]  data_length Size in bytes of \p data
 * @param[out] hash        Output hash
 * @param[in]  hash_len    Size in bytes of the \p hash buffer
 * @param[out] hash_size   Size of the produced hash
 *
 * @return FIH_SUCCESS on success, non-zero otherwise
 */
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

static fih_ret sha256_init(void)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    multipart_alg = TFM_BL1_HASH_ALG_SHA256;

    /* This is only used by TFM_BL1_2 which currently only uses SHA256 */
    fih_rc = fih_ret_encode_zero_equality(cc3xx_lowlevel_hash_init(CC3XX_HASH_ALG_SHA256));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_RET(FIH_SUCCESS);
}

static fih_ret sha256_update(const uint8_t *data,
                             size_t data_length)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    fih_rc = fih_ret_encode_zero_equality(cc3xx_lowlevel_hash_update(data, data_length));
    if(FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_RET(FIH_SUCCESS);
}

static fih_ret sha256_finish(uint8_t *hash,
                             size_t hash_length,
                             size_t *hash_size)
{
    cc3xx_lowlevel_hash_finish((uint32_t *)hash, hash_length);

    if (hash_size != NULL) {
        *hash_size = 32;
    }

    multipart_alg = 0;

    FIH_RET(FIH_SUCCESS);
}

static fih_ret sha384_init(void)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    int rc;

    multipart_alg = TFM_BL1_HASH_ALG_SHA384;

    mbedtls_sha512_init(&multipart_ctx);

    rc = mbedtls_sha512_starts(&multipart_ctx, 1);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    FIH_RET(FIH_SUCCESS);

out:
    mbedtls_sha512_free(&multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);

}

static fih_ret sha384_update(const uint8_t *data,
                             size_t data_length)
{
    int rc;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    rc = mbedtls_sha512_update(&multipart_ctx, data, data_length);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    FIH_RET(FIH_SUCCESS);

out:
    mbedtls_sha512_free(&multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);
}

static fih_ret sha384_finish(uint8_t *hash,
                             size_t hash_length,
                             size_t *hash_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    int rc;

    if (hash_length < 48) {
        fih_rc = FIH_FAILURE;
        goto out;
    }

    rc = mbedtls_sha512_finish(&multipart_ctx, hash);
    fih_rc = fih_ret_encode_zero_equality(rc);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        goto out;
    }

    if (hash_size != NULL) {
        *hash_size = 48;
    }

out:
    mbedtls_sha512_free(&multipart_ctx);
    multipart_alg = 0;
    FIH_RET(fih_rc);
}

/**
 * @brief Convert from BL1 key to KMU key (driver specific). For keys
 *        which are not HUK/GUK/Kce_cm, it will load the key material
 *        reading it from the OTP
 *
 * @param[in]  key_id         Id of the key to convert of type \ref tfm_bl1_key_id_t
 * @param[out] cc3xx_key_type Corresponding KMU keyslot
 * @param[out] key_buf        Pointer to buffer containing the key material for non HUK/GUK/Kce_cm
 * @param[in]  key_buf_size   Size in bytes of the buffer pointed by \p key_buf
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
static fih_ret bl1_key_to_kmu_key(enum tfm_bl1_key_id_t key_id,
                                  enum kmu_hardware_keyslot_t *cc3xx_key_type,
                                  uint8_t **key_buf, size_t key_buf_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    switch(key_id) {
    case TFM_BL1_KEY_HUK:
        *cc3xx_key_type = KMU_HW_SLOT_HUK;
        *key_buf = NULL;
        break;
    case TFM_BL1_KEY_GUK:
        *cc3xx_key_type = KMU_HW_SLOT_GUK;
        *key_buf = NULL;
        break;
    case TFM_BL1_KEY_BL2_ENCRYPTION:
        *cc3xx_key_type = KMU_HW_SLOT_KCE_CM;
        *key_buf = NULL;
        break;
    case TFM_BL1_KEY_USER:
        FIH_RET(FIH_FAILURE);

    default:
        FIH_CALL(bl1_otp_read_key, fih_rc, key_id, *key_buf, key_buf_size, NULL);
        *cc3xx_key_type = 0;
        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            memset(*key_buf, 0, key_buf_size);
            FIH_RET(fih_rc);
        }
        break;
    }

    FIH_RET(FIH_SUCCESS);
}

/**
 * @brief Convert from BL1 curve to CC3XX curve (driver_specific)
 *
 * @param[in] bl1_curve BL1 curve to translate to a CC3XX curve
 *
 * @return cc3xx_ec_curve_id_t Converted curve as interpreted by CC3XX driver
 */
static cc3xx_ec_curve_id_t bl1_curve_to_cc3xx_curve(enum tfm_bl1_ecdsa_curve_t bl1_curve)
{
    switch(bl1_curve) {
    case TFM_BL1_CURVE_P256:
        return CC3XX_EC_CURVE_SECP_256_R1;
    case TFM_BL1_CURVE_P384:
        return CC3XX_EC_CURVE_SECP_384_R1;
    default:
        return _CURVE_ID_MAX;
    };
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

fih_ret bl1_aes_256_ctr_decrypt(enum tfm_bl1_key_id_t key_id,
                                const uint8_t *key_material,
                                uint8_t *counter,
                                const uint8_t *ciphertext,
                                size_t ciphertext_length,
                                uint8_t *plaintext)
{
    enum kmu_hardware_keyslot_t kmu_key_slot;
    uint32_t key_buf[32 / sizeof(uint32_t)];
    uint8_t *input_key = (uint8_t *)key_buf;
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    cc3xx_err_t cc_err;

    if (ciphertext_length == 0) {
        FIH_RET(FIH_SUCCESS);
    }

    if ((counter == NULL) || (ciphertext == NULL) || (plaintext == NULL)) {
        fih_rc = fih_ret_encode_zero_equality(TFM_PLAT_ERR_ROM_CRYPTO_AES256_CTR_DECRYPT_INVALID_INPUT);
        FIH_RET(fih_rc);
    }

    if ((uintptr_t)counter & 0x3) {
        fih_rc = fih_ret_encode_zero_equality(TFM_PLAT_ERR_ROM_CRYPTO_AES256_CTR_DECRYPT_INVALID_ALIGNMENT);
        FIH_RET(fih_rc);
    }

    if (key_material == NULL) {
        FIH_CALL(bl1_key_to_kmu_key, fih_rc, key_id, &kmu_key_slot, &input_key, sizeof(key_buf));
        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            FIH_RET(fih_rc);
        }
    } else {
        input_key = (uint8_t *)key_material;
        kmu_key_slot = KMU_INVALID_SLOT;
    }

    cc_err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_DECRYPT, CC3XX_AES_MODE_CTR,
                                     kmu_key_slot, (uint32_t *)input_key,
                                     CC3XX_AES_KEYSIZE_256, (uint32_t *)counter, 16);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        fih_rc = fih_ret_encode_zero_equality(cc_err);
        FIH_RET(fih_rc);
    }

    cc3xx_lowlevel_aes_set_output_buffer(plaintext, ciphertext_length);

    cc_err = cc3xx_lowlevel_aes_update(ciphertext, ciphertext_length);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        fih_rc = fih_ret_encode_zero_equality(cc_err);
        FIH_RET(fih_rc);
    }

    /* Safely ignore the returned value, this API does not return an error for CTR mode */
    (void) cc3xx_lowlevel_aes_finish(NULL, NULL);

    FIH_RET(FIH_SUCCESS);
}

fih_ret bl1_derive_key(enum tfm_bl1_key_id_t key_id, const uint8_t *label,
                       size_t label_length, const uint8_t *context,
                       size_t context_length, uint32_t *output_key,
                       size_t output_length)
{
    enum kmu_hardware_keyslot_t kmu_key_slot;
    uint32_t key_buf[32 / sizeof(uint32_t)];
    uint8_t *input_key = (uint8_t *)key_buf;
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    cc3xx_err_t cc_err;

    FIH_CALL(bl1_key_to_kmu_key, fih_rc, key_id, &kmu_key_slot, &input_key, sizeof(key_buf));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    /* All the relevant secret keys for input are 256-bit */
    cc_err = cc3xx_lowlevel_kdf_cmac(kmu_key_slot, (uint32_t *)input_key,
                                     CC3XX_AES_KEYSIZE_256, label, label_length, context,
                                     context_length, output_key, output_length);

    fih_rc = fih_ret_encode_zero_equality(cc_err);
    FIH_RET(fih_rc);
}

psa_status_t bl1_psa_derive_key(psa_key_id_t key, const uint8_t *label,
                                size_t label_length, const uint8_t *context,
                                size_t context_length, uint8_t *output_key,
                                size_t output_length)
{
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_status_t status;

    status = psa_key_derivation_setup(&operation, PSA_ALG_SP800_108_COUNTER_CMAC);
    if (status != PSA_SUCCESS) {
        goto psa_abort;
    }

    status = psa_key_derivation_set_capacity(&operation, output_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort;
    }

    /* Feed inputs in the order required by PSA key -> label -> context */
    status = psa_key_derivation_input_key(&operation,
                PSA_KEY_DERIVATION_INPUT_SECRET, key);
    if (status != PSA_SUCCESS) {
        goto psa_abort;
    }

    status = psa_key_derivation_input_bytes(&operation,
                PSA_KEY_DERIVATION_INPUT_LABEL, label, label_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort;
    }

    status = psa_key_derivation_input_bytes(&operation,
                PSA_KEY_DERIVATION_INPUT_CONTEXT, context, context_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort;
    }

    status = psa_key_derivation_output_bytes(&operation,
                output_key, output_length);
    if (status != PSA_SUCCESS) {
        goto psa_abort;
    }

psa_abort:
    (void)psa_key_derivation_abort(&operation);
    return status;
}

fih_ret bl1_ecc_derive_key(
    enum tfm_bl1_ecdsa_curve_t curve, enum tfm_bl1_key_id_t key_id,
    const uint8_t *label, size_t label_length,
    const uint8_t *context, size_t context_length,
    uint32_t *output_key, size_t output_size)
{
    const cc3xx_ec_curve_id_t cc_curve = bl1_curve_to_cc3xx_curve(curve);
    enum kmu_hardware_keyslot_t kmu_key_slot;
    uint32_t key_buf[32 / sizeof(uint32_t)];
    uint8_t *input_key = (uint8_t *)key_buf;
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    cc3xx_err_t cc_err;

    if (CC3XX_IS_CURVE_ID_INVALID(cc_curve)) {
        fih_rc = fih_ret_encode_zero_equality(CC3XX_ERR_EC_CURVE_NOT_SUPPORTED);
        FIH_RET(fih_rc);
    }

    FIH_CALL(bl1_key_to_kmu_key, fih_rc, key_id, &kmu_key_slot, &input_key, sizeof(key_buf));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    /* All the relevant secret keys for input are 256-bit */
    cc_err = cc3xx_lowlevel_ecdsa_derive_key(
                 cc_curve, kmu_key_slot, (uint32_t *)input_key,
                 CC3XX_AES_KEYSIZE_256, label, label_length, context,
                 context_length, output_key, output_size, NULL);

    fih_rc = fih_ret_encode_zero_equality(cc_err);
    FIH_RET(fih_rc);
}

fih_ret bl1_internal_ecdsa_verify(enum tfm_bl1_ecdsa_curve_t bl1_curve,
                                const uint32_t *public_key_x,
                                size_t public_key_x_len,
                                const uint32_t *public_key_y,
                                size_t public_key_y_len,
                                const uint32_t *hash, size_t hash_len,
                                const uint32_t *sig_r, size_t sig_r_len,
                                const uint32_t *sig_s, size_t sig_s_len)
{
    cc3xx_err_t cc_err = CC3XX_ERR_SUCCESS;

    cc_err = cc3xx_lowlevel_ecdsa_verify(bl1_curve_to_cc3xx_curve(bl1_curve),
                                            public_key_x, public_key_x_len,
                                            public_key_y, public_key_y_len,
                                            hash, hash_len,
                                            sig_r, sig_r_len,
                                            sig_s, sig_s_len);

    FIH_RET(fih_ret_encode_zero_equality(cc_err));
}

fih_ret bl1_ecdsa_verify(enum tfm_bl1_ecdsa_curve_t curve,
                         uint8_t *key, size_t key_size,
                         const uint8_t *hash,
                         size_t hash_length,
                         const uint8_t *signature,
                         size_t signature_size)
{
    const uint32_t point_size =
        cc3xx_lowlevel_ec_get_modulus_size_from_curve(bl1_curve_to_cc3xx_curve(curve));
    uint32_t pubkey_x[point_size / sizeof(uint32_t)];
    uint32_t pubkey_y[point_size / sizeof(uint32_t)];
    uint32_t sig_r[point_size / sizeof(uint32_t)];
    uint32_t sig_s[point_size / sizeof(uint32_t)];
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    /* We extract at least 2 * point_size from the key buffer, right aligned */
    if (key_size < point_size * 2) {
        FATAL_ERR(TFM_PLAT_ERR_BL1_ECDSA_VERIFY_INVALID_KEY_LEN);
        FIH_RET(fih_ret_encode_zero_equality(TFM_PLAT_ERR_BL1_ECDSA_VERIFY_INVALID_KEY_LEN));
    }

    memcpy(pubkey_x, key + key_size - 2 * point_size, point_size);
    memcpy(pubkey_y, key + key_size - 1 * point_size, point_size);

    if (signature_size < point_size * 2) {
        FATAL_ERR(TFM_PLAT_ERR_BL1_ECDSA_VERIFY_INVALID_SIG_LEN);
        FIH_RET(fih_ret_encode_zero_equality(TFM_PLAT_ERR_BL1_ECDSA_VERIFY_INVALID_SIG_LEN));
    }

    memcpy(sig_r, signature, point_size);
    memcpy(sig_s, signature + point_size, point_size);

    FIH_CALL(bl1_internal_ecdsa_verify, fih_rc, curve, pubkey_x, sizeof(pubkey_x),
                pubkey_y, sizeof(pubkey_y), (uint32_t *)hash, hash_length,
                sig_r, sizeof(sig_r), sig_s, sizeof(sig_s));

    FIH_RET(fih_rc);
}

