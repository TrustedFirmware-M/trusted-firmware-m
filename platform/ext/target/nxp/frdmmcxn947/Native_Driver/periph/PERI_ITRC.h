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
**         CMSIS Peripheral Access Layer for ITRC
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
 * @file PERI_ITRC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ITRC
 *
 * CMSIS Peripheral Access Layer for ITRC
 */

#if !defined(PERI_ITRC_H_)
#define PERI_ITRC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- ITRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITRC_Peripheral_Access_Layer ITRC Peripheral Access Layer
 * @{
 */

/** ITRC - Size of Registers Arrays */
#define ITRC_OUTX_SEL_COUNT                       7u
#define ITRC_OUTX_SEL_OUTX_SELY_COUNT             2u
#define ITRC_OUTX_SEL_1_COUNT                     7u
#define ITRC_OUTX_SEL_1_OUTX_SELY_COUNT           2u
#define ITRC_OUTX_SEL_2_COUNT                     7u
#define ITRC_OUTX_SEL_2_OUTX_SELY_COUNT           2u

/** ITRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t STATUS;                            /**< ITRC outputs and IN0 to IN15 Status, offset: 0x0 */
  __IO uint32_t STATUS1;                           /**< ITRC IN16 to IN47 Status, offset: 0x4 */
  __IO uint32_t OUT_SEL[ITRC_OUTX_SEL_COUNT][ITRC_OUTX_SEL_OUTX_SELY_COUNT]; /**< Trigger Source IN0 to IN15 selector, array offset: 0x8, array step: index*0x8, index2*0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t OUT_SEL_1[ITRC_OUTX_SEL_1_COUNT][ITRC_OUTX_SEL_1_OUTX_SELY_COUNT]; /**< Trigger Source IN16 to IN31 selector, array offset: 0x48, array step: index*0x8, index2*0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t OUT_SEL_2[ITRC_OUTX_SEL_2_COUNT][ITRC_OUTX_SEL_2_OUTX_SELY_COUNT]; /**< Trigger source IN32 to IN47 selector, array offset: 0x88, array step: index*0x8, index2*0x4 */
       uint8_t RESERVED_2[48];
  __O  uint32_t SW_EVENT0;                         /**< Software event 0, offset: 0xF0 */
  __O  uint32_t SW_EVENT1;                         /**< Software event 1, offset: 0xF4 */
} ITRC_Type;

/* ----------------------------------------------------------------------------
   -- ITRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITRC_Register_Masks ITRC Register Masks
 * @{
 */

/*! @name STATUS - ITRC outputs and IN0 to IN15 Status */
/*! @{ */

