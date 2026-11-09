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
**         CMSIS Peripheral Access Layer for XCVR_TSM
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
 * @file PERI_XCVR_TSM.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for XCVR_TSM
 *
 * CMSIS Peripheral Access Layer for XCVR_TSM
 */

#if !defined(PERI_XCVR_TSM_H_)
#define PERI_XCVR_TSM_H_                         /**< Symbol preventing repeated inclusion */

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
   -- XCVR_TSM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_TSM_Peripheral_Access_Layer XCVR_TSM Peripheral Access Layer
 * @{
 */

/** XCVR_TSM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< TSM CONTROL, offset: 0x0 */
  __IO uint32_t LPPS_CTRL;                         /**< TSM CONTROL, offset: 0x4 */
  __IO uint32_t END_OF_SEQ;                        /**< TSM END OF SEQUENCE, offset: 0x8 */
  __IO uint32_t WU_LATENCY;                        /**< WARMUP LATENCY, offset: 0xC */
  __IO uint32_t RECYCLE_COUNT;                     /**< TSM RECYCLE COUNT, offset: 0x10 */
  __IO uint32_t FAST_CTRL1;                        /**< TSM FAST WARMUP CONTROL 1, offset: 0x14 */
  __IO uint32_t FAST_CTRL2;                        /**< TSM FAST WARMUP CONTROL 2, offset: 0x18 */
  __IO uint32_t FAST_CTRL3;                        /**< TSM FAST WARMUP CONTROL 3, offset: 0x1C */
  __IO uint32_t TIMING00;                          /**< TSM_TIMING00, offset: 0x20 */
  __IO uint32_t TIMING01;                          /**< TSM_TIMING01, offset: 0x24 */
  __IO uint32_t TIMING02;                          /**< TSM_TIMING02, offset: 0x28 */
  __IO uint32_t TIMING03;                          /**< TSM_TIMING03, offset: 0x2C */
  __IO uint32_t TIMING04;                          /**< TSM_TIMING04, offset: 0x30 */
  __IO uint32_t TIMING05;                          /**< TSM_TIMING05, offset: 0x34 */
  __IO uint32_t TIMING06;                          /**< TSM_TIMING06, offset: 0x38 */
  __IO uint32_t TIMING07;                          /**< TSM_TIMING07, offset: 0x3C */
  __IO uint32_t TIMING08;                          /**< TSM_TIMING08, offset: 0x40 */
  __IO uint32_t TIMING09;                          /**< TSM_TIMING09, offset: 0x44 */
  __IO uint32_t TIMING10;                          /**< TSM_TIMING10, offset: 0x48 */
  __IO uint32_t TIMING11;                          /**< TSM_TIMING11, offset: 0x4C */
  __IO uint32_t TIMING12;                          /**< TSM_TIMING12, offset: 0x50 */
  __IO uint32_t TIMING13;                          /**< TSM_TIMING13, offset: 0x54 */
  __IO uint32_t TIMING14;                          /**< TSM_TIMING14, offset: 0x58 */
  __IO uint32_t TIMING15;                          /**< TSM_TIMING15, offset: 0x5C */
  __IO uint32_t TIMING16;                          /**< TSM_TIMING16, offset: 0x60 */
  __IO uint32_t TIMING17;                          /**< TSM_TIMING17, offset: 0x64 */
  __IO uint32_t TIMING18;                          /**< TSM_TIMING18, offset: 0x68 */
  __IO uint32_t TIMING19;                          /**< TSM_TIMING19, offset: 0x6C */
  __IO uint32_t TIMING20;                          /**< TSM_TIMING20, offset: 0x70 */
  __IO uint32_t TIMING21;                          /**< TSM_TIMING21, offset: 0x74 */
  __IO uint32_t TIMING22;                          /**< TSM_TIMING22, offset: 0x78 */
  __IO uint32_t TIMING23;                          /**< TSM_TIMING23, offset: 0x7C */
  __IO uint32_t TIMING24;                          /**< TSM_TIMING24, offset: 0x80 */
  __IO uint32_t TIMING25;                          /**< TSM_TIMING25, offset: 0x84 */
  __IO uint32_t TIMING26;                          /**< TSM_TIMING26, offset: 0x88 */
  __IO uint32_t TIMING27;                          /**< TSM_TIMING27, offset: 0x8C */
  __IO uint32_t TIMING28;                          /**< TSM_TIMING28, offset: 0x90 */
  __IO uint32_t TIMING29;                          /**< TSM_TIMING29, offset: 0x94 */
  __IO uint32_t TIMING30;                          /**< TSM_TIMING30, offset: 0x98 */
  __IO uint32_t TIMING31;                          /**< TSM_TIMING31, offset: 0x9C */
  __IO uint32_t TIMING32;                          /**< TSM_TIMING32, offset: 0xA0 */
  __IO uint32_t TIMING33;                          /**< TSM_TIMING33, offset: 0xA4 */
  __IO uint32_t TIMING34;                          /**< TSM_TIMING34, offset: 0xA8 */
  __IO uint32_t TIMING35;                          /**< TSM_TIMING35, offset: 0xAC */
  __IO uint32_t TIMING36;                          /**< TSM_TIMING36, offset: 0xB0 */
  __IO uint32_t TIMING37;                          /**< TSM_TIMING37, offset: 0xB4 */
  __IO uint32_t TIMING38;                          /**< TSM_TIMING38, offset: 0xB8 */
  __IO uint32_t TIMING39;                          /**< TSM_TIMING39, offset: 0xBC */
  __IO uint32_t TIMING40;                          /**< TSM_TIMING40, offset: 0xC0 */
  __IO uint32_t TIMING41;                          /**< TSM_TIMING41, offset: 0xC4 */
  __IO uint32_t TIMING42;                          /**< TSM_TIMING42, offset: 0xC8 */
  __IO uint32_t TIMING43;                          /**< TSM_TIMING43, offset: 0xCC */
  __IO uint32_t TIMING44;                          /**< TSM_TIMING44, offset: 0xD0 */
  __IO uint32_t TIMING45;                          /**< TSM_TIMING45, offset: 0xD4 */
  __IO uint32_t TIMING46;                          /**< TSM_TIMING46, offset: 0xD8 */
  __IO uint32_t TIMING47;                          /**< TSM_TIMING47, offset: 0xDC */
  __IO uint32_t TIMING48;                          /**< TSM_TIMING48, offset: 0xE0 */
  __IO uint32_t TIMING49;                          /**< TSM_TIMING49, offset: 0xE4 */
  __IO uint32_t TIMING50;                          /**< TSM_TIMING50, offset: 0xE8 */
  __IO uint32_t TIMING51;                          /**< TSM_TIMING51, offset: 0xEC */
  __IO uint32_t TIMING52;                          /**< TSM_TIMING52, offset: 0xF0 */
  __IO uint32_t TIMING53;                          /**< TSM TIMING_53, offset: 0xF4 */
  __IO uint32_t TIMING54;                          /**< TSM TIMING_54, offset: 0xF8 */
  __IO uint32_t TIMING55;                          /**< TSM TIMING_55, offset: 0xFC */
  __IO uint32_t TIMING56;                          /**< TSM TIMING_56, offset: 0x100 */
  __IO uint32_t TIMING57;                          /**< TSM TIMING_57, offset: 0x104 */
  __IO uint32_t TIMING58;                          /**< TSM TIMING_58, offset: 0x108 */
  __IO uint32_t TIMING59;                          /**< TSM TIMING_59, offset: 0x10C */
  __IO uint32_t TIMING60;                          /**< TSM TIMING_60, offset: 0x110 */
  __IO uint32_t TIMING61;                          /**< TSM TIMING_61, offset: 0x114 */
  __IO uint32_t OVRD0;                             /**< TSM OVERRIDE REGISTER 0, offset: 0x118 */
  __IO uint32_t OVRD1;                             /**< TSM OVERRIDE REGISTER 1, offset: 0x11C */
  __IO uint32_t OVRD2;                             /**< TSM OVERRIDE REGISTER 2, offset: 0x120 */
  __IO uint32_t OVRD3;                             /**< TSM OVERRIDE REGISTER 3, offset: 0x124 */
  __IO uint32_t OVRD4;                             /**< TSM OVERRIDE REGISTER 4, offset: 0x128 */
  __IO uint32_t CTRL2;                             /**< TSM CONTROL 2, offset: 0x12C */
} XCVR_TSM_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_TSM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_TSM_Register_Masks XCVR_TSM Register Masks
 * @{
 */

/*! @name CTRL - TSM CONTROL */
/*! @{ */

#define XCVR_TSM_CTRL_TSM_SOFT_RESET_MASK        (0x2U)
#define XCVR_TSM_CTRL_TSM_SOFT_RESET_SHIFT       (1U)
/*! TSM_SOFT_RESET - TSM Soft Reset
 *  0b0..TSM Soft Reset removed. Normal operation.
 *  0b1..TSM Soft Reset engaged. TSM forced to IDLE, and holds there until the bit is cleared.
 */
#define XCVR_TSM_CTRL_TSM_SOFT_RESET(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TSM_SOFT_RESET_SHIFT)) & XCVR_TSM_CTRL_TSM_SOFT_RESET_MASK)

#define XCVR_TSM_CTRL_FORCE_TX_EN_MASK           (0x4U)
#define XCVR_TSM_CTRL_FORCE_TX_EN_SHIFT          (2U)
/*! FORCE_TX_EN - Force Transmit Enable
 *  0b0..TSM Idle
 *  0b1..TSM executes a TX sequence
 */
#define XCVR_TSM_CTRL_FORCE_TX_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_FORCE_TX_EN_SHIFT)) & XCVR_TSM_CTRL_FORCE_TX_EN_MASK)

#define XCVR_TSM_CTRL_FORCE_RX_EN_MASK           (0x8U)
#define XCVR_TSM_CTRL_FORCE_RX_EN_SHIFT          (3U)
/*! FORCE_RX_EN - Force Receive Enable
 *  0b0..TSM Idle
 *  0b1..TSM executes a RX sequence
 */
#define XCVR_TSM_CTRL_FORCE_RX_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_FORCE_RX_EN_SHIFT)) & XCVR_TSM_CTRL_FORCE_RX_EN_MASK)

#define XCVR_TSM_CTRL_TX_ABORT_DIS_MASK          (0x10U)
#define XCVR_TSM_CTRL_TX_ABORT_DIS_SHIFT         (4U)
/*! TX_ABORT_DIS - Transmit Abort Disable */
#define XCVR_TSM_CTRL_TX_ABORT_DIS(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TX_ABORT_DIS_SHIFT)) & XCVR_TSM_CTRL_TX_ABORT_DIS_MASK)

#define XCVR_TSM_CTRL_RX_ABORT_DIS_MASK          (0x20U)
#define XCVR_TSM_CTRL_RX_ABORT_DIS_SHIFT         (5U)
/*! RX_ABORT_DIS - Receive Abort Disable */
#define XCVR_TSM_CTRL_RX_ABORT_DIS(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_RX_ABORT_DIS_SHIFT)) & XCVR_TSM_CTRL_RX_ABORT_DIS_MASK)

#define XCVR_TSM_CTRL_ABORT_ON_CTUNE_MASK        (0x40U)
#define XCVR_TSM_CTRL_ABORT_ON_CTUNE_SHIFT       (6U)
/*! ABORT_ON_CTUNE - Abort On Coarse Tune Lock Detect Failure
 *  0b0..don't allow TSM abort on Coarse Tune Unlock Detect
 *  0b1..allow TSM abort on Coarse Tune Unlock Detect
 */
#define XCVR_TSM_CTRL_ABORT_ON_CTUNE(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_ABORT_ON_CTUNE_SHIFT)) & XCVR_TSM_CTRL_ABORT_ON_CTUNE_MASK)

#define XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_MASK    (0x80U)
#define XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_SHIFT   (7U)
/*! ABORT_ON_FREQ_TARG - Abort On Frequency Target Lock Detect Failure
 *  0b0..don't allow TSM abort on Frequency Target Unlock Detect
 *  0b1..allow TSM abort on Frequency Target Unlock Detect
 */
#define XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_SHIFT)) & XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_MASK)

#define XCVR_TSM_CTRL_TSM_IRQ0_EN_MASK           (0x100U)
#define XCVR_TSM_CTRL_TSM_IRQ0_EN_SHIFT          (8U)
/*! TSM_IRQ0_EN - TSM_IRQ0 Enable/Disable bit
 *  0b0..TSM_IRQ0 is disabled
 *  0b1..TSM_IRQ0 is enabled
 */
#define XCVR_TSM_CTRL_TSM_IRQ0_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TSM_IRQ0_EN_SHIFT)) & XCVR_TSM_CTRL_TSM_IRQ0_EN_MASK)

#define XCVR_TSM_CTRL_TSM_IRQ1_EN_MASK           (0x200U)
#define XCVR_TSM_CTRL_TSM_IRQ1_EN_SHIFT          (9U)
/*! TSM_IRQ1_EN - TSM_IRQ1 Enable/Disable bit
 *  0b0..TSM_IRQ1 is disabled
 *  0b1..TSM_IRQ1 is enabled
 */
#define XCVR_TSM_CTRL_TSM_IRQ1_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TSM_IRQ1_EN_SHIFT)) & XCVR_TSM_CTRL_TSM_IRQ1_EN_MASK)

#define XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_EN_MASK     (0x400U)
#define XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT    (10U)
/*! PLL_UNLOCK_IRQ_EN - PLL Unlock Interrupt Enable
 *  0b0..allows PLL unlock event to generate an interrupt
 *  0b1..A PLL unlock event will set the PLL_UNLOCK_IRQ status bit, but an interrupt is not generated
 */
#define XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT)) & XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_EN_MASK)

#define XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_MASK        (0x800U)
#define XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_SHIFT       (11U)
/*! PLL_UNLOCK_IRQ - PLL Unlock IRQ
 *  0b0..A PLL Unlock Interrupt has not occurred
 *  0b1..A PLL Unlock Interrupt has occurred
 */
#define XCVR_TSM_CTRL_PLL_UNLOCK_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_SHIFT)) & XCVR_TSM_CTRL_PLL_UNLOCK_IRQ_MASK)

#define XCVR_TSM_CTRL_TSM_LL_INHIBIT_MASK        (0xF000U)
#define XCVR_TSM_CTRL_TSM_LL_INHIBIT_SHIFT       (12U)
/*! TSM_LL_INHIBIT - TSM Per-Link-Layer Inhibit */
#define XCVR_TSM_CTRL_TSM_LL_INHIBIT(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TSM_LL_INHIBIT_SHIFT)) & XCVR_TSM_CTRL_TSM_LL_INHIBIT_MASK)

#define XCVR_TSM_CTRL_RF_ACTIVE_EXTEND_MASK      (0xFF0000U)
#define XCVR_TSM_CTRL_RF_ACTIVE_EXTEND_SHIFT     (16U)
/*! RF_ACTIVE_EXTEND - TSM RF_ACTIVE Extension Duration */
#define XCVR_TSM_CTRL_RF_ACTIVE_EXTEND(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_RF_ACTIVE_EXTEND_SHIFT)) & XCVR_TSM_CTRL_RF_ACTIVE_EXTEND_MASK)

#define XCVR_TSM_CTRL_BKPT_MASK                  (0xFF000000U)
#define XCVR_TSM_CTRL_BKPT_SHIFT                 (24U)
/*! BKPT - TSM Breakpoint */
#define XCVR_TSM_CTRL_BKPT(x)                    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_BKPT_SHIFT)) & XCVR_TSM_CTRL_BKPT_MASK)
/*! @} */

/*! @name LPPS_CTRL - TSM CONTROL */
/*! @{ */

#define XCVR_TSM_LPPS_CTRL_LPPS_LNA_MIX_ALLOW_MASK (0x2U)
#define XCVR_TSM_LPPS_CTRL_LPPS_LNA_MIX_ALLOW_SHIFT (1U)
/*! LPPS_LNA_MIX_ALLOW - LPPS_LNA_MIX_ALLOW */
#define XCVR_TSM_LPPS_CTRL_LPPS_LNA_MIX_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_LNA_MIX_ALLOW_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_LNA_MIX_ALLOW_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_CBPF_ALLOW_MASK  (0x4U)
#define XCVR_TSM_LPPS_CTRL_LPPS_CBPF_ALLOW_SHIFT (2U)
/*! LPPS_CBPF_ALLOW - LPPS_CBPF_ALLOW */
#define XCVR_TSM_LPPS_CTRL_LPPS_CBPF_ALLOW(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_CBPF_ALLOW_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_CBPF_ALLOW_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_ADC_ALLOW_MASK   (0x8U)
#define XCVR_TSM_LPPS_CTRL_LPPS_ADC_ALLOW_SHIFT  (3U)
/*! LPPS_ADC_ALLOW - LPPS_ADC_ALLOW */
#define XCVR_TSM_LPPS_CTRL_LPPS_ADC_ALLOW(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_ADC_ALLOW_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_ADC_ALLOW_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_LO_RX_ALLOW_MASK (0x10U)
#define XCVR_TSM_LPPS_CTRL_LPPS_LO_RX_ALLOW_SHIFT (4U)
/*! LPPS_LO_RX_ALLOW - LPPS_LO_RX_ALLOW */
#define XCVR_TSM_LPPS_CTRL_LPPS_LO_RX_ALLOW(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_LO_RX_ALLOW_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_LO_RX_ALLOW_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_LO_RXDRV_ALLOW_MASK (0x20U)
#define XCVR_TSM_LPPS_CTRL_LPPS_LO_RXDRV_ALLOW_SHIFT (5U)
/*! LPPS_LO_RXDRV_ALLOW - LPPS_LO_RXDRV_ALLOW */
#define XCVR_TSM_LPPS_CTRL_LPPS_LO_RXDRV_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_LO_RXDRV_ALLOW_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_LO_RXDRV_ALLOW_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_RX_DIG_ALLOW_MASK (0x40U)
#define XCVR_TSM_LPPS_CTRL_LPPS_RX_DIG_ALLOW_SHIFT (6U)
/*! LPPS_RX_DIG_ALLOW - LPPS_RX_DIG_ALLOW */
#define XCVR_TSM_LPPS_CTRL_LPPS_RX_DIG_ALLOW(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_RX_DIG_ALLOW_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_RX_DIG_ALLOW_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_RX_PHY_ALLOW_MASK (0x80U)
#define XCVR_TSM_LPPS_CTRL_LPPS_RX_PHY_ALLOW_SHIFT (7U)
/*! LPPS_RX_PHY_ALLOW - LPPS_RX_PHY_ALLOW */
#define XCVR_TSM_LPPS_CTRL_LPPS_RX_PHY_ALLOW(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_RX_PHY_ALLOW_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_RX_PHY_ALLOW_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_START_RX_MASK    (0xFF0000U)
#define XCVR_TSM_LPPS_CTRL_LPPS_START_RX_SHIFT   (16U)
/*! LPPS_START_RX - LPPS Fast TSM RX Warmup "Jump-from" Point */
#define XCVR_TSM_LPPS_CTRL_LPPS_START_RX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_START_RX_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_START_RX_MASK)

#define XCVR_TSM_LPPS_CTRL_LPPS_DEST_RX_MASK     (0xFF000000U)
#define XCVR_TSM_LPPS_CTRL_LPPS_DEST_RX_SHIFT    (24U)
/*! LPPS_DEST_RX - LPPS Fast TSM RX Warmup "Jump-to" Point */
#define XCVR_TSM_LPPS_CTRL_LPPS_DEST_RX(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_LPPS_CTRL_LPPS_DEST_RX_SHIFT)) & XCVR_TSM_LPPS_CTRL_LPPS_DEST_RX_MASK)
/*! @} */

/*! @name END_OF_SEQ - TSM END OF SEQUENCE */
/*! @{ */

#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_MASK    (0xFFU)
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_SHIFT   (0U)
/*! END_OF_TX_WU - End of TX Warmup */
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WU(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_MASK)

#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_MASK    (0xFF00U)
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_SHIFT   (8U)
/*! END_OF_TX_WD - End of TX Warmdown */
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_MASK)

