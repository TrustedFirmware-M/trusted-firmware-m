/*
 * Copyright (c) 2018-2022 Arm Limited. All rights reserved.
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

/* Flash layout with BL2:
 *
 * Not supported
 *
 * Flash layout for stm32wba65i-dk without BL2 :
 *
 *  0x000_0000 OTP / NV counters area (8 KB)
 *  0x000_4000 Protected Storage Area (16 KB)
 *  0x000_8000 Internal Trusted Storage Area (16 KB)
 *  0x000_c400 Secure     image  (384 KB)
 *  0x006_c400 Non-secure image primary (512 KB)
 */


/* This header file is included from linker scatter file as well, where only a
 * limited C constructs are allowed. Therefore it is not possible to include
 * here the platform_retarget.h to access flash related defines. To resolve this
 * some of the values are redefined here with different names, these are marked
 * with comment.
 */

#define BOOT_DATA_AVAILABLE

#ifdef BL2
#error "BL2 configuration is not supported"
#endif /* BL2 */

/* Sector size of the flash hardware; same as FLASH0_SECTOR_SIZE */
#define FLASH_AREA_IMAGE_SECTOR_SIZE    (0x2000)      /* 8 kB */
/* Same as FLASH0_SIZE */
#define FLASH_B_SIZE                    (0x100000)   /* 1 MBytes*/
#define FLASH_TOTAL_SIZE                (FLASH_B_SIZE + FLASH_B_SIZE) /* 2 MBytes */

/* Flash layout info for BL2 bootloader */
#define FLASH_BASE_ADDRESS              (0x0c000000) /* same as FLASH0_BASE */

#define FLASH_HASH_REF_AREA_OFFSET      (0x0000)
#define FLASH_HASH_REF_AREA_SIZE        (FLASH_AREA_IMAGE_SECTOR_SIZE)

/* area for HUK and anti roll back counter */
#define FLASH_BL2_NVCNT_AREA_OFFSET     (FLASH_HASH_REF_AREA_OFFSET + FLASH_HASH_REF_AREA_SIZE)
#define FLASH_BL2_NVCNT_AREA_SIZE       (FLASH_AREA_IMAGE_SECTOR_SIZE)

/* scratch area */
#define FLASH_AREA_SCRATCH_OFFSET       (FLASH_BL2_NVCNT_AREA_OFFSET + FLASH_BL2_NVCNT_AREA_SIZE)
#define FLASH_AREA_SCRATCH_SIZE         (0x0000) /* Not used in MCUBOOT_OVERWRITE_ONLY mode */
/* control scratch area */
#if (FLASH_AREA_SCRATCH_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_SCRATCH_OFFSET not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /* (FLASH_AREA_SCRATCH_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0*/

/* personal area */
#define FLASH_AREA_PERSO_OFFSET         (FLASH_BL2_NVCNT_AREA_OFFSET + FLASH_BL2_NVCNT_AREA_SIZE + \
                                         FLASH_AREA_SCRATCH_SIZE)
#define FLASH_AREA_PERSO_SIZE           (0x2000)
/* control personal area */
#if (FLASH_AREA_PERSO_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_PERSO_OFFSET not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /* FLASH_AREA_PERSO_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

/* area for BL2 code protected by hdp */
#define FLASH_AREA_BL2_OFFSET           (FLASH_AREA_PERSO_OFFSET+FLASH_AREA_PERSO_SIZE)
#define FLASH_AREA_BL2_SIZE             (0x10000)

/* HDP area end at this address */
#define FLASH_BL2_HDP_END               (FLASH_AREA_BL2_OFFSET+FLASH_AREA_BL2_SIZE-1)
/* area for BL2 code not protected by hdp */
#define FLASH_AREA_BL2_NOHDP_OFFSET     (FLASH_AREA_BL2_OFFSET+FLASH_AREA_BL2_SIZE)
#define FLASH_AREA_BL2_NOHDP_SIZE       (FLASH_AREA_IMAGE_SECTOR_SIZE)
/* control area for BL2 code protected by hdp */
#if (FLASH_AREA_BL2_NOHDP_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "HDP area must be aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /* (FLASH_AREA_BL2_NOHDP_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

