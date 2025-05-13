/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"

__NO_RETURN void tfm_hal_system_reset(void)
{
    struct rse_sysctrl_t *rse_sysctrl = (void *)RSE_SYSCTRL_BASE_S;

    __DSB();
    rse_sysctrl->swreset = 0x1u << 5;
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
