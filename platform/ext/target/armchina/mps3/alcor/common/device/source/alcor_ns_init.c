/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2024 ArmChina. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "tfm_peripherals_def.h"
#include "uart_stdout.h"
#include "Driver_USART.h"
#include "test_interrupt.h"

int32_t tfm_ns_platform_init (void)
{
    /* Register FPU non-secure test interrupt handler */
    NVIC_SetVector(TFM_FPU_NS_TEST_IRQ, (uint32_t)TFM_FPU_NS_TEST_Handler);

    /* Enable FPU non-secure test interrupt */
    NVIC_EnableIRQ(TFM_FPU_NS_TEST_IRQ);

    stdio_init();

    return ARM_DRIVER_OK;
}
