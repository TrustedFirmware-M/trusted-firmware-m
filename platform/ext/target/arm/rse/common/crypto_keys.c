/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "tfm_plat_crypto_keys.h"
#include "tfm_builtin_key_ids.h"
#include "region_defs.h"
#include "cmsis_compiler.h"
#include "tfm_plat_otp.h"
#include "psa_manifest/pid.h"
#include "tfm_builtin_key_loader.h"
#include "kmu_drv.h"
#include "device_definition.h"
#include "tfm_plat_otp.h"
#include "rse_kmu_slot_ids.h"
#include "rse_rotpk_mapping.h"

#define NUMBER_OF_ELEMENTS_OF(x) sizeof(x)/sizeof(*x)
#define MAPPED_RSE_MBOX_NS_AGENT_DEFAULT_CLIENT_ID -0x04000000
#define TFM_NS_PARTITION_ID                        MAPPED_RSE_MBOX_NS_AGENT_DEFAULT_CLIENT_ID

static enum tfm_plat_err_t tfm_plat_get_huk(const void *ctx,
                                            uint8_t *buf, size_t buf_len,
                                            size_t *key_len,
                                            psa_key_bits_t *key_bits,
                                            psa_algorithm_t *algorithm,
                                            psa_key_type_t *type)
{
    enum kmu_error_t kmu_err;

    if (buf_len < 32) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    *key_len = 32;
    *key_bits = 256;
    *algorithm = PSA_ALG_HKDF(PSA_ALG_SHA_256);
    *type = PSA_KEY_TYPE_DERIVE;

    kmu_err = kmu_get_key(&KMU_DEV_S, RSE_KMU_SLOT_VHUK, buf, 32);
    if (kmu_err != KMU_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t tfm_plat_get_iak(const void *ctx,
                                     uint8_t *buf, size_t buf_len,
                                     size_t *key_len,
                                     psa_key_bits_t *key_bits,
                                     psa_algorithm_t *algorithm,
                                     psa_key_type_t *type)
{
    psa_status_t status;
    enum kmu_error_t kmu_err;
    psa_key_attributes_t seed_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t transient_attr = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_handle_t seed_key = PSA_KEY_HANDLE_INIT;
    psa_key_handle_t transient_key = PSA_KEY_HANDLE_INIT;
    psa_key_derivation_operation_t op = PSA_KEY_DERIVATION_OPERATION_INIT;

    if (buf_len < PSA_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(ATTEST_KEY_BITS)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    kmu_err = kmu_get_key(&KMU_DEV_S, RSE_KMU_SLOT_IAK_SEED, buf, 32);
    if (kmu_err != KMU_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    psa_set_key_type(&seed_attributes, PSA_KEY_TYPE_DERIVE);
    psa_set_key_algorithm(&seed_attributes, PSA_ALG_HKDF(PSA_ALG_SHA_256));
    psa_set_key_bits(&seed_attributes, 256);
    psa_set_key_usage_flags(&seed_attributes, PSA_KEY_USAGE_DERIVE);

    status = psa_import_key(&seed_attributes, buf, 32, &seed_key);
    if (status != PSA_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    status = psa_key_derivation_setup(&op, PSA_ALG_HKDF(PSA_ALG_SHA_256));
    if (status != PSA_SUCCESS) {
        goto err_release_seed_key;
    }

    status = psa_key_derivation_input_key(&op, PSA_KEY_DERIVATION_INPUT_SECRET,
                                          seed_key);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    status = psa_key_derivation_input_bytes(&op, PSA_KEY_DERIVATION_INPUT_INFO,
                                            NULL, 0);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    *key_bits = ATTEST_KEY_BITS;
#if (ATTEST_KEY_BITS == 256)
    *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
#elif (ATTEST_KEY_BITS == 384)
    *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_384);
#else
#error "Unsupported IAK size"
#endif
    *type = PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1);

    psa_set_key_type(&transient_attr, *type);
    psa_set_key_algorithm(&transient_attr, *algorithm);
    psa_set_key_bits(&transient_attr, *key_bits);
    psa_set_key_usage_flags(&transient_attr, PSA_KEY_USAGE_EXPORT);

    status = psa_key_derivation_output_key(&transient_attr, &op, &transient_key);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    status = psa_export_key(transient_key, buf, buf_len, key_len);
    if (status != PSA_SUCCESS) {
        goto err_release_transient_key;
    }

    status = psa_destroy_key(transient_key);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    status = psa_key_derivation_abort(&op);
    if (status != PSA_SUCCESS) {
        goto err_release_seed_key;
    }

    status = psa_destroy_key(seed_key);
    if (status != PSA_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return PSA_SUCCESS;

err_release_transient_key:
    (void)psa_destroy_key(transient_key);

err_release_op:
    (void)psa_key_derivation_abort(&op);

err_release_seed_key:
    (void)psa_destroy_key(seed_key);

    return TFM_PLAT_ERR_SYSTEM_ERR;
}

#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
static enum tfm_plat_err_t tfm_plat_get_dak_seed(const void *ctx,
                                                 uint8_t *buf, size_t buf_len,
                                                 size_t *key_len,
                                                 psa_key_bits_t *key_bits,
                                                 psa_algorithm_t *algorithm,
                                                 psa_key_type_t *type)
{
    enum kmu_error_t kmu_err;

    if (buf_len < 32) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    *key_len = 32;
    *key_bits = 256;
    *algorithm = PSA_ALG_HKDF(PSA_ALG_SHA_256);
    *type = PSA_KEY_TYPE_DERIVE;

    kmu_err = kmu_get_key(&KMU_DEV_S, RSE_KMU_SLOT_DAK_SEED, buf, 32);
    if (kmu_err != KMU_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */

#ifdef TFM_PARTITION_DPE
static enum tfm_plat_err_t tfm_plat_get_rot_cdi(const void *ctx,
                                                uint8_t *buf, size_t buf_len,
                                                size_t *key_len,
                                                psa_key_bits_t *key_bits,
                                                psa_algorithm_t *algorithm,
                                                psa_key_type_t *type)
{
    enum kmu_error_t kmu_err;

    if (buf_len < 32) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    *key_len = 32;
    *key_bits = 256;
    *algorithm = PSA_ALG_HKDF(PSA_ALG_SHA_256);
    *type = PSA_KEY_TYPE_DERIVE;

    kmu_err = kmu_get_key(&KMU_DEV_S, RSE_KMU_SLOT_ROT_CDI, buf, 32);
    if (kmu_err != KMU_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* TFM_PARTITION_DPE */

static enum tfm_plat_err_t tfm_plat_load_cm_host_key(const void *ctx,
                                                     uint8_t *buf, size_t buf_len,
                                                     size_t *key_len,
                                                     psa_key_bits_t *key_bits,
                                                     psa_algorithm_t *algorithm,
                                                     psa_key_type_t *type)
{
    tfm_plat_builtin_key_descriptor_t *descriptor =
        (tfm_plat_builtin_key_descriptor_t *)ctx;
    enum tfm_otp_element_id_t otp_id =
        rse_cm_get_host_rotpk(TFM_BUILTIN_KEY_HOST_CM_MIN - descriptor->key_id);
    size_t key_size;
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_get_size(otp_id, &key_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *key_len = key_size;
    *key_bits = key_size * 8;

#ifdef RSE_OTP_CM_ROTPK_IS_HASH_NOT_KEY
    *algorithm = PSA_ALG_NONE;
    *type = PSA_KEY_TYPE_VENDOR_FLAG | PSA_KEY_TYPE_CATEGORY_RAW;
#else
    if (key_size == 64) {
        *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
    } else if (key_size == 96) {
        *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_384);
    } else {
        *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_512);
    }

    *type = PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1);
#endif

    return tfm_plat_otp_read(otp_id, buf_len, buf);
}

static enum tfm_plat_err_t tfm_plat_load_dm_host_key(const void *ctx,
                                                     uint8_t *buf, size_t buf_len,
                                                     size_t *key_len,
                                                     psa_key_bits_t *key_bits,
                                                     psa_algorithm_t *algorithm,
                                                     psa_key_type_t *type)
{
    tfm_plat_builtin_key_descriptor_t *descriptor =
        (tfm_plat_builtin_key_descriptor_t *)ctx;
    enum tfm_otp_element_id_t otp_id =
        rse_dm_get_host_rotpk(TFM_BUILTIN_KEY_HOST_DM_MIN - descriptor->key_id);
    size_t key_size;
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_get_size(otp_id, &key_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *key_len = key_size;
    *key_bits = key_size * 8;

#ifdef RSE_OTP_DM_ROTPK_IS_HASH_NOT_KEY
    *algorithm = PSA_ALG_NONE;
    *type = PSA_KEY_TYPE_VENDOR_FLAG | PSA_KEY_TYPE_CATEGORY_RAW;
#else
    if (key_size == 64) {
        *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
    } else if (key_size == 96) {
        *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_384);
    } else {
        *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_512);
    }

    *type = PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1);
#endif

    return tfm_plat_otp_read(otp_id, buf_len, buf);
}

/**
 * @brief Table describing per-user key policy for the IAK
 *
 */
static const tfm_plat_builtin_key_per_user_policy_t g_iak_per_user_policy[] = {
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
    {.user = TFM_SP_INITIAL_ATTESTATION,
#ifdef SYMMETRIC_INITIAL_ATTESTATION
        .usage = PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_EXPORT,
#else
        .usage = PSA_KEY_USAGE_SIGN_HASH,
#endif /* SYMMETRIC_INITIAL_ATTESTATION */
    },
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
#ifdef TEST_S_ATTESTATION
    {.user = TFM_SP_SECURE_TEST_PARTITION, .usage = PSA_KEY_USAGE_VERIFY_HASH},
#endif /* TEST_S_ATTESTATION */
#ifdef TEST_NS_ATTESTATION
    {.user = TFM_NS_PARTITION_ID, .usage = PSA_KEY_USAGE_VERIFY_HASH},
#endif /* TEST_NS_ATTESTATION */
#ifdef TFM_PARTITION_DPE
    {.user = TFM_SP_DPE, .usage = PSA_KEY_USAGE_SIGN_HASH},
#endif /* TFM_PARTITION_DPE */
};

#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
/**
 * @brief Table describing per-user key policy for the DAK seed
 *
 */
static const tfm_plat_builtin_key_per_user_policy_t g_dak_seed_per_user_policy[] = {
    {.user = TFM_SP_DELEGATED_ATTESTATION, .usage = PSA_KEY_USAGE_DERIVE},
};
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */

#ifdef TFM_PARTITION_DPE
/**
 * @brief Table describing per-user key policy for the RoT CDI
 *
 */
static const tfm_plat_builtin_key_per_user_policy_t g_rot_cdi_per_user_policy[] = {
    {.user = TFM_SP_DPE,
     .usage = PSA_KEY_USAGE_DERIVE | PSA_KEY_USAGE_EXPORT},
};
#endif /* TFM_PARTITION_DPE */

/**
 * @brief Table describing per-user key policy for all the HOST RoTPK (S, NS, CCA)
 *
 */
static const tfm_plat_builtin_key_per_user_policy_t g_host_rotpk_per_user_policy[] = {
    {.user = TFM_NS_PARTITION_ID, .usage = PSA_KEY_USAGE_VERIFY_HASH},
};

/**
 * @brief Table describing per-key user policies
 *
 */
static const tfm_plat_builtin_key_policy_t g_builtin_keys_policy[] = {
    {.key_id = TFM_BUILTIN_KEY_ID_HUK, .per_user_policy = 0, .usage = PSA_KEY_USAGE_DERIVE},
    {.key_id = TFM_BUILTIN_KEY_ID_IAK,
     .per_user_policy = NUMBER_OF_ELEMENTS_OF(g_iak_per_user_policy),
     .policy_ptr = g_iak_per_user_policy},
#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
    {.key_id = TFM_BUILTIN_KEY_ID_DAK_SEED,
     .per_user_policy = NUMBER_OF_ELEMENTS_OF(g_dak_seed_per_user_policy),
     .policy_ptr = g_dak_seed_per_user_policy},
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */
#ifdef TFM_PARTITION_DPE
    {.key_id = TFM_BUILTIN_KEY_ID_ROT_CDI,
     .per_user_policy = NUMBER_OF_ELEMENTS_OF(g_rot_cdi_per_user_policy),
     .policy_ptr = g_rot_cdi_per_user_policy},
#endif /* TFM_PARTITION_DPE */
};

/**
 * @brief Table describing the builtin-in keys (platform keys) available in the platform. Note
 *        that to bind the keys to the tfm_builtin_key_loader driver, the lifetime must be
 *        explicitly set to the one associated to the driver, i.e. TFM_BUILTIN_KEY_LOADER_LIFETIME
 */
static const tfm_plat_builtin_key_descriptor_t g_builtin_keys_desc[] = {
    {.key_id = TFM_BUILTIN_KEY_ID_HUK,
     .slot_number = TFM_BUILTIN_KEY_SLOT_HUK,
     .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
     .loader_key_func = tfm_plat_get_huk,
     .loader_key_ctx = NULL},
    {.key_id = TFM_BUILTIN_KEY_ID_IAK,
     .slot_number = TFM_BUILTIN_KEY_SLOT_IAK,
     .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
     .loader_key_func = tfm_plat_get_iak,
     .loader_key_ctx = NULL},
#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
    {.key_id = TFM_BUILTIN_KEY_ID_DAK_SEED,
     .slot_number = TFM_BUILTIN_KEY_SLOT_DAK_SEED,
     .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
     .loader_key_func = tfm_plat_get_dak_seed,
     .loader_key_ctx = NULL},
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */
#ifdef TFM_PARTITION_DPE
    {.key_id = TFM_BUILTIN_KEY_ID_ROT_CDI,
     .slot_number = TFM_BUILTIN_KEY_SLOT_ROT_CDI,
     .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
     .loader_key_func = tfm_plat_get_rot_cdi,
     .loader_key_ctx = NULL},
#endif /* TFM_PARTITION_DPE */
};

size_t tfm_plat_builtin_key_get_policy_table_ptr(const tfm_plat_builtin_key_policy_t *policy_ptr[])
{
    static bool dynamic_table_set_up = false;
    static tfm_plat_builtin_key_policy_t dynamic_policy_table[NUMBER_OF_ELEMENTS_OF(g_builtin_keys_policy) +
                                                                RSE_ROTPK_CM_HOST_AMOUNT +
                                                                RSE_ROTPK_DM_HOST_AMOUNT];

    if (!dynamic_table_set_up) {
        tfm_plat_builtin_key_policy_t *dynamic_table_fill_ptr =
            &dynamic_policy_table[NUMBER_OF_ELEMENTS_OF(g_builtin_keys_policy)];
        memcpy(dynamic_policy_table, g_builtin_keys_policy, sizeof(g_builtin_keys_policy));

        for (uint32_t idx = 0; idx < RSE_ROTPK_CM_HOST_AMOUNT; idx++) {
             tfm_plat_builtin_key_policy_t policy = {
                .key_id = TFM_BUILTIN_KEY_HOST_CM_MIN + idx,
                .per_user_policy = NUMBER_OF_ELEMENTS_OF(g_host_rotpk_per_user_policy),
                .policy_ptr = g_host_rotpk_per_user_policy,
            };

            *dynamic_table_fill_ptr = policy;
            dynamic_table_fill_ptr++;
        }

        for (uint32_t idx = 0; idx < RSE_ROTPK_DM_HOST_AMOUNT; idx++) {
             tfm_plat_builtin_key_policy_t policy = {
                .key_id = TFM_BUILTIN_KEY_HOST_DM_MIN + idx,
                .per_user_policy = NUMBER_OF_ELEMENTS_OF(g_host_rotpk_per_user_policy),
                .policy_ptr = g_host_rotpk_per_user_policy,
            };

            *dynamic_table_fill_ptr = policy;
            dynamic_table_fill_ptr++;
        }

        dynamic_table_set_up = true;
    }

    *policy_ptr = &dynamic_policy_table[0];
    return NUMBER_OF_ELEMENTS_OF(dynamic_policy_table);
}

size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[])
{
    static bool dynamic_table_set_up = false;
    static tfm_plat_builtin_key_descriptor_t dynamic_desc_table[NUMBER_OF_ELEMENTS_OF(g_builtin_keys_desc) +
                                                                RSE_ROTPK_CM_HOST_AMOUNT +
                                                                RSE_ROTPK_DM_HOST_AMOUNT];

    if (!dynamic_table_set_up) {
        tfm_plat_builtin_key_descriptor_t *dynamic_table_fill_ptr =
            &dynamic_desc_table[NUMBER_OF_ELEMENTS_OF(g_builtin_keys_desc)];
        memcpy(dynamic_desc_table, g_builtin_keys_desc, sizeof(g_builtin_keys_desc));

        for (uint32_t idx = 0; idx < RSE_ROTPK_CM_HOST_AMOUNT; idx++) {
             tfm_plat_builtin_key_descriptor_t desc = {
                .key_id = TFM_BUILTIN_KEY_HOST_CM_MIN + idx,
                .slot_number = TFM_BUILTIN_KEY_SLOT_HOST_CM_MIN + idx,
                .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
                .loader_key_func = tfm_plat_load_cm_host_key,
                .loader_key_ctx = dynamic_table_fill_ptr,
            };

            *dynamic_table_fill_ptr = desc;
            dynamic_table_fill_ptr++;
        }

        for (uint32_t idx = 0; idx < RSE_ROTPK_DM_HOST_AMOUNT; idx++) {
             tfm_plat_builtin_key_descriptor_t desc = {
                .key_id = TFM_BUILTIN_KEY_HOST_DM_MIN + idx,
                .slot_number = TFM_BUILTIN_KEY_SLOT_HOST_DM_MIN + idx,
                .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
                .loader_key_func = tfm_plat_load_dm_host_key,
                .loader_key_ctx = dynamic_table_fill_ptr,
            };

            *dynamic_table_fill_ptr = desc;
            dynamic_table_fill_ptr++;
        }

        dynamic_table_set_up = true;
    }

    *desc_ptr = &dynamic_desc_table[0];
    return NUMBER_OF_ELEMENTS_OF(dynamic_desc_table);
}
