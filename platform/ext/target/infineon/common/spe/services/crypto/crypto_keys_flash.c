/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_utils.h"
#include "crypto_keys_flash.h"
#include "psa_manifest/pid.h"
#include "tfm_builtin_key_ids.h"
#include "tfm_builtin_key_loader.h"
#include "tfm_plat_crypto_keys.h"
#include "ifx_spe_config.h"

#include <string.h>
#include <stdbool.h>

#ifdef TEST_NS_ATTESTATION
#define MAPPED_TZ_NS_AGENT_DEFAULT_CLIENT_ID 0xaaaa7fffU
#define IFX_IAK_TEST_NS_PARTITION_ID         MAPPED_TZ_NS_AGENT_DEFAULT_CLIENT_ID
#endif /* TEST_NS_ATTESTATION */

static inline bool ifx_is_key_empty(const uint8_t *key_data, size_t key_len) {
    uint8_t sum = 0;
    for (size_t i = 0; i < key_len; ++i) {
        sum |= key_data[i];
    }
    return (sum == 0u);
}

static enum tfm_plat_err_t ifx_plat_get_huk(const void *ctx,
                                            uint8_t *buf, size_t buf_len,
                                            size_t *key_len,
                                            psa_key_bits_t *key_bits,
                                            psa_algorithm_t *algorithm,
                                            psa_key_type_t *type)
{
    size_t key_size = sizeof(IFX_CRYPTO_KEYS_PTR->huk);
    (void)ctx;

    if (buf_len < key_size) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Perform minimal check for empty (zero) key as empty key is not valid.
     * Empty key indicates that key was not provisioned. */
    if (ifx_is_key_empty(IFX_CRYPTO_KEYS_PTR->huk, key_size)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    (void)memcpy(buf, IFX_CRYPTO_KEYS_PTR->huk, key_size);

    *key_bits = IFX_CRYPTO_KEYS_HUK_KEY_BITS;
    *key_len = IFX_CRYPTO_KEYS_HUK_KEY_LEN;
    *algorithm = IFX_CRYPTO_KEYS_HUK_ALGORITHM;
    *type = IFX_CRYPTO_KEYS_HUK_TYPE;

    return TFM_PLAT_ERR_SUCCESS;
}

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
static enum tfm_plat_err_t ifx_plat_get_iak(const void *ctx,
                                            uint8_t *buf, size_t buf_len,
                                            size_t *key_len,
                                            psa_key_bits_t *key_bits,
                                            psa_algorithm_t *algorithm,
                                            psa_key_type_t *type)
{
    size_t key_size = sizeof(IFX_CRYPTO_KEYS_PTR->iak);
    (void)ctx;

    if (buf_len < key_size) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Perform minimal check for empty (zero) key as empty key is not valid.
     * Empty key indicates that key was not provisioned. */
    if (ifx_is_key_empty(IFX_CRYPTO_KEYS_PTR->iak, key_size)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    (void)memcpy(buf, IFX_CRYPTO_KEYS_PTR->iak, key_size);

#if IFX_MULTIPLE_IAK_KEY_TYPES
    /* Check if key type is correct */
    if (IFX_CRYPTO_KEYS_IAK_IS_VALID(IFX_CRYPTO_KEYS_PTR->iak_key_type) == false) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
    *key_bits = IFX_CRYPTO_KEYS_IAK_KEY_BITS_BY_TYPE(IFX_CRYPTO_KEYS_PTR->iak_key_type);
    *key_len = IFX_CRYPTO_KEYS_IAK_KEY_LEN_BY_TYPE(IFX_CRYPTO_KEYS_PTR->iak_key_type);
    *algorithm = IFX_CRYPTO_KEYS_IAK_ALGORITHM_BY_TYPE(IFX_CRYPTO_KEYS_PTR->iak_key_type);
    *type = IFX_CRYPTO_KEYS_IAK_TYPE_BY_TYPE(IFX_CRYPTO_KEYS_PTR->iak_key_type);
#else /* IFX_MULTIPLE_IAK_KEY_TYPES */
    *key_bits = IFX_CRYPTO_KEYS_IAK_KEY_BITS;
    *key_len = IFX_CRYPTO_KEYS_IAK_KEY_LEN;
    *algorithm = IFX_CRYPTO_KEYS_IAK_ALGORITHM;
    *type = IFX_CRYPTO_KEYS_IAK_TYPE;
#endif /* IFX_MULTIPLE_IAK_KEY_TYPES */

    return TFM_PLAT_ERR_SUCCESS;
}

/**
 * @brief Table describing per-user key policy for the IAK
 *
 */
static const tfm_plat_builtin_key_per_user_policy_t g_iak_per_user_policy[] = {
#ifdef SYMMETRIC_INITIAL_ATTESTATION
    { .user = TFM_SP_INITIAL_ATTESTATION,
      .usage = PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_EXPORT },
#else
    { .user = TFM_SP_INITIAL_ATTESTATION, .usage = PSA_KEY_USAGE_SIGN_HASH },
#endif /* SYMMETRIC_INITIAL_ATTESTATION */
#ifdef TEST_S_ATTESTATION
    { .user = TFM_SP_SECURE_TEST_PARTITION, .usage = PSA_KEY_USAGE_VERIFY_HASH },
#endif /* TEST_S_ATTESTATION */
#ifdef TEST_NS_ATTESTATION
    { .user = IFX_IAK_TEST_NS_PARTITION_ID, .usage = PSA_KEY_USAGE_VERIFY_HASH },
#endif /* TEST_NS_ATTESTATION */
};
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */

/**
 * @brief Table describing per-key user policies
 *
 */
static const tfm_plat_builtin_key_policy_t g_builtin_keys_policy[] = {
    { .key_id = (uint32_t)TFM_BUILTIN_KEY_ID_HUK,
      .per_user_policy = 0,
      .usage = PSA_KEY_USAGE_DERIVE },
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
    { .key_id = (uint32_t)TFM_BUILTIN_KEY_ID_IAK,
      .per_user_policy = ARRAY_SIZE(g_iak_per_user_policy),
      .policy_ptr = g_iak_per_user_policy }
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
};

/**
 * @brief Table describing the builtin-in keys (platform keys) available in the platform. Note
 *        that to bind the keys to the tfm_builtin_key_loader driver, the lifetime must be
 *        explicitly set to the one associated to the driver, i.e. TFM_BUILTIN_KEY_LOADER_LIFETIME
 */
static const tfm_plat_builtin_key_descriptor_t g_builtin_keys_desc[] = {
    { .key_id = (uint32_t)TFM_BUILTIN_KEY_ID_HUK,
      .slot_number = (psa_drv_slot_number_t)TFM_BUILTIN_KEY_SLOT_HUK,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
      .loader_key_func = ifx_plat_get_huk,
      .loader_key_ctx = NULL,
    },
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
    { .key_id = (uint32_t)TFM_BUILTIN_KEY_ID_IAK,
      .slot_number = (psa_drv_slot_number_t)TFM_BUILTIN_KEY_SLOT_IAK,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
      .loader_key_func = ifx_plat_get_iak,
      .loader_key_ctx = NULL,
    },
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
};

size_t tfm_plat_builtin_key_get_policy_table_ptr(const tfm_plat_builtin_key_policy_t *desc_ptr[])
{
    *desc_ptr = &g_builtin_keys_policy[0];
    return ARRAY_SIZE(g_builtin_keys_policy);
}

size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[])
{
    *desc_ptr = &g_builtin_keys_desc[0];
    return ARRAY_SIZE(g_builtin_keys_desc);
}
