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
**         CMSIS Peripheral Access Layer for SEMA42
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
 * @file PERI_SEMA42.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for SEMA42
 *
 * CMSIS Peripheral Access Layer for SEMA42
 */

#if !defined(PERI_SEMA42_H_)
#define PERI_SEMA42_H_                           /**< Symbol preventing repeated inclusion */

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
   -- SEMA42 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA42_Peripheral_Access_Layer SEMA42 Peripheral Access Layer
 * @{
 */

/** SEMA42 - Register Layout Typedef */
typedef struct {
  __IO uint8_t GATE3;                              /**< Gate, offset: 0x0 */
  __IO uint8_t GATE2;                              /**< Gate, offset: 0x1 */
  __IO uint8_t GATE1;                              /**< Gate, offset: 0x2 */
  __IO uint8_t GATE0;                              /**< Gate, offset: 0x3 */
  __IO uint8_t GATE7;                              /**< Gate, offset: 0x4 */
  __IO uint8_t GATE6;                              /**< Gate, offset: 0x5 */
  __IO uint8_t GATE5;                              /**< Gate, offset: 0x6 */
  __IO uint8_t GATE4;                              /**< Gate, offset: 0x7 */
  __IO uint8_t GATE11;                             /**< Gate, offset: 0x8 */
  __IO uint8_t GATE10;                             /**< Gate, offset: 0x9 */
  __IO uint8_t GATE9;                              /**< Gate, offset: 0xA */
  __IO uint8_t GATE8;                              /**< Gate, offset: 0xB */
  __IO uint8_t GATE15;                             /**< Gate, offset: 0xC */
  __IO uint8_t GATE14;                             /**< Gate, offset: 0xD */
  __IO uint8_t GATE13;                             /**< Gate, offset: 0xE */
  __IO uint8_t GATE12;                             /**< Gate, offset: 0xF */
       uint8_t RESERVED_0[50];
  union {                                          /* offset: 0x42 */
    __I  uint16_t RSTGT_R;                           /**< Reset Gate Read, offset: 0x42 */
    __O  uint16_t RSTGT_W;                           /**< Reset Gate Write, offset: 0x42 */
  };
} SEMA42_Type;

/* ----------------------------------------------------------------------------
   -- SEMA42 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA42_Register_Masks SEMA42 Register Masks
 * @{
 */

/*! @name GATE3 - Gate */
/*! @{ */

#define SEMA42_GATE3_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE3_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE3_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE3_GTFSM_SHIFT)) & SEMA42_GATE3_GTFSM_MASK)
/*! @} */

/*! @name GATE2 - Gate */
/*! @{ */

#define SEMA42_GATE2_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE2_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE2_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE2_GTFSM_SHIFT)) & SEMA42_GATE2_GTFSM_MASK)
/*! @} */

/*! @name GATE1 - Gate */
/*! @{ */

#define SEMA42_GATE1_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE1_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE1_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE1_GTFSM_SHIFT)) & SEMA42_GATE1_GTFSM_MASK)
/*! @} */

/*! @name GATE0 - Gate */
/*! @{ */

#define SEMA42_GATE0_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE0_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE0_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE0_GTFSM_SHIFT)) & SEMA42_GATE0_GTFSM_MASK)
/*! @} */

/*! @name GATE7 - Gate */
/*! @{ */

#define SEMA42_GATE7_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE7_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE7_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE7_GTFSM_SHIFT)) & SEMA42_GATE7_GTFSM_MASK)
/*! @} */

/*! @name GATE6 - Gate */
/*! @{ */

#define SEMA42_GATE6_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE6_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE6_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE6_GTFSM_SHIFT)) & SEMA42_GATE6_GTFSM_MASK)
/*! @} */

/*! @name GATE5 - Gate */
/*! @{ */

#define SEMA42_GATE5_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE5_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE5_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE5_GTFSM_SHIFT)) & SEMA42_GATE5_GTFSM_MASK)
/*! @} */

/*! @name GATE4 - Gate */
/*! @{ */

#define SEMA42_GATE4_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE4_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE4_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE4_GTFSM_SHIFT)) & SEMA42_GATE4_GTFSM_MASK)
/*! @} */

/*! @name GATE11 - Gate */
/*! @{ */

#define SEMA42_GATE11_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE11_GTFSM_SHIFT                (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE11_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE11_GTFSM_SHIFT)) & SEMA42_GATE11_GTFSM_MASK)
/*! @} */

/*! @name GATE10 - Gate */
/*! @{ */

#define SEMA42_GATE10_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE10_GTFSM_SHIFT                (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE10_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE10_GTFSM_SHIFT)) & SEMA42_GATE10_GTFSM_MASK)
/*! @} */

/*! @name GATE9 - Gate */
/*! @{ */

#define SEMA42_GATE9_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE9_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE9_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE9_GTFSM_SHIFT)) & SEMA42_GATE9_GTFSM_MASK)
/*! @} */

/*! @name GATE8 - Gate */
/*! @{ */

#define SEMA42_GATE8_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE8_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE8_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE8_GTFSM_SHIFT)) & SEMA42_GATE8_GTFSM_MASK)
/*! @} */

/*! @name GATE15 - Gate */
/*! @{ */

#define SEMA42_GATE15_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE15_GTFSM_SHIFT                (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE15_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE15_GTFSM_SHIFT)) & SEMA42_GATE15_GTFSM_MASK)
/*! @} */

/*! @name GATE14 - Gate */
/*! @{ */

#define SEMA42_GATE14_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE14_GTFSM_SHIFT                (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE14_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE14_GTFSM_SHIFT)) & SEMA42_GATE14_GTFSM_MASK)
/*! @} */

/*! @name GATE13 - Gate */
/*! @{ */

#define SEMA42_GATE13_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE13_GTFSM_SHIFT                (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE13_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE13_GTFSM_SHIFT)) & SEMA42_GATE13_GTFSM_MASK)
/*! @} */

/*! @name GATE12 - Gate */
/*! @{ */

#define SEMA42_GATE12_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE12_GTFSM_SHIFT                (0U)
/*! GTFSM - Gate Finite State Machine
 *  0b0000..The gate is unlocked (free).
 *  0b0001..Domain 0 locked the gate.
 *  0b0010..Domain 1 locked the gate.
 *  0b0011..Domain 2 locked the gate.
 *  0b0100..Domain 3 locked the gate.
 *  0b0101..Domain 4 locked the gate.
 *  0b0110..Domain 5 locked the gate.
 *  0b0111..Domain 6 locked the gate.
 *  0b1000..Domain 7 locked the gate.
 *  0b1001..Domain 8 locked the gate.
 *  0b1010..Domain 9 locked the gate.
 *  0b1011..Domain 10 locked the gate.
 *  0b1100..Domain 11 locked the gate.
 *  0b1101..Domain 12 locked the gate.
 *  0b1110..Domain 13 locked the gate.
 *  0b1111..Domain 14 locked the gate.
 */
#define SEMA42_GATE12_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE12_GTFSM_SHIFT)) & SEMA42_GATE12_GTFSM_MASK)
/*! @} */

/*! @name RSTGT_R - Reset Gate Read */
/*! @{ */

#define SEMA42_RSTGT_R_RSTGTN_MASK               (0xFFU)
#define SEMA42_RSTGT_R_RSTGTN_SHIFT              (0U)
/*! RSTGTN - Reset Gate Number */
#define SEMA42_RSTGT_R_RSTGTN(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_R_RSTGTN_SHIFT)) & SEMA42_RSTGT_R_RSTGTN_MASK)

#define SEMA42_RSTGT_R_RSTGMS_MASK               (0xF00U)
#define SEMA42_RSTGT_R_RSTGMS_SHIFT              (8U)
/*! RSTGMS - Reset Gate Domain */
#define SEMA42_RSTGT_R_RSTGMS(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_R_RSTGMS_SHIFT)) & SEMA42_RSTGT_R_RSTGMS_MASK)

#define SEMA42_RSTGT_R_RSTGSM_MASK               (0x3000U)
#define SEMA42_RSTGT_R_RSTGSM_SHIFT              (12U)
/*! RSTGSM - Reset Gate Finite State Machine
 *  0b00..Idle, waiting for the first data pattern write.
 *  0b01..Waiting for the second data pattern write
 *  0b10..The 2-write sequence has completed. Generate the specified gate reset(s). After the reset is performed,
 *        this machine returns to the idle (waiting for first data pattern write) state.
 *  0b11..This state encoding is never used and therefore reserved.
 */
#define SEMA42_RSTGT_R_RSTGSM(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_R_RSTGSM_SHIFT)) & SEMA42_RSTGT_R_RSTGSM_MASK)
/*! @} */

/*! @name RSTGT_W - Reset Gate Write */
/*! @{ */

#define SEMA42_RSTGT_W_RSTGTN_MASK               (0xFFU)
#define SEMA42_RSTGT_W_RSTGTN_SHIFT              (0U)
/*! RSTGTN - Reset Gate Number */
#define SEMA42_RSTGT_W_RSTGTN(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_W_RSTGTN_SHIFT)) & SEMA42_RSTGT_W_RSTGTN_MASK)

#define SEMA42_RSTGT_W_RSTGDP_MASK               (0xFF00U)
#define SEMA42_RSTGT_W_RSTGDP_SHIFT              (8U)
/*! RSTGDP - Reset Gate Data Pattern */
#define SEMA42_RSTGT_W_RSTGDP(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_W_RSTGDP_SHIFT)) & SEMA42_RSTGT_W_RSTGDP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SEMA42_Register_Masks */


/*!
 * @}
 */ /* end of group SEMA42_Peripheral_Access_Layer */


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


#endif  /* PERI_SEMA42_H_ */

