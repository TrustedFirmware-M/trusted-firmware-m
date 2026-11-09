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
**         CMSIS Peripheral Access Layer for KW43B43ZC7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
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
 * @file KW43B43ZC7_COMMON.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for KW43B43ZC7
 *
 * CMSIS Peripheral Access Layer for KW43B43ZC7
 */

#if !defined(KW43B43ZC7_COMMON_H_)
#define KW43B43ZC7_COMMON_H_                     /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 129                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M33 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M33 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M33 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M33 Usage Fault Interrupt */
  SecureFault_IRQn             = -9,               /**< Cortex-M33 Secure Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M33 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M33 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M33 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M33 System Tick Interrupt */

  /* Device specific interrupts */
  CTI_IRQn                     = 0,                /**< Cross Trigger Interface interrupt */
  CMC0_IRQn                    = 1,                /**< Core Mode Controller interrupt */
  DMA0_CH0_IRQn                = 2,                /**< eDMA channel 0 error or transfer complete */
  DMA0_CH1_IRQn                = 3,                /**< eDMA channel 1 error or transfer complete */
  DMA0_CH2_IRQn                = 4,                /**< eDMA channel 2 error or transfer complete */
  DMA0_CH3_IRQn                = 5,                /**< eDMA channel 3 error or transfer complete */
  DMA0_CH4_IRQn                = 6,                /**< eDMA channel 4 error or transfer complete */
  DMA0_CH5_IRQn                = 7,                /**< eDMA channel 5 error or transfer complete */
  DMA0_CH6_IRQn                = 8,                /**< eDMA channel 6 error or transfer complete */
  DMA0_CH7_IRQn                = 9,                /**< eDMA channel 7 error or transfer complete */
  DMA0_CH8_IRQn                = 10,               /**< eDMA channel 8 error or transfer complete */
  DMA0_CH9_IRQn                = 11,               /**< eDMA channel 9 error or transfer complete */
  DMA0_CH10_IRQn               = 12,               /**< eDMA channel 10 error or transfer complete */
  DMA0_CH11_IRQn               = 13,               /**< eDMA channel 11 error or transfer complete */
  DMA0_CH12_IRQn               = 14,               /**< eDMA channel 12 error or transfer complete */
  DMA0_CH13_IRQn               = 15,               /**< eDMA channel 13 error or transfer complete */
  DMA0_CH14_IRQn               = 16,               /**< eDMA channel 14 error or transfer complete */
  DMA0_CH15_IRQn               = 17,               /**< eDMA channel 15 error or transfer complete */
  EWM0_IRQn                    = 18,               /**< External Watchdog Monitor interrupt */
  MCM0_IRQn                    = 19,               /**< Miscellaneous Control Module0 interrupt */
  MSCM0_IRQn                   = 20,               /**< Miscellaneous System Control Module interrupt */
  SYSCON0_IRQn                 = 21,               /**< System control module */
  SECCON0_IRQn                 = 22,               /**< Secure System control module */
  SPC0_IRQn                    = 23,               /**< System Power Controller 0 interrupt */
  WUU0_IRQn                    = 24,               /**< Wake-Up Unit 0 interrupt */
  WDOG0_IRQn                   = 25,               /**< Watchdog Timer 0 interrupt */
  WDOG1_IRQn                   = 26,               /**< Watchdog Timer 1 interrupt */
  CDOG0_IRQn                   = 27,               /**< Code watchdog 0 interrupt */
  CDOG1_IRQn                   = 28,               /**< Code watchdog 1 interrupt */
  SCG0_IRQn                    = 29,               /**< System Clock Generator 0 interrupt */
  SFA0_IRQn                    = 30,               /**< Signal Frequency Analyzer 0 interrupt */
  FMU0_IRQn                    = 31,               /**< Flash Memory Unit 0 interrupt */
  SFA1_IRQn                    = 32,               /**< SFA interrupt for FRO-200M calibration */
  DSB0_IRQn                    = 33,               /**< Data Stream Buffer */
  TRDC0_IRQn                   = 34,               /**< Trusted Resource Domain Controller 0 interrupt */
  RTC_Alarm_IRQn               = 35,               /**< Real Time Clock 0 alarm interrupt */
  RTC_Seconds_IRQn             = 36,               /**< Real Time Clock 0 seconds interrupt */
  LPTMR0_IRQn                  = 37,               /**< Low-Power Timer0 interrupt */
  LPTMR1_IRQn                  = 38,               /**< Low-Power Timer1 interrupt */
  LPIT0_IRQn                   = 39,               /**< Low-Power Periodic Interrupt Timer 0 interrupt */
  TPM_0_IRQn                   = 40,               /**< Timer / PWM Module 0 interrupt */
  TPM_1_IRQn                   = 41,               /**< Timer / PWM Module 1 interrupt */
  TPM_2_IRQn                   = 42,               /**< Timer / PWM Module 2 interrupt */
  TPM_3_IRQn                   = 43,               /**< Timer / PWM Module 3 interrupt */
  TPM_4_IRQn                   = 44,               /**< Timer / PWM Module 4 interrupt */
  MU1_IRQn                     = 45,               /**< Interrupt from MU1/DSP-V lite */
  SYSCON0_ECC_IRQn             = 46,               /**< SRAM ECC Error interrupt */
  LPI2C0_IRQn                  = 47,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPI2C1_IRQn                  = 48,               /**< Low-Power Inter Integrated Circuit 1 interrupt */
  LPSPI0_IRQn                  = 49,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  LPSPI1_IRQn                  = 50,               /**< Low-Power Serial Peripheral Interface 1 interrupt */
  LPSPI2_IRQn                  = 51,               /**< Low-Power Serial Peripheral Interface 2 interrupt */
  LPUART0_IRQn                 = 52,               /**< Low-Power Universal Asynchronous Receiver/Transmitter 0 interrupt */
  LPUART1_IRQn                 = 53,               /**< Low-Power Universal Asynchronous Receiver/Transmitter 1 interrupt */
  CAN0_IRQn                    = 54,               /**< Controller Area Network 0 interrupt */
  RF_ZIGBEE_IRQn               = 55,               /**< Zigbee Mac controller */
  RF_Generic_IRQn              = 56,               /**< Generic Link Layer interrupt */
  RF_BRIC_IRQn                 = 57,               /**< Baix Radio Crypto */
  RF_LCL_IRQn                  = 58,               /**< Localization control */
  RF_WOR_IRQn                  = 59,               /**< Wake on radio */
  RFMC_IRQn                    = 60,               /**< RFMC interrupt */
  COEX_INT_IRQn                = 63,               /**< COEX_INT_IRQn */
  GPIOA_INT0_IRQn              = 65,               /**< General Purpose Input/Output A interrupt 0 */
  GPIOA_INT1_IRQn              = 66,               /**< General Purpose Input/Output A interrupt 1 */
  GPIOB_INT0_IRQn              = 67,               /**< General Purpose Input/Output B interrupt 0 */
  GPIOB_INT1_IRQn              = 68,               /**< General Purpose Input/Output B interrupt 1 */
  GPIOC_INT0_IRQn              = 69,               /**< General Purpose Input/Output C interrupt 0 */
  GPIOC_INT1_IRQn              = 70,               /**< General Purpose Input/Output C interrupt 1 */
  GPIOD_INT0_IRQn              = 71,               /**< General Purpose Input/Output D interrupt 0 */
  GPIOD_INT1_IRQn              = 72,               /**< General Purpose Input/Output D interrupt 1 */
  ADC0_IRQn                    = 77,               /**< Analog-to-Digital Converter - General Purpose0 interrupt */
  CMP0_IRQn                    = 78,               /**< Comparator - General Purpose0 interrupt */
  FLEXPWM0_SUBMODULE0_CMP_IRQn = 79,               /**< PWM_CMP0: Submodule 0 compare interrupt */
  FLEXPWM0_SUBMODULE0_CAP_IRQn = 80,               /**< PWM_CAP0: Submodule 0 input capture interrupt */
  FLEXPWM0_SUBMODULE0_RELOAD_IRQn = 81,            /**< PWM_RELOAD0: Submodule 0 Reload interrupt */
  FLEXPWM0_SUBMODULE1_CMP_IRQn = 82,               /**< PWM_CMP1: Submodule 1 compare interrupt */
  FLEXPWM0_SUBMODULE1_CAP_IRQn = 83,               /**< PWM_CAP1: Submodule 1 input capture interrupt */
  FLEXPWM0_SUBMODULE1_RELOAD_IRQn = 84,            /**< PWM_RELOAD1: Submodule 1 Reload interrupt */
  FLEXPWM0_SUBMODULE2_CMP_IRQn = 85,               /**< PWM_CMP2: Submodule 2 compare interrupt */
  FLEXPWM0_SUBMODULE2_CAP_IRQn = 86,               /**< PWM_CAP2: Submodule 2 input capture interrupt */
  FLEXPWM0_SUBMODULE2_RELOAD_IRQn = 87,            /**< PWM_RELOAD2: Submodule 2 Reload interrupt */
  FLEXPWM0_RELOAD_ERROR_IRQn   = 88,               /**< PWM_RERR: Reload Error interrupt */
  FLEXPWM0_FAULT_IRQn          = 89,               /**< PWM_FAULT: PWM fault input interrupt */
  ITRC_IRQn                    = 90,               /**< Output of Intrusion and tamper response controller (ITRC_IRQ) */
  TDET_IRQn                    = 91,               /**< Tamper detection interrupt */
  MU0_IRQn                     = 92,               /**< Interrupt from MU0 to CPU0 */
  INTM_IRQn                    = 93,               /**< Error flag to show Radio interrrupt is not serviced in time */
  SGI_IRQn                     = 94,               /**< SGI Interrupt */
  SECURE_ERR_IRQn              = 95,               /**< Secure IP Error Interrupt */
  PKC_IRQn                     = 96,               /**< PKC Module Error */
  TRNG_IRQn                    = 97,               /**< TRNG Module Error */
  FLASH_Arbiter_IRQn           = 98,               /**< Combined interrupt from Flash Arbiter  */
  BLE_INT0_IRQn                = 99,               /**< BLE LL interrupt Set 0 (BLE_INT0_IRQn) */
  BLE_INT1_IRQn                = 100,              /**< BLE LL interrupt Set 1 (BLE_INT1_IRQn) */
  BLE_INT2_IRQn                = 101,              /**< BLE LL interrupt Set 2 (BLE_INT2_IRQn) */
  BRF_INT_IRQn                 = 102,              /**< BLE LL/ BTRFIRQ (BRF_INT_IRQn) */
  T1_INT_IRQn                  = 103,              /**< BLE LL / RTU 1 (T1_INT_IRQn) */
  T2_INT_IRQn                  = 104,              /**< BLE LL / RTU 2 (T2_INT_IRQn) */
  T3_INT_IRQn                  = 105,              /**< BLE LL / RTU 3 (T3_INT_IRQn) */
  T4_INT_IRQn                  = 106,              /**< BLE LL / RTU 4 (T4_INT_IRQn) */
  WDG1_IRQn                    = 107,              /**< BLE LL / RTU 5 (WDG1_INT_IRQn) */
  OSC_32M_READY_IRQn           = 108,              /**< 32M Crystal OSC ready interrupt */
  RBME_INT_IRQn                = 109,              /**< Radio Bit Manipulation Engine (RBME_INT_IRQn) */
  RSM_INT_IRQn                 = 110,              /**< Ranging State Machine (RSM_INT_IRQn) */
  PLL_ABORT_INT_IRQn           = 111,              /**< PLL control (PLL_ABORT_INT_IRQn) */
  DMA_LIGHT_IRQn               = 112,              /**< DMA light */
  DEVICE_MAX_IRQn              = DMA_LIGHT_IRQn    /**< Highest IRQ number for this device */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M33 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M33 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               3         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */
#define __DSP_PRESENT                  1         /**< Defines if Armv8-M Mainline core supports DSP instructions */
#define __SAUREGION_PRESENT            1         /**< Defines if an SAU is present or not */

#include "core_cm33.h"                 /* Core Peripheral Access Layer */
#include "system_KW43B43ZC7.h"         /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef KW43B43ZC7_SERIES
#define KW43B43ZC7_SERIES
#endif
/* CPU specific feature definitions */
#include "KW43B43ZC7_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSADC_0 base address */
  #define HSADC_0_BASE                             (0x5002F000u)
  /** Peripheral HSADC_0 base address */
  #define HSADC_0_BASE_NS                          (0x4002F000u)
  /** Peripheral HSADC_0 base pointer */
  #define HSADC_0                                  ((ADC_Type *)HSADC_0_BASE)
  /** Peripheral HSADC_0 base pointer */
  #define HSADC_0_NS                               ((ADC_Type *)HSADC_0_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { HSADC_0_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { HSADC_0 }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { HSADC_0_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { HSADC_0_NS }
#else
  /** Peripheral HSADC_0 base address */
  #define HSADC_0_BASE                             (0x4002F000u)
  /** Peripheral HSADC_0 base pointer */
  #define HSADC_0                                  ((ADC_Type *)HSADC_0_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { HSADC_0_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { HSADC_0 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* AOI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AOI_0 base address */
  #define AOI_0_BASE                               (0x50036000u)
  /** Peripheral AOI_0 base address */
  #define AOI_0_BASE_NS                            (0x40036000u)
  /** Peripheral AOI_0 base pointer */
  #define AOI_0                                    ((AOI_Type *)AOI_0_BASE)
  /** Peripheral AOI_0 base pointer */
  #define AOI_0_NS                                 ((AOI_Type *)AOI_0_BASE_NS)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI_0_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI_0 }
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS_NS                        { AOI_0_BASE_NS }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS_NS                         { AOI_0_NS }
#else
  /** Peripheral AOI_0 base address */
  #define AOI_0_BASE                               (0x40036000u)
  /** Peripheral AOI_0 base pointer */
  #define AOI_0                                    ((AOI_Type *)AOI_0_BASE)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI_0_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI_0 }
#endif

/* ATX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ATX_0 base address */
  #define ATX_0_BASE                               (0x50031000u)
  /** Peripheral ATX_0 base address */
  #define ATX_0_BASE_NS                            (0x40031000u)
  /** Peripheral ATX_0 base pointer */
  #define ATX_0                                    ((ATX_Type *)ATX_0_BASE)
  /** Peripheral ATX_0 base pointer */
  #define ATX_0_NS                                 ((ATX_Type *)ATX_0_BASE_NS)
  /** Array initializer of ATX peripheral base addresses */
  #define ATX_BASE_ADDRS                           { ATX_0_BASE }
  /** Array initializer of ATX peripheral base pointers */
  #define ATX_BASE_PTRS                            { ATX_0 }
  /** Array initializer of ATX peripheral base addresses */
  #define ATX_BASE_ADDRS_NS                        { ATX_0_BASE_NS }
  /** Array initializer of ATX peripheral base pointers */
  #define ATX_BASE_PTRS_NS                         { ATX_0_NS }
#else
  /** Peripheral ATX_0 base address */
  #define ATX_0_BASE                               (0x40031000u)
  /** Peripheral ATX_0 base pointer */
  #define ATX_0                                    ((ATX_Type *)ATX_0_BASE)
  /** Array initializer of ATX peripheral base addresses */
  #define ATX_BASE_ADDRS                           { ATX_0_BASE }
  /** Array initializer of ATX peripheral base pointers */
  #define ATX_BASE_PTRS                            { ATX_0 }
#endif

/* AXBS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AXBS_0 base address */
  #define AXBS_0_BASE                              (0x50000000u)
  /** Peripheral AXBS_0 base address */
  #define AXBS_0_BASE_NS                           (0x40000000u)
  /** Peripheral AXBS_0 base pointer */
  #define AXBS_0                                   ((AXBS_Type *)AXBS_0_BASE)
  /** Peripheral AXBS_0 base pointer */
  #define AXBS_0_NS                                ((AXBS_Type *)AXBS_0_BASE_NS)
  /** Peripheral AXBS_MAIN_0 base address */
  #define AXBS_MAIN_0_BASE                         (0x503D0000u)
  /** Peripheral AXBS_MAIN_0 base address */
  #define AXBS_MAIN_0_BASE_NS                      (0x403D0000u)
  /** Peripheral AXBS_MAIN_0 base pointer */
  #define AXBS_MAIN_0                              ((AXBS_Type *)AXBS_MAIN_0_BASE)
  /** Peripheral AXBS_MAIN_0 base pointer */
  #define AXBS_MAIN_0_NS                           ((AXBS_Type *)AXBS_MAIN_0_BASE_NS)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS_0_BASE, AXBS_MAIN_0_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS_0, AXBS_MAIN_0 }
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS_NS                       { AXBS_0_BASE_NS, AXBS_MAIN_0_BASE_NS }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS_NS                        { AXBS_0_NS, AXBS_MAIN_0_NS }
#else
  /** Peripheral AXBS_0 base address */
  #define AXBS_0_BASE                              (0x40000000u)
  /** Peripheral AXBS_0 base pointer */
  #define AXBS_0                                   ((AXBS_Type *)AXBS_0_BASE)
  /** Peripheral AXBS_MAIN_0 base address */
  #define AXBS_MAIN_0_BASE                         (0x403D0000u)
  /** Peripheral AXBS_MAIN_0 base pointer */
  #define AXBS_MAIN_0                              ((AXBS_Type *)AXBS_MAIN_0_BASE)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS_0_BASE, AXBS_MAIN_0_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS_0, AXBS_MAIN_0 }
