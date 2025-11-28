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
**         CMSIS Peripheral Access Layer for SRC_MIX_SLICE
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
 * @file PERI_SRC_MIX_SLICE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC_MIX_SLICE
 *
 * CMSIS Peripheral Access Layer for SRC_MIX_SLICE
 */

#if !defined(PERI_SRC_MIX_SLICE_H_)
#define PERI_SRC_MIX_SLICE_H_                    /**< Symbol preventing repeated inclusion */

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
   -- SRC_MIX_SLICE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MIX_SLICE_Peripheral_Access_Layer SRC_MIX_SLICE Peripheral Access Layer
 * @{
 */

/** SRC_MIX_SLICE - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t LPM_SETTING_0;                     /**< Low power mode setting, offset: 0x10 */
  __IO uint32_t LPM_SETTING_1;                     /**< Low power mode setting, offset: 0x14 */
  __IO uint32_t LPM_SETTING_2;                     /**< Low power mode setting, offset: 0x18 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SLICE_SW_CTRL;                     /**< Slice software control, offset: 0x20 */
  __IO uint32_t SINGLE_RESET_SW_CTRL;              /**< Single reset by software control, offset: 0x24 */
       uint8_t RESERVED_3[24];
  __IO uint32_t A55_HDSK_ACK_CTRL;                 /**< A55 handshake acknowledge control, offset: 0x40 */
  __I  uint32_t A55_HDSK_ACK_STAT;                 /**< A55 handshake acknowledge status, offset: 0x44 */
       uint8_t RESERVED_4[8];
  __IO uint32_t SSAR_ACK_CTRL;                     /**< SSAR acknowledge control, offset: 0x50 */
  __I  uint32_t SSAR_ACK_STAT;                     /**< SSAR acknowledge status, offset: 0x54 */
       uint8_t RESERVED_5[4];
  __IO uint32_t ISO_OFF_DLY_POR;                   /**< iso off delay control when por, offset: 0x5C */
  __IO uint32_t ISO_ON_DLY;                        /**< iso on delay control, offset: 0x60 */
  __IO uint32_t ISO_OFF_DLY;                       /**< iso off delay control, offset: 0x64 */
  __IO uint32_t PSW_OFF_LF_DLY;                    /**< psw off lf delay control, offset: 0x68 */
       uint8_t RESERVED_6[4];
  __IO uint32_t PSW_OFF_HF_DLY;                    /**< psw off hf delay control, offset: 0x70 */
  __IO uint32_t PSW_ON_LF_DLY;                     /**< psw on lf delay control, offset: 0x74 */
  __IO uint32_t PSW_ON_HF_DLY;                     /**< psw on hf delay control, offset: 0x78 */
       uint8_t RESERVED_7[4];
  __IO uint32_t PSW_ACK_CTRL_0;                    /**< Power switch acknowledge control, offset: 0x80 */
  __IO uint32_t PSW_ACK_CTRL_1;                    /**< Power switch acknowledge control, offset: 0x84 */
  __I  uint32_t PSW_ACK_STAT;                      /**< PSW acknowledge status, offset: 0x88 */
       uint8_t RESERVED_8[4];
  __IO uint32_t MTR_ACK_CTRL;                      /**< MTR acknowledge control, offset: 0x90 */
  __I  uint32_t MTR_ACK_STAT;                      /**< MTR acknowledge status, offset: 0x94 */
       uint8_t RESERVED_9[8];
  __I  uint32_t UPI_STAT_0;                        /**< UPI status 0, offset: 0xA0 */
  __I  uint32_t UPI_STAT_1;                        /**< UPI status 1, offset: 0xA4 */
  __I  uint32_t UPI_STAT_2;                        /**< UPI status 2, offset: 0xA8 */
  __I  uint32_t UPI_STAT_3;                        /**< UPI status 3, offset: 0xAC */
  __I  uint32_t FSM_STAT;                          /**< FSM status, offset: 0xB0 */
  __I  uint32_t FUNC_STAT;                         /**< function status, offset: 0xB4 */
} SRC_MIX_SLICE_Type;

/* ----------------------------------------------------------------------------
   -- SRC_MIX_SLICE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MIX_SLICE_Register_Masks SRC_MIX_SLICE Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - Authentication Control */
/*! @{ */

