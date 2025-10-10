/*
** ###################################################################
**     Processors:          MCXN247VAB
**                          MCXN247VDF
**                          MCXN247VKL
**                          MCXN247VPB
**                          MCXN526VDF_cm33_core0
**                          MCXN526VDF_cm33_core1
**                          MCXN526VKL_cm33_core0
**                          MCXN526VKL_cm33_core1
**                          MCXN527VAB_cm33_core0
**                          MCXN527VAB_cm33_core1
**                          MCXN527VDF_cm33_core0
**                          MCXN527VDF_cm33_core1
**                          MCXN527VKL_cm33_core0
**                          MCXN527VKL_cm33_core1
**                          MCXN536VAB_cm33_core0
**                          MCXN536VAB_cm33_core1
**                          MCXN536VDF_cm33_core0
**                          MCXN536VDF_cm33_core1
**                          MCXN536VKL_cm33_core0
**                          MCXN536VKL_cm33_core1
**                          MCXN536VPB_cm33_core0
**                          MCXN536VPB_cm33_core1
**                          MCXN537VAB_cm33_core0
**                          MCXN537VAB_cm33_core1
**                          MCXN537VDF_cm33_core0
**                          MCXN537VDF_cm33_core1
**                          MCXN537VKL_cm33_core0
**                          MCXN537VKL_cm33_core1
**                          MCXN537VPB_cm33_core0
**                          MCXN537VPB_cm33_core1
**                          MCXN546VAB_cm33_core0
**                          MCXN546VAB_cm33_core1
**                          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VAB_cm33_core0
**                          MCXN547VAB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN556SCDF_cm33_core0
**                          MCXN556SCDF_cm33_core1
**                          MCXN946VAB_cm33_core0
**                          MCXN946VAB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VAB_cm33_core0
**                          MCXN947VAB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250811
**
**     Abstract:
**         CMSIS Peripheral Access Layer for QDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_QDC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for QDC
 *
 * CMSIS Peripheral Access Layer for QDC
 */

