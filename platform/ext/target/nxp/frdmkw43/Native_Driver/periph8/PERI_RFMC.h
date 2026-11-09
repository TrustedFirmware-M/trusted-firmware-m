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
**         CMSIS Peripheral Access Layer for RFMC
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
 * @file PERI_RFMC.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for RFMC
 *
 * CMSIS Peripheral Access Layer for RFMC
 */

#if !defined(PERI_RFMC_H_)
#define PERI_RFMC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- RFMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFMC_Peripheral_Access_Layer RFMC Peripheral Access Layer
 * @{
 */

/** RFMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< RFMC Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< RFMC Parameter Register, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< RFMC Control Register, offset: 0x8 */
  __IO uint32_t XO_CTRL;                           /**< XO Control Register, offset: 0xC */
  __IO uint32_t XO_STAT;                           /**< XO Status Register, offset: 0x10 */
  __IO uint32_t XO_TEST;                           /**< XO Test Register, offset: 0x14 */
  __IO uint32_t RF2P4GHZ_CTRL;                     /**< 2.4GHz Radio Control Register, offset: 0x18 */
  __IO uint32_t RF2P4GHZ_STAT;                     /**< 2.4GHz Radio Status Register, offset: 0x1C */
  __IO uint32_t RF2P4GHZ_COEXT;                    /**< 2.4GHz Radio Coexistence Register, offset: 0x20 */
  __IO uint32_t RF2P4GHZ_TIMER;                    /**< 2.4GHz TIMER Register, offset: 0x24 */
  __I  uint32_t RF2P4GHZ_WOR1;                     /**< 2.4GHz WOR Register 1, offset: 0x28 */
  __IO uint32_t RF2P4GHZ_WOR2;                     /**< 2.4GHz WOR Register 2, offset: 0x2C */
  __I  uint32_t RF2P4GHZ_MAN1;                     /**< 2.4GHz MAN Register 1, offset: 0x30 */
  __IO uint32_t RF2P4GHZ_MAN2;                     /**< 2.4GHz MAN Register 2, offset: 0x34 */
  __I  uint32_t RF2P4GHZ_MAN3;                     /**< 2.4GHz MAN Register 3, offset: 0x38 */
  __I  uint32_t RF2P4GHZ_MAN4;                     /**< 2.4GHz MAN Register 4, offset: 0x3C */
       uint8_t RESERVED_0[8];
  __IO uint32_t RF2P4GHZ_HOST2RADIO;               /**< RF 2.4GHz Buffer from Host to Radio, offset: 0x48 */
  __I  uint32_t RF2P4GHZ_RADIO2HOST;               /**< RF 2.4GHz Buffer from Radio to Host, offset: 0x4C */
  __IO uint32_t RF2P4GHZ_CFG;                      /**< 2.4GHz Radio Configuration Register, offset: 0x50 */
  __I  uint32_t RF2P4GHZ_WKUP_SRC;                 /**< 2.4GHz Radio WakeUp Source Register, offset: 0x54 */
} RFMC_Type;

/* ----------------------------------------------------------------------------
   -- RFMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFMC_Register_Masks RFMC Register Masks
 * @{
 */

/*! @name VERID - RFMC Version ID Register */
/*! @{ */

#define RFMC_VERID_RADIO_ID_MASK                 (0xFFFFU)
#define RFMC_VERID_RADIO_ID_SHIFT                (0U)
/*! RADIO_ID - Radio Identification Number */
#define RFMC_VERID_RADIO_ID(x)                   (((uint32_t)(((uint32_t)(x)) << RFMC_VERID_RADIO_ID_SHIFT)) & RFMC_VERID_RADIO_ID_MASK)

#define RFMC_VERID_MINOR_MASK                    (0xFF0000U)
#define RFMC_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor RFMC Version Number */
#define RFMC_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << RFMC_VERID_MINOR_SHIFT)) & RFMC_VERID_MINOR_MASK)

#define RFMC_VERID_MAJOR_MASK                    (0xFF000000U)
#define RFMC_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major RFMC Version Number */
#define RFMC_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << RFMC_VERID_MAJOR_SHIFT)) & RFMC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - RFMC Parameter Register */
/*! @{ */

#define RFMC_PARAM_RF2p4GHz_EN_MASK              (0x1U)
#define RFMC_PARAM_RF2p4GHz_EN_SHIFT             (0U)
/*! RF2p4GHz_EN
 *  0b0..2.4GHz radio disabled
 *  0b1..2.4GHz radio enabled
 */
#define RFMC_PARAM_RF2p4GHz_EN(x)                (((uint32_t)(((uint32_t)(x)) << RFMC_PARAM_RF2p4GHz_EN_SHIFT)) & RFMC_PARAM_RF2p4GHz_EN_MASK)
/*! @} */

/*! @name CTRL - RFMC Control Register */
/*! @{ */

#define RFMC_CTRL_RFMC_RST_MASK                  (0x80000000U)
#define RFMC_CTRL_RFMC_RST_SHIFT                 (31U)
/*! RFMC_RST - S/W System Reset for RFMC
 *  0b0..Release the RFMC from reset
 *  0b1..Hold the RFMC in reset
 */
#define RFMC_CTRL_RFMC_RST(x)                    (((uint32_t)(((uint32_t)(x)) << RFMC_CTRL_RFMC_RST_SHIFT)) & RFMC_CTRL_RFMC_RST_MASK)
/*! @} */

/*! @name XO_CTRL - XO Control Register */
/*! @{ */

#define RFMC_XO_CTRL_RDY_IE_MASK                 (0x1U)
#define RFMC_XO_CTRL_RDY_IE_SHIFT                (0U)
/*! RDY_IE - XTAL Ready Interrupt Enable
 *  0b0..XTAL ready interrupt disabled
 *  0b1..XTAL ready interrupt enabled
 */
#define RFMC_XO_CTRL_RDY_IE(x)                   (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_RDY_IE_SHIFT)) & RFMC_XO_CTRL_RDY_IE_MASK)

#define RFMC_XO_CTRL_INT_IE_MASK                 (0x2U)
#define RFMC_XO_CTRL_INT_IE_SHIFT                (1U)
/*! INT_IE - XO Internal Request Interrupt Enable
 *  0b0..XO internal request interrupt disabled
 *  0b1..XO internal request interrupt enabled
 */
#define RFMC_XO_CTRL_INT_IE(x)                   (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_INT_IE_SHIFT)) & RFMC_XO_CTRL_INT_IE_MASK)

#define RFMC_XO_CTRL_EXT_IE_MASK                 (0x4U)
#define RFMC_XO_CTRL_EXT_IE_SHIFT                (2U)
/*! EXT_IE - XO External Request Interrupt Enable
 *  0b0..XO external request interrupt disabled
 *  0b1..XO external request interrupt enabled
 */
#define RFMC_XO_CTRL_EXT_IE(x)                   (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_EXT_IE_SHIFT)) & RFMC_XO_CTRL_EXT_IE_MASK)

#define RFMC_XO_CTRL_XTAL_OUT_EN_MASK            (0x10U)
#define RFMC_XO_CTRL_XTAL_OUT_EN_SHIFT           (4U)
/*! XTAL_OUT_EN - XTAL_OUT Output Pin Enable
 *  0b0..XTAL_OUT output disabled
 *  0b1..XTAL_OUT output enabled
 */
#define RFMC_XO_CTRL_XTAL_OUT_EN(x)              (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XTAL_OUT_EN_SHIFT)) & RFMC_XO_CTRL_XTAL_OUT_EN_MASK)

#define RFMC_XO_CTRL_XTAL_REQ_OBE_MASK           (0x20U)
#define RFMC_XO_CTRL_XTAL_REQ_OBE_SHIFT          (5U)
/*! XTAL_REQ_OBE - XTAL_REQ Output Pin Enable
 *  0b0..XTAL_REQ output pin disabled
 *  0b1..XTAL_REQ output pin enabled
 */
#define RFMC_XO_CTRL_XTAL_REQ_OBE(x)             (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XTAL_REQ_OBE_SHIFT)) & RFMC_XO_CTRL_XTAL_REQ_OBE_MASK)

#define RFMC_XO_CTRL_XTAL_EN_IBE_MASK            (0x40U)
#define RFMC_XO_CTRL_XTAL_EN_IBE_SHIFT           (6U)
/*! XTAL_EN_IBE - XTAL_OUT_EN Input Pin Enable
 *  0b0..XTAL_OUT_EN input pin disabled
 *  0b1..XTAL_OUT_EN input pin enabled
 */
#define RFMC_XO_CTRL_XTAL_EN_IBE(x)              (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XTAL_EN_IBE_SHIFT)) & RFMC_XO_CTRL_XTAL_EN_IBE_MASK)

