/*******************************************************************************
 * File Name: cycfg_peripherals.h
 *
 * Description:
 * Peripheral Hardware Block configuration
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_scb_uart.h"
#include "cy_sysclk.h"
#include "cy_ppca_cnfg.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#include "cyhal.h"
#endif /* defined (CY_USING_HAL) */

#if defined (COMPONENT_MTB_HAL)
#include "mtb_hal.h"
#include "cycfg_peripheral_clocks.h"
#include "mtb_hal_hw_types.h"
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define DEBUG_UART_ENABLED 1U
#define IFX_TFM_SPM_UART_ENABLED DEBUG_UART_ENABLED
#define DEBUG_UART_HW SCB2
#define IFX_TFM_SPM_UART_HW DEBUG_UART_HW
#define DEBUG_UART_IRQ scb_2_interrupt_IRQn
#define IFX_TFM_SPM_UART_IRQ DEBUG_UART_IRQ
#define PPCA_CNFG_ENABLED 1U
#define PPCA_CNFG_HW PPCA_CNFG
#define PPCA_CNFGCNFG_HW PPCA_CNFG_CNFG
#define PPCA_CNFG_IRQ ppca_cnfg_rdy_for_dslp_IRQn
#define CY_CFG_SYSCLK_PPCA 200000000UL

extern const cy_stc_scb_uart_config_t DEBUG_UART_config;

#define IFX_TFM_SPM_UART_config DEBUG_UART_config

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DEBUG_UART_obj;
#define IFX_TFM_SPM_UART_obj DEBUG_UART_obj
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t DEBUG_UART_clock;
#define IFX_TFM_SPM_UART_clock DEBUG_UART_clock
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_uart_configurator_t DEBUG_UART_hal_config;
#define IFX_TFM_SPM_UART_hal_config DEBUG_UART_hal_config
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t DEBUG_UART_clock_ref;
#define IFX_TFM_SPM_UART_clock_ref DEBUG_UART_clock_ref
extern const mtb_hal_clock_t DEBUG_UART_hal_clock;
#define IFX_TFM_SPM_UART_hal_clock DEBUG_UART_hal_clock
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART)
extern const mtb_hal_uart_configurator_t DEBUG_UART_hal_config;
#define IFX_TFM_SPM_UART_hal_config DEBUG_UART_hal_config
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART) */

extern const cy_stc_ppca_control_config_t PPCA_CNFG_controlConfig;
extern const cy_stc_ppca_cnfg_ppcaout_output_selector_t PPCA_CNFG_ppcaOutConfig;
extern const cy_stc_ppca_cnfg_config_t PPCA_CNFG_config;

void init_cycfg_peripherals(void);
void reserve_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PERIPHERALS_H */
