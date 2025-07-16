/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include "rse_provisioning_message_handler.h"

#include "rse_provisioning_message.h"
#include "rse_provisioning_config.h"
#include "device_definition.h"
#include "tfm_log.h"
#include "region_defs.h"
#include "fatal_error.h"
#include "tfm_hal_platform.h"
#include "crypto.h"
#include "tfm_plat_otp.h"
#include "rse_otp_dev.h"
#include "rse_provisioning_comms.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_blob_handler.h"
#include "psa/crypto.h"

#include <string.h>

#ifdef TEST_BL1_1
#define TEST_STATIC
#define TEST_STATIC_INLINE
#else
#define TEST_STATIC static
#define TEST_STATIC_INLINE static inline
#endif

#define AES_IV_LEN 16
#define AES_TAG_MAX_LEN 16

static bool rse_debug_is_enabled(void)
{
    enum lcm_error_t lcm_err;
    uint32_t dcu_values[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)dcu_values);
    if (lcm_err != LCM_ERROR_NONE) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_DEBUG_DISABLED_CHECK_FAILED);
        /* Assume the least secure case if there is an error */
        return true;
    }

    /* FIXME remove this once the FVP is fixed */
    if (dcu_values[0] == 0) {
        return false;
    }

    return (dcu_values[0] & 0x55555555) != 0;
}

static bool rse_disable_debug_and_reset(void)
{
    /* FixMe: Use the reset debug disable mechanism */
    assert(false);
    return false;
}

static enum tfm_plat_err_t is_blob_valid_for_lcs(const struct rse_provisioning_message_blob_t *blob,
                                                 enum lcm_lcs_t lcs)
{
    uint32_t purpose_mask = 0;

    switch(lcs) {
    case LCM_LCS_CM:
       purpose_mask = RSE_PROVISIONING_BLOB_VALID_IN_CM_LCS
                      << RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_OFFSET;
       break;
    case LCM_LCS_DM:
       purpose_mask = RSE_PROVISIONING_BLOB_VALID_IN_DM_LCS
                      << RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_OFFSET;
       break;
    case LCM_LCS_SE:
       purpose_mask = RSE_PROVISIONING_BLOB_VALID_IN_SE_LCS
                      << RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_OFFSET;
       break;
    case LCM_LCS_RMA:
       purpose_mask = RSE_PROVISIONING_BLOB_VALID_IN_RMA_LCS
                      << RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_OFFSET;
       break;
    default:
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_LCS);
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_LCS;
    }

    if (blob->purpose & purpose_mask) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_PURPOSE);
    return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_PURPOSE;
}

static enum tfm_plat_err_t get_tp_mode_for_blob(const struct rse_provisioning_message_blob_t *blob,
                                                enum lcm_tp_mode_t *tp_mode)
{
    enum rse_provisioning_blob_required_tp_mode_config_t tp_mode_config;

    tp_mode_config = (blob->purpose >> RSE_PROVISIONING_BLOB_PURPOSE_TP_MODE_OFFSET)
                     & RSE_PROVISIONING_BLOB_PURPOSE_TP_MODE_MASK;
    switch(tp_mode_config) {
    case RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_VIRGIN:
        *tp_mode = LCM_TP_MODE_VIRGIN;
        return TFM_PLAT_ERR_SUCCESS;
    case RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_PCI:
        *tp_mode = LCM_TP_MODE_PCI;
        return TFM_PLAT_ERR_SUCCESS;
    case RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_TCI:
        *tp_mode = LCM_TP_MODE_TCI;
        return TFM_PLAT_ERR_SUCCESS;
    default:
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_TP_MODE);
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_TP_MODE;
    }
}

static bool is_sp_mode_required_for_blob(const struct rse_provisioning_message_blob_t *blob)
{
    return (((blob->purpose >> RSE_PROVISIONING_BLOB_PURPOSE_SP_MODE_OFFSET)
            & RSE_PROVISIONING_BLOB_PURPOSE_SP_MODE_MASK)
            == RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_ENABLED);
}

