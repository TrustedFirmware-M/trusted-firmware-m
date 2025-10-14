
/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MPS4_MBEDCRYPTO_CONFIG_H
#define MPS4_MBEDCRYPTO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C
#define MBEDTLS_HMAC_DRBG_C
#define MBEDTLS_MD_C
#define MBEDTLS_AES_C
#define MBEDTLS_HKDF_C
#define MBEDTLS_SHA256_C
#define MBEDTLS_CIPHER_MODE_CTR

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MPS4_MBEDCRYPTO_CONFIG_H */
