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
**         CMSIS Peripheral Access Layer for CCM32K
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
 * @file PERI_CCM32K.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for CCM32K
 *
 * CMSIS Peripheral Access Layer for CCM32K
 */

#if !defined(PERI_CCM32K_H_)
#define PERI_CCM32K_H_                           /**< Symbol preventing repeated inclusion */

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
   -- CCM32K Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM32K_Peripheral_Access_Layer CCM32K Peripheral Access Layer
 * @{
 */

/** CCM32K - Register Layout Typedef */
typedef struct {
  __IO uint32_t FRO32K_CTRL;                       /**< Free Running 32 kHz Oscillator Control Register, offset: 0x0 */
  __IO uint32_t FRO32K_TRIM;                       /**< Free Running 32 kHz Oscillator Trim Register, offset: 0x4 */
  __IO uint32_t OSC32K_CTRL;                       /**< 32 kHz OSC Control Register, offset: 0x8 */
  __I  uint32_t STATUS;                            /**< Status Register, offset: 0xC */
       uint8_t RESERVED_0[4];
  __IO uint32_t CLKMON_CTRL;                       /**< Clock Monitor Control Register, offset: 0x14 */
  __IO uint32_t CLKMON_TST;                        /**< Clock Monitor Test Register, offset: 0x18 */
  __IO uint32_t CGC32K;                            /**< 32 kHz Clock Gate Control Register, offset: 0x1C */
       uint8_t RESERVED_1[4];
  __IO uint32_t OSC32K_MON_TRIM;                   /**< 32 kHz OSC Internal Monitor Trim Register, offset: 0x24 */
} CCM32K_Type;

/* ----------------------------------------------------------------------------
   -- CCM32K Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM32K_Register_Masks CCM32K Register Masks
 * @{
 */

/*! @name FRO32K_CTRL - Free Running 32 kHz Oscillator Control Register */
/*! @{ */

#define CCM32K_FRO32K_CTRL_FRO_EN_MASK           (0x1U)
#define CCM32K_FRO32K_CTRL_FRO_EN_SHIFT          (0U)
/*! FRO_EN - FRO Enable
 *  0b0..FRO is disabled
 *  0b1..FRO is enabled
 */
#define CCM32K_FRO32K_CTRL_FRO_EN(x)             (((uint32_t)(((uint32_t)(x)) << CCM32K_FRO32K_CTRL_FRO_EN_SHIFT)) & CCM32K_FRO32K_CTRL_FRO_EN_MASK)

#define CCM32K_FRO32K_CTRL_LOCK_EN_MASK          (0x80000000U)
#define CCM32K_FRO32K_CTRL_LOCK_EN_SHIFT         (31U)
/*! LOCK_EN - Write Access Lock
 *  0b0..Register write access is unlocked
 *  0b1..Register write access is locked
 */
#define CCM32K_FRO32K_CTRL_LOCK_EN(x)            (((uint32_t)(((uint32_t)(x)) << CCM32K_FRO32K_CTRL_LOCK_EN_SHIFT)) & CCM32K_FRO32K_CTRL_LOCK_EN_MASK)
/*! @} */

/*! @name FRO32K_TRIM - Free Running 32 kHz Oscillator Trim Register */
/*! @{ */

#define CCM32K_FRO32K_TRIM_FREQ_TRIM_MASK        (0x7FFU)
#define CCM32K_FRO32K_TRIM_FREQ_TRIM_SHIFT       (0U)
/*! FREQ_TRIM - Frequency Trim
 *  0b10000000000..Default trim value
 */
#define CCM32K_FRO32K_TRIM_FREQ_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << CCM32K_FRO32K_TRIM_FREQ_TRIM_SHIFT)) & CCM32K_FRO32K_TRIM_FREQ_TRIM_MASK)

#define CCM32K_FRO32K_TRIM_IFR_DIS_MASK          (0x20000000U)
#define CCM32K_FRO32K_TRIM_IFR_DIS_SHIFT         (29U)
/*! IFR_DIS - IFR Loading Disable Control
 *  0b0..IFR loading is enabled
 *  0b1..IFR loading is disabled
 */
#define CCM32K_FRO32K_TRIM_IFR_DIS(x)            (((uint32_t)(((uint32_t)(x)) << CCM32K_FRO32K_TRIM_IFR_DIS_SHIFT)) & CCM32K_FRO32K_TRIM_IFR_DIS_MASK)

#define CCM32K_FRO32K_TRIM_LOCK_EN_MASK          (0x80000000U)
#define CCM32K_FRO32K_TRIM_LOCK_EN_SHIFT         (31U)
/*! LOCK_EN - Write Access Lock
 *  0b0..Register write access is unlocked
 *  0b1..Register write access is locked
 */
#define CCM32K_FRO32K_TRIM_LOCK_EN(x)            (((uint32_t)(((uint32_t)(x)) << CCM32K_FRO32K_TRIM_LOCK_EN_SHIFT)) & CCM32K_FRO32K_TRIM_LOCK_EN_MASK)
/*! @} */

/*! @name OSC32K_CTRL - 32 kHz OSC Control Register */
/*! @{ */

#define CCM32K_OSC32K_CTRL_OSC_EN_MASK           (0x1U)
#define CCM32K_OSC32K_CTRL_OSC_EN_SHIFT          (0U)
/*! OSC_EN - Crystal Oscillator Enable
 *  0b0..Oscillator is disabled
 *  0b1..Oscillator is enabled
 */
#define CCM32K_OSC32K_CTRL_OSC_EN(x)             (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_OSC_EN_SHIFT)) & CCM32K_OSC32K_CTRL_OSC_EN_MASK)

#define CCM32K_OSC32K_CTRL_OSC_BYP_EN_MASK       (0x2U)
#define CCM32K_OSC32K_CTRL_OSC_BYP_EN_SHIFT      (1U)
/*! OSC_BYP_EN - Crystal Oscillator Bypass Enable
 *  0b0..Crystal oscillator is not bypassed
 *  0b1..Crystal oscillator is bypassed
 */
#define CCM32K_OSC32K_CTRL_OSC_BYP_EN(x)         (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_OSC_BYP_EN_SHIFT)) & CCM32K_OSC32K_CTRL_OSC_BYP_EN_MASK)

#define CCM32K_OSC32K_CTRL_OSC_CLKMON_EN_MASK    (0x4U)
#define CCM32K_OSC32K_CTRL_OSC_CLKMON_EN_SHIFT   (2U)
/*! OSC_CLKMON_EN - Crystal Oscillator Internal Clock Monitor Enable
 *  0b0..Oscillator internal clock monitor is disabled
 *  0b1..Oscillator internal clock monitor is enabled
 */
#define CCM32K_OSC32K_CTRL_OSC_CLKMON_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_OSC_CLKMON_EN_SHIFT)) & CCM32K_OSC32K_CTRL_OSC_CLKMON_EN_MASK)

#define CCM32K_OSC32K_CTRL_CAP_TRIM_MASK         (0x60U)
#define CCM32K_OSC32K_CTRL_CAP_TRIM_SHIFT        (5U)
/*! CAP_TRIM - SOX Capacitor Trim */
#define CCM32K_OSC32K_CTRL_CAP_TRIM(x)           (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_CAP_TRIM_SHIFT)) & CCM32K_OSC32K_CTRL_CAP_TRIM_MASK)

#define CCM32K_OSC32K_CTRL_CAP_SEL_EN_MASK       (0x80U)
#define CCM32K_OSC32K_CTRL_CAP_SEL_EN_SHIFT      (7U)
/*! CAP_SEL_EN - Crystal Load Capacitance Selection Enable
 *  0b0..Internal capacitance bank is not enabled
 *  0b1..Internal capacitance bank is enabled
 */
#define CCM32K_OSC32K_CTRL_CAP_SEL_EN(x)         (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_CAP_SEL_EN_SHIFT)) & CCM32K_OSC32K_CTRL_CAP_SEL_EN_MASK)

#define CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL_MASK    (0xF00U)
#define CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL_SHIFT   (8U)
/*! EXTAL_CAP_SEL - Crystal load capacitance selection bits
 *  0b0000..0 pF
 *  0b0001..2 pF
 *  0b0010..4 pF
 *  0b0011..6 pF
 *  0b0100..8 pF
 *  0b0101..10 pF
 *  0b0110..12 pF
 *  0b0111..14 pF
 *  0b1000..16 pF
 *  0b1001..18 pF
 *  0b1010..20 pF
 *  0b1011..22 pF
 *  0b1100..24 pF
 *  0b1101..26 pF
 *  0b1110..28 pF
 *  0b1111..30 pF
 */
#define CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL_SHIFT)) & CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL_MASK)

#define CCM32K_OSC32K_CTRL_XTAL_CAP_SEL_MASK     (0xF000U)
#define CCM32K_OSC32K_CTRL_XTAL_CAP_SEL_SHIFT    (12U)
/*! XTAL_CAP_SEL - Crystal load capacitance selection bits
 *  0b0000..0 pF
 *  0b0001..2 pF
 *  0b0010..4 pF
 *  0b0011..6 pF
 *  0b0100..8 pF
 *  0b0101..10 pF
 *  0b0110..12 pF
 *  0b0111..14 pF
 *  0b1000..16 pF
 *  0b1001..18 pF
 *  0b1010..20 pF
 *  0b1011..22 pF
 *  0b1100..24 pF
 *  0b1101..26 pF
 *  0b1110..28 pF
 *  0b1111..30 pF
 */
#define CCM32K_OSC32K_CTRL_XTAL_CAP_SEL(x)       (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_XTAL_CAP_SEL_SHIFT)) & CCM32K_OSC32K_CTRL_XTAL_CAP_SEL_MASK)

#define CCM32K_OSC32K_CTRL_CMP_TRIM_MASK         (0x70000U)
#define CCM32K_OSC32K_CTRL_CMP_TRIM_SHIFT        (16U)
/*! CMP_TRIM - SOX Comparator trim */
#define CCM32K_OSC32K_CTRL_CMP_TRIM(x)           (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_CMP_TRIM_SHIFT)) & CCM32K_OSC32K_CTRL_CMP_TRIM_MASK)

#define CCM32K_OSC32K_CTRL_OSC_HP_EN_MASK        (0x80000U)
#define CCM32K_OSC32K_CTRL_OSC_HP_EN_SHIFT       (19U)
/*! OSC_HP_EN - Crystal Oscillator High Power Enable
 *  0b0..Oscillator internal clock monitor is disabled
 *  0b1..Oscillator internal clock monitor is enabled
 */
#define CCM32K_OSC32K_CTRL_OSC_HP_EN(x)          (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_OSC_HP_EN_SHIFT)) & CCM32K_OSC32K_CTRL_OSC_HP_EN_MASK)

#define CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN_MASK  (0x300000U)
#define CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN_SHIFT (20U)
/*! COARSE_AMP_GAIN - Amplifier gain adjustment bits to allow the use of a wide range of external crystal ESR values.
 *  0b00..ESR_Range0
 *  0b01..ESR_Range1
 *  0b10..ESR_Range2
 *  0b11..ESR_Range3
 */
#define CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN(x)    (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN_SHIFT)) & CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN_MASK)

#define CCM32K_OSC32K_CTRL_SOX_EN_MASK           (0x1000000U)
#define CCM32K_OSC32K_CTRL_SOX_EN_SHIFT          (24U)
/*! SOX_EN - Crystal mode enable
 *  0b0..Not supported for crystal mode operation
 *  0b1..Required for crystal mode operation
 */
#define CCM32K_OSC32K_CTRL_SOX_EN(x)             (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_SOX_EN_SHIFT)) & CCM32K_OSC32K_CTRL_SOX_EN_MASK)

#define CCM32K_OSC32K_CTRL_SUPPLY_DET_MASK       (0x6000000U)
#define CCM32K_OSC32K_CTRL_SUPPLY_DET_SHIFT      (25U)
/*! SUPPLY_DET - Supply Detector Trim */
#define CCM32K_OSC32K_CTRL_SUPPLY_DET(x)         (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_SUPPLY_DET_SHIFT)) & CCM32K_OSC32K_CTRL_SUPPLY_DET_MASK)

#define CCM32K_OSC32K_CTRL_DLY_TRIM_MASK         (0x78000000U)
#define CCM32K_OSC32K_CTRL_DLY_TRIM_SHIFT        (27U)
/*! DLY_TRIM - SOX Delay Selection */
#define CCM32K_OSC32K_CTRL_DLY_TRIM(x)           (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_DLY_TRIM_SHIFT)) & CCM32K_OSC32K_CTRL_DLY_TRIM_MASK)

#define CCM32K_OSC32K_CTRL_LOCK_EN_MASK          (0x80000000U)
#define CCM32K_OSC32K_CTRL_LOCK_EN_SHIFT         (31U)
/*! LOCK_EN - Write Access Lock bit
 *  0b0..Register write access is unlocked
 *  0b1..Register write access is locked
 */
#define CCM32K_OSC32K_CTRL_LOCK_EN(x)            (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_CTRL_LOCK_EN_SHIFT)) & CCM32K_OSC32K_CTRL_LOCK_EN_MASK)
/*! @} */

/*! @name STATUS - Status Register */
/*! @{ */

#define CCM32K_STATUS_OSC32K_RDY_MASK            (0x1U)
#define CCM32K_STATUS_OSC32K_RDY_SHIFT           (0U)
/*! OSC32K_RDY - 32 kHz Oscillator ready bit.
 *  0b0..Clock output from crystal oscillator is not stable.
 *  0b1..Clock output from crystal oscillator is stable.
 */
#define CCM32K_STATUS_OSC32K_RDY(x)              (((uint32_t)(((uint32_t)(x)) << CCM32K_STATUS_OSC32K_RDY_SHIFT)) & CCM32K_STATUS_OSC32K_RDY_MASK)

#define CCM32K_STATUS_OSC32K_ACTIVE_MASK         (0x4U)
#define CCM32K_STATUS_OSC32K_ACTIVE_SHIFT        (2U)
/*! OSC32K_ACTIVE - 32 kHz Oscillator active bit
 *  0b0..OSC32K is not the active clock source
 *  0b1..OSC32K is the active clock source
 */
#define CCM32K_STATUS_OSC32K_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << CCM32K_STATUS_OSC32K_ACTIVE_SHIFT)) & CCM32K_STATUS_OSC32K_ACTIVE_MASK)

#define CCM32K_STATUS_FRO32K_ACTIVE_MASK         (0x10U)
#define CCM32K_STATUS_FRO32K_ACTIVE_SHIFT        (4U)
/*! FRO32K_ACTIVE - 32 kHz FRO active bit
 *  0b0..FRO32K is not the active clock source
 *  0b1..FRO32K is the active clock source
 */
#define CCM32K_STATUS_FRO32K_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << CCM32K_STATUS_FRO32K_ACTIVE_SHIFT)) & CCM32K_STATUS_FRO32K_ACTIVE_MASK)

#define CCM32K_STATUS_CLOCK_DET_MASK             (0x40U)
#define CCM32K_STATUS_CLOCK_DET_SHIFT            (6U)
/*! CLOCK_DET - Clock Detect
 *  0b0..Clock error is not detected
 *  0b1..Clock error is detected
 */
#define CCM32K_STATUS_CLOCK_DET(x)               (((uint32_t)(((uint32_t)(x)) << CCM32K_STATUS_CLOCK_DET_SHIFT)) & CCM32K_STATUS_CLOCK_DET_MASK)

#define CCM32K_STATUS_AUTO_SWITCH_MASK           (0x100U)
#define CCM32K_STATUS_AUTO_SWITCH_SHIFT          (8U)
/*! AUTO_SWITCH - Clock Source Auto switch
 *  0b0..Clock source do not switch
 *  0b1..Clock source switch back to FRO
 */
#define CCM32K_STATUS_AUTO_SWITCH(x)             (((uint32_t)(((uint32_t)(x)) << CCM32K_STATUS_AUTO_SWITCH_SHIFT)) & CCM32K_STATUS_AUTO_SWITCH_MASK)
/*! @} */

/*! @name CLKMON_CTRL - Clock Monitor Control Register */
/*! @{ */

#define CCM32K_CLKMON_CTRL_MON_EN_MASK           (0x1U)
#define CCM32K_CLKMON_CTRL_MON_EN_SHIFT          (0U)
/*! MON_EN - CLKMON Enable
 *  0b0..CLKMON is disabled
 *  0b1..CLKMON is enabled
 */
#define CCM32K_CLKMON_CTRL_MON_EN(x)             (((uint32_t)(((uint32_t)(x)) << CCM32K_CLKMON_CTRL_MON_EN_SHIFT)) & CCM32K_CLKMON_CTRL_MON_EN_MASK)

#define CCM32K_CLKMON_CTRL_FREQ_TRIM_MASK        (0x6U)
#define CCM32K_CLKMON_CTRL_FREQ_TRIM_SHIFT       (1U)
/*! FREQ_TRIM - Frequency trim bits
 *  0b00..Clock monitor asserts 2 cycle after expected edge (assert after 10 cycles with no edge)
 *  0b01..Clock monitor asserts 4 cycles after expected edge (assert after 12 cycles with no edge)
 *  0b10..Clock monitor asserts 6 cycles after expected edge (assert after 14 cycles with no edge)
 *  0b11..Clock monitor asserts 8 cycles after expected edge (assert after 16 cycles with no edge)
 */
#define CCM32K_CLKMON_CTRL_FREQ_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << CCM32K_CLKMON_CTRL_FREQ_TRIM_SHIFT)) & CCM32K_CLKMON_CTRL_FREQ_TRIM_MASK)

#define CCM32K_CLKMON_CTRL_DIVIDE_TRIM_MASK      (0x18U)
#define CCM32K_CLKMON_CTRL_DIVIDE_TRIM_SHIFT     (3U)
/*! DIVIDE_TRIM - Divide Trim
 *  0b00..Clock monitor operates at 1 kHz for both FRO32K and OSC32K
 *  0b01..Clock monitor operates at 64 Hz for FRO32K and clock monitor operates at 1 kHz for OSC32K (Reserved)
 *  0b10..Clock monitor operates at 1 kHz for FRO32K and clock monitor operates at 64 Hz for OSC32K (Reserved)
 *  0b11..Clock monitor operates at 64 Hz for both FRO32K and OSC32K
 */
#define CCM32K_CLKMON_CTRL_DIVIDE_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << CCM32K_CLKMON_CTRL_DIVIDE_TRIM_SHIFT)) & CCM32K_CLKMON_CTRL_DIVIDE_TRIM_MASK)

#define CCM32K_CLKMON_CTRL_AUTO_SWITCH_EN_MASK   (0x100U)
#define CCM32K_CLKMON_CTRL_AUTO_SWITCH_EN_SHIFT  (8U)
/*! AUTO_SWITCH_EN - Automatic Switch Enable Bit
 *  0b0..Automatic switch is disable
 *  0b1..Automatic switch is enable
 */
#define CCM32K_CLKMON_CTRL_AUTO_SWITCH_EN(x)     (((uint32_t)(((uint32_t)(x)) << CCM32K_CLKMON_CTRL_AUTO_SWITCH_EN_SHIFT)) & CCM32K_CLKMON_CTRL_AUTO_SWITCH_EN_MASK)

#define CCM32K_CLKMON_CTRL_LOCK_EN_MASK          (0x80000000U)
#define CCM32K_CLKMON_CTRL_LOCK_EN_SHIFT         (31U)
/*! LOCK_EN - Write Access Lock bit
 *  0b0..Register write access is unlocked
 *  0b1..Register write access is locked
 */
#define CCM32K_CLKMON_CTRL_LOCK_EN(x)            (((uint32_t)(((uint32_t)(x)) << CCM32K_CLKMON_CTRL_LOCK_EN_SHIFT)) & CCM32K_CLKMON_CTRL_LOCK_EN_MASK)
/*! @} */

/*! @name CLKMON_TST - Clock Monitor Test Register */
/*! @{ */

#define CCM32K_CLKMON_TST_CLKMON_TSTMODE_MASK    (0xFU)
#define CCM32K_CLKMON_TST_CLKMON_TSTMODE_SHIFT   (0U)
/*! CLKMON_TSTMODE - Test Mode */
#define CCM32K_CLKMON_TST_CLKMON_TSTMODE(x)      (((uint32_t)(((uint32_t)(x)) << CCM32K_CLKMON_TST_CLKMON_TSTMODE_SHIFT)) & CCM32K_CLKMON_TST_CLKMON_TSTMODE_MASK)

#define CCM32K_CLKMON_TST_LOCK_EN_MASK           (0x80000000U)
#define CCM32K_CLKMON_TST_LOCK_EN_SHIFT          (31U)
/*! LOCK_EN - Write Access Lock bit
 *  0b0..Register write access is unlocked
 *  0b1..Register write access is locked
 */
#define CCM32K_CLKMON_TST_LOCK_EN(x)             (((uint32_t)(((uint32_t)(x)) << CCM32K_CLKMON_TST_LOCK_EN_SHIFT)) & CCM32K_CLKMON_TST_LOCK_EN_MASK)
/*! @} */

/*! @name CGC32K - 32 kHz Clock Gate Control Register */
/*! @{ */

#define CCM32K_CGC32K_CLK_OE_32K_MASK            (0x1FU)
#define CCM32K_CGC32K_CLK_OE_32K_SHIFT           (0U)
/*! CLK_OE_32K - 32 kHz clock output enable bits
 *  0b00000..Clock output is disabled
 *  0b00001..Clock output is enabled
 */
#define CCM32K_CGC32K_CLK_OE_32K(x)              (((uint32_t)(((uint32_t)(x)) << CCM32K_CGC32K_CLK_OE_32K_SHIFT)) & CCM32K_CGC32K_CLK_OE_32K_MASK)

#define CCM32K_CGC32K_CLK_SEL_32K_MASK           (0x20U)
#define CCM32K_CGC32K_CLK_SEL_32K_SHIFT          (5U)
/*! CLK_SEL_32K - 32 kHz clock source selection bit
 *  0b0..FRO32K clock output is selected as clock source
 *  0b1..OSC32K clock output is selected as clock source
 */
#define CCM32K_CGC32K_CLK_SEL_32K(x)             (((uint32_t)(((uint32_t)(x)) << CCM32K_CGC32K_CLK_SEL_32K_SHIFT)) & CCM32K_CGC32K_CLK_SEL_32K_MASK)

#define CCM32K_CGC32K_LOCK_EN_MASK               (0x80000000U)
#define CCM32K_CGC32K_LOCK_EN_SHIFT              (31U)
/*! LOCK_EN - Write Access Lock bit
 *  0b0..Register write access is unlocked
 *  0b1..Register write access is locked
 */
#define CCM32K_CGC32K_LOCK_EN(x)                 (((uint32_t)(((uint32_t)(x)) << CCM32K_CGC32K_LOCK_EN_SHIFT)) & CCM32K_CGC32K_LOCK_EN_MASK)
/*! @} */

/*! @name OSC32K_MON_TRIM - 32 kHz OSC Internal Monitor Trim Register */
/*! @{ */

#define CCM32K_OSC32K_MON_TRIM_CAP_TRIM_HIGH_MASK (0x1FU)
#define CCM32K_OSC32K_MON_TRIM_CAP_TRIM_HIGH_SHIFT (0U)
/*! CAP_TRIM_HIGH - OSC32K Internal Monitor Capacitance Trim for Clock High Level
 *  0b11111..Default trim value
 */
#define CCM32K_OSC32K_MON_TRIM_CAP_TRIM_HIGH(x)  (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_MON_TRIM_CAP_TRIM_HIGH_SHIFT)) & CCM32K_OSC32K_MON_TRIM_CAP_TRIM_HIGH_MASK)

#define CCM32K_OSC32K_MON_TRIM_CAP_TRIM_LOW_MASK (0x1F00U)
#define CCM32K_OSC32K_MON_TRIM_CAP_TRIM_LOW_SHIFT (8U)
/*! CAP_TRIM_LOW - OSC32K Internal Monitor Capacitance Trim for Clock Low Level
 *  0b11111..Default trim value
 */
#define CCM32K_OSC32K_MON_TRIM_CAP_TRIM_LOW(x)   (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_MON_TRIM_CAP_TRIM_LOW_SHIFT)) & CCM32K_OSC32K_MON_TRIM_CAP_TRIM_LOW_MASK)

#define CCM32K_OSC32K_MON_TRIM_IFR_DIS_MASK      (0x20000000U)
#define CCM32K_OSC32K_MON_TRIM_IFR_DIS_SHIFT     (29U)
/*! IFR_DIS - IFR Loading Disable Control
 *  0b0..IFR loading is enabled
 *  0b1..IFR loading is disabled
 */
#define CCM32K_OSC32K_MON_TRIM_IFR_DIS(x)        (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_MON_TRIM_IFR_DIS_SHIFT)) & CCM32K_OSC32K_MON_TRIM_IFR_DIS_MASK)

#define CCM32K_OSC32K_MON_TRIM_LOCK_EN_MASK      (0x80000000U)
#define CCM32K_OSC32K_MON_TRIM_LOCK_EN_SHIFT     (31U)
/*! LOCK_EN - Write Access Lock
 *  0b0..Register write access is unlocked
 *  0b1..Register write access is locked
 */
#define CCM32K_OSC32K_MON_TRIM_LOCK_EN(x)        (((uint32_t)(((uint32_t)(x)) << CCM32K_OSC32K_MON_TRIM_LOCK_EN_SHIFT)) & CCM32K_OSC32K_MON_TRIM_LOCK_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CCM32K_Register_Masks */


/*!
 * @}
 */ /* end of group CCM32K_Peripheral_Access_Layer */


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


#endif  /* PERI_CCM32K_H_ */

