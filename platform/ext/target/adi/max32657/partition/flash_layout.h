/*
 * Copyright (c) 2018-2022 Arm Limited. All rights reserved.
 * Copyright 2019-2023 NXP. All rights reserved.
 * Copyright (C) 2024-2025 Analog Devices, Inc.
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

/* Flash layout on MAX32657 with BL2 (multiple image boot):
 *
 * Secure flash address which 28th bit 1 is logical address
 *
 * 0X0100_0000 BL2 - MCUBoot (64KB)
 * 0x0101_0000 Secure image     primary slot (320KB)
 * 0x0106_0000 Non-secure image primary slot (576KB)
 * 0x010F_0000 Secure image     secondary slot (0KB)
 * 0x010F_0000 Non-secure image secondary slot (0KB)
 * 0x010F_0000 Scratch area (0)
 * 0x010F_0000 Protected Storage Area (0)
 * 0x010F_0000 Internal Trusted Storage Area (16 KB)
 * 0x010F_4000 OTP / NV counters area (16 KB)
 * 0x010F_8000 Unused (32KB)
 *
 * Flash layout on MAX32657 with BL2 (single image boot):
 *
 * 0X0100_0000 BL2 - MCUBoot (64KB)
 * 0x0101_0000 Primary image area (896KB):
 *    0x0101_0000 Secure     image primary
 *    0x0106_0000 Non-secure image primary
 * 0x010F_0000 Secondary image area (0KB):
 *    0x010F_0000 Secure     image secondary
 *    0x010F_0000 Non-secure image secondary
 * 0x010F_0000 Scratch area (0)
 * 0x010F_0000 Protected Storage Area (0)
 * 0x010F_0000 Internal Trusted Storage Area (16 KB)
 * 0x010F_4000 OTP / NV counters area (16 KB)
 * 0x010F_8000 Unused
 *
 * Flash layout on MAX32657, if BL2 not defined:
 *
 * 0X0100_0000 Secure     image (512KB)
 * 0X0108_0000 Non-secure image (512KB)
 */

/* This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_base_address.h to access flash related defines. To resolve
 * this some of the values are redefined here with different names, these are
 * marked with comment.
 */

#ifndef KB
#define KB(x)   ((x) * 1024)
#endif

/* Size of a Secure and of a Non-secure image */
#define FLASH_S_PARTITION_SIZE          ADI_FLASH_S_PARTITION_SIZE
#define FLASH_NS_PARTITION_SIZE         ADI_FLASH_NS_PARTITION_SIZE

#if (FLASH_S_PARTITION_SIZE > FLASH_NS_PARTITION_SIZE)
#define FLASH_MAX_PARTITION_SIZE FLASH_S_PARTITION_SIZE
#else
#define FLASH_MAX_PARTITION_SIZE FLASH_NS_PARTITION_SIZE
#endif
/* Sector size of the flash hardware; same as FLASH0_SECTOR_SIZE */
#define FLASH_AREA_IMAGE_SECTOR_SIZE    KB(8)
/* Same as FLASH0_SIZE */
#define FLASH_TOTAL_SIZE                KB(1024)

/* Flash layout info for BL2 bootloader */
/* Same as FLASH0_BASE_S */
#define FLASH_BASE_ADDRESS              (0x11000000)

/* Offset and size definitions of the flash partitions that are handled by the
 * bootloader. The image swapping is done between IMAGE_PRIMARY and
 * IMAGE_SECONDARY, SCRATCH is used as a temporary storage during image
 * swapping.
 */
#define FLASH_AREA_BL2_OFFSET      (0)
#define FLASH_AREA_BL2_SIZE        ADI_FLASH_AREA_BL2_SIZE

#if !defined(MCUBOOT_IMAGE_NUMBER) || (MCUBOOT_IMAGE_NUMBER == 1)
/* Secure + Non-secure image primary slot */
#define FLASH_AREA_0_ID            (1)
#define FLASH_AREA_0_OFFSET        (FLASH_AREA_BL2_OFFSET + FLASH_AREA_BL2_SIZE)
#define FLASH_AREA_0_SIZE          (FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE)
/* Secure + Non-secure secondary slot */
#define FLASH_AREA_2_ID            (FLASH_AREA_0_ID + 1)
#define FLASH_AREA_2_OFFSET        (FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE)
#define FLASH_AREA_2_SIZE          (0)
/* Not used (scratch area), the 'Swap' firmware upgrade operation is not
 * supported on MAX32657 */
