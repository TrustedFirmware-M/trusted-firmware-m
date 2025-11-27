/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
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

/* ifx_driver_rram.h is used for definition of IFX_DRIVER_RRAM_PROGRAM_UNIT and
 * is only needed for tfm_hal_its.h file. Thus, to avoid adding RRAM driver
 * to include directories of all other libs that use flash_layout.h, include
 * of ifx_driver_rram.h is made conditional.
 * Also it is done outside of FLASH_LAYOUT_H include guard as tfm_hal_its.h
 * may not be the first file that includes flash_layout.h */
#ifdef __TFM_HAL_ITS_H__
#include "ifx_driver_rram.h"
#endif /* __TFM_HAL_ITS_H__ */

#ifndef FLASH_LAYOUT_H
#define FLASH_LAYOUT_H

#include "config_tfm.h"
/* Include TrustZone configurator generated file with memory areas definitions */
#include "project_memory_layout.h"

/*******************************************************************************
************************************** PS **************************************
*******************************************************************************/

#ifdef TFM_PARTITION_PROTECTED_STORAGE
#if PS_RAM_FS

#ifndef PS_RAM_FS_SIZE
/* Size of RAM allocated for RAM PS flash driver */
#define PS_RAM_FS_SIZE                  0x4000 /* 16KB */
#endif
#ifndef PS_RAM_FS_BLOCK_SIZE
/* Block size of RAM PS flash driver */
#define PS_RAM_FS_BLOCK_SIZE            0x1000 /* 4KB */
#endif

/* Smallest flash programmable unit in bytes */
#define TFM_HAL_PS_PROGRAM_UNIT         (0x4)

#else /* PS_RAM_FS */

/* Protected Storage (PS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M PS Integration Guide. */
#define TFM_HAL_PS_FLASH_DRIVER         ifx_ps_cmsis_flash_instance
/* Size of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_SIZE      IFX_TFM_PS_SIZE
/* Size of logical FS block */
#ifndef TFM_HAL_PS_BLOCK_SIZE
#define TFM_HAL_PS_BLOCK_SIZE           (0x1000) /* 4 KB */
#endif /* TFM_HAL_PS_BLOCK_SIZE */
#ifndef PS_FLASH_NAND_BUF_SIZE
/* Size of buffer for NAND driver in bytes. Must not be less than logical block size. */
#define PS_FLASH_NAND_BUF_SIZE          (0x1000) /* 4 KB */
#endif /* PS_FLASH_NAND_BUF_SIZE */

#if IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION)
/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address. */
#define TFM_HAL_PS_FLASH_AREA_ADDR      0
#ifndef TFM_HAL_PS_PROGRAM_UNIT
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_PS_PROGRAM_UNIT         (512) /* 256/512 page size for S25HS512T */
#endif /* TFM_HAL_PS_PROGRAM_UNIT */
#elif IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_RRAM
/* Base address of dedicated flash area for PS */
#define TFM_HAL_PS_FLASH_AREA_ADDR      IFX_TFM_PS_ADDR
#ifndef TFM_HAL_PS_PROGRAM_UNIT
/* Smallest flash programmable unit in bytes */
#define TFM_HAL_PS_PROGRAM_UNIT         (0x4) /* 4 bytes for RRAM */
/* Instance of RRAM controller */
#define IFX_HAL_PS_FLASH_RRAM_BASE     IFX_RRAMC0
/* IFX_HAL_PS_FLASH_RRAM_SECTOR_SIZE is set to TFM_HAL_PS_BLOCK_SIZE, this way
 * erase_sector operation will be called only once for whole
 * TFM_HAL_PS_BLOCK_SIZE. This removes overhead of calling erase_sector for
 * each of CY_RRAM_BLOCK_SIZE_BYTES */
#define IFX_HAL_PS_FLASH_RRAM_SECTOR_SIZE  TFM_HAL_PS_BLOCK_SIZE
#endif /* TFM_HAL_PS_PROGRAM_UNIT */
#else /* IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION) */
#error Unsupported IFX_TFM_PS_LOCATION
#endif /* IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION) */

#endif /* PS_RAM_FS */
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

/*******************************************************************************
************************************* ITS **************************************
*******************************************************************************/

#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
#if ITS_RAM_FS

#ifndef ITS_RAM_FS_SIZE
/* Size of RAM allocated for RAM ITS flash driver */
#define ITS_RAM_FS_SIZE                 0x4000 /* 16KB */
#endif
#ifndef ITS_RAM_FS_BLOCK_SIZE
/* Block size of RAM ITS flash driver */
#define ITS_RAM_FS_BLOCK_SIZE           0x1000 /* 4KB */
#endif

/* Smallest flash programmable unit in bytes */
#define TFM_HAL_ITS_PROGRAM_UNIT        (0x4)

#else /* ITS_RAM_FS */

/* Instance of RRAM controller */
#define IFX_HAL_ITS_FLASH_RRAM_BASE     IFX_RRAMC0

/* Internal Trusted Storage (ITS) Service definitions
 * Note: Further documentation of these definitions can be found in the
 * TF-M ITS Integration Guide. */
#define TFM_HAL_ITS_FLASH_DRIVER        ifx_its_cmsis_flash_instance
/* In this target the CMSIS driver requires only the offset from the base
 * address instead of the full memory address. */
/* Base address of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_ADDR     IFX_TFM_ITS_ADDR
/* Size of dedicated flash area for ITS */
#define TFM_HAL_ITS_FLASH_AREA_SIZE     IFX_TFM_ITS_SIZE
/* Size of logical FS block */
#ifndef TFM_HAL_ITS_BLOCK_SIZE
#define TFM_HAL_ITS_BLOCK_SIZE          (0x0800) /* 2 KB */
#endif /* TFM_HAL_ITS_BLOCK_SIZE */
/* Number of physical erase sectors per logical FS block */
#define TFM_HAL_ITS_SECTORS_PER_BLOCK  (2) 

/* IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE is set to TFM_HAL_ITS_BLOCK_SIZE, this way
 * erase_sector operation will be called only once for whole
 * TFM_HAL_ITS_BLOCK_SIZE. This removes overhead of calling erase_sector for
 * each of CY_RRAM_BLOCK_SIZE_BYTES */
#define IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE  TFM_HAL_ITS_BLOCK_SIZE

/* Smallest flash programmable unit in bytes */
#define TFM_HAL_ITS_PROGRAM_UNIT        IFX_DRIVER_RRAM_PROGRAM_UNIT

#endif /* ITS_RAM_FS */
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

#endif /* FLASH_LAYOUT_H */
