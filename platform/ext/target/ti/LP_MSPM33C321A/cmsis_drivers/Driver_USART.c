/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * CMSIS ARM_DRIVER_USART implementation for MSPM33C321A.
 *
 * Wraps TI driverlib DL_UART_* APIs from dl_unicommuart.h.
 *
 * MSPM33C321A uses a "Universal Communications" (UNICOMM) peripheral
 * architecture.  On LP_MSPM33C321A, "UART0" is implemented by the UC12
 * module in UART mode.  The driverlib API takes UNICOMM_Inst_Regs* — use
 * the UC12 instance pointer (not UC12_UART which is UNICOMMUART_Regs*).
 *
 * ARM_USART_Initialize sets up pin-mux only.  PowerControl(ARM_POWER_FULL)
 * performs hardware bring-up: power-on, clock, mode, baud rate, and enable.
 *
 * Default configuration (LP_MSPM33C321A):
 *   PA10 (PINCM21) = UC12 TX, PA11 (PINCM22) = UC12 RX
 *   32 MHz BUSCLK, 115200 baud, 16x oversampling, 8N1
 */

#include <stdint.h>
#include <stdbool.h>

#include "Driver_USART.h"
#include "platform_base_address.h"
#include <ti/driverlib/dl_unicommuart.h>
#include <ti/driverlib/dl_gpio.h>
#include <ti/devices/msp/msp.h>

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  ((void)(arg))
#endif

/*----------------------------------------------------------------------------
  Driver version
 *----------------------------------------------------------------------------*/
#define ARM_USART_DRV_VERSION  ARM_DRIVER_VERSION_MAJOR_MINOR(2, 2)

static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_USART_API_VERSION,
    ARM_USART_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_USART_CAPABILITIES DriverCapabilities = {
    1, /* supports UART (Asynchronous) mode */
    0, /* supports Synchronous Master mode  */
    0, /* supports Synchronous Slave mode   */
    0, /* supports UART Single-wire mode    */
    0, /* supports UART IrDA mode           */
    0, /* supports UART Smart Card mode     */
    0, /* Smart Card Clock generator        */
    0, /* RTS Flow Control                  */
    0, /* CTS Flow Control                  */
    0, /* TX complete event                 */
    0, /* RX timeout event                  */
    0, /* RTS Line                          */
    0, /* CTS Line                          */
    0, /* DTR Line                          */
    0, /* DSR Line                          */
    0, /* DCD Line                          */
    0, /* RI Line                           */
    0, /* Signal CTS change                 */
    0, /* Signal DSR change                 */
    0, /* Signal DCD change                 */
    0, /* Signal RI change                  */
    0  /* Reserved                          */
};

/* Spin-count per byte before ARM_USART_Receive returns a timeout error.
 * At 115200 baud and ~32 MHz this gives ~40× margin (~3 ms per byte). */
#define RX_TIMEOUT_CYCLES  100000U

/* BUSCLK frequency assumed by DL_UART_configBaudRate (32 MHz, divide-by-1) */
#define UART_BUSCLK_HZ     32000000U

/*----------------------------------------------------------------------------
  Internal UART device state and configuration
 *----------------------------------------------------------------------------*/
typedef struct {
    UNICOMM_Inst_Regs   *base;           /* UNICOMM instance (UC12)          */
    uint32_t             tx_pincm;       /* IOMUX PINCM index for TX pin     */
    uint32_t             tx_pf;          /* TX pin function select value     */
    uint32_t             rx_pincm;       /* IOMUX PINCM index for RX pin     */
    uint32_t             rx_pf;          /* RX pin function select value     */
    DL_UART_ClockConfig  clk_cfg;        /* Clock source and divider         */
    DL_UART_Config       uart_cfg;       /* Mode, direction, framing         */
    uint32_t             ibrd;           /* Integer baud-rate divisor        */
    uint32_t             fbrd;           /* Fractional baud-rate divisor     */
    DL_UART_OVERSAMPLING_RATE oversampling;
    uint32_t             tx_nbr_bytes;
    uint32_t             rx_nbr_bytes;
    bool                 is_initialized;
    ARM_POWER_STATE      power_state;
} UARTx_Resources;

/*
 * Default configuration for UART0 on LP_MSPM33C321A:
 *   UC12, PA10/PA11, 32 MHz BUSCLK, 115200 baud 8N1, 16x oversampling
 *   IBRD=17, FBRD=23  (32e6 / (16 * 115200) = 17.361...)
 */