#define RFMC_XO_CTRL_WKUP_OFFSET_MASK            (0x3F00U)
#define RFMC_XO_CTRL_WKUP_OFFSET_SHIFT           (8U)
/*! WKUP_OFFSET - XO Wakeup Offset */
#define RFMC_XO_CTRL_WKUP_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_WKUP_OFFSET_SHIFT)) & RFMC_XO_CTRL_WKUP_OFFSET_MASK)

#define RFMC_XO_CTRL_RDY_CNT_MASK                (0x30000U)
#define RFMC_XO_CTRL_RDY_CNT_SHIFT               (16U)
/*! RDY_CNT - XTAL Ready Count
 *  0b00..1024
 *  0b01..2048
 *  0b10..4096
 *  0b11..8192
 */
#define RFMC_XO_CTRL_RDY_CNT(x)                  (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_RDY_CNT_SHIFT)) & RFMC_XO_CTRL_RDY_CNT_MASK)

#define RFMC_XO_CTRL_RDY_CNT_OFF_MASK            (0x40000U)
#define RFMC_XO_CTRL_RDY_CNT_OFF_SHIFT           (18U)
/*! RDY_CNT_OFF - XTAL Ready Count Disable
 *  0b0..XTAL Ready Count Enabled
 *  0b1..XTAL Ready Count Disabled
 */
#define RFMC_XO_CTRL_RDY_CNT_OFF(x)              (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_RDY_CNT_OFF_SHIFT)) & RFMC_XO_CTRL_RDY_CNT_OFF_MASK)

#define RFMC_XO_CTRL_XTAL_OUT_INV_MASK           (0x80000U)
#define RFMC_XO_CTRL_XTAL_OUT_INV_SHIFT          (19U)
/*! XTAL_OUT_INV - XO Clock Output Invert
 *  0b0..XTAL_OUT not inverted
 *  0b1..XTAL_OUT inverted
 */
#define RFMC_XO_CTRL_XTAL_OUT_INV(x)             (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XTAL_OUT_INV_SHIFT)) & RFMC_XO_CTRL_XTAL_OUT_INV_MASK)

#define RFMC_XO_CTRL_LDO_BYPASS_MASK             (0x100000U)
#define RFMC_XO_CTRL_LDO_BYPASS_SHIFT            (20U)
/*! LDO_BYPASS - XO LDO Bypass */
#define RFMC_XO_CTRL_LDO_BYPASS(x)               (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_LDO_BYPASS_SHIFT)) & RFMC_XO_CTRL_LDO_BYPASS_MASK)

#define RFMC_XO_CTRL_EXT_MODE_MASK               (0x200000U)
#define RFMC_XO_CTRL_EXT_MODE_SHIFT              (21U)
/*! EXT_MODE - External Clock Mode
 *  0b0..DC coupled external clock mode (amplifier powered down).
 *  0b1..AC coupled external clock mode or crystal mode (amplifier powered up).
 */
#define RFMC_XO_CTRL_EXT_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_EXT_MODE_SHIFT)) & RFMC_XO_CTRL_EXT_MODE_MASK)

#define RFMC_XO_CTRL_XTAL_RDY_OVR_EN_MASK        (0x400000U)
#define RFMC_XO_CTRL_XTAL_RDY_OVR_EN_SHIFT       (22U)
/*! XTAL_RDY_OVR_EN - XTAL Ready Override Enable */
#define RFMC_XO_CTRL_XTAL_RDY_OVR_EN(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XTAL_RDY_OVR_EN_SHIFT)) & RFMC_XO_CTRL_XTAL_RDY_OVR_EN_MASK)

#define RFMC_XO_CTRL_XTAL_RDY_OVR_MASK           (0x800000U)
#define RFMC_XO_CTRL_XTAL_RDY_OVR_SHIFT          (23U)
/*! XTAL_RDY_OVR - XTAL Ready Override */
#define RFMC_XO_CTRL_XTAL_RDY_OVR(x)             (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XTAL_RDY_OVR_SHIFT)) & RFMC_XO_CTRL_XTAL_RDY_OVR_MASK)

#define RFMC_XO_CTRL_SPARE_MASK                  (0xF000000U)
#define RFMC_XO_CTRL_SPARE_SHIFT                 (24U)
/*! SPARE - XO Spare Registers */
#define RFMC_XO_CTRL_SPARE(x)                    (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_SPARE_SHIFT)) & RFMC_XO_CTRL_SPARE_MASK)

#define RFMC_XO_CTRL_XO_LDO_OVR_MASK             (0x10000000U)
#define RFMC_XO_CTRL_XO_LDO_OVR_SHIFT            (28U)
/*! XO_LDO_OVR - XO LDO Enable Override
 *  0b0..XO LDO enable not overridden
 *  0b1..XO LDO enable overridden by XO_LDO_EN bit
 */
#define RFMC_XO_CTRL_XO_LDO_OVR(x)               (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XO_LDO_OVR_SHIFT)) & RFMC_XO_CTRL_XO_LDO_OVR_MASK)

#define RFMC_XO_CTRL_XO_LDO_EN_MASK              (0x20000000U)
#define RFMC_XO_CTRL_XO_LDO_EN_SHIFT             (29U)
/*! XO_LDO_EN - XO LDO Enable
 *  0b0..XO LDO disabled
 *  0b1..XO LDO enabled
 */
#define RFMC_XO_CTRL_XO_LDO_EN(x)                (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XO_LDO_EN_SHIFT)) & RFMC_XO_CTRL_XO_LDO_EN_MASK)

#define RFMC_XO_CTRL_XO_ANA_OVR_MASK             (0x40000000U)
#define RFMC_XO_CTRL_XO_ANA_OVR_SHIFT            (30U)
/*! XO_ANA_OVR - XO Analog Enable Override
 *  0b0..XO analog enable not overridden
 *  0b1..XO analog enable overridden by XO_ANA_EN bit
 */
#define RFMC_XO_CTRL_XO_ANA_OVR(x)               (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XO_ANA_OVR_SHIFT)) & RFMC_XO_CTRL_XO_ANA_OVR_MASK)

#define RFMC_XO_CTRL_XO_ANA_EN_MASK              (0x80000000U)
#define RFMC_XO_CTRL_XO_ANA_EN_SHIFT             (31U)
/*! XO_ANA_EN - XO Analog Enable
 *  0b0..XO analog disabled
 *  0b1..XO analog enabled
 */
#define RFMC_XO_CTRL_XO_ANA_EN(x)                (((uint32_t)(((uint32_t)(x)) << RFMC_XO_CTRL_XO_ANA_EN_SHIFT)) & RFMC_XO_CTRL_XO_ANA_EN_MASK)
/*! @} */

/*! @name XO_STAT - XO Status Register */
/*! @{ */

#define RFMC_XO_STAT_RDY_FLAG_MASK               (0x1U)
#define RFMC_XO_STAT_RDY_FLAG_SHIFT              (0U)
/*! RDY_FLAG - XTAL Ready Flag */
#define RFMC_XO_STAT_RDY_FLAG(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_STAT_RDY_FLAG_SHIFT)) & RFMC_XO_STAT_RDY_FLAG_MASK)

#define RFMC_XO_STAT_INT_FLAG_MASK               (0x2U)
#define RFMC_XO_STAT_INT_FLAG_SHIFT              (1U)
/*! INT_FLAG - XO Internal Request Flag */
#define RFMC_XO_STAT_INT_FLAG(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_STAT_INT_FLAG_SHIFT)) & RFMC_XO_STAT_INT_FLAG_MASK)

#define RFMC_XO_STAT_EXT_FLAG_MASK               (0x4U)
#define RFMC_XO_STAT_EXT_FLAG_SHIFT              (2U)
/*! EXT_FLAG - XO External Request Flag */
#define RFMC_XO_STAT_EXT_FLAG(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_STAT_EXT_FLAG_SHIFT)) & RFMC_XO_STAT_EXT_FLAG_MASK)

#define RFMC_XO_STAT_XTAL_RDY_MASK               (0x10U)
#define RFMC_XO_STAT_XTAL_RDY_SHIFT              (4U)
/*! XTAL_RDY - XTAL Ready */
#define RFMC_XO_STAT_XTAL_RDY(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_STAT_XTAL_RDY_SHIFT)) & RFMC_XO_STAT_XTAL_RDY_MASK)

#define RFMC_XO_STAT_XO_EN_MASK                  (0x20U)
#define RFMC_XO_STAT_XO_EN_SHIFT                 (5U)
/*! XO_EN - XO_EN */
#define RFMC_XO_STAT_XO_EN(x)                    (((uint32_t)(((uint32_t)(x)) << RFMC_XO_STAT_XO_EN_SHIFT)) & RFMC_XO_STAT_XO_EN_MASK)
/*! @} */

