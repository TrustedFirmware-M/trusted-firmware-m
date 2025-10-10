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
**         CMSIS Peripheral Access Layer for DIGTMP
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
 * @file PERI_DIGTMP.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DIGTMP
 *
 * CMSIS Peripheral Access Layer for DIGTMP
 */

#if !defined(PERI_DIGTMP_H_)
#define PERI_DIGTMP_H_                           /**< Symbol preventing repeated inclusion */

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
   -- DIGTMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIGTMP_Peripheral_Access_Layer DIGTMP Peripheral Access Layer
 * @{
 */

/** DIGTMP - Size of Registers Arrays */
#define DIGTMP_ATR_COUNT                          2u
#define DIGTMP_PGFR_COUNT                         8u

/** DIGTMP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t CR;                                /**< Control, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status, offset: 0x14 */
  __IO uint32_t LR;                                /**< Lock, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t TSR;                               /**< Tamper Seconds, offset: 0x20 */
  __IO uint32_t TER;                               /**< Tamper Enable, offset: 0x24 */
  __IO uint32_t PDR;                               /**< Pin Direction, offset: 0x28 */
  __IO uint32_t PPR;                               /**< Pin Polarity, offset: 0x2C */
  __IO uint32_t ATR[DIGTMP_ATR_COUNT];             /**< Active Tamper, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PGFR[DIGTMP_PGFR_COUNT];           /**< Pin Glitch Filter, array offset: 0x40, array step: 0x4 */
} DIGTMP_Type;

/* ----------------------------------------------------------------------------
   -- DIGTMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIGTMP_Register_Masks DIGTMP Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define DIGTMP_CR_SWR_MASK                       (0x1U)
#define DIGTMP_CR_SWR_SHIFT                      (0U)
/*! SWR - Software Reset
 *  0b0..No effect
 *  0b1..Perform a software reset
 */
#define DIGTMP_CR_SWR(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_SWR_SHIFT)) & DIGTMP_CR_SWR_MASK)

#define DIGTMP_CR_DEN_MASK                       (0x2U)
#define DIGTMP_CR_DEN_SHIFT                      (1U)
/*! DEN - Digital Tamper Enable
 *  0b0..Disables TDET clock and prescaler
 *  0b1..Enables TDET clock and prescaler
 */
#define DIGTMP_CR_DEN(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_DEN_SHIFT)) & DIGTMP_CR_DEN_MASK)

#define DIGTMP_CR_TFSR_MASK                      (0x4U)
#define DIGTMP_CR_TFSR_SHIFT                     (2U)
/*! TFSR - Tamper Force System Reset
 *  0b0..Do not force chip reset
 *  0b1..Force chip reset
 */
#define DIGTMP_CR_TFSR(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_TFSR_SHIFT)) & DIGTMP_CR_TFSR_MASK)

#define DIGTMP_CR_UM_MASK                        (0x8U)
#define DIGTMP_CR_UM_SHIFT                       (3U)
/*! UM - Update Mode
 *  0b0..No effect
 *  0b1..Allows the clearing of interrupts
 */
#define DIGTMP_CR_UM(x)                          (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_UM_SHIFT)) & DIGTMP_CR_UM_MASK)

#define DIGTMP_CR_ATCS0_MASK                     (0x10U)
#define DIGTMP_CR_ATCS0_SHIFT                    (4U)
/*! ATCS0 - Active Tamper Clock Source
 *  0b0..1 Hz prescaler clock
 *  0b1..64 Hz prescaler clock
 */
#define DIGTMP_CR_ATCS0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_ATCS0_SHIFT)) & DIGTMP_CR_ATCS0_MASK)

#define DIGTMP_CR_ATCS1_MASK                     (0x20U)
#define DIGTMP_CR_ATCS1_SHIFT                    (5U)
/*! ATCS1 - Active Tamper Clock Source
 *  0b0..1 Hz prescaler clock
 *  0b1..64 Hz prescaler clock
 */
#define DIGTMP_CR_ATCS1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_ATCS1_SHIFT)) & DIGTMP_CR_ATCS1_MASK)

#define DIGTMP_CR_DISTAM_MASK                    (0x100U)
#define DIGTMP_CR_DISTAM_SHIFT                   (8U)
/*! DISTAM - Disable Prescaler On Tamper
 *  0b0..No effect
 *  0b1..Automatically disables the prescaler after tamper detection
 */
#define DIGTMP_CR_DISTAM(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_DISTAM_SHIFT)) & DIGTMP_CR_DISTAM_MASK)

#define DIGTMP_CR_DPR_MASK                       (0xFFFE0000U)
#define DIGTMP_CR_DPR_SHIFT                      (17U)
/*! DPR - Digital Tamper Prescaler */
#define DIGTMP_CR_DPR(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_DPR_SHIFT)) & DIGTMP_CR_DPR_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define DIGTMP_SR_DTF_MASK                       (0x1U)
#define DIGTMP_SR_DTF_SHIFT                      (0U)
/*! DTF - Digital Tamper Flag
 *  0b0..TDET tampering not detected
 *  0b1..TDET tampering detected
 */
