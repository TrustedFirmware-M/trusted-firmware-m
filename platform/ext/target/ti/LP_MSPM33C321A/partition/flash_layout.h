/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FLASH_LAYOUT_H__
#define __FLASH_LAYOUT_H__

/*
 * Flash layout for LP_MSPM33C321A — No BL2, single-image boot.
 *
 * MSPM33C321A memory map (from datasheet Table 8-2):
 *
 *   Main Flash (1 MB, two security aliases):
 *     Non-Secure alias:  0x0000_0000 - 0x000F_FFFF
 *     Secure alias:      0x1000_0000 - 0x100F_FFFF
 *
 *   Data Flash (32 KB, two security aliases):
 *     Non-Secure alias:  0x8000_0000 - 0x8000_7FFF
 *     Secure alias:      0x9000_0000 - 0x9000_7FFF
 *
 *   SRAM (256 KB, two security aliases):
 *     Non-Secure alias:  0x2000_0000 - 0x2003_FFFF
 *     Secure alias:      0x3000_0000 - 0x3003_FFFF
 *
 * Partition layout:
 *
 *   Main flash (code):
 *   0x1000_0000  Secure image (TF-M)              512 KB  (S alias)
 *   0x0008_0000  Non-Secure image (app)            512 KB  (NS alias)
 *
 *   Data flash (Bank 2, 32 KB):
 *   0x8000_0000  OTP / NV counters                  8 KB
 *   0x8000_2000  Internal Trusted Storage (ITS)     16 KB
 *   0x8000_6000  Protected Storage (PS)              8 KB
 */

/* This header is included from linker scatter files -- only limited C
 * constructs are allowed (no includes, no sizeof, no enums).
 */

/*============================================================================
 * 1. Base Hardware Addresses & Total Sizes
 *============================================================================*/

/* Main Flash */
#define FLASH_BASE_ADDRESS              (0x00000000)
#define FLASH_TOTAL_SIZE                (0x00100000)  /* 1 MB              */
#define FLASH_AREA_IMAGE_SECTOR_SIZE    (0x00001000)  /* 4 KB              */

/* Data Flash (Bank 2) */
#define DATA_FLASH_BASE_ADDRESS         (0x80000000)  /* NS alias */
#define DATA_FLASH_BASE_ADDRESS_S       (0x90000000)  /* Secure alias */
#define DATA_FLASH_TOTAL_SIZE           (0x00008000)  /* 32 KB             */
#define DATA_FLASH_SECTOR_SIZE          (0x00001000)  /* 4 KB              */

/*============================================================================
 * 2. Flash Partition Sizes (Main Flash)
 *============================================================================*/

#define FLASH_S_PARTITION_OFFSET         (0x00000000)
#define FLASH_S_PARTITION_SIZE           (0x00080000)  /* 512 KB -- Secure  */

#define FLASH_NS_PARTITION_OFFSET        (0x00080000)
#define FLASH_NS_PARTITION_SIZE          (0x00080000)  /* 512 KB -- NS      */

/*============================================================================
 * Data flash areas (offsets relative to DATA_FLASH_BASE_ADDRESS):
 *   0x0000 - 0x1FFF  OTP / NV counters         8 KB  (2 x 4KB sectors)
 *   0x2000 - 0x5FFF  Internal Trusted Storage  16 KB  (4 x 4KB sectors)
 *   0x6000 - 0x7FFF  Protected Storage          8 KB  (2 x 4KB sectors)
 *===========================================================================*/

/* OTP / NV counters: 8 KB — absolute data flash address */
#define DATA_FLASH_OTP_OFFSET           (0x00000000)
#define FLASH_OTP_NV_COUNTERS_AREA_OFFSET (DATA_FLASH_BASE_ADDRESS + DATA_FLASH_OTP_OFFSET)
#define FLASH_OTP_NV_COUNTERS_AREA_SIZE   (DATA_FLASH_SECTOR_SIZE * 2)  /* 8 KB */
#define FLASH_OTP_NV_COUNTERS_SECTOR_SIZE DATA_FLASH_SECTOR_SIZE

/* Internal Trusted Storage: 16 KB — absolute data flash address */
#define DATA_FLASH_ITS_OFFSET           (0x00002000)
#define FLASH_ITS_AREA_OFFSET           (DATA_FLASH_BASE_ADDRESS + DATA_FLASH_ITS_OFFSET)
#define FLASH_ITS_AREA_SIZE             (0x00004000)  /* 16 KB */

