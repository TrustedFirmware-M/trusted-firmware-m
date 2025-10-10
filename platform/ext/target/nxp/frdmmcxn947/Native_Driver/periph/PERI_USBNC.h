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
 * @file PERI_USBNC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(PERI_USBNC_H_)
#define PERI_USBNC_H_                            /**< Symbol preventing repeated inclusion */

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
       uint8_t RESERVED_0[8];
  __IO uint32_t HSIC_CTRL;                         /**< USB Host HSIC Control, offset: 0x10 */
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
/*! OVER_CUR_DIS - Disable Overcurrent Detection
 *  0b0..Enables
 *  0b1..Disables
 */
#define USBNC_CTRL1_OVER_CUR_DIS(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_DIS_SHIFT)) & USBNC_CTRL1_OVER_CUR_DIS_MASK)

#define USBNC_CTRL1_OVER_CUR_POL_MASK            (0x100U)
#define USBNC_CTRL1_OVER_CUR_POL_SHIFT           (8U)
/*! OVER_CUR_POL - Polarity of Overcurrent
 *  0b0..High active (high on this signal represents an overcurrent condition)
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 */
#define USBNC_CTRL1_OVER_CUR_POL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_POL_SHIFT)) & USBNC_CTRL1_OVER_CUR_POL_MASK)

#define USBNC_CTRL1_PWR_POL_MASK                 (0x200U)
#define USBNC_CTRL1_PWR_POL_SHIFT                (9U)
/*! PWR_POL - Power Polarity
 *  0b0..PMIC Power Pin is Low active.
 *  0b1..PMIC Power Pin is High active.
 */
#define USBNC_CTRL1_PWR_POL(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_PWR_POL_SHIFT)) & USBNC_CTRL1_PWR_POL_MASK)

#define USBNC_CTRL1_WIE_MASK                     (0x400U)
#define USBNC_CTRL1_WIE_SHIFT                    (10U)
/*! WIE - Wake-up Interrupt Enable
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define USBNC_CTRL1_WIE(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIE_SHIFT)) & USBNC_CTRL1_WIE_MASK)

#define USBNC_CTRL1_WKUP_SW_EN_MASK              (0x4000U)
#define USBNC_CTRL1_WKUP_SW_EN_SHIFT             (14U)
/*! WKUP_SW_EN - Software Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_WKUP_SW_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_EN_SHIFT)) & USBNC_CTRL1_WKUP_SW_EN_MASK)

#define USBNC_CTRL1_WKUP_SW_MASK                 (0x8000U)
#define USBNC_CTRL1_WKUP_SW_SHIFT                (15U)
/*! WKUP_SW - Software Wake-up
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_CTRL1_WKUP_SW(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_SHIFT)) & USBNC_CTRL1_WKUP_SW_MASK)

#define USBNC_CTRL1_WKUP_ID_EN_MASK              (0x10000U)
#define USBNC_CTRL1_WKUP_ID_EN_SHIFT             (16U)
/*! WKUP_ID_EN - Wake-up on ID Change Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_WKUP_ID_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_ID_EN_SHIFT)) & USBNC_CTRL1_WKUP_ID_EN_MASK)

#define USBNC_CTRL1_WKUP_VBUS_EN_MASK            (0x20000U)
#define USBNC_CTRL1_WKUP_VBUS_EN_SHIFT           (17U)
/*! WKUP_VBUS_EN - Wake-up on VBUS Change Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_WKUP_VBUS_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_VBUS_EN_SHIFT)) & USBNC_CTRL1_WKUP_VBUS_EN_MASK)

#define USBNC_CTRL1_WKUP_DPDM_EN_MASK            (0x20000000U)
#define USBNC_CTRL1_WKUP_DPDM_EN_SHIFT           (29U)
/*! WKUP_DPDM_EN - Wake-up on DPDM Change Enable
 *  0b0..DPDM changes wake-up to be disabled only when VBUS is 0
 *  0b1..DPDM changes wake-up to be enabled, it is for device only
 */
#define USBNC_CTRL1_WKUP_DPDM_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_DPDM_EN_SHIFT)) & USBNC_CTRL1_WKUP_DPDM_EN_MASK)

#define USBNC_CTRL1_WIR_MASK                     (0x80000000U)
#define USBNC_CTRL1_WIR_SHIFT                    (31U)
/*! WIR - Wake-up Interrupt Request
 *  0b0..No request received
 *  0b1..Request received
 */
#define USBNC_CTRL1_WIR(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIR_SHIFT)) & USBNC_CTRL1_WIR_MASK)
/*! @} */

/*! @name CTRL2 - USB OTG Control 2 */
/*! @{ */

