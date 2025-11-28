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
**         CMSIS Peripheral Access Layer for GPC_GLOBAL
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
 * @file PERI_GPC_GLOBAL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_GLOBAL
 *
 * CMSIS Peripheral Access Layer for GPC_GLOBAL
 */

#if !defined(PERI_GPC_GLOBAL_H_)
#define PERI_GPC_GLOBAL_H_                       /**< Symbol preventing repeated inclusion */

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
   -- GPC_GLOBAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_GLOBAL_Peripheral_Access_Layer GPC_GLOBAL Peripheral Access Layer
 * @{
 */

/** GPC_GLOBAL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< GPC Global Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t GPC_DOMAIN;                        /**< GPC domain assignment, offset: 0x10 */
       uint8_t RESERVED_2[8];
  __IO uint32_t GPC_MASTER;                        /**< GPC master CPU configuration, offset: 0x1C */
       uint8_t RESERVED_3[32];
  __IO uint32_t GPC_SYS_SLEEP;                     /**< GPC system sleep control, offset: 0x40 */
       uint8_t RESERVED_4[188];
  __IO uint32_t PMIC_CTRL;                         /**< PMIC standby control, offset: 0x100 */
  __IO uint32_t PMIC_PRE_DLY_CTRL;                 /**< PMIC standby pre delay control, offset: 0x104 */
  __IO uint32_t PMIC_STBY_ACK_CTRL;                /**< PMIC standby acknowledge control, offset: 0x108 */
       uint8_t RESERVED_5[244];
  __IO uint32_t GPC_ROSC_CTRL;                     /**< RCOSC control, offset: 0x200 */
  __IO uint32_t GPC_AON_MEM_CTRL;                  /**< AON Memory control, offset: 0x204 */
  __IO uint32_t GPC_EFUSE_CTRL;                    /**< eFUSE control, offset: 0x208 */
} GPC_GLOBAL_Type;

/* ----------------------------------------------------------------------------
   -- GPC_GLOBAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_GLOBAL_Register_Masks GPC_GLOBAL Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - GPC Global Authentication Control */
/*! @{ */

