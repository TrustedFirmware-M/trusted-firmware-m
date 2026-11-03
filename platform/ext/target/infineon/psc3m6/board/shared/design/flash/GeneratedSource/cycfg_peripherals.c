/*******************************************************************************
 * File Name: cycfg_peripherals.c
 *
 * Description:
 * Analog configuration
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

#include "cycfg_peripherals.h"

#define TCPWM_COUNTER_INPUT_DISABLED 0x7U

const cy_stc_scb_uart_config_t CYBSP_DEBUG_UART_config =
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
    .rxFifoTriggerLevel = 63UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 63UL,
    .txFifoIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_DEBUG_UART_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 3U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t CYBSP_DEBUG_UART_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL4_16_5BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_uart_configurator_t CYBSP_DEBUG_UART_hal_config =
{
    .resource = &CYBSP_DEBUG_UART_obj,
    .config = &CYBSP_DEBUG_UART_config,
    .clock = &CYBSP_DEBUG_UART_clock,
#if defined (CY_USING_HAL)
    .gpios = {.pin_tx = P6_3, .pin_rts = NC, .pin_cts = NC},
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t CYBSP_DEBUG_UART_clock_ref =
{
    .clk_dst = (en_clk_dst_t)peri_0_group_4_div_16_5_0_GRP_NUM,
    .div_type = peri_0_group_4_div_16_5_0_HW,
    .div_num = peri_0_group_4_div_16_5_0_NUM,
};
const mtb_hal_clock_t CYBSP_DEBUG_UART_hal_clock =
{
    .clock_ref = &CYBSP_DEBUG_UART_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART)
const mtb_hal_uart_configurator_t CYBSP_DEBUG_UART_hal_config =
{
    .base = CYBSP_DEBUG_UART_HW,
    .clock = &CYBSP_DEBUG_UART_hal_clock,
    .tx_pin = 3,
#if defined (COMPONENT_MW_ASYNC_TRANSFER)
    .rts_pin = 0xFF,
#endif /* defined (COMPONENT_MW_ASYNC_TRANSFER) */
    .tx_port = 6,
#if defined (COMPONENT_MW_ASYNC_TRANSFER)
    .rts_port = 0xFF,
    .rts_enable = 0UL,
#endif /* defined (COMPONENT_MW_ASYNC_TRANSFER) */
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART) */

const cy_stc_tcpwm_counter_config_t TCPWM_COUNTER_config =
{
    .period = 9999,
    .clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
    .runMode = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection = CY_TCPWM_COUNTER_COUNT_UP,
    .compareOrCapture = CY_TCPWM_COUNTER_MODE_CAPTURE,
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC ) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .captureInputMode = TCPWM_COUNTER_INPUT_DISABLED & 0x3U,
    .captureInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = TCPWM_COUNTER_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = TCPWM_COUNTER_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .stopInputMode = TCPWM_COUNTER_INPUT_DISABLED & 0x3U,
    .stopInput = CY_TCPWM_INPUT_0,
    .countInputMode = TCPWM_COUNTER_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .capture1InputMode = TCPWM_COUNTER_INPUT_DISABLED & 0x3U,
    .capture1Input = CY_TCPWM_INPUT_0,
    .compare2 = 16384,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
#if defined (CY_IP_MXS40TCPWM)
    .buffer_swap_enable = false,
    .direction_mode = CY_TCPWM_COUNTER_DIRECTION_DISABLE,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t TCPWM_COUNTER_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t TCPWM_COUNTER_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL0_16BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_timer_configurator_t TCPWM_COUNTER_hal_config =
{
    .resource = &TCPWM_COUNTER_obj,
    .config = &TCPWM_COUNTER_config,
    .clock = &TCPWM_COUNTER_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t TCPWM_COUNTER_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN256,
    .div_type = CY_SYSCLK_DIV_16_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t TCPWM_COUNTER_hal_clock =
{
    .clock_ref = &TCPWM_COUNTER_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
const mtb_hal_timer_configurator_t TCPWM_COUNTER_hal_config =
{
    .tcpwm_base = TCPWM_COUNTER_HW,
    .clock = &TCPWM_COUNTER_hal_clock,
    .tcpwm_cntnum = 256U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

void init_cycfg_peripherals(void)
{
    Cy_SysClk_PeriPclkAssignDivider(PCLK_SCB3_CLOCK_SCB_EN, CY_SYSCLK_DIV_16_5_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriPclkAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN256, CY_SYSCLK_DIV_16_BIT, 0U);
}
void reserve_cycfg_peripherals(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&CYBSP_DEBUG_UART_obj);
    cyhal_hwmgr_reserve(&TCPWM_COUNTER_obj);
#endif /* defined (CY_USING_HAL) */
}
