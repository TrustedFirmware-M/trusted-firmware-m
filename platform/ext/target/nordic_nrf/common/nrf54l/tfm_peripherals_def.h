/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 *
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <nrfx.h>

#define TFM_FPU_IRQ (NRFX_IRQ_NUMBER_GET(NRF_FPU))
#define TFM_TIMER00_IRQ (NRFX_IRQ_NUMBER_GET(NRF_TIMER00))
#define TFM_TIMER10_IRQ (NRFX_IRQ_NUMBER_GET(NRF_TIMER10))
#define TFM_TIMER20_IRQ (NRFX_IRQ_NUMBER_GET(NRF_TIMER20))
#define TFM_TIMER21_IRQ (NRFX_IRQ_NUMBER_GET(NRF_TIMER21))
#define TFM_TIMER22_IRQ (NRFX_IRQ_NUMBER_GET(NRF_TIMER22))
#define TFM_TIMER23_IRQ (NRFX_IRQ_NUMBER_GET(NRF_TIMER23))
#define TFM_TIMER24_IRQ (NRFX_IRQ_NUMBER_GET(NRF_TIMER24))
#define TFM_SPIM00_IRQ (NRFX_IRQ_NUMBER_GET(NRF_SPIM00))
#define TFM_SPIM20_IRQ (NRFX_IRQ_NUMBER_GET(NRF_SPIM20))
#define TFM_SPIM21_IRQ (NRFX_IRQ_NUMBER_GET(NRF_SPIM21))
#define TFM_SPIM22_IRQ (NRFX_IRQ_NUMBER_GET(NRF_SPIM22))
#define TFM_SPIM23_IRQ (NRFX_IRQ_NUMBER_GET(NRF_SPIM23))
#define TFM_SPIM30_IRQ (NRFX_IRQ_NUMBER_GET(NRF_SPIM30))
#define TFM_EGU10_IRQ (NRFX_IRQ_NUMBER_GET(NRF_EGU10))
#define TFM_EGU20_IRQ (NRFX_IRQ_NUMBER_GET(NRF_EGU20))
#define TFM_GPIOTE20_1_IRQ GPIOTE20_1_IRQn
#define TFM_GPIOTE30_1_IRQ GPIOTE30_1_IRQn
#define TFM_PWM20_IRQ (NRFX_IRQ_NUMBER_GET(NRF_PWM20))
#define TFM_PWM21_IRQ (NRFX_IRQ_NUMBER_GET(NRF_PWM21))
#define TFM_PWM22_IRQ (NRFX_IRQ_NUMBER_GET(NRF_PWM22))

extern struct platform_data_t tfm_peripheral_timer00;
extern struct platform_data_t tfm_peripheral_timer10;
extern struct platform_data_t tfm_peripheral_timer20;
extern struct platform_data_t tfm_peripheral_timer21;
extern struct platform_data_t tfm_peripheral_timer22;
extern struct platform_data_t tfm_peripheral_timer23;
extern struct platform_data_t tfm_peripheral_timer24;
extern struct platform_data_t tfm_peripheral_spim00;
extern struct platform_data_t tfm_peripheral_spim20;
extern struct platform_data_t tfm_peripheral_spim21;
extern struct platform_data_t tfm_peripheral_spim22;
extern struct platform_data_t tfm_peripheral_spim23;
extern struct platform_data_t tfm_peripheral_spim30;
extern struct platform_data_t tfm_peripheral_egu10;
extern struct platform_data_t tfm_peripheral_egu20;
extern struct platform_data_t tfm_peripheral_gpiote20;
extern struct platform_data_t tfm_peripheral_gpiote30;
extern struct platform_data_t tfm_peripheral_pwm20;
extern struct platform_data_t tfm_peripheral_pwm21;
extern struct platform_data_t tfm_peripheral_pwm22;

