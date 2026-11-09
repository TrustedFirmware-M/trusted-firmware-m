/*
** ###################################################################
**     Processors:          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXAP144M180FS6_RM_Rev.1_DraftC
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXA577
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MCXA577_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCXA577
 *
 * CMSIS Peripheral Access Layer for MCXA577
 */

#if !defined(MCXA577_COMMON_H_)
#define MCXA577_COMMON_H_                        /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200U
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
#define NUMBER_OF_INT_VECTORS 162                /**< Number of interrupts in the Vector table */

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
  Reserved16_IRQn              = 0,                /**< OR IRQ1 to IRQ53 */
  CMC_IRQn                     = 1,                /**< Core Mode Controller interrupt */
  DMA0_CH0_IRQn                = 2,                /**< DMA3_0_CH0 error or transfer complete */
  DMA0_CH1_IRQn                = 3,                /**< DMA3_0_CH1 error or transfer complete */
  DMA0_CH2_IRQn                = 4,                /**< DMA3_0_CH2 error or transfer complete */
  DMA0_CH3_IRQn                = 5,                /**< DMA3_0_CH3 error or transfer complete */
  DMA0_CH4_IRQn                = 6,                /**< DMA3_0_CH4 error or transfer complete */
  DMA0_CH5_IRQn                = 7,                /**< DMA3_0_CH5 error or transfer complete */
  DMA0_CH6_IRQn                = 8,                /**< DMA3_0_CH6 error or transfer complete */
  DMA0_CH7_IRQn                = 9,                /**< DMA3_0_CH7 error or transfer complete */
  ERM0_SINGLE_BIT_IRQn         = 10,               /**< ERM Single Bit error interrupt */
  ERM0_MULTI_BIT_IRQn          = 11,               /**< ERM Multi Bit error interrupt */
  FMU0_IRQn                    = 12,               /**< Flash Management Unit interrupt */
  GLIKEY0_IRQn                 = 13,               /**< GLIKEY Interrupt  */
  MBC0_IRQn                    = 14,               /**< MBC secure violation interrupt */
  SCG0_IRQn                    = 15,               /**< System Clock Generator interrupt */
  SPC0_IRQn                    = 16,               /**< System Power Controller interrupt */
  TDET_IRQn                    = 17,               /**< TDET interrrupt */
  WUU0_IRQn                    = 18,               /**< Wake Up Unit interrupt */
  CAN0_IRQn                    = 19,               /**< Controller Area Network 0 interrupt */
  CAN1_IRQn                    = 20,               /**< Controller Area Network 1 interrupt */
  FLEXIO_IRQn                  = 23,               /**< Flexible Input/Output interrupt */
  I3C0_IRQn                    = 24,               /**< Improved Inter Integrated Circuit interrupt 0 */
  I3C1_IRQn                    = 25,               /**< Improved Inter Integrated Circuit interrupt 1 */
  LPI2C0_IRQn                  = 26,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPI2C1_IRQn                  = 27,               /**< Low-Power Inter Integrated Circuit 1 interrupt */
  LPSPI0_IRQn                  = 28,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  LPSPI1_IRQn                  = 29,               /**< Low-Power Serial Peripheral Interface 1 interrupt */
  LPSPI2_IRQn                  = 30,               /**< Low-Power Serial Peripheral Interface 2 interrupt */
  LPUART0_IRQn                 = 31,               /**< Low-Power Universal Asynchronous Receive/Transmit 0 interrupt */
  LPUART1_IRQn                 = 32,               /**< Low-Power Universal Asynchronous Receive/Transmit 1 interrupt */
  LPUART2_IRQn                 = 33,               /**< Low-Power Universal Asynchronous Receive/Transmit 2 interrupt */
  LPUART3_IRQn                 = 34,               /**< Low-Power Universal Asynchronous Receive/Transmit 3 interrupt */
  LPUART4_IRQn                 = 35,               /**< Low-Power Universal Asynchronous Receive/Transmit 4 interrupt */
  CDOG0_IRQn                   = 38,               /**< Code Watchdog Timer 0 interrupt */
  CTIMER0_IRQn                 = 39,               /**< Standard counter/timer 0 interrupt */
  CTIMER1_IRQn                 = 40,               /**< Standard counter/timer 1 interrupt */
  CTIMER2_IRQn                 = 41,               /**< Standard counter/timer 2 interrupt */
  CTIMER3_IRQn                 = 42,               /**< Standard counter/timer 3 interrupt */
  CTIMER4_IRQn                 = 43,               /**< Standard counter/timer 4 interrupt */
  FREQME0_IRQn                 = 54,               /**< Frequency Measurement interrupt */
  LPTMR0_IRQn                  = 55,               /**< Low Power Timer 0 interrupt */
  OS_EVENT_IRQn                = 57,               /**< OS event timer interrupt */
  WAKETIMER0_IRQn              = 58,               /**< Wake Timer Interrupt */
  UTICK0_IRQn                  = 59,               /**< Micro-Tick Timer interrupt */
  WWDT0_IRQn                   = 60,               /**< Windowed Watchdog Timer 0 interrupt */
  WWDT1_IRQn                   = 61,               /**< Windowed Watchdog Timer 2 interrupt */
  ADC0_IRQn                    = 62,               /**< Analog-to-Digital Converter 0 interrupt */
  ADC1_IRQn                    = 63,               /**< Analog-to-Digital Converter 1 interrupt */
  CMP0_IRQn                    = 64,               /**< Comparator 0 interrupt */
  DAC0_IRQn                    = 67,               /**< Digital-to-Analog Converter 0 - General Purpose interrupt */
  DAC1_IRQn                    = 68,               /**< Digital-to-Analog Converter 1 - General Purpose interrupt */
  GPIO0_IRQn                   = 71,               /**< General Purpose Input/Output 0 interrupt 0 */
  GPIO1_IRQn                   = 72,               /**< General Purpose Input/Output 1 interrupt 0 */
  GPIO2_IRQn                   = 73,               /**< General Purpose Input/Output 2 interrupt 0 */
  GPIO3_IRQn                   = 74,               /**< General Purpose Input/Output 3 interrupt 0 */
  GPIO4_IRQn                   = 75,               /**< General Purpose Input/Output 4 interrupt 0 */
  GPIO5_IRQn                   = 76,               /**< General Purpose Input/Output 5 interrupt 0 */
  LPI2C2_IRQn                  = 77,               /**< Low-Power Inter Integrated Circuit 2 interrupt */
  LPI2C3_IRQn                  = 78,               /**< Low-Power Inter Integrated Circuit 3 interrupt */
  ESPI_IRQn                    = 89,               /**< eSPI interrupt */
  ETHERNET_IRQn                = 90,               /**< Ethernet QoS interrupt */
  ETHERNET_PMT_IRQn            = 91,               /**< Ethernet QoS power management interrupt */
  TENBASET_PHY0_IRQn           = 93,               /**< 10Base-T1S interrupt */
  I3C2_IRQn                    = 94,               /**< Improved Inter Integrated Circuit interrupt 2 */
  LPUART5_IRQn                 = 95,               /**< Low-Power Universal Asynchronous Receive/Transmit interrupt */
  LPSPI3_IRQn                  = 97,               /**< Low-Power Serial Peripheral Interface 3 interrupt */
  LPSPI4_IRQn                  = 98,               /**< Low-Power Serial Peripheral Interface 4 interrupt */
  LPSPI5_IRQn                  = 99,               /**< Low-Power Serial Peripheral Interface 5 interrupt */
  LPI2C4_IRQn                  = 100,              /**< Low-Power Inter Integrated Circuit 4 interrupt */
  I3C3_IRQn                    = 101,              /**< Improved Inter Integrated Circuit interrupt 3 */
  USB1_HS_IRQn                 = 103,              /**< USB High Speed OTG Controller interrupt  */
  USB1_HS_PHY_IRQn             = 104,              /**< USBHS DCD or USBHS Phy interrupt */
  FLEXSPI0_IRQn                = 106,              /**< Flexible Serial Peripheral Interface interrupt */
  SMARTDMA_IRQn                = 108,              /**< SmartDMA interrupt */
  CDOG1_IRQn                   = 109,              /**< Code Watchdog Timer 1 interrupt */
  PKC_IRQn                     = 110,              /**< PKC interrupt */
  SGI_IRQn                     = 111,              /**< SGI interrupt */
  Reserved128_IRQn             = 112,              /**< Reserved interrupt */
  TRNG0_IRQn                   = 113,              /**< True Random Number Generator interrupt */
  SECURE_ERR_IRQn              = 114,              /**< Secure IP Error interrupt. It OR SGI, PKC, TRNG error together.  */
  SEC_HYPERVISOR_CALL_IRQn     = 115,              /**< AHB Secure Controller hypervisor call interrupt */
  RTC_IRQn                     = 119,              /**< RTC alarm interrupt */
  DGDET0_IRQn                  = 122,              /**< Digital Glitch Detect 0 interrupt  */
  EWM_IRQn                     = 123,              /**< External Watchdog Monitor interrupt */
  TSI_END_OF_SCAN_IRQn         = 124,              /**< TSI End of Scan interrupt */
  TSI_OUT_OF_SCAN_IRQn         = 125,              /**< TSI Out of Scan interrupt */
  GPIO0_1_IRQn                 = 126,              /**< General Purpose Input/Output 0 interrupt 1 */
  GPIO1_1_IRQn                 = 127,              /**< General Purpose Input/Output 1 interrupt 1 */
  GPIO2_1_IRQn                 = 128,              /**< General Purpose Input/Output 2 interrupt 1 */
  GPIO3_1_IRQn                 = 129,              /**< General Purpose Input/Output 3 interrupt 1 */
  GPIO4_1_IRQn                 = 130,              /**< General Purpose Input/Output 4 interrupt 1 */
  GPIO5_1_IRQn                 = 131,              /**< General Purpose Input/Output 5 interrupt 1 */
  ITRC0_IRQn                   = 133,              /**< Intrusion and Tamper Response Controller interrupt */
  DMA0_CH8_IRQn                = 134,              /**< DMA3_0_CH8 error or transfer complete */
  DMA0_CH9_IRQn                = 135,              /**< DMA3_0_CH9 error or transfer complete */
  DMA0_CH10_IRQn               = 136,              /**< DMA3_0_CH10 error or transfer complete */
  DMA0_CH11_IRQn               = 137,              /**< DMA3_0_CH11 error or transfer complete */
  DMA1_CH0_IRQn                = 142,              /**< DMA3_1_CH0 error or transfer complete */
  DMA1_CH1_IRQn                = 143,              /**< DMA3_1_CH1 error or transfer complete */
  DMA1_CH2_IRQn                = 144,              /**< DMA3_1_CH2 error or transfer complete */
  DMA1_CH3_IRQn                = 145               /**< DMA3_1_CH3 error or transfer complete */
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
#include "system_MCXA577.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXA577_SERIES
#define MCXA577_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXA577_features.h"

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup eim_memory_channel_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_memory_channel
 *
 *
 * Defines the structure for the EIM resource collections.
 */
