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
**         CMSIS Peripheral Access Layer for USBNC
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
 * @file PERI_USBNC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(PERI_USBNC_H_)
#define PERI_USBNC_H_                            /**< Symbol preventing repeated inclusion */

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
   -- USBNC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Peripheral_Access_Layer USBNC Peripheral Access Layer
 * @{
 */

/** USBNC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL1;                             /**< USB OTG Control 1, offset: 0x0 */
  __IO uint32_t CTRL2;                             /**< USB OTG Control 2, offset: 0x4 */
       uint8_t RESERVED_0[40];
  __IO uint32_t UTMIPHY_CFG1;                      /**< PHY Configure 1, offset: 0x30 */
} USBNC_Type;

/* ----------------------------------------------------------------------------
   -- USBNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Register_Masks USBNC Register Masks
 * @{
 */

/*! @name CTRL1 - USB OTG Control 1 */
/*! @{ */

#define USBNC_CTRL1_OVER_CUR_DIS_MASK            (0x80U)
#define USBNC_CTRL1_OVER_CUR_DIS_SHIFT           (7U)
/*! OVER_CUR_DIS - OVER_CUR_DIS
 *  0b0..Enables overcurrent detection
 *  0b1..Disables overcurrent detection
 */
#define USBNC_CTRL1_OVER_CUR_DIS(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_DIS_SHIFT)) & USBNC_CTRL1_OVER_CUR_DIS_MASK)

#define USBNC_CTRL1_OVER_CUR_POL_MASK            (0x100U)
#define USBNC_CTRL1_OVER_CUR_POL_SHIFT           (8U)
/*! OVER_CUR_POL - OVER_CUR_POL
 *  0b0..High active (high on this signal represents an overcurrent condition)
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 */
#define USBNC_CTRL1_OVER_CUR_POL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_POL_SHIFT)) & USBNC_CTRL1_OVER_CUR_POL_MASK)

#define USBNC_CTRL1_PWR_POL_MASK                 (0x200U)
#define USBNC_CTRL1_PWR_POL_SHIFT                (9U)
/*! PWR_POL - PWR_POL
 *  0b0..PMIC Power Pin is Low active.
 *  0b1..PMIC Power Pin is High active.
 */
#define USBNC_CTRL1_PWR_POL(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_PWR_POL_SHIFT)) & USBNC_CTRL1_PWR_POL_MASK)

#define USBNC_CTRL1_WIE_MASK                     (0x400U)
#define USBNC_CTRL1_WIE_SHIFT                    (10U)
/*! WIE - WIE
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define USBNC_CTRL1_WIE(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIE_SHIFT)) & USBNC_CTRL1_WIE_MASK)

#define USBNC_CTRL1_WKUP_SW_EN_MASK              (0x4000U)
#define USBNC_CTRL1_WKUP_SW_EN_SHIFT             (14U)
/*! WKUP_SW_EN - WKUP_SW_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CTRL1_WKUP_SW_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_EN_SHIFT)) & USBNC_CTRL1_WKUP_SW_EN_MASK)

#define USBNC_CTRL1_WKUP_SW_MASK                 (0x8000U)
#define USBNC_CTRL1_WKUP_SW_SHIFT                (15U)
/*! WKUP_SW - WKUP_SW
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_CTRL1_WKUP_SW(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_SHIFT)) & USBNC_CTRL1_WKUP_SW_MASK)

#define USBNC_CTRL1_WKUP_ID_EN_MASK              (0x10000U)
#define USBNC_CTRL1_WKUP_ID_EN_SHIFT             (16U)
/*! WKUP_ID_EN - WKUP_ID_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CTRL1_WKUP_ID_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_ID_EN_SHIFT)) & USBNC_CTRL1_WKUP_ID_EN_MASK)

#define USBNC_CTRL1_WKUP_VBUS_EN_MASK            (0x20000U)
#define USBNC_CTRL1_WKUP_VBUS_EN_SHIFT           (17U)
/*! WKUP_VBUS_EN - WKUP_VBUS_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CTRL1_WKUP_VBUS_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_VBUS_EN_SHIFT)) & USBNC_CTRL1_WKUP_VBUS_EN_MASK)

#define USBNC_CTRL1_WKUP_DPDM_EN_MASK            (0x20000000U)
#define USBNC_CTRL1_WKUP_DPDM_EN_SHIFT           (29U)
/*! WKUP_DPDM_EN - Wake-up on DP/DM change enable
 *  0b0..DP/DM changes wake-up to be disabled only when VBUS is 0.
 *  0b1..(Default) DP/DM changes wake-up to be enabled, it is for device only.
 */
#define USBNC_CTRL1_WKUP_DPDM_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_DPDM_EN_SHIFT)) & USBNC_CTRL1_WKUP_DPDM_EN_MASK)

#define USBNC_CTRL1_WIR_MASK                     (0x80000000U)
#define USBNC_CTRL1_WIR_SHIFT                    (31U)
/*! WIR - WIR
 *  0b0..No wake-up interrupt request received
 *  0b1..Wake-up Interrupt Request received
 */
