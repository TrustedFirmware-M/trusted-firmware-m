/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __TF_PSA_CRYPTO_EXTRA_CONFIG_H__
#define __TF_PSA_CRYPTO_EXTRA_CONFIG_H__

#define PSA_WANT_ALG_GCM                1

/* RNG Config */
#undef MBEDTLS_ENTROPY_NV_SEED
#undef MBEDTLS_ENTROPY_NO_SOURCES_OK
#undef MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG 1

#endif /* __TF_PSA_CRYPTO_EXTRA_CONFIG_H__ */
