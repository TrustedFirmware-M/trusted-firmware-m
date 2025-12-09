/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__
#define __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(PLATFORM_PSA_ADAC_SECURE_DEBUG) && !defined(MCUBOOT_SIGN_RSA)
#define PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY        1
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG && !MCUBOOT_SIGN_RSA */

#define PSA_WANT_KEY_TYPE_AES                   1

/* The CC312 does not support CFB mode */
#ifdef PSA_WANT_ALG_CFB
#undef PSA_WANT_ALG_CFB
#endif /* PSA_WANT_ALG_CFB */

#ifdef USE_MBEDTLS_CRYPTOCELL
#define MBEDTLS_MD_C
#endif

/* RNG Config */
#undef MBEDTLS_ENTROPY_NV_SEED
#undef MBEDTLS_ENTROPY_NO_SOURCES_OK

#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_PSA_DRIVER_GET_ENTROPY

#ifndef MCUBOOT_SIGN_EC384
#define MBEDTLS_PSA_CRYPTO_RNG_HASH     PSA_ALG_SHA_256
#endif

#ifdef CC3XX_RUNTIME_ENABLED
/* CC3XX integrates the cc3xx_random entry point through this mechanism */
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG
#endif

/****************************************************************/
/* Require built-in implementations based on PSA requirements */
/****************************************************************/

#ifdef PSA_WANT_KEY_TYPE_AES
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_AES
#endif

#ifdef PSA_WANT_KEY_TYPE_CHACHA20
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_CHACHA20
#endif

#if defined(PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY) ||      \
    defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_BASIC) ||  \
    defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_IMPORT) || \
    defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_EXPORT)
    /* Mbed TLS core does not support partially accelerating
     * so we must make sure they are all marked accelerated
     */
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_PUBLIC_KEY
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_KEY_PAIR_BASIC
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_KEY_PAIR_IMPORT
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_KEY_PAIR_EXPORT
#endif

#ifdef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_RSA_KEY_PAIR_BASIC
#endif

#ifdef PSA_WANT_ALG_ECDH
#define MBEDTLS_PSA_ACCEL_ALG_ECDH
#endif

#ifdef PSA_WANT_ALG_ECDSA
#define MBEDTLS_PSA_ACCEL_ALG_ECDSA
#ifdef PSA_WANT_ECC_SECP_R1_256
#define MBEDTLS_PSA_ACCEL_ECC_SECP_R1_256
#endif
#ifdef PSA_WANT_ECC_SECP_R1_384
#define MBEDTLS_PSA_ACCEL_ECC_SECP_R1_384
#endif
#ifdef PSA_WANT_ECC_SECP_R1_521
#define MBEDTLS_PSA_ACCEL_ECC_SECP_R1_521
#endif
#endif /* PSA_WANT_ALG_ECDSA */

#ifdef PSA_WANT_ALG_DETERMINISTIC_ECDSA
#define MBEDTLS_PSA_ACCEL_ALG_DETERMINISTIC_ECDSA
#define MBEDTLS_HMAC_DRBG_C
#define MBEDTLS_MD_C
#endif /* PSA_WANT_ALG_DETERMINISTIC_ECDSA */

#ifdef PSA_WANT_ALG_CBC_NO_PADDING
#define MBEDTLS_PSA_ACCEL_ALG_CBC_NO_PADDING
#endif

#ifdef PSA_WANT_ALG_CBC_PKCS7
#define MBEDTLS_PSA_ACCEL_ALG_CBC_PKCS7
#endif

#ifdef PSA_WANT_ALG_ECB_NO_PADDING
#define MBEDTLS_PSA_ACCEL_ALG_ECB_NO_PADDING
#endif

#ifdef PSA_WANT_ALG_CTR
#define MBEDTLS_PSA_ACCEL_ALG_CTR
#endif

#ifdef PSA_WANT_ALG_OFB
#define MBEDTLS_PSA_ACCEL_ALG_OFB
#endif

#ifdef PSA_WANT_ALG_CCM
#define MBEDTLS_PSA_ACCEL_ALG_CCM
#endif

#ifdef PSA_WANT_ALG_GCM
#define MBEDTLS_PSA_ACCEL_ALG_GCM
#endif

#ifdef PSA_WANT_ALG_CMAC
#define MBEDTLS_PSA_ACCEL_ALG_CMAC
#endif

#ifdef PSA_WANT_ALG_HMAC
#define MBEDTLS_PSA_ACCEL_ALG_HMAC
#endif

#ifdef PSA_WANT_ALG_CHACHA20_POLY1305
#define MBEDTLS_PSA_ACCEL_ALG_CHACHA20_POLY1305
#endif

#ifdef PSA_WANT_ALG_SHA_1
#define MBEDTLS_PSA_ACCEL_ALG_SHA_1
#endif

#ifdef PSA_WANT_ALG_SHA_224
#define MBEDTLS_PSA_ACCEL_ALG_SHA_224
#endif

#ifdef PSA_WANT_ALG_SHA_256
#define MBEDTLS_PSA_ACCEL_ALG_SHA_256
#endif

#ifdef PSA_WANT_ALG_RSA_OAEP
#define MBEDTLS_PSA_ACCEL_ALG_RSA_OAEP
#endif

#ifdef PSA_WANT_ALG_RSA_PKCS1V15_CRYPT
#define MBEDTLS_PSA_ACCEL_ALG_RSA_PKCS1V15_CRYPT
#endif

#ifdef PSA_WANT_ALG_RSA_PKCS1V15_SIGN
#define MBEDTLS_PSA_ACCEL_ALG_RSA_PKCS1V15_SIGN
#endif

#ifdef PSA_WANT_ALG_RSA_PSS
#define MBEDTLS_PSA_ACCEL_ALG_RSA_PSS
#endif

#if defined(PSA_WANT_ALG_RSA_OAEP)                 ||     \
    defined(PSA_WANT_ALG_RSA_PKCS1V15_CRYPT)       ||     \
    defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN)        ||     \
    defined(PSA_WANT_ALG_RSA_PSS)                  ||     \
    defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC)  ||     \
    defined(PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY)
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE     1
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__ */
