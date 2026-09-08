/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
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

#include <bl2_image_id.h>
#include <region_defs.h>
#include <device_cfg.h>
#include <devicetree.h>
#include <cmsis_fixed_partitions.h>
#include <soc_config.h>

/*
 * In M33tdcid
 *   Flash image is define in devicetree by labels:
 *      Label					Comment
 *      ---------------------------------------------------------
 *	bl2_primary_partition			BL2 bootloader - MCUboot (retram sz + bootrom padding)
 *	bl2_secondary_partition			BL2 bootloader - MCUboot (retram sz + bootrom padding)
 *	ddr_fw_primary_partition		Primary ddr setting
 *	ddr_fw_secondary_partition		Secondary ddr setting
 *	tfm_primary_partition			Primary image area (tfm_sign.bin)
 *						Secure + Non-Secure image;
 *						Primary memory partition
 *		0x0000_0000 - 0x0000_03ff		Common image header
 *		0x0000_0400 - 0x00x0_xxxx		Secure image
 *		0x0008_xxxx - 0x008x_xxxx		Non-secure image
 *		0x000x_xxxx - 0x0010_0000		Hash value(SHA256), RSA signature and other
 *	tfm_secondary_partition			Secondary slot : Secure + Non-Secure image;
 *						Secondary memory partition, structured
 *						identically to the primary slot
 */
/*
 *
 * Code RAM layout
 *
 *   BL2, only in M33tdcid
 *       0x0E08_0000 - 0x0E0A_0000		BL2  - MCUboot
 *
 *   tfm_s_ns is copied to Z->DDR_RAM_OFFSET
 *   Z:0x0000_0000 - Z:x0010_0000		(tfm_s_ns) image has been copied to ddr:
 *       Z:0x0000_0000 - Z:0x0008_0000		    Secure image
 *       Z:0x0008_0000 - Z:0x0010_0000		    Non-secure image
 *
 * In A35tdcid (copro)
 *   No flash Image, no BL2. A35 copies tfm_s_ns image to Z->DDR_RAM_OFFSET
 *       Z:0x0000_0000 - Z:x0010_0000		(tfm_s_ns) image has been copied to ddr:
 *       Z:0x0000_0000 - Z:0x0008_0000		    Secure image
 *       Z:0x0008_0000 - Z:0x0010_0000		    Non-secure image
 */

/*
 * Offset and size definition in flash area used by assemble.py
 * Image not take account the bl2 header
 *
 * the bl2 header is add after assemble.py
 */
#define SECURE_IMAGE_OFFSET		0x0
#define SECURE_IMAGE_MAX_SIZE		S_CODE_SIZE

#define NON_SECURE_IMAGE_OFFSET		(S_CODE_SIZE)
#define NON_SECURE_IMAGE_MAX_SIZE	NS_CODE_SIZE

#define DDR_RAM_OFFSET			0x0

/* Internal Trusted Storage (ITS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M ITS Integration Guide. The ITS should be in the internal flash, but is
 * allocated in the external flash just for development platforms that don't
 * have internal flash available.
 *
 * constraints:
 * - nb blocks (minimal): 2
 * - block size >= (file size + metadata) aligned on power of 2
 * - file size = config ITS_MAX_ASSET_SIZE
 */
#if ITS_RAM_FS
/* Internal Trusted Storage emulated on RAM FS (ITS_RAM_FS)
 * which use an internal variable (its_block_data in TFM_DATA),
 * Driver_Flash_DDR is not used.
 */
