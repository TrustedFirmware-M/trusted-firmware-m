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
**         CMSIS Peripheral Access Layer for XCVR_RX_DIG
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
 * @file PERI_XCVR_RX_DIG.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for XCVR_RX_DIG
 *
 * CMSIS Peripheral Access Layer for XCVR_RX_DIG
 */

#if !defined(PERI_XCVR_RX_DIG_H_)
#define PERI_XCVR_RX_DIG_H_                      /**< Symbol preventing repeated inclusion */

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
   -- XCVR_RX_DIG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_RX_DIG_Peripheral_Access_Layer XCVR_RX_DIG Peripheral Access Layer
 * @{
 */

/** XCVR_RX_DIG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL0;                             /**< RXDIG Control 0, offset: 0x0 */
  __IO uint32_t CTRL0_DRS;                         /**< RXDIG Control 0 DRS, offset: 0x4 */
  __IO uint32_t CTRL1;                             /**< RXDIG Control 1, offset: 0x8 */
  __IO uint32_t DFT_CTRL;                          /**< RXDIG DFT Control, offset: 0xC */
  __IO uint32_t RCCAL_CTRL0;                       /**< RCCAL Control 0, offset: 0x10 */
  __IO uint32_t RCCAL_CTRL1;                       /**< RCCAL Control 1, offset: 0x14 */
  __I  uint32_t RCCAL_RES;                         /**< RCCAL Result, offset: 0x18 */
  __IO uint32_t DCOC_CTRL0;                        /**< DCOC Control 0, offset: 0x1C */
  __IO uint32_t DCOC_CTRL0_DRS;                    /**< DCOC Control 0 DRS, offset: 0x20 */
  __IO uint32_t DCOC_CTRL1;                        /**< DCOC CONTROL 1, offset: 0x24 */
  __IO uint32_t DCOC_CTRL2;                        /**< DCOC CONTROL 2, offset: 0x28 */
  __I  uint32_t DCOC_STAT;                         /**< DCOC Status, offset: 0x2C */
  __IO uint32_t IQMC_CTRL0;                        /**< IQ Mismatch Control 0, offset: 0x30 */
  __IO uint32_t IQMC_CTRL1;                        /**< IQ Mismatch Control 1, offset: 0x34 */
  __IO uint32_t ACQ_FILT_0_3;                      /**< Acquisition Filter Coeffs 0~3, offset: 0x38 */
  __IO uint32_t ACQ_FILT_4_7;                      /**< Acquisition Filter Coeffs 4~7, offset: 0x3C */
  __IO uint32_t ACQ_FILT_8_9;                      /**< Acquisition Filter Coeffs 8~9, offset: 0x40 */
  __IO uint32_t ACQ_FILT_10_11;                    /**< Acquisition Filter Coeffs 10~11, offset: 0x44 */
  __IO uint32_t DEMOD_FILT_0_1;                    /**< Demod Filter Coeffs 0~1, offset: 0x48 */
  __IO uint32_t DEMOD_FILT_2_4;                    /**< Demod Filter Coeffs 2~4, offset: 0x4C */
  __IO uint32_t ACQ_FILT_0_3_DRS;                  /**< Acquisition Filter Coeffs 0~3 DRS, offset: 0x50 */
  __IO uint32_t ACQ_FILT_4_7_DRS;                  /**< Acquisition Filter Coeffs 4~7 DRS, offset: 0x54 */
  __IO uint32_t ACQ_FILT_8_9_DRS;                  /**< Acquisition Filter Coeffs 8~9 DRS, offset: 0x58 */
  __IO uint32_t ACQ_FILT_10_11_DRS;                /**< Acquisition Filter Coeffs 10~11 DRS, offset: 0x5C */
  __IO uint32_t DEMOD_FILT_0_1_DRS;                /**< Demod Filter Coeffs 0~1 DRS, offset: 0x60 */
  __IO uint32_t DEMOD_FILT_2_4_DRS;                /**< Demod Filter Coeffs 2~4 DRS, offset: 0x64 */
  __IO uint32_t RSSI_GLOBAL_CTRL;                  /**< RSSI Global Control, offset: 0x68 */
  __IO uint32_t WB_RSSI_CTRL;                      /**< Wide-Band RSSI Control, offset: 0x6C */
  __IO uint32_t WB_RSSI_RES0;                      /**< Wide-Band RSSI Result 0, offset: 0x70 */
  __I  uint32_t WB_RSSI_RES1;                      /**< Wide-Band RSSI Result 1, offset: 0x74 */
  __I  uint32_t WB_RSSI_DFT;                       /**< Wide-Band RSSI DFT Result, offset: 0x78 */
  __IO uint32_t NB_RSSI_CTRL0;                     /**< Narrow-Band RSSI Control 0, offset: 0x7C */
  __IO uint32_t NB_RSSI_CTRL1;                     /**< Narrow-Band RSSI Control 1, offset: 0x80 */
  __IO uint32_t NB_RSSI_RES0;                      /**< Narrow-Band RSSI Result 0, offset: 0x84 */
  __I  uint32_t NB_RSSI_RES1;                      /**< Narrow-Band RSSI Result 1, offset: 0x88 */
  __I  uint32_t NB_RSSI_DFT;                       /**< Narrow-Band RSSI DFT Result, offset: 0x8C */
  __IO uint32_t AGC_CTRL;                          /**< AGC Control, offset: 0x90 */
  __IO uint32_t AGC_CTRL_STAT;                     /**< AGC Control Status, offset: 0x94 */
  __IO uint32_t AGC_TIMING0;                       /**< AGC Timing Control 0, offset: 0x98 */
  __IO uint32_t AGC_TIMING1;                       /**< AGC Timing Control 1, offset: 0x9C */
  __IO uint32_t AGC_TIMING2;                       /**< AGC Timing Control 2, offset: 0xA0 */
  __IO uint32_t AGC_TIMING0_DRS;                   /**< AGC Timing Control 0 DRS, offset: 0xA4 */
  __IO uint32_t AGC_TIMING1_DRS;                   /**< AGC Timing Control 1 DRS, offset: 0xA8 */
  __IO uint32_t AGC_TIMING2_DRS;                   /**< AGC Timing Control 2 DRS, offset: 0xAC */
  __IO uint32_t AGC_IDX11_GAIN_CFG;                /**< AGC IDX11 Gain Config, offset: 0xB0 */
  __IO uint32_t AGC_IDX10_GAIN_CFG;                /**< AGC IDX10 Gain Config, offset: 0xB4 */
  __IO uint32_t AGC_IDX9_GAIN_CFG;                 /**< AGC IDX9 Gain Config, offset: 0xB8 */
  __IO uint32_t AGC_IDX8_GAIN_CFG;                 /**< AGC IDX8 Gain Config, offset: 0xBC */
  __IO uint32_t AGC_IDX7_GAIN_CFG;                 /**< AGC IDX7 Gain Config, offset: 0xC0 */
  __IO uint32_t AGC_IDX6_GAIN_CFG;                 /**< AGC IDX6 Gain Config, offset: 0xC4 */
  __IO uint32_t AGC_IDX5_GAIN_CFG;                 /**< AGC IDX5 Gain Config, offset: 0xC8 */
  __IO uint32_t AGC_IDX4_GAIN_CFG;                 /**< AGC IDX4 Gain Config, offset: 0xCC */
  __IO uint32_t AGC_IDX3_GAIN_CFG;                 /**< AGC IDX3 Gain Config, offset: 0xD0 */
  __IO uint32_t AGC_IDX2_GAIN_CFG;                 /**< AGC IDX2 Gain Config, offset: 0xD4 */
  __IO uint32_t AGC_IDX1_GAIN_CFG;                 /**< AGC IDX1 Gain Config, offset: 0xD8 */
  __IO uint32_t AGC_IDX0_GAIN_CFG;                 /**< AGC IDX0 Gain Config, offset: 0xDC */
  __IO uint32_t AGC_MIS_GAIN_CFG;                  /**< AGC Miscellaneous Gain Config, offset: 0xE0 */
  __IO uint32_t AGC_IDX11_GAIN_VAL;                /**< AGC IDX11 Gain Value, offset: 0xE4 */
  __IO uint32_t AGC_IDX10_GAIN_VAL;                /**< AGC_IDX10_GAIN_VAL, offset: 0xE8 */
  __IO uint32_t AGC_IDX9_GAIN_VAL;                 /**< AGC_IDX9_GAIN_VAL, offset: 0xEC */
  __IO uint32_t AGC_IDX8_GAIN_VAL;                 /**< AGC_IDX8_GAIN_VAL, offset: 0xF0 */
  __IO uint32_t AGC_IDX7_GAIN_VAL;                 /**< AGC_IDX7_GAIN_VAL, offset: 0xF4 */
  __IO uint32_t AGC_IDX6_GAIN_VAL;                 /**< AGC_IDX6_GAIN_VAL, offset: 0xF8 */
  __IO uint32_t AGC_IDX5_GAIN_VAL;                 /**< AGC_IDX5_GAIN_VAL, offset: 0xFC */
  __IO uint32_t AGC_IDX4_GAIN_VAL;                 /**< AGC_IDX4_GAIN_VAL, offset: 0x100 */
  __IO uint32_t AGC_IDX3_GAIN_VAL;                 /**< AGC_IDX3_GAIN_VAL, offset: 0x104 */
  __IO uint32_t AGC_IDX2_GAIN_VAL;                 /**< AGC_IDX2_GAIN_VAL, offset: 0x108 */
  __IO uint32_t AGC_IDX1_GAIN_VAL;                 /**< AGC_IDX1_GAIN_VAL, offset: 0x10C */
  __IO uint32_t AGC_IDX0_GAIN_VAL;                 /**< AGC_IDX0_GAIN_VAL, offset: 0x110 */
  __IO uint32_t AGC_THR_FAST;                      /**< AGC Fast Mode Threshold, offset: 0x114 */
  __IO uint32_t AGC_THR_FAST_DRS;                  /**< AGC Fast Mode Threshold DRS, offset: 0x118 */
  __IO uint32_t AGC_IDX11_THR;                     /**< AGC IDX11 Slow Mode Threshold, offset: 0x11C */
  __IO uint32_t AGC_IDX10_THR;                     /**< AGC IDX10 Slow Mode Threshold, offset: 0x120 */
  __IO uint32_t AGC_IDX9_THR;                      /**< AGC IDX9 Slow Mode Threshold, offset: 0x124 */
  __IO uint32_t AGC_IDX8_THR;                      /**< AGC IDX8 Slow Mode Threshold, offset: 0x128 */
  __IO uint32_t AGC_IDX7_THR;                      /**< AGC IDX7 Slow Mode Threshold, offset: 0x12C */
  __IO uint32_t AGC_IDX6_THR;                      /**< AGC IDX6 Slow Mode Threshold, offset: 0x130 */
  __IO uint32_t AGC_IDX5_THR;                      /**< AGC IDX5 Slow Mode Threshold, offset: 0x134 */
  __IO uint32_t AGC_IDX4_THR;                      /**< AGC IDX4 Slow Mode Threshold, offset: 0x138 */
  __IO uint32_t AGC_IDX3_THR;                      /**< AGC IDX3 Slow Mode Threshold, offset: 0x13C */
  __IO uint32_t AGC_IDX2_THR;                      /**< AGC IDX2 Slow Mode Threshold, offset: 0x140 */
  __IO uint32_t AGC_IDX1_THR;                      /**< AGC IDX1 Slow Mode Threshold, offset: 0x144 */
  __IO uint32_t AGC_IDX0_THR;                      /**< AGC IDX0 Slow Mode Threshold, offset: 0x148 */
  __IO uint32_t AGC_THR_MIS;                       /**< AGC Miscellaneous Thresholds, offset: 0x14C */
  __IO uint32_t AGC_OVRD;                          /**< AGC Override Control, offset: 0x150 */
  __IO uint32_t DC_RESID_CTRL;                     /**< DC Residual Control, offset: 0x154 */
  __IO uint32_t DC_RESID_CTRL2;                    /**< DC Residual Control2, offset: 0x158 */
  __IO uint32_t DC_RESID_CTRL_DRS;                 /**< DC Residual Control DataRate1, offset: 0x15C */
  __I  uint32_t DC_RESID_EST;                      /**< DC Residual Estimate, offset: 0x160 */
  __IO uint32_t DFT_TONE_ANALYZER0;                /**< DfT tone analyzer, offset: 0x164 */
  __IO uint32_t DFT_TONE_ANALYZER1;                /**< DfT tone analyzer, offset: 0x168 */
  __I  uint32_t DFT_TONE_ANALYZER2;                /**< DfT tone analyzer, offset: 0x16C */
  __IO uint32_t DFT_TONE_ANALYZER3;                /**< DfT tone analyzer, offset: 0x170 */
  __I  uint32_t DCOC_DIG_CORR_RESULT;              /**< DCOC Digital Correction Result, offset: 0x174 */
  __IO uint32_t IQMC_CTRL1_DRS;                    /**< IQ Mismatch Control 1 DRS, offset: 0x178 */
  __IO uint32_t TQI_CTRL;                          /**< TQI control fields, offset: 0x17C */
  __IO uint32_t TQI_THR;                           /**< TQI thresholds, offset: 0x180 */
  __IO uint32_t CTRL2;                             /**< RXDIG Control 2, offset: 0x184 */
  __IO uint32_t NADM_CTRL;                         /**< Controls for the NADM module, offset: 0x188 */
  __I  uint32_t NADM_RES;                          /**< NADM latest packet results., offset: 0x18C */
  __IO uint32_t FCFO_CTRL;                         /**< Fine CFO module controls., offset: 0x190 */
  __IO uint32_t FCFO_TN;                           /**< Tone parameters., offset: 0x194 */
  __IO uint32_t FCFO_TN_PH;                        /**< F2 carrier iq phases, offset: 0x198 */
  __I  uint32_t FCFO_RES;                          /**< Fine CFO results., offset: 0x19C */
} XCVR_RX_DIG_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_RX_DIG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_RX_DIG_Register_Masks XCVR_RX_DIG Register Masks
 * @{
 */

/*! @name CTRL0 - RXDIG Control 0 */
/*! @{ */

#define XCVR_RX_DIG_CTRL0_ADC_CLIP_EN_MASK       (0x1U)
#define XCVR_RX_DIG_CTRL0_ADC_CLIP_EN_SHIFT      (0U)
/*! ADC_CLIP_EN - ADC Output Clip Enable
 *  0b0..ADC clip is disabled.
 *  0b1..ADC clip is enabled.
 */
#define XCVR_RX_DIG_CTRL0_ADC_CLIP_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_ADC_CLIP_EN_SHIFT)) & XCVR_RX_DIG_CTRL0_ADC_CLIP_EN_MASK)

#define XCVR_RX_DIG_CTRL0_RX_IQMC_EN_MASK        (0x2U)
#define XCVR_RX_DIG_CTRL0_RX_IQMC_EN_SHIFT       (1U)
/*! RX_IQMC_EN - IQ Mismatch Compensation Enable
 *  0b0..IQ mismatch compensation is disabled.
 *  0b1..IQ mismatch compensation is enabled.
 */
#define XCVR_RX_DIG_CTRL0_RX_IQMC_EN(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_IQMC_EN_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_IQMC_EN_MASK)

#define XCVR_RX_DIG_CTRL0_DIG_MIXER_FREQ_MASK    (0x7FCU)
#define XCVR_RX_DIG_CTRL0_DIG_MIXER_FREQ_SHIFT   (2U)
/*! DIG_MIXER_FREQ - Digital Mixer Frequency */
#define XCVR_RX_DIG_CTRL0_DIG_MIXER_FREQ(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_DIG_MIXER_FREQ_SHIFT)) & XCVR_RX_DIG_CTRL0_DIG_MIXER_FREQ_MASK)

#define XCVR_RX_DIG_CTRL0_DIG_MIXER_PH_EN_MASK   (0x800U)
#define XCVR_RX_DIG_CTRL0_DIG_MIXER_PH_EN_SHIFT  (11U)
/*! DIG_MIXER_PH_EN - Mixer Phase Compensation Enable */
#define XCVR_RX_DIG_CTRL0_DIG_MIXER_PH_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_DIG_MIXER_PH_EN_SHIFT)) & XCVR_RX_DIG_CTRL0_DIG_MIXER_PH_EN_MASK)

#define XCVR_RX_DIG_CTRL0_CIC_ORDER_MASK         (0x1000U)
#define XCVR_RX_DIG_CTRL0_CIC_ORDER_SHIFT        (12U)
/*! CIC_ORDER - CIC Order(Stage) Selection
 *  0b0..4-stage CIC
 *  0b1..3-stage CIC
 */
#define XCVR_RX_DIG_CTRL0_CIC_ORDER(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_CIC_ORDER_SHIFT)) & XCVR_RX_DIG_CTRL0_CIC_ORDER_MASK)

#define XCVR_RX_DIG_CTRL0_CIC_RATE_MASK          (0xE000U)
#define XCVR_RX_DIG_CTRL0_CIC_RATE_SHIFT         (13U)
/*! CIC_RATE - CIC Decimation Rate
 *  0b000..Decimation Rate is 1.
 *  0b001..Decimation Rate is 2.
 *  0b010..Decimation Rate is 4.
 *  0b011..Decimation Rate is 8.
 *  0b100..Decimation Rate is 16.
 *  0b101..Decimation Rate is 32.
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define XCVR_RX_DIG_CTRL0_CIC_RATE(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_CIC_RATE_SHIFT)) & XCVR_RX_DIG_CTRL0_CIC_RATE_MASK)

#define XCVR_RX_DIG_CTRL0_RX_DIG_GAIN_MASK       (0x70000U)
#define XCVR_RX_DIG_CTRL0_RX_DIG_GAIN_SHIFT      (16U)
/*! RX_DIG_GAIN - RX Digital Gain Value
 *  0b000..Digital gain value is 1.000.
 *  0b001..Digital gain value is 1.125.
 *  0b010..Digital gain value is 1.250.
 *  0b011..Digital gain value is 1.375.
 *  0b100..Digital gain value is 1.500.
 *  0b101..Digital gain value is 1.625.
 *  0b110..Digital gain value is 1.750.
 *  0b111..Digital gain value is 1.875.
 */
#define XCVR_RX_DIG_CTRL0_RX_DIG_GAIN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_DIG_GAIN_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_DIG_GAIN_MASK)

#define XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_LEN_MASK   (0x100000U)
#define XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_LEN_SHIFT  (20U)
/*! RX_ACQ_FILT_LEN - Acquisition Filter Length
 *  0b0..Acquisition filter length is 24.
 *  0b1..Acquisition filter length is 16.
 */
#define XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_LEN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_LEN_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_LEN_MASK)

#define XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_BYPASS_MASK (0x200000U)
#define XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_BYPASS_SHIFT (21U)
/*! RX_ACQ_FILT_BYPASS - Acquisition Filter Bypass
 *  0b0..Acquisition filter is enabled
 *  0b1..Acquisition filter is bypassed
 */
#define XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_BYPASS(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_BYPASS_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_ACQ_FILT_BYPASS_MASK)

#define XCVR_RX_DIG_CTRL0_RX_SRC_EN_MASK         (0x400000U)
#define XCVR_RX_DIG_CTRL0_RX_SRC_EN_SHIFT        (22U)
/*! RX_SRC_EN - RX Sample Rate Converter Enable
 *  0b0..SRC is disabled.
 *  0b1..SRC is enabled.
 */
#define XCVR_RX_DIG_CTRL0_RX_SRC_EN(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_SRC_EN_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_SRC_EN_MASK)

#define XCVR_RX_DIG_CTRL0_RX_IQ_8B_OUT_MODE_MASK (0x3800000U)
#define XCVR_RX_DIG_CTRL0_RX_IQ_8B_OUT_MODE_SHIFT (23U)
/*! RX_IQ_8B_OUT_MODE - RX 8-bit IQ Output Mode
 *  0b000..Disable 8-bit IQ output
 *  0b001..{I[10],I[9:3]}, {Q[10],Q[9:3]}
 *  0b010..{I[10],I[8:2]}, {Q[10],Q[8:2]}
 *  0b011..{I[10],I[7:1]}, {Q[10],Q[7:1]}
 *  0b100..Dynamic scaling
 */
#define XCVR_RX_DIG_CTRL0_RX_IQ_8B_OUT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_IQ_8B_OUT_MODE_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_IQ_8B_OUT_MODE_MASK)

#define XCVR_RX_DIG_CTRL0_RX_FSK_ZB_SEL_MASK     (0x8000000U)
#define XCVR_RX_DIG_CTRL0_RX_FSK_ZB_SEL_SHIFT    (27U)
/*! RX_FSK_ZB_SEL
 *  0b0..2.4GHz PHY is selected
 *  0b1..15.4 PHY is selected
 */
#define XCVR_RX_DIG_CTRL0_RX_FSK_ZB_SEL(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_FSK_ZB_SEL_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_FSK_ZB_SEL_MASK)

#define XCVR_RX_DIG_CTRL0_RX_DEMOD_IN_SEL_MASK   (0x10000000U)
#define XCVR_RX_DIG_CTRL0_RX_DEMOD_IN_SEL_SHIFT  (28U)
/*! RX_DEMOD_IN_SEL - Rx Demod Input Sel
 *  0b0..Source is output channel filter
 *  0b1..Source is output acquisition filter
 */
#define XCVR_RX_DIG_CTRL0_RX_DEMOD_IN_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_DEMOD_IN_SEL_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_DEMOD_IN_SEL_MASK)

#define XCVR_RX_DIG_CTRL0_CIC_CNTR_FREE_RUN_EN_MASK (0x20000000U)
#define XCVR_RX_DIG_CTRL0_CIC_CNTR_FREE_RUN_EN_SHIFT (29U)
/*! CIC_CNTR_FREE_RUN_EN - CIC Dec Counter Free Run Enable */
#define XCVR_RX_DIG_CTRL0_CIC_CNTR_FREE_RUN_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_CIC_CNTR_FREE_RUN_EN_SHIFT)) & XCVR_RX_DIG_CTRL0_CIC_CNTR_FREE_RUN_EN_MASK)

#define XCVR_RX_DIG_CTRL0_RX_AGC_EN_MASK         (0x40000000U)
#define XCVR_RX_DIG_CTRL0_RX_AGC_EN_SHIFT        (30U)
/*! RX_AGC_EN - AGC Enable
 *  0b0..AGC is disabled
 *  0b1..AGC is enabled
 */
#define XCVR_RX_DIG_CTRL0_RX_AGC_EN(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_RX_AGC_EN_SHIFT)) & XCVR_RX_DIG_CTRL0_RX_AGC_EN_MASK)

#define XCVR_RX_DIG_CTRL0_DR_OVRD_IN_CTE_MASK    (0x80000000U)
#define XCVR_RX_DIG_CTRL0_DR_OVRD_IN_CTE_SHIFT   (31U)
/*! DR_OVRD_IN_CTE - DATARATE_CONFIG_SEL Override In CTE */
#define XCVR_RX_DIG_CTRL0_DR_OVRD_IN_CTE(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_DR_OVRD_IN_CTE_SHIFT)) & XCVR_RX_DIG_CTRL0_DR_OVRD_IN_CTE_MASK)
/*! @} */

/*! @name CTRL0_DRS - RXDIG Control 0 DRS */
/*! @{ */

#define XCVR_RX_DIG_CTRL0_DRS_DIG_MIXER_FREQ_MASK (0x7FCU)
#define XCVR_RX_DIG_CTRL0_DRS_DIG_MIXER_FREQ_SHIFT (2U)
/*! DIG_MIXER_FREQ - Digital Mixer Frequency */
#define XCVR_RX_DIG_CTRL0_DRS_DIG_MIXER_FREQ(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_DRS_DIG_MIXER_FREQ_SHIFT)) & XCVR_RX_DIG_CTRL0_DRS_DIG_MIXER_FREQ_MASK)

#define XCVR_RX_DIG_CTRL0_DRS_CIC_ORDER_MASK     (0x800U)
#define XCVR_RX_DIG_CTRL0_DRS_CIC_ORDER_SHIFT    (11U)
/*! CIC_ORDER - CIC Order(Stage) Selection
 *  0b0..4-stage CIC
 *  0b1..3-stage CIC
 */
#define XCVR_RX_DIG_CTRL0_DRS_CIC_ORDER(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_DRS_CIC_ORDER_SHIFT)) & XCVR_RX_DIG_CTRL0_DRS_CIC_ORDER_MASK)

#define XCVR_RX_DIG_CTRL0_DRS_CIC_RATE_MASK      (0x7000U)
#define XCVR_RX_DIG_CTRL0_DRS_CIC_RATE_SHIFT     (12U)
/*! CIC_RATE - CIC Decimation Rate
 *  0b000..Decimation Rate is 1.
 *  0b001..Decimation Rate is 2.
 *  0b010..Decimation Rate is 4.
 *  0b011..Decimation Rate is 8.
 *  0b100..Decimation Rate is 16.
 *  0b101..Decimation Rate is 32.
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define XCVR_RX_DIG_CTRL0_DRS_CIC_RATE(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL0_DRS_CIC_RATE_SHIFT)) & XCVR_RX_DIG_CTRL0_DRS_CIC_RATE_MASK)
/*! @} */

/*! @name CTRL1 - RXDIG Control 1 */
/*! @{ */

#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_MASK (0x1U)
#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_SHIFT (0U)
/*! RX_SAMPLE_BUF_BYPASS - Bypass Sample Buffer */
#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_MASK)

#define XCVR_RX_DIG_CTRL1_RX_DFT_IQ_OUT_AVERAGED_MASK (0x2U)
#define XCVR_RX_DIG_CTRL1_RX_DFT_IQ_OUT_AVERAGED_SHIFT (1U)
/*! RX_DFT_IQ_OUT_AVERAGED - I/Q output as raw or averaged data
 *  0b0..Raw data at rx_dft_iq_out
 *  0b1..Averaged data at rx_dft_iq_out
 */
#define XCVR_RX_DIG_CTRL1_RX_DFT_IQ_OUT_AVERAGED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_DFT_IQ_OUT_AVERAGED_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_DFT_IQ_OUT_AVERAGED_MASK)

#define XCVR_RX_DIG_CTRL1_RX_IQ_AVG_WIN_PCT_MASK (0xCU)
#define XCVR_RX_DIG_CTRL1_RX_IQ_AVG_WIN_PCT_SHIFT (2U)
/*! RX_IQ_AVG_WIN_PCT - RX IQ Output Average Window Config to generate PCT
 *  0b00..Disable RX IQ output average function
 *  0b01..Average window size = 4
 *  0b10..Average window size = 8
 *  0b11..Average window size = 16
 */
#define XCVR_RX_DIG_CTRL1_RX_IQ_AVG_WIN_PCT(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_IQ_AVG_WIN_PCT_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_IQ_AVG_WIN_PCT_MASK)

#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_IN_CTE_MASK (0x10U)
#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_IN_CTE_SHIFT (4U)
/*! RX_SAMPLE_BUF_BYPASS_IN_CTE - Bypass Sample Buffer During CTE */
#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_IN_CTE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_IN_CTE_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_BYPASS_IN_CTE_MASK)

#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_AUTO_GATE_MASK (0x20U)
#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_AUTO_GATE_SHIFT (5U)
/*! RX_SAMPLE_BUF_AUTO_GATE - Sample Buffer Automatically Gate Off */
#define XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_AUTO_GATE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_AUTO_GATE_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_SAMPLE_BUF_AUTO_GATE_MASK)

#define XCVR_RX_DIG_CTRL1_DC_RESID_EN_MASK       (0x40U)
#define XCVR_RX_DIG_CTRL1_DC_RESID_EN_SHIFT      (6U)
/*! DC_RESID_EN - DC_RESID Enable */
#define XCVR_RX_DIG_CTRL1_DC_RESID_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_DC_RESID_EN_SHIFT)) & XCVR_RX_DIG_CTRL1_DC_RESID_EN_MASK)

#define XCVR_RX_DIG_CTRL1_DIS_WB_NORM_AA_FOUND_MASK (0x80U)
#define XCVR_RX_DIG_CTRL1_DIS_WB_NORM_AA_FOUND_SHIFT (7U)
/*! DIS_WB_NORM_AA_FOUND - Disable WB-NORM when AA found */
#define XCVR_RX_DIG_CTRL1_DIS_WB_NORM_AA_FOUND(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_DIS_WB_NORM_AA_FOUND_SHIFT)) & XCVR_RX_DIG_CTRL1_DIS_WB_NORM_AA_FOUND_MASK)

#define XCVR_RX_DIG_CTRL1_RX_NB_NORM_EN_MASK     (0x100U)
#define XCVR_RX_DIG_CTRL1_RX_NB_NORM_EN_SHIFT    (8U)
/*! RX_NB_NORM_EN - Narrow-Band Normalizer Enable
 *  0b0..Narrow-Band normalizer is disabled.
 *  0b1..Narrow-Band normalizer is enabled.
 */
#define XCVR_RX_DIG_CTRL1_RX_NB_NORM_EN(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_NB_NORM_EN_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_NB_NORM_EN_MASK)

#define XCVR_RX_DIG_CTRL1_RX_HIGH_RES_NORM_SEL_MASK (0x200U)
#define XCVR_RX_DIG_CTRL1_RX_HIGH_RES_NORM_SEL_SHIFT (9U)
/*! RX_HIGH_RES_NORM_SEL - High Resolution Phase Source Select
 *  0b0..From RX_NORM_NB
 *  0b1..From RX_NORM_WB
 */
#define XCVR_RX_DIG_CTRL1_RX_HIGH_RES_NORM_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_HIGH_RES_NORM_SEL_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_HIGH_RES_NORM_SEL_MASK)

#define XCVR_RX_DIG_CTRL1_RX_DEMOD_FILT_BYPASS_MASK (0x400U)
#define XCVR_RX_DIG_CTRL1_RX_DEMOD_FILT_BYPASS_SHIFT (10U)
/*! RX_DEMOD_FILT_BYPASS - Demod Channel Filter Bypass
 *  0b0..Demod channel filter is enabled.
 *  0b1..Demod channel filter is bypassed.
 */
#define XCVR_RX_DIG_CTRL1_RX_DEMOD_FILT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_DEMOD_FILT_BYPASS_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_DEMOD_FILT_BYPASS_MASK)

#define XCVR_RX_DIG_CTRL1_RX_DC_RES_AFTER_IF_MIX_MASK (0x800U)
#define XCVR_RX_DIG_CTRL1_RX_DC_RES_AFTER_IF_MIX_SHIFT (11U)
#define XCVR_RX_DIG_CTRL1_RX_DC_RES_AFTER_IF_MIX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_DC_RES_AFTER_IF_MIX_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_DC_RES_AFTER_IF_MIX_MASK)

#define XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_MASK (0x7000U)
#define XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_SHIFT (12U)
/*! RX_FRAC_CORR_OVRD - Fractional Correction Coefficient Override Value */
#define XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_MASK)

#define XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_EN_MASK (0x8000U)
#define XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_EN_SHIFT (15U)
/*! RX_FRAC_CORR_OVRD_EN - Fractional Correction Coefficient Override Enable */
#define XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_EN_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_FRAC_CORR_OVRD_EN_MASK)

#define XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_MASK   (0x3FF0000U)
#define XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_SHIFT  (16U)
/*! RX_CFO_EST_OVRD - CFO Estimation Override Value */
#define XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_MASK)

#define XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_EN_MASK (0x4000000U)
#define XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_EN_SHIFT (26U)
/*! RX_CFO_EST_OVRD_EN - CFO Estimation Override Enable
 *  0b0..CFO override is enabled
 *  0b1..CFO override is disabled
 */
#define XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_EN_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_CFO_EST_OVRD_EN_MASK)

#define XCVR_RX_DIG_CTRL1_RX_MIXER_IDX_OUT_MODE_MASK (0x8000000U)
#define XCVR_RX_DIG_CTRL1_RX_MIXER_IDX_OUT_MODE_SHIFT (27U)
/*! RX_MIXER_IDX_OUT_MODE - RX_DIG Mixer Index Output Mode */
#define XCVR_RX_DIG_CTRL1_RX_MIXER_IDX_OUT_MODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_MIXER_IDX_OUT_MODE_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_MIXER_IDX_OUT_MODE_MASK)

#define XCVR_RX_DIG_CTRL1_RX_IQ_PH_AVG_WIN_MASK  (0x70000000U)
#define XCVR_RX_DIG_CTRL1_RX_IQ_PH_AVG_WIN_SHIFT (28U)
/*! RX_IQ_PH_AVG_WIN - RX IQ Phase Output Average Window Config
 *  0b000..Disable RX IQ and/or Phase output average function
 *  0b001..Average window size = 4
 *  0b010..Average window size = 8
 *  0b011..Average window size = 16
 *  0b100..Average window size = 32
 *  0b101..Average window size = 64
 *  0b110..Average window size = 128
 *  0b111..Average window size = 256
 */
#define XCVR_RX_DIG_CTRL1_RX_IQ_PH_AVG_WIN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_IQ_PH_AVG_WIN_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_IQ_PH_AVG_WIN_MASK)

#define XCVR_RX_DIG_CTRL1_RX_IQ_PH_OUTPUT_COND_MASK (0x80000000U)
#define XCVR_RX_DIG_CTRL1_RX_IQ_PH_OUTPUT_COND_SHIFT (31U)
/*! RX_IQ_PH_OUTPUT_COND - RX IQ or Phase Output Conditioning
 *  0b0..Output IQ and/or Phase all-time
 *  0b1..Only output IQ and/or Phase during localization sample slot
 */
#define XCVR_RX_DIG_CTRL1_RX_IQ_PH_OUTPUT_COND(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL1_RX_IQ_PH_OUTPUT_COND_SHIFT)) & XCVR_RX_DIG_CTRL1_RX_IQ_PH_OUTPUT_COND_MASK)
/*! @} */

/*! @name DFT_CTRL - RXDIG DFT Control */
/*! @{ */

#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_PH_OUT_SEL_MASK (0x300U)
#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_PH_OUT_SEL_SHIFT (8U)
/*! DFT_RX_PH_OUT_SEL - DFT RXDIG Phase Output Selection
 *  0b00..Disable DFT phase output
 *  0b01..Select wide-band phase output
 *  0b10..Select narrow-band phase output
 *  0b11..Disable DFT phase output
 */
#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_PH_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_CTRL_DFT_RX_PH_OUT_SEL_SHIFT)) & XCVR_RX_DIG_DFT_CTRL_DFT_RX_PH_OUT_SEL_MASK)

#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SEL_MASK (0x1C00U)
#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SEL_SHIFT (10U)
/*! DFT_RX_IQ_OUT_SEL - DFT I/Q Output Selection
 *  0b000..Disabled
 *  0b001..Select IF_MIXER
 *  0b010..Select CIC
 *  0b011..Select ACQ channel filter
 *  0b100..Select SRC
 *  0b101..Select CFO_MIXER
 *  0b110..Select FRAC_CORR
 *  0b111..Select DC_RESID
 */
#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SEL_SHIFT)) & XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SEL_MASK)

#define XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_MAG_OUT_SEL_MASK (0xE000U)
#define XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_MAG_OUT_SEL_SHIFT (13U)
/*! DFT_RSSI_MAG_OUT_SEL - DFT RSSI Magnitude Output Selection
 *  0b000..Disabled
 *  0b001..WB-RSSI fast magnitude
 *  0b010..WB-RSSI slow magnitude
 *  0b011..NB-RSSI mag IIR
 *  0b100..NB-RSSI mag avg
 *  0b101..NB-RSSI noise mag IIR
 *  0b110..NB-RSSI noise mag avg
 *  0b111..DFT_RX_IQ_OUT mag
 */
#define XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_MAG_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_MAG_OUT_SEL_SHIFT)) & XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_MAG_OUT_SEL_MASK)

#define XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_OUT_SEL_MASK (0x70000U)
#define XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_OUT_SEL_SHIFT (16U)
/*! DFT_RSSI_OUT_SEL - DFT RSSI Result Output Selection
 *  0b000..Disable RSSI output
 *  0b001..Wide-band RSSI_RAW output
 *  0b010..Wide-band RSSI output
 *  0b011..Narrow-band RSSI_RAW output
 *  0b100..Narrow-band RSSI output
 *  0b101..Narrow-band NOISE_RAW output
 *  0b110..Narrow-band SNR output
 *  0b111..Narrow-band LQI output
 */
#define XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_OUT_SEL_SHIFT)) & XCVR_RX_DIG_DFT_CTRL_DFT_RSSI_OUT_SEL_MASK)

#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SAMPLE_BUF_OUT2_MASK (0x80000U)
#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SAMPLE_BUF_OUT2_SHIFT (19U)
/*! DFT_RX_IQ_OUT_SAMPLE_BUF_OUT2 - Enable sample_buf output after delay line instead of src output for DFT RX_IQ_OUT
 *  0b0..SRC output
 *  0b1..SAMPLE BUF 2 output
 */
#define XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SAMPLE_BUF_OUT2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SAMPLE_BUF_OUT2_SHIFT)) & XCVR_RX_DIG_DFT_CTRL_DFT_RX_IQ_OUT_SAMPLE_BUF_OUT2_MASK)
/*! @} */

/*! @name RCCAL_CTRL0 - RCCAL Control 0 */
/*! @{ */

#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_MASK (0x7U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_SHIFT (0U)
/*! CBPF_BW_CODE - CBPF BW_CODE */
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_MASK (0x8U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_SHIFT (3U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_DRS_MASK (0x70U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_DRS_SHIFT (4U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_DRS_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_CBPF_BW_CODE_DRS_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_DRS_MASK (0x80U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_DRS_SHIFT (7U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_DRS_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_CBPF_SC_CODE_DRS_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_CCODE_OFFSET_MASK (0x1F00U)
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_CCODE_OFFSET_SHIFT (8U)
/*! CBPF_CCODE_OFFSET - CBPF_CCODE Offset */
#define XCVR_RX_DIG_RCCAL_CTRL0_CBPF_CCODE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_CBPF_CCODE_OFFSET_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_CBPF_CCODE_OFFSET_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CODE_OFFSET_MASK (0xF0000U)
#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CODE_OFFSET_SHIFT (16U)
/*! RCCAL_CODE_OFFSET - RCCAL_CODE Offset */
#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CODE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CODE_OFFSET_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CODE_OFFSET_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_SMPL_DLY_MASK (0x300000U)
#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_SMPL_DLY_SHIFT (20U)
/*! RCCAL_SMPL_DLY - RCCAL Sample Delay
 *  0b00..2 cycles (default)
 *  0b01..1 cycle
 *  0b10..2 cycles
 *  0b11..3 cycles
 */
#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_SMPL_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_SMPL_DLY_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_SMPL_DLY_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CMPOUT_INV_MASK (0x400000U)
#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CMPOUT_INV_SHIFT (22U)
/*! RCCAL_CMPOUT_INV - RCCAL Comparator Output Invert */
#define XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CMPOUT_INV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CMPOUT_INV_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL0_RCCAL_CMPOUT_INV_MASK)
/*! @} */

/*! @name RCCAL_CTRL1 - RCCAL Control 1 */
/*! @{ */

#define XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_MASK (0x7FU)
#define XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_SHIFT (0U)
/*! CBPF_CCODE_OVRD - CBPF_CCODE Override Value */
#define XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_EN_MASK (0x80U)
#define XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_EN_SHIFT (7U)
/*! CBPF_CCODE_OVRD_EN - CBPF_CCODE Override Enable */
#define XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_EN_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_CBPF_CCODE_OVRD_EN_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_MASK (0x1F00U)
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_SHIFT (8U)
/*! RCCAL_CODE_OVRD - RCCAL_CODE Override Value */
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_EN_MASK (0x2000U)
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_EN_SHIFT (13U)
/*! RCCAL_CODE_OVRD_EN - RCCAL_CODE Override Enable */
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_EN_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CODE_OVRD_EN_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_SAMPLE_OVRD_MASK (0x10000U)
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_SAMPLE_OVRD_SHIFT (16U)
/*! RCCAL_SAMPLE_OVRD - RCCAL_SAMPLE Override Value */
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_SAMPLE_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_SAMPLE_OVRD_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_SAMPLE_OVRD_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CHARGE_OVRD_MASK (0x20000U)
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CHARGE_OVRD_SHIFT (17U)
/*! RCCAL_CHARGE_OVRD - RCCAL_CHARGE Override Value */
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CHARGE_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CHARGE_OVRD_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CHARGE_OVRD_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_DISCHARGE_OVRD_MASK (0x40000U)
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_DISCHARGE_OVRD_SHIFT (18U)
/*! RCCAL_DISCHARGE_OVRD - RCCAL_DISCHARGE Override Value */
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_DISCHARGE_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_DISCHARGE_OVRD_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_DISCHARGE_OVRD_MASK)

#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CTRL_OVRD_EN_MASK (0x80000U)
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CTRL_OVRD_EN_SHIFT (19U)
/*! RCCAL_CTRL_OVRD_EN - RCCAL Control Signals Override Enable */
#define XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CTRL_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CTRL_OVRD_EN_SHIFT)) & XCVR_RX_DIG_RCCAL_CTRL1_RCCAL_CTRL_OVRD_EN_MASK)
/*! @} */

/*! @name RCCAL_RES - RCCAL Result */
/*! @{ */

#define XCVR_RX_DIG_RCCAL_RES_RCCAL_CODE_MASK    (0x1FU)
#define XCVR_RX_DIG_RCCAL_RES_RCCAL_CODE_SHIFT   (0U)
/*! RCCAL_CODE - RCCAL_CODE */
#define XCVR_RX_DIG_RCCAL_RES_RCCAL_CODE(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_RES_RCCAL_CODE_SHIFT)) & XCVR_RX_DIG_RCCAL_RES_RCCAL_CODE_MASK)

#define XCVR_RX_DIG_RCCAL_RES_CBPF_CCODE_MASK    (0x7F00U)
#define XCVR_RX_DIG_RCCAL_RES_CBPF_CCODE_SHIFT   (8U)
/*! CBPF_CCODE - CBPF_CCODE */
#define XCVR_RX_DIG_RCCAL_RES_CBPF_CCODE(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_RES_CBPF_CCODE_SHIFT)) & XCVR_RX_DIG_RCCAL_RES_CBPF_CCODE_MASK)

#define XCVR_RX_DIG_RCCAL_RES_RCCAL_CMPOUT_MASK  (0x10000U)
#define XCVR_RX_DIG_RCCAL_RES_RCCAL_CMPOUT_SHIFT (16U)
/*! RCCAL_CMPOUT - RCCAL CMPOUT */
#define XCVR_RX_DIG_RCCAL_RES_RCCAL_CMPOUT(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RCCAL_RES_RCCAL_CMPOUT_SHIFT)) & XCVR_RX_DIG_RCCAL_RES_RCCAL_CMPOUT_MASK)
/*! @} */

/*! @name DCOC_CTRL0 - DCOC Control 0 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFII_MASK    (0xFU)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFII_SHIFT   (0U)
/*! DCOC_SFII - DCOC_SFII */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFII(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFII_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFII_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQ_MASK    (0xF0U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQ_SHIFT   (4U)
/*! DCOC_SFQQ - DCOC_SFQQ */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQ(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQ_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQ_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIIP_MASK   (0x100U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIIP_SHIFT  (8U)
/*! DCOC_SFIIP - DCOC_SFIIP */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIIP(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIIP_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIIP_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQP_MASK   (0x200U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQP_SHIFT  (9U)
/*! DCOC_SFQQP - DCOC_SFQQP */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQP(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQP_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQQP_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIQ_MASK    (0x400U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIQ_SHIFT   (10U)
/*! DCOC_SFIQ - DCOC_SFIQ */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIQ(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIQ_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFIQ_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQI_MASK    (0x800U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQI_SHIFT   (11U)
/*! DCOC_SFQI - DCOC_SFQI */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQI(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQI_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_SFQI_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_I_CAL_POL_MASK (0x1000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_I_CAL_POL_SHIFT (12U)
/*! DCOC_I_CAL_POL - DCOC_I_CAL_POL */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_I_CAL_POL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_I_CAL_POL_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_I_CAL_POL_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_Q_CAL_POL_MASK (0x2000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_Q_CAL_POL_SHIFT (13U)
/*! DCOC_Q_CAL_POL - DCOC_Q_CAL_POL */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_Q_CAL_POL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_Q_CAL_POL_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_Q_CAL_POL_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_ORDER_MASK (0x4000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_ORDER_SHIFT (14U)
/*! DCOC_DAC_ORDER - DCOC_DAC_ORDER
 *  0b0..DCOC I DAC is calibrated first
 *  0b1..DCOC Q DAC is calibrated first
 */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_ORDER(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_ORDER_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_ORDER_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_PULSE_CAPCODE_MASK (0x8000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_PULSE_CAPCODE_SHIFT (15U)
/*! DCOC_PULSE_CAPCODE - DCOC pulse capcode */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_PULSE_CAPCODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_PULSE_CAPCODE_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_PULSE_CAPCODE_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_STL_TIME_MASK (0xF0000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_STL_TIME_SHIFT (16U)
/*! DCOC_CBPF_STL_TIME - DCOC CBPF Settle Time */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_STL_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_STL_TIME_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_STL_TIME_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SAR_STL_TIME_MASK (0xF00000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SAR_STL_TIME_SHIFT (20U)
/*! DCOC_SAR_STL_TIME - DCOC CBPF Settle Time */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_SAR_STL_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_SAR_STL_TIME_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_SAR_STL_TIME_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CAL_USE_OFFSET_MASK (0x1000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CAL_USE_OFFSET_SHIFT (24U)
/*! DCOC_CAL_USE_OFFSET
 *  0b0..Do not apply dcoc_i/qcbpf_offset during DCOC calibration
 *  0b1..Apply dcoc_i/qcbpf_offset during DCOC calibration
 */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CAL_USE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_CAL_USE_OFFSET_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_CAL_USE_OFFSET_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_AVG_WIN_MASK (0x2000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_AVG_WIN_SHIFT (25U)
/*! DCOC_AVG_WIN - DCOC Average Window Select
 *  0b0..4-sample
 *  0b1..8-sample
 */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_AVG_WIN(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_AVG_WIN_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_AVG_WIN_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DIG_CORR_EN_MASK (0x4000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DIG_CORR_EN_SHIFT (26U)
/*! DCOC_DIG_CORR_EN - DCOC Digital Correction Enable */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DIG_CORR_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_DIG_CORR_EN_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_DIG_CORR_EN_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_OVRD_EN_MASK (0x8000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_OVRD_EN_SHIFT (27U)
/*! DCOC_DAC_OVRD_EN - DCOC_DAC_OVRD_EN */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_OVRD_EN_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_DAC_OVRD_EN_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_ADC_OFFSET_OVRD_EN_MASK (0x10000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_ADC_OFFSET_OVRD_EN_SHIFT (28U)
/*! DCOC_ADC_OFFSET_OVRD_EN - DCOC_ADC_OFFSET_OVRD_EN */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_ADC_OFFSET_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_ADC_OFFSET_OVRD_EN_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_ADC_OFFSET_OVRD_EN_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_SHORT_OVRD_MASK (0x20000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_SHORT_OVRD_SHIFT (29U)
/*! DCOC_CBPF_SHORT_OVRD - DCOC CBPF_SHORT Override Value */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_SHORT_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_SHORT_OVRD_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_SHORT_OVRD_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_OVRD_MASK (0x40000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_OVRD_SHIFT (30U)
/*! DCOC_CBPF_HIZ_OVRD - DCOC CBPF_HIZ Override Value */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_OVRD_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_OVRD_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_SHORT_OVRD_EN_MASK (0x80000000U)
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_SHORT_OVRD_EN_SHIFT (31U)
/*! DCOC_CBPF_HIZ_SHORT_OVRD_EN - DCOC CBPF HIZ SHORT Override Enable */
#define XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_SHORT_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_SHORT_OVRD_EN_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DCOC_CBPF_HIZ_SHORT_OVRD_EN_MASK)
/*! @} */

/*! @name DCOC_CTRL0_DRS - DCOC Control 0 DRS */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFII_MASK (0xFU)
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFII_SHIFT (0U)
/*! DCOC_SFII - DCOC_SFII */
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFII(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFII_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFII_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQ_MASK (0xF0U)
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQ_SHIFT (4U)
/*! DCOC_SFQQ - DCOC_SFQQ */
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQ(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQ_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQ_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFIIP_MASK (0x100U)
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFIIP_SHIFT (8U)
/*! DCOC_SFIIP - DCOC_SFIIP */
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFIIP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFIIP_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFIIP_MASK)

#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQP_MASK (0x200U)
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQP_SHIFT (9U)
/*! DCOC_SFQQP - DCOC_SFQQP */
#define XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQP_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL0_DRS_DCOC_SFQQP_MASK)
/*! @} */

/*! @name DCOC_CTRL1 - DCOC CONTROL 1 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_ILNA_OFFSET_MASK (0x3FU)
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_ILNA_OFFSET_SHIFT (0U)
/*! DCOC_ILNA_OFFSET - DCOC_ILNA_OFFSET */
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_ILNA_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL1_DCOC_ILNA_OFFSET_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL1_DCOC_ILNA_OFFSET_MASK)

#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_QLNA_OFFSET_MASK (0x3F00U)
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_QLNA_OFFSET_SHIFT (8U)
/*! DCOC_QLNA_OFFSET - DCOC_QLNA_OFFSET */
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_QLNA_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL1_DCOC_QLNA_OFFSET_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL1_DCOC_QLNA_OFFSET_MASK)

#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_ICBPF_OFFSET_MASK (0x3F0000U)
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_ICBPF_OFFSET_SHIFT (16U)
/*! DCOC_ICBPF_OFFSET - DCOC_ICBPF_OFFSET */
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_ICBPF_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL1_DCOC_ICBPF_OFFSET_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL1_DCOC_ICBPF_OFFSET_MASK)

#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_QCBPF_OFFSET_MASK (0x3F000000U)
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_QCBPF_OFFSET_SHIFT (24U)
/*! DCOC_QCBPF_OFFSET - DCOC_QCBPF_OFFSET */
#define XCVR_RX_DIG_DCOC_CTRL1_DCOC_QCBPF_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL1_DCOC_QCBPF_OFFSET_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL1_DCOC_QCBPF_OFFSET_MASK)
/*! @} */

/*! @name DCOC_CTRL2 - DCOC CONTROL 2 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_I_MASK (0x3FU)
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_I_SHIFT (0U)
/*! DCOC_DAC_OVRD_I - DCOC_DAC_OVRD_I */
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_I_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_I_MASK)

#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_Q_MASK (0x3F00U)
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_Q_SHIFT (8U)
/*! DCOC_DAC_OVRD_Q - DCOC_DAC_OVRD_Q */
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_Q_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL2_DCOC_DAC_OVRD_Q_MASK)

#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_I_MASK (0x7F0000U)
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_I_SHIFT (16U)
/*! DCOC_ADC_OFFSET_OVRD_I - DCOC_ADC_OFFSET_OVRD_I */
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_I_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_I_MASK)

#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_Q_MASK (0x7F000000U)
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_Q_SHIFT (24U)
/*! DCOC_ADC_OFFSET_OVRD_Q - DCOC_ADC_OFFSET_OVRD_Q */
#define XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_Q_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL2_DCOC_ADC_OFFSET_OVRD_Q_MASK)
/*! @} */

/*! @name DCOC_STAT - DCOC Status */
/*! @{ */

#define XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_I_MASK (0x3FU)
#define XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_I_SHIFT (0U)
/*! CBPF_CODE_DCOC_I - CBPF_CODE_DCOC_I */
#define XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_I_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_I_MASK)

#define XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_Q_MASK (0x3F00U)
#define XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_Q_SHIFT (8U)
/*! CBPF_CODE_DCOC_Q - CBPF_CODE_DCOC_Q */
#define XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_Q_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_CBPF_CODE_DCOC_Q_MASK)

#define XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_I_MASK (0x7F0000U)
#define XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_I_SHIFT (16U)
/*! DCOC_ADC_OFFSET_I - DCOC_ADC_OFFSET_I */
#define XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_I_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_I_MASK)

#define XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_Q_MASK (0x7F000000U)
#define XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_Q_SHIFT (24U)
/*! DCOC_ADC_OFFSET_Q - DCOC_ADC_OFFSET_Q */
#define XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_Q_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_DCOC_ADC_OFFSET_Q_MASK)

#define XCVR_RX_DIG_DCOC_STAT_DCOC_DONE_MASK     (0x80000000U)
#define XCVR_RX_DIG_DCOC_STAT_DCOC_DONE_SHIFT    (31U)
#define XCVR_RX_DIG_DCOC_STAT_DCOC_DONE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_DCOC_DONE_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_DCOC_DONE_MASK)
/*! @} */

/*! @name IQMC_CTRL0 - IQ Mismatch Control 0 */
/*! @{ */

#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_EN_MASK  (0x1U)
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_EN_SHIFT (0U)
/*! IQMC_CAL_EN - IQ Mismatch Cal Enable */
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_EN_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_EN_MASK)

#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_FREQ_SEL_MASK (0x2U)
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_FREQ_SEL_SHIFT (1U)
/*! IQMC_CAL_FREQ_SEL - IQMC_CAL_FREQ_SEL
 *  0b0..Reference clk divided by 2
 *  0b1..Reference clk divided by 4
 */
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_FREQ_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_FREQ_SEL_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL0_IQMC_CAL_FREQ_SEL_MASK)

#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_NUM_ITER_MASK (0xFF00U)
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_NUM_ITER_SHIFT (8U)
/*! IQMC_NUM_ITER - IQ Mismatch Cal Num Iter */
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_NUM_ITER(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL0_IQMC_NUM_ITER_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL0_IQMC_NUM_ITER_MASK)

#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_DC_GAIN_ADJ_MASK (0x7FF0000U)
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_DC_GAIN_ADJ_SHIFT (16U)
/*! IQMC_DC_GAIN_ADJ - IQ Mismatch gain adjust */
#define XCVR_RX_DIG_IQMC_CTRL0_IQMC_DC_GAIN_ADJ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL0_IQMC_DC_GAIN_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL0_IQMC_DC_GAIN_ADJ_MASK)
/*! @} */

/*! @name IQMC_CTRL1 - IQ Mismatch Control 1 */
/*! @{ */

#define XCVR_RX_DIG_IQMC_CTRL1_IQMC_GAIN_ADJ_MASK (0x7FFU)
#define XCVR_RX_DIG_IQMC_CTRL1_IQMC_GAIN_ADJ_SHIFT (0U)
/*! IQMC_GAIN_ADJ - IQ Mismatch Correction Gain Coeff */
#define XCVR_RX_DIG_IQMC_CTRL1_IQMC_GAIN_ADJ(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL1_IQMC_GAIN_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL1_IQMC_GAIN_ADJ_MASK)

#define XCVR_RX_DIG_IQMC_CTRL1_IQMC_PHASE_ADJ_MASK (0xFFF0000U)
#define XCVR_RX_DIG_IQMC_CTRL1_IQMC_PHASE_ADJ_SHIFT (16U)
/*! IQMC_PHASE_ADJ - IQ Mismatch Correction Phase Coeff */
#define XCVR_RX_DIG_IQMC_CTRL1_IQMC_PHASE_ADJ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL1_IQMC_PHASE_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL1_IQMC_PHASE_ADJ_MASK)
/*! @} */

/*! @name ACQ_FILT_0_3 - Acquisition Filter Coeffs 0~3 */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_0_3_H0_MASK         (0x3FU)
#define XCVR_RX_DIG_ACQ_FILT_0_3_H0_SHIFT        (0U)
/*! H0 - Acquisition Filter Coefficient 0 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_H0(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_H0_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_H0_MASK)

#define XCVR_RX_DIG_ACQ_FILT_0_3_H1_MASK         (0x3F00U)
#define XCVR_RX_DIG_ACQ_FILT_0_3_H1_SHIFT        (8U)
/*! H1 - Acquisition Filter Coefficient 1 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_H1(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_H1_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_H1_MASK)

#define XCVR_RX_DIG_ACQ_FILT_0_3_H2_MASK         (0x7F0000U)
#define XCVR_RX_DIG_ACQ_FILT_0_3_H2_SHIFT        (16U)
/*! H2 - Acquisition Filter Coefficient 2 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_H2(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_H2_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_H2_MASK)

#define XCVR_RX_DIG_ACQ_FILT_0_3_H3_MASK         (0x7F000000U)
#define XCVR_RX_DIG_ACQ_FILT_0_3_H3_SHIFT        (24U)
/*! H3 - Acquisition Filter Coefficient 3 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_H3(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_H3_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_H3_MASK)
/*! @} */

/*! @name ACQ_FILT_4_7 - Acquisition Filter Coeffs 4~7 */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_4_7_H4_MASK         (0x7FU)
#define XCVR_RX_DIG_ACQ_FILT_4_7_H4_SHIFT        (0U)
/*! H4 - Acquisition Filter Coefficient 4 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_H4(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_H4_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_H4_MASK)

#define XCVR_RX_DIG_ACQ_FILT_4_7_H5_MASK         (0x7F00U)
#define XCVR_RX_DIG_ACQ_FILT_4_7_H5_SHIFT        (8U)
/*! H5 - Acquisition Filter Coefficient 5 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_H5(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_H5_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_H5_MASK)

#define XCVR_RX_DIG_ACQ_FILT_4_7_H6_MASK         (0xFF0000U)
#define XCVR_RX_DIG_ACQ_FILT_4_7_H6_SHIFT        (16U)
/*! H6 - Acquisition Filter Coefficient 6 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_H6(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_H6_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_H6_MASK)

#define XCVR_RX_DIG_ACQ_FILT_4_7_H7_MASK         (0xFF000000U)
#define XCVR_RX_DIG_ACQ_FILT_4_7_H7_SHIFT        (24U)
/*! H7 - Acquisition Filter Coefficient 7 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_H7(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_H7_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_H7_MASK)
/*! @} */

/*! @name ACQ_FILT_8_9 - Acquisition Filter Coeffs 8~9 */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_8_9_H8_MASK         (0x1FFU)
#define XCVR_RX_DIG_ACQ_FILT_8_9_H8_SHIFT        (0U)
/*! H8 - Acquisition Filter Coefficient 8 */
#define XCVR_RX_DIG_ACQ_FILT_8_9_H8(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_8_9_H8_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_8_9_H8_MASK)

#define XCVR_RX_DIG_ACQ_FILT_8_9_H9_MASK         (0x1FF0000U)
#define XCVR_RX_DIG_ACQ_FILT_8_9_H9_SHIFT        (16U)
/*! H9 - Acquisition Filter Coefficient 9 */
#define XCVR_RX_DIG_ACQ_FILT_8_9_H9(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_8_9_H9_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_8_9_H9_MASK)
/*! @} */

/*! @name ACQ_FILT_10_11 - Acquisition Filter Coeffs 10~11 */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_10_11_H10_MASK      (0x3FFU)
#define XCVR_RX_DIG_ACQ_FILT_10_11_H10_SHIFT     (0U)
/*! H10 - Acquisition Filter Coefficient 10 */
#define XCVR_RX_DIG_ACQ_FILT_10_11_H10(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_10_11_H10_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_10_11_H10_MASK)

#define XCVR_RX_DIG_ACQ_FILT_10_11_H11_MASK      (0x3FF0000U)
#define XCVR_RX_DIG_ACQ_FILT_10_11_H11_SHIFT     (16U)
/*! H11 - Acquisition Filter Coefficient 11 */
#define XCVR_RX_DIG_ACQ_FILT_10_11_H11(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_10_11_H11_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_10_11_H11_MASK)
/*! @} */

/*! @name DEMOD_FILT_0_1 - Demod Filter Coeffs 0~1 */
/*! @{ */

#define XCVR_RX_DIG_DEMOD_FILT_0_1_H0_MASK       (0x1FFU)
#define XCVR_RX_DIG_DEMOD_FILT_0_1_H0_SHIFT      (0U)
/*! H0 - Demod Channel Filter Coefficient 0 */
#define XCVR_RX_DIG_DEMOD_FILT_0_1_H0(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_0_1_H0_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_0_1_H0_MASK)

#define XCVR_RX_DIG_DEMOD_FILT_0_1_H1_MASK       (0x1FF0000U)
#define XCVR_RX_DIG_DEMOD_FILT_0_1_H1_SHIFT      (16U)
/*! H1 - Demod Channel Filter Coefficient 1 */
#define XCVR_RX_DIG_DEMOD_FILT_0_1_H1(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_0_1_H1_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_0_1_H1_MASK)
/*! @} */

/*! @name DEMOD_FILT_2_4 - Demod Filter Coeffs 2~4 */
/*! @{ */

#define XCVR_RX_DIG_DEMOD_FILT_2_4_H2_MASK       (0x3FFU)
#define XCVR_RX_DIG_DEMOD_FILT_2_4_H2_SHIFT      (0U)
/*! H2 - Demod Channel Filter Coefficient 2 */
#define XCVR_RX_DIG_DEMOD_FILT_2_4_H2(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_2_4_H2_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_2_4_H2_MASK)

#define XCVR_RX_DIG_DEMOD_FILT_2_4_H3_MASK       (0xFFC00U)
#define XCVR_RX_DIG_DEMOD_FILT_2_4_H3_SHIFT      (10U)
/*! H3 - Demod Channel Filter Coefficient 3 */
#define XCVR_RX_DIG_DEMOD_FILT_2_4_H3(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_2_4_H3_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_2_4_H3_MASK)

#define XCVR_RX_DIG_DEMOD_FILT_2_4_H4_MASK       (0x3FF00000U)
#define XCVR_RX_DIG_DEMOD_FILT_2_4_H4_SHIFT      (20U)
/*! H4 - Demod Channel Filter Coefficient 4 */
#define XCVR_RX_DIG_DEMOD_FILT_2_4_H4(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_2_4_H4_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_2_4_H4_MASK)
/*! @} */

/*! @name ACQ_FILT_0_3_DRS - Acquisition Filter Coeffs 0~3 DRS */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H0_MASK     (0x3FU)
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H0_SHIFT    (0U)
/*! H0 - Acquisition Filter Coefficient 0 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H0(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H0_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H0_MASK)

#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H1_MASK     (0x3F00U)
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H1_SHIFT    (8U)
/*! H1 - Acquisition Filter Coefficient 1 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H1(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H1_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H1_MASK)

#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H2_MASK     (0x7F0000U)
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H2_SHIFT    (16U)
/*! H2 - Acquisition Filter Coefficient 2 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H2(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H2_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H2_MASK)

#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H3_MASK     (0x7F000000U)
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H3_SHIFT    (24U)
/*! H3 - Acquisition Filter Coefficient 3 */
#define XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H3(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H3_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_0_3_DRS_H3_MASK)
/*! @} */

/*! @name ACQ_FILT_4_7_DRS - Acquisition Filter Coeffs 4~7 DRS */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H4_MASK     (0x7FU)
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H4_SHIFT    (0U)
/*! H4 - Acquisition Filter Coefficient 4 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H4(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H4_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H4_MASK)

#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H5_MASK     (0x7F00U)
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H5_SHIFT    (8U)
/*! H5 - Acquisition Filter Coefficient 5 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H5(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H5_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H5_MASK)

#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H6_MASK     (0xFF0000U)
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H6_SHIFT    (16U)
/*! H6 - Acquisition Filter Coefficient 6 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H6(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H6_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H6_MASK)

#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H7_MASK     (0xFF000000U)
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H7_SHIFT    (24U)
/*! H7 - Acquisition Filter Coefficient 7 */
#define XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H7(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H7_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_4_7_DRS_H7_MASK)
/*! @} */

/*! @name ACQ_FILT_8_9_DRS - Acquisition Filter Coeffs 8~9 DRS */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H8_MASK     (0x1FFU)
#define XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H8_SHIFT    (0U)
/*! H8 - Acquisition Filter Coefficient 8 */
#define XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H8(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H8_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H8_MASK)

#define XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H9_MASK     (0x1FF0000U)
#define XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H9_SHIFT    (16U)
/*! H9 - Acquisition Filter Coefficient 9 */
#define XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H9(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H9_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_8_9_DRS_H9_MASK)
/*! @} */

/*! @name ACQ_FILT_10_11_DRS - Acquisition Filter Coeffs 10~11 DRS */
/*! @{ */

#define XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H10_MASK  (0x3FFU)
#define XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H10_SHIFT (0U)
/*! H10 - Acquisition Filter Coefficient 10 */
#define XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H10(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H10_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H10_MASK)

#define XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H11_MASK  (0x3FF0000U)
#define XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H11_SHIFT (16U)
/*! H11 - Acquisition Filter Coefficient 11 */
#define XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H11(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H11_SHIFT)) & XCVR_RX_DIG_ACQ_FILT_10_11_DRS_H11_MASK)
/*! @} */

/*! @name DEMOD_FILT_0_1_DRS - Demod Filter Coeffs 0~1 DRS */
/*! @{ */

#define XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H0_MASK   (0x1FFU)
#define XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H0_SHIFT  (0U)
/*! H0 - Demod Channel Filter Coefficient 0 */
#define XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H0(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H0_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H0_MASK)

#define XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H1_MASK   (0x1FF0000U)
#define XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H1_SHIFT  (16U)
/*! H1 - Demod Channel Filter Coefficient 1 */
#define XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H1(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H1_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_0_1_DRS_H1_MASK)
/*! @} */

/*! @name DEMOD_FILT_2_4_DRS - Demod Filter Coeffs 2~4 DRS */
/*! @{ */

#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H2_MASK   (0x3FFU)
#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H2_SHIFT  (0U)
/*! H2 - Demod Channel Filter Coefficient 2 */
#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H2(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H2_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H2_MASK)

#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H3_MASK   (0xFFC00U)
#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H3_SHIFT  (10U)
/*! H3 - Demod Channel Filter Coefficient 3 */
#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H3(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H3_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H3_MASK)

#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H4_MASK   (0x3FF00000U)
#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H4_SHIFT  (20U)
/*! H4 - Demod Channel Filter Coefficient 4 */
#define XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H4(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H4_SHIFT)) & XCVR_RX_DIG_DEMOD_FILT_2_4_DRS_H4_MASK)
/*! @} */

/*! @name RSSI_GLOBAL_CTRL - RSSI Global Control */
/*! @{ */

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_INPUT_SEL_MASK (0x3U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_INPUT_SEL_SHIFT (0U)
/*! NB_RSSI_INPUT_SEL - NB RSSI Input Select
 *  0b00..ACQ_CHF output I/Q
 *  0b01..SRC output I/Q
 *  0b10..DEMOD_CHF output I/Q
 *  0b11..
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_INPUT_SEL_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_INPUT_SEL_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_MASK (0x4U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_SHIFT (2U)
/*! NB_RSSI_AA_MATCH_OVRD - NB RSSI PHY Trigger Override */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_EN_MASK (0x8U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_EN_SHIFT (3U)
/*! NB_RSSI_AA_MATCH_OVRD_EN - NB RSSI PHY Trigger Override Enable */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_EN_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_AA_MATCH_OVRD_EN_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_PA_AA_MATCH_SEL_MASK (0x10U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_PA_AA_MATCH_SEL_SHIFT (4U)
/*! NB_RSSI_PA_AA_MATCH_SEL - NB RSSI PHY Trigger Select
 *  0b0..NB-RSSI starts work when PHY_PD_FOUND asserted
 *  0b1..NB-RSSI starts work when PHY_AA_MATCH asserted
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_PA_AA_MATCH_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_PA_AA_MATCH_SEL_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_PA_AA_MATCH_SEL_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CCA1_ED_EN_MASK (0x20U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CCA1_ED_EN_SHIFT (5U)
/*! NB_CCA1_ED_EN - NB RSSI CCA1 ED Enable
 *  0b0..NB-RSSI CCA1/ED is disabled
 *  0b1..NB-RSSI CCA1/ED is enabled
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CCA1_ED_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CCA1_ED_EN_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CCA1_ED_EN_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_MASK (0x40U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_SHIFT (6U)
/*! NB_CONT_MEAS_OVRD - NB RSSI Onetime Measure Override */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_EN_MASK (0x80U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_EN_SHIFT (7U)
/*! NB_CONT_MEAS_OVRD_EN - NB RSSI One-time Measure Override Enable */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_EN_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_CONT_MEAS_OVRD_EN_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_SNR_LQI_ENABLE_MASK (0x100U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_SNR_LQI_ENABLE_SHIFT (8U)
/*! NB_SNR_LQI_ENABLE - NB RSSI SNR LQI Enable
 *  0b0..NB-RSSI SNR/LQI calculation is disabled
 *  0b1..NB-RSSI SNR/LQI calculation is enabled
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_SNR_LQI_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_SNR_LQI_ENABLE_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_SNR_LQI_ENABLE_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_CCA1_ED_FROM_NB_MASK (0x200U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_CCA1_ED_FROM_NB_SHIFT (9U)
/*! CCA1_ED_FROM_NB - CCA1/ED Result Selection
 *  0b0..WB-RSSI's CCA1/ED result is selected
 *  0b1..NB-RSSI's CCA1/ED result is selected
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_CCA1_ED_FROM_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_CCA1_ED_FROM_NB_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_CCA1_ED_FROM_NB_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_EN_MASK (0x8000U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_EN_SHIFT (15U)
/*! NB_RSSI_EN - NB RSSI Enable
 *  0b0..NB-RSSI is disabled
 *  0b1..NB-RSSI is enabled
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_EN_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_NB_RSSI_EN_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_INPUT_SEL_MASK (0x10000U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_INPUT_SEL_SHIFT (16U)
/*! WB_RSSI_INPUT_SEL - WB RSSI Input Select
 *  0b0..DCOC output I/Q
 *  0b1..CIC output I/Q
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_INPUT_SEL_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_INPUT_SEL_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CCA1_ED_EN_MASK (0x100000U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CCA1_ED_EN_SHIFT (20U)
/*! WB_CCA1_ED_EN - WB RSSI CCA1 ED Enable
 *  0b0..WB-RSSI CCA1/ED disabled
 *  0b1..WB-RSSI CCA1/ED enabled
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CCA1_ED_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CCA1_ED_EN_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CCA1_ED_EN_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_MASK (0x200000U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_SHIFT (21U)
/*! WB_CONT_MEAS_OVRD - WB RSSI Continuous Measurment Override Value */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_EN_MASK (0x400000U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_EN_SHIFT (22U)
/*! WB_CONT_MEAS_OVRD_EN - WB RSSI Continuous Measurement Override Enable */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_EN_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_CONT_MEAS_OVRD_EN_MASK)

#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_EN_MASK (0x80000000U)
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_EN_SHIFT (31U)
/*! WB_RSSI_EN - WB RSSI Enable
 *  0b0..WB-RSSI is disabled
 *  0b1..WB-RSSI is enabled
 */
#define XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_EN_SHIFT)) & XCVR_RX_DIG_RSSI_GLOBAL_CTRL_WB_RSSI_EN_MASK)
/*! @} */

/*! @name WB_RSSI_CTRL - Wide-Band RSSI Control */
/*! @{ */

#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_MASK (0x7U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_SHIFT (0U)
/*! RSSI_N_WINDOW_WB - WB RSSI N Window Averager Factor */
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_M_WINDOW_WB_MASK (0x70U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_M_WINDOW_WB_SHIFT (4U)
/*! RSSI_M_WINDOW_WB - WB RSSI M Window Averager Factor */
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_M_WINDOW_WB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_M_WINDOW_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_M_WINDOW_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_MASK (0x700U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_SHIFT (8U)
/*! RSSI_F_WINDOW_WB - WB RSSI F Window Averager Factor */
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_DB_EN_WB_MASK (0x1000U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_DB_EN_WB_SHIFT (12U)
/*! RSSI_DB_EN_WB - WB RSSI dB Calculate Enable */
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_DB_EN_WB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_DB_EN_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_DB_EN_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_CTRL_KEEP_RSSI_RESULT_WB_MASK (0x2000U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_KEEP_RSSI_RESULT_WB_SHIFT (13U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_KEEP_RSSI_RESULT_WB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_KEEP_RSSI_RESULT_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_KEEP_RSSI_RESULT_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_DRS_MASK (0x70000U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_DRS_SHIFT (16U)
/*! RSSI_N_WINDOW_WB_DRS - DRS WB RSSI N Window Averager Factor */
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_DRS_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_N_WINDOW_WB_DRS_MASK)

#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_DRS_MASK (0x700000U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_DRS_SHIFT (20U)
/*! RSSI_F_WINDOW_WB_DRS - DRS WB RSSI F Window Averager Factor */
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_DRS_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_F_WINDOW_WB_DRS_MASK)

#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_ADJ_WB_MASK (0xFF000000U)
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_ADJ_WB_SHIFT (24U)
/*! RSSI_ADJ_WB - WB RSSI Adjust Value */
#define XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_ADJ_WB(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_ADJ_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_CTRL_RSSI_ADJ_WB_MASK)
/*! @} */

/*! @name WB_RSSI_RES0 - Wide-Band RSSI Result 0 */
/*! @{ */

#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_WB_MASK    (0x1FFU)
#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_WB_SHIFT   (0U)
/*! RSSI_WB - WB RSSI Result */
#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_WB(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_RES0_RSSI_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_RES0_RSSI_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RDY_WB_MASK (0x8000U)
#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RDY_WB_SHIFT (15U)
#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RDY_WB(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RDY_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RDY_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RAW_WB_MASK (0xFF0000U)
#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RAW_WB_SHIFT (16U)
/*! RSSI_RAW_WB - WB Raw RSSI Result */
#define XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RAW_WB(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RAW_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_RES0_RSSI_RAW_WB_MASK)
/*! @} */

/*! @name WB_RSSI_RES1 - Wide-Band RSSI Result 1 */
/*! @{ */

#define XCVR_RX_DIG_WB_RSSI_RES1_ED_WB_MASK      (0xFFU)
#define XCVR_RX_DIG_WB_RSSI_RES1_ED_WB_SHIFT     (0U)
/*! ED_WB - WB RSSI ED Result */
#define XCVR_RX_DIG_WB_RSSI_RES1_ED_WB(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_RES1_ED_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_RES1_ED_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_RES1_CCA1_STATE_WB_MASK (0x40000000U)
#define XCVR_RX_DIG_WB_RSSI_RES1_CCA1_STATE_WB_SHIFT (30U)
/*! CCA1_STATE_WB - WB RSSI CCA1 State */
#define XCVR_RX_DIG_WB_RSSI_RES1_CCA1_STATE_WB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_RES1_CCA1_STATE_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_RES1_CCA1_STATE_WB_MASK)

#define XCVR_RX_DIG_WB_RSSI_RES1_MEAS_COMPLETE_WB_MASK (0x80000000U)
#define XCVR_RX_DIG_WB_RSSI_RES1_MEAS_COMPLETE_WB_SHIFT (31U)
/*! MEAS_COMPLETE_WB - WB RSSI Measure Complete */
#define XCVR_RX_DIG_WB_RSSI_RES1_MEAS_COMPLETE_WB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_RES1_MEAS_COMPLETE_WB_SHIFT)) & XCVR_RX_DIG_WB_RSSI_RES1_MEAS_COMPLETE_WB_MASK)
/*! @} */

/*! @name WB_RSSI_DFT - Wide-Band RSSI DFT Result */
/*! @{ */

#define XCVR_RX_DIG_WB_RSSI_DFT_SLOW_MAG_MASK    (0x3FFU)
#define XCVR_RX_DIG_WB_RSSI_DFT_SLOW_MAG_SHIFT   (0U)
/*! SLOW_MAG - WB RSSI Slow Magnitude Value */
#define XCVR_RX_DIG_WB_RSSI_DFT_SLOW_MAG(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_DFT_SLOW_MAG_SHIFT)) & XCVR_RX_DIG_WB_RSSI_DFT_SLOW_MAG_MASK)

#define XCVR_RX_DIG_WB_RSSI_DFT_FAST_MAG_MASK    (0xFFC00U)
#define XCVR_RX_DIG_WB_RSSI_DFT_FAST_MAG_SHIFT   (10U)
/*! FAST_MAG - WB RSSI Fast Magnitude Value */
#define XCVR_RX_DIG_WB_RSSI_DFT_FAST_MAG(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_WB_RSSI_DFT_FAST_MAG_SHIFT)) & XCVR_RX_DIG_WB_RSSI_DFT_FAST_MAG_MASK)
/*! @} */

/*! @name NB_RSSI_CTRL0 - Narrow-Band RSSI Control 0 */
/*! @{ */

#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_N_WINDOW_NB_MASK (0xFU)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_N_WINDOW_NB_SHIFT (0U)
/*! RSSI_N_WINDOW_NB - NB RSSI N Window Averager Factor */
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_N_WINDOW_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_N_WINDOW_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_N_WINDOW_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_M_WINDOW_NB_MASK (0xF0U)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_M_WINDOW_NB_SHIFT (4U)
/*! RSSI_M_WINDOW_NB - NB RSSI M Window Averager Factor */
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_M_WINDOW_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_M_WINDOW_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_M_WINDOW_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WAIT_NB_MASK (0x700U)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WAIT_NB_SHIFT (8U)
/*! RSSI_IIR_WAIT_NB - NB RSSI IIR Filter Initial Wait Time */
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WAIT_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WAIT_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WAIT_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WT_NB_MASK (0x7000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WT_NB_SHIFT (12U)
/*! RSSI_IIR_WT_NB - NB RSSI IIR Filter Factor */
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WT_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WT_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_IIR_WT_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL0_SNR_ADJ_NB_MASK (0x3F0000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_SNR_ADJ_NB_SHIFT (16U)
/*! SNR_ADJ_NB - NB RSSI SNR Adjust Value */
#define XCVR_RX_DIG_NB_RSSI_CTRL0_SNR_ADJ_NB(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL0_SNR_ADJ_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL0_SNR_ADJ_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL0_KEEP_RSSI_RESULT_NB_MASK (0x400000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_KEEP_RSSI_RESULT_NB_SHIFT (22U)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_KEEP_RSSI_RESULT_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL0_KEEP_RSSI_RESULT_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL0_KEEP_RSSI_RESULT_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_ADJ_NB_MASK (0xFF000000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_ADJ_NB_SHIFT (24U)
/*! RSSI_ADJ_NB - NB RSSI Adjust Value */
#define XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_ADJ_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_ADJ_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL0_RSSI_ADJ_NB_MASK)
/*! @} */

/*! @name NB_RSSI_CTRL1 - Narrow-Band RSSI Control 1 */
/*! @{ */

#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_WEIGHT_MASK (0x70000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_WEIGHT_SHIFT (16U)
/*! LQI_RSSI_WEIGHT - RSSI Weight For LQI Calulation */
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_WEIGHT_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_WEIGHT_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_SNR_WEIGHT_MASK (0xF00000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_SNR_WEIGHT_SHIFT (20U)
/*! LQI_SNR_WEIGHT - SNR Weight For LQI Calculation */
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_SNR_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_SNR_WEIGHT_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_SNR_WEIGHT_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_SENS_ADJ_MASK (0xF000000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_SENS_ADJ_SHIFT (24U)
/*! LQI_RSSI_SENS_ADJ - LQI Sensitivity Adjust Value */
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_SENS_ADJ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_SENS_ADJ_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_RSSI_SENS_ADJ_MASK)

#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_BIAS_MASK  (0xF0000000U)
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_BIAS_SHIFT (28U)
/*! LQI_BIAS - LQI Bias Value */
#define XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_BIAS(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_BIAS_SHIFT)) & XCVR_RX_DIG_NB_RSSI_CTRL1_LQI_BIAS_MASK)
/*! @} */

/*! @name NB_RSSI_RES0 - Narrow-Band RSSI Result 0 */
/*! @{ */

#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_NB_MASK    (0x1FFU)
#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_NB_SHIFT   (0U)
/*! RSSI_NB - NB RSSI Result */
#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_NB(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES0_RSSI_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES0_RSSI_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RDY_NB_MASK (0x8000U)
#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RDY_NB_SHIFT (15U)
#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RDY_NB(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RDY_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RDY_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RAW_NB_MASK (0xFF0000U)
#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RAW_NB_SHIFT (16U)
/*! RSSI_RAW_NB - Raw NB RSSI Result */
#define XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RAW_NB(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RAW_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES0_RSSI_RAW_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_RES0_NOISE_RSSI_RAW_NB_MASK (0xFF000000U)
#define XCVR_RX_DIG_NB_RSSI_RES0_NOISE_RSSI_RAW_NB_SHIFT (24U)
/*! NOISE_RSSI_RAW_NB - Raw Noise Result */
#define XCVR_RX_DIG_NB_RSSI_RES0_NOISE_RSSI_RAW_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES0_NOISE_RSSI_RAW_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES0_NOISE_RSSI_RAW_NB_MASK)
/*! @} */

/*! @name NB_RSSI_RES1 - Narrow-Band RSSI Result 1 */
/*! @{ */

#define XCVR_RX_DIG_NB_RSSI_RES1_ED_NB_MASK      (0xFFU)
#define XCVR_RX_DIG_NB_RSSI_RES1_ED_NB_SHIFT     (0U)
/*! ED_NB - NB RSSI ED Result */
#define XCVR_RX_DIG_NB_RSSI_RES1_ED_NB(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES1_ED_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES1_ED_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_RES1_LQI_NB_MASK     (0xFF00U)
#define XCVR_RX_DIG_NB_RSSI_RES1_LQI_NB_SHIFT    (8U)
/*! LQI_NB - NB RSSI LQI Result */
#define XCVR_RX_DIG_NB_RSSI_RES1_LQI_NB(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES1_LQI_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES1_LQI_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_RES1_SNR_NB_MASK     (0x3F0000U)
#define XCVR_RX_DIG_NB_RSSI_RES1_SNR_NB_SHIFT    (16U)
/*! SNR_NB - NB RSSI SNR Result */
#define XCVR_RX_DIG_NB_RSSI_RES1_SNR_NB(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES1_SNR_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES1_SNR_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_RES1_CCA1_STATE_NB_MASK (0x40000000U)
#define XCVR_RX_DIG_NB_RSSI_RES1_CCA1_STATE_NB_SHIFT (30U)
/*! CCA1_STATE_NB - NB RSSI CCA1 State */
#define XCVR_RX_DIG_NB_RSSI_RES1_CCA1_STATE_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES1_CCA1_STATE_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES1_CCA1_STATE_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_RES1_MEAS_COMPLETE_NB_MASK (0x80000000U)
#define XCVR_RX_DIG_NB_RSSI_RES1_MEAS_COMPLETE_NB_SHIFT (31U)
/*! MEAS_COMPLETE_NB - NB RSSI Measure Complete */
#define XCVR_RX_DIG_NB_RSSI_RES1_MEAS_COMPLETE_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_RES1_MEAS_COMPLETE_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_RES1_MEAS_COMPLETE_NB_MASK)
/*! @} */

/*! @name NB_RSSI_DFT - Narrow-Band RSSI DFT Result */
/*! @{ */

#define XCVR_RX_DIG_NB_RSSI_DFT_AVG_NOISE_MAG_NB_MASK (0xFFFU)
#define XCVR_RX_DIG_NB_RSSI_DFT_AVG_NOISE_MAG_NB_SHIFT (0U)
/*! AVG_NOISE_MAG_NB - NB RSSI Averaged Noise Magnitude Value */
#define XCVR_RX_DIG_NB_RSSI_DFT_AVG_NOISE_MAG_NB(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_DFT_AVG_NOISE_MAG_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_DFT_AVG_NOISE_MAG_NB_MASK)

#define XCVR_RX_DIG_NB_RSSI_DFT_AVG_MAG_NB_MASK  (0xFFF0000U)
#define XCVR_RX_DIG_NB_RSSI_DFT_AVG_MAG_NB_SHIFT (16U)
/*! AVG_MAG_NB - NB RSSI Averaged Magnitude Value */
#define XCVR_RX_DIG_NB_RSSI_DFT_AVG_MAG_NB(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NB_RSSI_DFT_AVG_MAG_NB_SHIFT)) & XCVR_RX_DIG_NB_RSSI_DFT_AVG_MAG_NB_MASK)
/*! @} */

/*! @name AGC_CTRL - AGC Control */
/*! @{ */

#define XCVR_RX_DIG_AGC_CTRL_AGC_UNHOLD_FEAT_EN_MASK (0x3U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_UNHOLD_FEAT_EN_SHIFT (0U)
/*! AGC_UNHOLD_FEAT_EN - AGC Unhold Enable */
#define XCVR_RX_DIG_AGC_CTRL_AGC_UNHOLD_FEAT_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_UNHOLD_FEAT_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_UNHOLD_FEAT_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_HOLD_EN_MASK    (0xCU)
#define XCVR_RX_DIG_AGC_CTRL_AGC_HOLD_EN_SHIFT   (2U)
/*! AGC_HOLD_EN - AGC Hold Mode Enable
 *  0b00..Disable AGC hold mode
 *  0b01..AGC hold when preamble found
 *  0b10..AGC hold when AGC hold timeout matched
 *  0b11..AGC hold when preamble found or hold timeout matched
 */
#define XCVR_RX_DIG_AGC_CTRL_AGC_HOLD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_HOLD_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_HOLD_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_STEP_MASK (0x70U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_STEP_SHIFT (4U)
/*! AGC_DELTA_SLOW_STEP - AGC Delta Slow Mode Gain Step Up Value */
#define XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_STEP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_STEP_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_STEP_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_EN_MASK (0x80U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_EN_SHIFT (7U)
/*! AGC_DELTA_SLOW_EN - AGC Delta Slow Magnitude Mode Enable
 *  0b0..Disable AGC delta slow magnitude mode
 *  0b1..Enable AGC delta slow magnitude mode
 */
#define XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_DELTA_SLOW_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_SLOW_EN_MASK    (0x100U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_SLOW_EN_SHIFT   (8U)
/*! AGC_SLOW_EN - AGC Slow Magnitude Mode Enable
 *  0b0..Disable AGC slow magnitude mode
 *  0b1..Enable AGC slow magnitude mode
 */
#define XCVR_RX_DIG_AGC_CTRL_AGC_SLOW_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_SLOW_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_SLOW_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_FAST_STEP_UP_EN_MASK (0x200U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_FAST_STEP_UP_EN_SHIFT (9U)
/*! AGC_FAST_STEP_UP_EN - AGC Fast Magnitude Mode Step Up Enable
 *  0b0..Fast magnitude mode can only make AGC gain index step down
 *  0b1..Fast magnitude mode can make AGC gain index step down or step up
 */
#define XCVR_RX_DIG_AGC_CTRL_AGC_FAST_STEP_UP_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_FAST_STEP_UP_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_FAST_STEP_UP_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_FAST_EN_MASK    (0x400U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_FAST_EN_SHIFT   (10U)
/*! AGC_FAST_EN - AGC Fast Magnitude Mode Enable
 *  0b0..Disable fast magnitude mode
 *  0b1..Enable fast magnitude mode
 */
#define XCVR_RX_DIG_AGC_CTRL_AGC_FAST_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_FAST_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_FAST_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_SZ_MASK (0x3800U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_SZ_SHIFT (11U)
/*! AGC_WBD_STEP2_SZ - AGC WBD Step2 Gain Decrease Value */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_SZ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_SZ_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_SZ_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_SZ_MASK (0x1C000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_SZ_SHIFT (14U)
/*! AGC_WBD_STEP1_SZ - AGC WBD Step1 Gain Decrease Value */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_SZ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_SZ_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_SZ_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR2_MASK   (0x1E0000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR2_SHIFT  (17U)
/*! AGC_WBD_THR2 - AGC WBD Step2 threshold */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR2(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR2_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR2_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR1_MASK   (0x1E00000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR1_SHIFT  (21U)
/*! AGC_WBD_THR1 - AGC WBD Step1 threshold
 *  0b0000..49.31
 *  0b0001..67.56
 *  0b0010..90.98
 *  0b0011..117.42
 *  0b0100..150.66
 *  0b0101..180.98
 *  0b0110..211.87
 *  0b0111..245.2
 *  0b1000..288.31
 *  0b1001..336.02
 *  0b1010..394.34
 *  0b1011..462.71
 *  0b1100..548.04
 *  0b1101..650.13
 *  0b1110..771.65
 *  0b1111..918.12
 */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR1(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR1_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_THR1_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_DUAL_CLIP_EN_MASK (0x2000000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_DUAL_CLIP_EN_SHIFT (25U)
/*! AGC_WBD_STEP2_DUAL_CLIP_EN - AGC WBD Step2 Dual Clip Enable */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_DUAL_CLIP_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_DUAL_CLIP_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP2_DUAL_CLIP_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_DUAL_CLIP_EN_MASK (0x4000000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_DUAL_CLIP_EN_SHIFT (26U)
/*! AGC_WBD_STEP1_DUAL_CLIP_EN - AGC WBD Step1 Dual Clip Enable */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_DUAL_CLIP_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_DUAL_CLIP_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_STEP1_DUAL_CLIP_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_GAIN_LIMIT_EN_MASK (0x8000000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_GAIN_LIMIT_EN_SHIFT (27U)
/*! AGC_WBD_GAIN_LIMIT_EN - AGC WBD Gain Limit */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_GAIN_LIMIT_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_GAIN_LIMIT_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_GAIN_LIMIT_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_AUTO_DIS_CFG_MASK (0x30000000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_AUTO_DIS_CFG_SHIFT (28U)
/*! AGC_WBD_AUTO_DIS_CFG - AGC WBD Auto Disable */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_AUTO_DIS_CFG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_AUTO_DIS_CFG_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_AUTO_DIS_CFG_MASK)

#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_EN_MASK     (0xC0000000U)
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_EN_SHIFT    (30U)
/*! AGC_WBD_EN - AGC WBD Enable
 *  0b00..AGC WBD is disabled
 *  0b01..AGC WBD step1 is enabled
 *  0b10..AGC WBD step1 and step2 is enabled
 *  0b11..Reserved
 */
#define XCVR_RX_DIG_AGC_CTRL_AGC_WBD_EN(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_AGC_WBD_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_AGC_WBD_EN_MASK)
/*! @} */

/*! @name AGC_CTRL_STAT - AGC Control Status */
/*! @{ */

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_MAX_IDX_MASK (0x3U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_MAX_IDX_SHIFT (0U)
/*! AGC_MAX_IDX - AGC Max Gain Index */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_MAX_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_MAX_IDX_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_MAX_IDX_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_INIT_IDX_MASK (0x3CU)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_INIT_IDX_SHIFT (2U)
/*! AGC_INIT_IDX - AGC Initial Gain Index */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_INIT_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_INIT_IDX_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_INIT_IDX_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_HOLD_TRIG_SEL_MASK (0x40U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_HOLD_TRIG_SEL_SHIFT (6U)
/*! AGC_PHY_HOLD_TRIG_SEL - AGC PHY Hold Trigger Select
 *  0b0..PHY_AGC_HOLD_TRIG is select as AGC hold trig.
 *  0b1..PHY_AGC_FREEZE_TRIG is select as AGC hold trig.
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_HOLD_TRIG_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_HOLD_TRIG_SEL_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_HOLD_TRIG_SEL_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_FREEZE_TRIG_SEL_MASK (0x80U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_FREEZE_TRIG_SEL_SHIFT (7U)
/*! AGC_PHY_FREEZE_TRIG_SEL - AGC PHY Freeze Trigger Select
 *  0b0..PHY_AGC_FREEZE_TRIG is select as AGC freeze trig.
 *  0b1..PHY_AGC_HOLD_TRIG is select as AGC freeze trig.
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_FREEZE_TRIG_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_FREEZE_TRIG_SEL_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PHY_FREEZE_TRIG_SEL_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_CALC_MAG_IN_FRZ_MASK (0x100U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_CALC_MAG_IN_FRZ_SHIFT (8U)
/*! AGC_CALC_MAG_IN_FRZ - AGC Calculate Magnitude In Freeze Mode */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_CALC_MAG_IN_FRZ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_CALC_MAG_IN_FRZ_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_CALC_MAG_IN_FRZ_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_UNFREEZE_FEAT_EN_MASK (0x200U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_UNFREEZE_FEAT_EN_SHIFT (9U)
/*! AGC_UNFREEZE_FEAT_EN - AGC Unfreeze Feature Enable
 *  0b0..AGC unfreeze function is disabled
 *  0b1..AGC will exit FREEZE mode when AGC_UNFREEZE_TMEOUT matched and aa_found not be asserted
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_UNFREEZE_FEAT_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_UNFREEZE_FEAT_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_UNFREEZE_FEAT_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_FREEZE_EN_MASK (0xC00U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_FREEZE_EN_SHIFT (10U)
/*! AGC_FREEZE_EN - AGC Freeze Mode Enable
 *  0b00..Disable AGC freeze mode
 *  0b01..AGC freeze when AA/SFD matched
 *  0b10..AGC freeze when AGC freeze timeout matched
 *  0b11..AGC freeze when AA/SFD matched or freeze timeout matched
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_FREEZE_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_FREEZE_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_FREEZE_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_STORE_MASK (0x3000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_STORE_SHIFT (12U)
/*! AGC_GAIN_IDX_STORE
 *  0b00..AGC gain index store function is disabled
 *  0b01..Store AGC gain index when AGC enter into HOLD mode
 *  0b10..Store AGC gain index when AGC enter into FREEZE mode
 *  0b11..Store AGC gain index when AA matched
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_STORE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_STORE_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_STORE_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_GAIN_SEL_MASK (0x4000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_GAIN_SEL_SHIFT (14U)
/*! AGC_SOFT_RST_GAIN_SEL - PHY AGC Soft Reset Gain Sel
 *  0b0..AGC keep current gain index when PHY AGC soft reset trigged,
 *  0b1..AGC return to AGC_INIT_IDX when PHY AGC soft reset trigged,
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_GAIN_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_GAIN_SEL_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_GAIN_SEL_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_SRC_SEL_MASK (0x18000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_SRC_SEL_SHIFT (15U)
/*! AGC_SOFT_RST_SRC_SEL - PHY AGC Soft Reset Sel
 *  0b00..Disable PHY AGC soft reset function
 *  0b01..Use posedge phy_soft_rst to reset AGC
 *  0b10..Use negedge phy_soft_rst to reset AGC
 *  0b11..Use negedge phy_agc_freeze_trig to reset AGC
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_SRC_SEL_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_SOFT_RST_SRC_SEL_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PREV_GAIN_IDX_MASK (0x1E0000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PREV_GAIN_IDX_SHIFT (17U)
/*! AGC_PREV_GAIN_IDX - AGC Previous Gain Index */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PREV_GAIN_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PREV_GAIN_IDX_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_PREV_GAIN_IDX_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_MASK (0x1E00000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_SHIFT (21U)
/*! AGC_GAIN_IDX - AGC Gain Index */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_IDX_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_MASK (0x2000000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_SHIFT (25U)
/*! AGC_GAIN_CHANGE - AGC Gain Change */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_STATUS_MASK (0x1C000000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_STATUS_SHIFT (26U)
/*! AGC_GAIN_CHANGE_STATUS - AGC Gain Change Status
 *  0b000..No gain change
 *  0b001..Gain decreased by WBD step1
 *  0b010..Gain decreased by WBD step2
 *  0b011..Gain decreased by fast mode
 *  0b100..Gain increased by fast mode
 *  0b101..Gain decreased by slow mode
 *  0b110..Gain increased by slow mode
 *  0b111..Gain increased by delta slow mode
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_STATUS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_STATUS_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_GAIN_CHANGE_STATUS_MASK)

#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_STATUS_MASK (0xE0000000U)
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_STATUS_SHIFT (29U)
/*! AGC_STATUS - AGC FSM Status
 *  0b000..AGC_IDLE
 *  0b001..AGC_WB_ONLY
 *  0b010..AGC_WB_MAG
 *  0b011..AGC_WB_DEBOUNCE
 *  0b100..AGC_MAG_ONLY
 *  0b101..AGC_HOLD
 *  0b110..AGC_FREEZE
 *  0b111..AGC_WAIT_GAIN_SETTLE
 */
#define XCVR_RX_DIG_AGC_CTRL_STAT_AGC_STATUS(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_STAT_AGC_STATUS_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_STAT_AGC_STATUS_MASK)
/*! @} */

/*! @name AGC_TIMING0 - AGC Timing Control 0 */
/*! @{ */

#define XCVR_RX_DIG_AGC_TIMING0_AGC_DELTA_SLOW_WAIT_MASK (0x3U)
#define XCVR_RX_DIG_AGC_TIMING0_AGC_DELTA_SLOW_WAIT_SHIFT (0U)
/*! AGC_DELTA_SLOW_WAIT - AGC Delta Slow Mode Timing */
#define XCVR_RX_DIG_AGC_TIMING0_AGC_DELTA_SLOW_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_AGC_DELTA_SLOW_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_AGC_DELTA_SLOW_WAIT_MASK)

#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP2_TIMEOUT_MASK (0x7CU)
#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP2_TIMEOUT_SHIFT (2U)
/*! AGC_WBD_STEP2_TIMEOUT - AGC WBD Step2 Timeout */
#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP2_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP2_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP2_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP1_TIMEOUT_MASK (0x380U)
#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP1_TIMEOUT_SHIFT (7U)
/*! AGC_WBD_STEP1_TIMEOUT - AGC WBD Timeout */
#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP1_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP1_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_STEP1_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING0_AGC_GAIN_STEP_WAIT_MASK (0xFC00U)
#define XCVR_RX_DIG_AGC_TIMING0_AGC_GAIN_STEP_WAIT_SHIFT (10U)
/*! AGC_GAIN_STEP_WAIT - AGC Gain Change Wait Time */
#define XCVR_RX_DIG_AGC_TIMING0_AGC_GAIN_STEP_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_AGC_GAIN_STEP_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_AGC_GAIN_STEP_WAIT_MASK)

#define XCVR_RX_DIG_AGC_TIMING0_AGC_MAG_INIT_WAIT_MASK (0x7F0000U)
#define XCVR_RX_DIG_AGC_TIMING0_AGC_MAG_INIT_WAIT_SHIFT (16U)
/*! AGC_MAG_INIT_WAIT - AGC Magnitude Mode Initial Wait Time */
#define XCVR_RX_DIG_AGC_TIMING0_AGC_MAG_INIT_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_AGC_MAG_INIT_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_AGC_MAG_INIT_WAIT_MASK)

#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_INIT_WAIT_MASK (0x7F000000U)
#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_INIT_WAIT_SHIFT (24U)
/*! AGC_WBD_INIT_WAIT - AGC WBD Mode Initial Wait Time */
#define XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_INIT_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_INIT_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_AGC_WBD_INIT_WAIT_MASK)
/*! @} */

/*! @name AGC_TIMING1 - AGC Timing Control 1 */
/*! @{ */

#define XCVR_RX_DIG_AGC_TIMING1_AGC_FREEZE_TIMEOUT_MASK (0x7FU)
#define XCVR_RX_DIG_AGC_TIMING1_AGC_FREEZE_TIMEOUT_SHIFT (0U)
/*! AGC_FREEZE_TIMEOUT - AGC FREEZE Mode Wait Time */
#define XCVR_RX_DIG_AGC_TIMING1_AGC_FREEZE_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_AGC_FREEZE_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_AGC_FREEZE_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING1_AGC_HOLD_TIMEOUT_MASK (0x3F80U)
#define XCVR_RX_DIG_AGC_TIMING1_AGC_HOLD_TIMEOUT_SHIFT (7U)
/*! AGC_HOLD_TIMEOUT - AGC HOLD Mode Wait Time */
#define XCVR_RX_DIG_AGC_TIMING1_AGC_HOLD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_AGC_HOLD_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_AGC_HOLD_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_DUAL_CLIP_WAIT_MASK (0x1C000U)
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_DUAL_CLIP_WAIT_SHIFT (14U)
/*! AGC_WBD_STEP2_DUAL_CLIP_WAIT - AGC WBD step2 Debounce Wait Time */
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_DUAL_CLIP_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_DUAL_CLIP_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_DUAL_CLIP_WAIT_MASK)

#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP1_DUAL_CLIP_WAIT_MASK (0xE0000U)
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP1_DUAL_CLIP_WAIT_SHIFT (17U)
/*! AGC_WBD_STEP1_DUAL_CLIP_WAIT - AGC WBD step1 Debounce Wait Time */
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP1_DUAL_CLIP_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP1_DUAL_CLIP_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP1_DUAL_CLIP_WAIT_MASK)

#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_WAIT_MASK (0x3F00000U)
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_WAIT_SHIFT (20U)
/*! AGC_WBD_STEP2_WAIT - AGC Gain Change Wait For WBD step2 */
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_STEP2_WAIT_MASK)

#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_DUAL_CLIP_TIMEOUT_MASK (0x3C000000U)
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_DUAL_CLIP_TIMEOUT_SHIFT (26U)
#define XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_DUAL_CLIP_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_DUAL_CLIP_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_AGC_WBD_DUAL_CLIP_TIMEOUT_MASK)
/*! @} */

/*! @name AGC_TIMING2 - AGC Timing Control 2 */
/*! @{ */

#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNFREEZE_FEAT_TIMEOUT_MASK (0x7FFU)
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNFREEZE_FEAT_TIMEOUT_SHIFT (0U)
/*! AGC_UNFREEZE_FEAT_TIMEOUT - AGC Unfreeze Feature Timeout */
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNFREEZE_FEAT_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING2_AGC_UNFREEZE_FEAT_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING2_AGC_UNFREEZE_FEAT_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_FEAT_TIMEOUT_MASK (0x1FF800U)
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_FEAT_TIMEOUT_SHIFT (11U)
/*! AGC_UNHOLD_FEAT_TIMEOUT - AGC Unhold Feature Timeout */
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_FEAT_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_FEAT_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_FEAT_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_GAIN_CHG_MASK (0x20000000U)
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_GAIN_CHG_SHIFT (29U)
/*! AGC_UNHOLD_GAIN_CHG - AGC Gain Index Change When UNHOLD */
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_GAIN_CHG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_GAIN_CHG_SHIFT)) & XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_GAIN_CHG_MASK)

#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_CNT_MASK (0x40000000U)
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_CNT_SHIFT (30U)
/*! AGC_UNHOLD_MAG_CNT - AGC Unhold Magnitude Count Selection
 *  0b0..Once the selected magnitude exceeds unhold margin, the AGC will exit HOLD mode
 *  0b1..Need two consecutive selected magnitude values exceeds unhold margin to let AGC exit HOLD mode
 */
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_CNT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_CNT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_CNT_MASK)

#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_SRC_MASK (0x80000000U)
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_SRC_SHIFT (31U)
/*! AGC_UNHOLD_MAG_SRC - AGC Magnitude Unhold Feature Source Selection
 *  0b0..fast_mag
 *  0b1..slow_mag
 */
#define XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_SRC(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_SRC_SHIFT)) & XCVR_RX_DIG_AGC_TIMING2_AGC_UNHOLD_MAG_SRC_MASK)
/*! @} */

/*! @name AGC_TIMING0_DRS - AGC Timing Control 0 DRS */
/*! @{ */

#define XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_GAIN_STEP_WAIT_MASK (0xFC00U)
#define XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_GAIN_STEP_WAIT_SHIFT (10U)
/*! AGC_GAIN_STEP_WAIT - AGC Gain Change Wait Time */
#define XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_GAIN_STEP_WAIT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_GAIN_STEP_WAIT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_GAIN_STEP_WAIT_MASK)

#define XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_WBD_EN_DRS_MASK (0xC0000000U)
#define XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_WBD_EN_DRS_SHIFT (30U)
#define XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_WBD_EN_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_WBD_EN_DRS_SHIFT)) & XCVR_RX_DIG_AGC_TIMING0_DRS_AGC_WBD_EN_DRS_MASK)
/*! @} */

/*! @name AGC_TIMING1_DRS - AGC Timing Control 1 DRS */
/*! @{ */

#define XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_FREEZE_TIMEOUT_MASK (0x7FU)
#define XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_FREEZE_TIMEOUT_SHIFT (0U)
/*! AGC_FREEZE_TIMEOUT - AGC FREEZE Mode Wait Time */
#define XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_FREEZE_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_FREEZE_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_FREEZE_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_HOLD_TIMEOUT_MASK (0x3F80U)
#define XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_HOLD_TIMEOUT_SHIFT (7U)
/*! AGC_HOLD_TIMEOUT - AGC HOLD Mode Wait Time */
#define XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_HOLD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_HOLD_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING1_DRS_AGC_HOLD_TIMEOUT_MASK)
/*! @} */

/*! @name AGC_TIMING2_DRS - AGC Timing Control 2 DRS */
/*! @{ */

#define XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNFREEZE_FEAT_TIMEOUT_MASK (0x7FFU)
#define XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNFREEZE_FEAT_TIMEOUT_SHIFT (0U)
/*! AGC_UNFREEZE_FEAT_TIMEOUT - AGC Unfreeze Feature Timeout */
#define XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNFREEZE_FEAT_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNFREEZE_FEAT_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNFREEZE_FEAT_TIMEOUT_MASK)

#define XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNHOLD_FEAT_TIMEOUT_MASK (0x1FF800U)
#define XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNHOLD_FEAT_TIMEOUT_SHIFT (11U)
/*! AGC_UNHOLD_FEAT_TIMEOUT - AGC Unhold Feature Timeout */
#define XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNHOLD_FEAT_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNHOLD_FEAT_TIMEOUT_SHIFT)) & XCVR_RX_DIG_AGC_TIMING2_DRS_AGC_UNHOLD_FEAT_TIMEOUT_MASK)
/*! @} */

/*! @name AGC_IDX11_GAIN_CFG - AGC IDX11 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_CBPF_GAIN_11_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_CBPF_GAIN_11_SHIFT (0U)
/*! CBPF_GAIN_11 - CBPF_GAIN_11
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_CBPF_GAIN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_CBPF_GAIN_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_CBPF_GAIN_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_RTRIM_11_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_RTRIM_11_SHIFT (1U)
/*! LNA_RTRIM_11 - LNA_RTRIM_11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_RTRIM_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_RTRIM_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_RTRIM_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_ATTN_11_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_ATTN_11_SHIFT (4U)
/*! LNA_ATTN_11 - LNA_ATTN_11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_ATTN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_ATTN_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_ATTN_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HATTN_11_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HATTN_11_SHIFT (6U)
/*! LNA_HATTN_11 - LNA_HATTN_11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HATTN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HATTN_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HATTN_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_LGAIN_11_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_LGAIN_11_SHIFT (7U)
/*! LNA_LGAIN_11 - LNA_LGAIN_11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_LGAIN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_LGAIN_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_LGAIN_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HGAIN_11_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HGAIN_11_SHIFT (9U)
/*! LNA_HGAIN_11 - LNA_HGAIN_11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HGAIN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HGAIN_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_LNA_HGAIN_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_ANT_EN_RLOAD_11_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_ANT_EN_RLOAD_11_SHIFT (15U)
/*! ANT_EN_RLOAD_11 - ANT_EN_RLOAD_11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_ANT_EN_RLOAD_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_ANT_EN_RLOAD_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_ANT_EN_RLOAD_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_HI_11_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_HI_11_DRS_OFS_SHIFT (16U)
/*! MAG_THR_HI_11_DRS_OFS - Mag Thresh DRS for AGC Gain Index 11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_HI_11_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_HI_11_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_HI_11_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_11_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_11_DRS_OFS_SHIFT (24U)
/*! MAG_THR_11_DRS_OFS - Mag Thresh High DRS for AGC Gain Index 11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_11_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_11_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_CFG_MAG_THR_11_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX10_GAIN_CFG - AGC IDX10 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_CBPF_GAIN_10_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_CBPF_GAIN_10_SHIFT (0U)
/*! CBPF_GAIN_10 - CBPF_GAIN_10
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_CBPF_GAIN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_CBPF_GAIN_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_CBPF_GAIN_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_RTRIM_10_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_RTRIM_10_SHIFT (1U)
/*! LNA_RTRIM_10 - LNA_RTRIM_10 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_RTRIM_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_RTRIM_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_RTRIM_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_ATTN_10_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_ATTN_10_SHIFT (4U)
/*! LNA_ATTN_10 - LNA_ATTN_10 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_ATTN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_ATTN_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_ATTN_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HATTN_10_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HATTN_10_SHIFT (6U)
/*! LNA_HATTN_10 - LNA_HATTN_10 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HATTN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HATTN_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HATTN_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_LGAIN_10_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_LGAIN_10_SHIFT (7U)
/*! LNA_LGAIN_10 - LNA_LGAIN_10 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_LGAIN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_LGAIN_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_LGAIN_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HGAIN_10_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HGAIN_10_SHIFT (9U)
/*! LNA_HGAIN_10 - LNA_HGAIN_10 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HGAIN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HGAIN_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_LNA_HGAIN_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_ANT_EN_RLOAD_10_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_ANT_EN_RLOAD_10_SHIFT (15U)
/*! ANT_EN_RLOAD_10 - ANT_EN_RLOAD_10 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_ANT_EN_RLOAD_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_ANT_EN_RLOAD_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_ANT_EN_RLOAD_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_HI_10_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_HI_10_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_HI_10_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_HI_10_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_HI_10_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_10_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_10_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_10_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_10_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_CFG_MAG_THR_10_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX9_GAIN_CFG - AGC IDX9 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_CBPF_GAIN_9_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_CBPF_GAIN_9_SHIFT (0U)
/*! CBPF_GAIN_9 - CBPF_GAIN_9
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_CBPF_GAIN_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_CBPF_GAIN_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_CBPF_GAIN_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_RTRIM_9_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_RTRIM_9_SHIFT (1U)
/*! LNA_RTRIM_9 - LNA_RTRIM_9 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_RTRIM_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_RTRIM_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_RTRIM_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_ATTN_9_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_ATTN_9_SHIFT (4U)
/*! LNA_ATTN_9 - LNA_ATTN_9 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_ATTN_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_ATTN_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_ATTN_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HATTN_9_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HATTN_9_SHIFT (6U)
/*! LNA_HATTN_9 - LNA_HATTN_9 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HATTN_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HATTN_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HATTN_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_LGAIN_9_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_LGAIN_9_SHIFT (7U)
/*! LNA_LGAIN_9 - LNA_LGAIN_9 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_LGAIN_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_LGAIN_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_LGAIN_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HGAIN_9_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HGAIN_9_SHIFT (9U)
/*! LNA_HGAIN_9 - LNA_HGAIN_9 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HGAIN_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HGAIN_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_LNA_HGAIN_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_ANT_EN_RLOAD_9_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_ANT_EN_RLOAD_9_SHIFT (15U)
/*! ANT_EN_RLOAD_9 - ANT_EN_RLOAD_9 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_ANT_EN_RLOAD_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_ANT_EN_RLOAD_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_ANT_EN_RLOAD_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_HI_9_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_HI_9_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_HI_9_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_HI_9_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_HI_9_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_9_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_9_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_9_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_9_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_CFG_MAG_THR_9_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX8_GAIN_CFG - AGC IDX8 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_CBPF_GAIN_8_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_CBPF_GAIN_8_SHIFT (0U)
/*! CBPF_GAIN_8 - CBPF_GAIN_8
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_CBPF_GAIN_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_CBPF_GAIN_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_CBPF_GAIN_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_RTRIM_8_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_RTRIM_8_SHIFT (1U)
/*! LNA_RTRIM_8 - LNA_RTRIM_8 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_RTRIM_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_RTRIM_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_RTRIM_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_ATTN_8_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_ATTN_8_SHIFT (4U)
/*! LNA_ATTN_8 - LNA_ATTN_8 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_ATTN_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_ATTN_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_ATTN_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HATTN_8_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HATTN_8_SHIFT (6U)
/*! LNA_HATTN_8 - LNA_HATTN_8 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HATTN_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HATTN_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HATTN_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_LGAIN_8_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_LGAIN_8_SHIFT (7U)
/*! LNA_LGAIN_8 - LNA_LGAIN_8 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_LGAIN_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_LGAIN_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_LGAIN_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HGAIN_8_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HGAIN_8_SHIFT (9U)
/*! LNA_HGAIN_8 - LNA_HGAIN_8 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HGAIN_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HGAIN_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_LNA_HGAIN_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_ANT_EN_RLOAD_8_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_ANT_EN_RLOAD_8_SHIFT (15U)
/*! ANT_EN_RLOAD_8 - ANT_EN_RLOAD_8 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_ANT_EN_RLOAD_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_ANT_EN_RLOAD_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_ANT_EN_RLOAD_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_HI_8_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_HI_8_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_HI_8_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_HI_8_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_HI_8_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_8_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_8_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_8_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_8_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_CFG_MAG_THR_8_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX7_GAIN_CFG - AGC IDX7 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_CBPF_GAIN_7_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_CBPF_GAIN_7_SHIFT (0U)
/*! CBPF_GAIN_7 - CBPF_GAIN_7
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_CBPF_GAIN_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_CBPF_GAIN_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_CBPF_GAIN_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_RTRIM_7_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_RTRIM_7_SHIFT (1U)
/*! LNA_RTRIM_7 - LNA_RTRIM_7 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_RTRIM_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_RTRIM_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_RTRIM_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_ATTN_7_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_ATTN_7_SHIFT (4U)
/*! LNA_ATTN_7 - LNA_ATTN_7 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_ATTN_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_ATTN_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_ATTN_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HATTN_7_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HATTN_7_SHIFT (6U)
/*! LNA_HATTN_7 - LNA_HATTN_7 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HATTN_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HATTN_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HATTN_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_LGAIN_7_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_LGAIN_7_SHIFT (7U)
/*! LNA_LGAIN_7 - LNA_LGAIN_7 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_LGAIN_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_LGAIN_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_LGAIN_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HGAIN_7_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HGAIN_7_SHIFT (9U)
/*! LNA_HGAIN_7 - LNA_HGAIN_7 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HGAIN_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HGAIN_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_LNA_HGAIN_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_ANT_EN_RLOAD_7_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_ANT_EN_RLOAD_7_SHIFT (15U)
/*! ANT_EN_RLOAD_7 - ANT_EN_RLOAD_7 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_ANT_EN_RLOAD_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_ANT_EN_RLOAD_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_ANT_EN_RLOAD_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_HI_7_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_HI_7_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_HI_7_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_HI_7_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_HI_7_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_7_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_7_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_7_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_7_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_CFG_MAG_THR_7_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX6_GAIN_CFG - AGC IDX6 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_CBPF_GAIN_6_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_CBPF_GAIN_6_SHIFT (0U)
/*! CBPF_GAIN_6 - CBPF_GAIN_6
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_CBPF_GAIN_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_CBPF_GAIN_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_CBPF_GAIN_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_RTRIM_6_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_RTRIM_6_SHIFT (1U)
/*! LNA_RTRIM_6 - LNA_RTRIM_6 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_RTRIM_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_RTRIM_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_RTRIM_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_ATTN_6_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_ATTN_6_SHIFT (4U)
/*! LNA_ATTN_6 - LNA_ATTN_6 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_ATTN_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_ATTN_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_ATTN_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HATTN_6_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HATTN_6_SHIFT (6U)
/*! LNA_HATTN_6 - LNA_HATTN_6 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HATTN_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HATTN_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HATTN_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_LGAIN_6_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_LGAIN_6_SHIFT (7U)
/*! LNA_LGAIN_6 - LNA_LGAIN_6 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_LGAIN_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_LGAIN_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_LGAIN_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HGAIN_6_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HGAIN_6_SHIFT (9U)
/*! LNA_HGAIN_6 - LNA_HGAIN_6 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HGAIN_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HGAIN_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_LNA_HGAIN_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_ANT_EN_RLOAD_6_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_ANT_EN_RLOAD_6_SHIFT (15U)
/*! ANT_EN_RLOAD_6 - ANT_EN_RLOAD_6 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_ANT_EN_RLOAD_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_ANT_EN_RLOAD_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_ANT_EN_RLOAD_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_HI_6_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_HI_6_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_HI_6_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_HI_6_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_HI_6_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_6_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_6_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_6_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_6_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_CFG_MAG_THR_6_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX5_GAIN_CFG - AGC IDX5 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_CBPF_GAIN_5_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_CBPF_GAIN_5_SHIFT (0U)
/*! CBPF_GAIN_5 - CBPF_GAIN_5
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_CBPF_GAIN_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_CBPF_GAIN_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_CBPF_GAIN_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_RTRIM_5_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_RTRIM_5_SHIFT (1U)
/*! LNA_RTRIM_5 - LNA_RTRIM_5 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_RTRIM_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_RTRIM_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_RTRIM_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_ATTN_5_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_ATTN_5_SHIFT (4U)
/*! LNA_ATTN_5 - LNA_ATTN_5 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_ATTN_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_ATTN_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_ATTN_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HATTN_5_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HATTN_5_SHIFT (6U)
/*! LNA_HATTN_5 - LNA_HATTN_5 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HATTN_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HATTN_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HATTN_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_LGAIN_5_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_LGAIN_5_SHIFT (7U)
/*! LNA_LGAIN_5 - LNA_LGAIN_5 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_LGAIN_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_LGAIN_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_LGAIN_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HGAIN_5_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HGAIN_5_SHIFT (9U)
/*! LNA_HGAIN_5 - LNA_HGAIN_5 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HGAIN_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HGAIN_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_LNA_HGAIN_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_ANT_EN_RLOAD_5_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_ANT_EN_RLOAD_5_SHIFT (15U)
/*! ANT_EN_RLOAD_5 - ANT_EN_RLOAD_5 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_ANT_EN_RLOAD_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_ANT_EN_RLOAD_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_ANT_EN_RLOAD_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_HI_5_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_HI_5_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_HI_5_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_HI_5_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_HI_5_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_5_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_5_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_5_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_5_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_CFG_MAG_THR_5_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX4_GAIN_CFG - AGC IDX4 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_CBPF_GAIN_4_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_CBPF_GAIN_4_SHIFT (0U)
/*! CBPF_GAIN_4 - CBPF_GAIN_4
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_CBPF_GAIN_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_CBPF_GAIN_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_CBPF_GAIN_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_RTRIM_4_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_RTRIM_4_SHIFT (1U)
/*! LNA_RTRIM_4 - LNA_RTRIM_4 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_RTRIM_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_RTRIM_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_RTRIM_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_ATTN_4_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_ATTN_4_SHIFT (4U)
/*! LNA_ATTN_4 - LNA_ATTN_4 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_ATTN_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_ATTN_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_ATTN_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HATTN_4_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HATTN_4_SHIFT (6U)
/*! LNA_HATTN_4 - LNA_HATTN_4 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HATTN_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HATTN_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HATTN_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_LGAIN_4_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_LGAIN_4_SHIFT (7U)
/*! LNA_LGAIN_4 - LNA_LGAIN_4 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_LGAIN_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_LGAIN_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_LGAIN_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HGAIN_4_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HGAIN_4_SHIFT (9U)
/*! LNA_HGAIN_4 - LNA_HGAIN_4 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HGAIN_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HGAIN_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_LNA_HGAIN_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_ANT_EN_RLOAD_4_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_ANT_EN_RLOAD_4_SHIFT (15U)
/*! ANT_EN_RLOAD_4 - ANT_EN_RLOAD_4 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_ANT_EN_RLOAD_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_ANT_EN_RLOAD_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_ANT_EN_RLOAD_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_HI_4_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_HI_4_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_HI_4_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_HI_4_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_HI_4_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_4_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_4_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_4_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_4_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_CFG_MAG_THR_4_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX3_GAIN_CFG - AGC IDX3 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_CBPF_GAIN_3_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_CBPF_GAIN_3_SHIFT (0U)
/*! CBPF_GAIN_3 - CBPF_GAIN_3
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_CBPF_GAIN_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_CBPF_GAIN_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_CBPF_GAIN_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_RTRIM_3_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_RTRIM_3_SHIFT (1U)
/*! LNA_RTRIM_3 - LNA_RTRIM_3 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_RTRIM_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_RTRIM_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_RTRIM_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_ATTN_3_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_ATTN_3_SHIFT (4U)
/*! LNA_ATTN_3 - LNA_ATTN_3 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_ATTN_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_ATTN_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_ATTN_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HATTN_3_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HATTN_3_SHIFT (6U)
/*! LNA_HATTN_3 - LNA_HATTN_3 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HATTN_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HATTN_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HATTN_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_LGAIN_3_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_LGAIN_3_SHIFT (7U)
/*! LNA_LGAIN_3 - LNA_LGAIN_3 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_LGAIN_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_LGAIN_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_LGAIN_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HGAIN_3_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HGAIN_3_SHIFT (9U)
/*! LNA_HGAIN_3 - LNA_HGAIN_3 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HGAIN_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HGAIN_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_LNA_HGAIN_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_ANT_EN_RLOAD_3_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_ANT_EN_RLOAD_3_SHIFT (15U)
/*! ANT_EN_RLOAD_3 - ANT_EN_RLOAD_3 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_ANT_EN_RLOAD_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_ANT_EN_RLOAD_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_ANT_EN_RLOAD_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_HI_3_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_HI_3_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_HI_3_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_HI_3_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_HI_3_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_3_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_3_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_3_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_3_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_CFG_MAG_THR_3_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX2_GAIN_CFG - AGC IDX2 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_CBPF_GAIN_2_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_CBPF_GAIN_2_SHIFT (0U)
/*! CBPF_GAIN_2 - CBPF_GAIN_2
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_CBPF_GAIN_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_CBPF_GAIN_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_CBPF_GAIN_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_RTRIM_2_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_RTRIM_2_SHIFT (1U)
/*! LNA_RTRIM_2 - LNA_RTRIM_2 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_RTRIM_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_RTRIM_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_RTRIM_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_ATTN_2_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_ATTN_2_SHIFT (4U)
/*! LNA_ATTN_2 - LNA_ATTN_2 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_ATTN_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_ATTN_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_ATTN_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HATTN_2_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HATTN_2_SHIFT (6U)
/*! LNA_HATTN_2 - LNA_HATTN_2 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HATTN_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HATTN_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HATTN_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_LGAIN_2_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_LGAIN_2_SHIFT (7U)
/*! LNA_LGAIN_2 - LNA_LGAIN_2 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_LGAIN_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_LGAIN_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_LGAIN_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HGAIN_2_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HGAIN_2_SHIFT (9U)
/*! LNA_HGAIN_2 - LNA_HGAIN_2 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HGAIN_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HGAIN_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_LNA_HGAIN_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_ANT_EN_RLOAD_2_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_ANT_EN_RLOAD_2_SHIFT (15U)
/*! ANT_EN_RLOAD_2 - ANT_EN_RLOAD_2 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_ANT_EN_RLOAD_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_ANT_EN_RLOAD_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_ANT_EN_RLOAD_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_HI_2_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_HI_2_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_HI_2_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_HI_2_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_HI_2_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_2_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_2_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_2_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_2_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_CFG_MAG_THR_2_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX1_GAIN_CFG - AGC IDX1 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_CBPF_GAIN_1_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_CBPF_GAIN_1_SHIFT (0U)
/*! CBPF_GAIN_1 - CBPF_GAIN_1
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_CBPF_GAIN_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_CBPF_GAIN_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_CBPF_GAIN_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_RTRIM_1_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_RTRIM_1_SHIFT (1U)
/*! LNA_RTRIM_1 - LNA_RTRIM_1 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_RTRIM_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_RTRIM_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_RTRIM_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_ATTN_1_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_ATTN_1_SHIFT (4U)
/*! LNA_ATTN_1 - LNA_ATTN_1 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_ATTN_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_ATTN_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_ATTN_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HATTN_1_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HATTN_1_SHIFT (6U)
/*! LNA_HATTN_1 - LNA_HATTN_1 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HATTN_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HATTN_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HATTN_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_LGAIN_1_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_LGAIN_1_SHIFT (7U)
/*! LNA_LGAIN_1 - LNA_LGAIN_1 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_LGAIN_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_LGAIN_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_LGAIN_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HGAIN_1_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HGAIN_1_SHIFT (9U)
/*! LNA_HGAIN_1 - LNA_HGAIN_1 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HGAIN_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HGAIN_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_LNA_HGAIN_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_ANT_EN_RLOAD_1_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_ANT_EN_RLOAD_1_SHIFT (15U)
/*! ANT_EN_RLOAD_1 - ANT_EN_RLOAD_1 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_ANT_EN_RLOAD_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_ANT_EN_RLOAD_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_ANT_EN_RLOAD_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_HI_1_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_HI_1_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_HI_1_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_HI_1_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_HI_1_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_1_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_1_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_1_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_1_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_CFG_MAG_THR_1_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX0_GAIN_CFG - AGC IDX0 Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_CBPF_GAIN_0_MASK (0x1U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_CBPF_GAIN_0_SHIFT (0U)
/*! CBPF_GAIN_0 - CBPF_GAIN_0
 *  0b0..-6 dB
 *  0b1..0 dB
 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_CBPF_GAIN_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_CBPF_GAIN_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_CBPF_GAIN_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_RTRIM_0_MASK (0xEU)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_RTRIM_0_SHIFT (1U)
/*! LNA_RTRIM_0 - LNA_RTRIM_0 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_RTRIM_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_RTRIM_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_RTRIM_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_ATTN_0_MASK (0x30U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_ATTN_0_SHIFT (4U)
/*! LNA_ATTN_0 - LNA_ATTN_0 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_ATTN_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_ATTN_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_ATTN_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HATTN_0_MASK (0x40U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HATTN_0_SHIFT (6U)
/*! LNA_HATTN_0 - LNA_HATTN_0 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HATTN_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HATTN_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HATTN_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_LGAIN_0_MASK (0x180U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_LGAIN_0_SHIFT (7U)
/*! LNA_LGAIN_0 - LNA_LGAIN_0 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_LGAIN_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_LGAIN_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_LGAIN_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HGAIN_0_MASK (0x7E00U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HGAIN_0_SHIFT (9U)
/*! LNA_HGAIN_0 - LNA_HGAIN_0 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HGAIN_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HGAIN_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_LNA_HGAIN_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_ANT_EN_RLOAD_0_MASK (0x8000U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_ANT_EN_RLOAD_0_SHIFT (15U)
/*! ANT_EN_RLOAD_0 - ANT_EN_RLOAD_0 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_ANT_EN_RLOAD_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_ANT_EN_RLOAD_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_ANT_EN_RLOAD_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_HI_0_DRS_OFS_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_HI_0_DRS_OFS_SHIFT (16U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_HI_0_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_HI_0_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_HI_0_DRS_OFS_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_0_DRS_OFS_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_0_DRS_OFS_SHIFT (24U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_0_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_0_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_CFG_MAG_THR_0_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_MIS_GAIN_CFG - AGC Miscellaneous Gain Config */
/*! @{ */

#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_DCOC_CAL_MASK (0x7U)
#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_DCOC_CAL_SHIFT (0U)
#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_DCOC_CAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_DCOC_CAL_SHIFT)) & XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_DCOC_CAL_MASK)

#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_TX_MODE_MASK (0x38U)
#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_TX_MODE_SHIFT (3U)
#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_TX_MODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_TX_MODE_SHIFT)) & XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_RTRIM_IN_TX_MODE_MASK)

#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_HATTN_IN_TX_MODE_MASK (0x40U)
#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_HATTN_IN_TX_MODE_SHIFT (6U)
#define XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_HATTN_IN_TX_MODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_HATTN_IN_TX_MODE_SHIFT)) & XCVR_RX_DIG_AGC_MIS_GAIN_CFG_LNA_HATTN_IN_TX_MODE_MASK)
/*! @} */

/*! @name AGC_IDX11_GAIN_VAL - AGC IDX11 Gain Value */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_LOG_GAIN_11_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_LOG_GAIN_11_SHIFT (0U)
/*! LOG_GAIN_11 - LOG_GAIN_11 */
#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_LOG_GAIN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_LOG_GAIN_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_LOG_GAIN_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_HI_11_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_HI_11_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_HI_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_HI_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_HI_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_11_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_11_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_GAIN_VAL_MAG_THR_11_MASK)
/*! @} */

/*! @name AGC_IDX10_GAIN_VAL - AGC_IDX10_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_LOG_GAIN_10_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_LOG_GAIN_10_SHIFT (0U)
/*! LOG_GAIN_10 - LOG_GAIN_10 */
#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_LOG_GAIN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_LOG_GAIN_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_LOG_GAIN_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_HI_10_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_HI_10_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_HI_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_HI_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_HI_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_10_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_10_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_GAIN_VAL_MAG_THR_10_MASK)
/*! @} */

/*! @name AGC_IDX9_GAIN_VAL - AGC_IDX9_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_LOG_GAIN_9_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_LOG_GAIN_9_SHIFT (0U)
/*! LOG_GAIN_9 - LOG_GAIN_9 */
#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_LOG_GAIN_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_LOG_GAIN_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_LOG_GAIN_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_HI_9_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_HI_9_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_HI_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_HI_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_HI_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_9_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_9_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_GAIN_VAL_MAG_THR_9_MASK)
/*! @} */

/*! @name AGC_IDX8_GAIN_VAL - AGC_IDX8_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_LOG_GAIN_8_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_LOG_GAIN_8_SHIFT (0U)
/*! LOG_GAIN_8 - LOG_GAIN_8 */
#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_LOG_GAIN_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_LOG_GAIN_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_LOG_GAIN_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_HI_8_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_HI_8_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_HI_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_HI_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_HI_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_8_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_8_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_GAIN_VAL_MAG_THR_8_MASK)
/*! @} */

/*! @name AGC_IDX7_GAIN_VAL - AGC_IDX7_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_LOG_GAIN_7_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_LOG_GAIN_7_SHIFT (0U)
/*! LOG_GAIN_7 - LOG_GAIN_7 */
#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_LOG_GAIN_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_LOG_GAIN_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_LOG_GAIN_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_HI_7_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_HI_7_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_HI_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_HI_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_HI_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_7_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_7_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_GAIN_VAL_MAG_THR_7_MASK)
/*! @} */

/*! @name AGC_IDX6_GAIN_VAL - AGC_IDX6_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_LOG_GAIN_6_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_LOG_GAIN_6_SHIFT (0U)
/*! LOG_GAIN_6 - LOG_GAIN_6 */
#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_LOG_GAIN_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_LOG_GAIN_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_LOG_GAIN_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_HI_6_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_HI_6_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_HI_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_HI_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_HI_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_6_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_6_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_GAIN_VAL_MAG_THR_6_MASK)
/*! @} */

/*! @name AGC_IDX5_GAIN_VAL - AGC_IDX5_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_LOG_GAIN_5_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_LOG_GAIN_5_SHIFT (0U)
/*! LOG_GAIN_5 - LOG_GAIN_5 */
#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_LOG_GAIN_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_LOG_GAIN_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_LOG_GAIN_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_HI_5_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_HI_5_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_HI_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_HI_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_HI_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_5_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_5_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_GAIN_VAL_MAG_THR_5_MASK)
/*! @} */

/*! @name AGC_IDX4_GAIN_VAL - AGC_IDX4_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_LOG_GAIN_4_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_LOG_GAIN_4_SHIFT (0U)
/*! LOG_GAIN_4 - LOG_GAIN_4 */
#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_LOG_GAIN_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_LOG_GAIN_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_LOG_GAIN_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_HI_4_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_HI_4_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_HI_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_HI_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_HI_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_4_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_4_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_GAIN_VAL_MAG_THR_4_MASK)
/*! @} */

/*! @name AGC_IDX3_GAIN_VAL - AGC_IDX3_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_LOG_GAIN_3_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_LOG_GAIN_3_SHIFT (0U)
/*! LOG_GAIN_3 - LOG_GAIN_3 */
#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_LOG_GAIN_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_LOG_GAIN_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_LOG_GAIN_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_HI_3_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_HI_3_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_HI_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_HI_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_HI_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_3_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_3_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_GAIN_VAL_MAG_THR_3_MASK)
/*! @} */

/*! @name AGC_IDX2_GAIN_VAL - AGC_IDX2_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_LOG_GAIN_2_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_LOG_GAIN_2_SHIFT (0U)
/*! LOG_GAIN_2 - LOG_GAIN_2 */
#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_LOG_GAIN_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_LOG_GAIN_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_LOG_GAIN_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_HI_2_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_HI_2_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_HI_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_HI_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_HI_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_2_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_2_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_GAIN_VAL_MAG_THR_2_MASK)
/*! @} */

/*! @name AGC_IDX1_GAIN_VAL - AGC_IDX1_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_LOG_GAIN_1_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_LOG_GAIN_1_SHIFT (0U)
/*! LOG_GAIN_1 - LOG_GAIN_1 */
#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_LOG_GAIN_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_LOG_GAIN_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_LOG_GAIN_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_HI_1_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_HI_1_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_HI_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_HI_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_HI_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_1_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_1_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_GAIN_VAL_MAG_THR_1_MASK)
/*! @} */

/*! @name AGC_IDX0_GAIN_VAL - AGC_IDX0_GAIN_VAL */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_LOG_GAIN_0_MASK (0x3FFU)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_LOG_GAIN_0_SHIFT (0U)
/*! LOG_GAIN_0 - LOG_GAIN_0 */
#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_LOG_GAIN_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_LOG_GAIN_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_LOG_GAIN_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_HI_0_MASK (0x1FFC00U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_HI_0_SHIFT (10U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_HI_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_HI_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_HI_0_MASK)

#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_0_MASK (0xFFE00000U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_0_SHIFT (21U)
#define XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_GAIN_VAL_MAG_THR_0_MASK)
/*! @} */

/*! @name AGC_THR_FAST - AGC Fast Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_THR_FAST_STEP_UP_THR_FAST_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_THR_FAST_STEP_UP_THR_FAST_SHIFT (0U)
/*! STEP_UP_THR_FAST - Fast mode step up thresholds */
#define XCVR_RX_DIG_AGC_THR_FAST_STEP_UP_THR_FAST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_THR_FAST_STEP_UP_THR_FAST_SHIFT)) & XCVR_RX_DIG_AGC_THR_FAST_STEP_UP_THR_FAST_MASK)

#define XCVR_RX_DIG_AGC_THR_FAST_STEP_DOWN_THR_FAST_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_THR_FAST_STEP_DOWN_THR_FAST_SHIFT (16U)
/*! STEP_DOWN_THR_FAST - Fast mode step down thresholds */
#define XCVR_RX_DIG_AGC_THR_FAST_STEP_DOWN_THR_FAST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_THR_FAST_STEP_DOWN_THR_FAST_SHIFT)) & XCVR_RX_DIG_AGC_THR_FAST_STEP_DOWN_THR_FAST_MASK)
/*! @} */

/*! @name AGC_THR_FAST_DRS - AGC Fast Mode Threshold DRS */
/*! @{ */

#define XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_UP_THR_FAST_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_UP_THR_FAST_SHIFT (0U)
/*! STEP_UP_THR_FAST - Fast mode step up thresholds for datarate_config_sel = 1 */
#define XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_UP_THR_FAST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_UP_THR_FAST_SHIFT)) & XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_UP_THR_FAST_MASK)

#define XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_DOWN_THR_FAST_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_DOWN_THR_FAST_SHIFT (16U)
/*! STEP_DOWN_THR_FAST - Fast mode step down thresholds for datarate_config_sel = 1 */
#define XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_DOWN_THR_FAST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_DOWN_THR_FAST_SHIFT)) & XCVR_RX_DIG_AGC_THR_FAST_DRS_STEP_DOWN_THR_FAST_MASK)
/*! @} */

/*! @name AGC_IDX11_THR - AGC IDX11 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_SHIFT (16U)
/*! STEP_DOWN_THR_11 - STEP_DOWN_THR_11 */
#define XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_MASK)

#define XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_11_DRS_OFS - STEP_DOWN_THR_11 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX11_THR_STEP_DOWN_THR_11_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX10_THR - AGC IDX10 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_UP_THR_10_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_UP_THR_10_SHIFT (0U)
/*! STEP_UP_THR_10 - STEP_UP_THR_10 */
#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_UP_THR_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_THR_STEP_UP_THR_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_THR_STEP_UP_THR_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_SHIFT (16U)
/*! STEP_DOWN_THR_10 - STEP_DOWN_THR_10 */
#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_MASK)

#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_10_DRS_OFS - STEP_DOWN_THR_10 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX10_THR_STEP_DOWN_THR_10_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX9_THR - AGC IDX9 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_UP_THR_9_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_UP_THR_9_SHIFT (0U)
/*! STEP_UP_THR_9 - STEP_UP_THR_9 */
#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_UP_THR_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_THR_STEP_UP_THR_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_THR_STEP_UP_THR_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_SHIFT (16U)
/*! STEP_DOWN_THR_9 - STEP_DOWN_THR_9 */
#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_MASK)

#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_9_DRS_OFS - STEP_DOWN_THR_9 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX9_THR_STEP_DOWN_THR_9_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX8_THR - AGC IDX8 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_UP_THR_8_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_UP_THR_8_SHIFT (0U)
/*! STEP_UP_THR_8 - STEP_UP_THR_8 */
#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_UP_THR_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_THR_STEP_UP_THR_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_THR_STEP_UP_THR_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_SHIFT (16U)
/*! STEP_DOWN_THR_8 - STEP_DOWN_THR_8 */
#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_MASK)

#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_8_DRS_OFS - STEP_DOWN_THR_8 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX8_THR_STEP_DOWN_THR_8_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX7_THR - AGC IDX7 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_UP_THR_7_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_UP_THR_7_SHIFT (0U)
/*! STEP_UP_THR_7 - STEP_UP_THR_7 */
#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_UP_THR_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_THR_STEP_UP_THR_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_THR_STEP_UP_THR_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_SHIFT (16U)
/*! STEP_DOWN_THR_7 - STEP_DOWN_THR_7 */
#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_MASK)

#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_7_DRS_OFS - STEP_DOWN_THR_7 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX7_THR_STEP_DOWN_THR_7_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX6_THR - AGC IDX6 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_UP_THR_6_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_UP_THR_6_SHIFT (0U)
/*! STEP_UP_THR_6 - STEP_UP_THR_6 */
#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_UP_THR_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_THR_STEP_UP_THR_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_THR_STEP_UP_THR_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_SHIFT (16U)
/*! STEP_DOWN_THR_6 - STEP_DOWN_THR_6 */
#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_MASK)

#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_6_DRS_OFS - STEP_DOWN_THR_6 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX6_THR_STEP_DOWN_THR_6_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX5_THR - AGC IDX5 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_UP_THR_5_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_UP_THR_5_SHIFT (0U)
/*! STEP_UP_THR_5 - STEP_UP_THR_5 */
#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_UP_THR_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_THR_STEP_UP_THR_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_THR_STEP_UP_THR_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_SHIFT (16U)
/*! STEP_DOWN_THR_5 - STEP_DOWN_THR_5 */
#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_MASK)

#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_5_DRS_OFS - STEP_DOWN_THR_5 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX5_THR_STEP_DOWN_THR_5_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX4_THR - AGC IDX4 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_UP_THR_4_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_UP_THR_4_SHIFT (0U)
/*! STEP_UP_THR_4 - STEP_UP_THR_4 */
#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_UP_THR_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_THR_STEP_UP_THR_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_THR_STEP_UP_THR_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_SHIFT (16U)
/*! STEP_DOWN_THR_4 - STEP_DOWN_THR_4 */
#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_MASK)

#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_4_DRS_OFS - STEP_DOWN_THR_4 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX4_THR_STEP_DOWN_THR_4_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX3_THR - AGC IDX3 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_UP_THR_3_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_UP_THR_3_SHIFT (0U)
/*! STEP_UP_THR_3 - STEP_UP_THR_3 */
#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_UP_THR_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_THR_STEP_UP_THR_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_THR_STEP_UP_THR_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_SHIFT (16U)
/*! STEP_DOWN_THR_3 - STEP_DOWN_THR_3 */
#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_MASK)

#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_3_DRS_OFS - STEP_DOWN_THR_3 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX3_THR_STEP_DOWN_THR_3_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX2_THR - AGC IDX2 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_UP_THR_2_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_UP_THR_2_SHIFT (0U)
/*! STEP_UP_THR_2 - STEP_UP_THR_2 */
#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_UP_THR_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_THR_STEP_UP_THR_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_THR_STEP_UP_THR_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_SHIFT (16U)
/*! STEP_DOWN_THR_2 - STEP_DOWN_THR_2 */
#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_MASK)

#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_2_DRS_OFS - STEP_DOWN_THR_2 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX2_THR_STEP_DOWN_THR_2_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX1_THR - AGC IDX1 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_UP_THR_1_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_UP_THR_1_SHIFT (0U)
/*! STEP_UP_THR_1 - STEP_UP_THR_1 */
#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_UP_THR_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_THR_STEP_UP_THR_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_THR_STEP_UP_THR_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_SHIFT (16U)
/*! STEP_DOWN_THR_1 - STEP_DOWN_THR_1 */
#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_MASK)

#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_DRS_OFS_MASK (0xFE000000U)
#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_DRS_OFS_SHIFT (25U)
/*! STEP_DOWN_THR_1_DRS_OFS - STEP_DOWN_THR_1 DRS Offset */
#define XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_DRS_OFS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_DRS_OFS_SHIFT)) & XCVR_RX_DIG_AGC_IDX1_THR_STEP_DOWN_THR_1_DRS_OFS_MASK)
/*! @} */

/*! @name AGC_IDX0_THR - AGC IDX0 Slow Mode Threshold */
/*! @{ */

#define XCVR_RX_DIG_AGC_IDX0_THR_STEP_UP_THR_0_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_IDX0_THR_STEP_UP_THR_0_SHIFT (0U)
/*! STEP_UP_THR_0 - STEP_UP_THR_0 */
#define XCVR_RX_DIG_AGC_IDX0_THR_STEP_UP_THR_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_IDX0_THR_STEP_UP_THR_0_SHIFT)) & XCVR_RX_DIG_AGC_IDX0_THR_STEP_UP_THR_0_MASK)
/*! @} */

/*! @name AGC_THR_MIS - AGC Miscellaneous Thresholds */
/*! @{ */

#define XCVR_RX_DIG_AGC_THR_MIS_DELTA_SLOW_THR_MASK (0x1FFU)
#define XCVR_RX_DIG_AGC_THR_MIS_DELTA_SLOW_THR_SHIFT (0U)
/*! DELTA_SLOW_THR - STEP_UP_THR_VLG2 */
#define XCVR_RX_DIG_AGC_THR_MIS_DELTA_SLOW_THR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_THR_MIS_DELTA_SLOW_THR_SHIFT)) & XCVR_RX_DIG_AGC_THR_MIS_DELTA_SLOW_THR_MASK)

#define XCVR_RX_DIG_AGC_THR_MIS_HOLD_MARGIN_THR_MASK (0x1FF0000U)
#define XCVR_RX_DIG_AGC_THR_MIS_HOLD_MARGIN_THR_SHIFT (16U)
/*! HOLD_MARGIN_THR - STEP_UP_THR_VLG2large */
#define XCVR_RX_DIG_AGC_THR_MIS_HOLD_MARGIN_THR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_THR_MIS_HOLD_MARGIN_THR_SHIFT)) & XCVR_RX_DIG_AGC_THR_MIS_HOLD_MARGIN_THR_MASK)
/*! @} */

/*! @name AGC_OVRD - AGC Override Control */
/*! @{ */

#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_MASK  (0xFFFFU)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_SHIFT (0U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_MASK)

#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_EN_MASK (0x10000U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_EN_SHIFT (16U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_EN_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_OVRD_EN_MASK)

#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_MASK (0x1E0000U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_SHIFT (17U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_MASK)

#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_EN_MASK (0x200000U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_EN_SHIFT (21U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_EN_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_GAIN_IDX_OVRD_EN_MASK)

#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_MASK (0x400000U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_SHIFT (22U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_MASK)

#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_EN_MASK (0x800000U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_EN_SHIFT (23U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_EN_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_PHY_HOLD_OVRD_EN_MASK)

#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_MASK (0x1000000U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_SHIFT (24U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_MASK)

#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_EN_MASK (0x2000000U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_EN_SHIFT (25U)
#define XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_EN_SHIFT)) & XCVR_RX_DIG_AGC_OVRD_AGC_PHY_FREEZE_OVRD_EN_MASK)
/*! @} */

/*! @name DC_RESID_CTRL - DC Residual Control */
/*! @{ */

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_MASK (0x7FU)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_SHIFT (0U)
/*! DC_RESID_NWIN - DC Residual NWIN */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_MASK (0xF00U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_SHIFT (8U)
/*! DC_RESID_ITER_FREEZE - DC Residual Iteration Freeze */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_MASK (0x7000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_SHIFT (12U)
/*! DC_RESID_ALPHA - DC Residual Alpha
 *  0b000..Update factor is 1
 *  0b001..Update factor is 1/2
 *  0b010..Update factor is 1/4 + 1/8
 *  0b011..Update factor is 1/4
 *  0b100..Update factor is 1/8 + 16
 *  0b101..Update factor is 1/8
 *  0b110..Update factor is 1/16 + 1/32
 *  0b111..Update factor is 1/16
 */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GS_EN_MASK (0x8000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GS_EN_SHIFT (15U)
/*! DC_RESID_GS_EN - DC Residual Gearshift Enable
 *  0b0..Gearshifting disabled
 *  0b1..Gearshifting enabled
 */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GS_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GS_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GS_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_MASK (0x70000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_SHIFT (16U)
/*! DC_RESID_DLY - DC Residual Delay */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_SECOND_RUN_EN_MASK (0x80000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_SECOND_RUN_EN_SHIFT (19U)
/*! DC_RESID_SECOND_RUN_EN - DC Residual Second Run Enable
 *  0b0..Second Run disabled
 *  0b1..Second Run enabled
 */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_SECOND_RUN_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_SECOND_RUN_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_SECOND_RUN_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_MASK (0x100000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_SHIFT (20U)
/*! DC_RESID_EXT_DC_EN - DC Residual External DC Enable
 *  0b0..External DC disable. The DC Residual activates at a delay specified by DC_RESID_DLY after an AGC gain
 *       change pulse. The DC Residual is initialized with a DC offset of 0.
 *  0b1..External DC enable. The DC residual activates after the DCOC's tracking hold timer expires. The DC
 *       Residual is initialized with the DC estimate from the DCOC tracking estimator.
 */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_MASK (0x1F000000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_SHIFT (24U)
/*! DC_RESID_MIN_AGC_IDX - DC Residual Minimum AGC Table Index */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GEARSHIFT_MASK (0xE0000000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GEARSHIFT_SHIFT (29U)
/*! DC_RESID_GEARSHIFT - DC Residual Gearshift */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GEARSHIFT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GEARSHIFT_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_GEARSHIFT_MASK)
/*! @} */

/*! @name DC_RESID_CTRL2 - DC Residual Control2 */
/*! @{ */

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_NWIN2_MASK (0x1FFU)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_NWIN2_SHIFT (0U)
/*! DC_RESID_NWIN2 - DC Residual NWIN, for Second Run */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_NWIN2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_NWIN2_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_NWIN2_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_PHY_STOP_EN_MASK (0x200U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_PHY_STOP_EN_SHIFT (9U)
/*! DC_RESID_PHY_STOP_EN - DC Residual PHY Stop Enable */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_PHY_STOP_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_PHY_STOP_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_PHY_STOP_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_CC_EN_MASK (0x400U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_CC_EN_SHIFT (10U)
/*! DC_RESID_CC_EN - DC Residual Continuous Correction Enable */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_CC_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_CC_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_CC_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SR2_EN_MASK (0x800U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SR2_EN_SHIFT (11U)
/*! DC_RESID_SR2_EN - DC Residual Slew rate Enable, for Second Run */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SR2_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SR2_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SR2_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ALPHA2_MASK (0x7000U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ALPHA2_SHIFT (12U)
/*! DC_RESID_ALPHA2 - DC Residual Alpha, for Second Run
 *  0b000..Update factor is 1
 *  0b001..Update factor is 1/2
 *  0b010..Update factor is 1/4 + 1/8
 *  0b011..Update factor is 1/4
 *  0b100..Update factor is 1/8 + 16
 *  0b101..Update factor is 1/8
 *  0b110..Update factor is 1/16 + 1/32
 *  0b111..Update factor is 1/16
 */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ALPHA2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ALPHA2_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ALPHA2_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GS2_EN_MASK (0x8000U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GS2_EN_SHIFT (15U)
/*! DC_RESID_GS2_EN - DC Residual Gearshift Enable, for Second Run
 *  0b0..Gearshifting disabled for Second Run
 *  0b1..Gearshifting enabled for Second Run
 */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GS2_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GS2_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GS2_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ITER_FREEZE2_MASK (0x1F0000U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ITER_FREEZE2_SHIFT (16U)
/*! DC_RESID_ITER_FREEZE2 - DC Residual Iteration Freeze, for Second Run */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ITER_FREEZE2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ITER_FREEZE2_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_ITER_FREEZE2_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SLEWRATE2_MASK (0xE00000U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SLEWRATE2_SHIFT (21U)
/*! DC_RESID_SLEWRATE2 - DC Residual Slew rate, for Second Run */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SLEWRATE2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SLEWRATE2_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_SLEWRATE2_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_MIN_AGC_IDX2_MASK (0x1F000000U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_MIN_AGC_IDX2_SHIFT (24U)
/*! DC_RESID_MIN_AGC_IDX2 - DC Residual Minimum AGC Table Index, for Second Run */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_MIN_AGC_IDX2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_MIN_AGC_IDX2_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_MIN_AGC_IDX2_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GEARSHIFT2_MASK (0xE0000000U)
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GEARSHIFT2_SHIFT (29U)
/*! DC_RESID_GEARSHIFT2 - DC Residual Gearshift, for Second Run */
#define XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GEARSHIFT2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GEARSHIFT2_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL2_DC_RESID_GEARSHIFT2_MASK)
/*! @} */

/*! @name DC_RESID_CTRL_DRS - DC Residual Control DataRate1 */
/*! @{ */

#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN_MASK (0x7FU)
#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN_SHIFT (0U)
/*! DC_RESID_NWIN - DC Residual NWIN */
#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_DLY_MASK (0x70000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_DLY_SHIFT (16U)
/*! DC_RESID_DLY - DC Residual Delay */
#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_DLY_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_DLY_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN2_MASK (0x1FF00000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN2_SHIFT (20U)
/*! DC_RESID_NWIN2 - DC Residual NWIN, for Second Run */
#define XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN2_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DRS_DC_RESID_NWIN2_MASK)
/*! @} */

/*! @name DC_RESID_EST - DC Residual Estimate */
/*! @{ */

#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_MASK (0x1FFFU)
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_SHIFT (0U)
/*! DC_RESID_OFFSET_I - DC Residual Offset I */
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_SHIFT)) & XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_MASK)

#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_MASK (0x1FFF0000U)
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_SHIFT (16U)
/*! DC_RESID_OFFSET_Q - DC Residual Offset Q */
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_SHIFT)) & XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_MASK)
/*! @} */

/*! @name DFT_TONE_ANALYZER0 - DfT tone analyzer */
/*! @{ */

#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_Q_MASK (0x1FFU)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_Q_SHIFT (0U)
/*! IPR_DFT_ANA_START_OFFSET_Q - Q Initial Phase */
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_Q_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_Q_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_I_MASK (0x3FE00U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_I_SHIFT (9U)
/*! IPR_DFT_ANA_START_OFFSET_I - I Initial Phase */
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_I_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_START_OFFSET_I_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_Q_MASK (0x1C0000U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_Q_SHIFT (18U)
/*! IPR_DFT_ANA_ATTENUATION_Q - Tone Attenuation For Q Path */
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_Q_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_Q_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_I_MASK (0xE00000U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_I_SHIFT (21U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_I_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_ATTENUATION_I_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_EN_MASK (0x1000000U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_EN_SHIFT (24U)
/*! IPR_DFT_ANA_EN - Enable for DfT tone analyzer */
#define XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_EN_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER0_IPR_DFT_ANA_EN_MASK)
/*! @} */

/*! @name DFT_TONE_ANALYZER1 - DfT tone analyzer */
/*! @{ */

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_ACCU_OVF_MASK (0x1U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_ACCU_OVF_SHIFT (0U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_ACCU_OVF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_ACCU_OVF_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_ACCU_OVF_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_BITSHIFT_OVF_MASK (0x2U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_BITSHIFT_OVF_SHIFT (1U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_BITSHIFT_OVF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_BITSHIFT_OVF_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_BITSHIFT_OVF_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_BITSHIFT_MASK (0x3CU)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_BITSHIFT_SHIFT (2U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_BITSHIFT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_BITSHIFT_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_BITSHIFT_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_DONE_MASK (0x40U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_DONE_SHIFT (6U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_DONE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_DONE_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_RX_TONE_ANA_DONE_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_START_MASK (0x80U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_START_SHIFT (7U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_START(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_START_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_START_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_2_MASK (0x300U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_2_SHIFT (8U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_2_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_2_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_1_MASK (0xC00U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_1_SHIFT (10U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_1_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INPUT_SEL_1_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INCREMENT_MASK (0x7F000U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INCREMENT_SHIFT (12U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INCREMENT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INCREMENT_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_INCREMENT_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_CLK_DIV_MASK (0x380000U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_CLK_DIV_SHIFT (19U)
/*! IPR_DFT_ANA_CLK_DIV
 *  0b000..ref_clk
 *  0b001..ref_clk div 2
 *  0b010..ref_clk div 4
 *  0b011..ref_clk div 8
 *  0b100..ref_clk div 16
 */
#define XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_CLK_DIV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_CLK_DIV_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER1_IPR_DFT_ANA_CLK_DIV_MASK)
/*! @} */

/*! @name DFT_TONE_ANALYZER2 - DfT tone analyzer */
/*! @{ */

#define XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_Q_MASK (0xFFFFU)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_Q_SHIFT (0U)
/*! RX_TONE_ANA_OUT_Q - Accumulator Q path result. */
#define XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_Q_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_Q_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_I_MASK (0xFFFF0000U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_I_SHIFT (16U)
/*! RX_TONE_ANA_OUT_I - Accumulator I path result */
#define XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_I_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER2_RX_TONE_ANA_OUT_I_MASK)
/*! @} */

/*! @name DFT_TONE_ANALYZER3 - DfT tone analyzer */
/*! @{ */

#define XCVR_RX_DIG_DFT_TONE_ANALYZER3_IPR_DFT_ANA_ACCUMULATION_LENGTH_MASK (0x7FFFU)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER3_IPR_DFT_ANA_ACCUMULATION_LENGTH_SHIFT (0U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER3_IPR_DFT_ANA_ACCUMULATION_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER3_IPR_DFT_ANA_ACCUMULATION_LENGTH_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER3_IPR_DFT_ANA_ACCUMULATION_LENGTH_MASK)

#define XCVR_RX_DIG_DFT_TONE_ANALYZER3_RX_TONE_ANA_OUT_ABS_MASK (0x7FFF8000U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER3_RX_TONE_ANA_OUT_ABS_SHIFT (15U)
#define XCVR_RX_DIG_DFT_TONE_ANALYZER3_RX_TONE_ANA_OUT_ABS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DFT_TONE_ANALYZER3_RX_TONE_ANA_OUT_ABS_SHIFT)) & XCVR_RX_DIG_DFT_TONE_ANALYZER3_RX_TONE_ANA_OUT_ABS_MASK)
/*! @} */

/*! @name DCOC_DIG_CORR_RESULT - DCOC Digital Correction Result */
/*! @{ */

#define XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_Q_MASK (0xFFU)
#define XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_Q_SHIFT (0U)
/*! DCOC_DIG_CORR_Q - DCOC I-Channel Residual After Calibration */
#define XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_Q_SHIFT)) & XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_Q_MASK)

#define XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_I_MASK (0xFF00U)
#define XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_I_SHIFT (8U)
/*! DCOC_DIG_CORR_I - DCOC Q-Channel Residual After Calibration */
#define XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_I_SHIFT)) & XCVR_RX_DIG_DCOC_DIG_CORR_RESULT_DCOC_DIG_CORR_I_MASK)
/*! @} */

/*! @name IQMC_CTRL1_DRS - IQ Mismatch Control 1 DRS */
/*! @{ */

#define XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_GAIN_ADJ_MASK (0x7FFU)
#define XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_GAIN_ADJ_SHIFT (0U)
/*! IQMC_GAIN_ADJ - IQ Mismatch Correction Gain Coeff DRS */
#define XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_GAIN_ADJ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_GAIN_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_GAIN_ADJ_MASK)

#define XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_PHASE_ADJ_MASK (0xFFF0000U)
#define XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_PHASE_ADJ_SHIFT (16U)
/*! IQMC_PHASE_ADJ - IQ Mismatch Phase Correction DRS */
#define XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_PHASE_ADJ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_PHASE_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL1_DRS_IQMC_PHASE_ADJ_MASK)
/*! @} */

/*! @name TQI_CTRL - TQI control fields */
/*! @{ */

#define XCVR_RX_DIG_TQI_CTRL_IQ_AVG_DPTH_MASK    (0xFU)
#define XCVR_RX_DIG_TQI_CTRL_IQ_AVG_DPTH_SHIFT   (0U)
/*! IQ_AVG_DPTH - Number of IQ samples per IQ averaging window, in power of two.
 *  0b0000..IQ averager is bypassed
 *  0b0001..IQ averager uses 2 samples
 *  0b0010..IQ averager uses 4 samples
 *  0b0011..IQ averager uses 8 samples
 *  0b0100..IQ averager uses 16 samples
 */
#define XCVR_RX_DIG_TQI_CTRL_IQ_AVG_DPTH(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_TQI_CTRL_IQ_AVG_DPTH_SHIFT)) & XCVR_RX_DIG_TQI_CTRL_IQ_AVG_DPTH_MASK)

#define XCVR_RX_DIG_TQI_CTRL_MAG_AVG_DPTH_MASK   (0xF00U)
#define XCVR_RX_DIG_TQI_CTRL_MAG_AVG_DPTH_SHIFT  (8U)
/*! MAG_AVG_DPTH - Number of magnitude averaging windows, in power of two.
 *  0b0000..Magnitude averager is bypassed
 *  0b0001..Magnitude averager uses 2 windows
 *  0b0010..Magnitude averager uses 4 windows
 *  0b0011..Magnitude averager uses 8 windows
 *  0b0100..Magnitude averager uses 16 windows
 *  0b0101..Magnitude averager uses 32 windows
 */
#define XCVR_RX_DIG_TQI_CTRL_MAG_AVG_DPTH(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_TQI_CTRL_MAG_AVG_DPTH_SHIFT)) & XCVR_RX_DIG_TQI_CTRL_MAG_AVG_DPTH_MASK)

#define XCVR_RX_DIG_TQI_CTRL_TQI_EN_MASK         (0x10000U)
#define XCVR_RX_DIG_TQI_CTRL_TQI_EN_SHIFT        (16U)
/*! TQI_EN - Enables TQI operation.
 *  0b0..TQI operation is disabled.
 *  0b1..TQI operation is enabled.
 */
#define XCVR_RX_DIG_TQI_CTRL_TQI_EN(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_TQI_CTRL_TQI_EN_SHIFT)) & XCVR_RX_DIG_TQI_CTRL_TQI_EN_MASK)
/*! @} */

/*! @name TQI_THR - TQI thresholds */
/*! @{ */

#define XCVR_RX_DIG_TQI_THR_T1_MASK              (0x1FFU)
#define XCVR_RX_DIG_TQI_THR_T1_SHIFT             (0U)
/*! T1 - T1 threshold. */
#define XCVR_RX_DIG_TQI_THR_T1(x)                (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_TQI_THR_T1_SHIFT)) & XCVR_RX_DIG_TQI_THR_T1_MASK)

#define XCVR_RX_DIG_TQI_THR_T2_MASK              (0x1FF0000U)
#define XCVR_RX_DIG_TQI_THR_T2_SHIFT             (16U)
/*! T2 - T2 threshold */
#define XCVR_RX_DIG_TQI_THR_T2(x)                (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_TQI_THR_T2_SHIFT)) & XCVR_RX_DIG_TQI_THR_T2_MASK)

#define XCVR_RX_DIG_TQI_THR_INLINE_THR_TQI_MASK  (0xC0000000U)
#define XCVR_RX_DIG_TQI_THR_INLINE_THR_TQI_SHIFT (30U)
/*! INLINE_THR_TQI - INLINE_THR_TQI threshold */
#define XCVR_RX_DIG_TQI_THR_INLINE_THR_TQI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_TQI_THR_INLINE_THR_TQI_SHIFT)) & XCVR_RX_DIG_TQI_THR_INLINE_THR_TQI_MASK)
/*! @} */

/*! @name CTRL2 - RXDIG Control 2 */
/*! @{ */

#define XCVR_RX_DIG_CTRL2_SN_AGC_INIT_IDX2_MASK  (0xFU)
#define XCVR_RX_DIG_CTRL2_SN_AGC_INIT_IDX2_SHIFT (0U)
/*! SN_AGC_INIT_IDX2 - AGC Initial Gain Index of the second part of CS sub-event in sniffer mode */
#define XCVR_RX_DIG_CTRL2_SN_AGC_INIT_IDX2(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL2_SN_AGC_INIT_IDX2_SHIFT)) & XCVR_RX_DIG_CTRL2_SN_AGC_INIT_IDX2_MASK)

#define XCVR_RX_DIG_CTRL2_RX_SAMPLE_ADJ_MASK     (0x700U)
#define XCVR_RX_DIG_CTRL2_RX_SAMPLE_ADJ_SHIFT    (8U)
/*! RX_SAMPLE_ADJ - RX sample delay line adjustment */
#define XCVR_RX_DIG_CTRL2_RX_SAMPLE_ADJ(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL2_RX_SAMPLE_ADJ_SHIFT)) & XCVR_RX_DIG_CTRL2_RX_SAMPLE_ADJ_MASK)

#define XCVR_RX_DIG_CTRL2_AM_ATT_EN_MASK         (0x10000U)
#define XCVR_RX_DIG_CTRL2_AM_ATT_EN_SHIFT        (16U)
/*! AM_ATT_EN - AM attack detection enable */
#define XCVR_RX_DIG_CTRL2_AM_ATT_EN(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL2_AM_ATT_EN_SHIFT)) & XCVR_RX_DIG_CTRL2_AM_ATT_EN_MASK)

#define XCVR_RX_DIG_CTRL2_AM_ATT_DELAY_MASK      (0x1E0000U)
#define XCVR_RX_DIG_CTRL2_AM_ATT_DELAY_SHIFT     (17U)
/*! AM_ATT_DELAY - AM attack delay */
#define XCVR_RX_DIG_CTRL2_AM_ATT_DELAY(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL2_AM_ATT_DELAY_SHIFT)) & XCVR_RX_DIG_CTRL2_AM_ATT_DELAY_MASK)

#define XCVR_RX_DIG_CTRL2_AM_ATT_OFFSET_MASK     (0x1E00000U)
#define XCVR_RX_DIG_CTRL2_AM_ATT_OFFSET_SHIFT    (21U)
/*! AM_ATT_OFFSET - RX sample delay line adjustment */
#define XCVR_RX_DIG_CTRL2_AM_ATT_OFFSET(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL2_AM_ATT_OFFSET_SHIFT)) & XCVR_RX_DIG_CTRL2_AM_ATT_OFFSET_MASK)

#define XCVR_RX_DIG_CTRL2_AM_ATT_SEL_MASK        (0x2000000U)
#define XCVR_RX_DIG_CTRL2_AM_ATT_SEL_SHIFT       (25U)
/*! AM_ATT_SEL - RX sample delay line adjustment */
#define XCVR_RX_DIG_CTRL2_AM_ATT_SEL(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CTRL2_AM_ATT_SEL_SHIFT)) & XCVR_RX_DIG_CTRL2_AM_ATT_SEL_MASK)
/*! @} */

/*! @name NADM_CTRL - Controls for the NADM module */
/*! @{ */

#define XCVR_RX_DIG_NADM_CTRL_NADM_EN_MASK       (0x1U)
#define XCVR_RX_DIG_NADM_CTRL_NADM_EN_SHIFT      (0U)
/*! NADM_EN - NADM module enable.
 *  0b0..Nadm operation is disabled.
 *  0b1..Nadm operation is enabled.
 */
#define XCVR_RX_DIG_NADM_CTRL_NADM_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_EN_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_EN_MASK)

#define XCVR_RX_DIG_NADM_CTRL_NADM_SRC_MASK      (0x2U)
#define XCVR_RX_DIG_NADM_CTRL_NADM_SRC_SHIFT     (1U)
/*! NADM_SRC - FM correlator path, select source.
 *  0b0..CHF in selected
 *  0b1..CHF out selected
 */
#define XCVR_RX_DIG_NADM_CTRL_NADM_SRC(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_SRC_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_SRC_MASK)

#define XCVR_RX_DIG_NADM_CTRL_NADM_DLY_MASK      (0x7CU)
#define XCVR_RX_DIG_NADM_CTRL_NADM_DLY_SHIFT     (2U)
/*! NADM_DLY - FM correlator path, NADM trigger delay after access address reception. */
#define XCVR_RX_DIG_NADM_CTRL_NADM_DLY(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_DLY_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_DLY_MASK)

#define XCVR_RX_DIG_NADM_CTRL_NADM_OFFSET_MASK   (0xF80U)
#define XCVR_RX_DIG_NADM_CTRL_NADM_OFFSET_SHIFT  (7U)
/*! NADM_OFFSET - FM correlator path, offset in the delay array. */
#define XCVR_RX_DIG_NADM_CTRL_NADM_OFFSET(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_OFFSET_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_OFFSET_MASK)

#define XCVR_RX_DIG_NADM_CTRL_NADM_DMD_LATENCY_MASK (0x1F000U)
#define XCVR_RX_DIG_NADM_CTRL_NADM_DMD_LATENCY_SHIFT (12U)
/*! NADM_DMD_LATENCY - FM symbol error path, NADM trigger delay after access address reception. */
#define XCVR_RX_DIG_NADM_CTRL_NADM_DMD_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_DMD_LATENCY_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_DMD_LATENCY_MASK)

#define XCVR_RX_DIG_NADM_CTRL_NADM_FIR_LATENCY_MASK (0x3E0000U)
#define XCVR_RX_DIG_NADM_CTRL_NADM_FIR_LATENCY_SHIFT (17U)
/*! NADM_FIR_LATENCY - FM correlator path, delay between reference start and correlator start. */
#define XCVR_RX_DIG_NADM_CTRL_NADM_FIR_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_FIR_LATENCY_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_FIR_LATENCY_MASK)

#define XCVR_RX_DIG_NADM_CTRL_NADM_SIZE_MASK     (0x1C00000U)
#define XCVR_RX_DIG_NADM_CTRL_NADM_SIZE_SHIFT    (22U)
/*! NADM_SIZE - NADM size aligned on RTT_TYPE standard value */
#define XCVR_RX_DIG_NADM_CTRL_NADM_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_SIZE_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_SIZE_MASK)

#define XCVR_RX_DIG_NADM_CTRL_NADM_IDX_CAPTURE_MASK (0xE000000U)
#define XCVR_RX_DIG_NADM_CTRL_NADM_IDX_CAPTURE_SHIFT (25U)
/*! NADM_IDX_CAPTURE - Index used to get optimum fm_diff in DMA_DBG */
#define XCVR_RX_DIG_NADM_CTRL_NADM_IDX_CAPTURE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_CTRL_NADM_IDX_CAPTURE_SHIFT)) & XCVR_RX_DIG_NADM_CTRL_NADM_IDX_CAPTURE_MASK)
/*! @} */

/*! @name NADM_RES - NADM latest packet results. */
/*! @{ */

#define XCVR_RX_DIG_NADM_RES_NADM_MAX_CORR_MASK  (0x1FFU)
#define XCVR_RX_DIG_NADM_RES_NADM_MAX_CORR_SHIFT (0U)
/*! NADM_MAX_CORR - NADM maximum correlation value. */
#define XCVR_RX_DIG_NADM_RES_NADM_MAX_CORR(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_RES_NADM_MAX_CORR_SHIFT)) & XCVR_RX_DIG_NADM_RES_NADM_MAX_CORR_MASK)

#define XCVR_RX_DIG_NADM_RES_NADM_INST_MASK      (0x7000U)
#define XCVR_RX_DIG_NADM_RES_NADM_INST_SHIFT     (12U)
/*! NADM_INST - NADM correlator instance yielding maximum correlation value. */
#define XCVR_RX_DIG_NADM_RES_NADM_INST(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_NADM_RES_NADM_INST_SHIFT)) & XCVR_RX_DIG_NADM_RES_NADM_INST_MASK)
/*! @} */

/*! @name FCFO_CTRL - Fine CFO module controls. */
/*! @{ */

#define XCVR_RX_DIG_FCFO_CTRL_A_MUL_MASK         (0xFFU)
#define XCVR_RX_DIG_FCFO_CTRL_A_MUL_SHIFT        (0U)
/*! A_MUL - Alpha linear multiplication coeficient */
#define XCVR_RX_DIG_FCFO_CTRL_A_MUL(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_A_MUL_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_A_MUL_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_A_DIV_MASK         (0xF000U)
#define XCVR_RX_DIG_FCFO_CTRL_A_DIV_SHIFT        (12U)
/*! A_DIV - Alpha linear division coeficient */
#define XCVR_RX_DIG_FCFO_CTRL_A_DIV(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_A_DIV_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_A_DIV_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_FCFO_ENA_MASK      (0x10000U)
#define XCVR_RX_DIG_FCFO_CTRL_FCFO_ENA_SHIFT     (16U)
/*! FCFO_ENA - Enables FCFO module.
 *  0b0..Fcfo algorithm disabled.
 *  0b1..Fcfo algorithm enabled.
 */
#define XCVR_RX_DIG_FCFO_CTRL_FCFO_ENA(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_FCFO_ENA_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_FCFO_ENA_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_OUT_IQ_MASK        (0x40000U)
#define XCVR_RX_DIG_FCFO_CTRL_OUT_IQ_SHIFT       (18U)
/*! OUT_IQ - FCFO output format.
 *  0b0..Fcfo output are g function values (previous/current).
 *  0b1..Fcfo output are IQ values.
 */
#define XCVR_RX_DIG_FCFO_CTRL_OUT_IQ(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_OUT_IQ_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_OUT_IQ_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_TRIG_SRC_MASK      (0x300000U)
#define XCVR_RX_DIG_FCFO_CTRL_TRIG_SRC_SHIFT     (20U)
/*! TRIG_SRC - Selects FCFO trigger source.
 *  0b00..Selects TPM as trigger source
 *  0b01..Selects TFM as trigger source
 *  0b10..Selects software as trigger source.
 */
#define XCVR_RX_DIG_FCFO_CTRL_TRIG_SRC(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_TRIG_SRC_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_TRIG_SRC_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_TRIG_DLY_MASK      (0x3000000U)
#define XCVR_RX_DIG_FCFO_CTRL_TRIG_DLY_SHIFT     (24U)
/*! TRIG_DLY - Delay between trigger and fcfo start.
 *  0b00..Selects 2us trigger delay.
 *  0b01..Selects 5us trigger delay.
 *  0b10..Selects 10us trigger delay.
 *  0b11..Selects 15us trigger delay.
 */
#define XCVR_RX_DIG_FCFO_CTRL_TRIG_DLY(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_TRIG_DLY_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_TRIG_DLY_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_A_OVF_MASK         (0x10000000U)
#define XCVR_RX_DIG_FCFO_CTRL_A_OVF_SHIFT        (28U)
/*! A_OVF - Alpha multiplier overflow. */
#define XCVR_RX_DIG_FCFO_CTRL_A_OVF(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_A_OVF_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_A_OVF_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_FCFO_ERR_MASK      (0x20000000U)
#define XCVR_RX_DIG_FCFO_CTRL_FCFO_ERR_SHIFT     (29U)
/*! FCFO_ERR - FCFO value error. */
#define XCVR_RX_DIG_FCFO_CTRL_FCFO_ERR(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_FCFO_ERR_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_FCFO_ERR_MASK)

#define XCVR_RX_DIG_FCFO_CTRL_FCFO_DONE_MASK     (0x40000000U)
#define XCVR_RX_DIG_FCFO_CTRL_FCFO_DONE_SHIFT    (30U)
/*! FCFO_DONE - FCFO done. */
#define XCVR_RX_DIG_FCFO_CTRL_FCFO_DONE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_CTRL_FCFO_DONE_SHIFT)) & XCVR_RX_DIG_FCFO_CTRL_FCFO_DONE_MASK)
/*! @} */

/*! @name FCFO_TN - Tone parameters. */
/*! @{ */

#define XCVR_RX_DIG_FCFO_TN_TN_F1_INC_MASK       (0x7FU)
#define XCVR_RX_DIG_FCFO_TN_TN_F1_INC_SHIFT      (0U)
/*! TN_F1_INC - Tone F1 increment. */
#define XCVR_RX_DIG_FCFO_TN_TN_F1_INC(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_TN_TN_F1_INC_SHIFT)) & XCVR_RX_DIG_FCFO_TN_TN_F1_INC_MASK)

#define XCVR_RX_DIG_FCFO_TN_TN_F1_DIV_MASK       (0x700U)
#define XCVR_RX_DIG_FCFO_TN_TN_F1_DIV_SHIFT      (8U)
/*! TN_F1_DIV - Tone F1 clock divisor. */
#define XCVR_RX_DIG_FCFO_TN_TN_F1_DIV(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_TN_TN_F1_DIV_SHIFT)) & XCVR_RX_DIG_FCFO_TN_TN_F1_DIV_MASK)

#define XCVR_RX_DIG_FCFO_TN_TN_F2_INC_MASK       (0x7F0000U)
#define XCVR_RX_DIG_FCFO_TN_TN_F2_INC_SHIFT      (16U)
/*! TN_F2_INC - Tone F2 increment. */
#define XCVR_RX_DIG_FCFO_TN_TN_F2_INC(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_TN_TN_F2_INC_SHIFT)) & XCVR_RX_DIG_FCFO_TN_TN_F2_INC_MASK)

#define XCVR_RX_DIG_FCFO_TN_TN_F2_DIV_MASK       (0x7000000U)
#define XCVR_RX_DIG_FCFO_TN_TN_F2_DIV_SHIFT      (24U)
/*! TN_F2_DIV - Tone F2 clock divisor. */
#define XCVR_RX_DIG_FCFO_TN_TN_F2_DIV(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_TN_TN_F2_DIV_SHIFT)) & XCVR_RX_DIG_FCFO_TN_TN_F2_DIV_MASK)
/*! @} */

/*! @name FCFO_TN_PH - F2 carrier iq phases */
/*! @{ */

#define XCVR_RX_DIG_FCFO_TN_PH_F2_PH_I_MASK      (0x1FFU)
#define XCVR_RX_DIG_FCFO_TN_PH_F2_PH_I_SHIFT     (0U)
/*! F2_PH_I - F2 carrier I start phase */
#define XCVR_RX_DIG_FCFO_TN_PH_F2_PH_I(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_TN_PH_F2_PH_I_SHIFT)) & XCVR_RX_DIG_FCFO_TN_PH_F2_PH_I_MASK)

#define XCVR_RX_DIG_FCFO_TN_PH_F2_PH_Q_MASK      (0x1FF0000U)
#define XCVR_RX_DIG_FCFO_TN_PH_F2_PH_Q_SHIFT     (16U)
/*! F2_PH_Q - F2 carrier Q start phase */
#define XCVR_RX_DIG_FCFO_TN_PH_F2_PH_Q(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_TN_PH_F2_PH_Q_SHIFT)) & XCVR_RX_DIG_FCFO_TN_PH_F2_PH_Q_MASK)
/*! @} */

/*! @name FCFO_RES - Fine CFO results. */
/*! @{ */

#define XCVR_RX_DIG_FCFO_RES_G_CUR_MASK          (0xFFFFU)
#define XCVR_RX_DIG_FCFO_RES_G_CUR_SHIFT         (0U)
/*! G_CUR - g function, current value. */
#define XCVR_RX_DIG_FCFO_RES_G_CUR(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_RES_G_CUR_SHIFT)) & XCVR_RX_DIG_FCFO_RES_G_CUR_MASK)

#define XCVR_RX_DIG_FCFO_RES_G_PRV_MASK          (0xFFFF0000U)
#define XCVR_RX_DIG_FCFO_RES_G_PRV_SHIFT         (16U)
/*! G_PRV - g function, previous value. */
#define XCVR_RX_DIG_FCFO_RES_G_PRV(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_FCFO_RES_G_PRV_SHIFT)) & XCVR_RX_DIG_FCFO_RES_G_PRV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_RX_DIG_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_RX_DIG_Peripheral_Access_Layer */


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


#endif  /* PERI_XCVR_RX_DIG_H_ */

