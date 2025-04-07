/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
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
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM55.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */

#include "tfm_hal_device_header.h"
#include "config_tfm.h"

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
#define DEFAULT_IRQ_HANDLER(handler_name)       \
    __NO_RETURN void __WEAK handler_name(void); \
    void handler_name(void)                     \
    {                                           \
        while (1)                               \
            ;                                   \
    }

/*
 * Platform should define Expansion interrupts and their handlers
 * using the PLATFORM_EXPANSION_INTERRUPT_LIST macro. For example:
 *
 * #define PLATFORM_EXPANSION_INTERRUPT_LIST \
 *    EXPANSION_INTERRUPT(99, Platform_Timer_IRQ_Handler) \
 *    EXPANSION_INTERRUPT(181, Platform_Mailbox_IRQ_Handler)
 *
 * These handlers with their IRQ numbers will then be placed in the
 * vector table
 */
#ifndef PLATFORM_EXPANSION_INTERRUPT_LIST
#define PLATFORM_EXPANSION_INTERRUPT_LIST
#endif

#define GET_EXPANSION_IRQ_HANDLER_NAME_ARRAY_INITIALISER(interrupt_number, handler_name) \
    [interrupt_number + 16] = handler_name,

#define GET_EXPANSION_IRQ_HANDLER_DECLARATION(interrupt_number, handler_name) \
    __NO_RETURN extern void handler_name(void);

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
DEFAULT_IRQ_HANDLER(PPU_Combined_Handler)
DEFAULT_IRQ_HANDLER(NPU0_Handler)
DEFAULT_IRQ_HANDLER(NPU1_Handler)
DEFAULT_IRQ_HANDLER(NPU2_Handler)
DEFAULT_IRQ_HANDLER(NPU3_Handler)
DEFAULT_IRQ_HANDLER(KMU_Handler)
DEFAULT_IRQ_HANDLER(DMA_Combined_S_Handler)
DEFAULT_IRQ_HANDLER(DMA_Combined_NS_Handler)
DEFAULT_IRQ_HANDLER(DMA_Security_Violation_Handler)
DEFAULT_IRQ_HANDLER(TIMER3_AON_Handler)
DEFAULT_IRQ_HANDLER(CPU0_CTI_0_Handler)
DEFAULT_IRQ_HANDLER(CPU0_CTI_1_Handler)

DEFAULT_IRQ_HANDLER(SAM_Critical_Sec_Fault_S_Handler)
DEFAULT_IRQ_HANDLER(SAM_Sec_Fault_S_Handler)
DEFAULT_IRQ_HANDLER(GPIO_Combined_S_Handler)
DEFAULT_IRQ_HANDLER(SDC_Handler)
DEFAULT_IRQ_HANDLER(FPU_Handler)
DEFAULT_IRQ_HANDLER(SRAM_TRAM_ECC_Err_S_Handler)
DEFAULT_IRQ_HANDLER(SIC_S_Handler)
DEFAULT_IRQ_HANDLER(ATU_S_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU0_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU0_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU1_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU1_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU2_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU2_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU3_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU3_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU4_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU4_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU5_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU5_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU6_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU6_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU7_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU7_Receiver_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU8_Sender_Handler)
DEFAULT_IRQ_HANDLER(CMU_MHU8_Receiver_Handler)
DEFAULT_IRQ_HANDLER(Crypto_Engine_S_Handler)
DEFAULT_IRQ_HANDLER(SoC_System_Timer0_AON_Handler)
DEFAULT_IRQ_HANDLER(SoC_System_Timer1_AON_Handler)
DEFAULT_IRQ_HANDLER(SRAM_ECC_Partial_Write_S_Handler)
DEFAULT_IRQ_HANDLER(Integrity_Checker_Handler)

#undef EXPANSION_INTERRUPT
#define EXPANSION_INTERRUPT GET_EXPANSION_IRQ_HANDLER_DECLARATION
PLATFORM_EXPANSION_INTERRUPT_LIST

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];

