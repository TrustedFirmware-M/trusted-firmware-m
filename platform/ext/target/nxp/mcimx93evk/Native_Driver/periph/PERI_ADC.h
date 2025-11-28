/*
** ###################################################################
**     Processors:          MIMX9301CVVXD_ca55
**                          MIMX9301CVVXD_cm33
**                          MIMX9301DVVXD_ca55
**                          MIMX9301DVVXD_cm33
**                          MIMX9302CVVXD_ca55
**                          MIMX9302CVVXD_cm33
**                          MIMX9302DVVXD_ca55
**                          MIMX9302DVVXD_cm33
**                          MIMX9311CVXXM_ca55
**                          MIMX9311CVXXM_cm33
**                          MIMX9311DVXXM_ca55
**                          MIMX9311DVXXM_cm33
**                          MIMX9311XVXXM_ca55
**                          MIMX9311XVXXM_cm33
**                          MIMX9312CVXXM_ca55
**                          MIMX9312CVXXM_cm33
**                          MIMX9312DVXXM_ca55
**                          MIMX9312DVXXM_cm33
**                          MIMX9312XVXXM_ca55
**                          MIMX9312XVXXM_cm33
**                          MIMX9321CVXXM_ca55
**                          MIMX9321CVXXM_cm33
**                          MIMX9321DVXXM_ca55
**                          MIMX9321DVXXM_cm33
**                          MIMX9321XVXXM_ca55
**                          MIMX9321XVXXM_cm33
**                          MIMX9322CVXXM_ca55
**                          MIMX9322CVXXM_cm33
**                          MIMX9322DVXXM_ca55
**                          MIMX9322DVXXM_cm33
**                          MIMX9322XVXXM_ca55
**                          MIMX9322XVXXM_cm33
**                          MIMX9331AVTXM_ca55
**                          MIMX9331AVTXM_cm33
**                          MIMX9331CVVXM_ca55
**                          MIMX9331CVVXM_cm33
**                          MIMX9331DVVXM_ca55
**                          MIMX9331DVVXM_cm33
**                          MIMX9331XVVXM_ca55
**                          MIMX9331XVVXM_cm33
**                          MIMX9332AVTXM_ca55
**                          MIMX9332AVTXM_cm33
**                          MIMX9332CVVXM_ca55
**                          MIMX9332CVVXM_cm33
**                          MIMX9332DVVXM_ca55
**                          MIMX9332DVVXM_cm33
**                          MIMX9332XVVXM_ca55
**                          MIMX9332XVVXM_cm33
**                          MIMX9351AVTXM_ca55
**                          MIMX9351AVTXM_cm33
**                          MIMX9351CVVXM_ca55
**                          MIMX9351CVVXM_cm33
**                          MIMX9351DVVXM_ca55
**                          MIMX9351DVVXM_cm33
**                          MIMX9351XVVXM_ca55
**                          MIMX9351XVVXM_cm33
**                          MIMX9352AVTXM_ca55
**                          MIMX9352AVTXM_cm33
**                          MIMX9352CVVXM_ca55
**                          MIMX9352CVVXM_cm33
**                          MIMX9352DVVXM_ca55
**                          MIMX9352DVVXM_cm33
**                          MIMX9352XVVXM_ca55
**                          MIMX9352XVVXM_cm33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ADC
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
 * @file PERI_ADC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9301CVVXD_ca55) || defined(CPU_MIMX9301DVVXD_ca55))
#include "MIMX9301_ca55_COMMON.h"
#elif (defined(CPU_MIMX9301CVVXD_cm33) || defined(CPU_MIMX9301DVVXD_cm33))
#include "MIMX9301_cm33_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_ca55) || defined(CPU_MIMX9302DVVXD_ca55))
#include "MIMX9302_ca55_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_cm33) || defined(CPU_MIMX9302DVVXD_cm33))
#include "MIMX9302_cm33_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_ca55) || defined(CPU_MIMX9311DVXXM_ca55) || defined(CPU_MIMX9311XVXXM_ca55))
#include "MIMX9311_ca55_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_cm33) || defined(CPU_MIMX9311DVXXM_cm33) || defined(CPU_MIMX9311XVXXM_cm33))
#include "MIMX9311_cm33_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_ca55) || defined(CPU_MIMX9312DVXXM_ca55) || defined(CPU_MIMX9312XVXXM_ca55))
#include "MIMX9312_ca55_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_cm33) || defined(CPU_MIMX9312DVXXM_cm33) || defined(CPU_MIMX9312XVXXM_cm33))
#include "MIMX9312_cm33_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_ca55) || defined(CPU_MIMX9321DVXXM_ca55) || defined(CPU_MIMX9321XVXXM_ca55))
#include "MIMX9321_ca55_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_cm33) || defined(CPU_MIMX9321DVXXM_cm33) || defined(CPU_MIMX9321XVXXM_cm33))
#include "MIMX9321_cm33_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_ca55) || defined(CPU_MIMX9322DVXXM_ca55) || defined(CPU_MIMX9322XVXXM_ca55))
#include "MIMX9322_ca55_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_cm33) || defined(CPU_MIMX9322DVXXM_cm33) || defined(CPU_MIMX9322XVXXM_cm33))
#include "MIMX9322_cm33_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_ca55) || defined(CPU_MIMX9331CVVXM_ca55) || defined(CPU_MIMX9331DVVXM_ca55) || defined(CPU_MIMX9331XVVXM_ca55))
#include "MIMX9331_ca55_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_cm33) || defined(CPU_MIMX9331CVVXM_cm33) || defined(CPU_MIMX9331DVVXM_cm33) || defined(CPU_MIMX9331XVVXM_cm33))
#include "MIMX9331_cm33_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_ca55) || defined(CPU_MIMX9332CVVXM_ca55) || defined(CPU_MIMX9332DVVXM_ca55) || defined(CPU_MIMX9332XVVXM_ca55))
#include "MIMX9332_ca55_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_cm33) || defined(CPU_MIMX9332CVVXM_cm33) || defined(CPU_MIMX9332DVVXM_cm33) || defined(CPU_MIMX9332XVVXM_cm33))
#include "MIMX9332_cm33_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_ca55) || defined(CPU_MIMX9351CVVXM_ca55) || defined(CPU_MIMX9351DVVXM_ca55) || defined(CPU_MIMX9351XVVXM_ca55))
#include "MIMX9351_ca55_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_cm33) || defined(CPU_MIMX9351CVVXM_cm33) || defined(CPU_MIMX9351DVVXM_cm33) || defined(CPU_MIMX9351XVVXM_cm33))
#include "MIMX9351_cm33_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_ca55) || defined(CPU_MIMX9352CVVXM_ca55) || defined(CPU_MIMX9352DVVXM_ca55) || defined(CPU_MIMX9352XVVXM_ca55))
#include "MIMX9352_ca55_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_cm33) || defined(CPU_MIMX9352CVVXM_cm33) || defined(CPU_MIMX9352DVVXM_cm33) || defined(CPU_MIMX9352XVVXM_cm33))
#include "MIMX9352_cm33_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Size of Registers Arrays */
#define ADC_CDR0_COUNT                            8u
#define ADC_CDR32_COUNT                           8u

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Main Configuration, offset: 0x0 */
  __IO uint32_t MSR;                               /**< Main Status, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t ISR;                               /**< Interrupt Status, offset: 0x10 */
  __IO uint32_t CEOCFR0;                           /**< Channel Pending 0, offset: 0x14 */
  __IO uint32_t CEOCFR1;                           /**< Channel Pending 1, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t IMR;                               /**< Interrupt Mask, offset: 0x20 */
  __IO uint32_t CIMR0;                             /**< Channel Interrupt Mask 0, offset: 0x24 */
  __IO uint32_t CIMR1;                             /**< Channel Interrupt Mask 1, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t WTISR;                             /**< Watchdog Threshold Interrupt Status, offset: 0x30 */
  __IO uint32_t WTIMR;                             /**< Watchdog Threshold Interrupt Mask, offset: 0x34 */
       uint8_t RESERVED_3[8];
  __IO uint32_t DMAE;                              /**< DMAE, offset: 0x40 */
  __IO uint32_t DMAR0;                             /**< DMA 0, offset: 0x44 */
  __IO uint32_t DMAR1;                             /**< DMA 1, offset: 0x48 */
       uint8_t RESERVED_4[20];
  __IO uint32_t THRHLR0;                           /**< Analog Watchdog Threshold 0, offset: 0x60 */
  __IO uint32_t THRHLR1;                           /**< Analog Watchdog Threshold 1, offset: 0x64 */
  __IO uint32_t THRHLR2;                           /**< Analog Watchdog Threshold 2, offset: 0x68 */
  __IO uint32_t THRHLR3;                           /**< Analog Watchdog Threshold 3, offset: 0x6C */
       uint8_t RESERVED_5[16];
  __IO uint32_t PSCR;                              /**< Presampling Control, offset: 0x80 */
  __IO uint32_t PSR0;                              /**< Presampling 0, offset: 0x84 */
  __IO uint32_t PSR1;                              /**< Presampling 1, offset: 0x88 */
       uint8_t RESERVED_6[8];
  __IO uint32_t CTR0;                              /**< Conversion Timing 0, offset: 0x94 */
  __IO uint32_t CTR1;                              /**< Conversion Timing 1, offset: 0x98 */
       uint8_t RESERVED_7[8];
  __IO uint32_t NCMR0;                             /**< Normal Conversion Mask 0, offset: 0xA4 */
  __IO uint32_t NCMR1;                             /**< Normal Conversion Mask 1, offset: 0xA8 */
       uint8_t RESERVED_8[8];
  __IO uint32_t JCMR0;                             /**< Injected Conversion Mask 0, offset: 0xB4 */
  __IO uint32_t JCMR1;                             /**< Injected Conversion Mask 1, offset: 0xB8 */
       uint8_t RESERVED_9[4];
  __IO uint32_t USROFSGN;                          /**< User OFFSET and Gain, offset: 0xC0 */
       uint8_t RESERVED_10[4];
  __IO uint32_t PDEDR;                             /**< Power Down Exit Delay, offset: 0xC8 */
       uint8_t RESERVED_11[52];
  __I  uint32_t PCDR[ADC_CDR0_COUNT];              /**< Precision Channel n Data, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_12[96];
  __I  uint32_t ICDR[ADC_CDR32_COUNT];             /**< Internal Channel n Data, array offset: 0x180, array step: 0x4 */
       uint8_t RESERVED_13[224];
  __IO uint32_t THRHLR4;                           /**< Analog Watchdog Threshold 4, offset: 0x280 */
  __IO uint32_t THRHLR5;                           /**< Analog Watchdog Threshold 5, offset: 0x284 */
  __IO uint32_t THRHLR6;                           /**< Analog Watchdog Threshold 6, offset: 0x288 */
  __IO uint32_t THRHLR7;                           /**< Analog Watchdog Threshold 7, offset: 0x28C */
       uint8_t RESERVED_14[32];
  __IO uint32_t CWSELR0;                           /**< Channel Watchdog Select 0, offset: 0x2B0 */
       uint8_t RESERVED_15[12];
  __IO uint32_t CWSELR4;                           /**< Channel Watchdog Select 4, offset: 0x2C0 */
       uint8_t RESERVED_16[28];
  __IO uint32_t CWENR0;                            /**< Channel Watchdog Enable 0, offset: 0x2E0 */
  __IO uint32_t CWENR1;                            /**< Channel Watchdog Enable 1, offset: 0x2E4 */
       uint8_t RESERVED_17[8];
  __IO uint32_t AWORR0;                            /**< Analog Watchdog Out of Range 0, offset: 0x2F0 */
  __IO uint32_t AWORR1;                            /**< Analog Watchdog Out of Range 1, offset: 0x2F4 */
       uint8_t RESERVED_18[72];
  __IO uint32_t STCR1;                             /**< Self-Test Configuration 1, offset: 0x340 */
  __IO uint32_t STCR2;                             /**< Self-Test Configuration 2, offset: 0x344 */
  __IO uint32_t STCR3;                             /**< Self-Test Configuration 3, offset: 0x348 */
  __IO uint32_t STBRR;                             /**< Self-Test Baud Rate, offset: 0x34C */
  __IO uint32_t STSR1;                             /**< Self-Test Status 1, offset: 0x350 */
  __I  uint32_t STSR2;                             /**< Self-Test Status 2, offset: 0x354 */
  __I  uint32_t STSR3;                             /**< Self-Test Status 3, offset: 0x358 */
  __I  uint32_t STSR4;                             /**< Self-Test Status 4, offset: 0x35C */
       uint8_t RESERVED_19[16];
  __I  uint32_t STDR1;                             /**< Self-Test Data 1, offset: 0x370 */
  __I  uint32_t STDR2;                             /**< Self-Test Data 2, offset: 0x374 */
       uint8_t RESERVED_20[8];
  __IO uint32_t STAW0R;                            /**< Self-Test Analog Watchdog 0, offset: 0x380 */
  __IO uint32_t STAW1AR;                           /**< Self-Test Analog Watchdog 1A, offset: 0x384 */
  __IO uint32_t STAW1BR;                           /**< Self-Test Analog Watchdog 1B, offset: 0x388 */
  __IO uint32_t STAW2R;                            /**< Self-Test Analog Watchdog 2, offset: 0x38C */
       uint32_t STAW3R;                            /**< Self-Test Analog Watchdog 3, offset: 0x390 */
  __IO uint32_t STAW4R;                            /**< Self-Test Analog Watchdog 4, offset: 0x394 */
  __IO uint32_t STAW5R;                            /**< Self-Test Analog Watchdog 5, offset: 0x398 */
  __I  uint32_t CALSTAT;                           /**< Calibration Status, offset: 0x39C */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name MCR - Main Configuration */
/*! @{ */

#define ADC_MCR_PWDN_MASK                        (0x1U)
#define ADC_MCR_PWDN_SHIFT                       (0U)
/*! PWDN - Power-Down Enable
 *  0b0..When ADC status is in Power-down mode (MSR[ADCSTATUS] = 001b), start ADC transition to IDLE mode
 *  0b1..Request to enter Power-down mode
 */
#define ADC_MCR_PWDN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_PWDN_SHIFT)) & ADC_MCR_PWDN_MASK)

#define ADC_MCR_ACKO_MASK                        (0x20U)
#define ADC_MCR_ACKO_SHIFT                       (5U)
/*! ACKO - Auto-Clock-Off Mode Enable
 *  0b0..Auto-Clock-Off feature is disabled
 *  0b1..Auto-Clock-Off feature is enabled
 */
#define ADC_MCR_ACKO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ACKO_SHIFT)) & ADC_MCR_ACKO_MASK)

#define ADC_MCR_ABORT_MASK                       (0x40U)
#define ADC_MCR_ABORT_SHIFT                      (6U)
/*! ABORT - Abort Conversion
 *  0b0..Channel conversion has been aborted, or channel conversion is not currently running
 *  0b1..Abort current channel conversion
 */
#define ADC_MCR_ABORT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ABORT_SHIFT)) & ADC_MCR_ABORT_MASK)

#define ADC_MCR_ABORTCHAIN_MASK                  (0x80U)
#define ADC_MCR_ABORTCHAIN_SHIFT                 (7U)
/*! ABORTCHAIN - Abort Conversion Chain
 *  0b0..Chain conversion aborted or is currently not running
 *  0b1..Abort current chain conversion
 */
#define ADC_MCR_ABORTCHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ABORTCHAIN_SHIFT)) & ADC_MCR_ABORTCHAIN_MASK)

#define ADC_MCR_ADCLKSE_MASK                     (0x100U)
#define ADC_MCR_ADCLKSE_SHIFT                    (8U)
/*! ADCLKSE - Analog Clock Frequency Select
 *  0b0..AD_CLK frequency is half
 *  0b1..AD_CLK frequency is equal to bus clock frequency
 */
