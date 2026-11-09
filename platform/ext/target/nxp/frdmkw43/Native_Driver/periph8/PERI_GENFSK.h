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
**         CMSIS Peripheral Access Layer for GENFSK
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
 * @file PERI_GENFSK.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for GENFSK
 *
 * CMSIS Peripheral Access Layer for GENFSK
 */

#if !defined(PERI_GENFSK_H_)
#define PERI_GENFSK_H_                           /**< Symbol preventing repeated inclusion */

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
   -- GENFSK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GENFSK_Peripheral_Access_Layer GENFSK Peripheral Access Layer
 * @{
 */

/** GENFSK - Register Layout Typedef */
typedef struct {
  __IO uint32_t IRQ_CTRL;                          /**< IRQ CONTROL, offset: 0x0 */
  __I  uint32_t EVENT_TMR;                         /**< EVENT TIMER, offset: 0x4 */
  __IO uint32_t T1_CMP;                            /**< T1 COMPARE, offset: 0x8 */
  __IO uint32_t T2_CMP;                            /**< T2 COMPARE, offset: 0xC */
  __I  uint32_t TIMESTAMP;                         /**< TIMESTAMP, offset: 0x10 */
  __IO uint32_t XCVR_CTRL;                         /**< TRANSCEIVER CONTROL, offset: 0x14 */
  __I  uint32_t XCVR_STS;                          /**< TRANSCEIVER STATUS, offset: 0x18 */
  __IO uint32_t XCVR_CFG;                          /**< TRANSCEIVER CONFIGURATION, offset: 0x1C */
  __IO uint32_t CHANNEL_NUM0;                      /**< CHANNEL NUMBER 0, offset: 0x20 */
  __IO uint32_t TX_POWER;                          /**< TRANSMIT POWER, offset: 0x24 */
  __IO uint32_t NTW_ADR_CTRL;                      /**< NETWORK ADDRESS CONTROL, offset: 0x28 */
  __IO uint32_t NTW_ADR_0;                         /**< NETWORK ADDRESS 0, offset: 0x2C */
  __IO uint32_t NTW_ADR_1;                         /**< NETWORK ADDRESS 1, offset: 0x30 */
       uint8_t RESERVED_0[8];
  __IO uint32_t RX_WATERMARK;                      /**< RECEIVE WATERMARK, offset: 0x3C */
  __IO uint32_t DSM_CTRL;                          /**< DSM CONTROL, offset: 0x40 */
  __I  uint32_t PART_ID;                           /**< PART ID, offset: 0x44 */
  __IO uint32_t SLOT_PRELOAD;                      /**< SLOT PRELOAD, offset: 0x48 */
  __IO uint32_t SLOT_TIME;                         /**< SLOT TIME, offset: 0x4C */
  __IO uint32_t TURNAROUND_TIME;                   /**< TURNAROUND TIME, offset: 0x50 */
  __IO uint32_t ACKDELAY;                          /**< ACK DELAY, offset: 0x54 */
  __IO uint32_t RXDELAY;                           /**< RX DELAY, offset: 0x58 */
  __IO uint32_t TXDELAY;                           /**< TX DELAY, offset: 0x5C */
  __IO uint32_t PACKET_CFG;                        /**< PACKET CONFIGURATION, offset: 0x60 */
  __IO uint32_t H0_CFG;                            /**< H0 CONFIGURATION, offset: 0x64 */
  __IO uint32_t H1_CFG;                            /**< H1 CONFIGURATION, offset: 0x68 */
  __IO uint32_t CRC_CFG;                           /**< CRC CONFIGURATION, offset: 0x6C */
  __IO uint32_t LENGTH_ADJ;                        /**< LENGTH ADJUSTMENT, offset: 0x70 */
  __I  uint32_t TIMESTAMP_RX_DONE;                 /**< TIMESTAMP_RX_DONE, offset: 0x74 */
  __I  uint32_t TIMESTAMP_TX_DONE;                 /**< TIMESTAMP_TX_DONE, offset: 0x78 */
  __IO uint32_t MULT_PKT_CTRL;                     /**< MULT_PKT_CTRL, offset: 0x7C */
  __IO uint32_t RPA_WL_STATUS;                     /**< RPA AND WHITE LIST STATUS, offset: 0x80 */
  __IO uint32_t LENGTH_MAX;                        /**< MAXIMUM LENGTH, offset: 0x84 */
  __O  uint32_t EVENT_TMR_LD;                      /**< EVENT TIMER LOAD, offset: 0x88 */
  __O  uint32_t EVENT_TMR_ADD;                     /**< EVENT TIMER ADD, offset: 0x8C */
  __IO uint32_t ENH_FEATURE;                       /**< ENHANCED FEATURES, offset: 0x90 */
  __IO uint32_t RX_FRAME_FILTER;                   /**< RECEIVE FRAME FILTER, offset: 0x94 */
  __IO uint32_t FILTERFAIL_CODE;                   /**< FILTER FAIL CODE, offset: 0x98 */
  union {                                          /* offset: 0x9C */
    __IO uint32_t LENIENCY_LSB;                      /**< LENIENCY LSB, offset: 0x9C */
    __IO uint32_t RPA_CTRL;                          /**< RPA CONTROL, offset: 0x9C */
  };
  union {                                          /* offset: 0xA0 */
    __IO uint32_t LENIENCY_MSB;                      /**< LENIENCY MSB, offset: 0xA0 */
    __IO uint32_t WL_CTRL;                           /**< WHITE LIST CONTROL, offset: 0xA0 */
  };
  __IO uint32_t DUAL_PAN_CTRL;                     /**< DUAL PAN CONTROL, offset: 0xA4 */
  union {                                          /* offset: 0xA8 */
    __IO uint32_t GTM_PDU;                           /**< GTM MODE PDU, offset: 0xA8 */
    __IO uint32_t MACSHORTADDRS1;                    /**< MAC SHORT ADDRESS FOR PAN1, offset: 0xA8 */
    __IO uint32_t WL_VALID_ENTRY1;                   /**< VALID ENTRY OF WHITE LIST 1, offset: 0xA8 */
  };
  union {                                          /* offset: 0xAC */
    __IO uint32_t DIRECT_PEER_ADDR_LSB;              /**< DIRECT_PEER_ADDR[31:0], offset: 0xAC */
    __IO uint32_t GTM_CFG;                           /**< GTM MODE CONFIGURATION, offset: 0xAC */
    __IO uint32_t MACLONGADDRS1_LSB;                 /**< MAC LONG ADDRESS 1 LSB, offset: 0xAC */
  };
  union {                                          /* offset: 0xB0 */
    __IO uint32_t DIRECT_PEER_ADDR_MSB;              /**< DIRECT_PEER_ADDR[47:32], offset: 0xB0 */
    __IO uint32_t GTM_IPD;                           /**< GTM MODE INTER-PACKET DURATION, offset: 0xB0 */
    __IO uint32_t MACLONGADDRS1_MSB;                 /**< MAC LONG ADDRESS 1 MSB, offset: 0xB0 */
  };
  __IO uint32_t CHANNEL_NUM1;                      /**< CHANNEL NUMBER 1, offset: 0xB4 */
  union {                                          /* offset: 0xB8 */
    __IO uint32_t MACSHORTADDRS0;                    /**< MAC SHORT ADDRESS 0, offset: 0xB8 */
    __IO uint32_t WL_VALID_ENTRY0;                   /**< VALID ENTRY OF WHITE LIST 0, offset: 0xB8 */
  };
  union {                                          /* offset: 0xBC */
    __IO uint32_t GTM_FIRST_SFD2WD;                  /**< GTM MODE TIME OF FIRST SFD FOUND TO FORCE RX WARM-DOWN, offset: 0xBC */
    __IO uint32_t MACLONGADDRS0_LSB;                 /**< MAC LONG ADDRESS 0 LSB, offset: 0xBC */
    __IO uint32_t WL_SEARCH_ADDR_LSB;                /**< WL_SEARCH_ADDR[31:0], offset: 0xBC */
  };
  union {                                          /* offset: 0xC0 */
    __IO uint32_t GTM_RX_RECYCLE_TIME;               /**< GTM MODE RX RECYCLE TIME, offset: 0xC0 */
    __IO uint32_t MACLONGADDRS0_MSB;                 /**< MAC LONG ADDRESS 0 MSB, offset: 0xC0 */
    __IO uint32_t WL_SEARCH_ADDR_MSB;                /**< WL_SEARCH_ADDR[47:32], offset: 0xC0 */
  };
  __IO uint32_t CCA_LQI_CTRL;                      /**< CCA AND LQI CONTROL, offset: 0xC4 */
  __I  uint32_t WARMUP_TIME;                       /**< TX/RX WARMUP TIME, offset: 0xC8 */
  __IO uint32_t RXEN_DLY;                          /**< RX_EN Delay Time, offset: 0xCC */
       uint8_t RESERVED_1[4];
  __IO uint32_t SAM_CTRL;                          /**< SAM CONTROL, offset: 0xD4 */
  __IO uint32_t SAM_TABLE;                         /**< SOURCE ADDRESS MANAGEMENT TABLE, offset: 0xD8 */
  __I  uint32_t SAM_MATCH;                         /**< SOURCE ADDRESS MANAGEMENT MATCH, offset: 0xDC */
  __I  uint32_t SAM_FREE_IDX;                      /**< SAM FREE INDEX, offset: 0xE0 */
  __IO uint32_t MISC1;                             /**< MISCELLANEOUS(1), offset: 0xE4 */
  __I  uint32_t SEQ_STS;                           /**< SEQUENCE STATUS, offset: 0xE8 */
  __IO uint32_t PHR_MISC;                          /**< PHR MISCELLANEOUS, offset: 0xEC */
  __IO uint32_t GTM_CTRL;                          /**< GTM CONTROL, offset: 0xF0 */
  __I  uint32_t GTM_BAD_CNT;                       /**< GTM BAD PACKET COUNTER, offset: 0xF4 */
  __I  uint32_t GTM_GOOD_CNT;                      /**< GTM GOOD PACKET COUNTER, offset: 0xF8 */
  __I  uint32_t GTM_PKT_CNT;                       /**< GTM PACKET COUNTER, offset: 0xFC */
  __IO uint32_t COEX_CTRL;                         /**< COEXISTENCE CONTROL, offset: 0x100 */
  __IO uint32_t COEX_PRIORITY;                     /**< COEXISTENCE PRIORITY, offset: 0x104 */
  __IO uint32_t IRQ_CTRL2;                         /**< IRQ CONTROL 2, offset: 0x108 */
} GENFSK_Type;

/* ----------------------------------------------------------------------------
   -- GENFSK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GENFSK_Register_Masks GENFSK Register Masks
 * @{
 */

/*! @name IRQ_CTRL - IRQ CONTROL */
/*! @{ */

#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_MASK         (0x1U)
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_SHIFT        (0U)
/*! SEQ_END_IRQ - Sequence End Interrupt
 *  0b0..Sequence End Interrupt is not asserted.
 *  0b1..Sequence End Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_SEQ_END_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_SEQ_END_IRQ_MASK)

#define GENFSK_IRQ_CTRL_TX_IRQ_MASK              (0x2U)
#define GENFSK_IRQ_CTRL_TX_IRQ_SHIFT             (1U)
/*! TX_IRQ - TX Interrupt
 *  0b0..TX Interrupt is not asserted.
 *  0b1..TX Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_TX_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TX_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_TX_IRQ_MASK)

#define GENFSK_IRQ_CTRL_RX_IRQ_MASK              (0x4U)
#define GENFSK_IRQ_CTRL_RX_IRQ_SHIFT             (2U)
/*! RX_IRQ - RX Interrupt
 *  0b0..RX Interrupt is not asserted.
 *  0b1..RX Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_RX_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_RX_IRQ_MASK)

#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_MASK         (0x8U)
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_SHIFT        (3U)
/*! NTW_ADR_IRQ - Network Address Match Interrupt
 *  0b0..Network Address Match Interrupt is not asserted.
 *  0b1..Network Address Match Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_NTW_ADR_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_NTW_ADR_IRQ_MASK)

#define GENFSK_IRQ_CTRL_T1_IRQ_MASK              (0x10U)
#define GENFSK_IRQ_CTRL_T1_IRQ_SHIFT             (4U)
/*! T1_IRQ - Timer1 (T1) Compare Interrupt
 *  0b0..Timer1 (T1) Compare Interrupt is not asserted.
 *  0b1..Timer1 (T1) Compare Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_T1_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T1_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_T1_IRQ_MASK)

#define GENFSK_IRQ_CTRL_T2_IRQ_MASK              (0x20U)
#define GENFSK_IRQ_CTRL_T2_IRQ_SHIFT             (5U)
/*! T2_IRQ - Timer2 (T2) Compare Interrupt
 *  0b0..Timer2 (T2) Compare Interrupt is not asserted.
 *  0b1..Timer2 (T2) Compare Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_T2_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T2_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_T2_IRQ_MASK)

#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_MASK      (0x40U)
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_SHIFT     (6U)
/*! PLL_UNLOCK_IRQ - PLL Unlock Interrupt
 *  0b0..PLL Unlock Interrupt is not asserted.
 *  0b1..PLL Unlock Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_MASK)

#define GENFSK_IRQ_CTRL_WAKE_IRQ_MASK            (0x80U)
#define GENFSK_IRQ_CTRL_WAKE_IRQ_SHIFT           (7U)
/*! WAKE_IRQ - Wake Interrupt
 *  0b0..Wake Interrupt is not asserted.
 *  0b1..Wake Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_WAKE_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_WAKE_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_WAKE_IRQ_MASK)

#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_MASK    (0x100U)
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_SHIFT   (8U)
/*! RX_WATERMARK_IRQ - RX Watermark Interrupt
 *  0b0..RX Watermark Interrupt is not asserted.
 *  0b1..RX Watermark Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_MASK)

#define GENFSK_IRQ_CTRL_TSM_IRQ_MASK             (0x200U)
#define GENFSK_IRQ_CTRL_TSM_IRQ_SHIFT            (9U)
/*! TSM_IRQ - TSM Interrupt
 *  0b0..TSM0_IRQ and TSM1_IRQ are both clear.
 *  0b1..Indicates TSM0_IRQ or TSM1_IRQ is set in XCVR_STATUS.
 */
#define GENFSK_IRQ_CTRL_TSM_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TSM_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_TSM_IRQ_MASK)

#define GENFSK_IRQ_CTRL_CRC_VALID_MASK           (0x400U)
#define GENFSK_IRQ_CTRL_CRC_VALID_SHIFT          (10U)
/*! CRC_VALID - CRC Valid */
#define GENFSK_IRQ_CTRL_CRC_VALID(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_CRC_VALID_SHIFT)) & GENFSK_IRQ_CTRL_CRC_VALID_MASK)

#define GENFSK_IRQ_CTRL_ACK_IRQ_MASK             (0x800U)
#define GENFSK_IRQ_CTRL_ACK_IRQ_SHIFT            (11U)
/*! ACK_IRQ - Auto ACK Interrupt
 *  0b0..Auto ACK Interrupt is not asserted.
 *  0b1..Auto ACK Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_ACK_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_ACK_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_ACK_IRQ_MASK)

#define GENFSK_IRQ_CTRL_PHRFFAIL_IRQ_MASK        (0x1000U)
#define GENFSK_IRQ_CTRL_PHRFFAIL_IRQ_SHIFT       (12U)
/*! PHRFFAIL_IRQ - Received Frame PHR Fail Interrupt
 *  0b0..Received frame PHR Fail Interrupt is not asserted.
 *  0b1..Received frame PHR Fail Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_PHRFFAIL_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_PHRFFAIL_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_PHRFFAIL_IRQ_MASK)

#define GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_MASK      (0x2000U)
#define GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_SHIFT     (13U)
/*! FILTERFAIL_IRQ - Received Frame Filter Fail Interrupt
 *  0b0..A Filter Fail Interrupt has not occurred.
 *  0b1..A Filter Fail Interrupt has occurred.
 */
#define GENFSK_IRQ_CTRL_FILTERFAIL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_MASK)

#define GENFSK_IRQ_CTRL_CCA_IRQ_MASK             (0x4000U)
#define GENFSK_IRQ_CTRL_CCA_IRQ_SHIFT            (14U)
/*! CCA_IRQ - CCA Interrupt
 *  0b0..A CCA Interrupt has not occurred
 *  0b1..A CCA Interrupt has occurred
 */
#define GENFSK_IRQ_CTRL_CCA_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_CCA_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_CCA_IRQ_MASK)

#define GENFSK_IRQ_CTRL_MS_IRQ_MASK              (0x8000U)
#define GENFSK_IRQ_CTRL_MS_IRQ_SHIFT             (15U)
/*! MS_IRQ - Mode Switch Interrupt
 *  0b0..A Mode Switch frame is not received
 *  0b1..A Mode Switch frame is received
 */
#define GENFSK_IRQ_CTRL_MS_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_MS_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_MS_IRQ_MASK)

#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_MASK      (0x10000U)
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_SHIFT     (16U)
/*! SEQ_END_IRQ_EN - SEQ_END_IRQ Enable
 *  0b0..Sequence End Interrupt is not enabled.
 *  0b1..Sequence End Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_TX_IRQ_EN_MASK           (0x20000U)
#define GENFSK_IRQ_CTRL_TX_IRQ_EN_SHIFT          (17U)
/*! TX_IRQ_EN - TX_IRQ Enable
 *  0b0..TX Interrupt is not enabled.
 *  0b1..TX Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_TX_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TX_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_TX_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_RX_IRQ_EN_MASK           (0x40000U)
#define GENFSK_IRQ_CTRL_RX_IRQ_EN_SHIFT          (18U)
/*! RX_IRQ_EN - RX_IRQ Enable
 *  0b0..RX Interrupt is not enabled.
 *  0b1..RX Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_RX_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_RX_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_MASK      (0x80000U)
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_SHIFT     (19U)
/*! NTW_ADR_IRQ_EN - NTW_ADR_IRQ Enable
 *  0b0..Network Address Match Interrupt is not enabled.
 *  0b1..Network Address Match Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_T1_IRQ_EN_MASK           (0x100000U)
#define GENFSK_IRQ_CTRL_T1_IRQ_EN_SHIFT          (20U)
/*! T1_IRQ_EN - T1_IRQ Enable
 *  0b0..Timer1 (T1) Compare Interrupt is not enabled.
 *  0b1..Timer1 (T1) Compare Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_T1_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T1_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_T1_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_T2_IRQ_EN_MASK           (0x200000U)
#define GENFSK_IRQ_CTRL_T2_IRQ_EN_SHIFT          (21U)
/*! T2_IRQ_EN - T2_IRQ Enable
 *  0b0..Timer1 (T2) Compare Interrupt is not enabled.
 *  0b1..Timer1 (T2) Compare Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_T2_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T2_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_T2_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_MASK   (0x400000U)
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT  (22U)
/*! PLL_UNLOCK_IRQ_EN - PLL_UNLOCK_IRQ Enable
 *  0b0..PLL Unlock Interrupt is not enabled.
 *  0b1..PLL Unlock Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_WAKE_IRQ_EN_MASK         (0x800000U)
#define GENFSK_IRQ_CTRL_WAKE_IRQ_EN_SHIFT        (23U)
/*! WAKE_IRQ_EN - WAKE_IRQ Enable
 *  0b0..Wake Interrupt is not enabled.
 *  0b1..Wake Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_WAKE_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_WAKE_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_WAKE_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_MASK (0x1000000U)
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_SHIFT (24U)
/*! RX_WATERMARK_IRQ_EN - RX_WATERMARK_IRQ Enable
 *  0b0..RX Watermark Interrupt is not enabled.
 *  0b1..RX Watermark Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_TSM_IRQ_EN_MASK          (0x2000000U)
#define GENFSK_IRQ_CTRL_TSM_IRQ_EN_SHIFT         (25U)
/*! TSM_IRQ_EN - TSM_IRQ Enable
 *  0b0..TSM Interrupt is not enabled.
 *  0b1..TSM Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_TSM_IRQ_EN(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TSM_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_TSM_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_MASK  (0x4000000U)
#define GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_SHIFT (26U)
/*! GENERIC_FSK_IRQ_EN - GENERIC_FSK_IRQ Master Enable
 *  0b0..All GENERIC_FSK Interrupts are disabled.
 *  0b1..All GENERIC_FSK Interrupts can be enabled.
 */
#define GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_ACK_IRQ_EN_MASK          (0x8000000U)
#define GENFSK_IRQ_CTRL_ACK_IRQ_EN_SHIFT         (27U)
/*! ACK_IRQ_EN - ACK_IRQ Enable
 *  0b0..Auto ACK Interrupt is not enabled.
 *  0b1..Auto ACK Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_ACK_IRQ_EN(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_ACK_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_ACK_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_PHRFAIL_IRQ_EN_MASK      (0x10000000U)
#define GENFSK_IRQ_CTRL_PHRFAIL_IRQ_EN_SHIFT     (28U)
/*! PHRFAIL_IRQ_EN - PHRFAIL_IRQ Enable
 *  0b0..PHRFAIL Interrupt is not enabled.
 *  0b1..PHRFAIL Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_PHRFAIL_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_PHRFAIL_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_PHRFAIL_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_EN_MASK   (0x20000000U)
#define GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_EN_SHIFT  (29U)
/*! FILTERFAIL_IRQ_EN - FILTERFAIL_IRQ Enable
 *  0b0..FILTERFAIL Interrupt is not enabled.
 *  0b1..FILTERFAIL Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_FILTERFAIL_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_CCA_IRQ_EN_MASK          (0x40000000U)
#define GENFSK_IRQ_CTRL_CCA_IRQ_EN_SHIFT         (30U)
/*! CCA_IRQ_EN - CCA_IRQ Enable
 *  0b0..CCA Interrupt is not enabled.
 *  0b1..CCA Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_CCA_IRQ_EN(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_CCA_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_CCA_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_MS_IRQ_EN_MASK           (0x80000000U)
#define GENFSK_IRQ_CTRL_MS_IRQ_EN_SHIFT          (31U)
/*! MS_IRQ_EN - MS_IRQ Enable
 *  0b0..MS Interrupt is not enabled.
 *  0b1..MS Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_MS_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_MS_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_MS_IRQ_EN_MASK)
/*! @} */

/*! @name EVENT_TMR - EVENT TIMER */
/*! @{ */

#define GENFSK_EVENT_TMR_EVENT_TMR_MASK          (0xFFFFFFFFU)
#define GENFSK_EVENT_TMR_EVENT_TMR_SHIFT         (0U)
/*! EVENT_TMR - Event Timer */
#define GENFSK_EVENT_TMR_EVENT_TMR(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_EVENT_TMR_EVENT_TMR_SHIFT)) & GENFSK_EVENT_TMR_EVENT_TMR_MASK)
/*! @} */

/*! @name T1_CMP - T1 COMPARE */
/*! @{ */

#define GENFSK_T1_CMP_T1_CMP_MASK                (0xFFFFFFFFU)
#define GENFSK_T1_CMP_T1_CMP_SHIFT               (0U)
/*! T1_CMP - Timer1 (T1) Compare Value */
#define GENFSK_T1_CMP_T1_CMP(x)                  (((uint32_t)(((uint32_t)(x)) << GENFSK_T1_CMP_T1_CMP_SHIFT)) & GENFSK_T1_CMP_T1_CMP_MASK)
/*! @} */

/*! @name T2_CMP - T2 COMPARE */
/*! @{ */

#define GENFSK_T2_CMP_T2_CMP_MASK                (0xFFFFFFFFU)
#define GENFSK_T2_CMP_T2_CMP_SHIFT               (0U)
/*! T2_CMP - Timer2 (T2) Compare Value */
#define GENFSK_T2_CMP_T2_CMP(x)                  (((uint32_t)(((uint32_t)(x)) << GENFSK_T2_CMP_T2_CMP_SHIFT)) & GENFSK_T2_CMP_T2_CMP_MASK)
/*! @} */

/*! @name TIMESTAMP - TIMESTAMP */
/*! @{ */

#define GENFSK_TIMESTAMP_TIMESTAMP_MASK          (0xFFFFFFFFU)
#define GENFSK_TIMESTAMP_TIMESTAMP_SHIFT         (0U)
/*! TIMESTAMP - Received Packet Timestamp */
#define GENFSK_TIMESTAMP_TIMESTAMP(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_TIMESTAMP_TIMESTAMP_SHIFT)) & GENFSK_TIMESTAMP_TIMESTAMP_MASK)
/*! @} */

/*! @name XCVR_CTRL - TRANSCEIVER CONTROL */
/*! @{ */

#define GENFSK_XCVR_CTRL_SEQCMD_MASK             (0x1FU)
#define GENFSK_XCVR_CTRL_SEQCMD_SHIFT            (0U)
/*! SEQCMD - Sequence Commands, also named as "XCVSEQ(Transceiver Sequence)"
 *  0b00000..Same as command ABORT
 *  0b00001..TX Start Now
 *  0b00010..TX Start @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b00011..TX Start @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b00100..TX Cancel -- Cancels pending TX events but do not abort a TX-in-progress
 *  0b00101..RX Start Now
 *  0b00110..RX Start @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b00111..RX Start @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b01000..RX Stop @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b01001..RX Stop @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b01010..RX Cancel -- Cancels pending RX events but do not abort a RX-in-progress
 *  0b01011..Abort All - Cancels all pending events and abort any sequence-in-progress
 *  0b01100..TR Start Now
 *  0b01101..TR Start @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b01110..TR Start @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b01111..TR Cancel -- Cancels pending TR events but do not abort a TR-in-progress
 *  0b10000..CCA Start Now
 *  0b10001..CCA Start @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b10010..CCA Start @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b10011..CCA Cancel -- Cancels pending CCA events but do not abort a CCA-in-progress
 */
#define GENFSK_XCVR_CTRL_SEQCMD(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CTRL_SEQCMD_SHIFT)) & GENFSK_XCVR_CTRL_SEQCMD_MASK)

#define GENFSK_XCVR_CTRL_LENGTH_EXT_MASK         (0x7FF00U)
#define GENFSK_XCVR_CTRL_LENGTH_EXT_SHIFT        (8U)
/*! LENGTH_EXT - Extracted Length Field */
#define GENFSK_XCVR_CTRL_LENGTH_EXT(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CTRL_LENGTH_EXT_SHIFT)) & GENFSK_XCVR_CTRL_LENGTH_EXT_MASK)

#define GENFSK_XCVR_CTRL_CMDDEC_CS_MASK          (0x1F000000U)
#define GENFSK_XCVR_CTRL_CMDDEC_CS_SHIFT         (24U)
/*! CMDDEC_CS - Command Decode */
#define GENFSK_XCVR_CTRL_CMDDEC_CS(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CTRL_CMDDEC_CS_SHIFT)) & GENFSK_XCVR_CTRL_CMDDEC_CS_MASK)

#define GENFSK_XCVR_CTRL_XCVR_BUSY_MASK          (0x80000000U)
#define GENFSK_XCVR_CTRL_XCVR_BUSY_SHIFT         (31U)
/*! XCVR_BUSY - Transceiver Busy
 *  0b0..IDLE
 *  0b1..BUSY
 */
#define GENFSK_XCVR_CTRL_XCVR_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CTRL_XCVR_BUSY_SHIFT)) & GENFSK_XCVR_CTRL_XCVR_BUSY_MASK)
/*! @} */

/*! @name XCVR_STS - TRANSCEIVER STATUS */
/*! @{ */

#define GENFSK_XCVR_STS_LQI_MASK                 (0xFFU)
#define GENFSK_XCVR_STS_LQI_SHIFT                (0U)
/*! LQI - Link Quality Indicator */
#define GENFSK_XCVR_STS_LQI(x)                   (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_LQI_SHIFT)) & GENFSK_XCVR_STS_LQI_MASK)

#define GENFSK_XCVR_STS_LQI_VALID_MASK           (0x8000U)
#define GENFSK_XCVR_STS_LQI_VALID_SHIFT          (15U)
/*! LQI_VALID - LQI Valid Indicator
 *  0b0..LQI is not yet valid for RX packet.
 *  0b1..LQI is valid for RX packet.
 */
#define GENFSK_XCVR_STS_LQI_VALID(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_LQI_VALID_SHIFT)) & GENFSK_XCVR_STS_LQI_VALID_MASK)

#define GENFSK_XCVR_STS_RSSI_MASK                (0xFF0000U)
#define GENFSK_XCVR_STS_RSSI_SHIFT               (16U)
/*! RSSI - RSSI Value */
#define GENFSK_XCVR_STS_RSSI(x)                  (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RSSI_SHIFT)) & GENFSK_XCVR_STS_RSSI_MASK)
/*! @} */

/*! @name XCVR_CFG - TRANSCEIVER CONFIGURATION */
/*! @{ */

#define GENFSK_XCVR_CFG_TX_WHITEN_DIS_MASK       (0x1U)
#define GENFSK_XCVR_CFG_TX_WHITEN_DIS_SHIFT      (0U)
/*! TX_WHITEN_DIS - TX Whitening Disable */
#define GENFSK_XCVR_CFG_TX_WHITEN_DIS(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_TX_WHITEN_DIS_SHIFT)) & GENFSK_XCVR_CFG_TX_WHITEN_DIS_MASK)

#define GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_MASK     (0x2U)
#define GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_SHIFT    (1U)
/*! RX_DEWHITEN_DIS - RX De-Whitening Disable */
#define GENFSK_XCVR_CFG_RX_DEWHITEN_DIS(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_SHIFT)) & GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_MASK)

#define GENFSK_XCVR_CFG_SW_CRC_EN_MASK           (0x4U)
#define GENFSK_XCVR_CFG_SW_CRC_EN_SHIFT          (2U)
/*! SW_CRC_EN - Software CRC Enable */
#define GENFSK_XCVR_CFG_SW_CRC_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_SW_CRC_EN_SHIFT)) & GENFSK_XCVR_CFG_SW_CRC_EN_MASK)

#define GENFSK_XCVR_CFG_STOP_POSTPONE_ON_AA_MASK (0x8U)
#define GENFSK_XCVR_CFG_STOP_POSTPONE_ON_AA_SHIFT (3U)
/*! STOP_POSTPONE_ON_AA - Postpone Stop Command Timeout On Access Address Match Enable
 *  0b0..STOP Abort will occur on RX_STOP_T1 or RX_STOP_T1 Event Timer match, regardless of NTW_ADR_MCH
 *  0b1..STOP Abort will be deferred on RX_STOP_T1 or RX_STOP_T1 Event Timer match, if NTW_ADR_MCH is asserted;
 *       otherwise the RX_STOP Abort will occur immediately
 */
#define GENFSK_XCVR_CFG_STOP_POSTPONE_ON_AA(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_STOP_POSTPONE_ON_AA_SHIFT)) & GENFSK_XCVR_CFG_STOP_POSTPONE_ON_AA_MASK)

#define GENFSK_XCVR_CFG_PREAMBLE_SZ_MASK         (0x1FF0U)
#define GENFSK_XCVR_CFG_PREAMBLE_SZ_SHIFT        (4U)
/*! PREAMBLE_SZ - Preamble Size */
#define GENFSK_XCVR_CFG_PREAMBLE_SZ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_PREAMBLE_SZ_SHIFT)) & GENFSK_XCVR_CFG_PREAMBLE_SZ_MASK)

#define GENFSK_XCVR_CFG_GEN_PREAMBLE_MASK        (0xFF0000U)
#define GENFSK_XCVR_CFG_GEN_PREAMBLE_SHIFT       (16U)
/*! GEN_PREAMBLE - Preamble pattern */
#define GENFSK_XCVR_CFG_GEN_PREAMBLE(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_GEN_PREAMBLE_SHIFT)) & GENFSK_XCVR_CFG_GEN_PREAMBLE_MASK)

#define GENFSK_XCVR_CFG_PREAMBLE_SEL_MASK        (0x7000000U)
#define GENFSK_XCVR_CFG_PREAMBLE_SEL_SHIFT       (24U)
/*! PREAMBLE_SEL - Preamble Select
 *  0b000..The controller hardware selects the preamble pattern based on the first transmitted bit of Network
 *         Address, such that the last bit of preamble is the opposite polarity from the first bit of Network Address,
 *         forcing a bit transition at this boundary.
 *  0b001..Preamble is programmed by register GEN_PREAMBLE[7:0]
 *  0b010..Preamble is 0b01
 *  0b011..Preamble is 0b10
 */
#define GENFSK_XCVR_CFG_PREAMBLE_SEL(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_PREAMBLE_SEL_SHIFT)) & GENFSK_XCVR_CFG_PREAMBLE_SEL_MASK)

#define GENFSK_XCVR_CFG_T1_CMP_EN_MASK           (0x40000000U)
#define GENFSK_XCVR_CFG_T1_CMP_EN_SHIFT          (30U)
/*! T1_CMP_EN - Timer1 (T1) Compare Enable */
#define GENFSK_XCVR_CFG_T1_CMP_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_T1_CMP_EN_SHIFT)) & GENFSK_XCVR_CFG_T1_CMP_EN_MASK)

#define GENFSK_XCVR_CFG_T2_CMP_EN_MASK           (0x80000000U)
#define GENFSK_XCVR_CFG_T2_CMP_EN_SHIFT          (31U)
/*! T2_CMP_EN - Timer2 (T2) Compare Enable */
#define GENFSK_XCVR_CFG_T2_CMP_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_T2_CMP_EN_SHIFT)) & GENFSK_XCVR_CFG_T2_CMP_EN_MASK)
/*! @} */

/*! @name CHANNEL_NUM0 - CHANNEL NUMBER 0 */
/*! @{ */

#define GENFSK_CHANNEL_NUM0_CHANNEL_NUM0_MASK    (0x7FU)
#define GENFSK_CHANNEL_NUM0_CHANNEL_NUM0_SHIFT   (0U)
/*! CHANNEL_NUM0 - Channel Number for PAN0 */
#define GENFSK_CHANNEL_NUM0_CHANNEL_NUM0(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_CHANNEL_NUM0_CHANNEL_NUM0_SHIFT)) & GENFSK_CHANNEL_NUM0_CHANNEL_NUM0_MASK)
/*! @} */

/*! @name TX_POWER - TRANSMIT POWER */
/*! @{ */

#define GENFSK_TX_POWER_TX_POWER_MASK            (0x3FU)
#define GENFSK_TX_POWER_TX_POWER_SHIFT           (0U)
/*! TX_POWER - Transmit Power */
#define GENFSK_TX_POWER_TX_POWER(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_TX_POWER_TX_POWER_SHIFT)) & GENFSK_TX_POWER_TX_POWER_MASK)
/*! @} */

/*! @name NTW_ADR_CTRL - NETWORK ADDRESS CONTROL */
/*! @{ */

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_MASK      (0xFU)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_SHIFT     (0U)
/*! NTW_ADR_EN - Network Address Enable
 *  0b0001..Enable Network Address 0 for correlation
 *  0b0010..Enable Network Address 1 for correlation
 *  0b0100..Enable Network Address 2 for correlation
 *  0b1000..Enable Network Address 3 for correlation
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_MASK     (0xF0U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_SHIFT    (4U)
/*! NTW_ADR_MCH - Network Address Match
 *  0b0001..Network Address 0 has matched
 *  0b0010..Network Address 1 has matched
 *  0b0100..Network Address 2 has matched
 *  0b1000..Network Address 3 has matched
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_SZ_MASK      (0x300U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_SZ_SHIFT     (8U)
/*! NTW_ADR_SZ - Network Address Size
 *  0b00..Network Address 0/1/2/3 requires a 8-bit correlation
 *  0b01..Network Address 0/1/2/3 requires a 16-bit correlation
 *  0b10..Network Address 0/1/2/3 requires a 24-bit correlation
 *  0b11..Network Address 0/1/2/3 requires a 32-bit correlation
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_SZ(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_SZ_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_SZ_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR_MASK     (0x70000U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR_SHIFT    (16U)
/*! NTW_ADR_THR - Network Address Threshold */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_THR_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_THR_MASK)
/*! @} */

