/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_PERIPHERALS_DEF_H
#define IFX_PERIPHERALS_DEF_H

#include "cy_device.h"
#include "cycfg_pins.h"
#include "mxs22.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_FPU_NS_TEST_IRQ         ioss_interrupts_gpio_2_IRQn

/* Use GPIO to perform IFX IRQ preemption tests, because non-privileged code can't access NVIC.
 * CYBSP_USER_LED1 must be configured in design.modus for non-secure access. */
#define IFX_IRQ_TEST_NS_INTERRUPT               CYBSP_USER_LED1_IRQ
#define IFX_IRQ_TEST_NS_INTERRUPT_GPIO_PORT     IFX_NS_ADDRESS_ALIAS_T(GPIO_PRT_Type*, \
                                                                       CYBSP_USER_LED1_PORT)
#define IFX_IRQ_TEST_NS_INTERRUPT_GPIO_PIN      CYBSP_USER_LED1_PIN

#define IFX_IRQ_TEST_FLIH_INTERRUPT             CYBSP_DEBUG_UART_TX_IRQ
#define IFX_IRQ_TEST_FLIH_INTERRUPT_GPIO_PORT   CYBSP_DEBUG_UART_TX_PORT
#define IFX_IRQ_TEST_FLIH_INTERRUPT_GPIO_PIN    CYBSP_DEBUG_UART_TX_PIN

#ifdef __cplusplus
}
#endif

#endif /* IFX_PERIPHERALS_DEF_H */