#define ITRC_STATUS_IN0_STATUS_MASK              (0x1U)
#define ITRC_STATUS_IN0_STATUS_SHIFT             (0U)
/*! IN0_STATUS - GDET0 & 1 interrupt.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN0_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN0_STATUS_SHIFT)) & ITRC_STATUS_IN0_STATUS_MASK)

#define ITRC_STATUS_IN1_STATUS_MASK              (0x2U)
#define ITRC_STATUS_IN1_STATUS_SHIFT             (1U)
/*! IN1_STATUS - TDET tamper output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN1_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN1_STATUS_SHIFT)) & ITRC_STATUS_IN1_STATUS_MASK)

#define ITRC_STATUS_IN2_STATUS_MASK              (0x4U)
#define ITRC_STATUS_IN2_STATUS_SHIFT             (2U)
/*! IN2_STATUS - Code Watchdog 0 interrupt.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN2_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN2_STATUS_SHIFT)) & ITRC_STATUS_IN2_STATUS_MASK)

#define ITRC_STATUS_IN3_STATUS_MASK              (0x8U)
#define ITRC_STATUS_IN3_STATUS_SHIFT             (3U)
/*! IN3_STATUS - VBAT volt tamper output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN3_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN3_STATUS_SHIFT)) & ITRC_STATUS_IN3_STATUS_MASK)

#define ITRC_STATUS_IN4_STATUS_MASK              (0x10U)
#define ITRC_STATUS_IN4_STATUS_SHIFT             (4U)
/*! IN4_STATUS - SPC VDD_CORE_LVD detect.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN4_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN4_STATUS_SHIFT)) & ITRC_STATUS_IN4_STATUS_MASK)

#define ITRC_STATUS_IN5_STATUS_MASK              (0x20U)
#define ITRC_STATUS_IN5_STATUS_SHIFT             (5U)
/*! IN5_STATUS - Watch Dog timer event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN5_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN5_STATUS_SHIFT)) & ITRC_STATUS_IN5_STATUS_MASK)

#define ITRC_STATUS_IN6_STATUS_MASK              (0x40U)
#define ITRC_STATUS_IN6_STATUS_SHIFT             (6U)
/*! IN6_STATUS - Flash ECC mismatch event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN6_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN6_STATUS_SHIFT)) & ITRC_STATUS_IN6_STATUS_MASK)

#define ITRC_STATUS_IN7_STATUS_MASK              (0x80U)
#define ITRC_STATUS_IN7_STATUS_SHIFT             (7U)
/*! IN7_STATUS - AHB secure bus checkers detected illegal access.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN7_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN7_STATUS_SHIFT)) & ITRC_STATUS_IN7_STATUS_MASK)

#define ITRC_STATUS_IN8_STATUS_MASK              (0x100U)
#define ITRC_STATUS_IN8_STATUS_SHIFT             (8U)
/*! IN8_STATUS - ELS error event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN8_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN8_STATUS_SHIFT)) & ITRC_STATUS_IN8_STATUS_MASK)

#define ITRC_STATUS_IN9_STATUS_MASK              (0x200U)
#define ITRC_STATUS_IN9_STATUS_SHIFT             (9U)
/*! IN9_STATUS - SPC VDD_CORE glitch detect event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN9_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN9_STATUS_SHIFT)) & ITRC_STATUS_IN9_STATUS_MASK)

#define ITRC_STATUS_IN10_STATUS_MASK             (0x400U)
#define ITRC_STATUS_IN10_STATUS_SHIFT            (10U)
/*! IN10_STATUS - PKC module detected an error event.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN10_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN10_STATUS_SHIFT)) & ITRC_STATUS_IN10_STATUS_MASK)

#define ITRC_STATUS_IN11_STATUS_MASK             (0x800U)
#define ITRC_STATUS_IN11_STATUS_SHIFT            (11U)
/*! IN11_STATUS - Code Watchdog 1 interrupt.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN11_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN11_STATUS_SHIFT)) & ITRC_STATUS_IN11_STATUS_MASK)

#define ITRC_STATUS_IN112_STATUS_MASK            (0x1000U)
#define ITRC_STATUS_IN112_STATUS_SHIFT           (12U)
/*! IN112_STATUS - Watchdog 1 timer event interrupt.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN112_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN112_STATUS_SHIFT)) & ITRC_STATUS_IN112_STATUS_MASK)

#define ITRC_STATUS_IN113_STATUS_MASK            (0x2000U)
#define ITRC_STATUS_IN113_STATUS_SHIFT           (13U)
/*! IN113_STATUS - FREQME out of range status output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN113_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN113_STATUS_SHIFT)) & ITRC_STATUS_IN113_STATUS_MASK)

#define ITRC_STATUS_IN14_STATUS_MASK             (0x4000U)
#define ITRC_STATUS_IN14_STATUS_SHIFT            (14U)
/*! IN14_STATUS - Software event 0 occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN14_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN14_STATUS_SHIFT)) & ITRC_STATUS_IN14_STATUS_MASK)

#define ITRC_STATUS_IN15_STATUS_MASK             (0x8000U)
#define ITRC_STATUS_IN15_STATUS_SHIFT            (15U)
/*! IN15_STATUS - Software event 1 occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN15_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN15_STATUS_SHIFT)) & ITRC_STATUS_IN15_STATUS_MASK)

#define ITRC_STATUS_OUT0_STATUS_MASK             (0x10000U)
#define ITRC_STATUS_OUT0_STATUS_SHIFT            (16U)
/*! OUT0_STATUS - ITRC triggered ITRC_IRQ output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT0_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT0_STATUS_SHIFT)) & ITRC_STATUS_OUT0_STATUS_MASK)

#define ITRC_STATUS_OUT1_STATUS_MASK             (0x20000U)
#define ITRC_STATUS_OUT1_STATUS_SHIFT            (17U)
/*! OUT1_STATUS - ITRC triggered ELS_RESET to clear ELS key store.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT1_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT1_STATUS_SHIFT)) & ITRC_STATUS_OUT1_STATUS_MASK)

#define ITRC_STATUS_OUT2_STATUS_MASK             (0x40000U)
#define ITRC_STATUS_OUT2_STATUS_SHIFT            (18U)
/*! OUT2_STATUS - ITRC triggered PUF_ZEROIZE to clear PUF key store and RAM.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT2_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT2_STATUS_SHIFT)) & ITRC_STATUS_OUT2_STATUS_MASK)

#define ITRC_STATUS_OUT3_STATUS_MASK             (0x80000U)
#define ITRC_STATUS_OUT3_STATUS_SHIFT            (19U)
/*! OUT3_STATUS - ITRC triggered RAM_ZEROIZE.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT3_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT3_STATUS_SHIFT)) & ITRC_STATUS_OUT3_STATUS_MASK)

#define ITRC_STATUS_OUT4_STATUS_MASK             (0x100000U)
#define ITRC_STATUS_OUT4_STATUS_SHIFT            (20U)
/*! OUT4_STATUS - ITRC triggered CHIP_RESET to reset the chip after all other response process finished.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT4_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT4_STATUS_SHIFT)) & ITRC_STATUS_OUT4_STATUS_MASK)

#define ITRC_STATUS_OUT5_STATUS_MASK             (0x200000U)
#define ITRC_STATUS_OUT5_STATUS_SHIFT            (21U)
/*! OUT5_STATUS - ITRC triggered TMPR_OUT0 internal signal connected to various on-chip multiplexers.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT5_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT5_STATUS_SHIFT)) & ITRC_STATUS_OUT5_STATUS_MASK)

#define ITRC_STATUS_OUT6_STATUS_MASK             (0x400000U)
#define ITRC_STATUS_OUT6_STATUS_SHIFT            (22U)
/*! OUT6_STATUS - ITRC triggered TMPR_OUT1 internal signal connected to various on-chip multiplexers.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT6_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT6_STATUS_SHIFT)) & ITRC_STATUS_OUT6_STATUS_MASK)
/*! @} */