typedef enum _eim_memory_channel
{
    kEIM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
} eim_memory_channel_t;

/* @} */

/*!
 * @addtogroup eim_error_injection_channel_enab_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_error_injection_channel_enable
 *
 *
 * Defines the structure for the EIM error injection resource collections.
 */
typedef enum _eim_error_injection_channel_enab
{
    kEIM_MemoryChannelRAMAEnable    = 0x80000000U, /**< Memory channel 0(RAMA0) error injection enable */
} eim_error_injection_channel_enab_t;

/* @} */

/*!
 * @addtogroup erm_memory_channel_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the erm_memory_channel
 *
 *
 * Defines the structure for the ERM resource collections.
 */
typedef enum _erm_memory_channel
{
    kERM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
    kERM_MemoryChannelFLASH         = 1U,          /**< Memory FLASH */
} erm_memory_channel_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x500AF000u)
  /** Peripheral ADC0 base address */
  #define ADC0_BASE_NS                             (0x400AF000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Peripheral ADC0 base pointer */
  #define ADC0_NS                                  ((ADC_Type *)ADC0_BASE_NS)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x500B0000u)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE_NS                             (0x400B0000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Peripheral ADC1 base pointer */
  #define ADC1_NS                                  ((ADC_Type *)ADC1_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0, ADC1 }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { ADC0_BASE_NS, ADC1_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { ADC0_NS, ADC1_NS }
#else
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x400AF000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x400B0000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0, ADC1 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn, ADC1_IRQn }

/* AHBSC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AHBSC base address */
  #define AHBSC_BASE                               (0x50044000u)
  /** Peripheral AHBSC base address */
  #define AHBSC_BASE_NS                            (0x40044000u)
  /** Peripheral AHBSC base pointer */
  #define AHBSC                                    ((AHBSC_Type *)AHBSC_BASE)
  /** Peripheral AHBSC base pointer */
  #define AHBSC_NS                                 ((AHBSC_Type *)AHBSC_BASE_NS)
  /** Array initializer of AHBSC peripheral base addresses */
  #define AHBSC_BASE_ADDRS                         { AHBSC_BASE }
  /** Array initializer of AHBSC peripheral base pointers */
  #define AHBSC_BASE_PTRS                          { AHBSC }
  /** Array initializer of AHBSC peripheral base addresses */
  #define AHBSC_BASE_ADDRS_NS                      { AHBSC_BASE_NS }
  /** Array initializer of AHBSC peripheral base pointers */
  #define AHBSC_BASE_PTRS_NS                       { AHBSC_NS }
#else
  /** Peripheral AHBSC base address */
  #define AHBSC_BASE                               (0x40044000u)
  /** Peripheral AHBSC base pointer */
  #define AHBSC                                    ((AHBSC_Type *)AHBSC_BASE)
  /** Array initializer of AHBSC peripheral base addresses */
  #define AHBSC_BASE_ADDRS                         { AHBSC_BASE }
  /** Array initializer of AHBSC peripheral base pointers */
  #define AHBSC_BASE_PTRS                          { AHBSC }
#endif

/* AOI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AOI0 base address */
  #define AOI0_BASE                                (0x500C4000u)
  /** Peripheral AOI0 base address */
  #define AOI0_BASE_NS                             (0x400C4000u)
  /** Peripheral AOI0 base pointer */
  #define AOI0                                     ((AOI_Type *)AOI0_BASE)
  /** Peripheral AOI0 base pointer */
  #define AOI0_NS                                  ((AOI_Type *)AOI0_BASE_NS)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI0_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI0 }
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS_NS                        { AOI0_BASE_NS }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS_NS                         { AOI0_NS }
#else
  /** Peripheral AOI0 base address */
  #define AOI0_BASE                                (0x400C4000u)
  /** Peripheral AOI0 base pointer */
  #define AOI0                                     ((AOI_Type *)AOI0_BASE)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI0_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI0 }
#endif

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN0 base address */
  #define CAN0_BASE                                (0x500CC000u)
  /** Peripheral CAN0 base address */
  #define CAN0_BASE_NS                             (0x400CC000u)
  /** Peripheral CAN0 base pointer */
  #define CAN0                                     ((CAN_Type *)CAN0_BASE)
  /** Peripheral CAN0 base pointer */
  #define CAN0_NS                                  ((CAN_Type *)CAN0_BASE_NS)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x500D0000u)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE_NS                             (0x400D0000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Peripheral CAN1 base pointer */
  #define CAN1_NS                                  ((CAN_Type *)CAN1_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN0, CAN1 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { CAN0_BASE_NS, CAN1_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { CAN0_NS, CAN1_NS }
#else
  /** Peripheral CAN0 base address */
  #define CAN0_BASE                                (0x400CC000u)
  /** Peripheral CAN0 base pointer */
  #define CAN0                                     ((CAN_Type *)CAN0_BASE)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x400D0000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN0, CAN1 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_IRQn, CAN1_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_IRQn, CAN1_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_IRQn, CAN1_IRQn }
#define CAN_Error_IRQS                           { CAN0_IRQn, CAN1_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_IRQn, CAN1_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { CAN0_IRQn, CAN1_IRQn }

/* CDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE                               (0x50040000u)
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE_NS                            (0x40040000u)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0_NS                                 ((CDOG_Type *)CDOG0_BASE_NS)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE                               (0x50041000u)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE_NS                            (0x40041000u)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1                                    ((CDOG_Type *)CDOG1_BASE)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1_NS                                 ((CDOG_Type *)CDOG1_BASE_NS)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG0_BASE, CDOG1_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG0, CDOG1 }
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS_NS                       { CDOG0_BASE_NS, CDOG1_BASE_NS }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS_NS                        { CDOG0_NS, CDOG1_NS }
#else
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE                               (0x40040000u)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE                               (0x40041000u)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1                                    ((CDOG_Type *)CDOG1_BASE)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG0_BASE, CDOG1_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG0, CDOG1 }
#endif
/** Interrupt vectors for the CDOG peripheral type */
#define CDOG_IRQS                                { CDOG0_IRQn, CDOG1_IRQn }

/* CMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMC base address */
  #define CMC_BASE                                 (0x500C6000u)
  /** Peripheral CMC base address */
  #define CMC_BASE_NS                              (0x400C6000u)
  /** Peripheral CMC base pointer */
  #define CMC                                      ((CMC_Type *)CMC_BASE)
  /** Peripheral CMC base pointer */
  #define CMC_NS                                   ((CMC_Type *)CMC_BASE_NS)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC }
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS_NS                        { CMC_BASE_NS }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS_NS                         { CMC_NS }
#else
  /** Peripheral CMC base address */
  #define CMC_BASE                                 (0x400C6000u)
  /** Peripheral CMC base pointer */
  #define CMC                                      ((CMC_Type *)CMC_BASE)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC }
#endif
/** Interrupt vectors for the CMC peripheral type */
#define CMC_IRQS                                 { CMC_IRQn }
/* Backward compatibility for CMC */
#define CMC_SRAMDIS_DIS_MASK                     (0xFFFFFFFFU)
#define CMC_SRAMDIS_DIS_SHIFT                    (0U)
/*! DIS - SRAM Disable */
#define CMC_SRAMDIS_DIS(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS_SHIFT)) & CMC_SRAMDIS_DIS_MASK)

#define CMC_SRAMRET_RET_MASK                     (0xFFFFFFFFU)
#define CMC_SRAMRET_RET_SHIFT                    (0U)
/*! RET - SRAM Retention */
#define CMC_SRAMRET_RET(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET_SHIFT)) & CMC_SRAMRET_RET_MASK)


/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CRC0 base address */
  #define CRC0_BASE                                (0x500C5000u)
  /** Peripheral CRC0 base address */
  #define CRC0_BASE_NS                             (0x400C5000u)
  /** Peripheral CRC0 base pointer */
  #define CRC0                                     ((CRC_Type *)CRC0_BASE)
  /** Peripheral CRC0 base pointer */
  #define CRC0_NS                                  ((CRC_Type *)CRC0_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC0_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC0 }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { CRC0_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { CRC0_NS }
#else
  /** Peripheral CRC0 base address */
  #define CRC0_BASE                                (0x400C5000u)
  /** Peripheral CRC0 base pointer */
  #define CRC0                                     ((CRC_Type *)CRC0_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC0_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC0 }
#endif

/* CTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE                             (0x50004000u)
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE_NS                          (0x40004000u)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0_NS                               ((CTIMER_Type *)CTIMER0_BASE_NS)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE                             (0x50005000u)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE_NS                          (0x40005000u)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1_NS                               ((CTIMER_Type *)CTIMER1_BASE_NS)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE                             (0x50006000u)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE_NS                          (0x40006000u)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2_NS                               ((CTIMER_Type *)CTIMER2_BASE_NS)
  /** Peripheral CTIMER3 base address */
  #define CTIMER3_BASE                             (0x50007000u)
  /** Peripheral CTIMER3 base address */
  #define CTIMER3_BASE_NS                          (0x40007000u)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3_NS                               ((CTIMER_Type *)CTIMER3_BASE_NS)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE                             (0x50008000u)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE_NS                          (0x40008000u)
  /** Peripheral CTIMER4 base pointer */
  #define CTIMER4                                  ((CTIMER_Type *)CTIMER4_BASE)
  /** Peripheral CTIMER4 base pointer */
  #define CTIMER4_NS                               ((CTIMER_Type *)CTIMER4_BASE_NS)
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE, CTIMER3_BASE, CTIMER4_BASE }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2, CTIMER3, CTIMER4 }
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS_NS                     { CTIMER0_BASE_NS, CTIMER1_BASE_NS, CTIMER2_BASE_NS, CTIMER3_BASE_NS, CTIMER4_BASE_NS }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS_NS                      { CTIMER0_NS, CTIMER1_NS, CTIMER2_NS, CTIMER3_NS, CTIMER4_NS }
#else
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE                             (0x40004000u)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE                             (0x40005000u)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE                             (0x40006000u)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
  /** Peripheral CTIMER3 base address */
  #define CTIMER3_BASE                             (0x40007000u)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE                             (0x40008000u)
  /** Peripheral CTIMER4 base pointer */
  #define CTIMER4                                  ((CTIMER_Type *)CTIMER4_BASE)
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE, CTIMER3_BASE, CTIMER4_BASE }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2, CTIMER3, CTIMER4 }
#endif
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn, CTIMER2_IRQn, CTIMER3_IRQn, CTIMER4_IRQn }

/* DEBUGMAILBOX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DBGMAILBOX base address */
  #define DBGMAILBOX_BASE                          (0x50042000u)
  /** Peripheral DBGMAILBOX base address */
  #define DBGMAILBOX_BASE_NS                       (0x40042000u)
  /** Peripheral DBGMAILBOX base pointer */
  #define DBGMAILBOX                               ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE)
  /** Peripheral DBGMAILBOX base pointer */
  #define DBGMAILBOX_NS                            ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE_NS)
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS                  { DBGMAILBOX_BASE }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS                   { DBGMAILBOX }
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS_NS               { DBGMAILBOX_BASE_NS }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS_NS                { DBGMAILBOX_NS }
#else
  /** Peripheral DBGMAILBOX base address */
  #define DBGMAILBOX_BASE                          (0x40042000u)
  /** Peripheral DBGMAILBOX base pointer */
  #define DBGMAILBOX                               ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE)
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS                  { DBGMAILBOX_BASE }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS                   { DBGMAILBOX }
#endif

/* DIGTMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TDET0 base address */
  #define TDET0_BASE                               (0x500E9000u)
  /** Peripheral TDET0 base address */
  #define TDET0_BASE_NS                            (0x400E9000u)
  /** Peripheral TDET0 base pointer */
  #define TDET0                                    ((DIGTMP_Type *)TDET0_BASE)
  /** Peripheral TDET0 base pointer */
  #define TDET0_NS                                 ((DIGTMP_Type *)TDET0_BASE_NS)
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS                        { TDET0_BASE }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS                         { TDET0 }
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS_NS                     { TDET0_BASE_NS }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS_NS                      { TDET0_NS }
#else
  /** Peripheral TDET0 base address */
  #define TDET0_BASE                               (0x400E9000u)
  /** Peripheral TDET0 base pointer */
  #define TDET0                                    ((DIGTMP_Type *)TDET0_BASE)
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS                        { TDET0_BASE }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS                         { TDET0 }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x50080000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x40080000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA0 base pointer */
  #define DMA0_NS                                  ((DMA_Type *)DMA0_BASE_NS)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x50013000u)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE_NS                             (0x40013000u)
  /** Peripheral DMA1 base pointer */
  #define DMA1                                     ((DMA_Type *)DMA1_BASE)
  /** Peripheral DMA1 base pointer */
  #define DMA1_NS                                  ((DMA_Type *)DMA1_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0, DMA1 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { DMA0_BASE_NS, DMA1_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { DMA0_NS, DMA1_NS }
#else
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x40080000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x40013000u)
  /** Peripheral DMA1 base pointer */
  #define DMA1                                     ((DMA_Type *)DMA1_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0, DMA1 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA0_CH0_IRQn, DMA0_CH1_IRQn, DMA0_CH2_IRQn, DMA0_CH3_IRQn, DMA0_CH4_IRQn, DMA0_CH5_IRQn, DMA0_CH6_IRQn, DMA0_CH7_IRQn, DMA0_CH8_IRQn, DMA0_CH9_IRQn, DMA0_CH10_IRQn, DMA0_CH11_IRQn }, \
                                                   { DMA1_CH0_IRQn, DMA1_CH1_IRQn, DMA1_CH2_IRQn, DMA1_CH3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn } }

/* EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EIM0 base address */
  #define EIM0_BASE                                (0x500C7000u)
  /** Peripheral EIM0 base address */
  #define EIM0_BASE_NS                             (0x400C7000u)
  /** Peripheral EIM0 base pointer */
  #define EIM0                                     ((EIM_Type *)EIM0_BASE)
  /** Peripheral EIM0 base pointer */
  #define EIM0_NS                                  ((EIM_Type *)EIM0_BASE_NS)
  /** Array initializer of EIM peripheral base addresses */
  #define EIM_BASE_ADDRS                           { EIM0_BASE }
  /** Array initializer of EIM peripheral base pointers */
  #define EIM_BASE_PTRS                            { EIM0 }
  /** Array initializer of EIM peripheral base addresses */
  #define EIM_BASE_ADDRS_NS                        { EIM0_BASE_NS }
  /** Array initializer of EIM peripheral base pointers */
  #define EIM_BASE_PTRS_NS                         { EIM0_NS }
#else
  /** Peripheral EIM0 base address */
  #define EIM0_BASE                                (0x400C7000u)
  /** Peripheral EIM0 base pointer */
  #define EIM0                                     ((EIM_Type *)EIM0_BASE)
  /** Array initializer of EIM peripheral base addresses */
  #define EIM_BASE_ADDRS                           { EIM0_BASE }
  /** Array initializer of EIM peripheral base pointers */
  #define EIM_BASE_PTRS                            { EIM0 }
#endif

/* ENET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENET0 base address */
  #define ENET0_BASE                               (0x5001C000u)
  /** Peripheral ENET0 base address */
  #define ENET0_BASE_NS                            (0x4001C000u)
  /** Peripheral ENET0 base pointer */
  #define ENET0                                    ((ENET_Type *)ENET0_BASE)
  /** Peripheral ENET0 base pointer */
  #define ENET0_NS                                 ((ENET_Type *)ENET0_BASE_NS)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { ENET0_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { ENET0 }
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS_NS                       { ENET0_BASE_NS }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS_NS                        { ENET0_NS }
#else
  /** Peripheral ENET0 base address */
  #define ENET0_BASE                               (0x4001C000u)
  /** Peripheral ENET0 base pointer */
  #define ENET0                                    ((ENET_Type *)ENET0_BASE)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { ENET0_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { ENET0 }
#endif
/** Interrupt vectors for the ENET peripheral type */
#define ENET_IRQS                                { ETHERNET_IRQn }
#define ENET_PMT_IRQS                            { ETHERNET_PMT_IRQn }
/* Backward compatibility */
#define ENET ENET0


/* ERM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ERM0 base address */
  #define ERM0_BASE                                (0x500C8000u)
  /** Peripheral ERM0 base address */
  #define ERM0_BASE_NS                             (0x400C8000u)
  /** Peripheral ERM0 base pointer */
  #define ERM0                                     ((ERM_Type *)ERM0_BASE)
  /** Peripheral ERM0 base pointer */
  #define ERM0_NS                                  ((ERM_Type *)ERM0_BASE_NS)
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS                           { ERM0_BASE }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS                            { ERM0 }
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS_NS                        { ERM0_BASE_NS }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS_NS                         { ERM0_NS }
#else
  /** Peripheral ERM0 base address */
  #define ERM0_BASE                                (0x400C8000u)
  /** Peripheral ERM0 base pointer */
  #define ERM0                                     ((ERM_Type *)ERM0_BASE)
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS                           { ERM0_BASE }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS                            { ERM0 }
#endif

/* ESPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ESPI0 base address */
  #define ESPI0_BASE                               (0x5001F000u)
  /** Peripheral ESPI0 base address */
  #define ESPI0_BASE_NS                            (0x4001F000u)
  /** Peripheral ESPI0 base pointer */
  #define ESPI0                                    ((ESPI_Type *)ESPI0_BASE)
  /** Peripheral ESPI0 base pointer */
  #define ESPI0_NS                                 ((ESPI_Type *)ESPI0_BASE_NS)
  /** Array initializer of ESPI peripheral base addresses */
  #define ESPI_BASE_ADDRS                          { ESPI0_BASE }
  /** Array initializer of ESPI peripheral base pointers */
  #define ESPI_BASE_PTRS                           { ESPI0 }
  /** Array initializer of ESPI peripheral base addresses */
  #define ESPI_BASE_ADDRS_NS                       { ESPI0_BASE_NS }
  /** Array initializer of ESPI peripheral base pointers */
  #define ESPI_BASE_PTRS_NS                        { ESPI0_NS }
#else
  /** Peripheral ESPI0 base address */
  #define ESPI0_BASE                               (0x4001F000u)
  /** Peripheral ESPI0 base pointer */
  #define ESPI0                                    ((ESPI_Type *)ESPI0_BASE)
  /** Array initializer of ESPI peripheral base addresses */
  #define ESPI_BASE_ADDRS                          { ESPI0_BASE }
  /** Array initializer of ESPI peripheral base pointers */
  #define ESPI_BASE_PTRS                           { ESPI0 }
#endif
/** Interrupt vectors for the ESPI peripheral type */
#define ESPI_IRQS                                { ESPI_IRQn }

/* EWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EWM base address */
  #define EWM_BASE                                 (0x50010000u)
  /** Peripheral EWM base address */
  #define EWM_BASE_NS                              (0x40010000u)
  /** Peripheral EWM base pointer */
  #define EWM                                      ((EWM_Type *)EWM_BASE)
  /** Peripheral EWM base pointer */
  #define EWM_NS                                   ((EWM_Type *)EWM_BASE_NS)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM }
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS_NS                        { EWM_BASE_NS }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS_NS                         { EWM_NS }
#else
  /** Peripheral EWM base address */
  #define EWM_BASE                                 (0x40010000u)
  /** Peripheral EWM base pointer */
  #define EWM                                      ((EWM_Type *)EWM_BASE)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM }
#endif
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM_IRQn }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE                             (0x50099000u)
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE_NS                          (0x40099000u)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0_NS                               ((FLEXIO_Type *)FLEXIO0_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO0 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { FLEXIO0_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { FLEXIO0_NS }
#else
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE                             (0x40099000u)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO0 }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE                            (0x50020000u)
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE_NS                         (0x40020000u)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0_NS                              ((FLEXSPI_Type *)FLEXSPI0_BASE_NS)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI0 }
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS_NS                    { FLEXSPI0_BASE_NS }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS_NS                     { FLEXSPI0_NS }
#else
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE                            (0x40020000u)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI0 }
#endif
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FLEXSPI0_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** FlexSPI AMBA base address array */
  #define FlexSPI_AMBA_BASE_ARRAY                  { {0x90000000u} }
  /** FlexSPI AMBA end address array */
  #define FlexSPI_AMBA_END_ARRAY                   { {0x9FFFFFFFu} }
  /** FlexSPI AMBA base address array */
  #define FlexSPI_AMBA_BASE_ARRAY_NS               { {0x80000000u} }
  /** FlexSPI AMBA end address array */
  #define FlexSPI_AMBA_END_ARRAY_NS                { {0x8FFFFFFFu} }
  /** FlexSPI0 AMBA base address */
  #define FlexSPI0_AMBA_BASE                       (0x90000000u)
  /** FlexSPI0 AMBA base address */
  #define FlexSPI0_AMBA_BASE_NS                    (0x80000000u)
#else
  /** FlexSPI AMBA base address array */
  #define FlexSPI_AMBA_BASE_ARRAY                  { {0x80000000u} }
  /** FlexSPI AMBA end address array */
  #define FlexSPI_AMBA_END_ARRAY                   { {0x8FFFFFFFu} }
  /** FlexSPI0 AMBA base address */
  #define FlexSPI0_AMBA_BASE                       (0x80000000u)
#endif


/* FMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMC0 base address */
  #define FMC0_BASE                                (0x50094000u)
  /** Peripheral FMC0 base address */
  #define FMC0_BASE_NS                             (0x40094000u)
  /** Peripheral FMC0 base pointer */
  #define FMC0                                     ((FMC_Type *)FMC0_BASE)
  /** Peripheral FMC0 base pointer */
  #define FMC0_NS                                  ((FMC_Type *)FMC0_BASE_NS)
  /** Array initializer of FMC peripheral base addresses */
  #define FMC_BASE_ADDRS                           { FMC0_BASE }
  /** Array initializer of FMC peripheral base pointers */
  #define FMC_BASE_PTRS                            { FMC0 }
  /** Array initializer of FMC peripheral base addresses */
  #define FMC_BASE_ADDRS_NS                        { FMC0_BASE_NS }
  /** Array initializer of FMC peripheral base pointers */
  #define FMC_BASE_PTRS_NS                         { FMC0_NS }
#else
  /** Peripheral FMC0 base address */
  #define FMC0_BASE                                (0x40094000u)
  /** Peripheral FMC0 base pointer */
  #define FMC0                                     ((FMC_Type *)FMC0_BASE)
  /** Array initializer of FMC peripheral base addresses */
  #define FMC_BASE_ADDRS                           { FMC0_BASE }
  /** Array initializer of FMC peripheral base pointers */
  #define FMC_BASE_PTRS                            { FMC0 }
#endif

/* FMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMU0 base address */
  #define FMU0_BASE                                (0x50095000u)
  /** Peripheral FMU0 base address */
  #define FMU0_BASE_NS                             (0x40095000u)
  /** Peripheral FMU0 base pointer */
  #define FMU0                                     ((FMU_Type *)FMU0_BASE)
  /** Peripheral FMU0 base pointer */
  #define FMU0_NS                                  ((FMU_Type *)FMU0_BASE_NS)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU0_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU0 }
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS_NS                        { FMU0_BASE_NS }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS_NS                         { FMU0_NS }
#else
  /** Peripheral FMU0 base address */
  #define FMU0_BASE                                (0x40095000u)
  /** Peripheral FMU0 base pointer */
  #define FMU0                                     ((FMU_Type *)FMU0_BASE)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU0_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU0 }
#endif
/** Interrupt vectors for the FMU peripheral type */
#define FMU_IRQS                                 { FMU0_IRQn }

/* FREQME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FREQME0 base address */
  #define FREQME0_BASE                             (0x50009000u)
  /** Peripheral FREQME0 base address */
  #define FREQME0_BASE_NS                          (0x40009000u)
  /** Peripheral FREQME0 base pointer */
  #define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
  /** Peripheral FREQME0 base pointer */
  #define FREQME0_NS                               ((FREQME_Type *)FREQME0_BASE_NS)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME0_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME0 }
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS_NS                     { FREQME0_BASE_NS }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS_NS                      { FREQME0_NS }
#else
  /** Peripheral FREQME0 base address */
  #define FREQME0_BASE                             (0x40009000u)
  /** Peripheral FREQME0 base pointer */
  #define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME0_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME0 }
#endif
/** Interrupt vectors for the FREQME peripheral type */
#define FREQME_IRQS                              { FREQME0_IRQn }

/* GDET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DGDET0 base address */
  #define DGDET0_BASE                              (0x500E5000u)
  /** Peripheral DGDET0 base address */
  #define DGDET0_BASE_NS                           (0x400E5000u)
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
  #define DGDET0_BASE                              (0x400E5000u)
  /** Peripheral DGDET0 base pointer */
  #define DGDET0                                   ((GDET_Type *)DGDET0_BASE)
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS                          { DGDET0_BASE }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS                           { DGDET0 }
#endif
/** Interrupt vectors for the GDET peripheral type */
#define GDET_IRQS                                { DGDET0_IRQn }

/* GLIKEY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE                             (0x500E8000u)
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE_NS                          (0x400E8000u)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0_NS                               ((GLIKEY_Type *)GLIKEY0_BASE_NS)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY0 }
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS_NS                     { GLIKEY0_BASE_NS }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS_NS                      { GLIKEY0_NS }
#else
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE                             (0x400E8000u)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY0 }
#endif

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO0 base address */
  #define GPIO0_BASE                               (0x50048000u)
  /** Peripheral GPIO0 base address */
  #define GPIO0_BASE_NS                            (0x40048000u)
  /** Peripheral GPIO0 base pointer */
  #define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
  /** Peripheral GPIO0 base pointer */
  #define GPIO0_NS                                 ((GPIO_Type *)GPIO0_BASE_NS)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x5004A000u)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE_NS                            (0x4004A000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1_NS                                 ((GPIO_Type *)GPIO1_BASE_NS)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x5004C000u)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE_NS                            (0x4004C000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2_NS                                 ((GPIO_Type *)GPIO2_BASE_NS)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x5004E000u)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE_NS                            (0x4004E000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3_NS                                 ((GPIO_Type *)GPIO3_BASE_NS)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x50050000u)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE_NS                            (0x40050000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4_NS                                 ((GPIO_Type *)GPIO4_BASE_NS)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE                               (0x500DF000u)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE_NS                            (0x400DF000u)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5_NS                                 ((GPIO_Type *)GPIO5_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5 }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { GPIO0_BASE_NS, GPIO1_BASE_NS, GPIO2_BASE_NS, GPIO3_BASE_NS, GPIO4_BASE_NS, GPIO5_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { GPIO0_NS, GPIO1_NS, GPIO2_NS, GPIO3_NS, GPIO4_NS, GPIO5_NS }
#else
  /** Peripheral GPIO0 base address */
  #define GPIO0_BASE                               (0x40048000u)
  /** Peripheral GPIO0 base pointer */
  #define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x4004A000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x4004C000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x4004E000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x40050000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE                               (0x400DF000u)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5 }
#endif
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { GPIO0_IRQn, GPIO1_IRQn, GPIO2_IRQn, GPIO3_IRQn, GPIO4_IRQn, GPIO5_IRQn }
#define GPIO_S_IRQS                              { GPIO0_1_IRQn, GPIO1_1_IRQn, GPIO2_1_IRQn, GPIO3_1_IRQn, GPIO4_1_IRQn, GPIO5_1_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x50002000u)
  /** Peripheral I3C0 base address */
  #define I3C0_BASE_NS                             (0x40002000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C0 base pointer */
  #define I3C0_NS                                  ((I3C_Type *)I3C0_BASE_NS)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x50003000u)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE_NS                             (0x40003000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C1 base pointer */
  #define I3C1_NS                                  ((I3C_Type *)I3C1_BASE_NS)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x5009E000u)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE_NS                             (0x4009E000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C2 base pointer */
  #define I3C2_NS                                  ((I3C_Type *)I3C2_BASE_NS)
  /** Peripheral I3C3 base address */
  #define I3C3_BASE                                (0x500DE000u)
  /** Peripheral I3C3 base address */
  #define I3C3_BASE_NS                             (0x400DE000u)
  /** Peripheral I3C3 base pointer */
  #define I3C3                                     ((I3C_Type *)I3C3_BASE)
  /** Peripheral I3C3 base pointer */
  #define I3C3_NS                                  ((I3C_Type *)I3C3_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE, I3C2_BASE, I3C3_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0, I3C1, I3C2, I3C3 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { I3C0_BASE_NS, I3C1_BASE_NS, I3C2_BASE_NS, I3C3_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { I3C0_NS, I3C1_NS, I3C2_NS, I3C3_NS }
