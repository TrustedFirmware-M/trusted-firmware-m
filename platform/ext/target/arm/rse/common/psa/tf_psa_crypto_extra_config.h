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

#undef  PSA_WANT_ALG_CCM
#define PSA_WANT_ALG_CCM                        1

#undef  PSA_WANT_ALG_CTR
#define PSA_WANT_ALG_CTR                        1

#undef  PSA_WANT_ALG_SP800_108_COUNTER_CMAC
#define PSA_WANT_ALG_SP800_108_COUNTER_CMAC     1

#undef PSA_WANT_KEY_TYPE_AES
#define PSA_WANT_KEY_TYPE_AES                   1

#ifdef CRYPTO_HW_ACCELERATOR
#include MBEDTLS_ACCELERATOR_PSA_CRYPTO_CONFIG_FILE
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TF_PSA_CRYPTO_EXTRA_CONFIG_H__ */