#define ADC_MCR_ADCLKSE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ADCLKSE_SHIFT)) & ADC_MCR_ADCLKSE_MASK)

#define ADC_MCR_TSAMP_MASK                       (0x600U)
#define ADC_MCR_TSAMP_SHIFT                      (9U)
/*! TSAMP - Sample Time for Calibration
 *  0b00..22 cycles of AD_CLK (default)
 *  0b01..8 cycles of AD_CLK
 *  0b10..16 cycle of AD_CLK
 *  0b11..32 cycle of AD_CLK
 */
#define ADC_MCR_TSAMP(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_TSAMP_SHIFT)) & ADC_MCR_TSAMP_MASK)

#define ADC_MCR_NRSMPL_MASK                      (0x1800U)
#define ADC_MCR_NRSMPL_SHIFT                     (11U)
/*! NRSMPL - Number of Averaging Samples
 *  0b00..16
 *  0b01..32
 *  0b10..128
 *  0b11..512
 */
#define ADC_MCR_NRSMPL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_NRSMPL_SHIFT)) & ADC_MCR_NRSMPL_MASK)

#define ADC_MCR_AVGEN_MASK                       (0x2000U)
#define ADC_MCR_AVGEN_SHIFT                      (13U)
/*! AVGEN - Average Enable
 *  0b0..Disable
 *  0b1..Enable (default)
 */
#define ADC_MCR_AVGEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_AVGEN_SHIFT)) & ADC_MCR_AVGEN_MASK)

#define ADC_MCR_CALSTART_MASK                    (0x4000U)
#define ADC_MCR_CALSTART_SHIFT                   (14U)
/*! CALSTART - Calibration Start
 *  0b0..No effect
 *  0b1..Start calibration
 */
#define ADC_MCR_CALSTART(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_MCR_CALSTART_SHIFT)) & ADC_MCR_CALSTART_MASK)

#define ADC_MCR_STCL_MASK                        (0x8000U)
#define ADC_MCR_STCL_SHIFT                       (15U)
/*! STCL - Self-Testing Configuration Lock
 *  0b0..Not locked
 *  0b1..Locked
 */
#define ADC_MCR_STCL(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_STCL_SHIFT)) & ADC_MCR_STCL_MASK)

#define ADC_MCR_JSTART_MASK                      (0x100000U)
#define ADC_MCR_JSTART_SHIFT                     (20U)
/*! JSTART - Start Injection Conversion */
#define ADC_MCR_JSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_JSTART_SHIFT)) & ADC_MCR_JSTART_MASK)

#define ADC_MCR_NSTART_MASK                      (0x1000000U)
#define ADC_MCR_NSTART_SHIFT                     (24U)
/*! NSTART - Normal Conversion Start */
#define ADC_MCR_NSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_NSTART_SHIFT)) & ADC_MCR_NSTART_MASK)

#define ADC_MCR_EDGE_MASK                        (0x4000000U)
#define ADC_MCR_EDGE_SHIFT                       (26U)
/*! EDGE - Trigger Edge Select
 *  0b0..Falling edge is trigger
 *  0b1..Rising edge is trigger
 */
#define ADC_MCR_EDGE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_EDGE_SHIFT)) & ADC_MCR_EDGE_MASK)

#define ADC_MCR_TRGEN_MASK                       (0x8000000U)
#define ADC_MCR_TRGEN_SHIFT                      (27U)
/*! TRGEN - External Trigger Enable
 *  0b0..External trigger is disabled
 *  0b1..Enables the external trigger to start a conversion
 */
#define ADC_MCR_TRGEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_TRGEN_SHIFT)) & ADC_MCR_TRGEN_MASK)

#define ADC_MCR_MODE_MASK                        (0x20000000U)
#define ADC_MCR_MODE_SHIFT                       (29U)
/*! MODE - Normal Scan Mode Select
 *  0b0..One-Shot Operation mode
 *  0b1..Scan Operation mode
 */
#define ADC_MCR_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_MODE_SHIFT)) & ADC_MCR_MODE_MASK)

#define ADC_MCR_WLSIDE_MASK                      (0x40000000U)
#define ADC_MCR_WLSIDE_SHIFT                     (30U)
/*! WLSIDE - Write Left Side
 *  0b0..Write right-aligned conversion data (from 11 to 0)
 *  0b1..Write left-aligned conversion data (from 15 to 4)
 */
#define ADC_MCR_WLSIDE(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_WLSIDE_SHIFT)) & ADC_MCR_WLSIDE_MASK)

#define ADC_MCR_OWREN_MASK                       (0x80000000U)
#define ADC_MCR_OWREN_SHIFT                      (31U)
/*! OWREN - Overwrite Enable
 *  0b0..Older valid conversion data is not overwritten by newer conversion data
 *  0b1..Newer conversion result is always overwritten, irrespective of the validity of older conversion data
 */
#define ADC_MCR_OWREN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_OWREN_SHIFT)) & ADC_MCR_OWREN_MASK)
/*! @} */

/*! @name MSR - Main Status */
/*! @{ */

#define ADC_MSR_ADCSTATUS_MASK                   (0x7U)
#define ADC_MSR_ADCSTATUS_SHIFT                  (0U)
/*! ADCSTATUS - ADC Status
 *  0b000..Idle
 *  0b001..Power-down
 *  0b010..Wait state (waiting to start conversion after [external trigger]).
 *  0b011..Busy in calibration
 *  0b100..Sample
 *  0b110..Conversion
 */
#define ADC_MSR_ADCSTATUS(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_MSR_ADCSTATUS_SHIFT)) & ADC_MSR_ADCSTATUS_MASK)

#define ADC_MSR_ACKO_MASK                        (0x20U)
#define ADC_MSR_ACKO_SHIFT                       (5U)
/*! ACKO - Auto-Clock-Off Enable
 *  0b0..Auto-Clock-Off feature is not enabled
 *  0b1..Auto-Clock-Off feature is enabled
 */
#define ADC_MSR_ACKO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MSR_ACKO_SHIFT)) & ADC_MSR_ACKO_MASK)

#define ADC_MSR_CHADDR_MASK                      (0xFE00U)
#define ADC_MSR_CHADDR_SHIFT                     (9U)
/*! CHADDR - Channel Address
 *  0b0000000..Channel 0 selected
 *  0b0000001..Channel 1 selected
 *  0b0000010..Channel 2 selected
 *  0b0000011..Channel 3 selected
 *  0b0000100..Channel 4 selected
 *  0b0000101..Channel 5 selected
 *  0b0000110..Channel 6 selected
 *  0b0000111..Channel 7 selected
 *  0b0001000..Reserved
 *  0b0001001..Reserved
 *  0b0001010..Reserved
 *  0b0001011..Bandgap input selected
 *  0b0001100..Pre-sample voltage - 1 : DVDD1P0/2
 *  0b0001101..Pre-sample voltage - 2 : AVDD1p8/4
 *  0b0001110..Pre-sample voltage - 3 : VREFL_1p8
 *  0b0001111..Pre-sample voltage - 4 : VREFH_1p8
 */
#define ADC_MSR_CHADDR(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_CHADDR_SHIFT)) & ADC_MSR_CHADDR_MASK)

#define ADC_MSR_SELF_TEST_S_MASK                 (0x40000U)
#define ADC_MSR_SELF_TEST_S_SHIFT                (18U)
/*! SELF_TEST_S - Self-Test Status
 *  0b0..Self-test conversion is not in process
 *  0b1..Self-test conversion is in process
 */
#define ADC_MSR_SELF_TEST_S(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_MSR_SELF_TEST_S_SHIFT)) & ADC_MSR_SELF_TEST_S_MASK)

#define ADC_MSR_JSTART_MASK                      (0x100000U)
#define ADC_MSR_JSTART_SHIFT                     (20U)
/*! JSTART - Injected Conversion Status
 *  0b0..Injected conversion is not in process
 *  0b1..Injected conversion is in process
 */
#define ADC_MSR_JSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_JSTART_SHIFT)) & ADC_MSR_JSTART_MASK)

#define ADC_MSR_JABORT_MASK                      (0x800000U)
#define ADC_MSR_JABORT_SHIFT                     (23U)
/*! JABORT - Injected Conversion Abort Status
 *  0b0..Injected conversion has not been aborted
 *  0b1..Injected conversion has been aborted
 */
#define ADC_MSR_JABORT(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_JABORT_SHIFT)) & ADC_MSR_JABORT_MASK)

#define ADC_MSR_NSTART_MASK                      (0x1000000U)
#define ADC_MSR_NSTART_SHIFT                     (24U)
/*! NSTART - Normal Conversion Status
 *  0b0..Normal conversion is not in process
 *  0b1..Normal conversion is in process
 */
#define ADC_MSR_NSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_NSTART_SHIFT)) & ADC_MSR_NSTART_MASK)

#define ADC_MSR_CALBUSY_MASK                     (0x20000000U)
#define ADC_MSR_CALBUSY_SHIFT                    (29U)
/*! CALBUSY - Calibration Busy
 *  0b0..ADC is ready for use
 *  0b1..ADC is busy in a calibration process
 */
#define ADC_MSR_CALBUSY(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_MSR_CALBUSY_SHIFT)) & ADC_MSR_CALBUSY_MASK)

#define ADC_MSR_CALFAIL_MASK                     (0x40000000U)
#define ADC_MSR_CALFAIL_SHIFT                    (30U)
/*! CALFAIL - Calibration Failed
 *  0b0..Calibration passed (must be checked with CALBUSY = 0b)
 *  0b0..No effect
 *  0b1..Calibration failed
 *  0b1..Clear the flag
 */
#define ADC_MSR_CALFAIL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_MSR_CALFAIL_SHIFT)) & ADC_MSR_CALFAIL_MASK)

#define ADC_MSR_CALIBRTD_MASK                    (0x80000000U)
#define ADC_MSR_CALIBRTD_SHIFT                   (31U)
/*! CALIBRTD - Calibration Status
 *  0b0..Uncalibrated or calibration unsuccessful
 *  0b1..Calibrated or calibration successful
 */
#define ADC_MSR_CALIBRTD(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_MSR_CALIBRTD_SHIFT)) & ADC_MSR_CALIBRTD_MASK)
/*! @} */

/*! @name ISR - Interrupt Status */
/*! @{ */

#define ADC_ISR_ECH_MASK                         (0x1U)
#define ADC_ISR_ECH_SHIFT                        (0U)
/*! ECH - End of Conversion Chain
 *  0b0..End of conversion chain has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..End of conversion chain has occurred
 */
#define ADC_ISR_ECH(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_ISR_ECH_SHIFT)) & ADC_ISR_ECH_MASK)

#define ADC_ISR_EOC_MASK                         (0x2U)
#define ADC_ISR_EOC_SHIFT                        (1U)
/*! EOC - End of Channel Conversion
 *  0b0..Channel end of conversion has not occurred
 *  0b0..No effect
 *  0b1..Channel end of conversion has occurred
 *  0b1..Clear the flag
 */
#define ADC_ISR_EOC(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_ISR_EOC_SHIFT)) & ADC_ISR_EOC_MASK)

#define ADC_ISR_JECH_MASK                        (0x4U)
#define ADC_ISR_JECH_SHIFT                       (2U)
/*! JECH - Injected End of Conversion Chain
 *  0b0..Injected channel end of conversion chain has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Injected channel end of conversion chain has occurred
 */
#define ADC_ISR_JECH(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_ISR_JECH_SHIFT)) & ADC_ISR_JECH_MASK)

#define ADC_ISR_JEOC_MASK                        (0x8U)
#define ADC_ISR_JEOC_SHIFT                       (3U)
/*! JEOC - Injected Channel End of Conversion
 *  0b0..Injected channel end of conversion has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Injected channel end of conversion has occurred
 */
#define ADC_ISR_JEOC(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_ISR_JEOC_SHIFT)) & ADC_ISR_JEOC_MASK)
/*! @} */

/*! @name CEOCFR0 - Channel Pending 0 */
/*! @{ */

#define ADC_CEOCFR0_EOC_CH0_MASK                 (0x1U)
#define ADC_CEOCFR0_EOC_CH0_SHIFT                (0U)
/*! EOC_CH0 - Channel 0 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH0_SHIFT)) & ADC_CEOCFR0_EOC_CH0_MASK)

#define ADC_CEOCFR0_EOC_CH1_MASK                 (0x2U)
#define ADC_CEOCFR0_EOC_CH1_SHIFT                (1U)
/*! EOC_CH1 - Channel 1 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH1_SHIFT)) & ADC_CEOCFR0_EOC_CH1_MASK)

#define ADC_CEOCFR0_EOC_CH2_MASK                 (0x4U)
#define ADC_CEOCFR0_EOC_CH2_SHIFT                (2U)
/*! EOC_CH2 - Channel 2 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH2_SHIFT)) & ADC_CEOCFR0_EOC_CH2_MASK)

#define ADC_CEOCFR0_EOC_CH3_MASK                 (0x8U)
#define ADC_CEOCFR0_EOC_CH3_SHIFT                (3U)
/*! EOC_CH3 - Channel 3 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH3_SHIFT)) & ADC_CEOCFR0_EOC_CH3_MASK)

#define ADC_CEOCFR0_EOC_CH4_MASK                 (0x10U)
#define ADC_CEOCFR0_EOC_CH4_SHIFT                (4U)
/*! EOC_CH4 - Channel 4 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH4_SHIFT)) & ADC_CEOCFR0_EOC_CH4_MASK)

#define ADC_CEOCFR0_EOC_CH5_MASK                 (0x20U)
#define ADC_CEOCFR0_EOC_CH5_SHIFT                (5U)
/*! EOC_CH5 - Channel 5 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH5_SHIFT)) & ADC_CEOCFR0_EOC_CH5_MASK)

#define ADC_CEOCFR0_EOC_CH6_MASK                 (0x40U)
#define ADC_CEOCFR0_EOC_CH6_SHIFT                (6U)
/*! EOC_CH6 - Channel 6 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH6_SHIFT)) & ADC_CEOCFR0_EOC_CH6_MASK)

#define ADC_CEOCFR0_EOC_CH7_MASK                 (0x80U)
#define ADC_CEOCFR0_EOC_CH7_SHIFT                (7U)
/*! EOC_CH7 - Channel 7 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_EOC_CH7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_EOC_CH7_SHIFT)) & ADC_CEOCFR0_EOC_CH7_MASK)
/*! @} */

/*! @name CEOCFR1 - Channel Pending 1 */
/*! @{ */

