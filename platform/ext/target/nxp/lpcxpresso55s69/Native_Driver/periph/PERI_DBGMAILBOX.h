/*
** ###################################################################
**     Processors:          LPC5526JBD100
**                          LPC5526JBD64
**                          LPC5526JEV98
**                          LPC5528JBD100
**                          LPC5528JBD64
**                          LPC5528JEV59
**                          LPC5528JEV98
**                          LPC55S26JBD100
**                          LPC55S26JBD64
**                          LPC55S26JEV98
**                          LPC55S28JBD100
**                          LPC55S28JBD64
**                          LPC55S28JEV59
**                          LPC55S28JEV98
**                          LPC55S66JBD100_cm33_core0
**                          LPC55S66JBD100_cm33_core1
**                          LPC55S66JBD64_cm33_core0
**                          LPC55S66JBD64_cm33_core1
**                          LPC55S66JEV98_cm33_core0
**                          LPC55S66JEV98_cm33_core1
**                          LPC55S69JBD100_cm33_core0
**                          LPC55S69JBD100_cm33_core1
**                          LPC55S69JBD64_cm33_core0
**                          LPC55S69JBD64_cm33_core1
**                          LPC55S69JEV59_cm33_core0
**                          LPC55S69JEV59_cm33_core1
**                          LPC55S69JEV98_cm33_core0
**                          LPC55S69JEV98_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250529
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DBGMAILBOX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-08-22)
**         Initial version based on v0.2UM
**     - rev. 1.1 (2019-05-16)
**         Initial A1 version based on v1.3UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DBGMAILBOX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DBGMAILBOX
 *
 * CMSIS Peripheral Access Layer for DBGMAILBOX
 */

#if !defined(PERI_DBGMAILBOX_H_)
#define PERI_DBGMAILBOX_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5526JBD100) || defined(CPU_LPC5526JBD64) || defined(CPU_LPC5526JEV98))
#include "LPC5526_COMMON.h"
#elif (defined(CPU_LPC5528JBD100) || defined(CPU_LPC5528JBD64) || defined(CPU_LPC5528JEV59) || defined(CPU_LPC5528JEV98))
#include "LPC5528_COMMON.h"
#elif (defined(CPU_LPC55S26JBD100) || defined(CPU_LPC55S26JBD64) || defined(CPU_LPC55S26JEV98))
#include "LPC55S26_COMMON.h"
#elif (defined(CPU_LPC55S28JBD100) || defined(CPU_LPC55S28JBD64) || defined(CPU_LPC55S28JEV59) || defined(CPU_LPC55S28JEV98))
#include "LPC55S28_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core0) || defined(CPU_LPC55S66JBD64_cm33_core0) || defined(CPU_LPC55S66JEV98_cm33_core0))
#include "LPC55S66_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core1) || defined(CPU_LPC55S66JBD64_cm33_core1) || defined(CPU_LPC55S66JEV98_cm33_core1))
#include "LPC55S66_cm33_core1_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core0) || defined(CPU_LPC55S69JBD64_cm33_core0) || defined(CPU_LPC55S69JEV59_cm33_core0) || defined(CPU_LPC55S69JEV98_cm33_core0))
#include "LPC55S69_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core1) || defined(CPU_LPC55S69JBD64_cm33_core1) || defined(CPU_LPC55S69JEV59_cm33_core1) || defined(CPU_LPC55S69JEV98_cm33_core1))
#include "LPC55S69_cm33_core1_COMMON.h"
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
   -- DBGMAILBOX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DBGMAILBOX_Peripheral_Access_Layer DBGMAILBOX Peripheral Access Layer
 * @{
 */

/** DBGMAILBOX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< CRC mode register, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< CRC seed register, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return value from ROM., offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification register, offset: 0xFC */
} DBGMAILBOX_Type;

/* ----------------------------------------------------------------------------
   -- DBGMAILBOX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DBGMAILBOX_Register_Masks DBGMAILBOX Register Masks
 * @{
 */

/*! @name CSW - CRC mode register */
/*! @{ */

#define DBGMAILBOX_CSW_RESYNCH_REQ_MASK          (0x1U)
#define DBGMAILBOX_CSW_RESYNCH_REQ_SHIFT         (0U)
/*! RESYNCH_REQ - Debugger will set this bit to 1 to request a resynchronrisation */
#define DBGMAILBOX_CSW_RESYNCH_REQ(x)            (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_CSW_RESYNCH_REQ_SHIFT)) & DBGMAILBOX_CSW_RESYNCH_REQ_MASK)

