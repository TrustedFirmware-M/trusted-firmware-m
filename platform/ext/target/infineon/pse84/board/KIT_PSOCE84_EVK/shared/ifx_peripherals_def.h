/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_PERIPHERALS_DEF_H
#define IFX_PERIPHERALS_DEF_H

#include "cy_device.h"
#include "cy_tcpwm_counter.h"
#include "cycfg_pins.h"
#include "mxs22.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Inter-core communications IPC channels, etc */
/* Interrupt priorities to use for IPC interrupts */
#define IFX_IPC_TFM_TO_NS_IRQ_PRIORITY   3U
#define IFX_IPC_NS_TO_TFM_IRQ_PRIORITY   3U

/* Use GPIO to perform IFX IRQ preemption tests, because non-privileged code can't access NVIC.
 * CYBSP_USER_LED1 must be configured in design.modus for non-secure access. */
#define IFX_IRQ_TEST_NS_INTERRUPT               CYBSP_USER_LED1_IRQ
#define IFX_IRQ_TEST_NS_INTERRUPT_GPIO_PORT     IFX_NS_ADDRESS_ALIAS_T(GPIO_PRT_Type*, \
                                                                       CYBSP_USER_LED1_PORT)
#define IFX_IRQ_TEST_NS_INTERRUPT_GPIO_PIN      CYBSP_USER_LED1_PIN

/* Use GPIO to perform IFX IRQ preemption tests, because non-privileged code can't access NVIC.
 * CYBSP_DEBUG_UART_TX must be configured in design.modus for secure access. */
#define IFX_IRQ_TEST_FLIH_INTERRUPT             CYBSP_DEBUG_UART_TX_IRQ
#define IFX_IRQ_TEST_FLIH_INTERRUPT_GPIO_PORT   CYBSP_DEBUG_UART_TX_PORT
#define IFX_IRQ_TEST_FLIH_INTERRUPT_GPIO_PIN    CYBSP_DEBUG_UART_TX_PIN

#define TFM_FPU_NS_TEST_IRQ         ioss_interrupts_gpio_2_IRQn

/* CM55 is Non-Secure for PSE84 */
#define IFX_MXCM55                  IFX_NS_ADDRESS_ALIAS_T(MXCM55_Type*, MXCM55)

#ifdef __cplusplus
}
#endif

#endif /* IFX_PERIPHERALS_DEF_H */