static UARTx_Resources UART0_DEV = {
    .base          = UC12,
    .tx_pincm      = IOMUX_PINCM21,
    .tx_pf         = IOMUX_PINCM21_PF_UC12_TX,
    .rx_pincm      = IOMUX_PINCM22,
    .rx_pf         = IOMUX_PINCM22_PF_UC12_RX,
    .clk_cfg = {
        .clockSel    = DL_UART_CLOCK_BUSCLK,
        .divideRatio = DL_UART_CLOCK_DIVIDE_RATIO_1,
    },
    .uart_cfg = {
        .mode        = DL_UART_MODE_NORMAL,
        .direction   = DL_UART_DIRECTION_TX_RX,
        .flowControl = DL_UART_FLOW_CONTROL_NONE,
        .parity      = DL_UART_PARITY_NONE,
        .wordLength  = DL_UART_WORD_LENGTH_8_BITS,
        .stopBits    = DL_UART_STOP_BITS_ONE,
    },
    .ibrd          = 17U,
    .fbrd          = 23U,
    .oversampling  = DL_UART_OVERSAMPLING_RATE_16X,
    .tx_nbr_bytes  = 0,
    .rx_nbr_bytes  = 0,
    .is_initialized = false,
    .power_state   = ARM_POWER_OFF,
};

/*----------------------------------------------------------------------------
  Static helpers
 *----------------------------------------------------------------------------*/

static ARM_DRIVER_VERSION ARM_USART_GetVersion(void)
{
    return DriverVersion;
}

static ARM_USART_CAPABILITIES ARM_USART_GetCapabilities(void)
{
    return DriverCapabilities;
}

static int32_t ARM_USART_Initialize(ARM_USART_SignalEvent_t cb_event)
{
    ARG_UNUSED(cb_event);

    if (UART0_DEV.is_initialized) {
        return ARM_DRIVER_OK;
    }

    /* Pin-mux only; hardware bring-up is done in PowerControl(FULL) */
    DL_GPIO_initPeripheralOutputFunction(UART0_DEV.tx_pincm, UART0_DEV.tx_pf);
    DL_GPIO_initPeripheralInputFunction(UART0_DEV.rx_pincm,  UART0_DEV.rx_pf);

    UART0_DEV.is_initialized = true;
    UART0_DEV.power_state    = ARM_POWER_OFF;

    return ARM_DRIVER_OK;
}

static int32_t ARM_USART_Uninitialize(void)
{
    if (UART0_DEV.is_initialized) {
        /* Un-mux pins; hardware was already powered down by PowerControl(OFF) */
        IOMUX->SECCFG.PINCM[UART0_DEV.tx_pincm] = IOMUX_PINCM_PC_UNCONNECTED;
        IOMUX->SECCFG.PINCM[UART0_DEV.rx_pincm] = IOMUX_PINCM_PC_UNCONNECTED;
        UART0_DEV.is_initialized = false;
        UART0_DEV.power_state    = ARM_POWER_OFF;
    }
    return ARM_DRIVER_OK;
}

