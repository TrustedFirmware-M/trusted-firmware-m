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
**         CMSIS Peripheral Access Layer for SPC
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
 * @file PERI_SPC.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for SPC
 *
 * CMSIS Peripheral Access Layer for SPC
 */

#if !defined(PERI_SPC_H_)
#define PERI_SPC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- SPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPC_Peripheral_Access_Layer SPC Peripheral Access Layer
 * @{
 */

/** SPC - Size of Registers Arrays */
#define SPC_PD_STATUS_COUNT                       4u

/** SPC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t SC;                                /**< Status Control, offset: 0x10 */
  __IO uint32_t CNTRL;                             /**< SPC Regulator Control, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t LPREQ_CFG;                         /**< Low-Power Request Configuration, offset: 0x1C */
  __IO uint32_t CFG;                               /**< SPC Configuration, offset: 0x20 */
       uint8_t RESERVED_2[12];
  __IO uint32_t PD_STATUS[SPC_PD_STATUS_COUNT];    /**< SPC Power Domain Mode Status, array offset: 0x30, array step: 0x4 */
  __IO uint32_t SRAMCTL;                           /**< SRAM Control, offset: 0x40 */
       uint8_t RESERVED_3[28];
  __IO uint32_t HP_CNFG_CTRL;                      /**< High Power Config Control, offset: 0x60 */
       uint8_t RESERVED_4[124];
  __IO uint32_t WAKEUP;                            /**< General Purpose Wake-up, offset: 0xE0 */
       uint8_t RESERVED_5[28];
  __IO uint32_t ACTIVE_CFG;                        /**< Active Power Mode Configuration, offset: 0x100 */
  __IO uint32_t ACTIVE_CFG1;                       /**< Active Power Mode Configuration 1, offset: 0x104 */
  __IO uint32_t LP_CFG;                            /**< Low-Power Mode Configuration, offset: 0x108 */
  __IO uint32_t LP_CFG1;                           /**< Low Power Mode Configuration 1, offset: 0x10C */
  __IO uint32_t HP_CFG;                            /**< High Power Mode Configuration, offset: 0x110 */
       uint8_t RESERVED_6[12];
  __IO uint32_t LPWKUP_DELAY;                      /**< Low Power Wake-Up Delay, offset: 0x120 */
  __IO uint32_t ACTIVE_VDELAY;                     /**< Active Voltage Trim Delay, offset: 0x124 */
       uint8_t RESERVED_7[8];
  __IO uint32_t VD_STAT;                           /**< Voltage Detect Status, offset: 0x130 */
  __IO uint32_t VD_CORE_CFG;                       /**< Core Voltage Detect Configuration, offset: 0x134 */
  __IO uint32_t VD_VDD1P8_CFG;                     /**< VDD 1p8 Voltage Detect Configuration, offset: 0x138 */
  __IO uint32_t VD_IO_CFG;                         /**< IO Voltage Detect Configuration, offset: 0x13C */
  __IO uint32_t EVD_CFG;                           /**< External Voltage Domain Configuration, offset: 0x140 */
  __IO uint32_t VDD_GLITCH_DETECT_SC;              /**< Glitch Detect Status Control, offset: 0x144 */
       uint8_t RESERVED_8[440];
  __IO uint32_t CORELDO_CFG;                       /**< LDO_CORE Configuration, offset: 0x300 */
       uint8_t RESERVED_9[508];
  __IO uint32_t DCDC_CFG;                          /**< DCDC Configuration, offset: 0x500 */
} SPC_Type;

/* ----------------------------------------------------------------------------
   -- SPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPC_Register_Masks SPC Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define SPC_VERID_FEATURE_MASK                   (0xFFFFU)
#define SPC_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features
 */
#define SPC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_VERID_FEATURE_SHIFT)) & SPC_VERID_FEATURE_MASK)

#define SPC_VERID_MINOR_MASK                     (0xFF0000U)
#define SPC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define SPC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << SPC_VERID_MINOR_SHIFT)) & SPC_VERID_MINOR_MASK)

#define SPC_VERID_MAJOR_MASK                     (0xFF000000U)
#define SPC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define SPC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << SPC_VERID_MAJOR_SHIFT)) & SPC_VERID_MAJOR_MASK)
/*! @} */

/*! @name SC - Status Control */
/*! @{ */

#define SPC_SC_BUSY_MASK                         (0x1U)
#define SPC_SC_BUSY_SHIFT                        (0U)
/*! BUSY - SPC Busy Status Flag
 *  0b0..Not busy
 *  0b1..Busy
 */
#define SPC_SC_BUSY(x)                           (((uint32_t)(((uint32_t)(x)) << SPC_SC_BUSY_SHIFT)) & SPC_SC_BUSY_MASK)

#define SPC_SC_SPC_LP_REQ_MASK                   (0x2U)
#define SPC_SC_SPC_LP_REQ_SHIFT                  (1U)
/*! SPC_LP_REQ - SPC Power Mode Configuration Status Flag
 *  0b0..No effect
 *  0b0..SPC is in Active mode; the ACTIVE_CFG register has control
 *  0b1..All power domains requested low-power mode; SPC entered a low-power state; power-mode configuration based on the LP_CFG register
 *  0b1..Clear the flag
 */
#define SPC_SC_SPC_LP_REQ(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_SC_SPC_LP_REQ_SHIFT)) & SPC_SC_SPC_LP_REQ_MASK)

#define SPC_SC_REG_BUSY_MASK                     (0x4U)
#define SPC_SC_REG_BUSY_SHIFT                    (2U)
/*! REG_BUSY - SPC REG Busy Status Flag
 *  0b0..Not busy
 *  0b1..Busy
 */
#define SPC_SC_REG_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << SPC_SC_REG_BUSY_SHIFT)) & SPC_SC_REG_BUSY_MASK)

#define SPC_SC_HP_ACTIVE_MASK                    (0x8U)
#define SPC_SC_HP_ACTIVE_SHIFT                   (3U)
/*! HP_ACTIVE - HP_CFG Select Status Flag
 *  0b0..ACTIVE_CFG selected
 *  0b1..HP_CFG selected
 */
#define SPC_SC_HP_ACTIVE(x)                      (((uint32_t)(((uint32_t)(x)) << SPC_SC_HP_ACTIVE_SHIFT)) & SPC_SC_HP_ACTIVE_MASK)

#define SPC_SC_SPC_LP_MODE_MASK                  (0xF0U)
#define SPC_SC_SPC_LP_MODE_SHIFT                 (4U)
/*! SPC_LP_MODE - Power Domain Low-Power Mode Request
 *  0b0000..Sleep mode with system clock running
 *  0b0001..SLEEP with system clock off
 *  0b0010..DSLEEP with system clock off
 *  0b0100..PDOWN with system clock off
 *  0b1000..DPDOWN with system clock off
 */
#define SPC_SC_SPC_LP_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_SC_SPC_LP_MODE_SHIFT)) & SPC_SC_SPC_LP_MODE_MASK)

#define SPC_SC_ISO_CLR_MASK                      (0xF0000U)
#define SPC_SC_ISO_CLR_SHIFT                     (16U)
/*! ISO_CLR - Isolation Clear Flags */
#define SPC_SC_ISO_CLR(x)                        (((uint32_t)(((uint32_t)(x)) << SPC_SC_ISO_CLR_SHIFT)) & SPC_SC_ISO_CLR_MASK)

