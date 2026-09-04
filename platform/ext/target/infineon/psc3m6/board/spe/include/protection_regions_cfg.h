/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
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
#include "cycfg_ppc.h"
#include "cycfg_system.h"
#include "partition_psc3.h" /* IMPROVEMENT: BSP-7403, For now file name in PSC3P8 BSP is wrong */
#include "project_memory_layout.h"
#include "protection_data_common.h"
#include "protection_types.h"

/* Number of entries in \ref SAU_config. The last element (NSC region) is
 * excluded because TFM manages NSC configuration by own code. */
#define CY_SAU_REGION_CNT                   ((sizeof(SAU_config)/sizeof(SAU_config[0])) - 1u)

#endif /* PROTECTION_REGIONS_CFG_H */
