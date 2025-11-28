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
**         CMSIS Peripheral Access Layer for OCRAM_MECC
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
 * @file PERI_OCRAM_MECC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCRAM_MECC
 *
 * CMSIS Peripheral Access Layer for OCRAM_MECC
 */

#if !defined(PERI_OCRAM_MECC_H_)
#define PERI_OCRAM_MECC_H_                       /**< Symbol preventing repeated inclusion */

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
   -- OCRAM_MECC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCRAM_MECC_Peripheral_Access_Layer OCRAM_MECC Peripheral Access Layer
 * @{
 */

/** OCRAM_MECC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SINGLE_ERR_STATUS;                 /**< Error Interrupt Status Register, offset: 0x0 */
  __IO uint32_t MULTI_ERR_STATUS;                  /**< MULTI Error Interrupt Status Register, offset: 0x4 */
  __IO uint32_t STRB_ERR_STATUS;                   /**< STRB Error Interrupt Status Register, offset: 0x8 */
  __IO uint32_t ADDR_ERR_STATUS;                   /**< ADDR Error Interrupt Status Register, offset: 0xC */
  __IO uint32_t SINGLE_ERR_STAT_EN;                /**< Single Error Interrupt Status Enable Register, offset: 0x10 */
  __IO uint32_t MULTI_ERR_STAT_EN;                 /**< MULTI Error Interrupt Status Enable Register, offset: 0x14 */
  __IO uint32_t STRB_ERR_STAT_EN;                  /**< STRB Error Interrupt Status Enable Register, offset: 0x18 */
  __IO uint32_t ADDR_ERR_STAT_EN;                  /**< ADDR Error Interrupt Status Enable Register, offset: 0x1C */
  __IO uint32_t SINGLE_ERR_SIG_EN;                 /**< Single Error Interrupt Enable Register, offset: 0x20 */
  __IO uint32_t MULTI_ERR_SIG_EN;                  /**< MULTI Error Interrupt Enable Register, offset: 0x24 */
  __IO uint32_t STRB_ERR_SIG_EN;                   /**< STRB Error Interrupt Enable Register, offset: 0x28 */
  __IO uint32_t ADDR_ERR_SIG_EN;                   /**< ADDR Error Interrupt Enable Register, offset: 0x2C */
  __IO uint32_t ERR_DATA_INJ_LOW0;                 /**< Error Injection On Low 32 bits Of Ocram Bank0 Write Data, offset: 0x30 */
  __IO uint32_t ERR_DATA_INJ_HIGH0;                /**< Error Injection On High 32 bits Of Ocram Bank0 Write Data, offset: 0x34 */
  __IO uint32_t ERR_ECC_INJ0;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank0 Write Data, offset: 0x38 */
  __IO uint32_t ERR_DATA_INJ_LOW1;                 /**< Error Injection On Low 32 bits Of Ocram Bank1 Write Data, offset: 0x3C */
  __IO uint32_t ERR_DATA_INJ_HIGH1;                /**< Error Injection On High 32 bits Of Ocram Bank1 Write Data, offset: 0x40 */
  __IO uint32_t ERR_ECC_INJ1;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank1 Write Data, offset: 0x44 */
  __IO uint32_t ERR_DATA_INJ_LOW2;                 /**< Error Injection On Low 32 bits Of Ocram Bank2 Write Data, offset: 0x48 */
  __IO uint32_t ERR_DATA_INJ_HIGH2;                /**< Error Injection On High 32 bits Of Ocram Bank2 Write Data, offset: 0x4C */
  __IO uint32_t ERR_ECC_INJ2;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank2 Write Data, offset: 0x50 */
  __IO uint32_t ERR_DATA_INJ_LOW3;                 /**< Error Injection On Low 32 bits Of Ocram Bank3 Write Data, offset: 0x54 */
  __IO uint32_t ERR_DATA_INJ_HIGH3;                /**< Error Injection On High 32 bits Of Ocram Bank3 Write Data, offset: 0x58 */
  __IO uint32_t ERR_ECC_INJ3;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank3 Write Data, offset: 0x5C */
  __IO uint32_t ERR_DATA_INJ_LOW4;                 /**< Error Injection On Low 32 bits Of Ocram Bank4 Write Data, offset: 0x60 */
  __IO uint32_t ERR_DATA_INJ_HIGH4;                /**< Error Injection On High 32 bits Of Ocram Bank4 Write Data, offset: 0x64 */
  __IO uint32_t ERR_ECC_INJ4;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank4 Write Data, offset: 0x68 */
  __IO uint32_t ERR_DATA_INJ_LOW5;                 /**< Error Injection On Low 32 bits Of Ocram Bank5 Write Data, offset: 0x6C */
  __IO uint32_t ERR_DATA_INJ_HIGH5;                /**< Error Injection On High 32 bits Of Ocram Bank5 Write Data, offset: 0x70 */
  __IO uint32_t ERR_ECC_INJ5;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank5 Write Data, offset: 0x74 */
  __IO uint32_t ERR_DATA_INJ_LOW6;                 /**< Error Injection On Low 32 bits Of Ocram Bank6 Write Data, offset: 0x78 */
  __IO uint32_t ERR_DATA_INJ_HIGH6;                /**< Error Injection On High 32 bits Of Ocram Bank6 Write Data, offset: 0x7C */
  __IO uint32_t ERR_ECC_INJ6;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank6 Write Data, offset: 0x80 */
  __IO uint32_t ERR_DATA_INJ_LOW7;                 /**< Error Injection On Low 32 bits Of Ocram Bank7 Write Data, offset: 0x84 */
  __IO uint32_t ERR_DATA_INJ_HIGH7;                /**< Error Injection On High 32 bits Of Ocram Bank7 Write Data, offset: 0x88 */
  __IO uint32_t ERR_ECC_INJ7;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank7 Write Data, offset: 0x8C */
  __IO uint32_t ERR_DATA_INJ_LOW8;                 /**< Error Injection On Low 32 bits Of Ocram Bank8 Write Data, offset: 0x90 */
  __IO uint32_t ERR_DATA_INJ_HIGH8;                /**< Error Injection On High 32 bits Of Ocram Bank8 Write Data, offset: 0x94 */
  __IO uint32_t ERR_ECC_INJ8;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank8 Write Data, offset: 0x98 */
  __IO uint32_t ERR_DATA_INJ_LOW9;                 /**< Error Injection On Low 32 bits Of Ocram Bank9 Write Data, offset: 0x9C */
  __IO uint32_t ERR_DATA_INJ_HIGH9;                /**< Error Injection On High 32 bits Of Ocram Bank9 Write Data, offset: 0xA0 */
  __IO uint32_t ERR_ECC_INJ9;                      /**< Error Injection On 8 bits ECC code Of Ocram Bank9 Write Data, offset: 0xA4 */
  __IO uint32_t ERR_DATA_INJ_LOW10;                /**< Error Injection On Low 32 bits Of Ocram Bank10 Write Data, offset: 0xA8 */
  __IO uint32_t ERR_DATA_INJ_HIGH10;               /**< Error Injection On High 32 bits Of Ocram Bank10 Write Data, offset: 0xAC */
  __IO uint32_t ERR_ECC_INJ10;                     /**< Error Injection On 8 bits ECC code Of Ocram Bank10 Write Data, offset: 0xB0 */
  __IO uint32_t ERR_DATA_INJ_LOW11;                /**< Error Injection On Low 32 bits Of Ocram Bank11 Write Data, offset: 0xB4 */
  __IO uint32_t ERR_DATA_INJ_HIGH11;               /**< Error Injection On High 32 bits Of Ocram Bank11 Write Data, offset: 0xB8 */
  __IO uint32_t ERR_ECC_INJ11;                     /**< Error Injection On 8 bits ECC code Of Ocram Bank11 Write Data, offset: 0xBC */
  __IO uint32_t ERR_DATA_INJ_LOW12;                /**< Error Injection On Low 32 bits Of Ocram Bank12 Write Data, offset: 0xC0 */
  __IO uint32_t ERR_DATA_INJ_HIGH12;               /**< Error Injection On High 32 bits Of Ocram Bank12 Write Data, offset: 0xC4 */
  __IO uint32_t ERR_ECC_INJ12;                     /**< Error Injection On 8 bits ECC code Of Ocram Bank12 Write Data, offset: 0xC8 */
  __IO uint32_t ERR_DATA_INJ_LOW13;                /**< Error Injection On Low 32 bits Of Ocram Bank13 Write Data, offset: 0xCC */
  __IO uint32_t ERR_DATA_INJ_HIGH13;               /**< Error Injection On High 32 bits Of Ocram Bank13 Write Data, offset: 0xD0 */
  __IO uint32_t ERR_ECC_INJ13;                     /**< Error Injection On 8 bits ECC code Of Ocram Bank13 Write Data, offset: 0xD4 */
  __IO uint32_t ERR_DATA_INJ_LOW14;                /**< Error Injection On Low 32 bits Of Ocram Bank14 Write Data, offset: 0xD8 */
  __IO uint32_t ERR_DATA_INJ_HIGH14;               /**< Error Injection On High 32 bits Of Ocram Bank14 Write Data, offset: 0xDC */
  __IO uint32_t ERR_ECC_INJ14;                     /**< Error Injection On 8 bits ECC code Of Ocram Bank14 Write Data, offset: 0xE0 */
  __IO uint32_t ERR_DATA_INJ_LOW15;                /**< Error Injection On Low 32 bits Of Ocram Bank15 Write Data, offset: 0xE4 */
  __IO uint32_t ERR_DATA_INJ_HIGH15;               /**< Error Injection On High 32 bits Of Ocram Bank15 Write Data, offset: 0xE8 */
  __IO uint32_t ERR_ECC_INJ15;                     /**< Error Injection On 8 bits ECC code Of Ocram Bank15 Write Data, offset: 0xEC */
  __I  uint32_t SINGLE_ERR_ADDR_ECC0;              /**< Single Error Address And ECC Code On Ocram Bank0, offset: 0xF0 */
  __I  uint32_t SINGLE_ERR_DATA_LOW0;              /**< Low 32 Bits Single Error Read Data On Ocram Bank0, offset: 0xF4 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH0;             /**< High 32 Bits Single Error Read Data On Ocram Bank0, offset: 0xF8 */
  __I  uint32_t SINGLE_ERR_POS_LOW0;               /**< Low Single Error Bit Position On Ocram Bank0, offset: 0xFC */
  __I  uint32_t SINGLE_ERR_POS_HIGH0;              /**< High Single Error Bit Position On Ocram Bank0, offset: 0x100 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC1;              /**< Single Error Address And ECC Code On Ocram Bank1, offset: 0x104 */
  __I  uint32_t SINGLE_ERR_DATA_LOW1;              /**< Low 32 Bits Single Error Read Data On Ocram Bank1, offset: 0x108 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH1;             /**< High 32 Bits Single Error Read Data On Ocram Bank1, offset: 0x10C */
  __I  uint32_t SINGLE_ERR_POS_LOW1;               /**< Low Single Error Bit Position On Ocram Bank1, offset: 0x110 */
  __I  uint32_t SINGLE_ERR_POS_HIGH1;              /**< High Single Error Bit Position On Ocram Bank1, offset: 0x114 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC2;              /**< Single Error Address And ECC Code On Ocram Bank2, offset: 0x118 */
  __I  uint32_t SINGLE_ERR_DATA_LOW2;              /**< Low 32 Bits Single Error Read Data On Ocram Bank2, offset: 0x11C */
  __I  uint32_t SINGLE_ERR_DATA_HIGH2;             /**< High 32 Bits Single Error Read Data On Ocram Bank2, offset: 0x120 */
  __I  uint32_t SINGLE_ERR_POS_LOW2;               /**< Low Single Error Bit Position On Ocram Bank2, offset: 0x124 */
  __I  uint32_t SINGLE_ERR_POS_HIGH2;              /**< High Single Error Bit Position On Ocram Bank2, offset: 0x128 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC3;              /**< Single Error Address And ECC Code On Ocram Bank3, offset: 0x12C */
  __I  uint32_t SINGLE_ERR_DATA_LOW3;              /**< Low 32 Bits Single Error Read Data On Ocram Bank3, offset: 0x130 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH3;             /**< High 32 Bits Single Error Read Data On Ocram Bank3, offset: 0x134 */
  __I  uint32_t SINGLE_ERR_POS_LOW3;               /**< Low Single Error Bit Position On Ocram Bank3, offset: 0x138 */
  __I  uint32_t SINGLE_ERR_POS_HIGH3;              /**< High Single Error Bit Position On Ocram Bank3, offset: 0x13C */
  __I  uint32_t SINGLE_ERR_ADDR_ECC4;              /**< Single Error Address And ECC Code On Ocram Bank4, offset: 0x140 */
  __I  uint32_t SINGLE_ERR_DATA_LOW4;              /**< Low 32 Bits Single Error Read Data On Ocram Bank4, offset: 0x144 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH4;             /**< High 32 Bits Single Error Read Data On Ocram Bank4, offset: 0x148 */
  __I  uint32_t SINGLE_ERR_POS_LOW4;               /**< Low Single Error Bit Position On Ocram Bank4, offset: 0x14C */
  __I  uint32_t SINGLE_ERR_POS_HIGH4;              /**< High Single Error Bit Position On Ocram Bank4, offset: 0x150 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC5;              /**< Single Error Address And ECC Code On Ocram Bank5, offset: 0x154 */
  __I  uint32_t SINGLE_ERR_DATA_LOW5;              /**< Low 32 Bits Single Error Read Data On Ocram Bank5, offset: 0x158 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH5;             /**< High 32 Bits Single Error Read Data On Ocram Bank5, offset: 0x15C */
  __I  uint32_t SINGLE_ERR_POS_LOW5;               /**< Low Single Error Bit Position On Ocram Bank5, offset: 0x160 */
  __I  uint32_t SINGLE_ERR_POS_HIGH5;              /**< High Single Error Bit Position On Ocram Bank5, offset: 0x164 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC6;              /**< Single Error Address And ECC Code On Ocram Bank6, offset: 0x168 */
  __I  uint32_t SINGLE_ERR_DATA_LOW6;              /**< Low 32 Bits Single Error Read Data On Ocram Bank6, offset: 0x16C */
  __I  uint32_t SINGLE_ERR_DATA_HIGH6;             /**< High 32 Bits Single Error Read Data On Ocram Bank6, offset: 0x170 */
  __I  uint32_t SINGLE_ERR_POS_LOW6;               /**< Low Single Error Bit Position On Ocram Bank6, offset: 0x174 */
  __I  uint32_t SINGLE_ERR_POS_HIGH6;              /**< High Single Error Bit Position On Ocram Bank6, offset: 0x178 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC7;              /**< Single Error Address And ECC Code On Ocram Bank7, offset: 0x17C */
  __I  uint32_t SINGLE_ERR_DATA_LOW7;              /**< Low 32 Bits Single Error Read Data On Ocram Bank7, offset: 0x180 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH7;             /**< High 32 Bits Single Error Read Data On Ocram Bank7, offset: 0x184 */
  __I  uint32_t SINGLE_ERR_POS_LOW7;               /**< Low Single Error Bit Position On Ocram Bank7, offset: 0x188 */
  __I  uint32_t SINGLE_ERR_POS_HIGH7;              /**< High Single Error Bit Position On Ocram Bank7, offset: 0x18C */
  __I  uint32_t SINGLE_ERR_ADDR_ECC8;              /**< Single Error Address And ECC Code On Ocram Bank8, offset: 0x190 */
  __I  uint32_t SINGLE_ERR_DATA_LOW8;              /**< Low 32 Bits Single Error Read Data On Ocram Bank8, offset: 0x194 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH8;             /**< High 32 Bits Single Error Read Data On Ocram Bank8, offset: 0x198 */
  __I  uint32_t SINGLE_ERR_POS_LOW8;               /**< Low Single Error Bit Position On Ocram Bank8, offset: 0x19C */
  __I  uint32_t SINGLE_ERR_POS_HIGH8;              /**< High Single Error Bit Position On Ocram Bank8, offset: 0x1A0 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC9;              /**< Single Error Address And ECC Code On Ocram Bank9, offset: 0x1A4 */
  __I  uint32_t SINGLE_ERR_DATA_LOW9;              /**< Low 32 Bits Single Error Read Data On Ocram Bank9, offset: 0x1A8 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH9;             /**< High 32 Bits Single Error Read Data On Ocram Bank9, offset: 0x1AC */
  __I  uint32_t SINGLE_ERR_POS_LOW9;               /**< Low Single Error Bit Position On Ocram Bank9, offset: 0x1B0 */
  __I  uint32_t SINGLE_ERR_POS_HIGH9;              /**< High Single Error Bit Position On Ocram Bank9, offset: 0x1B4 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC10;             /**< Single Error Address And ECC Code On Ocram Bank10, offset: 0x1B8 */
  __I  uint32_t SINGLE_ERR_DATA_LOW10;             /**< Low 32 Bits Single Error Read Data On Ocram Bank10, offset: 0x1BC */
  __I  uint32_t SINGLE_ERR_DATA_HIGH10;            /**< High 32 Bits Single Error Read Data On Ocram Bank10, offset: 0x1C0 */
  __I  uint32_t SINGLE_ERR_POS_LOW10;              /**< Low Single Error Bit Position On Ocram Bank10, offset: 0x1C4 */
  __I  uint32_t SINGLE_ERR_POS_HIGH10;             /**< High Single Error Bit Position On Ocram Bank10, offset: 0x1C8 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC11;             /**< Single Error Address And ECC Code On Ocram Bank11, offset: 0x1CC */
  __I  uint32_t SINGLE_ERR_DATA_LOW11;             /**< Low 32 Bits Single Error Read Data On Ocram Bank11, offset: 0x1D0 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH11;            /**< High 32 Bits Single Error Read Data On Ocram Bank11, offset: 0x1D4 */
  __I  uint32_t SINGLE_ERR_POS_LOW11;              /**< Low Single Error Bit Position On Ocram Bank11, offset: 0x1D8 */
  __I  uint32_t SINGLE_ERR_POS_HIGH11;             /**< High Single Error Bit Position On Ocram Bank11, offset: 0x1DC */
  __I  uint32_t SINGLE_ERR_ADDR_ECC12;             /**< Single Error Address And ECC Code On Ocram Bank12, offset: 0x1E0 */
  __I  uint32_t SINGLE_ERR_DATA_LOW12;             /**< Low 32 Bits Single Error Read Data On Ocram Bank12, offset: 0x1E4 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH12;            /**< High 32 Bits Single Error Read Data On Ocram Bank12, offset: 0x1E8 */
  __I  uint32_t SINGLE_ERR_POS_LOW12;              /**< Low Single Error Bit Position On Ocram Bank12, offset: 0x1EC */
  __I  uint32_t SINGLE_ERR_POS_HIGH12;             /**< High Single Error Bit Position On Ocram Bank12, offset: 0x1F0 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC13;             /**< Single Error Address And ECC Code On Ocram Bank13, offset: 0x1F4 */
  __I  uint32_t SINGLE_ERR_DATA_LOW13;             /**< Low 32 Bits Single Error Read Data On Ocram Bank13, offset: 0x1F8 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH13;            /**< High 32 Bits Single Error Read Data On Ocram Bank13, offset: 0x1FC */
  __I  uint32_t SINGLE_ERR_POS_LOW13;              /**< Low Single Error Bit Position On Ocram Bank13, offset: 0x200 */
  __I  uint32_t SINGLE_ERR_POS_HIGH13;             /**< High Single Error Bit Position On Ocram Bank13, offset: 0x204 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC14;             /**< Single Error Address And ECC Code On Ocram Bank14, offset: 0x208 */
  __I  uint32_t SINGLE_ERR_DATA_LOW14;             /**< Low 32 Bits Single Error Read Data On Ocram Bank14, offset: 0x20C */
  __I  uint32_t SINGLE_ERR_DATA_HIGH14;            /**< High 32 Bits Single Error Read Data On Ocram Bank14, offset: 0x210 */
  __I  uint32_t SINGLE_ERR_POS_LOW14;              /**< Low Single Error Bit Position On Ocram Bank14, offset: 0x214 */
  __I  uint32_t SINGLE_ERR_POS_HIGH14;             /**< High Single Error Bit Position On Ocram Bank14, offset: 0x218 */
  __I  uint32_t SINGLE_ERR_ADDR_ECC15;             /**< Single Error Address And ECC Code On Ocram Bank15, offset: 0x21C */
  __I  uint32_t SINGLE_ERR_DATA_LOW15;             /**< Low 32 Bits Single Error Read Data On Ocram Bank15, offset: 0x220 */
  __I  uint32_t SINGLE_ERR_DATA_HIGH15;            /**< High 32 Bits Single Error Read Data On Ocram Bank15, offset: 0x224 */
  __I  uint32_t SINGLE_ERR_POS_LOW15;              /**< Low Single Error Bit Position On Ocram Bank15, offset: 0x228 */
  __I  uint32_t SINGLE_ERR_POS_HIGH15;             /**< High Single Error Bit Position On Ocram Bank15, offset: 0x22C */
  __I  uint32_t MULTI_ERR_ADDR_ECC0;               /**< Multiple Error Address And ECC Code On Ocram Bank0, offset: 0x230 */
  __I  uint32_t MULTI_ERR_DATA_LOW0;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank0, offset: 0x234 */
  __I  uint32_t MULTI_ERR_DATA_HIGH0;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank0, offset: 0x238 */
  __I  uint32_t MULTI_ERR_ADDR_ECC1;               /**< Multiple Error Address And ECC Code On Ocram Bank1, offset: 0x23C */
  __I  uint32_t MULTI_ERR_DATA_LOW1;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank1, offset: 0x240 */
  __I  uint32_t MULTI_ERR_DATA_HIGH1;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank1, offset: 0x244 */
  __I  uint32_t MULTI_ERR_ADDR_ECC2;               /**< Multiple Error Address And ECC Code On Ocram Bank2, offset: 0x248 */
  __I  uint32_t MULTI_ERR_DATA_LOW2;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank2, offset: 0x24C */
  __I  uint32_t MULTI_ERR_DATA_HIGH2;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank2, offset: 0x250 */
  __I  uint32_t MULTI_ERR_ADDR_ECC3;               /**< Multiple Error Address And ECC Code On Ocram Bank3, offset: 0x254 */
  __I  uint32_t MULTI_ERR_DATA_LOW3;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank3, offset: 0x258 */
  __I  uint32_t MULTI_ERR_DATA_HIGH3;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank3, offset: 0x25C */
  __I  uint32_t MULTI_ERR_ADDR_ECC4;               /**< Multiple Error Address And ECC Code On Ocram Bank4, offset: 0x260 */
  __I  uint32_t MULTI_ERR_DATA_LOW4;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank4, offset: 0x264 */
  __I  uint32_t MULTI_ERR_DATA_HIGH4;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank4, offset: 0x268 */
  __I  uint32_t MULTI_ERR_ADDR_ECC5;               /**< Multiple Error Address And ECC Code On Ocram Bank5, offset: 0x26C */
  __I  uint32_t MULTI_ERR_DATA_LOW5;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank5, offset: 0x270 */
  __I  uint32_t MULTI_ERR_DATA_HIGH5;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank5, offset: 0x274 */
  __I  uint32_t MULTI_ERR_ADDR_ECC6;               /**< Multiple Error Address And ECC Code On Ocram Bank6, offset: 0x278 */
  __I  uint32_t MULTI_ERR_DATA_LOW6;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank6, offset: 0x27C */
  __I  uint32_t MULTI_ERR_DATA_HIGH6;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank6, offset: 0x280 */
  __I  uint32_t MULTI_ERR_ADDR_ECC7;               /**< Multiple Error Address And ECC Code On Ocram Bank7, offset: 0x284 */
  __I  uint32_t MULTI_ERR_DATA_LOW7;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank7, offset: 0x288 */
  __I  uint32_t MULTI_ERR_DATA_HIGH7;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank7, offset: 0x28C */
  __I  uint32_t MULTI_ERR_ADDR_ECC8;               /**< Multiple Error Address And ECC Code On Ocram Bank8, offset: 0x290 */
  __I  uint32_t MULTI_ERR_DATA_LOW8;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank8, offset: 0x294 */
  __I  uint32_t MULTI_ERR_DATA_HIGH8;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank8, offset: 0x298 */
  __I  uint32_t MULTI_ERR_ADDR_ECC9;               /**< Multiple Error Address And ECC Code On Ocram Bank9, offset: 0x29C */
  __I  uint32_t MULTI_ERR_DATA_LOW9;               /**< Low 32 Bits Multiple Error Read Data On Ocram Bank9, offset: 0x2A0 */
  __I  uint32_t MULTI_ERR_DATA_HIGH9;              /**< High 32 Bits Multiple Error Read Data On Ocram Bank9, offset: 0x2A4 */
  __I  uint32_t MULTI_ERR_ADDR_ECC10;              /**< Multiple Error Address And ECC Code On Ocram Bank10, offset: 0x2A8 */
  __I  uint32_t MULTI_ERR_DATA_LOW10;              /**< Low 32 Bits Multiple Error Read Data On Ocram Bank10, offset: 0x2AC */
  __I  uint32_t MULTI_ERR_DATA_HIGH10;             /**< High 32 Bits Multiple Error Read Data On Ocram Bank10, offset: 0x2B0 */
  __I  uint32_t MULTI_ERR_ADDR_ECC11;              /**< Multiple Error Address And ECC Code On Ocram Bank11, offset: 0x2B4 */
  __I  uint32_t MULTI_ERR_DATA_LOW11;              /**< Low 32 Bits Multiple Error Read Data On Ocram Bank11, offset: 0x2B8 */
  __I  uint32_t MULTI_ERR_DATA_HIGH11;             /**< High 32 Bits Multiple Error Read Data On Ocram Bank11, offset: 0x2BC */
  __I  uint32_t MULTI_ERR_ADDR_ECC12;              /**< Multiple Error Address And ECC Code On Ocram Bank12, offset: 0x2C0 */
  __I  uint32_t MULTI_ERR_DATA_LOW12;              /**< Low 32 Bits Multiple Error Read Data On Ocram Bank12, offset: 0x2C4 */
  __I  uint32_t MULTI_ERR_DATA_HIGH12;             /**< High 32 Bits Multiple Error Read Data On Ocram Bank12, offset: 0x2C8 */
  __I  uint32_t MULTI_ERR_ADDR_ECC13;              /**< Multiple Error Address And ECC Code On Ocram Bank13, offset: 0x2CC */
  __I  uint32_t MULTI_ERR_DATA_LOW13;              /**< Low 32 Bits Multiple Error Read Data On Ocram Bank13, offset: 0x2D0 */
  __I  uint32_t MULTI_ERR_DATA_HIGH13;             /**< High 32 Bits Multiple Error Read Data On Ocram Bank13, offset: 0x2D4 */
  __I  uint32_t MULTI_ERR_ADDR_ECC14;              /**< Multiple Error Address And ECC Code On Ocram Bank14, offset: 0x2D8 */
  __I  uint32_t MULTI_ERR_DATA_LOW14;              /**< Low 32 Bits Multiple Error Read Data On Ocram Bank14, offset: 0x2DC */
  __I  uint32_t MULTI_ERR_DATA_HIGH14;             /**< High 32 Bits Multiple Error Read Data On Ocram Bank14, offset: 0x2E0 */
  __I  uint32_t MULTI_ERR_ADDR_ECC15;              /**< Multiple Error Address And ECC Code On Ocram Bank15, offset: 0x2E4 */
  __I  uint32_t MULTI_ERR_DATA_LOW15;              /**< Low 32 Bits Multiple Error Read Data On Ocram Bank15, offset: 0x2E8 */
  __I  uint32_t MULTI_ERR_DATA_HIGH15;             /**< High 32 Bits Multiple Error Read Data On Ocram Bank15, offset: 0x2EC */
  __IO uint32_t PIPE_ECC_EN;                       /**< Ocram Pipeline And ECC Enable, offset: 0x2F0 */
  __I  uint32_t PENDING_STAT;                      /**< Pending Status, offset: 0x2F4 */
  __IO uint32_t MEM_INIT;                          /**< Memory initialization, offset: 0x2F8 */
} OCRAM_MECC_Type;

