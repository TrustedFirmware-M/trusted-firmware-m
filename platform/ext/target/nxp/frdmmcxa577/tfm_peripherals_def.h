/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

#include "fsl_clock.h"
#include "fsl_ctimer.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Quantized default IRQ priority, the value is:
 * (Number of configurable priority) / 4: (1UL << __NVIC_PRIO_BITS) / 4
 */
#define DEFAULT_IRQ_PRIORITY    (1UL << (__NVIC_PRIO_BITS - 2))

#define CTIMER                  (CTIMER1)                       /* Timer 1 */
#define CTIMER_CLK_FREQ         (CLOCK_GetCTimerClkFreq(1U))
#define CTIMER_CLK_ATTACH       (kFRO_HF_to_CTIMER1)       /* Use 16 MHz clock */
#define CTIMER_CLK_DIVIDE       (kCLOCK_DivCTIMER1)
#define CTIMER_IRQ_HANDLER      (CTIMER1_IRQHandler)
#define TFM_TIMER0_IRQ          (CTIMER1_IRQn)                  /* (tfm_core_irq_signal_data_t->irq_line) */

#define CTIMER_NS               (CTIMER2)                       /* Timer 2 */
#define CTIMER_NS_CLK_FREQ      (CLOCK_GetCTimerClkFreq(2U))
#define CTIMER_NS_CLK_ATTACH    (kFRO_HF_to_CTIMER2)       /* Use 16 MHz clock */
#define CTIMER_NS_CLK_DIVIDE    (kCLOCK_DivCTIMER2)
#define CTIMER_NS_IRQ_HANDLER   (CTIMER2_IRQHandler)
#define TFM_TIMER1_IRQ          (CTIMER2_IRQn)                  /* use by tfm_core_test_irq() */

/* CDOG driver configs for platform*/
#define CDOG                    CDOG0
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
