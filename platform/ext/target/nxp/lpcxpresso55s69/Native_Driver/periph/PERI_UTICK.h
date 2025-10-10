/*
** ###################################################################
**     Processors:          LPC5526JBD100
**                          LPC5526JBD64
**                          LPC5526JEV98
**                          LPC5528JBD100
**                          LPC5528JBD64
**                          LPC5528JEV59
**                          LPC5528JEV98
**                          LPC55S26JBD100
**                          LPC55S26JBD64
**                          LPC55S26JEV98
**                          LPC55S28JBD100
**                          LPC55S28JBD64
**                          LPC55S28JEV59
**                          LPC55S28JEV98
**                          LPC55S66JBD100_cm33_core0
**                          LPC55S66JBD100_cm33_core1
**                          LPC55S66JBD64_cm33_core0
**                          LPC55S66JBD64_cm33_core1
**                          LPC55S66JEV98_cm33_core0
**                          LPC55S66JEV98_cm33_core1
**                          LPC55S69JBD100_cm33_core0
**                          LPC55S69JBD100_cm33_core1
**                          LPC55S69JBD64_cm33_core0
**                          LPC55S69JBD64_cm33_core1
**                          LPC55S69JEV59_cm33_core0
**                          LPC55S69JEV59_cm33_core1
**                          LPC55S69JEV98_cm33_core0
**                          LPC55S69JEV98_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250529
**
**     Abstract:
**         CMSIS Peripheral Access Layer for UTICK
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-08-22)
**         Initial version based on v0.2UM
**     - rev. 1.1 (2019-05-16)
**         Initial A1 version based on v1.3UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_UTICK.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for UTICK
 *
 * CMSIS Peripheral Access Layer for UTICK
 */

#if !defined(PERI_UTICK_H_)
#define PERI_UTICK_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5526JBD100) || defined(CPU_LPC5526JBD64) || defined(CPU_LPC5526JEV98))
#include "LPC5526_COMMON.h"
#elif (defined(CPU_LPC5528JBD100) || defined(CPU_LPC5528JBD64) || defined(CPU_LPC5528JEV59) || defined(CPU_LPC5528JEV98))
#include "LPC5528_COMMON.h"
#elif (defined(CPU_LPC55S26JBD100) || defined(CPU_LPC55S26JBD64) || defined(CPU_LPC55S26JEV98))
#include "LPC55S26_COMMON.h"
#elif (defined(CPU_LPC55S28JBD100) || defined(CPU_LPC55S28JBD64) || defined(CPU_LPC55S28JEV59) || defined(CPU_LPC55S28JEV98))
#include "LPC55S28_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core0) || defined(CPU_LPC55S66JBD64_cm33_core0) || defined(CPU_LPC55S66JEV98_cm33_core0))
#include "LPC55S66_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core1) || defined(CPU_LPC55S66JBD64_cm33_core1) || defined(CPU_LPC55S66JEV98_cm33_core1))
#include "LPC55S66_cm33_core1_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core0) || defined(CPU_LPC55S69JBD64_cm33_core0) || defined(CPU_LPC55S69JEV59_cm33_core0) || defined(CPU_LPC55S69JEV98_cm33_core0))
#include "LPC55S69_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core1) || defined(CPU_LPC55S69JBD64_cm33_core1) || defined(CPU_LPC55S69JEV59_cm33_core1) || defined(CPU_LPC55S69JEV98_cm33_core1))
#include "LPC55S69_cm33_core1_COMMON.h"
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
   -- UTICK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UTICK_Peripheral_Access_Layer UTICK Peripheral Access Layer
 * @{
 */

/** UTICK - Size of Registers Arrays */
#define UTICK_CAP_COUNT                           4u

/** UTICK - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control register., offset: 0x0 */
  __IO uint32_t STAT;                              /**< Status register., offset: 0x4 */
  __IO uint32_t CFG;                               /**< Capture configuration register., offset: 0x8 */
  __O  uint32_t CAPCLR;                            /**< Capture clear register., offset: 0xC */
  __I  uint32_t CAP[UTICK_CAP_COUNT];              /**< Capture register ., array offset: 0x10, array step: 0x4 */
} UTICK_Type;

/* ----------------------------------------------------------------------------
   -- UTICK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UTICK_Register_Masks UTICK Register Masks
 * @{
 */

