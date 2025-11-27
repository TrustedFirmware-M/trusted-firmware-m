/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef NV_COUNTERS_FLASH_DRIVER_H
#define NV_COUNTERS_FLASH_DRIVER_H

#include "ifx_driver_flash.h"

#define IFX_TFM_NV_COUNTERS_PROGRAM_UNIT  IFX_DRIVER_FLASH_PROGRAM_UNIT

#define IFX_TFM_NV_COUNTERS_SECTOR_SIZE   IFX_DRIVER_FLASH_SECTOR_SIZE

#if IFX_DRIVER_FLASH_SINGLE_INSTANCE
extern ARM_DRIVER_FLASH ifx_cmsis_driver_flash;
#define IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE    (ifx_cmsis_driver_flash)
#else
extern ARM_DRIVER_FLASH ifx_nv_counters_cmsis_flash_instance;
#define IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE    (ifx_nv_counters_cmsis_flash_instance)
#endif /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */

#endif /* NV_COUNTERS_FLASH_DRIVER_H */
