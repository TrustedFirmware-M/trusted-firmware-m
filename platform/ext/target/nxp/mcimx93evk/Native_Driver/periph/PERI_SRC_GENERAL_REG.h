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
**         CMSIS Peripheral Access Layer for SRC_GENERAL_REG
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
 * @file PERI_SRC_GENERAL_REG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC_GENERAL_REG
 *
 * CMSIS Peripheral Access Layer for SRC_GENERAL_REG
 */

#if !defined(PERI_SRC_GENERAL_REG_H_)
#define PERI_SRC_GENERAL_REG_H_                  /**< Symbol preventing repeated inclusion */

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
   -- SRC_GENERAL_REG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GENERAL_REG_Peripheral_Access_Layer SRC_GENERAL_REG Peripheral Access Layer
 * @{
 */

/** SRC_GENERAL_REG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t SCR;                               /**< SRC Control Register, offset: 0x10 */
  __IO uint32_t SRTMR;                             /**< SRC RESET TRIGGER MODE REGISTER, offset: 0x14 */
  __IO uint32_t SRMASK;                            /**< SRC RESET TRIGGER MODE REGISTER, offset: 0x18 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SRMR1;                             /**< SRC RESET MODE REGISTER 1, offset: 0x20 */
  __IO uint32_t SRMR2;                             /**< SRC RESET MODE REGISTER 2, offset: 0x24 */
  __IO uint32_t SRMR3;                             /**< SRC RESET MODE REGISTER 3, offset: 0x28 */
  __IO uint32_t SRMR4;                             /**< SRC RESET MODE REGISTER 4, offset: 0x2C */
  __IO uint32_t SRMR5;                             /**< SRC RESET MODE REGISTER 5, offset: 0x30 */
       uint8_t RESERVED_3[12];
  __I  uint32_t SBMR1;                             /**< SRC Boot Mode Register 1, offset: 0x40 */
  __I  uint32_t SBMR2;                             /**< SRC Boot Mode Register 2, offset: 0x44 */
       uint8_t RESERVED_4[8];
  __IO uint32_t SRSR;                              /**< SRC Reset Status Register, offset: 0x50 */
       uint8_t RESERVED_5[60];
  __IO uint32_t GPR16;                             /**< SRC General Purpose Register 16, offset: 0x90 */
  __IO uint32_t GPR17;                             /**< SRC General Purpose Register 17, offset: 0x94 */
  __IO uint32_t GPR18;                             /**< SRC General Purpose Register 18, offset: 0x98 */
  __IO uint32_t GPR19;                             /**< SRC General Purpose Register 19, offset: 0x9C */
       uint8_t RESERVED_6[96];
  __IO uint32_t GPR20;                             /**< SRC General Purpose Register 20, offset: 0x100 */
  __IO uint32_t CM_QUIESCE;                        /**< SRC_CORTEX_M_QUIESCE, offset: 0x104 */
  __IO uint32_t COLD_RESET_SSAR_ACK_CTRL;          /**< Cold reset SSAR acknowledge control, offset: 0x108 */
  __IO uint32_t SP_ISO_CTRL;                       /**< SRC special ISO Control, offset: 0x10C */
  __IO uint32_t ROM_LP_CTRL;                       /**< ROM Low Power Control, offset: 0x110 */
  __I  uint32_t A55_DENY_STAT;                     /**< A55 Q_Channel Deny Status, offset: 0x114 */
} SRC_GENERAL_REG_Type;

/* ----------------------------------------------------------------------------
   -- SRC_GENERAL_REG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GENERAL_REG_Register_Masks SRC_GENERAL_REG Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - Authentication Control */
/*! @{ */