#define USBNC_CTRL2_VBUS_SOURCE_SEL_MASK         (0x3U)
#define USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT        (0U)
/*! VBUS_SOURCE_SEL - VBUS Source Select
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
/*! LOWSPEED_EN - Low Speed Enable
 *  0b0..Default
 */
#define USBNC_CTRL2_LOWSPEED_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_LOWSPEED_EN_SHIFT)) & USBNC_CTRL2_LOWSPEED_EN_MASK)

#define USBNC_CTRL2_UTMI_CLK_VLD_MASK            (0x80000000U)
#define USBNC_CTRL2_UTMI_CLK_VLD_SHIFT           (31U)
/*! UTMI_CLK_VLD - UTMI Clock Valid
 *  0b0..Default
 */
#define USBNC_CTRL2_UTMI_CLK_VLD(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name HSIC_CTRL - USB Host HSIC Control */
/*! @{ */

#define USBNC_HSIC_CTRL_HSIC_CLK_ON_MASK         (0x800U)
#define USBNC_HSIC_CTRL_HSIC_CLK_ON_SHIFT        (11U)
/*! HSIC_CLK_ON - HSIC Clock ON
 *  0b0..Inactive
 *  0b1..Active
 */
#define USBNC_HSIC_CTRL_HSIC_CLK_ON(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_CTRL_HSIC_CLK_ON_SHIFT)) & USBNC_HSIC_CTRL_HSIC_CLK_ON_MASK)

#define USBNC_HSIC_CTRL_HSIC_EN_MASK             (0x1000U)
#define USBNC_HSIC_CTRL_HSIC_EN_SHIFT            (12U)
/*! HSIC_EN - Host HSIC Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBNC_HSIC_CTRL_HSIC_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_CTRL_HSIC_EN_SHIFT)) & USBNC_HSIC_CTRL_HSIC_EN_MASK)

#define USBNC_HSIC_CTRL_CLK_VLD_MASK             (0x80000000U)
#define USBNC_HSIC_CTRL_CLK_VLD_SHIFT            (31U)
/*! CLK_VLD - Clock Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define USBNC_HSIC_CTRL_CLK_VLD(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_CTRL_CLK_VLD_SHIFT)) & USBNC_HSIC_CTRL_CLK_VLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBNC_Register_Masks */

/* Backward compatibility */
#define USB_OTGn_CTRL     CTRL1
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_MASK     USBNC_CTRL1_OVER_CUR_DIS_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_SHIFT     USBNC_CTRL1_OVER_CUR_DIS_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS(x)     USBNC_CTRL1_OVER_CUR_DIS(x)
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_MASK     USBNC_CTRL1_OVER_CUR_POL_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_SHIFT     USBNC_CTRL1_OVER_CUR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL(x)     USBNC_CTRL1_OVER_CUR_POL(x)
#define USBNC_USB_OTGn_CTRL_PWR_POL_MASK     USBNC_CTRL1_PWR_POL_MASK
#define USBNC_USB_OTGn_CTRL_PWR_POL_SHIFT     USBNC_CTRL1_PWR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_PWR_POL(x)     USBNC_CTRL1_PWR_POL(x)
#define USBNC_USB_OTGn_CTRL_WIE_MASK     USBNC_CTRL1_WIE_MASK
#define USBNC_USB_OTGn_CTRL_WIE_SHIFT     USBNC_CTRL1_WIE_SHIFT
#define USBNC_USB_OTGn_CTRL_WIE(x)     USBNC_CTRL1_WIE(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_MASK     USBNC_CTRL1_WKUP_SW_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_SHIFT     USBNC_CTRL1_WKUP_SW_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN(x)     USBNC_CTRL1_WKUP_SW_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_MASK     USBNC_CTRL1_WKUP_SW_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_SHIFT     USBNC_CTRL1_WKUP_SW_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW(x)     USBNC_CTRL1_WKUP_SW(x)
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_MASK     USBNC_CTRL1_WKUP_ID_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_SHIFT     USBNC_CTRL1_WKUP_ID_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN(x)     USBNC_CTRL1_WKUP_ID_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_MASK     USBNC_CTRL1_WKUP_VBUS_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_SHIFT     USBNC_CTRL1_WKUP_VBUS_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN(x)     USBNC_CTRL1_WKUP_VBUS_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK     USBNC_CTRL1_WKUP_DPDM_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT     USBNC_CTRL1_WKUP_DPDM_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN(x)     USBNC_CTRL1_WKUP_DPDM_EN(x)
#define USBNC_USB_OTGn_CTRL_WIR_MASK     USBNC_CTRL1_WIR_MASK
#define USBNC_USB_OTGn_CTRL_WIR_SHIFT     USBNC_CTRL1_WIR_SHIFT
#define USBNC_USB_OTGn_CTRL_WIR(x)     USBNC_CTRL1_WIR(x)


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