/*! @name CTRL - Control register. */
/*! @{ */

#define UTICK_CTRL_DELAYVAL_MASK                 (0x7FFFFFFFU)
#define UTICK_CTRL_DELAYVAL_SHIFT                (0U)
/*! DELAYVAL - Tick interval value. The delay will be equal to DELAYVAL + 1 periods of the timer
 *    clock. The minimum usable value is 1, for a delay of 2 timer clocks. A value of 0 stops the timer.
 */
#define UTICK_CTRL_DELAYVAL(x)                   (((uint32_t)(((uint32_t)(x)) << UTICK_CTRL_DELAYVAL_SHIFT)) & UTICK_CTRL_DELAYVAL_MASK)

#define UTICK_CTRL_REPEAT_MASK                   (0x80000000U)
#define UTICK_CTRL_REPEAT_SHIFT                  (31U)
/*! REPEAT - Repeat delay. 0 = One-time delay. 1 = Delay repeats continuously. */
#define UTICK_CTRL_REPEAT(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CTRL_REPEAT_SHIFT)) & UTICK_CTRL_REPEAT_MASK)
/*! @} */

/*! @name STAT - Status register. */
/*! @{ */

#define UTICK_STAT_INTR_MASK                     (0x1U)
#define UTICK_STAT_INTR_SHIFT                    (0U)
/*! INTR - Interrupt flag. 0 = No interrupt is pending. 1 = An interrupt is pending. A write of any
 *    value to this register clears this flag.
 */
#define UTICK_STAT_INTR(x)                       (((uint32_t)(((uint32_t)(x)) << UTICK_STAT_INTR_SHIFT)) & UTICK_STAT_INTR_MASK)

#define UTICK_STAT_ACTIVE_MASK                   (0x2U)
#define UTICK_STAT_ACTIVE_SHIFT                  (1U)
/*! ACTIVE - Active flag. 0 = The Micro-Tick Timer is stopped. 1 = The Micro-Tick Timer is currently active. */
#define UTICK_STAT_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_STAT_ACTIVE_SHIFT)) & UTICK_STAT_ACTIVE_MASK)
/*! @} */

/*! @name CFG - Capture configuration register. */
/*! @{ */

#define UTICK_CFG_CAPEN0_MASK                    (0x1U)
#define UTICK_CFG_CAPEN0_SHIFT                   (0U)
/*! CAPEN0 - Enable Capture 0. 1 = Enabled, 0 = Disabled. */
#define UTICK_CFG_CAPEN0(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN0_SHIFT)) & UTICK_CFG_CAPEN0_MASK)

#define UTICK_CFG_CAPEN1_MASK                    (0x2U)
#define UTICK_CFG_CAPEN1_SHIFT                   (1U)
/*! CAPEN1 - Enable Capture 1. 1 = Enabled, 0 = Disabled. */
#define UTICK_CFG_CAPEN1(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN1_SHIFT)) & UTICK_CFG_CAPEN1_MASK)

#define UTICK_CFG_CAPEN2_MASK                    (0x4U)
#define UTICK_CFG_CAPEN2_SHIFT                   (2U)
/*! CAPEN2 - Enable Capture 2. 1 = Enabled, 0 = Disabled. */
#define UTICK_CFG_CAPEN2(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN2_SHIFT)) & UTICK_CFG_CAPEN2_MASK)

#define UTICK_CFG_CAPEN3_MASK                    (0x8U)
#define UTICK_CFG_CAPEN3_SHIFT                   (3U)
/*! CAPEN3 - Enable Capture 3. 1 = Enabled, 0 = Disabled. */
#define UTICK_CFG_CAPEN3(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN3_SHIFT)) & UTICK_CFG_CAPEN3_MASK)

#define UTICK_CFG_CAPPOL0_MASK                   (0x100U)
#define UTICK_CFG_CAPPOL0_SHIFT                  (8U)
/*! CAPPOL0 - Capture Polarity 0. 0 = Positive edge capture, 1 = Negative edge capture. */
#define UTICK_CFG_CAPPOL0(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL0_SHIFT)) & UTICK_CFG_CAPPOL0_MASK)