#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_MASK (0x80U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..General registers are not locked.
 *  0b1..LOCK_CFG and registers in the list are locked.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_MASK (0x100U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_SHIFT (8U)
/*! TZ_USER - Allow user mode access
 *  0b0..General registers can only be written in privilege mode.
 *  0b1..General registers can be written either in privilege mode or user mode.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_MASK   (0x200U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..General registers can only be written in secure mode.
 *  0b1..General registers can be written either in secure mode or non-secure mode.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_MASK (0x800U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TZ_NS and TZ_USER bits
 *  0b0..TZ_NS and TZ_USER value can be changed.
 *  0b1..LOCK_TZ, TZ_NS and TZ_USER value cannot be changed.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..LOCK_LIST and WHITE_LIST value cannot be changed.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write General registers.
 *  0b0000000000000010..Core with domain ID=1 can write General registers.
 *  0b0000000000000100..Core with domain ID=2 can write General registers.
 *  0b0000000000001000..Core with domain ID=3 can write General registers.
 *  0b0000000000010000..Core with domain ID=4 can write General registers.
 *  0b0000000000100000..Core with domain ID=5 can write General registers.
 *  0b0000000001000000..Core with domain ID=6 can write General registers.
 *  0b0000000010000000..Core with domain ID=7 can write General registers.
 *  0b0000000100000000..Core with domain ID=8 can write General registers.
 *  0b0000001000000000..Core with domain ID=9 can write General registers.
 *  0b0000010000000000..Core with domain ID=10 can write General registers.
 *  0b0000100000000000..Core with domain ID=11 can write General registers.
 *  0b0001000000000000..Core with domain ID=12 can write General registers.
 *  0b0010000000000000..Core with domain ID=13 can write General registers.
 *  0b0100000000000000..Core with domain ID=14 can write General registers.
 *  0b1000000000000000..Core with domain ID=15 can write General registers.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name SCR - SRC Control Register */
/*! @{ */

#define SRC_GENERAL_REG_SCR_BT_RELEASE_M33_MASK  (0x1U)
#define SRC_GENERAL_REG_SCR_BT_RELEASE_M33_SHIFT (0U)
/*! BT_RELEASE_M33 - If A55 boot, the CM33 reset will be held until boot core writes this bit to 1.
 *    Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GENERAL_REG_SCR_BT_RELEASE_M33(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SCR_BT_RELEASE_M33_SHIFT)) & SRC_GENERAL_REG_SCR_BT_RELEASE_M33_MASK)

#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU0_MASK (0x2U)
#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU0_SHIFT (1U)
/*! BT_RELEASE_A55_CPU0 - If M33 boot, the CA55 CPU0 reset will be held until boot core writes this
 *    bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU0_SHIFT)) & SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU0_MASK)

#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU1_MASK (0x4U)
#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU1_SHIFT (2U)
/*! BT_RELEASE_A55_CPU1 - If M33 boot, the CA55 CPU1 reset will be held until boot core writes this
 *    bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU1_SHIFT)) & SRC_GENERAL_REG_SCR_BT_RELEASE_A55_CPU1_MASK)

#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_PLAT_MASK (0x8U)
#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_PLAT_SHIFT (3U)
/*! BT_RELEASE_A55_PLAT - If M33 boot, the CA55 platform reset will be held until boot core writes
 *    this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GENERAL_REG_SCR_BT_RELEASE_A55_PLAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SCR_BT_RELEASE_A55_PLAT_SHIFT)) & SRC_GENERAL_REG_SCR_BT_RELEASE_A55_PLAT_MASK)

#define SRC_GENERAL_REG_SCR_BT_RELEASE_ML_MASK   (0x10U)
#define SRC_GENERAL_REG_SCR_BT_RELEASE_ML_SHIFT  (4U)
/*! BT_RELEASE_ML - MLMIX reset will be held until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GENERAL_REG_SCR_BT_RELEASE_ML(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SCR_BT_RELEASE_ML_SHIFT)) & SRC_GENERAL_REG_SCR_BT_RELEASE_ML_MASK)

#define SRC_GENERAL_REG_SCR_BT_RELEASE_MEDIA_MASK (0x20U)
#define SRC_GENERAL_REG_SCR_BT_RELEASE_MEDIA_SHIFT (5U)
/*! BT_RELEASE_MEDIA - MEDIAMIX reset will be held until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GENERAL_REG_SCR_BT_RELEASE_MEDIA(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SCR_BT_RELEASE_MEDIA_SHIFT)) & SRC_GENERAL_REG_SCR_BT_RELEASE_MEDIA_MASK)

#define SRC_GENERAL_REG_SCR_BT_RELEASE_DDR_MASK  (0x40U)
#define SRC_GENERAL_REG_SCR_BT_RELEASE_DDR_SHIFT (6U)
/*! BT_RELEASE_DDR - If M33 boot, the DDRMIX reset will be held until boot core writes this bit to
 *    1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GENERAL_REG_SCR_BT_RELEASE_DDR(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SCR_BT_RELEASE_DDR_SHIFT)) & SRC_GENERAL_REG_SCR_BT_RELEASE_DDR_MASK)
/*! @} */

/*! @name SRTMR - SRC RESET TRIGGER MODE REGISTER */
/*! @{ */

#define SRC_GENERAL_REG_SRTMR_WDOG1_TRIG_MODE_MASK (0x1U)
#define SRC_GENERAL_REG_SRTMR_WDOG1_TRIG_MODE_SHIFT (0U)
/*! WDOG1_TRIG_MODE - WDOG1 reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_WDOG1_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_WDOG1_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_WDOG1_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_WDOG2_TRIG_MODE_MASK (0x2U)
#define SRC_GENERAL_REG_SRTMR_WDOG2_TRIG_MODE_SHIFT (1U)
/*! WDOG2_TRIG_MODE - WDOG2 reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_WDOG2_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_WDOG2_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_WDOG2_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_WDOG3_TRIG_MODE_MASK (0x4U)
#define SRC_GENERAL_REG_SRTMR_WDOG3_TRIG_MODE_SHIFT (2U)
/*! WDOG3_TRIG_MODE - WDOG3 reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_WDOG3_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_WDOG3_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_WDOG3_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_WDOG4_TRIG_MODE_MASK (0x8U)
#define SRC_GENERAL_REG_SRTMR_WDOG4_TRIG_MODE_SHIFT (3U)
/*! WDOG4_TRIG_MODE - WDOG4 reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_WDOG4_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_WDOG4_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_WDOG4_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_WDOG5_TRIG_MODE_MASK (0x10U)
#define SRC_GENERAL_REG_SRTMR_WDOG5_TRIG_MODE_SHIFT (4U)
/*! WDOG5_TRIG_MODE - WDOG5 reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_WDOG5_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_WDOG5_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_WDOG5_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_TEMPSENSE_TRIG_MODE_MASK (0x20U)
#define SRC_GENERAL_REG_SRTMR_TEMPSENSE_TRIG_MODE_SHIFT (5U)
/*! TEMPSENSE_TRIG_MODE - Tempsense reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_TEMPSENSE_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_TEMPSENSE_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_TEMPSENSE_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_CSU_TRIG_MODE_MASK (0x40U)
#define SRC_GENERAL_REG_SRTMR_CSU_TRIG_MODE_SHIFT (6U)
/*! CSU_TRIG_MODE - CSU reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_CSU_TRIG_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_CSU_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_CSU_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_JTAGSW_TRIG_MODE_MASK (0x80U)
#define SRC_GENERAL_REG_SRTMR_JTAGSW_TRIG_MODE_SHIFT (7U)
/*! JTAGSW_TRIG_MODE - JTAGSW reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_JTAGSW_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_JTAGSW_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_JTAGSW_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_CM33_RESET_TRIG_MODE_MASK (0x100U)
#define SRC_GENERAL_REG_SRTMR_CM33_RESET_TRIG_MODE_SHIFT (8U)
/*! CM33_RESET_TRIG_MODE - CM33 reset trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_CM33_RESET_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_CM33_RESET_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_CM33_RESET_TRIG_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_CM33_LOCKUP_TRIG_MODE_MASK (0x200U)
#define SRC_GENERAL_REG_SRTMR_CM33_LOCKUP_TRIG_MODE_SHIFT (9U)
/*! CM33_LOCKUP_TRIG_MODE - CM33 lockup trigger mode configuration,locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_REG_SRTMR_CM33_LOCKUP_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_CM33_LOCKUP_TRIG_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_CM33_LOCKUP_TRIG_MODE_MASK)
/*! @} */

/*! @name SRMASK - SRC RESET TRIGGER MODE REGISTER */
/*! @{ */

#define SRC_GENERAL_REG_SRMASK_WDOG1_MASK_MASK   (0x1U)
#define SRC_GENERAL_REG_SRMASK_WDOG1_MASK_SHIFT  (0U)
/*! WDOG1_MASK - WDOG1 reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_WDOG1_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_WDOG1_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_WDOG1_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_WDOG2_MASK_MASK   (0x2U)
#define SRC_GENERAL_REG_SRMASK_WDOG2_MASK_SHIFT  (1U)
/*! WDOG2_MASK - WDOG2 reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_WDOG2_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_WDOG2_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_WDOG2_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_WDOG3_MASK_MASK   (0x4U)
#define SRC_GENERAL_REG_SRMASK_WDOG3_MASK_SHIFT  (2U)
/*! WDOG3_MASK - WDOG3 reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_WDOG3_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_WDOG3_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_WDOG3_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_WDOG4_MASK_MASK   (0x8U)
#define SRC_GENERAL_REG_SRMASK_WDOG4_MASK_SHIFT  (3U)
/*! WDOG4_MASK - WDOG4 reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_WDOG4_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_WDOG4_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_WDOG4_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_WDOG5_MASK_MASK   (0x10U)
#define SRC_GENERAL_REG_SRMASK_WDOG5_MASK_SHIFT  (4U)
/*! WDOG5_MASK - WDOG5 reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_WDOG5_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_WDOG5_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_WDOG5_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_TEMPSENSE_MASK_MASK (0x20U)
#define SRC_GENERAL_REG_SRMASK_TEMPSENSE_MASK_SHIFT (5U)
/*! TEMPSENSE_MASK - Tempsense reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_TEMPSENSE_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_TEMPSENSE_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_TEMPSENSE_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_CSU_MASK_MASK     (0x40U)
#define SRC_GENERAL_REG_SRMASK_CSU_MASK_SHIFT    (6U)
/*! CSU_MASK - CSU reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_CSU_MASK(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_CSU_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_CSU_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_JTAGSW_MASK_MASK  (0x80U)
#define SRC_GENERAL_REG_SRMASK_JTAGSW_MASK_SHIFT (7U)
/*! JTAGSW_MASK - JTAG SW reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_JTAGSW_MASK(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_JTAGSW_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_JTAGSW_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_CM33_RESET_MASK_MASK (0x100U)
#define SRC_GENERAL_REG_SRMASK_CM33_RESET_MASK_SHIFT (8U)
/*! CM33_RESET_MASK - CM33 reset mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_CM33_RESET_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_CM33_RESET_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_CM33_RESET_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_CM33_LOCKUP_MASK_MASK (0x200U)
#define SRC_GENERAL_REG_SRMASK_CM33_LOCKUP_MASK_SHIFT (9U)
/*! CM33_LOCKUP_MASK - CM33 lockup mask, locked by LOCK_CFG field.
 *  0b0..The cold reset source can work.
 *  0b1..The cold reset source is masked and cannot work.
 */
#define SRC_GENERAL_REG_SRMASK_CM33_LOCKUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_CM33_LOCKUP_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_CM33_LOCKUP_MASK_MASK)
/*! @} */

/*! @name SRMR1 - SRC RESET MODE REGISTER 1 */
/*! @{ */

#define SRC_GENERAL_REG_SRMR1_WDOG1_RESET_MODE_MASK (0xFFFFU)
#define SRC_GENERAL_REG_SRMR1_WDOG1_RESET_MODE_SHIFT (0U)
/*! WDOG1_RESET_MODE - WDOG1 reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR1_WDOG1_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR1_WDOG1_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR1_WDOG1_RESET_MODE_MASK)

#define SRC_GENERAL_REG_SRMR1_WDOG2_RESET_MODE_MASK (0xFFFF0000U)
#define SRC_GENERAL_REG_SRMR1_WDOG2_RESET_MODE_SHIFT (16U)
/*! WDOG2_RESET_MODE - WDOG2 reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR1_WDOG2_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR1_WDOG2_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR1_WDOG2_RESET_MODE_MASK)
/*! @} */

/*! @name SRMR2 - SRC RESET MODE REGISTER 2 */
/*! @{ */

#define SRC_GENERAL_REG_SRMR2_WDOG3_RESET_MODE_MASK (0xFFFFU)
#define SRC_GENERAL_REG_SRMR2_WDOG3_RESET_MODE_SHIFT (0U)
/*! WDOG3_RESET_MODE - WDOG3 reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR2_WDOG3_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR2_WDOG3_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR2_WDOG3_RESET_MODE_MASK)

#define SRC_GENERAL_REG_SRMR2_WDOG4_RESET_MODE_MASK (0xFFFF0000U)
#define SRC_GENERAL_REG_SRMR2_WDOG4_RESET_MODE_SHIFT (16U)
/*! WDOG4_RESET_MODE - WDOG4 reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR2_WDOG4_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR2_WDOG4_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR2_WDOG4_RESET_MODE_MASK)
/*! @} */

/*! @name SRMR3 - SRC RESET MODE REGISTER 3 */
/*! @{ */

#define SRC_GENERAL_REG_SRMR3_WDOG5_RESET_MODE_MASK (0xFFFFU)
#define SRC_GENERAL_REG_SRMR3_WDOG5_RESET_MODE_SHIFT (0U)
/*! WDOG5_RESET_MODE - WDOG5 reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR3_WDOG5_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR3_WDOG5_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR3_WDOG5_RESET_MODE_MASK)

#define SRC_GENERAL_REG_SRMR3_TEMPSENSE_RESET_MODE_MASK (0xFFFF0000U)
#define SRC_GENERAL_REG_SRMR3_TEMPSENSE_RESET_MODE_SHIFT (16U)
/*! TEMPSENSE_RESET_MODE - Tempsense reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR3_TEMPSENSE_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR3_TEMPSENSE_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR3_TEMPSENSE_RESET_MODE_MASK)
/*! @} */

/*! @name SRMR4 - SRC RESET MODE REGISTER 4 */
/*! @{ */

#define SRC_GENERAL_REG_SRMR4_CSU_RESET_MODE_MASK (0xFFFFU)
#define SRC_GENERAL_REG_SRMR4_CSU_RESET_MODE_SHIFT (0U)
/*! CSU_RESET_MODE - CSU reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR4_CSU_RESET_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR4_CSU_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR4_CSU_RESET_MODE_MASK)

#define SRC_GENERAL_REG_SRMR4_JTAGSW_RESET_MODE_MASK (0xFFFF0000U)
#define SRC_GENERAL_REG_SRMR4_JTAGSW_RESET_MODE_SHIFT (16U)
/*! JTAGSW_RESET_MODE - JTAG SW reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR4_JTAGSW_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR4_JTAGSW_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR4_JTAGSW_RESET_MODE_MASK)
/*! @} */

/*! @name SRMR5 - SRC RESET MODE REGISTER 5 */
/*! @{ */

#define SRC_GENERAL_REG_SRMR5_CM33_RESET_MODE_MASK (0xFFFFU)
#define SRC_GENERAL_REG_SRMR5_CM33_RESET_MODE_SHIFT (0U)
/*! CM33_RESET_MODE - CM33 sysrstreq reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR5_CM33_RESET_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR5_CM33_RESET_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR5_CM33_RESET_MODE_MASK)

#define SRC_GENERAL_REG_SRMR5_CM33_LOCKUP_MODE_MASK (0xFFFF0000U)
#define SRC_GENERAL_REG_SRMR5_CM33_LOCKUP_MODE_SHIFT (16U)
/*! CM33_LOCKUP_MODE - CM33 lockup reset mode configuration, locked by LOCK_CFG field.
 *  0b0000000000000000..system
 *  0b0000000000000001..bit0: AONMIX
 *  0b0000000000000010..bit1: WAKEUPMIX
 *  0b0000000000000100..bit2: DDRMIX
 *  0b0000000000001000..bit3: DRAM PHY
 *  0b0000000000010000..MLMIX
 *  0b0000000000100000..bit5: NICMIX
 *  0b0000000001000000..bit6: HSIOMIX
 *  0b0000000010000000..bit7: MEDIAMIX
 *  0b0000000100000000..bit8: CM33_Platform
 *  0b0000001000000000..bit9: CA55_CPU0
 *  0b0000010000000000..bit10: CA55_CPU1
 *  0b0000100000000000..bit11: CA55_Platform
 */
#define SRC_GENERAL_REG_SRMR5_CM33_LOCKUP_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR5_CM33_LOCKUP_MODE_SHIFT)) & SRC_GENERAL_REG_SRMR5_CM33_LOCKUP_MODE_MASK)
/*! @} */

/*! @name SBMR1 - SRC Boot Mode Register 1 */
/*! @{ */

#define SRC_GENERAL_REG_SBMR1_BOOT_CFG0_MASK     (0xFFFFFFFFU)
#define SRC_GENERAL_REG_SBMR1_BOOT_CFG0_SHIFT    (0U)
/*! BOOT_CFG0 - This bit field stores the BOOT_CFG8 fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GENERAL_REG_SBMR1_BOOT_CFG0(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR1_BOOT_CFG0_SHIFT)) & SRC_GENERAL_REG_SBMR1_BOOT_CFG0_MASK)
/*! @} */

/*! @name SBMR2 - SRC Boot Mode Register 2 */
/*! @{ */

#define SRC_GENERAL_REG_SBMR2_BOOT_CFG1_MASK     (0xFFFFU)
#define SRC_GENERAL_REG_SBMR2_BOOT_CFG1_SHIFT    (0U)
/*! BOOT_CFG1 - This bit field stores the BOOT_CFG0[15:0] fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GENERAL_REG_SBMR2_BOOT_CFG1(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_BOOT_CFG1_SHIFT)) & SRC_GENERAL_REG_SBMR2_BOOT_CFG1_MASK)

#define SRC_GENERAL_REG_SBMR2_SDP_DIS_MASK       (0x10000U)
#define SRC_GENERAL_REG_SBMR2_SDP_DIS_SHIFT      (16U)
/*! SDP_DIS - Please see the fusemap for fuse details. */
#define SRC_GENERAL_REG_SBMR2_SDP_DIS(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_SDP_DIS_SHIFT)) & SRC_GENERAL_REG_SBMR2_SDP_DIS_MASK)

#define SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_MASK (0x3F000000U)
#define SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_SHIFT (24U)
/*! IPP_BOOT_MODE - Boot mode from pins */
#define SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_SHIFT)) & SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_MASK)

#define SRC_GENERAL_REG_SBMR2_DIT_BT_DIS_MASK    (0x80000000U)
#define SRC_GENERAL_REG_SBMR2_DIT_BT_DIS_SHIFT   (31U)
/*! DIT_BT_DIS - Please see the fusemap for fuse details. */
#define SRC_GENERAL_REG_SBMR2_DIT_BT_DIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_DIT_BT_DIS_SHIFT)) & SRC_GENERAL_REG_SBMR2_DIT_BT_DIS_MASK)
/*! @} */

/*! @name SRSR - SRC Reset Status Register */
/*! @{ */

#define SRC_GENERAL_REG_SRSR_SRC_POR_B_MASK      (0x1U)
#define SRC_GENERAL_REG_SRSR_SRC_POR_B_SHIFT     (0U)
/*! SRC_POR_B - Indicates whether the reset was the result of the system_por_b or jtag_rst_b.
 *  0b0..Reset is not caused by system_por_b or jtag_rst_b event.
 *  0b1..Reset is caused by system_por_b or jtag_rst_b event.
 */
#define SRC_GENERAL_REG_SRSR_SRC_POR_B(x)        (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_SRC_POR_B_SHIFT)) & SRC_GENERAL_REG_SRSR_SRC_POR_B_MASK)

#define SRC_GENERAL_REG_SRSR_JTAG_RST_B_MASK     (0x2U)
#define SRC_GENERAL_REG_SRSR_JTAG_RST_B_SHIFT    (1U)
/*! JTAG_RST_B - Indicates whether the reset was the result of jtag_rst_b.
 *  0b0..Reset is not caused by JTAG_RST_B.
 *  0b1..Reset is caused by JTAG_RST_B.
 */
#define SRC_GENERAL_REG_SRSR_JTAG_RST_B(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_JTAG_RST_B_SHIFT)) & SRC_GENERAL_REG_SRSR_JTAG_RST_B_MASK)

#define SRC_GENERAL_REG_SRSR_IPP_USER_RESET_B_MASK (0x4U)
#define SRC_GENERAL_REG_SRSR_IPP_USER_RESET_B_SHIFT (2U)
/*! IPP_USER_RESET_B - Indicates whether the reset was the result of ipp_user_reset_b.
 *  0b0..Reset is not caused by IPP_USER_RESET_B.
 *  0b1..Reset is caused by IPP_USER_RESET_B.
 */
#define SRC_GENERAL_REG_SRSR_IPP_USER_RESET_B(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_IPP_USER_RESET_B_SHIFT)) & SRC_GENERAL_REG_SRSR_IPP_USER_RESET_B_MASK)

#define SRC_GENERAL_REG_SRSR_WDOG1_RST_B_MASK    (0x8U)
#define SRC_GENERAL_REG_SRSR_WDOG1_RST_B_SHIFT   (3U)
/*! WDOG1_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog1 time-out event.
 *  0b0..Reset is not caused by the watchdog1 time-out event.
 *  0b1..Reset is caused by the watchdog1 time-out event.
 */
#define SRC_GENERAL_REG_SRSR_WDOG1_RST_B(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_WDOG1_RST_B_SHIFT)) & SRC_GENERAL_REG_SRSR_WDOG1_RST_B_MASK)

#define SRC_GENERAL_REG_SRSR_WDOG2_RST_B_MASK    (0x10U)
#define SRC_GENERAL_REG_SRSR_WDOG2_RST_B_SHIFT   (4U)
/*! WDOG2_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog2 time-out event.
 *  0b0..Reset is not caused by the watchdog2 time-out event.
 *  0b1..Reset is caused by the watchdog2 time-out event.
 */
#define SRC_GENERAL_REG_SRSR_WDOG2_RST_B(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_WDOG2_RST_B_SHIFT)) & SRC_GENERAL_REG_SRSR_WDOG2_RST_B_MASK)

#define SRC_GENERAL_REG_SRSR_WDOG3_RST_B_MASK    (0x20U)
#define SRC_GENERAL_REG_SRSR_WDOG3_RST_B_SHIFT   (5U)
/*! WDOG3_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog3 time-out
 *  0b0..Reset is not caused by the watchdog3 time-out event.
 *  0b1..Reset is caused by the watchdog3 time-out event.
 */
#define SRC_GENERAL_REG_SRSR_WDOG3_RST_B(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_WDOG3_RST_B_SHIFT)) & SRC_GENERAL_REG_SRSR_WDOG3_RST_B_MASK)

#define SRC_GENERAL_REG_SRSR_WDOG4_RST_B_MASK    (0x40U)
#define SRC_GENERAL_REG_SRSR_WDOG4_RST_B_SHIFT   (6U)
/*! WDOG4_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog4 time-out
 *  0b0..Reset is not caused by the watchdog4 time-out event.
 *  0b1..Reset is caused by the watchdog4 time-out event.
 */
#define SRC_GENERAL_REG_SRSR_WDOG4_RST_B(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_WDOG4_RST_B_SHIFT)) & SRC_GENERAL_REG_SRSR_WDOG4_RST_B_MASK)

#define SRC_GENERAL_REG_SRSR_WDOG5_RST_B_MASK    (0x80U)
#define SRC_GENERAL_REG_SRSR_WDOG5_RST_B_SHIFT   (7U)
/*! WDOG5_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog5 time-out
 *  0b0..Reset is not caused by the watchdog5 time-out event.
 *  0b1..Reset is caused by the watchdog5 time-out event.
 */
#define SRC_GENERAL_REG_SRSR_WDOG5_RST_B(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_WDOG5_RST_B_SHIFT)) & SRC_GENERAL_REG_SRSR_WDOG5_RST_B_MASK)

#define SRC_GENERAL_REG_SRSR_TEMPSENSE_RST_B_MASK (0x100U)
#define SRC_GENERAL_REG_SRSR_TEMPSENSE_RST_B_SHIFT (8U)
/*! TEMPSENSE_RST_B - Temper Sensor software reset. Indicates whether the reset was the result of Temperature Sensor.
 *  0b0..Reset is not caused by Temperature Sensor.
 *  0b1..Reset is caused by Temperature Sensor.
 */
#define SRC_GENERAL_REG_SRSR_TEMPSENSE_RST_B(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_TEMPSENSE_RST_B_SHIFT)) & SRC_GENERAL_REG_SRSR_TEMPSENSE_RST_B_MASK)

#define SRC_GENERAL_REG_SRSR_CSU_RESET_B_MASK    (0x200U)
#define SRC_GENERAL_REG_SRSR_CSU_RESET_B_SHIFT   (9U)
/*! CSU_RESET_B - Indicates whether the reset was the result of the csu_reset_b input.
 *  0b0..Reset is not caused by the csu_reset_b event.
 *  0b1..Reset is caused by the csu_reset_b event.
 */
#define SRC_GENERAL_REG_SRSR_CSU_RESET_B(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_CSU_RESET_B_SHIFT)) & SRC_GENERAL_REG_SRSR_CSU_RESET_B_MASK)

#define SRC_GENERAL_REG_SRSR_JTAG_SW_RST_MASK    (0x400U)
#define SRC_GENERAL_REG_SRSR_JTAG_SW_RST_SHIFT   (10U)
/*! JTAG_SW_RST - JTAG software reset. Indicates whether the reset was the result of JTAG_SW_RST.
 *  0b0..Reset is not caused by JTAG_SW_RST.
 *  0b1..Reset is caused by JTAG_SW_RST.
 */
#define SRC_GENERAL_REG_SRSR_JTAG_SW_RST(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_JTAG_SW_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_JTAG_SW_RST_MASK)

#define SRC_GENERAL_REG_SRSR_CM33_REQUEST_MASK   (0x800U)
#define SRC_GENERAL_REG_SRSR_CM33_REQUEST_SHIFT  (11U)
/*! CM33_REQUEST - Indicates whether reset was the result of CM33 reset request
 *  0b0..Reset is not caused by CM33 reset request.
 *  0b1..Reset is caused by CM33 reset request.
 */
#define SRC_GENERAL_REG_SRSR_CM33_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_CM33_REQUEST_SHIFT)) & SRC_GENERAL_REG_SRSR_CM33_REQUEST_MASK)

#define SRC_GENERAL_REG_SRSR_CM33_LOCKUP_MASK    (0x1000U)
#define SRC_GENERAL_REG_SRSR_CM33_LOCKUP_SHIFT   (12U)
/*! CM33_LOCKUP - Indicates a reset has been caused by CM33 CPU lockup
 *  0b0..Reset is not caused by CM33 lockup.
 *  0b1..Reset is caused by CM33 lockup.
 */
#define SRC_GENERAL_REG_SRSR_CM33_LOCKUP(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_CM33_LOCKUP_SHIFT)) & SRC_GENERAL_REG_SRSR_CM33_LOCKUP_MASK)

#define SRC_GENERAL_REG_SRSR_AONMIX_RST_MASK     (0x10000U)
#define SRC_GENERAL_REG_SRSR_AONMIX_RST_SHIFT    (16U)
/*! AONMIX_RST - Indicates whether a AONMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..AONMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_AONMIX_RST(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_AONMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_AONMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_WAKEUPMIX_RST_MASK  (0x20000U)
#define SRC_GENERAL_REG_SRSR_WAKEUPMIX_RST_SHIFT (17U)
/*! WAKEUPMIX_RST - Indicates whether a WAKEUPMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..WAKEUPMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_WAKEUPMIX_RST(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_WAKEUPMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_WAKEUPMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_DDRMIX_RST_MASK     (0x40000U)
#define SRC_GENERAL_REG_SRSR_DDRMIX_RST_SHIFT    (18U)
/*! DDRMIX_RST - Indicates whether a DDRMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..DDRMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_DDRMIX_RST(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_DDRMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_DDRMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_DDRPHY_RST_MASK     (0x80000U)
#define SRC_GENERAL_REG_SRSR_DDRPHY_RST_SHIFT    (19U)
/*! DDRPHY_RST - Indicates whether a DDRPHY slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..DDRPHY slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_DDRPHY_RST(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_DDRPHY_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_DDRPHY_RST_MASK)

#define SRC_GENERAL_REG_SRSR_MLMIX_RST_MASK      (0x100000U)
#define SRC_GENERAL_REG_SRSR_MLMIX_RST_SHIFT     (20U)
/*! MLMIX_RST - Indicates whether a MLMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..MLMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_MLMIX_RST(x)        (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_MLMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_MLMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_NICMIX_RST_MASK     (0x200000U)
#define SRC_GENERAL_REG_SRSR_NICMIX_RST_SHIFT    (21U)
/*! NICMIX_RST - Indicates whether a NICMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..NICMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_NICMIX_RST(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_NICMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_NICMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_HSIOMIX_RST_MASK    (0x400000U)
#define SRC_GENERAL_REG_SRSR_HSIOMIX_RST_SHIFT   (22U)
/*! HSIOMIX_RST - Indicates whether a HSIOMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..HSIOMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_HSIOMIX_RST(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_HSIOMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_HSIOMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_MEDIAMIX_RST_MASK   (0x800000U)
#define SRC_GENERAL_REG_SRSR_MEDIAMIX_RST_SHIFT  (23U)
/*! MEDIAMIX_RST - Indicates whether a MEDIAMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..MEDIAMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_MEDIAMIX_RST(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_MEDIAMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_MEDIAMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_M33PMIX_RST_MASK    (0x1000000U)
#define SRC_GENERAL_REG_SRSR_M33PMIX_RST_SHIFT   (24U)
/*! M33PMIX_RST - Indicates whether a M33PMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..M33PMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_M33PMIX_RST(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_M33PMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_M33PMIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_A55C0MIX_RST_MASK   (0x2000000U)
#define SRC_GENERAL_REG_SRSR_A55C0MIX_RST_SHIFT  (25U)
/*! A55C0MIX_RST - Indicates whether a A55C0MIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..A55C0MIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_A55C0MIX_RST(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_A55C0MIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_A55C0MIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_A55C1MIX_RST_MASK   (0x4000000U)
#define SRC_GENERAL_REG_SRSR_A55C1MIX_RST_SHIFT  (26U)
/*! A55C1MIX_RST - Indicates whether a A55C1MIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..A55C1MIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_A55C1MIX_RST(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_A55C1MIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_A55C1MIX_RST_MASK)

#define SRC_GENERAL_REG_SRSR_A55PMIX_RST_MASK    (0x8000000U)
#define SRC_GENERAL_REG_SRSR_A55PMIX_RST_SHIFT   (27U)
/*! A55PMIX_RST - Indicates whether a A55PMIX slice reset happens
 *  0b0..Power on reset or system cold reset happens.
 *  0b1..A55PMIX slice reset happens.
 */
#define SRC_GENERAL_REG_SRSR_A55PMIX_RST(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRSR_A55PMIX_RST_SHIFT)) & SRC_GENERAL_REG_SRSR_A55PMIX_RST_MASK)
/*! @} */

/*! @name GPR16 - SRC General Purpose Register 16 */
/*! @{ */

#define SRC_GENERAL_REG_GPR16_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR16_GPR_SHIFT          (0U)
/*! GPR - General Purpose */
#define SRC_GENERAL_REG_GPR16_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR16_GPR_SHIFT)) & SRC_GENERAL_REG_GPR16_GPR_MASK)
/*! @} */

/*! @name GPR17 - SRC General Purpose Register 17 */
/*! @{ */

#define SRC_GENERAL_REG_GPR17_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR17_GPR_SHIFT          (0U)
/*! GPR - General Purpose */
#define SRC_GENERAL_REG_GPR17_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR17_GPR_SHIFT)) & SRC_GENERAL_REG_GPR17_GPR_MASK)
/*! @} */

/*! @name GPR18 - SRC General Purpose Register 18 */
/*! @{ */

#define SRC_GENERAL_REG_GPR18_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR18_GPR_SHIFT          (0U)
/*! GPR - General Purpose */
#define SRC_GENERAL_REG_GPR18_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR18_GPR_SHIFT)) & SRC_GENERAL_REG_GPR18_GPR_MASK)
/*! @} */

/*! @name GPR19 - SRC General Purpose Register 19 */
/*! @{ */

#define SRC_GENERAL_REG_GPR19_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR19_GPR_SHIFT          (0U)
/*! GPR - General Purpose */
#define SRC_GENERAL_REG_GPR19_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR19_GPR_SHIFT)) & SRC_GENERAL_REG_GPR19_GPR_MASK)
/*! @} */

/*! @name GPR20 - SRC General Purpose Register 20 */
/*! @{ */

#define SRC_GENERAL_REG_GPR20_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR20_GPR_SHIFT          (0U)
/*! GPR - General Purpose */
#define SRC_GENERAL_REG_GPR20_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR20_GPR_SHIFT)) & SRC_GENERAL_REG_GPR20_GPR_MASK)
/*! @} */

/*! @name CM_QUIESCE - SRC_CORTEX_M_QUIESCE */
/*! @{ */

#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_MASK (0x1U)
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_SHIFT (0U)
/*! SAFE_CM33_AHB_REQ - CM33 platform safe reset req control
 *  0b0..No effect
 *  0b1..request CM33 platform to be reset at safe state
 */
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_SHIFT)) & SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_MASK)

