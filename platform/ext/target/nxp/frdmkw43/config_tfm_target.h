/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CONFIG_TFM_TARGET_H__
#define __CONFIG_TFM_TARGET_H__

/* Using of stored NV seed to provide entropy is disabled, when CRYPTO_HW_ACCELERATOR is defined.  */
#ifdef CRYPTO_HW_ACCELERATOR
#define CRYPTO_NV_SEED       0
#define CRYPTO_EXT_RNG       1
#endif

/* The max number of concurrent operations that can be active (allocated) at any time in Crypto */
#ifndef CRYPTO_CONC_OPER_NUM
#define CRYPTO_CONC_OPER_NUM                   4
#endif

/* Enable PSA Crypto Cipher module */
#ifndef CRYPTO_CIPHER_MODULE_ENABLED
#define CRYPTO_CIPHER_MODULE_ENABLED           1
#endif

/*
 * Heap size for the crypto backend
 * CRYPTO_ENGINE_BUF_SIZE needs to be >8KB for EC signing by attest module.
 */
#undef CRYPTO_ENGINE_BUF_SIZE
#define CRYPTO_ENGINE_BUF_SIZE                 0x2040

/* Default size of the internal scratch buffer used for PSA FF IOVec allocations */
#undef CRYPTO_IOVEC_BUFFER_SIZE
#define CRYPTO_IOVEC_BUFFER_SIZE               4608

/* The stack size of the Crypto Secure Partition */
#undef CRYPTO_STACK_SIZE
#define CRYPTO_STACK_SIZE                      0x2000

#if defined(CONFIG_TFM_SPM_BACKEND_IPC)
/* The maximal number of secure services that are connected or requested at the same time */
#undef CONFIG_TFM_CONN_HANDLE_MAX_NUM
#define CONFIG_TFM_CONN_HANDLE_MAX_NUM         5
#endif /* CONFIG_TFM_SPM_BACKEND_IPC */

/* The maximum asset size to be stored in the Internal Trusted Storage */
#undef ITS_MAX_ASSET_SIZE
#define ITS_MAX_ASSET_SIZE                     512

/* The maximum number of assets to be stored in the Internal Trusted Storage */
#undef ITS_NUM_ASSETS
#define ITS_NUM_ASSETS                         6

#ifdef PLATFORM_NO_FLASH
/* Enable emulated RAM FS for platforms that don't have flash for Internal Trusted Storage partition */
#define ITS_RAM_FS           1

/* Enable emulated RAM FS for platforms that don't have flash for Protected Storage partition */
#define PS_RAM_FS            1

/* Enable OTP/NV_COUNTERS emulation in RAM */
#define OTP_NV_COUNTERS_RAM_EMULATION 1

#endif /* PLATFORM_NO_FLASH */

#endif /* __CONFIG_TFM_TARGET_H__ */
