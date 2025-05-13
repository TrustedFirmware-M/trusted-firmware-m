/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "tfm_hal_platform.h"

__NO_RETURN void tfm_hal_system_reset(void)
{
    NVIC_SystemReset();
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
