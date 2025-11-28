/*
** ###################################################################
**     Processors:          MIMX9352AVTXM_cm33
**                          MIMX9352CVVXM_cm33
**                          MIMX9352DVVXM_cm33
**                          MIMX9352XVVXM_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX93RM, Internal, November. 2021
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX9352_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX9352_cm33_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMX9352_cm33
 *
 * CMSIS Peripheral Access Layer for MIMX9352_cm33
 */

#if !defined(MIMX9352_CM33_COMMON_H_)
#define MIMX9352_CM33_COMMON_H_                  /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 284                /**< Number of interrupts in the Vector table */

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
  Reserved16_IRQn              = 0,                /**< Reserved interrupt */
  DAP_IRQn                     = 1,                /**< DAP interrupt */
  Reserved18_IRQn              = 2,                /**< Reserved interrupt */
  CTI_CM33_IRQn                = 3,                /**< CTI trigger outputs from CM33 platform */
  CTI_CA55_IRQn                = 4,                /**< CTI trigger outputs from CA55 platform */
  PMU_IRQn                     = 5,                /**< Performance Unit Interrupts from CA55 platform */
  CACHE_ECC_ERR_IRQn           = 6,                /**< ECC error from CA55 platform cache */
  CACHE_ECC_PARITY_ERR_IRQn    = 7,                /**< 1-bit or 2-bit ECC or Parity error from CA55 platform cache */
  CAN1_IRQn                    = 8,                /**< CAN1 interrupt */
  CAN1_ERROR_IRQn              = 9,                /**< CAN1 error interrupt */
  GPIO1_0_IRQn                 = 10,               /**< General Purpose Input/Output 1 interrupt 0 */
  GPIO1_1_IRQn                 = 11,               /**< General Purpose Input/Output 1 interrupt 1 */
  I3C1_IRQn                    = 12,               /**< Improved Inter-Integrated Circuit 1 interrupt */
  LPI2C1_IRQn                  = 13,               /**< Low Power Inter-Integrated Circuit module 1 */
  LPI2C2_IRQn                  = 14,               /**< Low Power Inter-Integrated Circuit module 2 */
  LPIT1_IRQn                   = 15,               /**< Low Power Periodic Interrupt Timer 1 */
  LPSPI1_IRQn                  = 16,               /**< Low Power Serial Peripheral Interface 1 */
  LPSPI2_IRQn                  = 17,               /**< Low Power Serial Peripheral Interface 2 */
  LPTMR1_IRQn                  = 18,               /**< Low Power Timer 1 */
  LPUART1_IRQn                 = 19,               /**< Low Power UART 1 */
  LPUART2_IRQn                 = 20,               /**< Low Power UART 2 */
  MU1_A_IRQn                   = 21,               /**< Messaging Unit 1 - Side A (to communicate with M7 core) */
  MU1_B_IRQn                   = 22,               /**< Messaging Unit 1 - Side B (to communicate with M33 core) */
  MU2_A_IRQn                   = 23,               /**< Messaging Unit 2 - Side A (to communicate with M7 core) */
  MU2_B_IRQn                   = 24,               /**< Messaging Unit 2 - Side B (to communicate with A55 core) */
  Reserved41_IRQn              = 25,               /**< Reserved interrupt */
  Reserved42_IRQn              = 26,               /**< Reserved interrupt */
  Reserved43_IRQn              = 27,               /**< Reserved interrupt */
  EDGELOCK_TRUST_MUA_RX_IRQn   = 28,               /**< Edgelock Trust MUA RX full interrupt */
  EDGELOCK_TRUST_MUA_TX_IRQn   = 29,               /**< Edgelock Trust MUA TX empty interrupt */
  EDGELOCK_APP_MUA_RX_IRQn     = 30,               /**< Edgelock Apps Core MUA RX full interrupt */
  EDGELOCK_APP_MUA_TX_IRQn     = 31,               /**< Edgelock Apps Core MUA TX empty interrupt */
  EDGELOCK_RT_MUA_RX_IRQn      = 32,               /**< Edgelock Realtime Core MUA RX full interrupt */
  EDGELOCK_RT_MUA_TX_IRQn      = 33,               /**< Edgelock Realtime Core MUA TX empty interrupt */
  EDGELOCK_SECURE_IRQn         = 34,               /**< Edgelock secure interrupt */
  EDGELOCK_NONSECURE_IRQn      = 35,               /**< Edgelock non-secure interrupt */
  TPM1_IRQn                    = 36,               /**< Timer PWM module 1 */
  TPM2_IRQn                    = 37,               /**< Timer PWM module 2 */
  WDOG1_IRQn                   = 38,               /**< Watchdog 1 Interrupt */
  WDOG2_IRQn                   = 39,               /**< Watchdog 2 Interrupt */
  TRDC_IRQn                    = 40,               /**< AONMIX TRDC transfer error interrupt */
  Reserved57_IRQn              = 41,               /**< Reserved interrupt */
  Reserved58_IRQn              = 42,               /**< Reserved interrupt */
  Reserved59_IRQn              = 43,               /**< Reserved interrupt */
  Reserved60_IRQn              = 44,               /**< Reserved interrupt */
  SAI1_IRQn                    = 45,               /**< Serial Audio Interface 1 */
  PS_PARITY_ERR_IRQn           = 46,               /**< M33 PS Tag/Data Parity Error */
  TCM_ECC_IRQn                 = 47,               /**< M33 TCM ECC interrupt */
  TCM_ERR_IRQn                 = 48,               /**< M33 TCM Error interrupt */
  Reserved65_IRQn              = 49,               /**< Reserved interrupt */
  Reserved66_IRQn              = 50,               /**< Reserved interrupt */
  CAN2_IRQn                    = 51,               /**< CAN2 interrupt */
  CAN2_ERROR_IRQn              = 52,               /**< CAN2 error interrupt */
  FLEXIO1_IRQn                 = 53,               /**< Flexible IO 1 interrupt */
  FLEXIO2_IRQn                 = 54,               /**< Flexible IO 2 interrupt */
  FlexSPI1_IRQn                = 55,               /**< FlexSPI controller interface interrupt 1 */
  Reserved72_IRQn              = 56,               /**< Reserved interrupt */
  GPIO2_0_IRQn                 = 57,               /**< General Purpose Input/Output 2 interrupt 0 */
  GPIO2_1_IRQn                 = 58,               /**< General Purpose Input/Output 2 interrupt 1 */
  GPIO3_0_IRQn                 = 59,               /**< General Purpose Input/Output 3 interrupt 0 */
  GPIO3_1_IRQn                 = 60,               /**< General Purpose Input/Output 3 interrupt 1 */
  I3C2_IRQn                    = 61,               /**< Improved Inter-Integrated Circuit 2 interrupt */
  LPI2C3_IRQn                  = 62,               /**< Low Power Inter-Integrated Circuit module 3 */
  LPI2C4_IRQn                  = 63,               /**< Low Power Inter-Integrated Circuit module 4 */
  LPIT2_IRQn                   = 64,               /**< Low Power Periodic Interrupt Timer 2 */
  LPSPI3_IRQn                  = 65,               /**< Low Power Serial Peripheral Interface 3 */
  LPSPI4_IRQn                  = 66,               /**< Low Power Serial Peripheral Interface 4 */
  LPTMR2_IRQn                  = 67,               /**< Low Power Timer 2 */
  LPUART3_IRQn                 = 68,               /**< Low Power UART 3 */
  LPUART4_IRQn                 = 69,               /**< Low Power UART 4 */
  LPUART5_IRQn                 = 70,               /**< Low Power UART 5 */
  LPUART6_IRQn                 = 71,               /**< Low Power UART 6 */
  MTR_MASTER_ERR_IRQn          = 72,               /**< MTR Master error interrupt */
  BBNSM_NONSECURE_IRQn         = 73,               /**< BBNSM Non-Secure interrupt */
  SYS_CTR_COMPARE_IRQn         = 74,               /**< System Counter compare interrupt */
  TPM3_IRQn                    = 75,               /**< Timer PWM module 3 */
  TPM4_IRQn                    = 76,               /**< Timer PWM module 4 */
  TPM5_IRQn                    = 77,               /**< Timer PWM module 5 */
  TPM6_IRQn                    = 78,               /**< Timer PWM module 6 */
  WDOG3_IRQn                   = 79,               /**< Watchdog 3 Interrupt */
  WDOG4_IRQn                   = 80,               /**< Watchdog 4 Interrupt */
  WDOG5_IRQn                   = 81,               /**< Watchdog 5 Interrupt */
  TRDC_WAKEUPMIX_ERR_IRQn      = 82,               /**< WAKEUPMIX TRDC transfer error interrupt */
  TEMPMON_IRQn                 = 83,               /**< TempSensor interrupt */
  Reserved100_IRQn             = 84,               /**< Reserved interrupt */
  Reserved101_IRQn             = 85,               /**< Reserved interrupt */
  uSDHC1_IRQn                  = 86,               /**< ultra Secure Digital Host Controller interrupt 1 */
  uSDHC2_IRQn                  = 87,               /**< ultra Secure Digital Host Controller interrupt 2 */
  TRDC_MEGAMIX_ERR_IRQn        = 88,               /**< MEGAMIX TRDC transfer error interrupt */
  TRDC_NIC_WRAPPER_ERR_IRQn    = 89,               /**< NIC_WRAPPER TRDC transfer error interrupt */
  DRAM_PERFMON_IRQn            = 90,               /**< DRAM controller Performance Monitor Interrupt */
  DRAM_CRITICAL_IRQn           = 91,               /**< DRAM controller Critical Interrupt */
  DRAM_PHY_CRITICAL_IRQn       = 92,               /**< DRAM Phy Critical Interrupt */
  Reserved109_IRQn             = 93,               /**< Reserved interrupt */
  DMA3_ERROR_IRQn              = 94,               /**< eDMA1 error interrupt */
  DMA3_0_IRQn                  = 95,               /**< eDMA1 channel 0 interrupt */
  DMA3_1_IRQn                  = 96,               /**< eDMA1 channel 1 interrupt */
  DMA3_2_IRQn                  = 97,               /**< eDMA1 channel 2 interrupt */
  DMA3_3_IRQn                  = 98,               /**< eDMA1 channel 3 interrupt */
  DMA3_4_IRQn                  = 99,               /**< eDMA1 channel 4 interrupt */
  DMA3_5_IRQn                  = 100,              /**< eDMA1 channel 5 interrupt */
  DMA3_6_IRQn                  = 101,              /**< eDMA1 channel 6 interrupt */
  DMA3_7_IRQn                  = 102,              /**< eDMA1 channel 7 interrupt */
  DMA3_8_IRQn                  = 103,              /**< eDMA1 channel 8 interrupt */
  DMA3_9_IRQn                  = 104,              /**< eDMA1 channel 9 interrupt */
  DMA3_10_IRQn                 = 105,              /**< eDMA1 channel 10 interrupt */
  DMA3_11_IRQn                 = 106,              /**< eDMA1 channel 11 interrupt */
  DMA3_12_IRQn                 = 107,              /**< eDMA1 channel 12 interrupt */
  DMA3_13_IRQn                 = 108,              /**< eDMA1 channel 13 interrupt */
  DMA3_14_IRQn                 = 109,              /**< eDMA1 channel 14 interrupt */
  DMA3_15_IRQn                 = 110,              /**< eDMA1 channel 15 interrupt */
  DMA3_16_IRQn                 = 111,              /**< eDMA1 channel 16 interrupt */
  DMA3_17_IRQn                 = 112,              /**< eDMA1 channel 17 interrupt */
  DMA3_18_IRQn                 = 113,              /**< eDMA1 channel 18 interrupt */
  DMA3_19_IRQn                 = 114,              /**< eDMA1 channel 19 interrupt */
  DMA3_20_IRQn                 = 115,              /**< eDMA1 channel 20 interrupt */
  DMA3_21_IRQn                 = 116,              /**< eDMA1 channel 21 interrupt */
  DMA3_22_IRQn                 = 117,              /**< eDMA1 channel 22 interrupt */
  DMA3_23_IRQn                 = 118,              /**< eDMA1 channel 23 interrupt */
  DMA3_24_IRQn                 = 119,              /**< eDMA1 channel 24 interrupt */
  DMA3_25_IRQn                 = 120,              /**< eDMA1 channel 25 interrupt */
  DMA3_26_IRQn                 = 121,              /**< eDMA1 channel 26 interrupt */
  DMA3_27_IRQn                 = 122,              /**< eDMA1 channel 27 interrupt */
  DMA3_28_IRQn                 = 123,              /**< eDMA1 channel 28 interrupt */
  DMA3_29_IRQn                 = 124,              /**< eDMA1 channel 29 interrupt */
  DMA3_30_IRQn                 = 125,              /**< eDMA1 channel 30 interrupt */
  Reserved142_IRQn             = 126,              /**< Reserved interrupt */
  DMA4_ERROR_IRQn              = 127,              /**< eDMA2 error interrupt */
  DMA4_0_1_IRQn                = 128,              /**< eDMA2 channel 0/1 interrupt */
  DMA4_2_3_IRQn                = 129,              /**< eDMA2 channel 2/3 interrupt */
  DMA4_4_5_IRQn                = 130,              /**< eDMA2 channel 4/5 interrupt */
  DMA4_6_7_IRQn                = 131,              /**< eDMA2 channel 6/7 interrupt */
  DMA4_8_9_IRQn                = 132,              /**< eDMA2 channel 8/9 interrupt */
  DMA4_10_11_IRQn              = 133,              /**< eDMA2 channel 10/11 interrupt */
  DMA4_12_13_IRQn              = 134,              /**< eDMA2 channel 12/13 interrupt */
  DMA4_14_15_IRQn              = 135,              /**< eDMA2 channel 14/15 interrupt */
  DMA4_16_17_IRQn              = 136,              /**< eDMA2 channel 16/17 interrupt */
  DMA4_18_19_IRQn              = 137,              /**< eDMA2 channel 18/19 interrupt */
  DMA4_20_21_IRQn              = 138,              /**< eDMA2 channel 20/21 interrupt */
  DMA4_22_23_IRQn              = 139,              /**< eDMA2 channel 22/23 interrupt */
  DMA4_24_25_IRQn              = 140,              /**< eDMA2 channel 24/25 interrupt */
  DMA4_26_27_IRQn              = 141,              /**< eDMA2 channel 26/27 interrupt */
  DMA4_28_29_IRQn              = 142,              /**< eDMA2 channel 28/29 interrupt */
  DMA4_30_31_IRQn              = 143,              /**< eDMA2 channel 30/31 interrupt */
  DMA4_32_33_IRQn              = 144,              /**< eDMA2 channel 32/33 interrupt */
  DMA4_34_35_IRQn              = 145,              /**< eDMA2 channel 34/35 interrupt */
  DMA4_36_37_IRQn              = 146,              /**< eDMA2 channel 36/37 interrupt */
  DMA4_38_39_IRQn              = 147,              /**< eDMA2 channel 38/39 interrupt */
  DMA4_40_41_IRQn              = 148,              /**< eDMA2 channel 40/41 interrupt */
  DMA4_42_43_IRQn              = 149,              /**< eDMA2 channel 42/43 interrupt */
  DMA4_44_45_IRQn              = 150,              /**< eDMA2 channel 44/45 interrupt */
  DMA4_46_47_IRQn              = 151,              /**< eDMA2 channel 46/47 interrupt */
  DMA4_48_49_IRQn              = 152,              /**< eDMA2 channel 48/49 interrupt */
  DMA4_50_51_IRQn              = 153,              /**< eDMA2 channel 50/51 interrupt */
  DMA4_52_53_IRQn              = 154,              /**< eDMA2 channel 52/53 interrupt */
  DMA4_54_55_IRQn              = 155,              /**< eDMA2 channel 54/55 interrupt */
  DMA4_56_57_IRQn              = 156,              /**< eDMA2 channel 56/57 interrupt */
  DMA4_58_59_IRQn              = 157,              /**< eDMA2 channel 58/59 interrupt */
  DMA4_60_61_IRQn              = 158,              /**< eDMA2 channel 60/61 interrupt */
  DMA4_62_63_IRQn              = 159,              /**< eDMA2 channel 62/63 interrupt */
  DEBUG_WAKEUP_IRQn            = 160,              /**< Debug Wakeup Interrupt */
  EDGELOCK_GROUP1_RST_SRC_IRQn = 161,              /**< Edgelock Group 1 reset source */
  EDGELOCK_GROUP2_RST_SRC_0_IRQn = 162,            /**< Edgelock Group 2 reset source */
  EDGELOCK_GROUP2_RST_SRC_1_IRQn = 163,            /**< Edgelock Group 2 reset source */
  DBG_TRACE_RST_SRC_IRQn       = 164,              /**< JTAGSW DAP MDM-AP SRC reset source */
  JTAGC_RST_SRC_IRQn           = 165,              /**< JTAGC SRC reset source */
  CM33_SYSREQRST_RST_SRC_IRQn  = 166,              /**< CM33 SYSREQRST SRC reset source */
  CM33_LOCKUP_RST_SRC_IRQn     = 167,              /**< CM33 LOCKUP SRC reset source */
  Reserved184_IRQn             = 168,              /**< Reserved interrupt */
  Reserved185_IRQn             = 169,              /**< Reserved interrupt */
  SAI2_IRQn                    = 170,              /**< Serial Audio Interface 2 */
  SAI3_IRQn                    = 171,              /**< Serial Audio Interface 3 */
  ISI_IRQn                     = 172,              /**< ISI interrupt */
  PXP_0_IRQn                   = 173,              /**< PXP interrupt 0 */
  PXP_1_IRQn                   = 174,              /**< PXP interrupt 1 */
  CSI_IRQn                     = 175,              /**< CSI interrupt */
  LCDIFv3_IRQn                 = 176,              /**< LCDIF Sync Interrupt */
  DSI_IRQn                     = 177,              /**< MIPI DSI Interrupt Request */
  ML_IRQn                      = 178,              /**< Machine learning processor interrupt */
  ENET_MAC0_Rx_Tx_Done1_IRQn   = 179,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET_MAC0_Rx_Tx_Done2_IRQn   = 180,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET_IRQn                    = 181,              /**< MAC 0 IRQ */
  ENET_1588_IRQn               = 182,              /**< MAC 0 1588 Timer Interrupt - synchronous */
  ENET_QOS_PMT_IRQn            = 183,              /**< ENET QOS PMT interrupt */
  ENET_QOS_IRQn                = 184,              /**< ENET QOS interrupt */
  Reserved201_IRQn             = 185,              /**< Reserved interrupt */
  Reserved202_IRQn             = 186,              /**< Reserved interrupt */
  USB1_WAKEUP_IRQn             = 187,              /**< USB-1 Wake-up Interrupt */
  USB2_WAKEUP_IRQn             = 188,              /**< USB-2 Wake-up Interrupt */
  GPIO4_0_IRQn                 = 189,              /**< General Purpose Input/Output 4 interrupt 0 */
  GPIO4_1_IRQn                 = 190,              /**< General Purpose Input/Output 4 interrupt 1 */
  LPSPI5_IRQn                  = 191,              /**< Low Power Serial Peripheral Interface 5 */
  LPSPI6_IRQn                  = 192,              /**< Low Power Serial Peripheral Interface 6 */
  LPSPI7_IRQn                  = 193,              /**< Low Power Serial Peripheral Interface 7 */
  LPSPI8_IRQn                  = 194,              /**< Low Power Serial Peripheral Interface 8 */
  LPI2C5_IRQn                  = 195,              /**< Low Power Inter-Integrated Circuit module 5 */
  LPI2C6_IRQn                  = 196,              /**< Low Power Inter-Integrated Circuit module 6 */
  LPI2C7_IRQn                  = 197,              /**< Low Power Inter-Integrated Circuit module 7 */
  LPI2C8_IRQn                  = 198,              /**< Low Power Inter-Integrated Circuit module 8 */
  PDM_HWVAD_ERROR_IRQn         = 199,              /**< PDM interrupt */
  PDM_HWVAD_EVENT_IRQn         = 200,              /**< PDM interrupt */
  PDM_ERROR_IRQn               = 201,              /**< PDM interrupt */
  PDM_EVENT_IRQn               = 202,              /**< PDM interrupt */
  AUDIO_XCVR_0_IRQn            = 203,              /**< AUDIO XCVR interrupt */
  AUDIO_XCVR_1_IRQn            = 204,              /**< AUDIO XCVR interrupt */
  uSDHC3_IRQn                  = 205,              /**< ultra Secure Digital Host Controller interrupt 3 */
  OCRAM_MECC_0_IRQn            = 206,              /**< OCRAM MECC interrupt */
  OCRAM_MECC_1_IRQn            = 207,              /**< OCRAM MECC interrupt */
  TRDC_HSIOMIX_ERR_IRQn        = 208,              /**< HSIOMIX TRDC transfer error interrupt */
  TRDC_MEDIAMIX_ERR_IRQn       = 209,              /**< MEDIAMIX TRDC transfer error interrupt */
  LPUART7_IRQn                 = 210,              /**< Low Power UART 7 */
  LPUART8_IRQn                 = 211,              /**< Low Power UART 8 */
  CM33_MCM_IRQn                = 212,              /**< CM33 MCM interrupt */
  SFA_IRQn                     = 213,              /**< SFA interrupt */
  GIC600_0_IRQn                = 214,              /**< GIC600 INTERRUPT */
  GIC600_1_IRQn                = 215,              /**< GIC600 INTERRUPT */
  GIC600_2_IRQn                = 216,              /**< GIC600 INTERRUPT */
  ADC_ER_IRQn                  = 217,              /**< ADC interrupt */
  ADC_WD_IRQn                  = 218,              /**< ADC interrupt */
  ADC_EOC_IRQn                 = 219,              /**< ADC interrupt */
  Reserved236_IRQn             = 220,              /**< Reserved interrupt */
  I3C1_WAKEUP_IRQn             = 221,              /**< I3C1 wakeup irq after double sync */
  I3C2_WAKEUP_IRQn             = 222,              /**< I3C2 wakeup irq after double sync */
  Reserved239_IRQn             = 223,              /**< Reserved interrupt */
  Reserved240_IRQn             = 224,              /**< Reserved interrupt */
  Reserved241_IRQn             = 225,              /**< Reserved interrupt */
  Reserved242_IRQn             = 226,              /**< Reserved interrupt */
  Reserved243_IRQn             = 227,              /**< Reserved interrupt */
  Reserved244_IRQn             = 228,              /**< Reserved interrupt */
  Reserved245_IRQn             = 229,              /**< Reserved interrupt */
  Reserved246_IRQn             = 230,              /**< Reserved interrupt */
  Reserved247_IRQn             = 231,              /**< Reserved interrupt */
  Reserved248_IRQn             = 232,              /**< Reserved interrupt */
  Reserved249_IRQn             = 233,              /**< Reserved interrupt */
  Reserved250_IRQn             = 234,              /**< Reserved interrupt */
  Reserved251_IRQn             = 235,              /**< Reserved interrupt */
  Reserved252_IRQn             = 236,              /**< Reserved interrupt */
  Reserved253_IRQn             = 237,              /**< Reserved interrupt */
  Reserved254_IRQn             = 238,              /**< Reserved interrupt */
  Reserved255_IRQn             = 239,              /**< Reserved interrupt */
  Reserved256_IRQn             = 240,              /**< Reserved interrupt */
  Reserved257_IRQn             = 241,              /**< Reserved interrupt */
  Reserved258_IRQn             = 242,              /**< Reserved interrupt */
  Reserved259_IRQn             = 243,              /**< Reserved interrupt */
  Reserved260_IRQn             = 244,              /**< Reserved interrupt */
  Reserved261_IRQn             = 245,              /**< Reserved interrupt */
  Reserved262_IRQn             = 246,              /**< Reserved interrupt */
  Reserved263_IRQn             = 247,              /**< Reserved interrupt */
  Reserved264_IRQn             = 248,              /**< Reserved interrupt */
  Reserved265_IRQn             = 249,              /**< Reserved interrupt */
  Reserved266_IRQn             = 250,              /**< Reserved interrupt */
  Reserved267_IRQn             = 251,              /**< Reserved interrupt */
  Reserved268_IRQn             = 252,              /**< Reserved interrupt */
  Reserved269_IRQn             = 253,              /**< Reserved interrupt */
  Reserved270_IRQn             = 254,              /**< Reserved interrupt */
  Reserved271_IRQn             = 255,              /**< Reserved interrupt */
  Reserved272_IRQn             = 256,              /**< Reserved interrupt */
  Reserved273_IRQn             = 257,              /**< Reserved interrupt */
  Reserved274_IRQn             = 258,              /**< Reserved interrupt */
  Reserved275_IRQn             = 259,              /**< Reserved interrupt */
  Reserved276_IRQn             = 260,              /**< Reserved interrupt */
  Reserved277_IRQn             = 261,              /**< Reserved interrupt */
  Reserved278_IRQn             = 262,              /**< Reserved interrupt */
  Reserved279_IRQn             = 263,              /**< Reserved interrupt */
  Reserved280_IRQn             = 264,              /**< Reserved interrupt */
  Reserved281_IRQn             = 265,              /**< Reserved interrupt */
  Reserved282_IRQn             = 266,              /**< Reserved interrupt */
  Reserved283_IRQn             = 267               /**< Reserved interrupt */
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
#include "system_MIMX9352_cm33.h"      /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMX9352_cm33_SERIES
#define MIMX9352_cm33_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX9352_cm33_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x54530000u)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE_NS                             (0x44530000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Peripheral ADC1 base pointer */
  #define ADC1_NS                                  ((ADC_Type *)ADC1_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC1 }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { ADC1_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { ADC1_NS }
