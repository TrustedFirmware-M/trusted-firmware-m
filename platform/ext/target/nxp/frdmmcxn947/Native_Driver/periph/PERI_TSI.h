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
**         CMSIS Peripheral Access Layer for TSI
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
 * @file PERI_TSI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TSI
 *
 * CMSIS Peripheral Access Layer for TSI
 */

#if !defined(PERI_TSI_H_)
#define PERI_TSI_H_                              /**< Symbol preventing repeated inclusion */

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
   -- TSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Peripheral_Access_Layer TSI Peripheral Access Layer
 * @{
 */

/** TSI - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __IO uint32_t CONFIG_MUTUAL;                     /**< TSI CONFIG (TSI_CONFIG) for Mutual-Capacitor, offset: 0x0 */
    __IO uint32_t CONFIG;                            /**< TSI CONFIG (TSI_CONFIG) for Self-Capacitor, offset: 0x0 */
  };
  __IO uint32_t TSHD;                              /**< TSI Threshold, offset: 0x4 */
  __IO uint32_t GENCS;                             /**< TSI General Control and Status, offset: 0x8 */
  __IO uint32_t MUL;                               /**< TSI Mutual-Capacitance, offset: 0xC */
  __IO uint32_t SINC;                              /**< TSI SINC Filter, offset: 0x10 */
  __IO uint32_t SSC0;                              /**< TSI SSC 0, offset: 0x14 */
  __IO uint32_t SSC1;                              /**< TSI SSC 1, offset: 0x18 */
  __IO uint32_t SSC2;                              /**< TSI SSC 2, offset: 0x1C */
  __IO uint32_t BASELINE;                          /**< TSI Baseline, offset: 0x20 */
  __IO uint32_t CHMERGE;                           /**< TSI Channel Merge, offset: 0x24 */
  __IO uint32_t SHIELD;                            /**< TSI Shield, offset: 0x28 */
       uint8_t RESERVED_0[212];
  __IO uint32_t DATA;                              /**< TSI Data and Status, offset: 0x100 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MISC;                              /**< TSI Miscellaneous, offset: 0x108 */
  __IO uint32_t TRIG;                              /**< TSI AUTO TRIG, offset: 0x10C */
} TSI_Type;

