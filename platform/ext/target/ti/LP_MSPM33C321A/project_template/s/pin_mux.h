/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file pin_mux.h
 * \brief Pin-mux declarations for LP_MSPM33C321A secure side.
 *
 * On MSPM33C321A, pin multiplexing is configured via the IOMUX peripheral.
 * BOARD_InitHardware() configures UART0 TX/RX pins directly.  This stub
 * provides a hook for any additional pin configuration needed at init time.
 */

#ifndef __PIN_MUX_H__
#define __PIN_MUX_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Configure board pin multiplexing.
 *
 * This is a minimal stub.  UART0 TX/RX pins are configured inside
 * BOARD_InitHardware().  Add additional IOMUX calls here as needed.
 */
void BOARD_InitPins(void);

#ifdef __cplusplus
}
#endif

#endif /* __PIN_MUX_H__ */
