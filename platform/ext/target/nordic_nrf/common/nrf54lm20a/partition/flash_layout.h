/*
 * Copyright (c) 2025 Nordic Semiconductor ASA. All rights reserved.
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

#ifdef BL2
#error "BL2 is not supported for this platform"
#endif

/* Flash layout on NRF54LM20A Application MCU without BL2:
 *
 * 0x0000_0000 Secure image primary (512 KB)
 * 0x0008_0000 Protected Storage Area (16 KB)
 * 0x0008_4000 Internal Trusted Storage Area (16 KB)
 * 0x0008_8000 OTP / NV counters area (8 KB)
 * 0x0008_A000 Non-secure image primary (1452 KB)
 * 0x001F_5000 Non-secure storage, used when built with NRF_NS_STORAGE=ON,
 *             otherwise unused (32 KB)
 */

/* This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_base_address.h to access flash related defines. To resolve
 * this some of the values are redefined here with different names, these are
 * marked with comment.
 */

/* Use Flash memory to store Code data */
#define FLASH_BASE_ADDRESS                  (0x0)

/* nRF54LM20A has 2036 kB of non volatile memory (RRAM) */
#define FLASH_TOTAL_SIZE                    (0x1FD000)
#define TOTAL_ROM_SIZE                       FLASH_TOTAL_SIZE

/* nRF54LM20A has 512 kB of volatile memory (SRAM) */
#define SRAM_BASE_ADDRESS                   (0x20000000)
#define TOTAL_RAM_SIZE                      (0x00080000)

#define FLASH_S_PARTITION_SIZE                (0x80000)       /* S partition: 512 kB*/
#define FLASH_NS_PARTITION_SIZE               (0x16B000)      /* NS partition: 1452 kB*/

#define S_ROM_ALIAS_BASE   FLASH_BASE_ADDRESS
#define NS_ROM_ALIAS_BASE  FLASH_BASE_ADDRESS

/* Use SRAM memory to store RW data */
#define S_RAM_ALIAS_BASE  SRAM_BASE_ADDRESS
#define NS_RAM_ALIAS_BASE SRAM_BASE_ADDRESS

/* Sector size of the embedded flash hardware (erase/program) */
#define FLASH_AREA_IMAGE_SECTOR_SIZE        (0x1000)           /* 4 KB. Flash memory program/erase operations have a page granularity. */

#if (FLASH_S_PARTITION_SIZE > FLASH_NS_PARTITION_SIZE)
#define FLASH_MAX_PARTITION_SIZE FLASH_S_PARTITION_SIZE
#else
#define FLASH_MAX_PARTITION_SIZE FLASH_NS_PARTITION_SIZE
#endif

/* Offset and size definition in flash area used by assemble.py */
#define SECURE_IMAGE_MAX_SIZE           FLASH_S_PARTITION_SIZE
#define NON_SECURE_IMAGE_MAX_SIZE       FLASH_NS_PARTITION_SIZE

#define SECURE_STORAGE_PARTITIONS_START       (FLASH_BASE_ADDRESS + FLASH_S_PARTITION_SIZE)

/* Protected Storage (PS) Service definitions */
#define FLASH_PS_AREA_OFFSET            (SECURE_STORAGE_PARTITIONS_START)
#define FLASH_PS_AREA_SIZE              (0x4000)   /* 16 KB */

/* Internal Trusted Storage (ITS) Service definitions */
#define FLASH_ITS_AREA_OFFSET           (FLASH_PS_AREA_OFFSET + FLASH_PS_AREA_SIZE)
#define FLASH_ITS_AREA_SIZE             (0x4000)   /* 16 KB */

/* OTP_definitions */
#define FLASH_OTP_NV_COUNTERS_AREA_OFFSET (FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE)
#define FLASH_OTP_NV_COUNTERS_AREA_SIZE   (0x2000) /* 8KB */

#define FLASH_OTP_NV_COUNTERS_SECTOR_SIZE FLASH_AREA_IMAGE_SECTOR_SIZE

#define SECURE_STORAGE_PARTITIONS_END     (FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE)
/* END OF PARTITIONS LAYOUT */

#define SECURE_IMAGE_OFFSET                   (0x0)
#define NON_SECURE_IMAGE_OFFSET               (SECURE_STORAGE_PARTITIONS_END)

/* Non-secure storage region */
#define NRF_FLASH_NS_STORAGE_AREA_SIZE      (0x8000)   /* 32 KB */
#define NRF_FLASH_NS_STORAGE_AREA_OFFSET    (FLASH_TOTAL_SIZE - \
                                             NRF_FLASH_NS_STORAGE_AREA_SIZE)

/* Flash device name used by BL2
 * Name is defined in flash driver file: Driver_Flash.c
 */
//#define FLASH_DEV_NAME Driver_FLASH0
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_FLASH_PROGRAM_UNIT       (0x4)

/* Protected Storage (PS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M PS Integration Guide.
 */
#define TFM_HAL_PS_FLASH_DRIVER Driver_FLASH0

/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address.
 */
/* Base address of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_ADDR    FLASH_PS_AREA_OFFSET
/* Size of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_SIZE    FLASH_PS_AREA_SIZE
#define PS_RAM_FS_SIZE                TFM_HAL_PS_FLASH_AREA_SIZE
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_PS_SECTORS_PER_BLOCK  (1)
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_PS_PROGRAM_UNIT       (0x4)

/* Internal Trusted Storage (ITS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M ITS Integration Guide. The ITS should be in the internal flash, but is
 * allocated in the external flash just for development platforms that don't
 * have internal flash available.
 */
#define TFM_HAL_ITS_FLASH_DRIVER Driver_FLASH0

/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address.
 */
/* Base address of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_ADDR    FLASH_ITS_AREA_OFFSET
/* Size of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_SIZE    FLASH_ITS_AREA_SIZE
#define ITS_RAM_FS_SIZE                TFM_HAL_ITS_FLASH_AREA_SIZE
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_ITS_SECTORS_PER_BLOCK  (1)
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_ITS_PROGRAM_UNIT       (0x4)

/* OTP / NV counter definitions */
#define TFM_OTP_NV_COUNTERS_AREA_SIZE   (FLASH_OTP_NV_COUNTERS_AREA_SIZE / 2)
#define TFM_OTP_NV_COUNTERS_AREA_ADDR   FLASH_OTP_NV_COUNTERS_AREA_OFFSET
#define TFM_OTP_NV_COUNTERS_SECTOR_SIZE FLASH_OTP_NV_COUNTERS_SECTOR_SIZE
#define TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR (TFM_OTP_NV_COUNTERS_AREA_ADDR + \
                                              TFM_OTP_NV_COUNTERS_AREA_SIZE)


#endif /* __FLASH_LAYOUT_H__ */
