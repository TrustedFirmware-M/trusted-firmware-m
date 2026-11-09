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
**         CMSIS Peripheral Access Layer for CIU2
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
 * @file PERI_CIU2.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for CIU2
 *
 * CMSIS Peripheral Access Layer for CIU2
 */

#if !defined(PERI_CIU2_H_)
#define PERI_CIU2_H_                             /**< Symbol preventing repeated inclusion */

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
   -- CIU2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CIU2_Peripheral_Access_Layer CIU2 Peripheral Access Layer
 * @{
 */

/** CIU2 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[384];
  __IO uint32_t CIU2_BTU_CTRL;                     /**< BTU Control and Status, offset: 0x180 */
       uint8_t RESERVED_1[20];
  __IO uint32_t CIU2_BTU_ECO_CTRL;                 /**< BTU ECO Control, offset: 0x198 */
       uint8_t RESERVED_2[4];
  __IO uint32_t CIU2_INT_MASK;                     /**< CIU2 Interrupt Mask, offset: 0x1A0 */
  __IO uint32_t CIU2_INT_SELECT;                   /**< CIU2 Interrupt Select, offset: 0x1A4 */
  __IO uint32_t CIU2_INT_EVENT_MASK;               /**< CIU2 Interrupt Event Mask, offset: 0x1A8 */
  __I  uint32_t CIU2_INT_STATUS;                   /**< CIU2 Interrupt Status, offset: 0x1AC */
       uint8_t RESERVED_3[144];
  __IO uint32_t CIU2_TESTBUS_CTRL;                 /**< CPU2 debug register, offset: 0x240 */
       uint8_t RESERVED_4[12];
  __IO uint32_t CIU2_LBC_CTRL;                     /**< LBC Control and Status, offset: 0x250 */
  __IO uint32_t CIU2_LBC_SLPCLK_NCO;               /**< LBC NCO Step for Sleep Clock, offset: 0x254 */
} CIU2_Type;

/* ----------------------------------------------------------------------------
   -- CIU2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CIU2_Register_Masks CIU2 Register Masks
 * @{
 */

/*! @name CIU2_BTU_CTRL - BTU Control and Status */
/*! @{ */

#define CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_MASK    (0x1U)
#define CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_SHIFT   (0U)
/*! btu_cipher_en - Bluetooth Cipher Logic */
#define CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_SHIFT)) & CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_MASK)

#define CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_MASK (0x2U)
#define CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_SHIFT (1U)
/*! dbus_high_speed_sel - Dbus High Speed Select Signal for Greater than 4 MHz */
#define CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_SHIFT)) & CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_MASK)

#define CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_MASK       (0xCU)
#define CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_SHIFT      (2U)
/*! bt_clk_sel - Bluetooth sys Clock Select */
#define CIU2_CIU2_BTU_CTRL_BT_CLK_SEL(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_SHIFT)) & CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_MASK)

#define CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_MASK    (0x700U)
#define CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_SHIFT   (8U)
/*! bt_ip_ser_sel - bt_ip_ser_sel */
#define CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_SHIFT)) & CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_MASK)

#define CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_MASK    (0x80000000U)
#define CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_SHIFT   (31U)
/*! btu_mc_wakeup - BTU MC_Wakeup Status */
#define CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_SHIFT)) & CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_MASK)
/*! @} */

/*! @name CIU2_BTU_ECO_CTRL - BTU ECO Control */
/*! @{ */

#define CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_MASK     (0xFFFFFFFFU)
#define CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_SHIFT    (0U)
/*! eco_bits - Reserved */
#define CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_SHIFT)) & CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_MASK)
/*! @} */

/*! @name CIU2_INT_MASK - CIU2 Interrupt Mask */
/*! @{ */

#define CIU2_CIU2_INT_MASK_MASK_MASK             (0xFFFFFFFFU)
#define CIU2_CIU2_INT_MASK_MASK_SHIFT            (0U)
/*! mask - Interrupt Mask for CIU2 Interrupts */
#define CIU2_CIU2_INT_MASK_MASK(x)               (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_MASK_MASK_SHIFT)) & CIU2_CIU2_INT_MASK_MASK_MASK)
/*! @} */

/*! @name CIU2_INT_SELECT - CIU2 Interrupt Select */
/*! @{ */

#define CIU2_CIU2_INT_SELECT_SEL_MASK            (0xFFFFFFFFU)
#define CIU2_CIU2_INT_SELECT_SEL_SHIFT           (0U)
/*! sel - Interrupt Read/Write Clear for CIU2 Interrupts */
#define CIU2_CIU2_INT_SELECT_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_SELECT_SEL_SHIFT)) & CIU2_CIU2_INT_SELECT_SEL_MASK)
/*! @} */

/*! @name CIU2_INT_EVENT_MASK - CIU2 Interrupt Event Mask */
/*! @{ */

