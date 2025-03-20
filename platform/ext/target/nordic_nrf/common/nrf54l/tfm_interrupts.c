/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "cmsis.h"
#include "spm.h"
#include "tfm_hal_interrupt.h"
#include "tfm_peripherals_def.h"
#include "tfm_peripherals_config.h"
#include "load/interrupt_defs.h"
#include "interrupt.h"

static enum tfm_hal_status_t irq_init(struct irq_t *irq, IRQn_Type irqn,
                                      void * p_pt,
                                      const struct irq_load_info_t *p_ildi)
{
    irq->p_ildi = p_ildi;
    irq->p_pt = p_pt;

    NVIC_SetPriority(irqn, DEFAULT_IRQ_PRIORITY);
    NVIC_ClearTargetState(irqn);
    NVIC_DisableIRQ(irqn);

    return TFM_HAL_SUCCESS;
}

#if TFM_PERIPHERAL_FPU_SECURE
static struct irq_t fpu_irq = {0};

void FPU_IRQHandler(void)
{
    spm_handle_interrupt(fpu_irq.p_pt, fpu_irq.p_ildi);
}

enum tfm_hal_status_t tfm_fpu_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&fpu_irq, TFM_FPU_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_TIMER00_SECURE
static struct irq_t timer00_irq = {0};

void TIMER00_IRQHandler(void)
{
    spm_handle_interrupt(timer00_irq.p_pt, timer00_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer00_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&timer00_irq, TFM_TIMER00_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_TIMER10_SECURE
static struct irq_t timer10_irq = {0};

void TIMER10_IRQHandler(void)
{
    spm_handle_interrupt(timer10_irq.p_pt, timer10_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer10_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&timer10_irq, TFM_TIMER10_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_TIMER20_SECURE
static struct irq_t timer20_irq = {0};

void TIMER20_IRQHandler(void)
{
    spm_handle_interrupt(timer20_irq.p_pt, timer20_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer20_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&timer20_irq, TFM_TIMER20_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_TIMER21_SECURE
static struct irq_t timer21_irq = {0};

void TIMER21_IRQHandler(void)
{
    spm_handle_interrupt(timer21_irq.p_pt, timer21_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer21_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&timer21_irq, TFM_TIMER21_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_TIMER22_SECURE
static struct irq_t timer22_irq = {0};

void TIMER22_IRQHandler(void)
{
    spm_handle_interrupt(timer22_irq.p_pt, timer22_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer22_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&timer22_irq, TFM_TIMER22_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_TIMER23_SECURE
static struct irq_t timer23_irq = {0};

void TIMER23_IRQHandler(void)
{
    spm_handle_interrupt(timer23_irq.p_pt, timer23_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer23_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&timer23_irq, TFM_TIMER23_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_TIMER24_SECURE
static struct irq_t timer24_irq = {0};

void TIMER24_IRQHandler(void)
{
    spm_handle_interrupt(timer24_irq.p_pt, timer24_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer24_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&timer24_irq, TFM_TIMER24_IRQ, p_pt, p_ildi);
}
#endif

/* By NRFX convention GPIOTE interrupt 1 targets secure, while 0 targets non-secure. */
static struct irq_t gpiote20_1_irq = {0};

void GPIOTE20_1_IRQHandler(void)
{
    spm_handle_interrupt(gpiote20_1_irq.p_pt, gpiote20_1_irq.p_ildi);
}

enum tfm_hal_status_t tfm_gpiote20_1_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&gpiote20_1_irq, TFM_GPIOTE20_1_IRQ, p_pt, p_ildi);
}

/* By NRFX convention GPIOTE interrupt 1 targets secure, while 0 targets non-secure. */
static struct irq_t gpiote30_1_irq = {0};

void GPIOTE30_1_IRQHandler(void)
{
    spm_handle_interrupt(gpiote30_1_irq.p_pt, gpiote30_1_irq.p_ildi);
}

enum tfm_hal_status_t tfm_gpiote30_1_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&gpiote30_1_irq, TFM_GPIOTE30_1_IRQ, p_pt, p_ildi);
}

#if TFM_PERIPHERAL_SPIM00_SECURE
static struct irq_t spim00_irq = {0};

void SPIM00_IRQHandler(void)
{
    spm_handle_interrupt(spim00_irq.p_pt, spim00_irq.p_ildi);
}

enum tfm_hal_status_t tfm_spim00_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&spim00_irq, TFM_SPIM00_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_SPIM22_SECURE
static struct irq_t spim22_irq = {0};

void SPIM22_IRQHandler(void)
{
    spm_handle_interrupt(spim22_irq.p_pt, spim22_irq.p_ildi);
}

enum tfm_hal_status_t tfm_spim22_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&spim22_irq, TFM_SPIM22_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_SPIM23_SECURE
static struct irq_t spim23_irq = {0};

void SPIM23_IRQHandler(void)
{
    spm_handle_interrupt(spim23_irq.p_pt, spim23_irq.p_ildi);
}

enum tfm_hal_status_t tfm_spim23_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&spim23_irq, TFM_SPIM23_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_SPIM30_SECURE
static struct irq_t spim30_irq = {0};

void SPIM30_IRQHandler(void)
{
    spm_handle_interrupt(spim30_irq.p_pt, spim30_irq.p_ildi);
}

enum tfm_hal_status_t tfm_spim30_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&spim30_irq, TFM_SPIM30_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_EGU10_SECURE
static struct irq_t egu10_irq = {0};

void EGU10_IRQHandler(void)
{
    spm_handle_interrupt(egu10_irq.p_pt, egu10_irq.p_ildi);
}

enum tfm_hal_status_t tfm_egu10_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&egu10_irq, TFM_EGU10_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_EGU20_SECURE
static struct irq_t egu20_irq = {0};

void EGU20_IRQHandler(void)
{
    spm_handle_interrupt(egu20_irq.p_pt, egu20_irq.p_ildi);
}

enum tfm_hal_status_t tfm_egu20_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&egu20_irq, TFM_EGU20_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_PWM20_SECURE
static struct irq_t pwm20_irq = {0};

void PWM20_IRQHandler(void)
{
    spm_handle_interrupt(pwm20_irq.p_pt, pwm20_irq.p_ildi);
}

enum tfm_hal_status_t tfm_pwm20_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&pwm20_irq, TFM_PWM20_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_PWM21_SECURE
static struct irq_t pwm21_irq = {0};

void PWM21_IRQHandler(void)
{
    spm_handle_interrupt(pwm21_irq.p_pt, pwm21_irq.p_ildi);
}

enum tfm_hal_status_t tfm_pwm21_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&pwm21_irq, TFM_PWM21_IRQ, p_pt, p_ildi);
}
#endif

#if TFM_PERIPHERAL_PWM22_SECURE
static struct irq_t pwm22_irq = {0};

void PWM22_IRQHandler(void)
{
    spm_handle_interrupt(pwm22_irq.p_pt, pwm22_irq.p_ildi);
}

enum tfm_hal_status_t tfm_pwm22_irq_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    return irq_init(&pwm22_irq, TFM_PWM22_IRQ, p_pt, p_ildi);
}
#endif

#ifdef PSA_API_TEST_IPC
enum tfm_hal_status_t ff_test_uart_irq_init(void *p_pt,
                                            const struct irq_load_info_t *p_ildi)
__attribute__((alias("tfm_egu10_irq_init")));

#endif
