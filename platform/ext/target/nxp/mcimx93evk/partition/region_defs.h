/*
 * Copyright (c) 2017-2023 Arm Limited. All rights reserved.
 * Copyright 2019-2025 NXP
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

#ifdef ENABLE_HEAP
    #define S_HEAP_SIZE         (0x0001000)
#endif

#define S_MSP_STACK_SIZE        (0x0001200)
#define S_PSP_STACK_SIZE        (0x0000800)

#define NS_HEAP_SIZE            (0x0004000)
#define NS_STACK_SIZE           (0x0002000)

/* Boot Image is exoected at offset 0 */
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
/* For Image on RAM, FLASH_S_PARTITION_SIZE is marked as 0 */
#if defined(FLASH_S_PARTITION_SIZE) && (FLASH_S_PARTITION_SIZE != 0)
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_0_OFFSET \
                                           + FLASH_S_PARTITION_SIZE)
#else

#ifdef NS_PARTITION_ON_OCRAM
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (0)
#else
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (IMAGE_S_CODE_SIZE)
#endif

#endif /* (FLASH_S_PARTITION_SIZE != 0) */

#else
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET \
                                           + FLASH_S_PARTITION_SIZE)
#endif /* !LINK_TO_SECONDARY_PARTITION */

/* Boot partition structure if MCUBoot is used:
 * 0x0_0000 Bootloader header
 * 0x0_0400 Image area
 * 0x1_FC00 Trailer
 */
/* IMAGE_CODE_SIZE is the space available for the software binary image.
 * It is less than the FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE
 * because we reserve space for the image header and trailer introduced
 * by the bootloader.
 */
#ifdef BL2
#define BL2_HEADER_SIZE      (0x400)       /* 1 KB */
#define BL2_TRAILER_SIZE     (0x400)       /* 1 KB */
#if (MCUBOOT_IMAGE_NUMBER == 1) && \
    (NS_IMAGE_PRIMARY_PARTITION_OFFSET > S_IMAGE_PRIMARY_PARTITION_OFFSET)
/* If secure image and nonsecure image are concatenated, and nonsecure image
 * locates at the higher memory range, then the secure image does not need
 * the trailer area.
 */
#define IMAGE_S_CODE_SIZE \
            (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE)
#endif
#else
#ifndef BL2_HEADER_SIZE /* if BL2_HEADER_SIZE is not defined by config.cmake, then define it*/
/* No header if no bootloader, but keep IMAGE_CODE_SIZE the same */
#define BL2_HEADER_SIZE      (0x0)
#endif /* !def BL2_HEADER_SIZE*/
#ifndef BL2_TRAILER_SIZE
#define BL2_TRAILER_SIZE     (0x0)
#endif /* !def BL2_TRAILER_SIZE*/
#endif /* BL2 */

#ifndef IMAGE_S_CODE_SIZE
#define IMAGE_S_CODE_SIZE \
            (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)
#endif

#ifndef IMAGE_NS_CODE_SIZE
#define IMAGE_NS_CODE_SIZE \
            (FLASH_NS_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)
#endif

#define CMSE_VENEER_REGION_SIZE     (0x340)

/* Alias definitions for secure and non-secure areas*/
#define S_ROM_ALIAS(x)  (S_ROM_ALIAS_BASE + (x))
#define NS_ROM_ALIAS(x) (NS_ROM_ALIAS_BASE + (x))

#define S_RAM_ALIAS(x)  (S_RAM_ALIAS_BASE + (x))
#define NS_RAM_ALIAS(x) (NS_RAM_ALIAS_BASE + (x))

#ifdef NS_PARTITION_ON_OCRAM
#define S_DATA_OFFSET    0x0				/* This offset is on System TCM fully dedicated for Secure data */
#define NS_DATA_OFFSET   ( NS_CODE_SIZE )	/* Offset on OCRAM for NS Data. Initial chumk of OCRAM is reserved for code. Data is placed  right after that */
#else
//#define S_DATA_OFFSET   0xD000
//#define NS_DATA_OFFSET   0x0

#define S_DATA_OFFSET	RESERVED_RAM_SIZE
#define NS_DATA_OFFSET  0x17000
#endif