/*! @name STATUS1 - ITRC IN16 to IN47 Status */
/*! @{ */

#define ITRC_STATUS1_IN16_STATUS_MASK            (0x1U)
#define ITRC_STATUS1_IN16_STATUS_SHIFT           (0U)
/*! IN16_STATUS - SSPC VDD_SYS_LVD detect event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN16_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN16_STATUS_SHIFT)) & ITRC_STATUS1_IN16_STATUS_MASK)

#define ITRC_STATUS1_IN17_STATUS_MASK            (0x2U)
#define ITRC_STATUS1_IN17_STATUS_SHIFT           (1U)
/*! IN17_STATUS - SPC VDD_IO_LVD detect event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN17_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN17_STATUS_SHIFT)) & ITRC_STATUS1_IN17_STATUS_MASK)

#define ITRC_STATUS1_IN18_STATUS_MASK            (0x4U)
#define ITRC_STATUS1_IN18_STATUS_SHIFT           (2U)
/*! IN18_STATUS - Reserved
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN18_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN18_STATUS_SHIFT)) & ITRC_STATUS1_IN18_STATUS_MASK)

#define ITRC_STATUS1_IN19_STATUS_MASK            (0x8U)
#define ITRC_STATUS1_IN19_STATUS_SHIFT           (3U)
/*! IN19_STATUS - Reserved
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN19_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN19_STATUS_SHIFT)) & ITRC_STATUS1_IN19_STATUS_MASK)

#define ITRC_STATUS1_IN20_STATUS_MASK            (0x10U)
#define ITRC_STATUS1_IN20_STATUS_SHIFT           (4U)
/*! IN20_STATUS - VBAT clock tamper output event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN20_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN20_STATUS_SHIFT)) & ITRC_STATUS1_IN20_STATUS_MASK)

#define ITRC_STATUS1_IN24_21_STATUS_MASK         (0x1E0U)
#define ITRC_STATUS1_IN24_21_STATUS_SHIFT        (5U)
/*! IN24_21_STATUS - INTM interrupt monitor error 3~0 event occurred.
 *  0b0000..Output not triggered.
 *  0b0001..Output has been triggered.
 */
