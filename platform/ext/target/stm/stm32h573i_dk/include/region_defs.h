/*
 * Copyright (c) 2017-2018 ARM Limited
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

#define BL2_HEAP_SIZE           0x0001000
#define BL2_MSP_STACK_SIZE      0x0002000

#define LOADER_S_MSP_STACK_SIZE 0x0000400
#define LOADER_S_HEAP_SIZE      0x0000200
#define LOADER_S_PSP_STACK_SIZE 0x0000400

#define S_HEAP_SIZE             0x0001000
#define S_MSP_STACK_SIZE_INIT   0x0000400
#define S_MSP_STACK_SIZE        0x0000800
#define S_PSP_STACK_SIZE        0x0000800

#define NS_HEAP_SIZE            0x0001000
#define NS_STACK_SIZE           0x0001000

#define NS_MSP_STACK_SIZE       0x0000C00
#define NS_PSP_STACK_SIZE       0x0000C00

/* GTZC specific Alignment */
#define GTZC_RAM_ALIGN 512
#define GTZC_FLASH_ALIGN 8192

/*
 * This size of buffer is big enough to store an attestation
 * token produced by initial attestation service
 */
#define PSA_INITIAL_ATTEST_TOKEN_MAX_SIZE   0x250

#define _SRAM2_TOP              (0x40000) /* 256Kbytes */
#define _SRAM1_SIZE_MAX         (0x40000) /*!< SRAM1=256 KB */
#define _SRAM2_SIZE_MAX         (0x10000 - BOOT_TFM_SHARED_DATA_SIZE)  /*!< SRAM2=64k -0x400 */
#define _SRAM3_SIZE_MAX         (0x50000) /*!< SRAM3=320 KB */

/* Flash and internal SRAMs base addresses - Non secure aliased */
#define _FLASH_BASE_NS          (0x08000000) /*!< FLASH(up to 512 KB) base address */
#define _SRAM1_BASE_NS          (0x20000000) /*!< SRAM1(up to 192 KB) base address */
#define _SRAM2_BASE_NS          (0x20040000) /*!< SRAM2(64 KB) base address */
#define _SRAM3_BASE_NS          (0x20050000) /*!< SRAM3(320 KB) base address */
/* Flash and internal SRAMs base addresses - Secure aliased */
#define _FLASH_BASE_S           (0x0C000000) /*!< FLASH(up to 512 KB) base address */
#define _SRAM1_BASE_S           (0x30000000) /*!< SRAM1(up to 192 KB) base address */
#define _SRAM2_BASE_S           (0x30040000) /*!< SRAM2(64 KB) base address */
#define _SRAM3_BASE_S           (0x30050000) /*!< SRAM3(320 KB) base address */


#define TOTAL_ROM_SIZE          FLASH_TOTAL_SIZE
#define TOTAL_RAM_SIZE          (_SRAM1_SIZE_MAX +_SRAM2_SIZE_MAX)

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

#define S_IMAGE_PRIMARY_PARTITION_OFFSET    (FLASH_AREA_0_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET  (FLASH_AREA_2_OFFSET)
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_AREA_0_OFFSET + FLASH_S_PARTITION_SIZE)
#define NS_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET + FLASH_S_PARTITION_SIZE)
#if (MCUBOOT_S_DATA_IMAGE_NUMBER == 1)
#define S_DATA_IMAGE_PRIMARY_PARTITION_OFFSET    (FLASH_AREA_4_OFFSET)
#define S_DATA_IMAGE_SECONDARY_PARTITION_OFFSET  (FLASH_AREA_6_OFFSET)
#endif /* MCUBOOT_S_DATA_IMAGE_NUMBER == 1 */
#if (MCUBOOT_NS_DATA_IMAGE_NUMBER == 1)
#define NS_DATA_IMAGE_PRIMARY_PARTITION_OFFSET   (FLASH_AREA_5_OFFSET)
#define NS_DATA_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_7_OFFSET)
#endif /* MCUBOOT_NS_DATA_IMAGE_NUMBER == 1 */



#define IMAGE_S_CODE_SIZE \
    (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)
#define IMAGE_NS_CODE_SIZE \
    (FLASH_NS_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)

/* Size to accomodate the veneers for iovec based services */
#define CMSE_VENEER_REGION_SIZE             (0x00000040)

