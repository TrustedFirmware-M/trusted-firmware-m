/*
 * Copyright (c) 2023 Arm Limited. All rights reserved.
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
 * \file  rse_expansion_device_definition.h
 * \brief The structure definitions in this file are exported based on the
 *        peripheral definitions from device_cfg.h.
 */

#ifndef __RSE_EXPANSION_DEVICE_DEFINITION_H__
#define __RSE_EXPANSION_DEVICE_DEFINITION_H__

#include "rse_expansion_device_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/* UART PL011 driver structures */
#ifdef UART0_PL011_S
#include "uart_pl011_drv.h"
extern struct uart_pl011_dev_t UART0_PL011_DEV_S;
#endif

#if (defined(SPI_STRATAFLASHJ3_S) && defined(CFI_S))
#include "spi_strataflashj3_flash_lib.h"
extern struct cfi_strataflashj3_dev_t SPI_STRATAFLASHJ3_DEV;
#endif

#ifdef __cplusplus
}
#endif

#endif  /* __RSE_EXPANSION_DEVICE_DEFINITION_H__ */
