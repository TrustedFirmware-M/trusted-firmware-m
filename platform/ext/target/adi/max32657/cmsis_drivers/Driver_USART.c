/*
 * Copyright (c) 2013-2022 ARM Limited. All rights reserved.
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Driver_USART.h"

#include "mxc_device.h"
#include "uart.h"
#include "RTE_Device.h"
#include "device_cfg.h"

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  (void)arg
#endif

/* Driver version */
#define ARM_USART_DRV_VERSION  ARM_DRIVER_VERSION_MAJOR_MINOR(2, 2)

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_USART_API_VERSION,
    ARM_USART_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_USART_CAPABILITIES DriverCapabilities = {
    1, /* supports UART (Asynchronous) mode */
    0, /* supports Synchronous Master mode */
    0, /* supports Synchronous Slave mode */
    0, /* supports UART Single-wire mode */
    0, /* supports UART IrDA mode */
    0, /* supports UART Smart Card mode */
    0, /* Smart Card Clock generator available */
    0, /* RTS Flow Control available */
    0, /* CTS Flow Control available */
    0, /* Transmit completed event: \ref ARM_USARTx_EVENT_TX_COMPLETE */
    0, /* Signal receive character timeout event: \ref ARM_USARTx_EVENT_RX_TIMEOUT */
    0, /* RTS Line: 0=not available, 1=available */
    0, /* CTS Line: 0=not available, 1=available */
    0, /* DTR Line: 0=not available, 1=available */
    0, /* DSR Line: 0=not available, 1=available */
    0, /* DCD Line: 0=not available, 1=available */
    0, /* RI Line: 0=not available, 1=available */
    0, /* Signal CTS change event: \ref ARM_USARTx_EVENT_CTS */
    0, /* Signal DSR change event: \ref ARM_USARTx_EVENT_DSR */
    0, /* Signal DCD change event: \ref ARM_USARTx_EVENT_DCD */
    0, /* Signal RI change event: \ref ARM_USARTx_EVENT_RI */
    0  /* Reserved */
};

static ARM_DRIVER_VERSION ARM_USART_GetVersion(void)
{
    return DriverVersion;
}

static ARM_USART_CAPABILITIES ARM_USART_GetCapabilities(void)
{
    return DriverCapabilities;
}

typedef struct {
    mxc_uart_regs_t* dev;               /* UART regs */
    uint32_t tx_nbr_bytes;              /* Number of bytes transfered */
    uint32_t rx_nbr_bytes;              /* Number of bytes recevied */
    ARM_USART_SignalEvent_t cb_event;   /* Callback function for events */
} UARTx_Resources;

static int32_t ARM_USARTx_Initialize(UARTx_Resources* uart_dev)
{
    /* Initializes generic UART driver */
    MXC_UART_Init(uart_dev->dev, DEFAULT_UART_BAUDRATE, MXC_UART_APB_CLK);

    return ARM_DRIVER_OK;
}

static int32_t ARM_USARTx_Send(UARTx_Resources* uart_dev, const void *src, uint32_t len)
{
    if (src == NULL) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    int retVal;
    uint8_t *data = (uint8_t *)src;
    uint32_t i = 0;

    while (i < len) {
        retVal = MXC_UART_WriteCharacter(uart_dev->dev, data[i]);
        if (retVal == E_NO_ERROR) {
            i++;
        }
    }
    uart_dev->tx_nbr_bytes = i;

    if (uart_dev->cb_event) {
        uart_dev->cb_event(ARM_USART_EVENT_RECEIVE_COMPLETE);
    }

    return ARM_DRIVER_OK;
}

static int32_t ARM_USARTx_Receive(UARTx_Resources* uart_dev, void *dst, uint32_t len)
{
    if (dst == NULL) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    int retVal;
    uint8_t *data = (uint8_t *)dst;
    uint32_t i = 0;

    while (i < len) {
        retVal = MXC_UART_ReadCharacter(uart_dev->dev);
        if (retVal >= 0) {
            data[i] = retVal;
            i++;
        }
    }
    uart_dev->rx_nbr_bytes = i;

    if (uart_dev->cb_event) {
        uart_dev->cb_event(ARM_USART_EVENT_RECEIVE_COMPLETE);
    }

    return ARM_DRIVER_OK;
}

static uint32_t ARM_USARTx_GetTxCount(UARTx_Resources* uart_dev)
{
    return uart_dev->tx_nbr_bytes;
}

static uint32_t ARM_USARTx_GetRxCount(UARTx_Resources* uart_dev)
{
    return uart_dev->rx_nbr_bytes;
}

