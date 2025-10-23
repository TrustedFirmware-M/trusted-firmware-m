/*
 * Copyright (c) 2025 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef TFM_INCLUDE_NRF_PINCTRL_H
#define TFM_INCLUDE_NRF_PINCTRL_H

/* The nrf-pinctrl.h is a copy of the header:
 * include/zephyr/dt-bindings/pinctrl/nrf-pinctrl.h
 * in Zephyr and it needs to be kept in sync.
 */
#include "nrf-pinctrl.h"

/* Copied from the header soc/nordic/common/pinctrl_soc.h in Zephyr because they are
 * used by the Driver_USART.c in TF-M.
 */

/**
 * @brief Utility macro to obtain pin function.
 *
 * @param pincfg Pin configuration bit field.
 */
#define NRF_GET_FUN(pincfg) (((pincfg) >> NRF_FUN_POS) & NRF_FUN_MSK)

/**
 * @brief Utility macro to obtain port and pin combination.
 *
 * @param pincfg Pin configuration bit field.
 */
#define NRF_GET_PIN(pincfg) (((pincfg) >> NRF_PIN_POS) & NRF_PIN_MSK)

#endif /* TFM_INCLUDE_NRF_PINCTRL_H */

