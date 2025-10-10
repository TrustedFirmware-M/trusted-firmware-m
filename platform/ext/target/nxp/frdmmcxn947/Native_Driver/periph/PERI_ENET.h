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
**         CMSIS Peripheral Access Layer for ENET
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
 * @file PERI_ENET.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ENET
 *
 * CMSIS Peripheral Access Layer for ENET
 */

#if !defined(PERI_ENET_H_)
#define PERI_ENET_H_                             /**< Symbol preventing repeated inclusion */

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
   -- ENET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_Peripheral_Access_Layer ENET Peripheral Access Layer
 * @{
 */

/** ENET - Size of Registers Arrays */
#define ENET_MAC_TX_FLOW_CTRL_Q_COUNT             1u
#define ENET_MAC_RXQ_CTRL_COUNT                   3u
#define ENET_MAC_HW_FEAT_COUNT                    4u
#define ENET_MTL_QUEUE_COUNT                      2u
#define ENET_DMA_CH_COUNT                         2u

/** ENET - Register Layout Typedef */
typedef struct {
  __IO uint32_t MAC_CONFIGURATION;                 /**< MAC Configuration, offset: 0x0 */
  __IO uint32_t MAC_EXT_CONFIGURATION;             /**< MAC Extended Configuration Register, offset: 0x4 */
  __IO uint32_t MAC_PACKET_FILTER;                 /**< MAC Packet Filter, offset: 0x8 */
  __IO uint32_t MAC_WATCHDOG_TIMEOUT;              /**< Watchdog Timeout, offset: 0xC */
       uint8_t RESERVED_0[64];
  __IO uint32_t MAC_VLAN_TAG_CTRL;                 /**< MAC VLAN Tag Control, offset: 0x50 */
       uint8_t RESERVED_1[12];
  __IO uint32_t MAC_VLAN_INCL;                     /**< VLAN Tag Inclusion or Replacement, offset: 0x60 */
  __IO uint32_t MAC_INNER_VLAN_INCL;               /**< MAC Inner VLAN Tag Inclusion or Replacement, offset: 0x64 */
       uint8_t RESERVED_2[8];
  __IO uint32_t MAC_TX_FLOW_CTRL_Q[ENET_MAC_TX_FLOW_CTRL_Q_COUNT]; /**< MAC Q0 Tx Flow Control, array offset: 0x70, array step: 0x4 */
       uint8_t RESERVED_3[28];
  __IO uint32_t MAC_RX_FLOW_CTRL;                  /**< MAC Rx Flow Control, offset: 0x90 */
  __IO uint32_t MAC_RXQ_CTRL4;                     /**< Receive Queue Control 4, offset: 0x94 */
       uint8_t RESERVED_4[8];
  __IO uint32_t MAC_RXQ_CTRL[ENET_MAC_RXQ_CTRL_COUNT]; /**< Receive Queue Control 0..Receive Queue Control 2, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_5[4];
  __I  uint32_t MAC_INTERRUPT_STATUS;              /**< Interrupt Status, offset: 0xB0 */
  __IO uint32_t MAC_INTERRUPT_ENABLE;              /**< Interrupt Enable, offset: 0xB4 */
  __I  uint32_t MAC_RX_TX_STATUS;                  /**< Receive Transmit Status, offset: 0xB8 */
       uint8_t RESERVED_6[4];
  __IO uint32_t MAC_PMT_CONTROL_STATUS;            /**< PMT Control and Status, offset: 0xC0 */
  __IO uint32_t MAC_RWK_PACKET_FILTER;             /**< Remote Wakeup Filter, offset: 0xC4 */
       uint8_t RESERVED_7[8];
  __IO uint32_t MAC_LPI_CONTROL_STATUS;            /**< LPI Control and Status, offset: 0xD0 */
  __IO uint32_t MAC_LPI_TIMERS_CONTROL;            /**< LPI Timers Control, offset: 0xD4 */
  __IO uint32_t MAC_LPI_ENTRY_TIMER;               /**< Tx LPI Entry Timer Control, offset: 0xD8 */
  __IO uint32_t MAC_ONEUS_TIC_COUNTER;             /**< One-microsecond Reference Timer, offset: 0xDC */
       uint8_t RESERVED_8[48];
  __I  uint32_t MAC_VERSION;                       /**< MAC Version, offset: 0x110 */
  __I  uint32_t MAC_DEBUG;                         /**< MAC Debug, offset: 0x114 */
       uint8_t RESERVED_9[4];
  __I  uint32_t MAC_HW_FEAT[ENET_MAC_HW_FEAT_COUNT]; /**< Hardware Features 0..Hardware Features 3, array offset: 0x11C, array step: 0x4 */
       uint8_t RESERVED_10[212];
  __IO uint32_t MAC_MDIO_ADDRESS;                  /**< MDIO Address, offset: 0x200 */
  __IO uint32_t MAC_MDIO_DATA;                     /**< MAC MDIO Data, offset: 0x204 */
       uint8_t RESERVED_11[40];
  __IO uint32_t MAC_CSR_SW_CTRL;                   /**< CSR Software Control, offset: 0x230 */
       uint8_t RESERVED_12[204];
  __IO uint32_t MAC_ADDRESS0_HIGH;                 /**< MAC Address0 High, offset: 0x300 */
  __IO uint32_t MAC_ADDRESS0_LOW;                  /**< MAC Address0 Low, offset: 0x304 */
       uint8_t RESERVED_13[1896];
  __IO uint32_t INDIR_ACCESS_CTRL;                 /**< Indirect Access Control, offset: 0xA70 */
  __IO uint32_t INDIR_ACCESS_DATA;                 /**< Indirect Access Data, offset: 0xA74 */
       uint8_t RESERVED_14[136];
  __IO uint32_t MAC_TIMESTAMP_CONTROL;             /**< Timestamp Control, offset: 0xB00 */
  __IO uint32_t MAC_SUB_SECOND_INCREMENT;          /**< Subsecond Increment, offset: 0xB04 */
  __I  uint32_t MAC_SYSTEM_TIME_SECONDS;           /**< System Time Seconds, offset: 0xB08 */
  __I  uint32_t MAC_SYSTEM_TIME_NANOSECONDS;       /**< System Time Nanoseconds, offset: 0xB0C */
  __IO uint32_t MAC_SYSTEM_TIME_SECONDS_UPDATE;    /**< System Time Seconds Update, offset: 0xB10 */
  __IO uint32_t MAC_SYSTEM_TIME_NANOSECONDS_UPDATE; /**< System Time Nanoseconds Update, offset: 0xB14 */
  __IO uint32_t MAC_TIMESTAMP_ADDEND;              /**< Timestamp Addend, offset: 0xB18 */
       uint8_t RESERVED_15[4];
  __I  uint32_t MAC_TIMESTAMP_STATUS;              /**< Timestamp Status, offset: 0xB20 */
       uint8_t RESERVED_16[12];
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_NANOSECONDS; /**< Transmit Timestamp Status Nanoseconds, offset: 0xB30 */
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_SECONDS;   /**< Transmit Timestamp Status Seconds, offset: 0xB34 */
       uint8_t RESERVED_17[32];
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND; /**< Timestamp Ingress Correction Nanosecond, offset: 0xB58 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND; /**< Timestamp Egress Correction Nanosecond, offset: 0xB5C */
       uint8_t RESERVED_18[8];
  __I  uint32_t MAC_TIMESTAMP_INGRESS_LATENCY;     /**< Timestamp Ingress Latency, offset: 0xB68 */
  __I  uint32_t MAC_TIMESTAMP_EGRESS_LATENCY;      /**< Timestamp Egress Latency, offset: 0xB6C */
  __IO uint32_t MAC_PPS_CONTROL;                   /**< PPS Control, offset: 0xB70 */
       uint8_t RESERVED_19[12];
  __IO uint32_t PPS0_TARGET_TIME_SECONDS;          /**< PPS0 Target Time Seconds, offset: 0xB80 */
  __IO uint32_t PPS0_TARGET_TIME_NANOSECONDS;      /**< PPS0 Target Time Nanoseconds, offset: 0xB84 */
       uint8_t RESERVED_20[120];
  __IO uint32_t MTL_OPERATION_MODE;                /**< MTL Operation Mode, offset: 0xC00 */
       uint8_t RESERVED_21[28];
  __I  uint32_t MTL_INTERRUPT_STATUS;              /**< MTL Interrupt Status, offset: 0xC20 */
       uint8_t RESERVED_22[12];
  __IO uint32_t MTL_RXQ_DMA_MAP0;                  /**< Receive Queue and DMA Channel Mapping 0, offset: 0xC30 */
       uint8_t RESERVED_23[204];
  struct {                                         /* offset: 0xD00, array step: 0x40 */
    __IO uint32_t MTL_TXQX_OP_MODE;                  /**< Queue 0 Transmit Operation Mode..Queue 1 Transmit Operation Mode, array offset: 0xD00, array step: 0x40 */
    __I  uint32_t MTL_TXQX_UNDRFLW;                  /**< Queue 0 Underflow Counter..Queue 1 Underflow Counter, array offset: 0xD04, array step: 0x40 */
    __I  uint32_t MTL_TXQX_DBG;                      /**< Queue 0 Transmit Debug..Queue 1 Transmit Debug, array offset: 0xD08, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t MTL_TXQX_ETS_CTRL;                 /**< Queue 1 ETS Control, array offset: 0xD10, array step: 0x40, valid indices: [1] */
    __I  uint32_t MTL_TXQX_ETS_STAT;                 /**< Queue 0 ETS Status..Queue 1 ETS Status, array offset: 0xD14, array step: 0x40 */
    __IO uint32_t MTL_TXQX_QNTM_WGHT;                /**< Queue 0 Quantum or Weights..Queue 1 idleSlopeCredit, Quantum or Weights, array offset: 0xD18, array step: 0x40 */
    __IO uint32_t MTL_TXQX_SNDSLP_CRDT;              /**< Queue 1 sendSlopeCredit, array offset: 0xD1C, array step: 0x40, valid indices: [1] */
    __IO uint32_t MTL_TXQX_HI_CRDT;                  /**< Queue 1 hiCredit, array offset: 0xD20, array step: 0x40, valid indices: [1] */
    __IO uint32_t MTL_TXQX_LO_CRDT;                  /**< Queue 1 loCredit, array offset: 0xD24, array step: 0x40, valid indices: [1] */
         uint8_t RESERVED_1[4];
    __IO uint32_t MTL_QX_INTCTRL_STAT;               /**< Queue 0 Interrupt Control Status..Queue 1 Interrupt Control Status, array offset: 0xD2C, array step: 0x40 */
    __IO uint32_t MTL_RXQX_OP_MODE;                  /**< Queue 0 Receive Operation Mode..Queue 1 Receive Operation Mode, array offset: 0xD30, array step: 0x40 */
    __I  uint32_t MTL_RXQX_MISSPKT_OVRFLW_CNT;       /**< Queue 0 Missed Packet and Overflow Counter..Queue 1 Missed Packet and Overflow Counter, array offset: 0xD34, array step: 0x40 */
    __I  uint32_t MTL_RXQX_DBG;                      /**< Queue 0 Receive Debug..Queue 1 Receive Debug, array offset: 0xD38, array step: 0x40 */
    __IO uint32_t MTL_RXQX_CTRL;                     /**< Queue 0 Receive Control..Queue 1 Receive Control, array offset: 0xD3C, array step: 0x40 */
  } MTL_QUEUE[ENET_MTL_QUEUE_COUNT];
       uint8_t RESERVED_24[640];
  __IO uint32_t DMA_MODE;                          /**< DMA Bus Mode, offset: 0x1000 */
  __IO uint32_t DMA_SYSBUS_MODE;                   /**< DMA System Bus Mode, offset: 0x1004 */
  __I  uint32_t DMA_INTERRUPT_STATUS;              /**< DMA Interrupt Status, offset: 0x1008 */
  __I  uint32_t DMA_DEBUG_STATUS0;                 /**< DMA Debug Status 0, offset: 0x100C */
       uint8_t RESERVED_25[240];
  struct {                                         /* offset: 0x1100, array step: 0x80 */
    __IO uint32_t DMA_CHX_CTRL;                      /**< DMA Channel 0 Control..DMA Channel 1 Control, array offset: 0x1100, array step: 0x80 */
    __IO uint32_t DMA_CHX_TX_CTRL;                   /**< DMA Channel 0 Transmit Control..DMA Channel 1 Transmit Control, array offset: 0x1104, array step: 0x80 */
    __IO uint32_t DMA_CHX_RX_CTRL;                   /**< DMA Channel 0 Receive Control..DMA Channel 1 Receive Control, array offset: 0x1108, array step: 0x80 */
         uint8_t RESERVED_0[8];
    __IO uint32_t DMA_CHX_TXDESC_LIST_ADDR;          /**< Channel 0 Tx Descriptor List Address register..Channel 1 Tx Descriptor List Address, array offset: 0x1114, array step: 0x80 */
         uint8_t RESERVED_1[4];
    __IO uint32_t DMA_CHX_RXDESC_LIST_ADDR;          /**< Channel 0 Rx Descriptor List Address register..Channel 1 Rx Descriptor List Address, array offset: 0x111C, array step: 0x80 */
    __IO uint32_t DMA_CHX_TXDESC_TAIL_PTR;           /**< Channel 0 Tx Descriptor Tail Pointer..Channel 1 Tx Descriptor Tail Pointer, array offset: 0x1120, array step: 0x80 */
         uint8_t RESERVED_2[4];
    __IO uint32_t DMA_CHX_RXDESC_TAIL_PTR;           /**< Channel 0 Rx Descriptor Tail Pointer..Channel 1 Rx Descriptor Tail Pointer, array offset: 0x1128, array step: 0x80 */
    __IO uint32_t DMA_CHX_TXDESC_RING_LENGTH;        /**< Channel 0 Tx Descriptor Ring Length..Channel 1 Tx Descriptor Ring Length, array offset: 0x112C, array step: 0x80 */
    __IO uint32_t DMA_CHX_RX_CONTROL2;               /**< Channeli Receive Control..DMA Channel 1 Receive Control, array offset: 0x1130, array step: 0x80 */
    __IO uint32_t DMA_CHX_INT_EN;                    /**< Channeli Interrupt Enable..Channel 1 Interrupt Enable, array offset: 0x1134, array step: 0x80 */
    __IO uint32_t DMA_CHX_RX_INT_WDTIMER;            /**< Channel 0 Receive Interrupt Watchdog Timer..Channel 1 Receive Interrupt Watchdog Timer, array offset: 0x1138, array step: 0x80 */
    __IO uint32_t DMA_CHX_SLOT_FUNC_CTRL_STAT;       /**< Channel 0 Slot Function Control and Status..Channel 1 Slot Function Control and Status, array offset: 0x113C, array step: 0x80 */
         uint8_t RESERVED_3[4];
    __I  uint32_t DMA_CHX_CUR_HST_TXDESC;            /**< Channel 0 Current Application Transmit Descriptor..Channel 1 Current Application Transmit Descriptor, array offset: 0x1144, array step: 0x80 */
         uint8_t RESERVED_4[4];
    __I  uint32_t DMA_CHX_CUR_HST_RXDESC;            /**< Channel 0 Current Application Receive Descriptor..Channel 1 Current Application Receive Descriptor, array offset: 0x114C, array step: 0x80 */
         uint8_t RESERVED_5[4];
    __I  uint32_t DMA_CHX_CUR_HST_TXBUF;             /**< Channel 0 Current Application Transmit Buffer Address..Channel 1 Current Application Transmit Buffer Address, array offset: 0x1154, array step: 0x80 */
         uint8_t RESERVED_6[4];
    __I  uint32_t DMA_CHX_CUR_HST_RXBUF;             /**< Channel 0 Current Application Receive Buffer Address..Channel 1 Current Application Receive Buffer Address, array offset: 0x115C, array step: 0x80 */
    __IO uint32_t DMA_CHX_STAT;                      /**< DMA Channel 0 Status..DMA Channel 1 Status, array offset: 0x1160, array step: 0x80 */
    __I  uint32_t DMA_CHX_MISS_FRAME_CNT;            /**< Channel 0 Missed Frame Counter..Channel 1 Missed Frame Counter, array offset: 0x1164, array step: 0x80 */
         uint8_t RESERVED_7[4];
    __I  uint32_t DMA_CHX_RX_ERI_CNT;                /**< Channel 0 Receive ERI Counter..Channel 1 Receive ERI Counter, array offset: 0x116C, array step: 0x80 */
         uint8_t RESERVED_8[16];
  } DMA_CH[ENET_DMA_CH_COUNT];
} ENET_Type;

/* ----------------------------------------------------------------------------
   -- ENET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_Register_Masks ENET Register Masks
 * @{
 */

/*! @name MAC_CONFIGURATION - MAC Configuration */
/*! @{ */

#define ENET_MAC_CONFIGURATION_RE_MASK           (0x1U)
#define ENET_MAC_CONFIGURATION_RE_SHIFT          (0U)
/*! RE - Receiver Enable
 *  0b0..Receiver is disabled
 *  0b1..Receiver is enabled
 */
#define ENET_MAC_CONFIGURATION_RE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_RE_SHIFT)) & ENET_MAC_CONFIGURATION_RE_MASK)

#define ENET_MAC_CONFIGURATION_TE_MASK           (0x2U)
#define ENET_MAC_CONFIGURATION_TE_SHIFT          (1U)
/*! TE - Transmitter Enable
 *  0b0..Transmitter is disabled
 *  0b1..Transmitter is enabled
 */
#define ENET_MAC_CONFIGURATION_TE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_TE_SHIFT)) & ENET_MAC_CONFIGURATION_TE_MASK)

#define ENET_MAC_CONFIGURATION_PRELEN_MASK       (0xCU)
#define ENET_MAC_CONFIGURATION_PRELEN_SHIFT      (2U)
/*! PRELEN - Preamble Length for Transmit packets
 *  0b00..7 bytes of preamble
 *  0b01..5 bytes of preamble
 *  0b10..3 bytes of preamble
 *  0b11..Reserved
 */
#define ENET_MAC_CONFIGURATION_PRELEN(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_PRELEN_SHIFT)) & ENET_MAC_CONFIGURATION_PRELEN_MASK)

#define ENET_MAC_CONFIGURATION_DC_MASK           (0x10U)
#define ENET_MAC_CONFIGURATION_DC_SHIFT          (4U)
/*! DC - Deferral Check
 *  0b0..Deferral check function is disabled
 *  0b1..Deferral check function is enabled
 */
#define ENET_MAC_CONFIGURATION_DC(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_DC_SHIFT)) & ENET_MAC_CONFIGURATION_DC_MASK)

#define ENET_MAC_CONFIGURATION_BL_MASK           (0x60U)
#define ENET_MAC_CONFIGURATION_BL_SHIFT          (5U)
/*! BL - Back-Off Limit
 *  0b00..k = min(n,10)
 *  0b01..k = min(n,8)
 *  0b10..k = min(n,4)
 *  0b11..k = min(n,1)
 */
#define ENET_MAC_CONFIGURATION_BL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_BL_SHIFT)) & ENET_MAC_CONFIGURATION_BL_MASK)

#define ENET_MAC_CONFIGURATION_DR_MASK           (0x100U)
#define ENET_MAC_CONFIGURATION_DR_SHIFT          (8U)
/*! DR - Disable Retry
 *  0b0..Enable Retry
 *  0b1..Disable Retry
 */
#define ENET_MAC_CONFIGURATION_DR(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_DR_SHIFT)) & ENET_MAC_CONFIGURATION_DR_MASK)

#define ENET_MAC_CONFIGURATION_DCRS_MASK         (0x200U)
#define ENET_MAC_CONFIGURATION_DCRS_SHIFT        (9U)
/*! DCRS - Disable Carrier Sense During Transmission
 *  0b0..Enable Carrier Sense During Transmission
 *  0b1..Disable Carrier Sense During Transmission
 */
#define ENET_MAC_CONFIGURATION_DCRS(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_DCRS_SHIFT)) & ENET_MAC_CONFIGURATION_DCRS_MASK)

#define ENET_MAC_CONFIGURATION_DO_MASK           (0x400U)
#define ENET_MAC_CONFIGURATION_DO_SHIFT          (10U)
/*! DO - Disable Receive Own
 *  0b0..Enable Receive Own
 *  0b1..Disable Receive Own
 */
#define ENET_MAC_CONFIGURATION_DO(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_DO_SHIFT)) & ENET_MAC_CONFIGURATION_DO_MASK)

#define ENET_MAC_CONFIGURATION_ECRSFD_MASK       (0x800U)
#define ENET_MAC_CONFIGURATION_ECRSFD_SHIFT      (11U)
/*! ECRSFD - Enable Carrier Sense Before Transmission in Full-Duplex Mode
 *  0b0..ECRSFD is disabled
 *  0b1..ECRSFD is enabled
 */
#define ENET_MAC_CONFIGURATION_ECRSFD(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_ECRSFD_SHIFT)) & ENET_MAC_CONFIGURATION_ECRSFD_MASK)

#define ENET_MAC_CONFIGURATION_LM_MASK           (0x1000U)
#define ENET_MAC_CONFIGURATION_LM_SHIFT          (12U)
/*! LM - Loopback Mode
 *  0b0..Loopback is disabled
 *  0b1..Loopback is enabled
 */
#define ENET_MAC_CONFIGURATION_LM(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_LM_SHIFT)) & ENET_MAC_CONFIGURATION_LM_MASK)

#define ENET_MAC_CONFIGURATION_DM_MASK           (0x2000U)
#define ENET_MAC_CONFIGURATION_DM_SHIFT          (13U)
/*! DM - Duplex Mode
 *  0b0..Half-duplex mode
 *  0b1..Full-duplex mode
 */
#define ENET_MAC_CONFIGURATION_DM(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_DM_SHIFT)) & ENET_MAC_CONFIGURATION_DM_MASK)

#define ENET_MAC_CONFIGURATION_FES_MASK          (0x4000U)
#define ENET_MAC_CONFIGURATION_FES_SHIFT         (14U)
/*! FES - Speed
 *  0b0..10 Mbps when PS bit is 1 and 1 Gbps when PS bit is 0
 *  0b1..100 Mbps when PS bit is 1 and 2.5 Gbps when PS bit is 0
 */
#define ENET_MAC_CONFIGURATION_FES(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_FES_SHIFT)) & ENET_MAC_CONFIGURATION_FES_MASK)

#define ENET_MAC_CONFIGURATION_PS_MASK           (0x8000U)
#define ENET_MAC_CONFIGURATION_PS_SHIFT          (15U)
/*! PS - Port Select
 *  0b0..For 1000 or 2500 Mbps operations
 *  0b1..For 10 or 100 Mbps operations
 */
#define ENET_MAC_CONFIGURATION_PS(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_PS_SHIFT)) & ENET_MAC_CONFIGURATION_PS_MASK)

#define ENET_MAC_CONFIGURATION_JE_MASK           (0x10000U)
#define ENET_MAC_CONFIGURATION_JE_SHIFT          (16U)
/*! JE - Jumbo Packet Enable
 *  0b0..Jumbo packet is disabled
 *  0b1..Jumbo packet is enabled
 */
#define ENET_MAC_CONFIGURATION_JE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_JE_SHIFT)) & ENET_MAC_CONFIGURATION_JE_MASK)

#define ENET_MAC_CONFIGURATION_JD_MASK           (0x20000U)
#define ENET_MAC_CONFIGURATION_JD_SHIFT          (17U)
/*! JD - Jabber Disable
 *  0b0..Jabber is enabled
 *  0b1..Jabber is disabled
 */
#define ENET_MAC_CONFIGURATION_JD(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_JD_SHIFT)) & ENET_MAC_CONFIGURATION_JD_MASK)

#define ENET_MAC_CONFIGURATION_WD_MASK           (0x80000U)
#define ENET_MAC_CONFIGURATION_WD_SHIFT          (19U)
/*! WD - Watchdog Disable
 *  0b0..Watchdog is enabled
 *  0b1..Watchdog is disabled
 */
#define ENET_MAC_CONFIGURATION_WD(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_WD_SHIFT)) & ENET_MAC_CONFIGURATION_WD_MASK)

#define ENET_MAC_CONFIGURATION_ACS_MASK          (0x100000U)
#define ENET_MAC_CONFIGURATION_ACS_SHIFT         (20U)
/*! ACS - Automatic Pad or CRC Stripping
 *  0b0..Automatic Pad or CRC Stripping is disabled
 *  0b1..Automatic Pad or CRC Stripping is enabled
 */
#define ENET_MAC_CONFIGURATION_ACS(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_ACS_SHIFT)) & ENET_MAC_CONFIGURATION_ACS_MASK)

#define ENET_MAC_CONFIGURATION_CST_MASK          (0x200000U)
#define ENET_MAC_CONFIGURATION_CST_SHIFT         (21U)
/*! CST - CRC stripping for Type packets
 *  0b0..CRC stripping for Type packets is disabled
 *  0b1..CRC stripping for Type packets is enabled
 */
#define ENET_MAC_CONFIGURATION_CST(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_CST_SHIFT)) & ENET_MAC_CONFIGURATION_CST_MASK)

#define ENET_MAC_CONFIGURATION_S2KP_MASK         (0x400000U)
#define ENET_MAC_CONFIGURATION_S2KP_SHIFT        (22U)
/*! S2KP - IEEE 802.3as Support for 2K Packets
 *  0b0..Support upto 2K packet is disabled
 *  0b1..Support upto 2K packet is Enabled
 */
#define ENET_MAC_CONFIGURATION_S2KP(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_S2KP_SHIFT)) & ENET_MAC_CONFIGURATION_S2KP_MASK)

#define ENET_MAC_CONFIGURATION_GPSLCE_MASK       (0x800000U)
#define ENET_MAC_CONFIGURATION_GPSLCE_SHIFT      (23U)
/*! GPSLCE - Giant Packet Size Limit Control Enable
 *  0b0..Giant Packet Size Limit Control is disabled
 *  0b1..Giant Packet Size Limit Control is enabled
 */
#define ENET_MAC_CONFIGURATION_GPSLCE(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_GPSLCE_SHIFT)) & ENET_MAC_CONFIGURATION_GPSLCE_MASK)

#define ENET_MAC_CONFIGURATION_IPG_MASK          (0x7000000U)
#define ENET_MAC_CONFIGURATION_IPG_SHIFT         (24U)
/*! IPG - Inter-Packet Gap
 *  0b000..96 bit times IPG
 *  0b001..88 bit times IPG
 *  0b010..80 bit times IPG
 *  0b011..72 bit times IPG
 *  0b100..64 bit times IPG
 *  0b101..56 bit times IPG
 *  0b110..48 bit times IPG
 *  0b111..40 bit times IPG
 */
#define ENET_MAC_CONFIGURATION_IPG(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_IPG_SHIFT)) & ENET_MAC_CONFIGURATION_IPG_MASK)

#define ENET_MAC_CONFIGURATION_IPC_MASK          (0x8000000U)
#define ENET_MAC_CONFIGURATION_IPC_SHIFT         (27U)
/*! IPC - Checksum Offload
 *  0b0..IP header/payload checksum checking is disabled
 *  0b1..IP header/payload checksum checking is enabled
 */
#define ENET_MAC_CONFIGURATION_IPC(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_IPC_SHIFT)) & ENET_MAC_CONFIGURATION_IPC_MASK)

#define ENET_MAC_CONFIGURATION_SARC_MASK         (0x70000000U)
#define ENET_MAC_CONFIGURATION_SARC_SHIFT        (28U)
/*! SARC - Source Address Insertion or Replacement Control
 *  0b000..mti_sa_ctrl_i and ati_sa_ctrl_i input signals control the SA field generation
 *  0b010..Contents of MAC Addr-0 inserted in SA field
 *  0b011..Contents of MAC Addr-0 replaces SA field
 *  0b110..Contents of MAC Addr-1 inserted in SA field
 *  0b111..Contents of MAC Addr-1 replaces SA field
 */
#define ENET_MAC_CONFIGURATION_SARC(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIGURATION_SARC_SHIFT)) & ENET_MAC_CONFIGURATION_SARC_MASK)
/*! @} */

/*! @name MAC_EXT_CONFIGURATION - MAC Extended Configuration Register */
/*! @{ */

#define ENET_MAC_EXT_CONFIGURATION_GPSL_MASK     (0x3FFFU)
#define ENET_MAC_EXT_CONFIGURATION_GPSL_SHIFT    (0U)
/*! GPSL - Giant Packet Size Limit */
#define ENET_MAC_EXT_CONFIGURATION_GPSL(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIGURATION_GPSL_SHIFT)) & ENET_MAC_EXT_CONFIGURATION_GPSL_MASK)

#define ENET_MAC_EXT_CONFIGURATION_DCRCC_MASK    (0x10000U)
#define ENET_MAC_EXT_CONFIGURATION_DCRCC_SHIFT   (16U)
/*! DCRCC - Disable CRC Checking for Received Packets
 *  0b0..CRC Checking is enabled
 *  0b1..CRC Checking is disabled
 */
#define ENET_MAC_EXT_CONFIGURATION_DCRCC(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIGURATION_DCRCC_SHIFT)) & ENET_MAC_EXT_CONFIGURATION_DCRCC_MASK)

#define ENET_MAC_EXT_CONFIGURATION_SPEN_MASK     (0x20000U)
#define ENET_MAC_EXT_CONFIGURATION_SPEN_SHIFT    (17U)
/*! SPEN - Slow Protocol Detection Enable
 *  0b0..Slow Protocol Detection is disabled
 *  0b1..Slow Protocol Detection is enabled
 */
#define ENET_MAC_EXT_CONFIGURATION_SPEN(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIGURATION_SPEN_SHIFT)) & ENET_MAC_EXT_CONFIGURATION_SPEN_MASK)

#define ENET_MAC_EXT_CONFIGURATION_USP_MASK      (0x40000U)
#define ENET_MAC_EXT_CONFIGURATION_USP_SHIFT     (18U)
/*! USP - Unicast Slow Protocol Packet Detect
 *  0b0..Unicast Slow Protocol Packet Detection is disabled
 *  0b1..Unicast Slow Protocol Packet Detection is enabled
 */
#define ENET_MAC_EXT_CONFIGURATION_USP(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIGURATION_USP_SHIFT)) & ENET_MAC_EXT_CONFIGURATION_USP_MASK)

#define ENET_MAC_EXT_CONFIGURATION_PDC_MASK      (0x80000U)
#define ENET_MAC_EXT_CONFIGURATION_PDC_SHIFT     (19U)
/*! PDC - Packet Duplication Control
 *  0b0..Packet Duplication Control is disabled
 *  0b1..Packet Duplication Control is enabled
 */
#define ENET_MAC_EXT_CONFIGURATION_PDC(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIGURATION_PDC_SHIFT)) & ENET_MAC_EXT_CONFIGURATION_PDC_MASK)

#define ENET_MAC_EXT_CONFIGURATION_EIPGEN_MASK   (0x1000000U)
#define ENET_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT  (24U)
/*! EIPGEN - Extended Inter-Packet Gap Enable
 *  0b0..Extended Inter-Packet Gap is disabled
 *  0b1..Extended Inter-Packet Gap is enabled
 */
#define ENET_MAC_EXT_CONFIGURATION_EIPGEN(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT)) & ENET_MAC_EXT_CONFIGURATION_EIPGEN_MASK)

#define ENET_MAC_EXT_CONFIGURATION_EIPG_MASK     (0x3E000000U)
#define ENET_MAC_EXT_CONFIGURATION_EIPG_SHIFT    (25U)
/*! EIPG - Extended Inter-Packet Gap */
#define ENET_MAC_EXT_CONFIGURATION_EIPG(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIGURATION_EIPG_SHIFT)) & ENET_MAC_EXT_CONFIGURATION_EIPG_MASK)
/*! @} */

/*! @name MAC_PACKET_FILTER - MAC Packet Filter */
/*! @{ */

#define ENET_MAC_PACKET_FILTER_PR_MASK           (0x1U)
#define ENET_MAC_PACKET_FILTER_PR_SHIFT          (0U)
/*! PR - Promiscuous Mode
 *  0b0..Promiscuous Mode is disabled
 *  0b1..Promiscuous Mode is enabled
 */
#define ENET_MAC_PACKET_FILTER_PR(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PACKET_FILTER_PR_SHIFT)) & ENET_MAC_PACKET_FILTER_PR_MASK)

#define ENET_MAC_PACKET_FILTER_DAIF_MASK         (0x8U)
#define ENET_MAC_PACKET_FILTER_DAIF_SHIFT        (3U)
/*! DAIF - DA Inverse Filtering
 *  0b0..DA Inverse Filtering is disabled
 *  0b1..DA Inverse Filtering is enabled
 */
#define ENET_MAC_PACKET_FILTER_DAIF(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PACKET_FILTER_DAIF_SHIFT)) & ENET_MAC_PACKET_FILTER_DAIF_MASK)

#define ENET_MAC_PACKET_FILTER_PM_MASK           (0x10U)
#define ENET_MAC_PACKET_FILTER_PM_SHIFT          (4U)
/*! PM - Pass All Multicast
 *  0b0..Pass All Multicast is disabled
 *  0b1..Pass All Multicast is enabled
 */
#define ENET_MAC_PACKET_FILTER_PM(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PACKET_FILTER_PM_SHIFT)) & ENET_MAC_PACKET_FILTER_PM_MASK)

#define ENET_MAC_PACKET_FILTER_DBF_MASK          (0x20U)
#define ENET_MAC_PACKET_FILTER_DBF_SHIFT         (5U)
/*! DBF - Disable Broadcast Packets
 *  0b0..Enable Broadcast Packets
 *  0b1..Disable Broadcast Packets
 */
#define ENET_MAC_PACKET_FILTER_DBF(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PACKET_FILTER_DBF_SHIFT)) & ENET_MAC_PACKET_FILTER_DBF_MASK)

#define ENET_MAC_PACKET_FILTER_PCF_MASK          (0xC0U)
#define ENET_MAC_PACKET_FILTER_PCF_SHIFT         (6U)
/*! PCF - Pass Control Packets
 *  0b00..MAC filters all control packets from reaching the application
 *  0b01..MAC forwards all control packets except Pause packets to the application even if they fail the address filter
 *  0b10..MAC forwards all control packets to the application even if they fail the address filter
 *  0b11..MAC forwards the control packets that pass the Address filter
 */
#define ENET_MAC_PACKET_FILTER_PCF(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PACKET_FILTER_PCF_SHIFT)) & ENET_MAC_PACKET_FILTER_PCF_MASK)

#define ENET_MAC_PACKET_FILTER_VTFE_MASK         (0x10000U)
#define ENET_MAC_PACKET_FILTER_VTFE_SHIFT        (16U)
/*! VTFE - VLAN Tag Filter Enable
 *  0b0..VLAN Tag Filter is disabled
 *  0b1..VLAN Tag Filter is enabled
 */
#define ENET_MAC_PACKET_FILTER_VTFE(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PACKET_FILTER_VTFE_SHIFT)) & ENET_MAC_PACKET_FILTER_VTFE_MASK)

#define ENET_MAC_PACKET_FILTER_RA_MASK           (0x80000000U)
#define ENET_MAC_PACKET_FILTER_RA_SHIFT          (31U)
/*! RA - Receive All
 *  0b0..Receive All is disabled
 *  0b1..Receive All is enabled
 */
#define ENET_MAC_PACKET_FILTER_RA(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PACKET_FILTER_RA_SHIFT)) & ENET_MAC_PACKET_FILTER_RA_MASK)
/*! @} */

/*! @name MAC_WATCHDOG_TIMEOUT - Watchdog Timeout */
/*! @{ */

#define ENET_MAC_WATCHDOG_TIMEOUT_WTO_MASK       (0xFU)
#define ENET_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT      (0U)
/*! WTO - Watchdog Timeout
 *  0b0000..2 KB
 *  0b0001..3 KB
 *  0b0010..4 KB
 *  0b0011..5 KB
 *  0b0100..6 KB
 *  0b0101..7 KB
 *  0b0110..8 KB
 *  0b0111..9 KB
 *  0b1000..10 KB
 *  0b1001..11 KB
 *  0b1010..12 KB
 *  0b1011..13 KB
 *  0b1100..14 KB
 *  0b1101..15 KB
 *  0b1110..16383 Bytes
 *  0b1111..Reserved
 */
#define ENET_MAC_WATCHDOG_TIMEOUT_WTO(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT)) & ENET_MAC_WATCHDOG_TIMEOUT_WTO_MASK)

#define ENET_MAC_WATCHDOG_TIMEOUT_PWE_MASK       (0x100U)
#define ENET_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT      (8U)
/*! PWE - Programmable Watchdog Enable
 *  0b0..Programmable Watchdog is disabled
 *  0b1..Programmable Watchdog is enabled
 */
#define ENET_MAC_WATCHDOG_TIMEOUT_PWE(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT)) & ENET_MAC_WATCHDOG_TIMEOUT_PWE_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_CTRL - MAC VLAN Tag Control */
/*! @{ */

#define ENET_MAC_VLAN_TAG_CTRL_VL_MASK           (0xFFFFU)
#define ENET_MAC_VLAN_TAG_CTRL_VL_SHIFT          (0U)
/*! VL - VLAN Tag Identifier for Receive Packets */
#define ENET_MAC_VLAN_TAG_CTRL_VL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_VL_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_VL_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_ETV_MASK          (0x10000U)
#define ENET_MAC_VLAN_TAG_CTRL_ETV_SHIFT         (16U)
/*! ETV - Enable 12-Bit VLAN Tag Comparison
 *  0b0..12-bit VLAN Tag Comparison is disabled
 *  0b1..12-bit VLAN Tag Comparison is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_ETV(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_ETV_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_ETV_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_VTIM_MASK         (0x20000U)
#define ENET_MAC_VLAN_TAG_CTRL_VTIM_SHIFT        (17U)
/*! VTIM - VLAN Tag Inverse Match Enable
 *  0b0..VLAN Tag Inverse Match is disabled
 *  0b1..VLAN Tag Inverse Match is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_VTIM(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_VTIM_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_VTIM_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_ESVL_MASK         (0x40000U)
#define ENET_MAC_VLAN_TAG_CTRL_ESVL_SHIFT        (18U)
/*! ESVL - Enable S-VLAN
 *  0b0..S-VLAN is disabled
 *  0b1..S-VLAN is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_ESVL(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_ESVL_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_ESVL_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_ERSVLM_MASK       (0x80000U)
#define ENET_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT      (19U)
/*! ERSVLM - Enable Receive S-VLAN Match
 *  0b0..Receive S-VLAN Match is disabled
 *  0b1..Receive S-VLAN Match is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_ERSVLM(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_ERSVLM_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_DOVLTC_MASK       (0x100000U)
#define ENET_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT      (20U)
/*! DOVLTC - Disable VLAN Type Check
 *  0b0..VLAN Type Check is enabled
 *  0b1..VLAN Type Check is disabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_DOVLTC(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_DOVLTC_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_EVLS_MASK         (0x600000U)
#define ENET_MAC_VLAN_TAG_CTRL_EVLS_SHIFT        (21U)
/*! EVLS - Enable VLAN Tag Stripping on Receive
 *  0b00..Do not strip
 *  0b01..Strip if VLAN filter passes
 *  0b10..Strip if VLAN filter fails
 *  0b11..Always strip
 */
#define ENET_MAC_VLAN_TAG_CTRL_EVLS(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_EVLS_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_EVLS_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_EVLRXS_MASK       (0x1000000U)
#define ENET_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT      (24U)
/*! EVLRXS - Enable VLAN Tag in Rx status
 *  0b0..VLAN Tag in Rx status is disabled
 *  0b1..VLAN Tag in Rx status is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_EVLRXS(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_EVLRXS_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_EDVLP_MASK        (0x4000000U)
#define ENET_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT       (26U)
/*! EDVLP - Enable Double VLAN Processing
 *  0b0..Double VLAN Processing is disabled
 *  0b1..Double VLAN Processing is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_EDVLP(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_EDVLP_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_ERIVLT_MASK       (0x8000000U)
#define ENET_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT      (27U)
/*! ERIVLT - Enable Inner VLAN Tag
 *  0b0..Inner VLAN tag is disabled
 *  0b1..Inner VLAN tag is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_ERIVLT(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_ERIVLT_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_EIVLS_MASK        (0x30000000U)
#define ENET_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT       (28U)
/*! EIVLS - Enable Inner VLAN Tag Stripping on Receive
 *  0b00..Do not strip
 *  0b01..Strip if VLAN filter passes
 *  0b10..Strip if VLAN filter fails
 *  0b11..Always strip
 */
#define ENET_MAC_VLAN_TAG_CTRL_EIVLS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_EIVLS_MASK)

#define ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK      (0x80000000U)
#define ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT     (31U)
/*! EIVLRXS - Enable Inner VLAN Tag in Rx Status
 *  0b0..Inner VLAN Tag in Rx status is disabled
 *  0b1..Inner VLAN Tag in Rx status is enabled
 */
#define ENET_MAC_VLAN_TAG_CTRL_EIVLRXS(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT)) & ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL - VLAN Tag Inclusion or Replacement */
/*! @{ */

#define ENET_MAC_VLAN_INCL_VLT_MASK              (0xFFFFU)
#define ENET_MAC_VLAN_INCL_VLT_SHIFT             (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define ENET_MAC_VLAN_INCL_VLT(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_VLT_SHIFT)) & ENET_MAC_VLAN_INCL_VLT_MASK)

#define ENET_MAC_VLAN_INCL_VLC_MASK              (0x30000U)
#define ENET_MAC_VLAN_INCL_VLC_SHIFT             (16U)
/*! VLC - VLAN Tag Control in Transmit Packets
 *  0b00..No VLAN tag deletion, insertion, or replacement
 *  0b01..VLAN tag deletion
 *  0b10..VLAN tag insertion
 *  0b11..VLAN tag replacement
 */
#define ENET_MAC_VLAN_INCL_VLC(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_VLC_SHIFT)) & ENET_MAC_VLAN_INCL_VLC_MASK)

#define ENET_MAC_VLAN_INCL_VLP_MASK              (0x40000U)
#define ENET_MAC_VLAN_INCL_VLP_SHIFT             (18U)
/*! VLP - VLAN Priority Control
 *  0b0..VLAN Priority Control is disabled
 *  0b1..VLAN Priority Control is enabled
 */
#define ENET_MAC_VLAN_INCL_VLP(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_VLP_SHIFT)) & ENET_MAC_VLAN_INCL_VLP_MASK)

#define ENET_MAC_VLAN_INCL_CSVL_MASK             (0x80000U)
#define ENET_MAC_VLAN_INCL_CSVL_SHIFT            (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted or replaced
 *  0b1..S-VLAN type (0x88A8) is inserted or replaced
 */
#define ENET_MAC_VLAN_INCL_CSVL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_CSVL_SHIFT)) & ENET_MAC_VLAN_INCL_CSVL_MASK)

#define ENET_MAC_VLAN_INCL_VLTI_MASK             (0x100000U)
#define ENET_MAC_VLAN_INCL_VLTI_SHIFT            (20U)
/*! VLTI - VLAN Tag Input
 *  0b0..VLAN Tag Input is disabled
 *  0b1..VLAN Tag Input is enabled
 */
#define ENET_MAC_VLAN_INCL_VLTI(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_VLTI_SHIFT)) & ENET_MAC_VLAN_INCL_VLTI_MASK)

#define ENET_MAC_VLAN_INCL_CBTI_MASK             (0x200000U)
#define ENET_MAC_VLAN_INCL_CBTI_SHIFT            (21U)
/*! CBTI - Channel based tag insertion
 *  0b0..Channel based tag insertion is disabled
 *  0b1..Channel based tag insertion is enabled
 */
#define ENET_MAC_VLAN_INCL_CBTI(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_CBTI_SHIFT)) & ENET_MAC_VLAN_INCL_CBTI_MASK)

#define ENET_MAC_VLAN_INCL_ADDR_MASK             (0x1000000U)
#define ENET_MAC_VLAN_INCL_ADDR_SHIFT            (24U)
/*! ADDR - Address */
#define ENET_MAC_VLAN_INCL_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_ADDR_SHIFT)) & ENET_MAC_VLAN_INCL_ADDR_MASK)

#define ENET_MAC_VLAN_INCL_RDWR_MASK             (0x40000000U)
#define ENET_MAC_VLAN_INCL_RDWR_SHIFT            (30U)
/*! RDWR - Read write control
 *  0b0..Read operation of indirect access
 *  0b1..Write operation of indirect access
 */
#define ENET_MAC_VLAN_INCL_RDWR(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_RDWR_SHIFT)) & ENET_MAC_VLAN_INCL_RDWR_MASK)

#define ENET_MAC_VLAN_INCL_BUSY_MASK             (0x80000000U)
#define ENET_MAC_VLAN_INCL_BUSY_SHIFT            (31U)
/*! BUSY - Busy
 *  0b0..Busy status not detected
 *  0b1..Busy status detected
 */
#define ENET_MAC_VLAN_INCL_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_INCL_BUSY_SHIFT)) & ENET_MAC_VLAN_INCL_BUSY_MASK)
/*! @} */

/*! @name MAC_INNER_VLAN_INCL - MAC Inner VLAN Tag Inclusion or Replacement */
/*! @{ */

#define ENET_MAC_INNER_VLAN_INCL_VLT_MASK        (0xFFFFU)
#define ENET_MAC_INNER_VLAN_INCL_VLT_SHIFT       (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define ENET_MAC_INNER_VLAN_INCL_VLT(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INNER_VLAN_INCL_VLT_SHIFT)) & ENET_MAC_INNER_VLAN_INCL_VLT_MASK)

#define ENET_MAC_INNER_VLAN_INCL_VLC_MASK        (0x30000U)
#define ENET_MAC_INNER_VLAN_INCL_VLC_SHIFT       (16U)
/*! VLC - VLAN Tag Control in Transmit Packets
 *  0b00..No VLAN tag deletion, insertion, or replacement
 *  0b01..VLAN tag deletion
 *  0b10..VLAN tag insertion
 *  0b11..VLAN tag replacement
 */
#define ENET_MAC_INNER_VLAN_INCL_VLC(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INNER_VLAN_INCL_VLC_SHIFT)) & ENET_MAC_INNER_VLAN_INCL_VLC_MASK)

#define ENET_MAC_INNER_VLAN_INCL_VLP_MASK        (0x40000U)
#define ENET_MAC_INNER_VLAN_INCL_VLP_SHIFT       (18U)
/*! VLP - VLAN Priority Control
 *  0b0..VLAN Priority Control is disabled
 *  0b1..VLAN Priority Control is enabled
 */
#define ENET_MAC_INNER_VLAN_INCL_VLP(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INNER_VLAN_INCL_VLP_SHIFT)) & ENET_MAC_INNER_VLAN_INCL_VLP_MASK)

#define ENET_MAC_INNER_VLAN_INCL_CSVL_MASK       (0x80000U)
#define ENET_MAC_INNER_VLAN_INCL_CSVL_SHIFT      (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define ENET_MAC_INNER_VLAN_INCL_CSVL(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INNER_VLAN_INCL_CSVL_SHIFT)) & ENET_MAC_INNER_VLAN_INCL_CSVL_MASK)

#define ENET_MAC_INNER_VLAN_INCL_VLTI_MASK       (0x100000U)
#define ENET_MAC_INNER_VLAN_INCL_VLTI_SHIFT      (20U)
/*! VLTI - VLAN Tag Input
 *  0b0..VLAN Tag Input is disabled
 *  0b1..VLAN Tag Input is enabled
 */
#define ENET_MAC_INNER_VLAN_INCL_VLTI(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INNER_VLAN_INCL_VLTI_SHIFT)) & ENET_MAC_INNER_VLAN_INCL_VLTI_MASK)
/*! @} */

/*! @name MAC_TX_FLOW_CTRL_Q - MAC Q0 Tx Flow Control */
/*! @{ */

#define ENET_MAC_TX_FLOW_CTRL_Q_FCB_BPA_MASK     (0x1U)
#define ENET_MAC_TX_FLOW_CTRL_Q_FCB_BPA_SHIFT    (0U)
/*! FCB_BPA - Flow Control Busy or Backpressure Activate
 *  0b0..Flow Control Busy or Backpressure Activate is disabled
 *  0b1..Flow Control Busy or Backpressure Activate is enabled
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_FCB_BPA(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_FCB_BPA_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_FCB_BPA_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_TFE_MASK         (0x2U)
#define ENET_MAC_TX_FLOW_CTRL_Q_TFE_SHIFT        (1U)
/*! TFE - Transmit Flow Control Enable
 *  0b0..Transmit Flow Control is disabled
 *  0b1..Transmit Flow Control is enabled
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_TFE(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_TFE_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_TFE_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_PLT_MASK         (0x70U)
#define ENET_MAC_TX_FLOW_CTRL_Q_PLT_SHIFT        (4U)
/*! PLT - Pause Low Threshold
 *  0b000..Pause Time minus 4 Slot Times (PT -4 slot times)
 *  0b001..Pause Time minus 28 Slot Times (PT -28 slot times)
 *  0b010..Pause Time minus 36 Slot Times (PT -36 slot times)
 *  0b011..Pause Time minus 144 Slot Times (PT -144 slot times)
 *  0b100..Pause Time minus 256 Slot Times (PT -256 slot times)
 *  0b101..Pause Time minus 512 Slot Times (PT -512 slot times)
 *  0b110..Reserved
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_PLT(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_PLT_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_PLT_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_MASK        (0x80U)
#define ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_SHIFT       (7U)
/*! DZPQ - Disable Zero-Quanta Pause
 *  0b0..Zero-Quanta Pause packet generation is enabled
 *  0b1..Zero-Quanta Pause packet generation is disabled
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_DZPQ(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_PT_MASK          (0xFFFF0000U)
#define ENET_MAC_TX_FLOW_CTRL_Q_PT_SHIFT         (16U)
/*! PT - Pause Time */
#define ENET_MAC_TX_FLOW_CTRL_Q_PT(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_PT_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_PT_MASK)
/*! @} */

/*! @name MAC_RX_FLOW_CTRL - MAC Rx Flow Control */
/*! @{ */

#define ENET_MAC_RX_FLOW_CTRL_RFE_MASK           (0x1U)
#define ENET_MAC_RX_FLOW_CTRL_RFE_SHIFT          (0U)
/*! RFE - Receive Flow Control Enable
 *  0b0..Receive Flow Control is disabled
 *  0b1..Receive Flow Control is enabled
 */
#define ENET_MAC_RX_FLOW_CTRL_RFE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_FLOW_CTRL_RFE_SHIFT)) & ENET_MAC_RX_FLOW_CTRL_RFE_MASK)

#define ENET_MAC_RX_FLOW_CTRL_UP_MASK            (0x2U)
#define ENET_MAC_RX_FLOW_CTRL_UP_SHIFT           (1U)
/*! UP - Unicast Pause Packet Detect
 *  0b0..Unicast Pause Packet Detect disabled
 *  0b1..Unicast Pause Packet Detect enabled
 */
#define ENET_MAC_RX_FLOW_CTRL_UP(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_FLOW_CTRL_UP_SHIFT)) & ENET_MAC_RX_FLOW_CTRL_UP_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL4 - Receive Queue Control 4 */
/*! @{ */

#define ENET_MAC_RXQ_CTRL4_UFFQE_MASK            (0x1U)
#define ENET_MAC_RXQ_CTRL4_UFFQE_SHIFT           (0U)
/*! UFFQE - Unicast Address Filter Fail Packets Queuing Enable.
 *  0b0..Unicast Address Filter Fail Packets Queuing is disabled
 *  0b1..Unicast Address Filter Fail Packets Queuing is enabled
 */
#define ENET_MAC_RXQ_CTRL4_UFFQE(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL4_UFFQE_SHIFT)) & ENET_MAC_RXQ_CTRL4_UFFQE_MASK)

#define ENET_MAC_RXQ_CTRL4_UFFQ_MASK             (0x2U)
#define ENET_MAC_RXQ_CTRL4_UFFQ_SHIFT            (1U)
/*! UFFQ - Unicast Address Filter Fail Packets Queue. */
#define ENET_MAC_RXQ_CTRL4_UFFQ(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL4_UFFQ_SHIFT)) & ENET_MAC_RXQ_CTRL4_UFFQ_MASK)

#define ENET_MAC_RXQ_CTRL4_MFFQE_MASK            (0x100U)
#define ENET_MAC_RXQ_CTRL4_MFFQE_SHIFT           (8U)
/*! MFFQE - Multicast Address Filter Fail Packets Queuing Enable.
 *  0b0..Multicast Address Filter Fail Packets Queuing is disabled
 *  0b1..Multicast Address Filter Fail Packets Queuing is enabled
 */
#define ENET_MAC_RXQ_CTRL4_MFFQE(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL4_MFFQE_SHIFT)) & ENET_MAC_RXQ_CTRL4_MFFQE_MASK)

#define ENET_MAC_RXQ_CTRL4_MFFQ_MASK             (0x200U)
#define ENET_MAC_RXQ_CTRL4_MFFQ_SHIFT            (9U)
/*! MFFQ - Multicast Address Filter Fail Packets Queue. */
#define ENET_MAC_RXQ_CTRL4_MFFQ(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL4_MFFQ_SHIFT)) & ENET_MAC_RXQ_CTRL4_MFFQ_MASK)

#define ENET_MAC_RXQ_CTRL4_VFFQE_MASK            (0x10000U)
#define ENET_MAC_RXQ_CTRL4_VFFQE_SHIFT           (16U)
/*! VFFQE - VLAN Tag Filter Fail Packets Queuing Enable
 *  0b0..VLAN tag Filter Fail Packets Queuing is disabled
 *  0b1..VLAN tag Filter Fail Packets Queuing is enabled
 */
#define ENET_MAC_RXQ_CTRL4_VFFQE(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL4_VFFQE_SHIFT)) & ENET_MAC_RXQ_CTRL4_VFFQE_MASK)

#define ENET_MAC_RXQ_CTRL4_VFFQ_MASK             (0x20000U)
#define ENET_MAC_RXQ_CTRL4_VFFQ_SHIFT            (17U)
/*! VFFQ - VLAN Tag Filter Fail Packets Queue */
#define ENET_MAC_RXQ_CTRL4_VFFQ(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL4_VFFQ_SHIFT)) & ENET_MAC_RXQ_CTRL4_VFFQ_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL - Receive Queue Control 0..Receive Queue Control 2 */
/*! @{ */

#define ENET_MAC_RXQ_CTRL_AVCPQ_MASK             (0x7U)
#define ENET_MAC_RXQ_CTRL_AVCPQ_SHIFT            (0U)
/*! AVCPQ - AV Untagged Control Packets Queue
 *  0b000..Receive Queue 0
 *  0b001..Receive Queue 1
 */
#define ENET_MAC_RXQ_CTRL_AVCPQ(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_AVCPQ_SHIFT)) & ENET_MAC_RXQ_CTRL_AVCPQ_MASK)

#define ENET_MAC_RXQ_CTRL_PSRQ0_MASK             (0xFFU)
#define ENET_MAC_RXQ_CTRL_PSRQ0_SHIFT            (0U)
/*! PSRQ0 - Priorities Selected in the Receive Queue 0 */
#define ENET_MAC_RXQ_CTRL_PSRQ0(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_PSRQ0_SHIFT)) & ENET_MAC_RXQ_CTRL_PSRQ0_MASK)

#define ENET_MAC_RXQ_CTRL_RXQ0EN_MASK            (0x3U)
#define ENET_MAC_RXQ_CTRL_RXQ0EN_SHIFT           (0U)
/*! RXQ0EN - Receive Queue 0 Enable
 *  0b00..Queue not enabled
 *  0b01..Queue enabled for AV
 *  0b10..Queue enabled for DCB/Generic
 *  0b11..Reserved
 */
#define ENET_MAC_RXQ_CTRL_RXQ0EN(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_RXQ0EN_SHIFT)) & ENET_MAC_RXQ_CTRL_RXQ0EN_MASK)

#define ENET_MAC_RXQ_CTRL_RXQ1EN_MASK            (0xCU)
#define ENET_MAC_RXQ_CTRL_RXQ1EN_SHIFT           (2U)
/*! RXQ1EN - Receive Queue 1 Enable
 *  0b00..Queue not enabled
 *  0b01..Queue enabled for AV
 *  0b10..Queue enabled for DCB/Generic
 *  0b11..Reserved
 */
#define ENET_MAC_RXQ_CTRL_RXQ1EN(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_RXQ1EN_SHIFT)) & ENET_MAC_RXQ_CTRL_RXQ1EN_MASK)

#define ENET_MAC_RXQ_CTRL_PTPQ_MASK              (0x70U)
#define ENET_MAC_RXQ_CTRL_PTPQ_SHIFT             (4U)
/*! PTPQ - PTP Packets Queue
 *  0b000..Receive Queue 0
 *  0b001..Receive Queue 1
 */
#define ENET_MAC_RXQ_CTRL_PTPQ(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_PTPQ_SHIFT)) & ENET_MAC_RXQ_CTRL_PTPQ_MASK)

#define ENET_MAC_RXQ_CTRL_PSRQ1_MASK             (0xFF00U)
#define ENET_MAC_RXQ_CTRL_PSRQ1_SHIFT            (8U)
/*! PSRQ1 - Priorities Selected in the Receive Queue 1 */
#define ENET_MAC_RXQ_CTRL_PSRQ1(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_PSRQ1_SHIFT)) & ENET_MAC_RXQ_CTRL_PSRQ1_MASK)

#define ENET_MAC_RXQ_CTRL_UPQ_MASK               (0x7000U)
#define ENET_MAC_RXQ_CTRL_UPQ_SHIFT              (12U)
/*! UPQ - Untagged Packet Queue
 *  0b000..Receive Queue 0
 *  0b001..Receive Queue 1
 */
#define ENET_MAC_RXQ_CTRL_UPQ(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_UPQ_SHIFT)) & ENET_MAC_RXQ_CTRL_UPQ_MASK)

#define ENET_MAC_RXQ_CTRL_MCBCQ_MASK             (0x70000U)
#define ENET_MAC_RXQ_CTRL_MCBCQ_SHIFT            (16U)
/*! MCBCQ - Multicast and Broadcast Queue
 *  0b000..Receive Queue 0
 *  0b001..Receive Queue 1
 */
#define ENET_MAC_RXQ_CTRL_MCBCQ(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_MCBCQ_SHIFT)) & ENET_MAC_RXQ_CTRL_MCBCQ_MASK)

#define ENET_MAC_RXQ_CTRL_MCBCQEN_MASK           (0x100000U)
#define ENET_MAC_RXQ_CTRL_MCBCQEN_SHIFT          (20U)
/*! MCBCQEN - Multicast and Broadcast Queue Enable
 *  0b0..Multicast and Broadcast Queue is disabled
 *  0b1..Multicast and Broadcast Queue is enabled
 */
#define ENET_MAC_RXQ_CTRL_MCBCQEN(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_MCBCQEN_SHIFT)) & ENET_MAC_RXQ_CTRL_MCBCQEN_MASK)

#define ENET_MAC_RXQ_CTRL_TACPQE_MASK            (0x200000U)
#define ENET_MAC_RXQ_CTRL_TACPQE_SHIFT           (21U)
/*! TACPQE - Tagged AV Control Packets Queuing Enable.
 *  0b0..Tagged AV Control Packets Queuing is disabled
 *  0b1..Tagged AV Control Packets Queuing is enabled
 */
#define ENET_MAC_RXQ_CTRL_TACPQE(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_TACPQE_SHIFT)) & ENET_MAC_RXQ_CTRL_TACPQE_MASK)

#define ENET_MAC_RXQ_CTRL_TPQC_MASK              (0xC00000U)
#define ENET_MAC_RXQ_CTRL_TPQC_SHIFT             (22U)
/*! TPQC - Tagged PTP over Ethernet Packets Queuing Control. */
#define ENET_MAC_RXQ_CTRL_TPQC(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_TPQC_SHIFT)) & ENET_MAC_RXQ_CTRL_TPQC_MASK)

#define ENET_MAC_RXQ_CTRL_OMCBCQ_MASK            (0x10000000U)
#define ENET_MAC_RXQ_CTRL_OMCBCQ_SHIFT           (28U)
/*! OMCBCQ - OMCBCQ
 *  0b0..overriding MCBCQ priority disabled
 *  0b1..overriding MCBCQ priority enabled
 */
#define ENET_MAC_RXQ_CTRL_OMCBCQ(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_OMCBCQ_SHIFT)) & ENET_MAC_RXQ_CTRL_OMCBCQ_MASK)

#define ENET_MAC_RXQ_CTRL_TBRQE_MASK             (0x20000000U)
#define ENET_MAC_RXQ_CTRL_TBRQE_SHIFT            (29U)
/*! TBRQE - Type Field Based Rx Queuing Enable */
#define ENET_MAC_RXQ_CTRL_TBRQE(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_TBRQE_SHIFT)) & ENET_MAC_RXQ_CTRL_TBRQE_MASK)
/*! @} */

/*! @name MAC_INTERRUPT_STATUS - Interrupt Status */
/*! @{ */

#define ENET_MAC_INTERRUPT_STATUS_PHYIS_MASK     (0x8U)
#define ENET_MAC_INTERRUPT_STATUS_PHYIS_SHIFT    (3U)
/*! PHYIS - PHY Interrupt
 *  0b0..PHY Interrupt not detected
 *  0b1..PHY Interrupt detected
 */
#define ENET_MAC_INTERRUPT_STATUS_PHYIS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_STATUS_PHYIS_SHIFT)) & ENET_MAC_INTERRUPT_STATUS_PHYIS_MASK)

#define ENET_MAC_INTERRUPT_STATUS_PMTIS_MASK     (0x10U)
#define ENET_MAC_INTERRUPT_STATUS_PMTIS_SHIFT    (4U)
/*! PMTIS - PMTIS
 *  0b0..PMT Interrupt status not active
 *  0b1..PMT Interrupt status active
 */
#define ENET_MAC_INTERRUPT_STATUS_PMTIS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_STATUS_PMTIS_SHIFT)) & ENET_MAC_INTERRUPT_STATUS_PMTIS_MASK)

#define ENET_MAC_INTERRUPT_STATUS_LPIIS_MASK     (0x20U)
#define ENET_MAC_INTERRUPT_STATUS_LPIIS_SHIFT    (5U)
/*! LPIIS - LPIIS
 *  0b0..LPI Interrupt status not active
 *  0b1..LPI Interrupt status active
 */
#define ENET_MAC_INTERRUPT_STATUS_LPIIS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_STATUS_LPIIS_SHIFT)) & ENET_MAC_INTERRUPT_STATUS_LPIIS_MASK)

#define ENET_MAC_INTERRUPT_STATUS_TSIS_MASK      (0x1000U)
#define ENET_MAC_INTERRUPT_STATUS_TSIS_SHIFT     (12U)
/*! TSIS - TSIS
 *  0b0..Timestamp Interrupt status not active
 *  0b1..Timestamp Interrupt status active
 */
#define ENET_MAC_INTERRUPT_STATUS_TSIS(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_STATUS_TSIS_SHIFT)) & ENET_MAC_INTERRUPT_STATUS_TSIS_MASK)

#define ENET_MAC_INTERRUPT_STATUS_TXSTSIS_MASK   (0x2000U)
#define ENET_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT  (13U)
/*! TXSTSIS - Transmit Status Interrupt
 *  0b0..Transmit Interrupt status not active
 *  0b1..Transmit Interrupt status active
 */
#define ENET_MAC_INTERRUPT_STATUS_TXSTSIS(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT)) & ENET_MAC_INTERRUPT_STATUS_TXSTSIS_MASK)

#define ENET_MAC_INTERRUPT_STATUS_RXSTSIS_MASK   (0x4000U)
#define ENET_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT  (14U)
/*! RXSTSIS - Receive Status Interrupt
 *  0b0..Receive Interrupt status not active
 *  0b1..Receive Interrupt status active
 */
#define ENET_MAC_INTERRUPT_STATUS_RXSTSIS(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT)) & ENET_MAC_INTERRUPT_STATUS_RXSTSIS_MASK)

#define ENET_MAC_INTERRUPT_STATUS_MDIOIS_MASK    (0x40000U)
#define ENET_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT   (18U)
/*! MDIOIS - MDIO Interrupt Status
 *  0b0..MDIO Interrupt status not active
 *  0b1..MDIO Interrupt status active
 */
#define ENET_MAC_INTERRUPT_STATUS_MDIOIS(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT)) & ENET_MAC_INTERRUPT_STATUS_MDIOIS_MASK)
/*! @} */

/*! @name MAC_INTERRUPT_ENABLE - Interrupt Enable */
/*! @{ */

#define ENET_MAC_INTERRUPT_ENABLE_PHYIE_MASK     (0x8U)
#define ENET_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT    (3U)
/*! PHYIE - PHY Interrupt Enable
 *  0b0..PHY Interrupt is disabled
 *  0b1..PHY Interrupt is enabled
 */
#define ENET_MAC_INTERRUPT_ENABLE_PHYIE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT)) & ENET_MAC_INTERRUPT_ENABLE_PHYIE_MASK)

#define ENET_MAC_INTERRUPT_ENABLE_PMTIE_MASK     (0x10U)
#define ENET_MAC_INTERRUPT_ENABLE_PMTIE_SHIFT    (4U)
/*! PMTIE - PMT Interrupt Enable
 *  0b0..PMT Interrupt is disabled
 *  0b1..PMT Interrupt is enabled
 */
#define ENET_MAC_INTERRUPT_ENABLE_PMTIE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_ENABLE_PMTIE_SHIFT)) & ENET_MAC_INTERRUPT_ENABLE_PMTIE_MASK)

#define ENET_MAC_INTERRUPT_ENABLE_LPIIE_MASK     (0x20U)
#define ENET_MAC_INTERRUPT_ENABLE_LPIIE_SHIFT    (5U)
/*! LPIIE - LPI Interrupt Enable
 *  0b0..LPI Interrupt is disabled
 *  0b1..LPI Interrupt is enabled
 */
#define ENET_MAC_INTERRUPT_ENABLE_LPIIE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_ENABLE_LPIIE_SHIFT)) & ENET_MAC_INTERRUPT_ENABLE_LPIIE_MASK)

#define ENET_MAC_INTERRUPT_ENABLE_TSIE_MASK      (0x1000U)
#define ENET_MAC_INTERRUPT_ENABLE_TSIE_SHIFT     (12U)
/*! TSIE - Timestamp Interrupt Enable
 *  0b0..Timestamp Interrupt is disabled
 *  0b1..Timestamp Interrupt is enabled
 */
#define ENET_MAC_INTERRUPT_ENABLE_TSIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_ENABLE_TSIE_SHIFT)) & ENET_MAC_INTERRUPT_ENABLE_TSIE_MASK)

#define ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK   (0x2000U)
#define ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT  (13U)
/*! TXSTSIE - Transmit Status Interrupt Enable
 *  0b0..Timestamp Status Interrupt is disabled
 *  0b1..Timestamp Status Interrupt is enabled
 */
#define ENET_MAC_INTERRUPT_ENABLE_TXSTSIE(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT)) & ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK)

#define ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK   (0x4000U)
#define ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT  (14U)
/*! RXSTSIE - Receive Status Interrupt Enable
 *  0b0..Receive Status Interrupt is disabled
 *  0b1..Receive Status Interrupt is enabled
 */
#define ENET_MAC_INTERRUPT_ENABLE_RXSTSIE(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT)) & ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK)

#define ENET_MAC_INTERRUPT_ENABLE_MDIOIE_MASK    (0x40000U)
#define ENET_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT   (18U)
/*! MDIOIE - MDIO Interrupt Enable
 *  0b0..MDIO Interrupt is disabled
 *  0b1..MDIO Interrupt is enabled
 */
#define ENET_MAC_INTERRUPT_ENABLE_MDIOIE(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT)) & ENET_MAC_INTERRUPT_ENABLE_MDIOIE_MASK)
/*! @} */

/*! @name MAC_RX_TX_STATUS - Receive Transmit Status */
/*! @{ */

#define ENET_MAC_RX_TX_STATUS_TJT_MASK           (0x1U)
#define ENET_MAC_RX_TX_STATUS_TJT_SHIFT          (0U)
/*! TJT - Transmit Jabber Timeout
 *  0b0..No Transmit Jabber Timeout
 *  0b1..Transmit Jabber Timeout occurred
 */
#define ENET_MAC_RX_TX_STATUS_TJT(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_TX_STATUS_TJT_SHIFT)) & ENET_MAC_RX_TX_STATUS_TJT_MASK)

#define ENET_MAC_RX_TX_STATUS_NCARR_MASK         (0x2U)
#define ENET_MAC_RX_TX_STATUS_NCARR_SHIFT        (1U)
/*! NCARR - No Carrier
 *  0b0..Carrier is present
 *  0b1..No carrier
 */
#define ENET_MAC_RX_TX_STATUS_NCARR(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_TX_STATUS_NCARR_SHIFT)) & ENET_MAC_RX_TX_STATUS_NCARR_MASK)

#define ENET_MAC_RX_TX_STATUS_LCARR_MASK         (0x4U)
#define ENET_MAC_RX_TX_STATUS_LCARR_SHIFT        (2U)
/*! LCARR - Loss of Carrier
 *  0b0..Carrier is present
 *  0b1..Loss of carrier
 */
#define ENET_MAC_RX_TX_STATUS_LCARR(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_TX_STATUS_LCARR_SHIFT)) & ENET_MAC_RX_TX_STATUS_LCARR_MASK)

#define ENET_MAC_RX_TX_STATUS_EXDEF_MASK         (0x8U)
#define ENET_MAC_RX_TX_STATUS_EXDEF_SHIFT        (3U)
/*! EXDEF - Excessive Deferral
 *  0b0..No Excessive deferral
 *  0b1..Excessive deferral
 */
#define ENET_MAC_RX_TX_STATUS_EXDEF(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_TX_STATUS_EXDEF_SHIFT)) & ENET_MAC_RX_TX_STATUS_EXDEF_MASK)

#define ENET_MAC_RX_TX_STATUS_LCOL_MASK          (0x10U)
#define ENET_MAC_RX_TX_STATUS_LCOL_SHIFT         (4U)
/*! LCOL - Late Collision
 *  0b0..No collision
 *  0b1..Late collision is sensed
 */
#define ENET_MAC_RX_TX_STATUS_LCOL(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_TX_STATUS_LCOL_SHIFT)) & ENET_MAC_RX_TX_STATUS_LCOL_MASK)

#define ENET_MAC_RX_TX_STATUS_EXCOL_MASK         (0x20U)
#define ENET_MAC_RX_TX_STATUS_EXCOL_SHIFT        (5U)
/*! EXCOL - Excessive Collisions
 *  0b0..No collision
 *  0b1..Excessive collision is sensed
 */
#define ENET_MAC_RX_TX_STATUS_EXCOL(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_TX_STATUS_EXCOL_SHIFT)) & ENET_MAC_RX_TX_STATUS_EXCOL_MASK)

#define ENET_MAC_RX_TX_STATUS_RWT_MASK           (0x100U)
#define ENET_MAC_RX_TX_STATUS_RWT_SHIFT          (8U)
/*! RWT - Receive Watchdog Timeout
 *  0b0..No receive watchdog timeout
 *  0b1..Receive watchdog timed out
 */
#define ENET_MAC_RX_TX_STATUS_RWT(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_TX_STATUS_RWT_SHIFT)) & ENET_MAC_RX_TX_STATUS_RWT_MASK)
/*! @} */

/*! @name MAC_PMT_CONTROL_STATUS - PMT Control and Status */
/*! @{ */

#define ENET_MAC_PMT_CONTROL_STATUS_PWRDWN_MASK  (0x1U)
#define ENET_MAC_PMT_CONTROL_STATUS_PWRDWN_SHIFT (0U)
/*! PWRDWN - Power Down
 *  0b0..Power down is disabled
 *  0b1..Power down is enabled
 */
#define ENET_MAC_PMT_CONTROL_STATUS_PWRDWN(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_PWRDWN_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_PWRDWN_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_MGKPKTEN_MASK (0x2U)
#define ENET_MAC_PMT_CONTROL_STATUS_MGKPKTEN_SHIFT (1U)
/*! MGKPKTEN - Magic Packet Enable
 *  0b0..Magic Packet is disabled
 *  0b1..Magic Packet is enabled
 */
#define ENET_MAC_PMT_CONTROL_STATUS_MGKPKTEN(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_MGKPKTEN_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_MGKPKTEN_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_RWKPKTEN_MASK (0x4U)
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPKTEN_SHIFT (2U)
/*! RWKPKTEN - Remote Wake-Up Packet Enable
 *  0b0..Remote wake-up packet is disabled
 *  0b1..Remote wake-up packet is enabled
 */
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPKTEN(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_RWKPKTEN_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_RWKPKTEN_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_MGKPRCVD_MASK (0x20U)
#define ENET_MAC_PMT_CONTROL_STATUS_MGKPRCVD_SHIFT (5U)
/*! MGKPRCVD - Magic Packet Received
 *  0b0..No Magic packet is received
 *  0b1..Magic packet is received
 */
#define ENET_MAC_PMT_CONTROL_STATUS_MGKPRCVD(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_MGKPRCVD_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_MGKPRCVD_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_RWKPRCVD_MASK (0x40U)
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPRCVD_SHIFT (6U)
/*! RWKPRCVD - Remote Wake-Up Packet Received
 *  0b0..Remote wake-up packet is received
 *  0b1..Remote wake-up packet is received
 */
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPRCVD(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_RWKPRCVD_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_RWKPRCVD_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_GLBLUCAST_MASK (0x200U)
#define ENET_MAC_PMT_CONTROL_STATUS_GLBLUCAST_SHIFT (9U)
/*! GLBLUCAST - Global Unicast
 *  0b0..Global unicast is disabled
 *  0b1..Global unicast is enabled
 */
#define ENET_MAC_PMT_CONTROL_STATUS_GLBLUCAST(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_GLBLUCAST_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_GLBLUCAST_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_RWKPFE_MASK  (0x400U)
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPFE_SHIFT (10U)
/*! RWKPFE - Remote Wake-up Packet Forwarding Enable
 *  0b0..Remote Wake-up Packet Forwarding is disabled
 *  0b1..Remote Wake-up Packet Forwarding is enabled
 */
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPFE(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_RWKPFE_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_RWKPFE_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_RWKPTR_MASK  (0x1F000000U)
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPTR_SHIFT (24U)
/*! RWKPTR - Remote Wake-up FIFO Pointer */
#define ENET_MAC_PMT_CONTROL_STATUS_RWKPTR(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_RWKPTR_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_RWKPTR_MASK)

#define ENET_MAC_PMT_CONTROL_STATUS_RWKFILTRST_MASK (0x80000000U)
#define ENET_MAC_PMT_CONTROL_STATUS_RWKFILTRST_SHIFT (31U)
/*! RWKFILTRST - Remote Wake-Up Packet Filter Register Pointer Reset
 *  0b0..Remote Wake-Up Packet Filter Register Pointer is not Reset
 *  0b1..Remote Wake-Up Packet Filter Register Pointer is Reset
 */
#define ENET_MAC_PMT_CONTROL_STATUS_RWKFILTRST(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CONTROL_STATUS_RWKFILTRST_SHIFT)) & ENET_MAC_PMT_CONTROL_STATUS_RWKFILTRST_MASK)
/*! @} */

/*! @name MAC_RWK_PACKET_FILTER - Remote Wakeup Filter */
/*! @{ */

#define ENET_MAC_RWK_PACKET_FILTER_WKUPFRMFTR_MASK (0xFFFFFFFFU)
#define ENET_MAC_RWK_PACKET_FILTER_WKUPFRMFTR_SHIFT (0U)
/*! WKUPFRMFTR - RWK Packet Filter */
#define ENET_MAC_RWK_PACKET_FILTER_WKUPFRMFTR(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RWK_PACKET_FILTER_WKUPFRMFTR_SHIFT)) & ENET_MAC_RWK_PACKET_FILTER_WKUPFRMFTR_MASK)
/*! @} */

/*! @name MAC_LPI_CONTROL_STATUS - LPI Control and Status */
/*! @{ */

#define ENET_MAC_LPI_CONTROL_STATUS_TLPIEN_MASK  (0x1U)
#define ENET_MAC_LPI_CONTROL_STATUS_TLPIEN_SHIFT (0U)
/*! TLPIEN - Transmit LPI Entry
 *  0b0..Transmit LPI entry not detected
 *  0b1..Transmit LPI entry detected
 */
#define ENET_MAC_LPI_CONTROL_STATUS_TLPIEN(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_TLPIEN_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_TLPIEN_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_TLPIEX_MASK  (0x2U)
#define ENET_MAC_LPI_CONTROL_STATUS_TLPIEX_SHIFT (1U)
/*! TLPIEX - Transmit LPI Exit
 *  0b0..Transmit LPI exit not detected
 *  0b1..Transmit LPI exit detected
 */
#define ENET_MAC_LPI_CONTROL_STATUS_TLPIEX(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_TLPIEX_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_TLPIEX_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_RLPIEN_MASK  (0x4U)
#define ENET_MAC_LPI_CONTROL_STATUS_RLPIEN_SHIFT (2U)
/*! RLPIEN - Receive LPI Entry
 *  0b0..Receive LPI entry not detected
 *  0b1..Receive LPI entry detected
 */
#define ENET_MAC_LPI_CONTROL_STATUS_RLPIEN(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_RLPIEN_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_RLPIEN_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_RLPIEX_MASK  (0x8U)
#define ENET_MAC_LPI_CONTROL_STATUS_RLPIEX_SHIFT (3U)
/*! RLPIEX - Receive LPI Exit
 *  0b0..Receive LPI exit not detected
 *  0b1..Receive LPI exit detected
 */
#define ENET_MAC_LPI_CONTROL_STATUS_RLPIEX(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_RLPIEX_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_RLPIEX_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_TLPIST_MASK  (0x100U)
#define ENET_MAC_LPI_CONTROL_STATUS_TLPIST_SHIFT (8U)
/*! TLPIST - Transmit LPI State
 *  0b0..Transmit LPI state not detected
 *  0b1..Transmit LPI state detected
 */
#define ENET_MAC_LPI_CONTROL_STATUS_TLPIST(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_TLPIST_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_TLPIST_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_RLPIST_MASK  (0x200U)
#define ENET_MAC_LPI_CONTROL_STATUS_RLPIST_SHIFT (9U)
/*! RLPIST - Receive LPI State
 *  0b0..Receive LPI state not detected
 *  0b1..Receive LPI state detected
 */
#define ENET_MAC_LPI_CONTROL_STATUS_RLPIST(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_RLPIST_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_RLPIST_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_LPIEN_MASK   (0x10000U)
#define ENET_MAC_LPI_CONTROL_STATUS_LPIEN_SHIFT  (16U)
/*! LPIEN - LPI Enable
 *  0b0..LPI state is disabled
 *  0b1..LPI state is enabled
 */
#define ENET_MAC_LPI_CONTROL_STATUS_LPIEN(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_LPIEN_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_LPIEN_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_PLS_MASK     (0x20000U)
#define ENET_MAC_LPI_CONTROL_STATUS_PLS_SHIFT    (17U)
/*! PLS - PHY Link Status
 *  0b0..link is down
 *  0b1..link is okay (UP)
 */
#define ENET_MAC_LPI_CONTROL_STATUS_PLS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_PLS_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_PLS_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_LPITXA_MASK  (0x80000U)
#define ENET_MAC_LPI_CONTROL_STATUS_LPITXA_SHIFT (19U)
/*! LPITXA - LPI Tx Automate
 *  0b0..LPI Tx Automate is disabled
 *  0b1..LPI Tx Automate is enabled
 */
#define ENET_MAC_LPI_CONTROL_STATUS_LPITXA(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_LPITXA_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_LPITXA_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_LPIATE_MASK  (0x100000U)
#define ENET_MAC_LPI_CONTROL_STATUS_LPIATE_SHIFT (20U)
/*! LPIATE - LPI Timer Enable
 *  0b0..LPI Timer is disabled
 *  0b1..LPI Timer is enabled
 */
#define ENET_MAC_LPI_CONTROL_STATUS_LPIATE(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_LPIATE_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_LPIATE_MASK)

#define ENET_MAC_LPI_CONTROL_STATUS_LPITCSE_MASK (0x200000U)
#define ENET_MAC_LPI_CONTROL_STATUS_LPITCSE_SHIFT (21U)
/*! LPITCSE - LPI Tx Clock Stop Enable
 *  0b0..LPI Tx Clock Stop is disabled
 *  0b1..LPI Tx Clock Stop is enabled
 */
#define ENET_MAC_LPI_CONTROL_STATUS_LPITCSE(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CONTROL_STATUS_LPITCSE_SHIFT)) & ENET_MAC_LPI_CONTROL_STATUS_LPITCSE_MASK)
/*! @} */

/*! @name MAC_LPI_TIMERS_CONTROL - LPI Timers Control */
/*! @{ */

#define ENET_MAC_LPI_TIMERS_CONTROL_TWT_MASK     (0xFFFFU)
#define ENET_MAC_LPI_TIMERS_CONTROL_TWT_SHIFT    (0U)
/*! TWT - LPI TW Timer */
#define ENET_MAC_LPI_TIMERS_CONTROL_TWT(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_TIMERS_CONTROL_TWT_SHIFT)) & ENET_MAC_LPI_TIMERS_CONTROL_TWT_MASK)

#define ENET_MAC_LPI_TIMERS_CONTROL_LST_MASK     (0x3FF0000U)
#define ENET_MAC_LPI_TIMERS_CONTROL_LST_SHIFT    (16U)
/*! LST - LPI LS Timer */
#define ENET_MAC_LPI_TIMERS_CONTROL_LST(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_TIMERS_CONTROL_LST_SHIFT)) & ENET_MAC_LPI_TIMERS_CONTROL_LST_MASK)
/*! @} */

/*! @name MAC_LPI_ENTRY_TIMER - Tx LPI Entry Timer Control */
/*! @{ */

#define ENET_MAC_LPI_ENTRY_TIMER_LPIET_MASK      (0xFFFF8U)
#define ENET_MAC_LPI_ENTRY_TIMER_LPIET_SHIFT     (3U)
/*! LPIET - LPI Entry Timer */
#define ENET_MAC_LPI_ENTRY_TIMER_LPIET(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_ENTRY_TIMER_LPIET_SHIFT)) & ENET_MAC_LPI_ENTRY_TIMER_LPIET_MASK)
/*! @} */

/*! @name MAC_ONEUS_TIC_COUNTER - One-microsecond Reference Timer */
/*! @{ */

#define ENET_MAC_ONEUS_TIC_COUNTER_TIC_1US_CNTR_MASK (0xFFFU)
#define ENET_MAC_ONEUS_TIC_COUNTER_TIC_1US_CNTR_SHIFT (0U)
/*! TIC_1US_CNTR - 1US TIC Counter */
#define ENET_MAC_ONEUS_TIC_COUNTER_TIC_1US_CNTR(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ONEUS_TIC_COUNTER_TIC_1US_CNTR_SHIFT)) & ENET_MAC_ONEUS_TIC_COUNTER_TIC_1US_CNTR_MASK)
/*! @} */

/*! @name MAC_VERSION - MAC Version */
/*! @{ */

#define ENET_MAC_VERSION_SNPSVER_MASK            (0xFFU)
#define ENET_MAC_VERSION_SNPSVER_SHIFT           (0U)
/*! SNPSVER - Synopsys-defined Version */
#define ENET_MAC_VERSION_SNPSVER(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VERSION_SNPSVER_SHIFT)) & ENET_MAC_VERSION_SNPSVER_MASK)

#define ENET_MAC_VERSION_USERVER_MASK            (0xFF00U)
#define ENET_MAC_VERSION_USERVER_SHIFT           (8U)
/*! USERVER - User-defined Version */
#define ENET_MAC_VERSION_USERVER(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VERSION_USERVER_SHIFT)) & ENET_MAC_VERSION_USERVER_MASK)
/*! @} */

/*! @name MAC_DEBUG - MAC Debug */
/*! @{ */

#define ENET_MAC_DEBUG_RPESTS_MASK               (0x1U)
#define ENET_MAC_DEBUG_RPESTS_SHIFT              (0U)
/*! RPESTS - MAC GMII or MII Receive Protocol Engine Status
 *  0b0..MAC GMII or MII Receive Protocol Engine Status not detected
 *  0b1..MAC GMII or MII Receive Protocol Engine Status detected
 */
#define ENET_MAC_DEBUG_RPESTS(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DEBUG_RPESTS_SHIFT)) & ENET_MAC_DEBUG_RPESTS_MASK)

#define ENET_MAC_DEBUG_RFCFCSTS_MASK             (0x6U)
#define ENET_MAC_DEBUG_RFCFCSTS_SHIFT            (1U)
/*! RFCFCSTS - MAC Receive Packet Controller FIFO Status */
#define ENET_MAC_DEBUG_RFCFCSTS(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DEBUG_RFCFCSTS_SHIFT)) & ENET_MAC_DEBUG_RFCFCSTS_MASK)

#define ENET_MAC_DEBUG_TPESTS_MASK               (0x10000U)
#define ENET_MAC_DEBUG_TPESTS_SHIFT              (16U)
/*! TPESTS - MAC GMII or MII Transmit Protocol Engine Status
 *  0b0..MAC GMII or MII Transmit Protocol Engine Status not detected
 *  0b1..MAC GMII or MII Transmit Protocol Engine Status detected
 */
#define ENET_MAC_DEBUG_TPESTS(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DEBUG_TPESTS_SHIFT)) & ENET_MAC_DEBUG_TPESTS_MASK)

#define ENET_MAC_DEBUG_TFCSTS_MASK               (0x60000U)
#define ENET_MAC_DEBUG_TFCSTS_SHIFT              (17U)
/*! TFCSTS - MAC Transmit Packet Controller Status
 *  0b00..Idle state
 *  0b01..Waiting for one of the following: Status of the previous packet OR IPG or back off period to be over
 *  0b10..Generating and transmitting a Pause control packet (in full-duplex mode)
 *  0b11..Transferring input packet for transmission
 */
#define ENET_MAC_DEBUG_TFCSTS(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DEBUG_TFCSTS_SHIFT)) & ENET_MAC_DEBUG_TFCSTS_MASK)
/*! @} */

/*! @name MAC_HW_FEAT - Hardware Features 0..Hardware Features 3 */
/*! @{ */

#define ENET_MAC_HW_FEAT_MIISEL_MASK             (0x1U)
#define ENET_MAC_HW_FEAT_MIISEL_SHIFT            (0U)
/*! MIISEL - 10 or 100 Mbps Support
 *  0b0..No 10 or 100 Mbps support
 *  0b1..10 or 100 Mbps support
 */
#define ENET_MAC_HW_FEAT_MIISEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MIISEL_SHIFT)) & ENET_MAC_HW_FEAT_MIISEL_MASK)

#define ENET_MAC_HW_FEAT_NRVF_MASK               (0x7U)
#define ENET_MAC_HW_FEAT_NRVF_SHIFT              (0U)
/*! NRVF - Number of Extended VLAN Tag Filters Enabled
 *  0b000..No Extended Rx VLAN Filters
 *  0b001..4 Extended Rx VLAN Filters
 *  0b010..8 Extended Rx VLAN Filters
 *  0b011..16 Extended Rx VLAN Filters
 *  0b100..24 Extended Rx VLAN Filters
 *  0b101..32 Extended Rx VLAN Filters
 *  0b110..Reserved
 */
#define ENET_MAC_HW_FEAT_NRVF(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_NRVF_SHIFT)) & ENET_MAC_HW_FEAT_NRVF_MASK)

#define ENET_MAC_HW_FEAT_RXFIFOSIZE_MASK         (0x1FU)
#define ENET_MAC_HW_FEAT_RXFIFOSIZE_SHIFT        (0U)
/*! RXFIFOSIZE - MTL Receive FIFO Size
 *  0b00000..128 bytes
 *  0b00001..256 bytes
 *  0b00010..512 bytes
 *  0b00011..1024 bytes
 *  0b00100..2048 bytes
 *  0b00101..4096 bytes
 *  0b00110..8192 bytes
 *  0b00111..16384 bytes
 *  0b01000..32 KB
 *  0b01001..64 KB
 *  0b01010..128 KB
 *  0b01011..256 KB
 *  0b01100..Reserved
 */
#define ENET_MAC_HW_FEAT_RXFIFOSIZE(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXFIFOSIZE_SHIFT)) & ENET_MAC_HW_FEAT_RXFIFOSIZE_MASK)

#define ENET_MAC_HW_FEAT_RXQCNT_MASK             (0xFU)
#define ENET_MAC_HW_FEAT_RXQCNT_SHIFT            (0U)
/*! RXQCNT - Number of MTL Receive Queues
 *  0b0000..1 MTL Rx Queue
 *  0b0001..2 MTL Rx Queues
 *  0b0010..3 MTL Rx Queues
 *  0b0011..4 MTL Rx Queues
 *  0b0100..5 MTL Rx Queues
 *  0b0101..6 MTL Rx Queues
 *  0b0110..7 MTL Rx Queues
 *  0b0111..8 MTL Rx Queues
 */
#define ENET_MAC_HW_FEAT_RXQCNT(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXQCNT_SHIFT)) & ENET_MAC_HW_FEAT_RXQCNT_MASK)

#define ENET_MAC_HW_FEAT_GMIISEL_MASK            (0x2U)
#define ENET_MAC_HW_FEAT_GMIISEL_SHIFT           (1U)
/*! GMIISEL - 1000 Mbps Support
 *  0b0..No 1000 Mbps support
 *  0b1..1000 Mbps support
 */
#define ENET_MAC_HW_FEAT_GMIISEL(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_GMIISEL_SHIFT)) & ENET_MAC_HW_FEAT_GMIISEL_MASK)

#define ENET_MAC_HW_FEAT_HDSEL_MASK              (0x4U)
#define ENET_MAC_HW_FEAT_HDSEL_SHIFT             (2U)
/*! HDSEL - Half-duplex Support
 *  0b0..No Half-duplex support
 *  0b1..Half-duplex support
 */
#define ENET_MAC_HW_FEAT_HDSEL(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_HDSEL_SHIFT)) & ENET_MAC_HW_FEAT_HDSEL_MASK)

#define ENET_MAC_HW_FEAT_PCSSEL_MASK             (0x8U)
#define ENET_MAC_HW_FEAT_PCSSEL_SHIFT            (3U)
/*! PCSSEL - PCS Registers (TBI, SGMII, or RTBI PHY interface)
 *  0b0..No PCS Registers (TBI, SGMII, or RTBI PHY interface)
 *  0b1..PCS Registers (TBI, SGMII, or RTBI PHY interface)
 */
#define ENET_MAC_HW_FEAT_PCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_PCSSEL_SHIFT)) & ENET_MAC_HW_FEAT_PCSSEL_MASK)

#define ENET_MAC_HW_FEAT_CBTISEL_MASK            (0x10U)
#define ENET_MAC_HW_FEAT_CBTISEL_SHIFT           (4U)
/*! CBTISEL - Queue/Channel based VLAN tag insertion on Tx Enable
 *  0b0..Enable Queue/Channel based VLAN tag insertion on Tx feature is not selected
 *  0b1..Enable Queue/Channel based VLAN tag insertion on Tx feature is selected
 */
#define ENET_MAC_HW_FEAT_CBTISEL(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_CBTISEL_SHIFT)) & ENET_MAC_HW_FEAT_CBTISEL_MASK)

#define ENET_MAC_HW_FEAT_VLHASH_MASK             (0x10U)
#define ENET_MAC_HW_FEAT_VLHASH_SHIFT            (4U)
/*! VLHASH - VLAN Hash Filter Selected
 *  0b0..VLAN Hash Filter not selected
 *  0b1..VLAN Hash Filter selected
 */
#define ENET_MAC_HW_FEAT_VLHASH(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_VLHASH_SHIFT)) & ENET_MAC_HW_FEAT_VLHASH_MASK)

#define ENET_MAC_HW_FEAT_DVLAN_MASK              (0x20U)
#define ENET_MAC_HW_FEAT_DVLAN_SHIFT             (5U)
/*! DVLAN - Double VLAN Tag Processing Selected
 *  0b0..Double VLAN option is not selected
 *  0b1..Double VLAN option is selected
 */
#define ENET_MAC_HW_FEAT_DVLAN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_DVLAN_SHIFT)) & ENET_MAC_HW_FEAT_DVLAN_MASK)

#define ENET_MAC_HW_FEAT_SMASEL_MASK             (0x20U)
#define ENET_MAC_HW_FEAT_SMASEL_SHIFT            (5U)
/*! SMASEL - SMA (MDIO) Interface
 *  0b0..SMA (MDIO) Interface not selected
 *  0b1..SMA (MDIO) Interface selected
 */
#define ENET_MAC_HW_FEAT_SMASEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_SMASEL_SHIFT)) & ENET_MAC_HW_FEAT_SMASEL_MASK)

#define ENET_MAC_HW_FEAT_SPRAM_MASK              (0x20U)
#define ENET_MAC_HW_FEAT_SPRAM_SHIFT             (5U)
/*! SPRAM - Single Port RAM Enable
 *  0b0..Single Port RAM feature is not selected
 *  0b1..Single Port RAM feature is selected
 */
#define ENET_MAC_HW_FEAT_SPRAM(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_SPRAM_SHIFT)) & ENET_MAC_HW_FEAT_SPRAM_MASK)

#define ENET_MAC_HW_FEAT_RWKSEL_MASK             (0x40U)
#define ENET_MAC_HW_FEAT_RWKSEL_SHIFT            (6U)
/*! RWKSEL - PMT Remote Wake-up Packet Enable
 *  0b0..PMT Remote Wake-up Packet Enable option is not selected
 *  0b1..PMT Remote Wake-up Packet Enable option is selected
 */
#define ENET_MAC_HW_FEAT_RWKSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RWKSEL_SHIFT)) & ENET_MAC_HW_FEAT_RWKSEL_MASK)

#define ENET_MAC_HW_FEAT_TXFIFOSIZE_MASK         (0x7C0U)
#define ENET_MAC_HW_FEAT_TXFIFOSIZE_SHIFT        (6U)
/*! TXFIFOSIZE - MTL Transmit FIFO Size
 *  0b00000..128 bytes
 *  0b00001..256 bytes
 *  0b00010..512 bytes
 *  0b00011..1024 bytes
 *  0b00100..2048 bytes
 *  0b00101..4096 bytes
 *  0b00110..8192 bytes
 *  0b00111..16384 bytes
 *  0b01000..32 KB
 *  0b01001..64 KB
 *  0b01010..128 KB
 *  0b01011..Reserved
 */
#define ENET_MAC_HW_FEAT_TXFIFOSIZE(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXFIFOSIZE_SHIFT)) & ENET_MAC_HW_FEAT_TXFIFOSIZE_MASK)

#define ENET_MAC_HW_FEAT_TXQCNT_MASK             (0x3C0U)
#define ENET_MAC_HW_FEAT_TXQCNT_SHIFT            (6U)
/*! TXQCNT - Number of MTL Transmit Queues
 *  0b0000..1 MTL Tx Queue
 *  0b0001..2 MTL Tx Queues
 *  0b0010..3 MTL Tx Queues
 *  0b0011..4 MTL Tx Queues
 *  0b0100..5 MTL Tx Queues
 *  0b0101..6 MTL Tx Queues
 *  0b0110..7 MTL Tx Queues
 *  0b0111..8 MTL Tx Queues
 */
#define ENET_MAC_HW_FEAT_TXQCNT(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXQCNT_SHIFT)) & ENET_MAC_HW_FEAT_TXQCNT_MASK)

#define ENET_MAC_HW_FEAT_MGKSEL_MASK             (0x80U)
#define ENET_MAC_HW_FEAT_MGKSEL_SHIFT            (7U)
/*! MGKSEL - PMT Magic Packet Enable
 *  0b0..PMT Magic Packet Enable option is not selected
 *  0b1..PMT Magic Packet Enable option is selected
 */
#define ENET_MAC_HW_FEAT_MGKSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MGKSEL_SHIFT)) & ENET_MAC_HW_FEAT_MGKSEL_MASK)

#define ENET_MAC_HW_FEAT_MMCSEL_MASK             (0x100U)
#define ENET_MAC_HW_FEAT_MMCSEL_SHIFT            (8U)
/*! MMCSEL - RMON Module Enable
 *  0b0..RMON Module Enable option is not selected
 *  0b1..RMON Module Enable option is selected
 */
#define ENET_MAC_HW_FEAT_MMCSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MMCSEL_SHIFT)) & ENET_MAC_HW_FEAT_MMCSEL_MASK)

#define ENET_MAC_HW_FEAT_ARPOFFSEL_MASK          (0x200U)
#define ENET_MAC_HW_FEAT_ARPOFFSEL_SHIFT         (9U)
/*! ARPOFFSEL - ARP Offload Enabled
 *  0b0..ARP Offload Enable option is not selected
 *  0b1..ARP Offload Enable option is selected
 */
#define ENET_MAC_HW_FEAT_ARPOFFSEL(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ARPOFFSEL_SHIFT)) & ENET_MAC_HW_FEAT_ARPOFFSEL_MASK)

#define ENET_MAC_HW_FEAT_PDUPSEL_MASK            (0x200U)
#define ENET_MAC_HW_FEAT_PDUPSEL_SHIFT           (9U)
/*! PDUPSEL - Broadcast/Multicast Packet Duplication
 *  0b0..Broadcast/Multicast Packet Duplication feature is not selected
 *  0b1..Broadcast/Multicast Packet Duplication feature is selected
 */
#define ENET_MAC_HW_FEAT_PDUPSEL(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_PDUPSEL_SHIFT)) & ENET_MAC_HW_FEAT_PDUPSEL_MASK)

#define ENET_MAC_HW_FEAT_FRPSEL_MASK             (0x400U)
#define ENET_MAC_HW_FEAT_FRPSEL_SHIFT            (10U)
/*! FRPSEL - Flexible Receive Parser Selected
 *  0b0..Flexible Receive Parser feature is not selected
 *  0b1..Flexible Receive Parser feature is selected
 */
#define ENET_MAC_HW_FEAT_FRPSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_FRPSEL_SHIFT)) & ENET_MAC_HW_FEAT_FRPSEL_MASK)

#define ENET_MAC_HW_FEAT_FRPBS_MASK              (0x1800U)
#define ENET_MAC_HW_FEAT_FRPBS_SHIFT             (11U)
/*! FRPBS - Flexible Receive Parser Buffer size
 *  0b00..64 Bytes
 *  0b01..128 Bytes
 *  0b10..256 Bytes
 *  0b11..Reserved
 */
#define ENET_MAC_HW_FEAT_FRPBS(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_FRPBS_SHIFT)) & ENET_MAC_HW_FEAT_FRPBS_MASK)

#define ENET_MAC_HW_FEAT_OSTEN_MASK              (0x800U)
#define ENET_MAC_HW_FEAT_OSTEN_SHIFT             (11U)
/*! OSTEN - One-Step Timestamping Enable
 *  0b0..One-Step Timestamping feature is not selected
 *  0b1..One-Step Timestamping feature is selected
 */
#define ENET_MAC_HW_FEAT_OSTEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_OSTEN_SHIFT)) & ENET_MAC_HW_FEAT_OSTEN_MASK)

#define ENET_MAC_HW_FEAT_PTOEN_MASK              (0x1000U)
#define ENET_MAC_HW_FEAT_PTOEN_SHIFT             (12U)
/*! PTOEN - PTP Offload Enable
 *  0b0..PTP Offload feature is not selected
 *  0b1..PTP Offload feature is selected
 */
#define ENET_MAC_HW_FEAT_PTOEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_PTOEN_SHIFT)) & ENET_MAC_HW_FEAT_PTOEN_MASK)

#define ENET_MAC_HW_FEAT_RXCHCNT_MASK            (0xF000U)
#define ENET_MAC_HW_FEAT_RXCHCNT_SHIFT           (12U)
/*! RXCHCNT - Number of DMA Receive Channels
 *  0b0000..1 MTL Rx Channel
 *  0b0001..2 MTL Rx Channels
 *  0b0010..3 MTL Rx Channels
 *  0b0011..4 MTL Rx Channels
 *  0b0100..5 MTL Rx Channels
 *  0b0101..6 MTL Rx Channels
 *  0b0110..7 MTL Rx Channels
 *  0b0111..8 MTL Rx Channels
 */
#define ENET_MAC_HW_FEAT_RXCHCNT(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXCHCNT_SHIFT)) & ENET_MAC_HW_FEAT_RXCHCNT_MASK)

#define ENET_MAC_HW_FEAT_TSSEL_MASK              (0x1000U)
#define ENET_MAC_HW_FEAT_TSSEL_SHIFT             (12U)
/*! TSSEL - IEEE 1588-2008 Timestamp Enabled
 *  0b0..IEEE 1588-2008 Timestamp Enable option is not selected
 *  0b1..IEEE 1588-2008 Timestamp Enable option is selected
 */
#define ENET_MAC_HW_FEAT_TSSEL(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TSSEL_SHIFT)) & ENET_MAC_HW_FEAT_TSSEL_MASK)

#define ENET_MAC_HW_FEAT_ADVTHWORD_MASK          (0x2000U)
#define ENET_MAC_HW_FEAT_ADVTHWORD_SHIFT         (13U)
/*! ADVTHWORD - IEEE 1588 High Word Register Enable
 *  0b0..IEEE 1588 High Word Register option is not selected
 *  0b1..IEEE 1588 High Word Register option is selected
 */
#define ENET_MAC_HW_FEAT_ADVTHWORD(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ADVTHWORD_SHIFT)) & ENET_MAC_HW_FEAT_ADVTHWORD_MASK)

#define ENET_MAC_HW_FEAT_EEESEL_MASK             (0x2000U)
#define ENET_MAC_HW_FEAT_EEESEL_SHIFT            (13U)
/*! EEESEL - Energy Efficient Ethernet Enabled
 *  0b0..Energy Efficient Ethernet Enable option is not selected
 *  0b1..Energy Efficient Ethernet Enable option is selected
 */
#define ENET_MAC_HW_FEAT_EEESEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_EEESEL_SHIFT)) & ENET_MAC_HW_FEAT_EEESEL_MASK)

#define ENET_MAC_HW_FEAT_FRPES_MASK              (0x6000U)
#define ENET_MAC_HW_FEAT_FRPES_SHIFT             (13U)
/*! FRPES - Flexible Receive Parser Table Entries size
 *  0b00..64 Entries
 *  0b01..128 Entries
 *  0b10..256 Entries
 *  0b11..Reserved
 */
#define ENET_MAC_HW_FEAT_FRPES(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_FRPES_SHIFT)) & ENET_MAC_HW_FEAT_FRPES_MASK)

#define ENET_MAC_HW_FEAT_ADDR64_MASK             (0xC000U)
#define ENET_MAC_HW_FEAT_ADDR64_SHIFT            (14U)
/*! ADDR64 - Address Width.
 *  0b00..32
 *  0b01..40
 *  0b10..48
 *  0b11..Reserved
 */
#define ENET_MAC_HW_FEAT_ADDR64(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ADDR64_SHIFT)) & ENET_MAC_HW_FEAT_ADDR64_MASK)

#define ENET_MAC_HW_FEAT_TXCOESEL_MASK           (0x4000U)
#define ENET_MAC_HW_FEAT_TXCOESEL_SHIFT          (14U)
/*! TXCOESEL - Transmit Checksum Offload Enabled
 *  0b0..Transmit Checksum Offload Enable option is not selected
 *  0b1..Transmit Checksum Offload Enable option is selected
 */
#define ENET_MAC_HW_FEAT_TXCOESEL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXCOESEL_SHIFT)) & ENET_MAC_HW_FEAT_TXCOESEL_MASK)

#define ENET_MAC_HW_FEAT_DCBEN_MASK              (0x10000U)
#define ENET_MAC_HW_FEAT_DCBEN_SHIFT             (16U)
/*! DCBEN - DCB Feature Enable
 *  0b0..DCB Feature is not selected
 *  0b1..DCB Feature is selected
 */
#define ENET_MAC_HW_FEAT_DCBEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_DCBEN_SHIFT)) & ENET_MAC_HW_FEAT_DCBEN_MASK)

#define ENET_MAC_HW_FEAT_ESTSEL_MASK             (0x10000U)
#define ENET_MAC_HW_FEAT_ESTSEL_SHIFT            (16U)
/*! ESTSEL - Enhancements to Scheduled Traffic Enable
 *  0b0..Enable Enhancements to Scheduling Traffic feature is not selected
 *  0b1..Enable Enhancements to Scheduling Traffic feature is selected
 */
#define ENET_MAC_HW_FEAT_ESTSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ESTSEL_SHIFT)) & ENET_MAC_HW_FEAT_ESTSEL_MASK)

#define ENET_MAC_HW_FEAT_RDCSZ_MASK              (0x30000U)
#define ENET_MAC_HW_FEAT_RDCSZ_SHIFT             (16U)
/*! RDCSZ - Rx DMA Descriptor Cache Size in terms of 16 bytes descriptors: */
#define ENET_MAC_HW_FEAT_RDCSZ(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RDCSZ_SHIFT)) & ENET_MAC_HW_FEAT_RDCSZ_MASK)

#define ENET_MAC_HW_FEAT_RXCOESEL_MASK           (0x10000U)
#define ENET_MAC_HW_FEAT_RXCOESEL_SHIFT          (16U)
/*! RXCOESEL - Receive Checksum Offload Enabled
 *  0b0..Receive Checksum Offload Enable option is not selected
 *  0b1..Receive Checksum Offload Enable option is selected
 */
#define ENET_MAC_HW_FEAT_RXCOESEL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXCOESEL_SHIFT)) & ENET_MAC_HW_FEAT_RXCOESEL_MASK)

#define ENET_MAC_HW_FEAT_ESTDEP_MASK             (0xE0000U)
#define ENET_MAC_HW_FEAT_ESTDEP_SHIFT            (17U)
/*! ESTDEP - Depth of the Gate Control List
 *  0b000..No Depth configured
 *  0b001..64
 *  0b010..128
 *  0b011..256
 *  0b100..512
 *  0b101..1024
 *  0b110..Reserved
 */
#define ENET_MAC_HW_FEAT_ESTDEP(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ESTDEP_SHIFT)) & ENET_MAC_HW_FEAT_ESTDEP_MASK)

#define ENET_MAC_HW_FEAT_SPHEN_MASK              (0x20000U)
#define ENET_MAC_HW_FEAT_SPHEN_SHIFT             (17U)
/*! SPHEN - Split Header Feature Enable
 *  0b0..Split Header Feature is not selected
 *  0b1..Split Header Feature is selected
 */
#define ENET_MAC_HW_FEAT_SPHEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_SPHEN_SHIFT)) & ENET_MAC_HW_FEAT_SPHEN_MASK)

#define ENET_MAC_HW_FEAT_ADDMACADRSEL_MASK       (0x7C0000U)
#define ENET_MAC_HW_FEAT_ADDMACADRSEL_SHIFT      (18U)
/*! ADDMACADRSEL - MAC Addresses 1-31 Selected */
#define ENET_MAC_HW_FEAT_ADDMACADRSEL(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ADDMACADRSEL_SHIFT)) & ENET_MAC_HW_FEAT_ADDMACADRSEL_MASK)

#define ENET_MAC_HW_FEAT_TSOEN_MASK              (0x40000U)
#define ENET_MAC_HW_FEAT_TSOEN_SHIFT             (18U)
/*! TSOEN - TCP Segmentation Offload Enable
 *  0b0..TCP Segmentation Offload Feature is not selected
 *  0b1..TCP Segmentation Offload Feature is selected
 */
#define ENET_MAC_HW_FEAT_TSOEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TSOEN_SHIFT)) & ENET_MAC_HW_FEAT_TSOEN_MASK)

#define ENET_MAC_HW_FEAT_TXCHCNT_MASK            (0x3C0000U)
#define ENET_MAC_HW_FEAT_TXCHCNT_SHIFT           (18U)
/*! TXCHCNT - Number of DMA Transmit Channels
 *  0b0000..1 MTL Tx Channel
 *  0b0001..2 MTL Tx Channels
 *  0b0010..3 MTL Tx Channels
 *  0b0011..4 MTL Tx Channels
 *  0b0100..5 MTL Tx Channels
 *  0b0101..6 MTL Tx Channels
 *  0b0110..7 MTL Tx Channels
 *  0b0111..8 MTL Tx Channels
 */
#define ENET_MAC_HW_FEAT_TXCHCNT(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXCHCNT_SHIFT)) & ENET_MAC_HW_FEAT_TXCHCNT_MASK)

#define ENET_MAC_HW_FEAT_DBGMEMA_MASK            (0x80000U)
#define ENET_MAC_HW_FEAT_DBGMEMA_SHIFT           (19U)
/*! DBGMEMA - DMA Debug Registers Enable
 *  0b0..DMA Debug Registers option is not selected
 *  0b1..DMA Debug Registers option is selected
 */
#define ENET_MAC_HW_FEAT_DBGMEMA(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_DBGMEMA_SHIFT)) & ENET_MAC_HW_FEAT_DBGMEMA_MASK)

#define ENET_MAC_HW_FEAT_AVSEL_MASK              (0x100000U)
#define ENET_MAC_HW_FEAT_AVSEL_SHIFT             (20U)
/*! AVSEL - AV Feature Enable
 *  0b0..AV Feature is not selected
 *  0b1..AV Feature is selected
 */
#define ENET_MAC_HW_FEAT_AVSEL(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_AVSEL_SHIFT)) & ENET_MAC_HW_FEAT_AVSEL_MASK)

#define ENET_MAC_HW_FEAT_ESTWID_MASK             (0x300000U)
#define ENET_MAC_HW_FEAT_ESTWID_SHIFT            (20U)
/*! ESTWID - Width of the Time Interval field in the Gate Control List
 *  0b00..Width not configured
 *  0b01..16
 *  0b10..20
 *  0b11..24
 */
#define ENET_MAC_HW_FEAT_ESTWID(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ESTWID_SHIFT)) & ENET_MAC_HW_FEAT_ESTWID_MASK)

#define ENET_MAC_HW_FEAT_RAVSEL_MASK             (0x200000U)
#define ENET_MAC_HW_FEAT_RAVSEL_SHIFT            (21U)
/*! RAVSEL - Rx Side Only AV Feature Enable
 *  0b0..Rx Side Only AV Feature is not selected
 *  0b1..Rx Side Only AV Feature is selected
 */
#define ENET_MAC_HW_FEAT_RAVSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RAVSEL_SHIFT)) & ENET_MAC_HW_FEAT_RAVSEL_MASK)

#define ENET_MAC_HW_FEAT_TDCSZ_MASK              (0xC00000U)
#define ENET_MAC_HW_FEAT_TDCSZ_SHIFT             (22U)
/*! TDCSZ - Tx DMA Descriptor Cache Size in terms of 16 bytes descriptors: */
#define ENET_MAC_HW_FEAT_TDCSZ(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TDCSZ_SHIFT)) & ENET_MAC_HW_FEAT_TDCSZ_MASK)

#define ENET_MAC_HW_FEAT_MACADR32SEL_MASK        (0x800000U)
#define ENET_MAC_HW_FEAT_MACADR32SEL_SHIFT       (23U)
/*! MACADR32SEL - MAC Addresses 32-63 Selected
 *  0b0..MAC Addresses 32-63 Select option is not selected
 *  0b1..MAC Addresses 32-63 Select option is selected
 */
#define ENET_MAC_HW_FEAT_MACADR32SEL(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MACADR32SEL_SHIFT)) & ENET_MAC_HW_FEAT_MACADR32SEL_MASK)

#define ENET_MAC_HW_FEAT_POUOST_MASK             (0x800000U)
#define ENET_MAC_HW_FEAT_POUOST_SHIFT            (23U)
/*! POUOST - One Step for PTP over UDP/IP Feature Enable
 *  0b0..One Step for PTP over UDP/IP Feature is not selected
 *  0b1..One Step for PTP over UDP/IP Feature is selected
 */
#define ENET_MAC_HW_FEAT_POUOST(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_POUOST_SHIFT)) & ENET_MAC_HW_FEAT_POUOST_MASK)

#define ENET_MAC_HW_FEAT_HASHTBLSZ_MASK          (0x3000000U)
#define ENET_MAC_HW_FEAT_HASHTBLSZ_SHIFT         (24U)
/*! HASHTBLSZ - Hash Table Size
 *  0b00..No hash table
 *  0b01..64
 *  0b10..128
 *  0b11..256
 */
#define ENET_MAC_HW_FEAT_HASHTBLSZ(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_HASHTBLSZ_SHIFT)) & ENET_MAC_HW_FEAT_HASHTBLSZ_MASK)

#define ENET_MAC_HW_FEAT_MACADR64SEL_MASK        (0x1000000U)
#define ENET_MAC_HW_FEAT_MACADR64SEL_SHIFT       (24U)
/*! MACADR64SEL - MAC Addresses 64-127 Selected
 *  0b0..MAC Addresses 64-127 Select option is not selected
 *  0b1..MAC Addresses 64-127 Select option is selected
 */
#define ENET_MAC_HW_FEAT_MACADR64SEL(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MACADR64SEL_SHIFT)) & ENET_MAC_HW_FEAT_MACADR64SEL_MASK)

#define ENET_MAC_HW_FEAT_PPSOUTNUM_MASK          (0x7000000U)
#define ENET_MAC_HW_FEAT_PPSOUTNUM_SHIFT         (24U)
/*! PPSOUTNUM - Number of PPS Outputs
 *  0b000..No PPS output
 *  0b001..1 PPS output
 *  0b010..2 PPS output
 *  0b011..3 PPS output
 *  0b100..4 PPS output
 *  0b101..Reserved
 */
#define ENET_MAC_HW_FEAT_PPSOUTNUM(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_PPSOUTNUM_SHIFT)) & ENET_MAC_HW_FEAT_PPSOUTNUM_MASK)

#define ENET_MAC_HW_FEAT_TSSTSSEL_MASK           (0x6000000U)
#define ENET_MAC_HW_FEAT_TSSTSSEL_SHIFT          (25U)
/*! TSSTSSEL - Timestamp System Time Source
 *  0b00..Internal
 *  0b01..External
 *  0b10..Both
 *  0b11..Reserved
 */
#define ENET_MAC_HW_FEAT_TSSTSSEL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TSSTSSEL_SHIFT)) & ENET_MAC_HW_FEAT_TSSTSSEL_MASK)

#define ENET_MAC_HW_FEAT_FPESEL_MASK             (0x4000000U)
#define ENET_MAC_HW_FEAT_FPESEL_SHIFT            (26U)
/*! FPESEL - Frame Preemption Enable
 *  0b0..Frame Preemption Enable feature is not selected
 *  0b1..Frame Preemption Enable feature is selected
 */
#define ENET_MAC_HW_FEAT_FPESEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_FPESEL_SHIFT)) & ENET_MAC_HW_FEAT_FPESEL_MASK)

#define ENET_MAC_HW_FEAT_L3L4FNUM_MASK           (0x78000000U)
#define ENET_MAC_HW_FEAT_L3L4FNUM_SHIFT          (27U)
/*! L3L4FNUM - Total number of L3 or L4 Filters
 *  0b0000..No L3 or L4 Filter
 *  0b0001..1 L3 or L4 Filter
 *  0b0010..2 L3 or L4 Filters
 *  0b0011..3 L3 or L4 Filters
 *  0b0100..4 L3 or L4 Filters
 *  0b0101..5 L3 or L4 Filters
 *  0b0110..6 L3 or L4 Filters
 *  0b0111..7 L3 or L4 Filters
 *  0b1000..8 L3 or L4 Filters
 */
#define ENET_MAC_HW_FEAT_L3L4FNUM(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_L3L4FNUM_SHIFT)) & ENET_MAC_HW_FEAT_L3L4FNUM_MASK)

#define ENET_MAC_HW_FEAT_SAVLANINS_MASK          (0x8000000U)
#define ENET_MAC_HW_FEAT_SAVLANINS_SHIFT         (27U)
/*! SAVLANINS - Source Address or VLAN Insertion Enable
 *  0b0..Source Address or VLAN Insertion Enable option is not selected
 *  0b1..Source Address or VLAN Insertion Enable option is selected
 */
#define ENET_MAC_HW_FEAT_SAVLANINS(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_SAVLANINS_SHIFT)) & ENET_MAC_HW_FEAT_SAVLANINS_MASK)

#define ENET_MAC_HW_FEAT_TBSSEL_MASK             (0x8000000U)
#define ENET_MAC_HW_FEAT_TBSSEL_SHIFT            (27U)
/*! TBSSEL - Time Based Scheduling Enable
 *  0b0..Time Based Scheduling Enable feature is not selected
 *  0b1..Time Based Scheduling Enable feature is selected
 */
#define ENET_MAC_HW_FEAT_TBSSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TBSSEL_SHIFT)) & ENET_MAC_HW_FEAT_TBSSEL_MASK)

#define ENET_MAC_HW_FEAT_ACTPHYSEL_MASK          (0x70000000U)
#define ENET_MAC_HW_FEAT_ACTPHYSEL_SHIFT         (28U)
/*! ACTPHYSEL - Active PHY Selected
 *  0b000..GMII or MII
 *  0b001..RGMII
 *  0b010..SGMII
 *  0b011..TBI
 *  0b100..RMII
 *  0b101..RTBI
 *  0b110..SMII
 *  0b111..RevMII
 */
#define ENET_MAC_HW_FEAT_ACTPHYSEL(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ACTPHYSEL_SHIFT)) & ENET_MAC_HW_FEAT_ACTPHYSEL_MASK)

#define ENET_MAC_HW_FEAT_ASP_MASK                (0x30000000U)
#define ENET_MAC_HW_FEAT_ASP_SHIFT               (28U)
/*! ASP - Automotive Safety Package
 *  0b00..No Safety features selected
 *  0b01..Only "ECC protection for external memory" feature is selected
 *  0b10..All the Automotive Safety features are selected without the "Parity Port Enable for external interface" feature
 *  0b11..All the Automotive Safety features are selected with the "Parity Port Enable for external interface" feature
 */
#define ENET_MAC_HW_FEAT_ASP(x)                  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ASP_SHIFT)) & ENET_MAC_HW_FEAT_ASP_MASK)

#define ENET_MAC_HW_FEAT_AUXSNAPNUM_MASK         (0x70000000U)
#define ENET_MAC_HW_FEAT_AUXSNAPNUM_SHIFT        (28U)
/*! AUXSNAPNUM - Number of Auxiliary Snapshot Inputs
 *  0b000..No auxiliary input
 *  0b001..1 auxiliary input
 *  0b010..2 auxiliary input
 *  0b011..3 auxiliary input
 *  0b100..4 auxiliary input
 *  0b101..Reserved
 */
#define ENET_MAC_HW_FEAT_AUXSNAPNUM(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_AUXSNAPNUM_SHIFT)) & ENET_MAC_HW_FEAT_AUXSNAPNUM_MASK)
/*! @} */

/*! @name MAC_MDIO_ADDRESS - MDIO Address */
/*! @{ */

#define ENET_MAC_MDIO_ADDRESS_GB_MASK            (0x1U)
#define ENET_MAC_MDIO_ADDRESS_GB_SHIFT           (0U)
/*! GB - GMII Busy
 *  0b0..GMII Busy is disabled
 *  0b1..GMII Busy is enabled
 */
#define ENET_MAC_MDIO_ADDRESS_GB(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_GB_SHIFT)) & ENET_MAC_MDIO_ADDRESS_GB_MASK)

#define ENET_MAC_MDIO_ADDRESS_C45E_MASK          (0x2U)
#define ENET_MAC_MDIO_ADDRESS_C45E_SHIFT         (1U)
/*! C45E - Clause 45 PHY Enable
 *  0b0..Clause 45 PHY is disabled
 *  0b1..Clause 45 PHY is enabled
 */
#define ENET_MAC_MDIO_ADDRESS_C45E(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_C45E_SHIFT)) & ENET_MAC_MDIO_ADDRESS_C45E_MASK)

#define ENET_MAC_MDIO_ADDRESS_GOC_0_MASK         (0x4U)
#define ENET_MAC_MDIO_ADDRESS_GOC_0_SHIFT        (2U)
/*! GOC_0 - GMII Operation Command 0
 *  0b0..GMII Operation Command 0 is disabled
 *  0b1..GMII Operation Command 0 is enabled
 */
#define ENET_MAC_MDIO_ADDRESS_GOC_0(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_GOC_0_SHIFT)) & ENET_MAC_MDIO_ADDRESS_GOC_0_MASK)

#define ENET_MAC_MDIO_ADDRESS_GOC_1_MASK         (0x8U)
#define ENET_MAC_MDIO_ADDRESS_GOC_1_SHIFT        (3U)
/*! GOC_1 - GMII Operation Command 1
 *  0b0..GMII Operation Command 1 is disabled
 *  0b1..GMII Operation Command 1 is enabled
 */
#define ENET_MAC_MDIO_ADDRESS_GOC_1(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_GOC_1_SHIFT)) & ENET_MAC_MDIO_ADDRESS_GOC_1_MASK)

#define ENET_MAC_MDIO_ADDRESS_SKAP_MASK          (0x10U)
#define ENET_MAC_MDIO_ADDRESS_SKAP_SHIFT         (4U)
/*! SKAP - Skip Address Packet
 *  0b0..Skip Address Packet is disabled
 *  0b1..Skip Address Packet is enabled
 */
#define ENET_MAC_MDIO_ADDRESS_SKAP(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_SKAP_SHIFT)) & ENET_MAC_MDIO_ADDRESS_SKAP_MASK)

#define ENET_MAC_MDIO_ADDRESS_CR_MASK            (0xF00U)
#define ENET_MAC_MDIO_ADDRESS_CR_SHIFT           (8U)
/*! CR - CR */
#define ENET_MAC_MDIO_ADDRESS_CR(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_CR_SHIFT)) & ENET_MAC_MDIO_ADDRESS_CR_MASK)

#define ENET_MAC_MDIO_ADDRESS_NTC_MASK           (0x7000U)
#define ENET_MAC_MDIO_ADDRESS_NTC_SHIFT          (12U)
/*! NTC - NTC */
#define ENET_MAC_MDIO_ADDRESS_NTC(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_NTC_SHIFT)) & ENET_MAC_MDIO_ADDRESS_NTC_MASK)

#define ENET_MAC_MDIO_ADDRESS_RDA_MASK           (0x1F0000U)
#define ENET_MAC_MDIO_ADDRESS_RDA_SHIFT          (16U)
/*! RDA - Register/Device Address */
#define ENET_MAC_MDIO_ADDRESS_RDA(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_RDA_SHIFT)) & ENET_MAC_MDIO_ADDRESS_RDA_MASK)

#define ENET_MAC_MDIO_ADDRESS_PA_MASK            (0x3E00000U)
#define ENET_MAC_MDIO_ADDRESS_PA_SHIFT           (21U)
/*! PA - Physical Layer Address */
#define ENET_MAC_MDIO_ADDRESS_PA(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_PA_SHIFT)) & ENET_MAC_MDIO_ADDRESS_PA_MASK)

#define ENET_MAC_MDIO_ADDRESS_BTB_MASK           (0x4000000U)
#define ENET_MAC_MDIO_ADDRESS_BTB_SHIFT          (26U)
/*! BTB - Back to Back transactions
 *  0b0..Back to Back transactions disabled
 *  0b1..Back to Back transactions enabled
 */
#define ENET_MAC_MDIO_ADDRESS_BTB(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_BTB_SHIFT)) & ENET_MAC_MDIO_ADDRESS_BTB_MASK)

#define ENET_MAC_MDIO_ADDRESS_PSE_MASK           (0x8000000U)
#define ENET_MAC_MDIO_ADDRESS_PSE_SHIFT          (27U)
/*! PSE - Preamble Suppression Enable
 *  0b0..Preamble Suppression disabled
 *  0b1..Preamble Suppression enabled
 */
#define ENET_MAC_MDIO_ADDRESS_PSE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDRESS_PSE_SHIFT)) & ENET_MAC_MDIO_ADDRESS_PSE_MASK)
/*! @} */

/*! @name MAC_MDIO_DATA - MAC MDIO Data */
/*! @{ */

#define ENET_MAC_MDIO_DATA_GD_MASK               (0xFFFFU)
#define ENET_MAC_MDIO_DATA_GD_SHIFT              (0U)
/*! GD - GMII Data */
#define ENET_MAC_MDIO_DATA_GD(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_DATA_GD_SHIFT)) & ENET_MAC_MDIO_DATA_GD_MASK)

#define ENET_MAC_MDIO_DATA_RA_MASK               (0xFFFF0000U)
#define ENET_MAC_MDIO_DATA_RA_SHIFT              (16U)
/*! RA - Register Address */
#define ENET_MAC_MDIO_DATA_RA(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_DATA_RA_SHIFT)) & ENET_MAC_MDIO_DATA_RA_MASK)
/*! @} */

/*! @name MAC_CSR_SW_CTRL - CSR Software Control */
/*! @{ */

#define ENET_MAC_CSR_SW_CTRL_RCWE_MASK           (0x1U)
#define ENET_MAC_CSR_SW_CTRL_RCWE_SHIFT          (0U)
/*! RCWE - Register Clear on Write 1 Enable
 *  0b0..Register Clear on Write 1 is disabled
 *  0b1..Register Clear on Write 1 is enabled
 */
#define ENET_MAC_CSR_SW_CTRL_RCWE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CSR_SW_CTRL_RCWE_SHIFT)) & ENET_MAC_CSR_SW_CTRL_RCWE_MASK)
/*! @} */

/*! @name MAC_ADDRESS0_HIGH - MAC Address0 High */
/*! @{ */

#define ENET_MAC_ADDRESS0_HIGH_ADDRHI_MASK       (0xFFFFU)
#define ENET_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT      (0U)
/*! ADDRHI - MAC Address0[47:32] */
#define ENET_MAC_ADDRESS0_HIGH_ADDRHI(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT)) & ENET_MAC_ADDRESS0_HIGH_ADDRHI_MASK)

#define ENET_MAC_ADDRESS0_HIGH_DCS_MASK          (0x30000U)
#define ENET_MAC_ADDRESS0_HIGH_DCS_SHIFT         (16U)
/*! DCS - DMA Channel Select */
#define ENET_MAC_ADDRESS0_HIGH_DCS(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDRESS0_HIGH_DCS_SHIFT)) & ENET_MAC_ADDRESS0_HIGH_DCS_MASK)

#define ENET_MAC_ADDRESS0_HIGH_AE_MASK           (0x80000000U)
#define ENET_MAC_ADDRESS0_HIGH_AE_SHIFT          (31U)
/*! AE - Address Enable
 *  0b0..INVALID : This bit must be always set to 1
 *  0b1..This bit is always set to 1
 */
#define ENET_MAC_ADDRESS0_HIGH_AE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDRESS0_HIGH_AE_SHIFT)) & ENET_MAC_ADDRESS0_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDRESS0_LOW - MAC Address0 Low */
/*! @{ */

#define ENET_MAC_ADDRESS0_LOW_ADDRLO_MASK        (0xFFFFFFFFU)
#define ENET_MAC_ADDRESS0_LOW_ADDRLO_SHIFT       (0U)
/*! ADDRLO - MAC Address0[31:0] */
#define ENET_MAC_ADDRESS0_LOW_ADDRLO(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDRESS0_LOW_ADDRLO_SHIFT)) & ENET_MAC_ADDRESS0_LOW_ADDRLO_MASK)
/*! @} */

/*! @name INDIR_ACCESS_CTRL - Indirect Access Control */
/*! @{ */

#define ENET_INDIR_ACCESS_CTRL_OB_MASK           (0x1U)
#define ENET_INDIR_ACCESS_CTRL_OB_SHIFT          (0U)
/*! OB - Operation Busy. */
#define ENET_INDIR_ACCESS_CTRL_OB(x)             (((uint32_t)(((uint32_t)(x)) << ENET_INDIR_ACCESS_CTRL_OB_SHIFT)) & ENET_INDIR_ACCESS_CTRL_OB_MASK)

#define ENET_INDIR_ACCESS_CTRL_COM_MASK          (0x2U)
#define ENET_INDIR_ACCESS_CTRL_COM_SHIFT         (1U)
/*! COM - Command type
 *  0b0..Write operation
 *  0b1..Read operation
 */
#define ENET_INDIR_ACCESS_CTRL_COM(x)            (((uint32_t)(((uint32_t)(x)) << ENET_INDIR_ACCESS_CTRL_COM_SHIFT)) & ENET_INDIR_ACCESS_CTRL_COM_MASK)

#define ENET_INDIR_ACCESS_CTRL_AUTO_MASK         (0x20U)
#define ENET_INDIR_ACCESS_CTRL_AUTO_SHIFT        (5U)
/*! AUTO - Auto increment */
#define ENET_INDIR_ACCESS_CTRL_AUTO(x)           (((uint32_t)(((uint32_t)(x)) << ENET_INDIR_ACCESS_CTRL_AUTO_SHIFT)) & ENET_INDIR_ACCESS_CTRL_AUTO_MASK)

#define ENET_INDIR_ACCESS_CTRL_AOFF_MASK         (0xFF00U)
#define ENET_INDIR_ACCESS_CTRL_AOFF_SHIFT        (8U)
/*! AOFF - Address Offset */
#define ENET_INDIR_ACCESS_CTRL_AOFF(x)           (((uint32_t)(((uint32_t)(x)) << ENET_INDIR_ACCESS_CTRL_AOFF_SHIFT)) & ENET_INDIR_ACCESS_CTRL_AOFF_MASK)

#define ENET_INDIR_ACCESS_CTRL_MSEL_MASK         (0xF0000U)
#define ENET_INDIR_ACCESS_CTRL_MSEL_SHIFT        (16U)
/*! MSEL - Mode Select */
#define ENET_INDIR_ACCESS_CTRL_MSEL(x)           (((uint32_t)(((uint32_t)(x)) << ENET_INDIR_ACCESS_CTRL_MSEL_SHIFT)) & ENET_INDIR_ACCESS_CTRL_MSEL_MASK)
/*! @} */

/*! @name INDIR_ACCESS_DATA - Indirect Access Data */
/*! @{ */

#define ENET_INDIR_ACCESS_DATA_DATA_MASK         (0xFFFFFFFFU)
#define ENET_INDIR_ACCESS_DATA_DATA_SHIFT        (0U)
/*! DATA - This field contains data to read/write for Indirect address access associated with MAC_Indir_Access_Ctrl */
#define ENET_INDIR_ACCESS_DATA_DATA(x)           (((uint32_t)(((uint32_t)(x)) << ENET_INDIR_ACCESS_DATA_DATA_SHIFT)) & ENET_INDIR_ACCESS_DATA_DATA_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_CONTROL - Timestamp Control */
/*! @{ */

#define ENET_MAC_TIMESTAMP_CONTROL_TSENA_MASK    (0x1U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT   (0U)
/*! TSENA - Enable Timestamp
 *  0b0..Timestamp is disabled
 *  0b1..Timestamp is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSENA(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSENA_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK (0x2U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT (1U)
/*! TSCFUPDT - Fine or Coarse Timestamp Update
 *  0b0..Coarse method is used to update system timestamp
 *  0b1..Fine method is used to update system timestamp
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSINIT_MASK   (0x4U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT  (2U)
/*! TSINIT - Initialize Timestamp
 *  0b0..Timestamp is not initialized
 *  0b1..Timestamp is initialized
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSINIT(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSINIT_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK   (0x8U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT  (3U)
/*! TSUPDT - Update Timestamp
 *  0b0..Timestamp is not updated
 *  0b1..Timestamp is updated
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSUPDT(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSTRIG_MASK   (0x10U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSTRIG_SHIFT  (4U)
/*! TSTRIG - Enable Timestamp Interrupt Trigger
 *  0b0..Timestamp Interrupt Trigger is not enabled
 *  0b1..Timestamp Interrupt Trigger is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSTRIG(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSTRIG_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSTRIG_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK (0x20U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT (5U)
/*! TSADDREG - Update Addend Register
 *  0b0..Addend Register is not updated
 *  0b1..Addend Register is updated
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSADDREG(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSENALL_MASK  (0x100U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT (8U)
/*! TSENALL - Enable Timestamp for All Packets
 *  0b0..Timestamp for All Packets disabled
 *  0b1..Timestamp for All Packets enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSENALL(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSENALL_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK (0x200U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT (9U)
/*! TSCTRLSSR - Timestamp Digital or Binary Rollover Control
 *  0b0..Timestamp Digital Rollover Control is disabled and Binary Rollover Control is enabled
 *  0b1..Timestamp Digital Rollover Control is enabled and Binary Rollover Control is disabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK (0x400U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT (10U)
/*! TSVER2ENA - Enable PTP Packet Processing for Version 2 Format
 *  0b0..PTP Packet Processing for Version 2 Format is disabled
 *  0b1..PTP Packet Processing for Version 2 Format is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK  (0x800U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT (11U)
/*! TSIPENA - Enable Processing of PTP over Ethernet Packets
 *  0b0..Processing of PTP over Ethernet Packets is disabled
 *  0b1..Processing of PTP over Ethernet Packets is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPENA(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK (0x1000U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT (12U)
/*! TSIPV6ENA - Enable Processing of PTP Packets Sent over IPv6-UDP
 *  0b0..Processing of PTP Packets Sent over IPv6-UDP is disabled
 *  0b1..Processing of PTP Packets Sent over IPv6-UDP is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK (0x2000U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT (13U)
/*! TSIPV4ENA - Enable Processing of PTP Packets Sent over IPv4-UDP
 *  0b0..Processing of PTP Packets Sent over IPv4-UDP is disabled
 *  0b1..Processing of PTP Packets Sent over IPv4-UDP is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK (0x4000U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT (14U)
/*! TSEVNTENA - Enable Timestamp Snapshot for Event Messages
 *  0b0..Timestamp Snapshot for Event Messages is disabled
 *  0b1..Timestamp Snapshot for Event Messages is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK (0x8000U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT (15U)
/*! TSMSTRENA - Enable Snapshot for Messages Relevant to Master
 *  0b0..Snapshot for Messages Relevant to Master is disabled
 *  0b1..Snapshot for Messages Relevant to Master is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK (0x30000U)
#define ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT (16U)
/*! SNAPTYPSEL - Select PTP packets for Taking Snapshots */
#define ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK (0x40000U)
#define ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT (18U)
/*! TSENMACADDR - Enable MAC Address for PTP Packet Filtering
 *  0b0..MAC Address for PTP Packet Filtering is disabled
 *  0b1..MAC Address for PTP Packet Filtering is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_ESTI_MASK     (0x100000U)
#define ENET_MAC_TIMESTAMP_CONTROL_ESTI_SHIFT    (20U)
/*! ESTI - External System Time Input
 *  0b0..External System Time Input is disabled
 *  0b1..External System Time Input is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_ESTI(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_ESTI_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_ESTI_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK (0x1000000U)
#define ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT (24U)
/*! TXTSSTSM - Transmit Timestamp Status Mode
 *  0b0..Transmit Timestamp Status Mode is disabled
 *  0b1..Transmit Timestamp Status Mode is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK)

#define ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK (0x10000000U)
#define ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT (28U)
/*! AV8021ASMEN - AV 802.
 *  0b0..AV 802.1AS Mode is disabled
 *  0b1..AV 802.1AS Mode is enabled
 */
#define ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT)) & ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK)
/*! @} */

/*! @name MAC_SUB_SECOND_INCREMENT - Subsecond Increment */
/*! @{ */

#define ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK (0xFF0000U)
#define ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT (16U)
/*! SNSINC - Sub-nanosecond Increment Value */
#define ENET_MAC_SUB_SECOND_INCREMENT_SNSINC(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT)) & ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_SECONDS - System Time Seconds */
/*! @{ */

#define ENET_MAC_SYSTEM_TIME_SECONDS_TSS_MASK    (0xFFFFFFFFU)
#define ENET_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT   (0U)
/*! TSS - Timestamp Second */
#define ENET_MAC_SYSTEM_TIME_SECONDS_TSS(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT)) & ENET_MAC_SYSTEM_TIME_SECONDS_TSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_NANOSECONDS - System Time Nanoseconds */
/*! @{ */

#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK (0x7FFFFFFFU)
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT (0U)
/*! TSSS - Timestamp Sub Seconds */
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT)) & ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_SECONDS_UPDATE - System Time Seconds Update */
/*! @{ */

#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK (0xFFFFFFFFU)
#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT (0U)
/*! TSS - Timestamp Seconds */
#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT)) & ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_NANOSECONDS_UPDATE - System Time Nanoseconds Update */
/*! @{ */

#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK (0x7FFFFFFFU)
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT (0U)
/*! TSSS - Timestamp Sub Seconds */
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT)) & ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK)

