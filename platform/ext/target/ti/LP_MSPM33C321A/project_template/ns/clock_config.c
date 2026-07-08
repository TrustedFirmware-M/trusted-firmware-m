/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file clock_config.c
 * \brief Clock configuration stub for LP_MSPM33C321A non-secure side.
 *
 * Clocks are configured by the TF-M secure image before the NS entry point
 * is called; nothing to do here.
 */

#include <stdint.h>
#include "clock_config.h"

/* MSPM33C321A default SYSOSC frequency (32 MHz). Clocks are configured
 * by the TF-M secure image; this value must match S-side configuration. */
uint32_t SystemCoreClock = 32000000U;

/* Called by startup before C runtime init. Clocks are already configured
 * by TF-M; update SystemCoreClock to match. */
void SystemInit(void)
{
    SystemCoreClock = 32000000U;
}

void BOARD_InitClock(void)
{
    /* Stub: clocks configured by TF-M secure image. */
}