#define SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_MASK  (0x4U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_SHIFT (2U)
/*! LPM_MODE - Low power control mode
 *  0b0..Low power mode controlled by software
 *  0b1..Low power mode controlled by GPC hardware
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_MASK  (0x80U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..Low power configuration fields are not locked.
 *  0b1..Low power configuration fields are locked.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_MASK   (0x100U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_SHIFT  (8U)
/*! TZ_USER - Allow user mode access
 *  0b0..This MIX SLICE registers can only be written in privilege mode.
 *  0b1..This MIX SLICE registers can be written either in privilege mode or user mode.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_MASK     (0x200U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_SHIFT    (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..This MIX SLICE registers can only be written in secure mode.
 *  0b1..This MIX SLICE registers can be written either in secure mode or non-secure mode.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_MASK   (0x800U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_SHIFT  (11U)
/*! LOCK_TZ - Lock NONSECURE and USER
 *  0b0..TZ_NS and TZ_USER value can be changed.
 *  0b1..TZ_NS and TZ_USER value cannot be changed.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..WHITE_LIST value cannot be changed.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write SRC MIX SLICE registers.
 *  0b0000000000000010..Core with domain ID=1 can write SRC MIX SLICE registers.
 *  0b0000000000000100..Core with domain ID=2 can write SRC MIX SLICE registers.
 *  0b0000000000001000..Core with domain ID=3 can write SRC MIX SLICE registers.
 *  0b0000000000010000..Core with domain ID=4 can write SRC MIX SLICE registers.
 *  0b0000000000100000..Core with domain ID=5 can write SRC MIX SLICE registers.
 *  0b0000000001000000..Core with domain ID=6 can write SRC MIX SLICE registers.
 *  0b0000000010000000..Core with domain ID=7 can write SRC MIX SLICE registers.
 *  0b0000000100000000..Core with domain ID=8 can write SRC MIX SLICE registers.
 *  0b0000001000000000..Core with domain ID=9 can write SRC MIX SLICE registers.
 *  0b0000010000000000..Core with domain ID=10 can write SRC MIX SLICE registers.
 *  0b0000100000000000..Core with domain ID=11 can write SRC MIX SLICE registers.
 *  0b0001000000000000..Core with domain ID=12 can write SRC MIX SLICE registers.
 *  0b0010000000000000..Core with domain ID=13 can write SRC MIX SLICE registers.
 *  0b0100000000000000..Core with domain ID=14 can write SRC MIX SLICE registers.
 *  0b1000000000000000..Core with domain ID=15 can write SRC MIX SLICE registers.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name LPM_SETTING_0 - Low power mode setting */
/*! @{ */

#define SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_MASK (0x7U)
#define SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_SHIFT (0U)
/*! LPM_SETTING_CD - LPM setting of current domain */
#define SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_MASK)
/*! @} */

/*! @name LPM_SETTING_1 - Low power mode setting */
/*! @{ */

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_MASK (0x7U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_SHIFT (0U)
/*! LPM_SETTING_D0 - LPM setting of domain 0
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_MASK (0x70U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_SHIFT (4U)
/*! LPM_SETTING_D1 - LPM setting of domain 1
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_MASK (0x700U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_SHIFT (8U)
/*! LPM_SETTING_D2 - LPM setting of domain 2
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_MASK (0x7000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_SHIFT (12U)
/*! LPM_SETTING_D3 - LPM setting of domain 3
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_MASK (0x70000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_SHIFT (16U)
/*! LPM_SETTING_D4 - LPM setting of domain 4
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_MASK (0x700000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_SHIFT (20U)
/*! LPM_SETTING_D5 - LPM setting of domain 5
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_MASK (0x7000000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_SHIFT (24U)
/*! LPM_SETTING_D6 - LPM setting of domain 6
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_MASK (0x70000000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_SHIFT (28U)
/*! LPM_SETTING_D7 - LPM setting of domain 7
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_MASK)
/*! @} */

/*! @name LPM_SETTING_2 - Low power mode setting */
/*! @{ */

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_MASK (0x7U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_SHIFT (0U)
/*! LPM_SETTING_D8 - LPM setting of domain 8
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_MASK (0x70U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_SHIFT (4U)
/*! LPM_SETTING_D9 - LPM setting of domain 9
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_MASK (0x700U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_SHIFT (8U)
/*! LPM_SETTING_D10 - LPM setting of domain 10
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_MASK (0x7000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_SHIFT (12U)
/*! LPM_SETTING_D11 - LPM setting of domain 11
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_MASK (0x70000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_SHIFT (16U)
/*! LPM_SETTING_D12 - LPM setting of domain 12
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_MASK (0x700000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_SHIFT (20U)
/*! LPM_SETTING_D13 - LPM setting of domain 13
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_MASK (0x7000000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_SHIFT (24U)
/*! LPM_SETTING_D14 - LPM setting of domain 14
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_MASK (0x70000000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_SHIFT (28U)
/*! LPM_SETTING_D15 - LPM setting of domain 15
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_MASK)
/*! @} */

/*! @name SLICE_SW_CTRL - Slice software control */
/*! @{ */

#define SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_MASK (0x1U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_SHIFT (0U)
/*! RST_CTRL_SOFT - Software reset control. Locked by LPM_MODE field.
 *  0b0..No effect or software reset deassert
 *  0b1..Software reset assert
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_CTRL_SOFT_MASK (0x4U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_CTRL_SOFT_SHIFT (2U)
/*! ISO_CTRL_SOFT - Software isolation control. Locked by LPM_MODE field.
 *  0b0..No effect or software iso off
 *  0b1..Software iso on
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_CTRL_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_CTRL_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_CTRL_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_CTRL_SOFT_MASK (0x10U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_CTRL_SOFT_SHIFT (4U)
/*! PSW_CTRL_SOFT - Software power switch control. Locked by LPM_MODE field.
 *  0b0..No effect or software power switch on
 *  0b1..Software power switch off
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_CTRL_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_CTRL_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_CTRL_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_MTR_LOAD_SOFT_MASK (0x40U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_MTR_LOAD_SOFT_SHIFT (6U)
/*! MTR_LOAD_SOFT - Software control MTR repair load. Locked by LPM_MODE field.
 *  0b0..No effect
 *  0b1..Software load MTR repair
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_MTR_LOAD_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_MTR_LOAD_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_MTR_LOAD_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_SSAR_CTRL_SOFT_MASK (0x100U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_SSAR_CTRL_SOFT_SHIFT (8U)
/*! SSAR_CTRL_SOFT - Software SSAR control. Locked by LPM_MODE field.
 *  0b0..No effect or software SSAR restore
 *  0b1..Software SSAR save
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_SSAR_CTRL_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_SSAR_CTRL_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_SSAR_CTRL_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_A55_HDSK_CTRL_SOFT_MASK (0x400U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_A55_HDSK_CTRL_SOFT_SHIFT (10U)
/*! A55_HDSK_CTRL_SOFT - Software A55 handshake control. Locked by LPM_MODE field.
 *  0b0..No effect or software notify A55 power up info
 *  0b1..Software notify A55 power down info
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_A55_HDSK_CTRL_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_A55_HDSK_CTRL_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_A55_HDSK_CTRL_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_SAFE_RESET_MASK (0x10000U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_SAFE_RESET_SHIFT (16U)
/*! SAFE_RESET - Only for CM33 safe reset feature
 *  0b0..No effect or software CM33 safe reset deassert
 *  0b1..Software CM33 safe reset assert
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_SAFE_RESET(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_SAFE_RESET_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_SAFE_RESET_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_MASK (0x80000000U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_SHIFT (31U)
/*! PDN_SOFT - Software power trans control, including reset, iso, and power switch. Locked by LPM_MODE field.
 *  0b0..No effect or software power up
 *  0b1..Software power down
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_MASK)
/*! @} */

/*! @name SINGLE_RESET_SW_CTRL - Single reset by software control */
/*! @{ */

#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_0_MASK (0x1U)
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_0_SHIFT (0U)
/*! RST_CTRL_SOFT_0 - Locked by LPM_MODE field. */
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_0(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_0_SHIFT)) & SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_0_MASK)

