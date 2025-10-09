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

#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#define MBEDTLS_SHA512_C
#define MBEDTLS_SHA384_C

#ifdef TFM_BL1_2_ENABLE_LMS
#define MBEDTLS_SHA256_C
#define MBEDTLS_LMS_C
#define MBEDTLS_LMOTS_C
#endif /* TFM_BL1_2_ENABLE_LMS */

#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

/* CCM and AES Keys are handled by the hardware */
#define MBEDTLS_PSA_ACCEL_ALG_CCM
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_AES

#if defined(CRYPTO_HW_ACCELERATOR) && defined(MBEDTLS_ACCELERATOR_CONFIG_FILE)
#include MBEDTLS_ACCELERATOR_CONFIG_FILE
#endif

#ifdef __cplusplus
}
#endif

#endif /* BL1_1_MBEDCRYPO_CONFIG_H */