/*! @name NTW_ADR_0 - NETWORK ADDRESS 0 */
/*! @{ */

#define GENFSK_NTW_ADR_0_NTW_ADR_0_MASK          (0xFFFFFFFFU)
#define GENFSK_NTW_ADR_0_NTW_ADR_0_SHIFT         (0U)
/*! NTW_ADR_0 - Network Address 0 */
#define GENFSK_NTW_ADR_0_NTW_ADR_0(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_0_NTW_ADR_0_SHIFT)) & GENFSK_NTW_ADR_0_NTW_ADR_0_MASK)
/*! @} */

/*! @name NTW_ADR_1 - NETWORK ADDRESS 1 */
/*! @{ */

#define GENFSK_NTW_ADR_1_NTW_ADR_1_MASK          (0xFFFFFFFFU)
#define GENFSK_NTW_ADR_1_NTW_ADR_1_SHIFT         (0U)
/*! NTW_ADR_1 - Network Address 1 */
#define GENFSK_NTW_ADR_1_NTW_ADR_1(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_1_NTW_ADR_1_SHIFT)) & GENFSK_NTW_ADR_1_NTW_ADR_1_MASK)
/*! @} */

/*! @name RX_WATERMARK - RECEIVE WATERMARK */
/*! @{ */

#define GENFSK_RX_WATERMARK_RX_WATERMARK_MASK    (0x1FFFU)
#define GENFSK_RX_WATERMARK_RX_WATERMARK_SHIFT   (0U)
/*! RX_WATERMARK - Receive Watermark */
#define GENFSK_RX_WATERMARK_RX_WATERMARK(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_WATERMARK_RX_WATERMARK_SHIFT)) & GENFSK_RX_WATERMARK_RX_WATERMARK_MASK)

#define GENFSK_RX_WATERMARK_BYTE_COUNTER_MASK    (0x1FFF0000U)
#define GENFSK_RX_WATERMARK_BYTE_COUNTER_SHIFT   (16U)
/*! BYTE_COUNTER - Byte Counter */
#define GENFSK_RX_WATERMARK_BYTE_COUNTER(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_WATERMARK_BYTE_COUNTER_SHIFT)) & GENFSK_RX_WATERMARK_BYTE_COUNTER_MASK)
/*! @} */

/*! @name DSM_CTRL - DSM CONTROL */
/*! @{ */

#define GENFSK_DSM_CTRL_GEN_SLEEP_REQUEST_MASK   (0x1U)
#define GENFSK_DSM_CTRL_GEN_SLEEP_REQUEST_SHIFT  (0U)
/*! GEN_SLEEP_REQUEST - GENERIC_FSK Deep Sleep Mode Request */
#define GENFSK_DSM_CTRL_GEN_SLEEP_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_DSM_CTRL_GEN_SLEEP_REQUEST_SHIFT)) & GENFSK_DSM_CTRL_GEN_SLEEP_REQUEST_MASK)
/*! @} */

/*! @name PART_ID - PART ID */
/*! @{ */

#define GENFSK_PART_ID_PART_ID_MASK              (0xFFU)
#define GENFSK_PART_ID_PART_ID_SHIFT             (0U)
/*! PART_ID - Part ID */
#define GENFSK_PART_ID_PART_ID(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_PART_ID_PART_ID_SHIFT)) & GENFSK_PART_ID_PART_ID_MASK)
/*! @} */

/*! @name SLOT_PRELOAD - SLOT PRELOAD */
/*! @{ */

