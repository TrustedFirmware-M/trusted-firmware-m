/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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

#ifndef __REGION_DEFS_H__
#define __REGION_DEFS_H__

#include "flash_layout.h"
#include "platform_base_address.h"
#include "bl1_2_config.h"

#define BL1_1_HEAP_SIZE         (0x0001000)
#define BL1_1_MSP_STACK_SIZE    (0x0001800)

#define BL1_2_HEAP_SIZE         (0x0001000)
#define BL1_2_MSP_STACK_SIZE    (0x0001800)

#define BL2_HEAP_SIZE           (0x0001000)
#define BL2_MSP_STACK_SIZE      (0x0001800)

#ifdef ENABLE_HEAP
#define S_HEAP_SIZE             (0x0000200)
#endif

#define S_MSP_STACK_SIZE        (0x0000800)
#define S_PSP_STACK_SIZE        (0x0000800)

#define NS_HEAP_SIZE            (0x0001000)
#define NS_STACK_SIZE           (0x0001000)

#ifdef BL2
#ifndef LINK_TO_SECONDARY_PARTITION
#define S_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_AREA_0_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET)
#else
#define S_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_AREA_2_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_0_OFFSET)
#endif /* !LINK_TO_SECONDARY_PARTITION */
#else
#define S_IMAGE_PRIMARY_PARTITION_OFFSET (0x0)
#endif /* BL2 */

#ifndef LINK_TO_SECONDARY_PARTITION
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_0_OFFSET \
                                           + FLASH_S_PARTITION_SIZE)
#else
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET \
                                           + FLASH_S_PARTITION_SIZE)
#endif /* !LINK_TO_SECONDARY_PARTITION */

/* Boot partition structure if MCUBoot is used:
 * 0x0_0000 Bootloader header
 * 0x0_0400 Image area
 * 0x5_0000 Trailer
 */
/* IMAGE_CODE_SIZE is the space available for the software binary image.
 * It is less than the FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE
 * because we reserve space for the image header and trailer introduced
 * by the bootloader.
 */
#define IMAGE_BL2_CODE_SIZE \
            (FLASH_AREA_BL2_SIZE - TFM_BL1_2_HEADER_MAX_SIZE)

#if (!defined(MCUBOOT_IMAGE_NUMBER) || (MCUBOOT_IMAGE_NUMBER == 1)) && \
    (NS_IMAGE_PRIMARY_PARTITION_OFFSET > S_IMAGE_PRIMARY_PARTITION_OFFSET)
/* If secure image and nonsecure image are concatenated, and nonsecure image
 * locates at the higher memory range, then the secure image does not need
 * the trailer area.
 */
#define IMAGE_S_CODE_SIZE \
            (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE)
#else
#define IMAGE_S_CODE_SIZE \
            (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)
#endif

#define IMAGE_NS_CODE_SIZE \
            (FLASH_NS_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)

