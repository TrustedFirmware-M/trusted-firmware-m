/*
** ###################################################################
**     Processors:          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TSI
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
 * @file PERI_TSI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TSI
 *
 * CMSIS Peripheral Access Layer for TSI
 */

#if !defined(PERI_TSI_H_)
#define PERI_TSI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
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
   -- TSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Peripheral_Access_Layer TSI Peripheral Access Layer
 * @{
 */

/** TSI - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __IO uint32_t CONFIG_MUTUAL;                     /**< TSI CONFIG register (TSI_CONFIG) for mutual-capacitor (CONFIG_MUTUAL), offset: 0x0 */
    __IO uint32_t CONFIG;                            /**< TSI CONFIG Register (TSI_CONFIG) for self-capacitor, offset: 0x0 */
  };
  __IO uint32_t TSHD;                              /**< TSI Threshold Register, offset: 0x4 */
  __IO uint32_t GENCS;                             /**< TSI General Control and Status Register, offset: 0x8 */
  __IO uint32_t MUL;                               /**< TSI Mutual-cap Register, offset: 0xC */
  __IO uint32_t SINC;                              /**< TSI SINC Filter Register, offset: 0x10 */
  __IO uint32_t SSC0;                              /**< TSI SSC Register 0, offset: 0x14 */
  __IO uint32_t SSC1;                              /**< TSI SSC Register 1, offset: 0x18 */
  __IO uint32_t SSC2;                              /**< TSI SSC Register 2, offset: 0x1C */
  __IO uint32_t BASELINE;                          /**< TSI Baseline Register, offset: 0x20 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SHIELD;                            /**< TSI Shield Register, offset: 0x28 */
  __IO uint32_t SELF_SEL_31_0;                     /**< Self-cap mode channels selection(CH31~CH0), offset: 0x2C */
  __IO uint32_t SELF_SEL_63_32;                    /**< Self-cap mode channels selection(CH63~CH32), offset: 0x30 */
  __IO uint32_t SELF_SEL_69_64;                    /**< Self-cap mode channels selection(CH69~CH64), offset: 0x34 */
  __IO uint32_t SHIELD_SEL_31_0;                   /**< Shield mode channels selection(CH31~CH0), offset: 0x38 */
  __IO uint32_t SHIELD_SEL_63_32;                  /**< Shield mode channels selection(CH63~CH32), offset: 0x3C */
  __IO uint32_t SHIELD_SEL_69_64;                  /**< Shield mode channels selection(CH69~CH64), offset: 0x40 */
  __IO uint32_t MUTUAL_TX_SEL_31_0;                /**< Mutual TX mode channels selection(CH31~CH0), offset: 0x44 */
  __IO uint32_t MUTUAL_TX_SEL_63_32;               /**< Mutual TX mode channels selection(CH63~CH32), offset: 0x48 */
  __IO uint32_t MUTUAL_TX_SEL_69_64;               /**< Mutual TX mode channels selection(CH69~CH64), offset: 0x4C */
  __IO uint32_t MUTUAL_RX_SEL_31_0;                /**< Mutual RX mode channels selection(CH31~CH0), offset: 0x50 */
  __IO uint32_t MUTUAL_RX_SEL_63_32;               /**< Mutual RX mode channels selection(CH63~CH32), offset: 0x54 */
  __IO uint32_t MUTUAL_RX_SEL_69_64;               /**< Mutual RX mode channels selection (CH69~CH64), offset: 0x58 */
       uint8_t RESERVED_1[164];
  __IO uint32_t DATA;                              /**< TSI Data and Status Register, offset: 0x100 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MISC;                              /**< TSI Miscellaneous Register, offset: 0x108 */
  __IO uint32_t TRIG;                              /**< TSI AUTO TRIG Register, offset: 0x10C */
  __IO uint32_t TEST;                              /**< TSI TEST Register, offset: 0x110 */
} TSI_Type;

