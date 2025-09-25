/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __FLASH_LAYOUT_H__
#define __FLASH_LAYOUT_H__

#include "host_base_address.h"
#include "platform_base_address.h"

/* This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_retarget.h to access flash related defines. To resolve this
 * some of the values are redefined here with different names, these are marked
 * with comment.
 */

/* Define to 0, so that we can feed the flash driver a fixed address instead of
 * an offset.
 */
#define FLASH_BASE_ADDRESS              (HOST_ACCESS_BASE_S)
#define FLASH_BL1_BASE_ADDRESS          (FLASH_BASE_ADDRESS)

/* Flash device name used by BL1 and BL2
 * Name is defined in flash driver file: Driver_Flash.c
 */
#define FLASH_DEV_NAME Driver_FLASH0
#define FLASH_DEV_NAME_BL1 FLASH_DEV_NAME

/* Smallest flash programmable unit in bytes */
#define TFM_HAL_FLASH_PROGRAM_UNIT      (0x1)

/* Sizes of a images */
#ifdef RSE_USE_OTP_EMULATION_IN_SRAM
#define FLASH_BL2_PARTITION_SIZE        (0x0B800) /* BL2 partition: 46 KiB */
#else
#define FLASH_BL2_PARTITION_SIZE        (0x0F800) /* BL2 partition: 62 KiB */
#endif
#define FLASH_S_PARTITION_SIZE          (0x60000) /* S   partition: 384 KiB */
#define FLASH_NS_PARTITION_SIZE         (0x60000) /* NS  partition: 384 KiB */
#define FLASH_AP_PARTITION_SIZE         (0x80000) /* AP  partition: 512 KiB */
#define FLASH_SCP_PARTITION_SIZE        (0x80000) /* SCP partition: 512 KiB */

#define HOST_IMAGE_HEADER_SIZE          (0x2000)

#ifdef RSE_XIP
/* Each table contains a bit less that 12KiB of HTR and 2KiB of mcuboot headers.
 * The spare space in the 8KiB is used for decryption IVs.
 */
#define FLASH_SIC_TABLE_SIZE            (0x3800) /* 10KiB */
#endif /* RSE_XIP */

/* Sector size of the flash hardware; same as FLASH0_SECTOR_SIZE */
#define FLASH_AREA_IMAGE_SECTOR_SIZE    (0x1000)    /* 512 KiB */
/* Same as FLASH0_SIZE */
#define FLASH_TOTAL_SIZE                (0xFC00000)  /* 252 MiB */

#ifndef RSE_GPT_SUPPORT
#define FLASH_FIP_MAX_SIZE         0x800000 /* 8MiB */
#define FLASH_FIP_A_OFFSET         0x0
#define FLASH_FIP_B_OFFSET         (FLASH_FIP_A_OFFSET + FLASH_FIP_MAX_SIZE)
#else
#define FLASH_LBA_SIZE             0x200
#endif /* !RSE_GPT_SUPPORT */

/* Offset and size definitions of the flash partitions that are handled by the
 * bootloader. The image swapping is done between IMAGE_PRIMARY and
 * IMAGE_SECONDARY, SCRATCH is used as a temporary storage during image
 * swapping.
 */

/* Sanity check that we can map the partition sizes given. The SIC tables are
 * always smaller than the partitions, so no need to check those. */
#if FLASH_BL2_PARTITION_SIZE > HOST_IMAGE_MAX_SIZE \
 || FLASH_S_PARTITION_SIZE   > HOST_IMAGE_MAX_SIZE \
 || FLASH_NS_PARTITION_SIZE  > HOST_IMAGE_MAX_SIZE \
 || FLASH_AP_PARTITION_SIZE  > HOST_IMAGE_MAX_SIZE \
 || FLASH_SCP_PARTITION_SIZE > HOST_IMAGE_MAX_SIZE
#error A partition is larger than HOST_IMAGE_MAX_SIZE, and so cannot be mapped
#endif

#ifndef RSE_XIP
#define FLASH_SIC_TABLE_SIZE 0
#endif /* !RSE_XIP */

#define FLASH_MAX_PARTITION_SIZE SECURE_IMAGE_MAX_SIZE

/* BL2 primary slot */
#define FLASH_AREA_0_ID            (1)
#define FLASH_AREA_0_OFFSET        (HOST_FLASH0_IMAGE0_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_0_SIZE          (FLASH_BL2_PARTITION_SIZE)
/* BL2 secondary slot */
#define FLASH_AREA_1_ID            (FLASH_AREA_0_ID + 1)
#define FLASH_AREA_1_OFFSET        (HOST_FLASH0_IMAGE1_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_1_SIZE          (FLASH_BL2_PARTITION_SIZE)

/* Secure image primary slot. */
#define FLASH_AREA_2_ID            (FLASH_AREA_1_ID + 1)
#define FLASH_AREA_2_OFFSET        (HOST_FLASH0_IMAGE0_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_2_SIZE          (FLASH_S_PARTITION_SIZE)
/* Non-secure image primary slot. */
#define FLASH_AREA_3_ID            (FLASH_AREA_2_ID + 1)
#define FLASH_AREA_3_OFFSET        (HOST_FLASH0_IMAGE0_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_3_SIZE          (FLASH_NS_PARTITION_SIZE)
/* Secure image secondary slot. */
#define FLASH_AREA_4_ID            (FLASH_AREA_3_ID + 1)
#define FLASH_AREA_4_OFFSET        (HOST_FLASH0_IMAGE1_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_4_SIZE          (FLASH_S_PARTITION_SIZE)
/* Non-secure image secondary slot. */
#define FLASH_AREA_5_ID            (FLASH_AREA_4_ID + 1)
#define FLASH_AREA_5_OFFSET        (HOST_FLASH0_IMAGE1_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_5_SIZE          (FLASH_NS_PARTITION_SIZE)

