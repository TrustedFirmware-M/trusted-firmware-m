/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "Driver_USART_PL011.h"
#include "cmsis_driver_config.h"
#include "RTE_Device.h"

#if (defined(RTE_USART0) && (RTE_USART0 == 1))
ARM_DRIVER_USART_PL011(UART0_DEV, Driver_USART0);
#endif /* RTE_USART0 */
