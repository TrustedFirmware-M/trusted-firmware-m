/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 * definitions from device_cfg.h.
 * This retarget file is meant to be used as a helper for baremetal
 * applications and/or as an example of how to configure the generic
 * driver structures.
 */

#include "device_definition.h"
#include "tfm_peripherals_def.h"
#include "tfm_plat_defs.h"

#if defined(IFX_IRQ_TEST_TIMER_NS)
/* TCPWM Timer structures for IRQ tests.
 * Add timer in Device Configurator with IFX_IRQ_TEST_TIMER_NS name. */
const ifx_timer_irq_test_dev_t IFX_IRQ_TEST_TIMER_DEV_NS = {
    .tcpwm_base         = IFX_IRQ_TEST_TIMER_NS_HW,
    .tcpwm_counter_num  = IFX_IRQ_TEST_TIMER_NS_NUM,
    .tcpwm_config       = &IFX_IRQ_TEST_TIMER_NS_config,
};
#endif  /* IFX_IRQ_TEST_TIMER_NS */