#if !defined(PERI_QDC_H_)
#define PERI_QDC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN247VAB) || defined(CPU_MCXN247VDF) || defined(CPU_MCXN247VKL) || defined(CPU_MCXN247VPB))
#include "MCXN247_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core0) || defined(CPU_MCXN526VKL_cm33_core0))
#include "MCXN526_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core1) || defined(CPU_MCXN526VKL_cm33_core1))
#include "MCXN526_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core0) || defined(CPU_MCXN527VDF_cm33_core0) || defined(CPU_MCXN527VKL_cm33_core0))
#include "MCXN527_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core1) || defined(CPU_MCXN527VDF_cm33_core1) || defined(CPU_MCXN527VKL_cm33_core1))
#include "MCXN527_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core0) || defined(CPU_MCXN536VDF_cm33_core0) || defined(CPU_MCXN536VKL_cm33_core0) || defined(CPU_MCXN536VPB_cm33_core0))
#include "MCXN536_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core1) || defined(CPU_MCXN536VDF_cm33_core1) || defined(CPU_MCXN536VKL_cm33_core1) || defined(CPU_MCXN536VPB_cm33_core1))
#include "MCXN536_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core0) || defined(CPU_MCXN537VDF_cm33_core0) || defined(CPU_MCXN537VKL_cm33_core0) || defined(CPU_MCXN537VPB_cm33_core0))
#include "MCXN537_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core1) || defined(CPU_MCXN537VDF_cm33_core1) || defined(CPU_MCXN537VKL_cm33_core1) || defined(CPU_MCXN537VPB_cm33_core1))
#include "MCXN537_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core0) || defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core1) || defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core0) || defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core1) || defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core0))
#include "MCXN556S_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core1))
#include "MCXN556S_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core0) || defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core1) || defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core0) || defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core1) || defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
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
   -- QDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QDC_Peripheral_Access_Layer QDC Peripheral Access Layer
 * @{
 */

/** QDC - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< Control, offset: 0x0 */
  __IO uint16_t FILT;                              /**< Input Filter, offset: 0x2 */
  __IO uint16_t WTR;                               /**< Watchdog Timeout, offset: 0x4 */
  __IO uint16_t POSD;                              /**< Position Difference Counter, offset: 0x6 */
  __I  uint16_t POSDH;                             /**< Position Difference Hold, offset: 0x8 */
  __IO uint16_t REV;                               /**< Revolution Counter, offset: 0xA */
  __I  uint16_t REVH;                              /**< Revolution Hold, offset: 0xC */
  __IO uint16_t UPOS;                              /**< Upper Position Counter, offset: 0xE */
  __IO uint16_t LPOS;                              /**< Lower Position Counter, offset: 0x10 */
  __I  uint16_t UPOSH;                             /**< Upper Position Hold, offset: 0x12 */
  __I  uint16_t LPOSH;                             /**< Lower Position Hold, offset: 0x14 */
  __IO uint16_t UINIT;                             /**< Upper Initialization, offset: 0x16 */
  __IO uint16_t LINIT;                             /**< Lower Initialization, offset: 0x18 */
  __I  uint16_t IMR;                               /**< Input Monitor, offset: 0x1A */
  __IO uint16_t TST;                               /**< Test, offset: 0x1C */
  __IO uint16_t CTRL2;                             /**< Control 2, offset: 0x1E */
  __IO uint16_t UMOD;                              /**< Upper Modulus, offset: 0x20 */
  __IO uint16_t LMOD;                              /**< Lower Modulus, offset: 0x22 */
  __IO uint16_t UCOMP;                             /**< Upper Position Compare, offset: 0x24 */
  __IO uint16_t LCOMP;                             /**< Lower Position Compare, offset: 0x26 */
  __I  uint16_t LASTEDGE;                          /**< Last Edge Time, offset: 0x28 */
  __I  uint16_t LASTEDGEH;                         /**< Last Edge Time Hold, offset: 0x2A */
  __I  uint16_t POSDPER;                           /**< Position Difference Period Counter, offset: 0x2C */
  __I  uint16_t POSDPERBFR;                        /**< Position Difference Period Buffer, offset: 0x2E */
  __I  uint16_t POSDPERH;                          /**< Position Difference Period Hold, offset: 0x30 */
  __IO uint16_t CTRL3;                             /**< Control 3, offset: 0x32 */
} QDC_Type;

/* ----------------------------------------------------------------------------
   -- QDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QDC_Register_Masks QDC Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define QDC_CTRL_CMPIE_MASK                      (0x1U)
#define QDC_CTRL_CMPIE_SHIFT                     (0U)
/*! CMPIE - Compare Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL_CMPIE(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_CMPIE_SHIFT)) & QDC_CTRL_CMPIE_MASK)

#define QDC_CTRL_CMPIRQ_MASK                     (0x2U)
#define QDC_CTRL_CMPIRQ_SHIFT                    (1U)
/*! CMPIRQ - Compare Interrupt Request
 *  0b0..No match has occurred
 *  0b1..COMP match has occurred
 */
#define QDC_CTRL_CMPIRQ(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_CMPIRQ_SHIFT)) & QDC_CTRL_CMPIRQ_MASK)

#define QDC_CTRL_WDE_MASK                        (0x4U)
#define QDC_CTRL_WDE_SHIFT                       (2U)
/*! WDE - Watchdog Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL_WDE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_WDE_SHIFT)) & QDC_CTRL_WDE_MASK)

#define QDC_CTRL_DIE_MASK                        (0x8U)
#define QDC_CTRL_DIE_SHIFT                       (3U)
/*! DIE - Watchdog Timeout Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL_DIE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_DIE_SHIFT)) & QDC_CTRL_DIE_MASK)

#define QDC_CTRL_DIRQ_MASK                       (0x10U)
#define QDC_CTRL_DIRQ_SHIFT                      (4U)
/*! DIRQ - Watchdog Timeout Interrupt Request
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define QDC_CTRL_DIRQ(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_DIRQ_SHIFT)) & QDC_CTRL_DIRQ_MASK)

#define QDC_CTRL_XNE_MASK                        (0x20U)
#define QDC_CTRL_XNE_SHIFT                       (5U)
/*! XNE - Select Positive and Negative Edge of INDEX Pulse
 *  0b0..Use positive edge
 *  0b1..Use negative edge
 */