#define ADC_CEOCFR1_EOC_CH32_MASK                (0x1U)
#define ADC_CEOCFR1_EOC_CH32_SHIFT               (0U)
/*! EOC_CH32 - Channel 32 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH32(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH32_SHIFT)) & ADC_CEOCFR1_EOC_CH32_MASK)

#define ADC_CEOCFR1_EOC_CH33_MASK                (0x2U)
#define ADC_CEOCFR1_EOC_CH33_SHIFT               (1U)
/*! EOC_CH33 - Channel 33 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH33(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH33_SHIFT)) & ADC_CEOCFR1_EOC_CH33_MASK)

#define ADC_CEOCFR1_EOC_CH34_MASK                (0x4U)
#define ADC_CEOCFR1_EOC_CH34_SHIFT               (2U)
/*! EOC_CH34 - Channel 34 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH34(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH34_SHIFT)) & ADC_CEOCFR1_EOC_CH34_MASK)

#define ADC_CEOCFR1_EOC_CH35_MASK                (0x8U)
#define ADC_CEOCFR1_EOC_CH35_SHIFT               (3U)
/*! EOC_CH35 - Channel 35 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH35(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH35_SHIFT)) & ADC_CEOCFR1_EOC_CH35_MASK)

#define ADC_CEOCFR1_EOC_CH36_MASK                (0x10U)
#define ADC_CEOCFR1_EOC_CH36_SHIFT               (4U)
/*! EOC_CH36 - Channel 36 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH36(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH36_SHIFT)) & ADC_CEOCFR1_EOC_CH36_MASK)

#define ADC_CEOCFR1_EOC_CH37_MASK                (0x20U)
#define ADC_CEOCFR1_EOC_CH37_SHIFT               (5U)
/*! EOC_CH37 - Channel 37 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH37(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH37_SHIFT)) & ADC_CEOCFR1_EOC_CH37_MASK)

#define ADC_CEOCFR1_EOC_CH38_MASK                (0x40U)
#define ADC_CEOCFR1_EOC_CH38_SHIFT               (6U)
/*! EOC_CH38 - Channel 38 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH38(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH38_SHIFT)) & ADC_CEOCFR1_EOC_CH38_MASK)

#define ADC_CEOCFR1_EOC_CH39_MASK                (0x80U)
#define ADC_CEOCFR1_EOC_CH39_SHIFT               (7U)
/*! EOC_CH39 - Channel 39 EOC Status
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_EOC_CH39(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_EOC_CH39_SHIFT)) & ADC_CEOCFR1_EOC_CH39_MASK)
/*! @} */

/*! @name IMR - Interrupt Mask */
/*! @{ */

#define ADC_IMR_MSKECH_MASK                      (0x1U)
#define ADC_IMR_MSKECH_SHIFT                     (0U)
/*! MSKECH - End of Chain Conversion Interrupt Mask
 *  0b0..End of chain conversion interrupt disabled
 *  0b1..End of chain conversion interrupt enabled
 */
#define ADC_IMR_MSKECH(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKECH_SHIFT)) & ADC_IMR_MSKECH_MASK)

#define ADC_IMR_MSKEOC_MASK                      (0x2U)
#define ADC_IMR_MSKEOC_SHIFT                     (1U)
/*! MSKEOC - End of Conversion Interrupt Mask
 *  0b0..End of conversion interrupt disabled
 *  0b1..End of conversion interrupt enabled
 */
#define ADC_IMR_MSKEOC(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKEOC_SHIFT)) & ADC_IMR_MSKEOC_MASK)

#define ADC_IMR_MSKJECH_MASK                     (0x4U)
#define ADC_IMR_MSKJECH_SHIFT                    (2U)
/*! MSKJECH - End of Injected Chain Conversion Interrupt Mask
 *  0b0..End of injected chain conversion interrupt disabled
 *  0b1..End of injected chain conversion interrupt enabled
 */
#define ADC_IMR_MSKJECH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKJECH_SHIFT)) & ADC_IMR_MSKJECH_MASK)

#define ADC_IMR_MSKJEOC_MASK                     (0x8U)
#define ADC_IMR_MSKJEOC_SHIFT                    (3U)
/*! MSKJEOC - End of Injected Conversion Interrupt Mask
 *  0b0..End of injected conversion interrupt disabled
 *  0b1..End of injected conversion interrupt enabled
 */
#define ADC_IMR_MSKJEOC(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKJEOC_SHIFT)) & ADC_IMR_MSKJEOC_MASK)
/*! @} */

/*! @name CIMR0 - Channel Interrupt Mask 0 */
/*! @{ */

#define ADC_CIMR0_CIM0_MASK                      (0x1U)
#define ADC_CIMR0_CIM0_SHIFT                     (0U)
/*! CIM0 - Channel 0 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM0(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM0_SHIFT)) & ADC_CIMR0_CIM0_MASK)

#define ADC_CIMR0_CIM1_MASK                      (0x2U)
#define ADC_CIMR0_CIM1_SHIFT                     (1U)
/*! CIM1 - Channel 1 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM1(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM1_SHIFT)) & ADC_CIMR0_CIM1_MASK)

#define ADC_CIMR0_CIM2_MASK                      (0x4U)
#define ADC_CIMR0_CIM2_SHIFT                     (2U)
/*! CIM2 - Channel 2 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM2(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM2_SHIFT)) & ADC_CIMR0_CIM2_MASK)

#define ADC_CIMR0_CIM3_MASK                      (0x8U)
#define ADC_CIMR0_CIM3_SHIFT                     (3U)
/*! CIM3 - Channel 3 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM3(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM3_SHIFT)) & ADC_CIMR0_CIM3_MASK)

#define ADC_CIMR0_CIM4_MASK                      (0x10U)
#define ADC_CIMR0_CIM4_SHIFT                     (4U)
/*! CIM4 - Channel 4 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM4(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM4_SHIFT)) & ADC_CIMR0_CIM4_MASK)

#define ADC_CIMR0_CIM5_MASK                      (0x20U)
#define ADC_CIMR0_CIM5_SHIFT                     (5U)
/*! CIM5 - Channel 5 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM5(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM5_SHIFT)) & ADC_CIMR0_CIM5_MASK)

#define ADC_CIMR0_CIM6_MASK                      (0x40U)
#define ADC_CIMR0_CIM6_SHIFT                     (6U)
/*! CIM6 - Channel 6 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM6(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM6_SHIFT)) & ADC_CIMR0_CIM6_MASK)

#define ADC_CIMR0_CIM7_MASK                      (0x80U)
#define ADC_CIMR0_CIM7_SHIFT                     (7U)
/*! CIM7 - Channel 7 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR0_CIM7(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_CIM7_SHIFT)) & ADC_CIMR0_CIM7_MASK)
/*! @} */

/*! @name CIMR1 - Channel Interrupt Mask 1 */
/*! @{ */

#define ADC_CIMR1_CIM32_MASK                     (0x1U)
#define ADC_CIMR1_CIM32_SHIFT                    (0U)
/*! CIM32 - Channel 32 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM32(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM32_SHIFT)) & ADC_CIMR1_CIM32_MASK)

#define ADC_CIMR1_CIM33_MASK                     (0x2U)
#define ADC_CIMR1_CIM33_SHIFT                    (1U)
/*! CIM33 - Channel 33 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM33(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM33_SHIFT)) & ADC_CIMR1_CIM33_MASK)

#define ADC_CIMR1_CIM34_MASK                     (0x4U)
#define ADC_CIMR1_CIM34_SHIFT                    (2U)
/*! CIM34 - Channel 34 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM34(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM34_SHIFT)) & ADC_CIMR1_CIM34_MASK)

#define ADC_CIMR1_CIM35_MASK                     (0x8U)
#define ADC_CIMR1_CIM35_SHIFT                    (3U)
/*! CIM35 - Channel 35 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM35(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM35_SHIFT)) & ADC_CIMR1_CIM35_MASK)

#define ADC_CIMR1_CIM36_MASK                     (0x10U)
#define ADC_CIMR1_CIM36_SHIFT                    (4U)
/*! CIM36 - Channel 36 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM36(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM36_SHIFT)) & ADC_CIMR1_CIM36_MASK)

#define ADC_CIMR1_CIM37_MASK                     (0x20U)
#define ADC_CIMR1_CIM37_SHIFT                    (5U)
/*! CIM37 - Channel 37 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM37(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM37_SHIFT)) & ADC_CIMR1_CIM37_MASK)

#define ADC_CIMR1_CIM38_MASK                     (0x40U)
#define ADC_CIMR1_CIM38_SHIFT                    (6U)
/*! CIM38 - Channel 38 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM38(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM38_SHIFT)) & ADC_CIMR1_CIM38_MASK)

#define ADC_CIMR1_CIM39_MASK                     (0x80U)
#define ADC_CIMR1_CIM39_SHIFT                    (7U)
/*! CIM39 - Channel 39 Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CIMR1_CIM39(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_CIM39_SHIFT)) & ADC_CIMR1_CIM39_MASK)
/*! @} */

/*! @name WTISR - Watchdog Threshold Interrupt Status */
/*! @{ */

#define ADC_WTISR_WDG0L_MASK                     (0x1U)
#define ADC_WTISR_WDG0L_SHIFT                    (0U)
/*! WDG0L - Channel 0 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG0L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG0L_SHIFT)) & ADC_WTISR_WDG0L_MASK)

#define ADC_WTISR_WDG0H_MASK                     (0x2U)
#define ADC_WTISR_WDG0H_SHIFT                    (1U)
/*! WDG0H - Channel 0 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG0H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG0H_SHIFT)) & ADC_WTISR_WDG0H_MASK)

#define ADC_WTISR_WDG1L_MASK                     (0x4U)
#define ADC_WTISR_WDG1L_SHIFT                    (2U)
/*! WDG1L - Channel 1 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG1L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG1L_SHIFT)) & ADC_WTISR_WDG1L_MASK)

#define ADC_WTISR_WDG1H_MASK                     (0x8U)
#define ADC_WTISR_WDG1H_SHIFT                    (3U)
/*! WDG1H - Channel 1 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG1H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG1H_SHIFT)) & ADC_WTISR_WDG1H_MASK)

#define ADC_WTISR_WDG2L_MASK                     (0x10U)
#define ADC_WTISR_WDG2L_SHIFT                    (4U)
/*! WDG2L - Channel 2 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG2L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG2L_SHIFT)) & ADC_WTISR_WDG2L_MASK)

#define ADC_WTISR_WDG2H_MASK                     (0x20U)
#define ADC_WTISR_WDG2H_SHIFT                    (5U)
/*! WDG2H - Channel 2 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG2H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG2H_SHIFT)) & ADC_WTISR_WDG2H_MASK)

#define ADC_WTISR_WDG3L_MASK                     (0x40U)
#define ADC_WTISR_WDG3L_SHIFT                    (6U)
/*! WDG3L - Channel 3 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG3L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG3L_SHIFT)) & ADC_WTISR_WDG3L_MASK)

#define ADC_WTISR_WDG3H_MASK                     (0x80U)
#define ADC_WTISR_WDG3H_SHIFT                    (7U)
/*! WDG3H - Channel 3 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG3H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG3H_SHIFT)) & ADC_WTISR_WDG3H_MASK)

#define ADC_WTISR_WDG4L_MASK                     (0x100U)
#define ADC_WTISR_WDG4L_SHIFT                    (8U)
/*! WDG4L - Channel 4 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG4L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG4L_SHIFT)) & ADC_WTISR_WDG4L_MASK)

#define ADC_WTISR_WDG4H_MASK                     (0x200U)
#define ADC_WTISR_WDG4H_SHIFT                    (9U)
/*! WDG4H - Channel 4 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG4H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG4H_SHIFT)) & ADC_WTISR_WDG4H_MASK)

#define ADC_WTISR_WDG5L_MASK                     (0x400U)
#define ADC_WTISR_WDG5L_SHIFT                    (10U)
/*! WDG5L - Channel 5 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG5L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG5L_SHIFT)) & ADC_WTISR_WDG5L_MASK)

#define ADC_WTISR_WDG5H_MASK                     (0x800U)
#define ADC_WTISR_WDG5H_SHIFT                    (11U)
/*! WDG5H - Channel 5 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG5H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG5H_SHIFT)) & ADC_WTISR_WDG5H_MASK)

#define ADC_WTISR_WDG6L_MASK                     (0x1000U)
#define ADC_WTISR_WDG6L_SHIFT                    (12U)
/*! WDG6L - Channel 6 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG6L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG6L_SHIFT)) & ADC_WTISR_WDG6L_MASK)

#define ADC_WTISR_WDG6H_MASK                     (0x2000U)
#define ADC_WTISR_WDG6H_SHIFT                    (13U)
/*! WDG6H - Channel 6 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG6H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG6H_SHIFT)) & ADC_WTISR_WDG6H_MASK)

#define ADC_WTISR_WDG7L_MASK                     (0x4000U)
#define ADC_WTISR_WDG7L_SHIFT                    (14U)
/*! WDG7L - Channel 7 Watchdog Low Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG7L(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG7L_SHIFT)) & ADC_WTISR_WDG7L_MASK)

#define ADC_WTISR_WDG7H_MASK                     (0x8000U)
#define ADC_WTISR_WDG7H_SHIFT                    (15U)
/*! WDG7H - Channel 7 Watchdog High Threshold Interrupt
 *  0b0..Interrupt not asserted
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt asserted
 */
#define ADC_WTISR_WDG7H(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_WDG7H_SHIFT)) & ADC_WTISR_WDG7H_MASK)
/*! @} */

/*! @name WTIMR - Watchdog Threshold Interrupt Mask */
/*! @{ */

#define ADC_WTIMR_MSKWDG0L_MASK                  (0x1U)
#define ADC_WTIMR_MSKWDG0L_SHIFT                 (0U)
/*! MSKWDG0L - Channel 0 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG0L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG0L_SHIFT)) & ADC_WTIMR_MSKWDG0L_MASK)

#define ADC_WTIMR_MSKWDG0H_MASK                  (0x2U)
#define ADC_WTIMR_MSKWDG0H_SHIFT                 (1U)
/*! MSKWDG0H - Channel 0 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG0H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG0H_SHIFT)) & ADC_WTIMR_MSKWDG0H_MASK)

#define ADC_WTIMR_MSKWDG1L_MASK                  (0x4U)
#define ADC_WTIMR_MSKWDG1L_SHIFT                 (2U)
/*! MSKWDG1L - Channel 1 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG1L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG1L_SHIFT)) & ADC_WTIMR_MSKWDG1L_MASK)

#define ADC_WTIMR_MSKWDG1H_MASK                  (0x8U)
#define ADC_WTIMR_MSKWDG1H_SHIFT                 (3U)
/*! MSKWDG1H - Channel 1 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG1H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG1H_SHIFT)) & ADC_WTIMR_MSKWDG1H_MASK)

#define ADC_WTIMR_MSKWDG2L_MASK                  (0x10U)
#define ADC_WTIMR_MSKWDG2L_SHIFT                 (4U)
/*! MSKWDG2L - Channel 2 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG2L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG2L_SHIFT)) & ADC_WTIMR_MSKWDG2L_MASK)

#define ADC_WTIMR_MSKWDG2H_MASK                  (0x20U)
#define ADC_WTIMR_MSKWDG2H_SHIFT                 (5U)
/*! MSKWDG2H - Channel 2 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG2H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG2H_SHIFT)) & ADC_WTIMR_MSKWDG2H_MASK)

#define ADC_WTIMR_MSKWDG3L_MASK                  (0x40U)
#define ADC_WTIMR_MSKWDG3L_SHIFT                 (6U)
/*! MSKWDG3L - Channel 3 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG3L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG3L_SHIFT)) & ADC_WTIMR_MSKWDG3L_MASK)

#define ADC_WTIMR_MSKWDG3H_MASK                  (0x80U)
#define ADC_WTIMR_MSKWDG3H_SHIFT                 (7U)
/*! MSKWDG3H - Channel 3 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG3H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG3H_SHIFT)) & ADC_WTIMR_MSKWDG3H_MASK)

#define ADC_WTIMR_MSKWDG4L_MASK                  (0x100U)
#define ADC_WTIMR_MSKWDG4L_SHIFT                 (8U)
/*! MSKWDG4L - Channel 4 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG4L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG4L_SHIFT)) & ADC_WTIMR_MSKWDG4L_MASK)

#define ADC_WTIMR_MSKWDG4H_MASK                  (0x200U)
#define ADC_WTIMR_MSKWDG4H_SHIFT                 (9U)
/*! MSKWDG4H - Channel 4 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG4H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG4H_SHIFT)) & ADC_WTIMR_MSKWDG4H_MASK)

#define ADC_WTIMR_MSKWDG5L_MASK                  (0x400U)
#define ADC_WTIMR_MSKWDG5L_SHIFT                 (10U)
/*! MSKWDG5L - Channel 5 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG5L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG5L_SHIFT)) & ADC_WTIMR_MSKWDG5L_MASK)

#define ADC_WTIMR_MSKWDG5H_MASK                  (0x800U)
#define ADC_WTIMR_MSKWDG5H_SHIFT                 (11U)
/*! MSKWDG5H - Channel 5 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG5H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG5H_SHIFT)) & ADC_WTIMR_MSKWDG5H_MASK)

#define ADC_WTIMR_MSKWDG6L_MASK                  (0x1000U)
#define ADC_WTIMR_MSKWDG6L_SHIFT                 (12U)
/*! MSKWDG6L - Channel 6 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG6L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG6L_SHIFT)) & ADC_WTIMR_MSKWDG6L_MASK)

#define ADC_WTIMR_MSKWDG6H_MASK                  (0x2000U)
#define ADC_WTIMR_MSKWDG6H_SHIFT                 (13U)
/*! MSKWDG6H - Channel 6 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG6H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG6H_SHIFT)) & ADC_WTIMR_MSKWDG6H_MASK)

#define ADC_WTIMR_MSKWDG7L_MASK                  (0x4000U)
#define ADC_WTIMR_MSKWDG7L_SHIFT                 (14U)
/*! MSKWDG7L - Channel 7 Watchdog Low Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG7L(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG7L_SHIFT)) & ADC_WTIMR_MSKWDG7L_MASK)

#define ADC_WTIMR_MSKWDG7H_MASK                  (0x8000U)
#define ADC_WTIMR_MSKWDG7H_SHIFT                 (15U)
/*! MSKWDG7H - Channel 7 Watchdog High Threshold Interrupt Mask
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ADC_WTIMR_MSKWDG7H(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_MSKWDG7H_SHIFT)) & ADC_WTIMR_MSKWDG7H_MASK)
/*! @} */