#define ITRC_STATUS1_IN24_21_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN24_21_STATUS_SHIFT)) & ITRC_STATUS1_IN24_21_STATUS_MASK)

#define ITRC_STATUS1_IN32_25_STATUS_MASK         (0x1FE00U)
#define ITRC_STATUS1_IN32_25_STATUS_SHIFT        (9U)
/*! IN32_25_STATUS - MSF SOCTRIM 7~0 ECC error event occurred.
 *  0b00000000..Output not triggered.
 *  0b00000001..Output has been triggered.
 */
#define ITRC_STATUS1_IN32_25_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN32_25_STATUS_SHIFT)) & ITRC_STATUS1_IN32_25_STATUS_MASK)

#define ITRC_STATUS1_IN33_STATUS_MASK            (0x20000U)
#define ITRC_STATUS1_IN33_STATUS_SHIFT           (17U)
/*! IN33_STATUS - GDET0/1 SFR error event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN33_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN33_STATUS_SHIFT)) & ITRC_STATUS1_IN33_STATUS_MASK)

#define ITRC_STATUS1_IN34_STATUS_MASK            (0x40000U)
#define ITRC_STATUS1_IN34_STATUS_SHIFT           (18U)
/*! IN34_STATUS - SPC VDD_CORE high voltage detect event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN34_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN34_STATUS_SHIFT)) & ITRC_STATUS1_IN34_STATUS_MASK)

#define ITRC_STATUS1_IN35_STATUS_MASK            (0x80000U)
#define ITRC_STATUS1_IN35_STATUS_SHIFT           (19U)
/*! IN35_STATUS - SPC VDD_SYS_HVD high voltage detect event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN35_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN35_STATUS_SHIFT)) & ITRC_STATUS1_IN35_STATUS_MASK)

#define ITRC_STATUS1_IN36_STATUS_MASK            (0x100000U)
#define ITRC_STATUS1_IN36_STATUS_SHIFT           (20U)
/*! IN36_STATUS - SPC VDD_IO high voltage detect event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN36_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN36_STATUS_SHIFT)) & ITRC_STATUS1_IN36_STATUS_MASK)

#define ITRC_STATUS1_IN37_STATUS_MASK            (0x200000U)
#define ITRC_STATUS1_IN37_STATUS_SHIFT           (21U)
/*! IN37_STATUS - FLEXSPI GCM error event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN37_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN37_STATUS_SHIFT)) & ITRC_STATUS1_IN37_STATUS_MASK)

#define ITRC_STATUS1_IN46_STATUS_MASK            (0x40000000U)
#define ITRC_STATUS1_IN46_STATUS_SHIFT           (30U)
/*! IN46_STATUS - SM3 SGI error event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN46_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN46_STATUS_SHIFT)) & ITRC_STATUS1_IN46_STATUS_MASK)

#define ITRC_STATUS1_IN47_STATUS_MASK            (0x80000000U)
#define ITRC_STATUS1_IN47_STATUS_SHIFT           (31U)
/*! IN47_STATUS - TRNG HW error event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN47_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN47_STATUS_SHIFT)) & ITRC_STATUS1_IN47_STATUS_MASK)
/*! @} */

/*! @name OUT_SEL - Trigger Source IN0 to IN15 selector */
/*! @{ */

#define ITRC_OUT_SEL_IN0_SELn_MASK               (0x3U)
#define ITRC_OUT_SEL_IN0_SELn_SHIFT              (0U)
/*! IN0_SELn - Selects digital glitch detector as a trigger source. */
#define ITRC_OUT_SEL_IN0_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN0_SELn_SHIFT)) & ITRC_OUT_SEL_IN0_SELn_MASK)