#define QDC_CTRL_XNE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XNE_SHIFT)) & QDC_CTRL_XNE_MASK)

#define QDC_CTRL_XIP_MASK                        (0x40U)
#define QDC_CTRL_XIP_SHIFT                       (6U)
/*! XIP - INDEX Triggered Initialization of Position Counters UPOS and LPOS
 *  0b0..Does not initialize
 *  0b1..Initializes
 */
#define QDC_CTRL_XIP(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XIP_SHIFT)) & QDC_CTRL_XIP_MASK)

#define QDC_CTRL_XIE_MASK                        (0x80U)
#define QDC_CTRL_XIE_SHIFT                       (7U)
/*! XIE - INDEX Pulse Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL_XIE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XIE_SHIFT)) & QDC_CTRL_XIE_MASK)

#define QDC_CTRL_XIRQ_MASK                       (0x100U)
#define QDC_CTRL_XIRQ_SHIFT                      (8U)
/*! XIRQ - INDEX Pulse Interrupt Request
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define QDC_CTRL_XIRQ(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XIRQ_SHIFT)) & QDC_CTRL_XIRQ_MASK)

#define QDC_CTRL_PH1_MASK                        (0x200U)
#define QDC_CTRL_PH1_SHIFT                       (9U)
/*! PH1 - Enable Signal Phase Count Mode
 *  0b0..Uses the standard quadrature decoder, where PHASEA and PHASEB represent a two-phase quadrature signal.
 *  0b1..Bypasses the quadrature decoder. A positive transition of the PHASEA input generates a count signal.
 *       PHASEB input and CTRL[REV] controls the counter direction. If the value of CTRL[REV] and PHASEB are identical;
 *       then count is up. If the value of CTRL[REV] and PHASEB is different, then count is down.
 */
#define QDC_CTRL_PH1(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_PH1_SHIFT)) & QDC_CTRL_PH1_MASK)

#define QDC_CTRL_REV_MASK                        (0x400U)
#define QDC_CTRL_REV_SHIFT                       (10U)
/*! REV - Enable Reverse Direction Counting
 *  0b0..Counts normally
 *  0b1..Counts in the reverse direction
 */
#define QDC_CTRL_REV(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_REV_SHIFT)) & QDC_CTRL_REV_MASK)

#define QDC_CTRL_SWIP_MASK                       (0x800U)
#define QDC_CTRL_SWIP_SHIFT                      (11U)
/*! SWIP - Software-Triggered Initialization of Position Counters UPOS and LPOS
 *  0b0..No action
 *  0b1..Initialize position counter
 */
#define QDC_CTRL_SWIP(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_SWIP_SHIFT)) & QDC_CTRL_SWIP_MASK)

#define QDC_CTRL_HNE_MASK                        (0x1000U)
#define QDC_CTRL_HNE_SHIFT                       (12U)
/*! HNE - Use Negative Edge of HOME Input
 *  0b0..Use positive-going edge-to-trigger initialization of position counters UPOS and LPOS
 *  0b1..Use negative-going edge-to-trigger initialization of position counters UPOS and LPOS
 */
#define QDC_CTRL_HNE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HNE_SHIFT)) & QDC_CTRL_HNE_MASK)

#define QDC_CTRL_HIP_MASK                        (0x2000U)
#define QDC_CTRL_HIP_SHIFT                       (13U)
/*! HIP - Enable HOME to Initialize Position Counters UPOS and LPOS
 *  0b0..No action
 *  0b1..HOME signal initializes the position counter
 */
#define QDC_CTRL_HIP(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HIP_SHIFT)) & QDC_CTRL_HIP_MASK)

#define QDC_CTRL_HIE_MASK                        (0x4000U)
#define QDC_CTRL_HIE_SHIFT                       (14U)
/*! HIE - HOME Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL_HIE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HIE_SHIFT)) & QDC_CTRL_HIE_MASK)

#define QDC_CTRL_HIRQ_MASK                       (0x8000U)
#define QDC_CTRL_HIRQ_SHIFT                      (15U)
/*! HIRQ - HOME Signal Transition Interrupt Request
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define QDC_CTRL_HIRQ(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HIRQ_SHIFT)) & QDC_CTRL_HIRQ_MASK)
/*! @} */