static int32_t ARM_USARTx_Control(UARTx_Resources* uart_dev, uint32_t control,
                                  uint32_t arg)
{
    if ((control & ARM_USART_CONTROL_Msk) != ARM_USART_MODE_ASYNCHRONOUS) {
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    if(MXC_UART_SetFrequency(uart_dev->dev, arg, MXC_UART_APB_CLK) < 0) {
        return ARM_USART_ERROR_BAUDRATE;
    }

    /* UART Data bits */
    switch (control & ARM_USART_DATA_BITS_Msk) {
        case ARM_USART_DATA_BITS_5:
            MXC_UART_SetDataSize(uart_dev->dev, 5);
            break;
        case ARM_USART_DATA_BITS_6:
            MXC_UART_SetDataSize(uart_dev->dev, 6);
            break;
        case ARM_USART_DATA_BITS_7:
            MXC_UART_SetDataSize(uart_dev->dev, 7);
            break;
        case ARM_USART_DATA_BITS_8:
            MXC_UART_SetDataSize(uart_dev->dev, 8);
            break;
        default:
            return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    /* UART Parity */
    switch (control & ARM_USART_PARITY_Msk) {
        case ARM_USART_PARITY_NONE:
            MXC_UART_SetParity(uart_dev->dev, MXC_UART_PARITY_DISABLE);
            break;
        case ARM_USART_PARITY_EVEN:
            MXC_UART_SetParity(uart_dev->dev, MXC_UART_PARITY_EVEN_1);
            break;
        case ARM_USART_PARITY_ODD:
            MXC_UART_SetParity(uart_dev->dev, MXC_UART_PARITY_ODD_1);
            break;
    }

    /* USART Stop bits */
    switch (control & ARM_USART_STOP_BITS_Msk) {
        case ARM_USART_STOP_BITS_1:
            MXC_UART_SetStopBits(uart_dev->dev, MXC_UART_STOP_1);
            break;
        case ARM_USART_STOP_BITS_2:
            MXC_UART_SetStopBits(uart_dev->dev, MXC_UART_STOP_2);
            break;
        default:
            return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    return ARM_DRIVER_OK;
}

static int32_t ARM_USARTx_PowerControl(UARTx_Resources* uart_dev,
                                        ARM_POWER_STATE state)
{
    ARG_UNUSED(uart_dev);

    switch (state) {
    case ARM_POWER_OFF:
    case ARM_POWER_LOW:
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    case ARM_POWER_FULL:
        /* Nothing to be done */
        return ARM_DRIVER_OK;
    default:
        return ARM_DRIVER_ERROR_PARAMETER;
    }
}

#if (RTE_USART0)

/* USART0 Driver wrapper functions */
static UARTx_Resources USART0_DEV = {
    .dev = MXC_UART,
    .tx_nbr_bytes = 0,
    .rx_nbr_bytes = 0,
    .cb_event = NULL,
};

static int32_t ARM_USART0_Initialize(ARM_USART_SignalEvent_t cb_event)
{
    USART0_DEV.cb_event = cb_event;

    return ARM_USARTx_Initialize(&USART0_DEV);
}

static int32_t ARM_USART0_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t ARM_USART0_PowerControl(ARM_POWER_STATE state)
{
    return ARM_USARTx_PowerControl(&USART0_DEV, state);
}

static int32_t ARM_USART0_Send(const void *data, uint32_t num)
{
    return ARM_USARTx_Send(&USART0_DEV, data, num);
}

static int32_t ARM_USART0_Receive(void *data, uint32_t num)
{
    return ARM_USARTx_Receive(&USART0_DEV, data, num);
}

static int32_t ARM_USART0_Transfer(const void *data_out, void *data_in,
                                   uint32_t num)
{
    ARG_UNUSED(data_out);
    ARG_UNUSED(data_in);
    ARG_UNUSED(num);

    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static uint32_t ARM_USART0_GetTxCount(void)
{
    return ARM_USARTx_GetTxCount(&USART0_DEV);
}

static uint32_t ARM_USART0_GetRxCount(void)
{
    return ARM_USARTx_GetRxCount(&USART0_DEV);
}

static int32_t ARM_USART0_Control(uint32_t control, uint32_t arg)
{
    return ARM_USARTx_Control(&USART0_DEV, control, arg);
}

static ARM_USART_STATUS ARM_USART0_GetStatus(void)
{
    ARM_USART_STATUS status = {0, 0, 0, 0, 0, 0, 0, 0};
    return status;
}

static int32_t ARM_USART0_SetModemControl(ARM_USART_MODEM_CONTROL control)
{
    ARG_UNUSED(control);

    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static ARM_USART_MODEM_STATUS ARM_USART0_GetModemStatus(void)
{
    ARM_USART_MODEM_STATUS modem_status = {0, 0, 0, 0, 0};

    return modem_status;
}

extern ARM_DRIVER_USART Driver_USART0;
ARM_DRIVER_USART Driver_USART0 = {
    ARM_USART_GetVersion,
    ARM_USART_GetCapabilities,
    ARM_USART0_Initialize,
    ARM_USART0_Uninitialize,
    ARM_USART0_PowerControl,
    ARM_USART0_Send,
    ARM_USART0_Receive,
    ARM_USART0_Transfer,
    ARM_USART0_GetTxCount,
    ARM_USART0_GetRxCount,
    ARM_USART0_Control,
    ARM_USART0_GetStatus,
    ARM_USART0_SetModemControl,
    ARM_USART0_GetModemStatus
};
#endif /* RTE_USART0 */
