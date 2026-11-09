/*
** ###################################################################
**     Processor:           KW43B43ZC7MFT
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    Rev. 1 Draft F, 2025-10-18
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b260316
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file KW43B43ZC7
 * @version 1.0
 * @date 2020-05-12
 * @brief Device specific configuration file for KW43B43ZC7 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_device_registers.h"



/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInit (void) {
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
  SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Secure mode */
  #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  SCB_NS->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Non-secure mode */
  #endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

#if (DISABLE_WDOG)
  while ((WDOG_0->CS & WDOG_CS_RCS_MASK) != WDOG_CS_RCS_MASK)
  {
  }

  if ((WDOG_0->CS & WDOG_CS_CMD32EN_MASK) != 0U)
  {
      WDOG_0->CNT = 0xD928C520U;
  }
  else
  {
      WDOG_0->CNT = 0xC520U;
      WDOG_0->CNT = 0xD928U;
  }

  while ((WDOG_0->CS & WDOG_CS_ULK_MASK) != WDOG_CS_ULK_MASK)
  {
  }

  WDOG_0->TOVAL = 0xFFFF;
  WDOG_0->CS = (uint32_t) ((WDOG_0->CS) & ~WDOG_CS_EN_MASK) | WDOG_CS_UPDATE_MASK;

  while ((WDOG_0->CS & WDOG_CS_RCS_MASK) != WDOG_CS_RCS_MASK)
  {
  }
#endif /* (DISABLE_WDOG) */

#if defined(__MCUXPRESSO)
    extern void(*const g_pfnVectors[]) (void);
    SCB->VTOR = (uint32_t) &g_pfnVectors;
#endif

  /* Request Core#1 to stall when accessing busy flash */
  SYSCON->AUTHENTICATE = SYSCON_UNLOCK_CODE;
  __DMB();
  SYSCON->FMC1_CTRL = SYSCON_FMC1_CTRL_PFLEXSTALL(1);
  /* Lock again */
  __DMB();
  SYSCON->AUTHENTICATE = 0UL;

  SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {

}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInitHook (void) {
  /* Void implementation of the weak function. */
}
