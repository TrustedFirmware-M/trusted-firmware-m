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
**         CMSIS Peripheral Access Layer for GDET
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
 * @file PERI_GDET.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GDET
 *
 * CMSIS Peripheral Access Layer for GDET
 */

#if !defined(PERI_GDET_H_)
#define PERI_GDET_H_                             /**< Symbol preventing repeated inclusion */

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
   -- GDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Peripheral_Access_Layer GDET Peripheral Access Layer
 * @{
 */

/** GDET - Register Layout Typedef */
typedef struct {
  __IO uint32_t GDET_CONF_0;                       /**< GDET Configuration 0 Register, offset: 0x0 */
  __IO uint32_t GDET_CONF_1;                       /**< GDET Configuration 1 Register, offset: 0x4 */
  __IO uint32_t GDET_ENABLE1;                      /**< GDET Enable Register, offset: 0x8 */
  __IO uint32_t GDET_CONF_2;                       /**< GDET Configuration 2 Register, offset: 0xC */
  __IO uint32_t GDET_CONF_3;                       /**< GDET Configuration 3 Register, offset: 0x10 */
  __IO uint32_t GDET_CONF_4;                       /**< GDET Configuration 4 Register, offset: 0x14 */
  __IO uint32_t GDET_CONF_5;                       /**< GDET Configuration 5 Register, offset: 0x18 */
       uint8_t RESERVED_0[4004];
  __IO uint32_t GDET_RESET;                        /**< GDET Reset Register, offset: 0xFC0 */
  __IO uint32_t GDET_TEST;                         /**< GDET Test Register, offset: 0xFC4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t GDET_DLY_CTRL;                     /**< GDET Delay Control Register, offset: 0xFCC */
} GDET_Type;

/* ----------------------------------------------------------------------------
   -- GDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Register_Masks GDET Register Masks
 * @{
 */

/*! @name GDET_CONF_0 - GDET Configuration 0 Register */
/*! @{ */

#define GDET_GDET_CONF_0_FIELD_3_0_MASK          (0xFU)
#define GDET_GDET_CONF_0_FIELD_3_0_SHIFT         (0U)
/*! FIELD_3_0 - GDET Configuration 0 Field 3_0 */
#define GDET_GDET_CONF_0_FIELD_3_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_FIELD_3_0_SHIFT)) & GDET_GDET_CONF_0_FIELD_3_0_MASK)

#define GDET_GDET_CONF_0_SBZ_MASK                (0x10U)
#define GDET_GDET_CONF_0_SBZ_SHIFT               (4U)
/*! SBZ - Should Be Left to Zero */
#define GDET_GDET_CONF_0_SBZ(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_SBZ_SHIFT)) & GDET_GDET_CONF_0_SBZ_MASK)

#define GDET_GDET_CONF_0_RFU_MASK                (0xFFFFFFE0U)
#define GDET_GDET_CONF_0_RFU_SHIFT               (5U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_CONF_0_RFU(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_RFU_SHIFT)) & GDET_GDET_CONF_0_RFU_MASK)
/*! @} */

/*! @name GDET_CONF_1 - GDET Configuration 1 Register */
/*! @{ */

#define GDET_GDET_CONF_1_FIELD_1_0_MASK          (0x3U)
#define GDET_GDET_CONF_1_FIELD_1_0_SHIFT         (0U)
/*! FIELD_1_0 - GDET Configuration 1 Field 1_0 */
#define GDET_GDET_CONF_1_FIELD_1_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_1_0_SHIFT)) & GDET_GDET_CONF_1_FIELD_1_0_MASK)

#define GDET_GDET_CONF_1_FIELD_3_2_MASK          (0xCU)
#define GDET_GDET_CONF_1_FIELD_3_2_SHIFT         (2U)
/*! FIELD_3_2 - GDET Configuration 1 Field 3_2 */
#define GDET_GDET_CONF_1_FIELD_3_2(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_3_2_SHIFT)) & GDET_GDET_CONF_1_FIELD_3_2_MASK)

#define GDET_GDET_CONF_1_SBZ1_MASK               (0x10U)
#define GDET_GDET_CONF_1_SBZ1_SHIFT              (4U)
/*! SBZ1 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ1_SHIFT)) & GDET_GDET_CONF_1_SBZ1_MASK)

#define GDET_GDET_CONF_1_SBZ2_MASK               (0x20U)
#define GDET_GDET_CONF_1_SBZ2_SHIFT              (5U)
/*! SBZ2 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ2(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ2_SHIFT)) & GDET_GDET_CONF_1_SBZ2_MASK)

#define GDET_GDET_CONF_1_SBZ3_MASK               (0x40U)
#define GDET_GDET_CONF_1_SBZ3_SHIFT              (6U)
/*! SBZ3 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ3(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ3_SHIFT)) & GDET_GDET_CONF_1_SBZ3_MASK)

#define GDET_GDET_CONF_1_FIELD_7_MASK            (0x80U)
#define GDET_GDET_CONF_1_FIELD_7_SHIFT           (7U)
/*! FIELD_7 - GDET Configuration 1 Field 7 */
#define GDET_GDET_CONF_1_FIELD_7(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_7_SHIFT)) & GDET_GDET_CONF_1_FIELD_7_MASK)

#define GDET_GDET_CONF_1_FIELD_8_MASK            (0x100U)
#define GDET_GDET_CONF_1_FIELD_8_SHIFT           (8U)
/*! FIELD_8 - GDET Configuration 1 Field 8 */
#define GDET_GDET_CONF_1_FIELD_8(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_8_SHIFT)) & GDET_GDET_CONF_1_FIELD_8_MASK)

#define GDET_GDET_CONF_1_SBZ4_MASK               (0x200U)
#define GDET_GDET_CONF_1_SBZ4_SHIFT              (9U)
/*! SBZ4 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ4(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ4_SHIFT)) & GDET_GDET_CONF_1_SBZ4_MASK)

#define GDET_GDET_CONF_1_SBZ5_MASK               (0x400U)
#define GDET_GDET_CONF_1_SBZ5_SHIFT              (10U)
/*! SBZ5 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ5(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ5_SHIFT)) & GDET_GDET_CONF_1_SBZ5_MASK)

#define GDET_GDET_CONF_1_RFU_MASK                (0xFFFFF800U)
#define GDET_GDET_CONF_1_RFU_SHIFT               (11U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_CONF_1_RFU(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_RFU_SHIFT)) & GDET_GDET_CONF_1_RFU_MASK)
/*! @} */

/*! @name GDET_ENABLE1 - GDET Enable Register */
/*! @{ */

#define GDET_GDET_ENABLE1_EN1_MASK               (0x1U)
#define GDET_GDET_ENABLE1_EN1_SHIFT              (0U)
/*! EN1 - If set, the detector will be clock gated */
#define GDET_GDET_ENABLE1_EN1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_EN1_SHIFT)) & GDET_GDET_ENABLE1_EN1_MASK)

#define GDET_GDET_ENABLE1_RFU_MASK               (0xFFFFFFFEU)
#define GDET_GDET_ENABLE1_RFU_SHIFT              (1U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_ENABLE1_RFU(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_RFU_SHIFT)) & GDET_GDET_ENABLE1_RFU_MASK)
/*! @} */

/*! @name GDET_CONF_2 - GDET Configuration 2 Register */
/*! @{ */

#define GDET_GDET_CONF_2_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_2_FIELD_6_0_SHIFT         (0U)
/*! FIELD_6_0 - GDET Configuration 2 Field 6_0 */
#define GDET_GDET_CONF_2_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_2_FIELD_6_0_MASK)

#define GDET_GDET_CONF_2_RFU1_MASK               (0xFF80U)
#define GDET_GDET_CONF_2_RFU1_SHIFT              (7U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU1_SHIFT)) & GDET_GDET_CONF_2_RFU1_MASK)

#define GDET_GDET_CONF_2_FIELD_21_16_MASK        (0x3F0000U)
#define GDET_GDET_CONF_2_FIELD_21_16_SHIFT       (16U)
/*! FIELD_21_16 - GDET Configuration 2 Field 21_16 */
#define GDET_GDET_CONF_2_FIELD_21_16(x)          (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_21_16_SHIFT)) & GDET_GDET_CONF_2_FIELD_21_16_MASK)

#define GDET_GDET_CONF_2_RFU2_MASK               (0xC00000U)
#define GDET_GDET_CONF_2_RFU2_SHIFT              (22U)
/*! RFU2 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU2(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU2_SHIFT)) & GDET_GDET_CONF_2_RFU2_MASK)

#define GDET_GDET_CONF_2_FIELD_29_24_MASK        (0x3F000000U)
#define GDET_GDET_CONF_2_FIELD_29_24_SHIFT       (24U)
/*! FIELD_29_24 - GDET Configuration 2 Field 29_24 */
#define GDET_GDET_CONF_2_FIELD_29_24(x)          (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_29_24_SHIFT)) & GDET_GDET_CONF_2_FIELD_29_24_MASK)

#define GDET_GDET_CONF_2_RFU3_MASK               (0xC0000000U)
#define GDET_GDET_CONF_2_RFU3_SHIFT              (30U)
/*! RFU3 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU3(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU3_SHIFT)) & GDET_GDET_CONF_2_RFU3_MASK)
/*! @} */

/*! @name GDET_CONF_3 - GDET Configuration 3 Register */
/*! @{ */

#define GDET_GDET_CONF_3_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_3_FIELD_6_0_SHIFT         (0U)
/*! FIELD_6_0 - GDET Configuration 3 Field 6_0 */
#define GDET_GDET_CONF_3_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_3_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_3_FIELD_6_0_MASK)

#define GDET_GDET_CONF_3_RFU1_MASK               (0xFFFFFF80U)
#define GDET_GDET_CONF_3_RFU1_SHIFT              (7U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_3_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_3_RFU1_SHIFT)) & GDET_GDET_CONF_3_RFU1_MASK)
/*! @} */

/*! @name GDET_CONF_4 - GDET Configuration 4 Register */
/*! @{ */

#define GDET_GDET_CONF_4_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_4_FIELD_6_0_SHIFT         (0U)
/*! FIELD_6_0 - GDET Configuration 4 Field 6_0 */
#define GDET_GDET_CONF_4_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_4_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_4_FIELD_6_0_MASK)

#define GDET_GDET_CONF_4_RFU1_MASK               (0xFFFFFF80U)
#define GDET_GDET_CONF_4_RFU1_SHIFT              (7U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_4_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_4_RFU1_SHIFT)) & GDET_GDET_CONF_4_RFU1_MASK)
/*! @} */

/*! @name GDET_CONF_5 - GDET Configuration 5 Register */
/*! @{ */

#define GDET_GDET_CONF_5_FIELD_5_0_MASK          (0x3FU)
#define GDET_GDET_CONF_5_FIELD_5_0_SHIFT         (0U)
/*! FIELD_5_0 - GDET Configuration 5 Field 5_0 */
#define GDET_GDET_CONF_5_FIELD_5_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_FIELD_5_0_SHIFT)) & GDET_GDET_CONF_5_FIELD_5_0_MASK)

#define GDET_GDET_CONF_5_FIELD_11_6_MASK         (0xFC0U)
#define GDET_GDET_CONF_5_FIELD_11_6_SHIFT        (6U)
/*! FIELD_11_6 - GDET Configuration 5 Field 11_6 */
#define GDET_GDET_CONF_5_FIELD_11_6(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_FIELD_11_6_SHIFT)) & GDET_GDET_CONF_5_FIELD_11_6_MASK)

#define GDET_GDET_CONF_5_RFU1_MASK               (0xFFFFF000U)
#define GDET_GDET_CONF_5_RFU1_SHIFT              (12U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_5_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_RFU1_SHIFT)) & GDET_GDET_CONF_5_RFU1_MASK)
/*! @} */

/*! @name GDET_RESET - GDET Reset Register */
/*! @{ */

#define GDET_GDET_RESET_RFU1_MASK                (0x7U)
#define GDET_GDET_RESET_RFU1_SHIFT               (0U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_RESET_RFU1(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_RFU1_SHIFT)) & GDET_GDET_RESET_RFU1_MASK)

#define GDET_GDET_RESET_SFT_RST_MASK             (0x8U)
#define GDET_GDET_RESET_SFT_RST_SHIFT            (3U)
/*! SFT_RST - Soft Reset for the Core Reset */
#define GDET_GDET_RESET_SFT_RST(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_SFT_RST_SHIFT)) & GDET_GDET_RESET_SFT_RST_MASK)

#define GDET_GDET_RESET_RFU2_MASK                (0xFFFFFFF0U)
#define GDET_GDET_RESET_RFU2_SHIFT               (4U)
/*! RFU2 - Reserved for Future Use */
#define GDET_GDET_RESET_RFU2(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_RFU2_SHIFT)) & GDET_GDET_RESET_RFU2_MASK)
/*! @} */

/*! @name GDET_TEST - GDET Test Register */
/*! @{ */

#define GDET_GDET_TEST_SBZ_MASK                  (0x1U)
#define GDET_GDET_TEST_SBZ_SHIFT                 (0U)
/*! SBZ - Should Be Left to Zero */
#define GDET_GDET_TEST_SBZ(x)                    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_TEST_SBZ_SHIFT)) & GDET_GDET_TEST_SBZ_MASK)

#define GDET_GDET_TEST_RFU_MASK                  (0xFFFFFFFEU)
#define GDET_GDET_TEST_RFU_SHIFT                 (1U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_TEST_RFU(x)                    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_TEST_RFU_SHIFT)) & GDET_GDET_TEST_RFU_MASK)
/*! @} */

/*! @name GDET_DLY_CTRL - GDET Delay Control Register */
/*! @{ */

#define GDET_GDET_DLY_CTRL_VOL_SEL_MASK          (0x3U)
#define GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT         (0U)
/*! VOL_SEL - GDET Delay Control of the Voltage Mode */
#define GDET_GDET_DLY_CTRL_VOL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT)) & GDET_GDET_DLY_CTRL_VOL_SEL_MASK)

#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK      (0x4U)
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT     (2U)
/*! SW_VOL_CTRL - Select the Control of the Trim Code to the Delay Line */
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT)) & GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK)

#define GDET_GDET_DLY_CTRL_RFU_MASK              (0xFFFFFFF8U)
#define GDET_GDET_DLY_CTRL_RFU_SHIFT             (3U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_DLY_CTRL_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_RFU_SHIFT)) & GDET_GDET_DLY_CTRL_RFU_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GDET_Register_Masks */


/*!
 * @}
 */ /* end of group GDET_Peripheral_Access_Layer */


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


#endif  /* PERI_GDET_H_ */

