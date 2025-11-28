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
**         CMSIS Peripheral Access Layer for TMU
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
 * @file PERI_TMU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TMU
 *
 * CMSIS Peripheral Access Layer for TMU
 */

#if !defined(PERI_TMU_H_)
#define PERI_TMU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- TMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Peripheral_Access_Layer TMU Peripheral Access Layer
 * @{
 */

/** TMU - Size of Registers Arrays */
#define TMU_TRITRATSR_COUNT                       16u
#define TMU_NUM_SITE_RC_COUNT                     16u

/** TMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t TMR;                               /**< Mode, offset: 0x0 */
  __IO uint32_t TSR;                               /**< Status, offset: 0x4 */
  __IO uint32_t TMSR;                              /**< Monitor Site, offset: 0x8 */
  __IO uint32_t TMTMIR;                            /**< Monitor Temperature Measurement Interval, offset: 0xC */
       uint8_t RESERVED_0[16];
  __IO uint32_t TIER;                              /**< Interrupt Enable, offset: 0x20 */
  __IO uint32_t TIDR;                              /**< Interrupt Detect, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t TIISCR;                            /**< Interrupt Immediate Site Capture, offset: 0x30 */
  __IO uint32_t TIASCR;                            /**< Interrupt Average Site Capture, offset: 0x34 */
  __IO uint32_t TICSCR;                            /**< Interrupt Critical Site Capture, offset: 0x38 */
       uint8_t RESERVED_2[4];
  __IO uint32_t TMHTCR;                            /**< Monitor High Temperature Capture, offset: 0x40 */
  __IO uint32_t TMLTCR;                            /**< Monitor Low Temperature Capture, offset: 0x44 */
  __IO uint32_t TMRTRCR;                           /**< Monitor Rising Temperature Rate Capture, offset: 0x48 */
  __IO uint32_t TMFTRCR;                           /**< Monitor Falling Temperature Rate Capture, offset: 0x4C */
  __IO uint32_t TMHTITR;                           /**< Monitor High Temperature Immediate Threshold, offset: 0x50 */
  __IO uint32_t TMHTATR;                           /**< Monitor High Temperature Average Threshold, offset: 0x54 */
  __IO uint32_t TMHTACTR;                          /**< Monitor High Temperature Average Critical Threshold, offset: 0x58 */
       uint8_t RESERVED_3[4];
  __IO uint32_t TMLTITR;                           /**< Monitor Low Temperature Immediate Threshold, offset: 0x60 */
  __IO uint32_t TMLTATR;                           /**< Monitor Low Temperature Average Threshold, offset: 0x64 */
  __IO uint32_t TMLTACTR;                          /**< Monitor Low Temperature Average Critical Threshold, offset: 0x68 */
       uint8_t RESERVED_4[4];
  __IO uint32_t TMRTRCTR;                          /**< Monitor Rising Temperature Rate Critical Threshold, offset: 0x70 */
  __IO uint32_t TMFTRCTR;                          /**< Monitor Falling Temperature Rate Critical Threshold, offset: 0x74 */
       uint8_t RESERVED_5[8];
  __IO uint32_t TTCFGR;                            /**< Temperature Configuration, offset: 0x80 */
  __IO uint32_t TSCFGR;                            /**< Sensor Configuration, offset: 0x84 */
       uint8_t RESERVED_6[120];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __I  uint32_t TRITSR;                            /**< Report Immediate Temperature at Site, array offset: 0x100, array step: 0x10 */
    __I  uint32_t TRATSR;                            /**< Report Average Temperature at Site, array offset: 0x104, array step: 0x10 */
         uint8_t RESERVED_0[8];
  } TRITRATSR[TMU_TRITRATSR_COUNT];
       uint8_t RESERVED_7[3328];
  __IO uint32_t TCMCFG;                            /**< Central Module Configuration, offset: 0xF00 */
       uint8_t RESERVED_8[12];
  __IO uint32_t TTRCR[TMU_NUM_SITE_RC_COUNT];      /**< Temperature Range Control 0..Temperature Range Control 15, array offset: 0xF10, array step: 0x4 */
} TMU_Type;

/* ----------------------------------------------------------------------------
   -- TMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Register_Masks TMU Register Masks
 * @{
 */

/*! @name TMR - Mode */
/*! @{ */

#define TMU_TMR_ALPF_MASK                        (0x3000000U)
#define TMU_TMR_ALPF_SHIFT                       (24U)
/*! ALPF - Average Low Pass Filter Setting
 *  0b00..1.0
 *  0b01..0.5
 *  0b10..0.25
 *  0b11..0.125
 */
