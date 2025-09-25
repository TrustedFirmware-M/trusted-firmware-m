/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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
 *  0x0_7000 BL2 - MCUBoot primary slot   (128 KB)
 *  0x2_7000 Secure image  primary slot   (256 KB)
 *  0x6_7000 SI CL0        primary slot   (1024 KB)
 * 0x16_7000 BL2 - MCUBoot secondary slot (128 KB)
 * 0x18_7000 Secure image  secondary slot (256 KB)
 * 0x1C_7000 SI CL0        secondary slot (1024 KB)
 *
 * Flash layout on AP Secure flash with BL2 (multiple image boot):
 *
 * Offset    Image (Size)
 *  0x0_7000 FIP primary slot   (2304 KB)
 * 0x24_7000 FIP secondary slot (2304 KB)
 */

/*
 * This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_retarget.h to access flash related defines. To resolve this
 * some of the values are redefined here with different names, these are marked
 * with comment.
 */

#define AP_FLASH_FIP_OFFSET         0x7000UL
#define AP_FLASH_FIP_SIZE           0x240000UL

/* Size of a Secure and of a Non-secure image */
#define FLASH_BL2_PARTITION_SIZE        (SIZE_DEF_BL2_IMAGE) /* BL2 partition */
#define FLASH_S_PARTITION_SIZE          (SIZE_DEF_S_IMAGE)   /* S   partition */
#define FLASH_NS_PARTITION_SIZE         (SIZE_DEF_NS_IMAGE)  /* NS  partition */
#define FLASH_AP_FIP_PARTITION_SIZE     (AP_FLASH_FIP_SIZE) /* AP FIP partition */
#define FLASH_SI_CL0_PARTITION_SIZE     (SIZE_DEF_SI_CL0_IMAGE) /* SI CL0 partition */
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

/* Primary Bank */
/* BL2 primary slot */
#define FLASH_AREA_0_ID            (1)
#define FLASH_AREA_0_OFFSET        (0x7000UL)
#define FLASH_AREA_0_SIZE          (FLASH_BL2_PARTITION_SIZE)
/* Secure image primary slot. */
#define FLASH_AREA_2_ID            (FLASH_AREA_0_ID + 2)
#define FLASH_AREA_2_OFFSET        (FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE)
#define FLASH_AREA_2_SIZE          (FLASH_S_PARTITION_SIZE)
/* SI CL0 image primary slot */
#define FLASH_AREA_4_ID            (FLASH_AREA_2_ID + 2)
#define FLASH_AREA_4_OFFSET        (FLASH_AREA_2_OFFSET + FLASH_AREA_2_SIZE)
#define FLASH_AREA_4_SIZE          (FLASH_SI_CL0_PARTITION_SIZE)

/* Secondary Bank */
/* BL2 secondary slot */
#define FLASH_AREA_1_ID            (FLASH_AREA_0_ID + 1)
#define FLASH_AREA_1_OFFSET        (FLASH_AREA_4_OFFSET + FLASH_AREA_4_SIZE)
#define FLASH_AREA_1_SIZE          (FLASH_BL2_PARTITION_SIZE)
/* Secure image secondary slot. */
#define FLASH_AREA_3_ID            (FLASH_AREA_1_ID + 2)
#define FLASH_AREA_3_OFFSET        (FLASH_AREA_1_OFFSET + FLASH_AREA_1_SIZE)
#define FLASH_AREA_3_SIZE          (FLASH_S_PARTITION_SIZE)
/* SI CL0 image secondary slot */
#define FLASH_AREA_5_ID            (FLASH_AREA_3_ID + 2)
#define FLASH_AREA_5_OFFSET        (FLASH_AREA_3_OFFSET + FLASH_AREA_3_SIZE)
#define FLASH_AREA_5_SIZE          (FLASH_SI_CL0_PARTITION_SIZE)

/* AP FIP image primary slot */
#define AP_FLASH_AREA_0_ID          (FLASH_AREA_5_ID + 1)
#define AP_FLASH_AREA_0_OFFSET      (AP_FLASH_FIP_OFFSET)
#define AP_FLASH_AREA_0_SIZE        (FLASH_AP_FIP_PARTITION_SIZE)
/* AP FIP image secondary slot */
#define AP_FLASH_AREA_1_ID          (AP_FLASH_AREA_0_ID + 1)
#define AP_FLASH_AREA_1_OFFSET      (AP_FLASH_AREA_0_OFFSET + \
                                     AP_FLASH_AREA_0_SIZE)
#define AP_FLASH_AREA_1_SIZE        (FLASH_AP_FIP_PARTITION_SIZE)

/* Maximum number of image sectors supported by the bootloader. */
#define MCUBOOT_MAX_IMG_SECTORS    (FLASH_MAX_PARTITION_SIZE / \
                                    FLASH_AREA_IMAGE_SECTOR_SIZE)

/* Check that all the images can fit in the Flash area. */
#if (FLASH_AREA_5_OFFSET + FLASH_AREA_5_SIZE > FLASH_TOTAL_SIZE)
#error "Out of RSE Flash memory!"
#endif

#if (AP_FLASH_AREA_1_OFFSET + AP_FLASH_AREA_1_SIZE > AP_BOOT_FLASH_SIZE)
#error "Out of AP Flash memory!"
#endif

#define FLASH_AREA_IMAGE_PRIMARY(x) \
        (((x) == RSE_FIRMWARE_SECURE_ID)     ? FLASH_AREA_2_ID : \
         ((x) == RSE_FIRMWARE_SI_CL0_ID)     ? FLASH_AREA_4_ID : \
         ((x) == RSE_FIRMWARE_AP_BL2_ID)     ? AP_FLASH_AREA_0_ID : \
                                              255)
#define FLASH_AREA_IMAGE_SECONDARY(x) \
        (((x) == RSE_FIRMWARE_SECURE_ID)     ? FLASH_AREA_3_ID : \
         ((x) == RSE_FIRMWARE_SI_CL0_ID)     ? FLASH_AREA_5_ID : \
         ((x) == RSE_FIRMWARE_AP_BL2_ID)     ? AP_FLASH_AREA_1_ID : \
                                              255)

/* Scratch area is not used with RAM loading firmware upgrade */
#define FLASH_AREA_IMAGE_SCRATCH        255

/* Offset and size definition in flash area used by assemble.py */
#define SECURE_IMAGE_OFFSET             (0x0)
#define SECURE_IMAGE_MAX_SIZE           FLASH_S_PARTITION_SIZE

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

#define UUID_TRUSTED_BOOT_FIRMWARE_BL2 \
    ((uuid_t){{0x5f, 0xf9, 0xec, 0x0b}, {0x4d, 0x22}, \
              {0x3e, 0x4d}, 0xa5, 0x44, \
              {0xc3, 0x9d, 0x81, 0xc7, 0x3f, 0x0a}})

#define RSE_FLASH_IMG_OFFSET        FLASH_AREA_0_OFFSET
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
