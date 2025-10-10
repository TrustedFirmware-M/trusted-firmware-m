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
**         CMSIS Peripheral Access Layer for CDOG
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
 * @file PERI_CDOG.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CDOG
 *
 * CMSIS Peripheral Access Layer for CDOG
 */

#if !defined(PERI_CDOG_H_)
#define PERI_CDOG_H_                             /**< Symbol preventing repeated inclusion */

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
   -- CDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CDOG_Peripheral_Access_Layer CDOG Peripheral Access Layer
 * @{
 */

/** CDOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONTROL;                           /**< Control Register, offset: 0x0 */
  __IO uint32_t RELOAD;                            /**< Instruction Timer Reload Register, offset: 0x4 */
  __I  uint32_t INSTRUCTION_TIMER;                 /**< Instruction Timer Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __I  uint32_t STATUS;                            /**< Status 1 Register, offset: 0x10 */
  __I  uint32_t STATUS2;                           /**< Status 2 Register, offset: 0x14 */
  __IO uint32_t FLAGS;                             /**< Flags Register, offset: 0x18 */
  __IO uint32_t PERSISTENT;                        /**< Persistent Data Storage Register, offset: 0x1C */
  __O  uint32_t START;                             /**< START Command Register, offset: 0x20 */
  __O  uint32_t STOP;                              /**< STOP Command Register, offset: 0x24 */
  __O  uint32_t RESTART;                           /**< RESTART Command Register, offset: 0x28 */
  __O  uint32_t ADD;                               /**< ADD Command Register, offset: 0x2C */
  __O  uint32_t ADD1;                              /**< ADD1 Command Register, offset: 0x30 */
  __O  uint32_t ADD16;                             /**< ADD16 Command Register, offset: 0x34 */
  __O  uint32_t ADD256;                            /**< ADD256 Command Register, offset: 0x38 */
  __O  uint32_t SUB;                               /**< SUB Command Register, offset: 0x3C */
  __O  uint32_t SUB1;                              /**< SUB1 Command Register, offset: 0x40 */
  __O  uint32_t SUB16;                             /**< SUB16 Command Register, offset: 0x44 */
  __O  uint32_t SUB256;                            /**< SUB256 Command Register, offset: 0x48 */
  __O  uint32_t ASSERT16;                          /**< ASSERT16 Command Register, offset: 0x4C */
} CDOG_Type;

/* ----------------------------------------------------------------------------
   -- CDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CDOG_Register_Masks CDOG Register Masks
 * @{
 */

/*! @name CONTROL - Control Register */
/*! @{ */

#define CDOG_CONTROL_LOCK_CTRL_MASK              (0x3U)
#define CDOG_CONTROL_LOCK_CTRL_SHIFT             (0U)
/*! LOCK_CTRL - Lock control
 *  0b01..Locked
 *  0b10..Unlocked
 */
#define CDOG_CONTROL_LOCK_CTRL(x)                (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_LOCK_CTRL_SHIFT)) & CDOG_CONTROL_LOCK_CTRL_MASK)

#define CDOG_CONTROL_TIMEOUT_CTRL_MASK           (0x1CU)
#define CDOG_CONTROL_TIMEOUT_CTRL_SHIFT          (2U)
/*! TIMEOUT_CTRL - TIMEOUT fault control
 *  0b001..Enable reset
 *  0b010..Enable interrupt
 *  0b100..Disable both reset and interrupt
 */
#define CDOG_CONTROL_TIMEOUT_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_TIMEOUT_CTRL_SHIFT)) & CDOG_CONTROL_TIMEOUT_CTRL_MASK)

#define CDOG_CONTROL_MISCOMPARE_CTRL_MASK        (0xE0U)
#define CDOG_CONTROL_MISCOMPARE_CTRL_SHIFT       (5U)
/*! MISCOMPARE_CTRL - MISCOMPARE fault control
 *  0b001..Enable reset
 *  0b010..Enable interrupt
 *  0b100..Disable both reset and interrupt
 */
#define CDOG_CONTROL_MISCOMPARE_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_MISCOMPARE_CTRL_SHIFT)) & CDOG_CONTROL_MISCOMPARE_CTRL_MASK)

#define CDOG_CONTROL_SEQUENCE_CTRL_MASK          (0x700U)
#define CDOG_CONTROL_SEQUENCE_CTRL_SHIFT         (8U)
/*! SEQUENCE_CTRL - SEQUENCE fault control
 *  0b001..Enable reset
 *  0b010..Enable interrupt
 *  0b100..Disable both reset and interrupt
 */