#define GENFSK_SLOT_PRELOAD_SLOT_PRELOAD_MASK    (0xFFFFU)
#define GENFSK_SLOT_PRELOAD_SLOT_PRELOAD_SHIFT   (0U)
/*! SLOT_PRELOAD - Slotted Mode Preload */
#define GENFSK_SLOT_PRELOAD_SLOT_PRELOAD(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_SLOT_PRELOAD_SLOT_PRELOAD_SHIFT)) & GENFSK_SLOT_PRELOAD_SLOT_PRELOAD_MASK)
/*! @} */

/*! @name SLOT_TIME - SLOT TIME */
/*! @{ */

#define GENFSK_SLOT_TIME_SLOT_TIME_MASK          (0xFFFFU)
#define GENFSK_SLOT_TIME_SLOT_TIME_SHIFT         (0U)
/*! SLOT_TIME - Duration of the Backoff Slot */
#define GENFSK_SLOT_TIME_SLOT_TIME(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_SLOT_TIME_SLOT_TIME_SHIFT)) & GENFSK_SLOT_TIME_SLOT_TIME_MASK)
/*! @} */

/*! @name TURNAROUND_TIME - TURNAROUND TIME */
/*! @{ */

#define GENFSK_TURNAROUND_TIME_TURNAROUND_TIME_MASK (0xFFFFU)
#define GENFSK_TURNAROUND_TIME_TURNAROUND_TIME_SHIFT (0U)
/*! TURNAROUND_TIME - RX-to-TX or TX-to-RX turnaround time */
#define GENFSK_TURNAROUND_TIME_TURNAROUND_TIME(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_TURNAROUND_TIME_TURNAROUND_TIME_SHIFT)) & GENFSK_TURNAROUND_TIME_TURNAROUND_TIME_MASK)
/*! @} */

/*! @name ACKDELAY - ACK DELAY */
/*! @{ */

#define GENFSK_ACKDELAY_ACKDELAY_MASK            (0x3FFU)
#define GENFSK_ACKDELAY_ACKDELAY_SHIFT           (0U)
/*! ACKDELAY - ACK Delay */
#define GENFSK_ACKDELAY_ACKDELAY(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_ACKDELAY_ACKDELAY_SHIFT)) & GENFSK_ACKDELAY_ACKDELAY_MASK)
/*! @} */

/*! @name RXDELAY - RX DELAY */
/*! @{ */

#define GENFSK_RXDELAY_RXDELAY_MASK              (0x3FFU)
#define GENFSK_RXDELAY_RXDELAY_SHIFT             (0U)
/*! RXDELAY - RX Delay */
#define GENFSK_RXDELAY_RXDELAY(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_RXDELAY_RXDELAY_SHIFT)) & GENFSK_RXDELAY_RXDELAY_MASK)
/*! @} */

/*! @name TXDELAY - TX DELAY */
/*! @{ */

#define GENFSK_TXDELAY_TXDELAY_MASK              (0x3FFU)
#define GENFSK_TXDELAY_TXDELAY_SHIFT             (0U)
/*! TXDELAY - TX Delay */
#define GENFSK_TXDELAY_TXDELAY(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_TXDELAY_TXDELAY_SHIFT)) & GENFSK_TXDELAY_TXDELAY_MASK)
/*! @} */

/*! @name PACKET_CFG - PACKET CONFIGURATION */
/*! @{ */

#define GENFSK_PACKET_CFG_LENGTH_SZ_MASK         (0x1FU)
#define GENFSK_PACKET_CFG_LENGTH_SZ_SHIFT        (0U)
/*! LENGTH_SZ - LENGTH Size */
#define GENFSK_PACKET_CFG_LENGTH_SZ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LENGTH_SZ_SHIFT)) & GENFSK_PACKET_CFG_LENGTH_SZ_MASK)

#define GENFSK_PACKET_CFG_LENGTH_BIT_ORD_MASK    (0x20U)
#define GENFSK_PACKET_CFG_LENGTH_BIT_ORD_SHIFT   (5U)
/*! LENGTH_BIT_ORD - LENGTH Bit Order
 *  0b0..LS Bit First
 *  0b1..MS Bit First
 */
#define GENFSK_PACKET_CFG_LENGTH_BIT_ORD(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LENGTH_BIT_ORD_SHIFT)) & GENFSK_PACKET_CFG_LENGTH_BIT_ORD_MASK)

#define GENFSK_PACKET_CFG_SYNC_ADDR_SZ_MASK      (0xC0U)
#define GENFSK_PACKET_CFG_SYNC_ADDR_SZ_SHIFT     (6U)
/*! SYNC_ADDR_SZ - Sync Address Size */
#define GENFSK_PACKET_CFG_SYNC_ADDR_SZ(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_SYNC_ADDR_SZ_SHIFT)) & GENFSK_PACKET_CFG_SYNC_ADDR_SZ_MASK)

#define GENFSK_PACKET_CFG_H0_SZ_MASK             (0x1F0000U)
#define GENFSK_PACKET_CFG_H0_SZ_SHIFT            (16U)
/*! H0_SZ - H0 Size */
#define GENFSK_PACKET_CFG_H0_SZ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H0_SZ_SHIFT)) & GENFSK_PACKET_CFG_H0_SZ_MASK)

#define GENFSK_PACKET_CFG_AA_PLAYBACK_CNT_MASK   (0x400000U)
#define GENFSK_PACKET_CFG_AA_PLAYBACK_CNT_SHIFT  (22U)
/*! AA_PLAYBACK_CNT - AA PLAYBACK COUNT
 *  0b0..AA is not through CRC and not playback to Link layer.
 *  0b1..AA is through CRC and palayback to Link Layer.
 */
#define GENFSK_PACKET_CFG_AA_PLAYBACK_CNT(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_AA_PLAYBACK_CNT_SHIFT)) & GENFSK_PACKET_CFG_AA_PLAYBACK_CNT_MASK)

#define GENFSK_PACKET_CFG_LL_FETCH_AA_MASK       (0x800000U)
#define GENFSK_PACKET_CFG_LL_FETCH_AA_SHIFT      (23U)
/*! LL_FETCH_AA - Link layer fetches AA from PHY
 *  0b0..Link layer does not fetch AA from PHY
 *  0b1..Link layer fetches AA from PHY when AA_PLAYBACK_CNT is 0
 */
#define GENFSK_PACKET_CFG_LL_FETCH_AA(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LL_FETCH_AA_SHIFT)) & GENFSK_PACKET_CFG_LL_FETCH_AA_MASK)

#define GENFSK_PACKET_CFG_H1_SZ_MASK             (0x1F000000U)
#define GENFSK_PACKET_CFG_H1_SZ_SHIFT            (24U)
/*! H1_SZ - H1 Size */
#define GENFSK_PACKET_CFG_H1_SZ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H1_SZ_SHIFT)) & GENFSK_PACKET_CFG_H1_SZ_MASK)

#define GENFSK_PACKET_CFG_H1_FAIL_MASK           (0x20000000U)
#define GENFSK_PACKET_CFG_H1_FAIL_SHIFT          (29U)
/*! H1_FAIL - H1 Violated Status Bit */
#define GENFSK_PACKET_CFG_H1_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H1_FAIL_SHIFT)) & GENFSK_PACKET_CFG_H1_FAIL_MASK)

#define GENFSK_PACKET_CFG_H0_FAIL_MASK           (0x40000000U)
#define GENFSK_PACKET_CFG_H0_FAIL_SHIFT          (30U)
/*! H0_FAIL - H0 Violated Status Bit */
#define GENFSK_PACKET_CFG_H0_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H0_FAIL_SHIFT)) & GENFSK_PACKET_CFG_H0_FAIL_MASK)

#define GENFSK_PACKET_CFG_LENGTH_FAIL_MASK       (0x80000000U)
#define GENFSK_PACKET_CFG_LENGTH_FAIL_SHIFT      (31U)
/*! LENGTH_FAIL - Maximum Length Violated Status Bit */
#define GENFSK_PACKET_CFG_LENGTH_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LENGTH_FAIL_SHIFT)) & GENFSK_PACKET_CFG_LENGTH_FAIL_MASK)
/*! @} */

/*! @name H0_CFG - H0 CONFIGURATION */
/*! @{ */

#define GENFSK_H0_CFG_H0_MATCH_MASK              (0xFFFFU)
#define GENFSK_H0_CFG_H0_MATCH_SHIFT             (0U)
/*! H0_MATCH - H0 Match Register */
#define GENFSK_H0_CFG_H0_MATCH(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_H0_CFG_H0_MATCH_SHIFT)) & GENFSK_H0_CFG_H0_MATCH_MASK)

#define GENFSK_H0_CFG_H0_MASK_MASK               (0xFFFF0000U)
#define GENFSK_H0_CFG_H0_MASK_SHIFT              (16U)
/*! H0_MASK - H0 Mask Register */
#define GENFSK_H0_CFG_H0_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << GENFSK_H0_CFG_H0_MASK_SHIFT)) & GENFSK_H0_CFG_H0_MASK_MASK)
/*! @} */

/*! @name H1_CFG - H1 CONFIGURATION */
/*! @{ */

#define GENFSK_H1_CFG_H1_MATCH_MASK              (0xFFFFU)
#define GENFSK_H1_CFG_H1_MATCH_SHIFT             (0U)
/*! H1_MATCH - H1 Match Register */
#define GENFSK_H1_CFG_H1_MATCH(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_H1_CFG_H1_MATCH_SHIFT)) & GENFSK_H1_CFG_H1_MATCH_MASK)

#define GENFSK_H1_CFG_H1_MASK_MASK               (0xFFFF0000U)
#define GENFSK_H1_CFG_H1_MASK_SHIFT              (16U)
/*! H1_MASK - H1 Mask Register */
#define GENFSK_H1_CFG_H1_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << GENFSK_H1_CFG_H1_MASK_SHIFT)) & GENFSK_H1_CFG_H1_MASK_MASK)
/*! @} */

/*! @name CRC_CFG - CRC CONFIGURATION */
/*! @{ */

#define GENFSK_CRC_CFG_CRC_IGNORE_MASK           (0x1000000U)
#define GENFSK_CRC_CFG_CRC_IGNORE_SHIFT          (24U)
/*! CRC_IGNORE - CRC Ignore
 *  0b0..RX_IRQ will not be asserted for a received packet which fails CRC verification.
 *  0b1..RX_IRQ will be asserted even for a received packet which fails CRC verification.
 */
#define GENFSK_CRC_CFG_CRC_IGNORE(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_CFG_CRC_IGNORE_SHIFT)) & GENFSK_CRC_CFG_CRC_IGNORE_MASK)

#define GENFSK_CRC_CFG_CRC_VALID_MASK            (0x10000000U)
#define GENFSK_CRC_CFG_CRC_VALID_SHIFT           (28U)
/*! CRC_VALID - CRC Valid
 *  0b0..CRC of RX packet is not valid.
 *  0b1..CRC of RX packet is valid.
 */
#define GENFSK_CRC_CFG_CRC_VALID(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_CFG_CRC_VALID_SHIFT)) & GENFSK_CRC_CFG_CRC_VALID_MASK)
/*! @} */

/*! @name LENGTH_ADJ - LENGTH ADJUSTMENT */
/*! @{ */

#define GENFSK_LENGTH_ADJ_LENGTH_ADJ_MASK        (0x7FFU)
#define GENFSK_LENGTH_ADJ_LENGTH_ADJ_SHIFT       (0U)
/*! LENGTH_ADJ - Length Adjustment */
#define GENFSK_LENGTH_ADJ_LENGTH_ADJ(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_LENGTH_ADJ_LENGTH_ADJ_SHIFT)) & GENFSK_LENGTH_ADJ_LENGTH_ADJ_MASK)
/*! @} */

/*! @name TIMESTAMP_RX_DONE - TIMESTAMP_RX_DONE */
/*! @{ */

#define GENFSK_TIMESTAMP_RX_DONE_TIMESTAMP_RX_DONE_MASK (0xFFFFFFFFU)
#define GENFSK_TIMESTAMP_RX_DONE_TIMESTAMP_RX_DONE_SHIFT (0U)
/*! TIMESTAMP_RX_DONE - Received Packet Timestamp. Captured at Rx done. */
#define GENFSK_TIMESTAMP_RX_DONE_TIMESTAMP_RX_DONE(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_TIMESTAMP_RX_DONE_TIMESTAMP_RX_DONE_SHIFT)) & GENFSK_TIMESTAMP_RX_DONE_TIMESTAMP_RX_DONE_MASK)
/*! @} */

/*! @name TIMESTAMP_TX_DONE - TIMESTAMP_TX_DONE */
/*! @{ */

#define GENFSK_TIMESTAMP_TX_DONE_TIMESTAMP_TX_DONE_MASK (0xFFFFFFFFU)
#define GENFSK_TIMESTAMP_TX_DONE_TIMESTAMP_TX_DONE_SHIFT (0U)
/*! TIMESTAMP_TX_DONE - Received Packet Timestamp. Captured at Tx done. */
#define GENFSK_TIMESTAMP_TX_DONE_TIMESTAMP_TX_DONE(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_TIMESTAMP_TX_DONE_TIMESTAMP_TX_DONE_SHIFT)) & GENFSK_TIMESTAMP_TX_DONE_TIMESTAMP_TX_DONE_MASK)
/*! @} */

/*! @name MULT_PKT_CTRL - MULT_PKT_CTRL */
/*! @{ */

#define GENFSK_MULT_PKT_CTRL_SEG_SZ_MASK         (0xFU)
#define GENFSK_MULT_PKT_CTRL_SEG_SZ_SHIFT        (0U)
/*! SEG_SZ - RAM Segment Size */
#define GENFSK_MULT_PKT_CTRL_SEG_SZ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_MULT_PKT_CTRL_SEG_SZ_SHIFT)) & GENFSK_MULT_PKT_CTRL_SEG_SZ_MASK)

#define GENFSK_MULT_PKT_CTRL_PKT_INDEX_MASK      (0x7F00U)
#define GENFSK_MULT_PKT_CTRL_PKT_INDEX_SHIFT     (8U)
/*! PKT_INDEX - Packet Index */
#define GENFSK_MULT_PKT_CTRL_PKT_INDEX(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_MULT_PKT_CTRL_PKT_INDEX_SHIFT)) & GENFSK_MULT_PKT_CTRL_PKT_INDEX_MASK)

#define GENFSK_MULT_PKT_CTRL_SEG_BASE_ADDR_MASK  (0xFFF0000U)
#define GENFSK_MULT_PKT_CTRL_SEG_BASE_ADDR_SHIFT (16U)
/*! SEG_BASE_ADDR - Segment Offset Address */
#define GENFSK_MULT_PKT_CTRL_SEG_BASE_ADDR(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_MULT_PKT_CTRL_SEG_BASE_ADDR_SHIFT)) & GENFSK_MULT_PKT_CTRL_SEG_BASE_ADDR_MASK)

#define GENFSK_MULT_PKT_CTRL_RESET_PKT_IDX_MASK  (0x40000000U)
#define GENFSK_MULT_PKT_CTRL_RESET_PKT_IDX_SHIFT (30U)
/*! RESET_PKT_IDX - Reset the PKT_INDEX to zero */
#define GENFSK_MULT_PKT_CTRL_RESET_PKT_IDX(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_MULT_PKT_CTRL_RESET_PKT_IDX_SHIFT)) & GENFSK_MULT_PKT_CTRL_RESET_PKT_IDX_MASK)

#define GENFSK_MULT_PKT_CTRL_MULT_PKT_EN_MASK    (0x80000000U)
#define GENFSK_MULT_PKT_CTRL_MULT_PKT_EN_SHIFT   (31U)
/*! MULT_PKT_EN - Enable to send or receive multiple packets
 *  0b0..Send or receive multiple packets is not enabled.
 *  0b1..Send or receive multiple packets is enabled.
 */
#define GENFSK_MULT_PKT_CTRL_MULT_PKT_EN(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_MULT_PKT_CTRL_MULT_PKT_EN_SHIFT)) & GENFSK_MULT_PKT_CTRL_MULT_PKT_EN_MASK)
/*! @} */

/*! @name RPA_WL_STATUS - RPA AND WHITE LIST STATUS */
/*! @{ */

#define GENFSK_RPA_WL_STATUS_WL_MATCH_INDEX_MASK (0x3FU)
#define GENFSK_RPA_WL_STATUS_WL_MATCH_INDEX_SHIFT (0U)
/*! WL_MATCH_INDEX - The matched white list index of the identity address resolved(RPA is enabled)
 *    or peer address received(RPA is not enabled)
 */
#define GENFSK_RPA_WL_STATUS_WL_MATCH_INDEX(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_WL_STATUS_WL_MATCH_INDEX_SHIFT)) & GENFSK_RPA_WL_STATUS_WL_MATCH_INDEX_MASK)

#define GENFSK_RPA_WL_STATUS_PEER_RESOLVED_INDEX_MASK (0xF0000U)
#define GENFSK_RPA_WL_STATUS_PEER_RESOLVED_INDEX_SHIFT (16U)
/*! PEER_RESOLVED_INDEX - The matched RPA index of peer address */
#define GENFSK_RPA_WL_STATUS_PEER_RESOLVED_INDEX(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_WL_STATUS_PEER_RESOLVED_INDEX_SHIFT)) & GENFSK_RPA_WL_STATUS_PEER_RESOLVED_INDEX_MASK)

#define GENFSK_RPA_WL_STATUS_LOCAL_RESOLVED_INDEX_MASK (0xF000000U)
#define GENFSK_RPA_WL_STATUS_LOCAL_RESOLVED_INDEX_SHIFT (24U)
/*! LOCAL_RESOLVED_INDEX - The matched RPA index of local address */
#define GENFSK_RPA_WL_STATUS_LOCAL_RESOLVED_INDEX(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_WL_STATUS_LOCAL_RESOLVED_INDEX_SHIFT)) & GENFSK_RPA_WL_STATUS_LOCAL_RESOLVED_INDEX_MASK)

#define GENFSK_RPA_WL_STATUS_SEARCH_WL_MASK      (0x80000000U)
#define GENFSK_RPA_WL_STATUS_SEARCH_WL_SHIFT     (31U)
/*! SEARCH_WL - Search Identity Address in White List */
#define GENFSK_RPA_WL_STATUS_SEARCH_WL(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_WL_STATUS_SEARCH_WL_SHIFT)) & GENFSK_RPA_WL_STATUS_SEARCH_WL_MASK)
/*! @} */

/*! @name LENGTH_MAX - MAXIMUM LENGTH */
/*! @{ */

#define GENFSK_LENGTH_MAX_LENGTH_MAX_MASK        (0x7F0000U)
#define GENFSK_LENGTH_MAX_LENGTH_MAX_SHIFT       (16U)
/*! LENGTH_MAX - Maximum Length for Received Packets */
#define GENFSK_LENGTH_MAX_LENGTH_MAX(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_LENGTH_MAX_LENGTH_MAX_SHIFT)) & GENFSK_LENGTH_MAX_LENGTH_MAX_MASK)

#define GENFSK_LENGTH_MAX_REC_BAD_PKT_MASK       (0x800000U)
#define GENFSK_LENGTH_MAX_REC_BAD_PKT_SHIFT      (23U)
/*! REC_BAD_PKT - Receive Bad Packets
 *  0b0..packets which fail H0, H1, or LENGTH_MAX result in an automatic recycle after the header is received and parsed
 *  0b1..packets which fail H0, H1, or LENGTH_MAX are received in their entirety
 */
#define GENFSK_LENGTH_MAX_REC_BAD_PKT(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_LENGTH_MAX_REC_BAD_PKT_SHIFT)) & GENFSK_LENGTH_MAX_REC_BAD_PKT_MASK)
/*! @} */

/*! @name EVENT_TMR_LD - EVENT TIMER LOAD */
/*! @{ */

