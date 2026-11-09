/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
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
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM33.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */

/* NS linker scripts using the default CMSIS style naming conventions, while the
 * secure and bl2 linker scripts remain untouched (region.h compatibility).
 * To be compatible with the untouched files (which using ARMCLANG naming style),
 * we have to override __INITIAL_SP and __STACK_LIMIT labels. */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#include "cmsis_override.h"
#endif

#include "cmsis.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

typedef void(*VECTOR_TABLE_Type)(void);

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/

void default_handler (void);
void default_handler (void) {
    while(1);
}

#define DEFAULT_IRQ_HANDLER(handler_name)  \
void handler_name (void) __attribute__((weak, alias("default_handler")));

#define DEFAULT_DRIVER_IRQ_HANDLER(handler_name, driver_handler_name)  \
DEFAULT_IRQ_HANDLER(driver_handler_name) \
void __WEAK handler_name (void); \
void handler_name (void) { \
    driver_handler_name(); \
}

DEFAULT_IRQ_HANDLER(DefaultISR)


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

DEFAULT_DRIVER_IRQ_HANDLER(CTI_IRQHandler, CTI_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CMC0_IRQHandler, CMC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH0_IRQHandler, DMA0_CH0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH1_IRQHandler, DMA0_CH1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH2_IRQHandler, DMA0_CH2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH3_IRQHandler, DMA0_CH3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH4_IRQHandler, DMA0_CH4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH5_IRQHandler, DMA0_CH5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH6_IRQHandler, DMA0_CH6_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH7_IRQHandler, DMA0_CH7_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH8_IRQHandler, DMA0_CH8_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH9_IRQHandler, DMA0_CH9_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH10_IRQHandler, DMA0_CH10_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH11_IRQHandler, DMA0_CH11_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH12_IRQHandler, DMA0_CH12_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH13_IRQHandler, DMA0_CH13_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH14_IRQHandler, DMA0_CH14_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH15_IRQHandler, DMA0_CH15_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EWM0_IRQHandler, EWM0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(MCM0_IRQHandler, MCM0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(MSCM0_IRQHandler, MSCM0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SYSCON0_IRQHandler, SYSCON0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SECCON0_IRQHandler, SECCON0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SPC0_IRQHandler, SPC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WUU0_IRQHandler, WUU0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WDOG0_IRQHandler, WDOG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WDOG1_IRQHandler, WDOG1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CWDOG0_IRQHandler, CWDOG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CWDOG1_IRQHandler, CWDOG1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SCG0_IRQHandler, SCG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SFA0_IRQHandler, SFA0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FMU0_IRQHandler, FMU0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SFA1_IRQHandler, SFA1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DSB0_IRQHandler, DSB0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TRDC0_IRQHandler, TRDC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RTC_Alarm_IRQHandler, RTC_Alarm_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RTC_Seconds_IRQHandler, RTC_Seconds_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPTMR0_IRQHandler, LPTMR0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPTMR1_IRQHandler, LPTMR1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPIT0_IRQHandler, LPIT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TPM_0_IRQHandler, TPM_0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TPM_1_IRQHandler, TPM_1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TPM_2_IRQHandler, TPM_2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TPM_3_IRQHandler, TPM_3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TPM_4_IRQHandler, TPM_4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(MU1_IRQHandler, MU1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SYSCON0_ECC_IRQHandler, SYSCON0_ECC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPI2C0_IRQHandler, LPI2C0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPI2C1_IRQHandler, LPI2C1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI0_IRQHandler, LPSPI0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI1_IRQHandler, LPSPI1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI2_IRQHandler, LPSPI2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART0_IRQHandler, LPUART0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART1_IRQHandler, LPUART1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CAN0_IRQHandler, CAN0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RF_ZIGBEE_IRQHandler, RF_ZIGBEE_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RF_Generic_IRQHandler, RF_Generic_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RF_BRIC_IRQHandler, RF_BRIC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RF_LCL_IRQHandler, RF_LCL_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RF_WOR_IRQHandler, RF_WOR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RFMC_IRQHandler, RFMC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved77_IRQHandler, Reserved77_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved78_IRQHandler, Reserved78_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(COEX_INT_IRQHandler, COEX_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved80_IRQHandler, Reserved80_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOA_INT0_IRQHandler, GPIOA_INT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOA_INT1_IRQHandler, GPIOA_INT1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOB_INT0_IRQHandler, GPIOB_INT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOB_INT1_IRQHandler, GPIOB_INT1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOC_INT0_IRQHandler, GPIOC_INT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOC_INT1_IRQHandler, GPIOC_INT1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOD_INT0_IRQHandler, GPIOD_INT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIOD_INT1_IRQHandler, GPIOD_INT1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved89_IRQHandler, Reserved89_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved90_IRQHandler, Reserved90_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved91_IRQHandler, Reserved91_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved92_IRQHandler, Reserved92_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ADC0_IRQHandler, ADC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CMP0_IRQHandler, CMP0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE0_CMP_IRQHandler, FLEXPWM0_SUBMODULE0_CMP_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE0_CAP_IRQHandler, FLEXPWM0_SUBMODULE0_CAP_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE0_RELOAD_IRQHandler, FLEXPWM0_SUBMODULE0_RELOAD_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE1_CMP_IRQHandler, FLEXPWM0_SUBMODULE1_CMP_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE1_CAP_IRQHandler, FLEXPWM0_SUBMODULE1_CAP_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE1_RELOAD_IRQHandler, FLEXPWM0_SUBMODULE1_RELOAD_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE2_CMP_IRQHandler, FLEXPWM0_SUBMODULE2_CMP_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE2_CAP_IRQHandler, FLEXPWM0_SUBMODULE2_CAP_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE2_RELOAD_IRQHandler, FLEXPWM0_SUBMODULE2_RELOAD_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_RELOAD_ERROR_IRQHandler, FLEXPWM0_RELOAD_ERROR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_FAULT_IRQHandler, FLEXPWM0_FAULT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ITRC_IRQHandler, ITRC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TDET_IRQHandler, TDET_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(MU0_IRQHandler, MU0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(INTM_IRQHandler, INTM_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SGI_IRQHandler, SGI_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SECURE_ERR_IRQHandler, SECURE_ERR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PKC_IRQHandler, PKC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TRNG_IRQHandler, TRNG_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLASH_Arbiter_IRQHandler, FLASH_Arbiter_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(BLE_INT0_IRQHandler, BLE_INT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(BLE_INT1_IRQHandler, BLE_INT1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(BLE_INT2_IRQHandler, BLE_INT2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(BRF_INT_IRQHandler, BRF_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(T1_INT_IRQHandler, T1_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(T2_INT_IRQHandler, T2_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(T3_INT_IRQHandler, T3_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(T4_INT_IRQHandler, T4_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WDG1_IRQHandler, WDG1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(OSC_32M_READY_IRQHandler, OSC_32M_READY_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RBME_INT_IRQHandler, RBME_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RSM_INT_IRQHandler, RSM_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PLL_ABORT_INT_IRQHandler, PLL_ABORT_INT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA_LIGHT_IRQHandler, DMA_LIGHT_DriverIRQHandler)

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
    Reset_Handler,                                   /* Reset Handler */
    NMI_Handler,                                     /* NMI Handler*/
    HardFault_Handler,                               /* Hard Fault Handler*/
    MemManage_Handler,                               /* MPU Fault Handler*/
    BusFault_Handler,                                /* Bus Fault Handler*/
    UsageFault_Handler,                              /* Usage Fault Handler*/
    SecureFault_Handler,                             /* Secure Fault Handler*/
    0,                                               /* Reserved*/
    0,                                               /* Reserved*/
    0,                                               /* Reserved*/
    SVC_Handler,                                     /* SVCall Handler*/
    DebugMon_Handler,                                /* Debug Monitor Handler*/
    0,                                               /* Reserved*/
    PendSV_Handler,                                  /* PendSV Handler*/
    SysTick_Handler,                                 /* SysTick Handler*/

                                                    /* External Interrupts*/
    CTI_IRQHandler,                                 /* Cross Trigger Interface interrupt*/
    CMC0_IRQHandler,                                /* Core Mode Controller interrupt*/
    DMA0_CH0_IRQHandler,                            /* eDMA channel 0 error or transfer complete*/
    DMA0_CH1_IRQHandler,                            /* eDMA channel 1 error or transfer complete*/
    DMA0_CH2_IRQHandler,                            /* eDMA channel 2 error or transfer complete*/
    DMA0_CH3_IRQHandler,                            /* eDMA channel 3 error or transfer complete*/
    DMA0_CH4_IRQHandler,                            /* eDMA channel 4 error or transfer complete*/
    DMA0_CH5_IRQHandler,                            /* eDMA channel 5 error or transfer complete*/
    DMA0_CH6_IRQHandler,                            /* eDMA channel 6 error or transfer complete*/
    DMA0_CH7_IRQHandler,                            /* eDMA channel 7 error or transfer complete*/
    DMA0_CH8_IRQHandler,                            /* eDMA channel 8 error or transfer complete*/
    DMA0_CH9_IRQHandler,                            /* eDMA channel 9 error or transfer complete*/
    DMA0_CH10_IRQHandler,                           /* eDMA channel 10 error or transfer complete*/
    DMA0_CH11_IRQHandler,                           /* eDMA channel 11 error or transfer complete*/
    DMA0_CH12_IRQHandler,                           /* eDMA channel 12 error or transfer complete*/
    DMA0_CH13_IRQHandler,                           /* eDMA channel 13 error or transfer complete*/
    DMA0_CH14_IRQHandler,                           /* eDMA channel 14 error or transfer complete*/
    DMA0_CH15_IRQHandler,                           /* eDMA channel 15 error or transfer complete*/
    EWM0_IRQHandler,                                /* External Watchdog Monitor interrupt*/
    MCM0_IRQHandler,                                /* Miscellaneous Control Module0 interrupt*/
    MSCM0_IRQHandler,                               /* Miscellaneous System Control Module interrupt*/
    SYSCON0_IRQHandler,                             /* System control module*/
    SECCON0_IRQHandler,                             /* Secure System control module*/
    SPC0_IRQHandler,                                /* System Power Controller 0 interrupt*/
    WUU0_IRQHandler,                                /* Wake-Up Unit 0 interrupt*/
    WDOG0_IRQHandler,                               /* Watchdog Timer 0 interrupt*/
    WDOG1_IRQHandler,                               /* Watchdog Timer 1 interrupt*/
    CWDOG0_IRQHandler,                              /* Code watchdog 0 interrupt*/
    CWDOG1_IRQHandler,                              /* Code watchdog 1 interrupt*/
    SCG0_IRQHandler,                                /* System Clock Generator 0 interrupt*/
    SFA0_IRQHandler,                                /* Signal Frequency Analyzer 0 interrupt*/
    FMU0_IRQHandler,                                /* Flash Memory Unit 0 interrupt*/
    SFA1_IRQHandler,                                /* SFA interrupt for FRO-200M calibration*/
    DSB0_IRQHandler,                                /* Data Stream Buffer*/
    TRDC0_IRQHandler,                               /* Trusted Resource Domain Controller 0 interrupt*/
    RTC_Alarm_IRQHandler,                           /* Real Time Clock 0 alarm interrupt*/
    RTC_Seconds_IRQHandler,                         /* Real Time Clock 0 seconds interrupt*/
    LPTMR0_IRQHandler,                              /* Low-Power Timer0 interrupt*/
    LPTMR1_IRQHandler,                              /* Low-Power Timer1 interrupt*/
    LPIT0_IRQHandler,                               /* Low-Power Periodic Interrupt Timer 0 interrupt*/
    TPM_0_IRQHandler,                               /* Timer / PWM Module 0 interrupt*/
    TPM_1_IRQHandler,                               /* Timer / PWM Module 1 interrupt*/
    TPM_2_IRQHandler,                               /* Timer / PWM Module 2 interrupt*/
    TPM_3_IRQHandler,                               /* Timer / PWM Module 3 interrupt*/
    TPM_4_IRQHandler,                               /* Timer / PWM Module 4 interrupt*/
    MU1_IRQHandler,                                 /* Interrupt from MU1/DSP-V lite*/
    SYSCON0_ECC_IRQHandler,                         /* SRAM ECC Error interrupt*/
    LPI2C0_IRQHandler,                              /* Low-Power Inter Integrated Circuit 0 interrupt*/
    LPI2C1_IRQHandler,                              /* Low-Power Inter Integrated Circuit 1 interrupt*/
    LPSPI0_IRQHandler,                              /* Low-Power Serial Peripheral Interface 0 interrupt*/
    LPSPI1_IRQHandler,                              /* Low-Power Serial Peripheral Interface 1 interrupt*/
    LPSPI2_IRQHandler,                              /* Low-Power Serial Peripheral Interface 2 interrupt*/
    LPUART0_IRQHandler,                             /* Low-Power Universal Asynchronous Receiver/Transmitter 0 interrupt*/
    LPUART1_IRQHandler,                             /* Low-Power Universal Asynchronous Receiver/Transmitter 1 interrupt*/
    CAN0_IRQHandler,                                /* Controller Area Network 0 interrupt*/
    RF_ZIGBEE_IRQHandler,                           /* Zigbee Mac controller*/
    RF_Generic_IRQHandler,                          /* Generic Link Layer interrupt*/
    RF_BRIC_IRQHandler,                             /* Baix Radio Crypto*/
    RF_LCL_IRQHandler,                              /* Localization control*/
    RF_WOR_IRQHandler,                              /* Wake on radio*/
    RFMC_IRQHandler,                                /* RFMC interrupt*/
    Reserved77_IRQHandler,                          /* xxx Interrupt 77*/
    Reserved78_IRQHandler,                          /* xxx Interrupt 78*/
    COEX_INT_IRQHandler,                            /* COEX_INT_IRQn*/
    Reserved80_IRQHandler,                          /* xxx Interrupt 80*/
    GPIOA_INT0_IRQHandler,                          /* General Purpose Input/Output A interrupt 0*/
    GPIOA_INT1_IRQHandler,                          /* General Purpose Input/Output A interrupt 1*/
    GPIOB_INT0_IRQHandler,                          /* General Purpose Input/Output B interrupt 0*/
    GPIOB_INT1_IRQHandler,                          /* General Purpose Input/Output B interrupt 1*/
    GPIOC_INT0_IRQHandler,                          /* General Purpose Input/Output C interrupt 0*/
    GPIOC_INT1_IRQHandler,                          /* General Purpose Input/Output C interrupt 1*/
    GPIOD_INT0_IRQHandler,                          /* General Purpose Input/Output D interrupt 0*/
    GPIOD_INT1_IRQHandler,                          /* General Purpose Input/Output D interrupt 1*/
    Reserved89_IRQHandler,                          /* xxx Interrupt 89*/
    Reserved90_IRQHandler,                          /* xxx Interrupt 90*/
    Reserved91_IRQHandler,                          /* xxx Interrupt 91*/
    Reserved92_IRQHandler,                          /* xxx Interrupt 92*/
    ADC0_IRQHandler,                                /* Analog-to-Digital Converter - General Purpose0 interrupt*/
    CMP0_IRQHandler,                                /* Comparator - General Purpose0 interrupt*/
    FLEXPWM0_SUBMODULE0_CMP_IRQHandler,             /* PWM_CMP0: Submodule 0 compare interrupt*/
    FLEXPWM0_SUBMODULE0_CAP_IRQHandler,             /* PWM_CAP0: Submodule 0 input capture interrupt*/
    FLEXPWM0_SUBMODULE0_RELOAD_IRQHandler,          /* PWM_RELOAD0: Submodule 0 Reload interrupt*/
    FLEXPWM0_SUBMODULE1_CMP_IRQHandler,             /* PWM_CMP1: Submodule 1 compare interrupt*/
    FLEXPWM0_SUBMODULE1_CAP_IRQHandler,             /* PWM_CAP1: Submodule 1 input capture interrupt*/
    FLEXPWM0_SUBMODULE1_RELOAD_IRQHandler,          /* PWM_RELOAD1: Submodule 1 Reload interrupt*/
    FLEXPWM0_SUBMODULE2_CMP_IRQHandler,             /* PWM_CMP2: Submodule 2 compare interrupt*/
    FLEXPWM0_SUBMODULE2_CAP_IRQHandler,             /* PWM_CAP2: Submodule 2 input capture interrupt*/
    FLEXPWM0_SUBMODULE2_RELOAD_IRQHandler,          /* PWM_RELOAD2: Submodule 2 Reload interrupt*/
    FLEXPWM0_RELOAD_ERROR_IRQHandler,               /* PWM_RERR: Reload Error interrupt*/
    FLEXPWM0_FAULT_IRQHandler,                      /* PWM_FAULT: PWM fault input interrupt*/
    ITRC_IRQHandler,                                /* Output of Intrusion and tamper response controller (ITRC_IRQ)*/
    TDET_IRQHandler,                                /* Tamper detection interrupt*/
    MU0_IRQHandler,                                 /* Interrupt from MU0 to CPU0*/
    INTM_IRQHandler,                                /* Error flag to show Radio interrrupt is not serviced in time*/
    SGI_IRQHandler,                                 /* SGI Interrupt*/
    SECURE_ERR_IRQHandler,                          /* Secure IP Error Interrupt*/
    PKC_IRQHandler,                                 /* PKC Module Error*/
    TRNG_IRQHandler,                                /* TRNG Module Error*/
    FLASH_Arbiter_IRQHandler,                       /* Combined interrupt from Flash Arbiter */
    BLE_INT0_IRQHandler,                            /* BLE LL interrupt Set 0 (BLE_INT0_IRQn)*/
    BLE_INT1_IRQHandler,                            /* BLE LL interrupt Set 1 (BLE_INT1_IRQn)*/
    BLE_INT2_IRQHandler,                            /* BLE LL interrupt Set 2 (BLE_INT2_IRQn)*/
    BRF_INT_IRQHandler,                             /* BLE LL/ BTRFIRQ (BRF_INT_IRQn)*/
    T1_INT_IRQHandler,                              /* BLE LL / RTU 1 (T1_INT_IRQn)*/
    T2_INT_IRQHandler,                              /* BLE LL / RTU 2 (T2_INT_IRQn)*/
    T3_INT_IRQHandler,                              /* BLE LL / RTU 3 (T3_INT_IRQn)*/
    T4_INT_IRQHandler,                              /* BLE LL / RTU 4 (T4_INT_IRQn)*/
    WDG1_IRQHandler,                                /* BLE LL / RTU 5 (WDG1_INT_IRQn)*/
    OSC_32M_READY_IRQHandler,                       /* 32M Crystal OSC ready interrupt*/
    RBME_INT_IRQHandler,                            /* Radio Bit Manipulation Engine (RBME_INT_IRQn)*/
    RSM_INT_IRQHandler,                             /* Ranging State Machine (RSM_INT_IRQn)*/
    PLL_ABORT_INT_IRQHandler,                       /* PLL control (PLL_ABORT_INT_IRQn)*/
    DMA_LIGHT_IRQHandler,                           /* DMA light*/
    DefaultISR,                                     /* 129*/
    DefaultISR,                                     /* 130*/
    DefaultISR,                                     /* 131*/
    DefaultISR,                                     /* 132*/
    DefaultISR,                                     /* 133*/
    DefaultISR,                                     /* 134*/
    DefaultISR,                                     /* 135*/
    DefaultISR,                                     /* 136*/
    DefaultISR,                                     /* 137*/
    DefaultISR,                                     /* 138*/
    DefaultISR,                                     /* 139*/
    DefaultISR,                                     /* 140*/
    DefaultISR,                                     /* 141*/
    DefaultISR,                                     /* 142*/
    DefaultISR,                                     /* 143*/
    DefaultISR,                                     /* 144*/
    DefaultISR,                                     /* 145*/
    DefaultISR,                                     /* 146*/
    DefaultISR,                                     /* 147*/
    DefaultISR,                                     /* 148*/
    DefaultISR,                                     /* 149*/
    DefaultISR,                                     /* 150*/
    DefaultISR,                                     /* 151*/
    DefaultISR,                                     /* 152*/
    DefaultISR,                                     /* 153*/
    DefaultISR,                                     /* 154*/
    DefaultISR,                                     /* 155*/
    DefaultISR,                                     /* 156*/
    DefaultISR,                                     /* 157*/
    DefaultISR,                                     /* 158*/
    DefaultISR,                                     /* 159*/
    DefaultISR,                                     /* 160*/
    DefaultISR,                                     /* 161*/
    DefaultISR,                                     /* 162*/
    DefaultISR,                                     /* 163*/
    DefaultISR,                                     /* 164*/
    DefaultISR,                                     /* 165*/
    DefaultISR,                                     /* 166*/
    DefaultISR,                                     /* 167*/
    DefaultISR,                                     /* 168*/
    DefaultISR,                                     /* 169*/
    DefaultISR,                                     /* 170*/
    DefaultISR,                                     /* 171*/
    DefaultISR,                                     /* 172*/
    DefaultISR,                                     /* 173*/
    DefaultISR,                                     /* 174*/
    DefaultISR,                                     /* 175*/
    DefaultISR,                                     /* 176*/
    DefaultISR,                                     /* 177*/
    DefaultISR,                                     /* 178*/
    DefaultISR,                                     /* 179*/
    DefaultISR,                                     /* 180*/
    DefaultISR,                                     /* 181*/
    DefaultISR,                                     /* 182*/
    DefaultISR,                                     /* 183*/
    DefaultISR,                                     /* 184*/
    DefaultISR,                                     /* 185*/
    DefaultISR,                                     /* 186*/
    DefaultISR,                                     /* 187*/
    DefaultISR,                                     /* 188*/
    DefaultISR,                                     /* 189*/
    DefaultISR,                                     /* 190*/
    DefaultISR,                                     /* 191*/
    DefaultISR,                                     /* 192*/
    DefaultISR,                                     /* 193*/
    DefaultISR,                                     /* 194*/
    DefaultISR,                                     /* 195*/
    DefaultISR,                                     /* 196*/
    DefaultISR,                                     /* 197*/
    DefaultISR,                                     /* 198*/
    DefaultISR,                                     /* 199*/
    DefaultISR,                                     /* 200*/
    DefaultISR,                                     /* 201*/
    DefaultISR,                                     /* 202*/
    DefaultISR,                                     /* 203*/
    DefaultISR,                                     /* 204*/
    DefaultISR,                                     /* 205*/
    DefaultISR,                                     /* 206*/
    DefaultISR,                                     /* 207*/
    DefaultISR,                                     /* 208*/
    DefaultISR,                                     /* 209*/
    DefaultISR,                                     /* 210*/
    DefaultISR,                                     /* 211*/
    DefaultISR,                                     /* 212*/
    DefaultISR,                                     /* 213*/
    DefaultISR,                                     /* 214*/
    DefaultISR,                                     /* 215*/
    DefaultISR,                                     /* 216*/
    DefaultISR,                                     /* 217*/
    DefaultISR,                                     /* 218*/
    DefaultISR,                                     /* 219*/
    DefaultISR,                                     /* 220*/
    DefaultISR,                                     /* 221*/
    DefaultISR,                                     /* 222*/
    DefaultISR,                                     /* 223*/
    DefaultISR,                                     /* 224*/
    DefaultISR,                                     /* 225*/
    DefaultISR,                                     /* 226*/
    DefaultISR,                                     /* 227*/
    DefaultISR,                                     /* 228*/
    DefaultISR,                                     /* 229*/
    DefaultISR,                                     /* 230*/
    DefaultISR,                                     /* 231*/
    DefaultISR,                                     /* 232*/
    DefaultISR,                                     /* 233*/
    DefaultISR,                                     /* 234*/
    DefaultISR,                                     /* 235*/
    DefaultISR,                                     /* 236*/
    DefaultISR,                                     /* 237*/
    DefaultISR,                                     /* 238*/
    DefaultISR,                                     /* 239*/
    DefaultISR,                                     /* 240*/
    DefaultISR,                                     /* 241*/
    DefaultISR,                                     /* 242*/
    DefaultISR,                                     /* 243*/
    DefaultISR,                                     /* 244*/
    DefaultISR,                                     /* 245*/
    DefaultISR,                                     /* 246*/
    DefaultISR,                                     /* 247*/
    DefaultISR,                                     /* 248*/
    DefaultISR,                                     /* 249*/
    DefaultISR,                                     /* 250*/
    DefaultISR,                                     /* 251*/
    DefaultISR,                                     /* 252*/
    DefaultISR,                                     /* 253*/
    DefaultISR,                                     /* 254*/
    DefaultISR,                                     /* 255*/

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