static int32_t ARM_USART_PowerControl(ARM_POWER_STATE state)
{
    if (!UART0_DEV.is_initialized) {
        return ARM_DRIVER_ERROR;
    }

    switch (state) {
    case ARM_POWER_FULL:
        if (UART0_DEV.power_state == ARM_POWER_FULL) {
            /* Already at full power, nothing to do */
            return ARM_DRIVER_OK;
        }
        if (UART0_DEV.power_state == ARM_POWER_LOW) {
            /* Resume from low power: peripheral was clock-gated, not reset.
             * Re-enable without re-initializing clock/baud/framing. */
            DL_UART_enable(UART0_DEV.base);
            UART0_DEV.power_state = ARM_POWER_FULL;
            return ARM_DRIVER_OK;
        }
        /* ARM_POWER_OFF: full re-init required (power was cut) */
        DL_UART_reset(UART0_DEV.base);
        DL_UART_enablePower(UART0_DEV.base);
        DL_UART_setClockConfig(UART0_DEV.base, &UART0_DEV.clk_cfg);
        DL_UART_init(UART0_DEV.base, &UART0_DEV.uart_cfg);
        DL_UART_setBaudRateDivisor(UART0_DEV.base, UART0_DEV.ibrd, UART0_DEV.fbrd);
        DL_UART_setOversampling(UART0_DEV.base, UART0_DEV.oversampling);
        DL_UART_enable(UART0_DEV.base);
        UART0_DEV.power_state = ARM_POWER_FULL;
        return ARM_DRIVER_OK;

    case ARM_POWER_LOW:
        if (UART0_DEV.power_state == ARM_POWER_LOW) {
            return ARM_DRIVER_OK;
        }
        if (UART0_DEV.power_state == ARM_POWER_OFF) {
            /* Cannot enter low power from power-off */
            return ARM_DRIVER_ERROR;
        }
        /* Clock-gate the peripheral; module power stays on for fast resume */
        DL_UART_disable(UART0_DEV.base);
        UART0_DEV.power_state = ARM_POWER_LOW;
        return ARM_DRIVER_OK;

    case ARM_POWER_OFF:
        if (UART0_DEV.power_state == ARM_POWER_OFF) {
            return ARM_DRIVER_OK;
        }
        DL_UART_disable(UART0_DEV.base);
        DL_UART_reset(UART0_DEV.base);
        DL_UART_disablePower(UART0_DEV.base);
        UART0_DEV.power_state = ARM_POWER_OFF;
        return ARM_DRIVER_OK;

    default:
        return ARM_DRIVER_ERROR_PARAMETER;
    }
}

/*
 * ARM_USART_Send — blocking byte-by-byte transmit via DL_UART_transmitDataBlocking
 */
static int32_t ARM_USART_Send(const void *data, uint32_t num)
{
    const uint8_t *p = (const uint8_t *)data;
    uint32_t i;

    for (i = 0; i < num; i++) {
        DL_UART_transmitDataBlocking(UART0_DEV.base, p[i]);
    }

    UART0_DEV.tx_nbr_bytes = num;
    return ARM_DRIVER_OK;
}

/*
 * ARM_USART_Receive — blocking byte-by-byte receive with timeout
 */
static int32_t ARM_USART_Receive(void *data, uint32_t num)
{
    uint8_t *p = (uint8_t *)data;
    uint32_t i;

    for (i = 0; i < num; i++) {
        uint32_t timeout = RX_TIMEOUT_CYCLES;
        while (DL_UART_isRXFIFOEmpty(UART0_DEV.base)) {
            if (--timeout == 0) {
                UART0_DEV.rx_nbr_bytes = i;
                return ARM_DRIVER_ERROR_TIMEOUT;
            }
        }
        p[i] = DL_UART_receiveData(UART0_DEV.base);
    }

    UART0_DEV.rx_nbr_bytes = num;
    return ARM_DRIVER_OK;
}