#endif

/* BLE2_REG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLE2 base address */
  #define BLE2_BASE                                (0x50110000u)
  /** Peripheral BLE2 base address */
  #define BLE2_BASE_NS                             (0x40110000u)
  /** Peripheral BLE2 base pointer */
  #define BLE2                                     ((BLE2_REG_Type *)BLE2_BASE)
  /** Peripheral BLE2 base pointer */
  #define BLE2_NS                                  ((BLE2_REG_Type *)BLE2_BASE_NS)
  /** Peripheral BLE2_REG base address */
  #define BLE2_REG_BASE                            (0x50110000u)
  /** Peripheral BLE2_REG base address */
  #define BLE2_REG_BASE_NS                         (0x40110000u)
  /** Peripheral BLE2_REG base pointer */
  #define BLE2_REG                                 ((BLE2_REG_Type *)BLE2_REG_BASE)
  /** Peripheral BLE2_REG base pointer */
  #define BLE2_REG_NS                              ((BLE2_REG_Type *)BLE2_REG_BASE_NS)
  /** Array initializer of BLE2_REG peripheral base addresses */
  #define BLE2_REG_BASE_ADDRS                      { BLE2_BASE, BLE2_REG_BASE }
  /** Array initializer of BLE2_REG peripheral base pointers */
  #define BLE2_REG_BASE_PTRS                       { BLE2, BLE2_REG }
  /** Array initializer of BLE2_REG peripheral base addresses */
  #define BLE2_REG_BASE_ADDRS_NS                   { BLE2_BASE_NS, BLE2_REG_BASE_NS }
  /** Array initializer of BLE2_REG peripheral base pointers */
  #define BLE2_REG_BASE_PTRS_NS                    { BLE2_NS, BLE2_REG_NS }
#else
  /** Peripheral BLE2 base address */
  #define BLE2_BASE                                (0x40110000u)
  /** Peripheral BLE2 base pointer */
  #define BLE2                                     ((BLE2_REG_Type *)BLE2_BASE)
  /** Peripheral BLE2_REG base address */
  #define BLE2_REG_BASE                            (0x40110000u)
  /** Peripheral BLE2_REG base pointer */
  #define BLE2_REG                                 ((BLE2_REG_Type *)BLE2_REG_BASE)
  /** Array initializer of BLE2_REG peripheral base addresses */
  #define BLE2_REG_BASE_ADDRS                      { BLE2_BASE, BLE2_REG_BASE }
  /** Array initializer of BLE2_REG peripheral base pointers */
  #define BLE2_REG_BASE_PTRS                       { BLE2, BLE2_REG }
#endif

/* BRIC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BRIC base address */
  #define BRIC_BASE                                (0x50106700u)
  /** Peripheral BRIC base address */
  #define BRIC_BASE_NS                             (0x40106700u)
  /** Peripheral BRIC base pointer */
  #define BRIC                                     ((BRIC_Type *)BRIC_BASE)
  /** Peripheral BRIC base pointer */
  #define BRIC_NS                                  ((BRIC_Type *)BRIC_BASE_NS)
  /** Array initializer of BRIC peripheral base addresses */
  #define BRIC_BASE_ADDRS                          { BRIC_BASE }
  /** Array initializer of BRIC peripheral base pointers */
  #define BRIC_BASE_PTRS                           { BRIC }
  /** Array initializer of BRIC peripheral base addresses */
  #define BRIC_BASE_ADDRS_NS                       { BRIC_BASE_NS }
  /** Array initializer of BRIC peripheral base pointers */
  #define BRIC_BASE_PTRS_NS                        { BRIC_NS }
#else
  /** Peripheral BRIC base address */
  #define BRIC_BASE                                (0x40106700u)
  /** Peripheral BRIC base pointer */
  #define BRIC                                     ((BRIC_Type *)BRIC_BASE)
  /** Array initializer of BRIC peripheral base addresses */
  #define BRIC_BASE_ADDRS                          { BRIC_BASE }
  /** Array initializer of BRIC peripheral base pointers */
  #define BRIC_BASE_PTRS                           { BRIC }
#endif

/* BTRTU1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BTRTU1 base address */
  #define BTRTU1_BASE                              (0x5010B400u)
  /** Peripheral BTRTU1 base address */
  #define BTRTU1_BASE_NS                           (0x4010B400u)
  /** Peripheral BTRTU1 base pointer */
  #define BTRTU1                                   ((BTRTU1_Type *)BTRTU1_BASE)
  /** Peripheral BTRTU1 base pointer */
  #define BTRTU1_NS                                ((BTRTU1_Type *)BTRTU1_BASE_NS)
  /** Array initializer of BTRTU1 peripheral base addresses */
  #define BTRTU1_BASE_ADDRS                        { BTRTU1_BASE }
  /** Array initializer of BTRTU1 peripheral base pointers */
  #define BTRTU1_BASE_PTRS                         { BTRTU1 }
  /** Array initializer of BTRTU1 peripheral base addresses */
  #define BTRTU1_BASE_ADDRS_NS                     { BTRTU1_BASE_NS }
  /** Array initializer of BTRTU1 peripheral base pointers */
  #define BTRTU1_BASE_PTRS_NS                      { BTRTU1_NS }
#else
  /** Peripheral BTRTU1 base address */
  #define BTRTU1_BASE                              (0x4010B400u)
  /** Peripheral BTRTU1 base pointer */
  #define BTRTU1                                   ((BTRTU1_Type *)BTRTU1_BASE)
  /** Array initializer of BTRTU1 peripheral base addresses */
  #define BTRTU1_BASE_ADDRS                        { BTRTU1_BASE }
  /** Array initializer of BTRTU1 peripheral base pointers */
  #define BTRTU1_BASE_PTRS                         { BTRTU1 }
#endif

/* BTU2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BTU2 base address */
  #define BTU2_BASE                                (0x50110000u)
  /** Peripheral BTU2 base address */
  #define BTU2_BASE_NS                             (0x40110000u)
  /** Peripheral BTU2 base pointer */
  #define BTU2                                     ((BTU2_Type *)BTU2_BASE)
  /** Peripheral BTU2 base pointer */
  #define BTU2_NS                                  ((BTU2_Type *)BTU2_BASE_NS)
  /** Array initializer of BTU2 peripheral base addresses */
  #define BTU2_BASE_ADDRS                          { BTU2_BASE }
  /** Array initializer of BTU2 peripheral base pointers */
  #define BTU2_BASE_PTRS                           { BTU2 }
  /** Array initializer of BTU2 peripheral base addresses */
  #define BTU2_BASE_ADDRS_NS                       { BTU2_BASE_NS }
  /** Array initializer of BTU2 peripheral base pointers */
  #define BTU2_BASE_PTRS_NS                        { BTU2_NS }
#else
  /** Peripheral BTU2 base address */
  #define BTU2_BASE                                (0x40110000u)
  /** Peripheral BTU2 base pointer */
  #define BTU2                                     ((BTU2_Type *)BTU2_BASE)
  /** Array initializer of BTU2 peripheral base addresses */
  #define BTU2_BASE_ADDRS                          { BTU2_BASE }
  /** Array initializer of BTU2 peripheral base pointers */
  #define BTU2_BASE_PTRS                           { BTU2 }
#endif

/* BTU2_REG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BTU2_REG base address */
  #define BTU2_REG_BASE                            (0x50110000u)
  /** Peripheral BTU2_REG base address */
  #define BTU2_REG_BASE_NS                         (0x40110000u)
  /** Peripheral BTU2_REG base pointer */
  #define BTU2_REG                                 ((BTU2_REG_Type *)BTU2_REG_BASE)
  /** Peripheral BTU2_REG base pointer */
  #define BTU2_REG_NS                              ((BTU2_REG_Type *)BTU2_REG_BASE_NS)
  /** Array initializer of BTU2_REG peripheral base addresses */
  #define BTU2_REG_BASE_ADDRS                      { BTU2_REG_BASE }
  /** Array initializer of BTU2_REG peripheral base pointers */
  #define BTU2_REG_BASE_PTRS                       { BTU2_REG }
  /** Array initializer of BTU2_REG peripheral base addresses */
  #define BTU2_REG_BASE_ADDRS_NS                   { BTU2_REG_BASE_NS }
  /** Array initializer of BTU2_REG peripheral base pointers */
  #define BTU2_REG_BASE_PTRS_NS                    { BTU2_REG_NS }
#else
  /** Peripheral BTU2_REG base address */
  #define BTU2_REG_BASE                            (0x40110000u)
  /** Peripheral BTU2_REG base pointer */
  #define BTU2_REG                                 ((BTU2_REG_Type *)BTU2_REG_BASE)
  /** Array initializer of BTU2_REG peripheral base addresses */
  #define BTU2_REG_BASE_ADDRS                      { BTU2_REG_BASE }
  /** Array initializer of BTU2_REG peripheral base pointers */
  #define BTU2_REG_BASE_PTRS                       { BTU2_REG }
#endif

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN_0 base address */
  #define CAN_0_BASE                               (0x50028000u)
  /** Peripheral CAN_0 base address */
  #define CAN_0_BASE_NS                            (0x40028000u)
  /** Peripheral CAN_0 base pointer */
  #define CAN_0                                    ((CAN_Type *)CAN_0_BASE)
  /** Peripheral CAN_0 base pointer */
  #define CAN_0_NS                                 ((CAN_Type *)CAN_0_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN_0_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN_0 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { CAN_0_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { CAN_0_NS }
#else
  /** Peripheral CAN_0 base address */
  #define CAN_0_BASE                               (0x40028000u)
  /** Peripheral CAN_0 base pointer */
  #define CAN_0                                    ((CAN_Type *)CAN_0_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN_0_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN_0 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_IRQn }
#define CAN_Error_IRQS                           { CAN0_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { CAN0_IRQn }

/* CCM32K - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANAREG_0 base address */
  #define ANAREG_0_BASE                            (0x5018A000u)
  /** Peripheral ANAREG_0 base address */
  #define ANAREG_0_BASE_NS                         (0x4018A000u)
  /** Peripheral ANAREG_0 base pointer */
  #define ANAREG_0                                 ((CCM32K_Type *)ANAREG_0_BASE)
  /** Peripheral ANAREG_0 base pointer */
  #define ANAREG_0_NS                              ((CCM32K_Type *)ANAREG_0_BASE_NS)
  /** Array initializer of CCM32K peripheral base addresses */
  #define CCM32K_BASE_ADDRS                        { ANAREG_0_BASE }
  /** Array initializer of CCM32K peripheral base pointers */
  #define CCM32K_BASE_PTRS                         { ANAREG_0 }
  /** Array initializer of CCM32K peripheral base addresses */
  #define CCM32K_BASE_ADDRS_NS                     { ANAREG_0_BASE_NS }
  /** Array initializer of CCM32K peripheral base pointers */
  #define CCM32K_BASE_PTRS_NS                      { ANAREG_0_NS }
#else
  /** Peripheral ANAREG_0 base address */
  #define ANAREG_0_BASE                            (0x4018A000u)
  /** Peripheral ANAREG_0 base pointer */
  #define ANAREG_0                                 ((CCM32K_Type *)ANAREG_0_BASE)
  /** Array initializer of CCM32K peripheral base addresses */
  #define CCM32K_BASE_ADDRS                        { ANAREG_0_BASE }
  /** Array initializer of CCM32K peripheral base pointers */
  #define CCM32K_BASE_PTRS                         { ANAREG_0 }
#endif

/* CDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CDOG_0 base address */
  #define CDOG_0_BASE                              (0x500B8000u)
  /** Peripheral CDOG_0 base address */
  #define CDOG_0_BASE_NS                           (0x400B8000u)
  /** Peripheral CDOG_0 base pointer */
  #define CDOG_0                                   ((CDOG_Type *)CDOG_0_BASE)
  /** Peripheral CDOG_0 base pointer */
  #define CDOG_0_NS                                ((CDOG_Type *)CDOG_0_BASE_NS)
  /** Peripheral CDOG_1 base address */
  #define CDOG_1_BASE                              (0x50130000u)
  /** Peripheral CDOG_1 base address */
  #define CDOG_1_BASE_NS                           (0x40130000u)
  /** Peripheral CDOG_1 base pointer */
  #define CDOG_1                                   ((CDOG_Type *)CDOG_1_BASE)
  /** Peripheral CDOG_1 base pointer */
  #define CDOG_1_NS                                ((CDOG_Type *)CDOG_1_BASE_NS)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG_0_BASE, CDOG_1_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG_0, CDOG_1 }
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS_NS                       { CDOG_0_BASE_NS, CDOG_1_BASE_NS }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS_NS                        { CDOG_0_NS, CDOG_1_NS }
#else
  /** Peripheral CDOG_0 base address */
  #define CDOG_0_BASE                              (0x400B8000u)
  /** Peripheral CDOG_0 base pointer */
  #define CDOG_0                                   ((CDOG_Type *)CDOG_0_BASE)
  /** Peripheral CDOG_1 base address */
  #define CDOG_1_BASE                              (0x40130000u)
  /** Peripheral CDOG_1 base pointer */
  #define CDOG_1                                   ((CDOG_Type *)CDOG_1_BASE)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG_0_BASE, CDOG_1_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG_0, CDOG_1 }
#endif
/** Interrupt vectors for the CDOG peripheral type */
#define CDOG_IRQS                                { CDOG0_IRQn, CDOG1_IRQn }

/* CIU2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CIU2 base address */
  #define CIU2_BASE                                (0x5010A000u)
  /** Peripheral CIU2 base address */
  #define CIU2_BASE_NS                             (0x4010A000u)
  /** Peripheral CIU2 base pointer */
  #define CIU2                                     ((CIU2_Type *)CIU2_BASE)
  /** Peripheral CIU2 base pointer */
  #define CIU2_NS                                  ((CIU2_Type *)CIU2_BASE_NS)
  /** Array initializer of CIU2 peripheral base addresses */
  #define CIU2_BASE_ADDRS                          { CIU2_BASE }
  /** Array initializer of CIU2 peripheral base pointers */
  #define CIU2_BASE_PTRS                           { CIU2 }
  /** Array initializer of CIU2 peripheral base addresses */
  #define CIU2_BASE_ADDRS_NS                       { CIU2_BASE_NS }
  /** Array initializer of CIU2 peripheral base pointers */
  #define CIU2_BASE_PTRS_NS                        { CIU2_NS }
#else
  /** Peripheral CIU2 base address */
  #define CIU2_BASE                                (0x4010A000u)
  /** Peripheral CIU2 base pointer */
  #define CIU2                                     ((CIU2_Type *)CIU2_BASE)
  /** Array initializer of CIU2 peripheral base addresses */
  #define CIU2_BASE_ADDRS                          { CIU2_BASE }
  /** Array initializer of CIU2 peripheral base pointers */
  #define CIU2_BASE_PTRS                           { CIU2 }
#endif

/* CMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMC_0 base address */
  #define CMC_0_BASE                               (0x50181000u)
  /** Peripheral CMC_0 base address */
  #define CMC_0_BASE_NS                            (0x40181000u)
  /** Peripheral CMC_0 base pointer */
  #define CMC_0                                    ((CMC_Type *)CMC_0_BASE)
  /** Peripheral CMC_0 base pointer */
  #define CMC_0_NS                                 ((CMC_Type *)CMC_0_BASE_NS)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_0_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC_0 }
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS_NS                        { CMC_0_BASE_NS }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS_NS                         { CMC_0_NS }
#else
  /** Peripheral CMC_0 base address */
  #define CMC_0_BASE                               (0x40181000u)
  /** Peripheral CMC_0 base pointer */
  #define CMC_0                                    ((CMC_Type *)CMC_0_BASE)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_0_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC_0 }
#endif

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CRC_0 base address */
  #define CRC_0_BASE                               (0x50018000u)
  /** Peripheral CRC_0 base address */
  #define CRC_0_BASE_NS                            (0x40018000u)
  /** Peripheral CRC_0 base pointer */
  #define CRC_0                                    ((CRC_Type *)CRC_0_BASE)
  /** Peripheral CRC_0 base pointer */
  #define CRC_0_NS                                 ((CRC_Type *)CRC_0_BASE_NS)
  /** Peripheral CRC_1 base address */
  #define CRC_1_BASE                               (0x50019000u)
  /** Peripheral CRC_1 base address */
  #define CRC_1_BASE_NS                            (0x40019000u)
  /** Peripheral CRC_1 base pointer */
  #define CRC_1                                    ((CRC_Type *)CRC_1_BASE)
  /** Peripheral CRC_1 base pointer */
  #define CRC_1_NS                                 ((CRC_Type *)CRC_1_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_0_BASE, CRC_1_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC_0, CRC_1 }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { CRC_0_BASE_NS, CRC_1_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { CRC_0_NS, CRC_1_NS }
