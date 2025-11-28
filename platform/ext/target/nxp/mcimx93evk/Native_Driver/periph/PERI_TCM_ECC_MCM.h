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
**         CMSIS Peripheral Access Layer for TCM_ECC_MCM
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
 * @file PERI_TCM_ECC_MCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TCM_ECC_MCM
 *
 * CMSIS Peripheral Access Layer for TCM_ECC_MCM
 */

#if !defined(PERI_TCM_ECC_MCM_H_)
#define PERI_TCM_ECC_MCM_H_                      /**< Symbol preventing repeated inclusion */

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
   -- TCM_ECC_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TCM_ECC_MCM_Peripheral_Access_Layer TCM_ECC_MCM Peripheral Access Layer
 * @{
 */

/** TCM_ECC_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t TCMECCR;                           /**< TCM ECC Control Register, offset: 0x4 */
       uint8_t RESERVED_1[24];
  __IO uint32_t INT_STATUS;                        /**< Interrupt Status Register, offset: 0x20 */
  __IO uint32_t INT_STAT_EN;                       /**< Interrupt Status Enable Register, offset: 0x24 */
  __IO uint32_t INT_SIG_EN;                        /**< Interrupt Enable Register, offset: 0x28 */
       uint8_t RESERVED_2[48];
  __I  uint32_t CODE_TCM_ECC_SINGLE_ERROR_INFO;    /**< CODE_TCM single-bit ECC Error Information Register, offset: 0x5C */
  __I  uint32_t CODE_TCM_ECC_SINGLE_ERROR_ADDR;    /**< CODE_TCM single-bit ECC Error Address Register, offset: 0x60 */
       uint8_t RESERVED_3[4];
  __I  uint32_t CODE_TCM_ECC_MULTI_ERROR_INFO;     /**< CODE_TCM multi-bit ECC Error Information Register, offset: 0x68 */
  __I  uint32_t CODE_TCM_ECC_MULTI_ERROR_ADDR;     /**< CODE_TCM multi-bit ECC Error Address Register, offset: 0x6C */
       uint8_t RESERVED_4[4];
  __I  uint32_t SYS_TCM_ECC_SINGLE_ERROR_INFO;     /**< SYS_TCM single-bit ECC Error Information Register, offset: 0x74 */
  __I  uint32_t SYS_TCM_ECC_SINGLE_ERROR_ADDR;     /**< SYS_TCM single-bit ECC Error Address Register, offset: 0x78 */
       uint8_t RESERVED_5[4];
  __I  uint32_t SYS_TCM_ECC_MULTI_ERROR_INFO;      /**< SYS_TCM multi-bit ECC Error Information Register, offset: 0x80 */
  __I  uint32_t SYS_TCM_ECC_MULTI_ERROR_ADDR;      /**< SYS_TCM multi-bit ECC Error Address Register, offset: 0x84 */
       uint8_t RESERVED_6[12];
  __IO uint32_t CODE_TCM_ECC_ERROR_INJEC;          /**< CODE_TCM ECC Error Injection Register, offset: 0x94 */
  __IO uint32_t SYS_TCM_ECC_ERROR_INJEC;           /**< SYS_TCM ECC Error Injection Register, offset: 0x98 */
} TCM_ECC_MCM_Type;

/* ----------------------------------------------------------------------------
   -- TCM_ECC_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TCM_ECC_MCM_Register_Masks TCM_ECC_MCM Register Masks
 * @{
 */

/*! @name TCMECCR - TCM ECC Control Register */
/*! @{ */

#define TCM_ECC_MCM_TCMECCR_WECC_DIS_MASK        (0x1U)
#define TCM_ECC_MCM_TCMECCR_WECC_DIS_SHIFT       (0U)
/*! WECC_DIS - Disable TCM ECC Write Generation
 *  0b0..Enable ECC generation on TCM write data
 *  0b1..Disable ECC generation on TCM write data
 */
#define TCM_ECC_MCM_TCMECCR_WECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_TCMECCR_WECC_DIS_SHIFT)) & TCM_ECC_MCM_TCMECCR_WECC_DIS_MASK)

#define TCM_ECC_MCM_TCMECCR_RECC_DIS_MASK        (0x2U)
#define TCM_ECC_MCM_TCMECCR_RECC_DIS_SHIFT       (1U)
/*! RECC_DIS - Disable TCM ECC Read Check
 *  0b0..Enable ECC check on TCM read data
 *  0b1..Disable ECC check on TCM read data
 */