/*! @name DMAE - DMAE */
/*! @{ */

#define ADC_DMAE_DMAEN_MASK                      (0x1U)
#define ADC_DMAE_DMAEN_SHIFT                     (0U)
/*! DMAEN - DMA Global Enable
 *  0b0..DMA feature is disabled
 *  0b1..DMA feature is enabled
 */
#define ADC_DMAE_DMAEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAE_DMAEN_SHIFT)) & ADC_DMAE_DMAEN_MASK)

#define ADC_DMAE_DCLR_MASK                       (0x2U)
#define ADC_DMAE_DCLR_SHIFT                      (1U)
/*! DCLR - DMA Clear Sequence Enable
 *  0b0..DMA request cleared by acknowledge from DMA controller
 *  0b1..DMA request cleared on read of data registers
 */
#define ADC_DMAE_DCLR(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_DMAE_DCLR_SHIFT)) & ADC_DMAE_DCLR_MASK)
/*! @} */

/*! @name DMAR0 - DMA 0 */
/*! @{ */

#define ADC_DMAR0_DMA0_MASK                      (0x1U)
#define ADC_DMAR0_DMA0_SHIFT                     (0U)
/*! DMA0 - Channel 0 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA0(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA0_SHIFT)) & ADC_DMAR0_DMA0_MASK)

#define ADC_DMAR0_DMA1_MASK                      (0x2U)
#define ADC_DMAR0_DMA1_SHIFT                     (1U)
/*! DMA1 - Channel 1 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA1(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA1_SHIFT)) & ADC_DMAR0_DMA1_MASK)

#define ADC_DMAR0_DMA2_MASK                      (0x4U)
#define ADC_DMAR0_DMA2_SHIFT                     (2U)
/*! DMA2 - Channel 2 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA2(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA2_SHIFT)) & ADC_DMAR0_DMA2_MASK)

#define ADC_DMAR0_DMA3_MASK                      (0x8U)
#define ADC_DMAR0_DMA3_SHIFT                     (3U)
/*! DMA3 - Channel 3 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA3(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA3_SHIFT)) & ADC_DMAR0_DMA3_MASK)

#define ADC_DMAR0_DMA4_MASK                      (0x10U)
#define ADC_DMAR0_DMA4_SHIFT                     (4U)
/*! DMA4 - Channel 4 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA4(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA4_SHIFT)) & ADC_DMAR0_DMA4_MASK)

#define ADC_DMAR0_DMA5_MASK                      (0x20U)
#define ADC_DMAR0_DMA5_SHIFT                     (5U)
/*! DMA5 - Channel 5 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA5(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA5_SHIFT)) & ADC_DMAR0_DMA5_MASK)

#define ADC_DMAR0_DMA6_MASK                      (0x40U)
#define ADC_DMAR0_DMA6_SHIFT                     (6U)
/*! DMA6 - Channel 6 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA6(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA6_SHIFT)) & ADC_DMAR0_DMA6_MASK)

#define ADC_DMAR0_DMA7_MASK                      (0x80U)
#define ADC_DMAR0_DMA7_SHIFT                     (7U)
/*! DMA7 - Channel 7 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR0_DMA7(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_DMA7_SHIFT)) & ADC_DMAR0_DMA7_MASK)
/*! @} */

/*! @name DMAR1 - DMA 1 */
/*! @{ */

#define ADC_DMAR1_DMA32_MASK                     (0x1U)
#define ADC_DMAR1_DMA32_SHIFT                    (0U)
/*! DMA32 - Channel 32 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA32(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA32_SHIFT)) & ADC_DMAR1_DMA32_MASK)

#define ADC_DMAR1_DMA33_MASK                     (0x2U)
#define ADC_DMAR1_DMA33_SHIFT                    (1U)
/*! DMA33 - Channel 33 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA33(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA33_SHIFT)) & ADC_DMAR1_DMA33_MASK)

#define ADC_DMAR1_DMA34_MASK                     (0x4U)
#define ADC_DMAR1_DMA34_SHIFT                    (2U)
/*! DMA34 - Channel 34 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA34(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA34_SHIFT)) & ADC_DMAR1_DMA34_MASK)

#define ADC_DMAR1_DMA35_MASK                     (0x8U)
#define ADC_DMAR1_DMA35_SHIFT                    (3U)
/*! DMA35 - Channel 35 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA35(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA35_SHIFT)) & ADC_DMAR1_DMA35_MASK)

#define ADC_DMAR1_DMA36_MASK                     (0x10U)
#define ADC_DMAR1_DMA36_SHIFT                    (4U)
/*! DMA36 - Channel 36 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA36(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA36_SHIFT)) & ADC_DMAR1_DMA36_MASK)

#define ADC_DMAR1_DMA37_MASK                     (0x20U)
#define ADC_DMAR1_DMA37_SHIFT                    (5U)
/*! DMA37 - Channel 37 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA37(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA37_SHIFT)) & ADC_DMAR1_DMA37_MASK)

#define ADC_DMAR1_DMA38_MASK                     (0x40U)
#define ADC_DMAR1_DMA38_SHIFT                    (6U)
/*! DMA38 - Channel 38 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA38(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA38_SHIFT)) & ADC_DMAR1_DMA38_MASK)

#define ADC_DMAR1_DMA39_MASK                     (0x80U)
#define ADC_DMAR1_DMA39_SHIFT                    (7U)
/*! DMA39 - Channel 39 DMA Enable
 *  0b0..Transfer of data in DMA mode is disabled
 *  0b1..Transfer of data in DMA mode is enabled
 */
#define ADC_DMAR1_DMA39(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_DMA39_SHIFT)) & ADC_DMAR1_DMA39_MASK)
/*! @} */

/*! @name THRHLR0 - Analog Watchdog Threshold 0 */
/*! @{ */

#define ADC_THRHLR0_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR0_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR0_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR0_THRL_SHIFT)) & ADC_THRHLR0_THRL_MASK)

#define ADC_THRHLR0_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR0_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR0_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR0_THRH_SHIFT)) & ADC_THRHLR0_THRH_MASK)
/*! @} */

/*! @name THRHLR1 - Analog Watchdog Threshold 1 */
/*! @{ */

#define ADC_THRHLR1_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR1_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR1_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR1_THRL_SHIFT)) & ADC_THRHLR1_THRL_MASK)

#define ADC_THRHLR1_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR1_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR1_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR1_THRH_SHIFT)) & ADC_THRHLR1_THRH_MASK)
/*! @} */

/*! @name THRHLR2 - Analog Watchdog Threshold 2 */
/*! @{ */

#define ADC_THRHLR2_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR2_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR2_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR2_THRL_SHIFT)) & ADC_THRHLR2_THRL_MASK)

#define ADC_THRHLR2_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR2_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR2_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR2_THRH_SHIFT)) & ADC_THRHLR2_THRH_MASK)
/*! @} */

/*! @name THRHLR3 - Analog Watchdog Threshold 3 */
/*! @{ */

#define ADC_THRHLR3_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR3_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR3_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR3_THRL_SHIFT)) & ADC_THRHLR3_THRL_MASK)

#define ADC_THRHLR3_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR3_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR3_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR3_THRH_SHIFT)) & ADC_THRHLR3_THRH_MASK)
/*! @} */

/*! @name PSCR - Presampling Control */
/*! @{ */

#define ADC_PSCR_PRECONV_MASK                    (0x1U)
#define ADC_PSCR_PRECONV_SHIFT                   (0U)
/*! PRECONV - Convert Presampled Value
 *  0b0..Presampling is followed by sampling then conversion.
 *  0b1..Presampling is followed by the conversion.
 */
#define ADC_PSCR_PRECONV(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PSCR_PRECONV_SHIFT)) & ADC_PSCR_PRECONV_MASK)

#define ADC_PSCR_PREVAL0_MASK                    (0x6U)
#define ADC_PSCR_PREVAL0_SHIFT                   (1U)
/*! PREVAL0 - Internal Presampling Voltage Selection */
#define ADC_PSCR_PREVAL0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PSCR_PREVAL0_SHIFT)) & ADC_PSCR_PREVAL0_MASK)

#define ADC_PSCR_PREVAL1_MASK                    (0x18U)
#define ADC_PSCR_PREVAL1_SHIFT                   (3U)
/*! PREVAL1 - Internal Presampling Voltage Selection. */
#define ADC_PSCR_PREVAL1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PSCR_PREVAL1_SHIFT)) & ADC_PSCR_PREVAL1_MASK)
/*! @} */

/*! @name PSR0 - Presampling 0 */
/*! @{ */

#define ADC_PSR0_PRES0_MASK                      (0x1U)
#define ADC_PSR0_PRES0_SHIFT                     (0U)
/*! PRES0 - Presampling Enable for Channel 0
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES0(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES0_SHIFT)) & ADC_PSR0_PRES0_MASK)

#define ADC_PSR0_PRES1_MASK                      (0x2U)
#define ADC_PSR0_PRES1_SHIFT                     (1U)
/*! PRES1 - Presampling Enable for Channel 1
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES1(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES1_SHIFT)) & ADC_PSR0_PRES1_MASK)

#define ADC_PSR0_PRES2_MASK                      (0x4U)
#define ADC_PSR0_PRES2_SHIFT                     (2U)
/*! PRES2 - Presampling Enable for Channel 2
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES2(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES2_SHIFT)) & ADC_PSR0_PRES2_MASK)

#define ADC_PSR0_PRES3_MASK                      (0x8U)
#define ADC_PSR0_PRES3_SHIFT                     (3U)
/*! PRES3 - Presampling Enable for Channel 3
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES3(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES3_SHIFT)) & ADC_PSR0_PRES3_MASK)

#define ADC_PSR0_PRES4_MASK                      (0x10U)
#define ADC_PSR0_PRES4_SHIFT                     (4U)
/*! PRES4 - Presampling Enable for Channel 4
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES4(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES4_SHIFT)) & ADC_PSR0_PRES4_MASK)

#define ADC_PSR0_PRES5_MASK                      (0x20U)
#define ADC_PSR0_PRES5_SHIFT                     (5U)
/*! PRES5 - Presampling Enable for Channel 5
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES5(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES5_SHIFT)) & ADC_PSR0_PRES5_MASK)

#define ADC_PSR0_PRES6_MASK                      (0x40U)
#define ADC_PSR0_PRES6_SHIFT                     (6U)
/*! PRES6 - Presampling Enable for Channel 6
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES6(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES6_SHIFT)) & ADC_PSR0_PRES6_MASK)

#define ADC_PSR0_PRES7_MASK                      (0x80U)
#define ADC_PSR0_PRES7_SHIFT                     (7U)
/*! PRES7 - Presampling Enable for Channel 7
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR0_PRES7(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES7_SHIFT)) & ADC_PSR0_PRES7_MASK)
/*! @} */

/*! @name PSR1 - Presampling 1 */
/*! @{ */

#define ADC_PSR1_PRES32_MASK                     (0x1U)
#define ADC_PSR1_PRES32_SHIFT                    (0U)
/*! PRES32 - Presampling Enable for Channel 32
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES32(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES32_SHIFT)) & ADC_PSR1_PRES32_MASK)

#define ADC_PSR1_PRES33_MASK                     (0x2U)
#define ADC_PSR1_PRES33_SHIFT                    (1U)
/*! PRES33 - Presampling Enable for Channel 33
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES33(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES33_SHIFT)) & ADC_PSR1_PRES33_MASK)

#define ADC_PSR1_PRES34_MASK                     (0x4U)
#define ADC_PSR1_PRES34_SHIFT                    (2U)
/*! PRES34 - Presampling Enable for Channel 34
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES34(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES34_SHIFT)) & ADC_PSR1_PRES34_MASK)

#define ADC_PSR1_PRES35_MASK                     (0x8U)
#define ADC_PSR1_PRES35_SHIFT                    (3U)
/*! PRES35 - Presampling Enable for Channel 35
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES35(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES35_SHIFT)) & ADC_PSR1_PRES35_MASK)

#define ADC_PSR1_PRES36_MASK                     (0x10U)
#define ADC_PSR1_PRES36_SHIFT                    (4U)
/*! PRES36 - Presampling Enable for Channel 36
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES36(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES36_SHIFT)) & ADC_PSR1_PRES36_MASK)

#define ADC_PSR1_PRES37_MASK                     (0x20U)
#define ADC_PSR1_PRES37_SHIFT                    (5U)
/*! PRES37 - Presampling Enable for Channel 37
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES37(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES37_SHIFT)) & ADC_PSR1_PRES37_MASK)

#define ADC_PSR1_PRES38_MASK                     (0x40U)
#define ADC_PSR1_PRES38_SHIFT                    (6U)
/*! PRES38 - Presampling Enable for Channel 38
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES38(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES38_SHIFT)) & ADC_PSR1_PRES38_MASK)

#define ADC_PSR1_PRES39_MASK                     (0x80U)
#define ADC_PSR1_PRES39_SHIFT                    (7U)
/*! PRES39 - Presampling Enable for Channel 39
 *  0b0..Presampling is disabled
 *  0b1..Presampling is enabled
 */
#define ADC_PSR1_PRES39(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES39_SHIFT)) & ADC_PSR1_PRES39_MASK)
/*! @} */

/*! @name CTR0 - Conversion Timing 0 */
/*! @{ */

#define ADC_CTR0_INPSAMP_MASK                    (0xFFU)
#define ADC_CTR0_INPSAMP_SHIFT                   (0U)
/*! INPSAMP - Sampling Phase Duration */
#define ADC_CTR0_INPSAMP(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTR0_INPSAMP_SHIFT)) & ADC_CTR0_INPSAMP_MASK)
/*! @} */

/*! @name CTR1 - Conversion Timing 1 */
/*! @{ */

