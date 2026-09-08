/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __CONFIG_TFM_STM32MP2_H__
#define __CONFIG_TFM_STM32MP2_H__

/* Include optional claims in initial attestation token */
#undef ATTEST_INCLUDE_OPTIONAL_CLAIMS
#define ATTEST_INCLUDE_OPTIONAL_CLAIMS	0

/* For size optimization, set CLK_MINIMAL_SZ (no clock name defined e.g.) */
#ifndef CLK_MINIMAL_SZ
#define CLK_MINIMAL_SZ	1
#endif

/* Use stored NV seed to provide entropy */
#undef CRYPTO_NV_SEED
#define CRYPTO_NV_SEED 0
#define CRYPTO_EXT_RNG 1

#endif /* __CONFIG_TFM_STM32MP2_H__ */