#define CDOG_CONTROL_SEQUENCE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_SEQUENCE_CTRL_SHIFT)) & CDOG_CONTROL_SEQUENCE_CTRL_MASK)

#define CDOG_CONTROL_STATE_CTRL_MASK             (0x1C000U)
#define CDOG_CONTROL_STATE_CTRL_SHIFT            (14U)
/*! STATE_CTRL - STATE fault control
 *  0b001..Enable reset
 *  0b010..Enable interrupt
 *  0b100..Disable both reset and interrupt
 */
#define CDOG_CONTROL_STATE_CTRL(x)               (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_STATE_CTRL_SHIFT)) & CDOG_CONTROL_STATE_CTRL_MASK)

#define CDOG_CONTROL_ADDRESS_CTRL_MASK           (0xE0000U)
#define CDOG_CONTROL_ADDRESS_CTRL_SHIFT          (17U)
/*! ADDRESS_CTRL - ADDRESS fault control
 *  0b001..Enable reset
 *  0b010..Enable interrupt
 *  0b100..Disable both reset and interrupt
 */
#define CDOG_CONTROL_ADDRESS_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_ADDRESS_CTRL_SHIFT)) & CDOG_CONTROL_ADDRESS_CTRL_MASK)

#define CDOG_CONTROL_IRQ_PAUSE_MASK              (0x30000000U)
#define CDOG_CONTROL_IRQ_PAUSE_SHIFT             (28U)
/*! IRQ_PAUSE - IRQ pause control
 *  0b01..Keep the timer running
 *  0b10..Stop the timer
 */
#define CDOG_CONTROL_IRQ_PAUSE(x)                (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_IRQ_PAUSE_SHIFT)) & CDOG_CONTROL_IRQ_PAUSE_MASK)

#define CDOG_CONTROL_DEBUG_HALT_CTRL_MASK        (0xC0000000U)
#define CDOG_CONTROL_DEBUG_HALT_CTRL_SHIFT       (30U)
/*! DEBUG_HALT_CTRL - DEBUG_HALT control
 *  0b01..Keep the timer running
 *  0b10..Stop the timer
 */
#define CDOG_CONTROL_DEBUG_HALT_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << CDOG_CONTROL_DEBUG_HALT_CTRL_SHIFT)) & CDOG_CONTROL_DEBUG_HALT_CTRL_MASK)
/*! @} */

/*! @name RELOAD - Instruction Timer Reload Register */
/*! @{ */

#define CDOG_RELOAD_RLOAD_MASK                   (0xFFFFFFFFU)
#define CDOG_RELOAD_RLOAD_SHIFT                  (0U)
/*! RLOAD - Instruction Timer reload value */
#define CDOG_RELOAD_RLOAD(x)                     (((uint32_t)(((uint32_t)(x)) << CDOG_RELOAD_RLOAD_SHIFT)) & CDOG_RELOAD_RLOAD_MASK)
/*! @} */

/*! @name INSTRUCTION_TIMER - Instruction Timer Register */
/*! @{ */

#define CDOG_INSTRUCTION_TIMER_INSTIM_MASK       (0xFFFFFFFFU)
#define CDOG_INSTRUCTION_TIMER_INSTIM_SHIFT      (0U)
/*! INSTIM - Current value of the Instruction Timer */
#define CDOG_INSTRUCTION_TIMER_INSTIM(x)         (((uint32_t)(((uint32_t)(x)) << CDOG_INSTRUCTION_TIMER_INSTIM_SHIFT)) & CDOG_INSTRUCTION_TIMER_INSTIM_MASK)
/*! @} */

/*! @name STATUS - Status 1 Register */
/*! @{ */

#define CDOG_STATUS_NUMTOF_MASK                  (0xFFU)
#define CDOG_STATUS_NUMTOF_SHIFT                 (0U)
/*! NUMTOF - Number of TIMEOUT faults since the last POR */
#define CDOG_STATUS_NUMTOF(x)                    (((uint32_t)(((uint32_t)(x)) << CDOG_STATUS_NUMTOF_SHIFT)) & CDOG_STATUS_NUMTOF_MASK)

#define CDOG_STATUS_NUMMISCOMPF_MASK             (0xFF00U)
#define CDOG_STATUS_NUMMISCOMPF_SHIFT            (8U)
/*! NUMMISCOMPF - Number of MISCOMPARE faults since the last POR */
#define CDOG_STATUS_NUMMISCOMPF(x)               (((uint32_t)(((uint32_t)(x)) << CDOG_STATUS_NUMMISCOMPF_SHIFT)) & CDOG_STATUS_NUMMISCOMPF_MASK)

