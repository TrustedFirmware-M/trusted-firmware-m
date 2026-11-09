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
**         CMSIS Peripheral Access Layer for ZLL
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
 * @file PERI_ZLL.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for ZLL
 *
 * CMSIS Peripheral Access Layer for ZLL
 */

#if !defined(PERI_ZLL_H_)
#define PERI_ZLL_H_                              /**< Symbol preventing repeated inclusion */

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
   -- ZLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ZLL_Peripheral_Access_Layer ZLL Peripheral Access Layer
 * @{
 */

/** ZLL - Register Layout Typedef */
typedef struct {
  __IO uint32_t IRQSTS;                            /**< INTERRUPT REQUEST STATUS (IRQSTS). The IRQSTS register indicates the status of interrupt requests in the802.15.4 module., offset: 0x0 */
  __IO uint32_t PHY_CTRL;                          /**< PHY CONTROL (PHY_CTRL)PHY Control Register, offset: 0x4 */
  __I  uint32_t EVENT_TMR;                         /**< EVENT TIMER (EVENT_TMR), offset: 0x8 */
  __I  uint32_t TIMESTAMP;                         /**< TIMESTAMP (TIMESTAMP), offset: 0xC */
  __IO uint32_t T1CMP;                             /**< T1 COMPARE (T1CMP)TMR1 Compare Value, offset: 0x10 */
  __IO uint32_t T2CMP;                             /**< T2 COMPARE (T2CMP)TMR2 Compare Value, offset: 0x14 */
  __IO uint32_t T2PRIMECMP;                        /**< T2 PRIME COMPARE (T2PRIMECMP)TMR2 Prime Compare Value, offset: 0x18 */
  __IO uint32_t T3CMP;                             /**< T3 COMPARE (T3CMP)TMR3 Compare Value, offset: 0x1C */
  __IO uint32_t T4CMP;                             /**< T4 COMPARE (T4CMP)TMR4 Compare Value, offset: 0x20 */
  __IO uint32_t PA_PWR;                            /**< PA POWER (PA_PWR), offset: 0x24 */
  __IO uint32_t CHANNEL_NUM0;                      /**< CHANNEL NUMBER 0 (CHANNEL_NUM0)Channel Number for PAN0, offset: 0x28 */
  __I  uint32_t LQI_AND_RSSI;                      /**< LQI AND RSSI (LQI_AND_RSSI), offset: 0x2C */
  __IO uint32_t MACSHORTADDRS0;                    /**< MAC SHORT ADDRESS 0 (MACSHORTADDRS0)MAC SHORT ADDRESS for PAN0, offset: 0x30 */
  __IO uint32_t MACLONGADDRS0_LSB;                 /**< MAC LONG ADDRESS 0 LSB (MACLONGADDRS0_LSB)MAC LONG ADDRESS for PAN0 LSB, offset: 0x34 */
  __IO uint32_t MACLONGADDRS0_MSB;                 /**< MAC LONG ADDRESS 0 MSB (MACLONGADDRS0_MSB)MAC LONG ADDRESS for PAN0 MSB, offset: 0x38 */
  __IO uint32_t RX_FRAME_FILTER;                   /**< RECEIVE FRAME FILTER (RX_FRAME_FILTER)RECEIVE FRAME FILTER, offset: 0x3C */
  __IO uint32_t CCA_LQI_CTRL;                      /**< CCA AND LQI CONTROL (CCA_LQI_CTRL), offset: 0x40 */
  __IO uint32_t CCA2_CTRL;                         /**< CCA2 CONTROL (CCA2_CTRL)CCA Mode 2 Control in Link Layer. This register provides control for CCA Mode 2 Correlation Threshold and Correlation Peaks related settings, offset: 0x44 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DSM_CTRL;                          /**< DSM CONTROL (DSM_CTRL), offset: 0x4C */
  __I  uint32_t BSM_CTRL;                          /**< BSM CONTROL (BSM_CTRL), offset: 0x50 */
  __IO uint32_t MACSHORTADDRS1;                    /**< MAC SHORT ADDRESS FOR PAN1 (MACSHORTADDRS1)The MACSHORTADDRS1 register ., offset: 0x54 */
  __IO uint32_t MACLONGADDRS1_LSB;                 /**< MAC LONG ADDRESS 1 LSB (MACLONGADDRS1_LSB)MAC Long Address for PAN1, offset: 0x58 */
  __IO uint32_t MACLONGADDRS1_MSB;                 /**< MAC LONG ADDRESS 1 MSB (MACLONGADDRS1_MSB)MAC Long Address for PAN1, offset: 0x5C */
  __IO uint32_t DUAL_PAN_CTRL;                     /**< DUAL PAN CONTROL (DUAL_PAN_CTRL)Dual PAN Control Register, offset: 0x60 */
  __IO uint32_t CHANNEL_NUM1;                      /**< CHANNEL NUMBER 1 (CHANNEL_NUM1), offset: 0x64 */
  __IO uint32_t SAM_CTRL;                          /**< SAM CONTROL (SAM_CTRL)Source Address Management Control Register, offset: 0x68 */
  __IO uint32_t SAM_TABLE;                         /**< SOURCE ADDRESS MANAGEMENT TABLE (SAM_TABLE)Source Address Management Table, offset: 0x6C */
  __I  uint32_t SAM_MATCH;                         /**< SOURCE ADDRESS MANAGEMENT MATCH (SAM_MATCH), offset: 0x70 */
  __I  uint32_t SAM_FREE_IDX;                      /**< SAM FREE INDEX (SAM_FREE_IDX), offset: 0x74 */
  __IO uint32_t SEQ_CTRL_STS;                      /**< SEQUENCE CONTROL AND STATUS (SEQ_CTRL_STS), offset: 0x78 */
  __IO uint32_t ACKDELAY;                          /**< ACK DELAY (ACKDELAY)Provides a fine-tune adjustment of the time delay between Rx warmdownand the beginning of Tx warmup for an autoTxAck packet., offset: 0x7C */
  __IO uint32_t FILTERFAIL_CODE;                   /**< FILTER FAIL CODE (FILTERFAIL_CODE), offset: 0x80 */
  __IO uint32_t RX_WTR_MARK;                       /**< RECEIVE WATER MARK (RX_WTR_MARK), offset: 0x84 */
  __IO uint32_t RESET_CTRL;                        /**< offset: 0x88 */
  __IO uint32_t SLOT_PRELOAD;                      /**< SLOT PRELOAD (SLOT_PRELOAD)Slotted Mode Preload, offset: 0x8C */
  __I  uint32_t SEQ_STATE;                         /**< 802.15.4 SEQUENCE STATE (SEQ_STATE)802.15.4 Sequence State Register, offset: 0x90 */
  __IO uint32_t TMR_PRESCALE;                      /**< TIMER PRESCALER (TMR_PRESCALE)Timer Prescaler Control Register, offset: 0x94 */
  __IO uint32_t LENIENCY_LSB;                      /**< LENIENCY LSB (LENIENCY_LSB)Packet Processor Leniency Bits (LSB), offset: 0x98 */
  __IO uint32_t LENIENCY_MSB;                      /**< LENIENCY MSB (LENIENCY_MSB)Packet Processor Leniency Bits (MSB), offset: 0x9C */
  __I  uint32_t PART_ID;                           /**< PART ID (PART_ID), offset: 0xA0 */
  __IO uint32_t COEX_CTRL;                         /**< COEXISTENCE CONTROL (COEX_CTRL)Coexistence Control Registers in Link Layer.This Register provides various control bits for Coexistence funciton. It contains the bits to enable the Coexistence funciton. Also contains Coexistence Timeout Interrupt, Coexistence Timeout Interrupt Mask bit and some other COEX bits, offset: 0xA4 */
  __IO uint32_t COEX_PRIORITY;                     /**< COEXISTENCE PRIORITY (COEX_PRIORITY)Programmable 2-bit priority for each RX or TX state in each ZSM., offset: 0xA8 */
  __IO uint32_t ENHACK_CTRL0;                      /**< ENHACK_CTRL 0 (ENHACK_CTRL0)Control Register 0 for Enhanced Acknowledgment Feature, offset: 0xAC */
  __IO uint32_t CG_OVRD;                           /**< Clock Gating Override Register (CG_OVRD), offset: 0xB0 */
  __IO uint32_t PROG_PKT_FLTR_LO_PATT_A;           /**< offset: 0xB4 */
  __IO uint32_t PROG_PKT_FLTR_UP_PATT_A;           /**< offset: 0xB8 */
  __IO uint32_t PROG_PKT_FLTR_LO_MSK_A;            /**< offset: 0xBC */
  __IO uint32_t PROG_PKT_FLTR_UP_MSK_A;            /**< offset: 0xC0 */
  __IO uint32_t PROG_PKT_FLTR_CTRL_A;              /**< offset: 0xC4 */
  __IO uint32_t PROG_PKT_FLTR_LO_PATT_B;           /**< offset: 0xC8 */
  __IO uint32_t PROG_PKT_FLTR_UP_PATT_B;           /**< offset: 0xCC */
  __IO uint32_t PROG_PKT_FLTR_LO_MSK_B;            /**< offset: 0xD0 */
  __IO uint32_t PROG_PKT_FLTR_UP_MSK_B;            /**< offset: 0xD4 */
  __IO uint32_t PROG_PKT_FLTR_CTRL_B;              /**< offset: 0xD8 */
  __I  uint32_t SAM_ADDR_PRESENT;                  /**< SAM ADDRESS PRESENT (SAM_ADDR_PRESENT), offset: 0xDC */
  __IO uint32_t TIMER_CTRL;                        /**< TIMER CONTROL (TIMER_CTRL), offset: 0xE0 */
  __I  uint32_t UNIV_CNTR_TIMESTAMP;               /**< Universal Counter Timestamp (UNIV_CNTR_TIMESTAMP), offset: 0xE4 */
  __I  uint32_t UNIV_CLK_CNTR;                     /**< Universal Clock Counter Freerunning value (UNIV_CLK_CNTR), offset: 0xE8 */
  __IO uint32_t EVENT_TMR_PRESET;                  /**< EVENT TIMER Preset value (EVENT_TMR_PRESET), offset: 0xEC */
  __IO uint32_t PROG_PKT_FLTR_INTR_MSK_STS;        /**< offset: 0xF0 */
  __I  uint32_t INTR_SUMMARY;                      /**< offset: 0xF4 */
  __I  uint32_t SAM_FREE_IDX_FND;                  /**< SAM FREE INDEX FOUND (SAM_FREE_IDX_FND), offset: 0xF8 */
} ZLL_Type;

/* ----------------------------------------------------------------------------
   -- ZLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ZLL_Register_Masks ZLL Register Masks
 * @{
 */

/*! @name IRQSTS - INTERRUPT REQUEST STATUS (IRQSTS). The IRQSTS register indicates the status of interrupt requests in the802.15.4 module. */
/*! @{ */

#define ZLL_IRQSTS_SEQIRQ_MASK                   (0x1U)
#define ZLL_IRQSTS_SEQIRQ_SHIFT                  (0U)
/*! SEQIRQ - Sequencer IRQ Sequence-end Interrupt Status bit. A '1' indicates the completion of an
 *    autosequence. This interrupt will assert whenever the Sequence Manager transitions from
 *    non-idle to idle state, for any reason. This is write a '1' to clear bit. 0x0,A Sequencer Interrupt
 *    has not occurred, 0x1,A Sequencer Interrupt has occurred
 */
#define ZLL_IRQSTS_SEQIRQ(x)                     (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_SEQIRQ_SHIFT)) & ZLL_IRQSTS_SEQIRQ_MASK)

#define ZLL_IRQSTS_TXIRQ_MASK                    (0x2U)
#define ZLL_IRQSTS_TXIRQ_SHIFT                   (1U)
/*! TXIRQ - TX IRQ Transmitter Interrupt Status bit. A '1' indicates the completion of a transmit
 *    operation. This is write a '1' to clear bit. 0x0,A TX Interrupt has not occurred, 0x1,A TX
 *    Interrupt has occurred
 */
#define ZLL_IRQSTS_TXIRQ(x)                      (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TXIRQ_SHIFT)) & ZLL_IRQSTS_TXIRQ_MASK)

#define ZLL_IRQSTS_RXIRQ_MASK                    (0x4U)
#define ZLL_IRQSTS_RXIRQ_SHIFT                   (2U)
/*! RXIRQ - RX IRQ Receiver Interrupt Status bit. A '1' indicates the completion of a receive
 *    operation. This is write a '1' to clear bit. 0x0,A RX Interrupt has not occurred, 0x1,A RX Interrupt
 *    has occurred
 */
#define ZLL_IRQSTS_RXIRQ(x)                      (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RXIRQ_SHIFT)) & ZLL_IRQSTS_RXIRQ_MASK)

#define ZLL_IRQSTS_CCAIRQ_MASK                   (0x8U)
#define ZLL_IRQSTS_CCAIRQ_SHIFT                  (3U)
/*! CCAIRQ - CCA IRQ Clear Channel Assessment Interrupt Status bit. A '1' indicates completion of
 *    CCA operation. This is write '1' to clear bit. 0x0,A CCA Interrupt has not occurred, 0x1,A CCA
 *    Interrupt has occurred
 */
#define ZLL_IRQSTS_CCAIRQ(x)                     (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_CCAIRQ_SHIFT)) & ZLL_IRQSTS_CCAIRQ_MASK)

#define ZLL_IRQSTS_RXWTRMRKIRQ_MASK              (0x10U)
#define ZLL_IRQSTS_RXWTRMRKIRQ_SHIFT             (4U)
/*! RXWTRMRKIRQ - Receive Watermark IRQ Receiver Byte Count Water Mark Interrupt Status bit. A '1'
 *    indicates that the number of bytes specified in the RX_WTR_MARK register has been reached. This
 *    is write a '1' to clear bit. 0x0,A Receive Watermark Interrupt has not occurred, 0x1,A
 *    Receive Watermark Interrupt has occurred
 */
#define ZLL_IRQSTS_RXWTRMRKIRQ(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RXWTRMRKIRQ_SHIFT)) & ZLL_IRQSTS_RXWTRMRKIRQ_MASK)

#define ZLL_IRQSTS_FILTERFAIL_IRQ_MASK           (0x20U)
#define ZLL_IRQSTS_FILTERFAIL_IRQ_SHIFT          (5U)
/*! FILTERFAIL_IRQ - Filter Fail IRQ Receiver Packet Filter Fail Interrupt Status bit. A '1'
 *    indicates that the most-recently received packet has been rejected due to elements within the packet.
 *    This is write a '1' to clear bit. In Dual PAN mode, FILTERFAIL_IRQ applies to either or both
 *    networks, as follows: A: If PAN0 and PAN1 occupy different channels and CURRENT_NETWORK=0,
 *    FILTERFAIL_IRQ applies to PAN0. B: If PAN0 and PAN1 occupy different channels and
 *    CURRENT_NETWORK=1, FILTERFAIL_IRQ applies to PAN1. C: If PAN0 and PAN1 occupy the same channel,
 *    FILTERFAIL_IRQ is the logical 'AND' of the individual PANs' Filter Fail status. 0x0,A Filter Fail Interrupt
 *    has not occurred, 0x1,A Filter Fail Interrupt has occurred
 */
#define ZLL_IRQSTS_FILTERFAIL_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_FILTERFAIL_IRQ_SHIFT)) & ZLL_IRQSTS_FILTERFAIL_IRQ_MASK)

#define ZLL_IRQSTS_PLL_UNLOCK_IRQ_MASK           (0x40U)
#define ZLL_IRQSTS_PLL_UNLOCK_IRQ_SHIFT          (6U)
/*! PLL_UNLOCK_IRQ - PLL Unlock IRQ PLL Un-lock Interrupt Status bit. A '1' indicates an unlock
 *    event has occurred in the PLL. This is write a '1' to clear bit. 0x0,A PLL Unlock Interrupt has
 *    not occurred, 0x1,A PLL Unlock Interrupt has occurred
 */
#define ZLL_IRQSTS_PLL_UNLOCK_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_PLL_UNLOCK_IRQ_SHIFT)) & ZLL_IRQSTS_PLL_UNLOCK_IRQ_MASK)

#define ZLL_IRQSTS_RX_FRM_PEND_MASK              (0x80U)
#define ZLL_IRQSTS_RX_FRM_PEND_SHIFT             (7U)
/*! RX_FRM_PEND - RX Frame Pending Status of the frame pending bit of the frame control field for
 *    the most-recently received packet. Read-only.
 */
#define ZLL_IRQSTS_RX_FRM_PEND(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RX_FRM_PEND_SHIFT)) & ZLL_IRQSTS_RX_FRM_PEND_MASK)

#define ZLL_IRQSTS_WAKE_IRQ_MASK                 (0x100U)
#define ZLL_IRQSTS_WAKE_IRQ_SHIFT                (8U)
/*! WAKE_IRQ - WAKE Interrupt Request Wake Interrupt. The RFMC TIMER has matched the WOR WKUP_TIME
 *    register, and DSM has exited. The 802.15.4 EVENT_TMR has resumed counting. 0x0,A Wake Interrupt
 *    has not occurred, 0x1,A Wake Interrupt has occurred
 */
#define ZLL_IRQSTS_WAKE_IRQ(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_WAKE_IRQ_SHIFT)) & ZLL_IRQSTS_WAKE_IRQ_MASK)

#define ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_MASK (0x200U)
#define ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_SHIFT (9U)
/*! ARB_GRANT_DEASSERTION_IRQ - arb_grant Deassertion IRQ arb_grant(!RF_NOT_ALLOWED) Deassertion
 *    Interrupt Status bit. A '1' indicates an arb_grant deassertion event has occurred. This is write
 *    a '1' to clear bit. 0x0,An arb_grant Deassertion Interrupt has not occurred, 0x1,An arb_grant
 *    Deassertion Interrupt has occurred
 */
#define ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_SHIFT)) & ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_MASK)

#define ZLL_IRQSTS_TSM_IRQ_MASK                  (0x400U)
#define ZLL_IRQSTS_TSM_IRQ_SHIFT                 (10U)
/*! TSM_IRQ - TSM IRQ TSM Interrupt Request 0x0,A TSM Interrupt has not occurred, 0x1,A TSM Interrupt has occurred */
#define ZLL_IRQSTS_TSM_IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TSM_IRQ_SHIFT)) & ZLL_IRQSTS_TSM_IRQ_MASK)

#define ZLL_IRQSTS_ENH_PKT_STATUS_MASK           (0x800U)
#define ZLL_IRQSTS_ENH_PKT_STATUS_SHIFT          (11U)
/*! ENH_PKT_STATUS - Enhanced Packet Status 0x0,The last packet received was neither 4e- nor
 *    2015-compliant, 0x1,The last packet received was 4e- or 2015-compliant (RX_FRAME_FILTER, register
 *    should be queried for additional status bits)
 */
#define ZLL_IRQSTS_ENH_PKT_STATUS(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_ENH_PKT_STATUS_SHIFT)) & ZLL_IRQSTS_ENH_PKT_STATUS_MASK)

#define ZLL_IRQSTS_PI_MASK                       (0x1000U)
#define ZLL_IRQSTS_PI_SHIFT                      (12U)
/*! PI - Poll Indication 0x0,the received packet was not a data request, 0x1,the received packet was
 *    a data request, regardless of whether a, Source Address table match occurred, or whether
 *    Source Address Management is enabled or not
 */
#define ZLL_IRQSTS_PI(x)                         (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_PI_SHIFT)) & ZLL_IRQSTS_PI_MASK)

#define ZLL_IRQSTS_SRCADDR_MASK                  (0x2000U)
#define ZLL_IRQSTS_SRCADDR_SHIFT                 (13U)
/*! SRCADDR - Source Address Match Status If Source Address Management is engaged, meaning at least
 *    one of the following bits is set: SAP0_EN SAA0_EN SAP1_EN SAA1_EN Then SRCADDR will be set to
 *    1 if the packet just received is a poll request (PI=1), and at least one of the following
 *    conditions is met: SAP0_EN and SAP0_ADDR_PRESENT SAA0_EN and SAA0_ADDR_ABSENT SAP1_EN and
 *    SAP1_ADDR_PRESENT SAA1_EN and SAA1_ADDR_ABSENT If SRCADDR=1, this indicates to SW that the Packet
 *    Processor has determined that an auto-TxACK frame must be transmitted with the FramePending
 *    subfield of the FrameControlField set to 1. HW will assemble and transmit this Ack packet. If the
 *    above conditions are not met, SRCADDR will be cleared to 0.
 */
#define ZLL_IRQSTS_SRCADDR(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_SRCADDR_SHIFT)) & ZLL_IRQSTS_SRCADDR_MASK)

#define ZLL_IRQSTS_CCA_MASK                      (0x4000U)
#define ZLL_IRQSTS_CCA_SHIFT                     (14U)
/*! CCA - CCA Status Channel IDLE/BUSY indicator. This indicator is valid at CCAIRQ and also at
 *    SEQIRQ. This flag is cleared at next receiver warm up. 0x0,IDLE, 0x1,BUSY
 */
#define ZLL_IRQSTS_CCA(x)                        (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_CCA_SHIFT)) & ZLL_IRQSTS_CCA_MASK)

#define ZLL_IRQSTS_CRCVALID_MASK                 (0x8000U)
#define ZLL_IRQSTS_CRCVALID_SHIFT                (15U)
/*! CRCVALID - CRC Valid Status * Code Redundancy Check Valid: This flag indicates the compare
 *    result between the FCS field, in the most-recently received frame, and the internally calculated
 *    CRC value. This flag is cleared at next receiver warm up. 0x0,Rx FCS != calculated CRC
 *    (incorrect), 0x1,Rx FCS = calculated CRC (correct)
 */
#define ZLL_IRQSTS_CRCVALID(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_CRCVALID_SHIFT)) & ZLL_IRQSTS_CRCVALID_MASK)

#define ZLL_IRQSTS_TMR1IRQ_MASK                  (0x10000U)
#define ZLL_IRQSTS_TMR1IRQ_SHIFT                 (16U)
/*! TMR1IRQ - Timer 1 IRQ * Timer Comparator 1 Interrupt Status bit: Indicates T1CMP comparator
 *    value matched event timer counter. This is write '1' to clear bit
 */
#define ZLL_IRQSTS_TMR1IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR1IRQ_SHIFT)) & ZLL_IRQSTS_TMR1IRQ_MASK)

#define ZLL_IRQSTS_TMR2IRQ_MASK                  (0x20000U)
#define ZLL_IRQSTS_TMR2IRQ_SHIFT                 (17U)
/*! TMR2IRQ - Timer 2 IRQ * Timer Comparator 2 Interrupt Status bit: Indicates comparator value
 *    matched event timer counter. This flag is shared between the T2CMP (24-bit) and T2PRIMECMP
 *    (16-bit) compare registers. This is write '1' to clear bit
 */
#define ZLL_IRQSTS_TMR2IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR2IRQ_SHIFT)) & ZLL_IRQSTS_TMR2IRQ_MASK)

#define ZLL_IRQSTS_TMR3IRQ_MASK                  (0x40000U)
#define ZLL_IRQSTS_TMR3IRQ_SHIFT                 (18U)
/*! TMR3IRQ - Timer 3 IRQ * Timer Comparator 3 Interrupt Status bit: Indicates T3CMP comparator
 *    value matched event timer counter. This is write '1' to clear bit
 */
#define ZLL_IRQSTS_TMR3IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR3IRQ_SHIFT)) & ZLL_IRQSTS_TMR3IRQ_MASK)

#define ZLL_IRQSTS_TMR4IRQ_MASK                  (0x80000U)
#define ZLL_IRQSTS_TMR4IRQ_SHIFT                 (19U)
/*! TMR4IRQ - Timer 4 IRQ * Timer Comparator 4 Interrupt Status bit: Indicates T4CMP comparator
 *    value matched event timer counter. This is write '1' to clear bit
 */
#define ZLL_IRQSTS_TMR4IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR4IRQ_SHIFT)) & ZLL_IRQSTS_TMR4IRQ_MASK)

#define ZLL_IRQSTS_TMR1MSK_MASK                  (0x100000U)
#define ZLL_IRQSTS_TMR1MSK_SHIFT                 (20U)
/*! TMR1MSK - Timer Comparator 1 Interrupt Mask bit 0x0,allows interrupt when comparator matches
 *    event timer count, 0x1,Interrupt generation is disabled, but a TMR1IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR1MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR1MSK_SHIFT)) & ZLL_IRQSTS_TMR1MSK_MASK)

#define ZLL_IRQSTS_TMR2MSK_MASK                  (0x200000U)
#define ZLL_IRQSTS_TMR2MSK_SHIFT                 (21U)
/*! TMR2MSK - Timer Comparator 2 Interrupt Mask bit 0x0,allows interrupt when comparator matches
 *    event timer count, 0x1,Interrupt generation is disabled, but a TMR2IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR2MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR2MSK_SHIFT)) & ZLL_IRQSTS_TMR2MSK_MASK)

#define ZLL_IRQSTS_TMR3MSK_MASK                  (0x400000U)
#define ZLL_IRQSTS_TMR3MSK_SHIFT                 (22U)
/*! TMR3MSK - Timer Comparator 3 Interrupt Mask bit 0x0,allows interrupt when comparator matches
 *    event timer count, 0x1,Interrupt generation is disabled, but a TMR3IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR3MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR3MSK_SHIFT)) & ZLL_IRQSTS_TMR3MSK_MASK)

#define ZLL_IRQSTS_TMR4MSK_MASK                  (0x800000U)
#define ZLL_IRQSTS_TMR4MSK_SHIFT                 (23U)
/*! TMR4MSK - Timer Comparator 4 Interrupt Mask bit 0x0,allows interrupt when comparator matches
 *    event timer count, 0x1,Interrupt generation is disabled, but a TMR4IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR4MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR4MSK_SHIFT)) & ZLL_IRQSTS_TMR4MSK_MASK)

#define ZLL_IRQSTS_RX_FRAME_LENGTH_MASK          (0xFF000000U)
#define ZLL_IRQSTS_RX_FRAME_LENGTH_SHIFT         (24U)
/*! RX_FRAME_LENGTH - Receive Frame Length Contents of the PHR (PHY header), or FrameLength field,
 *    of the most recently received packet. Read-only.
 */
#define ZLL_IRQSTS_RX_FRAME_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RX_FRAME_LENGTH_SHIFT)) & ZLL_IRQSTS_RX_FRAME_LENGTH_MASK)
/*! @} */

/*! @name PHY_CTRL - PHY CONTROL (PHY_CTRL)PHY Control Register */
/*! @{ */

#define ZLL_PHY_CTRL_XCVSEQ_MASK                 (0x7U)
#define ZLL_PHY_CTRL_XCVSEQ_SHIFT                (0U)
/*! XCVSEQ - 802.15.4 Transceiver Sequence Selector The Transceiver Sequence Selector register
 *    selects an autosequence for the sequence manager to execute. Sequence initiation can be immediate,
 *    or scheduled (see TMRTRIGEN). A write of XCVSEQ=IDLE will abort any ongoing sequence. A write
 *    of XCVSEQ=IDLE must always be performed after a sequence is complete, and before a new
 *    sequence is programmed. Any write to XCVSEQ other than XCVSEQ=IDLE during an ongoing sequence, shall
 *    be ignored. The mapping of XCVSEQ to sequence types is as follows: 0x0,I (IDLE), 0x1,R
 *    (RECEIVE), 0x2,T (TRANSMIT), 0x3,C (CCA), 0x4,TR (TRANSMIT/RECEIVE), 0x5,CCCA (CONTINUOUS CCA),
 *    0x6,Reserved, 0x7,Reserved
 */
#define ZLL_PHY_CTRL_XCVSEQ(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_XCVSEQ_SHIFT)) & ZLL_PHY_CTRL_XCVSEQ_MASK)

#define ZLL_PHY_CTRL_RXACKRQD_MASK               (0x10U)
#define ZLL_PHY_CTRL_RXACKRQD_SHIFT              (4U)
/*! RXACKRQD - Receive Acknowledge Frame required Applies only to Sequence TR, ignored during all
 *    other sequences. 0x0,An ordinary receive frame (any type of frame) follows the transmit, frame.
 *    0x1,A receive Ack frame is expected to follow the transmit frame, (non-Ack frames are
 *    rejected).
 */
#define ZLL_PHY_CTRL_RXACKRQD(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_RXACKRQD_SHIFT)) & ZLL_PHY_CTRL_RXACKRQD_MASK)

#define ZLL_PHY_CTRL_CCABFRTX_MASK               (0x20U)
#define ZLL_PHY_CTRL_CCABFRTX_SHIFT              (5U)
/*! CCABFRTX - CCA Before TX Applies only to Sequences T and TR, ignored during all other sequences.
 *    0x0,no CCA required, transmit operation begins immediately., 0x1,at least one CCA measurement
 *    is required prior to the transmit, operation (see also SLOTTED).
 */
#define ZLL_PHY_CTRL_CCABFRTX(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CCABFRTX_SHIFT)) & ZLL_PHY_CTRL_CCABFRTX_MASK)

#define ZLL_PHY_CTRL_SLOTTED_MASK                (0x40U)
#define ZLL_PHY_CTRL_SLOTTED_SHIFT               (6U)
/*! SLOTTED - Slotted Mode Slotted Mode, for beacon-enabled networks. Applies only to Sequences T,
 *    TR, and R, ignored during all other sequences. Used, in concert with CCABFRTX, to determine how
 *    many CCA measurements are required prior to a transmit operation. Also used during R sequence
 *    to determine whether the ensuing transmit acknowledge frame (if any) needs to be synchronized
 *    to a backoff slot boundary.
 */
#define ZLL_PHY_CTRL_SLOTTED(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_SLOTTED_SHIFT)) & ZLL_PHY_CTRL_SLOTTED_MASK)

#define ZLL_PHY_CTRL_TMRTRIGEN_MASK              (0x80U)
#define ZLL_PHY_CTRL_TMRTRIGEN_SHIFT             (7U)
/*! TMRTRIGEN - Timer2 Trigger Enable 0x0,programmed sequence initiates immediately upon write to
 *    XCVSEQ., 0x1,allow timer TC2 (or TC2') to initiate a preprogrammed sequence (see, XCVSEQ
 *    register).
 */
#define ZLL_PHY_CTRL_TMRTRIGEN(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMRTRIGEN_SHIFT)) & ZLL_PHY_CTRL_TMRTRIGEN_MASK)

#define ZLL_PHY_CTRL_SEQMSK_MASK                 (0x100U)
#define ZLL_PHY_CTRL_SEQMSK_SHIFT                (8U)
/*! SEQMSK - Sequencer Interrupt Mask 0x0,allows completion of an autosequence to generate a zigbee
 *    interrupt, 0x1,Completion of an autosequence will set the SEQIRQ status bit, but a, zigbee
 *    interrupt is not generated
 */
#define ZLL_PHY_CTRL_SEQMSK(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_SEQMSK_SHIFT)) & ZLL_PHY_CTRL_SEQMSK_MASK)

#define ZLL_PHY_CTRL_TXMSK_MASK                  (0x200U)
#define ZLL_PHY_CTRL_TXMSK_SHIFT                 (9U)
/*! TXMSK - TX Interrupt Mask 0x0,allows completion of a TX operation to generate a zigbee
 *    interrupt, 0x1,Completion of a TX operation will set the TXIRQ status bit, but a, zigbee interrupt is
 *    not generated
 */
#define ZLL_PHY_CTRL_TXMSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TXMSK_SHIFT)) & ZLL_PHY_CTRL_TXMSK_MASK)

#define ZLL_PHY_CTRL_RXMSK_MASK                  (0x400U)
#define ZLL_PHY_CTRL_RXMSK_SHIFT                 (10U)
/*! RXMSK - RX Interrupt Mask 0x0,allows completion of a RX operation to generate a zigbee
 *    interrupt, 0x1,Completion of a RX operation will set the RXIRQ status bit, but a, zigbee interrupt is
 *    not generated
 */
#define ZLL_PHY_CTRL_RXMSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_RXMSK_SHIFT)) & ZLL_PHY_CTRL_RXMSK_MASK)

#define ZLL_PHY_CTRL_CCAMSK_MASK                 (0x800U)
#define ZLL_PHY_CTRL_CCAMSK_SHIFT                (11U)
/*! CCAMSK - CCA Interrupt Mask CCA Interrupt Mask 0x0,allows completion of a CCA operation to
 *    generate a zigbee interrupt, 0x1,Completion of a CCA operation will set the CCA status bit, but a,
 *    zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_CCAMSK(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CCAMSK_SHIFT)) & ZLL_PHY_CTRL_CCAMSK_MASK)

#define ZLL_PHY_CTRL_RX_WMRK_MSK_MASK            (0x1000U)
#define ZLL_PHY_CTRL_RX_WMRK_MSK_SHIFT           (12U)
/*! RX_WMRK_MSK - RX Watermark Interrupt Mask RX Watermark Interrupt Mask 0x0,allows a Received Byte
 *    Count match to the RX_WTR_MARK threshold, register to generate a zigbee interrupt 0x1,A
 *    Received Byte Count match to the RX_WTR_MARK threshold register, will set the RXWTRMRKIRQ status
 *    bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_RX_WMRK_MSK(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_RX_WMRK_MSK_SHIFT)) & ZLL_PHY_CTRL_RX_WMRK_MSK_MASK)

#define ZLL_PHY_CTRL_FILTERFAIL_MSK_MASK         (0x2000U)
#define ZLL_PHY_CTRL_FILTERFAIL_MSK_SHIFT        (13U)
/*! FILTERFAIL_MSK - FilterFail Interrupt Mask FilterFail Interrupt Mask 0x0,allows Packet Processor
 *    Filtering Failure to generate a zigbee interrupt, 0x1,A Packet Processor Filtering Failure
 *    will set the FILTERFAIL_IRQ, status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_FILTERFAIL_MSK(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_FILTERFAIL_MSK_SHIFT)) & ZLL_PHY_CTRL_FILTERFAIL_MSK_MASK)

#define ZLL_PHY_CTRL_PLL_UNLOCK_MSK_MASK         (0x4000U)
#define ZLL_PHY_CTRL_PLL_UNLOCK_MSK_SHIFT        (14U)
/*! PLL_UNLOCK_MSK - PLL Unlock Interrupt Mask 0x0,allows PLL unlock event to generate a zigbee
 *    interrupt, 0x1,A PLL unlock event will set the PLL_UNLOCK_IRQ status bit, but a, zigbee interrupt
 *    is not generated
 */
#define ZLL_PHY_CTRL_PLL_UNLOCK_MSK(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_PLL_UNLOCK_MSK_SHIFT)) & ZLL_PHY_CTRL_PLL_UNLOCK_MSK_MASK)

#define ZLL_PHY_CTRL_CRC_MSK_MASK                (0x8000U)
#define ZLL_PHY_CTRL_CRC_MSK_SHIFT               (15U)
/*! CRC_MSK - CRC Mask CRC Mask 0x0,sequence manager ignores CRCVALID and considers the receive,
 *    operation complete after the last octet of the frame has been received. 0x1,sequence manager
 *    requires CRCVALID=1 at the end of the received, frame in order for the receive operation to
 *    complete successfully; if CRCVALID=0, sequence manager will return to preamble-detect mode after the
 *    last octet of the frame has been received.
 */
#define ZLL_PHY_CTRL_CRC_MSK(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CRC_MSK_SHIFT)) & ZLL_PHY_CTRL_CRC_MSK_MASK)

#define ZLL_PHY_CTRL_WAKE_MSK_MASK               (0x10000U)
#define ZLL_PHY_CTRL_WAKE_MSK_SHIFT              (16U)
/*! WAKE_MSK - Mask wakeup from DSM 0x0,Allows a wakeup from DSM to generate a zigbee interrupt,
 *    0x1,Wakeup from DSM will set the WAKE_IRQ status bit, but a zigbee, interrupt is not generated
 */
#define ZLL_PHY_CTRL_WAKE_MSK(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_WAKE_MSK_SHIFT)) & ZLL_PHY_CTRL_WAKE_MSK_MASK)

#define ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_MASK (0x20000U)
#define ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_SHIFT (17U)
/*! ARB_GRANT_DEASSERTION_MSK - arb_grant Deassertion Interrupt Mask 0x0,allows arb_grant
 *    deassertion event to generate a zigbee interrupt, 0x1,An arb_grant deassertion event will set the,
 *    ARB_GRANT_DEASSERTION_IRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_SHIFT)) & ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_MASK)

#define ZLL_PHY_CTRL_TSM_MSK_MASK                (0x40000U)
#define ZLL_PHY_CTRL_TSM_MSK_SHIFT               (18U)
/*! TSM_MSK - Mask generating interrupt from TSM 0x0,allows assertion of a TSM interrupt to generate
 *    a zigbee interrupt, 0x1,Assertion of a TSM interrupt will set the TSM_IRQ status bit, but a,
 *    zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_TSM_MSK(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TSM_MSK_SHIFT)) & ZLL_PHY_CTRL_TSM_MSK_MASK)

#define ZLL_PHY_CTRL_TMR1CMP_EN_MASK             (0x100000U)
#define ZLL_PHY_CTRL_TMR1CMP_EN_SHIFT            (20U)
/*! TMR1CMP_EN - Timer 1 Compare Enable 0x0,Don't allow an Event Timer Match to T1CMP to set
 *    TMR1IRQ, 0x1,Allow an Event Timer Match to T1CMP to set TMR1IRQ
 */
#define ZLL_PHY_CTRL_TMR1CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR1CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR1CMP_EN_MASK)

#define ZLL_PHY_CTRL_TMR2CMP_EN_MASK             (0x200000U)
#define ZLL_PHY_CTRL_TMR2CMP_EN_SHIFT            (21U)
/*! TMR2CMP_EN - Timer 2 Compare Enable 0x0,Don't allow an Event Timer Match to T2CMP or T2PRIMECMP
 *    to set TMR2IRQ, 0x1,Allow an Event Timer Match to T2CMP or T2PRIMECMP to set TMR2IRQ
 */
#define ZLL_PHY_CTRL_TMR2CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR2CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR2CMP_EN_MASK)

#define ZLL_PHY_CTRL_TMR3CMP_EN_MASK             (0x400000U)
#define ZLL_PHY_CTRL_TMR3CMP_EN_SHIFT            (22U)
/*! TMR3CMP_EN - Timer 3 Compare Enable 0x0,Don't allow an Event Timer Match to T3CMP to set
 *    TMR3IRQ, 0x1,Allow an Event Timer Match to T3CMP to set TMR3IRQ
 */
#define ZLL_PHY_CTRL_TMR3CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR3CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR3CMP_EN_MASK)

#define ZLL_PHY_CTRL_TMR4CMP_EN_MASK             (0x800000U)
#define ZLL_PHY_CTRL_TMR4CMP_EN_SHIFT            (23U)
/*! TMR4CMP_EN - Timer 4 Compare Enable 0x0,Don't allow an Event Timer Match to T4CMP to set
 *    TMR4IRQ, 0x1,Allow an Event Timer Match to T4CMP to set TMR4IRQ
 */
#define ZLL_PHY_CTRL_TMR4CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR4CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR4CMP_EN_MASK)

#define ZLL_PHY_CTRL_TC2PRIME_EN_MASK            (0x1000000U)
#define ZLL_PHY_CTRL_TC2PRIME_EN_SHIFT           (24U)
/*! TC2PRIME_EN - Timer 2 Prime Compare Enable 0x0,Don't allow a match of the lower 16 bits of Event
 *    Timer to, T2PRIMECMP to set TMR2IRQ 0x1,Allow a match of the lower 16 bits of Event Timer to
 *    T2PRIMECMP to, set TMR2IRQ
 */
#define ZLL_PHY_CTRL_TC2PRIME_EN(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TC2PRIME_EN_SHIFT)) & ZLL_PHY_CTRL_TC2PRIME_EN_MASK)

#define ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_MASK    (0x4000000U)
#define ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_SHIFT   (26U)
/*! TC3_POSTPONE_ON_SFD - Postpone TC3 Timeout On SFD Enable If this bit is set, if a TMR3 timeout
 *    occurs while a packet is being received ( rx_sfd_detect = 1), the timeout-related abort will be
 *    deferred until the packet reception is completed. If the packet is good, HW will signal Data
 *    Indication; otherwise the 802.15.4 ZSM (Sequence Manager) will return to SEQ_IDLE and await
 *    further commanding. 0x0,TC3 Abort will occur on TMR3 timeout, regardless of rx_sfd_detect,
 *    0x1,TC3 Abort will be deferred on TMR3 timeout if rx_sfd_detect is, asserted; otherwise the TC3
 *    Abort will occur immediately
 */
#define ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_SHIFT)) & ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_MASK)

#define ZLL_PHY_CTRL_CCATYPE_MASK                (0x18000000U)
#define ZLL_PHY_CTRL_CCATYPE_SHIFT               (27U)
/*! CCATYPE - Clear Channel Assessment Type Clear Channel Assessment Type. Selects one of four
 *    possible functions for CCA or Energy Detect, per below. 0x0,ENERGY DETECT, 0x1,CCA MODE 1, 0x2,CCA
 *    MODE 2, 0x3,CCA MODE 3
 */
#define ZLL_PHY_CTRL_CCATYPE(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CCATYPE_SHIFT)) & ZLL_PHY_CTRL_CCATYPE_MASK)

#define ZLL_PHY_CTRL_TC3TMOUT_MASK               (0x40000000U)
#define ZLL_PHY_CTRL_TC3TMOUT_SHIFT              (30U)
/*! TC3TMOUT - TMR3 Timeout Enable TMR3 Timeout Enable 0x0,TMR3 is a software timer only, 0x1,Enable
 *    TMR3 to abort Rx or CCCA operations.
 */
#define ZLL_PHY_CTRL_TC3TMOUT(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TC3TMOUT_SHIFT)) & ZLL_PHY_CTRL_TC3TMOUT_MASK)

#define ZLL_PHY_CTRL_TRCV_MSK_MASK               (0x80000000U)
#define ZLL_PHY_CTRL_TRCV_MSK_SHIFT              (31U)
/*! TRCV_MSK - Transceiver Global Interrupt Mask Transceiver Global Interrupt Mask 0x0,Enable any
 *    unmasked interrupt source to assert zigbee interrupt, 0x1,Mask all interrupt sources from
 *    asserting zigbee interrupt
 */
#define ZLL_PHY_CTRL_TRCV_MSK(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TRCV_MSK_SHIFT)) & ZLL_PHY_CTRL_TRCV_MSK_MASK)
/*! @} */

/*! @name EVENT_TMR - EVENT TIMER (EVENT_TMR) */
/*! @{ */

#define ZLL_EVENT_TMR_EVENT_TMR_FRAC_MASK        (0xFU)
#define ZLL_EVENT_TMR_EVENT_TMR_FRAC_SHIFT       (0U)
/*! EVENT_TMR_FRAC - Event Timer Fractional Component The EVENT_TMR represents a 32-bit number with
 *    28 Integer bits and 4 Fractional bits. This field is the fractional component, which appears
 *    to the right of the decimal point. The fractional component can be ignored for most 802.15.4
 *    operations which relate to the Event Timer; it has been provided only to allow for microsecond
 *    accuracy when software updates the Event Timer after a long period of DSM (sleep) mode
 */
#define ZLL_EVENT_TMR_EVENT_TMR_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_EVENT_TMR_EVENT_TMR_FRAC_SHIFT)) & ZLL_EVENT_TMR_EVENT_TMR_FRAC_MASK)

#define ZLL_EVENT_TMR_EVENT_TMR_MASK             (0xFFFFFFF0U)
#define ZLL_EVENT_TMR_EVENT_TMR_SHIFT            (4U)
/*! EVENT_TMR - Event Timer Integer Component The EVENT_TMR represents a 32-bit number with 28
 *    Integer bits and 4 Fractional bits. This field is the integer component, which appears to the left
 *    of the decimal point. Most 802.15.4 operations which relate to the Event Timer require only
 *    the integer component.
 */
#define ZLL_EVENT_TMR_EVENT_TMR(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_EVENT_TMR_EVENT_TMR_SHIFT)) & ZLL_EVENT_TMR_EVENT_TMR_MASK)
/*! @} */

/*! @name TIMESTAMP - TIMESTAMP (TIMESTAMP) */
/*! @{ */

#define ZLL_TIMESTAMP_TIMESTAMP_FRAC_MASK        (0xFU)
#define ZLL_TIMESTAMP_TIMESTAMP_FRAC_SHIFT       (0U)
/*! TIMESTAMP_FRAC - Timestamp Fractional Holds the latched value of the fractional portion of the
 *    Event Timer current time corresponding to the beginning of the most recently received packet,
 *    at the point of SFD detection
 */
#define ZLL_TIMESTAMP_TIMESTAMP_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_TIMESTAMP_TIMESTAMP_FRAC_SHIFT)) & ZLL_TIMESTAMP_TIMESTAMP_FRAC_MASK)

#define ZLL_TIMESTAMP_TIMESTAMP_MASK             (0xFFFFFFF0U)
#define ZLL_TIMESTAMP_TIMESTAMP_SHIFT            (4U)
/*! TIMESTAMP - Timestamp Holds the latched value of the integer portion of the Event Timer current
 *    time corresponding to the beginning of the most recently received packet, at the point of SFD
 *    detection
 */
#define ZLL_TIMESTAMP_TIMESTAMP(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_TIMESTAMP_TIMESTAMP_SHIFT)) & ZLL_TIMESTAMP_TIMESTAMP_MASK)
/*! @} */

/*! @name T1CMP - T1 COMPARE (T1CMP)TMR1 Compare Value */
/*! @{ */

#define ZLL_T1CMP_T1CMP_MASK                     (0xFFFFFFFU)
#define ZLL_T1CMP_T1CMP_SHIFT                    (0U)
/*! T1CMP - TMR1 Compare Value TMR1 compare value. If TMR1CMP_EN=1 and the Event Timer matches this value, TMR1IRQ is set. */
#define ZLL_T1CMP_T1CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T1CMP_T1CMP_SHIFT)) & ZLL_T1CMP_T1CMP_MASK)
/*! @} */

/*! @name T2CMP - T2 COMPARE (T2CMP)TMR2 Compare Value */
/*! @{ */

#define ZLL_T2CMP_T2CMP_MASK                     (0xFFFFFFFU)
#define ZLL_T2CMP_T2CMP_SHIFT                    (0U)
/*! T2CMP - TMR2 Compare Value TMR2 compare value. If TMR2CMP_EN=1 and TC2PRIME_EN=0 and the Event
 *    Timer matches this value, TMR2IRQ is set.
 */
#define ZLL_T2CMP_T2CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T2CMP_T2CMP_SHIFT)) & ZLL_T2CMP_T2CMP_MASK)
/*! @} */

/*! @name T2PRIMECMP - T2 PRIME COMPARE (T2PRIMECMP)TMR2 Prime Compare Value */
/*! @{ */

#define ZLL_T2PRIMECMP_T2PRIMECMP_MASK           (0xFFFFU)
#define ZLL_T2PRIMECMP_T2PRIMECMP_SHIFT          (0U)
/*! T2PRIMECMP - TMR2 Prime Compare Value TMR2 compare value. If TMR2CMP_EN=1 and TC2PRIME_EN=1 and
 *    the Event Timer matches this value, TMR2IRQ is set.
 */
#define ZLL_T2PRIMECMP_T2PRIMECMP(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_T2PRIMECMP_T2PRIMECMP_SHIFT)) & ZLL_T2PRIMECMP_T2PRIMECMP_MASK)
/*! @} */

/*! @name T3CMP - T3 COMPARE (T3CMP)TMR3 Compare Value */
/*! @{ */

#define ZLL_T3CMP_T3CMP_MASK                     (0xFFFFFFFU)
#define ZLL_T3CMP_T3CMP_SHIFT                    (0U)
/*! T3CMP - TMR3 Compare Value TMR3 compare value. If TMR3CMP_EN=1 and the Event Timer matches this value, TMR3IRQ is set. */
#define ZLL_T3CMP_T3CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T3CMP_T3CMP_SHIFT)) & ZLL_T3CMP_T3CMP_MASK)
/*! @} */

/*! @name T4CMP - T4 COMPARE (T4CMP)TMR4 Compare Value */
/*! @{ */

#define ZLL_T4CMP_T4CMP_MASK                     (0xFFFFFFFU)
#define ZLL_T4CMP_T4CMP_SHIFT                    (0U)
/*! T4CMP - TMR4 Compare Value TMR4 compare value. If TMR4CMP_EN=1 and the Event Timer matches this value, TMR4IRQ is set. */
#define ZLL_T4CMP_T4CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T4CMP_T4CMP_SHIFT)) & ZLL_T4CMP_T4CMP_MASK)
/*! @} */

/*! @name PA_PWR - PA POWER (PA_PWR) */
/*! @{ */

#define ZLL_PA_PWR_PA_PWR_MASK                   (0x7FU)
#define ZLL_PA_PWR_PA_PWR_SHIFT                  (0U)
/*! PA_PWR - PA Power */
#define ZLL_PA_PWR_PA_PWR(x)                     (((uint32_t)(((uint32_t)(x)) << ZLL_PA_PWR_PA_PWR_SHIFT)) & ZLL_PA_PWR_PA_PWR_MASK)

#define ZLL_PA_PWR_EXT_PA_PWR_MASK               (0x7F0000U)
#define ZLL_PA_PWR_EXT_PA_PWR_SHIFT              (16U)
/*! EXT_PA_PWR - External PA Power When transmitting and grant has been asserted, if
 *    zfdbk_txpower_ind asserts, then zfdbk_tx_power[5:0] is assigned to PA_PWR[6:1] and the status bit
 *    EXT_PA_PWR_CHG is set for software to check later. The value recorded in EXT_PA_PWR[6:0] is
 *    {zfdbk_tx_power[5:0],PA_PWR[0]} for debug purposes.
 */
#define ZLL_PA_PWR_EXT_PA_PWR(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PA_PWR_EXT_PA_PWR_SHIFT)) & ZLL_PA_PWR_EXT_PA_PWR_MASK)

#define ZLL_PA_PWR_EXT_PA_PWR_CHG_MASK           (0x80000000U)
#define ZLL_PA_PWR_EXT_PA_PWR_CHG_SHIFT          (31U)
/*! EXT_PA_PWR_CHG - External PA Power Change Flag THis flag is asserted when zfdbk_txpower_ind
 *    asserts during transmitting and grant has been asserted. This is write a '1' to clear bit.
 */
#define ZLL_PA_PWR_EXT_PA_PWR_CHG(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_PA_PWR_EXT_PA_PWR_CHG_SHIFT)) & ZLL_PA_PWR_EXT_PA_PWR_CHG_MASK)
/*! @} */

/*! @name CHANNEL_NUM0 - CHANNEL NUMBER 0 (CHANNEL_NUM0)Channel Number for PAN0 */
/*! @{ */

#define ZLL_CHANNEL_NUM0_CHANNEL_NUM0_MASK       (0x7FU)
#define ZLL_CHANNEL_NUM0_CHANNEL_NUM0_SHIFT      (0U)
/*! CHANNEL_NUM0 - Channel Number for PAN0 This is the mapped channel number used to transmit and
 *    receive Zigbee packets. If Dual PAN is engaged, this register applies to PAN0. CHANNEL_NUM0
 *    should be in the range: 11 <= CHANNEL_NUM0 <= 26
 */
#define ZLL_CHANNEL_NUM0_CHANNEL_NUM0(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM0_CHANNEL_NUM0_SHIFT)) & ZLL_CHANNEL_NUM0_CHANNEL_NUM0_MASK)

#define ZLL_CHANNEL_NUM0_TEMP_MACSHORTADDRS0_MASK (0xFFFF00U)
#define ZLL_CHANNEL_NUM0_TEMP_MACSHORTADDRS0_SHIFT (8U)
/*! TEMP_MACSHORTADDRS0 - TEMPORARY MAC SHORT ADDRESS for PAN0 DURING TRANSITION FROM CHILD TO PARENT AND VICE-VERSA */
#define ZLL_CHANNEL_NUM0_TEMP_MACSHORTADDRS0(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM0_TEMP_MACSHORTADDRS0_SHIFT)) & ZLL_CHANNEL_NUM0_TEMP_MACSHORTADDRS0_MASK)

#define ZLL_CHANNEL_NUM0_TEMP_SHORTADDRS_EN0_MASK (0x1000000U)
#define ZLL_CHANNEL_NUM0_TEMP_SHORTADDRS_EN0_SHIFT (24U)
/*! TEMP_SHORTADDRS_EN0 - When asserted Packet Processor will accept the packets with MACSHORTADDRS0
 *    and TEMP_MACSHORTADDRS0 during transition of the device. When de-asserted Packet Processor
 *    will accept only the packets with MACSHORTADDRS0
 */
#define ZLL_CHANNEL_NUM0_TEMP_SHORTADDRS_EN0(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM0_TEMP_SHORTADDRS_EN0_SHIFT)) & ZLL_CHANNEL_NUM0_TEMP_SHORTADDRS_EN0_MASK)
/*! @} */

/*! @name LQI_AND_RSSI - LQI AND RSSI (LQI_AND_RSSI) */
/*! @{ */

#define ZLL_LQI_AND_RSSI_LQI_VALUE_MASK          (0xFFU)
#define ZLL_LQI_AND_RSSI_LQI_VALUE_SHIFT         (0U)
/*! LQI_VALUE - LQI Value Link Quality Indicator for the most recently received packet. (LQI is also
 *    available in the Packet Buffer, at the end of the received packet data)
 */
#define ZLL_LQI_AND_RSSI_LQI_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_LQI_AND_RSSI_LQI_VALUE_SHIFT)) & ZLL_LQI_AND_RSSI_LQI_VALUE_MASK)

#define ZLL_LQI_AND_RSSI_RSSI_MASK               (0xFF00U)
#define ZLL_LQI_AND_RSSI_RSSI_SHIFT              (8U)
/*! RSSI - RSSI Value Received Signal Strength Indicator, in dBm */
#define ZLL_LQI_AND_RSSI_RSSI(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_LQI_AND_RSSI_RSSI_SHIFT)) & ZLL_LQI_AND_RSSI_RSSI_MASK)

#define ZLL_LQI_AND_RSSI_CCA1_ED_FNL_MASK        (0xFF0000U)
#define ZLL_LQI_AND_RSSI_CCA1_ED_FNL_SHIFT       (16U)
/*! CCA1_ED_FNL - Final Result for CCA Mode 1 and Energy Detect Output register to show final
 *    averaged RSSI value or compensated value of the same at the end of a CCA Mode1 or Energy Detect
 *    computation.
 */
#define ZLL_LQI_AND_RSSI_CCA1_ED_FNL(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_LQI_AND_RSSI_CCA1_ED_FNL_SHIFT)) & ZLL_LQI_AND_RSSI_CCA1_ED_FNL_MASK)

#define ZLL_LQI_AND_RSSI_RSSI_CCA_CONT_MASK      (0xFF000000U)
#define ZLL_LQI_AND_RSSI_RSSI_CCA_CONT_SHIFT     (24U)
/*! RSSI_CCA_CONT - This field is read only and never used in WCS FFU Instantiation. It will always read back zero value. */
#define ZLL_LQI_AND_RSSI_RSSI_CCA_CONT(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_LQI_AND_RSSI_RSSI_CCA_CONT_SHIFT)) & ZLL_LQI_AND_RSSI_RSSI_CCA_CONT_MASK)
/*! @} */

/*! @name MACSHORTADDRS0 - MAC SHORT ADDRESS 0 (MACSHORTADDRS0)MAC SHORT ADDRESS for PAN0 */
/*! @{ */

#define ZLL_MACSHORTADDRS0_MACPANID0_MASK        (0xFFFFU)
#define ZLL_MACSHORTADDRS0_MACPANID0_SHIFT       (0U)
/*! MACPANID0 - MAC PAN ID for PAN0 MAC PAN ID for PAN0. The packet processor compares the incoming
 *    packet's Destination PAN ID against the contents of this register to determine if the packet
 *    is addressed to this device; or if the incoming packet is a Beacon frame, the packet processor
 *    compares the incoming packet Source PAN ID against this register. Also, if PANCORDNTR0=1, and
 *    the incoming packet has no Destination Address field, and if the incoming packet is a Data or
 *    MAC Command frame, the packet processor compares the incoming packet Source PAN ID against
 *    this register.
 */
#define ZLL_MACSHORTADDRS0_MACPANID0(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS0_MACPANID0_SHIFT)) & ZLL_MACSHORTADDRS0_MACPANID0_MASK)

#define ZLL_MACSHORTADDRS0_MACSHORTADDRS0_MASK   (0xFFFF0000U)
#define ZLL_MACSHORTADDRS0_MACSHORTADDRS0_SHIFT  (16U)
/*! MACSHORTADDRS0 - MAC SHORT ADDRESS FOR PAN0 MAC Short Address for PAN0, for 16-bit destination
 *    addressing mode. The packet processor compares the incoming packet's Destination Address
 *    against the contents of this register to determine if the packet is addressed to this device.
 */
#define ZLL_MACSHORTADDRS0_MACSHORTADDRS0(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS0_MACSHORTADDRS0_SHIFT)) & ZLL_MACSHORTADDRS0_MACSHORTADDRS0_MASK)
/*! @} */

/*! @name MACLONGADDRS0_LSB - MAC LONG ADDRESS 0 LSB (MACLONGADDRS0_LSB)MAC LONG ADDRESS for PAN0 LSB */
/*! @{ */

#define ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_SHIFT (0U)
/*! MACLONGADDRS0_LSB - MAC LONG ADDRESS for PAN0 LSB MAC Long Address for PAN0, for 64-bit
 *    destination addressing mode. The packet processor compares the incoming packet's Destination Address
 *    against the contents of this register to determine if the packet is addressed to this device.
 */
#define ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_SHIFT)) & ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_MASK)
/*! @} */

/*! @name MACLONGADDRS0_MSB - MAC LONG ADDRESS 0 MSB (MACLONGADDRS0_MSB)MAC LONG ADDRESS for PAN0 MSB */
/*! @{ */

#define ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_SHIFT (0U)
/*! MACLONGADDRS0_MSB - MAC LONG ADDRESS for PAN0 MSB MAC Long Address for PAN0, for 64-bit
 *    destination addressing mode. The packet processor compares the incoming packet's Destination Address
 *    against the contents of this register to determine if the packet is addressed to this device.
 */
#define ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_SHIFT)) & ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_MASK)
/*! @} */

/*! @name RX_FRAME_FILTER - RECEIVE FRAME FILTER (RX_FRAME_FILTER)RECEIVE FRAME FILTER */
/*! @{ */

#define ZLL_RX_FRAME_FILTER_BEACON_FT_MASK       (0x1U)
#define ZLL_RX_FRAME_FILTER_BEACON_FT_SHIFT      (0U)
/*! BEACON_FT - Beacon Frame Type Enable 0x0,reject all Beacon frames, 0x1,Beacon frame type enabled. */
#define ZLL_RX_FRAME_FILTER_BEACON_FT(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_BEACON_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_BEACON_FT_MASK)

#define ZLL_RX_FRAME_FILTER_DATA_FT_MASK         (0x2U)
#define ZLL_RX_FRAME_FILTER_DATA_FT_SHIFT        (1U)
/*! DATA_FT - Data Frame Type Enable 0x0,reject all Data frames, 0x1,Data frame type enabled. */
#define ZLL_RX_FRAME_FILTER_DATA_FT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_DATA_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_DATA_FT_MASK)

#define ZLL_RX_FRAME_FILTER_ACK_FT_MASK          (0x4U)
#define ZLL_RX_FRAME_FILTER_ACK_FT_SHIFT         (2U)
/*! ACK_FT - Ack Frame Type Enable 0x0,reject all Acknowledge frames, 0x1,Acknowledge frame type enabled. */
#define ZLL_RX_FRAME_FILTER_ACK_FT(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_ACK_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_ACK_FT_MASK)

#define ZLL_RX_FRAME_FILTER_CMD_FT_MASK          (0x8U)
#define ZLL_RX_FRAME_FILTER_CMD_FT_SHIFT         (3U)
/*! CMD_FT - MAC Command Frame Type Enable 0x0,reject all MAC Command frames, 0x1,MAC Command frame type enabled. */
#define ZLL_RX_FRAME_FILTER_CMD_FT(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_CMD_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_CMD_FT_MASK)

#define ZLL_RX_FRAME_FILTER_LLDN_FT_MASK         (0x10U)
#define ZLL_RX_FRAME_FILTER_LLDN_FT_SHIFT        (4U)
/*! LLDN_FT - LLDN Frame Type Enable 0x0,reject all LLDN frames, 0x1,LLDN frame type enabled (Frame Type 4). */
#define ZLL_RX_FRAME_FILTER_LLDN_FT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_LLDN_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_LLDN_FT_MASK)

#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_MASK (0x20U)
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_SHIFT (5U)
/*! MULTIPURPOSE_FT - Multipurpose Frame Type Enable 0x0,reject all Multipurpose frames, 0x1,Multipurpose frame type enabled (Frame Type 5). */
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_MASK)