#define ITRC_OUT_SEL_IN1_SELn_MASK               (0xCU)
#define ITRC_OUT_SEL_IN1_SELn_SHIFT              (2U)
/*! IN1_SELn - Selects TDET event as a trigger source. */
#define ITRC_OUT_SEL_IN1_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN1_SELn_SHIFT)) & ITRC_OUT_SEL_IN1_SELn_MASK)

#define ITRC_OUT_SEL_IN2_SELn_MASK               (0x30U)
#define ITRC_OUT_SEL_IN2_SELn_SHIFT              (4U)
/*! IN2_SELn - Selects Code Watchdog 0 event as a trigger source. */
#define ITRC_OUT_SEL_IN2_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN2_SELn_SHIFT)) & ITRC_OUT_SEL_IN2_SELn_MASK)

#define ITRC_OUT_SEL_IN3_SELn_MASK               (0xC0U)
#define ITRC_OUT_SEL_IN3_SELn_SHIFT              (6U)
/*! IN3_SELn - Selects VBAT voltage tamper event as a trigger source. */
#define ITRC_OUT_SEL_IN3_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN3_SELn_SHIFT)) & ITRC_OUT_SEL_IN3_SELn_MASK)

#define ITRC_OUT_SEL_IN4_SELn_MASK               (0x300U)
#define ITRC_OUT_SEL_IN4_SELn_SHIFT              (8U)
/*! IN4_SELn - Selects low-voltage event on VDD_CORE rail as a trigger source. */
#define ITRC_OUT_SEL_IN4_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN4_SELn_SHIFT)) & ITRC_OUT_SEL_IN4_SELn_MASK)

#define ITRC_OUT_SEL_IN5_SELn_MASK               (0xC00U)
#define ITRC_OUT_SEL_IN5_SELn_SHIFT              (10U)
/*! IN5_SELn - Selects Watchdog 0 timer event as a trigger source. */
#define ITRC_OUT_SEL_IN5_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN5_SELn_SHIFT)) & ITRC_OUT_SEL_IN5_SELn_MASK)

#define ITRC_OUT_SEL_IN6_SELn_MASK               (0x3000U)
#define ITRC_OUT_SEL_IN6_SELn_SHIFT              (12U)
/*! IN6_SELn - Selects Flash ECC mismatch event as a trigger source. */
#define ITRC_OUT_SEL_IN6_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN6_SELn_SHIFT)) & ITRC_OUT_SEL_IN6_SELn_MASK)

#define ITRC_OUT_SEL_IN7_SELn_MASK               (0xC000U)
#define ITRC_OUT_SEL_IN7_SELn_SHIFT              (14U)
/*! IN7_SELn - Selects AHB secure bus or MBC bus illegal access event as a trigger source. */
#define ITRC_OUT_SEL_IN7_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN7_SELn_SHIFT)) & ITRC_OUT_SEL_IN7_SELn_MASK)

#define ITRC_OUT_SEL_IN8_SELn_MASK               (0x30000U)
#define ITRC_OUT_SEL_IN8_SELn_SHIFT              (16U)
/*! IN8_SELn - Selects ELS error event as a trigger source. */
#define ITRC_OUT_SEL_IN8_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN8_SELn_SHIFT)) & ITRC_OUT_SEL_IN8_SELn_MASK)

#define ITRC_OUT_SEL_IN9_SELn_MASK               (0xC0000U)
#define ITRC_OUT_SEL_IN9_SELn_SHIFT              (18U)
/*! IN9_SELn - Selects SPC VDD_CORE glitch detector as a trigger source. */
#define ITRC_OUT_SEL_IN9_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN9_SELn_SHIFT)) & ITRC_OUT_SEL_IN9_SELn_MASK)

#define ITRC_OUT_SEL_IN10_SELn_MASK              (0x300000U)
#define ITRC_OUT_SEL_IN10_SELn_SHIFT             (20U)
/*! IN10_SELn - Selects PKC error event as a trigger source. */
#define ITRC_OUT_SEL_IN10_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN10_SELn_SHIFT)) & ITRC_OUT_SEL_IN10_SELn_MASK)