#define GENFSK_EVENT_TMR_LD_EVENT_TMR_LD_MASK    (0xFFFFFFFFU)
#define GENFSK_EVENT_TMR_LD_EVENT_TMR_LD_SHIFT   (0U)
/*! EVENT_TMR_LD - Event Timer Load */
#define GENFSK_EVENT_TMR_LD_EVENT_TMR_LD(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_EVENT_TMR_LD_EVENT_TMR_LD_SHIFT)) & GENFSK_EVENT_TMR_LD_EVENT_TMR_LD_MASK)
/*! @} */

/*! @name EVENT_TMR_ADD - EVENT TIMER ADD */
/*! @{ */

#define GENFSK_EVENT_TMR_ADD_EVENT_TMR_ADD_MASK  (0xFFFFFFFFU)
#define GENFSK_EVENT_TMR_ADD_EVENT_TMR_ADD_SHIFT (0U)
/*! EVENT_TMR_ADD - Event Timer Add */
#define GENFSK_EVENT_TMR_ADD_EVENT_TMR_ADD(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_EVENT_TMR_ADD_EVENT_TMR_ADD_SHIFT)) & GENFSK_EVENT_TMR_ADD_EVENT_TMR_ADD_MASK)
/*! @} */

/*! @name ENH_FEATURE - ENHANCED FEATURES */
/*! @{ */

#define GENFSK_ENH_FEATURE_GENLL_MODE_MASK       (0xFU)
#define GENFSK_ENH_FEATURE_GENLL_MODE_SHIFT      (0U)
/*! GENLL_MODE - Link layer Mode Select
 *  0b0000..GLL Mode
 *  0b0001..PAN Mode
 *  0b0010..FAN Mode
 *  0b0011..Hybrid Dual PAN Mode
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..FCP Mode
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Bluetooth LE Uncoded Mode
 *  0b1010..Bluetooth LE LR Mode
 *  0b1011..Bluetooth LE Concurrent Mode (RX configuration only; TX uses either Bluetooth LE UNCODED or Bluetooth LE LR configuration)
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..GTM Mode
 */
#define GENFSK_ENH_FEATURE_GENLL_MODE(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_GENLL_MODE_SHIFT)) & GENFSK_ENH_FEATURE_GENLL_MODE_MASK)

#define GENFSK_ENH_FEATURE_SEL_RXIRQ_MASK        (0x20U)
#define GENFSK_ENH_FEATURE_SEL_RXIRQ_SHIFT       (5U)
/*! SEL_RXIRQ - Select the RX IRQ assert time
 *  0b0..RX_IRQ is asserted at the end of RX_PKT state.
 *  0b1..RX_IRQ is asserted at the end of RXEN_DLY state. This to be used for delaying RX_IRQ to accept TERM2 bits
 *       in Bluetooth LE-LR and CTE bits as needed.
 */
#define GENFSK_ENH_FEATURE_SEL_RXIRQ(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_SEL_RXIRQ_SHIFT)) & GENFSK_ENH_FEATURE_SEL_RXIRQ_MASK)

#define GENFSK_ENH_FEATURE_DATARATE_CONFIG_SEL_MASK (0x40U)
#define GENFSK_ENH_FEATURE_DATARATE_CONFIG_SEL_SHIFT (6U)
/*! DATARATE_CONFIG_SEL - Select the data rate configuration bank
 *  0b0..Select the data rate as per configuration bank 0
 *  0b1..Select the data rate as per configuration bank 1
 */
#define GENFSK_ENH_FEATURE_DATARATE_CONFIG_SEL(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_DATARATE_CONFIG_SEL_SHIFT)) & GENFSK_ENH_FEATURE_DATARATE_CONFIG_SEL_MASK)

#define GENFSK_ENH_FEATURE_STAY_IN_RX_MASK       (0x80U)
#define GENFSK_ENH_FEATURE_STAY_IN_RX_SHIFT      (7U)
/*! STAY_IN_RX - Stay in receive
 *  0b0..Link layer will warm-down after an RX_IRQ
 *  0b1..Link layer will recycle and stay in receive even after an RX_IRQ.
 */
#define GENFSK_ENH_FEATURE_STAY_IN_RX(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_STAY_IN_RX_SHIFT)) & GENFSK_ENH_FEATURE_STAY_IN_RX_MASK)

#define GENFSK_ENH_FEATURE_PHR_TYPE_MASK         (0x700U)
#define GENFSK_ENH_FEATURE_PHR_TYPE_SHIFT        (8U)
/*! PHR_TYPE - PHR Type
 *  0b000..The packet type is GFSK
 *  0b001..The packet type is MSK
 *  0b010..The packet type is SUN FSK
 *  0b011..The packet type is LECIM FSK
 */
#define GENFSK_ENH_FEATURE_PHR_TYPE(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_PHR_TYPE_SHIFT)) & GENFSK_ENH_FEATURE_PHR_TYPE_MASK)

#define GENFSK_ENH_FEATURE_SW_BUILD_ACK_MASK     (0x800U)
#define GENFSK_ENH_FEATURE_SW_BUILD_ACK_SHIFT    (11U)
/*! SW_BUILD_ACK - Software builds the ACK packet in RAM
 *  0b0..Hardware builds part of or the whole of the auto ACK frame
 *  0b1..Software builds the whole auto ACK frame in RAM.
 */
#define GENFSK_ENH_FEATURE_SW_BUILD_ACK(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_SW_BUILD_ACK_SHIFT)) & GENFSK_ENH_FEATURE_SW_BUILD_ACK_MASK)

#define GENFSK_ENH_FEATURE_ACKBUF_SEL_MASK       (0x1000U)
#define GENFSK_ENH_FEATURE_ACKBUF_SEL_SHIFT      (12U)
/*! ACKBUF_SEL - ACK frame is in 64-byte dedicated RAM or TX buffer RAM
 *  0b0..ACK frame is in 64-byte dedicated RAM
 *  0b1..ACK frame is in TX buffer RAM
 */
#define GENFSK_ENH_FEATURE_ACKBUF_SEL(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_ACKBUF_SEL_SHIFT)) & GENFSK_ENH_FEATURE_ACKBUF_SEL_MASK)

#define GENFSK_ENH_FEATURE_AUTOACK_MASK          (0x2000U)
#define GENFSK_ENH_FEATURE_AUTOACK_SHIFT         (13U)
/*! AUTOACK - Auto Acknowledge Enable
 *  0b0..sequence manager will not follow a receive frame with a Tx Ack frame, under any conditions; the
 *       auto-sequence will terminate after the receive frame.
 *  0b1..sequence manager will follow a receive frame with an automatic hardware-generated Tx Ack frame, assuming other necessary conditions are met.
 */
#define GENFSK_ENH_FEATURE_AUTOACK(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_AUTOACK_SHIFT)) & GENFSK_ENH_FEATURE_AUTOACK_MASK)

#define GENFSK_ENH_FEATURE_RXACKRQD_MASK         (0x4000U)
#define GENFSK_ENH_FEATURE_RXACKRQD_SHIFT        (14U)
/*! RXACKRQD - Receive Acknowledge Frame required
 *  0b0..An ordinary receive frame (any type of frame) follows the transmit frame.
 *  0b1..A receive Ack frame is expected to follow the transmit frame (non-Ack frames are rejected).
 */
#define GENFSK_ENH_FEATURE_RXACKRQD(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_RXACKRQD_SHIFT)) & GENFSK_ENH_FEATURE_RXACKRQD_MASK)

#define GENFSK_ENH_FEATURE_SLOTTED_MASK          (0x8000U)
#define GENFSK_ENH_FEATURE_SLOTTED_SHIFT         (15U)
/*! SLOTTED - Slotted Mode */
#define GENFSK_ENH_FEATURE_SLOTTED(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_SLOTTED_SHIFT)) & GENFSK_ENH_FEATURE_SLOTTED_MASK)

#define GENFSK_ENH_FEATURE_LENGTH_ACK_MASK       (0x7FF0000U)
#define GENFSK_ENH_FEATURE_LENGTH_ACK_SHIFT      (16U)
/*! LENGTH_ACK - Length of the ACK frame(or part of the ACK frame) in RAM */
#define GENFSK_ENH_FEATURE_LENGTH_ACK(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_LENGTH_ACK_SHIFT)) & GENFSK_ENH_FEATURE_LENGTH_ACK_MASK)

#define GENFSK_ENH_FEATURE_BLE_V5P1_CTE_EN_MASK  (0x80000000U)
#define GENFSK_ENH_FEATURE_BLE_V5P1_CTE_EN_SHIFT (31U)
/*! BLE_V5P1_CTE_EN - Bluetooth LE version 5.1 CTE feature enable
 *  0b0..Do not support Bluetooth LE version 5.1 CTE feature.
 *  0b1..Support Bluetooth LE version 5.1 CTE feature, which means the link layer hardware can parse the CTE field
 *       length and extend the RX_EN signal accordingly.
 */
#define GENFSK_ENH_FEATURE_BLE_V5P1_CTE_EN(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_ENH_FEATURE_BLE_V5P1_CTE_EN_SHIFT)) & GENFSK_ENH_FEATURE_BLE_V5P1_CTE_EN_MASK)
/*! @} */

/*! @name RX_FRAME_FILTER - RECEIVE FRAME FILTER */
/*! @{ */

#define GENFSK_RX_FRAME_FILTER_BEACON_FT_MASK    (0x1U)
#define GENFSK_RX_FRAME_FILTER_BEACON_FT_SHIFT   (0U)
/*! BEACON_FT - Beacon Frame Type Enable
 *  0b0..reject all Beacon frames
 *  0b1..Beacon frame type enabled.
 */
#define GENFSK_RX_FRAME_FILTER_BEACON_FT(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_BEACON_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_BEACON_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_DATA_FT_MASK      (0x2U)
#define GENFSK_RX_FRAME_FILTER_DATA_FT_SHIFT     (1U)
/*! DATA_FT - Data Frame Type Enable
 *  0b0..reject all Beacon frames
 *  0b1..Data frame type enabled.
 */
#define GENFSK_RX_FRAME_FILTER_DATA_FT(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_DATA_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_DATA_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_ACK_FT_MASK       (0x4U)
#define GENFSK_RX_FRAME_FILTER_ACK_FT_SHIFT      (2U)
/*! ACK_FT - Ack Frame Type Enable
 *  0b0..reject all Acknowledge frames
 *  0b1..Acknowledge frame type enabled.
 */
#define GENFSK_RX_FRAME_FILTER_ACK_FT(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_ACK_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_ACK_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_CMD_FT_MASK       (0x8U)
#define GENFSK_RX_FRAME_FILTER_CMD_FT_SHIFT      (3U)
/*! CMD_FT - MAC Command Frame Type Enable
 *  0b0..reject all MAC Command frames
 *  0b1..MAC Command frame type enabled.
 */
#define GENFSK_RX_FRAME_FILTER_CMD_FT(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_CMD_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_CMD_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_LLDN_FT_MASK      (0x10U)
#define GENFSK_RX_FRAME_FILTER_LLDN_FT_SHIFT     (4U)
/*! LLDN_FT - LLDN Frame Type Enable
 *  0b0..reject all LLDN frames
 *  0b1..LLDN frame type enabled (Frame Type 4).
 */
#define GENFSK_RX_FRAME_FILTER_LLDN_FT(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_LLDN_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_LLDN_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_FT_MASK (0x20U)
#define GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_FT_SHIFT (5U)
/*! MULTIPURPOSE_FT - Multipurpose Frame Type Enable
 *  0b0..reject all Multipurpose frames
 *  0b1..Multipurpose frame type enabled (Frame Type 5).
 */
#define GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_FT(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_FRAGMENT_FT_MASK  (0x40U)
#define GENFSK_RX_FRAME_FILTER_FRAGMENT_FT_SHIFT (6U)
/*! FRAGMENT_FT - Fragment Frame Type Enable
 *  0b0..reject all Fragment frames
 *  0b1..Fragment frame type enabled (Frame Type 6).
 */
#define GENFSK_RX_FRAME_FILTER_FRAGMENT_FT(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FRAGMENT_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_FRAGMENT_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_EXTENDED_FT_MASK  (0x80U)
#define GENFSK_RX_FRAME_FILTER_EXTENDED_FT_SHIFT (7U)
/*! EXTENDED_FT - Extended Frame Type Enable
 *  0b0..reject all Extended frames
 *  0b1..Extended frame type enabled (Frame Type 7).
 */
#define GENFSK_RX_FRAME_FILTER_EXTENDED_FT(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_EXTENDED_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_EXTENDED_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_NS_FT_MASK        (0x100U)
#define GENFSK_RX_FRAME_FILTER_NS_FT_SHIFT       (8U)
/*! NS_FT - "Not Specified" Frame Type Enable
 *  0b0..reject all "Not Specified" frames
 *  0b1..Not-specified (reserved) frame type enabled. Applies to Frame Type 6. No packet filtering is performed,
 *       except for frame length checking (FrameLength>=5 and FrameLength<=127). No AUTOACK is transmitted for this
 *       Frame Type
 */
#define GENFSK_RX_FRAME_FILTER_NS_FT(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_NS_FT_SHIFT)) & GENFSK_RX_FRAME_FILTER_NS_FT_MASK)

#define GENFSK_RX_FRAME_FILTER_FRM_VER_FILTER_MASK (0x1E00U)
#define GENFSK_RX_FRAME_FILTER_FRM_VER_FILTER_SHIFT (9U)
/*! FRM_VER_FILTER - Frame Version selector. */
#define GENFSK_RX_FRAME_FILTER_FRM_VER_FILTER(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FRM_VER_FILTER_SHIFT)) & GENFSK_RX_FRAME_FILTER_FRM_VER_FILTER_MASK)

#define GENFSK_RX_FRAME_FILTER_EXTENDED_FCS_CHK_MASK (0x8000U)
#define GENFSK_RX_FRAME_FILTER_EXTENDED_FCS_CHK_SHIFT (15U)
/*! EXTENDED_FCS_CHK - Verify FCS on Frame Type Extended
 *  0b0..Packet Processor will not check FCS for Frame Type EXTENDED (default)
 *  0b1..Packet Processor will check FCS at end-of-packet based on packet length derived from PHR, for Frame Type EXTENDED
 */
#define GENFSK_RX_FRAME_FILTER_EXTENDED_FCS_CHK(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_EXTENDED_FCS_CHK_SHIFT)) & GENFSK_RX_FRAME_FILTER_EXTENDED_FCS_CHK_MASK)

#define GENFSK_RX_FRAME_FILTER_FV2_BEACON_RECD_MASK (0x10000U)
#define GENFSK_RX_FRAME_FILTER_FV2_BEACON_RECD_SHIFT (16U)
/*! FV2_BEACON_RECD - Frame Version 2 Beacon Packet Received
 *  0b0..The last packet received was not Frame Type Beacon with Frame Version 2
 *  0b1..The last packet received was Frame Type Beacon with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define GENFSK_RX_FRAME_FILTER_FV2_BEACON_RECD(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FV2_BEACON_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_FV2_BEACON_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_FV2_DATA_RECD_MASK (0x20000U)
#define GENFSK_RX_FRAME_FILTER_FV2_DATA_RECD_SHIFT (17U)
/*! FV2_DATA_RECD - Frame Version 2 Data Packet Received
 *  0b0..The last packet received was not Frame Type Data with Frame Version 2
 *  0b1..The last packet received was Frame Type Data with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define GENFSK_RX_FRAME_FILTER_FV2_DATA_RECD(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FV2_DATA_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_FV2_DATA_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_FV2_ACK_RECD_MASK (0x40000U)
#define GENFSK_RX_FRAME_FILTER_FV2_ACK_RECD_SHIFT (18U)
/*! FV2_ACK_RECD - Frame Version 2 Acknowledge Packet Received
 *  0b0..The last packet received was not Frame Type Ack with Frame Version 2
 *  0b1..The last packet received was Frame Type Ack with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define GENFSK_RX_FRAME_FILTER_FV2_ACK_RECD(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FV2_ACK_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_FV2_ACK_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_FV2_CMD_RECD_MASK (0x80000U)
#define GENFSK_RX_FRAME_FILTER_FV2_CMD_RECD_SHIFT (19U)
/*! FV2_CMD_RECD - Frame Version 2 MAC Command Packet Received
 *  0b0..The last packet received was not Frame Type MAC Command with Frame Version 2
 *  0b1..The last packet received was Frame Type MAC Command with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define GENFSK_RX_FRAME_FILTER_FV2_CMD_RECD(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FV2_CMD_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_FV2_CMD_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_LLDN_RECD_MASK    (0x100000U)
#define GENFSK_RX_FRAME_FILTER_LLDN_RECD_SHIFT   (20U)
/*! LLDN_RECD - LLDN Packet Received
 *  0b0..The last packet received was not Frame Type LLDN
 *  0b1..The last packet received was Frame Type LLDN, and LLDN_FT=1 to allow such packets.
 */
#define GENFSK_RX_FRAME_FILTER_LLDN_RECD(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_LLDN_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_LLDN_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_RECD_MASK (0x200000U)
#define GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_RECD_SHIFT (21U)
/*! MULTIPURPOSE_RECD - Multipurpose Packet Received
 *  0b0..last packet received was not Frame Type MULTIPURPOSE
 *  0b1..The last packet received was Frame Type MULTIPURPOSE, and MULTIPURPOSE_FT=1 to allow such packets.
 */
#define GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_RECD(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_MULTIPURPOSE_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_FRAGMENT_RECD_MASK (0x400000U)
#define GENFSK_RX_FRAME_FILTER_FRAGMENT_RECD_SHIFT (22U)
/*! FRAGMENT_RECD - Fragment Packet Received
 *  0b0..last packet received was not Frame Type FRAGMENT
 *  0b1..The last packet received was Frame Type FRAGMENT, and FRAGMENT_FT=1 to allow such packets.
 */
#define GENFSK_RX_FRAME_FILTER_FRAGMENT_RECD(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FRAGMENT_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_FRAGMENT_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_EXTENDED_RECD_MASK (0x800000U)
#define GENFSK_RX_FRAME_FILTER_EXTENDED_RECD_SHIFT (23U)
/*! EXTENDED_RECD - Extended Packet Received
 *  0b0..The last packet received was not Frame Type EXTENDED
 *  0b1..The last packet received was Frame Type EXTENDED, and EXTENDED_FT=1 to allow such packets.
 */
#define GENFSK_RX_FRAME_FILTER_EXTENDED_RECD(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_EXTENDED_RECD_SHIFT)) & GENFSK_RX_FRAME_FILTER_EXTENDED_RECD_MASK)

#define GENFSK_RX_FRAME_FILTER_RXCYC_SEL_MASK    (0x10000000U)
#define GENFSK_RX_FRAME_FILTER_RXCYC_SEL_SHIFT   (28U)
/*! RXCYC_SEL - Rx Recycle Time Select
 *  0b0..Recycle when fail happens.
 *  0b1..Recycle when Rx done and fail happens.
 */
#define GENFSK_RX_FRAME_FILTER_RXCYC_SEL(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_RXCYC_SEL_SHIFT)) & GENFSK_RX_FRAME_FILTER_RXCYC_SEL_MASK)

#define GENFSK_RX_FRAME_FILTER_FILTER_FAIL_IGNORE_MASK (0x20000000U)
#define GENFSK_RX_FRAME_FILTER_FILTER_FAIL_IGNORE_SHIFT (29U)
/*! FILTER_FAIL_IGNORE - Filter Fail Ignore
 *  0b0..RX_IRQ will not be asserted when filter fail.
 *  0b1..RX_IRQ will be asserted when filter fail.
 */
#define GENFSK_RX_FRAME_FILTER_FILTER_FAIL_IGNORE(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_FILTER_FAIL_IGNORE_SHIFT)) & GENFSK_RX_FRAME_FILTER_FILTER_FAIL_IGNORE_MASK)