#define DIGTMP_SR_DTF(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_DTF_SHIFT)) & DIGTMP_SR_DTF_MASK)

#define DIGTMP_SR_TAF_MASK                       (0x2U)
#define DIGTMP_SR_TAF_SHIFT                      (1U)
/*! TAF - Tamper Acknowledge Flag
 *  0b0..Digital Tamper Flag (SR[DTF]) is clear or chip reset has not occurred after Digital Tamper Flag (SR[DTF]) was set.
 *  0b1..Chip reset has occurred after Digital Tamper Flag (SR[DTF]) was set.
 */
#define DIGTMP_SR_TAF(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TAF_SHIFT)) & DIGTMP_SR_TAF_MASK)

#define DIGTMP_SR_TIF0_MASK                      (0x4U)
#define DIGTMP_SR_TIF0_SHIFT                     (2U)
/*! TIF0 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF0_SHIFT)) & DIGTMP_SR_TIF0_MASK)

#define DIGTMP_SR_TIF1_MASK                      (0x8U)
#define DIGTMP_SR_TIF1_SHIFT                     (3U)
/*! TIF1 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF1(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF1_SHIFT)) & DIGTMP_SR_TIF1_MASK)

#define DIGTMP_SR_TIF2_MASK                      (0x10U)
#define DIGTMP_SR_TIF2_SHIFT                     (4U)
/*! TIF2 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF2(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF2_SHIFT)) & DIGTMP_SR_TIF2_MASK)

#define DIGTMP_SR_TIF3_MASK                      (0x20U)
#define DIGTMP_SR_TIF3_SHIFT                     (5U)
/*! TIF3 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF3(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF3_SHIFT)) & DIGTMP_SR_TIF3_MASK)

#define DIGTMP_SR_TIF4_MASK                      (0x40U)
#define DIGTMP_SR_TIF4_SHIFT                     (6U)
/*! TIF4 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF4(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF4_SHIFT)) & DIGTMP_SR_TIF4_MASK)

#define DIGTMP_SR_TIF5_MASK                      (0x80U)
#define DIGTMP_SR_TIF5_SHIFT                     (7U)
/*! TIF5 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF5(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF5_SHIFT)) & DIGTMP_SR_TIF5_MASK)

#define DIGTMP_SR_TIF6_MASK                      (0x100U)
#define DIGTMP_SR_TIF6_SHIFT                     (8U)
/*! TIF6 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF6(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF6_SHIFT)) & DIGTMP_SR_TIF6_MASK)

#define DIGTMP_SR_TIF7_MASK                      (0x200U)
#define DIGTMP_SR_TIF7_SHIFT                     (9U)
/*! TIF7 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF7(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF7_SHIFT)) & DIGTMP_SR_TIF7_MASK)

#define DIGTMP_SR_TIF8_MASK                      (0x400U)
#define DIGTMP_SR_TIF8_SHIFT                     (10U)
/*! TIF8 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF8(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF8_SHIFT)) & DIGTMP_SR_TIF8_MASK)

#define DIGTMP_SR_TIF9_MASK                      (0x800U)
#define DIGTMP_SR_TIF9_SHIFT                     (11U)
/*! TIF9 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF9(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF9_SHIFT)) & DIGTMP_SR_TIF9_MASK)

#define DIGTMP_SR_TPF0_MASK                      (0x10000U)
#define DIGTMP_SR_TPF0_SHIFT                     (16U)
/*! TPF0 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF0_SHIFT)) & DIGTMP_SR_TPF0_MASK)

#define DIGTMP_SR_TPF1_MASK                      (0x20000U)
#define DIGTMP_SR_TPF1_SHIFT                     (17U)
/*! TPF1 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF1(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF1_SHIFT)) & DIGTMP_SR_TPF1_MASK)

#define DIGTMP_SR_TPF2_MASK                      (0x40000U)
#define DIGTMP_SR_TPF2_SHIFT                     (18U)
/*! TPF2 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF2(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF2_SHIFT)) & DIGTMP_SR_TPF2_MASK)

#define DIGTMP_SR_TPF3_MASK                      (0x80000U)
#define DIGTMP_SR_TPF3_SHIFT                     (19U)
/*! TPF3 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF3(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF3_SHIFT)) & DIGTMP_SR_TPF3_MASK)

#define DIGTMP_SR_TPF4_MASK                      (0x100000U)
#define DIGTMP_SR_TPF4_SHIFT                     (20U)
/*! TPF4 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF4(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF4_SHIFT)) & DIGTMP_SR_TPF4_MASK)

#define DIGTMP_SR_TPF5_MASK                      (0x200000U)
#define DIGTMP_SR_TPF5_SHIFT                     (21U)
/*! TPF5 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF5(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF5_SHIFT)) & DIGTMP_SR_TPF5_MASK)

#define DIGTMP_SR_TPF6_MASK                      (0x400000U)
#define DIGTMP_SR_TPF6_SHIFT                     (22U)
/*! TPF6 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF6(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF6_SHIFT)) & DIGTMP_SR_TPF6_MASK)

#define DIGTMP_SR_TPF7_MASK                      (0x800000U)
#define DIGTMP_SR_TPF7_SHIFT                     (23U)
/*! TPF7 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF7(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF7_SHIFT)) & DIGTMP_SR_TPF7_MASK)
/*! @} */

