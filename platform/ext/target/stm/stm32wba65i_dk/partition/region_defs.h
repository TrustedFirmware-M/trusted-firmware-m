/*
 * Copyright (c) 2017-2022 ARM Limited
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

#define S_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_AREA_0_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET)

#define S_HEAP_SIZE             0x00000C0
#define S_MSP_STACK_SIZE_INIT   0x0000400
#define S_MSP_STACK_SIZE        0x0000200
#define S_PSP_STACK_SIZE        0x0000700

#define NS_HEAP_SIZE            0x0001000
#define NS_STACK_SIZE           0x0001000

#define NS_MSP_STACK_SIZE       0x0000C00
#define NS_PSP_STACK_SIZE       0x0000C00

/* GTZC specific Alignment */
#define GTZC_RAM_ALIGN 512
#define GTZC_FLASH_ALIGN 8192

/*  FIX ME : include stm32wba65xx.h instead  */
#define _SRAM2_TOP              (0x40000) /* 256 Kbytes */
#define _SRAM1_SIZE_MAX         (0x70000)  /*!< SRAM1 = 448 kbytes */
#define _SRAM2_SIZE_MAX         (0x10000 - BOOT_TFM_SHARED_DATA_SIZE)  /*!< SRAM2=64k -0x400 */
#define _SRAM6_SIZE_MAX         (0x4000) /* 512Kbytes */

/* Flash and internal SRAMs base addresses - Non secure aliased */
#define _FLASH_BASE_NS          (0x08000000) /*!< FLASH(1024 KB) base address */
#define _SRAM1_BASE_NS          (0x20000000) /*!< SRAM1(64 KB) base address */
#define _SRAM2_BASE_NS          (0x20070000) /*!< SRAM2(64 KB) base address */
/* Flash and internal SRAMs base addresses - Secure aliased */
#define _FLASH_BASE_S           (0x0C000000) /*!< FLASH(1024 KB) base address */
#define _SRAM1_BASE_S           (0x30000000) /*!< SRAM1(64 KB) base address */
#define _SRAM2_BASE_S           (0x30070000) /*!< SRAM2(64 KB) base address */

#define TOTAL_ROM_SIZE          FLASH_TOTAL_SIZE
#define TOTAL_RAM_SIZE          (_SRAM1_SIZE_MAX +_SRAM2_SIZE_MAX)
/* 448 kbytes + 64 Kbytes - BOOT info */
/* boot info are placed and locked at top of SRAM2  */

#define S_TOTAL_RAM2_SIZE       (_SRAM2_SIZE_MAX) /*! size require for Secure part */
#define S_TOTAL_RAM1_SIZE       (0x10000)
#define S_TOTAL_RAM_SIZE        (S_TOTAL_RAM2_SIZE + S_TOTAL_RAM1_SIZE)
#define NS_TOTAL_RAM_SIZE       (TOTAL_RAM_SIZE - S_TOTAL_RAM_SIZE)

/*
 * Boot partition structure if MCUBoot is used:
 * 0x0_0000 Bootloader header
 * 0x0_0400 Image area
 * 0x7_0000 Trailer
 */
/* IMAGE_CODE_SIZE is the space available for the software binary image.
 * It is less than the FLASH_PARTITION_SIZE because we reserve space
 * for the image header and trailer introduced by the bootloader.
 */

#ifndef BL2_HEADER_SIZE
#define BL2_HEADER_SIZE                     (0x400) /*!< Appli image header size */
#endif
#ifndef BL2_TRAILER_SIZE
#define BL2_TRAILER_SIZE                    (0x400)
#endif

#define BL2_DATA_HEADER_SIZE                (0x20)  /*!< Data image header size */

#define NS_IMAGE_PRIMARY_PARTITION_OFFSET FLASH_AREA_1_OFFSET


#define IMAGE_S_CODE_SIZE \
    (FLASH_S_PARTITION_SIZE - 0x400 - 0x400)
#define IMAGE_NS_CODE_SIZE \
    (FLASH_NS_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)

/* FIXME: veneer region size is increased temporarily while both legacy veneers
 * and their iovec-based equivalents co-exist for secure partitions. To be
 * adjusted as legacy veneers are eliminated
 */
#define CMSE_VENEER_REGION_SIZE             (0x00000380)

/* Use SRAM1 memory to store Code data */
#define S_ROM_ALIAS_BASE                    (_FLASH_BASE_S)
#define NS_ROM_ALIAS_BASE                   (_FLASH_BASE_NS)


#define S_RAM_ALIAS_BASE                    (_SRAM1_BASE_S)
#define NS_RAM_ALIAS_BASE                   (_SRAM1_BASE_NS)

/* Alias definitions for secure and non-secure areas*/
#define S_ROM_ALIAS(x)                      (S_ROM_ALIAS_BASE + (x))
#define NS_ROM_ALIAS(x)                     (NS_ROM_ALIAS_BASE + (x))

