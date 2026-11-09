/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __FLASH_LAYOUT_H__
#define __FLASH_LAYOUT_H__


 /* Flash layout on frdmmcxw70 without BL2:
 *
 * 0x0000_0000 Primary image area(288 KB):
 *    0x0000_0000 Secure     image primary (160 kB)
 *    0x0002_8000 Non-secure image primary (128 kB)
 * Reserved area:
 * 0xXXXX_XXXX Secure Binary tail Area (4 KB), if SB is used.
 * 0xXXXX_XXXX Internal Trusted Storage Area (4 KB) RAM based
 * 0xXXXX_XXXX NV counters area  RAM based
 * 0xXXXX_XXXX Unused
 */

/* This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_base_address.h to access flash related defines. To resolve
 * this some of the values are redefined here with different names, these are
 * marked with comment.
 */

/* Size of a Secure and of a Non-secure image */
#if defined(MCU_SDK_REGRESSION)
#define FLASH_S_PARTITION_SIZE              (192 * 1024)       /* S partition: 192 KB : (0x30000)  */
#define FLASH_NS_PARTITION_SIZE             (128 * 1024)       /* NS partition: 128 KB : (0x20000)  */
#else
#define FLASH_S_PARTITION_SIZE              (160 * 1024)       /* S partition: 160 KB : (0x28000)  */
#define FLASH_NS_PARTITION_SIZE             (128 * 1024)       /* NS partition: 128 KB : (0x20000)  */
#endif

/* Sector size of flash hardware (erase/program) */
#define FLASH_AREA_IMAGE_SECTOR_SIZE        (1*512)           /* As Only RAM is used, SECTOR size is adjusted to 512 B. */
#define FLASH_AREA_PROGRAM_SIZE             (128U)             /* 128 B as page size*/
#define FLASH_AREA_IMAGE_PHRASE_SIZE        (16U)              /* 16 B for write */

/* All phantoms of mcxw70 has 1.5 MB of flash*/
#define FLASH_TOTAL_SIZE   (1 * 1024 * 1024)    /* 1024 KB flash (1.5 MB) or use 1MB foot print becoz: 1536 -512 = 1024 KB, 512 KB is subtracted as its occupied by NBU firmware*/

/* Flash layout info for BL2 bootloader */
#define FLASH_BASE_ADDRESS                  (0x00800000)
#define FLASH_BASE_S                        (0x10800000)

#ifdef SB_FILE /* Use signed Secure Binary (SB) image */
#define FLASH_SB_TAIL   0x2000 /* 8 KB */
#else
#define FLASH_SB_TAIL   0x0 /* 0 KB */
#endif

/* Secure + Non-secure image primary slot */
#define FLASH_AREA_0_ID            (1)
#define FLASH_AREA_0_OFFSET        (0x0)
#define FLASH_AREA_0_SIZE          (FLASH_S_PARTITION_SIZE + \
                                    FLASH_NS_PARTITION_SIZE + \
                                    FLASH_SB_TAIL)

/* Not used*/
#define FLASH_AREA_SCRATCH_ID      (FLASH_AREA_0_ID + 1)
#define FLASH_AREA_SCRATCH_OFFSET  (FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE)
#define FLASH_AREA_SCRATCH_SIZE    (0)

/* Note: FLASH_PS_AREA_OFFSET, FLASH_ITS_AREA_OFFSET and
 * FLASH_OTP_NV_COUNTERS_AREA_OFFSET point to offsets in flash, but reads and
 * writes to these addresses are redirected to Code SRAM by Driver_Flash.c.
 */

/* Protected Storage (PS) Service definitions */
#define FLASH_PS_AREA_OFFSET            (FLASH_AREA_SCRATCH_OFFSET + \
                                         FLASH_AREA_SCRATCH_SIZE)
#define FLASH_PS_AREA_SIZE              (0x1000) /* 4 KB */

/* Internal Trusted Storage (ITS) Service definitions */
#define FLASH_ITS_AREA_OFFSET           (FLASH_PS_AREA_OFFSET + \
                                         FLASH_PS_AREA_SIZE)
#define FLASH_ITS_AREA_SIZE             (0x0C00) /* 3 KB */

/* OTP_definitions */
#define FLASH_OTP_NV_COUNTERS_AREA_OFFSET (FLASH_ITS_AREA_OFFSET + \
                                           FLASH_ITS_AREA_SIZE)
#define FLASH_OTP_NV_COUNTERS_AREA_SIZE   (FLASH_AREA_IMAGE_SECTOR_SIZE * 2)
#define FLASH_OTP_NV_COUNTERS_SECTOR_SIZE FLASH_AREA_IMAGE_SECTOR_SIZE

/* Offset and size definition in flash area used by assemble.py */
#define SECURE_IMAGE_OFFSET             (0x0)
#define SECURE_IMAGE_MAX_SIZE           FLASH_S_PARTITION_SIZE

#define NON_SECURE_IMAGE_OFFSET         (SECURE_IMAGE_OFFSET + \
                                         SECURE_IMAGE_MAX_SIZE)
#define NON_SECURE_IMAGE_MAX_SIZE       FLASH_NS_PARTITION_SIZE

/* Flash device name used by BL2
 * Name is defined in flash driver file: Driver_Flash.c
 */
