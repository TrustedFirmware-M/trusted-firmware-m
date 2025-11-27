/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "config_tfm.h"
#include "cmsis.h"
#include "device_definition.h"
#include "interrupt.h"
#include "tfm_peripherals_def.h"
#include "load/interrupt_defs.h"
#include "ifx_interrupt_defs.h"

#if defined(IFX_IRQ_TEST_TIMER_S) || defined(PSA_API_TEST_IPC)
static struct irq_t timer0_irq = {0};

#if IFX_IRQ_TEST_TIMER_S_SYSTICK
void SysTick_Handler(void)
#else
void IFX_IRQ_NAME_TO_HANDLER(TFM_TIMER0_IRQ)(void)
#endif
{
    spm_handle_interrupt(timer0_irq.p_pt, timer0_irq.p_ildi);
}

/* TFM regression tests and PSA arch tests are mutually exclusive thus
 * TFM_TIMER0_IRQ can be reused for FF_TEST_UART_IRQ to save up the resources */
#if defined(PSA_API_TEST_IPC)
enum tfm_hal_status_t ff_test_uart_irq_init(void *p_pt,
                                            const struct irq_load_info_t *p_ildi)
#else
enum tfm_hal_status_t tfm_timer0_irq_init(void *p_pt,
                                          const struct irq_load_info_t *p_ildi)
#endif
{
    timer0_irq.p_ildi = p_ildi;
    timer0_irq.p_pt = p_pt;

    NVIC_SetPriority(TFM_TIMER0_IRQ, DEFAULT_IRQ_PRIORITY);
    (void)NVIC_ClearTargetState(TFM_TIMER0_IRQ);
    NVIC_DisableIRQ(TFM_TIMER0_IRQ);

    return TFM_HAL_SUCCESS;
}
#endif /* defined(IFX_IRQ_TEST_TIMER_S) || defined(PSA_API_TEST_IPC) */
