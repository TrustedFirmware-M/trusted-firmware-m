/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H
#define TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef CRYPTO_HW_ACCELERATOR

/* Make sure NV seed is not used when HW accelerator/TRNG path is selected. */
#ifdef MBEDTLS_ENTROPY_NV_SEED
#undef MBEDTLS_ENTROPY_NV_SEED
#endif

#ifndef PSA_WANT_ALG_ECB_NO_PADDING
#define PSA_WANT_ALG_ECB_NO_PADDING 1
#endif

#ifdef MBEDTLS_PSA_BUILTIN_GET_ENTROPY
#undef MBEDTLS_PSA_BUILTIN_GET_ENTROPY
#endif

#ifndef MBEDTLS_PSA_DRIVER_GET_ENTROPY
#define MBEDTLS_PSA_DRIVER_GET_ENTROPY
#endif

/*todo remove it*/
#ifndef MBEDTLS_PSA_DRIVER_GET_ENTROPY
#define MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED
#endif

#if defined CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC
#define PSA_CRYPTO_DRIVER_PKC
#define PSA_CRYPTO_DRIVER_SGI
#endif /*CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC*/

#if defined CONFIG_PSA_CRYPTO_DRIVER_ELS_PKC
#define PSA_CRYPTO_DRIVER_ELS_PKC
#endif /*CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC*/

#include "platform_psa_hw_accel.h"

#endif /*CRYPTO_HW_ACCELERATOR*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H */