/*
 * Copyright (c) 2021, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_PERIPHERALS_CONFIG_H__
#define TFM_PERIPHERALS_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SECURE_UART1
#if NRF_SECURE_UART_INSTANCE == 30
#define TFM_PERIPHERAL_UARTE30_SECURE 1
#endif
#endif

/* The target_cfg.c requires this to be set */
#define TFM_PERIPHERAL_GPIO0_PIN_MASK_SECURE 0

#ifdef __cplusplus
}
#endif

#endif /* TFM_PERIPHERAL_CONFIG_H__ */