#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_MASK     (0x80U)
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_SHIFT    (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. Refer to the function field of each gpc_global registers.
 */
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_USER_MASK         (0x100U)
#define GPC_GLOBAL_AUTHEN_CTRL_USER_SHIFT        (8U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access CPU mode control registers
 *  0b1..Allow both privilege and user mode to access CPU mode control registers
 */
#define GPC_GLOBAL_AUTHEN_CTRL_USER(x)           (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_USER_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_USER_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_MASK    (0x200U)
#define GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_SHIFT   (9U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access CPU mode registers
 *  0b1..Allow both secure and non-secure mode to access CPU mode control registers.
 */
#define GPC_GLOBAL_AUTHEN_CTRL_NONSECURE(x)      (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_MASK (0x800U)
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_SHIFT (11U)
/*! LOCK_SETTING - Lock NONSECURE and USER
 *  0b0..NONSECURE and USER fields are not locked
 *  0b1..NONSECURE and USER fields are locked
 */
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING(x)   (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_MASK    (0x8000U)
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST is not locked
 *  0b1..WHITE_LIST is locked
 */
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_MASK   (0xFFFF0000U)
#define GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Domain ID white list */
#define GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name GPC_DOMAIN - GPC domain assignment */
/*! @{ */

#define GPC_GLOBAL_GPC_DOMAIN_CPU0_DOMAIN_MASK   (0xFU)
#define GPC_GLOBAL_GPC_DOMAIN_CPU0_DOMAIN_SHIFT  (0U)
/*! CPU0_DOMAIN - CPU0 domain assignment */
#define GPC_GLOBAL_GPC_DOMAIN_CPU0_DOMAIN(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_DOMAIN_CPU0_DOMAIN_SHIFT)) & GPC_GLOBAL_GPC_DOMAIN_CPU0_DOMAIN_MASK)

#define GPC_GLOBAL_GPC_DOMAIN_CPU1_DOMAIN_MASK   (0xF0U)
#define GPC_GLOBAL_GPC_DOMAIN_CPU1_DOMAIN_SHIFT  (4U)
/*! CPU1_DOMAIN - CPU1 domain assignment */
#define GPC_GLOBAL_GPC_DOMAIN_CPU1_DOMAIN(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_DOMAIN_CPU1_DOMAIN_SHIFT)) & GPC_GLOBAL_GPC_DOMAIN_CPU1_DOMAIN_MASK)

#define GPC_GLOBAL_GPC_DOMAIN_CPU2_DOMAIN_MASK   (0xF00U)
#define GPC_GLOBAL_GPC_DOMAIN_CPU2_DOMAIN_SHIFT  (8U)
/*! CPU2_DOMAIN - CPU2 domain assignment */
#define GPC_GLOBAL_GPC_DOMAIN_CPU2_DOMAIN(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_DOMAIN_CPU2_DOMAIN_SHIFT)) & GPC_GLOBAL_GPC_DOMAIN_CPU2_DOMAIN_MASK)

#define GPC_GLOBAL_GPC_DOMAIN_CPU3_DOMAIN_MASK   (0xF000U)
#define GPC_GLOBAL_GPC_DOMAIN_CPU3_DOMAIN_SHIFT  (12U)
/*! CPU3_DOMAIN - CPU3 domain assignment */
#define GPC_GLOBAL_GPC_DOMAIN_CPU3_DOMAIN(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_DOMAIN_CPU3_DOMAIN_SHIFT)) & GPC_GLOBAL_GPC_DOMAIN_CPU3_DOMAIN_MASK)
/*! @} */

/*! @name GPC_MASTER - GPC master CPU configuration */
/*! @{ */

#define GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_MASK   (0x1U)
#define GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_SHIFT  (0U)
/*! CPU0_MASTER - Setting to 1 means CPU0 is the master CPU of its domain
 *  0b0..CPU0 is not the master CPU of its domain
 *  0b1..CPU0 is the master CPU of its domain
 */
#define GPC_GLOBAL_GPC_MASTER_CPU0_MASTER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_SHIFT)) & GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_MASK)

#define GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_MASK   (0x2U)
#define GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_SHIFT  (1U)
/*! CPU1_MASTER - Setting to 1 means CPU1 is the master CPU of its domain
 *  0b0..CPU1 is not the master CPU of its domain
 *  0b1..CPU1 is the master CPU of its domain
 */
#define GPC_GLOBAL_GPC_MASTER_CPU1_MASTER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_SHIFT)) & GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_MASK)

#define GPC_GLOBAL_GPC_MASTER_CPU2_MASTER_MASK   (0x4U)
#define GPC_GLOBAL_GPC_MASTER_CPU2_MASTER_SHIFT  (2U)
/*! CPU2_MASTER - Setting to 1 means CPU2 is the master CPU of its domain
 *  0b0..CPU2 is not the master CPU of its domain
 *  0b1..CPU2 is the master CPU of its domain
 */
#define GPC_GLOBAL_GPC_MASTER_CPU2_MASTER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_MASTER_CPU2_MASTER_SHIFT)) & GPC_GLOBAL_GPC_MASTER_CPU2_MASTER_MASK)

#define GPC_GLOBAL_GPC_MASTER_CPU3_MASTER_MASK   (0x8U)
#define GPC_GLOBAL_GPC_MASTER_CPU3_MASTER_SHIFT  (3U)
/*! CPU3_MASTER - Setting to 1 means CPU3 is the master CPU of its domain
 *  0b0..CPU3 is not the master CPU of its domain
 *  0b1..CPU3 is the master CPU of its domain
 */
#define GPC_GLOBAL_GPC_MASTER_CPU3_MASTER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_MASTER_CPU3_MASTER_SHIFT)) & GPC_GLOBAL_GPC_MASTER_CPU3_MASTER_MASK)
/*! @} */

/*! @name GPC_SYS_SLEEP - GPC system sleep control */
/*! @{ */

#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU0_DISABLE_MASK (0x10000U)
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU0_DISABLE_SHIFT (16U)
/*! FORCE_CPU0_DISABLE - Force CPU0 into a system sleep status */
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU0_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU0_DISABLE_SHIFT)) & GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU0_DISABLE_MASK)

#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU1_DISABLE_MASK (0x20000U)
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU1_DISABLE_SHIFT (17U)
/*! FORCE_CPU1_DISABLE - Force CPU1 into a system sleep status */
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU1_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU1_DISABLE_SHIFT)) & GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU1_DISABLE_MASK)

#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU2_DISABLE_MASK (0x40000U)
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU2_DISABLE_SHIFT (18U)
/*! FORCE_CPU2_DISABLE - Force CPU2 into a system sleep status */
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU2_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU2_DISABLE_SHIFT)) & GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU2_DISABLE_MASK)

#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU3_DISABLE_MASK (0x80000U)
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU3_DISABLE_SHIFT (19U)
/*! FORCE_CPU3_DISABLE - Force CPU3 into a system sleep status */
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU3_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU3_DISABLE_SHIFT)) & GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU3_DISABLE_MASK)
/*! @} */

/*! @name PMIC_CTRL - PMIC standby control */
/*! @{ */