/*TFM_PARTITION_FIRMWARE_UPDATE*/
/* Sector size of the flash hardware; same as FLASH0_SECTOR_SIZE */
#define FWU_COMPONENT_NUMBER 2

/* Secure image primary slot */
#define FLASH_AREA_0_ID            (1)
#define FLASH_AREA_0_OFFSET        (FLASH_AREA_BEGIN_OFFSET)
#define FLASH_AREA_0_SIZE          (FLASH_S_PARTITION_SIZE)
/* Control Secure app image primary slot */
#if (FLASH_AREA_0_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_0_OFFSET  not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /*  (FLASH_AREA_0_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

/* Non-secure image primary slot */
#define FLASH_AREA_1_ID            (FLASH_AREA_0_ID + 1)
#define FLASH_AREA_1_OFFSET        (FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE)
#define FLASH_AREA_1_SIZE          (FLASH_NS_PARTITION_SIZE)
/* Control Non-secure app image primary slot */
#if (FLASH_AREA_1_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_1_OFFSET  not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /* (FLASH_AREA_1_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0  */

/* Secure image secondary slot */
#define FLASH_AREA_2_ID            (FLASH_AREA_1_ID + 1)
#define FLASH_AREA_2_OFFSET        (FLASH_NV_COUNTERS_AREA_OFFSET + FLASH_B_SIZE)
#define FLASH_AREA_2_SIZE          (FLASH_S_PARTITION_SIZE)
/* Non-secure image secondary slot */
#define FLASH_AREA_3_ID            (FLASH_AREA_2_ID + 1)
#define FLASH_AREA_3_OFFSET        (FLASH_AREA_2_OFFSET + FLASH_AREA_2_SIZE)
#define FLASH_AREA_3_SIZE          (FLASH_NS_PARTITION_SIZE)
/* Scratch area */
#define FLASH_AREA_SCRATCH_ID      (FLASH_AREA_3_ID + 1)
/* The maximum number of status entries supported by the bootloader. */
#define MCUBOOT_STATUS_MAX_ENTRIES (FLASH_MAX_PARTITION_SIZE / \
                                    FLASH_AREA_SCRATCH_SIZE)
/* Maximum number of image sectors supported by the bootloader. */
#define MCUBOOT_MAX_IMG_SECTORS    (FLASH_MAX_PARTITION_SIZE / \
                                    FLASH_AREA_IMAGE_SECTOR_SIZE)
/* Host BL2 (TF-A) primary and secondary image. */
#define FLASH_AREA_4_ID                 (FLASH_AREA_3_ID + 1)
#define FLASH_AREA_5_ID                 (FLASH_AREA_4_ID + 1)
#define FLASH_AREA_IMAGE_PRIMARY(x)     (((x) == 0) ? FLASH_AREA_2_ID : \
                                         ((x) == 1) ? FLASH_AREA_4_ID : \
                                                      255 )
#define FLASH_AREA_IMAGE_SECONDARY(x)   (((x) == 0) ? FLASH_AREA_3_ID : \
                                         ((x) == 1) ? FLASH_AREA_5_ID : \
                                                      255 )
#define FLASH_AREA_IMAGE_SCRATCH        255
#define FLASH_DEVICE_ID                 100
#define FLASH_DEVICE_BASE               FLASH_BASE_ADDRESS
#define FLASH_DEV_NAME                  TFM_Driver_FLASH0
/*TFM_PARTITION_FIRMWARE_UPDATE*/

/* The size of S partition */
#define FLASH_S_PARTITION_SIZE          (0x60000) /* 384 KB for S partition */
/* The size of NS partition */
#define FLASH_NS_PARTITION_SIZE         (0x60000) /* 512 KB for NS partition */

/* Non Volatile Counters definitions */
#define FLASH_NV_COUNTERS_AREA_OFFSET           (0x0000)
#define FLASH_NV_COUNTER_AREA_SIZE              (0x0000)