#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK (0x80000000U)
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT (31U)
/*! ADDSUB - Add or Subtract Time
 *  0b0..Add time
 *  0b1..Subtract time
 */
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT)) & ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_ADDEND - Timestamp Addend */
/*! @{ */

#define ENET_MAC_TIMESTAMP_ADDEND_TSAR_MASK      (0xFFFFFFFFU)
#define ENET_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT     (0U)
/*! TSAR - Timestamp Addend Register */
#define ENET_MAC_TIMESTAMP_ADDEND_TSAR(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT)) & ENET_MAC_TIMESTAMP_ADDEND_TSAR_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_STATUS - Timestamp Status */
/*! @{ */

#define ENET_MAC_TIMESTAMP_STATUS_TSSOVF_MASK    (0x1U)
#define ENET_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT   (0U)
/*! TSSOVF - Timestamp Seconds Overflow
 *  0b0..Timestamp Seconds Overflow status not detected
 *  0b1..Timestamp Seconds Overflow status detected
 */
#define ENET_MAC_TIMESTAMP_STATUS_TSSOVF(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT)) & ENET_MAC_TIMESTAMP_STATUS_TSSOVF_MASK)

#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK  (0x2U)
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT (1U)
/*! TSTARGT0 - Timestamp Target Time Reached
 *  0b0..Timestamp Target Time Reached status not detected
 *  0b1..Timestamp Target Time Reached status detected
 */
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT0(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT)) & ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK)