#define ADC_CTR1_INPSAMP_MASK                    (0xFFU)
#define ADC_CTR1_INPSAMP_SHIFT                   (0U)
/*! INPSAMP - Sampling Phase Duration */
#define ADC_CTR1_INPSAMP(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTR1_INPSAMP_SHIFT)) & ADC_CTR1_INPSAMP_MASK)
/*! @} */

/*! @name NCMR0 - Normal Conversion Mask 0 */
/*! @{ */

#define ADC_NCMR0_CH0_MASK                       (0x1U)
#define ADC_NCMR0_CH0_SHIFT                      (0U)
/*! CH0 - Normal Conversion Mask for Channel 0
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH0_SHIFT)) & ADC_NCMR0_CH0_MASK)

#define ADC_NCMR0_CH1_MASK                       (0x2U)
#define ADC_NCMR0_CH1_SHIFT                      (1U)
/*! CH1 - Normal Conversion Mask for Channel 1
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH1_SHIFT)) & ADC_NCMR0_CH1_MASK)

#define ADC_NCMR0_CH2_MASK                       (0x4U)
#define ADC_NCMR0_CH2_SHIFT                      (2U)
/*! CH2 - Normal Conversion Mask for Channel 2
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH2_SHIFT)) & ADC_NCMR0_CH2_MASK)

#define ADC_NCMR0_CH3_MASK                       (0x8U)
#define ADC_NCMR0_CH3_SHIFT                      (3U)
/*! CH3 - Normal Conversion Mask for Channel 3
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH3_SHIFT)) & ADC_NCMR0_CH3_MASK)

#define ADC_NCMR0_CH4_MASK                       (0x10U)
#define ADC_NCMR0_CH4_SHIFT                      (4U)
/*! CH4 - Normal Conversion Mask for Channel 4
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH4(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH4_SHIFT)) & ADC_NCMR0_CH4_MASK)

#define ADC_NCMR0_CH5_MASK                       (0x20U)
#define ADC_NCMR0_CH5_SHIFT                      (5U)
/*! CH5 - Normal Conversion Mask for Channel 5
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH5(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH5_SHIFT)) & ADC_NCMR0_CH5_MASK)

#define ADC_NCMR0_CH6_MASK                       (0x40U)
#define ADC_NCMR0_CH6_SHIFT                      (6U)
/*! CH6 - Normal Conversion Mask for Channel 6
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH6(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH6_SHIFT)) & ADC_NCMR0_CH6_MASK)

#define ADC_NCMR0_CH7_MASK                       (0x80U)
#define ADC_NCMR0_CH7_SHIFT                      (7U)
/*! CH7 - Normal Conversion Mask for Channel 7
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR0_CH7(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH7_SHIFT)) & ADC_NCMR0_CH7_MASK)
/*! @} */

/*! @name NCMR1 - Normal Conversion Mask 1 */
/*! @{ */

#define ADC_NCMR1_CH32_MASK                      (0x1U)
#define ADC_NCMR1_CH32_SHIFT                     (0U)
/*! CH32 - Normal Conversion Mask for Channel 32
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH32(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH32_SHIFT)) & ADC_NCMR1_CH32_MASK)

#define ADC_NCMR1_CH33_MASK                      (0x2U)
#define ADC_NCMR1_CH33_SHIFT                     (1U)
/*! CH33 - Normal Conversion Mask for Channel 33
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH33(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH33_SHIFT)) & ADC_NCMR1_CH33_MASK)

#define ADC_NCMR1_CH34_MASK                      (0x4U)
#define ADC_NCMR1_CH34_SHIFT                     (2U)
/*! CH34 - Normal Conversion Mask for Channel 34
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH34(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH34_SHIFT)) & ADC_NCMR1_CH34_MASK)

#define ADC_NCMR1_CH35_MASK                      (0x8U)
#define ADC_NCMR1_CH35_SHIFT                     (3U)
/*! CH35 - Normal Conversion Mask for Channel 35
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH35(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH35_SHIFT)) & ADC_NCMR1_CH35_MASK)

#define ADC_NCMR1_CH36_MASK                      (0x10U)
#define ADC_NCMR1_CH36_SHIFT                     (4U)
/*! CH36 - Normal Conversion Mask for Channel 36
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH36(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH36_SHIFT)) & ADC_NCMR1_CH36_MASK)

#define ADC_NCMR1_CH37_MASK                      (0x20U)
#define ADC_NCMR1_CH37_SHIFT                     (5U)
/*! CH37 - Normal Conversion Mask for Channel 37
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH37(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH37_SHIFT)) & ADC_NCMR1_CH37_MASK)

#define ADC_NCMR1_CH38_MASK                      (0x40U)
#define ADC_NCMR1_CH38_SHIFT                     (6U)
/*! CH38 - Normal Conversion Mask for Channel 38
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH38(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH38_SHIFT)) & ADC_NCMR1_CH38_MASK)

#define ADC_NCMR1_CH39_MASK                      (0x80U)
#define ADC_NCMR1_CH39_SHIFT                     (7U)
/*! CH39 - Normal Conversion Mask for Channel 39
 *  0b0..Normal Conversion is disabled
 *  0b1..Normal Conversion is enabled
 */
#define ADC_NCMR1_CH39(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH39_SHIFT)) & ADC_NCMR1_CH39_MASK)
/*! @} */

/*! @name JCMR0 - Injected Conversion Mask 0 */
/*! @{ */

#define ADC_JCMR0_CH0_MASK                       (0x1U)
#define ADC_JCMR0_CH0_SHIFT                      (0U)
/*! CH0 - Injected Conversion Mask for Channel 0
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH0_SHIFT)) & ADC_JCMR0_CH0_MASK)

#define ADC_JCMR0_CH1_MASK                       (0x2U)
#define ADC_JCMR0_CH1_SHIFT                      (1U)
/*! CH1 - Injected Conversion Mask for Channel 1
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH1_SHIFT)) & ADC_JCMR0_CH1_MASK)

#define ADC_JCMR0_CH2_MASK                       (0x4U)
#define ADC_JCMR0_CH2_SHIFT                      (2U)
/*! CH2 - Injected Conversion Mask for Channel 2
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH2_SHIFT)) & ADC_JCMR0_CH2_MASK)

#define ADC_JCMR0_CH3_MASK                       (0x8U)
#define ADC_JCMR0_CH3_SHIFT                      (3U)
/*! CH3 - Injected Conversion Mask for Channel 3
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH3_SHIFT)) & ADC_JCMR0_CH3_MASK)

#define ADC_JCMR0_CH4_MASK                       (0x10U)
#define ADC_JCMR0_CH4_SHIFT                      (4U)
/*! CH4 - Injected Conversion Mask for Channel 4
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH4(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH4_SHIFT)) & ADC_JCMR0_CH4_MASK)

#define ADC_JCMR0_CH5_MASK                       (0x20U)
#define ADC_JCMR0_CH5_SHIFT                      (5U)
/*! CH5 - Injected Conversion Mask for Channel 5
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH5(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH5_SHIFT)) & ADC_JCMR0_CH5_MASK)

#define ADC_JCMR0_CH6_MASK                       (0x40U)
#define ADC_JCMR0_CH6_SHIFT                      (6U)
/*! CH6 - Injected Conversion Mask for Channel 6
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH6(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH6_SHIFT)) & ADC_JCMR0_CH6_MASK)

#define ADC_JCMR0_CH7_MASK                       (0x80U)
#define ADC_JCMR0_CH7_SHIFT                      (7U)
/*! CH7 - Injected Conversion Mask for Channel 7
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR0_CH7(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH7_SHIFT)) & ADC_JCMR0_CH7_MASK)
/*! @} */

/*! @name JCMR1 - Injected Conversion Mask 1 */
/*! @{ */

#define ADC_JCMR1_CH32_MASK                      (0x1U)
#define ADC_JCMR1_CH32_SHIFT                     (0U)
/*! CH32 - Injected Conversion Mask for Channel 32
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH32(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH32_SHIFT)) & ADC_JCMR1_CH32_MASK)

#define ADC_JCMR1_CH33_MASK                      (0x2U)
#define ADC_JCMR1_CH33_SHIFT                     (1U)
/*! CH33 - Injected Conversion Mask for Channel 33
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH33(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH33_SHIFT)) & ADC_JCMR1_CH33_MASK)

#define ADC_JCMR1_CH34_MASK                      (0x4U)
#define ADC_JCMR1_CH34_SHIFT                     (2U)
/*! CH34 - Injected Conversion Mask for Channel 34
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH34(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH34_SHIFT)) & ADC_JCMR1_CH34_MASK)

#define ADC_JCMR1_CH35_MASK                      (0x8U)
#define ADC_JCMR1_CH35_SHIFT                     (3U)
/*! CH35 - Injected Conversion Mask for Channel 35
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH35(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH35_SHIFT)) & ADC_JCMR1_CH35_MASK)

#define ADC_JCMR1_CH36_MASK                      (0x10U)
#define ADC_JCMR1_CH36_SHIFT                     (4U)
/*! CH36 - Injected Conversion Mask for Channel 36
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH36(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH36_SHIFT)) & ADC_JCMR1_CH36_MASK)

#define ADC_JCMR1_CH37_MASK                      (0x20U)
#define ADC_JCMR1_CH37_SHIFT                     (5U)
/*! CH37 - Injected Conversion Mask for Channel 37
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH37(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH37_SHIFT)) & ADC_JCMR1_CH37_MASK)

#define ADC_JCMR1_CH38_MASK                      (0x40U)
#define ADC_JCMR1_CH38_SHIFT                     (6U)
/*! CH38 - Injected Conversion Mask for Channel 38
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH38(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH38_SHIFT)) & ADC_JCMR1_CH38_MASK)

#define ADC_JCMR1_CH39_MASK                      (0x80U)
#define ADC_JCMR1_CH39_SHIFT                     (7U)
/*! CH39 - Injected Conversion Mask for Channel 39
 *  0b0..Injected conversion is disabled
 *  0b1..Injected conversion is enabled
 */
#define ADC_JCMR1_CH39(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH39_SHIFT)) & ADC_JCMR1_CH39_MASK)
/*! @} */

/*! @name USROFSGN - User OFFSET and Gain */
/*! @{ */

#define ADC_USROFSGN_OFFSUSER_MASK               (0xFFU)
#define ADC_USROFSGN_OFFSUSER_SHIFT              (0U)
/*! OFFSUSER - User Defined Offset */
#define ADC_USROFSGN_OFFSUSER(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_USROFSGN_OFFSUSER_SHIFT)) & ADC_USROFSGN_OFFSUSER_MASK)

#define ADC_USROFSGN_GAINUSER_MASK               (0x3FF0000U)
#define ADC_USROFSGN_GAINUSER_SHIFT              (16U)
/*! GAINUSER - User-Defined Gain Value */
#define ADC_USROFSGN_GAINUSER(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_USROFSGN_GAINUSER_SHIFT)) & ADC_USROFSGN_GAINUSER_MASK)
/*! @} */

/*! @name PDEDR - Power Down Exit Delay */
/*! @{ */

#define ADC_PDEDR_PDED_MASK                      (0xFFU)
#define ADC_PDEDR_PDED_SHIFT                     (0U)
/*! PDED - Power Down Exist Delay */
#define ADC_PDEDR_PDED(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PDEDR_PDED_SHIFT)) & ADC_PDEDR_PDED_MASK)
/*! @} */

/*! @name PCDR - Precision Channel n Data */
/*! @{ */

#define ADC_PCDR_CDATA_MASK                      (0xFFFU)
#define ADC_PCDR_CDATA_SHIFT                     (0U)
/*! CDATA - Channel Converted Data */
#define ADC_PCDR_CDATA(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_CDATA_SHIFT)) & ADC_PCDR_CDATA_MASK)

#define ADC_PCDR_RESULT_MASK                     (0x30000U)
#define ADC_PCDR_RESULT_SHIFT                    (16U)
/*! RESULT - Mode of Conversion Status
 *  0b00..Data is a result of Normal conversion mode
 *  0b01..Data is a result of Injected conversion mode
 *  0b10..Data is a result of CTU conversion mode
 *  0b11..Reserved
 */
#define ADC_PCDR_RESULT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_RESULT_SHIFT)) & ADC_PCDR_RESULT_MASK)

#define ADC_PCDR_OVERW_MASK                      (0x40000U)
#define ADC_PCDR_OVERW_SHIFT                     (18U)
/*! OVERW - Data Overwrite
 *  0b0..Data not overwritten
 *  0b1..Data overwritten
 */
#define ADC_PCDR_OVERW(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_OVERW_SHIFT)) & ADC_PCDR_OVERW_MASK)

#define ADC_PCDR_VALID_MASK                      (0x80000U)
#define ADC_PCDR_VALID_SHIFT                     (19U)
/*! VALID - Conversion Data Valid
 *  0b0..Not valid data
 *  0b1..Valid data
 */
#define ADC_PCDR_VALID(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_VALID_SHIFT)) & ADC_PCDR_VALID_MASK)
/*! @} */

/* The count of ADC_PCDR */
#define ADC_PCDR_COUNT                           (8U)

/*! @name ICDR - Internal Channel n Data */
/*! @{ */

#define ADC_ICDR_CDATA_MASK                      (0xFFFU)
#define ADC_ICDR_CDATA_SHIFT                     (0U)
/*! CDATA - Channel Converted Data */
#define ADC_ICDR_CDATA(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_CDATA_SHIFT)) & ADC_ICDR_CDATA_MASK)

#define ADC_ICDR_RESULT_MASK                     (0x30000U)
#define ADC_ICDR_RESULT_SHIFT                    (16U)
/*! RESULT - Mode of Conversion Status
 *  0b00..Data is a result of Normal conversion mode
 *  0b01..Data is a result of Injected conversion mode
 *  0b10..Data is a result of CTU conversion mode
 *  0b11..Reserved
 */
#define ADC_ICDR_RESULT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_RESULT_SHIFT)) & ADC_ICDR_RESULT_MASK)

#define ADC_ICDR_OVERW_MASK                      (0x40000U)
#define ADC_ICDR_OVERW_SHIFT                     (18U)
/*! OVERW - Data Overwrite
 *  0b0..Data not overwritten
 *  0b1..Data overwritten
 */
#define ADC_ICDR_OVERW(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_OVERW_SHIFT)) & ADC_ICDR_OVERW_MASK)

#define ADC_ICDR_VALID_MASK                      (0x80000U)
#define ADC_ICDR_VALID_SHIFT                     (19U)
/*! VALID - Conversion Data Valid
 *  0b0..Not valid data
 *  0b1..Valid data
 */
#define ADC_ICDR_VALID(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_VALID_SHIFT)) & ADC_ICDR_VALID_MASK)
/*! @} */

/* The count of ADC_ICDR */
#define ADC_ICDR_COUNT                           (8U)

/*! @name THRHLR4 - Analog Watchdog Threshold 4 */
/*! @{ */

#define ADC_THRHLR4_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR4_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR4_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR4_THRL_SHIFT)) & ADC_THRHLR4_THRL_MASK)

#define ADC_THRHLR4_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR4_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR4_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR4_THRH_SHIFT)) & ADC_THRHLR4_THRH_MASK)
/*! @} */

/*! @name THRHLR5 - Analog Watchdog Threshold 5 */
/*! @{ */

#define ADC_THRHLR5_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR5_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR5_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR5_THRL_SHIFT)) & ADC_THRHLR5_THRL_MASK)

#define ADC_THRHLR5_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR5_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR5_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR5_THRH_SHIFT)) & ADC_THRHLR5_THRH_MASK)
/*! @} */

/*! @name THRHLR6 - Analog Watchdog Threshold 6 */
/*! @{ */

#define ADC_THRHLR6_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR6_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR6_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR6_THRL_SHIFT)) & ADC_THRHLR6_THRL_MASK)

