/*
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_interrupt_defs.h"
#include "tfm_peripherals_def.h"
#include "test_interrupt.h"

#if defined(__ICCARM__)
#pragma required = TFM_FPU_NS_TEST_Handler
#endif
__attribute__((naked)) void IFX_IRQ_NAME_TO_HANDLER(TFM_FPU_NS_TEST_IRQ)(void)
{
    __asm volatile("b.w     TFM_FPU_NS_TEST_Handler \n");
}

void tfm_test_ns_fpu_init(void)
{
    /* Enable FPU not secure test interrupt */
    NVIC_EnableIRQ(TFM_FPU_NS_TEST_IRQ);
}
