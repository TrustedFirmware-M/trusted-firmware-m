/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CRYPTO_CONFIG_EXTRA_NV_SEED_H__
#define __CRYPTO_CONFIG_EXTRA_NV_SEED_H__

#ifndef PLATFORM_DEFAULT_NV_SEED

#include "tfm_plat_crypto_nv_seed.h"

/* Use NV seed file-based entropy source */
#ifndef MBEDTLS_ENTROPY_NV_SEED
#define MBEDTLS_ENTROPY_NV_SEED
#endif /* !MBEDTLS_ENTROPY_NV_SEED */

/* Confirm the previous choice and the acceptance of its disadvantages */
#ifndef MBEDTLS_ENTROPY_NO_SOURCES_OK
#define MBEDTLS_ENTROPY_NO_SOURCES_OK
#endif /* !MBEDTLS_ENTROPY_NO_SOURCES_OK */

#ifndef MBEDTLS_PLATFORM_NV_SEED_READ_MACRO
#define MBEDTLS_PLATFORM_NV_SEED_READ_MACRO   tfm_plat_crypto_nv_seed_read /**< Default nv_seed_read function to use, can be undefined */
#endif /* !MBEDTLS_PLATFORM_NV_SEED_READ_MACRO */

#ifndef MBEDTLS_PLATFORM_NV_SEED_WRITE_MACRO
#define MBEDTLS_PLATFORM_NV_SEED_WRITE_MACRO  tfm_plat_crypto_nv_seed_write /**< Default nv_seed_write function to use, can be undefined */
#endif /* !MBEDTLS_PLATFORM_NV_SEED_WRITE_MACRO */

#endif /* !defined(PLATFORM_DEFAULT_NV_SEED) */

#endif /* __CRYPTO_CONFIG_EXTRA_NV_SEED_H__ */