static bool is_blob_chainloaded(const struct rse_provisioning_message_blob_t *blob)
{
    return (((blob->purpose >> RSE_PROVISIONING_BLOB_PURPOSE_SEQUENCING_OFFSET)
            & RSE_PROVISIONING_BLOB_PURPOSE_SEQUENCING_MASK)
            == RSE_PROVISIONING_BLOB_CHAINED);
}

static inline bool is_blob_personalized(const struct rse_provisioning_message_blob_t *blob)
{
    return (((blob->metadata >> RSE_PROVISIONING_BLOB_DETAILS_PERSONALIZATION_OFFSET)
            & RSE_PROVISIONING_BLOB_DETAILS_PERSONALIZATION_MASK)
            == RSE_PROVISIONING_BLOB_TYPE_PERSONALIZED);
}

TEST_STATIC_INLINE bool
blob_needs_code_data_decryption(const struct rse_provisioning_message_blob_t *blob)
{
    enum rse_provisioning_blob_code_and_data_decryption_config_t decryption_config =
        (blob->metadata >> RSE_PROVISIONING_BLOB_DETAILS_CODE_DATA_DECRYPTION_OFFSET)
        & RSE_PROVISIONING_BLOB_DETAILS_CODE_DATA_DECRYPTION_MASK;

    return (decryption_config == RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES);
}

TEST_STATIC_INLINE bool
blob_needs_secret_decryption(const struct rse_provisioning_message_blob_t *blob)
{
    enum rse_provisioning_blob_secret_values_decryption_config_t decryption_config =
        (blob->metadata >> RSE_PROVISIONING_BLOB_DETAILS_SECRET_VALUES_DECRYPTION_OFFSET)
        & RSE_PROVISIONING_BLOB_DETAILS_SECRET_VALUES_DECRYPTION_MASK;

    return decryption_config == RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES;
}

psa_status_t copy_auth_code_data(psa_aead_operation_t *operation,
                                 psa_algorithm_t alg,
                                 const struct rse_provisioning_message_blob_t *blob,
                                 void *code_output, size_t code_output_size,
                                 void *data_output, size_t data_output_size)
{
    psa_status_t status;

    memcpy(code_output, blob->code_and_data_and_secret_values, blob->code_size);
    memcpy(data_output, blob->code_and_data_and_secret_values + blob->code_size, blob->data_size);

    if (alg == PSA_ALG_CCM) {
        status = psa_aead_update_ad(operation, code_output, blob->code_size);
        if (status != PSA_SUCCESS) {
            return status;
        }

        status = psa_aead_update_ad(operation, data_output, blob->data_size);
        if (status != PSA_SUCCESS) {
            return status;
        }
    }

    return PSA_SUCCESS;
}