#define TMU_TMR_ALPF(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMR_ALPF_SHIFT)) & TMU_TMR_ALPF_MASK)

#define TMU_TMR_CMD_MASK                         (0x20000000U)
#define TMU_TMR_CMD_SHIFT                        (29U)
/*! CMD - Central Module Disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define TMU_TMR_CMD(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TMR_CMD_SHIFT)) & TMU_TMR_CMD_MASK)

#define TMU_TMR_MODE_MASK                        (0xC0000000U)
#define TMU_TMR_MODE_SHIFT                       (30U)
/*! MODE - Mode
 *  0b00..Idle; low-power mode
 *  0b01..Reserved
 *  0b10..Monitoring of sites as defined by TMSR[SITE]
 *  0b11..Reserved
 */
#define TMU_TMR_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMR_MODE_SHIFT)) & TMU_TMR_MODE_MASK)
/*! @} */

/*! @name TSR - Status */
/*! @{ */

#define TMU_TSR_ORH_MASK                         (0x10000000U)
#define TMU_TSR_ORH_SHIFT                        (28U)
/*! ORH - Out-of-Range High Temperature Measurement
 *  0b0..No out-of-range high temperature measurement detected
 *  0b1..Out-of-range high temperature measurement detected
 */
#define TMU_TSR_ORH(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_ORH_SHIFT)) & TMU_TSR_ORH_MASK)

#define TMU_TSR_ORL_MASK                         (0x20000000U)
#define TMU_TSR_ORL_SHIFT                        (29U)
/*! ORL - Out-of-Range Low Temperature Measurement
 *  0b0..No out-of-range low temperature measurement detected
 *  0b1..Out-of-range low temperature measurement detected
 */
#define TMU_TSR_ORL(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_ORL_SHIFT)) & TMU_TSR_ORL_MASK)

#define TMU_TSR_MIE_MASK                         (0x40000000U)
#define TMU_TSR_MIE_SHIFT                        (30U)
/*! MIE - Monitoring Interval Exceeded
 *  0b0..Monitoring interval not exceeded
 *  0b1..Monitoring interval exceeded
 */
#define TMU_TSR_MIE(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_MIE_SHIFT)) & TMU_TSR_MIE_MASK)

#define TMU_TSR_TB_MASK                          (0x80000000U)
#define TMU_TSR_TB_SHIFT                         (31U)
/*! TB - TMU Busy
 *  0b0..TMU is idle
 *  0b1..TMU is busy
 */
#define TMU_TSR_TB(x)                            (((uint32_t)(((uint32_t)(x)) << TMU_TSR_TB_SHIFT)) & TMU_TSR_TB_MASK)
/*! @} */

/*! @name TMSR - Monitor Site */
/*! @{ */

#define TMU_TMSR_SITE_MASK                       (0xFFFFU)
#define TMU_TMSR_SITE_SHIFT                      (0U)
/*! SITE - Monitoring Site Select 15-0 */
#define TMU_TMSR_SITE(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMSR_SITE_SHIFT)) & TMU_TMSR_SITE_MASK)
/*! @} */

/*! @name TMTMIR - Monitor Temperature Measurement Interval */
/*! @{ */

#define TMU_TMTMIR_TMI_MASK                      (0xFU)
#define TMU_TMTMIR_TMI_SHIFT                     (0U)
/*! TMI - Temperature Monitoring Interval in Seconds */
#define TMU_TMTMIR_TMI(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMTMIR_TMI_SHIFT)) & TMU_TMTMIR_TMI_MASK)
/*! @} */

/*! @name TIER - Interrupt Enable */
/*! @{ */

#define TMU_TIER_FTRCTIE_MASK                    (0x1000000U)
#define TMU_TIER_FTRCTIE_SHIFT                   (24U)
/*! FTRCTIE - Falling Temperature Rate Critical Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[FTRCT] is 1
 */
#define TMU_TIER_FTRCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_FTRCTIE_SHIFT)) & TMU_TIER_FTRCTIE_MASK)

#define TMU_TIER_RTRCTIE_MASK                    (0x2000000U)
#define TMU_TIER_RTRCTIE_SHIFT                   (25U)
/*! RTRCTIE - Rising Temperature Rate Critical Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[RTRCT] is 1
 */
#define TMU_TIER_RTRCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_RTRCTIE_SHIFT)) & TMU_TIER_RTRCTIE_MASK)