#else
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x44530000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC1 }
#endif

/* ANA_OSC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANA_OSC base address */
  #define ANA_OSC_BASE                             (0x54480000u)
  /** Peripheral ANA_OSC base address */
  #define ANA_OSC_BASE_NS                          (0x44480000u)
  /** Peripheral ANA_OSC base pointer */
  #define ANA_OSC                                  ((ANA_OSC_Type *)ANA_OSC_BASE)
  /** Peripheral ANA_OSC base pointer */
  #define ANA_OSC_NS                               ((ANA_OSC_Type *)ANA_OSC_BASE_NS)
  /** Array initializer of ANA_OSC peripheral base addresses */
  #define ANA_OSC_BASE_ADDRS                       { ANA_OSC_BASE }
  /** Array initializer of ANA_OSC peripheral base pointers */
  #define ANA_OSC_BASE_PTRS                        { ANA_OSC }
  /** Array initializer of ANA_OSC peripheral base addresses */
  #define ANA_OSC_BASE_ADDRS_NS                    { ANA_OSC_BASE_NS }
  /** Array initializer of ANA_OSC peripheral base pointers */
  #define ANA_OSC_BASE_PTRS_NS                     { ANA_OSC_NS }
#else
  /** Peripheral ANA_OSC base address */
  #define ANA_OSC_BASE                             (0x44480000u)
  /** Peripheral ANA_OSC base pointer */
  #define ANA_OSC                                  ((ANA_OSC_Type *)ANA_OSC_BASE)
  /** Array initializer of ANA_OSC peripheral base addresses */
  #define ANA_OSC_BASE_ADDRS                       { ANA_OSC_BASE }
  /** Array initializer of ANA_OSC peripheral base pointers */
  #define ANA_OSC_BASE_PTRS                        { ANA_OSC }
#endif

/* AXBS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AXBS base address */
  #define AXBS_BASE                                (0x54510000u)
  /** Peripheral AXBS base address */
  #define AXBS_BASE_NS                             (0x44510000u)
  /** Peripheral AXBS base pointer */
  #define AXBS                                     ((AXBS_Type *)AXBS_BASE)
  /** Peripheral AXBS base pointer */
  #define AXBS_NS                                  ((AXBS_Type *)AXBS_BASE_NS)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS }
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS_NS                       { AXBS_BASE_NS }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS_NS                        { AXBS_NS }
#else
  /** Peripheral AXBS base address */
  #define AXBS_BASE                                (0x44510000u)
  /** Peripheral AXBS base pointer */
  #define AXBS                                     ((AXBS_Type *)AXBS_BASE)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS }
#endif

/* BBNSM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x54440000u)
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE_NS                            (0x44440000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Peripheral BBNSM base pointer */
  #define BBNSM_NS                                 ((BBNSM_Type *)BBNSM_BASE_NS)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS_NS                      { BBNSM_BASE_NS }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS_NS                       { BBNSM_NS }
#else
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x44440000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
#endif

/* BLK_CTRL_MLMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_MLMIX base address */
  #define BLK_CTRL_MLMIX_BASE                      (0x5A810000u)
  /** Peripheral BLK_CTRL_MLMIX base address */
  #define BLK_CTRL_MLMIX_BASE_NS                   (0x4A810000u)
  /** Peripheral BLK_CTRL_MLMIX base pointer */
  #define BLK_CTRL_MLMIX                           ((BLK_CTRL_MLMIX_Type *)BLK_CTRL_MLMIX_BASE)
  /** Peripheral BLK_CTRL_MLMIX base pointer */
  #define BLK_CTRL_MLMIX_NS                        ((BLK_CTRL_MLMIX_Type *)BLK_CTRL_MLMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_MLMIX peripheral base addresses */
  #define BLK_CTRL_MLMIX_BASE_ADDRS                { BLK_CTRL_MLMIX_BASE }
  /** Array initializer of BLK_CTRL_MLMIX peripheral base pointers */
  #define BLK_CTRL_MLMIX_BASE_PTRS                 { BLK_CTRL_MLMIX }
  /** Array initializer of BLK_CTRL_MLMIX peripheral base addresses */
  #define BLK_CTRL_MLMIX_BASE_ADDRS_NS             { BLK_CTRL_MLMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_MLMIX peripheral base pointers */
  #define BLK_CTRL_MLMIX_BASE_PTRS_NS              { BLK_CTRL_MLMIX_NS }
#else
  /** Peripheral BLK_CTRL_MLMIX base address */
  #define BLK_CTRL_MLMIX_BASE                      (0x4A810000u)
  /** Peripheral BLK_CTRL_MLMIX base pointer */
  #define BLK_CTRL_MLMIX                           ((BLK_CTRL_MLMIX_Type *)BLK_CTRL_MLMIX_BASE)
  /** Array initializer of BLK_CTRL_MLMIX peripheral base addresses */
  #define BLK_CTRL_MLMIX_BASE_ADDRS                { BLK_CTRL_MLMIX_BASE }
  /** Array initializer of BLK_CTRL_MLMIX peripheral base pointers */
  #define BLK_CTRL_MLMIX_BASE_PTRS                 { BLK_CTRL_MLMIX }
#endif

/* BLK_CTRL_NICMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_NIC_WRAPPER1 base address */
  #define BLK_CTRL_NIC_WRAPPER1_BASE               (0x59000000u)
  /** Peripheral BLK_CTRL_NIC_WRAPPER1 base address */
  #define BLK_CTRL_NIC_WRAPPER1_BASE_NS            (0x49000000u)
  /** Peripheral BLK_CTRL_NIC_WRAPPER1 base pointer */
  #define BLK_CTRL_NIC_WRAPPER1                    ((BLK_CTRL_NICMIX_Type *)BLK_CTRL_NIC_WRAPPER1_BASE)
  /** Peripheral BLK_CTRL_NIC_WRAPPER1 base pointer */
  #define BLK_CTRL_NIC_WRAPPER1_NS                 ((BLK_CTRL_NICMIX_Type *)BLK_CTRL_NIC_WRAPPER1_BASE_NS)
  /** Array initializer of BLK_CTRL_NICMIX peripheral base addresses */
  #define BLK_CTRL_NICMIX_BASE_ADDRS               { BLK_CTRL_NIC_WRAPPER1_BASE }
  /** Array initializer of BLK_CTRL_NICMIX peripheral base pointers */
  #define BLK_CTRL_NICMIX_BASE_PTRS                { BLK_CTRL_NIC_WRAPPER1 }
  /** Array initializer of BLK_CTRL_NICMIX peripheral base addresses */
  #define BLK_CTRL_NICMIX_BASE_ADDRS_NS            { BLK_CTRL_NIC_WRAPPER1_BASE_NS }
  /** Array initializer of BLK_CTRL_NICMIX peripheral base pointers */
  #define BLK_CTRL_NICMIX_BASE_PTRS_NS             { BLK_CTRL_NIC_WRAPPER1_NS }
#else
  /** Peripheral BLK_CTRL_NIC_WRAPPER1 base address */
  #define BLK_CTRL_NIC_WRAPPER1_BASE               (0x49000000u)
  /** Peripheral BLK_CTRL_NIC_WRAPPER1 base pointer */
  #define BLK_CTRL_NIC_WRAPPER1                    ((BLK_CTRL_NICMIX_Type *)BLK_CTRL_NIC_WRAPPER1_BASE)
  /** Array initializer of BLK_CTRL_NICMIX peripheral base addresses */
  #define BLK_CTRL_NICMIX_BASE_ADDRS               { BLK_CTRL_NIC_WRAPPER1_BASE }
  /** Array initializer of BLK_CTRL_NICMIX peripheral base pointers */
  #define BLK_CTRL_NICMIX_BASE_PTRS                { BLK_CTRL_NIC_WRAPPER1 }
#endif

/* BLK_CTRL_NS_AONMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE                  (0x54210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE_NS               (0x44210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX                       ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX_NS                    ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS_NS         { BLK_CTRL_NS_AONMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS_NS          { BLK_CTRL_NS_AONMIX_NS }
#else
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE                  (0x44210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX                       ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX }
#endif

/* BLK_CTRL_S_AONMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE                   (0x544F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE_NS                (0x444F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX                        ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX_NS                     ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS_NS          { BLK_CTRL_S_AONMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS_NS           { BLK_CTRL_S_AONMIX_NS }
#else
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE                   (0x444F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX                        ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX }
#endif

/* BLK_CTRL_WAKEUPMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE                  (0x52420000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE_NS               (0x42420000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX                       ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX_NS                    ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS_NS         { BLK_CTRL_WAKEUPMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS_NS          { BLK_CTRL_WAKEUPMIX_NS }
#else
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE                  (0x42420000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX                       ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }
#endif

/* CACHE_ECC_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CM33_CACHE_ECC_MCM base address */
  #define CM33_CACHE_ECC_MCM_BASE                  (0x54401000u)
  /** Peripheral CM33_CACHE_ECC_MCM base address */
  #define CM33_CACHE_ECC_MCM_BASE_NS               (0x44401000u)
  /** Peripheral CM33_CACHE_ECC_MCM base pointer */
  #define CM33_CACHE_ECC_MCM                       ((CACHE_ECC_MCM_Type *)CM33_CACHE_ECC_MCM_BASE)
  /** Peripheral CM33_CACHE_ECC_MCM base pointer */
  #define CM33_CACHE_ECC_MCM_NS                    ((CACHE_ECC_MCM_Type *)CM33_CACHE_ECC_MCM_BASE_NS)
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS                 { CM33_CACHE_ECC_MCM_BASE }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS                  { CM33_CACHE_ECC_MCM }
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS_NS              { CM33_CACHE_ECC_MCM_BASE_NS }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS_NS               { CM33_CACHE_ECC_MCM_NS }
#else
  /** Peripheral CM33_CACHE_ECC_MCM base address */
  #define CM33_CACHE_ECC_MCM_BASE                  (0x44401000u)
  /** Peripheral CM33_CACHE_ECC_MCM base pointer */
  #define CM33_CACHE_ECC_MCM                       ((CACHE_ECC_MCM_Type *)CM33_CACHE_ECC_MCM_BASE)
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS                 { CM33_CACHE_ECC_MCM_BASE }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS                  { CM33_CACHE_ECC_MCM }
#endif

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x543A0000u)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE_NS                             (0x443A0000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Peripheral CAN1 base pointer */
  #define CAN1_NS                                  ((CAN_Type *)CAN1_BASE_NS)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE                                (0x525B0000u)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE_NS                             (0x425B0000u)
  /** Peripheral CAN2 base pointer */
  #define CAN2                                     ((CAN_Type *)CAN2_BASE)
  /** Peripheral CAN2 base pointer */
  #define CAN2_NS                                  ((CAN_Type *)CAN2_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { 0u, CAN1_BASE_NS, CAN2_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { (CAN_Type *)0u, CAN1_NS, CAN2_NS }
#else
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x443A0000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE                                (0x425B0000u)
  /** Peripheral CAN2 base pointer */
  #define CAN2                                     ((CAN_Type *)CAN2_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Tx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Wake_Up_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Error_IRQS                           { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Bus_Off_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }

/* CCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x54450000u)
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE_NS                         (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL_NS                              ((CCM_Type *)CCM_CTRL_BASE_NS)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS_NS                        { CCM_CTRL_BASE_NS }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS_NS                         { CCM_CTRL_NS }
#else
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
#endif

/* DDRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DDR_CTRL base address */
  #define DDR_CTRL_BASE                            (0x5E300000u)
  /** Peripheral DDR_CTRL base address */
  #define DDR_CTRL_BASE_NS                         (0x4E300000u)
  /** Peripheral DDR_CTRL base pointer */
  #define DDR_CTRL                                 ((DDRC_Type *)DDR_CTRL_BASE)
  /** Peripheral DDR_CTRL base pointer */
  #define DDR_CTRL_NS                              ((DDRC_Type *)DDR_CTRL_BASE_NS)
  /** Array initializer of DDRC peripheral base addresses */
  #define DDRC_BASE_ADDRS                          { DDR_CTRL_BASE }
  /** Array initializer of DDRC peripheral base pointers */
  #define DDRC_BASE_PTRS                           { DDR_CTRL }
  /** Array initializer of DDRC peripheral base addresses */
  #define DDRC_BASE_ADDRS_NS                       { DDR_CTRL_BASE_NS }
  /** Array initializer of DDRC peripheral base pointers */
  #define DDRC_BASE_PTRS_NS                        { DDR_CTRL_NS }
#else
  /** Peripheral DDR_CTRL base address */
  #define DDR_CTRL_BASE                            (0x4E300000u)
  /** Peripheral DDR_CTRL base pointer */
  #define DDR_CTRL                                 ((DDRC_Type *)DDR_CTRL_BASE)
  /** Array initializer of DDRC peripheral base addresses */
  #define DDRC_BASE_ADDRS                          { DDR_CTRL_BASE }
  /** Array initializer of DDRC peripheral base pointers */
  #define DDRC_BASE_PTRS                           { DDR_CTRL }
#endif

/* DDRMIX_BLK_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE                     (0x5E010000u)
  /** Peripheral BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE_NS                  (0x4E010000u)
  /** Peripheral BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX                          ((DDRMIX_BLK_CTRL_Type *)BLK_CTRL_DDRMIX_BASE)
  /** Peripheral BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX_NS                       ((DDRMIX_BLK_CTRL_Type *)BLK_CTRL_DDRMIX_BASE_NS)
  /** Array initializer of DDRMIX_BLK_CTRL peripheral base addresses */
  #define DDRMIX_BLK_CTRL_BASE_ADDRS               { BLK_CTRL_DDRMIX_BASE }
  /** Array initializer of DDRMIX_BLK_CTRL peripheral base pointers */
  #define DDRMIX_BLK_CTRL_BASE_PTRS                { BLK_CTRL_DDRMIX }
  /** Array initializer of DDRMIX_BLK_CTRL peripheral base addresses */
  #define DDRMIX_BLK_CTRL_BASE_ADDRS_NS            { BLK_CTRL_DDRMIX_BASE_NS }
  /** Array initializer of DDRMIX_BLK_CTRL peripheral base pointers */
  #define DDRMIX_BLK_CTRL_BASE_PTRS_NS             { BLK_CTRL_DDRMIX_NS }
#else
  /** Peripheral BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE                     (0x4E010000u)
  /** Peripheral BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX                          ((DDRMIX_BLK_CTRL_Type *)BLK_CTRL_DDRMIX_BASE)
  /** Array initializer of DDRMIX_BLK_CTRL peripheral base addresses */
  #define DDRMIX_BLK_CTRL_BASE_ADDRS               { BLK_CTRL_DDRMIX_BASE }
  /** Array initializer of DDRMIX_BLK_CTRL peripheral base pointers */
  #define DDRMIX_BLK_CTRL_BASE_PTRS                { BLK_CTRL_DDRMIX }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x54000000u)
  /** Peripheral DMA3 base address */
  #define DMA3_BASE_NS                             (0x44000000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Peripheral DMA3 base pointer */
  #define DMA3_NS                                  ((DMA_Type *)DMA3_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA3 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { DMA3_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { DMA3_NS }
#else
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x44000000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA3 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA3_0_IRQn, DMA3_1_IRQn, DMA3_2_IRQn, DMA3_3_IRQn, DMA3_4_IRQn, DMA3_5_IRQn, DMA3_6_IRQn, DMA3_7_IRQn, DMA3_8_IRQn, DMA3_9_IRQn, DMA3_10_IRQn, DMA3_11_IRQn, DMA3_12_IRQn, DMA3_13_IRQn, DMA3_14_IRQn, DMA3_15_IRQn, DMA3_16_IRQn, DMA3_17_IRQn, DMA3_18_IRQn, DMA3_19_IRQn, DMA3_20_IRQn, DMA3_21_IRQn, DMA3_22_IRQn, DMA3_23_IRQn, DMA3_24_IRQn, DMA3_25_IRQn, DMA3_26_IRQn, DMA3_27_IRQn, DMA3_28_IRQn, DMA3_29_IRQn, DMA3_30_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn } }

/* DMA4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA4 base address */
  #define DMA4_BASE                                (0x52000000u)
  /** Peripheral DMA4 base address */
  #define DMA4_BASE_NS                             (0x42000000u)
  /** Peripheral DMA4 base pointer */
  #define DMA4                                     ((DMA4_Type *)DMA4_BASE)
  /** Peripheral DMA4 base pointer */
  #define DMA4_NS                                  ((DMA4_Type *)DMA4_BASE_NS)
  /** Array initializer of DMA4 peripheral base addresses */
  #define DMA4_BASE_ADDRS                          { DMA4_BASE }
  /** Array initializer of DMA4 peripheral base pointers */
  #define DMA4_BASE_PTRS                           { DMA4 }
  /** Array initializer of DMA4 peripheral base addresses */
  #define DMA4_BASE_ADDRS_NS                       { DMA4_BASE_NS }
  /** Array initializer of DMA4 peripheral base pointers */
  #define DMA4_BASE_PTRS_NS                        { DMA4_NS }
#else
  /** Peripheral DMA4 base address */
  #define DMA4_BASE                                (0x42000000u)
  /** Peripheral DMA4 base pointer */
  #define DMA4                                     ((DMA4_Type *)DMA4_BASE)
  /** Array initializer of DMA4 peripheral base addresses */
  #define DMA4_BASE_ADDRS                          { DMA4_BASE }
  /** Array initializer of DMA4 peripheral base pointers */
  #define DMA4_BASE_PTRS                           { DMA4 }
#endif

/* ENET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENET base address */
  #define ENET_BASE                                (0x52890000u)
  /** Peripheral ENET base address */
  #define ENET_BASE_NS                             (0x42890000u)
  /** Peripheral ENET base pointer */
  #define ENET                                     ((ENET_Type *)ENET_BASE)
  /** Peripheral ENET base pointer */
  #define ENET_NS                                  ((ENET_Type *)ENET_BASE_NS)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { ENET_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { ENET }
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS_NS                       { ENET_BASE_NS }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS_NS                        { ENET_NS }
#else
  /** Peripheral ENET base address */
  #define ENET_BASE                                (0x42890000u)
  /** Peripheral ENET base pointer */
  #define ENET                                     ((ENET_Type *)ENET_BASE)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { ENET_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { ENET }
#endif
/** Interrupt vectors for the ENET peripheral type */
#define ENET_Transmit_IRQS                       { ENET_IRQn }
#define ENET_Receive_IRQS                        { ENET_IRQn }
#define ENET_Error_IRQS                          { ENET_IRQn }
#define ENET_1588_Timer_IRQS                     { ENET_IRQn }
#define ENET_Ts_IRQS                             { ENET_IRQn }
/* ENET Buffer Descriptor and Buffer Address Alignment. */
#define ENET_BUFF_ALIGNMENT                      (64U)


/* ENET_QOS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENET_QOS base address */
  #define ENET_QOS_BASE                            (0x528A0000u)
  /** Peripheral ENET_QOS base address */
  #define ENET_QOS_BASE_NS                         (0x428A0000u)
  /** Peripheral ENET_QOS base pointer */
  #define ENET_QOS                                 ((ENET_QOS_Type *)ENET_QOS_BASE)
  /** Peripheral ENET_QOS base pointer */
  #define ENET_QOS_NS                              ((ENET_QOS_Type *)ENET_QOS_BASE_NS)
  /** Array initializer of ENET_QOS peripheral base addresses */
  #define ENET_QOS_BASE_ADDRS                      { ENET_QOS_BASE }
  /** Array initializer of ENET_QOS peripheral base pointers */
  #define ENET_QOS_BASE_PTRS                       { ENET_QOS }
  /** Array initializer of ENET_QOS peripheral base addresses */
  #define ENET_QOS_BASE_ADDRS_NS                   { ENET_QOS_BASE_NS }
  /** Array initializer of ENET_QOS peripheral base pointers */
  #define ENET_QOS_BASE_PTRS_NS                    { ENET_QOS_NS }
#else
  /** Peripheral ENET_QOS base address */
  #define ENET_QOS_BASE                            (0x428A0000u)
  /** Peripheral ENET_QOS base pointer */
  #define ENET_QOS                                 ((ENET_QOS_Type *)ENET_QOS_BASE)
  /** Array initializer of ENET_QOS peripheral base addresses */
  #define ENET_QOS_BASE_ADDRS                      { ENET_QOS_BASE }
  /** Array initializer of ENET_QOS peripheral base pointers */
  #define ENET_QOS_BASE_PTRS                       { ENET_QOS }
