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


#if defined(IFX_IRQ_TEST_TIMER_NS)
/* Currently tfm_plat_test_non_secure_* functions are not used, but they are kept for possible use
 * in future */
void tfm_plat_test_non_secure_timer_start(void)
{
    static bool is_initialized = false;
    if (!is_initialized) {
        enum tfm_hal_status_t status =
                ifx_plat_test_timer_init(&IFX_IRQ_TEST_TIMER_DEV_NS);
        if (status != TFM_HAL_SUCCESS) {
            return;
        }
        is_initialized = true;
    }

    ifx_plat_test_timer_start(&IFX_IRQ_TEST_TIMER_DEV_NS);
}

uint32_t tfm_plat_test_non_secure_timer_get_reload_value(void)
{
    return Cy_TCPWM_Counter_GetCompare0Val(IFX_IRQ_TEST_TIMER_DEV_NS.tcpwm_base,
                                           IFX_IRQ_TEST_TIMER_DEV_NS.tcpwm_counter_num);
}
#endif  /* IFX_IRQ_TEST_TIMER_NS */