#else
  /** Peripheral CRC_0 base address */
  #define CRC_0_BASE                               (0x40018000u)
  /** Peripheral CRC_0 base pointer */
  #define CRC_0                                    ((CRC_Type *)CRC_0_BASE)
  /** Peripheral CRC_1 base address */
  #define CRC_1_BASE                               (0x40019000u)
  /** Peripheral CRC_1 base pointer */
  #define CRC_1                                    ((CRC_Type *)CRC_1_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_0_BASE, CRC_1_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC_0, CRC_1 }
#endif

/* DIGTMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TDET_0 base address */
  #define TDET_0_BASE                              (0x501A2000u)
  /** Peripheral TDET_0 base address */
  #define TDET_0_BASE_NS                           (0x401A2000u)
  /** Peripheral TDET_0 base pointer */
  #define TDET_0                                   ((DIGTMP_Type *)TDET_0_BASE)
  /** Peripheral TDET_0 base pointer */
  #define TDET_0_NS                                ((DIGTMP_Type *)TDET_0_BASE_NS)
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS                        { TDET_0_BASE }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS                         { TDET_0 }
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS_NS                     { TDET_0_BASE_NS }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS_NS                      { TDET_0_NS }
#else
  /** Peripheral TDET_0 base address */
  #define TDET_0_BASE                              (0x401A2000u)
  /** Peripheral TDET_0 base pointer */
  #define TDET_0                                   ((DIGTMP_Type *)TDET_0_BASE)
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS                        { TDET_0_BASE }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS                         { TDET_0 }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x501A4000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x401A4000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA0 base pointer */
  #define DMA0_NS                                  ((DMA_Type *)DMA0_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { DMA0_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { DMA0_NS }
#else
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x401A4000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA0_CH0_IRQn, DMA0_CH1_IRQn, DMA0_CH2_IRQn, DMA0_CH3_IRQn, DMA0_CH4_IRQn, DMA0_CH5_IRQn, DMA0_CH6_IRQn, DMA0_CH7_IRQn, DMA0_CH8_IRQn, DMA0_CH9_IRQn, DMA0_CH10_IRQn, DMA0_CH11_IRQn, DMA0_CH12_IRQn, DMA0_CH13_IRQn, DMA0_CH14_IRQn, DMA0_CH15_IRQn } }

/* DSB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DSB_0 base address */
  #define DSB_0_BASE                               (0x50204000u)
  /** Peripheral DSB_0 base address */
  #define DSB_0_BASE_NS                            (0x40204000u)
  /** Peripheral DSB_0 base pointer */
  #define DSB_0                                    ((DSB_Type *)DSB_0_BASE)
  /** Peripheral DSB_0 base pointer */
  #define DSB_0_NS                                 ((DSB_Type *)DSB_0_BASE_NS)
  /** Array initializer of DSB peripheral base addresses */
  #define DSB_BASE_ADDRS                           { DSB_0_BASE }
  /** Array initializer of DSB peripheral base pointers */
  #define DSB_BASE_PTRS                            { DSB_0 }
  /** Array initializer of DSB peripheral base addresses */
  #define DSB_BASE_ADDRS_NS                        { DSB_0_BASE_NS }
  /** Array initializer of DSB peripheral base pointers */
  #define DSB_BASE_PTRS_NS                         { DSB_0_NS }
#else
  /** Peripheral DSB_0 base address */
  #define DSB_0_BASE                               (0x40204000u)
  /** Peripheral DSB_0 base pointer */
  #define DSB_0                                    ((DSB_Type *)DSB_0_BASE)
  /** Array initializer of DSB peripheral base addresses */
  #define DSB_BASE_ADDRS                           { DSB_0_BASE }
  /** Array initializer of DSB peripheral base pointers */
  #define DSB_BASE_PTRS                            { DSB_0 }
#endif

/* EWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EWM_0 base address */
  #define EWM_0_BASE                               (0x5019C000u)
  /** Peripheral EWM_0 base address */
  #define EWM_0_BASE_NS                            (0x4019C000u)
  /** Peripheral EWM_0 base pointer */
  #define EWM_0                                    ((EWM_Type *)EWM_0_BASE)
  /** Peripheral EWM_0 base pointer */
  #define EWM_0_NS                                 ((EWM_Type *)EWM_0_BASE_NS)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM_0_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM_0 }
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS_NS                        { EWM_0_BASE_NS }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS_NS                         { EWM_0_NS }
#else
  /** Peripheral EWM_0 base address */
  #define EWM_0_BASE                               (0x4019C000u)
  /** Peripheral EWM_0 base pointer */
  #define EWM_0                                    ((EWM_Type *)EWM_0_BASE)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM_0_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM_0 }
#endif
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM0_IRQn }

/* FLASH_ARB_WRAP_SYN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLASH_ARB_WRAP_SYN base address */
  #define FLASH_ARB_WRAP_SYN_BASE                  (0x5001C000u)
  /** Peripheral FLASH_ARB_WRAP_SYN base address */
  #define FLASH_ARB_WRAP_SYN_BASE_NS               (0x4001C000u)
  /** Peripheral FLASH_ARB_WRAP_SYN base pointer */
  #define FLASH_ARB_WRAP_SYN                       ((FLASH_ARB_WRAP_SYN_Type *)FLASH_ARB_WRAP_SYN_BASE)
  /** Peripheral FLASH_ARB_WRAP_SYN base pointer */
  #define FLASH_ARB_WRAP_SYN_NS                    ((FLASH_ARB_WRAP_SYN_Type *)FLASH_ARB_WRAP_SYN_BASE_NS)
  /** Array initializer of FLASH_ARB_WRAP_SYN peripheral base addresses */
  #define FLASH_ARB_WRAP_SYN_BASE_ADDRS            { FLASH_ARB_WRAP_SYN_BASE }
  /** Array initializer of FLASH_ARB_WRAP_SYN peripheral base pointers */
  #define FLASH_ARB_WRAP_SYN_BASE_PTRS             { FLASH_ARB_WRAP_SYN }
  /** Array initializer of FLASH_ARB_WRAP_SYN peripheral base addresses */
  #define FLASH_ARB_WRAP_SYN_BASE_ADDRS_NS         { FLASH_ARB_WRAP_SYN_BASE_NS }
  /** Array initializer of FLASH_ARB_WRAP_SYN peripheral base pointers */
  #define FLASH_ARB_WRAP_SYN_BASE_PTRS_NS          { FLASH_ARB_WRAP_SYN_NS }
#else
  /** Peripheral FLASH_ARB_WRAP_SYN base address */
  #define FLASH_ARB_WRAP_SYN_BASE                  (0x4001C000u)
  /** Peripheral FLASH_ARB_WRAP_SYN base pointer */
  #define FLASH_ARB_WRAP_SYN                       ((FLASH_ARB_WRAP_SYN_Type *)FLASH_ARB_WRAP_SYN_BASE)
  /** Array initializer of FLASH_ARB_WRAP_SYN peripheral base addresses */
  #define FLASH_ARB_WRAP_SYN_BASE_ADDRS            { FLASH_ARB_WRAP_SYN_BASE }
  /** Array initializer of FLASH_ARB_WRAP_SYN peripheral base pointers */
  #define FLASH_ARB_WRAP_SYN_BASE_PTRS             { FLASH_ARB_WRAP_SYN }
#endif

/* FMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMU base address */
  #define FMU_BASE                                 (0x50017000u)
  /** Peripheral FMU base address */
  #define FMU_BASE_NS                              (0x40017000u)
  /** Peripheral FMU base pointer */
  #define FMU                                      ((FMU_Type *)FMU_BASE)
  /** Peripheral FMU base pointer */
  #define FMU_NS                                   ((FMU_Type *)FMU_BASE_NS)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU }
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS_NS                        { FMU_BASE_NS }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS_NS                         { FMU_NS }
#else
  /** Peripheral FMU base address */
  #define FMU_BASE                                 (0x40017000u)
  /** Peripheral FMU base pointer */
  #define FMU                                      ((FMU_Type *)FMU_BASE)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU }
#endif

/* FRO200M - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FRO200M base address */
  #define FRO200M_BASE                             (0x50024000u)
  /** Peripheral FRO200M base address */
  #define FRO200M_BASE_NS                          (0x40024000u)
  /** Peripheral FRO200M base pointer */
  #define FRO200M                                  ((FRO200M_Type *)FRO200M_BASE)
  /** Peripheral FRO200M base pointer */
  #define FRO200M_NS                               ((FRO200M_Type *)FRO200M_BASE_NS)
  /** Array initializer of FRO200M peripheral base addresses */
  #define FRO200M_BASE_ADDRS                       { FRO200M_BASE }
  /** Array initializer of FRO200M peripheral base pointers */
  #define FRO200M_BASE_PTRS                        { FRO200M }
  /** Array initializer of FRO200M peripheral base addresses */
  #define FRO200M_BASE_ADDRS_NS                    { FRO200M_BASE_NS }
  /** Array initializer of FRO200M peripheral base pointers */
  #define FRO200M_BASE_PTRS_NS                     { FRO200M_NS }
#else
  /** Peripheral FRO200M base address */
  #define FRO200M_BASE                             (0x40024000u)
  /** Peripheral FRO200M base pointer */
  #define FRO200M                                  ((FRO200M_Type *)FRO200M_BASE)
  /** Array initializer of FRO200M peripheral base addresses */
  #define FRO200M_BASE_ADDRS                       { FRO200M_BASE }
  /** Array initializer of FRO200M peripheral base pointers */
  #define FRO200M_BASE_PTRS                        { FRO200M }
#endif

/* GDET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DGDET0 base address */
  #define DGDET0_BASE                              (0x50039000u)
  /** Peripheral DGDET0 base address */
  #define DGDET0_BASE_NS                           (0x40039000u)
  /** Peripheral DGDET0 base pointer */
  #define DGDET0                                   ((GDET_Type *)DGDET0_BASE)
  /** Peripheral DGDET0 base pointer */
  #define DGDET0_NS                                ((GDET_Type *)DGDET0_BASE_NS)
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS                          { DGDET0_BASE }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS                           { DGDET0 }
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS_NS                       { DGDET0_BASE_NS }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS_NS                        { DGDET0_NS }
#else
  /** Peripheral DGDET0 base address */
  #define DGDET0_BASE                              (0x40039000u)
  /** Peripheral DGDET0 base pointer */
  #define DGDET0                                   ((GDET_Type *)DGDET0_BASE)
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS                          { DGDET0_BASE }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS                           { DGDET0 }
#endif

/* GEN4PHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_2P4GHZ_PHY base address */
  #define XCVR_2P4GHZ_PHY_BASE                     (0x50107600u)
  /** Peripheral XCVR_2P4GHZ_PHY base address */
  #define XCVR_2P4GHZ_PHY_BASE_NS                  (0x40107600u)
  /** Peripheral XCVR_2P4GHZ_PHY base pointer */
  #define XCVR_2P4GHZ_PHY                          ((GEN4PHY_Type *)XCVR_2P4GHZ_PHY_BASE)
  /** Peripheral XCVR_2P4GHZ_PHY base pointer */
  #define XCVR_2P4GHZ_PHY_NS                       ((GEN4PHY_Type *)XCVR_2P4GHZ_PHY_BASE_NS)
  /** Array initializer of GEN4PHY peripheral base addresses */
  #define GEN4PHY_BASE_ADDRS                       { XCVR_2P4GHZ_PHY_BASE }
  /** Array initializer of GEN4PHY peripheral base pointers */
  #define GEN4PHY_BASE_PTRS                        { XCVR_2P4GHZ_PHY }
  /** Array initializer of GEN4PHY peripheral base addresses */
  #define GEN4PHY_BASE_ADDRS_NS                    { XCVR_2P4GHZ_PHY_BASE_NS }
  /** Array initializer of GEN4PHY peripheral base pointers */
  #define GEN4PHY_BASE_PTRS_NS                     { XCVR_2P4GHZ_PHY_NS }
#else
  /** Peripheral XCVR_2P4GHZ_PHY base address */
  #define XCVR_2P4GHZ_PHY_BASE                     (0x40107600u)
  /** Peripheral XCVR_2P4GHZ_PHY base pointer */
  #define XCVR_2P4GHZ_PHY                          ((GEN4PHY_Type *)XCVR_2P4GHZ_PHY_BASE)
  /** Array initializer of GEN4PHY peripheral base addresses */
  #define GEN4PHY_BASE_ADDRS                       { XCVR_2P4GHZ_PHY_BASE }
  /** Array initializer of GEN4PHY peripheral base pointers */
  #define GEN4PHY_BASE_PTRS                        { XCVR_2P4GHZ_PHY }
#endif

/* GENFSK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GENFSK base address */
  #define GENFSK_BASE                              (0x50102000u)
  /** Peripheral GENFSK base address */
  #define GENFSK_BASE_NS                           (0x40102000u)
  /** Peripheral GENFSK base pointer */
  #define GENFSK                                   ((GENFSK_Type *)GENFSK_BASE)
  /** Peripheral GENFSK base pointer */
  #define GENFSK_NS                                ((GENFSK_Type *)GENFSK_BASE_NS)
  /** Array initializer of GENFSK peripheral base addresses */
  #define GENFSK_BASE_ADDRS                        { GENFSK_BASE }
  /** Array initializer of GENFSK peripheral base pointers */
  #define GENFSK_BASE_PTRS                         { GENFSK }
  /** Array initializer of GENFSK peripheral base addresses */
  #define GENFSK_BASE_ADDRS_NS                     { GENFSK_BASE_NS }
  /** Array initializer of GENFSK peripheral base pointers */
  #define GENFSK_BASE_PTRS_NS                      { GENFSK_NS }
#else
  /** Peripheral GENFSK base address */
  #define GENFSK_BASE                              (0x40102000u)
  /** Peripheral GENFSK base pointer */
  #define GENFSK                                   ((GENFSK_Type *)GENFSK_BASE)
  /** Array initializer of GENFSK peripheral base addresses */
  #define GENFSK_BASE_ADDRS                        { GENFSK_BASE }
  /** Array initializer of GENFSK peripheral base pointers */
  #define GENFSK_BASE_PTRS                         { GENFSK }
#endif

/* GLIKEY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GLIKEY base address */
  #define GLIKEY_BASE                              (0x5019FD00u)
  /** Peripheral GLIKEY base address */
  #define GLIKEY_BASE_NS                           (0x4019FD00u)
  /** Peripheral GLIKEY base pointer */
  #define GLIKEY                                   ((GLIKEY_Type *)GLIKEY_BASE)
  /** Peripheral GLIKEY base pointer */
  #define GLIKEY_NS                                ((GLIKEY_Type *)GLIKEY_BASE_NS)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { GLIKEY_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY }
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS_NS                     { GLIKEY_BASE_NS }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS_NS                      { GLIKEY_NS }
#else
  /** Peripheral GLIKEY base address */
  #define GLIKEY_BASE                              (0x4019FD00u)
  /** Peripheral GLIKEY base pointer */
  #define GLIKEY                                   ((GLIKEY_Type *)GLIKEY_BASE)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { GLIKEY_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY }
#endif

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO_A base address */
  #define GPIO_A_BASE                              (0x500C0000u)
  /** Peripheral GPIO_A base address */
  #define GPIO_A_BASE_NS                           (0x400C0000u)
  /** Peripheral GPIO_A base pointer */
  #define GPIO_A                                   ((GPIO_Type *)GPIO_A_BASE)
  /** Peripheral GPIO_A base pointer */
  #define GPIO_A_NS                                ((GPIO_Type *)GPIO_A_BASE_NS)
  /** Peripheral GPIO_B base address */
  #define GPIO_B_BASE                              (0x50090000u)
  /** Peripheral GPIO_B base address */
  #define GPIO_B_BASE_NS                           (0x40090000u)
  /** Peripheral GPIO_B base pointer */
  #define GPIO_B                                   ((GPIO_Type *)GPIO_B_BASE)
  /** Peripheral GPIO_B base pointer */
  #define GPIO_B_NS                                ((GPIO_Type *)GPIO_B_BASE_NS)
  /** Peripheral GPIO_C base address */
  #define GPIO_C_BASE                              (0x500A0000u)
  /** Peripheral GPIO_C base address */
  #define GPIO_C_BASE_NS                           (0x400A0000u)
  /** Peripheral GPIO_C base pointer */
  #define GPIO_C                                   ((GPIO_Type *)GPIO_C_BASE)
  /** Peripheral GPIO_C base pointer */
  #define GPIO_C_NS                                ((GPIO_Type *)GPIO_C_BASE_NS)
  /** Peripheral GPIO_D base address */
  #define GPIO_D_BASE                              (0x50196000u)
  /** Peripheral GPIO_D base address */
  #define GPIO_D_BASE_NS                           (0x40196000u)
  /** Peripheral GPIO_D base pointer */
  #define GPIO_D                                   ((GPIO_Type *)GPIO_D_BASE)
  /** Peripheral GPIO_D base pointer */
  #define GPIO_D_NS                                ((GPIO_Type *)GPIO_D_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO_A_BASE, GPIO_B_BASE, GPIO_C_BASE, GPIO_D_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO_A, GPIO_B, GPIO_C, GPIO_D }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { GPIO_A_BASE_NS, GPIO_B_BASE_NS, GPIO_C_BASE_NS, GPIO_D_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { GPIO_A_NS, GPIO_B_NS, GPIO_C_NS, GPIO_D_NS }
