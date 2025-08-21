/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"

uint32_t tfm_hal_get_reset_syndrome(void)
{
    return ((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->reset_syndrome;
}

void tfm_hal_clear_reset_syndrome_bit(uint8_t bit_pos)
{
    ((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->reset_syndrome &= ~(1 << bit_pos);
}

__NO_RETURN void tfm_hal_system_reset(uint32_t sw_reset_syn_value)
{
    struct rse_sysctrl_t *rse_sysctrl = (struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S;

    __DSB();
    rse_sysctrl->swreset = SYSCTRL_SWRESET_SWRESETREQ_MASK |
                               (sw_reset_syn_value & SYSCTRL_SWRESET_SWSYN_MASK);
    __DSB();

    while(1) {
        __NOP();
    }
}

__NO_RETURN void tfm_hal_system_halt(void)
{
    /*
     * Disable IRQs to stop all threads, not just the thread that
     * halted the system.
     */
    __disable_irq();

    /*
     * Enter sleep to reduce power consumption and do it in a loop in
     * case a signal wakes up the CPU.
     */
    while (1) {
        __WFE();
    }
}