#define SPC_SC_SWITCH_STATE_MASK                 (0x80000000U)
#define SPC_SC_SWITCH_STATE_SHIFT                (31U)
/*! SWITCH_STATE - Power Switch State
 *  0b0..Off
 *  0b1..On
 */
#define SPC_SC_SWITCH_STATE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_SC_SWITCH_STATE_SHIFT)) & SPC_SC_SWITCH_STATE_MASK)
/*! @} */

/*! @name CNTRL - SPC Regulator Control */
/*! @{ */

#define SPC_CNTRL_CORELDO_EN_MASK                (0x1U)
#define SPC_CNTRL_CORELDO_EN_SHIFT               (0U)
/*! CORELDO_EN - LDO_CORE Regulator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CNTRL_CORELDO_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_CNTRL_CORELDO_EN_SHIFT)) & SPC_CNTRL_CORELDO_EN_MASK)

#define SPC_CNTRL_DCDC_EN_MASK                   (0x4U)
#define SPC_CNTRL_DCDC_EN_SHIFT                  (2U)
/*! DCDC_EN - DCDC_CORE Regulator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CNTRL_DCDC_EN(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_CNTRL_DCDC_EN_SHIFT)) & SPC_CNTRL_DCDC_EN_MASK)

#define SPC_CNTRL_REG1P8_EN_MASK                 (0x8U)
#define SPC_CNTRL_REG1P8_EN_SHIFT                (3U)
/*! REG1P8_EN - 1.8 Regulator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CNTRL_REG1P8_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_CNTRL_REG1P8_EN_SHIFT)) & SPC_CNTRL_REG1P8_EN_MASK)
/*! @} */

/*! @name LPREQ_CFG - Low-Power Request Configuration */
/*! @{ */

#define SPC_LPREQ_CFG_LPREQOE_MASK               (0x1U)
#define SPC_LPREQ_CFG_LPREQOE_SHIFT              (0U)
/*! LPREQOE - Low-Power Request Output Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LPREQ_CFG_LPREQOE(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_LPREQ_CFG_LPREQOE_SHIFT)) & SPC_LPREQ_CFG_LPREQOE_MASK)

#define SPC_LPREQ_CFG_LPREQPOL_MASK              (0x2U)
#define SPC_LPREQ_CFG_LPREQPOL_SHIFT             (1U)
/*! LPREQPOL - Low-Power Request Output Pin Polarity Control
 *  0b0..High
 *  0b1..Low
 */
#define SPC_LPREQ_CFG_LPREQPOL(x)                (((uint32_t)(((uint32_t)(x)) << SPC_LPREQ_CFG_LPREQPOL_SHIFT)) & SPC_LPREQ_CFG_LPREQPOL_MASK)

#define SPC_LPREQ_CFG_LPREQOV_MASK               (0xCU)
#define SPC_LPREQ_CFG_LPREQOV_SHIFT              (2U)
/*! LPREQOV - Low-Power Request Output Override
 *  0b00..Not forced
 *  0b01..
 *  0b10..Forced low (ignore LPREQPOL settings)
 *  0b11..Forced high (ignore LPREQPOL settings)
 */
#define SPC_LPREQ_CFG_LPREQOV(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_LPREQ_CFG_LPREQOV_SHIFT)) & SPC_LPREQ_CFG_LPREQOV_MASK)
/*! @} */

/*! @name CFG - SPC Configuration */
/*! @{ */

#define SPC_CFG_INTG_PWSWTCH_SLEEP_EN_MASK       (0x1U)
#define SPC_CFG_INTG_PWSWTCH_SLEEP_EN_SHIFT      (0U)
/*! INTG_PWSWTCH_SLEEP_EN - Integrated Power Switch Sleep Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CFG_INTG_PWSWTCH_SLEEP_EN(x)         (((uint32_t)(((uint32_t)(x)) << SPC_CFG_INTG_PWSWTCH_SLEEP_EN_SHIFT)) & SPC_CFG_INTG_PWSWTCH_SLEEP_EN_MASK)

#define SPC_CFG_INTG_PWSWTCH_WKUP_EN_MASK        (0x2U)
#define SPC_CFG_INTG_PWSWTCH_WKUP_EN_SHIFT       (1U)
/*! INTG_PWSWTCH_WKUP_EN - Integrated Power Switch Wake-up Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CFG_INTG_PWSWTCH_WKUP_EN(x)          (((uint32_t)(((uint32_t)(x)) << SPC_CFG_INTG_PWSWTCH_WKUP_EN_SHIFT)) & SPC_CFG_INTG_PWSWTCH_WKUP_EN_MASK)

#define SPC_CFG_INTG_PWSWTCH_SLEEP_ACTIVE_EN_MASK (0x4U)
#define SPC_CFG_INTG_PWSWTCH_SLEEP_ACTIVE_EN_SHIFT (2U)
/*! INTG_PWSWTCH_SLEEP_ACTIVE_EN - Integrated Power Switch Active Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CFG_INTG_PWSWTCH_SLEEP_ACTIVE_EN(x)  (((uint32_t)(((uint32_t)(x)) << SPC_CFG_INTG_PWSWTCH_SLEEP_ACTIVE_EN_SHIFT)) & SPC_CFG_INTG_PWSWTCH_SLEEP_ACTIVE_EN_MASK)

#define SPC_CFG_INTG_PWSWTCH_WKUP_ACTIVE_EN_MASK (0x8U)
#define SPC_CFG_INTG_PWSWTCH_WKUP_ACTIVE_EN_SHIFT (3U)
/*! INTG_PWSWTCH_WKUP_ACTIVE_EN - Integrated Power Switch Wake-up Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CFG_INTG_PWSWTCH_WKUP_ACTIVE_EN(x)   (((uint32_t)(((uint32_t)(x)) << SPC_CFG_INTG_PWSWTCH_WKUP_ACTIVE_EN_SHIFT)) & SPC_CFG_INTG_PWSWTCH_WKUP_ACTIVE_EN_MASK)
/*! @} */

/*! @name PD_STATUS - SPC Power Domain Mode Status */
/*! @{ */

#define SPC_PD_STATUS_PWR_REQ_STATUS_MASK        (0x1U)
#define SPC_PD_STATUS_PWR_REQ_STATUS_SHIFT       (0U)
/*! PWR_REQ_STATUS - Power Request Status Flag
 *  0b0..Did not request
 *  0b1..Requested
 */
#define SPC_PD_STATUS_PWR_REQ_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << SPC_PD_STATUS_PWR_REQ_STATUS_SHIFT)) & SPC_PD_STATUS_PWR_REQ_STATUS_MASK)

#define SPC_PD_STATUS_PD_LP_REQ_MASK             (0x10U)
#define SPC_PD_STATUS_PD_LP_REQ_SHIFT            (4U)
/*! PD_LP_REQ - Power Domain Low Power Request Flag
 *  0b0..Did not request
 *  0b1..Requested
 */
#define SPC_PD_STATUS_PD_LP_REQ(x)               (((uint32_t)(((uint32_t)(x)) << SPC_PD_STATUS_PD_LP_REQ_SHIFT)) & SPC_PD_STATUS_PD_LP_REQ_MASK)