#define USBNC_CTRL1_WIR(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIR_SHIFT)) & USBNC_CTRL1_WIR_MASK)
/*! @} */

/*! @name CTRL2 - USB OTG Control 2 */
/*! @{ */

#define USBNC_CTRL2_VBUS_SOURCE_SEL_MASK         (0x3U)
#define USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT        (0U)
/*! VBUS_SOURCE_SEL - VBUS_SOURCE_SEL
 *  0b00..vbus_valid
 *  0b01..sess_valid
 *  0b10..sess_valid
 *  0b11..sess_valid
 */
#define USBNC_CTRL2_VBUS_SOURCE_SEL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT)) & USBNC_CTRL2_VBUS_SOURCE_SEL_MASK)

#define USBNC_CTRL2_AUTURESUME_EN_MASK           (0x4U)
#define USBNC_CTRL2_AUTURESUME_EN_SHIFT          (2U)
/*! AUTURESUME_EN - Auto Resume Enable
 *  0b0..Default
 */
#define USBNC_CTRL2_AUTURESUME_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_AUTURESUME_EN_SHIFT)) & USBNC_CTRL2_AUTURESUME_EN_MASK)

#define USBNC_CTRL2_LOWSPEED_EN_MASK             (0x8U)
#define USBNC_CTRL2_LOWSPEED_EN_SHIFT            (3U)
/*! LOWSPEED_EN - Low speed enable
 *  0b0..Default
 */
#define USBNC_CTRL2_LOWSPEED_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_LOWSPEED_EN_SHIFT)) & USBNC_CTRL2_LOWSPEED_EN_MASK)

#define USBNC_CTRL2_SHORT_PKT_EN_MASK            (0x800000U)
#define USBNC_CTRL2_SHORT_PKT_EN_SHIFT           (23U)
/*! SHORT_PKT_EN - Short Packet Interrupt
 *  0b0..Default
 */
#define USBNC_CTRL2_SHORT_PKT_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_SHORT_PKT_EN_SHIFT)) & USBNC_CTRL2_SHORT_PKT_EN_MASK)

#define USBNC_CTRL2_UTMI_CLK_VLD_MASK            (0x80000000U)
#define USBNC_CTRL2_UTMI_CLK_VLD_SHIFT           (31U)
/*! UTMI_CLK_VLD - UTMI_CLK_VLD
 *  0b0..Default
 */
#define USBNC_CTRL2_UTMI_CLK_VLD(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name UTMIPHY_CFG1 - PHY Configure 1 */
/*! @{ */

#define USBNC_UTMIPHY_CFG1_COMPDISTUNE0_MASK     (0x70U)
#define USBNC_UTMIPHY_CFG1_COMPDISTUNE0_SHIFT    (4U)
/*! COMPDISTUNE0 - Disconnect Threshold Adjustment
 *  0b000..-9.71%
 *  0b001..-6.85%
 *  0b010..-3.36%
 *  0b011..0, Design default
 *  0b100..+4.04%
 *  0b101..+8.22%
 *  0b110..+13.18%
 *  0b111..+18.39%
 */
#define USBNC_UTMIPHY_CFG1_COMPDISTUNE0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_COMPDISTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_COMPDISTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_SQRXTUNE0_MASK        (0x380U)
#define USBNC_UTMIPHY_CFG1_SQRXTUNE0_SHIFT       (7U)
/*! SQRXTUNE0 - Squelch Threshold Adjustment
 *  0b000..+15.19%
 *  0b001..+10.04%
 *  0b010..+5.14%
 *  0b011..0, design default
 *  0b100..-5.04%
 *  0b101..-10.19%
 *  0b110..-15.09%
 *  0b111..-20.24%
 */
#define USBNC_UTMIPHY_CFG1_SQRXTUNE0(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_SQRXTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_SQRXTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_OTGTUNE0_MASK         (0x1C00U)
#define USBNC_UTMIPHY_CFG1_OTGTUNE0_SHIFT        (10U)
/*! OTGTUNE0 - VBUS Valid Threshold Adjustment
 *  0b000..-9%
 *  0b001..-6%
 *  0b010..-3%
 *  0b011..0, Design default
 *  0b100..+3%
 *  0b101..+6%
 *  0b110..+9%
 *  0b111..+12%
 */
#define USBNC_UTMIPHY_CFG1_OTGTUNE0(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_OTGTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_OTGTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_TXHSXVTUNE0_MASK      (0x6000U)
#define USBNC_UTMIPHY_CFG1_TXHSXVTUNE0_SHIFT     (13U)
/*! TXHSXVTUNE0 - Transmitter High-Speed Crossover Adjustment
 *  0b00..Reserved
 *  0b01..-17.31 mV
 *  0b10..-16.69 mV
 *  0b11..0, design default
 */