#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_MASK    (0xFF0000U)
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_SHIFT   (16U)
/*! END_OF_RX_WU - End of RX Warmup */
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WU(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_MASK)

#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_MASK    (0xFF000000U)
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_SHIFT   (24U)
/*! END_OF_RX_WD - End of RX Warmdown */
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_MASK)
/*! @} */

/*! @name WU_LATENCY - WARMUP LATENCY */
/*! @{ */

#define XCVR_TSM_WU_LATENCY_TX_DATAPATH_LATENCY_MASK (0xFFU)
#define XCVR_TSM_WU_LATENCY_TX_DATAPATH_LATENCY_SHIFT (0U)
/*! TX_DATAPATH_LATENCY - TX Datapath Latency */
#define XCVR_TSM_WU_LATENCY_TX_DATAPATH_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_WU_LATENCY_TX_DATAPATH_LATENCY_SHIFT)) & XCVR_TSM_WU_LATENCY_TX_DATAPATH_LATENCY_MASK)

#define XCVR_TSM_WU_LATENCY_RX_SETTLING_LATENCY_MASK (0xFF0000U)
#define XCVR_TSM_WU_LATENCY_RX_SETTLING_LATENCY_SHIFT (16U)
/*! RX_SETTLING_LATENCY - RX Settling Latency */
#define XCVR_TSM_WU_LATENCY_RX_SETTLING_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_WU_LATENCY_RX_SETTLING_LATENCY_SHIFT)) & XCVR_TSM_WU_LATENCY_RX_SETTLING_LATENCY_MASK)
/*! @} */

/*! @name RECYCLE_COUNT - TSM RECYCLE COUNT */
/*! @{ */

#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_MASK (0xFFU)
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_SHIFT (0U)
/*! RECYCLE_COUNT0 - TSM RX Recycle Count 0 */
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_SHIFT)) & XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_MASK)

#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_MASK (0xFF00U)
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_SHIFT (8U)
/*! RECYCLE_COUNT1 - TSM RX Recycle Count 1 */
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_SHIFT)) & XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_MASK)

#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_MASK (0xFF0000U)
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_SHIFT (16U)
/*! RECYCLE_COUNT2 - TSM RX Recycle Count 2 */
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_SHIFT)) & XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_MASK)
/*! @} */

/*! @name FAST_CTRL1 - TSM FAST WARMUP CONTROL 1 */
/*! @{ */

#define XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_MASK   (0x1U)
#define XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_SHIFT  (0U)
/*! FAST_TX_WU_EN - Fast TSM TX Warmup Enable
 *  0b0..Fast TSM TX Warmups are disabled
 *  0b1..Fast TSM TX Warmups are enabled, if the RF channel has not changed since the last TX warmup, and for
 *       Bluetooth LE mode, the RF channel is not an advertising channel.
 */
#define XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_MASK   (0x2U)
#define XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_SHIFT  (1U)
/*! FAST_RX_WU_EN - Fast TSM RX Warmup Enable
 *  0b0..Fast TSM RX Warmups are disabled
 *  0b1..Fast TSM RX Warmups are enabled, if the RF channel has not changed since the last RX warmup, and for
 *       Bluetooth LE mode, the RF channel is not an advertising channel.
 */
#define XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_MASK   (0x4U)
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_SHIFT  (2U)
/*! FAST_RX2TX_EN - Fast TSM RX-to-TX Transition Enable
 *  0b0..Disable Fast RX-to-TX transitions
 *  0b1..Enable Fast RX-to-TX transitions (if fast_rx2tx_wu is asserted by the Link Layer)
 */
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_PWRSAVE_TX_WU_EN_MASK (0x10U)
#define XCVR_TSM_FAST_CTRL1_PWRSAVE_TX_WU_EN_SHIFT (4U)
/*! PWRSAVE_TX_WU_EN - Power Save TSM TX Warmup Enable
 *  0b0..PowerSave TSM TX Warmups are disabled
 *  0b1..PowerSave TSM TX Warmups are enabled, if the RF channel has not changed since the last TX warmup.
 */
#define XCVR_TSM_FAST_CTRL1_PWRSAVE_TX_WU_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_PWRSAVE_TX_WU_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_PWRSAVE_TX_WU_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_PWRSAVE_RX_WU_EN_MASK (0x20U)
#define XCVR_TSM_FAST_CTRL1_PWRSAVE_RX_WU_EN_SHIFT (5U)
/*! PWRSAVE_RX_WU_EN - Power Save TSM RX Warmup Enable
 *  0b0..PowerSave TSM RX Warmups are disabled
 *  0b1..PowerSave TSM RX Warmups are enabled, if the RF channel has not changed since the last RX warmup.
 */
#define XCVR_TSM_FAST_CTRL1_PWRSAVE_RX_WU_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_PWRSAVE_RX_WU_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_PWRSAVE_RX_WU_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_PWRSAVE_WU_CLEAR_MASK (0x40U)
#define XCVR_TSM_FAST_CTRL1_PWRSAVE_WU_CLEAR_SHIFT (6U)
/*! PWRSAVE_WU_CLEAR - PowerSave TSM Warmup Clear State */
#define XCVR_TSM_FAST_CTRL1_PWRSAVE_WU_CLEAR(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_PWRSAVE_WU_CLEAR_SHIFT)) & XCVR_TSM_FAST_CTRL1_PWRSAVE_WU_CLEAR_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_MASK (0xFF00U)
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_SHIFT (8U)
/*! FAST_RX2TX_START - TSM "Jump-to" point for a Fast TSM RX-to-TX Transition. */
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_TX2RX_EN_MASK   (0x800000U)
#define XCVR_TSM_FAST_CTRL1_FAST_TX2RX_EN_SHIFT  (23U)
/*! FAST_TX2RX_EN - Fast TSM TX-to-RX Transition Enable
 *  0b0..Disable Fast TX-to-RX transitions
 *  0b1..Enable Fast TX-to-RX transitions (if fast_tx2rx_wu is asserted by Ranging sequence manager)
 */
#define XCVR_TSM_FAST_CTRL1_FAST_TX2RX_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_TX2RX_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_TX2RX_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_TX2RX_START_MASK (0xFF000000U)
#define XCVR_TSM_FAST_CTRL1_FAST_TX2RX_START_SHIFT (24U)
/*! FAST_TX2RX_START - TSM "Jump-to" point for a Fast TSM TX-to-RX Transition. */
#define XCVR_TSM_FAST_CTRL1_FAST_TX2RX_START(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_TX2RX_START_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_TX2RX_START_MASK)
/*! @} */

/*! @name FAST_CTRL2 - TSM FAST WARMUP CONTROL 2 */
/*! @{ */

#define XCVR_TSM_FAST_CTRL2_FAST_START_TX_MASK   (0xFFU)
#define XCVR_TSM_FAST_CTRL2_FAST_START_TX_SHIFT  (0U)
/*! FAST_START_TX - Fast TSM TX "Jump-from" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_START_TX(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_START_TX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_START_TX_MASK)

#define XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_MASK    (0xFF00U)
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_SHIFT   (8U)
/*! FAST_DEST_TX - Fast TSM TX "Jump-to" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_TX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_MASK)

#define XCVR_TSM_FAST_CTRL2_FAST_START_RX_MASK   (0xFF0000U)
#define XCVR_TSM_FAST_CTRL2_FAST_START_RX_SHIFT  (16U)
/*! FAST_START_RX - Fast TSM RX "Jump-from" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_START_RX(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_START_RX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_START_RX_MASK)

#define XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_MASK    (0xFF000000U)
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_SHIFT   (24U)
/*! FAST_DEST_RX - Fast TSM RX "Jump-to" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_RX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_MASK)
/*! @} */

/*! @name FAST_CTRL3 - TSM FAST WARMUP CONTROL 3 */
/*! @{ */

#define XCVR_TSM_FAST_CTRL3_FAST_RX2TX_START_FC_MASK (0xFF00U)
#define XCVR_TSM_FAST_CTRL3_FAST_RX2TX_START_FC_SHIFT (8U)
/*! FAST_RX2TX_START_FC - TSM "Jump-to" point for RSM's FC RX-to-TX Transition */
#define XCVR_TSM_FAST_CTRL3_FAST_RX2TX_START_FC(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL3_FAST_RX2TX_START_FC_SHIFT)) & XCVR_TSM_FAST_CTRL3_FAST_RX2TX_START_FC_MASK)

#define XCVR_TSM_FAST_CTRL3_FAST_TX2RX_START_FC_MASK (0xFF000000U)
#define XCVR_TSM_FAST_CTRL3_FAST_TX2RX_START_FC_SHIFT (24U)
/*! FAST_TX2RX_START_FC - TSM "Jump-to" point for RSM's FC TX-to-RX Transition */
#define XCVR_TSM_FAST_CTRL3_FAST_TX2RX_START_FC(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL3_FAST_TX2RX_START_FC_SHIFT)) & XCVR_TSM_FAST_CTRL3_FAST_TX2RX_START_FC_MASK)
/*! @} */

/*! @name TIMING00 - TSM_TIMING00 */
/*! @{ */

#define XCVR_TSM_TIMING00_RF_ACTIVE_TX_HI_MASK   (0xFFU)
#define XCVR_TSM_TIMING00_RF_ACTIVE_TX_HI_SHIFT  (0U)
/*! RF_ACTIVE_TX_HI - Assertion time setting for RF_ACTIVE (TX) */
#define XCVR_TSM_TIMING00_RF_ACTIVE_TX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_RF_ACTIVE_TX_HI_SHIFT)) & XCVR_TSM_TIMING00_RF_ACTIVE_TX_HI_MASK)

#define XCVR_TSM_TIMING00_RF_ACTIVE_TX_LO_MASK   (0xFF00U)
#define XCVR_TSM_TIMING00_RF_ACTIVE_TX_LO_SHIFT  (8U)
/*! RF_ACTIVE_TX_LO - De-assertion time setting for RF_ACTIVE (TX) */
#define XCVR_TSM_TIMING00_RF_ACTIVE_TX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_RF_ACTIVE_TX_LO_SHIFT)) & XCVR_TSM_TIMING00_RF_ACTIVE_TX_LO_MASK)

#define XCVR_TSM_TIMING00_RF_ACTIVE_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING00_RF_ACTIVE_RX_HI_SHIFT  (16U)
/*! RF_ACTIVE_RX_HI - Assertion time setting for RF_ACTIVE_EN (RX) */
#define XCVR_TSM_TIMING00_RF_ACTIVE_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_RF_ACTIVE_RX_HI_SHIFT)) & XCVR_TSM_TIMING00_RF_ACTIVE_RX_HI_MASK)

#define XCVR_TSM_TIMING00_RF_ACTIVE_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING00_RF_ACTIVE_RX_LO_SHIFT  (24U)
/*! RF_ACTIVE_RX_LO - De-assertion time setting for RF_ACTIVE (RX) */
#define XCVR_TSM_TIMING00_RF_ACTIVE_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_RF_ACTIVE_RX_LO_SHIFT)) & XCVR_TSM_TIMING00_RF_ACTIVE_RX_LO_MASK)
/*! @} */

/*! @name TIMING01 - TSM_TIMING01 */
/*! @{ */

#define XCVR_TSM_TIMING01_RF_STATUS_TX_HI_MASK   (0xFFU)
#define XCVR_TSM_TIMING01_RF_STATUS_TX_HI_SHIFT  (0U)
/*! RF_STATUS_TX_HI - Assertion time setting for RF_STATUS (TX) */
#define XCVR_TSM_TIMING01_RF_STATUS_TX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_RF_STATUS_TX_HI_SHIFT)) & XCVR_TSM_TIMING01_RF_STATUS_TX_HI_MASK)

#define XCVR_TSM_TIMING01_RF_STATUS_TX_LO_MASK   (0xFF00U)
#define XCVR_TSM_TIMING01_RF_STATUS_TX_LO_SHIFT  (8U)
/*! RF_STATUS_TX_LO - De-assertion time setting for RF_STATUS (TX) */
#define XCVR_TSM_TIMING01_RF_STATUS_TX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_RF_STATUS_TX_LO_SHIFT)) & XCVR_TSM_TIMING01_RF_STATUS_TX_LO_MASK)

#define XCVR_TSM_TIMING01_RF_STATUS_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING01_RF_STATUS_RX_HI_SHIFT  (16U)
/*! RF_STATUS_RX_HI - Assertion time setting for RF_STATUS (RX) */
#define XCVR_TSM_TIMING01_RF_STATUS_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_RF_STATUS_RX_HI_SHIFT)) & XCVR_TSM_TIMING01_RF_STATUS_RX_HI_MASK)

#define XCVR_TSM_TIMING01_RF_STATUS_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING01_RF_STATUS_RX_LO_SHIFT  (24U)
/*! RF_STATUS_RX_LO - De-assertion time setting for RF_STATUS (RX) */
#define XCVR_TSM_TIMING01_RF_STATUS_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_RF_STATUS_RX_LO_SHIFT)) & XCVR_TSM_TIMING01_RF_STATUS_RX_LO_MASK)
/*! @} */

/*! @name TIMING02 - TSM_TIMING02 */
/*! @{ */

#define XCVR_TSM_TIMING02_RF_PRIORITY_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING02_RF_PRIORITY_TX_HI_SHIFT (0U)
/*! RF_PRIORITY_TX_HI - Assertion time setting for RF_PRIORITY (TX) */
#define XCVR_TSM_TIMING02_RF_PRIORITY_TX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING02_RF_PRIORITY_TX_HI_SHIFT)) & XCVR_TSM_TIMING02_RF_PRIORITY_TX_HI_MASK)