#endif
/** Interrupt vectors for the ENET_QOS peripheral type */
#define ENET_QOS_IRQS                            { ENET_QOS_IRQn }
#define ENET_QOS_PMT_IRQS                        { ENET_QOS_PMT_IRQn }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE                             (0x525C0000u)
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE_NS                          (0x425C0000u)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1_NS                               ((FLEXIO_Type *)FLEXIO1_BASE_NS)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE                             (0x525D0000u)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE_NS                          (0x425D0000u)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2_NS                               ((FLEXIO_Type *)FLEXIO2_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { 0u, FLEXIO1_BASE_NS, FLEXIO2_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { (FLEXIO_Type *)0u, FLEXIO1_NS, FLEXIO2_NS }
#else
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE                             (0x425C0000u)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE                             (0x425D0000u)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2 }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI base address */
  #define FLEXSPI_BASE                             (0x525E0000u)
  /** Peripheral FLEXSPI base address */
  #define FLEXSPI_BASE_NS                          (0x425E0000u)
  /** Peripheral FLEXSPI base pointer */
  #define FLEXSPI                                  ((FLEXSPI_Type *)FLEXSPI_BASE)
  /** Peripheral FLEXSPI base pointer */
  #define FLEXSPI_NS                               ((FLEXSPI_Type *)FLEXSPI_BASE_NS)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI }
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS_NS                    { FLEXSPI_BASE_NS }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS_NS                     { FLEXSPI_NS }
#else
  /** Peripheral FLEXSPI base address */
  #define FLEXSPI_BASE                             (0x425E0000u)
  /** Peripheral FLEXSPI base pointer */
  #define FLEXSPI                                  ((FLEXSPI_Type *)FLEXSPI_BASE)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI }
#endif
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FlexSPI1_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** FlexSPI AMBA base address array */
  #define FlexSPI_AMBA_BASE_ARRAY                  { {0x38000000u} }
  #define FlexSPI_AMBA_BASE_ARRAY_NS               { {0x28000000u} }
  /** FlexSPI AMBA end address array */
  #define FlexSPI_AMBA_END_ARRAY                   { {0x3FFFFFFFu} }
  #define FlexSPI_AMBA_END_ARRAY_NS                { {0x2FFFFFFFu} }
  /* FlexSPI AMBA address. */
  #define FlexSPI_AMBA_BASE                        (0x38000000u)
  #define FlexSPI_AMBA_BASE_NS                     (0x28000000u)
  /* FlexSPI ASFM address. */
  #define FlexSPI_ASFM_BASE                        (0x38000000u)
  #define FlexSPI_ASFM_BASE_NS                     (0x28000000u)
  /* Base Address of AHB address space mapped to IP RX FIFO. */
  #define FlexSPI_ARDF_BASE                        (0x57420000u)
  #define FlexSPI_ARDF_BASE_NS                     (0x47420000u)
  /* Base Address of AHB address space mapped to IP TX FIFO. */
  #define FlexSPI_ATDF_BASE                        (0x57430000u)
  #define FlexSPI_ATDF_BASE_NS                     (0x47430000u)
#else
  /** FlexSPI AMBA base address array */
  #define FlexSPI_AMBA_BASE_ARRAY                  { {0x28000000u} }
  /** FlexSPI AMBA end address array */
  #define FlexSPI_AMBA_END_ARRAY                   { {0x2FFFFFFFu} }
  /* FlexSPI AMBA address. */
  #define FlexSPI_AMBA_BASE                        (0x28000000u)
  /* FlexSPI ASFM address. */
  #define FlexSPI_ASFM_BASE                        (0x28000000u)
  /* Base Address of AHB address space mapped to IP RX FIFO. */
  #define FlexSPI_ARDF_BASE                        (0x47420000u)
  /* Base Address of AHB address space mapped to IP TX FIFO. */
  #define FlexSPI_ATDF_BASE                        (0x47430000u)
#endif


/* FSB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FSB1 base address */
  #define FSB1_BASE                                (0x57510000u)
  /** Peripheral FSB1 base address */
  #define FSB1_BASE_NS                             (0x47510000u)
  /** Peripheral FSB1 base pointer */
  #define FSB1                                     ((FSB_Type *)FSB1_BASE)
  /** Peripheral FSB1 base pointer */
  #define FSB1_NS                                  ((FSB_Type *)FSB1_BASE_NS)
  /** Array initializer of FSB peripheral base addresses */
  #define FSB_BASE_ADDRS                           { FSB1_BASE }
  /** Array initializer of FSB peripheral base pointers */
  #define FSB_BASE_PTRS                            { FSB1 }
  /** Array initializer of FSB peripheral base addresses */
  #define FSB_BASE_ADDRS_NS                        { FSB1_BASE_NS }
  /** Array initializer of FSB peripheral base pointers */
  #define FSB_BASE_PTRS_NS                         { FSB1_NS }
#else
  /** Peripheral FSB1 base address */
  #define FSB1_BASE                                (0x47510000u)
  /** Peripheral FSB1 base pointer */
  #define FSB1                                     ((FSB_Type *)FSB1_BASE)
  /** Array initializer of FSB peripheral base addresses */
  #define FSB_BASE_ADDRS                           { FSB1_BASE }
  /** Array initializer of FSB peripheral base pointers */
  #define FSB_BASE_PTRS                            { FSB1 }
#endif

/* GPC_CPU_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_CTRL_CM33 base address */
  #define GPC_CTRL_CM33_BASE                       (0x54470000u)
  /** Peripheral GPC_CTRL_CM33 base address */
  #define GPC_CTRL_CM33_BASE_NS                    (0x44470000u)
  /** Peripheral GPC_CTRL_CM33 base pointer */
  #define GPC_CTRL_CM33                            ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM33_BASE)
  /** Peripheral GPC_CTRL_CM33 base pointer */
  #define GPC_CTRL_CM33_NS                         ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM33_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_0 base address */
  #define GPC_CTRL_CA55_0_BASE                     (0x54470800u)
  /** Peripheral GPC_CTRL_CA55_0 base address */
  #define GPC_CTRL_CA55_0_BASE_NS                  (0x44470800u)
  /** Peripheral GPC_CTRL_CA55_0 base pointer */
  #define GPC_CTRL_CA55_0                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_0_BASE)
  /** Peripheral GPC_CTRL_CA55_0 base pointer */
  #define GPC_CTRL_CA55_0_NS                       ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_0_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_1 base address */
  #define GPC_CTRL_CA55_1_BASE                     (0x54471000u)
  /** Peripheral GPC_CTRL_CA55_1 base address */
  #define GPC_CTRL_CA55_1_BASE_NS                  (0x44471000u)
  /** Peripheral GPC_CTRL_CA55_1 base pointer */
  #define GPC_CTRL_CA55_1                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_1_BASE)
  /** Peripheral GPC_CTRL_CA55_1 base pointer */
  #define GPC_CTRL_CA55_1_NS                       ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_1_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base address */
  #define GPC_CTRL_CA55_CLUSTER_BASE               (0x54471800u)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base address */
  #define GPC_CTRL_CA55_CLUSTER_BASE_NS            (0x44471800u)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base pointer */
  #define GPC_CTRL_CA55_CLUSTER                    ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_CLUSTER_BASE)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base pointer */
  #define GPC_CTRL_CA55_CLUSTER_NS                 ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_CLUSTER_BASE_NS)
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS                  { GPC_CTRL_CM33_BASE, GPC_CTRL_CA55_0_BASE, GPC_CTRL_CA55_1_BASE, GPC_CTRL_CA55_CLUSTER_BASE }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS                   { GPC_CTRL_CM33, GPC_CTRL_CA55_0, GPC_CTRL_CA55_1, GPC_CTRL_CA55_CLUSTER }
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS_NS               { GPC_CTRL_CM33_BASE_NS, GPC_CTRL_CA55_0_BASE_NS, GPC_CTRL_CA55_1_BASE_NS, GPC_CTRL_CA55_CLUSTER_BASE_NS }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS_NS                { GPC_CTRL_CM33_NS, GPC_CTRL_CA55_0_NS, GPC_CTRL_CA55_1_NS, GPC_CTRL_CA55_CLUSTER_NS }
#else
  /** Peripheral GPC_CTRL_CM33 base address */
  #define GPC_CTRL_CM33_BASE                       (0x44470000u)
  /** Peripheral GPC_CTRL_CM33 base pointer */
  #define GPC_CTRL_CM33                            ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM33_BASE)
  /** Peripheral GPC_CTRL_CA55_0 base address */
  #define GPC_CTRL_CA55_0_BASE                     (0x44470800u)
  /** Peripheral GPC_CTRL_CA55_0 base pointer */
  #define GPC_CTRL_CA55_0                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_0_BASE)
  /** Peripheral GPC_CTRL_CA55_1 base address */
  #define GPC_CTRL_CA55_1_BASE                     (0x44471000u)
  /** Peripheral GPC_CTRL_CA55_1 base pointer */
  #define GPC_CTRL_CA55_1                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_1_BASE)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base address */
  #define GPC_CTRL_CA55_CLUSTER_BASE               (0x44471800u)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base pointer */
  #define GPC_CTRL_CA55_CLUSTER                    ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_CLUSTER_BASE)
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS                  { GPC_CTRL_CM33_BASE, GPC_CTRL_CA55_0_BASE, GPC_CTRL_CA55_1_BASE, GPC_CTRL_CA55_CLUSTER_BASE }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS                   { GPC_CTRL_CM33, GPC_CTRL_CA55_0, GPC_CTRL_CA55_1, GPC_CTRL_CA55_CLUSTER }
#endif

/* GPC_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE                          (0x54474000u)
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE_NS                       (0x44474000u)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL_NS                            ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE_NS)
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS_NS                 { GPC_GLOBAL_BASE_NS }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS_NS                  { GPC_GLOBAL_NS }
#else
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE                          (0x44474000u)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }
#endif

/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x543B0000u)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE_NS                             (0x443B0000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI1 base pointer */
  #define SAI1_NS                                  ((I2S_Type *)SAI1_BASE_NS)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x52650000u)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE_NS                             (0x42650000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI2 base pointer */
  #define SAI2_NS                                  ((I2S_Type *)SAI2_BASE_NS)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x52660000u)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE_NS                             (0x42660000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI3 base pointer */
  #define SAI3_NS                                  ((I2S_Type *)SAI3_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { 0u, SAI1_BASE_NS, SAI2_BASE_NS, SAI3_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { (I2S_Type *)0u, SAI1_NS, SAI2_NS, SAI3_NS }
#else
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x443B0000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x42650000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x42660000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3 }
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x54330000u)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE_NS                             (0x44330000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C1 base pointer */
  #define I3C1_NS                                  ((I3C_Type *)I3C1_BASE_NS)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x52520000u)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE_NS                             (0x42520000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C2 base pointer */
  #define I3C2_NS                                  ((I3C_Type *)I3C2_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { 0u, I3C1_BASE, I3C2_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { (I3C_Type *)0u, I3C1, I3C2 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { 0u, I3C1_BASE_NS, I3C2_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { (I3C_Type *)0u, I3C1_NS, I3C2_NS }
#else
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x44330000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x42520000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { 0u, I3C1_BASE, I3C2_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { (I3C_Type *)0u, I3C1, I3C2 }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { NotAvail_IRQn, I3C1_IRQn, I3C2_IRQn }

/* IOMUXC1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC1 base address */
  #define IOMUXC1_BASE                             (0x543C0000u)
  /** Peripheral IOMUXC1 base address */
  #define IOMUXC1_BASE_NS                          (0x443C0000u)
  /** Peripheral IOMUXC1 base pointer */
  #define IOMUXC1                                  ((IOMUXC1_Type *)IOMUXC1_BASE)
  /** Peripheral IOMUXC1 base pointer */
  #define IOMUXC1_NS                               ((IOMUXC1_Type *)IOMUXC1_BASE_NS)
  /** Array initializer of IOMUXC1 peripheral base addresses */
  #define IOMUXC1_BASE_ADDRS                       { IOMUXC1_BASE }
  /** Array initializer of IOMUXC1 peripheral base pointers */
  #define IOMUXC1_BASE_PTRS                        { IOMUXC1 }
  /** Array initializer of IOMUXC1 peripheral base addresses */
  #define IOMUXC1_BASE_ADDRS_NS                    { IOMUXC1_BASE_NS }
  /** Array initializer of IOMUXC1 peripheral base pointers */
  #define IOMUXC1_BASE_PTRS_NS                     { IOMUXC1_NS }
#else
  /** Peripheral IOMUXC1 base address */
  #define IOMUXC1_BASE                             (0x443C0000u)
  /** Peripheral IOMUXC1 base pointer */
  #define IOMUXC1                                  ((IOMUXC1_Type *)IOMUXC1_BASE)
  /** Array initializer of IOMUXC1 peripheral base addresses */
  #define IOMUXC1_BASE_ADDRS                       { IOMUXC1_BASE }
  /** Array initializer of IOMUXC1 peripheral base pointers */
  #define IOMUXC1_BASE_PTRS                        { IOMUXC1 }
#endif

/* IPC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IPC base address */
  #define IPC_BASE                                 (0x543D0000u)
  /** Peripheral IPC base address */
  #define IPC_BASE_NS                              (0x443D0000u)
  /** Peripheral IPC base pointer */
  #define IPC                                      ((IPC_Type *)IPC_BASE)
  /** Peripheral IPC base pointer */
  #define IPC_NS                                   ((IPC_Type *)IPC_BASE_NS)
  /** Array initializer of IPC peripheral base addresses */
  #define IPC_BASE_ADDRS                           { IPC_BASE }
  /** Array initializer of IPC peripheral base pointers */
  #define IPC_BASE_PTRS                            { IPC }
  /** Array initializer of IPC peripheral base addresses */
  #define IPC_BASE_ADDRS_NS                        { IPC_BASE_NS }
  /** Array initializer of IPC peripheral base pointers */
  #define IPC_BASE_PTRS_NS                         { IPC_NS }
#else
  /** Peripheral IPC base address */
  #define IPC_BASE                                 (0x443D0000u)
  /** Peripheral IPC base pointer */
  #define IPC                                      ((IPC_Type *)IPC_BASE)
  /** Array initializer of IPC peripheral base addresses */
  #define IPC_BASE_ADDRS                           { IPC_BASE }
  /** Array initializer of IPC peripheral base pointers */
  #define IPC_BASE_PTRS                            { IPC }
#endif

/* ISI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ISI base address */
  #define ISI_BASE                                 (0x5AE40000u)
  /** Peripheral ISI base address */
  #define ISI_BASE_NS                              (0x4AE40000u)
  /** Peripheral ISI base pointer */
  #define ISI                                      ((ISI_Type *)ISI_BASE)
  /** Peripheral ISI base pointer */
  #define ISI_NS                                   ((ISI_Type *)ISI_BASE_NS)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { ISI_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { ISI }
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS_NS                        { ISI_BASE_NS }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS_NS                         { ISI_NS }
#else
  /** Peripheral ISI base address */
  #define ISI_BASE                                 (0x4AE40000u)
  /** Peripheral ISI base pointer */
  #define ISI                                      ((ISI_Type *)ISI_BASE)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { ISI_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { ISI }
#endif

/* LCDIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE                               (0x5AE30000u)
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE_NS                            (0x4AE30000u)
  /** Peripheral LCDIF base pointer */
  #define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
  /** Peripheral LCDIF base pointer */
  #define LCDIF_NS                                 ((LCDIF_Type *)LCDIF_BASE_NS)
  /** Array initializer of LCDIF peripheral base addresses */
  #define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
  /** Array initializer of LCDIF peripheral base pointers */
  #define LCDIF_BASE_PTRS                          { LCDIF }
  /** Array initializer of LCDIF peripheral base addresses */
  #define LCDIF_BASE_ADDRS_NS                      { LCDIF_BASE_NS }
  /** Array initializer of LCDIF peripheral base pointers */
  #define LCDIF_BASE_PTRS_NS                       { LCDIF_NS }
#else
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE                               (0x4AE30000u)
  /** Peripheral LCDIF base pointer */
  #define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
  /** Array initializer of LCDIF peripheral base addresses */
  #define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
  /** Array initializer of LCDIF peripheral base pointers */
  #define LCDIF_BASE_PTRS                          { LCDIF }
#endif

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x54340000u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x44340000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x54350000u)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE_NS                           (0x44350000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2_NS                                ((LPI2C_Type *)LPI2C2_BASE_NS)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x52530000u)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE_NS                           (0x42530000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3_NS                                ((LPI2C_Type *)LPI2C3_BASE_NS)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x52540000u)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE_NS                           (0x42540000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4_NS                                ((LPI2C_Type *)LPI2C4_BASE_NS)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x526B0000u)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE_NS                           (0x426B0000u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5_NS                                ((LPI2C_Type *)LPI2C5_BASE_NS)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x526C0000u)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE_NS                           (0x426C0000u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6_NS                                ((LPI2C_Type *)LPI2C6_BASE_NS)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x526D0000u)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE_NS                           (0x426D0000u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7_NS                                ((LPI2C_Type *)LPI2C7_BASE_NS)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE                              (0x526E0000u)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE_NS                           (0x426E0000u)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8_NS                                ((LPI2C_Type *)LPI2C8_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { 0u, LPI2C1_BASE_NS, LPI2C2_BASE_NS, LPI2C3_BASE_NS, LPI2C4_BASE_NS, LPI2C5_BASE_NS, LPI2C6_BASE_NS, LPI2C7_BASE_NS, LPI2C8_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { (LPI2C_Type *)0u, LPI2C1_NS, LPI2C2_NS, LPI2C3_NS, LPI2C4_NS, LPI2C5_NS, LPI2C6_NS, LPI2C7_NS, LPI2C8_NS }
#else
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x44340000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x44350000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x42530000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x42540000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x426B0000u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x426C0000u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x426D0000u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE                              (0x426E0000u)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn, LPI2C5_IRQn, LPI2C6_IRQn, LPI2C7_IRQn, LPI2C8_IRQn }

/* LPIT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE                               (0x542F0000u)
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE_NS                            (0x442F0000u)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1_NS                                 ((LPIT_Type *)LPIT1_BASE_NS)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE                               (0x524C0000u)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE_NS                            (0x424C0000u)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2                                    ((LPIT_Type *)LPIT2_BASE)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2_NS                                 ((LPIT_Type *)LPIT2_BASE_NS)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2 }
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS_NS                       { 0u, LPIT1_BASE_NS, LPIT2_BASE_NS }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS_NS                        { (LPIT_Type *)0u, LPIT1_NS, LPIT2_NS }
#else
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE                               (0x442F0000u)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE                               (0x424C0000u)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2                                    ((LPIT_Type *)LPIT2_BASE)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2 }
#endif

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x54360000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x44360000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1_NS                                ((LPSPI_Type *)LPSPI1_BASE_NS)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x54370000u)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE_NS                           (0x44370000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2_NS                                ((LPSPI_Type *)LPSPI2_BASE_NS)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x52550000u)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE_NS                           (0x42550000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3_NS                                ((LPSPI_Type *)LPSPI3_BASE_NS)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x52560000u)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE_NS                           (0x42560000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4_NS                                ((LPSPI_Type *)LPSPI4_BASE_NS)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x526F0000u)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE_NS                           (0x426F0000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5_NS                                ((LPSPI_Type *)LPSPI5_BASE_NS)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE                              (0x52700000u)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE_NS                           (0x42700000u)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6_NS                                ((LPSPI_Type *)LPSPI6_BASE_NS)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE                              (0x52710000u)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE_NS                           (0x42710000u)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7_NS                                ((LPSPI_Type *)LPSPI7_BASE_NS)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE                              (0x52720000u)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE_NS                           (0x42720000u)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8_NS                                ((LPSPI_Type *)LPSPI8_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { 0u, LPSPI1_BASE_NS, LPSPI2_BASE_NS, LPSPI3_BASE_NS, LPSPI4_BASE_NS, LPSPI5_BASE_NS, LPSPI6_BASE_NS, LPSPI7_BASE_NS, LPSPI8_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { (LPSPI_Type *)0u, LPSPI1_NS, LPSPI2_NS, LPSPI3_NS, LPSPI4_NS, LPSPI5_NS, LPSPI6_NS, LPSPI7_NS, LPSPI8_NS }
#else
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x44360000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x44370000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x42550000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x42560000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x426F0000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE                              (0x42700000u)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE                              (0x42710000u)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE                              (0x42720000u)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn, LPSPI6_IRQn, LPSPI7_IRQn, LPSPI8_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x54300000u)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE_NS                           (0x44300000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1_NS                                ((LPTMR_Type *)LPTMR1_BASE_NS)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE                              (0x524D0000u)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE_NS                           (0x424D0000u)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2_NS                                ((LPTMR_Type *)LPTMR2_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE, LPTMR2_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1, LPTMR2 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { 0u, LPTMR1_BASE_NS, LPTMR2_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { (LPTMR_Type *)0u, LPTMR1_NS, LPTMR2_NS }
#else
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x44300000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE                              (0x424D0000u)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE, LPTMR2_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1, LPTMR2 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { NotAvail_IRQn, LPTMR1_IRQn, LPTMR2_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x54380000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x44380000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x54390000u)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE_NS                          (0x44390000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2_NS                               ((LPUART_Type *)LPUART2_BASE_NS)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x52570000u)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE_NS                          (0x42570000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3_NS                               ((LPUART_Type *)LPUART3_BASE_NS)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x52580000u)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE_NS                          (0x42580000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4_NS                               ((LPUART_Type *)LPUART4_BASE_NS)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x52590000u)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE_NS                          (0x42590000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5_NS                               ((LPUART_Type *)LPUART5_BASE_NS)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x525A0000u)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE_NS                          (0x425A0000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6_NS                               ((LPUART_Type *)LPUART6_BASE_NS)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x52690000u)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE_NS                          (0x42690000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7_NS                               ((LPUART_Type *)LPUART7_BASE_NS)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x526A0000u)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE_NS                          (0x426A0000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8_NS                               ((LPUART_Type *)LPUART8_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { 0u, LPUART1_BASE_NS, LPUART2_BASE_NS, LPUART3_BASE_NS, LPUART4_BASE_NS, LPUART5_BASE_NS, LPUART6_BASE_NS, LPUART7_BASE_NS, LPUART8_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { (LPUART_Type *)0u, LPUART1_NS, LPUART2_NS, LPUART3_NS, LPUART4_NS, LPUART5_NS, LPUART6_NS, LPUART7_NS, LPUART8_NS }
#else
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x44380000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x44390000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x42570000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x42580000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x42590000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x425A0000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x42690000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x426A0000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn }

/* MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PPB_MCM2_CM4 base address */
  #define PPB_MCM2_CM4_BASE                        (0xF0080000u)
  /** Peripheral PPB_MCM2_CM4 base address */
  #define PPB_MCM2_CM4_BASE_NS                     (0xE0080000u)
  /** Peripheral PPB_MCM2_CM4 base pointer */
  #define PPB_MCM2_CM4                             ((MCM_Type *)PPB_MCM2_CM4_BASE)
  /** Peripheral PPB_MCM2_CM4 base pointer */
  #define PPB_MCM2_CM4_NS                          ((MCM_Type *)PPB_MCM2_CM4_BASE_NS)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { PPB_MCM2_CM4_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { PPB_MCM2_CM4 }
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS_NS                        { PPB_MCM2_CM4_BASE_NS }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS_NS                         { PPB_MCM2_CM4_NS }
#else
  /** Peripheral PPB_MCM2_CM4 base address */
  #define PPB_MCM2_CM4_BASE                        (0xE0080000u)
  /** Peripheral PPB_MCM2_CM4 base pointer */
  #define PPB_MCM2_CM4                             ((MCM_Type *)PPB_MCM2_CM4_BASE)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { PPB_MCM2_CM4_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { PPB_MCM2_CM4 }
#endif

/* MEDIAMIX_BLK_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_MEDIAMIX base address */
  #define BLK_CTRL_MEDIAMIX_BASE                   (0x5AC10000u)
  /** Peripheral BLK_CTRL_MEDIAMIX base address */
  #define BLK_CTRL_MEDIAMIX_BASE_NS                (0x4AC10000u)
  /** Peripheral BLK_CTRL_MEDIAMIX base pointer */
  #define BLK_CTRL_MEDIAMIX                        ((MEDIAMIX_BLK_CTRL_Type *)BLK_CTRL_MEDIAMIX_BASE)
  /** Peripheral BLK_CTRL_MEDIAMIX base pointer */
  #define BLK_CTRL_MEDIAMIX_NS                     ((MEDIAMIX_BLK_CTRL_Type *)BLK_CTRL_MEDIAMIX_BASE_NS)
  /** Array initializer of MEDIAMIX_BLK_CTRL peripheral base addresses */
  #define MEDIAMIX_BLK_CTRL_BASE_ADDRS             { BLK_CTRL_MEDIAMIX_BASE }
  /** Array initializer of MEDIAMIX_BLK_CTRL peripheral base pointers */
  #define MEDIAMIX_BLK_CTRL_BASE_PTRS              { BLK_CTRL_MEDIAMIX }
  /** Array initializer of MEDIAMIX_BLK_CTRL peripheral base addresses */
  #define MEDIAMIX_BLK_CTRL_BASE_ADDRS_NS          { BLK_CTRL_MEDIAMIX_BASE_NS }
  /** Array initializer of MEDIAMIX_BLK_CTRL peripheral base pointers */
  #define MEDIAMIX_BLK_CTRL_BASE_PTRS_NS           { BLK_CTRL_MEDIAMIX_NS }
#else
  /** Peripheral BLK_CTRL_MEDIAMIX base address */
  #define BLK_CTRL_MEDIAMIX_BASE                   (0x4AC10000u)
  /** Peripheral BLK_CTRL_MEDIAMIX base pointer */
  #define BLK_CTRL_MEDIAMIX                        ((MEDIAMIX_BLK_CTRL_Type *)BLK_CTRL_MEDIAMIX_BASE)
  /** Array initializer of MEDIAMIX_BLK_CTRL peripheral base addresses */
  #define MEDIAMIX_BLK_CTRL_BASE_ADDRS             { BLK_CTRL_MEDIAMIX_BASE }
  /** Array initializer of MEDIAMIX_BLK_CTRL peripheral base pointers */
  #define MEDIAMIX_BLK_CTRL_BASE_PTRS              { BLK_CTRL_MEDIAMIX }
#endif

/* MIPI_CSI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MIPI_CSI_CSR base address */
  #define MIPI_CSI_CSR_BASE                        (0x5AE00000u)
  /** Peripheral MIPI_CSI_CSR base address */
  #define MIPI_CSI_CSR_BASE_NS                     (0x4AE00000u)
  /** Peripheral MIPI_CSI_CSR base pointer */
  #define MIPI_CSI_CSR                             ((MIPI_CSI_Type *)MIPI_CSI_CSR_BASE)
  /** Peripheral MIPI_CSI_CSR base pointer */
  #define MIPI_CSI_CSR_NS                          ((MIPI_CSI_Type *)MIPI_CSI_CSR_BASE_NS)
  /** Array initializer of MIPI_CSI peripheral base addresses */
  #define MIPI_CSI_BASE_ADDRS                      { MIPI_CSI_CSR_BASE }
  /** Array initializer of MIPI_CSI peripheral base pointers */
  #define MIPI_CSI_BASE_PTRS                       { MIPI_CSI_CSR }
  /** Array initializer of MIPI_CSI peripheral base addresses */
  #define MIPI_CSI_BASE_ADDRS_NS                   { MIPI_CSI_CSR_BASE_NS }
  /** Array initializer of MIPI_CSI peripheral base pointers */
  #define MIPI_CSI_BASE_PTRS_NS                    { MIPI_CSI_CSR_NS }
#else
  /** Peripheral MIPI_CSI_CSR base address */
  #define MIPI_CSI_CSR_BASE                        (0x4AE00000u)
  /** Peripheral MIPI_CSI_CSR base pointer */
  #define MIPI_CSI_CSR                             ((MIPI_CSI_Type *)MIPI_CSI_CSR_BASE)
  /** Array initializer of MIPI_CSI peripheral base addresses */
  #define MIPI_CSI_BASE_ADDRS                      { MIPI_CSI_CSR_BASE }
  /** Array initializer of MIPI_CSI peripheral base pointers */
  #define MIPI_CSI_BASE_PTRS                       { MIPI_CSI_CSR }
#endif

/* MIPI_DSI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MIPI_DSI base address */
  #define MIPI_DSI_BASE                            (0x5AE10000u)
  /** Peripheral MIPI_DSI base address */
  #define MIPI_DSI_BASE_NS                         (0x4AE10000u)
  /** Peripheral MIPI_DSI base pointer */
  #define MIPI_DSI                                 ((MIPI_DSI_Type *)MIPI_DSI_BASE)
  /** Peripheral MIPI_DSI base pointer */
  #define MIPI_DSI_NS                              ((MIPI_DSI_Type *)MIPI_DSI_BASE_NS)
  /** Array initializer of MIPI_DSI peripheral base addresses */
  #define MIPI_DSI_BASE_ADDRS                      { MIPI_DSI_BASE }
  /** Array initializer of MIPI_DSI peripheral base pointers */
  #define MIPI_DSI_BASE_PTRS                       { MIPI_DSI }
  /** Array initializer of MIPI_DSI peripheral base addresses */
  #define MIPI_DSI_BASE_ADDRS_NS                   { MIPI_DSI_BASE_NS }
  /** Array initializer of MIPI_DSI peripheral base pointers */
  #define MIPI_DSI_BASE_PTRS_NS                    { MIPI_DSI_NS }
#else
  /** Peripheral MIPI_DSI base address */
  #define MIPI_DSI_BASE                            (0x4AE10000u)
  /** Peripheral MIPI_DSI base pointer */
  #define MIPI_DSI                                 ((MIPI_DSI_Type *)MIPI_DSI_BASE)
  /** Array initializer of MIPI_DSI peripheral base addresses */
  #define MIPI_DSI_BASE_ADDRS                      { MIPI_DSI_BASE }
  /** Array initializer of MIPI_DSI peripheral base pointers */
  #define MIPI_DSI_BASE_PTRS                       { MIPI_DSI }
#endif

/* MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x54220000u)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE_NS                          (0x44220000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA_NS                               ((MU_Type *)MU1_MUA_BASE_NS)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x52430000u)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE_NS                          (0x42430000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA_NS                               ((MU_Type *)MU2_MUA_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU2_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUA, MU2_MUA }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU1_MUA_BASE_NS, MU2_MUA_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU1_MUA_NS, MU2_MUA_NS }
#else
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x44220000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x42430000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU2_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUA, MU2_MUA }
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_A_IRQn, MU2_A_IRQn }

/* NPU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NPU base address */
  #define NPU_BASE                                 (0x5A900000u)
  /** Peripheral NPU base address */
  #define NPU_BASE_NS                              (0x4A900000u)
  /** Peripheral NPU base pointer */
  #define NPU                                      ((NPU_Type *)NPU_BASE)
  /** Peripheral NPU base pointer */
  #define NPU_NS                                   ((NPU_Type *)NPU_BASE_NS)
  /** Array initializer of NPU peripheral base addresses */
  #define NPU_BASE_ADDRS                           { NPU_BASE }
  /** Array initializer of NPU peripheral base pointers */
  #define NPU_BASE_PTRS                            { NPU }
  /** Array initializer of NPU peripheral base addresses */
  #define NPU_BASE_ADDRS_NS                        { NPU_BASE_NS }
  /** Array initializer of NPU peripheral base pointers */
  #define NPU_BASE_PTRS_NS                         { NPU_NS }
#else
  /** Peripheral NPU base address */
  #define NPU_BASE                                 (0x4A900000u)
  /** Peripheral NPU base pointer */
  #define NPU                                      ((NPU_Type *)NPU_BASE)
  /** Array initializer of NPU peripheral base addresses */
  #define NPU_BASE_ADDRS                           { NPU_BASE }
  /** Array initializer of NPU peripheral base pointers */
  #define NPU_BASE_PTRS                            { NPU }
#endif

/* OCRAM_MECC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OCRAM_MECC1 base address */
  #define OCRAM_MECC1_BASE                         (0x590A0000u)
  /** Peripheral OCRAM_MECC1 base address */
  #define OCRAM_MECC1_BASE_NS                      (0x490A0000u)
  /** Peripheral OCRAM_MECC1 base pointer */
  #define OCRAM_MECC1                              ((OCRAM_MECC_Type *)OCRAM_MECC1_BASE)
  /** Peripheral OCRAM_MECC1 base pointer */
  #define OCRAM_MECC1_NS                           ((OCRAM_MECC_Type *)OCRAM_MECC1_BASE_NS)
  /** Array initializer of OCRAM_MECC peripheral base addresses */
  #define OCRAM_MECC_BASE_ADDRS                    { OCRAM_MECC1_BASE }
  /** Array initializer of OCRAM_MECC peripheral base pointers */
  #define OCRAM_MECC_BASE_PTRS                     { OCRAM_MECC1 }
  /** Array initializer of OCRAM_MECC peripheral base addresses */
  #define OCRAM_MECC_BASE_ADDRS_NS                 { OCRAM_MECC1_BASE_NS }
  /** Array initializer of OCRAM_MECC peripheral base pointers */
  #define OCRAM_MECC_BASE_PTRS_NS                  { OCRAM_MECC1_NS }
#else
  /** Peripheral OCRAM_MECC1 base address */
  #define OCRAM_MECC1_BASE                         (0x490A0000u)
  /** Peripheral OCRAM_MECC1 base pointer */
  #define OCRAM_MECC1                              ((OCRAM_MECC_Type *)OCRAM_MECC1_BASE)
  /** Array initializer of OCRAM_MECC peripheral base addresses */
  #define OCRAM_MECC_BASE_ADDRS                    { OCRAM_MECC1_BASE }
  /** Array initializer of OCRAM_MECC peripheral base pointers */
  #define OCRAM_MECC_BASE_PTRS                     { OCRAM_MECC1 }
#endif

/* OTFAD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI_OTFAD1 base address */
  #define FLEXSPI_OTFAD1_BASE                      (0x525E0000u)
  /** Peripheral FLEXSPI_OTFAD1 base address */
  #define FLEXSPI_OTFAD1_BASE_NS                   (0x425E0000u)
  /** Peripheral FLEXSPI_OTFAD1 base pointer */
  #define FLEXSPI_OTFAD1                           ((OTFAD_Type *)FLEXSPI_OTFAD1_BASE)
  /** Peripheral FLEXSPI_OTFAD1 base pointer */
  #define FLEXSPI_OTFAD1_NS                        ((OTFAD_Type *)FLEXSPI_OTFAD1_BASE_NS)
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS                         { FLEXSPI_OTFAD1_BASE }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS                          { FLEXSPI_OTFAD1 }
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS_NS                      { FLEXSPI_OTFAD1_BASE_NS }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS_NS                       { FLEXSPI_OTFAD1_NS }
#else
  /** Peripheral FLEXSPI_OTFAD1 base address */
  #define FLEXSPI_OTFAD1_BASE                      (0x425E0000u)
  /** Peripheral FLEXSPI_OTFAD1 base pointer */
  #define FLEXSPI_OTFAD1                           ((OTFAD_Type *)FLEXSPI_OTFAD1_BASE)
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS                         { FLEXSPI_OTFAD1_BASE }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS                          { FLEXSPI_OTFAD1 }
#endif

/* PDM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x54520000u)
  /** Peripheral PDM base address */
  #define PDM_BASE_NS                              (0x44520000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Peripheral PDM base pointer */
  #define PDM_NS                                   ((PDM_Type *)PDM_BASE_NS)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS_NS                        { PDM_BASE_NS }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS_NS                         { PDM_NS }
#else
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x44520000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
#endif

/* PLL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ARMPLL base address */
  #define ARMPLL_BASE                              (0x54481000u)
  /** Peripheral ARMPLL base address */
  #define ARMPLL_BASE_NS                           (0x44481000u)
  /** Peripheral ARMPLL base pointer */
  #define ARMPLL                                   ((PLL_Type *)ARMPLL_BASE)
  /** Peripheral ARMPLL base pointer */
  #define ARMPLL_NS                                ((PLL_Type *)ARMPLL_BASE_NS)
  /** Peripheral AUDIOPLL base address */
  #define AUDIOPLL_BASE                            (0x54481200u)
  /** Peripheral AUDIOPLL base address */
  #define AUDIOPLL_BASE_NS                         (0x44481200u)
  /** Peripheral AUDIOPLL base pointer */
  #define AUDIOPLL                                 ((PLL_Type *)AUDIOPLL_BASE)
  /** Peripheral AUDIOPLL base pointer */
  #define AUDIOPLL_NS                              ((PLL_Type *)AUDIOPLL_BASE_NS)
  /** Peripheral DRAMPLL base address */
  #define DRAMPLL_BASE                             (0x54481300u)
  /** Peripheral DRAMPLL base address */
  #define DRAMPLL_BASE_NS                          (0x44481300u)
  /** Peripheral DRAMPLL base pointer */
  #define DRAMPLL                                  ((PLL_Type *)DRAMPLL_BASE)
  /** Peripheral DRAMPLL base pointer */
  #define DRAMPLL_NS                               ((PLL_Type *)DRAMPLL_BASE_NS)
  /** Peripheral SYSPLL base address */
  #define SYSPLL_BASE                              (0x54481100u)
  /** Peripheral SYSPLL base address */
  #define SYSPLL_BASE_NS                           (0x44481100u)
  /** Peripheral SYSPLL base pointer */
  #define SYSPLL                                   ((PLL_Type *)SYSPLL_BASE)
  /** Peripheral SYSPLL base pointer */
  #define SYSPLL_NS                                ((PLL_Type *)SYSPLL_BASE_NS)
  /** Peripheral VIDEOPLL base address */
  #define VIDEOPLL_BASE                            (0x54481400u)
  /** Peripheral VIDEOPLL base address */
  #define VIDEOPLL_BASE_NS                         (0x44481400u)
  /** Peripheral VIDEOPLL base pointer */
  #define VIDEOPLL                                 ((PLL_Type *)VIDEOPLL_BASE)
  /** Peripheral VIDEOPLL base pointer */
  #define VIDEOPLL_NS                              ((PLL_Type *)VIDEOPLL_BASE_NS)
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS                           { ARMPLL_BASE, AUDIOPLL_BASE, DRAMPLL_BASE, SYSPLL_BASE, VIDEOPLL_BASE }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS                            { ARMPLL, AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL }
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS_NS                        { ARMPLL_BASE_NS, AUDIOPLL_BASE_NS, DRAMPLL_BASE_NS, SYSPLL_BASE_NS, VIDEOPLL_BASE_NS }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS_NS                         { ARMPLL_NS, AUDIOPLL_NS, DRAMPLL_NS, SYSPLL_NS, VIDEOPLL_NS }
#else
  /** Peripheral ARMPLL base address */
  #define ARMPLL_BASE                              (0x44481000u)
  /** Peripheral ARMPLL base pointer */
  #define ARMPLL                                   ((PLL_Type *)ARMPLL_BASE)
  /** Peripheral AUDIOPLL base address */
  #define AUDIOPLL_BASE                            (0x44481200u)
  /** Peripheral AUDIOPLL base pointer */
  #define AUDIOPLL                                 ((PLL_Type *)AUDIOPLL_BASE)
  /** Peripheral DRAMPLL base address */
  #define DRAMPLL_BASE                             (0x44481300u)
  /** Peripheral DRAMPLL base pointer */
  #define DRAMPLL                                  ((PLL_Type *)DRAMPLL_BASE)
  /** Peripheral SYSPLL base address */
  #define SYSPLL_BASE                              (0x44481100u)
  /** Peripheral SYSPLL base pointer */
  #define SYSPLL                                   ((PLL_Type *)SYSPLL_BASE)
  /** Peripheral VIDEOPLL base address */
  #define VIDEOPLL_BASE                            (0x44481400u)
  /** Peripheral VIDEOPLL base pointer */
  #define VIDEOPLL                                 ((PLL_Type *)VIDEOPLL_BASE)
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS                           { ARMPLL_BASE, AUDIOPLL_BASE, DRAMPLL_BASE, SYSPLL_BASE, VIDEOPLL_BASE }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS                            { ARMPLL, AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL }
#endif

/* PXP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PXP base address */
  #define PXP_BASE                                 (0x5AE20000u)
  /** Peripheral PXP base address */
  #define PXP_BASE_NS                              (0x4AE20000u)
  /** Peripheral PXP base pointer */
  #define PXP                                      ((PXP_Type *)PXP_BASE)
  /** Peripheral PXP base pointer */
  #define PXP_NS                                   ((PXP_Type *)PXP_BASE_NS)
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS                           { PXP_BASE }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS                            { PXP }
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS_NS                        { PXP_BASE_NS }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS_NS                         { PXP_NS }
#else
  /** Peripheral PXP base address */
  #define PXP_BASE                                 (0x4AE20000u)
  /** Peripheral PXP base pointer */
  #define PXP                                      ((PXP_Type *)PXP_BASE)
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS                           { PXP_BASE }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS                            { PXP }
#endif

/* RGPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x57400000u)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE_NS                            (0x47400000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((RGPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1_NS                                 ((RGPIO_Type *)GPIO1_BASE_NS)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x53810000u)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE_NS                            (0x43810000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((RGPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2_NS                                 ((RGPIO_Type *)GPIO2_BASE_NS)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x53820000u)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE_NS                            (0x43820000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((RGPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3_NS                                 ((RGPIO_Type *)GPIO3_BASE_NS)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x53830000u)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE_NS                            (0x43830000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((RGPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4_NS                                 ((RGPIO_Type *)GPIO4_BASE_NS)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { GPIO1, GPIO2, GPIO3, GPIO4 }
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS_NS                      { GPIO1_BASE_NS, GPIO2_BASE_NS, GPIO3_BASE_NS, GPIO4_BASE_NS }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS_NS                       { GPIO1_NS, GPIO2_NS, GPIO3_NS, GPIO4_NS }
#else
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x47400000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((RGPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x43810000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((RGPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x43820000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((RGPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x43830000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((RGPIO_Type *)GPIO4_BASE)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { GPIO1, GPIO2, GPIO3, GPIO4 }
#endif
/** Interrupt vectors for the RGPIO peripheral type */
#define RGPIO_IRQS                               { GPIO1_0_IRQn, GPIO2_0_IRQn, GPIO3_0_IRQn, GPIO4_0_IRQn }

/* S3MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU_APPS__S3MUA base address */
  #define MU_APPS__S3MUA_BASE                      (0x57520000u)
  /** Peripheral MU_APPS__S3MUA base address */
  #define MU_APPS__S3MUA_BASE_NS                   (0x47520000u)
  /** Peripheral MU_APPS__S3MUA base pointer */
  #define MU_APPS__S3MUA                           ((S3MU_Type *)MU_APPS__S3MUA_BASE)
  /** Peripheral MU_APPS__S3MUA base pointer */
  #define MU_APPS__S3MUA_NS                        ((S3MU_Type *)MU_APPS__S3MUA_BASE_NS)
  /** Peripheral MU_RT__S3MUA base address */
  #define MU_RT__S3MUA_BASE                        (0x57540000u)
  /** Peripheral MU_RT__S3MUA base address */
  #define MU_RT__S3MUA_BASE_NS                     (0x47540000u)
  /** Peripheral MU_RT__S3MUA base pointer */
  #define MU_RT__S3MUA                             ((S3MU_Type *)MU_RT__S3MUA_BASE)
  /** Peripheral MU_RT__S3MUA base pointer */
  #define MU_RT__S3MUA_NS                          ((S3MU_Type *)MU_RT__S3MUA_BASE_NS)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { MU_APPS__S3MUA_BASE, MU_RT__S3MUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { MU_APPS__S3MUA, MU_RT__S3MUA }
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS_NS                       { MU_APPS__S3MUA_BASE_NS, MU_RT__S3MUA_BASE_NS }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS_NS                        { MU_APPS__S3MUA_NS, MU_RT__S3MUA_NS }
#else
  /** Peripheral MU_APPS__S3MUA base address */
  #define MU_APPS__S3MUA_BASE                      (0x47520000u)
  /** Peripheral MU_APPS__S3MUA base pointer */
  #define MU_APPS__S3MUA                           ((S3MU_Type *)MU_APPS__S3MUA_BASE)
  /** Peripheral MU_RT__S3MUA base address */
  #define MU_RT__S3MUA_BASE                        (0x47540000u)
  /** Peripheral MU_RT__S3MUA base pointer */
  #define MU_RT__S3MUA                             ((S3MU_Type *)MU_RT__S3MUA_BASE)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { MU_APPS__S3MUA_BASE, MU_RT__S3MUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { MU_APPS__S3MUA, MU_RT__S3MUA }
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE                            (0x54260000u)
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE_NS                         (0x44260000u)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1_NS                              ((SEMA42_Type *)SEMA42_1_BASE_NS)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE                            (0x52450000u)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE_NS                         (0x42450000u)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2_NS                              ((SEMA42_Type *)SEMA42_2_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { 0u, SEMA42_1_BASE, SEMA42_2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { (SEMA42_Type *)0u, SEMA42_1, SEMA42_2 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { 0u, SEMA42_1_BASE_NS, SEMA42_2_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { (SEMA42_Type *)0u, SEMA42_1_NS, SEMA42_2_NS }
#else
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE                            (0x44260000u)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE                            (0x42450000u)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { 0u, SEMA42_1_BASE, SEMA42_2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { (SEMA42_Type *)0u, SEMA42_1, SEMA42_2 }
#endif

/* SPDIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE                               (0x52680000u)
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE_NS                            (0x42680000u)
  /** Peripheral SPDIF base pointer */
  #define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
  /** Peripheral SPDIF base pointer */
  #define SPDIF_NS                                 ((SPDIF_Type *)SPDIF_BASE_NS)
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS                          { SPDIF }
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS_NS                      { SPDIF_BASE_NS }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS_NS                       { SPDIF_NS }
#else
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE                               (0x42680000u)
  /** Peripheral SPDIF base pointer */
  #define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS                          { SPDIF }
#endif

/* SRC_GENERAL_REG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_GENERAL_REG base address */
  #define SRC_GENERAL_REG_BASE                     (0x54460000u)
  /** Peripheral SRC_GENERAL_REG base address */
  #define SRC_GENERAL_REG_BASE_NS                  (0x44460000u)
  /** Peripheral SRC_GENERAL_REG base pointer */
  #define SRC_GENERAL_REG                          ((SRC_GENERAL_REG_Type *)SRC_GENERAL_REG_BASE)
  /** Peripheral SRC_GENERAL_REG base pointer */
  #define SRC_GENERAL_REG_NS                       ((SRC_GENERAL_REG_Type *)SRC_GENERAL_REG_BASE_NS)
  /** Array initializer of SRC_GENERAL_REG peripheral base addresses */
  #define SRC_GENERAL_REG_BASE_ADDRS               { SRC_GENERAL_REG_BASE }
  /** Array initializer of SRC_GENERAL_REG peripheral base pointers */
  #define SRC_GENERAL_REG_BASE_PTRS                { SRC_GENERAL_REG }
  /** Array initializer of SRC_GENERAL_REG peripheral base addresses */
  #define SRC_GENERAL_REG_BASE_ADDRS_NS            { SRC_GENERAL_REG_BASE_NS }
  /** Array initializer of SRC_GENERAL_REG peripheral base pointers */
  #define SRC_GENERAL_REG_BASE_PTRS_NS             { SRC_GENERAL_REG_NS }
#else
  /** Peripheral SRC_GENERAL_REG base address */
  #define SRC_GENERAL_REG_BASE                     (0x44460000u)
  /** Peripheral SRC_GENERAL_REG base pointer */
  #define SRC_GENERAL_REG                          ((SRC_GENERAL_REG_Type *)SRC_GENERAL_REG_BASE)
  /** Array initializer of SRC_GENERAL_REG peripheral base addresses */
  #define SRC_GENERAL_REG_BASE_ADDRS               { SRC_GENERAL_REG_BASE }
  /** Array initializer of SRC_GENERAL_REG peripheral base pointers */
  #define SRC_GENERAL_REG_BASE_PTRS                { SRC_GENERAL_REG }
#endif

/* SRC_MEM_SLICE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_AON_MEM base address */
  #define SRC_AON_MEM_BASE                         (0x54463800u)
  /** Peripheral SRC_AON_MEM base address */
  #define SRC_AON_MEM_BASE_NS                      (0x44463800u)
  /** Peripheral SRC_AON_MEM base pointer */
  #define SRC_AON_MEM                              ((SRC_MEM_SLICE_Type *)SRC_AON_MEM_BASE)
  /** Peripheral SRC_AON_MEM base pointer */
  #define SRC_AON_MEM_NS                           ((SRC_MEM_SLICE_Type *)SRC_AON_MEM_BASE_NS)
  /** Peripheral SRC_WKUP_MEM base address */
  #define SRC_WKUP_MEM_BASE                        (0x54463C00u)
  /** Peripheral SRC_WKUP_MEM base address */
  #define SRC_WKUP_MEM_BASE_NS                     (0x44463C00u)
  /** Peripheral SRC_WKUP_MEM base pointer */
  #define SRC_WKUP_MEM                             ((SRC_MEM_SLICE_Type *)SRC_WKUP_MEM_BASE)
  /** Peripheral SRC_WKUP_MEM base pointer */
  #define SRC_WKUP_MEM_NS                          ((SRC_MEM_SLICE_Type *)SRC_WKUP_MEM_BASE_NS)
  /** Peripheral SRC_DDR_MEM base address */
  #define SRC_DDR_MEM_BASE                         (0x54464000u)
  /** Peripheral SRC_DDR_MEM base address */
  #define SRC_DDR_MEM_BASE_NS                      (0x44464000u)
  /** Peripheral SRC_DDR_MEM base pointer */
  #define SRC_DDR_MEM                              ((SRC_MEM_SLICE_Type *)SRC_DDR_MEM_BASE)
  /** Peripheral SRC_DDR_MEM base pointer */
  #define SRC_DDR_MEM_NS                           ((SRC_MEM_SLICE_Type *)SRC_DDR_MEM_BASE_NS)
  /** Peripheral SRC_DPHY_MEM base address */
  #define SRC_DPHY_MEM_BASE                        (0x54464400u)
  /** Peripheral SRC_DPHY_MEM base address */
  #define SRC_DPHY_MEM_BASE_NS                     (0x44464400u)
  /** Peripheral SRC_DPHY_MEM base pointer */
  #define SRC_DPHY_MEM                             ((SRC_MEM_SLICE_Type *)SRC_DPHY_MEM_BASE)
  /** Peripheral SRC_DPHY_MEM base pointer */
  #define SRC_DPHY_MEM_NS                          ((SRC_MEM_SLICE_Type *)SRC_DPHY_MEM_BASE_NS)
  /** Peripheral SRC_ML_MEM base address */
  #define SRC_ML_MEM_BASE                          (0x54464800u)
  /** Peripheral SRC_ML_MEM base address */
  #define SRC_ML_MEM_BASE_NS                       (0x44464800u)
  /** Peripheral SRC_ML_MEM base pointer */
  #define SRC_ML_MEM                               ((SRC_MEM_SLICE_Type *)SRC_ML_MEM_BASE)
  /** Peripheral SRC_ML_MEM base pointer */
  #define SRC_ML_MEM_NS                            ((SRC_MEM_SLICE_Type *)SRC_ML_MEM_BASE_NS)
  /** Peripheral SRC_NIC_MEM base address */
  #define SRC_NIC_MEM_BASE                         (0x54464C00u)
  /** Peripheral SRC_NIC_MEM base address */
  #define SRC_NIC_MEM_BASE_NS                      (0x44464C00u)
  /** Peripheral SRC_NIC_MEM base pointer */
  #define SRC_NIC_MEM                              ((SRC_MEM_SLICE_Type *)SRC_NIC_MEM_BASE)
  /** Peripheral SRC_NIC_MEM base pointer */
  #define SRC_NIC_MEM_NS                           ((SRC_MEM_SLICE_Type *)SRC_NIC_MEM_BASE_NS)
  /** Peripheral SRC_NIC_OCRAM base address */
  #define SRC_NIC_OCRAM_BASE                       (0x54465000u)
  /** Peripheral SRC_NIC_OCRAM base address */
  #define SRC_NIC_OCRAM_BASE_NS                    (0x44465000u)
  /** Peripheral SRC_NIC_OCRAM base pointer */
  #define SRC_NIC_OCRAM                            ((SRC_MEM_SLICE_Type *)SRC_NIC_OCRAM_BASE)
  /** Peripheral SRC_NIC_OCRAM base pointer */
  #define SRC_NIC_OCRAM_NS                         ((SRC_MEM_SLICE_Type *)SRC_NIC_OCRAM_BASE_NS)
  /** Peripheral SRC_HSIO_MEM base address */
  #define SRC_HSIO_MEM_BASE                        (0x54465400u)
  /** Peripheral SRC_HSIO_MEM base address */
  #define SRC_HSIO_MEM_BASE_NS                     (0x44465400u)
  /** Peripheral SRC_HSIO_MEM base pointer */
  #define SRC_HSIO_MEM                             ((SRC_MEM_SLICE_Type *)SRC_HSIO_MEM_BASE)
  /** Peripheral SRC_HSIO_MEM base pointer */
  #define SRC_HSIO_MEM_NS                          ((SRC_MEM_SLICE_Type *)SRC_HSIO_MEM_BASE_NS)
  /** Peripheral SRC_MEDIA_MEM base address */
  #define SRC_MEDIA_MEM_BASE                       (0x54465800u)
  /** Peripheral SRC_MEDIA_MEM base address */
  #define SRC_MEDIA_MEM_BASE_NS                    (0x44465800u)
  /** Peripheral SRC_MEDIA_MEM base pointer */
  #define SRC_MEDIA_MEM                            ((SRC_MEM_SLICE_Type *)SRC_MEDIA_MEM_BASE)
  /** Peripheral SRC_MEDIA_MEM base pointer */
  #define SRC_MEDIA_MEM_NS                         ((SRC_MEM_SLICE_Type *)SRC_MEDIA_MEM_BASE_NS)
  /** Peripheral SRC_A55C0_MEM base address */
  #define SRC_A55C0_MEM_BASE                       (0x54465C00u)
  /** Peripheral SRC_A55C0_MEM base address */
  #define SRC_A55C0_MEM_BASE_NS                    (0x44465C00u)
  /** Peripheral SRC_A55C0_MEM base pointer */
  #define SRC_A55C0_MEM                            ((SRC_MEM_SLICE_Type *)SRC_A55C0_MEM_BASE)
  /** Peripheral SRC_A55C0_MEM base pointer */
  #define SRC_A55C0_MEM_NS                         ((SRC_MEM_SLICE_Type *)SRC_A55C0_MEM_BASE_NS)
  /** Peripheral SRC_A55C1_MEM base address */
  #define SRC_A55C1_MEM_BASE                       (0x54466000u)
  /** Peripheral SRC_A55C1_MEM base address */
  #define SRC_A55C1_MEM_BASE_NS                    (0x44466000u)
  /** Peripheral SRC_A55C1_MEM base pointer */
  #define SRC_A55C1_MEM                            ((SRC_MEM_SLICE_Type *)SRC_A55C1_MEM_BASE)
  /** Peripheral SRC_A55C1_MEM base pointer */
  #define SRC_A55C1_MEM_NS                         ((SRC_MEM_SLICE_Type *)SRC_A55C1_MEM_BASE_NS)
  /** Peripheral SRC_A55_SCU_MEM base address */
  #define SRC_A55_SCU_MEM_BASE                     (0x54466400u)
  /** Peripheral SRC_A55_SCU_MEM base address */
  #define SRC_A55_SCU_MEM_BASE_NS                  (0x44466400u)
  /** Peripheral SRC_A55_SCU_MEM base pointer */
  #define SRC_A55_SCU_MEM                          ((SRC_MEM_SLICE_Type *)SRC_A55_SCU_MEM_BASE)
  /** Peripheral SRC_A55_SCU_MEM base pointer */
  #define SRC_A55_SCU_MEM_NS                       ((SRC_MEM_SLICE_Type *)SRC_A55_SCU_MEM_BASE_NS)
  /** Peripheral SRC_A55_L3_MEM base address */
  #define SRC_A55_L3_MEM_BASE                      (0x54466800u)
  /** Peripheral SRC_A55_L3_MEM base address */
  #define SRC_A55_L3_MEM_BASE_NS                   (0x44466800u)
  /** Peripheral SRC_A55_L3_MEM base pointer */
  #define SRC_A55_L3_MEM                           ((SRC_MEM_SLICE_Type *)SRC_A55_L3_MEM_BASE)
  /** Peripheral SRC_A55_L3_MEM base pointer */
  #define SRC_A55_L3_MEM_NS                        ((SRC_MEM_SLICE_Type *)SRC_A55_L3_MEM_BASE_NS)
  /** Array initializer of SRC_MEM_SLICE peripheral base addresses */
  #define SRC_MEM_SLICE_BASE_ADDRS                 { SRC_AON_MEM_BASE, SRC_WKUP_MEM_BASE, SRC_DDR_MEM_BASE, SRC_DPHY_MEM_BASE, SRC_ML_MEM_BASE, SRC_NIC_MEM_BASE, SRC_NIC_OCRAM_BASE, SRC_HSIO_MEM_BASE, SRC_MEDIA_MEM_BASE, SRC_A55C0_MEM_BASE, SRC_A55C1_MEM_BASE, SRC_A55_SCU_MEM_BASE, SRC_A55_L3_MEM_BASE }
  /** Array initializer of SRC_MEM_SLICE peripheral base pointers */
  #define SRC_MEM_SLICE_BASE_PTRS                  { SRC_AON_MEM, SRC_WKUP_MEM, SRC_DDR_MEM, SRC_DPHY_MEM, SRC_ML_MEM, SRC_NIC_MEM, SRC_NIC_OCRAM, SRC_HSIO_MEM, SRC_MEDIA_MEM, SRC_A55C0_MEM, SRC_A55C1_MEM, SRC_A55_SCU_MEM, SRC_A55_L3_MEM }
  /** Array initializer of SRC_MEM_SLICE peripheral base addresses */
  #define SRC_MEM_SLICE_BASE_ADDRS_NS              { SRC_AON_MEM_BASE_NS, SRC_WKUP_MEM_BASE_NS, SRC_DDR_MEM_BASE_NS, SRC_DPHY_MEM_BASE_NS, SRC_ML_MEM_BASE_NS, SRC_NIC_MEM_BASE_NS, SRC_NIC_OCRAM_BASE_NS, SRC_HSIO_MEM_BASE_NS, SRC_MEDIA_MEM_BASE_NS, SRC_A55C0_MEM_BASE_NS, SRC_A55C1_MEM_BASE_NS, SRC_A55_SCU_MEM_BASE_NS, SRC_A55_L3_MEM_BASE_NS }
  /** Array initializer of SRC_MEM_SLICE peripheral base pointers */
  #define SRC_MEM_SLICE_BASE_PTRS_NS               { SRC_AON_MEM_NS, SRC_WKUP_MEM_NS, SRC_DDR_MEM_NS, SRC_DPHY_MEM_NS, SRC_ML_MEM_NS, SRC_NIC_MEM_NS, SRC_NIC_OCRAM_NS, SRC_HSIO_MEM_NS, SRC_MEDIA_MEM_NS, SRC_A55C0_MEM_NS, SRC_A55C1_MEM_NS, SRC_A55_SCU_MEM_NS, SRC_A55_L3_MEM_NS }
#else
  /** Peripheral SRC_AON_MEM base address */
  #define SRC_AON_MEM_BASE                         (0x44463800u)
  /** Peripheral SRC_AON_MEM base pointer */
  #define SRC_AON_MEM                              ((SRC_MEM_SLICE_Type *)SRC_AON_MEM_BASE)
  /** Peripheral SRC_WKUP_MEM base address */
  #define SRC_WKUP_MEM_BASE                        (0x44463C00u)
  /** Peripheral SRC_WKUP_MEM base pointer */
  #define SRC_WKUP_MEM                             ((SRC_MEM_SLICE_Type *)SRC_WKUP_MEM_BASE)
  /** Peripheral SRC_DDR_MEM base address */
  #define SRC_DDR_MEM_BASE                         (0x44464000u)
  /** Peripheral SRC_DDR_MEM base pointer */
  #define SRC_DDR_MEM                              ((SRC_MEM_SLICE_Type *)SRC_DDR_MEM_BASE)
  /** Peripheral SRC_DPHY_MEM base address */
  #define SRC_DPHY_MEM_BASE                        (0x44464400u)
  /** Peripheral SRC_DPHY_MEM base pointer */
  #define SRC_DPHY_MEM                             ((SRC_MEM_SLICE_Type *)SRC_DPHY_MEM_BASE)
  /** Peripheral SRC_ML_MEM base address */
  #define SRC_ML_MEM_BASE                          (0x44464800u)
  /** Peripheral SRC_ML_MEM base pointer */
  #define SRC_ML_MEM                               ((SRC_MEM_SLICE_Type *)SRC_ML_MEM_BASE)
  /** Peripheral SRC_NIC_MEM base address */
  #define SRC_NIC_MEM_BASE                         (0x44464C00u)
  /** Peripheral SRC_NIC_MEM base pointer */
  #define SRC_NIC_MEM                              ((SRC_MEM_SLICE_Type *)SRC_NIC_MEM_BASE)
  /** Peripheral SRC_NIC_OCRAM base address */
  #define SRC_NIC_OCRAM_BASE                       (0x44465000u)
  /** Peripheral SRC_NIC_OCRAM base pointer */
  #define SRC_NIC_OCRAM                            ((SRC_MEM_SLICE_Type *)SRC_NIC_OCRAM_BASE)
  /** Peripheral SRC_HSIO_MEM base address */
  #define SRC_HSIO_MEM_BASE                        (0x44465400u)
  /** Peripheral SRC_HSIO_MEM base pointer */
  #define SRC_HSIO_MEM                             ((SRC_MEM_SLICE_Type *)SRC_HSIO_MEM_BASE)
  /** Peripheral SRC_MEDIA_MEM base address */
  #define SRC_MEDIA_MEM_BASE                       (0x44465800u)
  /** Peripheral SRC_MEDIA_MEM base pointer */
  #define SRC_MEDIA_MEM                            ((SRC_MEM_SLICE_Type *)SRC_MEDIA_MEM_BASE)
  /** Peripheral SRC_A55C0_MEM base address */
  #define SRC_A55C0_MEM_BASE                       (0x44465C00u)
  /** Peripheral SRC_A55C0_MEM base pointer */
  #define SRC_A55C0_MEM                            ((SRC_MEM_SLICE_Type *)SRC_A55C0_MEM_BASE)
  /** Peripheral SRC_A55C1_MEM base address */
  #define SRC_A55C1_MEM_BASE                       (0x44466000u)
  /** Peripheral SRC_A55C1_MEM base pointer */
  #define SRC_A55C1_MEM                            ((SRC_MEM_SLICE_Type *)SRC_A55C1_MEM_BASE)
  /** Peripheral SRC_A55_SCU_MEM base address */
  #define SRC_A55_SCU_MEM_BASE                     (0x44466400u)
  /** Peripheral SRC_A55_SCU_MEM base pointer */
  #define SRC_A55_SCU_MEM                          ((SRC_MEM_SLICE_Type *)SRC_A55_SCU_MEM_BASE)
  /** Peripheral SRC_A55_L3_MEM base address */
  #define SRC_A55_L3_MEM_BASE                      (0x44466800u)
  /** Peripheral SRC_A55_L3_MEM base pointer */
  #define SRC_A55_L3_MEM                           ((SRC_MEM_SLICE_Type *)SRC_A55_L3_MEM_BASE)
  /** Array initializer of SRC_MEM_SLICE peripheral base addresses */
  #define SRC_MEM_SLICE_BASE_ADDRS                 { SRC_AON_MEM_BASE, SRC_WKUP_MEM_BASE, SRC_DDR_MEM_BASE, SRC_DPHY_MEM_BASE, SRC_ML_MEM_BASE, SRC_NIC_MEM_BASE, SRC_NIC_OCRAM_BASE, SRC_HSIO_MEM_BASE, SRC_MEDIA_MEM_BASE, SRC_A55C0_MEM_BASE, SRC_A55C1_MEM_BASE, SRC_A55_SCU_MEM_BASE, SRC_A55_L3_MEM_BASE }
  /** Array initializer of SRC_MEM_SLICE peripheral base pointers */
  #define SRC_MEM_SLICE_BASE_PTRS                  { SRC_AON_MEM, SRC_WKUP_MEM, SRC_DDR_MEM, SRC_DPHY_MEM, SRC_ML_MEM, SRC_NIC_MEM, SRC_NIC_OCRAM, SRC_HSIO_MEM, SRC_MEDIA_MEM, SRC_A55C0_MEM, SRC_A55C1_MEM, SRC_A55_SCU_MEM, SRC_A55_L3_MEM }
#endif

/* SRC_MIX_SLICE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_EDGELOCK_SLICE base address */
  #define SRC_EDGELOCK_SLICE_BASE                  (0x54460400u)
  /** Peripheral SRC_EDGELOCK_SLICE base address */
  #define SRC_EDGELOCK_SLICE_BASE_NS               (0x44460400u)
  /** Peripheral SRC_EDGELOCK_SLICE base pointer */
  #define SRC_EDGELOCK_SLICE                       ((SRC_MIX_SLICE_Type *)SRC_EDGELOCK_SLICE_BASE)
  /** Peripheral SRC_EDGELOCK_SLICE base pointer */
  #define SRC_EDGELOCK_SLICE_NS                    ((SRC_MIX_SLICE_Type *)SRC_EDGELOCK_SLICE_BASE_NS)
  /** Peripheral SRC_AON_SLICE base address */
  #define SRC_AON_SLICE_BASE                       (0x54460800u)
  /** Peripheral SRC_AON_SLICE base address */
  #define SRC_AON_SLICE_BASE_NS                    (0x44460800u)
  /** Peripheral SRC_AON_SLICE base pointer */
  #define SRC_AON_SLICE                            ((SRC_MIX_SLICE_Type *)SRC_AON_SLICE_BASE)
  /** Peripheral SRC_AON_SLICE base pointer */
  #define SRC_AON_SLICE_NS                         ((SRC_MIX_SLICE_Type *)SRC_AON_SLICE_BASE_NS)
  /** Peripheral SRC_WKUP_SLICE base address */
  #define SRC_WKUP_SLICE_BASE                      (0x54460C00u)
  /** Peripheral SRC_WKUP_SLICE base address */
  #define SRC_WKUP_SLICE_BASE_NS                   (0x44460C00u)
  /** Peripheral SRC_WKUP_SLICE base pointer */
  #define SRC_WKUP_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_WKUP_SLICE_BASE)
  /** Peripheral SRC_WKUP_SLICE base pointer */
  #define SRC_WKUP_SLICE_NS                        ((SRC_MIX_SLICE_Type *)SRC_WKUP_SLICE_BASE_NS)
  /** Peripheral SRC_DDR_SLICE base address */
  #define SRC_DDR_SLICE_BASE                       (0x54461000u)
  /** Peripheral SRC_DDR_SLICE base address */
  #define SRC_DDR_SLICE_BASE_NS                    (0x44461000u)
  /** Peripheral SRC_DDR_SLICE base pointer */
  #define SRC_DDR_SLICE                            ((SRC_MIX_SLICE_Type *)SRC_DDR_SLICE_BASE)
  /** Peripheral SRC_DDR_SLICE base pointer */
  #define SRC_DDR_SLICE_NS                         ((SRC_MIX_SLICE_Type *)SRC_DDR_SLICE_BASE_NS)
  /** Peripheral SRC_DPHY_SLICE base address */
  #define SRC_DPHY_SLICE_BASE                      (0x54461400u)
  /** Peripheral SRC_DPHY_SLICE base address */
  #define SRC_DPHY_SLICE_BASE_NS                   (0x44461400u)
  /** Peripheral SRC_DPHY_SLICE base pointer */
  #define SRC_DPHY_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_DPHY_SLICE_BASE)
  /** Peripheral SRC_DPHY_SLICE base pointer */
  #define SRC_DPHY_SLICE_NS                        ((SRC_MIX_SLICE_Type *)SRC_DPHY_SLICE_BASE_NS)
  /** Peripheral SRC_ML_SLICE base address */
  #define SRC_ML_SLICE_BASE                        (0x54461800u)
  /** Peripheral SRC_ML_SLICE base address */
  #define SRC_ML_SLICE_BASE_NS                     (0x44461800u)
  /** Peripheral SRC_ML_SLICE base pointer */
  #define SRC_ML_SLICE                             ((SRC_MIX_SLICE_Type *)SRC_ML_SLICE_BASE)
  /** Peripheral SRC_ML_SLICE base pointer */
  #define SRC_ML_SLICE_NS                          ((SRC_MIX_SLICE_Type *)SRC_ML_SLICE_BASE_NS)
  /** Peripheral SRC_NIC_SLICE base address */
  #define SRC_NIC_SLICE_BASE                       (0x54461C00u)
  /** Peripheral SRC_NIC_SLICE base address */
  #define SRC_NIC_SLICE_BASE_NS                    (0x44461C00u)
  /** Peripheral SRC_NIC_SLICE base pointer */
  #define SRC_NIC_SLICE                            ((SRC_MIX_SLICE_Type *)SRC_NIC_SLICE_BASE)
  /** Peripheral SRC_NIC_SLICE base pointer */
  #define SRC_NIC_SLICE_NS                         ((SRC_MIX_SLICE_Type *)SRC_NIC_SLICE_BASE_NS)
  /** Peripheral SRC_HSIO_SLICE base address */
  #define SRC_HSIO_SLICE_BASE                      (0x54462000u)
  /** Peripheral SRC_HSIO_SLICE base address */
  #define SRC_HSIO_SLICE_BASE_NS                   (0x44462000u)
  /** Peripheral SRC_HSIO_SLICE base pointer */
  #define SRC_HSIO_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_HSIO_SLICE_BASE)
  /** Peripheral SRC_HSIO_SLICE base pointer */
  #define SRC_HSIO_SLICE_NS                        ((SRC_MIX_SLICE_Type *)SRC_HSIO_SLICE_BASE_NS)
  /** Peripheral SRC_MEDIA_SLICE base address */
  #define SRC_MEDIA_SLICE_BASE                     (0x54462400u)
  /** Peripheral SRC_MEDIA_SLICE base address */
  #define SRC_MEDIA_SLICE_BASE_NS                  (0x44462400u)
  /** Peripheral SRC_MEDIA_SLICE base pointer */
  #define SRC_MEDIA_SLICE                          ((SRC_MIX_SLICE_Type *)SRC_MEDIA_SLICE_BASE)
  /** Peripheral SRC_MEDIA_SLICE base pointer */
  #define SRC_MEDIA_SLICE_NS                       ((SRC_MIX_SLICE_Type *)SRC_MEDIA_SLICE_BASE_NS)
  /** Peripheral SRC_M33P_SLICE base address */
  #define SRC_M33P_SLICE_BASE                      (0x54462800u)
  /** Peripheral SRC_M33P_SLICE base address */
  #define SRC_M33P_SLICE_BASE_NS                   (0x44462800u)
  /** Peripheral SRC_M33P_SLICE base pointer */
  #define SRC_M33P_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_M33P_SLICE_BASE)
  /** Peripheral SRC_M33P_SLICE base pointer */
  #define SRC_M33P_SLICE_NS                        ((SRC_MIX_SLICE_Type *)SRC_M33P_SLICE_BASE_NS)
  /** Peripheral SRC_A55C0_SLICE base address */
  #define SRC_A55C0_SLICE_BASE                     (0x54462C00u)
  /** Peripheral SRC_A55C0_SLICE base address */
  #define SRC_A55C0_SLICE_BASE_NS                  (0x44462C00u)
  /** Peripheral SRC_A55C0_SLICE base pointer */
  #define SRC_A55C0_SLICE                          ((SRC_MIX_SLICE_Type *)SRC_A55C0_SLICE_BASE)
  /** Peripheral SRC_A55C0_SLICE base pointer */
  #define SRC_A55C0_SLICE_NS                       ((SRC_MIX_SLICE_Type *)SRC_A55C0_SLICE_BASE_NS)
  /** Peripheral SRC_A55C1_SLICE base address */
  #define SRC_A55C1_SLICE_BASE                     (0x54463000u)
  /** Peripheral SRC_A55C1_SLICE base address */
  #define SRC_A55C1_SLICE_BASE_NS                  (0x44463000u)
  /** Peripheral SRC_A55C1_SLICE base pointer */
  #define SRC_A55C1_SLICE                          ((SRC_MIX_SLICE_Type *)SRC_A55C1_SLICE_BASE)
  /** Peripheral SRC_A55C1_SLICE base pointer */
  #define SRC_A55C1_SLICE_NS                       ((SRC_MIX_SLICE_Type *)SRC_A55C1_SLICE_BASE_NS)
  /** Peripheral SRC_A55P_SLICE base address */
  #define SRC_A55P_SLICE_BASE                      (0x54463400u)
  /** Peripheral SRC_A55P_SLICE base address */
  #define SRC_A55P_SLICE_BASE_NS                   (0x44463400u)
  /** Peripheral SRC_A55P_SLICE base pointer */
  #define SRC_A55P_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_A55P_SLICE_BASE)
  /** Peripheral SRC_A55P_SLICE base pointer */
  #define SRC_A55P_SLICE_NS                        ((SRC_MIX_SLICE_Type *)SRC_A55P_SLICE_BASE_NS)
  /** Array initializer of SRC_MIX_SLICE peripheral base addresses */
  #define SRC_MIX_SLICE_BASE_ADDRS                 { SRC_EDGELOCK_SLICE_BASE, SRC_AON_SLICE_BASE, SRC_WKUP_SLICE_BASE, SRC_DDR_SLICE_BASE, SRC_DPHY_SLICE_BASE, SRC_ML_SLICE_BASE, SRC_NIC_SLICE_BASE, SRC_HSIO_SLICE_BASE, SRC_MEDIA_SLICE_BASE, SRC_M33P_SLICE_BASE, SRC_A55C0_SLICE_BASE, SRC_A55C1_SLICE_BASE, SRC_A55P_SLICE_BASE }
  /** Array initializer of SRC_MIX_SLICE peripheral base pointers */
  #define SRC_MIX_SLICE_BASE_PTRS                  { SRC_EDGELOCK_SLICE, SRC_AON_SLICE, SRC_WKUP_SLICE, SRC_DDR_SLICE, SRC_DPHY_SLICE, SRC_ML_SLICE, SRC_NIC_SLICE, SRC_HSIO_SLICE, SRC_MEDIA_SLICE, SRC_M33P_SLICE, SRC_A55C0_SLICE, SRC_A55C1_SLICE, SRC_A55P_SLICE }
  /** Array initializer of SRC_MIX_SLICE peripheral base addresses */
  #define SRC_MIX_SLICE_BASE_ADDRS_NS              { SRC_EDGELOCK_SLICE_BASE_NS, SRC_AON_SLICE_BASE_NS, SRC_WKUP_SLICE_BASE_NS, SRC_DDR_SLICE_BASE_NS, SRC_DPHY_SLICE_BASE_NS, SRC_ML_SLICE_BASE_NS, SRC_NIC_SLICE_BASE_NS, SRC_HSIO_SLICE_BASE_NS, SRC_MEDIA_SLICE_BASE_NS, SRC_M33P_SLICE_BASE_NS, SRC_A55C0_SLICE_BASE_NS, SRC_A55C1_SLICE_BASE_NS, SRC_A55P_SLICE_BASE_NS }
  /** Array initializer of SRC_MIX_SLICE peripheral base pointers */
  #define SRC_MIX_SLICE_BASE_PTRS_NS               { SRC_EDGELOCK_SLICE_NS, SRC_AON_SLICE_NS, SRC_WKUP_SLICE_NS, SRC_DDR_SLICE_NS, SRC_DPHY_SLICE_NS, SRC_ML_SLICE_NS, SRC_NIC_SLICE_NS, SRC_HSIO_SLICE_NS, SRC_MEDIA_SLICE_NS, SRC_M33P_SLICE_NS, SRC_A55C0_SLICE_NS, SRC_A55C1_SLICE_NS, SRC_A55P_SLICE_NS }
#else
  /** Peripheral SRC_EDGELOCK_SLICE base address */
  #define SRC_EDGELOCK_SLICE_BASE                  (0x44460400u)
  /** Peripheral SRC_EDGELOCK_SLICE base pointer */
  #define SRC_EDGELOCK_SLICE                       ((SRC_MIX_SLICE_Type *)SRC_EDGELOCK_SLICE_BASE)
  /** Peripheral SRC_AON_SLICE base address */
  #define SRC_AON_SLICE_BASE                       (0x44460800u)
  /** Peripheral SRC_AON_SLICE base pointer */
  #define SRC_AON_SLICE                            ((SRC_MIX_SLICE_Type *)SRC_AON_SLICE_BASE)
  /** Peripheral SRC_WKUP_SLICE base address */
  #define SRC_WKUP_SLICE_BASE                      (0x44460C00u)
  /** Peripheral SRC_WKUP_SLICE base pointer */
  #define SRC_WKUP_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_WKUP_SLICE_BASE)
  /** Peripheral SRC_DDR_SLICE base address */
  #define SRC_DDR_SLICE_BASE                       (0x44461000u)
  /** Peripheral SRC_DDR_SLICE base pointer */
  #define SRC_DDR_SLICE                            ((SRC_MIX_SLICE_Type *)SRC_DDR_SLICE_BASE)
  /** Peripheral SRC_DPHY_SLICE base address */
  #define SRC_DPHY_SLICE_BASE                      (0x44461400u)
  /** Peripheral SRC_DPHY_SLICE base pointer */
  #define SRC_DPHY_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_DPHY_SLICE_BASE)
  /** Peripheral SRC_ML_SLICE base address */
  #define SRC_ML_SLICE_BASE                        (0x44461800u)
  /** Peripheral SRC_ML_SLICE base pointer */
  #define SRC_ML_SLICE                             ((SRC_MIX_SLICE_Type *)SRC_ML_SLICE_BASE)
  /** Peripheral SRC_NIC_SLICE base address */
  #define SRC_NIC_SLICE_BASE                       (0x44461C00u)
  /** Peripheral SRC_NIC_SLICE base pointer */
  #define SRC_NIC_SLICE                            ((SRC_MIX_SLICE_Type *)SRC_NIC_SLICE_BASE)
  /** Peripheral SRC_HSIO_SLICE base address */
  #define SRC_HSIO_SLICE_BASE                      (0x44462000u)
  /** Peripheral SRC_HSIO_SLICE base pointer */
  #define SRC_HSIO_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_HSIO_SLICE_BASE)
  /** Peripheral SRC_MEDIA_SLICE base address */
  #define SRC_MEDIA_SLICE_BASE                     (0x44462400u)
  /** Peripheral SRC_MEDIA_SLICE base pointer */
  #define SRC_MEDIA_SLICE                          ((SRC_MIX_SLICE_Type *)SRC_MEDIA_SLICE_BASE)
  /** Peripheral SRC_M33P_SLICE base address */
  #define SRC_M33P_SLICE_BASE                      (0x44462800u)
  /** Peripheral SRC_M33P_SLICE base pointer */
  #define SRC_M33P_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_M33P_SLICE_BASE)
  /** Peripheral SRC_A55C0_SLICE base address */
  #define SRC_A55C0_SLICE_BASE                     (0x44462C00u)
  /** Peripheral SRC_A55C0_SLICE base pointer */
  #define SRC_A55C0_SLICE                          ((SRC_MIX_SLICE_Type *)SRC_A55C0_SLICE_BASE)
  /** Peripheral SRC_A55C1_SLICE base address */
  #define SRC_A55C1_SLICE_BASE                     (0x44463000u)
  /** Peripheral SRC_A55C1_SLICE base pointer */
  #define SRC_A55C1_SLICE                          ((SRC_MIX_SLICE_Type *)SRC_A55C1_SLICE_BASE)
  /** Peripheral SRC_A55P_SLICE base address */
  #define SRC_A55P_SLICE_BASE                      (0x44463400u)
  /** Peripheral SRC_A55P_SLICE base pointer */
  #define SRC_A55P_SLICE                           ((SRC_MIX_SLICE_Type *)SRC_A55P_SLICE_BASE)
  /** Array initializer of SRC_MIX_SLICE peripheral base addresses */
  #define SRC_MIX_SLICE_BASE_ADDRS                 { SRC_EDGELOCK_SLICE_BASE, SRC_AON_SLICE_BASE, SRC_WKUP_SLICE_BASE, SRC_DDR_SLICE_BASE, SRC_DPHY_SLICE_BASE, SRC_ML_SLICE_BASE, SRC_NIC_SLICE_BASE, SRC_HSIO_SLICE_BASE, SRC_MEDIA_SLICE_BASE, SRC_M33P_SLICE_BASE, SRC_A55C0_SLICE_BASE, SRC_A55C1_SLICE_BASE, SRC_A55P_SLICE_BASE }
  /** Array initializer of SRC_MIX_SLICE peripheral base pointers */
  #define SRC_MIX_SLICE_BASE_PTRS                  { SRC_EDGELOCK_SLICE, SRC_AON_SLICE, SRC_WKUP_SLICE, SRC_DDR_SLICE, SRC_DPHY_SLICE, SRC_ML_SLICE, SRC_NIC_SLICE, SRC_HSIO_SLICE, SRC_MEDIA_SLICE, SRC_M33P_SLICE, SRC_A55C0_SLICE, SRC_A55C1_SLICE, SRC_A55P_SLICE }
#endif

/* SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M33_PCF1 base address */
  #define M33_PCF1_BASE                            (0x543E0000u)
  /** Peripheral M33_PCF1 base address */
  #define M33_PCF1_BASE_NS                         (0x443E0000u)
  /** Peripheral M33_PCF1 base pointer */
  #define M33_PCF1                                 ((SYSPM_Type *)M33_PCF1_BASE)
  /** Peripheral M33_PCF1 base pointer */
  #define M33_PCF1_NS                              ((SYSPM_Type *)M33_PCF1_BASE_NS)
  /** Peripheral M33_PSF1 base address */
  #define M33_PSF1_BASE                            (0x543F0000u)
  /** Peripheral M33_PSF1 base address */
  #define M33_PSF1_BASE_NS                         (0x443F0000u)
  /** Peripheral M33_PSF1 base pointer */
  #define M33_PSF1                                 ((SYSPM_Type *)M33_PSF1_BASE)
  /** Peripheral M33_PSF1 base pointer */
  #define M33_PSF1_NS                              ((SYSPM_Type *)M33_PSF1_BASE_NS)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { M33_PCF1_BASE, M33_PSF1_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { M33_PCF1, M33_PSF1 }
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS_NS                      { M33_PCF1_BASE_NS, M33_PSF1_BASE_NS }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS_NS                       { M33_PCF1_NS, M33_PSF1_NS }
#else
  /** Peripheral M33_PCF1 base address */
  #define M33_PCF1_BASE                            (0x443E0000u)
  /** Peripheral M33_PCF1 base pointer */
  #define M33_PCF1                                 ((SYSPM_Type *)M33_PCF1_BASE)
  /** Peripheral M33_PSF1 base address */
  #define M33_PSF1_BASE                            (0x443F0000u)
  /** Peripheral M33_PSF1 base pointer */
  #define M33_PSF1                                 ((SYSPM_Type *)M33_PSF1_BASE)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { M33_PCF1_BASE, M33_PSF1_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { M33_PCF1, M33_PSF1 }
#endif

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_CTR_COMPARE base address */
  #define SYS_CTR_COMPARE_BASE                     (0x54292000u)
  /** Peripheral SYS_CTR_COMPARE base address */
  #define SYS_CTR_COMPARE_BASE_NS                  (0x44292000u)
  /** Peripheral SYS_CTR_COMPARE base pointer */
  #define SYS_CTR_COMPARE                          ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE)
  /** Peripheral SYS_CTR_COMPARE base pointer */
  #define SYS_CTR_COMPARE_NS                       ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE_NS)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { SYS_CTR_COMPARE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS_NS            { SYS_CTR_COMPARE_BASE_NS }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS_NS             { SYS_CTR_COMPARE_NS }
#else
  /** Peripheral SYS_CTR_COMPARE base address */
  #define SYS_CTR_COMPARE_BASE                     (0x44292000u)
  /** Peripheral SYS_CTR_COMPARE base pointer */
  #define SYS_CTR_COMPARE                          ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { SYS_CTR_COMPARE }
#endif

/* SYS_CTR_CONTROL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE                     (0x54290000u)
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE_NS                  (0x44290000u)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL                          ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL_NS                       ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE_NS)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CONTROL }
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS_NS            { SYS_CTR_CONTROL_BASE_NS }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS_NS             { SYS_CTR_CONTROL_NS }
#else
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE                     (0x44290000u)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL                          ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CONTROL }
#endif

/* SYS_CTR_READ - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_CTR_READ base address */
  #define SYS_CTR_READ_BASE                        (0x54291000u)
  /** Peripheral SYS_CTR_READ base address */
  #define SYS_CTR_READ_BASE_NS                     (0x44291000u)
  /** Peripheral SYS_CTR_READ base pointer */
  #define SYS_CTR_READ                             ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE)
  /** Peripheral SYS_CTR_READ base pointer */
  #define SYS_CTR_READ_NS                          ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE_NS)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { SYS_CTR_READ }
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS_NS               { SYS_CTR_READ_BASE_NS }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS_NS                { SYS_CTR_READ_NS }
#else
  /** Peripheral SYS_CTR_READ base address */
  #define SYS_CTR_READ_BASE                        (0x44291000u)
  /** Peripheral SYS_CTR_READ base pointer */
  #define SYS_CTR_READ                             ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { SYS_CTR_READ }
#endif

/* TCM_ECC_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CM33_TCM_MCM base address */
  #define CM33_TCM_MCM_BASE                        (0x54420000u)
  /** Peripheral CM33_TCM_MCM base address */
  #define CM33_TCM_MCM_BASE_NS                     (0x44420000u)
  /** Peripheral CM33_TCM_MCM base pointer */
  #define CM33_TCM_MCM                             ((TCM_ECC_MCM_Type *)CM33_TCM_MCM_BASE)
  /** Peripheral CM33_TCM_MCM base pointer */
  #define CM33_TCM_MCM_NS                          ((TCM_ECC_MCM_Type *)CM33_TCM_MCM_BASE_NS)
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS                   { CM33_TCM_MCM_BASE }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS                    { CM33_TCM_MCM }
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS_NS                { CM33_TCM_MCM_BASE_NS }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS_NS                 { CM33_TCM_MCM_NS }
#else
  /** Peripheral CM33_TCM_MCM base address */
  #define CM33_TCM_MCM_BASE                        (0x44420000u)
  /** Peripheral CM33_TCM_MCM base pointer */
  #define CM33_TCM_MCM                             ((TCM_ECC_MCM_Type *)CM33_TCM_MCM_BASE)
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS                   { CM33_TCM_MCM_BASE }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS                    { CM33_TCM_MCM }
#endif

/* TMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TMU base address */
  #define TMU_BASE                                 (0x54482000u)
  /** Peripheral TMU base address */
  #define TMU_BASE_NS                              (0x44482000u)
  /** Peripheral TMU base pointer */
  #define TMU                                      ((TMU_Type *)TMU_BASE)
  /** Peripheral TMU base pointer */
  #define TMU_NS                                   ((TMU_Type *)TMU_BASE_NS)
  /** Array initializer of TMU peripheral base addresses */
  #define TMU_BASE_ADDRS                           { TMU_BASE }
  /** Array initializer of TMU peripheral base pointers */
  #define TMU_BASE_PTRS                            { TMU }
  /** Array initializer of TMU peripheral base addresses */
  #define TMU_BASE_ADDRS_NS                        { TMU_BASE_NS }
  /** Array initializer of TMU peripheral base pointers */
  #define TMU_BASE_PTRS_NS                         { TMU_NS }
#else
  /** Peripheral TMU base address */
  #define TMU_BASE                                 (0x44482000u)
  /** Peripheral TMU base pointer */
  #define TMU                                      ((TMU_Type *)TMU_BASE)
  /** Array initializer of TMU peripheral base addresses */
  #define TMU_BASE_ADDRS                           { TMU_BASE }
  /** Array initializer of TMU peripheral base pointers */
  #define TMU_BASE_PTRS                            { TMU }
#endif

/* TPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x54310000u)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE_NS                             (0x44310000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM1 base pointer */
  #define TPM1_NS                                  ((TPM_Type *)TPM1_BASE_NS)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x54320000u)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE_NS                             (0x44320000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM2 base pointer */
  #define TPM2_NS                                  ((TPM_Type *)TPM2_BASE_NS)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE                                (0x524E0000u)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE_NS                             (0x424E0000u)
  /** Peripheral TPM3 base pointer */
  #define TPM3                                     ((TPM_Type *)TPM3_BASE)
  /** Peripheral TPM3 base pointer */
  #define TPM3_NS                                  ((TPM_Type *)TPM3_BASE_NS)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE                                (0x524F0000u)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE_NS                             (0x424F0000u)
  /** Peripheral TPM4 base pointer */
  #define TPM4                                     ((TPM_Type *)TPM4_BASE)
  /** Peripheral TPM4 base pointer */
  #define TPM4_NS                                  ((TPM_Type *)TPM4_BASE_NS)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE                                (0x52500000u)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE_NS                             (0x42500000u)
  /** Peripheral TPM5 base pointer */
  #define TPM5                                     ((TPM_Type *)TPM5_BASE)
  /** Peripheral TPM5 base pointer */
  #define TPM5_NS                                  ((TPM_Type *)TPM5_BASE_NS)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE                                (0x52510000u)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE_NS                             (0x42510000u)
  /** Peripheral TPM6 base pointer */
  #define TPM6                                     ((TPM_Type *)TPM6_BASE)
  /** Peripheral TPM6 base pointer */
  #define TPM6_NS                                  ((TPM_Type *)TPM6_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { 0u, TPM1_BASE_NS, TPM2_BASE_NS, TPM3_BASE_NS, TPM4_BASE_NS, TPM5_BASE_NS, TPM6_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { (TPM_Type *)0u, TPM1_NS, TPM2_NS, TPM3_NS, TPM4_NS, TPM5_NS, TPM6_NS }
#else
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x44310000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x44320000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE                                (0x424E0000u)
  /** Peripheral TPM3 base pointer */
  #define TPM3                                     ((TPM_Type *)TPM3_BASE)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE                                (0x424F0000u)
  /** Peripheral TPM4 base pointer */
  #define TPM4                                     ((TPM_Type *)TPM4_BASE)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE                                (0x42500000u)
  /** Peripheral TPM5 base pointer */
  #define TPM5                                     ((TPM_Type *)TPM5_BASE)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE                                (0x42510000u)
  /** Peripheral TPM6 base pointer */
  #define TPM6                                     ((TPM_Type *)TPM6_BASE)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, TPM4_IRQn, TPM5_IRQn, TPM6_IRQn }

/* TRDC_MBC0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRDC3 base address */
  #define TRDC3_BASE                               (0x52810000u)
  /** Peripheral TRDC3 base address */
  #define TRDC3_BASE_NS                            (0x42810000u)
  /** Peripheral TRDC3 base pointer */
  #define TRDC3                                    ((TRDC_MBC0_Type *)TRDC3_BASE)
  /** Peripheral TRDC3 base pointer */
  #define TRDC3_NS                                 ((TRDC_MBC0_Type *)TRDC3_BASE_NS)
  /** Peripheral TRDC5 base address */
  #define TRDC5_BASE                               (0x5AC30000u)
  /** Peripheral TRDC5 base address */
  #define TRDC5_BASE_NS                            (0x4AC30000u)
  /** Peripheral TRDC5 base pointer */
  #define TRDC5                                    ((TRDC_MBC0_Type *)TRDC5_BASE)
  /** Peripheral TRDC5 base pointer */
  #define TRDC5_NS                                 ((TRDC_MBC0_Type *)TRDC5_BASE_NS)
  /** Peripheral TRDC6 base address */
  #define TRDC6_BASE                               (0x5C030000u)
  /** Peripheral TRDC6 base address */
  #define TRDC6_BASE_NS                            (0x4C030000u)
  /** Peripheral TRDC6 base pointer */
  #define TRDC6                                    ((TRDC_MBC0_Type *)TRDC6_BASE)
  /** Peripheral TRDC6 base pointer */
  #define TRDC6_NS                                 ((TRDC_MBC0_Type *)TRDC6_BASE_NS)
  /** Array initializer of TRDC_MBC0 peripheral base addresses */
  #define TRDC_MBC0_BASE_ADDRS                     { 0u, 0u, 0u, TRDC3_BASE, 0u, TRDC5_BASE, TRDC6_BASE }
  /** Array initializer of TRDC_MBC0 peripheral base pointers */
  #define TRDC_MBC0_BASE_PTRS                      { (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, TRDC3, (TRDC_MBC0_Type *)0u, TRDC5, TRDC6 }
  /** Array initializer of TRDC_MBC0 peripheral base addresses */
  #define TRDC_MBC0_BASE_ADDRS_NS                  { 0u, 0u, 0u, TRDC3_BASE_NS, 0u, TRDC5_BASE_NS, TRDC6_BASE_NS }
  /** Array initializer of TRDC_MBC0 peripheral base pointers */
  #define TRDC_MBC0_BASE_PTRS_NS                   { (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, TRDC3_NS, (TRDC_MBC0_Type *)0u, TRDC5_NS, TRDC6_NS }
#else
  /** Peripheral TRDC3 base address */
  #define TRDC3_BASE                               (0x42810000u)
  /** Peripheral TRDC3 base pointer */
  #define TRDC3                                    ((TRDC_MBC0_Type *)TRDC3_BASE)
  /** Peripheral TRDC5 base address */
  #define TRDC5_BASE                               (0x4AC30000u)
  /** Peripheral TRDC5 base pointer */
  #define TRDC5                                    ((TRDC_MBC0_Type *)TRDC5_BASE)
  /** Peripheral TRDC6 base address */
  #define TRDC6_BASE                               (0x4C030000u)
  /** Peripheral TRDC6 base pointer */
  #define TRDC6                                    ((TRDC_MBC0_Type *)TRDC6_BASE)
  /** Array initializer of TRDC_MBC0 peripheral base addresses */
  #define TRDC_MBC0_BASE_ADDRS                     { 0u, 0u, 0u, TRDC3_BASE, 0u, TRDC5_BASE, TRDC6_BASE }
  /** Array initializer of TRDC_MBC0 peripheral base pointers */
  #define TRDC_MBC0_BASE_PTRS                      { (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, TRDC3, (TRDC_MBC0_Type *)0u, TRDC5, TRDC6 }
#endif
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


/* TRDC_MBC2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRDC1 base address */
  #define TRDC1_BASE                               (0x54270000u)
  /** Peripheral TRDC1 base address */
  #define TRDC1_BASE_NS                            (0x44270000u)
  /** Peripheral TRDC1 base pointer */
  #define TRDC1                                    ((TRDC_MBC2_Type *)TRDC1_BASE)
  /** Peripheral TRDC1 base pointer */
  #define TRDC1_NS                                 ((TRDC_MBC2_Type *)TRDC1_BASE_NS)
  /** Peripheral TRDC2 base address */
  #define TRDC2_BASE                               (0x52460000u)
  /** Peripheral TRDC2 base address */
  #define TRDC2_BASE_NS                            (0x42460000u)
  /** Peripheral TRDC2 base pointer */
  #define TRDC2                                    ((TRDC_MBC2_Type *)TRDC2_BASE)
  /** Peripheral TRDC2 base pointer */
  #define TRDC2_NS                                 ((TRDC_MBC2_Type *)TRDC2_BASE_NS)
  /** Array initializer of TRDC_MBC2 peripheral base addresses */
  #define TRDC_MBC2_BASE_ADDRS                     { 0u, TRDC1_BASE, TRDC2_BASE }
  /** Array initializer of TRDC_MBC2 peripheral base pointers */
  #define TRDC_MBC2_BASE_PTRS                      { (TRDC_MBC2_Type *)0u, TRDC1, TRDC2 }
  /** Array initializer of TRDC_MBC2 peripheral base addresses */
  #define TRDC_MBC2_BASE_ADDRS_NS                  { 0u, TRDC1_BASE_NS, TRDC2_BASE_NS }
  /** Array initializer of TRDC_MBC2 peripheral base pointers */
  #define TRDC_MBC2_BASE_PTRS_NS                   { (TRDC_MBC2_Type *)0u, TRDC1_NS, TRDC2_NS }
#else
  /** Peripheral TRDC1 base address */
  #define TRDC1_BASE                               (0x44270000u)
  /** Peripheral TRDC1 base pointer */
  #define TRDC1                                    ((TRDC_MBC2_Type *)TRDC1_BASE)
  /** Peripheral TRDC2 base address */
  #define TRDC2_BASE                               (0x42460000u)
  /** Peripheral TRDC2 base pointer */
  #define TRDC2                                    ((TRDC_MBC2_Type *)TRDC2_BASE)
  /** Array initializer of TRDC_MBC2 peripheral base addresses */
  #define TRDC_MBC2_BASE_ADDRS                     { 0u, TRDC1_BASE, TRDC2_BASE }
  /** Array initializer of TRDC_MBC2 peripheral base pointers */
  #define TRDC_MBC2_BASE_PTRS                      { (TRDC_MBC2_Type *)0u, TRDC1, TRDC2 }
#endif
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


/* TRDC_MBC4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRDC4 base address */
  #define TRDC4_BASE                               (0x59010000u)
  /** Peripheral TRDC4 base address */
  #define TRDC4_BASE_NS                            (0x49010000u)
  /** Peripheral TRDC4 base pointer */
  #define TRDC4                                    ((TRDC_MBC4_Type *)TRDC4_BASE)
  /** Peripheral TRDC4 base pointer */
  #define TRDC4_NS                                 ((TRDC_MBC4_Type *)TRDC4_BASE_NS)
  /** Array initializer of TRDC_MBC4 peripheral base addresses */
  #define TRDC_MBC4_BASE_ADDRS                     { 0u, 0u, 0u, 0u, TRDC4_BASE }
  /** Array initializer of TRDC_MBC4 peripheral base pointers */
  #define TRDC_MBC4_BASE_PTRS                      { (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, TRDC4 }
  /** Array initializer of TRDC_MBC4 peripheral base addresses */
  #define TRDC_MBC4_BASE_ADDRS_NS                  { 0u, 0u, 0u, 0u, TRDC4_BASE_NS }
  /** Array initializer of TRDC_MBC4 peripheral base pointers */
  #define TRDC_MBC4_BASE_PTRS_NS                   { (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, TRDC4_NS }
#else
  /** Peripheral TRDC4 base address */
  #define TRDC4_BASE                               (0x49010000u)
  /** Peripheral TRDC4 base pointer */
  #define TRDC4                                    ((TRDC_MBC4_Type *)TRDC4_BASE)
  /** Array initializer of TRDC_MBC4 peripheral base addresses */
  #define TRDC_MBC4_BASE_ADDRS                     { 0u, 0u, 0u, 0u, TRDC4_BASE }
  /** Array initializer of TRDC_MBC4 peripheral base pointers */
  #define TRDC_MBC4_BASE_PTRS                      { (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, TRDC4 }
#endif
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


/* TRGMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRGMUX base address */
  #define TRGMUX_BASE                              (0x54531000u)
  /** Peripheral TRGMUX base address */
  #define TRGMUX_BASE_NS                           (0x44531000u)
  /** Peripheral TRGMUX base pointer */
  #define TRGMUX                                   ((TRGMUX_Type *)TRGMUX_BASE)
  /** Peripheral TRGMUX base pointer */
  #define TRGMUX_NS                                ((TRGMUX_Type *)TRGMUX_BASE_NS)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX }
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS_NS                     { TRGMUX_BASE_NS }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS_NS                      { TRGMUX_NS }
#else
  /** Peripheral TRGMUX base address */
  #define TRGMUX_BASE                              (0x44531000u)
  /** Peripheral TRGMUX base pointer */
  #define TRGMUX                                   ((TRGMUX_Type *)TRGMUX_BASE)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX }
#endif

/* TSTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TSTMR1__TSTMRA base address */
  #define TSTMR1__TSTMRA_BASE                      (0x542C0000u)
  /** Peripheral TSTMR1__TSTMRA base address */
  #define TSTMR1__TSTMRA_BASE_NS                   (0x442C0000u)
  /** Peripheral TSTMR1__TSTMRA base pointer */
  #define TSTMR1__TSTMRA                           ((TSTMR_Type *)TSTMR1__TSTMRA_BASE)
  /** Peripheral TSTMR1__TSTMRA base pointer */
  #define TSTMR1__TSTMRA_NS                        ((TSTMR_Type *)TSTMR1__TSTMRA_BASE_NS)
  /** Peripheral TSTMR2__TSTMRA base address */
  #define TSTMR2__TSTMRA_BASE                      (0x52480000u)
  /** Peripheral TSTMR2__TSTMRA base address */
  #define TSTMR2__TSTMRA_BASE_NS                   (0x42480000u)
  /** Peripheral TSTMR2__TSTMRA base pointer */
  #define TSTMR2__TSTMRA                           ((TSTMR_Type *)TSTMR2__TSTMRA_BASE)
  /** Peripheral TSTMR2__TSTMRA base pointer */
  #define TSTMR2__TSTMRA_NS                        ((TSTMR_Type *)TSTMR2__TSTMRA_BASE_NS)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR1__TSTMRA_BASE, TSTMR2__TSTMRA_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR1__TSTMRA, TSTMR2__TSTMRA }
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS_NS                      { TSTMR1__TSTMRA_BASE_NS, TSTMR2__TSTMRA_BASE_NS }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS_NS                       { TSTMR1__TSTMRA_NS, TSTMR2__TSTMRA_NS }
#else
  /** Peripheral TSTMR1__TSTMRA base address */
  #define TSTMR1__TSTMRA_BASE                      (0x442C0000u)
  /** Peripheral TSTMR1__TSTMRA base pointer */
  #define TSTMR1__TSTMRA                           ((TSTMR_Type *)TSTMR1__TSTMRA_BASE)
  /** Peripheral TSTMR2__TSTMRA base address */
  #define TSTMR2__TSTMRA_BASE                      (0x42480000u)
  /** Peripheral TSTMR2__TSTMRA base pointer */
  #define TSTMR2__TSTMRA                           ((TSTMR_Type *)TSTMR2__TSTMRA_BASE)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR1__TSTMRA_BASE, TSTMR2__TSTMRA_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR1__TSTMRA, TSTMR2__TSTMRA }
#endif

/* USB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USB__USB_OTG1 base address */
  #define USB__USB_OTG1_BASE                       (0x5C100000u)
  /** Peripheral USB__USB_OTG1 base address */
  #define USB__USB_OTG1_BASE_NS                    (0x4C100000u)
  /** Peripheral USB__USB_OTG1 base pointer */
  #define USB__USB_OTG1                            ((USB_Type *)USB__USB_OTG1_BASE)
  /** Peripheral USB__USB_OTG1 base pointer */
  #define USB__USB_OTG1_NS                         ((USB_Type *)USB__USB_OTG1_BASE_NS)
  /** Peripheral USB__USB_OTG2 base address */
  #define USB__USB_OTG2_BASE                       (0x5C200000u)
  /** Peripheral USB__USB_OTG2 base address */
  #define USB__USB_OTG2_BASE_NS                    (0x4C200000u)
  /** Peripheral USB__USB_OTG2 base pointer */
  #define USB__USB_OTG2                            ((USB_Type *)USB__USB_OTG2_BASE)
  /** Peripheral USB__USB_OTG2 base pointer */
  #define USB__USB_OTG2_NS                         ((USB_Type *)USB__USB_OTG2_BASE_NS)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB__USB_OTG1_BASE, USB__USB_OTG2_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB__USB_OTG1, USB__USB_OTG2 }
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS_NS                        { USB__USB_OTG1_BASE_NS, USB__USB_OTG2_BASE_NS }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS_NS                         { USB__USB_OTG1_NS, USB__USB_OTG2_NS }
#else
  /** Peripheral USB__USB_OTG1 base address */
  #define USB__USB_OTG1_BASE                       (0x4C100000u)
  /** Peripheral USB__USB_OTG1 base pointer */
  #define USB__USB_OTG1                            ((USB_Type *)USB__USB_OTG1_BASE)
  /** Peripheral USB__USB_OTG2 base address */
  #define USB__USB_OTG2_BASE                       (0x4C200000u)
  /** Peripheral USB__USB_OTG2 base pointer */
  #define USB__USB_OTG2                            ((USB_Type *)USB__USB_OTG2_BASE)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB__USB_OTG1_BASE, USB__USB_OTG2_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB__USB_OTG1, USB__USB_OTG2 }
#endif

/* USBNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USB__USBNC_OTG1 base address */
  #define USB__USBNC_OTG1_BASE                     (0x5C100200u)
  /** Peripheral USB__USBNC_OTG1 base address */
  #define USB__USBNC_OTG1_BASE_NS                  (0x4C100200u)
  /** Peripheral USB__USBNC_OTG1 base pointer */
  #define USB__USBNC_OTG1                          ((USBNC_Type *)USB__USBNC_OTG1_BASE)
  /** Peripheral USB__USBNC_OTG1 base pointer */
  #define USB__USBNC_OTG1_NS                       ((USBNC_Type *)USB__USBNC_OTG1_BASE_NS)
  /** Peripheral USB__USBNC_OTG2 base address */
  #define USB__USBNC_OTG2_BASE                     (0x5C200200u)
  /** Peripheral USB__USBNC_OTG2 base address */
  #define USB__USBNC_OTG2_BASE_NS                  (0x4C200200u)
  /** Peripheral USB__USBNC_OTG2 base pointer */
  #define USB__USBNC_OTG2                          ((USBNC_Type *)USB__USBNC_OTG2_BASE)
  /** Peripheral USB__USBNC_OTG2 base pointer */
  #define USB__USBNC_OTG2_NS                       ((USBNC_Type *)USB__USBNC_OTG2_BASE_NS)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USB__USBNC_OTG1_BASE, USB__USBNC_OTG2_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USB__USBNC_OTG1, USB__USBNC_OTG2 }
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS_NS                      { USB__USBNC_OTG1_BASE_NS, USB__USBNC_OTG2_BASE_NS }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS_NS                       { USB__USBNC_OTG1_NS, USB__USBNC_OTG2_NS }
#else
  /** Peripheral USB__USBNC_OTG1 base address */
  #define USB__USBNC_OTG1_BASE                     (0x4C100200u)
  /** Peripheral USB__USBNC_OTG1 base pointer */
  #define USB__USBNC_OTG1                          ((USBNC_Type *)USB__USBNC_OTG1_BASE)
  /** Peripheral USB__USBNC_OTG2 base address */
  #define USB__USBNC_OTG2_BASE                     (0x4C200200u)
  /** Peripheral USB__USBNC_OTG2 base pointer */
  #define USB__USBNC_OTG2                          ((USBNC_Type *)USB__USBNC_OTG2_BASE)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USB__USBNC_OTG1_BASE, USB__USBNC_OTG2_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USB__USBNC_OTG1, USB__USBNC_OTG2 }
#endif

/* USDHC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x52850000u)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE_NS                           (0x42850000u)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1_NS                                ((USDHC_Type *)USDHC1_BASE_NS)
  /** Peripheral USDHC2 base address */
  #define USDHC2_BASE                              (0x52860000u)
  /** Peripheral USDHC2 base address */
  #define USDHC2_BASE_NS                           (0x42860000u)
  /** Peripheral USDHC2 base pointer */
  #define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
  /** Peripheral USDHC2 base pointer */
  #define USDHC2_NS                                ((USDHC_Type *)USDHC2_BASE_NS)
  /** Peripheral USDHC3 base address */
  #define USDHC3_BASE                              (0x528B0000u)
  /** Peripheral USDHC3 base address */
  #define USDHC3_BASE_NS                           (0x428B0000u)
  /** Peripheral USDHC3 base pointer */
  #define USDHC3                                   ((USDHC_Type *)USDHC3_BASE)
  /** Peripheral USDHC3 base pointer */
  #define USDHC3_NS                                ((USDHC_Type *)USDHC3_BASE_NS)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { 0u, USDHC1_BASE, USDHC2_BASE, USDHC3_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, USDHC1, USDHC2, USDHC3 }
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS_NS                      { 0u, USDHC1_BASE_NS, USDHC2_BASE_NS, USDHC3_BASE_NS }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS_NS                       { (USDHC_Type *)0u, USDHC1_NS, USDHC2_NS, USDHC3_NS }
#else
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x42850000u)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
  /** Peripheral USDHC2 base address */
  #define USDHC2_BASE                              (0x42860000u)
  /** Peripheral USDHC2 base pointer */
  #define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
  /** Peripheral USDHC3 base address */
  #define USDHC3_BASE                              (0x428B0000u)
  /** Peripheral USDHC3 base pointer */
  #define USDHC3                                   ((USDHC_Type *)USDHC3_BASE)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { 0u, USDHC1_BASE, USDHC2_BASE, USDHC3_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, USDHC1, USDHC2, USDHC3 }
#endif
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { NotAvail_IRQn, uSDHC1_IRQn, uSDHC2_IRQn, uSDHC3_IRQn }

/* WAKEUP_AHBRM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AHBRM1 base address */
  #define AHBRM1_BASE                              (0x525E0000u)
  /** Peripheral AHBRM1 base address */
  #define AHBRM1_BASE_NS                           (0x425E0000u)
  /** Peripheral AHBRM1 base pointer */
  #define AHBRM1                                   ((WAKEUP_AHBRM_Type *)AHBRM1_BASE)
  /** Peripheral AHBRM1 base pointer */
  #define AHBRM1_NS                                ((WAKEUP_AHBRM_Type *)AHBRM1_BASE_NS)
  /** Array initializer of WAKEUP_AHBRM peripheral base addresses */
  #define WAKEUP_AHBRM_BASE_ADDRS                  { AHBRM1_BASE }
  /** Array initializer of WAKEUP_AHBRM peripheral base pointers */
  #define WAKEUP_AHBRM_BASE_PTRS                   { AHBRM1 }
  /** Array initializer of WAKEUP_AHBRM peripheral base addresses */
  #define WAKEUP_AHBRM_BASE_ADDRS_NS               { AHBRM1_BASE_NS }
  /** Array initializer of WAKEUP_AHBRM peripheral base pointers */
  #define WAKEUP_AHBRM_BASE_PTRS_NS                { AHBRM1_NS }
#else
  /** Peripheral AHBRM1 base address */
  #define AHBRM1_BASE                              (0x425E0000u)
  /** Peripheral AHBRM1 base pointer */
  #define AHBRM1                                   ((WAKEUP_AHBRM_Type *)AHBRM1_BASE)
  /** Array initializer of WAKEUP_AHBRM peripheral base addresses */
  #define WAKEUP_AHBRM_BASE_ADDRS                  { AHBRM1_BASE }
  /** Array initializer of WAKEUP_AHBRM peripheral base pointers */
  #define WAKEUP_AHBRM_BASE_PTRS                   { AHBRM1 }
#endif

/* WDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x542D0000u)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE_NS                            (0x442D0000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1_NS                                 ((WDOG_Type *)WDOG1_BASE_NS)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE                               (0x542E0000u)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE_NS                            (0x442E0000u)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2_NS                                 ((WDOG_Type *)WDOG2_BASE_NS)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE                               (0x52490000u)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE_NS                            (0x42490000u)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3_NS                                 ((WDOG_Type *)WDOG3_BASE_NS)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE                               (0x524A0000u)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE_NS                            (0x424A0000u)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4_NS                                 ((WDOG_Type *)WDOG4_BASE_NS)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE                               (0x524B0000u)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE_NS                            (0x424B0000u)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5_NS                                 ((WDOG_Type *)WDOG5_BASE_NS)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS_NS                       { WDOG1_BASE_NS, WDOG2_BASE_NS, WDOG3_BASE_NS, WDOG4_BASE_NS, WDOG5_BASE_NS }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS_NS                        { WDOG1_NS, WDOG2_NS, WDOG3_NS, WDOG4_NS, WDOG5_NS }
#else
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x442D0000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE                               (0x442E0000u)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE                               (0x42490000u)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE                               (0x424A0000u)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE                               (0x424B0000u)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
#endif
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG1_IRQn, WDOG2_IRQn, WDOG3_IRQn, WDOG4_IRQn, WDOG5_IRQn }

/* XCACHE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPCAC_PC base address */
  #define LPCAC_PC_BASE                            (0x54400000u)
  /** Peripheral LPCAC_PC base address */
  #define LPCAC_PC_BASE_NS                         (0x44400000u)
  /** Peripheral LPCAC_PC base pointer */
  #define LPCAC_PC                                 ((XCACHE_Type *)LPCAC_PC_BASE)
  /** Peripheral LPCAC_PC base pointer */
  #define LPCAC_PC_NS                              ((XCACHE_Type *)LPCAC_PC_BASE_NS)
  /** Peripheral LPCAC_PS base address */
  #define LPCAC_PS_BASE                            (0x54400800u)
  /** Peripheral LPCAC_PS base address */
  #define LPCAC_PS_BASE_NS                         (0x44400800u)
  /** Peripheral LPCAC_PS base pointer */
  #define LPCAC_PS                                 ((XCACHE_Type *)LPCAC_PS_BASE)
  /** Peripheral LPCAC_PS base pointer */
  #define LPCAC_PS_NS                              ((XCACHE_Type *)LPCAC_PS_BASE_NS)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { LPCAC_PC_BASE, LPCAC_PS_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { LPCAC_PC, LPCAC_PS }
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS_NS                     { LPCAC_PC_BASE_NS, LPCAC_PS_BASE_NS }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS_NS                      { LPCAC_PC_NS, LPCAC_PS_NS }
#else
  /** Peripheral LPCAC_PC base address */
  #define LPCAC_PC_BASE                            (0x44400000u)
  /** Peripheral LPCAC_PC base pointer */
  #define LPCAC_PC                                 ((XCACHE_Type *)LPCAC_PC_BASE)
  /** Peripheral LPCAC_PS base address */
  #define LPCAC_PS_BASE                            (0x44400800u)
  /** Peripheral LPCAC_PS base pointer */
  #define LPCAC_PS                                 ((XCACHE_Type *)LPCAC_PS_BASE)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { LPCAC_PC_BASE, LPCAC_PS_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { LPCAC_PC, LPCAC_PS }
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES                { 0x10000000u, 0x30000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES                { 0x20000000u, 0xE0000000u }
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES_NS             { 0x00000000u, 0x20000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES_NS             { 0x20000000u, 0xE0000000u }
#else
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES                { 0x00000000u, 0x20000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES                { 0x20000000u, 0xE0000000u }
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


#endif  /* MIMX9352_CM33_COMMON_H_ */