#define CIU2_CIU2_INT_EVENT_MASK_MASK_MASK       (0xFFFFFFFFU)
#define CIU2_CIU2_INT_EVENT_MASK_MASK_SHIFT      (0U)
/*! mask - Interrupt Event Mask for CIU2 Interrupts */
#define CIU2_CIU2_INT_EVENT_MASK_MASK(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_EVENT_MASK_MASK_SHIFT)) & CIU2_CIU2_INT_EVENT_MASK_MASK_MASK)
/*! @} */

/*! @name CIU2_INT_STATUS - CIU2 Interrupt Status */
/*! @{ */

#define CIU2_CIU2_INT_STATUS_CIU_ISR_MASK        (0xFFFFFFFFU)
#define CIU2_CIU2_INT_STATUS_CIU_ISR_SHIFT       (0U)
/*! ciu_isr - CIU2 Interrupt Status (ISR) */
#define CIU2_CIU2_INT_STATUS_CIU_ISR(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_STATUS_CIU_ISR_SHIFT)) & CIU2_CIU2_INT_STATUS_CIU_ISR_MASK)
/*! @} */

/*! @name CIU2_TESTBUS_CTRL - CPU2 debug register */
/*! @{ */

#define CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_MASK  (0xFU)
#define CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_SHIFT (0U)
/*! testbus_sel - Select testbus debug output */
#define CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_SHIFT)) & CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_MASK)
/*! @} */

/*! @name CIU2_LBC_CTRL - LBC Control and Status */
/*! @{ */

#define CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_MASK       (0x1U)
#define CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_SHIFT      (0U)
/*! lbc_nco_en - LBC NCO Enable Signal */
#define CIU2_CIU2_LBC_CTRL_LBC_NCO_EN(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_SHIFT)) & CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_MASK)

#define CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_MASK   (0x60U)
#define CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_SHIFT  (5U)
/*! lbc_debug_ctrl - LBC Debug Control Signal */
#define CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_SHIFT)) & CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_MASK)

#define CIU2_CIU2_LBC_CTRL_DEJIT_EN_MASK         (0x10000U)
#define CIU2_CIU2_LBC_CTRL_DEJIT_EN_SHIFT        (16U)
/*! dejit_en - De-jitter Enable */
#define CIU2_CIU2_LBC_CTRL_DEJIT_EN(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_DEJIT_EN_SHIFT)) & CIU2_CIU2_LBC_CTRL_DEJIT_EN_MASK)

#define CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_MASK       (0x20000U)
#define CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_SHIFT      (17U)
/*! auto_dejit - Auto de-jitter */
#define CIU2_CIU2_LBC_CTRL_AUTO_DEJIT(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_SHIFT)) & CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_MASK)

#define CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_MASK      (0x40000U)
#define CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_SHIFT     (18U)
/*! man_sel_nco - Manual select NCO */
#define CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO(x)        (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_SHIFT)) & CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_MASK)

#define CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_MASK  (0x800000U)
#define CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_SHIFT (23U)
/*! nco_lpo_ramp_dn - Status nco_lpo_ramp_dn */
#define CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_SHIFT)) & CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_MASK)

#define CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_MASK (0x1000000U)
#define CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_SHIFT (24U)
/*! ref_lpo_clk_good - Status ref_lpo_clk_good */
#define CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_SHIFT)) & CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_MASK)

#define CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_MASK  (0x2000000U)
#define CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_SHIFT (25U)
/*! ref_lpo_ramp_dn - Status ref_lpo_ramp_dn */
#define CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_SHIFT)) & CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_MASK)

#define CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_MASK  (0x4000000U)
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_SHIFT (26U)
/*! lpo_clk_sel_fsm - Status lpo_clk_sel_fsm */
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_SHIFT)) & CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_MASK)

#define CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_MASK  (0xF8000000U)
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_SHIFT (27U)
/*! lpo_clk_3k2_cnt - Status lpo_clk_3k2_cnt, 3.2KHz Count */
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_SHIFT)) & CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_MASK)
/*! @} */

/*! @name CIU2_LBC_SLPCLK_NCO - LBC NCO Step for Sleep Clock */
/*! @{ */

#define CIU2_CIU2_LBC_SLPCLK_NCO_STEP_MASK       (0xFFFFFFFFU)
#define CIU2_CIU2_LBC_SLPCLK_NCO_STEP_SHIFT      (0U)
/*! step - LBC NCO step for sleep clock. Please refer to design spreadsheet for more details. */
#define CIU2_CIU2_LBC_SLPCLK_NCO_STEP(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_SLPCLK_NCO_STEP_SHIFT)) & CIU2_CIU2_LBC_SLPCLK_NCO_STEP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CIU2_Register_Masks */


/*!
 * @}
 */ /* end of group CIU2_Peripheral_Access_Layer */


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


#endif  /* PERI_CIU2_H_ */