const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
    (VECTOR_TABLE_Type)(&__INITIAL_SP), /*     Initial Stack Pointer */
    Reset_Handler,                     /*      Reset Handler */
    NMI_Handler,                       /* -14: NMI Handler */
    HardFault_Handler,                 /* -13: Hard Fault Handler */
    MemManage_Handler,                 /* -12: MPU Fault Handler */
    BusFault_Handler,                  /* -11: Bus Fault Handler */
    UsageFault_Handler,                /* -10: Usage Fault Handler */
    SecureFault_Handler,               /*  -9: Secure Fault Handler */
    0,                                 /*      Reserved */
    0,                                 /*      Reserved */
    0,                                 /*      Reserved */
    SVC_Handler,                       /*  -5: SVCall Handler */
    DebugMon_Handler,                  /*  -4: Debug Monitor Handler */
    0,                                 /*      Reserved */
    PendSV_Handler,                    /*  -2: PendSV Handler */
    SysTick_Handler,                   /*  -1: SysTick Handler */

    NONSEC_WATCHDOG_RESET_REQ_Handler, /*   0: Non-Secure Watchdog Reset Request Handler */
    NONSEC_WATCHDOG_Handler,           /*   1: Non-Secure Watchdog Handler */
    SLOWCLK_Timer_Handler,             /*   2: SLOWCLK Timer Handler */
    TFM_TIMER0_IRQ_Handler,            /*   3: TIMER 0 Handler */
    TIMER1_Handler,                    /*   4: TIMER 1 Handler */
    TIMER2_Handler,                    /*   5: TIMER 2 Handler */
    0,                                 /*   6: Reserved */
    0,                                 /*   7: Reserved */
    0,                                 /*   8: Reserved */
    MPC_Handler,                       /*   9: MPC Combined (Secure) Handler */
    PPC_Handler,                       /*  10: PPC Combined (Secure) Handler */
    MSC_Handler,                       /*  11: MSC Combined (Secure) Handler */
    BRIDGE_ERROR_Handler,              /*  12: Bridge Error (Secure) Handler */
    0,                                 /*  13: Reserved */
    PPU_Combined_Handler,              /*  14: PPU Combined (Secure) Handler */
    0,                                 /*  15: Reserved */
    NPU0_Handler,                      /*  16: NPU0 Handler */
    NPU1_Handler,                      /*  17: NPU1 Handler */
    NPU2_Handler,                      /*  18: NPU2 Handler */
    NPU3_Handler,                      /*  19: NPU3 Handler */
    KMU_Handler,                       /*  20: KMU (Secure) Handler */
    0,                                 /*  21: Reserved */
    0,                                 /*  22: Reserved */
    0,                                 /*  23: Reserved */
    DMA_Combined_S_Handler,            /*  24: DMA350 Combined (Secure) Handler */
    DMA_Combined_NS_Handler,           /*  25: DMA350 Combined (Non-Secure) Handler */
    DMA_Security_Violation_Handler,    /*  26: DMA350 Security Violation Handler */
    TIMER3_AON_Handler,                /*  27: TIMER 3 AON Handler */
    CPU0_CTI_0_Handler,                /*  28: CPU0 CTI IRQ 0 Handler */
    CPU0_CTI_1_Handler,                /*  29: CPU0 CTI IRQ 1 Handler */
    0,                                 /*  30: Reserved */
    0,                                 /*  31: Reserved */

    /* External interrupts */
    SAM_Critical_Sec_Fault_S_Handler,  /*  32: SAM Critical Security Fault (Secure) Handler */
    SAM_Sec_Fault_S_Handler,           /*  33: SAM Security Fault (Secure) Handler */
    GPIO_Combined_S_Handler,           /*  34: GPIO Combined (Secure) Handler */
    SDC_Handler,                       /*  35: Secure Debug Channel Handler */
    FPU_Handler,                       /*  36: FPU Exception Handler */
    SRAM_TRAM_ECC_Err_S_Handler,       /*  37: SRAM or TRAM Corrected ECC Error (Secure) Handler */
    SIC_S_Handler,                     /*  38: Secure I-Cache (Secure) Handler */
    ATU_S_Handler,                     /*  39: ATU (Secure) Handler */
    CMU_MHU0_Sender_Handler,           /*  40: CMU MHU 0 Sender Handler */
    CMU_MHU0_Receiver_Handler,         /*  41: CMU MHU 0 Receiver Handler */
    CMU_MHU1_Sender_Handler,           /*  42: CMU MHU 1 Sender Handler */
    CMU_MHU1_Receiver_Handler,         /*  43: CMU MHU 1 Receiver Handler */
    CMU_MHU2_Sender_Handler,           /*  44: CMU MHU 2 Sender Handler */
    CMU_MHU2_Receiver_Handler,         /*  45: CMU MHU 2 Receiver Handler */
    CMU_MHU3_Sender_Handler,           /*  46: CMU MHU 3 Sender Handler */
    CMU_MHU3_Receiver_Handler,         /*  47: CMU MHU 3 Receiver Handler */
    CMU_MHU4_Sender_Handler,           /*  48: CMU MHU 4 Sender Handler */
    CMU_MHU4_Receiver_Handler,         /*  49: CMU MHU 4 Receiver Handler */
    CMU_MHU5_Sender_Handler,           /*  50: CMU MHU 5 Sender Handler */
    CMU_MHU5_Receiver_Handler,         /*  51: CMU MHU 5 Receiver Handler */
    CMU_MHU6_Sender_Handler,           /*  52: CMU MHU 6 Sender Handler */
    CMU_MHU6_Receiver_Handler,         /*  53: CMU MHU 6 Receiver Handler */
    CMU_MHU7_Sender_Handler,           /*  54: CMU MHU 7 Sender Handler */
    CMU_MHU7_Receiver_Handler,         /*  55: CMU MHU 7 Receiver Handler */
    CMU_MHU8_Sender_Handler,           /*  56: CMU MHU 8 Sender Handler */
    CMU_MHU8_Receiver_Handler,         /*  57: CMU MHU 8 Receiver Handler */
    Crypto_Engine_S_Handler,           /*  58: Crypto Engine (Secure) Handler */
    SoC_System_Timer0_AON_Handler,     /*  59: SoC System Timer 0 AON Handler */
    SoC_System_Timer1_AON_Handler,     /*  60: SoC System Timer 1 AON Handler */
    SRAM_ECC_Partial_Write_S_Handler,  /*  61: SRAM ECC Detected Partial Write (Secure) Handler */
    Integrity_Checker_Handler,         /*  62: Integrity Checker Handler */
    0,                                 /*  63: Reserved */
    0,                                 /*  64: Reserved */
    0,                                 /*  65: Reserved */
    0,                                 /*  66: Reserved */
    0,                                 /*  67: Reserved */
    0,                                 /*  68: Reserved */
    0,                                 /*  69: Reserved */
    0,                                 /*  70: Reserved */
    0,                                 /*  71: Reserved */
    0,                                 /*  72: Reserved */
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
#undef EXPANSION_INTERRUPT
#define EXPANSION_INTERRUPT GET_EXPANSION_IRQ_HANDLER_NAME_ARRAY_INITIALISER
    PLATFORM_EXPANSION_INTERRUPT_LIST
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
