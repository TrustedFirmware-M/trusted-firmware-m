/*
** ###################################################################
**     Processors:          MCXA286VAPR
**                          MCXA286VASR
**                          MCXA286VLL
**                          MCXA286VLQ
**                          MCXA286VPN
**                          MCXA287VAPR
**                          MCXA287VASR
**                          MCXA287VLL
**                          MCXA287VLQ
**                          MCXA287VPN
**                          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
**                          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA566VLL
**                          MCXA566VLQ
**                          MCXA566VPN
**                          MCXA567VLL
**                          MCXA567VLQ
**                          MCXA567VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
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
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SPC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPC
 *
 * CMSIS Peripheral Access Layer for SPC
 */

#if !defined(PERI_SPC_H_)
#define PERI_SPC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
#elif (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA566VLL) || defined(CPU_MCXA566VLQ) || defined(CPU_MCXA566VPN))
#include "MCXA566_COMMON.h"
#elif (defined(CPU_MCXA567VLL) || defined(CPU_MCXA567VLQ) || defined(CPU_MCXA567VPN))
#include "MCXA567_COMMON.h"
#elif (defined(CPU_MCXA577VAPR) || defined(CPU_MCXA577VLL) || defined(CPU_MCXA577VLQ) || defined(CPU_MCXA577VPN))
#include "MCXA577_COMMON.h"
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
#define SPC_PD_STATUS_COUNT                       1u

/** SPC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t SC;                                /**< Status Control, offset: 0x10 */
  __IO uint32_t CNTRL;                             /**< SPC Regulator Control, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t LPREQ_CFG;                         /**< Low-Power Request Configuration, offset: 0x1C */
       uint8_t RESERVED_2[16];
  __IO uint32_t PD_STATUS[SPC_PD_STATUS_COUNT];    /**< SPC Power Domain Mode Status, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_3[12];
  __IO uint32_t SRAMCTL;                           /**< SRAM Control, offset: 0x40 */
       uint8_t RESERVED_4[188];
  __IO uint32_t ACTIVE_CFG;                        /**< Active Power Mode Configuration, offset: 0x100 */
  __IO uint32_t ACTIVE_CFG1;                       /**< Active Power Mode Configuration 1, offset: 0x104 */
  __IO uint32_t LP_CFG;                            /**< Low-Power Mode Configuration, offset: 0x108 */
  __IO uint32_t LP_CFG1;                           /**< Low Power Mode Configuration 1, offset: 0x10C */
       uint8_t RESERVED_5[16];
  __IO uint32_t LPWKUP_DELAY;                      /**< Low Power Wake-Up Delay, offset: 0x120 */
  __IO uint32_t ACTIVE_VDELAY;                     /**< Active Voltage Trim Delay, offset: 0x124 */
       uint8_t RESERVED_6[8];
  __IO uint32_t VD_STAT;                           /**< Voltage Detect Status, offset: 0x130 */
  __IO uint32_t VD_CORE_CFG;                       /**< Core Voltage Detect Configuration, offset: 0x134 */
  __IO uint32_t VD_SYS_CFG;                        /**< System Voltage Detect Configuration, offset: 0x138 */
       uint8_t RESERVED_7[4];
  __IO uint32_t EVD_CFG;                           /**< External Voltage Domain Configuration, offset: 0x140 */
  __IO uint32_t GLITCH_DETECT_SC;                  /**< Glitch Detect Status Control, offset: 0x144 */
       uint8_t RESERVED_8[4];
  __IO uint32_t GLITCH_VDDA_DETECT_SC;             /**< VDDA Glitch Detect Status Control, offset: 0x14C */
       uint8_t RESERVED_9[432];
  __IO uint32_t CORELDO_CFG;                       /**< LDO_CORE Configuration, offset: 0x300 */
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

#define SPC_SC_SPC_LP_MODE_MASK                  (0xF0U)
#define SPC_SC_SPC_LP_MODE_SHIFT                 (4U)
/*! SPC_LP_MODE - Power Domain Low-Power Mode Request
 *  0b0000..Sleep mode with system clock running
 *  0b0001..DSLEEP with system clock off
 *  0b0010..PDOWN with system clock off
 *  0b0100..
 *  0b1000..DPDOWN with system clock off
 */
#define SPC_SC_SPC_LP_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_SC_SPC_LP_MODE_SHIFT)) & SPC_SC_SPC_LP_MODE_MASK)