#else
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x40002000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x40003000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x4009E000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C3 base address */
  #define I3C3_BASE                                (0x400DE000u)
  /** Peripheral I3C3 base pointer */
  #define I3C3                                     ((I3C_Type *)I3C3_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE, I3C2_BASE, I3C3_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0, I3C1, I3C2, I3C3 }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C0_IRQn, I3C1_IRQn, I3C2_IRQn, I3C3_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE                           (0x50001000u)
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE_NS                        (0x40001000u)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0                                ((INPUTMUX_Type *)INPUTMUX0_BASE)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0_NS                             ((INPUTMUX_Type *)INPUTMUX0_BASE_NS)
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS                      { INPUTMUX0_BASE }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS                       { INPUTMUX0 }
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS_NS                   { INPUTMUX0_BASE_NS }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS_NS                    { INPUTMUX0_NS }
#else
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE                           (0x40001000u)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0                                ((INPUTMUX_Type *)INPUTMUX0_BASE)
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS                      { INPUTMUX0_BASE }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS                       { INPUTMUX0 }
#endif

/* ITRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ITRC0 base address */
  #define ITRC0_BASE                               (0x500E7000u)
  /** Peripheral ITRC0 base address */
  #define ITRC0_BASE_NS                            (0x400E7000u)
  /** Peripheral ITRC0 base pointer */
  #define ITRC0                                    ((ITRC_Type *)ITRC0_BASE)
  /** Peripheral ITRC0 base pointer */
  #define ITRC0_NS                                 ((ITRC_Type *)ITRC0_BASE_NS)
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS                          { ITRC0_BASE }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS                           { ITRC0 }
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS_NS                       { ITRC0_BASE_NS }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS_NS                        { ITRC0_NS }
#else
  /** Peripheral ITRC0 base address */
  #define ITRC0_BASE                               (0x400E7000u)
  /** Peripheral ITRC0 base pointer */
  #define ITRC0                                    ((ITRC_Type *)ITRC0_BASE)
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS                          { ITRC0_BASE }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS                           { ITRC0 }
#endif

/* LPCMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMP0 base address */
  #define CMP0_BASE                                (0x500B1000u)
  /** Peripheral CMP0 base address */
  #define CMP0_BASE_NS                             (0x400B1000u)
  /** Peripheral CMP0 base pointer */
  #define CMP0                                     ((LPCMP_Type *)CMP0_BASE)
  /** Peripheral CMP0 base pointer */
  #define CMP0_NS                                  ((LPCMP_Type *)CMP0_BASE_NS)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { CMP0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { CMP0 }
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS_NS                      { CMP0_BASE_NS }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS_NS                       { CMP0_NS }
#else
  /** Peripheral CMP0 base address */
  #define CMP0_BASE                                (0x400B1000u)
  /** Peripheral CMP0 base pointer */
  #define CMP0                                     ((LPCMP_Type *)CMP0_BASE)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { CMP0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { CMP0 }
#endif