#define SPC_PD_STATUS_LP_MODE_MASK               (0xF00U)
#define SPC_PD_STATUS_LP_MODE_SHIFT              (8U)
/*! LP_MODE - Power Domain Low Power Mode Request
 *  0b0000..SLEEP with system clock running
 *  0b0001..SLEEP with system clock off
 *  0b0010..DSLEEP with system clock off
 *  0b0100..PDOWN with system clock off
 *  0b1000..DPDOWN with system clock off
 */
#define SPC_PD_STATUS_LP_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_PD_STATUS_LP_MODE_SHIFT)) & SPC_PD_STATUS_LP_MODE_MASK)
/*! @} */

/*! @name SRAMCTL - SRAM Control */
/*! @{ */

#define SPC_SRAMCTL_VSM_MASK                     (0x3U)
#define SPC_SRAMCTL_VSM_SHIFT                    (0U)
/*! VSM - Voltage Select Margin
 *  0b00..
 *  0b01..1.0 V
 *  0b10..1.1 V
 *  0b11..SRAM configured for 1.1 V operation
 */
#define SPC_SRAMCTL_VSM(x)                       (((uint32_t)(((uint32_t)(x)) << SPC_SRAMCTL_VSM_SHIFT)) & SPC_SRAMCTL_VSM_MASK)

#define SPC_SRAMCTL_REQ_MASK                     (0x40000000U)
#define SPC_SRAMCTL_REQ_SHIFT                    (30U)
/*! REQ - SRAM Voltage Update Request
 *  0b0..Do not request
 *  0b1..Request
 */
#define SPC_SRAMCTL_REQ(x)                       (((uint32_t)(((uint32_t)(x)) << SPC_SRAMCTL_REQ_SHIFT)) & SPC_SRAMCTL_REQ_MASK)

#define SPC_SRAMCTL_ACK_MASK                     (0x80000000U)
#define SPC_SRAMCTL_ACK_SHIFT                    (31U)
/*! ACK - SRAM Voltage Update Request Acknowledge
 *  0b0..Not acknowledged
 *  0b1..Acknowledged
 */
#define SPC_SRAMCTL_ACK(x)                       (((uint32_t)(((uint32_t)(x)) << SPC_SRAMCTL_ACK_SHIFT)) & SPC_SRAMCTL_ACK_MASK)
/*! @} */

/*! @name HP_CNFG_CTRL - High Power Config Control */
/*! @{ */

#define SPC_HP_CNFG_CTRL_HP_REQ_EN_MASK          (0x1U)
#define SPC_HP_CNFG_CTRL_HP_REQ_EN_SHIFT         (0U)
/*! HP_REQ_EN - High Power Request Enable
 *  0b0..High Power request Disable
 *  0b1..High power reqeust Enable
 */
#define SPC_HP_CNFG_CTRL_HP_REQ_EN(x)            (((uint32_t)(((uint32_t)(x)) << SPC_HP_CNFG_CTRL_HP_REQ_EN_SHIFT)) & SPC_HP_CNFG_CTRL_HP_REQ_EN_MASK)

#define SPC_HP_CNFG_CTRL_OVERRIDE_EN_MASK        (0x2U)
#define SPC_HP_CNFG_CTRL_OVERRIDE_EN_SHIFT       (1U)
/*! OVERRIDE_EN - Override Enable
 *  0b0..Override Disabled
 *  0b1..Override Enabled
 */
#define SPC_HP_CNFG_CTRL_OVERRIDE_EN(x)          (((uint32_t)(((uint32_t)(x)) << SPC_HP_CNFG_CTRL_OVERRIDE_EN_SHIFT)) & SPC_HP_CNFG_CTRL_OVERRIDE_EN_MASK)

#define SPC_HP_CNFG_CTRL_OVERRIDE_SEL_MASK       (0x4U)
#define SPC_HP_CNFG_CTRL_OVERRIDE_SEL_SHIFT      (2U)
/*! OVERRIDE_SEL - Override Select
 *  0b0..Force the HP request to 0
 *  0b1..Force the HP request to 1
 */
#define SPC_HP_CNFG_CTRL_OVERRIDE_SEL(x)         (((uint32_t)(((uint32_t)(x)) << SPC_HP_CNFG_CTRL_OVERRIDE_SEL_SHIFT)) & SPC_HP_CNFG_CTRL_OVERRIDE_SEL_MASK)
/*! @} */

/*! @name WAKEUP - General Purpose Wake-up */
/*! @{ */

#define SPC_WAKEUP_WAKEUP_MASK                   (0xFFFFFFFFU)
#define SPC_WAKEUP_WAKEUP_SHIFT                  (0U)
/*! WAKEUP - Wake-up */
#define SPC_WAKEUP_WAKEUP(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_WAKEUP_WAKEUP_SHIFT)) & SPC_WAKEUP_WAKEUP_MASK)
/*! @} */

/*! @name ACTIVE_CFG - Active Power Mode Configuration */
/*! @{ */

#define SPC_ACTIVE_CFG_CORELDO_VDD_DS_MASK       (0x1U)
#define SPC_ACTIVE_CFG_CORELDO_VDD_DS_SHIFT      (0U)
/*! CORELDO_VDD_DS - LDO_CORE VDD Drive Strength
 *  0b0..Low
 *  0b1..Normal
 */
#define SPC_ACTIVE_CFG_CORELDO_VDD_DS(x)         (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_CORELDO_VDD_DS_SHIFT)) & SPC_ACTIVE_CFG_CORELDO_VDD_DS_MASK)

#define SPC_ACTIVE_CFG_CORELDO_VDD_LVL_MASK      (0xCU)
#define SPC_ACTIVE_CFG_CORELDO_VDD_LVL_SHIFT     (2U)
/*! CORELDO_VDD_LVL - LDO_CORE VDD Regulator Voltage Level
 *  0b00..
 *  0b01..Regulate to mid voltage (1.0 V)
 *  0b10..Regulate to normal voltage (1.1 V)
 *  0b11..Regulate to safe-mode voltage (1.15 V)
 */
#define SPC_ACTIVE_CFG_CORELDO_VDD_LVL(x)        (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_CORELDO_VDD_LVL_SHIFT)) & SPC_ACTIVE_CFG_CORELDO_VDD_LVL_MASK)

#define SPC_ACTIVE_CFG_DCDC_VDD_DS_MASK          (0x300U)
#define SPC_ACTIVE_CFG_DCDC_VDD_DS_SHIFT         (8U)
/*! DCDC_VDD_DS - DCDC VDD Drive Strength
 *  0b01..Low
 *  0b10..Normal
 */
#define SPC_ACTIVE_CFG_DCDC_VDD_DS(x)            (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_DCDC_VDD_DS_SHIFT)) & SPC_ACTIVE_CFG_DCDC_VDD_DS_MASK)

#define SPC_ACTIVE_CFG_DCDC_VDD_LVL_MASK         (0xC00U)
#define SPC_ACTIVE_CFG_DCDC_VDD_LVL_SHIFT        (10U)
/*! DCDC_VDD_LVL - DCDC VDD Regulator Voltage Level
 *  0b00..Low undervoltage (1.25 V)
 *  0b01..Normal voltage (1.35 V)
 *  0b10..Mid voltage (1.45 V)
 *  0b11..Safe-mode voltage (1.8 V)
 */
