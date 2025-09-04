/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MBEDTLS_ACCELERATOR_CONFIG_H
#define MBEDTLS_ACCELERATOR_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* When using the PSA Unified driver API, this is the only define that has to be added
 * to the ones being available in the non-platform aware config files being used, i.e.
 * just make sure that that the Crypto core and driver wrappers are aware of the driver
 */
#define PSA_CRYPTO_DRIVER_CC3XX

#define MBEDTLS_PSA_CRYPTO_CONFIG

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MBEDTLS_ACCELERATOR_CONFIG_H */
