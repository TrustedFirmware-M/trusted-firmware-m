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
**         CMSIS Peripheral Access Layer for XCVR_PLL_DIG
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
 * @file PERI_XCVR_PLL_DIG.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for XCVR_PLL_DIG
 *
 * CMSIS Peripheral Access Layer for XCVR_PLL_DIG
 */

#if !defined(PERI_XCVR_PLL_DIG_H_)
#define PERI_XCVR_PLL_DIG_H_                     /**< Symbol preventing repeated inclusion */

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
   -- XCVR_PLL_DIG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PLL_DIG_Peripheral_Access_Layer XCVR_PLL_DIG Peripheral Access Layer
 * @{
 */

/** XCVR_PLL_DIG - Register Layout Typedef */
typedef struct {
  __IO uint32_t HPM_BUMP;                          /**< PLL HPM Analog Bump Control, offset: 0x0 */
  __IO uint32_t MOD_CTRL;                          /**< PLL Modulation Control, offset: 0x4 */
  __IO uint32_t CHAN_MAP;                          /**< PLL Channel Mapping, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t CHAN_MAP_EXT;                      /**< PLL Channel Mapping Extended, offset: 0x10 */
       uint8_t RESERVED_1[4];
  __IO uint32_t LOCK_DETECT;                       /**< PLL Lock Detect Control, offset: 0x18 */
  __IO uint32_t HPM_CTRL;                          /**< PLL High Port Modulator Control, offset: 0x1C */
       uint8_t RESERVED_2[12];
  __IO uint32_t HPM_SDM_RES;                       /**< PLL High Port Sigma Delta Results, offset: 0x2C */
  __IO uint32_t LPM_CTRL;                          /**< PLL Low Port Modulator Control, offset: 0x30 */
  __IO uint32_t LPM_SDM_CTRL1;                     /**< PLL Low Port Sigma Delta Control 1, offset: 0x34 */
  __IO uint32_t LPM_SDM_CTRL2;                     /**< PLL Low Port Sigma Delta Control 2, offset: 0x38 */
  __IO uint32_t LPM_SDM_CTRL3;                     /**< PLL Low Port Sigma Delta Control 3, offset: 0x3C */
  __I  uint32_t LPM_SDM_RES1;                      /**< PLL Low Port Sigma Delta Result 1, offset: 0x40 */
  __I  uint32_t LPM_SDM_RES2;                      /**< PLL Low Port Sigma Delta Result 2, offset: 0x44 */
  __IO uint32_t DELAY_MATCH;                       /**< PLL Delay Matching, offset: 0x48 */
  __IO uint32_t TUNING_CAP_TX_CTRL;                /**< Tuning Cap Settings in Transmit Mode, offset: 0x4C */
  __IO uint32_t TUNING_CAP_RX_CTRL;                /**< Tuning Cap Settings in Receive Mode, offset: 0x50 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MAX_MIN_TX_CFG1_FREQ;              /**< Max and Min Transmit Frequencies For TX Configuration 1, offset: 0x58 */
  __IO uint32_t CTUNE_CTRL;                        /**< PLL Coarse Tune Control, offset: 0x5C */
  __IO uint32_t DATA_RATE_OVRD_CTRL1;              /**< PLL Data Rate Override Control, offset: 0x60 */
  __IO uint32_t DATA_RATE_OVRD_CTRL2;              /**< PLL Data Rate Override Control, offset: 0x64 */
       uint8_t RESERVED_4[28];
  __I  uint32_t CTUNE_RES;                         /**< PLL Coarse Tune Results, offset: 0x84 */
       uint8_t RESERVED_5[24];
  __IO uint32_t HPM_CAL_TIMING;                    /**< PLL HPM Calibration Timing Attributes, offset: 0xA0 */
  __IO uint32_t PLL_OFFSET_CTRL;                   /**< PLL Offset Control, offset: 0xA4 */
  __IO uint32_t PLL_DATARATE_CTRL;                 /**< PLL Data Rate Switch Control, offset: 0xA8 */
  __IO uint32_t PLL_PHASE_COMPENSATION;            /**< PLL phase compensation, offset: 0xAC */
} XCVR_PLL_DIG_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_PLL_DIG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PLL_DIG_Register_Masks XCVR_PLL_DIG Register Masks
 * @{
 */

/*! @name HPM_BUMP - PLL HPM Analog Bump Control */
/*! @{ */

#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_MASK    (0x7U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_SHIFT   (0U)
/*! HPM_VCM_TX - a_ip_2p4ghz_reg_dac_trim_vcm_dig[2:0] during Transmission
 *  0b000..0.120 (0.122)
 *  0b001..0.153 (0.189)
 *  0b010..0.182 (0.247)
 *  0b011..0.209 (0.300)
 *  0b100..0.234 (0.348)
 *  0b101..0.258 (0.393)
 *  0b110..0.279 (0.434)
 *  0b111..0.318 (0.509)
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_MASK   (0x70U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_SHIFT  (4U)
/*! HPM_VCM_CAL - a_ip_2p4ghz_reg_dac_trim_vcm_dig[2:0] during Calibration
 *  0b000..0.120 (0.122)
 *  0b001..0.153 (0.189)
 *  0b010..0.182 (0.247)
 *  0b011..0.209 (0.300)
 *  0b100..0.234 (0.348)
 *  0b101..0.258 (0.393)
 *  0b110..0.279 (0.434)
 *  0b111..0.318 (0.509)
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_MASK (0x300U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_SHIFT (8U)
/*! HPM_FDB_RES_TX - a_ip_2p4ghz_reg_dac_trim_rfbk_dig[1:0] during Transmission
 *  0b00..38.0k (1.0)
 *  0b01..76.0k (0.5)
 *  0b10..32.5k (1.14)
 *  0b11..25.3k (1.4)
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_MASK (0x3000U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_SHIFT (12U)
/*! HPM_FDB_RES_CAL - a_ip_2p4ghz_reg_dac_trim_rfbk_dig[1:0] during Calibration
 *  0b00..38.0k (1.0)
 *  0b01..76.0k (0.5)
 *  0b10..32.5k (1.14)
 *  0b11..25.3k (1.4)
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_TX_MASK (0x70000U)
#define XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_TX_SHIFT (16U)
/*! PLL_VCO_TRIM_KVM_TX - reg_vco_trim_kvm_dig[2:0] for transmit
 *  0b000..10MHz/V
 *  0b100..20MHz/V
 *  0b110..30MHz/V
 *  0b111..40MHz/V
 */
#define XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_TX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_TX_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_TX_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_CAL_MASK (0x700000U)
#define XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_CAL_SHIFT (20U)
/*! PLL_VCO_TRIM_KVM_CAL - reg_vco_trim_kvm_dig[2:0] for calibration
 *  0b000..10MHz/V
 *  0b100..20MHz/V
 *  0b110..30MHz/V
 *  0b111..40MHz/V
 */
#define XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_CAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_CAL_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_PLL_VCO_TRIM_KVM_CAL_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_BUMP_RX_TX_EN_MASK (0x1000000U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_BUMP_RX_TX_EN_SHIFT (24U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_BUMP_RX_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_BUMP_RX_TX_EN_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_BUMP_RX_TX_EN_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_RX_MASK    (0x1C000000U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_RX_SHIFT   (26U)
/*! HPM_VCM_RX - a_ip_2p4ghz_reg_dac_trim_vcm_dig[2:0] during Reception
 *  0b000..0.120 (0.122)
 *  0b001..0.153 (0.189)
 *  0b010..0.182 (0.247)
 *  0b011..0.209 (0.300)
 *  0b100..0.234 (0.348)
 *  0b101..0.258 (0.393)
 *  0b110..0.279 (0.434)
 *  0b111..0.318 (0.509)
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_RX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_RX_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_RX_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_RX_MASK (0xC0000000U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_RX_SHIFT (30U)
/*! HPM_FDB_RES_RX - a_ip_2p4ghz_reg_dac_trim_rfbk_dig[1:0] during Reception
 *  0b00..38.0k (1.0)
 *  0b01..76.0k (0.5)
 *  0b10..32.5k (1.14)
 *  0b11..25.3k (1.4)
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_RX(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_RX_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_RX_MASK)
/*! @} */

/*! @name MOD_CTRL - PLL Modulation Control */
/*! @{ */

#define XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_MASK (0x1FFFU)
#define XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_SHIFT (0U)
/*! MODULATION_WORD_MANUAL - Manual Modulation Word */
#define XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_MASK   (0x8000U)
#define XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_SHIFT  (15U)
/*! MOD_DISABLE - Disable Modulation Word */
#define XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_MASK (0xFF0000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_SHIFT (16U)
/*! HPM_MOD_MANUAL - Manual HPM Modulation */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_MASK (0x8000000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_SHIFT (27U)
/*! HPM_MOD_DISABLE - Disable HPM Modulation */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_MASK (0x30000000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_SHIFT (28U)
/*! HPM_SDM_OUT_MANUAL - Manual HPM SDM out */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_MASK (0x80000000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_SHIFT (31U)
/*! HPM_SDM_OUT_DISABLE - Disable HPM SDM out */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_MASK)
/*! @} */

/*! @name CHAN_MAP - PLL Channel Mapping */
/*! @{ */

#define XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_OVRD_MASK (0xFFFFU)
#define XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_OVRD_SHIFT (0U)
/*! CHANNEL_NUM_OVRD - Channel Selection Override */
#define XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_OVRD_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_OVRD_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_BAND_SELECT_MASK   (0x70000U)
#define XCVR_PLL_DIG_CHAN_MAP_BAND_SELECT_SHIFT  (16U)
/*! BAND_SELECT - Channel Mapping Band Select
 *  0b000..Bluetooth Low Energy
 *  0b001..Bluetooth Low Energy in MBAN
 *  0b010..Bluetooth Low Energy overlap MBAN
 *  0b011..RESERVED
 *  0b100..IEEE 802.15.4 O-QPSK PHY in ISM band
 *  0b101..IEEE 802.15.4 O-QPSK PHY in MBAN band
 *  0b110-0b111..Radio Channels 0-127 selectable
 */
#define XCVR_PLL_DIG_CHAN_MAP_BAND_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_BAND_SELECT_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_BAND_SELECT_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_BMR_MASK           (0x80000U)
#define XCVR_PLL_DIG_CHAN_MAP_BMR_SHIFT          (19U)
/*! BMR - Bluetooth Low Energy MBAN Channel Remap
 *  0b0..Bluetooth Low Energy channel 39 is mapped to Bluetooth Low Energy channel 39, 2.480 GHz
 *  0b1..Bluetooth Low Energy channel 39 is mapped to MBAN channel 39, 2.399 GHz
 */
#define XCVR_PLL_DIG_CHAN_MAP_BMR(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_BMR_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_BMR_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_MASK (0x7000000U)
#define XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_SHIFT (24U)
/*! HOP_TBL_CFG_OVRD - Hop Table Configuration Override
 *  0b000-0b001..CHANNEL_NUM_OVRD[6:0] is used as the mapped channel number. CHANNEL_NUM_OVRD[15:7] is unused.
 *  0b010..CHANNEL_NUM_OVRD[15:7] is signed Numerator offset to CHANNEL_NUM_OVRD[6:0] mapped channel number
 *  0b011..CHANNEL_NUM_OVRD[15:1] is selected as the signed Numerator, CHANNEL_NUM_OVRD[0] is integer selection
 */
#define XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_EN_MASK (0x8000000U)
#define XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_EN_SHIFT (27U)
/*! HOP_TBL_CFG_OVRD_EN - Hop Table Configuration Override Enable */
#define XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_EN_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_HOP_TBL_CFG_OVRD_EN_MASK)
/*! @} */

/*! @name CHAN_MAP_EXT - PLL Channel Mapping Extended */
/*! @{ */

#define XCVR_PLL_DIG_CHAN_MAP_EXT_NUM_OFFSET_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_CHAN_MAP_EXT_NUM_OFFSET_SHIFT (0U)
/*! NUM_OFFSET - Numerator Offset */
#define XCVR_PLL_DIG_CHAN_MAP_EXT_NUM_OFFSET(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_EXT_NUM_OFFSET_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_EXT_NUM_OFFSET_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_EXT_CTUNE_TGT_OFFSET_MASK (0x70000000U)
#define XCVR_PLL_DIG_CHAN_MAP_EXT_CTUNE_TGT_OFFSET_SHIFT (28U)
/*! CTUNE_TGT_OFFSET - Coarse Tune Target Frequency Offset */
#define XCVR_PLL_DIG_CHAN_MAP_EXT_CTUNE_TGT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_EXT_CTUNE_TGT_OFFSET_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_EXT_CTUNE_TGT_OFFSET_MASK)
/*! @} */

/*! @name LOCK_DETECT - PLL Lock Detect Control */
/*! @{ */

#define XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_MASK    (0x1U)
#define XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_SHIFT   (0U)
/*! CT_FAIL - Real time status of Coarse Tune Fail signal */
#define XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_CTFF_MASK       (0x2U)
#define XCVR_PLL_DIG_LOCK_DETECT_CTFF_SHIFT      (1U)
/*! CTFF - CTUNE Failure Flag, held until cleared */
#define XCVR_PLL_DIG_LOCK_DETECT_CTFF(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CTFF_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CTFF_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_MASK    (0x10U)
#define XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_SHIFT   (4U)
/*! FT_FAIL - Real time status of Frequency Target Failure */
#define XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTFF_MASK       (0x20U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTFF_SHIFT      (5U)
/*! FTFF - Frequency Target Failure Flag */
#define XCVR_PLL_DIG_LOCK_DETECT_FTFF(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTFF_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTFF_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_MASK (0xF00U)
#define XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_SHIFT (8U)
/*! CTUNE_LDF_LEV - CTUNE Lock Detect Fail Level */
#define XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_MASK (0x3F000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_SHIFT (12U)
/*! FTF_RX_THRSH - RX Frequency Target Fail Threshold */
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_MASK (0xFC0000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_SHIFT (18U)
/*! FTF_TX_THRSH - TX Frequency Target Fail Threshold */
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FCAL_HOLD_EN_MASK (0x1000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FCAL_HOLD_EN_SHIFT (24U)
/*! FCAL_HOLD_EN - Frequency Counter Hold Enable
 *  0b0..The frequency counter is turned off after CTUNE (RX Mode) or HPM CAL (TX Mode)
 *  0b1..The frequency counter is held on after CTUNE (RX Mode) or HPM CAL (TX Mode) for an optional lock detect sequence.
 */
#define XCVR_PLL_DIG_LOCK_DETECT_FCAL_HOLD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FCAL_HOLD_EN_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FCAL_HOLD_EN_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTW_TXRX_MASK   (0xE000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTW_TXRX_SHIFT  (25U)
/*! FTW_TXRX - TX and RX Frequency Target Window time select
 *  0b000..FTW_TX = 4us ; FTW_RX = 4us
 *  0b001..FTW_TX = 4us ; FTW_RX = 8us
 *  0b010..FTW_TX = 8us ; FTW_RX = 4us
 *  0b011..FTW_TX = 8us ; FTW_RX = 8us
 *  0b100..FTW_TX = 16us ; FTW_RX = 16us
 *  0b101..FTW_TX = 16us ; FTW_RX = 32us
 *  0b110..FTW_TX = 32us ; FTW_RX = 16us
 *  0b111..FTW_TX = 32us ; FTW_RX = 32us
 */
#define XCVR_PLL_DIG_LOCK_DETECT_FTW_TXRX(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTW_TXRX_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTW_TXRX_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_MASK (0x10000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_SHIFT (28U)
/*! FREQ_COUNT_GO - Start the Frequency Meter */
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_MASK (0x20000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_SHIFT (29U)
/*! FREQ_COUNT_FINISHED - Frequency Meter has finished the Count Time */
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_MASK (0xC0000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_SHIFT (30U)
/*! FREQ_COUNT_TIME - Frequency Meter Count Time
 *  0b00..800 us
 *  0b01..25 us
 *  0b10..50 us
 *  0b11..100 us
 */
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_MASK)
/*! @} */

/*! @name HPM_CTRL - PLL High Port Modulator Control */
/*! @{ */

#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_MASK (0x3FFU)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_SHIFT (0U)
/*! HPM_SDM_IN_MANUAL - Manual High Port SDM Fractional value */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_SEL_MASK (0x400U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_SEL_SHIFT (10U)
/*! HPM_DYNAMIC_SEL - HPM dynamic calibration factor source selection for channel sounding */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_SEL_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_SEL_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_CLK_CONFIG_MASK (0x1000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CLK_CONFIG_SHIFT (12U)
/*! HPM_CLK_CONFIG - HPM Clock Config */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CLK_CONFIG(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_CLK_CONFIG_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_CLK_CONFIG_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPFF_MASK          (0x2000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPFF_SHIFT         (13U)
/*! HPFF - HPM SDM Invalid Flag */
#define XCVR_PLL_DIG_HPM_CTRL_HPFF(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPFF_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPFF_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_MASK (0x4000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_SHIFT (14U)
/*! HPM_SDM_OUT_INVERT - Invert HPM SDM Output */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_MASK (0x8000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_SHIFT (15U)
/*! HPM_SDM_IN_DISABLE - Disable HPM SDM Input */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_MASK (0x70000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_SHIFT (16U)
/*! HPM_LFSR_SIZE - HPM LFSR Length
 *  0b000..LFSR 9, tap mask 100010000
 *  0b001..LFSR 10, tap mask 1001000000
 *  0b010..LFSR 11, tap mask 11101000000
 *  0b011..LFSR 13, tap mask 1101100000000
 *  0b100..LFSR 15, tap mask 111010000000000
 *  0b101..LFSR 17, tap mask 11110000000000000
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_RX_HPM_CAL_EN_MASK (0x80000U)
#define XCVR_PLL_DIG_HPM_CTRL_RX_HPM_CAL_EN_SHIFT (19U)
/*! RX_HPM_CAL_EN - Receive HPM Calibration Enable */
#define XCVR_PLL_DIG_HPM_CTRL_RX_HPM_CAL_EN(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_RX_HPM_CAL_EN_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_RX_HPM_CAL_EN_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_MASK   (0x100000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_SHIFT  (20U)
/*! HPM_DTH_SCL - HPM Dither Scale */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_PKT_TABLE_MASK (0x200000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_PKT_TABLE_SHIFT (21U)
/*! HPM_DYNAMIC_RX_PKT_TABLE
 *  0b0..constant value from HPM_CAL_FACTOR_MANUAL register
 *  0b1..table value from packet RAM
 */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_PKT_TABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_PKT_TABLE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_PKT_TABLE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_TONE_TABLE_MASK (0x400000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_TONE_TABLE_SHIFT (22U)
/*! HPM_DYNAMIC_RX_TONE_TABLE
 *  0b0..constant value from HPM_CAL_FACTOR_MANUAL register
 *  0b1..table value from packet RAM
 */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_TONE_TABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_TONE_TABLE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_DYNAMIC_RX_TONE_TABLE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_MASK    (0x800000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_SHIFT   (23U)
/*! HPM_DTH_EN - Dither Enable for HPM LFSR */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_SCALE_MASK     (0x7000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SCALE_SHIFT    (24U)
/*! HPM_SCALE - High Port Modulation Scale
 *  0b000..No Scaling
 *  0b001..Divide by 2
 *  0b010..Multiply by 2
 *  0b011..Multiply by 4
 *  0b100..Divide by 4
 *  0b101..Multiply by 8
 *  0b110..Divide by 8
 *  0b111..N/A
 */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SCALE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_SCALE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_SCALE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_MASK (0x8000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_SHIFT (27U)
/*! HPM_INTEGER_INVERT - Invert High Port Modulation Integer */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_MASK (0x10000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_SHIFT (28U)
/*! HPM_CAL_INVERT - Invert High Port Modulator Calibration */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_TIME_MASK  (0x60000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_TIME_SHIFT (29U)
/*! HPM_CAL_TIME - High Port Modulation Calibration Time
 *  0b00..25 us
 *  0b01..50 us
 *  0b10..100 us
 *  0b11..N/A
 */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_TIME(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_TIME_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_TIME_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_MASK (0x80000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_SHIFT (31U)
/*! HPM_MOD_IN_INVERT - Invert High Port Modulation */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_MASK)
/*! @} */

/*! @name HPM_SDM_RES - PLL High Port Sigma Delta Results */
/*! @{ */

#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_MASK (0x3FFU)
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_SHIFT (0U)
/*! HPM_NUM_SELECTED - High Port Modulator SDM Numerator */
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_SHIFT)) & XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_MASK)

#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_MASK  (0x3FF0000U)
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_SHIFT (16U)
/*! HPM_DENOM - High Port Modulator SDM Denominator */
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_SHIFT)) & XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_MASK)

#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_MASK (0xF0000000U)
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_SHIFT (28U)
/*! HPM_COUNT_ADJUST - HPM_COUNT_ADJUST */
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_SHIFT)) & XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_MASK)
/*! @} */

/*! @name LPM_CTRL - PLL Low Port Modulator Control */
/*! @{ */

#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_MASK (0x1FU)
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_SHIFT (0U)
/*! PLL_LD_MANUAL - Manual PLL Loop Divider value */
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_HPM_CAL_SCALE_MASK (0xF00U)
#define XCVR_PLL_DIG_LPM_CTRL_HPM_CAL_SCALE_SHIFT (8U)
/*! HPM_CAL_SCALE - High Port Calibration Word Scaling
 *  0b0000-0b0010..No Scaling
 *  0b0011..Divide by 32
 *  0b0100..Divide by 16
 *  0b0101..Divide by 8
 *  0b0110..Divide by 4
 *  0b0111..Divide by 2
 *  0b1000..No Scaling
 *  0b1001..Multiply by 2
 *  0b1010..Multiply by 4
 *  0b1011..Multiply by 8
 *  0b1011-0b1111..No Scaling
 */
#define XCVR_PLL_DIG_LPM_CTRL_HPM_CAL_SCALE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_HPM_CAL_SCALE_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_HPM_CAL_SCALE_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_MASK (0x1000U)
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_SHIFT (12U)
/*! PLL_LD_DISABLE - Disable PLL Loop Divider */
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPFF_MASK          (0x2000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPFF_SHIFT         (13U)
/*! LPFF - LPM SDM Invalid Flag */
#define XCVR_PLL_DIG_LPM_CTRL_LPFF(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPFF_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPFF_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_MASK   (0x4000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_SHIFT  (14U)
/*! LPM_SDM_INV - Invert LPM SDM */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_MASK   (0x8000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_SHIFT  (15U)
/*! LPM_DISABLE - Disable LPM SDM */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_MASK   (0xF0000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_SHIFT  (16U)
/*! LPM_DTH_SCL - LPM Dither Scale
 *  0b0000..Reserved
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..-128 to 96
 *  0b0110..-256 to 192
 *  0b0111..-512 to 384
 *  0b1000..-1024 to 768
 *  0b1001..-2048 to 1536
 *  0b1010..-4096 to 3072
 *  0b1011..-8192 to 6144
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_MASK    (0x400000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_SHIFT   (22U)
/*! LPM_D_CTRL - LPM Dither Control in Override Mode */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_MASK    (0x800000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_SHIFT   (23U)
/*! LPM_D_OVRD - LPM Dither Override Mode Select */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_MASK     (0xF000000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_SHIFT    (24U)
/*! LPM_SCALE - LPM Scale Factor
 *  0b0000..No Scaling
 *  0b0001..Multiply by 2
 *  0b0010..Multiply by 4
 *  0b0011..Multiply by 8
 *  0b0100..Multiply by 16
 *  0b0101..Multiply by 32
 *  0b0110..Multiply by 64
 *  0b0111..Multiply by 128
 *  0b1000..Multiply by 256
 */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_FAST_SW_MASK   (0x10000000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_FAST_SW_SHIFT  (28U)
/*! LPM_FAST_SW - LPM Fast Switch mode */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_FAST_SW(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_FAST_SW_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_FAST_SW_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_CODES_ADJ_MASK (0x20000000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_CODES_ADJ_SHIFT (29U)
/*! LPM_CODES_ADJ - LPM SDM Codes Adjustment */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_CODES_ADJ(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_CODES_ADJ_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_CODES_ADJ_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_SKIP_CNT_DELAY_MASK (0x40000000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SKIP_CNT_DELAY_SHIFT (30U)
/*! LPM_SKIP_CNT_DELAY - LPM SDM Skip Counter Delay */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SKIP_CNT_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_SKIP_CNT_DELAY_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_SKIP_CNT_DELAY_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_MASK (0x80000000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_SHIFT (31U)
/*! LPM_SDM_USE_NEG - Use the Negedge of the Sigma Delta clock */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_MASK)
/*! @} */

/*! @name LPM_SDM_CTRL1 - PLL Low Port Sigma Delta Control 1 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_MASK (0x7FU)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_SHIFT (0U)
/*! LPM_INTG_SELECTED - Low Port Modulation Integer Value Selected */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_MASK (0x7F00U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_SHIFT (8U)
/*! HPM_ARRAY_BIAS - Bias value for High Port DAC Array Midpoint */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_MASK (0x7F0000U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SHIFT (16U)
/*! LPM_INTG - Manual Low Port Modulation Integer Value */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_VAL_MASK (0x7800000U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_VAL_SHIFT (23U)
/*! LPM_FCODES_VAL - LPM SDM Forced Value */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_VAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_VAL_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_VAL_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_CNT_MASK (0x78000000U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_CNT_SHIFT (27U)
/*! LPM_FCODES_CNT - LPM SDM Forced Counter */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_CNT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_CNT_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_FCODES_CNT_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_MASK (0x80000000U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_SHIFT (31U)
/*! SDM_MAP_DISABLE - Disable SDM Mapping */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_MASK)
/*! @} */

/*! @name LPM_SDM_CTRL2 - PLL Low Port Sigma Delta Control 2 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_MASK  (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_SHIFT (0U)
/*! LPM_NUM - Low Port Modulation Numerator */
#define XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_MASK)
/*! @} */

/*! @name LPM_SDM_CTRL3 - PLL Low Port Sigma Delta Control 3 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_SHIFT (0U)
/*! LPM_DENOM - Low Port Modulation Denominator */
#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_SDM_INT_SHIFT_MASK (0x30000000U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_SDM_INT_SHIFT_SHIFT (28U)
/*! LPM_SDM_INT_SHIFT - Low Port Modulation Denominator */
#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_SDM_INT_SHIFT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_SDM_INT_SHIFT_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_SDM_INT_SHIFT_MASK)
/*! @} */

/*! @name LPM_SDM_RES1 - PLL Low Port Sigma Delta Result 1 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_SHIFT (0U)
/*! LPM_NUM_SELECTED - Low Port Modulation Numerator Applied */
#define XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_MASK)
/*! @} */

/*! @name LPM_SDM_RES2 - PLL Low Port Sigma Delta Result 2 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_SHIFT (0U)
/*! LPM_DENOM_SELECTED - Low Port Modulation Denominator Selected */
#define XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_MASK)
/*! @} */

/*! @name DELAY_MATCH - PLL Delay Matching */
/*! @{ */

#define XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_MASK (0xFU)
#define XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_SHIFT (0U)
/*! LPM_SDM_DELAY - Low Port SDM Delay Matching */
#define XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_SHIFT)) & XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_MASK)

#define XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_MASK (0xF00U)
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_SHIFT (8U)
/*! HPM_SDM_DELAY - High Port SDM Delay Matching */
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_SHIFT)) & XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_MASK)

#define XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_MASK (0xF0000U)
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_SHIFT (16U)
/*! HPM_INTEGER_DELAY - High Port Integer Delay Matching */
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_SHIFT)) & XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_MASK)
/*! @} */

/*! @name TUNING_CAP_TX_CTRL - Tuning Cap Settings in Transmit Mode */
/*! @{ */

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_0_MASK (0x7U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_0_SHIFT (0U)
/*! TUNING_RANGE_0 - Tuning Range 0 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_0_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_0_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_1_MASK (0x38U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_1_SHIFT (3U)
/*! TUNING_RANGE_1 - Tuning Range 1 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_1_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_1_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_2_MASK (0x1C0U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_2_SHIFT (6U)
/*! TUNING_RANGE_2 - Tuning Range 2 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_2_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_2_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_3_MASK (0xE00U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_3_SHIFT (9U)
/*! TUNING_RANGE_3 - Tuning Range 3 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_3_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_3_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_4_MASK (0x7000U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_4_SHIFT (12U)
/*! TUNING_RANGE_4 - Tuning Range 4 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_4_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_4_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_5_MASK (0x38000U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_5_SHIFT (15U)
/*! TUNING_RANGE_5 - Tuning Range 5 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_5_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_5_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_6_MASK (0x1C0000U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_6_SHIFT (18U)
/*! TUNING_RANGE_6 - Tuning Range 6 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_6_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_6_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_7_MASK (0xE00000U)
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_7_SHIFT (21U)
/*! TUNING_RANGE_7 - Tuning Range 7 */
#define XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_7_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_TX_CTRL_TUNING_RANGE_7_MASK)
/*! @} */

/*! @name TUNING_CAP_RX_CTRL - Tuning Cap Settings in Receive Mode */
/*! @{ */

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_0_MASK (0x7U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_0_SHIFT (0U)
/*! TUNING_RANGE_0 - Tuning Range 0 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_0_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_0_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_1_MASK (0x38U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_1_SHIFT (3U)
/*! TUNING_RANGE_1 - Tuning Range 1 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_1_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_1_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_2_MASK (0x1C0U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_2_SHIFT (6U)
/*! TUNING_RANGE_2 - Tuning Range 2 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_2_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_2_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_3_MASK (0xE00U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_3_SHIFT (9U)
/*! TUNING_RANGE_3 - Tuning Range 3 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_3_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_3_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_4_MASK (0x7000U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_4_SHIFT (12U)
/*! TUNING_RANGE_4 - Tuning Range 4 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_4_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_4_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_5_MASK (0x38000U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_5_SHIFT (15U)
/*! TUNING_RANGE_5 - Tuning Range 5 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_5_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_5_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_6_MASK (0x1C0000U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_6_SHIFT (18U)
/*! TUNING_RANGE_6 - Tuning Range 6 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_6_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_6_MASK)

#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_7_MASK (0xE00000U)
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_7_SHIFT (21U)
/*! TUNING_RANGE_7 - Tuning Range 7 */
#define XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_7_SHIFT)) & XCVR_PLL_DIG_TUNING_CAP_RX_CTRL_TUNING_RANGE_7_MASK)
/*! @} */

/*! @name MAX_MIN_TX_CFG1_FREQ - Max and Min Transmit Frequencies For TX Configuration 1 */
/*! @{ */

#define XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MAX_TX_CFG1_FREQ_MASK (0xFFFU)
#define XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MAX_TX_CFG1_FREQ_SHIFT (0U)
/*! MAX_TX_CFG1_FREQ - Maximum Transmit Frequency for Standard TX Settings */
#define XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MAX_TX_CFG1_FREQ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MAX_TX_CFG1_FREQ_SHIFT)) & XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MAX_TX_CFG1_FREQ_MASK)

#define XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MIN_TX_CFG1_FREQ_MASK (0xFFF0000U)
#define XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MIN_TX_CFG1_FREQ_SHIFT (16U)
/*! MIN_TX_CFG1_FREQ - Minimum Transmit Frequency for Standard TX Settings */
#define XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MIN_TX_CFG1_FREQ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MIN_TX_CFG1_FREQ_SHIFT)) & XCVR_PLL_DIG_MAX_MIN_TX_CFG1_FREQ_MIN_TX_CFG1_FREQ_MASK)
/*! @} */

/*! @name CTUNE_CTRL - PLL Coarse Tune Control */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_MASK (0xFFFU)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_SHIFT (0U)
/*! CTUNE_TARGET_MANUAL - Manual Coarse Tune Target */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_CNTR_RLS_RST_MASK (0x7000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_CNTR_RLS_RST_SHIFT (12U)
/*! CTUNE_CNTR_RLS_RST - Coarse Tune Counter Release Reset */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_CNTR_RLS_RST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_CNTR_RLS_RST_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_CNTR_RLS_RST_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_MASK (0x8000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_SHIFT (15U)
/*! CTUNE_TARGET_DISABLE - Disable Coarse Tune Target */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_MASK (0x1F0000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_SHIFT (16U)
/*! CTUNE_ADJUST - Coarse Tune Count Adjustment */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_MASK (0x3FE00000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_SHIFT (21U)
/*! CTUNE_MANUAL - Manual Coarse Tune Setting */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_MASK (0x80000000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_SHIFT (31U)
/*! CTUNE_DISABLE - Coarse Tune Disable */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_MASK)
/*! @} */

/*! @name DATA_RATE_OVRD_CTRL1 - PLL Data Rate Override Control */
/*! @{ */

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_CAL_SCALE_CFG1_MASK (0xFU)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_CAL_SCALE_CFG1_SHIFT (0U)
/*! HPM_CAL_SCALE_CFG1 - HPM Scale Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_CAL_SCALE_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_CAL_SCALE_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_CAL_SCALE_CFG1_MASK)

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_LPM_SCALE_CFG1_MASK (0xF0U)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_LPM_SCALE_CFG1_SHIFT (4U)
/*! LPM_SCALE_CFG1 - LPM Scale Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_LPM_SCALE_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_LPM_SCALE_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_LPM_SCALE_CFG1_MASK)

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_CAL_CFG1_MASK (0x300U)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_CAL_CFG1_SHIFT (8U)
/*! HPM_FDB_RES_CAL_CFG1 - HPM FDB RES Calibration Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_CAL_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_CAL_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_CAL_CFG1_MASK)

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_TX_CFG1_MASK (0xC00U)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_TX_CFG1_SHIFT (10U)
/*! HPM_FDB_RES_TX_CFG1 - HPM FDB RES Transmit Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_TX_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_TX_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_TX_CFG1_MASK)

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_BUMP_RX_TX_EN_CFG1_MASK (0x1000000U)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_BUMP_RX_TX_EN_CFG1_SHIFT (24U)
/*! HPM_BUMP_RX_TX_EN_CFG1 - HPM BUMP RX/TX enable Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_BUMP_RX_TX_EN_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_BUMP_RX_TX_EN_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_BUMP_RX_TX_EN_CFG1_MASK)

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_VCM_RX_CFG1_MASK (0x1C000000U)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_VCM_RX_CFG1_SHIFT (26U)
/*! HPM_VCM_RX_CFG1 - HPM VCM RX Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_VCM_RX_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_VCM_RX_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_VCM_RX_CFG1_MASK)

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_RX_CFG1_MASK (0xC0000000U)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_RX_CFG1_SHIFT (30U)
/*! HPM_FDB_RES_RX_CFG1 - HPM FDB RES RX Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_RX_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_RX_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL1_HPM_FDB_RES_RX_CFG1_MASK)
/*! @} */

/*! @name DATA_RATE_OVRD_CTRL2 - PLL Data Rate Override Control */
/*! @{ */

#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL2_NUM_OFFSET_CFG1_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL2_NUM_OFFSET_CFG1_SHIFT (0U)
/*! NUM_OFFSET_CFG1 - Numerator Offset Configuration1 */
#define XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL2_NUM_OFFSET_CFG1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL2_NUM_OFFSET_CFG1_SHIFT)) & XCVR_PLL_DIG_DATA_RATE_OVRD_CTRL2_NUM_OFFSET_CFG1_MASK)
/*! @} */

/*! @name CTUNE_RES - PLL Coarse Tune Results */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_MASK (0x1FFU)
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_SHIFT (0U)
/*! CTUNE_SELECTED - Coarse Tune Setting to VCO */
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_SHIFT)) & XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_MASK)

#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_MASK (0x3FC00U)
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_SHIFT (10U)
/*! CTUNE_BEST_DIFF - Coarse Tune Absolute Best Difference */
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_SHIFT)) & XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_MASK)

#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_MASK (0x3FFC0000U)
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_SHIFT (18U)
/*! CTUNE_FREQ_SELECTED - Coarse Tune Frequency Selected */
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_SHIFT)) & XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_MASK)
/*! @} */

/*! @name HPM_CAL_TIMING - PLL HPM Calibration Timing Attributes */
/*! @{ */

#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CTUNE_SETTLE_TIME_MASK (0xFU)
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CTUNE_SETTLE_TIME_SHIFT (0U)
/*! HPM_CTUNE_SETTLE_TIME - CTUNE Settling Time */
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CTUNE_SETTLE_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CTUNE_SETTLE_TIME_SHIFT)) & XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CTUNE_SETTLE_TIME_MASK)

#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL1_SETTLE_TIME_MASK (0xF0U)
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL1_SETTLE_TIME_SHIFT (4U)
/*! HPM_CAL1_SETTLE_TIME - HPM Calibration1 Settling Time */
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL1_SETTLE_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL1_SETTLE_TIME_SHIFT)) & XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL1_SETTLE_TIME_MASK)

#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL2_SETTLE_TIME_MASK (0xF00U)
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL2_SETTLE_TIME_SHIFT (8U)
/*! HPM_CAL2_SETTLE_TIME - HPM Calibration2 Settling Time */
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL2_SETTLE_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL2_SETTLE_TIME_SHIFT)) & XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_CAL2_SETTLE_TIME_MASK)

#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_VCO_MOD_DELAY_MASK (0xFFFF0000U)
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_VCO_MOD_DELAY_SHIFT (16U)
/*! HPM_VCO_MOD_DELAY - HPM VCO Modification Output Delay */
#define XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_VCO_MOD_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_VCO_MOD_DELAY_SHIFT)) & XCVR_PLL_DIG_HPM_CAL_TIMING_HPM_VCO_MOD_DELAY_MASK)
/*! @} */

/*! @name PLL_OFFSET_CTRL - PLL Offset Control */
/*! @{ */

#define XCVR_PLL_DIG_PLL_OFFSET_CTRL_PLL_NUMERATOR_OFFSET_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_PLL_OFFSET_CTRL_PLL_NUMERATOR_OFFSET_SHIFT (0U)
/*! PLL_NUMERATOR_OFFSET - PLL Numerator Offset */
#define XCVR_PLL_DIG_PLL_OFFSET_CTRL_PLL_NUMERATOR_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_OFFSET_CTRL_PLL_NUMERATOR_OFFSET_SHIFT)) & XCVR_PLL_DIG_PLL_OFFSET_CTRL_PLL_NUMERATOR_OFFSET_MASK)
/*! @} */

/*! @name PLL_DATARATE_CTRL - PLL Data Rate Switch Control */
/*! @{ */

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_TX_DRS_MASK (0x7U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_TX_DRS_SHIFT (0U)
/*! HPM_VCM_TX_DRS - Data Rate Switch for hpm_vcm_tx
 *  0b000..432 mV
 *  0b001..328 mV
 *  0b010..456 mV
 *  0b011..473 mV
 *  0b100..488 mV
 *  0b101..408 mV
 *  0b110..392 mV
 *  0b111..376 mV
 */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_TX_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_TX_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_TX_DRS_MASK)

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_CAL_DRS_MASK (0x70U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_CAL_DRS_SHIFT (4U)
/*! HPM_VCM_CAL_DRS - Data Rate Switch for hpm_vcm_cal
 *  0b000..432 mV
 *  0b001..328 mV
 *  0b010..456 mV
 *  0b011..473 mV
 *  0b100..488 mV
 *  0b101..408 mV
 *  0b110..392 mV
 *  0b111..376 mV
 */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_CAL_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_CAL_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_VCM_CAL_DRS_MASK)

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_TX_DRS_MASK (0x700U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_TX_DRS_SHIFT (8U)
/*! PLL_VCO_TRIM_KVM_TX_DRS - Data Rate Switch for pll_vco_trim_kvm_tx.
 *  0b000..10MHz/V
 *  0b100..20MHz/V
 *  0b110..30MHz/V
 *  0b111..40MHz/V
 */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_TX_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_TX_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_TX_DRS_MASK)

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_CAL_DRS_MASK (0x7000U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_CAL_DRS_SHIFT (12U)
/*! PLL_VCO_TRIM_KVM_CAL_DRS - Data Rate Switch for pll_vco_trim_kvm_cal
 *  0b000..10MHz/V
 *  0b100..20MHz/V
 *  0b110..30MHz/V
 *  0b111..40MHz/V
 */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_CAL_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_CAL_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_PLL_VCO_TRIM_KVM_CAL_DRS_MASK)

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_LPM_SDM_DELAY_DRS_MASK (0xF0000U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_LPM_SDM_DELAY_DRS_SHIFT (16U)
/*! LPM_SDM_DELAY_DRS - DRS LPM_SDM_DELAY */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_LPM_SDM_DELAY_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_LPM_SDM_DELAY_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_LPM_SDM_DELAY_DRS_MASK)

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_SDM_DELAY_DRS_MASK (0xF00000U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_SDM_DELAY_DRS_SHIFT (20U)
/*! HPM_SDM_DELAY_DRS - DRS HPM_SDM_DELAY */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_SDM_DELAY_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_SDM_DELAY_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_SDM_DELAY_DRS_MASK)

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_INTEGER_DELAY_DRS_MASK (0xF000000U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_INTEGER_DELAY_DRS_SHIFT (24U)
/*! HPM_INTEGER_DELAY_DRS - DRS HPM_SDM_DELAY */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_INTEGER_DELAY_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_INTEGER_DELAY_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_INTEGER_DELAY_DRS_MASK)

#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_COUNT_ADJUST_DRS_MASK (0xF0000000U)
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_COUNT_ADJUST_DRS_SHIFT (28U)
/*! HPM_COUNT_ADJUST_DRS - HPM_COUNT_ADJUST_DRS */
#define XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_COUNT_ADJUST_DRS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_COUNT_ADJUST_DRS_SHIFT)) & XCVR_PLL_DIG_PLL_DATARATE_CTRL_HPM_COUNT_ADJUST_DRS_MASK)
/*! @} */

/*! @name PLL_PHASE_COMPENSATION - PLL phase compensation */
/*! @{ */

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_MASK (0x3U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_SHIFT (0U)
/*! EN_INPR - Enable for feature Inline phase return ranging */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_RX_NORM_MASK (0x4U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_RX_NORM_SHIFT (2U)
/*! EN_INPR_RX_NORM - Enable for Inline phase return feature, rx_norm contribution */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_RX_NORM(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_RX_NORM_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_INPR_RX_NORM_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_COMP_INV_MASK (0x8U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_COMP_INV_SHIFT (3U)
/*! RX_COMP_INV - Rx phase compensation inversion */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_COMP_INV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_COMP_INV_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_COMP_INV_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_DT_MASK (0x30U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_DT_SHIFT (4U)
/*! INPR_DT - Inline phase return ranging integration period
 *  0b00..4 SDM clock cycles, 0.0625us
 *  0b01..8 SDM clock cycles, 0.125us
 *  0b10..16 SDM clock cycles, 0.25us
 *  0b11..32 SDM clock cycles, 0.5us
 */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_DT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_DT_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_DT_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_CORR_INV_MASK (0x40U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_CORR_INV_SHIFT (6U)
/*! INPR_CORR_INV - INPR_CORR_INV */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_CORR_INV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_CORR_INV_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_CORR_INV_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_TQI_DIS_MASK (0x80U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_TQI_DIS_SHIFT (7U)
/*! INPR_TX_TQI_DIS - INPR_TX_TQI_DIS */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_TQI_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_TQI_DIS_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_TQI_DIS_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_START_TUNING_MASK (0x3F00U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_START_TUNING_SHIFT (8U)
/*! INPR_START_TUNING - Fine phase shift start for inline phase return */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_START_TUNING(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_START_TUNING_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_START_TUNING_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_T_EXT_TQI_EN_MASK (0x4000U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_T_EXT_TQI_EN_SHIFT (14U)
/*! INPR_TX_T_EXT_TQI_EN - INPR_TX_T_EXT_TQI_EN */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_T_EXT_TQI_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_T_EXT_TQI_EN_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_T_EXT_TQI_EN_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_PA_PUP_TQI_EN_MASK (0x8000U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_PA_PUP_TQI_EN_SHIFT (15U)
/*! INPR_TX_PA_PUP_TQI_EN - INPR_TX_PA_PUP_TQI_EN */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_PA_PUP_TQI_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_PA_PUP_TQI_EN_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_INPR_TX_PA_PUP_TQI_EN_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_PLL_PHASE_SHIFT_MASK (0x30000U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_PLL_PHASE_SHIFT_SHIFT (16U)
/*! EN_PLL_PHASE_SHIFT - PLL phase shift */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_PLL_PHASE_SHIFT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_PLL_PHASE_SHIFT_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_EN_PLL_PHASE_SHIFT_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_DT_MASK (0xC0000U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_DT_SHIFT (18U)
/*! RX_PHASE_COMP_DT - RX compensation phase integration period
 *  0b00..4 SDM clock cycles, 0.0625us
 *  0b01..8 SDM clock cycles, 0.125us
 *  0b10..16 SDM clock cycles, 0.25us
 *  0b11..32 SDM clock cycles, 0.5us
 */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_DT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_DT_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_DT_MASK)

#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_START_TUNING_MASK (0x3F00000U)
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_START_TUNING_SHIFT (20U)
/*! RX_PHASE_COMP_START_TUNING - Fine phase shift start for RX phase compensation */
#define XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_START_TUNING(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_START_TUNING_SHIFT)) & XCVR_PLL_DIG_PLL_PHASE_COMPENSATION_RX_PHASE_COMP_START_TUNING_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_PLL_DIG_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_PLL_DIG_Peripheral_Access_Layer */


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


#endif  /* PERI_XCVR_PLL_DIG_H_ */

