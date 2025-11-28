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
**         CMSIS Peripheral Access Layer for SEMA42
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
 * @file PERI_SEMA42.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SEMA42
 *
 * CMSIS Peripheral Access Layer for SEMA42
 */

#if !defined(PERI_SEMA42_H_)
#define PERI_SEMA42_H_                           /**< Symbol preventing repeated inclusion */

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
  __IO uint8_t GATE19;                             /**< Gate, offset: 0x10 */
  __IO uint8_t GATE18;                             /**< Gate, offset: 0x11 */
  __IO uint8_t GATE17;                             /**< Gate, offset: 0x12 */
  __IO uint8_t GATE16;                             /**< Gate, offset: 0x13 */
  __IO uint8_t GATE23;                             /**< Gate, offset: 0x14 */
  __IO uint8_t GATE22;                             /**< Gate, offset: 0x15 */
  __IO uint8_t GATE21;                             /**< Gate, offset: 0x16 */
  __IO uint8_t GATE20;                             /**< Gate, offset: 0x17 */
  __IO uint8_t GATE27;                             /**< Gate, offset: 0x18 */
  __IO uint8_t GATE26;                             /**< Gate, offset: 0x19 */
  __IO uint8_t GATE25;                             /**< Gate, offset: 0x1A */
  __IO uint8_t GATE24;                             /**< Gate, offset: 0x1B */
  __IO uint8_t GATE31;                             /**< Gate, offset: 0x1C */
  __IO uint8_t GATE30;                             /**< Gate, offset: 0x1D */
  __IO uint8_t GATE29;                             /**< Gate, offset: 0x1E */
  __IO uint8_t GATE28;                             /**< Gate, offset: 0x1F */
  __IO uint8_t GATE35;                             /**< Gate, offset: 0x20 */
  __IO uint8_t GATE34;                             /**< Gate, offset: 0x21 */
  __IO uint8_t GATE33;                             /**< Gate, offset: 0x22 */
  __IO uint8_t GATE32;                             /**< Gate, offset: 0x23 */
  __IO uint8_t GATE39;                             /**< Gate, offset: 0x24 */
  __IO uint8_t GATE38;                             /**< Gate, offset: 0x25 */
  __IO uint8_t GATE37;                             /**< Gate, offset: 0x26 */
  __IO uint8_t GATE36;                             /**< Gate, offset: 0x27 */
  __IO uint8_t GATE43;                             /**< Gate, offset: 0x28 */
  __IO uint8_t GATE42;                             /**< Gate, offset: 0x29 */
  __IO uint8_t GATE41;                             /**< Gate, offset: 0x2A */
  __IO uint8_t GATE40;                             /**< Gate, offset: 0x2B */
  __IO uint8_t GATE47;                             /**< Gate, offset: 0x2C */
  __IO uint8_t GATE46;                             /**< Gate, offset: 0x2D */
  __IO uint8_t GATE45;                             /**< Gate, offset: 0x2E */
  __IO uint8_t GATE44;                             /**< Gate, offset: 0x2F */
  __IO uint8_t GATE51;                             /**< Gate, offset: 0x30 */
  __IO uint8_t GATE50;                             /**< Gate, offset: 0x31 */
  __IO uint8_t GATE49;                             /**< Gate, offset: 0x32 */
  __IO uint8_t GATE48;                             /**< Gate, offset: 0x33 */
  __IO uint8_t GATE55;                             /**< Gate, offset: 0x34 */
  __IO uint8_t GATE54;                             /**< Gate, offset: 0x35 */
  __IO uint8_t GATE53;                             /**< Gate, offset: 0x36 */
  __IO uint8_t GATE52;                             /**< Gate, offset: 0x37 */
  __IO uint8_t GATE59;                             /**< Gate, offset: 0x38 */
  __IO uint8_t GATE58;                             /**< Gate, offset: 0x39 */
  __IO uint8_t GATE57;                             /**< Gate, offset: 0x3A */
  __IO uint8_t GATE56;                             /**< Gate, offset: 0x3B */
  __IO uint8_t GATE63;                             /**< Gate, offset: 0x3C */
  __IO uint8_t GATE62;                             /**< Gate, offset: 0x3D */
  __IO uint8_t GATE61;                             /**< Gate, offset: 0x3E */
  __IO uint8_t GATE60;                             /**< Gate, offset: 0x3F */
       uint8_t RESERVED_0[2];
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

