/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file board.h
 * \brief Non-secure board support definitions for LP_MSPM33C321A.
 *
 * The NS side does not perform full hardware initialisation — that is done
 * by the secure image before jumping to the NS entry point.  BOARD_InitHardware()
 * on the NS side is therefore a stub.
 */

#ifndef __BOARD_NS_H__
#define __BOARD_NS_H__

#ifdef __cplusplus
extern "C" {
#endif

/** Debug UART baud rate (informational; actual config done by secure side) */
#define BOARD_DEBUG_UART_BAUDRATE   115200U

/**
 * \brief Non-secure board hardware init stub.
 *
 * The secure image has already configured clocks, UART, and pins before
 * transferring control to the NS entry point, so this function is empty.
 */
void BOARD_InitHardware(void);

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_NS_H__ */