/*! @name FILT - Input Filter */
/*! @{ */

#define QDC_FILT_FILT_PER_MASK                   (0xFFU)
#define QDC_FILT_FILT_PER_SHIFT                  (0U)
/*! FILT_PER - Input Filter Sample Period */
#define QDC_FILT_FILT_PER(x)                     (((uint16_t)(((uint16_t)(x)) << QDC_FILT_FILT_PER_SHIFT)) & QDC_FILT_FILT_PER_MASK)

#define QDC_FILT_FILT_CNT_MASK                   (0x700U)
#define QDC_FILT_FILT_CNT_SHIFT                  (8U)
/*! FILT_CNT - Input Filter Sample Count */
#define QDC_FILT_FILT_CNT(x)                     (((uint16_t)(((uint16_t)(x)) << QDC_FILT_FILT_CNT_SHIFT)) & QDC_FILT_FILT_CNT_MASK)

#define QDC_FILT_FILT_PRSC_MASK                  (0xE000U)
#define QDC_FILT_FILT_PRSC_SHIFT                 (13U)
/*! FILT_PRSC - Prescaler Divide IPBus Clock to FILT Clock */
#define QDC_FILT_FILT_PRSC(x)                    (((uint16_t)(((uint16_t)(x)) << QDC_FILT_FILT_PRSC_SHIFT)) & QDC_FILT_FILT_PRSC_MASK)
/*! @} */

/*! @name WTR - Watchdog Timeout */
/*! @{ */

#define QDC_WTR_WDOG_MASK                        (0xFFFFU)
#define QDC_WTR_WDOG_SHIFT                       (0U)
/*! WDOG - WDOG */
#define QDC_WTR_WDOG(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_WTR_WDOG_SHIFT)) & QDC_WTR_WDOG_MASK)
/*! @} */

/*! @name POSD - Position Difference Counter */
/*! @{ */

#define QDC_POSD_POSD_MASK                       (0xFFFFU)
#define QDC_POSD_POSD_SHIFT                      (0U)
/*! POSD - POSD */
#define QDC_POSD_POSD(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_POSD_POSD_SHIFT)) & QDC_POSD_POSD_MASK)
/*! @} */

/*! @name POSDH - Position Difference Hold */
/*! @{ */

#define QDC_POSDH_POSDH_MASK                     (0xFFFFU)
#define QDC_POSDH_POSDH_SHIFT                    (0U)
/*! POSDH - POSDH */
#define QDC_POSDH_POSDH(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_POSDH_POSDH_SHIFT)) & QDC_POSDH_POSDH_MASK)
/*! @} */

/*! @name REV - Revolution Counter */
/*! @{ */

#define QDC_REV_REV_MASK                         (0xFFFFU)
#define QDC_REV_REV_SHIFT                        (0U)
/*! REV - REV */
#define QDC_REV_REV(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_REV_REV_SHIFT)) & QDC_REV_REV_MASK)
/*! @} */

/*! @name REVH - Revolution Hold */
/*! @{ */

#define QDC_REVH_REVH_MASK                       (0xFFFFU)
#define QDC_REVH_REVH_SHIFT                      (0U)
/*! REVH - REVH */
#define QDC_REVH_REVH(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_REVH_REVH_SHIFT)) & QDC_REVH_REVH_MASK)
/*! @} */

/*! @name UPOS - Upper Position Counter */
/*! @{ */

#define QDC_UPOS_POS_MASK                        (0xFFFFU)
#define QDC_UPOS_POS_SHIFT                       (0U)
/*! POS - POS */
#define QDC_UPOS_POS(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_UPOS_POS_SHIFT)) & QDC_UPOS_POS_MASK)
/*! @} */

/*! @name LPOS - Lower Position Counter */
/*! @{ */