#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK (0x8U)
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT (3U)
/*! TSTRGTERR0 - Timestamp Target Time Error
 *  0b0..Timestamp Target Time Error status not detected
 *  0b1..Timestamp Target Time Error status detected
 */
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT)) & ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK)

#define ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK   (0x8000U)
#define ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT  (15U)
/*! TXTSSIS - Tx Timestamp Status Interrupt Status
 *  0b0..Tx Timestamp Status Interrupt status not detected
 *  0b1..Tx Timestamp Status Interrupt status detected
 */
#define ENET_MAC_TIMESTAMP_STATUS_TXTSSIS(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT)) & ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_NANOSECONDS - Transmit Timestamp Status Nanoseconds */
/*! @{ */

#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK (0x7FFFFFFFU)
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT (0U)
/*! TXTSSLO - Transmit Timestamp Status Low */
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT)) & ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK)

#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK (0x80000000U)
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT (31U)
/*! TXTSSMIS - TXTSSMIS
 *  0b0..Transmit Timestamp Status Missed status not detected
 *  0b1..Transmit Timestamp Status Missed status detected
 */
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT)) & ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_SECONDS - Transmit Timestamp Status Seconds */
/*! @{ */

#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK (0xFFFFFFFFU)
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT (0U)
/*! TXTSSHI - Transmit Timestamp Status High */
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT)) & ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND - Timestamp Ingress Correction Nanosecond */
/*! @{ */