/* Use SRAM1 memory to store Code data */
#define S_ROM_ALIAS_BASE                    (_FLASH_BASE_S)
#define NS_ROM_ALIAS_BASE                   (_FLASH_BASE_NS)

#define S_RAM_ALIAS_BASE                    (_SRAM1_BASE_S)
#define NS_RAM_ALIAS_BASE                   (_SRAM1_BASE_NS)

/* Alias definitions for secure and non-secure areas*/
#define S_ROM_ALIAS(x)                      (S_ROM_ALIAS_BASE + (x))
#define NS_ROM_ALIAS(x)                     (NS_ROM_ALIAS_BASE + (x))

#define LOADER_S_ROM_ALIAS(x)               (_FLASH_BASE_S + (x))

#define S_RAM_ALIAS(x)                      (S_RAM_ALIAS_BASE + (x))
#define NS_RAM_ALIAS(x)                     (NS_RAM_ALIAS_BASE + (x))

#define S_IMAGE_PRIMARY_AREA_OFFSET         (S_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define S_CODE_START                        (S_ROM_ALIAS(S_IMAGE_PRIMARY_AREA_OFFSET))
#define S_CODE_SIZE                         (IMAGE_S_CODE_SIZE - CMSE_VENEER_REGION_SIZE)
#define S_CODE_LIMIT                        ((S_CODE_START + S_CODE_SIZE) -0x1)
#define S_DATA_START                        (S_RAM_ALIAS(NS_TOTAL_RAM_SIZE))
#define S_DATA_SIZE                         (S_TOTAL_RAM_SIZE)
#define S_DATA_LIMIT                        (S_DATA_START + S_DATA_SIZE -0x1)

#if (MCUBOOT_S_DATA_IMAGE_NUMBER == 1)
#define S_DATA_IMAGE_PRIMARY_AREA_OFFSET    (S_DATA_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_DATA_HEADER_SIZE)
#endif /* MCUBOOT_S_DATA_IMAGE_NUMBER == 1 */

/* CMSE Veneers region */
#define CMSE_VENEER_REGION_START            (S_CODE_LIMIT + 1)
/* Non-secure regions */

/* Secure regions , the end of secure regions must be aligned on page size for dual bank 0x800*/
/* Offset and size definition in flash area, used by assemble.py
 * 0x11400+0x33c00= 13000+34000 = 45000*/

#define NS_IMAGE_PRIMARY_AREA_OFFSET        (NS_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define NS_CODE_START                       (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_AREA_OFFSET))
#define NS_CODE_SIZE                        (IMAGE_NS_CODE_SIZE)
#define NS_CODE_LIMIT                       (NS_CODE_START + NS_CODE_SIZE - 1)
#define NS_DATA_START                       (NS_RAM_ALIAS(0))
#define NS_DATA_START_2                     (_SRAM3_BASE_NS)
#define NS_NO_INIT_DATA_SIZE                (0x100)
#define NS_DATA_SIZE                        (NS_TOTAL_RAM_SIZE)
#define NS_DATA_SIZE_2                      (_SRAM3_SIZE_MAX)
#define NS_DATA_LIMIT                       (NS_DATA_START + NS_DATA_SIZE - 1)
#define NS_DATA_LIMIT_2                     (NS_DATA_START_2 + NS_DATA_SIZE_2 - 1)

/* NS partition information is used for MPC and SAU configuration */
#define NS_PARTITION_START                  (NS_CODE_START)
#define NS_PARTITION_SIZE                   (NS_CODE_SIZE)

/* Secondary partition for new images/ in case of firmware upgrade */
#define SECONDARY_PARTITION_START           (NS_ROM_ALIAS(S_IMAGE_SECONDARY_PARTITION_OFFSET))
#define SECONDARY_PARTITION_SIZE            (FLASH_AREA_2_SIZE)

#ifdef BL2
#define PERSO_START                         (S_ROM_ALIAS(FLASH_AREA_PERSO_OFFSET))
#define PERSO_SIZE                          (FLASH_AREA_PERSO_SIZE)
#define PERSO_LIMIT                         (PERSO_START + PERSO_SIZE - 1)
/* Bootloader region protected by hdp */
#define BL2_CODE_START                      (S_ROM_ALIAS(FLASH_AREA_BL2_OFFSET))
#define BL2_CODE_SIZE                       (FLASH_AREA_BL2_SIZE)
#define BL2_CODE_LIMIT                      (BL2_CODE_START + BL2_CODE_SIZE - 1)

