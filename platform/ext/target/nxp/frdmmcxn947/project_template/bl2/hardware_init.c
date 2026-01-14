/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*${header:start}*/
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "cmsis.h"

#include "fsl_lpuart.h"
#include "fsl_lpflexcomm.h"

/*${header:end}*/

/*${variable:start}*/

/*${variable:end}*/
/*${function:start}*/
void BOARD_InitHardware(void)
{

    /* 1) Initialize system clocks first (sets up FRO/PLL baseline) */
    BOARD_InitBootClocks();   // Do NOT attach UART clocks before this call

    /* 2) Pin mux for LPUART4 TX/RX (ensure BOARD_InitPins maps the right pins to FC4) */
    BOARD_InitDEBUG_UARTPins();

    /* 3) Choose ONE clock source and attach it to LP-FLEXCOMM4 */
    /* Option A: FRO 12 MHz — simple and good enough for 115200 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1U);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM4);

    /* 4) Release peripheral reset on FC4 AFTER clock is attached */
    RESET_PeripheralReset(kFC4_RST_SHIFT_RSTn);

    /* 5) Ungate and deassert reset for LP‑FLEXCOMM4 */
    CLOCK_EnableClock(kCLOCK_LPFlexComm4);
    /* Reset driver usage */
    RESET_PeripheralReset(kFC4_RST_SHIFT_RSTn);

    /*LPUART_Init() is done in driver_lpuart*/

}

void SystemInit(void)
{

#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));    /* set CP10, CP11 Full Access in Secure mode */
#endif                                                    /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    SCB->CPACR |= ((3UL << 0 * 2) | (3UL << 1 * 2));    /* set CP0, CP1 Full Access in Secure mode (enable PowerQuad) */

    SCB->NSACR |= ((3UL << 0) | (3UL << 10));           /* enable CP0, CP1, CP10, CP11 Non-secure Access */

    extern void *__VECTOR_TABLE[];
    SCB->VTOR = (uint32_t) & (__VECTOR_TABLE[0]);

    SYSCON->TRACECLKDIV = 0;

    /******************* TBD -> Recheck these settings based on Secure world TFM */

    /* enable the flash cache LPCAC */
    SYSCON->LPCAC_CTRL &= ~SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK;

    /* Disable aGDET trigger the CHIP_RESET */
    ITRC0->OUT_SEL[4][0] = (ITRC0->OUT_SEL[4][0] & ~ITRC_OUT_SEL_IN9_SELn_MASK) | (ITRC_OUT_SEL_IN9_SELn(0x2));
    ITRC0->OUT_SEL[4][1] = (ITRC0->OUT_SEL[4][1] & ~ITRC_OUT_SEL_IN9_SELn_MASK) | (ITRC_OUT_SEL_IN9_SELn(0x2));
    /* Disable aGDET interrupt and reset */
    SPC0->ACTIVE_CFG |= SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_MASK;
    SPC0->GLITCH_DETECT_SC &= ~SPC_GLITCH_DETECT_SC_LOCK_MASK;
    SPC0->GLITCH_DETECT_SC = 0x3C;
    SPC0->GLITCH_DETECT_SC |= SPC_GLITCH_DETECT_SC_LOCK_MASK;

    /* Disable dGDET trigger the CHIP_RESET */
    ITRC0->OUT_SEL[4][0] = (ITRC0->OUT_SEL[4][0] & ~ ITRC_OUT_SEL_IN0_SELn_MASK) | (ITRC_OUT_SEL_IN0_SELn(0x2));
    ITRC0->OUT_SEL[4][1] = (ITRC0->OUT_SEL[4][1] & ~ ITRC_OUT_SEL_IN0_SELn_MASK) | (ITRC_OUT_SEL_IN0_SELn(0x2));
    GDET0->GDET_ENABLE1 = 0;
    GDET1->GDET_ENABLE1 = 0;

    /* Board specific HW init*/
    BOARD_InitHardware();
}

/*${function:end}*/
