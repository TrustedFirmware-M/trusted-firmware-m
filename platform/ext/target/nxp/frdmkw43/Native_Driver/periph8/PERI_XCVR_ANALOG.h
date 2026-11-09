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
**         CMSIS Peripheral Access Layer for XCVR_ANALOG
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
 * @file PERI_XCVR_ANALOG.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for XCVR_ANALOG
 *
 * CMSIS Peripheral Access Layer for XCVR_ANALOG
 */

#if !defined(PERI_XCVR_ANALOG_H_)
#define PERI_XCVR_ANALOG_H_                      /**< Symbol preventing repeated inclusion */

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
   -- XCVR_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ANALOG_Peripheral_Access_Layer XCVR_ANALOG Peripheral Access Layer
 * @{
 */

/** XCVR_ANALOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDO_0;                             /**< RF Analog Baseband LDO Control 1, offset: 0x0 */
  __IO uint32_t LDO_1;                             /**< RF Analog Baseband LDO Control 2, offset: 0x4 */
  __IO uint32_t XO_DIST;                           /**< RF Analog XO DIST Control, offset: 0x8 */
  __IO uint32_t PLL;                               /**< RF Analog PLL Control, offset: 0xC */
  __IO uint32_t RX_0;                              /**< RF Analog RX Control0, offset: 0x10 */
  __IO uint32_t RX_1;                              /**< RF Analog RX Control1, offset: 0x14 */
  __IO uint32_t TX_DAC_PA;                         /**< RF Analog TX DAC PA Control, offset: 0x18 */
  __IO uint32_t DIAG;                              /**< RF Analog DIAG Control 1, offset: 0x1C */
  __IO uint32_t SPARE;                             /**< RF Analog SPARE Control, offset: 0x20 */
} XCVR_ANALOG_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_ANALOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ANALOG_Register_Masks XCVR_ANALOG Register Masks
 * @{
 */

/*! @name LDO_0 - RF Analog Baseband LDO Control 1 */
/*! @{ */

#define XCVR_ANALOG_LDO_0_BG_FORCE_MASK          (0x8U)
#define XCVR_ANALOG_LDO_0_BG_FORCE_SHIFT         (3U)
/*! BG_FORCE - reg_bg_force_dig
 *  0b0..force disable
 *  0b1..force enable
 */
#define XCVR_ANALOG_LDO_0_BG_FORCE(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_BG_FORCE_SHIFT)) & XCVR_ANALOG_LDO_0_BG_FORCE_MASK)

#define XCVR_ANALOG_LDO_0_LDO_LV_TRIM_MASK       (0x30U)
#define XCVR_ANALOG_LDO_0_LDO_LV_TRIM_SHIFT      (4U)
/*! LDO_LV_TRIM - reg_ldo_lv_trim_dig[1:0]
 *  0b00..0.91V Default LDO output
 *  0b01..0.86V
 *  0b10..0.97V
 *  0b11..1.3V
 */
#define XCVR_ANALOG_LDO_0_LDO_LV_TRIM(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_LV_TRIM_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_LV_TRIM_MASK)

#define XCVR_ANALOG_LDO_0_LDO_LV_BYPASS_MASK     (0x40U)
#define XCVR_ANALOG_LDO_0_LDO_LV_BYPASS_SHIFT    (6U)
/*! LDO_LV_BYPASS - reg_ldo_lv_bypass_dig
 *  0b0..disable bypass for ldo_lv
 *  0b1..enable bypass for ldo_lv
 */
#define XCVR_ANALOG_LDO_0_LDO_LV_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_LV_BYPASS_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_LV_BYPASS_MASK)

#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_FORCE_MASK  (0x100U)
#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_FORCE_SHIFT (8U)
/*! LDO_RXTXHF_FORCE - reg_ldo_rxtxhf_force_dig
 *  0b0..Force disabled.
 *  0b1..Force enabled
 */
#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_FORCE(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_RXTXHF_FORCE_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_RXTXHF_FORCE_MASK)

#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_PTAT_BUMP_MASK (0x600U)
#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_PTAT_BUMP_SHIFT (9U)
/*! LDO_RXTXHF_PTAT_BUMP - reg_ldo_rxtxhf_ptat_bump_dig
 *  0b00..nominal
 *  0b01..+30%
 *  0b10..nominal
 *  0b11..+30%
 */
#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_PTAT_BUMP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_RXTXHF_PTAT_BUMP_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_RXTXHF_PTAT_BUMP_MASK)

#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_BYPASS_MASK (0x800U)
#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_BYPASS_SHIFT (11U)
/*! LDO_RXTXHF_BYPASS - reg_ldo_rxtxihf_bypass_dig */
#define XCVR_ANALOG_LDO_0_LDO_RXTXHF_BYPASS(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_RXTXHF_BYPASS_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_RXTXHF_BYPASS_MASK)

#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_FORCE_MASK  (0x1000U)
#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_FORCE_SHIFT (12U)
/*! LDO_RXTXLF_FORCE - reg_ldo_rxtxlf_force_dig
 *  0b0..disable force
 *  0b1..enable force
 */
#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_FORCE(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_RXTXLF_FORCE_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_RXTXLF_FORCE_MASK)

#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_PTAT_BUMP_MASK (0x6000U)
#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_PTAT_BUMP_SHIFT (13U)
/*! LDO_RXTXLF_PTAT_BUMP - reg_ldo_rxtxlf_ptat_bump_dig[1:0]
 *  0b00..nominal
 *  0b01..+30%
 *  0b10..nominal
 *  0b11..+30%
 */
#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_PTAT_BUMP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_RXTXLF_PTAT_BUMP_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_RXTXLF_PTAT_BUMP_MASK)

#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_BYPASS_MASK (0x8000U)
#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_BYPASS_SHIFT (15U)
/*! LDO_RXTXLF_BYPASS - reg_ldo_rxtxlf_bypass_dig
 *  0b0..Bypass disable
 *  0b1..Bypass enable
 */
#define XCVR_ANALOG_LDO_0_LDO_RXTXLF_BYPASS(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_RXTXLF_BYPASS_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_RXTXLF_BYPASS_MASK)

#define XCVR_ANALOG_LDO_0_LDO_PLL_FORCE_MASK     (0x10000U)
#define XCVR_ANALOG_LDO_0_LDO_PLL_FORCE_SHIFT    (16U)
/*! LDO_PLL_FORCE - reg_ldo_pll_force_dig
 *  0b0..force disable
 *  0b1..force enable
 */
#define XCVR_ANALOG_LDO_0_LDO_PLL_FORCE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_PLL_FORCE_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_PLL_FORCE_MASK)

#define XCVR_ANALOG_LDO_0_LDO_PLL_PTAT_BUMP_MASK (0x60000U)
#define XCVR_ANALOG_LDO_0_LDO_PLL_PTAT_BUMP_SHIFT (17U)
/*! LDO_PLL_PTAT_BUMP - reg_ldo_pll_ptat_bump_dig[1:0]
 *  0b00..nominal
 *  0b01..+30%
 *  0b10..nominal
 *  0b11..+30%
 */
#define XCVR_ANALOG_LDO_0_LDO_PLL_PTAT_BUMP(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_PLL_PTAT_BUMP_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_PLL_PTAT_BUMP_MASK)

#define XCVR_ANALOG_LDO_0_LDO_PLL_BYPASS_MASK    (0x80000U)
#define XCVR_ANALOG_LDO_0_LDO_PLL_BYPASS_SHIFT   (19U)
/*! LDO_PLL_BYPASS - reg_ldo_pll_bypass_dig
 *  0b0..Bypass disabled.
 *  0b1..Bypass enabled
 */
#define XCVR_ANALOG_LDO_0_LDO_PLL_BYPASS(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_PLL_BYPASS_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_PLL_BYPASS_MASK)

#define XCVR_ANALOG_LDO_0_LDO_VCO_FORCE_MASK     (0x100000U)
#define XCVR_ANALOG_LDO_0_LDO_VCO_FORCE_SHIFT    (20U)
/*! LDO_VCO_FORCE - reg_ldo_vco_force_dig
 *  0b0..Force disable
 *  0b1..Force enable
 */
#define XCVR_ANALOG_LDO_0_LDO_VCO_FORCE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_VCO_FORCE_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_VCO_FORCE_MASK)

#define XCVR_ANALOG_LDO_0_LDO_VCO_PTAT_BUMP_MASK (0x600000U)
#define XCVR_ANALOG_LDO_0_LDO_VCO_PTAT_BUMP_SHIFT (21U)
/*! LDO_VCO_PTAT_BUMP - reg_ldo_vco_ptat_bump_dig[1:0]
 *  0b00..nominal
 *  0b01..+30%
 *  0b10..nominal
 *  0b11..+30%
 */
#define XCVR_ANALOG_LDO_0_LDO_VCO_PTAT_BUMP(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_VCO_PTAT_BUMP_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_VCO_PTAT_BUMP_MASK)

#define XCVR_ANALOG_LDO_0_LDO_VCO_BYPASS_MASK    (0x800000U)
#define XCVR_ANALOG_LDO_0_LDO_VCO_BYPASS_SHIFT   (23U)
/*! LDO_VCO_BYPASS - reg_ldo_vco_bypass_dig
 *  0b0..disable VCO bypass
 *  0b1..eable VCO bypass
 */
#define XCVR_ANALOG_LDO_0_LDO_VCO_BYPASS(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_VCO_BYPASS_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_VCO_BYPASS_MASK)

#define XCVR_ANALOG_LDO_0_LDO_CAL_FORCE_MASK     (0x1000000U)
#define XCVR_ANALOG_LDO_0_LDO_CAL_FORCE_SHIFT    (24U)
/*! LDO_CAL_FORCE - reg_ldo_cal_force_dig
 *  0b0..Force disable
 *  0b1..Force enable
 */
#define XCVR_ANALOG_LDO_0_LDO_CAL_FORCE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_CAL_FORCE_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_CAL_FORCE_MASK)

#define XCVR_ANALOG_LDO_0_LDO_CAL_PTAT_BUMP_MASK (0x6000000U)
#define XCVR_ANALOG_LDO_0_LDO_CAL_PTAT_BUMP_SHIFT (25U)
/*! LDO_CAL_PTAT_BUMP - reg_ldo_vco_ptat_bump_dig[1:0]
 *  0b00..nominal
 *  0b01..+30%
 *  0b10..nominal
 *  0b11..+30%
 */
#define XCVR_ANALOG_LDO_0_LDO_CAL_PTAT_BUMP(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_CAL_PTAT_BUMP_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_CAL_PTAT_BUMP_MASK)

#define XCVR_ANALOG_LDO_0_LDO_CAL_BYPASS_MASK    (0x8000000U)
#define XCVR_ANALOG_LDO_0_LDO_CAL_BYPASS_SHIFT   (27U)
/*! LDO_CAL_BYPASS - reg_ldo_cal_bypass_dig
 *  0b0..disable CAL bypass
 *  0b1..eable CAL bypass
 */
#define XCVR_ANALOG_LDO_0_LDO_CAL_BYPASS(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDO_CAL_BYPASS_SHIFT)) & XCVR_ANALOG_LDO_0_LDO_CAL_BYPASS_MASK)

#define XCVR_ANALOG_LDO_0_LDOTRIM_TRIM_VREF_MASK (0x30000000U)
#define XCVR_ANALOG_LDO_0_LDOTRIM_TRIM_VREF_SHIFT (28U)
/*! LDOTRIM_TRIM_VREF - reg_ldotrim_trim_vref_dig[1:0]
 *  0b00..0.810
 *  0b01..0.832
 *  0b10..0.854
 *  0b11..0.788
 */
#define XCVR_ANALOG_LDO_0_LDOTRIM_TRIM_VREF(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_0_LDOTRIM_TRIM_VREF_SHIFT)) & XCVR_ANALOG_LDO_0_LDOTRIM_TRIM_VREF_MASK)
/*! @} */

/*! @name LDO_1 - RF Analog Baseband LDO Control 2 */
/*! @{ */

#define XCVR_ANALOG_LDO_1_LDO_ANT_TRIM_MASK      (0xFU)
#define XCVR_ANALOG_LDO_1_LDO_ANT_TRIM_SHIFT     (0U)
/*! LDO_ANT_TRIM - reg_ldo_ant_trim_dig[3:0]
 *  0b0000..0.91 V ( Default )
 *  0b0001..0.97 V
 *  0b0010..1.04 V
 *  0b0011..1.12 V
 *  0b0100..1.21 V
 *  0b0101..1.32 V
 *  0b0110..1.45 V
 *  0b0111..1.52 V
 *  0b1000..1.61 V
 *  0b1001..1.80 V
 *  0b1010..2.06 V
 *  0b1011..2.13 V
 *  0b1100..2.21 V
 *  0b1101..2.30 V
 *  0b1110..2.39 V
 *  0b1111..2.50 V
 */
#define XCVR_ANALOG_LDO_1_LDO_ANT_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_1_LDO_ANT_TRIM_SHIFT)) & XCVR_ANALOG_LDO_1_LDO_ANT_TRIM_MASK)

#define XCVR_ANALOG_LDO_1_LDO_ANT_POWMOD_SEL_MASK (0x10U)
#define XCVR_ANALOG_LDO_1_LDO_ANT_POWMOD_SEL_SHIFT (4U)
/*! LDO_ANT_POWMOD_SEL - LDO_ANT_POWMOD_SEL
 *  0b0..KW45 Legacy mode
 *  0b1..When pup is low, force HiZ mode
 */
#define XCVR_ANALOG_LDO_1_LDO_ANT_POWMOD_SEL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_1_LDO_ANT_POWMOD_SEL_SHIFT)) & XCVR_ANALOG_LDO_1_LDO_ANT_POWMOD_SEL_MASK)

#define XCVR_ANALOG_LDO_1_LDO_ANT_HIZ_MASK       (0x80U)
#define XCVR_ANALOG_LDO_1_LDO_ANT_HIZ_SHIFT      (7U)
/*! LDO_ANT_HIZ - reg_ldo_ant_hiz_dig
 *  0b0..high-impedance disabled.
 *  0b1..high-impedance enabled
 */
#define XCVR_ANALOG_LDO_1_LDO_ANT_HIZ(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_1_LDO_ANT_HIZ_SHIFT)) & XCVR_ANALOG_LDO_1_LDO_ANT_HIZ_MASK)

#define XCVR_ANALOG_LDO_1_LDO_ANT_BYPASS_MASK    (0x100U)
#define XCVR_ANALOG_LDO_1_LDO_ANT_BYPASS_SHIFT   (8U)
/*! LDO_ANT_BYPASS - reg_ldo_ant_bypass_dig
 *  0b0..ANT bypass disable
 *  0b1..ANT bypass enable
 */
#define XCVR_ANALOG_LDO_1_LDO_ANT_BYPASS(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_1_LDO_ANT_BYPASS_SHIFT)) & XCVR_ANALOG_LDO_1_LDO_ANT_BYPASS_MASK)

#define XCVR_ANALOG_LDO_1_LDO_ANT_REF_SEL_MASK   (0x200U)
#define XCVR_ANALOG_LDO_1_LDO_ANT_REF_SEL_SHIFT  (9U)
/*! LDO_ANT_REF_SEL - reg_ldo_ant_ref_sel_dig
 *  0b0..sel type disable ( Default )
 *  0b1..sel type enable
 */
#define XCVR_ANALOG_LDO_1_LDO_ANT_REF_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_LDO_1_LDO_ANT_REF_SEL_SHIFT)) & XCVR_ANALOG_LDO_1_LDO_ANT_REF_SEL_MASK)
/*! @} */

/*! @name XO_DIST - RF Analog XO DIST Control */
/*! @{ */

#define XCVR_ANALOG_XO_DIST_XO_DIST_TRIM_MASK    (0x3U)
#define XCVR_ANALOG_XO_DIST_XO_DIST_TRIM_SHIFT   (0U)
/*! XO_DIST_TRIM - reg_xo_dist_trim_dig[1:0]
 *  0b00..0.9 V ( Default )
 *  0b01..0.86 V
 *  0b10..0.95 V
 *  0b11..1.21 V
 */
#define XCVR_ANALOG_XO_DIST_XO_DIST_TRIM(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_XO_DIST_XO_DIST_TRIM_SHIFT)) & XCVR_ANALOG_XO_DIST_XO_DIST_TRIM_MASK)

#define XCVR_ANALOG_XO_DIST_XO_DIST_FLIP_MASK    (0x4U)
#define XCVR_ANALOG_XO_DIST_XO_DIST_FLIP_SHIFT   (2U)
/*! XO_DIST_FLIP - reg_xo_dist_flip_dig
 *  0b0..XO DIST doesn't flip the output clock relative to input clock
 *  0b1..XO DIST flip the output clock relative to input clock
 */
#define XCVR_ANALOG_XO_DIST_XO_DIST_FLIP(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_XO_DIST_XO_DIST_FLIP_SHIFT)) & XCVR_ANALOG_XO_DIST_XO_DIST_FLIP_MASK)

#define XCVR_ANALOG_XO_DIST_XO_DIST_BYPASS_MASK  (0x8U)
#define XCVR_ANALOG_XO_DIST_XO_DIST_BYPASS_SHIFT (3U)
/*! XO_DIST_BYPASS - reg_xo_dist_bypass
 *  0b0..XO DIST not bypass
 *  0b1..XO DIST bypass
 */
#define XCVR_ANALOG_XO_DIST_XO_DIST_BYPASS(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_XO_DIST_XO_DIST_BYPASS_SHIFT)) & XCVR_ANALOG_XO_DIST_XO_DIST_BYPASS_MASK)
/*! @} */

/*! @name PLL - RF Analog PLL Control */
/*! @{ */

#define XCVR_ANALOG_PLL_PLL_VCO_TRIM_KVT_MASK    (0x70U)
#define XCVR_ANALOG_PLL_PLL_VCO_TRIM_KVT_SHIFT   (4U)
/*! PLL_VCO_TRIM_KVT - reg_vco_trim_kvt_dig[2:0]
 *  0b000..50MHz/V
 *  0b100..60MHz/V for fref = 32M
 *  0b110..70MHz/V
 *  0b111..80MHz/V for fref = 26M
 */
#define XCVR_ANALOG_PLL_PLL_VCO_TRIM_KVT(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PLL_VCO_TRIM_KVT_SHIFT)) & XCVR_ANALOG_PLL_PLL_VCO_TRIM_KVT_MASK)

#define XCVR_ANALOG_PLL_PLL_VCO_EN_PKDET_MASK    (0x100U)
#define XCVR_ANALOG_PLL_PLL_VCO_EN_PKDET_SHIFT   (8U)
/*! PLL_VCO_EN_PKDET - reg_vco_en_pkdet_dig
 *  0b0..PKDET disable
 *  0b1..PKDET enable
 */
#define XCVR_ANALOG_PLL_PLL_VCO_EN_PKDET(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PLL_VCO_EN_PKDET_SHIFT)) & XCVR_ANALOG_PLL_PLL_VCO_EN_PKDET_MASK)

#define XCVR_ANALOG_PLL_PIC_VREF_CTRL_MASK       (0x600U)
#define XCVR_ANALOG_PLL_PIC_VREF_CTRL_SHIFT      (9U)
/*! PIC_VREF_CTRL - reg_pic_vref_ctrl_dig[1:0]
 *  0b00..VREF=0.268*VDDX (VREF=245 mV for VDDX=0.9 V)
 *  0b01..VREF=0.292*VDDX (VREF=266 mV for VDDX=0.9 V)
 *  0b10..VREF=0.317*VDDX (VREF=287 mV for VDDX=0.9 V)
 *  0b11..VREF=0.341*VDDX (VREF=307 mV for VDDX=0.9 V) - (recommended setting)
 */
#define XCVR_ANALOG_PLL_PIC_VREF_CTRL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PIC_VREF_CTRL_SHIFT)) & XCVR_ANALOG_PLL_PIC_VREF_CTRL_MASK)

#define XCVR_ANALOG_PLL_PIC_SMOOTH_SWITCH_EN_MASK (0x800U)
#define XCVR_ANALOG_PLL_PIC_SMOOTH_SWITCH_EN_SHIFT (11U)
/*! PIC_SMOOTH_SWITCH_EN - reg_pic_smooth_switch_en_dig
 *  0b0..smoothing disable (recommended setting)
 *  0b1..smoothing enable
 */
#define XCVR_ANALOG_PLL_PIC_SMOOTH_SWITCH_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PIC_SMOOTH_SWITCH_EN_SHIFT)) & XCVR_ANALOG_PLL_PIC_SMOOTH_SWITCH_EN_MASK)

#define XCVR_ANALOG_PLL_PLL_VCO_PIC_INPUT_EN_MASK (0x8000U)
#define XCVR_ANALOG_PLL_PLL_VCO_PIC_INPUT_EN_SHIFT (15U)
/*! PLL_VCO_PIC_INPUT_EN - reg_vco_pic_input_en_dig
 *  0b0..PIC_INPUT disable
 *  0b1..PIC_INPUT enable
 */
#define XCVR_ANALOG_PLL_PLL_VCO_PIC_INPUT_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PLL_VCO_PIC_INPUT_EN_SHIFT)) & XCVR_ANALOG_PLL_PLL_VCO_PIC_INPUT_EN_MASK)

#define XCVR_ANALOG_PLL_PIC_RINT1_HVAL_SM_EN_MASK (0x10000U)
#define XCVR_ANALOG_PLL_PIC_RINT1_HVAL_SM_EN_SHIFT (16U)
/*! PIC_RINT1_HVAL_SM_EN - reg_pic_rint1_hval_sm_en_dig
 *  0b0..PIC_RINT1_HVAL_SM disable (Rint1=30 kohms) - (recommended setting)
 *  0b1..PIC_RINT1_HVAL_SM enable (Rint1=60 kohms)
 */
#define XCVR_ANALOG_PLL_PIC_RINT1_HVAL_SM_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PIC_RINT1_HVAL_SM_EN_SHIFT)) & XCVR_ANALOG_PLL_PIC_RINT1_HVAL_SM_EN_MASK)

#define XCVR_ANALOG_PLL_PIC_RINT2_VAL_SLOW_MODE_MASK (0x60000U)
#define XCVR_ANALOG_PLL_PIC_RINT2_VAL_SLOW_MODE_SHIFT (17U)
/*! PIC_RINT2_VAL_SLOW_MODE - reg_pic_rint2_val_slow_mode_dig[1:0]
 *  0b00..Rint2=90 kohms
 *  0b01..Rint2=210 kohms
 *  0b10..Rint2=450 kohms (recommended setting)
 *  0b11..Rint2=450 kohms
 */
#define XCVR_ANALOG_PLL_PIC_RINT2_VAL_SLOW_MODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PIC_RINT2_VAL_SLOW_MODE_SHIFT)) & XCVR_ANALOG_PLL_PIC_RINT2_VAL_SLOW_MODE_MASK)

#define XCVR_ANALOG_PLL_PIC_SPARE_MASK           (0x180000U)
#define XCVR_ANALOG_PLL_PIC_SPARE_SHIFT          (19U)
/*! PIC_SPARE - reg_pic_spare_dig[1:0] */
#define XCVR_ANALOG_PLL_PIC_SPARE(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PIC_SPARE_SHIFT)) & XCVR_ANALOG_PLL_PIC_SPARE_MASK)

#define XCVR_ANALOG_PLL_MUXCREF_DIVN_MASK        (0x200000U)
#define XCVR_ANALOG_PLL_MUXCREF_DIVN_SHIFT       (21U)
/*! MUXCREF_DIVN - reg_muxcref_divn */
#define XCVR_ANALOG_PLL_MUXCREF_DIVN(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_MUXCREF_DIVN_SHIFT)) & XCVR_ANALOG_PLL_MUXCREF_DIVN_MASK)

#define XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLDN_MASK (0x400000U)
#define XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLDN_SHIFT (22U)
/*! PLL_PD_EN_VPD_PULLDN - reg_pd_en_vpd_pulldn_dig
 *  0b0..not pull down vpd output
 *  0b1..pull down vpd output
 */
#define XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLDN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLDN_SHIFT)) & XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLDN_MASK)

#define XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLUP_MASK (0x800000U)
#define XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLUP_SHIFT (23U)
/*! PLL_PD_EN_VPD_PULLUP - reg_pd_en_vpd_pullup_dig
 *  0b0..not pull up vpd output
 *  0b1..pull up vpd output
 */
#define XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLUP(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLUP_SHIFT)) & XCVR_ANALOG_PLL_PLL_PD_EN_VPD_PULLUP_MASK)

#define XCVR_ANALOG_PLL_PLL_PD_TRIM_FCAL_BIAS_MASK (0xC000000U)
#define XCVR_ANALOG_PLL_PLL_PD_TRIM_FCAL_BIAS_SHIFT (26U)
/*! PLL_PD_TRIM_FCAL_BIAS - reg_pd_trim_fcal_bias_dig[1:0]
 *  0b00..0.276V (recommended setting for legacy operation)
 *  0b01..0.164V
 *  0b10..0.320V (recommended setting for PIC use)
 *  0b11..0.391V
 */
#define XCVR_ANALOG_PLL_PLL_PD_TRIM_FCAL_BIAS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PLL_PD_TRIM_FCAL_BIAS_SHIFT)) & XCVR_ANALOG_PLL_PLL_PD_TRIM_FCAL_BIAS_MASK)

#define XCVR_ANALOG_PLL_LODIV_SYNC_SPARE_MASK    (0x30000000U)
#define XCVR_ANALOG_PLL_LODIV_SYNC_SPARE_SHIFT   (28U)
/*! LODIV_SYNC_SPARE - reg_lodiv_sync_spare_dig[1:0] */
#define XCVR_ANALOG_PLL_LODIV_SYNC_SPARE(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_LODIV_SYNC_SPARE_SHIFT)) & XCVR_ANALOG_PLL_LODIV_SYNC_SPARE_MASK)

#define XCVR_ANALOG_PLL_PLL_FCAL_EN_STATIC_RES_MASK (0x80000000U)
#define XCVR_ANALOG_PLL_PLL_FCAL_EN_STATIC_RES_SHIFT (31U)
/*! PLL_FCAL_EN_STATIC_RES - reg_fcal_en_static_res_dig
 *  0b0..resistor is dynamically switched during FCAL operation
 *  0b1..resistor is always on during FCAL operation
 */
#define XCVR_ANALOG_PLL_PLL_FCAL_EN_STATIC_RES(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_PLL_PLL_FCAL_EN_STATIC_RES_SHIFT)) & XCVR_ANALOG_PLL_PLL_FCAL_EN_STATIC_RES_MASK)
/*! @} */

/*! @name RX_0 - RF Analog RX Control0 */
/*! @{ */

#define XCVR_ANALOG_RX_0_RX_LNA_ITRIM_MASK       (0x3U)
#define XCVR_ANALOG_RX_0_RX_LNA_ITRIM_SHIFT      (0U)
/*! RX_LNA_ITRIM - reg_rx_lna_itrim_dig[1:0]
 *  0b00..3.7u -25%
 *  0b01..4.4u -15%
 *  0b10..5.1u Default
 *  0b11..5.6u +10%
 */
#define XCVR_ANALOG_RX_0_RX_LNA_ITRIM(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_0_RX_LNA_ITRIM_SHIFT)) & XCVR_ANALOG_RX_0_RX_LNA_ITRIM_MASK)

#define XCVR_ANALOG_RX_0_RX_LNA_PTAT_FORCE_START_MASK (0x1000U)
#define XCVR_ANALOG_RX_0_RX_LNA_PTAT_FORCE_START_SHIFT (12U)
/*! RX_LNA_PTAT_FORCE_START - reg_rtfe_ptat_force_dig */
#define XCVR_ANALOG_RX_0_RX_LNA_PTAT_FORCE_START(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_0_RX_LNA_PTAT_FORCE_START_SHIFT)) & XCVR_ANALOG_RX_0_RX_LNA_PTAT_FORCE_START_MASK)

#define XCVR_ANALOG_RX_0_RX_MIX_VBIAS_MASK       (0x300000U)
#define XCVR_ANALOG_RX_0_RX_MIX_VBIAS_SHIFT      (20U)
/*! RX_MIX_VBIAS - reg_rx_mix_vbias_dig[1:0]
 *  0b00..0.800V
 *  0b01..0.742V
 *  0b10..0.689V
 *  0b11..0.857V
 */
#define XCVR_ANALOG_RX_0_RX_MIX_VBIAS(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_0_RX_MIX_VBIAS_SHIFT)) & XCVR_ANALOG_RX_0_RX_MIX_VBIAS_MASK)

#define XCVR_ANALOG_RX_0_ADC_TRIM_MASK           (0x3000000U)
#define XCVR_ANALOG_RX_0_ADC_TRIM_SHIFT          (24U)
/*! ADC_TRIM - reg_adc_trim_dig[1:0]
 *  0b00..0.965V
 *  0b01..0.935V
 *  0b10..0.905V
 *  0b11..0.875V
 */
#define XCVR_ANALOG_RX_0_ADC_TRIM(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_0_ADC_TRIM_SHIFT)) & XCVR_ANALOG_RX_0_ADC_TRIM_MASK)

#define XCVR_ANALOG_RX_0_ADC_INVERT_CLK_MASK     (0x8000000U)
#define XCVR_ANALOG_RX_0_ADC_INVERT_CLK_SHIFT    (27U)
/*! ADC_INVERT_CLK - reg_adc_invert_clk_dig
 *  0b0..not invert clk
 *  0b1..invert clk
 */
#define XCVR_ANALOG_RX_0_ADC_INVERT_CLK(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_0_ADC_INVERT_CLK_SHIFT)) & XCVR_ANALOG_RX_0_ADC_INVERT_CLK_MASK)
/*! @} */

/*! @name RX_1 - RF Analog RX Control1 */
/*! @{ */

#define XCVR_ANALOG_RX_1_CBPF_TYPE_MASK          (0x8U)
#define XCVR_ANALOG_RX_1_CBPF_TYPE_SHIFT         (3U)
/*! CBPF_TYPE - reg_cbpf_type_dig
 *  0b0..Real
 *  0b1..Complex,
 */
#define XCVR_ANALOG_RX_1_CBPF_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_1_CBPF_TYPE_SHIFT)) & XCVR_ANALOG_RX_1_CBPF_TYPE_MASK)

#define XCVR_ANALOG_RX_1_CBPF_TRIM_I_MASK        (0x30U)
#define XCVR_ANALOG_RX_1_CBPF_TRIM_I_SHIFT       (4U)
/*! CBPF_TRIM_I - reg_cbpf_trim_i_dig[1:0]
 *  0b00..5u (Default)
 *  0b01..6.25u
 *  0b10..7.5u
 *  0b11..8.75u
 */
#define XCVR_ANALOG_RX_1_CBPF_TRIM_I(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_1_CBPF_TRIM_I_SHIFT)) & XCVR_ANALOG_RX_1_CBPF_TRIM_I_MASK)

#define XCVR_ANALOG_RX_1_CBPF_TRIM_Q_MASK        (0x300U)
#define XCVR_ANALOG_RX_1_CBPF_TRIM_Q_SHIFT       (8U)
/*! CBPF_TRIM_Q - reg_cbpf_trim_q_dig[1:0]
 *  0b00..5u (Default)
 *  0b01..6.25u
 *  0b10..7.5u
 *  0b11..8.75u
 */
#define XCVR_ANALOG_RX_1_CBPF_TRIM_Q(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_1_CBPF_TRIM_Q_SHIFT)) & XCVR_ANALOG_RX_1_CBPF_TRIM_Q_MASK)

#define XCVR_ANALOG_RX_1_CBPF_VCM_TRIM_MASK      (0x3000U)
#define XCVR_ANALOG_RX_1_CBPF_VCM_TRIM_SHIFT     (12U)
/*! CBPF_VCM_TRIM - reg_cbpf_vcm_trim_dig[1:0]
 *  0b00..480mV
 *  0b01..453mV
 *  0b10..426mV
 *  0b11..401mV
 */
#define XCVR_ANALOG_RX_1_CBPF_VCM_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_1_CBPF_VCM_TRIM_SHIFT)) & XCVR_ANALOG_RX_1_CBPF_VCM_TRIM_MASK)

#define XCVR_ANALOG_RX_1_CBPF_TRIM_SHORT_DCBIAS_MASK (0x30000U)
#define XCVR_ANALOG_RX_1_CBPF_TRIM_SHORT_DCBIAS_SHIFT (16U)
/*! CBPF_TRIM_SHORT_DCBIAS - reg_cbpf_trim_short_dcbias_dig[1:0]
 *  0b00..470mV
 *  0b01..438mV
 *  0b10..413mV
 *  0b11..385mV
 */
#define XCVR_ANALOG_RX_1_CBPF_TRIM_SHORT_DCBIAS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_1_CBPF_TRIM_SHORT_DCBIAS_SHIFT)) & XCVR_ANALOG_RX_1_CBPF_TRIM_SHORT_DCBIAS_MASK)
/*! @} */

/*! @name TX_DAC_PA - RF Analog TX DAC PA Control */
/*! @{ */

#define XCVR_ANALOG_TX_DAC_PA_DAC_INVERT_CLK_MASK (0x8U)
#define XCVR_ANALOG_TX_DAC_PA_DAC_INVERT_CLK_SHIFT (3U)
/*! DAC_INVERT_CLK - reg_dac_invert_clk_dig */
#define XCVR_ANALOG_TX_DAC_PA_DAC_INVERT_CLK(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_DAC_INVERT_CLK_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_DAC_INVERT_CLK_MASK)

#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_RLOAD_MASK (0x300U)
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_RLOAD_SHIFT (8U)
/*! DAC_TRIM_RLOAD - reg_dac_trim_rload_dig[1:0]
 *  0b00..3K
 *  0b01..2.25K
 *  0b10..3.75K
 *  0b11..4.5K
 */
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_RLOAD(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_RLOAD_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_RLOAD_MASK)

#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_IBIAS_MASK (0xC00U)
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_IBIAS_SHIFT (10U)
/*! DAC_TRIM_IBIAS - reg_dac_trim_ibias_dig[1:0]
 *  0b00..3.0uA (I_lsb=250nA)
 *  0b01..2.5uA
 *  0b10..3.8uA
 *  0b11..5.0uA
 */
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_IBIAS(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_IBIAS_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_IBIAS_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_PA_VBIAS_MASK   (0x30000U)
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_VBIAS_SHIFT  (16U)
/*! TX_PA_VBIAS - reg_tx_pa_vbias_dig[1:0]
 *  0b00..0.460V
 *  0b01..0.431V
 *  0b10..0.403V
 *  0b11..0.375V
 */
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_VBIAS(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_PA_VBIAS_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_PA_VBIAS_MASK)

#define XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_EN_MASK (0x40000U)
#define XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_EN_SHIFT (18U)
/*! PA_SMOOTHER_EN - reg_pa_smoother_en_dig
 *  0b0..PA_SMOOTHER disable
 *  0b1..PA_SMOOTHER enable
 */
#define XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_EN_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_EN_MASK)

#define XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_CUR_MASK (0x380000U)
#define XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_CUR_SHIFT (19U)
/*! PA_SMOOTHER_CUR - reg_pa_smoother_cur_dig[2:0] */
#define XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_CUR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_CUR_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_PA_SMOOTHER_CUR_MASK)

#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_MASK (0x3000000U)
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_SHIFT (24U)
/*! DAC_TRIM_CFBK - reg_dac_trim_cfbk_dig[1:0]
 *  0b00..675fF
 *  0b01..1.35pF
 *  0b10..1.35pF
 *  0b11..2.025pF
 */
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_MASK)

#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_DRS_MASK (0xC000000U)
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_DRS_SHIFT (26U)
/*! DAC_TRIM_CFBK_DRS - reg_dac_trim_cfbk_dig[1:0]
 *  0b00..675fF
 *  0b01..1.35pF
 *  0b10..1.35pF
 *  0b11..2.025pF
 */
#define XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_DRS_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_DAC_TRIM_CFBK_DRS_MASK)
/*! @} */

/*! @name DIAG - RF Analog DIAG Control 1 */
/*! @{ */

#define XCVR_ANALOG_DIAG_DIAG_CODE_MASK          (0x7U)
#define XCVR_ANALOG_DIAG_DIAG_CODE_SHIFT         (0U)
/*! DIAG_CODE - reg_diag_code_dig[2:0] */
#define XCVR_ANALOG_DIAG_DIAG_CODE(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_DIAG_CODE_SHIFT)) & XCVR_ANALOG_DIAG_DIAG_CODE_MASK)

#define XCVR_ANALOG_DIAG_LDO_CAL_DIAG_SEL_MASK   (0x8U)
#define XCVR_ANALOG_DIAG_LDO_CAL_DIAG_SEL_SHIFT  (3U)
/*! LDO_CAL_DIAG_SEL - reg_ldo_cal_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDO_CAL_DIAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDO_CAL_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDO_CAL_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_LDO_VCO_DIAG_SEL_MASK   (0x10U)
#define XCVR_ANALOG_DIAG_LDO_VCO_DIAG_SEL_SHIFT  (4U)
/*! LDO_VCO_DIAG_SEL - reg_ldo_vco_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDO_VCO_DIAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDO_VCO_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDO_VCO_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_LDO_PLL_DIAG_SEL_MASK   (0x20U)
#define XCVR_ANALOG_DIAG_LDO_PLL_DIAG_SEL_SHIFT  (5U)
/*! LDO_PLL_DIAG_SEL - reg_ldo_pll_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDO_PLL_DIAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDO_PLL_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDO_PLL_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_LDO_RXTXLF_DIAG_SEL_MASK (0x100U)
#define XCVR_ANALOG_DIAG_LDO_RXTXLF_DIAG_SEL_SHIFT (8U)
/*! LDO_RXTXLF_DIAG_SEL - reg_ldo_rxtxlf_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDO_RXTXLF_DIAG_SEL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDO_RXTXLF_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDO_RXTXLF_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_LDO_RXTXHF_DIAG_SEL_MASK (0x200U)
#define XCVR_ANALOG_DIAG_LDO_RXTXHF_DIAG_SEL_SHIFT (9U)
/*! LDO_RXTXHF_DIAG_SEL - reg_ldo_rxtxhf_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDO_RXTXHF_DIAG_SEL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDO_RXTXHF_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDO_RXTXHF_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_LDO_LV_DIAG_SEL_MASK    (0x400U)
#define XCVR_ANALOG_DIAG_LDO_LV_DIAG_SEL_SHIFT   (10U)
/*! LDO_LV_DIAG_SEL - reg_ldo_lv_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDO_LV_DIAG_SEL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDO_LV_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDO_LV_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_BG_DIAG_SEL_MASK        (0x800U)
#define XCVR_ANALOG_DIAG_BG_DIAG_SEL_SHIFT       (11U)
/*! BG_DIAG_SEL - reg_bg_diag_sel_dig */
#define XCVR_ANALOG_DIAG_BG_DIAG_SEL(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_BG_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_BG_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_LDOTRIM_DIAG_SEL_MASK   (0x1000U)
#define XCVR_ANALOG_DIAG_LDOTRIM_DIAG_SEL_SHIFT  (12U)
/*! LDOTRIM_DIAG_SEL - reg_ldotrim_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDOTRIM_DIAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDOTRIM_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDOTRIM_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_PROC_MON_DIAG_SEL_MASK  (0x2000U)
#define XCVR_ANALOG_DIAG_PROC_MON_DIAG_SEL_SHIFT (13U)
/*! PROC_MON_DIAG_SEL - reg_proc_mon_diag_sel_dig */
#define XCVR_ANALOG_DIAG_PROC_MON_DIAG_SEL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_PROC_MON_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_PROC_MON_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_RTFE_DIAG_SEL_MASK      (0x8000U)
#define XCVR_ANALOG_DIAG_RTFE_DIAG_SEL_SHIFT     (15U)
/*! RTFE_DIAG_SEL - reg_rtfe_diag_sel_dig */
#define XCVR_ANALOG_DIAG_RTFE_DIAG_SEL(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_RTFE_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_RTFE_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_1_MASK  (0x10000U)
#define XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_1_SHIFT (16U)
/*! CBPF_I_DIAG_SEL_1 - reg_cbpf_i_diag_sel_1_dig */
#define XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_1(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_1_SHIFT)) & XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_1_MASK)

#define XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_2_MASK  (0x20000U)
#define XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_2_SHIFT (17U)
/*! CBPF_I_DIAG_SEL_2 - reg_cbpf_i_diag_sel_2_dig */
#define XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_2(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_2_SHIFT)) & XCVR_ANALOG_DIAG_CBPF_I_DIAG_SEL_2_MASK)

#define XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_1_MASK  (0x40000U)
#define XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_1_SHIFT (18U)
/*! CBPF_Q_DIAG_SEL_1 - reg_cbpf_q_diag_sel_1_dig */
#define XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_1(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_1_SHIFT)) & XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_1_MASK)

#define XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_2_MASK  (0x80000U)
#define XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_2_SHIFT (19U)
/*! CBPF_Q_DIAG_SEL_2 - reg_cbpf_q_diag_sel_2_dig */
#define XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_2(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_2_SHIFT)) & XCVR_ANALOG_DIAG_CBPF_Q_DIAG_SEL_2_MASK)

#define XCVR_ANALOG_DIAG_CBPF_EN_DIAG_MEAS_MASK  (0x100000U)
#define XCVR_ANALOG_DIAG_CBPF_EN_DIAG_MEAS_SHIFT (20U)
/*! CBPF_EN_DIAG_MEAS - reg_cbpf_en_diag_meas_dig */
#define XCVR_ANALOG_DIAG_CBPF_EN_DIAG_MEAS(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_CBPF_EN_DIAG_MEAS_SHIFT)) & XCVR_ANALOG_DIAG_CBPF_EN_DIAG_MEAS_MASK)

#define XCVR_ANALOG_DIAG_ADC_DIAG_SEL_MASK       (0x200000U)
#define XCVR_ANALOG_DIAG_ADC_DIAG_SEL_SHIFT      (21U)
/*! ADC_DIAG_SEL - reg_adc_diag_sel_dig */
#define XCVR_ANALOG_DIAG_ADC_DIAG_SEL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_ADC_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_ADC_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_PD_DIAG_SEL_MASK        (0x800000U)
#define XCVR_ANALOG_DIAG_PD_DIAG_SEL_SHIFT       (23U)
/*! PD_DIAG_SEL - reg_pd_diag_sel_dig */
#define XCVR_ANALOG_DIAG_PD_DIAG_SEL(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_PD_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_PD_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_VCO_DIAG_SEL_MASK       (0x1000000U)
#define XCVR_ANALOG_DIAG_VCO_DIAG_SEL_SHIFT      (24U)
/*! VCO_DIAG_SEL - reg_vco_diag_sel_dig */
#define XCVR_ANALOG_DIAG_VCO_DIAG_SEL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_VCO_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_VCO_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_DAC_DIAG_SEL_MASK       (0x2000000U)
#define XCVR_ANALOG_DIAG_DAC_DIAG_SEL_SHIFT      (25U)
/*! DAC_DIAG_SEL - reg_dac_diag_sel_dig */
#define XCVR_ANALOG_DIAG_DAC_DIAG_SEL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_DAC_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_DAC_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_PIC_DIAG_SEL_MASK       (0x4000000U)
#define XCVR_ANALOG_DIAG_PIC_DIAG_SEL_SHIFT      (26U)
/*! PIC_DIAG_SEL - reg_pic_diag_sel_dig */
#define XCVR_ANALOG_DIAG_PIC_DIAG_SEL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_PIC_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_PIC_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_XO_DIST_DIAG_SEL_MASK   (0x8000000U)
#define XCVR_ANALOG_DIAG_XO_DIST_DIAG_SEL_SHIFT  (27U)
/*! XO_DIST_DIAG_SEL - reg_xo_dist_diag_sel_dig */
#define XCVR_ANALOG_DIAG_XO_DIST_DIAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_XO_DIST_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_XO_DIST_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_LDO_ANT_DIAG_SEL_MASK   (0x10000000U)
#define XCVR_ANALOG_DIAG_LDO_ANT_DIAG_SEL_SHIFT  (28U)
/*! LDO_ANT_DIAG_SEL - reg_ldo_ant_diag_sel_dig */
#define XCVR_ANALOG_DIAG_LDO_ANT_DIAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_LDO_ANT_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_LDO_ANT_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_DAC_AMP_DIAG_SEL_MASK   (0x20000000U)
#define XCVR_ANALOG_DIAG_DAC_AMP_DIAG_SEL_SHIFT  (29U)
/*! DAC_AMP_DIAG_SEL - reg_dac_amp_diag_sel_dig */
#define XCVR_ANALOG_DIAG_DAC_AMP_DIAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_DAC_AMP_DIAG_SEL_SHIFT)) & XCVR_ANALOG_DIAG_DAC_AMP_DIAG_SEL_MASK)

#define XCVR_ANALOG_DIAG_DIAG_DIS_MASK           (0x40000000U)
#define XCVR_ANALOG_DIAG_DIAG_DIS_SHIFT          (30U)
/*! DIAG_DIS - reg_diag_dis_dig */
#define XCVR_ANALOG_DIAG_DIAG_DIS(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_DIAG_DIS_SHIFT)) & XCVR_ANALOG_DIAG_DIAG_DIS_MASK)

#define XCVR_ANALOG_DIAG_ATX_ON_2P4GHZ_MASK      (0x80000000U)
#define XCVR_ANALOG_DIAG_ATX_ON_2P4GHZ_SHIFT     (31U)
/*! ATX_ON_2P4GHZ - reg_2p4ghz_atx_on_dig */
#define XCVR_ANALOG_DIAG_ATX_ON_2P4GHZ(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DIAG_ATX_ON_2P4GHZ_SHIFT)) & XCVR_ANALOG_DIAG_ATX_ON_2P4GHZ_MASK)
/*! @} */

/*! @name SPARE - RF Analog SPARE Control */
/*! @{ */

#define XCVR_ANALOG_SPARE_SPARELV_MASK           (0xFU)
#define XCVR_ANALOG_SPARE_SPARELV_SHIFT          (0U)
/*! SPARELV - reg_sparelv_dig[3:0] */
#define XCVR_ANALOG_SPARE_SPARELV(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SPARE_SPARELV_SHIFT)) & XCVR_ANALOG_SPARE_SPARELV_MASK)

#define XCVR_ANALOG_SPARE_SPARE_DIAG_SEL_MASK    (0x3000U)
#define XCVR_ANALOG_SPARE_SPARE_DIAG_SEL_SHIFT   (12U)
/*! SPARE_DIAG_SEL - reg_spare_diag_sel_dig[1:0] */
#define XCVR_ANALOG_SPARE_SPARE_DIAG_SEL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SPARE_SPARE_DIAG_SEL_SHIFT)) & XCVR_ANALOG_SPARE_SPARE_DIAG_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_ANALOG_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_ANALOG_Peripheral_Access_Layer */


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


#endif  /* PERI_XCVR_ANALOG_H_ */

