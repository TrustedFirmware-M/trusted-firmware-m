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
**         CMSIS Peripheral Access Layer for XCVR_ZBDEMOD
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
 * @file PERI_XCVR_ZBDEMOD.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for XCVR_ZBDEMOD
 *
 * CMSIS Peripheral Access Layer for XCVR_ZBDEMOD
 */

#if !defined(PERI_XCVR_ZBDEMOD_H_)
#define PERI_XCVR_ZBDEMOD_H_                     /**< Symbol preventing repeated inclusion */

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
   -- XCVR_ZBDEMOD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ZBDEMOD_Peripheral_Access_Layer XCVR_ZBDEMOD Peripheral Access Layer
 * @{
 */

/** XCVR_ZBDEMOD - Register Layout Typedef */
typedef struct {
  __IO uint32_t CORR_CTRL;                         /**< 802.15.4 DEMOD CORRELATOR CONTROL, offset: 0x0 */
  __IO uint32_t PN_TYPE;                           /**< 802.15.4 DEMOD PN TYPE, offset: 0x4 */
  __IO uint32_t PN_CODE;                           /**< 802.15.4 DEMOD PN CODE, offset: 0x8 */
  __IO uint32_t SYNC_CTRL;                         /**< 802.15.4 DEMOD SYMBOL SYNC CONTROL, offset: 0xC */
  __IO uint32_t CCA_LQI_SRC;                       /**< 802.15.4 CCA/LQI SOURCE, offset: 0x10 */
  __IO uint32_t FAD_LPPS_THR;                      /**< FAD CORRELATOR THRESHOLD, offset: 0x14 */
  __IO uint32_t ZBDEM_AFC;                         /**< 802.15.4 AFC STATUS, offset: 0x18 */
  __IO uint32_t CCA2_CTRL;                         /**< CCA MODE 2 CONTROL REGISTER, offset: 0x1C */
  __IO uint32_t CCA2_THRESH;                       /**< CCA MODE 2 CONTROL REGISTER, offset: 0x20 */
  __I  uint32_t CCA2_STATUS;                       /**< CCA MODE 2 STATUS REGISTER, offset: 0x24 */
  __IO uint32_t CORR_CTRL2;                        /**< 802.15.4 DEMOD CORRELATOR CONTROL2, offset: 0x28 */
} XCVR_ZBDEMOD_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_ZBDEMOD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ZBDEMOD_Register_Masks XCVR_ZBDEMOD Register Masks
 * @{
 */

/*! @name CORR_CTRL - 802.15.4 DEMOD CORRELATOR CONTROL */
/*! @{ */

#define XCVR_ZBDEMOD_CORR_CTRL_CORR_VT_MASK      (0xFFU)
#define XCVR_ZBDEMOD_CORR_CTRL_CORR_VT_SHIFT     (0U)
/*! CORR_VT - CORR_VT */
#define XCVR_ZBDEMOD_CORR_CTRL_CORR_VT(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CORR_CTRL_CORR_VT_SHIFT)) & XCVR_ZBDEMOD_CORR_CTRL_CORR_VT_MASK)

#define XCVR_ZBDEMOD_CORR_CTRL_CORR_NVAL_MASK    (0x700U)
#define XCVR_ZBDEMOD_CORR_CTRL_CORR_NVAL_SHIFT   (8U)
/*! CORR_NVAL - CORR_NVAL */
#define XCVR_ZBDEMOD_CORR_CTRL_CORR_NVAL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CORR_CTRL_CORR_NVAL_SHIFT)) & XCVR_ZBDEMOD_CORR_CTRL_CORR_NVAL_MASK)

#define XCVR_ZBDEMOD_CORR_CTRL_MAX_CORR_EN_MASK  (0x800U)
#define XCVR_ZBDEMOD_CORR_CTRL_MAX_CORR_EN_SHIFT (11U)
/*! MAX_CORR_EN - MAX_CORR_EN */
#define XCVR_ZBDEMOD_CORR_CTRL_MAX_CORR_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CORR_CTRL_MAX_CORR_EN_SHIFT)) & XCVR_ZBDEMOD_CORR_CTRL_MAX_CORR_EN_MASK)

#define XCVR_ZBDEMOD_CORR_CTRL_ZBDEM_CLK_ON_MASK (0x8000U)
#define XCVR_ZBDEMOD_CORR_CTRL_ZBDEM_CLK_ON_SHIFT (15U)
/*! ZBDEM_CLK_ON - Force 802.15.4 Demodulator Clock On
 *  0b0..Normal Operation
 *  0b1..Force 802.15.4 Demodulator Clock On (debug purposes only)
 */
#define XCVR_ZBDEMOD_CORR_CTRL_ZBDEM_CLK_ON(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CORR_CTRL_ZBDEM_CLK_ON_SHIFT)) & XCVR_ZBDEMOD_CORR_CTRL_ZBDEM_CLK_ON_MASK)

#define XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_CORR_MASK  (0xFF0000U)
#define XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_CORR_SHIFT (16U)
/*! RX_MAX_CORR - RX_MAX_CORR */
#define XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_CORR(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_CORR_SHIFT)) & XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_CORR_MASK)

#define XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_PREAMBLE_MASK (0xFF000000U)
#define XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_PREAMBLE_SHIFT (24U)
/*! RX_MAX_PREAMBLE - RX_MAX_PREAMBLE */
#define XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_PREAMBLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_PREAMBLE_SHIFT)) & XCVR_ZBDEMOD_CORR_CTRL_RX_MAX_PREAMBLE_MASK)
/*! @} */

/*! @name PN_TYPE - 802.15.4 DEMOD PN TYPE */
/*! @{ */

#define XCVR_ZBDEMOD_PN_TYPE_PN_TYPE_MASK        (0x1U)
#define XCVR_ZBDEMOD_PN_TYPE_PN_TYPE_SHIFT       (0U)
/*! PN_TYPE - PN_TYPE */
#define XCVR_ZBDEMOD_PN_TYPE_PN_TYPE(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_PN_TYPE_PN_TYPE_SHIFT)) & XCVR_ZBDEMOD_PN_TYPE_PN_TYPE_MASK)

#define XCVR_ZBDEMOD_PN_TYPE_TX_INV_MASK         (0x2U)
#define XCVR_ZBDEMOD_PN_TYPE_TX_INV_SHIFT        (1U)
/*! TX_INV - TX_INV */
#define XCVR_ZBDEMOD_PN_TYPE_TX_INV(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_PN_TYPE_TX_INV_SHIFT)) & XCVR_ZBDEMOD_PN_TYPE_TX_INV_MASK)
/*! @} */

/*! @name PN_CODE - 802.15.4 DEMOD PN CODE */
/*! @{ */

#define XCVR_ZBDEMOD_PN_CODE_PN_LSB_MASK         (0xFFFFU)
#define XCVR_ZBDEMOD_PN_CODE_PN_LSB_SHIFT        (0U)
/*! PN_LSB - PN_LSB */
#define XCVR_ZBDEMOD_PN_CODE_PN_LSB(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_PN_CODE_PN_LSB_SHIFT)) & XCVR_ZBDEMOD_PN_CODE_PN_LSB_MASK)

#define XCVR_ZBDEMOD_PN_CODE_PN_MSB_MASK         (0xFFFF0000U)
#define XCVR_ZBDEMOD_PN_CODE_PN_MSB_SHIFT        (16U)
/*! PN_MSB - PN_MSB */
#define XCVR_ZBDEMOD_PN_CODE_PN_MSB(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_PN_CODE_PN_MSB_SHIFT)) & XCVR_ZBDEMOD_PN_CODE_PN_MSB_MASK)
/*! @} */

/*! @name SYNC_CTRL - 802.15.4 DEMOD SYMBOL SYNC CONTROL */
/*! @{ */

#define XCVR_ZBDEMOD_SYNC_CTRL_SYNC_PER_MASK     (0x7U)
#define XCVR_ZBDEMOD_SYNC_CTRL_SYNC_PER_SHIFT    (0U)
/*! SYNC_PER - Symbol Sync Tracking Period */
#define XCVR_ZBDEMOD_SYNC_CTRL_SYNC_PER(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_SYNC_CTRL_SYNC_PER_SHIFT)) & XCVR_ZBDEMOD_SYNC_CTRL_SYNC_PER_MASK)

#define XCVR_ZBDEMOD_SYNC_CTRL_TRACK_ENABLE_MASK (0x8U)
#define XCVR_ZBDEMOD_SYNC_CTRL_TRACK_ENABLE_SHIFT (3U)
/*! TRACK_ENABLE - TRACK_ENABLE
 *  0b0..symbol timing synchronization tracking disabled in Rx frontend
 *  0b1..symbol timing synchronization tracking enabled in Rx frontend (default)
 */
#define XCVR_ZBDEMOD_SYNC_CTRL_TRACK_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_SYNC_CTRL_TRACK_ENABLE_SHIFT)) & XCVR_ZBDEMOD_SYNC_CTRL_TRACK_ENABLE_MASK)

#define XCVR_ZBDEMOD_SYNC_CTRL_ZBPHYREG_CKEN_FW_OV_MASK (0x100U)
#define XCVR_ZBDEMOD_SYNC_CTRL_ZBPHYREG_CKEN_FW_OV_SHIFT (8U)
/*! ZBPHYREG_CKEN_FW_OV - Register clock SW override */
#define XCVR_ZBDEMOD_SYNC_CTRL_ZBPHYREG_CKEN_FW_OV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_SYNC_CTRL_ZBPHYREG_CKEN_FW_OV_SHIFT)) & XCVR_ZBDEMOD_SYNC_CTRL_ZBPHYREG_CKEN_FW_OV_MASK)
/*! @} */

/*! @name CCA_LQI_SRC - 802.15.4 CCA/LQI SOURCE */
/*! @{ */

#define XCVR_ZBDEMOD_CCA_LQI_SRC_CCA1_FROM_RX_DIG_MASK (0x1U)
#define XCVR_ZBDEMOD_CCA_LQI_SRC_CCA1_FROM_RX_DIG_SHIFT (0U)
/*! CCA1_FROM_RX_DIG - Selects the Source of CCA1 (Clear Channel Assessment Mode 1) Information Provided to the 802.15.4 Link Layer
 *  0b0..Use the CCA1 information computed internally in the 802.15.4 Demod
 *  0b1..Use the CCA1 information computed by the RX Digital
 */
#define XCVR_ZBDEMOD_CCA_LQI_SRC_CCA1_FROM_RX_DIG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA_LQI_SRC_CCA1_FROM_RX_DIG_SHIFT)) & XCVR_ZBDEMOD_CCA_LQI_SRC_CCA1_FROM_RX_DIG_MASK)

#define XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_FROM_RX_DIG_MASK (0x2U)
#define XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_FROM_RX_DIG_SHIFT (1U)
/*! LQI_FROM_RX_DIG - Selects the Source of LQI (Link Quality Indicator) Information Provided to the 802.15.4 Link Layer
 *  0b0..Use the LQI information computed internally in the 802.15.4 Demod
 *  0b1..Use the LQI information computed by the RX Digital
 */
#define XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_FROM_RX_DIG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_FROM_RX_DIG_SHIFT)) & XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_FROM_RX_DIG_MASK)

#define XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_START_AT_SFD_MASK (0x4U)
#define XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_START_AT_SFD_SHIFT (2U)
/*! LQI_START_AT_SFD - Select Start Point for LQI Computation
 *  0b0..Start LQI computation at Preamble Detection (similar to previous NXP 802.15.4 products)
 *  0b1..Start LQI computation at SFD (Start of Frame Delimiter) Detection
 */
#define XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_START_AT_SFD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_START_AT_SFD_SHIFT)) & XCVR_ZBDEMOD_CCA_LQI_SRC_LQI_START_AT_SFD_MASK)

#define XCVR_ZBDEMOD_CCA_LQI_SRC_ZBDEM_CCA_CLK_ON_MASK (0x8U)
#define XCVR_ZBDEMOD_CCA_LQI_SRC_ZBDEM_CCA_CLK_ON_SHIFT (3U)
/*! ZBDEM_CCA_CLK_ON - 802.15.4 Demodulator CCA Clock Enable */
#define XCVR_ZBDEMOD_CCA_LQI_SRC_ZBDEM_CCA_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA_LQI_SRC_ZBDEM_CCA_CLK_ON_SHIFT)) & XCVR_ZBDEMOD_CCA_LQI_SRC_ZBDEM_CCA_CLK_ON_MASK)
/*! @} */

/*! @name FAD_LPPS_THR - FAD CORRELATOR THRESHOLD */
/*! @{ */

#define XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_THR_MASK   (0xFFU)
#define XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_THR_SHIFT  (0U)
/*! FAD_THR - FAD_THR */
#define XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_THR(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_THR_SHIFT)) & XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_THR_MASK)

#define XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_FILL1_MASK (0x7F00U)
#define XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_FILL1_SHIFT (8U)
/*! FAD_FILL1 - Pre-detection buffer filling duration */
#define XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_FILL1(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_FILL1_SHIFT)) & XCVR_ZBDEMOD_FAD_LPPS_THR_FAD_FILL1_MASK)

#define XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_FILL_COUNT_MASK (0x7F0000U)
#define XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_FILL_COUNT_SHIFT (16U)
/*! LPPS_FILL_COUNT - Wait duration after lpps_lp_enable is de-asserted */
#define XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_FILL_COUNT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_FILL_COUNT_SHIFT)) & XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_FILL_COUNT_MASK)

#define XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_LP_EN_COUNT_MASK (0x7F000000U)
#define XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_LP_EN_COUNT_SHIFT (24U)
/*! LPPS_LP_EN_COUNT - LPPS_LP_EN high time */
#define XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_LP_EN_COUNT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_LP_EN_COUNT_SHIFT)) & XCVR_ZBDEMOD_FAD_LPPS_THR_LPPS_LP_EN_COUNT_MASK)
/*! @} */

/*! @name ZBDEM_AFC - 802.15.4 AFC STATUS */
/*! @{ */

#define XCVR_ZBDEMOD_ZBDEM_AFC_AFC_EN_MASK       (0x1U)
#define XCVR_ZBDEMOD_ZBDEM_AFC_AFC_EN_SHIFT      (0U)
/*! AFC_EN - AFC_EN
 *  0b0..AFC is disabled
 *  0b1..AFC is enabled
 */
#define XCVR_ZBDEMOD_ZBDEM_AFC_AFC_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_ZBDEM_AFC_AFC_EN_SHIFT)) & XCVR_ZBDEMOD_ZBDEM_AFC_AFC_EN_MASK)

#define XCVR_ZBDEMOD_ZBDEM_AFC_DCD_EN_MASK       (0x2U)
#define XCVR_ZBDEMOD_ZBDEM_AFC_DCD_EN_SHIFT      (1U)
/*! DCD_EN - DCD_EN
 *  0b0..NCD Mode (default)
 *  0b1..DCD Mode
 */
#define XCVR_ZBDEMOD_ZBDEM_AFC_DCD_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_ZBDEM_AFC_DCD_EN_SHIFT)) & XCVR_ZBDEMOD_ZBDEM_AFC_DCD_EN_MASK)

#define XCVR_ZBDEMOD_ZBDEM_AFC_AFC_OUT_MASK      (0x1F00U)
#define XCVR_ZBDEMOD_ZBDEM_AFC_AFC_OUT_SHIFT     (8U)
/*! AFC_OUT - AFC_OUT */
#define XCVR_ZBDEMOD_ZBDEM_AFC_AFC_OUT(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_ZBDEM_AFC_AFC_OUT_SHIFT)) & XCVR_ZBDEMOD_ZBDEM_AFC_AFC_OUT_MASK)
/*! @} */

/*! @name CCA2_CTRL - CCA MODE 2 CONTROL REGISTER */
/*! @{ */

#define XCVR_ZBDEMOD_CCA2_CTRL_CCA2_INTERVAL_MASK (0x3U)
#define XCVR_ZBDEMOD_CCA2_CTRL_CCA2_INTERVAL_SHIFT (0U)
/*! CCA2_INTERVAL - CCA Mode 2 Measurement Window Duration
 *  0b00..64 us
 *  0b01..128 us
 *  0b10..256 us
 *  0b11..512 us
 */
#define XCVR_ZBDEMOD_CCA2_CTRL_CCA2_INTERVAL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_CTRL_CCA2_INTERVAL_SHIFT)) & XCVR_ZBDEMOD_CCA2_CTRL_CCA2_INTERVAL_MASK)

#define XCVR_ZBDEMOD_CCA2_CTRL_USE_DEMOD_CCA2_MASK (0x4U)
#define XCVR_ZBDEMOD_CCA2_CTRL_USE_DEMOD_CCA2_SHIFT (2U)
/*! USE_DEMOD_CCA2 - Selects CCA Mode 2 Computation Engine
 *  0b0..Use standalone (new) CCA Mode 2 Engine, decoupled from demodulator
 *  0b1..Use 802.15.4 demodulator-based (legacy) CCA Mode 2 Engine (default)
 */
#define XCVR_ZBDEMOD_CCA2_CTRL_USE_DEMOD_CCA2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_CTRL_USE_DEMOD_CCA2_SHIFT)) & XCVR_ZBDEMOD_CCA2_CTRL_USE_DEMOD_CCA2_MASK)

#define XCVR_ZBDEMOD_CCA2_CTRL_CCA2_REF_SEQ_MASK (0xFF00U)
#define XCVR_ZBDEMOD_CCA2_CTRL_CCA2_REF_SEQ_SHIFT (8U)
/*! CCA2_REF_SEQ - CCA Mode 2 Sequence Address */
#define XCVR_ZBDEMOD_CCA2_CTRL_CCA2_REF_SEQ(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_CTRL_CCA2_REF_SEQ_SHIFT)) & XCVR_ZBDEMOD_CCA2_CTRL_CCA2_REF_SEQ_MASK)
/*! @} */

/*! @name CCA2_THRESH - CCA MODE 2 CONTROL REGISTER */
/*! @{ */

#define XCVR_ZBDEMOD_CCA2_THRESH_CCA2_CNT_THRESH_MASK (0x3FFU)
#define XCVR_ZBDEMOD_CCA2_THRESH_CCA2_CNT_THRESH_SHIFT (0U)
/*! CCA2_CNT_THRESH - CCA Mode 2 Count Threshold */
#define XCVR_ZBDEMOD_CCA2_THRESH_CCA2_CNT_THRESH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_THRESH_CCA2_CNT_THRESH_SHIFT)) & XCVR_ZBDEMOD_CCA2_THRESH_CCA2_CNT_THRESH_MASK)

#define XCVR_ZBDEMOD_CCA2_THRESH_CCA2_SYM_THRESH_MASK (0x3FF0000U)
#define XCVR_ZBDEMOD_CCA2_THRESH_CCA2_SYM_THRESH_SHIFT (16U)
/*! CCA2_SYM_THRESH - CCA Mode 2 Symbol Threshold */
#define XCVR_ZBDEMOD_CCA2_THRESH_CCA2_SYM_THRESH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_THRESH_CCA2_SYM_THRESH_SHIFT)) & XCVR_ZBDEMOD_CCA2_THRESH_CCA2_SYM_THRESH_MASK)
/*! @} */

/*! @name CCA2_STATUS - CCA MODE 2 STATUS REGISTER */
/*! @{ */

#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_MAX_MASK (0x3FFU)
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_MAX_SHIFT (0U)
/*! CCA2_CNT_MAX - CCA Mode 2 Maximum Count */
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_MAX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_MAX_SHIFT)) & XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_MAX_MASK)

