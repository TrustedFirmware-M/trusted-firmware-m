/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_OPAQUE_KEYS_H
#define __CC3XX_OPAQUE_KEYS_H

#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include "psa/crypto_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief The PSA driver location for builtin keys. Arbitrary within the
 *        ranges documented at
 *        https://armmbed.github.io/mbed-crypto/html/api/keys/lifetimes.html#c.psa_key_location_t
 */
#define CC3XX_OPAQUE_KEY_LOCATION ((psa_key_location_t)0x800002)

#define CC3XX_OPAQUE_KEY_LIFETIME PSA_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(\
                                         PSA_KEY_LIFETIME_PERSISTENT, CC3XX_OPAQUE_KEY_LOCATION)

#define CC3XX_OPAQUE_KEY_ID_INVALID ((psa_key_id_t) UINT_MAX)

/* Return true if the key is opaque, false otherwise */
#define CC3XX_IS_OPAQUE_KEY(key_attr) (psa_get_key_lifetime(key_attr) == CC3XX_OPAQUE_KEY_LIFETIME)

/* Return true of the opaque key is invalid */
#define CC3XX_IS_OPAQUE_KEY_INVALID(key_id) ((psa_key_id_t)(key_id) == CC3XX_OPAQUE_KEY_ID_INVALID)

/**
 * @brief           Return the corresponding key size of the corresponding
 *                  opaque key.
 *
 * @param key_id    Opaque key ID.
 * @return size_t   The opaque key ID size in bytes.
 */
size_t cc3xx_get_key_buffer_size(psa_key_id_t key_id);

/**
 * @brief               translate the key id of an opaque key to its corresponding
 *                      HW key ID.
 *
 * @param[in] key_id    The PSA opaque key ID.
 * @return size_t       The HW key slot ID.
 */
size_t cc3xx_get_builtin_key(psa_key_id_t key_id);

/**
 * @brief               translate the key id of a HW key to its corresponding
 *                      PSA opaque key ID.
 *
 * @param[in] key_id    The HW key slot ID.
 * @return size_t       The opaque key ID.
 */
size_t cc3xx_get_opaque_key(size_t key_id);

/**
 * @brief                          Initialize the key attributes of an opaque key.
 *
 * @param[in,out] attributes       Key attributes to initialize.
 * @param[in]     key_id           Opaque key ID.
 * @param[in]     alg              PSA Alg, used to set the key type.
 * @param[out]    key_buffer       key buffer which stores the opaque key ID.
 * @param[out]    key_buffer_size  Key buffer size.
 * @return psa_status_t
 */
psa_status_t cc3xx_opaque_keys_attr_init(psa_key_attributes_t *attributes,
                                             psa_key_id_t key_id,
                                             psa_algorithm_t alg,
                                             const uint8_t **key_buffer,
                                             size_t *key_buffer_size);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CC3XX_OPAQUE_KEYS_H */
