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
 * \file device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 * definitions from device_cfg.h.
 * This file is meant to be used as a helper for baremetal
 * applications and/or as an example of how to configure the generic
 * driver structures.
 */

#include "host_device_definition.h"
#include "platform_base_address.h"
#include "host_base_address.h"

/* Arm UART PL011 driver structures */
#ifdef UART0_PL011_S
static const struct uart_pl011_dev_cfg_t UART0_PL011_DEV_CFG_S = {
    .base = HOST_UART0_BASE_S,
    .def_baudrate = DEFAULT_UART_BAUDRATE,
    .def_wlen = UART_PL011_WLEN_8,
    .def_parity = UART_PL011_PARITY_DISABLED,
    .def_stopbit = UART_PL011_STOPBIT_1};
static struct uart_pl011_dev_data_t UART0_PL011_DEV_DATA_S = {
    .state = 0,
    .uart_clk = 0,
    .baudrate = 0};
struct uart_pl011_dev_t UART0_PL011_DEV_S = {&(UART0_PL011_DEV_CFG_S),
                                             &(UART0_PL011_DEV_DATA_S)};
#endif
#ifdef UART0_PL011_NS
static const struct uart_pl011_dev_cfg_t UART0_PL011_DEV_CFG_NS = {
    .base = HOST_UART0_BASE_NS,
    .def_baudrate = DEFAULT_UART_BAUDRATE,
    .def_wlen = UART_PL011_WLEN_8,
    .def_parity = UART_PL011_PARITY_DISABLED,
    .def_stopbit = UART_PL011_STOPBIT_1};
static struct uart_pl011_dev_data_t UART0_PL011_DEV_DATA_NS = {
    .state = 0,
    .uart_clk = 0,
    .baudrate = 0};
struct uart_pl011_dev_t UART0_PL011_DEV_NS = {&(UART0_PL011_DEV_CFG_NS),
                                              &(UART0_PL011_DEV_DATA_NS)};
#endif

#if (defined (SPI_STRATAFLASHJ3_S) && defined (CFI_S))
static const struct cfi_dev_cfg_t CFI_DEV_CFG_S = {
    /* Define the flash base/size to be the same as the host access area, as the
     * flash may not be mapped contiguously or predictably within that area.
     */
    .base = HOST_ACCESS_BASE_S,
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

/* Message Handling Units (MHU) */
#ifdef MHU_AP_MONITOR_TO_RSE
struct mhu_v2_x_dev_t MHU_AP_MONITOR_TO_RSE_DEV = {
    2,
    MHU0_RECEIVER_BASE_S,
    MHU_V2_X_RECEIVER_FRAME};
#endif

#ifdef MHU_RSE_TO_AP_MONITOR
struct mhu_v2_x_dev_t MHU_RSE_TO_AP_MONITOR_DEV = {
    2,
    MHU0_SENDER_BASE_S,
    MHU_V2_X_SENDER_FRAME};
#endif

#ifdef MHU_SCP_TO_RSE
struct mhu_v2_x_dev_t MHU_SCP_TO_RSE_DEV = {
    2,
    MHU2_RECEIVER_BASE_S,
    MHU_V2_X_RECEIVER_FRAME};
#endif

#ifdef MHU_RSE_TO_SCP
struct mhu_v2_x_dev_t MHU_RSE_TO_SCP_DEV = {
    2,
    MHU2_SENDER_BASE_S,
    MHU_V2_X_SENDER_FRAME};
#endif
