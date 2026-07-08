/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file pin_mux.c
 * \brief Pin-mux stub for LP_MSPM33C321A non-secure side.
 *
 * Pin multiplexing is configured by the TF-M secure image before control
 * is transferred to the NS entry point.
 */

#include "pin_mux.h"

void BOARD_InitPins(void)
{
    /* Stub: pin-mux configured by TF-M secure image. */
}