static int32_t ARM_USART_Transfer(const void *data_out, void *data_in,
                                   uint32_t num)
{
    ARG_UNUSED(data_out);
    ARG_UNUSED(data_in);
    ARG_UNUSED(num);
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static uint32_t ARM_USART_GetTxCount(void)
{
    return UART0_DEV.tx_nbr_bytes;
}

static uint32_t ARM_USART_GetRxCount(void)
{
    return UART0_DEV.rx_nbr_bytes;
}

/*
 * apply_framing — validate then re-configure parity/stop-bits/flow-control.
 * Validates all fields before touching hardware so the UART is never left
 * disabled on a bad-parameter error.  Leaves the UART disabled; caller must
 * call DL_UART_enable() afterwards.
 */
static int32_t apply_framing(uint32_t control)
{
    /* --- Validate all fields first --- */
    DL_UART_PARITY parity;
    switch (control & ARM_USART_PARITY_Msk) {
    case ARM_USART_PARITY_NONE: parity = DL_UART_PARITY_NONE; break;
    case ARM_USART_PARITY_EVEN: parity = DL_UART_PARITY_EVEN; break;
    case ARM_USART_PARITY_ODD:  parity = DL_UART_PARITY_ODD;  break;
    default: return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Hardware supports 1 or 2 stop bits only */
    DL_UART_STOP_BITS stop;
    switch (control & ARM_USART_STOP_BITS_Msk) {
    case ARM_USART_STOP_BITS_1: stop = DL_UART_STOP_BITS_ONE; break;
    case ARM_USART_STOP_BITS_2: stop = DL_UART_STOP_BITS_TWO; break;
    default: return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    /* No RTS/CTS lines are wired on this board; only NONE is honored. */
    DL_UART_FLOW_CONTROL flow;
    switch (control & ARM_USART_FLOW_CONTROL_Msk) {
    case ARM_USART_FLOW_CONTROL_NONE: flow = DL_UART_FLOW_CONTROL_NONE; break;
    default: return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    /* --- All fields valid: disable, reconfigure, leave disabled for caller --- */
    DL_UART_changeConfig(UART0_DEV.base);
    DL_UART_setParityMode(UART0_DEV.base, parity);
    DL_UART_setStopBits(UART0_DEV.base, stop);
    DL_UART_setFlowControl(UART0_DEV.base, flow);

    UART0_DEV.uart_cfg.parity      = parity;
    UART0_DEV.uart_cfg.stopBits    = stop;
    UART0_DEV.uart_cfg.flowControl = flow;

    return ARM_DRIVER_OK;
}

static int32_t ARM_USART_Control(uint32_t control, uint32_t arg)
{
    if (!UART0_DEV.is_initialized) {
        return ARM_DRIVER_ERROR;
    }

    switch (control & ARM_USART_CONTROL_Msk) {

    case ARM_USART_MODE_ASYNCHRONOUS: {
        /* Full reconfigure: framing from control word, baud rate from arg.
         * Validate framing before touching hardware. */
        int32_t ret = apply_framing(control);
        if (ret != ARM_DRIVER_OK) {
            return ret;
        }
        /* apply_framing left the UART disabled; set baud then re-enable */
        DL_UART_configBaudRate(UART0_DEV.base, UART_BUSCLK_HZ, arg);
        DL_UART_enable(UART0_DEV.base);
        return ARM_DRIVER_OK;
    }

    case ARM_USART_CONTROL_TX:
        /* TX is always enabled (DL_UART_DIRECTION_TX_RX); nothing to do */
        return ARM_DRIVER_OK;

    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }
}

static ARM_USART_STATUS ARM_USART_GetStatus(void)
{
    ARM_USART_STATUS status = {0, 0, 0, 0, 0, 0, 0, 0};
    uint32_t rxdata = DL_UART_getErrorStatus(UART0_DEV.base,
                          DL_UART_ERROR_PARITY | DL_UART_ERROR_FRAMING);
    /* Overrun is not a RXDATA bit on UNICOMMUART; read CPU_INT.RIS directly */
    if (UART0_DEV.base->uart->CPU_INT.RIS & UNICOMMUART_CPU_INT_RIS_OVRERR_SET) {
        status.rx_overflow      = 1U;
    }
    if (rxdata & DL_UART_ERROR_FRAMING) {
        status.rx_framing_error = 1U;
    }
    if (rxdata & DL_UART_ERROR_PARITY) {
        status.rx_parity_error  = 1U;
    }
    return status;
}

static int32_t ARM_USART_SetModemControl(ARM_USART_MODEM_CONTROL control)
{
    ARG_UNUSED(control);
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static ARM_USART_MODEM_STATUS ARM_USART_GetModemStatus(void)
{
    ARM_USART_MODEM_STATUS modem_status = {0, 0, 0, 0, 0};
    return modem_status;
}

/*----------------------------------------------------------------------------
  Exported driver objects
 *----------------------------------------------------------------------------*/
extern ARM_DRIVER_USART Driver_USART0;
ARM_DRIVER_USART Driver_USART0 = {
    .GetVersion      = ARM_USART_GetVersion,
    .GetCapabilities = ARM_USART_GetCapabilities,
    .Initialize      = ARM_USART_Initialize,
    .Uninitialize    = ARM_USART_Uninitialize,
    .PowerControl    = ARM_USART_PowerControl,
    .Send            = ARM_USART_Send,
    .Receive         = ARM_USART_Receive,
    .Transfer        = ARM_USART_Transfer,
    .GetTxCount      = ARM_USART_GetTxCount,
    .GetRxCount      = ARM_USART_GetRxCount,
    .Control         = ARM_USART_Control,
    .GetStatus       = ARM_USART_GetStatus,
    .SetModemControl = ARM_USART_SetModemControl,
    .GetModemStatus  = ARM_USART_GetModemStatus
};

/*
 * TF-M_DRIVER_STDIO and NS_DRIVER_STDIO are defined as Driver_USART0 in
 * target_cfg.h, so no additional alias is needed.
 */
