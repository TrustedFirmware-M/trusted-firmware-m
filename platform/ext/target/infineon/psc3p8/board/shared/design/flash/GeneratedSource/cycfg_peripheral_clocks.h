/*******************************************************************************
 * File Name: cycfg_peripheral_clocks.h
 *
 * Description:
 * Peripheral clock divider configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.41.0.11271
 * ifx-tf-m 1.0.0.0
 * mtb-dsl-psc3m8 1.2.0.558
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

#if !defined(CYCFG_PERIPHERAL_CLOCKS_H)
#define CYCFG_PERIPHERAL_CLOCKS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define peri_0_group_2_div_8_0_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define peri_0_group_2_div_8_0_HW CYHAL_CLOCK_BLOCK_PERIPHERAL2_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_2_div_8_0_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_2_div_8_0_NUM 0U
#define PERI_0_GROUP_2_DIV_8_0_GRP_NUM ((2U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_2_div_8_0_GRP_NUM)
#define peri_0_group_2_div_8_0_GRP_NUM PERI_0_GROUP_2_DIV_8_0_GRP_NUM
#endif /* !defined (peri_0_group_2_div_8_0_GRP_NUM) */

#define peri_0_group_2_div_8_0_FREQ 180000000UL
#define peri_0_group_3_div_8_0_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define peri_0_group_3_div_8_0_HW CYHAL_CLOCK_BLOCK_PERIPHERAL3_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_3_div_8_0_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_3_div_8_0_NUM 0U
#define PERI_0_GROUP_3_DIV_8_0_GRP_NUM ((3U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_3_div_8_0_GRP_NUM)
#define peri_0_group_3_div_8_0_GRP_NUM PERI_0_GROUP_3_DIV_8_0_GRP_NUM
#endif /* !defined (peri_0_group_3_div_8_0_GRP_NUM) */

#define peri_0_group_3_div_8_0_FREQ 180000000UL

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t peri_0_group_2_div_8_0_obj;
extern const cyhal_resource_inst_t peri_0_group_3_div_8_0_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_peripheral_clocks(void);
void reserve_cycfg_peripheral_clocks(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PERIPHERAL_CLOCKS_H */
