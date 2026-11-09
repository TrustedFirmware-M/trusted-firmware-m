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
**         CMSIS Peripheral Access Layer for GEN4PHY
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
 * @file PERI_GEN4PHY.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for GEN4PHY
 *
 * CMSIS Peripheral Access Layer for GEN4PHY
 */

#if !defined(PERI_GEN4PHY_H_)
#define PERI_GEN4PHY_H_                          /**< Symbol preventing repeated inclusion */

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
   -- GEN4PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GEN4PHY_Peripheral_Access_Layer GEN4PHY Peripheral Access Layer
 * @{
 */

/** GEN4PHY - Size of Registers Arrays */
#define GEN4PHY_FSK_PD_PH_REF_COUNT               2u
#define GEN4PHY_FSK_PD_RO_PH_REF_COUNT            4u
#define GEN4PHY_LR_PD_PH_REF_COUNT                4u
#define GEN4PHY_LR_PD_RO_PH_REF_COUNT             13u
#define GEN4PHY_DEMOD_WAVE_COUNT                  8u

/** GEN4PHY - Register Layout Typedef */
typedef struct {
  __IO uint32_t FSK_PD_CFG0;                       /**< PHY Uncoded Preamble Detect Config 0, offset: 0x0 */
  __IO uint32_t FSK_PD_CFG1;                       /**< PHY Uncoded Preamble Detect Config 1, offset: 0x4 */
  __IO uint32_t FSK_PD_CFG2;                       /**< PHY Uncoded Preamble Detect Config 2, offset: 0x8 */
  __IO uint32_t FSK_PD_PH[GEN4PHY_FSK_PD_PH_REF_COUNT]; /**< PHY Uncoded Preamble Detect Phase, array offset: 0xC, array step: 0x4 */
  __I  uint32_t FSK_PD_RO_PH[GEN4PHY_FSK_PD_RO_PH_REF_COUNT]; /**< PHY Uncoded Preamble Detect Read Only Phase, array offset: 0x14, array step: 0x4 */
  __IO uint32_t FSK_CFG0;                          /**< PHY Uncoded Config 0, offset: 0x24 */
  __IO uint32_t FSK_CFG1;                          /**< PHY Uncoded Config 1, offset: 0x28 */
  __IO uint32_t FSK_CFG2;                          /**< PHY Uncoded Config 2, offset: 0x2C */
       uint8_t RESERVED_0[4];
  __IO uint32_t FSK_PT;                            /**< PHY Uncoded Power Threshold Config, offset: 0x34 */
  __IO uint32_t FSK_FAD_CTRL;                      /**< PHY Uncoded FAD Control, offset: 0x38 */
  __IO uint32_t FSK_FAD_CFG;                       /**< PHY Uncoded FAD Config, offset: 0x3C */
  __I  uint32_t FSK_STAT;                          /**< PHY Uncoded Status, offset: 0x40 */
  __IO uint32_t LR_PD_CFG;                         /**< PHY Long Range Preamble Detect Config, offset: 0x44 */
  __IO uint32_t LR_PD_PH[GEN4PHY_LR_PD_PH_REF_COUNT]; /**< PHY Long Range Preamble Detect Phase 0..PHY Long Range Preamble Detect Phase 3, array offset: 0x48, array step: 0x4 */
  __I  uint32_t LR_PD_RO_PH[GEN4PHY_LR_PD_RO_PH_REF_COUNT]; /**< PHY Long Range Preamble Detect Read Only Phase 4..PHY Long Range Preamble Detect Read Only Phase 16, array offset: 0x58, array step: 0x4 */
  __IO uint32_t LR_AA_CFG;                         /**< PHY Long Range AA Config, offset: 0x8C */
  __I  uint32_t LR_STAT;                           /**< PHY Long Range Status, offset: 0x90 */
  __IO uint32_t SM_CFG;                            /**< PHY State Machine Config, offset: 0x94 */
  __IO uint32_t MISC;                              /**< PHY Misc Config, offset: 0x98 */
  __I  uint32_t STAT0;                             /**< PHY Status 0, offset: 0x9C */
  __I  uint32_t STAT1;                             /**< PHY Status 1, offset: 0xA0 */
  __I  uint32_t STAT2;                             /**< PHY Status 2, offset: 0xA4 */
  __IO uint32_t PREPHY_MISC;                       /**< PHY PrePHY Misc Config, offset: 0xA8 */
  __IO uint32_t DMD_CTRL0;                         /**< PHY Demodulator Control 0, offset: 0xAC */
  __IO uint32_t DMD_CTRL1;                         /**< PHY Demodulator Control 1, offset: 0xB0 */
  __IO uint32_t DMD_CTRL2;                         /**< PHY Demodulator Control 2, offset: 0xB4 */
  struct {                                         /* offset: 0xB8, array step: 0xC */
    __IO uint32_t DMD_WAVE_REG0;                     /**< PHY Demodulator Wave0 Register 0..PHY Demodulator Wave7 Register 0, array offset: 0xB8, array step: 0xC */
    __IO uint32_t DMD_WAVE_REG1;                     /**< PHY Demodulator Wave0 Register 1..PHY Demodulator Wave7 Register 1, array offset: 0xBC, array step: 0xC */
    __IO uint32_t DMD_WAVE_REG2;                     /**< PHY Demodulator Wave0 Register 2..PHY Demodulator Wave7 Register 2, array offset: 0xC0, array step: 0xC */
  } DEMOD_WAVE[GEN4PHY_DEMOD_WAVE_COUNT];
       uint8_t RESERVED_1[76];
  __IO uint32_t DMDAA_CTRL;                        /**< PHY Demodulator Based SFD Confirmation control register., offset: 0x164 */
  __I  uint32_t RTT_STAT;                          /**< High resolution Time-Of-Flight calculation Status., offset: 0x168 */
  __IO uint32_t RTT_CTRL;                          /**< PHY RTT control register., offset: 0x16C */
  __IO uint32_t RTT_REF;                           /**< PHY RTT reference register., offset: 0x170 */
} GEN4PHY_Type;

/* ----------------------------------------------------------------------------
   -- GEN4PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GEN4PHY_Register_Masks GEN4PHY Register Masks
 * @{
 */

/*! @name FSK_PD_CFG0 - PHY Uncoded Preamble Detect Config 0 */
/*! @{ */

#define GEN4PHY_FSK_PD_CFG0_PREAMBLE_T_SCALE_MASK (0xFU)
#define GEN4PHY_FSK_PD_CFG0_PREAMBLE_T_SCALE_SHIFT (0U)
/*! PREAMBLE_T_SCALE - Scaling factor used for fractional time estimation during preamble search. */
#define GEN4PHY_FSK_PD_CFG0_PREAMBLE_T_SCALE(x)  (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_CFG0_PREAMBLE_T_SCALE_SHIFT)) & GEN4PHY_FSK_PD_CFG0_PREAMBLE_T_SCALE_MASK)

#define GEN4PHY_FSK_PD_CFG0_PD_IIR_ALPHA_MASK    (0xFF00U)
#define GEN4PHY_FSK_PD_CFG0_PD_IIR_ALPHA_SHIFT   (8U)
/*! PD_IIR_ALPHA - Forgetting factor used by the complex correlations smoothing leaky integrator. */
#define GEN4PHY_FSK_PD_CFG0_PD_IIR_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_CFG0_PD_IIR_ALPHA_SHIFT)) & GEN4PHY_FSK_PD_CFG0_PD_IIR_ALPHA_MASK)
/*! @} */

/*! @name FSK_PD_CFG1 - PHY Uncoded Preamble Detect Config 1 */
/*! @{ */

#define GEN4PHY_FSK_PD_CFG1_PREAMBLE_PATTERN_MASK (0xFFU)
#define GEN4PHY_FSK_PD_CFG1_PREAMBLE_PATTERN_SHIFT (0U)
/*! PREAMBLE_PATTERN - 8-bit preamble pattern used in FM-domain preamble detector. */
#define GEN4PHY_FSK_PD_CFG1_PREAMBLE_PATTERN(x)  (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_CFG1_PREAMBLE_PATTERN_SHIFT)) & GEN4PHY_FSK_PD_CFG1_PREAMBLE_PATTERN_MASK)
/*! @} */

/*! @name FSK_PD_CFG2 - PHY Uncoded Preamble Detect Config 2 */
/*! @{ */

#define GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_1M_MASK (0xFFU)
#define GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_1M_SHIFT (0U)
/*! PD_THRESH_ACQ_1_3_1M - Preamble detect threshold for acq mode 1 and 3 at data rate 1Mbps */
#define GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_1M(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_1M_SHIFT)) & GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_1M_MASK)

#define GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_2M_MASK (0xFF0000U)
#define GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_2M_SHIFT (16U)
/*! PD_THRESH_ACQ_1_3_2M - Preamble detect threshold for acq mode 1 and 3 at data rate 2Mbps */
#define GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_2M(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_2M_SHIFT)) & GEN4PHY_FSK_PD_CFG2_PD_THRESH_ACQ_1_3_2M_MASK)
/*! @} */

/*! @name FSK_PD_PH - PHY Uncoded Preamble Detect Phase */
/*! @{ */

#define GEN4PHY_FSK_PD_PH_REF0_MASK              (0x3FU)
#define GEN4PHY_FSK_PD_PH_REF0_SHIFT             (0U)
/*! REF0 - Uncoded preamble reference waveform sample 4 (sfix6en5) */
#define GEN4PHY_FSK_PD_PH_REF0(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_PH_REF0_SHIFT)) & GEN4PHY_FSK_PD_PH_REF0_MASK)

#define GEN4PHY_FSK_PD_PH_REF1_MASK              (0x3F00U)
#define GEN4PHY_FSK_PD_PH_REF1_SHIFT             (8U)
/*! REF1 - Uncoded preamble reference waveform sample 5 (sfix6en5) */
#define GEN4PHY_FSK_PD_PH_REF1(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_PH_REF1_SHIFT)) & GEN4PHY_FSK_PD_PH_REF1_MASK)

#define GEN4PHY_FSK_PD_PH_REF2_MASK              (0x3F0000U)
#define GEN4PHY_FSK_PD_PH_REF2_SHIFT             (16U)
/*! REF2 - Uncoded preamble reference waveform sample 6 (sfix6en5) */
#define GEN4PHY_FSK_PD_PH_REF2(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_PH_REF2_SHIFT)) & GEN4PHY_FSK_PD_PH_REF2_MASK)

#define GEN4PHY_FSK_PD_PH_REF3_MASK              (0x3F000000U)
#define GEN4PHY_FSK_PD_PH_REF3_SHIFT             (24U)
/*! REF3 - Uncoded preamble reference waveform sample 7 (sfix6en5) */
#define GEN4PHY_FSK_PD_PH_REF3(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_PH_REF3_SHIFT)) & GEN4PHY_FSK_PD_PH_REF3_MASK)
/*! @} */

/* The count of GEN4PHY_FSK_PD_PH */
#define GEN4PHY_FSK_PD_PH_COUNT                  (2U)

/*! @name FSK_PD_RO_PH - PHY Uncoded Preamble Detect Read Only Phase */
/*! @{ */

#define GEN4PHY_FSK_PD_RO_PH_REF0_MASK           (0x3FU)
#define GEN4PHY_FSK_PD_RO_PH_REF0_SHIFT          (0U)
/*! REF0 - Uncoded preamble reference waveform sample 28 (sfix6en5) */
#define GEN4PHY_FSK_PD_RO_PH_REF0(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_RO_PH_REF0_SHIFT)) & GEN4PHY_FSK_PD_RO_PH_REF0_MASK)

#define GEN4PHY_FSK_PD_RO_PH_REF1_MASK           (0x3F00U)
#define GEN4PHY_FSK_PD_RO_PH_REF1_SHIFT          (8U)
/*! REF1 - Uncoded preamble reference waveform sample 29 (sfix6en5) */
#define GEN4PHY_FSK_PD_RO_PH_REF1(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_RO_PH_REF1_SHIFT)) & GEN4PHY_FSK_PD_RO_PH_REF1_MASK)

#define GEN4PHY_FSK_PD_RO_PH_REF2_MASK           (0x3F0000U)
#define GEN4PHY_FSK_PD_RO_PH_REF2_SHIFT          (16U)
/*! REF2 - Uncoded preamble reference waveform sample 30 (sfix6en5) */
#define GEN4PHY_FSK_PD_RO_PH_REF2(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_RO_PH_REF2_SHIFT)) & GEN4PHY_FSK_PD_RO_PH_REF2_MASK)

#define GEN4PHY_FSK_PD_RO_PH_REF3_MASK           (0x3F000000U)
#define GEN4PHY_FSK_PD_RO_PH_REF3_SHIFT          (24U)
/*! REF3 - Uncoded preamble reference waveform sample 31 (sfix6en5) */
#define GEN4PHY_FSK_PD_RO_PH_REF3(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PD_RO_PH_REF3_SHIFT)) & GEN4PHY_FSK_PD_RO_PH_REF3_MASK)
/*! @} */

/* The count of GEN4PHY_FSK_PD_RO_PH */
#define GEN4PHY_FSK_PD_RO_PH_COUNT               (4U)

/*! @name FSK_CFG0 - PHY Uncoded Config 0 */
/*! @{ */

#define GEN4PHY_FSK_CFG0_AA_OUT_SEL_MASK         (0x2U)
#define GEN4PHY_FSK_CFG0_AA_OUT_SEL_SHIFT        (1U)
/*! AA_OUT_SEL - Specifies which AA bits to be played-back to the LL:
 *  0b0..output the received AA bits
 *  0b1..output the programmed AA bits
 */
#define GEN4PHY_FSK_CFG0_AA_OUT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_AA_OUT_SEL_SHIFT)) & GEN4PHY_FSK_CFG0_AA_OUT_SEL_MASK)

#define GEN4PHY_FSK_CFG0_FSK_BIT_INVERT_MASK     (0x4U)
#define GEN4PHY_FSK_CFG0_FSK_BIT_INVERT_SHIFT    (2U)
/*! FSK_BIT_INVERT - This applies at the demodulator, so it affects both AA and the data portions of the packet.
 *  0b0..Normal demodulation
 *  0b1..Invert demodulated bits
 */
#define GEN4PHY_FSK_CFG0_FSK_BIT_INVERT(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_FSK_BIT_INVERT_SHIFT)) & GEN4PHY_FSK_CFG0_FSK_BIT_INVERT_MASK)

#define GEN4PHY_FSK_CFG0_MSK_EN_MASK             (0x20U)
#define GEN4PHY_FSK_CFG0_MSK_EN_SHIFT            (5U)
/*! MSK_EN - Configures PHY for MSK decoding. */
#define GEN4PHY_FSK_CFG0_MSK_EN(x)               (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_MSK_EN_SHIFT)) & GEN4PHY_FSK_CFG0_MSK_EN_MASK)

#define GEN4PHY_FSK_CFG0_MSK2FSK_SEED_MASK       (0x40U)
#define GEN4PHY_FSK_CFG0_MSK2FSK_SEED_SHIFT      (6U)
/*! MSK2FSK_SEED - Last bit of preamble. */
#define GEN4PHY_FSK_CFG0_MSK2FSK_SEED(x)         (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_MSK2FSK_SEED_SHIFT)) & GEN4PHY_FSK_CFG0_MSK2FSK_SEED_MASK)

#define GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_1M_MASK (0x1F00U)
#define GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_1M_SHIFT (8U)
/*! AA_ACQ_1_2_3_THRESH_1M - For 1Mbps data rate, Correlation threshold applicable to AA detection; uses ufix5_En5 fixed-point format. */
#define GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_1M(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_1M_SHIFT)) & GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_1M_MASK)

#define GEN4PHY_FSK_CFG0_HAMMING_AA_LOW_PWR_MASK (0xF0000U)
#define GEN4PHY_FSK_CFG0_HAMMING_AA_LOW_PWR_SHIFT (16U)
/*! HAMMING_AA_LOW_PWR - Maximum hamming distance from the given AA pattern that may still be
 *    accepted as a match; valid range [0,7]. This threshold value are performed on lower power case.
 */
#define GEN4PHY_FSK_CFG0_HAMMING_AA_LOW_PWR(x)   (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_HAMMING_AA_LOW_PWR_SHIFT)) & GEN4PHY_FSK_CFG0_HAMMING_AA_LOW_PWR_MASK)

#define GEN4PHY_FSK_CFG0_BLE_NTW_ADR_THR_MASK    (0x700000U)
#define GEN4PHY_FSK_CFG0_BLE_NTW_ADR_THR_SHIFT   (20U)
/*! BLE_NTW_ADR_THR - Maximum hamming distance from the given AA pattern that may still be accepted as a match; valid range [0,7]. */
#define GEN4PHY_FSK_CFG0_BLE_NTW_ADR_THR(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_BLE_NTW_ADR_THR_SHIFT)) & GEN4PHY_FSK_CFG0_BLE_NTW_ADR_THR_MASK)

#define GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_2M_MASK (0x1F000000U)
#define GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_2M_SHIFT (24U)
/*! AA_ACQ_1_2_3_THRESH_2M - For 2Mbps data rate, correlation threshold applicable to AA detection; uses ufix5_En5 fixed-point format. */
#define GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_2M(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_2M_SHIFT)) & GEN4PHY_FSK_CFG0_AA_ACQ_1_2_3_THRESH_2M_MASK)
/*! @} */

/*! @name FSK_CFG1 - PHY Uncoded Config 1 */
/*! @{ */

#define GEN4PHY_FSK_CFG1_OVERH_MASK              (0x1FFU)
#define GEN4PHY_FSK_CFG1_OVERH_SHIFT             (0U)
/*! OVERH - Modulation index; represented in ufix11_En6 format. */
#define GEN4PHY_FSK_CFG1_OVERH(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG1_OVERH_SHIFT)) & GEN4PHY_FSK_CFG1_OVERH_MASK)

#define GEN4PHY_FSK_CFG1_OVERH_INV_MASK          (0xFF800U)
#define GEN4PHY_FSK_CFG1_OVERH_INV_SHIFT         (11U)
/*! OVERH_INV - Reciprocal of modulation index; represented in ufix9_En7 format. */
#define GEN4PHY_FSK_CFG1_OVERH_INV(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG1_OVERH_INV_SHIFT)) & GEN4PHY_FSK_CFG1_OVERH_INV_MASK)

#define GEN4PHY_FSK_CFG1_SYNCTSCALE_MASK         (0xF000000U)
#define GEN4PHY_FSK_CFG1_SYNCTSCALE_SHIFT        (24U)
/*! SYNCTSCALE - Scaling factor used for fractional time estimation during AA search; represented in ufix4_En3 format. */
#define GEN4PHY_FSK_CFG1_SYNCTSCALE(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG1_SYNCTSCALE_SHIFT)) & GEN4PHY_FSK_CFG1_SYNCTSCALE_MASK)
/*! @} */

/*! @name FSK_CFG2 - PHY Uncoded Config 2 */
/*! @{ */

#define GEN4PHY_FSK_CFG2_MAG_WIN_MASK            (0xF0000000U)
#define GEN4PHY_FSK_CFG2_MAG_WIN_SHIFT           (28U)
/*! MAG_WIN - Indicates the forgetting factor used in received signal level measurement; */
#define GEN4PHY_FSK_CFG2_MAG_WIN(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_CFG2_MAG_WIN_SHIFT)) & GEN4PHY_FSK_CFG2_MAG_WIN_MASK)
/*! @} */

/*! @name FSK_PT - PHY Uncoded Power Threshold Config */
/*! @{ */

#define GEN4PHY_FSK_PT_AGC_TIMEOUT_MASK          (0xFFFFU)
#define GEN4PHY_FSK_PT_AGC_TIMEOUT_SHIFT         (0U)
/*! AGC_TIMEOUT - Time-out, applicable to special conditioning of signal power detection in the
 *    Power threshold block, after each AGC gain adjustment. It is expressed in number of samples.
 */
#define GEN4PHY_FSK_PT_AGC_TIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PT_AGC_TIMEOUT_SHIFT)) & GEN4PHY_FSK_PT_AGC_TIMEOUT_MASK)

#define GEN4PHY_FSK_PT_COND_SIG_PRST_EN_MASK     (0x10000U)
#define GEN4PHY_FSK_PT_COND_SIG_PRST_EN_SHIFT    (16U)
/*! COND_SIG_PRST_EN - Enables special conditioning of signal detection;
 *  0b0..disable.
 *  0b1..enable.
 */
#define GEN4PHY_FSK_PT_COND_SIG_PRST_EN(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PT_COND_SIG_PRST_EN_SHIFT)) & GEN4PHY_FSK_PT_COND_SIG_PRST_EN_MASK)

#define GEN4PHY_FSK_PT_COND_AA_BUFF_EN_MASK      (0x20000U)
#define GEN4PHY_FSK_PT_COND_AA_BUFF_EN_SHIFT     (17U)
/*! COND_AA_BUFF_EN - Enables special condition for enabling AA detector buffer;
 *  0b0..disable.
 *  0b1..enable.
 */
#define GEN4PHY_FSK_PT_COND_AA_BUFF_EN(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PT_COND_AA_BUFF_EN_SHIFT)) & GEN4PHY_FSK_PT_COND_AA_BUFF_EN_MASK)

#define GEN4PHY_FSK_PT_BYPASS_WITH_RSSI_MASK     (0x40000U)
#define GEN4PHY_FSK_PT_BYPASS_WITH_RSSI_SHIFT    (18U)
/*! BYPASS_WITH_RSSI - Bypass signal power measurement with RSSI measurement;
 *  0b0..no
 *  0b1..yes
 */
#define GEN4PHY_FSK_PT_BYPASS_WITH_RSSI(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_PT_BYPASS_WITH_RSSI_SHIFT)) & GEN4PHY_FSK_PT_BYPASS_WITH_RSSI_MASK)
/*! @} */

/*! @name FSK_FAD_CTRL - PHY Uncoded FAD Control */
/*! @{ */

#define GEN4PHY_FSK_FAD_CTRL_FAD_EN_MASK         (0x1U)
#define GEN4PHY_FSK_FAD_CTRL_FAD_EN_SHIFT        (0U)
/*! FAD_EN - Enables FAD;
 *  0b0..disable.
 *  0b1..enable.
 */
#define GEN4PHY_FSK_FAD_CTRL_FAD_EN(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_FAD_CTRL_FAD_EN_SHIFT)) & GEN4PHY_FSK_FAD_CTRL_FAD_EN_MASK)
/*! @} */

/*! @name FSK_FAD_CFG - PHY Uncoded FAD Config */
/*! @{ */

#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_SYNCH_MASK (0x7FU)
#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_SYNCH_SHIFT (0U)
/*! WIN_FAD_WAIT_SYNCH - Time-window to wait for clean samples, before transitioning to AA search
 *    PHY state, if PD was found after antenna switch , in sample clock cycles(referred to as T3 in
 *    the PHY state-machine section).
 */
#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_SYNCH(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_SYNCH_SHIFT)) & GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_SYNCH_MASK)

#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_PD_MASK (0x7F00U)
#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_PD_SHIFT (8U)
/*! WIN_FAD_WAIT_PD - Time-window to wait for clean samples if PD was not found after antenna switch
 *    , in sample clock cycles(referred to as T2 in the PHY state-machine section).
 */
#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_PD(x)   (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_PD_SHIFT)) & GEN4PHY_FSK_FAD_CFG_WIN_FAD_WAIT_PD_MASK)

#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_SEARCH_PD_MASK (0x7F0000U)
#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_SEARCH_PD_SHIFT (16U)
/*! WIN_FAD_SEARCH_PD - Time-window to match preamble pattern on samples coming from the previously
 *    selected antenna , in sample clock cycles(referred to as T1 in the PHY state-machine section).
 */
#define GEN4PHY_FSK_FAD_CFG_WIN_FAD_SEARCH_PD(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_FAD_CFG_WIN_FAD_SEARCH_PD_SHIFT)) & GEN4PHY_FSK_FAD_CFG_WIN_FAD_SEARCH_PD_MASK)

#define GEN4PHY_FSK_FAD_CFG_WIN_SEARCH_PD_MASK   (0x7F000000U)
#define GEN4PHY_FSK_FAD_CFG_WIN_SEARCH_PD_SHIFT  (24U)
/*! WIN_SEARCH_PD - Time-window to match preamble pattern on samples coming from the currently
 *    selected antenna, in sample clock cycles (referred to as T0 in the PHY state-machine section).
 */
#define GEN4PHY_FSK_FAD_CFG_WIN_SEARCH_PD(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_FAD_CFG_WIN_SEARCH_PD_SHIFT)) & GEN4PHY_FSK_FAD_CFG_WIN_SEARCH_PD_MASK)
/*! @} */

/*! @name FSK_STAT - PHY Uncoded Status */
/*! @{ */

#define GEN4PHY_FSK_STAT_EXT_TO_MODES_13_MASK    (0x2U)
#define GEN4PHY_FSK_STAT_EXT_TO_MODES_13_SHIFT   (1U)
/*! EXT_TO_MODES_13 - Indicates Timeout extension for modes 1 et 3 */
#define GEN4PHY_FSK_STAT_EXT_TO_MODES_13(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_STAT_EXT_TO_MODES_13_SHIFT)) & GEN4PHY_FSK_STAT_EXT_TO_MODES_13_MASK)

#define GEN4PHY_FSK_STAT_AA_FOUND_MASK           (0x4U)
#define GEN4PHY_FSK_STAT_AA_FOUND_SHIFT          (2U)
/*! AA_FOUND - Indicates that a uncoded AA detect is active. */
#define GEN4PHY_FSK_STAT_AA_FOUND(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_STAT_AA_FOUND_SHIFT)) & GEN4PHY_FSK_STAT_AA_FOUND_MASK)

#define GEN4PHY_FSK_STAT_LAST_AA_BIT_MASK        (0x8U)
#define GEN4PHY_FSK_STAT_LAST_AA_BIT_SHIFT       (3U)
/*! LAST_AA_BIT - reserved */
#define GEN4PHY_FSK_STAT_LAST_AA_BIT(x)          (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_STAT_LAST_AA_BIT_SHIFT)) & GEN4PHY_FSK_STAT_LAST_AA_BIT_MASK)

#define GEN4PHY_FSK_STAT_AA_MATCH_MASK           (0xF0U)
#define GEN4PHY_FSK_STAT_AA_MATCH_SHIFT          (4U)
/*! AA_MATCH - Indicates which non-coded AA has matched. This will clear when the PHY is re-initialized. */
#define GEN4PHY_FSK_STAT_AA_MATCH(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_STAT_AA_MATCH_SHIFT)) & GEN4PHY_FSK_STAT_AA_MATCH_MASK)

#define GEN4PHY_FSK_STAT_HAMM_DIST_MASK          (0x7F00U)
#define GEN4PHY_FSK_STAT_HAMM_DIST_SHIFT         (8U)
/*! HAMM_DIST - Indicates the hamming distance witnessed when AA match occurred. */
#define GEN4PHY_FSK_STAT_HAMM_DIST(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_STAT_HAMM_DIST_SHIFT)) & GEN4PHY_FSK_STAT_HAMM_DIST_MASK)

#define GEN4PHY_FSK_STAT_CORR_MAX_MASK           (0x1F0000U)
#define GEN4PHY_FSK_STAT_CORR_MAX_SHIFT          (16U)
/*! CORR_MAX - Indicates the correlation witnessed when AA match occurred */
#define GEN4PHY_FSK_STAT_CORR_MAX(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_STAT_CORR_MAX_SHIFT)) & GEN4PHY_FSK_STAT_CORR_MAX_MASK)

#define GEN4PHY_FSK_STAT_TOF_OFF_MASK            (0xF0000000U)
#define GEN4PHY_FSK_STAT_TOF_OFF_SHIFT           (28U)
/*! TOF_OFF - Timing offset for use in time-of-flight calculation. */
#define GEN4PHY_FSK_STAT_TOF_OFF(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_FSK_STAT_TOF_OFF_SHIFT)) & GEN4PHY_FSK_STAT_TOF_OFF_MASK)
/*! @} */

/*! @name LR_PD_CFG - PHY Long Range Preamble Detect Config */
/*! @{ */

#define GEN4PHY_LR_PD_CFG_CORR_TH_MASK           (0xFFU)
#define GEN4PHY_LR_PD_CFG_CORR_TH_SHIFT          (0U)
/*! CORR_TH - Correlation threshold applicable to preamble detection; uses (0,8,8) fixed-point format. */
#define GEN4PHY_LR_PD_CFG_CORR_TH(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_CFG_CORR_TH_SHIFT)) & GEN4PHY_LR_PD_CFG_CORR_TH_MASK)

#define GEN4PHY_LR_PD_CFG_FREQ_TH_MASK           (0x1F00U)
#define GEN4PHY_LR_PD_CFG_FREQ_TH_SHIFT          (8U)
/*! FREQ_TH - Threshold used to compare CFO estimates in the LR preamble detector; uses ufix5_En5 format. */
#define GEN4PHY_LR_PD_CFG_FREQ_TH(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_CFG_FREQ_TH_SHIFT)) & GEN4PHY_LR_PD_CFG_FREQ_TH_MASK)

#define GEN4PHY_LR_PD_CFG_NO_PEAKS_MASK          (0x30000U)
#define GEN4PHY_LR_PD_CFG_NO_PEAKS_SHIFT         (16U)
/*! NO_PEAKS - Number of consecutive correlation values that have to exceed the PD correlation
 *    threshold,for the same preamble phase, to assert preamble found;
 *  0b00..2 peaks;
 *  0b01..3 peaks;
 *  0b10..4 peaks;
 *  0b11..5 peaks;
 */
#define GEN4PHY_LR_PD_CFG_NO_PEAKS(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_CFG_NO_PEAKS_SHIFT)) & GEN4PHY_LR_PD_CFG_NO_PEAKS_MASK)
/*! @} */

/*! @name LR_PD_PH - PHY Long Range Preamble Detect Phase 0..PHY Long Range Preamble Detect Phase 3 */
/*! @{ */

#define GEN4PHY_LR_PD_PH_REF0_MASK               (0x3FU)
#define GEN4PHY_LR_PD_PH_REF0_SHIFT              (0U)
/*! REF0 - Long range preamble reference waveform sample 12 (sfix6en5) */
#define GEN4PHY_LR_PD_PH_REF0(x)                 (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_PH_REF0_SHIFT)) & GEN4PHY_LR_PD_PH_REF0_MASK)

#define GEN4PHY_LR_PD_PH_REF1_MASK               (0x3F00U)
#define GEN4PHY_LR_PD_PH_REF1_SHIFT              (8U)
/*! REF1 - Long range preamble reference waveform sample 13 (sfix6en5) */
#define GEN4PHY_LR_PD_PH_REF1(x)                 (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_PH_REF1_SHIFT)) & GEN4PHY_LR_PD_PH_REF1_MASK)

#define GEN4PHY_LR_PD_PH_REF2_MASK               (0x3F0000U)
#define GEN4PHY_LR_PD_PH_REF2_SHIFT              (16U)
/*! REF2 - Long range preamble reference waveform sample 14 (sfix6en5) */
#define GEN4PHY_LR_PD_PH_REF2(x)                 (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_PH_REF2_SHIFT)) & GEN4PHY_LR_PD_PH_REF2_MASK)

#define GEN4PHY_LR_PD_PH_REF3_MASK               (0x3F000000U)
#define GEN4PHY_LR_PD_PH_REF3_SHIFT              (24U)
/*! REF3 - Long range preamble reference waveform sample 15 (sfix6en5) */
#define GEN4PHY_LR_PD_PH_REF3(x)                 (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_PH_REF3_SHIFT)) & GEN4PHY_LR_PD_PH_REF3_MASK)
/*! @} */

/* The count of GEN4PHY_LR_PD_PH */
#define GEN4PHY_LR_PD_PH_COUNT                   (4U)

/*! @name LR_PD_RO_PH - PHY Long Range Preamble Detect Read Only Phase 4..PHY Long Range Preamble Detect Read Only Phase 16 */
/*! @{ */

#define GEN4PHY_LR_PD_RO_PH_REF0_MASK            (0x3FU)
#define GEN4PHY_LR_PD_RO_PH_REF0_SHIFT           (0U)
/*! REF0 - Long range preamble reference waveform sample 64 (sfix6en5) */
#define GEN4PHY_LR_PD_RO_PH_REF0(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_RO_PH_REF0_SHIFT)) & GEN4PHY_LR_PD_RO_PH_REF0_MASK)

#define GEN4PHY_LR_PD_RO_PH_REF1_MASK            (0x3F00U)
#define GEN4PHY_LR_PD_RO_PH_REF1_SHIFT           (8U)
/*! REF1 - Long range preamble reference waveform sample 65 (sfix6en5) */
#define GEN4PHY_LR_PD_RO_PH_REF1(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_RO_PH_REF1_SHIFT)) & GEN4PHY_LR_PD_RO_PH_REF1_MASK)

#define GEN4PHY_LR_PD_RO_PH_REF2_MASK            (0x3F0000U)
#define GEN4PHY_LR_PD_RO_PH_REF2_SHIFT           (16U)
/*! REF2 - Long range preamble reference waveform sample 66 (sfix6en5) */
#define GEN4PHY_LR_PD_RO_PH_REF2(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_RO_PH_REF2_SHIFT)) & GEN4PHY_LR_PD_RO_PH_REF2_MASK)

#define GEN4PHY_LR_PD_RO_PH_REF3_MASK            (0x3F000000U)
#define GEN4PHY_LR_PD_RO_PH_REF3_SHIFT           (24U)
/*! REF3 - Long range preamble reference waveform sample 67 (sfix6en5) */
#define GEN4PHY_LR_PD_RO_PH_REF3(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_PD_RO_PH_REF3_SHIFT)) & GEN4PHY_LR_PD_RO_PH_REF3_MASK)
/*! @} */

/* The count of GEN4PHY_LR_PD_RO_PH */
#define GEN4PHY_LR_PD_RO_PH_COUNT                (13U)

/*! @name LR_AA_CFG - PHY Long Range AA Config */
/*! @{ */

#define GEN4PHY_LR_AA_CFG_AA_COR_THRESH_MASK     (0xFFU)
#define GEN4PHY_LR_AA_CFG_AA_COR_THRESH_SHIFT    (0U)
/*! AA_COR_THRESH - Threshold use to compare the correlation magnitude in the long-range AA correlator. */
#define GEN4PHY_LR_AA_CFG_AA_COR_THRESH(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_AA_CFG_AA_COR_THRESH_SHIFT)) & GEN4PHY_LR_AA_CFG_AA_COR_THRESH_MASK)

#define GEN4PHY_LR_AA_CFG_AA_HAM_THRESH_MASK     (0x3F00U)
#define GEN4PHY_LR_AA_CFG_AA_HAM_THRESH_SHIFT    (8U)
/*! AA_HAM_THRESH - Threshold use to compare the Hamming distance, between reference coded sequence
 *    and received coded sequence, in the long-range AA correlator.
 */
#define GEN4PHY_LR_AA_CFG_AA_HAM_THRESH(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_AA_CFG_AA_HAM_THRESH_SHIFT)) & GEN4PHY_LR_AA_CFG_AA_HAM_THRESH_MASK)

#define GEN4PHY_LR_AA_CFG_ACCESS_ADDR_HAM_MASK   (0x1F0000U)
#define GEN4PHY_LR_AA_CFG_ACCESS_ADDR_HAM_SHIFT  (16U)
/*! ACCESS_ADDR_HAM - Threshold use to compare the Hamming distance, between the reference AA
 *    sequence and the received Viterbi decoded AA sequence.
 */
#define GEN4PHY_LR_AA_CFG_ACCESS_ADDR_HAM(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_AA_CFG_ACCESS_ADDR_HAM_SHIFT)) & GEN4PHY_LR_AA_CFG_ACCESS_ADDR_HAM_MASK)

#define GEN4PHY_LR_AA_CFG_AA_LR_CORR_GAIN_MASK   (0x3F000000U)
#define GEN4PHY_LR_AA_CFG_AA_LR_CORR_GAIN_SHIFT  (24U)
/*! AA_LR_CORR_GAIN - AA correlator gain. Format ufix6en3. This gain is applied to soft bits from
 *    the demodulator before they are used for address search synchronization.
 */
#define GEN4PHY_LR_AA_CFG_AA_LR_CORR_GAIN(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_AA_CFG_AA_LR_CORR_GAIN_SHIFT)) & GEN4PHY_LR_AA_CFG_AA_LR_CORR_GAIN_MASK)
/*! @} */

/*! @name LR_STAT - PHY Long Range Status */
/*! @{ */

#define GEN4PHY_LR_STAT_DECODED_HAMM_DIST_MASK   (0x3FU)
#define GEN4PHY_LR_STAT_DECODED_HAMM_DIST_SHIFT  (0U)
/*! DECODED_HAMM_DIST - Hamming distance between the reference sequence and the Viterbi decoded received sequence */
#define GEN4PHY_LR_STAT_DECODED_HAMM_DIST(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_STAT_DECODED_HAMM_DIST_SHIFT)) & GEN4PHY_LR_STAT_DECODED_HAMM_DIST_MASK)

#define GEN4PHY_LR_STAT_AA_FOUND_MASK            (0x40U)
#define GEN4PHY_LR_STAT_AA_FOUND_SHIFT           (6U)
/*! AA_FOUND - Indicates that a AA detect is active for both LR and uncoded. */
#define GEN4PHY_LR_STAT_AA_FOUND(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_STAT_AA_FOUND_SHIFT)) & GEN4PHY_LR_STAT_AA_FOUND_MASK)

#define GEN4PHY_LR_STAT_CI_MASK                  (0x80U)
#define GEN4PHY_LR_STAT_CI_SHIFT                 (7U)
/*! CI - CI received. */
#define GEN4PHY_LR_STAT_CI(x)                    (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_STAT_CI_SHIFT)) & GEN4PHY_LR_STAT_CI_MASK)

#define GEN4PHY_LR_STAT_CODED_HAMM_DIST_MASK     (0x7F00U)
#define GEN4PHY_LR_STAT_CODED_HAMM_DIST_SHIFT    (8U)
/*! CODED_HAMM_DIST - Hamming distance between the coded reference sequence and the coded received sequence. */
#define GEN4PHY_LR_STAT_CODED_HAMM_DIST(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_STAT_CODED_HAMM_DIST_SHIFT)) & GEN4PHY_LR_STAT_CODED_HAMM_DIST_MASK)

#define GEN4PHY_LR_STAT_AA_CORR_MAX_MASK         (0xFF0000U)
#define GEN4PHY_LR_STAT_AA_CORR_MAX_SHIFT        (16U)
/*! AA_CORR_MAX - Indicates the AA correlation magnitude witnessed when AA match occurred */
#define GEN4PHY_LR_STAT_AA_CORR_MAX(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_STAT_AA_CORR_MAX_SHIFT)) & GEN4PHY_LR_STAT_AA_CORR_MAX_MASK)

#define GEN4PHY_LR_STAT_CMAG_MAX_MASK            (0xFF000000U)
#define GEN4PHY_LR_STAT_CMAG_MAX_SHIFT           (24U)
/*! CMAG_MAX - Indicates the maximum preamble correlation magnitude during preamble found */
#define GEN4PHY_LR_STAT_CMAG_MAX(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_LR_STAT_CMAG_MAX_SHIFT)) & GEN4PHY_LR_STAT_CMAG_MAX_MASK)
/*! @} */

/*! @name SM_CFG - PHY State Machine Config */
/*! @{ */

#define GEN4PHY_SM_CFG_ACQ_MODE_MASK             (0x3U)
#define GEN4PHY_SM_CFG_ACQ_MODE_SHIFT            (0U)
/*! ACQ_MODE - Acquisition mode for non-coded reception
 *  0b00..Reserved
 *  0b01..Use preamble and verify a correlation peak, the synch at the symbol rate as symbol timing is established by the preamble acquisition
 *  0b10..Use synch only (which may incorporate part of the preamble)
 *  0b11..Use mainly the sync detection: Use a low threshold on the preamble detector and launch the synch
 *        detection only if the preamble has shown a recent peak
 */
#define GEN4PHY_SM_CFG_ACQ_MODE(x)               (((uint32_t)(((uint32_t)(x)) << GEN4PHY_SM_CFG_ACQ_MODE_SHIFT)) & GEN4PHY_SM_CFG_ACQ_MODE_MASK)

#define GEN4PHY_SM_CFG_EN_PHY_SM_EXT_RST_MASK    (0x4U)
#define GEN4PHY_SM_CFG_EN_PHY_SM_EXT_RST_SHIFT   (2U)
/*! EN_PHY_SM_EXT_RST - Enable PHY state-machine reset on the external reset port; Reserved, should keep 0.
 *  0b0..Reset is not allowed.
 *  0b1..Reset is allowed.
 */
#define GEN4PHY_SM_CFG_EN_PHY_SM_EXT_RST(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_SM_CFG_EN_PHY_SM_EXT_RST_SHIFT)) & GEN4PHY_SM_CFG_EN_PHY_SM_EXT_RST_MASK)

#define GEN4PHY_SM_CFG_AGC_FRZ_ON_PD_FOUND_ACQ1_LR_MASK (0x8U)
#define GEN4PHY_SM_CFG_AGC_FRZ_ON_PD_FOUND_ACQ1_LR_SHIFT (3U)
/*! AGC_FRZ_ON_PD_FOUND_ACQ1_LR - Specifies AGC freeze condition for non-coded acq.1 and Bluetooth LE long range.
 *  0b0..AGC freeze on AA found.
 *  0b1..AGC freeze asserted on PD found.
 */
#define GEN4PHY_SM_CFG_AGC_FRZ_ON_PD_FOUND_ACQ1_LR(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_SM_CFG_AGC_FRZ_ON_PD_FOUND_ACQ1_LR_SHIFT)) & GEN4PHY_SM_CFG_AGC_FRZ_ON_PD_FOUND_ACQ1_LR_MASK)

#define GEN4PHY_SM_CFG_PH_BUFF_PTR_SYM_MASK      (0x30U)
#define GEN4PHY_SM_CFG_PH_BUFF_PTR_SYM_SHIFT     (4U)
/*! PH_BUFF_PTR_SYM - Phase buffer size to demodulator, long range only. */
#define GEN4PHY_SM_CFG_PH_BUFF_PTR_SYM(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_SM_CFG_PH_BUFF_PTR_SYM_SHIFT)) & GEN4PHY_SM_CFG_PH_BUFF_PTR_SYM_MASK)

#define GEN4PHY_SM_CFG_EARLY_PD_TIMEOUT_MASK     (0x3F00U)
#define GEN4PHY_SM_CFG_EARLY_PD_TIMEOUT_SHIFT    (8U)
/*! EARLY_PD_TIMEOUT - Time-out used to reset the AGC state-machine for the eventuality that an "PD
 *    found early" , expressed in number of sample clock cycles. Event occurs but it is not followed
 *    by an "PD found" event
 */
#define GEN4PHY_SM_CFG_EARLY_PD_TIMEOUT(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_SM_CFG_EARLY_PD_TIMEOUT_SHIFT)) & GEN4PHY_SM_CFG_EARLY_PD_TIMEOUT_MASK)

#define GEN4PHY_SM_CFG_AA_TIMEOUT_UNCODED_MASK   (0x3FF0000U)
#define GEN4PHY_SM_CFG_AA_TIMEOUT_UNCODED_SHIFT  (16U)
/*! AA_TIMEOUT_UNCODED - Time-out value for access address search for uncoded packets, expressed in number of sample clock cycles */
#define GEN4PHY_SM_CFG_AA_TIMEOUT_UNCODED(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_SM_CFG_AA_TIMEOUT_UNCODED_SHIFT)) & GEN4PHY_SM_CFG_AA_TIMEOUT_UNCODED_MASK)
/*! @} */

/*! @name MISC - PHY Misc Config */
/*! @{ */

#define GEN4PHY_MISC_RSSI_CORR_TH_MASK           (0xFFU)
#define GEN4PHY_MISC_RSSI_CORR_TH_SHIFT          (0U)
/*! RSSI_CORR_TH - Threshold use to compare a correlation magnitude value, computed in the
 *    acquisition block, in order to determine the correlation flag value provided by the PHY to the LQI
 *    computation block. Format is ufix8_En8
 */
#define GEN4PHY_MISC_RSSI_CORR_TH(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_MISC_RSSI_CORR_TH_SHIFT)) & GEN4PHY_MISC_RSSI_CORR_TH_MASK)

#define GEN4PHY_MISC_DMA_PAGE_SEL_MASK           (0x700U)
#define GEN4PHY_MISC_DMA_PAGE_SEL_SHIFT          (8U)
/*! DMA_PAGE_SEL - Select which DMA page is send out
 *  0b000..Select DMA PAGE 0 for M3C with cfo;
 *  0b001..Select DMA PAGE 1 for M3C with magnitude;
 *  0b010..Select DMA PAGE 2 for un-coded;
 *  0b011..Select DMA PAGE 3 for Long Range Preamble Detect;
 *  0b100..Select DMA PAGE 4 for Long Range AA Detect;
 */
#define GEN4PHY_MISC_DMA_PAGE_SEL(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_MISC_DMA_PAGE_SEL_SHIFT)) & GEN4PHY_MISC_DMA_PAGE_SEL_MASK)

#define GEN4PHY_MISC_ECO1_RSVD_MASK              (0xF800U)
#define GEN4PHY_MISC_ECO1_RSVD_SHIFT             (11U)
/*! ECO1_RSVD - Reserved . Must be programed as reset value 0. */
#define GEN4PHY_MISC_ECO1_RSVD(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_MISC_ECO1_RSVD_SHIFT)) & GEN4PHY_MISC_ECO1_RSVD_MASK)

#define GEN4PHY_MISC_PHY_CLK_CTRL_MASK           (0x3FF0000U)
#define GEN4PHY_MISC_PHY_CLK_CTRL_SHIFT          (16U)
/*! PHY_CLK_CTRL - Enables various clock gating features. Bits are individually decoded, so any combination is allowable. */
#define GEN4PHY_MISC_PHY_CLK_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_MISC_PHY_CLK_CTRL_SHIFT)) & GEN4PHY_MISC_PHY_CLK_CTRL_MASK)

#define GEN4PHY_MISC_ECO2_RSVD_MASK              (0x3C000000U)
#define GEN4PHY_MISC_ECO2_RSVD_SHIFT             (26U)
/*! ECO2_RSVD - Reserved */
#define GEN4PHY_MISC_ECO2_RSVD(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_MISC_ECO2_RSVD_SHIFT)) & GEN4PHY_MISC_ECO2_RSVD_MASK)

#define GEN4PHY_MISC_DTEST_MUX_EN_MASK           (0x40000000U)
#define GEN4PHY_MISC_DTEST_MUX_EN_SHIFT          (30U)
/*! DTEST_MUX_EN - Reserved . Should be programed as reset value 0. */
#define GEN4PHY_MISC_DTEST_MUX_EN(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_MISC_DTEST_MUX_EN_SHIFT)) & GEN4PHY_MISC_DTEST_MUX_EN_MASK)

#define GEN4PHY_MISC_PHY_CLK_ON_MASK             (0x80000000U)
#define GEN4PHY_MISC_PHY_CLK_ON_SHIFT            (31U)
/*! PHY_CLK_ON - Force PHY clock ON */
#define GEN4PHY_MISC_PHY_CLK_ON(x)               (((uint32_t)(((uint32_t)(x)) << GEN4PHY_MISC_PHY_CLK_ON_SHIFT)) & GEN4PHY_MISC_PHY_CLK_ON_MASK)
/*! @} */

/*! @name STAT0 - PHY Status 0 */
/*! @{ */

#define GEN4PHY_STAT0_PD_FOUND_MASK              (0x1U)
#define GEN4PHY_STAT0_PD_FOUND_SHIFT             (0U)
/*! PD_FOUND - PD_FOUND for LR or uncoded */
#define GEN4PHY_STAT0_PD_FOUND(x)                (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT0_PD_FOUND_SHIFT)) & GEN4PHY_STAT0_PD_FOUND_MASK)

#define GEN4PHY_STAT0_LR_DET_FLAG_MASK           (0x2U)
#define GEN4PHY_STAT0_LR_DET_FLAG_SHIFT          (1U)
/*! LR_DET_FLAG - Indicates Bluetooth LE long range was detected */
#define GEN4PHY_STAT0_LR_DET_FLAG(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT0_LR_DET_FLAG_SHIFT)) & GEN4PHY_STAT0_LR_DET_FLAG_MASK)

#define GEN4PHY_STAT0_AA_MATCHED_MASK            (0x4U)
#define GEN4PHY_STAT0_AA_MATCHED_SHIFT           (2U)
/*! AA_MATCHED - Indicates AA was matched for LR or uncoded */
#define GEN4PHY_STAT0_AA_MATCHED(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT0_AA_MATCHED_SHIFT)) & GEN4PHY_STAT0_AA_MATCHED_MASK)

#define GEN4PHY_STAT0_AA_FOUND_ID_MASK           (0x38U)
#define GEN4PHY_STAT0_AA_FOUND_ID_SHIFT          (3U)
/*! AA_FOUND_ID - Indicates which AA was matched for LR and uncode
 *  0b000..uncoded address 0 matched
 *  0b001..uncoded address 1 matched
 *  0b010..uncoded address 2 matched
 *  0b011..uncoded address 3 matched
 *  0b100..long range address matched
 */
#define GEN4PHY_STAT0_AA_FOUND_ID(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT0_AA_FOUND_ID_SHIFT)) & GEN4PHY_STAT0_AA_FOUND_ID_MASK)

#define GEN4PHY_STAT0_DATA_RATE_MASK             (0xC0U)
#define GEN4PHY_STAT0_DATA_RATE_SHIFT            (6U)
/*! DATA_RATE - Indicates the data rate of received bit
 *  0b00..1Mbps
 *  0b01..2Mbps
 *  0b10..125kbps
 *  0b11..500kbps
 */
#define GEN4PHY_STAT0_DATA_RATE(x)               (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT0_DATA_RATE_SHIFT)) & GEN4PHY_STAT0_DATA_RATE_MASK)

#define GEN4PHY_STAT0_FRAC_MASK                  (0x3F00U)
#define GEN4PHY_STAT0_FRAC_SHIFT                 (8U)
/*! FRAC - Indicates the fractional timing estimate determined in the acquisition block. Format is
 *    sfix6_en5(sign extend from sfix3_En2).
 */
#define GEN4PHY_STAT0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT0_FRAC_SHIFT)) & GEN4PHY_STAT0_FRAC_MASK)

#define GEN4PHY_STAT0_CFO_EST_MASK               (0x3FF0000U)
#define GEN4PHY_STAT0_CFO_EST_SHIFT              (16U)
/*! CFO_EST - Indicates the currently estimated CFO. Format is sfix10_en9(sign extend from sfix8_en9) */
#define GEN4PHY_STAT0_CFO_EST(x)                 (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT0_CFO_EST_SHIFT)) & GEN4PHY_STAT0_CFO_EST_MASK)
/*! @} */

/*! @name STAT1 - PHY Status 1 */
/*! @{ */

#define GEN4PHY_STAT1_AA_BITS_MASK               (0xFFFFFFFFU)
#define GEN4PHY_STAT1_AA_BITS_SHIFT              (0U)
/*! AA_BITS - AA bits either received or programed */
#define GEN4PHY_STAT1_AA_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT1_AA_BITS_SHIFT)) & GEN4PHY_STAT1_AA_BITS_MASK)
/*! @} */

/*! @name STAT2 - PHY Status 2 */
/*! @{ */

#define GEN4PHY_STAT2_CNT_ANT_SW_MASK            (0x3U)
#define GEN4PHY_STAT2_CNT_ANT_SW_SHIFT           (0U)
/*! CNT_ANT_SW - Count of uncoded ANT switch event when FAD was enabled. */
#define GEN4PHY_STAT2_CNT_ANT_SW(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT2_CNT_ANT_SW_SHIFT)) & GEN4PHY_STAT2_CNT_ANT_SW_MASK)

#define GEN4PHY_STAT2_CNT_UNCAA_TIMEOUT_MASK     (0xCU)
#define GEN4PHY_STAT2_CNT_UNCAA_TIMEOUT_SHIFT    (2U)
/*! CNT_UNCAA_TIMEOUT - Count of uncoded AA search timeout event */
#define GEN4PHY_STAT2_CNT_UNCAA_TIMEOUT(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT2_CNT_UNCAA_TIMEOUT_SHIFT)) & GEN4PHY_STAT2_CNT_UNCAA_TIMEOUT_MASK)

#define GEN4PHY_STAT2_CNT_LRAA_TIMEOUT_MASK      (0x30U)
#define GEN4PHY_STAT2_CNT_LRAA_TIMEOUT_SHIFT     (4U)
/*! CNT_LRAA_TIMEOUT - Count of long range AA search timeout event */
#define GEN4PHY_STAT2_CNT_LRAA_TIMEOUT(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT2_CNT_LRAA_TIMEOUT_SHIFT)) & GEN4PHY_STAT2_CNT_LRAA_TIMEOUT_MASK)

#define GEN4PHY_STAT2_CNT_AACI_TIMEOUT_MASK      (0xC0U)
#define GEN4PHY_STAT2_CNT_AACI_TIMEOUT_SHIFT     (6U)
/*! CNT_AACI_TIMEOUT - Count of long range AACI detect timeout event */
#define GEN4PHY_STAT2_CNT_AACI_TIMEOUT(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT2_CNT_AACI_TIMEOUT_SHIFT)) & GEN4PHY_STAT2_CNT_AACI_TIMEOUT_MASK)

#define GEN4PHY_STAT2_CNT_AGC_RST_MASK           (0x300U)
#define GEN4PHY_STAT2_CNT_AGC_RST_SHIFT          (8U)
/*! CNT_AGC_RST - Count of AGC soft reset event */
#define GEN4PHY_STAT2_CNT_AGC_RST(x)             (((uint32_t)(((uint32_t)(x)) << GEN4PHY_STAT2_CNT_AGC_RST_SHIFT)) & GEN4PHY_STAT2_CNT_AGC_RST_MASK)
/*! @} */

/*! @name PREPHY_MISC - PHY PrePHY Misc Config */
/*! @{ */

#define GEN4PHY_PREPHY_MISC_BUFF_PTR_LR_MASK     (0x1FU)
#define GEN4PHY_PREPHY_MISC_BUFF_PTR_LR_SHIFT    (0U)
/*! BUFF_PTR_LR - Pointer to the PrePHY IQ buffer for the reception of the long-range packets. */
#define GEN4PHY_PREPHY_MISC_BUFF_PTR_LR(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_PREPHY_MISC_BUFF_PTR_LR_SHIFT)) & GEN4PHY_PREPHY_MISC_BUFF_PTR_LR_MASK)

#define GEN4PHY_PREPHY_MISC_BUFF_PTR_GFSK_MASK   (0x1F00U)
#define GEN4PHY_PREPHY_MISC_BUFF_PTR_GFSK_SHIFT  (8U)
/*! BUFF_PTR_GFSK - Pointer to the PrePHY IQ buffer for the reception of the uncoded packets. */
#define GEN4PHY_PREPHY_MISC_BUFF_PTR_GFSK(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_PREPHY_MISC_BUFF_PTR_GFSK_SHIFT)) & GEN4PHY_PREPHY_MISC_BUFF_PTR_GFSK_MASK)
/*! @} */

/*! @name DMD_CTRL0 - PHY Demodulator Control 0 */
/*! @{ */

#define GEN4PHY_DMD_CTRL0_TED_ACT_WIN_MASK       (0x3U)
#define GEN4PHY_DMD_CTRL0_TED_ACT_WIN_SHIFT      (0U)
/*! TED_ACT_WIN - Active window size for the time tracking mechanism, expressed in symbols. */
#define GEN4PHY_DMD_CTRL0_TED_ACT_WIN(x)         (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_TED_ACT_WIN_SHIFT)) & GEN4PHY_DMD_CTRL0_TED_ACT_WIN_MASK)

#define GEN4PHY_DMD_CTRL0_FED_ACT_WIN_MASK       (0x300U)
#define GEN4PHY_DMD_CTRL0_FED_ACT_WIN_SHIFT      (8U)
/*! FED_ACT_WIN - Active window size for the frequency tracking mechanism, expressed in symbols. */
#define GEN4PHY_DMD_CTRL0_FED_ACT_WIN(x)         (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_FED_ACT_WIN_SHIFT)) & GEN4PHY_DMD_CTRL0_FED_ACT_WIN_MASK)

#define GEN4PHY_DMD_CTRL0_DREP_SCALE_FREQ_MASK   (0xF0000U)
#define GEN4PHY_DMD_CTRL0_DREP_SCALE_FREQ_SHIFT  (16U)
/*! DREP_SCALE_FREQ - Frequency domain signal scaling factor used by the de-repeater. */
#define GEN4PHY_DMD_CTRL0_DREP_SCALE_FREQ(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_DREP_SCALE_FREQ_SHIFT)) & GEN4PHY_DMD_CTRL0_DREP_SCALE_FREQ_MASK)

#define GEN4PHY_DMD_CTRL0_REPEAT_FACTOR_MASK     (0x700000U)
#define GEN4PHY_DMD_CTRL0_REPEAT_FACTOR_SHIFT    (20U)
/*! REPEAT_FACTOR - Repetition factor used by the de-repeater. */
#define GEN4PHY_DMD_CTRL0_REPEAT_FACTOR(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_REPEAT_FACTOR_SHIFT)) & GEN4PHY_DMD_CTRL0_REPEAT_FACTOR_MASK)

#define GEN4PHY_DMD_CTRL0_FED_ERR_SCALE_MASK     (0x3800000U)
#define GEN4PHY_DMD_CTRL0_FED_ERR_SCALE_SHIFT    (23U)
/*! FED_ERR_SCALE - Scaling factor used by the frequency tracking loop. */
#define GEN4PHY_DMD_CTRL0_FED_ERR_SCALE(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_FED_ERR_SCALE_SHIFT)) & GEN4PHY_DMD_CTRL0_FED_ERR_SCALE_MASK)

#define GEN4PHY_DMD_CTRL0_TERR_TRK_EN_MASK       (0x4000000U)
#define GEN4PHY_DMD_CTRL0_TERR_TRK_EN_SHIFT      (26U)
/*! TERR_TRK_EN - Enables time tracking in the demodulator. */
#define GEN4PHY_DMD_CTRL0_TERR_TRK_EN(x)         (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_TERR_TRK_EN_SHIFT)) & GEN4PHY_DMD_CTRL0_TERR_TRK_EN_MASK)

#define GEN4PHY_DMD_CTRL0_FERR_TRK_EN_MASK       (0x8000000U)
#define GEN4PHY_DMD_CTRL0_FERR_TRK_EN_SHIFT      (27U)
/*! FERR_TRK_EN - Enables frequency tracking in the demodulator. */
#define GEN4PHY_DMD_CTRL0_FERR_TRK_EN(x)         (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_FERR_TRK_EN_SHIFT)) & GEN4PHY_DMD_CTRL0_FERR_TRK_EN_MASK)

#define GEN4PHY_DMD_CTRL0_DREP_SINE_EN_MASK      (0x10000000U)
#define GEN4PHY_DMD_CTRL0_DREP_SINE_EN_SHIFT     (28U)
/*! DREP_SINE_EN - Flag used to enable the non-linear operation in the de-repeater. */
#define GEN4PHY_DMD_CTRL0_DREP_SINE_EN(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_DREP_SINE_EN_SHIFT)) & GEN4PHY_DMD_CTRL0_DREP_SINE_EN_MASK)

#define GEN4PHY_DMD_CTRL0_DEMOD_MOD_MASK         (0x60000000U)
#define GEN4PHY_DMD_CTRL0_DEMOD_MOD_SHIFT        (29U)
/*! DEMOD_MOD - Determines the number of taps used by the demodulator correlators;
 *  0b00..use 12 taps
 *  0b01..use 4 taps
 *  0b10..use 7 taps
 *  0b11..use 13 taps
 */
#define GEN4PHY_DMD_CTRL0_DEMOD_MOD(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL0_DEMOD_MOD_SHIFT)) & GEN4PHY_DMD_CTRL0_DEMOD_MOD_MASK)
/*! @} */

/*! @name DMD_CTRL1 - PHY Demodulator Control 1 */
/*! @{ */

#define GEN4PHY_DMD_CTRL1_FED_IDLE_WIN_MASK      (0x3FFU)
#define GEN4PHY_DMD_CTRL1_FED_IDLE_WIN_SHIFT     (0U)
/*! FED_IDLE_WIN - Idle window size for the frequency tracking mechanism, expressed in symbols. */
#define GEN4PHY_DMD_CTRL1_FED_IDLE_WIN(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL1_FED_IDLE_WIN_SHIFT)) & GEN4PHY_DMD_CTRL1_FED_IDLE_WIN_MASK)

#define GEN4PHY_DMD_CTRL1_TED_ERR_SCALE_MASK     (0x3C00U)
#define GEN4PHY_DMD_CTRL1_TED_ERR_SCALE_SHIFT    (10U)
/*! TED_ERR_SCALE - Scaling factor used by the time tracking loop. */
#define GEN4PHY_DMD_CTRL1_TED_ERR_SCALE(x)       (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL1_TED_ERR_SCALE_SHIFT)) & GEN4PHY_DMD_CTRL1_TED_ERR_SCALE_MASK)

#define GEN4PHY_DMD_CTRL1_FED_IMM_MEAS_EN_MASK   (0x8000U)
#define GEN4PHY_DMD_CTRL1_FED_IMM_MEAS_EN_SHIFT  (15U)
/*! FED_IMM_MEAS_EN - Specifies whether the frequency tracking starts with an active window;
 *  0b0..start with idle window
 *  0b1..start with active window
 */
#define GEN4PHY_DMD_CTRL1_FED_IMM_MEAS_EN(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL1_FED_IMM_MEAS_EN_SHIFT)) & GEN4PHY_DMD_CTRL1_FED_IMM_MEAS_EN_MASK)

#define GEN4PHY_DMD_CTRL1_TED_IDLE_WIN_MASK      (0x3FF0000U)
#define GEN4PHY_DMD_CTRL1_TED_IDLE_WIN_SHIFT     (16U)
/*! TED_IDLE_WIN - Idle window size for the time tracking mechanism, expressed in symbols. */
#define GEN4PHY_DMD_CTRL1_TED_IDLE_WIN(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL1_TED_IDLE_WIN_SHIFT)) & GEN4PHY_DMD_CTRL1_TED_IDLE_WIN_MASK)

#define GEN4PHY_DMD_CTRL1_TTRK_INT_RANGE_MASK    (0x3C000000U)
#define GEN4PHY_DMD_CTRL1_TTRK_INT_RANGE_SHIFT   (26U)
/*! TTRK_INT_RANGE - Timing error correction interpolation range, expressed in samples. The value must equal or bigger than 1. */
#define GEN4PHY_DMD_CTRL1_TTRK_INT_RANGE(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL1_TTRK_INT_RANGE_SHIFT)) & GEN4PHY_DMD_CTRL1_TTRK_INT_RANGE_MASK)

#define GEN4PHY_DMD_CTRL1_TED_IMM_MEAS_EN_MASK   (0x80000000U)
#define GEN4PHY_DMD_CTRL1_TED_IMM_MEAS_EN_SHIFT  (31U)
/*! TED_IMM_MEAS_EN - Specifies whether the time tracking starts with an active window;
 *  0b0..start with idle window
 *  0b1..start with active window
 */
#define GEN4PHY_DMD_CTRL1_TED_IMM_MEAS_EN(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL1_TED_IMM_MEAS_EN_SHIFT)) & GEN4PHY_DMD_CTRL1_TED_IMM_MEAS_EN_MASK)
/*! @} */

/*! @name DMD_CTRL2 - PHY Demodulator Control 2 */
/*! @{ */

#define GEN4PHY_DMD_CTRL2_WAIT_DMD_LR_ADJ_MASK   (0xFU)
#define GEN4PHY_DMD_CTRL2_WAIT_DMD_LR_ADJ_SHIFT  (0U)
/*! WAIT_DMD_LR_ADJ - Reserved. Must be programed as reset value 1. */
#define GEN4PHY_DMD_CTRL2_WAIT_DMD_LR_ADJ(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL2_WAIT_DMD_LR_ADJ_SHIFT)) & GEN4PHY_DMD_CTRL2_WAIT_DMD_LR_ADJ_MASK)

#define GEN4PHY_DMD_CTRL2_WAIT_VIA_AFTER_AA_ADJ_MASK (0xF0U)
#define GEN4PHY_DMD_CTRL2_WAIT_VIA_AFTER_AA_ADJ_SHIFT (4U)
/*! WAIT_VIA_AFTER_AA_ADJ - Reserved. Must be programed as reset value 1. */
#define GEN4PHY_DMD_CTRL2_WAIT_VIA_AFTER_AA_ADJ(x) (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL2_WAIT_VIA_AFTER_AA_ADJ_SHIFT)) & GEN4PHY_DMD_CTRL2_WAIT_VIA_AFTER_AA_ADJ_MASK)

#define GEN4PHY_DMD_CTRL2_WAIT_DMD_CLKEN_ADJ_MASK (0xF00U)
#define GEN4PHY_DMD_CTRL2_WAIT_DMD_CLKEN_ADJ_SHIFT (8U)
/*! WAIT_DMD_CLKEN_ADJ - Reserved. Must be programed as reset value 1. */
#define GEN4PHY_DMD_CTRL2_WAIT_DMD_CLKEN_ADJ(x)  (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_CTRL2_WAIT_DMD_CLKEN_ADJ_SHIFT)) & GEN4PHY_DMD_CTRL2_WAIT_DMD_CLKEN_ADJ_MASK)
/*! @} */

/*! @name DMD_WAVE_REG0 - PHY Demodulator Wave0 Register 0..PHY Demodulator Wave7 Register 0 */
/*! @{ */

#define GEN4PHY_DMD_WAVE_REG0_SMPL0_MASK         (0x3FU)
#define GEN4PHY_DMD_WAVE_REG0_SMPL0_SHIFT        (0U)
/*! SMPL0 - Demodulator waveform 7 sample 0 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG0_SMPL0(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG0_SMPL0_SHIFT)) & GEN4PHY_DMD_WAVE_REG0_SMPL0_MASK)

#define GEN4PHY_DMD_WAVE_REG0_SMPL1_MASK         (0xFC0U)
#define GEN4PHY_DMD_WAVE_REG0_SMPL1_SHIFT        (6U)
/*! SMPL1 - Demodulator waveform 7 sample 1 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG0_SMPL1(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG0_SMPL1_SHIFT)) & GEN4PHY_DMD_WAVE_REG0_SMPL1_MASK)

#define GEN4PHY_DMD_WAVE_REG0_SMPL2_MASK         (0x3F000U)
#define GEN4PHY_DMD_WAVE_REG0_SMPL2_SHIFT        (12U)
/*! SMPL2 - Demodulator waveform 7 sample 2 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG0_SMPL2(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG0_SMPL2_SHIFT)) & GEN4PHY_DMD_WAVE_REG0_SMPL2_MASK)

#define GEN4PHY_DMD_WAVE_REG0_SMPL3_MASK         (0xFC0000U)
#define GEN4PHY_DMD_WAVE_REG0_SMPL3_SHIFT        (18U)
/*! SMPL3 - Demodulator waveform 7 sample 3 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG0_SMPL3(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG0_SMPL3_SHIFT)) & GEN4PHY_DMD_WAVE_REG0_SMPL3_MASK)

#define GEN4PHY_DMD_WAVE_REG0_SMPL4_MASK         (0x3F000000U)
#define GEN4PHY_DMD_WAVE_REG0_SMPL4_SHIFT        (24U)
/*! SMPL4 - Demodulator waveform 7 sample 4 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG0_SMPL4(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG0_SMPL4_SHIFT)) & GEN4PHY_DMD_WAVE_REG0_SMPL4_MASK)
/*! @} */

/* The count of GEN4PHY_DMD_WAVE_REG0 */
#define GEN4PHY_DMD_WAVE_REG0_COUNT              (8U)

/*! @name DMD_WAVE_REG1 - PHY Demodulator Wave0 Register 1..PHY Demodulator Wave7 Register 1 */
/*! @{ */

#define GEN4PHY_DMD_WAVE_REG1_SMPL5_MASK         (0x3FU)
#define GEN4PHY_DMD_WAVE_REG1_SMPL5_SHIFT        (0U)
/*! SMPL5 - Demodulator waveform 7 sample 5 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG1_SMPL5(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG1_SMPL5_SHIFT)) & GEN4PHY_DMD_WAVE_REG1_SMPL5_MASK)

#define GEN4PHY_DMD_WAVE_REG1_SMPL6_MASK         (0xFC0U)
#define GEN4PHY_DMD_WAVE_REG1_SMPL6_SHIFT        (6U)
/*! SMPL6 - Demodulator waveform 7 sample 6 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG1_SMPL6(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG1_SMPL6_SHIFT)) & GEN4PHY_DMD_WAVE_REG1_SMPL6_MASK)

#define GEN4PHY_DMD_WAVE_REG1_SMPL7_MASK         (0x3F000U)
#define GEN4PHY_DMD_WAVE_REG1_SMPL7_SHIFT        (12U)
/*! SMPL7 - Demodulator waveform 7 sample 7 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG1_SMPL7(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG1_SMPL7_SHIFT)) & GEN4PHY_DMD_WAVE_REG1_SMPL7_MASK)

#define GEN4PHY_DMD_WAVE_REG1_SMPL8_MASK         (0xFC0000U)
#define GEN4PHY_DMD_WAVE_REG1_SMPL8_SHIFT        (18U)
/*! SMPL8 - Demodulator waveform 7 sample 8 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG1_SMPL8(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG1_SMPL8_SHIFT)) & GEN4PHY_DMD_WAVE_REG1_SMPL8_MASK)

#define GEN4PHY_DMD_WAVE_REG1_SMPL9_MASK         (0x3F000000U)
#define GEN4PHY_DMD_WAVE_REG1_SMPL9_SHIFT        (24U)
/*! SMPL9 - Demodulator waveform 7 sample 9 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG1_SMPL9(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG1_SMPL9_SHIFT)) & GEN4PHY_DMD_WAVE_REG1_SMPL9_MASK)
/*! @} */

/* The count of GEN4PHY_DMD_WAVE_REG1 */
#define GEN4PHY_DMD_WAVE_REG1_COUNT              (8U)

/*! @name DMD_WAVE_REG2 - PHY Demodulator Wave0 Register 2..PHY Demodulator Wave7 Register 2 */
/*! @{ */

#define GEN4PHY_DMD_WAVE_REG2_SMPL10_MASK        (0x3FU)
#define GEN4PHY_DMD_WAVE_REG2_SMPL10_SHIFT       (0U)
/*! SMPL10 - Demodulator waveform 7 sample 10 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG2_SMPL10(x)          (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG2_SMPL10_SHIFT)) & GEN4PHY_DMD_WAVE_REG2_SMPL10_MASK)

#define GEN4PHY_DMD_WAVE_REG2_SMPL11_MASK        (0xFC0U)
#define GEN4PHY_DMD_WAVE_REG2_SMPL11_SHIFT       (6U)
/*! SMPL11 - Demodulator waveform 7 sample 11 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG2_SMPL11(x)          (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG2_SMPL11_SHIFT)) & GEN4PHY_DMD_WAVE_REG2_SMPL11_MASK)

#define GEN4PHY_DMD_WAVE_REG2_SMPL12_MASK        (0x3F000U)
#define GEN4PHY_DMD_WAVE_REG2_SMPL12_SHIFT       (12U)
/*! SMPL12 - Demodulator waveform 7 sample 12 (sfix6en5) */
#define GEN4PHY_DMD_WAVE_REG2_SMPL12(x)          (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMD_WAVE_REG2_SMPL12_SHIFT)) & GEN4PHY_DMD_WAVE_REG2_SMPL12_MASK)
/*! @} */

/* The count of GEN4PHY_DMD_WAVE_REG2 */
#define GEN4PHY_DMD_WAVE_REG2_COUNT              (8U)

/*! @name DMDAA_CTRL - PHY Demodulator Based SFD Confirmation control register. */
/*! @{ */

#define GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_LP_MASK    (0x7U)
#define GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_LP_SHIFT   (0U)
/*! DMDAA_HAMM_LP - Maximum hamming distance from the given AA pattern that may still be accepted as
 *    a match in low power case; valid range [0,7].
 */
#define GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_LP(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_LP_SHIFT)) & GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_LP_MASK)

#define GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_HP_MASK    (0x38U)
#define GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_HP_SHIFT   (3U)
/*! DMDAA_HAMM_HP - Maximum hamming distance from the given AA pattern that may still be accepted as
 *    a match in high power case; valid range [0,7].
 */
#define GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_HP(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_HP_SHIFT)) & GEN4PHY_DMDAA_CTRL_DMDAA_HAMM_HP_MASK)

#define GEN4PHY_DMDAA_CTRL_HIPOW_DIS_OVRD_MASK   (0x40U)
#define GEN4PHY_DMDAA_CTRL_HIPOW_DIS_OVRD_SHIFT  (6U)
/*! HIPOW_DIS_OVRD - Override the feature: disable DMDAA when power sensitivity is higher;
 *  0b0..disable override, DMDAA disabled when power is high
 *  0b1..enable override, DMDAA enabled when power is high
 */
#define GEN4PHY_DMDAA_CTRL_HIPOW_DIS_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMDAA_CTRL_HIPOW_DIS_OVRD_SHIFT)) & GEN4PHY_DMDAA_CTRL_HIPOW_DIS_OVRD_MASK)

#define GEN4PHY_DMDAA_CTRL_DMDAA_EN_MASK         (0x80U)
#define GEN4PHY_DMDAA_CTRL_DMDAA_EN_SHIFT        (7U)
/*! DMDAA_EN - Enables Demodulator Based SFD Confirmation;
 *  0b0..disable
 *  0b1..enable
 */
#define GEN4PHY_DMDAA_CTRL_DMDAA_EN(x)           (((uint32_t)(((uint32_t)(x)) << GEN4PHY_DMDAA_CTRL_DMDAA_EN_SHIFT)) & GEN4PHY_DMDAA_CTRL_DMDAA_EN_MASK)
/*! @} */

/*! @name RTT_STAT - High resolution Time-Of-Flight calculation Status. */
/*! @{ */

#define GEN4PHY_RTT_STAT_RTT_CFO_MASK            (0xFFFFU)
#define GEN4PHY_RTT_STAT_RTT_CFO_SHIFT           (0U)
/*! RTT_CFO - The high accuracy CFO computed by the HARTT block through the CORDIC algorithm. */
#define GEN4PHY_RTT_STAT_RTT_CFO(x)              (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_STAT_RTT_CFO_SHIFT)) & GEN4PHY_RTT_STAT_RTT_CFO_MASK)

#define GEN4PHY_RTT_STAT_RTT_P_DELTA_MASK        (0x3FF0000U)
#define GEN4PHY_RTT_STAT_RTT_P_DELTA_SHIFT       (16U)
/*! RTT_P_DELTA - Difference between the squared correlation magnitude values, pm-pp provided by the HARTT block, format is sfix10En9. */
#define GEN4PHY_RTT_STAT_RTT_P_DELTA(x)          (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_STAT_RTT_P_DELTA_SHIFT)) & GEN4PHY_RTT_STAT_RTT_P_DELTA_MASK)

#define GEN4PHY_RTT_STAT_RTT_DIST_SAT_MASK       (0xC000000U)
#define GEN4PHY_RTT_STAT_RTT_DIST_SAT_SHIFT      (26U)
/*! RTT_DIST_SAT - Computed Hamming distance saturated to 2 bits, format is ufix2. */
#define GEN4PHY_RTT_STAT_RTT_DIST_SAT(x)         (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_STAT_RTT_DIST_SAT_SHIFT)) & GEN4PHY_RTT_STAT_RTT_DIST_SAT_MASK)

#define GEN4PHY_RTT_STAT_RTT_INT_ADJ_MASK        (0x30000000U)
#define GEN4PHY_RTT_STAT_RTT_INT_ADJ_SHIFT       (28U)
/*! RTT_INT_ADJ - An integer adjustment of the timing which takes a value different of 0 when the
 *    early-late mechanism in the HARTT block chooses a peak different of the one chosen in the
 *    acquisition module (possible values are {-1,0,+1}).
 */
#define GEN4PHY_RTT_STAT_RTT_INT_ADJ(x)          (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_STAT_RTT_INT_ADJ_SHIFT)) & GEN4PHY_RTT_STAT_RTT_INT_ADJ_MASK)

#define GEN4PHY_RTT_STAT_RTT_FOUND_MASK          (0x40000000U)
#define GEN4PHY_RTT_STAT_RTT_FOUND_SHIFT         (30U)
/*! RTT_FOUND - Flag that indicates that the HARTT operation is done and a valid PN pattern was detected. */
#define GEN4PHY_RTT_STAT_RTT_FOUND(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_STAT_RTT_FOUND_SHIFT)) & GEN4PHY_RTT_STAT_RTT_FOUND_MASK)
/*! @} */

/*! @name RTT_CTRL - PHY RTT control register. */
/*! @{ */

#define GEN4PHY_RTT_CTRL_HA_RTT_THRESHOLD_MASK   (0x1FFU)
#define GEN4PHY_RTT_CTRL_HA_RTT_THRESHOLD_SHIFT  (0U)
/*! HA_RTT_THRESHOLD - threshold used to validate a HA RTT result. */
#define GEN4PHY_RTT_CTRL_HA_RTT_THRESHOLD(x)     (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_CTRL_HA_RTT_THRESHOLD_SHIFT)) & GEN4PHY_RTT_CTRL_HA_RTT_THRESHOLD_MASK)

#define GEN4PHY_RTT_CTRL_FIRST_PDU_BIT_MASK      (0x1000U)
#define GEN4PHY_RTT_CTRL_FIRST_PDU_BIT_SHIFT     (12U)
/*! FIRST_PDU_BIT - Programmed by software - used for regular packets high accuracy RTT; First PDU bit gets programmed into this field */
#define GEN4PHY_RTT_CTRL_FIRST_PDU_BIT(x)        (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_CTRL_FIRST_PDU_BIT_SHIFT)) & GEN4PHY_RTT_CTRL_FIRST_PDU_BIT_MASK)

#define GEN4PHY_RTT_CTRL_RTT_SEQ_LEN_MASK        (0x2000U)
#define GEN4PHY_RTT_CTRL_RTT_SEQ_LEN_SHIFT       (13U)
/*! RTT_SEQ_LEN - Allow PHY Demodulation during RTT computation */
#define GEN4PHY_RTT_CTRL_RTT_SEQ_LEN(x)          (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_CTRL_RTT_SEQ_LEN_SHIFT)) & GEN4PHY_RTT_CTRL_RTT_SEQ_LEN_MASK)

#define GEN4PHY_RTT_CTRL_OVERRD_PROGR_AA_MASK    (0x4000U)
#define GEN4PHY_RTT_CTRL_OVERRD_PROGR_AA_SHIFT   (14U)
/*! OVERRD_PROGR_AA - Enables overriding the programmed AA bits with the PN sequence used by RTT; */
#define GEN4PHY_RTT_CTRL_OVERRD_PROGR_AA(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_CTRL_OVERRD_PROGR_AA_SHIFT)) & GEN4PHY_RTT_CTRL_OVERRD_PROGR_AA_MASK)

#define GEN4PHY_RTT_CTRL_EN_HIGH_ACC_RTT_MASK    (0x8000U)
#define GEN4PHY_RTT_CTRL_EN_HIGH_ACC_RTT_SHIFT   (15U)
/*! EN_HIGH_ACC_RTT - enables the use of the HA RTT block; */
#define GEN4PHY_RTT_CTRL_EN_HIGH_ACC_RTT(x)      (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_CTRL_EN_HIGH_ACC_RTT_SHIFT)) & GEN4PHY_RTT_CTRL_EN_HIGH_ACC_RTT_MASK)
/*! @} */

/*! @name RTT_REF - PHY RTT reference register. */
/*! @{ */

#define GEN4PHY_RTT_REF_FM_REF_010_MASK          (0xFFU)
#define GEN4PHY_RTT_REF_FM_REF_010_SHIFT         (0U)
/*! FM_REF_010 - Contextual values used to derive the FM reference ha_rtt_threshold . */
#define GEN4PHY_RTT_REF_FM_REF_010(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_REF_FM_REF_010_SHIFT)) & GEN4PHY_RTT_REF_FM_REF_010_MASK)

#define GEN4PHY_RTT_REF_FM_REF_110_MASK          (0xFF00U)
#define GEN4PHY_RTT_REF_FM_REF_110_SHIFT         (8U)
/*! FM_REF_110 - Contextual values used to derive the FM reference ha_rtt_threshold . */
#define GEN4PHY_RTT_REF_FM_REF_110(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_REF_FM_REF_110_SHIFT)) & GEN4PHY_RTT_REF_FM_REF_110_MASK)

#define GEN4PHY_RTT_REF_FM_REF_111_MASK          (0xFF0000U)
#define GEN4PHY_RTT_REF_FM_REF_111_SHIFT         (16U)
/*! FM_REF_111 - Contextual values used to derive the FM reference ha_rtt_threshold . */
#define GEN4PHY_RTT_REF_FM_REF_111(x)            (((uint32_t)(((uint32_t)(x)) << GEN4PHY_RTT_REF_FM_REF_111_SHIFT)) & GEN4PHY_RTT_REF_FM_REF_111_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GEN4PHY_Register_Masks */


/*!
 * @}
 */ /* end of group GEN4PHY_Peripheral_Access_Layer */


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


#endif  /* PERI_GEN4PHY_H_ */

