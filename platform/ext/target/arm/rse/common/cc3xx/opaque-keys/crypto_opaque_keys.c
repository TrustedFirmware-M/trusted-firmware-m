/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "cc3xx_opaque_keys.h"
#include "crypto_opaque_key_ids.h"
#include "kmu_drv.h"
#include "psa/crypto.h"

/* KMU keys are 256-bit long */
#define OPAQUE_KEY_SIZE ((size_t)32)

/**
 * @brief           Return the corresponding key size of the corresponding
 *                  opaque key.
 *
 * @param key_id    Opaque key ID.
 * @return size_t   The opaque key ID size in bytes.
 */
inline size_t cc3xx_get_key_buffer_size(psa_key_id_t key_id) {
    return OPAQUE_KEY_SIZE;
}

/**
 * @brief           translate they key id of an opaque key to its corresponding
 *                  HW key ID. The latter makes sense to actual consumer of
 *                  they key.
 *
 * @param[in] key_id    The opaque key ID.
 * @return size_t       The HW key slot ID.
 */
inline size_t cc3xx_get_builtin_key(psa_key_id_t key_id) {
    switch (key_id) {
        case PSA_OPAQUE_KEY_ID_KRTL:
            return KMU_HW_SLOT_KRTL;

        case PSA_OPAQUE_KEY_ID_HUK:
            return KMU_HW_SLOT_HUK;

        case PSA_OPAQUE_KEY_ID_GUK:
            return KMU_HW_SLOT_GUK;

        case PSA_OPAQUE_KEY_ID_KP_CM:
            return KMU_HW_SLOT_KP_CM;

        case PSA_OPAQUE_KEY_ID_KCE_CM:
            return KMU_HW_SLOT_KCE_CM;

        case PSA_OPAQUE_KEY_ID_KP_DM:
            return KMU_HW_SLOT_KP_DM;

        case PSA_OPAQUE_KEY_ID_KCE_DM:
            return KMU_HW_SLOT_KCE_DM;
    }

    if ((key_id >= PSA_OPAQUE_KEY_ID_USER_SLOT_MIN) && (key_id <= PSA_OPAQUE_KEY_ID_USER_SLOT_MAX)) {
        return KMU_USER_SLOT_MIN + (key_id - PSA_OPAQUE_KEY_ID_USER_SLOT_MIN);
    }

    return CC3XX_OPAQUE_KEY_ID_INVALID;
}

/**
 * @brief           translate they key id of a HW key to its corresponding
 *                  Opaque key ID.
 *
 * @param[in] key_id    The HW key slot ID.
 * @return size_t       The opaque key ID.
 */
inline size_t cc3xx_get_opaque_key(size_t key_id) {
    switch (key_id) {
        case KMU_HW_SLOT_KRTL:
            return PSA_OPAQUE_KEY_ID_KRTL;

        case KMU_HW_SLOT_HUK:
            return PSA_OPAQUE_KEY_ID_HUK;

        case KMU_HW_SLOT_GUK :
            return PSA_OPAQUE_KEY_ID_GUK;

        case KMU_HW_SLOT_KP_CM :
            return PSA_OPAQUE_KEY_ID_KP_CM;

        case KMU_HW_SLOT_KCE_CM :
            return PSA_OPAQUE_KEY_ID_KCE_CM;

        case KMU_HW_SLOT_KP_DM :
            return PSA_OPAQUE_KEY_ID_KP_DM;

        case KMU_HW_SLOT_KCE_DM :
            return PSA_OPAQUE_KEY_ID_KCE_DM;
    }

    if ((key_id >= KMU_USER_SLOT_MIN ) && (key_id <= KMU_USER_SLOT_MAX)) {
        return  PSA_OPAQUE_KEY_ID_USER_SLOT_MIN + (key_id - KMU_USER_SLOT_MIN);
    }

    return CC3XX_OPAQUE_KEY_ID_INVALID;
}

psa_status_t cc3xx_opaque_keys_attr_init(psa_key_attributes_t *attributes,
                                             psa_key_id_t key_id,
                                             psa_algorithm_t alg,
                                             const uint8_t **key_buffer,
                                             size_t *key_buffer_size)
{
#if !defined(MBEDTLS_PSA_CRYPTO_KEY_ID_ENCODES_OWNER)

    size_t key_size = cc3xx_get_key_buffer_size(key_id);
    psa_key_type_t key_type;

    psa_set_key_lifetime(attributes, CC3XX_OPAQUE_KEY_LIFETIME);
    psa_set_key_bits(attributes, PSA_BYTES_TO_BITS(key_size));
    psa_set_key_id(attributes, key_id);

    switch (alg) {
        case PSA_ALG_CTR:
        case PSA_ALG_CCM:
        case PSA_ALG_CMAC:
        case PSA_ALG_ECB_NO_PADDING:
            key_type = PSA_KEY_TYPE_AES;
            break;
        default:
            return PSA_ERROR_NOT_SUPPORTED;
    }

    psa_set_key_type(attributes, key_type);

    *key_buffer = (const uint8_t*)key_id;
    *key_buffer_size = key_size;

    return PSA_SUCCESS;
#else
    return PSA_ERROR_NOT_SUPPORTED;
#endif
}
