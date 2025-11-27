/*
 * Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "config_tfm.h"
#include "cy_tcpwm_counter.h"
#include "tfm_plat_defs.h"
#include "tfm_plat_test.h"
#include "tfm_peripherals_def.h"
#include "plat_test.h"

#include "platform_svc_api.h"

#if !IFX_IRQ_TEST_TIMER_S_SYSTICK
#if defined(IFX_IRQ_TEST_TIMER_S)
/* TCPWM Timer structures for IRQ tests.
 * Add timer in Device Configurator with IFX_IRQ_TEST_TIMER_S name. */
static const ifx_timer_irq_test_dev_t IFX_IRQ_TEST_TIMER_DEV_S = {
    .tcpwm_base         = IFX_IRQ_TEST_TIMER_S_HW,
    .tcpwm_counter_num  = IFX_IRQ_TEST_TIMER_S_NUM,
    .tcpwm_config       = &IFX_IRQ_TEST_TIMER_S_config,
};
#endif  /* IFX_IRQ_TEST_TIMER_S */
#endif  /* IFX_IRQ_TEST_TIMER_S_SYSTICK */

void tfm_plat_test_secure_timer_start(void)
{
#if IFX_IRQ_TEST_TIMER_S_SYSTICK
    ifx_call_platform_enable_systick(1);
#else
    static bool is_initialized = false;
    if (!is_initialized) {
        enum tfm_hal_status_t status =
                ifx_plat_test_timer_init(&IFX_IRQ_TEST_TIMER_DEV_S);
        if (status != TFM_HAL_SUCCESS) {
            return;
        }
        is_initialized = true;
    }

    ifx_plat_test_timer_start(&IFX_IRQ_TEST_TIMER_DEV_S);
#endif
}

void tfm_plat_test_secure_timer_clear_intr(void)
{
#if IFX_IRQ_TEST_TIMER_S_SYSTICK
#else
    ifx_plat_test_secure_timer_clear_intr(&IFX_IRQ_TEST_TIMER_DEV_S);
#endif
}

void tfm_plat_test_secure_timer_stop(void)
{
#if IFX_IRQ_TEST_TIMER_S_SYSTICK
    /* Disable SysTick IRQ and SysTick Timer */
    ifx_call_platform_enable_systick(0);
#else
    ifx_plat_test_secure_timer_stop(&IFX_IRQ_TEST_TIMER_DEV_S);
#endif
}

#ifdef PSA_API_TEST_IPC
void ifx_psa_test_pal_generate_interrupt()
{
    tfm_plat_test_secure_timer_start();
}

void ifx_psa_test_pal_disable_interrupt()
{
    tfm_plat_test_secure_timer_stop();
}
#endif  /* PSA_API_TEST_IPC */