#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_1_MASK (0x4U)
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_1_SHIFT (2U)
/*! RST_CTRL_SOFT_1 - Locked by LPM_MODE field. */
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_1(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_1_SHIFT)) & SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_1_MASK)

#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_2_MASK (0x10U)
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_2_SHIFT (4U)
/*! RST_CTRL_SOFT_2 - Locked by LPM_MODE field.
 *  0b0..Software reset assert
 *  0b1..No effect or software reset deassert
 */
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_2(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_2_SHIFT)) & SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_2_MASK)

#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_3_MASK (0x40U)
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_3_SHIFT (6U)
/*! RST_CTRL_SOFT_3 - Locked by LPM_MODE field.
 *  0b0..Software reset assert
 *  0b1..No effect or software reset deassert
 */
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_3(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_3_SHIFT)) & SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_3_MASK)

#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_4_MASK (0x100U)
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_4_SHIFT (8U)
/*! RST_CTRL_SOFT_4 - Locked by LPM_MODE field.
 *  0b0..Software reset assert
 *  0b1..No effect or software reset deassert
 */
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_4(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_4_SHIFT)) & SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_4_MASK)

#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_5_MASK (0x400U)
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_5_SHIFT (10U)
/*! RST_CTRL_SOFT_5 - Locked by LPM_MODE field.
 *  0b0..software reset assert
 *  0b1..No effect or software reset deassert
 */
#define SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_5(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_5_SHIFT)) & SRC_MIX_SLICE_SINGLE_RESET_SW_CTRL_RST_CTRL_SOFT_5_MASK)
/*! @} */

/*! @name A55_HDSK_ACK_CTRL - A55 handshake acknowledge control */
/*! @{ */

#define SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_A55_HDSK_CNT_CFG_MASK (0xFFU)
#define SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_A55_HDSK_CNT_CFG_SHIFT (0U)
/*! A55_HDSK_CNT_CFG - A55 handshake count configure. Usage depends on CNT_MODE. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_A55_HDSK_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_A55_HDSK_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_A55_HDSK_CNT_CFG_MASK)

#define SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode. Locked by LOCK_CFG field.
 *  0b00..Not use counter, raise a55_hdsk done to GPC once get A55 ack
 *  0b01..Delay after receiving a55 ack, delay cycle number is CNT_CFG
 *  0b10..Ignore A55 ack, raise a55_hdsk done to GPC when counting to CNT_CFG value
 *  0b11..Time out mode, raise a55_hdsk done to GPC when either A55 ack received or counting to CNT_CFG value
 */
#define SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_A55_HDSK_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name A55_HDSK_ACK_STAT - A55 handshake acknowledge status */
/*! @{ */

#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PDN_ACK_CNT_MASK (0xFFU)
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PDN_ACK_CNT_SHIFT (0U)
/*! PDN_ACK_CNT - A55 handshake power down acknowledge count. */
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PDN_ACK_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PDN_ACK_CNT_SHIFT)) & SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PDN_ACK_CNT_MASK)

#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PUP_ACK_CNT_MASK (0xFF0000U)
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PUP_ACK_CNT_SHIFT (16U)
/*! PUP_ACK_CNT - A55 handshake power up acknowledge count */
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PUP_ACK_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PUP_ACK_CNT_SHIFT)) & SRC_MIX_SLICE_A55_HDSK_ACK_STAT_PUP_ACK_CNT_MASK)