/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Register_Masks TSI Register Masks
 * @{
 */

/*! @name CONFIG_MUTUAL - TSI CONFIG register (TSI_CONFIG) for mutual-capacitor (CONFIG_MUTUAL) */
/*! @{ */

#define TSI_CONFIG_MUTUAL_MODE_MASK              (0x1U)
#define TSI_CONFIG_MUTUAL_MODE_SHIFT             (0U)
/*! MODE - MODE
 *  0b0..Self-cap mode, this address is TSI_CONFIG for self-cap
 *  0b1..Mutual-cap mode, this address is TSI_CONFIG for mutual-cap
 */
#define TSI_CONFIG_MUTUAL_MODE(x)                (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_MODE_SHIFT)) & TSI_CONFIG_MUTUAL_MODE_MASK)

#define TSI_CONFIG_MUTUAL_M_NMIRROR_MASK         (0x6U)
#define TSI_CONFIG_MUTUAL_M_NMIRROR_SHIFT        (1U)
/*! M_NMIRROR - M_NMIRROR
 *  0b00..m=1
 *  0b01..m=2
 *  0b10..m=3
 *  0b11..m=4 (default)
 */
#define TSI_CONFIG_MUTUAL_M_NMIRROR(x)           (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_NMIRROR_SHIFT)) & TSI_CONFIG_MUTUAL_M_NMIRROR_MASK)

#define TSI_CONFIG_MUTUAL_M_PMIRRORR_MASK        (0x18U)
#define TSI_CONFIG_MUTUAL_M_PMIRRORR_SHIFT       (3U)
/*! M_PMIRRORR - M_PMIRRORR
 *  0b00..m=1
 *  0b01..m=2
 *  0b10..m=3
 *  0b11..m=4 (default)
 */
#define TSI_CONFIG_MUTUAL_M_PMIRRORR(x)          (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_PMIRRORR_SHIFT)) & TSI_CONFIG_MUTUAL_M_PMIRRORR_MASK)

#define TSI_CONFIG_MUTUAL_M_PMIRRORL_MASK        (0xE0U)
#define TSI_CONFIG_MUTUAL_M_PMIRRORL_SHIFT       (5U)
/*! M_PMIRRORL - M_PMIRRORL
 *  0b000..m=4
 *  0b001..m=8
 *  0b010..m=12
 *  0b011..m=16 (default)
 *  0b100..m=20
 *  0b101..m=24
 *  0b110..m=28
 *  0b111..m=32
 */
#define TSI_CONFIG_MUTUAL_M_PMIRRORL(x)          (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_PMIRRORL_SHIFT)) & TSI_CONFIG_MUTUAL_M_PMIRRORL_MASK)

#define TSI_CONFIG_MUTUAL_M_CNT_EN_MASK          (0x10000U)
#define TSI_CONFIG_MUTUAL_M_CNT_EN_SHIFT         (16U)
/*! M_CNT_EN - M_CNT_EN
 *  0b0..Disable, the counter works in all scan process
 *  0b1..Enable, the counter only works when the capacitor does the integration
 */
#define TSI_CONFIG_MUTUAL_M_CNT_EN(x)            (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_CNT_EN_SHIFT)) & TSI_CONFIG_MUTUAL_M_CNT_EN_MASK)

#define TSI_CONFIG_MUTUAL_M_TX_PD_EN_MASK        (0x20000U)
#define TSI_CONFIG_MUTUAL_M_TX_PD_EN_SHIFT       (17U)
/*! M_TX_PD_EN - M_TX_PD_EN
 *  0b0..Disable
 *  0b1..Enable (default)
 */
#define TSI_CONFIG_MUTUAL_M_TX_PD_EN(x)          (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_TX_PD_EN_SHIFT)) & TSI_CONFIG_MUTUAL_M_TX_PD_EN_MASK)

#define TSI_CONFIG_MUTUAL_M_SEN_BOOST_MASK       (0x7C0000U)
#define TSI_CONFIG_MUTUAL_M_SEN_BOOST_SHIFT      (18U)
/*! M_SEN_BOOST - M_SEN_BOOST
 *  0b00000..0 u
 *  0b00001..2 u
 *  0b00010..4 u
 *  0b00011..6 u
 *  0b00100..8 u
 *  0b00101..10 u
 *  0b00110..12 u
 *  0b00111..14 u
 *  0b01000..16 u
 *  0b01001..18 u
 *  0b01010..20 u
 *  0b01011..22 u
 *  0b01100..24 u
 *  0b01101..26 u
 *  0b01110..28 u
 *  0b01111..30 u
 *  0b10000..32 u
 *  0b10001..34 u
 *  0b10010..36 u
 *  0b10011..38 u
 *  0b10100..40 u
 *  0b10101..42 u
 *  0b10110..44 u
 *  0b10111..46 u
 *  0b11000..48 u
 *  0b11001..50 u
 *  0b11010..52 u
 *  0b11011..54 u
 *  0b11100..56 u
 *  0b11101..58 u
 *  0b11110..60 u
 *  0b11111..62 u
 */
#define TSI_CONFIG_MUTUAL_M_SEN_BOOST(x)         (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_SEN_BOOST_SHIFT)) & TSI_CONFIG_MUTUAL_M_SEN_BOOST_MASK)

#define TSI_CONFIG_MUTUAL_PRE_CHRG_MODE_MASK     (0x800000U)
#define TSI_CONFIG_MUTUAL_PRE_CHRG_MODE_SHIFT    (23U)
/*! PRE_CHRG_MODE - PRE_CHRG_MODE
 *  0b0..Mode 0
 *  0b1..Mode 1
 */
#define TSI_CONFIG_MUTUAL_PRE_CHRG_MODE(x)       (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_PRE_CHRG_MODE_SHIFT)) & TSI_CONFIG_MUTUAL_PRE_CHRG_MODE_MASK)

#define TSI_CONFIG_MUTUAL_M_PRE_RES_MASK         (0x1C000000U)
#define TSI_CONFIG_MUTUAL_M_PRE_RES_SHIFT        (26U)
/*! M_PRE_RES - M_PRE_RES
 *  0b000..1 kohm
 *  0b001..2 kohm
 *  0b010..3 kohm
 *  0b011..4 kohm
 *  0b100..5 kohm
 *  0b101..6 kohm
 *  0b110..7 kohm
 *  0b111..8 kohm
 */
#define TSI_CONFIG_MUTUAL_M_PRE_RES(x)           (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_PRE_RES_SHIFT)) & TSI_CONFIG_MUTUAL_M_PRE_RES_MASK)

#define TSI_CONFIG_MUTUAL_M_PRE_CURRENT_MASK     (0xE0000000U)
#define TSI_CONFIG_MUTUAL_M_PRE_CURRENT_SHIFT    (29U)
/*! M_PRE_CURRENT - M_PRE_CURRENT
 *  0b000..1 uA
 *  0b001..2 uA
 *  0b010..3 uA
 *  0b011..4 uA
 *  0b100..5 uA
 *  0b101..6 uA
 *  0b110..7 uA
 *  0b111..8 uA
 */
#define TSI_CONFIG_MUTUAL_M_PRE_CURRENT(x)       (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_PRE_CURRENT_SHIFT)) & TSI_CONFIG_MUTUAL_M_PRE_CURRENT_MASK)
/*! @} */

/*! @name CONFIG - TSI CONFIG Register (TSI_CONFIG) for self-capacitor */
/*! @{ */

#define TSI_CONFIG_MODE_MASK                     (0x1U)
#define TSI_CONFIG_MODE_SHIFT                    (0U)
/*! MODE - MODE
 *  0b0..Self-cap mode, this address is TSI_SEL_CONFIG
 *  0b1..Mutual-cap mode, this address is TSI_MUL_CONFIG
 */
#define TSI_CONFIG_MODE(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MODE_SHIFT)) & TSI_CONFIG_MODE_MASK)

#define TSI_CONFIG_FILTER_TRIM_MASK              (0x30U)
#define TSI_CONFIG_FILTER_TRIM_SHIFT             (4U)
/*! FILTER_TRIM - FILTER_TRIM
 *  0b00..filter bypass
 *  0b01..5.3ns
 *  0b10..21.1ns
 *  0b11..25ns
 */
#define TSI_CONFIG_FILTER_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_FILTER_TRIM_SHIFT)) & TSI_CONFIG_FILTER_TRIM_MASK)

#define TSI_CONFIG_SELF_BYPASS_FLT_MASK          (0x40U)
#define TSI_CONFIG_SELF_BYPASS_FLT_SHIFT         (6U)
/*! SELF_BYPASS_FLT - self_bypass_flt
 *  0b0..LPF is not bypassed (default)
 *  0b1..LPF is bypassed
 */
#define TSI_CONFIG_SELF_BYPASS_FLT(x)            (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_SELF_BYPASS_FLT_SHIFT)) & TSI_CONFIG_SELF_BYPASS_FLT_MASK)

#define TSI_CONFIG_XIN_SCALE_DOWN_TRIM_MASK      (0xF00U)
#define TSI_CONFIG_XIN_SCALE_DOWN_TRIM_SHIFT     (8U)
/*! XIN_SCALE_DOWN_TRIM - xin_scale_down_trim
 *  0b0000..1 (default)
 *  0b0001..1/2
 *  0b0010..1/3
 *  0b0011..1/4
 *  0b0100..1/5
 *  0b0101..1/6
 *  0b0110..1/7
 *  0b0111..1/8
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define TSI_CONFIG_XIN_SCALE_DOWN_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_XIN_SCALE_DOWN_TRIM_SHIFT)) & TSI_CONFIG_XIN_SCALE_DOWN_TRIM_MASK)

#define TSI_CONFIG_XIN_SCALE_DOWN_MASK           (0xF000U)
#define TSI_CONFIG_XIN_SCALE_DOWN_SHIFT          (12U)
/*! XIN_SCALE_DOWN - xin_scale_down
 *  0b0000..1 (default)
 *  0b0001..1/2
 *  0b0010..1/3
 *  0b0011..1/4
 *  0b0100..1/5
 *  0b0101..1/6
 *  0b0110..1/7
 *  0b0111..1/8
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define TSI_CONFIG_XIN_SCALE_DOWN(x)             (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_XIN_SCALE_DOWN_SHIFT)) & TSI_CONFIG_XIN_SCALE_DOWN_MASK)

#define TSI_CONFIG_SELF_BOOST_SCALE_MASK         (0x70000U)
#define TSI_CONFIG_SELF_BOOST_SCALE_SHIFT        (16U)
/*! SELF_BOOST_SCALE - self_boost_scale
 *  0b000..500 nA (default)
 *  0b001..1 uA
 *  0b010..1.5 uA
 *  0b011..2 uA
 *  0b100..2.5 uA
 *  0b101..3 uA
 *  0b110..3.5 uA
 *  0b111..4 uA
 */
#define TSI_CONFIG_SELF_BOOST_SCALE(x)           (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_SELF_BOOST_SCALE_SHIFT)) & TSI_CONFIG_SELF_BOOST_SCALE_MASK)

#define TSI_CONFIG_S_NOISE_MASK                  (0x80000U)
#define TSI_CONFIG_S_NOISE_SHIFT                 (19U)
/*! S_NOISE - S_NOISE
 *  0b0..Noise cancellation off (default)
 *  0b1..Noise cancellation on
 */
#define TSI_CONFIG_S_NOISE(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_NOISE_SHIFT)) & TSI_CONFIG_S_NOISE_MASK)

#define TSI_CONFIG_S_XCH_MASK                    (0x700000U)
#define TSI_CONFIG_S_XCH_SHIFT                   (20U)
/*! S_XCH - S_XCH
 *  0b000..1/16 (default)
 *  0b001..1/8
 *  0b010..1/4
 *  0b011..1/2
 *  0b100..1/1
 *  0b101..2/1
 *  0b110..4/1
 *  0b111..8/1
 */
#define TSI_CONFIG_S_XCH(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_XCH_SHIFT)) & TSI_CONFIG_S_XCH_MASK)

#define TSI_CONFIG_S_XIN_MASK                    (0x800000U)
#define TSI_CONFIG_S_XIN_SHIFT                   (23U)
/*! S_XIN - S_XIN
 *  0b0..1/8
 *  0b1..1/4 (default)
 */
#define TSI_CONFIG_S_XIN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_XIN_SHIFT)) & TSI_CONFIG_S_XIN_MASK)

#define TSI_CONFIG_S_SEN_MASK                    (0x8000000U)
#define TSI_CONFIG_S_SEN_SHIFT                   (27U)
/*! S_SEN - S_SEN
 *  0b0..Sensitivity boost off (default)
 *  0b1..Sensitivity boost on
 */
#define TSI_CONFIG_S_SEN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_SEN_SHIFT)) & TSI_CONFIG_S_SEN_MASK)

#define TSI_CONFIG_S_XDN_MASK                    (0x70000000U)
#define TSI_CONFIG_S_XDN_SHIFT                   (28U)
/*! S_XDN - S_XDN
 *  0b000..1/16 (default)
 *  0b001..1/8
 *  0b010..1/4
 *  0b011..1/2
 *  0b100..NA
 *  0b101..NA
 *  0b110..NA
 *  0b111..NA
 */
#define TSI_CONFIG_S_XDN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_XDN_SHIFT)) & TSI_CONFIG_S_XDN_MASK)

#define TSI_CONFIG_SELF_BOOST_MODE_MASK          (0x80000000U)
#define TSI_CONFIG_SELF_BOOST_MODE_SHIFT         (31U)
/*! SELF_BOOST_MODE - self_boost_mode
 *  0b0..Cap boost mode (default)
 *  0b1..Current boost mode
 */
#define TSI_CONFIG_SELF_BOOST_MODE(x)            (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_SELF_BOOST_MODE_SHIFT)) & TSI_CONFIG_SELF_BOOST_MODE_MASK)
/*! @} */

/*! @name TSHD - TSI Threshold Register */
/*! @{ */

#define TSI_TSHD_THRESL_MASK                     (0xFFFFU)
#define TSI_TSHD_THRESL_SHIFT                    (0U)
/*! THRESL - TSI Wakeup Channel Low-Threshold */
#define TSI_TSHD_THRESL(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_TSHD_THRESL_SHIFT)) & TSI_TSHD_THRESL_MASK)

#define TSI_TSHD_THRESH_MASK                     (0xFFFF0000U)
#define TSI_TSHD_THRESH_SHIFT                    (16U)
/*! THRESH - TSI Wakeup Channel High-threshold */
#define TSI_TSHD_THRESH(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_TSHD_THRESH_SHIFT)) & TSI_TSHD_THRESH_MASK)
/*! @} */

/*! @name GENCS - TSI General Control and Status Register */
/*! @{ */

#define TSI_GENCS_DMAEN_EOS_MASK                 (0x1U)
#define TSI_GENCS_DMAEN_EOS_SHIFT                (0U)
/*! DMAEN_EOS - In-progress DMA Transfer Request Enable
 *  0b0..Disable DMA request at End of Scan event
 *  0b1..Enable DMA request at End of event
 */
#define TSI_GENCS_DMAEN_EOS(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DMAEN_EOS_SHIFT)) & TSI_GENCS_DMAEN_EOS_MASK)

#define TSI_GENCS_DMAEN_OUTRG_MASK               (0x4U)
#define TSI_GENCS_DMAEN_OUTRG_SHIFT              (2U)
/*! DMAEN_OUTRG - Out of Range DMA Transfer Request Enable
 *  0b0..Disable DMA request at Out-of-Range event
 *  0b1..Enable DMA request at Out-of-Range event
 */
#define TSI_GENCS_DMAEN_OUTRG(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DMAEN_OUTRG_SHIFT)) & TSI_GENCS_DMAEN_OUTRG_MASK)

#define TSI_GENCS_STM_MASK                       (0x8U)
#define TSI_GENCS_STM_SHIFT                      (3U)
/*! STM - Scan Trigger Mode
 *  0b0..Software trigger scan
 *  0b1..Hardware trigger scan
 */
#define TSI_GENCS_STM(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_STM_SHIFT)) & TSI_GENCS_STM_MASK)

#define TSI_GENCS_TSIEN_MASK                     (0x20U)
#define TSI_GENCS_TSIEN_SHIFT                    (5U)
/*! TSIEN - Touch Sensing Input Module Enable
 *  0b0..TSI module disabled
 *  0b1..TSI module enabled
 */
#define TSI_GENCS_TSIEN(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_TSIEN_SHIFT)) & TSI_GENCS_TSIEN_MASK)

#define TSI_GENCS_CLK_SEL_MASK                   (0x40U)
#define TSI_GENCS_CLK_SEL_SHIFT                  (6U)
/*! CLK_SEL - KHz clock selection
 *  0b0..Select 16K clock to use
 *  0b1..Select 32K clock to use
 */
#define TSI_GENCS_CLK_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_CLK_SEL_SHIFT)) & TSI_GENCS_CLK_SEL_MASK)

#define TSI_GENCS_SWTS_MASK                      (0x80U)
#define TSI_GENCS_SWTS_SHIFT                     (7U)
/*! SWTS - Software Trigger Start
 *  0b0..No effect
 *  0b1..Takes effect
 */
#define TSI_GENCS_SWTS(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_SWTS_SHIFT)) & TSI_GENCS_SWTS_MASK)

#define TSI_GENCS_TSIEN_DPD_MASK                 (0x100U)
#define TSI_GENCS_TSIEN_DPD_SHIFT                (8U)
/*! TSIEN_DPD - Enable of 3v domain logic in this IP
 *  0b0..3v domain logic is disabled
 *  0b1..3v domain logic is enabled
 */
#define TSI_GENCS_TSIEN_DPD(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_TSIEN_DPD_SHIFT)) & TSI_GENCS_TSIEN_DPD_MASK)

#define TSI_GENCS_DVOLT_MASK                     (0xF000U)
#define TSI_GENCS_DVOLT_SHIFT                    (12U)
/*! DVOLT - DVOLT
 *  0b0000..Vm=0.6 V, Vp=1.73 V
 *  0b0001..Vm=0.6 V, Vp=1.82 V
 *  0b0010..Vm=0.6 V, Vp=1.89 V
 *  0b0011..Vm=0.6 V, Vp=1.98 V
 *  0b0100..Vm=0.6 V, Vp=2.06 V
 *  0b0101..Vm=0.6 V, Vp=2.14 V
 *  0b0110..Vm=0.6 V, Vp=2.23 V
 *  0b0111..Vm=0.6 V, Vp=2.31 V
 *  0b1000..Vm=0.6 V, Vp=2.39 V
 *  0b1001..Vm=0.6 V, Vp=2.47 V
 *  0b1010..Vm=0.6 V, Vp=2.56 V
 *  0b1011..Vm=0.6 V, Vp=2.64 V
 *  0b1100..Vm=0.6 V, Vp=2.72 V
 *  0b1101..Vm=0.6 V, Vp=2.81 V
 *  0b1110..Vm=0.6 V, Vp=2.88 V
 *  0b1111..Vm=0.6 V, Vp=2.97 V
 */
#define TSI_GENCS_DVOLT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DVOLT_SHIFT)) & TSI_GENCS_DVOLT_MASK)

#define TSI_GENCS_DEBOUNCE_COUNTER_CONFIGURED_MASK (0x1F0000U)
#define TSI_GENCS_DEBOUNCE_COUNTER_CONFIGURED_SHIFT (16U)
/*! DEBOUNCE_COUNTER_CONFIGURED - DEBOUNCE
 *  0b00000..1 out of range event can generate interrupt
 *  0b00001..2 out of range events can generate interrupt
 *  0b00010..3 out of range events can generate interrupt
 *  0b00011..4 out of range events can generate interrupt
 *  0b00100..5 out of range events can generate interrupt
 *  0b00101..6 out of range events can generate interrupt
 *  0b00110..7 out of range events can generate interrupt
 *  0b00111..8 out of range events can generate interrupt
 *  0b01000..9 out of range events can generate interrupt
 *  0b01001..10 out of range events can generate interrupt
 *  0b01010..11 out of range events can generate interrupt
 *  0b01011..12 out of range events can generate interrupt
 *  0b01100..13 out of range events can generate interrupt
 *  0b01101..14 out of range events can generate interrupt
 *  0b01110..15 out of range events can generate interrupt
 *  0b01111..16 out of range events can generate interrupt
 *  0b10000..17 out of range events can generate interrupt
 *  0b10001..18 out of range events can generate interrupt
 *  0b10010..19 out of range events can generate interrupt
 *  0b10011..20 out of range events can generate interrupt
 *  0b10100..21 out of range events can generate interrupt
 *  0b10101..22 out of range events can generate interrupt
 *  0b10110..23 out of range events can generate interrupt
 *  0b10111..24 out of range events can generate interrupt
 *  0b11000..25 out of range events can generate interrupt
 *  0b11001..26 out of range events can generate interrupt
 *  0b11010..27 out of range events can generate interrupt
 *  0b11011..28 out of range events can generate interrupt
 *  0b11100..29 out of range events can generate interrupt
 *  0b11101..30 out of range events can generate interrupt
 *  0b11110..31 out of range events can generate interrupt
 *  0b11111..32 out of range events can generate interrupt
 */
#define TSI_GENCS_DEBOUNCE_COUNTER_CONFIGURED(x) (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DEBOUNCE_COUNTER_CONFIGURED_SHIFT)) & TSI_GENCS_DEBOUNCE_COUNTER_CONFIGURED_MASK)

#define TSI_GENCS_ESOR_MASK                      (0x8000000U)
#define TSI_GENCS_ESOR_SHIFT                     (27U)
/*! ESOR - End of Scan Interrupt enable.
 *  0b0..End of Scan interrupt is disable
 *  0b1..End of Scan interrupt is enabled
 */
#define TSI_GENCS_ESOR(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_ESOR_SHIFT)) & TSI_GENCS_ESOR_MASK)

#define TSI_GENCS_OUTRG_EN_MASK                  (0x40000000U)
#define TSI_GENCS_OUTRG_EN_SHIFT                 (30U)
/*! OUTRG_EN - Out-of-range interrupt enable.
 *  0b0..Out-of-range interrupt is disable
 *  0b1..Out-of-range interrupt is enabled
 */
#define TSI_GENCS_OUTRG_EN(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_OUTRG_EN_SHIFT)) & TSI_GENCS_OUTRG_EN_MASK)
/*! @} */

/*! @name MUL - TSI Mutual-cap Register */
/*! @{ */

#define TSI_MUL_M_VPRE_CHOOSE_MASK               (0x1U)
#define TSI_MUL_M_VPRE_CHOOSE_SHIFT              (0U)
/*! M_VPRE_CHOOSE - M_VPRE_CHOOSE
 *  0b0..Internal 1.2 V voltage (default)
 *  0b1..External 1.2 V voltage from PMC
 */
#define TSI_MUL_M_VPRE_CHOOSE(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_VPRE_CHOOSE_SHIFT)) & TSI_MUL_M_VPRE_CHOOSE_MASK)

#define TSI_MUL_M_MODE_MASK                      (0x6U)
#define TSI_MUL_M_MODE_SHIFT                     (1U)
/*! M_MODE - M_MODE
 *  0b00..Sense both pos and neg side
 *  0b01..Sense pos side only
 *  0b10..Sense neg side only
 *  0b11..Not allowed
 */
#define TSI_MUL_M_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_MODE_SHIFT)) & TSI_MUL_M_MODE_MASK)

#define TSI_MUL_M_TRIM_CAP_MASK                  (0x18U)
#define TSI_MUL_M_TRIM_CAP_SHIFT                 (3U)
/*! M_TRIM_CAP - M_TRIM_CAP
 *  0b00..0 pF (default)
 *  0b01..10 pF
 *  0b10..10 pF
 *  0b11..20 pF
 */
#define TSI_MUL_M_TRIM_CAP(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_TRIM_CAP_SHIFT)) & TSI_MUL_M_TRIM_CAP_MASK)

#define TSI_MUL_M_TRIM_USED_MASK                 (0xFFFF0000U)
#define TSI_MUL_M_TRIM_USED_SHIFT                (16U)
/*! M_TRIM_USED - Not use, just reserved */
#define TSI_MUL_M_TRIM_USED(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_TRIM_USED_SHIFT)) & TSI_MUL_M_TRIM_USED_MASK)
/*! @} */

/*! @name SINC - TSI SINC Filter Register */
/*! @{ */

#define TSI_SINC_SSC_CONTROL_OUT_MASK            (0x1U)
#define TSI_SINC_SSC_CONTROL_OUT_SHIFT           (0U)
/*! SSC_CONTROL_OUT - SSC_CONTROL_OUT
 *  0b0..SSC output value is 0
 *  0b1..SSC output value is 1
 */
#define TSI_SINC_SSC_CONTROL_OUT(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SSC_CONTROL_OUT_SHIFT)) & TSI_SINC_SSC_CONTROL_OUT_MASK)

#define TSI_SINC_SINC_VALID_MASK                 (0x2U)
#define TSI_SINC_SINC_VALID_SHIFT                (1U)
/*! SINC_VALID - SINC_VALID
 *  0b0..SINC filter is disabled
 *  0b1..SINC filter is enabled
 */
#define TSI_SINC_SINC_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_VALID_SHIFT)) & TSI_SINC_SINC_VALID_MASK)

#define TSI_SINC_SINC_OVERFLOW_FLAG_MASK         (0x4U)
#define TSI_SINC_SINC_OVERFLOW_FLAG_SHIFT        (2U)
/*! SINC_OVERFLOW_FLAG - SINC_OVERFLOW_FLAG
 *  0b0..The counter result has no overflow occurrence in the last scan process
 *  0b1..The counter result has an overflow occurrence in the last scan process
 */
#define TSI_SINC_SINC_OVERFLOW_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_OVERFLOW_FLAG_SHIFT)) & TSI_SINC_SINC_OVERFLOW_FLAG_MASK)

#define TSI_SINC_SWITCH_ENABLE_MASK              (0x8U)
#define TSI_SINC_SWITCH_ENABLE_SHIFT             (3U)
/*! SWITCH_ENABLE - SWITCH_ENABLE
 *  0b0..SSC function is disabled
 *  0b1..SSC function is enabled
 */
#define TSI_SINC_SWITCH_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SWITCH_ENABLE_SHIFT)) & TSI_SINC_SWITCH_ENABLE_MASK)

#define TSI_SINC_SINC_DECIMATION_MASK            (0x1F0000U)
#define TSI_SINC_SINC_DECIMATION_SHIFT           (16U)
/*! SINC_DECIMATION - SINC_DECIMATION
 *  0b00000..The TSI_DATA[TSICNT] bits is the counter value of 1 trigger period
 *  0b00001..The TSI_DATA[TSICNT] bits is the counter value of 2 trigger periods
 *  0b00010..The TSI_DATA[TSICNT] bits is the counter value of 3 trigger periods
 *  0b00011..The TSI_DATA[TSICNT] bits is the counter value of 4 trigger periods
 *  0b00100..The TSI_DATA[TSICNT] bits is the counter value of 5 trigger periods
 *  0b00101..The TSI_DATA[TSICNT] bits is the counter value of 6 trigger periods
 *  0b00110..The TSI_DATA[TSICNT] bits is the counter value of 7 trigger periods
 *  0b00111..The TSI_DATA[TSICNT] bits is the counter value of 8 trigger periods
 *  0b01000..The TSI_DATA[TSICNT] bits is the counter value of 9 trigger periods
 *  0b01001..The TSI_DATA[TSICNT] bits is the counter value of 10 trigger periods
 *  0b01010..The TSI_DATA[TSICNT] bits is the counter value of 11 trigger periods
 *  0b01011..The TSI_DATA[TSICNT] bits is the counter value of 12 trigger periods
 *  0b01100..The TSI_DATA[TSICNT] bits is the counter value of 13 trigger periods
 *  0b01101..The TSI_DATA[TSICNT] bits is the counter value of 14 trigger periods
 *  0b01110..The TSI_DATA[TSICNT] bits is the counter value of 15 trigger periods
 *  0b01111..The TSI_DATA[TSICNT] bits is the counter value of 16 trigger periods
 *  0b10000..The TSI_DATA[TSICNT] bits is the counter value of 17 trigger periods
 *  0b10001..The TSI_DATA[TSICNT] bits is the counter value of 18 trigger periods
 *  0b10010..The TSI_DATA[TSICNT] bits is the counter value of 19 trigger periods
 *  0b10011..The TSI_DATA[TSICNT] bits is the counter value of 20 trigger periods
 *  0b10100..The TSI_DATA[TSICNT] bits is the counter value of 21 trigger periods
 *  0b10101..The TSI_DATA[TSICNT] bits is the counter value of 22 trigger periods
 *  0b10110..The TSI_DATA[TSICNT] bits is the counter value of 23 trigger periods
 *  0b10111..The TSI_DATA[TSICNT] bits is the counter value of 24 trigger periods
 *  0b11000..The TSI_DATA[TSICNT] bits is the counter value of 25 trigger periods
 *  0b11001..The TSI_DATA[TSICNT] bits is the counter value of 26 trigger periods
 *  0b11010..The TSI_DATA[TSICNT] bits is the counter value of 27 trigger periods
 *  0b11011..The TSI_DATA[TSICNT] bits is the counter value of 28 trigger periods
 *  0b11100..The TSI_DATA[TSICNT] bits is the counter value of 29 trigger periods
 *  0b11101..The TSI_DATA[TSICNT] bits is the counter value of 30 trigger periods
 *  0b11110..The TSI_DATA[TSICNT] bits is the counter value of 31 trigger periods
 *  0b11111..The TSI_DATA[TSICNT] bits is the counter value of 32 trigger periods
 */
#define TSI_SINC_SINC_DECIMATION(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_DECIMATION_SHIFT)) & TSI_SINC_SINC_DECIMATION_MASK)

#define TSI_SINC_SINC_ORDER_MASK                 (0x200000U)
#define TSI_SINC_SINC_ORDER_SHIFT                (21U)
/*! SINC_ORDER - SINC_ORDER
 *  0b0..Using 1 order sinc filter
 *  0b1..Using 2 order sinc filter
 */
#define TSI_SINC_SINC_ORDER(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_ORDER_SHIFT)) & TSI_SINC_SINC_ORDER_MASK)

#define TSI_SINC_SINC_CUTOFF_MASK                (0xF000000U)
#define TSI_SINC_SINC_CUTOFF_SHIFT               (24U)
/*! SINC_CUTOFF - SINC_CUTOFF
 *  0b0000..div=1
 *  0b0001..div=2
 *  0b0010..div=4
 *  0b0011..div=8
 *  0b0100..div=16
 *  0b0101..div=32
 *  0b0110..div=64
 *  0b0111..div=128
 *  0b1000..NC
 *  0b1001..NC
 *  0b1010..NC
 *  0b1011..NC
 *  0b1100..NC
 *  0b1101..NC
 *  0b1110..NC
 *  0b1111..NC
 */
#define TSI_SINC_SINC_CUTOFF(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_CUTOFF_SHIFT)) & TSI_SINC_SINC_CUTOFF_MASK)
/*! @} */

/*! @name SSC0 - TSI SSC Register 0 */
/*! @{ */

#define TSI_SSC0_SSC_PRESCALE_NUM_MASK           (0xFFFU)
#define TSI_SSC0_SSC_PRESCALE_NUM_SHIFT          (0U)
/*! SSC_PRESCALE_NUM - SSC_PRESCALE_NUM
 *  0b000000000000..div1
 *  0b000000000001..div2
 *  0b000000000011..div4
 *  0b000000000111..div8
 *  0b000000001111..div16
 *  0b000000011111..div32
 *  0b000000111111..div64
 *  0b000001111111..div128
 *  0b000011111111..div256
 */
#define TSI_SSC0_SSC_PRESCALE_NUM(x)             (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_PRESCALE_NUM_SHIFT)) & TSI_SSC0_SSC_PRESCALE_NUM_MASK)

#define TSI_SSC0_BASE_NOCHARGE_NUM_MASK          (0xF0000U)
#define TSI_SSC0_BASE_NOCHARGE_NUM_SHIFT         (16U)
/*! BASE_NOCHARGE_NUM - BASE_NOCHARGE_NUM
 *  0b0000..The SSC output bit 1's basic period will be 1 clock cycle of system clock
 *  0b0001..The SSC output bit 1's basic period will be 2 clock cycles of system clock
 *  0b0010..The SSC output bit 1's basic period will be 3 clock cycles of system clock
 *  0b0011..The SSC output bit 1's basic period will be 4 clock cycles of system clock
 *  0b0100..The SSC output bit 1's basic period will be 5 clock cycles of system clock
 *  0b0101..The SSC output bit 1's basic period will be 6 clock cycles of system clock
 *  0b0110..The SSC output bit 1's basic period will be 7 clock cycles of system clock
 *  0b0111..The SSC output bit 1's basic period will be 8 clock cycles of system clock
 *  0b1000..The SSC output bit 1's basic period will be 9 clock cycles of system clock
 *  0b1001..The SSC output bit 1's basic period will be 10 clock cycles of system clock
 *  0b1010..The SSC output bit 1's basic period will be 11 clock cycles of system clock
 *  0b1011..The SSC output bit 1's basic period will be 12 clock cycles of system clock
 *  0b1100..The SSC output bit 1's basic period will be 13 clock cycles of system clock
 *  0b1101..The SSC output bit 1's basic period will be 14 clock cycles of system clock
 *  0b1110..The SSC output bit 1's basic period will be 15 clock cycles of system clock
 *  0b1111..The SSC output bit 1's basic period will be 16 clock cycles of system clock
 */
#define TSI_SSC0_BASE_NOCHARGE_NUM(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_BASE_NOCHARGE_NUM_SHIFT)) & TSI_SSC0_BASE_NOCHARGE_NUM_MASK)

#define TSI_SSC0_CHARGE_NUM_MASK                 (0xF00000U)
#define TSI_SSC0_CHARGE_NUM_SHIFT                (20U)
/*! CHARGE_NUM - CHARGE_NUM
 *  0b0000..The SSC output bit 0's period will be 1 clock cycle of system clock
 *  0b0001..The SSC output bit 0's period will be 2 clock cycles of system clock
 *  0b0010..The SSC output bit 0's period will be 3 clock cycles of system clock
 *  0b0011..The SSC output bit 0's period will be 4 clock cycles of system clock
 *  0b0100..The SSC output bit 0's period will be 5 clock cycles of system clock
 *  0b0101..The SSC output bit 0's period will be 6 clock cycles of system clock
 *  0b0110..The SSC output bit 0's period will be 7 clock cycles of system clock
 *  0b0111..The SSC output bit 0's period will be 8 clock cycles of system clock
 *  0b1000..The SSC output bit 0's period will be 9 clock cycles of system clock
 *  0b1001..The SSC output bit 0's period will be 10 clock cycles of system clock
 *  0b1010..The SSC output bit 0's period will be 11 clock cycles of system clock
 *  0b1011..The SSC output bit 0's period will be 12 clock cycles of system clock
 *  0b1100..The SSC output bit 0's period will be 13 clock cycles of system clock
 *  0b1101..The SSC output bit 0's period will be 14 clock cycles of system clock
 *  0b1110..The SSC output bit 0's period will be 15 clock cycles of system clock
 *  0b1111..The SSC output bit 0's period will be 16 clock cycles of system clock
 */
#define TSI_SSC0_CHARGE_NUM(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_CHARGE_NUM_SHIFT)) & TSI_SSC0_CHARGE_NUM_MASK)

#define TSI_SSC0_SSC_CONTROL_REVERSE_MASK        (0x1000000U)
#define TSI_SSC0_SSC_CONTROL_REVERSE_SHIFT       (24U)
/*! SSC_CONTROL_REVERSE - SSC_CONTROL_REVERSE
 *  0b0..Keep the polarity of the SSC output bit
 *  0b1..Reverse the polarity of the SSC output bit
 */
#define TSI_SSC0_SSC_CONTROL_REVERSE(x)          (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_CONTROL_REVERSE_SHIFT)) & TSI_SSC0_SSC_CONTROL_REVERSE_MASK)

#define TSI_SSC0_SSC_MODE_MASK                   (0x6000000U)
#define TSI_SSC0_SSC_MODE_SHIFT                  (25U)
/*! SSC_MODE - SSC_MODE
 *  0b00..Using PRBS method generating SSC output bit
 *  0b01..Using up-down counter generating SSC output bit
 *  0b10..SSC function is disabled
 *  0b11..NC
 */
#define TSI_SSC0_SSC_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_MODE_SHIFT)) & TSI_SSC0_SSC_MODE_MASK)

#define TSI_SSC0_PRBS_OUTSEL_MASK                (0xF0000000U)
#define TSI_SSC0_PRBS_OUTSEL_SHIFT               (28U)
/*! PRBS_OUTSEL - PRBS_OUTSEL
 *  0b0000..NC
 *  0b0001..NC
 *  0b0010..The order of the primitive polynomial is 2
 *  0b0011..The order of the primitive polynomial is 3
 *  0b0100..The order of the primitive polynomial is 4
 *  0b0101..The order of the primitive polynomial is 5
 *  0b0110..The order of the primitive polynomial is 6
 *  0b0111..The order of the primitive polynomial is 7
 *  0b1000..The order of the primitive polynomial is 8
 *  0b1001..The order of the primitive polynomial is 9
 *  0b1010..The order of the primitive polynomial is 10
 *  0b1011..The order of the primitive polynomial is 11
 *  0b1100..The order of the primitive polynomial is 12
 *  0b1101..The order of the primitive polynomial is 13
 *  0b1110..The order of the primitive polynomial is 14
 *  0b1111..The order of the primitive polynomial is 15
 */
#define TSI_SSC0_PRBS_OUTSEL(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_PRBS_OUTSEL_SHIFT)) & TSI_SSC0_PRBS_OUTSEL_MASK)
/*! @} */

/*! @name SSC1 - TSI SSC Register 1 */
/*! @{ */

#define TSI_SSC1_PRBS_SEED_LO_MASK               (0xFFU)
#define TSI_SSC1_PRBS_SEED_LO_SHIFT              (0U)
/*! PRBS_SEED_LO - PRBS_SEED_LO */
#define TSI_SSC1_PRBS_SEED_LO(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_SEED_LO_SHIFT)) & TSI_SSC1_PRBS_SEED_LO_MASK)

#define TSI_SSC1_PRBS_SEED_HI_MASK               (0xFF00U)
#define TSI_SSC1_PRBS_SEED_HI_SHIFT              (8U)
/*! PRBS_SEED_HI - PRBS_SEED_HI */
#define TSI_SSC1_PRBS_SEED_HI(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_SEED_HI_SHIFT)) & TSI_SSC1_PRBS_SEED_HI_MASK)

#define TSI_SSC1_PRBS_WEIGHT_LO_MASK             (0xFF0000U)
#define TSI_SSC1_PRBS_WEIGHT_LO_SHIFT            (16U)
/*! PRBS_WEIGHT_LO - PRBS_WEIGHT_LO */
#define TSI_SSC1_PRBS_WEIGHT_LO(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_WEIGHT_LO_SHIFT)) & TSI_SSC1_PRBS_WEIGHT_LO_MASK)

#define TSI_SSC1_PRBS_WEIGHT_HI_MASK             (0xFF000000U)
#define TSI_SSC1_PRBS_WEIGHT_HI_SHIFT            (24U)
/*! PRBS_WEIGHT_HI - PRBS_WEIGHT_HI */
#define TSI_SSC1_PRBS_WEIGHT_HI(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_WEIGHT_HI_SHIFT)) & TSI_SSC1_PRBS_WEIGHT_HI_MASK)
/*! @} */

/*! @name SSC2 - TSI SSC Register 2 */
/*! @{ */

#define TSI_SSC2_MOVE_REPEAT_NUM_MASK            (0x1FU)
#define TSI_SSC2_MOVE_REPEAT_NUM_SHIFT           (0U)
/*! MOVE_REPEAT_NUM - MOVE_REPEAT_NUM
 *  0b00000..The up_down counter will be updated for every sample-charge cycle
 *  0b00001..The up_down counter will be updated for every 2 sample-charge cycles
 *  0b00010..The up_down counter will be updated for every 3 sample-charge cycles
 *  0b00011..The up_down counter will be updated for every 4 sample-charge cycles
 *  0b00100..The up_down counter will be updated for every 5 sample-charge cycles
 *  0b00101..The up_down counter will be updated for every 6 sample-charge cycles
 *  0b00110..The up_down counter will be updated for every 7 sample-charge cycles
 */
#define TSI_SSC2_MOVE_REPEAT_NUM(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_REPEAT_NUM_SHIFT)) & TSI_SSC2_MOVE_REPEAT_NUM_MASK)

#define TSI_SSC2_MOVE_STEPS_NUM_MASK             (0x700U)
#define TSI_SSC2_MOVE_STEPS_NUM_SHIFT            (8U)
/*! MOVE_STEPS_NUM - MOVE_STEPS_NUM
 *  0b000..The added value for up-down counter is 0
 *  0b001..The added value for up-down counter is 1
 *  0b010..The added value for up-down counter is 2
 *  0b011..The added value for up-down counter is 3
 *  0b100..The added value for up-down counter is 4
 *  0b101..The added value for up-down counter is 5
 *  0b110..The added value for up-down counter is 6
 *  0b111..The added value for up-down counter is 7
 */
#define TSI_SSC2_MOVE_STEPS_NUM(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_STEPS_NUM_SHIFT)) & TSI_SSC2_MOVE_STEPS_NUM_MASK)

#define TSI_SSC2_MOVE_NOCHARGE_MAX_MASK          (0x3F0000U)
#define TSI_SSC2_MOVE_NOCHARGE_MAX_SHIFT         (16U)
/*! MOVE_NOCHARGE_MAX - MOVE_NOCHARGE_MAX */
#define TSI_SSC2_MOVE_NOCHARGE_MAX(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_NOCHARGE_MAX_SHIFT)) & TSI_SSC2_MOVE_NOCHARGE_MAX_MASK)

#define TSI_SSC2_MOVE_NOCHARGE_MIN_MASK          (0xF0000000U)
#define TSI_SSC2_MOVE_NOCHARGE_MIN_SHIFT         (28U)
/*! MOVE_NOCHARGE_MIN - MOVE_NOCHARGE_MIN
 *  0b0000..The SSC output bit 1's min period will be (1 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycle of system clock
 *  0b0001..The SSC output bit 1's min period will be (2 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b0010..The SSC output bit 1's min period will be (3 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b0011..The SSC output bit 1's min period will be (4 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b0100..The SSC output bit 1's min period will be (5 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b0101..The SSC output bit 1's min period will be (6 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b0110..The SSC output bit 1's min period will be (7 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b0111..The SSC output bit 1's min period will be (8 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1000..The SSC output bit 1's min period will be (9 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1001..The SSC output bit 1's min period will be (10 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1010..The SSC output bit 1's min period will be (11 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1011..The SSC output bit 1's min period will be (12 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1100..The SSC output bit 1's min period will be (13 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1101..The SSC output bit 1's min period will be (14 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1110..The SSC output bit 1's min period will be (15 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 *  0b1111..The SSC output bit 1's min period will be (16 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of system clock
 */
#define TSI_SSC2_MOVE_NOCHARGE_MIN(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_NOCHARGE_MIN_SHIFT)) & TSI_SSC2_MOVE_NOCHARGE_MIN_MASK)
/*! @} */

/*! @name BASELINE - TSI Baseline Register */
/*! @{ */

#define TSI_BASELINE_TSI_BASELINE_MASK           (0xFFFFU)
#define TSI_BASELINE_TSI_BASELINE_SHIFT          (0U)
/*! TSI_BASELINE - TSI_BASELINE */
#define TSI_BASELINE_TSI_BASELINE(x)             (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_TSI_BASELINE_SHIFT)) & TSI_BASELINE_TSI_BASELINE_MASK)

#define TSI_BASELINE_BASE_TRACE_DEBOUNCE_MASK    (0xF0000U)
#define TSI_BASELINE_BASE_TRACE_DEBOUNCE_SHIFT   (16U)
/*! BASE_TRACE_DEBOUNCE - BASE_TRACE_DEBOUNCE
 *  0b0000..The current counter value takes 0 ratio
 *  0b0001..The current counter value takes 1/16 ratio
 *  0b0010..The current counter value takes 2/16 ratio
 *  0b0011..The current counter value takes 3/16 ratio
 *  0b0100..The current counter value takes 4/16 ratio
 *  0b0101..The current counter value takes 5/16 ratio
 *  0b0110..The current counter value take 6/16 ratio
 *  0b0111..The current counter value takes 7/16 ratio
 *  0b1000..The current counter value takes 8/16 ratio
 *  0b1001..The current counter value takes 9/16 ratio
 *  0b1010..The current counter value takes 10/16 ratio
 *  0b1011..The current counter value takes 11/16 ratio
 *  0b1100..The current counter value takes 12/16 ratio
 *  0b1101..The current counter value takes 13/16 ratio
 *  0b1110..The current counter value takes 14/16 ratio
 *  0b1111..The current counter value takes 15/16 ratio
 */
#define TSI_BASELINE_BASE_TRACE_DEBOUNCE(x)      (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_BASE_TRACE_DEBOUNCE_SHIFT)) & TSI_BASELINE_BASE_TRACE_DEBOUNCE_MASK)

#define TSI_BASELINE_BASE_TRACE_EN_MASK          (0x100000U)
#define TSI_BASELINE_BASE_TRACE_EN_SHIFT         (20U)
/*! BASE_TRACE_EN - BASE_TRACE_EN
 *  0b0..Reserved
 *  0b1..Reserved
 */
#define TSI_BASELINE_BASE_TRACE_EN(x)            (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_BASE_TRACE_EN_SHIFT)) & TSI_BASELINE_BASE_TRACE_EN_MASK)

#define TSI_BASELINE_THESHOLD_RATIO_MASK         (0x70000000U)
#define TSI_BASELINE_THESHOLD_RATIO_SHIFT        (28U)
/*! THESHOLD_RATIO - THESHOLD_RATIO
 *  0b000..The thresholdh = baseline+counter/2, and thresholdl = baseline-counter/2
 *  0b001..The thresholdh = baseline+counter/4, and thresholdl = baseline-counter/4
 *  0b010..The thresholdh = baseline+counter/8, and thresholdl = baseline-counter/8
 *  0b011..The thresholdh = baseline+counter/16, and thresholdl = baseline-counter/16
 *  0b100..The thresholdh = baseline+counter/32, and thresholdl = baseline-counter/32
 *  0b101..The thresholdh = baseline+counter/64, and thresholdl = baseline-counter/64
 *  0b110..The thresholdh = baseline+counter/128, and thresholdl = baseline-counter/128
 *  0b111..The thresholdh = baseline+counter/256, and thresholdl = baseline-counter/256
 */
#define TSI_BASELINE_THESHOLD_RATIO(x)           (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_THESHOLD_RATIO_SHIFT)) & TSI_BASELINE_THESHOLD_RATIO_MASK)

#define TSI_BASELINE_THRESHOLD_TRACE_EN_MASK     (0x80000000U)
#define TSI_BASELINE_THRESHOLD_TRACE_EN_SHIFT    (31U)
/*! THRESHOLD_TRACE_EN - THRESHOLD_TRACE_EN
 *  0b0..Disable threshold trace function
 *  0b1..Enable threshold trace function
 */
#define TSI_BASELINE_THRESHOLD_TRACE_EN(x)       (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_THRESHOLD_TRACE_EN_SHIFT)) & TSI_BASELINE_THRESHOLD_TRACE_EN_MASK)
/*! @} */

/*! @name SHIELD - TSI Shield Register */
/*! @{ */

#define TSI_SHIELD_M_SEN_RES_MASK                (0x7E000000U)
#define TSI_SHIELD_M_SEN_RES_SHIFT               (25U)
/*! M_SEN_RES - M_SEN_RES
 *  0b000000..10 k
 *  0b000001..10 k + (2.5/3) k (just for auto-calibration)
 *  0b000010..12.5 k (default)
 *  0b001110..25 k
 */
#define TSI_SHIELD_M_SEN_RES(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_M_SEN_RES_SHIFT)) & TSI_SHIELD_M_SEN_RES_MASK)
/*! @} */

/*! @name SELF_SEL_31_0 - Self-cap mode channels selection(CH31~CH0) */
/*! @{ */

#define TSI_SELF_SEL_31_0_AS_SELF_31_0_MASK      (0xFFFFFFFFU)
#define TSI_SELF_SEL_31_0_AS_SELF_31_0_SHIFT     (0U)
/*! AS_SELF_31_0 - Config TSI channel as self-cap mode among CH31~CH0 */
#define TSI_SELF_SEL_31_0_AS_SELF_31_0(x)        (((uint32_t)(((uint32_t)(x)) << TSI_SELF_SEL_31_0_AS_SELF_31_0_SHIFT)) & TSI_SELF_SEL_31_0_AS_SELF_31_0_MASK)
/*! @} */

/*! @name SELF_SEL_63_32 - Self-cap mode channels selection(CH63~CH32) */
/*! @{ */

#define TSI_SELF_SEL_63_32_AS_SELF_63_32_MASK    (0xFFFFFFFFU)
#define TSI_SELF_SEL_63_32_AS_SELF_63_32_SHIFT   (0U)
/*! AS_SELF_63_32 - Config TSI channel as self-cap mode among CH63~CH32 */
#define TSI_SELF_SEL_63_32_AS_SELF_63_32(x)      (((uint32_t)(((uint32_t)(x)) << TSI_SELF_SEL_63_32_AS_SELF_63_32_SHIFT)) & TSI_SELF_SEL_63_32_AS_SELF_63_32_MASK)
/*! @} */

/*! @name SELF_SEL_69_64 - Self-cap mode channels selection(CH69~CH64) */
/*! @{ */

#define TSI_SELF_SEL_69_64_AS_SELF_69_64_MASK    (0x3FU)
#define TSI_SELF_SEL_69_64_AS_SELF_69_64_SHIFT   (0U)
/*! AS_SELF_69_64 - Config TSI channel as self-cap mode among CH69~CH64 */
#define TSI_SELF_SEL_69_64_AS_SELF_69_64(x)      (((uint32_t)(((uint32_t)(x)) << TSI_SELF_SEL_69_64_AS_SELF_69_64_SHIFT)) & TSI_SELF_SEL_69_64_AS_SELF_69_64_MASK)
/*! @} */

/*! @name SHIELD_SEL_31_0 - Shield mode channels selection(CH31~CH0) */
/*! @{ */

#define TSI_SHIELD_SEL_31_0_AS_SHIELD_31_0_MASK  (0xFFFFFFFFU)
#define TSI_SHIELD_SEL_31_0_AS_SHIELD_31_0_SHIFT (0U)
/*! AS_SHIELD_31_0 - Config TSI channel as shield mode among CH31~CH0 */
#define TSI_SHIELD_SEL_31_0_AS_SHIELD_31_0(x)    (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SEL_31_0_AS_SHIELD_31_0_SHIFT)) & TSI_SHIELD_SEL_31_0_AS_SHIELD_31_0_MASK)
/*! @} */

/*! @name SHIELD_SEL_63_32 - Shield mode channels selection(CH63~CH32) */
/*! @{ */

#define TSI_SHIELD_SEL_63_32_AS_SHIELD_63_32_MASK (0xFFFFFFFFU)
#define TSI_SHIELD_SEL_63_32_AS_SHIELD_63_32_SHIFT (0U)
/*! AS_SHIELD_63_32 - Config TSI channel as shield mode among CH63~CH32 */
#define TSI_SHIELD_SEL_63_32_AS_SHIELD_63_32(x)  (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SEL_63_32_AS_SHIELD_63_32_SHIFT)) & TSI_SHIELD_SEL_63_32_AS_SHIELD_63_32_MASK)
/*! @} */

/*! @name SHIELD_SEL_69_64 - Shield mode channels selection(CH69~CH64) */
/*! @{ */

#define TSI_SHIELD_SEL_69_64_AS_SHIELD_69_64_MASK (0x3FU)
#define TSI_SHIELD_SEL_69_64_AS_SHIELD_69_64_SHIFT (0U)
/*! AS_SHIELD_69_64 - Config TSI channel as shield mode among CH69~CH64 */
#define TSI_SHIELD_SEL_69_64_AS_SHIELD_69_64(x)  (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SEL_69_64_AS_SHIELD_69_64_SHIFT)) & TSI_SHIELD_SEL_69_64_AS_SHIELD_69_64_MASK)
/*! @} */

/*! @name MUTUAL_TX_SEL_31_0 - Mutual TX mode channels selection(CH31~CH0) */
/*! @{ */

#define TSI_MUTUAL_TX_SEL_31_0_AS_MUTUAL_TX_31_0_MASK (0xFFFFFFFFU)
#define TSI_MUTUAL_TX_SEL_31_0_AS_MUTUAL_TX_31_0_SHIFT (0U)
/*! AS_MUTUAL_TX_31_0 - Config TSI channel as mutual TX mode among CH31~CH0 */
#define TSI_MUTUAL_TX_SEL_31_0_AS_MUTUAL_TX_31_0(x) (((uint32_t)(((uint32_t)(x)) << TSI_MUTUAL_TX_SEL_31_0_AS_MUTUAL_TX_31_0_SHIFT)) & TSI_MUTUAL_TX_SEL_31_0_AS_MUTUAL_TX_31_0_MASK)
/*! @} */

/*! @name MUTUAL_TX_SEL_63_32 - Mutual TX mode channels selection(CH63~CH32) */
/*! @{ */

#define TSI_MUTUAL_TX_SEL_63_32_AS_MUTUAL_TX_63_32_MASK (0xFFFFFFFFU)
#define TSI_MUTUAL_TX_SEL_63_32_AS_MUTUAL_TX_63_32_SHIFT (0U)
/*! AS_MUTUAL_TX_63_32 - Config TSI channel as mutual TX mode among CH63~CH32 */
#define TSI_MUTUAL_TX_SEL_63_32_AS_MUTUAL_TX_63_32(x) (((uint32_t)(((uint32_t)(x)) << TSI_MUTUAL_TX_SEL_63_32_AS_MUTUAL_TX_63_32_SHIFT)) & TSI_MUTUAL_TX_SEL_63_32_AS_MUTUAL_TX_63_32_MASK)
/*! @} */

/*! @name MUTUAL_TX_SEL_69_64 - Mutual TX mode channels selection(CH69~CH64) */
/*! @{ */

#define TSI_MUTUAL_TX_SEL_69_64_AS_MUTUAL_TX_69_64_MASK (0x3FU)
#define TSI_MUTUAL_TX_SEL_69_64_AS_MUTUAL_TX_69_64_SHIFT (0U)
/*! AS_MUTUAL_TX_69_64 - Config TSI channel as mutual TX mode among CH69~CH64 */
#define TSI_MUTUAL_TX_SEL_69_64_AS_MUTUAL_TX_69_64(x) (((uint32_t)(((uint32_t)(x)) << TSI_MUTUAL_TX_SEL_69_64_AS_MUTUAL_TX_69_64_SHIFT)) & TSI_MUTUAL_TX_SEL_69_64_AS_MUTUAL_TX_69_64_MASK)
/*! @} */

/*! @name MUTUAL_RX_SEL_31_0 - Mutual RX mode channels selection(CH31~CH0) */
/*! @{ */

#define TSI_MUTUAL_RX_SEL_31_0_AS_MUTUAL_RX_31_0_MASK (0xFFFFFFFFU)
#define TSI_MUTUAL_RX_SEL_31_0_AS_MUTUAL_RX_31_0_SHIFT (0U)
/*! AS_MUTUAL_RX_31_0 - Config TSI channel as mutual RX mode among CH31~CH0 */
#define TSI_MUTUAL_RX_SEL_31_0_AS_MUTUAL_RX_31_0(x) (((uint32_t)(((uint32_t)(x)) << TSI_MUTUAL_RX_SEL_31_0_AS_MUTUAL_RX_31_0_SHIFT)) & TSI_MUTUAL_RX_SEL_31_0_AS_MUTUAL_RX_31_0_MASK)
/*! @} */

/*! @name MUTUAL_RX_SEL_63_32 - Mutual RX mode channels selection(CH63~CH32) */
/*! @{ */

#define TSI_MUTUAL_RX_SEL_63_32_AS_MUTUAL_RX_63_32_MASK (0xFFFFFFFFU)
#define TSI_MUTUAL_RX_SEL_63_32_AS_MUTUAL_RX_63_32_SHIFT (0U)
/*! AS_MUTUAL_RX_63_32 - Config TSI channel as mutual RX mode among CH63~CH32 */
#define TSI_MUTUAL_RX_SEL_63_32_AS_MUTUAL_RX_63_32(x) (((uint32_t)(((uint32_t)(x)) << TSI_MUTUAL_RX_SEL_63_32_AS_MUTUAL_RX_63_32_SHIFT)) & TSI_MUTUAL_RX_SEL_63_32_AS_MUTUAL_RX_63_32_MASK)
/*! @} */

/*! @name MUTUAL_RX_SEL_69_64 - Mutual RX mode channels selection (CH69~CH64) */
/*! @{ */

#define TSI_MUTUAL_RX_SEL_69_64_AS_MUTUAL_RX_69_64_MASK (0x3FU)
#define TSI_MUTUAL_RX_SEL_69_64_AS_MUTUAL_RX_69_64_SHIFT (0U)
/*! AS_MUTUAL_RX_69_64 - Config TSI channel as mutual RX mode among CH69~CH64 */
#define TSI_MUTUAL_RX_SEL_69_64_AS_MUTUAL_RX_69_64(x) (((uint32_t)(((uint32_t)(x)) << TSI_MUTUAL_RX_SEL_69_64_AS_MUTUAL_RX_69_64_SHIFT)) & TSI_MUTUAL_RX_SEL_69_64_AS_MUTUAL_RX_69_64_MASK)
/*! @} */

/*! @name DATA - TSI Data and Status Register */
/*! @{ */

#define TSI_DATA_TSICNT_MASK                     (0xFFFFU)
#define TSI_DATA_TSICNT_SHIFT                    (0U)
/*! TSICNT - TSI Conversion Counter Value */
#define TSI_DATA_TSICNT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_DATA_TSICNT_SHIFT)) & TSI_DATA_TSICNT_MASK)

#define TSI_DATA_TSICNT_OVERFLOW_FLAG_MASK       (0x10000U)
#define TSI_DATA_TSICNT_OVERFLOW_FLAG_SHIFT      (16U)
/*! TSICNT_OVERFLOW_FLAG - TSI Counter Overflow Flag
 *  0b0..The DATA[TSICNT] value has no overflow occurrence in the last scan process
 *  0b1..The DATA[TSICNT] value has an overflow occurrence in the last scan process
 */
#define TSI_DATA_TSICNT_OVERFLOW_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << TSI_DATA_TSICNT_OVERFLOW_FLAG_SHIFT)) & TSI_DATA_TSICNT_OVERFLOW_FLAG_MASK)

#define TSI_DATA_EOSF_MASK                       (0x8000000U)
#define TSI_DATA_EOSF_SHIFT                      (27U)
/*! EOSF - End of Scan Flag
 *  0b0..Scan is not done
 *  0b1..Scan is done
 */
#define TSI_DATA_EOSF(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_DATA_EOSF_SHIFT)) & TSI_DATA_EOSF_MASK)

#define TSI_DATA_OVERRUNF_MASK                   (0x20000000U)
#define TSI_DATA_OVERRUNF_SHIFT                  (29U)
/*! OVERRUNF - Overrun Flag
 *  0b0..There is trigger or ips bus writing during scan progress
 *  0b1..There is no trigger or ips bus writing during scan progress
 */
#define TSI_DATA_OVERRUNF(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_DATA_OVERRUNF_SHIFT)) & TSI_DATA_OVERRUNF_MASK)

#define TSI_DATA_OUTRGF_MASK                     (0x40000000U)
#define TSI_DATA_OUTRGF_SHIFT                    (30U)
/*! OUTRGF - Out of Range Flag
 *  0b0..The counter value is not out of range
 *  0b1..The counter value is out of range
 */
#define TSI_DATA_OUTRGF(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_DATA_OUTRGF_SHIFT)) & TSI_DATA_OUTRGF_MASK)

#define TSI_DATA_DPD_OUTRGF_MASK                 (0x80000000U)
#define TSI_DATA_DPD_OUTRGF_SHIFT                (31U)
/*! DPD_OUTRGF - DPD Out of Range Flag
 *  0b0..The counter value is not out of range
 *  0b1..The counter value is out of range
 */
#define TSI_DATA_DPD_OUTRGF(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_DATA_DPD_OUTRGF_SHIFT)) & TSI_DATA_DPD_OUTRGF_MASK)
/*! @} */

/*! @name MISC - TSI Miscellaneous Register */
/*! @{ */

#define TSI_MISC_CAP_BANK_2500FF_MASK            (0x7U)
#define TSI_MISC_CAP_BANK_2500FF_SHIFT           (0U)
/*! CAP_BANK_2500FF - Enable the 2500fF caps inside cap bank
 *  0b000..Enable another 2.5 pF in cap bank
 *  0b001..Enable another 5.0 pF in cap bank
 *  0b010..Enable another 7.5 pF in cap bank
 *  0b011..Enable another 10 pF in cap bank
 *  0b100..Enable another 12.5 pF in cap bank
 *  0b101..Enable another 15 pF in cap bank
 *  0b110..Enable another 17.5 pF in cap bank
 *  0b111..Enable another 20 pF in cap bank
 */
#define TSI_MISC_CAP_BANK_2500FF(x)              (((uint32_t)(((uint32_t)(x)) << TSI_MISC_CAP_BANK_2500FF_SHIFT)) & TSI_MISC_CAP_BANK_2500FF_MASK)

#define TSI_MISC_CAP_BANK_312FF_MASK             (0x70U)
#define TSI_MISC_CAP_BANK_312FF_SHIFT            (4U)
/*! CAP_BANK_312FF - Enable the 312fF caps inside cap bank
 *  0b000..Enable another 0.3125 pF
 *  0b001..Enable another 0.625 pF
 *  0b010..Enable another 0.936 pF
 *  0b011..Enable another 1.25 pF
 *  0b100..Enable another 1.56 pF
 *  0b101..Enable another 1.87 pF
 *  0b110..Enable another 2.19 pF
 *  0b111..Enable another 2.5 pF
 */
#define TSI_MISC_CAP_BANK_312FF(x)               (((uint32_t)(((uint32_t)(x)) << TSI_MISC_CAP_BANK_312FF_SHIFT)) & TSI_MISC_CAP_BANK_312FF_MASK)

#define TSI_MISC_DPD_MODE_ENABLE_MASK            (0x80000U)
#define TSI_MISC_DPD_MODE_ENABLE_SHIFT           (19U)
/*! DPD_MODE_ENABLE - DPD_MODE_ENABLE
 *  0b0..Configuration information in 3v domain logic is latched
 *  0b1..Configuration information in 3v domain logic is updating from configuration registers simultaneously
 */
#define TSI_MISC_DPD_MODE_ENABLE(x)              (((uint32_t)(((uint32_t)(x)) << TSI_MISC_DPD_MODE_ENABLE_SHIFT)) & TSI_MISC_DPD_MODE_ENABLE_MASK)

#define TSI_MISC_CAP_BANK_148FF_MASK             (0x700000U)
#define TSI_MISC_CAP_BANK_148FF_SHIFT            (20U)
/*! CAP_BANK_148FF - CAP_BANK_148FF
 *  0b000..Enable another 148 pF in cap bank
 *  0b001..Enable another 296 pF in cap bank
 *  0b010..Enable another 444 pF in cap bank
 *  0b011..Enable another 592 pF in cap bank
 *  0b100..Enable another 740 pF in cap bank
 *  0b101..Enable another 888 pF in cap bank
 *  0b110..Enable another 1036 pF in cap bank
 *  0b111..Enable another 1184 pF in cap bank
 */
#define TSI_MISC_CAP_BANK_148FF(x)               (((uint32_t)(((uint32_t)(x)) << TSI_MISC_CAP_BANK_148FF_SHIFT)) & TSI_MISC_CAP_BANK_148FF_MASK)

#define TSI_MISC_CAP_BANK_EN_MASK                (0x800000U)
#define TSI_MISC_CAP_BANK_EN_SHIFT               (23U)
/*! CAP_BANK_EN - Cap bank function enable signal
 *  0b0..Disable cap bank function
 *  0b1..Enable cap bank function
 */
#define TSI_MISC_CAP_BANK_EN(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_MISC_CAP_BANK_EN_SHIFT)) & TSI_MISC_CAP_BANK_EN_MASK)

#define TSI_MISC_CLK_DIVIDER_MASK                (0x1F000000U)
#define TSI_MISC_CLK_DIVIDER_SHIFT               (24U)
/*! CLK_DIVIDER - TSI Clock Divider */
#define TSI_MISC_CLK_DIVIDER(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_MISC_CLK_DIVIDER_SHIFT)) & TSI_MISC_CLK_DIVIDER_MASK)

#define TSI_MISC_COUNTING_CLK_HIGH_MASK          (0x80000000U)
#define TSI_MISC_COUNTING_CLK_HIGH_SHIFT         (31U)
/*! COUNTING_CLK_HIGH - COUNTING_CLK_HIGH
 *  0b0..Using default process inside SSC
 *  0b1..Follow the counting signal from AIP front end
 */
#define TSI_MISC_COUNTING_CLK_HIGH(x)            (((uint32_t)(((uint32_t)(x)) << TSI_MISC_COUNTING_CLK_HIGH_SHIFT)) & TSI_MISC_COUNTING_CLK_HIGH_MASK)
/*! @} */

/*! @name TRIG - TSI AUTO TRIG Register */
/*! @{ */

#define TSI_TRIG_TRIG_PERIOD_COUNTER_MASK        (0xFFFFFU)
#define TSI_TRIG_TRIG_PERIOD_COUNTER_SHIFT       (0U)
/*! TRIG_PERIOD_COUNTER - TRIG_PERIOD_COUNTER */
#define TSI_TRIG_TRIG_PERIOD_COUNTER(x)          (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_PERIOD_COUNTER_SHIFT)) & TSI_TRIG_TRIG_PERIOD_COUNTER_MASK)

#define TSI_TRIG_TRIG_CLK_DIVIDER_MASK           (0x1F000000U)
#define TSI_TRIG_TRIG_CLK_DIVIDER_SHIFT          (24U)
/*! TRIG_CLK_DIVIDER - TRIG_CLK_DIVIDER
 *  0b00000..No divider
 *  0b00001..Divided by 2
 *  0b00010..Divided by 3
 *  0b00011..Divided by 4
 *  0b00100..Divided by 5
 *  0b00101..Divided by 6
 *  0b00110..Divided by 7
 *  0b00111..Divided by 8
 *  0b01000..Divided by 9
 *  0b01001..Divided by 10
 *  0b01010..Divided by 11
 *  0b01011..Divided by 12
 *  0b01100..Divided by 13
 *  0b01101..Divided by 14
 *  0b01110..Divided by 15
 *  0b01111..Divided by 16
 *  0b10000..Divided by 17
 *  0b10001..Divided by 18
 *  0b10010..Divided by 19
 *  0b10011..Divided by 20
 *  0b10100..Divided by 21
 *  0b10101..Divided by 22
 *  0b10110..Divided by 23
 *  0b10111..Divided by 24
 *  0b11000..Divided by 25
 *  0b11001..Divided by 26
 *  0b11010..Divided by 27
 *  0b11011..Divided by 28
 *  0b11100..Divided by 29
 *  0b11101..Divided by 30
 *  0b11110..Divided by 31
 *  0b11111..Divided by 32
 */
#define TSI_TRIG_TRIG_CLK_DIVIDER(x)             (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_CLK_DIVIDER_SHIFT)) & TSI_TRIG_TRIG_CLK_DIVIDER_MASK)

#define TSI_TRIG_TRIG_EN_MASK                    (0x40000000U)
#define TSI_TRIG_TRIG_EN_SHIFT                   (30U)
/*! TRIG_EN - TRIG_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TSI_TRIG_TRIG_EN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_EN_SHIFT)) & TSI_TRIG_TRIG_EN_MASK)

#define TSI_TRIG_TRIG_CLK_SEL_MASK               (0x80000000U)
#define TSI_TRIG_TRIG_CLK_SEL_SHIFT              (31U)
/*! TRIG_CLK_SEL - TRIG_CLK_SEL
 *  0b0..32 KHz clock
 *  0b1..clksoc
 */
#define TSI_TRIG_TRIG_CLK_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_CLK_SEL_SHIFT)) & TSI_TRIG_TRIG_CLK_SEL_MASK)
/*! @} */

/*! @name TEST - TSI TEST Register */
/*! @{ */

#define TSI_TEST_TSI_TEST_EN_MASK                (0x1U)
#define TSI_TEST_TSI_TEST_EN_SHIFT               (0U)
/*! TSI_TEST_EN - TSI_TEST_EN
 *  0b0..Test mode is disabled
 *  0b1..Test mode is enabled
 */
#define TSI_TEST_TSI_TEST_EN(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_TEST_TSI_TEST_EN_SHIFT)) & TSI_TEST_TSI_TEST_EN_MASK)

#define TSI_TEST_DPD_TEST_EN_MASK                (0x2U)
#define TSI_TEST_DPD_TEST_EN_SHIFT               (1U)
/*! DPD_TEST_EN - DPD_TEST_EN
 *  0b0..IP is not entering dpd test mode
 *  0b1..IP is entering dpd test mode
 */
#define TSI_TEST_DPD_TEST_EN(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_TEST_DPD_TEST_EN_SHIFT)) & TSI_TEST_DPD_TEST_EN_MASK)

#define TSI_TEST_DPD_TEST_EOSF_MASK              (0x100U)
#define TSI_TEST_DPD_TEST_EOSF_SHIFT             (8U)
/*! DPD_TEST_EOSF - End of Scan Flag in DPD test mode
 *  0b0..Scan is not done in DPD test mode
 *  0b1..Scan is done in DPD test mode
 */
#define TSI_TEST_DPD_TEST_EOSF(x)                (((uint32_t)(((uint32_t)(x)) << TSI_TEST_DPD_TEST_EOSF_SHIFT)) & TSI_TEST_DPD_TEST_EOSF_MASK)

#define TSI_TEST_TSI_ANA_TEST_SETTING_MASK       (0xF0000U)
#define TSI_TEST_TSI_ANA_TEST_SETTING_SHIFT      (16U)
/*! TSI_ANA_TEST_SETTING - TSI_ANA_TEST_SETTING
 *  0b0000..Normal operation mode
 *  0b0001..Test mode 1, Vref test
 *  0b0010..Test mode 2, Vprechrg voltage test
 *  0b0011..Test mode 3, Comparator test
 *  0b0100..Test mode 4, Precharge function test
 *  0b0101..Test mode 5, 4uA bias test
 *  0b0110..Test mode 6, 2uA bias test
 *  0b0111..Test mode 7, Function monitor test
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define TSI_TEST_TSI_ANA_TEST_SETTING(x)         (((uint32_t)(((uint32_t)(x)) << TSI_TEST_TSI_ANA_TEST_SETTING_SHIFT)) & TSI_TEST_TSI_ANA_TEST_SETTING_MASK)

#define TSI_TEST_CLKSOC_SEL_MASK                 (0x100000U)
#define TSI_TEST_CLKSOC_SEL_SHIFT                (20U)
/*! CLKSOC_SEL - CLKSOC_SEL
 *  0b0..Reserved
 *  0b1..Reserved
 */
#define TSI_TEST_CLKSOC_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_TEST_CLKSOC_SEL_SHIFT)) & TSI_TEST_CLKSOC_SEL_MASK)

#define TSI_TEST_RUN_CTRL_MASK                   (0x200000U)
#define TSI_TEST_RUN_CTRL_SHIFT                  (21U)
/*! RUN_CTRL - RUN_CTRL
 *  0b0..Gate analog switch clock
 *  0b1..Not gate analog switch clock
 */
#define TSI_TEST_RUN_CTRL(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_TEST_RUN_CTRL_SHIFT)) & TSI_TEST_RUN_CTRL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TSI_Register_Masks */


/*!
 * @}
 */ /* end of group TSI_Peripheral_Access_Layer */


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


#endif  /* PERI_TSI_H_ */