/* ----------------------------------------------------------------------------
   -- OCRAM_MECC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCRAM_MECC_Register_Masks OCRAM_MECC Register Masks
 * @{
 */

/*! @name SINGLE_ERR_STATUS - Error Interrupt Status Register */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR0_MASK (0x1U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR0_SHIFT (0U)
/*! SINGLE_ERR0 - Single Bit Error On Ocram Bank0
 *  0b0..Single bit error does not happen on ocram bank0.
 *  0b1..Single bit error happens on ocram bank0.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR0_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR0_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR1_MASK (0x2U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR1_SHIFT (1U)
/*! SINGLE_ERR1 - Single Bit Error On Ocram Bank1
 *  0b0..Single bit error does not happen on ocram bank1.
 *  0b1..Single bit error happens on ocram bank1.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR1_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR1_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR2_MASK (0x4U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR2_SHIFT (2U)
/*! SINGLE_ERR2 - Single Bit Error On Ocram Bank2
 *  0b0..Single bit error does not happen on ocram bank2.
 *  0b1..Single bit error happens on ocram bank2.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR2_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR2_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR3_MASK (0x8U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR3_SHIFT (3U)
/*! SINGLE_ERR3 - Single Bit Error On Ocram Bank3
 *  0b0..Single bit error does not happen on ocram bank3.
 *  0b1..Single bit error happens on ocram bank3.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR3_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR3_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR4_MASK (0x10U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR4_SHIFT (4U)
/*! SINGLE_ERR4 - Multiple Bits Error On Ocram Bank0
 *  0b0..Multiple bits error does not happen on ocram bank0.
 *  0b1..Multiple bits error happens on ocram bank0.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR4_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR4_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR5_MASK (0x20U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR5_SHIFT (5U)
/*! SINGLE_ERR5 - Multiple Bits Error On Ocram Bank1
 *  0b0..Multiple bits error does not happen on ocram bank1.
 *  0b1..Multiple bits error happens on ocram bank1.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR5_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR5_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR6_MASK (0x40U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR6_SHIFT (6U)
/*! SINGLE_ERR6 - Multiple Bits Error On Ocram Bank2
 *  0b0..Multiple bits error does not happen on ocram bank2.
 *  0b1..Multiple bits error happens on ocram bank2.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR6_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR6_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR7_MASK (0x80U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR7_SHIFT (7U)
/*! SINGLE_ERR7 - Multiple Bits Error On Ocram Bank3
 *  0b0..Multiple bits error does not happen on ocram bank3.
 *  0b1..Multiple bits error happens on ocram bank3.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR7_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR7_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR8_MASK (0x100U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR8_SHIFT (8U)
/*! SINGLE_ERR8 - AXI Strobe Error On Ocram Bank0
 *  0b0..AXI strobe error does not happen on ocram bank0.
 *  0b1..AXI strobe error happens on ocram bank0.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR8_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR8_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR9_MASK (0x200U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR9_SHIFT (9U)
/*! SINGLE_ERR9 - AXI Strobe Error On Ocram Bank1
 *  0b0..AXI strobe error does not happen on ocram bank1.
 *  0b1..AXI strobe error happens on ocram bank1.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR9_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR9_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR10_MASK (0x400U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR10_SHIFT (10U)
/*! SINGLE_ERR10 - AXI Strobe Error On Ocram Bank2
 *  0b0..AXI strobe error does not happen on ocram bank2.
 *  0b1..AXI strobe error happens on ocram bank2.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR10_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR10_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR11_MASK (0x800U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR11_SHIFT (11U)
/*! SINGLE_ERR11 - AXI Strobe Error On Ocram Bank3
 *  0b0..AXI strobe error does not happen on ocram bank3.
 *  0b1..AXI strobe error happens on ocram bank3.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR11_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR11_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR12_MASK (0x1000U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR12_SHIFT (12U)
/*! SINGLE_ERR12 - Ocram Access Error On Bank0
 *  0b0..Ocram access error does not happen on ocram bank0.
 *  0b1..Ocram access error happens on ocram bank0.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR12_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR12_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR13_MASK (0x2000U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR13_SHIFT (13U)
/*! SINGLE_ERR13 - Ocram Access Error On Bank1
 *  0b0..Ocram access error does not happen on ocram bank1.
 *  0b1..Ocram access error happens on ocram bank1.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR13_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR13_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR14_MASK (0x4000U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR14_SHIFT (14U)
/*! SINGLE_ERR14 - Ocram Access Error On Bank2
 *  0b0..Ocram access error does not happen on ocram bank2.
 *  0b1..Ocram access error happens on ocram bank2.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR14_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR14_MASK)

#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR15_MASK (0x8000U)
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR15_SHIFT (15U)
/*! SINGLE_ERR15 - Ocram Access Error On Bank3
 *  0b0..Ocram access error does not happen on ocram bank3.
 *  0b1..Ocram access error happens on ocram bank3.
 */
#define OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR15_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STATUS_SINGLE_ERR15_MASK)
/*! @} */

/*! @name MULTI_ERR_STATUS - MULTI Error Interrupt Status Register */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR0_MASK (0x1U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR0_SHIFT (0U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR0_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR0_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR1_MASK (0x2U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR1_SHIFT (1U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR1_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR1_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR2_MASK (0x4U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR2_SHIFT (2U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR2_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR2_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR3_MASK (0x8U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR3_SHIFT (3U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR3_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR3_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR4_MASK (0x10U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR4_SHIFT (4U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR4_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR4_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR5_MASK (0x20U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR5_SHIFT (5U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR5_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR5_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR6_MASK (0x40U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR6_SHIFT (6U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR6_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR6_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR7_MASK (0x80U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR7_SHIFT (7U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR7_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR7_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR8_MASK (0x100U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR8_SHIFT (8U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR8_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR8_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR9_MASK (0x200U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR9_SHIFT (9U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR9_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR9_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR10_MASK (0x400U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR10_SHIFT (10U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR10_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR10_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR11_MASK (0x800U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR11_SHIFT (11U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR11_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR11_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR12_MASK (0x1000U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR12_SHIFT (12U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR12_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR12_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR13_MASK (0x2000U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR13_SHIFT (13U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR13_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR13_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR14_MASK (0x4000U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR14_SHIFT (14U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR14_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR14_MASK)

#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR15_MASK (0x8000U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR15_SHIFT (15U)
#define OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR15_SHIFT)) & OCRAM_MECC_MULTI_ERR_STATUS_MULTI_ERR15_MASK)
/*! @} */

/*! @name STRB_ERR_STATUS - STRB Error Interrupt Status Register */
/*! @{ */

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR0_MASK (0x1U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR0_SHIFT (0U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR0(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR0_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR0_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR1_MASK (0x2U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR1_SHIFT (1U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR1(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR1_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR1_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR2_MASK (0x4U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR2_SHIFT (2U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR2(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR2_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR2_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR3_MASK (0x8U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR3_SHIFT (3U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR3(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR3_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR3_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR4_MASK (0x10U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR4_SHIFT (4U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR4(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR4_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR4_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR5_MASK (0x20U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR5_SHIFT (5U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR5(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR5_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR5_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR6_MASK (0x40U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR6_SHIFT (6U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR6(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR6_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR6_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR7_MASK (0x80U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR7_SHIFT (7U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR7(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR7_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR7_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR8_MASK (0x100U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR8_SHIFT (8U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR8(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR8_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR8_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR9_MASK (0x200U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR9_SHIFT (9U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR9(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR9_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR9_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR10_MASK (0x400U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR10_SHIFT (10U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR10_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR10_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR11_MASK (0x800U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR11_SHIFT (11U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR11_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR11_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR12_MASK (0x1000U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR12_SHIFT (12U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR12_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR12_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR13_MASK (0x2000U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR13_SHIFT (13U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR13_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR13_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR14_MASK (0x4000U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR14_SHIFT (14U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR14_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR14_MASK)

#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR15_MASK (0x8000U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR15_SHIFT (15U)
#define OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR15_SHIFT)) & OCRAM_MECC_STRB_ERR_STATUS_STRB_ERR15_MASK)
/*! @} */

/*! @name ADDR_ERR_STATUS - ADDR Error Interrupt Status Register */
/*! @{ */

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR0_MASK (0x1U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR0_SHIFT (0U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR0(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR0_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR0_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR1_MASK (0x2U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR1_SHIFT (1U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR1(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR1_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR1_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR2_MASK (0x4U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR2_SHIFT (2U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR2(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR2_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR2_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR3_MASK (0x8U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR3_SHIFT (3U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR3(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR3_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR3_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR4_MASK (0x10U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR4_SHIFT (4U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR4(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR4_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR4_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR5_MASK (0x20U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR5_SHIFT (5U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR5(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR5_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR5_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR6_MASK (0x40U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR6_SHIFT (6U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR6(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR6_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR6_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR7_MASK (0x80U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR7_SHIFT (7U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR7(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR7_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR7_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR8_MASK (0x100U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR8_SHIFT (8U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR8(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR8_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR8_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR9_MASK (0x200U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR9_SHIFT (9U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR9(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR9_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR9_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR10_MASK (0x400U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR10_SHIFT (10U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR10_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR10_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR11_MASK (0x800U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR11_SHIFT (11U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR11_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR11_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR12_MASK (0x1000U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR12_SHIFT (12U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR12_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR12_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR13_MASK (0x2000U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR13_SHIFT (13U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR13_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR13_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR14_MASK (0x4000U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR14_SHIFT (14U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR14_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR14_MASK)

#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR15_MASK (0x8000U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR15_SHIFT (15U)
#define OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR15_SHIFT)) & OCRAM_MECC_ADDR_ERR_STATUS_ADDR_ERR15_MASK)
/*! @} */

/*! @name SINGLE_ERR_STAT_EN - Single Error Interrupt Status Enable Register */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR0_STAT_EN_MASK (0x1U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR0_STAT_EN_SHIFT (0U)
/*! SINGLE_ERR0_STAT_EN - Single Bit Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR0_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR0_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR0_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR1_STAT_EN_MASK (0x2U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR1_STAT_EN_SHIFT (1U)
/*! SINGLE_ERR1_STAT_EN - Single Bit Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR1_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR1_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR1_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR2_STAT_EN_MASK (0x4U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR2_STAT_EN_SHIFT (2U)
/*! SINGLE_ERR2_STAT_EN - Single Bit Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR2_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR2_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR2_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR3_STAT_EN_MASK (0x8U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR3_STAT_EN_SHIFT (3U)
/*! SINGLE_ERR3_STAT_EN - Single Bit Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR3_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR3_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR3_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR4_STAT_EN_MASK (0x10U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR4_STAT_EN_SHIFT (4U)
/*! SINGLE_ERR4_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR4_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR4_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR4_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR5_STAT_EN_MASK (0x20U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR5_STAT_EN_SHIFT (5U)
/*! SINGLE_ERR5_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR5_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR5_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR5_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR6_STAT_EN_MASK (0x40U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR6_STAT_EN_SHIFT (6U)
/*! SINGLE_ERR6_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR6_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR6_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR6_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR7_STAT_EN_MASK (0x80U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR7_STAT_EN_SHIFT (7U)
/*! SINGLE_ERR7_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR7_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR7_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR7_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR8_STAT_EN_MASK (0x100U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR8_STAT_EN_SHIFT (8U)
/*! SINGLE_ERR8_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR8_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR8_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR8_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR9_STAT_EN_MASK (0x200U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR9_STAT_EN_SHIFT (9U)
/*! SINGLE_ERR9_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR9_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR9_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR9_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR10_STAT_EN_MASK (0x400U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR10_STAT_EN_SHIFT (10U)
/*! SINGLE_ERR10_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR10_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR10_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR10_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR11_STAT_EN_MASK (0x800U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR11_STAT_EN_SHIFT (11U)
/*! SINGLE_ERR11_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR11_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR11_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR11_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR12_STAT_EN_MASK (0x1000U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR12_STAT_EN_SHIFT (12U)
/*! SINGLE_ERR12_STAT_EN - Ocram Access Error Status Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR12_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR12_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR12_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR13_STAT_EN_MASK (0x2000U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR13_STAT_EN_SHIFT (13U)
/*! SINGLE_ERR13_STAT_EN - Ocram Access Error Status Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR13_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR13_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR13_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR14_STAT_EN_MASK (0x4000U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR14_STAT_EN_SHIFT (14U)
/*! SINGLE_ERR14_STAT_EN - Ocram Access Error Status Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR14_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR14_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR14_STAT_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR15_STAT_EN_MASK (0x8000U)
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR15_STAT_EN_SHIFT (15U)
/*! SINGLE_ERR15_STAT_EN - Ocram Access Error Status Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR15_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR15_STAT_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_STAT_EN_SINGLE_ERR15_STAT_EN_MASK)
/*! @} */

/*! @name MULTI_ERR_STAT_EN - MULTI Error Interrupt Status Enable Register */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR0_STAT_EN_MASK (0x1U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR0_STAT_EN_SHIFT (0U)
/*! MULTI_ERR0_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR0_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR0_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR0_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR1_STAT_EN_MASK (0x2U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR1_STAT_EN_SHIFT (1U)
/*! MULTI_ERR1_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR1_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR1_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR1_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR2_STAT_EN_MASK (0x4U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR2_STAT_EN_SHIFT (2U)
/*! MULTI_ERR2_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR2_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR2_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR2_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR3_STAT_EN_MASK (0x8U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR3_STAT_EN_SHIFT (3U)
/*! MULTI_ERR3_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR3_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR3_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR3_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR4_STAT_EN_MASK (0x10U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR4_STAT_EN_SHIFT (4U)
/*! MULTI_ERR4_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR4_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR4_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR4_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR5_STAT_EN_MASK (0x20U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR5_STAT_EN_SHIFT (5U)
/*! MULTI_ERR5_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR5_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR5_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR5_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR6_STAT_EN_MASK (0x40U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR6_STAT_EN_SHIFT (6U)
/*! MULTI_ERR6_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR6_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR6_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR6_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR7_STAT_EN_MASK (0x80U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR7_STAT_EN_SHIFT (7U)
/*! MULTI_ERR7_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR7_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR7_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR7_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR8_STAT_EN_MASK (0x100U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR8_STAT_EN_SHIFT (8U)
/*! MULTI_ERR8_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR8_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR8_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR8_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR9_STAT_EN_MASK (0x200U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR9_STAT_EN_SHIFT (9U)
/*! MULTI_ERR9_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR9_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR9_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR9_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR10_STAT_EN_MASK (0x400U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR10_STAT_EN_SHIFT (10U)
/*! MULTI_ERR10_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR10_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR10_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR10_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR11_STAT_EN_MASK (0x800U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR11_STAT_EN_SHIFT (11U)
/*! MULTI_ERR11_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR11_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR11_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR11_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR12_STAT_EN_MASK (0x1000U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR12_STAT_EN_SHIFT (12U)
/*! MULTI_ERR12_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR12_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR12_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR12_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR13_STAT_EN_MASK (0x2000U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR13_STAT_EN_SHIFT (13U)
/*! MULTI_ERR13_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR13_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR13_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR13_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR14_STAT_EN_MASK (0x4000U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR14_STAT_EN_SHIFT (14U)
/*! MULTI_ERR14_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR14_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR14_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR14_STAT_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR15_STAT_EN_MASK (0x8000U)
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR15_STAT_EN_SHIFT (15U)
/*! MULTI_ERR15_STAT_EN - Multiple Bits Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR15_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR15_STAT_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_STAT_EN_MULTI_ERR15_STAT_EN_MASK)
/*! @} */

/*! @name STRB_ERR_STAT_EN - STRB Error Interrupt Status Enable Register */
/*! @{ */

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR0_STAT_EN_MASK (0x1U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR0_STAT_EN_SHIFT (0U)
/*! STRB_ERR0_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR0_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR0_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR0_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR1_STAT_EN_MASK (0x2U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR1_STAT_EN_SHIFT (1U)
/*! STRB_ERR1_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR1_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR1_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR1_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR2_STAT_EN_MASK (0x4U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR2_STAT_EN_SHIFT (2U)
/*! STRB_ERR2_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR2_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR2_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR2_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR3_STAT_EN_MASK (0x8U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR3_STAT_EN_SHIFT (3U)
/*! STRB_ERR3_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR3_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR3_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR3_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR4_STAT_EN_MASK (0x10U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR4_STAT_EN_SHIFT (4U)
/*! STRB_ERR4_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR4_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR4_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR4_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR5_STAT_EN_MASK (0x20U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR5_STAT_EN_SHIFT (5U)
/*! STRB_ERR5_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR5_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR5_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR5_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR6_STAT_EN_MASK (0x40U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR6_STAT_EN_SHIFT (6U)
/*! STRB_ERR6_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR6_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR6_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR6_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR7_STAT_EN_MASK (0x80U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR7_STAT_EN_SHIFT (7U)
/*! STRB_ERR7_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR7_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR7_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR7_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR8_STAT_EN_MASK (0x100U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR8_STAT_EN_SHIFT (8U)
/*! STRB_ERR8_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR8_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR8_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR8_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR9_STAT_EN_MASK (0x200U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR9_STAT_EN_SHIFT (9U)
/*! STRB_ERR9_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR9_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR9_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR9_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR10_STAT_EN_MASK (0x400U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR10_STAT_EN_SHIFT (10U)
/*! STRB_ERR10_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR10_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR10_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR10_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR11_STAT_EN_MASK (0x800U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR11_STAT_EN_SHIFT (11U)
/*! STRB_ERR11_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR11_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR11_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR11_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR12_STAT_EN_MASK (0x1000U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR12_STAT_EN_SHIFT (12U)
/*! STRB_ERR12_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR12_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR12_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR12_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR13_STAT_EN_MASK (0x2000U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR13_STAT_EN_SHIFT (13U)
/*! STRB_ERR13_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR13_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR13_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR13_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR14_STAT_EN_MASK (0x4000U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR14_STAT_EN_SHIFT (14U)
/*! STRB_ERR14_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR14_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR14_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR14_STAT_EN_MASK)

#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR15_STAT_EN_MASK (0x8000U)
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR15_STAT_EN_SHIFT (15U)
/*! STRB_ERR15_STAT_EN - AXI Strobe Error Status Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR15_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR15_STAT_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_STAT_EN_STRB_ERR15_STAT_EN_MASK)
/*! @} */

/*! @name ADDR_ERR_STAT_EN - ADDR Error Interrupt Status Enable Register */
/*! @{ */

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR0_STAT_EN_MASK (0x1U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR0_STAT_EN_SHIFT (0U)
/*! ADDR_ERR0_STAT_EN - Ocram Access Error Status Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR0_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR0_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR0_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR1_STAT_EN_MASK (0x2U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR1_STAT_EN_SHIFT (1U)
/*! ADDR_ERR1_STAT_EN - Ocram Access Error Status Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR1_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR1_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR1_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR2_STAT_EN_MASK (0x4U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR2_STAT_EN_SHIFT (2U)
/*! ADDR_ERR2_STAT_EN - Ocram Access Error Status Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR2_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR2_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR2_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR3_STAT_EN_MASK (0x8U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR3_STAT_EN_SHIFT (3U)
/*! ADDR_ERR3_STAT_EN - Ocram Access Error Status Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR3_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR3_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR3_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR4_STAT_EN_MASK (0x10U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR4_STAT_EN_SHIFT (4U)
/*! ADDR_ERR4_STAT_EN - Ocram Access Error Status Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR4_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR4_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR4_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR5_STAT_EN_MASK (0x20U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR5_STAT_EN_SHIFT (5U)
/*! ADDR_ERR5_STAT_EN - Ocram Access Error Status Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR5_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR5_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR5_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR6_STAT_EN_MASK (0x40U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR6_STAT_EN_SHIFT (6U)
/*! ADDR_ERR6_STAT_EN - Ocram Access Error Status Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR6_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR6_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR6_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR7_STAT_EN_MASK (0x80U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR7_STAT_EN_SHIFT (7U)
/*! ADDR_ERR7_STAT_EN - Ocram Access Error Status Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR7_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR7_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR7_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR8_STAT_EN_MASK (0x100U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR8_STAT_EN_SHIFT (8U)
/*! ADDR_ERR8_STAT_EN - Ocram Access Error Status Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR8_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR8_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR8_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR9_STAT_EN_MASK (0x200U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR9_STAT_EN_SHIFT (9U)
/*! ADDR_ERR9_STAT_EN - Ocram Access Error Status Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR9_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR9_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR9_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR10_STAT_EN_MASK (0x400U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR10_STAT_EN_SHIFT (10U)
/*! ADDR_ERR10_STAT_EN - Ocram Access Error Status Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR10_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR10_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR10_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR11_STAT_EN_MASK (0x800U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR11_STAT_EN_SHIFT (11U)
/*! ADDR_ERR11_STAT_EN - Ocram Access Error Status Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR11_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR11_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR11_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR12_STAT_EN_MASK (0x1000U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR12_STAT_EN_SHIFT (12U)
/*! ADDR_ERR12_STAT_EN - Ocram Access Error Status Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR12_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR12_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR12_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR13_STAT_EN_MASK (0x2000U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR13_STAT_EN_SHIFT (13U)
/*! ADDR_ERR13_STAT_EN - Ocram Access Error Status Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR13_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR13_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR13_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR14_STAT_EN_MASK (0x4000U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR14_STAT_EN_SHIFT (14U)
/*! ADDR_ERR14_STAT_EN - Ocram Access Error Status Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR14_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR14_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR14_STAT_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR15_STAT_EN_MASK (0x8000U)
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR15_STAT_EN_SHIFT (15U)
/*! ADDR_ERR15_STAT_EN - Ocram Access Error Status Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR15_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR15_STAT_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_STAT_EN_ADDR_ERR15_STAT_EN_MASK)
/*! @} */

/*! @name SINGLE_ERR_SIG_EN - Single Error Interrupt Enable Register */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR0_SIG_EN_MASK (0x1U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR0_SIG_EN_SHIFT (0U)
/*! SINGLE_ERR0_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR0_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR0_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR0_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR1_SIG_EN_MASK (0x2U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR1_SIG_EN_SHIFT (1U)
/*! SINGLE_ERR1_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR1_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR1_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR1_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR2_SIG_EN_MASK (0x4U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR2_SIG_EN_SHIFT (2U)
/*! SINGLE_ERR2_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR2_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR2_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR2_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR3_SIG_EN_MASK (0x8U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR3_SIG_EN_SHIFT (3U)
/*! SINGLE_ERR3_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR3_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR3_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR3_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR4_SIG_EN_MASK (0x10U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR4_SIG_EN_SHIFT (4U)
/*! SINGLE_ERR4_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR4_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR4_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR4_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR5_SIG_EN_MASK (0x20U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR5_SIG_EN_SHIFT (5U)
/*! SINGLE_ERR5_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR5_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR5_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR5_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR6_SIG_EN_MASK (0x40U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR6_SIG_EN_SHIFT (6U)
/*! SINGLE_ERR6_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR6_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR6_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR6_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR7_SIG_EN_MASK (0x80U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR7_SIG_EN_SHIFT (7U)
/*! SINGLE_ERR7_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR7_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR7_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR7_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR8_SIG_EN_MASK (0x100U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR8_SIG_EN_SHIFT (8U)
/*! SINGLE_ERR8_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR8_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR8_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR8_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR9_SIG_EN_MASK (0x200U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR9_SIG_EN_SHIFT (9U)
/*! SINGLE_ERR9_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR9_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR9_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR9_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR10_SIG_EN_MASK (0x400U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR10_SIG_EN_SHIFT (10U)
/*! SINGLE_ERR10_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR10_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR10_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR10_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR11_SIG_EN_MASK (0x800U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR11_SIG_EN_SHIFT (11U)
/*! SINGLE_ERR11_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR11_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR11_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR11_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR12_SIG_EN_MASK (0x1000U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR12_SIG_EN_SHIFT (12U)
/*! SINGLE_ERR12_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR12_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR12_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR12_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR13_SIG_EN_MASK (0x2000U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR13_SIG_EN_SHIFT (13U)
/*! SINGLE_ERR13_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR13_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR13_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR13_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR14_SIG_EN_MASK (0x4000U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR14_SIG_EN_SHIFT (14U)
/*! SINGLE_ERR14_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR14_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR14_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR14_SIG_EN_MASK)

#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR15_SIG_EN_MASK (0x8000U)
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR15_SIG_EN_SHIFT (15U)
/*! SINGLE_ERR15_SIG_EN - Single Bit Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR15_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR15_SIG_EN_SHIFT)) & OCRAM_MECC_SINGLE_ERR_SIG_EN_SINGLE_ERR15_SIG_EN_MASK)
/*! @} */

/*! @name MULTI_ERR_SIG_EN - MULTI Error Interrupt Enable Register */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR0_SIG_EN_MASK (0x1U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR0_SIG_EN_SHIFT (0U)
/*! MULTI_ERR0_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR0_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR0_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR0_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR1_SIG_EN_MASK (0x2U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR1_SIG_EN_SHIFT (1U)
/*! MULTI_ERR1_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR1_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR1_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR1_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR2_SIG_EN_MASK (0x4U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR2_SIG_EN_SHIFT (2U)
/*! MULTI_ERR2_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR2_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR2_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR2_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR3_SIG_EN_MASK (0x8U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR3_SIG_EN_SHIFT (3U)
/*! MULTI_ERR3_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR3_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR3_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR3_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR4_SIG_EN_MASK (0x10U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR4_SIG_EN_SHIFT (4U)
/*! MULTI_ERR4_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR4_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR4_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR4_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR5_SIG_EN_MASK (0x20U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR5_SIG_EN_SHIFT (5U)
/*! MULTI_ERR5_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR5_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR5_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR5_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR6_SIG_EN_MASK (0x40U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR6_SIG_EN_SHIFT (6U)
/*! MULTI_ERR6_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR6_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR6_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR6_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR7_SIG_EN_MASK (0x80U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR7_SIG_EN_SHIFT (7U)
/*! MULTI_ERR7_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR7_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR7_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR7_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR8_SIG_EN_MASK (0x100U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR8_SIG_EN_SHIFT (8U)
/*! MULTI_ERR8_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR8_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR8_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR8_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR9_SIG_EN_MASK (0x200U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR9_SIG_EN_SHIFT (9U)
/*! MULTI_ERR9_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR9_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR9_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR9_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR10_SIG_EN_MASK (0x400U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR10_SIG_EN_SHIFT (10U)
/*! MULTI_ERR10_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR10_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR10_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR10_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR11_SIG_EN_MASK (0x800U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR11_SIG_EN_SHIFT (11U)
/*! MULTI_ERR11_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR11_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR11_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR11_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR12_SIG_EN_MASK (0x1000U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR12_SIG_EN_SHIFT (12U)
/*! MULTI_ERR12_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR12_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR12_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR12_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR13_SIG_EN_MASK (0x2000U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR13_SIG_EN_SHIFT (13U)
/*! MULTI_ERR13_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR13_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR13_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR13_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR14_SIG_EN_MASK (0x4000U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR14_SIG_EN_SHIFT (14U)
/*! MULTI_ERR14_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR14_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR14_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR14_SIG_EN_MASK)

#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR15_SIG_EN_MASK (0x8000U)
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR15_SIG_EN_SHIFT (15U)
/*! MULTI_ERR15_SIG_EN - Multiple Bits Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR15_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR15_SIG_EN_SHIFT)) & OCRAM_MECC_MULTI_ERR_SIG_EN_MULTI_ERR15_SIG_EN_MASK)
/*! @} */

/*! @name STRB_ERR_SIG_EN - STRB Error Interrupt Enable Register */
/*! @{ */

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR0_SIG_EN_MASK (0x1U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR0_SIG_EN_SHIFT (0U)
/*! STRB_ERR0_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR0_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR0_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR0_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR1_SIG_EN_MASK (0x2U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR1_SIG_EN_SHIFT (1U)
/*! STRB_ERR1_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR1_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR1_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR1_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR2_SIG_EN_MASK (0x4U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR2_SIG_EN_SHIFT (2U)
/*! STRB_ERR2_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR2_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR2_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR2_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR3_SIG_EN_MASK (0x8U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR3_SIG_EN_SHIFT (3U)
/*! STRB_ERR3_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR3_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR3_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR3_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR4_SIG_EN_MASK (0x10U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR4_SIG_EN_SHIFT (4U)
/*! STRB_ERR4_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR4_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR4_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR4_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR5_SIG_EN_MASK (0x20U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR5_SIG_EN_SHIFT (5U)
/*! STRB_ERR5_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR5_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR5_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR5_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR6_SIG_EN_MASK (0x40U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR6_SIG_EN_SHIFT (6U)
/*! STRB_ERR6_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR6_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR6_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR6_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR7_SIG_EN_MASK (0x80U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR7_SIG_EN_SHIFT (7U)
/*! STRB_ERR7_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR7_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR7_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR7_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR8_SIG_EN_MASK (0x100U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR8_SIG_EN_SHIFT (8U)
/*! STRB_ERR8_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR8_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR8_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR8_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR9_SIG_EN_MASK (0x200U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR9_SIG_EN_SHIFT (9U)
/*! STRB_ERR9_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR9_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR9_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR9_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR10_SIG_EN_MASK (0x400U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR10_SIG_EN_SHIFT (10U)
/*! STRB_ERR10_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR10_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR10_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR10_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR11_SIG_EN_MASK (0x800U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR11_SIG_EN_SHIFT (11U)
/*! STRB_ERR11_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR11_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR11_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR11_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR12_SIG_EN_MASK (0x1000U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR12_SIG_EN_SHIFT (12U)
/*! STRB_ERR12_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR12_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR12_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR12_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR13_SIG_EN_MASK (0x2000U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR13_SIG_EN_SHIFT (13U)
/*! STRB_ERR13_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR13_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR13_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR13_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR14_SIG_EN_MASK (0x4000U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR14_SIG_EN_SHIFT (14U)
/*! STRB_ERR14_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR14_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR14_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR14_SIG_EN_MASK)

#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR15_SIG_EN_MASK (0x8000U)
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR15_SIG_EN_SHIFT (15U)
/*! STRB_ERR15_SIG_EN - AXI Strobe Error Interrupt Enable On Ocram Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR15_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR15_SIG_EN_SHIFT)) & OCRAM_MECC_STRB_ERR_SIG_EN_STRB_ERR15_SIG_EN_MASK)
/*! @} */

/*! @name ADDR_ERR_SIG_EN - ADDR Error Interrupt Enable Register */
/*! @{ */

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR0_SIG_EN_MASK (0x1U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR0_SIG_EN_SHIFT (0U)
/*! ADDR_ERR0_SIG_EN - Ocram Access Error Interrupt Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR0_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR0_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR0_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR1_SIG_EN_MASK (0x2U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR1_SIG_EN_SHIFT (1U)
/*! ADDR_ERR1_SIG_EN - Ocram Access Error Interrupt Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR1_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR1_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR1_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR2_SIG_EN_MASK (0x4U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR2_SIG_EN_SHIFT (2U)
/*! ADDR_ERR2_SIG_EN - Ocram Access Error Interrupt Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR2_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR2_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR2_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR3_SIG_EN_MASK (0x8U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR3_SIG_EN_SHIFT (3U)
/*! ADDR_ERR3_SIG_EN - Ocram Access Error Interrupt Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR3_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR3_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR3_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR4_SIG_EN_MASK (0x10U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR4_SIG_EN_SHIFT (4U)
/*! ADDR_ERR4_SIG_EN - Ocram Access Error Interrupt Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR4_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR4_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR4_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR5_SIG_EN_MASK (0x20U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR5_SIG_EN_SHIFT (5U)
/*! ADDR_ERR5_SIG_EN - Ocram Access Error Interrupt Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR5_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR5_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR5_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR6_SIG_EN_MASK (0x40U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR6_SIG_EN_SHIFT (6U)
/*! ADDR_ERR6_SIG_EN - Ocram Access Error Interrupt Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR6_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR6_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR6_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR7_SIG_EN_MASK (0x80U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR7_SIG_EN_SHIFT (7U)
/*! ADDR_ERR7_SIG_EN - Ocram Access Error Interrupt Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR7_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR7_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR7_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR8_SIG_EN_MASK (0x100U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR8_SIG_EN_SHIFT (8U)
/*! ADDR_ERR8_SIG_EN - Ocram Access Error Interrupt Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR8_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR8_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR8_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR9_SIG_EN_MASK (0x200U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR9_SIG_EN_SHIFT (9U)
/*! ADDR_ERR9_SIG_EN - Ocram Access Error Interrupt Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR9_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR9_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR9_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR10_SIG_EN_MASK (0x400U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR10_SIG_EN_SHIFT (10U)
/*! ADDR_ERR10_SIG_EN - Ocram Access Error Interrupt Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR10_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR10_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR10_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR11_SIG_EN_MASK (0x800U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR11_SIG_EN_SHIFT (11U)
/*! ADDR_ERR11_SIG_EN - Ocram Access Error Interrupt Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR11_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR11_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR11_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR12_SIG_EN_MASK (0x1000U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR12_SIG_EN_SHIFT (12U)
/*! ADDR_ERR12_SIG_EN - Ocram Access Error Interrupt Enable On Bank0
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR12_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR12_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR12_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR13_SIG_EN_MASK (0x2000U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR13_SIG_EN_SHIFT (13U)
/*! ADDR_ERR13_SIG_EN - Ocram Access Error Interrupt Enable On Bank1
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR13_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR13_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR13_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR14_SIG_EN_MASK (0x4000U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR14_SIG_EN_SHIFT (14U)
/*! ADDR_ERR14_SIG_EN - Ocram Access Error Interrupt Enable On Bank2
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR14_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR14_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR14_SIG_EN_MASK)

#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR15_SIG_EN_MASK (0x8000U)
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR15_SIG_EN_SHIFT (15U)
/*! ADDR_ERR15_SIG_EN - Ocram Access Error Interrupt Enable On Bank3
 *  0b0..Masked
 *  0b1..Enabled
 */
#define OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR15_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR15_SIG_EN_SHIFT)) & OCRAM_MECC_ADDR_ERR_SIG_EN_ADDR_ERR15_SIG_EN_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW0 - Error Injection On Low 32 bits Of Ocram Bank0 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW0_ERR_DATA_INJ_LOW0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW0_ERR_DATA_INJ_LOW0_SHIFT (0U)
/*! ERR_DATA_INJ_LOW0 - Error Injection On Low 32 bits Of Ocram Bank0 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW0_ERR_DATA_INJ_LOW0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW0_ERR_DATA_INJ_LOW0_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW0_ERR_DATA_INJ_LOW0_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH0 - Error Injection On High 32 bits Of Ocram Bank0 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH0_ERR_DATA_INJ_HIGH0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH0_ERR_DATA_INJ_HIGH0_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH0 - Error Injection On High 32 bits Of Ocram Bank0 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH0_ERR_DATA_INJ_HIGH0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH0_ERR_DATA_INJ_HIGH0_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH0_ERR_DATA_INJ_HIGH0_MASK)
/*! @} */

/*! @name ERR_ECC_INJ0 - Error Injection On 8 bits ECC code Of Ocram Bank0 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ0_ERR_ECC_INJ0_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ0_ERR_ECC_INJ0_SHIFT (0U)
/*! ERR_ECC_INJ0 - Error Injection On 8 bits ECC code Of Ocram Bank0 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ0_ERR_ECC_INJ0(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ0_ERR_ECC_INJ0_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ0_ERR_ECC_INJ0_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW1 - Error Injection On Low 32 bits Of Ocram Bank1 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW1_ERR_DATA_INJ_LOW1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW1_ERR_DATA_INJ_LOW1_SHIFT (0U)
/*! ERR_DATA_INJ_LOW1 - Error Injection On Low 32 bits Of Ocram Bank1 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW1_ERR_DATA_INJ_LOW1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW1_ERR_DATA_INJ_LOW1_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW1_ERR_DATA_INJ_LOW1_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH1 - Error Injection On High 32 bits Of Ocram Bank1 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH1_ERR_DATA_INJ_HIGH1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH1_ERR_DATA_INJ_HIGH1_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH1 - Error Injection On High 32 bits Of Ocram Bank1 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH1_ERR_DATA_INJ_HIGH1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH1_ERR_DATA_INJ_HIGH1_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH1_ERR_DATA_INJ_HIGH1_MASK)
/*! @} */

/*! @name ERR_ECC_INJ1 - Error Injection On 8 bits ECC code Of Ocram Bank1 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ1_ERR_ECC_INJ1_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ1_ERR_ECC_INJ1_SHIFT (0U)
/*! ERR_ECC_INJ1 - Error Injection On 8 bits ECC code Of Ocram Bank1 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ1_ERR_ECC_INJ1(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ1_ERR_ECC_INJ1_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ1_ERR_ECC_INJ1_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW2 - Error Injection On Low 32 bits Of Ocram Bank2 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW2_ERR_DATA_INJ_LOW2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW2_ERR_DATA_INJ_LOW2_SHIFT (0U)
/*! ERR_DATA_INJ_LOW2 - Error Injection On Low 32 bits Of Ocram Bank2 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW2_ERR_DATA_INJ_LOW2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW2_ERR_DATA_INJ_LOW2_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW2_ERR_DATA_INJ_LOW2_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH2 - Error Injection On High 32 bits Of Ocram Bank2 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH2_ERR_DATA_INJ_HIGH2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH2_ERR_DATA_INJ_HIGH2_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH2 - Error Injection On High 32 bits Of Ocram Bank2 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH2_ERR_DATA_INJ_HIGH2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH2_ERR_DATA_INJ_HIGH2_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH2_ERR_DATA_INJ_HIGH2_MASK)
/*! @} */

/*! @name ERR_ECC_INJ2 - Error Injection On 8 bits ECC code Of Ocram Bank2 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ2_ERR_ECC_INJ2_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ2_ERR_ECC_INJ2_SHIFT (0U)
/*! ERR_ECC_INJ2 - Error Injection On 8 bits ECC code Of Ocram Bank2 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ2_ERR_ECC_INJ2(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ2_ERR_ECC_INJ2_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ2_ERR_ECC_INJ2_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW3 - Error Injection On Low 32 bits Of Ocram Bank3 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW3_ERR_DATA_INJ_LOW3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW3_ERR_DATA_INJ_LOW3_SHIFT (0U)
/*! ERR_DATA_INJ_LOW3 - Error Injection On Low 32 bits Of Ocram Bank3 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW3_ERR_DATA_INJ_LOW3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW3_ERR_DATA_INJ_LOW3_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW3_ERR_DATA_INJ_LOW3_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH3 - Error Injection On High 32 bits Of Ocram Bank3 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH3_ERR_DATA_INJ_HIGH3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH3_ERR_DATA_INJ_HIGH3_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH3 - Error Injection On High 32 bits Of Ocram Bank2 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH3_ERR_DATA_INJ_HIGH3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH3_ERR_DATA_INJ_HIGH3_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH3_ERR_DATA_INJ_HIGH3_MASK)
/*! @} */

/*! @name ERR_ECC_INJ3 - Error Injection On 8 bits ECC code Of Ocram Bank3 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ3_ERR_ECC_INJ3_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ3_ERR_ECC_INJ3_SHIFT (0U)
/*! ERR_ECC_INJ3 - Error Injection On 8 bits ECC code Of Ocram Bank3 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ3_ERR_ECC_INJ3(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ3_ERR_ECC_INJ3_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ3_ERR_ECC_INJ3_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW4 - Error Injection On Low 32 bits Of Ocram Bank4 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW4_ERR_DATA_INJ_LOW4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW4_ERR_DATA_INJ_LOW4_SHIFT (0U)
/*! ERR_DATA_INJ_LOW4 - Error Injection On Low 32 bits Of Ocram Bank4 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW4_ERR_DATA_INJ_LOW4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW4_ERR_DATA_INJ_LOW4_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW4_ERR_DATA_INJ_LOW4_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH4 - Error Injection On High 32 bits Of Ocram Bank4 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH4_ERR_DATA_INJ_HIGH4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH4_ERR_DATA_INJ_HIGH4_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH4 - Error Injection On High 32 bits Of Ocram Bank4 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH4_ERR_DATA_INJ_HIGH4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH4_ERR_DATA_INJ_HIGH4_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH4_ERR_DATA_INJ_HIGH4_MASK)
/*! @} */

/*! @name ERR_ECC_INJ4 - Error Injection On 8 bits ECC code Of Ocram Bank4 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ4_ERR_ECC_INJ4_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ4_ERR_ECC_INJ4_SHIFT (0U)
/*! ERR_ECC_INJ4 - Error Injection On 8 bits ECC code Of Ocram Bank4 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ4_ERR_ECC_INJ4(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ4_ERR_ECC_INJ4_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ4_ERR_ECC_INJ4_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW5 - Error Injection On Low 32 bits Of Ocram Bank5 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW5_ERR_DATA_INJ_LOW5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW5_ERR_DATA_INJ_LOW5_SHIFT (0U)
/*! ERR_DATA_INJ_LOW5 - Error Injection On Low 32 bits Of Ocram Bank5 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW5_ERR_DATA_INJ_LOW5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW5_ERR_DATA_INJ_LOW5_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW5_ERR_DATA_INJ_LOW5_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH5 - Error Injection On High 32 bits Of Ocram Bank5 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH5_ERR_DATA_INJ_HIGH5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH5_ERR_DATA_INJ_HIGH5_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH5 - Error Injection On High 32 bits Of Ocram Bank5 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH5_ERR_DATA_INJ_HIGH5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH5_ERR_DATA_INJ_HIGH5_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH5_ERR_DATA_INJ_HIGH5_MASK)
/*! @} */

/*! @name ERR_ECC_INJ5 - Error Injection On 8 bits ECC code Of Ocram Bank5 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ5_ERR_ECC_INJ5_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ5_ERR_ECC_INJ5_SHIFT (0U)
/*! ERR_ECC_INJ5 - Error Injection On 8 bits ECC code Of Ocram Bank5 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ5_ERR_ECC_INJ5(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ5_ERR_ECC_INJ5_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ5_ERR_ECC_INJ5_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW6 - Error Injection On Low 32 bits Of Ocram Bank6 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW6_ERR_DATA_INJ_LOW6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW6_ERR_DATA_INJ_LOW6_SHIFT (0U)
/*! ERR_DATA_INJ_LOW6 - Error Injection On Low 32 bits Of Ocram Bank6 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW6_ERR_DATA_INJ_LOW6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW6_ERR_DATA_INJ_LOW6_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW6_ERR_DATA_INJ_LOW6_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH6 - Error Injection On High 32 bits Of Ocram Bank6 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH6_ERR_DATA_INJ_HIGH6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH6_ERR_DATA_INJ_HIGH6_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH6 - Error Injection On High 32 bits Of Ocram Bank6 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH6_ERR_DATA_INJ_HIGH6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH6_ERR_DATA_INJ_HIGH6_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH6_ERR_DATA_INJ_HIGH6_MASK)
/*! @} */

/*! @name ERR_ECC_INJ6 - Error Injection On 8 bits ECC code Of Ocram Bank6 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ6_ERR_ECC_INJ6_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ6_ERR_ECC_INJ6_SHIFT (0U)
/*! ERR_ECC_INJ6 - Error Injection On 8 bits ECC code Of Ocram Bank6 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ6_ERR_ECC_INJ6(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ6_ERR_ECC_INJ6_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ6_ERR_ECC_INJ6_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW7 - Error Injection On Low 32 bits Of Ocram Bank7 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW7_ERR_DATA_INJ_LOW7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW7_ERR_DATA_INJ_LOW7_SHIFT (0U)
/*! ERR_DATA_INJ_LOW7 - Error Injection On Low 32 bits Of Ocram Bank7 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW7_ERR_DATA_INJ_LOW7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW7_ERR_DATA_INJ_LOW7_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW7_ERR_DATA_INJ_LOW7_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH7 - Error Injection On High 32 bits Of Ocram Bank7 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH7_ERR_DATA_INJ_HIGH7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH7_ERR_DATA_INJ_HIGH7_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH7 - Error Injection On High 32 bits Of Ocram Bank7 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH7_ERR_DATA_INJ_HIGH7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH7_ERR_DATA_INJ_HIGH7_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH7_ERR_DATA_INJ_HIGH7_MASK)
/*! @} */

/*! @name ERR_ECC_INJ7 - Error Injection On 8 bits ECC code Of Ocram Bank7 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ7_ERR_ECC_INJ7_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ7_ERR_ECC_INJ7_SHIFT (0U)
/*! ERR_ECC_INJ7 - Error Injection On 8 bits ECC code Of Ocram Bank7 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ7_ERR_ECC_INJ7(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ7_ERR_ECC_INJ7_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ7_ERR_ECC_INJ7_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW8 - Error Injection On Low 32 bits Of Ocram Bank8 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW8_ERR_DATA_INJ_LOW8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW8_ERR_DATA_INJ_LOW8_SHIFT (0U)
/*! ERR_DATA_INJ_LOW8 - Error Injection On Low 32 bits Of Ocram Bank8 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW8_ERR_DATA_INJ_LOW8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW8_ERR_DATA_INJ_LOW8_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW8_ERR_DATA_INJ_LOW8_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH8 - Error Injection On High 32 bits Of Ocram Bank8 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH8_ERR_DATA_INJ_HIGH8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH8_ERR_DATA_INJ_HIGH8_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH8 - Error Injection On High 32 bits Of Ocram Bank8 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH8_ERR_DATA_INJ_HIGH8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH8_ERR_DATA_INJ_HIGH8_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH8_ERR_DATA_INJ_HIGH8_MASK)
/*! @} */

/*! @name ERR_ECC_INJ8 - Error Injection On 8 bits ECC code Of Ocram Bank8 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ8_ERR_ECC_INJ8_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ8_ERR_ECC_INJ8_SHIFT (0U)
/*! ERR_ECC_INJ8 - Error Injection On 8 bits ECC code Of Ocram Bank8 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ8_ERR_ECC_INJ8(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ8_ERR_ECC_INJ8_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ8_ERR_ECC_INJ8_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW9 - Error Injection On Low 32 bits Of Ocram Bank9 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW9_ERR_DATA_INJ_LOW9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW9_ERR_DATA_INJ_LOW9_SHIFT (0U)
/*! ERR_DATA_INJ_LOW9 - Error Injection On Low 32 bits Of Ocram Bank9 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW9_ERR_DATA_INJ_LOW9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW9_ERR_DATA_INJ_LOW9_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW9_ERR_DATA_INJ_LOW9_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH9 - Error Injection On High 32 bits Of Ocram Bank9 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH9_ERR_DATA_INJ_HIGH9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH9_ERR_DATA_INJ_HIGH9_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH9 - Error Injection On High 32 bits Of Ocram Bank9 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH9_ERR_DATA_INJ_HIGH9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH9_ERR_DATA_INJ_HIGH9_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH9_ERR_DATA_INJ_HIGH9_MASK)
/*! @} */

/*! @name ERR_ECC_INJ9 - Error Injection On 8 bits ECC code Of Ocram Bank9 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ9_ERR_ECC_INJ9_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ9_ERR_ECC_INJ9_SHIFT (0U)
/*! ERR_ECC_INJ9 - Error Injection On 8 bits ECC code Of Ocram Bank9 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ9_ERR_ECC_INJ9(x)  (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ9_ERR_ECC_INJ9_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ9_ERR_ECC_INJ9_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW10 - Error Injection On Low 32 bits Of Ocram Bank10 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW10_ERR_DATA_INJ_LOW10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW10_ERR_DATA_INJ_LOW10_SHIFT (0U)
/*! ERR_DATA_INJ_LOW10 - Error Injection On Low 32 bits Of Ocram Bank10 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW10_ERR_DATA_INJ_LOW10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW10_ERR_DATA_INJ_LOW10_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW10_ERR_DATA_INJ_LOW10_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH10 - Error Injection On High 32 bits Of Ocram Bank10 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH10_ERR_DATA_INJ_HIGH10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH10_ERR_DATA_INJ_HIGH10_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH10 - Error Injection On High 32 bits Of Ocram Bank10 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH10_ERR_DATA_INJ_HIGH10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH10_ERR_DATA_INJ_HIGH10_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH10_ERR_DATA_INJ_HIGH10_MASK)
/*! @} */

/*! @name ERR_ECC_INJ10 - Error Injection On 8 bits ECC code Of Ocram Bank10 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ10_ERR_ECC_INJ10_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ10_ERR_ECC_INJ10_SHIFT (0U)
/*! ERR_ECC_INJ10 - Error Injection On 8 bits ECC code Of Ocram Bank10 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ10_ERR_ECC_INJ10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ10_ERR_ECC_INJ10_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ10_ERR_ECC_INJ10_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW11 - Error Injection On Low 32 bits Of Ocram Bank11 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW11_ERR_DATA_INJ_LOW11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW11_ERR_DATA_INJ_LOW11_SHIFT (0U)
/*! ERR_DATA_INJ_LOW11 - Error Injection On Low 32 bits Of Ocram Bank11 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW11_ERR_DATA_INJ_LOW11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW11_ERR_DATA_INJ_LOW11_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW11_ERR_DATA_INJ_LOW11_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH11 - Error Injection On High 32 bits Of Ocram Bank11 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH11_ERR_DATA_INJ_HIGH11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH11_ERR_DATA_INJ_HIGH11_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH11 - Error Injection On High 32 bits Of Ocram Bank11 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH11_ERR_DATA_INJ_HIGH11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH11_ERR_DATA_INJ_HIGH11_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH11_ERR_DATA_INJ_HIGH11_MASK)
/*! @} */

/*! @name ERR_ECC_INJ11 - Error Injection On 8 bits ECC code Of Ocram Bank11 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ11_ERR_ECC_INJ11_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ11_ERR_ECC_INJ11_SHIFT (0U)
/*! ERR_ECC_INJ11 - Error Injection On 8 bits ECC code Of Ocram Bank11 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ11_ERR_ECC_INJ11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ11_ERR_ECC_INJ11_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ11_ERR_ECC_INJ11_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW12 - Error Injection On Low 32 bits Of Ocram Bank12 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW12_ERR_DATA_INJ_LOW12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW12_ERR_DATA_INJ_LOW12_SHIFT (0U)
/*! ERR_DATA_INJ_LOW12 - Error Injection On Low 32 bits Of Ocram Bank12 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW12_ERR_DATA_INJ_LOW12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW12_ERR_DATA_INJ_LOW12_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW12_ERR_DATA_INJ_LOW12_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH12 - Error Injection On High 32 bits Of Ocram Bank12 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH12_ERR_DATA_INJ_HIGH12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH12_ERR_DATA_INJ_HIGH12_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH12 - Error Injection On High 32 bits Of Ocram Bank12 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH12_ERR_DATA_INJ_HIGH12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH12_ERR_DATA_INJ_HIGH12_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH12_ERR_DATA_INJ_HIGH12_MASK)
/*! @} */

/*! @name ERR_ECC_INJ12 - Error Injection On 8 bits ECC code Of Ocram Bank12 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ12_ERR_ECC_INJ12_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ12_ERR_ECC_INJ12_SHIFT (0U)
/*! ERR_ECC_INJ12 - Error Injection On 8 bits ECC code Of Ocram Bank12 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ12_ERR_ECC_INJ12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ12_ERR_ECC_INJ12_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ12_ERR_ECC_INJ12_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW13 - Error Injection On Low 32 bits Of Ocram Bank13 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW13_ERR_DATA_INJ_LOW13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW13_ERR_DATA_INJ_LOW13_SHIFT (0U)
/*! ERR_DATA_INJ_LOW13 - Error Injection On Low 32 bits Of Ocram Bank13 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW13_ERR_DATA_INJ_LOW13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW13_ERR_DATA_INJ_LOW13_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW13_ERR_DATA_INJ_LOW13_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH13 - Error Injection On High 32 bits Of Ocram Bank13 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH13_ERR_DATA_INJ_HIGH13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH13_ERR_DATA_INJ_HIGH13_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH13 - Error Injection On High 32 bits Of Ocram Bank13 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH13_ERR_DATA_INJ_HIGH13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH13_ERR_DATA_INJ_HIGH13_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH13_ERR_DATA_INJ_HIGH13_MASK)
/*! @} */

/*! @name ERR_ECC_INJ13 - Error Injection On 8 bits ECC code Of Ocram Bank13 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ13_ERR_ECC_INJ13_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ13_ERR_ECC_INJ13_SHIFT (0U)
/*! ERR_ECC_INJ13 - Error Injection On 8 bits ECC code Of Ocram Bank13 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ13_ERR_ECC_INJ13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ13_ERR_ECC_INJ13_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ13_ERR_ECC_INJ13_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW14 - Error Injection On Low 32 bits Of Ocram Bank14 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW14_ERR_DATA_INJ_LOW14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW14_ERR_DATA_INJ_LOW14_SHIFT (0U)
/*! ERR_DATA_INJ_LOW14 - Error Injection On Low 32 bits Of Ocram Bank14 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW14_ERR_DATA_INJ_LOW14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW14_ERR_DATA_INJ_LOW14_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW14_ERR_DATA_INJ_LOW14_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH14 - Error Injection On High 32 bits Of Ocram Bank14 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH14_ERR_DATA_INJ_HIGH14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH14_ERR_DATA_INJ_HIGH14_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH14 - Error Injection On High 32 bits Of Ocram Bank14 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH14_ERR_DATA_INJ_HIGH14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH14_ERR_DATA_INJ_HIGH14_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH14_ERR_DATA_INJ_HIGH14_MASK)
/*! @} */

/*! @name ERR_ECC_INJ14 - Error Injection On 8 bits ECC code Of Ocram Bank14 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ14_ERR_ECC_INJ14_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ14_ERR_ECC_INJ14_SHIFT (0U)
/*! ERR_ECC_INJ14 - Error Injection On 8 bits ECC code Of Ocram Bank14 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ14_ERR_ECC_INJ14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ14_ERR_ECC_INJ14_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ14_ERR_ECC_INJ14_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_LOW15 - Error Injection On Low 32 bits Of Ocram Bank15 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_LOW15_ERR_DATA_INJ_LOW15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_LOW15_ERR_DATA_INJ_LOW15_SHIFT (0U)
/*! ERR_DATA_INJ_LOW15 - Error Injection On Low 32 bits Of Ocram Bank15 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_LOW15_ERR_DATA_INJ_LOW15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_LOW15_ERR_DATA_INJ_LOW15_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_LOW15_ERR_DATA_INJ_LOW15_MASK)
/*! @} */

/*! @name ERR_DATA_INJ_HIGH15 - Error Injection On High 32 bits Of Ocram Bank15 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_DATA_INJ_HIGH15_ERR_DATA_INJ_HIGH15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_ERR_DATA_INJ_HIGH15_ERR_DATA_INJ_HIGH15_SHIFT (0U)
/*! ERR_DATA_INJ_HIGH15 - Error Injection On High 32 bits Of Ocram Bank15 Write Data */
#define OCRAM_MECC_ERR_DATA_INJ_HIGH15_ERR_DATA_INJ_HIGH15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_DATA_INJ_HIGH15_ERR_DATA_INJ_HIGH15_SHIFT)) & OCRAM_MECC_ERR_DATA_INJ_HIGH15_ERR_DATA_INJ_HIGH15_MASK)
/*! @} */

/*! @name ERR_ECC_INJ15 - Error Injection On 8 bits ECC code Of Ocram Bank15 Write Data */
/*! @{ */

#define OCRAM_MECC_ERR_ECC_INJ15_ERR_ECC_INJ15_MASK (0xFFU)
#define OCRAM_MECC_ERR_ECC_INJ15_ERR_ECC_INJ15_SHIFT (0U)
/*! ERR_ECC_INJ15 - Error Injection On 8 bits ECC code Of Ocram Bank15 Write Data */
#define OCRAM_MECC_ERR_ECC_INJ15_ERR_ECC_INJ15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_ERR_ECC_INJ15_ERR_ECC_INJ15_SHIFT)) & OCRAM_MECC_ERR_ECC_INJ15_ERR_ECC_INJ15_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC0 - Single Error Address And ECC Code On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ECC0_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ECC0_SHIFT (0U)
/*! SINGLE_ERR_ECC0 - Single Error ECC Code On Ocram Bank0 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ECC0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ECC0_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ECC0_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ADDR0_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ADDR0_SHIFT (8U)
/*! SINGLE_ERR_ADDR0 - Single Error Address On Ocram Bank0 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ADDR0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ADDR0_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC0_SINGLE_ERR_ADDR0_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW0 - Low 32 Bits Single Error Read Data On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW0_SINGLE_ERR_DATA_LOW0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW0_SINGLE_ERR_DATA_LOW0_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW0 - Low 32 Bits Single Error Read Data On Ocram Bank0 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW0_SINGLE_ERR_DATA_LOW0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW0_SINGLE_ERR_DATA_LOW0_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW0_SINGLE_ERR_DATA_LOW0_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH0 - High 32 Bits Single Error Read Data On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH0_SINGLE_ERR_DATA_HIGH0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH0_SINGLE_ERR_DATA_HIGH0_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH0 - High 32 Bits Single Error Read Data On Ocram Bank0 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH0_SINGLE_ERR_DATA_HIGH0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH0_SINGLE_ERR_DATA_HIGH0_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH0_SINGLE_ERR_DATA_HIGH0_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW0 - Low Single Error Bit Position On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW0_SINGLE_ERR_POS_LOW0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW0_SINGLE_ERR_POS_LOW0_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW0 - Low Single Error Bit Position On Ocram Bank0 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW0_SINGLE_ERR_POS_LOW0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW0_SINGLE_ERR_POS_LOW0_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW0_SINGLE_ERR_POS_LOW0_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH0 - High Single Error Bit Position On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH0_SINGLE_ERR_POS_HIGH0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH0_SINGLE_ERR_POS_HIGH0_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH0 - High Single Error Bit Position On Ocram Bank0 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH0_SINGLE_ERR_POS_HIGH0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH0_SINGLE_ERR_POS_HIGH0_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH0_SINGLE_ERR_POS_HIGH0_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC1 - Single Error Address And ECC Code On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ECC1_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ECC1_SHIFT (0U)
/*! SINGLE_ERR_ECC1 - Single Error ECC Code On Ocram Bank1 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ECC1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ECC1_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ECC1_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ADDR1_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ADDR1_SHIFT (8U)
/*! SINGLE_ERR_ADDR1 - Single Error Address On Ocram Bank1 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ADDR1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ADDR1_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC1_SINGLE_ERR_ADDR1_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW1 - Low 32 Bits Single Error Read Data On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW1_SINGLE_ERR_DATA_LOW1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW1_SINGLE_ERR_DATA_LOW1_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW1 - Low 32 Bits Single Error Read Data On Ocram Bank1 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW1_SINGLE_ERR_DATA_LOW1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW1_SINGLE_ERR_DATA_LOW1_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW1_SINGLE_ERR_DATA_LOW1_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH1 - High 32 Bits Single Error Read Data On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH1_SINGLE_ERR_DATA_HIGH1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH1_SINGLE_ERR_DATA_HIGH1_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH1 - High 32 Bits Single Error Read Data On Ocram Bank1 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH1_SINGLE_ERR_DATA_HIGH1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH1_SINGLE_ERR_DATA_HIGH1_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH1_SINGLE_ERR_DATA_HIGH1_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW1 - Low Single Error Bit Position On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW1_SINGLE_ERR_POS_LOW1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW1_SINGLE_ERR_POS_LOW1_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW1 - Low Single Error Bit Position On Ocram Bank1 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW1_SINGLE_ERR_POS_LOW1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW1_SINGLE_ERR_POS_LOW1_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW1_SINGLE_ERR_POS_LOW1_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH1 - High Single Error Bit Position On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH1_SINGLE_ERR_POS_HIGH1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH1_SINGLE_ERR_POS_HIGH1_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH1 - High Single Error Bit Position On Ocram Bank1 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH1_SINGLE_ERR_POS_HIGH1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH1_SINGLE_ERR_POS_HIGH1_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH1_SINGLE_ERR_POS_HIGH1_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC2 - Single Error Address And ECC Code On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ECC2_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ECC2_SHIFT (0U)
/*! SINGLE_ERR_ECC2 - Single Error ECC Code On Ocram Bank2 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ECC2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ECC2_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ECC2_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ADDR2_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ADDR2_SHIFT (8U)
/*! SINGLE_ERR_ADDR2 - Single Error Address On Ocram Bank2 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ADDR2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ADDR2_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC2_SINGLE_ERR_ADDR2_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW2 - Low 32 Bits Single Error Read Data On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW2_SINGLE_ERR_DATA_LOW2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW2_SINGLE_ERR_DATA_LOW2_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW2 - Low 32 Bits Single Error Read Data On Ocram Bank2 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW2_SINGLE_ERR_DATA_LOW2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW2_SINGLE_ERR_DATA_LOW2_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW2_SINGLE_ERR_DATA_LOW2_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH2 - High 32 Bits Single Error Read Data On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH2_SINGLE_ERR_DATA_HIGH2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH2_SINGLE_ERR_DATA_HIGH2_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH2 - High 32 Bits Single Error Read Data On Ocram Bank2 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH2_SINGLE_ERR_DATA_HIGH2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH2_SINGLE_ERR_DATA_HIGH2_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH2_SINGLE_ERR_DATA_HIGH2_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW2 - Low Single Error Bit Position On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW2_SINGLE_ERR_POS_LOW2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW2_SINGLE_ERR_POS_LOW2_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW2 - Low Single Error Bit Position On Ocram Bank2 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW2_SINGLE_ERR_POS_LOW2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW2_SINGLE_ERR_POS_LOW2_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW2_SINGLE_ERR_POS_LOW2_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH2 - High Single Error Bit Position On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH2_SINGLE_ERR_POS_HIGH2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH2_SINGLE_ERR_POS_HIGH2_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH2 - High Single Error Bit Position On Ocram Bank2 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH2_SINGLE_ERR_POS_HIGH2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH2_SINGLE_ERR_POS_HIGH2_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH2_SINGLE_ERR_POS_HIGH2_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC3 - Single Error Address And ECC Code On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ECC3_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ECC3_SHIFT (0U)
/*! SINGLE_ERR_ECC3 - Single Error ECC Code On Ocram Bank3 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ECC3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ECC3_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ECC3_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ADDR3_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ADDR3_SHIFT (8U)
/*! SINGLE_ERR_ADDR3 - Single Error Address On Ocram Bank3 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ADDR3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ADDR3_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC3_SINGLE_ERR_ADDR3_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW3 - Low 32 Bits Single Error Read Data On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW3_SINGLE_ERR_DATA_LOW3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW3_SINGLE_ERR_DATA_LOW3_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW3 - Low 32 Bits Single Error Read Data On Ocram Bank3 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW3_SINGLE_ERR_DATA_LOW3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW3_SINGLE_ERR_DATA_LOW3_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW3_SINGLE_ERR_DATA_LOW3_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH3 - High 32 Bits Single Error Read Data On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH3_SINGLE_ERR_DATA_HIGH3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH3_SINGLE_ERR_DATA_HIGH3_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH3 - High 32 Bits Single Error Read Data On Ocram Bank3 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH3_SINGLE_ERR_DATA_HIGH3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH3_SINGLE_ERR_DATA_HIGH3_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH3_SINGLE_ERR_DATA_HIGH3_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW3 - Low Single Error Bit Position On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW3_SINGLE_ERR_POS_LOW3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW3_SINGLE_ERR_POS_LOW3_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW3 - Low Single Error Bit Position On Ocram Bank3 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW3_SINGLE_ERR_POS_LOW3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW3_SINGLE_ERR_POS_LOW3_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW3_SINGLE_ERR_POS_LOW3_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH3 - High Single Error Bit Position On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH3_SINGLE_ERR_POS_HIGH3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH3_SINGLE_ERR_POS_HIGH3_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH3 - High Single Error Bit Position On Ocram Bank3 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH3_SINGLE_ERR_POS_HIGH3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH3_SINGLE_ERR_POS_HIGH3_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH3_SINGLE_ERR_POS_HIGH3_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC4 - Single Error Address And ECC Code On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ECC4_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ECC4_SHIFT (0U)
/*! SINGLE_ERR_ECC4 - Single Error ECC Code On Ocram Bank4 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ECC4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ECC4_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ECC4_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ADDR4_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ADDR4_SHIFT (8U)
/*! SINGLE_ERR_ADDR4 - Single Error Address On Ocram Bank4 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ADDR4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ADDR4_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC4_SINGLE_ERR_ADDR4_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW4 - Low 32 Bits Single Error Read Data On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW4_SINGLE_ERR_DATA_LOW4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW4_SINGLE_ERR_DATA_LOW4_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW4 - Low 32 Bits Single Error Read Data On Ocram Bank4 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW4_SINGLE_ERR_DATA_LOW4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW4_SINGLE_ERR_DATA_LOW4_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW4_SINGLE_ERR_DATA_LOW4_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH4 - High 32 Bits Single Error Read Data On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH4_SINGLE_ERR_DATA_HIGH4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH4_SINGLE_ERR_DATA_HIGH4_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH4 - High 32 Bits Single Error Read Data On Ocram Bank4 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH4_SINGLE_ERR_DATA_HIGH4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH4_SINGLE_ERR_DATA_HIGH4_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH4_SINGLE_ERR_DATA_HIGH4_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW4 - Low Single Error Bit Position On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW4_SINGLE_ERR_POS_LOW4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW4_SINGLE_ERR_POS_LOW4_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW4 - Low Single Error Bit Position On Ocram Bank4 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW4_SINGLE_ERR_POS_LOW4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW4_SINGLE_ERR_POS_LOW4_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW4_SINGLE_ERR_POS_LOW4_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH4 - High Single Error Bit Position On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH4_SINGLE_ERR_POS_HIGH4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH4_SINGLE_ERR_POS_HIGH4_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH4 - High Single Error Bit Position On Ocram Bank4 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH4_SINGLE_ERR_POS_HIGH4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH4_SINGLE_ERR_POS_HIGH4_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH4_SINGLE_ERR_POS_HIGH4_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC5 - Single Error Address And ECC Code On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ECC5_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ECC5_SHIFT (0U)
/*! SINGLE_ERR_ECC5 - Single Error ECC Code On Ocram Bank5 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ECC5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ECC5_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ECC5_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ADDR5_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ADDR5_SHIFT (8U)
/*! SINGLE_ERR_ADDR5 - Single Error Address On Ocram Bank5 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ADDR5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ADDR5_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC5_SINGLE_ERR_ADDR5_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW5 - Low 32 Bits Single Error Read Data On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW5_SINGLE_ERR_DATA_LOW5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW5_SINGLE_ERR_DATA_LOW5_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW5 - Low 32 Bits Single Error Read Data On Ocram Bank5 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW5_SINGLE_ERR_DATA_LOW5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW5_SINGLE_ERR_DATA_LOW5_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW5_SINGLE_ERR_DATA_LOW5_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH5 - High 32 Bits Single Error Read Data On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH5_SINGLE_ERR_DATA_HIGH5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH5_SINGLE_ERR_DATA_HIGH5_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH5 - High 32 Bits Single Error Read Data On Ocram Bank5 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH5_SINGLE_ERR_DATA_HIGH5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH5_SINGLE_ERR_DATA_HIGH5_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH5_SINGLE_ERR_DATA_HIGH5_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW5 - Low Single Error Bit Position On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW5_SINGLE_ERR_POS_LOW5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW5_SINGLE_ERR_POS_LOW5_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW5 - Low Single Error Bit Position On Ocram Bank5 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW5_SINGLE_ERR_POS_LOW5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW5_SINGLE_ERR_POS_LOW5_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW5_SINGLE_ERR_POS_LOW5_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH5 - High Single Error Bit Position On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH5_SINGLE_ERR_POS_HIGH5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH5_SINGLE_ERR_POS_HIGH5_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH5 - High Single Error Bit Position On Ocram Bank5 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH5_SINGLE_ERR_POS_HIGH5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH5_SINGLE_ERR_POS_HIGH5_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH5_SINGLE_ERR_POS_HIGH5_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC6 - Single Error Address And ECC Code On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ECC6_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ECC6_SHIFT (0U)
/*! SINGLE_ERR_ECC6 - Single Error ECC Code On Ocram Bank6 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ECC6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ECC6_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ECC6_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ADDR6_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ADDR6_SHIFT (8U)
/*! SINGLE_ERR_ADDR6 - Single Error Address On Ocram Bank6 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ADDR6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ADDR6_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC6_SINGLE_ERR_ADDR6_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW6 - Low 32 Bits Single Error Read Data On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW6_SINGLE_ERR_DATA_LOW6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW6_SINGLE_ERR_DATA_LOW6_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW6 - Low 32 Bits Single Error Read Data On Ocram Bank6 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW6_SINGLE_ERR_DATA_LOW6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW6_SINGLE_ERR_DATA_LOW6_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW6_SINGLE_ERR_DATA_LOW6_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH6 - High 32 Bits Single Error Read Data On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH6_SINGLE_ERR_DATA_HIGH6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH6_SINGLE_ERR_DATA_HIGH6_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH6 - High 32 Bits Single Error Read Data On Ocram Bank6 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH6_SINGLE_ERR_DATA_HIGH6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH6_SINGLE_ERR_DATA_HIGH6_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH6_SINGLE_ERR_DATA_HIGH6_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW6 - Low Single Error Bit Position On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW6_SINGLE_ERR_POS_LOW6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW6_SINGLE_ERR_POS_LOW6_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW6 - Low Single Error Bit Position On Ocram Bank6 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW6_SINGLE_ERR_POS_LOW6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW6_SINGLE_ERR_POS_LOW6_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW6_SINGLE_ERR_POS_LOW6_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH6 - High Single Error Bit Position On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH6_SINGLE_ERR_POS_HIGH6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH6_SINGLE_ERR_POS_HIGH6_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH6 - High Single Error Bit Position On Ocram Bank6 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH6_SINGLE_ERR_POS_HIGH6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH6_SINGLE_ERR_POS_HIGH6_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH6_SINGLE_ERR_POS_HIGH6_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC7 - Single Error Address And ECC Code On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ECC7_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ECC7_SHIFT (0U)
/*! SINGLE_ERR_ECC7 - Single Error ECC Code On Ocram Bank7 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ECC7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ECC7_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ECC7_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ADDR7_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ADDR7_SHIFT (8U)
/*! SINGLE_ERR_ADDR7 - Single Error Address On Ocram Bank7 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ADDR7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ADDR7_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC7_SINGLE_ERR_ADDR7_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW7 - Low 32 Bits Single Error Read Data On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW7_SINGLE_ERR_DATA_LOW7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW7_SINGLE_ERR_DATA_LOW7_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW7 - Low 32 Bits Single Error Read Data On Ocram Bank7 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW7_SINGLE_ERR_DATA_LOW7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW7_SINGLE_ERR_DATA_LOW7_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW7_SINGLE_ERR_DATA_LOW7_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH7 - High 32 Bits Single Error Read Data On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH7_SINGLE_ERR_DATA_HIGH7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH7_SINGLE_ERR_DATA_HIGH7_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH7 - High 32 Bits Single Error Read Data On Ocram Bank7 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH7_SINGLE_ERR_DATA_HIGH7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH7_SINGLE_ERR_DATA_HIGH7_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH7_SINGLE_ERR_DATA_HIGH7_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW7 - Low Single Error Bit Position On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW7_SINGLE_ERR_POS_LOW7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW7_SINGLE_ERR_POS_LOW7_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW7 - Low Single Error Bit Position On Ocram Bank7 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW7_SINGLE_ERR_POS_LOW7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW7_SINGLE_ERR_POS_LOW7_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW7_SINGLE_ERR_POS_LOW7_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH7 - High Single Error Bit Position On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH7_SINGLE_ERR_POS_HIGH7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH7_SINGLE_ERR_POS_HIGH7_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH7 - High Single Error Bit Position On Ocram Bank7 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH7_SINGLE_ERR_POS_HIGH7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH7_SINGLE_ERR_POS_HIGH7_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH7_SINGLE_ERR_POS_HIGH7_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC8 - Single Error Address And ECC Code On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ECC8_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ECC8_SHIFT (0U)
/*! SINGLE_ERR_ECC8 - Single Error ECC Code On Ocram Bank8 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ECC8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ECC8_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ECC8_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ADDR8_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ADDR8_SHIFT (8U)
/*! SINGLE_ERR_ADDR8 - Single Error Address On Ocram Bank8 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ADDR8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ADDR8_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC8_SINGLE_ERR_ADDR8_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW8 - Low 32 Bits Single Error Read Data On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW8_SINGLE_ERR_DATA_LOW8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW8_SINGLE_ERR_DATA_LOW8_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW8 - Low 32 Bits Single Error Read Data On Ocram Bank8 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW8_SINGLE_ERR_DATA_LOW8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW8_SINGLE_ERR_DATA_LOW8_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW8_SINGLE_ERR_DATA_LOW8_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH8 - High 32 Bits Single Error Read Data On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH8_SINGLE_ERR_DATA_HIGH8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH8_SINGLE_ERR_DATA_HIGH8_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH8 - High 32 Bits Single Error Read Data On Ocram Bank8 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH8_SINGLE_ERR_DATA_HIGH8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH8_SINGLE_ERR_DATA_HIGH8_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH8_SINGLE_ERR_DATA_HIGH8_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW8 - Low Single Error Bit Position On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW8_SINGLE_ERR_POS_LOW8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW8_SINGLE_ERR_POS_LOW8_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW8 - Low Single Error Bit Position On Ocram Bank8 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW8_SINGLE_ERR_POS_LOW8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW8_SINGLE_ERR_POS_LOW8_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW8_SINGLE_ERR_POS_LOW8_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH8 - High Single Error Bit Position On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH8_SINGLE_ERR_POS_HIGH8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH8_SINGLE_ERR_POS_HIGH8_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH8 - High Single Error Bit Position On Ocram Bank8 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH8_SINGLE_ERR_POS_HIGH8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH8_SINGLE_ERR_POS_HIGH8_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH8_SINGLE_ERR_POS_HIGH8_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC9 - Single Error Address And ECC Code On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ECC9_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ECC9_SHIFT (0U)
/*! SINGLE_ERR_ECC9 - Single Error ECC Code On Ocram Bank9 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ECC9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ECC9_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ECC9_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ADDR9_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ADDR9_SHIFT (8U)
/*! SINGLE_ERR_ADDR9 - Single Error Address On Ocram Bank9 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ADDR9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ADDR9_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC9_SINGLE_ERR_ADDR9_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW9 - Low 32 Bits Single Error Read Data On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW9_SINGLE_ERR_DATA_LOW9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW9_SINGLE_ERR_DATA_LOW9_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW9 - Low 32 Bits Single Error Read Data On Ocram Bank9 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW9_SINGLE_ERR_DATA_LOW9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW9_SINGLE_ERR_DATA_LOW9_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW9_SINGLE_ERR_DATA_LOW9_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH9 - High 32 Bits Single Error Read Data On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH9_SINGLE_ERR_DATA_HIGH9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH9_SINGLE_ERR_DATA_HIGH9_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH9 - High 32 Bits Single Error Read Data On Ocram Bank9 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH9_SINGLE_ERR_DATA_HIGH9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH9_SINGLE_ERR_DATA_HIGH9_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH9_SINGLE_ERR_DATA_HIGH9_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW9 - Low Single Error Bit Position On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW9_SINGLE_ERR_POS_LOW9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW9_SINGLE_ERR_POS_LOW9_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW9 - Low Single Error Bit Position On Ocram Bank9 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW9_SINGLE_ERR_POS_LOW9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW9_SINGLE_ERR_POS_LOW9_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW9_SINGLE_ERR_POS_LOW9_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH9 - High Single Error Bit Position On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH9_SINGLE_ERR_POS_HIGH9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH9_SINGLE_ERR_POS_HIGH9_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH9 - High Single Error Bit Position On Ocram Bank9 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH9_SINGLE_ERR_POS_HIGH9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH9_SINGLE_ERR_POS_HIGH9_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH9_SINGLE_ERR_POS_HIGH9_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC10 - Single Error Address And ECC Code On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ECC10_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ECC10_SHIFT (0U)
/*! SINGLE_ERR_ECC10 - Single Error ECC Code On Ocram Bank2 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ECC10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ECC10_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ECC10_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ADDR10_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ADDR10_SHIFT (8U)
/*! SINGLE_ERR_ADDR10 - Single Error Address On Ocram Bank10 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ADDR10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ADDR10_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC10_SINGLE_ERR_ADDR10_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW10 - Low 32 Bits Single Error Read Data On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW10_SINGLE_ERR_DATA_LOW10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW10_SINGLE_ERR_DATA_LOW10_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW10 - Low 32 Bits Single Error Read Data On Ocram Bank10 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW10_SINGLE_ERR_DATA_LOW10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW10_SINGLE_ERR_DATA_LOW10_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW10_SINGLE_ERR_DATA_LOW10_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH10 - High 32 Bits Single Error Read Data On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH10_SINGLE_ERR_DATA_HIGH10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH10_SINGLE_ERR_DATA_HIGH10_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH10 - High 32 Bits Single Error Read Data On Ocram Bank10 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH10_SINGLE_ERR_DATA_HIGH10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH10_SINGLE_ERR_DATA_HIGH10_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH10_SINGLE_ERR_DATA_HIGH10_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW10 - Low Single Error Bit Position On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW10_SINGLE_ERR_POS_LOW10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW10_SINGLE_ERR_POS_LOW10_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW10 - Low Single Error Bit Position On Ocram Bank10 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW10_SINGLE_ERR_POS_LOW10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW10_SINGLE_ERR_POS_LOW10_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW10_SINGLE_ERR_POS_LOW10_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH10 - High Single Error Bit Position On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH10_SINGLE_ERR_POS_HIGH10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH10_SINGLE_ERR_POS_HIGH10_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH10 - High Single Error Bit Position On Ocram Bank10 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH10_SINGLE_ERR_POS_HIGH10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH10_SINGLE_ERR_POS_HIGH10_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH10_SINGLE_ERR_POS_HIGH10_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC11 - Single Error Address And ECC Code On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ECC11_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ECC11_SHIFT (0U)
/*! SINGLE_ERR_ECC11 - Single Error ECC Code On Ocram Bank11 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ECC11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ECC11_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ECC11_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ADDR11_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ADDR11_SHIFT (8U)
/*! SINGLE_ERR_ADDR11 - Single Error Address On Ocram Bank11 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ADDR11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ADDR11_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC11_SINGLE_ERR_ADDR11_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW11 - Low 32 Bits Single Error Read Data On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW11_SINGLE_ERR_DATA_LOW11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW11_SINGLE_ERR_DATA_LOW11_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW11 - Low 32 Bits Single Error Read Data On Ocram Bank11 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW11_SINGLE_ERR_DATA_LOW11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW11_SINGLE_ERR_DATA_LOW11_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW11_SINGLE_ERR_DATA_LOW11_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH11 - High 32 Bits Single Error Read Data On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH11_SINGLE_ERR_DATA_HIGH11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH11_SINGLE_ERR_DATA_HIGH11_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH11 - High 32 Bits Single Error Read Data On Ocram Bank11 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH11_SINGLE_ERR_DATA_HIGH11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH11_SINGLE_ERR_DATA_HIGH11_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH11_SINGLE_ERR_DATA_HIGH11_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW11 - Low Single Error Bit Position On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW11_SINGLE_ERR_POS_LOW11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW11_SINGLE_ERR_POS_LOW11_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW11 - Low Single Error Bit Position On Ocram Bank11 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW11_SINGLE_ERR_POS_LOW11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW11_SINGLE_ERR_POS_LOW11_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW11_SINGLE_ERR_POS_LOW11_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH11 - High Single Error Bit Position On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH11_SINGLE_ERR_POS_HIGH11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH11_SINGLE_ERR_POS_HIGH11_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH11 - High Single Error Bit Position On Ocram Bank11 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH11_SINGLE_ERR_POS_HIGH11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH11_SINGLE_ERR_POS_HIGH11_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH11_SINGLE_ERR_POS_HIGH11_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC12 - Single Error Address And ECC Code On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ECC12_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ECC12_SHIFT (0U)
/*! SINGLE_ERR_ECC12 - Single Error ECC Code On Ocram Bank12 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ECC12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ECC12_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ECC12_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ADDR12_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ADDR12_SHIFT (8U)
/*! SINGLE_ERR_ADDR12 - Single Error Address On Ocram Bank12 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ADDR12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ADDR12_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC12_SINGLE_ERR_ADDR12_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW12 - Low 32 Bits Single Error Read Data On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW12_SINGLE_ERR_DATA_LOW12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW12_SINGLE_ERR_DATA_LOW12_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW12 - Low 32 Bits Single Error Read Data On Ocram Bank12 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW12_SINGLE_ERR_DATA_LOW12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW12_SINGLE_ERR_DATA_LOW12_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW12_SINGLE_ERR_DATA_LOW12_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH12 - High 32 Bits Single Error Read Data On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH12_SINGLE_ERR_DATA_HIGH12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH12_SINGLE_ERR_DATA_HIGH12_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH12 - High 32 Bits Single Error Read Data On Ocram Bank12 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH12_SINGLE_ERR_DATA_HIGH12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH12_SINGLE_ERR_DATA_HIGH12_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH12_SINGLE_ERR_DATA_HIGH12_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW12 - Low Single Error Bit Position On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW12_SINGLE_ERR_POS_LOW12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW12_SINGLE_ERR_POS_LOW12_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW12 - Low Single Error Bit Position On Ocram Bank12 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW12_SINGLE_ERR_POS_LOW12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW12_SINGLE_ERR_POS_LOW12_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW12_SINGLE_ERR_POS_LOW12_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH12 - High Single Error Bit Position On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH12_SINGLE_ERR_POS_HIGH12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH12_SINGLE_ERR_POS_HIGH12_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH12 - High Single Error Bit Position On Ocram Bank12 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH12_SINGLE_ERR_POS_HIGH12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH12_SINGLE_ERR_POS_HIGH12_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH12_SINGLE_ERR_POS_HIGH12_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC13 - Single Error Address And ECC Code On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ECC13_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ECC13_SHIFT (0U)
/*! SINGLE_ERR_ECC13 - Single Error ECC Code On Ocram Bank13 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ECC13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ECC13_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ECC13_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ADDR13_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ADDR13_SHIFT (8U)
/*! SINGLE_ERR_ADDR13 - Single Error Address On Ocram Bank13 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ADDR13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ADDR13_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC13_SINGLE_ERR_ADDR13_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW13 - Low 32 Bits Single Error Read Data On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW13_SINGLE_ERR_DATA_LOW13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW13_SINGLE_ERR_DATA_LOW13_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW13 - Low 32 Bits Single Error Read Data On Ocram Bank13 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW13_SINGLE_ERR_DATA_LOW13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW13_SINGLE_ERR_DATA_LOW13_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW13_SINGLE_ERR_DATA_LOW13_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH13 - High 32 Bits Single Error Read Data On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH13_SINGLE_ERR_DATA_HIGH13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH13_SINGLE_ERR_DATA_HIGH13_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH13 - High 32 Bits Single Error Read Data On Ocram Bank13 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH13_SINGLE_ERR_DATA_HIGH13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH13_SINGLE_ERR_DATA_HIGH13_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH13_SINGLE_ERR_DATA_HIGH13_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW13 - Low Single Error Bit Position On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW13_SINGLE_ERR_POS_LOW13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW13_SINGLE_ERR_POS_LOW13_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW13 - Low Single Error Bit Position On Ocram Bank13 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW13_SINGLE_ERR_POS_LOW13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW13_SINGLE_ERR_POS_LOW13_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW13_SINGLE_ERR_POS_LOW13_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH13 - High Single Error Bit Position On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH13_SINGLE_ERR_POS_HIGH13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH13_SINGLE_ERR_POS_HIGH13_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH13 - High Single Error Bit Position On Ocram Bank13 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH13_SINGLE_ERR_POS_HIGH13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH13_SINGLE_ERR_POS_HIGH13_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH13_SINGLE_ERR_POS_HIGH13_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC14 - Single Error Address And ECC Code On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ECC14_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ECC14_SHIFT (0U)
/*! SINGLE_ERR_ECC14 - Single Error ECC Code On Ocram Bank14 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ECC14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ECC14_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ECC14_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ADDR14_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ADDR14_SHIFT (8U)
/*! SINGLE_ERR_ADDR14 - Single Error Address On Ocram Bank14 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ADDR14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ADDR14_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC14_SINGLE_ERR_ADDR14_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW14 - Low 32 Bits Single Error Read Data On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW14_SINGLE_ERR_DATA_LOW14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW14_SINGLE_ERR_DATA_LOW14_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW14 - Low 32 Bits Single Error Read Data On Ocram Bank14 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW14_SINGLE_ERR_DATA_LOW14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW14_SINGLE_ERR_DATA_LOW14_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW14_SINGLE_ERR_DATA_LOW14_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH14 - High 32 Bits Single Error Read Data On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH14_SINGLE_ERR_DATA_HIGH14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH14_SINGLE_ERR_DATA_HIGH14_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH14 - High 32 Bits Single Error Read Data On Ocram Bank14 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH14_SINGLE_ERR_DATA_HIGH14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH14_SINGLE_ERR_DATA_HIGH14_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH14_SINGLE_ERR_DATA_HIGH14_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW14 - Low Single Error Bit Position On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW14_SINGLE_ERR_POS_LOW14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW14_SINGLE_ERR_POS_LOW14_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW14 - Low Single Error Bit Position On Ocram Bank14 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW14_SINGLE_ERR_POS_LOW14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW14_SINGLE_ERR_POS_LOW14_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW14_SINGLE_ERR_POS_LOW14_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH14 - High Single Error Bit Position On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH14_SINGLE_ERR_POS_HIGH14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH14_SINGLE_ERR_POS_HIGH14_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH14 - High Single Error Bit Position On Ocram Bank14 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH14_SINGLE_ERR_POS_HIGH14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH14_SINGLE_ERR_POS_HIGH14_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH14_SINGLE_ERR_POS_HIGH14_MASK)
/*! @} */

/*! @name SINGLE_ERR_ADDR_ECC15 - Single Error Address And ECC Code On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ECC15_MASK (0xFFU)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ECC15_SHIFT (0U)
/*! SINGLE_ERR_ECC15 - Single Error ECC Code On Ocram Bank15 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ECC15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ECC15_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ECC15_MASK)

#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ADDR15_MASK (0x7FFFF00U)
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ADDR15_SHIFT (8U)
/*! SINGLE_ERR_ADDR15 - Single Error Address On Ocram Bank15 */
#define OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ADDR15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ADDR15_SHIFT)) & OCRAM_MECC_SINGLE_ERR_ADDR_ECC15_SINGLE_ERR_ADDR15_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_LOW15 - Low 32 Bits Single Error Read Data On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_LOW15_SINGLE_ERR_DATA_LOW15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW15_SINGLE_ERR_DATA_LOW15_SHIFT (0U)
/*! SINGLE_ERR_DATA_LOW15 - Low 32 Bits Single Error Read Data On Ocram Bank15 */
#define OCRAM_MECC_SINGLE_ERR_DATA_LOW15_SINGLE_ERR_DATA_LOW15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_LOW15_SINGLE_ERR_DATA_LOW15_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_LOW15_SINGLE_ERR_DATA_LOW15_MASK)
/*! @} */

/*! @name SINGLE_ERR_DATA_HIGH15 - High 32 Bits Single Error Read Data On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH15_SINGLE_ERR_DATA_HIGH15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH15_SINGLE_ERR_DATA_HIGH15_SHIFT (0U)
/*! SINGLE_ERR_DATA_HIGH15 - High 32 Bits Single Error Read Data On Ocram Bank15 */
#define OCRAM_MECC_SINGLE_ERR_DATA_HIGH15_SINGLE_ERR_DATA_HIGH15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_DATA_HIGH15_SINGLE_ERR_DATA_HIGH15_SHIFT)) & OCRAM_MECC_SINGLE_ERR_DATA_HIGH15_SINGLE_ERR_DATA_HIGH15_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_LOW15 - Low Single Error Bit Position On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_LOW15_SINGLE_ERR_POS_LOW15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_LOW15_SINGLE_ERR_POS_LOW15_SHIFT (0U)
/*! SINGLE_ERR_POS_LOW15 - Low Single Error Bit Position On Ocram Bank15 */
#define OCRAM_MECC_SINGLE_ERR_POS_LOW15_SINGLE_ERR_POS_LOW15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_LOW15_SINGLE_ERR_POS_LOW15_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_LOW15_SINGLE_ERR_POS_LOW15_MASK)
/*! @} */

/*! @name SINGLE_ERR_POS_HIGH15 - High Single Error Bit Position On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_SINGLE_ERR_POS_HIGH15_SINGLE_ERR_POS_HIGH15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH15_SINGLE_ERR_POS_HIGH15_SHIFT (0U)
/*! SINGLE_ERR_POS_HIGH15 - High Single Error Bit Position On Ocram Bank15 */
#define OCRAM_MECC_SINGLE_ERR_POS_HIGH15_SINGLE_ERR_POS_HIGH15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_SINGLE_ERR_POS_HIGH15_SINGLE_ERR_POS_HIGH15_SHIFT)) & OCRAM_MECC_SINGLE_ERR_POS_HIGH15_SINGLE_ERR_POS_HIGH15_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC0 - Multiple Error Address And ECC Code On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ECC0_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ECC0_SHIFT (0U)
/*! MULTI_ERR_ECC0 - Multiple Error ECC Code On Ocram Bank0 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ECC0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ECC0_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ECC0_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ADDR0_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ADDR0_SHIFT (8U)
/*! MULTI_ERR_ADDR0 - Multiple Error Address On Ocram Bank0 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ADDR0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ADDR0_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC0_MULTI_ERR_ADDR0_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW0 - Low 32 Bits Multiple Error Read Data On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW0_MULTI_ERR_DATA_LOW0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW0_MULTI_ERR_DATA_LOW0_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW0 - Low 32 Bits Multiple Error Read Data On Ocram Bank0 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW0_MULTI_ERR_DATA_LOW0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW0_MULTI_ERR_DATA_LOW0_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW0_MULTI_ERR_DATA_LOW0_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH0 - High 32 Bits Multiple Error Read Data On Ocram Bank0 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH0_MULTI_ERR_DATA_HIGH0_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH0_MULTI_ERR_DATA_HIGH0_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH0 - High 32 Bits Multiple Error Read Data On Ocram Bank0 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH0_MULTI_ERR_DATA_HIGH0(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH0_MULTI_ERR_DATA_HIGH0_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH0_MULTI_ERR_DATA_HIGH0_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC1 - Multiple Error Address And ECC Code On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ECC1_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ECC1_SHIFT (0U)
/*! MULTI_ERR_ECC1 - Multiple Error ECC Code On Ocram Bank1 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ECC1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ECC1_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ECC1_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ADDR1_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ADDR1_SHIFT (8U)
/*! MULTI_ERR_ADDR1 - Multiple Error Address On Ocram Bank1 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ADDR1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ADDR1_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC1_MULTI_ERR_ADDR1_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW1 - Low 32 Bits Multiple Error Read Data On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW1_MULTI_ERR_DATA_LOW1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW1_MULTI_ERR_DATA_LOW1_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW1 - Low 32 Bits Multiple Error Read Data On Ocram Bank1 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW1_MULTI_ERR_DATA_LOW1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW1_MULTI_ERR_DATA_LOW1_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW1_MULTI_ERR_DATA_LOW1_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH1 - High 32 Bits Multiple Error Read Data On Ocram Bank1 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH1_MULTI_ERR_DATA_HIGH1_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH1_MULTI_ERR_DATA_HIGH1_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH1 - High 32 Bits Multiple Error Read Data On Ocram Bank1 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH1_MULTI_ERR_DATA_HIGH1(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH1_MULTI_ERR_DATA_HIGH1_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH1_MULTI_ERR_DATA_HIGH1_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC2 - Multiple Error Address And ECC Code On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ECC2_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ECC2_SHIFT (0U)
/*! MULTI_ERR_ECC2 - Multiple Error ECC Code On Ocram Bank2 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ECC2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ECC2_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ECC2_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ADDR2_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ADDR2_SHIFT (8U)
/*! MULTI_ERR_ADDR2 - Multiple Error Address On Ocram Bank2 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ADDR2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ADDR2_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC2_MULTI_ERR_ADDR2_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW2 - Low 32 Bits Multiple Error Read Data On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW2_MULTI_ERR_DATA_LOW2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW2_MULTI_ERR_DATA_LOW2_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW2 - Low 32 Bits Multiple Error Read Data On Ocram Bank2 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW2_MULTI_ERR_DATA_LOW2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW2_MULTI_ERR_DATA_LOW2_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW2_MULTI_ERR_DATA_LOW2_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH2 - High 32 Bits Multiple Error Read Data On Ocram Bank2 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH2_MULTI_ERR_DATA_HIGH2_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH2_MULTI_ERR_DATA_HIGH2_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH2 - High 32 Bits Multiple Error Read Data On Ocram Bank2 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH2_MULTI_ERR_DATA_HIGH2(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH2_MULTI_ERR_DATA_HIGH2_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH2_MULTI_ERR_DATA_HIGH2_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC3 - Multiple Error Address And ECC Code On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ECC3_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ECC3_SHIFT (0U)
/*! MULTI_ERR_ECC3 - Multiple Error ECC Code On Ocram Bank3 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ECC3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ECC3_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ECC3_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ADDR3_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ADDR3_SHIFT (8U)
/*! MULTI_ERR_ADDR3 - Multiple Error Address On Ocram Bank3 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ADDR3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ADDR3_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC3_MULTI_ERR_ADDR3_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW3 - Low 32 Bits Multiple Error Read Data On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW3_MULTI_ERR_DATA_LOW3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW3_MULTI_ERR_DATA_LOW3_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW3 - Low 32 Bits Multiple Error Read Data On Ocram Bank3 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW3_MULTI_ERR_DATA_LOW3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW3_MULTI_ERR_DATA_LOW3_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW3_MULTI_ERR_DATA_LOW3_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH3 - High 32 Bits Multiple Error Read Data On Ocram Bank3 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH3_MULTI_ERR_DATA_HIGH3_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH3_MULTI_ERR_DATA_HIGH3_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH3 - High 32 Bits Multiple Error Read Data On Ocram Bank3 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH3_MULTI_ERR_DATA_HIGH3(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH3_MULTI_ERR_DATA_HIGH3_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH3_MULTI_ERR_DATA_HIGH3_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC4 - Multiple Error Address And ECC Code On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ECC4_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ECC4_SHIFT (0U)
/*! MULTI_ERR_ECC4 - Multiple Error ECC Code On Ocram Bank4 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ECC4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ECC4_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ECC4_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ADDR4_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ADDR4_SHIFT (8U)
/*! MULTI_ERR_ADDR4 - Multiple Error Address On Ocram Bank4 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ADDR4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ADDR4_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC4_MULTI_ERR_ADDR4_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW4 - Low 32 Bits Multiple Error Read Data On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW4_MULTI_ERR_DATA_LOW4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW4_MULTI_ERR_DATA_LOW4_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW4 - Low 32 Bits Multiple Error Read Data On Ocram Bank4 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW4_MULTI_ERR_DATA_LOW4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW4_MULTI_ERR_DATA_LOW4_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW4_MULTI_ERR_DATA_LOW4_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH4 - High 32 Bits Multiple Error Read Data On Ocram Bank4 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH4_MULTI_ERR_DATA_HIGH4_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH4_MULTI_ERR_DATA_HIGH4_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH4 - High 32 Bits Multiple Error Read Data On Ocram Bank4 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH4_MULTI_ERR_DATA_HIGH4(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH4_MULTI_ERR_DATA_HIGH4_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH4_MULTI_ERR_DATA_HIGH4_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC5 - Multiple Error Address And ECC Code On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ECC5_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ECC5_SHIFT (0U)
/*! MULTI_ERR_ECC5 - Multiple Error ECC Code On Ocram Bank5 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ECC5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ECC5_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ECC5_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ADDR5_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ADDR5_SHIFT (8U)
/*! MULTI_ERR_ADDR5 - Multiple Error Address On Ocram Bank5 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ADDR5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ADDR5_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC5_MULTI_ERR_ADDR5_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW5 - Low 32 Bits Multiple Error Read Data On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW5_MULTI_ERR_DATA_LOW5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW5_MULTI_ERR_DATA_LOW5_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW5 - Low 32 Bits Multiple Error Read Data On Ocram Bank5 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW5_MULTI_ERR_DATA_LOW5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW5_MULTI_ERR_DATA_LOW5_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW5_MULTI_ERR_DATA_LOW5_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH5 - High 32 Bits Multiple Error Read Data On Ocram Bank5 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH5_MULTI_ERR_DATA_HIGH5_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH5_MULTI_ERR_DATA_HIGH5_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH5 - High 32 Bits Multiple Error Read Data On Ocram Bank5 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH5_MULTI_ERR_DATA_HIGH5(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH5_MULTI_ERR_DATA_HIGH5_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH5_MULTI_ERR_DATA_HIGH5_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC6 - Multiple Error Address And ECC Code On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ECC6_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ECC6_SHIFT (0U)
/*! MULTI_ERR_ECC6 - Multiple Error ECC Code On Ocram Bank6 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ECC6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ECC6_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ECC6_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ADDR6_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ADDR6_SHIFT (8U)
/*! MULTI_ERR_ADDR6 - Multiple Error Address On Ocram Bank6 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ADDR6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ADDR6_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC6_MULTI_ERR_ADDR6_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW6 - Low 32 Bits Multiple Error Read Data On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW6_MULTI_ERR_DATA_LOW6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW6_MULTI_ERR_DATA_LOW6_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW6 - Low 32 Bits Multiple Error Read Data On Ocram Bank6 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW6_MULTI_ERR_DATA_LOW6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW6_MULTI_ERR_DATA_LOW6_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW6_MULTI_ERR_DATA_LOW6_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH6 - High 32 Bits Multiple Error Read Data On Ocram Bank6 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH6_MULTI_ERR_DATA_HIGH6_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH6_MULTI_ERR_DATA_HIGH6_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH6 - High 32 Bits Multiple Error Read Data On Ocram Bank6 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH6_MULTI_ERR_DATA_HIGH6(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH6_MULTI_ERR_DATA_HIGH6_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH6_MULTI_ERR_DATA_HIGH6_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC7 - Multiple Error Address And ECC Code On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ECC7_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ECC7_SHIFT (0U)
/*! MULTI_ERR_ECC7 - Multiple Error ECC Code On Ocram Bank7 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ECC7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ECC7_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ECC7_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ADDR7_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ADDR7_SHIFT (8U)
/*! MULTI_ERR_ADDR7 - Multiple Error Address On Ocram Bank7 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ADDR7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ADDR7_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC7_MULTI_ERR_ADDR7_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW7 - Low 32 Bits Multiple Error Read Data On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW7_MULTI_ERR_DATA_LOW7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW7_MULTI_ERR_DATA_LOW7_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW7 - Low 32 Bits Multiple Error Read Data On Ocram Bank7 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW7_MULTI_ERR_DATA_LOW7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW7_MULTI_ERR_DATA_LOW7_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW7_MULTI_ERR_DATA_LOW7_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH7 - High 32 Bits Multiple Error Read Data On Ocram Bank7 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH7_MULTI_ERR_DATA_HIGH7_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH7_MULTI_ERR_DATA_HIGH7_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH7 - High 32 Bits Multiple Error Read Data On Ocram Bank7 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH7_MULTI_ERR_DATA_HIGH7(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH7_MULTI_ERR_DATA_HIGH7_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH7_MULTI_ERR_DATA_HIGH7_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC8 - Multiple Error Address And ECC Code On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ECC8_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ECC8_SHIFT (0U)
/*! MULTI_ERR_ECC8 - Multiple Error ECC Code On Ocram Bank8 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ECC8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ECC8_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ECC8_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ADDR8_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ADDR8_SHIFT (8U)
/*! MULTI_ERR_ADDR8 - Multiple Error Address On Ocram Bank8 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ADDR8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ADDR8_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC8_MULTI_ERR_ADDR8_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW8 - Low 32 Bits Multiple Error Read Data On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW8_MULTI_ERR_DATA_LOW8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW8_MULTI_ERR_DATA_LOW8_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW8 - Low 32 Bits Multiple Error Read Data On Ocram Bank8 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW8_MULTI_ERR_DATA_LOW8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW8_MULTI_ERR_DATA_LOW8_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW8_MULTI_ERR_DATA_LOW8_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH8 - High 32 Bits Multiple Error Read Data On Ocram Bank8 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH8_MULTI_ERR_DATA_HIGH8_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH8_MULTI_ERR_DATA_HIGH8_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH8 - High 32 Bits Multiple Error Read Data On Ocram Bank8 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH8_MULTI_ERR_DATA_HIGH8(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH8_MULTI_ERR_DATA_HIGH8_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH8_MULTI_ERR_DATA_HIGH8_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC9 - Multiple Error Address And ECC Code On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ECC9_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ECC9_SHIFT (0U)
/*! MULTI_ERR_ECC9 - Multiple Error ECC Code On Ocram Bank9 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ECC9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ECC9_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ECC9_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ADDR9_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ADDR9_SHIFT (8U)
/*! MULTI_ERR_ADDR9 - Multiple Error Address On Ocram Bank9 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ADDR9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ADDR9_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC9_MULTI_ERR_ADDR9_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW9 - Low 32 Bits Multiple Error Read Data On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW9_MULTI_ERR_DATA_LOW9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW9_MULTI_ERR_DATA_LOW9_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW9 - Low 32 Bits Multiple Error Read Data On Ocram Bank9 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW9_MULTI_ERR_DATA_LOW9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW9_MULTI_ERR_DATA_LOW9_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW9_MULTI_ERR_DATA_LOW9_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH9 - High 32 Bits Multiple Error Read Data On Ocram Bank9 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH9_MULTI_ERR_DATA_HIGH9_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH9_MULTI_ERR_DATA_HIGH9_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH9 - High 32 Bits Multiple Error Read Data On Ocram Bank9 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH9_MULTI_ERR_DATA_HIGH9(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH9_MULTI_ERR_DATA_HIGH9_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH9_MULTI_ERR_DATA_HIGH9_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC10 - Multiple Error Address And ECC Code On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ECC10_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ECC10_SHIFT (0U)
/*! MULTI_ERR_ECC10 - Multiple Error ECC Code On Ocram Bank10 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ECC10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ECC10_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ECC10_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ADDR10_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ADDR10_SHIFT (8U)
/*! MULTI_ERR_ADDR10 - Multiple Error Address On Ocram Bank10 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ADDR10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ADDR10_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC10_MULTI_ERR_ADDR10_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW10 - Low 32 Bits Multiple Error Read Data On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW10_MULTI_ERR_DATA_LOW10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW10_MULTI_ERR_DATA_LOW10_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW10 - Low 32 Bits Multiple Error Read Data On Ocram Bank10 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW10_MULTI_ERR_DATA_LOW10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW10_MULTI_ERR_DATA_LOW10_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW10_MULTI_ERR_DATA_LOW10_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH10 - High 32 Bits Multiple Error Read Data On Ocram Bank10 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH10_MULTI_ERR_DATA_HIGH10_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH10_MULTI_ERR_DATA_HIGH10_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH10 - High 32 Bits Multiple Error Read Data On Ocram Bank10 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH10_MULTI_ERR_DATA_HIGH10(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH10_MULTI_ERR_DATA_HIGH10_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH10_MULTI_ERR_DATA_HIGH10_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC11 - Multiple Error Address And ECC Code On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ECC11_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ECC11_SHIFT (0U)
/*! MULTI_ERR_ECC11 - Multiple Error ECC Code On Ocram Bank11 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ECC11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ECC11_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ECC11_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ADDR11_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ADDR11_SHIFT (8U)
/*! MULTI_ERR_ADDR11 - Multiple Error Address On Ocram Bank11 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ADDR11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ADDR11_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC11_MULTI_ERR_ADDR11_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW11 - Low 32 Bits Multiple Error Read Data On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW11_MULTI_ERR_DATA_LOW11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW11_MULTI_ERR_DATA_LOW11_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW11 - Low 32 Bits Multiple Error Read Data On Ocram Bank11 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW11_MULTI_ERR_DATA_LOW11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW11_MULTI_ERR_DATA_LOW11_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW11_MULTI_ERR_DATA_LOW11_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH11 - High 32 Bits Multiple Error Read Data On Ocram Bank11 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH11_MULTI_ERR_DATA_HIGH11_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH11_MULTI_ERR_DATA_HIGH11_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH11 - High 32 Bits Multiple Error Read Data On Ocram Bank11 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH11_MULTI_ERR_DATA_HIGH11(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH11_MULTI_ERR_DATA_HIGH11_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH11_MULTI_ERR_DATA_HIGH11_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC12 - Multiple Error Address And ECC Code On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ECC12_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ECC12_SHIFT (0U)
/*! MULTI_ERR_ECC12 - Multiple Error ECC Code On Ocram Bank12 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ECC12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ECC12_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ECC12_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ADDR12_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ADDR12_SHIFT (8U)
/*! MULTI_ERR_ADDR12 - Multiple Error Address On Ocram Bank12 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ADDR12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ADDR12_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC12_MULTI_ERR_ADDR12_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW12 - Low 32 Bits Multiple Error Read Data On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW12_MULTI_ERR_DATA_LOW12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW12_MULTI_ERR_DATA_LOW12_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW12 - Low 32 Bits Multiple Error Read Data On Ocram Bank12 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW12_MULTI_ERR_DATA_LOW12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW12_MULTI_ERR_DATA_LOW12_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW12_MULTI_ERR_DATA_LOW12_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH12 - High 32 Bits Multiple Error Read Data On Ocram Bank12 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH12_MULTI_ERR_DATA_HIGH12_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH12_MULTI_ERR_DATA_HIGH12_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH12 - High 32 Bits Multiple Error Read Data On Ocram Bank12 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH12_MULTI_ERR_DATA_HIGH12(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH12_MULTI_ERR_DATA_HIGH12_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH12_MULTI_ERR_DATA_HIGH12_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC13 - Multiple Error Address And ECC Code On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ECC13_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ECC13_SHIFT (0U)
/*! MULTI_ERR_ECC13 - Multiple Error ECC Code On Ocram Bank13 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ECC13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ECC13_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ECC13_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ADDR13_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ADDR13_SHIFT (8U)
/*! MULTI_ERR_ADDR13 - Multiple Error Address On Ocram Bank13 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ADDR13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ADDR13_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC13_MULTI_ERR_ADDR13_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW13 - Low 32 Bits Multiple Error Read Data On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW13_MULTI_ERR_DATA_LOW13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW13_MULTI_ERR_DATA_LOW13_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW13 - Low 32 Bits Multiple Error Read Data On Ocram Bank13 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW13_MULTI_ERR_DATA_LOW13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW13_MULTI_ERR_DATA_LOW13_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW13_MULTI_ERR_DATA_LOW13_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH13 - High 32 Bits Multiple Error Read Data On Ocram Bank13 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH13_MULTI_ERR_DATA_HIGH13_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH13_MULTI_ERR_DATA_HIGH13_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH13 - High 32 Bits Multiple Error Read Data On Ocram Bank13 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH13_MULTI_ERR_DATA_HIGH13(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH13_MULTI_ERR_DATA_HIGH13_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH13_MULTI_ERR_DATA_HIGH13_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC14 - Multiple Error Address And ECC Code On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ECC14_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ECC14_SHIFT (0U)
/*! MULTI_ERR_ECC14 - Multiple Error ECC Code On Ocram Bank14 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ECC14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ECC14_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ECC14_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ADDR14_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ADDR14_SHIFT (8U)
/*! MULTI_ERR_ADDR14 - Multiple Error Address On Ocram Bank14 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ADDR14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ADDR14_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC14_MULTI_ERR_ADDR14_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW14 - Low 32 Bits Multiple Error Read Data On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW14_MULTI_ERR_DATA_LOW14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW14_MULTI_ERR_DATA_LOW14_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW14 - Low 32 Bits Multiple Error Read Data On Ocram Bank14 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW14_MULTI_ERR_DATA_LOW14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW14_MULTI_ERR_DATA_LOW14_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW14_MULTI_ERR_DATA_LOW14_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH14 - High 32 Bits Multiple Error Read Data On Ocram Bank14 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH14_MULTI_ERR_DATA_HIGH14_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH14_MULTI_ERR_DATA_HIGH14_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH14 - High 32 Bits Multiple Error Read Data On Ocram Bank14 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH14_MULTI_ERR_DATA_HIGH14(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH14_MULTI_ERR_DATA_HIGH14_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH14_MULTI_ERR_DATA_HIGH14_MASK)
/*! @} */

/*! @name MULTI_ERR_ADDR_ECC15 - Multiple Error Address And ECC Code On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ECC15_MASK (0xFFU)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ECC15_SHIFT (0U)
/*! MULTI_ERR_ECC15 - Multiple Error ECC Code On Ocram Bank15 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ECC15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ECC15_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ECC15_MASK)

#define OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ADDR15_MASK (0x7FFFF00U)
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ADDR15_SHIFT (8U)
/*! MULTI_ERR_ADDR15 - Multiple Error Address On Ocram Bank15 */
#define OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ADDR15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ADDR15_SHIFT)) & OCRAM_MECC_MULTI_ERR_ADDR_ECC15_MULTI_ERR_ADDR15_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_LOW15 - Low 32 Bits Multiple Error Read Data On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_LOW15_MULTI_ERR_DATA_LOW15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_LOW15_MULTI_ERR_DATA_LOW15_SHIFT (0U)
/*! MULTI_ERR_DATA_LOW15 - Low 32 Bits Multiple Error Read Data On Ocram Bank15 */
#define OCRAM_MECC_MULTI_ERR_DATA_LOW15_MULTI_ERR_DATA_LOW15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_LOW15_MULTI_ERR_DATA_LOW15_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_LOW15_MULTI_ERR_DATA_LOW15_MASK)
/*! @} */

/*! @name MULTI_ERR_DATA_HIGH15 - High 32 Bits Multiple Error Read Data On Ocram Bank15 */
/*! @{ */

#define OCRAM_MECC_MULTI_ERR_DATA_HIGH15_MULTI_ERR_DATA_HIGH15_MASK (0xFFFFFFFFU)
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH15_MULTI_ERR_DATA_HIGH15_SHIFT (0U)
/*! MULTI_ERR_DATA_HIGH15 - High 32 Bits Multiple Error Read Data On Ocram Bank15 */
#define OCRAM_MECC_MULTI_ERR_DATA_HIGH15_MULTI_ERR_DATA_HIGH15(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MULTI_ERR_DATA_HIGH15_MULTI_ERR_DATA_HIGH15_SHIFT)) & OCRAM_MECC_MULTI_ERR_DATA_HIGH15_MULTI_ERR_DATA_HIGH15_MASK)
/*! @} */

/*! @name PIPE_ECC_EN - Ocram Pipeline And ECC Enable */
/*! @{ */

#define OCRAM_MECC_PIPE_ECC_EN_READ_DATA_WAIT_EN_MASK (0x1U)
#define OCRAM_MECC_PIPE_ECC_EN_READ_DATA_WAIT_EN_SHIFT (0U)
/*! READ_DATA_WAIT_EN - Read Data Wait Enable
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define OCRAM_MECC_PIPE_ECC_EN_READ_DATA_WAIT_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PIPE_ECC_EN_READ_DATA_WAIT_EN_SHIFT)) & OCRAM_MECC_PIPE_ECC_EN_READ_DATA_WAIT_EN_MASK)

#define OCRAM_MECC_PIPE_ECC_EN_READ_ADDR_PIPE_EN_MASK (0x2U)
#define OCRAM_MECC_PIPE_ECC_EN_READ_ADDR_PIPE_EN_SHIFT (1U)
/*! READ_ADDR_PIPE_EN - Read Address Pipeline Enable
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define OCRAM_MECC_PIPE_ECC_EN_READ_ADDR_PIPE_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PIPE_ECC_EN_READ_ADDR_PIPE_EN_SHIFT)) & OCRAM_MECC_PIPE_ECC_EN_READ_ADDR_PIPE_EN_MASK)

#define OCRAM_MECC_PIPE_ECC_EN_WRITE_DATA_PIPE_EN_MASK (0x4U)
#define OCRAM_MECC_PIPE_ECC_EN_WRITE_DATA_PIPE_EN_SHIFT (2U)
/*! WRITE_DATA_PIPE_EN - Write Data Pipeline Enable
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define OCRAM_MECC_PIPE_ECC_EN_WRITE_DATA_PIPE_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PIPE_ECC_EN_WRITE_DATA_PIPE_EN_SHIFT)) & OCRAM_MECC_PIPE_ECC_EN_WRITE_DATA_PIPE_EN_MASK)

#define OCRAM_MECC_PIPE_ECC_EN_WRITE_ADDR_PIPE_EN_MASK (0x8U)
#define OCRAM_MECC_PIPE_ECC_EN_WRITE_ADDR_PIPE_EN_SHIFT (3U)
/*! WRITE_ADDR_PIPE_EN - Write Address Pipeline Enable
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define OCRAM_MECC_PIPE_ECC_EN_WRITE_ADDR_PIPE_EN(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PIPE_ECC_EN_WRITE_ADDR_PIPE_EN_SHIFT)) & OCRAM_MECC_PIPE_ECC_EN_WRITE_ADDR_PIPE_EN_MASK)

#define OCRAM_MECC_PIPE_ECC_EN_ECC_EN_MASK       (0x10U)
#define OCRAM_MECC_PIPE_ECC_EN_ECC_EN_SHIFT      (4U)
/*! ECC_EN - ECC Function Enable
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define OCRAM_MECC_PIPE_ECC_EN_ECC_EN(x)         (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PIPE_ECC_EN_ECC_EN_SHIFT)) & OCRAM_MECC_PIPE_ECC_EN_ECC_EN_MASK)
/*! @} */

/*! @name PENDING_STAT - Pending Status */
/*! @{ */

#define OCRAM_MECC_PENDING_STAT_READ_DATA_WAIT_PENDING_MASK (0x1U)
#define OCRAM_MECC_PENDING_STAT_READ_DATA_WAIT_PENDING_SHIFT (0U)
/*! READ_DATA_WAIT_PENDING - Read Data Wait Pending */
#define OCRAM_MECC_PENDING_STAT_READ_DATA_WAIT_PENDING(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PENDING_STAT_READ_DATA_WAIT_PENDING_SHIFT)) & OCRAM_MECC_PENDING_STAT_READ_DATA_WAIT_PENDING_MASK)

#define OCRAM_MECC_PENDING_STAT_READ_ADDR_PIPE_PENDING_MASK (0x2U)
#define OCRAM_MECC_PENDING_STAT_READ_ADDR_PIPE_PENDING_SHIFT (1U)
/*! READ_ADDR_PIPE_PENDING - Read Address Pipeline Pending */
#define OCRAM_MECC_PENDING_STAT_READ_ADDR_PIPE_PENDING(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PENDING_STAT_READ_ADDR_PIPE_PENDING_SHIFT)) & OCRAM_MECC_PENDING_STAT_READ_ADDR_PIPE_PENDING_MASK)

#define OCRAM_MECC_PENDING_STAT_WRITE_DATA_PIPE_PENDING_MASK (0x4U)
#define OCRAM_MECC_PENDING_STAT_WRITE_DATA_PIPE_PENDING_SHIFT (2U)
/*! WRITE_DATA_PIPE_PENDING - Write Data Pipeline Pending */
#define OCRAM_MECC_PENDING_STAT_WRITE_DATA_PIPE_PENDING(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PENDING_STAT_WRITE_DATA_PIPE_PENDING_SHIFT)) & OCRAM_MECC_PENDING_STAT_WRITE_DATA_PIPE_PENDING_MASK)

#define OCRAM_MECC_PENDING_STAT_WRITE_ADDR_PIPE_PENDING_MASK (0x8U)
#define OCRAM_MECC_PENDING_STAT_WRITE_ADDR_PIPE_PENDING_SHIFT (3U)
/*! WRITE_ADDR_PIPE_PENDING - Write Address Pipeline Pending */
#define OCRAM_MECC_PENDING_STAT_WRITE_ADDR_PIPE_PENDING(x) (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_PENDING_STAT_WRITE_ADDR_PIPE_PENDING_SHIFT)) & OCRAM_MECC_PENDING_STAT_WRITE_ADDR_PIPE_PENDING_MASK)
/*! @} */

/*! @name MEM_INIT - Memory initialization */
/*! @{ */

#define OCRAM_MECC_MEM_INIT_MEM_INIT_ENABLE_MASK (0x1U)
#define OCRAM_MECC_MEM_INIT_MEM_INIT_ENABLE_SHIFT (0U)
/*! MEM_INIT_ENABLE - Memory initialization enable.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define OCRAM_MECC_MEM_INIT_MEM_INIT_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MEM_INIT_MEM_INIT_ENABLE_SHIFT)) & OCRAM_MECC_MEM_INIT_MEM_INIT_ENABLE_MASK)

#define OCRAM_MECC_MEM_INIT_MEM_INIT_DONE_MASK   (0x2U)
#define OCRAM_MECC_MEM_INIT_MEM_INIT_DONE_SHIFT  (1U)
/*! MEM_INIT_DONE - Memory initialization done.
 *  0b0..Memory initialization is not done.
 *  0b1..Memory initialization is done.
 */
#define OCRAM_MECC_MEM_INIT_MEM_INIT_DONE(x)     (((uint32_t)(((uint32_t)(x)) << OCRAM_MECC_MEM_INIT_MEM_INIT_DONE_SHIFT)) & OCRAM_MECC_MEM_INIT_MEM_INIT_DONE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCRAM_MECC_Register_Masks */


/*!
 * @}
 */ /* end of group OCRAM_MECC_Peripheral_Access_Layer */


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


#endif  /* PERI_OCRAM_MECC_H_ */
