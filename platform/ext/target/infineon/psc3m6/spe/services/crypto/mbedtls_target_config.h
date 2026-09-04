/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MBEDTLS_TARGET_CONFIG_H
#define MBEDTLS_TARGET_CONFIG_H

#if defined(SYMMETRIC_INITIAL_ATTESTATION) || defined(IFX_CRYPTOSUITE_ENABLED)
/* CMAC and AES key type are required for symmetric attestation or the cryptosuite */
#define PSA_WANT_ALG_CMAC 1
#define PSA_WANT_KEY_TYPE_AES 1
#endif /* SYMMETRIC_INITIAL_ATTESTATION || IFX_CRYPTOSUITE_ENABLED */

#ifdef IFX_CRYPTOSUITE_ENABLED

#define IFX_PSA_CRYPTOSUITE_PRESENT

#define PSA_WANT_ALG_ECB_NO_PADDING     1
#define PSA_WANT_ALG_CBC_NO_PADDING     1
#define PSA_WANT_ALG_CTR                1
#define PSA_WANT_ALG_CFB                1
#define PSA_WANT_ALG_CCM                1
#endif /* IFX_CRYPTOSUITE_ENABLED */

/* *** DO NOT CHANGE ANY SETTINGS IN THIS SECTION *** */

#if IFX_MBEDTLS_ACCELERATION_ENABLED
/* Enable CRYPTOLITE transparent driver */
#define IFX_PSA_CRYPTOLITE_PRESENT
#endif /* IFX_MBEDTLS_ACCELERATION_ENABLED */

/* Enable support for platform built-in keys */
#define MBEDTLS_PSA_CRYPTO_BUILTIN_KEYS

#ifdef IFX_MBEDTLS_CONFIG_PATH
/* Include project specific ifx-mbedtls configuration header */
#include IFX_MBEDTLS_CONFIG_PATH
#endif

#endif /* MBEDTLS_TARGET_CONFIG_H */