#define TFM_HAL_ITS_FLASH_DRIVER	Driver_FLASH_DDR
#define TFM_HAL_ITS_FLASH_AREA_ADDR	0x0
#define TFM_HAL_ITS_FLASH_AREA_SIZE	4 * FLASH_DDR_SECTOR_SIZE
#define TFM_HAL_ITS_SECTORS_PER_BLOCK	(0x1)
#define TFM_HAL_ITS_PROGRAM_UNIT	FLASH_DDR_PROGRAM_UNIT
#define ITS_RAM_FS_SIZE			TFM_HAL_ITS_FLASH_AREA_SIZE
#else
/* enable backup sram driver */
#define STM32_FLASH_BKPSRAM
#define TFM_HAL_ITS_FLASH_DRIVER	Driver_FLASH_BKPSRAM
#define TFM_HAL_ITS_FLASH_AREA_ADDR	0x1000
#define TFM_HAL_ITS_FLASH_AREA_SIZE	0x1000
#define TFM_HAL_ITS_SECTORS_PER_BLOCK	(0x2)
#define TFM_HAL_ITS_PROGRAM_UNIT	FLASH_BKPSRAM_PROGRAM_UNIT
#define ITS_RAM_FS_SIZE			TFM_HAL_ITS_FLASH_AREA_SIZE
#endif

#ifndef OTP_NV_COUNTERS_RAM_EMULATION
/* NV Counters: valide & backup (Backup register) */
#define NV_COUNTERS_FLASH_DRIVER	Driver_FLASH_BKPREG
#define NV_COUNTERS_AREA_SIZE		(0x1C) /* 28 Bytes */
#define NV_COUNTERS_AREA_ADDR		0x60
#endif

/* Protected Storage (PS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M PS Integration Guide.
 *
 * constraints:
 *  - nb blocks (minimal): 2
 *  - block size >= (file size + metadata) aligned on power of 2
 *  - file size = config PS_MAX_ASSET_SIZE
 */
#if PS_RAM_FS
/* Protected Storage emulated on RAM FS (PS_RAM_FS)
 * which use an internal variable (ps_block_data in TFM_DATA),
 * Driver_Flash_DDR is not used.
 */
#define TFM_HAL_PS_FLASH_DRIVER		Driver_FLASH_DDR
#define TFM_HAL_PS_FLASH_AREA_ADDR	0x0
#define TFM_HAL_PS_FLASH_AREA_SIZE	4 * FLASH_DDR_SECTOR_SIZE
#define TFM_HAL_PS_SECTORS_PER_BLOCK	(0x1)
#define TFM_HAL_PS_PROGRAM_UNIT		FLASH_DDR_PROGRAM_UNIT
#define PS_RAM_FS_SIZE			TFM_HAL_PS_FLASH_AREA_SIZE
#else
/* enable backup register driver */
#define STM32_FLASH_BKPREG
#define TFM_HAL_PS_FLASH_DRIVER		DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(tfm_ps_partition)
#define TFM_HAL_PS_FLASH_AREA_ADDR	DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(tfm_ps_partition)
#define TFM_HAL_PS_FLASH_AREA_SIZE	DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(tfm_ps_partition)
#define TFM_HAL_PS_SECTORS_PER_BLOCK	(0x1)
#define TFM_HAL_PS_PROGRAM_UNIT		(0x1)
#endif

#ifdef STM32_M33TDCID

/* No flash base address on stm32mp2 but required for flash_map.h */
#define FLASH_BASE_ADDRESS		(0x00000000)

#define FLASH_AREA_IMAGE_SECTOR_SIZE	TFM_HAL_FLASH_PROGRAM_UNIT

/*
 * Not used, only the RAM loading firmware upgrade operation
 * is supported on STM32MP2. The maximum number of status entries
 * supported by the bootloader.
 */
#define MCUBOOT_STATUS_MAX_ENTRIES	(0)
/* Maximum number of image sectors supported by the bootloader. */
#define MCUBOOT_MAX_IMG_SECTORS		((IMAGE_S_CODE_SIZE + \
					  IMAGE_NS_CODE_SIZE) / \
					 TFM_HAL_FLASH_PROGRAM_UNIT)

#if !defined(MCUBOOT_IMAGE_NUMBER) || (MCUBOOT_IMAGE_NUMBER == 2) || (MCUBOOT_IMAGE_NUMBER == 3)
#if (STM32_BL2 || STM32_FWU_STORAGE_ACCESS)
#define FLASH_AREA_0_ID			(1)
#define FLASH_DEVICE_ID_0		100
#define FLASH_AREA_1_ID			(FLASH_AREA_0_ID + 1)
#define FLASH_DEVICE_ID_1		101
#define FLASH_AREA_2_ID			(FLASH_AREA_1_ID + 1)
#define FLASH_DEVICE_ID_2		102
#define FLASH_AREA_3_ID			(FLASH_AREA_2_ID + 1)
#define FLASH_DEVICE_ID_3		103
#define FLASH_AREA_4_ID			(FLASH_AREA_3_ID + 1)
#define FLASH_DEVICE_ID_4		104
#define FLASH_AREA_5_ID			(FLASH_AREA_4_ID + 1)
#define FLASH_DEVICE_ID_5		105

