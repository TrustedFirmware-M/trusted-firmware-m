/*
 * Copyright (c) 2018-2021, Arm Limited. All rights reserved.
 * Copyright 2019-2020, 2022, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

#include "fsl_clock.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Quantized default IRQ priority, the value is:
 * (Number of configurable priority) / 4: (1UL << __NVIC_PRIO_BITS) / 4
 */
#define DEFAULT_IRQ_PRIORITY    (1UL << (__NVIC_PRIO_BITS - 2))

/* Get source clock for LPTMR driver */
#define LPTMR_SOURCE_CLOCK 32000U
/* Define LPTMR microseconds counts value */
#define LPTMR_USEC_COUNT 1000000U

#define TIMER_BASE             LPTMR1                     /* Timer 0 */
//#define TIMER_CLK_FREQ         USEC_TO_COUNT(LPTMR_USEC_COUNT, LPTMR_SOURCE_CLOCK)
#define TIMER_CLK_FREQ         USEC_TO_COUNT(1000000u, LPTMR_SOURCE_CLOCK)
#define TIMER_IRQ_HANDLER      LPTMR1_IRQHandler
#define TFM_TIMER0_IRQ         LPTMR1_IRQn                /* (tfm_core_irq_signal_data_t->irq_line) */

#define TIMER_NS_BASE          LPTMR2                     /* Timer 1 */
//#define TIMER_NS_CLK_FREQ      USEC_TO_COUNT(LPTMR_USEC_COUNT, LPTMR_SOURCE_CLOCK)
#define TIMER_NS_CLK_FREQ      USEC_TO_COUNT(1000000u, LPTMR_SOURCE_CLOCK)
#define TIMER_NS_IRQ_HANDLER   LPTMR2_IRQHandler
#define TFM_TIMER1_IRQ         LPTMR2_IRQn                /* use by tfm_core_test_irq() */

struct platform_data_t;

extern struct platform_data_t tfm_peripheral_std_uart;
extern struct platform_data_t tfm_peripheral_timer0;

#define TFM_PERIPHERAL_STD_UART     (&tfm_peripheral_std_uart)
#define TFM_PERIPHERAL_TIMER0       (&tfm_peripheral_timer0)

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PERIPHERALS_DEF_H__ */
