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
**         CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
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
 * @file PERI_BLK_CTRL_NS_AONMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
 */

#if !defined(PERI_BLK_CTRL_NS_AONMIX_H_)
#define PERI_BLK_CTRL_NS_AONMIX_H_               /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_NS_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer BLK_CTRL_NS_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_NS_AONMIX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12];
  __IO uint32_t IPG_DEBUG_CA55C0;                  /**< IPG DEBUG MASK BIT CA55 CORE0, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t QCH_DIS;                           /**< QCHANNEL DISABLE, offset: 0x14 */
       uint8_t RESERVED_2[8];
  __IO uint32_t MQS_SETTINGS;                      /**< MQS settings., offset: 0x20 */
       uint8_t RESERVED_3[4];
  __I  uint32_t FUSE_ACC_DIS;                      /**< Read-only version of the OCOTP fuse-access-disable bit, offset: 0x28 */
       uint8_t RESERVED_4[4];
  __I  uint32_t OCOTP_FUSE_DATA0;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_0, offset: 0x30 */
  __I  uint32_t OCOTP_FUSE_DATA1;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_1, offset: 0x34 */
  __I  uint32_t OCOTP_FUSE_DATA2;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_2, offset: 0x38 */
  __I  uint32_t OCOTP_FUSE_DATA3;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_3, offset: 0x3C */
  __I  uint32_t OCOTP_FUSE_DATA4;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_4, offset: 0x40 */
  __I  uint32_t OCOTP_FUSE_DATA5;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_5, offset: 0x44 */
  __I  uint32_t OCOTP_FUSE_DATA6;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_6, offset: 0x48 */
  __I  uint32_t OCOTP_FUSE_DATA7;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_7, offset: 0x4C */
  __I  uint32_t OCOTP_FUSE_DATA8;                  /**< Read-only version of OCOTP fusedata_mem_trim_cfg0, offset: 0x50 */
  __I  uint32_t OCOTP_FUSE_DATA9;                  /**< Read-only version of OCOTP fusedata_mem_trim_cfg1, offset: 0x54 */
  __I  uint32_t OCOTP_FUSE_DATA10;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg2, offset: 0x58 */
  __I  uint32_t OCOTP_FUSE_DATA11;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg3, offset: 0x5C */
  __I  uint32_t OCOTP_FUSE_DATA12;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg4, offset: 0x60 */
  __I  uint32_t OCOTP_FUSE_DATA13;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg5, offset: 0x64 */
  __I  uint32_t OCOTP_FUSE_DATA14;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg6, offset: 0x68 */
  __I  uint32_t OCOTP_FUSE_DATA15;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg7, offset: 0x6C */
  __IO uint32_t I3C1_WAKEUP;                       /**< I3C1 WAKEUPX CLR, offset: 0x70 */
  __I  uint32_t OCOTP_STATUS;                      /**< OCOTP status, offset: 0x74 */
  __IO uint32_t PDM_CLK_SEL;                       /**< PDM clock selection register, offset: 0x78 */
  __IO uint32_t I3C1_SDA_IRQ;                      /**< I3C1 SDA IRQ CONTROL, offset: 0x7C */
  __I  uint32_t FASTBOOT_ENABLE;                   /**< Fastboot enable, offset: 0x80 */
  __I  uint32_t EDGELOCK_FW_PRESENT;               /**< Read only Edgelock fuse, offset: 0x84 */
} BLK_CTRL_NS_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NS_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Register_Masks BLK_CTRL_NS_AONMIX Register Masks
 * @{
 */

/*! @name IPG_DEBUG_CA55C0 - IPG DEBUG MASK BIT CA55 CORE0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_SHIFT (0U)
/*! CAN1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_SHIFT (1U)
/*! EDMA1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_SHIFT (2U)
/*! LPI2C1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_SHIFT (3U)
/*! LPI2C2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_SHIFT (4U)
/*! LPIT1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_SHIFT (5U)
/*! LPSPI1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_SHIFT (6U)
/*! LPSPI2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_SHIFT (7U)
/*! LPTMR1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_SHIFT (8U)
/*! SAI1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_SHIFT (9U)
/*! TPM1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_SHIFT (10U)
/*! TPM2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_SHIFT (11U)
/*! WDOG1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_SHIFT (12U)
/*! WDOG2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_SHIFT (13U)
/*! I3C1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_SHIFT (14U)
/*! PDM - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_MASK)
/*! @} */

/*! @name QCH_DIS - QCHANNEL DISABLE */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_QCH_DIS_GPIO1_MASK    (0x1U)
#define BLK_CTRL_NS_AONMIX_QCH_DIS_GPIO1_SHIFT   (0U)
/*! GPIO1 - Module QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_NS_AONMIX_QCH_DIS_GPIO1(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QCH_DIS_GPIO1_SHIFT)) & BLK_CTRL_NS_AONMIX_QCH_DIS_GPIO1_MASK)

#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART1_MASK  (0x2U)
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART1_SHIFT (1U)
/*! LPUART1 - Module QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART1(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART2_MASK  (0x4U)
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART2_SHIFT (2U)
/*! LPUART2 - Module QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART2(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QCH_DIS_LPUART2_MASK)

#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI1_MASK   (0x8U)
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI1_SHIFT  (3U)
/*! LPSPI1 - Module QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI1(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI2_MASK   (0x10U)
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI2_SHIFT  (4U)
/*! LPSPI2 - Module QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI2(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QCH_DIS_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QCH_DIS_SAI1_MASK     (0x20U)
#define BLK_CTRL_NS_AONMIX_QCH_DIS_SAI1_SHIFT    (5U)
/*! SAI1 - Module QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_NS_AONMIX_QCH_DIS_SAI1(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QCH_DIS_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QCH_DIS_SAI1_MASK)
/*! @} */

/*! @name MQS_SETTINGS - MQS settings. */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_SHIFT (1U)
/*! MQS_EN - MQS Enable */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_SHIFT (2U)
/*! SOFT_RESET - Software Reset */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_SHIFT (3U)
/*! OVERSAMPLE - Oversample enable */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_MASK (0xFF00U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_SHIFT (8U)
/*! CLK_DIVIDE - Clock divide factor configuration */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_MASK)
/*! @} */

/*! @name FUSE_ACC_DIS - Read-only version of the OCOTP fuse-access-disable bit */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT (0U)
/*! OSCCA_FUSE_READ_DIS - OSCCA fuse read disable
 *  0b0..The chip is allowed to access the OCOTP registers
 *  0b1..The chip is not allowed to access the OCOTP registers
 */
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT)) & BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA0 - Read-only version of OCOTP fusedata_mtr_cfg_0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_SHIFT (0U)
/*! OCOTP_FUSE_DATA0 - OCOTP_FUSE_DATA0 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA1 - Read-only version of OCOTP fusedata_mtr_cfg_1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_SHIFT (0U)
/*! OCOTP_FUSE_DATA1 - OCOTP_FUSE_DATA1 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA2 - Read-only version of OCOTP fusedata_mtr_cfg_2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_SHIFT (0U)
/*! OCOTP_FUSE_DATA2 - OCOTP_FUSE_DATA2 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA3 - Read-only version of OCOTP fusedata_mtr_cfg_3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_SHIFT (0U)
/*! OCOTP_FUSE_DATA3 - OCOTP_FUSE_DATA3 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA4 - Read-only version of OCOTP fusedata_mtr_cfg_4 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_SHIFT (0U)
/*! OCOTP_FUSE_DATA4 - OCOTP_FUSE_DATA4 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA5 - Read-only version of OCOTP fusedata_mtr_cfg_5 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_SHIFT (0U)
/*! OCOTP_FUSE_DATA5 - OCOTP_FUSE_DATA5 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA6 - Read-only version of OCOTP fusedata_mtr_cfg_6 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_SHIFT (0U)
/*! OCOTP_FUSE_DATA6 - OCOTP_FUSE_DATA6 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA7 - Read-only version of OCOTP fusedata_mtr_cfg_7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_SHIFT (0U)
/*! OCOTP_FUSE_DATA7 - OCOTP_FUSE_DATA7 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA8 - Read-only version of OCOTP fusedata_mem_trim_cfg0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_SHIFT (0U)
/*! OCOTP_FUSE_DATA8 - OCOTP_FUSE_DATA8 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA9 - Read-only version of OCOTP fusedata_mem_trim_cfg1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_SHIFT (0U)
/*! OCOTP_FUSE_DATA9 - OCOTP_FUSE_DATA9 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA10 - Read-only version of OCOTP fusedata_mem_trim_cfg2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_SHIFT (0U)
/*! OCOTP_FUSE_DATA10 - OCOTP_FUSE_DATA10 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA11 - Read-only version of OCOTP fusedata_mem_trim_cfg3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_SHIFT (0U)
/*! OCOTP_FUSE_DATA11 - OCOTP_FUSE_DATA12 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA12 - Read-only version of OCOTP fusedata_mem_trim_cfg4 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_SHIFT (0U)
/*! OCOTP_FUSE_DATA12 - OCOTP_FUSE_DATA13 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA13 - Read-only version of OCOTP fusedata_mem_trim_cfg5 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_SHIFT (0U)
/*! OCOTP_FUSE_DATA13 - OCOTP_FUSE_DATA13 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA14 - Read-only version of OCOTP fusedata_mem_trim_cfg6 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_SHIFT (0U)
/*! OCOTP_FUSE_DATA14 - OCOTP_FUSE_DATA14 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA15 - Read-only version of OCOTP fusedata_mem_trim_cfg7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_SHIFT (0U)
/*! OCOTP_FUSE_DATA15 - OCOTP_FUSE_DATA15 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_MASK)
/*! @} */