#define FLASH_DEV_NAME                  Driver_EFLASH0
/* Smallest flash programmable unit in bytes (not used at the moment) */
#define TFM_HAL_FLASH_PROGRAM_UNIT      FLASH_AREA_IMAGE_PHRASE_SIZE

/* Protected Storage (PS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M PS Integration Guide.
 */
#define TFM_HAL_PS_FLASH_DRIVER Driver_EFLASH0

/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address.
 */
/* Base address of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_ADDR      (FLASH_PS_AREA_OFFSET)
/* Size of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_SIZE      FLASH_PS_AREA_SIZE
#define PS_RAM_FS_SIZE                  TFM_HAL_PS_FLASH_AREA_SIZE
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_PS_SECTORS_PER_BLOCK    1

/* Smallest flash programmable unit in bytes */
#define TFM_HAL_PS_PROGRAM_UNIT         FLASH_AREA_IMAGE_PHRASE_SIZE
/* TBD -- Not sure what is this ? */
#define PS_FLASH_NAND_BUF_SIZE          (FLASH_AREA_IMAGE_SECTOR_SIZE * \
                                        TFM_HAL_PS_SECTORS_PER_BLOCK)

/* Internal Trusted Storage (ITS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M ITS Integration Guide. The ITS should be in the internal flash, but is
 * allocated in the external flash just for development platforms that don't
 * have internal flash available.
 */
#define TFM_HAL_ITS_FLASH_DRIVER Driver_EFLASH0


/* In this target the CMSIS driver requires the full memory address
 */
/* Base address of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_ADDR    (FLASH_ITS_AREA_OFFSET)
/* Size of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_SIZE    FLASH_ITS_AREA_SIZE
#define ITS_RAM_FS_SIZE                TFM_HAL_ITS_FLASH_AREA_SIZE
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_ITS_SECTORS_PER_BLOCK   1

/* Smallest flash programmable unit in bytes */
#define TFM_HAL_ITS_PROGRAM_UNIT        FLASH_AREA_IMAGE_PHRASE_SIZE

#define ITS_FLASH_NAND_BUF_SIZE        (FLASH_AREA_IMAGE_SECTOR_SIZE * \
                                        TFM_HAL_ITS_SECTORS_PER_BLOCK)

/* OTP / NV counter definitions */
#define TFM_OTP_NV_COUNTERS_AREA_SIZE   (FLASH_OTP_NV_COUNTERS_AREA_SIZE / 2)
#define TFM_OTP_NV_COUNTERS_AREA_ADDR   (FLASH_OTP_NV_COUNTERS_AREA_OFFSET)
#define TFM_OTP_NV_COUNTERS_SECTOR_SIZE FLASH_OTP_NV_COUNTERS_SECTOR_SIZE
#define TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR (TFM_OTP_NV_COUNTERS_AREA_ADDR + \
                                              TFM_OTP_NV_COUNTERS_AREA_SIZE)

/* Use Flash memory to store Code data */
#define S_ROM_ALIAS_BASE        (0x10800000)
#define NS_ROM_ALIAS_BASE       (0x00800000)

/* Use SRAM[0-4] memory to store RW data */
#define S_RAM_ALIAS_BASE        (0x30000000)
#define NS_RAM_ALIAS_BASE       (0x20000000)

/* Offset, from the start of RAM0, of the secure data area. Kept at 0 so that
 * S_DATA_START/BL2_DATA_START/BOOT_TFM_SHARED_DATA_BASE all sit at the very
 * beginning of RAM0. This is NOT the inter-core shared region: that one is the
 * 8 KB at the end of RAM2 (0x2002E000 - 0x2002FFFF), which is owned by the NBU
 * core and is already excluded from TOTAL_RAM_SIZE (see the layout below).
 */
#define RESERVED_RAM_SIZE       0x0

#define TOTAL_ROM_SIZE      FLASH_TOTAL_SIZE

/*
 * RAM layout (256 KB total, 4 banks of 64 KB each).
 *
 * +----------------------------------------------------+
 * | RAM0  0x20000000 - 0x2000FFFF  App core    (64 KB) |
 * +----------------------------------------------------+
 * | RAM1  0x20010000 - 0x2001FFFF  App core    (64 KB) |
 * +----------------------------------------------------+
 * | RAM2  0x20020000 - 0x20028DFF  App core  (0x8E00)  |
 * |       0x20028E00 - 0x2002DFFF  NBU core  (0x5200)  |
 * |       0x2002E000 - 0x2002FFFF  Shared      (8 KB)  |
 * +----------------------------------------------------+
 * | RAM3  0x20030000 - 0x2003FFFF  NBU core    (64 KB) |
 * +----------------------------------------------------+
 *
 * The application core (TF-M secure + non-secure) owns RAM0, RAM1 and the
 * first 0x8E00 of RAM2. The remainder of RAM2 and all of RAM3 belong to the
 * NBU core and are left out of TOTAL_RAM_SIZE.
 */
#define TOTAL_RAM_SIZE      (0x00028E00)  /* RAM0 (64 KB) + RAM1 (64 KB) + RAM2 app part (35.5 KB) */

#endif /* __FLASH_LAYOUT_H__ */
