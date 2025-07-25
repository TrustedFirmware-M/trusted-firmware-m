/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef BL1_2_PQ_CRYPTO_H
#define BL1_2_PQ_CRYPTO_H

#include <stddef.h>
#include <stdint.h>
#include "crypto_key_defs.h"
#include "fih.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Verify signature using the LMS stateful-hash post-quantum crypto algorithm as
 * per IETF RFC8554 and NIST SP800-208.
 */
fih_ret pq_crypto_verify(uint8_t *key, size_t key_size,
                         const uint8_t *data,
                         size_t data_length,
                         const uint8_t *signature,
                         size_t signature_length);

/* Get the hash of the public key */
int pq_crypto_get_pub_key_hash(enum tfm_bl1_key_id_t key,
                               uint8_t *hash,
                               size_t hash_size,
                               size_t *hash_length);

#ifdef __cplusplus
}
#endif

#endif /* BL1_2_PQ_CRYPTO_H */