#define UTICK_CFG_CAPPOL1_MASK                   (0x200U)
#define UTICK_CFG_CAPPOL1_SHIFT                  (9U)
/*! CAPPOL1 - Capture Polarity 1. 0 = Positive edge capture, 1 = Negative edge capture. */
#define UTICK_CFG_CAPPOL1(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL1_SHIFT)) & UTICK_CFG_CAPPOL1_MASK)

#define UTICK_CFG_CAPPOL2_MASK                   (0x400U)
#define UTICK_CFG_CAPPOL2_SHIFT                  (10U)
/*! CAPPOL2 - Capture Polarity 2. 0 = Positive edge capture, 1 = Negative edge capture. */
#define UTICK_CFG_CAPPOL2(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL2_SHIFT)) & UTICK_CFG_CAPPOL2_MASK)

#define UTICK_CFG_CAPPOL3_MASK                   (0x800U)
#define UTICK_CFG_CAPPOL3_SHIFT                  (11U)
/*! CAPPOL3 - Capture Polarity 3. 0 = Positive edge capture, 1 = Negative edge capture. */
#define UTICK_CFG_CAPPOL3(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL3_SHIFT)) & UTICK_CFG_CAPPOL3_MASK)
/*! @} */

/*! @name CAPCLR - Capture clear register. */
/*! @{ */

#define UTICK_CAPCLR_CAPCLR0_MASK                (0x1U)
#define UTICK_CAPCLR_CAPCLR0_SHIFT               (0U)
/*! CAPCLR0 - Clear capture 0. Writing 1 to this bit clears the CAP0 register value. */
#define UTICK_CAPCLR_CAPCLR0(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR0_SHIFT)) & UTICK_CAPCLR_CAPCLR0_MASK)

#define UTICK_CAPCLR_CAPCLR1_MASK                (0x2U)
#define UTICK_CAPCLR_CAPCLR1_SHIFT               (1U)
/*! CAPCLR1 - Clear capture 1. Writing 1 to this bit clears the CAP1 register value. */
#define UTICK_CAPCLR_CAPCLR1(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR1_SHIFT)) & UTICK_CAPCLR_CAPCLR1_MASK)

#define UTICK_CAPCLR_CAPCLR2_MASK                (0x4U)
#define UTICK_CAPCLR_CAPCLR2_SHIFT               (2U)
/*! CAPCLR2 - Clear capture 2. Writing 1 to this bit clears the CAP2 register value. */
#define UTICK_CAPCLR_CAPCLR2(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR2_SHIFT)) & UTICK_CAPCLR_CAPCLR2_MASK)

#define UTICK_CAPCLR_CAPCLR3_MASK                (0x8U)
#define UTICK_CAPCLR_CAPCLR3_SHIFT               (3U)
/*! CAPCLR3 - Clear capture 3. Writing 1 to this bit clears the CAP3 register value. */
#define UTICK_CAPCLR_CAPCLR3(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR3_SHIFT)) & UTICK_CAPCLR_CAPCLR3_MASK)
/*! @} */

/*! @name CAP - Capture register . */
/*! @{ */

#define UTICK_CAP_CAP_VALUE_MASK                 (0x7FFFFFFFU)
#define UTICK_CAP_CAP_VALUE_SHIFT                (0U)
/*! CAP_VALUE - Capture value for the related capture event (UTICK_CAPn. Note: the value is 1 lower
 *    than the actual value of the Micro-tick Timer at the moment of the capture event.
 */
#define UTICK_CAP_CAP_VALUE(x)                   (((uint32_t)(((uint32_t)(x)) << UTICK_CAP_CAP_VALUE_SHIFT)) & UTICK_CAP_CAP_VALUE_MASK)

#define UTICK_CAP_VALID_MASK                     (0x80000000U)
#define UTICK_CAP_VALID_SHIFT                    (31U)
/*! VALID - Capture Valid. When 1, a value has been captured based on a transition of the related
 *    UTICK_CAPn pin. Cleared by writing to the related bit in the CAPCLR register.
 */
#define UTICK_CAP_VALID(x)                       (((uint32_t)(((uint32_t)(x)) << UTICK_CAP_VALID_SHIFT)) & UTICK_CAP_VALID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UTICK_Register_Masks */


/*!
 * @}
 */ /* end of group UTICK_Peripheral_Access_Layer */


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


#endif  /* PERI_UTICK_H_ */

