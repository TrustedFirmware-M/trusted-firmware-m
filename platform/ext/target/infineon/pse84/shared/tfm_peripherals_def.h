/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_PERIPHERALS_DEF_H
#define TFM_PERIPHERALS_DEF_H

#include "tfm_peripherals_def_common.h"

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

/* Free peripheral that does not require configuration is used */
#define IFX_TEST_PERIPHERAL_1               PROT_PERI0_GPIO_PRT0_PRT
#define IFX_TEST_PERIPHERAL_1_BASE          GPIO_PRT0
#define IFX_TEST_PERIPHERAL_1_SIZE          0x40U

/* Free peripheral that does not require configuration is used */
#define IFX_TEST_PERIPHERAL_2               PROT_PERI0_GPIO_PRT1_PRT
#define IFX_TEST_PERIPHERAL_2_BASE          GPIO_PRT1
#define IFX_TEST_PERIPHERAL_2_SIZE          0x40U

/* Free peripheral that does not require configuration is used */
#define IFX_TEST_PERIPHERAL_3               PROT_PERI0_GPIO_PRT2_PRT
#define IFX_TEST_PERIPHERAL_3_BASE          GPIO_PRT2
#define IFX_TEST_PERIPHERAL_3_SIZE          0x40U

#endif /* TFM_PERIPHERALS_DEF_H */