#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_MASK (0x2U)
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_SHIFT (1U)
/*! SAFE_CM33_AHB_ACK_STAT - CM33 platform safe reset ahb ack status
 *  0b0..No CM33 platform safe reset req or it could not be placed in safe state for reset sequencing
 *  0b1..CM33 platform is in safe state for reset sequencing
 */
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_SHIFT)) & SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_MASK)
/*! @} */

/*! @name COLD_RESET_SSAR_ACK_CTRL - Cold reset SSAR acknowledge control */
/*! @{ */

#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK (0x3FFFU)
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT (0U)
/*! SSAR_CNT_CFG - ssar count configure. Usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT)) & SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK)

#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode. Locked by LOCK_CFG field
 *  0b00..Not use counter, raise done to cold_reset_controller once get EdgeLock Enclave ack
 *  0b01..Delay after receiving EdgeLock Enclave ack, delay cycle number is CNT_CFG
 *  0b10..Ignore EdgeLock Enclave ack, raise done to cold_reset_controller when counting to CNT_CFG value
 *  0b11..Time out mode, raise done to cold_reset_controller when either EdgeLock Enclave ack received or counting to CNT_CFG value
 */
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name SP_ISO_CTRL - SRC special ISO Control */
/*! @{ */

#define SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY1_ISO_MASK (0x1U)
#define SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY1_ISO_SHIFT (0U)
/*! USB_PHY1_ISO - Software control USB PHY1 isolation enable
 *  0b0..Isolation disable
 *  0b1..Isolation enable
 */