#define ADC_THRHLR6_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR6_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR6_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR6_THRH_SHIFT)) & ADC_THRHLR6_THRH_MASK)
/*! @} */

/*! @name THRHLR7 - Analog Watchdog Threshold 7 */
/*! @{ */

#define ADC_THRHLR7_THRL_MASK                    (0xFFFU)
#define ADC_THRHLR7_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold */
#define ADC_THRHLR7_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR7_THRL_SHIFT)) & ADC_THRHLR7_THRL_MASK)

#define ADC_THRHLR7_THRH_MASK                    (0xFFF0000U)
#define ADC_THRHLR7_THRH_SHIFT                   (16U)
/*! THRH - High Threshold */
#define ADC_THRHLR7_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR7_THRH_SHIFT)) & ADC_THRHLR7_THRH_MASK)
/*! @} */

/*! @name CWSELR0 - Channel Watchdog Select 0 */
/*! @{ */

#define ADC_CWSELR0_WSEL_CH0_MASK                (0x7U)
#define ADC_CWSELR0_WSEL_CH0_SHIFT               (0U)
/*! WSEL_CH0 - Channel Watchdog Select for Channel 0 */
#define ADC_CWSELR0_WSEL_CH0(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH0_SHIFT)) & ADC_CWSELR0_WSEL_CH0_MASK)

#define ADC_CWSELR0_WSEL_CH1_MASK                (0x70U)
#define ADC_CWSELR0_WSEL_CH1_SHIFT               (4U)
/*! WSEL_CH1 - Channel Watchdog Select for Channel 1 */
#define ADC_CWSELR0_WSEL_CH1(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH1_SHIFT)) & ADC_CWSELR0_WSEL_CH1_MASK)

#define ADC_CWSELR0_WSEL_CH2_MASK                (0x700U)
#define ADC_CWSELR0_WSEL_CH2_SHIFT               (8U)
/*! WSEL_CH2 - Channel Watchdog Select for Channel 2 */
#define ADC_CWSELR0_WSEL_CH2(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH2_SHIFT)) & ADC_CWSELR0_WSEL_CH2_MASK)

#define ADC_CWSELR0_WSEL_CH3_MASK                (0x7000U)
#define ADC_CWSELR0_WSEL_CH3_SHIFT               (12U)
/*! WSEL_CH3 - Channel Watchdog Select for Channel 3 */
#define ADC_CWSELR0_WSEL_CH3(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH3_SHIFT)) & ADC_CWSELR0_WSEL_CH3_MASK)

#define ADC_CWSELR0_WSEL_CH4_MASK                (0x70000U)
#define ADC_CWSELR0_WSEL_CH4_SHIFT               (16U)
/*! WSEL_CH4 - Channel Watchdog Select for Channel 4 */
#define ADC_CWSELR0_WSEL_CH4(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH4_SHIFT)) & ADC_CWSELR0_WSEL_CH4_MASK)

#define ADC_CWSELR0_WSEL_CH5_MASK                (0x700000U)
#define ADC_CWSELR0_WSEL_CH5_SHIFT               (20U)
/*! WSEL_CH5 - Channel Watchdog Select for Channel 5 */
#define ADC_CWSELR0_WSEL_CH5(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH5_SHIFT)) & ADC_CWSELR0_WSEL_CH5_MASK)

#define ADC_CWSELR0_WSEL_CH6_MASK                (0x7000000U)
#define ADC_CWSELR0_WSEL_CH6_SHIFT               (24U)
/*! WSEL_CH6 - Channel Watchdog Select for Channel 6 */
#define ADC_CWSELR0_WSEL_CH6(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH6_SHIFT)) & ADC_CWSELR0_WSEL_CH6_MASK)

#define ADC_CWSELR0_WSEL_CH7_MASK                (0x70000000U)
#define ADC_CWSELR0_WSEL_CH7_SHIFT               (28U)
/*! WSEL_CH7 - Channel Watchdog Select for Channel 7 */
#define ADC_CWSELR0_WSEL_CH7(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR0_WSEL_CH7_SHIFT)) & ADC_CWSELR0_WSEL_CH7_MASK)
/*! @} */

/*! @name CWSELR4 - Channel Watchdog Select 4 */
/*! @{ */

#define ADC_CWSELR4_WSEL_CH32_MASK               (0x7U)
#define ADC_CWSELR4_WSEL_CH32_SHIFT              (0U)
/*! WSEL_CH32 - Channel Watchdog Select for Channel 32 */
#define ADC_CWSELR4_WSEL_CH32(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH32_SHIFT)) & ADC_CWSELR4_WSEL_CH32_MASK)

#define ADC_CWSELR4_WSEL_CH33_MASK               (0x70U)
#define ADC_CWSELR4_WSEL_CH33_SHIFT              (4U)
/*! WSEL_CH33 - Channel Watchdog Select for Channel 33 */
#define ADC_CWSELR4_WSEL_CH33(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH33_SHIFT)) & ADC_CWSELR4_WSEL_CH33_MASK)

#define ADC_CWSELR4_WSEL_CH34_MASK               (0x700U)
#define ADC_CWSELR4_WSEL_CH34_SHIFT              (8U)
/*! WSEL_CH34 - Channel Watchdog Select for Channel 34 */
#define ADC_CWSELR4_WSEL_CH34(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH34_SHIFT)) & ADC_CWSELR4_WSEL_CH34_MASK)

#define ADC_CWSELR4_WSEL_CH35_MASK               (0x7000U)
#define ADC_CWSELR4_WSEL_CH35_SHIFT              (12U)
/*! WSEL_CH35 - Channel Watchdog Select for Channel 35 */
#define ADC_CWSELR4_WSEL_CH35(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH35_SHIFT)) & ADC_CWSELR4_WSEL_CH35_MASK)

#define ADC_CWSELR4_WSEL_CH36_MASK               (0x70000U)
#define ADC_CWSELR4_WSEL_CH36_SHIFT              (16U)
/*! WSEL_CH36 - Channel Watchdog Select for Channel 36 */
#define ADC_CWSELR4_WSEL_CH36(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH36_SHIFT)) & ADC_CWSELR4_WSEL_CH36_MASK)

#define ADC_CWSELR4_WSEL_CH37_MASK               (0x700000U)
#define ADC_CWSELR4_WSEL_CH37_SHIFT              (20U)
/*! WSEL_CH37 - Channel Watchdog Select for Channel 37 */
#define ADC_CWSELR4_WSEL_CH37(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH37_SHIFT)) & ADC_CWSELR4_WSEL_CH37_MASK)

#define ADC_CWSELR4_WSEL_CH38_MASK               (0x7000000U)
#define ADC_CWSELR4_WSEL_CH38_SHIFT              (24U)
/*! WSEL_CH38 - Channel Watchdog Select for Channel 38 */
#define ADC_CWSELR4_WSEL_CH38(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH38_SHIFT)) & ADC_CWSELR4_WSEL_CH38_MASK)

#define ADC_CWSELR4_WSEL_CH39_MASK               (0x70000000U)
#define ADC_CWSELR4_WSEL_CH39_SHIFT              (28U)
/*! WSEL_CH39 - Channel Watchdog Select for Channel 39 */
#define ADC_CWSELR4_WSEL_CH39(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CWSELR4_WSEL_CH39_SHIFT)) & ADC_CWSELR4_WSEL_CH39_MASK)
/*! @} */

/*! @name CWENR0 - Channel Watchdog Enable 0 */
/*! @{ */

#define ADC_CWENR0_CWEN0_MASK                    (0x1U)
#define ADC_CWENR0_CWEN0_SHIFT                   (0U)
/*! CWEN0 - Watchdog Enable for Channel 0
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN0_SHIFT)) & ADC_CWENR0_CWEN0_MASK)

#define ADC_CWENR0_CWEN1_MASK                    (0x2U)
#define ADC_CWENR0_CWEN1_SHIFT                   (1U)
/*! CWEN1 - Watchdog Enable for Channel 1
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN1_SHIFT)) & ADC_CWENR0_CWEN1_MASK)

#define ADC_CWENR0_CWEN2_MASK                    (0x4U)
#define ADC_CWENR0_CWEN2_SHIFT                   (2U)
/*! CWEN2 - Watchdog Enable for Channel 2
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN2_SHIFT)) & ADC_CWENR0_CWEN2_MASK)

#define ADC_CWENR0_CWEN3_MASK                    (0x8U)
#define ADC_CWENR0_CWEN3_SHIFT                   (3U)
/*! CWEN3 - Watchdog Enable for Channel 3
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN3_SHIFT)) & ADC_CWENR0_CWEN3_MASK)

#define ADC_CWENR0_CWEN4_MASK                    (0x10U)
#define ADC_CWENR0_CWEN4_SHIFT                   (4U)
/*! CWEN4 - Watchdog Enable for Channel 4
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN4_SHIFT)) & ADC_CWENR0_CWEN4_MASK)

#define ADC_CWENR0_CWEN5_MASK                    (0x20U)
#define ADC_CWENR0_CWEN5_SHIFT                   (5U)
/*! CWEN5 - Watchdog Enable for Channel 5
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN5_SHIFT)) & ADC_CWENR0_CWEN5_MASK)

#define ADC_CWENR0_CWEN6_MASK                    (0x40U)
#define ADC_CWENR0_CWEN6_SHIFT                   (6U)
/*! CWEN6 - Watchdog Enable for Channel 6
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN6_SHIFT)) & ADC_CWENR0_CWEN6_MASK)

#define ADC_CWENR0_CWEN7_MASK                    (0x80U)
#define ADC_CWENR0_CWEN7_SHIFT                   (7U)
/*! CWEN7 - Watchdog Enable for Channel 7
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR0_CWEN7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN7_SHIFT)) & ADC_CWENR0_CWEN7_MASK)
/*! @} */

/*! @name CWENR1 - Channel Watchdog Enable 1 */
/*! @{ */

#define ADC_CWENR1_CWEN32_MASK                   (0x1U)
#define ADC_CWENR1_CWEN32_SHIFT                  (0U)
/*! CWEN32 - Watchdog Enable for Channel 32
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN32(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN32_SHIFT)) & ADC_CWENR1_CWEN32_MASK)

#define ADC_CWENR1_CWEN33_MASK                   (0x2U)
#define ADC_CWENR1_CWEN33_SHIFT                  (1U)
/*! CWEN33 - Watchdog Enable for Channel 33
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN33(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN33_SHIFT)) & ADC_CWENR1_CWEN33_MASK)

#define ADC_CWENR1_CWEN34_MASK                   (0x4U)
#define ADC_CWENR1_CWEN34_SHIFT                  (2U)
/*! CWEN34 - Watchdog Enable for Channel 34
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN34(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN34_SHIFT)) & ADC_CWENR1_CWEN34_MASK)

#define ADC_CWENR1_CWEN35_MASK                   (0x8U)
#define ADC_CWENR1_CWEN35_SHIFT                  (3U)
/*! CWEN35 - Watchdog Enable for Channel 35
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN35(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN35_SHIFT)) & ADC_CWENR1_CWEN35_MASK)

#define ADC_CWENR1_CWEN36_MASK                   (0x10U)
#define ADC_CWENR1_CWEN36_SHIFT                  (4U)
/*! CWEN36 - Watchdog Enable for Channel 36
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN36(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN36_SHIFT)) & ADC_CWENR1_CWEN36_MASK)

#define ADC_CWENR1_CWEN37_MASK                   (0x20U)
#define ADC_CWENR1_CWEN37_SHIFT                  (5U)
/*! CWEN37 - Watchdog Enable for Channel 37
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN37(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN37_SHIFT)) & ADC_CWENR1_CWEN37_MASK)

#define ADC_CWENR1_CWEN38_MASK                   (0x40U)
#define ADC_CWENR1_CWEN38_SHIFT                  (6U)
/*! CWEN38 - Watchdog Enable for Channel 38
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN38(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN38_SHIFT)) & ADC_CWENR1_CWEN38_MASK)

#define ADC_CWENR1_CWEN39_MASK                   (0x80U)
#define ADC_CWENR1_CWEN39_SHIFT                  (7U)
/*! CWEN39 - Watchdog Enable for Channel 39
 *  0b0..Watchdog is disabled
 *  0b1..Watchdog is enabled
 */
#define ADC_CWENR1_CWEN39(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN39_SHIFT)) & ADC_CWENR1_CWEN39_MASK)
/*! @} */

/*! @name AWORR0 - Analog Watchdog Out of Range 0 */
/*! @{ */

#define ADC_AWORR0_AWOR_CH0_MASK                 (0x1U)
#define ADC_AWORR0_AWOR_CH0_SHIFT                (0U)
/*! AWOR_CH0 - Analog Watchdog Out of Range for Channel 0
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH0_SHIFT)) & ADC_AWORR0_AWOR_CH0_MASK)

#define ADC_AWORR0_AWOR_CH1_MASK                 (0x2U)
#define ADC_AWORR0_AWOR_CH1_SHIFT                (1U)
/*! AWOR_CH1 - Analog Watchdog Out of Range for Channel 1
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH1_SHIFT)) & ADC_AWORR0_AWOR_CH1_MASK)

#define ADC_AWORR0_AWOR_CH2_MASK                 (0x4U)
#define ADC_AWORR0_AWOR_CH2_SHIFT                (2U)
/*! AWOR_CH2 - Analog Watchdog Out of Range for Channel 2
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH2_SHIFT)) & ADC_AWORR0_AWOR_CH2_MASK)

#define ADC_AWORR0_AWOR_CH3_MASK                 (0x8U)
#define ADC_AWORR0_AWOR_CH3_SHIFT                (3U)
/*! AWOR_CH3 - Analog Watchdog Out of Range for Channel 3
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH3_SHIFT)) & ADC_AWORR0_AWOR_CH3_MASK)

#define ADC_AWORR0_AWOR_CH4_MASK                 (0x10U)
#define ADC_AWORR0_AWOR_CH4_SHIFT                (4U)
/*! AWOR_CH4 - Analog Watchdog Out of Range for Channel 4
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH4_SHIFT)) & ADC_AWORR0_AWOR_CH4_MASK)

#define ADC_AWORR0_AWOR_CH5_MASK                 (0x20U)
#define ADC_AWORR0_AWOR_CH5_SHIFT                (5U)
/*! AWOR_CH5 - Analog Watchdog Out of Range for Channel 5
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH5_SHIFT)) & ADC_AWORR0_AWOR_CH5_MASK)

#define ADC_AWORR0_AWOR_CH6_MASK                 (0x40U)
#define ADC_AWORR0_AWOR_CH6_SHIFT                (6U)
/*! AWOR_CH6 - Analog Watchdog Out of Range for Channel 6
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH6_SHIFT)) & ADC_AWORR0_AWOR_CH6_MASK)

#define ADC_AWORR0_AWOR_CH7_MASK                 (0x80U)
#define ADC_AWORR0_AWOR_CH7_SHIFT                (7U)
/*! AWOR_CH7 - Analog Watchdog Out of Range for Channel 7
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR0_AWOR_CH7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH7_SHIFT)) & ADC_AWORR0_AWOR_CH7_MASK)
/*! @} */

/*! @name AWORR1 - Analog Watchdog Out of Range 1 */
/*! @{ */