psa_status_t decrypt_code_data(psa_aead_operation_t *operation,
                               const struct rse_provisioning_message_blob_t *blob,
                               void *code_output, size_t code_output_size,
                               void *data_output, size_t data_output_size)
{
    size_t output_length = 0;
    psa_status_t status;

    status = psa_aead_update(operation, blob->code_and_data_and_secret_values,
                             blob->code_size, code_output, code_output_size,
                             &output_length);
    if (status != PSA_SUCCESS) {
        return status;
    } else if (output_length != blob->code_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    status = psa_aead_update(operation, blob->code_and_data_and_secret_values +
                             blob->code_size, blob->data_size, data_output, data_output_size,
                             &output_length);
    if (status != PSA_SUCCESS) {
        return status;
    } else if (output_length != blob->data_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    return PSA_SUCCESS;
}

psa_status_t copy_auth_secret_values(psa_aead_operation_t *operation,
                                     psa_algorithm_t alg,
                                     const struct rse_provisioning_message_blob_t *blob,
                                     void *values_output, size_t values_output_size)
{
    psa_status_t status;

    memcpy(values_output, blob->code_and_data_and_secret_values + blob->code_size + blob->data_size,
           blob->secret_values_size);

    if (alg == PSA_ALG_CCM) {
        status = psa_aead_update_ad(operation, values_output, blob->secret_values_size);
        if (status != PSA_SUCCESS) {
            return status;
        }
    }

    return PSA_SUCCESS;
}

psa_status_t decrypt_secret_values(psa_aead_operation_t *operation,
                                   const struct rse_provisioning_message_blob_t *blob,
                                   void *values_output, size_t values_output_size)
{
    psa_status_t status;
    size_t output_length = 0;

    status = psa_aead_update(operation, blob->code_and_data_and_secret_values +
                             blob->code_size + blob->data_size, blob->secret_values_size,
                             values_output, values_output_size, &output_length);
    if (status != PSA_SUCCESS) {
        return status;
    } else if (output_length != blob->secret_values_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    return PSA_SUCCESS;
}

static enum tfm_plat_err_t aes_generic_blob_operation(psa_algorithm_t alg,
                                                      const struct rse_provisioning_message_blob_t *blob,
                                                      uint8_t *iv, size_t iv_len,
                                                      void *code_output, size_t code_output_size,
                                                      void *data_output, size_t data_output_size,
                                                      void *values_output, size_t values_output_size,
                                                      setup_aes_key_func_t setup_aes_key)
{
    psa_status_t status;
    enum tfm_plat_err_t err;
    size_t actual_blob_size = sizeof(*blob) + blob->code_size + blob->data_size + blob->secret_values_size;
    size_t data_size_to_decrypt = 0;
    size_t data_size_to_auth = 0;
    uint32_t authed_header_offset = offsetof(struct rse_provisioning_message_blob_t, metadata);
    size_t authed_header_size = offsetof(struct rse_provisioning_message_blob_t, code_and_data_and_secret_values) - authed_header_offset;
    enum kmu_hardware_keyslot_t kmu_slot;
    psa_aead_operation_t operation = psa_aead_operation_init();

    if (blob->signature_size < AES_TAG_MAX_LEN) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_TAG_LEN);
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_TAG_LEN;
    }

    if (blob->code_size > code_output_size) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_CODE_SIZE);
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_CODE_SIZE;
    }

    if (blob->data_size > data_output_size) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_DATA_SIZE);
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_DATA_SIZE;
    }

    if (blob->secret_values_size > values_output_size) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_VALUES_SIZE);
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_VALUES_SIZE;
    }

    if (blob_needs_code_data_decryption(blob)) {
        data_size_to_decrypt += blob->code_size;
        data_size_to_decrypt += blob->data_size;
    }

    if (blob_needs_secret_decryption(blob)) {
        data_size_to_decrypt += blob->secret_values_size;
    }

    /* If the values are decrypted by the blob but the code is decrypted here,
     * then the ordering would have changed so that we don't have an
     * _update_auth_data operation after an _update operation. Instead, this is
     * an invalid configuration.
     */
    if (!blob_needs_secret_decryption(blob) && blob_needs_code_data_decryption(blob)) {
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_DECRYPTION_CONFIG;
    }

    data_size_to_auth = actual_blob_size - data_size_to_decrypt - authed_header_offset;

    if ((alg == PSA_ALG_CCM) || (data_size_to_decrypt != 0)) {
        psa_key_id_t psa_key_id;

        err = setup_aes_key(blob, (uint32_t *)&kmu_slot);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            ERROR("Provisioning key setup failed\r\n");
            return err;
        }

        psa_key_id = cc3xx_get_opaque_key(kmu_slot);
        if (CC3XX_IS_OPAQUE_KEY_INVALID(psa_key_id)) {
            ERROR("Invalid key\r\n");
            status = PSA_ERROR_INVALID_ARGUMENT;
            goto psa_abort;
        }

        status = psa_aead_decrypt_setup(&operation, psa_key_id, alg);
        if (status != PSA_SUCCESS) {
            ERROR("AEAD setup failed\r\n");
            goto psa_abort;
        }

        status = psa_aead_set_lengths(&operation, data_size_to_auth, data_size_to_decrypt);
        if (status != PSA_SUCCESS) {
            ERROR("PSA AEAD set lengths failed\r\n");
            goto psa_abort;
        }

        status = psa_aead_set_nonce(&operation, iv, iv_len);
        if (status != PSA_SUCCESS) {
            ERROR("PSA AEAD set nonce failed\r\n");
            goto psa_abort;
        }

        status = psa_aead_update_ad(&operation,
                                    ((uint8_t *)blob) + authed_header_offset,
                                    authed_header_size);
        if (status != PSA_SUCCESS) {
            ERROR("PSA AEAD error updating authed header\r\n");
            goto psa_abort;
        }
    }

    if (blob_needs_code_data_decryption(blob)) {
        status = decrypt_code_data(&operation,
                                   blob,
                                   code_output, code_output_size,
                                   data_output, data_output_size);
    } else {
        status = copy_auth_code_data(&operation, alg,
                                     blob,
                                     code_output, code_output_size,
                                     data_output, data_output_size);
    }
    if (status != PSA_SUCCESS) {
        ERROR("Error decrypting or authenticating code / data\r\n");
        goto psa_abort;
    }

    if (blob_needs_secret_decryption(blob)) {
        status = decrypt_secret_values(&operation,
                                       blob,
                                       values_output, values_output_size);
    } else {
        status = copy_auth_secret_values(&operation, alg,
                                         blob,
                                         values_output, values_output_size);
    }
    if (status != PSA_SUCCESS) {
        ERROR("Error decrypting or authenticating code / data\r\n");
        goto psa_abort;
    }

    if (alg == PSA_ALG_CCM) {
        size_t dummy = 0;

        status = psa_aead_verify(&operation,
                                 NULL,
                                 dummy,
                                 &dummy,
                                 (uint8_t*)blob->signature,
                                 AES_TAG_MAX_LEN);
        if (status != PSA_SUCCESS) {
            ERROR("Tag verification failed!\r\n");
            goto psa_abort;
        }
    } else if (data_size_to_decrypt != 0) {
        size_t dummy = 0;

        status = psa_aead_finish(&operation,
                                 NULL,
                                 dummy,
                                 &dummy,
                                 (uint8_t*)&dummy,
                                 dummy,
                                 &dummy);
        if (status != PSA_SUCCESS) {
            ERROR("Bundle decryption failed!\r\n");
            goto psa_abort;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;

psa_abort:
    ERROR("Aborting %s due to %d error\r\n", __func__, status);
    psa_aead_abort(&operation);
    return (enum tfm_plat_err_t)status;
}

#ifdef RSE_PROVISIONING_ENABLE_AES_SIGNATURES
static fih_ret aes_validate_and_unpack_blob(const struct rse_provisioning_message_blob_t *blob,
                                            void *code_output, size_t code_output_size,
                                            void *data_output, size_t data_output_size,
                                            void *values_output, size_t values_output_size,
                                            setup_aes_key_func_t setup_aes_key)
{
    enum tfm_plat_err_t err;

    uint8_t iv[AES_IV_LEN] = {0};

    memcpy(iv, (uint8_t*)blob->iv, sizeof(blob->iv));

    err = aes_generic_blob_operation(PSA_ALG_CCM, blob,
                                     iv, 8,
                                     code_output, code_output_size,
                                     data_output, data_output_size,
                                     values_output, values_output_size,
                                     setup_aes_key);

    FIH_RET(fih_ret_encode_zero_equality(err));
}
#endif /* RSE_PROVISIONING_ENABLE_AES_SIGNATURES */

#ifdef RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES
static fih_ret aes_decrypt_and_unpack_blob(const struct rse_provisioning_message_blob_t *blob,
                                           void *code_output, size_t code_output_size,
                                           void *data_output, size_t data_output_size,
                                           void *values_output, size_t values_output_size,
                                           setup_aes_key_func_t setup_aes_key)
{
    enum tfm_plat_err_t err;

    uint8_t iv[AES_IV_LEN] = {0};

    memcpy(iv, (uint8_t*)blob->iv, sizeof(blob->iv));

    err = aes_generic_blob_operation(PSA_ALG_CTR, blob, iv, AES_IV_LEN,
                                     code_output, code_output_size,
                                     data_output, data_output_size,
                                     values_output, values_output_size,
                                     setup_aes_key);

    FIH_RET(fih_ret_encode_zero_equality(err));
}

static enum tfm_plat_err_t hash_blob(const struct rse_provisioning_message_blob_t *blob,
                                     void *code_output, size_t code_output_size,
                                     void *data_output, size_t data_output_size,
                                     void *values_output, size_t values_output_size,
                                     uint8_t *hash, size_t hash_len, size_t *hash_size)
{
    int32_t bl1_err;
    const uint32_t authed_header_offset =
        offsetof(struct rse_provisioning_message_blob_t, metadata);
    const size_t authed_header_size =
        offsetof(struct rse_provisioning_message_blob_t, code_and_data_and_secret_values) - authed_header_offset;

    FIH_CALL(bl1_hash_init, bl1_err, RSE_PROVISIONING_HASH_ALG);
    if (FIH_NOT_EQ(bl1_err, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)bl1_err;
    }

    FIH_CALL(bl1_hash_update, bl1_err, ((uint8_t *)blob) + authed_header_offset,
                                        authed_header_size);
    if (FIH_NOT_EQ(bl1_err, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)bl1_err;
    }

    FIH_CALL(bl1_hash_update, bl1_err, code_output, blob->code_size);
    if (FIH_NOT_EQ(bl1_err, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)bl1_err;
    }

    FIH_CALL(bl1_hash_update, bl1_err, data_output, blob->data_size);
    if (FIH_NOT_EQ(bl1_err, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)bl1_err;
    }

    FIH_CALL(bl1_hash_update, bl1_err, values_output, blob->secret_values_size);
    if (FIH_NOT_EQ(bl1_err, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)bl1_err;
    }

    FIH_CALL(bl1_hash_finish, bl1_err, hash, hash_len, hash_size);
    if (FIH_NOT_EQ(bl1_err, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)bl1_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static fih_ret ecdsa_validate_and_unpack_blob(const struct rse_provisioning_message_blob_t *blob,
                                                          void *code_output, size_t code_output_size,
                                                          void *data_output, size_t data_output_size,
                                                          void *values_output, size_t values_output_size,
                                                          setup_aes_key_func_t setup_aes_key,
                                                          get_rotpk_func_t get_rotpk)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    FIH_RET_TYPE(enum tfm_plat_err_t) err;
    uint32_t blob_hash[RSE_PROVISIONING_HASH_SIZE / sizeof(uint32_t)];
    uint32_t *public_key_x;
    uint32_t *public_key_y;
    size_t public_key_x_size;
    size_t public_key_y_size;
    size_t sig_point_len = blob->signature_size / 2;
    size_t hash_size;

    /* FixMe: Check the usage of AES in the ECDSA signed blob */
    FIH_CALL(aes_decrypt_and_unpack_blob, fih_rc, blob,
                                      code_output, code_output_size,
                                      data_output, data_output_size,
                                      values_output, values_output_size,
                                      setup_aes_key);
    if (fih_rc != FIH_SUCCESS) {
        FIH_RET(fih_rc);
    }

    err = hash_blob(blob,
                    code_output, code_output_size,
                    data_output, data_output_size,
                    values_output, values_output_size,
                    (uint8_t *)blob_hash, sizeof(blob_hash), &hash_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_ret_encode_zero_equality(err));
    }

    err = get_rotpk(blob, &public_key_x, &public_key_x_size, &public_key_y, &public_key_y_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_ret_encode_zero_equality(err));
    }

    FIH_CALL(bl1_internal_ecdsa_verify, fih_rc, RSE_PROVISIONING_CURVE,
             public_key_x, public_key_x_size,
             public_key_y, public_key_y_size,
             blob_hash, hash_size,
             (uint32_t *)blob->signature, sig_point_len,
             (uint32_t *)(blob->signature + sig_point_len), sig_point_len);
    FIH_RET(fih_rc);
}
#endif /* RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES */

TEST_STATIC fih_ret
validate_and_unpack_blob(const struct rse_provisioning_message_blob_t *blob, size_t msg_size,
                         void *code_output, size_t code_output_size, void *data_output,
                         size_t data_output_size, void *values_output, size_t values_output_size,
                         setup_aes_key_func_t setup_aes_key, get_rotpk_func_t get_rotpk)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    enum rse_provisioning_blob_signature_config_t sig_config;

    /* Perform the size check stepwise in order to avoid the risk of underflowing
     * and check that msg_size is the sum of code, data, secret_values sizes + header size
     */
    if (msg_size < sizeof(*blob)
     || blob->code_size > msg_size - sizeof(*blob)
     || blob->data_size > (msg_size - sizeof(*blob) - blob->code_size)
     || blob->secret_values_size != (msg_size - sizeof(*blob) - blob->code_size - blob->data_size)) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_SIZE);
        FIH_RET(fih_ret_encode_zero_equality(TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_SIZE));
    }

    if (blob->code_size == 0) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_BLOB_ZERO_CODE_SIZE);
        FIH_RET(fih_ret_encode_zero_equality(TFM_PLAT_ERR_PROVISIONING_BLOB_ZERO_CODE_SIZE));
    }

    sig_config = (blob->metadata >> RSE_PROVISIONING_BLOB_DETAILS_SIGNATURE_OFFSET)
                 & RSE_PROVISIONING_BLOB_DETAILS_SIGNATURE_MASK;
    switch(sig_config) {
#ifdef RSE_PROVISIONING_ENABLE_AES_SIGNATURES
    case RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE:
        FIH_CALL(aes_validate_and_unpack_blob, fih_rc, blob,
                 code_output, code_output_size,
                 data_output, data_output_size,
                 values_output, values_output_size,
                 setup_aes_key);
        FIH_RET(fih_rc);
#endif
#ifdef RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES
    case RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_IN_ROM:
    case RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM:
        FIH_CALL(ecdsa_validate_and_unpack_blob, fih_rc, blob,
                 code_output, code_output_size,
                 data_output, data_output_size,
                 values_output, values_output_size,
                 setup_aes_key, get_rotpk);
        FIH_RET(fih_rc);
#endif
    default:
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_SIGNATURE_TYPE_NOT_SUPPORTED);
        FIH_RET(fih_ret_encode_zero_equality(TFM_PLAT_ERR_PROVISIONING_SIGNATURE_TYPE_NOT_SUPPORTED));
    }
}