#define GPC_GLOBAL_PMIC_CTRL_PMIC_STBY_EN_MASK   (0x1U)
#define GPC_GLOBAL_PMIC_CTRL_PMIC_STBY_EN_SHIFT  (0U)
/*! PMIC_STBY_EN - Assert the pmic standby request when system sleep */
#define GPC_GLOBAL_PMIC_CTRL_PMIC_STBY_EN(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_PMIC_CTRL_PMIC_STBY_EN_SHIFT)) & GPC_GLOBAL_PMIC_CTRL_PMIC_STBY_EN_MASK)
/*! @} */

/*! @name PMIC_PRE_DLY_CTRL - PMIC standby pre delay control */
/*! @{ */

#define GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_ON_MASK (0xFFFFU)
#define GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_ON_SHIFT (0U)
/*! DLY_PRE_STBY_ON - Delay before pmic_standby on. Locked by LOCK_CFG field. */
#define GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_ON(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_ON_SHIFT)) & GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_ON_MASK)

#define GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_OFF_MASK (0xFFFF0000U)
#define GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_OFF_SHIFT (16U)
/*! DLY_PRE_STBY_OFF - Delay before pmic_standby off. Locked by LOCK_CFG field. */
#define GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_OFF(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_OFF_SHIFT)) & GPC_GLOBAL_PMIC_PRE_DLY_CTRL_DLY_PRE_STBY_OFF_MASK)
/*! @} */

/*! @name PMIC_STBY_ACK_CTRL - PMIC standby acknowledge control */
/*! @{ */

#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_MASK (0xFFFU)
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_SHIFT (0U)
/*! STBY_ON_CNT_CFG - PMIC standby on acknowledge count configure. Usage depends on STBY_ON_CNT_MODE. Locked by LOCK_CFG field. */
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_SHIFT)) & GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_MASK)

#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_MASK (0xC000U)
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_SHIFT (14U)
/*! STBY_ON_CNT_MODE - PMIC standby on acknowledge count mode. Locked by LOCK_CFG field.
 *  0b00..Finish the process once pmic_standby signal changes
 *  0b01..Finish the process once getting acknowledge from PMIC
 *  0b10..Ignore PMIC acknowledge, the delay counter starts to count once pmic_standby changes
 *  0b11..Time out mode, the counter starts to count once pmic_standby changes, then finishes the process when
 *        either acknowledge received or counting to CNT_CFG value
 */
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_SHIFT)) & GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_MASK)

#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_MASK (0xFFF0000U)
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_SHIFT (16U)
/*! STBY_OFF_CNT_CFG - PMIC standby off acknowledge count configure. Usage depends on STBY_OFF_CNT_MODE. Locked by LOCK_CFG field. */
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_SHIFT)) & GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_MASK)

#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_MASK (0xC0000000U)
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_SHIFT (30U)
/*! STBY_OFF_CNT_MODE - PMIC standby off acknowledge count mode. Locked by LOCK_CFG field.
 *  0b00..Finish the process once pmic_standby signal changes
 *  0b01..Finish the process once getting acknowledge from PMIC
 *  0b10..Ignore PMIC acknowledge, the delay counter starts to count once pmic_standby changes
 *  0b11..Time out mode, the counter starts to count once pmic_standby changes, then finishes the process when
 *        either acknowledge received or counting to CNT_CFG value
 */
#define GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_SHIFT)) & GPC_GLOBAL_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_MASK)
/*! @} */

/*! @name GPC_ROSC_CTRL - RCOSC control */
/*! @{ */

#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_SHIFT (0U)
/*! ROSC_OFF_EN - Shut off the 24 MHz RCOSC clock when system sleep */
#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_SHIFT)) & GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK)
/*! @} */

/*! @name GPC_AON_MEM_CTRL - AON Memory control */
/*! @{ */

#define GPC_GLOBAL_GPC_AON_MEM_CTRL_AON_MEM_LP_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_AON_MEM_CTRL_AON_MEM_LP_EN_SHIFT (0U)
/*! AON_MEM_LP_EN - AON memory enter LP enable */
#define GPC_GLOBAL_GPC_AON_MEM_CTRL_AON_MEM_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_AON_MEM_CTRL_AON_MEM_LP_EN_SHIFT)) & GPC_GLOBAL_GPC_AON_MEM_CTRL_AON_MEM_LP_EN_MASK)
/*! @} */

/*! @name GPC_EFUSE_CTRL - eFUSE control */
/*! @{ */

#define GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_SHIFT (0U)
/*! EFUSE_PD_EN - eFUSE power down enable */
#define GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_SHIFT)) & GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_GLOBAL_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_GLOBAL_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_GLOBAL_H_ */