#ifdef STM32_BOOT_DEV_OSPI
#define FLASH_DEV_NAME			FLASH_DEV_NAME_0
/* Secure + Non-secure image primary slot */
#define FLASH_DEV_NAME_0		DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(tfm_primary_partition)
#define FLASH_AREA_0_OFFSET		DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(tfm_primary_partition)
#define FLASH_AREA_0_SIZE		DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(tfm_primary_partition)
/* Secure + Non-secure secondary slot */
#define FLASH_DEV_NAME_2		DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(tfm_secondary_partition)
#define FLASH_AREA_2_OFFSET		DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(tfm_secondary_partition)
#define FLASH_AREA_2_SIZE		DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(tfm_secondary_partition)
#define TFM_HAL_FLASH_PROGRAM_UNIT	SPI_NOR_FLASH_PAGE_SIZE

/* DDR Firmware primary slot */
#define FLASH_DEV_NAME_1		DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(ddr_fw_primary_partition)
#define FLASH_AREA_1_OFFSET		DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(ddr_fw_primary_partition)
#define FLASH_AREA_1_SIZE		DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(ddr_fw_primary_partition)
/* DDR Firmware secondary slot */
#define FLASH_DEV_NAME_3		DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(ddr_fw_secondary_partition)
#define FLASH_AREA_3_OFFSET	        DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(ddr_fw_secondary_partition)
#define FLASH_AREA_3_SIZE		DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(ddr_fw_secondary_partition)

/* Cortex A35 firmware primary slot */
#define FLASH_DEV_NAME_4		DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(ca35_fw_primary_partition)
#define FLASH_AREA_4_OFFSET	        DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(ca35_fw_primary_partition)
#define FLASH_AREA_4_SIZE		DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(ca35_fw_primary_partition)
/* Cortex A35 firmware secondary slot */
#define FLASH_DEV_NAME_5		DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(ca35_fw_secondary_partition)
#define FLASH_AREA_5_OFFSET	        DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(ca35_fw_secondary_partition)
#define FLASH_AREA_5_SIZE		DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(ca35_fw_secondary_partition)
#endif

#ifdef STM32_BOOT_DEV_SDMMC1
#define STM32_FLASH_SDMMC1
#define FLASH_DEV_NAME			Driver_sdmmc1
#endif

#ifdef STM32_BOOT_DEV_SDMMC2
#define STM32_FLASH_SDMMC2
#define FLASH_DEV_NAME			Driver_sdmmc2
#endif

#if defined(STM32_BOOT_DEV_SDMMC1) || defined(STM32_BOOT_DEV_SDMMC2)
#define IMAGE_S_CODE_SIZE		DT_REG_SIZE(DT_NODELABEL(tfm_code))
#define IMAGE_NS_CODE_SIZE		DT_REG_SIZE(DT_NODELABEL(cm33_cube_fw))
#define IMAGE_EXECUTABLE_RAM_SIZE	(IMAGE_S_CODE_SIZE + IMAGE_NS_CODE_SIZE)
#define FLASH_DEV_NAME_0		FLASH_DEV_NAME
#define FLASH_AREA_0_OFFSET		0
#define FLASH_AREA_0_SIZE		STM32MP_M33_FW_SLOT_SIZE
/* Secure + Non-secure secondary slot */
#define FLASH_DEV_NAME_2		FLASH_DEV_NAME
#define FLASH_AREA_2_OFFSET		0
#define FLASH_AREA_2_SIZE		STM32MP_M33_FW_SLOT_SIZE
#define TFM_HAL_FLASH_PROGRAM_UNIT	512
/* DDR Firmware primary slot */
#define FLASH_DEV_NAME_1		FLASH_DEV_NAME
#define FLASH_AREA_1_OFFSET		0
#define FLASH_AREA_1_SIZE		STM32MP_DDR_FW_SLOT_SIZE
/* DDR Firmware secondary slot */
#define FLASH_DEV_NAME_3		FLASH_DEV_NAME
#define FLASH_AREA_3_OFFSET	        0
#define FLASH_AREA_3_SIZE		STM32MP_DDR_FW_SLOT_SIZE
/* Cortex A35 firmware primary slot */
#define FLASH_DEV_NAME_4		FLASH_DEV_NAME
#define FLASH_AREA_4_OFFSET	        0
#define FLASH_AREA_4_SIZE		STM32_CA35_FW_SLOT_SIZE
/* Cortex A35 firmware secondary slot */
#define FLASH_DEV_NAME_5		FLASH_DEV_NAME
#define FLASH_AREA_5_OFFSET	        0
#define FLASH_AREA_5_SIZE		STM32_CA35_FW_SLOT_SIZE
#endif