#define SPC_ACTIVE_CFG_DCDC_VDD_LVL(x)           (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_DCDC_VDD_LVL_SHIFT)) & SPC_ACTIVE_CFG_DCDC_VDD_LVL_MASK)

#define SPC_ACTIVE_CFG_DCDC_VOUT2P5_SEL_MASK     (0x1000U)
#define SPC_ACTIVE_CFG_DCDC_VOUT2P5_SEL_SHIFT    (12U)
/*! DCDC_VOUT2P5_SEL - 2.5 V Output Select
 *  0b0..From DCDC_VDD_LVL register
 *  0b1..2.5 V
 */
#define SPC_ACTIVE_CFG_DCDC_VOUT2P5_SEL(x)       (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_DCDC_VOUT2P5_SEL_SHIFT)) & SPC_ACTIVE_CFG_DCDC_VOUT2P5_SEL_MASK)

#define SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_MASK (0x2000U)
#define SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_SHIFT (13U)
/*! GLITCH_DETECT_DISABLE - Glitch Detect Disable
 *  0b0..Low Voltage Glitch Detect enabled
 *  0b1..Low Voltage Glitch Detect disabled
 */
#define SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_SHIFT)) & SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_MASK)

#define SPC_ACTIVE_CFG_BGMODE_MASK               (0x300000U)
#define SPC_ACTIVE_CFG_BGMODE_SHIFT              (20U)
/*! BGMODE - Bandgap Mode
 *  0b00..Bandgap disabled
 *  0b01..Bandgap enabled, buffer disabled
 *  0b10..Bandgap enabled, buffer enabled
 *  0b11..
 */
#define SPC_ACTIVE_CFG_BGMODE(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_BGMODE_SHIFT)) & SPC_ACTIVE_CFG_BGMODE_MASK)

#define SPC_ACTIVE_CFG_VDD_VD_DISABLE_MASK       (0x800000U)
#define SPC_ACTIVE_CFG_VDD_VD_DISABLE_SHIFT      (23U)
/*! VDD_VD_DISABLE - VDD Voltage Detect Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define SPC_ACTIVE_CFG_VDD_VD_DISABLE(x)         (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_VDD_VD_DISABLE_SHIFT)) & SPC_ACTIVE_CFG_VDD_VD_DISABLE_MASK)

#define SPC_ACTIVE_CFG_CORE_LVDE_MASK            (0x1000000U)
#define SPC_ACTIVE_CFG_CORE_LVDE_SHIFT           (24U)
/*! CORE_LVDE - Core Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_CORE_LVDE(x)              (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_CORE_LVDE_SHIFT)) & SPC_ACTIVE_CFG_CORE_LVDE_MASK)

#define SPC_ACTIVE_CFG_IO_LVDE_MASK              (0x4000000U)
#define SPC_ACTIVE_CFG_IO_LVDE_SHIFT             (26U)
/*! IO_LVDE - IO Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_IO_LVDE(x)                (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_IO_LVDE_SHIFT)) & SPC_ACTIVE_CFG_IO_LVDE_MASK)

#define SPC_ACTIVE_CFG_CORE_HVDE_MASK            (0x8000000U)
#define SPC_ACTIVE_CFG_CORE_HVDE_SHIFT           (27U)
/*! CORE_HVDE - Core High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_CORE_HVDE(x)              (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_CORE_HVDE_SHIFT)) & SPC_ACTIVE_CFG_CORE_HVDE_MASK)

#define SPC_ACTIVE_CFG_IO_HVDE_MASK              (0x20000000U)
#define SPC_ACTIVE_CFG_IO_HVDE_SHIFT             (29U)
/*! IO_HVDE - IO High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_IO_HVDE(x)                (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_IO_HVDE_SHIFT)) & SPC_ACTIVE_CFG_IO_HVDE_MASK)

#define SPC_ACTIVE_CFG_VDD1P8_LVDE_MASK          (0x40000000U)
#define SPC_ACTIVE_CFG_VDD1P8_LVDE_SHIFT         (30U)
/*! VDD1P8_LVDE - 1P8 VDD Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_VDD1P8_LVDE(x)            (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_VDD1P8_LVDE_SHIFT)) & SPC_ACTIVE_CFG_VDD1P8_LVDE_MASK)
/*! @} */

/*! @name ACTIVE_CFG1 - Active Power Mode Configuration 1 */
/*! @{ */

#define SPC_ACTIVE_CFG1_SOC_CNTRL_MASK           (0xFFFFFFFFU)
#define SPC_ACTIVE_CFG1_SOC_CNTRL_SHIFT          (0U)
/*! SOC_CNTRL - Active Config Chip Control */
#define SPC_ACTIVE_CFG1_SOC_CNTRL(x)             (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG1_SOC_CNTRL_SHIFT)) & SPC_ACTIVE_CFG1_SOC_CNTRL_MASK)
/*! @} */

/*! @name LP_CFG - Low-Power Mode Configuration */
/*! @{ */

#define SPC_LP_CFG_CORELDO_VDD_DS_MASK           (0x1U)
#define SPC_LP_CFG_CORELDO_VDD_DS_SHIFT          (0U)
/*! CORELDO_VDD_DS - LDO_CORE VDD Drive Strength
 *  0b0..Low
 *  0b1..Normal
 */
#define SPC_LP_CFG_CORELDO_VDD_DS(x)             (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_CORELDO_VDD_DS_SHIFT)) & SPC_LP_CFG_CORELDO_VDD_DS_MASK)

#define SPC_LP_CFG_CORELDO_VDD_LVL_MASK          (0xCU)
#define SPC_LP_CFG_CORELDO_VDD_LVL_SHIFT         (2U)
/*! CORELDO_VDD_LVL - LDO_CORE VDD Regulator Voltage Level
 *  0b00..
 *  0b01..Mid voltage (1.0 V)
 *  0b10..Normal voltage (1.1 V)
 *  0b11..Safe-mode voltage (1.15 V)
 */
#define SPC_LP_CFG_CORELDO_VDD_LVL(x)            (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_CORELDO_VDD_LVL_SHIFT)) & SPC_LP_CFG_CORELDO_VDD_LVL_MASK)

#define SPC_LP_CFG_DCDC_VDD_DS_MASK              (0x300U)
#define SPC_LP_CFG_DCDC_VDD_DS_SHIFT             (8U)
/*! DCDC_VDD_DS - DCDC VDD Drive Strength
 *  0b00..
 *  0b01..Low
 *  0b10..Normal
 *  0b11..
 */
#define SPC_LP_CFG_DCDC_VDD_DS(x)                (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_DCDC_VDD_DS_SHIFT)) & SPC_LP_CFG_DCDC_VDD_DS_MASK)

#define SPC_LP_CFG_DCDC_VDD_LVL_MASK             (0xC00U)
#define SPC_LP_CFG_DCDC_VDD_LVL_SHIFT            (10U)
/*! DCDC_VDD_LVL - DCDC VDD Regulator Voltage Level
 *  0b00..Low undervoltage (1.25 V)
 *  0b01..Normal voltage (1.35 V)
 *  0b10..Mid voltage (1.45 V)
 *  0b11..Safe-mode voltage (1.8 V)
 */
