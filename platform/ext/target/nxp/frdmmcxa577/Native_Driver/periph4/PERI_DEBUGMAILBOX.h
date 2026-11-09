/*
** ###################################################################
**     Processors:          MCXA286VAPR
**                          MCXA286VASR
**                          MCXA286VLL
**                          MCXA286VLQ
**                          MCXA286VPN
**                          MCXA287VAPR
**                          MCXA287VASR
**                          MCXA287VLL
**                          MCXA287VLQ
**                          MCXA287VPN
**                          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
**                          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA566VLL
**                          MCXA566VLQ
**                          MCXA566VPN
**                          MCXA567VLL
**                          MCXA567VLQ
**                          MCXA567VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DEBUGMAILBOX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DEBUGMAILBOX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DEBUGMAILBOX
 *
 * CMSIS Peripheral Access Layer for DEBUGMAILBOX
 */

#if !defined(PERI_DEBUGMAILBOX_H_)
#define PERI_DEBUGMAILBOX_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
#elif (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA566VLL) || defined(CPU_MCXA566VLQ) || defined(CPU_MCXA566VPN))
#include "MCXA566_COMMON.h"
#elif (defined(CPU_MCXA567VLL) || defined(CPU_MCXA567VLQ) || defined(CPU_MCXA567VPN))
#include "MCXA567_COMMON.h"
#elif (defined(CPU_MCXA577VAPR) || defined(CPU_MCXA577VLL) || defined(CPU_MCXA577VLQ) || defined(CPU_MCXA577VPN))
#include "MCXA577_COMMON.h"
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
   -- DEBUGMAILBOX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUGMAILBOX_Peripheral_Access_Layer DEBUGMAILBOX Peripheral Access Layer
 * @{
 */

/** DEBUGMAILBOX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< Command and Status Word, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< Request Value, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return Value, offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification, offset: 0xFC */
} DEBUGMAILBOX_Type;

/* ----------------------------------------------------------------------------
   -- DEBUGMAILBOX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUGMAILBOX_Register_Masks DEBUGMAILBOX Register Masks
 * @{
 */

/*! @name CSW - Command and Status Word */
/*! @{ */

#define DEBUGMAILBOX_CSW_RESYNCH_REQ_MASK        (0x1U)
#define DEBUGMAILBOX_CSW_RESYNCH_REQ_SHIFT       (0U)
/*! RESYNCH_REQ - Resynchronization Request
 *  0b0..No request
 *  0b1..Request for resynchronization
 */
#define DEBUGMAILBOX_CSW_RESYNCH_REQ(x)          (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_RESYNCH_REQ_SHIFT)) & DEBUGMAILBOX_CSW_RESYNCH_REQ_MASK)

#define DEBUGMAILBOX_CSW_REQ_PENDING_MASK        (0x2U)
#define DEBUGMAILBOX_CSW_REQ_PENDING_SHIFT       (1U)
/*! REQ_PENDING - Request Pending
 *  0b0..No request pending
 *  0b1..The debugger has written a value into the REQUEST register and it's pending the chip reading REQUEST
 */
#define DEBUGMAILBOX_CSW_REQ_PENDING(x)          (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_REQ_PENDING_SHIFT)) & DEBUGMAILBOX_CSW_REQ_PENDING_MASK)

#define DEBUGMAILBOX_CSW_DBG_OR_ERR_MASK         (0x4U)
#define DEBUGMAILBOX_CSW_DBG_OR_ERR_SHIFT        (2U)
/*! DBG_OR_ERR - DBGMB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DEBUGMAILBOX_CSW_DBG_OR_ERR(x)           (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_DBG_OR_ERR_SHIFT)) & DEBUGMAILBOX_CSW_DBG_OR_ERR_MASK)

#define DEBUGMAILBOX_CSW_AHB_OR_ERR_MASK         (0x8U)
#define DEBUGMAILBOX_CSW_AHB_OR_ERR_SHIFT        (3U)
/*! AHB_OR_ERR - AHB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DEBUGMAILBOX_CSW_AHB_OR_ERR(x)           (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_AHB_OR_ERR_SHIFT)) & DEBUGMAILBOX_CSW_AHB_OR_ERR_MASK)

#define DEBUGMAILBOX_CSW_SOFT_RESET_MASK         (0x10U)
#define DEBUGMAILBOX_CSW_SOFT_RESET_SHIFT        (4U)
/*! SOFT_RESET - Soft Reset
 *  0b0..No effect
 *  0b1..Reset
 */
#define DEBUGMAILBOX_CSW_SOFT_RESET(x)           (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_SOFT_RESET_SHIFT)) & DEBUGMAILBOX_CSW_SOFT_RESET_MASK)

#define DEBUGMAILBOX_CSW_CHIP_RESET_REQ_MASK     (0x20U)
#define DEBUGMAILBOX_CSW_CHIP_RESET_REQ_SHIFT    (5U)
/*! CHIP_RESET_REQ - Chip Reset Request
 *  0b0..No effect
 *  0b1..Reset
 */
#define DEBUGMAILBOX_CSW_CHIP_RESET_REQ(x)       (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_CHIP_RESET_REQ_SHIFT)) & DEBUGMAILBOX_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - Request Value */
/*! @{ */

#define DEBUGMAILBOX_REQUEST_REQUEST_MASK        (0xFFFFFFFFU)
#define DEBUGMAILBOX_REQUEST_REQUEST_SHIFT       (0U)
/*! REQUEST - Request Value */
#define DEBUGMAILBOX_REQUEST_REQUEST(x)          (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_REQUEST_REQUEST_SHIFT)) & DEBUGMAILBOX_REQUEST_REQUEST_MASK)
/*! @} */

/*! @name RETURN - Return Value */
/*! @{ */

#define DEBUGMAILBOX_RETURN_RET_MASK             (0xFFFFFFFFU)
#define DEBUGMAILBOX_RETURN_RET_SHIFT            (0U)
/*! RET - Return Value */
#define DEBUGMAILBOX_RETURN_RET(x)               (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_RETURN_RET_SHIFT)) & DEBUGMAILBOX_RETURN_RET_MASK)
/*! @} */

/*! @name ID - Identification */
/*! @{ */

#define DEBUGMAILBOX_ID_ID_MASK                  (0xFFFFFFFFU)
#define DEBUGMAILBOX_ID_ID_SHIFT                 (0U)
/*! ID - Identification Value */
#define DEBUGMAILBOX_ID_ID(x)                    (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_ID_ID_SHIFT)) & DEBUGMAILBOX_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DEBUGMAILBOX_Register_Masks */


/*!
 * @}
 */ /* end of group DEBUGMAILBOX_Peripheral_Access_Layer */


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


#endif  /* PERI_DEBUGMAILBOX_H_ */