#define ZLL_RX_FRAME_FILTER_NS_FT_MASK           (0x40U)
#define ZLL_RX_FRAME_FILTER_NS_FT_SHIFT          (6U)
/*! NS_FT - Not Specified Frame Type Enable This bit enables reception of all Frame Types not
 *    covered by the other _FT bits in this register. 0x0,reject all Not Specified frames,
 *    0x1,Not-specified (reserved) frame type enabled. Applies to Frame Type, 6. No packet filtering is performed,
 *    except for frame length checking (FrameLength>=5 and FrameLength<=127). No AUTOACK is
 *    transmitted for this Frame Type
 */
#define ZLL_RX_FRAME_FILTER_NS_FT(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_NS_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_NS_FT_MASK)

#define ZLL_RX_FRAME_FILTER_EXTENDED_FT_MASK     (0x80U)
#define ZLL_RX_FRAME_FILTER_EXTENDED_FT_SHIFT    (7U)
/*! EXTENDED_FT - Extended Frame Type Enable 0x0,reject all Extended frames, 0x1,Extended frame type enabled (Frame Type 7). */
#define ZLL_RX_FRAME_FILTER_EXTENDED_FT(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_EXTENDED_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_EXTENDED_FT_MASK)

#define ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_MASK  (0xF00U)
#define ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_SHIFT (8U)
/*! FRM_VER_FILTER - Frame Version selector. The incoming packet's Frame Control Field is parsed to
 *    obtain the FrameVersion subfield, and that value is compared against this register, in
 *    accordance with the following: xxx1: Accept received packets with FrameVersion=00 xx1x: Accept
 *    received packets with FrameVersion=01 x1xx: Accept received packets with FrameVersion=10 1xxx:
 *    Accept received packets with FrameVersion=11 These filtering rules apply to Beacon, Acknowledge,
 *    Data, and MAC Command Frame Types, since these frame types require a 2-octet Frame Control Field
 *    which embeds a 2-bit FrameVersion subfield. Later frame types introduced in the 802.15.4e
 *    addendum (LLDN, Multipurpose) don't guarantee a FrameVersion subfield with the original meaning,
 *    so these filtering rules do not apply to these frame types. See registers LLDN_FT and
 *    MULTIPURPOSE_FT. For Acknowledge frames, FrameVersion bits are ignored by the Packet Processor,
 *    irrespective of FRM_VER_FILTER.
 */