#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK (0xFFFFFFFFU)
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT (0U)
/*! TSIC - Timestamp Ingress Correction */
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT)) & ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND - Timestamp Egress Correction Nanosecond */
/*! @{ */

#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK (0xFFFFFFFFU)
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT (0U)
/*! TSEC - Timestamp Egress Correction */
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT)) & ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_LATENCY - Timestamp Ingress Latency */
/*! @{ */

#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK (0xFF00U)
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT (8U)
/*! ITLSNS - ITLSNS */
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT)) & ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK)

#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK (0xFFF0000U)
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT (16U)
/*! ITLNS - ITLNS */
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT)) & ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_LATENCY - Timestamp Egress Latency */
/*! @{ */

#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK (0xFF00U)
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT (8U)
/*! ETLSNS - Egress Timestamp Latency, in sub-nanoseconds */
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT)) & ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK)

#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK (0xFFF0000U)
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT (16U)
/*! ETLNS - Egress Timestamp Latency, in nanoseconds */
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT)) & ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK)
/*! @} */

/*! @name MAC_PPS_CONTROL - PPS Control */
/*! @{ */

#define ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK (0xFU)
#define ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT (0U)
/*! PPSCTRL_PPSCMD - PPS Output Frequency Control */
#define ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT)) & ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK)
/*! @} */

