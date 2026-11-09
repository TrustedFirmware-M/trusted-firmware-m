/*
** ###################################################################
**     Processors:          KW43B43ZC2MFT
**                          KW43B43ZC3MFT
**                          KW43B43ZC6MFT
**                          KW43B43ZC7MFT
**                          KW43L43Z92MFT
**                          KW43L43Z93MFT
**                          KW43L43Z96MFT
**                          KW43L43Z97MFT
**
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b260316
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GDET
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
 * @file PERI_GDET.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for GDET
 *
 * CMSIS Peripheral Access Layer for GDET
 */

#if !defined(PERI_GDET_H_)
#define PERI_GDET_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW43B43ZC2MFT))
#include "KW43B43ZC2_COMMON.h"
#elif (defined(CPU_KW43B43ZC3MFT))
#include "KW43B43ZC3_COMMON.h"
#elif (defined(CPU_KW43B43ZC6MFT))
#include "KW43B43ZC6_COMMON.h"
#elif (defined(CPU_KW43B43ZC7MFT))
#include "KW43B43ZC7_COMMON.h"
#elif (defined(CPU_KW43L43Z92MFT))
#include "KW43L43Z92_COMMON.h"
#elif (defined(CPU_KW43L43Z93MFT))
#include "KW43L43Z93_COMMON.h"
#elif (defined(CPU_KW43L43Z96MFT))
#include "KW43L43Z96_COMMON.h"
#elif (defined(CPU_KW43L43Z97MFT))
#include "KW43L43Z97_COMMON.h"
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
   -- GDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Peripheral_Access_Layer GDET Peripheral Access Layer
 * @{
 */

/** GDET - Register Layout Typedef */
typedef struct {
  __IO uint32_t GDET_UPDATE_TIMER;                 /**< Update timer control., offset: 0x0 */
       uint8_t RESERVED_0[512];
  __IO uint32_t GDET_RCTRL1;                       /**< GDET control., offset: 0x204 */
  __IO uint32_t GDET_RENABLE1;                     /**< GDET enable., offset: 0x208 */
  __IO uint32_t GDET_RFORCE_ALARM1;                /**< GDET force alarm., offset: 0x20C */
  __I  uint32_t GDET_RSTATUS1;                     /**< GDET status readout., offset: 0x210 */
  __I  uint32_t GDET_RRESULT1;                     /**< GDET result., offset: 0x214 */
       uint8_t RESERVED_1[8];
  __IO uint32_t GDET_RMARGIN1;                     /**< Margin and target definition., offset: 0x220 */
  __IO uint32_t GDET_RREF1;                        /**< Reference limits for mode 0., offset: 0x224 */
  __IO uint32_t GDET_RMARGIN1_MODE1;               /**< Margin and target definition for mode 1., offset: 0x228 */
  __IO uint32_t GDET_RREF1_MODE1;                  /**< Reference limits for mode 1., offset: 0x22C */
  __IO uint32_t GDET_RMARGIN1_MODE2;               /**< Margin and target definition for mode 2., offset: 0x230 */
  __IO uint32_t GDET_RREF1_MODE2;                  /**< Reference limits for mode 2., offset: 0x234 */
       uint8_t RESERVED_2[1488];
  __IO uint32_t GDET_DLY_CTRL;                     /**< GDET delay control., offset: 0x808 */
  __IO uint32_t GDET_CTRL_CLR;                     /**< GDET clear control., offset: 0x80C */
       uint8_t RESERVED_3[2028];
  __I  uint32_t GDET_IP_VERSION;                   /**< IP Version., offset: 0xFFC */
} GDET_Type;

/* ----------------------------------------------------------------------------
   -- GDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Register_Masks GDET Register Masks
 * @{
 */

/*! @name GDET_UPDATE_TIMER - Update timer control. */
/*! @{ */

#define GDET_GDET_UPDATE_TIMER_UPD_RATE_MASK     (0xFU)
#define GDET_GDET_UPDATE_TIMER_UPD_RATE_SHIFT    (0U)
/*! UPD_RATE - Update rate. */
#define GDET_GDET_UPDATE_TIMER_UPD_RATE(x)       (((uint32_t)(((uint32_t)(x)) << GDET_GDET_UPDATE_TIMER_UPD_RATE_SHIFT)) & GDET_GDET_UPDATE_TIMER_UPD_RATE_MASK)

#define GDET_GDET_UPDATE_TIMER_UPD_STOP_MASK     (0x10U)
#define GDET_GDET_UPDATE_TIMER_UPD_STOP_SHIFT    (4U)
/*! UPD_STOP - Update stop.
 *  0b0..Periodic update pulses are generated.
 *  0b1..No periodic update pulses are generated. Individual pulses can be forced through UPD_MAN.
 */
#define GDET_GDET_UPDATE_TIMER_UPD_STOP(x)       (((uint32_t)(((uint32_t)(x)) << GDET_GDET_UPDATE_TIMER_UPD_STOP_SHIFT)) & GDET_GDET_UPDATE_TIMER_UPD_STOP_MASK)

#define GDET_GDET_UPDATE_TIMER_UPD_MAN_MASK      (0x20U)
#define GDET_GDET_UPDATE_TIMER_UPD_MAN_SHIFT     (5U)
/*! UPD_MAN - Manual update pulse. */
#define GDET_GDET_UPDATE_TIMER_UPD_MAN(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_UPDATE_TIMER_UPD_MAN_SHIFT)) & GDET_GDET_UPDATE_TIMER_UPD_MAN_MASK)

#define GDET_GDET_UPDATE_TIMER_RFU_MASK          (0xFFFFFFC0U)
#define GDET_GDET_UPDATE_TIMER_RFU_SHIFT         (6U)
/*! RFU - Reserved. */
#define GDET_GDET_UPDATE_TIMER_RFU(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_UPDATE_TIMER_RFU_SHIFT)) & GDET_GDET_UPDATE_TIMER_RFU_MASK)
/*! @} */

/*! @name GDET_RCTRL1 - GDET control. */
/*! @{ */

#define GDET_GDET_RCTRL1_RCHG_SEL1_MASK          (0x3U)
#define GDET_GDET_RCTRL1_RCHG_SEL1_SHIFT         (0U)
/*! RCHG_SEL1 - Change select.
 *  0b00..Chg = Minimum result value of last period
 *  0b01..Chg = Maximum result value of last period
 *  0b10..Chg = Caculated average of min and max result values of last period
 *  0b11..Chg = Reference is fixed to GDET_CTRL1.TARGET1
 */
#define GDET_GDET_RCTRL1_RCHG_SEL1(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RCHG_SEL1_SHIFT)) & GDET_GDET_RCTRL1_RCHG_SEL1_MASK)

#define GDET_GDET_RCTRL1_RWEIGHT1_MASK           (0xCU)
#define GDET_GDET_RCTRL1_RWEIGHT1_SHIFT          (2U)
/*! RWEIGHT1 - Weight.
 *  0b00..Ref.i = Chg
 *  0b01..Ref.i = 1/2 * Ref.i-1 + 1/2 * Chg
 *  0b10..Ref.i = 3/4 * Ref.i-1 + 1/4 * Chg
 *  0b11..Ref.i = 7/8 * Ref.i-1 + 1/8 * Chg
 */
#define GDET_GDET_RCTRL1_RWEIGHT1(x)             (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RWEIGHT1_SHIFT)) & GDET_GDET_RCTRL1_RWEIGHT1_MASK)

#define GDET_GDET_RCTRL1_RIGN_ERR1_MASK          (0x10U)
#define GDET_GDET_RCTRL1_RIGN_ERR1_SHIFT         (4U)
/*! RIGN_ERR1 - Ignore error.
 *  0b0..Alarms force min/max to default.
 *  0b1..Alarms do not force min/max.
 */
#define GDET_GDET_RCTRL1_RIGN_ERR1(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RIGN_ERR1_SHIFT)) & GDET_GDET_RCTRL1_RIGN_ERR1_MASK)

#define GDET_GDET_RCTRL1_RFU_MASK                (0x60U)
#define GDET_GDET_RCTRL1_RFU_SHIFT               (5U)
/*! RFU - Reserved. */
#define GDET_GDET_RCTRL1_RFU(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RFU_SHIFT)) & GDET_GDET_RCTRL1_RFU_MASK)

#define GDET_GDET_RCTRL1_RMEAS_TIME1_MASK        (0x180U)
#define GDET_GDET_RCTRL1_RMEAS_TIME1_SHIFT       (7U)
/*! RMEAS_TIME1 - Measurement time. */
#define GDET_GDET_RCTRL1_RMEAS_TIME1(x)          (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RMEAS_TIME1_SHIFT)) & GDET_GDET_RCTRL1_RMEAS_TIME1_MASK)

#define GDET_GDET_RCTRL1_RFU3_MASK               (0x200U)
#define GDET_GDET_RCTRL1_RFU3_SHIFT              (9U)
/*! RFU3 - Reserved. */
#define GDET_GDET_RCTRL1_RFU3(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RFU3_SHIFT)) & GDET_GDET_RCTRL1_RFU3_MASK)

#define GDET_GDET_RCTRL1_RFU1_MASK               (0xFC00U)
#define GDET_GDET_RCTRL1_RFU1_SHIFT              (10U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RCTRL1_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RFU1_SHIFT)) & GDET_GDET_RCTRL1_RFU1_MASK)

#define GDET_GDET_RCTRL1_RFU4_MASK               (0xFF0000U)
#define GDET_GDET_RCTRL1_RFU4_SHIFT              (16U)
/*! RFU4 - Reserved. */
#define GDET_GDET_RCTRL1_RFU4(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RFU4_SHIFT)) & GDET_GDET_RCTRL1_RFU4_MASK)

#define GDET_GDET_RCTRL1_RFU2_MASK               (0xFF000000U)
#define GDET_GDET_RCTRL1_RFU2_SHIFT              (24U)
/*! RFU2 - Reserved. */
#define GDET_GDET_RCTRL1_RFU2(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RCTRL1_RFU2_SHIFT)) & GDET_GDET_RCTRL1_RFU2_MASK)
/*! @} */

/*! @name GDET_RENABLE1 - GDET enable. */
/*! @{ */

#define GDET_GDET_RENABLE1_REN1_MASK             (0x1U)
#define GDET_GDET_RENABLE1_REN1_SHIFT            (0U)
/*! REN1 - GDET enable.
 *  0b0..Reference clock is not requested.
 *  0b1..Reference clock is requested. This enables GDET.
 */
#define GDET_GDET_RENABLE1_REN1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RENABLE1_REN1_SHIFT)) & GDET_GDET_RENABLE1_REN1_MASK)

#define GDET_GDET_RENABLE1_RFU_MASK              (0xFFFFFFFEU)
#define GDET_GDET_RENABLE1_RFU_SHIFT             (1U)
/*! RFU - Reserved. */
#define GDET_GDET_RENABLE1_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RENABLE1_RFU_SHIFT)) & GDET_GDET_RENABLE1_RFU_MASK)
/*! @} */

/*! @name GDET_RFORCE_ALARM1 - GDET force alarm. */
/*! @{ */

#define GDET_GDET_RFORCE_ALARM1_POS_ALARM1_MASK  (0x1U)
#define GDET_GDET_RFORCE_ALARM1_POS_ALARM1_SHIFT (0U)
/*! POS_ALARM1 - Positve alarm.
 *  0b0..No positive alarm pulse.
 *  0b1..Forces a positive alarm pulse.
 */
#define GDET_GDET_RFORCE_ALARM1_POS_ALARM1(x)    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RFORCE_ALARM1_POS_ALARM1_SHIFT)) & GDET_GDET_RFORCE_ALARM1_POS_ALARM1_MASK)

#define GDET_GDET_RFORCE_ALARM1_NEG_ALARM1_MASK  (0x2U)
#define GDET_GDET_RFORCE_ALARM1_NEG_ALARM1_SHIFT (1U)
/*! NEG_ALARM1 - Negative alarm.
 *  0b0..No negative alarm pulse.
 *  0b1..Forces a negative alarm pulse.
 */
#define GDET_GDET_RFORCE_ALARM1_NEG_ALARM1(x)    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RFORCE_ALARM1_NEG_ALARM1_SHIFT)) & GDET_GDET_RFORCE_ALARM1_NEG_ALARM1_MASK)

#define GDET_GDET_RFORCE_ALARM1_RFU_MASK         (0xFFFFFFFCU)
#define GDET_GDET_RFORCE_ALARM1_RFU_SHIFT        (2U)
/*! RFU - Reserved. */
#define GDET_GDET_RFORCE_ALARM1_RFU(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RFORCE_ALARM1_RFU_SHIFT)) & GDET_GDET_RFORCE_ALARM1_RFU_MASK)
/*! @} */

/*! @name GDET_RSTATUS1 - GDET status readout. */
/*! @{ */

#define GDET_GDET_RSTATUS1_MIN1_MASK             (0x3FFU)
#define GDET_GDET_RSTATUS1_MIN1_SHIFT            (0U)
/*! MIN1 - Minimum result value. */
#define GDET_GDET_RSTATUS1_MIN1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RSTATUS1_MIN1_SHIFT)) & GDET_GDET_RSTATUS1_MIN1_MASK)

#define GDET_GDET_RSTATUS1_MAX1_MASK             (0xFFC00U)
#define GDET_GDET_RSTATUS1_MAX1_SHIFT            (10U)
/*! MAX1 - Maximum result value. */
#define GDET_GDET_RSTATUS1_MAX1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RSTATUS1_MAX1_SHIFT)) & GDET_GDET_RSTATUS1_MAX1_MASK)

#define GDET_GDET_RSTATUS1_REF1_MASK             (0x3FF00000U)
#define GDET_GDET_RSTATUS1_REF1_SHIFT            (20U)
/*! REF1 - Reference value. */
#define GDET_GDET_RSTATUS1_REF1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RSTATUS1_REF1_SHIFT)) & GDET_GDET_RSTATUS1_REF1_MASK)

#define GDET_GDET_RSTATUS1_RFU1_MASK             (0xC0000000U)
#define GDET_GDET_RSTATUS1_RFU1_SHIFT            (30U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RSTATUS1_RFU1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RSTATUS1_RFU1_SHIFT)) & GDET_GDET_RSTATUS1_RFU1_MASK)
/*! @} */

/*! @name GDET_RRESULT1 - GDET result. */
/*! @{ */

#define GDET_GDET_RRESULT1_RESULT1_MASK          (0x3FFU)
#define GDET_GDET_RRESULT1_RESULT1_SHIFT         (0U)
/*! RESULT1 - Result value. */
#define GDET_GDET_RRESULT1_RESULT1(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RRESULT1_RESULT1_SHIFT)) & GDET_GDET_RRESULT1_RESULT1_MASK)

#define GDET_GDET_RRESULT1_RFU_MASK              (0xFFFFC00U)
#define GDET_GDET_RRESULT1_RFU_SHIFT             (10U)
/*! RFU - Reserved. */
#define GDET_GDET_RRESULT1_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RRESULT1_RFU_SHIFT)) & GDET_GDET_RRESULT1_RFU_MASK)

#define GDET_GDET_RRESULT1_NEG_LAT1_MASK         (0x10000000U)
#define GDET_GDET_RRESULT1_NEG_LAT1_SHIFT        (28U)
/*! NEG_LAT1 - Latched negative alarm. */
#define GDET_GDET_RRESULT1_NEG_LAT1(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RRESULT1_NEG_LAT1_SHIFT)) & GDET_GDET_RRESULT1_NEG_LAT1_MASK)

#define GDET_GDET_RRESULT1_POS_LAT1_MASK         (0x20000000U)
#define GDET_GDET_RRESULT1_POS_LAT1_SHIFT        (29U)
/*! POS_LAT1 - Latched positive alarm. */
#define GDET_GDET_RRESULT1_POS_LAT1(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RRESULT1_POS_LAT1_SHIFT)) & GDET_GDET_RRESULT1_POS_LAT1_MASK)

#define GDET_GDET_RRESULT1_ERR_NEG1_MASK         (0x40000000U)
#define GDET_GDET_RRESULT1_ERR_NEG1_SHIFT        (30U)
/*! ERR_NEG1 - Negative alarm. */
#define GDET_GDET_RRESULT1_ERR_NEG1(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RRESULT1_ERR_NEG1_SHIFT)) & GDET_GDET_RRESULT1_ERR_NEG1_MASK)

#define GDET_GDET_RRESULT1_ERR_POS1_MASK         (0x80000000U)
#define GDET_GDET_RRESULT1_ERR_POS1_SHIFT        (31U)
/*! ERR_POS1 - Positive alarm. */
#define GDET_GDET_RRESULT1_ERR_POS1(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RRESULT1_ERR_POS1_SHIFT)) & GDET_GDET_RRESULT1_ERR_POS1_MASK)
/*! @} */

/*! @name GDET_RMARGIN1 - Margin and target definition. */
/*! @{ */

#define GDET_GDET_RMARGIN1_MNEG1_MASK            (0x3FFU)
#define GDET_GDET_RMARGIN1_MNEG1_SHIFT           (0U)
/*! MNEG1 - Negative margin. */
#define GDET_GDET_RMARGIN1_MNEG1(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MNEG1_SHIFT)) & GDET_GDET_RMARGIN1_MNEG1_MASK)

#define GDET_GDET_RMARGIN1_MPOS1_MASK            (0xFFC00U)
#define GDET_GDET_RMARGIN1_MPOS1_SHIFT           (10U)
/*! MPOS1 - Positive margin. */
#define GDET_GDET_RMARGIN1_MPOS1(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MPOS1_SHIFT)) & GDET_GDET_RMARGIN1_MPOS1_MASK)

#define GDET_GDET_RMARGIN1_TGT1_MASK             (0x3FF00000U)
#define GDET_GDET_RMARGIN1_TGT1_SHIFT            (20U)
/*! TGT1 - Target reference value. */
#define GDET_GDET_RMARGIN1_TGT1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_TGT1_SHIFT)) & GDET_GDET_RMARGIN1_TGT1_MASK)

#define GDET_GDET_RMARGIN1_RFU1_MASK             (0xC0000000U)
#define GDET_GDET_RMARGIN1_RFU1_SHIFT            (30U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RMARGIN1_RFU1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_RFU1_SHIFT)) & GDET_GDET_RMARGIN1_RFU1_MASK)
/*! @} */

/*! @name GDET_RREF1 - Reference limits for mode 0. */
/*! @{ */

#define GDET_GDET_RREF1_MIN_REF1_MASK            (0x3FFU)
#define GDET_GDET_RREF1_MIN_REF1_SHIFT           (0U)
/*! MIN_REF1 - Smallest allowed reference value. */
#define GDET_GDET_RREF1_MIN_REF1(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MIN_REF1_SHIFT)) & GDET_GDET_RREF1_MIN_REF1_MASK)

#define GDET_GDET_RREF1_MAX_REF1_MASK            (0xFFC00U)
#define GDET_GDET_RREF1_MAX_REF1_SHIFT           (10U)
/*! MAX_REF1 - Highest allowed reference value. */
#define GDET_GDET_RREF1_MAX_REF1(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MAX_REF1_SHIFT)) & GDET_GDET_RREF1_MAX_REF1_MASK)

#define GDET_GDET_RREF1_RFU1_MASK                (0xFFF00000U)
#define GDET_GDET_RREF1_RFU1_SHIFT               (20U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RREF1_RFU1(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_RFU1_SHIFT)) & GDET_GDET_RREF1_RFU1_MASK)
/*! @} */

/*! @name GDET_RMARGIN1_MODE1 - Margin and target definition for mode 1. */
/*! @{ */

#define GDET_GDET_RMARGIN1_MODE1_MNEG1_MASK      (0x3FFU)
#define GDET_GDET_RMARGIN1_MODE1_MNEG1_SHIFT     (0U)
/*! MNEG1 - Negative margin. */
#define GDET_GDET_RMARGIN1_MODE1_MNEG1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE1_MNEG1_SHIFT)) & GDET_GDET_RMARGIN1_MODE1_MNEG1_MASK)

#define GDET_GDET_RMARGIN1_MODE1_MPOS1_MASK      (0xFFC00U)
#define GDET_GDET_RMARGIN1_MODE1_MPOS1_SHIFT     (10U)
/*! MPOS1 - Negative margin. */
#define GDET_GDET_RMARGIN1_MODE1_MPOS1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE1_MPOS1_SHIFT)) & GDET_GDET_RMARGIN1_MODE1_MPOS1_MASK)

#define GDET_GDET_RMARGIN1_MODE1_TGT1_MASK       (0x3FF00000U)
#define GDET_GDET_RMARGIN1_MODE1_TGT1_SHIFT      (20U)
/*! TGT1 - Target reference value. */
#define GDET_GDET_RMARGIN1_MODE1_TGT1(x)         (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE1_TGT1_SHIFT)) & GDET_GDET_RMARGIN1_MODE1_TGT1_MASK)

#define GDET_GDET_RMARGIN1_MODE1_RFU1_MASK       (0xC0000000U)
#define GDET_GDET_RMARGIN1_MODE1_RFU1_SHIFT      (30U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RMARGIN1_MODE1_RFU1(x)         (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE1_RFU1_SHIFT)) & GDET_GDET_RMARGIN1_MODE1_RFU1_MASK)
/*! @} */

/*! @name GDET_RREF1_MODE1 - Reference limits for mode 1. */
/*! @{ */

#define GDET_GDET_RREF1_MODE1_MIN_REF1_MASK      (0x3FFU)
#define GDET_GDET_RREF1_MODE1_MIN_REF1_SHIFT     (0U)
/*! MIN_REF1 - Smallest allowed reference value. */
#define GDET_GDET_RREF1_MODE1_MIN_REF1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MODE1_MIN_REF1_SHIFT)) & GDET_GDET_RREF1_MODE1_MIN_REF1_MASK)

#define GDET_GDET_RREF1_MODE1_MAX_REF1_MASK      (0xFFC00U)
#define GDET_GDET_RREF1_MODE1_MAX_REF1_SHIFT     (10U)
/*! MAX_REF1 - Highest allowed reference value. */
#define GDET_GDET_RREF1_MODE1_MAX_REF1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MODE1_MAX_REF1_SHIFT)) & GDET_GDET_RREF1_MODE1_MAX_REF1_MASK)

#define GDET_GDET_RREF1_MODE1_RFU1_MASK          (0xFFF00000U)
#define GDET_GDET_RREF1_MODE1_RFU1_SHIFT         (20U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RREF1_MODE1_RFU1(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MODE1_RFU1_SHIFT)) & GDET_GDET_RREF1_MODE1_RFU1_MASK)
/*! @} */

/*! @name GDET_RMARGIN1_MODE2 - Margin and target definition for mode 2. */
/*! @{ */

#define GDET_GDET_RMARGIN1_MODE2_MNEG1_MASK      (0x3FFU)
#define GDET_GDET_RMARGIN1_MODE2_MNEG1_SHIFT     (0U)
/*! MNEG1 - Negative margin. */
#define GDET_GDET_RMARGIN1_MODE2_MNEG1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE2_MNEG1_SHIFT)) & GDET_GDET_RMARGIN1_MODE2_MNEG1_MASK)

#define GDET_GDET_RMARGIN1_MODE2_MPOS1_MASK      (0xFFC00U)
#define GDET_GDET_RMARGIN1_MODE2_MPOS1_SHIFT     (10U)
/*! MPOS1 - Negative margin. */
#define GDET_GDET_RMARGIN1_MODE2_MPOS1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE2_MPOS1_SHIFT)) & GDET_GDET_RMARGIN1_MODE2_MPOS1_MASK)

#define GDET_GDET_RMARGIN1_MODE2_TGT1_MASK       (0x3FF00000U)
#define GDET_GDET_RMARGIN1_MODE2_TGT1_SHIFT      (20U)
/*! TGT1 - Target reference value. */
#define GDET_GDET_RMARGIN1_MODE2_TGT1(x)         (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE2_TGT1_SHIFT)) & GDET_GDET_RMARGIN1_MODE2_TGT1_MASK)

#define GDET_GDET_RMARGIN1_MODE2_RFU1_MASK       (0xC0000000U)
#define GDET_GDET_RMARGIN1_MODE2_RFU1_SHIFT      (30U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RMARGIN1_MODE2_RFU1(x)         (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RMARGIN1_MODE2_RFU1_SHIFT)) & GDET_GDET_RMARGIN1_MODE2_RFU1_MASK)
/*! @} */

/*! @name GDET_RREF1_MODE2 - Reference limits for mode 2. */
/*! @{ */

#define GDET_GDET_RREF1_MODE2_MIN_REF1_MASK      (0x3FFU)
#define GDET_GDET_RREF1_MODE2_MIN_REF1_SHIFT     (0U)
/*! MIN_REF1 - Smallest allowed reference value. */
#define GDET_GDET_RREF1_MODE2_MIN_REF1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MODE2_MIN_REF1_SHIFT)) & GDET_GDET_RREF1_MODE2_MIN_REF1_MASK)

#define GDET_GDET_RREF1_MODE2_MAX_REF1_MASK      (0xFFC00U)
#define GDET_GDET_RREF1_MODE2_MAX_REF1_SHIFT     (10U)
/*! MAX_REF1 - Highest allowed reference value. */
#define GDET_GDET_RREF1_MODE2_MAX_REF1(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MODE2_MAX_REF1_SHIFT)) & GDET_GDET_RREF1_MODE2_MAX_REF1_MASK)

#define GDET_GDET_RREF1_MODE2_RFU1_MASK          (0xFFF00000U)
#define GDET_GDET_RREF1_MODE2_RFU1_SHIFT         (20U)
/*! RFU1 - Reserved. */
#define GDET_GDET_RREF1_MODE2_RFU1(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RREF1_MODE2_RFU1_SHIFT)) & GDET_GDET_RREF1_MODE2_RFU1_MASK)
/*! @} */

/*! @name GDET_DLY_CTRL - GDET delay control. */
/*! @{ */

#define GDET_GDET_DLY_CTRL_VOL_SEL_MASK          (0x3U)
#define GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT         (0U)
/*! VOL_SEL - (Voltage) mode selection.
 *  0b00..Drive mode 0.
 *  0b01..Drive mode 1.
 *  0b10..Drive mode 2.
 *  0b11..Drive mode 3.
 */
#define GDET_GDET_DLY_CTRL_VOL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT)) & GDET_GDET_DLY_CTRL_VOL_SEL_MASK)

#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK      (0x4U)
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT     (2U)
/*! SW_VOL_CTRL - Software voltage mode selection.
 *  0b0..HW control through volt_sel input pin.
 *  0b1..SW SFR control through GDET_DLY_CTRL.VOL_SEL.
 */
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT)) & GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK)

