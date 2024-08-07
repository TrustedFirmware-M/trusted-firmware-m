/*
 * Copyright (c) 2023-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_peripherals_def.h"
#include "tfm_hal_device_header.h"

#ifdef RSE_USE_LOCAL_UART
struct platform_data_t tfm_peripheral_std_uart = {
        LOCAL_UART0_BASE_S,
        LOCAL_UART0_BASE_S + 0xFFF,
        PPC_SP_DO_NOT_CONFIGURE,
        -1
};
#endif /* RSE_USE_LOCAL_UART */
