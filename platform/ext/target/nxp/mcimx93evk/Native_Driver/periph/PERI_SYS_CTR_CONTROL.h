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
**         CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
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
 * @file PERI_SYS_CTR_CONTROL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
 *
 * CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
 */

#if !defined(PERI_SYS_CTR_CONTROL_H_)
#define PERI_SYS_CTR_CONTROL_H_                  /**< Symbol preventing repeated inclusion */

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
   -- SYS_CTR_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_CONTROL_Peripheral_Access_Layer SYS_CTR_CONTROL Peripheral Access Layer
 * @{
 */

/** SYS_CTR_CONTROL - Register Layout Typedef */
typedef struct {
  __IO uint32_t CNTCR;                             /**< Counter Control, offset: 0x0 */
  __I  uint32_t CNTSR;                             /**< Counter Status, offset: 0x4 */
  __IO uint32_t CNTCV0;                            /**< Counter Count Value Low, offset: 0x8 */
  __IO uint32_t CNTCV1;                            /**< Counter Count Value High, offset: 0xC */
       uint8_t RESERVED_0[16];
  __I  uint32_t CNTFID0;                           /**< Frequency-Modes Table 0, offset: 0x20 */
  __I  uint32_t CNTFID1;                           /**< Frequency-Modes Table 1, offset: 0x24 */
  __I  uint32_t CNTFID2;                           /**< Frequency-Modes Table 2, offset: 0x28 */
       uint8_t RESERVED_1[148];
  __IO uint32_t CNTCR2;                            /**< Counter Control 2, offset: 0xC0 */
       uint8_t RESERVED_2[3852];
  __I  uint32_t CNTID0;                            /**< Counter ID, offset: 0xFD0 */
} SYS_CTR_CONTROL_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_CONTROL_Register_Masks SYS_CTR_CONTROL Register Masks
 * @{
 */

/*! @name CNTCR - Counter Control */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCR_EN_MASK            (0x1U)
#define SYS_CTR_CONTROL_CNTCR_EN_SHIFT           (0U)
/*! EN - Enable Counting
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYS_CTR_CONTROL_CNTCR_EN(x)              (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_EN_SHIFT)) & SYS_CTR_CONTROL_CNTCR_EN_MASK)

#define SYS_CTR_CONTROL_CNTCR_HDBG_MASK          (0x2U)
#define SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT         (1U)
/*! HDBG - Enable Debug Halt
 *  0b0..Ignored
 *  0b1..Causes SYS_CTR to halt
 */
#define SYS_CTR_CONTROL_CNTCR_HDBG(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT)) & SYS_CTR_CONTROL_CNTCR_HDBG_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR0_MASK          (0x100U)
#define SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT         (8U)
/*! FCR0 - Frequency Change Request, ID 0
 *  0b0..No change
 *  0b1..Base frequency
 */
#define SYS_CTR_CONTROL_CNTCR_FCR0(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR0_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR1_MASK          (0x200U)
#define SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT         (9U)
/*! FCR1 - Frequency Change Request, ID 1
 *  0b0..No change
 *  0b1..Base frequency
 */
#define SYS_CTR_CONTROL_CNTCR_FCR1(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR1_MASK)
/*! @} */

/*! @name CNTSR - Counter Status */
/*! @{ */

#define SYS_CTR_CONTROL_CNTSR_DBGH_MASK          (0x1U)
#define SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT         (0U)
/*! DBGH - Debug Halt
 *  0b0..Did not halt
 *  0b1..Halted
 */
#define SYS_CTR_CONTROL_CNTSR_DBGH(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT)) & SYS_CTR_CONTROL_CNTSR_DBGH_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA0_MASK          (0x100U)
#define SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT         (8U)
/*! FCA0 - Frequency Change Acknowledge, ID 0
 *  0b0..Not selected
 *  0b1..Selected
 */
#define SYS_CTR_CONTROL_CNTSR_FCA0(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA0_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA1_MASK          (0x200U)
#define SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT         (9U)
/*! FCA1 - Frequency Change Acknowledge, ID 1
 *  0b0..Not selected
 *  0b1..Selected
 */
#define SYS_CTR_CONTROL_CNTSR_FCA1(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA1_MASK)
/*! @} */

/*! @name CNTCV0 - Counter Count Value Low */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK       (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT      (0U)
/*! CNTCV0 - Counter Count Value Bits [31:0] */
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0(x)         (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT)) & SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK)
/*! @} */

/*! @name CNTCV1 - Counter Count Value High */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK       (0xFFFFFFU)
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT      (0U)
/*! CNTCV1 - Counter Count Value Bits [55:32] */
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1(x)         (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT)) & SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK)
/*! @} */

/*! @name CNTFID0 - Frequency-Modes Table 0 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT    (0U)
/*! CNTFID0 - Counter Frequency ID 0 */
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT)) & SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK)
/*! @} */

/*! @name CNTFID1 - Frequency-Modes Table 1 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT    (0U)
/*! CNTFID1 - Counter Frequency ID 1 */
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT)) & SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK)
/*! @} */

/*! @name CNTFID2 - Frequency-Modes Table 2 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT    (0U)
/*! CNTFID2 - Counter Frequency ID 2 */
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT)) & SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK)
/*! @} */

/*! @name CNTCR2 - Counter Control 2 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCR2_HWFC_EN_MASK      (0x1U)
#define SYS_CTR_CONTROL_CNTCR2_HWFC_EN_SHIFT     (0U)
/*! HWFC_EN - Hardware Frequency Change Enable
 *  0b0..No effect
 *  0b1..Same as performed via software
 */
#define SYS_CTR_CONTROL_CNTCR2_HWFC_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR2_HWFC_EN_SHIFT)) & SYS_CTR_CONTROL_CNTCR2_HWFC_EN_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID */
/*! @{ */

#define SYS_CTR_CONTROL_CNTID0_CNTID_MASK        (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTID0_CNTID_SHIFT       (0U)
/*! CNTID - Counter Identification */
#define SYS_CTR_CONTROL_CNTID0_CNTID(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTID0_CNTID_SHIFT)) & SYS_CTR_CONTROL_CNTID0_CNTID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYS_CTR_CONTROL_Register_Masks */


/*!
 * @}
 */ /* end of group SYS_CTR_CONTROL_Peripheral_Access_Layer */


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


#endif  /* PERI_SYS_CTR_CONTROL_H_ */