#define SPC_LP_CFG_DCDC_VDD_LVL(x)               (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_DCDC_VDD_LVL_SHIFT)) & SPC_LP_CFG_DCDC_VDD_LVL_MASK)

#define SPC_LP_CFG_GLITCH_DETECT_DISABLE_MASK    (0x2000U)
#define SPC_LP_CFG_GLITCH_DETECT_DISABLE_SHIFT   (13U)
/*! GLITCH_DETECT_DISABLE - Glitch Detect Disable
 *  0b0..Low Voltage Glitch Detect enabled
 *  0b1..Low Voltage Glitch Detect disabled
 */
#define SPC_LP_CFG_GLITCH_DETECT_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_GLITCH_DETECT_DISABLE_SHIFT)) & SPC_LP_CFG_GLITCH_DETECT_DISABLE_MASK)

#define SPC_LP_CFG_COREVDD_IVS_EN_MASK           (0x20000U)
#define SPC_LP_CFG_COREVDD_IVS_EN_SHIFT          (17U)
/*! COREVDD_IVS_EN - CORE VDD Internal Voltage Scaling (IVS) Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_COREVDD_IVS_EN(x)             (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_COREVDD_IVS_EN_SHIFT)) & SPC_LP_CFG_COREVDD_IVS_EN_MASK)

#define SPC_LP_CFG_BGMODE_MASK                   (0x300000U)
#define SPC_LP_CFG_BGMODE_SHIFT                  (20U)
/*! BGMODE - Bandgap Mode
 *  0b00..Bandgap disabled
 *  0b01..Bandgap enabled, buffer disabled
 *  0b10..Bandgap enabled, buffer enabled
 *  0b11..
 */
#define SPC_LP_CFG_BGMODE(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_BGMODE_SHIFT)) & SPC_LP_CFG_BGMODE_MASK)

#define SPC_LP_CFG_LP_IREFEN_MASK                (0x800000U)
#define SPC_LP_CFG_LP_IREFEN_SHIFT               (23U)
/*! LP_IREFEN - Low-Power IREF Enable
 *  0b0..Disable for power saving in Deep Power Down mode
 *  0b1..Enable
 */
#define SPC_LP_CFG_LP_IREFEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_LP_IREFEN_SHIFT)) & SPC_LP_CFG_LP_IREFEN_MASK)

#define SPC_LP_CFG_CORE_LVDE_MASK                (0x1000000U)
#define SPC_LP_CFG_CORE_LVDE_SHIFT               (24U)
/*! CORE_LVDE - Core Low Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_CORE_LVDE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_CORE_LVDE_SHIFT)) & SPC_LP_CFG_CORE_LVDE_MASK)

#define SPC_LP_CFG_IO_LVDE_MASK                  (0x4000000U)
#define SPC_LP_CFG_IO_LVDE_SHIFT                 (26U)
/*! IO_LVDE - IO Low Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_IO_LVDE(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_IO_LVDE_SHIFT)) & SPC_LP_CFG_IO_LVDE_MASK)

#define SPC_LP_CFG_CORE_HVDE_MASK                (0x8000000U)
#define SPC_LP_CFG_CORE_HVDE_SHIFT               (27U)
/*! CORE_HVDE - Core High Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_CORE_HVDE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_CORE_HVDE_SHIFT)) & SPC_LP_CFG_CORE_HVDE_MASK)

#define SPC_LP_CFG_IO_HVDE_MASK                  (0x20000000U)
#define SPC_LP_CFG_IO_HVDE_SHIFT                 (29U)
/*! IO_HVDE - IO High Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_IO_HVDE(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_IO_HVDE_SHIFT)) & SPC_LP_CFG_IO_HVDE_MASK)

#define SPC_LP_CFG_VDD1P8_LVDE_MASK              (0x40000000U)
#define SPC_LP_CFG_VDD1P8_LVDE_SHIFT             (30U)
/*! VDD1P8_LVDE - VDD 1P8 Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_VDD1P8_LVDE(x)                (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_VDD1P8_LVDE_SHIFT)) & SPC_LP_CFG_VDD1P8_LVDE_MASK)
/*! @} */

/*! @name LP_CFG1 - Low Power Mode Configuration 1 */
/*! @{ */

#define SPC_LP_CFG1_SOC_CNTRL_MASK               (0xFFFFFFFFU)
#define SPC_LP_CFG1_SOC_CNTRL_SHIFT              (0U)
/*! SOC_CNTRL - Low-Power Configuration Chip Control */
#define SPC_LP_CFG1_SOC_CNTRL(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG1_SOC_CNTRL_SHIFT)) & SPC_LP_CFG1_SOC_CNTRL_MASK)
/*! @} */

/*! @name HP_CFG - High Power Mode Configuration */
/*! @{ */

#define SPC_HP_CFG_CORELDO_VDD_DS_MASK           (0x1U)
#define SPC_HP_CFG_CORELDO_VDD_DS_SHIFT          (0U)
/*! CORELDO_VDD_DS - LDO_CORE VDD Drive Strength
 *  0b0..Low
 *  0b1..Normal
 */
#define SPC_HP_CFG_CORELDO_VDD_DS(x)             (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_CORELDO_VDD_DS_SHIFT)) & SPC_HP_CFG_CORELDO_VDD_DS_MASK)

#define SPC_HP_CFG_CORELDO_VDD_LVL_MASK          (0xCU)
#define SPC_HP_CFG_CORELDO_VDD_LVL_SHIFT         (2U)
/*! CORELDO_VDD_LVL - LDO_CORE VDD Regulator Voltage Level
 *  0b00..
 *  0b01..Regulate to mid voltage (1.0 V)
 *  0b10..Regulate to normal voltage (1.1 V)
 *  0b11..Regulate to safe-mode voltage (1.15 V)
 */
#define SPC_HP_CFG_CORELDO_VDD_LVL(x)            (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_CORELDO_VDD_LVL_SHIFT)) & SPC_HP_CFG_CORELDO_VDD_LVL_MASK)

#define SPC_HP_CFG_DCDC_VDD_DS_MASK              (0x300U)
#define SPC_HP_CFG_DCDC_VDD_DS_SHIFT             (8U)
/*! DCDC_VDD_DS - DCDC VDD Drive Strength
 *  0b01..Low
 *  0b10..Normal
 */
#define SPC_HP_CFG_DCDC_VDD_DS(x)                (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_DCDC_VDD_DS_SHIFT)) & SPC_HP_CFG_DCDC_VDD_DS_MASK)

#define SPC_HP_CFG_DCDC_VDD_LVL_MASK             (0xC00U)
#define SPC_HP_CFG_DCDC_VDD_LVL_SHIFT            (10U)
/*! DCDC_VDD_LVL - DCDC VDD Regulator Voltage Level
 *  0b00..Low undervoltage (1.25 V)
 *  0b01..Normal voltage (1.35 V)
 *  0b10..Mid voltage (1.45 V)
 *  0b11..Safe-mode voltage (1.8 V)
 */
