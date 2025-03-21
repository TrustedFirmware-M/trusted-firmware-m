/*
 * Copyright (c) 2017-2023 Arm Limited. All rights reserved.
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

#ifndef __REGION_DEFS_H__
#define __REGION_DEFS_H__

#include "flash_layout.h"

#define BL2_HEAP_SIZE           KB(4)
#define BL2_MSP_STACK_SIZE      KB(6)

#ifdef ENABLE_HEAP
#define S_HEAP_SIZE             (512)
#endif

#ifdef TFM_FIH_PROFILE_ON
#define S_MSP_STACK_SIZE        (0x00000A40)
#else
#define S_MSP_STACK_SIZE        KB(4)
#endif
#define S_PSP_STACK_SIZE        KB(2)

#define NS_HEAP_SIZE            KB(4)
#define NS_STACK_SIZE           (0x000001E0)


#ifdef BL2
#ifndef LINK_TO_SECONDARY_PARTITION
#define S_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_AREA_0_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET)
#else
#define S_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_AREA_2_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_0_OFFSET)
#endif /* !LINK_TO_SECONDARY_PARTITION */
#else
#define S_IMAGE_PRIMARY_PARTITION_OFFSET (0)
#endif /* BL2 */

#ifndef LINK_TO_SECONDARY_PARTITION

#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_0_OFFSET + FLASH_S_PARTITION_SIZE)
#else
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET + FLASH_S_PARTITION_SIZE)
#endif /* !LINK_TO_SECONDARY_PARTITION */

/* IMAGE_CODE_SIZE is the space available for the software binary image.
 * It is less than the FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE
 * because we reserve space for the image header and trailer introduced
 * by the bootloader.
 */
#if (!defined(MCUBOOT_IMAGE_NUMBER) || (MCUBOOT_IMAGE_NUMBER == 1)) && \
    (NS_IMAGE_PRIMARY_PARTITION_OFFSET > S_IMAGE_PRIMARY_PARTITION_OFFSET)
/* If secure image and nonsecure image are concatenated, and nonsecure image
 * locates at the higher memory range, then the secure image does not need
 * the trailer area.
 */
#define IMAGE_S_CODE_SIZE (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE)
#else
#define IMAGE_S_CODE_SIZE (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)
#endif

#define IMAGE_NS_CODE_SIZE  FLASH_NS_PARTITION_SIZE

/* Alias definitions for secure and non-secure areas*/
#define S_ROM_ALIAS(x)  (S_ROM_ALIAS_BASE + (x))
#define NS_ROM_ALIAS(x) (NS_ROM_ALIAS_BASE + (x))

#define S_RAM_ALIAS(x)  (S_RAM_ALIAS_BASE + (x))
#define NS_RAM_ALIAS(x) (NS_RAM_ALIAS_BASE + (x))

/* Secure regions */
#define S_IMAGE_PRIMARY_AREA_OFFSET (S_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define S_CODE_START    (S_ROM_ALIAS(S_IMAGE_PRIMARY_AREA_OFFSET))
#define S_CODE_SIZE     (IMAGE_S_CODE_SIZE)
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

/* Size of vector table: 69 interrupt handlers + 16 bytes of reserved space */
#define S_CODE_VECTOR_TABLE_SIZE    (0x00000124)

/* Set Secure FW SRAM Size */
#define S_TOTAL_DATA_SIZE  ( MAX32657_S_SRAM0_SIZE + \
                             MAX32657_S_SRAM1_SIZE + \
                             MAX32657_S_SRAM2_SIZE + \
                             MAX32657_S_SRAM3_SIZE + \
                             MAX32657_S_SRAM4_SIZE )

#define S_RAM_CODE_SIZE    ADI_S_RAM_CODE_SIZE  /* ramfuncs section size*/

#define S_DATA_START    (S_RAM_ALIAS(MAX32657_S_DATA_OFFSET))
#define S_DATA_SIZE     (S_TOTAL_DATA_SIZE - S_RAM_CODE_SIZE)
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

#define S_RAM_CODE_START  (S_DATA_START + S_DATA_SIZE) /* ramfuncs section start */
#define S_RAM_CODE_EXTRA_SECTION_NAME ".flashprog"  /* ramfuncs section name */

/* Non-secure regions
 * MPC block aligned 32KB, NS binary need to aling that
 */
#define NS_IMAGE_PRIMARY_AREA_OFFSET (NS_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define NS_CODE_START   (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_AREA_OFFSET))
#define NS_CODE_SIZE    (IMAGE_NS_CODE_SIZE)
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