/* Secure regions */
#define S_IMAGE_PRIMARY_AREA_OFFSET \
             (S_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
/* Secure Code stored in Code SRAM */
#define S_CODE_START    ((QSPI_SRAM_BASE_S) + (S_IMAGE_PRIMARY_AREA_OFFSET))
#define S_CODE_SIZE     (IMAGE_S_CODE_SIZE)
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#if (S_DATA_OVERALL_SIZE > ISRAM0_SIZE)
#error "Secure data must fit in ISRAM0!"
#endif

/* Secure Data stored in ISRAM0 */
#define S_DATA_START    (ISRAM0_BASE_S)
#define S_DATA_SIZE     (S_DATA_OVERALL_SIZE - S_RAM_CODE_SIZE)
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

/* Size of vector table: 247 interrupt handlers + 4 bytes MPS initial value */
#define S_CODE_VECTOR_TABLE_SIZE    (0x3E0)

/* Non-secure regions */
#define NS_IMAGE_PRIMARY_AREA_OFFSET \
                        (NS_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
/* Non-Secure Code stored in Code SRAM memory */
#define NS_CODE_START   (QSPI_SRAM_BASE_NS + (NS_IMAGE_PRIMARY_AREA_OFFSET))
#define NS_CODE_SIZE    (IMAGE_NS_CODE_SIZE)
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

/* Non-Secure Data stored in ISRAM0+ISRAM1 */
#define NS_DATA_START   (ISRAM0_BASE_NS + S_DATA_OVERALL_SIZE)
#define NS_DATA_SIZE    ((ISRAM0_SIZE - S_DATA_OVERALL_SIZE) + ISRAM1_SIZE)
#define NS_DATA_LIMIT   (NS_DATA_START + NS_DATA_SIZE - 1)

/* NS partition information is used for MPC and SAU configuration */
#define NS_PARTITION_START \
            ((QSPI_SRAM_BASE_NS) + (NS_IMAGE_PRIMARY_PARTITION_OFFSET))
#define NS_PARTITION_SIZE (FLASH_NS_PARTITION_SIZE)

/* Secondary partition for new images in case of firmware upgrade */
#define SECONDARY_PARTITION_START \
            ((QSPI_SRAM_BASE_NS) + (S_IMAGE_SECONDARY_PARTITION_OFFSET))
#define SECONDARY_PARTITION_SIZE (FLASH_S_PARTITION_SIZE + \
                                  FLASH_NS_PARTITION_SIZE)

/* Code SRAM area */
#define S_RAM_CODE_SIZE          (0x00004000) /* 16 KB (SRAM MPC block size)*/
#define S_RAM_CODE_START         (S_DATA_START + S_DATA_SIZE)

#ifdef BL1
#define BL1_1_CODE_START  (BOOT_ROM_BASE_S)
#define BL1_1_CODE_SIZE   (BOOT_ROM_SIZE)
#define BL1_1_CODE_LIMIT  (BL1_1_CODE_START + BL1_1_CODE_SIZE - 1)

#define BL1_2_CODE_START  (SRAM_BASE_S)
#define BL1_2_CODE_SIZE   (0x2000) /* 8 KiB */
#define BL1_2_CODE_LIMIT  (BL1_2_CODE_START + BL1_2_CODE_SIZE - 1)

#define BL1_1_DATA_START  (BOOT_TFM_SHARED_DATA_BASE + BOOT_TFM_SHARED_DATA_SIZE)
#define BL1_1_DATA_SIZE   (0x20000)
#define BL1_1_DATA_LIMIT  (BL1_1_DATA_START + BL1_1_DATA_SIZE - 1)

/* The BL1_1 and BL1_2 data region cannot overlap because the
 * used shared symbols that are located at BL1_1's data region.
 */
#define BL1_2_DATA_START  (BL1_1_DATA_START + BL1_1_DATA_SIZE)
#define BL1_2_DATA_SIZE   (0x20000)
#define BL1_2_DATA_LIMIT  (BL1_2_DATA_START + BL1_2_DATA_SIZE - 1)
#endif

#ifdef BL2
/* Bootloader regions */
/* Use SRAM to store Bootloader */

#define BL2_IMAGE_START   (BL1_2_CODE_START + BL1_2_CODE_SIZE)
#define BL2_CODE_START    (BL2_IMAGE_START + TFM_BL1_2_HEADER_MAX_SIZE)
#define BL2_CODE_SIZE     (FLASH_AREA_BL2_SIZE)
#define BL2_CODE_LIMIT    (BL2_CODE_START + BL2_CODE_SIZE - 1)

/* Bootloader uses same memory as for secure image */
#define BL2_DATA_START    (S_DATA_START)
#define BL2_DATA_SIZE     (S_DATA_SIZE)
#define BL2_DATA_LIMIT    (BL2_DATA_START + BL2_DATA_SIZE - 1)
#endif /* BL2 */

/* Shared data area between bootloader and runtime firmware.
 * Shared data area is allocated at the beginning of the RAM, it is overlapping
 * with TF-M Secure code's MSP stack
 */
#define BOOT_TFM_SHARED_DATA_BASE S_DATA_START
#define BOOT_TFM_SHARED_DATA_SIZE (0x400)
#define BOOT_TFM_SHARED_DATA_LIMIT (BOOT_TFM_SHARED_DATA_BASE + \
                                    BOOT_TFM_SHARED_DATA_SIZE - 1)
#define SHARED_BOOT_MEASUREMENT_BASE BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE BOOT_TFM_SHARED_DATA_SIZE
#define SHARED_BOOT_MEASUREMENT_LIMIT BOOT_TFM_SHARED_DATA_LIMIT

#define PROVISIONING_BUNDLE_CODE_START (BL2_IMAGE_START + BL2_CODE_SIZE)
#define PROVISIONING_BUNDLE_CODE_SIZE  (PROVISIONING_CODE_PADDED_SIZE)
#define PROVISIONING_BUNDLE_VALUES_START (BL1_2_DATA_START)
#define PROVISIONING_BUNDLE_VALUES_SIZE (PROVISIONING_VALUES_PADDED_SIZE)
#define PROVISIONING_BUNDLE_DATA_START (PROVISIONING_BUNDLE_VALUES_START + \
                                        PROVISIONING_BUNDLE_VALUES_SIZE)
#define PROVISIONING_BUNDLE_DATA_SIZE (PROVISIONING_DATA_PADDED_SIZE)

#define CM_PROVISIONING_BUNDLE_START (PROVISIONING_BUNDLE_CODE_START + \
                                      PROVISIONING_BUNDLE_CODE_SIZE)
#define CM_PROVISIONING_BUNDLE_SIZE (PROVISIONING_BUNDLE_CODE_SIZE + \
                                     PROVISIONING_BUNDLE_VALUES_SIZE + \
                                     PROVISIONING_BUNDLE_DATA_SIZE + \
                                     0x200) // Add 0x200 because the CM_PROVISIONING_BUNDLE has some overhead

#define DM_PROVISIONING_BUNDLE_START (CM_PROVISIONING_BUNDLE_START + CM_PROVISIONING_BUNDLE_SIZE)
#define DM_PROVISIONING_BUNDLE_SIZE (PROVISIONING_BUNDLE_CODE_SIZE + \
                                     PROVISIONING_BUNDLE_VALUES_SIZE + \
                                     PROVISIONING_BUNDLE_DATA_SIZE + \
                                     0x200) // Add 0x200 because the DM_PROVISIONING_BUNDLE has some overhead


#ifdef BL2
#define BL2_IMAGE_LOAD_ADDRESS (DM_PROVISIONING_BUNDLE_START + DM_PROVISIONING_BUNDLE_SIZE)
#endif /* BL2 */

#define OTP_SAM_CONFIGURATION_SIZE_BYTES 0x60

#if ((OTP_SAM_CONFIGURATION_SIZE_BYTES % 4) != 0)
#error "OTP_SAM_CONFIGURATION_SIZE_BYTES must be divisible by 4!"
#endif

#endif /* __REGION_DEFS_H__ */
