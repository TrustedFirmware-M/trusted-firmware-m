/*
** ###################################################################
**     Processors:          KW43B43ZC2MFT
**                          KW43B43ZC3MFT
**                          KW43B43ZC6MFT
**                          KW43B43ZC7MFT
**                          KW43L43Z92MFT
**                          KW43L43Z93MFT
**                          KW43L43Z96MFT
**                          KW43L43Z97MFT
**
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b260316
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ISP_AP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_ISP_AP.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for ISP_AP
 *
 * CMSIS Peripheral Access Layer for ISP_AP
 */

#if !defined(PERI_ISP_AP_H_)
#define PERI_ISP_AP_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW43B43ZC2MFT))
#include "KW43B43ZC2_COMMON.h"
#elif (defined(CPU_KW43B43ZC3MFT))
#include "KW43B43ZC3_COMMON.h"
#elif (defined(CPU_KW43B43ZC6MFT))
#include "KW43B43ZC6_COMMON.h"
#elif (defined(CPU_KW43B43ZC7MFT))
#include "KW43B43ZC7_COMMON.h"
#elif (defined(CPU_KW43L43Z92MFT))
#include "KW43L43Z92_COMMON.h"
#elif (defined(CPU_KW43L43Z93MFT))
#include "KW43L43Z93_COMMON.h"
#elif (defined(CPU_KW43L43Z96MFT))
#include "KW43L43Z96_COMMON.h"
#elif (defined(CPU_KW43L43Z97MFT))
#include "KW43L43Z97_COMMON.h"
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
   -- ISP_AP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISP_AP_Peripheral_Access_Layer ISP_AP Peripheral Access Layer
 * @{
 */

/** ISP_AP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< Command and Status Word, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< Request Value, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return Value, offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification, offset: 0xFC */
} ISP_AP_Type;

/* ----------------------------------------------------------------------------
   -- ISP_AP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISP_AP_Register_Masks ISP_AP Register Masks
 * @{
 */

/*! @name CSW - Command and Status Word */
/*! @{ */

#define ISP_AP_CSW_RESYNCH_REQ_MASK              (0x1U)
#define ISP_AP_CSW_RESYNCH_REQ_SHIFT             (0U)
/*! RESYNCH_REQ - Resynchronization Request
 *  0b0..No request
 *  0b1..Request for resynchronization
 */
#define ISP_AP_CSW_RESYNCH_REQ(x)                (((uint32_t)(((uint32_t)(x)) << ISP_AP_CSW_RESYNCH_REQ_SHIFT)) & ISP_AP_CSW_RESYNCH_REQ_MASK)

#define ISP_AP_CSW_REQ_PENDING_MASK              (0x2U)
#define ISP_AP_CSW_REQ_PENDING_SHIFT             (1U)
/*! REQ_PENDING - Request Pending
 *  0b0..No request pending
 *  0b1..Request for resynchronization pending
 */
#define ISP_AP_CSW_REQ_PENDING(x)                (((uint32_t)(((uint32_t)(x)) << ISP_AP_CSW_REQ_PENDING_SHIFT)) & ISP_AP_CSW_REQ_PENDING_MASK)

#define ISP_AP_CSW_DBG_OR_ERR_MASK               (0x4U)
#define ISP_AP_CSW_DBG_OR_ERR_SHIFT              (2U)
/*! DBG_OR_ERR - DBGMB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define ISP_AP_CSW_DBG_OR_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << ISP_AP_CSW_DBG_OR_ERR_SHIFT)) & ISP_AP_CSW_DBG_OR_ERR_MASK)

#define ISP_AP_CSW_AHB_OR_ERR_MASK               (0x8U)
#define ISP_AP_CSW_AHB_OR_ERR_SHIFT              (3U)
/*! AHB_OR_ERR - AHB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define ISP_AP_CSW_AHB_OR_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << ISP_AP_CSW_AHB_OR_ERR_SHIFT)) & ISP_AP_CSW_AHB_OR_ERR_MASK)

#define ISP_AP_CSW_SOFT_RESET_MASK               (0x10U)
#define ISP_AP_CSW_SOFT_RESET_SHIFT              (4U)
/*! SOFT_RESET - Soft Reset
 *  0b0..No effect
 *  0b1..Reset
 */
#define ISP_AP_CSW_SOFT_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << ISP_AP_CSW_SOFT_RESET_SHIFT)) & ISP_AP_CSW_SOFT_RESET_MASK)

#define ISP_AP_CSW_CHIP_RESET_REQ_MASK           (0x20U)
#define ISP_AP_CSW_CHIP_RESET_REQ_SHIFT          (5U)
/*! CHIP_RESET_REQ - Chip Reset Request
 *  0b0..No effect
 *  0b1..Reset
 */
#define ISP_AP_CSW_CHIP_RESET_REQ(x)             (((uint32_t)(((uint32_t)(x)) << ISP_AP_CSW_CHIP_RESET_REQ_SHIFT)) & ISP_AP_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - Request Value */
/*! @{ */

#define ISP_AP_REQUEST_REQUEST_MASK              (0xFFFFFFFFU)
#define ISP_AP_REQUEST_REQUEST_SHIFT             (0U)
/*! REQUEST - Request Value */
#define ISP_AP_REQUEST_REQUEST(x)                (((uint32_t)(((uint32_t)(x)) << ISP_AP_REQUEST_REQUEST_SHIFT)) & ISP_AP_REQUEST_REQUEST_MASK)
/*! @} */

/*! @name RETURN - Return Value */
/*! @{ */

#define ISP_AP_RETURN_RET_MASK                   (0xFFFFFFFFU)
#define ISP_AP_RETURN_RET_SHIFT                  (0U)
/*! RET - Return Value */
#define ISP_AP_RETURN_RET(x)                     (((uint32_t)(((uint32_t)(x)) << ISP_AP_RETURN_RET_SHIFT)) & ISP_AP_RETURN_RET_MASK)
/*! @} */

/*! @name ID - Identification */
/*! @{ */

#define ISP_AP_ID_ID_MASK                        (0xFFFFFFFFU)
#define ISP_AP_ID_ID_SHIFT                       (0U)
/*! ID - Identification Value */
#define ISP_AP_ID_ID(x)                          (((uint32_t)(((uint32_t)(x)) << ISP_AP_ID_ID_SHIFT)) & ISP_AP_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ISP_AP_Register_Masks */


/*!
 * @}
 */ /* end of group ISP_AP_Peripheral_Access_Layer */


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


#endif  /* PERI_ISP_AP_H_ */