#define XCVR_TSM_TIMING02_RF_PRIORITY_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING02_RF_PRIORITY_TX_LO_SHIFT (8U)
/*! RF_PRIORITY_TX_LO - De-assertion time setting for RF_PRIORITY (TX) */
#define XCVR_TSM_TIMING02_RF_PRIORITY_TX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING02_RF_PRIORITY_TX_LO_SHIFT)) & XCVR_TSM_TIMING02_RF_PRIORITY_TX_LO_MASK)

#define XCVR_TSM_TIMING02_RF_PRIORITY_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING02_RF_PRIORITY_RX_HI_SHIFT (16U)
/*! RF_PRIORITY_RX_HI - Assertion time setting for RF_PRIORITY (RX) */
#define XCVR_TSM_TIMING02_RF_PRIORITY_RX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING02_RF_PRIORITY_RX_HI_SHIFT)) & XCVR_TSM_TIMING02_RF_PRIORITY_RX_HI_MASK)

#define XCVR_TSM_TIMING02_RF_PRIORITY_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING02_RF_PRIORITY_RX_LO_SHIFT (24U)
/*! RF_PRIORITY_RX_LO - De-assertion time setting for RF_PRIORITY (RX) */
#define XCVR_TSM_TIMING02_RF_PRIORITY_RX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING02_RF_PRIORITY_RX_LO_SHIFT)) & XCVR_TSM_TIMING02_RF_PRIORITY_RX_LO_MASK)
/*! @} */

/*! @name TIMING03 - TSM_TIMING03 */
/*! @{ */

#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_HI_SHIFT (0U)
/*! IRQ0_START_TRIG_TX_HI - Assertion time setting for IRQ0_START_TRIG (TX) */
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_HI_SHIFT)) & XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_HI_MASK)

#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_LO_SHIFT (8U)
/*! IRQ0_START_TRIG_TX_LO - De-assertion time setting for IRQ0_START_TRIG (TX) */
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_LO_SHIFT)) & XCVR_TSM_TIMING03_IRQ0_START_TRIG_TX_LO_MASK)

#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_HI_SHIFT (16U)
/*! IRQ0_START_TRIG_RX_HI - Assertion time setting for IRQ0_START_TRIG (RX) */
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_HI_SHIFT)) & XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_HI_MASK)

#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_LO_SHIFT (24U)
/*! IRQ0_START_TRIG_RX_LO - De-assertion time setting for IRQ0_START_TRIG (RX) */
#define XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_LO_SHIFT)) & XCVR_TSM_TIMING03_IRQ0_START_TRIG_RX_LO_MASK)
/*! @} */

/*! @name TIMING04 - TSM_TIMING04 */
/*! @{ */

#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_HI_SHIFT (0U)
/*! IRQ1_STOP_TRIG_TX_HI - Assertion time setting for IRQ1_STOP_TRIG (TX) */
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_HI_SHIFT)) & XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_HI_MASK)

#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_LO_SHIFT (8U)
/*! IRQ1_STOP_TRIG_TX_LO - De-assertion time setting for IRQ1_STOP_TRIG (TX) */
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_LO_SHIFT)) & XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_TX_LO_MASK)

#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_HI_SHIFT (16U)
/*! IRQ1_STOP_TRIG_RX_HI - Assertion time setting for IRQ1_STOP_TRIG (RX) */
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_HI_SHIFT)) & XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_HI_MASK)

#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_LO_SHIFT (24U)
/*! IRQ1_STOP_TRIG_RX_LO - De-assertion time setting for IRQ1_STOP_TRIG (RX) */
#define XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_LO_SHIFT)) & XCVR_TSM_TIMING04_IRQ1_STOP_TRIG_RX_LO_MASK)
/*! @} */

/*! @name TIMING05 - TSM_TIMING05 */
/*! @{ */

#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO0_TRIG_EN_TX_HI - Assertion time setting for GPIO0_TRIG_EN (TX) */
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO0_TRIG_EN_TX_LO - De-assertion time setting for GPIO0_TRIG_EN (TX) */
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING05_GPIO0_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO0_TRIG_EN_RX_HI - Assertion time setting for GPIO0_TRIG_EN (RX) */
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO0_TRIG_EN_RX_LO - De-assertion time setting for GPIO0_TRIG_EN (RX) */
#define XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING05_GPIO0_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING06 - TSM_TIMING06 */
/*! @{ */

#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO1_TRIG_EN_TX_HI - Assertion time setting for GPIO1_TRIG_EN (TX) */
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO1_TRIG_EN_TX_LO - De-assertion time setting for GPIO1_TRIG_EN (TX) */
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING06_GPIO1_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO1_TRIG_EN_RX_HI - Assertion time setting for GPIO1_TRIG_EN (RX) */
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO1_TRIG_EN_RX_LO - De-assertion time setting for GPIO1_TRIG_EN (RX) */
#define XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING06_GPIO1_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING07 - TSM_TIMING07 */
/*! @{ */

#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO2_TRIG_EN_TX_HI - Assertion time setting for GPIO2_TRIG_EN (TX) */
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO2_TRIG_EN_TX_LO - De-assertion time setting for GPIO2_TRIG_EN (TX) */
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING07_GPIO2_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO2_TRIG_EN_RX_HI - Assertion time setting for GPIO2_TRIG_EN (RX) */
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO2_TRIG_EN_RX_LO - De-assertion time setting for GPIO2_TRIG_EN (RX) */
#define XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING07_GPIO2_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING08 - TSM_TIMING08 */
/*! @{ */

#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO3_TRIG_EN_TX_HI - Assertion time setting for GPIO3_TRIG_EN (TX) */
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO3_TRIG_EN_TX_LO - De-assertion time setting for GPIO3_TRIG_EN (TX) */
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING08_GPIO3_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO3_TRIG_EN_RX_HI - Assertion time setting for GPIO3_TRIG_EN (RX) */
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO3_TRIG_EN_RX_LO - De-assertion time setting for GPIO3_TRIG_EN (RX) */
#define XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING08_GPIO3_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING09 - TSM_TIMING09 */
/*! @{ */

#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_HI_SHIFT (0U)
/*! DCOC_GAIN_CFG_EN_TX_HI - Assertion time setting for DCOC_GAIN_CFG_EN (TX) */
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_LO_SHIFT (8U)
/*! DCOC_GAIN_CFG_EN_TX_LO - De-assertion time setting for DCOC_GAIN_CFG_EN (TX) */
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_HI_SHIFT (16U)
/*! DCOC_GAIN_CFG_EN_RX_HI - Assertion time setting for DCOC_GAIN_CFG_EN (RX) */
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_LO_SHIFT (24U)
/*! DCOC_GAIN_CFG_EN_RX_LO - De-assertion time setting for DCOC_GAIN_CFG_EN (RX) */
#define XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING09_DCOC_GAIN_CFG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING10 - TSM_TIMING10 */
/*! @{ */

#define XCVR_TSM_TIMING10_LDO_CAL_EN_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING10_LDO_CAL_EN_TX_HI_SHIFT (0U)
/*! LDO_CAL_EN_TX_HI - Assertion time setting for LDO_CAL_EN (TX) */
#define XCVR_TSM_TIMING10_LDO_CAL_EN_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_LDO_CAL_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING10_LDO_CAL_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING10_LDO_CAL_EN_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING10_LDO_CAL_EN_TX_LO_SHIFT (8U)
/*! LDO_CAL_EN_TX_LO - De-assertion time setting for LDO_CAL_EN (TX) */
#define XCVR_TSM_TIMING10_LDO_CAL_EN_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_LDO_CAL_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING10_LDO_CAL_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING10_LDO_CAL_EN_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING10_LDO_CAL_EN_RX_HI_SHIFT (16U)
/*! LDO_CAL_EN_RX_HI - Assertion time setting for LDO_CAL_EN (RX) */
#define XCVR_TSM_TIMING10_LDO_CAL_EN_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_LDO_CAL_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING10_LDO_CAL_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING10_LDO_CAL_EN_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING10_LDO_CAL_EN_RX_LO_SHIFT (24U)
/*! LDO_CAL_EN_RX_LO - De-assertion time setting for LDO_CAL_EN (RX) */
#define XCVR_TSM_TIMING10_LDO_CAL_EN_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_LDO_CAL_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING10_LDO_CAL_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING11 - TSM_TIMING11 */
/*! @{ */

#define XCVR_TSM_TIMING11_PLL_DIG_EN_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING11_PLL_DIG_EN_TX_HI_SHIFT (0U)
/*! PLL_DIG_EN_TX_HI - Assertion time setting for PLL_DIG_EN (TX) */
#define XCVR_TSM_TIMING11_PLL_DIG_EN_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING11_PLL_DIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING11_PLL_DIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING11_PLL_DIG_EN_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING11_PLL_DIG_EN_TX_LO_SHIFT (8U)
/*! PLL_DIG_EN_TX_LO - De-assertion time setting for PLL_DIG_EN (TX) */
#define XCVR_TSM_TIMING11_PLL_DIG_EN_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING11_PLL_DIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING11_PLL_DIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING11_PLL_DIG_EN_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING11_PLL_DIG_EN_RX_HI_SHIFT (16U)
/*! PLL_DIG_EN_RX_HI - Assertion time setting for PLL_DIG_EN (RX) */
#define XCVR_TSM_TIMING11_PLL_DIG_EN_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING11_PLL_DIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING11_PLL_DIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING11_PLL_DIG_EN_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING11_PLL_DIG_EN_RX_LO_SHIFT (24U)
/*! PLL_DIG_EN_RX_LO - De-assertion time setting for PLL_DIG_EN (RX) */
#define XCVR_TSM_TIMING11_PLL_DIG_EN_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING11_PLL_DIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING11_PLL_DIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING12 - TSM_TIMING12 */
/*! @{ */

#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_HI_SHIFT (0U)
/*! SIGMA_DELTA_EN_TX_HI - Assertion time setting for SIGMA_DELTA_EN (TX) */
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_LO_SHIFT (8U)
/*! SIGMA_DELTA_EN_TX_LO - De-assertion time setting for SIGMA_DELTA_EN (TX) */
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING12_SIGMA_DELTA_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_HI_SHIFT (16U)
/*! SIGMA_DELTA_EN_RX_HI - Assertion time setting for SIGMA_DELTA_EN (RX) */
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_LO_SHIFT (24U)
/*! SIGMA_DELTA_EN_RX_LO - De-assertion time setting for SIGMA_DELTA_EN (RX) */
#define XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING12_SIGMA_DELTA_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING13 - TSM_TIMING13 */
/*! @{ */

#define XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_HI_SHIFT (0U)
/*! DCOC_CAL_EN_TX_HI - Assertion time setting for DCOC_CAL_EN (TX) */
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_LO_SHIFT (8U)
/*! DCOC_CAL_EN_TX_LO - De-assertion time setting for DCOC_CAL_EN (TX) */
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING13_DCOC_CAL_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_HI_SHIFT (16U)
/*! DCOC_CAL_EN_RX_HI - Assertion time setting for DCOC_CAL_EN (RX) */
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_LO_SHIFT (24U)
/*! DCOC_CAL_EN_RX_LO - De-assertion time setting for DCOC_CAL_EN (RX) */
#define XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING13_DCOC_CAL_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING14 - TSM_TIMING14 */
/*! @{ */

#define XCVR_TSM_TIMING14_TX_DIG_EN_TX_HI_MASK   (0xFFU)
#define XCVR_TSM_TIMING14_TX_DIG_EN_TX_HI_SHIFT  (0U)
/*! TX_DIG_EN_TX_HI - Assertion time setting for TX_DIG_EN (TX) */
#define XCVR_TSM_TIMING14_TX_DIG_EN_TX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING14_TX_DIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING14_TX_DIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING14_TX_DIG_EN_TX_LO_MASK   (0xFF00U)
#define XCVR_TSM_TIMING14_TX_DIG_EN_TX_LO_SHIFT  (8U)
/*! TX_DIG_EN_TX_LO - De-assertion time setting for TX_DIG_EN (TX) */
#define XCVR_TSM_TIMING14_TX_DIG_EN_TX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING14_TX_DIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING14_TX_DIG_EN_TX_LO_MASK)
/*! @} */

/*! @name TIMING15 - TSM_TIMING15 */
/*! @{ */

#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_HI_SHIFT (0U)
/*! FREQ_TARG_LD_EN_TX_HI - Assertion time setting for FREQ_TARG_LD_EN (TX) */
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_LO_SHIFT (8U)
/*! FREQ_TARG_LD_EN_TX_LO - De-assertion time setting for FREQ_TARG_LD_EN (TX) */
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_HI_SHIFT (16U)
/*! FREQ_TARG_LD_EN_RX_HI - Assertion time setting for FREQ_TARG_LD_EN (RX) */
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_LO_SHIFT (24U)
/*! FREQ_TARG_LD_EN_RX_LO - De-assertion time setting for FREQ_TARG_LD_EN (RX) */
#define XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING15_FREQ_TARG_LD_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING16 - TSM_TIMING16 */
/*! @{ */

#define XCVR_TSM_TIMING16_RX_INIT_RX_HI_MASK     (0xFF0000U)
#define XCVR_TSM_TIMING16_RX_INIT_RX_HI_SHIFT    (16U)
/*! RX_INIT_RX_HI - Assertion time setting for RX_INIT (RX) */
#define XCVR_TSM_TIMING16_RX_INIT_RX_HI(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING16_RX_INIT_RX_HI_SHIFT)) & XCVR_TSM_TIMING16_RX_INIT_RX_HI_MASK)

#define XCVR_TSM_TIMING16_RX_INIT_RX_LO_MASK     (0xFF000000U)
#define XCVR_TSM_TIMING16_RX_INIT_RX_LO_SHIFT    (24U)
/*! RX_INIT_RX_LO - De-assertion time setting for RX_INIT (RX) */
#define XCVR_TSM_TIMING16_RX_INIT_RX_LO(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING16_RX_INIT_RX_LO_SHIFT)) & XCVR_TSM_TIMING16_RX_INIT_RX_LO_MASK)
/*! @} */

/*! @name TIMING17 - TSM_TIMING17 */
/*! @{ */

#define XCVR_TSM_TIMING17_RX_DIG_EN_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING17_RX_DIG_EN_RX_HI_SHIFT  (16U)
/*! RX_DIG_EN_RX_HI - Assertion time setting for RX_DIG_EN (RX) */
#define XCVR_TSM_TIMING17_RX_DIG_EN_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING17_RX_DIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING17_RX_DIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING17_RX_DIG_EN_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING17_RX_DIG_EN_RX_LO_SHIFT  (24U)
/*! RX_DIG_EN_RX_LO - De-assertion time setting for RX_DIG_EN (RX) */
#define XCVR_TSM_TIMING17_RX_DIG_EN_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING17_RX_DIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING17_RX_DIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING18 - TSM_TIMING18 */
/*! @{ */

#define XCVR_TSM_TIMING18_RX_PHY_EN_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING18_RX_PHY_EN_RX_HI_SHIFT  (16U)
/*! RX_PHY_EN_RX_HI - Assertion time setting for RX_PHY_EN (RX) */
#define XCVR_TSM_TIMING18_RX_PHY_EN_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING18_RX_PHY_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING18_RX_PHY_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING18_RX_PHY_EN_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING18_RX_PHY_EN_RX_LO_SHIFT  (24U)
/*! RX_PHY_EN_RX_LO - De-assertion time setting for RX_PHY_EN (RX) */
#define XCVR_TSM_TIMING18_RX_PHY_EN_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING18_RX_PHY_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING18_RX_PHY_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING19 - TSM_TIMING19 */
/*! @{ */

#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_HI_SHIFT (0U)
/*! SEQ_BG_PUP_IBG_CAL_TX_HI - Assertion time setting for SEQ_BG_PUP_IBG_CAL (TX) */
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_HI_SHIFT)) & XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_HI_MASK)

#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_LO_SHIFT (8U)
/*! SEQ_BG_PUP_IBG_CAL_TX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_CAL (TX) */
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_LO_SHIFT)) & XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_TX_LO_MASK)

#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_HI_SHIFT (16U)
/*! SEQ_BG_PUP_IBG_CAL_RX_HI - Assertion time setting for SEQ_BG_PUP_IBG_CAL (RX) */
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_HI_SHIFT)) & XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_HI_MASK)

#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_LO_SHIFT (24U)
/*! SEQ_BG_PUP_IBG_CAL_RX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_CAL (RX) */
#define XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_LO_SHIFT)) & XCVR_TSM_TIMING19_SEQ_BG_PUP_IBG_CAL_RX_LO_MASK)
/*! @} */

/*! @name TIMING20 - TSM_TIMING20 */
/*! @{ */

