/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PSA_CRYPTO_VALUES_LMS_H
#define PSA_CRYPTO_VALUES_LMS_H

#define PSA_ALG_LMS_BASE     0x00100000

#define PSA_ALG_IS_LMS(alg) (((alg) & ~PSA_ALG_HASH_MASK) == PSA_ALG_LMS_BASE)

#define PSA_ALG_LMS(hash) ( \
    PSA_ALG_VENDOR_FLAG | \
    PSA_ALG_CATEGORY_SIGN | \
    PSA_ALG_LMS_BASE | \
    ((hash) & PSA_ALG_HASH_MASK) \
    )

#define PSA_ALG_HSS_BASE     0x00200000

#define PSA_ALG_IS_HSS(alg) (((alg) & ~PSA_ALG_HASH_MASK) == PSA_ALG_HSS_BASE)

#define PSA_ALG_HSS(hash) ( \
    PSA_ALG_VENDOR_FLAG | \
    PSA_ALG_CATEGORY_SIGN | \
    PSA_ALG_HSS_BASE | \
    ((hash) & PSA_ALG_HASH_MASK) \
    )

#endif /* PSA_CRYPTO_VALUES_LMS_H */
