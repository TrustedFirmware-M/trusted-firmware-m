/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_BL2_H__
#define __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_BL2_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* When using the PSA Unified driver API, this is the only define that has to be added
 * to the ones being available in the non-platform aware config files being used, i.e.
 * just make sure that that the Crypto core and driver wrappers are aware of the driver
 */
#define PSA_CRYPTO_DRIVER_CC3XX

/* As CC3XX has HW P256 acceleration for signature verification, we can just disable the
 * P256M software driver if it is being enabled in the BL2 config.
 */
#if defined(MBEDTLS_PSA_P256M_DRIVER_ENABLED)
#undef MBEDTLS_PSA_P256M_DRIVER_ENABLED
#endif

/****************************************************************/
/* Require built-in implementations based on PSA requirements */
/****************************************************************/

#define PSA_WANT_KEY_TYPE_AES                   1

/* The CC312 does not support CFB mode */
#ifdef PSA_WANT_ALG_CFB
#undef PSA_WANT_ALG_CFB
#endif /* PSA_WANT_ALG_CFB */

#ifdef LEGACY_DRIVER_API_ENABLED

#ifdef PSA_WANT_KEY_TYPE_AES
#define MBEDTLS_AES_ALT
#define MBEDTLS_AES_SETKEY_ENC_ALT
#define MBEDTLS_AES_SETKEY_DEC_ALT
#define MBEDTLS_AES_ENCRYPT_ALT
#define MBEDTLS_AES_DECRYPT_ALT
#endif /* PSA_WANT_KEY_TYPE_AES */

#ifdef PSA_WANT_KEY_TYPE_ARIA
#define MBEDTLS_ARIA_ALT
#endif /* PSA_WANT_KEY_TYPE_ARIA */

#ifdef PSA_WANT_ALG_CCM
#define MBEDTLS_CCM_ALT
#endif /* PSA_WANT_ALG_CCM */

#ifdef PSA_WANT_KEY_TYPE_CHACHA20
#define MBEDTLS_CHACHA20_ALT
#ifdef PSA_WANT_ALG_CHACHA20_POLY1305
#define MBEDTLS_CHACHAPOLY_ALT
#endif /* PSA_WANT_ALG_CHACHA20_POLY1305 */
#endif /* PSA_WANT_KEY_TYPE_CHACHA20 */

#ifdef PSA_WANT_ALG_CMAC
#define MBEDTLS_CMAC_ALT
#endif /* PSA_WANT_ALG_CMAC */

#ifdef PSA_WANT_ALG_ECDH
#define MBEDTLS_ECDH_GEN_PUBLIC_ALT
#define MBEDTLS_ECDH_COMPUTE_SHARED_ALT
#endif /* PSA_WANT_ALG_ECDH */

#ifdef PSA_WANT_ALG_ECDSA
#define MBEDTLS_ECDSA_VERIFY_ALT
#define MBEDTLS_ECDSA_SIGN_ALT

#ifndef CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING
#define MBEDTLS_ECDSA_GENKEY_ALT
#endif
#endif /* PSA_WANT_ALG_ECDSA */

#ifdef PSA_WANT_ALG_GCM
#define MBEDTLS_GCM_ALT
#endif /* PSA_WANT_ALG_GCM */

#ifdef PSA_WANT_ALG_SHA_1
#define MBEDTLS_SHA1_ALT
#define MBEDTLS_SHA1_PROCESS_ALT
#endif /* PSA_WANT_ALG_SHA_1 */

#ifdef PSA_WANT_ALG_SHA_256
#define MBEDTLS_SHA256_ALT
#define MBEDTLS_SHA256_PROCESS_ALT
#else
#endif /* PSA_WANT_ALG_SHA_256 */

#else /* LEGACY_DRIVER_API_ENABLED */

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
#define MBEDTLS_GCM_C
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

#endif /* LEGACY_DRIVER_API_ENABLED */

#if defined(PSA_WANT_ALG_RSA_OAEP)                 ||     \
    defined(PSA_WANT_ALG_RSA_PKCS1V15_CRYPT)       ||     \
    defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN)        ||     \
    defined(PSA_WANT_ALG_RSA_PSS)                  ||     \
    defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC)  ||     \
    defined(PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY)
#ifdef LEGACY_DRIVER_API_ENABLED
#define MBEDTLS_RSA_ALT
#define MBEDTLS_PK_RSA_ALT_SUPPORT
#endif /* LEGACY_DRIVER_API_ENABLED */
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE     1
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_BL2_H__ */
