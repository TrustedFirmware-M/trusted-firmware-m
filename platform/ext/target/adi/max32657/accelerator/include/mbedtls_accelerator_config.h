/*
 * Copyright (c) 2025 Analog Devices, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __MBEDTLS_ACCELERATOR_CONF_H__
#define __MBEDTLS_ACCELERATOR_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* RNG Config */
#undef MBEDTLS_ENTROPY_NV_SEED
#undef MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MBEDTLS_ACCELERATOR_CONF_H__ */