#define ZLL_RX_FRAME_FILTER_FRM_VER_FILTER(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_SHIFT)) & ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_ALLOW_BCD_TYPE_FOR_PP_MASK (0x1000U)
#define ZLL_RX_FRAME_FILTER_FV2_ALLOW_BCD_TYPE_FOR_PP_SHIFT (12U)
/*! FV2_ALLOW_BCD_TYPE_FOR_PP - Enable packet_processor filter check on pp_filterfail_code0/1 for
 *    FV2, FrameType Beacon/CMD/DATA if 1'b1 : pp_filterail_code0/1 enabled for FV2, PacketType
 *    Beacon/Cmd/Data if 1'b0 (default) pp_filterfail_code0/1 are forced zero (for FV2)
 */
#define ZLL_RX_FRAME_FILTER_FV2_ALLOW_BCD_TYPE_FOR_PP(x) (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_ALLOW_BCD_TYPE_FOR_PP_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_ALLOW_BCD_TYPE_FOR_PP_MASK)

#define ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_MASK (0x8000U)
#define ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_SHIFT (15U)
/*! EXTENDED_FCS_CHK - Verify FCS on Frame Type Extended 0x0,Packet Processor will not check FCS for
 *    Frame Type EXTENDED (default), 0x1,Packet Processor will check FCS at end-of-packet based on
 *    packet, length derived from PHR, for Frame Type EXTENDED
 */
#define ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_SHIFT)) & ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_MASK (0x10000U)
#define ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_SHIFT (16U)
/*! FV2_BEACON_RECD - Frame Version 2 Beacon Packet Received 0x0,The last packet received was not
 *    Frame Type Beacon with Frame Version 2, 0x1,The last packet received was Frame Type Beacon with
 *    Frame Version 2 and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_MASK   (0x20000U)
#define ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_SHIFT  (17U)
/*! FV2_DATA_RECD - Frame Version 2 Data Packet Received 0x0,The last packet received was not Frame
 *    Type Data with Frame Version 2, 0x1,The last packet received was Frame Type Data with Frame
 *    Version 2 and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_DATA_RECD(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_MASK    (0x40000U)
#define ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_SHIFT   (18U)
/*! FV2_ACK_RECD - Frame Version 2 Acknowledge Packet Received 0x0,The last packet received was not
 *    Frame Type Ack with Frame Version 2, 0x1,The last packet received was Frame Type Ack with
 *    Frame Version 2 and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_ACK_RECD(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_MASK    (0x80000U)
#define ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_SHIFT   (19U)
/*! FV2_CMD_RECD - Frame Version 2 MAC Command Packet Received 0x0,The last packet received was not
 *    Frame Type MAC Command with Frame, Version 2 0x1,The last packet received was Frame Type MAC
 *    Command with Frame, Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_CMD_RECD(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_LLDN_RECD_MASK       (0x100000U)
#define ZLL_RX_FRAME_FILTER_LLDN_RECD_SHIFT      (20U)
/*! LLDN_RECD - LLDN Packet Received 0x0,The last packet received was not Frame Type LLDN, 0x1,The
 *    last packet received was Frame Type LLDN, and LLDN_FT=1 to allow, such packets.
 */
#define ZLL_RX_FRAME_FILTER_LLDN_RECD(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_LLDN_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_LLDN_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_MASK (0x200000U)
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_SHIFT (21U)
/*! MULTIPURPOSE_RECD - Multipurpose Packet Received 0x0,last packet received was not Frame Type
 *    MULTIPURPOSE, 0x1,The last packet received was Frame Type MULTIPURPOSE, and, MULTIPURPOSE_FT=1 to
 *    allow such packets.
 */
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD(x) (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_EXTENDED_RECD_MASK   (0x800000U)
#define ZLL_RX_FRAME_FILTER_EXTENDED_RECD_SHIFT  (23U)
/*! EXTENDED_RECD - Extended Packet Received 0x0,The last packet received was not Frame Type
 *    EXTENDED, 0x1,The last packet received was Frame Type EXTENDED, and EXTENDED_FT=1, to allow such
 *    packets.
 */
#define ZLL_RX_FRAME_FILTER_EXTENDED_RECD(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_EXTENDED_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_EXTENDED_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_PROMISCUOUS_MASK     (0x1000000U)
#define ZLL_RX_FRAME_FILTER_PROMISCUOUS_SHIFT    (24U)
/*! PROMISCUOUS - Promiscuous Mode Enable (PAN0) Bypasses most packet filtering. 0x0,normal mode,
 *    0x1,all packet filtering except frame length checking (FrameLength>=5, and FrameLength<=127) is
 *    bypassed.
 */
#define ZLL_RX_FRAME_FILTER_PROMISCUOUS(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_PROMISCUOUS_SHIFT)) & ZLL_RX_FRAME_FILTER_PROMISCUOUS_MASK)

#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_MASK (0x2000000U)
#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_SHIFT (25U)
/*! ACTIVE_PROMISCUOUS - Active Promiscuous (PAN0) 0x0,normal operation, 0x1,Provide Data Indication
 *    on all received packets under the same rules, which apply in PROMISCUOUS mode, however
 *    acknowledge those packets under rules which apply in non-PROMISCUOUS mode
 */
#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS(x) (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_SHIFT)) & ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_MASK)

#define ZLL_RX_FRAME_FILTER_AUTOACK_MASK         (0x4000000U)
#define ZLL_RX_FRAME_FILTER_AUTOACK_SHIFT        (26U)
/*! AUTOACK - Auto Acknowledge Enable (PAN0) Applies only to Sequence R and Sequence TR, ignored
 *    during other sequences 0x0,sequence manager will not follow a receive frame with a Tx Ack, frame,
 *    under any conditions; the autosequence will terminate after the receive frame. 0x1,sequence
 *    manager will follow a receive frame with an automatic, hardware-generated Tx Ack frame,
 *    assuming other necessary conditions are met.
 */
#define ZLL_RX_FRAME_FILTER_AUTOACK(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_AUTOACK_SHIFT)) & ZLL_RX_FRAME_FILTER_AUTOACK_MASK)

#define ZLL_RX_FRAME_FILTER_PANCORDNTR0_MASK     (0x8000000U)
#define ZLL_RX_FRAME_FILTER_PANCORDNTR0_SHIFT    (27U)
/*! PANCORDNTR0 - Device is a PAN Coordinator on PAN0 Device is a PAN Coordinator on PAN0. Allows
 *    device to receive packets with no destination address, if Source PAN ID matches.
 */
#define ZLL_RX_FRAME_FILTER_PANCORDNTR0(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_PANCORDNTR0_SHIFT)) & ZLL_RX_FRAME_FILTER_PANCORDNTR0_MASK)

#define ZLL_RX_FRAME_FILTER_PROMISCUOUS_PAN1_MASK (0x10000000U)
#define ZLL_RX_FRAME_FILTER_PROMISCUOUS_PAN1_SHIFT (28U)
/*! PROMISCUOUS_PAN1 - Promiscuous Mode Enable (PAN1) */
#define ZLL_RX_FRAME_FILTER_PROMISCUOUS_PAN1(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_PROMISCUOUS_PAN1_SHIFT)) & ZLL_RX_FRAME_FILTER_PROMISCUOUS_PAN1_MASK)

#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_PAN1_MASK (0x20000000U)
#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_PAN1_SHIFT (29U)
/*! ACTIVE_PROMISCUOUS_PAN1 - Active Promiscuous Mode Enable (PAN1) */
#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_PAN1(x) (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_PAN1_SHIFT)) & ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_PAN1_MASK)

#define ZLL_RX_FRAME_FILTER_AUTOACK_PAN1_MASK    (0x40000000U)
#define ZLL_RX_FRAME_FILTER_AUTOACK_PAN1_SHIFT   (30U)
/*! AUTOACK_PAN1 - Auto Acknowledge Enable (PAN1) */
#define ZLL_RX_FRAME_FILTER_AUTOACK_PAN1(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_AUTOACK_PAN1_SHIFT)) & ZLL_RX_FRAME_FILTER_AUTOACK_PAN1_MASK)

#define ZLL_RX_FRAME_FILTER_PANCORDNTR1_MASK     (0x80000000U)
#define ZLL_RX_FRAME_FILTER_PANCORDNTR1_SHIFT    (31U)
/*! PANCORDNTR1 - Device is a PAN Coordinator on PAN1 */
#define ZLL_RX_FRAME_FILTER_PANCORDNTR1(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_PANCORDNTR1_SHIFT)) & ZLL_RX_FRAME_FILTER_PANCORDNTR1_MASK)
/*! @} */

/*! @name CCA_LQI_CTRL - CCA AND LQI CONTROL (CCA_LQI_CTRL) */
/*! @{ */

#define ZLL_CCA_LQI_CTRL_CCA1_THRESH_MASK        (0xFFU)
#define ZLL_CCA_LQI_CTRL_CCA1_THRESH_SHIFT       (0U)
/*! CCA1_THRESH - CCA Mode 1 Threshold Programmable energy threshold register for CCA mode 1. */
#define ZLL_CCA_LQI_CTRL_CCA1_THRESH(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_CCA1_THRESH_SHIFT)) & ZLL_CCA_LQI_CTRL_CCA1_THRESH_MASK)

#define ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_MASK    (0xFF0000U)
#define ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_SHIFT   (16U)
/*! LQI_OFFSET_COMP - LQI Offset Compensation Programmable amount to offset RSSI based LQI value */
#define ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_SHIFT)) & ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_MASK)

#define ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_MASK       (0x1000000U)
#define ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_SHIFT      (24U)
/*! SIMUL_CCA_RX - Simultaneous CCA and Receive Enable During autosequences of type Sequence T or
 *    Sequence TR with CCA before TX, this bit allows a packet to be received if preamble and SFD are
 *    detected during the CCA measurement window. 0x0,Packets can't be received during CCA
 *    measurement, 0x1,Packet reception is enabled during CCA measurement if preamble and, SFD are detected
 */
#define ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_SHIFT)) & ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_MASK)

#define ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_MASK    (0x8000000U)
#define ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_SHIFT   (27U)
/*! CCA3_AND_NOT_OR - CCA Mode 3 AND not OR Determines the way CCA3 is required to be detected 0x0,CCA1 or CCA2, 0x1,CCA1 and CCA2 */
#define ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_SHIFT)) & ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_MASK)

#define ZLL_CCA_LQI_CTRL_CONT_RSSI_EN_MASK       (0x20000000U)
#define ZLL_CCA_LQI_CTRL_CONT_RSSI_EN_SHIFT      (29U)
/*! CONT_RSSI_EN - This is a function not used in WCS FFU Instantiation */
#define ZLL_CCA_LQI_CTRL_CONT_RSSI_EN(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_CONT_RSSI_EN_SHIFT)) & ZLL_CCA_LQI_CTRL_CONT_RSSI_EN_MASK)
/*! @} */

/*! @name CCA2_CTRL - CCA2 CONTROL (CCA2_CTRL)CCA Mode 2 Control in Link Layer. This register provides control for CCA Mode 2 Correlation Threshold and Correlation Peaks related settings */
/*! @{ */

#define ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_MASK   (0xFU)
#define ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_SHIFT  (0U)
/*! CCA2_NUM_CORR_PEAKS - CCA Mode 2 Number of Correlation Peaks Detected Counts of number of peaks
 *    that crossed CCA2_CORR_THRESH in CCA Mode 2 operation
 */
#define ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_SHIFT)) & ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_MASK)

#define ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_MASK  (0x70U)
#define ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_SHIFT (4U)
/*! CCA2_MIN_NUM_CORR_TH - CCA Mode 2 Threshold Number of Correlation Peaks Programmable threshold
 *    to be compared against number of correlation peaks that exceeded CCA2_CORR_THRESH for detecting
 *    CCA mode 2. Number of peaks detected = CCA2_MIN_NUM_CORR_TH + 1; Example: If it is programmed
 *    to 3, CCA2 logic looks for at least 4 correlation peaks that crossed the threshold, to
 *    indicate channel is idle or busy.
 */
#define ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_SHIFT)) & ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_MASK)

#define ZLL_CCA2_CTRL_CCA2_CORR_THRESH_MASK      (0xFF00U)
#define ZLL_CCA2_CTRL_CCA2_CORR_THRESH_SHIFT     (8U)
/*! CCA2_CORR_THRESH - CCA Mode 2 Correlation Threshold Correlator threshold used to qualify
 *    correlator peaks counted by CCA2_NUM_CORR_PEAKS. Correlator peaks exceeding this value increment
 *    CCA2_NUM_CORR_PEAKS.
 */
#define ZLL_CCA2_CTRL_CCA2_CORR_THRESH(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_CCA2_CTRL_CCA2_CORR_THRESH_SHIFT)) & ZLL_CCA2_CTRL_CCA2_CORR_THRESH_MASK)
/*! @} */

/*! @name DSM_CTRL - DSM CONTROL (DSM_CTRL) */
/*! @{ */

#define ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_MASK   (0x1U)
#define ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_SHIFT  (0U)
/*! ZIGBEE_SLEEP_REQUEST - 802.15.4 Deep Sleep Mode Request for Manual DSM If 802.15.4 is assigned
 *    to Manual DSM (XCVR_CTRL[MAN_DSM_SEL] = 1), setting ZIGBEE_SLEEP_REQUEST to 1 enables Deep
 *    Sleep Mode (DSM) to be entered when the RFMC TIMER matches the WOR ENTER_TIME register.
 */
#define ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_SHIFT)) & ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_MASK)
/*! @} */

/*! @name BSM_CTRL - BSM CONTROL (BSM_CTRL) */
/*! @{ */

#define ZLL_BSM_CTRL_BSM_EN_MASK                 (0x1U)
#define ZLL_BSM_CTRL_BSM_EN_SHIFT                (0U)
/*! BSM_EN - Enable Bit Stream Mode Controller */
#define ZLL_BSM_CTRL_BSM_EN(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_BSM_CTRL_BSM_EN_SHIFT)) & ZLL_BSM_CTRL_BSM_EN_MASK)
/*! @} */

/*! @name MACSHORTADDRS1 - MAC SHORT ADDRESS FOR PAN1 (MACSHORTADDRS1)The MACSHORTADDRS1 register . */
/*! @{ */

#define ZLL_MACSHORTADDRS1_MACPANID1_MASK        (0xFFFFU)
#define ZLL_MACSHORTADDRS1_MACPANID1_SHIFT       (0U)
/*! MACPANID1 - MAC PAN ID for PAN1 MAC PAN ID for PAN1. The packet processor compares the incoming
 *    packet's Destination PAN ID against the contents of this register to determine if the packet
 *    is addressed to this device; or if the incoming packet is a Beacon frame, the packet processor
 *    compares the incoming packet Source PAN ID against this register. Also, if PANCORDNTR1=1, and
 *    the incoming packet has no Destination Address field, and if the incoming packet is a Data or
 *    MAC Command frame, the packet processor compares the incoming packet Source PAN ID against
 *    this register.
 */
#define ZLL_MACSHORTADDRS1_MACPANID1(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS1_MACPANID1_SHIFT)) & ZLL_MACSHORTADDRS1_MACPANID1_MASK)

#define ZLL_MACSHORTADDRS1_MACSHORTADDRS1_MASK   (0xFFFF0000U)
#define ZLL_MACSHORTADDRS1_MACSHORTADDRS1_SHIFT  (16U)
/*! MACSHORTADDRS1 - MAC SHORT ADDRESS for PAN1 MAC Short Address for PAN1, for 16-bit destination
 *    addressing mode. The packet processor compares the incoming packet's Destination Address
 *    against the contents of this register to determine if the packet is addressed to this device.
 */
#define ZLL_MACSHORTADDRS1_MACSHORTADDRS1(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS1_MACSHORTADDRS1_SHIFT)) & ZLL_MACSHORTADDRS1_MACSHORTADDRS1_MASK)
/*! @} */

/*! @name MACLONGADDRS1_LSB - MAC LONG ADDRESS 1 LSB (MACLONGADDRS1_LSB)MAC Long Address for PAN1 */
/*! @{ */

#define ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_SHIFT (0U)
/*! MACLONGADDRS1_LSB - MAC LONG ADDRESS for PAN1 LSB MAC Long Address for PAN1, for 64-bit
 *    destination addressing mode. The packet processor compares the incoming packet's Destination Address
 *    against the contents of this register to determine if the packet is addressed to this device.
 */
#define ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_SHIFT)) & ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_MASK)
/*! @} */

/*! @name MACLONGADDRS1_MSB - MAC LONG ADDRESS 1 MSB (MACLONGADDRS1_MSB)MAC Long Address for PAN1 */
/*! @{ */

#define ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_SHIFT (0U)
/*! MACLONGADDRS1_MSB - MAC LONG ADDRESS for PAN1 MSB MAC Long Address for PAN1, for 64-bit
 *    destination addressing mode. The packet processor compares the incoming packet's Destination Address
 *    against the contents of this register to determine if the packet is addressed to this device.
 */
#define ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_SHIFT)) & ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_MASK)
/*! @} */

/*! @name DUAL_PAN_CTRL - DUAL PAN CONTROL (DUAL_PAN_CTRL)Dual PAN Control Register */
/*! @{ */

#define ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_MASK    (0x1U)
#define ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_SHIFT   (0U)
/*! ACTIVE_NETWORK - Active Network Selector Selects the PAN on which to transceive, by activating a
 *    PAN parameter set (PAN0 or PAN1). In Manual Dual PAN mode (or Single PAN mode), this bit
 *    selects the active PAN parameter set (channel and addressing parameters) which governs all
 *    autosequences. In Auto Dual PAN mode, this bit selects the PAN on which to begin transceiving,
 *    latched at the point at which DUAL_PAN_DWELL register is written. 0x0,Select PAN0, 0x1,Select PAN1
 */
#define ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_SHIFT)) & ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_MASK)

#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_MASK     (0x2U)
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_SHIFT    (1U)
/*! DUAL_PAN_AUTO - Activates automatic Dual PAN operating mode Activates automatic Dual PAN
 *    operating mode. In this mode, PAN-switching is controlled by hardware at a pre-programmed rate,
 *    determined by DUAL_PAN_DWELL. 0: Manual Dual PAN mode (or Single PAN mode). 1: Auto Dual PAN Mode
 *    Whenever DUAL_PAN_AUTO=0, CURRENT_NETWORK=ACTIVE_NETWORK at all times. In other words, software
 *    directly controls which PAN is selected. Whenever DUAL_PAN_AUTO=1, CURRENT_NETWORK is
 *    controlled by hardware.
 */
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_SHIFT)) & ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_MASK)