/*! @name PPS0_TARGET_TIME_SECONDS - PPS0 Target Time Seconds */
/*! @{ */

#define ENET_PPS0_TARGET_TIME_SECONDS_TSTRH0_MASK (0xFFFFFFFFU)
#define ENET_PPS0_TARGET_TIME_SECONDS_TSTRH0_SHIFT (0U)
/*! TSTRH0 - PPS Target Time Seconds Register */
#define ENET_PPS0_TARGET_TIME_SECONDS_TSTRH0(x)  (((uint32_t)(((uint32_t)(x)) << ENET_PPS0_TARGET_TIME_SECONDS_TSTRH0_SHIFT)) & ENET_PPS0_TARGET_TIME_SECONDS_TSTRH0_MASK)
/*! @} */

/*! @name PPS0_TARGET_TIME_NANOSECONDS - PPS0 Target Time Nanoseconds */
/*! @{ */

#define ENET_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_MASK (0x7FFFFFFFU)
#define ENET_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT (0U)
/*! TTSL0 - Target Time Low for PPS Register */
#define ENET_PPS0_TARGET_TIME_NANOSECONDS_TTSL0(x) (((uint32_t)(((uint32_t)(x)) << ENET_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT)) & ENET_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_MASK)
/*! @} */

/*! @name MTL_OPERATION_MODE - MTL Operation Mode */
/*! @{ */

