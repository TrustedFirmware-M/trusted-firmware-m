/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

//#include "fsl_clock.h"
//#include "fsl_lptmr.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Quantized default IRQ priority, the value is:
 * (Number of configurable priority) / 4: (1UL << __NVIC_PRIO_BITS) / 4
 */
#define DEFAULT_IRQ_PRIORITY    (1UL << (__NVIC_PRIO_BITS - 2))

#define TIMER_BASE             LPTMR_0                     /* Timer 0 */
#define TIMER_CLK_FREQ         (CLOCK_GetFreq(kCLOCK_RtcOscClk))
#define TIMER_IRQ_HANDLER      LPTMR0_IRQHandler
#define TFM_TIMER0_IRQ         LPTMR0_IRQn                /* (tfm_core_irq_signal_data_t->irq_line) */

#define TIMER_NS_BASE          LPTMR_1                     /* Timer 1 */
#define TIMER_NS_CLK_FREQ      (CLOCK_GetFreq(kCLOCK_RtcOscClk))
#define TIMER_NS_IRQ_HANDLER   LPTMR1_IRQHandler
#define TFM_TIMER1_IRQ         LPTMR1_IRQn                /* use by tfm_core_test_irq() */

/* CDOG driver configs for platform*/
//#define CDOG                    CDOG0
#define CDOG_IRQn               CDOG0_IRQn
#define CDOG_DriverIRQHandler   CDOG0_DriverIRQHandler

struct platform_data_t;

extern struct platform_data_t tfm_peripheral_std_uart;
extern struct platform_data_t tfm_peripheral_timer0;

#define TFM_PERIPHERAL_STD_UART     (&tfm_peripheral_std_uart)
#define TFM_PERIPHERAL_TIMER0       (&tfm_peripheral_timer0)

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PERIPHERALS_DEF_H__ */