#define ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_MASK   (0x8U)
#define ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_SHIFT  (3U)
/*! CURRENT_NETWORK - Indicates which PAN is currently selected by hardware This read-only bit
 *    indicates which PAN is currently selected by hardware in automatic Dual PAN mode 0x0,PAN0 is
 *    selected, 0x1,PAN1 is selected
 */
#define ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_SHIFT)) & ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_MASK)

#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_MASK (0x10U)
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_SHIFT (4U)
/*! ZB_DP_CHAN_OVRD_EN - Dual PAN Channel Override Enable In Dual PAN mode, in case there is a need
 *    to generate a frequency which may be offset from the 16 prescribed 5MHz-spaced channels, to,
 *    for example, avoid interference on one of the Dual PAN channels, a method has been provided to
 *    accomplish that, by designating one of the two PAN channels to use the transceiver's set of
 *    direct frequency-programming registers, instead of CHANNEL_NUMx. Programming the direct
 *    frequency-programming registers -- integer, numerator, and denominator, allows an RF frequency to be
 *    selected with much more precision than the 5MHz granularity of the Zigbee mapped-channel
 *    registers, CHANNEL_NUM0 and CHANNEL_NUM1. Two bits have been provided in 802.15.4 space to realize
 *    this feature: ZB_DP_CHAN_OVRD_SEL and ZB_DP_CHAN_OVRD_EN. When ZB_DP_CHAN_OVRD_EN=1, this
 *    enables one of the Dual PAN channels to use the direct frequency programming. The
 *    ZB_DP_CHAN_OVRD_SEL bit determines which channel uses the direct programming, according to the following: If
 *    ZB_DP_CHAN_OVRD_EN=0, then PAN0 frequency is determined by register CHANNEL_NUM0[6:0] and PAN1
 *    frequency is determined by register CHANNEL_NUM1[6:0]. If ZB_DP_CHAN_OVRD_EN=1 and
 *    ZB_DP_CHAN_OVRD_SEL=0, then PAN0 frequency is determined by DIRECT FREQUENCY PROGRAMMING and PAN1
 *    frequency is determined by register CHANNEL_NUM1[6:0]. If ZB_DP_CHAN_OVRD_EN=1 and
 *    ZB_DP_CHAN_OVRD_SEL=1, then PAN0 frequency is determined by register CHANNEL_NUM0[6:0] and PAN1 frequency is
 *    determined by DIRECT FREQUENCY PROGRAMMING. Direct Frequency Programming is accomplished by
 *    setting the PLL's Integer, Numerator, and Denominator registers to the appropriate values for the
 *    desired RF frequency.
 */
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_SHIFT)) & ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_MASK)

#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_MASK (0x20U)
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_SHIFT (5U)
/*! ZB_DP_CHAN_OVRD_SEL - Dual PAN Channel Override Selector This bit works with ZB_DP_CHAN_OVRD_EN
 *    to allow one of the two Dual PAN channels to use Direct Frequency programming. See description
 *    for ZB_DP_CHAN_OVRD_EN .
 */
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL(x) (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_SHIFT)) & ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_MASK)

#define ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PPME_MASK (0x40U)
#define ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PPME_SHIFT (6U)
/*! RECYC_IMMEDIATE_PPME - RECYCLE trigger timing for Filterfail_codes generated by PPME 1'b0:
 *    trigger transition to RECYCLE at the end of the packet reception (default) 1'b1: trigger RECYCLE
 *    immediately
 */
#define ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PPME(x) (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PPME_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PPME_MASK)

#define ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PP_MASK (0x80U)
#define ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PP_SHIFT (7U)
/*! RECYC_IMMEDIATE_PP - RECYCLE trigger timing for Filterfail_codes generated by packet_processor
 *    1'b0: trigger transition to RECYCLE at the end of the packet reception (default) 1'b1: trigger
 *    RECYCLE immediately
 */
#define ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PP(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PP_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECYC_IMMEDIATE_PP_MASK)

#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_MASK    (0xFF00U)
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_SHIFT   (8U)
/*! DUAL_PAN_DWELL - Dual PAN Channel Frequency Dwell Time Channel Frequency Dwell Time. In Auto
 *    Dual PAN mode, hardware will toggle the PAN, after dwelling on the current PAN for the interval
 *    described below (assuming Preamble/SFD not detected). A write to DUAL_PAN_DWELL, always
 *    re-initializes the DWELL TIMER to the programmed value. If a write to DUAL_PAN_DWELL occurs during an
 *    autosequence, the DWELL TIMER will begin counting down immediately. If a write to
 *    DUAL_PAN_DWELL occurs when there is no autosequence underway, the DWELL TIMER will not begin counting
 *    until the next autosequence begins; it will begin counting at the start of the sequence warmup.
 *    DUAL_PAN_DWELL[1:0] select the timebase for the dwell time. There are 4 options:
 *    DUAL_PAN_DWELL[1:0]=0b00 --> TIMEBASE=0.5ms DUAL_PAN_DWELL[1:0]=0b01 --> TIMEBASE=2.5ms
 *    DUAL_PAN_DWELL[1:0]=0b10 --> TIMEBASE=10ms DUAL_PAN_DWELL[1:0]=0b11 --> TIMEBASE=50ms DUAL_PAN_DWELL[7:2] select
 *    how many multiples of the time base to use, from 1 (DUAL_PAN_DWELL[7:2]=0) to 64
 *    (DUAL_PAN_DWELL[7:2]=63). Given those definitions, the table below specifies the minimum and maximum dwell
 *    times for each TIMEBASE option: DUAL_PAN_DWELL[1:0]=0b00 --> MIN_DWELL=0.5ms MAX_DWELL=32ms
 *    DUAL_PAN_DWELL[1:0]=0b01 --> MIN_DWELL=2.5ms MAX_DWELL=160ms DUAL_PAN_DWELL[1:0]=0b10 -->
 *    MIN_DWELL=10ms MAX_DWELL=640ms DUAL_PAN_DWELL[1:0]=0b11 --> MIN_DWELL=50ms MAX_DWELL=3.2seconds A
 *    write to DUAL_PAN_DWELL also causes the value of ACTIVE_NETWORK to get latched into the hardware.
 *    This latched value will be the starting point for the automatic dual-pan mode (i.e., start on
 *    PAN0 or on PAN1). The starting value takes effect immediately (if sequence is underway and
 *    DUAL_PAN_AUTO=1), or is otherwise delayed until sequence starts and DUAL_PAN_AUTO=1.
 */
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_SHIFT)) & ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_MASK)

#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_MASK   (0x3F0000U)
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_SHIFT  (16U)
/*! DUAL_PAN_REMAIN - Time Remaining before next PAN switch in auto Dual PAN mode This read-only
 *    register indicates time remaining before next PAN switch in auto Dual PAN mode. The units for
 *    this register, depend on the PRESCALER setting (bits [1:0]) in the DUAL_PAN_DWELL register. Tthe
 *    units are the same as the TIMEBASE determined by the prescaler, as per the following table:
 *    DUAL_PAN_DWELL[1:0]=0b00 (TIMEBASE=0.5ms) DUAL_PAN_REMAIN UNITS=0.5ms DUAL_PAN_DWELL[1:0]=0b01
 *    (TIMEBASE=2.5ms) DUAL_PAN_REMAIN UNITS=2.5ms DUAL_PAN_DWELL[1:0]=0b10 (TIMEBASE=10ms)
 *    DUAL_PAN_REMAIN UNITS=10ms DUAL_PAN_DWELL[1:0]=0b11 (TIMEBASE=50ms) DUAL_PAN_REMAIN UNITS=50ms The
 *    readback value indicates that between N-1 and N timebase units remain until the next PAN switch.
 *    For example, a DUAL_PAN_REMAIN readback value of 3, with a DUAL_PAN_DWELL PRESCALER setting of
 *    2 (10ms), indicates that between 20ms (2*10ms) and 30ms (3*10ms), remain until the next
 *    automatic PAN switch.
 */
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_SHIFT)) & ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_MASK)

#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_MASK      (0x1000000U)
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_SHIFT     (24U)
/*! RECD_ON_PAN0 - Last Packet was Received on PAN0 Indicates the packet which was just received,
 *    was received on PAN0. In Dual PAN mode operating on 2 different channels, RECD_ON_PAN0 will be
 *    set if CURRENT_NETWORK=0 when the packet was received, regardless of FILTERFAIL status. In DUAL
 *    PAN mode operating with same channel on both networks, CURRENT_NETWORK will be ignored and
 *    RECD_ON_PAN0 will be set only if a valid packet was received on PAN0 (PAN0's FILTERFAIL_FLAG is
 *    deasserted). RECD_ON_PAN0 remains valid until the start of the next autoseqeuence.
 */
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_MASK)

#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_MASK      (0x2000000U)
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_SHIFT     (25U)
/*! RECD_ON_PAN1 - Last Packet was Received on PAN1 Indicates the packet which was just received,
 *    was received on PAN1. In Dual PAN mode operating on 2 different channels, RECD_ON_PAN1 will be
 *    set if CURRENT_NETWORK=1 when the packet was received, regardless of FILTERFAIL status. In DUAL
 *    PAN mode operating with same channel on both networks, CURRENT_NETWORK will be ignored and
 *    RECD_ON_PAN1 will be set only if a valid packet was received on PAN1 (PAN1's FILTERFAIL_FLAG is
 *    deasserted). RECD_ON_PAN1 remains valid until the start of the next autoseqeuence.
 */
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_MASK)

#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_EARLY_MASK (0x10000000U)
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_EARLY_SHIFT (28U)
/*! RECD_ON_PAN0_EARLY - Current packet is Received on PAN0, early indication. The early indication
 *    is evaluated when packet_processor or PPME have finished the addresses and/or PANId matching
 *    check on the incomming packet. The status of RECD_ON_PAN0_EARLY is valid if
 *    RECD_ON_PAN_EARLY_STS = 1'b1. Indicates the packet which was just received, was received on PAN0. In Dual PAN
 *    mode operating on 2 different channels, RECD_ON_PAN0_EARLY will be set if CURRENT_NETWORK=0 when
 *    the address or PANId matching was processed, regardless of FILTERFAIL status. In DUAL PAN mode
 *    operating with same channel on both networks, CURRENT_NETWORK will be ignored and
 *    RECD_ON_PAN0_EARLY will be set only if a valid packet was received on PAN0 (PAN0's FILTERFAIL_FLAG is
 *    deasserted). RECD_ON_PAN0_EARLY remains valid until the start of the next autoseqeuence.
 */
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_EARLY(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_EARLY_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_EARLY_MASK)

#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_EARLY_MASK (0x20000000U)
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_EARLY_SHIFT (29U)
/*! RECD_ON_PAN1_EARLY - Current packet is Received on PAN1, early indication. The early indication
 *    is evaluated when packet_processor or PPME have finished the addresses and/or PANId matching
 *    check on the incomming packet. The status of RECD_ON_PAN1_EARLY is valid if
 *    RECD_ON_PAN_EARLY_STS = 1'b1. Indicates the packet which was just received, was received on PAN1. In Dual PAN
 *    mode operating on 2 different channels, RECD_ON_PAN1_EARLY will be set if CURRENT_NETWORK=0 when
 *    the address or PANId matching was processed, regardless of FILTERFAIL status. In DUAL PAN mode
 *    operating with same channel on both networks, CURRENT_NETWORK will be ignored and
 *    RECD_ON_PAN1_EARLY will be set only if a valid packet was received on PAN1 (PAN1's FILTERFAIL_FLAG is
 *    deasserted). RECD_ON_PAN1_EARLY remains valid until the start of the next autoseqeuence.
 */
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_EARLY(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_EARLY_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_EARLY_MASK)

#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN_EARLY_STS_MASK (0x40000000U)
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN_EARLY_STS_SHIFT (30U)
/*! RECD_ON_PAN_EARLY_STS - Status flag. Indicates that for the current packet address and PANId
 *    checks are processed and that RECD_ON_PAN0_EARLY and RECD_ON_PAN1_EARLY have been evaluated and
 *    valid. For packet types that are supported for the second stage of packet filtering of the
 *    packet_processor - which includes matching checks on Address and PANId fields of the Packet header
 *    - this is at the end of receiving the packet header fields. For packet-types for which the
 *    packet_processor does not support the address and PanID fiels checks, PPME can be used for
 *    "second stage" filtering. For those PP-unsupported packets, the RECD_ON_PAN_EARLY status is set if
 *    PPME filtering has been processed, i.e as soon as the matching process has finished (either
 *    resulting in a match or no-match indication).
 */
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN_EARLY_STS(x) (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECD_ON_PAN_EARLY_STS_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECD_ON_PAN_EARLY_STS_MASK)
/*! @} */

/*! @name CHANNEL_NUM1 - CHANNEL NUMBER 1 (CHANNEL_NUM1) */
/*! @{ */

#define ZLL_CHANNEL_NUM1_CHANNEL_NUM1_MASK       (0x7FU)
#define ZLL_CHANNEL_NUM1_CHANNEL_NUM1_SHIFT      (0U)
/*! CHANNEL_NUM1 - Channel Number for PAN1 This is the mapped channel number used to transmit and
 *    receive Zigbee packets. This register applies to PAN1 only. CHANNEL_NUM1 should be in the range:
 *    11 <= CHANNEL_NUM1 <= 26 Note : This register should not be programmed, and left in its
 *    default state, if Dual PAN mode is not in use.
 */
#define ZLL_CHANNEL_NUM1_CHANNEL_NUM1(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM1_CHANNEL_NUM1_SHIFT)) & ZLL_CHANNEL_NUM1_CHANNEL_NUM1_MASK)

#define ZLL_CHANNEL_NUM1_TEMP_MACSHORTADDRS1_MASK (0xFFFF00U)
#define ZLL_CHANNEL_NUM1_TEMP_MACSHORTADDRS1_SHIFT (8U)
/*! TEMP_MACSHORTADDRS1 - TEMPORARY MAC SHORT ADDRESS for PAN1 DURING TRANSITION FROM CHILD TO PARENT AND VICE-VERSA */
#define ZLL_CHANNEL_NUM1_TEMP_MACSHORTADDRS1(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM1_TEMP_MACSHORTADDRS1_SHIFT)) & ZLL_CHANNEL_NUM1_TEMP_MACSHORTADDRS1_MASK)

#define ZLL_CHANNEL_NUM1_TEMP_SHORTADDRS_EN1_MASK (0x1000000U)
#define ZLL_CHANNEL_NUM1_TEMP_SHORTADDRS_EN1_SHIFT (24U)
/*! TEMP_SHORTADDRS_EN1 - When asserted Packet Processor will accept the packets with MACSHORTADDRS1
 *    and TEMP_MACSHORTADDRS1 during transition of the device. When de-asserted Packet Processor
 *    will accept only the packets with MACSHORTADDRS1
 */
#define ZLL_CHANNEL_NUM1_TEMP_SHORTADDRS_EN1(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM1_TEMP_SHORTADDRS_EN1_SHIFT)) & ZLL_CHANNEL_NUM1_TEMP_SHORTADDRS_EN1_MASK)
/*! @} */

/*! @name SAM_CTRL - SAM CONTROL (SAM_CTRL)Source Address Management Control Register */
/*! @{ */

#define ZLL_SAM_CTRL_SAP0_EN_MASK                (0x1U)
#define ZLL_SAM_CTRL_SAP0_EN_SHIFT               (0U)
/*! SAP0_EN - Enables SAP0 Partition of the SAM Table 0x0,Disables SAP0 Partition, 0x1,Enables SAP0 Partition */
#define ZLL_SAM_CTRL_SAP0_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAP0_EN_SHIFT)) & ZLL_SAM_CTRL_SAP0_EN_MASK)

#define ZLL_SAM_CTRL_SAA0_EN_MASK                (0x2U)
#define ZLL_SAM_CTRL_SAA0_EN_SHIFT               (1U)
/*! SAA0_EN - Enables SAA0 Partition of the SAM Table 0x0,Disables SAA0 Partition, 0x1,Enables SAA0 Partition */
#define ZLL_SAM_CTRL_SAA0_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA0_EN_SHIFT)) & ZLL_SAM_CTRL_SAA0_EN_MASK)

#define ZLL_SAM_CTRL_SAP1_EN_MASK                (0x4U)
#define ZLL_SAM_CTRL_SAP1_EN_SHIFT               (2U)
/*! SAP1_EN - Enables SAP1 Partition of the SAM Table 0x0,Disables SAP1 Partition, 0x1,Enables SAP1 Partition */
#define ZLL_SAM_CTRL_SAP1_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAP1_EN_SHIFT)) & ZLL_SAM_CTRL_SAP1_EN_MASK)

#define ZLL_SAM_CTRL_SAA1_EN_MASK                (0x8U)
#define ZLL_SAM_CTRL_SAA1_EN_SHIFT               (3U)
/*! SAA1_EN - Enables SAA1 Partition of the SAM Table 0x0,Disables SAA1 Partition, 0x1,Enables SAA1 Partition */
#define ZLL_SAM_CTRL_SAA1_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA1_EN_SHIFT)) & ZLL_SAM_CTRL_SAA1_EN_MASK)

#define ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_MASK (0x10U)
#define ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_SHIFT (4U)
/*! ENABLE_FV1_DATA_PKT_IND - Enables HW Frame Pending calculation for Frame Version 1 Data Packets
 *    for PAN0 0x0,Disables HW Frame Pending calculation for Frame Version 1 Data Packet,
 *    0x1,Enables HW Frame Pending calculation for Frame Version 1 Data Packet
 */
#define ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_SHIFT)) & ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_MASK)

#define ZLL_SAM_CTRL_FV1_DATA_PKT_IND_MASK       (0x20U)
#define ZLL_SAM_CTRL_FV1_DATA_PKT_IND_SHIFT      (5U)
/*! FV1_DATA_PKT_IND - Data Packet Indication for Frame Version 1 packet (valid only when
 *    ENABLE_FV1_DATA_PKT_IND is set) 0x0,Data Packet Indication not received, 0x1,Data Packet Indication
 *    received
 */
#define ZLL_SAM_CTRL_FV1_DATA_PKT_IND(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_FV1_DATA_PKT_IND_SHIFT)) & ZLL_SAM_CTRL_FV1_DATA_PKT_IND_MASK)

#define ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_PAN1_MASK (0x40U)
#define ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_PAN1_SHIFT (6U)
/*! ENABLE_FV1_DATA_PKT_IND_PAN1 - Enables HW Frame Pending calculation for Frame Version 1 Data
 *    Packets for PAN1 0x0,Disables HW Frame Pending calculation for Frame Version 1 Data Packet,
 *    0x1,Enables HW Frame Pending calculation for Frame Version 1 Data Packet
 */
