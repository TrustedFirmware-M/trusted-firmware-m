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
**         CMSIS Peripheral Access Layer for SPC
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
 * @file PERI_SPC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPC
 *
 * CMSIS Peripheral Access Layer for SPC
 */

#if !defined(PERI_SPC_H_)
#define PERI_SPC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- SPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPC_Peripheral_Access_Layer SPC Peripheral Access Layer
 * @{
 */

/** SPC - Size of Registers Arrays */
#define SPC_PD_STATUS_COUNT                       2u

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
       uint8_t RESERVED_3[8];
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
  __IO uint32_t VD_IO_CFG;                         /**< IO Voltage Detect Configuration, offset: 0x13C */
  __IO uint32_t EVD_CFG;                           /**< External Voltage Domain Configuration, offset: 0x140 */
  __IO uint32_t GLITCH_DETECT_SC;                  /**< Glitch Detect Status Control, offset: 0x144 */
       uint8_t RESERVED_7[440];
  __IO uint32_t CORELDO_CFG;                       /**< LDO_CORE Configuration, offset: 0x300 */
       uint8_t RESERVED_8[252];
  __IO uint32_t SYSLDO_CFG;                        /**< LDO_SYS Configuration, offset: 0x400 */
       uint8_t RESERVED_9[252];
  __IO uint32_t DCDC_CFG;                          /**< DCDC Configuration, offset: 0x500 */
  __IO uint32_t DCDC_BURST_CFG;                    /**< DCDC Burst Configuration, offset: 0x504 */
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
 *  0b0..SPC is in Active or Sleep mode; the ACTIVE_CFG register has control
 *  0b1..All power domains requested low-power mode; SPC entered a low-power state; power-mode configuration based on the LP_CFG register
 *  0b1..Clear the flag
 */
#define SPC_SC_SPC_LP_REQ(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_SC_SPC_LP_REQ_SHIFT)) & SPC_SC_SPC_LP_REQ_MASK)

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

#define SPC_SC_ISO_CLR_MASK                      (0x30000U)
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

#define SPC_CNTRL_SYSLDO_EN_MASK                 (0x2U)
#define SPC_CNTRL_SYSLDO_EN_SHIFT                (1U)
/*! SYSLDO_EN - LDO_SYS Regulator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CNTRL_SYSLDO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_CNTRL_SYSLDO_EN_SHIFT)) & SPC_CNTRL_SYSLDO_EN_MASK)

#define SPC_CNTRL_DCDC_EN_MASK                   (0x4U)
#define SPC_CNTRL_DCDC_EN_SHIFT                  (2U)
/*! DCDC_EN - DCDC_CORE Regulator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_CNTRL_DCDC_EN(x)                     (((uint32_t)(((uint32_t)(x)) << SPC_CNTRL_DCDC_EN_SHIFT)) & SPC_CNTRL_DCDC_EN_MASK)
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
 *  0b11..
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
 *  0b00..
 *  0b01..Regulate to mid voltage (1.0 V)
 *  0b10..Regulate to normal voltage (1.1 V)
 *  0b11..Regulate to overdrive voltage (1.2 V)
 */
#define SPC_ACTIVE_CFG_CORELDO_VDD_LVL(x)        (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_CORELDO_VDD_LVL_SHIFT)) & SPC_ACTIVE_CFG_CORELDO_VDD_LVL_MASK)

#define SPC_ACTIVE_CFG_SYSLDO_VDD_DS_MASK        (0x10U)
#define SPC_ACTIVE_CFG_SYSLDO_VDD_DS_SHIFT       (4U)
/*! SYSLDO_VDD_DS - LDO_SYS VDD Drive Strength
 *  0b0..Low
 *  0b1..Normal
 */
#define SPC_ACTIVE_CFG_SYSLDO_VDD_DS(x)          (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_SYSLDO_VDD_DS_SHIFT)) & SPC_ACTIVE_CFG_SYSLDO_VDD_DS_MASK)

#define SPC_ACTIVE_CFG_SYSLDO_VDD_LVL_MASK       (0x40U)
#define SPC_ACTIVE_CFG_SYSLDO_VDD_LVL_SHIFT      (6U)
/*! SYSLDO_VDD_LVL - LDO_SYS VDD Regulator Voltage Level
 *  0b0..Normal voltage (1.8 V)
 *  0b1..Overdrive voltage (2.5 V)
 */
#define SPC_ACTIVE_CFG_SYSLDO_VDD_LVL(x)         (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_SYSLDO_VDD_LVL_SHIFT)) & SPC_ACTIVE_CFG_SYSLDO_VDD_LVL_MASK)

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
 *  0b00..Reserved
 *  0b01..Midvoltage (1.0 V)
 *  0b10..Normal voltage (1.1 V)
 *  0b11..Overdrive voltage (1.2 V)
 */
#define SPC_ACTIVE_CFG_DCDC_VDD_LVL(x)           (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_DCDC_VDD_LVL_SHIFT)) & SPC_ACTIVE_CFG_DCDC_VDD_LVL_MASK)

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

#define SPC_ACTIVE_CFG_SYS_HVDE_MASK             (0x10000000U)
#define SPC_ACTIVE_CFG_SYS_HVDE_SHIFT            (28U)
/*! SYS_HVDE - System High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_SYS_HVDE(x)               (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_SYS_HVDE_SHIFT)) & SPC_ACTIVE_CFG_SYS_HVDE_MASK)

#define SPC_ACTIVE_CFG_IO_HVDE_MASK              (0x20000000U)
#define SPC_ACTIVE_CFG_IO_HVDE_SHIFT             (29U)
/*! IO_HVDE - IO High-Voltage Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_ACTIVE_CFG_IO_HVDE(x)                (((uint32_t)(((uint32_t)(x)) << SPC_ACTIVE_CFG_IO_HVDE_SHIFT)) & SPC_ACTIVE_CFG_IO_HVDE_MASK)
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
 *  0b00..Retention voltage
 *  0b01..Mid voltage (1.0 V)
 *  0b10..Normal voltage (1.1 V)
 *  0b11..Overdrive voltage (1.2 V)
 */
#define SPC_LP_CFG_CORELDO_VDD_LVL(x)            (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_CORELDO_VDD_LVL_SHIFT)) & SPC_LP_CFG_CORELDO_VDD_LVL_MASK)

#define SPC_LP_CFG_SYSLDO_VDD_DS_MASK            (0x10U)
#define SPC_LP_CFG_SYSLDO_VDD_DS_SHIFT           (4U)
/*! SYSLDO_VDD_DS - LDO_SYS VDD Drive Strength
 *  0b0..Low
 *  0b1..Normal
 */
#define SPC_LP_CFG_SYSLDO_VDD_DS(x)              (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_SYSLDO_VDD_DS_SHIFT)) & SPC_LP_CFG_SYSLDO_VDD_DS_MASK)

#define SPC_LP_CFG_DCDC_VDD_DS_MASK              (0x300U)
#define SPC_LP_CFG_DCDC_VDD_DS_SHIFT             (8U)
/*! DCDC_VDD_DS - DCDC VDD Drive Strength
 *  0b00..Pulse refresh
 *  0b01..Low
 *  0b10..Normal
 *  0b11..
 */
#define SPC_LP_CFG_DCDC_VDD_DS(x)                (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_DCDC_VDD_DS_SHIFT)) & SPC_LP_CFG_DCDC_VDD_DS_MASK)

#define SPC_LP_CFG_DCDC_VDD_LVL_MASK             (0xC00U)
#define SPC_LP_CFG_DCDC_VDD_LVL_SHIFT            (10U)
/*! DCDC_VDD_LVL - DCDC VDD Regulator Voltage Level
 *  0b00..Retention voltage (0.7 V)
 *  0b01..Mid voltage (1.0 V)
 *  0b10..Normal voltage (1.1 V)
 *  0b11..Overdrive voltage (1.2 V)
 */
#define SPC_LP_CFG_DCDC_VDD_LVL(x)               (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_DCDC_VDD_LVL_SHIFT)) & SPC_LP_CFG_DCDC_VDD_LVL_MASK)

#define SPC_LP_CFG_GLITCH_DETECT_DISABLE_MASK    (0x1000U)
#define SPC_LP_CFG_GLITCH_DETECT_DISABLE_SHIFT   (12U)
/*! GLITCH_DETECT_DISABLE - Glitch Detect Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define SPC_LP_CFG_GLITCH_DETECT_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_GLITCH_DETECT_DISABLE_SHIFT)) & SPC_LP_CFG_GLITCH_DETECT_DISABLE_MASK)

#define SPC_LP_CFG_COREVDD_IVS_EN_MASK           (0x20000U)
#define SPC_LP_CFG_COREVDD_IVS_EN_SHIFT          (17U)
/*! COREVDD_IVS_EN - CORE VDD Internal Voltage Scaling (IVS) Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_COREVDD_IVS_EN(x)             (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_COREVDD_IVS_EN_SHIFT)) & SPC_LP_CFG_COREVDD_IVS_EN_MASK)

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

#define SPC_LP_CFG_SYS_HVDE_MASK                 (0x10000000U)
#define SPC_LP_CFG_SYS_HVDE_SHIFT                (28U)
/*! SYS_HVDE - System High Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_SYS_HVDE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_SYS_HVDE_SHIFT)) & SPC_LP_CFG_SYS_HVDE_MASK)

#define SPC_LP_CFG_IO_HVDE_MASK                  (0x20000000U)
#define SPC_LP_CFG_IO_HVDE_SHIFT                 (29U)
/*! IO_HVDE - IO High Voltage Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_LP_CFG_IO_HVDE(x)                    (((uint32_t)(((uint32_t)(x)) << SPC_LP_CFG_IO_HVDE_SHIFT)) & SPC_LP_CFG_IO_HVDE_MASK)
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

#define SPC_VD_STAT_IOVDD_LVDF_MASK              (0x4U)
#define SPC_VD_STAT_IOVDD_LVDF_SHIFT             (2U)
/*! IOVDD_LVDF - IO VDD LVD Flag
 *  0b0..Event not detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event detected
 */
#define SPC_VD_STAT_IOVDD_LVDF(x)                (((uint32_t)(((uint32_t)(x)) << SPC_VD_STAT_IOVDD_LVDF_SHIFT)) & SPC_VD_STAT_IOVDD_LVDF_MASK)

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

#define SPC_VD_SYS_CFG_LOCK_MASK                 (0x10000U)
#define SPC_VD_SYS_CFG_LOCK_SHIFT                (16U)
/*! LOCK - System Voltage Detect Reset Enable Lock
 *  0b0..Allow
 *  0b1..Deny
 */
#define SPC_VD_SYS_CFG_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_VD_SYS_CFG_LOCK_SHIFT)) & SPC_VD_SYS_CFG_LOCK_MASK)
/*! @} */

/*! @name VD_IO_CFG - IO Voltage Detect Configuration */
/*! @{ */

#define SPC_VD_IO_CFG_LVDRE_MASK                 (0x1U)
#define SPC_VD_IO_CFG_LVDRE_SHIFT                (0U)
/*! LVDRE - IO VDD LVD Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_IO_CFG_LVDRE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_VD_IO_CFG_LVDRE_SHIFT)) & SPC_VD_IO_CFG_LVDRE_MASK)

#define SPC_VD_IO_CFG_LVDIE_MASK                 (0x2U)
#define SPC_VD_IO_CFG_LVDIE_SHIFT                (1U)
/*! LVDIE - IO VDD LVD Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_VD_IO_CFG_LVDIE(x)                   (((uint32_t)(((uint32_t)(x)) << SPC_VD_IO_CFG_LVDIE_SHIFT)) & SPC_VD_IO_CFG_LVDIE_MASK)

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
 *  0b0..GLITCH_DETECT_FLAG[CNT_SELECT] does not generate POR/LVD reset
 *  0b1..GLITCH_DETECT_FLAG[CNT_SELECT] does generate POR/LVD reset
 */
#define SPC_GLITCH_DETECT_SC_RE(x)               (((uint32_t)(((uint32_t)(x)) << SPC_GLITCH_DETECT_SC_RE_SHIFT)) & SPC_GLITCH_DETECT_SC_RE_MASK)

#define SPC_GLITCH_DETECT_SC_IE_MASK             (0x80U)
#define SPC_GLITCH_DETECT_SC_IE_SHIFT            (7U)
/*! IE - Glitch Detect Interrupt Enable
 *  0b0..GLITCH_DETECT_FLAG[CNT_SELECT] does not generate hardware interrupt (user polling)
 *  0b1..GLITCH_DETECT_FLAG[CNT_SELECT] does generate hardware interrupt
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
/*! @} */

/*! @name CORELDO_CFG - LDO_CORE Configuration */
/*! @{ */

#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_MASK (0x10000U)
#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_SHIFT (16U)
/*! DPDOWN_PULLDOWN_DISABLE - LDO_CORE Deep Power Down Pulldown Disable
 *  0b0..LDO_CORE pulldown in Deep Power Down not disabled
 *  0b1..LDO_CORE pulldown in Deep Power Down disabled
 */
#define SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_SHIFT)) & SPC_CORELDO_CFG_DPDOWN_PULLDOWN_DISABLE_MASK)
/*! @} */

/*! @name SYSLDO_CFG - LDO_SYS Configuration */
/*! @{ */

#define SPC_SYSLDO_CFG_ISINKEN_MASK              (0x1U)
#define SPC_SYSLDO_CFG_ISINKEN_SHIFT             (0U)
/*! ISINKEN - Current Sink Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_SYSLDO_CFG_ISINKEN(x)                (((uint32_t)(((uint32_t)(x)) << SPC_SYSLDO_CFG_ISINKEN_SHIFT)) & SPC_SYSLDO_CFG_ISINKEN_MASK)
/*! @} */

/*! @name DCDC_CFG - DCDC Configuration */
/*! @{ */

#define SPC_DCDC_CFG_FREQ_CNTRL_ON_MASK          (0x1U)
#define SPC_DCDC_CFG_FREQ_CNTRL_ON_SHIFT         (0U)
/*! FREQ_CNTRL_ON - DCDC Burst Frequency Control Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_DCDC_CFG_FREQ_CNTRL_ON(x)            (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_CFG_FREQ_CNTRL_ON_SHIFT)) & SPC_DCDC_CFG_FREQ_CNTRL_ON_MASK)

#define SPC_DCDC_CFG_FREQ_CNTRL_MASK             (0x3F00U)
#define SPC_DCDC_CFG_FREQ_CNTRL_SHIFT            (8U)
/*! FREQ_CNTRL - DCDC Burst Frequency Control */
#define SPC_DCDC_CFG_FREQ_CNTRL(x)               (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_CFG_FREQ_CNTRL_SHIFT)) & SPC_DCDC_CFG_FREQ_CNTRL_MASK)

#define SPC_DCDC_CFG_BLEED_EN_MASK               (0x80000U)
#define SPC_DCDC_CFG_BLEED_EN_SHIFT              (19U)
/*! BLEED_EN - DCDC Bleed Enable
 *  0b0..Do not add
 *  0b1..Add
 */
#define SPC_DCDC_CFG_BLEED_EN(x)                 (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_CFG_BLEED_EN_SHIFT)) & SPC_DCDC_CFG_BLEED_EN_MASK)
/*! @} */

/*! @name DCDC_BURST_CFG - DCDC Burst Configuration */
/*! @{ */

#define SPC_DCDC_BURST_CFG_BURST_REQ_MASK        (0x1U)
#define SPC_DCDC_BURST_CFG_BURST_REQ_SHIFT       (0U)
/*! BURST_REQ - Software Burst Request
 *  0b0..Do not generate
 *  0b1..Generate
 */
#define SPC_DCDC_BURST_CFG_BURST_REQ(x)          (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_BURST_CFG_BURST_REQ_SHIFT)) & SPC_DCDC_BURST_CFG_BURST_REQ_MASK)

#define SPC_DCDC_BURST_CFG_EXT_BURST_EN_MASK     (0x2U)
#define SPC_DCDC_BURST_CFG_EXT_BURST_EN_SHIFT    (1U)
/*! EXT_BURST_EN - External Burst Request Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SPC_DCDC_BURST_CFG_EXT_BURST_EN(x)       (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_BURST_CFG_EXT_BURST_EN_SHIFT)) & SPC_DCDC_BURST_CFG_EXT_BURST_EN_MASK)

#define SPC_DCDC_BURST_CFG_BURST_ACK_MASK        (0x8U)
#define SPC_DCDC_BURST_CFG_BURST_ACK_SHIFT       (3U)
/*! BURST_ACK - Burst Acknowledge Flag
 *  0b0..Did not complete
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Completed
 */
#define SPC_DCDC_BURST_CFG_BURST_ACK(x)          (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_BURST_CFG_BURST_ACK_SHIFT)) & SPC_DCDC_BURST_CFG_BURST_ACK_MASK)

#define SPC_DCDC_BURST_CFG_PULSE_REFRESH_CNT_MASK (0xFFFF0000U)
#define SPC_DCDC_BURST_CFG_PULSE_REFRESH_CNT_SHIFT (16U)
/*! PULSE_REFRESH_CNT - Refresh Count Value */
#define SPC_DCDC_BURST_CFG_PULSE_REFRESH_CNT(x)  (((uint32_t)(((uint32_t)(x)) << SPC_DCDC_BURST_CFG_PULSE_REFRESH_CNT_SHIFT)) & SPC_DCDC_BURST_CFG_PULSE_REFRESH_CNT_MASK)
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

