/*
 * Copyright (c) 2019 Arm Limited. All rights reserved.
 * Copyright (c) 2025 Nordic Semiconductor ASA. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __RTE_DEVICE_H
#define __RTE_DEVICE_H

#define RTE_USART20 1

#define RTE_USART20_PINS         \
{                                \
        NRF_PSEL(UART_TX,  0, 32),\
        NRF_PSEL(UART_RX,  0, 33),\
        NRF_PSEL(UART_RTS, 0, 34),\
        NRF_PSEL(UART_CTS, 0, 35),\
}


#define RTE_USART21 1

#define RTE_USART21_PINS         \
{                                \
        NRF_PSEL(UART_TX,  0, 40),\
        NRF_PSEL(UART_RX,  0, 41),\
        NRF_PSEL(UART_RTS, 0, 42),\
        NRF_PSEL(UART_CTS, 0, 43),\
}


#define RTE_FLASH0 1

#endif  /* __RTE_DEVICE_H */