#define USBNC_UTMIPHY_CFG1_TXHSXVTUNE0(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_TXHSXVTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_TXHSXVTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_PHY_POR_SW_MASK       (0x8000U)
#define USBNC_UTMIPHY_CFG1_PHY_POR_SW_SHIFT      (15U)
/*! PHY_POR_SW - PHY software POR
 *  0b0..Do not perform the Power-On Reset by software.
 *  0b1..Perform the Power-On Reset by software.
 */
#define USBNC_UTMIPHY_CFG1_PHY_POR_SW(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_PHY_POR_SW_SHIFT)) & USBNC_UTMIPHY_CFG1_PHY_POR_SW_MASK)

#define USBNC_UTMIPHY_CFG1_TXFSLSTUNE0_MASK      (0xF0000U)
#define USBNC_UTMIPHY_CFG1_TXFSLSTUNE0_SHIFT     (16U)
/*! TXFSLSTUNE0 - FS/LS Source Impedance Adjustment
 *  0b0000..+6.27%
 *  0b0001..+3.02%
 *  0b0011..0, design default
 *  0b0111..-3.23%
 *  0b1111..-6.25%
 */
#define USBNC_UTMIPHY_CFG1_TXFSLSTUNE0(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_TXFSLSTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_TXFSLSTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_TXVREFTUNE0_MASK      (0xF00000U)
#define USBNC_UTMIPHY_CFG1_TXVREFTUNE0_SHIFT     (20U)
/*! TXVREFTUNE0 - HS DC Voltage Level Adjustment
 *  0b0000..-5.88%
 *  0b0001..-3.92%
 *  0b0010..-1.96%
 *  0b0011..0, design default
 *  0b0100..+1.96%
 *  0b0101..+3.92%
 *  0b0110..+5.88%
 *  0b0111..+7.84%
 *  0b1000..+9.80%
 *  0b1001..+11.75%
 *  0b1010..+13.71%
 *  0b1011..+15.67%
 *  0b1100..+17.63%
 *  0b1101..+19.59%
 *  0b1110..+21.55%
 *  0b1111..+23.51%
 */
#define USBNC_UTMIPHY_CFG1_TXVREFTUNE0(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_TXVREFTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_TXVREFTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_TXRISETUNE0_MASK      (0x3000000U)
#define USBNC_UTMIPHY_CFG1_TXRISETUNE0_SHIFT     (24U)
/*! TXRISETUNE0 - HS Transmitter Rise/Fall Time Adjustment
 *  0b00..+3.46%
 *  0b01..0, Design default
 *  0b10..-1.47%
 *  0b11..-3.33%
 */
#define USBNC_UTMIPHY_CFG1_TXRISETUNE0(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_TXRISETUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_TXRISETUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_TXRESTUNE0_MASK       (0xC000000U)
#define USBNC_UTMIPHY_CFG1_TXRESTUNE0_SHIFT      (26U)
/*! TXRESTUNE0 - USB Source Impedance Adjustment
 *  0b00..Source impedance is increased by approximately 3.01 ohm
 *  0b01..00, design default
 *  0b10..Source impedance is decreased by approximately 1.32 ohm
 *  0b11..Source impedance is decreased by approximately 3.71 ohm
 */
#define USBNC_UTMIPHY_CFG1_TXRESTUNE0(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_TXRESTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_TXRESTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_TXPREEMPAMPTUNE0_MASK (0x30000000U)
#define USBNC_UTMIPHY_CFG1_TXPREEMPAMPTUNE0_SHIFT (28U)
/*! TXPREEMPAMPTUNE0 - HS Transmitter Pre-Emphasis Current Control
 *  0b00..HS Transmitter pre-emphasis is disabled.
 *  0b01..HS Transmitter pre-emphasis circuit sources 1x pre-emphasis current.
 *  0b10..HS Transmitter pre-emphasis circuit sources 2x pre-emphasis current.
 *  0b11..HS Transmitter pre-emphasis circuit sources 3x pre-emphasis current.
 */
#define USBNC_UTMIPHY_CFG1_TXPREEMPAMPTUNE0(x)   (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_TXPREEMPAMPTUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_TXPREEMPAMPTUNE0_MASK)

#define USBNC_UTMIPHY_CFG1_TXPREEMPPULSETUNE0_MASK (0x40000000U)
#define USBNC_UTMIPHY_CFG1_TXPREEMPPULSETUNE0_SHIFT (30U)
/*! TXPREEMPPULSETUNE0 - HS Transmitter Pre-Emphasis Duration Control
 *  0b0..Design default. Long pre-emphasis current duration
 *  0b1..Short pre-emphasis current duration
 */
#define USBNC_UTMIPHY_CFG1_TXPREEMPPULSETUNE0(x) (((uint32_t)(((uint32_t)(x)) << USBNC_UTMIPHY_CFG1_TXPREEMPPULSETUNE0_SHIFT)) & USBNC_UTMIPHY_CFG1_TXPREEMPPULSETUNE0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBNC_Register_Masks */


/*!
 * @}
 */ /* end of group USBNC_Peripheral_Access_Layer */


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


#endif  /* PERI_USBNC_H_ */
