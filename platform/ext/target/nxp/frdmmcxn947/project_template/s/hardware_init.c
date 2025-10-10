/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*${header:start}*/
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "cmsis.h"
/*${header:end}*/

/*${variable:start}*/

/*${variable:end}*/
/*${function:start}*/
void BOARD_InitHardware(void)
{
    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);	


    // /* Step 1: Set PLL clock divider */
    // CLOCK_AttachClk(kPLL0_to_PLLCLKDIV);               // Attach PLL0 to PLLCLKDIV
    // CLOCK_SetClkDiv(kCLOCK_DivPllClk, 1U);              // Set PLL divider to 1
    
    // /* Step 2: Attach PLL divided clock to FlexCOMM4 */
    // CLOCK_AttachClk(kPLL_DIV_to_FLEXCOMM4);            // Use PLL_DIV as source for FlexCOMM4
    
    // /* Step 3: Set FlexCOMM4 clock divider */
    // CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1U);         // Set divider for FlexCOMM4


    BOARD_InitPins();
    BOARD_InitBootClocks();
    
    /* Removing Debug Console Init */
    // BOARD_InitDebugConsole();
}

void SystemInit(void)
{
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));    /* set CP10, CP11 Full Access in Secure mode */
    SCB_NS->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10, CP11 Full Access in Non-secure mode */
#endif                                                    /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    SCB->CPACR |= ((3UL << 0 * 2) | (3UL << 1 * 2));    /* set CP0, CP1 Full Access in Secure mode (enable PowerQuad) */
    SCB_NS->CPACR |= ((3UL << 0 * 2) | (3UL << 1 * 2)); /* set CP0, CP1 Full Access in Normal mode (enable PowerQuad) */

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
}

/*${function:end}*/