#define TMU_TIER_ALTCTIE_MASK                    (0x4000000U)
#define TMU_TIER_ALTCTIE_SHIFT                   (26U)
/*! ALTCTIE - Average Low Temperature Critical Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[ALTCT] is 1
 */
#define TMU_TIER_ALTCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ALTCTIE_SHIFT)) & TMU_TIER_ALTCTIE_MASK)

#define TMU_TIER_ALTTIE_MASK                     (0x8000000U)
#define TMU_TIER_ALTTIE_SHIFT                    (27U)
/*! ALTTIE - Average Low Temperature Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[ALTT] is 1
 */
#define TMU_TIER_ALTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ALTTIE_SHIFT)) & TMU_TIER_ALTTIE_MASK)

#define TMU_TIER_ILTTIE_MASK                     (0x10000000U)
#define TMU_TIER_ILTTIE_SHIFT                    (28U)
/*! ILTTIE - Immediate Low Temperature Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[ILTT] is 1
 */
#define TMU_TIER_ILTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ILTTIE_SHIFT)) & TMU_TIER_ILTTIE_MASK)

#define TMU_TIER_AHTCTIE_MASK                    (0x20000000U)
#define TMU_TIER_AHTCTIE_SHIFT                   (29U)
/*! AHTCTIE - Average High Temperature Critical Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[AHTCT] is 1
 */
#define TMU_TIER_AHTCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_AHTCTIE_SHIFT)) & TMU_TIER_AHTCTIE_MASK)

#define TMU_TIER_AHTTIE_MASK                     (0x40000000U)
#define TMU_TIER_AHTTIE_SHIFT                    (30U)
/*! AHTTIE - Average High Temperature Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[AHTT] is 1
 */
#define TMU_TIER_AHTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_AHTTIE_SHIFT)) & TMU_TIER_AHTTIE_MASK)

#define TMU_TIER_IHTTIE_MASK                     (0x80000000U)
#define TMU_TIER_IHTTIE_SHIFT                    (31U)
/*! IHTTIE - Immediate High Temperature Threshold Interrupt Enable
 *  0b0..Disabled
 *  0b1..Interrupt enabled; generates an interrupt if TIDR[IHTT] is 1
 */
#define TMU_TIER_IHTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_IHTTIE_SHIFT)) & TMU_TIER_IHTTIE_MASK)
/*! @} */

/*! @name TIDR - Interrupt Detect */
/*! @{ */

#define TMU_TIDR_FTRCT_MASK                      (0x1000000U)
#define TMU_TIDR_FTRCT_SHIFT                     (24U)
/*! FTRCT - Falling Temperature Rate Critical Threshold
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites exceed the falling temperature rate critical threshold, as defined by .
 *       TICSCR[SITE] captures the sites that exceed the threshold.
 */
#define TMU_TIDR_FTRCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_FTRCT_SHIFT)) & TMU_TIDR_FTRCT_MASK)

#define TMU_TIDR_RTRCT_MASK                      (0x2000000U)
#define TMU_TIDR_RTRCT_SHIFT                     (25U)
/*! RTRCT - Rising Temperature Rate Critical Threshold
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites pass the rising temperature rate critical threshold, as defined by .
 *       TICSCR[SITE] captures the sites that exceed the threshold.
 */
#define TMU_TIDR_RTRCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_RTRCT_SHIFT)) & TMU_TIDR_RTRCT_MASK)

#define TMU_TIDR_ALTCT_MASK                      (0x4000000U)
#define TMU_TIDR_ALTCT_SHIFT                     (26U)
/*! ALTCT - Average Low Temperature Critical Threshold
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites pass the average low temperature threshold, as defined by . TICSCR[SITE]
 *       captures the sites that pass the threshold.
 */
#define TMU_TIDR_ALTCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ALTCT_SHIFT)) & TMU_TIDR_ALTCT_MASK)

#define TMU_TIDR_ALTT_MASK                       (0x8000000U)
#define TMU_TIDR_ALTT_SHIFT                      (27U)
/*! ALTT - Average Low Temperature Threshold
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites pass the average low temperature threshold, as defined by . TIASCR[SITE]
 *       captures the sites that pass the threshold.
 */
#define TMU_TIDR_ALTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ALTT_SHIFT)) & TMU_TIDR_ALTT_MASK)

#define TMU_TIDR_ILTT_MASK                       (0x10000000U)
#define TMU_TIDR_ILTT_SHIFT                      (28U)
/*! ILTT - Immediate Low Temperature Threshold
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites has passed the immediate low temperature threshold, as defined by . This
 *       includes an out-of-range measured temperature below the minimum calibrated temperature. TIISCR[SITE] captures
 *       the sites that pass the threshold.
 */