#define SPC_SC_ISO_CLR_MASK                      (0x10000U)
#define SPC_SC_ISO_CLR_SHIFT                     (16U)
/*! ISO_CLR - Isolation Clear Flags */
#define SPC_SC_ISO_CLR(x)                        (((uint32_t)(((uint32_t)(x)) << SPC_SC_ISO_CLR_SHIFT)) & SPC_SC_ISO_CLR_MASK)
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
 *  0b0001..DSLEEP with system clock off
 *  0b0010..PDOWN with system clock off
 *  0b0100..
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
 *  0b11..SRAM configured for "1.2" V operation
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
 *  0b01..Regulate to mid voltage (1.0 V)
 *  0b10..Regulate to normal voltage (1.1 V)
 *  0b11..Regulate to overdrive voltage (1.2 V)
 */
#define SPC_ACTIVE_CFG_CORELDO_VDD_LVL(x)        (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_CORELDO_VDD_LVL_SHIFT)) & SPC_ACTIVE_CFG_CORELDO_VDD_LVL_MASK)

#define SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_MASK (0x1000U)
#define SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_SHIFT (12U)
/*! GLITCH_DETECT_DISABLE - Glitch Detect Disable
 *  0b0..Low Voltage Glitch Detect enabled
 *  0b1..Low Voltage Glitch Detect disabled
 */
#define SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_SHIFT)) & SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_MASK)

#define SPC_ACTIVE_CFG_LPBUFF_EN_MASK            (0x40000U)
#define SPC_ACTIVE_CFG_LPBUFF_EN_SHIFT           (18U)
/*! LPBUFF_EN - CMP Bandgap Buffer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_LPBUFF_EN(x)              (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_LPBUFF_EN_SHIFT)) & SPC_ACTIVE_CFG_LPBUFF_EN_MASK)

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

#define SPC_ACTIVE_CFG_SYS_LVDE_MASK             (0x2000000U)
#define SPC_ACTIVE_CFG_SYS_LVDE_SHIFT            (25U)
/*! SYS_LVDE - System Low-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_SYS_LVDE(x)               (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_SYS_LVDE_SHIFT)) & SPC_ACTIVE_CFG_SYS_LVDE_MASK)

#define SPC_ACTIVE_CFG_CORE_HVDE_MASK            (0x8000000U)
#define SPC_ACTIVE_CFG_CORE_HVDE_SHIFT           (27U)
/*! CORE_HVDE - Core High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_CORE_HVDE(x)              (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_CORE_HVDE_SHIFT)) & SPC_ACTIVE_CFG_CORE_HVDE_MASK)

#define SPC_ACTIVE_CFG_SYS_HVDE_MASK             (0x10000000U)
#define SPC_ACTIVE_CFG_SYS_HVDE_SHIFT            (28U)
/*! SYS_HVDE - System High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_SYS_HVDE(x)               (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_SYS_HVDE_SHIFT)) & SPC_ACTIVE_CFG_SYS_HVDE_MASK)
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
 *  0b00..Reserved
 *  0b01..Mid voltage (1.0 V)
 *  0b10..Normal voltage (1.1 V)
 *  0b11..Overdrive voltage (1.2 V)
 */
#define SPC_LP_CFG_CORELDO_VDD_LVL(x)            (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_CORELDO_VDD_LVL_SHIFT)) & SPC_LP_CFG_CORELDO_VDD_LVL_MASK)

#define SPC_LP_CFG_GLITCH_DETECT_DISABLE_MASK    (0x1000U)
#define SPC_LP_CFG_GLITCH_DETECT_DISABLE_SHIFT   (12U)
/*! GLITCH_DETECT_DISABLE - Glitch Detect Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define SPC_LP_CFG_GLITCH_DETECT_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_GLITCH_DETECT_DISABLE_SHIFT)) & SPC_LP_CFG_GLITCH_DETECT_DISABLE_MASK)

#define SPC_LP_CFG_LPBUFF_EN_MASK                (0x40000U)
#define SPC_LP_CFG_LPBUFF_EN_SHIFT               (18U)
/*! LPBUFF_EN - CMP Bandgap Buffer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_LPBUFF_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_LPBUFF_EN_SHIFT)) & SPC_LP_CFG_LPBUFF_EN_MASK)

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

#define SPC_LP_CFG_SYS_LVDE_MASK                 (0x2000000U)
#define SPC_LP_CFG_SYS_LVDE_SHIFT                (25U)
/*! SYS_LVDE - System Low Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_SYS_LVDE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_SYS_LVDE_SHIFT)) & SPC_LP_CFG_SYS_LVDE_MASK)

#define SPC_LP_CFG_CORE_HVDE_MASK                (0x8000000U)
#define SPC_LP_CFG_CORE_HVDE_SHIFT               (27U)
/*! CORE_HVDE - Core High Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_CORE_HVDE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_CORE_HVDE_SHIFT)) & SPC_LP_CFG_CORE_HVDE_MASK)

#define SPC_LP_CFG_SYS_HVDE_MASK                 (0x10000000U)
#define SPC_LP_CFG_SYS_HVDE_SHIFT                (28U)
/*! SYS_HVDE - System High Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_SYS_HVDE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_SYS_HVDE_SHIFT)) & SPC_LP_CFG_SYS_HVDE_MASK)
/*! @} */

