/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__
#define __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "cc3xx_opaque_keys.h"
#include "crypto_opaque_key_ids.h"

#define PSA_WANT_ALG_SHA_256                    1

#define MBEDTLS_PSA_ACCEL_ALG_CCM
#define MBEDTLS_PSA_ACCEL_ALG_CTR
#define MBEDTLS_PSA_ACCEL_ALG_CMAC
#define MBEDTLS_PSA_ACCEL_ALG_SHA_256
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_AES


/* When using the PSA Unified driver API, this is the only define that has to be added
 * to the ones being available in the non-platform aware config files being used, i.e.
 * just make sure that that the Crypto core and driver wrappers are aware of the driver
 */
#define PSA_CRYPTO_DRIVER_CC3XX

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TF_PSA_CRYPTO_ACCELERATOR_CONFIG_H__ */