/*! @name LR - Lock */
/*! @{ */

#define DIGTMP_LR_CRL_MASK                       (0x10U)
#define DIGTMP_LR_CRL_SHIFT                      (4U)
/*! CRL - Control Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_CRL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_CRL_SHIFT)) & DIGTMP_LR_CRL_MASK)

#define DIGTMP_LR_SRL_MASK                       (0x20U)
#define DIGTMP_LR_SRL_SHIFT                      (5U)
/*! SRL - Status Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_SRL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_SRL_SHIFT)) & DIGTMP_LR_SRL_MASK)

#define DIGTMP_LR_LRL_MASK                       (0x40U)
#define DIGTMP_LR_LRL_SHIFT                      (6U)
/*! LRL - Lock Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_LRL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_LRL_SHIFT)) & DIGTMP_LR_LRL_MASK)

#define DIGTMP_LR_IEL_MASK                       (0x80U)
#define DIGTMP_LR_IEL_SHIFT                      (7U)
/*! IEL - Interrupt Enable Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_IEL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_IEL_SHIFT)) & DIGTMP_LR_IEL_MASK)

#define DIGTMP_LR_TSL_MASK                       (0x100U)
#define DIGTMP_LR_TSL_SHIFT                      (8U)
/*! TSL - Tamper Seconds Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_TSL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_TSL_SHIFT)) & DIGTMP_LR_TSL_MASK)

#define DIGTMP_LR_TEL_MASK                       (0x200U)
#define DIGTMP_LR_TEL_SHIFT                      (9U)
/*! TEL - Tamper Enable Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_TEL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_TEL_SHIFT)) & DIGTMP_LR_TEL_MASK)

#define DIGTMP_LR_PDL_MASK                       (0x400U)
#define DIGTMP_LR_PDL_SHIFT                      (10U)
/*! PDL - Pin Direction Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_PDL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_PDL_SHIFT)) & DIGTMP_LR_PDL_MASK)

#define DIGTMP_LR_PPL_MASK                       (0x800U)
#define DIGTMP_LR_PPL_SHIFT                      (11U)
/*! PPL - Pin Polarity Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_PPL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_PPL_SHIFT)) & DIGTMP_LR_PPL_MASK)

#define DIGTMP_LR_ATL0_MASK                      (0x1000U)
#define DIGTMP_LR_ATL0_SHIFT                     (12U)
/*! ATL0 - Active Tamper Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_ATL0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_ATL0_SHIFT)) & DIGTMP_LR_ATL0_MASK)

#define DIGTMP_LR_ATL1_MASK                      (0x2000U)
#define DIGTMP_LR_ATL1_SHIFT                     (13U)
/*! ATL1 - Active Tamper Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_ATL1(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_ATL1_SHIFT)) & DIGTMP_LR_ATL1_MASK)

#define DIGTMP_LR_GFL0_MASK                      (0x10000U)
#define DIGTMP_LR_GFL0_SHIFT                     (16U)
/*! GFL0 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL0_SHIFT)) & DIGTMP_LR_GFL0_MASK)

#define DIGTMP_LR_GFL1_MASK                      (0x20000U)
#define DIGTMP_LR_GFL1_SHIFT                     (17U)
/*! GFL1 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL1(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL1_SHIFT)) & DIGTMP_LR_GFL1_MASK)

#define DIGTMP_LR_GFL2_MASK                      (0x40000U)
#define DIGTMP_LR_GFL2_SHIFT                     (18U)
/*! GFL2 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL2(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL2_SHIFT)) & DIGTMP_LR_GFL2_MASK)

#define DIGTMP_LR_GFL3_MASK                      (0x80000U)
#define DIGTMP_LR_GFL3_SHIFT                     (19U)
/*! GFL3 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL3(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL3_SHIFT)) & DIGTMP_LR_GFL3_MASK)

#define DIGTMP_LR_GFL4_MASK                      (0x100000U)
#define DIGTMP_LR_GFL4_SHIFT                     (20U)
/*! GFL4 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL4(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL4_SHIFT)) & DIGTMP_LR_GFL4_MASK)

#define DIGTMP_LR_GFL5_MASK                      (0x200000U)
#define DIGTMP_LR_GFL5_SHIFT                     (21U)
/*! GFL5 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL5(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL5_SHIFT)) & DIGTMP_LR_GFL5_MASK)

#define DIGTMP_LR_GFL6_MASK                      (0x400000U)
#define DIGTMP_LR_GFL6_SHIFT                     (22U)
/*! GFL6 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL6(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL6_SHIFT)) & DIGTMP_LR_GFL6_MASK)

#define DIGTMP_LR_GFL7_MASK                      (0x800000U)
#define DIGTMP_LR_GFL7_SHIFT                     (23U)
/*! GFL7 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL7(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL7_SHIFT)) & DIGTMP_LR_GFL7_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define DIGTMP_IER_DTIE_MASK                     (0x1U)
#define DIGTMP_IER_DTIE_SHIFT                    (0U)
/*! DTIE - Digital Tamper Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_DTIE(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_DTIE_SHIFT)) & DIGTMP_IER_DTIE_MASK)

#define DIGTMP_IER_TIIE0_MASK                    (0x4U)
#define DIGTMP_IER_TIIE0_SHIFT                   (2U)
/*! TIIE0 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE0_SHIFT)) & DIGTMP_IER_TIIE0_MASK)

#define DIGTMP_IER_TIIE1_MASK                    (0x8U)
#define DIGTMP_IER_TIIE1_SHIFT                   (3U)
/*! TIIE1 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE1(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE1_SHIFT)) & DIGTMP_IER_TIIE1_MASK)

#define DIGTMP_IER_TIIE2_MASK                    (0x10U)
#define DIGTMP_IER_TIIE2_SHIFT                   (4U)
/*! TIIE2 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE2(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE2_SHIFT)) & DIGTMP_IER_TIIE2_MASK)

#define DIGTMP_IER_TIIE3_MASK                    (0x20U)
#define DIGTMP_IER_TIIE3_SHIFT                   (5U)
/*! TIIE3 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE3(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE3_SHIFT)) & DIGTMP_IER_TIIE3_MASK)

#define DIGTMP_IER_TIIE4_MASK                    (0x40U)
#define DIGTMP_IER_TIIE4_SHIFT                   (6U)
/*! TIIE4 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE4(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE4_SHIFT)) & DIGTMP_IER_TIIE4_MASK)

#define DIGTMP_IER_TIIE5_MASK                    (0x80U)
#define DIGTMP_IER_TIIE5_SHIFT                   (7U)
/*! TIIE5 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE5(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE5_SHIFT)) & DIGTMP_IER_TIIE5_MASK)

#define DIGTMP_IER_TIIE6_MASK                    (0x100U)
#define DIGTMP_IER_TIIE6_SHIFT                   (8U)
/*! TIIE6 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE6(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE6_SHIFT)) & DIGTMP_IER_TIIE6_MASK)

#define DIGTMP_IER_TIIE7_MASK                    (0x200U)
#define DIGTMP_IER_TIIE7_SHIFT                   (9U)
/*! TIIE7 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE7(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE7_SHIFT)) & DIGTMP_IER_TIIE7_MASK)

#define DIGTMP_IER_TIIE8_MASK                    (0x400U)
#define DIGTMP_IER_TIIE8_SHIFT                   (10U)
/*! TIIE8 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE8(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE8_SHIFT)) & DIGTMP_IER_TIIE8_MASK)

#define DIGTMP_IER_TIIE9_MASK                    (0x800U)
#define DIGTMP_IER_TIIE9_SHIFT                   (11U)
/*! TIIE9 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE9(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE9_SHIFT)) & DIGTMP_IER_TIIE9_MASK)

#define DIGTMP_IER_TPIE0_MASK                    (0x10000U)
#define DIGTMP_IER_TPIE0_SHIFT                   (16U)
/*! TPIE0 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE0_SHIFT)) & DIGTMP_IER_TPIE0_MASK)

#define DIGTMP_IER_TPIE1_MASK                    (0x20000U)
#define DIGTMP_IER_TPIE1_SHIFT                   (17U)
/*! TPIE1 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE1(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE1_SHIFT)) & DIGTMP_IER_TPIE1_MASK)

#define DIGTMP_IER_TPIE2_MASK                    (0x40000U)
#define DIGTMP_IER_TPIE2_SHIFT                   (18U)
/*! TPIE2 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE2(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE2_SHIFT)) & DIGTMP_IER_TPIE2_MASK)

#define DIGTMP_IER_TPIE3_MASK                    (0x80000U)
#define DIGTMP_IER_TPIE3_SHIFT                   (19U)
/*! TPIE3 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE3(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE3_SHIFT)) & DIGTMP_IER_TPIE3_MASK)

#define DIGTMP_IER_TPIE4_MASK                    (0x100000U)
#define DIGTMP_IER_TPIE4_SHIFT                   (20U)
/*! TPIE4 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE4(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE4_SHIFT)) & DIGTMP_IER_TPIE4_MASK)

#define DIGTMP_IER_TPIE5_MASK                    (0x200000U)
#define DIGTMP_IER_TPIE5_SHIFT                   (21U)
/*! TPIE5 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE5(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE5_SHIFT)) & DIGTMP_IER_TPIE5_MASK)

#define DIGTMP_IER_TPIE6_MASK                    (0x400000U)
#define DIGTMP_IER_TPIE6_SHIFT                   (22U)
/*! TPIE6 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE6(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE6_SHIFT)) & DIGTMP_IER_TPIE6_MASK)

#define DIGTMP_IER_TPIE7_MASK                    (0x800000U)
#define DIGTMP_IER_TPIE7_SHIFT                   (23U)
/*! TPIE7 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE7(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE7_SHIFT)) & DIGTMP_IER_TPIE7_MASK)
/*! @} */