#else
  /** Peripheral GPIO_A base address */
  #define GPIO_A_BASE                              (0x400C0000u)
  /** Peripheral GPIO_A base pointer */
  #define GPIO_A                                   ((GPIO_Type *)GPIO_A_BASE)
  /** Peripheral GPIO_B base address */
  #define GPIO_B_BASE                              (0x40090000u)
  /** Peripheral GPIO_B base pointer */
  #define GPIO_B                                   ((GPIO_Type *)GPIO_B_BASE)
  /** Peripheral GPIO_C base address */
  #define GPIO_C_BASE                              (0x400A0000u)
  /** Peripheral GPIO_C base pointer */
  #define GPIO_C                                   ((GPIO_Type *)GPIO_C_BASE)
  /** Peripheral GPIO_D base address */
  #define GPIO_D_BASE                              (0x40196000u)
  /** Peripheral GPIO_D base pointer */
  #define GPIO_D                                   ((GPIO_Type *)GPIO_D_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO_A_BASE, GPIO_B_BASE, GPIO_C_BASE, GPIO_D_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO_A, GPIO_B, GPIO_C, GPIO_D }
#endif

/* INTM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral INTM_0 base address */
  #define INTM_0_BASE                              (0x50200000u)
  /** Peripheral INTM_0 base address */
  #define INTM_0_BASE_NS                           (0x40200000u)
  /** Peripheral INTM_0 base pointer */
  #define INTM_0                                   ((INTM_Type *)INTM_0_BASE)
  /** Peripheral INTM_0 base pointer */
  #define INTM_0_NS                                ((INTM_Type *)INTM_0_BASE_NS)
  /** Array initializer of INTM peripheral base addresses */
  #define INTM_BASE_ADDRS                          { INTM_0_BASE }
  /** Array initializer of INTM peripheral base pointers */
  #define INTM_BASE_PTRS                           { INTM_0 }
  /** Array initializer of INTM peripheral base addresses */
  #define INTM_BASE_ADDRS_NS                       { INTM_0_BASE_NS }
  /** Array initializer of INTM peripheral base pointers */
  #define INTM_BASE_PTRS_NS                        { INTM_0_NS }
#else
  /** Peripheral INTM_0 base address */
  #define INTM_0_BASE                              (0x40200000u)
  /** Peripheral INTM_0 base pointer */
  #define INTM_0                                   ((INTM_Type *)INTM_0_BASE)
  /** Array initializer of INTM peripheral base addresses */
  #define INTM_BASE_ADDRS                          { INTM_0_BASE }
  /** Array initializer of INTM peripheral base pointers */
  #define INTM_BASE_PTRS                           { INTM_0 }
#endif

/* ISP_AP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ISP_AP_0 base address */
  #define ISP_AP_0_BASE                            (0x50080000u)
  /** Peripheral ISP_AP_0 base address */
  #define ISP_AP_0_BASE_NS                         (0x40080000u)
  /** Peripheral ISP_AP_0 base pointer */
  #define ISP_AP_0                                 ((ISP_AP_Type *)ISP_AP_0_BASE)
  /** Peripheral ISP_AP_0 base pointer */
  #define ISP_AP_0_NS                              ((ISP_AP_Type *)ISP_AP_0_BASE_NS)
  /** Array initializer of ISP_AP peripheral base addresses */
  #define ISP_AP_BASE_ADDRS                        { ISP_AP_0_BASE }
  /** Array initializer of ISP_AP peripheral base pointers */
  #define ISP_AP_BASE_PTRS                         { ISP_AP_0 }
  /** Array initializer of ISP_AP peripheral base addresses */
  #define ISP_AP_BASE_ADDRS_NS                     { ISP_AP_0_BASE_NS }
  /** Array initializer of ISP_AP peripheral base pointers */
  #define ISP_AP_BASE_PTRS_NS                      { ISP_AP_0_NS }
#else
  /** Peripheral ISP_AP_0 base address */
  #define ISP_AP_0_BASE                            (0x40080000u)
  /** Peripheral ISP_AP_0 base pointer */
  #define ISP_AP_0                                 ((ISP_AP_Type *)ISP_AP_0_BASE)
  /** Array initializer of ISP_AP peripheral base addresses */
  #define ISP_AP_BASE_ADDRS                        { ISP_AP_0_BASE }
  /** Array initializer of ISP_AP peripheral base pointers */
  #define ISP_AP_BASE_PTRS                         { ISP_AP_0 }
#endif

/* ITRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ITRC_0 base address */
  #define ITRC_0_BASE                              (0x50016000u)
  /** Peripheral ITRC_0 base address */
  #define ITRC_0_BASE_NS                           (0x40016000u)
  /** Peripheral ITRC_0 base pointer */
  #define ITRC_0                                   ((ITRC_Type *)ITRC_0_BASE)
  /** Peripheral ITRC_0 base pointer */
  #define ITRC_0_NS                                ((ITRC_Type *)ITRC_0_BASE_NS)
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS                          { ITRC_0_BASE }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS                           { ITRC_0 }
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS_NS                       { ITRC_0_BASE_NS }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS_NS                        { ITRC_0_NS }
#else
  /** Peripheral ITRC_0 base address */
  #define ITRC_0_BASE                              (0x40016000u)
  /** Peripheral ITRC_0 base pointer */
  #define ITRC_0                                   ((ITRC_Type *)ITRC_0_BASE)
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS                          { ITRC_0_BASE }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS                           { ITRC_0 }
#endif

/* LPCMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMP_0 base address */
  #define CMP_0_BASE                               (0x50030000u)
  /** Peripheral CMP_0 base address */
  #define CMP_0_BASE_NS                            (0x40030000u)
  /** Peripheral CMP_0 base pointer */
  #define CMP_0                                    ((LPCMP_Type *)CMP_0_BASE)
  /** Peripheral CMP_0 base pointer */
  #define CMP_0_NS                                 ((LPCMP_Type *)CMP_0_BASE_NS)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { CMP_0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { CMP_0 }
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS_NS                      { CMP_0_BASE_NS }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS_NS                       { CMP_0_NS }
#else
  /** Peripheral CMP_0 base address */
  #define CMP_0_BASE                               (0x40030000u)
  /** Peripheral CMP_0 base pointer */
  #define CMP_0                                    ((LPCMP_Type *)CMP_0_BASE)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { CMP_0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { CMP_0 }
#endif

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C_0 base address */
  #define LPI2C_0_BASE                             (0x501A0000u)
  /** Peripheral LPI2C_0 base address */
  #define LPI2C_0_BASE_NS                          (0x401A0000u)
  /** Peripheral LPI2C_0 base pointer */
  #define LPI2C_0                                  ((LPI2C_Type *)LPI2C_0_BASE)
  /** Peripheral LPI2C_0 base pointer */
  #define LPI2C_0_NS                               ((LPI2C_Type *)LPI2C_0_BASE_NS)
  /** Peripheral LPI2C_1 base address */
  #define LPI2C_1_BASE                             (0x5002C000u)
  /** Peripheral LPI2C_1 base address */
  #define LPI2C_1_BASE_NS                          (0x4002C000u)
  /** Peripheral LPI2C_1 base pointer */
  #define LPI2C_1                                  ((LPI2C_Type *)LPI2C_1_BASE)
  /** Peripheral LPI2C_1 base pointer */
  #define LPI2C_1_NS                               ((LPI2C_Type *)LPI2C_1_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C_0_BASE, LPI2C_1_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C_0, LPI2C_1 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { LPI2C_0_BASE_NS, LPI2C_1_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { LPI2C_0_NS, LPI2C_1_NS }
#else
  /** Peripheral LPI2C_0 base address */
  #define LPI2C_0_BASE                             (0x401A0000u)
  /** Peripheral LPI2C_0 base pointer */
  #define LPI2C_0                                  ((LPI2C_Type *)LPI2C_0_BASE)
  /** Peripheral LPI2C_1 base address */
  #define LPI2C_1_BASE                             (0x4002C000u)
  /** Peripheral LPI2C_1 base pointer */
  #define LPI2C_1                                  ((LPI2C_Type *)LPI2C_1_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C_0_BASE, LPI2C_1_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C_0, LPI2C_1 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn }

/* LPIT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPIT_0 base address */
  #define LPIT_0_BASE                              (0x5001D000u)
  /** Peripheral LPIT_0 base address */
  #define LPIT_0_BASE_NS                           (0x4001D000u)
  /** Peripheral LPIT_0 base pointer */
  #define LPIT_0                                   ((LPIT_Type *)LPIT_0_BASE)
  /** Peripheral LPIT_0 base pointer */
  #define LPIT_0_NS                                ((LPIT_Type *)LPIT_0_BASE_NS)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { LPIT_0_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { LPIT_0 }
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS_NS                       { LPIT_0_BASE_NS }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS_NS                        { LPIT_0_NS }
#else
  /** Peripheral LPIT_0 base address */
  #define LPIT_0_BASE                              (0x4001D000u)
  /** Peripheral LPIT_0 base pointer */
  #define LPIT_0                                   ((LPIT_Type *)LPIT_0_BASE)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { LPIT_0_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { LPIT_0 }
#endif
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn } }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI_0 base address */
  #define LPSPI_0_BASE                             (0x50183000u)
  /** Peripheral LPSPI_0 base address */
  #define LPSPI_0_BASE_NS                          (0x40183000u)
  /** Peripheral LPSPI_0 base pointer */
  #define LPSPI_0                                  ((LPSPI_Type *)LPSPI_0_BASE)
  /** Peripheral LPSPI_0 base pointer */
  #define LPSPI_0_NS                               ((LPSPI_Type *)LPSPI_0_BASE_NS)
  /** Peripheral LPSPI_1 base address */
  #define LPSPI_1_BASE                             (0x50025000u)
  /** Peripheral LPSPI_1 base address */
  #define LPSPI_1_BASE_NS                          (0x40025000u)
  /** Peripheral LPSPI_1 base pointer */
  #define LPSPI_1                                  ((LPSPI_Type *)LPSPI_1_BASE)
  /** Peripheral LPSPI_1 base pointer */
  #define LPSPI_1_NS                               ((LPSPI_Type *)LPSPI_1_BASE_NS)
  /** Peripheral LPSPI_2 base address */
  #define LPSPI_2_BASE                             (0x50026000u)
  /** Peripheral LPSPI_2 base address */
  #define LPSPI_2_BASE_NS                          (0x40026000u)
  /** Peripheral LPSPI_2 base pointer */
  #define LPSPI_2                                  ((LPSPI_Type *)LPSPI_2_BASE)
  /** Peripheral LPSPI_2 base pointer */
  #define LPSPI_2_NS                               ((LPSPI_Type *)LPSPI_2_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI_0_BASE, LPSPI_1_BASE, LPSPI_2_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI_0, LPSPI_1, LPSPI_2 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { LPSPI_0_BASE_NS, LPSPI_1_BASE_NS, LPSPI_2_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { LPSPI_0_NS, LPSPI_1_NS, LPSPI_2_NS }
#else
  /** Peripheral LPSPI_0 base address */
  #define LPSPI_0_BASE                             (0x40183000u)
  /** Peripheral LPSPI_0 base pointer */
  #define LPSPI_0                                  ((LPSPI_Type *)LPSPI_0_BASE)
  /** Peripheral LPSPI_1 base address */
  #define LPSPI_1_BASE                             (0x40025000u)
  /** Peripheral LPSPI_1 base pointer */
  #define LPSPI_1                                  ((LPSPI_Type *)LPSPI_1_BASE)
  /** Peripheral LPSPI_2 base address */
  #define LPSPI_2_BASE                             (0x40026000u)
  /** Peripheral LPSPI_2 base pointer */
  #define LPSPI_2                                  ((LPSPI_Type *)LPSPI_2_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI_0_BASE, LPSPI_1_BASE, LPSPI_2_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI_0, LPSPI_1, LPSPI_2 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPTMR_0 base address */
  #define LPTMR_0_BASE                             (0x50185000u)
  /** Peripheral LPTMR_0 base address */
  #define LPTMR_0_BASE_NS                          (0x40185000u)
  /** Peripheral LPTMR_0 base pointer */
  #define LPTMR_0                                  ((LPTMR_Type *)LPTMR_0_BASE)
  /** Peripheral LPTMR_0 base pointer */
  #define LPTMR_0_NS                               ((LPTMR_Type *)LPTMR_0_BASE_NS)
  /** Peripheral LPTMR_1 base address */
  #define LPTMR_1_BASE                             (0x50186000u)
  /** Peripheral LPTMR_1 base address */
  #define LPTMR_1_BASE_NS                          (0x40186000u)
  /** Peripheral LPTMR_1 base pointer */
  #define LPTMR_1                                  ((LPTMR_Type *)LPTMR_1_BASE)
  /** Peripheral LPTMR_1 base pointer */
  #define LPTMR_1_NS                               ((LPTMR_Type *)LPTMR_1_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR_0_BASE, LPTMR_1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR_0, LPTMR_1 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { LPTMR_0_BASE_NS, LPTMR_1_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { LPTMR_0_NS, LPTMR_1_NS }
#else
  /** Peripheral LPTMR_0 base address */
  #define LPTMR_0_BASE                             (0x40185000u)
  /** Peripheral LPTMR_0 base pointer */
  #define LPTMR_0                                  ((LPTMR_Type *)LPTMR_0_BASE)
  /** Peripheral LPTMR_1 base address */
  #define LPTMR_1_BASE                             (0x40186000u)
  /** Peripheral LPTMR_1 base pointer */
  #define LPTMR_1                                  ((LPTMR_Type *)LPTMR_1_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR_0_BASE, LPTMR_1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR_0, LPTMR_1 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn, LPTMR1_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART_0 base address */
  #define LPUART_0_BASE                            (0x50184000u)
  /** Peripheral LPUART_0 base address */
  #define LPUART_0_BASE_NS                         (0x40184000u)
  /** Peripheral LPUART_0 base pointer */
  #define LPUART_0                                 ((LPUART_Type *)LPUART_0_BASE)
  /** Peripheral LPUART_0 base pointer */
  #define LPUART_0_NS                              ((LPUART_Type *)LPUART_0_BASE_NS)
  /** Peripheral LPUART_1 base address */
  #define LPUART_1_BASE                            (0x50027000u)
  /** Peripheral LPUART_1 base address */
  #define LPUART_1_BASE_NS                         (0x40027000u)
  /** Peripheral LPUART_1 base pointer */
  #define LPUART_1                                 ((LPUART_Type *)LPUART_1_BASE)
  /** Peripheral LPUART_1 base pointer */
  #define LPUART_1_NS                              ((LPUART_Type *)LPUART_1_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART_0_BASE, LPUART_1_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART_0, LPUART_1 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { LPUART_0_BASE_NS, LPUART_1_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { LPUART_0_NS, LPUART_1_NS }
#else
  /** Peripheral LPUART_0 base address */
  #define LPUART_0_BASE                            (0x40184000u)
  /** Peripheral LPUART_0 base pointer */
  #define LPUART_0                                 ((LPUART_Type *)LPUART_0_BASE)
  /** Peripheral LPUART_1 base address */
  #define LPUART_1_BASE                            (0x40027000u)
  /** Peripheral LPUART_1 base pointer */
  #define LPUART_1                                 ((LPUART_Type *)LPUART_1_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART_0_BASE, LPUART_1_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART_0, LPUART_1 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn }

/* LTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LTC base address */
  #define LTC_BASE                                 (0x50106800u)
  /** Peripheral LTC base address */
  #define LTC_BASE_NS                              (0x40106800u)
  /** Peripheral LTC base pointer */
  #define LTC                                      ((LTC_Type *)LTC_BASE)
  /** Peripheral LTC base pointer */
  #define LTC_NS                                   ((LTC_Type *)LTC_BASE_NS)
  /** Array initializer of LTC peripheral base addresses */
  #define LTC_BASE_ADDRS                           { LTC_BASE }
  /** Array initializer of LTC peripheral base pointers */
  #define LTC_BASE_PTRS                            { LTC }
  /** Array initializer of LTC peripheral base addresses */
  #define LTC_BASE_ADDRS_NS                        { LTC_BASE_NS }
  /** Array initializer of LTC peripheral base pointers */
  #define LTC_BASE_PTRS_NS                         { LTC_NS }
#else
  /** Peripheral LTC base address */
  #define LTC_BASE                                 (0x40106800u)
  /** Peripheral LTC base pointer */
  #define LTC                                      ((LTC_Type *)LTC_BASE)
  /** Array initializer of LTC peripheral base addresses */
  #define LTC_BASE_ADDRS                           { LTC_BASE }
  /** Array initializer of LTC peripheral base pointers */
  #define LTC_BASE_PTRS                            { LTC }
#endif

