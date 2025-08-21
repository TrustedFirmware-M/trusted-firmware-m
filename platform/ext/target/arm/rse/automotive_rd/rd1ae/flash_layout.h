/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
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

/**
 * \file flash_layout.h
 * \brief This file contains the flash layout (memory offsets and sizes)
 *        and the flash devices name.
 */

#ifndef __FLASH_LAYOUT_H__
#define __FLASH_LAYOUT_H__

#include "bl2_image_id.h"
#include "image_size_defs.h"
#include "platform_base_address.h"

/* Flash layout on RSE flash with BL2 (multiple image boot):
 *
 * Offset    Image (Size)
 *       0x0 BL2 - MCUBoot primary slot (128 KB)
 *  0x2_0000 BL2 - MCUBoot secondary slot (128 KB)
 *  0x4_0000 Secure image     primary slot (384 KB)
 *  0xA_0000 Non-secure image primary slot (384 KB)
 * 0x10_0000 Secure image     secondary slot (384 KB)
 * 0x16_0000 Non-secure image secondary slot (384 KB)
 * 0x1C_0000 SCP primary slot (512 KB)
 * 0x24_0000 SCP secondary slot (512 KB)
 * 0x2C_0000 SI CL0 primary slot (2048 KB)
 * 0x4C_0000 SI CL0 secondary slot (2048 KB)
 * 0x6C_0000 SI CL1 primary slot (4096 KB)
 * 0xAC_0000 SI CL1 secondary slot (4096 KB)
 * 0xEC_0000 SI CL2 primary slot (8192 KB)
 * 0x16C_0000 SI CL2 secondary slot (8192 KB)
 *
 * Flash layout on AP Secure flash with BL2 (multiple image boot):
 *
 * Offset    Image (Size)
 *    0x0    FIP primary slot (2048 KB)
 * 0x20_0000 FIP secondary slot (2048 KB)
 */

/*
 * This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_retarget.h to access flash related defines. To resolve this
 * some of the values are redefined here with different names, these are marked
 * with comment.
 */

/* Size of a Secure and of a Non-secure image */
#define FLASH_BL2_PARTITION_SIZE        (SIZE_DEF_BL2_IMAGE) /* BL2 partition */
#define FLASH_S_PARTITION_SIZE          (SIZE_DEF_S_IMAGE)   /* S   partition */
#define FLASH_NS_PARTITION_SIZE         (SIZE_DEF_NS_IMAGE)  /* NS  partition */
#define FLASH_SCP_PARTITION_SIZE        (SIZE_DEF_SCP_IMAGE) /* SCP partition */
#define FLASH_AP_BL2_PARTITION_SIZE     (SIZE_DEF_AP_BL2_IMAGE) /* AP BL2  partition */
#define FLASH_SI_CL0_PARTITION_SIZE     (SIZE_DEF_SI_CL0_IMAGE) /* SI CL0 partition */
#define FLASH_SI_CL1_PARTITION_SIZE     (SIZE_DEF_SI_CL1_IMAGE) /* SI CL1 partition */
#define FLASH_SI_CL2_PARTITION_SIZE     (SIZE_DEF_SI_CL2_IMAGE) /* SI CL2 partition */
#define FLASH_MAX_PARTITION_SIZE        ((FLASH_S_PARTITION_SIZE >   \
                                          FLASH_NS_PARTITION_SIZE) ? \
                                         FLASH_S_PARTITION_SIZE :    \
                                         FLASH_NS_PARTITION_SIZE)

/* Sector size of the flash hardware; same as FLASH0_SECTOR_SIZE */
#define FLASH_AREA_IMAGE_SECTOR_SIZE    (0x1000)    /* 4 KB */
/* Same as FLASH0_SIZE */
#define FLASH_TOTAL_SIZE                (BOOT_FLASH_SIZE)

