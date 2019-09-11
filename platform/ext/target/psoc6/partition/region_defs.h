/*
 * Copyright (c) 2017-2019 ARM Limited. All rights reserved.
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

#define TOTAL_ROM_SIZE FLASH_TOTAL_SIZE
#define TOTAL_RAM_SIZE (0x00048000) /* CY_SRAM0_SIZE */

#define BL2_HEAP_SIZE           0x0001000
#define BL2_MSP_STACK_SIZE      0x0001000

#define S_HEAP_SIZE             0x0001000
#define S_MSP_STACK_SIZE_INIT   0x0000400
#define S_MSP_STACK_SIZE        0x0000800
#define S_PSP_STACK_SIZE        0x0000800

#define NS_HEAP_SIZE            0x0001000
#define NS_MSP_STACK_SIZE       0x0000400
#define NS_PSP_STACK_SIZE       0x0000C00

/* Relocation of vectors to RAM support */
/* #define RAM_VECTORS_SUPPORT */

/*
 * This size of buffer is big enough to store an attestation
 * token produced by initial attestation service
 */
#define PSA_INITIAL_ATTEST_TOKEN_MAX_SIZE   0x250

/*
 * MPC granularity is 128 KB on AN519 MPS2 FPGA image. Alignment
 * of partitions is defined in accordance with this constraint.
 */

#ifdef BL2
#ifndef LINK_TO_SECONDARY_PARTITION
#define S_IMAGE_PRIMARY_PARTITION_OFFSET    (FLASH_AREA_0_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET  (FLASH_AREA_2_OFFSET)
#else
#define S_IMAGE_PRIMARY_PARTITION_OFFSET    (FLASH_AREA_2_OFFSET)
#define S_IMAGE_SECONDARY_PARTITION_OFFSET  (FLASH_AREA_0_OFFSET)
#endif /* !LINK_TO_SECONDARY_PARTITION */
#else
#define  S_IMAGE_PRIMARY_PARTITION_OFFSET (0x0)
#endif /* BL2 */

#ifndef LINK_TO_SECONDARY_PARTITION
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_0_OFFSET + \
                                           FLASH_S_PARTITION_SIZE)
#else
#define NS_IMAGE_PRIMARY_PARTITION_OFFSET (FLASH_AREA_2_OFFSET + \
                                           FLASH_S_PARTITION_SIZE)
#endif /* !LINK_TO_SECONDARY_PARTITION */

/*
 * Boot partition structure if MCUBoot is used:
 * 0x0_0000 Bootloader header
 * 0x0_0400 Image area
 * 0x1_FC00 Trailer
 */
/* Image code size is the space available for the software binary image.
 * It is less than the FLASH_S_PARTITION_SIZE and FLASH_NS_PARTITION_SIZE
 * because we reserve space for the image header and trailer introduced by the
 * bootloader.
 */
#ifdef BL2
#define BL2_HEADER_SIZE      (0x400)
#define BL2_TRAILER_SIZE     (0x400)
#else
/* No header if no bootloader, but keep image code size the same */
#define BL2_HEADER_SIZE      (0x0)
#define BL2_TRAILER_SIZE     (0x800)
#endif /* BL2 */

#define IMAGE_S_CODE_SIZE \
            (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)
#define IMAGE_NS_CODE_SIZE \
            (FLASH_NS_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)

/* Alias definitions for secure and non-secure areas*/
#define S_ROM_ALIAS(x)  (S_ROM_ALIAS_BASE + (x))
#define NS_ROM_ALIAS(x) (NS_ROM_ALIAS_BASE + (x))

#define S_RAM_ALIAS(x)  (S_RAM_ALIAS_BASE + (x))
#define NS_RAM_ALIAS(x) (NS_RAM_ALIAS_BASE + (x))

/* Secure regions */
#define  S_IMAGE_PRIMARY_AREA_OFFSET \
             (S_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define S_CODE_START    (S_ROM_ALIAS(S_IMAGE_PRIMARY_AREA_OFFSET))
#define S_CODE_SIZE     IMAGE_S_CODE_SIZE
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_START    (S_RAM_ALIAS(0x0))
#define S_UNPRIV_DATA_SIZE  0x8000
#define S_PRIV_DATA_SIZE    0x20000
/* Unprivileged data area + privileged data area */
#define S_DATA_SIZE     (S_UNPRIV_DATA_SIZE + S_PRIV_DATA_SIZE)
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

/* We need the privileged data area to be aligned so that an SMPU
 * region can cover it.
 */
/* TODO It would be nice to figure this out automatically.
 * In theory, in the linker script, we could determine the amount
 * of secure data space available after all the unprivileged data,
 * round that down to a power of 2 to get the actual size we want
 * to use for privileged data, and then determine this value from
 * that. We'd also potentially have to update the configs for SMPU9
 * and SMPU10.
 * Leave the SMPU alignment check in SMPU configuration file.
 */
#define S_DATA_PRIV_OFFSET       S_UNPRIV_DATA_SIZE
#define S_DATA_PRIV_START        S_RAM_ALIAS(S_DATA_PRIV_OFFSET)

/* Non-secure regions */
#define NS_IMAGE_PRIMARY_AREA_OFFSET \
                        (NS_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
#define NS_CODE_START   (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_AREA_OFFSET))
#define NS_CODE_SIZE    IMAGE_NS_CODE_SIZE
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

#define NS_DATA_START   (NS_RAM_ALIAS(S_DATA_SIZE))
#define NS_DATA_SIZE    (TOTAL_RAM_SIZE - S_DATA_SIZE)
#define NS_DATA_LIMIT   (NS_DATA_START + NS_DATA_SIZE - 1)

/* NS partition information is used for MPC and SAU configuration */
#define NS_PARTITION_START \
            (NS_ROM_ALIAS(NS_IMAGE_PRIMARY_PARTITION_OFFSET))

#define NS_PARTITION_SIZE (FLASH_NS_PARTITION_SIZE)

/* Secondary partition for new images in case of firmware upgrade */
#define SECONDARY_PARTITION_START \
            (NS_ROM_ALIAS(S_IMAGE_SECONDARY_PARTITION_OFFSET))

#define SECONDARY_PARTITION_SIZE   FLASH_PARTITION_SIZE

#ifdef BL2
/* Bootloader regions */
#define BL2_CODE_START    (S_ROM_ALIAS(FLASH_AREA_BL2_OFFSET))
#define BL2_CODE_SIZE     (FLASH_AREA_BL2_SIZE)
#define BL2_CODE_LIMIT    (BL2_CODE_START + BL2_CODE_SIZE - 1)

#define BL2_DATA_START    (S_RAM_ALIAS(S_DATA_PRIV_OFFSET))
#define BL2_DATA_SIZE     (S_PRIV_DATA_SIZE)
#define BL2_DATA_LIMIT    (BL2_DATA_START + BL2_DATA_SIZE - 1)

/* Shared data area between bootloader and runtime firmware.
 * Shared data area is allocated at the beginning of the privileged data area,
 * it is overlapping with TF-M Secure code's MSP stack
 */
#define BOOT_TFM_SHARED_DATA_BASE BL2_DATA_START
#define BOOT_TFM_SHARED_DATA_SIZE 0x400
#endif /* BL2 */

#endif /* __REGION_DEFS_H__ */

