/*
** ###################################################################
**     Processors:          MCXN247VAB
**                          MCXN247VDF
**                          MCXN247VKL
**                          MCXN247VPB
**                          MCXN526VDF_cm33_core0
**                          MCXN526VDF_cm33_core1
**                          MCXN526VKL_cm33_core0
**                          MCXN526VKL_cm33_core1
**                          MCXN527VAB_cm33_core0
**                          MCXN527VAB_cm33_core1
**                          MCXN527VDF_cm33_core0
**                          MCXN527VDF_cm33_core1
**                          MCXN527VKL_cm33_core0
**                          MCXN527VKL_cm33_core1
**                          MCXN536VAB_cm33_core0
**                          MCXN536VAB_cm33_core1
**                          MCXN536VDF_cm33_core0
**                          MCXN536VDF_cm33_core1
**                          MCXN536VKL_cm33_core0
**                          MCXN536VKL_cm33_core1
**                          MCXN536VPB_cm33_core0
**                          MCXN536VPB_cm33_core1
**                          MCXN537VAB_cm33_core0
**                          MCXN537VAB_cm33_core1
**                          MCXN537VDF_cm33_core0
**                          MCXN537VDF_cm33_core1
**                          MCXN537VKL_cm33_core0
**                          MCXN537VKL_cm33_core1
**                          MCXN537VPB_cm33_core0
**                          MCXN537VPB_cm33_core1
**                          MCXN546VAB_cm33_core0
**                          MCXN546VAB_cm33_core1
**                          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VAB_cm33_core0
**                          MCXN547VAB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN556SCDF_cm33_core0
**                          MCXN556SCDF_cm33_core1
**                          MCXN946VAB_cm33_core0
**                          MCXN946VAB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VAB_cm33_core0
**                          MCXN947VAB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250811
**
**     Abstract:
**         CMSIS Peripheral Access Layer for UTICK
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_UTICK.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for UTICK
 *
 * CMSIS Peripheral Access Layer for UTICK
 */

#if !defined(PERI_UTICK_H_)
#define PERI_UTICK_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN247VAB) || defined(CPU_MCXN247VDF) || defined(CPU_MCXN247VKL) || defined(CPU_MCXN247VPB))
#include "MCXN247_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core0) || defined(CPU_MCXN526VKL_cm33_core0))
#include "MCXN526_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core1) || defined(CPU_MCXN526VKL_cm33_core1))
#include "MCXN526_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core0) || defined(CPU_MCXN527VDF_cm33_core0) || defined(CPU_MCXN527VKL_cm33_core0))
#include "MCXN527_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core1) || defined(CPU_MCXN527VDF_cm33_core1) || defined(CPU_MCXN527VKL_cm33_core1))
#include "MCXN527_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core0) || defined(CPU_MCXN536VDF_cm33_core0) || defined(CPU_MCXN536VKL_cm33_core0) || defined(CPU_MCXN536VPB_cm33_core0))
#include "MCXN536_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core1) || defined(CPU_MCXN536VDF_cm33_core1) || defined(CPU_MCXN536VKL_cm33_core1) || defined(CPU_MCXN536VPB_cm33_core1))
#include "MCXN536_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core0) || defined(CPU_MCXN537VDF_cm33_core0) || defined(CPU_MCXN537VKL_cm33_core0) || defined(CPU_MCXN537VPB_cm33_core0))
#include "MCXN537_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core1) || defined(CPU_MCXN537VDF_cm33_core1) || defined(CPU_MCXN537VKL_cm33_core1) || defined(CPU_MCXN537VPB_cm33_core1))
#include "MCXN537_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core0) || defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core1) || defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core0) || defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core1) || defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core0))
#include "MCXN556S_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core1))
#include "MCXN556S_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core0) || defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core1) || defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core0) || defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core1) || defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
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
   -- UTICK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UTICK_Peripheral_Access_Layer UTICK Peripheral Access Layer
 * @{
 */

/** UTICK - Size of Registers Arrays */
#define UTICK_CAP_COUNT                           4u

/** UTICK - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control, offset: 0x0 */
  __IO uint32_t STAT;                              /**< Status, offset: 0x4 */
  __IO uint32_t CFG;                               /**< Capture Configuration, offset: 0x8 */
  __O  uint32_t CAPCLR;                            /**< Capture Clear, offset: 0xC */
  __I  uint32_t CAP[UTICK_CAP_COUNT];              /**< Capture, array offset: 0x10, array step: 0x4 */
} UTICK_Type;