/*! @name LP_CFG1 - Low Power Mode Configuration 1 */
/*! @{ */

#define SPC_LP_CFG1_SOC_CNTRL_MASK               (0xFFFFFFFFU)
#define SPC_LP_CFG1_SOC_CNTRL_SHIFT              (0U)
/*! SOC_CNTRL - Low-Power Configuration Chip Control */
#define SPC_LP_CFG1_SOC_CNTRL(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG1_SOC_CNTRL_SHIFT)) & SPC_LP_CFG1_SOC_CNTRL_MASK)
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

#define SPC_VD_STAT_SYSVDD_LVDF_MASK             (0x2U)
#define SPC_VD_STAT_SYSVDD_LVDF_SHIFT            (1U)
/*! SYSVDD_LVDF - System Low-Voltage Detect Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_SYSVDD_LVDF(x)               (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_SYSVDD_LVDF_SHIFT)) & SPC_VD_STAT_SYSVDD_LVDF_MASK)

#define SPC_VD_STAT_COREVDD_HVDF_MASK            (0x10U)
#define SPC_VD_STAT_COREVDD_HVDF_SHIFT           (4U)
/*! COREVDD_HVDF - Core VDD HVD Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_COREVDD_HVDF(x)              (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_COREVDD_HVDF_SHIFT)) & SPC_VD_STAT_COREVDD_HVDF_MASK)

#define SPC_VD_STAT_SYSVDD_HVDF_MASK             (0x20U)
#define SPC_VD_STAT_SYSVDD_HVDF_SHIFT            (5U)
/*! SYSVDD_HVDF - System HVD Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_SYSVDD_HVDF(x)               (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_SYSVDD_HVDF_SHIFT)) & SPC_VD_STAT_SYSVDD_HVDF_MASK)

#define SPC_VD_STAT_COREVDD_LVD_STATUS_MASK      (0x10000U)
#define SPC_VD_STAT_COREVDD_LVD_STATUS_SHIFT     (16U)
/*! COREVDD_LVD_STATUS - Core Low-Voltage Monitor Status
 *  0b0..Event not detected
 *  0b1..Event detected
 */
#define SPC_VD_STAT_COREVDD_LVD_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_COREVDD_LVD_STATUS_SHIFT)) & SPC_VD_STAT_COREVDD_LVD_STATUS_MASK)

#define SPC_VD_STAT_SYSVDD_LVD_STATUS_MASK       (0x20000U)
#define SPC_VD_STAT_SYSVDD_LVD_STATUS_SHIFT      (17U)
/*! SYSVDD_LVD_STATUS - System Low-Voltage Monitor Status
 *  0b0..Event not detected
 *  0b1..Event detected
 */
#define SPC_VD_STAT_SYSVDD_LVD_STATUS(x)         (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_SYSVDD_LVD_STATUS_SHIFT)) & SPC_VD_STAT_SYSVDD_LVD_STATUS_MASK)

#define SPC_VD_STAT_COREVDD_HVD_STATUS_MASK      (0x100000U)
#define SPC_VD_STAT_COREVDD_HVD_STATUS_SHIFT     (20U)
/*! COREVDD_HVD_STATUS - Core VDD HVD Monitor Status
 *  0b0..Event not detected
 *  0b1..Event detected
 */
#define SPC_VD_STAT_COREVDD_HVD_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_COREVDD_HVD_STATUS_SHIFT)) & SPC_VD_STAT_COREVDD_HVD_STATUS_MASK)

