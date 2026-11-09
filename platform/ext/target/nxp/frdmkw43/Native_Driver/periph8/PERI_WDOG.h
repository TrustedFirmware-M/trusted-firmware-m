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
**         CMSIS Peripheral Access Layer for WDOG
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
 * @file PERI_WDOG.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for WDOG
 *
 * CMSIS Peripheral Access Layer for WDOG
 */

#if !defined(PERI_WDOG_H_)
#define PERI_WDOG_H_                             /**< Symbol preventing repeated inclusion */

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
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CS;                                /**< WDOG Control and Status, offset: 0x0 */
  __IO uint32_t CNT;                               /**< WDOG Counter, offset: 0x4 */
  __IO uint32_t TOVAL;                             /**< WDOG Timeout Value, offset: 0x8 */
  __IO uint32_t WIN;                               /**< Watchdog Window, offset: 0xC */
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/*! @name CS - WDOG Control and Status */
/*! @{ */

#define WDOG_CS_STOP_MASK                        (0x1U)
#define WDOG_CS_STOP_SHIFT                       (0U)
/*! STOP - Stop Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_STOP(x)                          (((uint32_t)(((uint32_t)(x)) << WDOG_CS_STOP_SHIFT)) & WDOG_CS_STOP_MASK)

#define WDOG_CS_WAIT_MASK                        (0x2U)
#define WDOG_CS_WAIT_SHIFT                       (1U)
/*! WAIT - Wait Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_WAIT(x)                          (((uint32_t)(((uint32_t)(x)) << WDOG_CS_WAIT_SHIFT)) & WDOG_CS_WAIT_MASK)

#define WDOG_CS_DBG_MASK                         (0x4U)
#define WDOG_CS_DBG_SHIFT                        (2U)
/*! DBG - Debug Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_DBG(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_DBG_SHIFT)) & WDOG_CS_DBG_MASK)

#define WDOG_CS_TST_MASK                         (0x18U)
#define WDOG_CS_TST_SHIFT                        (3U)
/*! TST - WDOG Test
 *  0b00..Disable WDOG Test mode
 *  0b01..Enable WDOG User mode
 *  0b10-0b11..Enable WDOG Test mode
 */
#define WDOG_CS_TST(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_TST_SHIFT)) & WDOG_CS_TST_MASK)

#define WDOG_CS_UPDATE_MASK                      (0x20U)
#define WDOG_CS_UPDATE_SHIFT                     (5U)
/*! UPDATE - Updates Allowed
 *  0b0..Updates not allowed
 *  0b1..Updates allowed
 */
#define WDOG_CS_UPDATE(x)                        (((uint32_t)(((uint32_t)(x)) << WDOG_CS_UPDATE_SHIFT)) & WDOG_CS_UPDATE_MASK)

#define WDOG_CS_INT_MASK                         (0x40U)
#define WDOG_CS_INT_SHIFT                        (6U)
/*! INT - WDOG Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_INT(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_INT_SHIFT)) & WDOG_CS_INT_MASK)

#define WDOG_CS_EN_MASK                          (0x80U)
#define WDOG_CS_EN_SHIFT                         (7U)
/*! EN - WDOG Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_EN(x)                            (((uint32_t)(((uint32_t)(x)) << WDOG_CS_EN_SHIFT)) & WDOG_CS_EN_MASK)

#define WDOG_CS_CLK_MASK                         (0x300U)
#define WDOG_CS_CLK_SHIFT                        (8U)
/*! CLK - WDOG Clock */
#define WDOG_CS_CLK(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_CLK_SHIFT)) & WDOG_CS_CLK_MASK)

#define WDOG_CS_RCS_MASK                         (0x400U)
#define WDOG_CS_RCS_SHIFT                        (10U)
/*! RCS - Reconfiguration Success
 *  0b0..Unsuccessful
 *  0b1..Successful
 */
#define WDOG_CS_RCS(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_RCS_SHIFT)) & WDOG_CS_RCS_MASK)

#define WDOG_CS_ULK_MASK                         (0x800U)
#define WDOG_CS_ULK_SHIFT                        (11U)
/*! ULK - Unlock Status
 *  0b0..Locked
 *  0b1..Unlocked
 */
#define WDOG_CS_ULK(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_ULK_SHIFT)) & WDOG_CS_ULK_MASK)

#define WDOG_CS_PRES_MASK                        (0x1000U)
#define WDOG_CS_PRES_SHIFT                       (12U)
/*! PRES - WDOG Prescaler
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_PRES(x)                          (((uint32_t)(((uint32_t)(x)) << WDOG_CS_PRES_SHIFT)) & WDOG_CS_PRES_MASK)

#define WDOG_CS_CMD32EN_MASK                     (0x2000U)
#define WDOG_CS_CMD32EN_SHIFT                    (13U)
/*! CMD32EN - Command 32 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_CMD32EN(x)                       (((uint32_t)(((uint32_t)(x)) << WDOG_CS_CMD32EN_SHIFT)) & WDOG_CS_CMD32EN_MASK)

#define WDOG_CS_FLG_MASK                         (0x4000U)
#define WDOG_CS_FLG_SHIFT                        (14U)
/*! FLG - WDOG Interrupt Flag
 *  0b0..No interrupt occurred
 *  0b1..An interrupt occurred
 */
#define WDOG_CS_FLG(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_FLG_SHIFT)) & WDOG_CS_FLG_MASK)

#define WDOG_CS_WIN_MASK                         (0x8000U)
#define WDOG_CS_WIN_SHIFT                        (15U)
/*! WIN - WDOG Window
 *  0b0..Disable
 *  0b1..Enable
 */
#define WDOG_CS_WIN(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_WIN_SHIFT)) & WDOG_CS_WIN_MASK)
/*! @} */

/*! @name CNT - WDOG Counter */
/*! @{ */

#define WDOG_CNT_CNTLOW_MASK                     (0xFFU)
#define WDOG_CNT_CNTLOW_SHIFT                    (0U)
/*! CNTLOW - Counter Low Byte */
#define WDOG_CNT_CNTLOW(x)                       (((uint32_t)(((uint32_t)(x)) << WDOG_CNT_CNTLOW_SHIFT)) & WDOG_CNT_CNTLOW_MASK)

#define WDOG_CNT_CNTHIGH_MASK                    (0xFF00U)
#define WDOG_CNT_CNTHIGH_SHIFT                   (8U)
/*! CNTHIGH - Counter High Byte */
#define WDOG_CNT_CNTHIGH(x)                      (((uint32_t)(((uint32_t)(x)) << WDOG_CNT_CNTHIGH_SHIFT)) & WDOG_CNT_CNTHIGH_MASK)
/*! @} */

/*! @name TOVAL - WDOG Timeout Value */
/*! @{ */

#define WDOG_TOVAL_TOVALLOW_MASK                 (0xFFU)
#define WDOG_TOVAL_TOVALLOW_SHIFT                (0U)
/*! TOVALLOW - Timeout Value Low */
#define WDOG_TOVAL_TOVALLOW(x)                   (((uint32_t)(((uint32_t)(x)) << WDOG_TOVAL_TOVALLOW_SHIFT)) & WDOG_TOVAL_TOVALLOW_MASK)

#define WDOG_TOVAL_TOVALHIGH_MASK                (0xFF00U)
#define WDOG_TOVAL_TOVALHIGH_SHIFT               (8U)
/*! TOVALHIGH - Timeout Value High */
#define WDOG_TOVAL_TOVALHIGH(x)                  (((uint32_t)(((uint32_t)(x)) << WDOG_TOVAL_TOVALHIGH_SHIFT)) & WDOG_TOVAL_TOVALHIGH_MASK)
/*! @} */

/*! @name WIN - Watchdog Window */
/*! @{ */

#define WDOG_WIN_WINLOW_MASK                     (0xFFU)
#define WDOG_WIN_WINLOW_SHIFT                    (0U)
/*! WINLOW - Low Byte */
#define WDOG_WIN_WINLOW(x)                       (((uint32_t)(((uint32_t)(x)) << WDOG_WIN_WINLOW_SHIFT)) & WDOG_WIN_WINLOW_MASK)

#define WDOG_WIN_WINHIGH_MASK                    (0xFF00U)
#define WDOG_WIN_WINHIGH_SHIFT                   (8U)
/*! WINHIGH - High Byte */
#define WDOG_WIN_WINHIGH(x)                      (((uint32_t)(((uint32_t)(x)) << WDOG_WIN_WINHIGH_SHIFT)) & WDOG_WIN_WINHIGH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


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


#endif  /* PERI_WDOG_H_ */

