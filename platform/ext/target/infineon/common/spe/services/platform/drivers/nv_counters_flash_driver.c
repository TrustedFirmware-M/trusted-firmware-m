/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "nv_counters_flash_driver.h"
#include "region_defs.h"
#include "coverity_check.h"

#define IFX_TFM_NV_COUNTERS_ERASE_VALUE   IFX_DRIVER_FLASH_ERASE_VALUE

static const ifx_driver_flash_obj_t ifx_flash_obj_nv_counters = {
    .start_address = IFX_TFM_NV_COUNTERS_AREA_ADDR,
    .flash_info = {
        /* Sector layout information (NULL=Uniform sectors) */
        .sector_info  = NULL,

        .sector_count = IFX_TFM_NV_COUNTERS_AREA_SIZE / IFX_TFM_NV_COUNTERS_SECTOR_SIZE,

        /* Uniform sector size in bytes (0=sector_info used) */
        .sector_size  = IFX_TFM_NV_COUNTERS_SECTOR_SIZE,
        /* Optimal programming page size in bytes */
        .page_size    = IFX_TFM_NV_COUNTERS_SECTOR_SIZE,
        /* Smallest programmable unit in bytes */
        .program_unit = IFX_TFM_NV_COUNTERS_PROGRAM_UNIT,
        /* Contents of erased memory (usually 0xFF) */
        .erased_value = IFX_TFM_NV_COUNTERS_ERASE_VALUE,
    }
};

#if IFX_DRIVER_FLASH_SINGLE_INSTANCE
/* FLASH driver single instance for NV counters */
IFX_DRIVER_FLASH_DEFINE_SINGLE_INSTANCE(ifx_flash_obj_nv_counters)
#else
/* FLASH driver instance for NV counters */
IFX_DRIVER_FLASH_CREATE_INSTANCE(ifx_flash_instance_nv_counters, ifx_flash_obj_nv_counters)

/* Create CMSIS wrapper for FLASH driver for NV counters */
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_20_7, "Checked this part with preprocessor(-E option) and identified as not an issue")
IFX_CREATE_CMSIS_FLASH_DRIVER(ifx_flash_instance_nv_counters, ifx_nv_counters_cmsis_flash_instance)

#endif /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */
