/*
 * Copyright (c) 2023-2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_REGIONS_CFG_H
#define PROTECTION_REGIONS_CFG_H

#include "cy_mpc.h"
#include "cy_ms_ctl.h"
#include "cy_ppc.h"
#include "cy_sysfault.h"
#include "cycfg_protection.h"
#include "cycfg_qspi_memslot.h"
#include "cycfg_ppc.h"
#include "cycfg_system.h"
#include "partition_edge.h"
#include "project_memory_layout.h"
#include "protection_data_common.h"
#include "protection_types.h"

/* Defines whether XIP0 enabled */
#define IFX_SMIF_XIP0_ENABLED               (CY_SMIF_DEVICE_NUM0 != 0U)

/* Defines whether XIP1 enabled */
#define IFX_SMIF_XIP1_ENABLED               (CY_SMIF_DEVICE_NUM1 != 0U)

/* Defines whether SOCMEM enabled */
#define IFX_SOCMEM_ENABLED                  (socmem_0_mpc_0_REGION_COUNT != 0U)

/* Number of entries in \ref SAU_config. The last element (NSC region) is
 * excluded because TFM manages NSC configuration by own code. */
#define CY_SAU_REGION_CNT                   ((sizeof(SAU_config)/sizeof(SAU_config[0])) - 1u)

#endif /* PROTECTION_REGIONS_CFG_H */