#define ENET_MTL_OPERATION_MODE_DTXSTS_MASK      (0x2U)
#define ENET_MTL_OPERATION_MODE_DTXSTS_SHIFT     (1U)
/*! DTXSTS - Drop Transmit Status
 *  0b0..Drop Transmit Status is disabled
 *  0b1..Drop Transmit Status is enabled
 */
#define ENET_MTL_OPERATION_MODE_DTXSTS(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OPERATION_MODE_DTXSTS_SHIFT)) & ENET_MTL_OPERATION_MODE_DTXSTS_MASK)

#define ENET_MTL_OPERATION_MODE_RAA_MASK         (0x4U)
#define ENET_MTL_OPERATION_MODE_RAA_SHIFT        (2U)
/*! RAA - Receive Arbitration Algorithm
 *  0b0..Strict priority (SP)
 *  0b1..Weighted Strict Priority (WSP)
 */
#define ENET_MTL_OPERATION_MODE_RAA(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OPERATION_MODE_RAA_SHIFT)) & ENET_MTL_OPERATION_MODE_RAA_MASK)

#define ENET_MTL_OPERATION_MODE_SCHALG_MASK      (0x60U)
#define ENET_MTL_OPERATION_MODE_SCHALG_SHIFT     (5U)
/*! SCHALG - Tx Scheduling Algorithm
 *  0b00..WRR algorithm
 *  0b01..WFQ algorithm when DCB feature is selected.Otherwise, Reserved
 *  0b10..DWRR algorithm when DCB feature is selected.Otherwise, Reserved
 *  0b11..Strict priority algorithm
 */
