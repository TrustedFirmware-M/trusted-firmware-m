/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MBEDTLS_TARGET_CONFIG_PSE84_H
#define MBEDTLS_TARGET_CONFIG_PSE84_H

/* *** DO NOT CHANGE ANY SETTINGS IN THIS SECTION *** */

#if IFX_MBEDTLS_ACCELERATION_ENABLED
/* Enable MXCRYPTO transparent driver */
#define IFX_PSA_MXCRYPTO_PRESENT

/* Use stack for mxcrypto dynamic data */
#define IFX_PSA_MXCRYPTO_USE_STACK_MEM

/*
 * Enable the CTR_DRBG AES-based random generator.
 * The CTR_DRBG generator uses AES-256 by default.
 * To use AES-128 instead, enable MBEDTLS_CTR_DRBG_USE_128_BIT_KEY below.
 */
#define MBEDTLS_CTR_DRBG_C
#endif

/*
 * Assume all buffers passed to PSA functions are owned exclusively by the
 * PSA function and are not stored in shared memory.
 */
#define MBEDTLS_PSA_ASSUME_EXCLUSIVE_BUFFERS

#ifdef IFX_MBEDTLS_CONFIG_PATH
/* Include project specific ifx-mbedtls configuration header */
#include IFX_MBEDTLS_CONFIG_PATH
#endif

#endif /* MBEDTLS_TARGET_CONFIG_PSE84_H */