/* Flash layout info for BL2 bootloader */
/* Same as FLASH0_BASE_S */
#define FLASH_BASE_ADDRESS              (BOOT_FLASH_BASE_S)
#define FLASH_BL1_BASE_ADDRESS          (FLASH_BASE_ADDRESS)

/*
 * Offset and size definitions of the flash partitions that are handled by the
 * bootloader. The image swapping is done between IMAGE_PRIMARY and
 * IMAGE_SECONDARY, SCRATCH is used as a temporary storage during image
 * swapping.
 */

/* BL2 primary slot */
#define FLASH_AREA_0_ID            (1)
#define FLASH_AREA_0_OFFSET        (0)
#define FLASH_AREA_0_SIZE          (FLASH_BL2_PARTITION_SIZE)
/* BL2 secondary slot */
#define FLASH_AREA_1_ID            (FLASH_AREA_0_ID + 1)
#define FLASH_AREA_1_OFFSET        (FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE)
#define FLASH_AREA_1_SIZE          (FLASH_BL2_PARTITION_SIZE)

/* Secure image primary slot. */
#define FLASH_AREA_2_ID            (FLASH_AREA_1_ID + 1)
#define FLASH_AREA_2_OFFSET        (FLASH_AREA_1_OFFSET + FLASH_AREA_1_SIZE)
#define FLASH_AREA_2_SIZE          (FLASH_S_PARTITION_SIZE)
/* Non-secure image primary slot. */
#define FLASH_AREA_3_ID            (FLASH_AREA_2_ID + 1)
#define FLASH_AREA_3_OFFSET        (FLASH_AREA_2_OFFSET + FLASH_AREA_2_SIZE)
#define FLASH_AREA_3_SIZE          (FLASH_NS_PARTITION_SIZE)
/* Secure image secondary slot. */
#define FLASH_AREA_4_ID            (FLASH_AREA_3_ID + 1)
#define FLASH_AREA_4_OFFSET        (FLASH_AREA_3_OFFSET + FLASH_AREA_3_SIZE)
#define FLASH_AREA_4_SIZE          (FLASH_S_PARTITION_SIZE)
/* Non-secure image secondary slot. */
#define FLASH_AREA_5_ID            (FLASH_AREA_4_ID + 1)
#define FLASH_AREA_5_OFFSET        (FLASH_AREA_4_OFFSET + FLASH_AREA_4_SIZE)
#define FLASH_AREA_5_SIZE          (FLASH_NS_PARTITION_SIZE)