/* AP image primary slot */
#define FLASH_AREA_6_ID            (FLASH_AREA_5_ID + 1)
#define FLASH_AREA_6_OFFSET        (HOST_FLASH0_IMAGE0_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_6_SIZE          (FLASH_AP_PARTITION_SIZE)
/* SCP image primary slot */
#define FLASH_AREA_7_ID            (FLASH_AREA_6_ID + 1)
#define FLASH_AREA_7_OFFSET        (HOST_FLASH0_IMAGE0_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_7_SIZE          (FLASH_SCP_PARTITION_SIZE)
/* AP image secondary slot */
#define FLASH_AREA_8_ID            (FLASH_AREA_7_ID + 1)
#define FLASH_AREA_8_OFFSET        (HOST_FLASH0_IMAGE1_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_8_SIZE          (FLASH_AP_PARTITION_SIZE)
/* SCP image secondary slot */
#define FLASH_AREA_9_ID            (FLASH_AREA_8_ID + 1)
#define FLASH_AREA_9_OFFSET        (HOST_FLASH0_IMAGE1_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_9_SIZE          (FLASH_SCP_PARTITION_SIZE)

#ifdef RSE_XIP
/* Secure image SIC tables primary slot */
#define FLASH_AREA_10_ID            (FLASH_AREA_9_ID + 1)
#define FLASH_AREA_10_OFFSET        (HOST_FLASH0_IMAGE0_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_10_SIZE          (FLASH_SIC_TABLE_SIZE)
/* Non-secure image SIC tables primary slot */
#define FLASH_AREA_11_ID            (FLASH_AREA_10_ID + 1)
#define FLASH_AREA_11_OFFSET        (HOST_FLASH0_IMAGE0_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_11_SIZE          (FLASH_SIC_TABLE_SIZE)
/* Secure image SIC tables secondary slot */
#define FLASH_AREA_12_ID            (FLASH_AREA_11_ID + 1)
#define FLASH_AREA_12_OFFSET        (HOST_FLASH0_IMAGE1_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_12_SIZE          (FLASH_SIC_TABLE_SIZE)
/* Non-secure image SIC tables secondary slot */
#define FLASH_AREA_13_ID            (FLASH_AREA_12_ID + 1)
#define FLASH_AREA_13_OFFSET        (HOST_FLASH0_IMAGE1_BASE_S - HOST_ACCESS_BASE_S)
#define FLASH_AREA_13_SIZE          (FLASH_SIC_TABLE_SIZE)
#endif /* RSE_XIP */

/* Maximum number of image sectors supported by the bootloader. */
#define MCUBOOT_MAX_IMG_SECTORS    (FLASH_MAX_PARTITION_SIZE / \
                                    FLASH_AREA_IMAGE_SECTOR_SIZE)

#ifdef RSE_XIP
#define FLASH_AREA_IMAGE_PRIMARY(x)     (((x) == 0) ? FLASH_AREA_10_ID : \
                                         ((x) == 1) ? FLASH_AREA_11_ID : \
                                         ((x) == 2) ? FLASH_AREA_6_ID : \
                                         ((x) == 3) ? FLASH_AREA_7_ID : \
                                                      255)
#define FLASH_AREA_IMAGE_SECONDARY(x)   (((x) == 0) ? FLASH_AREA_12_ID : \
                                         ((x) == 1) ? FLASH_AREA_13_ID : \
                                         ((x) == 2) ? FLASH_AREA_8_ID : \
                                         ((x) == 3) ? FLASH_AREA_9_ID : \
                                                      255)

#else
#define FLASH_AREA_IMAGE_PRIMARY(x)     (((x) == 0) ? FLASH_AREA_2_ID : \
                                         ((x) == 1) ? FLASH_AREA_3_ID : \
                                         ((x) == 2) ? FLASH_AREA_6_ID : \
                                         ((x) == 3) ? FLASH_AREA_7_ID : \
                                                      255)
#define FLASH_AREA_IMAGE_SECONDARY(x)   (((x) == 0) ? FLASH_AREA_4_ID : \
                                         ((x) == 1) ? FLASH_AREA_5_ID : \
                                         ((x) == 2) ? FLASH_AREA_8_ID : \
                                         ((x) == 3) ? FLASH_AREA_9_ID : \
                                                      255)
#endif /* RSE_XIP */

/* Scratch area is not used with RAM loading firmware upgrade */
#define FLASH_AREA_IMAGE_SCRATCH        255

/* Offset and size definition in flash area used by assemble.py */
#define SECURE_IMAGE_OFFSET             (0x0)
#define NON_SECURE_IMAGE_OFFSET         (SECURE_IMAGE_OFFSET + \
                                         SECURE_IMAGE_MAX_SIZE)
#ifndef RSE_XIP
#define SECURE_IMAGE_MAX_SIZE           FLASH_S_PARTITION_SIZE
#define NON_SECURE_IMAGE_MAX_SIZE       FLASH_NS_PARTITION_SIZE
#else
#define SECURE_IMAGE_MAX_SIZE           FLASH_SIC_TABLE_SIZE
#define NON_SECURE_IMAGE_MAX_SIZE       FLASH_SIC_TABLE_SIZE
#endif /* !RSE_XIP */

#if !defined(RSE_XIP) && \
    FLASH_BL2_PARTITION_SIZE + FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE \
    > VM0_SIZE + VM1_SIZE
#error Partition sizes are too large to load into RSE SRAM
#endif

#include "flash_layout_common.h"

#endif /* __FLASH_LAYOUT_H__ */
