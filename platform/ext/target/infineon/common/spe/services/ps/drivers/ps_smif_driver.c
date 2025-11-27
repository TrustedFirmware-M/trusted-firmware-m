/*
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "region_defs.h"

#if !PS_RAM_FS && IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION)
#include "ifx_driver_smif.h"
#include "tfm_peripherals_def.h"

/* Flash info for Protected Storage SMIF ITS FS driver */
struct _ARM_FLASH_INFO ifx_flash_smif_instance_ps_flash_info;

/* SMIF driver object for Protected Storage */
const struct ifx_driver_smif_obj_t ifx_flash_smif_instance_ps = {
    .memory = &IFX_TFM_PS_SMIF_MEMORY_CONFIG,
    .offset = IFX_TFM_PS_OFFSET,
    .size = IFX_TFM_PS_SIZE,
    .flash_info = &ifx_flash_smif_instance_ps_flash_info,
};

/* SMIF driver for Protected Storage */
IFX_DRIVER_SMIF_MMIO_INSTANCE(ifx_flash_instance_ps, ifx_flash_smif_instance_ps)

/* Create CMSIS wrapper for SMIF driver for Protected Storage */
IFX_CREATE_CMSIS_FLASH_DRIVER(ifx_flash_instance_ps, ifx_ps_cmsis_flash_instance)
#endif /* !PS_RAM_FS && IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION) */
