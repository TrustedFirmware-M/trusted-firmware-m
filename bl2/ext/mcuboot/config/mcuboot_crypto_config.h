/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file mcuboot/config/mcuboot_crypto_config.h
 * \brief PSA crypto configuration options (set of defines)
 *
 */
/**
 * This file determines which cryptographic mechanisms are enabled
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

#ifndef __MCUBOOT_CRYPTO_CONFIG_H__
#define __MCUBOOT_CRYPTO_CONFIG_H__

/**
 * \name SECTION: SECTION Cryptographic mechanism selection (PSA API)
 *
 * This section sets PSA API settings.
 * \{
 */

/* Hashing algorithms */
#if defined(MCUBOOT_SIGN_EC384)
/* When the image is signed with EC-P384 the image hash
 * is calculated using SHA-384
 */
#define PSA_WANT_ALG_SHA_384                1
#else
/* All the other supported signing algorithms use SHA-256 to compute the image hash */
#define PSA_WANT_ALG_SHA_256                1
#endif

/* Signature verification algorithms */
#if defined(MCUBOOT_SIGN_RSA)
#define PSA_WANT_ALG_RSA_PSS                1
#else
#define PSA_WANT_ALG_ECDSA                  1
/* Curves supported for ECDSA */
#if defined(MCUBOOT_SIGN_EC384)
#define PSA_WANT_ECC_SECP_R1_384            1
#else
#define PSA_WANT_ECC_SECP_R1_256            1
#endif /* MCUBOOT_SIGN_EC384 */
#endif /* MCUBOOT_SIGN_RSA */

/* Key types supported */
#if defined(MCUBOOT_SIGN_RSA)
#define PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY    1
#else
#define PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY    1
#endif

#define PSA_WANT_ALG_ECB_NO_PADDING         1
#define PSA_WANT_ALG_CTR                    1       /* TODO: condition? */

#if defined(MCUBOOT_ENC_IMAGES)
#define PSA_WANT_ALG_CTR                    1
#define PSA_WANT_KEY_TYPE_AES               1
#endif

#ifdef CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING
#define PSA_WANT_ALG_CCM
#define PSA_WANT_ECC_SECP_R1_256
#define PSA_WANT_ECC_MONTGOMERY_255
#endif /* CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING */

/** \} name SECTION Cryptographic mechanism selection (PSA API) */

/**
 * \name SECTION: Platform abstraction layer
 *
 * This section sets platform specific settings.
 * \{
 */

/* System support */
#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C
#define MBEDTLS_PLATFORM_EXIT_ALT
#define MBEDTLS_PLATFORM_PRINTF_ALT

/** \} name SECTION: Platform abstraction layer */

/**
 * \name SECTION: Cryptographic mechanism selection (extended API)
 *
 * This section sets cryptographic mechanism settings.
 * \{
 */

#define MBEDTLS_MD_C
#define MBEDTLS_NIST_KW_C

 /** \} name SECTION: Cryptographic mechanism selection (extended API) */

/**
 * \name SECTION: Data format support
 *
 * This section sets data-format specific settings.
 * \{
 */

#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_ASN1_WRITE_C

 /** \} name SECTION: Data format support */

/**
 * \name SECTION: PSA core
 *
 * This section sets PSA specific settings.
 * \{
 */

/* Enable PSA Crypto Core without support for the permanent storage
 * Don't define MBEDTLS_PSA_CRYPTO_STORAGE_C to make sure that support
 * for permanent keys is not enabled, as it is not available during boot
 */
#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

/** \} name SECTION: PSA core */

/**
 * \name SECTION: Builtin drivers
 *
 * This section sets driver specific settings.
 * \{
 */

#if defined(MCUBOOT_SIGN_EC256)
#define MBEDTLS_PSA_P256M_DRIVER_ENABLED
#endif

#if defined(MCUBOOT_SIGN_EC256) || defined(MCUBOOT_SIGN_EC384)
#define MBEDTLS_ECP_NIST_OPTIM
#endif

#if defined(MCUBOOT_SIGN_RSA)
/* Save RAM by adjusting to our exact needs */
#if MCUBOOT_SIGN_RSA_LEN == 3072
#define MBEDTLS_MPI_MAX_SIZE 384
#else /* RSA2048 */
#define MBEDTLS_MPI_MAX_SIZE 256
#endif
#endif /* MCUBOOT_SIGN_RSA */

#if defined(MCUBOOT_ENC_IMAGES)
#define MBEDTLS_AES_FEWER_TABLES
#endif

 /** \} name SECTION: Builtin drivers */

/**
 * \name SECTION: Legacy cryptography
 *
 * This section sets legacy settings.
 * \{
 */

/** \} name SECTION: Legacy cryptography */

#ifdef MCUBOOT_IMAGE_BINDING
#ifdef MCUBOOT_ENC_IMAGES
#define PSA_WANT_ALG_CCM
#else
#define PSA_WANT_ALG_CMAC
#endif /* MCUBOOT_ENC_IMAGES */
#endif /* MCUBOOT_IMAGE_BINDING */

#ifdef CRYPTO_HW_ACCELERATOR
#ifdef TF_PSA_CRYPTO_ACCELERATOR_CONFIG_FILE
#include TF_PSA_CRYPTO_ACCELERATOR_CONFIG_FILE
#endif
#endif /* CRYPTO_HW_ACCELERATOR */

#define PSA_CRYPTO_OPAQUE_KEYS

#endif /* __MCUBOOT_CRYPTO_CONFIG_H__ */