/*! @name TSR - Tamper Seconds */
/*! @{ */

#define DIGTMP_TSR_TTS_MASK                      (0xFFFFFFFFU)
#define DIGTMP_TSR_TTS_SHIFT                     (0U)
/*! TTS - Tamper Time Seconds */
#define DIGTMP_TSR_TTS(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_TSR_TTS_SHIFT)) & DIGTMP_TSR_TTS_MASK)
/*! @} */

/*! @name TER - Tamper Enable */
/*! @{ */

#define DIGTMP_TER_TIE0_MASK                     (0x4U)
#define DIGTMP_TER_TIE0_SHIFT                    (2U)
/*! TIE0 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE0_SHIFT)) & DIGTMP_TER_TIE0_MASK)

#define DIGTMP_TER_TIE1_MASK                     (0x8U)
#define DIGTMP_TER_TIE1_SHIFT                    (3U)
/*! TIE1 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE1_SHIFT)) & DIGTMP_TER_TIE1_MASK)

#define DIGTMP_TER_TIE2_MASK                     (0x10U)
#define DIGTMP_TER_TIE2_SHIFT                    (4U)
/*! TIE2 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE2(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE2_SHIFT)) & DIGTMP_TER_TIE2_MASK)

#define DIGTMP_TER_TIE3_MASK                     (0x20U)
#define DIGTMP_TER_TIE3_SHIFT                    (5U)
/*! TIE3 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE3(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE3_SHIFT)) & DIGTMP_TER_TIE3_MASK)

#define DIGTMP_TER_TIE4_MASK                     (0x40U)
#define DIGTMP_TER_TIE4_SHIFT                    (6U)
/*! TIE4 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE4(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE4_SHIFT)) & DIGTMP_TER_TIE4_MASK)

#define DIGTMP_TER_TIE5_MASK                     (0x80U)
#define DIGTMP_TER_TIE5_SHIFT                    (7U)
/*! TIE5 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE5(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE5_SHIFT)) & DIGTMP_TER_TIE5_MASK)

#define DIGTMP_TER_TIE6_MASK                     (0x100U)
#define DIGTMP_TER_TIE6_SHIFT                    (8U)
/*! TIE6 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE6(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE6_SHIFT)) & DIGTMP_TER_TIE6_MASK)

#define DIGTMP_TER_TIE7_MASK                     (0x200U)
#define DIGTMP_TER_TIE7_SHIFT                    (9U)
/*! TIE7 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE7(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE7_SHIFT)) & DIGTMP_TER_TIE7_MASK)

#define DIGTMP_TER_TIE8_MASK                     (0x400U)
#define DIGTMP_TER_TIE8_SHIFT                    (10U)
/*! TIE8 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE8(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE8_SHIFT)) & DIGTMP_TER_TIE8_MASK)

#define DIGTMP_TER_TIE9_MASK                     (0x800U)
#define DIGTMP_TER_TIE9_SHIFT                    (11U)
/*! TIE9 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE9(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE9_SHIFT)) & DIGTMP_TER_TIE9_MASK)

#define DIGTMP_TER_TPE0_MASK                     (0x10000U)
#define DIGTMP_TER_TPE0_SHIFT                    (16U)
/*! TPE0 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE0_SHIFT)) & DIGTMP_TER_TPE0_MASK)

#define DIGTMP_TER_TPE1_MASK                     (0x20000U)
#define DIGTMP_TER_TPE1_SHIFT                    (17U)
/*! TPE1 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE1_SHIFT)) & DIGTMP_TER_TPE1_MASK)

#define DIGTMP_TER_TPE2_MASK                     (0x40000U)
#define DIGTMP_TER_TPE2_SHIFT                    (18U)
/*! TPE2 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE2(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE2_SHIFT)) & DIGTMP_TER_TPE2_MASK)

#define DIGTMP_TER_TPE3_MASK                     (0x80000U)
#define DIGTMP_TER_TPE3_SHIFT                    (19U)
/*! TPE3 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE3(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE3_SHIFT)) & DIGTMP_TER_TPE3_MASK)

#define DIGTMP_TER_TPE4_MASK                     (0x100000U)
#define DIGTMP_TER_TPE4_SHIFT                    (20U)
/*! TPE4 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE4(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE4_SHIFT)) & DIGTMP_TER_TPE4_MASK)

#define DIGTMP_TER_TPE5_MASK                     (0x200000U)
#define DIGTMP_TER_TPE5_SHIFT                    (21U)
/*! TPE5 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE5(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE5_SHIFT)) & DIGTMP_TER_TPE5_MASK)

#define DIGTMP_TER_TPE6_MASK                     (0x400000U)
#define DIGTMP_TER_TPE6_SHIFT                    (22U)
/*! TPE6 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE6(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE6_SHIFT)) & DIGTMP_TER_TPE6_MASK)

#define DIGTMP_TER_TPE7_MASK                     (0x800000U)
#define DIGTMP_TER_TPE7_SHIFT                    (23U)
/*! TPE7 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE7(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE7_SHIFT)) & DIGTMP_TER_TPE7_MASK)
/*! @} */

