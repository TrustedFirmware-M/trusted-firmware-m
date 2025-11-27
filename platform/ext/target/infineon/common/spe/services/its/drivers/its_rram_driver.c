/*
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"

#if !ITS_RAM_FS && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_RRAM)
#include "ifx_driver_rram.h"
#include "partition/flash_layout.h"

#include "cy_device.h"

/* RRAM driver object for Internal Trusted Storage */
static const ifx_driver_rram_obj_t ifx_rram_obj_its = {
    .rram_base = IFX_HAL_ITS_FLASH_RRAM_BASE,
    .start_address = TFM_HAL_ITS_FLASH_AREA_ADDR,
    .flash_info = {
        /* Sector layout information (NULL=Uniform sectors) */
        .sector_info = NULL,
        /* Number of sectors */
        .sector_count = TFM_HAL_ITS_FLASH_AREA_SIZE / IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE,
        /* Uniform sector size in bytes (0=sector_info used) */
        .sector_size = IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE,
        /* Optimal programming page size in bytes */
        .page_size = IFX_HAL_ITS_FLASH_RRAM_SECTOR_SIZE,
        /* Smallest programmable unit in bytes */
        .program_unit = IFX_DRIVER_RRAM_PROGRAM_UNIT,
        /* Contents of erased memory (usually 0xFF) */
        .erased_value = IFX_DRIVER_RRAM_ERASE_VALUE,
    },
};

/* RRAM ITS FS driver for Internal Trusted Storage */
IFX_DRIVER_RRAM_CREATE_INSTANCE(ifx_flash_instance_its, ifx_rram_obj_its)

/* Create CMSIS wrapper for RRAM driver for ITS */
IFX_CREATE_CMSIS_FLASH_DRIVER(ifx_flash_instance_its, ifx_its_cmsis_flash_instance)

#endif /* !ITS_RAM_FS && (IFX_TFM_ITS_LOCATION == IFX_MEMORY_TYPE_RRAM) */