#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PDN_HDSK_MASK (0x40000000U)
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PDN_HDSK_SHIFT (30U)
/*! BUSY_A55_PDN_HDSK - Busy requesting A55 power down handshake */
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PDN_HDSK(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PDN_HDSK_SHIFT)) & SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PDN_HDSK_MASK)

#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PUP_HDSK_MASK (0x80000000U)
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PUP_HDSK_SHIFT (31U)
/*! BUSY_A55_PUP_HDSK - Busy requesting A55 power up handshake */
#define SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PUP_HDSK(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PUP_HDSK_SHIFT)) & SRC_MIX_SLICE_A55_HDSK_ACK_STAT_BUSY_A55_PUP_HDSK_MASK)
/*! @} */

/*! @name SSAR_ACK_CTRL - SSAR acknowledge control */
/*! @{ */

#define SRC_MIX_SLICE_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK (0x3FFFU)
#define SRC_MIX_SLICE_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT (0U)
/*! SSAR_CNT_CFG - ssar count configure. Usage depends on CNT_MODE. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_SSAR_ACK_CTRL_SSAR_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK)

#define SRC_MIX_SLICE_SSAR_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_MIX_SLICE_SSAR_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode. Locked by LOCK_CFG field.
 *  0b00..Not use counter, raise ssar_save/restore done to GPC once get Edgelock Enclave ack
 *  0b01..Delay after receiving Edgelock Enclave ack, delay cycle number is CNT_CFG
 *  0b10..Ignore Edgelock Enclave ack, raise ssar_save/restore done to GPC when counting to CNT_CFG value
 *  0b11..Time out mode, raise ssar_save/restore done to GPC when either Edgelock Enclave ack received or counting to CNT_CFG value
 */
#define SRC_MIX_SLICE_SSAR_ACK_CTRL_CNT_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SSAR_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_SSAR_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name SSAR_ACK_STAT - SSAR acknowledge status */
/*! @{ */

#define SRC_MIX_SLICE_SSAR_ACK_STAT_SAVE_ACK_CNT_MASK (0x3FFFU)
#define SRC_MIX_SLICE_SSAR_ACK_STAT_SAVE_ACK_CNT_SHIFT (0U)
/*! SAVE_ACK_CNT - SAVE acknowledge count, record the delay from stat change to acknowledge received */
#define SRC_MIX_SLICE_SSAR_ACK_STAT_SAVE_ACK_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SSAR_ACK_STAT_SAVE_ACK_CNT_SHIFT)) & SRC_MIX_SLICE_SSAR_ACK_STAT_SAVE_ACK_CNT_MASK)

#define SRC_MIX_SLICE_SSAR_ACK_STAT_RESTORE_ACK_CNT_MASK (0xFFFC000U)
#define SRC_MIX_SLICE_SSAR_ACK_STAT_RESTORE_ACK_CNT_SHIFT (14U)
/*! RESTORE_ACK_CNT - RESTORE acknowledge count, record the delay from stat change to acknowledge received */
#define SRC_MIX_SLICE_SSAR_ACK_STAT_RESTORE_ACK_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SSAR_ACK_STAT_RESTORE_ACK_CNT_SHIFT)) & SRC_MIX_SLICE_SSAR_ACK_STAT_RESTORE_ACK_CNT_MASK)

#define SRC_MIX_SLICE_SSAR_ACK_STAT_SAVED_MASK   (0x20000000U)
#define SRC_MIX_SLICE_SSAR_ACK_STAT_SAVED_SHIFT  (29U)
/*! SAVED - Indicate this mix power down info have accepted Edgelock Enclave ack */
#define SRC_MIX_SLICE_SSAR_ACK_STAT_SAVED(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SSAR_ACK_STAT_SAVED_SHIFT)) & SRC_MIX_SLICE_SSAR_ACK_STAT_SAVED_MASK)

#define SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_SAVED_MASK (0x40000000U)
#define SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_SAVED_SHIFT (30U)
/*! BUSY_SAVED - Busy requesting SSAR save */
#define SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_SAVED(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_SAVED_SHIFT)) & SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_SAVED_MASK)

#define SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_RESTORE_MASK (0x80000000U)
#define SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_RESTORE_SHIFT (31U)
/*! BUSY_RESTORE - Busy requesting SSAR restore */
#define SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_RESTORE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_RESTORE_SHIFT)) & SRC_MIX_SLICE_SSAR_ACK_STAT_BUSY_RESTORE_MASK)
/*! @} */

/*! @name ISO_OFF_DLY_POR - iso off delay control when por */
/*! @{ */

#define SRC_MIX_SLICE_ISO_OFF_DLY_POR_DLY_PRE_ISO_OFF_POR_MASK (0xFFFFFFFFU)
#define SRC_MIX_SLICE_ISO_OFF_DLY_POR_DLY_PRE_ISO_OFF_POR_SHIFT (0U)
/*! DLY_PRE_ISO_OFF_POR - Delay from receiving iso off request to isolation disable. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_ISO_OFF_DLY_POR_DLY_PRE_ISO_OFF_POR(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_ISO_OFF_DLY_POR_DLY_PRE_ISO_OFF_POR_SHIFT)) & SRC_MIX_SLICE_ISO_OFF_DLY_POR_DLY_PRE_ISO_OFF_POR_MASK)
/*! @} */

