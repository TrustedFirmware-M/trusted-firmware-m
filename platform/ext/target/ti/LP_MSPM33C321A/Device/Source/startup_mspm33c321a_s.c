/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM33.c
 */


/*
 * Secure-world startup for MSPM33C321A TF-M secure image.
 *
 * NS linker scripts use the default CMSIS style naming conventions, while the
 * secure and bl2 linker scripts remain untouched (region.h compatibility).
 * To be compatible with the untouched files (which use ARMCLANG naming style),
 * we override __INITIAL_SP and __STACK_LIMIT labels via cmsis_override.h.
 */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#include "cmsis_override.h"
#endif

#include "tfm_hal_device_header.h"
/* hw_eam.h is included transitively via mspm33c321x.h (tfm_hal_device_header.h) */

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

typedef void(*VECTOR_TABLE_Type)(void);

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler macro
 *----------------------------------------------------------------------------*/
#define DEFAULT_IRQ_HANDLER(handler_name)  \
__NO_RETURN void __WEAK handler_name(void); \
void handler_name(void) { \
    while(1); \
}

/* ARM Cortex-M33 core exceptions */
/*
 * NMI_Handler — handles non-maskable interrupts.
 */
void NMI_Handler(void)
{
    while (1);
}
DEFAULT_IRQ_HANDLER(HardFault_Handler)
DEFAULT_IRQ_HANDLER(MemManage_Handler)
DEFAULT_IRQ_HANDLER(BusFault_Handler)
DEFAULT_IRQ_HANDLER(UsageFault_Handler)
DEFAULT_IRQ_HANDLER(SecureFault_Handler)
DEFAULT_IRQ_HANDLER(SVC_Handler)
DEFAULT_IRQ_HANDLER(DebugMon_Handler)
DEFAULT_IRQ_HANDLER(PendSV_Handler)
DEFAULT_IRQ_HANDLER(SysTick_Handler)

