/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "board.h"
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Initialize debug console.
 */
void BOARD_InitDebugConsole(void)
{
    uint32_t uartClkSrcFreq = 0U;

    CLOCK_SetIpSrc(kCLOCK_Lpuart1, kCLOCK_IpSrcFro192M);
    CLOCK_EnableClock(kCLOCK_Fro_hf_div);
    CLOCK_SetIpSrcDiv(kCLOCK_Lpuart1, 1U);

    uartClkSrcFreq = CLOCK_GetIpFreq(kCLOCK_Lpuart1);

    DbgConsole_Init(BOARD_DEBUG_UART_INSTANCE, BOARD_DEBUG_UART_BAUDRATE, BOARD_DEBUG_UART_TYPE, uartClkSrcFreq);
}