#define SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY1_ISO(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY1_ISO_SHIFT)) & SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY1_ISO_MASK)

#define SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY2_ISO_MASK (0x2U)
#define SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY2_ISO_SHIFT (1U)
/*! USB_PHY2_ISO - Software control USB PHY2 isolation enable
 *  0b0..Isolation disable
 *  0b1..Isolation enable
 */
#define SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY2_ISO(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY2_ISO_SHIFT)) & SRC_GENERAL_REG_SP_ISO_CTRL_USB_PHY2_ISO_MASK)

#define SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_CSI_ISO_MASK (0x4U)
#define SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_CSI_ISO_SHIFT (2U)
/*! MIPI_CSI_ISO - Software control MIPI CSI isolation enable
 *  0b0..Isolation disable
 *  0b1..Isolation enable
 */
#define SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_CSI_ISO(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_CSI_ISO_SHIFT)) & SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_CSI_ISO_MASK)

#define SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_DSI_ISO_MASK (0x8U)
#define SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_DSI_ISO_SHIFT (3U)
/*! MIPI_DSI_ISO - Software control MIPI DSI isolation enable
 *  0b0..Isolation disable
 *  0b1..Isolation enable
 */
#define SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_DSI_ISO(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_DSI_ISO_SHIFT)) & SRC_GENERAL_REG_SP_ISO_CTRL_MIPI_DSI_ISO_MASK)
/*! @} */

/*! @name ROM_LP_CTRL - ROM Low Power Control */
/*! @{ */

#define SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_MASK (0x1U)
#define SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_SHIFT (0U)
/*! AONMIX_ROM_LP_EN - ROM in AONMIX low power control enable */
#define SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_SHIFT)) & SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_MASK)
/*! @} */

/*! @name A55_DENY_STAT - A55 Q_Channel Deny Status */
/*! @{ */

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_MASK (0x1U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_SHIFT (0U)
/*! A55_CORE0_PWRDN_DENY_STAT - A55 CORE 0 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_MASK (0x2U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_SHIFT (1U)
/*! A55_CORE1_PWRDN_DENY_STAT - A55 CORE 1 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_MASK (0x4U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_SHIFT (2U)
/*! A55_CLUSTER_PWRDN_DENY_STAT - A55 Cluster Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_MASK (0x8U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_SHIFT (3U)
/*! A55_CLUSTER_CLKOFF_DENY_STAT - A55 Cluster Q_Channel clockoff deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_GENERAL_REG_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_GENERAL_REG_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_GENERAL_REG_H_ */