#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_COMPLETE_MASK (0x400U)
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_COMPLETE_SHIFT (10U)
/*! CCA2_COMPLETE - CCA Mode 2 Measurement Complete */
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_COMPLETE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_STATUS_CCA2_COMPLETE_SHIFT)) & XCVR_ZBDEMOD_CCA2_STATUS_CCA2_COMPLETE_MASK)

#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CHANNEL_STATE_MASK (0x800U)
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CHANNEL_STATE_SHIFT (11U)
/*! CCA2_CHANNEL_STATE - CCA Mode 2 Channel State */
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CHANNEL_STATE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CHANNEL_STATE_SHIFT)) & XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CHANNEL_STATE_MASK)

#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_SYM_MASK (0x3FF0000U)
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_SYM_SHIFT (16U)
/*! CCA2_CNT_SYM - CCA Mode 2 Repetition Sequence Addresses Count */
#define XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_SYM(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_SYM_SHIFT)) & XCVR_ZBDEMOD_CCA2_STATUS_CCA2_CNT_SYM_MASK)
/*! @} */

/*! @name CORR_CTRL2 - 802.15.4 DEMOD CORRELATOR CONTROL2 */
/*! @{ */

#define XCVR_ZBDEMOD_CORR_CTRL2_EARLY_PD_THRESH_MASK (0xFFU)
#define XCVR_ZBDEMOD_CORR_CTRL2_EARLY_PD_THRESH_SHIFT (0U)
/*! EARLY_PD_THRESH - EARLY_PD_THRESH */
#define XCVR_ZBDEMOD_CORR_CTRL2_EARLY_PD_THRESH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEMOD_CORR_CTRL2_EARLY_PD_THRESH_SHIFT)) & XCVR_ZBDEMOD_CORR_CTRL2_EARLY_PD_THRESH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_ZBDEMOD_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_ZBDEMOD_Peripheral_Access_Layer */


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


#endif  /* PERI_XCVR_ZBDEMOD_H_ */