/*! @name ISO_ON_DLY - iso on delay control */
/*! @{ */

#define SRC_MIX_SLICE_ISO_ON_DLY_DLY_PRE_ISO_ON_MASK (0xFFFFFFFFU)
#define SRC_MIX_SLICE_ISO_ON_DLY_DLY_PRE_ISO_ON_SHIFT (0U)
/*! DLY_PRE_ISO_ON - Delay from receiving iso_on request to isolation enable. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_ISO_ON_DLY_DLY_PRE_ISO_ON(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_ISO_ON_DLY_DLY_PRE_ISO_ON_SHIFT)) & SRC_MIX_SLICE_ISO_ON_DLY_DLY_PRE_ISO_ON_MASK)
/*! @} */

/*! @name ISO_OFF_DLY - iso off delay control */
/*! @{ */

#define SRC_MIX_SLICE_ISO_OFF_DLY_DLY_PRE_ISO_OFF_MASK (0xFFFFFFFFU)
#define SRC_MIX_SLICE_ISO_OFF_DLY_DLY_PRE_ISO_OFF_SHIFT (0U)
/*! DLY_PRE_ISO_OFF - Delay from receiving iso off request to isolation disable. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_ISO_OFF_DLY_DLY_PRE_ISO_OFF(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_ISO_OFF_DLY_DLY_PRE_ISO_OFF_SHIFT)) & SRC_MIX_SLICE_ISO_OFF_DLY_DLY_PRE_ISO_OFF_MASK)
/*! @} */

/*! @name PSW_OFF_LF_DLY - psw off lf delay control */
/*! @{ */

#define SRC_MIX_SLICE_PSW_OFF_LF_DLY_DLY_PRE_PSW_OFF_LF_MASK (0xFFFFFFFFU)
#define SRC_MIX_SLICE_PSW_OFF_LF_DLY_DLY_PRE_PSW_OFF_LF_SHIFT (0U)
/*! DLY_PRE_PSW_OFF_LF - Delay from receiving power off lf request to power switch shut off. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_OFF_LF_DLY_DLY_PRE_PSW_OFF_LF(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_OFF_LF_DLY_DLY_PRE_PSW_OFF_LF_SHIFT)) & SRC_MIX_SLICE_PSW_OFF_LF_DLY_DLY_PRE_PSW_OFF_LF_MASK)
/*! @} */

/*! @name PSW_OFF_HF_DLY - psw off hf delay control */
/*! @{ */

#define SRC_MIX_SLICE_PSW_OFF_HF_DLY_DLY_PRE_PSW_OFF_HF_MASK (0xFFFFFFFFU)
#define SRC_MIX_SLICE_PSW_OFF_HF_DLY_DLY_PRE_PSW_OFF_HF_SHIFT (0U)
/*! DLY_PRE_PSW_OFF_HF - Delay from receiving power off hf request to power switch shut off. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_OFF_HF_DLY_DLY_PRE_PSW_OFF_HF(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_OFF_HF_DLY_DLY_PRE_PSW_OFF_HF_SHIFT)) & SRC_MIX_SLICE_PSW_OFF_HF_DLY_DLY_PRE_PSW_OFF_HF_MASK)
/*! @} */

/*! @name PSW_ON_LF_DLY - psw on lf delay control */
/*! @{ */

#define SRC_MIX_SLICE_PSW_ON_LF_DLY_DLY_PRE_PSW_ON_LF_MASK (0xFFFFFFFFU)
#define SRC_MIX_SLICE_PSW_ON_LF_DLY_DLY_PRE_PSW_ON_LF_SHIFT (0U)
/*! DLY_PRE_PSW_ON_LF - Delay from receiving power on lf request to power switch turns on. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ON_LF_DLY_DLY_PRE_PSW_ON_LF(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ON_LF_DLY_DLY_PRE_PSW_ON_LF_SHIFT)) & SRC_MIX_SLICE_PSW_ON_LF_DLY_DLY_PRE_PSW_ON_LF_MASK)
/*! @} */

/*! @name PSW_ON_HF_DLY - psw on hf delay control */
/*! @{ */

#define SRC_MIX_SLICE_PSW_ON_HF_DLY_DLY_PRE_PSW_ON_HF_MASK (0xFFFFFFFFU)
#define SRC_MIX_SLICE_PSW_ON_HF_DLY_DLY_PRE_PSW_ON_HF_SHIFT (0U)
/*! DLY_PRE_PSW_ON_HF - Delay from receiving power on lf request to power switch turns on. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ON_HF_DLY_DLY_PRE_PSW_ON_HF(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ON_HF_DLY_DLY_PRE_PSW_ON_HF_SHIFT)) & SRC_MIX_SLICE_PSW_ON_HF_DLY_DLY_PRE_PSW_ON_HF_MASK)
/*! @} */

/*! @name PSW_ACK_CTRL_0 - Power switch acknowledge control */
/*! @{ */