/* MRCC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRCC_0 base address */
  #define MRCC_0_BASE                              (0x501A1000u)
  /** Peripheral MRCC_0 base address */
  #define MRCC_0_BASE_NS                           (0x401A1000u)
  /** Peripheral MRCC_0 base pointer */
  #define MRCC_0                                   ((MRCC_Type *)MRCC_0_BASE)
  /** Peripheral MRCC_0 base pointer */
  #define MRCC_0_NS                                ((MRCC_Type *)MRCC_0_BASE_NS)
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS                          { MRCC_0_BASE }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS                           { MRCC_0 }
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS_NS                       { MRCC_0_BASE_NS }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS_NS                        { MRCC_0_NS }
#else
  /** Peripheral MRCC_0 base address */
  #define MRCC_0_BASE                              (0x401A1000u)
  /** Peripheral MRCC_0 base pointer */
  #define MRCC_0                                   ((MRCC_Type *)MRCC_0_BASE)
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS                          { MRCC_0_BASE }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS                           { MRCC_0 }
#endif

/* MSCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MSCM base address */
  #define MSCM_BASE                                (0x50012000u)
  /** Peripheral MSCM base address */
  #define MSCM_BASE_NS                             (0x40012000u)
  /** Peripheral MSCM base pointer */
  #define MSCM                                     ((MSCM_Type *)MSCM_BASE)
  /** Peripheral MSCM base pointer */
  #define MSCM_NS                                  ((MSCM_Type *)MSCM_BASE_NS)
  /** Array initializer of MSCM peripheral base addresses */
  #define MSCM_BASE_ADDRS                          { MSCM_BASE }
  /** Array initializer of MSCM peripheral base pointers */
  #define MSCM_BASE_PTRS                           { MSCM }
  /** Array initializer of MSCM peripheral base addresses */
  #define MSCM_BASE_ADDRS_NS                       { MSCM_BASE_NS }
  /** Array initializer of MSCM peripheral base pointers */
  #define MSCM_BASE_PTRS_NS                        { MSCM_NS }
#else
  /** Peripheral MSCM base address */
  #define MSCM_BASE                                (0x40012000u)
  /** Peripheral MSCM base pointer */
  #define MSCM                                     ((MSCM_Type *)MSCM_BASE)
  /** Array initializer of MSCM peripheral base addresses */
  #define MSCM_BASE_ADDRS                          { MSCM_BASE }
  /** Array initializer of MSCM peripheral base pointers */
  #define MSCM_BASE_PTRS                           { MSCM }
#endif

/* MSF1_B_test - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TEST base address */
  #define TEST_BASE                                (0x50032000u)
  /** Peripheral TEST base address */
  #define TEST_BASE_NS                             (0x40032000u)
  /** Peripheral TEST base pointer */
  #define TEST                                     ((MSF1_B_test_Type *)TEST_BASE)
  /** Peripheral TEST base pointer */
  #define TEST_NS                                  ((MSF1_B_test_Type *)TEST_BASE_NS)
  /** Array initializer of MSF1_B_test peripheral base addresses */
  #define MSF1_B_test_BASE_ADDRS                   { TEST_BASE }
  /** Array initializer of MSF1_B_test peripheral base pointers */
  #define MSF1_B_test_BASE_PTRS                    { TEST }
  /** Array initializer of MSF1_B_test peripheral base addresses */
  #define MSF1_B_test_BASE_ADDRS_NS                { TEST_BASE_NS }
  /** Array initializer of MSF1_B_test peripheral base pointers */
  #define MSF1_B_test_BASE_PTRS_NS                 { TEST_NS }
#else
  /** Peripheral TEST base address */
  #define TEST_BASE                                (0x40032000u)
  /** Peripheral TEST base pointer */
  #define TEST                                     ((MSF1_B_test_Type *)TEST_BASE)
  /** Array initializer of MSF1_B_test peripheral base addresses */
  #define MSF1_B_test_BASE_ADDRS                   { TEST_BASE }
  /** Array initializer of MSF1_B_test peripheral base pointers */
  #define MSF1_B_test_BASE_PTRS                    { TEST }
#endif

/* MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU_0__MUA base address */
  #define MU_0__MUA_BASE                           (0x50192000u)
  /** Peripheral MU_0__MUA base address */
  #define MU_0__MUA_BASE_NS                        (0x40192000u)
  /** Peripheral MU_0__MUA base pointer */
  #define MU_0__MUA                                ((MU_Type *)MU_0__MUA_BASE)
  /** Peripheral MU_0__MUA base pointer */
  #define MU_0__MUA_NS                             ((MU_Type *)MU_0__MUA_BASE_NS)
  /** Peripheral MU_0__MUB base address */
  #define MU_0__MUB_BASE                           (0x50193000u)
  /** Peripheral MU_0__MUB base address */
  #define MU_0__MUB_BASE_NS                        (0x40193000u)
  /** Peripheral MU_0__MUB base pointer */
  #define MU_0__MUB                                ((MU_Type *)MU_0__MUB_BASE)
  /** Peripheral MU_0__MUB base pointer */
  #define MU_0__MUB_NS                             ((MU_Type *)MU_0__MUB_BASE_NS)
  /** Peripheral MU_1__MUA base address */
  #define MU_1__MUA_BASE                           (0x50037000u)
  /** Peripheral MU_1__MUA base address */
  #define MU_1__MUA_BASE_NS                        (0x40037000u)
  /** Peripheral MU_1__MUA base pointer */
  #define MU_1__MUA                                ((MU_Type *)MU_1__MUA_BASE)
  /** Peripheral MU_1__MUA base pointer */
  #define MU_1__MUA_NS                             ((MU_Type *)MU_1__MUA_BASE_NS)
  /** Peripheral MU_1__MUB base address */
  #define MU_1__MUB_BASE                           (0x50038000u)
  /** Peripheral MU_1__MUB base address */
  #define MU_1__MUB_BASE_NS                        (0x40038000u)
  /** Peripheral MU_1__MUB base pointer */
  #define MU_1__MUB                                ((MU_Type *)MU_1__MUB_BASE)
  /** Peripheral MU_1__MUB base pointer */
  #define MU_1__MUB_NS                             ((MU_Type *)MU_1__MUB_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU_0__MUA_BASE, MU_0__MUB_BASE, MU_1__MUA_BASE, MU_1__MUB_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU_0__MUA, MU_0__MUB, MU_1__MUA, MU_1__MUB }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU_0__MUA_BASE_NS, MU_0__MUB_BASE_NS, MU_1__MUA_BASE_NS, MU_1__MUB_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU_0__MUA_NS, MU_0__MUB_NS, MU_1__MUA_NS, MU_1__MUB_NS }
#else
  /** Peripheral MU_0__MUA base address */
  #define MU_0__MUA_BASE                           (0x40192000u)
  /** Peripheral MU_0__MUA base pointer */
  #define MU_0__MUA                                ((MU_Type *)MU_0__MUA_BASE)
  /** Peripheral MU_0__MUB base address */
  #define MU_0__MUB_BASE                           (0x40193000u)
  /** Peripheral MU_0__MUB base pointer */
  #define MU_0__MUB                                ((MU_Type *)MU_0__MUB_BASE)
  /** Peripheral MU_1__MUA base address */
  #define MU_1__MUA_BASE                           (0x40037000u)
  /** Peripheral MU_1__MUA base pointer */
  #define MU_1__MUA                                ((MU_Type *)MU_1__MUA_BASE)
  /** Peripheral MU_1__MUB base address */
  #define MU_1__MUB_BASE                           (0x40038000u)
  /** Peripheral MU_1__MUB base pointer */
  #define MU_1__MUB                                ((MU_Type *)MU_1__MUB_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU_0__MUA_BASE, MU_0__MUB_BASE, MU_1__MUA_BASE, MU_1__MUB_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU_0__MUA, MU_0__MUB, MU_1__MUA, MU_1__MUB }
#endif

/* PKC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PKC base address */
  #define PKC_BASE                                 (0x50023000u)
  /** Peripheral PKC base address */
  #define PKC_BASE_NS                              (0x40023000u)
  /** Peripheral PKC base pointer */
  #define PKC                                      ((PKC_Type *)PKC_BASE)
  /** Peripheral PKC base pointer */
  #define PKC_NS                                   ((PKC_Type *)PKC_BASE_NS)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC }
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS_NS                        { PKC_BASE_NS }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS_NS                         { PKC_NS }
#else
  /** Peripheral PKC base address */
  #define PKC_BASE                                 (0x40023000u)
  /** Peripheral PKC base pointer */
  #define PKC                                      ((PKC_Type *)PKC_BASE)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC }
#endif

/* PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PORT_A base address */
  #define PORT_A_BASE                              (0x50197000u)
  /** Peripheral PORT_A base address */
  #define PORT_A_BASE_NS                           (0x40197000u)
  /** Peripheral PORT_A base pointer */
  #define PORT_A                                   ((PORT_Type *)PORT_A_BASE)
  /** Peripheral PORT_A base pointer */
  #define PORT_A_NS                                ((PORT_Type *)PORT_A_BASE_NS)
  /** Peripheral PORT_B base address */
  #define PORT_B_BASE                              (0x5002D000u)
  /** Peripheral PORT_B base address */
  #define PORT_B_BASE_NS                           (0x4002D000u)
  /** Peripheral PORT_B base pointer */
  #define PORT_B                                   ((PORT_Type *)PORT_B_BASE)
  /** Peripheral PORT_B base pointer */
  #define PORT_B_NS                                ((PORT_Type *)PORT_B_BASE_NS)
  /** Peripheral PORT_C base address */
  #define PORT_C_BASE                              (0x5002E000u)
  /** Peripheral PORT_C base address */
  #define PORT_C_BASE_NS                           (0x4002E000u)
  /** Peripheral PORT_C base pointer */
  #define PORT_C                                   ((PORT_Type *)PORT_C_BASE)
  /** Peripheral PORT_C base pointer */
  #define PORT_C_NS                                ((PORT_Type *)PORT_C_BASE_NS)
  /** Peripheral PORT_D base address */
  #define PORT_D_BASE                              (0x50195000u)
  /** Peripheral PORT_D base address */
  #define PORT_D_BASE_NS                           (0x40195000u)
  /** Peripheral PORT_D base pointer */
  #define PORT_D                                   ((PORT_Type *)PORT_D_BASE)
  /** Peripheral PORT_D base pointer */
  #define PORT_D_NS                                ((PORT_Type *)PORT_D_BASE_NS)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { PORT_A_BASE, PORT_B_BASE, PORT_C_BASE, PORT_D_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { PORT_A, PORT_B, PORT_C, PORT_D }
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS_NS                       { PORT_A_BASE_NS, PORT_B_BASE_NS, PORT_C_BASE_NS, PORT_D_BASE_NS }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS_NS                        { PORT_A_NS, PORT_B_NS, PORT_C_NS, PORT_D_NS }
#else
  /** Peripheral PORT_A base address */
  #define PORT_A_BASE                              (0x40197000u)
  /** Peripheral PORT_A base pointer */
  #define PORT_A                                   ((PORT_Type *)PORT_A_BASE)
  /** Peripheral PORT_B base address */
  #define PORT_B_BASE                              (0x4002D000u)
  /** Peripheral PORT_B base pointer */
  #define PORT_B                                   ((PORT_Type *)PORT_B_BASE)
  /** Peripheral PORT_C base address */
  #define PORT_C_BASE                              (0x4002E000u)
  /** Peripheral PORT_C base pointer */
  #define PORT_C                                   ((PORT_Type *)PORT_C_BASE)
  /** Peripheral PORT_D base address */
  #define PORT_D_BASE                              (0x40195000u)
  /** Peripheral PORT_D base pointer */
  #define PORT_D                                   ((PORT_Type *)PORT_D_BASE)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { PORT_A_BASE, PORT_B_BASE, PORT_C_BASE, PORT_D_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { PORT_A, PORT_B, PORT_C, PORT_D }
#endif

/* PPB_MCM2_CM4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PPB_MCM2_CM4 base address */
  #define PPB_MCM2_CM4_BASE                        (0xF0080000u)
  /** Peripheral PPB_MCM2_CM4 base address */
  #define PPB_MCM2_CM4_BASE_NS                     (0xE0080000u)
  /** Peripheral PPB_MCM2_CM4 base pointer */
  #define PPB_MCM2_CM4                             ((PPB_MCM2_CM4_Type *)PPB_MCM2_CM4_BASE)
  /** Peripheral PPB_MCM2_CM4 base pointer */
  #define PPB_MCM2_CM4_NS                          ((PPB_MCM2_CM4_Type *)PPB_MCM2_CM4_BASE_NS)
  /** Array initializer of PPB_MCM2_CM4 peripheral base addresses */
  #define PPB_MCM2_CM4_BASE_ADDRS                  { PPB_MCM2_CM4_BASE }
  /** Array initializer of PPB_MCM2_CM4 peripheral base pointers */
  #define PPB_MCM2_CM4_BASE_PTRS                   { PPB_MCM2_CM4 }
  /** Array initializer of PPB_MCM2_CM4 peripheral base addresses */
  #define PPB_MCM2_CM4_BASE_ADDRS_NS               { PPB_MCM2_CM4_BASE_NS }
  /** Array initializer of PPB_MCM2_CM4 peripheral base pointers */
  #define PPB_MCM2_CM4_BASE_PTRS_NS                { PPB_MCM2_CM4_NS }
#else
  /** Peripheral PPB_MCM2_CM4 base address */
  #define PPB_MCM2_CM4_BASE                        (0xE0080000u)
  /** Peripheral PPB_MCM2_CM4 base pointer */
  #define PPB_MCM2_CM4                             ((PPB_MCM2_CM4_Type *)PPB_MCM2_CM4_BASE)
  /** Array initializer of PPB_MCM2_CM4 peripheral base addresses */
  #define PPB_MCM2_CM4_BASE_ADDRS                  { PPB_MCM2_CM4_BASE }
  /** Array initializer of PPB_MCM2_CM4 peripheral base pointers */
  #define PPB_MCM2_CM4_BASE_PTRS                   { PPB_MCM2_CM4 }
#endif

/* PWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXPWM_0 base address */
  #define FLEXPWM_0_BASE                           (0x50021000u)
  /** Peripheral FLEXPWM_0 base address */
  #define FLEXPWM_0_BASE_NS                        (0x40021000u)
  /** Peripheral FLEXPWM_0 base pointer */
  #define FLEXPWM_0                                ((PWM_Type *)FLEXPWM_0_BASE)
  /** Peripheral FLEXPWM_0 base pointer */
  #define FLEXPWM_0_NS                             ((PWM_Type *)FLEXPWM_0_BASE_NS)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { FLEXPWM_0_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { FLEXPWM_0 }
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS_NS                        { FLEXPWM_0_BASE_NS }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS_NS                         { FLEXPWM_0_NS }
#else
  /** Peripheral FLEXPWM_0 base address */
  #define FLEXPWM_0_BASE                           (0x40021000u)
  /** Peripheral FLEXPWM_0 base pointer */
  #define FLEXPWM_0                                ((PWM_Type *)FLEXPWM_0_BASE)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { FLEXPWM_0_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { FLEXPWM_0 }
#endif
/** Interrupt vectors for the PWM peripheral type */
#define PWM_FAULT_IRQS                           { FLEXPWM0_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { FLEXPWM0_RELOAD_ERROR_IRQn }

/* RADIO_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RADIO_CTRL base address */
  #define RADIO_CTRL_BASE                          (0x50106000u)
  /** Peripheral RADIO_CTRL base address */
  #define RADIO_CTRL_BASE_NS                       (0x40106000u)
  /** Peripheral RADIO_CTRL base pointer */
  #define RADIO_CTRL                               ((RADIO_CTRL_Type *)RADIO_CTRL_BASE)
  /** Peripheral RADIO_CTRL base pointer */
  #define RADIO_CTRL_NS                            ((RADIO_CTRL_Type *)RADIO_CTRL_BASE_NS)
  /** Array initializer of RADIO_CTRL peripheral base addresses */
  #define RADIO_CTRL_BASE_ADDRS                    { RADIO_CTRL_BASE }
  /** Array initializer of RADIO_CTRL peripheral base pointers */
  #define RADIO_CTRL_BASE_PTRS                     { RADIO_CTRL }
  /** Array initializer of RADIO_CTRL peripheral base addresses */
  #define RADIO_CTRL_BASE_ADDRS_NS                 { RADIO_CTRL_BASE_NS }
  /** Array initializer of RADIO_CTRL peripheral base pointers */
  #define RADIO_CTRL_BASE_PTRS_NS                  { RADIO_CTRL_NS }
#else
  /** Peripheral RADIO_CTRL base address */
  #define RADIO_CTRL_BASE                          (0x40106000u)
  /** Peripheral RADIO_CTRL base pointer */
  #define RADIO_CTRL                               ((RADIO_CTRL_Type *)RADIO_CTRL_BASE)
  /** Array initializer of RADIO_CTRL peripheral base addresses */
  #define RADIO_CTRL_BASE_ADDRS                    { RADIO_CTRL_BASE }
  /** Array initializer of RADIO_CTRL peripheral base pointers */
  #define RADIO_CTRL_BASE_PTRS                     { RADIO_CTRL }
#endif