/*! @name PDR - Pin Direction */
/*! @{ */

#define DIGTMP_PDR_TPD0_MASK                     (0x1U)
#define DIGTMP_PDR_TPD0_SHIFT                    (0U)
/*! TPD0 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD0_SHIFT)) & DIGTMP_PDR_TPD0_MASK)

#define DIGTMP_PDR_TPD1_MASK                     (0x2U)
#define DIGTMP_PDR_TPD1_SHIFT                    (1U)
/*! TPD1 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD1_SHIFT)) & DIGTMP_PDR_TPD1_MASK)

#define DIGTMP_PDR_TPD2_MASK                     (0x4U)
#define DIGTMP_PDR_TPD2_SHIFT                    (2U)
/*! TPD2 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD2(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD2_SHIFT)) & DIGTMP_PDR_TPD2_MASK)

#define DIGTMP_PDR_TPD3_MASK                     (0x8U)
#define DIGTMP_PDR_TPD3_SHIFT                    (3U)
/*! TPD3 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD3(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD3_SHIFT)) & DIGTMP_PDR_TPD3_MASK)

#define DIGTMP_PDR_TPD4_MASK                     (0x10U)
#define DIGTMP_PDR_TPD4_SHIFT                    (4U)
/*! TPD4 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD4(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD4_SHIFT)) & DIGTMP_PDR_TPD4_MASK)

#define DIGTMP_PDR_TPD5_MASK                     (0x20U)
#define DIGTMP_PDR_TPD5_SHIFT                    (5U)
/*! TPD5 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD5(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD5_SHIFT)) & DIGTMP_PDR_TPD5_MASK)

#define DIGTMP_PDR_TPD6_MASK                     (0x40U)
#define DIGTMP_PDR_TPD6_SHIFT                    (6U)
/*! TPD6 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD6(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD6_SHIFT)) & DIGTMP_PDR_TPD6_MASK)

#define DIGTMP_PDR_TPD7_MASK                     (0x80U)
#define DIGTMP_PDR_TPD7_SHIFT                    (7U)
/*! TPD7 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD7(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD7_SHIFT)) & DIGTMP_PDR_TPD7_MASK)

#define DIGTMP_PDR_TPOD0_MASK                    (0x10000U)
#define DIGTMP_PDR_TPOD0_SHIFT                   (16U)
/*! TPOD0 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD0_SHIFT)) & DIGTMP_PDR_TPOD0_MASK)

#define DIGTMP_PDR_TPOD1_MASK                    (0x20000U)
#define DIGTMP_PDR_TPOD1_SHIFT                   (17U)
/*! TPOD1 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD1(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD1_SHIFT)) & DIGTMP_PDR_TPOD1_MASK)

#define DIGTMP_PDR_TPOD2_MASK                    (0x40000U)
#define DIGTMP_PDR_TPOD2_SHIFT                   (18U)
/*! TPOD2 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD2(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD2_SHIFT)) & DIGTMP_PDR_TPOD2_MASK)

#define DIGTMP_PDR_TPOD3_MASK                    (0x80000U)
#define DIGTMP_PDR_TPOD3_SHIFT                   (19U)
/*! TPOD3 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD3(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD3_SHIFT)) & DIGTMP_PDR_TPOD3_MASK)

#define DIGTMP_PDR_TPOD4_MASK                    (0x100000U)
#define DIGTMP_PDR_TPOD4_SHIFT                   (20U)
/*! TPOD4 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD4(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD4_SHIFT)) & DIGTMP_PDR_TPOD4_MASK)

#define DIGTMP_PDR_TPOD5_MASK                    (0x200000U)
#define DIGTMP_PDR_TPOD5_SHIFT                   (21U)
/*! TPOD5 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD5(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD5_SHIFT)) & DIGTMP_PDR_TPOD5_MASK)

#define DIGTMP_PDR_TPOD6_MASK                    (0x400000U)
#define DIGTMP_PDR_TPOD6_SHIFT                   (22U)
/*! TPOD6 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD6(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD6_SHIFT)) & DIGTMP_PDR_TPOD6_MASK)

#define DIGTMP_PDR_TPOD7_MASK                    (0x800000U)
#define DIGTMP_PDR_TPOD7_SHIFT                   (23U)
/*! TPOD7 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD7(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD7_SHIFT)) & DIGTMP_PDR_TPOD7_MASK)
/*! @} */