#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_LF_CNT_CFG_MASK (0x3FFU)
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_LF_CNT_CFG_SHIFT (0U)
/*! PUP_LF_CNT_CFG - PUP LF Count configure. Usage depends on CNT_MODE. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_LF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_LF_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_LF_CNT_CFG_MASK)

#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_HF_CNT_CFG_MASK (0x3FF0000U)
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_HF_CNT_CFG_SHIFT (16U)
/*! PUP_HF_CNT_CFG - PUP HF Count configure. Usage depends on CNT_MODE. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_HF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_HF_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_CTRL_0_PUP_HF_CNT_CFG_MASK)

#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_CNT_MODE_MASK (0x30000000U)
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Configure the acknowledge counter working mode. Locked by LOCK_CFG field.
 *  0b00..Not use counter, raise power_on/off done to GPC once get psw ack
 *  0b01..Delay after receiving psw ack, delay cycle number is CNT_CFG
 *  0b10..Ignore psw ack, raise power_on/off done to GPC when counting to CNT_CFG value
 *  0b11..Time out mode, raise power_on/off done to GPC when either psw ack received or counting to CNT_CFG value
 */
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_CTRL_0_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_CTRL_0_CNT_MODE_MASK)

#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_LF_ACK_INVERT_MASK (0x40000000U)
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_LF_ACK_INVERT_SHIFT (30U)
/*! LF_ACK_INVERT - LF Acknowledge value is inverted from power switch control. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_LF_ACK_INVERT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_CTRL_0_LF_ACK_INVERT_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_CTRL_0_LF_ACK_INVERT_MASK)

#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_HF_ACK_INVERT_MASK (0x80000000U)
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_HF_ACK_INVERT_SHIFT (31U)
/*! HF_ACK_INVERT - HF Acknowledge value is inverted from power switch control. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ACK_CTRL_0_HF_ACK_INVERT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_CTRL_0_HF_ACK_INVERT_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_CTRL_0_HF_ACK_INVERT_MASK)
/*! @} */

/*! @name PSW_ACK_CTRL_1 - Power switch acknowledge control */
/*! @{ */

#define SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_LF_CNT_CFG_MASK (0x3FFU)
#define SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_LF_CNT_CFG_SHIFT (0U)
/*! PDN_LF_CNT_CFG - PDN LF Count configure. Usage depends on CNT_MODE. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_LF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_LF_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_LF_CNT_CFG_MASK)

#define SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_HF_CNT_CFG_MASK (0x3FF0000U)
#define SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_HF_CNT_CFG_SHIFT (16U)
/*! PDN_HF_CNT_CFG - PDN HF Count configure. Usage depends on CNT_MODE. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_HF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_HF_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_CTRL_1_PDN_HF_CNT_CFG_MASK)
/*! @} */

/*! @name PSW_ACK_STAT - PSW acknowledge status */
/*! @{ */

#define SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_CNT_MASK (0x3FFU)
#define SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_CNT_SHIFT (0U)
/*! LF_ACK_CNT - LF PSW acknowledge count */
#define SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_CNT_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_CNT_MASK)

#define SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_CNT_MASK (0x3FF0000U)
#define SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_CNT_SHIFT (16U)
/*! HF_ACK_CNT - HF PSW acknowledge count */
#define SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_CNT_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_CNT_MASK)

#define SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_STAT_MASK (0x40000000U)
#define SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_STAT_SHIFT (30U)
/*! LF_ACK_STAT - LF PSW acknowledge status */
#define SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_STAT_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_STAT_LF_ACK_STAT_MASK)

#define SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_STAT_MASK (0x80000000U)
#define SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_STAT_SHIFT (31U)
/*! HF_ACK_STAT - HF PSW acknowledge status */
#define SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_STAT_SHIFT)) & SRC_MIX_SLICE_PSW_ACK_STAT_HF_ACK_STAT_MASK)
/*! @} */

/*! @name MTR_ACK_CTRL - MTR acknowledge control */
/*! @{ */

#define SRC_MIX_SLICE_MTR_ACK_CTRL_MTR_CNT_CFG_MASK (0xFFU)
#define SRC_MIX_SLICE_MTR_ACK_CTRL_MTR_CNT_CFG_SHIFT (0U)
/*! MTR_CNT_CFG - MTR count configure. Usage depends on CNT_MODE. Locked by LOCK_CFG field. */
#define SRC_MIX_SLICE_MTR_ACK_CTRL_MTR_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MTR_ACK_CTRL_MTR_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_MTR_ACK_CTRL_MTR_CNT_CFG_MASK)

#define SRC_MIX_SLICE_MTR_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_MIX_SLICE_MTR_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode. Locked by LOCK_CFG field.
 *  0b00..Not use counter, raise mtr done to GPC once get MTR ack
 *  0b01..Delay after receiving MTR ack, delay cycle number is CNT_CFG
 *  0b10..Ignore MTR ack, raise mtr done to GPC when counting to CNT_CFG value
 *  0b11..Time out mode, raise mtr done to GPC when either MTR ack received or counting to CNT_CFG value
 */
#define SRC_MIX_SLICE_MTR_ACK_CTRL_CNT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MTR_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_MTR_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name MTR_ACK_STAT - MTR acknowledge status */
/*! @{ */

#define SRC_MIX_SLICE_MTR_ACK_STAT_MTR_ACK_CNT_MASK (0xFFU)
#define SRC_MIX_SLICE_MTR_ACK_STAT_MTR_ACK_CNT_SHIFT (0U)
/*! MTR_ACK_CNT - MTR acknowledge count, record the delay from stat change to acknowledge received */
#define SRC_MIX_SLICE_MTR_ACK_STAT_MTR_ACK_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MTR_ACK_STAT_MTR_ACK_CNT_SHIFT)) & SRC_MIX_SLICE_MTR_ACK_STAT_MTR_ACK_CNT_MASK)