#define ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_PAN1(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_PAN1_SHIFT)) & ZLL_SAM_CTRL_ENABLE_FV1_DATA_PKT_IND_PAN1_MASK)

#define ZLL_SAM_CTRL_SAA0_START_MASK             (0xFF00U)
#define ZLL_SAM_CTRL_SAA0_START_SHIFT            (8U)
/*! SAA0_START - First Index of SAA0 partition The reset value is 0x40 for SAM size = 128 The reset value is 0x80 for SAM size = 256 */
#define ZLL_SAM_CTRL_SAA0_START(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA0_START_SHIFT)) & ZLL_SAM_CTRL_SAA0_START_MASK)

#define ZLL_SAM_CTRL_SAP1_START_MASK             (0xFF0000U)
#define ZLL_SAM_CTRL_SAP1_START_SHIFT            (16U)
/*! SAP1_START - First Index of SAP1 partition */
#define ZLL_SAM_CTRL_SAP1_START(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAP1_START_SHIFT)) & ZLL_SAM_CTRL_SAP1_START_MASK)

#define ZLL_SAM_CTRL_SAA1_START_MASK             (0xFF000000U)
#define ZLL_SAM_CTRL_SAA1_START_SHIFT            (24U)
/*! SAA1_START - First Index of SAA1 partition */
#define ZLL_SAM_CTRL_SAA1_START(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA1_START_SHIFT)) & ZLL_SAM_CTRL_SAA1_START_MASK)
/*! @} */

/*! @name SAM_TABLE - SOURCE ADDRESS MANAGEMENT TABLE (SAM_TABLE)Source Address Management Table */
/*! @{ */

#define ZLL_SAM_TABLE_SAM_INDEX_MASK             (0xFFU)
#define ZLL_SAM_TABLE_SAM_INDEX_SHIFT            (0U)
/*! SAM_INDEX - Contains the SAM table index to be enabled or invalidated Contains the table index
 *    to be enabled or invalidated. Software must ensure that the index is within the range of the
 *    desired partition.
 */
#define ZLL_SAM_TABLE_SAM_INDEX(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_MASK)

#define ZLL_SAM_TABLE_SAM_CHECKSUM_MASK          (0xFFFF00U)
#define ZLL_SAM_TABLE_SAM_CHECKSUM_SHIFT         (8U)
/*! SAM_CHECKSUM - Software-computed source address checksum, to be installed into a table index
 *    Software-computed source address checksum, to be installed into a table index. The value on
 *    SAM_CHECKSUM[15:0] can be installed into the table with a single, atomic 32-bit write; in that
 *    case, the write data would contain the desired SAM_INDEX[6:0] and SAM_CHECKSUM[15:0], and
 *    SAM_INDEX_WR=1. If SAM_INDEX_WR=0, then the SAM_INDEX[6:0] register is written, but the checksum is
 *    not written to the table. The readback value of SAM_CHECKSUM[15:0] is the contents of the SAM
 *    Table at the location pointed to by SAM_INDEX[6:0]. To readback from a specific table index,
 *    software should first write the desired index to SAM_INDEX[6:0], and then read back the checksum
 *    from the table on SAM_CHECKSUM[15:0].
 */
#define ZLL_SAM_TABLE_SAM_CHECKSUM(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_CHECKSUM_SHIFT)) & ZLL_SAM_TABLE_SAM_CHECKSUM_MASK)

#define ZLL_SAM_TABLE_SAM_INDEX_INV_MASK         (0x1000000U)
#define ZLL_SAM_TABLE_SAM_INDEX_INV_SHIFT        (24U)
/*! SAM_INDEX_INV - Invalidate the SAM table index selected by SAM_INDEX */
#define ZLL_SAM_TABLE_SAM_INDEX_INV(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_INV_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_INV_MASK)

#define ZLL_SAM_TABLE_SAM_INDEX_EN_MASK          (0x2000000U)
#define ZLL_SAM_TABLE_SAM_INDEX_EN_SHIFT         (25U)
/*! SAM_INDEX_EN - Enable the SAM table index selected by SAM_INDEX */
#define ZLL_SAM_TABLE_SAM_INDEX_EN(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_EN_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_EN_MASK)

#define ZLL_SAM_TABLE_ACK_FRM_PND_MASK           (0x4000000U)
#define ZLL_SAM_TABLE_ACK_FRM_PND_SHIFT          (26U)
/*! ACK_FRM_PND - State of AutoTxAck FramePending field when SAM Accelleration is Disabled Software
 *    can take manual control of the FramePending field of the Frame Control Field of the next
 *    automatic TX acknowledge packet, by setting ACK_FRM_PND_CTRL=1; in that case FramePending will
 *    track the state of this bit. The FramePending field also tracks this bit if Source Address
 *    Management is completely disabled, i.e., SAP0_EN=SAA0_EN=SAP1_EN=SAA1_EN=0 Otherwise, the
 *    FramePending field is determined by Source Address Management (SAM) hardware.
 */
#define ZLL_SAM_TABLE_ACK_FRM_PND(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_ACK_FRM_PND_SHIFT)) & ZLL_SAM_TABLE_ACK_FRM_PND_MASK)

#define ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_MASK      (0x8000000U)
#define ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_SHIFT     (27U)
/*! ACK_FRM_PND_CTRL - Manual Control for AutoTxAck FramePending field 0x0,the FramePending field of
 *    the Frame Control Field of the next, automatic TX acknowledge packet is determined by
 *    hardware 0x1,the FramePending field of the Frame Control Field of the next, automatic TX acknowledge
 *    packet tracks ACK_FRM_PEND
 */
#define ZLL_SAM_TABLE_ACK_FRM_PND_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_SHIFT)) & ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_MASK)

#define ZLL_SAM_TABLE_FIND_FREE_IDX_MASK         (0x10000000U)
#define ZLL_SAM_TABLE_FIND_FREE_IDX_SHIFT        (28U)
/*! FIND_FREE_IDX - Find First Free Index After modifying Valid bits (enabling or invalidating),
 *    write this bit to 1 to force hardware to update the First Free Index registers to account for the
 *    changed Valid bits. This hardware update process takes 4us. Software can poll SAM_BUSY to
 *    determine when the table update is complete. Write-only bit. Writing 0 to this bit has no effect.
 *    Readback value is indeterminate.
 */
#define ZLL_SAM_TABLE_FIND_FREE_IDX(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_FIND_FREE_IDX_SHIFT)) & ZLL_SAM_TABLE_FIND_FREE_IDX_MASK)

#define ZLL_SAM_TABLE_INVALIDATE_ALL_MASK        (0x20000000U)
#define ZLL_SAM_TABLE_INVALIDATE_ALL_SHIFT       (29U)
/*! INVALIDATE_ALL - Invalidate Entire SAM Table Writing a 1 to this bit clears all 128 Valid bits.
 *    Invalidates the entire table. Write-only bit. Writing 0 to this bit has no effect. Readback
 *    value is indeterminate.
 */
#define ZLL_SAM_TABLE_INVALIDATE_ALL(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_INVALIDATE_ALL_SHIFT)) & ZLL_SAM_TABLE_INVALIDATE_ALL_MASK)

#define ZLL_SAM_TABLE_SAM_INDEX_WR_MASK          (0x40000000U)
#define ZLL_SAM_TABLE_SAM_INDEX_WR_SHIFT         (30U)
/*! SAM_INDEX_WR - Enables SAM Table Contents to be updated For 32-bit writes, SAM_INDEX_WR must be
 *    set to indicate that the table entry specified by SAM_INDEX[6:0] is to be written; if
 *    SAM_INDEX_WR=0, the table entry is not written, but the SAM_INDEX[6:0] register is updated. For 8-bit
 *    writes, this bit is ignored.
 */
#define ZLL_SAM_TABLE_SAM_INDEX_WR(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_WR_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_WR_MASK)

#define ZLL_SAM_TABLE_SAM_BUSY_MASK              (0x80000000U)
#define ZLL_SAM_TABLE_SAM_BUSY_SHIFT             (31U)
/*! SAM_BUSY - SAM Table Update Status Bit Hardware is in the process of updating the Source Address
 *    table, either in response to a poll indication from the packet processor, or due to software
 *    setting FIND_FREE_IDX=1. In the latter case, software should poll SAM_BUSY until low before
 *    accessing the First Free Index registers. Read-only bit.
 */
#define ZLL_SAM_TABLE_SAM_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_BUSY_SHIFT)) & ZLL_SAM_TABLE_SAM_BUSY_MASK)
/*! @} */

/*! @name SAM_MATCH - SOURCE ADDRESS MANAGEMENT MATCH (SAM_MATCH) */
/*! @{ */

#define ZLL_SAM_MATCH_SAP0_MATCH_MASK            (0xFFU)
#define ZLL_SAM_MATCH_SAP0_MATCH_SHIFT           (0U)
/*! SAP0_MATCH - Index in the SAP0 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAP0_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAP0_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAP0_MATCH_MASK)

#define ZLL_SAM_MATCH_SAA0_MATCH_MASK            (0xFF00U)
#define ZLL_SAM_MATCH_SAA0_MATCH_SHIFT           (8U)
/*! SAA0_MATCH - Index in the SAA0 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAA0_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAA0_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAA0_MATCH_MASK)

#define ZLL_SAM_MATCH_SAP1_MATCH_MASK            (0xFF0000U)
#define ZLL_SAM_MATCH_SAP1_MATCH_SHIFT           (16U)
/*! SAP1_MATCH - Index in the SAP1 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAP1_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAP1_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAP1_MATCH_MASK)

#define ZLL_SAM_MATCH_SAA1_MATCH_MASK            (0xFF000000U)
#define ZLL_SAM_MATCH_SAA1_MATCH_SHIFT           (24U)
/*! SAA1_MATCH - Index in the SAA1 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAA1_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAA1_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAA1_MATCH_MASK)
/*! @} */

/*! @name SAM_FREE_IDX - SAM FREE INDEX (SAM_FREE_IDX) */
/*! @{ */

#define ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_MASK  (0xFFU)
#define ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_SHIFT (0U)
/*! SAP0_1ST_FREE_IDX - First non-enabled (invalid) index in the SAP0 partition */
#define ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_MASK)

#define ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_MASK  (0xFF00U)
#define ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_SHIFT (8U)
/*! SAA0_1ST_FREE_IDX - First non-enabled (invalid) index in the SAA0 partition */
#define ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_MASK)

#define ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_MASK  (0xFF0000U)
#define ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_SHIFT (16U)
/*! SAP1_1ST_FREE_IDX - First non-enabled (invalid) index in the SAP1 partition */
#define ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_MASK)

#define ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_MASK  (0xFF000000U)
#define ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_SHIFT (24U)
/*! SAA1_1ST_FREE_IDX - First non-enabled (invalid) index in the SAA1 partition */
#define ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_MASK)
/*! @} */

/*! @name SEQ_CTRL_STS - SEQUENCE CONTROL AND STATUS (SEQ_CTRL_STS) */
/*! @{ */

#define ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_MASK       (0x2U)
#define ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_SHIFT      (1U)
/*! FORCE_CLK_ON - Force On 802.15.4 phy_gck Force On 802.15.4 phy_gck 0x0,Allow TSM to control
 *    802.15.4 phy_gck, for minimum power consumption, (default) 0x1,Force on 802.15.4 phy_gclk at all
 *    times, for debug purposes only
 */
#define ZLL_SEQ_CTRL_STS_FORCE_CLK_ON(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_SHIFT)) & ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_MASK)

#define ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_MASK (0x4U)
#define ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_SHIFT (2U)
/*! CLR_NEW_SEQ_INHIBIT - Overrides the automatic hardware locking of the programmed XCVSEQ while an
 *    autosequence is underway when asserted, overrides the automatic hardware locking of the
 *    programmed XCVSEQ while an autosequence is underway. Asserting this feature will allow software to
 *    change the programmed autosequence on-the-fly, without aborting and returning to idle between
 *    sequences. Overriding the hardware lockout of XCVSEQ should be used with caution, since the
 *    Sequence Manager is not designed (or verified) for manual state transitions between one type of
 *    autosequence and other (i.e., Sequence T -> Sequence R).
 */
#define ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_SHIFT)) & ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_MASK)

#define ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_MASK (0x8U)
#define ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_SHIFT (3U)
/*! EVENT_TMR_DO_NOT_LATCH - Overrides the automatic hardware latching of the Event Timer when
 *    asserted, overrides the automatic hardware latching of the Event Timer that prevents the timer from
 *    updating while software reads the 3 Event Timer bytes. This allows the Event Timer LS byte to
 *    continue to update without reading the upper 2 bytes. Overriding the automatic latching of
 *    the Event Timer should be used with caution, as it can allow the Event Timer lower bytes to get
 *    out-of-sync with the upper bytes. However, it can be useful when polling the Event Timer LS
 *    byte for a value that is just a few counts in the future.
 */
#define ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_SHIFT)) & ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_MASK)

#define ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_MASK     (0x10U)
#define ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_SHIFT    (4U)
/*! LATCH_PREAMBLE - Stickiness Control for Preamble Detection 0x0,Don't make PREAMBLE_DET and
 *    SFD_DET bits of PHY_STS (SEQ_STATE), Register sticky, i.e, these status bits reflect the realtime,
 *    dynamic state of preamble_detect and sfd_detect 0x1,Make PREAMBLE_DET and SFD_DET bits of
 *    PHY_STS (SEQ_STATE) Register, sticky, i.e., occurrences of preamble and SFD detection are latched
 *    and held until the start of the next autosequence
 */
#define ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_SHIFT)) & ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_MASK)

#define ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_MASK      (0x20U)
#define ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_SHIFT     (5U)
/*! NO_RX_RECYCLE - Disable Automatic RX Sequence Recycling when asserted, prevents the Zigbee
 *    Sequence Manager (ZSM) from automatically re-starting (recycling) the receiver when a packet is
 *    received which results in a FilterFail or CRC failure. Normally, on a RX recycle, the ZSM returns
 *    to the RX_WU (warmup) state, and then resumes from there with a new, foreshortened, Rx
 *    warmup, in search of a new preamble. When this bit is set, the Sequence Manager will instead return
 *    to idle state, and issue a SEQIRQ, after a FilterFail or CRC failure.
 */
#define ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_SHIFT)) & ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_MASK)

#define ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_MASK    (0x40U)
#define ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_SHIFT   (6U)
/*! FORCE_CRC_ERROR - Induce a CRC Error in Transmitted Packets 0x0,normal operation, 0x1,Force the
 *    next transmitted packet to have a CRC error
 */
#define ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_SHIFT)) & ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_MASK)

#define ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_MASK      (0x80U)
#define ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_SHIFT     (7U)
/*! CONTINUOUS_EN - Enable Continuous TX or RX Mode Continuous Mode Enable (Continuous TX or RX).
 *    Note: Dual PAN mode should not be engaged in Continuous TX or RX modes. 0x0,normal operation,
 *    0x1,Continuous TX or RX mode is enabled (depending on XCVSEQ setting).
 */
#define ZLL_SEQ_CTRL_STS_CONTINUOUS_EN(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_SHIFT)) & ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_MASK)

#define ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_MASK      (0x700U)
#define ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_SHIFT     (8U)
/*! XCVSEQ_ACTUAL - Indicates the programmed sequence that has been recognized by the ZSM Sequence
 *    Manager Reflects the programmed sequence that has been recognized by the Zigbee Sequence
 *    Manager. Takes into account the fact that sequence-change commands from software are ignored while a
 *    sequence is underway (see NEW_SEQ_INHIBIT). Read-only bits.
 */
#define ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_SHIFT)) & ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_MASK)

#define ZLL_SEQ_CTRL_STS_SEQ_IDLE_MASK           (0x800U)
#define ZLL_SEQ_CTRL_STS_SEQ_IDLE_SHIFT          (11U)
/*! SEQ_IDLE - ZSM Sequence Idle Indicator */
#define ZLL_SEQ_CTRL_STS_SEQ_IDLE(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_SEQ_IDLE_SHIFT)) & ZLL_SEQ_CTRL_STS_SEQ_IDLE_MASK)

#define ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_MASK    (0x1000U)
#define ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_SHIFT   (12U)
/*! NEW_SEQ_INHIBIT - New Sequence Inhibit When asserted, indicates that a new programmed
 *    autosequence has commenced (TMR2 match has occurred if TMRTRIGEN=1). Once this bit is asserted, software
 *    is blocked from commanding any new autosequences (other than Sequence I to abort the current
 *    sequence), until the current sequence completes. Hardware will ignore a sequence-change
 *    command from software while this bit is asserted. Hardware will automatically deassert this bit once
 *    the sequence completes. Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_SHIFT)) & ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_MASK)

#define ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_MASK (0x2000U)
#define ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_SHIFT (13U)
/*! RX_TIMEOUT_PENDING - Indicates a TMR3 RX Timeout is Pending when asserted, indicates that a TMR3
 *    timeout (RX timeout) flag has been set by Hardware, but the Sequence Manager has not yet
 *    aborted because an RX operation is not currently underway. This would be the case, for example,
 *    during a Sequence TR, if a TMR3 timeout were to occur during the transmit operation of this
 *    sequence; the sequence would not be aborted by Hardware until the receive operation begins. This
 *    bit will always be 0 if TC3TMOUT=0. Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_SHIFT)) & ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_MASK)

#define ZLL_SEQ_CTRL_STS_RX_MODE_MASK            (0x4000U)
#define ZLL_SEQ_CTRL_STS_RX_MODE_SHIFT           (14U)
/*! RX_MODE - RX Operation in Progress when asserted, this Sequence Manager Output indicates that an
 *    RX operation is in progress. An RX operation can be part of a complex transmit autosequence
 *    such as a Sequence TR. CCA and ED operations are considered RX operations, during which RX_MODE
 *    is asserted. Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_RX_MODE(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_RX_MODE_SHIFT)) & ZLL_SEQ_CTRL_STS_RX_MODE_MASK)

#define ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_MASK (0x8000U)
#define ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_SHIFT (15U)
/*! TMR2_SEQ_TRIG_ARMED - indicates that TMR2 has been programmed and is armed to trigger a new
 *    autosequence when asserted, indicates that TMR2 has been programmed and is armed to trigger a new
 *    autosequence, when Zigbee Sequence Manager timer-triggering mode is selected (i.e.,
 *    TMRTRIGEN=1). When timer-triggering mode is selected, TMR2 must be re-programmed (using either T2CMP or
 *    T2PRIMECMP), in advance of each new sequence. Once TMR2 is programmed, this bit will be
 *    asserted, and will remain asserted until the new sequence commences (at TMR2 match). Hardware will
 *    deassert this bit when the new sequence starts. When TMRTRIGEN=0, this bit should be ignored.
 *    Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_SHIFT)) & ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_MASK)

#define ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_MASK       (0x3F0000U)
#define ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_SHIFT      (16U)
/*! SEQ_T_STATUS - Status of the just-completed or ongoing Sequence T or Sequence TR Status of the
 *    just-completed (or ongoing) Sequence T or Sequence TR autosequence. This register is valid at
 *    all times during, and after, the Sequence T or Sequence TR. Not valid for other types of
 *    autosequences. This is a read-only register. The bits of this register map to status, according to
 *    the following table: [0] 1st CCA complete (CCABFRTX=1) [1] 2nd CCA complete (SLOTTED=1) [2] Tx
 *    operation complete [3] Rx Recycle occurred (Sequence TR only) [4] Rx operation complete
 *    (Sequence TR only) [5] TxAck operation complete(Sequence TR only)
 */
#define ZLL_SEQ_CTRL_STS_SEQ_T_STATUS(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_SHIFT)) & ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_MASK)

#define ZLL_SEQ_CTRL_STS_SW_ABORTED_MASK         (0x1000000U)
#define ZLL_SEQ_CTRL_STS_SW_ABORTED_SHIFT        (24U)
/*! SW_ABORTED - Autosequence has terminated due to a Software abort. when asserted, indicates that
 *    the autosequence has terminated due to an Software abort. Software can abort any programmed
 *    autosequence by writing Sequence I to XCVSEQ. This bit is valid at the SEQIRQ interrupt.
 *    Hardware will maintain this bit asserted until the next autosequence commences. Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_SW_ABORTED(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_SW_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_SW_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_TC3_ABORTED_MASK        (0x2000000U)
#define ZLL_SEQ_CTRL_STS_TC3_ABORTED_SHIFT       (25U)
/*! TC3_ABORTED - autosequence has terminated due to an TMR3 timeout when asserted, indicates that
 *    the autosequence has terminated due to an TC3 (TMR3) timeout during a receive operation. This
 *    bit is valid at the SEQIRQ interrupt. Hardware will maintain this bit asserted until the next
 *    autosequence commences. Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_TC3_ABORTED(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_TC3_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_TC3_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_PLL_ABORTED_MASK        (0x4000000U)
#define ZLL_SEQ_CTRL_STS_PLL_ABORTED_SHIFT       (26U)
/*! PLL_ABORTED - Autosequence has terminated due to an PLL unlock event when asserted, indicates
 *    that the autosequence has terminated due to an PLL unlock event. This bit is valid at the SEQIRQ
 *    interrupt. Hardware will maintain this bit asserted until the next autosequence commences.
 *    Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_PLL_ABORTED(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_PLL_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_PLL_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_EXT_ABORTED_MASK        (0x8000000U)
#define ZLL_SEQ_CTRL_STS_EXT_ABORTED_SHIFT       (27U)
/*! EXT_ABORTED - Autosequence has terminated due to a Wake-On-Radio command when asserted,
 *    indicates that the autosequence has terminated due to an external event, such as a Wake-On-Radio stop
 *    command. This bit is valid at the SEQIRQ interrupt. Hardware will maintain this bit asserted
 *    until the next autosequence commences. Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_EXT_ABORTED(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_EXT_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_EXT_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_MASK (0x10000000U)
#define ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_SHIFT (28U)
/*! ARB_GRANT_DEASSERTION_ABORTED - Autosequence has terminated due to an arb_grant deassertion
 *    event when asserted, indicates that the autosequence has terminated due to an arb_grant
 *    deassertion event. This bit is valid at the SEQIRQ interrupt. Hardware will maintain this bit asserted
 *    until the next autosequence commences. Read-only bit.
 */
#define ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_MASK)
/*! @} */

/*! @name ACKDELAY - ACK DELAY (ACKDELAY)Provides a fine-tune adjustment of the time delay between Rx warmdownand the beginning of Tx warmup for an autoTxAck packet. */
/*! @{ */

#define ZLL_ACKDELAY_ACKDELAY_MASK               (0x7FU)
#define ZLL_ACKDELAY_ACKDELAY_SHIFT              (0U)
/*! ACKDELAY - ACK Delay Provides a fine-tune adjustment of the time delay between Rx warmdown and
 *    the beginning of Tx warmup for an Tx Acknowledge packet. ACKDELAY register will apply to both
 *    SLOTTED and UNSLOTTED TxAck, but only to TxAck (not T sequences). This is a two's complement
 *    value. Resolution = 2us. Range = -128 - 126us. Max ACKDELAY = 0x3F. Min ACKDELAY = 0x40.
 */
#define ZLL_ACKDELAY_ACKDELAY(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_ACKDELAY_SHIFT)) & ZLL_ACKDELAY_ACKDELAY_MASK)

#define ZLL_ACKDELAY_TXDELAY_MASK                (0x3F00U)
#define ZLL_ACKDELAY_TXDELAY_SHIFT               (8U)
/*! TXDELAY - TX Delay Provides a fine-tune adjustment of the time delay between post-CCA Rx
 *    warm-down and the beginning of Tx warm-up for an Tx (non-Ack) packet. TXDELAY register will apply in
 *    both SLOTTED and UNSLOTTED modes, but only to T sequences (e.g., T, TR, and T(R) ), not TxAck
 *    operations. This is a two's complement value. The minimum permissible value is -19 (0x2D).
 *    Values less than -19 will lead to unexpected results. Resolution = 2us. Range = +/- 62us. Max
 *    TXDELAY = 0x1F. Min TXDELAY = 0x2D.
 */
#define ZLL_ACKDELAY_TXDELAY(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_TXDELAY_SHIFT)) & ZLL_ACKDELAY_TXDELAY_MASK)

#define ZLL_ACKDELAY_RXDELAY_MASK                (0x3F0000U)
#define ZLL_ACKDELAY_RXDELAY_SHIFT               (16U)
/*! RXDELAY - RX Delay Provides a fine-tune adjustment of the time delay between Tx warmdown and the
 *    beginning of Rx warmup for TR sequence. RXDELAY register will apply to both SLOTTED and
 *    UNSLOTTED TR sequence. This is an unsigned value. Resolution = 2us. Range = 3 - 127us. Max RXDELAY
 *    = 0x3F. Min RXDELAY = 0x01.
 */
#define ZLL_ACKDELAY_RXDELAY(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_RXDELAY_SHIFT)) & ZLL_ACKDELAY_RXDELAY_MASK)

