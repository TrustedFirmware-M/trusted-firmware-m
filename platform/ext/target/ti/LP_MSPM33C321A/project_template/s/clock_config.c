/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file clock_config.c
 * \brief Clock configuration stub for LP_MSPM33C321A secure side.
 *
 * MSPM33C321A exits reset with the internal SYSOSC (32 MHz) as MCLK / BUSCLK.
 * No additional clock configuration is needed for the default TF-M build.
 * Replace this stub with a SysConfig-generated implementation if a specific
 * clock frequency or source (e.g. PLL, HFXT) is required.
 */

#include "clock_config.h"

void BOARD_InitClock(void)
{
    /* Stub: default SYSOSC 32 MHz is sufficient for TF-M + UART 115200. */
}
