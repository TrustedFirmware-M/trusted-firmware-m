/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file pin_mux.h
 * \brief Pin-mux stub for LP_MSPM33C321A non-secure side.
 */

#ifndef __PIN_MUX_NS_H__
#define __PIN_MUX_NS_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialise pin multiplexing (NS stub — no-op).
 *
 * Pins are already configured by the TF-M secure image.
 */
void BOARD_InitPins(void);

#ifdef __cplusplus
}
#endif

#endif /* __PIN_MUX_NS_H__ */