#define CDOG_STATUS_NUMILSEQF_MASK               (0xFF0000U)
#define CDOG_STATUS_NUMILSEQF_SHIFT              (16U)
/*! NUMILSEQF - Number of SEQUENCE faults since the last POR */
#define CDOG_STATUS_NUMILSEQF(x)                 (((uint32_t)(((uint32_t)(x)) << CDOG_STATUS_NUMILSEQF_SHIFT)) & CDOG_STATUS_NUMILSEQF_MASK)

#define CDOG_STATUS_CURST_MASK                   (0xF0000000U)
#define CDOG_STATUS_CURST_SHIFT                  (28U)
/*! CURST - Current State */
#define CDOG_STATUS_CURST(x)                     (((uint32_t)(((uint32_t)(x)) << CDOG_STATUS_CURST_SHIFT)) & CDOG_STATUS_CURST_MASK)
/*! @} */

/*! @name STATUS2 - Status 2 Register */
/*! @{ */

#define CDOG_STATUS2_NUMCNTF_MASK                (0xFFU)
#define CDOG_STATUS2_NUMCNTF_SHIFT               (0U)
/*! NUMCNTF - Number of CONTROL faults since the last POR */
#define CDOG_STATUS2_NUMCNTF(x)                  (((uint32_t)(((uint32_t)(x)) << CDOG_STATUS2_NUMCNTF_SHIFT)) & CDOG_STATUS2_NUMCNTF_MASK)

#define CDOG_STATUS2_NUMILLSTF_MASK              (0xFF00U)
#define CDOG_STATUS2_NUMILLSTF_SHIFT             (8U)
/*! NUMILLSTF - Number of STATE faults since the last POR */
#define CDOG_STATUS2_NUMILLSTF(x)                (((uint32_t)(((uint32_t)(x)) << CDOG_STATUS2_NUMILLSTF_SHIFT)) & CDOG_STATUS2_NUMILLSTF_MASK)

#define CDOG_STATUS2_NUMILLA_MASK                (0xFF0000U)
#define CDOG_STATUS2_NUMILLA_SHIFT               (16U)
/*! NUMILLA - Number of ADDRESS faults since the last POR */
#define CDOG_STATUS2_NUMILLA(x)                  (((uint32_t)(((uint32_t)(x)) << CDOG_STATUS2_NUMILLA_SHIFT)) & CDOG_STATUS2_NUMILLA_MASK)
/*! @} */

/*! @name FLAGS - Flags Register */
/*! @{ */

#define CDOG_FLAGS_TO_FLAG_MASK                  (0x1U)
#define CDOG_FLAGS_TO_FLAG_SHIFT                 (0U)
/*! TO_FLAG - TIMEOUT fault flag
 *  0b0..A TIMEOUT fault has not occurred
 *  0b1..A TIMEOUT fault has occurred
 */
#define CDOG_FLAGS_TO_FLAG(x)                    (((uint32_t)(((uint32_t)(x)) << CDOG_FLAGS_TO_FLAG_SHIFT)) & CDOG_FLAGS_TO_FLAG_MASK)

#define CDOG_FLAGS_MISCOM_FLAG_MASK              (0x2U)
#define CDOG_FLAGS_MISCOM_FLAG_SHIFT             (1U)
/*! MISCOM_FLAG - MISCOMPARE fault flag
 *  0b0..A MISCOMPARE fault has not occurred
 *  0b1..A MISCOMPARE fault has occurred
 */
#define CDOG_FLAGS_MISCOM_FLAG(x)                (((uint32_t)(((uint32_t)(x)) << CDOG_FLAGS_MISCOM_FLAG_SHIFT)) & CDOG_FLAGS_MISCOM_FLAG_MASK)

#define CDOG_FLAGS_SEQ_FLAG_MASK                 (0x4U)
#define CDOG_FLAGS_SEQ_FLAG_SHIFT                (2U)
/*! SEQ_FLAG - SEQUENCE fault flag
 *  0b0..A SEQUENCE fault has not occurred
 *  0b1..A SEQUENCE fault has occurred
 */
#define CDOG_FLAGS_SEQ_FLAG(x)                   (((uint32_t)(((uint32_t)(x)) << CDOG_FLAGS_SEQ_FLAG_SHIFT)) & CDOG_FLAGS_SEQ_FLAG_MASK)

