/*******************************************************************************
 * File Name: cycfg_clocks.h
 *
 * Description:
 * Clock configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.39.0.10988
 * ifx-tf-m 1.0.0.0
 * mtb-dsl-psc3m6 1.0.0.335
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#if !defined(CYCFG_CLOCKS_H)
#define CYCFG_CLOCKS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"
#include "cy_wdt.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define srss_0_clock_0_ENABLED 1U
#define srss_0_clock_0_iho_0_ENABLED 1U
#define srss_0_clock_0_ilo_0_ENABLED 1U
#define srss_0_clock_0_imo_0_ENABLED 1U
#define srss_0_clock_0_pathmux_0_ENABLED 1U
#define srss_0_clock_0_pathmux_1_ENABLED 1U
#define srss_0_clock_0_pathmux_2_ENABLED 1U
#define srss_0_clock_0_pathmux_3_ENABLED 1U
#define srss_0_clock_0_pathmux_4_ENABLED 1U
#define srss_0_clock_0_pathmux_5_ENABLED 1U
#define srss_0_clock_0_pathmux_6_ENABLED 1U
#define srss_0_clock_0_powerclk_0_ENABLED 1U
#define CY_CFG_SYSCLK_CLKPWR_SOURCE CY_SYSCLK_CLKMF_IN_IMO
#define srss_0_clock_0_dpll250_0_ENABLED 1U
#define srss_0_clock_0_fll_0_ENABLED 1U
#define srss_0_clock_0_lfclk_0_ENABLED 1U
#define CY_CFG_SYSCLK_CLKLF_FREQ_HZ 32768
#define CY_CFG_SYSCLK_CLKLF_SOURCE CY_SYSCLK_CLKLF_IN_ILO
#define srss_0_clock_0_bakclk_0_ENABLED 1U
#define srss_0_clock_0_hfclk_0_ENABLED 1U
#define CY_CFG_SYSCLK_CLKHF0 0UL
#define CY_CFG_SYSCLK_CLKHF0_FREQ 180000000UL
#define CY_CFG_SYSCLK_CLKHF0_CLKPATH_NUM 1UL
#define srss_0_clock_0_hfclk_1_ENABLED 1U
#define CY_CFG_SYSCLK_CLKHF1 1UL
#define CY_CFG_SYSCLK_CLKHF1_FREQ 180000000UL
#define CY_CFG_SYSCLK_CLKHF1_CLKPATH_NUM 1UL
#define srss_0_clock_0_hfclk_2_ENABLED 1U
#define CY_CFG_SYSCLK_CLKHF2 2UL
#define CY_CFG_SYSCLK_CLKHF2_FREQ 100000000UL
#define CY_CFG_SYSCLK_CLKHF2_CLKPATH_NUM 0UL
#define srss_0_clock_0_hfclk_3_ENABLED 1U
#define CY_CFG_SYSCLK_CLKHF3 3UL
#define CY_CFG_SYSCLK_CLKHF3_FREQ 50000000UL
#define CY_CFG_SYSCLK_CLKHF3_CLKPATH_NUM 0UL
#define srss_0_clock_0_hfclk_4_ENABLED 1U
#define CY_CFG_SYSCLK_CLKHF4 4UL
#define CY_CFG_SYSCLK_CLKHF4_FREQ 180000000UL
#define CY_CFG_SYSCLK_CLKHF4_CLKPATH_NUM 1UL
#define srss_0_clock_0_timerclk_0_ENABLED 1U

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t srss_0_clock_0_pathmux_0_obj;
extern const cyhal_resource_inst_t srss_0_clock_0_pathmux_1_obj;
extern const cyhal_resource_inst_t srss_0_clock_0_pathmux_2_obj;
extern const cyhal_resource_inst_t srss_0_clock_0_pathmux_3_obj;
extern const cyhal_resource_inst_t srss_0_clock_0_pathmux_4_obj;
extern const cyhal_resource_inst_t srss_0_clock_0_pathmux_5_obj;
extern const cyhal_resource_inst_t srss_0_clock_0_pathmux_6_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_clocks(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_CLOCKS_H */