#define ITRC_OUT_SEL_IN11_SELn_MASK              (0xC00000U)
#define ITRC_OUT_SEL_IN11_SELn_SHIFT             (22U)
/*! IN11_SELn - Selects Code Watchdog 1 event as a trigger source. */
#define ITRC_OUT_SEL_IN11_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN11_SELn_SHIFT)) & ITRC_OUT_SEL_IN11_SELn_MASK)

#define ITRC_OUT_SEL_IN12_SELn_MASK              (0x3000000U)
#define ITRC_OUT_SEL_IN12_SELn_SHIFT             (24U)
/*! IN12_SELn - Selects Watchdog 1 timer event as a trigger source. */
#define ITRC_OUT_SEL_IN12_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN12_SELn_SHIFT)) & ITRC_OUT_SEL_IN12_SELn_MASK)

#define ITRC_OUT_SEL_IN13_SELn_MASK              (0xC000000U)
#define ITRC_OUT_SEL_IN13_SELn_SHIFT             (26U)
/*! IN13_SELn - Selects FREQME out of range status output as a trigger source. */
#define ITRC_OUT_SEL_IN13_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN13_SELn_SHIFT)) & ITRC_OUT_SEL_IN13_SELn_MASK)

#define ITRC_OUT_SEL_IN14_SELn_MASK              (0x30000000U)
#define ITRC_OUT_SEL_IN14_SELn_SHIFT             (28U)
/*! IN14_SELn - Selects software event 0 as a trigger source. */
#define ITRC_OUT_SEL_IN14_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN14_SELn_SHIFT)) & ITRC_OUT_SEL_IN14_SELn_MASK)

#define ITRC_OUT_SEL_IN15_SELn_MASK              (0xC0000000U)
#define ITRC_OUT_SEL_IN15_SELn_SHIFT             (30U)
/*! IN15_SELn - Selects software event 1 as a trigger source. */
#define ITRC_OUT_SEL_IN15_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN15_SELn_SHIFT)) & ITRC_OUT_SEL_IN15_SELn_MASK)
/*! @} */

/* The count of ITRC_OUT_SEL */
#define ITRC_OUT_SEL_COUNT                       (7U)

/* The count of ITRC_OUT_SEL */
#define ITRC_OUT_SEL_COUNT2                      (2U)

/*! @name OUT_SEL_1 - Trigger Source IN16 to IN31 selector */
/*! @{ */

#define ITRC_OUT_SEL_1_IN16_SELn_MASK            (0x3U)
#define ITRC_OUT_SEL_1_IN16_SELn_SHIFT           (0U)
/*! IN16_SELn - Selects SPC VDD_SYS_LVD detect as a trigger source. */
#define ITRC_OUT_SEL_1_IN16_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN16_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN16_SELn_MASK)

#define ITRC_OUT_SEL_1_IN17_SELn_MASK            (0xCU)
#define ITRC_OUT_SEL_1_IN17_SELn_SHIFT           (2U)
/*! IN17_SELn - Selects SPC VDD_IO_LVD detect as a trigger source. */
#define ITRC_OUT_SEL_1_IN17_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN17_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN17_SELn_MASK)

#define ITRC_OUT_SEL_1_IN18_SELn_MASK            (0x30U)
#define ITRC_OUT_SEL_1_IN18_SELn_SHIFT           (4U)
/*! IN18_SELn - Reserved. */
#define ITRC_OUT_SEL_1_IN18_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN18_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN18_SELn_MASK)

#define ITRC_OUT_SEL_1_IN19_SELn_MASK            (0xC0U)
#define ITRC_OUT_SEL_1_IN19_SELn_SHIFT           (6U)
/*! IN19_SELn - Selects VBAT temperature tamper output event as a trigger source. */
#define ITRC_OUT_SEL_1_IN19_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN19_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN19_SELn_MASK)

#define ITRC_OUT_SEL_1_IN20_SELn_MASK            (0x300U)
#define ITRC_OUT_SEL_1_IN20_SELn_SHIFT           (8U)
/*! IN20_SELn - Selects VBAT clock tamper output event as a trigger source. */
#define ITRC_OUT_SEL_1_IN20_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN20_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN20_SELn_MASK)

