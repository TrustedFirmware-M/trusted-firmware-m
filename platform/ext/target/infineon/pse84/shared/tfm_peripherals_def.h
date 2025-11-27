/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_PERIPHERALS_DEF_H
#define TFM_PERIPHERALS_DEF_H

#include "cycfg.h"

/* ifx_peripherals_def.h should be provided by BSP to define peripheral
 * configuration for SPE and NSPE */
#include "ifx_peripherals_def.h"

#if DOMAIN_S
/* ifx_s_peripherals_def.h should be provided by BSP to define peripheral
 * configuration for SPE */
#include "ifx_s_peripherals_def.h"

/* Defines partition MMIO asset which is defined in TF-M/tf-m-tests/psa-arch-tests
 * partition manifest, but is not used by platform.
 */
#define IFX_UNUSED_MMIO                     (0xFFFFFFFFu)

#if IFX_UART_ENABLED
/* UART block to use */
#define IFX_TFM_SPM_UART                    (IFX_TFM_SPM_UART_HW)
#ifndef IFX_TFM_SPM_UART_FLUSH
#define IFX_TFM_SPM_UART_FLUSH               0
#endif /* IFX_TFM_SPM_UART_FLUSH */
#endif /* IFX_UART_ENABLED */
#endif /* DOMAIN_S */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Quantized default IRQ priority, the value is:
 * (Number of configurable priority) / 4: (1UL << __NVIC_PRIO_BITS) / 4
 */
#define DEFAULT_IRQ_PRIORITY    (1UL << (__NVIC_PRIO_BITS - 2))

/* IPC channel 9 for M55 -> M33 */
#define IFX_IPC_NS_TO_TFM_CHAN              (9U)
#define IFX_IPC_NS_TO_TFM_INTR_MASK         (1UL << IFX_IPC_NS_TO_TFM_CHAN)
/* IPC interrupt 6 */
#define IFX_IPC_NS_TO_TFM_INTR_STRUCT       (6U)
#define IFX_IPC_NS_TO_TFM_NOTIFY_MASK       (1UL << IFX_IPC_NS_TO_TFM_INTR_STRUCT)
#define IFX_IPC_NS_TO_TFM_IPC_INTR          m33syscpuss_interrupts_ipc_dpslp_6_IRQn

/* IPC channel 8 for M33 -> M55 */
#define IFX_IPC_TFM_TO_NS_CHAN              (8U)
#define IFX_IPC_TFM_TO_NS_INTR_MASK         (1UL << IFX_IPC_TFM_TO_NS_CHAN)
/* IPC interrupt 7 */
#define IFX_IPC_TFM_TO_NS_INTR_STRUCT       (7U)
#define IFX_IPC_TFM_TO_NS_NOTIFY_MASK       (1UL << IFX_IPC_TFM_TO_NS_INTR_STRUCT)
#define IFX_IPC_TFM_TO_NS_IPC_INTR          m33syscpuss_interrupts_ipc_dpslp_7_IRQn

/* IPC channel 10 for mailbox critical sections */
#define IFX_IPC_MAILBOX_LOCK_CHAN           (10U)

/* Interrupt priorities to use for IPC interrupts */
#ifndef IFX_IPC_TFM_TO_NS_IRQ_PRIORITY
#define IFX_IPC_TFM_TO_NS_IRQ_PRIORITY      3U
#endif
#ifndef IFX_IPC_NS_TO_TFM_IRQ_PRIORITY
#define IFX_IPC_NS_TO_TFM_IRQ_PRIORITY      3U
#endif

#if DOMAIN_S
/* SPE-to-NSPE interrupt */
#define MAILBOX_IRQ                         IFX_IPC_NS_TO_TFM_IPC_INTR
#else
/* NSPE-to-SPE interrupt */
#define MAILBOX_IRQ                         IFX_IPC_TFM_TO_NS_IPC_INTR
#endif /* DOMAIN_S */

/* Section that defines peripherals used by tests */
#if DOMAIN_S
/* TF-M Regression Tests use UART provided by SPM */
#define TFM_PERIPHERAL_STD_UART             (IFX_UNUSED_MMIO)
#define TFM_PERIPHERAL_TIMER0               (IFX_UNUSED_MMIO)
/* FF Tests use UART provided by SPM */
#define FF_TEST_UART_REGION                 (IFX_UNUSED_MMIO)

#ifndef IFX_IRQ_TEST_TIMER_S_SYSTICK
#define IFX_IRQ_TEST_TIMER_S_SYSTICK        1
#endif
#if IFX_IRQ_TEST_TIMER_S_SYSTICK
#define TFM_TIMER0_IRQ                      SysTick_IRQn
#else
/* Add timer in Device Configurator with IFX_IRQ_TEST_TIMER_S name. */
#define TFM_TIMER0_IRQ                      IFX_IRQ_TEST_TIMER_S_IRQ
#endif

/* TFM regression tests and PSA arch tests are mutually exclusive thus
 * TFM_TIMER0_IRQ can be reused for FF_TEST_UART_IRQ to save up the resources */
#define FF_TEST_UART_IRQ                    TFM_TIMER0_IRQ

/* Watchdog is not supported for psa-arch-tests */
#define FF_TEST_WATCHDOG_REGION             IFX_UNUSED_MMIO

/* Following FF_* memory regions are assigned to FF tests partitions as NAMED
 * mmio_regions, but in PSE84 NAMED mmio_regions represent peripherals.
 * Thus following FF_* defines are set to IFX_UNUSED_MMIO and instead respective
 * memory areas are added to partitions as NUMBERED mmio_regions in
 * partition_info.template */
#define FF_TEST_DRIVER_PARTITION_MMIO       IFX_UNUSED_MMIO
#define FF_TEST_SERVER_PARTITION_MMIO       IFX_UNUSED_MMIO
#define FF_TEST_NVMEM_REGION                IFX_UNUSED_MMIO
#endif /* DOMAIN_S */

/* Free peripheral that does not require configuration is used */
#define IFX_TEST_PERIPHERAL_1               PROT_PERI0_GPIO_PRT0_PRT
#define IFX_TEST_PERIPHERAL_1_BASE          GPIO_PRT0
#define IFX_TEST_PERIPHERAL_1_SIZE          0x40U

/* Free peripheral that does not require configuration is used */
#define IFX_TEST_PERIPHERAL_2               PROT_PERI0_GPIO_PRT1_PRT
#define IFX_TEST_PERIPHERAL_2_BASE          GPIO_PRT1
#define IFX_TEST_PERIPHERAL_2_SIZE          0x40U

#ifdef __cplusplus
}
#endif

#endif /* TFM_PERIPHERALS_DEF_H */