#define ENET_MTL_OPERATION_MODE_SCHALG(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OPERATION_MODE_SCHALG_SHIFT)) & ENET_MTL_OPERATION_MODE_SCHALG_MASK)

#define ENET_MTL_OPERATION_MODE_CNTPRST_MASK     (0x100U)
#define ENET_MTL_OPERATION_MODE_CNTPRST_SHIFT    (8U)
/*! CNTPRST - Counters Preset
 *  0b0..Counters Preset is disabled
 *  0b1..Counters Preset is enabled
 */
#define ENET_MTL_OPERATION_MODE_CNTPRST(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OPERATION_MODE_CNTPRST_SHIFT)) & ENET_MTL_OPERATION_MODE_CNTPRST_MASK)

#define ENET_MTL_OPERATION_MODE_CNTCLR_MASK      (0x200U)
#define ENET_MTL_OPERATION_MODE_CNTCLR_SHIFT     (9U)
/*! CNTCLR - Counters Reset
 *  0b0..Counters are not reset
 *  0b1..All counters are reset
 */
#define ENET_MTL_OPERATION_MODE_CNTCLR(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OPERATION_MODE_CNTCLR_SHIFT)) & ENET_MTL_OPERATION_MODE_CNTCLR_MASK)
/*! @} */

/*! @name MTL_INTERRUPT_STATUS - MTL Interrupt Status */
/*! @{ */

#define ENET_MTL_INTERRUPT_STATUS_Q0IS_MASK      (0x1U)
#define ENET_MTL_INTERRUPT_STATUS_Q0IS_SHIFT     (0U)
/*! Q0IS - Queue 0 Interrupt status
 *  0b0..Queue 0 Interrupt status not detected
 *  0b1..Queue 0 Interrupt status detected
 */
#define ENET_MTL_INTERRUPT_STATUS_Q0IS(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_INTERRUPT_STATUS_Q0IS_SHIFT)) & ENET_MTL_INTERRUPT_STATUS_Q0IS_MASK)

#define ENET_MTL_INTERRUPT_STATUS_Q1IS_MASK      (0x2U)
#define ENET_MTL_INTERRUPT_STATUS_Q1IS_SHIFT     (1U)
/*! Q1IS - Queue 1 Interrupt status
 *  0b0..Queue 1 Interrupt status not detected
 *  0b1..Queue 1 Interrupt status detected
 */
#define ENET_MTL_INTERRUPT_STATUS_Q1IS(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_INTERRUPT_STATUS_Q1IS_SHIFT)) & ENET_MTL_INTERRUPT_STATUS_Q1IS_MASK)
/*! @} */

/*! @name MTL_RXQ_DMA_MAP0 - Receive Queue and DMA Channel Mapping 0 */
/*! @{ */

#define ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK      (0x1U)
#define ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT     (0U)
/*! Q0MDMACH - Queue 0 Mapped to DMA Channel */
#define ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK)

#define ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK      (0x10U)
#define ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT     (4U)
/*! Q0DDMACH - Queue 0 Enabled for DA-based DMA Channel Selection
 *  0b0..Queue 0 disabled for DA-based DMA Channel Selection
 *  0b1..Queue 0 enabled for DA-based DMA Channel Selection
 */
#define ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK)

#define ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK      (0x100U)
#define ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT     (8U)
/*! Q1MDMACH - Queue 1 Mapped to DMA Channel */
#define ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK)

#define ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK      (0x1000U)
#define ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT     (12U)
/*! Q1DDMACH - Queue 1 Enabled for DA-based DMA Channel Selection
 *  0b0..Queue 1 disabled for DA-based DMA Channel Selection
 *  0b1..Queue 1 enabled for DA-based DMA Channel Selection
 */
#define ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK)
/*! @} */

/*! @name MTL_QUEUE_MTL_TXQX_OP_MODE - Queue 0 Transmit Operation Mode..Queue 1 Transmit Operation Mode */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_MASK (0x1U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_SHIFT (0U)
/*! FTQ - Flush Transmit Queue
 *  0b0..Flush Transmit Queue is disabled
 *  0b1..Flush Transmit Queue is enabled
 */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_MASK (0x2U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_SHIFT (1U)
/*! TSF - Transmit Store and Forward
 *  0b0..Transmit Store and Forward is disabled
 *  0b1..Transmit Store and Forward is enabled
 */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_MASK (0xCU)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_SHIFT (2U)
/*! TXQEN - Transmit Queue Enable
 *  0b00..Not enabled
 *  0b01..Enable in AV mode (Reserved in non-AV)
 *  0b10..Enabled
 *  0b11..Reserved
 */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_MASK (0x70U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_SHIFT (4U)
/*! TTC - Transmit Threshold Control
 *  0b000..32
 *  0b001..64
 *  0b010..96
 *  0b011..128
 *  0b100..192
 *  0b101..256
 *  0b110..384
 *  0b111..512
 */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_MASK (0x70000U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_SHIFT (16U)
/*! TQS - Transmit Queue Size */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_OP_MODE */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_TXQX_UNDRFLW - Queue 0 Underflow Counter..Queue 1 Underflow Counter */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_MASK (0x7FFU)
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_SHIFT (0U)
/*! UFFRMCNT - Underflow Packet Counter */
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_MASK (0x800U)
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_SHIFT (11U)
/*! UFCNTOVF - Overflow Bit for Underflow Packet Counter
 *  0b0..Overflow not detected for Underflow Packet Counter
 *  0b1..Overflow detected for Underflow Packet Counter
 */
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW */
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_TXQX_DBG - Queue 0 Transmit Debug..Queue 1 Transmit Debug */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_MASK (0x1U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_SHIFT (0U)
/*! TXQPAUSED - Transmit Queue in Pause
 *  0b0..Transmit Queue in Pause status is not detected
 *  0b1..Transmit Queue in Pause status is detected
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_MASK  (0x6U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_SHIFT (1U)
/*! TRCSTS - MTL Tx Queue Read Controller Status
 *  0b00..Idle state
 *  0b01..Read state (transferring data to the MAC transmitter)
 *  0b10..Waiting for pending Tx Status from the MAC transmitter
 *  0b11..Flushing the Tx queue because of the Packet Abort request from the MAC
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_MASK  (0x8U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_SHIFT (3U)
/*! TWCSTS - MTL Tx Queue Write Controller Status
 *  0b0..MTL Tx Queue Write Controller status is not detected
 *  0b1..MTL Tx Queue Write Controller status is detected
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_MASK  (0x10U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_SHIFT (4U)
/*! TXQSTS - MTL Tx Queue Not Empty Status
 *  0b0..MTL Tx Queue Not Empty status is not detected
 *  0b1..MTL Tx Queue Not Empty status is detected
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_MASK (0x20U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_SHIFT (5U)
/*! TXSTSFSTS - MTL Tx Status FIFO Full Status
 *  0b0..MTL Tx Status FIFO Full status is not detected
 *  0b1..MTL Tx Status FIFO Full status is detected
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_MASK    (0x70000U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_SHIFT   (16U)
/*! PTXQ - Number of Packets in the Transmit Queue */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_STXSTSF_MASK (0x700000U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_STXSTSF_SHIFT (20U)
/*! STXSTSF - Number of Status Words in Tx Status FIFO of Queue */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_STXSTSF(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_STXSTSF_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_STXSTSF_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_DBG */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_COUNT        (2U)

/*! @name MTL_QUEUE_MTL_TXQX_ETS_CTRL - Queue 1 ETS Control */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_MASK (0x4U)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_SHIFT (2U)
/*! AVALG - AV Algorithm
 *  0b0..CBS Algorithm is disabled
 *  0b1..CBS Algorithm is enabled
 */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_MASK (0x8U)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_SHIFT (3U)
/*! CC - Credit Control
 *  0b0..Credit Control is disabled
 *  0b1..Credit Control is enabled
 */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_MASK (0x70U)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_SHIFT (4U)
/*! SLC - Slot Count
 *  0b000..1 slot
 *  0b001..2 slots
 *  0b010..4 slots
 *  0b011..8 slots
 *  0b100..16 slots
 *  0b101..Reserved
 */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_COUNT   (2U)

/*! @name MTL_QUEUE_MTL_TXQX_ETS_STAT - Queue 0 ETS Status..Queue 1 ETS Status */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_MASK (0xFFFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_SHIFT (0U)
/*! ABS - Average Bits per Slot */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_COUNT   (2U)

/*! @name MTL_QUEUE_MTL_TXQX_QNTM_WGHT - Queue 0 Quantum or Weights..Queue 1 idleSlopeCredit, Quantum or Weights */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_MASK (0x1FFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_SHIFT (0U)
/*! ISCQW - idleSlopeCredit, Quantum or Weights */
#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT */
#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_COUNT  (2U)

/*! @name MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT - Queue 1 sendSlopeCredit */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_MASK (0x3FFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_SHIFT (0U)
/*! SSC - sendSlopeCredit Value */
#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT */
#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_COUNT (2U)

/*! @name MTL_QUEUE_MTL_TXQX_HI_CRDT - Queue 1 hiCredit */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_MASK  (0x1FFFFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_SHIFT (0U)
/*! HC - hiCredit Value */
#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT */
#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_TXQX_LO_CRDT - Queue 1 loCredit */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_MASK  (0x1FFFFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_SHIFT (0U)
/*! LC - loCredit Value */
#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT */
#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_QX_INTCTRL_STAT - Queue 0 Interrupt Control Status..Queue 1 Interrupt Control Status */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUNFIS_MASK (0x1U)
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUNFIS_SHIFT (0U)
/*! TXUNFIS - Transmit Queue Underflow Interrupt Status
 *  0b0..Transmit Queue Underflow Interrupt Status not detected
 *  0b1..Transmit Queue Underflow Interrupt Status detected
 */
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUNFIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUNFIS_SHIFT)) & ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUNFIS_MASK)

#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIS_MASK (0x2U)
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIS_SHIFT (1U)
/*! ABPSIS - Average Bits Per Slot Interrupt Status
 *  0b0..Average Bits Per Slot Interrupt Status not detected
 *  0b1..Average Bits Per Slot Interrupt Status detected
 */
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIS_SHIFT)) & ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIS_MASK)

#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUIE_MASK (0x100U)
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUIE_SHIFT (8U)
/*! TXUIE - Transmit Queue Underflow Interrupt Enable
 *  0b0..Transmit Queue Underflow Interrupt Status is disabled
 *  0b1..Transmit Queue Underflow Interrupt Status is enabled
 */
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUIE(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUIE_SHIFT)) & ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_TXUIE_MASK)

#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIE_MASK (0x200U)
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIE_SHIFT (9U)
/*! ABPSIE - Average Bits Per Slot Interrupt Enable
 *  0b0..Average Bits Per Slot Interrupt is disabled
 *  0b1..Average Bits Per Slot Interrupt is enabled
 */
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIE(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIE_SHIFT)) & ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_ABPSIE_MASK)

#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOVFIS_MASK (0x10000U)
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOVFIS_SHIFT (16U)
/*! RXOVFIS - Receive Queue Overflow Interrupt Status
 *  0b0..Receive Queue Overflow Interrupt Status not detected
 *  0b1..Receive Queue Overflow Interrupt Status detected
 */
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOVFIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOVFIS_SHIFT)) & ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOVFIS_MASK)

#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOIE_MASK (0x1000000U)
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOIE_SHIFT (24U)
/*! RXOIE - Receive Queue Overflow Interrupt Enable
 *  0b0..Receive Queue Overflow Interrupt is disabled
 *  0b1..Receive Queue Overflow Interrupt is enabled
 */
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOIE(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOIE_SHIFT)) & ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_RXOIE_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT */
#define ENET_MTL_QUEUE_MTL_QX_INTCTRL_STAT_COUNT (2U)

