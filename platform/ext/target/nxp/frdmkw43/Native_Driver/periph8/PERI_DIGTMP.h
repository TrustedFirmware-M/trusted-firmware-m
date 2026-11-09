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
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DIGTMP.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for DIGTMP
 *
 * CMSIS Peripheral Access Layer for DIGTMP
 */

#if !defined(PERI_DIGTMP_H_)
#define PERI_DIGTMP_H_                           /**< Symbol preventing repeated inclusion */

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
   -- DIGTMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIGTMP_Peripheral_Access_Layer DIGTMP Peripheral Access Layer
 * @{
 */

/** DIGTMP - Size of Registers Arrays */
#define DIGTMP_PGFR_COUNT                         3u

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

