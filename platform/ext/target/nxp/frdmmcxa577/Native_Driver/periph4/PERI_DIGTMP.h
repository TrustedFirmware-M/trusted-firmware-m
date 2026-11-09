/*
** ###################################################################
**     Processors:          MCXA286VAPR
**                          MCXA286VASR
**                          MCXA286VLL
**                          MCXA286VLQ
**                          MCXA286VPN
**                          MCXA287VAPR
**                          MCXA287VASR
**                          MCXA287VLL
**                          MCXA287VLQ
**                          MCXA287VPN
**                          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
**                          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA566VLL
**                          MCXA566VLQ
**                          MCXA566VPN
**                          MCXA567VLL
**                          MCXA567VLQ
**                          MCXA567VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DIGTMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DIGTMP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DIGTMP
 *
 * CMSIS Peripheral Access Layer for DIGTMP
 */

#if !defined(PERI_DIGTMP_H_)
#define PERI_DIGTMP_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
#elif (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA566VLL) || defined(CPU_MCXA566VLQ) || defined(CPU_MCXA566VPN))
#include "MCXA566_COMMON.h"
#elif (defined(CPU_MCXA567VLL) || defined(CPU_MCXA567VLQ) || defined(CPU_MCXA567VPN))
#include "MCXA567_COMMON.h"
#elif (defined(CPU_MCXA577VAPR) || defined(CPU_MCXA577VLL) || defined(CPU_MCXA577VLQ) || defined(CPU_MCXA577VPN))
#include "MCXA577_COMMON.h"
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
       uint8_t RESERVED_1[4];
  __IO uint32_t PPR;                               /**< Pin Polarity, offset: 0x2C */
       uint8_t RESERVED_2[16];
  __IO uint32_t PGFR[DIGTMP_PGFR_COUNT];           /**< Pin Glitch Filter, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_3[1952];
  __IO uint32_t WAC;                               /**< Write Access Control, offset: 0x800 */
  __IO uint32_t RAC;                               /**< Read Access Control, offset: 0x804 */
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

#define DIGTMP_SR_TIF10_MASK                     (0x1000U)
#define DIGTMP_SR_TIF10_SHIFT                    (12U)
/*! TIF10 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF10(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF10_SHIFT)) & DIGTMP_SR_TIF10_MASK)

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

#define DIGTMP_LR_PPL_MASK                       (0x800U)
#define DIGTMP_LR_PPL_SHIFT                      (11U)
/*! PPL - Pin Polarity Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_PPL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_PPL_SHIFT)) & DIGTMP_LR_PPL_MASK)

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

#define DIGTMP_IER_TIIE10_MASK                   (0x1000U)
#define DIGTMP_IER_TIIE10_SHIFT                  (12U)
/*! TIIE10 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE10(x)                     (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE10_SHIFT)) & DIGTMP_IER_TIIE10_MASK)

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

#define DIGTMP_TER_TIE10_MASK                    (0x1000U)
#define DIGTMP_TER_TIE10_SHIFT                   (12U)
/*! TIE10 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE10(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE10_SHIFT)) & DIGTMP_TER_TIE10_MASK)

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

/*! @name WAC - Write Access Control */
/*! @{ */

#define DIGTMP_WAC_CRW_MASK                      (0x10U)
#define DIGTMP_WAC_CRW_SHIFT                     (4U)
/*! CRW - Control Register Write
 *  0b0..Writes to the Control register are ignored.
 *  0b1..Writes to the Control register complete as normal.
 */
#define DIGTMP_WAC_CRW(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_CRW_SHIFT)) & DIGTMP_WAC_CRW_MASK)

#define DIGTMP_WAC_SRW_MASK                      (0x20U)
#define DIGTMP_WAC_SRW_SHIFT                     (5U)
/*! SRW - Status Register Write
 *  0b0..Writes to the Status Register are ignored.
 *  0b1..Writes to the Status Register complete as normal.
 */
#define DIGTMP_WAC_SRW(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_SRW_SHIFT)) & DIGTMP_WAC_SRW_MASK)

#define DIGTMP_WAC_LRW_MASK                      (0x40U)
#define DIGTMP_WAC_LRW_SHIFT                     (6U)
/*! LRW - Lock Register Write
 *  0b0..Writes to the Lock register are ignored.
 *  0b1..Writes to the Lock register complete as normal.
 */
#define DIGTMP_WAC_LRW(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_LRW_SHIFT)) & DIGTMP_WAC_LRW_MASK)

#define DIGTMP_WAC_IEW_MASK                      (0x80U)
#define DIGTMP_WAC_IEW_SHIFT                     (7U)
/*! IEW - Interrupt Enable Write
 *  0b0..Writes to the Interrupt enable register are ignored.
 *  0b1..Writes to the Interrupt enable register complete as normal.
 */
