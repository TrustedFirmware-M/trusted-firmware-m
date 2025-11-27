/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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
#include "protection_types.h"

/* Defines whether XIP0 enabled */
#define IFX_SMIF_XIP0_ENABLED               (CY_SMIF_DEVICE_NUM0 != 0U)

/* Defines whether XIP1 enabled */
#define IFX_SMIF_XIP1_ENABLED               (CY_SMIF_DEVICE_NUM1 != 0U)

/* Defines whether SOCMEM enabled */
#define IFX_SOCMEM_ENABLED                  (socmem_0_mpc_0_REGION_COUNT != 0U)

typedef struct {
    en_ms_ctl_master_sc_acg_t      bus_master;
    cy_en_ms_ctl_cfg_gate_resp_t   gate_resp;
    cy_en_ms_ctl_sec_resp_t        sec_resp;
} ifx_msc_agc_resp_config_t;

typedef struct {
    en_ms_ctl_master_sc_acg_v1_t   bus_master;
    cy_en_ms_ctl_cfg_gate_resp_t   gate_resp;
    cy_en_ms_ctl_sec_resp_t        sec_resp;
} ifx_msc_agc_resp_config_v1_t;

typedef cy_stc_sau_config_t ifx_sau_config_t;


/* Number of entries in \ref SAU_config. The last element (NSC region) is
 * excluded because TFM manages NSC configuration by own code. */
#define CY_SAU_REGION_CNT                   ((sizeof(SAU_config)/sizeof(SAU_config[0])) - 1u)

extern PPC_Type* const                      ifx_ppcx_region_ptrs[];
extern const size_t                         ifx_ppcx_region_ptrs_count;
extern const ifx_ppcx_config_t              ifx_ppcx_static_config[];
extern const size_t                         ifx_ppcx_static_config_count;
extern const ifx_msc_agc_resp_config_t      ifx_msc_agc_resp_config[];
extern const size_t                         ifx_msc_agc_resp_config_count;
extern const ifx_msc_agc_resp_config_v1_t   ifx_msc_agc_resp_config_v1[];
extern const size_t                         ifx_msc_agc_resp_config_v1_count;
extern const IRQn_Type                      ifx_secure_interrupts_config[];
extern const size_t                         ifx_secure_interrupts_config_count;
extern const cy_en_SysFault_source_t        ifx_fault_sources_fault_struct0[];
extern const size_t                         ifx_fault_sources_fault_struct0_count;

#endif /* PROTECTION_REGIONS_CFG_H */
