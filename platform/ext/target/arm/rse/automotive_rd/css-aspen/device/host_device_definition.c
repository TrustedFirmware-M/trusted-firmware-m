/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 * definitions from device_cfg.h.
 */

#include "platform_base_address.h"

#include "host_base_address.h"
#include "host_device_definition.h"

#ifdef RSE_USE_HOST_UART
static const struct uart_pl011_dev_cfg_t UART0_PL011_DEV_CFG_NS = {
    .base = HOST_UART0_BASE_NS,
    .def_baudrate = DEFAULT_UART_BAUDRATE,
    .def_wlen = UART_PL011_WLEN_8,
    .def_parity = UART_PL011_PARITY_DISABLED,
    .def_stopbit = UART_PL011_STOPBIT_1
};
static struct uart_pl011_dev_data_t UART0_PL011_DEV_DATA_NS = {
    .state = 0,
    .uart_clk = 0,
    .baudrate = 0
};
struct uart_pl011_dev_t UART0_PL011_DEV_NS = {
    &(UART0_PL011_DEV_CFG_NS),
    &(UART0_PL011_DEV_DATA_NS)
};
#endif /* RSE_USE_HOST_UART */

#ifdef PLATFORM_HOST_HAS_SI_CL0
const struct ppu_dev_t HOST_SI_CL0_CLUS_PPU_DEV = {
    .ppu_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x10000,
    .cluster_safety_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x80000,
};
const struct ppu_dev_t HOST_SI_CL0_CORE0_PPU_DEV = {
    .ppu_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x40000,
    .cluster_safety_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x80000,
};
#endif /* PLATFORM_HOST_HAS_SI_CL0 */
