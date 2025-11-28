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
**         CMSIS Peripheral Access Layer for GPC_CPU_CTRL
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
 * @file PERI_GPC_CPU_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_CPU_CTRL
 *
 * CMSIS Peripheral Access Layer for GPC_CPU_CTRL
 */

#if !defined(PERI_GPC_CPU_CTRL_H_)
#define PERI_GPC_CPU_CTRL_H_                     /**< Symbol preventing repeated inclusion */

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
   -- GPC_CPU_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_CPU_CTRL_Peripheral_Access_Layer GPC_CPU_CTRL Peripheral Access Layer
 * @{
 */

/** GPC_CPU_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CM_AUTHEN_CTRL;                    /**< CM Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CM_MISC;                           /**< Miscellaneous, offset: 0xC */
  __IO uint32_t CM_MODE_CTRL;                      /**< CPU mode control, offset: 0x10 */
  __I  uint32_t CM_MODE_STAT;                      /**< CM CPU mode Status, offset: 0x14 */
  __I  uint32_t CM_PIN_STAT;                       /**< CM pin Status, offset: 0x18 */
       uint8_t RESERVED_2[228];
  __IO uint32_t CM_IRQ_WAKEUP_MASK_0;              /**< CM IRQ0~31 wakeup mask, offset: 0x100 */
  __IO uint32_t CM_IRQ_WAKEUP_MASK_1;              /**< CM IRQ32~63 wakeup mask, offset: 0x104 */
  __IO uint32_t CM_IRQ_WAKEUP_MASK_2;              /**< CM IRQ64~95 wakeup mask, offset: 0x108 */
  __IO uint32_t CM_IRQ_WAKEUP_MASK_3;              /**< CM IRQ96~127 wakeup mask, offset: 0x10C */
  __IO uint32_t CM_IRQ_WAKEUP_MASK_4;              /**< CM IRQ128~159 wakeup mask, offset: 0x110 */
  __IO uint32_t CM_IRQ_WAKEUP_MASK_5;              /**< CM IRQ160~191 wakeup mask, offset: 0x114 */
  __IO uint32_t CM_IRQ_WAKEUP_MASK_6;              /**< CM IRQ192~223 wakeup mask, offset: 0x118 */
  __IO uint32_t CM_IRQ_WAKEUP_MASK_7;              /**< CM IRQ224~255 wakeup mask, offset: 0x11C */
       uint8_t RESERVED_3[32];
  __IO uint32_t CM_NON_IRQ_WAKEUP_MASK;            /**< CM non-IRQ wakeup mask, offset: 0x140 */
       uint8_t RESERVED_4[12];
  __I  uint32_t CM_IRQ_WAKEUP_STAT_0;              /**< CM IRQ0~31 wakeup status, offset: 0x150 */
  __I  uint32_t CM_IRQ_WAKEUP_STAT_1;              /**< CM IRQ32~63 wakeup status, offset: 0x154 */
  __I  uint32_t CM_IRQ_WAKEUP_STAT_2;              /**< CM IRQ64~95 wakeup status, offset: 0x158 */
  __I  uint32_t CM_IRQ_WAKEUP_STAT_3;              /**< CM IRQ96~127 wakeup status, offset: 0x15C */
  __I  uint32_t CM_IRQ_WAKEUP_STAT_4;              /**< CM IRQ128~159 wakeup status, offset: 0x160 */
  __I  uint32_t CM_IRQ_WAKEUP_STAT_5;              /**< CM IRQ160~191 wakeup status, offset: 0x164 */
  __I  uint32_t CM_IRQ_WAKEUP_STAT_6;              /**< CM IRQ192~223 wakeup status, offset: 0x168 */
  __I  uint32_t CM_IRQ_WAKEUP_STAT_7;              /**< CM IRQ224~255 wakeup status, offset: 0x16C */
       uint8_t RESERVED_5[32];
  __I  uint32_t CM_NON_IRQ_WAKEUP_STAT;            /**< CM non-IRQ wakeup status, offset: 0x190 */
       uint8_t RESERVED_6[108];
  __IO uint32_t CM_SLEEP_A55_HDSK_CTRL;            /**< CM sleep A55_HDSK control, offset: 0x200 */
       uint8_t RESERVED_7[4];
  __IO uint32_t CM_SLEEP_SSAR_CTRL;                /**< CM sleep SSAR control, offset: 0x208 */
       uint8_t RESERVED_8[4];
  __IO uint32_t CM_SLEEP_LPCG_CTRL;                /**< CM sleep LPCG control, offset: 0x210 */
       uint8_t RESERVED_9[4];
  __IO uint32_t CM_SLEEP_PLL_CTRL;                 /**< CM sleep PLL control, offset: 0x218 */
       uint8_t RESERVED_10[4];
  __IO uint32_t CM_SLEEP_ISO_CTRL;                 /**< CM sleep isolation control, offset: 0x220 */
       uint8_t RESERVED_11[4];
  __IO uint32_t CM_SLEEP_MEM_CTRL;                 /**< CM sleep memory control, offset: 0x228 */
       uint8_t RESERVED_12[4];
  __IO uint32_t CM_SLEEP_RESET_CTRL;               /**< CM sleep reset control, offset: 0x230 */
       uint8_t RESERVED_13[4];
  __IO uint32_t CM_SLEEP_POWER_CTRL;               /**< CM sleep power control, offset: 0x238 */
       uint8_t RESERVED_14[4];
  __IO uint32_t CM_SLEEP_RSV2_CTRL;                /**< CM sleep rsv2 control, offset: 0x240 */
       uint8_t RESERVED_15[68];
  __IO uint32_t CM_WAKEUP_RSV2_CTRL;               /**< CM wakeup rsv2 control, offset: 0x288 */
       uint8_t RESERVED_16[4];
  __IO uint32_t CM_WAKEUP_POWER_CTRL;              /**< CM wakeup power control, offset: 0x290 */
       uint8_t RESERVED_17[4];
  __IO uint32_t CM_WAKEUP_MEM_CTRL;                /**< CM wakeup memory control, offset: 0x298 */
       uint8_t RESERVED_18[4];
  __IO uint32_t CM_WAKEUP_RESET_CTRL;              /**< CM wakeup reset control, offset: 0x2A0 */
       uint8_t RESERVED_19[4];
  __IO uint32_t CM_WAKEUP_ISO_CTRL;                /**< CM wakeup isolation control, offset: 0x2A8 */
       uint8_t RESERVED_20[4];
  __IO uint32_t CM_WAKEUP_PLL_CTRL;                /**< CM wakeup PLL control, offset: 0x2B0 */
       uint8_t RESERVED_21[4];
  __IO uint32_t CM_WAKEUP_LPCG_CTRL;               /**< CM wakeup LPCG control, offset: 0x2B8 */
       uint8_t RESERVED_22[4];
  __IO uint32_t CM_WAKEUP_MTR_CTRL;                /**< CM wakeup MTR control, offset: 0x2C0 */
       uint8_t RESERVED_23[4];
  __IO uint32_t CM_WAKEUP_SSAR_CTRL;               /**< CM wakeup SSAR control, offset: 0x2C8 */
       uint8_t RESERVED_24[4];
  __IO uint32_t CM_WAKEUP_A55_HDSK_CTRL;           /**< CM wakeup A55_HDSK control, offset: 0x2D0 */
       uint8_t RESERVED_25[172];
  __IO uint32_t CM_SYS_SLEEP_CTRL;                 /**< CM system sleep control, offset: 0x380 */
       uint8_t RESERVED_26[12];
  __IO uint32_t CM_DEBUG;                          /**< CM debug, offset: 0x390 */
} GPC_CPU_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- GPC_CPU_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_CPU_CTRL_Register_Masks GPC_CPU_CTRL Register Masks
 * @{
 */

/*! @name CM_AUTHEN_CTRL - CM Authentication Control */
/*! @{ */

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_MASK (0x80U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. It locks the CPUx_CM registers which are marked
 *       as "Locked by LOCK_CFG field" in the function field.
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_MASK    (0x100U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_SHIFT   (8U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access CPU mode control registers
 *  0b1..Allow both privilege and user mode to access CPU mode control registers
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_MASK (0x200U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_SHIFT (9U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access CPU mode control
 *  0b1..Allow both secure and non-secure mode to access CPU mode control registers
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_MASK (0x800U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_SHIFT (11U)
/*! LOCK_SETTING - Lock NONSECURE and USER
 *  0b0..NONSECURE and USER fields are not locked
 *  0b1..NONSECURE and USER fields are locked
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST is not locked
 *  0b1..WHITE_LIST is locked
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name CM_MISC - Miscellaneous */
/*! @{ */

#define GPC_CPU_CTRL_CM_MISC_NMI_STAT_MASK       (0x1U)
#define GPC_CPU_CTRL_CM_MISC_NMI_STAT_SHIFT      (0U)
/*! NMI_STAT - Non-masked interrupt status
 *  0b0..NMI is not asserted
 *  0b1..NMI is asserted
 */
#define GPC_CPU_CTRL_CM_MISC_NMI_STAT(x)         (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_NMI_STAT_SHIFT)) & GPC_CPU_CTRL_CM_MISC_NMI_STAT_MASK)

#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_MASK  (0x2U)
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_SHIFT (1U)
/*! SLEEP_HOLD_EN - Allow cpu_sleep_hold_req assert during CPU low power status
 *  0b0..Disable cpu_sleep_hold_req
 *  0b1..Allow cpu_sleep_hold_req to assert during CPU low power status
 */
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_SHIFT)) & GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_MASK)

#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_MASK (0x4U)
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_SHIFT (2U)
/*! SLEEP_HOLD_STAT - Status of cpu_sleep_hold_ack_b
 *  0b0..CPU sleep hold is acknowledged
 *  0b1..CPU is not in sleep hold
 */
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_SHIFT)) & GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_MASK)

#define GPC_CPU_CTRL_CM_MISC_GIC_WAKEUP_STAT_MASK (0x10U)
#define GPC_CPU_CTRL_CM_MISC_GIC_WAKEUP_STAT_SHIFT (4U)
/*! GIC_WAKEUP_STAT - GIC wakeup request status */
#define GPC_CPU_CTRL_CM_MISC_GIC_WAKEUP_STAT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_GIC_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CM_MISC_GIC_WAKEUP_STAT_MASK)

#define GPC_CPU_CTRL_CM_MISC_IRQ_MUX_MASK        (0x20U)
#define GPC_CPU_CTRL_CM_MISC_IRQ_MUX_SHIFT       (5U)
/*! IRQ_MUX - IRQ select
 *  0b0..From raw IRQ
 *  0b1..From GIC
 */
#define GPC_CPU_CTRL_CM_MISC_IRQ_MUX(x)          (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_IRQ_MUX_SHIFT)) & GPC_CPU_CTRL_CM_MISC_IRQ_MUX_MASK)

#define GPC_CPU_CTRL_CM_MISC_SW_WAKEUP_MASK      (0x40U)
#define GPC_CPU_CTRL_CM_MISC_SW_WAKEUP_SHIFT     (6U)
/*! SW_WAKEUP - software wakeup. Used for CPU hotplug. */
#define GPC_CPU_CTRL_CM_MISC_SW_WAKEUP(x)        (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_SW_WAKEUP_SHIFT)) & GPC_CPU_CTRL_CM_MISC_SW_WAKEUP_MASK)
/*! @} */

/*! @name CM_MODE_CTRL - CPU mode control */
/*! @{ */

#define GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_MASK (0x3U)
#define GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_SHIFT (0U)
/*! CPU_MODE_TARGET - The CPU mode the CPU platform should transit to on next sleep event
 *  0b00..Stay in RUN mode
 *  0b01..Transit to WAIT mode
 *  0b10..Transit to STOP mode
 *  0b11..Transit to SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_SHIFT)) & GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_MASK)
/*! @} */

/*! @name CM_MODE_STAT - CM CPU mode Status */
/*! @{ */

#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_MASK (0x3U)
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_SHIFT (0U)
/*! CPU_MODE_CURRENT - Current CPU mode
 *  0b00..CPU is currently in RUN mode
 *  0b01..CPU is currently in WAIT mode
 *  0b10..CPU is currently in STOP mode
 *  0b11..CPU is currently in SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_MASK (0xCU)
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT (2U)
/*! CPU_MODE_PREVIOUS - Previous CPU mode
 *  0b00..CPU was previously in RUN mode
 *  0b01..CPU was previously in WAIT mode
 *  0b10..CPU was previously in STOP mode
 *  0b11..CPU was previously in SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_TRANS_BUSY_MASK (0x100U)
#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_TRANS_BUSY_SHIFT (8U)
/*! SLEEP_TRANS_BUSY - Busy on CPU mode transition of sleep, not include set point trans busy. */
#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_TRANS_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_TRANS_BUSY_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_TRANS_BUSY_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_TRANS_BUSY_MASK (0x200U)
#define GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_TRANS_BUSY_SHIFT (9U)
/*! WAKEUP_TRANS_BUSY - Busy on CPU mode transition of wakeup, not include set point trans busy. */
#define GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_TRANS_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_TRANS_BUSY_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_TRANS_BUSY_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEPING_IDLE_MASK (0x400U)
#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEPING_IDLE_SHIFT (10U)
/*! SLEEPING_IDLE - Completed CPU mode and set point transition of sleep sequence, in a sleeping_idle state. */
#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEPING_IDLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_SLEEPING_IDLE_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_SLEEPING_IDLE_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_REQUEST_MASK (0x10000U)
#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_REQUEST_SHIFT (16U)
/*! SLEEP_REQUEST - Status of sleep_request input port */
#define GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_REQUEST_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_SLEEP_REQUEST_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_REQUEST_MASK (0x40000U)
#define GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_REQUEST_SHIFT (18U)
/*! WAKEUP_REQUEST - "ORed" of all unmasked IRQ in. */
#define GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_REQUEST_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_WAKEUP_REQUEST_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_FSM_STATE_MASK (0x1F000000U)
#define GPC_CPU_CTRL_CM_MODE_STAT_FSM_STATE_SHIFT (24U)
/*! FSM_STATE - CPU mode trans FSM state. */
#define GPC_CPU_CTRL_CM_MODE_STAT_FSM_STATE(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_FSM_STATE_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_FSM_STATE_MASK)
/*! @} */

/*! @name CM_PIN_STAT - CM pin Status */
/*! @{ */

#define GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_REQUEST_STAT_MASK (0x1U)
#define GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_REQUEST_STAT_SHIFT (0U)
/*! A55_HDSK_REQUEST_STAT - cpu_mode_trans_a55_hdsk_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_SSAR_REQUEST_STAT_MASK (0x2U)
#define GPC_CPU_CTRL_CM_PIN_STAT_SSAR_REQUEST_STAT_SHIFT (1U)
/*! SSAR_REQUEST_STAT - cpu_mode_trans_ssar_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_SSAR_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_SSAR_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_SSAR_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_LPCG_REQUEST_STAT_MASK (0x4U)
#define GPC_CPU_CTRL_CM_PIN_STAT_LPCG_REQUEST_STAT_SHIFT (2U)
/*! LPCG_REQUEST_STAT - cpu_mode_trans_lpcg_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_LPCG_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_LPCG_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_LPCG_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_PLL_REQUEST_STAT_MASK (0x8U)
#define GPC_CPU_CTRL_CM_PIN_STAT_PLL_REQUEST_STAT_SHIFT (3U)
/*! PLL_REQUEST_STAT - cpu_mode_trans_pll_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_PLL_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_PLL_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_PLL_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_ISO_REQUEST_STAT_MASK (0x10U)
#define GPC_CPU_CTRL_CM_PIN_STAT_ISO_REQUEST_STAT_SHIFT (4U)
/*! ISO_REQUEST_STAT - cpu_mode_trans_iso_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_ISO_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_ISO_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_ISO_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_MEM_REQUEST_STAT_MASK (0x20U)
#define GPC_CPU_CTRL_CM_PIN_STAT_MEM_REQUEST_STAT_SHIFT (5U)
/*! MEM_REQUEST_STAT - cpu_mode_trans_mem_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_MEM_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_MEM_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_MEM_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_RESET_REQUEST_STAT_MASK (0x40U)
#define GPC_CPU_CTRL_CM_PIN_STAT_RESET_REQUEST_STAT_SHIFT (6U)
/*! RESET_REQUEST_STAT - cpu_mode_trans_reset_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_RESET_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_RESET_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_RESET_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_POWER_REQUEST_STAT_MASK (0x80U)
#define GPC_CPU_CTRL_CM_PIN_STAT_POWER_REQUEST_STAT_SHIFT (7U)
/*! POWER_REQUEST_STAT - cpu_mode_trans_power_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_POWER_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_POWER_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_POWER_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_MTR_REQUEST_STAT_MASK (0x100U)
#define GPC_CPU_CTRL_CM_PIN_STAT_MTR_REQUEST_STAT_SHIFT (8U)
/*! MTR_REQUEST_STAT - cpu_mode_trans_mtr_request pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_MTR_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_MTR_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_MTR_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_DONE_STAT_MASK (0x10000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_DONE_STAT_SHIFT (16U)
/*! A55_HDSK_DONE_STAT - cpu_mode_trans_a55_hdsk_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_A55_HDSK_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_SSAR_DONE_STAT_MASK (0x20000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_SSAR_DONE_STAT_SHIFT (17U)
/*! SSAR_DONE_STAT - cpu_mode_trans_ssar_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_SSAR_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_SSAR_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_SSAR_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_LPCG_DONE_STAT_MASK (0x40000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_LPCG_DONE_STAT_SHIFT (18U)
/*! LPCG_DONE_STAT - cpu_mode_trans_lpcg_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_LPCG_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_LPCG_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_LPCG_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_PLL_DONE_STAT_MASK (0x80000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_PLL_DONE_STAT_SHIFT (19U)
/*! PLL_DONE_STAT - cpu_mode_trans_pll_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_PLL_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_PLL_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_PLL_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_ISO_DONE_STAT_MASK (0x100000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_ISO_DONE_STAT_SHIFT (20U)
/*! ISO_DONE_STAT - cpu_mode_trans_iso_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_ISO_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_ISO_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_ISO_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_MEM_DONE_STAT_MASK (0x200000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_MEM_DONE_STAT_SHIFT (21U)
/*! MEM_DONE_STAT - cpu_mode_trans_mem_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_MEM_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_MEM_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_MEM_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_RESET_DONE_STAT_MASK (0x400000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_RESET_DONE_STAT_SHIFT (22U)
/*! RESET_DONE_STAT - cpu_mode_trans_reset_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_RESET_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_RESET_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_RESET_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_POWER_DONE_STAT_MASK (0x800000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_POWER_DONE_STAT_SHIFT (23U)
/*! POWER_DONE_STAT - cpu_mode_trans_power_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_POWER_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_POWER_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_POWER_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_MTR_DONE_STAT_MASK (0x1000000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_MTR_DONE_STAT_SHIFT (24U)
/*! MTR_DONE_STAT - cpu_mode_trans_mtr_done pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_MTR_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_MTR_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_MTR_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_CPU_MODE_STAT_MASK (0x60000000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_CPU_MODE_STAT_SHIFT (29U)
/*! CPU_MODE_STAT - cpu_power_mode pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_CPU_MODE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_CPU_MODE_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_CPU_MODE_STAT_MASK)

#define GPC_CPU_CTRL_CM_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_SHIFT (31U)
/*! DEBUG_WAKEUP_ACK_STAT - debug wakeup acknowledge pin status */
#define GPC_CPU_CTRL_CM_PIN_STAT_DEBUG_WAKEUP_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_SHIFT)) & GPC_CPU_CTRL_CM_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_0 - CM IRQ0~31 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_0_IRQ_WAKEUP_MASK_0_31_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_0_IRQ_WAKEUP_MASK_0_31_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_0_31 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_0_IRQ_WAKEUP_MASK_0_31(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_0_IRQ_WAKEUP_MASK_0_31_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_0_IRQ_WAKEUP_MASK_0_31_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_1 - CM IRQ32~63 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_1_IRQ_WAKEUP_MASK_32_63_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_1_IRQ_WAKEUP_MASK_32_63_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_32_63 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_1_IRQ_WAKEUP_MASK_32_63(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_1_IRQ_WAKEUP_MASK_32_63_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_1_IRQ_WAKEUP_MASK_32_63_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_2 - CM IRQ64~95 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_2_IRQ_WAKEUP_MASK_64_95_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_2_IRQ_WAKEUP_MASK_64_95_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_64_95 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_2_IRQ_WAKEUP_MASK_64_95(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_2_IRQ_WAKEUP_MASK_64_95_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_2_IRQ_WAKEUP_MASK_64_95_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_3 - CM IRQ96~127 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_3_IRQ_WAKEUP_MASK_96_127_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_3_IRQ_WAKEUP_MASK_96_127_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_96_127 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_3_IRQ_WAKEUP_MASK_96_127(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_3_IRQ_WAKEUP_MASK_96_127_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_3_IRQ_WAKEUP_MASK_96_127_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_4 - CM IRQ128~159 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_4_IRQ_WAKEUP_MASK_128_159_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_4_IRQ_WAKEUP_MASK_128_159_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_128_159 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_4_IRQ_WAKEUP_MASK_128_159(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_4_IRQ_WAKEUP_MASK_128_159_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_4_IRQ_WAKEUP_MASK_128_159_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_5 - CM IRQ160~191 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_5_IRQ_WAKEUP_MASK_160_191_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_5_IRQ_WAKEUP_MASK_160_191_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_160_191 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_5_IRQ_WAKEUP_MASK_160_191(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_5_IRQ_WAKEUP_MASK_160_191_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_5_IRQ_WAKEUP_MASK_160_191_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_6 - CM IRQ192~223 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_6_IRQ_WAKEUP_MASK_192_223_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_6_IRQ_WAKEUP_MASK_192_223_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_192_223 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_6_IRQ_WAKEUP_MASK_192_223(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_6_IRQ_WAKEUP_MASK_192_223_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_6_IRQ_WAKEUP_MASK_192_223_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_MASK_7 - CM IRQ224~255 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_7_IRQ_WAKEUP_MASK_224_255_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_7_IRQ_WAKEUP_MASK_224_255_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_224_255 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_7_IRQ_WAKEUP_MASK_224_255(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_7_IRQ_WAKEUP_MASK_224_255_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_7_IRQ_WAKEUP_MASK_224_255_MASK)
/*! @} */

/*! @name CM_NON_IRQ_WAKEUP_MASK - CM non-IRQ wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_MASK (0x1U)
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_SHIFT (0U)
/*! EVENT_WAKEUP_MASK - "1" means the event cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_SHIFT)) & GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_MASK)

#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK (0x2U)
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT (1U)
/*! DEBUG_WAKEUP_MASK - "1" means the debug_wakeup_request cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT)) & GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_0 - CM IRQ0~31 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_0_IRQ_WAKEUP_STAT_0_31_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_0_IRQ_WAKEUP_STAT_0_31_SHIFT (0U)
/*! IRQ_WAKEUP_STAT_0_31 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_0_IRQ_WAKEUP_STAT_0_31(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_0_IRQ_WAKEUP_STAT_0_31_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_0_IRQ_WAKEUP_STAT_0_31_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_1 - CM IRQ32~63 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_1_IRQ_WAKEUP_STAT_32_63_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_1_IRQ_WAKEUP_STAT_32_63_SHIFT (0U)
/*! IRQ_WAKEUP_STAT_32_63 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_1_IRQ_WAKEUP_STAT_32_63(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_1_IRQ_WAKEUP_STAT_32_63_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_1_IRQ_WAKEUP_STAT_32_63_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_2 - CM IRQ64~95 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_2_IRQ_WAKEUP_STAT_64_95_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_2_IRQ_WAKEUP_STAT_64_95_SHIFT (0U)
/*! IRQ_WAKEUP_STAT_64_95 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_2_IRQ_WAKEUP_STAT_64_95(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_2_IRQ_WAKEUP_STAT_64_95_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_2_IRQ_WAKEUP_STAT_64_95_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_3 - CM IRQ96~127 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_3_IRQ_WAKEUP_STAT_96_127_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_3_IRQ_WAKEUP_STAT_96_127_SHIFT (0U)
/*! IRQ_WAKEUP_STAT_96_127 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_3_IRQ_WAKEUP_STAT_96_127(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_3_IRQ_WAKEUP_STAT_96_127_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_3_IRQ_WAKEUP_STAT_96_127_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_4 - CM IRQ128~159 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_4_IRQ_WAKEUP_STAT_128_159_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_4_IRQ_WAKEUP_STAT_128_159_SHIFT (0U)
/*! IRQ_WAKEUP_STAT_128_159 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_4_IRQ_WAKEUP_STAT_128_159(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_4_IRQ_WAKEUP_STAT_128_159_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_4_IRQ_WAKEUP_STAT_128_159_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_5 - CM IRQ160~191 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_5_IRQ_WAKEUP_STAT_160_191_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_5_IRQ_WAKEUP_STAT_160_191_SHIFT (0U)
/*! IRQ_WAKEUP_STAT_160_191 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_5_IRQ_WAKEUP_STAT_160_191(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_5_IRQ_WAKEUP_STAT_160_191_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_5_IRQ_WAKEUP_STAT_160_191_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_6 - CM IRQ192~223 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_6_IRQ_WAKEUP_STAT_192_223_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_6_IRQ_WAKEUP_STAT_192_223_SHIFT (0U)
/*! IRQ_WAKEUP_STAT_192_223 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_6_IRQ_WAKEUP_STAT_192_223(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_6_IRQ_WAKEUP_STAT_192_223_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_6_IRQ_WAKEUP_STAT_192_223_MASK)
/*! @} */

/*! @name CM_IRQ_WAKEUP_STAT_7 - CM IRQ224~255 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_7_IRQ_WAKEUP_MASK_224_255_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_7_IRQ_WAKEUP_MASK_224_255_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_224_255 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_7_IRQ_WAKEUP_MASK_224_255(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_7_IRQ_WAKEUP_MASK_224_255_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_7_IRQ_WAKEUP_MASK_224_255_MASK)
/*! @} */

/*! @name CM_NON_IRQ_WAKEUP_STAT - CM non-IRQ wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_MASK (0x1U)
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_SHIFT (0U)
/*! EVENT_WAKEUP_STAT - Event wakeup status
 *  0b0..No event wakeup is requested
 *  0b1..Event wakeup is requested
 */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_MASK)

