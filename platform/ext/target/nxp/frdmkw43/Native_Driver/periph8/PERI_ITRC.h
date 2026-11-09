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
**         CMSIS Peripheral Access Layer for ITRC
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
 * @file PERI_ITRC.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for ITRC
 *
 * CMSIS Peripheral Access Layer for ITRC
 */

#if !defined(PERI_ITRC_H_)
#define PERI_ITRC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- ITRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITRC_Peripheral_Access_Layer ITRC Peripheral Access Layer
 * @{
 */

/** ITRC - Size of Registers Arrays */
#define ITRC_OUTX_SEL_COUNT                       3u
#define ITRC_OUTX_SEL_OUTX_SELY_COUNT             2u
#define ITRC_OUTX_SEL_1_COUNT                     3u
#define ITRC_OUTX_SEL_1_OUTX_SELY_COUNT           2u
#define ITRC_OUTX_SEL_2_COUNT                     3u
#define ITRC_OUTX_SEL_2_OUTX_SELY_COUNT           2u

/** ITRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t STATUS;                            /**< ITRC outputs and IN0 to IN15 Status, offset: 0x0 */
  __IO uint32_t STATUS1;                           /**< ITRC IN16 to IN47 Status, offset: 0x4 */
  __IO uint32_t OUT_SEL[ITRC_OUTX_SEL_COUNT][ITRC_OUTX_SEL_OUTX_SELY_COUNT]; /**< Trigger Source IN0 to IN15 selector, array offset: 0x8, array step: index*0x8, index2*0x4 */
       uint8_t RESERVED_0[40];
  __IO uint32_t OUT_SEL_1[ITRC_OUTX_SEL_1_COUNT][ITRC_OUTX_SEL_1_OUTX_SELY_COUNT]; /**< Trigger Source IN16 to IN31 selector, array offset: 0x48, array step: index*0x8, index2*0x4 */
       uint8_t RESERVED_1[40];
  __IO uint32_t OUT_SEL_2[ITRC_OUTX_SEL_2_COUNT][ITRC_OUTX_SEL_2_OUTX_SELY_COUNT]; /**< Trigger source IN32 to IN47 selector, array offset: 0x88, array step: index*0x8, index2*0x4 */
       uint8_t RESERVED_2[80];
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
/*! IN0_STATUS - ORed output of IRQ signal coming from digital glitch detector (dGDET).
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN0_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN0_STATUS_SHIFT)) & ITRC_STATUS_IN0_STATUS_MASK)

#define ITRC_STATUS_IN4_STATUS_MASK              (0x10U)
#define ITRC_STATUS_IN4_STATUS_SHIFT             (4U)
/*! IN4_STATUS - IRQ coming from CDOG0.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN4_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN4_STATUS_SHIFT)) & ITRC_STATUS_IN4_STATUS_MASK)

#define ITRC_STATUS_IN5_STATUS_MASK              (0x20U)
#define ITRC_STATUS_IN5_STATUS_SHIFT             (5U)
/*! IN5_STATUS - IRQ coming from CDOG1.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN5_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN5_STATUS_SHIFT)) & ITRC_STATUS_IN5_STATUS_MASK)

#define ITRC_STATUS_IN9_STATUS_MASK              (0x200U)
#define ITRC_STATUS_IN9_STATUS_SHIFT             (9U)
/*! IN9_STATUS - IRQ coming from WDOG0.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN9_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN9_STATUS_SHIFT)) & ITRC_STATUS_IN9_STATUS_MASK)

#define ITRC_STATUS_IN10_STATUS_MASK             (0x400U)
#define ITRC_STATUS_IN10_STATUS_SHIFT            (10U)
/*! IN10_STATUS - IRQ coming from WDOG1.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN10_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN10_STATUS_SHIFT)) & ITRC_STATUS_IN10_STATUS_MASK)

#define ITRC_STATUS_IN11_STATUS_MASK             (0x800U)
#define ITRC_STATUS_IN11_STATUS_SHIFT            (11U)
/*! IN11_STATUS - UDF Error Event from udf_err output signal.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN11_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN11_STATUS_SHIFT)) & ITRC_STATUS_IN11_STATUS_MASK)

#define ITRC_STATUS_IN13_STATUS_MASK             (0x2000U)
#define ITRC_STATUS_IN13_STATUS_SHIFT            (13U)
/*! IN13_STATUS - Error Event from ORed output of IRQ signals from LVD HVD VDD_Core.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN13_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN13_STATUS_SHIFT)) & ITRC_STATUS_IN13_STATUS_MASK)

#define ITRC_STATUS_IN15_STATUS_MASK             (0x8000U)
#define ITRC_STATUS_IN15_STATUS_SHIFT            (15U)
/*! IN15_STATUS - Error Event only from HVD VDD_IO.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN15_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN15_STATUS_SHIFT)) & ITRC_STATUS_IN15_STATUS_MASK)

#define ITRC_STATUS_OUT0_STATUS_MASK             (0x10000U)
#define ITRC_STATUS_OUT0_STATUS_SHIFT            (16U)
/*! OUT0_STATUS - ITRC triggered RAM_Zeroize output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT0_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT0_STATUS_SHIFT)) & ITRC_STATUS_OUT0_STATUS_MASK)

#define ITRC_STATUS_OUT1_STATUS_MASK             (0x20000U)
#define ITRC_STATUS_OUT1_STATUS_SHIFT            (17U)
/*! OUT1_STATUS - ITRC triggered chip reset output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT1_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT1_STATUS_SHIFT)) & ITRC_STATUS_OUT1_STATUS_MASK)

#define ITRC_STATUS_OUT2_STATUS_MASK             (0x40000U)
#define ITRC_STATUS_OUT2_STATUS_SHIFT            (18U)
/*! OUT2_STATUS - ITRC triggered ITRC_IRQ output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT2_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT2_STATUS_SHIFT)) & ITRC_STATUS_OUT2_STATUS_MASK)
/*! @} */

/*! @name STATUS1 - ITRC IN16 to IN47 Status */
/*! @{ */

#define ITRC_STATUS1_IN16_STATUS_MASK            (0x1U)
#define ITRC_STATUS1_IN16_STATUS_SHIFT           (0U)
/*! IN16_STATUS - Error Event coming from AGDET VDD_CORE.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN16_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN16_STATUS_SHIFT)) & ITRC_STATUS1_IN16_STATUS_MASK)

#define ITRC_STATUS1_IN17_STATUS_MASK            (0x2U)
#define ITRC_STATUS1_IN17_STATUS_SHIFT           (1U)
/*! IN17_STATUS - TRDC ERROR EVENT whenever MBC_Err_UPD is raised.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN17_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN17_STATUS_SHIFT)) & ITRC_STATUS1_IN17_STATUS_MASK)

#define ITRC_STATUS1_IN18_STATUS_MASK            (0x4U)
#define ITRC_STATUS1_IN18_STATUS_SHIFT           (2U)
/*! IN18_STATUS - Output error event coming from out of range ADC Temperature sensor.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN18_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN18_STATUS_SHIFT)) & ITRC_STATUS1_IN18_STATUS_MASK)

#define ITRC_STATUS1_IN20_STATUS_MASK            (0x10U)
#define ITRC_STATUS1_IN20_STATUS_SHIFT           (4U)
/*! IN20_STATUS - GLIKEY Interrupt.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN20_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN20_STATUS_SHIFT)) & ITRC_STATUS1_IN20_STATUS_MASK)

#define ITRC_STATUS1_IN21_STATUS_MASK            (0x20U)
#define ITRC_STATUS1_IN21_STATUS_SHIFT           (5U)
/*! IN21_STATUS - Glikey Error Signal from SECCON Glikey Instance.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN21_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN21_STATUS_SHIFT)) & ITRC_STATUS1_IN21_STATUS_MASK)

#define ITRC_STATUS1_IN24_STATUS_MASK            (0x100U)
#define ITRC_STATUS1_IN24_STATUS_SHIFT           (8U)
/*! IN24_STATUS - Error Event coming from PKC block.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN24_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN24_STATUS_SHIFT)) & ITRC_STATUS1_IN24_STATUS_MASK)

#define ITRC_STATUS1_IN25_STATUS_MASK            (0x200U)
#define ITRC_STATUS1_IN25_STATUS_SHIFT           (9U)
/*! IN25_STATUS - Error Event coming from all detected errors as indicated by the 'o_error[2:0] output signal of SGI.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN25_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN25_STATUS_SHIFT)) & ITRC_STATUS1_IN25_STATUS_MASK)

#define ITRC_STATUS1_IN26_STATUS_MASK            (0x400U)
#define ITRC_STATUS1_IN26_STATUS_SHIFT           (10U)
/*! IN26_STATUS - Error Event Flag coming from Clock Monitor.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN26_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN26_STATUS_SHIFT)) & ITRC_STATUS1_IN26_STATUS_MASK)

#define ITRC_STATUS1_IN31_STATUS_MASK            (0x8000U)
#define ITRC_STATUS1_IN31_STATUS_SHIFT           (15U)
/*! IN31_STATUS - Error Event Flag from Tamper 1
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN31_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN31_STATUS_SHIFT)) & ITRC_STATUS1_IN31_STATUS_MASK)

#define ITRC_STATUS1_IN32_STATUS_MASK            (0x10000U)
#define ITRC_STATUS1_IN32_STATUS_SHIFT           (16U)
/*! IN32_STATUS - Error Event Flag from Tamper 2.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN32_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN32_STATUS_SHIFT)) & ITRC_STATUS1_IN32_STATUS_MASK)

#define ITRC_STATUS1_IN33_STATUS_MASK            (0x20000U)
#define ITRC_STATUS1_IN33_STATUS_SHIFT           (17U)
/*! IN33_STATUS - Error Event Flag from Tamper 3.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN33_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN33_STATUS_SHIFT)) & ITRC_STATUS1_IN33_STATUS_MASK)

#define ITRC_STATUS1_IN34_STATUS_MASK            (0x40000U)
#define ITRC_STATUS1_IN34_STATUS_SHIFT           (18U)
/*! IN34_STATUS - IRQ from Tamper Detect Pin Assert.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN34_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN34_STATUS_SHIFT)) & ITRC_STATUS1_IN34_STATUS_MASK)

#define ITRC_STATUS1_IN35_STATUS_MASK            (0x80000U)
#define ITRC_STATUS1_IN35_STATUS_SHIFT           (19U)
/*! IN35_STATUS - SW Event 0 set by SW writing.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN35_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN35_STATUS_SHIFT)) & ITRC_STATUS1_IN35_STATUS_MASK)

#define ITRC_STATUS1_IN36_STATUS_MASK            (0x100000U)
#define ITRC_STATUS1_IN36_STATUS_SHIFT           (20U)
/*! IN36_STATUS - SW Event 1 set by SW writing.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS1_IN36_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS1_IN36_STATUS_SHIFT)) & ITRC_STATUS1_IN36_STATUS_MASK)
/*! @} */

/*! @name OUT_SEL - Trigger Source IN0 to IN15 selector */
/*! @{ */

#define ITRC_OUT_SEL_IN0_SELn_MASK               (0x3U)
#define ITRC_OUT_SEL_IN0_SELn_SHIFT              (0U)
/*! IN0_SELn - Selects ORed output of IRQ signal coming from digital glitch detector (dGDET) as a trigger source. */
#define ITRC_OUT_SEL_IN0_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN0_SELn_SHIFT)) & ITRC_OUT_SEL_IN0_SELn_MASK)

#define ITRC_OUT_SEL_IN4_SELn_MASK               (0x300U)
#define ITRC_OUT_SEL_IN4_SELn_SHIFT              (8U)
/*! IN4_SELn - Selects IRQ coming from CDOG0 as a trigger source. */
#define ITRC_OUT_SEL_IN4_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN4_SELn_SHIFT)) & ITRC_OUT_SEL_IN4_SELn_MASK)

#define ITRC_OUT_SEL_IN5_SELn_MASK               (0xC00U)
#define ITRC_OUT_SEL_IN5_SELn_SHIFT              (10U)
/*! IN5_SELn - Selects IRQ coming from CDOG1 as a trigger source. */
#define ITRC_OUT_SEL_IN5_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN5_SELn_SHIFT)) & ITRC_OUT_SEL_IN5_SELn_MASK)

#define ITRC_OUT_SEL_IN9_SELn_MASK               (0xC0000U)
#define ITRC_OUT_SEL_IN9_SELn_SHIFT              (18U)
/*! IN9_SELn - Selects IRQ coming from WDOG0 as a trigger source. */
#define ITRC_OUT_SEL_IN9_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN9_SELn_SHIFT)) & ITRC_OUT_SEL_IN9_SELn_MASK)

#define ITRC_OUT_SEL_IN10_SELn_MASK              (0x300000U)
#define ITRC_OUT_SEL_IN10_SELn_SHIFT             (20U)
/*! IN10_SELn - Selects IRQ coming from WDOG1 as a trigger source. */
#define ITRC_OUT_SEL_IN10_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN10_SELn_SHIFT)) & ITRC_OUT_SEL_IN10_SELn_MASK)

#define ITRC_OUT_SEL_IN11_SELn_MASK              (0xC00000U)
#define ITRC_OUT_SEL_IN11_SELn_SHIFT             (22U)
/*! IN11_SELn - Selects UDF Error Event from udf_err output signal as a trigger source. */
#define ITRC_OUT_SEL_IN11_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN11_SELn_SHIFT)) & ITRC_OUT_SEL_IN11_SELn_MASK)

#define ITRC_OUT_SEL_IN13_SELn_MASK              (0xC000000U)
#define ITRC_OUT_SEL_IN13_SELn_SHIFT             (26U)
/*! IN13_SELn - Selects Error Event from ORed output of IRQ signals from LVD HVD VDD_Core as a trigger source. */
#define ITRC_OUT_SEL_IN13_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN13_SELn_SHIFT)) & ITRC_OUT_SEL_IN13_SELn_MASK)

#define ITRC_OUT_SEL_IN15_SELn_MASK              (0xC0000000U)
#define ITRC_OUT_SEL_IN15_SELn_SHIFT             (30U)
/*! IN15_SELn - Selects Error Event only from HVD VDD_IO as a trigger source. */
#define ITRC_OUT_SEL_IN15_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN15_SELn_SHIFT)) & ITRC_OUT_SEL_IN15_SELn_MASK)
/*! @} */

/* The count of ITRC_OUT_SEL */
#define ITRC_OUT_SEL_COUNT                       (3U)

/* The count of ITRC_OUT_SEL */
#define ITRC_OUT_SEL_COUNT2                      (2U)

/*! @name OUT_SEL_1 - Trigger Source IN16 to IN31 selector */
/*! @{ */

#define ITRC_OUT_SEL_1_IN16_SELn_MASK            (0x3U)
#define ITRC_OUT_SEL_1_IN16_SELn_SHIFT           (0U)
/*! IN16_SELn - Selects Error Event coming from AGDET VDD_CORE as a trigger source. */
#define ITRC_OUT_SEL_1_IN16_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN16_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN16_SELn_MASK)

#define ITRC_OUT_SEL_1_IN17_SELn_MASK            (0xCU)
#define ITRC_OUT_SEL_1_IN17_SELn_SHIFT           (2U)
/*! IN17_SELn - Selects TRDC ERROR EVENT, whenever MBC_Err_UPD is raised, as a trigger source. */
#define ITRC_OUT_SEL_1_IN17_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN17_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN17_SELn_MASK)

#define ITRC_OUT_SEL_1_IN18_SELn_MASK            (0x30U)
#define ITRC_OUT_SEL_1_IN18_SELn_SHIFT           (4U)
/*! IN18_SELn - Selects Output error event coming from out of range ADC Temperature sensor as a trigger source. */
#define ITRC_OUT_SEL_1_IN18_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN18_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN18_SELn_MASK)

#define ITRC_OUT_SEL_1_IN20_SELn_MASK            (0x300U)
#define ITRC_OUT_SEL_1_IN20_SELn_SHIFT           (8U)
/*! IN20_SELn - Selects GLIKEY Interrup as a trigger source. */
#define ITRC_OUT_SEL_1_IN20_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN20_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN20_SELn_MASK)

#define ITRC_OUT_SEL_1_IN21_SELn_MASK            (0xC00U)
#define ITRC_OUT_SEL_1_IN21_SELn_SHIFT           (10U)
/*! IN21_SELn - Selects Glikey Error Signal from SECCON GLIKEY instance as a trigger source. */
#define ITRC_OUT_SEL_1_IN21_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN21_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN21_SELn_MASK)

#define ITRC_OUT_SEL_1_IN24_SELn_MASK            (0x30000U)
#define ITRC_OUT_SEL_1_IN24_SELn_SHIFT           (16U)
/*! IN24_SELn - Selects error event coming from PKC block as a trigger source. */
#define ITRC_OUT_SEL_1_IN24_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN24_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN24_SELn_MASK)

#define ITRC_OUT_SEL_1_IN25_SELn_MASK            (0xC0000U)
#define ITRC_OUT_SEL_1_IN25_SELn_SHIFT           (18U)
/*! IN25_SELn - Error event coming from all detected errors output signal of SGI as a trigger source. */
#define ITRC_OUT_SEL_1_IN25_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN25_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN25_SELn_MASK)

#define ITRC_OUT_SEL_1_IN26_SELn_MASK            (0x300000U)
#define ITRC_OUT_SEL_1_IN26_SELn_SHIFT           (20U)
/*! IN26_SELn - Error event flag coming from clock monitor as a trigger source. */
#define ITRC_OUT_SEL_1_IN26_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN26_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN26_SELn_MASK)

#define ITRC_OUT_SEL_1_IN31_SELn_MASK            (0xC0000000U)
#define ITRC_OUT_SEL_1_IN31_SELn_SHIFT           (30U)
/*! IN31_SELn - Selects error event flag from Tamper 1 as a trigger source. */
#define ITRC_OUT_SEL_1_IN31_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_1_IN31_SELn_SHIFT)) & ITRC_OUT_SEL_1_IN31_SELn_MASK)
/*! @} */

/* The count of ITRC_OUT_SEL_1 */
#define ITRC_OUT_SEL_1_COUNT                     (3U)

/* The count of ITRC_OUT_SEL_1 */
#define ITRC_OUT_SEL_1_COUNT2                    (2U)

/*! @name OUT_SEL_2 - Trigger source IN32 to IN47 selector */
/*! @{ */

#define ITRC_OUT_SEL_2_IN32_SELn_MASK            (0x3U)
#define ITRC_OUT_SEL_2_IN32_SELn_SHIFT           (0U)
/*! IN32_SELn - Selects error event flag from Tamper 2 as a trigger source. */
#define ITRC_OUT_SEL_2_IN32_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN32_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN32_SELn_MASK)

#define ITRC_OUT_SEL_2_IN33_SELn_MASK            (0xCU)
#define ITRC_OUT_SEL_2_IN33_SELn_SHIFT           (2U)
/*! IN33_SELn - Selects error event flag from Tamper 3 as a trigger source. */
#define ITRC_OUT_SEL_2_IN33_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN33_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN33_SELn_MASK)

#define ITRC_OUT_SEL_2_IN34_SELn_MASK            (0x30U)
#define ITRC_OUT_SEL_2_IN34_SELn_SHIFT           (4U)
/*! IN34_SELn - Selects IRQ from Tamper Detect Pin Assert as a trigger source. */
#define ITRC_OUT_SEL_2_IN34_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN34_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN34_SELn_MASK)

#define ITRC_OUT_SEL_2_IN35_SELn_MASK            (0xC0U)
#define ITRC_OUT_SEL_2_IN35_SELn_SHIFT           (6U)
/*! IN35_SELn - Selects SW Event 0 set by SW writing as a trigger source. */
#define ITRC_OUT_SEL_2_IN35_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN35_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN35_SELn_MASK)

#define ITRC_OUT_SEL_2_IN36_SELn_MASK            (0x300U)
#define ITRC_OUT_SEL_2_IN36_SELn_SHIFT           (8U)
/*! IN36_SELn - Selects SW Event 1 set by SW writing as a trigger source. */
#define ITRC_OUT_SEL_2_IN36_SELn(x)              (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_2_IN36_SELn_SHIFT)) & ITRC_OUT_SEL_2_IN36_SELn_MASK)
/*! @} */

/* The count of ITRC_OUT_SEL_2 */
#define ITRC_OUT_SEL_2_COUNT                     (3U)

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

