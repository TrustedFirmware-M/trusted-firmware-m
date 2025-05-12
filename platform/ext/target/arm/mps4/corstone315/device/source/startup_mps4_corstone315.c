/*
 * Copyright (c) 2024 Arm Limited. All rights reserved.
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
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM85.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */

#include "tfm_hal_device_header.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler (void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
#define DEFAULT_IRQ_HANDLER(handler_name)  \
__NO_RETURN void __WEAK handler_name(void); \
void handler_name(void) { \
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

DEFAULT_IRQ_HANDLER(NONSEC_WATCHDOG_RESET_REQ_Handler)
DEFAULT_IRQ_HANDLER(NONSEC_WATCHDOG_Handler)
DEFAULT_IRQ_HANDLER(SLOWCLK_Timer_Handler)
DEFAULT_IRQ_HANDLER(TFM_TIMER0_IRQ_Handler)
DEFAULT_IRQ_HANDLER(TIMER1_Handler)
DEFAULT_IRQ_HANDLER(TIMER2_Handler)
DEFAULT_IRQ_HANDLER(MPC_Handler)
DEFAULT_IRQ_HANDLER(PPC_Handler)
DEFAULT_IRQ_HANDLER(MSC_Handler)
DEFAULT_IRQ_HANDLER(BRIDGE_ERROR_Handler)
DEFAULT_IRQ_HANDLER(COMBINED_PPU_Handler)
DEFAULT_IRQ_HANDLER(SDC_Handler)
DEFAULT_IRQ_HANDLER(KMU_Handler)
DEFAULT_IRQ_HANDLER(DMA_SEC_Combined_Handler)
DEFAULT_IRQ_HANDLER(DMA_NONSEC_Combined_Handler)
DEFAULT_IRQ_HANDLER(DMA_SECURITY_VIOLATION_Handler)
DEFAULT_IRQ_HANDLER(TIMER3_AON_Handler)
DEFAULT_IRQ_HANDLER(CPU0_CTI_0_Handler)
DEFAULT_IRQ_HANDLER(CPU0_CTI_1_Handler)
DEFAULT_IRQ_HANDLER(SAM_Critical_Severity_Fault_Handler)
DEFAULT_IRQ_HANDLER(SAM_Severity_Fault_Handler)

DEFAULT_IRQ_HANDLER(System_Timestamp_Counter_Handler)
DEFAULT_IRQ_HANDLER(UARTRX0_Handler)
DEFAULT_IRQ_HANDLER(UARTTX0_Handler)
DEFAULT_IRQ_HANDLER(UARTRX1_Handler)
DEFAULT_IRQ_HANDLER(UARTTX1_Handler)
DEFAULT_IRQ_HANDLER(UARTRX2_Handler)
DEFAULT_IRQ_HANDLER(UARTTX2_Handler)
DEFAULT_IRQ_HANDLER(UARTRX3_Handler)
DEFAULT_IRQ_HANDLER(UARTTX3_Handler)
DEFAULT_IRQ_HANDLER(UARTRX4_Handler)
DEFAULT_IRQ_HANDLER(UARTTX4_Handler)
DEFAULT_IRQ_HANDLER(UART0_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART1_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART2_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART3_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART4_Combined_Handler)
DEFAULT_IRQ_HANDLER(UARTOVF_Handler)
DEFAULT_IRQ_HANDLER(ETHERNET_Handler)
DEFAULT_IRQ_HANDLER(I2S_Handler)
DEFAULT_IRQ_HANDLER(DMA_Channel_0_Handler)
DEFAULT_IRQ_HANDLER(DMA_Channel_1_Handler)
DEFAULT_IRQ_HANDLER(NPU0_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_Combined_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_Combined_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_Combined_Handler)
DEFAULT_IRQ_HANDLER(GPIO3_Combined_Handler)
DEFAULT_IRQ_HANDLER(UARTRX5_Handler)
DEFAULT_IRQ_HANDLER(UARTTX5_Handler)
DEFAULT_IRQ_HANDLER(RTC_Handler)
DEFAULT_IRQ_HANDLER(ISP_C55_Handler)
DEFAULT_IRQ_HANDLER(HDLCD_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI0_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI1_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI2_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI3_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI4_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI5_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI6_Handler)
DEFAULT_IRQ_HANDLER(ARM_VSI7_Handler)

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
       const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),            /*      Initial Stack Pointer */
  Reset_Handler,                       /*      Reset Handler */
  NMI_Handler,                         /* -14: NMI Handler */
  HardFault_Handler,                   /* -13: Hard Fault Handler */
  MemManage_Handler,                   /* -12: MPU Fault Handler */
  BusFault_Handler,                    /* -11: Bus Fault Handler */
  UsageFault_Handler,                  /* -10: Usage Fault Handler */
  SecureFault_Handler,                 /*  -9: Secure Fault Handler */
  0,                                   /*      Reserved */
  0,                                   /*      Reserved */
  0,                                   /*      Reserved */
  SVC_Handler,                         /*  -5: SVCall Handler */
  DebugMon_Handler,                    /*  -4: Debug Monitor Handler */
  0,                                   /*      Reserved */
  PendSV_Handler,                      /*  -2: PendSV Handler */
  SysTick_Handler,                     /*  -1: SysTick Handler */

  NONSEC_WATCHDOG_RESET_REQ_Handler,   /*   0: Non-Secure Watchdog Reset Request Handler */
  NONSEC_WATCHDOG_Handler,             /*   1: Non-Secure Watchdog Handler */
  SLOWCLK_Timer_Handler,               /*   2: SLOWCLK Timer Handler */
  TFM_TIMER0_IRQ_Handler,              /*   3: TIMER 0 Handler */
  TIMER1_Handler,                      /*   4: TIMER 1 Handler */
  TIMER2_Handler,                      /*   5: TIMER 2 Handler */
  0,                                   /*   6: Reserved */
  0,                                   /*   7: Reserved */
  0,                                   /*   8: Reserved */
  MPC_Handler,                         /*   9: MPC Combined (Secure) Handler */
  PPC_Handler,                         /*  10: PPC Combined (Secure) Handler */
  MSC_Handler,                         /*  11: MSC Combined (Secure) Handler */
  BRIDGE_ERROR_Handler,                /*  12: Bridge Error (Secure) Handler */
  0,                                   /*  13: Reserved */
  COMBINED_PPU_Handler,                /*  14: Combined PPU Handler */
  SDC_Handler,                         /*  15: Secure Debug Channel Handler */
  NPU0_Handler,                        /*  16: NPU0 Handler */
  0,                                   /*  17: Reserved */
  0,                                   /*  18: Reserved */
  0,                                   /*  19: Reserved */
  KMU_Handler,                         /*  20: KMU Handler */
  0,                                   /*  21: Reserved */
  0,                                   /*  22: Reserved */
  0,                                   /*  23: Reserved */
  DMA_SEC_Combined_Handler,            /*  24: DMA Secure Combined Handler */
  DMA_NONSEC_Combined_Handler,         /*  25: DMA Non-Secure Combined Handler */
  DMA_SECURITY_VIOLATION_Handler,      /*  26: DMA Security Violation Handler */
  TIMER3_AON_Handler,                  /*  27: TIMER 3 AON Handler */
  CPU0_CTI_0_Handler,                  /*  28: CPU0 CTI IRQ 0 Handler */
  CPU0_CTI_1_Handler,                  /*  29: CPU0 CTI IRQ 1 Handler */
  SAM_Critical_Severity_Fault_Handler, /*  30: SAM Critical Severity Fault Handler */
  SAM_Severity_Fault_Handler,          /*  31: SAM Severity Fault Handler */

  /* External interrupts */
  0,                                 /*  32: Reserved */
  UARTRX0_Handler,                   /*  33: UART 0 RX Handler */
  UARTTX0_Handler,                   /*  34: UART 0 TX Handler */
  UARTRX1_Handler,                   /*  35: UART 1 RX Handler */
  UARTTX1_Handler,                   /*  36: UART 1 TX Handler */
  UARTRX2_Handler,                   /*  37: UART 2 RX Handler */
  UARTTX2_Handler,                   /*  38: UART 2 TX Handler */
  UARTRX3_Handler,                   /*  39: UART 3 RX Handler */
  UARTTX3_Handler,                   /*  40: UART 3 TX Handler */
  UARTRX4_Handler,                   /*  41: UART 4 RX Handler */
  UARTTX4_Handler,                   /*  42: UART 4 TX Handler */
  UART0_Combined_Handler,            /*  43: UART 0 Combined Handler */
  UART1_Combined_Handler,            /*  44: UART 1 Combined Handler */
  UART2_Combined_Handler,            /*  45: UART 2 Combined Handler */
  UART3_Combined_Handler,            /*  46: UART 3 Combined Handler */
  UART4_Combined_Handler,            /*  47: UART 4 Combined Handler */
  UARTOVF_Handler,                   /*  48: UART 0, 1, 2, 3, 4 & 5 Overflow Handler */
  ETHERNET_Handler,                  /*  49: Ethernet Handler */
  I2S_Handler,                       /*  50: Audio I2S Handler */
  0,                                 /*  51: Reserved */
  0,                                 /*  52: Reserved */
  0,                                 /*  53: Reserved */
  0,                                 /*  54: Reserved */
  0,                                 /*  55: Reserved */
  0,                                 /*  56: Reserved */
  DMA_Channel_0_Handler,             /*  57: DMA (DMA350) Channel 0 Handler */
  DMA_Channel_1_Handler,             /*  58: DMA (DMA350) Channel 1 Handler */
  0,                                 /*  59: Reserved */
  0,                                 /*  60: Reserved */
  0,                                 /*  61: Reserved */
  0,                                 /*  62: Reserved */
  0,                                 /*  63: Reserved */
  0,                                 /*  64: Reserved */
  0,                                 /*  65: Reserved */
  0,                                 /*  66: Reserved */
  0,                                 /*  67: Reserved */
  0,                                 /*  68: Reserved */
  GPIO0_Combined_Handler,            /*  69: GPIO 0 Combined Handler */
  GPIO1_Combined_Handler,            /*  70: GPIO 1 Combined Handler */
  GPIO2_Combined_Handler,            /*  71: GPIO 2 Combined Handler */
  GPIO3_Combined_Handler,            /*  72: GPIO 3 Combined Handler */
  0,                                 /*  73: Reserved */
  0,                                 /*  74: Reserved */
  0,                                 /*  75: Reserved */
  0,                                 /*  76: Reserved */
  0,                                 /*  77: Reserved */
  0,                                 /*  78: Reserved */
  0,                                 /*  79: Reserved */
  0,                                 /*  80: Reserved */
  0,                                 /*  81: Reserved */
  0,                                 /*  82: Reserved */
  0,                                 /*  83: Reserved */
  0,                                 /*  84: Reserved */
  0,                                 /*  85: Reserved */
  0,                                 /*  86: Reserved */
  0,                                 /*  87: Reserved */
  0,                                 /*  88: Reserved */
  0,                                 /*  89: Reserved */
  0,                                 /*  90: Reserved */
  0,                                 /*  91: Reserved */
  0,                                 /*  92: Reserved */
  0,                                 /*  93: Reserved */
  0,                                 /*  94: Reserved */
  0,                                 /*  95: Reserved */
  0,                                 /*  96: Reserved */
  0,                                 /*  97: Reserved */
  0,                                 /*  98: Reserved */
  0,                                 /*  99: Reserved */
  0,                                 /*  100: Reserved */
  0,                                 /*  101: Reserved */
  0,                                 /*  102: Reserved */
  0,                                 /*  103: Reserved */
  0,                                 /*  104: Reserved */
  0,                                 /*  105: Reserved */
  0,                                 /*  106: Reserved */
  0,                                 /*  107: Reserved */
  0,                                 /*  108: Reserved */
  0,                                 /*  109: Reserved */
  0,                                 /*  110: Reserved */
  0,                                 /*  111: Reserved */
  0,                                 /*  112: Reserved */
  0,                                 /*  113: Reserved */
  0,                                 /*  114: Reserved */
  0,                                 /*  115: Reserved */
  0,                                 /*  116: Reserved */
  0,                                 /*  117: Reserved */
  0,                                 /*  118: Reserved */
  0,                                 /*  119: Reserved */
  0,                                 /*  120: Reserved */
  0,                                 /*  121: Reserved */
  0,                                 /*  122: Reserved */
  0,                                 /*  123: Reserved */
  0,                                 /*  124: Reserved */
  UARTRX5_Handler,                   /*  125: UART 5 RX Interrupt */
  UARTTX5_Handler,                   /*  126: UART 5 TX Interrupt */
  0,                                 /*  127: Reserved */
  RTC_Handler,                       /*  128: UART 5 combined Interrupt */
  0,                                 /*  129: Reserved */
  0,                                 /*  130: Reserved */
  0,                                 /*  131: Reserved */
  ISP_C55_Handler,                   /*  132: ISP C55 Handler */
  HDLCD_Handler,                     /*  133: HDLCD Handler */
  0,                                 /*  134: Reserved */
  0,                                 /*  135: Reserved */
  0,                                 /*  136: Reserved */
  0,                                 /*  137: Reserved */
  0,                                 /*  138: Reserved */
  0,                                 /*  139: Reserved */
  0,                                 /*  140: Reserved */
  0,                                 /*  141: Reserved */
  0,                                 /*  142: Reserved */
  0,                                 /*  143: Reserved */
  0,                                 /*  144: Reserved */
  0,                                 /*  145: Reserved */
  0,                                 /*  146: Reserved */
  0,                                 /*  147: Reserved */
  0,                                 /*  148: Reserved */
  0,                                 /*  149: Reserved */
  0,                                 /*  150: Reserved */
  0,                                 /*  151: Reserved */
  0,                                 /*  152: Reserved */
  0,                                 /*  153: Reserved */
  0,                                 /*  154: Reserved */
  0,                                 /*  155: Reserved */
  0,                                 /*  156: Reserved */
  0,                                 /*  157: Reserved */
  0,                                 /*  158: Reserved */
  0,                                 /*  159: Reserved */
  0,                                 /*  160: Reserved */
  0,                                 /*  161: Reserved */
  0,                                 /*  162: Reserved */
  0,                                 /*  163: Reserved */
  0,                                 /*  164: Reserved */
  0,                                 /*  165: Reserved */
  0,                                 /*  166: Reserved */
  0,                                 /*  167: Reserved */
  0,                                 /*  168: Reserved */
  0,                                 /*  169: Reserved */
  0,                                 /*  170: Reserved */
  0,                                 /*  171: Reserved */
  0,                                 /*  172: Reserved */
  0,                                 /*  173: Reserved */
  0,                                 /*  174: Reserved */
  0,                                 /*  175: Reserved */
  0,                                 /*  176: Reserved */
  0,                                 /*  177: Reserved */
  0,                                 /*  178: Reserved */
  0,                                 /*  179: Reserved */
  0,                                 /*  180: Reserved */
  0,                                 /*  181: Reserved */
  0,                                 /*  182: Reserved */
  0,                                 /*  183: Reserved */
  0,                                 /*  184: Reserved */
  0,                                 /*  185: Reserved */
  0,                                 /*  186: Reserved */
  0,                                 /*  187: Reserved */
  0,                                 /*  188: Reserved */
  0,                                 /*  189: Reserved */
  0,                                 /*  190: Reserved */
  0,                                 /*  191: Reserved */
  0,                                 /*  192: Reserved */
  0,                                 /*  193: Reserved */
  0,                                 /*  194: Reserved */
  0,                                 /*  195: Reserved */
  0,                                 /*  196: Reserved */
  0,                                 /*  197: Reserved */
  0,                                 /*  198: Reserved */
  0,                                 /*  199: Reserved */
  0,                                 /*  200: Reserved */
  0,                                 /*  201: Reserved */
  0,                                 /*  202: Reserved */
  0,                                 /*  203: Reserved */
  0,                                 /*  204: Reserved */
  0,                                 /*  205: Reserved */
  0,                                 /*  206: Reserved */
  0,                                 /*  207: Reserved */
  0,                                 /*  208: Reserved */
  0,                                 /*  209: Reserved */
  0,                                 /*  210: Reserved */
  0,                                 /*  211: Reserved */
  0,                                 /*  212: Reserved */
  0,                                 /*  213: Reserved */
  0,                                 /*  214: Reserved */
  0,                                 /*  215: Reserved */
  0,                                 /*  216: Reserved */
  0,                                 /*  217: Reserved */
  0,                                 /*  218: Reserved */
  0,                                 /*  219: Reserved */
  0,                                 /*  220: Reserved */
  0,                                 /*  221: Reserved */
  0,                                 /*  222: Reserved */
  0,                                 /*  223: Reserved */
  ARM_VSI0_Handler,                  /*  224: VSI 0 Handler */
  ARM_VSI1_Handler,                  /*  225: VSI 1 Handler */
  ARM_VSI2_Handler,                  /*  226: VSI 2 Handler */
  ARM_VSI3_Handler,                  /*  227: VSI 3 Handler */
  ARM_VSI4_Handler,                  /*  228: VSI 4 Handler */
  ARM_VSI5_Handler,                  /*  229: VSI 5 Handler */
  ARM_VSI6_Handler,                  /*  230: VSI 6 Handler */
  ARM_VSI7_Handler,                  /*  231: VSI 7 Handler */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();                             /* CMSIS System Initialization */
    __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}