#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK (0x2U)
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT (1U)
/*! DEBUG_WAKEUP_STAT - Debug wakeup status
 *  0b0..No debug wakeup is requested
 *  0b1..Debug wakeup is requested
 */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK)
/*! @} */

/*! @name CM_SLEEP_A55_HDSK_CTRL - CM sleep A55_HDSK control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE. */
#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_A55_HDSK_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_SSAR_CTRL - CM sleep SSAR control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE. */
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_LPCG_CTRL - CM sleep LPCG control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_PLL_CTRL - CM sleep PLL control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_ISO_CTRL - CM sleep isolation control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_MEM_CTRL - CM sleep memory control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_MEM_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_RESET_CTRL - CM sleep reset control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_POWER_CTRL - CM sleep power control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SLEEP_RSV2_CTRL - CM sleep rsv2 control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_RSV2_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_RSV2_CTRL - CM wakeup rsv2 control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_RSV2_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_POWER_CTRL - CM wakeup power control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_MEM_CTRL - CM wakeup memory control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_MEM_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_RESET_CTRL - CM wakeup reset control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_ISO_CTRL - CM wakeup isolation control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_PLL_CTRL - CM wakeup PLL control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_LPCG_CTRL - CM wakeup LPCG control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_MTR_CTRL - CM wakeup MTR control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_MTR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_SSAR_CTRL - CM wakeup SSAR control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_WAKEUP_A55_HDSK_CTRL - CM wakeup A55_HDSK control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CM_SYS_SLEEP_CTRL - CM system sleep control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_MASK (0x1U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_SHIFT (0U)
/*! SS_WAIT - Request system sleep when CPU is in WAIT mode
 *  0b0..Do not request system sleep when CPU is in WAIT mode
 *  0b1..Request system sleep when CPU is in WAIT mode
 */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_MASK)

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_MASK (0x2U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_SHIFT (1U)
/*! SS_STOP - Request system sleep when CPU is in STOP mode
 *  0b0..Do not request system sleep when CPU is in STOP mode
 *  0b1..Request system sleep when CPU is in STOP mode
 */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_MASK)

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_MASK (0x4U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT (2U)
/*! SS_SUSPEND - Request system sleep when CPU is in SUSPEND mode
 *  0b0..Do not request system sleep when CPU is in SUSPEND mode
 *  0b1..Request system sleep when CPU is in SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_MASK)

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_MASK (0x10000U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_SHIFT (16U)
/*! SYS_SLEEP_BUSY - Indicates the CPU is busy entering system sleep mode. */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_MASK)

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_MASK (0x20000U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_SHIFT (17U)
/*! SYS_WAKEUP_BUSY - Indicates the CPU is busy exiting system sleep mode. */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_MASK)
/*! @} */

/*! @name CM_DEBUG - CM debug */
/*! @{ */

#define GPC_CPU_CTRL_CM_DEBUG_PRETEND_SLEEP_MASK (0x1U)
#define GPC_CPU_CTRL_CM_DEBUG_PRETEND_SLEEP_SHIFT (0U)
/*! PRETEND_SLEEP - Write 1 to force CMC into sleep. Used to debug GPC status. Locked by LOCK_CFG field. */
#define GPC_CPU_CTRL_CM_DEBUG_PRETEND_SLEEP(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_DEBUG_PRETEND_SLEEP_SHIFT)) & GPC_CPU_CTRL_CM_DEBUG_PRETEND_SLEEP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_CPU_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_CPU_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_CPU_CTRL_H_ */
