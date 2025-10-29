
/*
 * Copyright (c) 2025 Analog Devices, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__
#define __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* RNG Config */
#undef MBEDTLS_ENTROPY_NV_SEED
#undef MBEDTLS_ENTROPY_NO_SOURCES_OK
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

/****************************************************************/
/* Require built-in implementations based on PSA requirements */
/****************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__ */