/* Protected Storage: 8 KB — absolute data flash address */
#define DATA_FLASH_PS_OFFSET            (0x00006000)
#define FLASH_PS_AREA_OFFSET            (DATA_FLASH_BASE_ADDRESS + DATA_FLASH_PS_OFFSET)
#define FLASH_PS_AREA_SIZE              (0x00002000)  /* 8 KB */

/*============================================================================
 * CMSIS Flash driver — single Driver_FLASH0 handles both main and data flash.
 * Address-based dispatch in Driver_Flash.c:
 *   addr >= DATA_FLASH_BASE_ADDRESS  →  data flash (Bank 2)
 *   addr <  DATA_FLASH_BASE_ADDRESS  →  main flash (Bank 0/1)
 *===========================================================================*/

#define FLASH_DEV_NAME                  Driver_FLASH0
#define TFM_HAL_FLASH_PROGRAM_UNIT      (0x10)  /* 128-bit flash word */

/*============================================================================
 * Protected Storage (PS) HAL definitions — data flash
 *===========================================================================*/

#define TFM_HAL_PS_FLASH_DRIVER         Driver_FLASH0
#define TFM_HAL_PS_FLASH_AREA_ADDR      FLASH_PS_AREA_OFFSET
#define TFM_HAL_PS_FLASH_AREA_SIZE      FLASH_PS_AREA_SIZE
#define PS_RAM_FS_SIZE                  TFM_HAL_PS_FLASH_AREA_SIZE
#define TFM_HAL_PS_SECTORS_PER_BLOCK    (1)
#define TFM_HAL_PS_PROGRAM_UNIT         (0x10)

/*============================================================================
 * Internal Trusted Storage (ITS) HAL definitions — data flash
 *===========================================================================*/

#define TFM_HAL_ITS_FLASH_DRIVER        Driver_FLASH0
#define TFM_HAL_ITS_FLASH_AREA_ADDR     FLASH_ITS_AREA_OFFSET
#define TFM_HAL_ITS_FLASH_AREA_SIZE     FLASH_ITS_AREA_SIZE
#define ITS_RAM_FS_SIZE                 TFM_HAL_ITS_FLASH_AREA_SIZE
#define TFM_HAL_ITS_SECTORS_PER_BLOCK   (1)
#define TFM_HAL_ITS_PROGRAM_UNIT        (0x10)

/*============================================================================
 * OTP / NV counter HAL definitions — data flash
 *===========================================================================*/

#define TFM_OTP_NV_COUNTERS_AREA_SIZE   (FLASH_OTP_NV_COUNTERS_AREA_SIZE / 2)
#define TFM_OTP_NV_COUNTERS_AREA_ADDR   FLASH_OTP_NV_COUNTERS_AREA_OFFSET
#define TFM_OTP_NV_COUNTERS_SECTOR_SIZE FLASH_OTP_NV_COUNTERS_SECTOR_SIZE
#define TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR \
                                        (TFM_OTP_NV_COUNTERS_AREA_ADDR + \
                                         TFM_OTP_NV_COUNTERS_AREA_SIZE)

/*============================================================================
 * Memory alias base addresses (from datasheet Table 8-2)
 *
 * Flash and SRAM each have two security aliases over the same physical memory.
 *===========================================================================*/

#define S_ROM_ALIAS_BASE                (0x10000000)  /* Secure main flash alias  */
#define NS_ROM_ALIAS_BASE               (0x00000000)  /* NS main flash alias      */

#define S_RAM_ALIAS_BASE                (0x30000000)  /* Secure SRAM alias        */
#define NS_RAM_ALIAS_BASE               (0x20000000)  /* NS SRAM alias            */

#define TOTAL_ROM_SIZE                  FLASH_TOTAL_SIZE

/*
 * SRAM security split — must match the GSC configuration in target_cfg.c.
 * GSC marks pages 0-7 (0x2000_0000-0x2001_FFFF) Secure and
 * pages 8-15 (0x2002_0000-0x2003_FFFF) Non-Secure: 128 KB each.
 */
#define S_RAM_SIZE                      (0x00020000)  /* 128 KB — Secure (GSC pages 0-7)  */
#define NS_RAM_SIZE                     (0x00020000)  /* 128 KB — NS     (GSC pages 8-15) */
#define TOTAL_RAM_SIZE                  (S_RAM_SIZE + NS_RAM_SIZE)  /* 256 KB */

#endif /* __FLASH_LAYOUT_H__ */
