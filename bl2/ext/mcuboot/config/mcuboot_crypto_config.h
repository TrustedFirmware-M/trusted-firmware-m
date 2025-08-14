/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/**
 * \file psa/crypto_config.h
 * \brief PSA crypto configuration options (set of defines)
 *
 */
#if defined(MBEDTLS_PSA_CRYPTO_CONFIG)
/**
 * When #MBEDTLS_PSA_CRYPTO_CONFIG is enabled in mbedtls_config.h,
 * this file determines which cryptographic mechanisms are enabled
 * through the PSA Cryptography API (\c psa_xxx() functions).
 *
 * To enable a cryptographic mechanism, uncomment the definition of
 * the corresponding \c PSA_WANT_xxx preprocessor symbol.
 * To disable a cryptographic mechanism, comment out the definition of
 * the corresponding \c PSA_WANT_xxx preprocessor symbol.
 * The names of cryptographic mechanisms correspond to values
 * defined in psa/crypto_values.h, with the prefix \c PSA_WANT_ instead
 * of \c PSA_.
 *
 * Note that many cryptographic mechanisms involve two symbols: one for
 * the key type (\c PSA_WANT_KEY_TYPE_xxx) and one for the algorithm
 * (\c PSA_WANT_ALG_xxx). Mechanisms with additional parameters may involve
 * additional symbols.
 */
#else
/**
 * When \c MBEDTLS_PSA_CRYPTO_CONFIG is disabled in mbedtls_config.h,
 * this file is not used, and cryptographic mechanisms are supported
 * through the PSA API if and only if they are supported through the
 * mbedtls_xxx API.
 */
#endif

#ifndef MCUBOOT_CRYPTO_CONFIG_H
#define MCUBOOT_CRYPTO_CONFIG_H

/* Hashing algorithms */
#if defined(MCUBOOT_SIGN_EC384)
#define PSA_WANT_ALG_SHA_384                    1
#else
#define PSA_WANT_ALG_SHA_256                    1
#endif

/* Signature verification algorithms */
#if defined(MCUBOOT_SIGN_RSA)
#define PSA_WANT_ALG_RSA_PSS                    1
#else
#define PSA_WANT_ALG_ECDSA                      1
/* Curves supported for ECDSA */
#if defined(MCUBOOT_SIGN_EC384)
#define PSA_WANT_ECC_SECP_R1_384                1
#else
#define PSA_WANT_ECC_SECP_R1_256                1
#endif
#endif

/* Key types supported */
#if defined(MCUBOOT_SIGN_RSA)
#define PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY        1
#else
#define PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY        1
#endif

#define PSA_WANT_ALG_ECB_NO_PADDING
#define PSA_WANT_ALG_CTR

#ifdef CRYPTO_HW_ACCELERATOR
#include MBEDTLS_ACCELERATOR_PSA_CRYPTO_CONFIG_FILE
#endif

#define PSA_CRYPTO_OPAQUE_KEYS
#endif /* MCUBOOT_CRYPTO_CONFIG_H */
