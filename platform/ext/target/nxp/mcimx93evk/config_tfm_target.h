/*
 * Copyright (c) 2022, Arm Limited. All rights reserved.
 * Copyright 2022, 2025 NXP
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

/* This platform doesn't have flash on evk, so emulated RAM FS used for ITS, PS and NV Counters */
#ifndef PLATFORM_NO_FLASH
#define PLATFORM_NO_FLASH
#endif

#ifdef PLATFORM_NO_FLASH
/* Enable emulated RAM FS for platforms that don't have flash for Internal Trusted Storage partition */
#define ITS_RAM_FS           1

/* Enable emulated RAM FS for platforms that don't have flash for Protected Storage partition */
#define PS_RAM_FS            1

/* Enable OTP/NV_COUNTERS emulation in RAM */
#define OTP_NV_COUNTERS_RAM_EMULATION 1

#endif /* PLATFORM_NO_FLASH */

#endif /* __CONFIG_TFM_TARGET_H__ */