#define GDET_GDET_DLY_CTRL_RFU_MASK              (0xFFFFFFF8U)
#define GDET_GDET_DLY_CTRL_RFU_SHIFT             (3U)
/*! RFU - Reserved. */
#define GDET_GDET_DLY_CTRL_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_RFU_SHIFT)) & GDET_GDET_DLY_CTRL_RFU_MASK)
/*! @} */

/*! @name GDET_CTRL_CLR - GDET clear control. */
/*! @{ */

#define GDET_GDET_CTRL_CLR_SFT_RST_MASK          (0x1U)
#define GDET_GDET_CTRL_CLR_SFT_RST_SHIFT         (0U)
/*! SFT_RST - Soft reset. */
#define GDET_GDET_CTRL_CLR_SFT_RST(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CTRL_CLR_SFT_RST_SHIFT)) & GDET_GDET_CTRL_CLR_SFT_RST_MASK)

#define GDET_GDET_CTRL_CLR_RFU_MASK              (0xFFFFFFFEU)
#define GDET_GDET_CTRL_CLR_RFU_SHIFT             (1U)
/*! RFU - Reserved. */
#define GDET_GDET_CTRL_CLR_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CTRL_CLR_RFU_SHIFT)) & GDET_GDET_CTRL_CLR_RFU_MASK)
/*! @} */