#define QDC_LPOS_POS_MASK                        (0xFFFFU)
#define QDC_LPOS_POS_SHIFT                       (0U)
/*! POS - POS */
#define QDC_LPOS_POS(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_LPOS_POS_SHIFT)) & QDC_LPOS_POS_MASK)
/*! @} */

/*! @name UPOSH - Upper Position Hold */
/*! @{ */

#define QDC_UPOSH_POSH_MASK                      (0xFFFFU)
#define QDC_UPOSH_POSH_SHIFT                     (0U)
/*! POSH - POSH */
#define QDC_UPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_UPOSH_POSH_SHIFT)) & QDC_UPOSH_POSH_MASK)
/*! @} */

/*! @name LPOSH - Lower Position Hold */
/*! @{ */

#define QDC_LPOSH_POSH_MASK                      (0xFFFFU)
#define QDC_LPOSH_POSH_SHIFT                     (0U)
/*! POSH - POSH */
#define QDC_LPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_LPOSH_POSH_SHIFT)) & QDC_LPOSH_POSH_MASK)
/*! @} */

/*! @name UINIT - Upper Initialization */
/*! @{ */

#define QDC_UINIT_INIT_MASK                      (0xFFFFU)
#define QDC_UINIT_INIT_SHIFT                     (0U)
/*! INIT - INIT */
#define QDC_UINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_UINIT_INIT_SHIFT)) & QDC_UINIT_INIT_MASK)
/*! @} */

/*! @name LINIT - Lower Initialization */
/*! @{ */

#define QDC_LINIT_INIT_MASK                      (0xFFFFU)
#define QDC_LINIT_INIT_SHIFT                     (0U)
/*! INIT - INIT */
#define QDC_LINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_LINIT_INIT_SHIFT)) & QDC_LINIT_INIT_MASK)
/*! @} */

/*! @name IMR - Input Monitor */
/*! @{ */

#define QDC_IMR_HOME_MASK                        (0x1U)
#define QDC_IMR_HOME_SHIFT                       (0U)
/*! HOME - HOME */
#define QDC_IMR_HOME(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_HOME_SHIFT)) & QDC_IMR_HOME_MASK)

#define QDC_IMR_INDEX_MASK                       (0x2U)
#define QDC_IMR_INDEX_SHIFT                      (1U)
/*! INDEX - INDEX */
#define QDC_IMR_INDEX(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_IMR_INDEX_SHIFT)) & QDC_IMR_INDEX_MASK)

#define QDC_IMR_PHB_MASK                         (0x4U)
#define QDC_IMR_PHB_SHIFT                        (2U)
/*! PHB - PHB */
#define QDC_IMR_PHB(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_IMR_PHB_SHIFT)) & QDC_IMR_PHB_MASK)

#define QDC_IMR_PHA_MASK                         (0x8U)
#define QDC_IMR_PHA_SHIFT                        (3U)
/*! PHA - PHA */
#define QDC_IMR_PHA(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_IMR_PHA_SHIFT)) & QDC_IMR_PHA_MASK)

#define QDC_IMR_FHOM_MASK                        (0x10U)
#define QDC_IMR_FHOM_SHIFT                       (4U)
/*! FHOM - FHOM */
#define QDC_IMR_FHOM(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FHOM_SHIFT)) & QDC_IMR_FHOM_MASK)

#define QDC_IMR_FIND_MASK                        (0x20U)
#define QDC_IMR_FIND_SHIFT                       (5U)
/*! FIND - FIND */
#define QDC_IMR_FIND(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FIND_SHIFT)) & QDC_IMR_FIND_MASK)

#define QDC_IMR_FPHB_MASK                        (0x40U)
#define QDC_IMR_FPHB_SHIFT                       (6U)
/*! FPHB - FPHB */
#define QDC_IMR_FPHB(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FPHB_SHIFT)) & QDC_IMR_FPHB_MASK)

#define QDC_IMR_FPHA_MASK                        (0x80U)
#define QDC_IMR_FPHA_SHIFT                       (7U)
/*! FPHA - FPHA */
#define QDC_IMR_FPHA(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FPHA_SHIFT)) & QDC_IMR_FPHA_MASK)
/*! @} */

/*! @name TST - Test */
/*! @{ */