#define DIGTMP_WAC_IEW(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_IEW_SHIFT)) & DIGTMP_WAC_IEW_MASK)

#define DIGTMP_WAC_TSRW_MASK                     (0x100U)
#define DIGTMP_WAC_TSRW_SHIFT                    (8U)
/*! TSRW - Tamper Seconds Register Write
 *  0b0..Writes to the Tamper Seconds register are ignored.
 *  0b1..Writes to the Tamper Seconds register complete as normal.
 */
#define DIGTMP_WAC_TSRW(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_TSRW_SHIFT)) & DIGTMP_WAC_TSRW_MASK)

#define DIGTMP_WAC_TEW_MASK                      (0x200U)
#define DIGTMP_WAC_TEW_SHIFT                     (9U)
/*! TEW - Tamper Enable Write
 *  0b0..Writes to the tamper enable register are ignored.
 *  0b1..Writes to the tamper enable register complete as normal.
 */
#define DIGTMP_WAC_TEW(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_TEW_SHIFT)) & DIGTMP_WAC_TEW_MASK)

#define DIGTMP_WAC_PPW_MASK                      (0x800U)
#define DIGTMP_WAC_PPW_SHIFT                     (11U)
/*! PPW - Pin Polarity Write
 *  0b0..Writes to the pin polarity register are ignored.
 *  0b1..Writes to the pin polarity register complete as normal.
 */
#define DIGTMP_WAC_PPW(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_PPW_SHIFT)) & DIGTMP_WAC_PPW_MASK)

#define DIGTMP_WAC_GFW0_MASK                     (0x10000U)
#define DIGTMP_WAC_GFW0_SHIFT                    (16U)
/*! GFW0 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW0_SHIFT)) & DIGTMP_WAC_GFW0_MASK)

#define DIGTMP_WAC_GFW1_MASK                     (0x20000U)
#define DIGTMP_WAC_GFW1_SHIFT                    (17U)
/*! GFW1 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW1_SHIFT)) & DIGTMP_WAC_GFW1_MASK)

#define DIGTMP_WAC_GFW2_MASK                     (0x40000U)
#define DIGTMP_WAC_GFW2_SHIFT                    (18U)
/*! GFW2 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW2(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW2_SHIFT)) & DIGTMP_WAC_GFW2_MASK)

#define DIGTMP_WAC_GFW3_MASK                     (0x80000U)
#define DIGTMP_WAC_GFW3_SHIFT                    (19U)
/*! GFW3 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW3(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW3_SHIFT)) & DIGTMP_WAC_GFW3_MASK)

#define DIGTMP_WAC_GFW4_MASK                     (0x100000U)
#define DIGTMP_WAC_GFW4_SHIFT                    (20U)
/*! GFW4 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW4(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW4_SHIFT)) & DIGTMP_WAC_GFW4_MASK)

#define DIGTMP_WAC_GFW5_MASK                     (0x200000U)
#define DIGTMP_WAC_GFW5_SHIFT                    (21U)
/*! GFW5 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW5(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW5_SHIFT)) & DIGTMP_WAC_GFW5_MASK)

#define DIGTMP_WAC_GFW6_MASK                     (0x400000U)
#define DIGTMP_WAC_GFW6_SHIFT                    (22U)
/*! GFW6 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW6(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW6_SHIFT)) & DIGTMP_WAC_GFW6_MASK)

#define DIGTMP_WAC_GFW7_MASK                     (0x800000U)
#define DIGTMP_WAC_GFW7_SHIFT                    (23U)
/*! GFW7 - Glitch Filter Write
 *  0b0..Writes are ignored
 *  0b1..Writes complete as normal
 */
#define DIGTMP_WAC_GFW7(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_WAC_GFW7_SHIFT)) & DIGTMP_WAC_GFW7_MASK)
/*! @} */

/*! @name RAC - Read Access Control */
/*! @{ */

#define DIGTMP_RAC_CRR_MASK                      (0x10U)
#define DIGTMP_RAC_CRR_SHIFT                     (4U)
/*! CRR - Control Register Read
 *  0b0..Reads to the Control register are ignored.
 *  0b1..Reads to the Control register complete as normal.
 */
#define DIGTMP_RAC_CRR(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_CRR_SHIFT)) & DIGTMP_RAC_CRR_MASK)

#define DIGTMP_RAC_SRR_MASK                      (0x20U)
#define DIGTMP_RAC_SRR_SHIFT                     (5U)
/*! SRR - Status Register Read
 *  0b0..Reads to the Status Register are ignored.
 *  0b1..Reads to the Status Register complete as normal.
 */