/* ----------------------------------------------------------------------------
   -- UTICK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UTICK_Register_Masks UTICK Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define UTICK_CTRL_DELAYVAL_MASK                 (0x7FFFFFFFU)
#define UTICK_CTRL_DELAYVAL_SHIFT                (0U)
/*! DELAYVAL - Tick Interval
 *  0b0000000000000000000000000000000..
 *  *..Clock cycles as defined in the description
 */
#define UTICK_CTRL_DELAYVAL(x)                   (((uint32_t)(((uint32_t)(x)) << UTICK_CTRL_DELAYVAL_SHIFT)) & UTICK_CTRL_DELAYVAL_MASK)

#define UTICK_CTRL_REPEAT_MASK                   (0x80000000U)
#define UTICK_CTRL_REPEAT_SHIFT                  (31U)
/*! REPEAT - Repeat Delay
 *  0b0..One-time delay
 *  0b1..Delay repeats continuously
 */
#define UTICK_CTRL_REPEAT(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CTRL_REPEAT_SHIFT)) & UTICK_CTRL_REPEAT_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define UTICK_STAT_INTR_MASK                     (0x1U)
#define UTICK_STAT_INTR_SHIFT                    (0U)
/*! INTR - Interrupt Flag
 *  0b0..Not pending
 *  0b1..Pending
 */
#define UTICK_STAT_INTR(x)                       (((uint32_t)(((uint32_t)(x)) << UTICK_STAT_INTR_SHIFT)) & UTICK_STAT_INTR_MASK)

#define UTICK_STAT_ACTIVE_MASK                   (0x2U)
#define UTICK_STAT_ACTIVE_SHIFT                  (1U)
/*! ACTIVE - Timer Active Flag
 *  0b0..Inactive (stopped)
 *  0b1..Active
 */
#define UTICK_STAT_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_STAT_ACTIVE_SHIFT)) & UTICK_STAT_ACTIVE_MASK)
/*! @} */

/*! @name CFG - Capture Configuration */
/*! @{ */

#define UTICK_CFG_CAPEN0_MASK                    (0x1U)
#define UTICK_CFG_CAPEN0_SHIFT                   (0U)
/*! CAPEN0 - Enable Capture 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN0(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN0_SHIFT)) & UTICK_CFG_CAPEN0_MASK)

#define UTICK_CFG_CAPEN1_MASK                    (0x2U)
#define UTICK_CFG_CAPEN1_SHIFT                   (1U)
/*! CAPEN1 - Enable Capture 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN1(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN1_SHIFT)) & UTICK_CFG_CAPEN1_MASK)

#define UTICK_CFG_CAPEN2_MASK                    (0x4U)
#define UTICK_CFG_CAPEN2_SHIFT                   (2U)
/*! CAPEN2 - Enable Capture 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN2(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN2_SHIFT)) & UTICK_CFG_CAPEN2_MASK)

#define UTICK_CFG_CAPEN3_MASK                    (0x8U)
#define UTICK_CFG_CAPEN3_SHIFT                   (3U)
/*! CAPEN3 - Enable Capture 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN3(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN3_SHIFT)) & UTICK_CFG_CAPEN3_MASK)

#define UTICK_CFG_CAPPOL0_MASK                   (0x100U)
#define UTICK_CFG_CAPPOL0_SHIFT                  (8U)
/*! CAPPOL0 - Capture Polarity 0
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL0(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL0_SHIFT)) & UTICK_CFG_CAPPOL0_MASK)

#define UTICK_CFG_CAPPOL1_MASK                   (0x200U)
#define UTICK_CFG_CAPPOL1_SHIFT                  (9U)
/*! CAPPOL1 - Capture-Polarity 1
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL1(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL1_SHIFT)) & UTICK_CFG_CAPPOL1_MASK)

#define UTICK_CFG_CAPPOL2_MASK                   (0x400U)
#define UTICK_CFG_CAPPOL2_SHIFT                  (10U)
/*! CAPPOL2 - Capture Polarity 2
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL2(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL2_SHIFT)) & UTICK_CFG_CAPPOL2_MASK)

#define UTICK_CFG_CAPPOL3_MASK                   (0x800U)
#define UTICK_CFG_CAPPOL3_SHIFT                  (11U)
/*! CAPPOL3 - Capture Polarity 3
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL3(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL3_SHIFT)) & UTICK_CFG_CAPPOL3_MASK)
/*! @} */