#define FLASH_AREA_SCRATCH_ID      (FLASH_AREA_2_ID + 1)
#define FLASH_AREA_SCRATCH_OFFSET  (FLASH_AREA_2_OFFSET + FLASH_AREA_2_SIZE)
#define FLASH_AREA_SCRATCH_SIZE    (0)
/* The maximum number of status entries supported by the bootloader. */
#define MCUBOOT_STATUS_MAX_ENTRIES (0)
/* Maximum number of image sectors supported by the bootloader. */
#define MCUBOOT_MAX_IMG_SECTORS    ((FLASH_S_PARTITION_SIZE + \
                                     FLASH_NS_PARTITION_SIZE) / \
                                    FLASH_AREA_IMAGE_SECTOR_SIZE)
#elif (MCUBOOT_IMAGE_NUMBER == 2)
/* Secure image primary slot */
#define FLASH_AREA_0_ID            (1)
#define FLASH_AREA_0_OFFSET        (FLASH_AREA_BL2_OFFSET + FLASH_AREA_BL2_SIZE)
#define FLASH_AREA_0_SIZE          (FLASH_S_PARTITION_SIZE)
/* Non-secure image primary slot */
#define FLASH_AREA_1_ID            (FLASH_AREA_0_ID + 1)
#define FLASH_AREA_1_OFFSET        (FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE)
#define FLASH_AREA_1_SIZE          (FLASH_NS_PARTITION_SIZE)
/* Secure image secondary slot */
#define FLASH_AREA_2_ID            (FLASH_AREA_1_ID + 1)
#define FLASH_AREA_2_OFFSET        (FLASH_AREA_1_OFFSET + FLASH_AREA_1_SIZE)
#define FLASH_AREA_2_SIZE          (0)
/* Non-secure image secondary slot */
#define FLASH_AREA_3_ID            (FLASH_AREA_2_ID + 1)
#define FLASH_AREA_3_OFFSET        (FLASH_AREA_2_OFFSET + FLASH_AREA_2_SIZE)
#define FLASH_AREA_3_SIZE          (0)
/* Scratch area */
/* FIXME: remove scartch area. Currently removing them yields BL2 error*/
#define FLASH_AREA_SCRATCH_ID      (FLASH_AREA_3_ID + 1)
#define FLASH_AREA_SCRATCH_OFFSET  (FLASH_AREA_3_OFFSET + FLASH_AREA_3_SIZE)
#define FLASH_AREA_SCRATCH_SIZE    (0)
/* The maximum number of status entries supported by the bootloader. */
#define MCUBOOT_STATUS_MAX_ENTRIES (0)
/* Maximum number of image sectors supported by the bootloader. */
#define MCUBOOT_MAX_IMG_SECTORS    (FLASH_MAX_PARTITION_SIZE / FLASH_AREA_IMAGE_SECTOR_SIZE)
#else /* MCUBOOT_IMAGE_NUMBER > 2 */
#error "Only MCUBOOT_IMAGE_NUMBER 1 and 2 are supported!"
#endif /* MCUBOOT_IMAGE_NUMBER */

/* Protected Storage (PS) Service definitions */
#define FLASH_PS_AREA_OFFSET            (FLASH_AREA_SCRATCH_OFFSET + FLASH_AREA_SCRATCH_SIZE)
#define FLASH_PS_AREA_SIZE              ADI_FLASH_PS_AREA_SIZE

/* Internal Trusted Storage (ITS) Service definitions */
#define FLASH_ITS_AREA_OFFSET           (FLASH_PS_AREA_OFFSET + FLASH_PS_AREA_SIZE)
#define FLASH_ITS_AREA_SIZE             ADI_FLASH_ITS_AREA_SIZE

/* Placing OTP backup area in Flash because of limited availability of Secure Flash Info area */
#define FLASH_OTP_NV_COUNTERS_AREA_OFFSET  (FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE)
#define FLASH_OTP_NV_COUNTERS_AREA_SIZE    (FLASH_AREA_IMAGE_SECTOR_SIZE*2)
#define FLASH_OTP_NV_COUNTERS_SECTOR_SIZE  FLASH_AREA_IMAGE_SECTOR_SIZE


/* Offset and size definition in flash area used by assemble.py */
#define SECURE_IMAGE_OFFSET             (0)
#define SECURE_IMAGE_MAX_SIZE           FLASH_S_PARTITION_SIZE

#define NON_SECURE_IMAGE_OFFSET         (SECURE_IMAGE_OFFSET + SECURE_IMAGE_MAX_SIZE)
#define NON_SECURE_IMAGE_MAX_SIZE       FLASH_NS_PARTITION_SIZE