/*! @name GATE19 - Gate */
/*! @{ */

#define SEMA42_GATE19_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE19_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE19_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE19_GTFSM_SHIFT)) & SEMA42_GATE19_GTFSM_MASK)
/*! @} */

/*! @name GATE18 - Gate */
/*! @{ */

#define SEMA42_GATE18_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE18_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE18_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE18_GTFSM_SHIFT)) & SEMA42_GATE18_GTFSM_MASK)
/*! @} */

/*! @name GATE17 - Gate */
/*! @{ */

#define SEMA42_GATE17_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE17_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE17_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE17_GTFSM_SHIFT)) & SEMA42_GATE17_GTFSM_MASK)
/*! @} */

/*! @name GATE16 - Gate */
/*! @{ */

#define SEMA42_GATE16_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE16_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE16_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE16_GTFSM_SHIFT)) & SEMA42_GATE16_GTFSM_MASK)
/*! @} */

/*! @name GATE23 - Gate */
/*! @{ */

#define SEMA42_GATE23_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE23_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE23_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE23_GTFSM_SHIFT)) & SEMA42_GATE23_GTFSM_MASK)
/*! @} */

/*! @name GATE22 - Gate */
/*! @{ */

#define SEMA42_GATE22_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE22_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE22_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE22_GTFSM_SHIFT)) & SEMA42_GATE22_GTFSM_MASK)
/*! @} */

/*! @name GATE21 - Gate */
/*! @{ */

#define SEMA42_GATE21_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE21_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE21_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE21_GTFSM_SHIFT)) & SEMA42_GATE21_GTFSM_MASK)
/*! @} */

/*! @name GATE20 - Gate */
/*! @{ */

#define SEMA42_GATE20_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE20_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE20_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE20_GTFSM_SHIFT)) & SEMA42_GATE20_GTFSM_MASK)
/*! @} */

/*! @name GATE27 - Gate */
/*! @{ */

#define SEMA42_GATE27_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE27_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE27_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE27_GTFSM_SHIFT)) & SEMA42_GATE27_GTFSM_MASK)
/*! @} */

/*! @name GATE26 - Gate */
/*! @{ */

#define SEMA42_GATE26_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE26_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE26_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE26_GTFSM_SHIFT)) & SEMA42_GATE26_GTFSM_MASK)
/*! @} */

/*! @name GATE25 - Gate */
/*! @{ */

#define SEMA42_GATE25_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE25_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE25_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE25_GTFSM_SHIFT)) & SEMA42_GATE25_GTFSM_MASK)
/*! @} */

/*! @name GATE24 - Gate */
/*! @{ */

#define SEMA42_GATE24_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE24_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE24_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE24_GTFSM_SHIFT)) & SEMA42_GATE24_GTFSM_MASK)
/*! @} */

/*! @name GATE31 - Gate */
/*! @{ */

#define SEMA42_GATE31_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE31_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE31_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE31_GTFSM_SHIFT)) & SEMA42_GATE31_GTFSM_MASK)
/*! @} */

/*! @name GATE30 - Gate */
/*! @{ */

#define SEMA42_GATE30_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE30_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE30_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE30_GTFSM_SHIFT)) & SEMA42_GATE30_GTFSM_MASK)
/*! @} */

/*! @name GATE29 - Gate */
/*! @{ */