/* MSPM33C321A device-specific interrupt handlers */
DEFAULT_IRQ_HANDLER(SYSCTL_IRQHandler)
DEFAULT_IRQ_HANDLER(DEBUGSS_IRQHandler)
DEFAULT_IRQ_HANDLER(FLASHCTL_IRQHandler)
DEFAULT_IRQ_HANDLER(WWDT0_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOA_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOB_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOC_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC0_SEQ0_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC0_SEQ1_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC0_SEQ2_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC0_SEQ3_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC0_DCOMP_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC1_SEQ0_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC1_SEQ1_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC1_SEQ2_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC1_SEQ3_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC1_DCOMP_IRQHandler)
DEFAULT_IRQ_HANDLER(CANFD0_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMA0_0_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMG4_0_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMG4_1_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMG8_0_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMG12_0_IRQHandler)
DEFAULT_IRQ_HANDLER(UC1_0_IRQHandler)
DEFAULT_IRQ_HANDLER(UC1_1_IRQHandler)
DEFAULT_IRQ_HANDLER(UC2_IRQHandler)
DEFAULT_IRQ_HANDLER(UC15_0_IRQHandler)
DEFAULT_IRQ_HANDLER(UC15_1_IRQHandler)
DEFAULT_IRQ_HANDLER(UC12_IRQHandler)
DEFAULT_IRQ_HANDLER(UC13_0_IRQHandler)
DEFAULT_IRQ_HANDLER(UC14_IRQHandler)
DEFAULT_IRQ_HANDLER(CANFD1_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMA0_1_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMG4_2_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMG4_3_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMG8_1_IRQHandler)
DEFAULT_IRQ_HANDLER(COMP0_IRQHandler)
DEFAULT_IRQ_HANDLER(COMP1_IRQHandler)
DEFAULT_IRQ_HANDLER(TRNG_IRQHandler)
DEFAULT_IRQ_HANDLER(AESADV_IRQHandler)
DEFAULT_IRQ_HANDLER(LFSS_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA0_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA1_IRQHandler)
DEFAULT_IRQ_HANDLER(I2S0_IRQHandler)
DEFAULT_IRQ_HANDLER(I2S1_IRQHandler)
DEFAULT_IRQ_HANDLER(QSPI_IRQHandler)
DEFAULT_IRQ_HANDLER(SHAW_IRQHandler)
DEFAULT_IRQ_HANDLER(PKA_IRQHandler)
DEFAULT_IRQ_HANDLER(UC13_1_IRQHandler)
DEFAULT_IRQ_HANDLER(UC13_2_IRQHandler)
DEFAULT_IRQ_HANDLER(UC13_3_IRQHandler)

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
       const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),  /* Initial Stack Pointer                */
  Reset_Handler,                       /* Reset Handler                        */
  NMI_Handler,                         /* NMI Handler                          */
  HardFault_Handler,                   /* Hard Fault Handler                   */
  MemManage_Handler,                   /* MPU Fault Handler                    */
  BusFault_Handler,                    /* Bus Fault Handler                    */
  UsageFault_Handler,                  /* Usage Fault Handler                  */
  SecureFault_Handler,                 /* Secure Fault Handler                 */
  0,                                   /* Reserved                             */
  0,                                   /* Reserved                             */
  0,                                   /* Reserved                             */
  SVC_Handler,                         /* SVCall Handler                       */
  DebugMon_Handler,                    /* Debug Monitor Handler                */
  0,                                   /* Reserved                             */
  PendSV_Handler,                      /* PendSV Handler                       */
  SysTick_Handler,                     /* SysTick Handler                      */

  /* MSPM33C321A device-specific external interrupts */
  SYSCTL_IRQHandler,                   /* IRQ0:  SYSCTL                        */
  DEBUGSS_IRQHandler,                  /* IRQ1:  DEBUGSS                       */
  FLASHCTL_IRQHandler,                 /* IRQ2:  FLASHCTL                      */
  WWDT0_IRQHandler,                    /* IRQ3:  WWDT0                         */
  0,                                   /* IRQ4:  Reserved                      */
  0,                                   /* IRQ5:  Reserved                      */
  GPIOA_IRQHandler,                    /* IRQ6:  GPIOA                         */
  GPIOB_IRQHandler,                    /* IRQ7:  GPIOB                         */
  GPIOC_IRQHandler,                    /* IRQ8:  GPIOC                         */
  ADC0_SEQ0_IRQHandler,                /* IRQ9:  ADC0 SEQ0                     */
  ADC0_SEQ1_IRQHandler,                /* IRQ10: ADC0 SEQ1                     */
  ADC0_SEQ2_IRQHandler,                /* IRQ11: ADC0 SEQ2                     */
  ADC0_SEQ3_IRQHandler,                /* IRQ12: ADC0 SEQ3                     */
  ADC0_DCOMP_IRQHandler,               /* IRQ13: ADC0 DCOMP                    */
  ADC1_SEQ0_IRQHandler,                /* IRQ14: ADC1 SEQ0                     */
  ADC1_SEQ1_IRQHandler,                /* IRQ15: ADC1 SEQ1                     */
  ADC1_SEQ2_IRQHandler,                /* IRQ16: ADC1 SEQ2                     */
  ADC1_SEQ3_IRQHandler,                /* IRQ17: ADC1 SEQ3                     */
  ADC1_DCOMP_IRQHandler,               /* IRQ18: ADC1 DCOMP                    */
  CANFD0_IRQHandler,                   /* IRQ19: CANFD0                        */
  TIMA0_0_IRQHandler,                  /* IRQ20: TIMA0_0                       */
  TIMG4_0_IRQHandler,                  /* IRQ21: TIMG4_0                       */
  TIMG4_1_IRQHandler,                  /* IRQ22: TIMG4_1                       */
  TIMG8_0_IRQHandler,                  /* IRQ23: TIMG8_0                       */
  TIMG12_0_IRQHandler,                 /* IRQ24: TIMG12_0                      */
  UC1_0_IRQHandler,                    /* IRQ25: UC1_0                         */
  UC1_1_IRQHandler,                    /* IRQ26: UC1_1                         */
  UC2_IRQHandler,                      /* IRQ27: UC2                           */
  UC15_0_IRQHandler,                   /* IRQ28: UC15_0                        */
  UC15_1_IRQHandler,                   /* IRQ29: UC15_1                        */
  UC12_IRQHandler,                     /* IRQ30: UC12                          */
  UC13_0_IRQHandler,                   /* IRQ31: UC13_0                        */
  UC14_IRQHandler,                     /* IRQ32: UC14                          */
  CANFD1_IRQHandler,                   /* IRQ33: CANFD1                        */
  TIMA0_1_IRQHandler,                  /* IRQ34: TIMA0_1                       */
  TIMG4_2_IRQHandler,                  /* IRQ35: TIMG4_2                       */
  TIMG4_3_IRQHandler,                  /* IRQ36: TIMG4_3                       */
  TIMG8_1_IRQHandler,                  /* IRQ37: TIMG8_1                       */
  COMP0_IRQHandler,                    /* IRQ38: COMP0                         */
  COMP1_IRQHandler,                    /* IRQ39: COMP1                         */
  TRNG_IRQHandler,                     /* IRQ40: TRNG                          */
  AESADV_IRQHandler,                   /* IRQ41: AESADV                        */
  LFSS_IRQHandler,                     /* IRQ42: LFSS                          */
  DMA0_IRQHandler,                     /* IRQ43: DMA0                          */
  DMA1_IRQHandler,                     /* IRQ44: DMA1                          */
  I2S0_IRQHandler,                     /* IRQ45: I2S0                          */
  I2S1_IRQHandler,                     /* IRQ46: I2S1                          */
  QSPI_IRQHandler,                     /* IRQ47: QSPI                          */
  SHAW_IRQHandler,                     /* IRQ48: SHAW                          */
  PKA_IRQHandler,                      /* IRQ49: PKA                           */
  UC13_1_IRQHandler,                   /* IRQ50: UC13_1                        */
  UC13_2_IRQHandler,                   /* IRQ51: UC13_2                        */
  UC13_3_IRQHandler,                   /* IRQ52: UC13_3                        */
};

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();          /* CMSIS System Initialization */
    __PROGRAM_START();     /* Enter PreMain (C library entry point) */
}
