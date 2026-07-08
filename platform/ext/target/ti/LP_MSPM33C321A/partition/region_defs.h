/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __REGION_DEFS_H__
#define __REGION_DEFS_H__

#include "flash_layout.h"

/*============================================================================
 * Stack and heap sizes
 *===========================================================================*/

#define S_HEAP_SIZE             (0x00001000)  /* 4 KB                      */
#define S_MSP_STACK_SIZE_INIT   (0x00000400)  /* 1 KB — early init stack   */
#define S_MSP_STACK_SIZE        (0x00002000)  /* 8 KB — main secure stack  */
#define S_PSP_STACK_SIZE        (0x00000800)  /* 2 KB — partition stack    */

#define NS_HEAP_SIZE            (0x00001000)  /* 4 KB                      */
#define NS_STACK_SIZE           (0x00001000)  /* 4 KB — NS main stack      */
#define NS_MSP_STACK_SIZE       (0x00000400)  /* 1 KB                      */
#define NS_PSP_STACK_SIZE       (0x00000C00)  /* 3 KB                      */

/*============================================================================
 * Attestation token size
 *===========================================================================*/

#define PSA_INITIAL_ATTEST_TOKEN_MAX_SIZE   (0x250)

/*============================================================================
 * No-BL2: Secure image starts at offset 0 within the Secure flash alias.
 *         NS image starts at offset 0x80000 within the NS flash alias
 *         (after the 512KB Secure partition).
 *===========================================================================*/

#define S_IMAGE_PRIMARY_PARTITION_OFFSET    (0x0)
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_S_PARTITION_SIZE)  /* 0x80000 */

/* No header overhead without bootloader */
#ifndef BL2_HEADER_SIZE
#define BL2_HEADER_SIZE                     (0x0)
#endif
#ifndef BL2_TRAILER_SIZE
#define BL2_TRAILER_SIZE                    (0x0)
#endif

/*============================================================================
 * Alias macros — resolve a partition-relative offset to an absolute address
 *===========================================================================*/

#define S_ROM_ALIAS(x)  (S_ROM_ALIAS_BASE + (x))
#define NS_ROM_ALIAS(x) (NS_ROM_ALIAS_BASE + (x))

#define S_RAM_ALIAS(x)  (S_RAM_ALIAS_BASE + (x))
#define NS_RAM_ALIAS(x) (NS_RAM_ALIAS_BASE + (x))

/*============================================================================
 * CMSE veneer region (NSC gateway — placed at end of Secure code region)
 *===========================================================================*/

#define CMSE_VENEER_REGION_SIZE         (0x000000C0)

/*============================================================================
 * Secure code and data regions
 *
 *   S_CODE_START = 0x1000_0000  (Secure flash alias base)
 *   S_CODE_SIZE  = 512 KB
 *   S_DATA_START = 0x3000_0000  (Secure SRAM alias base)
 *   S_DATA_SIZE  = 128 KB       (half of 256 KB SRAM)
 *===========================================================================*/

#define S_CODE_START    (S_ROM_ALIAS(S_IMAGE_PRIMARY_PARTITION_OFFSET))
#define S_CODE_SIZE     (FLASH_S_PARTITION_SIZE - CMSE_VENEER_REGION_SIZE)
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_START    (S_RAM_ALIAS(0x0))
#define S_DATA_SIZE     (TOTAL_RAM_SIZE / 2)            /* 128 KB           */
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

/*
 * RAM code region for functions that must execute from SRAM.
 * The MSPM33C321A flash controller requires DL_FlashCTL_executeCommandFromRAM
 * to run from SRAM — executing it from flash during a flash erase/program
 * operation causes a fault. Placed at end of Secure SRAM (512 bytes).
 * Size must be a multiple of 16 (128-bit flash word) for flash programming.
 */
#define S_RAM_CODE_START  (S_DATA_LIMIT - 0x1FF)       /* 512 B at end of S SRAM */
#define S_RAM_CODE_SIZE   (0x200)                      /* 512 B, multiple of 16  */

/* CMSE veneer region immediately follows Secure code */
#define CMSE_VENEER_REGION_START    (S_CODE_LIMIT + 1)

/*============================================================================
 * Non-Secure code and data regions
 *
 *   NS_CODE_START = 0x0000_0000  (NS flash alias base)
 *   NS_CODE_SIZE  = 512 KB
 *   NS_DATA_START = 0x2002_0000  (NS SRAM alias, offset by S_DATA_SIZE)
 *   NS_DATA_SIZE  = 128 KB       (remaining half of 256 KB SRAM)
 *===========================================================================*/

#define NS_CODE_START   (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_PARTITION_OFFSET))
#define NS_CODE_SIZE    (FLASH_NS_PARTITION_SIZE)
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

#define NS_DATA_START   (NS_RAM_ALIAS(S_DATA_SIZE))     /* 0x2002_0000      */
#define NS_DATA_SIZE    (TOTAL_RAM_SIZE - S_DATA_SIZE)  /* 128 KB           */
#define NS_DATA_LIMIT   (NS_DATA_START + NS_DATA_SIZE - 1)

/*============================================================================
 * NS partition info — used by SPM HAL to configure SAU
 *===========================================================================*/

#define NS_PARTITION_START  (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_PARTITION_OFFSET))
#define NS_PARTITION_SIZE   (FLASH_NS_PARTITION_SIZE)

/*============================================================================
 * Boot measurement shared data (at base of S SRAM, 1 KB)
 *===========================================================================*/
#define BOOT_TFM_SHARED_DATA_BASE   S_RAM_ALIAS_BASE
#define BOOT_TFM_SHARED_DATA_SIZE   (0x400)
#define BOOT_TFM_SHARED_DATA_LIMIT  (BOOT_TFM_SHARED_DATA_BASE + \
                                     BOOT_TFM_SHARED_DATA_SIZE - 1)
#define SHARED_BOOT_MEASUREMENT_BASE  BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE  BOOT_TFM_SHARED_DATA_SIZE
#define SHARED_BOOT_MEASUREMENT_LIMIT BOOT_TFM_SHARED_DATA_LIMIT

#endif /* __REGION_DEFS_H__ */
