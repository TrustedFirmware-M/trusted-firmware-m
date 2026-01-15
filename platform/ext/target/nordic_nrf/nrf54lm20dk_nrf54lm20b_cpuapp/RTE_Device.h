/*
 * Copyright (c) 2019 Arm Limited. All rights reserved.
 * Copyright (c) 2020 Nordic Semiconductor ASA. All rights reserved.
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

#define RTE_USART20_PINS          \
{                                 \
        NRF_PSEL(UART_TX,  0, 36),\
        NRF_PSEL(UART_RX,  0, 37),\
        NRF_PSEL(UART_RTS, 0, 38),\
        NRF_PSEL(UART_CTS, 0, 39),\
}


#define RTE_USART30 1

#define RTE_USART30_PINS         \
{                                \
        NRF_PSEL(UART_TX,  0, 0),\
        NRF_PSEL(UART_RX,  0, 1),\
        NRF_PSEL(UART_RTS, 0, 2),\
        NRF_PSEL(UART_CTS, 0, 3),\
}


#define RTE_FLASH0 1

#endif  /* __RTE_DEVICE_H */