#define DIGTMP_RAC_SRR(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_SRR_SHIFT)) & DIGTMP_RAC_SRR_MASK)

#define DIGTMP_RAC_LRR_MASK                      (0x40U)
#define DIGTMP_RAC_LRR_SHIFT                     (6U)
/*! LRR - Lock Register Read
 *  0b0..Reads to the Lock register are ignored.
 *  0b1..Reads to the Lock register complete as normal.
 */
#define DIGTMP_RAC_LRR(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_LRR_SHIFT)) & DIGTMP_RAC_LRR_MASK)

#define DIGTMP_RAC_IER_MASK                      (0x80U)
#define DIGTMP_RAC_IER_SHIFT                     (7U)
/*! IER - Interrupt Enable Read
 *  0b0..Reads to the Interrupt enable register are ignored.
 *  0b1..Reads to the Interrupt enable register complete as normal.
 */
#define DIGTMP_RAC_IER(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_IER_SHIFT)) & DIGTMP_RAC_IER_MASK)

#define DIGTMP_RAC_TSRR_MASK                     (0x100U)
#define DIGTMP_RAC_TSRR_SHIFT                    (8U)
/*! TSRR - Tamper Seconds Register Read
 *  0b0..Reads to the tamper seconds register are ignored.
 *  0b1..Reads to the tamper seconds register complete as normal.
 */
#define DIGTMP_RAC_TSRR(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_TSRR_SHIFT)) & DIGTMP_RAC_TSRR_MASK)

#define DIGTMP_RAC_TER_MASK                      (0x200U)
#define DIGTMP_RAC_TER_SHIFT                     (9U)
/*! TER - Tamper Enable Read
 *  0b0..Reads to the tamper enable register are ignored.
 *  0b1..Reads to the tamper enable register complete as normal.
 */
#define DIGTMP_RAC_TER(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_TER_SHIFT)) & DIGTMP_RAC_TER_MASK)

#define DIGTMP_RAC_PPR_MASK                      (0x800U)
#define DIGTMP_RAC_PPR_SHIFT                     (11U)
/*! PPR - Pin Polarity Read
 *  0b0..Reads to the pin polarity register are ignored.
 *  0b1..Reads to the pin polarity register complete as normal.
 */
#define DIGTMP_RAC_PPR(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_PPR_SHIFT)) & DIGTMP_RAC_PPR_MASK)

#define DIGTMP_RAC_GFR0_MASK                     (0x10000U)
#define DIGTMP_RAC_GFR0_SHIFT                    (16U)
/*! GFR0 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR0_SHIFT)) & DIGTMP_RAC_GFR0_MASK)

#define DIGTMP_RAC_GFR1_MASK                     (0x20000U)
#define DIGTMP_RAC_GFR1_SHIFT                    (17U)
/*! GFR1 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR1_SHIFT)) & DIGTMP_RAC_GFR1_MASK)

#define DIGTMP_RAC_GFR2_MASK                     (0x40000U)
#define DIGTMP_RAC_GFR2_SHIFT                    (18U)
/*! GFR2 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR2(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR2_SHIFT)) & DIGTMP_RAC_GFR2_MASK)

#define DIGTMP_RAC_GFR3_MASK                     (0x80000U)
#define DIGTMP_RAC_GFR3_SHIFT                    (19U)
/*! GFR3 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR3(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR3_SHIFT)) & DIGTMP_RAC_GFR3_MASK)

#define DIGTMP_RAC_GFR4_MASK                     (0x100000U)
#define DIGTMP_RAC_GFR4_SHIFT                    (20U)
/*! GFR4 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR4(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR4_SHIFT)) & DIGTMP_RAC_GFR4_MASK)

#define DIGTMP_RAC_GFR5_MASK                     (0x200000U)
#define DIGTMP_RAC_GFR5_SHIFT                    (21U)
/*! GFR5 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR5(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR5_SHIFT)) & DIGTMP_RAC_GFR5_MASK)

#define DIGTMP_RAC_GFR6_MASK                     (0x400000U)
#define DIGTMP_RAC_GFR6_SHIFT                    (22U)
/*! GFR6 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR6(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR6_SHIFT)) & DIGTMP_RAC_GFR6_MASK)

#define DIGTMP_RAC_GFR7_MASK                     (0x800000U)
#define DIGTMP_RAC_GFR7_SHIFT                    (23U)
/*! GFR7 - Glitch Filter Read
 *  0b0..Reads are ignored
 *  0b1..Reads complete as normal
 */
#define DIGTMP_RAC_GFR7(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_RAC_GFR7_SHIFT)) & DIGTMP_RAC_GFR7_MASK)
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

