/*
 * Copyright (c) 2009-2020 Arm Limited. All rights reserved.
 * Copyright (c) 2024 STMicroelectronics. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is derivative of CMSIS V5.6.0 startup_ARMv81MML.c
 * Git SHA: b5f0603d6a584d1724d952fd8b0737458b90d62b
 */

#include "stm32u3xx.h"

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler Function Prototype
 *----------------------------------------------------------------------------*/
typedef void( *pFunc )( void );

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

#if defined(__ICCARM__)
  extern __noreturn void __PROGRAM_START(void);
#else
  extern void __PROGRAM_START(void) __NO_RETURN;
#endif

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
#if defined(__ICCARM__)
  __noreturn void Reset_Handler(void);
#else
  void Reset_Handler(void) __NO_RETURN;
#endif

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
#define DEFAULT_IRQ_HANDLER(handler_name)  \
void handler_name(void); \
__WEAK void handler_name(void) { \
    while(1); \
}

/* Exceptions */
DEFAULT_IRQ_HANDLER(NMI_Handler)
DEFAULT_IRQ_HANDLER(HardFault_Handler)
DEFAULT_IRQ_HANDLER(MemManage_Handler)
DEFAULT_IRQ_HANDLER(BusFault_Handler)
DEFAULT_IRQ_HANDLER(UsageFault_Handler)
DEFAULT_IRQ_HANDLER(SecureFault_Handler)
DEFAULT_IRQ_HANDLER(SVC_Handler)
DEFAULT_IRQ_HANDLER(DebugMon_Handler)
DEFAULT_IRQ_HANDLER(PendSV_Handler)
DEFAULT_IRQ_HANDLER(SysTick_Handler)
DEFAULT_IRQ_HANDLER(WWDG_IRQHandler)
DEFAULT_IRQ_HANDLER(PVD_PVM_IRQHandler)
DEFAULT_IRQ_HANDLER(RTC_IRQHandler)
DEFAULT_IRQ_HANDLER(RTC_S_IRQHandler)
DEFAULT_IRQ_HANDLER(TAMP_IRQHandler)
DEFAULT_IRQ_HANDLER(RAMCFG_IRQHandler)
DEFAULT_IRQ_HANDLER(FLASH_IRQHandler)
DEFAULT_IRQ_HANDLER(FLASH_S_IRQHandler)
DEFAULT_IRQ_HANDLER(GTZC_IRQHandler)
DEFAULT_IRQ_HANDLER(RCC_IRQHandler)
DEFAULT_IRQ_HANDLER(RCC_S_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI0_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI3_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI4_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI5_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI6_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI7_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI8_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI9_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI10_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI11_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI12_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI13_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI14_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI15_IRQHandler)
DEFAULT_IRQ_HANDLER(IWDG_IRQHandler)
DEFAULT_IRQ_HANDLER(SAES_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel0_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel1_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel2_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel3_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel4_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel5_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel6_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel7_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC1_IRQHandler)
DEFAULT_IRQ_HANDLER(DAC1_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN1_IT0_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN1_IT1_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_BRK_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_UP_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_TRG_COM_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_CC_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM2_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM3_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM4_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM6_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM7_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM12_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C1_EV_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C1_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C1_EV_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C1_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C2_EV_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C2_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI1_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI2_IRQHandler)
DEFAULT_IRQ_HANDLER(USART1_IRQHandler)
DEFAULT_IRQ_HANDLER(USART2_IRQHandler)
DEFAULT_IRQ_HANDLER(USART3_IRQHandler)
DEFAULT_IRQ_HANDLER(UART4_IRQHandler)
DEFAULT_IRQ_HANDLER(UART5_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM2_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM15_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM16_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM17_IRQHandler)
DEFAULT_IRQ_HANDLER(COMP_IRQHandler)
DEFAULT_IRQ_HANDLER(USB_IRQHandler)
DEFAULT_IRQ_HANDLER(CRS_IRQHandler)
DEFAULT_IRQ_HANDLER(OCTOSPI1_IRQHandler)
DEFAULT_IRQ_HANDLER(HSP1_IRQHandler)
DEFAULT_IRQ_HANDLER(SDMMC1_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel8_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel9_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel10_IRQHandler)
DEFAULT_IRQ_HANDLER(GPDMA1_Channel11_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C3_EV_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C3_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI1_IRQHandler)
DEFAULT_IRQ_HANDLER(TSC_IRQHandler)
DEFAULT_IRQ_HANDLER(AES_IRQHandler)
DEFAULT_IRQ_HANDLER(RNG_IRQHandler)
DEFAULT_IRQ_HANDLER(FPU_IRQHandler)
DEFAULT_IRQ_HANDLER(HASH_IRQHandler)
DEFAULT_IRQ_HANDLER(PKA_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM3_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI3_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C2_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C2_EV_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_BRK_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_UP_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_TRG_COM_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_CC_IRQHandler)
DEFAULT_IRQ_HANDLER(ICACHE_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM4_IRQHandler)
DEFAULT_IRQ_HANDLER(ADF1_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC2_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN2_IT0_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN2_IT1_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C4_EV_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C4_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI4_IRQHandler)
DEFAULT_IRQ_HANDLER(PWR_IRQHandler)
DEFAULT_IRQ_HANDLER(PWR_S_IRQHandler)

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const pFunc __VECTOR_TABLE[];
       const pFunc __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (pFunc)(&__INITIAL_SP),           /*      Initial Stack Pointer */
  Reset_Handler,                    /*      Reset Handler */
  NMI_Handler,                      /* -14: NMI Handler */
  HardFault_Handler,                /* -13: Hard Fault Handler*/
  MemManage_Handler,                /* -12: MPU Fault Handler*/
  BusFault_Handler,                 /* -11: Bus Fault Handler */
  UsageFault_Handler ,              /* -10: Usage Fault Handler */
  SecureFault_Handler,              /*  -9: Secure Fault Handler */
  0,                                /*      Reserved */
  0,                                /*      Reserved */
  0,                                /*      Reserved */
  SVC_Handler,                      /*  -5: SVCall Handler */
  DebugMon_Handler,                 /*  -4: Debug Monitor Handler */
  0,                                /*      Reserved */
  PendSV_Handler,                   /*  -2: PendSV Handler */
  SysTick_Handler,                  /*  -1: SysTick Handler */
  WWDG_IRQHandler,                  /*   0: Window WatchDog */
  PVD_PVM_IRQHandler,               /*   1: PVD/AVD through EXTI Line detection Interrupt */
  RTC_IRQHandler,                   /*   2: RTC non-secure interrupt */
  RTC_S_IRQHandler,                 /*   3: RTC secure interrupt */
  TAMP_IRQHandler,                  /*   4: Tamper non-secure interrupt  */
  RAMCFG_IRQHandler,                /*   5: RAMCFG global */
  FLASH_IRQHandler,                 /*   6: FLASH non-secure global interrupt */
  FLASH_S_IRQHandler,               /*   7: FLASH secure global interrupt */
  GTZC_IRQHandler,                  /*   8: Global TrustZone Controller interrupt */
  RCC_IRQHandler,                   /*   9: RCC non-secure global interrupts */
  RCC_S_IRQHandler,                 /*  10: RCC secure global interrupts */
  EXTI0_IRQHandler,                 /*  11: EXTI Line0 */
  EXTI1_IRQHandler,                 /*  12: EXTI Line1 */
  EXTI2_IRQHandler,                 /*  13: EXTI Line2 */
  EXTI3_IRQHandler,                 /*  14: EXTI Line3 */
  EXTI4_IRQHandler,                 /*  15: EXTI Line4 */
  EXTI5_IRQHandler,                 /*  16: EXTI Line5 */
  EXTI6_IRQHandler,                 /*  17: EXTI Line6 */
  EXTI7_IRQHandler,                 /*  18: EXTI Line7 */
  EXTI8_IRQHandler,                 /*  19: EXTI Line8 */
  EXTI9_IRQHandler,                 /*  20: EXTI Line9 */
  EXTI10_IRQHandler,                /*  21: EXTI Line10 */
  EXTI11_IRQHandler,                /*  22: EXTI Line11 */
  EXTI12_IRQHandler,                /*  23: EXTI Line12 */
  EXTI13_IRQHandler,                /*  24: EXTI Line13 */
  EXTI14_IRQHandler,                /*  25: EXTI Line14 */
  EXTI15_IRQHandler,                /*  26: EXTI Line15 */
  IWDG_IRQHandler,                  /*  27: IWDG global interrupt */
  SAES_IRQHandler,                  /*  28:Secure AES global interrupt */
  GPDMA1_Channel0_IRQHandler,       /*  29: GPDMA1 Channel 0 global interrupt */
  GPDMA1_Channel1_IRQHandler,       /*  30: GPDMA1 Channel 1 global interrupt */
  GPDMA1_Channel2_IRQHandler,       /*  31: GPDMA1 Channel 2 global interrupt */
  GPDMA1_Channel3_IRQHandler,       /*  32: GPDMA1 Channel 3 global interrupt */
  GPDMA1_Channel4_IRQHandler,       /*  33: GPDMA1 Channel 4 global interrupt */
  GPDMA1_Channel5_IRQHandler,       /*  34: GPDMA1 Channel 5 global interrupt */
  GPDMA1_Channel6_IRQHandler,       /*  35: GPDMA1 Channel 6 global interrupt */
  GPDMA1_Channel7_IRQHandler,       /*  36: GPDMA1 Channel 7 global interrupt */
  ADC1_IRQHandler,                  /*  37: ADC1 global interrupt  */
  DAC1_IRQHandler,                  /*  38: DAC1 global interrupt */
  FDCAN1_IT0_IRQHandler,            /*  39: FDCAN1 Interrupt 0 */
  FDCAN1_IT1_IRQHandler,            /*  40: FDCAN1 Interrupt 1 */
  TIM1_BRK_IRQHandler,              /*  41: TIM1 Break */
  TIM1_UP_IRQHandler,               /*  42: TIM1 Update */
  TIM1_TRG_COM_IRQHandler,          /*  43: TIM1 Trigger and Commutation */
  TIM1_CC_IRQHandler,               /*  44: TIM1 Capture Compare */
  TIM2_IRQHandler,                  /*  45: TIM2 */
  TIM3_IRQHandler,                  /*  46: TIM3 */
  TIM4_IRQHandler,                  /*  47: TIM4 */
  0,                                /*  48: Reserved */
  TIM6_IRQHandler,                  /*  49: TIM6 */
  TIM7_IRQHandler,                  /*  50: TIM7 */
  TIM12_IRQHandler,                 /*  51: TIM12 */
  0,                                /*  Reserved */
  I3C1_EV_IRQHandler,               /*  53: I3C1 Event */
  I3C1_ER_IRQHandler,               /*  54: I3C1 Error */
  I2C1_EV_IRQHandler,               /*  55: I2C1 Event */
  I2C1_ER_IRQHandler,               /*  56: I2C1 Error */
  I2C2_EV_IRQHandler,               /*  57: I2C2 Event */
  I2C2_ER_IRQHandler,               /*  58: I2C2 Error */
  SPI1_IRQHandler,                  /*  59: SPI1 */
  SPI2_IRQHandler,                  /*  60: SPI2 */
  USART1_IRQHandler,                /*  61: USART1 */
  USART2_IRQHandler,                /*  62: USART2 */
  USART3_IRQHandler,                /*  63: USART3 */
  UART4_IRQHandler,                 /*  64: UART4 */
  UART5_IRQHandler,                 /*  65: UART5 */
  LPUART1_IRQHandler,               /*  66: LP UART1 */
  LPTIM1_IRQHandler,                /*  67: LP TIM1 */
  LPTIM2_IRQHandler,                /*  68: LP TIM2 */
  TIM15_IRQHandler,                 /*  69: TIM15 */
  TIM16_IRQHandler,                 /*  70: TIM16 */
  TIM17_IRQHandler,                 /*  71: TIM17 */
  COMP_IRQHandler,                  /*  72: COMP1&2 */
  USB_IRQHandler,                   /*  73, USB global interrupt */
  CRS_IRQHandler,                   /*  74: CRS */
  0,                                /*  75: Reserved */
  OCTOSPI1_IRQHandler,              /*  76: OctoSPI1 global interrupt */
  HSP1_IRQHandler,                  /*  77: HSP1 */
  SDMMC1_IRQHandler,                /*  78: SDMMC1 global interrupt */
  0,                                /*  79: Reserved */
  GPDMA1_Channel8_IRQHandler,       /*  80: GPDMA1 Channel 8 global interrupt */
  GPDMA1_Channel9_IRQHandler,       /*  81: GPDMA1 Channel 9 global interrupt */
  GPDMA1_Channel10_IRQHandler,      /*  82: GPDMA1 Channel 10 global interrupt */
  GPDMA1_Channel11_IRQHandler,      /*  83: GPDMA1 Channel 11 global interrupt */
  0,                                /*  84: Reserved */
  0,                                /*  85: Reserved */
  0,                                /*  86: Reserved */
  0,                                /*  87: Reserved */
  I2C3_EV_IRQHandler,               /*  88: I2C3 event */
  I2C3_ER_IRQHandler,               /*  89: I2C3 error */
  SAI1_IRQHandler,                  /*  90: Serial Audio Interface 1 global interrupt */
  0,                                /*  91: Reserved */
  TSC_IRQHandler,                   /*  92: Touch Sense Controller global interrupt */
  AES_IRQHandler,                   /*  93: AES global interrupt */
  RNG_IRQHandler,                   /*  94: RNG global interrupt */
  FPU_IRQHandler,                   /*  95: FPU */
  HASH_IRQHandler,                  /*  96: HASH global interrupt */
  PKA_IRQHandler,                   /*  97: PKA global interrupt */
  LPTIM3_IRQHandler,                /*  98: LP TIM3 */
  SPI3_IRQHandler,                  /*  99: SPI3 */
  I3C2_ER_IRQHandler,               /* 100: I3C2 error */
  I3C2_EV_IRQHandler,               /* 101: I3C2 event */
  TIM8_BRK_IRQHandler,              /* 102: TIM8 Break */
  TIM8_UP_IRQHandler,               /* 103: TIM8 Update */
  TIM8_TRG_COM_IRQHandler,          /* 104: TIM8 Trigger and Commutation */
  TIM8_CC_IRQHandler,               /* 105: TIM8 Capture Compare */
  0,                                /* 106: Reserved */
  ICACHE_IRQHandler,                /* 107: Instruction cache global interrupt*/
  0,                                /* 108: Reserved */
  0,                                /* 109: Reserved */
  LPTIM4_IRQHandler,                /* 110: LPTIM4 global interrupt */
  0,                                /* 111: Data cache global interrupt */
  ADF1_IRQHandler,                  /* 112: ADF interrupt */
  ADC2_IRQHandler,                  /* 113: ADC2 (12bits) global interrupt */
  FDCAN2_IT0_IRQHandler,            /* 114: FDCAN2 Interrupt 0 */
  FDCAN2_IT1_IRQHandler,            /* 115: FDCAN2 Interrupt 1 */
  I2C4_EV_IRQHandler,               /* 116: I2C4 Event */
  I2C4_ER_IRQHandler,               /* 117: I2C4 Error */
  0,                                /* 118: Reserved */
  SPI4_IRQHandler,                  /* 119: SPI4 */
  0,                                /* 120: Reserved */
  0,                                /* 121: Reserved */
  0,                                /* 122: Reserved */
  PWR_IRQHandler,                   /* 123: PWR non-secure interrupt */
  PWR_S_IRQHandler,                 /* 124: PWR secure interrupt */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/

