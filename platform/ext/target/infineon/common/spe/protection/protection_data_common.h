/*
 * Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_DATA_COMMON_H
#define PROTECTION_DATA_COMMON_H

#include <stddef.h>

#include "cy_device.h"
#include "cy_sysfault.h"
#include "protection_types.h"

extern const IRQn_Type ifx_secure_interrupts_config[];
extern const size_t ifx_secure_interrupts_config_count;

#if IFX_MPC_DRIVER_HW_MPC
extern const ifx_memory_config_t* const ifx_memory_cm33_config[];
extern const size_t ifx_memory_cm33_config_count;

#if IFX_MPC_CM55_MPC
extern const ifx_memory_config_t* const ifx_memory_cm55_config[];
extern const size_t ifx_memory_cm55_config_count;
#endif /* IFX_MPC_CM55_MPC */
#endif /* IFX_MPC_DRIVER_HW_MPC */

#if IFX_PLATFORM_PPC_PRESENT
extern PPC_Type* const ifx_ppcx_region_ptrs[];
extern const size_t ifx_ppcx_region_ptrs_count;
extern const ifx_ppcx_config_t ifx_ppcx_static_config[];
extern const size_t ifx_ppcx_static_config_count;
#endif /* IFX_PLATFORM_PPC_PRESENT */

extern const cy_en_SysFault_source_t ifx_tfm_fault_sources[];
extern const size_t ifx_tfm_fault_sources_count;

#if IFX_MSC_ACG_RESP_CONFIG
extern const ifx_msc_agc_resp_config_t ifx_msc_agc_resp_config[];
extern const size_t ifx_msc_agc_resp_config_count;
#endif /* IFX_MSC_ACG_RESP_CONFIG */

#if IFX_MSC_ACG_RESP_CONFIG_V1
extern const ifx_msc_agc_resp_config_v1_t ifx_msc_agc_resp_config_v1[];
extern const size_t ifx_msc_agc_resp_config_v1_count;
#endif /* IFX_MSC_ACG_RESP_CONFIG_V1 */

#endif /* PROTECTION_DATA_COMMON_H */
