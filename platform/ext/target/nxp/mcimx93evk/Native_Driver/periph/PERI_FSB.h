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
**         CMSIS Peripheral Access Layer for FSB
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
 * @file PERI_FSB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FSB
 *
 * CMSIS Peripheral Access Layer for FSB
 */

#if !defined(PERI_FSB_H_)
#define PERI_FSB_H_                              /**< Symbol preventing repeated inclusion */

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
   -- FSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Peripheral_Access_Layer FSB Peripheral Access Layer
 * @{
 */

/** FSB - Size of Registers Arrays */
#define FSB_MU_INT_COUNT                          3u
#define FSB_FUSE_ARRAY_COUNT                      8192u

/** FSB - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< FSB Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[24];
  __I  uint32_t STATUS;                            /**< Status Register, offset: 0x1C */
       uint8_t RESERVED_1[68];
  __IO uint32_t ACCESS_COUNT;                      /**< Access Count Register, offset: 0x64 */
       uint8_t RESERVED_2[152];
  __IO uint32_t MU_INT[FSB_MU_INT_COUNT];          /**< MU Interrupt Control Registers, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_3[36];
  __IO uint32_t ACCESS_DOMAIN;                     /**< Access Domain Identifier, offset: 0x130 */
       uint8_t RESERVED_4[748];
  __I  uint32_t FEATURE_DIS;                       /**< Feature disables, offset: 0x420 */
       uint8_t RESERVED_5[31708];
  __I  uint32_t FUSE[FSB_FUSE_ARRAY_COUNT];        /**< Fuse Value Registers, array offset: 0x8000, array step: 0x4 */
} FSB_Type;

/* ----------------------------------------------------------------------------
   -- FSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Register_Masks FSB Register Masks
 * @{
 */

/*! @name VERID - FSB Version ID Register */
/*! @{ */

#define FSB_VERID_MISC_MASK                      (0xFFU)
#define FSB_VERID_MISC_SHIFT                     (0U)
/*! MISC - Feature Specification Number */
#define FSB_VERID_MISC(x)                        (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MISC_SHIFT)) & FSB_VERID_MISC_MASK)

#define FSB_VERID_ECO_MASK                       (0xFF00U)
#define FSB_VERID_ECO_SHIFT                      (8U)
/*! ECO - Minor Version Number */
#define FSB_VERID_ECO(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_VERID_ECO_SHIFT)) & FSB_VERID_ECO_MASK)

#define FSB_VERID_MINOR_MASK                     (0xFF0000U)
#define FSB_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define FSB_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MINOR_SHIFT)) & FSB_VERID_MINOR_MASK)

#define FSB_VERID_MAJOR_MASK                     (0xFF000000U)
#define FSB_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define FSB_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MAJOR_SHIFT)) & FSB_VERID_MAJOR_MASK)
/*! @} */

/*! @name STATUS - Status Register */
/*! @{ */

#define FSB_STATUS_FUSE_VALID_MASK               (0x1U)
#define FSB_STATUS_FUSE_VALID_SHIFT              (0U)
/*! FUSE_VALID - Fuse valid. */
#define FSB_STATUS_FUSE_VALID(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_STATUS_FUSE_VALID_SHIFT)) & FSB_STATUS_FUSE_VALID_MASK)
/*! @} */

/*! @name ACCESS_COUNT - Access Count Register */
/*! @{ */

#define FSB_ACCESS_COUNT_COUNT_MASK              (0xFFFFFFFFU)
#define FSB_ACCESS_COUNT_COUNT_SHIFT             (0U)
/*! COUNT - Access Count Register. */
#define FSB_ACCESS_COUNT_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << FSB_ACCESS_COUNT_COUNT_SHIFT)) & FSB_ACCESS_COUNT_COUNT_MASK)
/*! @} */

/*! @name MU_INT - MU Interrupt Control Registers */
/*! @{ */

