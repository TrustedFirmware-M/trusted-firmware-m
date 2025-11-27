/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "nv_counters_rram_driver.h"
#include "region_defs.h"

#define IFX_TFM_NV_COUNTERS_ERASE_VALUE   IFX_DRIVER_RRAM_ERASE_VALUE

static const ifx_driver_rram_obj_t ifx_rram_obj_nv_counters = {
    .rram_base = IFX_RRAMC0,
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

/* RRAM driver instance for NV counters */
IFX_DRIVER_RRAM_CREATE_INSTANCE(ifx_rram_instance_nv_counters, ifx_rram_obj_nv_counters)

/* Create CMSIS wrapper for RRAM driver for NV counters */
IFX_CREATE_CMSIS_FLASH_DRIVER(ifx_rram_instance_nv_counters, ifx_nv_counters_cmsis_flash_instance)