#define SPC_VD_STAT_SYSVDD_HVD_STATUS_MASK       (0x200000U)
#define SPC_VD_STAT_SYSVDD_HVD_STATUS_SHIFT      (21U)
/*! SYSVDD_HVD_STATUS - System HVD Monitor Status
 *  0b0..Event not detected
 *  0b1..Event detected
 */
#define SPC_VD_STAT_SYSVDD_HVD_STATUS(x)         (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_SYSVDD_HVD_STATUS_SHIFT)) & SPC_VD_STAT_SYSVDD_HVD_STATUS_MASK)
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

/*! @name VD_SYS_CFG - System Voltage Detect Configuration */
/*! @{ */

#define SPC_VD_SYS_CFG_LVDRE_MASK                (0x1U)
#define SPC_VD_SYS_CFG_LVDRE_SHIFT               (0U)
/*! LVDRE - System LVD Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_SYS_CFG_LVDRE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_VD_SYS_CFG_LVDRE_SHIFT)) & SPC_VD_SYS_CFG_LVDRE_MASK)

#define SPC_VD_SYS_CFG_LVDIE_MASK                (0x2U)
#define SPC_VD_SYS_CFG_LVDIE_SHIFT               (1U)
/*! LVDIE - System LVD Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_SYS_CFG_LVDIE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_VD_SYS_CFG_LVDIE_SHIFT)) & SPC_VD_SYS_CFG_LVDIE_MASK)

#define SPC_VD_SYS_CFG_HVDRE_MASK                (0x4U)
#define SPC_VD_SYS_CFG_HVDRE_SHIFT               (2U)
/*! HVDRE - System HVD Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_SYS_CFG_HVDRE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_VD_SYS_CFG_HVDRE_SHIFT)) & SPC_VD_SYS_CFG_HVDRE_MASK)

#define SPC_VD_SYS_CFG_HVDIE_MASK                (0x8U)
#define SPC_VD_SYS_CFG_HVDIE_SHIFT               (3U)
/*! HVDIE - System HVD Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_SYS_CFG_HVDIE(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_VD_SYS_CFG_HVDIE_SHIFT)) & SPC_VD_SYS_CFG_HVDIE_MASK)

#define SPC_VD_SYS_CFG_LVSEL_MASK                (0x100U)
#define SPC_VD_SYS_CFG_LVSEL_SHIFT               (8U)
/*! LVSEL - System Low-Voltage Level Select
 *  0b0..Normal
 *  0b1..Safe
 */
#define SPC_VD_SYS_CFG_LVSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_VD_SYS_CFG_LVSEL_SHIFT)) & SPC_VD_SYS_CFG_LVSEL_MASK)

#define SPC_VD_SYS_CFG_LOCK_MASK                 (0x10000U)
#define SPC_VD_SYS_CFG_LOCK_SHIFT                (16U)
/*! LOCK - System Voltage Detect Reset Enable Lock
 *  0b0..Allow
 *  0b1..Deny
 */
#define SPC_VD_SYS_CFG_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_VD_SYS_CFG_LOCK_SHIFT)) & SPC_VD_SYS_CFG_LOCK_MASK)
/*! @} */

/*! @name EVD_CFG - External Voltage Domain Configuration */
/*! @{ */

#define SPC_EVD_CFG_EVDISO_MASK                  (0x3FU)
#define SPC_EVD_CFG_EVDISO_SHIFT                 (0U)
/*! EVDISO - External Voltage Domain Isolation */
#define SPC_EVD_CFG_EVDISO(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_EVD_CFG_EVDISO_SHIFT)) & SPC_EVD_CFG_EVDISO_MASK)

#define SPC_EVD_CFG_EVDLPISO_MASK                (0x3F00U)
#define SPC_EVD_CFG_EVDLPISO_SHIFT               (8U)
/*! EVDLPISO - External Voltage Domain Low-Power Isolation */
#define SPC_EVD_CFG_EVDLPISO(x)                  (((uint32_t)(((uint32_t)(x)) << SPC_EVD_CFG_EVDLPISO_SHIFT)) & SPC_EVD_CFG_EVDLPISO_MASK)

#define SPC_EVD_CFG_EVDSTAT_MASK                 (0x3F0000U)
#define SPC_EVD_CFG_EVDSTAT_SHIFT                (16U)
/*! EVDSTAT - External Voltage Domain Status */
#define SPC_EVD_CFG_EVDSTAT(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_EVD_CFG_EVDSTAT_SHIFT)) & SPC_EVD_CFG_EVDSTAT_MASK)
/*! @} */

/*! @name GLITCH_DETECT_SC - Glitch Detect Status Control */
/*! @{ */

#define SPC_GLITCH_DETECT_SC_CNT_SELECT_MASK     (0x3U)
#define SPC_GLITCH_DETECT_SC_CNT_SELECT_SHIFT    (0U)
/*! CNT_SELECT - Counter Select
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define SPC_GLITCH_DETECT_SC_CNT_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_CNT_SELECT_SHIFT)) & SPC_GLITCH_DETECT_SC_CNT_SELECT_MASK)

#define SPC_GLITCH_DETECT_SC_TIMEOUT_MASK        (0x3CU)
#define SPC_GLITCH_DETECT_SC_TIMEOUT_SHIFT       (2U)
/*! TIMEOUT - Timeout */
#define SPC_GLITCH_DETECT_SC_TIMEOUT(x)          (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_TIMEOUT_SHIFT)) & SPC_GLITCH_DETECT_SC_TIMEOUT_MASK)

#define SPC_GLITCH_DETECT_SC_RE_MASK             (0x40U)
#define SPC_GLITCH_DETECT_SC_RE_SHIFT            (6U)
/*! RE - Glitch Detect Reset Enable
 *  0b0..Disables POR/LVD reset generation
 *  0b1..Enables POR/LVD reset generation
 */
#define SPC_GLITCH_DETECT_SC_RE(x)               (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_RE_SHIFT)) & SPC_GLITCH_DETECT_SC_RE_MASK)

#define SPC_GLITCH_DETECT_SC_IE_MASK             (0x80U)
#define SPC_GLITCH_DETECT_SC_IE_SHIFT            (7U)
/*! IE - Glitch Detect Interrupt Enable
 *  0b0..Disables automatic interrupt generation (user polling)
 *  0b1..Enables automatic interrupt generation
 */
#define SPC_GLITCH_DETECT_SC_IE(x)               (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_IE_SHIFT)) & SPC_GLITCH_DETECT_SC_IE_MASK)

#define SPC_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_MASK (0xF00U)
#define SPC_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_SHIFT (8U)
/*! GLITCH_DETECT_FLAG - GLITCH_DETECT_FLAG */
#define SPC_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_SHIFT)) & SPC_GLITCH_DETECT_SC_GLITCH_DETECT_FLAG_MASK)

#define SPC_GLITCH_DETECT_SC_LOCK_MASK           (0x10000U)
#define SPC_GLITCH_DETECT_SC_LOCK_SHIFT          (16U)
/*! LOCK - Glitch Detect Reset Enable Lock Bit
 *  0b0..Writes to RE are allowed.
 *  0b1..Writes to RE are ignored.
 */
#define SPC_GLITCH_DETECT_SC_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_LOCK_SHIFT)) & SPC_GLITCH_DETECT_SC_LOCK_MASK)

#define SPC_GLITCH_DETECT_SC_HIGH_GAIN_MODE_MASK (0x20000U)
#define SPC_GLITCH_DETECT_SC_HIGH_GAIN_MODE_SHIFT (17U)
/*! HIGH_GAIN_MODE - High Gain Mode Enable
 *  0b0..High Gain Model disabled.
 *  0b1..High Gain Model enabled.
 */
#define SPC_GLITCH_DETECT_SC_HIGH_GAIN_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_HIGH_GAIN_MODE_SHIFT)) & SPC_GLITCH_DETECT_SC_HIGH_GAIN_MODE_MASK)

#define SPC_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_MASK (0x40000U)
#define SPC_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_SHIFT (18U)
/*! HVDD_AMP_DISABLE - HVDD AMP DISABLE
 *  0b0..HVDD Amplifier detection enabled.
 *  0b1..HVDD Amplifier detection disabled.
 */
#define SPC_GLITCH_DETECT_SC_HVDD_AMP_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_SHIFT)) & SPC_GLITCH_DETECT_SC_HVDD_AMP_DISABLE_MASK)
/*! @} */

/*! @name GLITCH_VDDA_DETECT_SC - VDDA Glitch Detect Status Control */
/*! @{ */

#define SPC_GLITCH_VDDA_DETECT_SC_CNT_SELECT_MASK (0x3U)
#define SPC_GLITCH_VDDA_DETECT_SC_CNT_SELECT_SHIFT (0U)
/*! CNT_SELECT - Counter Select
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define SPC_GLITCH_VDDA_DETECT_SC_CNT_SELECT(x)  (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_VDDA_DETECT_SC_CNT_SELECT_SHIFT)) & SPC_GLITCH_VDDA_DETECT_SC_CNT_SELECT_MASK)

#define SPC_GLITCH_VDDA_DETECT_SC_TIMEOUT_MASK   (0x3CU)
#define SPC_GLITCH_VDDA_DETECT_SC_TIMEOUT_SHIFT  (2U)
/*! TIMEOUT - Timeout */
#define SPC_GLITCH_VDDA_DETECT_SC_TIMEOUT(x)     (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_VDDA_DETECT_SC_TIMEOUT_SHIFT)) & SPC_GLITCH_VDDA_DETECT_SC_TIMEOUT_MASK)

#define SPC_GLITCH_VDDA_DETECT_SC_RE_MASK        (0x40U)
#define SPC_GLITCH_VDDA_DETECT_SC_RE_SHIFT       (6U)
/*! RE - Glitch Detect Reset Enable
 *  0b0..Disables POR/LVD reset generation
 *  0b1..Enables POR/LVD reset generation
 */
#define SPC_GLITCH_VDDA_DETECT_SC_RE(x)          (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_VDDA_DETECT_SC_RE_SHIFT)) & SPC_GLITCH_VDDA_DETECT_SC_RE_MASK)

#define SPC_GLITCH_VDDA_DETECT_SC_IE_MASK        (0x80U)
#define SPC_GLITCH_VDDA_DETECT_SC_IE_SHIFT       (7U)
/*! IE - Glitch Detect Interrupt Enable
 *  0b0..Disables automatic interrupt generation (user polling)
 *  0b1..Enables automatic interrupt generation
 */
#define SPC_GLITCH_VDDA_DETECT_SC_IE(x)          (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_VDDA_DETECT_SC_IE_SHIFT)) & SPC_GLITCH_VDDA_DETECT_SC_IE_MASK)

#define SPC_GLITCH_VDDA_DETECT_SC_GLITCH_DETECT_FLAG_MASK (0xF00U)
#define SPC_GLITCH_VDDA_DETECT_SC_GLITCH_DETECT_FLAG_SHIFT (8U)
/*! GLITCH_DETECT_FLAG - GLITCH_DETECT_FLAG */
#define SPC_GLITCH_VDDA_DETECT_SC_GLITCH_DETECT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_VDDA_DETECT_SC_GLITCH_DETECT_FLAG_SHIFT)) & SPC_GLITCH_VDDA_DETECT_SC_GLITCH_DETECT_FLAG_MASK)

#define SPC_GLITCH_VDDA_DETECT_SC_LOCK_MASK      (0x10000U)
#define SPC_GLITCH_VDDA_DETECT_SC_LOCK_SHIFT     (16U)
/*! LOCK - Glitch Detect Reset Enable Lock Bit
 *  0b0..Writes to RE are allowed.
 *  0b1..Writes to RE are ignored.
 */
#define SPC_GLITCH_VDDA_DETECT_SC_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_VDDA_DETECT_SC_LOCK_SHIFT)) & SPC_GLITCH_VDDA_DETECT_SC_LOCK_MASK)
/*! @} */

/*! @name CORELDO_CFG - LDO_CORE Configuration */
/*! @{ */

#define SPC_CORELDO_CFG_CORELDO_SPARE_MASK       (0x1F0000U)
#define SPC_CORELDO_CFG_CORELDO_SPARE_SHIFT      (16U)
/*! CORELDO_SPARE - CORELDO_SPARE
 *  0b00000..TBD.
 *  0b00001..TBD.
 */
#define SPC_CORELDO_CFG_CORELDO_SPARE(x)         (((uint32_t)(((uint32_t)(x)) << SPC_CORELDO_CFG_CORELDO_SPARE_SHIFT)) & SPC_CORELDO_CFG_CORELDO_SPARE_MASK)

#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_MASK (0x800000U)
#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_SHIFT (23U)
/*! DPDOWN_PULLDOWN_DISABLE - LDO_CORE Deep Power Down Pulldown Disable
 *  0b0..LDO_CORE pulldown in Deep Power Down not disabled
 *  0b1..LDO_CORE pulldown in Deep Power Down disabled
 */
#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_SHIFT)) & SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_MASK)
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