/*! @name I3C1_WAKEUP - I3C1 WAKEUPX CLR */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_SHIFT (0U)
/*! IRQ_CLR - I3C1 Interrupt request clear */
#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_MASK)
/*! @} */

/*! @name OCOTP_STATUS - OCOTP status */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_SHIFT (0U)
/*! BUSY - OCOTP controller busy bit
 *  0b0..Idle
 *  0b1..OCOTP is Busy
 */
#define BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_MASK)
/*! @} */

/*! @name PDM_CLK_SEL - PDM clock selection register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_MASK  (0x1U)
#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_SHIFT (0U)
/*! SEL - Select source for PDM clock
 *  0b0..PDM root clock
 *  0b1..SAI1_MCLK
 */
#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_MASK)
/*! @} */

/*! @name I3C1_SDA_IRQ - I3C1 SDA IRQ CONTROL */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_SHIFT (0U)
/*! ENABLE - IRQ enable bit
 *  0b0..I3C1 SDA IRQ disable
 *  0b1..I3C1 SDA IRQ enable
 */
#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_MASK)
/*! @} */

/*! @name FASTBOOT_ENABLE - Fastboot enable */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_MASK (0x3U)
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_SHIFT (0U)
/*! FASTBOOT_ENABLE - FASTBOOT_ENABLE bits */
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_MASK)

#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_MASK (0xCU)
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_SHIFT (2U)
/*! BP_FASTBOOT_ENABLE - BP_FASTBOOT_ENABLE */
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_MASK)
/*! @} */

/*! @name EDGELOCK_FW_PRESENT - Read only Edgelock fuse */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_EDGELOCK_FW_PRESENT_EDGELOCK_FW_PRESENT_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_EDGELOCK_FW_PRESENT_EDGELOCK_FW_PRESENT_SHIFT (0U)
/*! EDGELOCK_FW_PRESENT - Read only bit for Edgelock fuse */
#define BLK_CTRL_NS_AONMIX_EDGELOCK_FW_PRESENT_EDGELOCK_FW_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_EDGELOCK_FW_PRESENT_EDGELOCK_FW_PRESENT_SHIFT)) & BLK_CTRL_NS_AONMIX_EDGELOCK_FW_PRESENT_EDGELOCK_FW_PRESENT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_NS_AONMIX_H_ */
