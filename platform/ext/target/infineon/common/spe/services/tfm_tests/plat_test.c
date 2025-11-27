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
#include "device_definition.h"
#include "tfm_peripherals_def.h"
#include "tfm_plat_defs.h"
#include "tfm_plat_test.h"
#include "plat_test.h"

#if ((defined(IFX_IRQ_TEST_TIMER_S) || defined(PSA_API_TEST_IPC)) && !IFX_IRQ_TEST_TIMER_S_SYSTICK) \
    || defined(IFX_IRQ_TEST_TIMER_NS) || defined(TEST_NS_FPU)
enum tfm_hal_status_t ifx_plat_test_timer_init(const ifx_timer_irq_test_dev_t* dev)
{
    cy_en_tcpwm_status_t status = CY_TCPWM_BAD_PARAM;
    Cy_TCPWM_Counter_Disable(dev->tcpwm_base, dev->tcpwm_counter_num);
    status = Cy_TCPWM_Counter_Init(dev->tcpwm_base, dev->tcpwm_counter_num, dev->tcpwm_config);

    return status == CY_TCPWM_SUCCESS ? TFM_HAL_SUCCESS : TFM_HAL_ERROR_GENERIC;
}

void ifx_plat_test_timer_start(const ifx_timer_irq_test_dev_t* dev)
{
    Cy_TCPWM_Counter_SetCounter(dev->tcpwm_base, dev->tcpwm_counter_num, 0);
    Cy_TCPWM_SetInterruptMask(dev->tcpwm_base, dev->tcpwm_counter_num,
                              dev->tcpwm_config->interruptSources);
    Cy_TCPWM_Counter_Enable(dev->tcpwm_base, dev->tcpwm_counter_num);
    Cy_TCPWM_TriggerStart_Single(dev->tcpwm_base, dev->tcpwm_counter_num);
}

void ifx_plat_test_secure_timer_clear_intr(const ifx_timer_irq_test_dev_t* dev)
{
    Cy_TCPWM_ClearInterrupt(dev->tcpwm_base, dev->tcpwm_counter_num,
                            dev->tcpwm_config->interruptSources);
}

void ifx_plat_test_secure_timer_stop(const ifx_timer_irq_test_dev_t* dev)
{
    Cy_TCPWM_TriggerStopOrKill_Single(dev->tcpwm_base, dev->tcpwm_counter_num);
    Cy_TCPWM_Counter_Disable(dev->tcpwm_base, dev->tcpwm_counter_num);
    Cy_TCPWM_SetInterruptMask(dev->tcpwm_base, dev->tcpwm_counter_num, 0);
    Cy_TCPWM_ClearInterrupt(dev->tcpwm_base, dev->tcpwm_counter_num,
                            dev->tcpwm_config->interruptSources);
}
#endif
