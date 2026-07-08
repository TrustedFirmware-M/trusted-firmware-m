/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file pin_mux.c
 * \brief Pin-mux stub for LP_MSPM33C321A secure side.
 *
 * UART0 TX (PA10) and RX (PA11) are configured inside BOARD_InitHardware().
 * Additional pins (e.g. SWO, LEDs) can be added here.
 */

#include "pin_mux.h"

void BOARD_InitPins(void)
{
    /* Stub: UART0 pin-mux is handled in BOARD_InitHardware(). */
}