/* SCP image primary slot */
#define FLASH_AREA_6_ID            (FLASH_AREA_5_ID + 1)
#define FLASH_AREA_6_OFFSET        (FLASH_AREA_5_OFFSET + FLASH_AREA_5_SIZE)
#define FLASH_AREA_6_SIZE          (FLASH_SCP_PARTITION_SIZE)
/* SCP image secondary slot */
#define FLASH_AREA_7_ID            (FLASH_AREA_6_ID + 1)
#define FLASH_AREA_7_OFFSET        (FLASH_AREA_6_OFFSET + FLASH_AREA_6_SIZE)
#define FLASH_AREA_7_SIZE          (FLASH_SCP_PARTITION_SIZE)
/* SI CL0 image primary slot */
#define FLASH_AREA_8_ID            (FLASH_AREA_7_ID + 1)
#define FLASH_AREA_8_OFFSET        (FLASH_AREA_7_OFFSET + FLASH_AREA_7_SIZE)
#define FLASH_AREA_8_SIZE          (FLASH_SI_CL0_PARTITION_SIZE)
/* SI CL0 image secondary slot */
#define FLASH_AREA_9_ID            (FLASH_AREA_8_ID + 1)
#define FLASH_AREA_9_OFFSET        (FLASH_AREA_8_OFFSET + FLASH_AREA_8_SIZE)
#define FLASH_AREA_9_SIZE          (FLASH_SI_CL0_PARTITION_SIZE)
/* SI CL1 image primary slot */
#define FLASH_AREA_10_ID            (FLASH_AREA_9_ID + 1)
#define FLASH_AREA_10_OFFSET        (FLASH_AREA_9_OFFSET + FLASH_AREA_9_SIZE)
#define FLASH_AREA_10_SIZE          (FLASH_SI_CL1_PARTITION_SIZE)
/* SI CL1 image secondary slot */
#define FLASH_AREA_11_ID            (FLASH_AREA_10_ID + 1)
#define FLASH_AREA_11_OFFSET        (FLASH_AREA_10_OFFSET + FLASH_AREA_10_SIZE)
#define FLASH_AREA_11_SIZE          (FLASH_SI_CL1_PARTITION_SIZE)
/* SI CL2 image primary slot */
#define FLASH_AREA_12_ID            (FLASH_AREA_11_ID + 1)
#define FLASH_AREA_12_OFFSET        (FLASH_AREA_11_OFFSET + FLASH_AREA_11_SIZE)
#define FLASH_AREA_12_SIZE          (FLASH_SI_CL2_PARTITION_SIZE)
/* SI CL2 image secondary slot */
#define FLASH_AREA_13_ID            (FLASH_AREA_12_ID + 1)
#define FLASH_AREA_13_OFFSET        (FLASH_AREA_12_OFFSET + FLASH_AREA_12_SIZE)
#define FLASH_AREA_13_SIZE          (FLASH_SI_CL2_PARTITION_SIZE)
/* AP BL2 image primary slot */
#define AP_FLASH_AREA_0_ID          (FLASH_AREA_13_ID + 1)
#define AP_FLASH_AREA_0_OFFSET      (0)
#define AP_FLASH_AREA_0_SIZE        (FLASH_AP_BL2_PARTITION_SIZE)
/* AP BL2 image secondary slot */
#define AP_FLASH_AREA_1_ID          (AP_FLASH_AREA_0_ID + 1)
#define AP_FLASH_AREA_1_OFFSET      (AP_FLASH_AREA_0_OFFSET + \
                                     AP_FLASH_AREA_0_SIZE)
#define AP_FLASH_AREA_1_SIZE        (FLASH_AP_BL2_PARTITION_SIZE)

/* Maximum number of image sectors supported by the bootloader. */
#define MCUBOOT_MAX_IMG_SECTORS    (FLASH_MAX_PARTITION_SIZE / \
                                    FLASH_AREA_IMAGE_SECTOR_SIZE)

/* Check that all the images can fit in the Flash area. */
#if (FLASH_AREA_13_OFFSET + FLASH_AREA_13_SIZE > FLASH_TOTAL_SIZE)
#error "Out of RSE Flash memory!"
#endif

#if (AP_FLASH_AREA_1_OFFSET + AP_FLASH_AREA_1_SIZE > AP_BOOT_FLASH_SIZE)
#error "Out of AP Flash memory!"
#endif

#define FLASH_AREA_IMAGE_PRIMARY(x) \
        (((x) == RSE_FIRMWARE_SECURE_ID)     ? FLASH_AREA_2_ID : \
         ((x) == RSE_FIRMWARE_NON_SECURE_ID) ? FLASH_AREA_3_ID : \
         ((x) == RSE_FIRMWARE_SCP_ID)        ? FLASH_AREA_6_ID : \
         ((x) == RSE_FIRMWARE_SI_CL0_ID)     ? FLASH_AREA_8_ID : \
         ((x) == RSE_FIRMWARE_SI_CL1_ID)     ? FLASH_AREA_10_ID : \
         ((x) == RSE_FIRMWARE_SI_CL2_ID)     ? FLASH_AREA_12_ID : \
         ((x) == RSE_FIRMWARE_AP_BL2_ID)     ? AP_FLASH_AREA_0_ID : \
                                              255)