#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_HI_SHIFT (0U)
/*! SEQ_LDOTRIM_PUP_TX_HI - Assertion time setting for SEQ_LDOTRIM_PUP (TX) */
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_LO_SHIFT (8U)
/*! SEQ_LDOTRIM_PUP_TX_LO - De-assertion time setting for SEQ_LDOTRIM_PUP (TX) */
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_HI_SHIFT (16U)
/*! SEQ_LDOTRIM_PUP_RX_HI - Assertion time setting for SEQ_LDOTRIM_PUP (RX) */
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_LO_SHIFT (24U)
/*! SEQ_LDOTRIM_PUP_RX_LO - De-assertion time setting for SEQ_LDOTRIM_PUP (RX) */
#define XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING20_SEQ_LDOTRIM_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING21 - TSM_TIMING21 */
/*! @{ */

#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_HI_SHIFT (0U)
/*! SEQ_LDO_CAL_PUP_TX_HI - Assertion time setting for SEQ_LDO_CAL_PUP (TX) */
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_LO_SHIFT (8U)
/*! SEQ_LDO_CAL_PUP_TX_LO - De-assertion time setting for SEQ_LDO_CAL_PUP (TX) */
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_HI_SHIFT (16U)
/*! SEQ_LDO_CAL_PUP_RX_HI - Assertion time setting for SEQ_LDO_CAL_PUP (RX) */
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_LO_SHIFT (24U)
/*! SEQ_LDO_CAL_PUP_RX_LO - De-assertion time setting for SEQ_LDO_CAL_PUP (RX) */
#define XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING21_SEQ_LDO_CAL_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING22 - TSM_TIMING22 */
/*! @{ */

#define XCVR_TSM_TIMING22_SEQ_BG_FC_TX_HI_MASK   (0xFFU)
#define XCVR_TSM_TIMING22_SEQ_BG_FC_TX_HI_SHIFT  (0U)
/*! SEQ_BG_FC_TX_HI - Assertion time setting for SEQ_BG_FC (TX) */
#define XCVR_TSM_TIMING22_SEQ_BG_FC_TX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING22_SEQ_BG_FC_TX_HI_SHIFT)) & XCVR_TSM_TIMING22_SEQ_BG_FC_TX_HI_MASK)

#define XCVR_TSM_TIMING22_SEQ_BG_FC_TX_LO_MASK   (0xFF00U)
#define XCVR_TSM_TIMING22_SEQ_BG_FC_TX_LO_SHIFT  (8U)
/*! SEQ_BG_FC_TX_LO - De-assertion time setting for SEQ_BG_FC (TX) */
#define XCVR_TSM_TIMING22_SEQ_BG_FC_TX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING22_SEQ_BG_FC_TX_LO_SHIFT)) & XCVR_TSM_TIMING22_SEQ_BG_FC_TX_LO_MASK)

#define XCVR_TSM_TIMING22_SEQ_BG_FC_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING22_SEQ_BG_FC_RX_HI_SHIFT  (16U)
/*! SEQ_BG_FC_RX_HI - Assertion time setting for SEQ_BG_FC (RX) */
#define XCVR_TSM_TIMING22_SEQ_BG_FC_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING22_SEQ_BG_FC_RX_HI_SHIFT)) & XCVR_TSM_TIMING22_SEQ_BG_FC_RX_HI_MASK)

#define XCVR_TSM_TIMING22_SEQ_BG_FC_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING22_SEQ_BG_FC_RX_LO_SHIFT  (24U)
/*! SEQ_BG_FC_RX_LO - De-assertion time setting for SEQ_BG_FC (RX) */
#define XCVR_TSM_TIMING22_SEQ_BG_FC_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING22_SEQ_BG_FC_RX_LO_SHIFT)) & XCVR_TSM_TIMING22_SEQ_BG_FC_RX_LO_MASK)
/*! @} */

/*! @name TIMING23 - TSM_TIMING23 */
/*! @{ */

#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_HI_SHIFT (0U)
/*! SEQ_LDO_GANG_FC_TX_HI - Assertion time setting for SEQ_LDO_GANG_FC (TX) */
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_HI_SHIFT)) & XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_HI_MASK)

#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_LO_SHIFT (8U)
/*! SEQ_LDO_GANG_FC_TX_LO - De-assertion time setting for SEQ_LDO_(PLL/RXTXHF/RXTXLF/VCO)_FC (TX) */
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_LO_SHIFT)) & XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_TX_LO_MASK)

#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_HI_SHIFT (16U)
/*! SEQ_LDO_GANG_FC_RX_HI - Assertion time setting for SEQ_LDO_(PLL/RXTXHF/RXTXLF/VCO)_FC (RX) */
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_HI_SHIFT)) & XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_HI_MASK)

#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_LO_SHIFT (24U)
/*! SEQ_LDO_GANG_FC_RX_LO - De-assertion time setting for SEQ_LDO_(PLL/RXTXHF/RXTXLF/VCO)_FC (RX) */
#define XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_LO_SHIFT)) & XCVR_TSM_TIMING23_SEQ_LDO_GANG_FC_RX_LO_MASK)
/*! @} */

/*! @name TIMING24 - TSM_TIMING24 */
/*! @{ */

#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_HI_SHIFT (0U)
/*! SEQ_LDO_GANG_PUP_TX_HI - Assertion time setting for SEQ_LDO_(ANT/PLL/RXTXHF/RXTXLF/VCO/XO_DIST)_PUP (TX) */
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_LO_SHIFT (8U)
/*! SEQ_LDO_GANG_PUP_TX_LO - De-assertion time setting for SEQ_LDO_(ANT/PLL/RXTXHF/RXTXLF/VCO/XO_DIST)_PUP (TX) */
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_HI_SHIFT (16U)
/*! SEQ_LDO_GANG_PUP_RX_HI - Assertion time setting for SEQ_LDO_(ANT/PLL/RXTXHF/RXTXLF/VCO/XO_DIST)_PUP (RX) */
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_LO_SHIFT (24U)
/*! SEQ_LDO_GANG_PUP_RX_LO - De-assertion time setting for SEQ_LDO_(ANT/PLL/RXTXHF/RXTXLF/VCO/XO_DIST)_PUP (RX) */
#define XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING24_SEQ_LDO_GANG_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING25 - TSM_TIMING25 */
/*! @{ */

#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_HI_SHIFT (0U)
/*! SEQ_LDO_LV_PUP_TX_HI - Assertion time setting for SEQ_LDO_LV_PUP (TX) */
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_LO_SHIFT (8U)
/*! SEQ_LDO_LV_PUP_TX_LO - De-assertion time setting for SEQ_LDO_LV_PUP (TX) */
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_HI_SHIFT (16U)
/*! SEQ_LDO_LV_PUP_RX_HI - Assertion time setting for SEQ_LDO_LV_PUP (RX) */
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_LO_SHIFT (24U)
/*! SEQ_LDO_LV_PUP_RX_LO - De-assertion time setting for SEQ_LDO_LV_PUP (RX) */
#define XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING25_SEQ_LDO_LV_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING26 - TSM_TIMING26 */
/*! @{ */

#define XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_HI_SHIFT (0U)
/*! SEQ_BG_PUP_TX_HI - Assertion time setting for SEQ_BG_PUP (TX) */
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_LO_SHIFT (8U)
/*! SEQ_BG_PUP_TX_LO - De-assertion time setting for SEQ_BG_PUP (TX) */
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING26_SEQ_BG_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_HI_SHIFT (16U)
/*! SEQ_BG_PUP_RX_HI - Assertion time setting for SEQ_BG_PUP (RX) */
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_LO_SHIFT (24U)
/*! SEQ_BG_PUP_RX_LO - De-assertion time setting for SEQ_BG_PUP (RX) */
#define XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING26_SEQ_BG_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING27 - TSM_TIMING27 */
/*! @{ */

#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_HI_SHIFT (0U)
/*! SEQ_BG_PUP_IBG_ANT_TX_HI - Assertion time setting for SEQ_BG_PUP_IBG_ANT (TX) */
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_HI_SHIFT)) & XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_HI_MASK)

#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_LO_SHIFT (8U)
/*! SEQ_BG_PUP_IBG_ANT_TX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_ANT (TX) */
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_LO_SHIFT)) & XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_TX_LO_MASK)

#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_HI_SHIFT (16U)
/*! SEQ_BG_PUP_IBG_ANT_RX_HI - Assertion time setting for SEQ_BG_PUP_IBG_ANT (RX) */
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_HI_SHIFT)) & XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_HI_MASK)

#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_LO_SHIFT (24U)
/*! SEQ_BG_PUP_IBG_ANT_RX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_ANT (RX) */
#define XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_LO_SHIFT)) & XCVR_TSM_TIMING27_SEQ_BG_PUP_IBG_ANT_RX_LO_MASK)
/*! @} */

/*! @name TIMING28 - TSM_TIMING28 */
/*! @{ */

#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_HI_SHIFT (0U)
/*! SEQ_BG_PUP_IBG_XO_DIST_TX_HI - Assertion time setting for SEQ_BG_PUP_IBG_XO_DIST (TX) */
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_HI_SHIFT)) & XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_HI_MASK)

#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_LO_SHIFT (8U)
/*! SEQ_BG_PUP_IBG_XO_DIST_TX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_XO_DIST (TX) */
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_LO_SHIFT)) & XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_TX_LO_MASK)

#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_HI_SHIFT (16U)
/*! SEQ_BG_PUP_IBG_XO_DIST_RX_HI - Assertion time setting for SEQ_BG_PUP_IBG_XO_DIST (RX) */
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_HI_SHIFT)) & XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_HI_MASK)

#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_LO_SHIFT (24U)
/*! SEQ_BG_PUP_IBG_XO_DIST_RX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_XO_DIST (RX) */
#define XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_LO_SHIFT)) & XCVR_TSM_TIMING28_SEQ_BG_PUP_IBG_XO_DIST_RX_LO_MASK)
/*! @} */

/*! @name TIMING29 - TSM_TIMING29 */
/*! @{ */

#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_HI_SHIFT (0U)
/*! SEQ_BG_PUP_IBG_TX_TX_HI - Assertion time setting for SEQ_BG_PUP_IBG_TX (TX) */
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_HI_SHIFT)) & XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_HI_MASK)

#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_LO_SHIFT (8U)
/*! SEQ_BG_PUP_IBG_TX_TX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_TX (TX) */
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_LO_SHIFT)) & XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_TX_LO_MASK)

#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_HI_SHIFT (16U)
/*! SEQ_BG_PUP_IBG_TX_RX_HI - Assertion time setting for SEQ_BG_PUP_IBG_TX (RX) */
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_HI_SHIFT)) & XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_HI_MASK)

#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_LO_SHIFT (24U)
/*! SEQ_BG_PUP_IBG_TX_RX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_TX (RX) */
#define XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_LO_SHIFT)) & XCVR_TSM_TIMING29_SEQ_BG_PUP_IBG_TX_RX_LO_MASK)
/*! @} */

/*! @name TIMING30 - TSM_TIMING30 */
/*! @{ */

#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_HI_SHIFT (0U)
/*! SEQ_BG_PUP_IBG_RX_TX_HI - Assertion time setting for SEQ_BG_PUP_IBG_RX (TX) */
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_HI_SHIFT)) & XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_HI_MASK)

#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_LO_SHIFT (8U)
/*! SEQ_BG_PUP_IBG_RX_TX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_RX (TX) */
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_LO_SHIFT)) & XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_TX_LO_MASK)

#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_HI_SHIFT (16U)
/*! SEQ_BG_PUP_IBG_RX_RX_HI - Assertion time setting for SEQ_BG_PUP_IBG_RX (RX) */
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_HI_SHIFT)) & XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_HI_MASK)

#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_LO_SHIFT (24U)
/*! SEQ_BG_PUP_IBG_RX_RX_LO - De-assertion time setting for SEQ_BG_PUP_IBG_RX (RX) */
#define XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_LO_SHIFT)) & XCVR_TSM_TIMING30_SEQ_BG_PUP_IBG_RX_RX_LO_MASK)
/*! @} */

/*! @name TIMING31 - TSM_TIMING31 */
/*! @{ */

#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_HI_SHIFT (0U)
/*! SEQ_TSM_ISO_B_2P4GHZ_TX_HI - Assertion time setting for SEQ_TSM_ISO_B_2P4GHZ (TX) */
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_HI_SHIFT)) & XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_HI_MASK)

#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_LO_SHIFT (8U)
/*! SEQ_TSM_ISO_B_2P4GHZ_TX_LO - De-assertion time setting for SEQ_TSM_ISO_B_2P4GHZ (TX) */
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_LO_SHIFT)) & XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_TX_LO_MASK)

#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_HI_SHIFT (16U)
/*! SEQ_TSM_ISO_B_2P4GHZ_RX_HI - Assertion time setting for SEQ_TSM_ISO_B_2P4GHZ (RX) */
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_HI_SHIFT)) & XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_HI_MASK)

#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_LO_SHIFT (24U)
/*! SEQ_TSM_ISO_B_2P4GHZ_RX_LO - De-assertion time setting for SEQ_TSM_ISO_B_2P4GHZ (RX) */
#define XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_LO_SHIFT)) & XCVR_TSM_TIMING31_SEQ_TSM_ISO_B_2P4GHZ_RX_LO_MASK)
/*! @} */

/*! @name TIMING32 - TSM_TIMING32 */
/*! @{ */

#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_HI_SHIFT (0U)
/*! SEQ_RCCAL_PUP_TX_HI - Assertion time setting for SEQ_RCCAL_PUP (TX) */
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_LO_SHIFT (8U)
/*! SEQ_RCCAL_PUP_TX_LO - De-assertion time setting for SEQ_RCCAL_PUP (TX) */
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_HI_SHIFT (16U)
/*! SEQ_RCCAL_PUP_RX_HI - Assertion time setting for SEQ_RCCAL_PUP (RX) */
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_LO_SHIFT (24U)
/*! SEQ_RCCAL_PUP_RX_LO - De-assertion time setting for SEQ_RCCAL_PUP (RX) */
#define XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING32_SEQ_RCCAL_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING33 - TSM_TIMING33 */
/*! @{ */

#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_HI_SHIFT (0U)
/*! SEQ_PD_EN_FCAL_BIAS_TX_HI - Assertion time setting for SEQ_PD_EN_FCAL_BIAS (TX) */
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_HI_SHIFT)) & XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_HI_MASK)

#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_LO_SHIFT (8U)
/*! SEQ_PD_EN_FCAL_BIAS_TX_LO - De-assertion time setting for SEQ_PD_EN_FCAL_BIAS (TX) */
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_LO_SHIFT)) & XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_TX_LO_MASK)

#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_HI_SHIFT (16U)
/*! SEQ_PD_EN_FCAL_BIAS_RX_HI - Assertion time setting for SEQ_PD_EN_FCAL_BIAS (RX) */
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_HI_SHIFT)) & XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_HI_MASK)

#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_LO_SHIFT (24U)
/*! SEQ_PD_EN_FCAL_BIAS_RX_LO - De-assertion time setting for SEQ_PD_EN_FCAL_BIAS (RX) */
#define XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_LO_SHIFT)) & XCVR_TSM_TIMING33_SEQ_PD_EN_FCAL_BIAS_RX_LO_MASK)
/*! @} */

/*! @name TIMING34 - TSM_TIMING34 */
/*! @{ */

#define XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_HI_SHIFT (0U)
/*! SEQ_PD_PUP_TX_HI - Assertion time setting for SEQ_PD_PUP (TX) */
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_LO_SHIFT (8U)
/*! SEQ_PD_PUP_TX_LO - De-assertion time setting for SEQ_PD_PUP (TX) */
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING34_SEQ_PD_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_HI_SHIFT (16U)
/*! SEQ_PD_PUP_RX_HI - Assertion time setting for SEQ_PD_PUP (RX) */
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_LO_SHIFT (24U)
/*! SEQ_PD_PUP_RX_LO - De-assertion time setting for SEQ_PD_PUP (RX) */
#define XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING34_SEQ_PD_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING35 - TSM_TIMING35 */
/*! @{ */

#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_HI_SHIFT (0U)
/*! SEQ_VCO_PUP_TX_HI - Assertion time setting for SEQ_VCO_PUP (TX) */
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_LO_SHIFT (8U)
/*! SEQ_VCO_PUP_TX_LO - De-assertion time setting for SEQ_VCO_PUP (TX) */
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING35_SEQ_VCO_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_HI_SHIFT (16U)
/*! SEQ_VCO_PUP_RX_HI - Assertion time setting for SEQ_VCO_PUP (RX) */
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_LO_SHIFT (24U)
/*! SEQ_VCO_PUP_RX_LO - De-assertion time setting for SEQ_VCO_PUP (RX) */
#define XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING35_SEQ_VCO_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING36 - TSM_TIMING36 */
/*! @{ */