#define SEMA42_GATE29_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE29_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE29_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE29_GTFSM_SHIFT)) & SEMA42_GATE29_GTFSM_MASK)
/*! @} */

/*! @name GATE28 - Gate */
/*! @{ */

#define SEMA42_GATE28_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE28_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE28_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE28_GTFSM_SHIFT)) & SEMA42_GATE28_GTFSM_MASK)
/*! @} */

/*! @name GATE35 - Gate */
/*! @{ */

#define SEMA42_GATE35_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE35_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE35_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE35_GTFSM_SHIFT)) & SEMA42_GATE35_GTFSM_MASK)
/*! @} */

/*! @name GATE34 - Gate */
/*! @{ */

#define SEMA42_GATE34_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE34_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE34_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE34_GTFSM_SHIFT)) & SEMA42_GATE34_GTFSM_MASK)
/*! @} */

/*! @name GATE33 - Gate */
/*! @{ */

#define SEMA42_GATE33_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE33_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE33_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE33_GTFSM_SHIFT)) & SEMA42_GATE33_GTFSM_MASK)
/*! @} */

/*! @name GATE32 - Gate */
/*! @{ */

#define SEMA42_GATE32_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE32_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE32_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE32_GTFSM_SHIFT)) & SEMA42_GATE32_GTFSM_MASK)
/*! @} */

/*! @name GATE39 - Gate */
/*! @{ */

#define SEMA42_GATE39_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE39_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE39_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE39_GTFSM_SHIFT)) & SEMA42_GATE39_GTFSM_MASK)
/*! @} */

/*! @name GATE38 - Gate */
/*! @{ */

#define SEMA42_GATE38_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE38_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE38_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE38_GTFSM_SHIFT)) & SEMA42_GATE38_GTFSM_MASK)
/*! @} */

/*! @name GATE37 - Gate */
/*! @{ */

#define SEMA42_GATE37_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE37_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE37_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE37_GTFSM_SHIFT)) & SEMA42_GATE37_GTFSM_MASK)
/*! @} */

/*! @name GATE36 - Gate */
/*! @{ */

#define SEMA42_GATE36_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE36_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE36_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE36_GTFSM_SHIFT)) & SEMA42_GATE36_GTFSM_MASK)
/*! @} */

/*! @name GATE43 - Gate */
/*! @{ */

#define SEMA42_GATE43_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE43_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE43_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE43_GTFSM_SHIFT)) & SEMA42_GATE43_GTFSM_MASK)
/*! @} */

/*! @name GATE42 - Gate */
/*! @{ */

#define SEMA42_GATE42_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE42_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE42_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE42_GTFSM_SHIFT)) & SEMA42_GATE42_GTFSM_MASK)
/*! @} */

/*! @name GATE41 - Gate */
/*! @{ */

#define SEMA42_GATE41_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE41_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE41_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE41_GTFSM_SHIFT)) & SEMA42_GATE41_GTFSM_MASK)
/*! @} */

/*! @name GATE40 - Gate */
/*! @{ */

#define SEMA42_GATE40_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE40_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE40_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE40_GTFSM_SHIFT)) & SEMA42_GATE40_GTFSM_MASK)
/*! @} */

/*! @name GATE47 - Gate */
/*! @{ */

#define SEMA42_GATE47_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE47_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE47_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE47_GTFSM_SHIFT)) & SEMA42_GATE47_GTFSM_MASK)
/*! @} */

/*! @name GATE46 - Gate */
/*! @{ */

#define SEMA42_GATE46_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE46_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE46_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE46_GTFSM_SHIFT)) & SEMA42_GATE46_GTFSM_MASK)
/*! @} */

/*! @name GATE45 - Gate */
/*! @{ */

#define SEMA42_GATE45_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE45_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE45_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE45_GTFSM_SHIFT)) & SEMA42_GATE45_GTFSM_MASK)
/*! @} */

/*! @name GATE44 - Gate */
/*! @{ */