#define ADC_AWORR1_AWOR_CH32_MASK                (0x1U)
#define ADC_AWORR1_AWOR_CH32_SHIFT               (0U)
/*! AWOR_CH32 - Analog Watchdog Out of Range for Channel 32
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH32(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH32_SHIFT)) & ADC_AWORR1_AWOR_CH32_MASK)

#define ADC_AWORR1_AWOR_CH33_MASK                (0x2U)
#define ADC_AWORR1_AWOR_CH33_SHIFT               (1U)
/*! AWOR_CH33 - Analog Watchdog Out of Range for Channel 33
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH33(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH33_SHIFT)) & ADC_AWORR1_AWOR_CH33_MASK)

#define ADC_AWORR1_AWOR_CH34_MASK                (0x4U)
#define ADC_AWORR1_AWOR_CH34_SHIFT               (2U)
/*! AWOR_CH34 - Analog Watchdog Out of Range for Channel 34
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH34(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH34_SHIFT)) & ADC_AWORR1_AWOR_CH34_MASK)

#define ADC_AWORR1_AWOR_CH35_MASK                (0x8U)
#define ADC_AWORR1_AWOR_CH35_SHIFT               (3U)
/*! AWOR_CH35 - Analog Watchdog Out of Range for Channel 35
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH35(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH35_SHIFT)) & ADC_AWORR1_AWOR_CH35_MASK)

#define ADC_AWORR1_AWOR_CH36_MASK                (0x10U)
#define ADC_AWORR1_AWOR_CH36_SHIFT               (4U)
/*! AWOR_CH36 - Analog Watchdog Out of Range for Channel 36
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH36(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH36_SHIFT)) & ADC_AWORR1_AWOR_CH36_MASK)

#define ADC_AWORR1_AWOR_CH37_MASK                (0x20U)
#define ADC_AWORR1_AWOR_CH37_SHIFT               (5U)
/*! AWOR_CH37 - Analog Watchdog Out of Range for Channel 37
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH37(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH37_SHIFT)) & ADC_AWORR1_AWOR_CH37_MASK)

#define ADC_AWORR1_AWOR_CH38_MASK                (0x40U)
#define ADC_AWORR1_AWOR_CH38_SHIFT               (6U)
/*! AWOR_CH38 - Analog Watchdog Out of Range for Channel 38
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH38(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH38_SHIFT)) & ADC_AWORR1_AWOR_CH38_MASK)

#define ADC_AWORR1_AWOR_CH39_MASK                (0x80U)
#define ADC_AWORR1_AWOR_CH39_SHIFT               (7U)
/*! AWOR_CH39 - Analog Watchdog Out of Range for Channel 39
 *  0b0..Converted data is in range
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Converted data is out of range
 */
#define ADC_AWORR1_AWOR_CH39(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH39_SHIFT)) & ADC_AWORR1_AWOR_CH39_MASK)
/*! @} */

/*! @name STCR1 - Self-Test Configuration 1 */
/*! @{ */

#define ADC_STCR1_INPSAMP_S_MASK                 (0xFF00U)
#define ADC_STCR1_INPSAMP_S_SHIFT                (8U)
/*! INPSAMP_S - Sampling Configuration for Algorithm S */
#define ADC_STCR1_INPSAMP_S(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR1_INPSAMP_S_SHIFT)) & ADC_STCR1_INPSAMP_S_MASK)

#define ADC_STCR1_INPSAMP_C_MASK                 (0xFF000000U)
#define ADC_STCR1_INPSAMP_C_SHIFT                (24U)
/*! INPSAMP_C - Sampling Configuration for Algorithm C */
#define ADC_STCR1_INPSAMP_C(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR1_INPSAMP_C_SHIFT)) & ADC_STCR1_INPSAMP_C_MASK)
/*! @} */

/*! @name STCR2 - Self-Test Configuration 2 */
/*! @{ */

#define ADC_STCR2_FMA_S_MASK                     (0x1U)
#define ADC_STCR2_FMA_S_SHIFT                    (0U)
/*! FMA_S - Fault Mapping for BGAP Algorithm
 *  0b0..NCF
 *  0b1..CF
 */
#define ADC_STCR2_FMA_S(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_S_SHIFT)) & ADC_STCR2_FMA_S_MASK)

#define ADC_STCR2_FMA_C_MASK                     (0x4U)
#define ADC_STCR2_FMA_C_SHIFT                    (2U)
/*! FMA_C - Fault Mapping for Algorithm C
 *  0b0..NCF
 *  0b1..CF
 */
#define ADC_STCR2_FMA_C(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_C_SHIFT)) & ADC_STCR2_FMA_C_MASK)

#define ADC_STCR2_FMA_WDTERR_MASK                (0x8U)
#define ADC_STCR2_FMA_WDTERR_SHIFT               (3U)
/*! FMA_WDTERR - Fault Mapping for Watchdog Timer Error
 *  0b0..NCF
 *  0b1..CF
 */
#define ADC_STCR2_FMA_WDTERR(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_WDTERR_SHIFT)) & ADC_STCR2_FMA_WDTERR_MASK)

#define ADC_STCR2_FMA_WDSERR_MASK                (0x10U)
#define ADC_STCR2_FMA_WDSERR_SHIFT               (4U)
/*! FMA_WDSERR - Fault Mapping for Watchdog Sequence Error
 *  0b0..NCF mapping
 *  0b1..CF mapping
 */
#define ADC_STCR2_FMA_WDSERR(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_WDSERR_SHIFT)) & ADC_STCR2_FMA_WDSERR_MASK)

#define ADC_STCR2_EN_MASK                        (0x80U)
#define ADC_STCR2_EN_SHIFT                       (7U)
/*! EN - Self-Testing Channel Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STCR2_EN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_EN_SHIFT)) & ADC_STCR2_EN_MASK)

#define ADC_STCR2_MSKERR_S0_MASK                 (0x800U)
#define ADC_STCR2_MSKERR_S0_SHIFT                (11U)
/*! MSKERR_S0 - Error on Algorithm S0 Channel Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKERR_S0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_S0_SHIFT)) & ADC_STCR2_MSKERR_S0_MASK)

#define ADC_STCR2_MSKERR_S1_MASK                 (0x1000U)
#define ADC_STCR2_MSKERR_S1_SHIFT                (12U)
/*! MSKERR_S1 - Error on Algorithm S1 Channel Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKERR_S1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_S1_SHIFT)) & ADC_STCR2_MSKERR_S1_MASK)

#define ADC_STCR2_MSKERR_S2_MASK                 (0x2000U)
#define ADC_STCR2_MSKERR_S2_SHIFT                (13U)
/*! MSKERR_S2 - Error on Algorithm S2 Channel Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKERR_S2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_S2_SHIFT)) & ADC_STCR2_MSKERR_S2_MASK)

#define ADC_STCR2_MSKERR_C_MASK                  (0x8000U)
#define ADC_STCR2_MSKERR_C_SHIFT                 (15U)
/*! MSKERR_C - Error on Algorithm C Channel Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKERR_C(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_C_SHIFT)) & ADC_STCR2_MSKERR_C_MASK)

#define ADC_STCR2_MSKWDG_EOA_S_MASK              (0x10000U)
#define ADC_STCR2_MSKWDG_EOA_S_SHIFT             (16U)
/*! MSKWDG_EOA_S - End of Algorithm S Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKWDG_EOA_S(x)                (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDG_EOA_S_SHIFT)) & ADC_STCR2_MSKWDG_EOA_S_MASK)

#define ADC_STCR2_MSKWDG_EOA_C_MASK              (0x40000U)
#define ADC_STCR2_MSKWDG_EOA_C_SHIFT             (18U)
/*! MSKWDG_EOA_C - End of Algorithm C Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKWDG_EOA_C(x)                (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDG_EOA_C_SHIFT)) & ADC_STCR2_MSKWDG_EOA_C_MASK)

#define ADC_STCR2_MSKST_EOC_MASK                 (0x800000U)
#define ADC_STCR2_MSKST_EOC_SHIFT                (23U)
/*! MSKST_EOC - Self-Test EOC Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKST_EOC(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKST_EOC_SHIFT)) & ADC_STCR2_MSKST_EOC_MASK)

#define ADC_STCR2_MSKWDTERR_MASK                 (0x2000000U)
#define ADC_STCR2_MSKWDTERR_SHIFT                (25U)
/*! MSKWDTERR - Watchdog Timer Error Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKWDTERR(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDTERR_SHIFT)) & ADC_STCR2_MSKWDTERR_MASK)

#define ADC_STCR2_SERR_MASK                      (0x4000000U)
#define ADC_STCR2_SERR_SHIFT                     (26U)
/*! SERR - Error Fault Injection Field (write-only) */
#define ADC_STCR2_SERR(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_SERR_SHIFT)) & ADC_STCR2_SERR_MASK)

#define ADC_STCR2_MSKWDSERR_MASK                 (0x8000000U)
#define ADC_STCR2_MSKWDSERR_SHIFT                (27U)
/*! MSKWDSERR - Watchdog Sequence Error Interrupt Mask
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_STCR2_MSKWDSERR(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDSERR_SHIFT)) & ADC_STCR2_MSKWDSERR_MASK)
/*! @} */

/*! @name STCR3 - Self-Test Configuration 3 */
/*! @{ */

#define ADC_STCR3_MSTEP_MASK                     (0x1FU)
#define ADC_STCR3_MSTEP_SHIFT                    (0U)
/*! MSTEP - Self-Test Step Select */
#define ADC_STCR3_MSTEP(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STCR3_MSTEP_SHIFT)) & ADC_STCR3_MSTEP_MASK)

#define ADC_STCR3_ALG_MASK                       (0x300U)
#define ADC_STCR3_ALG_SHIFT                      (8U)
/*! ALG - Self-Test Algorithm Select
 *  0b00..Algorithm S
 *  0b01..Reserved
 *  0b10..Algorithm C
 *  0b11..Algorithm S (for One-Shot Operation mode); Algorithm S + C (for Scan Operation mode)
 */
#define ADC_STCR3_ALG(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_STCR3_ALG_SHIFT)) & ADC_STCR3_ALG_MASK)
/*! @} */

/*! @name STBRR - Self-Test Baud Rate */
/*! @{ */

#define ADC_STBRR_BR_MASK                        (0xFFU)
#define ADC_STBRR_BR_SHIFT                       (0U)
/*! BR - Algorithm Baud Rate */
#define ADC_STBRR_BR(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_STBRR_BR_SHIFT)) & ADC_STBRR_BR_MASK)

#define ADC_STBRR_WDT_MASK                       (0x70000U)
#define ADC_STBRR_WDT_SHIFT                      (16U)
/*! WDT - Watchdog Timer Value
 *  0b000..0.1 ms ((0008h * Prescaler) cycles at 80 MHz)
 *  0b001..0.5 ms ((0027h * Prescaler) cycles at 80 MHz)
 *  0b010..1 ms ((004Eh * Prescaler) cycles at 80 MHz)
 *  0b011..2 ms ((009Ch * Prescaler) cycles at 80 MHz)
 *  0b100..5 ms ((0187h * Prescaler) cycles at 80 MHz)
 *  0b101..10 ms ((030Dh * Prescaler) cycles at 80 MHz)
 *  0b110..20 ms (061Ah * Prescaler) cycles at 80 MHz)
 *  0b111..50 ms (0F42h *Prescaler) cycles at 80 MHz)
 */
#define ADC_STBRR_WDT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_STBRR_WDT_SHIFT)) & ADC_STBRR_WDT_MASK)
/*! @} */

/*! @name STSR1 - Self-Test Status 1 */
/*! @{ */

#define ADC_STSR1_STEP_C_MASK                    (0x3E0U)
#define ADC_STSR1_STEP_C_SHIFT                   (5U)
/*! STEP_C - Algorithm C Step Number Error */
#define ADC_STSR1_STEP_C(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_STEP_C_SHIFT)) & ADC_STSR1_STEP_C_MASK)

#define ADC_STSR1_ERR_S0_MASK                    (0x800U)
#define ADC_STSR1_ERR_S0_SHIFT                   (11U)
/*! ERR_S0 - Algorithm S0 Error
 *  0b0..No VREF error
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..VREF error occurred
 */
#define ADC_STSR1_ERR_S0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_S0_SHIFT)) & ADC_STSR1_ERR_S0_MASK)

#define ADC_STSR1_ERR_S1_MASK                    (0x1000U)
#define ADC_STSR1_ERR_S1_SHIFT                   (12U)
/*! ERR_S1 - Algorithm S1 Error
 *  0b0..No VDD ERROR
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..VDD ERROR occurred
 */
#define ADC_STSR1_ERR_S1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_S1_SHIFT)) & ADC_STSR1_ERR_S1_MASK)

#define ADC_STSR1_ERR_S2_MASK                    (0x2000U)
#define ADC_STSR1_ERR_S2_SHIFT                   (13U)
/*! ERR_S2 - Algorithm S2 Error
 *  0b0..No effect
 *  0b0..No error occurred on the sampled signal
 *  0b1..Clear the flag
 *  0b1..Error occurred on the sampled signal
 */
#define ADC_STSR1_ERR_S2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_S2_SHIFT)) & ADC_STSR1_ERR_S2_MASK)

#define ADC_STSR1_ERR_C_MASK                     (0x8000U)
#define ADC_STSR1_ERR_C_SHIFT                    (15U)
/*! ERR_C - Algorithm C Error
 *  0b0..No Algorithm C error
 *  0b0..No effect
 *  0b1..Algorithm C error occurred
 *  0b1..Clear the flag
 */
#define ADC_STSR1_ERR_C(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_C_SHIFT)) & ADC_STSR1_ERR_C_MASK)

#define ADC_STSR1_WDG_EOA_S_MASK                 (0x10000U)
#define ADC_STSR1_WDG_EOA_S_SHIFT                (16U)
/*! WDG_EOA_S - Watchdog End of Algorithm S
 *  0b0..No effect
 *  0b0..Self-test end of Algorithm S conversion is not complete.
 *  0b1..Clear the flag
 *  0b1..Self-test end of Algorithm S conversion is complete.
 */
#define ADC_STSR1_WDG_EOA_S(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDG_EOA_S_SHIFT)) & ADC_STSR1_WDG_EOA_S_MASK)

#define ADC_STSR1_WDG_EOA_C_MASK                 (0x40000U)
#define ADC_STSR1_WDG_EOA_C_SHIFT                (18U)
/*! WDG_EOA_C - Watchdog End of Algorithm C
 *  0b0..No effect
 *  0b0..Self-test end of Algorithm C conversion is not complete
 *  0b1..Clear the flag
 *  0b1..Self-test end of Algorithm C conversion is complete
 */
#define ADC_STSR1_WDG_EOA_C(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDG_EOA_C_SHIFT)) & ADC_STSR1_WDG_EOA_C_MASK)

#define ADC_STSR1_ST_EOC_MASK                    (0x800000U)
#define ADC_STSR1_ST_EOC_SHIFT                   (23U)
/*! ST_EOC - Self-Test EOC
 *  0b0..No effect
 *  0b0..Self-test end of conversion is not complete
 *  0b1..Clear the flag
 *  0b1..Self-test end of conversion is complete
 */
#define ADC_STSR1_ST_EOC(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ST_EOC_SHIFT)) & ADC_STSR1_ST_EOC_MASK)

#define ADC_STSR1_OVERWR_MASK                    (0x1000000U)
#define ADC_STSR1_OVERWR_SHIFT                   (24U)
/*! OVERWR - Overwrite Error
 *  0b0..No effect
 *  0b0..No overwrite error
 *  0b1..Clear the flag
 *  0b1..Overwrite error occurred
 */
#define ADC_STSR1_OVERWR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_OVERWR_SHIFT)) & ADC_STSR1_OVERWR_MASK)

#define ADC_STSR1_WDTERR_MASK                    (0x2000000U)
#define ADC_STSR1_WDTERR_SHIFT                   (25U)
/*! WDTERR - Watchdog Timer Error
 *  0b0..No effect
 *  0b0..No failure
 *  0b1..Clear the flag
 *  0b1..Failure occurred
 */
#define ADC_STSR1_WDTERR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDTERR_SHIFT)) & ADC_STSR1_WDTERR_MASK)