/* Flash device name used by BL2 */
#define FLASH_DEV_NAME Driver_FLASH0
/* Smallest flash programmable unit in bytes - MAX32657: 128 bits */
#define TFM_HAL_FLASH_PROGRAM_UNIT       (0x00000010)

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
#define TFM_HAL_PS_PROGRAM_UNIT       (0x00000010)

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
#define TFM_HAL_ITS_PROGRAM_UNIT       (0x00000010) // Supports 128 bit writes

/* OTP / NV counter definitions */
#define TFM_OTP_NV_COUNTERS_AREA_SIZE (FLASH_OTP_NV_COUNTERS_AREA_SIZE / 2)
#define TFM_OTP_NV_COUNTERS_AREA_ADDR FLASH_OTP_NV_COUNTERS_AREA_OFFSET
#define TFM_OTP_NV_COUNTERS_SECTOR_SIZE FLASH_OTP_NV_COUNTERS_SECTOR_SIZE
#define TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR (TFM_OTP_NV_COUNTERS_AREA_ADDR + TFM_OTP_NV_COUNTERS_AREA_SIZE)

/* Flash and RAM configurations for secure and non-secure image partitions*/

#define S_ROM_ALIAS_BASE  (0x11000000)
#define NS_ROM_ALIAS_BASE (0X01000000)

#define S_RAM_ALIAS_BASE  (0x30000000)
#define NS_RAM_ALIAS_BASE (0x20000000)

#define TOTAL_ROM_SIZE FLASH_TOTAL_SIZE
#define TOTAL_RAM_SIZE KB(256)

// SRAM_0
#define MAX32657_SRAM0_OFFSET  0
#define MAX32657_SRAM0_SIZE    KB(32)
// SRAM_1
#define MAX32657_SRAM1_OFFSET  0x00008000UL
#define MAX32657_SRAM1_SIZE    KB(32)
// SRAM_2
#define MAX32657_SRAM2_OFFSET  0x00010000UL
#define MAX32657_SRAM2_SIZE    KB(64)
// SRAM_3
#define MAX32657_SRAM3_OFFSET  0x00020000UL
#define MAX32657_SRAM3_SIZE    KB(64)
// SRAM_4
#define MAX32657_SRAM4_OFFSET  0x00030000UL
#define MAX32657_SRAM4_SIZE    KB(64)


#if defined(ADI_NS_SRAM_0)
    #define MAX32657_S_SRAM0_SIZE 0
#else
    #define MAX32657_S_SRAM0_SIZE MAX32657_SRAM0_SIZE
#endif

#if defined(ADI_NS_SRAM_1)
    #define MAX32657_S_SRAM1_SIZE 0
#else
    #define MAX32657_S_SRAM1_SIZE MAX32657_SRAM1_SIZE
#endif

#if defined(ADI_NS_SRAM_2)
    #define MAX32657_S_SRAM2_SIZE 0
#else
    #define MAX32657_S_SRAM2_SIZE MAX32657_SRAM2_SIZE
#endif

#if defined(ADI_NS_SRAM_3)
    #define MAX32657_S_SRAM3_SIZE 0
#else
    #define MAX32657_S_SRAM3_SIZE MAX32657_SRAM3_SIZE
#endif

#if defined(ADI_NS_SRAM_4)
    #define MAX32657_S_SRAM4_SIZE 0
#else
    #define MAX32657_S_SRAM4_SIZE MAX32657_SRAM4_SIZE
#endif

/* RAM shall be defined sequential */
#if !defined(ADI_NS_SRAM_0)
    // SRAM0 on secure world
    #define MAX32657_S_DATA_OFFSET MAX32657_SRAM0_OFFSET
#elif !defined(ADI_NS_SRAM_1)
    // SRAM1 on secure world
    #define MAX32657_S_DATA_OFFSET MAX32657_SRAM1_OFFSET
#elif !defined(ADI_NS_SRAM_2)
    // SRAM2 on secure world
    #define MAX32657_S_DATA_OFFSET MAX32657_SRAM2_OFFSET
#elif !defined(ADI_NS_SRAM_3)
    // SRAM3 on secure world
    #define MAX32657_S_DATA_OFFSET MAX32657_SRAM3_OFFSET
#elif !defined(ADI_NS_SRAM_4)
    // SRAM4 on secure world
    #define MAX32657_S_DATA_OFFSET MAX32657_SRAM4_OFFSET
#else
    #error "SRAM Not Defined for TF-M"
#endif

#endif /* __FLASH_LAYOUT_H__ */