#define FLASH_AREA_IMAGE_SECONDARY(x) \
        (((x) == RSE_FIRMWARE_SECURE_ID)     ? FLASH_AREA_4_ID : \
         ((x) == RSE_FIRMWARE_NON_SECURE_ID) ? FLASH_AREA_5_ID : \
         ((x) == RSE_FIRMWARE_SCP_ID)        ? FLASH_AREA_7_ID : \
         ((x) == RSE_FIRMWARE_SI_CL0_ID)     ? FLASH_AREA_9_ID : \
         ((x) == RSE_FIRMWARE_SI_CL1_ID)     ? FLASH_AREA_11_ID : \
         ((x) == RSE_FIRMWARE_SI_CL2_ID)     ? FLASH_AREA_13_ID : \
         ((x) == RSE_FIRMWARE_AP_BL2_ID)     ? AP_FLASH_AREA_1_ID : \
                                              255)

/* Scratch area is not used with RAM loading firmware upgrade */
#define FLASH_AREA_IMAGE_SCRATCH        255

/* Offset and size definition in flash area used by assemble.py */
#define SECURE_IMAGE_OFFSET             (0x0)
#define SECURE_IMAGE_MAX_SIZE           FLASH_S_PARTITION_SIZE

#define NON_SECURE_IMAGE_OFFSET         (SECURE_IMAGE_OFFSET + \
                                         SECURE_IMAGE_MAX_SIZE)
#define NON_SECURE_IMAGE_MAX_SIZE       FLASH_NS_PARTITION_SIZE

#define FLASH_SIC_TABLE_SIZE 0

/*
 * Flash device name used by BL2
 * Name is defined in flash driver file: Driver_Flash.c
 */
#define FLASH_DEV_NAME          Driver_FLASH0
#define FLASH_DEV_NAME_BL1      FLASH_DEV_NAME

/* Smallest flash programmable unit in bytes */
#define TFM_HAL_FLASH_PROGRAM_UNIT      (0x1)

/*
 * Application Processor Secure Flash used by BL2
 */
#define AP_FLASH_DEV_NAME       Driver_FLASH1

#define AP_FLASH_FIP_OFFSET     0x0UL
#define AP_FLASH_FIP_SIZE       0x200000UL

#define UUID_TRUSTED_BOOT_FIRMWARE_BL2 \
    ((uuid_t){{0x5f, 0xf9, 0xec, 0x0b}, {0x4d, 0x22}, \
              {0x3e, 0x4d}, 0xa5, 0x44, \
              {0xc3, 0x9d, 0x81, 0xc7, 0x3f, 0x0a}})

#define RSE_FLASH_IMG_OFFSET        0x0UL
#define RSE_FLASH_PS_OFFSET         RSE_FLASH_IMG_OFFSET + RSE_FLASH_IMG_SIZE
#define RSE_FLASH_ITS_OFFSET        RSE_FLASH_PS_OFFSET + RSE_FLASH_PS_SIZE

#define FLASH_DEV_NAME_SE_SECURE_FLASH  Driver_FLASH0

/*******************************/
/* PS */
/*******************************/
/* Protected Storage (PS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M PS Integration Guide.
 */
#define TFM_HAL_PS_FLASH_DRIVER FLASH_DEV_NAME_SE_SECURE_FLASH

/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address.
 */
/* Base address of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_ADDR      RSE_FLASH_PS_OFFSET
/* Size of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_SIZE      RSE_FLASH_PS_SIZE
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_PS_SECTORS_PER_BLOCK    (4)
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_PS_PROGRAM_UNIT         (1)

/*******************************/
/* ITS */
/*******************************/
/* Internal Trusted Storage (ITS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M ITS Integration Guide.
 */
#define TFM_HAL_ITS_FLASH_DRIVER FLASH_DEV_NAME_SE_SECURE_FLASH

/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address.
 */
/* Base address of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_ADDR     RSE_FLASH_ITS_OFFSET
/* Size of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_SIZE     RSE_FLASH_ITS_SIZE
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_ITS_SECTORS_PER_BLOCK   (1)
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_ITS_PROGRAM_UNIT        (1)

#include "flash_layout_common.h"

#endif /* __FLASH_LAYOUT_H__ */
