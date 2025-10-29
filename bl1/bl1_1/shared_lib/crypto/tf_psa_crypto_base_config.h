/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __BL1_1_TF_PSA_CRYPTO_CONFIG_H__
#define __BL1_1_TF_PSA_CRYPTO_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \name SECTION: SECTION Cryptographic mechanism selection (PSA API)
 *
 * This section sets PSA API settings.
 * \{
 */

#define PSA_WANT_ALG_SHA_384                    1
#define PSA_WANT_ALG_SHA_512                    1

/** \} name SECTION Cryptographic mechanism selection (PSA API) */

/**
 * \name SECTION: Cryptographic mechanism selection (extended API)
 *
 * This section sets cryptographic mechanism settings.
 * \{
 */

#ifdef TFM_BL1_2_ENABLE_LMS
#define MBEDTLS_LMS_C
#endif /* TFM_BL1_2_ENABLE_LMS */

/** \} name SECTION: Cryptographic mechanism selection (extended API) */

/**
 * \name SECTION: PSA core
 *
 * This section sets PSA specific settings.
 * \{
 */

#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

/** \} name SECTION: PSA core */

#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#ifdef __cplusplus
}
#endif

#endif /* __BL1_1_TF_PSA_CRYPTO_CONFIG_H__ */