#define SEMA42_GATE44_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE44_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE44_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE44_GTFSM_SHIFT)) & SEMA42_GATE44_GTFSM_MASK)
/*! @} */

/*! @name GATE51 - Gate */
/*! @{ */

#define SEMA42_GATE51_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE51_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE51_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE51_GTFSM_SHIFT)) & SEMA42_GATE51_GTFSM_MASK)
/*! @} */

/*! @name GATE50 - Gate */
/*! @{ */

#define SEMA42_GATE50_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE50_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE50_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE50_GTFSM_SHIFT)) & SEMA42_GATE50_GTFSM_MASK)
/*! @} */

/*! @name GATE49 - Gate */
/*! @{ */

#define SEMA42_GATE49_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE49_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE49_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE49_GTFSM_SHIFT)) & SEMA42_GATE49_GTFSM_MASK)
/*! @} */

/*! @name GATE48 - Gate */
/*! @{ */

#define SEMA42_GATE48_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE48_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE48_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE48_GTFSM_SHIFT)) & SEMA42_GATE48_GTFSM_MASK)
/*! @} */

/*! @name GATE55 - Gate */
/*! @{ */

#define SEMA42_GATE55_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE55_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE55_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE55_GTFSM_SHIFT)) & SEMA42_GATE55_GTFSM_MASK)
/*! @} */

/*! @name GATE54 - Gate */
/*! @{ */

#define SEMA42_GATE54_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE54_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE54_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE54_GTFSM_SHIFT)) & SEMA42_GATE54_GTFSM_MASK)
/*! @} */

/*! @name GATE53 - Gate */
/*! @{ */

#define SEMA42_GATE53_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE53_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE53_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE53_GTFSM_SHIFT)) & SEMA42_GATE53_GTFSM_MASK)
/*! @} */

/*! @name GATE52 - Gate */
/*! @{ */

#define SEMA42_GATE52_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE52_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE52_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE52_GTFSM_SHIFT)) & SEMA42_GATE52_GTFSM_MASK)
/*! @} */

/*! @name GATE59 - Gate */
/*! @{ */

#define SEMA42_GATE59_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE59_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE59_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE59_GTFSM_SHIFT)) & SEMA42_GATE59_GTFSM_MASK)
/*! @} */

/*! @name GATE58 - Gate */
/*! @{ */

#define SEMA42_GATE58_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE58_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE58_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE58_GTFSM_SHIFT)) & SEMA42_GATE58_GTFSM_MASK)
/*! @} */

/*! @name GATE57 - Gate */
/*! @{ */

#define SEMA42_GATE57_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE57_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE57_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE57_GTFSM_SHIFT)) & SEMA42_GATE57_GTFSM_MASK)
/*! @} */

/*! @name GATE56 - Gate */
/*! @{ */

#define SEMA42_GATE56_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE56_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE56_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE56_GTFSM_SHIFT)) & SEMA42_GATE56_GTFSM_MASK)
/*! @} */

/*! @name GATE63 - Gate */
/*! @{ */

#define SEMA42_GATE63_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE63_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE63_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE63_GTFSM_SHIFT)) & SEMA42_GATE63_GTFSM_MASK)
/*! @} */

/*! @name GATE62 - Gate */
/*! @{ */

#define SEMA42_GATE62_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE62_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE62_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE62_GTFSM_SHIFT)) & SEMA42_GATE62_GTFSM_MASK)
/*! @} */

/*! @name GATE61 - Gate */
/*! @{ */

#define SEMA42_GATE61_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE61_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE61_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE61_GTFSM_SHIFT)) & SEMA42_GATE61_GTFSM_MASK)
/*! @} */

/*! @name GATE60 - Gate */
/*! @{ */

#define SEMA42_GATE60_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE60_GTFSM_SHIFT                (0U)
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
#define SEMA42_GATE60_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE60_GTFSM_SHIFT)) & SEMA42_GATE60_GTFSM_MASK)
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