#define SRC_MIX_SLICE_MTR_ACK_STAT_MTR_DONE_MASK (0x40000000U)
#define SRC_MIX_SLICE_MTR_ACK_STAT_MTR_DONE_SHIFT (30U)
/*! MTR_DONE - Indicate MTR load repair finished */
#define SRC_MIX_SLICE_MTR_ACK_STAT_MTR_DONE(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MTR_ACK_STAT_MTR_DONE_SHIFT)) & SRC_MIX_SLICE_MTR_ACK_STAT_MTR_DONE_MASK)

#define SRC_MIX_SLICE_MTR_ACK_STAT_BUSY_MTR_MASK (0x80000000U)
#define SRC_MIX_SLICE_MTR_ACK_STAT_BUSY_MTR_SHIFT (31U)
/*! BUSY_MTR - Busy requesting MTR */
#define SRC_MIX_SLICE_MTR_ACK_STAT_BUSY_MTR(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MTR_ACK_STAT_BUSY_MTR_SHIFT)) & SRC_MIX_SLICE_MTR_ACK_STAT_BUSY_MTR_MASK)
/*! @} */

/*! @name UPI_STAT_0 - UPI status 0 */
/*! @{ */

#define SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_MASK (0xFFFFU)
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_SHIFT (0U)
/*! UPI_ISO_REQUEST - CPU mode trans iso request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_MASK)

#define SRC_MIX_SLICE_UPI_STAT_0_UPI_POWER_REQUEST_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_POWER_REQUEST_SHIFT (16U)
/*! UPI_POWER_REQUEST - CPU mode trans power request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_POWER_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_0_UPI_POWER_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_0_UPI_POWER_REQUEST_MASK)
/*! @} */

/*! @name UPI_STAT_1 - UPI status 1 */
/*! @{ */

#define SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_MASK (0xFFFFU)
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_SHIFT (0U)
/*! UPI_RESET_REQUEST - CPU mode trans reset request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_MASK)

#define SRC_MIX_SLICE_UPI_STAT_1_UPI_SSAR_REQUEST_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_SSAR_REQUEST_SHIFT (16U)
/*! UPI_SSAR_REQUEST - CPU mode trans ssar request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_SSAR_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_1_UPI_SSAR_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_1_UPI_SSAR_REQUEST_MASK)
/*! @} */

/*! @name UPI_STAT_2 - UPI status 2 */
/*! @{ */

#define SRC_MIX_SLICE_UPI_STAT_2_UPI_MTR_REQUEST_MASK (0xFFFFU)
#define SRC_MIX_SLICE_UPI_STAT_2_UPI_MTR_REQUEST_SHIFT (0U)
/*! UPI_MTR_REQUEST - CPU mode trans mtr request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_2_UPI_MTR_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_2_UPI_MTR_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_2_UPI_MTR_REQUEST_MASK)

#define SRC_MIX_SLICE_UPI_STAT_2_UPI_A55_HDSK_REQUEST_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_UPI_STAT_2_UPI_A55_HDSK_REQUEST_SHIFT (16U)
/*! UPI_A55_HDSK_REQUEST - CPU mode trans A55 handshake request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_2_UPI_A55_HDSK_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_2_UPI_A55_HDSK_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_2_UPI_A55_HDSK_REQUEST_MASK)
/*! @} */

/*! @name UPI_STAT_3 - UPI status 3 */
/*! @{ */

#define SRC_MIX_SLICE_UPI_STAT_3_UPI_MEM_REQUEST_MASK (0xFFFFU)
#define SRC_MIX_SLICE_UPI_STAT_3_UPI_MEM_REQUEST_SHIFT (0U)
/*! UPI_MEM_REQUEST - CPU mode trans mem request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_3_UPI_MEM_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_3_UPI_MEM_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_3_UPI_MEM_REQUEST_MASK)
/*! @} */

/*! @name FSM_STAT - FSM status */
/*! @{ */

#define SRC_MIX_SLICE_FSM_STAT_PSW_STAT_MASK     (0xFU)
#define SRC_MIX_SLICE_FSM_STAT_PSW_STAT_SHIFT    (0U)
/*! PSW_STAT - Power switch FSM status */
#define SRC_MIX_SLICE_FSM_STAT_PSW_STAT(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FSM_STAT_PSW_STAT_SHIFT)) & SRC_MIX_SLICE_FSM_STAT_PSW_STAT_MASK)

#define SRC_MIX_SLICE_FSM_STAT_RST_STAT_MASK     (0xF0U)
#define SRC_MIX_SLICE_FSM_STAT_RST_STAT_SHIFT    (4U)
/*! RST_STAT - Reset FSM status */
#define SRC_MIX_SLICE_FSM_STAT_RST_STAT(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FSM_STAT_RST_STAT_SHIFT)) & SRC_MIX_SLICE_FSM_STAT_RST_STAT_MASK)

