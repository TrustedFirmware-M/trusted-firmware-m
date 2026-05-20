/*
 * Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "project_memory_layout.h"

#ifdef TFM_PARTITION_PROTECTED_STORAGE
#ifndef IFX_TFM_PS_LOCATION
#error "IFX_TFM_PS_LOCATION is not defined"
#endif /* IFX_TFM_PS_LOCATION */

/* Include only the backend driver definitions needed by tfm_hal_ps.h or
 * tfm_hal_its.h to avoid expanding include paths for unrelated libraries. This
 * stays outside the guard so a later include through tfm_hal_ps.h/tfm_hal_its.h
 * still pulls the required backend definitions. */
#ifdef __TFM_HAL_PS_H__
#if defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_FLASH)
#include "ifx_driver_flash.h"
#elif defined(IFX_MEMORY_TYPE_RRAM) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_RRAM)
#include "ifx_driver_rram.h"
#elif IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION)
/* SMIF driver uses run time values, thus no include is needed */
#else /* defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_FLASH) */
#error Unsupported PS location
#endif /* defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_FLASH) */
#endif /* __TFM_HAL_PS_H__ */
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
#ifndef IFX_TFM_ITS_LOCATION
#error "IFX_TFM_ITS_LOCATION is not defined"
#endif /* IFX_TFM_ITS_LOCATION */

#ifdef __TFM_HAL_ITS_H__
#if defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_FLASH)
#include "ifx_driver_flash.h"
#elif defined(IFX_MEMORY_TYPE_RRAM) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_RRAM)
#include "ifx_driver_rram.h"
#else /* defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_FLASH) */
#error Unsupported ITS location
#endif /* defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_FLASH) */
#endif /* __TFM_HAL_ITS_H__ */
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

#ifndef IFX_COMMON_FLASH_LAYOUT_H
#define IFX_COMMON_FLASH_LAYOUT_H


/*******************************************************************************
************************************* ITS **************************************
*******************************************************************************/


#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE

#define TFM_HAL_ITS_FLASH_DRIVER       	ifx_its_cmsis_flash_instance

#define TFM_HAL_ITS_FLASH_AREA_ADDR    	IFX_TFM_ITS_ADDR
#define TFM_HAL_ITS_FLASH_AREA_SIZE    	IFX_TFM_ITS_SIZE

/* TF-M derives the filesystem block size from the flash sector size and the
 * platform-provided sectors-per-block value. Infineon platforms define a
 * desired block size first and calculate sectors-per-block from it. This keeps
 * the layout easy to reason about: the block size is known, the number of
 * filesystem blocks is predictable, and different platforms can use a uniform
 * logical block size even when their flash sector sizes differ.
 */
#ifndef IFX_ITS_BLOCK_SIZE
#define IFX_ITS_BLOCK_SIZE         		(0x800U) /* 2 KB */
#endif /* IFX_ITS_BLOCK_SIZE */

#ifndef ITS_RAM_FS_SIZE
/* The flash filesystem accepts either 2 blocks or 4+ blocks; 3 blocks is invalid.
 * Although 2 blocks is the minimum valid layout, it is too small for running
 * tests. Use 4 blocks to provide enough room while staying at the smallest
 * supported size above the minimum.
 */
#define ITS_RAM_FS_SIZE                	(IFX_ITS_BLOCK_SIZE * 4U)
#endif /* ITS_RAM_FS_SIZE */

#if defined(IFX_MEMORY_TYPE_RRAM) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_RRAM)
#ifndef IFX_HAL_ITS_FLASH_RRAM_BASE
#define IFX_HAL_ITS_FLASH_RRAM_BASE     IFX_RRAMC0
#endif /* IFX_HAL_ITS_FLASH_RRAM_BASE */

/* IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE is set to IFX_ITS_BLOCK_SIZE, this way
 * erase_sector operation will be called only once for whole
 * IFX_ITS_BLOCK_SIZE. This removes overhead of calling erase_sector for
 * each of CY_RRAM_BLOCK_SIZE_BYTES */
#ifndef IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE
#define IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE IFX_ITS_BLOCK_SIZE
#endif /* IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE */

#ifndef TFM_HAL_ITS_PROGRAM_UNIT
#define TFM_HAL_ITS_PROGRAM_UNIT        IFX_DRIVER_RRAM_PROGRAM_UNIT
#endif /* TFM_HAL_ITS_PROGRAM_UNIT */

/* TFM_HAL_ITS_SECTORS_PER_BLOCK is calculated based on the block size and the sector size */
#ifndef TFM_HAL_ITS_SECTORS_PER_BLOCK
#define TFM_HAL_ITS_SECTORS_PER_BLOCK   (IFX_ITS_BLOCK_SIZE / IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE)
#endif /* TFM_HAL_ITS_SECTORS_PER_BLOCK */

#elif defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_FLASH)
#ifndef TFM_HAL_ITS_PROGRAM_UNIT
#define TFM_HAL_ITS_PROGRAM_UNIT        IFX_DRIVER_FLASH_PROGRAM_UNIT
#endif /* TFM_HAL_ITS_PROGRAM_UNIT */

/* TFM_HAL_ITS_SECTORS_PER_BLOCK is calculated based on the block size and the sector size */
#ifndef TFM_HAL_ITS_SECTORS_PER_BLOCK
#define TFM_HAL_ITS_SECTORS_PER_BLOCK   (IFX_ITS_BLOCK_SIZE / IFX_DRIVER_FLASH_SECTOR_SIZE)
#endif /* TFM_HAL_ITS_SECTORS_PER_BLOCK */
#else /* defined(IFX_MEMORY_TYPE_RRAM) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_RRAM) */
#error Unsupported ITS location
#endif /* defined(IFX_MEMORY_TYPE_RRAM) && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_RRAM) */
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */


/*******************************************************************************
************************************** PS **************************************
*******************************************************************************/


#ifdef TFM_PARTITION_PROTECTED_STORAGE

#define TFM_HAL_PS_FLASH_DRIVER         ifx_ps_cmsis_flash_instance

#define TFM_HAL_PS_FLASH_AREA_SIZE      IFX_TFM_PS_SIZE

/* TF-M derives the filesystem block size from the flash sector size and the
 * platform-provided sectors-per-block value. Infineon platforms define a
 * desired block size first and calculate sectors-per-block from it. This keeps
 * the layout easy to reason about: the block size is known, the number of
 * filesystem blocks is predictable, and different platforms can use a uniform
 * logical block size even when their flash sector sizes differ.
 */
#ifndef IFX_PS_BLOCK_SIZE
#define IFX_PS_BLOCK_SIZE               (0x1000U) /* 4 KB */
#endif /* IFX_PS_BLOCK_SIZE */

#ifndef PS_RAM_FS_SIZE
/* The flash filesystem accepts either 2 blocks or 4+ blocks; 3 blocks is invalid.
 * Although 2 blocks is the minimum valid layout, it is too small for running
 * tests. Use 4 blocks to provide enough room while staying at the smallest
 * supported size above the minimum.
 */
#define PS_RAM_FS_SIZE                  (IFX_PS_BLOCK_SIZE * 4U)
#endif /* PS_RAM_FS_SIZE */

#ifndef PS_FLASH_NAND_BUF_SIZE
#define PS_FLASH_NAND_BUF_SIZE          IFX_PS_BLOCK_SIZE
#endif /* PS_FLASH_NAND_BUF_SIZE */

#if IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION)
/* The SMIF-backed CMSIS driver uses an offset within the selected external
 * memory device instead of an absolute address. */
#define TFM_HAL_PS_FLASH_AREA_ADDR      0

#ifndef IFX_TFM_PS_SMIF_PROGRAM_UNIT
#define IFX_TFM_PS_SMIF_PROGRAM_UNIT    (512U)
#endif /* IFX_TFM_PS_SMIF_PROGRAM_UNIT */

#ifndef TFM_HAL_PS_PROGRAM_UNIT
#define TFM_HAL_PS_PROGRAM_UNIT         IFX_TFM_PS_SMIF_PROGRAM_UNIT
#endif /* TFM_HAL_PS_PROGRAM_UNIT */

/* SMIF has no compile-time sector size, so define it based on the runtime value
 * from the flash driver. */
#ifndef TFM_HAL_PS_SECTORS_PER_BLOCK
#define TFM_HAL_PS_SECTORS_PER_BLOCK    (IFX_PS_BLOCK_SIZE /
						                 (TFM_HAL_PS_FLASH_DRIVER.GetInfo()->sector_size))
#endif /* TFM_HAL_PS_SECTORS_PER_BLOCK */

#elif defined(IFX_MEMORY_TYPE_RRAM) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_RRAM)
#define TFM_HAL_PS_FLASH_AREA_ADDR      IFX_TFM_PS_ADDR

#ifndef IFX_HAL_PS_FLASH_RRAM_BASE
#define IFX_HAL_PS_FLASH_RRAM_BASE      IFX_RRAMC0
#endif /* IFX_HAL_PS_FLASH_RRAM_BASE */

/* IFX_HAL_PS_FLASH_RRAM_SECTOR_SIZE is set to IFX_PS_BLOCK_SIZE, this way
 * erase_sector operation will be called only once for whole
 * IFX_PS_BLOCK_SIZE. This removes overhead of calling erase_sector for
 * each of CY_RRAM_BLOCK_SIZE_BYTES */
#ifndef IFX_HAL_PS_FLASH_RRAM_SECTOR_SIZE
#define IFX_HAL_PS_FLASH_RRAM_SECTOR_SIZE IFX_PS_BLOCK_SIZE
#endif /* IFX_HAL_PS_FLASH_RRAM_SECTOR_SIZE */

#ifndef TFM_HAL_PS_PROGRAM_UNIT
#define TFM_HAL_PS_PROGRAM_UNIT         IFX_DRIVER_RRAM_PROGRAM_UNIT
#endif /* TFM_HAL_PS_PROGRAM_UNIT */

#ifndef TFM_HAL_PS_SECTORS_PER_BLOCK
#define TFM_HAL_PS_SECTORS_PER_BLOCK    (IFX_PS_BLOCK_SIZE / IFX_HAL_PS_FLASH_RRAM_SECTOR_SIZE)
#endif /* TFM_HAL_PS_SECTORS_PER_BLOCK */

#elif defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_FLASH)
#define TFM_HAL_PS_FLASH_AREA_ADDR      IFX_TFM_PS_ADDR

#ifndef TFM_HAL_PS_PROGRAM_UNIT
#define TFM_HAL_PS_PROGRAM_UNIT         IFX_DRIVER_FLASH_PROGRAM_UNIT
#endif /* TFM_HAL_PS_PROGRAM_UNIT */

#ifndef TFM_HAL_PS_SECTORS_PER_BLOCK
#define TFM_HAL_PS_SECTORS_PER_BLOCK    (IFX_PS_BLOCK_SIZE / IFX_DRIVER_FLASH_SECTOR_SIZE)
#endif /* TFM_HAL_PS_SECTORS_PER_BLOCK */
#else /* IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION) */
#error Unsupported PS storage backend
#endif /* IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION) */
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

#endif /* IFX_COMMON_FLASH_LAYOUT_H */