#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_HI_SHIFT (0U)
/*! SEQ_XO_DIST_EN_TX_HI - Assertion time setting for SEQ_XO_DIST_EN (TX) */
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_LO_SHIFT (8U)
/*! SEQ_XO_DIST_EN_TX_LO - De-assertion time setting for SEQ_XO_DIST_EN (TX) */
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_HI_SHIFT (16U)
/*! SEQ_XO_DIST_EN_RX_HI - Assertion time setting for SEQ_XO_DIST_EN (RX) */
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_LO_SHIFT (24U)
/*! SEQ_XO_DIST_EN_RX_LO - De-assertion time setting for SEQ_XO_DIST_EN (RX) */
#define XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING36_SEQ_XO_DIST_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING37 - TSM_TIMING37 */
/*! @{ */

#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_HI_SHIFT (0U)
/*! SEQ_XO_DIST_EN_CLK_REF_TX_HI - Assertion time setting for SEQ_XO_DIST_EN_CLK_REF (TX) */
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_HI_SHIFT)) & XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_HI_MASK)

#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_LO_SHIFT (8U)
/*! SEQ_XO_DIST_EN_CLK_REF_TX_LO - De-assertion time setting for SEQ_XO_DIST_EN_CLK_REF (TX) */
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_LO_SHIFT)) & XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_TX_LO_MASK)

#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_HI_SHIFT (16U)
/*! SEQ_XO_DIST_EN_CLK_REF_RX_HI - Assertion time setting for SEQ_XO_DIST_EN_CLK_REF (RX) */
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_HI_SHIFT)) & XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_HI_MASK)

#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_LO_SHIFT (24U)
/*! SEQ_XO_DIST_EN_CLK_REF_RX_LO - De-assertion time setting for SEQ_XO_DIST_EN_CLK_REF (RX) */
#define XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_LO_SHIFT)) & XCVR_TSM_TIMING37_SEQ_XO_DIST_EN_CLK_REF_RX_LO_MASK)
/*! @} */

/*! @name TIMING38 - TSM_TIMING38 */
/*! @{ */

#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_HI_SHIFT (0U)
/*! SEQ_XO_EN_CLK_2P4G_TX_HI - Assertion time setting for SEQ_XO_EN_CLK_2P4G (TX) */
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_HI_SHIFT)) & XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_HI_MASK)

#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_LO_SHIFT (8U)
/*! SEQ_XO_EN_CLK_2P4G_TX_LO - De-assertion time setting for SEQ_XO_EN_CLK_2P4G (TX) */
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_LO_SHIFT)) & XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_TX_LO_MASK)

#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_HI_SHIFT (16U)
/*! SEQ_XO_EN_CLK_2P4G_RX_HI - Assertion time setting for SEQ_XO_EN_CLK_2P4G (RX) */
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_HI_SHIFT)) & XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_HI_MASK)

#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_LO_SHIFT (24U)
/*! SEQ_XO_EN_CLK_2P4G_RX_LO - De-assertion time setting for SEQ_XO_EN_CLK_2P4G (RX) */
#define XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_LO_SHIFT)) & XCVR_TSM_TIMING38_SEQ_XO_EN_CLK_2P4G_RX_LO_MASK)
/*! @} */

/*! @name TIMING39 - TSM_TIMING39 */
/*! @{ */

#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_HI_SHIFT (0U)
/*! SEQ_XO_DIST_EN_CLK_ADCDAC_TX_HI - Assertion time setting for SEQ_XO_DIST_EN_CLK_ADCDAC (TX) */
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_HI_SHIFT)) & XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_HI_MASK)

#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_LO_SHIFT (8U)
/*! SEQ_XO_DIST_EN_CLK_ADCDAC_TX_LO - De-assertion time setting for SEQ_XO_DIST_EN_CLK_ADCDAC (TX) */
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_LO_SHIFT)) & XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_TX_LO_MASK)

#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_HI_SHIFT (16U)
/*! SEQ_XO_DIST_EN_CLK_ADCDAC_RX_HI - Assertion time setting for SEQ_XO_DIST_EN_CLK_ADCDAC (RX) */
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_HI_SHIFT)) & XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_HI_MASK)

#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_LO_SHIFT (24U)
/*! SEQ_XO_DIST_EN_CLK_ADCDAC_RX_LO - De-assertion time setting for SEQ_XO_DIST_EN_CLK_ADCDAC (RX) */
#define XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_LO_SHIFT)) & XCVR_TSM_TIMING39_SEQ_XO_DIST_EN_CLK_ADCDAC_RX_LO_MASK)
/*! @} */

/*! @name TIMING40 - TSM_TIMING40 */
/*! @{ */

#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_HI_SHIFT (0U)
/*! SEQ_DAC_PUP_TX_HI - Assertion time setting for SEQ_DAC_PUP (TX) */
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_LO_SHIFT (8U)
/*! SEQ_DAC_PUP_TX_LO - De-assertion time setting for SEQ_DAC_PUP (TX) */
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING40_SEQ_DAC_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_HI_SHIFT (16U)
/*! SEQ_DAC_PUP_RX_HI - Assertion time setting for SEQ_DAC_PUP (RX) */
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_LO_SHIFT (24U)
/*! SEQ_DAC_PUP_RX_LO - De-assertion time setting for SEQ_DAC_PUP (RX) */
#define XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING40_SEQ_DAC_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING41 - TSM_TIMING41 */
/*! @{ */

#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_HI_SHIFT (0U)
/*! SEQ_VCO_EN_HPM_TX_HI - Assertion time setting for SEQ_VCO_EN_HPM (TX) */
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_HI_SHIFT)) & XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_HI_MASK)

#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_LO_SHIFT (8U)
/*! SEQ_VCO_EN_HPM_TX_LO - De-assertion time setting for SEQ_VCO_EN_HPM (TX) */
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_LO_SHIFT)) & XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_TX_LO_MASK)

#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_HI_SHIFT (16U)
/*! SEQ_VCO_EN_HPM_RX_HI - Assertion time setting for SEQ_VCO_EN_HPM (RX) */
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_HI_SHIFT)) & XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_HI_MASK)

#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_LO_SHIFT (24U)
/*! SEQ_VCO_EN_HPM_RX_LO - De-assertion time setting for SEQ_VCO_EN_HPM (RX) */
#define XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_LO_SHIFT)) & XCVR_TSM_TIMING41_SEQ_VCO_EN_HPM_RX_LO_MASK)
/*! @} */

/*! @name TIMING42 - TSM_TIMING42 */
/*! @{ */

#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_HI_SHIFT (0U)
/*! SEQ_LO_PUP_VLO_FBK_TX_HI - Assertion time setting for SEQ_LO_PUP_VLO_FBK (TX) */
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_HI_SHIFT)) & XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_HI_MASK)

#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_LO_SHIFT (8U)
/*! SEQ_LO_PUP_VLO_FBK_TX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_FBK (TX) */
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_LO_SHIFT)) & XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_TX_LO_MASK)

#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_HI_SHIFT (16U)
/*! SEQ_LO_PUP_VLO_FBK_RX_HI - Assertion time setting for SEQ_LO_PUP_VLO_FBK (RX) */
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_HI_SHIFT)) & XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_HI_MASK)

#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_LO_SHIFT (24U)
/*! SEQ_LO_PUP_VLO_FBK_RX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_FBK (RX) */
#define XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_LO_SHIFT)) & XCVR_TSM_TIMING42_SEQ_LO_PUP_VLO_FBK_RX_LO_MASK)
/*! @} */

/*! @name TIMING43 - TSM_TIMING43 */
/*! @{ */

#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_HI_SHIFT (0U)
/*! SEQ_LO_PUP_VLO_RX_TX_HI - Assertion time setting for SEQ_LO_PUP_VLO_RX (TX) */
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_HI_SHIFT)) & XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_HI_MASK)

#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_LO_SHIFT (8U)
/*! SEQ_LO_PUP_VLO_RX_TX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_RX (TX) */
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_LO_SHIFT)) & XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_TX_LO_MASK)

#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_HI_SHIFT (16U)
/*! SEQ_LO_PUP_VLO_RX_RX_HI - Assertion time setting for SEQ_LO_PUP_VLO_RX (RX) */
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_HI_SHIFT)) & XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_HI_MASK)

#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_LO_SHIFT (24U)
/*! SEQ_LO_PUP_VLO_RX_RX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_RX (RX) */
#define XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_LO_SHIFT)) & XCVR_TSM_TIMING43_SEQ_LO_PUP_VLO_RX_RX_LO_MASK)
/*! @} */

/*! @name TIMING44 - TSM_TIMING44 */
/*! @{ */

#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_HI_SHIFT (0U)
/*! SEQ_LO_PUP_VLO_RXDRV_TX_HI - Assertion time setting for SEQ_LO_PUP_VLO_RXDRV (TX) */
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_HI_SHIFT)) & XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_HI_MASK)

#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_LO_SHIFT (8U)
/*! SEQ_LO_PUP_VLO_RXDRV_TX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_RXDRV (TX) */
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_LO_SHIFT)) & XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_TX_LO_MASK)

#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_HI_SHIFT (16U)
/*! SEQ_LO_PUP_VLO_RXDRV_RX_HI - Assertion time setting for SEQ_LO_PUP_VLO_RXDRV (RX) */
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_HI_SHIFT)) & XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_HI_MASK)

#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_LO_SHIFT (24U)
/*! SEQ_LO_PUP_VLO_RXDRV_RX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_RXDRV (RX) */
#define XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_LO_SHIFT)) & XCVR_TSM_TIMING44_SEQ_LO_PUP_VLO_RXDRV_RX_LO_MASK)
/*! @} */

/*! @name TIMING45 - TSM_TIMING45 */
/*! @{ */

#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_HI_SHIFT (0U)
/*! SEQ_LO_PUP_VLO_TX_TX_HI - Assertion time setting for SEQ_LO_PUP_VLO_TX (TX) */
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_HI_SHIFT)) & XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_HI_MASK)

#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_LO_SHIFT (8U)
/*! SEQ_LO_PUP_VLO_TX_TX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_TX (TX) */
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_LO_SHIFT)) & XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_TX_LO_MASK)

#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_HI_SHIFT (16U)
/*! SEQ_LO_PUP_VLO_TX_RX_HI - Assertion time setting for SEQ_LO_PUP_VLO_TX (RX) */
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_HI_SHIFT)) & XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_HI_MASK)

#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_LO_SHIFT (24U)
/*! SEQ_LO_PUP_VLO_TX_RX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_TX (RX) */
#define XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_LO_SHIFT)) & XCVR_TSM_TIMING45_SEQ_LO_PUP_VLO_TX_RX_LO_MASK)
/*! @} */

/*! @name TIMING46 - TSM_TIMING46 */
/*! @{ */

#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_HI_SHIFT (0U)
/*! SEQ_LO_PUP_VLO_TXDRV_TX_HI - Assertion time setting for SEQ_LO_PUP_VLO_TXDRV (TX) */
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_HI_SHIFT)) & XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_HI_MASK)

#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_LO_SHIFT (8U)
/*! SEQ_LO_PUP_VLO_TXDRV_TX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_TXDRV (TX) */
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_LO_SHIFT)) & XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_TX_LO_MASK)

#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_HI_SHIFT (16U)
/*! SEQ_LO_PUP_VLO_TXDRV_RX_HI - Assertion time setting for SEQ_LO_PUP_VLO_TXDRV (RX) */
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_HI_SHIFT)) & XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_HI_MASK)

#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_LO_SHIFT (24U)
/*! SEQ_LO_PUP_VLO_TXDRV_RX_LO - De-assertion time setting for SEQ_LO_PUP_VLO_TXDRV (RX) */
#define XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_LO_SHIFT)) & XCVR_TSM_TIMING46_SEQ_LO_PUP_VLO_TXDRV_RX_LO_MASK)
/*! @} */

/*! @name TIMING47 - TSM_TIMING47 */
/*! @{ */

#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_HI_SHIFT (0U)
/*! SEQ_DIVN_PUP_TX_HI - Assertion time setting for SEQ_DIVN_PUP (TX) */
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_HI(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_LO_SHIFT (8U)
/*! SEQ_DIVN_PUP_TX_LO - De-assertion time setting for SEQ_DIVN_PUP (TX) */
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_LO(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING47_SEQ_DIVN_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_HI_SHIFT (16U)
/*! SEQ_DIVN_PUP_RX_HI - Assertion time setting for SEQ_DIVN_PUP (RX) */
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_HI(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_LO_SHIFT (24U)
/*! SEQ_DIVN_PUP_RX_LO - De-assertion time setting for SEQ_DIVN_PUP (RX) */
#define XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_LO(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING47_SEQ_DIVN_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING48 - TSM_TIMING48 */
/*! @{ */

#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_HI_SHIFT (0U)
/*! SEQ_DIVN_CLOSEDLOOP_TX_HI - Assertion time setting for SEQ_DIVN_CLOSEDLOOP (TX) */
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_HI_SHIFT)) & XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_HI_MASK)

#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_LO_SHIFT (8U)
/*! SEQ_DIVN_CLOSEDLOOP_TX_LO - De-assertion time setting for SEQ_DIVN_CLOSEDLOOP (TX) */
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_LO_SHIFT)) & XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_TX_LO_MASK)

#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_HI_SHIFT (16U)
/*! SEQ_DIVN_CLOSEDLOOP_RX_HI - Assertion time setting for SEQ_DIVN_CLOSEDLOOP (RX) */
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_HI_SHIFT)) & XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_HI_MASK)

#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_LO_SHIFT (24U)
/*! SEQ_DIVN_CLOSEDLOOP_RX_LO - De-assertion time setting for SEQ_DIVN_CLOSEDLOOP (RX) */
#define XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_LO_SHIFT)) & XCVR_TSM_TIMING48_SEQ_DIVN_CLOSEDLOOP_RX_LO_MASK)
/*! @} */

/*! @name TIMING49 - TSM_TIMING49 */
/*! @{ */

#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_HI_SHIFT (0U)
/*! SEQ_PD_EN_PD_DRV_TX_HI - Assertion time setting for SEQ_PD_EN_PD_DRV (TX) */
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_HI_SHIFT)) & XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_HI_MASK)

#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_LO_SHIFT (8U)
/*! SEQ_PD_EN_PD_DRV_TX_LO - De-assertion time setting for SEQ_PD_EN_PD_DRV (TX) */
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_LO_SHIFT)) & XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_TX_LO_MASK)

#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_HI_SHIFT (16U)
/*! SEQ_PD_EN_PD_DRV_RX_HI - Assertion time setting for SEQ_PD_EN_PD_DRV (RX) */
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_HI_SHIFT)) & XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_HI_MASK)

#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_LO_SHIFT (24U)
/*! SEQ_PD_EN_PD_DRV_RX_LO - De-assertion time setting for SEQ_PD_EN_PD_DRV (RX) */
#define XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_LO_SHIFT)) & XCVR_TSM_TIMING49_SEQ_PD_EN_PD_DRV_RX_LO_MASK)
/*! @} */

/*! @name TIMING50 - TSM_TIMING50 */
/*! @{ */

#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_HI_SHIFT (0U)
/*! SEQ_CBPF_EN_DCOC_TX_HI - Assertion time setting for SEQ_CBPF_EN_DCOC (TX) */
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_HI_SHIFT)) & XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_HI_MASK)

#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_LO_SHIFT (8U)
/*! SEQ_CBPF_EN_DCOC_TX_LO - De-assertion time setting for SEQ_CBPF_EN_DCOC (TX) */
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_LO_SHIFT)) & XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_TX_LO_MASK)

#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_HI_SHIFT (16U)
/*! SEQ_CBPF_EN_DCOC_RX_HI - Assertion time setting for SEQ_CBPF_EN_DCOC (RX) */
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_HI_SHIFT)) & XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_HI_MASK)

#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_LO_SHIFT (24U)
/*! SEQ_CBPF_EN_DCOC_RX_LO - De-assertion time setting for SEQ_CBPF_EN_DCOC (RX) */
#define XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_LO_SHIFT)) & XCVR_TSM_TIMING50_SEQ_CBPF_EN_DCOC_RX_LO_MASK)
/*! @} */

/*! @name TIMING51 - TSM_TIMING51 */
/*! @{ */

#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_HI_SHIFT (0U)
/*! SEQ_RX_GANG_PUP_TX_HI - Assertion time setting for SEQ_(RX_LAN/RX_MIX/CBPF/ADC_PUP) and SEQ_SPARE1 (TX) */
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_HI_SHIFT)) & XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_HI_MASK)

#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_LO_SHIFT (8U)
/*! SEQ_RX_GANG_PUP_TX_LO - De-assertion time setting for SEQ_(RX_LAN/RX_MIX/CBPF/ADC_PUP) and SEQ_SPARE1 (TX) */
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_LO_SHIFT)) & XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_TX_LO_MASK)

#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_HI_SHIFT (16U)
/*! SEQ_RX_GANG_PUP_RX_HI - Assertion time setting for SEQ_(RX_LAN/RX_MIX/CBPF/ADC_PUP) and SEQ_SPARE1 (RX) */
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_HI_SHIFT)) & XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_HI_MASK)

