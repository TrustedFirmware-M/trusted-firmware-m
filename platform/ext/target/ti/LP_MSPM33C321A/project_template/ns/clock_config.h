/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file clock_config.h
 * \brief Clock configuration stub for LP_MSPM33C321A non-secure side.
 */

#ifndef __CLOCK_CONFIG_NS_H__
#define __CLOCK_CONFIG_NS_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialise system clocks (NS stub — no-op).
 *
 * Clocks are already configured by the TF-M secure image.
 */
void BOARD_InitClock(void);

#ifdef __cplusplus
}
#endif

#endif /* __CLOCK_CONFIG_NS_H__ */