#define GENFSK_RX_FRAME_FILTER_PROMISCUOUS_MASK  (0x40000000U)
#define GENFSK_RX_FRAME_FILTER_PROMISCUOUS_SHIFT (30U)
/*! PROMISCUOUS - Promiscuous Mode Enable
 *  0b0..normal mode
 *  0b1..all packet filtering except frame length checking (FrameLength>=5) is bypassed.
 */
#define GENFSK_RX_FRAME_FILTER_PROMISCUOUS(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_PROMISCUOUS_SHIFT)) & GENFSK_RX_FRAME_FILTER_PROMISCUOUS_MASK)

#define GENFSK_RX_FRAME_FILTER_ENH_PKT_STATUS_MASK (0x80000000U)
#define GENFSK_RX_FRAME_FILTER_ENH_PKT_STATUS_SHIFT (31U)
/*! ENH_PKT_STATUS - Enhanced Packet Status
 *  0b0..The last packet received was not 2015-compliant
 *  0b1..The last packet received was 2015-compliant (RX_FRAME_FILTER register should be queried for additional status bits)
 */
#define GENFSK_RX_FRAME_FILTER_ENH_PKT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_FRAME_FILTER_ENH_PKT_STATUS_SHIFT)) & GENFSK_RX_FRAME_FILTER_ENH_PKT_STATUS_MASK)
/*! @} */

/*! @name FILTERFAIL_CODE - FILTER FAIL CODE */
/*! @{ */

#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_PAN_MASK (0x3FFU)
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_PAN_SHIFT (0U)
/*! FILTERFAIL_CODE_PAN - Filter Fail Code When in PAN Mode */
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_PAN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_PAN_SHIFT)) & GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_PAN_MASK)

#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_FAN_MASK (0x30000U)
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_FAN_SHIFT (16U)
/*! FILTERFAIL_CODE_FAN - Filter Fail Code When in FAN Mode */
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_FAN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_FAN_SHIFT)) & GENFSK_FILTERFAIL_CODE_FILTERFAIL_CODE_FAN_MASK)

#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_MASK (0x40000000U)
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_SHIFT (30U)
/*! FILTERFAIL_PAN_SEL - PAN Selector for Filter Fail Code
 *  0b0..FILTERFAIL_CODE_PAN/FILTERFAIL_CODE_FAN will report the FILTERFAIL status of PAN0
 *  0b1..FILTERFAIL_CODE_PAN/FILTERFAIL_CODE_FAN will report the FILTERFAIL status of PAN1
 */
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_SHIFT)) & GENFSK_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_MASK)

#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_FLAG_SEL_MASK (0x80000000U)
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_FLAG_SEL_SHIFT (31U)
/*! FILTERFAIL_FLAG_SEL - Consolidated Filter Fail Flag */
#define GENFSK_FILTERFAIL_CODE_FILTERFAIL_FLAG_SEL(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_FILTERFAIL_CODE_FILTERFAIL_FLAG_SEL_SHIFT)) & GENFSK_FILTERFAIL_CODE_FILTERFAIL_FLAG_SEL_MASK)
/*! @} */

/*! @name LENIENCY_LSB - LENIENCY LSB */
/*! @{ */

#define GENFSK_LENIENCY_LSB_LENIENCY_LSB_MASK    (0xFFFFFFFFU)
#define GENFSK_LENIENCY_LSB_LENIENCY_LSB_SHIFT   (0U)
/*! LENIENCY_LSB - Leniency LSB Register */
#define GENFSK_LENIENCY_LSB_LENIENCY_LSB(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_LENIENCY_LSB_LENIENCY_LSB_SHIFT)) & GENFSK_LENIENCY_LSB_LENIENCY_LSB_MASK)
/*! @} */

/*! @name RPA_CTRL - RPA CONTROL */
/*! @{ */

#define GENFSK_RPA_CTRL_RPA_VALID_ENTRY_MASK     (0xFFU)
#define GENFSK_RPA_CTRL_RPA_VALID_ENTRY_SHIFT    (0U)
#define GENFSK_RPA_CTRL_RPA_VALID_ENTRY(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_CTRL_RPA_VALID_ENTRY_SHIFT)) & GENFSK_RPA_CTRL_RPA_VALID_ENTRY_MASK)

#define GENFSK_RPA_CTRL_IGNORE_RPA_FAIL_MASK     (0x8000000U)
#define GENFSK_RPA_CTRL_IGNORE_RPA_FAIL_SHIFT    (27U)
/*! IGNORE_RPA_FAIL
 *  0b0..link layer aborts the Rx process when LOCAL_RPA_FAIL_IRQ or PEER_RPA_FAIL_IRQ
 *  0b1..link layer ignores LOCAL_RPA_FAIL_IRQ and PEER_RPA_FAIL_IRQ.
 */
#define GENFSK_RPA_CTRL_IGNORE_RPA_FAIL(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_CTRL_IGNORE_RPA_FAIL_SHIFT)) & GENFSK_RPA_CTRL_IGNORE_RPA_FAIL_MASK)

#define GENFSK_RPA_CTRL_IGNORE_DIRECT_FAIL_MASK  (0x10000000U)
#define GENFSK_RPA_CTRL_IGNORE_DIRECT_FAIL_SHIFT (28U)
/*! IGNORE_DIRECT_FAIL
 *  0b0..link layer aborts the Rx process when DIRECT_ID_FAIL_IRQ
 *  0b1..link layer ignores DIRECT_ID_FAIL_IRQ.
 */
#define GENFSK_RPA_CTRL_IGNORE_DIRECT_FAIL(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_CTRL_IGNORE_DIRECT_FAIL_SHIFT)) & GENFSK_RPA_CTRL_IGNORE_DIRECT_FAIL_MASK)

#define GENFSK_RPA_CTRL_ADV_DIRECT_IND_SENT_MASK (0x20000000U)
#define GENFSK_RPA_CTRL_ADV_DIRECT_IND_SENT_SHIFT (29U)
#define GENFSK_RPA_CTRL_ADV_DIRECT_IND_SENT(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_CTRL_ADV_DIRECT_IND_SENT_SHIFT)) & GENFSK_RPA_CTRL_ADV_DIRECT_IND_SENT_MASK)

#define GENFSK_RPA_CTRL_RPA_EN_MASK              (0x40000000U)
#define GENFSK_RPA_CTRL_RPA_EN_SHIFT             (30U)
/*! RPA_EN
 *  0b0..The RPA check is disabled.
 *  0b1..The RPA check is enabled.
 */
#define GENFSK_RPA_CTRL_RPA_EN(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_CTRL_RPA_EN_SHIFT)) & GENFSK_RPA_CTRL_RPA_EN_MASK)

#define GENFSK_RPA_CTRL_ADV_CHANNEL_EN_MASK      (0x80000000U)
#define GENFSK_RPA_CTRL_ADV_CHANNEL_EN_SHIFT     (31U)
/*! ADV_CHANNEL_EN
 *  0b0..The packet to be received is in Data Channel PDU.
 *  0b1..The packet to be received is in Advertising Channel PDU.
 */
#define GENFSK_RPA_CTRL_ADV_CHANNEL_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_RPA_CTRL_ADV_CHANNEL_EN_SHIFT)) & GENFSK_RPA_CTRL_ADV_CHANNEL_EN_MASK)
/*! @} */

/*! @name LENIENCY_MSB - LENIENCY MSB */
/*! @{ */

#define GENFSK_LENIENCY_MSB_LENIENCY_MSB_MASK    (0x1FFFU)
#define GENFSK_LENIENCY_MSB_LENIENCY_MSB_SHIFT   (0U)
/*! LENIENCY_MSB - Leniency MSB Register */
#define GENFSK_LENIENCY_MSB_LENIENCY_MSB(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_LENIENCY_MSB_LENIENCY_MSB_SHIFT)) & GENFSK_LENIENCY_MSB_LENIENCY_MSB_MASK)
/*! @} */

/*! @name WL_CTRL - WHITE LIST CONTROL */
/*! @{ */

#define GENFSK_WL_CTRL_WL_EN_MASK                (0x1U)
#define GENFSK_WL_CTRL_WL_EN_SHIFT               (0U)
/*! WL_EN
 *  0b0..White list search is not enabled
 *  0b1..White list search is enabled
 */
#define GENFSK_WL_CTRL_WL_EN(x)                  (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_CTRL_WL_EN_SHIFT)) & GENFSK_WL_CTRL_WL_EN_MASK)

#define GENFSK_WL_CTRL_WL_SEL_MASK               (0x2U)
#define GENFSK_WL_CTRL_WL_SEL_SHIFT              (1U)
/*! WL_SEL
 *  0b0..Select white list 0
 *  0b1..Select white list 1
 */
#define GENFSK_WL_CTRL_WL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_CTRL_WL_SEL_SHIFT)) & GENFSK_WL_CTRL_WL_SEL_MASK)

#define GENFSK_WL_CTRL_IGNORE_WL_FAIL_MASK       (0x8U)
#define GENFSK_WL_CTRL_IGNORE_WL_FAIL_SHIFT      (3U)
/*! IGNORE_WL_FAIL
 *  0b0..link layer aborts the Rx process when WL_FAIL_IRQ
 *  0b1..link layer ignores WL_FAIL_IRQ.
 */
#define GENFSK_WL_CTRL_IGNORE_WL_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_CTRL_IGNORE_WL_FAIL_SHIFT)) & GENFSK_WL_CTRL_IGNORE_WL_FAIL_MASK)
/*! @} */

/*! @name DUAL_PAN_CTRL - DUAL PAN CONTROL */
/*! @{ */

#define GENFSK_DUAL_PAN_CTRL_ACTIVE_NETWORK_MASK (0x1U)
#define GENFSK_DUAL_PAN_CTRL_ACTIVE_NETWORK_SHIFT (0U)
/*! ACTIVE_NETWORK - Active Network Selector
 *  0b0..Select PAN0
 *  0b1..Select PAN1
 */
#define GENFSK_DUAL_PAN_CTRL_ACTIVE_NETWORK(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_ACTIVE_NETWORK_SHIFT)) & GENFSK_DUAL_PAN_CTRL_ACTIVE_NETWORK_MASK)

#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_AUTO_MASK  (0x2U)
#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_AUTO_SHIFT (1U)
/*! DUAL_PAN_AUTO - Activates automatic Dual PAN operating mode */
#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_AUTO(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_DUAL_PAN_AUTO_SHIFT)) & GENFSK_DUAL_PAN_CTRL_DUAL_PAN_AUTO_MASK)

#define GENFSK_DUAL_PAN_CTRL_CURRENT_NETWORK_MASK (0x4U)
#define GENFSK_DUAL_PAN_CTRL_CURRENT_NETWORK_SHIFT (2U)
/*! CURRENT_NETWORK - Indicates which PAN is currently selected by hardware
 *  0b0..PAN0 is selected
 *  0b1..PAN1 is selected
 */
#define GENFSK_DUAL_PAN_CTRL_CURRENT_NETWORK(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_CURRENT_NETWORK_SHIFT)) & GENFSK_DUAL_PAN_CTRL_CURRENT_NETWORK_MASK)

#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_DWELL_MASK (0xFF00U)
#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_DWELL_SHIFT (8U)
/*! DUAL_PAN_DWELL - Dual PAN Channel Frequency Dwell Time */
#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_DWELL(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_DUAL_PAN_DWELL_SHIFT)) & GENFSK_DUAL_PAN_CTRL_DUAL_PAN_DWELL_MASK)

#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_MASK (0x3F0000U)
#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_SHIFT (16U)
/*! DUAL_PAN_REMAIN - Time Remaining before next PAN switch in auto Dual PAN mode */
#define GENFSK_DUAL_PAN_CTRL_DUAL_PAN_REMAIN(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_SHIFT)) & GENFSK_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_MASK)

#define GENFSK_DUAL_PAN_CTRL_MODE_PAN0_MASK      (0x1000000U)
#define GENFSK_DUAL_PAN_CTRL_MODE_PAN0_SHIFT     (24U)
/*! MODE_PAN0 - PAN0 Mode Select
 *  0b0..PAN0 is in PAN mode
 *  0b1..PAN0 is in FAN mode
 */
#define GENFSK_DUAL_PAN_CTRL_MODE_PAN0(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_MODE_PAN0_SHIFT)) & GENFSK_DUAL_PAN_CTRL_MODE_PAN0_MASK)

#define GENFSK_DUAL_PAN_CTRL_MODE_PAN1_MASK      (0x2000000U)
#define GENFSK_DUAL_PAN_CTRL_MODE_PAN1_SHIFT     (25U)
/*! MODE_PAN1 - PAN1 Mode Select
 *  0b0..PAN1 is in PAN mode
 *  0b1..PAN1 is in FAN mode
 */
#define GENFSK_DUAL_PAN_CTRL_MODE_PAN1(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_MODE_PAN1_SHIFT)) & GENFSK_DUAL_PAN_CTRL_MODE_PAN1_MASK)

#define GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_EN_MASK (0x4000000U)
#define GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_EN_SHIFT (26U)
/*! DP_CHAN_OVRD_EN - Dual PAN Channel Override Enable */
#define GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_EN_SHIFT)) & GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_EN_MASK)

#define GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_SEL_MASK (0x8000000U)
#define GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_SEL_SHIFT (27U)
/*! DP_CHAN_OVRD_SEL - Dual PAN Channel Override Selector */
#define GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_SEL(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_SEL_SHIFT)) & GENFSK_DUAL_PAN_CTRL_DP_CHAN_OVRD_SEL_MASK)

#define GENFSK_DUAL_PAN_CTRL_PANCORDNTR0_MASK    (0x10000000U)
#define GENFSK_DUAL_PAN_CTRL_PANCORDNTR0_SHIFT   (28U)
/*! PANCORDNTR0 - Device is a PAN Coordinator on PAN0 */
#define GENFSK_DUAL_PAN_CTRL_PANCORDNTR0(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_PANCORDNTR0_SHIFT)) & GENFSK_DUAL_PAN_CTRL_PANCORDNTR0_MASK)

#define GENFSK_DUAL_PAN_CTRL_PANCORDNTR1_MASK    (0x20000000U)
#define GENFSK_DUAL_PAN_CTRL_PANCORDNTR1_SHIFT   (29U)
/*! PANCORDNTR1 - Device is a PAN Coordinator on PAN1 */
#define GENFSK_DUAL_PAN_CTRL_PANCORDNTR1(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_PANCORDNTR1_SHIFT)) & GENFSK_DUAL_PAN_CTRL_PANCORDNTR1_MASK)

#define GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN0_MASK   (0x40000000U)
#define GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN0_SHIFT  (30U)
/*! RECD_ON_PAN0 - Last Packet was Received on PAN0 */
#define GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN0(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN0_SHIFT)) & GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN0_MASK)

#define GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN1_MASK   (0x80000000U)
#define GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN1_SHIFT  (31U)
/*! RECD_ON_PAN1 - Last Packet was Received on PAN1 */
#define GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN1(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN1_SHIFT)) & GENFSK_DUAL_PAN_CTRL_RECD_ON_PAN1_MASK)
/*! @} */

/*! @name GTM_PDU - GTM MODE PDU */
/*! @{ */

#define GENFSK_GTM_PDU_GTM_PDU_MASK              (0xFFFFFFFFU)
#define GENFSK_GTM_PDU_GTM_PDU_SHIFT             (0U)
/*! GTM_PDU - GTM MODE PDU */
#define GENFSK_GTM_PDU_GTM_PDU(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_PDU_GTM_PDU_SHIFT)) & GENFSK_GTM_PDU_GTM_PDU_MASK)
/*! @} */

/*! @name MACSHORTADDRS1 - MAC SHORT ADDRESS FOR PAN1 */
/*! @{ */

#define GENFSK_MACSHORTADDRS1_MACPANID1_MASK     (0xFFFFU)
#define GENFSK_MACSHORTADDRS1_MACPANID1_SHIFT    (0U)
/*! MACPANID1 - MAC PAN ID for PAN1 */
#define GENFSK_MACSHORTADDRS1_MACPANID1(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_MACSHORTADDRS1_MACPANID1_SHIFT)) & GENFSK_MACSHORTADDRS1_MACPANID1_MASK)

#define GENFSK_MACSHORTADDRS1_MACSHORTADDRS1_MASK (0xFFFF0000U)
#define GENFSK_MACSHORTADDRS1_MACSHORTADDRS1_SHIFT (16U)
/*! MACSHORTADDRS1 - MAC SHORT ADDRESS for PAN1 */
#define GENFSK_MACSHORTADDRS1_MACSHORTADDRS1(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_MACSHORTADDRS1_MACSHORTADDRS1_SHIFT)) & GENFSK_MACSHORTADDRS1_MACSHORTADDRS1_MASK)
/*! @} */

/*! @name WL_VALID_ENTRY1 - VALID ENTRY OF WHITE LIST 1 */
/*! @{ */

#define GENFSK_WL_VALID_ENTRY1_WL_VALID_ENTRY1_MASK (0xFFFFFFFFU)
#define GENFSK_WL_VALID_ENTRY1_WL_VALID_ENTRY1_SHIFT (0U)
#define GENFSK_WL_VALID_ENTRY1_WL_VALID_ENTRY1(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_VALID_ENTRY1_WL_VALID_ENTRY1_SHIFT)) & GENFSK_WL_VALID_ENTRY1_WL_VALID_ENTRY1_MASK)
/*! @} */

/*! @name DIRECT_PEER_ADDR_LSB - DIRECT_PEER_ADDR[31:0] */
/*! @{ */

#define GENFSK_DIRECT_PEER_ADDR_LSB_DIRECT_PEER_ADDR_LSB_MASK (0xFFFFFFFFU)
#define GENFSK_DIRECT_PEER_ADDR_LSB_DIRECT_PEER_ADDR_LSB_SHIFT (0U)
#define GENFSK_DIRECT_PEER_ADDR_LSB_DIRECT_PEER_ADDR_LSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_DIRECT_PEER_ADDR_LSB_DIRECT_PEER_ADDR_LSB_SHIFT)) & GENFSK_DIRECT_PEER_ADDR_LSB_DIRECT_PEER_ADDR_LSB_MASK)
/*! @} */

/*! @name GTM_CFG - GTM MODE CONFIGURATION */
/*! @{ */

#define GENFSK_GTM_CFG_GTM_PKT_NUM_MASK          (0xFFFU)
#define GENFSK_GTM_CFG_GTM_PKT_NUM_SHIFT         (0U)
/*! GTM_PKT_NUM - GTM MODE PACKET NUMBER */
#define GENFSK_GTM_CFG_GTM_PKT_NUM(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_CFG_GTM_PKT_NUM_SHIFT)) & GENFSK_GTM_CFG_GTM_PKT_NUM_MASK)

#define GENFSK_GTM_CFG_GTM_PDU_TYPE_MASK         (0xF000000U)
#define GENFSK_GTM_CFG_GTM_PDU_TYPE_SHIFT        (24U)
/*! GTM_PDU_TYPE - GTM MODE PDU TYPE SELECTION
 *  0b0000..PRBS9 Sequence
 *  0b0001..Programmable 8-bit Pattern (from register GTM_PDU[7:0], reused from MACSHORTADDRS1[7:0])
 *  0b0010..PRBS-13 Sequence
 *  0b0011..PRBS-15 Sequence
 *  0b0100..Programmable 32-bit Pattern (from register GTM_PDU[31:0], reused from {MACSHORTADDRS1,MACPANID1})
 *  0b0101..Programmable packet from Packet RAM (in this case, PKT_LEN is ignored)
 */
#define GENFSK_GTM_CFG_GTM_PDU_TYPE(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_CFG_GTM_PDU_TYPE_SHIFT)) & GENFSK_GTM_CFG_GTM_PDU_TYPE_MASK)

#define GENFSK_GTM_CFG_GTM_IPD_CHECK_DIS_MASK    (0x40000000U)
#define GENFSK_GTM_CFG_GTM_IPD_CHECK_DIS_SHIFT   (30U)
/*! GTM_IPD_CHECK_DIS - GTM MODE INTER-PACKET DURATION CHECK DISABLE */
#define GENFSK_GTM_CFG_GTM_IPD_CHECK_DIS(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_CFG_GTM_IPD_CHECK_DIS_SHIFT)) & GENFSK_GTM_CFG_GTM_IPD_CHECK_DIS_MASK)