/* LPDAC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DAC0 base address */
  #define DAC0_BASE                                (0x500B4000u)
  /** Peripheral DAC0 base address */
  #define DAC0_BASE_NS                             (0x400B4000u)
  /** Peripheral DAC0 base pointer */
  #define DAC0                                     ((LPDAC_Type *)DAC0_BASE)
  /** Peripheral DAC0 base pointer */
  #define DAC0_NS                                  ((LPDAC_Type *)DAC0_BASE_NS)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE                                (0x500B5000u)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE_NS                             (0x400B5000u)
  /** Peripheral DAC1 base pointer */
  #define DAC1                                     ((LPDAC_Type *)DAC1_BASE)
  /** Peripheral DAC1 base pointer */
  #define DAC1_NS                                  ((LPDAC_Type *)DAC1_BASE_NS)
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS                         { DAC0_BASE, DAC1_BASE }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS                          { DAC0, DAC1 }
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS_NS                      { DAC0_BASE_NS, DAC1_BASE_NS }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS_NS                       { DAC0_NS, DAC1_NS }
#else
  /** Peripheral DAC0 base address */
  #define DAC0_BASE                                (0x400B4000u)
  /** Peripheral DAC0 base pointer */
  #define DAC0                                     ((LPDAC_Type *)DAC0_BASE)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE                                (0x400B5000u)
  /** Peripheral DAC1 base pointer */
  #define DAC1                                     ((LPDAC_Type *)DAC1_BASE)
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS                         { DAC0_BASE, DAC1_BASE }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS                          { DAC0, DAC1 }
#endif
/** Interrupt vectors for the LPDAC peripheral type */
#define LPDAC_IRQS                               { DAC0_IRQn, DAC1_IRQn }

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x5009A000u)
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE_NS                           (0x4009A000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0_NS                                ((LPI2C_Type *)LPI2C0_BASE_NS)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x5009B000u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x4009B000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x500D4000u)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE_NS                           (0x400D4000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2_NS                                ((LPI2C_Type *)LPI2C2_BASE_NS)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x500D5000u)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE_NS                           (0x400D5000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3_NS                                ((LPI2C_Type *)LPI2C3_BASE_NS)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x500D6000u)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE_NS                           (0x400D6000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4_NS                                ((LPI2C_Type *)LPI2C4_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { LPI2C0_BASE_NS, LPI2C1_BASE_NS, LPI2C2_BASE_NS, LPI2C3_BASE_NS, LPI2C4_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { LPI2C0_NS, LPI2C1_NS, LPI2C2_NS, LPI2C3_NS, LPI2C4_NS }
#else
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x4009A000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x4009B000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x400D4000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x400D5000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x400D6000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x5009C000u)
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE_NS                           (0x4009C000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0_NS                                ((LPSPI_Type *)LPSPI0_BASE_NS)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x5009D000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x4009D000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1_NS                                ((LPSPI_Type *)LPSPI1_BASE_NS)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x50021000u)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE_NS                           (0x40021000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2_NS                                ((LPSPI_Type *)LPSPI2_BASE_NS)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x50022000u)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE_NS                           (0x40022000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3_NS                                ((LPSPI_Type *)LPSPI3_BASE_NS)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x50023000u)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE_NS                           (0x40023000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4_NS                                ((LPSPI_Type *)LPSPI4_BASE_NS)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x50024000u)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE_NS                           (0x40024000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5_NS                                ((LPSPI_Type *)LPSPI5_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { LPSPI0_BASE_NS, LPSPI1_BASE_NS, LPSPI2_BASE_NS, LPSPI3_BASE_NS, LPSPI4_BASE_NS, LPSPI5_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { LPSPI0_NS, LPSPI1_NS, LPSPI2_NS, LPSPI3_NS, LPSPI4_NS, LPSPI5_NS }
#else
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x4009C000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x4009D000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x40021000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x40022000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x40023000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x40024000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE                              (0x500AB000u)
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE_NS                           (0x400AB000u)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0_NS                                ((LPTMR_Type *)LPTMR0_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR0_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR0 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { LPTMR0_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { LPTMR0_NS }
#else
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE                              (0x400AB000u)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR0_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR0 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x5009F000u)
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE_NS                          (0x4009F000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0_NS                               ((LPUART_Type *)LPUART0_BASE_NS)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x500A0000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x400A0000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x500A1000u)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE_NS                          (0x400A1000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2_NS                               ((LPUART_Type *)LPUART2_BASE_NS)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x500A2000u)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE_NS                          (0x400A2000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3_NS                               ((LPUART_Type *)LPUART3_BASE_NS)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x500A3000u)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE_NS                          (0x400A3000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4_NS                               ((LPUART_Type *)LPUART4_BASE_NS)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x500DA000u)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE_NS                          (0x400DA000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5_NS                               ((LPUART_Type *)LPUART5_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { LPUART0_BASE_NS, LPUART1_BASE_NS, LPUART2_BASE_NS, LPUART3_BASE_NS, LPUART4_BASE_NS, LPUART5_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { LPUART0_NS, LPUART1_NS, LPUART2_NS, LPUART3_NS, LPUART4_NS, LPUART5_NS }
#else
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x4009F000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x400A0000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x400A1000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x400A2000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x400A3000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x400DA000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn }

/* MRCC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRCC0 base address */
  #define MRCC0_BASE                               (0x50091800u)
  /** Peripheral MRCC0 base address */
  #define MRCC0_BASE_NS                            (0x40091800u)
  /** Peripheral MRCC0 base pointer */
  #define MRCC0                                    ((MRCC_Type *)MRCC0_BASE)
  /** Peripheral MRCC0 base pointer */
  #define MRCC0_NS                                 ((MRCC_Type *)MRCC0_BASE_NS)
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS                          { MRCC0_BASE }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS                           { MRCC0 }
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS_NS                       { MRCC0_BASE_NS }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS_NS                        { MRCC0_NS }
#else
  /** Peripheral MRCC0 base address */
  #define MRCC0_BASE                               (0x40091800u)
  /** Peripheral MRCC0 base pointer */
  #define MRCC0                                    ((MRCC_Type *)MRCC0_BASE)
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS                          { MRCC0_BASE }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS                           { MRCC0 }
#endif

/* OSTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE                            (0x500AD000u)
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE_NS                         (0x400AD000u)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0                                 ((OSTIMER_Type *)OSTIMER0_BASE)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0_NS                              ((OSTIMER_Type *)OSTIMER0_BASE_NS)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER0 }
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS_NS                    { OSTIMER0_BASE_NS }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS_NS                     { OSTIMER0_NS }
#else
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE                            (0x400AD000u)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0                                 ((OSTIMER_Type *)OSTIMER0_BASE)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER0 }
#endif
/** Interrupt vectors for the OSTIMER peripheral type */
#define OSTIMER_IRQS                             { OS_EVENT_IRQn }

/* PKC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PKC0 base address */
  #define PKC0_BASE                                (0x50012000u)
  /** Peripheral PKC0 base address */
  #define PKC0_BASE_NS                             (0x40012000u)
  /** Peripheral PKC0 base pointer */
  #define PKC0                                     ((PKC_Type *)PKC0_BASE)
  /** Peripheral PKC0 base pointer */
  #define PKC0_NS                                  ((PKC_Type *)PKC0_BASE_NS)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC0_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC0 }
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS_NS                        { PKC0_BASE_NS }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS_NS                         { PKC0_NS }
#else
  /** Peripheral PKC0 base address */
  #define PKC0_BASE                                (0x40012000u)
  /** Peripheral PKC0 base pointer */
  #define PKC0                                     ((PKC_Type *)PKC0_BASE)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC0_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC0 }
#endif
/** Interrupt vectors for the PKC peripheral type */
#define PKC_IRQS                                 { PKC_IRQn }

/* PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PORT0 base address */
  #define PORT0_BASE                               (0x500BC000u)
  /** Peripheral PORT0 base address */
  #define PORT0_BASE_NS                            (0x400BC000u)
  /** Peripheral PORT0 base pointer */
  #define PORT0                                    ((PORT_Type *)PORT0_BASE)
  /** Peripheral PORT0 base pointer */
  #define PORT0_NS                                 ((PORT_Type *)PORT0_BASE_NS)
  /** Peripheral PORT1 base address */
  #define PORT1_BASE                               (0x500BD000u)
  /** Peripheral PORT1 base address */
  #define PORT1_BASE_NS                            (0x400BD000u)
  /** Peripheral PORT1 base pointer */
  #define PORT1                                    ((PORT_Type *)PORT1_BASE)
  /** Peripheral PORT1 base pointer */
  #define PORT1_NS                                 ((PORT_Type *)PORT1_BASE_NS)
  /** Peripheral PORT2 base address */
  #define PORT2_BASE                               (0x500BE000u)
  /** Peripheral PORT2 base address */
  #define PORT2_BASE_NS                            (0x400BE000u)
  /** Peripheral PORT2 base pointer */
  #define PORT2                                    ((PORT_Type *)PORT2_BASE)
  /** Peripheral PORT2 base pointer */
  #define PORT2_NS                                 ((PORT_Type *)PORT2_BASE_NS)
  /** Peripheral PORT3 base address */
  #define PORT3_BASE                               (0x500BF000u)
  /** Peripheral PORT3 base address */
  #define PORT3_BASE_NS                            (0x400BF000u)
  /** Peripheral PORT3 base pointer */
  #define PORT3                                    ((PORT_Type *)PORT3_BASE)
  /** Peripheral PORT3 base pointer */
  #define PORT3_NS                                 ((PORT_Type *)PORT3_BASE_NS)
  /** Peripheral PORT4 base address */
  #define PORT4_BASE                               (0x500C0000u)
  /** Peripheral PORT4 base address */
  #define PORT4_BASE_NS                            (0x400C0000u)
  /** Peripheral PORT4 base pointer */
  #define PORT4                                    ((PORT_Type *)PORT4_BASE)
  /** Peripheral PORT4 base pointer */
  #define PORT4_NS                                 ((PORT_Type *)PORT4_BASE_NS)
  /** Peripheral PORT5 base address */
  #define PORT5_BASE                               (0x500E3000u)
  /** Peripheral PORT5 base address */
  #define PORT5_BASE_NS                            (0x400E3000u)
  /** Peripheral PORT5 base pointer */
  #define PORT5                                    ((PORT_Type *)PORT5_BASE)
  /** Peripheral PORT5 base pointer */
  #define PORT5_NS                                 ((PORT_Type *)PORT5_BASE_NS)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE, PORT4_BASE, PORT5_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { PORT0, PORT1, PORT2, PORT3, PORT4, PORT5 }
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS_NS                       { PORT0_BASE_NS, PORT1_BASE_NS, PORT2_BASE_NS, PORT3_BASE_NS, PORT4_BASE_NS, PORT5_BASE_NS }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS_NS                        { PORT0_NS, PORT1_NS, PORT2_NS, PORT3_NS, PORT4_NS, PORT5_NS }
#else
  /** Peripheral PORT0 base address */
  #define PORT0_BASE                               (0x400BC000u)
  /** Peripheral PORT0 base pointer */
  #define PORT0                                    ((PORT_Type *)PORT0_BASE)
  /** Peripheral PORT1 base address */
  #define PORT1_BASE                               (0x400BD000u)
  /** Peripheral PORT1 base pointer */
  #define PORT1                                    ((PORT_Type *)PORT1_BASE)
  /** Peripheral PORT2 base address */
  #define PORT2_BASE                               (0x400BE000u)
  /** Peripheral PORT2 base pointer */
  #define PORT2                                    ((PORT_Type *)PORT2_BASE)
  /** Peripheral PORT3 base address */
  #define PORT3_BASE                               (0x400BF000u)
  /** Peripheral PORT3 base pointer */
  #define PORT3                                    ((PORT_Type *)PORT3_BASE)
  /** Peripheral PORT4 base address */
  #define PORT4_BASE                               (0x400C0000u)
  /** Peripheral PORT4 base pointer */
  #define PORT4                                    ((PORT_Type *)PORT4_BASE)
  /** Peripheral PORT5 base address */
  #define PORT5_BASE                               (0x400E3000u)
  /** Peripheral PORT5 base pointer */
  #define PORT5                                    ((PORT_Type *)PORT5_BASE)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE, PORT4_BASE, PORT5_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { PORT0, PORT1, PORT2, PORT3, PORT4, PORT5 }
#endif

/* RTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RTC0 base address */
  #define RTC0_BASE                                (0x500EE000u)
  /** Peripheral RTC0 base address */
  #define RTC0_BASE_NS                             (0x400EE000u)
  /** Peripheral RTC0 base pointer */
  #define RTC0                                     ((RTC_Type *)RTC0_BASE)
  /** Peripheral RTC0 base pointer */
  #define RTC0_NS                                  ((RTC_Type *)RTC0_BASE_NS)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC0_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC0 }
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS_NS                        { RTC0_BASE_NS }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS_NS                         { RTC0_NS }
#else
  /** Peripheral RTC0 base address */
  #define RTC0_BASE                                (0x400EE000u)
  /** Peripheral RTC0 base pointer */
  #define RTC0                                     ((RTC_Type *)RTC0_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC0_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC0 }
#endif
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }

/* SCG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SCG0 base address */
  #define SCG0_BASE                                (0x500CA000u)
  /** Peripheral SCG0 base address */
  #define SCG0_BASE_NS                             (0x400CA000u)
  /** Peripheral SCG0 base pointer */
  #define SCG0                                     ((SCG_Type *)SCG0_BASE)
  /** Peripheral SCG0 base pointer */
  #define SCG0_NS                                  ((SCG_Type *)SCG0_BASE_NS)
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS                           { SCG0_BASE }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS                            { SCG0 }
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS_NS                        { SCG0_BASE_NS }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS_NS                         { SCG0_NS }
#else
  /** Peripheral SCG0 base address */
  #define SCG0_BASE                                (0x400CA000u)
  /** Peripheral SCG0 base pointer */
  #define SCG0                                     ((SCG_Type *)SCG0_BASE)
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS                           { SCG0_BASE }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS                            { SCG0 }
#endif

/* SECCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SECCON base address */
  #define SECCON_BASE                              (0x500EA000u)
  /** Peripheral SECCON base address */
  #define SECCON_BASE_NS                           (0x400EA000u)
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
  #define SECCON_BASE                              (0x400EA000u)
  /** Peripheral SECCON base pointer */
  #define SECCON                                   ((SECCON_Type *)SECCON_BASE)
  /** Array initializer of SECCON peripheral base addresses */
  #define SECCON_BASE_ADDRS                        { SECCON_BASE }
  /** Array initializer of SECCON peripheral base pointers */
  #define SECCON_BASE_PTRS                         { SECCON }
#endif

/* SGI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SGI0 base address */
  #define SGI0_BASE                                (0x500EB000u)
  /** Peripheral SGI0 base address */
  #define SGI0_BASE_NS                             (0x400EB000u)
  /** Peripheral SGI0 base pointer */
  #define SGI0                                     ((SGI_Type *)SGI0_BASE)
  /** Peripheral SGI0 base pointer */
  #define SGI0_NS                                  ((SGI_Type *)SGI0_BASE_NS)
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS                           { SGI0_BASE }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS                            { SGI0 }
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS_NS                        { SGI0_BASE_NS }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS_NS                         { SGI0_NS }
#else
  /** Peripheral SGI0 base address */
  #define SGI0_BASE                                (0x400EB000u)
  /** Peripheral SGI0 base pointer */
  #define SGI0                                     ((SGI_Type *)SGI0_BASE)
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS                           { SGI0_BASE }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS                            { SGI0 }
#endif

/* SMARTDMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SMARTDMA base address */
  #define SMARTDMA_BASE                            (0x5000E000u)
  /** Peripheral SMARTDMA base address */
  #define SMARTDMA_BASE_NS                         (0x4000E000u)
  /** Peripheral SMARTDMA base pointer */
  #define SMARTDMA                                 ((SMARTDMA_Type *)SMARTDMA_BASE)
  /** Peripheral SMARTDMA base pointer */
  #define SMARTDMA_NS                              ((SMARTDMA_Type *)SMARTDMA_BASE_NS)
  /** Array initializer of SMARTDMA peripheral base addresses */
  #define SMARTDMA_BASE_ADDRS                      { SMARTDMA_BASE }
  /** Array initializer of SMARTDMA peripheral base pointers */
  #define SMARTDMA_BASE_PTRS                       { SMARTDMA }
  /** Array initializer of SMARTDMA peripheral base addresses */
  #define SMARTDMA_BASE_ADDRS_NS                   { SMARTDMA_BASE_NS }
  /** Array initializer of SMARTDMA peripheral base pointers */
  #define SMARTDMA_BASE_PTRS_NS                    { SMARTDMA_NS }
#else
  /** Peripheral SMARTDMA base address */
  #define SMARTDMA_BASE                            (0x4000E000u)
  /** Peripheral SMARTDMA base pointer */
  #define SMARTDMA                                 ((SMARTDMA_Type *)SMARTDMA_BASE)
  /** Array initializer of SMARTDMA peripheral base addresses */
  #define SMARTDMA_BASE_ADDRS                      { SMARTDMA_BASE }
  /** Array initializer of SMARTDMA peripheral base pointers */
  #define SMARTDMA_BASE_PTRS                       { SMARTDMA }
#endif

/* SPC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPC0 base address */
  #define SPC0_BASE                                (0x500CB000u)
  /** Peripheral SPC0 base address */
  #define SPC0_BASE_NS                             (0x400CB000u)
  /** Peripheral SPC0 base pointer */
  #define SPC0                                     ((SPC_Type *)SPC0_BASE)
  /** Peripheral SPC0 base pointer */
  #define SPC0_NS                                  ((SPC_Type *)SPC0_BASE_NS)
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS                           { SPC0_BASE }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS                            { SPC0 }
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS_NS                        { SPC0_BASE_NS }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS_NS                         { SPC0_NS }
#else
  /** Peripheral SPC0 base address */
  #define SPC0_BASE                                (0x400CB000u)
  /** Peripheral SPC0 base pointer */
  #define SPC0                                     ((SPC_Type *)SPC0_BASE)
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS                           { SPC0_BASE }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS                            { SPC0 }
#endif

/* SYSCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE                              (0x50091000u)
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE_NS                           (0x40091000u)
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
  #define SYSCON_BASE                              (0x40091000u)
  /** Peripheral SYSCON base pointer */
  #define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS                         { SYSCON }
#endif

/* TENBASET_PHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral T1S0 base address */
  #define T1S0_BASE                                (0x5002D000u)
  /** Peripheral T1S0 base address */
  #define T1S0_BASE_NS                             (0x4002D000u)
  /** Peripheral T1S0 base pointer */
  #define T1S0                                     ((TENBASET_PHY_Type *)T1S0_BASE)
  /** Peripheral T1S0 base pointer */
  #define T1S0_NS                                  ((TENBASET_PHY_Type *)T1S0_BASE_NS)
  /** Array initializer of TENBASET_PHY peripheral base addresses */
  #define TENBASET_PHY_BASE_ADDRS                  { T1S0_BASE }
  /** Array initializer of TENBASET_PHY peripheral base pointers */
  #define TENBASET_PHY_BASE_PTRS                   { T1S0 }
  /** Array initializer of TENBASET_PHY peripheral base addresses */
  #define TENBASET_PHY_BASE_ADDRS_NS               { T1S0_BASE_NS }
  /** Array initializer of TENBASET_PHY peripheral base pointers */
  #define TENBASET_PHY_BASE_PTRS_NS                { T1S0_NS }
#else
  /** Peripheral T1S0 base address */
  #define T1S0_BASE                                (0x4002D000u)
  /** Peripheral T1S0 base pointer */
  #define T1S0                                     ((TENBASET_PHY_Type *)T1S0_BASE)
  /** Array initializer of TENBASET_PHY peripheral base addresses */
  #define TENBASET_PHY_BASE_ADDRS                  { T1S0_BASE }
  /** Array initializer of TENBASET_PHY peripheral base pointers */
  #define TENBASET_PHY_BASE_PTRS                   { T1S0 }
#endif
/** Interrupt vectors for the TENBASET_PHY peripheral type */
#define TENBASET_PHY_IRQS                        { TENBASET_PHY0_IRQn }

/* TRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MBC0 base address */
  #define MBC0_BASE                                (0x500C9000u)
  /** Peripheral MBC0 base address */
  #define MBC0_BASE_NS                             (0x400C9000u)
  /** Peripheral MBC0 base pointer */
  #define MBC0                                     ((TRDC_Type *)MBC0_BASE)
  /** Peripheral MBC0 base pointer */
  #define MBC0_NS                                  ((TRDC_Type *)MBC0_BASE_NS)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { MBC0_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { MBC0 }
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS_NS                       { MBC0_BASE_NS }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS_NS                        { MBC0_NS }
#else
  /** Peripheral MBC0 base address */
  #define MBC0_BASE                                (0x400C9000u)
  /** Peripheral MBC0 base pointer */
  #define MBC0                                     ((TRDC_Type *)MBC0_BASE)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { MBC0_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { MBC0 }
#endif
/** Interrupt vectors for the TRDC peripheral type */
#define TRDC_IRQS                                { MBC0_IRQn }
#define MBC0_MEMORY_CFG_WORD_COUNT {1,2,4,1}
#define MBC1_MEMORY_CFG_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_CFG_WORD_COUNT {9,6,1,1}
#define MBC3_MEMORY_CFG_WORD_COUNT {3,0,0,0}
#define MBC_MEMORY_CFG_WORD_COUNT {MBC0_MEMORY_CFG_WORD_COUNT , MBC1_MEMORY_CFG_WORD_COUNT, MBC2_MEMORY_CFG_WORD_COUNT, MBC3_MEMORY_CFG_WORD_COUNT}
#define MBC0_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC1_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_NSE_WORD_COUNT {3,2,1,1}
#define MBC3_MEMORY_NSE_WORD_COUNT {1,0,0,0}
#define MBC_MEMORY_NSE_WORD_COUNT {MBC0_MEMORY_NSE_WORD_COUNT , MBC1_MEMORY_NSE_WORD_COUNT, MBC2_MEMORY_NSE_WORD_COUNT, MBC3_MEMORY_NSE_WORD_COUNT}


/* TRNG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRNG0 base address */
  #define TRNG0_BASE                               (0x500EC000u)
  /** Peripheral TRNG0 base address */
  #define TRNG0_BASE_NS                            (0x400EC000u)
  /** Peripheral TRNG0 base pointer */
  #define TRNG0                                    ((TRNG_Type *)TRNG0_BASE)
  /** Peripheral TRNG0 base pointer */
  #define TRNG0_NS                                 ((TRNG_Type *)TRNG0_BASE_NS)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG0_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG0 }
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS_NS                       { TRNG0_BASE_NS }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS_NS                        { TRNG0_NS }
#else
  /** Peripheral TRNG0 base address */
  #define TRNG0_BASE                               (0x400EC000u)
  /** Peripheral TRNG0 base pointer */
  #define TRNG0                                    ((TRNG_Type *)TRNG0_BASE)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG0_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG0 }
#endif

/* TSI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TSI0 base address */
  #define TSI0_BASE                                (0x500C3000u)
  /** Peripheral TSI0 base address */
  #define TSI0_BASE_NS                             (0x400C3000u)
  /** Peripheral TSI0 base pointer */
  #define TSI0                                     ((TSI_Type *)TSI0_BASE)
  /** Peripheral TSI0 base pointer */
  #define TSI0_NS                                  ((TSI_Type *)TSI0_BASE_NS)
  /** Array initializer of TSI peripheral base addresses */
  #define TSI_BASE_ADDRS                           { TSI0_BASE }
  /** Array initializer of TSI peripheral base pointers */
  #define TSI_BASE_PTRS                            { TSI0 }
  /** Array initializer of TSI peripheral base addresses */
  #define TSI_BASE_ADDRS_NS                        { TSI0_BASE_NS }
  /** Array initializer of TSI peripheral base pointers */
  #define TSI_BASE_PTRS_NS                         { TSI0_NS }
#else
  /** Peripheral TSI0 base address */
  #define TSI0_BASE                                (0x400C3000u)
  /** Peripheral TSI0 base pointer */
  #define TSI0                                     ((TSI_Type *)TSI0_BASE)
  /** Array initializer of TSI peripheral base addresses */
  #define TSI_BASE_ADDRS                           { TSI0_BASE }
  /** Array initializer of TSI peripheral base pointers */
  #define TSI_BASE_PTRS                            { TSI0 }
#endif

/* USBHS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHS1 base address */
  #define USBHS1_BASE                              (0x5002E000u)
  /** Peripheral USBHS1 base address */
  #define USBHS1_BASE_NS                           (0x4002E000u)
  /** Peripheral USBHS1 base pointer */
  #define USBHS1                                   ((USBHS_Type *)USBHS1_BASE)
  /** Peripheral USBHS1 base pointer */
  #define USBHS1_NS                                ((USBHS_Type *)USBHS1_BASE_NS)
  /** Array initializer of USBHS peripheral base addresses */
  #define USBHS_BASE_ADDRS                         { USBHS1_BASE }
  /** Array initializer of USBHS peripheral base pointers */
  #define USBHS_BASE_PTRS                          { USBHS1 }
  /** Array initializer of USBHS peripheral base addresses */
  #define USBHS_BASE_ADDRS_NS                      { USBHS1_BASE_NS }
  /** Array initializer of USBHS peripheral base pointers */
  #define USBHS_BASE_PTRS_NS                       { USBHS1_NS }
#else
  /** Peripheral USBHS1 base address */
  #define USBHS1_BASE                              (0x4002E000u)
  /** Peripheral USBHS1 base pointer */
  #define USBHS1                                   ((USBHS_Type *)USBHS1_BASE)
  /** Array initializer of USBHS peripheral base addresses */
  #define USBHS_BASE_ADDRS                         { USBHS1_BASE }
  /** Array initializer of USBHS peripheral base pointers */
  #define USBHS_BASE_PTRS                          { USBHS1 }
#endif
/** Interrupt vectors for the USBHS peripheral type */
#define USBHS_IRQS                               { USB1_HS_IRQn }

/* USBHSDCD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHS1_PHY_DCD base address */
  #define USBHS1_PHY_DCD_BASE                      (0x5002F800u)
  /** Peripheral USBHS1_PHY_DCD base address */
  #define USBHS1_PHY_DCD_BASE_NS                   (0x4002F800u)
  /** Peripheral USBHS1_PHY_DCD base pointer */
  #define USBHS1_PHY_DCD                           ((USBHSDCD_Type *)USBHS1_PHY_DCD_BASE)
  /** Peripheral USBHS1_PHY_DCD base pointer */
  #define USBHS1_PHY_DCD_NS                        ((USBHSDCD_Type *)USBHS1_PHY_DCD_BASE_NS)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBHS1_PHY_DCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBHS1_PHY_DCD }
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS_NS                   { USBHS1_PHY_DCD_BASE_NS }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS_NS                    { USBHS1_PHY_DCD_NS }
#else
  /** Peripheral USBHS1_PHY_DCD base address */
  #define USBHS1_PHY_DCD_BASE                      (0x4002F800u)
  /** Peripheral USBHS1_PHY_DCD base pointer */
  #define USBHS1_PHY_DCD                           ((USBHSDCD_Type *)USBHS1_PHY_DCD_BASE)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBHS1_PHY_DCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBHS1_PHY_DCD }
#endif

/* USBNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHS1NC base address */
  #define USBHS1NC_BASE                            (0x5002E200u)
  /** Peripheral USBHS1NC base address */
  #define USBHS1NC_BASE_NS                         (0x4002E200u)
  /** Peripheral USBHS1NC base pointer */
  #define USBHS1NC                                 ((USBNC_Type *)USBHS1NC_BASE)
  /** Peripheral USBHS1NC base pointer */
  #define USBHS1NC_NS                              ((USBNC_Type *)USBHS1NC_BASE_NS)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBHS1NC_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBHS1NC }
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS_NS                      { USBHS1NC_BASE_NS }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS_NS                       { USBHS1NC_NS }
#else
  /** Peripheral USBHS1NC base address */
  #define USBHS1NC_BASE                            (0x4002E200u)
  /** Peripheral USBHS1NC base pointer */
  #define USBHS1NC                                 ((USBNC_Type *)USBHS1NC_BASE)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBHS1NC_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBHS1NC }
#endif

/* USBPHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHS1_PHY base address */
  #define USBHS1_PHY_BASE                          (0x5002F000u)
  /** Peripheral USBHS1_PHY base address */
  #define USBHS1_PHY_BASE_NS                       (0x4002F000u)
  /** Peripheral USBHS1_PHY base pointer */
  #define USBHS1_PHY                               ((USBPHY_Type *)USBHS1_PHY_BASE)
  /** Peripheral USBHS1_PHY base pointer */
  #define USBHS1_PHY_NS                            ((USBPHY_Type *)USBHS1_PHY_BASE_NS)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { USBHS1_PHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { USBHS1_PHY }
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS_NS                     { USBHS1_PHY_BASE_NS }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS_NS                      { USBHS1_PHY_NS }
#else
  /** Peripheral USBHS1_PHY base address */
  #define USBHS1_PHY_BASE                          (0x4002F000u)
  /** Peripheral USBHS1_PHY base pointer */
  #define USBHS1_PHY                               ((USBPHY_Type *)USBHS1_PHY_BASE)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { USBHS1_PHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { USBHS1_PHY }
#endif
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { USB1_HS_PHY_IRQn }
/* Backward compatibility */
#define USBPHY_CTRL_ENDEVPLUGINDET_MASK     USBPHY_CTRL_ENDEVPLUGINDETECT_MASK
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT    USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT
#define USBPHY_CTRL_ENDEVPLUGINDET(x)       USBPHY_CTRL_ENDEVPLUGINDETECT(x)
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)



/* UTICK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE                              (0x5000B000u)
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE_NS                           (0x4000B000u)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0_NS                                ((UTICK_Type *)UTICK0_BASE_NS)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { UTICK0_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { UTICK0 }
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS_NS                      { UTICK0_BASE_NS }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS_NS                       { UTICK0_NS }
#else
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE                              (0x4000B000u)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { UTICK0_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { UTICK0 }
#endif
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { UTICK0_IRQn }

/* VBAT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VBAT0 base address */
  #define VBAT0_BASE                               (0x50093000u)
  /** Peripheral VBAT0 base address */
  #define VBAT0_BASE_NS                            (0x40093000u)
  /** Peripheral VBAT0 base pointer */
  #define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
  /** Peripheral VBAT0 base pointer */
  #define VBAT0_NS                                 ((VBAT_Type *)VBAT0_BASE_NS)
  /** Array initializer of VBAT peripheral base addresses */
  #define VBAT_BASE_ADDRS                          { VBAT0_BASE }
  /** Array initializer of VBAT peripheral base pointers */
  #define VBAT_BASE_PTRS                           { VBAT0 }
  /** Array initializer of VBAT peripheral base addresses */
  #define VBAT_BASE_ADDRS_NS                       { VBAT0_BASE_NS }
  /** Array initializer of VBAT peripheral base pointers */
  #define VBAT_BASE_PTRS_NS                        { VBAT0_NS }
#else
  /** Peripheral VBAT0 base address */
  #define VBAT0_BASE                               (0x40093000u)
  /** Peripheral VBAT0 base pointer */
  #define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
  /** Array initializer of VBAT peripheral base addresses */
  #define VBAT_BASE_ADDRS                          { VBAT0_BASE }
  /** Array initializer of VBAT peripheral base pointers */
  #define VBAT_BASE_PTRS                           { VBAT0 }
#endif

/* VREF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VREF0 base address */
  #define VREF0_BASE                               (0x500BB000u)
  /** Peripheral VREF0 base address */
  #define VREF0_BASE_NS                            (0x400BB000u)
  /** Peripheral VREF0 base pointer */
  #define VREF0                                    ((VREF_Type *)VREF0_BASE)
  /** Peripheral VREF0 base pointer */
  #define VREF0_NS                                 ((VREF_Type *)VREF0_BASE_NS)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF0_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF0 }
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS_NS                       { VREF0_BASE_NS }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS_NS                        { VREF0_NS }
#else
  /** Peripheral VREF0 base address */
  #define VREF0_BASE                               (0x400BB000u)
  /** Peripheral VREF0 base pointer */
  #define VREF0                                    ((VREF_Type *)VREF0_BASE)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF0_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF0 }
#endif

/* WAKETIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKETIMER0 base address */
  #define WAKETIMER0_BASE                          (0x500AE000u)
  /** Peripheral WAKETIMER0 base address */
  #define WAKETIMER0_BASE_NS                       (0x400AE000u)
  /** Peripheral WAKETIMER0 base pointer */
  #define WAKETIMER0                               ((WAKETIMER_Type *)WAKETIMER0_BASE)
  /** Peripheral WAKETIMER0 base pointer */
  #define WAKETIMER0_NS                            ((WAKETIMER_Type *)WAKETIMER0_BASE_NS)
  /** Array initializer of WAKETIMER peripheral base addresses */
  #define WAKETIMER_BASE_ADDRS                     { WAKETIMER0_BASE }
  /** Array initializer of WAKETIMER peripheral base pointers */
  #define WAKETIMER_BASE_PTRS                      { WAKETIMER0 }
  /** Array initializer of WAKETIMER peripheral base addresses */
  #define WAKETIMER_BASE_ADDRS_NS                  { WAKETIMER0_BASE_NS }
  /** Array initializer of WAKETIMER peripheral base pointers */
  #define WAKETIMER_BASE_PTRS_NS                   { WAKETIMER0_NS }
#else
  /** Peripheral WAKETIMER0 base address */
  #define WAKETIMER0_BASE                          (0x400AE000u)
  /** Peripheral WAKETIMER0 base pointer */
  #define WAKETIMER0                               ((WAKETIMER_Type *)WAKETIMER0_BASE)
  /** Array initializer of WAKETIMER peripheral base addresses */
  #define WAKETIMER_BASE_ADDRS                     { WAKETIMER0_BASE }
  /** Array initializer of WAKETIMER peripheral base pointers */
  #define WAKETIMER_BASE_PTRS                      { WAKETIMER0 }
#endif
/** Interrupt vectors for the WAKETIMER peripheral type */
#define WAKETIMER_IRQS                           { WAKETIMER0_IRQn }

/* WUU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WUU0 base address */
  #define WUU0_BASE                                (0x50092000u)
  /** Peripheral WUU0 base address */
  #define WUU0_BASE_NS                             (0x40092000u)
  /** Peripheral WUU0 base pointer */
  #define WUU0                                     ((WUU_Type *)WUU0_BASE)
  /** Peripheral WUU0 base pointer */
  #define WUU0_NS                                  ((WUU_Type *)WUU0_BASE_NS)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU0_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU0 }
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS_NS                        { WUU0_BASE_NS }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS_NS                         { WUU0_NS }
#else
  /** Peripheral WUU0 base address */
  #define WUU0_BASE                                (0x40092000u)
  /** Peripheral WUU0 base pointer */
  #define WUU0                                     ((WUU_Type *)WUU0_BASE)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU0_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU0 }
#endif
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn }

/* WWDT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE                               (0x5000C000u)
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE_NS                            (0x4000C000u)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0_NS                                 ((WWDT_Type *)WWDT0_BASE_NS)
  /** Peripheral WWDT1 base address */
  #define WWDT1_BASE                               (0x5000D000u)
  /** Peripheral WWDT1 base address */
  #define WWDT1_BASE_NS                            (0x4000D000u)
  /** Peripheral WWDT1 base pointer */
  #define WWDT1                                    ((WWDT_Type *)WWDT1_BASE)
  /** Peripheral WWDT1 base pointer */
  #define WWDT1_NS                                 ((WWDT_Type *)WWDT1_BASE_NS)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { WWDT0_BASE, WWDT1_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { WWDT0, WWDT1 }
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS_NS                       { WWDT0_BASE_NS, WWDT1_BASE_NS }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS_NS                        { WWDT0_NS, WWDT1_NS }
#else
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE                               (0x4000C000u)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
  /** Peripheral WWDT1 base address */
  #define WWDT1_BASE                               (0x4000D000u)
  /** Peripheral WWDT1 base pointer */
  #define WWDT1                                    ((WWDT_Type *)WWDT1_BASE)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { WWDT0_BASE, WWDT1_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { WWDT0, WWDT1 }
#endif
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { WWDT0_IRQn, WWDT1_IRQn }

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
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

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

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MCXA577_COMMON_H_ */