static enum tfm_plat_err_t run_blob(void *code_ptr)
{
    enum tfm_plat_err_t err;

    INFO("Running blob\n");

    err = ((enum tfm_plat_err_t (*)(void))((uintptr_t)code_ptr | 0b1))();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t default_blob_handler(const struct rse_provisioning_message_blob_t *blob,
                                         size_t msg_size, const void *ctx)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    enum tfm_plat_err_t err;
    enum lcm_lcs_t lcs;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_tp_mode_t blob_tp_mode;
    enum lcm_error_t lcm_err;
    enum lcm_bool_t sp_mode_enabled;

    struct default_blob_handler_ctx_t *blob_ctx = (struct default_blob_handler_ctx_t *)ctx;

    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    err = get_tp_mode_for_blob(blob, &blob_tp_mode);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (blob_tp_mode != tp_mode) {
        if (tp_mode == LCM_TP_MODE_VIRGIN && blob_tp_mode == LCM_TP_MODE_PCI) {
            lcm_err = lcm_set_tp_mode(&LCM_DEV_S, LCM_TP_MODE_PCI);
            if (lcm_err != LCM_ERROR_NONE) {
                message_handling_status_report_error(PROVISIONING_REPORT_STEP_SET_TP_MODE_PCI,
                                                  lcm_err);
                return (enum tfm_plat_err_t)lcm_err;
            }
            message_handling_status_report_continue(PROVISIONING_REPORT_STEP_SET_TP_MODE_PCI);
#ifdef RSE_PROVISIONING_ISSUE_SELF_RESET
            tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
#endif
        }

#if !(defined(RSE_PROVISIONING_CM_DEBUG_CLOSED) && defined(RSE_PROVISIONING_REQUIRE_AUTHENTICATION_FOR_TCI))
        if (tp_mode == LCM_TP_MODE_VIRGIN && blob_tp_mode == LCM_TP_MODE_TCI) {
            lcm_err = lcm_set_tp_mode(&LCM_DEV_S, LCM_TP_MODE_TCI);
            if (lcm_err != LCM_ERROR_NONE) {
                message_handling_status_report_error(PROVISIONING_REPORT_STEP_SET_TP_MODE_TCI,
                                                  lcm_err);
                return (enum tfm_plat_err_t)lcm_err;
            }
            message_handling_status_report_continue(PROVISIONING_REPORT_STEP_SET_TP_MODE_TCI);
#ifdef RSE_PROVISIONING_ISSUE_SELF_RESET
            tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
#endif
        }
#endif

        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_INVALID_TP_MODE);
        return TFM_PLAT_ERR_PROVISIONING_INVALID_TP_MODE;
    }

    err = is_blob_valid_for_lcs(blob, lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    lcm_err = lcm_get_sp_enabled(&LCM_DEV_S, &sp_mode_enabled);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (is_sp_mode_required_for_blob(blob) && (sp_mode_enabled == LCM_FALSE)) {
        err = tfm_plat_otp_secure_provisioning_start();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        /* This function returning (and not resetting) is an error */
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_START_FAILED);
        return TFM_PLAT_ERR_PROVISIONING_START_FAILED;
    } else if (rse_debug_is_enabled()){
        err = rse_disable_debug_and_reset();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        /* This function returning (and not resetting) is an error */
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_DEBUG_DISABLE_FAILED);
        return TFM_PLAT_ERR_PROVISIONING_DEBUG_DISABLE_FAILED;
    }

    lcm_err = lcm_get_sp_enabled(&LCM_DEV_S, &sp_mode_enabled);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (is_sp_mode_required_for_blob(blob) != (sp_mode_enabled == LCM_TRUE)) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_INVALID_SP_MODE);
        return TFM_PLAT_ERR_PROVISIONING_INVALID_SP_MODE;
    }

    if (is_blob_chainloaded(blob) != blob_ctx->blob_is_chainloaded) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_INVALID_BLOB_SEQUENCING);
        return TFM_PLAT_ERR_PROVISIONING_INVALID_BLOB_SEQUENCING;
    }

    if (is_blob_personalized(blob)) {
#ifdef RSE_OTP_HAS_SOC_AREA
        if (memcmp(blob->soc_uid, (void *)P_RSE_OTP_SOC->soc_id_area.unique_id,
                   sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id)) != 0) {
            FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_INVALID_BLOB_PERSONALIZATION);
            return TFM_PLAT_ERR_PROVISIONING_INVALID_BLOB_PERSONALIZATION;
        }