#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_LO_SHIFT (24U)
/*! SEQ_RX_GANG_PUP_RX_LO - De-assertion time setting for SEQ_(RX_LAN/RX_MIX/CBPF/ADC_PUP) and SEQ_SPARE1 (RX) */
#define XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_LO_SHIFT)) & XCVR_TSM_TIMING51_SEQ_RX_GANG_PUP_RX_LO_MASK)
/*! @} */

/*! @name TIMING52 - TSM_TIMING52 */
/*! @{ */

#define XCVR_TSM_TIMING52_SEQ_SPARE3_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING52_SEQ_SPARE3_TX_HI_SHIFT (0U)
/*! SEQ_SPARE3_TX_HI - Assertion time setting for SEQ_SPARE3 (TX) */
#define XCVR_TSM_TIMING52_SEQ_SPARE3_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING52_SEQ_SPARE3_TX_HI_SHIFT)) & XCVR_TSM_TIMING52_SEQ_SPARE3_TX_HI_MASK)

#define XCVR_TSM_TIMING52_SEQ_SPARE3_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING52_SEQ_SPARE3_TX_LO_SHIFT (8U)
/*! SEQ_SPARE3_TX_LO - De-assertion time setting for SEQ_SPARE3 (TX) */
#define XCVR_TSM_TIMING52_SEQ_SPARE3_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING52_SEQ_SPARE3_TX_LO_SHIFT)) & XCVR_TSM_TIMING52_SEQ_SPARE3_TX_LO_MASK)

#define XCVR_TSM_TIMING52_SEQ_SPARE3_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING52_SEQ_SPARE3_RX_HI_SHIFT (16U)
/*! SEQ_SPARE3_RX_HI - Assertion time setting for SEQ_SPARE3 (RX) */
#define XCVR_TSM_TIMING52_SEQ_SPARE3_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING52_SEQ_SPARE3_RX_HI_SHIFT)) & XCVR_TSM_TIMING52_SEQ_SPARE3_RX_HI_MASK)

#define XCVR_TSM_TIMING52_SEQ_SPARE3_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING52_SEQ_SPARE3_RX_LO_SHIFT (24U)
/*! SEQ_SPARE3_RX_LO - De-assertion time setting for SEQ_SPARE3 (RX) */
#define XCVR_TSM_TIMING52_SEQ_SPARE3_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING52_SEQ_SPARE3_RX_LO_SHIFT)) & XCVR_TSM_TIMING52_SEQ_SPARE3_RX_LO_MASK)
/*! @} */

/*! @name TIMING53 - TSM TIMING_53 */
/*! @{ */

#define XCVR_TSM_TIMING53_GEAR_SHIFT_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING53_GEAR_SHIFT_TX_HI_SHIFT (0U)
/*! GEAR_SHIFT_TX_HI - Assertion time setting for GEAR_SHIFT (TX) */
#define XCVR_TSM_TIMING53_GEAR_SHIFT_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING53_GEAR_SHIFT_TX_HI_SHIFT)) & XCVR_TSM_TIMING53_GEAR_SHIFT_TX_HI_MASK)

#define XCVR_TSM_TIMING53_GEAR_SHIFT_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING53_GEAR_SHIFT_TX_LO_SHIFT (8U)
/*! GEAR_SHIFT_TX_LO - De-assertion time setting for GEAR_SHIFT (TX) */
#define XCVR_TSM_TIMING53_GEAR_SHIFT_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING53_GEAR_SHIFT_TX_LO_SHIFT)) & XCVR_TSM_TIMING53_GEAR_SHIFT_TX_LO_MASK)

#define XCVR_TSM_TIMING53_GEAR_SHIFT_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING53_GEAR_SHIFT_RX_HI_SHIFT (16U)
/*! GEAR_SHIFT_RX_HI - Assertion time setting for GEAR_SHIFT (RX) */
#define XCVR_TSM_TIMING53_GEAR_SHIFT_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING53_GEAR_SHIFT_RX_HI_SHIFT)) & XCVR_TSM_TIMING53_GEAR_SHIFT_RX_HI_MASK)

#define XCVR_TSM_TIMING53_GEAR_SHIFT_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING53_GEAR_SHIFT_RX_LO_SHIFT (24U)
/*! GEAR_SHIFT_RX_LO - De-assertion time setting for GEAR_SHIFT (RX) */
#define XCVR_TSM_TIMING53_GEAR_SHIFT_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING53_GEAR_SHIFT_RX_LO_SHIFT)) & XCVR_TSM_TIMING53_GEAR_SHIFT_RX_LO_MASK)
/*! @} */

/*! @name TIMING54 - TSM TIMING_54 */
/*! @{ */

#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_HI_SHIFT (0U)
/*! SEQ_PIC_CORE_EN_TX_HI - Assertion time setting for SEQ_PIC_CORE_EN (TX) */
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_LO_SHIFT (8U)
/*! SEQ_PIC_CORE_EN_TX_LO - De-assertion time setting for SEQ_PIC_CORE_EN (TX) */
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_HI_SHIFT (16U)
/*! SEQ_PIC_CORE_EN_RX_HI - Assertion time setting for SEQ_PIC_CORE_EN (RX) */
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_LO_SHIFT (24U)
/*! SEQ_PIC_CORE_EN_RX_LO - De-assertion time setting for SEQ_PIC_CORE_EN (RX) */
#define XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING54_SEQ_PIC_CORE_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING55 - TSM TIMING_55 */
/*! @{ */

#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_HI_SHIFT (0U)
/*! SEQ_PIC_SHORT_CINT_SHORT_EN_TX_HI - Assertion time setting for SEQ_PIC_SHORT_CINT_SHORT_EN (TX) */
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_LO_SHIFT (8U)
/*! SEQ_PIC_SHORT_CINT_SHORT_EN_TX_LO - De-assertion time setting for SEQ_PIC_SHORT_CINT_SHORT_EN (TX) */
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_HI_SHIFT (16U)
/*! SEQ_PIC_SHORT_CINT_SHORT_EN_RX_HI - Assertion time setting for SEQ_PIC_SHORT_CINT_SHORT_EN (RX) */
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_LO_SHIFT (24U)
/*! SEQ_PIC_SHORT_CINT_SHORT_EN_RX_LO - De-assertion time setting for SEQ_PIC_SHORT_CINT_SHORT_EN (RX) */
#define XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING55_SEQ_PIC_SHORT_CINT_SHORT_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING56 - TSM TIMING_56 */
/*! @{ */

#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_HI_SHIFT (0U)
/*! SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_HI - Assertion time setting for SEQ_PIC_FILTER_LOW_BW_SM_EN (TX) */
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_LO_SHIFT (8U)
/*! SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_LO - De-assertion time setting for SEQ_PIC_FILTER_LOW_BW_SM_EN (TX) */
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_HI_SHIFT (16U)
/*! SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_HI - Assertion time setting for SEQ_PIC_FILTER_LOW_BW_SM_EN (RX) */
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_LO_SHIFT (24U)
/*! SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_LO - De-assertion time setting for SEQ_PIC_FILTER_LOW_BW_SM_EN (RX) */
#define XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING56_SEQ_PIC_FILTER_LOW_BW_SM_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING57 - TSM TIMING_57 */
/*! @{ */

#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_HI_SHIFT (0U)
/*! SEQ_PIC_RFB_OPEN_SM_EN_TX_HI - Assertion time setting for SEQ_PIC_RFB_OPEN_SM_EN (TX) */
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_LO_SHIFT (8U)
/*! SEQ_PIC_RFB_OPEN_SM_EN_TX_LO - De-assertion time setting for SEQ_PIC_RFB_OPEN_SM_EN (TX) */
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_HI_SHIFT (16U)
/*! SEQ_PIC_RFB_OPEN_SM_EN_RX_HI - Assertion time setting for SEQ_PIC_RFB_OPEN_SM_EN (RX) */
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_LO_SHIFT (24U)
/*! SEQ_PIC_RFB_OPEN_SM_EN_RX_LO - De-assertion time setting for SEQ_PIC_RFB_OPEN_SM_EN (RX) */
#define XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING57_SEQ_PIC_RFB_OPEN_SM_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING58 - TSM TIMING_58 */
/*! @{ */

#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_HI_SHIFT (0U)
/*! SEQ_PIC_RINT2_SHORT_FM_EN_TX_HI - Assertion time setting for SEQ_PIC_RINT2_SHORT_FM_EN (TX) */
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_LO_SHIFT (8U)
/*! SEQ_PIC_RINT2_SHORT_FM_EN_TX_LO - De-assertion time setting for SEQ_PIC_RINT2_SHORT_FM_EN (TX) */
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_HI_SHIFT (16U)
/*! SEQ_PIC_RINT2_SHORT_FM_EN_RX_HI - Assertion time setting for SEQ_PIC_RINT2_SHORT_FM_EN (RX) */
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_LO_SHIFT (24U)
/*! SEQ_PIC_RINT2_SHORT_FM_EN_RX_LO - De-assertion time setting for SEQ_PIC_RINT2_SHORT_FM_EN (RX) */
#define XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING58_SEQ_PIC_RINT2_SHORT_FM_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING59 - TSM TIMING_59 */
/*! @{ */

#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_HI_SHIFT (0U)
/*! SEQ_LODIV_SYNC_RESET_EN_TX_HI - Assertion time setting for SEQ_LODIV_SYNC_RESET_EN (TX) */
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_LO_SHIFT (8U)
/*! SEQ_LODIV_SYNC_RESET_EN_TX_LO - De-assertion time setting for SEQ_LODIV_SYNC_RESET_EN (TX) */
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_HI_SHIFT (16U)
/*! SEQ_LODIV_SYNC_RESET_EN_RX_HI - Assertion time setting for SEQ_LODIV_SYNC_RESET_EN (RX) */
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_LO_SHIFT (24U)
/*! SEQ_LODIV_SYNC_RESET_EN_RX_LO - De-assertion time setting for SEQ_LODIV_SYNC_RESET_EN (RX) */
#define XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING59_SEQ_LODIV_SYNC_RESET_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING60 - TSM TIMING_60 */
/*! @{ */

#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_HI_SHIFT (0U)
/*! SEQ_LODIV_SYNC_EN_TX_HI - Assertion time setting for SEQ_LODIV_SYNC_EN (TX) */
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_LO_SHIFT (8U)
/*! SEQ_LODIV_SYNC_EN_TX_LO - De-assertion time setting for SEQ_LODIV_SYNC_EN (TX) */
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_HI_SHIFT (16U)
/*! SEQ_LODIV_SYNC_EN_RX_HI - Assertion time setting for SEQ_LODIV_SYNC_EN (RX) */
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_LO_SHIFT (24U)
/*! SEQ_LODIV_SYNC_EN_RX_LO - De-assertion time setting for SEQ_LODIV_SYNC_EN (RX) */
#define XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING60_SEQ_LODIV_SYNC_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING61 - TSM TIMING_61 */
/*! @{ */

#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_HI_SHIFT (0U)
/*! SEQ_LODIV_SYNC_SPARE_EN_TX_HI - Assertion time setting for SEQ_LODIV_SYNC_SPARE_EN (TX) */
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_LO_SHIFT (8U)
/*! SEQ_LODIV_SYNC_SPARE_EN_TX_LO - De-assertion time setting for SEQ_LODIV_SYNC_SPARE_EN (TX) */
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_HI_SHIFT (16U)
/*! SEQ_LODIV_SYNC_SPARE_EN_RX_HI - Assertion time setting for SEQ_LODIV_SYNC_SPARE_EN (RX) */
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_LO_SHIFT (24U)
/*! SEQ_LODIV_SYNC_SPARE_EN_RX_LO - De-assertion time setting for SEQ_LODIV_SYNC_SPARE_EN (RX) */
#define XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING61_SEQ_LODIV_SYNC_SPARE_EN_RX_LO_MASK)
/*! @} */

/*! @name OVRD0 - TSM OVERRIDE REGISTER 0 */
/*! @{ */

#define XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_EN_SHIFT (0U)
/*! TSM_RF_ACTIVE_OVRD_EN - Override control for TSM_RF_ACTIVE
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_RF_ACTIVE_OVRD to override the signal "tsm_rf_active".
 */
#define XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_MASK   (0x2U)
#define XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_SHIFT  (1U)
/*! TSM_RF_ACTIVE_OVRD - Override value for TSM_RF_ACTIVE */
#define XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_SHIFT)) & XCVR_TSM_OVRD0_TSM_RF_ACTIVE_OVRD_MASK)

#define XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_EN_SHIFT (2U)
/*! TSM_RF_STATUS_OVRD_EN - Override control for TSM_RF_STATUS
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_RF_STATUS_OVRD to override the signal "tsm_rf_status".
 */
#define XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_MASK   (0x8U)
#define XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_SHIFT  (3U)
/*! TSM_RF_STATUS_OVRD - Override value for TSM_RF_STATUS */
#define XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_SHIFT)) & XCVR_TSM_OVRD0_TSM_RF_STATUS_OVRD_MASK)

#define XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_EN_MASK (0x10U)
#define XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_EN_SHIFT (4U)
/*! TSM_RF_PRIORITY_OVRD_EN - Override control for TSM_RF_PRIORITY
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_RF_PRIORITY_OVRD to override the signal "tsm_rf_priority".
 */
#define XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_MASK (0x20U)
#define XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_SHIFT (5U)
/*! TSM_RF_PRIORITY_OVRD - Override value for TSM_RF_PRIORITY */
#define XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_SHIFT)) & XCVR_TSM_OVRD0_TSM_RF_PRIORITY_OVRD_MASK)

#define XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_EN_SHIFT (6U)
/*! TSM_IRQ0_START_TRIG_OVRD_EN - Override control for TSM_IRQ0_START_TRIG
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_IRQ0_START_TRIG_OVRD to override the signal "tsm_irq0_start_trig".
 */
#define XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_MASK (0x80U)
#define XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_SHIFT (7U)
/*! TSM_IRQ0_START_TRIG_OVRD - Override value for TSM_IRQ0_START_TRIG */
#define XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_SHIFT)) & XCVR_TSM_OVRD0_TSM_IRQ0_START_TRIG_OVRD_MASK)

#define XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_EN_MASK (0x100U)
#define XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_EN_SHIFT (8U)
/*! TSM_IRQ1_STOP_TRIG_OVRD_EN - Override control for TSM_IRQ1_STOP_TRIG
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_IRQ1_STOP_TRIG_OVRD to override the signal "tsm_irq1_stop_trig".
 */
#define XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_MASK (0x200U)
#define XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_SHIFT (9U)
/*! TSM_IRQ1_STOP_TRIG_OVRD - Override value for TSM_IRQ1_STOP_TRIG */
#define XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_SHIFT)) & XCVR_TSM_OVRD0_TSM_IRQ1_STOP_TRIG_OVRD_MASK)

#define XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_EN_SHIFT (10U)
/*! DCOC_GAIN_CFG_EN_OVRD_EN - Override control for DCOC_GAIN_CFG_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of DCOC_GAIN_CFG_EN_OVRD to override the signal "dcoc_gain_cfg_en".
 */
#define XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_MASK (0x800U)
#define XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_SHIFT (11U)
/*! DCOC_GAIN_CFG_EN_OVRD - Override value for DCOC_GAIN_CFG_EN */
#define XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_DCOC_GAIN_CFG_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_EN_MASK   (0x1000U)
#define XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_EN_SHIFT  (12U)
/*! LDO_CAL_EN_OVRD_EN - Override control for LDO_CAL_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of LDO_CAL_EN_OVRD to override the signal "ldo_cal_en".
 */
#define XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_MASK      (0x2000U)
#define XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_SHIFT     (13U)
/*! LDO_CAL_EN_OVRD - Override value for LDO_CAL_EN */
#define XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_LDO_CAL_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_EN_MASK   (0x4000U)
#define XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_EN_SHIFT  (14U)
/*! PLL_DIG_EN_OVRD_EN - Override control for PLL_DIG_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of PLL_DIG_EN_OVRD to override the signal "pll_dig_en".
 */
#define XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_MASK      (0x8000U)
#define XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_SHIFT     (15U)
/*! PLL_DIG_EN_OVRD - Override value for PLL_DIG_EN */
#define XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_PLL_DIG_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_EN_MASK (0x10000U)
#define XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_EN_SHIFT (16U)
/*! SIGMA_DELTA_EN_OVRD_EN - Override control for SIGMA_DELTA_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SIGMA_DELTA_EN_OVRD to override the signal "sigma_delta_en".
 */
#define XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_MASK  (0x20000U)
#define XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_SHIFT (17U)
/*! SIGMA_DELTA_EN_OVRD - Override value for SIGMA_DELTA_EN */
#define XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_SIGMA_DELTA_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_EN_MASK  (0x40000U)
#define XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_EN_SHIFT (18U)
/*! DCOC_CAL_EN_OVRD_EN - Override control for DCOC_CAL_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of DCOC_CAL_EN_OVRD to override the signal "dcoc_cal_en".
 */