#define NS_DATA_START   (NS_RAM_ALIAS( S_TOTAL_DATA_SIZE ))
#if defined(PSA_API_TEST_NS) && !defined(PSA_API_TEST_IPC)
#define DEV_APIS_TEST_NVMEM_REGION_SIZE  KB(1)
#define NS_DATA_SIZE    (TOTAL_RAM_SIZE - S_TOTAL_DATA_SIZE - DEV_APIS_TEST_NVMEM_REGION_SIZE)
#else
#define NS_DATA_SIZE    (TOTAL_RAM_SIZE - S_TOTAL_DATA_SIZE)
#endif
#define NS_DATA_LIMIT   (NS_DATA_START + NS_DATA_SIZE - 1)

/* NS partition information is used for MPC and SAU configuration */

#define MPC_CONFIG_BLOCK_SIZE KB(32) //Configurable block size by MPC is 32kb

#define NS_PARTITION_START (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_PARTITION_OFFSET))
#define NS_PARTITION_SIZE  (FLASH_NS_PARTITION_SIZE)
#define NS_PARTITION_END   (NS_PARTITION_START + NS_PARTITION_SIZE - 1)

/* Secondary partition for new images in case of firmware upgrade */
#define SECONDARY_PARTITION_START (NS_ROM_ALIAS(S_IMAGE_SECONDARY_PARTITION_OFFSET))
#define SECONDARY_PARTITION_SIZE  (FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE)

#ifdef BL2
/* Bootloader regions */
#define BL2_CODE_START    (S_ROM_ALIAS(FLASH_AREA_BL2_OFFSET))
#define BL2_CODE_SIZE     (FLASH_AREA_BL2_SIZE)
#define BL2_CODE_LIMIT    (BL2_CODE_START + BL2_CODE_SIZE - 1)

#define BL2_DATA_START    (S_RAM_ALIAS(0x0))
#define BL2_DATA_SIZE     (TOTAL_RAM_SIZE)
#define BL2_DATA_LIMIT    (BL2_DATA_START + BL2_DATA_SIZE - 1)
#endif /* BL2 */

/* Shared symbol area between bootloader and runtime firmware. Global variables
 * in the shared code can be placed here.
 */
#ifdef CODE_SHARING
#define SHARED_SYMBOL_AREA_BASE (S_RAM_ALIAS_BASE)
#define SHARED_SYMBOL_AREA_SIZE (0x00000020)
#else
#define SHARED_SYMBOL_AREA_BASE (S_RAM_ALIAS_BASE)
#define SHARED_SYMBOL_AREA_SIZE (0x00000000)
#endif /* CODE_SHARING */

/* Shared data area between bootloader and runtime firmware.
 * These areas are allocated at the beginning of the RAM, it is overlapping
 * with TF-M Secure code's MSP stack
 */
#define BOOT_TFM_SHARED_DATA_BASE  (SHARED_SYMBOL_AREA_BASE + SHARED_SYMBOL_AREA_SIZE)
#define BOOT_TFM_SHARED_DATA_SIZE  KB(1)
#define BOOT_TFM_SHARED_DATA_LIMIT (BOOT_TFM_SHARED_DATA_BASE + BOOT_TFM_SHARED_DATA_SIZE - 1)

#define SHARED_BOOT_MEASUREMENT_BASE BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE BOOT_TFM_SHARED_DATA_SIZE
#define SHARED_BOOT_MEASUREMENT_LIMIT BOOT_TFM_SHARED_DATA_LIMIT

#define PROVISIONING_BUNDLE_CODE_START (BL2_DATA_START + BL2_DATA_SIZE - KB(32))
#define PROVISIONING_BUNDLE_CODE_SIZE  (PROVISIONING_CODE_PADDED_SIZE)
/* The max size of the values(keys, seeds) that are going to be provisioned into the OTP. */
#define PROVISIONING_BUNDLE_VALUES_START (PROVISIONING_BUNDLE_CODE_START + PROVISIONING_BUNDLE_CODE_SIZE)
#define PROVISIONING_BUNDLE_VALUES_SIZE (PROVISIONING_VALUES_PADDED_SIZE)
#define PROVISIONING_BUNDLE_DATA_START (PROVISIONING_BUNDLE_VALUES_START + PROVISIONING_BUNDLE_VALUES_SIZE)
#define PROVISIONING_BUNDLE_DATA_SIZE (PROVISIONING_DATA_PADDED_SIZE)
#define PROVISIONING_BUNDLE_START (FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE)

#endif /* __REGION_DEFS_H__ */