/*! @name PPR - Pin Polarity */
/*! @{ */

#define DIGTMP_PPR_TPP0_MASK                     (0x1U)
#define DIGTMP_PPR_TPP0_SHIFT                    (0U)
/*! TPP0 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP0_SHIFT)) & DIGTMP_PPR_TPP0_MASK)

#define DIGTMP_PPR_TPP1_MASK                     (0x2U)
#define DIGTMP_PPR_TPP1_SHIFT                    (1U)
/*! TPP1 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP1_SHIFT)) & DIGTMP_PPR_TPP1_MASK)

#define DIGTMP_PPR_TPP2_MASK                     (0x4U)
#define DIGTMP_PPR_TPP2_SHIFT                    (2U)
/*! TPP2 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP2(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP2_SHIFT)) & DIGTMP_PPR_TPP2_MASK)

#define DIGTMP_PPR_TPP3_MASK                     (0x8U)
#define DIGTMP_PPR_TPP3_SHIFT                    (3U)
/*! TPP3 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP3(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP3_SHIFT)) & DIGTMP_PPR_TPP3_MASK)

#define DIGTMP_PPR_TPP4_MASK                     (0x10U)
#define DIGTMP_PPR_TPP4_SHIFT                    (4U)
/*! TPP4 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP4(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP4_SHIFT)) & DIGTMP_PPR_TPP4_MASK)

#define DIGTMP_PPR_TPP5_MASK                     (0x20U)
#define DIGTMP_PPR_TPP5_SHIFT                    (5U)
/*! TPP5 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP5(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP5_SHIFT)) & DIGTMP_PPR_TPP5_MASK)

#define DIGTMP_PPR_TPP6_MASK                     (0x40U)
#define DIGTMP_PPR_TPP6_SHIFT                    (6U)
/*! TPP6 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP6(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP6_SHIFT)) & DIGTMP_PPR_TPP6_MASK)

#define DIGTMP_PPR_TPP7_MASK                     (0x80U)
#define DIGTMP_PPR_TPP7_SHIFT                    (7U)
/*! TPP7 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP7(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP7_SHIFT)) & DIGTMP_PPR_TPP7_MASK)

#define DIGTMP_PPR_TPID0_MASK                    (0x10000U)
#define DIGTMP_PPR_TPID0_SHIFT                   (16U)
/*! TPID0 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID0_SHIFT)) & DIGTMP_PPR_TPID0_MASK)

#define DIGTMP_PPR_TPID1_MASK                    (0x20000U)
#define DIGTMP_PPR_TPID1_SHIFT                   (17U)
/*! TPID1 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID1(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID1_SHIFT)) & DIGTMP_PPR_TPID1_MASK)

#define DIGTMP_PPR_TPID2_MASK                    (0x40000U)
#define DIGTMP_PPR_TPID2_SHIFT                   (18U)
/*! TPID2 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID2(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID2_SHIFT)) & DIGTMP_PPR_TPID2_MASK)

#define DIGTMP_PPR_TPID3_MASK                    (0x80000U)
#define DIGTMP_PPR_TPID3_SHIFT                   (19U)
/*! TPID3 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID3(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID3_SHIFT)) & DIGTMP_PPR_TPID3_MASK)

#define DIGTMP_PPR_TPID4_MASK                    (0x100000U)
#define DIGTMP_PPR_TPID4_SHIFT                   (20U)
/*! TPID4 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID4(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID4_SHIFT)) & DIGTMP_PPR_TPID4_MASK)

#define DIGTMP_PPR_TPID5_MASK                    (0x200000U)
#define DIGTMP_PPR_TPID5_SHIFT                   (21U)
/*! TPID5 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID5(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID5_SHIFT)) & DIGTMP_PPR_TPID5_MASK)

#define DIGTMP_PPR_TPID6_MASK                    (0x400000U)
#define DIGTMP_PPR_TPID6_SHIFT                   (22U)
/*! TPID6 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID6(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID6_SHIFT)) & DIGTMP_PPR_TPID6_MASK)

#define DIGTMP_PPR_TPID7_MASK                    (0x800000U)
#define DIGTMP_PPR_TPID7_SHIFT                   (23U)
/*! TPID7 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID7(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID7_SHIFT)) & DIGTMP_PPR_TPID7_MASK)
/*! @} */

