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
**         CMSIS Peripheral Access Layer for PLL
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
 * @file PERI_PLL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PLL
 *
 * CMSIS Peripheral Access Layer for PLL
 */

#if !defined(PERI_PLL_H_)
#define PERI_PLL_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Peripheral_Access_Layer PLL Peripheral Access Layer
 * @{
 */

/** PLL - Size of Registers Arrays */
#define PLL_DFS_COUNT                             3u

/** PLL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< PLL Control, offset: 0x0 */
    __IO uint32_t SET;                               /**< PLL Control, offset: 0x4 */
    __IO uint32_t CLR;                               /**< PLL Control, offset: 0x8 */
    __IO uint32_t TOG;                               /**< PLL Control, offset: 0xC */
  } CTRL;
       uint8_t RESERVED_0[32];
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Spread Spectrum, offset: 0x30, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t SET;                               /**< Spread Spectrum, offset: 0x34, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t CLR;                               /**< Spread Spectrum, offset: 0x38, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t TOG;                               /**< Spread Spectrum, offset: 0x3C, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
  } SPREAD_SPECTRUM;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< Numerator, offset: 0x40, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t SET;                               /**< Numerator, offset: 0x44, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t CLR;                               /**< Numerator, offset: 0x48, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t TOG;                               /**< Numerator, offset: 0x4C, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
  } NUMERATOR;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< Denominator, offset: 0x50, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t SET;                               /**< Denominator, offset: 0x54, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t CLR;                               /**< Denominator, offset: 0x58, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
    __IO uint32_t TOG;                               /**< Denominator, offset: 0x5C, available only on: AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL (missing on ARMPLL) */
  } DENOMINATOR;
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< PLL Dividers, offset: 0x60 */
    __IO uint32_t SET;                               /**< PLL Dividers, offset: 0x64 */
    __IO uint32_t CLR;                               /**< PLL Dividers, offset: 0x68 */
    __IO uint32_t TOG;                               /**< PLL Dividers, offset: 0x6C */
  } DIV;
  struct {                                         /* offset: 0x70, array step: 0x20 */
    struct {                                         /* offset: 0x70 */
      __IO uint32_t RW;                                /**< DFS Control, offset: 0x70, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
      __IO uint32_t SET;                               /**< DFS Control, offset: 0x74, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
      __IO uint32_t CLR;                               /**< DFS Control, offset: 0x78, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
      __IO uint32_t TOG;                               /**< DFS Control, offset: 0x7C, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
    } DFS_CTRL;
    struct {                                         /* offset: 0x80 */
      __IO uint32_t RW;                                /**< DFS Division_0..DFS Division_2, offset: 0x80, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
      __IO uint32_t SET;                               /**< DFS Division_0..DFS Division_2, offset: 0x84, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
      __IO uint32_t CLR;                               /**< DFS Division_0..DFS Division_2, offset: 0x88, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
      __IO uint32_t TOG;                               /**< DFS Division_0..DFS Division_2, offset: 0x8C, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
    } DFS_DIV;
  } DFS[PLL_DFS_COUNT];
       uint8_t RESERVED_1[32];
  __I  uint32_t PLL_STATUS;                        /**< PLL Status, offset: 0xF0 */
  __I  uint32_t DFS_STATUS;                        /**< DFS Status, offset: 0xF4, available only on: SYSPLL (missing on ARMPLL, AUDIOPLL, DRAMPLL, VIDEOPLL) */
} PLL_Type;

/* ----------------------------------------------------------------------------
   -- PLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Register_Masks PLL Register Masks
 * @{
 */

/*! @name CTRL - PLL Control */
/*! @{ */

#define PLL_CTRL_POWERUP_MASK                    (0x1U)
#define PLL_CTRL_POWERUP_SHIFT                   (0U)
/*! POWERUP - Power Up
 *  0b0..Disables PLL.
 *  0b1..Enables PLL
 */
#define PLL_CTRL_POWERUP(x)                      (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_POWERUP_SHIFT)) & PLL_CTRL_POWERUP_MASK)

#define PLL_CTRL_CLKMUX_EN_MASK                  (0x2U)
#define PLL_CTRL_CLKMUX_EN_SHIFT                 (1U)
/*! CLKMUX_EN - CLKMUX Enable
 *  0b0..Disables output clock mux.
 *  0b1..Enables output clock mux.
 */
#define PLL_CTRL_CLKMUX_EN(x)                    (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_CLKMUX_EN_SHIFT)) & PLL_CTRL_CLKMUX_EN_MASK)

#define PLL_CTRL_CLKMUX_BYPASS_MASK              (0x4U)
#define PLL_CTRL_CLKMUX_BYPASS_SHIFT             (2U)
/*! CLKMUX_BYPASS - CLKMUX_Bypass
 *  0b0..Normal mode
 *  0b1..PLL bypass mode
 */
#define PLL_CTRL_CLKMUX_BYPASS(x)                (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_CLKMUX_BYPASS_SHIFT)) & PLL_CTRL_CLKMUX_BYPASS_MASK)

#define PLL_CTRL_SPREADCTL_MASK                  (0x100U)
#define PLL_CTRL_SPREADCTL_SHIFT                 (8U)
/*! SPREADCTL - Modulation Type Select
 *  0b0..Modulation is centered around nominal frequency.
 *  0b1..Modulation is spread below nominal frequency.
 */
#define PLL_CTRL_SPREADCTL(x)                    (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_SPREADCTL_SHIFT)) & PLL_CTRL_SPREADCTL_MASK)

#define PLL_CTRL_HW_CTRL_SEL_MASK                (0x10000U)
#define PLL_CTRL_HW_CTRL_SEL_SHIFT               (16U)
/*! HW_CTRL_SEL - Hardware Control Select
 *  0b0..Disables hardware control. PLL is controlled by register.
 *  0b1..Enables hardware control. PLL is controlled by hardware inputs.
 */
#define PLL_CTRL_HW_CTRL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_HW_CTRL_SEL_SHIFT)) & PLL_CTRL_HW_CTRL_SEL_MASK)

#define PLL_CTRL_LOCK_BYPASS_MASK                (0x80000000U)
#define PLL_CTRL_LOCK_BYPASS_SHIFT               (31U)
/*! LOCK_BYPASS - Lock Bypass
 *  0b0..Disables bypass for the lock detector.
 *  0b1..Enables bypass for the lock detector.
 */
#define PLL_CTRL_LOCK_BYPASS(x)                  (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_LOCK_BYPASS_SHIFT)) & PLL_CTRL_LOCK_BYPASS_MASK)
/*! @} */

/*! @name SPREAD_SPECTRUM - Spread Spectrum */
/*! @{ */

#define PLL_SPREAD_SPECTRUM_STEP_MASK            (0x7FFFU)
#define PLL_SPREAD_SPECTRUM_STEP_SHIFT           (0U)
/*! STEP - Step */
#define PLL_SPREAD_SPECTRUM_STEP(x)              (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STEP_SHIFT)) & PLL_SPREAD_SPECTRUM_STEP_MASK)

#define PLL_SPREAD_SPECTRUM_ENABLE_MASK          (0x8000U)
#define PLL_SPREAD_SPECTRUM_ENABLE_SHIFT         (15U)
/*! ENABLE - Enable
 *  0b0..Disables the spread spectrum modulation.
 *  0b1..Enables the spread spectrum modulation.
 */
#define PLL_SPREAD_SPECTRUM_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_ENABLE_SHIFT)) & PLL_SPREAD_SPECTRUM_ENABLE_MASK)

#define PLL_SPREAD_SPECTRUM_STOP_MASK            (0xFFFF0000U)
#define PLL_SPREAD_SPECTRUM_STOP_SHIFT           (16U)
/*! STOP - Stop */
#define PLL_SPREAD_SPECTRUM_STOP(x)              (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STOP_SHIFT)) & PLL_SPREAD_SPECTRUM_STOP_MASK)
/*! @} */

/*! @name NUMERATOR - Numerator */
/*! @{ */

#define PLL_NUMERATOR_MFN_MASK                   (0xFFFFFFFCU)
#define PLL_NUMERATOR_MFN_SHIFT                  (2U)
/*! MFN - Numerator */
#define PLL_NUMERATOR_MFN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_NUMERATOR_MFN_SHIFT)) & PLL_NUMERATOR_MFN_MASK)
/*! @} */

/*! @name DENOMINATOR - Denominator */
/*! @{ */

#define PLL_DENOMINATOR_MFD_MASK                 (0x3FFFFFFFU)
#define PLL_DENOMINATOR_MFD_SHIFT                (0U)
/*! MFD - Denominator */
#define PLL_DENOMINATOR_MFD(x)                   (((uint32_t)(((uint32_t)(x)) << PLL_DENOMINATOR_MFD_SHIFT)) & PLL_DENOMINATOR_MFD_MASK)
/*! @} */

/*! @name DIV - PLL Dividers */
/*! @{ */

#define PLL_DIV_ODIV_MASK                        (0xFFU)
#define PLL_DIV_ODIV_SHIFT                       (0U)
/*! ODIV - Output Frequency Divider for Clock Output
 *  0b00000000..Divide by 2
 *  0b00000001..Divide by 3
 *  0b00000010..Divide by 2
 *  0b00000011..Divide by 3
 *  0b00000100..Divide by 4
 *  0b00000101..Divide by 5
 *  0b00000110..Divide by 6
 *  0b00001010..Divide by 10
 *  0b10000010..Divide by 130
 *  0b11111111..Divide by 255
 */
#define PLL_DIV_ODIV(x)                          (((uint32_t)(((uint32_t)(x)) << PLL_DIV_ODIV_SHIFT)) & PLL_DIV_ODIV_MASK)

#define PLL_DIV_RDIV_MASK                        (0xE000U)
#define PLL_DIV_RDIV_SHIFT                       (13U)
/*! RDIV - Input Clock Predivider
 *  0b000..Divide by 1
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 3
 *  0b100..Divide by 4
 *  0b101..Divide by 5
 *  0b110..Divide by 6
 *  0b111..Divide by 7
 */
#define PLL_DIV_RDIV(x)                          (((uint32_t)(((uint32_t)(x)) << PLL_DIV_RDIV_SHIFT)) & PLL_DIV_RDIV_MASK)

#define PLL_DIV_MFI_MASK                         (0x1FF0000U)
#define PLL_DIV_MFI_SHIFT                        (16U)
/*! MFI - Integer Portion of Loop Divider */
#define PLL_DIV_MFI(x)                           (((uint32_t)(((uint32_t)(x)) << PLL_DIV_MFI_SHIFT)) & PLL_DIV_MFI_MASK)
/*! @} */

/*! @name DFS - DFS Control */
/*! @{ */

#define PLL_DFS_HW_CTRL_SEL_MASK                 (0x10000U)
#define PLL_DFS_HW_CTRL_SEL_SHIFT                (16U)
/*! HW_CTRL_SEL - Hardware Control Select
 *  0b0..Disables hardware control. DFS is controlled by register
 *  0b1..Enables hardware control.DFS is controlled by hardware inputs.
 */
#define PLL_DFS_HW_CTRL_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << PLL_DFS_HW_CTRL_SEL_SHIFT)) & PLL_DFS_HW_CTRL_SEL_MASK)

#define PLL_DFS_BYPASS_EN_MASK                   (0x800000U)
#define PLL_DFS_BYPASS_EN_SHIFT                  (23U)
/*! BYPASS_EN - Bypass Enable
 *  0b0..Disables bypass for DFS.
 *  0b1..Enables bypass for DFS.
 */
#define PLL_DFS_BYPASS_EN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_BYPASS_EN_SHIFT)) & PLL_DFS_BYPASS_EN_MASK)

#define PLL_DFS_CLKOUT_DIVBY2_EN_MASK            (0x20000000U)
#define PLL_DFS_CLKOUT_DIVBY2_EN_SHIFT           (29U)
/*! CLKOUT_DIVBY2_EN - DFS Clock Output Divide by 2 Enable
 *  0b0..Disables DFS divide by 2 clock output.
 *  0b1..Enables DFS divide by 2 clock output.
 */
#define PLL_DFS_CLKOUT_DIVBY2_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CLKOUT_DIVBY2_EN_SHIFT)) & PLL_DFS_CLKOUT_DIVBY2_EN_MASK)

#define PLL_DFS_CLKOUT_EN_MASK                   (0x40000000U)
#define PLL_DFS_CLKOUT_EN_SHIFT                  (30U)
/*! CLKOUT_EN - DFS Clock Output Enable
 *  0b0..Disables DFS clock output.
 *  0b1..Enables DFS clock output.
 */
#define PLL_DFS_CLKOUT_EN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CLKOUT_EN_SHIFT)) & PLL_DFS_CLKOUT_EN_MASK)

#define PLL_DFS_ENABLE_MASK                      (0x80000000U)
#define PLL_DFS_ENABLE_SHIFT                     (31U)
/*! ENABLE - DFS Block Enable
 *  0b0..Disables DFS Block.
 *  0b1..Enables DFS Block.
 */
#define PLL_DFS_ENABLE(x)                        (((uint32_t)(((uint32_t)(x)) << PLL_DFS_ENABLE_SHIFT)) & PLL_DFS_ENABLE_MASK)
/*! @} */

/*! @name DFS - DFS Division_0..DFS Division_2 */
/*! @{ */

#define PLL_DFS_MFN_MASK                         (0x7U)
#define PLL_DFS_MFN_SHIFT                        (0U)
#define PLL_DFS_MFN(x)                           (((uint32_t)(((uint32_t)(x)) << PLL_DFS_MFN_SHIFT)) & PLL_DFS_MFN_MASK)

#define PLL_DFS_MFI_MASK                         (0xFF00U)
#define PLL_DFS_MFI_SHIFT                        (8U)
#define PLL_DFS_MFI(x)                           (((uint32_t)(((uint32_t)(x)) << PLL_DFS_MFI_SHIFT)) & PLL_DFS_MFI_MASK)
/*! @} */

/*! @name PLL_STATUS - PLL Status */
/*! @{ */

#define PLL_PLL_STATUS_PLL_LOCK_MASK             (0x1U)
#define PLL_PLL_STATUS_PLL_LOCK_SHIFT            (0U)
/*! PLL_LOCK - PLL_LOCK */
#define PLL_PLL_STATUS_PLL_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_PLL_LOCK_SHIFT)) & PLL_PLL_STATUS_PLL_LOCK_MASK)

#define PLL_PLL_STATUS_PLL_LOL_MASK              (0x2U)
#define PLL_PLL_STATUS_PLL_LOL_SHIFT             (1U)
/*! PLL_LOL - PLL_LOL */
#define PLL_PLL_STATUS_PLL_LOL(x)                (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_PLL_LOL_SHIFT)) & PLL_PLL_STATUS_PLL_LOL_MASK)

#define PLL_PLL_STATUS_ANA_MFN_MASK              (0xFFFFFFFCU)
#define PLL_PLL_STATUS_ANA_MFN_SHIFT             (2U)
/*! ANA_MFN - ANA_MFN */
#define PLL_PLL_STATUS_ANA_MFN(x)                (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_ANA_MFN_SHIFT)) & PLL_PLL_STATUS_ANA_MFN_MASK)
/*! @} */

/*! @name DFS_STATUS - DFS Status */
/*! @{ */

#define PLL_DFS_STATUS_DFS_OK_MASK               (0x7U)
#define PLL_DFS_STATUS_DFS_OK_SHIFT              (0U)
/*! DFS_OK - DFS OK
 *  0b000..The corresponding DFS output clock is not valid.
 *  0b001..The corresponding DFS output clock is valid.
 */
#define PLL_DFS_STATUS_DFS_OK(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_DFS_STATUS_DFS_OK_SHIFT)) & PLL_DFS_STATUS_DFS_OK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PLL_Register_Masks */


/*!
 * @}
 */ /* end of group PLL_Peripheral_Access_Layer */


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


#endif  /* PERI_PLL_H_ */