#define DBGMAILBOX_CSW_REQ_PENDING_MASK          (0x2U)
#define DBGMAILBOX_CSW_REQ_PENDING_SHIFT         (1U)
/*! REQ_PENDING - Request is pending from debugger (i.e unread value in REQUEST) */
#define DBGMAILBOX_CSW_REQ_PENDING(x)            (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_CSW_REQ_PENDING_SHIFT)) & DBGMAILBOX_CSW_REQ_PENDING_MASK)

#define DBGMAILBOX_CSW_DBG_OR_ERR_MASK           (0x4U)
#define DBGMAILBOX_CSW_DBG_OR_ERR_SHIFT          (2U)
/*! DBG_OR_ERR - Debugger overrun error (previous REQUEST overwritten before being picked up by ROM) */
#define DBGMAILBOX_CSW_DBG_OR_ERR(x)             (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_CSW_DBG_OR_ERR_SHIFT)) & DBGMAILBOX_CSW_DBG_OR_ERR_MASK)

#define DBGMAILBOX_CSW_AHB_OR_ERR_MASK           (0x8U)
#define DBGMAILBOX_CSW_AHB_OR_ERR_SHIFT          (3U)
/*! AHB_OR_ERR - AHB overrun Error (Return value overwritten by ROM) */
#define DBGMAILBOX_CSW_AHB_OR_ERR(x)             (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_CSW_AHB_OR_ERR_SHIFT)) & DBGMAILBOX_CSW_AHB_OR_ERR_MASK)

#define DBGMAILBOX_CSW_SOFT_RESET_MASK           (0x10U)
#define DBGMAILBOX_CSW_SOFT_RESET_SHIFT          (4U)
/*! SOFT_RESET - Soft Reset for DM (write-only from AHB, not readable and selfclearing). A write to
 *    this bit will cause a soft reset for DM.
 */
#define DBGMAILBOX_CSW_SOFT_RESET(x)             (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_CSW_SOFT_RESET_SHIFT)) & DBGMAILBOX_CSW_SOFT_RESET_MASK)

#define DBGMAILBOX_CSW_CHIP_RESET_REQ_MASK       (0x20U)
#define DBGMAILBOX_CSW_CHIP_RESET_REQ_SHIFT      (5U)
/*! CHIP_RESET_REQ - Write only bit. Once written will cause the chip to reset (note that the DM is
 *    not reset by this reset as it is only resettable by a SOFT reset or a POR/BOD event)
 */
#define DBGMAILBOX_CSW_CHIP_RESET_REQ(x)         (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_CSW_CHIP_RESET_REQ_SHIFT)) & DBGMAILBOX_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - CRC seed register */
/*! @{ */

#define DBGMAILBOX_REQUEST_REQ_MASK              (0xFFFFFFFFU)
#define DBGMAILBOX_REQUEST_REQ_SHIFT             (0U)
/*! REQ - Request Value */
#define DBGMAILBOX_REQUEST_REQ(x)                (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_REQUEST_REQ_SHIFT)) & DBGMAILBOX_REQUEST_REQ_MASK)
/*! @} */

/*! @name RETURN - Return value from ROM. */
/*! @{ */

#define DBGMAILBOX_RETURN_RET_MASK               (0xFFFFFFFFU)
#define DBGMAILBOX_RETURN_RET_SHIFT              (0U)
/*! RET - The Return value from ROM. */
#define DBGMAILBOX_RETURN_RET(x)                 (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_RETURN_RET_SHIFT)) & DBGMAILBOX_RETURN_RET_MASK)
/*! @} */

/*! @name ID - Identification register */
/*! @{ */

#define DBGMAILBOX_ID_ID_MASK                    (0xFFFFFFFFU)
#define DBGMAILBOX_ID_ID_SHIFT                   (0U)
/*! ID - Identification value. */
#define DBGMAILBOX_ID_ID(x)                      (((uint32_t)(((uint32_t)(x)) << DBGMAILBOX_ID_ID_SHIFT)) & DBGMAILBOX_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DBGMAILBOX_Register_Masks */


/*!
 * @}
 */ /* end of group DBGMAILBOX_Peripheral_Access_Layer */


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


#endif  /* PERI_DBGMAILBOX_H_ */

