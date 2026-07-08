/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file board.h
 * \brief Secure-side board support definitions for LP_MSPM33C321A.
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <ti/devices/msp/msp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialise board hardware.
 *
 * Called early in tfm_hal_platform_init(). Configures clocks and pins only.
 * UART bring-up is handled by Driver_USART0 via stdio_init().
 */
void BOARD_InitHardware(void);

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H__ */