#define CDOG_FLAGS_CNT_FLAG_MASK                 (0x8U)
#define CDOG_FLAGS_CNT_FLAG_SHIFT                (3U)
/*! CNT_FLAG - CONTROL fault flag
 *  0b0..A CONTROL fault has not occurred
 *  0b1..A CONTROL fault has occurred
 */
#define CDOG_FLAGS_CNT_FLAG(x)                   (((uint32_t)(((uint32_t)(x)) << CDOG_FLAGS_CNT_FLAG_SHIFT)) & CDOG_FLAGS_CNT_FLAG_MASK)

#define CDOG_FLAGS_STATE_FLAG_MASK               (0x10U)
#define CDOG_FLAGS_STATE_FLAG_SHIFT              (4U)
/*! STATE_FLAG - STATE fault flag
 *  0b0..A STATE fault has not occurred
 *  0b1..A STATE fault has occurred
 */
#define CDOG_FLAGS_STATE_FLAG(x)                 (((uint32_t)(((uint32_t)(x)) << CDOG_FLAGS_STATE_FLAG_SHIFT)) & CDOG_FLAGS_STATE_FLAG_MASK)

#define CDOG_FLAGS_ADDR_FLAG_MASK                (0x20U)
#define CDOG_FLAGS_ADDR_FLAG_SHIFT               (5U)
/*! ADDR_FLAG - ADDRESS fault flag
 *  0b0..An ADDRESS fault has not occurred
 *  0b1..An ADDRESS fault has occurred
 */
#define CDOG_FLAGS_ADDR_FLAG(x)                  (((uint32_t)(((uint32_t)(x)) << CDOG_FLAGS_ADDR_FLAG_SHIFT)) & CDOG_FLAGS_ADDR_FLAG_MASK)

#define CDOG_FLAGS_POR_FLAG_MASK                 (0x10000U)
#define CDOG_FLAGS_POR_FLAG_SHIFT                (16U)
/*! POR_FLAG - Power-on reset flag
 *  0b0..A Power-on reset event has not occurred
 *  0b1..A Power-on reset event has occurred
 */
#define CDOG_FLAGS_POR_FLAG(x)                   (((uint32_t)(((uint32_t)(x)) << CDOG_FLAGS_POR_FLAG_SHIFT)) & CDOG_FLAGS_POR_FLAG_MASK)
/*! @} */

/*! @name PERSISTENT - Persistent Data Storage Register */
/*! @{ */

#define CDOG_PERSISTENT_PERSIS_MASK              (0xFFFFFFFFU)
#define CDOG_PERSISTENT_PERSIS_SHIFT             (0U)
/*! PERSIS - Persistent Storage */
#define CDOG_PERSISTENT_PERSIS(x)                (((uint32_t)(((uint32_t)(x)) << CDOG_PERSISTENT_PERSIS_SHIFT)) & CDOG_PERSISTENT_PERSIS_MASK)
/*! @} */

/*! @name START - START Command Register */
/*! @{ */

#define CDOG_START_STRT_MASK                     (0xFFFFFFFFU)
#define CDOG_START_STRT_SHIFT                    (0U)
/*! STRT - Start command */
#define CDOG_START_STRT(x)                       (((uint32_t)(((uint32_t)(x)) << CDOG_START_STRT_SHIFT)) & CDOG_START_STRT_MASK)
/*! @} */

/*! @name STOP - STOP Command Register */
/*! @{ */

#define CDOG_STOP_STP_MASK                       (0xFFFFFFFFU)
#define CDOG_STOP_STP_SHIFT                      (0U)
/*! STP - Stop command */
#define CDOG_STOP_STP(x)                         (((uint32_t)(((uint32_t)(x)) << CDOG_STOP_STP_SHIFT)) & CDOG_STOP_STP_MASK)
/*! @} */

/*! @name RESTART - RESTART Command Register */
/*! @{ */

#define CDOG_RESTART_RSTRT_MASK                  (0xFFFFFFFFU)
#define CDOG_RESTART_RSTRT_SHIFT                 (0U)
/*! RSTRT - Restart command */
#define CDOG_RESTART_RSTRT(x)                    (((uint32_t)(((uint32_t)(x)) << CDOG_RESTART_RSTRT_SHIFT)) & CDOG_RESTART_RSTRT_MASK)
/*! @} */

/*! @name ADD - ADD Command Register */
/*! @{ */