/*! @name XO_TEST - XO Test Register */
/*! @{ */

#define RFMC_XO_TEST_ISEL_MASK                   (0xFU)
#define RFMC_XO_TEST_ISEL_SHIFT                  (0U)
/*! ISEL - XO Amplifier Current Select
 *  0b0000..40uA (min)
 *  0b0001..80uA
 *  0b0101..240uA (default)
 *  0b1111..640uA (max)
 */
#define RFMC_XO_TEST_ISEL(x)                     (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_ISEL_SHIFT)) & RFMC_XO_TEST_ISEL_MASK)

#define RFMC_XO_TEST_CDAC_MASK                   (0x3F0U)
#define RFMC_XO_TEST_CDAC_SHIFT                  (4U)
/*! CDAC - XO On-chip Load Capacitor Trim
 *  0b000000..C_FIX
 *  0b111111..C_FIX + 14.36pF
 */
#define RFMC_XO_TEST_CDAC(x)                     (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_CDAC_SHIFT)) & RFMC_XO_TEST_CDAC_MASK)

#define RFMC_XO_TEST_CAP_OFF_MASK                (0x400U)
#define RFMC_XO_TEST_CAP_OFF_SHIFT               (10U)
/*! CAP_OFF - XO Load Capacitor Disable */
#define RFMC_XO_TEST_CAP_OFF(x)                  (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_CAP_OFF_SHIFT)) & RFMC_XO_TEST_CAP_OFF_MASK)

#define RFMC_XO_TEST_AUX_PD_MASK                 (0x800U)
#define RFMC_XO_TEST_AUX_PD_SHIFT                (11U)
/*! AUX_PD - XO CLK_AUX_DRV Powerdown */
#define RFMC_XO_TEST_AUX_PD(x)                   (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_AUX_PD_SHIFT)) & RFMC_XO_TEST_AUX_PD_MASK)

#define RFMC_XO_TEST_AMP_FORCE_MASK              (0x1000U)
#define RFMC_XO_TEST_AMP_FORCE_SHIFT             (12U)
/*! AMP_FORCE - XO Amplifier Force PTAT Startup */
#define RFMC_XO_TEST_AMP_FORCE(x)                (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_AMP_FORCE_SHIFT)) & RFMC_XO_TEST_AMP_FORCE_MASK)

#define RFMC_XO_TEST_DYN_ISEL_MASK               (0x2000U)
#define RFMC_XO_TEST_DYN_ISEL_SHIFT              (13U)
/*! DYN_ISEL - XO Amplifier: enable current switching during startup */
#define RFMC_XO_TEST_DYN_ISEL(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_DYN_ISEL_SHIFT)) & RFMC_XO_TEST_DYN_ISEL_MASK)

#define RFMC_XO_TEST_DYN_CAP_MASK                (0x4000U)
#define RFMC_XO_TEST_DYN_CAP_SHIFT               (14U)
/*! DYN_CAP - XO On-chip Load Capacitor: enable switching during startup */
#define RFMC_XO_TEST_DYN_CAP(x)                  (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_DYN_CAP_SHIFT)) & RFMC_XO_TEST_DYN_CAP_MASK)

#define RFMC_XO_TEST_LDO_TRIM_MASK               (0x30000U)
#define RFMC_XO_TEST_LDO_TRIM_SHIFT              (16U)
/*! LDO_TRIM - XO LDO Output Voltage Trim
 *  0b00..0.92V
 *  0b01..0.885V
 *  0b10..0.955V
 *  0b11..1.011V
 */
#define RFMC_XO_TEST_LDO_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_LDO_TRIM_SHIFT)) & RFMC_XO_TEST_LDO_TRIM_MASK)

#define RFMC_XO_TEST_LDO_BUMP_MASK               (0xC0000U)
#define RFMC_XO_TEST_LDO_BUMP_SHIFT              (18U)
/*! LDO_BUMP - XO LDO PTAT Current Bump
 *  0b00..PTAT current bump default
 *  0b01..PTAT current boost: +30%
 */
#define RFMC_XO_TEST_LDO_BUMP(x)                 (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_LDO_BUMP_SHIFT)) & RFMC_XO_TEST_LDO_BUMP_MASK)

#define RFMC_XO_TEST_LDO_FORCE_MASK              (0x100000U)
#define RFMC_XO_TEST_LDO_FORCE_SHIFT             (20U)
/*! LDO_FORCE - XO LDO Force PTAT Startup */
#define RFMC_XO_TEST_LDO_FORCE(x)                (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_LDO_FORCE_SHIFT)) & RFMC_XO_TEST_LDO_FORCE_MASK)

#define RFMC_XO_TEST_XO_CDAC_TRIM_MASK           (0x600000U)
#define RFMC_XO_TEST_XO_CDAC_TRIM_SHIFT          (21U)
/*! XO_CDAC_TRIM - XO fixed cap bank C_FIX trimming
 *  0b00..5.19pF
 *  0b01..3.81pF
 *  0b10..2.44pF
 *  0b11..1.98pF
 */
#define RFMC_XO_TEST_XO_CDAC_TRIM(x)             (((uint32_t)(((uint32_t)(x)) << RFMC_XO_TEST_XO_CDAC_TRIM_SHIFT)) & RFMC_XO_TEST_XO_CDAC_TRIM_MASK)
/*! @} */

/*! @name RF2P4GHZ_CTRL - 2.4GHz Radio Control Register */
/*! @{ */

#define RFMC_RF2P4GHZ_CTRL_WOR_WKUP_IE_MASK      (0x1U)
#define RFMC_RF2P4GHZ_CTRL_WOR_WKUP_IE_SHIFT     (0U)
/*! WOR_WKUP_IE - WOR Wakeup Interrupt Enable
 *  0b0..WOR wakeup interrupt disabled
 *  0b1..WOR wakeup interrupt enabled
 */
#define RFMC_RF2P4GHZ_CTRL_WOR_WKUP_IE(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_WOR_WKUP_IE_SHIFT)) & RFMC_RF2P4GHZ_CTRL_WOR_WKUP_IE_MASK)

#define RFMC_RF2P4GHZ_CTRL_MAN_WKUP_IE_MASK      (0x2U)
#define RFMC_RF2P4GHZ_CTRL_MAN_WKUP_IE_SHIFT     (1U)
/*! MAN_WKUP_IE - MAN Wakeup Interrupt Enable
 *  0b0..MAN wakeup interrupt disabled
 *  0b1..MAN wakeup interrupt enabled
 */
#define RFMC_RF2P4GHZ_CTRL_MAN_WKUP_IE(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_MAN_WKUP_IE_SHIFT)) & RFMC_RF2P4GHZ_CTRL_MAN_WKUP_IE_MASK)

#define RFMC_RF2P4GHZ_CTRL_BLE_WKUP_IE_MASK      (0x4U)
#define RFMC_RF2P4GHZ_CTRL_BLE_WKUP_IE_SHIFT     (2U)
/*! BLE_WKUP_IE - Bluetooth LE Wakeup Interrupt Enable
 *  0b0..Bluetooth LE wakeup interrupt disabled
 *  0b1..Bluetooth LE wakeup interrupt enabled
 */
#define RFMC_RF2P4GHZ_CTRL_BLE_WKUP_IE(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_BLE_WKUP_IE_SHIFT)) & RFMC_RF2P4GHZ_CTRL_BLE_WKUP_IE_MASK)

#define RFMC_RF2P4GHZ_CTRL_RFACT_IE_MASK         (0x8U)
#define RFMC_RF2P4GHZ_CTRL_RFACT_IE_SHIFT        (3U)
/*! RFACT_IE - RF_ACTIVE Interrupt Enable
 *  0b0..RF_ACTIVE interrupt disabled
 *  0b1..RF_ACTIVE interrupt enabled
 */
#define RFMC_RF2P4GHZ_CTRL_RFACT_IE(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_RFACT_IE_SHIFT)) & RFMC_RF2P4GHZ_CTRL_RFACT_IE_MASK)

#define RFMC_RF2P4GHZ_CTRL_LP_WKUP_IE_MASK       (0x10U)
#define RFMC_RF2P4GHZ_CTRL_LP_WKUP_IE_SHIFT      (4U)
/*! LP_WKUP_IE - Low Power Wakeup Interrupt Enable
 *  0b0..Low Power wakeup interrupt disabled
 *  0b1..Low Power wakeup interrupt enabled
 */
#define RFMC_RF2P4GHZ_CTRL_LP_WKUP_IE(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_LP_WKUP_IE_SHIFT)) & RFMC_RF2P4GHZ_CTRL_LP_WKUP_IE_MASK)

