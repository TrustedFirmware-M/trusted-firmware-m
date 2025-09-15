/*
 * Copyright (c) 2018-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

#include "platform_irq.h"

#ifdef __cplusplus
extern "C" {
#endif

struct tfm_spm_partition_platform_data_t;

extern struct tfm_spm_partition_platform_data_t tfm_peripheral_std_uart;

#define TFM_PERIPHERAL_STD_UART     (&tfm_peripheral_std_uart)

/* NSPE-to-SPE interrupt */
#define MAILBOX_IRQ HSE1_RECEIVER_COMBINED_IRQn

#define ADAC_REQUEST_IRQ SE_INTERRUPT_EXPANSION_IRQn

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PERIPHERALS_DEF_H__ */
