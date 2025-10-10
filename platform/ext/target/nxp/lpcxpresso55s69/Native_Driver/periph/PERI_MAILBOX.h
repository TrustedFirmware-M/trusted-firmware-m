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
**         CMSIS Peripheral Access Layer for MAILBOX
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
 * @file PERI_MAILBOX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MAILBOX
 *
 * CMSIS Peripheral Access Layer for MAILBOX
 */

#if !defined(PERI_MAILBOX_H_)
#define PERI_MAILBOX_H_                          /**< Symbol preventing repeated inclusion */

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
   -- MAILBOX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAILBOX_Peripheral_Access_Layer MAILBOX Peripheral Access Layer
 * @{
 */

/** MAILBOX - Size of Registers Arrays */
#define MAILBOX_MBOXIRQ_COUNT                     2u

/** MAILBOX - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t IRQ;                               /**< Interrupt request register for the Cortex-M0+ CPU., array offset: 0x0, array step: 0x10 */
    __O  uint32_t IRQSET;                            /**< Set bits in IRQ0, array offset: 0x4, array step: 0x10 */
    __O  uint32_t IRQCLR;                            /**< Clear bits in IRQ0, array offset: 0x8, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } MBOXIRQ[MAILBOX_MBOXIRQ_COUNT];
       uint8_t RESERVED_0[216];
  __IO uint32_t MUTEX;                             /**< Mutual exclusion register[1], offset: 0xF8 */
} MAILBOX_Type;

/* ----------------------------------------------------------------------------
   -- MAILBOX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAILBOX_Register_Masks MAILBOX Register Masks
 * @{
 */

/*! @name MBOXIRQ_IRQ - Interrupt request register for the Cortex-M0+ CPU. */
/*! @{ */

#define MAILBOX_MBOXIRQ_IRQ_INTREQ_MASK          (0xFFFFFFFFU)
#define MAILBOX_MBOXIRQ_IRQ_INTREQ_SHIFT         (0U)
/*! INTREQ - If any bit is set, an interrupt request is sent to the Cortex-M0+ interrupt controller. */
#define MAILBOX_MBOXIRQ_IRQ_INTREQ(x)            (((uint32_t)(((uint32_t)(x)) << MAILBOX_MBOXIRQ_IRQ_INTREQ_SHIFT)) & MAILBOX_MBOXIRQ_IRQ_INTREQ_MASK)
/*! @} */

/* The count of MAILBOX_MBOXIRQ_IRQ */
#define MAILBOX_MBOXIRQ_IRQ_COUNT                (2U)

/*! @name MBOXIRQ_IRQSET - Set bits in IRQ0 */
/*! @{ */

#define MAILBOX_MBOXIRQ_IRQSET_INTREQSET_MASK    (0xFFFFFFFFU)
#define MAILBOX_MBOXIRQ_IRQSET_INTREQSET_SHIFT   (0U)
/*! INTREQSET - Writing 1 sets the corresponding bit in the IRQ0 register. */
#define MAILBOX_MBOXIRQ_IRQSET_INTREQSET(x)      (((uint32_t)(((uint32_t)(x)) << MAILBOX_MBOXIRQ_IRQSET_INTREQSET_SHIFT)) & MAILBOX_MBOXIRQ_IRQSET_INTREQSET_MASK)
/*! @} */

/* The count of MAILBOX_MBOXIRQ_IRQSET */
#define MAILBOX_MBOXIRQ_IRQSET_COUNT             (2U)

/*! @name MBOXIRQ_IRQCLR - Clear bits in IRQ0 */
/*! @{ */

#define MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_MASK    (0xFFFFFFFFU)
#define MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_SHIFT   (0U)
/*! INTREQCLR - Writing 1 clears the corresponding bit in the IRQ0 register. */
#define MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR(x)      (((uint32_t)(((uint32_t)(x)) << MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_SHIFT)) & MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_MASK)
/*! @} */

/* The count of MAILBOX_MBOXIRQ_IRQCLR */
#define MAILBOX_MBOXIRQ_IRQCLR_COUNT             (2U)

/*! @name MUTEX - Mutual exclusion register[1] */
/*! @{ */

#define MAILBOX_MUTEX_EX_MASK                    (0x1U)
#define MAILBOX_MUTEX_EX_SHIFT                   (0U)
/*! EX - Cleared when read, set when written. See usage description above. */
#define MAILBOX_MUTEX_EX(x)                      (((uint32_t)(((uint32_t)(x)) << MAILBOX_MUTEX_EX_SHIFT)) & MAILBOX_MUTEX_EX_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MAILBOX_Register_Masks */


/*!
 * @}
 */ /* end of group MAILBOX_Peripheral_Access_Layer */


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


#endif  /* PERI_MAILBOX_H_ */