#define RFMC_RF2P4GHZ_CTRL_BLE_WKUP_MASK         (0x20U)
#define RFMC_RF2P4GHZ_CTRL_BLE_WKUP_SHIFT        (5U)
/*! BLE_WKUP - Bluetooth LE Wakeup
 *  0b0..Bluetooth LE low power mode wakeup deasserted
 *  0b1..Bluetooth LE low power mode wakeup asserted
 */
#define RFMC_RF2P4GHZ_CTRL_BLE_WKUP(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_BLE_WKUP_SHIFT)) & RFMC_RF2P4GHZ_CTRL_BLE_WKUP_MASK)

#define RFMC_RF2P4GHZ_CTRL_BLE_LP_EN_MASK        (0x40U)
#define RFMC_RF2P4GHZ_CTRL_BLE_LP_EN_SHIFT       (6U)
/*! BLE_LP_EN - Bluetooth LE Low Power Enable
 *  0b0..Bluetooth LE wakeup request disabled
 *  0b1..Bluetooth LE wakeup request enabled
 */
#define RFMC_RF2P4GHZ_CTRL_BLE_LP_EN(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_BLE_LP_EN_SHIFT)) & RFMC_RF2P4GHZ_CTRL_BLE_LP_EN_MASK)

#define RFMC_RF2P4GHZ_CTRL_LP_ENTER_MASK         (0x80U)
#define RFMC_RF2P4GHZ_CTRL_LP_ENTER_SHIFT        (7U)
/*! LP_ENTER - S/W Low Power Entry Request
 *  0b0..Deassert S/W request for low power mode entry
 *  0b1..Assert S/W request for low power mode entry
 */
#define RFMC_RF2P4GHZ_CTRL_LP_ENTER(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_LP_ENTER_SHIFT)) & RFMC_RF2P4GHZ_CTRL_LP_ENTER_MASK)

#define RFMC_RF2P4GHZ_CTRL_LP_MODE_MASK          (0xF00U)
#define RFMC_RF2P4GHZ_CTRL_LP_MODE_SHIFT         (8U)
/*! LP_MODE - Radio Low Power Mode
 *  0b0000..Active: clock gating only (only intended for debug)
 *  0b0001..Sleep: clock gating, PMC in low power mode(only intended for debug)
 *  0b0011..Deep Sleep: low power static mode with retention of digital logic and SRAMs.
 *  0b0111..Power Down: power down of radio digital logic, optional SRAM retention.
 *  0b1111..Deep Power Down: power down of radio digital logic and SRAMs.
 */
#define RFMC_RF2P4GHZ_CTRL_LP_MODE(x)            (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_LP_MODE_SHIFT)) & RFMC_RF2P4GHZ_CTRL_LP_MODE_MASK)

#define RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_MASK      (0x3F000U)
#define RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_SHIFT     (12U)
/*! LP_WKUP_DLY - LP Wakeup Delay */
#define RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_SHIFT)) & RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_MASK)

#define RFMC_RF2P4GHZ_CTRL_SFA_TRIG_EN_MASK      (0x1C0000U)
#define RFMC_RF2P4GHZ_CTRL_SFA_TRIG_EN_SHIFT     (18U)
/*! SFA_TRIG_EN - SFA Trigger Enable
 *  0b0xx..Bluetooth LE Low Power Controller is not allowed to cause an SFA trigger.
 *  0b1xx..Bluetooth LE Low Power Controller is allowed to cause an SFA trigger.
 *  0bx0x..WOR Low Power Controller is not allowed to cause an SFA trigger.
 *  0bx1x..WOR Low Power Controller is allowed to cause an SFA trigger.
 *  0bxx0..MAN Low Power Controller is not allowed to cause an SFA trigger.
 *  0bxx1..MAN Low Power Controller is allowed to cause an SFA trigger.
 */
#define RFMC_RF2P4GHZ_CTRL_SFA_TRIG_EN(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_SFA_TRIG_EN_SHIFT)) & RFMC_RF2P4GHZ_CTRL_SFA_TRIG_EN_MASK)

#define RFMC_RF2P4GHZ_CTRL_LP_STOP_REQ_GLITCH_DIS_MASK (0x200000U)
#define RFMC_RF2P4GHZ_CTRL_LP_STOP_REQ_GLITCH_DIS_SHIFT (21U)
/*! LP_STOP_REQ_GLITCH_DIS - LP_STOP_REQ Glitch Disable for 2.4GHz Radio */
#define RFMC_RF2P4GHZ_CTRL_LP_STOP_REQ_GLITCH_DIS(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_LP_STOP_REQ_GLITCH_DIS_SHIFT)) & RFMC_RF2P4GHZ_CTRL_LP_STOP_REQ_GLITCH_DIS_MASK)

#define RFMC_RF2P4GHZ_CTRL_XO_EN_GLITCH_DIS_MASK (0x400000U)
#define RFMC_RF2P4GHZ_CTRL_XO_EN_GLITCH_DIS_SHIFT (22U)
/*! XO_EN_GLITCH_DIS - XO_EN Glitch Disable for 2.4GHz Radio */
#define RFMC_RF2P4GHZ_CTRL_XO_EN_GLITCH_DIS(x)   (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_XO_EN_GLITCH_DIS_SHIFT)) & RFMC_RF2P4GHZ_CTRL_XO_EN_GLITCH_DIS_MASK)

#define RFMC_RF2P4GHZ_CTRL_XO_EN_MASK            (0x800000U)
#define RFMC_RF2P4GHZ_CTRL_XO_EN_SHIFT           (23U)
/*! XO_EN - XO Enable for 2.4GHz Radio
 *  0b0..XO software enable deasserted
 *  0b1..XO software enable asserted
 */
#define RFMC_RF2P4GHZ_CTRL_XO_EN(x)              (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_XO_EN_SHIFT)) & RFMC_RF2P4GHZ_CTRL_XO_EN_MASK)

#define RFMC_RF2P4GHZ_CTRL_CLK_OVR_MASK          (0xF000000U)
#define RFMC_RF2P4GHZ_CTRL_CLK_OVR_SHIFT         (24U)
/*! CLK_OVR - Clock Gating Override
 *  0b0xxx..Bluetooth LE power controller clock (and 32kHz clock used by Bluetooth LE link layer) only enabled when BLE_LP_EN=1 (default)
 *  0b1xxx..Bluetooth LE power controller clock (and 32kHz clock used by Bluetooth LE link layer) always enabled
 *  0bx0xx..WOR power controller clock only enabled when WOR_EN=1 (default)
 *  0bx1xx..WOR power controller clock always enabled
 *  0bxx0x..MAN power controller clock only enabled when MAN_EN=1 (default)
 *  0bxx1x..MAN power controller clock always enabled
 *  0bxxx0..TIMER clock only enabled when TIM_EN=1
 *  0bxxx1..TIMER clock always enabled
 */
#define RFMC_RF2P4GHZ_CTRL_CLK_OVR(x)            (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_CLK_OVR_SHIFT)) & RFMC_RF2P4GHZ_CTRL_CLK_OVR_MASK)

#define RFMC_RF2P4GHZ_CTRL_CPU_RST_LOCK_MASK     (0x10000000U)
#define RFMC_RF2P4GHZ_CTRL_CPU_RST_LOCK_SHIFT    (28U)
/*! CPU_RST_LOCK - LOCK for CPU_RST
 *  0b0..CPU_RST bit is not locked
 *  0b1..CPU_RST bit is locked
 */
#define RFMC_RF2P4GHZ_CTRL_CPU_RST_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_CPU_RST_LOCK_SHIFT)) & RFMC_RF2P4GHZ_CTRL_CPU_RST_LOCK_MASK)

#define RFMC_RF2P4GHZ_CTRL_CPU_RST_MASK          (0x20000000U)
#define RFMC_RF2P4GHZ_CTRL_CPU_RST_SHIFT         (29U)
/*! CPU_RST - S/W Reset for 2.4GHz Radio CPU
 *  0b0..Release the 2.4GHz radio CPU from reset
 *  0b1..Hold the 2.4GHz radio CPU in reset
 */
#define RFMC_RF2P4GHZ_CTRL_CPU_RST(x)            (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_CPU_RST_SHIFT)) & RFMC_RF2P4GHZ_CTRL_CPU_RST_MASK)

#define RFMC_RF2P4GHZ_CTRL_RF_POR_MASK           (0x40000000U)
#define RFMC_RF2P4GHZ_CTRL_RF_POR_SHIFT          (30U)
/*! RF_POR - S/W Power-on-Reset for 2.4GHz Radio
 *  0b0..Release the 2.4GHz radio from power-on-reset
 *  0b1..Hold the 2.4GHz radio in power-on-reset
 */
