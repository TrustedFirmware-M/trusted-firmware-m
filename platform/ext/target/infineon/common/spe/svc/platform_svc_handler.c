/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "cmsis.h"
#include "cy_device_headers.h"
#include "ifx_fih.h"
#include "platform_svc_api.h"
#include "spm.h"
#include "target_cfg.h"
#include "tfm_hal_isolation.h"
#include "tfm_peripherals_def.h"
#if IFX_UART_ENABLED
#include "uart_pdl_stdout.h"
#endif

static int32_t ifx_svc_platform_uart_log_handler(const char *msg, uint32_t len, uint32_t core_id)
{
#if IFX_UART_ENABLED
    IFX_FIH_DECLARE(enum tfm_hal_status_t, fih_rc, TFM_HAL_ERROR_GENERIC);
    struct partition_t *curr_partition = GET_CURRENT_COMPONENT();

    FIH_CALL(tfm_hal_memory_check, fih_rc,
             curr_partition->boundary, (uintptr_t)msg,
             (size_t)len, (uint32_t)TFM_HAL_ACCESS_READABLE);
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    (void)stdio_output_string_raw(msg, len, (ifx_stdio_core_id_t)core_id);

    return (int32_t)PSA_SUCCESS;
#else
    return (int32_t)PSA_ERROR_NOT_SUPPORTED;
#endif
}

static int32_t ifx_svc_platform_enable_systick(uint32_t enable)
{
    if (enable != 0u) {
        /* Enable SysTick every 100 cycles of clock to not overload the system
         * with interrupts */
        (void)SysTick_Config(SystemCoreClock / 100u);
        /* SysTick_Config set the lowest IRQ priority (equal to PendSV) - which
         * generate tfm_core_panic(). So, we should fix this. */
        NVIC_SetPriority(TFM_TIMER0_IRQ, DEFAULT_IRQ_PRIORITY);
    }
    else {
        /* Disable SysTick IRQ and SysTick Timer */
        SysTick->CTRL  &= ~(SysTick_CTRL_TICKINT_Msk |
                         SysTick_CTRL_ENABLE_Msk);
    }

    return (int32_t)PSA_SUCCESS;
}

static int32_t ifx_svc_platform_system_reset(void)
{
    NVIC_SystemReset();

    /* Suppress Pe111 (statement is unreachable) for IAR as return here is in
     * case system reset fails, which should not happen */
#if defined(__ICCARM__)
#pragma diag_suppress = Pe111
#endif
    /* Execution should not reach here */
    return (int32_t)TFM_PLAT_ERR_SYSTEM_ERR;
#if defined(__ICCARM__)
#pragma diag_default = Pe111
#endif
}

int32_t platform_svc_handlers(uint8_t svc_num, uint32_t *svc_args,
                                uint32_t lr)
{
    (void) lr;

    int32_t retval;

    switch (svc_num) {
        case IFX_SVC_PLATFORM_UART_LOG:
            retval = ifx_svc_platform_uart_log_handler(
                    (const char *)svc_args[0], svc_args[1], svc_args[2]);
            break;

        case IFX_SVC_PLATFORM_ENABLE_SYSTICK:
            retval = ifx_svc_platform_enable_systick(svc_args[0]);
            break;

        case IFX_SVC_PLATFORM_SYSTEM_RESET:
            retval = ifx_svc_platform_system_reset();
            break;

        default:
            retval = PSA_ERROR_GENERIC_ERROR;
            break;
    }

    return retval;
}