#define TMU_TIDR_ILTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ILTT_SHIFT)) & TMU_TIDR_ILTT_MASK)

#define TMU_TIDR_AHTCT_MASK                      (0x20000000U)
#define TMU_TIDR_AHTCT_SHIFT                     (29U)
/*! AHTCT - Average High Temperature Critical Threshold Exceeded
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites exceed the average high temperature critical threshold, as defined by .
 *       TICSCR[SITE] captures the sites that exceed the threshold.
 */
#define TMU_TIDR_AHTCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_AHTCT_SHIFT)) & TMU_TIDR_AHTCT_MASK)

#define TMU_TIDR_AHTT_MASK                       (0x40000000U)
#define TMU_TIDR_AHTT_SHIFT                      (30U)
/*! AHTT - Average High Temperature Threshold Exceeded
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites exceed the average high temperature threshold, as defined by . TIASCR[SITE]
 *       captures the sites that exceed the threshold.
 */
#define TMU_TIDR_AHTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_AHTT_SHIFT)) & TMU_TIDR_AHTT_MASK)

#define TMU_TIDR_IHTT_MASK                       (0x80000000U)
#define TMU_TIDR_IHTT_SHIFT                      (31U)
/*! IHTT - Immediate High Temperature Threshold Exceeded
 *  0b0..No threshold exceeded
 *  0b1..One or more monitored sites has exceeded the immediate high temperature threshold, as defined by . This
 *       includes an out-of-range measured temperature above the maximum calibrated temperature. TIISCR[SITE]
 *       captures the sites that exceed the threshold.
 */
#define TMU_TIDR_IHTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_IHTT_SHIFT)) & TMU_TIDR_IHTT_MASK)
/*! @} */

/*! @name TIISCR - Interrupt Immediate Site Capture */
/*! @{ */

#define TMU_TIISCR_SITE_MASK                     (0xFFFFU)
#define TMU_TIISCR_SITE_SHIFT                    (0U)
/*! SITE - Temperature Sensor Site */
#define TMU_TIISCR_SITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIISCR_SITE_SHIFT)) & TMU_TIISCR_SITE_MASK)
/*! @} */

/*! @name TIASCR - Interrupt Average Site Capture */
/*! @{ */

#define TMU_TIASCR_SITE_MASK                     (0xFFFFU)
#define TMU_TIASCR_SITE_SHIFT                    (0U)
/*! SITE - Temperature Sensor Site */
#define TMU_TIASCR_SITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIASCR_SITE_SHIFT)) & TMU_TIASCR_SITE_MASK)
/*! @} */

/*! @name TICSCR - Interrupt Critical Site Capture */
/*! @{ */

#define TMU_TICSCR_SITE_MASK                     (0xFFFFU)
#define TMU_TICSCR_SITE_SHIFT                    (0U)
/*! SITE - Temperature Sensor Site */
#define TMU_TICSCR_SITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TICSCR_SITE_SHIFT)) & TMU_TICSCR_SITE_MASK)
/*! @} */

/*! @name TMHTCR - Monitor High Temperature Capture */
/*! @{ */

#define TMU_TMHTCR_TEMP_MASK                     (0x1FFU)
#define TMU_TMHTCR_TEMP_SHIFT                    (0U)
/*! TEMP - Highest Temperature Recorded in Kelvin by Any Enabled Monitored Site */
#define TMU_TMHTCR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCR_TEMP_SHIFT)) & TMU_TMHTCR_TEMP_MASK)

#define TMU_TMHTCR_TP5_MASK                      (0x200U)
#define TMU_TMHTCR_TP5_SHIFT                     (9U)
/*! TP5 - Highest Temperature Recorded in Kelvin by Any Enabled Monitored Site */
#define TMU_TMHTCR_TP5(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCR_TP5_SHIFT)) & TMU_TMHTCR_TP5_MASK)

#define TMU_TMHTCR_V_MASK                        (0x80000000U)
#define TMU_TMHTCR_V_SHIFT                       (31U)
/*! V - Valid Reading
 *  0b0..Temperature reading is not valid due to no measured temperature within the calibrated sensor range for an enabled monitored site
 *  0b1..Temperature reading is valid
 */
#define TMU_TMHTCR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCR_V_SHIFT)) & TMU_TMHTCR_V_MASK)
/*! @} */