#define RFMC_RF2P4GHZ_CTRL_RF_POR(x)             (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_RF_POR_SHIFT)) & RFMC_RF2P4GHZ_CTRL_RF_POR_MASK)

#define RFMC_RF2P4GHZ_CTRL_RST_MASK              (0x80000000U)
#define RFMC_RF2P4GHZ_CTRL_RST_SHIFT             (31U)
/*! RST - S/W Reset for 2.4GHz Radio
 *  0b0..Release the 2.4GHz radio from reset
 *  0b1..Hold the 2.4GHz radio in reset
 */
#define RFMC_RF2P4GHZ_CTRL_RST(x)                (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CTRL_RST_SHIFT)) & RFMC_RF2P4GHZ_CTRL_RST_MASK)
/*! @} */

/*! @name RF2P4GHZ_STAT - 2.4GHz Radio Status Register */
/*! @{ */

#define RFMC_RF2P4GHZ_STAT_WOR_WKUP_FLAG_MASK    (0x1U)
#define RFMC_RF2P4GHZ_STAT_WOR_WKUP_FLAG_SHIFT   (0U)
/*! WOR_WKUP_FLAG - WOR Wakeup Flag */
#define RFMC_RF2P4GHZ_STAT_WOR_WKUP_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_WOR_WKUP_FLAG_SHIFT)) & RFMC_RF2P4GHZ_STAT_WOR_WKUP_FLAG_MASK)

#define RFMC_RF2P4GHZ_STAT_MAN_WKUP_FLAG_MASK    (0x2U)
#define RFMC_RF2P4GHZ_STAT_MAN_WKUP_FLAG_SHIFT   (1U)
/*! MAN_WKUP_FLAG - MAN Wakeup Flag */
#define RFMC_RF2P4GHZ_STAT_MAN_WKUP_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_MAN_WKUP_FLAG_SHIFT)) & RFMC_RF2P4GHZ_STAT_MAN_WKUP_FLAG_MASK)

#define RFMC_RF2P4GHZ_STAT_BLE_WKUP_FLAG_MASK    (0x4U)
#define RFMC_RF2P4GHZ_STAT_BLE_WKUP_FLAG_SHIFT   (2U)
/*! BLE_WKUP_FLAG - Bluetooth LE Wakeup Flag */
#define RFMC_RF2P4GHZ_STAT_BLE_WKUP_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_BLE_WKUP_FLAG_SHIFT)) & RFMC_RF2P4GHZ_STAT_BLE_WKUP_FLAG_MASK)

#define RFMC_RF2P4GHZ_STAT_RFACT_FLAG_MASK       (0x8U)
#define RFMC_RF2P4GHZ_STAT_RFACT_FLAG_SHIFT      (3U)
/*! RFACT_FLAG - RF_ACTIVE Flag */
#define RFMC_RF2P4GHZ_STAT_RFACT_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_RFACT_FLAG_SHIFT)) & RFMC_RF2P4GHZ_STAT_RFACT_FLAG_MASK)

#define RFMC_RF2P4GHZ_STAT_LP_WKUP_FLAG_MASK     (0x10U)
#define RFMC_RF2P4GHZ_STAT_LP_WKUP_FLAG_SHIFT    (4U)
/*! LP_WKUP_FLAG - Low Power Wakeup Flag */
#define RFMC_RF2P4GHZ_STAT_LP_WKUP_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_LP_WKUP_FLAG_SHIFT)) & RFMC_RF2P4GHZ_STAT_LP_WKUP_FLAG_MASK)

#define RFMC_RF2P4GHZ_STAT_SLP_RDY_STAT_MASK     (0x20U)
#define RFMC_RF2P4GHZ_STAT_SLP_RDY_STAT_SHIFT    (5U)
/*! SLP_RDY_STAT - RF_CMC Sleep Ready Status */
#define RFMC_RF2P4GHZ_STAT_SLP_RDY_STAT(x)       (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_SLP_RDY_STAT_SHIFT)) & RFMC_RF2P4GHZ_STAT_SLP_RDY_STAT_MASK)

#define RFMC_RF2P4GHZ_STAT_RST_STAT_MASK         (0x40U)
#define RFMC_RF2P4GHZ_STAT_RST_STAT_SHIFT        (6U)
/*! RST_STAT - Reset Status
 *  0b0..Reset is not asserted.
 *  0b1..Reset is asserted.
 */
#define RFMC_RF2P4GHZ_STAT_RST_STAT(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_RST_STAT_SHIFT)) & RFMC_RF2P4GHZ_STAT_RST_STAT_MASK)

#define RFMC_RF2P4GHZ_STAT_FRO_CLK_VLD_STAT_MASK (0x80U)
#define RFMC_RF2P4GHZ_STAT_FRO_CLK_VLD_STAT_SHIFT (7U)
/*! FRO_CLK_VLD_STAT - FRO Clock Valid Status */
#define RFMC_RF2P4GHZ_STAT_FRO_CLK_VLD_STAT(x)   (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_FRO_CLK_VLD_STAT_SHIFT)) & RFMC_RF2P4GHZ_STAT_FRO_CLK_VLD_STAT_MASK)

#define RFMC_RF2P4GHZ_STAT_LP_REQ_STAT_MASK      (0x100U)
#define RFMC_RF2P4GHZ_STAT_LP_REQ_STAT_SHIFT     (8U)
/*! LP_REQ_STAT - Low Power Request Status */
#define RFMC_RF2P4GHZ_STAT_LP_REQ_STAT(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_LP_REQ_STAT_SHIFT)) & RFMC_RF2P4GHZ_STAT_LP_REQ_STAT_MASK)

#define RFMC_RF2P4GHZ_STAT_LP_ACK_STAT_MASK      (0x200U)
#define RFMC_RF2P4GHZ_STAT_LP_ACK_STAT_SHIFT     (9U)
/*! LP_ACK_STAT - Low Power Acknowledge Status */
#define RFMC_RF2P4GHZ_STAT_LP_ACK_STAT(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_LP_ACK_STAT_SHIFT)) & RFMC_RF2P4GHZ_STAT_LP_ACK_STAT_MASK)

#define RFMC_RF2P4GHZ_STAT_BLE_WKUP_STAT_MASK    (0x400U)
#define RFMC_RF2P4GHZ_STAT_BLE_WKUP_STAT_SHIFT   (10U)
/*! BLE_WKUP_STAT - Bluetooth LE Wakeup Status */
#define RFMC_RF2P4GHZ_STAT_BLE_WKUP_STAT(x)      (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_BLE_WKUP_STAT_SHIFT)) & RFMC_RF2P4GHZ_STAT_BLE_WKUP_STAT_MASK)

#define RFMC_RF2P4GHZ_STAT_WOR_STATE_MASK        (0x7000U)
#define RFMC_RF2P4GHZ_STAT_WOR_STATE_SHIFT       (12U)
/*! WOR_STATE - WOR Low Power State
 *  0b000..RESET state (WOR_EN=0).
 *  0b001..ACTIVE state (XO enabled, RF_ACTIVE asserted, LP request deasserted).
 *  0b010..SLEEP state (XO disabled, RF_ACTIVE deasserted, LP request asserted).
 *  0b011..WAKEUP state (XO enabled, RF_ACTIVE asserted after RFACT_WKUP_DLY, LP request deasserted after LP_WKUP_DLY).
 */
#define RFMC_RF2P4GHZ_STAT_WOR_STATE(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_WOR_STATE_SHIFT)) & RFMC_RF2P4GHZ_STAT_WOR_STATE_MASK)

#define RFMC_RF2P4GHZ_STAT_MAN_STATE_MASK        (0x38000U)
#define RFMC_RF2P4GHZ_STAT_MAN_STATE_SHIFT       (15U)
/*! MAN_STATE - MAN Low Power State
 *  0b000..RESET state (MAN_EN=0).
 *  0b001..ACTIVE state (XO enabled, RF_ACTIVE asserted, LP request deasserted).
 *  0b010..SLEEP state (XO disabled, RF_ACTIVE deasserted, LP request asserted).
 *  0b011..WAKEUP state (XO enabled, RF_ACTIVE asserted after RFACT_WKUP_DLY, LP request deasserted after LP_WKUP_DLY).
 */
#define RFMC_RF2P4GHZ_STAT_MAN_STATE(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_MAN_STATE_SHIFT)) & RFMC_RF2P4GHZ_STAT_MAN_STATE_MASK)

