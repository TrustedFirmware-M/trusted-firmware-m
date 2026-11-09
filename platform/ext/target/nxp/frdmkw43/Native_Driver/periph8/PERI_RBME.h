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
**         CMSIS Peripheral Access Layer for RBME
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
 * @file PERI_RBME.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for RBME
 *
 * CMSIS Peripheral Access Layer for RBME
 */

#if !defined(PERI_RBME_H_)
#define PERI_RBME_H_                             /**< Symbol preventing repeated inclusion */

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
   -- RBME Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RBME_Peripheral_Access_Layer RBME Peripheral Access Layer
 * @{
 */

/** RBME - Register Layout Typedef */
typedef struct {
  __IO uint32_t CRCW_CFG;                          /**< CRC/WHITENER CONFIG, offset: 0x0 */
  __I  uint32_t CRC_EC_MASK;                       /**< CRC ERROR CORRECTION MASK, offset: 0x4 */
  __I  uint32_t CRC_RES_OUT;                       /**< CRC RESULT, offset: 0x8 */
  __IO uint32_t CRCW_CFG2;                         /**< CRC/WHITENER CONFIG 2, offset: 0xC */
  __IO uint32_t CRCW_CFG3;                         /**< CRC CONFIGURATION, offset: 0x10 */
  __IO uint32_t CRC_INIT;                          /**< CRC INITIALIZATION, offset: 0x14 */
  __IO uint32_t CRC_POLY;                          /**< CRC POLYNOMIAL, offset: 0x18 */
  __IO uint32_t CRC_XOR_OUT;                       /**< CRC XOR OUT, offset: 0x1C */
  __IO uint32_t WHITEN_CFG;                        /**< WHITENER CONFIGURATION, offset: 0x20 */
  __IO uint32_t WHITEN_POLY;                       /**< WHITENER POLYNOMIAL, offset: 0x24 */
  __IO uint32_t WHITEN_SZ_THR;                     /**< WHITENER SIZE THRESHOLD, offset: 0x28 */
  __IO uint32_t FEC_CFG1;                          /**< FEC CONFIG 1, offset: 0x2C */
  __IO uint32_t RBME_RST;                          /**< RBME SOFT RESET, offset: 0x30 */
  __IO uint32_t FEC_CFG2;                          /**< FEC CONFIG 2, offset: 0x34 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SPREAD_CFG;                        /**< SPREADER CONFIG, offset: 0x3C */
  __IO uint32_t WHT_CFG;                           /**< WHITEN CONFIG, offset: 0x40 */
  __IO uint32_t PKT_SZ;                            /**< PACKET SIZE, offset: 0x44 */
  __IO uint32_t CRC_PHR_SZ;                        /**< LENGTH OF PHR CONFIG, offset: 0x48 */
  __IO uint32_t FCP_CFG;                           /**< FCP SUPPORT CONFIG, offset: 0x4C */
  __IO uint32_t FRAME_OVER_SZ;                     /**< FRAME OVERRIDE SIZE, offset: 0x50 */
  __IO uint32_t FEC_BSZ_OV_B4SP;                   /**< OVERRIDE OF FEC BLOCK SIZE, offset: 0x54 */
  __IO uint32_t LEG0_CFG;                          /**< LEG0 CONFIG, offset: 0x58 */
  __IO uint32_t NPAYL_OVER_SZ;                     /**< OVERRIDE PAYLOAD, offset: 0x5C */
       uint8_t RESERVED_1[4];
  __IO uint32_t RAM_S_ADDR;                        /**< PACKET RAM SOURCE ADDRESS, offset: 0x64 */
  __IO uint32_t RAM_D_ADDR;                        /**< PACKET RAM DESTINATION ADDRESS, offset: 0x68 */
  __IO uint32_t RAM_IF_CFG;                        /**< PACKET RAM INTERFACE CONFIG, offset: 0x6C */
} RBME_Type;

/* ----------------------------------------------------------------------------
   -- RBME Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RBME_Register_Masks RBME Register Masks
 * @{
 */

/*! @name CRCW_CFG - CRC/WHITENER CONFIG */
/*! @{ */

#define RBME_CRCW_CFG_CRCW_EN_MASK               (0x1U)
#define RBME_CRCW_CFG_CRCW_EN_SHIFT              (0U)
/*! CRCW_EN - CRC calculation enable */
#define RBME_CRCW_CFG_CRCW_EN(x)                 (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRCW_EN_SHIFT)) & RBME_CRCW_CFG_CRCW_EN_MASK)

#define RBME_CRCW_CFG_CRCW_EC_EN_MASK            (0x2U)
#define RBME_CRCW_CFG_CRCW_EC_EN_SHIFT           (1U)
/*! CRCW_EC_EN - CRC Error Correction Enable */
#define RBME_CRCW_CFG_CRCW_EC_EN(x)              (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRCW_EC_EN_SHIFT)) & RBME_CRCW_CFG_CRCW_EC_EN_MASK)

#define RBME_CRCW_CFG_CRC_ZERO_MASK              (0x4U)
#define RBME_CRCW_CFG_CRC_ZERO_SHIFT             (2U)
/*! CRC_ZERO - CRC zero */
#define RBME_CRCW_CFG_CRC_ZERO(x)                (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRC_ZERO_SHIFT)) & RBME_CRCW_CFG_CRC_ZERO_MASK)

#define RBME_CRCW_CFG_CRC_EARLY_FAIL_MASK        (0x8U)
#define RBME_CRCW_CFG_CRC_EARLY_FAIL_SHIFT       (3U)
/*! CRC_EARLY_FAIL - CRC error correction fail */
#define RBME_CRCW_CFG_CRC_EARLY_FAIL(x)          (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRC_EARLY_FAIL_SHIFT)) & RBME_CRCW_CFG_CRC_EARLY_FAIL_MASK)

#define RBME_CRCW_CFG_CRC_RES_OUT_VLD_MASK       (0x10U)
#define RBME_CRCW_CFG_CRC_RES_OUT_VLD_SHIFT      (4U)
/*! CRC_RES_OUT_VLD - CRC result output valid */
#define RBME_CRCW_CFG_CRC_RES_OUT_VLD(x)         (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRC_RES_OUT_VLD_SHIFT)) & RBME_CRCW_CFG_CRC_RES_OUT_VLD_MASK)

#define RBME_CRCW_CFG_CRC_EC_OFFSET_MASK         (0x7FF0000U)
#define RBME_CRCW_CFG_CRC_EC_OFFSET_SHIFT        (16U)
/*! CRC_EC_OFFSET - CRC error correction offset */
#define RBME_CRCW_CFG_CRC_EC_OFFSET(x)           (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRC_EC_OFFSET_SHIFT)) & RBME_CRCW_CFG_CRC_EC_OFFSET_MASK)

#define RBME_CRCW_CFG_CRC_EC_DONE_MASK           (0x10000000U)
#define RBME_CRCW_CFG_CRC_EC_DONE_SHIFT          (28U)
/*! CRC_EC_DONE - CRC error correction done */
#define RBME_CRCW_CFG_CRC_EC_DONE(x)             (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRC_EC_DONE_SHIFT)) & RBME_CRCW_CFG_CRC_EC_DONE_MASK)

#define RBME_CRCW_CFG_CRC_EC_FAIL_MASK           (0x20000000U)
#define RBME_CRCW_CFG_CRC_EC_FAIL_SHIFT          (29U)
/*! CRC_EC_FAIL - CRC error correction fail */
#define RBME_CRCW_CFG_CRC_EC_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG_CRC_EC_FAIL_SHIFT)) & RBME_CRCW_CFG_CRC_EC_FAIL_MASK)
/*! @} */

/*! @name CRC_EC_MASK - CRC ERROR CORRECTION MASK */
/*! @{ */

#define RBME_CRC_EC_MASK_CRC_EC_MASK_MASK        (0xFFFFFFFFU)
#define RBME_CRC_EC_MASK_CRC_EC_MASK_SHIFT       (0U)
/*! CRC_EC_MASK - CRC error correction mask */
#define RBME_CRC_EC_MASK_CRC_EC_MASK(x)          (((uint32_t)(((uint32_t)(x)) << RBME_CRC_EC_MASK_CRC_EC_MASK_SHIFT)) & RBME_CRC_EC_MASK_CRC_EC_MASK_MASK)
/*! @} */

/*! @name CRC_RES_OUT - CRC RESULT */
/*! @{ */

#define RBME_CRC_RES_OUT_CRC_RES_OUT_MASK        (0xFFFFFFFFU)
#define RBME_CRC_RES_OUT_CRC_RES_OUT_SHIFT       (0U)
/*! CRC_RES_OUT - CRC result output */
#define RBME_CRC_RES_OUT_CRC_RES_OUT(x)          (((uint32_t)(((uint32_t)(x)) << RBME_CRC_RES_OUT_CRC_RES_OUT_SHIFT)) & RBME_CRC_RES_OUT_CRC_RES_OUT_MASK)
/*! @} */

/*! @name CRCW_CFG2 - CRC/WHITENER CONFIG 2 */
/*! @{ */

#define RBME_CRCW_CFG2_CRC_EC_SPKT_BYTES_MASK    (0xFFU)
#define RBME_CRCW_CFG2_CRC_EC_SPKT_BYTES_SHIFT   (0U)
/*! CRC_EC_SPKT_BYTES - Error Correction Short Packet Bytes */
#define RBME_CRCW_CFG2_CRC_EC_SPKT_BYTES(x)      (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG2_CRC_EC_SPKT_BYTES_SHIFT)) & RBME_CRCW_CFG2_CRC_EC_SPKT_BYTES_MASK)

#define RBME_CRCW_CFG2_CRC_EC_SPKT_WND_MASK      (0xF00U)
#define RBME_CRCW_CFG2_CRC_EC_SPKT_WND_SHIFT     (8U)
/*! CRC_EC_SPKT_WND - Error correction short packet burst error window */
#define RBME_CRCW_CFG2_CRC_EC_SPKT_WND(x)        (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG2_CRC_EC_SPKT_WND_SHIFT)) & RBME_CRCW_CFG2_CRC_EC_SPKT_WND_MASK)

#define RBME_CRCW_CFG2_CRC_EC_LPKT_WND_MASK      (0xF000U)
#define RBME_CRCW_CFG2_CRC_EC_LPKT_WND_SHIFT     (12U)
/*! CRC_EC_LPKT_WND - Error correction long packet burst error window */
#define RBME_CRCW_CFG2_CRC_EC_LPKT_WND(x)        (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG2_CRC_EC_LPKT_WND_SHIFT)) & RBME_CRCW_CFG2_CRC_EC_LPKT_WND_MASK)
/*! @} */

/*! @name CRCW_CFG3 - CRC CONFIGURATION */
/*! @{ */

#define RBME_CRCW_CFG3_CRC_SZ_MASK               (0x7U)
#define RBME_CRCW_CFG3_CRC_SZ_SHIFT              (0U)
/*! CRC_SZ - CRC Size (in octets) */
#define RBME_CRCW_CFG3_CRC_SZ(x)                 (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG3_CRC_SZ_SHIFT)) & RBME_CRCW_CFG3_CRC_SZ_MASK)

#define RBME_CRCW_CFG3_CRC_START_BYTE_MASK       (0xF00U)
#define RBME_CRCW_CFG3_CRC_START_BYTE_SHIFT      (8U)
/*! CRC_START_BYTE - Configure CRC Start Point */
#define RBME_CRCW_CFG3_CRC_START_BYTE(x)         (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG3_CRC_START_BYTE_SHIFT)) & RBME_CRCW_CFG3_CRC_START_BYTE_MASK)

#define RBME_CRCW_CFG3_CRC_REF_IN_MASK           (0x10000U)
#define RBME_CRCW_CFG3_CRC_REF_IN_SHIFT          (16U)
/*! CRC_REF_IN - CRC Reflect In
 *  0b0..Does not manipulate input data stream
 *  0b1..reflect each byte in the input stream bitwise
 */
#define RBME_CRCW_CFG3_CRC_REF_IN(x)             (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG3_CRC_REF_IN_SHIFT)) & RBME_CRCW_CFG3_CRC_REF_IN_MASK)

#define RBME_CRCW_CFG3_CRC_REF_OUT_MASK          (0x20000U)
#define RBME_CRCW_CFG3_CRC_REF_OUT_SHIFT         (17U)
/*! CRC_REF_OUT - CRC Reflect Out
 *  0b0..Does not manipulate CRC result
 *  0b1..CRC result is to be reflected bitwise (operated on entire word)
 */
#define RBME_CRCW_CFG3_CRC_REF_OUT(x)            (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG3_CRC_REF_OUT_SHIFT)) & RBME_CRCW_CFG3_CRC_REF_OUT_MASK)

#define RBME_CRCW_CFG3_CRC_BYTE_ORD_MASK         (0x40000U)
#define RBME_CRCW_CFG3_CRC_BYTE_ORD_SHIFT        (18U)
/*! CRC_BYTE_ORD - CRC Byte Order
 *  0b0..LS Byte First
 *  0b1..MS Byte First
 */
#define RBME_CRCW_CFG3_CRC_BYTE_ORD(x)           (((uint32_t)(((uint32_t)(x)) << RBME_CRCW_CFG3_CRC_BYTE_ORD_SHIFT)) & RBME_CRCW_CFG3_CRC_BYTE_ORD_MASK)
/*! @} */

/*! @name CRC_INIT - CRC INITIALIZATION */
/*! @{ */

#define RBME_CRC_INIT_CRC_SEED_MASK              (0xFFFFFFFFU)
#define RBME_CRC_INIT_CRC_SEED_SHIFT             (0U)
/*! CRC_SEED - CRC Seed Value */
#define RBME_CRC_INIT_CRC_SEED(x)                (((uint32_t)(((uint32_t)(x)) << RBME_CRC_INIT_CRC_SEED_SHIFT)) & RBME_CRC_INIT_CRC_SEED_MASK)
/*! @} */

/*! @name CRC_POLY - CRC POLYNOMIAL */
/*! @{ */

#define RBME_CRC_POLY_CRC_POLY_MASK              (0xFFFFFFFFU)
#define RBME_CRC_POLY_CRC_POLY_SHIFT             (0U)
/*! CRC_POLY - CRC Polynomial. */
#define RBME_CRC_POLY_CRC_POLY(x)                (((uint32_t)(((uint32_t)(x)) << RBME_CRC_POLY_CRC_POLY_SHIFT)) & RBME_CRC_POLY_CRC_POLY_MASK)
/*! @} */

/*! @name CRC_XOR_OUT - CRC XOR OUT */
/*! @{ */

#define RBME_CRC_XOR_OUT_CRC_XOR_OUT_MASK        (0xFFFFFFFFU)
#define RBME_CRC_XOR_OUT_CRC_XOR_OUT_SHIFT       (0U)
/*! CRC_XOR_OUT - CRC XOR OUT Register */
#define RBME_CRC_XOR_OUT_CRC_XOR_OUT(x)          (((uint32_t)(((uint32_t)(x)) << RBME_CRC_XOR_OUT_CRC_XOR_OUT_SHIFT)) & RBME_CRC_XOR_OUT_CRC_XOR_OUT_MASK)
/*! @} */

/*! @name WHITEN_CFG - WHITENER CONFIGURATION */
/*! @{ */

#define RBME_WHITEN_CFG_WHITEN_START_MASK        (0x3U)
#define RBME_WHITEN_CFG_WHITEN_START_SHIFT       (0U)
/*! WHITEN_START - Configure Whitener Start Point
 *  0b00..no whitening
 *  0b01..start whitening at start-of-H0
 *  0b10..start whitening at start-of-H1 but only if LENGTH > WHITEN_SZ_THR
 *  0b11..start whitening at start-of-payload but only if LENGTH > WHITEN_SZ_THR
 */
#define RBME_WHITEN_CFG_WHITEN_START(x)          (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_START_SHIFT)) & RBME_WHITEN_CFG_WHITEN_START_MASK)

#define RBME_WHITEN_CFG_WHITEN_END_MASK          (0x4U)
#define RBME_WHITEN_CFG_WHITEN_END_SHIFT         (2U)
/*! WHITEN_END - Configure end-of-whitening
 *  0b0..end whiten at end-of-payload
 *  0b1..end whiten at end-of-crc
 */
#define RBME_WHITEN_CFG_WHITEN_END(x)            (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_END_SHIFT)) & RBME_WHITEN_CFG_WHITEN_END_MASK)

#define RBME_WHITEN_CFG_WHITEN_B4_CRC_MASK       (0x8U)
#define RBME_WHITEN_CFG_WHITEN_B4_CRC_SHIFT      (3U)
/*! WHITEN_B4_CRC - Configure for Whitening-before-CRC
 *  0b0..CRC before whiten/de-whiten
 *  0b1..Whiten/de-whiten before CRC
 */
#define RBME_WHITEN_CFG_WHITEN_B4_CRC(x)         (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_B4_CRC_SHIFT)) & RBME_WHITEN_CFG_WHITEN_B4_CRC_MASK)

#define RBME_WHITEN_CFG_WHITEN_POLY_TYPE_MASK    (0x10U)
#define RBME_WHITEN_CFG_WHITEN_POLY_TYPE_SHIFT   (4U)
/*! WHITEN_POLY_TYPE - Whiten Polynomial Type */
#define RBME_WHITEN_CFG_WHITEN_POLY_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_POLY_TYPE_SHIFT)) & RBME_WHITEN_CFG_WHITEN_POLY_TYPE_MASK)

#define RBME_WHITEN_CFG_WHITEN_REF_IN_MASK       (0x20U)
#define RBME_WHITEN_CFG_WHITEN_REF_IN_SHIFT      (5U)
/*! WHITEN_REF_IN - Whiten Reflect Input */
#define RBME_WHITEN_CFG_WHITEN_REF_IN(x)         (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_REF_IN_SHIFT)) & RBME_WHITEN_CFG_WHITEN_REF_IN_MASK)

#define RBME_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_MASK (0x40U)
#define RBME_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_SHIFT (6U)
/*! WHITEN_PAYLOAD_REINIT - Configure for Whitener re-initialization
 *  0b0..Does not re-initialize Whitener LFSR at start-of-payload
 *  0b1..Re-initialize Whitener LFSR at start-of-payload
 */
#define RBME_WHITEN_CFG_WHITEN_PAYLOAD_REINIT(x) (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_SHIFT)) & RBME_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_MASK)

#define RBME_WHITEN_CFG_WHITEN_SIZE_MASK         (0xF00U)
#define RBME_WHITEN_CFG_WHITEN_SIZE_SHIFT        (8U)
/*! WHITEN_SIZE - Length of Whitener LFSR */
#define RBME_WHITEN_CFG_WHITEN_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_SIZE_SHIFT)) & RBME_WHITEN_CFG_WHITEN_SIZE_MASK)

#define RBME_WHITEN_CFG_WHITEN_INIT_MASK         (0x1FF0000U)
#define RBME_WHITEN_CFG_WHITEN_INIT_SHIFT        (16U)
/*! WHITEN_INIT - Initialization value for whitening/de-whitening */
#define RBME_WHITEN_CFG_WHITEN_INIT(x)           (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_CFG_WHITEN_INIT_SHIFT)) & RBME_WHITEN_CFG_WHITEN_INIT_MASK)
/*! @} */

/*! @name WHITEN_POLY - WHITENER POLYNOMIAL */
/*! @{ */

#define RBME_WHITEN_POLY_WHITEN_POLY_MASK        (0x1FFU)
#define RBME_WHITEN_POLY_WHITEN_POLY_SHIFT       (0U)
/*! WHITEN_POLY - Whitener Polynomial */
#define RBME_WHITEN_POLY_WHITEN_POLY(x)          (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_POLY_WHITEN_POLY_SHIFT)) & RBME_WHITEN_POLY_WHITEN_POLY_MASK)
/*! @} */

/*! @name WHITEN_SZ_THR - WHITENER SIZE THRESHOLD */
/*! @{ */

#define RBME_WHITEN_SZ_THR_WHITEN_SZ_THR_MASK    (0xFFFU)
#define RBME_WHITEN_SZ_THR_WHITEN_SZ_THR_SHIFT   (0U)
/*! WHITEN_SZ_THR - Whitener Size Threshold */
#define RBME_WHITEN_SZ_THR_WHITEN_SZ_THR(x)      (((uint32_t)(((uint32_t)(x)) << RBME_WHITEN_SZ_THR_WHITEN_SZ_THR_SHIFT)) & RBME_WHITEN_SZ_THR_WHITEN_SZ_THR_MASK)
/*! @} */

/*! @name FEC_CFG1 - FEC CONFIG 1 */
/*! @{ */

#define RBME_FEC_CFG1_FEC_EN_MASK                (0x1U)
#define RBME_FEC_CFG1_FEC_EN_SHIFT               (0U)
/*! FEC_EN - FEC enable
 *  0b0..Disable FEC encoder and decoder
 *  0b1..Enable FEC encoder and decoder
 */
#define RBME_FEC_CFG1_FEC_EN(x)                  (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG1_FEC_EN_SHIFT)) & RBME_FEC_CFG1_FEC_EN_MASK)

#define RBME_FEC_CFG1_FEC_SWAP_MASK              (0x2U)
#define RBME_FEC_CFG1_FEC_SWAP_SHIFT             (1U)
/*! FEC_SWAP - FEC output swap */
#define RBME_FEC_CFG1_FEC_SWAP(x)                (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG1_FEC_SWAP_SHIFT)) & RBME_FEC_CFG1_FEC_SWAP_MASK)

#define RBME_FEC_CFG1_FECOV_EN_MASK              (0x4U)
#define RBME_FEC_CFG1_FECOV_EN_SHIFT             (2U)
/*! FECOV_EN - Enable dynamic override of FEC
 *  0b0..Disable FEC override
 *  0b1..The override of FEC is only used in Bluetooth LE LR cases, dynamically depending on the LR AA detected
 */
#define RBME_FEC_CFG1_FECOV_EN(x)                (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG1_FECOV_EN_SHIFT)) & RBME_FEC_CFG1_FECOV_EN_MASK)

#define RBME_FEC_CFG1_INTV_EN_MASK               (0x10U)
#define RBME_FEC_CFG1_INTV_EN_SHIFT              (4U)
/*! INTV_EN - Enable interleaver register */
#define RBME_FEC_CFG1_INTV_EN(x)                 (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG1_INTV_EN_SHIFT)) & RBME_FEC_CFG1_INTV_EN_MASK)

#define RBME_FEC_CFG1_FEC_START_BYTE_MASK        (0xE0U)
#define RBME_FEC_CFG1_FEC_START_BYTE_SHIFT       (5U)
/*! FEC_START_BYTE - FEC Start Byte */
#define RBME_FEC_CFG1_FEC_START_BYTE(x)          (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG1_FEC_START_BYTE_SHIFT)) & RBME_FEC_CFG1_FEC_START_BYTE_MASK)

#define RBME_FEC_CFG1_NTERM_MASK                 (0x700U)
#define RBME_FEC_CFG1_NTERM_SHIFT                (8U)
/*! NTERM - Number of term bits */
#define RBME_FEC_CFG1_NTERM(x)                   (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG1_NTERM_SHIFT)) & RBME_FEC_CFG1_NTERM_MASK)
/*! @} */

/*! @name RBME_RST - RBME SOFT RESET */
/*! @{ */

#define RBME_RBME_RST_RBME_RST_MASK              (0x1U)
#define RBME_RBME_RST_RBME_RST_SHIFT             (0U)
/*! RBME_RST - RBME reset signal
 *  0b0..Disable soft reset
 *  0b1..Enable soft reset. When this bit is write to 1, the soft reset to RBME happens immediately. Then all
 *       internal registers and functions will be reset.
 */
#define RBME_RBME_RST_RBME_RST(x)                (((uint32_t)(((uint32_t)(x)) << RBME_RBME_RST_RBME_RST_SHIFT)) & RBME_RBME_RST_RBME_RST_MASK)

#define RBME_RBME_RST_RBME_CLK_EN_OVRD_MASK      (0x2U)
#define RBME_RBME_RST_RBME_CLK_EN_OVRD_SHIFT     (1U)
/*! RBME_CLK_EN_OVRD - RBME Clock Enable override */
#define RBME_RBME_RST_RBME_CLK_EN_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << RBME_RBME_RST_RBME_CLK_EN_OVRD_SHIFT)) & RBME_RBME_RST_RBME_CLK_EN_OVRD_MASK)
/*! @} */

/*! @name FEC_CFG2 - FEC CONFIG 2 */
/*! @{ */

#define RBME_FEC_CFG2_TB_LENGTH_MASK             (0x1FU)
#define RBME_FEC_CFG2_TB_LENGTH_SHIFT            (0U)
/*! TB_LENGTH - Trace-back length */
#define RBME_FEC_CFG2_TB_LENGTH(x)               (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG2_TB_LENGTH_SHIFT)) & RBME_FEC_CFG2_TB_LENGTH_MASK)

#define RBME_FEC_CFG2_SAT_VL_MASK                (0xFF00U)
#define RBME_FEC_CFG2_SAT_VL_SHIFT               (8U)
/*! SAT_VL - Saturation value for PM */
#define RBME_FEC_CFG2_SAT_VL(x)                  (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG2_SAT_VL_SHIFT)) & RBME_FEC_CFG2_SAT_VL_MASK)

#define RBME_FEC_CFG2_LARGE_VL_MASK              (0x7F0000U)
#define RBME_FEC_CFG2_LARGE_VL_SHIFT             (16U)
/*! LARGE_VL - Large value used at startup phase, assigned to the initial PMs. */
#define RBME_FEC_CFG2_LARGE_VL(x)                (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG2_LARGE_VL_SHIFT)) & RBME_FEC_CFG2_LARGE_VL_MASK)

#define RBME_FEC_CFG2_SDIDX_MASK                 (0x7000000U)
#define RBME_FEC_CFG2_SDIDX_SHIFT                (24U)
/*! SDIDX - Index of startup state. PM(startStIdx)=0 */
#define RBME_FEC_CFG2_SDIDX(x)                   (((uint32_t)(((uint32_t)(x)) << RBME_FEC_CFG2_SDIDX_SHIFT)) & RBME_FEC_CFG2_SDIDX_MASK)
/*! @} */

/*! @name SPREAD_CFG - SPREADER CONFIG */
/*! @{ */

#define RBME_SPREAD_CFG_SP_EN_MASK               (0x1U)
#define RBME_SPREAD_CFG_SP_EN_SHIFT              (0U)
/*! SP_EN - Spreader Enable bit
 *  0b0..Disable spreader
 *  0b1..Enable spreader
 */
#define RBME_SPREAD_CFG_SP_EN(x)                 (((uint32_t)(((uint32_t)(x)) << RBME_SPREAD_CFG_SP_EN_SHIFT)) & RBME_SPREAD_CFG_SP_EN_MASK)

#define RBME_SPREAD_CFG_SPOV_EN_MASK             (0x2U)
#define RBME_SPREAD_CFG_SPOV_EN_SHIFT            (1U)
/*! SPOV_EN - Spreader Override Enable
 *  0b0..Does not allow active override of the spreading enable
 *  0b1..Allows active override of the spreading enable
 */
#define RBME_SPREAD_CFG_SPOV_EN(x)               (((uint32_t)(((uint32_t)(x)) << RBME_SPREAD_CFG_SPOV_EN_SHIFT)) & RBME_SPREAD_CFG_SPOV_EN_MASK)

#define RBME_SPREAD_CFG_CI_TX_MASK               (0x4U)
#define RBME_SPREAD_CFG_CI_TX_SHIFT              (2U)
/*! CI_TX - Bluetooth LE
 *  0b0..FEC Block 2 coded using S=8
 *  0b1..FEC Block 2 coded using S=2
 */
#define RBME_SPREAD_CFG_CI_TX(x)                 (((uint32_t)(((uint32_t)(x)) << RBME_SPREAD_CFG_CI_TX_SHIFT)) & RBME_SPREAD_CFG_CI_TX_MASK)

#define RBME_SPREAD_CFG_SP_START_BYTE_MASK       (0x38U)
#define RBME_SPREAD_CFG_SP_START_BYTE_SHIFT      (3U)
/*! SP_START_BYTE - Spread Start Byte */
#define RBME_SPREAD_CFG_SP_START_BYTE(x)         (((uint32_t)(((uint32_t)(x)) << RBME_SPREAD_CFG_SP_START_BYTE_SHIFT)) & RBME_SPREAD_CFG_SP_START_BYTE_MASK)

#define RBME_SPREAD_CFG_SP_FACTOR_MASK           (0x700U)
#define RBME_SPREAD_CFG_SP_FACTOR_SHIFT          (8U)
/*! SP_FACTOR - Spreading Factor
 *  0b000..Factor = 1(No spreading and despreading)
 *  0b001..Factor = 2
 *  0b010..Factor = 4
 *  0b011..Factor = 8
 *  0b100..Factor = 16
 */
#define RBME_SPREAD_CFG_SP_FACTOR(x)             (((uint32_t)(((uint32_t)(x)) << RBME_SPREAD_CFG_SP_FACTOR_SHIFT)) & RBME_SPREAD_CFG_SP_FACTOR_MASK)

#define RBME_SPREAD_CFG_SP_SEQ_MASK              (0xFFFF0000U)
#define RBME_SPREAD_CFG_SP_SEQ_SHIFT             (16U)
/*! SP_SEQ - Spreading Bit Sequence */
#define RBME_SPREAD_CFG_SP_SEQ(x)                (((uint32_t)(((uint32_t)(x)) << RBME_SPREAD_CFG_SP_SEQ_SHIFT)) & RBME_SPREAD_CFG_SP_SEQ_MASK)
/*! @} */

/*! @name WHT_CFG - WHITEN CONFIG */
/*! @{ */

#define RBME_WHT_CFG_W1_EN_MASK                  (0x1U)
#define RBME_WHT_CFG_W1_EN_SHIFT                 (0U)
/*! W1_EN - Enable first whitener */
#define RBME_WHT_CFG_W1_EN(x)                    (((uint32_t)(((uint32_t)(x)) << RBME_WHT_CFG_W1_EN_SHIFT)) & RBME_WHT_CFG_W1_EN_MASK)

#define RBME_WHT_CFG_WFIRST_MASK                 (0x4U)
#define RBME_WHT_CFG_WFIRST_SHIFT                (2U)
/*! WFIRST - Whitens before CRC */
#define RBME_WHT_CFG_WFIRST(x)                   (((uint32_t)(((uint32_t)(x)) << RBME_WHT_CFG_WFIRST_SHIFT)) & RBME_WHT_CFG_WFIRST_MASK)

#define RBME_WHT_CFG_WTOV_EN_MASK                (0x8U)
#define RBME_WHT_CFG_WTOV_EN_SHIFT               (3U)
/*! WTOV_EN - Allows overwrite of the whitening */
#define RBME_WHT_CFG_WTOV_EN(x)                  (((uint32_t)(((uint32_t)(x)) << RBME_WHT_CFG_WTOV_EN_SHIFT)) & RBME_WHT_CFG_WTOV_EN_MASK)

#define RBME_WHT_CFG_WT_OUT_SEL_MASK             (0xF000U)
#define RBME_WHT_CFG_WT_OUT_SEL_SHIFT            (12U)
/*! WT_OUT_SEL - Selected Output */
#define RBME_WHT_CFG_WT_OUT_SEL(x)               (((uint32_t)(((uint32_t)(x)) << RBME_WHT_CFG_WT_OUT_SEL_SHIFT)) & RBME_WHT_CFG_WT_OUT_SEL_MASK)

#define RBME_WHT_CFG_WT_TPOGY_MASK               (0x3000000U)
#define RBME_WHT_CFG_WT_TPOGY_SHIFT              (24U)
/*! WT_TPOGY - Whiten 1 Polynomial Type */
#define RBME_WHT_CFG_WT_TPOGY(x)                 (((uint32_t)(((uint32_t)(x)) << RBME_WHT_CFG_WT_TPOGY_SHIFT)) & RBME_WHT_CFG_WT_TPOGY_MASK)
/*! @} */

/*! @name PKT_SZ - PACKET SIZE */
/*! @{ */

#define RBME_PKT_SZ_MAX_PKT_SZ_MASK              (0xFFFFU)
#define RBME_PKT_SZ_MAX_PKT_SZ_SHIFT             (0U)
/*! MAX_PKT_SZ - Maximum Packet Size In Bits */
#define RBME_PKT_SZ_MAX_PKT_SZ(x)                (((uint32_t)(((uint32_t)(x)) << RBME_PKT_SZ_MAX_PKT_SZ_SHIFT)) & RBME_PKT_SZ_MAX_PKT_SZ_MASK)

#define RBME_PKT_SZ_DEF_PKT_SZ_MASK              (0xFFFF0000U)
#define RBME_PKT_SZ_DEF_PKT_SZ_SHIFT             (16U)
/*! DEF_PKT_SZ - Default Packet Size */
#define RBME_PKT_SZ_DEF_PKT_SZ(x)                (((uint32_t)(((uint32_t)(x)) << RBME_PKT_SZ_DEF_PKT_SZ_SHIFT)) & RBME_PKT_SZ_DEF_PKT_SZ_MASK)
/*! @} */

/*! @name CRC_PHR_SZ - LENGTH OF PHR CONFIG */
/*! @{ */

#define RBME_CRC_PHR_SZ_PHR_SZ_MASK              (0xFU)
#define RBME_CRC_PHR_SZ_PHR_SZ_SHIFT             (0U)
/*! PHR_SZ - PHR Size Config */
#define RBME_CRC_PHR_SZ_PHR_SZ(x)                (((uint32_t)(((uint32_t)(x)) << RBME_CRC_PHR_SZ_PHR_SZ_SHIFT)) & RBME_CRC_PHR_SZ_PHR_SZ_MASK)
/*! @} */

/*! @name FCP_CFG - FCP SUPPORT CONFIG */
/*! @{ */

#define RBME_FCP_CFG_FCP_SUPPORT_MASK            (0x1U)
#define RBME_FCP_CFG_FCP_SUPPORT_SHIFT           (0U)
/*! FCP_SUPPORT - FCP Support
 *  0b0..Disable FCP support
 *  0b1..Enable FCP support
 */
#define RBME_FCP_CFG_FCP_SUPPORT(x)              (((uint32_t)(((uint32_t)(x)) << RBME_FCP_CFG_FCP_SUPPORT_SHIFT)) & RBME_FCP_CFG_FCP_SUPPORT_MASK)
/*! @} */

/*! @name FRAME_OVER_SZ - FRAME OVERRIDE SIZE */
/*! @{ */

#define RBME_FRAME_OVER_SZ_STD_FRM_OV_EN_MASK    (0x1U)
#define RBME_FRAME_OVER_SZ_STD_FRM_OV_EN_SHIFT   (0U)
/*! STD_FRM_OV_EN - Overrides active STD frame length from link layer enable bit
 *  0b0..Disable override active STD frame length from link layer
 *  0b1..Enable override active STD frame length from link layer
 */
#define RBME_FRAME_OVER_SZ_STD_FRM_OV_EN(x)      (((uint32_t)(((uint32_t)(x)) << RBME_FRAME_OVER_SZ_STD_FRM_OV_EN_SHIFT)) & RBME_FRAME_OVER_SZ_STD_FRM_OV_EN_MASK)

#define RBME_FRAME_OVER_SZ_STD_FRM_OV_MASK       (0x7FF0000U)
#define RBME_FRAME_OVER_SZ_STD_FRM_OV_SHIFT      (16U)
/*! STD_FRM_OV - Value to override the STD frame length (bits) */
#define RBME_FRAME_OVER_SZ_STD_FRM_OV(x)         (((uint32_t)(((uint32_t)(x)) << RBME_FRAME_OVER_SZ_STD_FRM_OV_SHIFT)) & RBME_FRAME_OVER_SZ_STD_FRM_OV_MASK)
/*! @} */

/*! @name FEC_BSZ_OV_B4SP - OVERRIDE OF FEC BLOCK SIZE */
/*! @{ */

#define RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_B4SP_EN_MASK (0x1U)
#define RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_B4SP_EN_SHIFT (0U)
/*! FEC_BSZ_OV_B4SP_EN - Override of the FEC block size for data
 *  0b0..Disable Override actvie STD frame length from link layer
 *  0b1..Enable Override actvie STD frame length from link layer
 */
#define RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_B4SP_EN(x) (((uint32_t)(((uint32_t)(x)) << RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_B4SP_EN_SHIFT)) & RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_B4SP_EN_MASK)

#define RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_MASK     (0xFFFF0000U)
#define RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_SHIFT    (16U)
/*! FEC_BSZ_OV - Value of the override in bits. It is for test purpose. */
#define RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV(x)       (((uint32_t)(((uint32_t)(x)) << RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_SHIFT)) & RBME_FEC_BSZ_OV_B4SP_FEC_BSZ_OV_MASK)
/*! @} */

/*! @name LEG0_CFG - LEG0 CONFIG */
/*! @{ */

#define RBME_LEG0_CFG_LEG0_INV_EN_MASK           (0x1U)
#define RBME_LEG0_CFG_LEG0_INV_EN_SHIFT          (0U)
/*! LEG0_INV_EN - Whiten invert enable bit
 *  0b0..Disable whiten invert for LEG0
 *  0b1..Enable whiten invert for LEG0
 */
#define RBME_LEG0_CFG_LEG0_INV_EN(x)             (((uint32_t)(((uint32_t)(x)) << RBME_LEG0_CFG_LEG0_INV_EN_SHIFT)) & RBME_LEG0_CFG_LEG0_INV_EN_MASK)

#define RBME_LEG0_CFG_LEG0_SUP_MASK              (0x2U)
#define RBME_LEG0_CFG_LEG0_SUP_SHIFT             (1U)
/*! LEG0_SUP - LEG0 support
 *  0b0..Disable LEG0 support
 *  0b1..Enable LEG0 support
 */
#define RBME_LEG0_CFG_LEG0_SUP(x)                (((uint32_t)(((uint32_t)(x)) << RBME_LEG0_CFG_LEG0_SUP_SHIFT)) & RBME_LEG0_CFG_LEG0_SUP_MASK)

#define RBME_LEG0_CFG_LEG0_XOR_BYTE_MASK         (0xFF00U)
#define RBME_LEG0_CFG_LEG0_XOR_BYTE_SHIFT        (8U)
/*! LEG0_XOR_BYTE - LEG0 whitening masking byte */
#define RBME_LEG0_CFG_LEG0_XOR_BYTE(x)           (((uint32_t)(((uint32_t)(x)) << RBME_LEG0_CFG_LEG0_XOR_BYTE_SHIFT)) & RBME_LEG0_CFG_LEG0_XOR_BYTE_MASK)

#define RBME_LEG0_CFG_LEG0_XOR_RP_BYTE_MASK      (0xFF0000U)
#define RBME_LEG0_CFG_LEG0_XOR_RP_BYTE_SHIFT     (16U)
/*! LEG0_XOR_RP_BYTE - LEG0 repeat bytes masking */
#define RBME_LEG0_CFG_LEG0_XOR_RP_BYTE(x)        (((uint32_t)(((uint32_t)(x)) << RBME_LEG0_CFG_LEG0_XOR_RP_BYTE_SHIFT)) & RBME_LEG0_CFG_LEG0_XOR_RP_BYTE_MASK)

#define RBME_LEG0_CFG_LEG0_XOR_FST_BYTE_MASK     (0xFF000000U)
#define RBME_LEG0_CFG_LEG0_XOR_FST_BYTE_SHIFT    (24U)
/*! LEG0_XOR_FST_BYTE - FEC first byte masking */
#define RBME_LEG0_CFG_LEG0_XOR_FST_BYTE(x)       (((uint32_t)(((uint32_t)(x)) << RBME_LEG0_CFG_LEG0_XOR_FST_BYTE_SHIFT)) & RBME_LEG0_CFG_LEG0_XOR_FST_BYTE_MASK)
/*! @} */

/*! @name NPAYL_OVER_SZ - OVERRIDE PAYLOAD */
/*! @{ */

#define RBME_NPAYL_OVER_SZ_NPAYL_OV_EN_MASK      (0x1U)
#define RBME_NPAYL_OVER_SZ_NPAYL_OV_EN_SHIFT     (0U)
/*! NPAYL_OV_EN - Override the internal payload length computation
 *  0b0..Disable override the internal payload length
 *  0b1..Enable override the internal payload length
 */
#define RBME_NPAYL_OVER_SZ_NPAYL_OV_EN(x)        (((uint32_t)(((uint32_t)(x)) << RBME_NPAYL_OVER_SZ_NPAYL_OV_EN_SHIFT)) & RBME_NPAYL_OVER_SZ_NPAYL_OV_EN_MASK)

#define RBME_NPAYL_OVER_SZ_FT_FEC_FLUSH_MASK     (0x1F00U)
#define RBME_NPAYL_OVER_SZ_FT_FEC_FLUSH_SHIFT    (8U)
/*! FT_FEC_FLUSH - Value to override the payload length (bits) */
#define RBME_NPAYL_OVER_SZ_FT_FEC_FLUSH(x)       (((uint32_t)(((uint32_t)(x)) << RBME_NPAYL_OVER_SZ_FT_FEC_FLUSH_SHIFT)) & RBME_NPAYL_OVER_SZ_FT_FEC_FLUSH_MASK)

#define RBME_NPAYL_OVER_SZ_NPAYL_OV_MASK         (0x7FF0000U)
#define RBME_NPAYL_OVER_SZ_NPAYL_OV_SHIFT        (16U)
#define RBME_NPAYL_OVER_SZ_NPAYL_OV(x)           (((uint32_t)(((uint32_t)(x)) << RBME_NPAYL_OVER_SZ_NPAYL_OV_SHIFT)) & RBME_NPAYL_OVER_SZ_NPAYL_OV_MASK)
/*! @} */

/*! @name RAM_S_ADDR - PACKET RAM SOURCE ADDRESS */
/*! @{ */

#define RBME_RAM_S_ADDR_RAM_S_ADDR_MASK          (0x3FFFU)
#define RBME_RAM_S_ADDR_RAM_S_ADDR_SHIFT         (0U)
/*! RAM_S_ADDR - Packet RAM source address. This address is ram physical address. */
#define RBME_RAM_S_ADDR_RAM_S_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << RBME_RAM_S_ADDR_RAM_S_ADDR_SHIFT)) & RBME_RAM_S_ADDR_RAM_S_ADDR_MASK)
/*! @} */

/*! @name RAM_D_ADDR - PACKET RAM DESTINATION ADDRESS */
/*! @{ */

#define RBME_RAM_D_ADDR_RAM_D_ADDR_MASK          (0x3FFFU)
#define RBME_RAM_D_ADDR_RAM_D_ADDR_SHIFT         (0U)
/*! RAM_D_ADDR - Packet RAM destination address, this address is ram physical address. */
#define RBME_RAM_D_ADDR_RAM_D_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << RBME_RAM_D_ADDR_RAM_D_ADDR_SHIFT)) & RBME_RAM_D_ADDR_RAM_D_ADDR_MASK)
/*! @} */

/*! @name RAM_IF_CFG - PACKET RAM INTERFACE CONFIG */
/*! @{ */

#define RBME_RAM_IF_CFG_RAM_IF_TX_EN_MASK        (0x1U)
#define RBME_RAM_IF_CFG_RAM_IF_TX_EN_SHIFT       (0U)
/*! RAM_IF_TX_EN - RAM interface TX enable bit
 *  0b0..Disable RAM interface TX
 *  0b1..Enable RAM interface TX
 */
#define RBME_RAM_IF_CFG_RAM_IF_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_RAM_IF_TX_EN_SHIFT)) & RBME_RAM_IF_CFG_RAM_IF_TX_EN_MASK)

#define RBME_RAM_IF_CFG_RAM_IF_RX_EN_MASK        (0x2U)
#define RBME_RAM_IF_CFG_RAM_IF_RX_EN_SHIFT       (1U)
/*! RAM_IF_RX_EN - RAM interface RX enable
 *  0b0..Disable RAM interface RX
 *  0b1..Enable RAM interface RX
 */
#define RBME_RAM_IF_CFG_RAM_IF_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_RAM_IF_RX_EN_SHIFT)) & RBME_RAM_IF_CFG_RAM_IF_RX_EN_MASK)

#define RBME_RAM_IF_CFG_RAM_IF_IE_MASK           (0x10U)
#define RBME_RAM_IF_CFG_RAM_IF_IE_SHIFT          (4U)
/*! RAM_IF_IE - RAM interface interrupt enable bit
 *  0b0..Disable RAM interface interrupt
 *  0b1..Enable RAM interface interrupt
 */
#define RBME_RAM_IF_CFG_RAM_IF_IE(x)             (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_RAM_IF_IE_SHIFT)) & RBME_RAM_IF_CFG_RAM_IF_IE_MASK)

#define RBME_RAM_IF_CFG_RAM_IF_IC_MASK           (0x20U)
#define RBME_RAM_IF_CFG_RAM_IF_IC_SHIFT          (5U)
/*! RAM_IF_IC - RAM interface interrupt clear
 *  0b0..To do nothing to RAM interface interrupt
 *  0b1..To clear RAM interface interrupt
 */
#define RBME_RAM_IF_CFG_RAM_IF_IC(x)             (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_RAM_IF_IC_SHIFT)) & RBME_RAM_IF_CFG_RAM_IF_IC_MASK)

#define RBME_RAM_IF_CFG_H2S_EN_MASK              (0x40U)
#define RBME_RAM_IF_CFG_H2S_EN_SHIFT             (6U)
/*! H2S_EN - Hard bit convert to soft bit enable
 *  0b0..Disable hard bit to soft bits conversion
 *  0b1..Enable hard bit to soft bits conversion
 */
#define RBME_RAM_IF_CFG_H2S_EN(x)                (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_H2S_EN_SHIFT)) & RBME_RAM_IF_CFG_H2S_EN_MASK)

#define RBME_RAM_IF_CFG_SOFT_HD_SEL_RD_MASK      (0x100U)
#define RBME_RAM_IF_CFG_SOFT_HD_SEL_RD_SHIFT     (8U)
/*! SOFT_HD_SEL_RD - Soft and hard bit selection of write operation
 *  0b0..Hard bit selection of write operation
 *  0b1..Soft bit selection of write operation
 */
#define RBME_RAM_IF_CFG_SOFT_HD_SEL_RD(x)        (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_SOFT_HD_SEL_RD_SHIFT)) & RBME_RAM_IF_CFG_SOFT_HD_SEL_RD_MASK)

#define RBME_RAM_IF_CFG_SOFT_HD_SEL_WR_MASK      (0x200U)
#define RBME_RAM_IF_CFG_SOFT_HD_SEL_WR_SHIFT     (9U)
/*! SOFT_HD_SEL_WR - Soft and hard bit selection of read operation
 *  0b0..Hard bit selection of read operation
 *  0b1..Soft bit selection of read operation
 */
#define RBME_RAM_IF_CFG_SOFT_HD_SEL_WR(x)        (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_SOFT_HD_SEL_WR_SHIFT)) & RBME_RAM_IF_CFG_SOFT_HD_SEL_WR_MASK)

#define RBME_RAM_IF_CFG_WR_IRQ_MASK              (0x400U)
#define RBME_RAM_IF_CFG_WR_IRQ_SHIFT             (10U)
/*! WR_IRQ - Write to RAM complete flag
 *  0b0..Writing to RAM not complete
 *  0b1..Writing to RAM complete
 */
#define RBME_RAM_IF_CFG_WR_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_WR_IRQ_SHIFT)) & RBME_RAM_IF_CFG_WR_IRQ_MASK)

#define RBME_RAM_IF_CFG_RD_IRQ_MASK              (0x800U)
#define RBME_RAM_IF_CFG_RD_IRQ_SHIFT             (11U)
/*! RD_IRQ - Read to RAM complete flag
 *  0b0..Reading to RAM not complete
 *  0b1..Reading to RAM complete
 */
#define RBME_RAM_IF_CFG_RD_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << RBME_RAM_IF_CFG_RD_IRQ_SHIFT)) & RBME_RAM_IF_CFG_RD_IRQ_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RBME_Register_Masks */


/*!
 * @}
 */ /* end of group RBME_Peripheral_Access_Layer */


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


#endif  /* PERI_RBME_H_ */

