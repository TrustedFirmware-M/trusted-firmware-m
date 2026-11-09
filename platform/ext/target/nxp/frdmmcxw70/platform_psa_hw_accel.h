/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PLATFORM_PSA_HW_ACCEL_H
#define PLATFORM_PSA_HW_ACCEL_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/***********************************************************************/
/* Override built-in implementations based on Platform HW capabilities */
/***********************************************************************/

/* We have explicitly disabled this Algorithm on top of Medium profile to reduce memory footprint*/
#if defined(PSA_WANT_ALG_SHA_224)
#undef PSA_WANT_ALG_SHA_224
#endif

#if defined(PSA_WANT_ALG_SHA_256)
#define MBEDTLS_PSA_ACCEL_ALG_SHA_256 1
#endif

#if defined(PSA_WANT_ALG_SHA_384)
#define MBEDTLS_PSA_ACCEL_ALG_SHA_384 1
#endif

#if defined(PSA_WANT_ALG_SHA_512)
#define MBEDTLS_PSA_ACCEL_ALG_SHA_512 1
#endif

#if defined(PSA_WANT_KEY_TYPE_AES)
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_AES 1
#endif

#if defined(PSA_WANT_ALG_GCM)
#define MBEDTLS_PSA_ACCEL_ALG_GCM 1
#endif

#if defined(PSA_WANT_ALG_CCM)
#define MBEDTLS_PSA_ACCEL_ALG_CCM 1
#endif

#if defined(PSA_WANT_ALG_CMAC)
#define MBEDTLS_PSA_ACCEL_ALG_CMAC 1
#endif

#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
#define MBEDTLS_PSA_ACCEL_ALG_CBC_NO_PADDING 1
#endif

#if defined(PSA_WANT_ALG_CTR)
#define MBEDTLS_PSA_ACCEL_ALG_CTR 1
#endif

#if defined(PSA_WANT_ALG_CBC_PKCS7)
 #define MBEDTLS_PSA_ACCEL_ALG_CBC_PKCS7 1
#endif

#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
 #define MBEDTLS_PSA_ACCEL_ALG_ECB_NO_PADDING 1
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PLATFORM_PSA_HW_ACCEL_H */