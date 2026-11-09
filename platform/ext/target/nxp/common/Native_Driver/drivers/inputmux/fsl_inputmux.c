/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021, 2023-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_inputmux.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.inputmux"
#endif

#if defined(INPUTMUX_RSTS)
#define INPUTMUX_RESETS_ARRAY INPUTMUX_RSTS
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if !(defined(FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE) && FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE)
#if !(defined(INPUTMUX_CLOCKS))
#define INPUTMUX_CLOCKS    \
    {                      \
        kCLOCK_InputMux    \
    }
#endif
#endif
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#if defined(INPUTMUX_RESETS_ARRAY) || defined(INPUTMUX_CLOCKS)
/*!
 * @brief Get instance number for INPUTMUX module.
 *
 * @param base INPUTMUX peripheral base address
 */
static uint32_t INPUTMUX_GetInstance(void *base);
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if defined(INPUTMUX_RESETS_ARRAY) || defined(INPUTMUX_CLOCKS)
/*! @brief Pointers to INPUTMUX bases for each instance. */
static void *const s_inputmuxBases[] = INPUTMUX_BASE_PTRS;
#endif

#if defined(INPUTMUX_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_inputmuxResets[] = INPUTMUX_RESETS_ARRAY;
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if !(defined(FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE) && FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE)
/*! @brief Array to map INPUTMUX instance number to clock name. */
static const clock_ip_name_t s_inputmuxClockName[] = INPUTMUX_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
#if defined(INPUTMUX_RESETS_ARRAY) || defined(INPUTMUX_CLOCKS)
static uint32_t INPUTMUX_GetInstance(void *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_inputmuxBases); instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_inputmuxBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_inputmuxBases));

    return instance;
}
#endif

/*!
 * @brief Initialize INPUTMUX peripheral.
 *
 * This function enables the INPUTMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 */
void INPUTMUX_Init(void *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if defined(FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE) && FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE
#if (defined(FSL_FEATURE_SOC_SCT_COUNT) && (FSL_FEATURE_SOC_SCT_COUNT > 0))
    CLOCK_EnableClock(kCLOCK_Sct);
#endif /* FSL_FEATURE_SOC_SCT_COUNT */
    CLOCK_EnableClock(kCLOCK_Dma);
#else
    CLOCK_EnableClock(s_inputmuxClockName[INPUTMUX_GetInstance(base)]);
#endif /* FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(INPUTMUX_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_inputmuxResets[INPUTMUX_GetInstance(base)]);
#endif
}

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
void INPUTMUX_AttachSignal(void *base, uint16_t index, inputmux_connection_t connection)
{
    uint32_t pmux_id;
    uint32_t output_id;

    /* extract pmux to be used */
    pmux_id = ((uint32_t)(connection)) >> PMUX_SHIFT;
    /*  extract function number */
    output_id = ((uint32_t)(connection)) & ((1UL << PMUX_SHIFT) - 1U);
    /* programm signal */
    *(volatile uint32_t *)(((uint32_t)base) + pmux_id + (index * 4U)) = output_id;
}

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
void INPUTMUX_EnableSignal(void *base, inputmux_signal_t signal, bool enable)
{
    uint32_t ena_id;
    uint32_t ena_id_mask;
    uint32_t bit_offset;

#if defined(FSL_FEATURE_INPUTMUX_HAS_CHANNEL_MUX) && FSL_FEATURE_INPUTMUX_HAS_CHANNEL_MUX
    uint32_t chmux_offset;
    uint32_t chmux_value;

    /* Only enable need to update channel mux */
    if (enable && ((((uint32_t)signal) & (1UL << CHMUX_AVL_SHIFT)) != 0U))
    {
        chmux_offset = (((uint32_t)signal) >> CHMUX_OFF_SHIFT) & ((1UL << (CHMUX_AVL_SHIFT - CHMUX_OFF_SHIFT)) - 1UL);
        chmux_value  = (((uint32_t)signal) >> CHMUX_VAL_SHIFT) & ((1UL << (CHMUX_OFF_SHIFT - CHMUX_VAL_SHIFT)) - 1UL);
        *(volatile uint32_t *)(((uint32_t)base) + chmux_offset) = chmux_value;
    }
    ena_id_mask = (1UL << (CHMUX_VAL_SHIFT - ENA_SHIFT)) - 1U;
#else
    ena_id_mask = (1UL << (32U - ENA_SHIFT)) - 1U;
#endif
    /* extract enable register to be used */
    ena_id = (((uint32_t)signal) >> ENA_SHIFT) & ena_id_mask;
    /* extract enable bit offset */
    bit_offset = ((uint32_t)signal) & ((1UL << ENA_SHIFT) - 1U);
    /* set signal */
    if (enable)
    {
        *(volatile uint32_t *)(((uint32_t)base) + ena_id) |= (1UL << bit_offset);
    }
    else
    {
        *(volatile uint32_t *)(((uint32_t)base) + ena_id) &= ~(1UL << bit_offset);
    }
}
#endif

/*!
 * @brief Deinitialize INPUTMUX peripheral.
 *
 * This function disables the INPUTMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 */
void INPUTMUX_Deinit(void *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if defined(FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE) && FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE
#if (defined(FSL_FEATURE_SOC_SCT_COUNT) && (FSL_FEATURE_SOC_SCT_COUNT > 0))
    CLOCK_DisableClock(kCLOCK_Sct);
#endif /* FSL_FEATURE_SOC_SCT_COUNT */
    CLOCK_DisableClock(kCLOCK_Dma);
#else
    CLOCK_DisableClock(s_inputmuxClockName[INPUTMUX_GetInstance(base)]);
#endif /* FSL_FEATURE_INPUTMUX_HAS_NO_INPUTMUX_CLOCK_SOURCE */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
