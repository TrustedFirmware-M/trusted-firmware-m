/*******************************************************************************
 * File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

const cy_stc_scb_uart_config_t DEBUG_UART_config =
{
    .uartMode = CY_SCB_UART_STANDARD,
    .enableMultiProcessorMode = false,
    .smartCardRetryOnNack = false,
    .irdaInvertRx = false,
    .irdaEnableLowPowerReceiver = false,
    .halfDuplexMode = false,
    .oversample = 8,
    .enableMsbFirst = false,
    .dataWidth = 8UL,
    .parity = CY_SCB_UART_PARITY_NONE,
    .stopBits = CY_SCB_UART_STOP_BITS_1,
    .enableInputFilter = false,
    .breakWidth = 11UL,
    .dropOnFrameError = false,
    .dropOnParityError = false,
    .breaklevel = false,
    .receiverAddress = 0x0UL,
    .receiverAddressMask = 0x0UL,
    .acceptAddrInFifo = false,
    .enableCts = false,
    .ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rtsRxFifoLevel = 0UL,
    .rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rxFifoTriggerLevel = 31UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 31UL,
    .txFifoIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t DEBUG_UART_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 2U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t DEBUG_UART_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL3_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_uart_configurator_t DEBUG_UART_hal_config =
{
    .resource = &DEBUG_UART_obj,
    .config = &DEBUG_UART_config,
    .clock = &DEBUG_UART_clock,
#if defined (CY_USING_HAL)
    .gpios = {.pin_tx = P3_3, .pin_rts = NC, .pin_cts = NC},
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t DEBUG_UART_clock_ref =
{
    .clk_dst = (en_clk_dst_t)peri_0_group_3_div_8_0_GRP_NUM,
    .div_type = peri_0_group_3_div_8_0_HW,
    .div_num = peri_0_group_3_div_8_0_NUM,
};
const mtb_hal_clock_t DEBUG_UART_hal_clock =
{
    .clock_ref = &DEBUG_UART_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART)
const mtb_hal_uart_configurator_t DEBUG_UART_hal_config =
{
    .base = DEBUG_UART_HW,
    .clock = &DEBUG_UART_hal_clock,
    .tx_pin = 3,
#if defined (COMPONENT_MW_ASYNC_TRANSFER)
    .rts_pin = 0xFF,
#endif /* defined (COMPONENT_MW_ASYNC_TRANSFER) */
    .tx_port = 3,
#if defined (COMPONENT_MW_ASYNC_TRANSFER)
    .rts_port = 0xFF,
    .rts_enable = 0UL,
#endif /* defined (COMPONENT_MW_ASYNC_TRANSFER) */
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART) */

const cy_stc_ppca_control_config_t PPCA_CNFG_controlConfig =
{
    .pwmSS0 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .pwmSS1 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .pwmSS2 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .pwmSS3 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .HWFILT3P3Z_SS0 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .HWFILT3P3Z_SS1 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .ADCMirror = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .CLB = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .cordic0 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .cordic1 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .adcGroup0 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .adcGroup1 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .adcGroup2 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .adcGroup3 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .dcsgGroup0 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
    .dcsgGroup1 = CY_ALLOCATE_PERIPHERAL_TO_CPU0,
};
const cy_stc_ppca_cnfg_ppcaout_output_selector_t PPCA_CNFG_ppcaOutConfig =
{
    .outputSelSrc = CY_PPCAOUT_TCPWM_OUTPUT,
    .enableOutputSel = false,
};
const cy_stc_ppca_cnfg_config_t PPCA_CNFG_config =
{
    .dpslpRetentionEnable = false,
    .clkShutDown = false,
    .remapEnable = false,
    .cpu0HRESPError = true,
    .cpu1HRESPError = true,
    .cpu0Enable = true,
    .cpu1Enable = true,
    .ctrl_cnfg = &PPCA_CNFG_controlConfig,
    .puty1ResAlloc = 0,
    .puty2ResAlloc = 0,
    .ppcaout_cnfg = &PPCA_CNFG_ppcaOutConfig,
};

void init_cycfg_peripherals(void)
{
    Cy_SysClk_PeriPclkAssignDivider(PCLK_SCB2_CLOCK_SCB_EN, CY_SYSCLK_DIV_8_BIT, 0U);
#if !defined (COMPONENT_PPCA_DEVICE)
    Cy_PPCA_CNFG_Init(PPCA_CNFG_HW, &PPCA_CNFG_config);
#endif /* !defined (COMPONENT_PPCA_DEVICE) */
}
void reserve_cycfg_peripherals(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&DEBUG_UART_obj);
#endif /* defined (CY_USING_HAL) */
}