#define TCM_ECC_MCM_TCMECCR_RECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_TCMECCR_RECC_DIS_SHIFT)) & TCM_ECC_MCM_TCMECCR_RECC_DIS_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status Register */
/*! @{ */

#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_MASK (0x400U)
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_SHIFT (10U)
/*! CODE_TCM_ECC_ERRM_INT - CODE_TCM access multi-bit ECC Error Interrupt Status
 *  0b0..CODE_TCM multi-bit ECC error does not happen
 *  0b1..CODE_TCM multi-bit ECC error happens.
 */
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_MASK)

#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_MASK (0x800U)
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_SHIFT (11U)
/*! CODE_TCM_ECC_ERRS_INT - CODE_TCM access single-bit ECC Error Interrupt Status
 *  0b0..CODE_TCM single-bit ECC error does not happen
 *  0b1..CODE_TCM single-bit ECC error happens.
 */
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_MASK)

#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_MASK (0x1000U)
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_SHIFT (12U)
/*! SYS_TCM_ECC_ERRM_INT - SYS_TCM access multi-bit ECC Error Interrupt Status
 *  0b0..SYS_TCM multi-bit ECC error does not happen
 *  0b1..SYS_TCM multi-bit ECC error happens.
 */
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_MASK)

#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_MASK (0x2000U)
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_SHIFT (13U)
/*! SYS_TCM_ECC_ERRS_INT - SYS_TCM access single-bit ECC Error Interrupt Status
 *  0b0..SYS_TCM single-bit ECC error does not happen
 *  0b1..SYS_TCM single-bit ECC error happens.
 */
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_MASK)
/*! @} */

/*! @name INT_STAT_EN - Interrupt Status Enable Register */
/*! @{ */

#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_MASK (0x400U)
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_SHIFT (10U)
/*! CODE_TCM_ERRM_INT_EN - CODE_TCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_MASK)

#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_MASK (0x800U)
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_SHIFT (11U)
/*! CODE_TCM_ERRS_INT_EN - CODE_TCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_MASK)

#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_MASK (0x1000U)
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_SHIFT (12U)
/*! SYS_TCM_ERRM_INT_EN - SYS_TCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_MASK)

#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_MASK (0x2000U)
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_SHIFT (13U)
/*! SYS_TCM_ERRS_INT_EN - SYS_TCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_MASK)
/*! @} */

/*! @name INT_SIG_EN - Interrupt Enable Register */
/*! @{ */