#define ZLL_ACKDELAY_FAST_TX_WD_EN_MASK          (0x1000000U)
#define ZLL_ACKDELAY_FAST_TX_WD_EN_SHIFT         (24U)
/*! FAST_TX_WD_EN - Fast TX_WD enable/disable When this bit is enabled, the Zigbee squence manager
 *    executes the fast TX warmdown sequence by bypassing TX_PA_OFF and XTAL_CLK1 and jumping from
 *    TX_WD to TSM_WD directly. 0x0,Disable fast Tx warmdown sequence., 0x1,Enable fast Tx warmdown
 *    sequence.
 */
#define ZLL_ACKDELAY_FAST_TX_WD_EN(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_FAST_TX_WD_EN_SHIFT)) & ZLL_ACKDELAY_FAST_TX_WD_EN_MASK)

#define ZLL_ACKDELAY_FAST_TX_WD_DELAY_MASK       (0x6000000U)
#define ZLL_ACKDELAY_FAST_TX_WD_DELAY_SHIFT      (25U)
/*! FAST_TX_WD_DELAY - FAST_TX_WD_DELAY Provides a fine-tune adjustment of the time delay from the
 *    beginning of Tx warmdown to the end of Tx warmdown when FAST_TX_WD_EN is set to 1.
 */
#define ZLL_ACKDELAY_FAST_TX_WD_DELAY(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_FAST_TX_WD_DELAY_SHIFT)) & ZLL_ACKDELAY_FAST_TX_WD_DELAY_MASK)
/*! @} */

/*! @name FILTERFAIL_CODE - FILTER FAIL CODE (FILTERFAIL_CODE) */
/*! @{ */

#define ZLL_FILTERFAIL_CODE_PP_FILTERFAIL_CODE_MASK (0x3FFU)
#define ZLL_FILTERFAIL_CODE_PP_FILTERFAIL_CODE_SHIFT (0U)
/*! PP_FILTERFAIL_CODE - Filter Fail Code, packet_processor Code indicating what condition, or
 *    conditions, caused the Packet Processor to reject the just-received packet. The bits of
 *    FILTERFAIL_CODE indicate the reason for packet rejection. For a description of the individual
 *    FILTERFAIL_CODE bits, see the 802.15.4 Link Layer Controller chapter.
 */
#define ZLL_FILTERFAIL_CODE_PP_FILTERFAIL_CODE(x) (((uint32_t)(((uint32_t)(x)) << ZLL_FILTERFAIL_CODE_PP_FILTERFAIL_CODE_SHIFT)) & ZLL_FILTERFAIL_CODE_PP_FILTERFAIL_CODE_MASK)

#define ZLL_FILTERFAIL_CODE_PPME_FILTERFAIL_CODE_MASK (0xC00U)
#define ZLL_FILTERFAIL_CODE_PPME_FILTERFAIL_CODE_SHIFT (10U)
/*! PPME_FILTERFAIL_CODE - Filter Fail Code, Programmable Packet Filter Matching Engine (PPME) */
#define ZLL_FILTERFAIL_CODE_PPME_FILTERFAIL_CODE(x) (((uint32_t)(((uint32_t)(x)) << ZLL_FILTERFAIL_CODE_PPME_FILTERFAIL_CODE_SHIFT)) & ZLL_FILTERFAIL_CODE_PPME_FILTERFAIL_CODE_MASK)

#define ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_RAW_SEL_MASK (0x4000U)
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_RAW_SEL_SHIFT (14U)
/*! FILTERFAIL_CODE_RAW_SEL - Select PP_FILTERFAIL_CODE before or after filtering by PROMISCOUS,
 *    Applied to PAN0 and PAN1 FILTERFAIL_CODES of the packet_processor (not relevant for
 *    PPME_FILTERFAIL_CODE) 1'b0: PP_FILTERFAIL_CODE after PROMISCUOUS filtering 1'b1: PP_FILTERFAIL_CODE before
 *    PROMISCOUS fitlering
 */
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_RAW_SEL(x) (((uint32_t)(((uint32_t)(x)) << ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_RAW_SEL_SHIFT)) & ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_RAW_SEL_MASK)

#define ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_MASK (0x8000U)
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_SHIFT (15U)
/*! FILTERFAIL_PAN_SEL - PAN Selector for Filter Fail Code 0x0,{ PPME_FILTERFAIL_CODE[1:0],
 *    PP_FILTERFAIL_CODE[9:0] } will report the FILTERFAIL status of PAN0, 0x1,{ PPME_FILTERFAIL_CODE[1:0],
 *    PP_FILTERFAIL_CODE[9:0] } will report the FILTERFAIL status of PAN1
 */
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL(x) (((uint32_t)(((uint32_t)(x)) << ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_SHIFT)) & ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_MASK)
/*! @} */

/*! @name RX_WTR_MARK - RECEIVE WATER MARK (RX_WTR_MARK) */
/*! @{ */

#define ZLL_RX_WTR_MARK_RX_WTR_MARK_MASK         (0xFFU)
#define ZLL_RX_WTR_MARK_RX_WTR_MARK_SHIFT        (0U)
/*! RX_WTR_MARK - RECEIVE WATER MARK Receive byte count (octets) needed to trigger a RXWTRMRKIRQ
 *    interrupt . A setting of 0 generates an interrupt at end of the Frame Length field (first byte
 *    after SFD). A setting of 1 generates an interrupt after the first byte of Frame Control Field,
 *    etc.
 */
#define ZLL_RX_WTR_MARK_RX_WTR_MARK(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_RX_WTR_MARK_RX_WTR_MARK_SHIFT)) & ZLL_RX_WTR_MARK_RX_WTR_MARK_MASK)
/*! @} */

/*! @name RESET_CTRL -  */
/*! @{ */

#define ZLL_RESET_CTRL_SEQ_MGR_RST_MASK          (0x1U)
#define ZLL_RESET_CTRL_SEQ_MGR_RST_SHIFT         (0U)
/*! SEQ_MGR_RST - Setting this bit will reset all BSM Controller Register. FW should set it and then clear it to assert a reset pulse. */
#define ZLL_RESET_CTRL_SEQ_MGR_RST(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_RESET_CTRL_SEQ_MGR_RST_SHIFT)) & ZLL_RESET_CTRL_SEQ_MGR_RST_MASK)

#define ZLL_RESET_CTRL_RX_RST_MASK               (0x2U)
#define ZLL_RESET_CTRL_RX_RST_SHIFT              (1U)
/*! RX_RST - Setting this bit will reset all Rx Datapath. FW should set it and then clear it to assert a reset pulse. */
#define ZLL_RESET_CTRL_RX_RST(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_RESET_CTRL_RX_RST_SHIFT)) & ZLL_RESET_CTRL_RX_RST_MASK)

#define ZLL_RESET_CTRL_TX_RST_MASK               (0x4U)
#define ZLL_RESET_CTRL_TX_RST_SHIFT              (2U)
/*! TX_RST - Setting this bit will reset all Tx Datapath. FW should set it and then clear it to assert a reset pulse. */
#define ZLL_RESET_CTRL_TX_RST(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_RESET_CTRL_TX_RST_SHIFT)) & ZLL_RESET_CTRL_TX_RST_MASK)

#define ZLL_RESET_CTRL_PLL_RST_MASK              (0x8U)
#define ZLL_RESET_CTRL_PLL_RST_SHIFT             (3U)
/*! PLL_RST - This field will reset the PLL but not applicable to WCS FFU Instantiation */
#define ZLL_RESET_CTRL_PLL_RST(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_RESET_CTRL_PLL_RST_SHIFT)) & ZLL_RESET_CTRL_PLL_RST_MASK)

#define ZLL_RESET_CTRL_REGS_RST_MASK             (0x10U)
#define ZLL_RESET_CTRL_REGS_RST_SHIFT            (4U)
/*! REGS_RST - Setting this bit will reset all Interrupt Status Register. FW should set it and then clear it to assert a reset pulse. */
#define ZLL_RESET_CTRL_REGS_RST(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_RESET_CTRL_REGS_RST_SHIFT)) & ZLL_RESET_CTRL_REGS_RST_MASK)

#define ZLL_RESET_CTRL_ZIGBEE_RST_MASK           (0x80U)
#define ZLL_RESET_CTRL_ZIGBEE_RST_SHIFT          (7U)
/*! ZIGBEE_RST - Setting this bit will reset BSM Controller, Rx/Tx Datapath & Interrupt Status
 *    Register. FW should set it and then clear it to assert a reset pulse.
 */
#define ZLL_RESET_CTRL_ZIGBEE_RST(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_RESET_CTRL_ZIGBEE_RST_SHIFT)) & ZLL_RESET_CTRL_ZIGBEE_RST_MASK)
/*! @} */

/*! @name SLOT_PRELOAD - SLOT PRELOAD (SLOT_PRELOAD)Slotted Mode Preload */
/*! @{ */

#define ZLL_SLOT_PRELOAD_SLOT_PRELOAD_MASK       (0xFFU)
#define ZLL_SLOT_PRELOAD_SLOT_PRELOAD_SHIFT      (0U)
/*! SLOT_PRELOAD - Slotted Mode Preload This register represents the number that gets loaded into
 *    the slot_timer at SFD detect, which ultimately determines when the next slot boundary will
 *    occur. Due to processing delays within the analog front-end and digital modem, the point at which
 *    SFD is detected by the modem, is delayed relative to over-the-air timing. This register setting
 *    compensates for that delay. This timing parameter is critical for the Sequence R autosequence
 *    in SLOTTED mode, when an automatic TxAck is required.
 */
#define ZLL_SLOT_PRELOAD_SLOT_PRELOAD(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_SLOT_PRELOAD_SLOT_PRELOAD_SHIFT)) & ZLL_SLOT_PRELOAD_SLOT_PRELOAD_MASK)
/*! @} */

/*! @name SEQ_STATE - 802.15.4 SEQUENCE STATE (SEQ_STATE)802.15.4 Sequence State Register */
/*! @{ */

#define ZLL_SEQ_STATE_SEQ_STATE_MASK             (0x1FU)
#define ZLL_SEQ_STATE_SEQ_STATE_SHIFT            (0U)
/*! SEQ_STATE - ZSM Sequence State This read-only register reflects the instantaneous state of the 802.15.4 Sequence Manager */
#define ZLL_SEQ_STATE_SEQ_STATE(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_SEQ_STATE_SHIFT)) & ZLL_SEQ_STATE_SEQ_STATE_MASK)

#define ZLL_SEQ_STATE_PREAMBLE_DET_MASK          (0x100U)
#define ZLL_SEQ_STATE_PREAMBLE_DET_SHIFT         (8U)
/*! PREAMBLE_DET - Preamble Detected 0x0 an 802.15.4 preamble has not been detected. 1: An 802.15.4
 *    preamble has been detected. The function of this read-only bit depends on the setting of the
 *    LATCH_PREAMBLE bit of the SEQ_MGR_CTRL register. If LATCH_PREAMBLE=1, any preamble detection
 *    during a Sequence R (even false detections), will set this bit, and it will remain set (sticky)
 *    until the start of the next autosequence. If LATCH_PREAMBLE=0, this bit is not sticky, and
 *    reflects the instantaneous state of the preamble-detection circuit; for false preambles, the bit
 *    will clear when the false nature of the preamble is recognized. When LATCH_PREAMBLE=0,
 *    PREAMBLE_DET should be considered valid only while an autosequence is underway.
 */
#define ZLL_SEQ_STATE_PREAMBLE_DET(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_PREAMBLE_DET_SHIFT)) & ZLL_SEQ_STATE_PREAMBLE_DET_MASK)

#define ZLL_SEQ_STATE_SFD_DET_MASK               (0x200U)
#define ZLL_SEQ_STATE_SFD_DET_SHIFT              (9U)
/*! SFD_DET - SFD Detected 0x0 an 802.15.4 preamble-and-SFD have not been detected. 1: An 802.15.4
 *    preamble-and-SFD have been detected. The function of this read-only bit depends on the setting
 *    of the LATCH_PREAMBLE bit of the SEQ_MGR_CTRL register. If LATCH_PREAMBLE=1, any
 *    preamble-and-SFD detection during a Sequence R (even false detections), will set this bit, and it will
 *    remain set (sticky) until the start of the next autosequence. If LATCH_PREAMBLE=0, this bit is not
 *    sticky, and reflects the instantaneous state of the SFD-detection circuit; for false SFD, the
 *    bit will clear when the false nature of the SFD is recognized (i.e., an RX recycle). When
 *    LATCH_PREAMBLE=0, SFD_DET should be considered valid only while an autosequence is underway.
 */
#define ZLL_SEQ_STATE_SFD_DET(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_SFD_DET_SHIFT)) & ZLL_SEQ_STATE_SFD_DET_MASK)

#define ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_MASK   (0x400U)
#define ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_SHIFT  (10U)
/*! FILTERFAIL_FLAG_SEL - Consolidated Filter Fail Flag 0x0 The incoming, or just-received packet,
 *    passed packet filtering rules. 1: The incoming, or just-received packet, failed packet
 *    filtering rules When FILTERFAIL_FLAG_SEL=1, a non-zero FILTERFAIL_CODE is present (see FILTERFAIL_CODE
 *    registers). In Dual PAN mode, FILTERFAIL_FLAG_SEL applies to either or both networks, as
 *    follows: A: If PAN0 and PAN1 occupy different channels and CURRENT_NETWORK=0, FILTERFAIL_FLAG_SEL
 *    applies to PAN0. B: If PAN0 and PAN1 occupy different channels and CURRENT_NETWORK=1,
 *    FILTERFAIL_FLAG_SEL applies to PAN1. C: If PAN0 and PAN1 occupy the same channel, FILTERFAIL_FLAG_SEL
 *    is the logical 'AND' of the individual PANs' FILTERFAIL_FLAG bits.
 */
#define ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_SHIFT)) & ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_MASK)

#define ZLL_SEQ_STATE_CRCVALID_MASK              (0x800U)
#define ZLL_SEQ_STATE_CRCVALID_SHIFT             (11U)
/*! CRCVALID - CRC Valid Indicator * Cyclic Redundancy Check Valid: This flag indicates the compare
 *    result between the FCS field, in the most-recently received frame, and the internally
 *    calculated CRC value. This flag is cleared at next receiver warm up. 0x0,Rx FCS != calculated CRC
 *    (incorrect), 0x1,Rx FCS = calculated CRC (correct)
 */
#define ZLL_SEQ_STATE_CRCVALID(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_CRCVALID_SHIFT)) & ZLL_SEQ_STATE_CRCVALID_MASK)

#define ZLL_SEQ_STATE_PLL_ABORT_MASK             (0x1000U)
#define ZLL_SEQ_STATE_PLL_ABORT_SHIFT            (12U)
/*! PLL_ABORT - Raw PLL Abort Signal This bit reflects the instantaneous, consolidated status of the
 *    PLL unlock detection circuits; if asserted high, indicates that at least one of the three PLL
 *    unlock detect mechanisms is currently reporting an unlocked condition.
 */
#define ZLL_SEQ_STATE_PLL_ABORT(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_PLL_ABORT_SHIFT)) & ZLL_SEQ_STATE_PLL_ABORT_MASK)

#define ZLL_SEQ_STATE_PLL_ABORTED_MASK           (0x2000U)
#define ZLL_SEQ_STATE_PLL_ABORTED_SHIFT          (13U)
/*! PLL_ABORTED - Autosequence has terminated due to an PLL unlock event when asserted, indicates
 *    that the autosequence has terminated due to an PLL unlock event. This bit is valid at the SEQIRQ
 *    interrupt. Hardware will maintain this bit asserted until the next autosequence commences.
 *    This bit is a read-only mirror of the register bit of the same name in the ABORT_STS
 *    (SEQ_CTRL_STS) register.
 */
#define ZLL_SEQ_STATE_PLL_ABORTED(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_PLL_ABORTED_SHIFT)) & ZLL_SEQ_STATE_PLL_ABORTED_MASK)

#define ZLL_SEQ_STATE_PPME_FILTERFAIL_FLAG_SEL_MASK (0x4000U)
#define ZLL_SEQ_STATE_PPME_FILTERFAIL_FLAG_SEL_SHIFT (14U)
/*! PPME_FILTERFAIL_FLAG_SEL - Consolidated Filter Fail Flag (PPME) 0x0 The incoming, or
 *    just-received packet, passed PPME filtering (matching) rules. 1: The incoming, or just-received packet,
 *    failed packet filtering (matching) rules When PPME_FILTERFAIL_FLAG_SEL=1, a non-zero
 *    PPME_FILTERFAIL_CODE is present (see PPME_FILTERFAIL_CODE registers). In Dual PAN mode,
 *    PPME_FILTERFAIL_FLAG_SEL applies to either or both networks, as follows: A: If PAN0 and PAN1 occupy different
 *    channels and CURRENT_NETWORK=0, PPME_FILTERFAIL_FLAG_SEL applies to PAN0. B: If PAN0 and PAN1
 *    occupy different channels and CURRENT_NETWORK=1, PPME_FILTERFAIL_FLAG_SEL applies to PAN1. C:
 *    If PAN0 and PAN1 occupy the same channel, PPME_FILTERFAIL_FLAG_SEL is the logical 'AND' of the
 *    individual PANs' PPME_FILTERFAIL_FLAG bits.
 */
#define ZLL_SEQ_STATE_PPME_FILTERFAIL_FLAG_SEL(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_PPME_FILTERFAIL_FLAG_SEL_SHIFT)) & ZLL_SEQ_STATE_PPME_FILTERFAIL_FLAG_SEL_MASK)

#define ZLL_SEQ_STATE_RX_BYTE_COUNT_MASK         (0xFF0000U)
#define ZLL_SEQ_STATE_RX_BYTE_COUNT_SHIFT        (16U)
/*! RX_BYTE_COUNT - Realtime Received Byte Count During packet reception, this read-only register is
 *    a real-time indicator of the number of bytes that have been received. This register will read
 *    0 until SFD and PHR have been received. It will read 1 after the first byte of Frame Control
 *    Field has been received, etc.
 */
#define ZLL_SEQ_STATE_RX_BYTE_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_RX_BYTE_COUNT_SHIFT)) & ZLL_SEQ_STATE_RX_BYTE_COUNT_MASK)

#define ZLL_SEQ_STATE_CCCA_BUSY_CNT_MASK         (0x3F000000U)
#define ZLL_SEQ_STATE_CCCA_BUSY_CNT_SHIFT        (24U)
/*! CCCA_BUSY_CNT - Number of CCA Measurements resulting in Busy Channel For Sequence CCCA mode
 *    only, this register indicates the number of busy CCA attempts which occurred during the
 *    autosequence, before the channel was detected to be idle. This register can also be read in real-time
 *    (during the autosequence) to determine how many busy CCA attempts have occurred to that point.
 *    The register saturates at 63 (i.e, if there are more than 63 busy attempts, the register will
 *    continue to read 63). This register is automatically cleared to zero by hardware when the next
 *    autosequence commences. Read-only register.
 */
#define ZLL_SEQ_STATE_CCCA_BUSY_CNT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_CCCA_BUSY_CNT_SHIFT)) & ZLL_SEQ_STATE_CCCA_BUSY_CNT_MASK)
/*! @} */

/*! @name TMR_PRESCALE - TIMER PRESCALER (TMR_PRESCALE)Timer Prescaler Control Register */
/*! @{ */

#define ZLL_TMR_PRESCALE_TMR_PRESCALE_MASK       (0x7U)
#define ZLL_TMR_PRESCALE_TMR_PRESCALE_SHIFT      (0U)
/*! TMR_PRESCALE - Timer Prescaler Timer Prescaler. Establishes the Event Timer clock rate (and also
 *    maximum timer duration) Note: To take advantage of the EVENT_TMR Fractional bits for 802.15.4
 *    DSM mode, only the default setting (5, or 62.5KHz) is allowed. 0x0,Reserved, 0x1,Reserved,
 *    0x2,500kHz (33.55 S), 0x3,250kHz (67.11 S), 0x4,125kHz (134.22 S), 0x5,62.5kHz (268.44 S) --
 *    default, 0x6,31.25kHz (536.87 S), 0x7,15.625kHz (1073.74 S)
 */
#define ZLL_TMR_PRESCALE_TMR_PRESCALE(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_TMR_PRESCALE_TMR_PRESCALE_SHIFT)) & ZLL_TMR_PRESCALE_TMR_PRESCALE_MASK)
/*! @} */

/*! @name LENIENCY_LSB - LENIENCY LSB (LENIENCY_LSB)Packet Processor Leniency Bits (LSB) */
/*! @{ */

#define ZLL_LENIENCY_LSB_LENIENCY_LSB_MASK       (0xFFFFFFFFU)
#define ZLL_LENIENCY_LSB_LENIENCY_LSB_SHIFT      (0U)
/*! LENIENCY_LSB - Leniency LSB Register The Packet Processor performs filtering on all received
 *    packets, in order to determine whether the packet is intended for the device. The packet
 *    filtering is based on rules. In case any of the packet filtering rules need to be overridden, a 43-bit
 *    leniency register has been provided. When the leniency register is programmed to its default
 *    value (0), all hardware packet filtering rules are in effect, and if an incoming packet
 *    violates any rule, a Filter Fail will occur (packet will be rejected). When a given leniency
 *    register bit is asserted, the packet filtering rule assigned to that bit will not be in effect, and
 *    if any incoming packet violates that rule (but no other rules), then a Filter Fail will not
 *    occur, the packet will not be rejected, the packet will be treated as intended for the device,
 *    and software will be notified of the incoming packet. For a description of the function of the
 *    individual leniency bits, see the 802.15.4 Link Layer Controller chapter.
 */
#define ZLL_LENIENCY_LSB_LENIENCY_LSB(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_LENIENCY_LSB_LENIENCY_LSB_SHIFT)) & ZLL_LENIENCY_LSB_LENIENCY_LSB_MASK)
/*! @} */

/*! @name LENIENCY_MSB - LENIENCY MSB (LENIENCY_MSB)Packet Processor Leniency Bits (MSB) */
/*! @{ */

#define ZLL_LENIENCY_MSB_LENIENCY_MSB_MASK       (0x7FFU)
#define ZLL_LENIENCY_MSB_LENIENCY_MSB_SHIFT      (0U)
/*! LENIENCY_MSB - Leniency MSB Register The Packet Processor performs filtering on all received
 *    packets, in order to determine whether the packet is intended for the device. The packet
 *    filtering is based on rules. In case any of the packet filtering rules need to be overridden, a 43-bit
 *    leniency register has been provided. When the leniency register is programmed to its default
 *    value (0), all hardware packet filtering rules are in effect, and if an incoming packet
 *    violates any rule, a Filter Fail will occur (packet will be rejected). When a given leniency
 *    register bit is asserted, the packet filtering rule assigned to that bit will not be in effect, and
 *    if any incoming packet violates that rule (but no other rules), then a Filter Fail will not
 *    occur, the packet will not be rejected, the packet will be treated as intended for the device,
 *    and software will be notified of the incoming packet. For a description of the function of the
 *    individual leniency bits, see the 802.15.4 Link Layer Controller chapter.
 */
#define ZLL_LENIENCY_MSB_LENIENCY_MSB(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_LENIENCY_MSB_LENIENCY_MSB_SHIFT)) & ZLL_LENIENCY_MSB_LENIENCY_MSB_MASK)
/*! @} */

/*! @name PART_ID - PART ID (PART_ID) */
/*! @{ */

#define ZLL_PART_ID_PART_ID_MASK                 (0xFFU)
#define ZLL_PART_ID_PART_ID_SHIFT                (0U)
/*! PART_ID - 802.15.4 Part ID */
#define ZLL_PART_ID_PART_ID(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PART_ID_PART_ID_SHIFT)) & ZLL_PART_ID_PART_ID_MASK)
/*! @} */

/*! @name COEX_CTRL - COEXISTENCE CONTROL (COEX_CTRL)Coexistence Control Registers in Link Layer.This Register provides various control bits for Coexistence funciton. It contains the bits to enable the Coexistence funciton. Also contains Coexistence Timeout Interrupt, Coexistence Timeout Interrupt Mask bit and some other COEX bits */
/*! @{ */

#define ZLL_COEX_CTRL_COEX_EN_MASK               (0x1U)
#define ZLL_COEX_CTRL_COEX_EN_SHIFT              (0U)
/*! COEX_EN - Coexistence Enable 0x0,Coexistence function is disabled., 0x1,Coexistence function is enabled. */
#define ZLL_COEX_CTRL_COEX_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_EN_SHIFT)) & ZLL_COEX_CTRL_COEX_EN_MASK)

#define ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_MASK     (0x2U)
#define ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_SHIFT    (1U)
/*! COEX_REQ_DELAY_EN - Coexistence Request Delay Enable 0x0,arb_request is not delayed during R
 *    sequence., 0x1,arb_request is delayed until preamble is detected during R sequence.
 */
#define ZLL_COEX_CTRL_COEX_REQ_DELAY_EN(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_SHIFT)) & ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_MASK)

#define ZLL_COEX_CTRL_COEX_REQ_ON_PD_MASK        (0x4U)
#define ZLL_COEX_CTRL_COEX_REQ_ON_PD_SHIFT       (2U)
/*! COEX_REQ_ON_PD - Coexistence Request on Preamble detected 0x0,arb_request is delayed until SFD
 *    is detected during R sequence., 0x1,arb_request is delayed until preamble is detected during R
 *    sequence.
 */