#define QDC_TST_TEST_COUNT_MASK                  (0xFFU)
#define QDC_TST_TEST_COUNT_SHIFT                 (0U)
/*! TEST_COUNT - TEST_COUNT */
#define QDC_TST_TEST_COUNT(x)                    (((uint16_t)(((uint16_t)(x)) << QDC_TST_TEST_COUNT_SHIFT)) & QDC_TST_TEST_COUNT_MASK)

#define QDC_TST_TEST_PERIOD_MASK                 (0x1F00U)
#define QDC_TST_TEST_PERIOD_SHIFT                (8U)
/*! TEST_PERIOD - TEST_PERIOD */
#define QDC_TST_TEST_PERIOD(x)                   (((uint16_t)(((uint16_t)(x)) << QDC_TST_TEST_PERIOD_SHIFT)) & QDC_TST_TEST_PERIOD_MASK)

#define QDC_TST_QDN_MASK                         (0x2000U)
#define QDC_TST_QDN_SHIFT                        (13U)
/*! QDN - Quadrature Decoder Negative Signal
 *  0b0..Positive quadrature decoder signal
 *  0b1..Negative quadrature decoder signal
 */
#define QDC_TST_QDN(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_TST_QDN_SHIFT)) & QDC_TST_QDN_MASK)

#define QDC_TST_TCE_MASK                         (0x4000U)
#define QDC_TST_TCE_SHIFT                        (14U)
/*! TCE - Test Counter Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_TST_TCE(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_TST_TCE_SHIFT)) & QDC_TST_TCE_MASK)

#define QDC_TST_TEN_MASK                         (0x8000U)
#define QDC_TST_TEN_SHIFT                        (15U)
/*! TEN - Test Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_TST_TEN(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_TST_TEN_SHIFT)) & QDC_TST_TEN_MASK)
/*! @} */

/*! @name CTRL2 - Control 2 */
/*! @{ */

#define QDC_CTRL2_UPDHLD_MASK                    (0x1U)
#define QDC_CTRL2_UPDHLD_SHIFT                   (0U)
/*! UPDHLD - Update Hold Registers
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL2_UPDHLD(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_UPDHLD_SHIFT)) & QDC_CTRL2_UPDHLD_MASK)

#define QDC_CTRL2_UPDPOS_MASK                    (0x2U)
#define QDC_CTRL2_UPDPOS_SHIFT                   (1U)
/*! UPDPOS - Update Position Registers
 *  0b0..No action
 *  0b1..Clear
 */
#define QDC_CTRL2_UPDPOS(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_UPDPOS_SHIFT)) & QDC_CTRL2_UPDPOS_MASK)

#define QDC_CTRL2_MOD_MASK                       (0x4U)
#define QDC_CTRL2_MOD_SHIFT                      (2U)
/*! MOD - Enable Modulo Counting
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL2_MOD(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_MOD_SHIFT)) & QDC_CTRL2_MOD_MASK)

#define QDC_CTRL2_DIR_MASK                       (0x8U)
#define QDC_CTRL2_DIR_SHIFT                      (3U)
/*! DIR - Count Direction Flag
 *  0b0..Down direction
 *  0b1..Up direction
 */
#define QDC_CTRL2_DIR(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_DIR_SHIFT)) & QDC_CTRL2_DIR_MASK)

#define QDC_CTRL2_RUIE_MASK                      (0x10U)
#define QDC_CTRL2_RUIE_SHIFT                     (4U)
/*! RUIE - Roll-under Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL2_RUIE(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_RUIE_SHIFT)) & QDC_CTRL2_RUIE_MASK)

#define QDC_CTRL2_RUIRQ_MASK                     (0x20U)
#define QDC_CTRL2_RUIRQ_SHIFT                    (5U)
/*! RUIRQ - Roll-under Interrupt Request
 *  0b0..No roll-under has occurred
 *  0b1..Roll-under has occurred
 */
#define QDC_CTRL2_RUIRQ(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_RUIRQ_SHIFT)) & QDC_CTRL2_RUIRQ_MASK)