/*! @name MTL_QUEUE_MTL_RXQX_OP_MODE - Queue 0 Receive Operation Mode..Queue 1 Receive Operation Mode */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_MASK (0x3U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_SHIFT (0U)
/*! RTC - Receive Queue Threshold Control
 *  0b00..64
 *  0b01..32
 *  0b10..96
 *  0b11..128
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_MASK (0x8U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_SHIFT (3U)
/*! FUP - Forward Undersized Good Packets
 *  0b0..Forward Undersized Good Packets is disabled
 *  0b1..Forward Undersized Good Packets is enabled
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_MASK (0x10U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_SHIFT (4U)
/*! FEP - Forward Error Packets
 *  0b0..Forward Error Packets is disabled
 *  0b1..Forward Error Packets is enabled
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_MASK (0x20U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_SHIFT (5U)
/*! RSF - Receive Queue Store and Forward
 *  0b0..Receive Queue Store and Forward is disabled
 *  0b1..Receive Queue Store and Forward is enabled
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_MASK (0x40U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_SHIFT (6U)
/*! DIS_TCP_EF - Disable Dropping of TCP/IP Checksum Error Packets
 *  0b0..Dropping of TCP/IP Checksum Error Packets is enabled
 *  0b1..Dropping of TCP/IP Checksum Error Packets is disabled
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_MASK (0x700000U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_SHIFT (20U)
/*! RQS - Receive Queue Size */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_OP_MODE */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT - Queue 0 Missed Packet and Overflow Counter..Queue 1 Missed Packet and Overflow Counter */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_MASK (0x7FFU)
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_SHIFT (0U)
/*! OVFPKTCNT - Overflow Packet Counter */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_MASK (0x800U)
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_SHIFT (11U)
/*! OVFCNTOVF - Overflow Counter Overflow Bit
 *  0b0..Overflow Counter overflow not detected
 *  0b1..Overflow Counter overflow detected
 */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISPKTCNT_MASK (0x7FF0000U)
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISPKTCNT_SHIFT (16U)
/*! MISPKTCNT - Missed Packet Counter */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISPKTCNT_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISPKTCNT_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISCNTOVF_MASK (0x8000000U)
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISCNTOVF_SHIFT (27U)
/*! MISCNTOVF - Missed Packet Counter Overflow Bit
 *  0b0..Missed Packet Counter overflow not detected
 *  0b1..Missed Packet Counter overflow detected
 */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISCNTOVF_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_MISCNTOVF_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_COUNT (2U)

/*! @name MTL_QUEUE_MTL_RXQX_DBG - Queue 0 Receive Debug..Queue 1 Receive Debug */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_MASK  (0x1U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_SHIFT (0U)
/*! RWCSTS - MTL Rx Queue Write Controller Active Status
 *  0b0..MTL Rx Queue Write Controller Active Status not detected
 *  0b1..MTL Rx Queue Write Controller Active Status detected
 */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_MASK  (0x6U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_SHIFT (1U)
/*! RRCSTS - MTL Rx Queue Read Controller State
 *  0b00..Idle state
 *  0b01..Reading packet data
 *  0b10..Reading packet status (or timestamp)
 *  0b11..Flushing the packet data and status
 */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_MASK  (0x30U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_SHIFT (4U)
/*! RXQSTS - MTL Rx Queue Fill-Level Status
 *  0b00..Rx Queue empty
 *  0b01..Rx Queue fill-level below flow-control deactivate threshold
 *  0b10..Rx Queue fill-level above flow-control activate threshold
 *  0b11..Rx Queue full
 */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_MASK    (0x3FFF0000U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_SHIFT   (16U)
/*! PRXQ - Number of Packets in Receive Queue */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_DBG */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_COUNT        (2U)

/*! @name MTL_QUEUE_MTL_RXQX_CTRL - Queue 0 Receive Control..Queue 1 Receive Control */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_MASK (0x7U)
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_SHIFT (0U)
/*! RXQ_WEGT - Receive Queue Weight */
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_MASK (0x8U)
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_SHIFT (3U)
/*! RXQ_FRM_ARBIT - Receive Queue Packet Arbitration
 *  0b0..Receive Queue Packet Arbitration is disabled
 *  0b1..Receive Queue Packet Arbitration is enabled
 */
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_CTRL */
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_COUNT       (2U)

/*! @name DMA_MODE - DMA Bus Mode */
/*! @{ */

#define ENET_DMA_MODE_SWR_MASK                   (0x1U)
#define ENET_DMA_MODE_SWR_SHIFT                  (0U)
/*! SWR - Software Reset
 *  0b0..Software Reset is disabled
 *  0b1..Software Reset is enabled
 */
#define ENET_DMA_MODE_SWR(x)                     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_SWR_SHIFT)) & ENET_DMA_MODE_SWR_MASK)

#define ENET_DMA_MODE_DA_MASK                    (0x2U)
#define ENET_DMA_MODE_DA_SHIFT                   (1U)
/*! DA - DMA Tx or Rx Arbitration Scheme
 *  0b0..Weighted Round-Robin with Rx:Tx or Tx:Rx
 *  0b1..Fixed Priority
 */
#define ENET_DMA_MODE_DA(x)                      (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_DA_SHIFT)) & ENET_DMA_MODE_DA_MASK)

#define ENET_DMA_MODE_TAA_MASK                   (0x1CU)
#define ENET_DMA_MODE_TAA_SHIFT                  (2U)
/*! TAA - Transmit Arbitration Algorithm
 *  0b000..Fixed priority
 *  0b001..Weighted Strict Priority (WSP)
 *  0b010..Weighted Round-Robin (WRR)
 *  0b011..Reserved (for 3'b011 to 3'b111)
 */
#define ENET_DMA_MODE_TAA(x)                     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_TAA_SHIFT)) & ENET_DMA_MODE_TAA_MASK)

#define ENET_DMA_MODE_TXPR_MASK                  (0x800U)
#define ENET_DMA_MODE_TXPR_SHIFT                 (11U)
/*! TXPR - Transmit Priority
 *  0b0..Transmit Priority is disabled
 *  0b1..Transmit Priority is enabled
 */
#define ENET_DMA_MODE_TXPR(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_TXPR_SHIFT)) & ENET_DMA_MODE_TXPR_MASK)

#define ENET_DMA_MODE_PR_MASK                    (0x7000U)
#define ENET_DMA_MODE_PR_SHIFT                   (12U)
/*! PR - Priority Ratio
 *  0b000..The priority ratio is 1:1
 *  0b001..The priority ratio is 2:1
 *  0b010..The priority ratio is 3:1
 *  0b011..The priority ratio is 4:1
 *  0b100..The priority ratio is 5:1
 *  0b101..The priority ratio is 6:1
 *  0b110..The priority ratio is 7:1
 *  0b111..The priority ratio is 8:1
 */
#define ENET_DMA_MODE_PR(x)                      (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_PR_SHIFT)) & ENET_DMA_MODE_PR_MASK)
/*! @} */

/*! @name DMA_SYSBUS_MODE - DMA System Bus Mode */
/*! @{ */

#define ENET_DMA_SYSBUS_MODE_FB_MASK             (0x1U)
#define ENET_DMA_SYSBUS_MODE_FB_SHIFT            (0U)
/*! FB - Fixed Burst Length
 *  0b0..Fixed Burst Length is disabled
 *  0b1..Fixed Burst Length is enabled
 */
#define ENET_DMA_SYSBUS_MODE_FB(x)               (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_FB_SHIFT)) & ENET_DMA_SYSBUS_MODE_FB_MASK)

#define ENET_DMA_SYSBUS_MODE_AAL_MASK            (0x1000U)
#define ENET_DMA_SYSBUS_MODE_AAL_SHIFT           (12U)
/*! AAL - Address-Aligned Beats
 *  0b0..Address-Aligned Beats is disabled
 *  0b1..Address-Aligned Beats is enabled
 */
#define ENET_DMA_SYSBUS_MODE_AAL(x)              (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_AAL_SHIFT)) & ENET_DMA_SYSBUS_MODE_AAL_MASK)

#define ENET_DMA_SYSBUS_MODE_MB_MASK             (0x4000U)
#define ENET_DMA_SYSBUS_MODE_MB_SHIFT            (14U)
/*! MB - Mixed Burst
 *  0b0..Mixed Burst is disabled
 *  0b1..Mixed Burst is enabled
 */
#define ENET_DMA_SYSBUS_MODE_MB(x)               (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_MB_SHIFT)) & ENET_DMA_SYSBUS_MODE_MB_MASK)

#define ENET_DMA_SYSBUS_MODE_RB_MASK             (0x8000U)
#define ENET_DMA_SYSBUS_MODE_RB_SHIFT            (15U)
/*! RB - Rebuild INCRx Burst
 *  0b0..Rebuild INCRx Burst is disabled
 *  0b1..Rebuild INCRx Burst is enabled
 */
#define ENET_DMA_SYSBUS_MODE_RB(x)               (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_RB_SHIFT)) & ENET_DMA_SYSBUS_MODE_RB_MASK)
/*! @} */

/*! @name DMA_INTERRUPT_STATUS - DMA Interrupt Status */
/*! @{ */

#define ENET_DMA_INTERRUPT_STATUS_DC0IS_MASK     (0x1U)
#define ENET_DMA_INTERRUPT_STATUS_DC0IS_SHIFT    (0U)
/*! DC0IS - DMA Channel 0 Interrupt Status
 *  0b0..DMA Channel 0 Interrupt Status not detected
 *  0b1..DMA Channel 0 Interrupt Status detected
 */
#define ENET_DMA_INTERRUPT_STATUS_DC0IS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTERRUPT_STATUS_DC0IS_SHIFT)) & ENET_DMA_INTERRUPT_STATUS_DC0IS_MASK)

#define ENET_DMA_INTERRUPT_STATUS_DC1IS_MASK     (0x2U)
#define ENET_DMA_INTERRUPT_STATUS_DC1IS_SHIFT    (1U)
/*! DC1IS - DMA Channel 1 Interrupt Status
 *  0b0..DMA Channel 1 Interrupt Status not detected
 *  0b1..DMA Channel 1 Interrupt Status detected
 */
#define ENET_DMA_INTERRUPT_STATUS_DC1IS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTERRUPT_STATUS_DC1IS_SHIFT)) & ENET_DMA_INTERRUPT_STATUS_DC1IS_MASK)

#define ENET_DMA_INTERRUPT_STATUS_MTLIS_MASK     (0x10000U)
#define ENET_DMA_INTERRUPT_STATUS_MTLIS_SHIFT    (16U)
/*! MTLIS - MTL Interrupt Status
 *  0b0..MTL Interrupt Status not detected
 *  0b1..MTL Interrupt Status detected
 */
#define ENET_DMA_INTERRUPT_STATUS_MTLIS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTERRUPT_STATUS_MTLIS_SHIFT)) & ENET_DMA_INTERRUPT_STATUS_MTLIS_MASK)

#define ENET_DMA_INTERRUPT_STATUS_MACIS_MASK     (0x20000U)
#define ENET_DMA_INTERRUPT_STATUS_MACIS_SHIFT    (17U)
/*! MACIS - MAC Interrupt Status
 *  0b0..MAC Interrupt Status not detected
 *  0b1..MAC Interrupt Status detected
 */
#define ENET_DMA_INTERRUPT_STATUS_MACIS(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTERRUPT_STATUS_MACIS_SHIFT)) & ENET_DMA_INTERRUPT_STATUS_MACIS_MASK)
/*! @} */

/*! @name DMA_DEBUG_STATUS0 - DMA Debug Status 0 */
/*! @{ */

#define ENET_DMA_DEBUG_STATUS0_AXWHSTS_MASK      (0x1U)
#define ENET_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT     (0U)
/*! AXWHSTS - AHB Master Status
 *  0b0..AXI Master Write Channel or AHB Master Status not detected
 *  0b1..AXI Master Write Channel or AHB Master Status detected
 */
#define ENET_DMA_DEBUG_STATUS0_AXWHSTS(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT)) & ENET_DMA_DEBUG_STATUS0_AXWHSTS_MASK)

#define ENET_DMA_DEBUG_STATUS0_RPS0_MASK         (0xF00U)
#define ENET_DMA_DEBUG_STATUS0_RPS0_SHIFT        (8U)
/*! RPS0 - DMA Channel 0 Receive Process State
 *  0b0000..Stopped (Reset or Stop Receive Command issued)
 *  0b0001..Running (Fetching Rx Transfer Descriptor)
 *  0b0010..Reserved for future use
 *  0b0011..Running (Waiting for Rx packet)
 *  0b0100..Suspended (Rx Descriptor Unavailable)
 *  0b0101..Running (Closing the Rx Descriptor)
 *  0b0110..Timestamp write state
 *  0b0111..Running (Transferring the received packet data from the Rx buffer to the system memory)
 */
#define ENET_DMA_DEBUG_STATUS0_RPS0(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DEBUG_STATUS0_RPS0_SHIFT)) & ENET_DMA_DEBUG_STATUS0_RPS0_MASK)

#define ENET_DMA_DEBUG_STATUS0_TPS0_MASK         (0xF000U)
#define ENET_DMA_DEBUG_STATUS0_TPS0_SHIFT        (12U)
/*! TPS0 - DMA Channel 0 Transmit Process State
 *  0b0000..Stopped (Reset or Stop Transmit Command issued)
 *  0b0001..Running (Fetching Tx Transfer Descriptor)
 *  0b0010..Running (Waiting for status)
 *  0b0011..Running (Reading Data from system memory buffer and queuing it to the Tx buffer (Tx FIFO))
 *  0b0100..Timestamp write state
 *  0b0101..Reserved for future use
 *  0b0110..Suspended (Tx Descriptor Unavailable or Tx Buffer Underflow)
 *  0b0111..Running (Closing Tx Descriptor)
 */
#define ENET_DMA_DEBUG_STATUS0_TPS0(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DEBUG_STATUS0_TPS0_SHIFT)) & ENET_DMA_DEBUG_STATUS0_TPS0_MASK)

#define ENET_DMA_DEBUG_STATUS0_RPS1_MASK         (0xF0000U)
#define ENET_DMA_DEBUG_STATUS0_RPS1_SHIFT        (16U)
/*! RPS1 - DMA Channel 1 Receive Process State
 *  0b0000..Stopped (Reset or Stop Receive Command issued)
 *  0b0001..Running (Fetching Rx Transfer Descriptor)
 *  0b0010..Reserved for future use
 *  0b0011..Running (Waiting for Rx packet)
 *  0b0100..Suspended (Rx Descriptor Unavailable)
 *  0b0101..Running (Closing the Rx Descriptor)
 *  0b0110..Timestamp write state
 *  0b0111..Running (Transferring the received packet data from the Rx buffer to the system memory)
 */
#define ENET_DMA_DEBUG_STATUS0_RPS1(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DEBUG_STATUS0_RPS1_SHIFT)) & ENET_DMA_DEBUG_STATUS0_RPS1_MASK)

#define ENET_DMA_DEBUG_STATUS0_TPS1_MASK         (0xF00000U)
#define ENET_DMA_DEBUG_STATUS0_TPS1_SHIFT        (20U)
/*! TPS1 - DMA Channel 1 Transmit Process State
 *  0b0000..Stopped (Reset or Stop Transmit Command issued)
 *  0b0001..Running (Fetching Tx Transfer Descriptor)
 *  0b0010..Running (Waiting for status)
 *  0b0011..Running (Reading Data from system memory buffer and queuing it to the Tx buffer (Tx FIFO))
 *  0b0100..Timestamp write state
 *  0b0101..Reserved for future use
 *  0b0110..Suspended (Tx Descriptor Unavailable or Tx Buffer Underflow)
 *  0b0111..Running (Closing Tx Descriptor)
 */
#define ENET_DMA_DEBUG_STATUS0_TPS1(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DEBUG_STATUS0_TPS1_SHIFT)) & ENET_DMA_DEBUG_STATUS0_TPS1_MASK)
/*! @} */

/*! @name DMA_CH_DMA_CHX_CTRL - DMA Channel 0 Control..DMA Channel 1 Control */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_MASK      (0x10000U)
#define ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_SHIFT     (16U)
/*! PBLx8 - 8xPBL mode
 *  0b0..8xPBL mode is disabled
 *  0b1..8xPBL mode is enabled
 */
#define ENET_DMA_CH_DMA_CHX_CTRL_PBLx8(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_SHIFT)) & ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_MASK)

#define ENET_DMA_CH_DMA_CHX_CTRL_DSL_MASK        (0x1C0000U)
#define ENET_DMA_CH_DMA_CHX_CTRL_DSL_SHIFT       (18U)
/*! DSL - Descriptor Skip Length */
#define ENET_DMA_CH_DMA_CHX_CTRL_DSL(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CTRL_DSL_SHIFT)) & ENET_DMA_CH_DMA_CHX_CTRL_DSL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CTRL */
#define ENET_DMA_CH_DMA_CHX_CTRL_COUNT           (2U)

/*! @name DMA_CH_DMA_CHX_TX_CTRL - DMA Channel 0 Transmit Control..DMA Channel 1 Transmit Control */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_MASK      (0x1U)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_SHIFT     (0U)
/*! ST - Start or Stop Transmission Command
 *  0b0..Stop Transmission Command
 *  0b1..Start Transmission Command
 */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ST(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_MASK)

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_MASK     (0xEU)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_SHIFT    (1U)
/*! TCW - Transmit Channel Weight */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_MASK)

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_MASK     (0x10U)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_SHIFT    (4U)
/*! OSF - Operate on Second Packet
 *  0b0..Operate on Second Packet disabled
 *  0b1..Operate on Second Packet enabled
 */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_MASK)

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_MASK   (0x3F0000U)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_SHIFT  (16U)
/*! TxPBL - Transmit Programmable Burst Length */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL(x)     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_MASK)

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ETIC_MASK    (0x400000U)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ETIC_SHIFT   (22U)
/*! ETIC - Early Transmit Interrupt Control
 *  0b0..Early Transmit Interrupt is disabled
 *  0b1..Early Transmit Interrupt is enabled
 */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ETIC(x)      (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_ETIC_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_ETIC_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TX_CTRL */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_COUNT        (2U)

/*! @name DMA_CH_DMA_CHX_RX_CTRL - DMA Channel 0 Receive Control..DMA Channel 1 Receive Control */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_MASK      (0x1U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_SHIFT     (0U)
/*! SR - Start or Stop Receive
 *  0b0..Stop Receive
 *  0b1..Start Receive
 */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_SR(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_X_0_MASK (0x6U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_X_0_SHIFT (1U)
/*! RBSZ_X_0 - Receive Buffer size Low */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_X_0(x)  (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_X_0_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_X_0_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_13_Y_MASK (0x7FF8U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_13_Y_SHIFT (3U)
/*! RBSZ_13_Y - Receive Buffer size High */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_13_Y(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_13_Y_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_13_Y_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_MASK   (0x3F0000U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_SHIFT  (16U)
/*! RxPBL - Receive Programmable Burst Length */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL(x)     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_ERIC_MASK    (0x400000U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_ERIC_SHIFT   (22U)
/*! ERIC - Early Receive Interrupt Control
 *  0b0..Early Receive Interrupt is disabled
 *  0b1..Early Receive Interrupt is enabled
 */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_ERIC(x)      (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_ERIC_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_ERIC_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_MASK     (0x80000000U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_SHIFT    (31U)
/*! RPF - Rx Packet Flush.
 *  0b0..Rx Packet Flush is disabled
 *  0b1..Rx Packet Flush is enabled
 */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RX_CTRL */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_COUNT        (2U)

/*! @name DMA_CH_DMA_CHX_TXDESC_LIST_ADDR - Channel 0 Tx Descriptor List Address register..Channel 1 Tx Descriptor List Address */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_TDESLA_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_TDESLA_SHIFT (2U)
/*! TDESLA - Start of Transmit List */
#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_TDESLA(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_TDESLA_SHIFT)) & ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_TDESLA_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR */
#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_RXDESC_LIST_ADDR - Channel 0 Rx Descriptor List Address register..Channel 1 Rx Descriptor List Address */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_RDESLA_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_RDESLA_SHIFT (2U)
/*! RDESLA - Start of Receive List */
#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_RDESLA(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_RDESLA_SHIFT)) & ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_RDESLA_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR */
#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_TXDESC_TAIL_PTR - Channel 0 Tx Descriptor Tail Pointer..Channel 1 Tx Descriptor Tail Pointer */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_SHIFT (2U)
/*! TDTP - Transmit Descriptor Tail Pointer */
#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_SHIFT)) & ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR */
#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_RXDESC_TAIL_PTR - Channel 0 Rx Descriptor Tail Pointer..Channel 1 Rx Descriptor Tail Pointer */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_SHIFT (2U)
/*! RDTP - Receive Descriptor Tail Pointer */
#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_SHIFT)) & ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR */
#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_TXDESC_RING_LENGTH - Channel 0 Tx Descriptor Ring Length..Channel 1 Tx Descriptor Ring Length */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_MASK (0x3FFU)
#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_SHIFT (0U)
/*! TDRL - Transmit Descriptor Ring Length */
#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_SHIFT)) & ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH */
#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_RX_CONTROL2 - Channeli Receive Control..DMA Channel 1 Receive Control */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RX_CONTROL2_RDRL_MASK (0x3FFU)
#define ENET_DMA_CH_DMA_CHX_RX_CONTROL2_RDRL_SHIFT (0U)
/*! RDRL - Receive Descriptor Ring Length */
#define ENET_DMA_CH_DMA_CHX_RX_CONTROL2_RDRL(x)  (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CONTROL2_RDRL_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CONTROL2_RDRL_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CONTROL2_ARBS_MASK (0xFF0000U)
#define ENET_DMA_CH_DMA_CHX_RX_CONTROL2_ARBS_SHIFT (16U)
/*! ARBS - Alternate Receive Buffer Size */
#define ENET_DMA_CH_DMA_CHX_RX_CONTROL2_ARBS(x)  (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CONTROL2_ARBS_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CONTROL2_ARBS_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RX_CONTROL2 */
#define ENET_DMA_CH_DMA_CHX_RX_CONTROL2_COUNT    (2U)

/*! @name DMA_CH_DMA_CHX_INT_EN - Channeli Interrupt Enable..Channel 1 Interrupt Enable */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_INT_EN_TIE_MASK      (0x1U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_TIE_SHIFT     (0U)
/*! TIE - Transmit Interrupt Enable
 *  0b0..Transmit Interrupt is disabled
 *  0b1..Transmit Interrupt is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_TIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_TIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_TIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_TXSE_MASK     (0x2U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_TXSE_SHIFT    (1U)
/*! TXSE - Transmit Stopped Enable
 *  0b0..Transmit Stopped is disabled
 *  0b1..Transmit Stopped is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_TXSE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_TXSE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_TXSE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_MASK     (0x4U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_SHIFT    (2U)
/*! TBUE - Transmit Buffer Unavailable Enable
 *  0b0..Transmit Buffer Unavailable is disabled
 *  0b1..Transmit Buffer Unavailable is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_TBUE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RIE_MASK      (0x40U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RIE_SHIFT     (6U)
/*! RIE - Receive Interrupt Enable
 *  0b0..Receive Interrupt is disabled
 *  0b1..Receive Interrupt is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_MASK     (0x80U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_SHIFT    (7U)
/*! RBUE - Receive Buffer Unavailable Enable
 *  0b0..Receive Buffer Unavailable is disabled
 *  0b1..Receive Buffer Unavailable is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RBUE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RSE_MASK      (0x100U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RSE_SHIFT     (8U)
/*! RSE - Receive Stopped Enable
 *  0b0..Receive Stopped is disabled
 *  0b1..Receive Stopped is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RSE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RSE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RSE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_MASK     (0x200U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_SHIFT    (9U)
/*! RWTE - Receive Watchdog Timeout Enable
 *  0b0..Receive Watchdog Timeout is disabled
 *  0b1..Receive Watchdog Timeout is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RWTE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_MASK     (0x400U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_SHIFT    (10U)
/*! ETIE - Early Transmit Interrupt Enable
 *  0b0..Early Transmit Interrupt is disabled
 *  0b1..Early Transmit Interrupt is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_ETIE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_MASK     (0x800U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_SHIFT    (11U)
/*! ERIE - Early Receive Interrupt Enable
 *  0b0..Early Receive Interrupt is disabled
 *  0b1..Early Receive Interrupt is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_ERIE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_MASK     (0x1000U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_SHIFT    (12U)
/*! FBEE - Fatal Bus Error Enable
 *  0b0..Fatal Bus Error is disabled
 *  0b1..Fatal Bus Error is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_FBEE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_CDEE_MASK     (0x2000U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_CDEE_SHIFT    (13U)
/*! CDEE - Context Descriptor Error Enable
 *  0b0..Context Descriptor Error is disabled
 *  0b1..Context Descriptor Error is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_CDEE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_CDEE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_CDEE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_AIE_MASK      (0x4000U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_AIE_SHIFT     (14U)
/*! AIE - Abnormal Interrupt Summary Enable
 *  0b0..Abnormal Interrupt Summary is disabled
 *  0b1..Abnormal Interrupt Summary is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_AIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_AIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_AIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_NIE_MASK      (0x8000U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_NIE_SHIFT     (15U)
/*! NIE - Normal Interrupt Summary Enable
 *  0b0..Normal Interrupt Summary is disabled
 *  0b1..Normal Interrupt Summary is enabled
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_NIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_NIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_NIE_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_INT_EN */
#define ENET_DMA_CH_DMA_CHX_INT_EN_COUNT         (2U)

/*! @name DMA_CH_DMA_CHX_RX_INT_WDTIMER - Channel 0 Receive Interrupt Watchdog Timer..Channel 1 Receive Interrupt Watchdog Timer */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWT_MASK (0xFFU)
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWT_SHIFT (0U)
/*! RWT - Receive Interrupt Watchdog Timer Count */
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWT(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWT_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWT_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWTU_MASK (0x30000U)
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWTU_SHIFT (16U)
/*! RWTU - Receive Interrupt Watchdog Timer Count Units */
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWTU(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWTU_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RWTU_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER */
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT - Channel 0 Slot Function Control and Status..Channel 1 Slot Function Control and Status */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_MASK (0x1U)
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_SHIFT (0U)
/*! ESC - Enable Slot Comparison
 *  0b0..Slot Comparison is disabled
 *  0b1..Slot Comparison is enabled
 */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_SHIFT)) & ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_MASK)

#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_MASK (0x2U)
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_SHIFT (1U)
/*! ASC - Advance Slot Check
 *  0b0..Advance Slot Check is disabled
 *  0b1..Advance Slot Check is enabled
 */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_SHIFT)) & ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_MASK)

#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_SIV_MASK (0xFFF0U)
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_SIV_SHIFT (4U)
/*! SIV - Slot Interval Value */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_SIV(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_SIV_SHIFT)) & ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_SIV_MASK)

#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_MASK (0xF0000U)
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_SHIFT (16U)
/*! RSN - Reference Slot Number */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_SHIFT)) & ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_TXDESC - Channel 0 Current Application Transmit Descriptor..Channel 1 Current Application Transmit Descriptor */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_CURTDESAPTR_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_CURTDESAPTR_SHIFT (0U)
/*! CURTDESAPTR - Application Transmit Descriptor Address Pointer */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_CURTDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_CURTDESAPTR_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_CURTDESAPTR_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_RXDESC - Channel 0 Current Application Receive Descriptor..Channel 1 Current Application Receive Descriptor */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_CURRDESAPTR_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_CURRDESAPTR_SHIFT (0U)
/*! CURRDESAPTR - Application Receive Descriptor Address Pointer */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_CURRDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_CURRDESAPTR_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_CURRDESAPTR_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_TXBUF - Channel 0 Current Application Transmit Buffer Address..Channel 1 Current Application Transmit Buffer Address */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_CURTBUFAPTR_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_CURTBUFAPTR_SHIFT (0U)
/*! CURTBUFAPTR - Application Transmit Buffer Address Pointer */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_CURTBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_CURTBUFAPTR_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_CURTBUFAPTR_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_COUNT  (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_RXBUF - Channel 0 Current Application Receive Buffer Address..Channel 1 Current Application Receive Buffer Address */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_CURRBUFAPTR_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_CURRBUFAPTR_SHIFT (0U)
/*! CURRBUFAPTR - Application Receive Buffer Address Pointer */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_CURRBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_CURRBUFAPTR_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_CURRBUFAPTR_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_COUNT  (2U)

/*! @name DMA_CH_DMA_CHX_STAT - DMA Channel 0 Status..DMA Channel 1 Status */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_STAT_TI_MASK         (0x1U)
#define ENET_DMA_CH_DMA_CHX_STAT_TI_SHIFT        (0U)
/*! TI - Transmit Interrupt
 *  0b0..Transmit Interrupt status not detected
 *  0b1..Transmit Interrupt status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_TI(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_TI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_TI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_TPS_MASK        (0x2U)
#define ENET_DMA_CH_DMA_CHX_STAT_TPS_SHIFT       (1U)
/*! TPS - Transmit Process Stopped
 *  0b0..Transmit Process Stopped status not detected
 *  0b1..Transmit Process Stopped status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_TPS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_TPS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_TPS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_TBU_MASK        (0x4U)
#define ENET_DMA_CH_DMA_CHX_STAT_TBU_SHIFT       (2U)
/*! TBU - Transmit Buffer Unavailable
 *  0b0..Transmit Buffer Unavailable status not detected
 *  0b1..Transmit Buffer Unavailable status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_TBU(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_TBU_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_TBU_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RI_MASK         (0x40U)
#define ENET_DMA_CH_DMA_CHX_STAT_RI_SHIFT        (6U)
/*! RI - Receive Interrupt
 *  0b0..Receive Interrupt status not detected
 *  0b1..Receive Interrupt status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_RI(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RBU_MASK        (0x80U)
#define ENET_DMA_CH_DMA_CHX_STAT_RBU_SHIFT       (7U)
/*! RBU - Receive Buffer Unavailable
 *  0b0..Receive Buffer Unavailable status not detected
 *  0b1..Receive Buffer Unavailable status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_RBU(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RBU_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RBU_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RPS_MASK        (0x100U)
#define ENET_DMA_CH_DMA_CHX_STAT_RPS_SHIFT       (8U)
/*! RPS - Receive Process Stopped
 *  0b0..Receive Process Stopped status not detected
 *  0b1..Receive Process Stopped status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_RPS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RPS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RPS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RWT_MASK        (0x200U)
#define ENET_DMA_CH_DMA_CHX_STAT_RWT_SHIFT       (9U)
/*! RWT - Receive Watchdog Timeout
 *  0b0..Receive Watchdog Timeout status not detected
 *  0b1..Receive Watchdog Timeout status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_RWT(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RWT_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RWT_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_ETI_MASK        (0x400U)
#define ENET_DMA_CH_DMA_CHX_STAT_ETI_SHIFT       (10U)
/*! ETI - Early Transmit Interrupt
 *  0b0..Early Transmit Interrupt status not detected
 *  0b1..Early Transmit Interrupt status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_ETI(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_ETI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_ETI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_ERI_MASK        (0x800U)
#define ENET_DMA_CH_DMA_CHX_STAT_ERI_SHIFT       (11U)
/*! ERI - Early Receive Interrupt
 *  0b0..Early Receive Interrupt status not detected
 *  0b1..Early Receive Interrupt status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_ERI(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_ERI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_ERI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_FBE_MASK        (0x1000U)
#define ENET_DMA_CH_DMA_CHX_STAT_FBE_SHIFT       (12U)
/*! FBE - Fatal Bus Error
 *  0b0..Fatal Bus Error status not detected
 *  0b1..Fatal Bus Error status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_FBE(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_FBE_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_FBE_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_CDE_MASK        (0x2000U)
#define ENET_DMA_CH_DMA_CHX_STAT_CDE_SHIFT       (13U)
/*! CDE - Context Descriptor Error
 *  0b0..Context Descriptor Error status not detected
 *  0b1..Context Descriptor Error status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_CDE(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_CDE_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_CDE_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_AIS_MASK        (0x4000U)
#define ENET_DMA_CH_DMA_CHX_STAT_AIS_SHIFT       (14U)
/*! AIS - Abnormal Interrupt Summary
 *  0b0..Abnormal Interrupt Summary status not detected
 *  0b1..Abnormal Interrupt Summary status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_AIS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_AIS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_AIS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_NIS_MASK        (0x8000U)
#define ENET_DMA_CH_DMA_CHX_STAT_NIS_SHIFT       (15U)
/*! NIS - Normal Interrupt Summary
 *  0b0..Normal Interrupt Summary status not detected
 *  0b1..Normal Interrupt Summary status detected
 */
#define ENET_DMA_CH_DMA_CHX_STAT_NIS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_NIS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_NIS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_TEB_MASK        (0x70000U)
#define ENET_DMA_CH_DMA_CHX_STAT_TEB_SHIFT       (16U)
/*! TEB - Tx DMA Error Bits */
#define ENET_DMA_CH_DMA_CHX_STAT_TEB(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_TEB_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_TEB_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_REB_MASK        (0x380000U)
#define ENET_DMA_CH_DMA_CHX_STAT_REB_SHIFT       (19U)
/*! REB - Rx DMA Error Bits */
#define ENET_DMA_CH_DMA_CHX_STAT_REB(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_REB_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_REB_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_STAT */
#define ENET_DMA_CH_DMA_CHX_STAT_COUNT           (2U)

/*! @name DMA_CH_DMA_CHX_MISS_FRAME_CNT - Channel 0 Missed Frame Counter..Channel 1 Missed Frame Counter */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_MASK (0x7FFU)
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_SHIFT (0U)
/*! MFC - Dropped Packet Counters */
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_SHIFT)) & ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_MASK)

#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_MASK (0x8000U)
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_SHIFT (15U)
/*! MFCO - Overflow status of the MFC Counter
 *  0b0..Miss Frame Counter overflow not occurred
 *  0b1..Miss Frame Counter overflow occurred
 */
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_SHIFT)) & ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT */
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_RX_ERI_CNT - Channel 0 Receive ERI Counter..Channel 1 Receive ERI Counter */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RX_ERI_CNT_ECNT_MASK (0xFFFU)
#define ENET_DMA_CH_DMA_CHX_RX_ERI_CNT_ECNT_SHIFT (0U)
/*! ECNT - ERI Counter */
#define ENET_DMA_CH_DMA_CHX_RX_ERI_CNT_ECNT(x)   (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_ERI_CNT_ECNT_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_ERI_CNT_ECNT_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RX_ERI_CNT */
#define ENET_DMA_CH_DMA_CHX_RX_ERI_CNT_COUNT     (2U)


/*!
 * @}
 */ /* end of group ENET_Register_Masks */


/*!
 * @}
 */ /* end of group ENET_Peripheral_Access_Layer */


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


#endif  /* PERI_ENET_H_ */