/*! @name GDET_IP_VERSION - IP Version. */
/*! @{ */

#define GDET_GDET_IP_VERSION_Z_MASK              (0xFU)
#define GDET_GDET_IP_VERSION_Z_SHIFT             (0U)
/*! Z - Extended revision number. */
#define GDET_GDET_IP_VERSION_Z(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_IP_VERSION_Z_SHIFT)) & GDET_GDET_IP_VERSION_Z_MASK)

#define GDET_GDET_IP_VERSION_Y2_MASK             (0xF0U)
#define GDET_GDET_IP_VERSION_Y2_SHIFT            (4U)
/*! Y2 - Minor revision number 2. */
#define GDET_GDET_IP_VERSION_Y2(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_IP_VERSION_Y2_SHIFT)) & GDET_GDET_IP_VERSION_Y2_MASK)

#define GDET_GDET_IP_VERSION_Y1_MASK             (0xF00U)
#define GDET_GDET_IP_VERSION_Y1_SHIFT            (8U)
/*! Y1 - Minor revision number 1. */
#define GDET_GDET_IP_VERSION_Y1(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_IP_VERSION_Y1_SHIFT)) & GDET_GDET_IP_VERSION_Y1_MASK)

#define GDET_GDET_IP_VERSION_X_MASK              (0xF000U)
#define GDET_GDET_IP_VERSION_X_SHIFT             (12U)
/*! X - Major revision number. */
#define GDET_GDET_IP_VERSION_X(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_IP_VERSION_X_SHIFT)) & GDET_GDET_IP_VERSION_X_MASK)

#define GDET_GDET_IP_VERSION_MILESTONE_MASK      (0x30000U)
#define GDET_GDET_IP_VERSION_MILESTONE_SHIFT     (16U)
/*! MILESTONE - Release milestone.
 *  0b00..IP Pre-release.
 *  0b01..IP Bronze-release.
 *  0b10..IP Silver-release.
 *  0b11..IP Gold-release.
 */
#define GDET_GDET_IP_VERSION_MILESTONE(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_IP_VERSION_MILESTONE_SHIFT)) & GDET_GDET_IP_VERSION_MILESTONE_MASK)

#define GDET_GDET_IP_VERSION_RFU_MASK            (0xFFFC0000U)
#define GDET_GDET_IP_VERSION_RFU_SHIFT           (18U)
/*! RFU - Reserved. */
#define GDET_GDET_IP_VERSION_RFU(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_IP_VERSION_RFU_SHIFT)) & GDET_GDET_IP_VERSION_RFU_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GDET_Register_Masks */


/*!
 * @}
 */ /* end of group GDET_Peripheral_Access_Layer */


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


#endif  /* PERI_GDET_H_ */