/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Register_Masks TSI Register Masks
 * @{
 */

/*! @name CONFIG_MUTUAL - TSI CONFIG (TSI_CONFIG) for Mutual-Capacitor */
/*! @{ */

#define TSI_CONFIG_MUTUAL_MODE_MASK              (0x1U)
#define TSI_CONFIG_MUTUAL_MODE_SHIFT             (0U)
/*! MODE - Mode
 *  0b0..Self capacitance
 *  0b1..Mutual capacitance
 */
#define TSI_CONFIG_MUTUAL_MODE(x)                (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_MODE_SHIFT)) & TSI_CONFIG_MUTUAL_MODE_MASK)

#define TSI_CONFIG_MUTUAL_M_NMIRROR_MASK         (0x6U)
#define TSI_CONFIG_MUTUAL_M_NMIRROR_SHIFT        (1U)
/*! M_NMIRROR - NMOS Current Mirror
 *  0b00..m = 1
 *  0b01..m = 2
 *  0b10..m = 3
 *  0b11..m = 4
 */
#define TSI_CONFIG_MUTUAL_M_NMIRROR(x)           (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_NMIRROR_SHIFT)) & TSI_CONFIG_MUTUAL_M_NMIRROR_MASK)

#define TSI_CONFIG_MUTUAL_M_PMIRRORR_MASK        (0x18U)
#define TSI_CONFIG_MUTUAL_M_PMIRRORR_SHIFT       (3U)
/*! M_PMIRRORR - PMOS Current Mirror on Right Side
 *  0b00..m = 1
 *  0b01..m = 2
 *  0b10..m = 3
 *  0b11..m = 4
 */
#define TSI_CONFIG_MUTUAL_M_PMIRRORR(x)          (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_PMIRRORR_SHIFT)) & TSI_CONFIG_MUTUAL_M_PMIRRORR_MASK)

#define TSI_CONFIG_MUTUAL_M_PMIRRORL_MASK        (0xE0U)
#define TSI_CONFIG_MUTUAL_M_PMIRRORL_SHIFT       (5U)
/*! M_PMIRRORL - PMOS Current Mirror on Left Side
 *  0b000..m = 4
 *  0b001..m = 8
 *  0b010..m = 12
 *  0b011..m = 16
 *  0b100..m = 20
 *  0b101..m = 24
 *  0b110..m = 28
 *  0b111..m = 32
 */
#define TSI_CONFIG_MUTUAL_M_PMIRRORL(x)          (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_PMIRRORL_SHIFT)) & TSI_CONFIG_MUTUAL_M_PMIRRORL_MASK)

#define TSI_CONFIG_MUTUAL_M_SEL_RX_MASK          (0x1F00U)
#define TSI_CONFIG_MUTUAL_M_SEL_RX_SHIFT         (8U)
/*! M_SEL_RX - Mutual-Capacitance RX Channel Selection
 *  0b00000..TSI[8]
 *  0b00001..TSI[9]
 *  0b00010..TSI[10]
 *  0b00011..TSI[11]
 *  0b00100..TSI[12]
 *  0b00101..TSI[13]
 *  0b00110..TSI[14]
 *  0b00111..TSI[15]
 *  0b01000..TSI[16]
 *  0b01001..TSI[17]
 *  0b01010..TSI[18]
 *  0b01011..TSI[19]
 *  0b01100..TSI[20]
 *  0b01101..TSI[21]
 *  0b01110..TSI[22]
 *  0b01111..TSI[23]
 *  0b10000..TSI[24]
 */
#define TSI_CONFIG_MUTUAL_M_SEL_RX(x)            (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_SEL_RX_SHIFT)) & TSI_CONFIG_MUTUAL_M_SEL_RX_MASK)

#define TSI_CONFIG_MUTUAL_M_SEL_TX_MASK          (0xE000U)
#define TSI_CONFIG_MUTUAL_M_SEL_TX_SHIFT         (13U)
/*! M_SEL_TX - Mutual-Capacitance TX Channel Selection
 *  0b000..TSI[0]
 *  0b001..TSI[1]
 *  0b010..TSI[2]
 *  0b011..TSI[3]
 *  0b100..TSI[4]
 *  0b101..TSI[5]
 *  0b110..TSI[6]
 *  0b111..TSI[7]
 */
#define TSI_CONFIG_MUTUAL_M_SEL_TX(x)            (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_SEL_TX_SHIFT)) & TSI_CONFIG_MUTUAL_M_SEL_TX_MASK)

#define TSI_CONFIG_MUTUAL_M_CNT_EN_MASK          (0x10000U)
#define TSI_CONFIG_MUTUAL_M_CNT_EN_SHIFT         (16U)
/*! M_CNT_EN - Mutual-Capacitance Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_CONFIG_MUTUAL_M_CNT_EN(x)            (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_CNT_EN_SHIFT)) & TSI_CONFIG_MUTUAL_M_CNT_EN_MASK)

#define TSI_CONFIG_MUTUAL_M_TX_PD_EN_MASK        (0x20000U)
#define TSI_CONFIG_MUTUAL_M_TX_PD_EN_SHIFT       (17U)
/*! M_TX_PD_EN - Mutual-Capacitance TX Pulldown Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_CONFIG_MUTUAL_M_TX_PD_EN(x)          (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_TX_PD_EN_SHIFT)) & TSI_CONFIG_MUTUAL_M_TX_PD_EN_MASK)

#define TSI_CONFIG_MUTUAL_M_SEN_BOOST_MASK       (0x7C0000U)
#define TSI_CONFIG_MUTUAL_M_SEN_BOOST_SHIFT      (18U)
/*! M_SEN_BOOST - Mutual-Capacitance Sensitivity Boost
 *  0b00000..0 uA
 *  0b00001..2 uA
 *  0b00010..4 uA
 *  0b00011..6 uA
 *  0b00100..8 uA
 *  0b00101..10 uA
 *  0b00110..12 uA
 *  0b00111..14 uA
 *  0b11111..62 uA
 *  0b1xxxx..2 * n uA
 */
#define TSI_CONFIG_MUTUAL_M_SEN_BOOST(x)         (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_SEN_BOOST_SHIFT)) & TSI_CONFIG_MUTUAL_M_SEN_BOOST_MASK)

#define TSI_CONFIG_MUTUAL_M_PRE_RES_MASK         (0x1C000000U)
#define TSI_CONFIG_MUTUAL_M_PRE_RES_SHIFT        (26U)
/*! M_PRE_RES - Mutual-Capacitance Precharge Resistor
 *  0b000..1 kΩ
 *  0b001..2 kΩ
 *  0b010..3 kΩ
 *  0b011..4 kΩ
 *  0b100..5 kΩ
 *  0b101..6 kΩ
 *  0b110..7 kΩ
 *  0b111..8 kΩ
 */
#define TSI_CONFIG_MUTUAL_M_PRE_RES(x)           (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MUTUAL_M_PRE_RES_SHIFT)) & TSI_CONFIG_MUTUAL_M_PRE_RES_MASK)

#define TSI_CONFIG_MUTUAL_M_PRE_CURRENT_MASK     (0xE0000000U)
#define TSI_CONFIG_MUTUAL_M_PRE_CURRENT_SHIFT    (29U)
/*! M_PRE_CURRENT - Mutual-Capacitance Precharge Current
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

/*! @name CONFIG - TSI CONFIG (TSI_CONFIG) for Self-Capacitor */
/*! @{ */

#define TSI_CONFIG_MODE_MASK                     (0x1U)
#define TSI_CONFIG_MODE_SHIFT                    (0U)
/*! MODE - Mode
 *  0b0..Self capacitance
 *  0b1..Mutual capacitance
 */
#define TSI_CONFIG_MODE(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_MODE_SHIFT)) & TSI_CONFIG_MODE_MASK)

#define TSI_CONFIG_TSICH_MASK                    (0x3EU)
#define TSI_CONFIG_TSICH_SHIFT                   (1U)
/*! TSICH - TSI Channel
 *  0b00000..Channel 0
 *  0b00001..Channel 1
 *  0b00010..Channel 2
 *  0b00011..Channel 3
 *  0b00100..Channel 4
 *  0b00101..Channel 5
 *  0b00110..Channel 6
 *  0b00111..Channel 7
 *  0b01000..Channel 8
 *  0b01001..Channel 9
 *  0b01010..Channel 10
 *  0b01011..Channel 11
 *  0b01100..Channel 12
 *  0b01101..Channel 13
 *  0b01110..Channel 14
 *  0b01111..Channel 15
 *  0b10000..Channel 16
 *  0b10001..Channel 17
 *  0b10010..Channel 18
 *  0b10011..Channel 19
 *  0b10100..Channel 20
 *  0b10101..Channel 21
 *  0b10110..Channel 22
 *  0b10111..Channel 23
 *  0b11000..Channel 24
 */
#define TSI_CONFIG_TSICH(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_TSICH_SHIFT)) & TSI_CONFIG_TSICH_MASK)

#define TSI_CONFIG_S_NOISE_MASK                  (0x80000U)
#define TSI_CONFIG_S_NOISE_SHIFT                 (19U)
/*! S_NOISE - Self-Capacitance Noise Cancelation
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_CONFIG_S_NOISE(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_NOISE_SHIFT)) & TSI_CONFIG_S_NOISE_MASK)

#define TSI_CONFIG_S_XCH_MASK                    (0x700000U)
#define TSI_CONFIG_S_XCH_SHIFT                   (20U)
/*! S_XCH - Self-Capacitance Charge Current Multiple
 *  0b000..1 / 16
 *  0b001..1 / 8
 *  0b010..1 / 4
 *  0b011..1 / 2
 */
#define TSI_CONFIG_S_XCH(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_XCH_SHIFT)) & TSI_CONFIG_S_XCH_MASK)

#define TSI_CONFIG_S_XIN_MASK                    (0x800000U)
#define TSI_CONFIG_S_XIN_SHIFT                   (23U)
/*! S_XIN - Self-Capacitance Input Current Multiple
 *  0b0..1 / 8
 *  0b1..1 / 4
 */
#define TSI_CONFIG_S_XIN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_XIN_SHIFT)) & TSI_CONFIG_S_XIN_MASK)

#define TSI_CONFIG_S_CTRIM_MASK                  (0x7000000U)
#define TSI_CONFIG_S_CTRIM_SHIFT                 (24U)
/*! S_CTRIM - Capacitor Trim Setting
 *  0b000..2.5 pF
 *  0b001..5.0 pF
 *  0b010..7.5 pF
 *  0b011..10 pF
 *  0b100..12.5 pF
 *  0b101..15.0 pF
 *  0b110..17.5 pF
 *  0b111..20 pF
 */
#define TSI_CONFIG_S_CTRIM(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_CTRIM_SHIFT)) & TSI_CONFIG_S_CTRIM_MASK)

#define TSI_CONFIG_S_SEN_MASK                    (0x8000000U)
#define TSI_CONFIG_S_SEN_SHIFT                   (27U)
/*! S_SEN - Self-Capacitance Sensitivity Boost
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_CONFIG_S_SEN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_SEN_SHIFT)) & TSI_CONFIG_S_SEN_MASK)

#define TSI_CONFIG_S_XDN_MASK                    (0x70000000U)
#define TSI_CONFIG_S_XDN_SHIFT                   (28U)
/*! S_XDN - Self-Capacitance Discharge Current Multiple
 *  0b000..1 / 16
 *  0b001..1 / 8
 *  0b010..1 / 4
 *  0b011..1 / 2
 */
#define TSI_CONFIG_S_XDN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_XDN_SHIFT)) & TSI_CONFIG_S_XDN_MASK)

#define TSI_CONFIG_S_XIN_ADD_MASK                (0x80000000U)
#define TSI_CONFIG_S_XIN_ADD_SHIFT               (31U)
/*! S_XIN_ADD - S_XIN Adjust Ratio
 *  0b0..Disables; S_XIN = 0 for 1 / 4, S_XIN = 1 for 1 / 8
 *  0b1..Enables; S_XIN = 0 for 1 / 8, S_XIN = 1 for 1 / 16
 */
#define TSI_CONFIG_S_XIN_ADD(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_CONFIG_S_XIN_ADD_SHIFT)) & TSI_CONFIG_S_XIN_ADD_MASK)
/*! @} */

/*! @name TSHD - TSI Threshold */
/*! @{ */

#define TSI_TSHD_THRESL_MASK                     (0xFFFFU)
#define TSI_TSHD_THRESL_SHIFT                    (0U)
/*! THRESL - TSI Wakeup Channel Low Threshold */
#define TSI_TSHD_THRESL(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_TSHD_THRESL_SHIFT)) & TSI_TSHD_THRESL_MASK)

#define TSI_TSHD_THRESH_MASK                     (0xFFFF0000U)
#define TSI_TSHD_THRESH_SHIFT                    (16U)
/*! THRESH - TSI Wakeup Channel High Threshold */
#define TSI_TSHD_THRESH(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_TSHD_THRESH_SHIFT)) & TSI_TSHD_THRESH_MASK)
/*! @} */

/*! @name GENCS - TSI General Control and Status */
/*! @{ */

#define TSI_GENCS_DMAEN_EOS_MASK                 (0x1U)
#define TSI_GENCS_DMAEN_EOS_SHIFT                (0U)
/*! DMAEN_EOS - In-Progress DMA Transfer Request Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_GENCS_DMAEN_EOS(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DMAEN_EOS_SHIFT)) & TSI_GENCS_DMAEN_EOS_MASK)

#define TSI_GENCS_DMAEN_OUTRG_MASK               (0x4U)
#define TSI_GENCS_DMAEN_OUTRG_SHIFT              (2U)
/*! DMAEN_OUTRG - Out-of-Range DMA Transfer Request Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_GENCS_DMAEN_OUTRG(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DMAEN_OUTRG_SHIFT)) & TSI_GENCS_DMAEN_OUTRG_MASK)

#define TSI_GENCS_STM_MASK                       (0x8U)
#define TSI_GENCS_STM_SHIFT                      (3U)
/*! STM - Scan Trigger Mode
 *  0b0..Software trigger scan
 *  0b1..Hardware trigger scan
 */
#define TSI_GENCS_STM(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_STM_SHIFT)) & TSI_GENCS_STM_MASK)

#define TSI_GENCS_STPE_MASK                      (0x10U)
#define TSI_GENCS_STPE_SHIFT                     (4U)
/*! STPE - TSI Stop Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_GENCS_STPE(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_STPE_SHIFT)) & TSI_GENCS_STPE_MASK)

#define TSI_GENCS_TSIEN_MASK                     (0x20U)
#define TSI_GENCS_TSIEN_SHIFT                    (5U)
/*! TSIEN - TSI Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_GENCS_TSIEN(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_TSIEN_SHIFT)) & TSI_GENCS_TSIEN_MASK)

#define TSI_GENCS_SWTS_MASK                      (0x80U)
#define TSI_GENCS_SWTS_SHIFT                     (7U)
/*! SWTS - Software Trigger Start
 *  0b0..No effect
 *  0b1..Takes effect
 */
#define TSI_GENCS_SWTS(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_SWTS_SHIFT)) & TSI_GENCS_SWTS_MASK)

#define TSI_GENCS_CTRIM_FINE_MASK                (0xE00U)
#define TSI_GENCS_CTRIM_FINE_SHIFT               (9U)
/*! CTRIM_FINE - Capacitor Fine Trim
 *  0b000..0.3125 pF
 *  0b001..0.625 pF
 *  0b010..0.3125 * 3 pF
 *  0b011..0.3125 * 4 pF
 *  0b100..0.3125 * 5 pF
 *  0b101..0.3125 * 6 pF
 *  0b110..2.1875 pF
 *  0b111..2.5 pF
 */
#define TSI_GENCS_CTRIM_FINE(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_CTRIM_FINE_SHIFT)) & TSI_GENCS_CTRIM_FINE_MASK)

#define TSI_GENCS_DVOLT_MASK                     (0x7000U)
#define TSI_GENCS_DVOLT_SHIFT                    (12U)
/*! DVOLT - Delta Voltage
 *  0b000..Vm = 0.6 V, Vp = 1.7 V
 *  0b001..Vm = 0.6 V, Vp = 1.9 V
 *  0b010..Vm = 0.6 V, Vp = 2.1 V
 *  0b011..Vm = 0.6 V, Vp = 2.3 V
 *  0b100..Vm = 0.6 V, Vp = 2.5 V
 *  0b101..Vm = 0.6 V, Vp = 2.7 V
 */
#define TSI_GENCS_DVOLT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DVOLT_SHIFT)) & TSI_GENCS_DVOLT_MASK)

#define TSI_GENCS_DEBOUNCE_MASK                  (0x1F0000U)
#define TSI_GENCS_DEBOUNCE_SHIFT                 (16U)
/*! DEBOUNCE - Debounce
 *  0b00000..1
 *  0b00001..2
 *  0b11111..31
 *  0b1xxxx..n
 */
#define TSI_GENCS_DEBOUNCE(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DEBOUNCE_SHIFT)) & TSI_GENCS_DEBOUNCE_MASK)

#define TSI_GENCS_S_PROX_EN_MASK                 (0x400000U)
#define TSI_GENCS_S_PROX_EN_SHIFT                (22U)
/*! S_PROX_EN - Proximity Enable Signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_GENCS_S_PROX_EN(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_S_PROX_EN_SHIFT)) & TSI_GENCS_S_PROX_EN_MASK)

#define TSI_GENCS_SETCLK_MASK                    (0x7000000U)
#define TSI_GENCS_SETCLK_SHIFT                   (24U)
/*! SETCLK - Set Clock
 *  0b000..27.37 MHz
 *  0b001..22.23 MHz
 *  0b010..18.73 MHz
 *  0b011..16.65 MHz
 *  0b100..14.27 MHz
 *  0b101..12.73 MHz
 *  0b110..11.49 MHz
 *  0b111..10.46 MHz
 */
#define TSI_GENCS_SETCLK(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_SETCLK_SHIFT)) & TSI_GENCS_SETCLK_MASK)

#define TSI_GENCS_ESOR_MASK                      (0x8000000U)
#define TSI_GENCS_ESOR_SHIFT                     (27U)
/*! ESOR - End-of-Scan Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_GENCS_ESOR(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_ESOR_SHIFT)) & TSI_GENCS_ESOR_MASK)

#define TSI_GENCS_OUTRG_EN_MASK                  (0x40000000U)
#define TSI_GENCS_OUTRG_EN_SHIFT                 (30U)
/*! OUTRG_EN - Out-of-Range Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_GENCS_OUTRG_EN(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_OUTRG_EN_SHIFT)) & TSI_GENCS_OUTRG_EN_MASK)
/*! @} */

/*! @name MUL - TSI Mutual-Capacitance */
/*! @{ */

#define TSI_MUL_M_VPRE_CHOOSE_MASK               (0x2U)
#define TSI_MUL_M_VPRE_CHOOSE_SHIFT              (1U)
/*! M_VPRE_CHOOSE - Mutual-Capacitance Prevoltage
 *  0b0..Internal 1.2 V
 *  0b1..External 1.2 V from PMC
 */
#define TSI_MUL_M_VPRE_CHOOSE(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_VPRE_CHOOSE_SHIFT)) & TSI_MUL_M_VPRE_CHOOSE_MASK)

#define TSI_MUL_M_MODE_MASK                      (0x4U)
#define TSI_MUL_M_MODE_SHIFT                     (2U)
/*! M_MODE - Mutual-Capacitance Mode
 *  0b0..- 5 V ~ + 5 V
 *  0b1..0 V ~ + 5 V
 */
#define TSI_MUL_M_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_MODE_SHIFT)) & TSI_MUL_M_MODE_MASK)

#define TSI_MUL_M_TRIM_CAP_MASK                  (0x18U)
#define TSI_MUL_M_TRIM_CAP_SHIFT                 (3U)
/*! M_TRIM_CAP - Mutual-Capacitance Trim Cap
 *  0b00..0 pF
 *  0b01..10 pF
 *  0b10..10 pF
 *  0b11..20 pF
 */
#define TSI_MUL_M_TRIM_CAP(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_TRIM_CAP_SHIFT)) & TSI_MUL_M_TRIM_CAP_MASK)

#define TSI_MUL_M_TX_USED_MASK                   (0x1FE0U)
#define TSI_MUL_M_TX_USED_SHIFT                  (5U)
/*! M_TX_USED - Mutual-Capacitance TX Used
 *  0b00000000..GPIO
 *  0b00000001..Mutual capacitance
 */
#define TSI_MUL_M_TX_USED(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_TX_USED_SHIFT)) & TSI_MUL_M_TX_USED_MASK)

#define TSI_MUL_M_TRIM_MASK                      (0xFFFF0000U)
#define TSI_MUL_M_TRIM_SHIFT                     (16U)
/*! M_TRIM - Mutual-Capacitance Trim */
#define TSI_MUL_M_TRIM(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_MUL_M_TRIM_SHIFT)) & TSI_MUL_M_TRIM_MASK)
/*! @} */

/*! @name SINC - TSI SINC Filter */
/*! @{ */

#define TSI_SINC_SSC_CONTROL_OUT_MASK            (0x1U)
#define TSI_SINC_SSC_CONTROL_OUT_SHIFT           (0U)
/*! SSC_CONTROL_OUT - SSC Output Control
 *  0b0..0
 *  0b1..1
 */
#define TSI_SINC_SSC_CONTROL_OUT(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SSC_CONTROL_OUT_SHIFT)) & TSI_SINC_SSC_CONTROL_OUT_MASK)

#define TSI_SINC_SINC_VALID_MASK                 (0x2U)
#define TSI_SINC_SINC_VALID_SHIFT                (1U)
/*! SINC_VALID - SINC Valid
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TSI_SINC_SINC_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_VALID_SHIFT)) & TSI_SINC_SINC_VALID_MASK)

#define TSI_SINC_SINC_OVERFLOW_FLAG_MASK         (0x4U)
#define TSI_SINC_SINC_OVERFLOW_FLAG_SHIFT        (2U)
/*! SINC_OVERFLOW_FLAG - SINC Overflow Flag
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define TSI_SINC_SINC_OVERFLOW_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_OVERFLOW_FLAG_SHIFT)) & TSI_SINC_SINC_OVERFLOW_FLAG_MASK)

#define TSI_SINC_SWITCH_ENABLE_MASK              (0x8U)
#define TSI_SINC_SWITCH_ENABLE_SHIFT             (3U)
/*! SWITCH_ENABLE - Switch Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TSI_SINC_SWITCH_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SWITCH_ENABLE_SHIFT)) & TSI_SINC_SWITCH_ENABLE_MASK)

#define TSI_SINC_DECIMATION_MASK                 (0x1F0000U)
#define TSI_SINC_DECIMATION_SHIFT                (16U)
/*! DECIMATION - Decimation
 *  0b00000..1
 *  0b00001..2
 *  0b00010..3
 *  0b00011..4
 *  0b00100..5
 *  0b00101..6
 *  0b00110..7
 *  0b00111..8
 *  0b01000..9
 *  0b01001..10
 *  0b01010..11
 *  0b01011..12
 *  0b01100..13
 *  0b01101..14
 *  0b01110..15
 *  0b01111..16
 *  0b10000..17
 *  0b10001..18
 *  0b10010..19
 *  0b10011..20
 *  0b10100..21
 *  0b10101..22
 *  0b10110..23
 *  0b10111..24
 *  0b11000..25
 *  0b11001..26
 *  0b11010..27
 *  0b11011..28
 *  0b11100..29
 *  0b11101..30
 *  0b11110..31
 *  0b11111..32
 */
#define TSI_SINC_DECIMATION(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SINC_DECIMATION_SHIFT)) & TSI_SINC_DECIMATION_MASK)

#define TSI_SINC_ORDER_MASK                      (0x200000U)
#define TSI_SINC_ORDER_SHIFT                     (21U)
/*! ORDER - Order
 *  0b0..Order 1
 *  0b1..Order 2
 */
#define TSI_SINC_ORDER(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_SINC_ORDER_SHIFT)) & TSI_SINC_ORDER_MASK)

#define TSI_SINC_CUTOFF_MASK                     (0xF000000U)
#define TSI_SINC_CUTOFF_SHIFT                    (24U)
/*! CUTOFF - Cutoff
 *  0b0000..div = 1
 *  0b0001..div = 2
 *  0b0010..div = 4
 *  0b0011..div = 8
 *  0b0100..div = 16
 *  0b0101..div = 32
 *  0b0110..div = 64
 *  0b0111..div = 128
 *  0b1000..Do not use
 *  0b1001..Do not use
 *  0b1010..Do not use
 *  0b1011..Do not use
 *  0b1100..Do not use
 *  0b1101..Do not use
 *  0b1110..Do not use
 *  0b1111..Do not use
 */
#define TSI_SINC_CUTOFF(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_SINC_CUTOFF_SHIFT)) & TSI_SINC_CUTOFF_MASK)
/*! @} */

/*! @name SSC0 - TSI SSC 0 */
/*! @{ */

#define TSI_SSC0_SSC_PRESCALE_NUM_MASK           (0xFFU)
#define TSI_SSC0_SSC_PRESCALE_NUM_SHIFT          (0U)
/*! SSC_PRESCALE_NUM - SSC Prescale Number
 *  0b00000000..div = 1
 *  0b00000001..div = 2
 *  0b00000011..div = 4
 *  0b00000111..div = 8
 *  0b00001111..div = 16
 *  0b00011111..div = 32
 *  0b00111111..div = 64
 *  0b01111111..div = 128
 *  0b11111111..div = 256
 */
#define TSI_SSC0_SSC_PRESCALE_NUM(x)             (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_PRESCALE_NUM_SHIFT)) & TSI_SSC0_SSC_PRESCALE_NUM_MASK)

#define TSI_SSC0_BASE_NOCHARGE_NUM_MASK          (0xF0000U)
#define TSI_SSC0_BASE_NOCHARGE_NUM_SHIFT         (16U)
/*! BASE_NOCHARGE_NUM - Base Nocharge Number
 *  0b0000..1
 *  0b0001..2
 *  0b0010..3
 *  0b0011..4
 *  0b0100..5
 *  0b0101..6
 *  0b0110..7
 *  0b0111..8
 *  0b1000..9
 *  0b1001..10
 *  0b1010..11
 *  0b1011..12
 *  0b1100..13
 *  0b1101..14
 *  0b1110..15
 *  0b1111..16
 */
#define TSI_SSC0_BASE_NOCHARGE_NUM(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_BASE_NOCHARGE_NUM_SHIFT)) & TSI_SSC0_BASE_NOCHARGE_NUM_MASK)

#define TSI_SSC0_CHARGE_NUM_MASK                 (0xF00000U)
#define TSI_SSC0_CHARGE_NUM_SHIFT                (20U)
/*! CHARGE_NUM - Charge Number
 *  0b0000..1
 *  0b0001..2
 *  0b0010..3
 *  0b0011..4
 *  0b0100..5
 *  0b0101..6
 *  0b0110..7
 *  0b0111..8
 *  0b1000..9
 *  0b1001..10
 *  0b1010..11
 *  0b1011..12
 *  0b1100..13
 *  0b1101..14
 *  0b1110..15
 *  0b1111..16
 */
#define TSI_SSC0_CHARGE_NUM(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_CHARGE_NUM_SHIFT)) & TSI_SSC0_CHARGE_NUM_MASK)

#define TSI_SSC0_SSC_CONTROL_REVERSE_MASK        (0x1000000U)
#define TSI_SSC0_SSC_CONTROL_REVERSE_SHIFT       (24U)
/*! SSC_CONTROL_REVERSE - SSC Control Reverse
 *  0b0..Polarity retained
 *  0b1..Polarity reversed
 */
#define TSI_SSC0_SSC_CONTROL_REVERSE(x)          (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_CONTROL_REVERSE_SHIFT)) & TSI_SSC0_SSC_CONTROL_REVERSE_MASK)

#define TSI_SSC0_SSC_MODE_MASK                   (0x6000000U)
#define TSI_SSC0_SSC_MODE_SHIFT                  (25U)
/*! SSC_MODE - SSC Mode
 *  0b00..PRBS mode
 *  0b01..Up-Down Counter mode
 *  0b10..Disables SSC function
 *  0b11..Do not use
 */
#define TSI_SSC0_SSC_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_MODE_SHIFT)) & TSI_SSC0_SSC_MODE_MASK)

#define TSI_SSC0_PRBS_OUTSEL_MASK                (0xF0000000U)
#define TSI_SSC0_PRBS_OUTSEL_SHIFT               (28U)
/*! PRBS_OUTSEL - PRBS Output Selection
 *  0b0000..Do not use
 *  0b0001..Do not use
 *  0b0010..2
 *  0b0011..3
 *  0b0100..4
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 *  0b1001..9
 *  0b1010..10
 *  0b1011..11
 *  0b1100..12
 *  0b1101..13
 *  0b1110..14
 *  0b1111..15
 */
#define TSI_SSC0_PRBS_OUTSEL(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_PRBS_OUTSEL_SHIFT)) & TSI_SSC0_PRBS_OUTSEL_MASK)
/*! @} */

/*! @name SSC1 - TSI SSC 1 */
/*! @{ */

#define TSI_SSC1_PRBS_SEED_LO_MASK               (0xFFU)
#define TSI_SSC1_PRBS_SEED_LO_SHIFT              (0U)
/*! PRBS_SEED_LO - PRBS Low Seed */
#define TSI_SSC1_PRBS_SEED_LO(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_SEED_LO_SHIFT)) & TSI_SSC1_PRBS_SEED_LO_MASK)

#define TSI_SSC1_PRBS_SEED_HI_MASK               (0xFF00U)
#define TSI_SSC1_PRBS_SEED_HI_SHIFT              (8U)
/*! PRBS_SEED_HI - PRBS High Seed */
#define TSI_SSC1_PRBS_SEED_HI(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_SEED_HI_SHIFT)) & TSI_SSC1_PRBS_SEED_HI_MASK)

#define TSI_SSC1_PRBS_WEIGHT_LO_MASK             (0xFF0000U)
#define TSI_SSC1_PRBS_WEIGHT_LO_SHIFT            (16U)
/*! PRBS_WEIGHT_LO - PRBS Low Weight */
#define TSI_SSC1_PRBS_WEIGHT_LO(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_WEIGHT_LO_SHIFT)) & TSI_SSC1_PRBS_WEIGHT_LO_MASK)

#define TSI_SSC1_PRBS_WEIGHT_HI_MASK             (0xFF000000U)
#define TSI_SSC1_PRBS_WEIGHT_HI_SHIFT            (24U)
/*! PRBS_WEIGHT_HI - PRBS High Weight */
#define TSI_SSC1_PRBS_WEIGHT_HI(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_WEIGHT_HI_SHIFT)) & TSI_SSC1_PRBS_WEIGHT_HI_MASK)
/*! @} */

/*! @name SSC2 - TSI SSC 2 */
/*! @{ */

#define TSI_SSC2_MOVE_REPEAT_NUM_MASK            (0x1FU)
#define TSI_SSC2_MOVE_REPEAT_NUM_SHIFT           (0U)
/*! MOVE_REPEAT_NUM - Move Repeat Number
 *  0b00000..1
 *  0b00001..2
 *  0b00010..3
 *  0b00011..4
 *  0b00100..5
 *  0b00101..6
 *  0b00110..7
 */
#define TSI_SSC2_MOVE_REPEAT_NUM(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_REPEAT_NUM_SHIFT)) & TSI_SSC2_MOVE_REPEAT_NUM_MASK)

#define TSI_SSC2_MOVE_STEPS_NUM_MASK             (0x700U)
#define TSI_SSC2_MOVE_STEPS_NUM_SHIFT            (8U)
/*! MOVE_STEPS_NUM - Move Steps Number
 *  0b000..0
 *  0b001..1
 *  0b010..2
 *  0b011..3
 *  0b100..4
 *  0b101..5
 *  0b110..6
 *  0b111..7
 */
#define TSI_SSC2_MOVE_STEPS_NUM(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_STEPS_NUM_SHIFT)) & TSI_SSC2_MOVE_STEPS_NUM_MASK)

#define TSI_SSC2_MOVE_NOCHARGE_MAX_MASK          (0x3F0000U)
#define TSI_SSC2_MOVE_NOCHARGE_MAX_SHIFT         (16U)
/*! MOVE_NOCHARGE_MAX - Move Nocharge Maximum */
#define TSI_SSC2_MOVE_NOCHARGE_MAX(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_NOCHARGE_MAX_SHIFT)) & TSI_SSC2_MOVE_NOCHARGE_MAX_MASK)

#define TSI_SSC2_MOVE_NOCHARGE_MIN_MASK          (0xF0000000U)
#define TSI_SSC2_MOVE_NOCHARGE_MIN_SHIFT         (28U)
/*! MOVE_NOCHARGE_MIN - Move Nocharge Minimum
 *  0b0000..(1 + SSC0[BASE_NOCHARGE_NUM])
 *  0b0001..(2 + SSC0[BASE_NOCHARGE_NUM])
 *  0b0010..(3 + SSC0[BASE_NOCHARGE_NUM])
 *  0b0011..(4 + SSC0[BASE_NOCHARGE_NUM])
 *  0b0100..(5 + SSC0[BASE_NOCHARGE_NUM])
 *  0b0101..(6 + SSC0[BASE_NOCHARGE_NUM])
 *  0b0110..(7 + SSC0[BASE_NOCHARGE_NUM])
 *  0b0111..(8 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1000..(9 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1001..(10 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1010..(11 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1011..(12 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1100..(13 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1101..(14 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1110..(15 + SSC0[BASE_NOCHARGE_NUM])
 *  0b1111..(16 + SSC0[BASE_NOCHARGE_NUM])
 */
#define TSI_SSC2_MOVE_NOCHARGE_MIN(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_NOCHARGE_MIN_SHIFT)) & TSI_SSC2_MOVE_NOCHARGE_MIN_MASK)
/*! @} */

/*! @name BASELINE - TSI Baseline */
/*! @{ */

#define TSI_BASELINE_BASELINE_MASK               (0xFFFFU)
#define TSI_BASELINE_BASELINE_SHIFT              (0U)
/*! BASELINE - Baseline */
#define TSI_BASELINE_BASELINE(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_BASELINE_SHIFT)) & TSI_BASELINE_BASELINE_MASK)

#define TSI_BASELINE_BASE_TRACE_DEBOUNCE_MASK    (0xF0000U)
#define TSI_BASELINE_BASE_TRACE_DEBOUNCE_SHIFT   (16U)
/*! BASE_TRACE_DEBOUNCE - Base Trace Debounce
 *  0b0000..0
 *  0b0001..1 / 16
 *  0b0010..2 / 16
 *  0b0011..3 / 16
 *  0b1111..15 / 16
 *  0b1xxx..n / 16
 */
#define TSI_BASELINE_BASE_TRACE_DEBOUNCE(x)      (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_BASE_TRACE_DEBOUNCE_SHIFT)) & TSI_BASELINE_BASE_TRACE_DEBOUNCE_MASK)

#define TSI_BASELINE_BASE_TRACE_EN_MASK          (0x100000U)
#define TSI_BASELINE_BASE_TRACE_EN_SHIFT         (20U)
/*! BASE_TRACE_EN - Baseline Trace Enable */
#define TSI_BASELINE_BASE_TRACE_EN(x)            (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_BASE_TRACE_EN_SHIFT)) & TSI_BASELINE_BASE_TRACE_EN_MASK)

#define TSI_BASELINE_THESHOLD_RATIO_MASK         (0x70000000U)
#define TSI_BASELINE_THESHOLD_RATIO_SHIFT        (28U)
/*! THESHOLD_RATIO - Threshold Ratio
 *  0b000..thresholdh = (baseline + counter) / 2 and thresholdl = (baseline - counter) / 2
 *  0b001..thresholdh = (baseline + counter) / 4 and thresholdl = (baseline - counter) / 4
 *  0b010..thresholdh = (baseline + counter) / 8 and thresholdl = (baseline - counter) / 8
 *  0b011..thresholdh = (baseline + counter) / 16 and thresholdl = (baseline - counter) / 16
 *  0b100..thresholdh = (baseline + counter) / 32 and thresholdl = (baseline - counter) / 32
 *  0b101..thresholdh = (baseline + counter) / 64 and thresholdl = (baseline - counter) / 64
 *  0b110..thresholdh = (baseline + counter) / 128 and thresholdl = (baseline - counter) / 128
 *  0b111..thresholdh = (baseline + counter) / 256 and thresholdl = (baseline - counter) / 256
 */
#define TSI_BASELINE_THESHOLD_RATIO(x)           (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_THESHOLD_RATIO_SHIFT)) & TSI_BASELINE_THESHOLD_RATIO_MASK)

#define TSI_BASELINE_THRESHOLD_TRACE_EN_MASK     (0x80000000U)
#define TSI_BASELINE_THRESHOLD_TRACE_EN_SHIFT    (31U)
/*! THRESHOLD_TRACE_EN - Threshold Trace Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_BASELINE_THRESHOLD_TRACE_EN(x)       (((uint32_t)(((uint32_t)(x)) << TSI_BASELINE_THRESHOLD_TRACE_EN_SHIFT)) & TSI_BASELINE_THRESHOLD_TRACE_EN_MASK)
/*! @} */

/*! @name CHMERGE - TSI Channel Merge */
/*! @{ */

#define TSI_CHMERGE_CHANNEL_ENABLE_MASK          (0x1FFFFFFU)
#define TSI_CHMERGE_CHANNEL_ENABLE_SHIFT         (0U)
/*! CHANNEL_ENABLE - Channel Enable
 *  0b0000000000000000000000000..Channel not chosen for proximity pad
 *  0b0000000000000000000000001..Channel chosen for proximity pad
 */
#define TSI_CHMERGE_CHANNEL_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << TSI_CHMERGE_CHANNEL_ENABLE_SHIFT)) & TSI_CHMERGE_CHANNEL_ENABLE_MASK)
/*! @} */

/*! @name SHIELD - TSI Shield */
/*! @{ */

#define TSI_SHIELD_SHIELD_ENABLE_MASK            (0xFU)
#define TSI_SHIELD_SHIELD_ENABLE_SHIFT           (0U)
/*! SHIELD_ENABLE - Shield Enable
 *  0b0000..Disables
 *  0b0001..Enables
 */
#define TSI_SHIELD_SHIELD_ENABLE(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_ENABLE_SHIFT)) & TSI_SHIELD_SHIELD_ENABLE_MASK)

#define TSI_SHIELD_M_SEN_RES_MASK                (0x7E000000U)
#define TSI_SHIELD_M_SEN_RES_SHIFT               (25U)
/*! M_SEN_RES - Mutual-Capacitance Sensitivity Resistor
 *  0b000000..10 kΩ
 *  0b000001..10 kΩ + (2.5 / 3) kΩ (just for auto-calibration)
 *  0b000010..12.5 kΩ (default)
 *  0b001110..25 kΩ
 */
#define TSI_SHIELD_M_SEN_RES(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_M_SEN_RES_SHIFT)) & TSI_SHIELD_M_SEN_RES_MASK)
/*! @} */

/*! @name DATA - TSI Data and Status */
/*! @{ */

#define TSI_DATA_TSICNT_MASK                     (0xFFFFU)
#define TSI_DATA_TSICNT_SHIFT                    (0U)
/*! TSICNT - TSI Conversion Counter Value */
#define TSI_DATA_TSICNT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_DATA_TSICNT_SHIFT)) & TSI_DATA_TSICNT_MASK)

#define TSI_DATA_EOSF_MASK                       (0x8000000U)
#define TSI_DATA_EOSF_SHIFT                      (27U)
/*! EOSF - End-of-Scan Flag */
#define TSI_DATA_EOSF(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_DATA_EOSF_SHIFT)) & TSI_DATA_EOSF_MASK)

#define TSI_DATA_OVERRUNF_MASK                   (0x20000000U)
#define TSI_DATA_OVERRUNF_SHIFT                  (29U)
/*! OVERRUNF - Overrun Flag
 *  0b0..No
 *  0b1..Yes
 */
#define TSI_DATA_OVERRUNF(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_DATA_OVERRUNF_SHIFT)) & TSI_DATA_OVERRUNF_MASK)

#define TSI_DATA_OUTRGF_MASK                     (0x40000000U)
#define TSI_DATA_OUTRGF_SHIFT                    (30U)
/*! OUTRGF - Out-of-Range Flag */
#define TSI_DATA_OUTRGF(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_DATA_OUTRGF_SHIFT)) & TSI_DATA_OUTRGF_MASK)
/*! @} */

/*! @name MISC - TSI Miscellaneous */
/*! @{ */

#define TSI_MISC_OSC_CLK_SEL_MASK                (0x80000U)
#define TSI_MISC_OSC_CLK_SEL_SHIFT               (19U)
/*! OSC_CLK_SEL - Oscillator Clock Select
 *  0b0..Analog oscillator
 *  0b1..Chip
 */
#define TSI_MISC_OSC_CLK_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_MISC_OSC_CLK_SEL_SHIFT)) & TSI_MISC_OSC_CLK_SEL_MASK)

#define TSI_MISC_TEST_FINGER_MASK                (0x700000U)
#define TSI_MISC_TEST_FINGER_SHIFT               (20U)
/*! TEST_FINGER - Test Finger
 *  0b000..Finger capacitor is 148 pF
 *  0b001..Finger capacitor is 296 pF
 *  0b010..Finger capacitor is 444 pF
 *  0b011..Finger capacitor is 592 pF
 *  0b100..Finger capacitor is 740 pF
 *  0b101..Finger capacitor is 888 pF
 *  0b110..Finger capacitor is 1036 pF
 *  0b111..Finger capacitor is 1184 pF
 */
#define TSI_MISC_TEST_FINGER(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_MISC_TEST_FINGER_SHIFT)) & TSI_MISC_TEST_FINGER_MASK)

#define TSI_MISC_TEST_FINGER_EN_MASK             (0x800000U)
#define TSI_MISC_TEST_FINGER_EN_SHIFT            (23U)
/*! TEST_FINGER_EN - Test Finger Function Enable Signals
 *  0b0..Disables
 *  0b1..Enables
 */
#define TSI_MISC_TEST_FINGER_EN(x)               (((uint32_t)(((uint32_t)(x)) << TSI_MISC_TEST_FINGER_EN_SHIFT)) & TSI_MISC_TEST_FINGER_EN_MASK)

#define TSI_MISC_CLKDIVIDER_MASK                 (0x1F000000U)
#define TSI_MISC_CLKDIVIDER_SHIFT                (24U)
/*! CLKDIVIDER - TSI Clock Divider */
#define TSI_MISC_CLKDIVIDER(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_MISC_CLKDIVIDER_SHIFT)) & TSI_MISC_CLKDIVIDER_MASK)
/*! @} */

/*! @name TRIG - TSI AUTO TRIG */
/*! @{ */

#define TSI_TRIG_TRIG_PERIOD_COUNTER_MASK        (0xFFFFFU)
#define TSI_TRIG_TRIG_PERIOD_COUNTER_SHIFT       (0U)
/*! TRIG_PERIOD_COUNTER - Trigger Period Counter */
#define TSI_TRIG_TRIG_PERIOD_COUNTER(x)          (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_PERIOD_COUNTER_SHIFT)) & TSI_TRIG_TRIG_PERIOD_COUNTER_MASK)

#define TSI_TRIG_TRIG_CLK_DIVIDER_MASK           (0x1F000000U)
#define TSI_TRIG_TRIG_CLK_DIVIDER_SHIFT          (24U)
/*! TRIG_CLK_DIVIDER - Trigger Clock Divider
 *  0b00000..No divider
 *  0b00001..Divided by 2
 *  0b00010..Divided by 3
 *  0b00011..Divided by 4
 *  0b1xxxx..Divided by n
 */
#define TSI_TRIG_TRIG_CLK_DIVIDER(x)             (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_CLK_DIVIDER_SHIFT)) & TSI_TRIG_TRIG_CLK_DIVIDER_MASK)

#define TSI_TRIG_TRIG_EN_MASK                    (0x40000000U)
#define TSI_TRIG_TRIG_EN_SHIFT                   (30U)
/*! TRIG_EN - Trigger Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TSI_TRIG_TRIG_EN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_EN_SHIFT)) & TSI_TRIG_TRIG_EN_MASK)

#define TSI_TRIG_TRIG_CLK_SEL_MASK               (0x80000000U)
#define TSI_TRIG_TRIG_CLK_SEL_SHIFT              (31U)
/*! TRIG_CLK_SEL - Trigger Clock Select
 *  0b0..32 k clock
 *  0b1..clksoc
 */
#define TSI_TRIG_TRIG_CLK_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_TRIG_TRIG_CLK_SEL_SHIFT)) & TSI_TRIG_TRIG_CLK_SEL_MASK)
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