/*! @name TMLTCR - Monitor Low Temperature Capture */
/*! @{ */

#define TMU_TMLTCR_TEMP_MASK                     (0x1FFU)
#define TMU_TMLTCR_TEMP_SHIFT                    (0U)
/*! TEMP - Lowest Temperature in Kelvin that Any Enabled Monitored Site Records */
#define TMU_TMLTCR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMLTCR_TEMP_SHIFT)) & TMU_TMLTCR_TEMP_MASK)

#define TMU_TMLTCR_TP5_MASK                      (0x200U)
#define TMU_TMLTCR_TP5_SHIFT                     (9U)
/*! TP5 - Lowest Temperature in Kelvin that Any Enabled Monitored Site Records */
#define TMU_TMLTCR_TP5(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMLTCR_TP5_SHIFT)) & TMU_TMLTCR_TP5_MASK)

#define TMU_TMLTCR_V_MASK                        (0x80000000U)
#define TMU_TMLTCR_V_SHIFT                       (31U)
/*! V - Valid Reading
 *  0b0..Temperature reading is not valid because of no measured temperature within the sensor calibration range for an enabled monitored site
 *  0b1..Temperature reading is valid
 */
#define TMU_TMLTCR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMLTCR_V_SHIFT)) & TMU_TMLTCR_V_MASK)
/*! @} */

/*! @name TMRTRCR - Monitor Rising Temperature Rate Capture */
/*! @{ */

#define TMU_TMRTRCR_TEMP_MASK                    (0xFFU)
#define TMU_TMRTRCR_TEMP_SHIFT                   (0U)
/*! TEMP - Highest Rising Temperature Rate Change in Kelvin that Any Enabled Monitored Site Records */
#define TMU_TMRTRCR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCR_TEMP_SHIFT)) & TMU_TMRTRCR_TEMP_MASK)

#define TMU_TMRTRCR_V_MASK                       (0x80000000U)
#define TMU_TMRTRCR_V_SHIFT                      (31U)
/*! V - Valid Reading
 *  0b0..Temperature reading is not valid because of no two successive measured temperatures within the sensor
 *       calibration range for an enabled monitored site
 *  0b1..Temperature reading is valid
 */
#define TMU_TMRTRCR_V(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCR_V_SHIFT)) & TMU_TMRTRCR_V_MASK)
/*! @} */

/*! @name TMFTRCR - Monitor Falling Temperature Rate Capture */
/*! @{ */

#define TMU_TMFTRCR_TEMP_MASK                    (0xFFU)
#define TMU_TMFTRCR_TEMP_SHIFT                   (0U)
/*! TEMP - Highest Falling Temperature Rate Change in Kelvin that Any Enabled Monitored Site Records */
#define TMU_TMFTRCR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCR_TEMP_SHIFT)) & TMU_TMFTRCR_TEMP_MASK)

#define TMU_TMFTRCR_V_MASK                       (0x80000000U)
#define TMU_TMFTRCR_V_SHIFT                      (31U)
/*! V - Valid Reading
 *  0b0..Temperature reading is not valid because of no two successive measured temperatures within the sensor
 *       calibration range for an enabled monitored site
 *  0b1..Temperature reading is valid
 */
#define TMU_TMFTRCR_V(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCR_V_SHIFT)) & TMU_TMFTRCR_V_MASK)
/*! @} */

/*! @name TMHTITR - Monitor High Temperature Immediate Threshold */
/*! @{ */

#define TMU_TMHTITR_TEMP_MASK                    (0x1FFU)
#define TMU_TMHTITR_TEMP_SHIFT                   (0U)
/*! TEMP - High Temperature Immediate Threshold Value */
#define TMU_TMHTITR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_TEMP_SHIFT)) & TMU_TMHTITR_TEMP_MASK)

#define TMU_TMHTITR_EN_MASK                      (0x80000000U)
#define TMU_TMHTITR_EN_SHIFT                     (31U)
/*! EN - Enable Threshold
 *  0b0..Disabled
 *  0b1..Threshold enabled
 */
#define TMU_TMHTITR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_EN_SHIFT)) & TMU_TMHTITR_EN_MASK)
/*! @} */

/*! @name TMHTATR - Monitor High Temperature Average Threshold */
/*! @{ */

#define TMU_TMHTATR_TEMP_MASK                    (0x1FFU)
#define TMU_TMHTATR_TEMP_SHIFT                   (0U)
/*! TEMP - High Temperature Average Threshold Value */
#define TMU_TMHTATR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_TEMP_SHIFT)) & TMU_TMHTATR_TEMP_MASK)