#define SPC_HP_CFG_DCDC_VDD_LVL(x)               (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_DCDC_VDD_LVL_SHIFT)) & SPC_HP_CFG_DCDC_VDD_LVL_MASK)

#define SPC_HP_CFG_DCDC_VOUT2P5_SEL_MASK         (0x1000U)
#define SPC_HP_CFG_DCDC_VOUT2P5_SEL_SHIFT        (12U)
/*! DCDC_VOUT2P5_SEL - 2.5 V Output Select
 *  0b0..From DCDC_VDD_LVL register
 *  0b1..2.5 V
 */
#define SPC_HP_CFG_DCDC_VOUT2P5_SEL(x)           (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_DCDC_VOUT2P5_SEL_SHIFT)) & SPC_HP_CFG_DCDC_VOUT2P5_SEL_MASK)

#define SPC_HP_CFG_GLITCH_DETECT_DISABLE_MASK    (0x2000U)
#define SPC_HP_CFG_GLITCH_DETECT_DISABLE_SHIFT   (13U)
/*! GLITCH_DETECT_DISABLE - Glitch Detect Disable
 *  0b0..Low Voltage Glitch Detect enabled
 *  0b1..Low Voltage Glitch Detect disabled
 */
#define SPC_HP_CFG_GLITCH_DETECT_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_GLITCH_DETECT_DISABLE_SHIFT)) & SPC_HP_CFG_GLITCH_DETECT_DISABLE_MASK)

#define SPC_HP_CFG_BGMODE_MASK                   (0x300000U)
#define SPC_HP_CFG_BGMODE_SHIFT                  (20U)
/*! BGMODE - Bandgap Mode
 *  0b00..Bandgap disabled
 *  0b01..Bandgap enabled, buffer disabled
 *  0b10..Bandgap enabled, buffer enabled
 *  0b11..
 */
#define SPC_HP_CFG_BGMODE(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_BGMODE_SHIFT)) & SPC_HP_CFG_BGMODE_MASK)

#define SPC_HP_CFG_VDD_VD_DISABLE_MASK           (0x800000U)
#define SPC_HP_CFG_VDD_VD_DISABLE_SHIFT          (23U)
/*! VDD_VD_DISABLE - VDD Voltage Detect Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define SPC_HP_CFG_VDD_VD_DISABLE(x)             (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_VDD_VD_DISABLE_SHIFT)) & SPC_HP_CFG_VDD_VD_DISABLE_MASK)

#define SPC_HP_CFG_CORE_LVDE_MASK                (0x1000000U)
#define SPC_HP_CFG_CORE_LVDE_SHIFT               (24U)
/*! CORE_LVDE - Core Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_HP_CFG_CORE_LVDE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_CORE_LVDE_SHIFT)) & SPC_HP_CFG_CORE_LVDE_MASK)

#define SPC_HP_CFG_IO_LVDE_MASK                  (0x4000000U)
#define SPC_HP_CFG_IO_LVDE_SHIFT                 (26U)
/*! IO_LVDE - IO Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_HP_CFG_IO_LVDE(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_IO_LVDE_SHIFT)) & SPC_HP_CFG_IO_LVDE_MASK)

#define SPC_HP_CFG_CORE_HVDE_MASK                (0x8000000U)
#define SPC_HP_CFG_CORE_HVDE_SHIFT               (27U)
/*! CORE_HVDE - Core High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_HP_CFG_CORE_HVDE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_CORE_HVDE_SHIFT)) & SPC_HP_CFG_CORE_HVDE_MASK)

#define SPC_HP_CFG_IO_HVDE_MASK                  (0x20000000U)
#define SPC_HP_CFG_IO_HVDE_SHIFT                 (29U)
/*! IO_HVDE - IO High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_HP_CFG_IO_HVDE(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_IO_HVDE_SHIFT)) & SPC_HP_CFG_IO_HVDE_MASK)

#define SPC_HP_CFG_VDD1P8_LVDE_MASK              (0x40000000U)
#define SPC_HP_CFG_VDD1P8_LVDE_SHIFT             (30U)
/*! VDD1P8_LVDE - VDD 1P8 Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_HP_CFG_VDD1P8_LVDE(x)                (((uint32_t)(((uint32_t)(x)) << SPC_HP_CFG_VDD1P8_LVDE_SHIFT)) & SPC_HP_CFG_VDD1P8_LVDE_MASK)
/*! @} */

/*! @name LPWKUP_DELAY - Low Power Wake-Up Delay */
/*! @{ */

#define SPC_LPWKUP_DELAY_LPWKUP_DELAY_MASK       (0xFFFFU)
#define SPC_LPWKUP_DELAY_LPWKUP_DELAY_SHIFT      (0U)
/*! LPWKUP_DELAY - Low-Power Wake-Up Delay */
#define SPC_LPWKUP_DELAY_LPWKUP_DELAY(x)         (((uint32_t)(((uint32_t)(x)) << SPC_LPWKUP_DELAY_LPWKUP_DELAY_SHIFT)) & SPC_LPWKUP_DELAY_LPWKUP_DELAY_MASK)
/*! @} */

/*! @name ACTIVE_VDELAY - Active Voltage Trim Delay */
/*! @{ */

#define SPC_ACTIVE_VDELAY_ACTIVE_VDELAY_MASK     (0xFFFFU)
#define SPC_ACTIVE_VDELAY_ACTIVE_VDELAY_SHIFT    (0U)
/*! ACTIVE_VDELAY - Active Voltage Delay */
#define SPC_ACTIVE_VDELAY_ACTIVE_VDELAY(x)       (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_VDELAY_ACTIVE_VDELAY_SHIFT)) & SPC_ACTIVE_VDELAY_ACTIVE_VDELAY_MASK)
/*! @} */

/*! @name VD_STAT - Voltage Detect Status */
/*! @{ */

#define SPC_VD_STAT_COREVDD_LVDF_MASK            (0x1U)
#define SPC_VD_STAT_COREVDD_LVDF_SHIFT           (0U)
/*! COREVDD_LVDF - Core Low-Voltage Detect Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_COREVDD_LVDF(x)              (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_COREVDD_LVDF_SHIFT)) & SPC_VD_STAT_COREVDD_LVDF_MASK)

#define SPC_VD_STAT_IOVDD_LVDF_MASK              (0x4U)
#define SPC_VD_STAT_IOVDD_LVDF_SHIFT             (2U)
/*! IOVDD_LVDF - IO VDD LVD Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_IOVDD_LVDF(x)                (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_IOVDD_LVDF_SHIFT)) & SPC_VD_STAT_IOVDD_LVDF_MASK)

#define SPC_VD_STAT_VDD1P8_LVDF_MASK             (0x8U)
#define SPC_VD_STAT_VDD1P8_LVDF_SHIFT            (3U)
/*! VDD1P8_LVDF - Reg 1.8 VDD Low-Voltage Detect Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_VDD1P8_LVDF(x)               (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_VDD1P8_LVDF_SHIFT)) & SPC_VD_STAT_VDD1P8_LVDF_MASK)

#define SPC_VD_STAT_COREVDD_HVDF_MASK            (0x10U)
#define SPC_VD_STAT_COREVDD_HVDF_SHIFT           (4U)
/*! COREVDD_HVDF - Core VDD HVD Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_COREVDD_HVDF(x)              (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_COREVDD_HVDF_SHIFT)) & SPC_VD_STAT_COREVDD_HVDF_MASK)

#define SPC_VD_STAT_IOVDD_HVDF_MASK              (0x40U)
#define SPC_VD_STAT_IOVDD_HVDF_SHIFT             (6U)
/*! IOVDD_HVDF - IO VDD HVD Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_IOVDD_HVDF(x)                (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_IOVDD_HVDF_SHIFT)) & SPC_VD_STAT_IOVDD_HVDF_MASK)
/*! @} */

/*! @name VD_CORE_CFG - Core Voltage Detect Configuration */
/*! @{ */

#define SPC_VD_CORE_CFG_LVDRE_MASK               (0x1U)
#define SPC_VD_CORE_CFG_LVDRE_SHIFT              (0U)
/*! LVDRE - Core LVD Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_CORE_CFG_LVDRE(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_VD_CORE_CFG_LVDRE_SHIFT)) & SPC_VD_CORE_CFG_LVDRE_MASK)

#define SPC_VD_CORE_CFG_LVDIE_MASK               (0x2U)
#define SPC_VD_CORE_CFG_LVDIE_SHIFT              (1U)
/*! LVDIE - Core LVD Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_CORE_CFG_LVDIE(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_VD_CORE_CFG_LVDIE_SHIFT)) & SPC_VD_CORE_CFG_LVDIE_MASK)

#define SPC_VD_CORE_CFG_HVDRE_MASK               (0x4U)
#define SPC_VD_CORE_CFG_HVDRE_SHIFT              (2U)
/*! HVDRE - Core VDD HVD Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_CORE_CFG_HVDRE(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_VD_CORE_CFG_HVDRE_SHIFT)) & SPC_VD_CORE_CFG_HVDRE_MASK)

#define SPC_VD_CORE_CFG_HVDIE_MASK               (0x8U)
#define SPC_VD_CORE_CFG_HVDIE_SHIFT              (3U)
/*! HVDIE - Core VDD HVD Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_CORE_CFG_HVDIE(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_VD_CORE_CFG_HVDIE_SHIFT)) & SPC_VD_CORE_CFG_HVDIE_MASK)

#define SPC_VD_CORE_CFG_LOCK_MASK                (0x10000U)
#define SPC_VD_CORE_CFG_LOCK_SHIFT               (16U)
/*! LOCK - Core Voltage Detect Reset Enable Lock
 *  0b0..Allow
 *  0b1..Deny
 */
#define SPC_VD_CORE_CFG_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_VD_CORE_CFG_LOCK_SHIFT)) & SPC_VD_CORE_CFG_LOCK_MASK)
/*! @} */

/*! @name VD_VDD1P8_CFG - VDD 1p8 Voltage Detect Configuration */
/*! @{ */

#define SPC_VD_VDD1P8_CFG_LVDIE_MASK             (0x2U)
#define SPC_VD_VDD1P8_CFG_LVDIE_SHIFT            (1U)
/*! LVDIE - VDD 1.8 LVD Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_VDD1P8_CFG_LVDIE(x)               (((uint32_t)(((uint32_t)(x)) << SPC_VD_VDD1P8_CFG_LVDIE_SHIFT)) & SPC_VD_VDD1P8_CFG_LVDIE_MASK)
/*! @} */

/*! @name VD_IO_CFG - IO Voltage Detect Configuration */
/*! @{ */

#define SPC_VD_IO_CFG_HVDRE_MASK                 (0x4U)
#define SPC_VD_IO_CFG_HVDRE_SHIFT                (2U)
/*! HVDRE - IO VDD HVD Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_IO_CFG_HVDRE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_VD_IO_CFG_HVDRE_SHIFT)) & SPC_VD_IO_CFG_HVDRE_MASK)

#define SPC_VD_IO_CFG_HVDIE_MASK                 (0x8U)
#define SPC_VD_IO_CFG_HVDIE_SHIFT                (3U)
/*! HVDIE - IO VDD HVD Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_IO_CFG_HVDIE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_VD_IO_CFG_HVDIE_SHIFT)) & SPC_VD_IO_CFG_HVDIE_MASK)

#define SPC_VD_IO_CFG_LVSEL_MASK                 (0x100U)
#define SPC_VD_IO_CFG_LVSEL_SHIFT                (8U)
/*! LVSEL - IO VDD Low-Voltage Level Select
 *  0b0..High range
 *  0b1..Low range
 */
#define SPC_VD_IO_CFG_LVSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_VD_IO_CFG_LVSEL_SHIFT)) & SPC_VD_IO_CFG_LVSEL_MASK)

#define SPC_VD_IO_CFG_LOCK_MASK                  (0x10000U)
#define SPC_VD_IO_CFG_LOCK_SHIFT                 (16U)
/*! LOCK - IO Voltage Detect Reset Enable Lock
 *  0b0..Allow
 *  0b1..Deny
 */
#define SPC_VD_IO_CFG_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_VD_IO_CFG_LOCK_SHIFT)) & SPC_VD_IO_CFG_LOCK_MASK)
/*! @} */

/*! @name EVD_CFG - External Voltage Domain Configuration */
/*! @{ */

#define SPC_EVD_CFG_EVDISO_MASK                  (0x7U)
#define SPC_EVD_CFG_EVDISO_SHIFT                 (0U)
/*! EVDISO - External Voltage Domain Isolation */
#define SPC_EVD_CFG_EVDISO(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_EVD_CFG_EVDISO_SHIFT)) & SPC_EVD_CFG_EVDISO_MASK)

#define SPC_EVD_CFG_EVDLPISO_MASK                (0x700U)
#define SPC_EVD_CFG_EVDLPISO_SHIFT               (8U)
/*! EVDLPISO - External Voltage Domain Low-Power Isolation */
#define SPC_EVD_CFG_EVDLPISO(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_EVD_CFG_EVDLPISO_SHIFT)) & SPC_EVD_CFG_EVDLPISO_MASK)

#define SPC_EVD_CFG_EVDSTAT_MASK                 (0x70000U)
#define SPC_EVD_CFG_EVDSTAT_SHIFT                (16U)
/*! EVDSTAT - External Voltage Domain Status */
#define SPC_EVD_CFG_EVDSTAT(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_EVD_CFG_EVDSTAT_SHIFT)) & SPC_EVD_CFG_EVDSTAT_MASK)
/*! @} */

/*! @name VDD_GLITCH_DETECT_SC - Glitch Detect Status Control */
/*! @{ */

#define SPC_VDD_GLITCH_DETECT_SC_CNT_SELECT_MASK (0x3U)
#define SPC_VDD_GLITCH_DETECT_SC_CNT_SELECT_SHIFT (0U)
/*! CNT_SELECT - Counter Select
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define SPC_VDD_GLITCH_DETECT_SC_CNT_SELECT(x)   (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_CNT_SELECT_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_CNT_SELECT_MASK)

#define SPC_VDD_GLITCH_DETECT_SC_TIMEOUT_MASK    (0x3CU)
#define SPC_VDD_GLITCH_DETECT_SC_TIMEOUT_SHIFT   (2U)
/*! TIMEOUT - Timeout */
#define SPC_VDD_GLITCH_DETECT_SC_TIMEOUT(x)      (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_TIMEOUT_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_TIMEOUT_MASK)

#define SPC_VDD_GLITCH_DETECT_SC_RE_MASK         (0x40U)
#define SPC_VDD_GLITCH_DETECT_SC_RE_SHIFT        (6U)
/*! RE - Glitch Detect Reset Enable
 *  0b0..GLITCH_DETECT_FLAG[CNT_SELECT] does not generate POR/LVD reset
 *  0b1..GLITCH_DETECT_FLAG[CNT_SELECT] does generate POR/LVD reset
 */
#define SPC_VDD_GLITCH_DETECT_SC_RE(x)           (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_RE_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_RE_MASK)

#define SPC_VDD_GLITCH_DETECT_SC_IE_MASK         (0x80U)
#define SPC_VDD_GLITCH_DETECT_SC_IE_SHIFT        (7U)
/*! IE - Glitch Detect Interrupt Enable
 *  0b0..GLITCH_DETECT_FLAG[CNT_SELECT] does not generate hardware interrupt (user polling)
 *  0b1..GLITCH_DETECT_FLAG[CNT_SELECT] does generate hardware interrupt
 */
#define SPC_VDD_GLITCH_DETECT_SC_IE(x)           (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_IE_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_IE_MASK)

#define SPC_VDD_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_MASK (0xF00U)
#define SPC_VDD_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_SHIFT (8U)
/*! GLITCH_DETECT_FLAG - GLITCH_DETECT_FLAG */
#define SPC_VDD_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_MASK)

#define SPC_VDD_GLITCH_DETECT_SC_LOCK_MASK       (0x10000U)
#define SPC_VDD_GLITCH_DETECT_SC_LOCK_SHIFT      (16U)
/*! LOCK - Glitch Detect Reset Enable Lock Bit
 *  0b0..Writes to RE are allowed.
 *  0b1..Writes to RE are ignored.
 */
#define SPC_VDD_GLITCH_DETECT_SC_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_LOCK_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_LOCK_MASK)

#define SPC_VDD_GLITCH_DETECT_SC_HIGH_GAIN_MODE_MASK (0x20000U)
#define SPC_VDD_GLITCH_DETECT_SC_HIGH_GAIN_MODE_SHIFT (17U)
/*! HIGH_GAIN_MODE - High Gain Mode Enable
 *  0b0..High Gain Model disabled.
 *  0b1..High Gain Model enabled.
 */
#define SPC_VDD_GLITCH_DETECT_SC_HIGH_GAIN_MODE(x) (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_HIGH_GAIN_MODE_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_HIGH_GAIN_MODE_MASK)

#define SPC_VDD_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_MASK (0x40000U)
#define SPC_VDD_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_SHIFT (18U)
/*! HVDD_AMP_DISABLE - HVDD AMP DISABLE
 *  0b0..HVDD Amplifier detection enabled.
 *  0b1..HVDD Amplifier detection disabled.
 */
#define SPC_VDD_GLITCH_DETECT_SC_HVDD_AMP_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SPC_VDD_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_SHIFT)) & SPC_VDD_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_MASK)
/*! @} */

/*! @name CORELDO_CFG - LDO_CORE Configuration */
/*! @{ */

#define SPC_CORELDO_CFG_DPDOWN_LDO_EN_MASK       (0x8U)
#define SPC_CORELDO_CFG_DPDOWN_LDO_EN_SHIFT      (3U)
/*! DPDOWN_LDO_EN - LDO_CORE Deep Power Down Reg Enable
 *  0b0..LDO_CORE disabled in Deep Power Down
 *  0b1..LDO_CORE enabled in Deep Power Down
 */
#define SPC_CORELDO_CFG_DPDOWN_LDO_EN(x)         (((uint32_t)(((uint32_t)(x)) << SPC_CORELDO_CFG_DPDOWN_LDO_EN_SHIFT)) & SPC_CORELDO_CFG_DPDOWN_LDO_EN_MASK)

#define SPC_CORELDO_CFG_PASSTHROUGH_MASK         (0x100U)
#define SPC_CORELDO_CFG_PASSTHROUGH_SHIFT        (8U)
/*! PASSTHROUGH - LDO_CORE Pass Through Enable */
#define SPC_CORELDO_CFG_PASSTHROUGH(x)           (((uint32_t)(((uint32_t)(x)) << SPC_CORELDO_CFG_PASSTHROUGH_SHIFT)) & SPC_CORELDO_CFG_PASSTHROUGH_MASK)

#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_MASK (0x800000U)
#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_SHIFT (23U)
/*! DPDOWN_PULLDOWN_DISABLE - LDO_CORE Deep Power Down Pulldown Disable
 *  0b0..LDO_CORE pulldown in Deep Power Down not disabled
 *  0b1..LDO_CORE pulldown in Deep Power Down disabled
 */
#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_SHIFT)) & SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_MASK)
/*! @} */

/*! @name DCDC_CFG - DCDC Configuration */
/*! @{ */

#define SPC_DCDC_CFG_DPDOWN_LDO_EN_MASK          (0x8U)
#define SPC_DCDC_CFG_DPDOWN_LDO_EN_SHIFT         (3U)
/*! DPDOWN_LDO_EN - DCDC Deep Power Down Enable
 *  0b0..DCDC disabled in Deep Power Down
 *  0b1..DCDC enabled in Deep Power Down
 */
#define SPC_DCDC_CFG_DPDOWN_LDO_EN(x)            (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_CFG_DPDOWN_LDO_EN_SHIFT)) & SPC_DCDC_CFG_DPDOWN_LDO_EN_MASK)

#define SPC_DCDC_CFG_RAMP_CNTRL_EN_MASK          (0x100000U)
#define SPC_DCDC_CFG_RAMP_CNTRL_EN_SHIFT         (20U)
/*! RAMP_CNTRL_EN - DCDC Trim Step Enable */
#define SPC_DCDC_CFG_RAMP_CNTRL_EN(x)            (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_CFG_RAMP_CNTRL_EN_SHIFT)) & SPC_DCDC_CFG_RAMP_CNTRL_EN_MASK)

#define SPC_DCDC_CFG_RAMP_CNTRL_MASK             (0xE00000U)
#define SPC_DCDC_CFG_RAMP_CNTRL_SHIFT            (21U)
/*! RAMP_CNTRL - DCDC Ramp Control Select */
#define SPC_DCDC_CFG_RAMP_CNTRL(x)               (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_CFG_RAMP_CNTRL_SHIFT)) & SPC_DCDC_CFG_RAMP_CNTRL_MASK)

#define SPC_DCDC_CFG_RAMP_CNTRL_LP_MASK          (0x7000000U)
#define SPC_DCDC_CFG_RAMP_CNTRL_LP_SHIFT         (24U)
/*! RAMP_CNTRL_LP - DCDC Ramp Control Select */
#define SPC_DCDC_CFG_RAMP_CNTRL_LP(x)            (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_CFG_RAMP_CNTRL_LP_SHIFT)) & SPC_DCDC_CFG_RAMP_CNTRL_LP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPC_Register_Masks */


/*!
 * @}
 */ /* end of group SPC_Peripheral_Access_Layer */


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


#endif  /* PERI_SPC_H_ */

