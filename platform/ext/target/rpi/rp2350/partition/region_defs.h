/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __REGION_DEFS_H__
#define __REGION_DEFS_H__

#ifdef NO_U_MODIFIER
#define _u(x) x
#endif

#include "flash_layout.h"
#include "hardware/regs/addressmap.h" /* Coming from SDK */

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
/* Secure Code stored in Flash */
#define S_CODE_START    ((XIP_BASE) + (S_IMAGE_PRIMARY_AREA_OFFSET))
#define S_CODE_SIZE     (IMAGE_S_CODE_SIZE)
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_OVERALL_SIZE         (0x30000) /* 192 KB */

/* Secure Data stored in SRAM0-3 */
#define S_DATA_START    (SRAM0_BASE)
#define S_DATA_SIZE     (S_DATA_OVERALL_SIZE)
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

/* Size of vector table: 52 + 16 entry -> 0x110 bytes */
/* Not defined, reason: TFM_VECTORS contain default handler implementations as
   well, which increases the standard size, resulting a failed check in linker
   script */
//#define S_CODE_VECTOR_TABLE_SIZE    (0x110)
/* This is used instead of the above */
#define NS_VECTOR_ALLOCATED_SIZE 0x124

/* Non-secure regions */
#define NS_IMAGE_PRIMARY_AREA_OFFSET \
                        (NS_IMAGE_PRIMARY_PARTITION_OFFSET + BL2_HEADER_SIZE)
/* Non-Secure Code stored in Code SRAM memory */
#define NS_CODE_START   ((XIP_BASE) + (NS_IMAGE_PRIMARY_AREA_OFFSET))

#if defined(TFM_LOAD_NS_IMAGE)
#define NS_CODE_SIZE    (IMAGE_NS_CODE_SIZE)
#else
#define NS_CODE_SIZE    (0x0)
#endif

#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

/* Entry point of Core1 */
#define NS_CODE_CORE1_START (NS_CODE_START + NS_VECTOR_ALLOCATED_SIZE)

#define NS_DATA_OVERALL_SIZE         (0x40000)

/* Non-Secure Data stored in ISRAM0+ISRAM1 */
#define NS_DATA_START   (SRAM4_BASE)

#if defined(TFM_LOAD_NS_IMAGE)
#define NS_DATA_SIZE    (NS_DATA_OVERALL_SIZE)
#else
#define NS_DATA_SIZE    (0)
#endif

#define NS_DATA_LIMIT   (NS_DATA_START + NS_DATA_SIZE - 1)

/* NS partition information is used for SAU configuration */
#define NS_PARTITION_START \
            ((XIP_BASE) + (NS_IMAGE_PRIMARY_PARTITION_OFFSET))

#if defined(TFM_LOAD_NS_IMAGE)
#define NS_PARTITION_SIZE (FLASH_NS_PARTITION_SIZE)
#else
#define NS_PARTITION_SIZE (0x0)
#endif

/* Secondary partition for new images in case of firmware upgrade */
#define SECONDARY_PARTITION_START \
            ((XIP_BASE) + (S_IMAGE_SECONDARY_PARTITION_OFFSET))
#define SECONDARY_PARTITION_SIZE (FLASH_S_PARTITION_SIZE + \
                                  FLASH_NS_PARTITION_SIZE)

#ifdef BL2
/* Bootloader regions */
#define BL2_CODE_START    (XIP_BASE)
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

#define PROVISIONING_BUNDLE_CODE_START (NS_DATA_START)
#define PROVISIONING_BUNDLE_CODE_SIZE  (PROVISIONING_CODE_PADDED_SIZE)
/* The max size of the values(keys, seeds) that are going to be provisioned
 * into the OTP. */
#define PROVISIONING_BUNDLE_VALUES_START (PROVISIONING_BUNDLE_CODE_START + PROVISIONING_BUNDLE_CODE_SIZE)
#define PROVISIONING_BUNDLE_VALUES_SIZE (PROVISIONING_VALUES_PADDED_SIZE)
#define PROVISIONING_BUNDLE_DATA_START (PROVISIONING_BUNDLE_VALUES_START + \
                                        PROVISIONING_BUNDLE_VALUES_SIZE)
#define PROVISIONING_BUNDLE_DATA_SIZE (PROVISIONING_DATA_PADDED_SIZE)

#define PROVISIONING_BUNDLE_START (XIP_BASE + FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE)
#define PROVISIONING_BUNDLE_MAGIC (0x18)

#if ((PROVISIONING_BUNDLE_START + PROVISIONING_BUNDLE_CODE_SIZE + PROVISIONING_BUNDLE_VALUES_SIZE + \
     PROVISIONING_BUNDLE_DATA_SIZE + PROVISIONING_BUNDLE_MAGIC) > XIP_BASE + FLASH_TOTAL_SIZE)
#error "Out of flash memory!"
#endif

/* Enable scratch regions for pico-rp2350 */
#define __ENABLE_SCRATCH__

#define SCRATCH_X_START (BL2_DATA_START + BL2_DATA_SIZE)
#define SCRATCH_X_SIZE  0x1000
#define SCRATCH_Y_START (SCRATCH_X_START + SCRATCH_X_SIZE)
#define SCRATCH_Y_SIZE  0x1000

#endif /* __REGION_DEFS_H__ */
