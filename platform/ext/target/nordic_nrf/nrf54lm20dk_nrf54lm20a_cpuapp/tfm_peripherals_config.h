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


/* Explicitly configure UART20 as non-secure for NS world */
#define TFM_PERIPHERAL_UARTE20_SECURE 0

/* The target_cfg.c requires this to be set */
#define TFM_PERIPHERAL_GPIO0_PIN_MASK_SECURE 0

#if defined(NRF54L_SERIES)
    #include <tfm_peripherals_config_nrf54l.h>
#else
    #error "Unknown device."
#endif

#ifdef __cplusplus
}
#endif

#endif /* TFM_PERIPHERAL_CONFIG_H__ */
