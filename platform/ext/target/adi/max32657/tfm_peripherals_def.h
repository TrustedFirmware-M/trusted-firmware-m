/*
 * Copyright (c) 2018-2022, Arm Limited. All rights reserved.
 * Copyright (c) 2020, Cypress Semiconductor Corporation. All rights reserved.
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

#include "max32657.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * tfm_peripheral_std_uart is defined for regression test partition
 */

struct platform_data_t;

extern struct platform_data_t tfm_peripheral_std_uart;

#define TFM_PERIPHERAL_STD_UART  (&tfm_peripheral_std_uart)

#endif /* __TFM_PERIPHERALS_DEF_H__ */
