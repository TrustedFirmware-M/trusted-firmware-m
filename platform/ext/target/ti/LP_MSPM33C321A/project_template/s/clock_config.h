/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file clock_config.h
 * \brief Clock configuration declarations for LP_MSPM33C321A secure side.
 *
 * On MSPM33C321A, clocks are configured either by the SysConfig tool or
 * manually via driverlib DL_SYSCTL_* APIs.  This stub provides an empty
 * BOARD_InitClock() that is a no-op; replace with a SysConfig-generated
 * implementation when specific clock settings are required.
 */

#ifndef __CLOCK_CONFIG_H__
#define __CLOCK_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialise system clocks.
 *
 * This is a minimal stub. By default MSPM33C321A runs from the internal
 * SYSOSC at 32 MHz after reset.  Replace with your SysConfig-generated
 * clock initialisation if you need a different frequency.
 */
void BOARD_InitClock(void);

#ifdef __cplusplus
}
#endif

#endif /* __CLOCK_CONFIG_H__ */