#define TFM_PERIPHERAL_TIMER00 (&tfm_peripheral_timer00)
#define TFM_PERIPHERAL_TIMER10 (&tfm_peripheral_timer10)
#define TFM_PERIPHERAL_TIMER20 (&tfm_peripheral_timer20)
#define TFM_PERIPHERAL_TIMER21 (&tfm_peripheral_timer21)
#define TFM_PERIPHERAL_TIMER22 (&tfm_peripheral_timer22)
#define TFM_PERIPHERAL_TIMER23 (&tfm_peripheral_timer23)
#define TFM_PERIPHERAL_TIMER24 (&tfm_peripheral_timer24)
#define TFM_PERIPHERAL_SPIM00 (&tfm_peripheral_spim00)
#define TFM_PERIPHERAL_SPIM20 (&tfm_peripheral_spim20)
#define TFM_PERIPHERAL_SPIM21 (&tfm_peripheral_spim21)
#define TFM_PERIPHERAL_SPIM22 (&tfm_peripheral_spim22)
#define TFM_PERIPHERAL_SPIM23 (&tfm_peripheral_spim23)
#define TFM_PERIPHERAL_SPIM30 (&tfm_peripheral_spim30)
#define TFM_PERIPHERAL_EGU10 (&tfm_peripheral_egu10)
#define TFM_PERIPHERAL_EGU20 (&tfm_peripheral_egu20)
#define TFM_PERIPHERAL_GPIOTE20 (&tfm_peripheral_gpiote20)
#define TFM_PERIPHERAL_GPIOTE30 (&tfm_peripheral_gpiote30)
#define TFM_PERIPHERAL_PWM20 (&tfm_peripheral_pwm20)
#define TFM_PERIPHERAL_PWM21 (&tfm_peripheral_pwm21)
#define TFM_PERIPHERAL_PWM22 (&tfm_peripheral_pwm22)

/*
 * Quantized default IRQ priority, the value is:
 * (Number of configurable priority) / 4: (1UL << __NVIC_PRIO_BITS) / 4
 */
#define DEFAULT_IRQ_PRIORITY (1UL << (__NVIC_PRIO_BITS - 2))

extern struct platform_data_t tfm_peripheral_uarte00;
extern struct platform_data_t tfm_peripheral_uarte20;
extern struct platform_data_t tfm_peripheral_uarte21;
extern struct platform_data_t tfm_peripheral_uarte22;
extern struct platform_data_t tfm_peripheral_uarte30;

#define TFM_PERIPHERAL_UARTE00       (&tfm_peripheral_uarte00)
#define TFM_PERIPHERAL_UARTE20       (&tfm_peripheral_uarte20)
#define TFM_PERIPHERAL_UARTE21       (&tfm_peripheral_uarte21)
#define TFM_PERIPHERAL_UARTE22       (&tfm_peripheral_uarte22)
#define TFM_PERIPHERAL_UARTE30       (&tfm_peripheral_uarte30)

#define TFM_PERIPHERAL_STD_UART     TFM_PERIPHERAL_UARTE30

extern struct platform_data_t tfm_peripheral_uarte00;
extern struct platform_data_t tfm_peripheral_uarte20;
extern struct platform_data_t tfm_peripheral_uarte21;
extern struct platform_data_t tfm_peripheral_uarte22;
extern struct platform_data_t tfm_peripheral_uarte30;

#define TFM_PERIPHERAL_UARTE00       (&tfm_peripheral_uarte00)
#define TFM_PERIPHERAL_UARTE20       (&tfm_peripheral_uarte20)
#define TFM_PERIPHERAL_UARTE21       (&tfm_peripheral_uarte21)
#define TFM_PERIPHERAL_UARTE22       (&tfm_peripheral_uarte22)
#define TFM_PERIPHERAL_UARTE30       (&tfm_peripheral_uarte30)

#define TFM_PERIPHERAL_STD_UART     TFM_PERIPHERAL_UARTE30

#ifdef PSA_API_TEST_IPC
/* see other platforms when supporting this */
#error "Not supported yet"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PERIPHERALS_DEF_H__ */
