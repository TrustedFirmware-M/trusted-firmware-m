/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __RTE_DEVICE_H
#define __RTE_DEVICE_H

#include <tfm-pinctrl.h>

#define RTE_USART0 1

#define RTE_USART0_PINS            \
{                                  \
        NRF_PSEL(UART_TX,  0, 27), \
        NRF_PSEL(UART_RX,  0, 26), \
        NRF_PSEL(UART_RTS, 0, 14), \
        NRF_PSEL(UART_CTS, 0, 15), \
}


#define RTE_USART1 1

#define RTE_USART1_PINS            \
{                                  \
        NRF_PSEL(UART_TX,  0, 29), \
        NRF_PSEL(UART_RX,  0, 28), \
        NRF_PSEL(UART_RTS, 0, 16), \
        NRF_PSEL(UART_CTS, 0, 17), \
}

#define RTE_FLASH0 1

#endif  /* __RTE_DEVICE_H */