#define ADC_STSR1_WDSERR_MASK                    (0x8000000U)
#define ADC_STSR1_WDSERR_SHIFT                   (27U)
/*! WDSERR - Watchdog Sequence Errors
 *  0b0..No effect
 *  0b0..No failure
 *  0b1..Clear the flag
 *  0b1..Failure occurred
 */
#define ADC_STSR1_WDSERR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDSERR_SHIFT)) & ADC_STSR1_WDSERR_MASK)
/*! @} */

/*! @name STSR2 - Self-Test Status 2 */
/*! @{ */

#define ADC_STSR2_DATA0_MASK                     (0xFFFU)
#define ADC_STSR2_DATA0_SHIFT                    (0U)
/*! DATA0 - Test Channel Converted Data when ERR_S1 Occurred */
#define ADC_STSR2_DATA0(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR2_DATA0_SHIFT)) & ADC_STSR2_DATA0_MASK)

#define ADC_STSR2_DATA1_MASK                     (0xFFF0000U)
#define ADC_STSR2_DATA1_SHIFT                    (16U)
/*! DATA1 - Test Channel Converted Data when ERR_S1 Occurred */
#define ADC_STSR2_DATA1(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR2_DATA1_SHIFT)) & ADC_STSR2_DATA1_MASK)

#define ADC_STSR2_OVFL_MASK                      (0x80000000U)
#define ADC_STSR2_OVFL_SHIFT                     (31U)
/*! OVFL - Overflow Bit
 *  0b0..Not overflow
 *  0b1..Overflow
 */
#define ADC_STSR2_OVFL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_STSR2_OVFL_SHIFT)) & ADC_STSR2_OVFL_MASK)
/*! @} */

/*! @name STSR3 - Self-Test Status 3 */
/*! @{ */

#define ADC_STSR3_DATA0_MASK                     (0xFFFU)
#define ADC_STSR3_DATA0_SHIFT                    (0U)
/*! DATA0 - Test Channel Converted Data when ERR_S0 Occurred */
#define ADC_STSR3_DATA0(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR3_DATA0_SHIFT)) & ADC_STSR3_DATA0_MASK)

#define ADC_STSR3_DATA1_MASK                     (0xFFF0000U)
#define ADC_STSR3_DATA1_SHIFT                    (16U)
/*! DATA1 - Test Channel Converted Data when ERR_C Occurred */
#define ADC_STSR3_DATA1(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR3_DATA1_SHIFT)) & ADC_STSR3_DATA1_MASK)
/*! @} */

/*! @name STSR4 - Self-Test Status 4 */
/*! @{ */

#define ADC_STSR4_DATA1_MASK                     (0xFFF0000U)
#define ADC_STSR4_DATA1_SHIFT                    (16U)
/*! DATA1 - Test Channel Converted Data When ERR_C Occurred */
#define ADC_STSR4_DATA1(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR4_DATA1_SHIFT)) & ADC_STSR4_DATA1_MASK)
/*! @} */

/*! @name STDR1 - Self-Test Data 1 */
/*! @{ */

#define ADC_STDR1_TCDATA_MASK                    (0xFFFU)
#define ADC_STDR1_TCDATA_SHIFT                   (0U)
/*! TCDATA - Test Channel Converted Data */
#define ADC_STDR1_TCDATA(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STDR1_TCDATA_SHIFT)) & ADC_STDR1_TCDATA_MASK)

#define ADC_STDR1_OWERWR_MASK                    (0x40000U)
#define ADC_STDR1_OWERWR_SHIFT                   (18U)
/*! OWERWR - Overwrite Data
 *  0b0..Data not overwritten
 *  0b1..Data overwritten
 */
#define ADC_STDR1_OWERWR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STDR1_OWERWR_SHIFT)) & ADC_STDR1_OWERWR_MASK)

#define ADC_STDR1_VALID_MASK                     (0x80000U)
#define ADC_STDR1_VALID_SHIFT                    (19U)
/*! VALID - Valid Data
 *  0b0..Data not valid
 *  0b1..Data valid
 */
#define ADC_STDR1_VALID(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STDR1_VALID_SHIFT)) & ADC_STDR1_VALID_MASK)
/*! @} */

/*! @name STDR2 - Self-Test Data 2 */
/*! @{ */

#define ADC_STDR2_IDATA_MASK                     (0xFFFU)
#define ADC_STDR2_IDATA_SHIFT                    (0U)
/*! IDATA - Integer Data */
#define ADC_STDR2_IDATA(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STDR2_IDATA_SHIFT)) & ADC_STDR2_IDATA_MASK)

#define ADC_STDR2_OVERWR_MASK                    (0x40000U)
#define ADC_STDR2_OVERWR_SHIFT                   (18U)
/*! OVERWR - Overwrite Data
 *  0b0..Data not overwritten
 *  0b1..Data overwritten
 */
#define ADC_STDR2_OVERWR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STDR2_OVERWR_SHIFT)) & ADC_STDR2_OVERWR_MASK)

#define ADC_STDR2_VALID_MASK                     (0x80000U)
#define ADC_STDR2_VALID_SHIFT                    (19U)
/*! VALID - Valid Data
 *  0b0..Data not valid
 *  0b1..Data valid
 */
#define ADC_STDR2_VALID(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STDR2_VALID_SHIFT)) & ADC_STDR2_VALID_MASK)

#define ADC_STDR2_FDATA_MASK                     (0xFFF00000U)
#define ADC_STDR2_FDATA_SHIFT                    (20U)
/*! FDATA - Fractional Data */
#define ADC_STDR2_FDATA(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STDR2_FDATA_SHIFT)) & ADC_STDR2_FDATA_MASK)
/*! @} */

/*! @name STAW0R - Self-Test Analog Watchdog 0 */
/*! @{ */

#define ADC_STAW0R_THRL_MASK                     (0xFFFU)
#define ADC_STAW0R_THRL_SHIFT                    (0U)
/*! THRL - Low Threshold Value for Algorithm S Step0 */
#define ADC_STAW0R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_THRL_SHIFT)) & ADC_STAW0R_THRL_MASK)

#define ADC_STAW0R_THRH_MASK                     (0xFFF0000U)
#define ADC_STAW0R_THRH_SHIFT                    (16U)
/*! THRH - High Threshold Value for Algorithm S Step0 */
#define ADC_STAW0R_THRH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_THRH_SHIFT)) & ADC_STAW0R_THRH_MASK)

#define ADC_STAW0R_WDTE_MASK                     (0x40000000U)
#define ADC_STAW0R_WDTE_SHIFT                    (30U)
/*! WDTE - Watchdog Timer Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_STAW0R_WDTE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_WDTE_SHIFT)) & ADC_STAW0R_WDTE_MASK)

#define ADC_STAW0R_AWDE_MASK                     (0x80000000U)
#define ADC_STAW0R_AWDE_SHIFT                    (31U)
/*! AWDE - Analog Watchdog Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_STAW0R_AWDE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_AWDE_SHIFT)) & ADC_STAW0R_AWDE_MASK)
/*! @} */

/*! @name STAW1AR - Self-Test Analog Watchdog 1A */
/*! @{ */

#define ADC_STAW1AR_THRL_MASK                    (0xFFFU)
#define ADC_STAW1AR_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold Value for Algorithm S Step1 */
#define ADC_STAW1AR_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STAW1AR_THRL_SHIFT)) & ADC_STAW1AR_THRL_MASK)

#define ADC_STAW1AR_THRH_MASK                    (0xFFF0000U)
#define ADC_STAW1AR_THRH_SHIFT                   (16U)
/*! THRH - High Threshold Value for Algorithm S Step1 */
#define ADC_STAW1AR_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STAW1AR_THRH_SHIFT)) & ADC_STAW1AR_THRH_MASK)

#define ADC_STAW1AR_AWDE_MASK                    (0x80000000U)
#define ADC_STAW1AR_AWDE_SHIFT                   (31U)
/*! AWDE - Analog Watchdog Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_STAW1AR_AWDE(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STAW1AR_AWDE_SHIFT)) & ADC_STAW1AR_AWDE_MASK)
/*! @} */

/*! @name STAW1BR - Self-Test Analog Watchdog 1B */
/*! @{ */

#define ADC_STAW1BR_THRL_MASK                    (0xFFFU)
#define ADC_STAW1BR_THRL_SHIFT                   (0U)
/*! THRL - Low Threshold Value for Algorithm S Step1 */
#define ADC_STAW1BR_THRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STAW1BR_THRL_SHIFT)) & ADC_STAW1BR_THRL_MASK)

#define ADC_STAW1BR_THRH_MASK                    (0xFFF0000U)
#define ADC_STAW1BR_THRH_SHIFT                   (16U)
/*! THRH - High Threshold Value for Algorithm S Step1 */
#define ADC_STAW1BR_THRH(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STAW1BR_THRH_SHIFT)) & ADC_STAW1BR_THRH_MASK)
/*! @} */

/*! @name STAW2R - Self-Test Analog Watchdog 2 */
/*! @{ */

#define ADC_STAW2R_THRL_MASK                     (0xFFFU)
#define ADC_STAW2R_THRL_SHIFT                    (0U)
/*! THRL - Threshold level low */
#define ADC_STAW2R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW2R_THRL_SHIFT)) & ADC_STAW2R_THRL_MASK)

#define ADC_STAW2R_AWDE_MASK                     (0x80000000U)
#define ADC_STAW2R_AWDE_SHIFT                    (31U)
/*! AWDE - Analog Watchdog Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_STAW2R_AWDE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW2R_AWDE_SHIFT)) & ADC_STAW2R_AWDE_MASK)
/*! @} */

/*! @name STAW4R - Self-Test Analog Watchdog 4 */
/*! @{ */

#define ADC_STAW4R_THRL_MASK                     (0xFFFU)
#define ADC_STAW4R_THRL_SHIFT                    (0U)
/*! THRL - Low Threshold Value for Step0 of Algorithm C */
#define ADC_STAW4R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_THRL_SHIFT)) & ADC_STAW4R_THRL_MASK)

#define ADC_STAW4R_THRH_MASK                     (0xFFF0000U)
#define ADC_STAW4R_THRH_SHIFT                    (16U)
/*! THRH - High Threshold Value for Step0 of Algorithm C */
#define ADC_STAW4R_THRH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_THRH_SHIFT)) & ADC_STAW4R_THRH_MASK)

#define ADC_STAW4R_WDTE_MASK                     (0x40000000U)
#define ADC_STAW4R_WDTE_SHIFT                    (30U)
/*! WDTE - Watchdog Timer Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_STAW4R_WDTE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_WDTE_SHIFT)) & ADC_STAW4R_WDTE_MASK)

#define ADC_STAW4R_AWDE_MASK                     (0x80000000U)
#define ADC_STAW4R_AWDE_SHIFT                    (31U)
/*! AWDE - Analog Watchdog Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_STAW4R_AWDE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_AWDE_SHIFT)) & ADC_STAW4R_AWDE_MASK)
/*! @} */

/*! @name STAW5R - Self-Test Analog Watchdog 5 */
/*! @{ */

#define ADC_STAW5R_THRL_MASK                     (0xFFFU)
#define ADC_STAW5R_THRL_SHIFT                    (0U)
/*! THRL - Low Threshold Value for Step0 of Algorithm C */
#define ADC_STAW5R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW5R_THRL_SHIFT)) & ADC_STAW5R_THRL_MASK)

#define ADC_STAW5R_THRH_MASK                     (0xFFF0000U)
#define ADC_STAW5R_THRH_SHIFT                    (16U)
/*! THRH - High Threshold Value for Step N of Algorithm C */
#define ADC_STAW5R_THRH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW5R_THRH_SHIFT)) & ADC_STAW5R_THRH_MASK)
/*! @} */

/*! @name CALSTAT - Calibration Status */
/*! @{ */

#define ADC_CALSTAT_STAT_1_MASK                  (0x1U)
#define ADC_CALSTAT_STAT_1_SHIFT                 (0U)
/*! STAT_1 - Status of Calibration Step 1
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_1(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_1_SHIFT)) & ADC_CALSTAT_STAT_1_MASK)

#define ADC_CALSTAT_STAT_2_MASK                  (0x2U)
#define ADC_CALSTAT_STAT_2_SHIFT                 (1U)
/*! STAT_2 - Status of Calibration Step 2
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_2(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_2_SHIFT)) & ADC_CALSTAT_STAT_2_MASK)

#define ADC_CALSTAT_STAT_3_MASK                  (0x4U)
#define ADC_CALSTAT_STAT_3_SHIFT                 (2U)
/*! STAT_3 - Status of Calibration Step 3
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_3(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_3_SHIFT)) & ADC_CALSTAT_STAT_3_MASK)

#define ADC_CALSTAT_STAT_4_MASK                  (0x8U)
#define ADC_CALSTAT_STAT_4_SHIFT                 (3U)
/*! STAT_4 - Status of calibration step 4
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_4(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_4_SHIFT)) & ADC_CALSTAT_STAT_4_MASK)

#define ADC_CALSTAT_STAT_5_MASK                  (0x10U)
#define ADC_CALSTAT_STAT_5_SHIFT                 (4U)
/*! STAT_5 - Status of Calibration Step 5
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_5(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_5_SHIFT)) & ADC_CALSTAT_STAT_5_MASK)

#define ADC_CALSTAT_STAT_6_MASK                  (0x20U)
#define ADC_CALSTAT_STAT_6_SHIFT                 (5U)
/*! STAT_6 - Status of Calibration Step 6
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_6(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_6_SHIFT)) & ADC_CALSTAT_STAT_6_MASK)

#define ADC_CALSTAT_STAT_7_MASK                  (0x40U)
#define ADC_CALSTAT_STAT_7_SHIFT                 (6U)
/*! STAT_7 - Status of Calibration Step 7
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_7(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_7_SHIFT)) & ADC_CALSTAT_STAT_7_MASK)

#define ADC_CALSTAT_STAT_8_MASK                  (0x80U)
#define ADC_CALSTAT_STAT_8_SHIFT                 (7U)
/*! STAT_8 - Status of Calibration Step 8
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_8(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_8_SHIFT)) & ADC_CALSTAT_STAT_8_MASK)

#define ADC_CALSTAT_STAT_9_MASK                  (0x100U)
#define ADC_CALSTAT_STAT_9_SHIFT                 (8U)
/*! STAT_9 - Status of Calibration Step 9
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_9(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_9_SHIFT)) & ADC_CALSTAT_STAT_9_MASK)

#define ADC_CALSTAT_STAT_10_MASK                 (0x200U)
#define ADC_CALSTAT_STAT_10_SHIFT                (9U)
/*! STAT_10 - Status of Calibration Step 10
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_10(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_10_SHIFT)) & ADC_CALSTAT_STAT_10_MASK)

#define ADC_CALSTAT_STAT_11_MASK                 (0x400U)
#define ADC_CALSTAT_STAT_11_SHIFT                (10U)
/*! STAT_11 - Status of Calibration Step 11
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_11(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_11_SHIFT)) & ADC_CALSTAT_STAT_11_MASK)

#define ADC_CALSTAT_STAT_12_MASK                 (0x800U)
#define ADC_CALSTAT_STAT_12_SHIFT                (11U)
/*! STAT_12 - Status of Calibration Step 12
 *  0b0..Test passed
 *  0b1..Test failed
 */
#define ADC_CALSTAT_STAT_12(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_STAT_12_SHIFT)) & ADC_CALSTAT_STAT_12_MASK)

#define ADC_CALSTAT_TEST_RESULT_MASK             (0xFFFF0000U)
#define ADC_CALSTAT_TEST_RESULT_SHIFT            (16U)
/*! TEST_RESULT - TEST_RESULT */
#define ADC_CALSTAT_TEST_RESULT(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CALSTAT_TEST_RESULT_SHIFT)) & ADC_CALSTAT_TEST_RESULT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ADC_H_ */