#define QDC_CTRL2_ROIE_MASK                      (0x40U)
#define QDC_CTRL2_ROIE_SHIFT                     (6U)
/*! ROIE - Roll-over Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL2_ROIE(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_ROIE_SHIFT)) & QDC_CTRL2_ROIE_MASK)

#define QDC_CTRL2_ROIRQ_MASK                     (0x80U)
#define QDC_CTRL2_ROIRQ_SHIFT                    (7U)
/*! ROIRQ - Roll-over Interrupt Request
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define QDC_CTRL2_ROIRQ(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_ROIRQ_SHIFT)) & QDC_CTRL2_ROIRQ_MASK)

#define QDC_CTRL2_REVMOD_MASK                    (0x100U)
#define QDC_CTRL2_REVMOD_SHIFT                   (8U)
/*! REVMOD - Revolution Counter Modulus Enable
 *  0b0..Use INDEX pulse
 *  0b1..Use modulus counting roll-over or roll-under
 */
#define QDC_CTRL2_REVMOD(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_REVMOD_SHIFT)) & QDC_CTRL2_REVMOD_MASK)

#define QDC_CTRL2_OUTCTL_MASK                    (0x200U)
#define QDC_CTRL2_OUTCTL_SHIFT                   (9U)
/*! OUTCTL - Output Control
 *  0b0..POSMATCH pulses when a match occurs between the position counters (POS) and the corresponding compare value (COMP )
 *  0b1..POSMATCH pulses when the UPOS, LPOS, REV, or POSD registers are read
 */
#define QDC_CTRL2_OUTCTL(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_OUTCTL_SHIFT)) & QDC_CTRL2_OUTCTL_MASK)

#define QDC_CTRL2_SABIE_MASK                     (0x400U)
#define QDC_CTRL2_SABIE_SHIFT                    (10U)
/*! SABIE - Simultaneous PHASEA and PHASEB Change Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define QDC_CTRL2_SABIE(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_SABIE_SHIFT)) & QDC_CTRL2_SABIE_MASK)

#define QDC_CTRL2_SABIRQ_MASK                    (0x800U)
#define QDC_CTRL2_SABIRQ_SHIFT                   (11U)
/*! SABIRQ - Simultaneous PHASEA and PHASEB Change Interrupt Request
 *  0b0..No simultaneous change has occurred
 *  0b1..A simultaneous change has occurred
 */
#define QDC_CTRL2_SABIRQ(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_SABIRQ_SHIFT)) & QDC_CTRL2_SABIRQ_MASK)

#define QDC_CTRL2_INITPOS_MASK                   (0x1000U)
#define QDC_CTRL2_INITPOS_SHIFT                  (12U)
/*! INITPOS - Initialize Position Registers
 *  0b0..Don't initialize position counter
 *  0b1..Initialize position counter
 */
#define QDC_CTRL2_INITPOS(x)                     (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_INITPOS_SHIFT)) & QDC_CTRL2_INITPOS_MASK)
/*! @} */

/*! @name UMOD - Upper Modulus */
/*! @{ */

#define QDC_UMOD_MOD_MASK                        (0xFFFFU)
#define QDC_UMOD_MOD_SHIFT                       (0U)
/*! MOD - MOD */
#define QDC_UMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_UMOD_MOD_SHIFT)) & QDC_UMOD_MOD_MASK)
/*! @} */

/*! @name LMOD - Lower Modulus */
/*! @{ */

#define QDC_LMOD_MOD_MASK                        (0xFFFFU)
#define QDC_LMOD_MOD_SHIFT                       (0U)
/*! MOD - MOD */
#define QDC_LMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_LMOD_MOD_SHIFT)) & QDC_LMOD_MOD_MASK)
/*! @} */

/*! @name UCOMP - Upper Position Compare */
/*! @{ */

#define QDC_UCOMP_COMP_MASK                      (0xFFFFU)
#define QDC_UCOMP_COMP_SHIFT                     (0U)
/*! COMP - COMP */
#define QDC_UCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_UCOMP_COMP_SHIFT)) & QDC_UCOMP_COMP_MASK)
/*! @} */

/*! @name LCOMP - Lower Position Compare */
/*! @{ */