#define ZLL_COEX_CTRL_COEX_REQ_ON_PD(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_REQ_ON_PD_SHIFT)) & ZLL_COEX_CTRL_COEX_REQ_ON_PD_MASK)

#define ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_MASK      (0x40U)
#define ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_SHIFT     (6U)
/*! COEX_TIMEOUT_MSK - Coexistence Timeout Interrupt Mask bit 0x0,allows interrupt when coexistence
 *    timeout, 0x1,Interrupt generation is disabled, but a COEX_TIMEOUT_IRQ flag can be set
 */
#define ZLL_COEX_CTRL_COEX_TIMEOUT_MSK(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_SHIFT)) & ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_MASK)

#define ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_MASK      (0x80U)
#define ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_SHIFT     (7U)
/*! COEX_TIMEOUT_IRQ - Coexistence Timeout Interrupt Indicates coexistence timeout occurs. This is write '1' to clear bit. */
#define ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_SHIFT)) & ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_MASK)

#define ZLL_COEX_CTRL_COEX_TIMEOUT_MASK          (0xFF00U)
#define ZLL_COEX_CTRL_COEX_TIMEOUT_SHIFT         (8U)
/*! COEX_TIMEOUT - Coexistence timeout value After arb_request asserts, arb_grant should assert
 *    before the timeout value. Otherwise the sequence is abort and COEX_TIMEOUT_IRQ bit is set. The
 *    step of the timeout value is 32us.
 */
#define ZLL_COEX_CTRL_COEX_TIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_TIMEOUT_SHIFT)) & ZLL_COEX_CTRL_COEX_TIMEOUT_MASK)
/*! @} */

/*! @name COEX_PRIORITY - COEXISTENCE PRIORITY (COEX_PRIORITY)Programmable 2-bit priority for each RX or TX state in each ZSM. */
/*! @{ */

#define ZLL_COEX_PRIORITY_PRIORITY_T_MASK        (0x3U)
#define ZLL_COEX_PRIORITY_PRIORITY_T_SHIFT       (0U)
/*! PRIORITY_T - PRIORITY_T PRIORITY value for TX Packet. */
#define ZLL_COEX_PRIORITY_PRIORITY_T(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_T_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_T_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_R_PRE_MASK    (0xCU)
#define ZLL_COEX_PRIORITY_PRIORITY_R_PRE_SHIFT   (2U)
/*! PRIORITY_R_PRE - PRIORITY_R_PRE PRIORITY value of searching Preamble for RX Packet. */
#define ZLL_COEX_PRIORITY_PRIORITY_R_PRE(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_R_PRE_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_R_PRE_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_R_PKT_MASK    (0x30U)
#define ZLL_COEX_PRIORITY_PRIORITY_R_PKT_SHIFT   (4U)
/*! PRIORITY_R_PKT - PRIORITY_R_PKT PRIORITY value for RX Packet. */
#define ZLL_COEX_PRIORITY_PRIORITY_R_PKT(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_R_PKT_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_R_PKT_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_TACK_MASK     (0xC0U)
#define ZLL_COEX_PRIORITY_PRIORITY_TACK_SHIFT    (6U)
/*! PRIORITY_TACK - PRIORITY_TACK PRIORITY value for TX ACK Packet. */
#define ZLL_COEX_PRIORITY_PRIORITY_TACK(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_TACK_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_TACK_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_CCA_MASK      (0x300U)
#define ZLL_COEX_PRIORITY_PRIORITY_CCA_SHIFT     (8U)
/*! PRIORITY_CCA - PRIORITY_CCA PRIORITY value for CCA. */
#define ZLL_COEX_PRIORITY_PRIORITY_CCA(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_CCA_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_CCA_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_CCCA_MASK     (0xC00U)
#define ZLL_COEX_PRIORITY_PRIORITY_CCCA_SHIFT    (10U)
/*! PRIORITY_CCCA - PRIORITY_CCCA PRIORITY value for Continuous CCA. */
#define ZLL_COEX_PRIORITY_PRIORITY_CCCA(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_CCCA_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_CCCA_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_CTX_MASK      (0x3000U)
#define ZLL_COEX_PRIORITY_PRIORITY_CTX_SHIFT     (12U)
/*! PRIORITY_CTX - PRIORITY_CT PRIORITY value for CCA before TX Packet. */
#define ZLL_COEX_PRIORITY_PRIORITY_CTX(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_CTX_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_CTX_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_MASK (0xC000U)
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_SHIFT (14U)
/*! PRIORITY_RACK_PRE - PRIORITY_RACK_PRE PRIORITY value during searching preamble of ACK packet. */
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_MASK (0x30000U)
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_SHIFT (16U)
/*! PRIORITY_RACK_PKT - PRIORITY_RACK_PKT PRIORITY value during receiving ACK packet. */
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_MASK     (0x60000000U)
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_SHIFT    (29U)
/*! PRIORITY_OVRD - PRIORITY_OVRD When PRIORITY_OVRD_EN is set to 1, PRIORITY_OVRD is used to override PRIORITY value. */
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_OVRD_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_OVRD_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_MASK  (0x80000000U)
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_SHIFT (31U)
/*! PRIORITY_OVRD_EN - PRIORITY_OVRD_EN Enable/Disable overriding PRIORITY value. 0x0,Disable
 *    overriding PRIORITY value., 0x1,Enable overriding PRIORITY value.
 */
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_MASK)
/*! @} */

/*! @name ENHACK_CTRL0 - ENHACK_CTRL 0 (ENHACK_CTRL0)Control Register 0 for Enhanced Acknowledgment Feature */
/*! @{ */

#define ZLL_ENHACK_CTRL0_ENHACK_EN_MASK          (0x1U)
#define ZLL_ENHACK_CTRL0_ENHACK_EN_SHIFT         (0U)
/*! ENHACK_EN - Enhanced Acknowledgment Enable 0x0,Enhanced acknowledgment is disabled., 0x1,Enhanced acknowledgment is enabled. */
#define ZLL_ENHACK_CTRL0_ENHACK_EN(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_ENHACK_EN_SHIFT)) & ZLL_ENHACK_CTRL0_ENHACK_EN_MASK)

#define ZLL_ENHACK_CTRL0_SW_LEN_RDY_MASK         (0x2U)
#define ZLL_ENHACK_CTRL0_SW_LEN_RDY_SHIFT        (1U)
/*! SW_LEN_RDY - Software enhanced acknowledgment frame Length field ready 0x0,Software enhanced
 *    acknowledgment frame Length field is not ready., 0x1,Software enhanced acknowledgment frame
 *    Length field is ready in RAM
 */
#define ZLL_ENHACK_CTRL0_SW_LEN_RDY(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_SW_LEN_RDY_SHIFT)) & ZLL_ENHACK_CTRL0_SW_LEN_RDY_MASK)

#define ZLL_ENHACK_CTRL0_SW_HIE_RDY_MASK         (0x4U)
#define ZLL_ENHACK_CTRL0_SW_HIE_RDY_SHIFT        (2U)
/*! SW_HIE_RDY - Software enhanced acknowledgment frame HIE field ready 0x0,Software enhanced
 *    acknowledgment frame HIE field is not ready., 0x1,Software enhanced acknowledgment frame HIE field
 *    is ready in RAM
 */
#define ZLL_ENHACK_CTRL0_SW_HIE_RDY(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_SW_HIE_RDY_SHIFT)) & ZLL_ENHACK_CTRL0_SW_HIE_RDY_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_MASK (0x10U)
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_SHIFT (4U)
/*! EMPTY_SECURITY_ENABLED_OVRD - Override value of Security Enabled field in Empty Enhanced Acknowledgment */
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD(x) (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_MASK (0x60U)
#define ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_SHIFT (5U)
/*! EMPTY_SRC_ADDR_MODE - Source Address Mode field in Empty Enhanced Acknowledgment */
#define ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_MASK)

#define ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_MASK      (0xFF00U)
#define ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_SHIFT     (8U)
/*! SW_MHR_LENGTH - Software calculated MHR(excludes the HIE field) Length in bytes. */
#define ZLL_ENHACK_CTRL0_SW_MHR_LENGTH(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_SHIFT)) & ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_MASK)

#define ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_MASK   (0x10000U)
#define ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_SHIFT  (16U)
/*! HW_FRAME_PENDING - Hardware calculated Frame Pending field When received a DATA or Command
 *    Frame, hardware calculates the Frame Pending field by Source Address Management. This bit can be
 *    used by software to build the Enhanced Acknowledgment frame.
 */
#define ZLL_ENHACK_CTRL0_HW_FRAME_PENDING(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_SHIFT)) & ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_MASK (0x40000U)
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_SHIFT (18U)
/*! EMPTY_SECURITY_ENABLED_OVRD_EN - Override enable of Security Enabled field in Empty Enhanced
 *    Acknowledgment 0x0,Security Enabled field in Empty Enhanced Acknowledgment frame is 0.,
 *    0x1,Security Enabled field in Empty Enhanced Acknowledgment frame is, from EMPTY_SECURITY_ENABLED_OVRD.
 */
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_MASK)

#define ZLL_ENHACK_CTRL0_ENABLE_HW_MODE7_8_MASK  (0x80000U)
#define ZLL_ENHACK_CTRL0_ENABLE_HW_MODE7_8_SHIFT (19U)
/*! ENABLE_HW_MODE7_8 - Enable AUTOACK for frame version 2 extended addressing modes 0x0,Disable
 *    autack for frame version 2 extended addressing modes, 0x1,Enable AUTOACK for frame version
 *    2extended addressing modes
 */
#define ZLL_ENHACK_CTRL0_ENABLE_HW_MODE7_8(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_ENABLE_HW_MODE7_8_SHIFT)) & ZLL_ENHACK_CTRL0_ENABLE_HW_MODE7_8_MASK)

#define ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_MASK (0x100000U)
#define ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_SHIFT (20U)
/*! FORCE_ACK_ENABLE_FOR_FV2 - Force AUTOACK for all frame version 2 packets, PAN0 0x0,Normal
 *    operation, 0x1,Force AUTOACK for all frame version2 packets
 */
#define ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2(x) (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_SHIFT)) & ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_MASK)

#define ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_PAN1_MASK (0x200000U)
#define ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_PAN1_SHIFT (21U)
/*! FORCE_ACK_ENABLE_FOR_FV2_PAN1 - Force AUTOACK for all frame version 2 packets, PAN1 0x0,Normal
 *    operation, 0x1,Force AUTOACK for all frame version2 packets
 */
#define ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_PAN1(x) (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_PAN1_SHIFT)) & ZLL_ENHACK_CTRL0_FORCE_ACK_ENABLE_FOR_FV2_PAN1_MASK)

#define ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_MASK      (0x4000000U)
#define ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_SHIFT     (26U)
/*! ACK_ABORT_MSK - Enhanced Acknowledgment Abort IRQ Mask bit 0x0,allows interrupt when HIE field
 *    is not ready by software., 0x1,Interrupt generation is disabled, but a ACK_ABORT_IRQ flag can
 *    be set
 */
#define ZLL_ENHACK_CTRL0_ACK_ABORT_MSK(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_SHIFT)) & ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_MASK)

#define ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_MASK      (0x8000000U)
#define ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_SHIFT     (27U)
/*! ACK_ABORT_IRQ - Enhanced Acknowledgment Abort IRQ This interrupt status bit indicates the HIE field is not ready by software. */
#define ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_SHIFT)) & ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_MASK      (0x10000000U)
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_SHIFT     (28U)
/*! EMPTY_ACK_MSK - Empty Enhanced Acknowledgment IRQ Mask bit 0x0,allows interrupt when Empty
 *    Enhanced Acknowledgment, 0x1,Interrupt generation is disabled, but a EMPTY_ACK_IRQ flag can be set
 */
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_MASK      (0x20000000U)
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_SHIFT     (29U)
/*! EMPTY_ACK_IRQ - Empty Enhanced Acknowledgment IRQ This interrupt status bit indicates the Empty Enhanced Acknowledgment is to be sent. */
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_MASK)

#define ZLL_ENHACK_CTRL0_RECYC_MSK_MASK          (0x40000000U)
#define ZLL_ENHACK_CTRL0_RECYC_MSK_SHIFT         (30U)
/*! RECYC_MSK - Recycle IRQ Mask bit 0x0,allows interrupt when recycle, 0x1,Interrupt generation is
 *    disabled, but a RECYC_IRQ flag can be set
 */
#define ZLL_ENHACK_CTRL0_RECYC_MSK(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_RECYC_MSK_SHIFT)) & ZLL_ENHACK_CTRL0_RECYC_MSK_MASK)

#define ZLL_ENHACK_CTRL0_RECYC_IRQ_MASK          (0x80000000U)
#define ZLL_ENHACK_CTRL0_RECYC_IRQ_SHIFT         (31U)
/*! RECYC_IRQ - Recycle IRQ This interrupt status bit indicates the hardware recycle on filter fail or CRC invalid. */
#define ZLL_ENHACK_CTRL0_RECYC_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_RECYC_IRQ_SHIFT)) & ZLL_ENHACK_CTRL0_RECYC_IRQ_MASK)
/*! @} */

/*! @name CG_OVRD - Clock Gating Override Register (CG_OVRD) */
/*! @{ */

#define ZLL_CG_OVRD_AHB_HCLK_GATED_OVRD_MASK     (0x1U)
#define ZLL_CG_OVRD_AHB_HCLK_GATED_OVRD_SHIFT    (0U)
/*! AHB_HCLK_GATED_OVRD - Zigbee AHB clock enable override (default = 0 ) If set 1'b1, the AHB hclk is always enabled */
#define ZLL_CG_OVRD_AHB_HCLK_GATED_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_CG_OVRD_AHB_HCLK_GATED_OVRD_SHIFT)) & ZLL_CG_OVRD_AHB_HCLK_GATED_OVRD_MASK)

#define ZLL_CG_OVRD_IPS_CLK_EN_OVRD_MASK         (0x2U)
#define ZLL_CG_OVRD_IPS_CLK_EN_OVRD_SHIFT        (1U)
/*! IPS_CLK_EN_OVRD - IPS clock enable override (default =0), if set 1'b1 the CFG clock of the ahb_slave is always enabled */
#define ZLL_CG_OVRD_IPS_CLK_EN_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_CG_OVRD_IPS_CLK_EN_OVRD_SHIFT)) & ZLL_CG_OVRD_IPS_CLK_EN_OVRD_MASK)

#define ZLL_CG_OVRD_SAME_CH_BOTH_SAM_LKUP_EM_MASK (0x4U)
#define ZLL_CG_OVRD_SAME_CH_BOTH_SAM_LKUP_EM_SHIFT (2U)
/*! SAME_CH_BOTH_SAM_LKUP_EM - Enable look-up for both PAN0 and PAN1 SAM table for same channel scenario */
#define ZLL_CG_OVRD_SAME_CH_BOTH_SAM_LKUP_EM(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_CG_OVRD_SAME_CH_BOTH_SAM_LKUP_EM_SHIFT)) & ZLL_CG_OVRD_SAME_CH_BOTH_SAM_LKUP_EM_MASK)

#define ZLL_CG_OVRD_ZIGREG_CKEN_FW_OV_MASK       (0x8U)
#define ZLL_CG_OVRD_ZIGREG_CKEN_FW_OV_SHIFT      (3U)
/*! ZIGREG_CKEN_FW_OV - AHB clock (hclk) enable override (default = 0 ) If set 1'b1, the AHB hclk is always enabled */
#define ZLL_CG_OVRD_ZIGREG_CKEN_FW_OV(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CG_OVRD_ZIGREG_CKEN_FW_OV_SHIFT)) & ZLL_CG_OVRD_ZIGREG_CKEN_FW_OV_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_LO_PATT_A -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_LO_PATT_A_PKT_FLTR_LO_PATT_A_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_LO_PATT_A_PKT_FLTR_LO_PATT_A_SHIFT (0U)
/*! PKT_FLTR_LO_PATT_A - PPME filter A: 32bit LSB Rx Pattern programmed by software to be matched with the subfield of the incoming Rx Packet. */
#define ZLL_PROG_PKT_FLTR_LO_PATT_A_PKT_FLTR_LO_PATT_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_LO_PATT_A_PKT_FLTR_LO_PATT_A_SHIFT)) & ZLL_PROG_PKT_FLTR_LO_PATT_A_PKT_FLTR_LO_PATT_A_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_UP_PATT_A -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_UP_PATT_A_PKT_FLTR_UP_PATT_A_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_UP_PATT_A_PKT_FLTR_UP_PATT_A_SHIFT (0U)
/*! PKT_FLTR_UP_PATT_A - PPME filter A: 32bit MSB Rx Pattern programmed by software to be matched with the subfield of the incoming Rx Packet. */
#define ZLL_PROG_PKT_FLTR_UP_PATT_A_PKT_FLTR_UP_PATT_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_UP_PATT_A_PKT_FLTR_UP_PATT_A_SHIFT)) & ZLL_PROG_PKT_FLTR_UP_PATT_A_PKT_FLTR_UP_PATT_A_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_LO_MSK_A -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_LO_MSK_A_PKT_FLTR_LO_MSK_A_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_LO_MSK_A_PKT_FLTR_LO_MSK_A_SHIFT (0U)
/*! PKT_FLTR_LO_MSK_A - PPME filter A: To mask off the bits not required to be compared between
 *    PKT_FLTR_LO_PATT_A and Rx packet buffer mask bit = 1 means "no compare" mask-bit = 0 means "do
 *    compare"
 */
#define ZLL_PROG_PKT_FLTR_LO_MSK_A_PKT_FLTR_LO_MSK_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_LO_MSK_A_PKT_FLTR_LO_MSK_A_SHIFT)) & ZLL_PROG_PKT_FLTR_LO_MSK_A_PKT_FLTR_LO_MSK_A_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_UP_MSK_A -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_UP_MSK_A_PKT_FLTR_UP_MSK_A_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_UP_MSK_A_PKT_FLTR_UP_MSK_A_SHIFT (0U)
/*! PKT_FLTR_UP_MSK_A - PPME filter A: To mask off the bits not required to be compared between
 *    PKT_FLTR_UP_PATT_A and Rx packet buffer mask bit = 1 means "no compare" mask-bit = 0 means "do
 *    compare"
 */
