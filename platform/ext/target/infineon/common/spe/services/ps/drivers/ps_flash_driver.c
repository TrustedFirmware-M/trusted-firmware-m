/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "region_defs.h"

#ifndef IFX_TFM_PS_LOCATION
#error "IFX_TFM_PS_LOCATION is not defined"
#endif /* IFX_TFM_PS_LOCATION */

#if defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_FLASH)
#include "ifx_driver_flash.h"
#include "tfm_peripherals_def.h"

/* FLASH driver object for Internal Trusted Storage */
static const ifx_driver_flash_obj_t ifx_flash_obj_ps = {
    .start_address = TFM_HAL_PS_FLASH_AREA_ADDR,
    .flash_info = {
        /* Sector layout information (NULL=Uniform sectors) */
        .sector_info  = NULL,
        /* Number of sectors */
        .sector_count = TFM_HAL_PS_FLASH_AREA_SIZE / IFX_DRIVER_FLASH_SECTOR_SIZE,
        /* Uniform sector size in bytes (0=sector_info used) */
        .sector_size  = IFX_DRIVER_FLASH_SECTOR_SIZE,
        /* Optimal programming page size in bytes */
        .page_size    = IFX_DRIVER_FLASH_SECTOR_SIZE,
        /* Smallest programmable unit in bytes */
        .program_unit = IFX_DRIVER_FLASH_PROGRAM_UNIT,
        /* Contents of erased memory (usually 0xFF) */
        .erased_value = IFX_DRIVER_FLASH_ERASE_VALUE,
    }
};

/* FLASH PS FS driver for Internal Trusted Storage */
IFX_DRIVER_FLASH_CREATE_INSTANCE(ifx_flash_instance_ps, ifx_flash_obj_ps)

/* Create CMSIS wrapper for FLASH driver for PS */
IFX_CREATE_CMSIS_FLASH_DRIVER(ifx_flash_instance_ps, ifx_ps_cmsis_flash_instance)
#endif /* defined(IFX_MEMORY_TYPE_FLASH) && (IFX_TFM_PS_LOCATION == IFX_MEMORY_TYPE_FLASH) */