/* RBME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RBME base address */
  #define RBME_BASE                                (0x50106200u)
  /** Peripheral RBME base address */
  #define RBME_BASE_NS                             (0x40106200u)
  /** Peripheral RBME base pointer */
  #define RBME                                     ((RBME_Type *)RBME_BASE)
  /** Peripheral RBME base pointer */
  #define RBME_NS                                  ((RBME_Type *)RBME_BASE_NS)
  /** Array initializer of RBME peripheral base addresses */
  #define RBME_BASE_ADDRS                          { RBME_BASE }
  /** Array initializer of RBME peripheral base pointers */
  #define RBME_BASE_PTRS                           { RBME }
  /** Array initializer of RBME peripheral base addresses */
  #define RBME_BASE_ADDRS_NS                       { RBME_BASE_NS }
  /** Array initializer of RBME peripheral base pointers */
  #define RBME_BASE_PTRS_NS                        { RBME_NS }
#else
  /** Peripheral RBME base address */
  #define RBME_BASE                                (0x40106200u)
  /** Peripheral RBME base pointer */
  #define RBME                                     ((RBME_Type *)RBME_BASE)
  /** Array initializer of RBME peripheral base addresses */
  #define RBME_BASE_ADDRS                          { RBME_BASE }
  /** Array initializer of RBME peripheral base pointers */
  #define RBME_BASE_PTRS                           { RBME }
#endif

/* REGFILE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral REGFILE_0 base address */
  #define REGFILE_0_BASE                           (0x5018B000u)
  /** Peripheral REGFILE_0 base address */
  #define REGFILE_0_BASE_NS                        (0x4018B000u)
  /** Peripheral REGFILE_0 base pointer */
  #define REGFILE_0                                ((REGFILE_Type *)REGFILE_0_BASE)
  /** Peripheral REGFILE_0 base pointer */
  #define REGFILE_0_NS                             ((REGFILE_Type *)REGFILE_0_BASE_NS)
  /** Array initializer of REGFILE peripheral base addresses */
  #define REGFILE_BASE_ADDRS                       { REGFILE_0_BASE }
  /** Array initializer of REGFILE peripheral base pointers */
  #define REGFILE_BASE_PTRS                        { REGFILE_0 }
  /** Array initializer of REGFILE peripheral base addresses */
  #define REGFILE_BASE_ADDRS_NS                    { REGFILE_0_BASE_NS }
  /** Array initializer of REGFILE peripheral base pointers */
  #define REGFILE_BASE_PTRS_NS                     { REGFILE_0_NS }
#else
  /** Peripheral REGFILE_0 base address */
  #define REGFILE_0_BASE                           (0x4018B000u)
  /** Peripheral REGFILE_0 base pointer */
  #define REGFILE_0                                ((REGFILE_Type *)REGFILE_0_BASE)
  /** Array initializer of REGFILE peripheral base addresses */
  #define REGFILE_BASE_ADDRS                       { REGFILE_0_BASE }
  /** Array initializer of REGFILE peripheral base pointers */
  #define REGFILE_BASE_PTRS                        { REGFILE_0 }
#endif

/* RFMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RFMC base address */
  #define RFMC_BASE                                (0x501A3000u)
  /** Peripheral RFMC base address */
  #define RFMC_BASE_NS                             (0x401A3000u)
  /** Peripheral RFMC base pointer */
  #define RFMC                                     ((RFMC_Type *)RFMC_BASE)
  /** Peripheral RFMC base pointer */
  #define RFMC_NS                                  ((RFMC_Type *)RFMC_BASE_NS)
  /** Array initializer of RFMC peripheral base addresses */
  #define RFMC_BASE_ADDRS                          { RFMC_BASE }
  /** Array initializer of RFMC peripheral base pointers */
  #define RFMC_BASE_PTRS                           { RFMC }
  /** Array initializer of RFMC peripheral base addresses */
  #define RFMC_BASE_ADDRS_NS                       { RFMC_BASE_NS }
  /** Array initializer of RFMC peripheral base pointers */
  #define RFMC_BASE_PTRS_NS                        { RFMC_NS }
#else
  /** Peripheral RFMC base address */
  #define RFMC_BASE                                (0x401A3000u)
  /** Peripheral RFMC base pointer */
  #define RFMC                                     ((RFMC_Type *)RFMC_BASE)
  /** Array initializer of RFMC peripheral base addresses */
  #define RFMC_BASE_ADDRS                          { RFMC_BASE }
  /** Array initializer of RFMC peripheral base pointers */
  #define RFMC_BASE_PTRS                           { RFMC }
#endif

/* RF_CMC1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RF_CMC1 base address */
  #define RF_CMC1_BASE                             (0x50203000u)
  /** Peripheral RF_CMC1 base address */
  #define RF_CMC1_BASE_NS                          (0x40203000u)
  /** Peripheral RF_CMC1 base pointer */
  #define RF_CMC1                                  ((RF_CMC1_Type *)RF_CMC1_BASE)
  /** Peripheral RF_CMC1 base pointer */
  #define RF_CMC1_NS                               ((RF_CMC1_Type *)RF_CMC1_BASE_NS)
  /** Array initializer of RF_CMC1 peripheral base addresses */
  #define RF_CMC1_BASE_ADDRS                       { RF_CMC1_BASE }
  /** Array initializer of RF_CMC1 peripheral base pointers */
  #define RF_CMC1_BASE_PTRS                        { RF_CMC1 }
  /** Array initializer of RF_CMC1 peripheral base addresses */
  #define RF_CMC1_BASE_ADDRS_NS                    { RF_CMC1_BASE_NS }
  /** Array initializer of RF_CMC1 peripheral base pointers */
  #define RF_CMC1_BASE_PTRS_NS                     { RF_CMC1_NS }
#else
  /** Peripheral RF_CMC1 base address */
  #define RF_CMC1_BASE                             (0x40203000u)
  /** Peripheral RF_CMC1 base pointer */
  #define RF_CMC1                                  ((RF_CMC1_Type *)RF_CMC1_BASE)
  /** Array initializer of RF_CMC1 peripheral base addresses */
  #define RF_CMC1_BASE_ADDRS                       { RF_CMC1_BASE }
  /** Array initializer of RF_CMC1 peripheral base pointers */
  #define RF_CMC1_BASE_PTRS                        { RF_CMC1 }
#endif

/* RTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRTC_0 base address */
  #define SRTC_0_BASE                              (0x50189000u)
  /** Peripheral SRTC_0 base address */
  #define SRTC_0_BASE_NS                           (0x40189000u)
  /** Peripheral SRTC_0 base pointer */
  #define SRTC_0                                   ((RTC_Type *)SRTC_0_BASE)
  /** Peripheral SRTC_0 base pointer */
  #define SRTC_0_NS                                ((RTC_Type *)SRTC_0_BASE_NS)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { SRTC_0_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { SRTC_0 }
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS_NS                        { SRTC_0_BASE_NS }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS_NS                         { SRTC_0_NS }
#else
  /** Peripheral SRTC_0 base address */
  #define SRTC_0_BASE                              (0x40189000u)
  /** Peripheral SRTC_0 base pointer */
  #define SRTC_0                                   ((RTC_Type *)SRTC_0_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { SRTC_0_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { SRTC_0 }
#endif

/* RTU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RTU base address */
  #define RTU_BASE                                 (0x5010B400u)
  /** Peripheral RTU base address */
  #define RTU_BASE_NS                              (0x4010B400u)
  /** Peripheral RTU base pointer */
  #define RTU                                      ((RTU_Type *)RTU_BASE)
  /** Peripheral RTU base pointer */
  #define RTU_NS                                   ((RTU_Type *)RTU_BASE_NS)
  /** Array initializer of RTU peripheral base addresses */
  #define RTU_BASE_ADDRS                           { RTU_BASE }
  /** Array initializer of RTU peripheral base pointers */
  #define RTU_BASE_PTRS                            { RTU }
  /** Array initializer of RTU peripheral base addresses */
  #define RTU_BASE_ADDRS_NS                        { RTU_BASE_NS }
  /** Array initializer of RTU peripheral base pointers */
  #define RTU_BASE_PTRS_NS                         { RTU_NS }
#else
  /** Peripheral RTU base address */
  #define RTU_BASE                                 (0x4010B400u)
  /** Peripheral RTU base pointer */
  #define RTU                                      ((RTU_Type *)RTU_BASE)
  /** Array initializer of RTU peripheral base addresses */
  #define RTU_BASE_ADDRS                           { RTU_BASE }
  /** Array initializer of RTU peripheral base pointers */
  #define RTU_BASE_PTRS                            { RTU }
#endif

/* RX_PACKET_RAM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RX_PACKET_RAM base address */
  #define RX_PACKET_RAM_BASE                       (0x50109000u)
  /** Peripheral RX_PACKET_RAM base address */
  #define RX_PACKET_RAM_BASE_NS                    (0x40109000u)
  /** Peripheral RX_PACKET_RAM base pointer */
  #define RX_PACKET_RAM                            ((RX_PACKET_RAM_Type *)RX_PACKET_RAM_BASE)
  /** Peripheral RX_PACKET_RAM base pointer */
  #define RX_PACKET_RAM_NS                         ((RX_PACKET_RAM_Type *)RX_PACKET_RAM_BASE_NS)
  /** Array initializer of RX_PACKET_RAM peripheral base addresses */
  #define RX_PACKET_RAM_BASE_ADDRS                 { RX_PACKET_RAM_BASE }
  /** Array initializer of RX_PACKET_RAM peripheral base pointers */
  #define RX_PACKET_RAM_BASE_PTRS                  { RX_PACKET_RAM }
  /** Array initializer of RX_PACKET_RAM peripheral base addresses */
  #define RX_PACKET_RAM_BASE_ADDRS_NS              { RX_PACKET_RAM_BASE_NS }
  /** Array initializer of RX_PACKET_RAM peripheral base pointers */
  #define RX_PACKET_RAM_BASE_PTRS_NS               { RX_PACKET_RAM_NS }
#else
  /** Peripheral RX_PACKET_RAM base address */
  #define RX_PACKET_RAM_BASE                       (0x40109000u)
  /** Peripheral RX_PACKET_RAM base pointer */
  #define RX_PACKET_RAM                            ((RX_PACKET_RAM_Type *)RX_PACKET_RAM_BASE)
  /** Array initializer of RX_PACKET_RAM peripheral base addresses */
  #define RX_PACKET_RAM_BASE_ADDRS                 { RX_PACKET_RAM_BASE }
  /** Array initializer of RX_PACKET_RAM peripheral base pointers */
  #define RX_PACKET_RAM_BASE_PTRS                  { RX_PACKET_RAM }
#endif

/* SCG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SCG_0 base address */
  #define SCG_0_BASE                               (0x50182000u)
  /** Peripheral SCG_0 base address */
  #define SCG_0_BASE_NS                            (0x40182000u)
  /** Peripheral SCG_0 base pointer */
  #define SCG_0                                    ((SCG_Type *)SCG_0_BASE)
  /** Peripheral SCG_0 base pointer */
  #define SCG_0_NS                                 ((SCG_Type *)SCG_0_BASE_NS)
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS                           { SCG_0_BASE }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS                            { SCG_0 }
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS_NS                        { SCG_0_BASE_NS }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS_NS                         { SCG_0_NS }
#else
  /** Peripheral SCG_0 base address */
  #define SCG_0_BASE                               (0x40182000u)
  /** Peripheral SCG_0 base pointer */
  #define SCG_0                                    ((SCG_Type *)SCG_0_BASE)
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS                           { SCG_0_BASE }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS                            { SCG_0 }
#endif

/* SECCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SECCON base address */
  #define SECCON_BASE                              (0x5019F000u)
  /** Peripheral SECCON base address */
  #define SECCON_BASE_NS                           (0x4019F000u)
  /** Peripheral SECCON base pointer */
  #define SECCON                                   ((SECCON_Type *)SECCON_BASE)
  /** Peripheral SECCON base pointer */
  #define SECCON_NS                                ((SECCON_Type *)SECCON_BASE_NS)
  /** Array initializer of SECCON peripheral base addresses */
  #define SECCON_BASE_ADDRS                        { SECCON_BASE }
  /** Array initializer of SECCON peripheral base pointers */
  #define SECCON_BASE_PTRS                         { SECCON }
  /** Array initializer of SECCON peripheral base addresses */
  #define SECCON_BASE_ADDRS_NS                     { SECCON_BASE_NS }
  /** Array initializer of SECCON peripheral base pointers */
  #define SECCON_BASE_PTRS_NS                      { SECCON_NS }
#else
  /** Peripheral SECCON base address */
  #define SECCON_BASE                              (0x4019F000u)
  /** Peripheral SECCON base pointer */
  #define SECCON                                   ((SECCON_Type *)SECCON_BASE)
  /** Array initializer of SECCON peripheral base addresses */
  #define SECCON_BASE_ADDRS                        { SECCON_BASE }
  /** Array initializer of SECCON peripheral base pointers */
  #define SECCON_BASE_PTRS                         { SECCON }
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE                              (0x50188000u)
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE_NS                           (0x40188000u)
  /** Peripheral SEMA42 base pointer */
  #define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
  /** Peripheral SEMA42 base pointer */
  #define SEMA42_NS                                ((SEMA42_Type *)SEMA42_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { SEMA42_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { SEMA42_NS }
#else
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE                              (0x40188000u)
  /** Peripheral SEMA42 base pointer */
  #define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42 }
#endif

/* SFA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SFA_0 base address */
  #define SFA_0_BASE                               (0x50198000u)
  /** Peripheral SFA_0 base address */
  #define SFA_0_BASE_NS                            (0x40198000u)
  /** Peripheral SFA_0 base pointer */
  #define SFA_0                                    ((SFA_Type *)SFA_0_BASE)
  /** Peripheral SFA_0 base pointer */
  #define SFA_0_NS                                 ((SFA_Type *)SFA_0_BASE_NS)
  /** Peripheral SFA_1 base address */
  #define SFA_1_BASE                               (0x50022000u)
  /** Peripheral SFA_1 base address */
  #define SFA_1_BASE_NS                            (0x40022000u)
  /** Peripheral SFA_1 base pointer */
  #define SFA_1                                    ((SFA_Type *)SFA_1_BASE)
  /** Peripheral SFA_1 base pointer */
  #define SFA_1_NS                                 ((SFA_Type *)SFA_1_BASE_NS)
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS                           { SFA_0_BASE, SFA_1_BASE }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS                            { SFA_0, SFA_1 }
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS_NS                        { SFA_0_BASE_NS, SFA_1_BASE_NS }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS_NS                         { SFA_0_NS, SFA_1_NS }
#else
  /** Peripheral SFA_0 base address */
  #define SFA_0_BASE                               (0x40198000u)
  /** Peripheral SFA_0 base pointer */
  #define SFA_0                                    ((SFA_Type *)SFA_0_BASE)
  /** Peripheral SFA_1 base address */
  #define SFA_1_BASE                               (0x40022000u)
  /** Peripheral SFA_1 base pointer */
  #define SFA_1                                    ((SFA_Type *)SFA_1_BASE)
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS                           { SFA_0_BASE, SFA_1_BASE }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS                            { SFA_0, SFA_1 }
#endif

/* SGI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SGI_0 base address */
  #define SGI_0_BASE                               (0x5003A000u)
  /** Peripheral SGI_0 base address */
  #define SGI_0_BASE_NS                            (0x4003A000u)
  /** Peripheral SGI_0 base pointer */
  #define SGI_0                                    ((SGI_Type *)SGI_0_BASE)
  /** Peripheral SGI_0 base pointer */
  #define SGI_0_NS                                 ((SGI_Type *)SGI_0_BASE_NS)
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS                           { SGI_0_BASE }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS                            { SGI_0 }
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS_NS                        { SGI_0_BASE_NS }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS_NS                         { SGI_0_NS }
#else
  /** Peripheral SGI_0 base address */
  #define SGI_0_BASE                               (0x4003A000u)
  /** Peripheral SGI_0 base pointer */
  #define SGI_0                                    ((SGI_Type *)SGI_0_BASE)
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS                           { SGI_0_BASE }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS                            { SGI_0 }
#endif

/* SPC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPC_0 base address */
  #define SPC_0_BASE                               (0x50180000u)
  /** Peripheral SPC_0 base address */
  #define SPC_0_BASE_NS                            (0x40180000u)
  /** Peripheral SPC_0 base pointer */
  #define SPC_0                                    ((SPC_Type *)SPC_0_BASE)
  /** Peripheral SPC_0 base pointer */
  #define SPC_0_NS                                 ((SPC_Type *)SPC_0_BASE_NS)
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS                           { SPC_0_BASE }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS                            { SPC_0 }
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS_NS                        { SPC_0_BASE_NS }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS_NS                         { SPC_0_NS }
#else
  /** Peripheral SPC_0 base address */
  #define SPC_0_BASE                               (0x40180000u)
  /** Peripheral SPC_0 base pointer */
  #define SPC_0                                    ((SPC_Type *)SPC_0_BASE)
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS                           { SPC_0_BASE }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS                            { SPC_0 }
#endif

/* SYSCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE                              (0x5019E000u)
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE_NS                           (0x4019E000u)
  /** Peripheral SYSCON base pointer */
  #define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
  /** Peripheral SYSCON base pointer */
  #define SYSCON_NS                                ((SYSCON_Type *)SYSCON_BASE_NS)
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS                         { SYSCON }
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS_NS                     { SYSCON_BASE_NS }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS_NS                      { SYSCON_NS }
#else
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE                              (0x4019E000u)
  /** Peripheral SYSCON base pointer */
  #define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS                         { SYSCON }
#endif

/* SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSPM base address */
  #define SYSPM_BASE                               (0x50014000u)
  /** Peripheral SYSPM base address */
  #define SYSPM_BASE_NS                            (0x40014000u)
  /** Peripheral SYSPM base pointer */
  #define SYSPM                                    ((SYSPM_Type *)SYSPM_BASE)
  /** Peripheral SYSPM base pointer */
  #define SYSPM_NS                                 ((SYSPM_Type *)SYSPM_BASE_NS)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { SYSPM_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { SYSPM }
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS_NS                      { SYSPM_BASE_NS }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS_NS                       { SYSPM_NS }
#else
  /** Peripheral SYSPM base address */
  #define SYSPM_BASE                               (0x40014000u)
  /** Peripheral SYSPM base pointer */
  #define SYSPM                                    ((SYSPM_Type *)SYSPM_BASE)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { SYSPM_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { SYSPM }
#endif

/* TPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TPM_0 base address */
  #define TPM_0_BASE                               (0x5001E000u)
  /** Peripheral TPM_0 base address */
  #define TPM_0_BASE_NS                            (0x4001E000u)
  /** Peripheral TPM_0 base pointer */
  #define TPM_0                                    ((TPM_Type *)TPM_0_BASE)
  /** Peripheral TPM_0 base pointer */
  #define TPM_0_NS                                 ((TPM_Type *)TPM_0_BASE_NS)
  /** Peripheral TPM_1 base address */
  #define TPM_1_BASE                               (0x50187000u)
  /** Peripheral TPM_1 base address */
  #define TPM_1_BASE_NS                            (0x40187000u)
  /** Peripheral TPM_1 base pointer */
  #define TPM_1                                    ((TPM_Type *)TPM_1_BASE)
  /** Peripheral TPM_1 base pointer */
  #define TPM_1_NS                                 ((TPM_Type *)TPM_1_BASE_NS)
  /** Peripheral TPM_2 base address */
  #define TPM_2_BASE                               (0x50202000u)
  /** Peripheral TPM_2 base address */
  #define TPM_2_BASE_NS                            (0x40202000u)
  /** Peripheral TPM_2 base pointer */
  #define TPM_2                                    ((TPM_Type *)TPM_2_BASE)
  /** Peripheral TPM_2 base pointer */
  #define TPM_2_NS                                 ((TPM_Type *)TPM_2_BASE_NS)
  /** Peripheral TPM_3 base address */
  #define TPM_3_BASE                               (0x5001F000u)
  /** Peripheral TPM_3 base address */
  #define TPM_3_BASE_NS                            (0x4001F000u)
  /** Peripheral TPM_3 base pointer */
  #define TPM_3                                    ((TPM_Type *)TPM_3_BASE)
  /** Peripheral TPM_3 base pointer */
  #define TPM_3_NS                                 ((TPM_Type *)TPM_3_BASE_NS)
  /** Peripheral TPM_4 base address */
  #define TPM_4_BASE                               (0x50020000u)
  /** Peripheral TPM_4 base address */
  #define TPM_4_BASE_NS                            (0x40020000u)
  /** Peripheral TPM_4 base pointer */
  #define TPM_4                                    ((TPM_Type *)TPM_4_BASE)
  /** Peripheral TPM_4 base pointer */
  #define TPM_4_NS                                 ((TPM_Type *)TPM_4_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { TPM_0_BASE, TPM_1_BASE, TPM_2_BASE, TPM_3_BASE, TPM_4_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { TPM_0, TPM_1, TPM_2, TPM_3, TPM_4 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { TPM_0_BASE_NS, TPM_1_BASE_NS, TPM_2_BASE_NS, TPM_3_BASE_NS, TPM_4_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { TPM_0_NS, TPM_1_NS, TPM_2_NS, TPM_3_NS, TPM_4_NS }
#else
  /** Peripheral TPM_0 base address */
  #define TPM_0_BASE                               (0x4001E000u)
  /** Peripheral TPM_0 base pointer */
  #define TPM_0                                    ((TPM_Type *)TPM_0_BASE)
  /** Peripheral TPM_1 base address */
  #define TPM_1_BASE                               (0x40187000u)
  /** Peripheral TPM_1 base pointer */
  #define TPM_1                                    ((TPM_Type *)TPM_1_BASE)
  /** Peripheral TPM_2 base address */
  #define TPM_2_BASE                               (0x40202000u)
  /** Peripheral TPM_2 base pointer */
  #define TPM_2                                    ((TPM_Type *)TPM_2_BASE)
  /** Peripheral TPM_3 base address */
  #define TPM_3_BASE                               (0x4001F000u)
  /** Peripheral TPM_3 base pointer */
  #define TPM_3                                    ((TPM_Type *)TPM_3_BASE)
  /** Peripheral TPM_4 base address */
  #define TPM_4_BASE                               (0x40020000u)
  /** Peripheral TPM_4 base pointer */
  #define TPM_4                                    ((TPM_Type *)TPM_4_BASE)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { TPM_0_BASE, TPM_1_BASE, TPM_2_BASE, TPM_3_BASE, TPM_4_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { TPM_0, TPM_1, TPM_2, TPM_3, TPM_4 }
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { TPM_0_IRQn, TPM_1_IRQn, TPM_2_IRQn, TPM_3_IRQn, TPM_4_IRQn }

/* TRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRDC_0_MGR base address */
  #define TRDC_0_MGR_BASE                          (0x5018C000u)
  /** Peripheral TRDC_0_MGR base address */
  #define TRDC_0_MGR_BASE_NS                       (0x4018C000u)
  /** Peripheral TRDC_0_MGR base pointer */
  #define TRDC_0_MGR                               ((TRDC_Type *)TRDC_0_MGR_BASE)
  /** Peripheral TRDC_0_MGR base pointer */
  #define TRDC_0_MGR_NS                            ((TRDC_Type *)TRDC_0_MGR_BASE_NS)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { TRDC_0_MGR_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { TRDC_0_MGR }
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS_NS                       { TRDC_0_MGR_BASE_NS }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS_NS                        { TRDC_0_MGR_NS }
#else
  /** Peripheral TRDC_0_MGR base address */
  #define TRDC_0_MGR_BASE                          (0x4018C000u)
  /** Peripheral TRDC_0_MGR base pointer */
  #define TRDC_0_MGR                               ((TRDC_Type *)TRDC_0_MGR_BASE)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { TRDC_0_MGR_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { TRDC_0_MGR }
#endif

/* TRGMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRGMUX_0 base address */
  #define TRGMUX_0_BASE                            (0x50015000u)
  /** Peripheral TRGMUX_0 base address */
  #define TRGMUX_0_BASE_NS                         (0x40015000u)
  /** Peripheral TRGMUX_0 base pointer */
  #define TRGMUX_0                                 ((TRGMUX_Type *)TRGMUX_0_BASE)
  /** Peripheral TRGMUX_0 base pointer */
  #define TRGMUX_0_NS                              ((TRGMUX_Type *)TRGMUX_0_BASE_NS)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX_0_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX_0 }
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS_NS                     { TRGMUX_0_BASE_NS }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS_NS                      { TRGMUX_0_NS }
#else
  /** Peripheral TRGMUX_0 base address */
  #define TRGMUX_0_BASE                            (0x40015000u)
  /** Peripheral TRGMUX_0 base pointer */
  #define TRGMUX_0                                 ((TRGMUX_Type *)TRGMUX_0_BASE)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX_0_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX_0 }
#endif

/* TRNG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRNG_0 base address */
  #define TRNG_0_BASE                              (0x5003C000u)
  /** Peripheral TRNG_0 base address */
  #define TRNG_0_BASE_NS                           (0x4003C000u)
  /** Peripheral TRNG_0 base pointer */
  #define TRNG_0                                   ((TRNG_Type *)TRNG_0_BASE)
  /** Peripheral TRNG_0 base pointer */
  #define TRNG_0_NS                                ((TRNG_Type *)TRNG_0_BASE_NS)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG_0_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG_0 }
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS_NS                       { TRNG_0_BASE_NS }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS_NS                        { TRNG_0_NS }
#else
  /** Peripheral TRNG_0 base address */
  #define TRNG_0_BASE                              (0x4003C000u)
  /** Peripheral TRNG_0 base pointer */
  #define TRNG_0                                   ((TRNG_Type *)TRNG_0_BASE)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG_0_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG_0 }
#endif

/* TSTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TIMESTAMP0 base address */
  #define TIMESTAMP0_BASE                          (0x50199000u)
  /** Peripheral TIMESTAMP0 base address */
  #define TIMESTAMP0_BASE_NS                       (0x40199000u)
  /** Peripheral TIMESTAMP0 base pointer */
  #define TIMESTAMP0                               ((TSTMR_Type *)TIMESTAMP0_BASE)
  /** Peripheral TIMESTAMP0 base pointer */
  #define TIMESTAMP0_NS                            ((TSTMR_Type *)TIMESTAMP0_BASE_NS)
  /** Peripheral TIMESTAMP1_0 base address */
  #define TIMESTAMP1_0_BASE                        (0x5019A000u)
  /** Peripheral TIMESTAMP1_0 base address */
  #define TIMESTAMP1_0_BASE_NS                     (0x4019A000u)
  /** Peripheral TIMESTAMP1_0 base pointer */
  #define TIMESTAMP1_0                             ((TSTMR_Type *)TIMESTAMP1_0_BASE)
  /** Peripheral TIMESTAMP1_0 base pointer */
  #define TIMESTAMP1_0_NS                          ((TSTMR_Type *)TIMESTAMP1_0_BASE_NS)
  /** Peripheral TIMESTAMP1_1 base address */
  #define TIMESTAMP1_1_BASE                        (0x5019B000u)
  /** Peripheral TIMESTAMP1_1 base address */
  #define TIMESTAMP1_1_BASE_NS                     (0x4019B000u)
  /** Peripheral TIMESTAMP1_1 base pointer */
  #define TIMESTAMP1_1                             ((TSTMR_Type *)TIMESTAMP1_1_BASE)
  /** Peripheral TIMESTAMP1_1 base pointer */
  #define TIMESTAMP1_1_NS                          ((TSTMR_Type *)TIMESTAMP1_1_BASE_NS)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TIMESTAMP0_BASE, TIMESTAMP1_0_BASE, TIMESTAMP1_1_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TIMESTAMP0, TIMESTAMP1_0, TIMESTAMP1_1 }
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS_NS                      { TIMESTAMP0_BASE_NS, TIMESTAMP1_0_BASE_NS, TIMESTAMP1_1_BASE_NS }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS_NS                       { TIMESTAMP0_NS, TIMESTAMP1_0_NS, TIMESTAMP1_1_NS }
#else
  /** Peripheral TIMESTAMP0 base address */
  #define TIMESTAMP0_BASE                          (0x40199000u)
  /** Peripheral TIMESTAMP0 base pointer */
  #define TIMESTAMP0                               ((TSTMR_Type *)TIMESTAMP0_BASE)
  /** Peripheral TIMESTAMP1_0 base address */
  #define TIMESTAMP1_0_BASE                        (0x4019A000u)
  /** Peripheral TIMESTAMP1_0 base pointer */
  #define TIMESTAMP1_0                             ((TSTMR_Type *)TIMESTAMP1_0_BASE)
  /** Peripheral TIMESTAMP1_1 base address */
  #define TIMESTAMP1_1_BASE                        (0x4019B000u)
  /** Peripheral TIMESTAMP1_1 base pointer */
  #define TIMESTAMP1_1                             ((TSTMR_Type *)TIMESTAMP1_1_BASE)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TIMESTAMP0_BASE, TIMESTAMP1_0_BASE, TIMESTAMP1_1_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TIMESTAMP0, TIMESTAMP1_0, TIMESTAMP1_1 }
#endif
/* Extra definition */
#define TSTMR_CLOCK_FREQUENCY_MHZ                (1U)


/* TX_PACKET_RAM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TX_PACKET_RAM base address */
  #define TX_PACKET_RAM_BASE                       (0x50108000u)
  /** Peripheral TX_PACKET_RAM base address */
  #define TX_PACKET_RAM_BASE_NS                    (0x40108000u)
  /** Peripheral TX_PACKET_RAM base pointer */
  #define TX_PACKET_RAM                            ((TX_PACKET_RAM_Type *)TX_PACKET_RAM_BASE)
  /** Peripheral TX_PACKET_RAM base pointer */
  #define TX_PACKET_RAM_NS                         ((TX_PACKET_RAM_Type *)TX_PACKET_RAM_BASE_NS)
  /** Array initializer of TX_PACKET_RAM peripheral base addresses */
  #define TX_PACKET_RAM_BASE_ADDRS                 { TX_PACKET_RAM_BASE }
  /** Array initializer of TX_PACKET_RAM peripheral base pointers */
  #define TX_PACKET_RAM_BASE_PTRS                  { TX_PACKET_RAM }
  /** Array initializer of TX_PACKET_RAM peripheral base addresses */
  #define TX_PACKET_RAM_BASE_ADDRS_NS              { TX_PACKET_RAM_BASE_NS }
  /** Array initializer of TX_PACKET_RAM peripheral base pointers */
  #define TX_PACKET_RAM_BASE_PTRS_NS               { TX_PACKET_RAM_NS }
#else
  /** Peripheral TX_PACKET_RAM base address */
  #define TX_PACKET_RAM_BASE                       (0x40108000u)
  /** Peripheral TX_PACKET_RAM base pointer */
  #define TX_PACKET_RAM                            ((TX_PACKET_RAM_Type *)TX_PACKET_RAM_BASE)
  /** Array initializer of TX_PACKET_RAM peripheral base addresses */
  #define TX_PACKET_RAM_BASE_ADDRS                 { TX_PACKET_RAM_BASE }
  /** Array initializer of TX_PACKET_RAM peripheral base pointers */
  #define TX_PACKET_RAM_BASE_PTRS                  { TX_PACKET_RAM }
#endif

/* UDF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral UDF_0 base address */
  #define UDF_0_BASE                               (0x5003B000u)
  /** Peripheral UDF_0 base address */
  #define UDF_0_BASE_NS                            (0x4003B000u)
  /** Peripheral UDF_0 base pointer */
  #define UDF_0                                    ((UDF_Type *)UDF_0_BASE)
  /** Peripheral UDF_0 base pointer */
  #define UDF_0_NS                                 ((UDF_Type *)UDF_0_BASE_NS)
  /** Array initializer of UDF peripheral base addresses */
  #define UDF_BASE_ADDRS                           { UDF_0_BASE }
  /** Array initializer of UDF peripheral base pointers */
  #define UDF_BASE_PTRS                            { UDF_0 }
  /** Array initializer of UDF peripheral base addresses */
  #define UDF_BASE_ADDRS_NS                        { UDF_0_BASE_NS }
  /** Array initializer of UDF peripheral base pointers */
  #define UDF_BASE_PTRS_NS                         { UDF_0_NS }
#else
  /** Peripheral UDF_0 base address */
  #define UDF_0_BASE                               (0x4003B000u)
  /** Peripheral UDF_0 base pointer */
  #define UDF_0                                    ((UDF_Type *)UDF_0_BASE)
  /** Array initializer of UDF peripheral base addresses */
  #define UDF_BASE_ADDRS                           { UDF_0_BASE }
  /** Array initializer of UDF peripheral base pointers */
  #define UDF_BASE_PTRS                            { UDF_0 }
#endif

/* WDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WDOG_0 base address */
  #define WDOG_0_BASE                              (0x5019D000u)
  /** Peripheral WDOG_0 base address */
  #define WDOG_0_BASE_NS                           (0x4019D000u)
  /** Peripheral WDOG_0 base pointer */
  #define WDOG_0                                   ((WDOG_Type *)WDOG_0_BASE)
  /** Peripheral WDOG_0 base pointer */
  #define WDOG_0_NS                                ((WDOG_Type *)WDOG_0_BASE_NS)
  /** Peripheral WDOG_1 base address */
  #define WDOG_1_BASE                              (0x50201000u)
  /** Peripheral WDOG_1 base address */
  #define WDOG_1_BASE_NS                           (0x40201000u)
  /** Peripheral WDOG_1 base pointer */
  #define WDOG_1                                   ((WDOG_Type *)WDOG_1_BASE)
  /** Peripheral WDOG_1 base pointer */
  #define WDOG_1_NS                                ((WDOG_Type *)WDOG_1_BASE_NS)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG_0_BASE, WDOG_1_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG_0, WDOG_1 }
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS_NS                       { WDOG_0_BASE_NS, WDOG_1_BASE_NS }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS_NS                        { WDOG_0_NS, WDOG_1_NS }
#else
  /** Peripheral WDOG_0 base address */
  #define WDOG_0_BASE                              (0x4019D000u)
  /** Peripheral WDOG_0 base pointer */
  #define WDOG_0                                   ((WDOG_Type *)WDOG_0_BASE)
  /** Peripheral WDOG_1 base address */
  #define WDOG_1_BASE                              (0x40201000u)
  /** Peripheral WDOG_1 base pointer */
  #define WDOG_1                                   ((WDOG_Type *)WDOG_1_BASE)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG_0_BASE, WDOG_1_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG_0, WDOG_1 }
