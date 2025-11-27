/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef NV_COUNTERS_RRAM_DRIVER_H
#define NV_COUNTERS_RRAM_DRIVER_H

#include "ifx_driver_rram.h"

#define IFX_TFM_NV_COUNTERS_PROGRAM_UNIT    IFX_DRIVER_RRAM_PROGRAM_UNIT
#define IFX_TFM_NV_COUNTERS_SECTOR_SIZE     CY_RRAM_BLOCK_SIZE_BYTES

extern ARM_DRIVER_FLASH ifx_nv_counters_cmsis_flash_instance;
#define IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE    (ifx_nv_counters_cmsis_flash_instance)

#endif /* NV_COUNTERS_RRAM_DRIVER_H */