#define TMU_TMHTATR_EN_MASK                      (0x80000000U)
#define TMU_TMHTATR_EN_SHIFT                     (31U)
/*! EN - Enable Threshold
 *  0b0..Disabled
 *  0b1..Threshold enabled
 */
#define TMU_TMHTATR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_EN_SHIFT)) & TMU_TMHTATR_EN_MASK)
/*! @} */

/*! @name TMHTACTR - Monitor High Temperature Average Critical Threshold */
/*! @{ */

#define TMU_TMHTACTR_TEMP_MASK                   (0x1FFU)
#define TMU_TMHTACTR_TEMP_SHIFT                  (0U)
/*! TEMP - High Temperature Average Critical Threshold Value */
#define TMU_TMHTACTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_TEMP_SHIFT)) & TMU_TMHTACTR_TEMP_MASK)

#define TMU_TMHTACTR_EN_MASK                     (0x80000000U)
#define TMU_TMHTACTR_EN_SHIFT                    (31U)
/*! EN - Enable Threshold
 *  0b0..Disabled
 *  0b1..Threshold enabled
 */
#define TMU_TMHTACTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_EN_SHIFT)) & TMU_TMHTACTR_EN_MASK)
/*! @} */

/*! @name TMLTITR - Monitor Low Temperature Immediate Threshold */
/*! @{ */

#define TMU_TMLTITR_TEMP_MASK                    (0x1FFU)
#define TMU_TMLTITR_TEMP_SHIFT                   (0U)
/*! TEMP - Low Temperature Immediate Threshold Value */
#define TMU_TMLTITR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMLTITR_TEMP_SHIFT)) & TMU_TMLTITR_TEMP_MASK)

#define TMU_TMLTITR_EN_MASK                      (0x80000000U)
#define TMU_TMLTITR_EN_SHIFT                     (31U)
/*! EN - Enable Threshold
 *  0b0..Disabled
 *  0b1..Threshold enabled
 */
#define TMU_TMLTITR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMLTITR_EN_SHIFT)) & TMU_TMLTITR_EN_MASK)
/*! @} */

/*! @name TMLTATR - Monitor Low Temperature Average Threshold */
/*! @{ */

#define TMU_TMLTATR_TEMP_MASK                    (0x1FFU)
#define TMU_TMLTATR_TEMP_SHIFT                   (0U)
/*! TEMP - Low Temperature Average Threshold Value */
#define TMU_TMLTATR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMLTATR_TEMP_SHIFT)) & TMU_TMLTATR_TEMP_MASK)

#define TMU_TMLTATR_EN_MASK                      (0x80000000U)
#define TMU_TMLTATR_EN_SHIFT                     (31U)
/*! EN - Enable Threshold
 *  0b0..Disabled
 *  0b1..Threshold enabled
 */
#define TMU_TMLTATR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMLTATR_EN_SHIFT)) & TMU_TMLTATR_EN_MASK)
/*! @} */

/*! @name TMLTACTR - Monitor Low Temperature Average Critical Threshold */
/*! @{ */

#define TMU_TMLTACTR_TEMP_MASK                   (0x1FFU)
#define TMU_TMLTACTR_TEMP_SHIFT                  (0U)
/*! TEMP - Low Temperature Average Critical Threshold Value */
#define TMU_TMLTACTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMLTACTR_TEMP_SHIFT)) & TMU_TMLTACTR_TEMP_MASK)

#define TMU_TMLTACTR_EN_MASK                     (0x80000000U)
#define TMU_TMLTACTR_EN_SHIFT                    (31U)
/*! EN - Enable Threshold
 *  0b0..Disabled
 *  0b1..Threshold enabled
 */
#define TMU_TMLTACTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMLTACTR_EN_SHIFT)) & TMU_TMLTACTR_EN_MASK)
/*! @} */

/*! @name TMRTRCTR - Monitor Rising Temperature Rate Critical Threshold */
/*! @{ */

#define TMU_TMRTRCTR_TEMP_MASK                   (0xFFU)
#define TMU_TMRTRCTR_TEMP_SHIFT                  (0U)
/*! TEMP - Temperature Difference Between Two Measurements From the Same Site */
#define TMU_TMRTRCTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCTR_TEMP_SHIFT)) & TMU_TMRTRCTR_TEMP_MASK)

#define TMU_TMRTRCTR_EN_MASK                     (0x80000000U)
#define TMU_TMRTRCTR_EN_SHIFT                    (31U)
/*! EN - Enable Threshold
 *  0b0..Disabled
 *  0b1..Threshold enabled
 */
#define TMU_TMRTRCTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCTR_EN_SHIFT)) & TMU_TMRTRCTR_EN_MASK)
/*! @} */

/*! @name TMFTRCTR - Monitor Falling Temperature Rate Critical Threshold */
/*! @{ */

#define TMU_TMFTRCTR_TEMP_MASK                   (0xFFU)
#define TMU_TMFTRCTR_TEMP_SHIFT                  (0U)
/*! TEMP - Temperature Difference Between Two Measurements From the Same Site */
#define TMU_TMFTRCTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCTR_TEMP_SHIFT)) & TMU_TMFTRCTR_TEMP_MASK)

#define TMU_TMFTRCTR_EN_MASK                     (0x80000000U)
#define TMU_TMFTRCTR_EN_SHIFT                    (31U)
/*! EN - Enable threshold
 *  0b0..Disabled
 *  0b1..Threshold Enabled
 */
#define TMU_TMFTRCTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCTR_EN_SHIFT)) & TMU_TMFTRCTR_EN_MASK)
/*! @} */

/*! @name TTCFGR - Temperature Configuration */
/*! @{ */

#define TMU_TTCFGR_CAL_PT_MASK                   (0xFU)
#define TMU_TTCFGR_CAL_PT_SHIFT                  (0U)
/*! CAL_PT - Calibration Point */
#define TMU_TTCFGR_CAL_PT(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TTCFGR_CAL_PT_SHIFT)) & TMU_TTCFGR_CAL_PT_MASK)
/*! @} */

/*! @name TSCFGR - Sensor Configuration */
/*! @{ */

#define TMU_TSCFGR_SENSOR_MASK                   (0x1FFU)
#define TMU_TSCFGR_SENSOR_SHIFT                  (0U)
/*! SENSOR - Sensor Value */
#define TMU_TSCFGR_SENSOR(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TSCFGR_SENSOR_SHIFT)) & TMU_TSCFGR_SENSOR_MASK)
/*! @} */

/*! @name TRITSR - Report Immediate Temperature at Site */
/*! @{ */

#define TMU_TRITSR_TEMP_MASK                     (0x1FFU)
#define TMU_TRITSR_TEMP_SHIFT                    (0U)
/*! TEMP - Last Temperature Reading in Kelvin at the Site */
#define TMU_TRITSR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_TEMP_SHIFT)) & TMU_TRITSR_TEMP_MASK)

#define TMU_TRITSR_TP5_MASK                      (0x200U)
#define TMU_TRITSR_TP5_SHIFT                     (9U)
/*! TP5 - Last Temperature Reading in Kelvin at the Site */
#define TMU_TRITSR_TP5(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_TP5_SHIFT)) & TMU_TRITSR_TP5_MASK)

#define TMU_TRITSR_V_MASK                        (0x80000000U)
#define TMU_TRITSR_V_SHIFT                       (31U)
/*! V - Valid Measured Temperature
 *  0b0..Not valid; temperature is out of sensor calibration range or the first measurement is still pending
 *  0b1..Valid
 */
#define TMU_TRITSR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_V_SHIFT)) & TMU_TRITSR_V_MASK)
/*! @} */

/* The count of TMU_TRITSR */
#define TMU_TRITSR_COUNT                         (16U)

/*! @name TRATSR - Report Average Temperature at Site */
/*! @{ */

#define TMU_TRATSR_TEMP_MASK                     (0x1FFU)
#define TMU_TRATSR_TEMP_SHIFT                    (0U)
/*! TEMP - Average Temperature Reading in Kelvin at the Site */
#define TMU_TRATSR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_TEMP_SHIFT)) & TMU_TRATSR_TEMP_MASK)

#define TMU_TRATSR_V_MASK                        (0x80000000U)
#define TMU_TRATSR_V_SHIFT                       (31U)
/*! V - Valid Measured Temperature
 *  0b0..Not valid; temperature is out of sensor range or the first measurement is still pending
 *  0b1..Valid
 */
#define TMU_TRATSR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_V_SHIFT)) & TMU_TRATSR_V_MASK)
/*! @} */

/* The count of TMU_TRATSR */
#define TMU_TRATSR_COUNT                         (16U)

/*! @name TCMCFG - Central Module Configuration */
/*! @{ */