#define QDC_LCOMP_COMP_MASK                      (0xFFFFU)
#define QDC_LCOMP_COMP_SHIFT                     (0U)
/*! COMP - COMP */
#define QDC_LCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_LCOMP_COMP_SHIFT)) & QDC_LCOMP_COMP_MASK)
/*! @} */

/*! @name LASTEDGE - Last Edge Time */
/*! @{ */

#define QDC_LASTEDGE_LASTEDGE_MASK               (0xFFFFU)
#define QDC_LASTEDGE_LASTEDGE_SHIFT              (0U)
/*! LASTEDGE - Last Edge Time Counter */
#define QDC_LASTEDGE_LASTEDGE(x)                 (((uint16_t)(((uint16_t)(x)) << QDC_LASTEDGE_LASTEDGE_SHIFT)) & QDC_LASTEDGE_LASTEDGE_MASK)
/*! @} */

/*! @name LASTEDGEH - Last Edge Time Hold */
/*! @{ */

#define QDC_LASTEDGEH_LASTEDGEH_MASK             (0xFFFFU)
#define QDC_LASTEDGEH_LASTEDGEH_SHIFT            (0U)
/*! LASTEDGEH - Last Edge Time Hold */
#define QDC_LASTEDGEH_LASTEDGEH(x)               (((uint16_t)(((uint16_t)(x)) << QDC_LASTEDGEH_LASTEDGEH_SHIFT)) & QDC_LASTEDGEH_LASTEDGEH_MASK)
/*! @} */

/*! @name POSDPER - Position Difference Period Counter */
/*! @{ */

#define QDC_POSDPER_POSDPER_MASK                 (0xFFFFU)
#define QDC_POSDPER_POSDPER_SHIFT                (0U)
/*! POSDPER - Position difference period */
#define QDC_POSDPER_POSDPER(x)                   (((uint16_t)(((uint16_t)(x)) << QDC_POSDPER_POSDPER_SHIFT)) & QDC_POSDPER_POSDPER_MASK)
/*! @} */

/*! @name POSDPERBFR - Position Difference Period Buffer */
/*! @{ */

#define QDC_POSDPERBFR_POSDPERBFR_MASK           (0xFFFFU)
#define QDC_POSDPERBFR_POSDPERBFR_SHIFT          (0U)
/*! POSDPERBFR - Position difference period buffer */
#define QDC_POSDPERBFR_POSDPERBFR(x)             (((uint16_t)(((uint16_t)(x)) << QDC_POSDPERBFR_POSDPERBFR_SHIFT)) & QDC_POSDPERBFR_POSDPERBFR_MASK)
/*! @} */

/*! @name POSDPERH - Position Difference Period Hold */
/*! @{ */

#define QDC_POSDPERH_POSDPERH_MASK               (0xFFFFU)
#define QDC_POSDPERH_POSDPERH_SHIFT              (0U)
/*! POSDPERH - Position difference period hold */
#define QDC_POSDPERH_POSDPERH(x)                 (((uint16_t)(((uint16_t)(x)) << QDC_POSDPERH_POSDPERH_SHIFT)) & QDC_POSDPERH_POSDPERH_MASK)
/*! @} */

/*! @name CTRL3 - Control 3 */
/*! @{ */

#define QDC_CTRL3_PMEN_MASK                      (0x1U)
#define QDC_CTRL3_PMEN_SHIFT                     (0U)
/*! PMEN - Period Measurement Function Enable
 *  0b0..Not used
 *  0b1..Used
 */
#define QDC_CTRL3_PMEN(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL3_PMEN_SHIFT)) & QDC_CTRL3_PMEN_MASK)

#define QDC_CTRL3_PRSC_MASK                      (0xF0U)
#define QDC_CTRL3_PRSC_SHIFT                     (4U)
/*! PRSC - Prescaler */
#define QDC_CTRL3_PRSC(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL3_PRSC_SHIFT)) & QDC_CTRL3_PRSC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group QDC_Register_Masks */


/*!
 * @}
 */ /* end of group QDC_Peripheral_Access_Layer */


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


#endif  /* PERI_QDC_H_ */

