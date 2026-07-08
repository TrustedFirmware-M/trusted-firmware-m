/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file board.c
 * \brief Non-secure board initialisation stub for LP_MSPM33C321A.
 *
 * Hardware is fully configured by the TF-M secure image before it hands
 * control to the NS entry point.  The NS side therefore does not need to
 * re-configure clocks, UART, or pins.
 */

#include "board.h"

void BOARD_InitHardware(void)
{
    /* Stub: secure image has already initialised hardware. */
}
