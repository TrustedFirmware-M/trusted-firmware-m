/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TF_PSA_CRYPTO_EXTRA_CONFIG_H__
#define __TF_PSA_CRYPTO_EXTRA_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define PSA_WANT_ALG_CTR                        1
#define PSA_WANT_ALG_SHA_256                    1
#define PSA_WANT_ALG_SP800_108_COUNTER_CMAC     1
#define PSA_WANT_KEY_TYPE_AES                   1

#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C
#define MBEDTLS_HMAC_DRBG_C
#define MBEDTLS_MD_C

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TF_PSA_CRYPTO_EXTRA_CONFIG_H__ */