/*! @name CAPCLR - Capture Clear */
/*! @{ */

#define UTICK_CAPCLR_CAPCLR0_MASK                (0x1U)
#define UTICK_CAPCLR_CAPCLR0_SHIFT               (0U)
/*! CAPCLR0 - Clear Capture 0
 *  0b0..Does nothing
 *  0b1..Clears the CAP0 register value
 */
#define UTICK_CAPCLR_CAPCLR0(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR0_SHIFT)) & UTICK_CAPCLR_CAPCLR0_MASK)

#define UTICK_CAPCLR_CAPCLR1_MASK                (0x2U)
#define UTICK_CAPCLR_CAPCLR1_SHIFT               (1U)
/*! CAPCLR1 - Clear Capture 1
 *  0b0..Does nothing
 *  0b1..Clears the CAP1 register value
 */
#define UTICK_CAPCLR_CAPCLR1(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR1_SHIFT)) & UTICK_CAPCLR_CAPCLR1_MASK)

#define UTICK_CAPCLR_CAPCLR2_MASK                (0x4U)
#define UTICK_CAPCLR_CAPCLR2_SHIFT               (2U)
/*! CAPCLR2 - Clear Capture 2
 *  0b0..Does nothing
 *  0b1..Clears the CAP2 register value
 */
#define UTICK_CAPCLR_CAPCLR2(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR2_SHIFT)) & UTICK_CAPCLR_CAPCLR2_MASK)

#define UTICK_CAPCLR_CAPCLR3_MASK                (0x8U)
#define UTICK_CAPCLR_CAPCLR3_SHIFT               (3U)
/*! CAPCLR3 - Clear Capture 3
 *  0b0..Does nothing
 *  0b1..Clears the CAP3 register value
 */
#define UTICK_CAPCLR_CAPCLR3(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR3_SHIFT)) & UTICK_CAPCLR_CAPCLR3_MASK)
/*! @} */

/*! @name CAP - Capture */
/*! @{ */

#define UTICK_CAP_CAP_VALUE_MASK                 (0x7FFFFFFFU)
#define UTICK_CAP_CAP_VALUE_SHIFT                (0U)
/*! CAP_VALUE - Captured Value for the Related Capture Event */
#define UTICK_CAP_CAP_VALUE(x)                   (((uint32_t)(((uint32_t)(x)) << UTICK_CAP_CAP_VALUE_SHIFT)) & UTICK_CAP_CAP_VALUE_MASK)

#define UTICK_CAP_VALID_MASK                     (0x80000000U)
#define UTICK_CAP_VALID_SHIFT                    (31U)
/*! VALID - Captured Value Valid Flag
 *  0b0..Valid value not captured
 *  0b1..Valid value captured
 */
#define UTICK_CAP_VALID(x)                       (((uint32_t)(((uint32_t)(x)) << UTICK_CAP_VALID_SHIFT)) & UTICK_CAP_VALID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UTICK_Register_Masks */


/*!
 * @}
 */ /* end of group UTICK_Peripheral_Access_Layer */


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


#endif  /* PERI_UTICK_H_ */