#define FSB_MU_INT_INT_EN0_MASK                  (0x1U)
#define FSB_MU_INT_INT_EN0_SHIFT                 (0U)
/*! INT_EN0 - Interrupt enables for cores */
#define FSB_MU_INT_INT_EN0(x)                    (((uint32_t)(((uint32_t)(x)) << FSB_MU_INT_INT_EN0_SHIFT)) & FSB_MU_INT_INT_EN0_MASK)

#define FSB_MU_INT_INT_EN1_MASK                  (0x2U)
#define FSB_MU_INT_INT_EN1_SHIFT                 (1U)
/*! INT_EN1 - Interrupt enables for cores */
#define FSB_MU_INT_INT_EN1(x)                    (((uint32_t)(((uint32_t)(x)) << FSB_MU_INT_INT_EN1_SHIFT)) & FSB_MU_INT_INT_EN1_MASK)

#define FSB_MU_INT_INT_EN2_MASK                  (0x4U)
#define FSB_MU_INT_INT_EN2_SHIFT                 (2U)
/*! INT_EN2 - Interrupt enables for cores */
#define FSB_MU_INT_INT_EN2(x)                    (((uint32_t)(((uint32_t)(x)) << FSB_MU_INT_INT_EN2_SHIFT)) & FSB_MU_INT_INT_EN2_MASK)

#define FSB_MU_INT_LCK_MASK                      (0x10000U)
#define FSB_MU_INT_LCK_SHIFT                     (16U)
/*! LCK - Lock register from further writing. */
#define FSB_MU_INT_LCK(x)                        (((uint32_t)(((uint32_t)(x)) << FSB_MU_INT_LCK_SHIFT)) & FSB_MU_INT_LCK_MASK)
/*! @} */

/*! @name ACCESS_DOMAIN - Access Domain Identifier */
/*! @{ */

#define FSB_ACCESS_DOMAIN_TZ_MASK                (0x1U)
#define FSB_ACCESS_DOMAIN_TZ_SHIFT               (0U)
/*! TZ - TruseZone or Secure World. */
#define FSB_ACCESS_DOMAIN_TZ(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_ACCESS_DOMAIN_TZ_SHIFT)) & FSB_ACCESS_DOMAIN_TZ_MASK)

#define FSB_ACCESS_DOMAIN_DID_MASK               (0x1EU)
#define FSB_ACCESS_DOMAIN_DID_SHIFT              (1U)
/*! DID - Domain Identifier. */
#define FSB_ACCESS_DOMAIN_DID(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_ACCESS_DOMAIN_DID_SHIFT)) & FSB_ACCESS_DOMAIN_DID_MASK)
/*! @} */

/*! @name FEATURE_DIS - Feature disables */
/*! @{ */

#define FSB_FEATURE_DIS_FEAT_DIS_MASK            (0xFFU)
#define FSB_FEATURE_DIS_FEAT_DIS_SHIFT           (0U)
/*! FEAT_DIS - Status of SoC features that may be disabled. */
#define FSB_FEATURE_DIS_FEAT_DIS(x)              (((uint32_t)(((uint32_t)(x)) << FSB_FEATURE_DIS_FEAT_DIS_SHIFT)) & FSB_FEATURE_DIS_FEAT_DIS_MASK)
/*! @} */

/*! @name FUSE - Fuse Value Registers */
/*! @{ */

#define FSB_FUSE_FUSE_MASK                       (0xFFFFFFFFU)
#define FSB_FUSE_FUSE_SHIFT                      (0U)
/*! FUSE - Fuse Values */
#define FSB_FUSE_FUSE(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_FUSE_SHIFT)) & FSB_FUSE_FUSE_MASK)
/*! @} */

/* The count of FSB_FUSE */
#define FSB_FUSE_COUNT                           (8192U)


/*!
 * @}
 */ /* end of group FSB_Register_Masks */


/*!
 * @}
 */ /* end of group FSB_Peripheral_Access_Layer */


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


#endif  /* PERI_FSB_H_ */
