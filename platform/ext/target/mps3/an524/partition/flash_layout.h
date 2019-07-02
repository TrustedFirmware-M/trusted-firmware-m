/*
 * Copyright (c) 2019 Arm Limited. All rights reserved.
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

/*
 * Use the QSPI as boot flash
 *
 * QSPI MPC BLK_CFG register value is 0xD.
 * Thus QSPI MPC Block size is 256 KB = 2 ^ (0xD + 5).
 */

/*
 * The addresses used in the following layout are all NS alias
 * Flash layout with BL2:
 * 0x0000_0000 BL2 - MCUBoot            (256 KB)
 * Flash_area_image_0
 *     0x0004_0000 Secure image         (256 KB)
 *     0x0008_0000 Non-secure image     (256 KB)
 * Flash_area_image_1:
 *     0x000C_0000 Secure image         (256 KB)
 *     0x0010_0000 Non-secure image     (256 KB)
 * 0x0014_0000 Scratch area             (512 KB)
 * 0x001C_0000 SST area                 (20 KB)
 * 0x001C_5000 NV counters              (20 B)
 * 0x001C_5014 Unused
 *
 * Flash layout without BL2
 * 0x0000_0000 Secure image             (256 KB)
 * 0x0008_0000 Non-secure image         (256 KB)
 * 0x001C_0000 SST area                 (20 KB)
 * 0x001C_5000 NV counter               (20 B)
 * 0x001C_5014 Unused
 */

/* Flash base info for BL2 bootloader */
#define FLASH_BASE_ADDRESS              0x10000000
/*
 * Flash device name used by BL2
 * Name is defined in flash driver file: Driver_Flash.c
 */
#define FLASH_DEV_NAME              Driver_FLASH0

/*
 * Flash device name used by SST
 * Name is defined in flash driver file: Driver_Flash.c
 */
#define SST_FLASH_DEV_NAME          Driver_FLASH0


#define FLASH_AREA_IMAGE_SECTOR_SIZE    0x1000      /* 4 KB */
#define FLASH_TOTAL_SIZE                0x800000    /* 8 MB */

#define FLASH_AREA_S_IMAGE_SIZE         0x40000     /* 256 KB */
#define FLASH_AREA_NS_IMAGE_SIZE        0x40000     /* 256 KB */

#define FLASH_AREA_IMAGE_SLOT_SIZE      (FLASH_AREA_S_IMAGE_SIZE + \
                                         FLASH_AREA_NS_IMAGE_SIZE)

/* offset to QSPI base */
#define FLASH_AREA_BL2_OFFSET           0x0
#define FLASH_AREA_BL2_SIZE             0x40000     /* 256 KB */

#define FLASH_AREA_IMAGE_0_OFFSET       (FLASH_AREA_BL2_OFFSET + \
                                         FLASH_AREA_BL2_SIZE)
#define FLASH_AREA_IMAGE_0_SIZE         FLASH_AREA_IMAGE_SLOT_SIZE

#define FLASH_AREA_IMAGE_1_OFFSET       (FLASH_AREA_IMAGE_0_OFFSET + \
                                         FLASH_AREA_IMAGE_0_SIZE)
#define FLASH_AREA_IMAGE_1_SIZE         FLASH_AREA_IMAGE_SLOT_SIZE

#define FLASH_AREA_IMAGE_SCRATCH_OFFSET (FLASH_AREA_IMAGE_1_OFFSET + \
                                         FLASH_AREA_IMAGE_1_SIZE)
#define FLASH_AREA_IMAGE_SCRATCH_SIZE   FLASH_AREA_IMAGE_SLOT_SIZE

/* Maximum number of status entries supported by the bootloader. */
#define BOOT_STATUS_MAX_ENTRIES         (FLASH_AREA_IMAGE_SLOT_SIZE / \
                                         FLASH_AREA_IMAGE_SCRATCH_SIZE)

/* Maximum number of image sectors supported by the bootloader. */
#define BOOT_MAX_IMG_SECTORS            (FLASH_AREA_IMAGE_SLOT_SIZE / \
                                         FLASH_AREA_IMAGE_SECTOR_SIZE)

/*
 * Secure Storage (SST) Service definitions
 */
#define SST_FLASH_AREA_OFFSET       (FLASH_AREA_IMAGE_SCRATCH_OFFSET + \
                                     FLASH_AREA_IMAGE_SCRATCH_SIZE)

/*
 * In this target the CMSIS driver requires only the offset from the
 * flash base address instead of the full flash address.
 */
#define SST_FLASH_AREA_SIZE         0x5000   /* 20 KB */
#define SST_FLASH_AREA_ADDR         SST_FLASH_AREA_OFFSET

/* Sector size of the flash hardware; same as FLASH0_SECTOR_SIZE */
#define SST_SECTOR_SIZE             FLASH_AREA_IMAGE_SECTOR_SIZE  /* 4 KB */
/* The sectors must be in consecutive memory location */
#define SST_NBR_OF_SECTORS          (SST_FLASH_AREA_SIZE / SST_SECTOR_SIZE)
/* Specifies the smallest flash programmable unit in bytes */
#define SST_FLASH_PROGRAM_UNIT      0x1
/* The maximum asset size to be stored in the SST area */
#define SST_MAX_ASSET_SIZE          2048
/* The maximum number of assets to be stored in the SST area */
#define SST_NUM_ASSETS              10

/* NV Counters definitions */
#define FLASH_NV_COUNTERS_AREA_SIZE     (0x14)     /* 20 Bytes */
#define FLASH_NV_COUNTERS_AREA_OFFSET   (SST_FLASH_AREA_OFFSET + \
                                         SST_FLASH_AREA_SIZE)

#define TFM_NV_COUNTERS_AREA_ADDR       FLASH_NV_COUNTERS_AREA_OFFSET
#define TFM_NV_COUNTERS_AREA_SIZE       FLASH_NV_COUNTERS_AREA_SIZE
#define TFM_NV_COUNTERS_SECTOR_ADDR     FLASH_NV_COUNTERS_AREA_OFFSET
#define TFM_NV_COUNTERS_SECTOR_SIZE     FLASH_AREA_IMAGE_SECTOR_SIZE

/*
 * Offset and size definition in flash area, used by BL2 MCUboot assemble.py
 * assemble.py is unable to handle the nested macros.
 * Only immediate data is valid here.
 */
#define SECURE_IMAGE_OFFSET             0x0
/* FLASH_AREA_S_IMAGE_SIZE */
#define SECURE_IMAGE_MAX_SIZE           0x40000

/* SECURE_IMAGE_OFFSET + SECURE_IMAGE_MAX_SIZE */
#define NON_SECURE_IMAGE_OFFSET         0x40000
/* FLASH_AREA_NS_IMAGE_SIZE */
#define NON_SECURE_IMAGE_MAX_SIZE       0x40000

/*
 * Use Internal SRAM0~3 to store RW data
 * ISRAM0 and ISRAM1 for Secure Data
 * ISRAM2 and ISRAM3 for Non-Secure Data
 */
#define S_RAM_ALIAS_BASE                0x30000000
#define NS_RAM_ALIAS_BASE               0x20000000

/* Shared data area between bootloader and runtime firmware.
 * Shared data area is allocated at the beginning of the RAM, it is overlapping
 * with TF-M Secure code's MSP stack
 */
#define BOOT_TFM_SHARED_DATA_BASE       S_RAM_ALIAS_BASE
#define BOOT_TFM_SHARED_DATA_SIZE       0x400

#endif /* __FLASH_LAYOUT_H__ */