#endif
/* Extra definition */
#define WDOG_UPDATE_KEY                          (0xD928C520U)
#define WDOG_REFRESH_KEY                         (0xB480A602U)


/* WOR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WOR_REGS base address */
  #define WOR_REGS_BASE                            (0x50106100u)
  /** Peripheral WOR_REGS base address */
  #define WOR_REGS_BASE_NS                         (0x40106100u)
  /** Peripheral WOR_REGS base pointer */
  #define WOR_REGS                                 ((WOR_Type *)WOR_REGS_BASE)
  /** Peripheral WOR_REGS base pointer */
  #define WOR_REGS_NS                              ((WOR_Type *)WOR_REGS_BASE_NS)
  /** Array initializer of WOR peripheral base addresses */
  #define WOR_BASE_ADDRS                           { WOR_REGS_BASE }
  /** Array initializer of WOR peripheral base pointers */
  #define WOR_BASE_PTRS                            { WOR_REGS }
  /** Array initializer of WOR peripheral base addresses */
  #define WOR_BASE_ADDRS_NS                        { WOR_REGS_BASE_NS }
  /** Array initializer of WOR peripheral base pointers */
  #define WOR_BASE_PTRS_NS                         { WOR_REGS_NS }
#else
  /** Peripheral WOR_REGS base address */
  #define WOR_REGS_BASE                            (0x40106100u)
  /** Peripheral WOR_REGS base pointer */
  #define WOR_REGS                                 ((WOR_Type *)WOR_REGS_BASE)
  /** Array initializer of WOR peripheral base addresses */
  #define WOR_BASE_ADDRS                           { WOR_REGS_BASE }
  /** Array initializer of WOR peripheral base pointers */
  #define WOR_BASE_PTRS                            { WOR_REGS }
#endif

/* WUU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WUU_0 base address */
  #define WUU_0_BASE                               (0x50194000u)
  /** Peripheral WUU_0 base address */
  #define WUU_0_BASE_NS                            (0x40194000u)
  /** Peripheral WUU_0 base pointer */
  #define WUU_0                                    ((WUU_Type *)WUU_0_BASE)
  /** Peripheral WUU_0 base pointer */
  #define WUU_0_NS                                 ((WUU_Type *)WUU_0_BASE_NS)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU_0_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU_0 }
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS_NS                        { WUU_0_BASE_NS }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS_NS                         { WUU_0_NS }
#else
  /** Peripheral WUU_0 base address */
  #define WUU_0_BASE                               (0x40194000u)
  /** Peripheral WUU_0 base pointer */
  #define WUU_0                                    ((WUU_Type *)WUU_0_BASE)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU_0_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU_0 }
#endif
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn }

/* XCVR_ANALOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_ANALOG base address */
  #define XCVR_ANALOG_BASE                         (0x50107C00u)
  /** Peripheral XCVR_ANALOG base address */
  #define XCVR_ANALOG_BASE_NS                      (0x40107C00u)
  /** Peripheral XCVR_ANALOG base pointer */
  #define XCVR_ANALOG                              ((XCVR_ANALOG_Type *)XCVR_ANALOG_BASE)
  /** Peripheral XCVR_ANALOG base pointer */
  #define XCVR_ANALOG_NS                           ((XCVR_ANALOG_Type *)XCVR_ANALOG_BASE_NS)
  /** Array initializer of XCVR_ANALOG peripheral base addresses */
  #define XCVR_ANALOG_BASE_ADDRS                   { XCVR_ANALOG_BASE }
  /** Array initializer of XCVR_ANALOG peripheral base pointers */
  #define XCVR_ANALOG_BASE_PTRS                    { XCVR_ANALOG }
  /** Array initializer of XCVR_ANALOG peripheral base addresses */
  #define XCVR_ANALOG_BASE_ADDRS_NS                { XCVR_ANALOG_BASE_NS }
  /** Array initializer of XCVR_ANALOG peripheral base pointers */
  #define XCVR_ANALOG_BASE_PTRS_NS                 { XCVR_ANALOG_NS }
#else
  /** Peripheral XCVR_ANALOG base address */
  #define XCVR_ANALOG_BASE                         (0x40107C00u)
  /** Peripheral XCVR_ANALOG base pointer */
  #define XCVR_ANALOG                              ((XCVR_ANALOG_Type *)XCVR_ANALOG_BASE)
  /** Array initializer of XCVR_ANALOG peripheral base addresses */
  #define XCVR_ANALOG_BASE_ADDRS                   { XCVR_ANALOG_BASE }
  /** Array initializer of XCVR_ANALOG peripheral base pointers */
  #define XCVR_ANALOG_BASE_PTRS                    { XCVR_ANALOG }
#endif

/* XCVR_MISC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_MISC base address */
  #define XCVR_MISC_BASE                           (0x50107D00u)
  /** Peripheral XCVR_MISC base address */
  #define XCVR_MISC_BASE_NS                        (0x40107D00u)
  /** Peripheral XCVR_MISC base pointer */
  #define XCVR_MISC                                ((XCVR_MISC_Type *)XCVR_MISC_BASE)
  /** Peripheral XCVR_MISC base pointer */
  #define XCVR_MISC_NS                             ((XCVR_MISC_Type *)XCVR_MISC_BASE_NS)
  /** Array initializer of XCVR_MISC peripheral base addresses */
  #define XCVR_MISC_BASE_ADDRS                     { XCVR_MISC_BASE }
  /** Array initializer of XCVR_MISC peripheral base pointers */
  #define XCVR_MISC_BASE_PTRS                      { XCVR_MISC }
  /** Array initializer of XCVR_MISC peripheral base addresses */
  #define XCVR_MISC_BASE_ADDRS_NS                  { XCVR_MISC_BASE_NS }
  /** Array initializer of XCVR_MISC peripheral base pointers */
  #define XCVR_MISC_BASE_PTRS_NS                   { XCVR_MISC_NS }
#else
  /** Peripheral XCVR_MISC base address */
  #define XCVR_MISC_BASE                           (0x40107D00u)
  /** Peripheral XCVR_MISC base pointer */
  #define XCVR_MISC                                ((XCVR_MISC_Type *)XCVR_MISC_BASE)
  /** Array initializer of XCVR_MISC peripheral base addresses */
  #define XCVR_MISC_BASE_ADDRS                     { XCVR_MISC_BASE }
  /** Array initializer of XCVR_MISC peripheral base pointers */
  #define XCVR_MISC_BASE_PTRS                      { XCVR_MISC }
#endif

/* XCVR_PLL_DIG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_PLL_DIG base address */
  #define XCVR_PLL_DIG_BASE                        (0x50107300u)
  /** Peripheral XCVR_PLL_DIG base address */
  #define XCVR_PLL_DIG_BASE_NS                     (0x40107300u)
  /** Peripheral XCVR_PLL_DIG base pointer */
  #define XCVR_PLL_DIG                             ((XCVR_PLL_DIG_Type *)XCVR_PLL_DIG_BASE)
  /** Peripheral XCVR_PLL_DIG base pointer */
  #define XCVR_PLL_DIG_NS                          ((XCVR_PLL_DIG_Type *)XCVR_PLL_DIG_BASE_NS)
  /** Array initializer of XCVR_PLL_DIG peripheral base addresses */
  #define XCVR_PLL_DIG_BASE_ADDRS                  { XCVR_PLL_DIG_BASE }
  /** Array initializer of XCVR_PLL_DIG peripheral base pointers */
  #define XCVR_PLL_DIG_BASE_PTRS                   { XCVR_PLL_DIG }
  /** Array initializer of XCVR_PLL_DIG peripheral base addresses */
  #define XCVR_PLL_DIG_BASE_ADDRS_NS               { XCVR_PLL_DIG_BASE_NS }
  /** Array initializer of XCVR_PLL_DIG peripheral base pointers */
  #define XCVR_PLL_DIG_BASE_PTRS_NS                { XCVR_PLL_DIG_NS }
#else
  /** Peripheral XCVR_PLL_DIG base address */
  #define XCVR_PLL_DIG_BASE                        (0x40107300u)
  /** Peripheral XCVR_PLL_DIG base pointer */
  #define XCVR_PLL_DIG                             ((XCVR_PLL_DIG_Type *)XCVR_PLL_DIG_BASE)
  /** Array initializer of XCVR_PLL_DIG peripheral base addresses */
  #define XCVR_PLL_DIG_BASE_ADDRS                  { XCVR_PLL_DIG_BASE }
  /** Array initializer of XCVR_PLL_DIG peripheral base pointers */
  #define XCVR_PLL_DIG_BASE_PTRS                   { XCVR_PLL_DIG }
#endif

/* XCVR_RX_DIG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_RX_DIG base address */
  #define XCVR_RX_DIG_BASE                         (0x50107000u)
  /** Peripheral XCVR_RX_DIG base address */
  #define XCVR_RX_DIG_BASE_NS                      (0x40107000u)
  /** Peripheral XCVR_RX_DIG base pointer */
  #define XCVR_RX_DIG                              ((XCVR_RX_DIG_Type *)XCVR_RX_DIG_BASE)
  /** Peripheral XCVR_RX_DIG base pointer */
  #define XCVR_RX_DIG_NS                           ((XCVR_RX_DIG_Type *)XCVR_RX_DIG_BASE_NS)
  /** Array initializer of XCVR_RX_DIG peripheral base addresses */
  #define XCVR_RX_DIG_BASE_ADDRS                   { XCVR_RX_DIG_BASE }
  /** Array initializer of XCVR_RX_DIG peripheral base pointers */
  #define XCVR_RX_DIG_BASE_PTRS                    { XCVR_RX_DIG }
  /** Array initializer of XCVR_RX_DIG peripheral base addresses */
  #define XCVR_RX_DIG_BASE_ADDRS_NS                { XCVR_RX_DIG_BASE_NS }
  /** Array initializer of XCVR_RX_DIG peripheral base pointers */
  #define XCVR_RX_DIG_BASE_PTRS_NS                 { XCVR_RX_DIG_NS }
#else
  /** Peripheral XCVR_RX_DIG base address */
  #define XCVR_RX_DIG_BASE                         (0x40107000u)
  /** Peripheral XCVR_RX_DIG base pointer */
  #define XCVR_RX_DIG                              ((XCVR_RX_DIG_Type *)XCVR_RX_DIG_BASE)
  /** Array initializer of XCVR_RX_DIG peripheral base addresses */
  #define XCVR_RX_DIG_BASE_ADDRS                   { XCVR_RX_DIG_BASE }
  /** Array initializer of XCVR_RX_DIG peripheral base pointers */
  #define XCVR_RX_DIG_BASE_PTRS                    { XCVR_RX_DIG }
#endif

/* XCVR_TSM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_TSM base address */
  #define XCVR_TSM_BASE                            (0x50107800u)
  /** Peripheral XCVR_TSM base address */
  #define XCVR_TSM_BASE_NS                         (0x40107800u)
  /** Peripheral XCVR_TSM base pointer */
  #define XCVR_TSM                                 ((XCVR_TSM_Type *)XCVR_TSM_BASE)
  /** Peripheral XCVR_TSM base pointer */
  #define XCVR_TSM_NS                              ((XCVR_TSM_Type *)XCVR_TSM_BASE_NS)
  /** Array initializer of XCVR_TSM peripheral base addresses */
  #define XCVR_TSM_BASE_ADDRS                      { XCVR_TSM_BASE }
  /** Array initializer of XCVR_TSM peripheral base pointers */
  #define XCVR_TSM_BASE_PTRS                       { XCVR_TSM }
  /** Array initializer of XCVR_TSM peripheral base addresses */
  #define XCVR_TSM_BASE_ADDRS_NS                   { XCVR_TSM_BASE_NS }
  /** Array initializer of XCVR_TSM peripheral base pointers */
  #define XCVR_TSM_BASE_PTRS_NS                    { XCVR_TSM_NS }
#else
  /** Peripheral XCVR_TSM base address */
  #define XCVR_TSM_BASE                            (0x40107800u)
  /** Peripheral XCVR_TSM base pointer */
  #define XCVR_TSM                                 ((XCVR_TSM_Type *)XCVR_TSM_BASE)
  /** Array initializer of XCVR_TSM peripheral base addresses */
  #define XCVR_TSM_BASE_ADDRS                      { XCVR_TSM_BASE }
  /** Array initializer of XCVR_TSM peripheral base pointers */
  #define XCVR_TSM_BASE_PTRS                       { XCVR_TSM }
#endif

/* XCVR_TX_DIG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_TX_DIG base address */
  #define XCVR_TX_DIG_BASE                         (0x50107200u)
  /** Peripheral XCVR_TX_DIG base address */
  #define XCVR_TX_DIG_BASE_NS                      (0x40107200u)
  /** Peripheral XCVR_TX_DIG base pointer */
  #define XCVR_TX_DIG                              ((XCVR_TX_DIG_Type *)XCVR_TX_DIG_BASE)
  /** Peripheral XCVR_TX_DIG base pointer */
  #define XCVR_TX_DIG_NS                           ((XCVR_TX_DIG_Type *)XCVR_TX_DIG_BASE_NS)
  /** Array initializer of XCVR_TX_DIG peripheral base addresses */
  #define XCVR_TX_DIG_BASE_ADDRS                   { XCVR_TX_DIG_BASE }
  /** Array initializer of XCVR_TX_DIG peripheral base pointers */
  #define XCVR_TX_DIG_BASE_PTRS                    { XCVR_TX_DIG }
  /** Array initializer of XCVR_TX_DIG peripheral base addresses */
  #define XCVR_TX_DIG_BASE_ADDRS_NS                { XCVR_TX_DIG_BASE_NS }
  /** Array initializer of XCVR_TX_DIG peripheral base pointers */
  #define XCVR_TX_DIG_BASE_PTRS_NS                 { XCVR_TX_DIG_NS }
#else
  /** Peripheral XCVR_TX_DIG base address */
  #define XCVR_TX_DIG_BASE                         (0x40107200u)
  /** Peripheral XCVR_TX_DIG base pointer */
  #define XCVR_TX_DIG                              ((XCVR_TX_DIG_Type *)XCVR_TX_DIG_BASE)
  /** Array initializer of XCVR_TX_DIG peripheral base addresses */
  #define XCVR_TX_DIG_BASE_ADDRS                   { XCVR_TX_DIG_BASE }
  /** Array initializer of XCVR_TX_DIG peripheral base pointers */
  #define XCVR_TX_DIG_BASE_PTRS                    { XCVR_TX_DIG }
#endif

/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field##_SHIFT)) & (field##_MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field##_MASK)) >> (field##_SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */
#define RTC  SRTC_0
#define CDOG CDOG_0
#define FMU0 FMU
#define CAN0 CAN_0
#define SCG0 SCG_0
#define SFA0 SFA_0
#define CMC0 CMC_0
#define DSB0 DSB_0
#define SPC0 SPC_0
#define WUU0 WUU_0
#define MRCC MRCC_0
#define INTM0 INTM_0
#define GPIOA GPIO_A
#define GPIOB GPIO_B
#define GPIOC GPIO_C
#define GPIOD GPIO_D
#define PORTA PORT_A
#define PORTB PORT_B
#define PORTC PORT_C
#define PORTD PORT_D
#define CCM32K ANAREG_0
#define LPTMR0 LPTMR_0
#define RF_SFA SFA_1
#define MU0_MUA MU_0__MUA
#define MU0_MUB MU_0__MUB
#define MU1_MUA MU_1__MUA
#define MU1_MUB MU_1__MUB
#define PORTA_BASE PORT_A_BASE

#define NXP_RADIO_GEN (475)
#define RADIO_IS_GEN_4P7 (1)
#define IS_APP_CORE (1)
#define IS_RADIO_CORE (0)
#ifndef KW43_core0_SERIES
#define KW43_core0_SERIES
#endif

/*! @brief define LTC0 from LTC. */
#define LTC0 LTC

/*
 * Macros below define the chip revision.
 */
#define DEVICE_REVISION_A0     (0x10U)
#define DEVICE_REVISION_A1     (0x11U)
#define DEVICE_REVISION_A2     (0x12U)
#define DEVICE_REVISION_OTHERS (0xFFU)

#define IS_CHIP_REVISION_A0() (DEVICE_REVISION_A0 == Chip_GetVersion())
#define IS_CHIP_REVISION_A1() (DEVICE_REVISION_A1 == Chip_GetVersion())
#define IS_CHIP_REVISION_A2() (DEVICE_REVISION_A2 == Chip_GetVersion())

/*!
* @brief Get the chip value.
*
* @return chip version, 0x10: A0 version chip, 0x11: A1 version chip, 0x12: A2 version chip, 0xFF: invalid version.
*/
static inline uint8_t Chip_GetVersion(void)
{
    return DEVICE_REVISION_A0;
}

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* KW43B43ZC7_COMMON_H_ */

