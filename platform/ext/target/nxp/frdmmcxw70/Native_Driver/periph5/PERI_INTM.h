/*
** ###################################################################
**     Processors:          MCXW70ACMFT
**                          MCXW70ACMMP
**                          MCXW70ADMFT
**                          MCXW70ADMMP
**
**     Version:             rev. 1.0, 2026-01-09
**     Build:               b260813
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INTM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-01-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_INTM.h
 * @version 1.0
 * @date 2026-01-09
 * @brief CMSIS Peripheral Access Layer for INTM
 *
 * CMSIS Peripheral Access Layer for INTM
 */

#if !defined(PERI_INTM_H_)
#define PERI_INTM_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW70ACMFT) || defined(CPU_MCXW70ACMMP))
#include "MCXW70AC_COMMON.h"
#elif (defined(CPU_MCXW70ADMFT) || defined(CPU_MCXW70ADMMP))
#include "MCXW70AD_COMMON.h"
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
   -- INTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTM_Peripheral_Access_Layer INTM Peripheral Access Layer
 * @{
 */

/** INTM - Size of Registers Arrays */
#define INTM_MON_COUNT                            4u

/** INTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t INTM_MM;                           /**< Monitor Mode, offset: 0x0 */
  __O  uint32_t INTM_IACK;                         /**< Interrupt Acknowledge, offset: 0x4 */
  struct {                                         /* offset: 0x8, array step: 0x10 */
    __IO uint32_t INTM_IRQSEL;                       /**< Interrupt Request Select for Monitor 0..Interrupt Request Select for Monitor 3, array offset: 0x8, array step: 0x10 */
    __IO uint32_t INTM_LATENCY;                      /**< Interrupt Latency for Monitor 0..Interrupt Latency for Monitor 3, array offset: 0xC, array step: 0x10 */
    __IO uint32_t INTM_TIMER;                        /**< Timer for Monitor 0..Timer for Monitor 3, array offset: 0x10, array step: 0x10 */
    __I  uint32_t INTM_STATUS;                       /**< Status for Monitor 0..Status for Monitor 3, array offset: 0x14, array step: 0x10 */
  } MON[INTM_MON_COUNT];
} INTM_Type;

/* ----------------------------------------------------------------------------
   -- INTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTM_Register_Masks INTM Register Masks
 * @{
 */

/*! @name INTM_MM - Monitor Mode */
/*! @{ */

#define INTM_INTM_MM_MM_MASK                     (0x1U)
#define INTM_INTM_MM_MM_SHIFT                    (0U)
/*! MM - Monitor Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define INTM_INTM_MM_MM(x)                       (((uint32_t)(((uint32_t)(x)) << INTM_INTM_MM_MM_SHIFT)) & INTM_INTM_MM_MM_MASK)
/*! @} */

/*! @name INTM_IACK - Interrupt Acknowledge */
/*! @{ */

#define INTM_INTM_IACK_IRQ_MASK                  (0x3FFU)
#define INTM_INTM_IACK_IRQ_SHIFT                 (0U)
/*! IRQ - Interrupt Request */
#define INTM_INTM_IACK_IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << INTM_INTM_IACK_IRQ_SHIFT)) & INTM_INTM_IACK_IRQ_MASK)
/*! @} */

/*! @name MON_INTM_IRQSEL - Interrupt Request Select for Monitor 0..Interrupt Request Select for Monitor 3 */
/*! @{ */

#define INTM_MON_INTM_IRQSEL_IRQ_MASK            (0x3FFU)
#define INTM_MON_INTM_IRQSEL_IRQ_SHIFT           (0U)
/*! IRQ - Interrupt Request */
#define INTM_MON_INTM_IRQSEL_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << INTM_MON_INTM_IRQSEL_IRQ_SHIFT)) & INTM_MON_INTM_IRQSEL_IRQ_MASK)
/*! @} */

/* The count of INTM_MON_INTM_IRQSEL */
#define INTM_MON_INTM_IRQSEL_COUNT               (4U)

/*! @name MON_INTM_LATENCY - Interrupt Latency for Monitor 0..Interrupt Latency for Monitor 3 */
/*! @{ */

#define INTM_MON_INTM_LATENCY_LAT_MASK           (0xFFFFFFU)
#define INTM_MON_INTM_LATENCY_LAT_SHIFT          (0U)
/*! LAT - Latency */
#define INTM_MON_INTM_LATENCY_LAT(x)             (((uint32_t)(((uint32_t)(x)) << INTM_MON_INTM_LATENCY_LAT_SHIFT)) & INTM_MON_INTM_LATENCY_LAT_MASK)
/*! @} */

/* The count of INTM_MON_INTM_LATENCY */
#define INTM_MON_INTM_LATENCY_COUNT              (4U)

/*! @name MON_INTM_TIMER - Timer for Monitor 0..Timer for Monitor 3 */
/*! @{ */

#define INTM_MON_INTM_TIMER_TIMER_MASK           (0xFFFFFFU)
#define INTM_MON_INTM_TIMER_TIMER_SHIFT          (0U)
/*! TIMER - Timer */
#define INTM_MON_INTM_TIMER_TIMER(x)             (((uint32_t)(((uint32_t)(x)) << INTM_MON_INTM_TIMER_TIMER_SHIFT)) & INTM_MON_INTM_TIMER_TIMER_MASK)
/*! @} */

/* The count of INTM_MON_INTM_TIMER */
#define INTM_MON_INTM_TIMER_COUNT                (4U)

/*! @name MON_INTM_STATUS - Status for Monitor 0..Status for Monitor 3 */
/*! @{ */

#define INTM_MON_INTM_STATUS_STATUS_MASK         (0x1U)
#define INTM_MON_INTM_STATUS_STATUS_SHIFT        (0U)
/*! STATUS - Monitor status
 *  0b0..Did not exceed
 *  0b1..Exceeded
 */
#define INTM_MON_INTM_STATUS_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << INTM_MON_INTM_STATUS_STATUS_SHIFT)) & INTM_MON_INTM_STATUS_STATUS_MASK)
/*! @} */

/* The count of INTM_MON_INTM_STATUS */
#define INTM_MON_INTM_STATUS_COUNT               (4U)


/*!
 * @}
 */ /* end of group INTM_Register_Masks */


/*!
 * @}
 */ /* end of group INTM_Peripheral_Access_Layer */


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


#endif  /* PERI_INTM_H_ */