#define XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_MASK     (0x80000U)
#define XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_SHIFT    (19U)
/*! DCOC_CAL_EN_OVRD - Override value for DCOC_CAL_EN */
#define XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_DCOC_CAL_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_EN_MASK    (0x100000U)
#define XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_EN_SHIFT   (20U)
/*! TX_DIG_EN_OVRD_EN - Override control for TX_DIG_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TX_DIG_EN_OVRD to override the signal "tx_dig_en".
 */
#define XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_MASK       (0x200000U)
#define XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_SHIFT      (21U)
/*! TX_DIG_EN_OVRD - Override value for TX_DIG_EN */
#define XCVR_TSM_OVRD0_TX_DIG_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_TX_DIG_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_EN_MASK (0x400000U)
#define XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_EN_SHIFT (22U)
/*! FREQ_TARG_LD_EN_OVRD_EN - Override control for FREQ_TARG_LD_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of FREQ_TARG_LD_EN_OVRD to override the signal "freq_targ_ld_en".
 */
#define XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_MASK (0x800000U)
#define XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_SHIFT (23U)
/*! FREQ_TARG_LD_EN_OVRD - Override value for FREQ_TARG_LD_EN */
#define XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_FREQ_TARG_LD_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_EN_MASK   (0x1000000U)
#define XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_EN_SHIFT  (24U)
/*! RX_INIT_EN_OVRD_EN - Override control for RX_INIT_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_INIT_EN_OVRD to override the signal "rx_init_en".
 */
#define XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_MASK      (0x2000000U)
#define XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_SHIFT     (25U)
/*! RX_INIT_EN_OVRD - Override value for RX_INIT_EN */
#define XCVR_TSM_OVRD0_RX_INIT_EN_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_RX_INIT_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_EN_MASK    (0x4000000U)
#define XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_EN_SHIFT   (26U)
/*! RX_DIG_EN_OVRD_EN - Override control for RX_DIG_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_DIG_EN_OVRD to override the signal "rx_dig_en".
 */
#define XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_MASK       (0x8000000U)
#define XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_SHIFT      (27U)
/*! RX_DIG_EN_OVRD - Override value for RX_DIG_EN */
#define XCVR_TSM_OVRD0_RX_DIG_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_RX_DIG_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_EN_MASK    (0x10000000U)
#define XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_EN_SHIFT   (28U)
/*! RX_PHY_EN_OVRD_EN - Override control for RX_PHY_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_PHY_EN_OVRD to override the signal "rx_phy_en".
 */
#define XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_MASK       (0x20000000U)
#define XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_SHIFT      (29U)
/*! RX_PHY_EN_OVRD - Override value for RX_PHY_EN */
#define XCVR_TSM_OVRD0_RX_PHY_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_RX_PHY_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_EN_MASK (0x40000000U)
#define XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_EN_SHIFT (30U)
/*! SEQ_BG_PUP_IBG_CAL_OVRD_EN - Override control for SEQ_BG_PUP_IBG_CAL
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_BG_PUP_IBG_CAL_OVRD to override the signal "seq_bg_pup_ibg_cal".
 */
#define XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_MASK (0x80000000U)
#define XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_SHIFT (31U)
/*! SEQ_BG_PUP_IBG_CAL_OVRD - Override value for SEQ_BG_PUP_IBG_CAL */
#define XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_SHIFT)) & XCVR_TSM_OVRD0_SEQ_BG_PUP_IBG_CAL_OVRD_MASK)
/*! @} */

/*! @name OVRD1 - TSM OVERRIDE REGISTER 1 */
/*! @{ */

#define XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_EN_SHIFT (0U)
/*! SEQ_LDOTRIM_PUP_OVRD_EN - Override control for SEQ_LDOTRIM_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDOTRIM_PUP_OVRD to override the signal "seq_ldotrim_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_MASK (0x2U)
#define XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_SHIFT (1U)
/*! SEQ_LDOTRIM_PUP_OVRD - Override value for SEQ_LDOTRIM_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDOTRIM_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_EN_SHIFT (2U)
/*! SEQ_LDO_CAL_PUP_OVRD_EN - Override control for SEQ_LDO_CAL_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_CAL_PUP_OVRD to override the signal "seq_ldo_cal_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_MASK (0x8U)
#define XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_SHIFT (3U)
/*! SEQ_LDO_CAL_PUP_OVRD - Override value for SEQ_LDO_CAL_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_CAL_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_EN_MASK    (0x10U)
#define XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_EN_SHIFT   (4U)
/*! SEQ_BG_FC_OVRD_EN - Override control for SEQ_BG_FC
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_BG_FC_OVRD to override the signal "seq_bg_fc".
 */
