/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file  rse_expansion_device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 *        definitions from device_cfg.h.
 */

#include "rse_expansion_device_definition.h"
#include "platform_base_address.h"

/* Arm UART PL011 driver structures */
#ifdef UART0_PL011_S
static const struct uart_pl011_dev_cfg_t UART0_PL011_DEV_CFG_S = {
    .base = UART0_BASE_S,
    .def_baudrate = DEFAULT_UART_BAUDRATE,
    .def_wlen = UART_PL011_WLEN_8,
    .def_parity = UART_PL011_PARITY_DISABLED,
    .def_stopbit = UART_PL011_STOPBIT_1
};
static struct uart_pl011_dev_data_t UART0_PL011_DEV_DATA_S = {
    .state = 0,
    .uart_clk = 0,
    .baudrate = 0
};
struct uart_pl011_dev_t UART0_PL011_DEV_S = {
    &(UART0_PL011_DEV_CFG_S),
    &(UART0_PL011_DEV_DATA_S)
};
#endif

#if (defined (SPI_STRATAFLASHJ3_S) && defined (CFI_S))
static const struct cfi_dev_cfg_t CFI_DEV_CFG_S = {
    .base = BOOT_FLASH_BASE_S,
};
struct cfi_dev_t CFI_DEV_S = {
    .cfg = &CFI_DEV_CFG_S,
};
#endif

#if (defined(SPI_STRATAFLASHJ3_S) && defined(CFI_S))
struct cfi_strataflashj3_dev_t SPI_STRATAFLASHJ3_DEV = {
    .controller = &CFI_DEV_S,
    .total_sector_cnt = 0,
    .page_size = 0,
    .sector_size = 0,
    .program_unit = 0,
    .is_initialized = false
};
#endif

#ifdef MHU_RSE_TO_RSE_SIDEBAND_RECEIVER_COUNT
struct mhu_v2_x_dev_t MHU_RSE_TO_RSE_RECEIVER_DEVS[RSE_AMOUNT - 1] = {
    {
        .version = 2,
        .base = MHU_SIDEBAND_0_RECEIVER_BASE_S,
        .frame = MHU_V2_X_RECEIVER_FRAME,
        .subversion = 0
    },
#if MHU_RSE_TO_RSE_SIDEBAND_RECEIVER_COUNT > 1
    {
        .version = 2,
        .base = MHU_SIDEBAND_1_RECEIVER_BASE_S,
        .frame = MHU_V2_X_RECEIVER_FRAME,
        .subversion = 0
    },
#endif
#if MHU_RSE_TO_RSE_SIDEBAND_RECEIVER_COUNT > 2
    {
        .version = 2,
        .base = MHU_SIDEBAND_2_RECEIVER_BASE_S,
        .frame = MHU_V2_X_RECEIVER_FRAME,
        .subversion = 0
    },
#endif
};
#endif /* MHU_RSE_TO_RSE_SIDEBAND_RECEIVER_COUNT */

#ifdef MHU_RSE_TO_RSE_SIDEBAND_SENDER_COUNT
struct mhu_v2_x_dev_t MHU_RSE_TO_RSE_SENDER_DEVS[RSE_AMOUNT - 1] = {
    {
        .version = 2,
        .base = MHU_SIDEBAND_0_SENDER_BASE_S,
        .frame = MHU_V2_X_SENDER_FRAME,
        .subversion = 0
    },
#if MHU_RSE_TO_RSE_SIDEBAND_SENDER_COUNT > 1
    {
        .version = 2,
        .base = MHU_SIDEBAND_1_SENDER_BASE_S,
        .frame = MHU_V2_X_SENDER_FRAME,
        .subversion = 0
    },
#endif
#if MHU_RSE_TO_RSE_SIDEBAND_SENDER_COUNT > 2
    {
        .version = 2,
        .base = MHU_SIDEBAND_2_SENDER_BASE_S,
        .frame = MHU_V2_X_SENDER_FRAME,
        .subversion = 0
    },
#endif
};
#endif /* MHU_RSE_TO_RSE_SIDEBAND_SENDER_COUNT */