#define ITRC_OUT_SEL_1_IN21_SELn_MASK            (0xC00U)
#define ITRC_OUT_SEL_1_IN21_SELn_SHIFT           (10U)
/*! IN21_SELn - Selects INTM interrupt monitor error 0 event as a trigger source. */
#define ITRC_OUT_SEL_1_IN21_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN21_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN21_SELn_MASK)

#define ITRC_OUT_SEL_1_IN22_SELn_MASK            (0x3000U)
#define ITRC_OUT_SEL_1_IN22_SELn_SHIFT           (12U)
/*! IN22_SELn - Selects INTM interrupt monitor error 1 event as a trigger source. */
#define ITRC_OUT_SEL_1_IN22_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN22_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN22_SELn_MASK)

#define ITRC_OUT_SEL_1_IN23_SELn_MASK            (0xC000U)
#define ITRC_OUT_SEL_1_IN23_SELn_SHIFT           (14U)
/*! IN23_SELn - Selects INTM interrupt monitor error 2 event as a trigger source. */
#define ITRC_OUT_SEL_1_IN23_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN23_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN23_SELn_MASK)

#define ITRC_OUT_SEL_1_IN24_SELn_MASK            (0x30000U)
#define ITRC_OUT_SEL_1_IN24_SELn_SHIFT           (16U)
/*! IN24_SELn - Selects INTM interrupt monitor error 3 event as a trigger source. */
#define ITRC_OUT_SEL_1_IN24_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN24_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN24_SELn_MASK)

#define ITRC_OUT_SEL_1_IN25_SELn_MASK            (0xC0000U)
#define ITRC_OUT_SEL_1_IN25_SELn_SHIFT           (18U)
/*! IN25_SELn - Selects MSF SOCTRIM 0 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_1_IN25_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN25_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN25_SELn_MASK)

#define ITRC_OUT_SEL_1_IN26_SELn_MASK            (0x300000U)
#define ITRC_OUT_SEL_1_IN26_SELn_SHIFT           (20U)
/*! IN26_SELn - Selects MSF SOCTRIM 1 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_1_IN26_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN26_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN26_SELn_MASK)

#define ITRC_OUT_SEL_1_IN27_SELn_MASK            (0xC00000U)
#define ITRC_OUT_SEL_1_IN27_SELn_SHIFT           (22U)
/*! IN27_SELn - Selects MSF SOCTRIM 2 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_1_IN27_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN27_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN27_SELn_MASK)

#define ITRC_OUT_SEL_1_IN28_SELn_MASK            (0x3000000U)
#define ITRC_OUT_SEL_1_IN28_SELn_SHIFT           (24U)
/*! IN28_SELn - Selects MSF SOCTRIM 3 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_1_IN28_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN28_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN28_SELn_MASK)

#define ITRC_OUT_SEL_1_IN29_SELn_MASK            (0xC000000U)
#define ITRC_OUT_SEL_1_IN29_SELn_SHIFT           (26U)
/*! IN29_SELn - Selects MSF SOCTRIM 4 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_1_IN29_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN29_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN29_SELn_MASK)

#define ITRC_OUT_SEL_1_IN30_SELn_MASK            (0x30000000U)
#define ITRC_OUT_SEL_1_IN30_SELn_SHIFT           (28U)
/*! IN30_SELn - Selects MSF SOCTRIM 5 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_1_IN30_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN30_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN30_SELn_MASK)

#define ITRC_OUT_SEL_1_IN31_SELn_MASK            (0xC0000000U)
#define ITRC_OUT_SEL_1_IN31_SELn_SHIFT           (30U)
/*! IN31_SELn - Selects MSF SOCTRIM 6 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_1_IN31_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN31_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN31_SELn_MASK)
/*! @} */

/* The count of ITRC_OUT_SEL_1 */
#define ITRC_OUT_SEL_1_COUNT                     (7U)

/* The count of ITRC_OUT_SEL_1 */
#define ITRC_OUT_SEL_1_COUNT2                    (2U)

/*! @name OUT_SEL_2 - Trigger source IN32 to IN47 selector */
/*! @{ */

