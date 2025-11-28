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
**         CMSIS Peripheral Access Layer for LPIT
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
 * @file PERI_LPIT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPIT
 *
 * CMSIS Peripheral Access Layer for LPIT
 */

#if !defined(PERI_LPIT_H_)
#define PERI_LPIT_H_                             /**< Symbol preventing repeated inclusion */

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
   -- LPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Peripheral_Access_Layer LPIT Peripheral Access Layer
 * @{
 */

/** LPIT - Size of Registers Arrays */
#define LPIT_CHANNEL_COUNT                        4u

/** LPIT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t MCR;                               /**< Module Control, offset: 0x8 */
  __IO uint32_t MSR;                               /**< Module Status, offset: 0xC */
  __IO uint32_t MIER;                              /**< Module Interrupt Enable, offset: 0x10 */
  __IO uint32_t SETTEN;                            /**< Set Timer Enable, offset: 0x14 */
  __IO uint32_t CLRTEN;                            /**< Clear Timer Enable, offset: 0x18 */
       uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32_t TVAL;                              /**< Timer Value, array offset: 0x20, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control, array offset: 0x28, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } CHANNEL[LPIT_CHANNEL_COUNT];
} LPIT_Type;

/* ----------------------------------------------------------------------------
   -- LPIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Register_Masks LPIT Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define LPIT_VERID_FEATURE_MASK                  (0xFFFFU)
#define LPIT_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Number */
#define LPIT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << LPIT_VERID_FEATURE_SHIFT)) & LPIT_VERID_FEATURE_MASK)

#define LPIT_VERID_MINOR_MASK                    (0xFF0000U)
#define LPIT_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define LPIT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << LPIT_VERID_MINOR_SHIFT)) & LPIT_VERID_MINOR_MASK)

#define LPIT_VERID_MAJOR_MASK                    (0xFF000000U)
#define LPIT_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define LPIT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << LPIT_VERID_MAJOR_SHIFT)) & LPIT_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPIT_PARAM_CHANNEL_MASK                  (0xFFU)
#define LPIT_PARAM_CHANNEL_SHIFT                 (0U)
/*! CHANNEL - Number of Timer Channels */
#define LPIT_PARAM_CHANNEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPIT_PARAM_CHANNEL_SHIFT)) & LPIT_PARAM_CHANNEL_MASK)

#define LPIT_PARAM_EXT_TRIG_MASK                 (0xFF00U)
#define LPIT_PARAM_EXT_TRIG_SHIFT                (8U)
/*! EXT_TRIG - Number of External Trigger Inputs */
#define LPIT_PARAM_EXT_TRIG(x)                   (((uint32_t)(((uint32_t)(x)) << LPIT_PARAM_EXT_TRIG_SHIFT)) & LPIT_PARAM_EXT_TRIG_MASK)
/*! @} */

/*! @name MCR - Module Control */
/*! @{ */

#define LPIT_MCR_M_CEN_MASK                      (0x1U)
#define LPIT_MCR_M_CEN_SHIFT                     (0U)
/*! M_CEN - Module Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPIT_MCR_M_CEN(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_M_CEN_SHIFT)) & LPIT_MCR_M_CEN_MASK)

#define LPIT_MCR_SW_RST_MASK                     (0x2U)
#define LPIT_MCR_SW_RST_SHIFT                    (1U)
/*! SW_RST - Software Reset
 *  0b0..Does not reset
 *  0b1..Resets
 */
#define LPIT_MCR_SW_RST(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_SW_RST_SHIFT)) & LPIT_MCR_SW_RST_MASK)

#define LPIT_MCR_DOZE_EN_MASK                    (0x4U)
#define LPIT_MCR_DOZE_EN_SHIFT                   (2U)
/*! DOZE_EN - DOZE Mode Enable
 *  0b0..Stops timer channels
 *  0b1..Allows timer channels to continue running
 */
#define LPIT_MCR_DOZE_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_DOZE_EN_SHIFT)) & LPIT_MCR_DOZE_EN_MASK)

#define LPIT_MCR_DBG_EN_MASK                     (0x8U)
#define LPIT_MCR_DBG_EN_SHIFT                    (3U)
/*! DBG_EN - Debug Mode Enable
 *  0b0..Stops timer channels
 *  0b1..Allows timer channels to continue running
 */
#define LPIT_MCR_DBG_EN(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_DBG_EN_SHIFT)) & LPIT_MCR_DBG_EN_MASK)
/*! @} */

/*! @name MSR - Module Status */
/*! @{ */

#define LPIT_MSR_TIF0_MASK                       (0x1U)
#define LPIT_MSR_TIF0_SHIFT                      (0U)
/*! TIF0 - Channel 0 Timer Interrupt Flag
 *  0b0..No effect
 *  0b0..Not timed out
 *  0b1..Clear the flag
 *  0b1..Timed out
 */
#define LPIT_MSR_TIF0(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF0_SHIFT)) & LPIT_MSR_TIF0_MASK)

#define LPIT_MSR_TIF1_MASK                       (0x2U)
#define LPIT_MSR_TIF1_SHIFT                      (1U)
/*! TIF1 - Channel 1 Timer Interrupt Flag
 *  0b0..No effect
 *  0b0..Not timed out
 *  0b1..Clear the flag
 *  0b1..Timed out
 */
#define LPIT_MSR_TIF1(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF1_SHIFT)) & LPIT_MSR_TIF1_MASK)

#define LPIT_MSR_TIF2_MASK                       (0x4U)
#define LPIT_MSR_TIF2_SHIFT                      (2U)
/*! TIF2 - Channel 2 Timer Interrupt Flag
 *  0b0..No effect
 *  0b0..Not timed out
 *  0b1..Clear the flag
 *  0b1..Timed out
 */
#define LPIT_MSR_TIF2(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF2_SHIFT)) & LPIT_MSR_TIF2_MASK)

#define LPIT_MSR_TIF3_MASK                       (0x8U)
#define LPIT_MSR_TIF3_SHIFT                      (3U)
/*! TIF3 - Channel 3 Timer Interrupt Flag
 *  0b0..No effect
 *  0b0..Not timed out
 *  0b1..Clear the flag
 *  0b1..Timed out
 */
#define LPIT_MSR_TIF3(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF3_SHIFT)) & LPIT_MSR_TIF3_MASK)
/*! @} */

/*! @name MIER - Module Interrupt Enable */
/*! @{ */

#define LPIT_MIER_TIE0_MASK                      (0x1U)
#define LPIT_MIER_TIE0_SHIFT                     (0U)
/*! TIE0 - Channel 0 Timer Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPIT_MIER_TIE0(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE0_SHIFT)) & LPIT_MIER_TIE0_MASK)

#define LPIT_MIER_TIE1_MASK                      (0x2U)
#define LPIT_MIER_TIE1_SHIFT                     (1U)
/*! TIE1 - Channel 1 Timer Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPIT_MIER_TIE1(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE1_SHIFT)) & LPIT_MIER_TIE1_MASK)

#define LPIT_MIER_TIE2_MASK                      (0x4U)
#define LPIT_MIER_TIE2_SHIFT                     (2U)
/*! TIE2 - Channel 2 Timer Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPIT_MIER_TIE2(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE2_SHIFT)) & LPIT_MIER_TIE2_MASK)

#define LPIT_MIER_TIE3_MASK                      (0x8U)
#define LPIT_MIER_TIE3_SHIFT                     (3U)
/*! TIE3 - Channel 3 Timer Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPIT_MIER_TIE3(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE3_SHIFT)) & LPIT_MIER_TIE3_MASK)
/*! @} */

/*! @name SETTEN - Set Timer Enable */
/*! @{ */

#define LPIT_SETTEN_SET_T_EN_0_MASK              (0x1U)
#define LPIT_SETTEN_SET_T_EN_0_SHIFT             (0U)
/*! SET_T_EN_0 - Set Timer 0 Enable
 *  0b0..No effect
 *  0b1..Enables timer channel 0
 */
#define LPIT_SETTEN_SET_T_EN_0(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_0_SHIFT)) & LPIT_SETTEN_SET_T_EN_0_MASK)

#define LPIT_SETTEN_SET_T_EN_1_MASK              (0x2U)
#define LPIT_SETTEN_SET_T_EN_1_SHIFT             (1U)
/*! SET_T_EN_1 - Set Timer 1 Enable
 *  0b0..No Effect
 *  0b1..Enables timer channel 1
 */
#define LPIT_SETTEN_SET_T_EN_1(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_1_SHIFT)) & LPIT_SETTEN_SET_T_EN_1_MASK)

#define LPIT_SETTEN_SET_T_EN_2_MASK              (0x4U)
#define LPIT_SETTEN_SET_T_EN_2_SHIFT             (2U)
/*! SET_T_EN_2 - Set Timer 2 Enable
 *  0b0..No Effect
 *  0b1..Enables timer channel 2
 */
#define LPIT_SETTEN_SET_T_EN_2(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_2_SHIFT)) & LPIT_SETTEN_SET_T_EN_2_MASK)

#define LPIT_SETTEN_SET_T_EN_3_MASK              (0x8U)
#define LPIT_SETTEN_SET_T_EN_3_SHIFT             (3U)
/*! SET_T_EN_3 - Set Timer 3 Enable
 *  0b0..No effect
 *  0b1..Enables timer channel 3
 */
#define LPIT_SETTEN_SET_T_EN_3(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_3_SHIFT)) & LPIT_SETTEN_SET_T_EN_3_MASK)
/*! @} */

/*! @name CLRTEN - Clear Timer Enable */
/*! @{ */

#define LPIT_CLRTEN_CLR_T_EN_0_MASK              (0x1U)
#define LPIT_CLRTEN_CLR_T_EN_0_SHIFT             (0U)
/*! CLR_T_EN_0 - Clear Timer 0 Enable
 *  0b0..No action
 *  0b1..Turns TCTRL0[T_EN] = 0 for timer channel 0
 */
#define LPIT_CLRTEN_CLR_T_EN_0(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_0_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_0_MASK)

#define LPIT_CLRTEN_CLR_T_EN_1_MASK              (0x2U)
#define LPIT_CLRTEN_CLR_T_EN_1_SHIFT             (1U)
/*! CLR_T_EN_1 - Clear Timer 1 Enable
 *  0b0..No action
 *  0b1..Turns TCTRL1[T_EN] = 0 for timer channel 1
 */
#define LPIT_CLRTEN_CLR_T_EN_1(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_1_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_1_MASK)

#define LPIT_CLRTEN_CLR_T_EN_2_MASK              (0x4U)
#define LPIT_CLRTEN_CLR_T_EN_2_SHIFT             (2U)
/*! CLR_T_EN_2 - Clear Timer 2 Enable
 *  0b0..No action
 *  0b1..Turns TCTRL2[T_EN] = 0 for timer channel 2
 */
#define LPIT_CLRTEN_CLR_T_EN_2(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_2_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_2_MASK)

#define LPIT_CLRTEN_CLR_T_EN_3_MASK              (0x8U)
#define LPIT_CLRTEN_CLR_T_EN_3_SHIFT             (3U)
/*! CLR_T_EN_3 - Clear Timer 3 Enable
 *  0b0..No action
 *  0b1..Turns TCTRL3[T_EN] = 0 for timer channel 3
 */
#define LPIT_CLRTEN_CLR_T_EN_3(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_3_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_3_MASK)
/*! @} */

/*! @name TVAL - Timer Value */
/*! @{ */

#define LPIT_TVAL_TMR_VAL_MASK                   (0xFFFFFFFFU)
#define LPIT_TVAL_TMR_VAL_SHIFT                  (0U)
/*! TMR_VAL - Timer Value
 *  0b00000000000000000000000000000000, 0b00000000000000000000000000000001..Invalid load value in Compare mode
 *  0b00000000000000000000000000000010-0b11111111111111111111111111111111..In Compare mode: the value to be loaded; in Capture mode, the value of the timer
 */
#define LPIT_TVAL_TMR_VAL(x)                     (((uint32_t)(((uint32_t)(x)) << LPIT_TVAL_TMR_VAL_SHIFT)) & LPIT_TVAL_TMR_VAL_MASK)
/*! @} */

/* The count of LPIT_TVAL */
#define LPIT_TVAL_COUNT                          (4U)

/*! @name CVAL - Current Timer Value */
/*! @{ */

#define LPIT_CVAL_TMR_CUR_VAL_MASK               (0xFFFFFFFFU)
#define LPIT_CVAL_TMR_CUR_VAL_SHIFT              (0U)
/*! TMR_CUR_VAL - Current Timer Value */
#define LPIT_CVAL_TMR_CUR_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << LPIT_CVAL_TMR_CUR_VAL_SHIFT)) & LPIT_CVAL_TMR_CUR_VAL_MASK)
/*! @} */

/* The count of LPIT_CVAL */
#define LPIT_CVAL_COUNT                          (4U)

/*! @name TCTRL - Timer Control */
/*! @{ */

#define LPIT_TCTRL_T_EN_MASK                     (0x1U)
#define LPIT_TCTRL_T_EN_SHIFT                    (0U)
/*! T_EN - Timer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPIT_TCTRL_T_EN(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_T_EN_SHIFT)) & LPIT_TCTRL_T_EN_MASK)

#define LPIT_TCTRL_CHAIN_MASK                    (0x2U)
#define LPIT_TCTRL_CHAIN_SHIFT                   (1U)
/*! CHAIN - Chain Channel
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPIT_TCTRL_CHAIN(x)                      (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_CHAIN_SHIFT)) & LPIT_TCTRL_CHAIN_MASK)

#define LPIT_TCTRL_MODE_MASK                     (0xCU)
#define LPIT_TCTRL_MODE_SHIFT                    (2U)
/*! MODE - Timer Operation Mode
 *  0b00..32-bit periodic counter
 *  0b01..Dual 16-bit periodic counter
 *  0b10..32-bit trigger accumulator
 *  0b11..32-bit trigger input capture
 */
#define LPIT_TCTRL_MODE(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_MODE_SHIFT)) & LPIT_TCTRL_MODE_MASK)

#define LPIT_TCTRL_TSOT_MASK                     (0x10000U)
#define LPIT_TCTRL_TSOT_SHIFT                    (16U)
/*! TSOT - Timer Start on Trigger
 *  0b0..Immediately
 *  0b1..When a rising edge is detected
 */
#define LPIT_TCTRL_TSOT(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_TSOT_SHIFT)) & LPIT_TCTRL_TSOT_MASK)

#define LPIT_TCTRL_TSOI_MASK                     (0x20000U)
#define LPIT_TCTRL_TSOI_SHIFT                    (17U)
/*! TSOI - Timer Stop on Interrupt
 *  0b0..Does not stop
 *  0b1..Stops
 */
#define LPIT_TCTRL_TSOI(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_TSOI_SHIFT)) & LPIT_TCTRL_TSOI_MASK)

#define LPIT_TCTRL_TROT_MASK                     (0x40000U)
#define LPIT_TCTRL_TROT_SHIFT                    (18U)
/*! TROT - Timer Reload on Trigger
 *  0b0..Does not reload
 *  0b1..Reloads
 */
#define LPIT_TCTRL_TROT(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_TROT_SHIFT)) & LPIT_TCTRL_TROT_MASK)

#define LPIT_TCTRL_TRG_SRC_MASK                  (0x800000U)
#define LPIT_TCTRL_TRG_SRC_SHIFT                 (23U)
/*! TRG_SRC - Trigger Source
 *  0b0..External
 *  0b1..Internal
 */
#define LPIT_TCTRL_TRG_SRC(x)                    (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_TRG_SRC_SHIFT)) & LPIT_TCTRL_TRG_SRC_MASK)

#define LPIT_TCTRL_TRG_SEL_MASK                  (0xF000000U)
#define LPIT_TCTRL_TRG_SEL_SHIFT                 (24U)
/*! TRG_SEL - Trigger Select
 *  0b0000-0b0011..Timer channel 0-3 trigger source
 *  0b0100-0b1111..Reserved
 */
#define LPIT_TCTRL_TRG_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPIT_TCTRL_TRG_SEL_SHIFT)) & LPIT_TCTRL_TRG_SEL_MASK)
/*! @} */

/* The count of LPIT_TCTRL */
#define LPIT_TCTRL_COUNT                         (4U)


/*!
 * @}
 */ /* end of group LPIT_Register_Masks */


/*!
 * @}
 */ /* end of group LPIT_Peripheral_Access_Layer */


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


#endif  /* PERI_LPIT_H_ */