#define SRC_MIX_SLICE_FSM_STAT_ISO_STAT_MASK     (0xF00U)
#define SRC_MIX_SLICE_FSM_STAT_ISO_STAT_SHIFT    (8U)
/*! ISO_STAT - Isolation FSM status */
#define SRC_MIX_SLICE_FSM_STAT_ISO_STAT(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FSM_STAT_ISO_STAT_SHIFT)) & SRC_MIX_SLICE_FSM_STAT_ISO_STAT_MASK)

#define SRC_MIX_SLICE_FSM_STAT_MTR_STAT_MASK     (0x7000U)
#define SRC_MIX_SLICE_FSM_STAT_MTR_STAT_SHIFT    (12U)
/*! MTR_STAT - MTR FSM status */
#define SRC_MIX_SLICE_FSM_STAT_MTR_STAT(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FSM_STAT_MTR_STAT_SHIFT)) & SRC_MIX_SLICE_FSM_STAT_MTR_STAT_MASK)

#define SRC_MIX_SLICE_FSM_STAT_SSAR_STAT_MASK    (0x70000U)
#define SRC_MIX_SLICE_FSM_STAT_SSAR_STAT_SHIFT   (16U)
/*! SSAR_STAT - SSAR FSM status */
#define SRC_MIX_SLICE_FSM_STAT_SSAR_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FSM_STAT_SSAR_STAT_SHIFT)) & SRC_MIX_SLICE_FSM_STAT_SSAR_STAT_MASK)

#define SRC_MIX_SLICE_FSM_STAT_A55_HDSK_STAT_MASK (0xF00000U)
#define SRC_MIX_SLICE_FSM_STAT_A55_HDSK_STAT_SHIFT (20U)
/*! A55_HDSK_STAT - A55 handshake FSM status */
#define SRC_MIX_SLICE_FSM_STAT_A55_HDSK_STAT(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FSM_STAT_A55_HDSK_STAT_SHIFT)) & SRC_MIX_SLICE_FSM_STAT_A55_HDSK_STAT_MASK)

#define SRC_MIX_SLICE_FSM_STAT_MEM_STAT_MASK     (0x7000000U)
#define SRC_MIX_SLICE_FSM_STAT_MEM_STAT_SHIFT    (24U)
/*! MEM_STAT - Memory FSM status */
#define SRC_MIX_SLICE_FSM_STAT_MEM_STAT(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FSM_STAT_MEM_STAT_SHIFT)) & SRC_MIX_SLICE_FSM_STAT_MEM_STAT_MASK)
/*! @} */

/*! @name FUNC_STAT - function status */
/*! @{ */

#define SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_MASK    (0x1U)
#define SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_SHIFT   (0U)
/*! PSW_STAT - Power switch status
 *  0b0..Power switch on
 *  0b1..Power switch off
 */
#define SRC_MIX_SLICE_FUNC_STAT_PSW_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_RST_STAT_MASK    (0x4U)
#define SRC_MIX_SLICE_FUNC_STAT_RST_STAT_SHIFT   (2U)
/*! RST_STAT - Reset status
 *  0b0..Reset assert
 *  0b1..Reset release
 */
#define SRC_MIX_SLICE_FUNC_STAT_RST_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_RST_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_RST_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_MASK    (0x10U)
#define SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_SHIFT   (4U)
/*! ISO_STAT - Isolation status
 *  0b0..Isolation off
 *  0b1..Isolation on
 */
#define SRC_MIX_SLICE_FUNC_STAT_ISO_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_MTR_STAT_MASK    (0x40U)
#define SRC_MIX_SLICE_FUNC_STAT_MTR_STAT_SHIFT   (6U)
/*! MTR_STAT - MTR status
 *  0b0..No effect
 *  0b1..Memory repair/trim done
 */
#define SRC_MIX_SLICE_FUNC_STAT_MTR_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_MTR_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_MTR_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_SSAR_STAT_MASK   (0x100U)
#define SRC_MIX_SLICE_FUNC_STAT_SSAR_STAT_SHIFT  (8U)
/*! SSAR_STAT - ssar status
 *  0b0..No effect or power up handshake with Edgelock Enclave done
 *  0b1..Power down handshake with Edgelock Enclave done
 */
#define SRC_MIX_SLICE_FUNC_STAT_SSAR_STAT(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_SSAR_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_SSAR_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_A55_HDSK_STAT_MASK (0x400U)
#define SRC_MIX_SLICE_FUNC_STAT_A55_HDSK_STAT_SHIFT (10U)
/*! A55_HDSK_STAT - A55 handshake status
 *  0b0..No effect or power up handshake with A55 done(just for A55 SLICE)
 *  0b1..Power down handshake with A55 done(just for A55 SLICE)
 */
#define SRC_MIX_SLICE_FUNC_STAT_A55_HDSK_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_A55_HDSK_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_A55_HDSK_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_MEM_STAT_MASK    (0x1000U)
#define SRC_MIX_SLICE_FUNC_STAT_MEM_STAT_SHIFT   (12U)
/*! MEM_STAT - Memory w/ status
 *  0b0..No effect or memory w/ exit LP done
 *  0b1..Memory w/ enter LP done
 */
#define SRC_MIX_SLICE_FUNC_STAT_MEM_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_MEM_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_MEM_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_MIX_SLICE_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_MIX_SLICE_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_MIX_SLICE_H_ */