#if (MCUBOOT_IMAGE_NUMBER == 3)
#define FLASH_AREA_IMAGE_PRIMARY(x)     (((x) == TFM_S_NS_ID) ? FLASH_AREA_0_ID : \
                                         ((x) == DDR_FIRMWARE_ID) ? FLASH_AREA_1_ID : \
                                         ((x) == CA35_FIRMWARE_ID) ? FLASH_AREA_4_ID : \
                                         255 )
#define FLASH_AREA_IMAGE_SECONDARY(x)   (((x) == TFM_S_NS_ID) ? FLASH_AREA_2_ID : \
                                         ((x) == DDR_FIRMWARE_ID) ? FLASH_AREA_3_ID : \
                                         ((x) == CA35_FIRMWARE_ID) ? FLASH_AREA_5_ID : \
                                         255 )
#else
#define FLASH_AREA_IMAGE_PRIMARY(x)     (((x) == TFM_S_NS_ID) ? FLASH_AREA_0_ID : \
                                         ((x) == DDR_FIRMWARE_ID) ? FLASH_AREA_1_ID : \
                                         255 )
#define FLASH_AREA_IMAGE_SECONDARY(x)   (((x) == TFM_S_NS_ID) ? FLASH_AREA_2_ID : \
                                         ((x) == DDR_FIRMWARE_ID) ? FLASH_AREA_3_ID : \
                                         255 )
#endif

/*
 * On stm32mp2, only the RAM loading firmware upgrade operation
 * is supported. The scratch area is not used
 */
#if (MCUBOOT_IMAGE_NUMBER == 3)
#define FLASH_AREA_SCRATCH_ID		(FLASH_AREA_5_ID + 1)
#else
#define FLASH_AREA_SCRATCH_ID		(FLASH_AREA_3_ID + 1)
#endif
#define FLASH_AREA_IMAGE_SCRATCH        255

/*
 * DDR firmware is copied from boot device to mcuram memory
 *   - boot device is defined by ddr_fw_primary_partition of dt
 *   - mcuram is defined reserved memory of dt
 *
 *   considerate the mcuram like the max size of ddr fw size
 */
#define DDR_FW_SIZE			DT_REG_SIZE(DT_NODELABEL(ddr_fw_buffer)) /* exclusif for ddr */
#define DDR_FW_DEST_ADDR		DT_REG_ADDR(DT_NODELABEL(ddr_fw_buffer))

/* Cortex-A35 firmware */
#define CA35_FW_SIZE			DT_REG_SIZE(DT_NODELABEL(ca35_cube_fw))
#define CA35_FW_DEST_ADDR		DT_REG_ADDR(DT_NODELABEL(ca35_cube_fw))
#endif /* (STM32_BL2 || STM32_FWU_STORAGE_ACCESS) */
#else /* MCUBOOT_IMAGE_NUMBER > 3 */
#error "Only MCUBOOT_IMAGE_NUMBER 2 or 3 is supported!"
#endif /* MCUBOOT_IMAGE_NUMBER */

#endif /* STM32_M33TDCID */

#endif /* __FLASH_LAYOUT_H__ */