/*! @name ATR - Active Tamper */
/*! @{ */

#define DIGTMP_ATR_ATSR_MASK                     (0xFFFFU)
#define DIGTMP_ATR_ATSR_SHIFT                    (0U)
/*! ATSR - Active Tamper Shift Register */
#define DIGTMP_ATR_ATSR(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_ATR_ATSR_SHIFT)) & DIGTMP_ATR_ATSR_MASK)

#define DIGTMP_ATR_ATP_MASK                      (0xFFFF0000U)
#define DIGTMP_ATR_ATP_SHIFT                     (16U)
/*! ATP - Active Tamper Polynomial */
#define DIGTMP_ATR_ATP(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_ATR_ATP_SHIFT)) & DIGTMP_ATR_ATP_MASK)
/*! @} */

/*! @name PGFR - Pin Glitch Filter */
/*! @{ */

#define DIGTMP_PGFR_GFW_MASK                     (0x3FU)
#define DIGTMP_PGFR_GFW_SHIFT                    (0U)
/*! GFW - Glitch Filter Width */
#define DIGTMP_PGFR_GFW(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_GFW_SHIFT)) & DIGTMP_PGFR_GFW_MASK)

#define DIGTMP_PGFR_GFP_MASK                     (0x40U)
#define DIGTMP_PGFR_GFP_SHIFT                    (6U)
/*! GFP - Glitch Filter Prescaler
 *  0b0..512 Hz prescaler clock
 *  0b1..32.768 kHz clock
 */
