/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#ifndef BL1_1_MBEDCRYPO_CONFIG_H
#define BL1_1_MBEDCRYPO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C

#define MBEDTLS_SHA256_C
#define MBEDTLS_SHA224_C
#define MBEDTLS_SHA512_C
#define MBEDTLS_SHA384_C

#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_LMS_C
#define MBEDTLS_LMOTS_C
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

#define MBEDTLS_AES_C
#define MBEDTLS_HKDF_C
#define MBEDTLS_MD_C
#define MBEDTLS_CIPHER_MODE_CTR

#if defined(CRYPTO_HW_ACCELERATOR) && defined(MBEDTLS_ACCELERATOR_CONFIG_FILE)
#include MBEDTLS_ACCELERATOR_CONFIG_FILE
#endif

#ifdef __cplusplus
}
#endif

#endif /* BL1_1_MBEDCRYPO_CONFIG_H */