#define CDOG_ADD_AD_MASK                         (0xFFFFFFFFU)
#define CDOG_ADD_AD_SHIFT                        (0U)
/*! AD - ADD Write Value */
#define CDOG_ADD_AD(x)                           (((uint32_t)(((uint32_t)(x)) << CDOG_ADD_AD_SHIFT)) & CDOG_ADD_AD_MASK)
/*! @} */

/*! @name ADD1 - ADD1 Command Register */
/*! @{ */

#define CDOG_ADD1_AD1_MASK                       (0xFFFFFFFFU)
#define CDOG_ADD1_AD1_SHIFT                      (0U)
/*! AD1 - ADD 1 */
#define CDOG_ADD1_AD1(x)                         (((uint32_t)(((uint32_t)(x)) << CDOG_ADD1_AD1_SHIFT)) & CDOG_ADD1_AD1_MASK)
/*! @} */

/*! @name ADD16 - ADD16 Command Register */
/*! @{ */

#define CDOG_ADD16_AD16_MASK                     (0xFFFFFFFFU)
#define CDOG_ADD16_AD16_SHIFT                    (0U)
/*! AD16 - ADD 16 */
#define CDOG_ADD16_AD16(x)                       (((uint32_t)(((uint32_t)(x)) << CDOG_ADD16_AD16_SHIFT)) & CDOG_ADD16_AD16_MASK)
/*! @} */

/*! @name ADD256 - ADD256 Command Register */
/*! @{ */

#define CDOG_ADD256_AD256_MASK                   (0xFFFFFFFFU)
#define CDOG_ADD256_AD256_SHIFT                  (0U)
/*! AD256 - ADD 256 */
#define CDOG_ADD256_AD256(x)                     (((uint32_t)(((uint32_t)(x)) << CDOG_ADD256_AD256_SHIFT)) & CDOG_ADD256_AD256_MASK)
/*! @} */

/*! @name SUB - SUB Command Register */
/*! @{ */

#define CDOG_SUB_SB_MASK                         (0xFFFFFFFFU)
#define CDOG_SUB_SB_SHIFT                        (0U)
/*! SB - Subtract Write Value */
#define CDOG_SUB_SB(x)                           (((uint32_t)(((uint32_t)(x)) << CDOG_SUB_SB_SHIFT)) & CDOG_SUB_SB_MASK)
/*! @} */

/*! @name SUB1 - SUB1 Command Register */
/*! @{ */

#define CDOG_SUB1_SB1_MASK                       (0xFFFFFFFFU)
#define CDOG_SUB1_SB1_SHIFT                      (0U)
/*! SB1 - Subtract 1 */
#define CDOG_SUB1_SB1(x)                         (((uint32_t)(((uint32_t)(x)) << CDOG_SUB1_SB1_SHIFT)) & CDOG_SUB1_SB1_MASK)
/*! @} */

/*! @name SUB16 - SUB16 Command Register */
/*! @{ */

#define CDOG_SUB16_SB16_MASK                     (0xFFFFFFFFU)
#define CDOG_SUB16_SB16_SHIFT                    (0U)
/*! SB16 - Subtract 16 */
#define CDOG_SUB16_SB16(x)                       (((uint32_t)(((uint32_t)(x)) << CDOG_SUB16_SB16_SHIFT)) & CDOG_SUB16_SB16_MASK)
/*! @} */

/*! @name SUB256 - SUB256 Command Register */
/*! @{ */

#define CDOG_SUB256_SB256_MASK                   (0xFFFFFFFFU)
#define CDOG_SUB256_SB256_SHIFT                  (0U)
/*! SB256 - Subtract 256 */
#define CDOG_SUB256_SB256(x)                     (((uint32_t)(((uint32_t)(x)) << CDOG_SUB256_SB256_SHIFT)) & CDOG_SUB256_SB256_MASK)
/*! @} */

/*! @name ASSERT16 - ASSERT16 Command Register */
/*! @{ */

#define CDOG_ASSERT16_AST16_MASK                 (0xFFFFFFFFU)
#define CDOG_ASSERT16_AST16_SHIFT                (0U)
/*! AST16 - ASSERT16 Command */
#define CDOG_ASSERT16_AST16(x)                   (((uint32_t)(((uint32_t)(x)) << CDOG_ASSERT16_AST16_SHIFT)) & CDOG_ASSERT16_AST16_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CDOG_Register_Masks */


/*!
 * @}
 */ /* end of group CDOG_Peripheral_Access_Layer */


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


#endif  /* PERI_CDOG_H_ */

