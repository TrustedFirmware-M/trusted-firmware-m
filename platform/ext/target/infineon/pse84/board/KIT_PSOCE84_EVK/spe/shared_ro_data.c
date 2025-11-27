/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file shared_ro_data.c
 * \brief This file contains shared data that can be read/write within SPM
 * and read-only from any secure partition.
 */


#include "ifx_driver_smif.h"
#include "cycfg_qspi_memslot.h"
#include "tfm_peripherals_def.h"

#if CY_SMIF_DEVICE_NUM0
cy_stc_smif_context_t ifx_smif_0_context;

ifx_driver_smif_mem_t ifx_smif_0_memory_config = {
    .smif_base = IFX_SMIF_HW,
    .block_config = &smif0BlockConfig,
    .mem_config = &IFX_SMIF_0_MEMORY_CONFIG,
    .mem_config_dual_quad_pair = NULL,
    .smif_context = &ifx_smif_0_context,
};
#endif /* CY_SMIF_DEVICE_NUM0 */