#define DIGTMP_PGFR_GFP(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_GFP_SHIFT)) & DIGTMP_PGFR_GFP_MASK)

#define DIGTMP_PGFR_GFE_MASK                     (0x80U)
#define DIGTMP_PGFR_GFE_SHIFT                    (7U)
/*! GFE - Glitch Filter Enable
 *  0b0..Bypasses
 *  0b1..Enables
 */
#define DIGTMP_PGFR_GFE(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_GFE_SHIFT)) & DIGTMP_PGFR_GFE_MASK)

#define DIGTMP_PGFR_TPSW_MASK                    (0x300U)
#define DIGTMP_PGFR_TPSW_SHIFT                   (8U)
/*! TPSW - Tamper Pin Sample Width
 *  0b00..Continuous monitoring, pin sampling disabled
 *  0b01..2 cycles for pull enable and 1 cycle for input buffer enable
 *  0b10..4 cycles for pull enable and 2 cycles for input buffer enable
 *  0b11..8 cycles for pull enable and 4 cycles for input buffer enable
 */
#define DIGTMP_PGFR_TPSW(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPSW_SHIFT)) & DIGTMP_PGFR_TPSW_MASK)

#define DIGTMP_PGFR_TPSF_MASK                    (0xC00U)
#define DIGTMP_PGFR_TPSF_SHIFT                   (10U)
/*! TPSF - Tamper Pin Sample Frequency
 *  0b00..Every 8 cycles
 *  0b01..Every 32 cycles
 *  0b10..Every 128 cycles
 *  0b11..Every 512 cycles
 */
#define DIGTMP_PGFR_TPSF(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPSF_SHIFT)) & DIGTMP_PGFR_TPSF_MASK)

#define DIGTMP_PGFR_TPEX_MASK                    (0x30000U)
#define DIGTMP_PGFR_TPEX_SHIFT                   (16U)
/*! TPEX - Tamper Pin Expected
 *  0b00..Zero/passive tamper
 *  0b01..Active Tamper 0 output
 *  0b10..Active Tamper 1 output
 *  0b11..Active Tamper 0 output XORed with Active Tamper 1 output
 */
#define DIGTMP_PGFR_TPEX(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPEX_SHIFT)) & DIGTMP_PGFR_TPEX_MASK)

#define DIGTMP_PGFR_TPE_MASK                     (0x1000000U)
#define DIGTMP_PGFR_TPE_SHIFT                    (24U)
/*! TPE - Tamper Pull Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_PGFR_TPE(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPE_SHIFT)) & DIGTMP_PGFR_TPE_MASK)

#define DIGTMP_PGFR_TPS_MASK                     (0x2000000U)
#define DIGTMP_PGFR_TPS_SHIFT                    (25U)
/*! TPS - Tamper Pull Select
 *  0b0..Asserts
 *  0b1..Negates
 */
#define DIGTMP_PGFR_TPS(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPS_SHIFT)) & DIGTMP_PGFR_TPS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DIGTMP_Register_Masks */


/*!
 * @}
 */ /* end of group DIGTMP_Peripheral_Access_Layer */


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


#endif  /* PERI_DIGTMP_H_ */

