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
**         CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
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
 * @file PERI_SYS_CTR_COMPARE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
 *
 * CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
 */

#if !defined(PERI_SYS_CTR_COMPARE_H_)
#define PERI_SYS_CTR_COMPARE_H_                  /**< Symbol preventing repeated inclusion */

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
   -- SYS_CTR_COMPARE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Peripheral_Access_Layer SYS_CTR_COMPARE Peripheral Access Layer
 * @{
 */

/** SYS_CTR_COMPARE - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t CMPCVL0;                           /**< Compare Count Value Low, offset: 0x20 */
  __IO uint32_t CMPCVH0;                           /**< Compare Count Value High, offset: 0x24 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CMPCR0;                            /**< Compare Control, offset: 0x2C */
       uint8_t RESERVED_2[240];
  __IO uint32_t CMPCVL1;                           /**< Compare Count Value Low, offset: 0x120 */
  __IO uint32_t CMPCVH1;                           /**< Compare Count Value High, offset: 0x124 */
       uint8_t RESERVED_3[4];
  __IO uint32_t CMPCR1;                            /**< Compare Control, offset: 0x12C */
       uint8_t RESERVED_4[3744];
  __I  uint32_t CNTID0;                            /**< Counter ID, offset: 0xFD0 */
} SYS_CTR_COMPARE_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_COMPARE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Register_Masks SYS_CTR_COMPARE Register Masks
 * @{
 */

/*! @name CMPCVL0 - Compare Count Value Low */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK      (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT     (0U)
/*! CMPCV0 - Compare Count Value Bits [31:0] */
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH0 - Compare Count Value High */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK      (0xFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT     (0U)
/*! CMPCV1 - Compare Count Value Bits [55:32] */
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR0 - Compare Control */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR0_EN_MASK           (0x1U)
#define SYS_CTR_COMPARE_CMPCR0_EN_SHIFT          (0U)
/*! EN - Compare Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYS_CTR_COMPARE_CMPCR0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR0_IMASK_MASK        (0x2U)
#define SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT       (1U)
/*! IMASK - Interrupt Request Mask
 *  0b0..Not masked
 *  0b1..Masked
 */
#define SYS_CTR_COMPARE_CMPCR0_IMASK(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK        (0x4U)
#define SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT       (2U)
/*! ISTAT - Compare Interrupt Status
 *  0b0..Either less than the compare value or compare is disabled
 *  0b1..Greater than or equal to the compare value and compare is enabled
 */
#define SYS_CTR_COMPARE_CMPCR0_ISTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK)
/*! @} */

/*! @name CMPCVL1 - Compare Count Value Low */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK      (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT     (0U)
/*! CMPCV0 - Compare Count Value Bits [31:0] */
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH1 - Compare Count Value High */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK      (0xFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT     (0U)
/*! CMPCV1 - Compare Count Value Bits [55:32] */
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR1 - Compare Control */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR1_EN_MASK           (0x1U)
#define SYS_CTR_COMPARE_CMPCR1_EN_SHIFT          (0U)
/*! EN - Compare Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYS_CTR_COMPARE_CMPCR1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR1_IMASK_MASK        (0x2U)
#define SYS_CTR_COMPARE_CMPCR1_IMASK_SHIFT       (1U)
/*! IMASK - Interrupt Request Mask
 *  0b0..Not masked
 *  0b1..Masked
 */
#define SYS_CTR_COMPARE_CMPCR1_IMASK(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR1_ISTAT_MASK        (0x4U)
#define SYS_CTR_COMPARE_CMPCR1_ISTAT_SHIFT       (2U)
/*! ISTAT - Compare Interrupt Status
 *  0b0..Either less than the compare value or compare is disabled
 *  0b1..Greater than or equal to the compare value and compare is enabled
 */
#define SYS_CTR_COMPARE_CMPCR1_ISTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_ISTAT_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID */
/*! @{ */

#define SYS_CTR_COMPARE_CNTID0_CNTID_MASK        (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CNTID0_CNTID_SHIFT       (0U)
/*! CNTID - Counter Identification */
#define SYS_CTR_COMPARE_CNTID0_CNTID(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CNTID0_CNTID_SHIFT)) & SYS_CTR_COMPARE_CNTID0_CNTID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYS_CTR_COMPARE_Register_Masks */


/*!
 * @}
 */ /* end of group SYS_CTR_COMPARE_Peripheral_Access_Layer */


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


#endif  /* PERI_SYS_CTR_COMPARE_H_ */