#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_MASK (0x400U)
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_SHIFT (10U)
/*! CODE_TCM_ERRM_INT_SIG_EN - CODE_TCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_MASK)

#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_MASK (0x800U)
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_SHIFT (11U)
/*! CODE_TCM_ERRS_INT_SIG_EN - CODE_TCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_MASK)

#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_MASK (0x1000U)
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_SHIFT (12U)
/*! SYS_TCM_ERRM_INT_SIG_EN - SYS_TCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_MASK)

#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_MASK (0x2000U)
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_SHIFT (13U)
/*! SYS_TCM_ERRS_INT_SIG_EN - SYS_TCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_SINGLE_ERROR_INFO - CODE_TCM single-bit ECC Error Information Register */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_SHIFT (1U)
/*! CODE_TCM_ECCS_EFSIZ - CODE_TCM single-bit ECC error corresponding TCM access size */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_SHIFT (4U)
/*! CODE_TCM_ECCS_EFMST - CODE_TCM single-bit ECC error corresponding tcm_master */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_SHIFT (8U)
/*! CODE_TCM_ECCS_EFPRT - CODE_TCM single-bit ECC error corresponding tcm_priv */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_SHIFT (12U)
/*! CODE_TCM_ECCS_EFSYN - CODE_TCM single-bit ECC error corresponding syndrome */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_SINGLE_ERROR_ADDR - CODE_TCM single-bit ECC Error Address Register */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! CODE_TCM_ECCS_ERRED_ADDR - CODE_TCM single-bit ECC error address */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_MULTI_ERROR_INFO - CODE_TCM multi-bit ECC Error Information Register */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_SHIFT (1U)
/*! CODE_TCM_ECCM_EFSIZ - CODE_TCM multi-bit ECC error corresponding TCM access size */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_SHIFT (4U)
/*! CODE_TCM_ECCM_EFMST - CODE_TCM multi-bit ECC error corresponding tcm_master */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_SHIFT (8U)
/*! CODE_TCM_ECCM_EFPRT - CODE_TCM multi-bit ECC error corresponding tcm_priv */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_SHIFT (12U)
/*! CODE_TCM_ECCM_EFSYN - CODE_TCM multi-bit ECC error corresponding syndrome */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_MULTI_ERROR_ADDR - CODE_TCM multi-bit ECC Error Address Register */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! CODE_TCM_ECCM_ERRED_ADDR - CODE_TCM multi-bit ECC error address */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_SINGLE_ERROR_INFO - SYS_TCM single-bit ECC Error Information Register */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_SHIFT (1U)
/*! SYS_TCM_ECCS_EFSIZ - SYS_TCM single-bit ECC error corresponding TCM access size */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_SHIFT (4U)
/*! SYS_TCM_ECCS_EFMST - SYS_TCM single-bit ECC error corresponding tcm_master */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_SHIFT (8U)
/*! SYS_TCM_ECCS_EFPRT - SYS_TCM single-bit ECC error corresponding tcm_priv */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_SHIFT (12U)
/*! SYS_TCM_ECCS_EFSYN - SYS_TCM single-bit ECC error corresponding syndrome */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_SINGLE_ERROR_ADDR - SYS_TCM single-bit ECC Error Address Register */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! SYS_TCM_ECCS_ERRED_ADDR - SYS_TCM single-bit ECC error address */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_MULTI_ERROR_INFO - SYS_TCM multi-bit ECC Error Information Register */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_SHIFT (1U)
/*! SYS_TCM_ECCM_EFSIZ - SYS_TCM multi-bit ECC error corresponding TCM access size */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_SHIFT (4U)
/*! SYS_TCM_ECCM_EFMST - SYS_TCM multi-bit ECC error corresponding tcm_master */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_SHIFT (8U)
/*! SYS_TCM_ECCM_EFPRT - SYS_TCM multi-bit ECC error corresponding tcm_priv */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_SHIFT (12U)
/*! SYS_TCM_ECCM_EFSYN - SYS_TCM multi-bit ECC error corresponding syndrome */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_MULTI_ERROR_ADDR - SYS_TCM multi-bit ECC Error Address Register */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! SYS_TCM_ECCM_ERRED_ADDR - SYS_TCM multi-bit ECC error address */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_ERROR_INJEC - CODE_TCM ECC Error Injection Register */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_MASK (0xFFU)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_SHIFT (0U)
/*! CODE_TCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error injection. */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_MASK (0xFF00U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_SHIFT (8U)
/*! CODE_TCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_MASK (0x10000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_SHIFT (16U)
/*! CODE_TCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on CODE_TCM write access */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_MASK (0x20000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_SHIFT (17U)
/*! CODE_TCM_FR1NCI - Force One Non-correctable Data Inversion(multi-bit ECC error) on CODE_TCM write access */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_MASK (0x40000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_SHIFT (18U)
/*! CODE_TCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on CODE_TCM write access */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_MASK (0x80000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_SHIFT (19U)
/*! CODE_TCM_FRCNCI - Force Continuous Non-correctable Data Inversions (multi-bit ECC error) on CODE_TCM write access */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_ERROR_INJEC - SYS_TCM ECC Error Injection Register */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_MASK (0xFFU)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_SHIFT (0U)
/*! SYS_TCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error injection */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_MASK (0xFF00U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_SHIFT (8U)
/*! SYS_TCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_MASK (0x10000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_SHIFT (16U)
/*! SYS_TCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on SYS_TCM write access */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_MASK (0x20000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_SHIFT (17U)
/*! SYS_TCM_FR1NCI - Force One Non-correctable Data Inversion(multi-bit ECC error) on SYS_TCM write access */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_MASK (0x40000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_SHIFT (18U)
/*! SYS_TCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on SYS_TCM write access */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_MASK (0x80000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_SHIFT (19U)
/*! SYS_TCM_FRCNCI - Force Continuous Non-correctable Data Inversions (multi-bit ECC error) on SYS_TCM write access */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TCM_ECC_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group TCM_ECC_MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_TCM_ECC_MCM_H_ */