#define ZLL_PROG_PKT_FLTR_UP_MSK_A_PKT_FLTR_UP_MSK_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_UP_MSK_A_PKT_FLTR_UP_MSK_A_SHIFT)) & ZLL_PROG_PKT_FLTR_UP_MSK_A_PKT_FLTR_UP_MSK_A_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_CTRL_A -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_OFST_A_MASK (0xFFU)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_OFST_A_SHIFT (0U)
/*! PKT_FLTR_OFST_A - PPME_A: Offset to skip pattern match for any number of bytes between 0 to
 *    127th byte of the packet buffer for pkt_fltr_patt_a
 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_OFST_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_OFST_A_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_OFST_A_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_EN_A_MASK (0x100U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_EN_A_SHIFT (8U)
/*! PKT_FLTR_EN_A - PPME_A: Set to enable packet filter for pkt_fltr_patt_a */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_EN_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_EN_A_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_EN_A_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_REJECT_PKT_A_MASK (0x200U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_REJECT_PKT_A_SHIFT (9U)
/*! PKT_FLTR_REJECT_PKT_A - PPME_A: Enable to abort the current packet. Disable to generate
 *    FILTERFAIL_IRQ interrupt and continue reception of the current packet.
 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_REJECT_PKT_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_REJECT_PKT_A_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_REJECT_PKT_A_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_MAT_IRQ_MODE_A_MASK (0x400U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_MAT_IRQ_MODE_A_SHIFT (10U)
/*! PKT_FLTR_MAT_IRQ_MODE_A - PPME_A: Disabled (1'b0) - There will be no patt_mat_irq_a generated in
 *    real time if pkt_fltr_patt_a matches and if there is No CRC failure. At the end of the
 *    receive only RXIRQ will be generated to signify the end of the packet. Enabled (1'b1) - interrupt
 *    patt_mat_irq_a will be generated in the real time.
 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_MAT_IRQ_MODE_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_MAT_IRQ_MODE_A_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_MAT_IRQ_MODE_A_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_PAN_A_MASK (0x800U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_PAN_A_SHIFT (11U)
/*! PKT_FLTR_PAN_A - PPME_A: PAN selector 0x0 - filter set a assigned to PAN0 0x1 - filter set a assigned to PAN1 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_PAN_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_PAN_A_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_PAN_A_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PPME_FILTERFAIL_ENABLE_MASK (0x1000U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PPME_FILTERFAIL_ENABLE_SHIFT (12U)
/*! PPME_FILTERFAIL_ENABLE - If set 1'b1, PPME Filterfail_code0/1 is disabled for
 *    RECD_ON_PAN_0/1_EARLY evaluation, regardless if PPME is setup for "phase2" frame header checking for PP
 *    -unsupported frame types if reset (1'b0), PPME Fitlerfail_codes are evaluated for
 *    RECD_ON_PAN_0/1_EARLY evaluation
 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PPME_FILTERFAIL_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PPME_FILTERFAIL_ENABLE_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PPME_FILTERFAIL_ENABLE_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PPME_SECURITY_ENABLED_OVRD_MASK (0x2000U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PPME_SECURITY_ENABLED_OVRD_SHIFT (13U)
/*! PPME_SECURITY_ENABLED_OVRD - Override that the "security_enabled" packet header field when set
 *    is clearing PPME filterfail codes. If set 1'b1, ppme_fitlerfail_codes are not cleared
 *    regardless of security_enabled
 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PPME_SECURITY_ENABLED_OVRD(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PPME_SECURITY_ENABLED_OVRD_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PPME_SECURITY_ENABLED_OVRD_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_VER_A_MASK (0xF0000U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_VER_A_SHIFT (16U)
/*! PKT_FLTR_FRM_VER_A - PPME_A: Packet Filter Frame Version selector for filter set a. The incoming
 *    packet's Frame Control Field is parsed to obtain the FrameVersion subfield, and that value is
 *    compared against this register, in accordance with the following: xxx1: Accept received
 *    packets with FrameVersion=00 xx1x: Accept received packets with FrameVersion=01 x1xx: Accept
 *    received packets with FrameVersion=10 1xxx: Accept received packets with FrameVersion=11
 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_VER_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_VER_A_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_VER_A_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_TYPE_A_MASK (0xFF000000U)
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_TYPE_A_SHIFT (24U)
/*! PKT_FLTR_FRM_TYPE_A - PPME fiter A: Packet type selector for filter set a. Packet type can be
 *    parsed from Frame Control field and can be used to filter the packet types as per the settings
 *    in this register. xxxxxxx1 - Accept packets with Frame Type Beacon xxxxxx1x - Accept packets
 *    with Frame Type Data xxxxx1xx - Accept packets with Frame Type Acknowledgement xxxx1xxx - Accept
 *    packets with Frame Type MAC command. xxx1xxxx - Accept packets with Frame Type Reserved
 *    xx1xxxxx - Accept packets with Frame Type Multipurpose x1xxxxxx - Accept packets with Frame Type
 *    Fragment or Frak 1xxxxxxx - Accept packets with Frame Type Extended
 */
#define ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_TYPE_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_TYPE_A_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_A_PKT_FLTR_FRM_TYPE_A_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_LO_PATT_B -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_LO_PATT_B_PKT_FLTR_LO_PATT_B_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_LO_PATT_B_PKT_FLTR_LO_PATT_B_SHIFT (0U)
/*! PKT_FLTR_LO_PATT_B - PPME filter B: 32bit LSB Rx Pattern programmed by software to be matched with the subfield of the incoming Rx Packet. */
#define ZLL_PROG_PKT_FLTR_LO_PATT_B_PKT_FLTR_LO_PATT_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_LO_PATT_B_PKT_FLTR_LO_PATT_B_SHIFT)) & ZLL_PROG_PKT_FLTR_LO_PATT_B_PKT_FLTR_LO_PATT_B_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_UP_PATT_B -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_UP_PATT_B_PKT_FLTR_UP_PATT_B_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_UP_PATT_B_PKT_FLTR_UP_PATT_B_SHIFT (0U)
/*! PKT_FLTR_UP_PATT_B - PPME filter B: 32bit MSB Rx Pattern programmed by software to be matched with the subfield of the incoming Rx Packet. */
#define ZLL_PROG_PKT_FLTR_UP_PATT_B_PKT_FLTR_UP_PATT_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_UP_PATT_B_PKT_FLTR_UP_PATT_B_SHIFT)) & ZLL_PROG_PKT_FLTR_UP_PATT_B_PKT_FLTR_UP_PATT_B_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_LO_MSK_B -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_LO_MSK_B_PKT_FLTR_LO_MSK_B_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_LO_MSK_B_PKT_FLTR_LO_MSK_B_SHIFT (0U)
/*! PKT_FLTR_LO_MSK_B - PPME filter B: To mask off the bits not required to be compared between
 *    PKT_FLTR_LO_PATT_B and Rx packet buffer mask bit = 1 means "no compare" mask-bit = 0 means "do
 *    compare"
 */
#define ZLL_PROG_PKT_FLTR_LO_MSK_B_PKT_FLTR_LO_MSK_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_LO_MSK_B_PKT_FLTR_LO_MSK_B_SHIFT)) & ZLL_PROG_PKT_FLTR_LO_MSK_B_PKT_FLTR_LO_MSK_B_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_UP_MSK_B -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_UP_MSK_B_PKT_FLTR_UP_MSK_B_MASK (0xFFFFFFFFU)
#define ZLL_PROG_PKT_FLTR_UP_MSK_B_PKT_FLTR_UP_MSK_B_SHIFT (0U)
/*! PKT_FLTR_UP_MSK_B - PPME filter B: To mask off the bits not required to be compared between
 *    PKT_FLTR_UP_PATT_B and Rx packet buffer mask bit = 1 means "no compare" mask-bit = 0 means "do
 *    compare"
 */
#define ZLL_PROG_PKT_FLTR_UP_MSK_B_PKT_FLTR_UP_MSK_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_UP_MSK_B_PKT_FLTR_UP_MSK_B_SHIFT)) & ZLL_PROG_PKT_FLTR_UP_MSK_B_PKT_FLTR_UP_MSK_B_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_CTRL_B -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_OFST_B_MASK (0xFFU)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_OFST_B_SHIFT (0U)
/*! PKT_FLTR_OFST_B - PPME_B: Offset to skip pattern match for any number of bytes between 0 to
 *    127th byte of the packet buffer for pkt_fltr_patt_b
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_OFST_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_OFST_B_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_OFST_B_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_EN_B_MASK (0x100U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_EN_B_SHIFT (8U)
/*! PKT_FLTR_EN_B - PPME_B: Set to enable packet filter for pkt_fltr_patt_b */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_EN_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_EN_B_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_EN_B_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_PKT_B_MASK (0x200U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_PKT_B_SHIFT (9U)
/*! PKT_FLTR_REJECT_PKT_B - PPME_B: Enable to abort the current packet. Disable to generate
 *    FILTERFAIL_IRQ interrupt and continue reception of the current packet.
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_PKT_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_PKT_B_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_PKT_B_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_MAT_IRQ_MODE_B_MASK (0x400U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_MAT_IRQ_MODE_B_SHIFT (10U)
/*! PKT_FLTR_MAT_IRQ_MODE_B - PPME_B: Disabled (1'b0) - There will be no patt_mat_irq_a generated in
 *    real time if pkt_fltr_patt_b matches and if there is No CRC failure. At the end of the
 *    receive only RXIRQ will be generated to signify the end of the packet. Enabled (1'b1) - interrupt
 *    patt_mat_irq_b will be generated in the real time.
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_MAT_IRQ_MODE_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_MAT_IRQ_MODE_B_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_MAT_IRQ_MODE_B_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_PAN_B_MASK (0x800U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_PAN_B_SHIFT (11U)
/*! PKT_FLTR_PAN_B - PPME_B: PAN selector 0x0 - filter set a assigned to PAN0 0x1 - filter set a assigned to PAN1 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_PAN_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_PAN_B_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_PAN_B_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_AND_MASK (0x1000U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_AND_SHIFT (12U)
/*! PKT_FLTR_REJECT_AND - When both filter sets A and B are enabled and packet rejection bits
 *    PKT_FLTR_REJECT_PKT_A, PKT_FLTR_REJECT_PKT_B is enabled software can select to reject the Rx packet
 *    if both patterns are not matched or either pattern is not matched. 0: Rx packet rejected if
 *    pkt_fltr_patt_a OR pkt_fltr_patt_b is not matched 1: Rx packet rejected if pkt_fltr_patt_a AND
 *    pkt_fltr_patt_b is not matched
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_AND(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_AND_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_REJECT_AND_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_CONCAT_PFAB_MASK (0x2000U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_CONCAT_PFAB_SHIFT (13U)
/*! PKT_FLTR_CONCAT_PFAB - To concatenate the pkt_fltr_patt_a + pkt_fltr_patt_b and receive
 *    interrupt patt_mat_irq_b only when complete pattern has matched
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_CONCAT_PFAB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_CONCAT_PFAB_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_CONCAT_PFAB_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FLOAT_OFST_EN_MASK (0x4000U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FLOAT_OFST_EN_SHIFT (14U)
/*! PKT_FLTR_FLOAT_OFST_EN - This bit is used to decide if pattern b offset should be fixed
 *    (configurable by software) or should be kept floating (anytime the match occurs).
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FLOAT_OFST_EN(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FLOAT_OFST_EN_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FLOAT_OFST_EN_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_VER_B_MASK (0xF0000U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_VER_B_SHIFT (16U)
/*! PKT_FLTR_FRM_VER_B - PPME_B: Packet Filter Frame Version selector for filter set B. The incoming
 *    packet's Frame Control Field is parsed to obtain the FrameVersion subfield, and that value is
 *    compared against this register, in accordance with the following: xxx1: Accept received
 *    packets with FrameVersion=00 xx1x: Accept received packets with FrameVersion=01 x1xx: Accept
 *    received packets with FrameVersion=10 1xxx: Accept received packets with FrameVersion=11
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_VER_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_VER_B_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_VER_B_MASK)

#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_TYPE_B_MASK (0xFF000000U)
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_TYPE_B_SHIFT (24U)
/*! PKT_FLTR_FRM_TYPE_B - PPME filter B: Packet type selector for filter set B. Packet type can be
 *    parsed from Frame Control field and can be used to filter the packet types as per the settings
 *    in this register. xxxxxxx1 - Accept packets with Frame Type Beacon xxxxxx1x - Accept packets
 *    with Frame Type Data xxxxx1xx - Accept packets with Frame Type Acknowledgement xxxx1xxx -
 *    Accept packets with Frame Type MAC command. xxx1xxxx - Accept packets with Frame Type Reserved
 *    xx1xxxxx - Accept packets with Frame Type Multipurpose x1xxxxxx - Accept packets with Frame Type
 *    Fragment or Frak 1xxxxxxx - Accept packets with Frame Type Extended
 */
#define ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_TYPE_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_TYPE_B_SHIFT)) & ZLL_PROG_PKT_FLTR_CTRL_B_PKT_FLTR_FRM_TYPE_B_MASK)
/*! @} */

/*! @name SAM_ADDR_PRESENT - SAM ADDRESS PRESENT (SAM_ADDR_PRESENT) */
/*! @{ */

#define ZLL_SAM_ADDR_PRESENT_SAP0_ADDR_PRESENT_MASK (0x1U)
#define ZLL_SAM_ADDR_PRESENT_SAP0_ADDR_PRESENT_SHIFT (0U)
/*! SAP0_ADDR_PRESENT - A Checksum Match is Present in the SAP0 Partition of the SAM Table */
#define ZLL_SAM_ADDR_PRESENT_SAP0_ADDR_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_ADDR_PRESENT_SAP0_ADDR_PRESENT_SHIFT)) & ZLL_SAM_ADDR_PRESENT_SAP0_ADDR_PRESENT_MASK)

#define ZLL_SAM_ADDR_PRESENT_SAA0_ADDR_ABSENT_MASK (0x2U)
#define ZLL_SAM_ADDR_PRESENT_SAA0_ADDR_ABSENT_SHIFT (1U)
/*! SAA0_ADDR_ABSENT - A Checksum Match is Absent in the SAA0 Partition of the SAM Table */
#define ZLL_SAM_ADDR_PRESENT_SAA0_ADDR_ABSENT(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_ADDR_PRESENT_SAA0_ADDR_ABSENT_SHIFT)) & ZLL_SAM_ADDR_PRESENT_SAA0_ADDR_ABSENT_MASK)

#define ZLL_SAM_ADDR_PRESENT_SAP1_ADDR_PRESENT_MASK (0x4U)
#define ZLL_SAM_ADDR_PRESENT_SAP1_ADDR_PRESENT_SHIFT (2U)
/*! SAP1_ADDR_PRESENT - A Checksum Match is Present in the SAP1 Partition of the SAM Table */
#define ZLL_SAM_ADDR_PRESENT_SAP1_ADDR_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_ADDR_PRESENT_SAP1_ADDR_PRESENT_SHIFT)) & ZLL_SAM_ADDR_PRESENT_SAP1_ADDR_PRESENT_MASK)

#define ZLL_SAM_ADDR_PRESENT_SAA1_ADDR_ABSENT_MASK (0x8U)
#define ZLL_SAM_ADDR_PRESENT_SAA1_ADDR_ABSENT_SHIFT (3U)
/*! SAA1_ADDR_ABSENT - A Checksum Match is Absent in the SAA1 Partition of the SAM Table */
#define ZLL_SAM_ADDR_PRESENT_SAA1_ADDR_ABSENT(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_ADDR_PRESENT_SAA1_ADDR_ABSENT_SHIFT)) & ZLL_SAM_ADDR_PRESENT_SAA1_ADDR_ABSENT_MASK)
/*! @} */

/*! @name TIMER_CTRL - TIMER CONTROL (TIMER_CTRL) */
/*! @{ */

#define ZLL_TIMER_CTRL_EVENT_TMR_LD_MASK         (0x1U)
#define ZLL_TIMER_CTRL_EVENT_TMR_LD_SHIFT        (0U)
/*! EVENT_TMR_LD - Event Timer Load Enable Loads the Event Timer with the values written to the
 *    EVENT_TMR[23:0] and EVENT_TMR_FRAC[3:0] fields of this register.
 */
#define ZLL_TIMER_CTRL_EVENT_TMR_LD(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_TIMER_CTRL_EVENT_TMR_LD_SHIFT)) & ZLL_TIMER_CTRL_EVENT_TMR_LD_MASK)

#define ZLL_TIMER_CTRL_EVENT_TMR_ADD_MASK        (0x2U)
#define ZLL_TIMER_CTRL_EVENT_TMR_ADD_SHIFT       (1U)
/*! EVENT_TMR_ADD - Event Timer Add Enable Increments the Event Timer by the values written to the
 *    EVENT_TMR[23:0] and EVENT_TMR_FRAC[3:0] fields of this register.
 */
#define ZLL_TIMER_CTRL_EVENT_TMR_ADD(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_TIMER_CTRL_EVENT_TMR_ADD_SHIFT)) & ZLL_TIMER_CTRL_EVENT_TMR_ADD_MASK)

#define ZLL_TIMER_CTRL_EVNTMR_WKUP_TRIG_EN_MASK  (0x10U)
#define ZLL_TIMER_CTRL_EVNTMR_WKUP_TRIG_EN_SHIFT (4U)
/*! EVNTMR_WKUP_TRIG_EN - Configuration to trigger T[1-4]CMP comparison after a wakeup is detected.
 *    This bit is used only for the first TX or RX event after wakeup, and is self-cleared by HW.
 */
#define ZLL_TIMER_CTRL_EVNTMR_WKUP_TRIG_EN(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_TIMER_CTRL_EVNTMR_WKUP_TRIG_EN_SHIFT)) & ZLL_TIMER_CTRL_EVNTMR_WKUP_TRIG_EN_MASK)

#define ZLL_TIMER_CTRL_CAPTURE_TIMESTAMP_MASK    (0x20U)
#define ZLL_TIMER_CTRL_CAPTURE_TIMESTAMP_SHIFT   (5U)
/*! CAPTURE_TIMESTAMP - SW can write this bit to capture a snapshot of FP4_UNIVERSAL_CLOCK and Event
 *    Timer in UC_TIMESTAMP and TIMESTAMP registers. This bit is self-cleared by HW
 */
#define ZLL_TIMER_CTRL_CAPTURE_TIMESTAMP(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_TIMER_CTRL_CAPTURE_TIMESTAMP_SHIFT)) & ZLL_TIMER_CTRL_CAPTURE_TIMESTAMP_MASK)

#define ZLL_TIMER_CTRL_TMSTMP_ANCHORED_MASK      (0x40U)
#define ZLL_TIMER_CTRL_TMSTMP_ANCHORED_SHIFT     (6U)
/*! TMSTMP_ANCHORED - When set, CAPTURE_TIMESTAMP will capture an anchored TIMESTAMP of universal
 *    clock counter and event timer. This bit does not affect the timestamping at RX SFD detection
 */
#define ZLL_TIMER_CTRL_TMSTMP_ANCHORED(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_TIMER_CTRL_TMSTMP_ANCHORED_SHIFT)) & ZLL_TIMER_CTRL_TMSTMP_ANCHORED_MASK)

#define ZLL_TIMER_CTRL_RST_EVNTMR_AT_WKUP_MASK   (0x80U)
#define ZLL_TIMER_CTRL_RST_EVNTMR_AT_WKUP_SHIFT  (7U)
/*! RST_EVNTMR_AT_WKUP - Bit to enable Event Timer reset at wakeup */
#define ZLL_TIMER_CTRL_RST_EVNTMR_AT_WKUP(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_TIMER_CTRL_RST_EVNTMR_AT_WKUP_SHIFT)) & ZLL_TIMER_CTRL_RST_EVNTMR_AT_WKUP_MASK)
/*! @} */

/*! @name UNIV_CNTR_TIMESTAMP - Universal Counter Timestamp (UNIV_CNTR_TIMESTAMP) */
/*! @{ */

#define ZLL_UNIV_CNTR_TIMESTAMP_UNIV_CNTR_TIMESTAMP_MASK (0xFFFFFFFFU)
#define ZLL_UNIV_CNTR_TIMESTAMP_UNIV_CNTR_TIMESTAMP_SHIFT (0U)
/*! UNIV_CNTR_TIMESTAMP - Timestamped value captured from FP4_UNIVERSAL_CLOCK counter at
 *    CAPTURE_TIMESTAMP assertion from SW. This TIMESTAMP is also updated at SFD detection when Event Timer
 *    TIMESTAMP is updated in ZLL TIMESTAMP register
 */
#define ZLL_UNIV_CNTR_TIMESTAMP_UNIV_CNTR_TIMESTAMP(x) (((uint32_t)(((uint32_t)(x)) << ZLL_UNIV_CNTR_TIMESTAMP_UNIV_CNTR_TIMESTAMP_SHIFT)) & ZLL_UNIV_CNTR_TIMESTAMP_UNIV_CNTR_TIMESTAMP_MASK)
/*! @} */

/*! @name UNIV_CLK_CNTR - Universal Clock Counter Freerunning value (UNIV_CLK_CNTR) */
/*! @{ */

#define ZLL_UNIV_CLK_CNTR_FP4_UNIVERSAL_CLOCK_MASK (0xFFFFFFFFU)
#define ZLL_UNIV_CLK_CNTR_FP4_UNIVERSAL_CLOCK_SHIFT (0U)
/*! FP4_UNIVERSAL_CLOCK - FP4_UNIVERSAL_CLOCK counter (live value) readback from d_ip_15p4_radio_syn block */
#define ZLL_UNIV_CLK_CNTR_FP4_UNIVERSAL_CLOCK(x) (((uint32_t)(((uint32_t)(x)) << ZLL_UNIV_CLK_CNTR_FP4_UNIVERSAL_CLOCK_SHIFT)) & ZLL_UNIV_CLK_CNTR_FP4_UNIVERSAL_CLOCK_MASK)
/*! @} */

/*! @name EVENT_TMR_PRESET - EVENT TIMER Preset value (EVENT_TMR_PRESET) */
/*! @{ */

#define ZLL_EVENT_TMR_PRESET_EVENT_TMR_PRESET_MASK (0xFFFFFFFFU)
#define ZLL_EVENT_TMR_PRESET_EVENT_TMR_PRESET_SHIFT (0U)
/*! EVENT_TMR_PRESET - for SW to provide the pre-set value to load into, or, add to, the Event Timer
 *    when EVENT_TMR_LD or EVENT_TMR_ADD bits in FFU_DSM_CTRL register are set
 */
#define ZLL_EVENT_TMR_PRESET_EVENT_TMR_PRESET(x) (((uint32_t)(((uint32_t)(x)) << ZLL_EVENT_TMR_PRESET_EVENT_TMR_PRESET_SHIFT)) & ZLL_EVENT_TMR_PRESET_EVENT_TMR_PRESET_MASK)
/*! @} */

/*! @name PROG_PKT_FLTR_INTR_MSK_STS -  */
/*! @{ */

#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_A_MASK (0x1U)
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_A_SHIFT (0U)
/*! PKT_FLTR_IRQ_MASK_A - PPME_A: if 1'b1: disable PKT_FLTR_IRQ_A to trigger FW IRQ (irq_b, ipi_int_modem_rx) */
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_A_SHIFT)) & ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_A_MASK)

#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_A_MASK (0x2U)
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_A_SHIFT (1U)
/*! PKT_FLTR_IRQ_A - PPME_A: Pattern match interrupt on PPME_A, generated if a pattern match was found in PPME_A, write 1 to clear */
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_A_SHIFT)) & ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_A_MASK)

#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_B_MASK (0x4U)
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_B_SHIFT (2U)
/*! PKT_FLTR_IRQ_MASK_B - PPME_B: if 1'b1: disable PKT_FLTR_IRQ_B to trigger FW IRQ (irq_b, ipi_int_modem_rx) */
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_B_SHIFT)) & ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_MASK_B_MASK)

#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_B_MASK (0x8U)
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_B_SHIFT (3U)
/*! PKT_FLTR_IRQ_B - PPME_B: Pattern match interrupt on PPME_B, generated if a pattern match was found in PPME_B, write 1 to clear */
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_B_SHIFT)) & ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_IRQ_B_MASK)

#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_A_MASK (0x10U)
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_A_SHIFT (4U)
/*! PKT_FLTR_OFST_ERR_A - PPME_A: Pattern offset error status. Generated at packet start if
 *    PKT_FLTR_OFST_A (+ASH index) exceeds the packet length, write 1 to clear
 */
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_A(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_A_SHIFT)) & ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_A_MASK)

#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_B_MASK (0x20U)
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_B_SHIFT (5U)
/*! PKT_FLTR_OFST_ERR_B - PPME_B: Pattern offset error status. Generated at packet start if
 *    PKT_FLTR_OFST_B (+ASH index) exceeds the packet length, write 1 to clear
 */
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_B(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_B_SHIFT)) & ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_OFST_ERR_B_MASK)

#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_PAN_CFG_ERR_MASK (0x40U)
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_PAN_CFG_ERR_SHIFT (6U)
/*! PKT_FLTR_PAN_CFG_ERR - PPME PAN configuration error in concatenation mode Set when the assigned PAN of PPME-A is not equal to the PAN of PPME-B */
#define ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_PAN_CFG_ERR(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_PAN_CFG_ERR_SHIFT)) & ZLL_PROG_PKT_FLTR_INTR_MSK_STS_PKT_FLTR_PAN_CFG_ERR_MASK)
/*! @} */

/*! @name INTR_SUMMARY -  */
/*! @{ */

#define ZLL_INTR_SUMMARY_IRQSTS_IRQ_MASK         (0x1U)
#define ZLL_INTR_SUMMARY_IRQSTS_IRQ_SHIFT        (0U)
/*! IRQSTS_irq - IRQSTS_IRQ = (SEQIRQ | TXIRQ | RXIRQ | CCAIRQ | RXWTRMKIRQ | FILTERFAIL_IRQ |
 *    PLL_INLOCK_IRQ | WAKE_IRQ | ARB_GRANT_DEASSERTION_IRQ | TSM_IRQ | (| TMR_IRQ_STATUS_TMR_IRQ (4:1) )
 */
#define ZLL_INTR_SUMMARY_IRQSTS_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_INTR_SUMMARY_IRQSTS_IRQ_SHIFT)) & ZLL_INTR_SUMMARY_IRQSTS_IRQ_MASK)

#define ZLL_INTR_SUMMARY_ENHACK_CTRL0_IRQ_MASK   (0x2U)
#define ZLL_INTR_SUMMARY_ENHACK_CTRL0_IRQ_SHIFT  (1U)
/*! ENHACK_CTRL0_IRQ - ENHACK_CTRL_IRQ = ( RECY_IRQ OR EMPTY_ACK_IRQ | ACK_ABORT_IRQ) */
#define ZLL_INTR_SUMMARY_ENHACK_CTRL0_IRQ(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_INTR_SUMMARY_ENHACK_CTRL0_IRQ_SHIFT)) & ZLL_INTR_SUMMARY_ENHACK_CTRL0_IRQ_MASK)

#define ZLL_INTR_SUMMARY_COEX_CTRL_IRQ_MASK      (0x4U)
#define ZLL_INTR_SUMMARY_COEX_CTRL_IRQ_SHIFT     (2U)
/*! COEX_CTRL_IRQ - COEX_TIMEOUT_IRQ */
#define ZLL_INTR_SUMMARY_COEX_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_INTR_SUMMARY_COEX_CTRL_IRQ_SHIFT)) & ZLL_INTR_SUMMARY_COEX_CTRL_IRQ_MASK)

#define ZLL_INTR_SUMMARY_XCVR_STATUS_IRQ_MASK    (0x8U)
#define ZLL_INTR_SUMMARY_XCVR_STATUS_IRQ_SHIFT   (3U)
/*! XCVR_STATUS_IRQ - TSM_IRQ */
#define ZLL_INTR_SUMMARY_XCVR_STATUS_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_INTR_SUMMARY_XCVR_STATUS_IRQ_SHIFT)) & ZLL_INTR_SUMMARY_XCVR_STATUS_IRQ_MASK)

#define ZLL_INTR_SUMMARY_PROG_PKT_FLTR_INTR_MSK_STS_IRQ_MASK (0x10U)
#define ZLL_INTR_SUMMARY_PROG_PKT_FLTR_INTR_MSK_STS_IRQ_SHIFT (4U)
/*! PROG_PKT_FLTR_INTR_MSK_STS_IRQ - PPME IRQ status summary (PKT_FLTR_OFST_ERR_B | PKT_FLTR_OFST_ERR_A | PKT_FLTR_OFST_ERR_B | PKT_FLTR_OFST_ERR_A) */
#define ZLL_INTR_SUMMARY_PROG_PKT_FLTR_INTR_MSK_STS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << ZLL_INTR_SUMMARY_PROG_PKT_FLTR_INTR_MSK_STS_IRQ_SHIFT)) & ZLL_INTR_SUMMARY_PROG_PKT_FLTR_INTR_MSK_STS_IRQ_MASK)
/*! @} */

/*! @name SAM_FREE_IDX_FND - SAM FREE INDEX FOUND (SAM_FREE_IDX_FND) */
/*! @{ */

#define ZLL_SAM_FREE_IDX_FND_SAP0_1ST_FREE_IDX_FOUND_MASK (0x1U)
#define ZLL_SAM_FREE_IDX_FND_SAP0_1ST_FREE_IDX_FOUND_SHIFT (0U)
/*! SAP0_1ST_FREE_IDX_FOUND - Source Address Present #0 First Free Index found */
#define ZLL_SAM_FREE_IDX_FND_SAP0_1ST_FREE_IDX_FOUND(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_FND_SAP0_1ST_FREE_IDX_FOUND_SHIFT)) & ZLL_SAM_FREE_IDX_FND_SAP0_1ST_FREE_IDX_FOUND_MASK)

#define ZLL_SAM_FREE_IDX_FND_SAA0_1ST_FREE_IDX_FOUND_MASK (0x2U)
#define ZLL_SAM_FREE_IDX_FND_SAA0_1ST_FREE_IDX_FOUND_SHIFT (1U)
/*! SAA0_1ST_FREE_IDX_FOUND - Source Address Absent #0 First Free Index found */
#define ZLL_SAM_FREE_IDX_FND_SAA0_1ST_FREE_IDX_FOUND(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_FND_SAA0_1ST_FREE_IDX_FOUND_SHIFT)) & ZLL_SAM_FREE_IDX_FND_SAA0_1ST_FREE_IDX_FOUND_MASK)

#define ZLL_SAM_FREE_IDX_FND_SAP1_1ST_FREE_IDX_FOUND_MASK (0x4U)
#define ZLL_SAM_FREE_IDX_FND_SAP1_1ST_FREE_IDX_FOUND_SHIFT (2U)
/*! sap1_1st_free_idx_found - Source Address Present #1 First Free Index found */
#define ZLL_SAM_FREE_IDX_FND_SAP1_1ST_FREE_IDX_FOUND(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_FND_SAP1_1ST_FREE_IDX_FOUND_SHIFT)) & ZLL_SAM_FREE_IDX_FND_SAP1_1ST_FREE_IDX_FOUND_MASK)

#define ZLL_SAM_FREE_IDX_FND_SAA1_1ST_FREE_IDX_FOUND_MASK (0x8U)
#define ZLL_SAM_FREE_IDX_FND_SAA1_1ST_FREE_IDX_FOUND_SHIFT (3U)
/*! SAA1_1ST_FREE_IDX_FOUND - Source Address Absent #1 First Free Index found */
#define ZLL_SAM_FREE_IDX_FND_SAA1_1ST_FREE_IDX_FOUND(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_FND_SAA1_1ST_FREE_IDX_FOUND_SHIFT)) & ZLL_SAM_FREE_IDX_FND_SAA1_1ST_FREE_IDX_FOUND_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ZLL_Register_Masks */


/*!
 * @}
 */ /* end of group ZLL_Peripheral_Access_Layer */


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


#endif  /* PERI_ZLL_H_ */