#define ITRC_OUT_SEL_2_IN32_SELn_MASK            (0x3U)
#define ITRC_OUT_SEL_2_IN32_SELn_SHIFT           (0U)
/*! IN32_SELn - Selects MSF SOCTRIM 7 ECC error event as a trigger source. */
#define ITRC_OUT_SEL_2_IN32_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN32_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN32_SELn_MASK)

#define ITRC_OUT_SEL_2_IN33_SELn_MASK            (0xCU)
#define ITRC_OUT_SEL_2_IN33_SELn_SHIFT           (2U)
/*! IN33_SELn - Selects GDET0 & 1 SFR error detect as a trigger source. */
#define ITRC_OUT_SEL_2_IN33_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN33_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN33_SELn_MASK)

#define ITRC_OUT_SEL_2_IN34_SELn_MASK            (0x30U)
#define ITRC_OUT_SEL_2_IN34_SELn_SHIFT           (4U)
/*! IN34_SELn - Selects SPC VDD_CORE_HVD as a trigger source. */
#define ITRC_OUT_SEL_2_IN34_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN34_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN34_SELn_MASK)

#define ITRC_OUT_SEL_2_IN35_SELn_MASK            (0xC0U)
#define ITRC_OUT_SEL_2_IN35_SELn_SHIFT           (6U)
/*! IN35_SELn - Selects VDD_SYS_HVD as a trigger source. */
#define ITRC_OUT_SEL_2_IN35_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN35_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN35_SELn_MASK)

#define ITRC_OUT_SEL_2_IN36_SELn_MASK            (0x300U)
#define ITRC_OUT_SEL_2_IN36_SELn_SHIFT           (8U)
/*! IN36_SELn - Selects VDD_IO_HVD as a trigger source. */
#define ITRC_OUT_SEL_2_IN36_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN36_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN36_SELn_MASK)

#define ITRC_OUT_SEL_2_IN37_SELn_MASK            (0xC00U)
#define ITRC_OUT_SEL_2_IN37_SELn_SHIFT           (10U)
/*! IN37_SELn - Selects FLEXSPI GCM error as a trigger source. */
#define ITRC_OUT_SEL_2_IN37_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN37_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN37_SELn_MASK)

#define ITRC_OUT_SEL_2_IN46_SELn_MASK            (0x30000000U)
#define ITRC_OUT_SEL_2_IN46_SELn_SHIFT           (28U)
/*! IN46_SELn - Selects SM3 SGI error as a trigger source. */
#define ITRC_OUT_SEL_2_IN46_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN46_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN46_SELn_MASK)

#define ITRC_OUT_SEL_2_IN47_SELn_MASK            (0xC0000000U)
#define ITRC_OUT_SEL_2_IN47_SELn_SHIFT           (30U)
/*! IN47_SELn - Selects TRNG HW Error as a trigger source. */
#define ITRC_OUT_SEL_2_IN47_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN47_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN47_SELn_MASK)
/*! @} */

/* The count of ITRC_OUT_SEL_2 */
#define ITRC_OUT_SEL_2_COUNT                     (7U)

/* The count of ITRC_OUT_SEL_2 */
#define ITRC_OUT_SEL_2_COUNT2                    (2U)

/*! @name SW_EVENT0 - Software event 0 */
/*! @{ */

#define ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_MASK   (0xFFFFFFFFU)
#define ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_SHIFT  (0U)
/*! TRIGGER_SW_EVENT_0 - Trigger software event 0. */
#define ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0(x)     (((uint32_t)(((uint32_t)(x)) << ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_SHIFT)) & ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_MASK)
/*! @} */

/*! @name SW_EVENT1 - Software event 1 */
/*! @{ */

#define ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_MASK   (0xFFFFFFFFU)
#define ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_SHIFT  (0U)
/*! TRIGGER_SW_EVENT_1 - Trigger software event 1. */
#define ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1(x)     (((uint32_t)(((uint32_t)(x)) << ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_SHIFT)) & ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ITRC_Register_Masks */


/*!
 * @}
 */ /* end of group ITRC_Peripheral_Access_Layer */


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


#endif  /* PERI_ITRC_H_ */