/* Control Non Volatile Counters definitions */
#if (FLASH_NV_COUNTER_AREA_SIZE % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_NV_COUNTER_AREA_SIZE not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /*  (FLASH_NV_COUNTER_AREA_SIZE % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

/* OTP / Non Volatile Counters definitions */
#define FLASH_OTP_NV_COUNTERS_SECTOR_SIZE   (FLASH_AREA_IMAGE_SECTOR_SIZE)
#define FLASH_OTP_NV_COUNTERS_AREA_OFFSET   (FLASH_AREA_BL2_NOHDP_OFFSET + \
                                                 FLASH_AREA_BL2_NOHDP_SIZE)
#define FLASH_OTP_NV_COUNTERS_AREA_SIZE   (FLASH_OTP_NV_COUNTERS_SECTOR_SIZE + \
                                           FLASH_OTP_NV_COUNTERS_SECTOR_SIZE)

/* Secure Storage (PS) Service definitions */
#define FLASH_PS_AREA_SIZE             (FLASH_AREA_IMAGE_SECTOR_SIZE+FLASH_AREA_IMAGE_SECTOR_SIZE)
#define FLASH_PS_AREA_OFFSET           (FLASH_OTP_NV_COUNTERS_AREA_OFFSET+FLASH_OTP_NV_COUNTERS_AREA_SIZE)

/* Control Secure Storage (PS) Service definitions*/
#if (FLASH_PS_AREA_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_PS_AREA_OFFSET not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /*  (FLASH_PS_AREA_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

/* Internal Trusted Storage (ITS) Service definitions */
#define FLASH_ITS_AREA_OFFSET           (FLASH_PS_AREA_OFFSET+FLASH_PS_AREA_SIZE)
#define FLASH_ITS_AREA_SIZE             (FLASH_AREA_IMAGE_SECTOR_SIZE+FLASH_AREA_IMAGE_SECTOR_SIZE)

/*Control  Internal Trusted Storage (ITS) Service definitions */
#if (FLASH_ITS_AREA_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_ITS_AREA_OFFSET not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /*  (FLASH_ITS_AREA_OFFSET % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

#define FLASH_AREA_BEGIN_OFFSET         (FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE)

/* Secure app image primary slot */
#define FLASH_AREA_0_OFFSET             (FLASH_AREA_BEGIN_OFFSET)
#define FLASH_AREA_0_SIZE               (FLASH_S_PARTITION_SIZE)
/* Control Secure app image primary slot */
#if (FLASH_AREA_0_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_0_OFFSET  not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /*  (FLASH_AREA_0_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

/* Non-secure app image primary slot */
#define FLASH_AREA_1_OFFSET             (FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE)
#define FLASH_AREA_1_SIZE               (FLASH_NS_PARTITION_SIZE)
/* Control Non-secure app image primary slot */
#if (FLASH_AREA_1_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_1_OFFSET  not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /* (FLASH_AREA_1_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0  */


/* flash areas end offset */
#define FLASH_AREA_END_OFFSET           (FLASH_AREA_BEGIN_OFFSET + FLASH_AREA_0_SIZE + FLASH_AREA_1_SIZE)

/* Control flash area end */
#if (FLASH_AREA_END_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0
#error "FLASH_AREA_END_OFFSET  not aligned on FLASH_AREA_IMAGE_SECTOR_SIZE"
#endif /*  (FLASH_AREA_END_OFFSET  % FLASH_AREA_IMAGE_SECTOR_SIZE) != 0 */

#define FLASH_PARTITION_SIZE            (FLASH_S_PARTITION_SIZE+FLASH_NS_PARTITION_SIZE)

#if (FLASH_S_PARTITION_SIZE > FLASH_NS_PARTITION_SIZE)
#define FLASH_MAX_PARTITION_SIZE FLASH_S_PARTITION_SIZE
#else
#define FLASH_MAX_PARTITION_SIZE FLASH_NS_PARTITION_SIZE
#endif


#define SECURE_IMAGE_OFFSET             (0x0)
#define SECURE_IMAGE_MAX_SIZE           FLASH_S_PARTITION_SIZE

