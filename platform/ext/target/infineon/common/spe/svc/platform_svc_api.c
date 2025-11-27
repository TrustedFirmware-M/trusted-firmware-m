/*
 * Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "config_tfm.h"
#include "compiler_ext_defs.h"
#include "utilities.h"
#include "config_impl.h"
#include "platform_svc_api.h"

__naked int32_t ifx_call_platform_uart_log(const char *str, uint32_t len, uint32_t core_id)
{
    __asm volatile("svc     "M2S(IFX_SVC_PLATFORM_UART_LOG)"         \n"
                   "bx      lr                                       \n");
}

__naked int32_t ifx_call_platform_enable_systick(uint32_t enable)
{
#if TFM_ISOLATION_LEVEL == 1
    /* On Isolation Level 1 all partitions are privileged, so it's OK to access SysTick directly */
    __asm volatile("b       ifx_svc_platform_enable_systick          \n");
#else
    __asm volatile("svc     "M2S(IFX_SVC_PLATFORM_ENABLE_SYSTICK)"   \n"
                   "bx      lr                                       \n");
#endif /* TFM_ISOLATION_LEVEL == 1 */
}

__naked void ifx_call_platform_system_reset(void)
{
    __asm volatile("svc     "M2S(IFX_SVC_PLATFORM_SYSTEM_RESET)"     \n"
                   "bx      lr                                       \n");
}
