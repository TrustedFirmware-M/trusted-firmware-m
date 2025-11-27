/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * \file device_definition.h
 * \brief The structure definitions in this file are exported based on the peripheral
 * definitions from device_cfg.h.
 * This retarget file is meant to be used as a helper for baremetal
 * applications and/or as an example of how to configure the generic
 * driver structures.
 */

#ifndef DEVICE_DEFINITION_H
#define DEVICE_DEFINITION_H

#include "device_cfg.h"
#include <stdint.h>
#include <stdbool.h>

/* ======= Defines peripheral configuration structures ======= */
/* ======= and includes generic driver headers if necessary ======= */

#if defined(IFX_IRQ_TEST_TIMER_S) || defined(IFX_IRQ_TEST_TIMER_NS) || \
    defined(TEST_NS_FPU)
#include "cy_tcpwm_counter.h"
typedef struct ifx_timer_irq_test_dev_config {
    TCPWM_Type *tcpwm_base;
    uint32_t    tcpwm_counter_num;
    const cy_stc_tcpwm_counter_config_t   *tcpwm_config;
} ifx_timer_irq_test_dev_t;
#endif

#ifdef IFX_IRQ_TEST_TIMER_NS
extern const ifx_timer_irq_test_dev_t IFX_IRQ_TEST_TIMER_DEV_NS;
#endif

#endif  /* DEVICE_DEFINITION_H */