#define TMU_TCMCFG_DAC_OFFSET_MASK               (0x7FU)
#define TMU_TCMCFG_DAC_OFFSET_SHIFT              (0U)
/*! DAC_OFFSET - DAC Offset */
#define TMU_TCMCFG_DAC_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DAC_OFFSET_SHIFT)) & TMU_TCMCFG_DAC_OFFSET_MASK)

#define TMU_TCMCFG_CMET_MASK                     (0x300U)
#define TMU_TCMCFG_CMET_SHIFT                    (8U)
/*! CMET - Central Module Enable Time */
#define TMU_TCMCFG_CMET(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_CMET_SHIFT)) & TMU_TCMCFG_CMET_MASK)

#define TMU_TCMCFG_DFD_MASK                      (0xC00U)
#define TMU_TCMCFG_DFD_SHIFT                     (10U)
/*! DFD - Digital Filter Depth */
#define TMU_TCMCFG_DFD(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DFD_SHIFT)) & TMU_TCMCFG_DFD_MASK)

#define TMU_TCMCFG_CLK_DIV_MASK                  (0xF000U)
#define TMU_TCMCFG_CLK_DIV_SHIFT                 (12U)
/*! CLK_DIV - Clock Divider */
#define TMU_TCMCFG_CLK_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_CLK_DIV_SHIFT)) & TMU_TCMCFG_CLK_DIV_MASK)

#define TMU_TCMCFG_SAR_RDY_MASK                  (0x10000U)
#define TMU_TCMCFG_SAR_RDY_SHIFT                 (16U)
/*! SAR_RDY - SAR Ready
 *  0b0..SAR not ready to receive command
 *  0b1..SAR ready to receive command
 */
#define TMU_TCMCFG_SAR_RDY(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_SAR_RDY_SHIFT)) & TMU_TCMCFG_SAR_RDY_MASK)

#define TMU_TCMCFG_RCTC_MASK                     (0x7000000U)
#define TMU_TCMCFG_RCTC_SHIFT                    (24U)
/*! RCTC - RC Time Constant Setting */
#define TMU_TCMCFG_RCTC(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_RCTC_SHIFT)) & TMU_TCMCFG_RCTC_MASK)

#define TMU_TCMCFG_DEMA_MASK                     (0x10000000U)
#define TMU_TCMCFG_DEMA_SHIFT                    (28U)
/*! DEMA - Dynamic Element Match Averaging Mode */
#define TMU_TCMCFG_DEMA(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DEMA_SHIFT)) & TMU_TCMCFG_DEMA_MASK)

#define TMU_TCMCFG_OCS_MASK                      (0x20000000U)
#define TMU_TCMCFG_OCS_SHIFT                     (29U)
/*! OCS - Offset Cancellation Manual Setting */
#define TMU_TCMCFG_OCS(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_OCS_SHIFT)) & TMU_TCMCFG_OCS_MASK)

#define TMU_TCMCFG_OCM_MASK                      (0x40000000U)
#define TMU_TCMCFG_OCM_SHIFT                     (30U)
/*! OCM - Offset Cancellation Mode */
#define TMU_TCMCFG_OCM(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_OCM_SHIFT)) & TMU_TCMCFG_OCM_MASK)

#define TMU_TCMCFG_DPM_MASK                      (0x80000000U)
#define TMU_TCMCFG_DPM_SHIFT                     (31U)
/*! DPM - Dynamic Power Management */
#define TMU_TCMCFG_DPM(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DPM_SHIFT)) & TMU_TCMCFG_DPM_MASK)
/*! @} */

/*! @name TTRCR - Temperature Range Control 0..Temperature Range Control 15 */
/*! @{ */

#define TMU_TTRCR_TEMP_MASK                      (0x1FFU)
#define TMU_TTRCR_TEMP_SHIFT                     (0U)
/*! TEMP - Temperature in Kelvin for the Calibration Point */
#define TMU_TTRCR_TEMP(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TTRCR_TEMP_SHIFT)) & TMU_TTRCR_TEMP_MASK)

#define TMU_TTRCR_V_MASK                         (0x80000000U)
#define TMU_TTRCR_V_SHIFT                        (31U)
/*! V - Calibration Point is Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define TMU_TTRCR_V(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TTRCR_V_SHIFT)) & TMU_TTRCR_V_MASK)
/*! @} */

/* The count of TMU_TTRCR */
#define TMU_TTRCR_COUNT                          (16U)


/*!
 * @}
 */ /* end of group TMU_Register_Masks */


/*!
 * @}
 */ /* end of group TMU_Peripheral_Access_Layer */


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


#endif  /* PERI_TMU_H_ */