#else
        /* Cannot accept personalized blobs for OTP without SoC Area*/
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_INVALID_BLOB_PERSONALIZATION);
        return TFM_PLAT_ERR_PROVISIONING_INVALID_BLOB_PERSONALIZATION;
#endif /* RSE_OTP_HAS_SOC_AREA */

    } else {
#if RSE_CM_REQUIRES_PERSONALIZED_BLOBS
        if (lcs == LCM_LCS_CM) {
            FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_CM_DERIVATION_NOT_PERSONALIZED);
            return TFM_PLAT_ERR_PROVISIONING_CM_DERIVATION_NOT_PERSONALIZED;
        }
#endif
#ifdef RSE_DM_REQUIRES_PERSONALIZED_BLOBS
        if (lcs == LCM_LCS_DM) {
            FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_DM_DERIVATION_NOT_PERSONALIZED);
            return TFM_PLAT_ERR_PROVISIONING_DM_DERIVATION_NOT_PERSONALIZED;
        }
#endif
    }

    FIH_CALL(validate_and_unpack_blob, fih_rc, blob, msg_size,
             (void * )PROVISIONING_BUNDLE_CODE_START,
             PROVISIONING_BUNDLE_CODE_SIZE,
             (void * )PROVISIONING_BUNDLE_DATA_START,
             PROVISIONING_BUNDLE_DATA_SIZE,
             (void * )PROVISIONING_BUNDLE_VALUES_START,
             PROVISIONING_BUNDLE_VALUES_SIZE,
             blob_ctx->setup_aes_key, blob_ctx->get_rotpk);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        message_handling_status_report_error(PROVISIONING_REPORT_STEP_VALIDATE_BLOB, err);
        return (enum tfm_plat_err_t)fih_ret_decode_zero_equality(fih_rc);
    }

    message_handling_status_report_continue(PROVISIONING_REPORT_STEP_VALIDATE_BLOB);

    err = run_blob((void *)PROVISIONING_BUNDLE_CODE_START);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
