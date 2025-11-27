/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CRYPTO_KEYS_RRAM_H
#define CRYPTO_KEYS_RRAM_H

#include <stdint.h>

typedef struct {
    uint8_t iak_private[32];            /* PSA_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(256) */
    uint8_t iak_private_checksum[4];    /* CRC32 */
    uint8_t iak_public[65];             /* PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(256) */
    uint8_t iak_public_checksum[4];     /* CRC32 */
    uint8_t huk[32];                    /* PSA_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(256) */
    uint8_t huk_checksum[4];            /* CRC32 */
} ifx_plat_epc2_keys_t;

#define IFX_CRYPTO_KEYS_PTR                   ((ifx_plat_epc2_keys_t *)0x1200132EU)

#define IFX_CRYPTO_KEYS_HUK_KEY_BITS          (256)
#define IFX_CRYPTO_KEYS_HUK_KEY_LEN           (PSA_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(256U))
#define IFX_CRYPTO_KEYS_HUK_ALGORITHM         (PSA_ALG_HKDF(PSA_ALG_SHA_256))
#define IFX_CRYPTO_KEYS_HUK_TYPE              (PSA_KEY_TYPE_DERIVE)

#define IFX_CRYPTO_KEYS_IAK_PRIVATE_KEY_BITS  (256)
#define IFX_CRYPTO_KEYS_IAK_PRIVATE_KEY_LEN   (PSA_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(256U))
#define IFX_CRYPTO_KEYS_IAK_PRIVATE_ALGORITHM (PSA_ALG_ECDSA(PSA_ALG_SHA_256))
#define IFX_CRYPTO_KEYS_IAK_PRIVATE_TYPE      (PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1))

#define IFX_CRYPTO_KEYS_IAK_PUBLIC_KEY_BITS   (256)
#define IFX_CRYPTO_KEYS_IAK_PUBLIC_KEY_LEN    (PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(256U))
#define IFX_CRYPTO_KEYS_IAK_PUBLIC_ALGORITHM  (PSA_ALG_ECDSA(PSA_ALG_SHA_256))
#define IFX_CRYPTO_KEYS_IAK_PUBLIC_TYPE       (PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1))

#endif /* CRYPTO_KEYS_RRAM_H */
