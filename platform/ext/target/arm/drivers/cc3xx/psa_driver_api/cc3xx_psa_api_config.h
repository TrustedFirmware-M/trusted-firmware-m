/*
 * Copyright (c) 2022-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_PSA_API_CONFIG_H__
#define __CC3XX_PSA_API_CONFIG_H__

/** @file cc3xx_psa_api_config.h
 *
 * This file includes the configuration items specific to the CC3XX driver which
 * are not covered by the configuration mechanisms available in the PSA config
 * file, but are still relative to the CC3XX PSA Driver API interface layer only
 * A description of the options is available in \ref cc3xx.h
 *
 */

//#define CC3XX_CONFIG_ASSERT_CHECK
//#define CC3XX_CONFIG_ASSERT_DISABLE
#define CC3XX_CONFIG_ASSERT_ENABLE

//#define CC3XX_CONFIG_ENABLE_RANDOM_HASH_DRBG
//#define CC3XX_CONFIG_ENABLE_RANDOM_HMAC_DRBG
#define CC3XX_CONFIG_ENABLE_RANDOM_CTR_DRBG

#define CC3XX_CONFIG_ENABLE_MAC_INTEGRATED_API

#define CC3XX_CONFIG_ENABLE_STREAM_CIPHER

//#define CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS

#endif /* __CC3XX_PSA_API_CONFIG_H__ */