#define RFMC_RF2P4GHZ_STAT_BLE_STATE_MASK        (0x1C0000U)
#define RFMC_RF2P4GHZ_STAT_BLE_STATE_SHIFT       (18U)
/*! BLE_STATE - Bluetooth LE Low Power State
 *  0b000..RESET state (BLE_LP_EN=0).
 *  0b001..ACTIVE state (XO enabled, RF_ACTIVE asserted, LP request deasserted).
 *  0b010..SLEEP state (XO disabled, RF_ACTIVE deasserted, LP request asserted).
 *  0b011..WAKEUP state (XO enabled, RF_ACTIVE asserted after RFACT_WKUP_DLY, LP request deasserted after LP_WKUP_DLY).
 */
#define RFMC_RF2P4GHZ_STAT_BLE_STATE(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_STAT_BLE_STATE_SHIFT)) & RFMC_RF2P4GHZ_STAT_BLE_STATE_MASK)
/*! @} */

/*! @name RF2P4GHZ_COEXT - 2.4GHz Radio Coexistence Register */
/*! @{ */

#define RFMC_RF2P4GHZ_COEXT_RFGPO_OBE_MASK       (0xFFU)
#define RFMC_RF2P4GHZ_COEXT_RFGPO_OBE_SHIFT      (0U)
/*! RFGPO_OBE - RF_GPO Output Buffer Enable */
#define RFMC_RF2P4GHZ_COEXT_RFGPO_OBE(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_RFGPO_OBE_SHIFT)) & RFMC_RF2P4GHZ_COEXT_RFGPO_OBE_MASK)

#define RFMC_RF2P4GHZ_COEXT_RFGPO_SRC_MASK       (0x700U)
#define RFMC_RF2P4GHZ_COEXT_RFGPO_SRC_SHIFT      (8U)
/*! RFGPO_SRC - RF_GPO Source
 *  0b000..RF_GPO[7:0] = {coext[3:0], fem_ctrl[3:0]}
 *  0b001..RF_GPO[7:0] = {fem_ctrl[3:0], coext[3:0]}
 *  0b010..RF_GPO[7:0] = {lant_lut_gpio[3:0], fem_ctrl[3:0]}
 *  0b011..RF_GPO[7:0] = {fem_ctrl[3:0], lant_lut_gpio[3:0]}
 *  0b100..RF_GPO[7:0] = {lant_lut_gpio[3:0], coext[3:0]}
 *  0b101..RF_GPO[7:0] = {coext[3:0], lant_lut_gpio[3:0]}
 */
#define RFMC_RF2P4GHZ_COEXT_RFGPO_SRC(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_RFGPO_SRC_SHIFT)) & RFMC_RF2P4GHZ_COEXT_RFGPO_SRC_MASK)

#define RFMC_RF2P4GHZ_COEXT_PORTA_PWR_MASK       (0x800U)
#define RFMC_RF2P4GHZ_COEXT_PORTA_PWR_SHIFT      (11U)
/*! PORTA_PWR - PORTA Power
 *  0b0..PORTA pins do not remain powered (default behavior)
 *  0b1..PORTA pins remain powered
 */
#define RFMC_RF2P4GHZ_COEXT_PORTA_PWR(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_PORTA_PWR_SHIFT)) & RFMC_RF2P4GHZ_COEXT_PORTA_PWR_MASK)

#define RFMC_RF2P4GHZ_COEXT_RFACT_SRC_MASK       (0x3000U)
#define RFMC_RF2P4GHZ_COEXT_RFACT_SRC_SHIFT      (12U)
/*! RFACT_SRC - RF_ACTIVE Source
 *  0b00..RF_ACTIVE is driven by the RFMC
 *  0b01..RF_ACTIVE is driven by the TSM/LL
 *  0b10..RF_ACTIVE is driven by the Bluetooth LE wakeup request (bt_clk_req)
 *  0b11..Reserved
 */
#define RFMC_RF2P4GHZ_COEXT_RFACT_SRC(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_RFACT_SRC_SHIFT)) & RFMC_RF2P4GHZ_COEXT_RFACT_SRC_MASK)

#define RFMC_RF2P4GHZ_COEXT_RFACT_IDIS_MASK      (0x4000U)
#define RFMC_RF2P4GHZ_COEXT_RFACT_IDIS_SHIFT     (14U)
/*! RFACT_IDIS - RF_ACTIVE Idle Disable
 *  0b0..RF_ACTIVE does not deassert when TSM is idle (will deassert on next low power mode entry)
 *  0b1..RF_ACTIVE will deassert when TSM is idle
 */
#define RFMC_RF2P4GHZ_COEXT_RFACT_IDIS(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_RFACT_IDIS_SHIFT)) & RFMC_RF2P4GHZ_COEXT_RFACT_IDIS_MASK)

#define RFMC_RF2P4GHZ_COEXT_RFACT_EN_MASK        (0x8000U)
#define RFMC_RF2P4GHZ_COEXT_RFACT_EN_SHIFT       (15U)
/*! RFACT_EN - S/W Enable of RF_ACTIVE pin
 *  0b0..Take no action
 *  0b1..Assert RF_ACTIVE pin
 */
#define RFMC_RF2P4GHZ_COEXT_RFACT_EN(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_RFACT_EN_SHIFT)) & RFMC_RF2P4GHZ_COEXT_RFACT_EN_MASK)

#define RFMC_RF2P4GHZ_COEXT_RFACT_WKUP_DLY_MASK  (0x3F0000U)
#define RFMC_RF2P4GHZ_COEXT_RFACT_WKUP_DLY_SHIFT (16U)
/*! RFACT_WKUP_DLY - RF_ACTIVE Wakeup Delay */
#define RFMC_RF2P4GHZ_COEXT_RFACT_WKUP_DLY(x)    (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_RFACT_WKUP_DLY_SHIFT)) & RFMC_RF2P4GHZ_COEXT_RFACT_WKUP_DLY_MASK)

#define RFMC_RF2P4GHZ_COEXT_QREQ_SRC_MASK        (0x1000000U)
#define RFMC_RF2P4GHZ_COEXT_QREQ_SRC_SHIFT       (24U)
/*! QREQ_SRC - QUIET_REQ Source
 *  0b0..QUIET_REQ is driven by the RFMC
 *  0b1..QUIET_REQ is driven by the TSM/LL
 */
#define RFMC_RF2P4GHZ_COEXT_QREQ_SRC(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_QREQ_SRC_SHIFT)) & RFMC_RF2P4GHZ_COEXT_QREQ_SRC_MASK)

#define RFMC_RF2P4GHZ_COEXT_QREQ_SOC_EN_MASK     (0x2000000U)
#define RFMC_RF2P4GHZ_COEXT_QREQ_SOC_EN_SHIFT    (25U)
/*! QREQ_SOC_EN - QUIET_REQ Enable for SOC Core Flash
 *  0b0..QUIET_REQ is not enabled for SOC Core Flash
 *  0b1..QUIET_REQ is enabled for SOC Core Flash
 */
#define RFMC_RF2P4GHZ_COEXT_QREQ_SOC_EN(x)       (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_QREQ_SOC_EN_SHIFT)) & RFMC_RF2P4GHZ_COEXT_QREQ_SOC_EN_MASK)

#define RFMC_RF2P4GHZ_COEXT_QREQ_RF_EN_MASK      (0x4000000U)
#define RFMC_RF2P4GHZ_COEXT_QREQ_RF_EN_SHIFT     (26U)
/*! QREQ_RF_EN - QUIET_REQ Enable for Radio CPU Flash
 *  0b0..QUIET_REQ is not enabled for Radio CPU Flash
 *  0b1..QUIET_REQ is enabled for Radio CPU Flash
 */
#define RFMC_RF2P4GHZ_COEXT_QREQ_RF_EN(x)        (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_QREQ_RF_EN_SHIFT)) & RFMC_RF2P4GHZ_COEXT_QREQ_RF_EN_MASK)

#define RFMC_RF2P4GHZ_COEXT_RFNA_IBE_MASK        (0x70000000U)
#define RFMC_RF2P4GHZ_COEXT_RFNA_IBE_SHIFT       (28U)
/*! RFNA_IBE - RF_NOT_ALLOWED Input Buffer Enables
 *  0b000..RF_NOT_ALLOWED input pin disabled
 *  0b001..RF_NOT_ALLOWED input pin uses PTA16
 *  0b010..RF_NOT_ALLOWED input pin uses PTA17
 *  0b011..RF_NOT_ALLOWED input pin uses PTA22
 *  0b100..RF_NOT_ALLOWED input pin uses PTC7
 *  0b101..RF_NOT_ALLOWED input pin uses PTD6
 */
#define RFMC_RF2P4GHZ_COEXT_RFNA_IBE(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_COEXT_RFNA_IBE_SHIFT)) & RFMC_RF2P4GHZ_COEXT_RFNA_IBE_MASK)
/*! @} */

