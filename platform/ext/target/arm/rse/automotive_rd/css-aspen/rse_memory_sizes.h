/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file rse_memory_sizes.h
 * \brief This file contains the sizes of main memories, boot flash and OTP.
 */

#ifndef __RSE_MEMORY_SIZES_H__
#define __RSE_MEMORY_SIZES_H__

/* Override memory sizes before loading the common default sizes */

#define BOOT_FLASH_SIZE    0x4000000 /* 64MB */
#define AP_BOOT_FLASH_SIZE 0x4000000 /* 64MB */

/*
 * The size of the SRAM which is allocated to NS. This may be increased
 * depending on the layout.
 */
#define NS_DATA_SIZE (0x0)

/* The maximum size for secret values in the provisioning bundle */
#define PROVISIONING_BUNDLE_VALUES_SIZE (0x3D00)

/* RSE flash layout */
/*
 * ┌─────────────────────┬──────────────────────┬──────────────────────────┐
 * │    Signed Images    │  Protected Storage   │ Internal Trusted Storage │
 * │     (48MB)          │       (64KB)         │           (1MB)          │
 * └─────────────────────┴──────────────────────┴──────────────────────────┘
 */
/* This part is for signed images. 48MB */
#define RSE_FLASH_IMG_SIZE          0x3000000UL
/* This part is for Protected Storage. 64KB */
#define RSE_FLASH_PS_SIZE           0x10000UL
/* This part is for Internal Trusted Storage. 1MB */
#define RSE_FLASH_ITS_SIZE          0x100000UL

#include "rse_memory_sizes_common.h"

#endif /* __RSE_MEMORY_SIZES_H__ */