#define GENFSK_GTM_CFG_GTM_PKT_COUNT_CHECK_DIS_MASK (0x80000000U)
#define GENFSK_GTM_CFG_GTM_PKT_COUNT_CHECK_DIS_SHIFT (31U)
/*! GTM_PKT_COUNT_CHECK_DIS - GTM MODE PACKET NUMBER CHECK DISABLE */
#define GENFSK_GTM_CFG_GTM_PKT_COUNT_CHECK_DIS(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_CFG_GTM_PKT_COUNT_CHECK_DIS_SHIFT)) & GENFSK_GTM_CFG_GTM_PKT_COUNT_CHECK_DIS_MASK)
/*! @} */

/*! @name MACLONGADDRS1_LSB - MAC LONG ADDRESS 1 LSB */
/*! @{ */

#define GENFSK_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_MASK (0xFFFFFFFFU)
#define GENFSK_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_SHIFT (0U)
/*! MACLONGADDRS1_LSB - MAC LONG ADDRESS for PAN1 LSB */
#define GENFSK_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_SHIFT)) & GENFSK_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_MASK)
/*! @} */

/*! @name DIRECT_PEER_ADDR_MSB - DIRECT_PEER_ADDR[47:32] */
/*! @{ */

#define GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_MSB_MASK (0xFFFFU)
#define GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_MSB_SHIFT (0U)
#define GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_MSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_MSB_SHIFT)) & GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_MSB_MASK)

#define GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_TYPE_MASK (0x80000000U)
#define GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_TYPE_SHIFT (31U)
/*! DIRECT_PEER_ADDR_TYPE
 *  0b0..Direct peer device address type is public.
 *  0b1..Direct peer device address type is random.
 */
#define GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_TYPE(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_TYPE_SHIFT)) & GENFSK_DIRECT_PEER_ADDR_MSB_DIRECT_PEER_ADDR_TYPE_MASK)
/*! @} */

/*! @name GTM_IPD - GTM MODE INTER-PACKET DURATION */
/*! @{ */

#define GENFSK_GTM_IPD_GTM_IPD_MASK              (0xFFFFFU)
#define GENFSK_GTM_IPD_GTM_IPD_SHIFT             (0U)
/*! GTM_IPD - GTM MODE INTER-PACKET DURATION */
#define GENFSK_GTM_IPD_GTM_IPD(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_IPD_GTM_IPD_SHIFT)) & GENFSK_GTM_IPD_GTM_IPD_MASK)
/*! @} */

/*! @name MACLONGADDRS1_MSB - MAC LONG ADDRESS 1 MSB */
/*! @{ */

#define GENFSK_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_MASK (0xFFFFFFFFU)
#define GENFSK_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_SHIFT (0U)
/*! MACLONGADDRS1_MSB - MAC LONG ADDRESS for PAN1 MSB */
#define GENFSK_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_SHIFT)) & GENFSK_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_MASK)
/*! @} */

/*! @name CHANNEL_NUM1 - CHANNEL NUMBER 1 */
/*! @{ */

#define GENFSK_CHANNEL_NUM1_CHANNEL_NUM1_MASK    (0x7FU)
#define GENFSK_CHANNEL_NUM1_CHANNEL_NUM1_SHIFT   (0U)
/*! CHANNEL_NUM1 - Channel Number for PAN1 */
#define GENFSK_CHANNEL_NUM1_CHANNEL_NUM1(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_CHANNEL_NUM1_CHANNEL_NUM1_SHIFT)) & GENFSK_CHANNEL_NUM1_CHANNEL_NUM1_MASK)
/*! @} */

/*! @name MACSHORTADDRS0 - MAC SHORT ADDRESS 0 */
/*! @{ */

#define GENFSK_MACSHORTADDRS0_MACPANID0_MASK     (0xFFFFU)
#define GENFSK_MACSHORTADDRS0_MACPANID0_SHIFT    (0U)
/*! MACPANID0 - MAC PAN ID for PAN0 */
#define GENFSK_MACSHORTADDRS0_MACPANID0(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_MACSHORTADDRS0_MACPANID0_SHIFT)) & GENFSK_MACSHORTADDRS0_MACPANID0_MASK)

#define GENFSK_MACSHORTADDRS0_MACSHORTADDRS0_MASK (0xFFFF0000U)
#define GENFSK_MACSHORTADDRS0_MACSHORTADDRS0_SHIFT (16U)
/*! MACSHORTADDRS0 - MAC SHORT ADDRESS FOR PAN0 */
#define GENFSK_MACSHORTADDRS0_MACSHORTADDRS0(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_MACSHORTADDRS0_MACSHORTADDRS0_SHIFT)) & GENFSK_MACSHORTADDRS0_MACSHORTADDRS0_MASK)
/*! @} */

/*! @name WL_VALID_ENTRY0 - VALID ENTRY OF WHITE LIST 0 */
/*! @{ */

#define GENFSK_WL_VALID_ENTRY0_WL_VALID_ENTRY0_MASK (0xFFFFFFFFU)
#define GENFSK_WL_VALID_ENTRY0_WL_VALID_ENTRY0_SHIFT (0U)
#define GENFSK_WL_VALID_ENTRY0_WL_VALID_ENTRY0(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_VALID_ENTRY0_WL_VALID_ENTRY0_SHIFT)) & GENFSK_WL_VALID_ENTRY0_WL_VALID_ENTRY0_MASK)
/*! @} */

/*! @name GTM_FIRST_SFD2WD - GTM MODE TIME OF FIRST SFD FOUND TO FORCE RX WARM-DOWN */
/*! @{ */

#define GENFSK_GTM_FIRST_SFD2WD_GTM_FIRST_SFD2WD_MASK (0xFFFFFU)
#define GENFSK_GTM_FIRST_SFD2WD_GTM_FIRST_SFD2WD_SHIFT (0U)
/*! GTM_FIRST_SFD2WD - GTM MODE TIME OF FIRST SFD FOUND TO FORCE RX WARMDOWN */
#define GENFSK_GTM_FIRST_SFD2WD_GTM_FIRST_SFD2WD(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_FIRST_SFD2WD_GTM_FIRST_SFD2WD_SHIFT)) & GENFSK_GTM_FIRST_SFD2WD_GTM_FIRST_SFD2WD_MASK)
/*! @} */

/*! @name MACLONGADDRS0_LSB - MAC LONG ADDRESS 0 LSB */
/*! @{ */

#define GENFSK_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_MASK (0xFFFFFFFFU)
#define GENFSK_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_SHIFT (0U)
/*! MACLONGADDRS0_LSB - MAC LONG ADDRESS for PAN0 LSB */
#define GENFSK_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_SHIFT)) & GENFSK_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_MASK)
/*! @} */

/*! @name WL_SEARCH_ADDR_LSB - WL_SEARCH_ADDR[31:0] */
/*! @{ */

#define GENFSK_WL_SEARCH_ADDR_LSB_WL_SEARCH_ADDR_LSB_MASK (0xFFFFFFFFU)
#define GENFSK_WL_SEARCH_ADDR_LSB_WL_SEARCH_ADDR_LSB_SHIFT (0U)
#define GENFSK_WL_SEARCH_ADDR_LSB_WL_SEARCH_ADDR_LSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_SEARCH_ADDR_LSB_WL_SEARCH_ADDR_LSB_SHIFT)) & GENFSK_WL_SEARCH_ADDR_LSB_WL_SEARCH_ADDR_LSB_MASK)
/*! @} */

/*! @name GTM_RX_RECYCLE_TIME - GTM MODE RX RECYCLE TIME */
/*! @{ */

#define GENFSK_GTM_RX_RECYCLE_TIME_GTM_RX_RECYCLE_TIME_MASK (0xFFFFFU)
#define GENFSK_GTM_RX_RECYCLE_TIME_GTM_RX_RECYCLE_TIME_SHIFT (0U)
/*! GTM_RX_RECYCLE_TIME - GTM MODE RX RECYCLE TIME */
#define GENFSK_GTM_RX_RECYCLE_TIME_GTM_RX_RECYCLE_TIME(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_RX_RECYCLE_TIME_GTM_RX_RECYCLE_TIME_SHIFT)) & GENFSK_GTM_RX_RECYCLE_TIME_GTM_RX_RECYCLE_TIME_MASK)
/*! @} */

/*! @name MACLONGADDRS0_MSB - MAC LONG ADDRESS 0 MSB */
/*! @{ */

#define GENFSK_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_MASK (0xFFFFFFFFU)
#define GENFSK_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_SHIFT (0U)
/*! MACLONGADDRS0_MSB - MAC LONG ADDRESS for PAN0 MSB */
#define GENFSK_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_SHIFT)) & GENFSK_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_MASK)
/*! @} */

/*! @name WL_SEARCH_ADDR_MSB - WL_SEARCH_ADDR[47:32] */
/*! @{ */

#define GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_MSB_MASK (0xFFFFU)
#define GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_MSB_SHIFT (0U)
#define GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_MSB(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_MSB_SHIFT)) & GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_MSB_MASK)

#define GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_TYPE_MASK (0x80000000U)
#define GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_TYPE_SHIFT (31U)
/*! WL_SEARCH_ADDR_TYPE
 *  0b0..The address type is public.
 *  0b1..The address type is random.
 */
#define GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_TYPE(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_TYPE_SHIFT)) & GENFSK_WL_SEARCH_ADDR_MSB_WL_SEARCH_ADDR_TYPE_MASK)
/*! @} */

/*! @name CCA_LQI_CTRL - CCA AND LQI CONTROL */
/*! @{ */

#define GENFSK_CCA_LQI_CTRL_CCABFRTX_MASK        (0x1U)
#define GENFSK_CCA_LQI_CTRL_CCABFRTX_SHIFT       (0U)
/*! CCABFRTX - CCA Before TX
 *  0b0..no CCA required, transmit operation begins immediately.
 *  0b1..at least one CCA measurement is required prior to the transmit operation (see also SLOTTED).
 */
#define GENFSK_CCA_LQI_CTRL_CCABFRTX(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_CCA_LQI_CTRL_CCABFRTX_SHIFT)) & GENFSK_CCA_LQI_CTRL_CCABFRTX_MASK)

#define GENFSK_CCA_LQI_CTRL_SIMUL_CCA_RX_MASK    (0x2U)
#define GENFSK_CCA_LQI_CTRL_SIMUL_CCA_RX_SHIFT   (1U)
/*! SIMUL_CCA_RX - Simultaneous CCA and Receive Enable
 *  0b0..Packets can't be received during CCA measurement
 *  0b1..Packet reception is enabled during CCA measurement if preamble and SFD are detected
 */
#define GENFSK_CCA_LQI_CTRL_SIMUL_CCA_RX(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_CCA_LQI_CTRL_SIMUL_CCA_RX_SHIFT)) & GENFSK_CCA_LQI_CTRL_SIMUL_CCA_RX_MASK)

#define GENFSK_CCA_LQI_CTRL_CCA_MASK             (0x80U)
#define GENFSK_CCA_LQI_CTRL_CCA_SHIFT            (7U)
/*! CCA - CCA Status
 *  0b0..IDLE
 *  0b1..BUSY
 */
#define GENFSK_CCA_LQI_CTRL_CCA(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_CCA_LQI_CTRL_CCA_SHIFT)) & GENFSK_CCA_LQI_CTRL_CCA_MASK)

#define GENFSK_CCA_LQI_CTRL_CCA1_THRESH_MASK     (0xFF00U)
#define GENFSK_CCA_LQI_CTRL_CCA1_THRESH_SHIFT    (8U)
/*! CCA1_THRESH - CCA Mode 1 Threshold */
#define GENFSK_CCA_LQI_CTRL_CCA1_THRESH(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_CCA_LQI_CTRL_CCA1_THRESH_SHIFT)) & GENFSK_CCA_LQI_CTRL_CCA1_THRESH_MASK)

#define GENFSK_CCA_LQI_CTRL_CCA1_ED_FNL_MASK     (0xFF0000U)
#define GENFSK_CCA_LQI_CTRL_CCA1_ED_FNL_SHIFT    (16U)
/*! CCA1_ED_FNL - Final Result for CCA Mode 1 and Energy Detect */
#define GENFSK_CCA_LQI_CTRL_CCA1_ED_FNL(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_CCA_LQI_CTRL_CCA1_ED_FNL_SHIFT)) & GENFSK_CCA_LQI_CTRL_CCA1_ED_FNL_MASK)
/*! @} */

/*! @name WARMUP_TIME - TX/RX WARMUP TIME */
/*! @{ */

#define GENFSK_WARMUP_TIME_RX_WARMUP_MASK        (0xFFU)
#define GENFSK_WARMUP_TIME_RX_WARMUP_SHIFT       (0U)
/*! RX_WARMUP - Receive Warmup Time */
#define GENFSK_WARMUP_TIME_RX_WARMUP(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_WARMUP_TIME_RX_WARMUP_SHIFT)) & GENFSK_WARMUP_TIME_RX_WARMUP_MASK)

#define GENFSK_WARMUP_TIME_TX_WARMUP_MASK        (0xFF0000U)
#define GENFSK_WARMUP_TIME_TX_WARMUP_SHIFT       (16U)
/*! TX_WARMUP - Transmit Warmup Time */
#define GENFSK_WARMUP_TIME_TX_WARMUP(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_WARMUP_TIME_TX_WARMUP_SHIFT)) & GENFSK_WARMUP_TIME_TX_WARMUP_MASK)
/*! @} */

/*! @name RXEN_DLY - RX_EN Delay Time */
/*! @{ */

#define GENFSK_RXEN_DLY_RXEN_DLY_MASK            (0x3FFU)
#define GENFSK_RXEN_DLY_RXEN_DLY_SHIFT           (0U)
#define GENFSK_RXEN_DLY_RXEN_DLY(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_RXEN_DLY_RXEN_DLY_SHIFT)) & GENFSK_RXEN_DLY_RXEN_DLY_MASK)

#define GENFSK_RXEN_DLY_RXEN_DLY_OVERRIDE_MASK   (0x80000000U)
#define GENFSK_RXEN_DLY_RXEN_DLY_OVERRIDE_SHIFT  (31U)
/*! RXEN_DLY_OVERRIDE
 *  0b0..For Bluetooth LE case, RX_EN signal will delay to de-assert according to the length of TERM2 or CTE(when
 *       BLE_V5P1_CTE_EN is enabled) field parsed by hardware
 *  0b1..For all receive case, RX_EN signal will delay to de-assert according to register RXEN_DLY[9:0].
 */
#define GENFSK_RXEN_DLY_RXEN_DLY_OVERRIDE(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_RXEN_DLY_RXEN_DLY_OVERRIDE_SHIFT)) & GENFSK_RXEN_DLY_RXEN_DLY_OVERRIDE_MASK)
/*! @} */

/*! @name SAM_CTRL - SAM CONTROL */
/*! @{ */

#define GENFSK_SAM_CTRL_SAP0_EN_MASK             (0x1U)
#define GENFSK_SAM_CTRL_SAP0_EN_SHIFT            (0U)
/*! SAP0_EN - Enables SAP0 Partition of the SAM Table
 *  0b0..Disables SAP0 Partition
 *  0b1..Enables SAP0 Partition
 */
#define GENFSK_SAM_CTRL_SAP0_EN(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_CTRL_SAP0_EN_SHIFT)) & GENFSK_SAM_CTRL_SAP0_EN_MASK)

#define GENFSK_SAM_CTRL_SAA0_EN_MASK             (0x2U)
#define GENFSK_SAM_CTRL_SAA0_EN_SHIFT            (1U)
/*! SAA0_EN - Enables SAA0 Partition of the SAM Table
 *  0b0..Disables SAA0 Partition
 *  0b1..Enables SAA0 Partition
 */
#define GENFSK_SAM_CTRL_SAA0_EN(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_CTRL_SAA0_EN_SHIFT)) & GENFSK_SAM_CTRL_SAA0_EN_MASK)

#define GENFSK_SAM_CTRL_SAP1_EN_MASK             (0x4U)
#define GENFSK_SAM_CTRL_SAP1_EN_SHIFT            (2U)
/*! SAP1_EN - Enables SAP1 Partition of the SAM Table
 *  0b0..Disables SAP1 Partition
 *  0b1..Enables SAP1 Partition
 */
#define GENFSK_SAM_CTRL_SAP1_EN(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_CTRL_SAP1_EN_SHIFT)) & GENFSK_SAM_CTRL_SAP1_EN_MASK)

#define GENFSK_SAM_CTRL_SAA1_EN_MASK             (0x8U)
#define GENFSK_SAM_CTRL_SAA1_EN_SHIFT            (3U)
/*! SAA1_EN - Enables SAA1 Partition of the SAM Table
 *  0b0..Disables SAA1 Partition
 *  0b1..Enables SAA1 Partition
 */
#define GENFSK_SAM_CTRL_SAA1_EN(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_CTRL_SAA1_EN_SHIFT)) & GENFSK_SAM_CTRL_SAA1_EN_MASK)

#define GENFSK_SAM_CTRL_SAA0_START_MASK          (0xFF00U)
#define GENFSK_SAM_CTRL_SAA0_START_SHIFT         (8U)
/*! SAA0_START - First Index of SAA0 partition */
#define GENFSK_SAM_CTRL_SAA0_START(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_CTRL_SAA0_START_SHIFT)) & GENFSK_SAM_CTRL_SAA0_START_MASK)

#define GENFSK_SAM_CTRL_SAP1_START_MASK          (0xFF0000U)
#define GENFSK_SAM_CTRL_SAP1_START_SHIFT         (16U)
/*! SAP1_START - First Index of SAP1 partition */
#define GENFSK_SAM_CTRL_SAP1_START(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_CTRL_SAP1_START_SHIFT)) & GENFSK_SAM_CTRL_SAP1_START_MASK)

#define GENFSK_SAM_CTRL_SAA1_START_MASK          (0xFF000000U)
#define GENFSK_SAM_CTRL_SAA1_START_SHIFT         (24U)
/*! SAA1_START - First Index of SAA1 partition */
#define GENFSK_SAM_CTRL_SAA1_START(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_CTRL_SAA1_START_SHIFT)) & GENFSK_SAM_CTRL_SAA1_START_MASK)
/*! @} */

/*! @name SAM_TABLE - SOURCE ADDRESS MANAGEMENT TABLE */
/*! @{ */

#define GENFSK_SAM_TABLE_SAM_INDEX_MASK          (0x7FU)
#define GENFSK_SAM_TABLE_SAM_INDEX_SHIFT         (0U)
/*! SAM_INDEX - Contains the SAM table index to be enabled or invalidated */
#define GENFSK_SAM_TABLE_SAM_INDEX(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_SAM_INDEX_SHIFT)) & GENFSK_SAM_TABLE_SAM_INDEX_MASK)

#define GENFSK_SAM_TABLE_SAM_INDEX_WR_MASK       (0x80U)
#define GENFSK_SAM_TABLE_SAM_INDEX_WR_SHIFT      (7U)
/*! SAM_INDEX_WR - Enables SAM Table Contents to be updated */
#define GENFSK_SAM_TABLE_SAM_INDEX_WR(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_SAM_INDEX_WR_SHIFT)) & GENFSK_SAM_TABLE_SAM_INDEX_WR_MASK)

#define GENFSK_SAM_TABLE_SAM_CHECKSUM_MASK       (0xFFFF00U)
#define GENFSK_SAM_TABLE_SAM_CHECKSUM_SHIFT      (8U)
/*! SAM_CHECKSUM - Software-computed source address checksum, to be installed into a table index */
#define GENFSK_SAM_TABLE_SAM_CHECKSUM(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_SAM_CHECKSUM_SHIFT)) & GENFSK_SAM_TABLE_SAM_CHECKSUM_MASK)