/*! @name RF2P4GHZ_TIMER - 2.4GHz TIMER Register */
/*! @{ */

#define RFMC_RF2P4GHZ_TIMER_TIME_MASK            (0xFFFFFFU)
#define RFMC_RF2P4GHZ_TIMER_TIME_SHIFT           (0U)
/*! TIME - Timer Count */
#define RFMC_RF2P4GHZ_TIMER_TIME(x)              (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_TIMER_TIME_SHIFT)) & RFMC_RF2P4GHZ_TIMER_TIME_MASK)

#define RFMC_RF2P4GHZ_TIMER_TIM_CLR_MASK         (0x40000000U)
#define RFMC_RF2P4GHZ_TIMER_TIM_CLR_SHIFT        (30U)
/*! TIM_CLR - Timer Clear
 *  0b0..Timer not cleared
 *  0b1..Timer cleared
 */
#define RFMC_RF2P4GHZ_TIMER_TIM_CLR(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_TIMER_TIM_CLR_SHIFT)) & RFMC_RF2P4GHZ_TIMER_TIM_CLR_MASK)

#define RFMC_RF2P4GHZ_TIMER_TIM_EN_MASK          (0x80000000U)
#define RFMC_RF2P4GHZ_TIMER_TIM_EN_SHIFT         (31U)
/*! TIM_EN - Timer Enable
 *  0b0..Timer disabled
 *  0b1..Timer enabled
 */
#define RFMC_RF2P4GHZ_TIMER_TIM_EN(x)            (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_TIMER_TIM_EN_SHIFT)) & RFMC_RF2P4GHZ_TIMER_TIM_EN_MASK)
/*! @} */

/*! @name RF2P4GHZ_WOR1 - 2.4GHz WOR Register 1 */
/*! @{ */

#define RFMC_RF2P4GHZ_WOR1_DURATION_TGT_MASK     (0xFFFFFFU)
#define RFMC_RF2P4GHZ_WOR1_DURATION_TGT_SHIFT    (0U)
/*! DURATION_TGT - WOR Low Power Duration Target */
#define RFMC_RF2P4GHZ_WOR1_DURATION_TGT(x)       (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WOR1_DURATION_TGT_SHIFT)) & RFMC_RF2P4GHZ_WOR1_DURATION_TGT_MASK)

#define RFMC_RF2P4GHZ_WOR1_ENTER_REQ_MASK        (0x80000000U)
#define RFMC_RF2P4GHZ_WOR1_ENTER_REQ_SHIFT       (31U)
/*! ENTER_REQ - WOR Low Power Entry Request
 *  0b0..WOR low power mode request deasserted
 *  0b1..WOR low power mode request asserted
 */
#define RFMC_RF2P4GHZ_WOR1_ENTER_REQ(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WOR1_ENTER_REQ_SHIFT)) & RFMC_RF2P4GHZ_WOR1_ENTER_REQ_MASK)
/*! @} */

/*! @name RF2P4GHZ_WOR2 - 2.4GHz WOR Register 2 */
/*! @{ */

#define RFMC_RF2P4GHZ_WOR2_DURATION_MASK         (0xFFFFFFU)
#define RFMC_RF2P4GHZ_WOR2_DURATION_SHIFT        (0U)
/*! DURATION - WOR Low Power Duration */
#define RFMC_RF2P4GHZ_WOR2_DURATION(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WOR2_DURATION_SHIFT)) & RFMC_RF2P4GHZ_WOR2_DURATION_MASK)

#define RFMC_RF2P4GHZ_WOR2_WOR_WKUP_MASK         (0x40000000U)
#define RFMC_RF2P4GHZ_WOR2_WOR_WKUP_SHIFT        (30U)
/*! WOR_WKUP - WOR Wakeup
 *  0b0..WOR low power mode wakeup deasserted
 *  0b1..WOR low power mode wakeup asserted
 */
#define RFMC_RF2P4GHZ_WOR2_WOR_WKUP(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WOR2_WOR_WKUP_SHIFT)) & RFMC_RF2P4GHZ_WOR2_WOR_WKUP_MASK)

#define RFMC_RF2P4GHZ_WOR2_WOR_EN_MASK           (0x80000000U)
#define RFMC_RF2P4GHZ_WOR2_WOR_EN_SHIFT          (31U)
/*! WOR_EN - WOR Enable
 *  0b0..WOR low power mode entry/wakeup disabled
 *  0b1..WOR low power mode entry/wakeup enabled
 */
#define RFMC_RF2P4GHZ_WOR2_WOR_EN(x)             (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WOR2_WOR_EN_SHIFT)) & RFMC_RF2P4GHZ_WOR2_WOR_EN_MASK)
/*! @} */

/*! @name RF2P4GHZ_MAN1 - 2.4GHz MAN Register 1 */
/*! @{ */

#define RFMC_RF2P4GHZ_MAN1_ENTER_TIME_MASK       (0xFFFFFFU)
#define RFMC_RF2P4GHZ_MAN1_ENTER_TIME_SHIFT      (0U)
/*! ENTER_TIME - MAN Low Power Entry Time Stamp */
#define RFMC_RF2P4GHZ_MAN1_ENTER_TIME(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_MAN1_ENTER_TIME_SHIFT)) & RFMC_RF2P4GHZ_MAN1_ENTER_TIME_MASK)

#define RFMC_RF2P4GHZ_MAN1_ENTER_REQ_MASK        (0x80000000U)
#define RFMC_RF2P4GHZ_MAN1_ENTER_REQ_SHIFT       (31U)
/*! ENTER_REQ - MAN Low Power Entry Request
 *  0b0..MAN low power mode request deasserted
 *  0b1..MAN low power mode request asserted
 */
#define RFMC_RF2P4GHZ_MAN1_ENTER_REQ(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_MAN1_ENTER_REQ_SHIFT)) & RFMC_RF2P4GHZ_MAN1_ENTER_REQ_MASK)
/*! @} */

/*! @name RF2P4GHZ_MAN2 - 2.4GHz MAN Register 2 */
/*! @{ */

#define RFMC_RF2P4GHZ_MAN2_WKUP_TIME_MASK        (0xFFFFFFU)
#define RFMC_RF2P4GHZ_MAN2_WKUP_TIME_SHIFT       (0U)
/*! WKUP_TIME - MAN Low Power Wakeup Time Stamp */
#define RFMC_RF2P4GHZ_MAN2_WKUP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_MAN2_WKUP_TIME_SHIFT)) & RFMC_RF2P4GHZ_MAN2_WKUP_TIME_MASK)

#define RFMC_RF2P4GHZ_MAN2_MAN_WKUP_MASK         (0x40000000U)
#define RFMC_RF2P4GHZ_MAN2_MAN_WKUP_SHIFT        (30U)
/*! MAN_WKUP - MAN Wakeup
 *  0b0..MAN low power mode wakeup deasserted
 *  0b1..MAN low power mode wakeup asserted
 */
#define RFMC_RF2P4GHZ_MAN2_MAN_WKUP(x)           (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_MAN2_MAN_WKUP_SHIFT)) & RFMC_RF2P4GHZ_MAN2_MAN_WKUP_MASK)

#define RFMC_RF2P4GHZ_MAN2_MAN_EN_MASK           (0x80000000U)
#define RFMC_RF2P4GHZ_MAN2_MAN_EN_SHIFT          (31U)
/*! MAN_EN - MAN Enable
 *  0b0..MAN low power mode entry/wakeup disabled
 *  0b1..MAN low power mode entry/wakeup enabled
 */
#define RFMC_RF2P4GHZ_MAN2_MAN_EN(x)             (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_MAN2_MAN_EN_SHIFT)) & RFMC_RF2P4GHZ_MAN2_MAN_EN_MASK)
/*! @} */

/*! @name RF2P4GHZ_MAN3 - 2.4GHz MAN Register 3 */
/*! @{ */

#define RFMC_RF2P4GHZ_MAN3_ENTER_TIME_CAPT_MASK  (0xFFFFFFU)
#define RFMC_RF2P4GHZ_MAN3_ENTER_TIME_CAPT_SHIFT (0U)
/*! ENTER_TIME_CAPT - MAN Low Power Entry Time Captured */
#define RFMC_RF2P4GHZ_MAN3_ENTER_TIME_CAPT(x)    (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_MAN3_ENTER_TIME_CAPT_SHIFT)) & RFMC_RF2P4GHZ_MAN3_ENTER_TIME_CAPT_MASK)
/*! @} */

/*! @name RF2P4GHZ_MAN4 - 2.4GHz MAN Register 4 */
/*! @{ */

