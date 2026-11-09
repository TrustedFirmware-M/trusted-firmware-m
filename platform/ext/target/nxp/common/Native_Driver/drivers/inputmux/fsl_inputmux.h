/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021, 2023-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_INPUTMUX_H_
#define FSL_INPUTMUX_H_

#include "fsl_inputmux_connections.h"
#include "fsl_common.h"

/*!
 * @addtogroup inputmux_driver
 * @{
 */

/*! @file */
/*! @file fsl_inputmux_connections.h */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Group interrupt driver version for SDK */
#define FSL_INPUTMUX_DRIVER_VERSION (MAKE_VERSION(2, 0, 11))
/*! @} */

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Initialize INPUTMUX peripheral.
 *
 * This function enables the INPUTMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 */
void INPUTMUX_Init(void *base);

/*!
 * @brief Attaches a signal
 *
 * This function writes a source signal selection into an INPUTMUX multiplexer register.
 * The target register address is computed as:
 * @code
 *   target address = base + pmux_id + index * 4
 * @endcode
 *
 * Each @ref inputmux_connection_t enum value encodes two fields via @c PMUX_SHIFT (20):
 * @code
 *   31          20 19                    0
 *   +------------+------------------------+
 *   |  pmux_id   |       output_id        |
 *   +------------+------------------------+
 *        |                   |
 *   group base          signal value
 *   addr offset         to write
 * @endcode
 *
 * When N consecutive registers all accept the same set of source signals (same @c pmux_id),
 * only one set of enum values is defined for the whole group; @p index (0 ~ N-1) selects
 * which register to write, avoiding duplicate enum entries.
 *
 * Example: SCT0 has 8 input mux registers sharing @c SCT0_INMUX0 = 0x000 as the group base:
 * @code
 *   base
 *    |
 *    +--[+0x000] SCT0_INMUX0  <-- index=0
 *    +--[+0x004] SCT0_INMUX1  <-- index=1
 *    +--[+0x008] SCT0_INMUX2  <-- index=2
 *    :   ...
 *    +--[+0x014] SCT0_INMUX5  <-- index=5  (write target for the call below)
 *    :   ...
 *    +--[+0x01C] SCT0_INMUX7  <-- index=7
 * @endcode
 * To connect CMP0 output to SCT0 input 5:
 * @code
 *   INPUTMUX_AttachSignal(INPUTMUX, 5, kINPUTMUX_Cmp0OutToSct0);
 *   // write address = base + 0x000 + 5*4 = base + 0x014  (SCT0_INMUX5)
 * @endcode
 *
 * For peripherals with only a single register per function (e.g. @c FREQMEAS_REF_REG = 0x180,
 * @c FREQMEAS_TAR_REG = 0x184), each register has its own unique @c pmux_id and @p index must be 0.
 * The two registers are distinguished by their different @c pmux_id values, not by @p index:
 * @code
 *   base
 *    |
 *    +--[+0x180] FREQMEAS_REF_REG  (pmux_id=0x180, index=0)
 *    +--[+0x184] FREQMEAS_TAR_REG  (pmux_id=0x184, index=0)
 * @endcode
 *
 * @param base       Base address of the INPUTMUX peripheral.
 * @param index      Zero-based index of the destination register within its group.
 *                   Each increment advances the address by 4 bytes. Use 0 for single-register groups.
 * @param connection Encodes the group base offset (bits [31:PMUX_SHIFT]) and the source
 *                   signal value (bits [PMUX_SHIFT-1:0]).
 */
void INPUTMUX_AttachSignal(void *base, uint16_t index, inputmux_connection_t connection);

#if defined(FSL_FEATURE_INPUTMUX_HAS_SIGNAL_ENA) && FSL_FEATURE_INPUTMUX_HAS_SIGNAL_ENA
/*!
 * @brief Enable/disable a signal
 *
 * This function gates the INPUTMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 * @param signal Enable signal register id and bit offset.
 * @param enable Selects enable or disable.
 */
void INPUTMUX_EnableSignal(void *base, inputmux_signal_t signal, bool enable);
#endif

/*!
 * @brief Deinitialize INPUTMUX peripheral.
 *
 * This function disables the INPUTMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 */
void INPUTMUX_Deinit(void *base);

#ifdef __cplusplus
}
#endif

/*! @} */

#endif /* FSL_INPUTMUX_H_ */