#define XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_MASK       (0x20U)
#define XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_SHIFT      (5U)
/*! SEQ_BG_FC_OVRD - Override value for SEQ_BG_FC */
#define XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_BG_FC_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_EN_SHIFT (6U)
/*! SEQ_LDO_PLL_FC_OVRD_EN - Override control for SEQ_LDO_PLL_FC
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_PLL_FC_OVRD to override the signal "seq_ldo_pll_fc".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_MASK  (0x80U)
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_SHIFT (7U)
/*! SEQ_LDO_PLL_FC_OVRD - Override value for SEQ_LDO_PLL_FC */
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_PLL_FC_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_EN_MASK (0x100U)
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_EN_SHIFT (8U)
/*! SEQ_LDO_VCO_FC_OVRD_EN - Override control for SEQ_LDO_VCO_FC
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_VCO_FC_OVRD to override the signal "seq_ldo_vco_fc".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_MASK  (0x200U)
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_SHIFT (9U)
/*! SEQ_LDO_VCO_FC_OVRD - Override value for SEQ_LDO_VCO_FC */
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_VCO_FC_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_EN_SHIFT (10U)
/*! SEQ_LDO_RXTXHF_FC_OVRD_EN - Override control for SEQ_LDO_RXTXHF_FC
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_RXTXHF_FC_OVRD to override the signal "seq_ldo_rxtxhf_fc".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_MASK (0x800U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_SHIFT (11U)
/*! SEQ_LDO_RXTXHF_FC_OVRD - Override value for SEQ_LDO_RXTXHF_FC */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_FC_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_EN_MASK (0x1000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_EN_SHIFT (12U)
/*! SEQ_LDO_RXTXLF_FC_OVRD_EN - Override control for SEQ_LDO_RXTXLF_FC
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_RXTXLF_FC_OVRD to override the signal "seq_ldo_rxtxlf_fc".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_MASK (0x2000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_SHIFT (13U)
/*! SEQ_LDO_RXTXLF_FC_OVRD - Override value for SEQ_LDO_RXTXLF_FC */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_FC_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_EN_MASK (0x4000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_EN_SHIFT (14U)
/*! SEQ_LDO_ANT_PUP_OVRD_EN - Override control for SEQ_LDO_ANT_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_ANT_PUP_OVRD to override the signal "seq_ldo_ant_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_MASK (0x8000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_SHIFT (15U)
/*! SEQ_LDO_ANT_PUP_OVRD - Override value for SEQ_LDO_ANT_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_ANT_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_EN_MASK (0x10000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_EN_SHIFT (16U)
/*! SEQ_LDO_PLL_PUP_OVRD_EN - Override control for SEQ_LDO_PLL_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_PLL_PUP_OVRD to override the signal "seq_ldo_pll_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_MASK (0x20000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_SHIFT (17U)
/*! SEQ_LDO_PLL_PUP_OVRD - Override value for SEQ_LDO_PLL_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_PLL_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_EN_MASK (0x40000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_EN_SHIFT (18U)
/*! SEQ_LDO_VCO_PUP_OVRD_EN - Override control for SEQ_LDO_VCO_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_VCO_PUP_OVRD to override the signal "seq_ldo_vco_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_MASK (0x80000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_SHIFT (19U)
/*! SEQ_LDO_VCO_PUP_OVRD - Override value for SEQ_LDO_VCO_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_VCO_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_EN_MASK (0x100000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_EN_SHIFT (20U)
/*! SEQ_LDO_XO_DIST_PUP_OVRD_EN - Override control for SEQ_LDO_XO_DIST_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_XO_DIST_PUP_OVRD to override the signal "seq_ldo_xo_dist_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_MASK (0x200000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_SHIFT (21U)
/*! SEQ_LDO_XO_DIST_PUP_OVRD - Override value for SEQ_LDO_XO_DIST_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_XO_DIST_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_EN_MASK (0x400000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_EN_SHIFT (22U)
/*! SEQ_LDO_RXTXHF_PUP_OVRD_EN - Override control for SEQ_LDO_RXTXHF_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_RXTXHF_PUP_OVRD to override the signal "seq_ldo_rxtxhf_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_MASK (0x800000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_SHIFT (23U)
/*! SEQ_LDO_RXTXHF_PUP_OVRD - Override value for SEQ_LDO_RXTXHF_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXHF_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_EN_MASK (0x1000000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_EN_SHIFT (24U)
/*! SEQ_LDO_RXTXLF_PUP_OVRD_EN - Override control for SEQ_LDO_RXTXLF_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_RXTXLF_PUP_OVRD to override the signal "seq_ldo_rxtxlf_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_MASK (0x2000000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_SHIFT (25U)
/*! SEQ_LDO_RXTXLF_PUP_OVRD - Override value for SEQ_LDO_RXTXLF_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_RXTXLF_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_EN_MASK (0x4000000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_EN_SHIFT (26U)
/*! SEQ_LDO_LV_PUP_OVRD_EN - Override control for SEQ_LDO_LV_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LDO_LV_PUP_OVRD to override the signal "seq_ldo_lv_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_MASK  (0x8000000U)
#define XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_SHIFT (27U)
/*! SEQ_LDO_LV_PUP_OVRD - Override value for SEQ_LDO_LV_PUP */
#define XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_LDO_LV_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_EN_MASK   (0x10000000U)
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_EN_SHIFT  (28U)
/*! SEQ_BG_PUP_OVRD_EN - Override control for SEQ_BG_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_BG_PUP_OVRD to override the signal "seq_bg_pup".
 */
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_MASK      (0x20000000U)
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_SHIFT     (29U)
/*! SEQ_BG_PUP_OVRD - Override value for SEQ_BG_PUP */
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_BG_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_EN_MASK (0x40000000U)
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_EN_SHIFT (30U)
/*! SEQ_BG_PUP_IBG_ANT_OVRD_EN - Override control for SEQ_BG_PUP_IBG_ANT
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_BG_PUP_IBG_ANT_OVRD to override the signal "seq_bg_pup_ibg_ant".
 */
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_MASK (0x80000000U)
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_SHIFT (31U)
/*! SEQ_BG_PUP_IBG_ANT_OVRD - Override value for SEQ_BG_PUP_IBG_ANT */
#define XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SEQ_BG_PUP_IBG_ANT_OVRD_MASK)
/*! @} */

/*! @name OVRD2 - TSM OVERRIDE REGISTER 2 */
/*! @{ */

#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_EN_SHIFT (0U)
/*! SEQ_BG_PUP_IBG_XO_DIST_OVRD_EN - Override control for SEQ_BG_PUP_IBG_XO_DIST
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_BG_PUP_IBG_XO_DIST_OVRD to override the signal "seq_bg_pup_ibg_xo_dist".
 */
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_MASK (0x2U)
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_SHIFT (1U)
/*! SEQ_BG_PUP_IBG_XO_DIST_OVRD - Override value for SEQ_BG_PUP_IBG_XO_DIST */
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_XO_DIST_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_EN_SHIFT (2U)
/*! SEQ_BG_PUP_IBG_TX_OVRD_EN - Override control for SEQ_BG_PUP_IBG_TX
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_BG_PUP_IBG_TX_OVRD to override the signal "seq_bg_pup_ibg_tx".
 */
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_MASK (0x8U)
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_SHIFT (3U)
/*! SEQ_BG_PUP_IBG_TX_OVRD - Override value for SEQ_BG_PUP_IBG_TX */
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_TX_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_EN_MASK (0x10U)
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_EN_SHIFT (4U)
/*! SEQ_BG_PUP_IBG_RX_OVRD_EN - Override control for SEQ_BG_PUP_IBG_RX
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_BG_PUP_IBG_RX_OVRD to override the signal "seq_bg_pup_ibg_rx".
 */
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_MASK (0x20U)
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_SHIFT (5U)
/*! SEQ_BG_PUP_IBG_RX_OVRD - Override value for SEQ_BG_PUP_IBG_RX */
#define XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_BG_PUP_IBG_RX_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_EN_SHIFT (6U)
/*! SEQ_TSM_ISO_B_2P4GHZ_OVRD_EN - Override control for SEQ_TSM_ISO_B_2P4GHZ
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_TSM_ISO_B_2P4GHZ_OVRD to override the signal "seq_tsm_iso_b_2p4ghz".
 */
#define XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_MASK (0x80U)
#define XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_SHIFT (7U)
/*! SEQ_TSM_ISO_B_2P4GHZ_OVRD - Override value for SEQ_TSM_ISO_B_2P4GHZ */
#define XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_TSM_ISO_B_2P4GHZ_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_EN_MASK (0x100U)
#define XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_EN_SHIFT (8U)
/*! SEQ_RCCAL_PUP_OVRD_EN - Override control for SEQ_RCCAL_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_RCCAL_PUP_OVRD to override the signal "rx_rccal_pup".
 */
#define XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_MASK   (0x200U)
#define XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_SHIFT  (9U)
/*! SEQ_RCCAL_PUP_OVRD - Override value for SEQ_RCCAL_PUP */
#define XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_RCCAL_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_EN_SHIFT (10U)
/*! SEQ_PD_EN_FCAL_BIAS_OVRD_EN - Override control for SEQ_PD_EN_FCAL_BIAS
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PD_EN_FCAL_BIAS_OVRD to override the signal "seq_pd_en_fcal_bias".
 */
#define XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_MASK (0x800U)
#define XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_SHIFT (11U)
/*! SEQ_PD_EN_FCAL_BIAS_OVRD - Override value for SEQ_PD_EN_FCAL_BIAS */
#define XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_PD_EN_FCAL_BIAS_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_EN_MASK   (0x1000U)
#define XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_EN_SHIFT  (12U)
/*! SEQ_PD_PUP_OVRD_EN - Override control for SEQ_PD_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PD_PUP_OVRD to override the signal "seq_pd_pup".
 */
#define XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_MASK      (0x2000U)
#define XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_SHIFT     (13U)
/*! SEQ_PD_PUP_OVRD - Override value for SEQ_PD_PUP */
#define XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_PD_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_EN_MASK  (0x4000U)
#define XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_EN_SHIFT (14U)
/*! SEQ_VCO_PUP_OVRD_EN - Override control for SEQ_VCO_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_VCO_PUP_OVRD to override the signal "seq_vco_pup".
 */
#define XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_MASK     (0x8000U)
#define XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_SHIFT    (15U)
/*! SEQ_VCO_PUP_OVRD - Override value for SEQ_VCO_PUP */
#define XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_VCO_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_EN_MASK (0x10000U)
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_EN_SHIFT (16U)
/*! SEQ_XO_DIST_EN_OVRD_EN - Override control for SEQ_XO_DIST_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_XO_DIST_EN_OVRD to override the signal "seq_xo_dist_en".
 */
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_MASK  (0x20000U)
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_SHIFT (17U)
/*! SEQ_XO_DIST_EN_OVRD - Override value for SEQ_XO_DIST_EN */
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_EN_MASK (0x40000U)
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_EN_SHIFT (18U)
/*! SEQ_XO_DIST_EN_CLK_REF_OVRD_EN - Override control for SEQ_XO_DIST_EN_CLK_REF
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_XO_DIST_EN_CLK_REF_OVRD to override the signal "seq_xo_dist_en_clk_ref".
 */
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_MASK (0x80000U)
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_SHIFT (19U)
/*! SEQ_XO_DIST_EN_CLK_REF_OVRD - Override value for SEQ_XO_DIST_EN_CLK_REF */
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_REF_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_EN_MASK (0x100000U)
#define XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_EN_SHIFT (20U)
/*! SEQ_XO_EN_CLK_2P4G_OVRD_EN - Override control for SEQ_XO_EN_CLK_2P4G
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_XO_EN_CLK_2P4G_OVRD to override the signal "seq_xo_en_clk_2p4g".
 */
#define XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_MASK (0x200000U)
#define XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_SHIFT (21U)
/*! SEQ_XO_EN_CLK_2P4G_OVRD - Override value for SEQ_XO_EN_CLK_2P4G */
#define XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_EN_CLK_2P4G_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_EN_MASK (0x400000U)
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_EN_SHIFT (22U)
/*! SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_EN - Override control for SEQ_XO_DIST_EN_CLK_ADCDAC
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_EN to override the signal "seq_xo_dist_en_clk_adcdac".
 */
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_MASK (0x800000U)
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_SHIFT (23U)
/*! SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD - Override value for SEQ_XO_DIST_EN_CLK_ADCDAC */
#define XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_XO_DIST_EN_CLK_ADCDAC_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_EN_MASK  (0x1000000U)
#define XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_EN_SHIFT (24U)
/*! SEQ_DAC_PUP_OVRD_EN - Override control for SEQ_DAC_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_DAC_PUP_OVRD to override the signal "seq_dac_pup".
 */
#define XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_MASK     (0x2000000U)
#define XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_SHIFT    (25U)
/*! SEQ_DAC_PUP_OVRD - Override value for SEQ_DAC_PUP */
#define XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_DAC_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_EN_MASK (0x4000000U)
#define XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_EN_SHIFT (26U)
/*! SEQ_VCO_EN_HPM_OVRD_EN - Override control for SEQ_VCO_EN_HPM
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_VCO_EN_HPM_OVRD to override the signal "seq_vco_en_hpm".
 */
#define XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_MASK  (0x8000000U)
#define XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_SHIFT (27U)
/*! SEQ_VCO_EN_HPM_OVRD - Override value for SEQ_VCO_EN_HPM */
#define XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_VCO_EN_HPM_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_EN_MASK (0x10000000U)
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_EN_SHIFT (28U)
/*! SEQ_LO_PUP_VLO_FBK_OVRD_EN - Override control for SEQ_LO_PUP_VLO_FBK
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LO_PUP_VLO_FBK_OVRD to override the signal "seq_lo_pup_vlo_fbk".
 */
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_MASK (0x20000000U)
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_SHIFT (29U)
/*! SEQ_LO_PUP_VLO_FBK_OVRD - Override value for SEQ_LO_PUP_VLO_FBK */
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_FBK_OVRD_MASK)

#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_EN_MASK (0x40000000U)
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_EN_SHIFT (30U)
/*! SEQ_LO_PUP_VLO_RXDRV_OVRD_EN - Override control for SEQ_LO_PUP_VLO_RXDRV
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LO_PUP_VLO_RXDRV_OVRD to override the signal "seq_lo_pup_vlo_rxdrv".
 */
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_MASK (0x80000000U)
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_SHIFT (31U)
/*! SEQ_LO_PUP_VLO_RXDRV_OVRD - Override value for SEQ_LO_PUP_VLO_RXDRV */
#define XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SEQ_LO_PUP_VLO_RXDRV_OVRD_MASK)
/*! @} */

/*! @name OVRD3 - TSM OVERRIDE REGISTER 3 */
/*! @{ */

#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_EN_SHIFT (0U)
/*! SEQ_LO_PUP_VLO_RX_OVRD_EN - Override control for SEQ_LO_PUP_VLO_RX
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LO_PUP_VLO_RX_OVRD to override the signal "seq_lo_pup_vlo_rx".
 */
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_MASK (0x2U)
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_SHIFT (1U)
/*! SEQ_LO_PUP_VLO_RX_OVRD - Override value for SEQ_LO_PUP_VLO_RX */
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_RX_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_EN_SHIFT (2U)
/*! SEQ_LO_PUP_VLO_TX_OVRD_EN - Override control for SEQ_LO_PUP_VLO_TX
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LO_PUP_VLO_TX_OVRD to override the signal "seq_lo_pup_vlo_tx".
 */
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_MASK (0x8U)
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_SHIFT (3U)
/*! SEQ_LO_PUP_VLO_TX_OVRD - Override value for SEQ_LO_PUP_VLO_TX */
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TX_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_EN_MASK (0x10U)
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_EN_SHIFT (4U)
/*! SEQ_LO_PUP_VLO_TXDRV_OVRD_EN - Override control for SEQ_LO_PUP_VLO_TXDRV
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LO_PUP_VLO_TXDRV_OVRD to override the signal "seq_lo_pup_vlo_txdrv".
 */
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_MASK (0x20U)
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_SHIFT (5U)
/*! SEQ_LO_PUP_VLO_TXDRV_OVRD - Override value for SEQ_LO_PUP_VLO_TXDRV */
#define XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_LO_PUP_VLO_TXDRV_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_EN_SHIFT (6U)
/*! SEQ_DIVN_PUP_OVRD_EN - Override control for SEQ_DIVN_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_DIVN_PUP_OVRD to override the signal "seq_divn_pup".
 */
#define XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_MASK    (0x80U)
#define XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_SHIFT   (7U)
/*! SEQ_DIVN_PUP_OVRD - Override value for SEQ_DIVN_PUP */
#define XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_DIVN_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_EN_MASK (0x100U)
#define XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_EN_SHIFT (8U)
/*! SEQ_DIVN_OPENLOOP_OVRD_EN - Override control for SEQ_DIVN_OPENLOOP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_DIVN_OPENLOOP_OVRD to override the signal "seq_divn_openloop".
 */
#define XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_MASK (0x200U)
#define XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_SHIFT (9U)
/*! SEQ_DIVN_OPENLOOP_OVRD - Override value for SEQ_DIVN_OPENLOOP */
#define XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_DIVN_OPENLOOP_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_EN_SHIFT (10U)
/*! SEQ_PD_EN_PD_DRV_OVRD_EN - Override control for SEQ_PD_EN_PD_DRV
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PD_EN_PD_DRV_OVRD to override the signal "seq_pd_en_pd_drv".
 */
#define XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_MASK (0x800U)
#define XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_SHIFT (11U)
/*! SEQ_PD_EN_PD_DRV_OVRD - Override value for SEQ_PD_EN_PD_DRV */
#define XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_PD_EN_PD_DRV_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_EN_MASK (0x1000U)
#define XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_EN_SHIFT (12U)
/*! SEQ_CBPF_EN_DCOC_OVRD_EN - Override control for SEQ_CBPF_EN_DCOC
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_CBPF_EN_DCOC_OVRD to override the signal "seq_cbpf_en_dcoc".
 */
#define XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_MASK (0x2000U)
#define XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_SHIFT (13U)
/*! SEQ_CBPF_EN_DCOC_OVRD - Override value for SEQ_CBPF_EN_DCOC */
#define XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_CBPF_EN_DCOC_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_EN_MASK (0x4000U)
#define XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_EN_SHIFT (14U)
/*! SEQ_RX_LNA_PUP_OVRD_EN - Override control for SEQ_RX_LNA_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_RX_LNA_PUP_OVRD to override the signal "seq_rx_lna_pup".
 */
#define XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_MASK  (0x8000U)
#define XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_SHIFT (15U)
/*! SEQ_RX_LNA_PUP_OVRD - Override value for SEQ_RX_LNA_PUP */
#define XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_RX_LNA_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_EN_MASK  (0x10000U)
#define XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_EN_SHIFT (16U)
/*! SEQ_ADC_PUP_OVRD_EN - Override control for SEQ_ADC_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_ADC_PUP_OVRD to override the signal "seq_adc_pup".
 */
#define XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_MASK     (0x20000U)
#define XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_SHIFT    (17U)
/*! SEQ_ADC_PUP_OVRD - Override value for SEQ_ADC_PUP */
#define XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_ADC_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_EN_MASK (0x40000U)
#define XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_EN_SHIFT (18U)
/*! SEQ_CBPF_PUP_OVRD_EN - Override control for SEQ_CBPF_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_CBPF_PUP_OVRD to override the signal "seq_cbpf_pup".
 */
#define XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_MASK    (0x80000U)
#define XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_SHIFT   (19U)
/*! SEQ_CBPF_PUP_OVRD - Override value for SEQ_CBPF_PUP */
#define XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_CBPF_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_EN_MASK (0x100000U)
#define XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_EN_SHIFT (20U)
/*! SEQ_RX_MIX_PUP_OVRD_EN - Override control for SEQ_RX_MIX_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_RX_MIX_PUP_OVRD to override the signal "seq_rx_mix_pup".
 */
#define XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_MASK  (0x200000U)
#define XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_SHIFT (21U)
/*! SEQ_RX_MIX_PUP_OVRD - Override control for SEQ_RX_MIX_PUP
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_RX_MIX_PUP_OVRD to override the signal "seq_rx_mix_pup".
 */
#define XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_RX_MIX_PUP_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_EN_MASK   (0x400000U)
#define XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_EN_SHIFT  (22U)
/*! SEQ_SPARE1_OVRD_EN - Override control for SEQ_SPARE1
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_SPARE1_OVRD to override the signal "seq_spare1".
 */
#define XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_MASK      (0x800000U)
#define XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_SHIFT     (23U)
/*! SEQ_SPARE1_OVRD - Override value for SEQ_SPARE1 */
#define XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_SPARE1_OVRD_MASK)

#define XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_EN_MASK   (0x1000000U)
#define XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_EN_SHIFT  (24U)
/*! SEQ_SPARE3_OVRD_EN - Override control for SEQ_SPARE3
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_SPARE3_OVRD to override the signal "seq_spare3".
 */
#define XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_MASK      (0x2000000U)
#define XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_SHIFT     (25U)
/*! SEQ_SPARE3_OVRD - Override value for SEQ_SPARE3 */
#define XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_SHIFT)) & XCVR_TSM_OVRD3_SEQ_SPARE3_OVRD_MASK)

#define XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_MASK      (0x4000000U)
#define XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_SHIFT     (26U)
/*! TX_MODE_OVRD_EN - Override control for TX_MODE
 *  0b0..Normal operation.
 *  0b1..Use the state of TX_MODE_OVRD to override the signal "tx_mode".
 */
#define XCVR_TSM_OVRD3_TX_MODE_OVRD_EN(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_TX_MODE_OVRD_MASK         (0x8000000U)
#define XCVR_TSM_OVRD3_TX_MODE_OVRD_SHIFT        (27U)
/*! TX_MODE_OVRD - Override value for TX_MODE */
#define XCVR_TSM_OVRD3_TX_MODE_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TX_MODE_OVRD_SHIFT)) & XCVR_TSM_OVRD3_TX_MODE_OVRD_MASK)

#define XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_MASK      (0x10000000U)
#define XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_SHIFT     (28U)
/*! RX_MODE_OVRD_EN - Override control for RX_MODE
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_MODE_OVRD to override the signal "rx_mode".
 */
#define XCVR_TSM_OVRD3_RX_MODE_OVRD_EN(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RX_MODE_OVRD_MASK         (0x20000000U)
#define XCVR_TSM_OVRD3_RX_MODE_OVRD_SHIFT        (29U)
/*! RX_MODE_OVRD - Override value for RX_MODE */
#define XCVR_TSM_OVRD3_RX_MODE_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RX_MODE_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RX_MODE_OVRD_MASK)

#define XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_EN_MASK   (0x40000000U)
#define XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_EN_SHIFT  (30U)
/*! GEAR_SHIFT_OVRD_EN - Override control for GEAR_SHIFT
 *  0b0..Normal operation.
 *  0b1..Use the state of GEAR_SHIFT_OVRD to override the signal "gear_shift".
 */
#define XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_MASK      (0x80000000U)
#define XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_SHIFT     (31U)
/*! GEAR_SHIFT_OVRD - Override value for GEAR_SHIFT */
#define XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_SHIFT)) & XCVR_TSM_OVRD3_GEAR_SHIFT_OVRD_MASK)
/*! @} */

/*! @name OVRD4 - TSM OVERRIDE REGISTER 4 */
/*! @{ */

#define XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_EN_SHIFT (0U)
/*! SEQ_PIC_CORE_EN_OVRD_EN - Override control for SEQ_PIC_CORE_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PIC_CORE_EN_OVRD to override the signal "seq_pic_core_en".
 */
#define XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_MASK (0x2U)
#define XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_SHIFT (1U)
/*! SEQ_PIC_CORE_EN_OVRD - Override value for SEQ_PIC_CORE_EN */
#define XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_CORE_EN_OVRD_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_EN_SHIFT (2U)
/*! SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_EN - Override control for SEQ_PIC_SHORT_CINT_SHORT_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD to override the signal "seq_pic_short_cint_short_en".
 */
#define XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_MASK (0x8U)
#define XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_SHIFT (3U)
/*! SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD - Override value for SEQ_PIC_SHORT_CINT_SHORT_EN */
#define XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_SHORT_CINT_SHORT_EN_OVRD_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_EN_MASK (0x10U)
#define XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_EN_SHIFT (4U)
/*! SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_EN - Override control for SEQ_PIC_FILTER_LOW_BW_SM_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD to override the signal "seq_pic_filter_low_bw_sm_en".
 */
#define XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_MASK (0x20U)
#define XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_SHIFT (5U)
/*! SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD - Override value for SEQ_PIC_FILTER_LOW_BW_SM_EN */
#define XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_FILTER_LOW_BW_SM_EN_OVRD_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_EN_SHIFT (6U)
/*! SEQ_PIC_RFB_OPEN_SM_EN_OVRD_EN - Override control for SEQ_PIC_RFB_OPEN_SM_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PIC_RFB_OPEN_SM_EN_OVRD to override the signal "seq_pic_rfb_open_sm_en".
 */
#define XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_MASK (0x80U)
#define XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_SHIFT (7U)
/*! SEQ_PIC_RFB_OPEN_SM_EN_OVRD - Override value for SEQ_PIC_RFB_OPEN_SM_EN */
#define XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_RFB_OPEN_SM_EN_OVRD_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_EN_MASK (0x100U)
#define XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_EN_SHIFT (8U)
/*! SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_EN - Override control for SEQ_PIC_RINT2_SHORT_FM_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_PIC_RINT2_SHORT_FM_EN_OVRD to override the signal "seq_pic_rint2_short_fm_en".
 */
#define XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_MASK (0x200U)
#define XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_SHIFT (9U)
/*! SEQ_PIC_RINT2_SHORT_FM_EN_OVRD - Override value for SEQ_PIC_RINT2_SHORT_FM_EN */
#define XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_PIC_RINT2_SHORT_FM_EN_OVRD_MASK)

#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_EN_SHIFT (10U)
/*! SEQ_LODIV_SYNC_RESET_EN_OVRD_EN - Override control for SEQ_LODIV_SYNC_RESET_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LODIV_SYNC_RESET_EN_OVRD to override the signal "seq_lodiv_sync_reset_en".
 */
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_MASK (0x800U)
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_SHIFT (11U)
/*! SEQ_LODIV_SYNC_RESET_EN_OVRD - Override value for SEQ_LODIV_SYNC_RESET_EN */
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_RESET_EN_OVRD_MASK)

#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_EN_MASK (0x1000U)
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_EN_SHIFT (12U)
/*! SEQ_LODIV_SYNC_EN_OVRD_EN - Override control for SEQ_LODIV_SYNC_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LODIV_SYNC_EN_OVRD to override the signal "seq_lodiv_sync_en".
 */
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_MASK (0x2000U)
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_SHIFT (13U)
/*! SEQ_LODIV_SYNC_EN_OVRD - Override value for SEQ_LODIV_SYNC_EN */
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_EN_OVRD_MASK)

#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_EN_MASK (0x4000U)
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_EN_SHIFT (14U)
/*! SEQ_LODIV_SYNC_SPARE_EN_OVRD_EN - Override control for SEQ_LODIV_SYNC_SPARE_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SEQ_LODIV_SYNC_SPARE_EN_OVRD to override the signal "seq_lodiv_sync_spare_en".
 */
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_MASK (0x8000U)
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_SHIFT (15U)
/*! SEQ_LODIV_SYNC_SPARE_EN_OVRD - Override value for SEQ_LODIV_SYNC_SPARE_EN */
#define XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD4_SEQ_LODIV_SYNC_SPARE_EN_OVRD_MASK)
/*! @} */

/*! @name CTRL2 - TSM CONTROL 2 */
/*! @{ */

#define XCVR_TSM_CTRL2_RST_CSR_SW_EN_MASK        (0x1U)
#define XCVR_TSM_CTRL2_RST_CSR_SW_EN_SHIFT       (0U)
/*! RST_CSR_SW_EN - Reset CSR Timing Values By SW 1
 *  0b0..Reset Enabled
 *  0b1..Reset Disabled
 */
#define XCVR_TSM_CTRL2_RST_CSR_SW_EN(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL2_RST_CSR_SW_EN_SHIFT)) & XCVR_TSM_CTRL2_RST_CSR_SW_EN_MASK)

#define XCVR_TSM_CTRL2_RST_CSR_SW2_EN_MASK       (0x2U)
#define XCVR_TSM_CTRL2_RST_CSR_SW2_EN_SHIFT      (1U)
/*! RST_CSR_SW2_EN - Reset CSR Timing Values By SW 2
 *  0b0..Reset Enabled
 *  0b1..Reset Disabled
 */
#define XCVR_TSM_CTRL2_RST_CSR_SW2_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL2_RST_CSR_SW2_EN_SHIFT)) & XCVR_TSM_CTRL2_RST_CSR_SW2_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_TSM_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_TSM_Peripheral_Access_Layer */


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


#endif  /* PERI_XCVR_TSM_H_ */