#define BL2_NOHDP_CODE_START                (S_ROM_ALIAS(FLASH_AREA_BL2_NOHDP_OFFSET))
#define BL2_NOHDP_CODE_SIZE                 (FLASH_AREA_BL2_NOHDP_SIZE)
#define BL2_NOHDP_CODE_LIMIT                (BL2_NOHDP_CODE_START + BL2_NOHDP_CODE_SIZE - 1)
/* Bootloader boot address */
#define BL2_BOOT_VTOR_ADDR                  (BL2_CODE_START)

/*  keep 256 bytes unused to place while(1) for non secure to enable */
/*  regression from local tool with non secure attachment
 *  This avoid blocking board in case of hardening error */
#define BL2_DATA_START                      (S_RAM_ALIAS(_SRAM1_SIZE_MAX))
#define BL2_DATA_SIZE                       (BOOT_TFM_SHARED_DATA_BASE - BL2_DATA_START)
#define BL2_DATA_LIMIT                      (BL2_DATA_START + BL2_DATA_SIZE - 1)

/* Define BL2 MPU SRAM protection to remove execution capability */
/* Area is covering the complete SRAM memory space non secure alias and secure alias */
#define BL2_SRAM_AREA_BASE                  (_SRAM1_BASE_NS)
#define BL2_SRAM_AREA_END                   (_SRAM3_BASE_S + _SRAM3_SIZE_MAX - 1)

/* Define Area provision by BL2 */
#define BL2_OTP_AREA_BASE                   S_ROM_ALIAS(TFM_OTP_NV_COUNTERS_AREA_ADDR)
#define BL2_OTP_AREA_SIZE                   (TFM_OTP_NV_COUNTERS_AREA_SIZE)
/* Define Area for Initializing NVM counter */
/* backup sector is initialised */
#define BL2_NVM_AREA_BASE                   S_ROM_ALIAS(TFM_NV_COUNTERS_AREA_ADDR+FLASH_AREA_IMAGE_SECTOR_SIZE)
#define BL2_NVM_AREA_SIZE                   (FLASH_AREA_IMAGE_SECTOR_SIZE)
/* Define Area for initializing BL2_NVCNT   */
/* backup sector is initialised */
#define BL2_NVMCNT_AREA_BASE                S_ROM_ALIAS(FLASH_BL2_NVCNT_AREA_OFFSET+FLASH_AREA_IMAGE_SECTOR_SIZE)
#define BL2_NVMCNT_AREA_SIZE                (FLASH_AREA_IMAGE_SECTOR_SIZE)
#endif /* BL2 */


/*  Secure Loader Image */
/* Control  Secure Loader Image */
#if (FLASH_AREA_LOADER_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_LOADER_OFFSET  not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /* (FLASH_AREA_LOADER_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0  */


#define LOADER_IMAGE_S_CODE_SIZE            (FLASH_AREA_LOADER_SIZE)

#define LOADER_S_CODE_START                 (LOADER_S_ROM_ALIAS(FLASH_AREA_LOADER_OFFSET))
#define LOADER_S_CODE_SIZE                  (LOADER_IMAGE_S_CODE_SIZE) 
#define LOADER_S_CODE_LIMIT                 (LOADER_S_CODE_START + LOADER_S_CODE_SIZE -1)
#define LOADER_S_DATA_START                 (S_RAM_ALIAS(_SRAM1_SIZE_MAX))
#define LOADER_S_DATA_SIZE                  (_SRAM2_SIZE_MAX)
#define LOADER_S_DATA_LIMIT                 (LOADER_S_DATA_START + LOADER_S_DATA_SIZE - 1)
#define TRIGGER_LOADER_ADDRESS              (NS_RAM_ALIAS(0))
#define TRIGGER_LOADER_ADDRESS_S            (S_RAM_ALIAS(0))
#define TRIGGER_LOADER_MAGIC                (0x10ADE8AD)

/* TFM non volatile data (PS/ITS) region */
#define TFM_NV_DATA_START                   (S_ROM_ALIAS(FLASH_OTP_NV_COUNTERS_AREA_OFFSET))
#define TFM_NV_DATA_SIZE                    (FLASH_OTP_NV_COUNTERS_AREA_SIZE + FLASH_NV_COUNTERS_AREA_SIZE + FLASH_PS_AREA_SIZE + FLASH_ITS_AREA_SIZE)
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