#define RFMC_RF2P4GHZ_MAN4_WKUP_TIME_CAPT_MASK   (0xFFFFFFU)
#define RFMC_RF2P4GHZ_MAN4_WKUP_TIME_CAPT_SHIFT  (0U)
/*! WKUP_TIME_CAPT - MAN Low Power Wakeup Time Captured */
#define RFMC_RF2P4GHZ_MAN4_WKUP_TIME_CAPT(x)     (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_MAN4_WKUP_TIME_CAPT_SHIFT)) & RFMC_RF2P4GHZ_MAN4_WKUP_TIME_CAPT_MASK)
/*! @} */

/*! @name RF2P4GHZ_HOST2RADIO - RF 2.4GHz Buffer from Host to Radio */
/*! @{ */

#define RFMC_RF2P4GHZ_HOST2RADIO_DATA_MASK       (0xFFFFU)
#define RFMC_RF2P4GHZ_HOST2RADIO_DATA_SHIFT      (0U)
/*! DATA - Data of Buffer0 */
#define RFMC_RF2P4GHZ_HOST2RADIO_DATA(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_HOST2RADIO_DATA_SHIFT)) & RFMC_RF2P4GHZ_HOST2RADIO_DATA_MASK)
/*! @} */

/*! @name RF2P4GHZ_RADIO2HOST - RF 2.4GHz Buffer from Radio to Host */
/*! @{ */

#define RFMC_RF2P4GHZ_RADIO2HOST_DATA_MASK       (0xFFFFU)
#define RFMC_RF2P4GHZ_RADIO2HOST_DATA_SHIFT      (0U)
/*! DATA - Data of Buffer0 */
#define RFMC_RF2P4GHZ_RADIO2HOST_DATA(x)         (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_RADIO2HOST_DATA_SHIFT)) & RFMC_RF2P4GHZ_RADIO2HOST_DATA_MASK)
/*! @} */

/*! @name RF2P4GHZ_CFG - 2.4GHz Radio Configuration Register */
/*! @{ */

#define RFMC_RF2P4GHZ_CFG_BLE_FAST_WKUP_MASK     (0x1U)
#define RFMC_RF2P4GHZ_CFG_BLE_FAST_WKUP_SHIFT    (0U)
/*! BLE_FAST_WKUP - No LP Wakeup Delay on WakeUp from Host */
#define RFMC_RF2P4GHZ_CFG_BLE_FAST_WKUP(x)       (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CFG_BLE_FAST_WKUP_SHIFT)) & RFMC_RF2P4GHZ_CFG_BLE_FAST_WKUP_MASK)

#define RFMC_RF2P4GHZ_CFG_RFMC_RADIO_DEBUG_REQ_EN_MASK (0x2U)
#define RFMC_RF2P4GHZ_CFG_RFMC_RADIO_DEBUG_REQ_EN_SHIFT (1U)
/*! RFMC_RADIO_DEBUG_REQ_EN - rfmc_radio_debug_req_en */
#define RFMC_RF2P4GHZ_CFG_RFMC_RADIO_DEBUG_REQ_EN(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CFG_RFMC_RADIO_DEBUG_REQ_EN_SHIFT)) & RFMC_RF2P4GHZ_CFG_RFMC_RADIO_DEBUG_REQ_EN_MASK)

#define RFMC_RF2P4GHZ_CFG_RFMC_EXT_WAKEUP_EN_MASK (0xCU)
#define RFMC_RF2P4GHZ_CFG_RFMC_EXT_WAKEUP_EN_SHIFT (2U)
/*! RFMC_EXT_WAKEUP_EN - Enable Radio wakeup by external source */
#define RFMC_RF2P4GHZ_CFG_RFMC_EXT_WAKEUP_EN(x)  (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CFG_RFMC_EXT_WAKEUP_EN_SHIFT)) & RFMC_RF2P4GHZ_CFG_RFMC_EXT_WAKEUP_EN_MASK)

#define RFMC_RF2P4GHZ_CFG_FORCE_DBG_PWRUP_ACK_MASK (0x10U)
#define RFMC_RF2P4GHZ_CFG_FORCE_DBG_PWRUP_ACK_SHIFT (4U)
/*! FORCE_DBG_PWRUP_ACK - Controls the Radio ack so that Radio can go into power down in debug mode also */
#define RFMC_RF2P4GHZ_CFG_FORCE_DBG_PWRUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_CFG_FORCE_DBG_PWRUP_ACK_SHIFT)) & RFMC_RF2P4GHZ_CFG_FORCE_DBG_PWRUP_ACK_MASK)
/*! @} */

/*! @name RF2P4GHZ_WKUP_SRC - 2.4GHz Radio WakeUp Source Register */
/*! @{ */

#define RFMC_RF2P4GHZ_WKUP_SRC_RFMC_RADIO_DEBUG_REQ_STATUS_MASK (0x1U)
#define RFMC_RF2P4GHZ_WKUP_SRC_RFMC_RADIO_DEBUG_REQ_STATUS_SHIFT (0U)
/*! RFMC_RADIO_DEBUG_REQ_STATUS - Radio debug request status */
#define RFMC_RF2P4GHZ_WKUP_SRC_RFMC_RADIO_DEBUG_REQ_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WKUP_SRC_RFMC_RADIO_DEBUG_REQ_STATUS_SHIFT)) & RFMC_RF2P4GHZ_WKUP_SRC_RFMC_RADIO_DEBUG_REQ_STATUS_MASK)

#define RFMC_RF2P4GHZ_WKUP_SRC_RFMC_EXT_WAKEUP_STATUS_MASK (0x6U)
#define RFMC_RF2P4GHZ_WKUP_SRC_RFMC_EXT_WAKEUP_STATUS_SHIFT (1U)
/*! RFMC_EXT_WAKEUP_STATUS - Radio wakeup by external source status */
#define RFMC_RF2P4GHZ_WKUP_SRC_RFMC_EXT_WAKEUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WKUP_SRC_RFMC_EXT_WAKEUP_STATUS_SHIFT)) & RFMC_RF2P4GHZ_WKUP_SRC_RFMC_EXT_WAKEUP_STATUS_MASK)

#define RFMC_RF2P4GHZ_WKUP_SRC_BLE_WKUP_STATUS_MASK (0x8U)
#define RFMC_RF2P4GHZ_WKUP_SRC_BLE_WKUP_STATUS_SHIFT (3U)
/*! BLE_WKUP_STATUS - RFMC BLE Wakeup status (Host Controlled) */
#define RFMC_RF2P4GHZ_WKUP_SRC_BLE_WKUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WKUP_SRC_BLE_WKUP_STATUS_SHIFT)) & RFMC_RF2P4GHZ_WKUP_SRC_BLE_WKUP_STATUS_MASK)

#define RFMC_RF2P4GHZ_WKUP_SRC_MAN_WKUP_STATUS_MASK (0x10U)
#define RFMC_RF2P4GHZ_WKUP_SRC_MAN_WKUP_STATUS_SHIFT (4U)
/*! MAN_WKUP_STATUS - RFMC MAN Wakeup status (Host Controlled) */
#define RFMC_RF2P4GHZ_WKUP_SRC_MAN_WKUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WKUP_SRC_MAN_WKUP_STATUS_SHIFT)) & RFMC_RF2P4GHZ_WKUP_SRC_MAN_WKUP_STATUS_MASK)

#define RFMC_RF2P4GHZ_WKUP_SRC_WOR_WKUP_STATUS_MASK (0x20U)
#define RFMC_RF2P4GHZ_WKUP_SRC_WOR_WKUP_STATUS_SHIFT (5U)
/*! WOR_WKUP_STATUS - RFMC WOR Wakeup status (Host Controlled) */
#define RFMC_RF2P4GHZ_WKUP_SRC_WOR_WKUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WKUP_SRC_WOR_WKUP_STATUS_SHIFT)) & RFMC_RF2P4GHZ_WKUP_SRC_WOR_WKUP_STATUS_MASK)

#define RFMC_RF2P4GHZ_WKUP_SRC_RF_CMC_BLE_WKUP_STATUS_MASK (0x40U)
#define RFMC_RF2P4GHZ_WKUP_SRC_RF_CMC_BLE_WKUP_STATUS_SHIFT (6U)
/*! RF_CMC_BLE_WKUP_STATUS - RF_CMC BLE Wakeup status */
#define RFMC_RF2P4GHZ_WKUP_SRC_RF_CMC_BLE_WKUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RFMC_RF2P4GHZ_WKUP_SRC_RF_CMC_BLE_WKUP_STATUS_SHIFT)) & RFMC_RF2P4GHZ_WKUP_SRC_RF_CMC_BLE_WKUP_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RFMC_Register_Masks */


/*!
 * @}
 */ /* end of group RFMC_Peripheral_Access_Layer */


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


#endif  /* PERI_RFMC_H_ */

