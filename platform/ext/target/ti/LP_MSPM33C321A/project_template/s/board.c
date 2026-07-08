/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file board.c
 * \brief Secure-side board initialisation for LP_MSPM33C321A.
 *
 * BOARD_InitHardware() is called once from tfm_hal_platform_init() before
 * TF-M logging is enabled.  It configures clocks and pins only.
 * UART bring-up is handled by Driver_USART0 via stdio_init().
 */

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"


void BOARD_InitHardware(void)
{
    /* Clock and pin initialisation only.
     * UART bring-up is owned by Driver_USART0 (Driver_USART.c) and is
     * performed via stdio_init() -> Initialize() + PowerControl(FULL). */
    BOARD_InitClock();
    BOARD_InitPins();
}