#define GENFSK_SAM_TABLE_SAM_INDEX_INV_MASK      (0x1000000U)
#define GENFSK_SAM_TABLE_SAM_INDEX_INV_SHIFT     (24U)
/*! SAM_INDEX_INV - Invalidate the SAM table index selected by SAM_INDEX */
#define GENFSK_SAM_TABLE_SAM_INDEX_INV(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_SAM_INDEX_INV_SHIFT)) & GENFSK_SAM_TABLE_SAM_INDEX_INV_MASK)

#define GENFSK_SAM_TABLE_SAM_INDEX_EN_MASK       (0x2000000U)
#define GENFSK_SAM_TABLE_SAM_INDEX_EN_SHIFT      (25U)
/*! SAM_INDEX_EN - Enable the SAM table index selected by SAM_INDEX */
#define GENFSK_SAM_TABLE_SAM_INDEX_EN(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_SAM_INDEX_EN_SHIFT)) & GENFSK_SAM_TABLE_SAM_INDEX_EN_MASK)

#define GENFSK_SAM_TABLE_ACK_FRM_PND_MASK        (0x4000000U)
#define GENFSK_SAM_TABLE_ACK_FRM_PND_SHIFT       (26U)
/*! ACK_FRM_PND - State of AutoTxAck FramePending field when SAM Acceleration is Disabled */
#define GENFSK_SAM_TABLE_ACK_FRM_PND(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_ACK_FRM_PND_SHIFT)) & GENFSK_SAM_TABLE_ACK_FRM_PND_MASK)

#define GENFSK_SAM_TABLE_ACK_FRM_PND_CTRL_MASK   (0x8000000U)
#define GENFSK_SAM_TABLE_ACK_FRM_PND_CTRL_SHIFT  (27U)
/*! ACK_FRM_PND_CTRL - Manual Control for AutoTxAck FramePending field
 *  0b0..the FramePending field of the Frame Control Field of the next automatic TX acknowledge packet is determined by hardware
 *  0b1..the FramePending field of the Frame Control Field of the next automatic TX acknowledge packet tracks ACK_FRM_PEND
 */
#define GENFSK_SAM_TABLE_ACK_FRM_PND_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_ACK_FRM_PND_CTRL_SHIFT)) & GENFSK_SAM_TABLE_ACK_FRM_PND_CTRL_MASK)

#define GENFSK_SAM_TABLE_FIND_FREE_IDX_MASK      (0x10000000U)
#define GENFSK_SAM_TABLE_FIND_FREE_IDX_SHIFT     (28U)
/*! FIND_FREE_IDX - Find First Free Index */
#define GENFSK_SAM_TABLE_FIND_FREE_IDX(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_FIND_FREE_IDX_SHIFT)) & GENFSK_SAM_TABLE_FIND_FREE_IDX_MASK)

#define GENFSK_SAM_TABLE_INVALIDATE_ALL_MASK     (0x20000000U)
#define GENFSK_SAM_TABLE_INVALIDATE_ALL_SHIFT    (29U)
/*! INVALIDATE_ALL - Invalidate Entire SAM Table */
#define GENFSK_SAM_TABLE_INVALIDATE_ALL(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_INVALIDATE_ALL_SHIFT)) & GENFSK_SAM_TABLE_INVALIDATE_ALL_MASK)

#define GENFSK_SAM_TABLE_SRCADDR_MASK            (0x40000000U)
#define GENFSK_SAM_TABLE_SRCADDR_SHIFT           (30U)
/*! SRCADDR - Source Address Match Status */
#define GENFSK_SAM_TABLE_SRCADDR(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_SRCADDR_SHIFT)) & GENFSK_SAM_TABLE_SRCADDR_MASK)

#define GENFSK_SAM_TABLE_SAM_BUSY_MASK           (0x80000000U)
#define GENFSK_SAM_TABLE_SAM_BUSY_SHIFT          (31U)
/*! SAM_BUSY - SAM Table Update Status Bit */
#define GENFSK_SAM_TABLE_SAM_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_TABLE_SAM_BUSY_SHIFT)) & GENFSK_SAM_TABLE_SAM_BUSY_MASK)
/*! @} */

/*! @name SAM_MATCH - SOURCE ADDRESS MANAGEMENT MATCH */
/*! @{ */

#define GENFSK_SAM_MATCH_SAP0_MATCH_MASK         (0x7FU)
#define GENFSK_SAM_MATCH_SAP0_MATCH_SHIFT        (0U)
/*! SAP0_MATCH - Index in the SAP0 Partition of the SAM Table corresponding to the first checksum match */
#define GENFSK_SAM_MATCH_SAP0_MATCH(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAP0_MATCH_SHIFT)) & GENFSK_SAM_MATCH_SAP0_MATCH_MASK)

#define GENFSK_SAM_MATCH_SAP0_ADDR_PRESENT_MASK  (0x80U)
#define GENFSK_SAM_MATCH_SAP0_ADDR_PRESENT_SHIFT (7U)
/*! SAP0_ADDR_PRESENT - A Checksum Match is Present in the SAP0 Partition of the SAM Table */
#define GENFSK_SAM_MATCH_SAP0_ADDR_PRESENT(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAP0_ADDR_PRESENT_SHIFT)) & GENFSK_SAM_MATCH_SAP0_ADDR_PRESENT_MASK)

#define GENFSK_SAM_MATCH_SAA0_MATCH_MASK         (0x7F00U)
#define GENFSK_SAM_MATCH_SAA0_MATCH_SHIFT        (8U)
/*! SAA0_MATCH - Index in the SAA0 Partition of the SAM Table corresponding to the first checksum match */
#define GENFSK_SAM_MATCH_SAA0_MATCH(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAA0_MATCH_SHIFT)) & GENFSK_SAM_MATCH_SAA0_MATCH_MASK)

#define GENFSK_SAM_MATCH_SAA0_ADDR_ABSENT_MASK   (0x8000U)
#define GENFSK_SAM_MATCH_SAA0_ADDR_ABSENT_SHIFT  (15U)
/*! SAA0_ADDR_ABSENT - A Checksum Match is Absent in the SAA0 Partition of the SAM Table */
#define GENFSK_SAM_MATCH_SAA0_ADDR_ABSENT(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAA0_ADDR_ABSENT_SHIFT)) & GENFSK_SAM_MATCH_SAA0_ADDR_ABSENT_MASK)

#define GENFSK_SAM_MATCH_SAP1_MATCH_MASK         (0x7F0000U)
#define GENFSK_SAM_MATCH_SAP1_MATCH_SHIFT        (16U)
/*! SAP1_MATCH - Index in the SAP1 Partition of the SAM Table corresponding to the first checksum match */
#define GENFSK_SAM_MATCH_SAP1_MATCH(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAP1_MATCH_SHIFT)) & GENFSK_SAM_MATCH_SAP1_MATCH_MASK)

#define GENFSK_SAM_MATCH_SAP1_ADDR_PRESENT_MASK  (0x800000U)
#define GENFSK_SAM_MATCH_SAP1_ADDR_PRESENT_SHIFT (23U)
/*! SAP1_ADDR_PRESENT - A Checksum Match is Present in the SAP1 Partition of the SAM Table */
#define GENFSK_SAM_MATCH_SAP1_ADDR_PRESENT(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAP1_ADDR_PRESENT_SHIFT)) & GENFSK_SAM_MATCH_SAP1_ADDR_PRESENT_MASK)

#define GENFSK_SAM_MATCH_SAA1_MATCH_MASK         (0x7F000000U)
#define GENFSK_SAM_MATCH_SAA1_MATCH_SHIFT        (24U)
/*! SAA1_MATCH - Index in the SAA1 Partition of the SAM Table corresponding to the first checksum match */
#define GENFSK_SAM_MATCH_SAA1_MATCH(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAA1_MATCH_SHIFT)) & GENFSK_SAM_MATCH_SAA1_MATCH_MASK)

#define GENFSK_SAM_MATCH_SAA1_ADDR_ABSENT_MASK   (0x80000000U)
#define GENFSK_SAM_MATCH_SAA1_ADDR_ABSENT_SHIFT  (31U)
/*! SAA1_ADDR_ABSENT - A Checksum Match is Absent in the SAP1 Partition of the SAM Table */
#define GENFSK_SAM_MATCH_SAA1_ADDR_ABSENT(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_MATCH_SAA1_ADDR_ABSENT_SHIFT)) & GENFSK_SAM_MATCH_SAA1_ADDR_ABSENT_MASK)
/*! @} */

/*! @name SAM_FREE_IDX - SAM FREE INDEX */
/*! @{ */

#define GENFSK_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_MASK (0xFFU)
#define GENFSK_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_SHIFT (0U)
/*! SAP0_1ST_FREE_IDX - First non-enabled (invalid) index in the SAP0 partition */
#define GENFSK_SAM_FREE_IDX_SAP0_1ST_FREE_IDX(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_SHIFT)) & GENFSK_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_MASK)

#define GENFSK_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_MASK (0xFF00U)
#define GENFSK_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_SHIFT (8U)
/*! SAA0_1ST_FREE_IDX - First non-enabled (invalid) index in the SAA0 partition */
#define GENFSK_SAM_FREE_IDX_SAA0_1ST_FREE_IDX(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_SHIFT)) & GENFSK_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_MASK)

#define GENFSK_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_MASK (0xFF0000U)
#define GENFSK_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_SHIFT (16U)
/*! SAP1_1ST_FREE_IDX - First non-enabled (invalid) index in the SAP1 partition */
#define GENFSK_SAM_FREE_IDX_SAP1_1ST_FREE_IDX(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_SHIFT)) & GENFSK_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_MASK)

#define GENFSK_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_MASK (0xFF000000U)
#define GENFSK_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_SHIFT (24U)
/*! SAA1_1ST_FREE_IDX - First non-enabled (invalid) index in the SAA1 partition */
#define GENFSK_SAM_FREE_IDX_SAA1_1ST_FREE_IDX(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_SHIFT)) & GENFSK_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_MASK)
/*! @} */

/*! @name MISC1 - MISCELLANEOUS(1) */
/*! @{ */

#define GENFSK_MISC1_SRC_ADDR_CHECKSUM_MASK      (0xFFFFU)
#define GENFSK_MISC1_SRC_ADDR_CHECKSUM_SHIFT     (0U)
/*! SRC_ADDR_CHECKSUM - Hardware-computed received source address checksum */
#define GENFSK_MISC1_SRC_ADDR_CHECKSUM(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_SRC_ADDR_CHECKSUM_SHIFT)) & GENFSK_MISC1_SRC_ADDR_CHECKSUM_MASK)

#define GENFSK_MISC1_SW_ABORTED_MASK             (0x10000U)
#define GENFSK_MISC1_SW_ABORTED_SHIFT            (16U)
/*! SW_ABORTED - Autosequence has terminated due to a Software abort. */
#define GENFSK_MISC1_SW_ABORTED(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_SW_ABORTED_SHIFT)) & GENFSK_MISC1_SW_ABORTED_MASK)

#define GENFSK_MISC1_PLL_ABORTED_MASK            (0x20000U)
#define GENFSK_MISC1_PLL_ABORTED_SHIFT           (17U)
/*! PLL_ABORTED - Autosequence has terminated due to an PLL unlock event. */
#define GENFSK_MISC1_PLL_ABORTED(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_PLL_ABORTED_SHIFT)) & GENFSK_MISC1_PLL_ABORTED_MASK)

#define GENFSK_MISC1_EXT_ABORTED_MASK            (0x40000U)
#define GENFSK_MISC1_EXT_ABORTED_SHIFT           (18U)
/*! EXT_ABORTED - Autosequence has terminated due to a Wake-On-Radio command */
#define GENFSK_MISC1_EXT_ABORTED(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_EXT_ABORTED_SHIFT)) & GENFSK_MISC1_EXT_ABORTED_MASK)

#define GENFSK_MISC1_ARB_GRANT_DEASSERTION_ABORTED_MASK (0x80000U)
#define GENFSK_MISC1_ARB_GRANT_DEASSERTION_ABORTED_SHIFT (19U)
/*! ARB_GRANT_DEASSERTION_ABORTED - Autosequence has terminated due to an arb_grant de-assertion event */
#define GENFSK_MISC1_ARB_GRANT_DEASSERTION_ABORTED(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_ARB_GRANT_DEASSERTION_ABORTED_SHIFT)) & GENFSK_MISC1_ARB_GRANT_DEASSERTION_ABORTED_MASK)

#define GENFSK_MISC1_FAST_TX_WU_OVRD_MASK        (0x10000000U)
#define GENFSK_MISC1_FAST_TX_WU_OVRD_SHIFT       (28U)
/*! FAST_TX_WU_OVRD - FAST_TX_WU override
 *  0b0..If TSM enables Fast Warmup Capability, LL will request it when TX in RT or (CCA+TX)
 *  0b1..If TSM enables Fast Warmup Capability, LL will request it at every TX. User should insure channel is not changed since last sequence.
 */
#define GENFSK_MISC1_FAST_TX_WU_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_FAST_TX_WU_OVRD_SHIFT)) & GENFSK_MISC1_FAST_TX_WU_OVRD_MASK)

#define GENFSK_MISC1_FAST_RX_WU_OVRD_MASK        (0x20000000U)
#define GENFSK_MISC1_FAST_RX_WU_OVRD_SHIFT       (29U)
/*! FAST_RX_WU_OVRD - FAST_RX_WU override
 *  0b0..If TSM enables Fast Warmup Capability, LL will request it when RX in TR
 *  0b1..If TSM enables Fast Warmup Capability, LL will request it at every RX. User should insure channel is not changed since last sequence.
 */
#define GENFSK_MISC1_FAST_RX_WU_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_FAST_RX_WU_OVRD_SHIFT)) & GENFSK_MISC1_FAST_RX_WU_OVRD_MASK)

#define GENFSK_MISC1_PI_MASK                     (0x40000000U)
#define GENFSK_MISC1_PI_SHIFT                    (30U)
/*! PI - Poll Indication
 *  0b0..the received packet was not a data request
 *  0b1..the received packet was a data request, regardless of whether a Source Address table match occurred, or
 *       whether Source Address Management is enabled or not
 */
#define GENFSK_MISC1_PI(x)                       (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_PI_SHIFT)) & GENFSK_MISC1_PI_MASK)

#define GENFSK_MISC1_RX_FRM_PEND_MASK            (0x80000000U)
#define GENFSK_MISC1_RX_FRM_PEND_SHIFT           (31U)
/*! RX_FRM_PEND - RX Frame Pending */
#define GENFSK_MISC1_RX_FRM_PEND(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_MISC1_RX_FRM_PEND_SHIFT)) & GENFSK_MISC1_RX_FRM_PEND_MASK)
/*! @} */

/*! @name SEQ_STS - SEQUENCE STATUS */
/*! @{ */

#define GENFSK_SEQ_STS_TX_START_T1_PEND_MASK     (0x1U)
#define GENFSK_SEQ_STS_TX_START_T1_PEND_SHIFT    (0U)
/*! TX_START_T1_PEND - TX T1 Start Pending Status */
#define GENFSK_SEQ_STS_TX_START_T1_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_TX_START_T1_PEND_SHIFT)) & GENFSK_SEQ_STS_TX_START_T1_PEND_MASK)

#define GENFSK_SEQ_STS_TX_START_T2_PEND_MASK     (0x2U)
#define GENFSK_SEQ_STS_TX_START_T2_PEND_SHIFT    (1U)
/*! TX_START_T2_PEND - TX T2 Start Pending Status */
#define GENFSK_SEQ_STS_TX_START_T2_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_TX_START_T2_PEND_SHIFT)) & GENFSK_SEQ_STS_TX_START_T2_PEND_MASK)

#define GENFSK_SEQ_STS_TX_IN_WARMUP_MASK         (0x4U)
#define GENFSK_SEQ_STS_TX_IN_WARMUP_SHIFT        (2U)
/*! TX_IN_WARMUP - TX Warmup Status */
#define GENFSK_SEQ_STS_TX_IN_WARMUP(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_TX_IN_WARMUP_SHIFT)) & GENFSK_SEQ_STS_TX_IN_WARMUP_MASK)

#define GENFSK_SEQ_STS_TX_IN_PROGRESS_MASK       (0x8U)
#define GENFSK_SEQ_STS_TX_IN_PROGRESS_SHIFT      (3U)
/*! TX_IN_PROGRESS - TX in Progress Status */
#define GENFSK_SEQ_STS_TX_IN_PROGRESS(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_TX_IN_PROGRESS_SHIFT)) & GENFSK_SEQ_STS_TX_IN_PROGRESS_MASK)

#define GENFSK_SEQ_STS_TX_IN_WARMDN_MASK         (0x10U)
#define GENFSK_SEQ_STS_TX_IN_WARMDN_SHIFT        (4U)
/*! TX_IN_WARMDN - TX Warm-down Status */
#define GENFSK_SEQ_STS_TX_IN_WARMDN(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_TX_IN_WARMDN_SHIFT)) & GENFSK_SEQ_STS_TX_IN_WARMDN_MASK)

#define GENFSK_SEQ_STS_RX_START_T1_PEND_MASK     (0x20U)
#define GENFSK_SEQ_STS_RX_START_T1_PEND_SHIFT    (5U)
/*! RX_START_T1_PEND - RX T1 Start Pending Status */
#define GENFSK_SEQ_STS_RX_START_T1_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_START_T1_PEND_SHIFT)) & GENFSK_SEQ_STS_RX_START_T1_PEND_MASK)

#define GENFSK_SEQ_STS_RX_START_T2_PEND_MASK     (0x40U)
#define GENFSK_SEQ_STS_RX_START_T2_PEND_SHIFT    (6U)
/*! RX_START_T2_PEND - RX T2 Start Pending Status */
#define GENFSK_SEQ_STS_RX_START_T2_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_START_T2_PEND_SHIFT)) & GENFSK_SEQ_STS_RX_START_T2_PEND_MASK)

#define GENFSK_SEQ_STS_RX_STOP_T1_PEND_MASK      (0x80U)
#define GENFSK_SEQ_STS_RX_STOP_T1_PEND_SHIFT     (7U)
/*! RX_STOP_T1_PEND - RX T1 Stop Pending Status */
#define GENFSK_SEQ_STS_RX_STOP_T1_PEND(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_STOP_T1_PEND_SHIFT)) & GENFSK_SEQ_STS_RX_STOP_T1_PEND_MASK)

#define GENFSK_SEQ_STS_RX_STOP_T2_PEND_MASK      (0x100U)
#define GENFSK_SEQ_STS_RX_STOP_T2_PEND_SHIFT     (8U)
/*! RX_STOP_T2_PEND - RX T2 Start Pending Status */
#define GENFSK_SEQ_STS_RX_STOP_T2_PEND(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_STOP_T2_PEND_SHIFT)) & GENFSK_SEQ_STS_RX_STOP_T2_PEND_MASK)

#define GENFSK_SEQ_STS_RX_IN_WARMUP_MASK         (0x200U)
#define GENFSK_SEQ_STS_RX_IN_WARMUP_SHIFT        (9U)
/*! RX_IN_WARMUP - RX Warmup Status */
#define GENFSK_SEQ_STS_RX_IN_WARMUP(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_IN_WARMUP_SHIFT)) & GENFSK_SEQ_STS_RX_IN_WARMUP_MASK)

#define GENFSK_SEQ_STS_RX_IN_SEARCH_MASK         (0x400U)
#define GENFSK_SEQ_STS_RX_IN_SEARCH_SHIFT        (10U)
/*! RX_IN_SEARCH - RX Search Status */
#define GENFSK_SEQ_STS_RX_IN_SEARCH(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_IN_SEARCH_SHIFT)) & GENFSK_SEQ_STS_RX_IN_SEARCH_MASK)