void Reset_Handler(void)
{
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  __IO uint32_t tmp;

#endif
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  /* disable IRQ is removed */
  /*__disable_irq();*/
  /* Tamp IRQ prio is set to highest , and IRQ is enabled */
  NVIC_SetPriority(TAMP_IRQn, 0);
  NVIC_EnableIRQ(TAMP_IRQn);
#endif
  __set_PSP((uint32_t)(&__INITIAL_SP));

  __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
  __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  SCB->VTOR = (uint32_t) &__VECTOR_TABLE[0];

  /* Program AIRCR with PRIS = 1 */
  tmp = SCB->AIRCR;
  SCB->AIRCR = (~tmp & SCB_AIRCR_VECTKEYSTAT_Msk) |
               SCB_AIRCR_PRIS_Msk |
               (tmp & ~SCB_AIRCR_VECTKEY_Msk);

  /* Lock Secure Vector Table */
  /* Enable SYSCFG interface clock */
  RCC->APB3ENR |= RCC_APB3ENR_SYSCFGEN;
  /* Delay after an RCC peripheral clock enabling */
  tmp = RCC->APB3ENR;
  (void)tmp;
  SYSCFG->CSLCKR |= SYSCFG_CSLCKR_LOCKSVTAIRCR;
#endif

  SystemInit();                             /* CMSIS System Initialization */
  __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}