#define NON_SECURE_IMAGE_OFFSET         (SECURE_IMAGE_OFFSET + SECURE_IMAGE_MAX_SIZE)
#define NON_SECURE_IMAGE_MAX_SIZE       FLASH_NS_PARTITION_SIZE

/* Flash device name used by BL2 and NV Counter
 * Name is defined in flash driver file: low_level_flash.c
 */
#define TFM_NV_COUNTERS_FLASH_DEV       TFM_Driver_FLASH0
#define FLASH_DEV_NAME                  TFM_Driver_FLASH0
#define TFM_HAL_FLASH_PROGRAM_UNIT       (0x10)

/* Protected Storage (PS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M PS Integration Guide.
 */
#define TFM_HAL_PS_FLASH_DRIVER TFM_Driver_FLASH0

/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address.
 */
#define PS_SECTOR_SIZE                 FLASH_AREA_IMAGE_SECTOR_SIZE
/* The sectors must be in consecutive memory location */
#define PS_NBR_OF_SECTORS              (FLASH_PS_AREA_SIZE / PS_SECTOR_SIZE)
/* The maximum asset size to be stored in the ITS area */
#define ITS_SECTOR_SIZE                 FLASH_AREA_IMAGE_SECTOR_SIZE
/* The sectors must be in consecutive memory location */
#define ITS_NBR_OF_SECTORS              (FLASH_ITS_AREA_SIZE / ITS_SECTOR_SIZE)

/* Base address of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_ADDR    FLASH_PS_AREA_OFFSET
/* Size of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_SIZE    FLASH_PS_AREA_SIZE
#define PS_RAM_FS_SIZE                TFM_HAL_PS_FLASH_AREA_SIZE
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_PS_SECTORS_PER_BLOCK  (1)
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_PS_PROGRAM_UNIT       (0x10)

/* Internal Trusted Storage (ITS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M ITS Integration Guide.
 */
#define TFM_HAL_ITS_FLASH_DRIVER TFM_Driver_FLASH0

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
#define TFM_HAL_ITS_PROGRAM_UNIT       (0x10)
/* OTP area definition */
#define TFM_OTP_NV_COUNTERS_AREA_SIZE    FLASH_OTP_NV_COUNTERS_SECTOR_SIZE
#define TFM_OTP_NV_COUNTERS_AREA_ADDR    FLASH_OTP_NV_COUNTERS_AREA_OFFSET
#define TFM_OTP_NV_COUNTERS_SECTOR_SIZE  FLASH_OTP_NV_COUNTERS_SECTOR_SIZE
#define TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR (TFM_OTP_NV_COUNTERS_AREA_ADDR + \
                                              TFM_OTP_NV_COUNTERS_AREA_SIZE)
/* NV Counters definitions */
#define TFM_NV_COUNTERS_AREA_ADDR        FLASH_NV_COUNTERS_AREA_OFFSET
#define TFM_NV_COUNTERS_AREA_SIZE        (0x20)/* 32 Bytes */
#define TFM_NV_COUNTERS_SECTOR_ADDR      FLASH_NV_COUNTERS_AREA_OFFSET
#define TFM_NV_COUNTERS_SECTOR_SIZE      FLASH_AREA_IMAGE_SECTOR_SIZE

/* BL2 NV Counters definitions  */
#define BL2_NV_COUNTERS_AREA_ADDR        FLASH_BL2_NVCNT_AREA_OFFSET
#define BL2_NV_COUNTERS_AREA_SIZE        FLASH_BL2_NVCNT_AREA_SIZE

/* FIXME: not valid today */
#define BL2_S_RAM_ALIAS_BASE             (0x30000000)
#define BL2_NS_RAM_ALIAS_BASE            (0x20000000)

/*  This area in SRAM 2 is updated BL2 and can be lock to avoid any changes */
#define BOOT_TFM_SHARED_DATA_SIZE        (0x400)
#define BOOT_TFM_SHARED_DATA_BASE        (0x3007fc00)
#define SHARED_BOOT_MEASUREMENT_BASE     BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE     BOOT_TFM_SHARED_DATA_SIZE

#endif /* __FLASH_LAYOUT_H__ */