#define GENFSK_SEQ_STS_RX_IN_PROGRESS_MASK       (0x800U)
#define GENFSK_SEQ_STS_RX_IN_PROGRESS_SHIFT      (11U)
/*! RX_IN_PROGRESS - RX in Progress Status */
#define GENFSK_SEQ_STS_RX_IN_PROGRESS(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_IN_PROGRESS_SHIFT)) & GENFSK_SEQ_STS_RX_IN_PROGRESS_MASK)

#define GENFSK_SEQ_STS_RX_IN_WARMDN_MASK         (0x1000U)
#define GENFSK_SEQ_STS_RX_IN_WARMDN_SHIFT        (12U)
/*! RX_IN_WARMDN - RX Warm-down Status */
#define GENFSK_SEQ_STS_RX_IN_WARMDN(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_RX_IN_WARMDN_SHIFT)) & GENFSK_SEQ_STS_RX_IN_WARMDN_MASK)

#define GENFSK_SEQ_STS_TR_START_T1_PEND_MASK     (0x2000U)
#define GENFSK_SEQ_STS_TR_START_T1_PEND_SHIFT    (13U)
/*! TR_START_T1_PEND - TR T1 Start Pending Status */
#define GENFSK_SEQ_STS_TR_START_T1_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_TR_START_T1_PEND_SHIFT)) & GENFSK_SEQ_STS_TR_START_T1_PEND_MASK)

#define GENFSK_SEQ_STS_TR_START_T2_PEND_MASK     (0x4000U)
#define GENFSK_SEQ_STS_TR_START_T2_PEND_SHIFT    (14U)
/*! TR_START_T2_PEND - TR T2 Start Pending Status */
#define GENFSK_SEQ_STS_TR_START_T2_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_TR_START_T2_PEND_SHIFT)) & GENFSK_SEQ_STS_TR_START_T2_PEND_MASK)

#define GENFSK_SEQ_STS_CCA_START_T1_PEND_MASK    (0x8000U)
#define GENFSK_SEQ_STS_CCA_START_T1_PEND_SHIFT   (15U)
/*! CCA_START_T1_PEND - CCA T1 Start Pending Status */
#define GENFSK_SEQ_STS_CCA_START_T1_PEND(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_CCA_START_T1_PEND_SHIFT)) & GENFSK_SEQ_STS_CCA_START_T1_PEND_MASK)

#define GENFSK_SEQ_STS_CCA_START_T2_PEND_MASK    (0x10000U)
#define GENFSK_SEQ_STS_CCA_START_T2_PEND_SHIFT   (16U)
/*! CCA_START_T2_PEND - CCA T2 Start Pending Status */
#define GENFSK_SEQ_STS_CCA_START_T2_PEND(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_CCA_START_T2_PEND_SHIFT)) & GENFSK_SEQ_STS_CCA_START_T2_PEND_MASK)

#define GENFSK_SEQ_STS_SEQ_T_STATUS_MASK         (0x1F000000U)
#define GENFSK_SEQ_STS_SEQ_T_STATUS_SHIFT        (24U)
/*! SEQ_T_STATUS - Status of the just-completed or ongoing Sequence T or Sequence TR */
#define GENFSK_SEQ_STS_SEQ_T_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_SEQ_STS_SEQ_T_STATUS_SHIFT)) & GENFSK_SEQ_STS_SEQ_T_STATUS_MASK)
/*! @} */

/*! @name PHR_MISC - PHR MISCELLANEOUS */
/*! @{ */

#define GENFSK_PHR_MISC_SUNFSK_MS_MASK           (0x1U)
#define GENFSK_PHR_MISC_SUNFSK_MS_SHIFT          (0U)
/*! SUNFSK_MS - Mode Switch Bit */
#define GENFSK_PHR_MISC_SUNFSK_MS(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_PHR_MISC_SUNFSK_MS_SHIFT)) & GENFSK_PHR_MISC_SUNFSK_MS_MASK)

#define GENFSK_PHR_MISC_SUNFSK_MSP_MASK          (0x6U)
#define GENFSK_PHR_MISC_SUNFSK_MSP_SHIFT         (1U)
/*! SUNFSK_MSP - Mode Switch Parameter Bit */
#define GENFSK_PHR_MISC_SUNFSK_MSP(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_PHR_MISC_SUNFSK_MSP_SHIFT)) & GENFSK_PHR_MISC_SUNFSK_MSP_MASK)

#define GENFSK_PHR_MISC_SUNFSK_FEC_MASK          (0x8U)
#define GENFSK_PHR_MISC_SUNFSK_FEC_SHIFT         (3U)
/*! SUNFSK_FEC - New Mode FEC Bit */
#define GENFSK_PHR_MISC_SUNFSK_FEC(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_PHR_MISC_SUNFSK_FEC_SHIFT)) & GENFSK_PHR_MISC_SUNFSK_FEC_MASK)

#define GENFSK_PHR_MISC_SUNFSK_NM_MASK           (0x7F0U)
#define GENFSK_PHR_MISC_SUNFSK_NM_SHIFT          (4U)
/*! SUNFSK_NM - New Mode Bit */
#define GENFSK_PHR_MISC_SUNFSK_NM(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_PHR_MISC_SUNFSK_NM_SHIFT)) & GENFSK_PHR_MISC_SUNFSK_NM_MASK)

#define GENFSK_PHR_MISC_PHR_FAIL_IGNORE_MASK     (0x1000000U)
#define GENFSK_PHR_MISC_PHR_FAIL_IGNORE_SHIFT    (24U)
/*! PHR_FAIL_IGNORE - Ignore PHR Fail */
#define GENFSK_PHR_MISC_PHR_FAIL_IGNORE(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_PHR_MISC_PHR_FAIL_IGNORE_SHIFT)) & GENFSK_PHR_MISC_PHR_FAIL_IGNORE_MASK)
/*! @} */

/*! @name GTM_CTRL - GTM CONTROL */
/*! @{ */

#define GENFSK_GTM_CTRL_GTM_IN_RX_MASK           (0x1U)
#define GENFSK_GTM_CTRL_GTM_IN_RX_SHIFT          (0U)
/*! GTM_IN_RX - Enable GTM Receive Mode
 *  0b0..GTM receive mode is not enabled.
 *  0b1..GTM receive mode is enabled.
 */
#define GENFSK_GTM_CTRL_GTM_IN_RX(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_CTRL_GTM_IN_RX_SHIFT)) & GENFSK_GTM_CTRL_GTM_IN_RX_MASK)

#define GENFSK_GTM_CTRL_GTM_IN_TX_MASK           (0x2U)
#define GENFSK_GTM_CTRL_GTM_IN_TX_SHIFT          (1U)
/*! GTM_IN_TX - Enable GTM Transmit Mode
 *  0b0..GTM transmit mode is not enabled.
 *  0b1..GTM transmit mode is enabled.
 */
#define GENFSK_GTM_CTRL_GTM_IN_TX(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_CTRL_GTM_IN_TX_SHIFT)) & GENFSK_GTM_CTRL_GTM_IN_TX_MASK)
/*! @} */

/*! @name GTM_BAD_CNT - GTM BAD PACKET COUNTER */
/*! @{ */

#define GENFSK_GTM_BAD_CNT_GTM_BAD_PKT_COUNT_MASK (0x1FFFU)
#define GENFSK_GTM_BAD_CNT_GTM_BAD_PKT_COUNT_SHIFT (0U)
/*! GTM_BAD_PKT_COUNT - GTM Bad Packet Counter */
#define GENFSK_GTM_BAD_CNT_GTM_BAD_PKT_COUNT(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_BAD_CNT_GTM_BAD_PKT_COUNT_SHIFT)) & GENFSK_GTM_BAD_CNT_GTM_BAD_PKT_COUNT_MASK)
/*! @} */

/*! @name GTM_GOOD_CNT - GTM GOOD PACKET COUNTER */
/*! @{ */

#define GENFSK_GTM_GOOD_CNT_GTM_GOOD_PKT_COUNT_MASK (0x1FFFU)
#define GENFSK_GTM_GOOD_CNT_GTM_GOOD_PKT_COUNT_SHIFT (0U)
/*! GTM_GOOD_PKT_COUNT - GTM Good Packet Counter */
#define GENFSK_GTM_GOOD_CNT_GTM_GOOD_PKT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_GOOD_CNT_GTM_GOOD_PKT_COUNT_SHIFT)) & GENFSK_GTM_GOOD_CNT_GTM_GOOD_PKT_COUNT_MASK)
/*! @} */

/*! @name GTM_PKT_CNT - GTM PACKET COUNTER */
/*! @{ */

#define GENFSK_GTM_PKT_CNT_GTM_PKT_COUNT_MASK    (0x1FFFU)
#define GENFSK_GTM_PKT_CNT_GTM_PKT_COUNT_SHIFT   (0U)
/*! GTM_PKT_COUNT - GTM Packet Counter */
#define GENFSK_GTM_PKT_CNT_GTM_PKT_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_GTM_PKT_CNT_GTM_PKT_COUNT_SHIFT)) & GENFSK_GTM_PKT_CNT_GTM_PKT_COUNT_MASK)
/*! @} */

/*! @name COEX_CTRL - COEXISTENCE CONTROL */
/*! @{ */

#define GENFSK_COEX_CTRL_COEX_EN_MASK            (0x1U)
#define GENFSK_COEX_CTRL_COEX_EN_SHIFT           (0U)
/*! COEX_EN - Coexistence Enable
 *  0b0..Coexistence function is disabled.
 *  0b1..Coexistence function is enabled.
 */
#define GENFSK_COEX_CTRL_COEX_EN(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_CTRL_COEX_EN_SHIFT)) & GENFSK_COEX_CTRL_COEX_EN_MASK)

#define GENFSK_COEX_CTRL_COEX_REQ_DELAY_EN_MASK  (0x2U)
#define GENFSK_COEX_CTRL_COEX_REQ_DELAY_EN_SHIFT (1U)
/*! COEX_REQ_DELAY_EN - Coexistence Request Delay Enable
 *  0b0..arb_request is not delayed during R sequence.
 *  0b1..arb_request is delayed until preamble or Access Address is detected during R sequence.
 */
#define GENFSK_COEX_CTRL_COEX_REQ_DELAY_EN(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_CTRL_COEX_REQ_DELAY_EN_SHIFT)) & GENFSK_COEX_CTRL_COEX_REQ_DELAY_EN_MASK)

#define GENFSK_COEX_CTRL_COEX_REQ_ON_PD_MASK     (0x4U)
#define GENFSK_COEX_CTRL_COEX_REQ_ON_PD_SHIFT    (2U)
/*! COEX_REQ_ON_PD - Coexistence Request on Preamble detected
 *  0b0..arb_request is delayed until Access Address is detected during R sequence.
 *  0b1..arb_request is delayed until preamble is detected during R sequence.
 */
#define GENFSK_COEX_CTRL_COEX_REQ_ON_PD(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_CTRL_COEX_REQ_ON_PD_SHIFT)) & GENFSK_COEX_CTRL_COEX_REQ_ON_PD_MASK)

#define GENFSK_COEX_CTRL_COEX_TIMEOUT_MASK       (0xFF00U)
#define GENFSK_COEX_CTRL_COEX_TIMEOUT_SHIFT      (8U)
/*! COEX_TIMEOUT - Coexistence timeout value */
#define GENFSK_COEX_CTRL_COEX_TIMEOUT(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_CTRL_COEX_TIMEOUT_SHIFT)) & GENFSK_COEX_CTRL_COEX_TIMEOUT_MASK)
/*! @} */

/*! @name COEX_PRIORITY - COEXISTENCE PRIORITY */
/*! @{ */

#define GENFSK_COEX_PRIORITY_PRIORITY_T_MASK     (0x3U)
#define GENFSK_COEX_PRIORITY_PRIORITY_T_SHIFT    (0U)
/*! PRIORITY_T - PRIORITY_T */
#define GENFSK_COEX_PRIORITY_PRIORITY_T(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_T_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_T_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_R_PRE_MASK (0xCU)
#define GENFSK_COEX_PRIORITY_PRIORITY_R_PRE_SHIFT (2U)
/*! PRIORITY_R_PRE - PRIORITY_R_PRE */
#define GENFSK_COEX_PRIORITY_PRIORITY_R_PRE(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_R_PRE_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_R_PRE_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_R_PKT_MASK (0x30U)
#define GENFSK_COEX_PRIORITY_PRIORITY_R_PKT_SHIFT (4U)
/*! PRIORITY_R_PKT - PRIORITY_R_PKT */
#define GENFSK_COEX_PRIORITY_PRIORITY_R_PKT(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_R_PKT_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_R_PKT_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_TACK_MASK  (0xC0U)
#define GENFSK_COEX_PRIORITY_PRIORITY_TACK_SHIFT (6U)
/*! PRIORITY_TACK - PRIORITY_TACK */
#define GENFSK_COEX_PRIORITY_PRIORITY_TACK(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_TACK_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_TACK_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_CCA_MASK   (0x300U)
#define GENFSK_COEX_PRIORITY_PRIORITY_CCA_SHIFT  (8U)
/*! PRIORITY_CCA - PRIORITY_CCA */
#define GENFSK_COEX_PRIORITY_PRIORITY_CCA(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_CCA_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_CCA_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_CTX_MASK   (0x3000U)
#define GENFSK_COEX_PRIORITY_PRIORITY_CTX_SHIFT  (12U)
/*! PRIORITY_CTX - PRIORITY_CT */
#define GENFSK_COEX_PRIORITY_PRIORITY_CTX(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_CTX_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_CTX_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_RACK_PRE_MASK (0xC000U)
#define GENFSK_COEX_PRIORITY_PRIORITY_RACK_PRE_SHIFT (14U)
/*! PRIORITY_RACK_PRE - PRIORITY_RACK_PRE */
#define GENFSK_COEX_PRIORITY_PRIORITY_RACK_PRE(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_RACK_PRE_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_RACK_PRE_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_RACK_PKT_MASK (0x30000U)
#define GENFSK_COEX_PRIORITY_PRIORITY_RACK_PKT_SHIFT (16U)
/*! PRIORITY_RACK_PKT - PRIORITY_RACK_PKT */
#define GENFSK_COEX_PRIORITY_PRIORITY_RACK_PKT(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_RACK_PKT_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_RACK_PKT_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_OVRD_MASK  (0x60000000U)
#define GENFSK_COEX_PRIORITY_PRIORITY_OVRD_SHIFT (29U)
/*! PRIORITY_OVRD - PRIORITY_OVRD */
#define GENFSK_COEX_PRIORITY_PRIORITY_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_OVRD_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_OVRD_MASK)

#define GENFSK_COEX_PRIORITY_PRIORITY_OVRD_EN_MASK (0x80000000U)
#define GENFSK_COEX_PRIORITY_PRIORITY_OVRD_EN_SHIFT (31U)
/*! PRIORITY_OVRD_EN - PRIORITY_OVRD_EN
 *  0b0..Disable overriding PRIORITY value.
 *  0b1..Enable overriding PRIORITY value.
 */
#define GENFSK_COEX_PRIORITY_PRIORITY_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_COEX_PRIORITY_PRIORITY_OVRD_EN_SHIFT)) & GENFSK_COEX_PRIORITY_PRIORITY_OVRD_EN_MASK)
/*! @} */

/*! @name IRQ_CTRL2 - IRQ CONTROL 2 */
/*! @{ */

#define GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_MASK (0x1U)
#define GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_SHIFT (0U)
/*! ARB_GRANT_DEASSERTION_IRQ - arb_grant Deassertion IRQ
 *  0b0..An arb_grant Deassertion Interrupt has not occurred
 *  0b1..An arb_grant Deassertion Interrupt has occurred
 */
#define GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_SHIFT)) & GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_MASK)

#define GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_MASK   (0x2U)
#define GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_SHIFT  (1U)
/*! COEX_TIMEOUT_IRQ - Coexistence Timeout Interrupt */
#define GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_SHIFT)) & GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_MASK)

#define GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_MASK (0x4U)
#define GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_SHIFT (2U)
/*! EVENT_TIMER_OVER_FLOW_IRQ - Event Timer Overflow Interrupt */
#define GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_SHIFT)) & GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_MASK)

#define GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_MASK        (0x8U)
#define GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_SHIFT       (3U)
/*! WL_FAIL_IRQ - White List Check Fail Interrupt */
#define GENFSK_IRQ_CTRL2_WL_FAIL_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_SHIFT)) & GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_MASK)

#define GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_MASK (0x10U)
#define GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_SHIFT (4U)
/*! DIRECT_ID_FAIL_IRQ - Direct Case Check Fail Interrupt */
#define GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_SHIFT)) & GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_MASK)

#define GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_MASK  (0x20U)
#define GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_SHIFT (5U)
/*! PEER_RPA_FAIL_IRQ - Peer RPA Check Fail Interrupt */
#define GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_SHIFT)) & GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_MASK)

#define GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_MASK (0x40U)
#define GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_SHIFT (6U)
/*! LOCAL_RPA_FAIL_IRQ - Local RPA Check Fail Interrupt */
#define GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_SHIFT)) & GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_MASK)

#define GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_EN_MASK (0x10000U)
#define GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_EN_SHIFT (16U)
/*! ARB_GRANT_DEASSERTION_IRQ_EN - arb_grant Deassertion Interrupt enable
 *  0b0..An arb_grant deassertion event will set the ARB_GRANT_DEASSERTION_IRQ status bit, but no interrupt is not generated
 *  0b1..allows arb_grant deassertion event to generate an interrupt
 */
#define GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL2_ARB_GRANT_DEASSERTION_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_EN_MASK (0x20000U)
#define GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_EN_SHIFT (17U)
/*! COEX_TIMEOUT_IRQ_EN - Coexistence Timeout Interrupt enable bit
 *  0b0..Interrupt generation is disabled, but a COEX_TIMEOUT_IRQ flag can be set
 *  0b1..allows interrupt when coexistence timeout
 */
#define GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_EN(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL2_COEX_TIMEOUT_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_EN_MASK (0x40000U)
#define GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_EN_SHIFT (18U)
/*! EVENT_TIMER_OVER_FLOW_IRQ_EN - Event Timer Overflow Interrupt enable bit
 *  0b0..Interrupt generation is disabled, but an EVENT_TIMER_OVER_FLOW_IRQ flag can be set
 *  0b1..allows interrupt when Event Timer overflow
 */
#define GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL2_EVENT_TIMER_OVER_FLOW_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_EN_MASK     (0x80000U)
#define GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_EN_SHIFT    (19U)
/*! WL_FAIL_IRQ_EN
 *  0b0..WL_FAIL Interrupt is not enabled.
 *  0b1..WL_FAIL Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL2_WL_FAIL_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_EN_MASK (0x100000U)
#define GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_EN_SHIFT (20U)
/*! DIRECT_ID_FAIL_IRQ_EN
 *  0b0..DIRECT_ID_FAIL Interrupt is not enabled.
 *  0b1..DIRECT_ID_FAIL Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL2_DIRECT_ID_FAIL_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_EN_MASK (0x200000U)
#define GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_EN_SHIFT (21U)
/*! PEER_RPA_FAIL_IRQ_EN
 *  0b0..PEER_RPA_FAIL Interrupt is not enabled.
 *  0b1..PEER_RPA_FAIL Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL2_PEER_RPA_FAIL_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_EN_MASK (0x400000U)
#define GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_EN_SHIFT (22U)
/*! LOCAL_RPA_FAIL_IRQ_EN
 *  0b0..LOCAL_RPA_FAIL Interrupt is not enabled.
 *  0b1..LOCAL_RPA_FAIL Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL2_LOCAL_RPA_FAIL_IRQ_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GENFSK_Register_Masks */


/*!
 * @}
 */ /* end of group GENFSK_Peripheral_Access_Layer */


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


#endif  /* PERI_GENFSK_H_ */

