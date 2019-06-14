/*
 * Copyright (c) 2017-2019 Arm Limited. All rights reserved.
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
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

/* Flash layout on PSoC6 CY8CKIT_062 with BL2:
 *
 * 0x1000_0000 BL2 - MCUBoot(128 KB)
 * 0x1002_0000 Flash_area_image_0(416 KB):
 *    0x1002_0000 Secure     image primary
 *    0x1006_0000 Non-secure image primary
 * 0x1008_8000 Flash_area_image_1(416 KB):
 *    0x1008_8000 Secure     image secondary
 *    0x100c_8000 Non-secure image secondary
 * 0x100f_0000 Scratch area(32 KB)
 * 0x100f_8000 Secure Storage Area(0.02 MB)
 * 0x100f_d000 NV counters area(16 Bytes)
 * 0x100f_d014 Unused(12 KB)
 *
 * Flash layout if BL2 not defined:
 * TBD
 *
 */

/* This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_base_address.h to access flash related defines. To resolve this
 * some of the values are redefined here with different names, these are marked
 * with comment.
 */

/* The size of S partition */
#define FLASH_S_PARTITION_SIZE          0x40000      /* 256 KB */
/* The size of NS partition */
#define FLASH_NS_PARTITION_SIZE         0x28000      /* 160 KB */
/*
 * Each FLASH_AREA_IMAGE contains NS and S partitions.
 * See Flash layout above.
 */
#define FLASH_PARTITION_SIZE            (FLASH_S_PARTITION_SIZE + \
                                         FLASH_NS_PARTITION_SIZE)

/* Sector size of the flash hardware; same as FLASH0_SECTOR_SIZE */
#define FLASH_AREA_IMAGE_SECTOR_SIZE    (0x200)      /* 512 B */
/* Same as FLASH0_SIZE */
#define FLASH_TOTAL_SIZE                (0x00100000) /* 1 MB */

/* Flash layout info for BL2 bootloader */
#define FLASH_BASE_ADDRESS              (0x10000000) /* same as FLASH0_BASE */

/* Offset and size definitions of the flash partitions that are handled by the
 * bootloader. The image swapping is done between IMAGE_0 and IMAGE_1, SCRATCH
 * is used as a temporary storage during image swapping.
 */
#define FLASH_AREA_BL2_OFFSET           (0x0)
#define FLASH_AREA_BL2_SIZE             (0x20000)  /* 128 kB */

#define FLASH_AREA_IMAGE_0_OFFSET       (FLASH_AREA_BL2_SIZE)
#define FLASH_AREA_IMAGE_0_SIZE         (FLASH_PARTITION_SIZE)

#define FLASH_AREA_IMAGE_1_OFFSET       (FLASH_AREA_IMAGE_0_OFFSET + FLASH_AREA_IMAGE_0_SIZE)
#define FLASH_AREA_IMAGE_1_SIZE         (FLASH_PARTITION_SIZE)

#define FLASH_AREA_IMAGE_SCRATCH_OFFSET (FLASH_AREA_IMAGE_1_OFFSET + FLASH_AREA_IMAGE_1_SIZE)
#define FLASH_AREA_IMAGE_SCRATCH_SIZE   (0x8000)   /* 32 KB */

/* Maximum number of status entries supported by the bootloader. */
#define BOOT_STATUS_MAX_ENTRIES         (FLASH_PARTITION_SIZE / \
                                         FLASH_AREA_IMAGE_SCRATCH_SIZE)

/** Maximum number of image sectors supported by the bootloader. */
#define BOOT_MAX_IMG_SECTORS            (FLASH_PARTITION_SIZE / \
                                         FLASH_AREA_IMAGE_SECTOR_SIZE)

#define FLASH_SST_AREA_OFFSET           (FLASH_AREA_IMAGE_SCRATCH_OFFSET + FLASH_AREA_IMAGE_SCRATCH_SIZE)
#define FLASH_SST_AREA_SIZE             (0x5000)   /* 20 KB */

#define FLASH_NV_COUNTERS_AREA_OFFSET   (FLASH_SST_AREA_OFFSET + FLASH_SST_AREA_SIZE)
#define FLASH_NV_COUNTERS_AREA_SIZE     (0x10)     /* 16 Bytes */

/* Offset and size definition in flash area, used by assemble.py */
#define SECURE_IMAGE_OFFSET             0x0
#define SECURE_IMAGE_MAX_SIZE           0x40000

#define NON_SECURE_IMAGE_OFFSET         0x40000
#define NON_SECURE_IMAGE_MAX_SIZE       0x28000

/* Flash device name used by BL2 and SST
 * Name is defined in flash driver file: Driver_Flash.c
 */
#define FLASH_DEV_NAME Driver_FLASH0

/* Secure Storage (SST) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M SST Integration Guide.
 */
#define SST_FLASH_DEV_NAME Driver_FLASH0

/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address.
 */
#define SST_FLASH_AREA_ADDR  FLASH_SST_AREA_OFFSET
// AINH: SST_SECTOR_SIZE has to be bigger than SST_ALIGNED_MAX_FILE_SIZE
#define SST_SECTOR_SIZE      (8 * FLASH_AREA_IMAGE_SECTOR_SIZE)
/* The sectors must be in consecutive memory location */
#define SST_NBR_OF_SECTORS  (FLASH_SST_AREA_SIZE / SST_SECTOR_SIZE)
/* Specifies the smallest flash programmable unit in bytes */
#define SST_FLASH_PROGRAM_UNIT  0x1
/* The maximum asset size to be stored in the SST area */
#define SST_MAX_ASSET_SIZE      2048
/* The maximum number of assets to be stored in the SST area */
#define SST_NUM_ASSETS          10

/* NV Counters definitions */
#define TFM_NV_COUNTERS_AREA_ADDR    FLASH_NV_COUNTERS_AREA_OFFSET
#define TFM_NV_COUNTERS_AREA_SIZE    FLASH_NV_COUNTERS_AREA_SIZE
#define TFM_NV_COUNTERS_SECTOR_ADDR  FLASH_NV_COUNTERS_AREA_OFFSET
#define TFM_NV_COUNTERS_SECTOR_SIZE  FLASH_AREA_IMAGE_SECTOR_SIZE

/* FIXME: Use SRAM2 memory to store RW data */
#define S_RAM_ALIAS_BASE  (0x08000000)
#define NS_RAM_ALIAS_BASE (0x08000000)

/* Shared data area between bootloader and runtime firmware.
 * Shared data area is allocated at the beginning of the RAM, it is overlapping
 * with TF-M Secure code's MSP stack
 */
#define BOOT_TFM_SHARED_DATA_BASE S_RAM_ALIAS_BASE
#define BOOT_TFM_SHARED_DATA_SIZE 0x400

#endif /* __FLASH_LAYOUT_H__ */