/* Secure regions */
#define S_IMAGE_PRIMARY_AREA_OFFSET \
             (S_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define S_CODE_START    (S_ROM_ALIAS(S_IMAGE_PRIMARY_AREA_OFFSET))
#define S_CODE_SIZE     (IMAGE_S_CODE_SIZE)
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_START                    (S_RAM_ALIAS(S_DATA_OFFSET + RESERVED_RAM_SIZE))

#ifdef NS_PARTITION_ON_OCRAM
#define S_DATA_SIZE                     (TOTAL_RAM_S_SIZE - RESERVED_RAM_SIZE)   /*  64K out of 128K TCM for secure */
#else
//#define S_DATA_SIZE                     (0x13000 - RESERVED_RAM_SIZE)   /*  64K out of 128K TCM for secure */
#define S_DATA_SIZE                     (NS_DATA_OFFSET - RESERVED_RAM_SIZE)   /*  92K out of 128K TCM for secure */
#endif

#define S_DATA_LIMIT                    (S_DATA_START + S_DATA_SIZE - 1)

/* Size of vector table: 284 interrupt handlers(see g_pfnVectors definition) + 4 bytes MPS initial value ((284*4 + 4) = 1140 = 0x474) */
#define S_CODE_VECTOR_TABLE_SIZE    (0x474)

/* Non-secure regions */
#define NS_IMAGE_PRIMARY_AREA_OFFSET \
                        (NS_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define NS_CODE_START   (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_AREA_OFFSET))
#define NS_CODE_SIZE    (IMAGE_NS_CODE_SIZE)
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

//#define NS_DATA_START                   (NS_RAM_ALIAS(S_DATA_OFFSET + RESERVED_RAM_SIZE + S_DATA_SIZE))
#define NS_DATA_START                   (NS_RAM_ALIAS(NS_DATA_OFFSET))
#ifdef NS_PARTITION_ON_OCRAM
#define NS_DATA_SIZE                    (TOTAL_RAM_NS_SIZE)
#else
#define NS_DATA_SIZE                    (TOTAL_RAM_SIZE - RESERVED_RAM_SIZE - S_DATA_SIZE)
#endif
#define NS_DATA_LIMIT                   (NS_DATA_START + NS_DATA_SIZE - 1)

/* Flash is divided into 32 kB sub-regions. Each sub-region can be assigned individual
security tier by programing corresponding registers in secure AHB controller.*/
#define FLASH_SUBREGION_SIZE    (0x8000)     /* 32 kB */

#define FLASH_REGION0_SUBREGION_NUMBER          32
#define FLASH_REGION0_SIZE                      (1024 * 1024)

#define FLASH_REGION1_SUBREGION_NUMBER          32
#define FLASH_REGION1_SIZE                      (1024 * 1024)

/* RAM is divided into 4 kB sub-regions. Each sub-region can be assigned individual
security tier by programing corresponding registers in secure AHB controller. */
#define DATA_SUBREGION_SIZE 0x1000      /* 4 KB*/

/* NS partition information is used for MPC and SAU configuration */
#define NS_PARTITION_START \
            (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_PARTITION_OFFSET))
#if defined(FLASH_NS_PARTITION_SIZE) && (FLASH_NS_PARTITION_SIZE != 0)
#define NS_PARTITION_SIZE (FLASH_NS_PARTITION_SIZE)
#else
#define NS_PARTITION_SIZE (NS_CODE_SIZE)
#endif

/* Secondary partition for new images in case of firmware upgrade */
#define SECONDARY_PARTITION_START \
            (NS_ROM_ALIAS(S_IMAGE_SECONDARY_PARTITION_OFFSET))
#define SECONDARY_PARTITION_SIZE (FLASH_S_PARTITION_SIZE + \
                                  FLASH_NS_PARTITION_SIZE)

#ifdef BL2
/* Bootloader regions */
#define BL2_CODE_START    (S_ROM_ALIAS(FLASH_AREA_BL2_OFFSET))
#define BL2_CODE_SIZE     (FLASH_AREA_BL2_SIZE)
#define BL2_CODE_LIMIT    (BL2_CODE_START + BL2_CODE_SIZE - 1)

#define BL2_DATA_START    (S_RAM_ALIAS(0x0))
#define BL2_DATA_SIZE     (TOTAL_RAM_SIZE)
#define BL2_DATA_LIMIT    (BL2_DATA_START + BL2_DATA_SIZE - 1)
#endif /* BL2 */

/* Shared data area between bootloader and runtime firmware.
 * Shared data area is allocated at the beginning of the RAM, it is overlapping
 * with TF-M Secure code's MSP stack
 */
#define BOOT_TFM_SHARED_DATA_BASE S_RAM_ALIAS_BASE
#define BOOT_TFM_SHARED_DATA_SIZE (0x400)
#define BOOT_TFM_SHARED_DATA_LIMIT (BOOT_TFM_SHARED_DATA_BASE + \
                                    BOOT_TFM_SHARED_DATA_SIZE - 1)


/* Shared data area between bootloader and runtime firmware.
 * Shared data area is allocated at the beginning of the RAM, it is overlapping
 * with TF-M Secure code's MSP stack
 */
#define BOOT_TFM_SHARED_DATA_BASE S_RAM_ALIAS_BASE
#define BOOT_TFM_SHARED_DATA_SIZE (0x400)
#define BOOT_TFM_SHARED_DATA_LIMIT (BOOT_TFM_SHARED_DATA_BASE + \
                                    BOOT_TFM_SHARED_DATA_SIZE - 1)
#define SHARED_BOOT_MEASUREMENT_BASE BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE BOOT_TFM_SHARED_DATA_SIZE
#define SHARED_BOOT_MEASUREMENT_LIMIT BOOT_TFM_SHARED_DATA_LIMIT

#endif /* __REGION_DEFS_H__ */