#define LOADER_NS_ROM_ALIAS(x)              (_FLASH_BASE_NS + (x))
#define LOADER_S_ROM_ALIAS(x)               (_FLASH_BASE_S + (x))

#define S_RAM_ALIAS(x)                      (S_RAM_ALIAS_BASE + (x))
#define NS_RAM_ALIAS(x)                     (NS_RAM_ALIAS_BASE + (x))


#define S_IMAGE_PRIMARY_AREA_OFFSET         (S_IMAGE_PRIMARY_PARTITION_OFFSET + 0x400)
#define S_CODE_START                        (S_ROM_ALIAS(S_IMAGE_PRIMARY_AREA_OFFSET))
#define S_CODE_SIZE                         (IMAGE_S_CODE_SIZE - CMSE_VENEER_REGION_SIZE)
#define S_CODE_LIMIT                        ((S_CODE_START + S_CODE_SIZE) -1)
#define S_DATA_START                        (S_RAM_ALIAS(NS_TOTAL_RAM_SIZE))
#define S_DATA_SIZE                         (S_TOTAL_RAM_SIZE)
#define S_DATA_LIMIT                        (S_DATA_START + S_DATA_SIZE - 1)

/* CMSE Veneers region */
#define CMSE_VENEER_REGION_START            (S_CODE_LIMIT + 1)
/* Non-secure regions */

/* Secure regions , the end of secure regions must be aligned on page size for dual bank 0x800*/
/* Offset and size definition in flash area, used by assemble.py
 * 0x11400+0x33c00= 13000+34000 = 45000*/

#define NS_IMAGE_PRIMARY_AREA_OFFSET        (NS_IMAGE_PRIMARY_PARTITION_OFFSET + 0x400)
#define NS_CODE_START                       (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_AREA_OFFSET))
#define NS_CODE_SIZE                        (IMAGE_NS_CODE_SIZE)
#define NS_CODE_LIMIT                       (NS_CODE_START + NS_CODE_SIZE - 1)
#define NS_DATA_START                       (NS_RAM_ALIAS(0))
#define NS_NO_INIT_DATA_SIZE                (0x100)
#define NS_DATA_SIZE                        (NS_TOTAL_RAM_SIZE)
#define NS_DATA_LIMIT                       (NS_DATA_START + NS_DATA_SIZE - 1)

/* NS partition information is used for MPC and SAU configuration */
#define NS_PARTITION_START                  (NS_CODE_START)
#define NS_PARTITION_SIZE                   (NS_CODE_SIZE)

/* Secondary partition for new images/ in case of firmware upgrade */
#define SECONDARY_PARTITION_START           (NS_ROM_ALIAS(S_IMAGE_SECONDARY_PARTITION_OFFSET))
#define SECONDARY_PARTITION_SIZE            (FLASH_AREA_2_SIZE)

/* Define OTP Area provisionnig */
#ifdef TFM_OTP_DEFAULT_PROVIONNING
#define OTP_AREA_BASE                   S_ROM_ALIAS(TFM_OTP_NV_COUNTERS_AREA_ADDR)
#define OTP_AREA_SIZE                   (TFM_OTP_NV_COUNTERS_AREA_SIZE)
#endif //TFM_OTP_DEFAULT_PROVIONNING//

/* TFM non volatile data (NVCNT/PS/ITS) region */
#define TFM_NV_DATA_START                   (S_ROM_ALIAS(FLASH_OTP_NV_COUNTERS_AREA_OFFSET))
#define TFM_NV_DATA_SIZE                    (FLASH_OTP_NV_COUNTERS_AREA_SIZE + FLASH_NV_COUNTER_AREA_SIZE \
                                             + FLASH_PS_AREA_SIZE + FLASH_ITS_AREA_SIZE)
#define TFM_NV_DATA_LIMIT                   (TFM_NV_DATA_START + TFM_NV_DATA_SIZE - 1)
/* Additional Check to detect flash download slot overlap or overflow */
#define FLASH_AREA_END_OFFSET_MAX (FLASH_TOTAL_SIZE)

#if (MCUBOOT_S_DATA_IMAGE_NUMBER == 1)
/* S DATA image layout */
#define S_DATA_IMAGE_IAT_PRIV_KEY_OFFSET    (BL2_DATA_HEADER_SIZE)
#endif /* (MCUBOOT_S_DATA_IMAGE_NUMBER == 1) */

#if (MCUBOOT_NS_DATA_IMAGE_NUMBER == 1)
/* NS DATA image layout */
#define NS_DATA_IMAGE_DATA1_OFFSET          (BL2_DATA_HEADER_SIZE)
#define NS_DATA_IMAGE_DATA1_SIZE            (32U)
#endif /* (MCUBOOT_NS_DATA_IMAGE_NUMBER == 1) */

#if FLASH_AREA_END_OFFSET > FLASH_AREA_END_OFFSET_MAX
#error "Flash memory overflow"
#endif /* FLASH_AREA_END_OFFSET > FLASH_AREA_END_OFFSET_MAX */

#endif /* __REGION_DEFS_H__ */