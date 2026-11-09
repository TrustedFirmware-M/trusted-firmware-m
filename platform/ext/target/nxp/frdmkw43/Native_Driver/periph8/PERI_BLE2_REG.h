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
**         CMSIS Peripheral Access Layer for BLE2_REG
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
 * @file PERI_BLE2_REG.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for BLE2_REG
 *
 * CMSIS Peripheral Access Layer for BLE2_REG
 */

#if !defined(PERI_BLE2_REG_H_)
#define PERI_BLE2_REG_H_                         /**< Symbol preventing repeated inclusion */

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
   -- BLE2_REG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLE2_REG_Peripheral_Access_Layer BLE2_REG Peripheral Access Layer
 * @{
 */

/** BLE2_REG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint32_t BLE_REG_TXRX_CCM_SESSION_KEY_0;    /**< Session Key 0 for CCM Operation, offset: 0x200 */
  __IO uint32_t BLE_REG_TXRX_CCM_SESSION_KEY_1;    /**< Session Key 1 for CCM Operation, offset: 0x204 */
  __IO uint32_t BLE_REG_TXRX_CCM_SESSION_KEY_2;    /**< Session Key 2 for CCM Operation, offset: 0x208 */
  __IO uint32_t BLE_REG_TXRX_CCM_SESSION_KEY_3;    /**< Session Key 3 for CCM Operation, offset: 0x20C */
  __IO uint32_t BLE_REG_TXRX_CCM_INIT_VEC_0;       /**< Initialization Vector 0 for CCM Operation, offset: 0x210 */
  __IO uint32_t BLE_REG_TXRX_CCM_INIT_VEC_1;       /**< Initialization Vector 1 for CCM Operation, offset: 0x214 */
  __IO uint32_t BLE_REG_TX_CCM_PKT_CNT_0;          /**< Transmit CCM Packet Count 0, offset: 0x218 */
  __IO uint32_t BLE_REG_TX_CCM_PKT_CNT_1;          /**< Transmit CCM Packet Count 1, offset: 0x21C */
  __IO uint32_t BLE_REG_RX_CCM_PKT_CNT_0;          /**< Receive CCM Packet Count 0, offset: 0x220 */
  __IO uint32_t BLE_REG_RX_CCM_PKT_CNT_1;          /**< Receive CCM Packet Count 1, offset: 0x224 */
  __IO uint32_t BLE_REG_TXRX_CNTRL;                /**< Transmit/Receive Packet Control, offset: 0x228 */
  __IO uint32_t BLE_REG_TXRX_CRC_INIT_VAL;         /**< CRC Initialization Value, offset: 0x22C */
  __IO uint32_t BLE_REG_TX_ACC_ADDR;               /**< Tx Access Address, for Advt and Data Packets, offset: 0x230 */
       uint8_t RESERVED_1[12];
  __I  uint32_t BLE_REG_RX_PKT_STATUS;             /**< Rx Packet Status, for Advt and Data Packets, offset: 0x240 */
  __IO uint32_t BLE_REG_RX_CNTRL;                  /**< Receive Packet Control, offset: 0x244, available only on: RADIO.NBU.BLE2/BLE2 (missing on BLE2_REG) */
       uint8_t RESERVED_2[8];
  __IO uint32_t BLE_REG_TXRX_CCM_CNTRL;            /**< CCM Operation (encryption/authentication) Control, offset: 0x250 */
       uint8_t RESERVED_3[4];
  __I  uint32_t BLE_REG_TXRX_CORHIT_QUS_TIMESTAMP; /**< Quarter microsecond level timestamp, offset: 0x258 */
  __I  uint32_t BLE_REG_TXRX_CORHIT_MCCLOCK_TIMESTAMP; /**< Native clock timestamp, offset: 0x25C */
  __I  uint32_t BLE_REG_TXRX_PKTEND_QUS_TIMESTAMP; /**< Quarter microsecond level timestamp, offset: 0x260 */
  __I  uint32_t BLE_REG_TXRX_PKTEND_MCCLOCK_TIMESTAMP; /**< Native clock timestamp, offset: 0x264 */
       uint8_t RESERVED_4[8];
  __IO uint32_t BLE_REG_TXRX_ERR_INJ_CNTRL;        /**< TxRx Error Injection Control, offset: 0x270 */
  __IO uint32_t BLE_REG_TXRX_CRC_CORRUPT;          /**< TxRx CRC Corruption Control, offset: 0x274 */
       uint8_t RESERVED_5[16];
  __IO uint32_t BLE_REG_RL_DELAY;                  /**< BLE Register Loader Delay Register, offset: 0x288, available only on: RADIO.NBU.BLE2/BLE2 (missing on BLE2_REG) */
  __IO uint32_t BLE_REG_RL_START_ADDR_ALT;         /**< Register Loader Alternate Start Address, offset: 0x28C, available only on: RADIO.NBU.BLE2/BLE2 (missing on BLE2_REG) */
  __IO uint32_t BLE_REG_RL_START_ADDR;             /**< Register Loader Start Address, offset: 0x290 */
  __IO uint32_t BLE_REG_RL_CNTRL_STS;              /**< Register Loader Control and Status, offset: 0x294 */
  __IO uint32_t BLE_REG_DFE_PKT_EXTENSION_CNTRL;   /**< Tx/Rx Packet Extension Control, offset: 0x298 */
  __IO uint32_t BLE_REG_RX_ADV_PDU_TYPE;           /**< Rx Advertising Packet PDU Type, offset: 0x29C */
  __IO uint32_t BLE_REG_PRNG_CTRL_STS;             /**< PRNG Control Status, offset: 0x2A0, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PRNG_IN;                   /**< PRNG Input, offset: 0x2A4, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __I  uint32_t BLE_REG_PRNG_OUT;                  /**< PRNG Output, offset: 0x2A8, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
       uint8_t RESERVED_6[44];
  __IO uint32_t BLE_REG_CODED_PKT_CNTRL;           /**< LE Coded Packet Control, offset: 0x2D8 */
  __IO uint32_t BLE_REG_IRK_BASE_ADDR;             /**< IRK Resolution Base address, offset: 0x2DC */
  __IO uint32_t BLE_REG_IRK_CTRL_0;                /**< IRK Resolution Control 0, offset: 0x2E0 */
  __IO uint32_t BLE_REG_IRK_CTRL_1;                /**< IRK Resolution Control 1, offset: 0x2E4 */
  __I  uint32_t BLE_REG_IRK_STATUS_0;              /**< IRK Resolution Status 0, offset: 0x2E8 */
  __I  uint32_t BLE_REG_IRK_STATUS_1;              /**< IRK Resolution Status 1, offset: 0x2EC */
  __IO uint32_t BLE_REG_WHITELIST_BASE_ADDR;       /**< Whitelist Base address, offset: 0x2F0 */
  __IO uint32_t BLE_REG_WHITELIST_CTRL_0;          /**< Whitelist Search Control 0, offset: 0x2F4 */
  __IO uint32_t BLE_REG_WHITELIST_CTRL_1;          /**< Whitelist Search Control 1, offset: 0x2F8 */
  __I  uint32_t BLE_REG_WHITELIST_STATUS;          /**< Whitelist Search Status, offset: 0x2FC */
  __IO uint32_t BLE_REG_TD_START_ADDR;             /**< Tx Descriptor Start Address, offset: 0x300 */
  __I  uint32_t BLE_REG_TD_STATUS;                 /**< Tx Descriptor Status, offset: 0x304 */
       uint8_t RESERVED_7[248];
  __IO uint32_t BLE_REG_RD_START_ADDR;             /**< Rx Descriptor Start Address, offset: 0x400 */
  __I  uint32_t BLE_REG_RD_STATUS;                 /**< Rx Descriptor Status, offset: 0x404 */
  __IO uint32_t BLE_REG_RSSI_ARB_CTRL;             /**< BLE RSSI ARBITRATION CONTROL, offset: 0x408, available only on: RADIO.NBU.BLE2/BLE2 (missing on BLE2_REG) */
  __IO uint32_t BLE_REG_RD_START_ADDR_ALT;         /**< Alternate Rx Descriptor Start Address, offset: 0x40C, available only on: RADIO.NBU.BLE2/BLE2 (missing on BLE2_REG) */
  __IO uint32_t BLE_REG_RD_CTRL;                   /**< Rx Descriptor Control, offset: 0x410, available only on: RADIO.NBU.BLE2/BLE2 (missing on BLE2_REG) */
       uint8_t RESERVED_8[244];
  __IO uint32_t BLE_REG_CLK_CTRL_SLEEP_OK_TIMER;   /**< BLE sleep ok timer, offset: 0x508 */
       uint8_t RESERVED_9[244];
  __IO uint32_t BLE_REG_AES_CNTRL;                 /**< AES Control, offset: 0x600 */
       uint8_t RESERVED_10[12];
  __IO uint32_t BLE_REG_AES_KEY_0;                 /**< Key 0 for Software AES encryption, offset: 0x610 */
  __IO uint32_t BLE_REG_AES_KEY_1;                 /**< Key 1 for Software AES encryption, offset: 0x614 */
  __IO uint32_t BLE_REG_AES_KEY_2;                 /**< Key 2 for Software AES encryption, offset: 0x618 */
  __IO uint32_t BLE_REG_AES_KEY_3;                 /**< Key 3 for Software AES encryption, offset: 0x61C */
  __IO uint32_t BLE_REG_AES_DIN_0;                 /**< Raw Data Input 0 for Software AES encryption, offset: 0x620 */
  __IO uint32_t BLE_REG_AES_DIN_1;                 /**< Raw Data Input 1 for Software AES encryption, offset: 0x624 */
  __IO uint32_t BLE_REG_AES_DIN_2;                 /**< Raw Data Input 2 for Software AES encryption, offset: 0x628 */
  __IO uint32_t BLE_REG_AES_DIN_3;                 /**< Raw Data Input 3 for Software AES encryption, offset: 0x62C */
  __I  uint32_t BLE_REG_AES_DOUT_0;                /**< AES Encrypted Data Output 0, offset: 0x630 */
  __I  uint32_t BLE_REG_AES_DOUT_1;                /**< AES Encrypted Data Output 1, offset: 0x634 */
  __I  uint32_t BLE_REG_AES_DOUT_2;                /**< AES Encrypted Data Output 2, offset: 0x638 */
  __I  uint32_t BLE_REG_AES_DOUT_3;                /**< AES Encrypted Data Output 3, offset: 0x63C */
       uint8_t RESERVED_11[192];
  __IO uint32_t BLE_REG_INT_MASK_0;                /**< BLE Interrupt Mask 0, offset: 0x700 */
  __IO uint32_t BLE_REG_INT_MASK_1;                /**< BLE Interrupt Mask 0/1, offset: 0x704 */
  __IO uint32_t BLE_REG_INT_MASK_2;                /**< BLE Interrupt Mask 2, offset: 0x708 */
  __IO uint32_t BLE_REG_HW_ABORT_MASK;             /**< BLE Interrupt Mask, hardware Abort, offset: 0x70C */
  __IO uint32_t BLE_REG_RT_ERR_MASK;               /**< BLE Interrupt Mask, Real-time Error, offset: 0x710 */
       uint8_t RESERVED_12[44];
  __IO uint32_t BLE_REG_INT_STS_0;                 /**< BLE Interrupt Status 0, offset: 0x740 */
  __IO uint32_t BLE_REG_INT_STS_1;                 /**< BLE Interrupt Status 1, offset: 0x744 */
  __IO uint32_t BLE_REG_INT_STS_2;                 /**< BLE Interrupt Status 2, offset: 0x748 */
  __IO uint32_t BLE_REG_HW_ABORT_STS;              /**< BLE Interrupt Status, hardware Abort, offset: 0x74C */
  __IO uint32_t BLE_REG_RT_ERR_STS;                /**< BLE Interrupt Status, Real-time Error, offset: 0x750 */
       uint8_t RESERVED_13[44];
  __IO uint32_t BLE_REG_INT_CFG_01;                /**< BLE Interrupt Configuration, offset: 0x780 */
  __IO uint32_t BLE_REG_INT_DELAY_CTRL_01;         /**< BLE Interrupt Delay Control, offset: 0x784 */
  __IO uint32_t BLE_REG_INT_SW_MBOX;               /**< Software Mailbox Interrupt, offset: 0x788 */
       uint8_t RESERVED_14[116];
  __IO uint32_t BLE_REG_TMR_SWT_CTL_0;             /**< Software Timer 0: Control, offset: 0x800 */
  __IO uint32_t BLE_REG_TMR_SWT_VALUE_0;           /**< Software Timer 0: Expiration Value, offset: 0x804 */
  __I  uint32_t BLE_REG_TMR_SWT_STS_0;             /**< Software Timer 0: Expiration Status, offset: 0x808 */
       uint8_t RESERVED_15[4];
  __IO uint32_t BLE_REG_TMR_SWT_CTL_1;             /**< Software Timer 1: Control, offset: 0x810 */
  __IO uint32_t BLE_REG_TMR_SWT_VALUE_1;           /**< Software Timer 1: Expiration Value, offset: 0x814 */
  __I  uint32_t BLE_REG_TMR_SWT_STS_1;             /**< Software Timer 1: Expiration Status, offset: 0x818 */
       uint8_t RESERVED_16[4];
  __IO uint32_t BLE_REG_TMR_SWT_CTL_2;             /**< Software Timer 2: Control, offset: 0x820 */
  __IO uint32_t BLE_REG_TMR_SWT_VALUE_2;           /**< Software Timer 2: Expiration Value, offset: 0x824 */
  __I  uint32_t BLE_REG_TMR_SWT_STS_2;             /**< Software Timer 2: Expiration Status, offset: 0x828 */
       uint8_t RESERVED_17[4];
  __IO uint32_t BLE_REG_TMR_SWT_CTL_3;             /**< Software Timer 3: Control, offset: 0x830 */
  __IO uint32_t BLE_REG_TMR_SWT_VALUE_3;           /**< Software Timer 3: Expiration Value, offset: 0x834 */
  __I  uint32_t BLE_REG_TMR_SWT_STS_3;             /**< Software Timer 3: Expiration Status, offset: 0x838 */
  __I  uint32_t BLE_REG_TMR_NATIVE_QUS;            /**< Native quarter microsecond counter Value, offset: 0x83C */
  __I  uint32_t BLE_REG_TMR_NATIVE_CLOCK;          /**< Native mcClock Value, offset: 0x840 */
  __IO uint32_t BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES; /**< Wakeup delay value in LPO cycles, offset: 0x844 */
  __I  uint32_t BLE_REG_TMR_CLOCK_SKIP;            /**< Native Clock Value, offset: 0x848 */
       uint8_t RESERVED_18[4];
  __IO uint32_t BLE_REG_TMR_CDT_CTL_0;             /**< Qus Count Down Timer 0: Control, offset: 0x850 */
  __IO uint32_t BLE_REG_TMR_CDT_VALUE_0;           /**< Count Down Timer 0: Count Value, offset: 0x854 */
  __IO uint32_t BLE_REG_TMR_CDT_CTL_1;             /**< Qus Count Down Timer 1: Control, offset: 0x858 */
  __IO uint32_t BLE_REG_TMR_CDT_VALUE_1;           /**< Count Down Timer 1: Count Value, offset: 0x85C */
  __IO uint32_t BLE_REG_TMR_CDT_CTL_2;             /**< Qus Count Down Timer 2: Control, offset: 0x860 */
  __IO uint32_t BLE_REG_TMR_CDT_VALUE_2;           /**< Count Down Timer 2: Count Value, offset: 0x864 */
  __IO uint32_t BLE_REG_TMR_CDT_CTL_3;             /**< Qus Count Down Timer 3: Control, offset: 0x868 */
  __IO uint32_t BLE_REG_TMR_CDT_VALUE_3;           /**< Count Down Timer 3: Count Value, offset: 0x86C */
  __IO uint32_t BLE_REG_TMR_CDT_CTL_4;             /**< Qus Count Down Timer 4: Control, offset: 0x870 */
  __IO uint32_t BLE_REG_TMR_CDT_VALUE_4;           /**< Count Down Timer 4: Count Value, offset: 0x874 */
  __IO uint32_t BLE_REG_TMR_CDT_CTL_5;             /**< Qus Count Down Timer 5: Control, offset: 0x878 */
  __IO uint32_t BLE_REG_TMR_CDT_VALUE_5;           /**< Count Down Timer 5: Count Value, offset: 0x87C */
  __IO uint32_t BLE_REG_TMR_CDT_2M_DATA_ADJ;       /**< Qus Count Offset Register: LE 2M, offset: 0x880 */
  __IO uint32_t BLE_REG_TMR_CDT_CI_TX_DATA_ADJ;    /**< Qus Count Offset Register: LE Coded Tx, offset: 0x884 */
  __IO uint32_t BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0;  /**< Qus Count Offset Register: LE Coded Rx 0, offset: 0x888 */
  __IO uint32_t BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1;  /**< Qus Count Offset Register: LE Coded Rx 1, offset: 0x88C */
  __IO uint32_t BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2;  /**< Qus Count Offset Register: LE Coded Rx 2, offset: 0x890 */
  __IO uint32_t BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3;  /**< Qus Count Offset Register: LE Coded Rx 3, offset: 0x894 */
  __IO uint32_t BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4;  /**< Qus Count Offset Register: LE Coded Rx 4, offset: 0x898 */
  __I  uint32_t BLE_REG_TMR_CDT_STS;               /**< Countdown timer Status, offset: 0x89C, available only on: RADIO.NBU.BLE2/BLE2 (missing on BLE2_REG) */
       uint8_t RESERVED_19[96];
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_CNTRL;       /**< Tx Antenna Switch Control, offset: 0x900 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_0;       /**< Tx Antenna Switch Map: Map 0, offset: 0x904 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_1;       /**< Tx Antenna Switch Map: Map 1, offset: 0x908 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_2;       /**< Tx Antenna Switch Map: Map 2, offset: 0x90C */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_3;       /**< Tx Antenna Switch Map: Map 3, offset: 0x910 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_4;       /**< Tx Antenna Switch Map: Map 4, offset: 0x914 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_5;       /**< Tx Antenna Switch Map: Map 5, offset: 0x918 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_6;       /**< Tx Antenna Switch Map: Map 6, offset: 0x91C */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_7;       /**< Tx Antenna Switch Map: Map 7, offset: 0x920 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_8;       /**< Tx Antenna Switch Map: Map 8, offset: 0x924 */
  __IO uint32_t BLE_REG_ANT_SWITCH_TX_MAP_9;       /**< Tx Antenna Switch Map: Map 9, offset: 0x928 */
       uint8_t RESERVED_20[4];
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_CNTRL;       /**< Rx Antenna Switch Control, offset: 0x930 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_0;       /**< Rx Antenna Switch Map: Map 0, offset: 0x934 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_1;       /**< Rx Antenna Switch Map: Map 1, offset: 0x938 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_2;       /**< Rx Antenna Switch Map: Map 2, offset: 0x93C */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_3;       /**< Rx Antenna Switch Map: Map 3, offset: 0x940 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_4;       /**< Rx Antenna Switch Map: Map 4, offset: 0x944 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_5;       /**< Rx Antenna Switch Map: Map 5, offset: 0x948 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_6;       /**< Rx Antenna Switch Map: Map 6, offset: 0x94C */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_7;       /**< Rx Antenna Switch Map: Map 7, offset: 0x950 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_8;       /**< Rx Antenna Switch Map: Map 8, offset: 0x954 */
  __IO uint32_t BLE_REG_ANT_SWITCH_RX_MAP_9;       /**< Rx Antenna Switch Map: Map 9, offset: 0x958 */
       uint8_t RESERVED_21[164];
  __IO uint32_t BLE_REG_PST_CTRL_0;                /**< Periodic SW Timer 0: Control, offset: 0xA00, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_STS_0;                 /**< Periodic SW Timer 0: Status, offset: 0xA04, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_FRST_ANCHR_0;          /**< Periodic SW Timer 0: First Anchor, offset: 0xA08, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_ANCHR_OFST_0;          /**< Periodic SW Timer 0: First Anchor Offset, offset: 0xA0C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_ANCHR_ADJ_0;           /**< Periodic SW Timer 0: Anchor Adjustment, offset: 0xA10, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_INTVL_0;               /**< Periodic SW Timer 0: ISO Interval, offset: 0xA14, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SPC_0;                 /**< Periodic SW Timer 0: Spacing, offset: 0xA18, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SEL_STRM_0;            /**< Periodic SW Timer 0: Select Stream, offset: 0xA1C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SYNC_DLY_0;            /**< Periodic SW Timer 0: Group Sync Delay, offset: 0xA20, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SE_CTRL_0;             /**< Periodic SW Timer 0: SubEvent Control, offset: 0xA24, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SE_INTVL_0;            /**< Periodic SW Timer 0: SubEvent Interval, offset: 0xA28, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __I  uint32_t BLE_REG_PST_SE_DIS_0;              /**< Periodic SW Timer 0: SubEvent Disable, offset: 0xA2C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_CTRL_1;                /**< Periodic SW Timer 1: Control, offset: 0xA30, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_STS_1;                 /**< Periodic SW Timer 1: Status, offset: 0xA34, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_FRST_ANCHR_1;          /**< Periodic SW Timer 1: First Anchor, offset: 0xA38, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_ANCHR_OFST_1;          /**< Periodic SW Timer 1: First Anchor Offset, offset: 0xA3C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_ANCHR_ADJ_1;           /**< Periodic SW Timer 1: Anchor Adjustment, offset: 0xA40, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_INTVL_1;               /**< Periodic SW Timer 1: ISO Interval, offset: 0xA44, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SPC_1;                 /**< Periodic SW Timer 1: Spacing, offset: 0xA48, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SEL_STRM_1;            /**< Periodic SW Timer 1: Select Stream, offset: 0xA4C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SYNC_DLY_1;            /**< Periodic SW Timer 1: Group Sync Delay, offset: 0xA50, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SE_CTRL_1;             /**< Periodic SW Timer 1: SubEvent Control, offset: 0xA54, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SE_INTVL_1;            /**< Periodic SW Timer 1: SubEvent Interval, offset: 0xA58, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __I  uint32_t BLE_REG_PST_SE_DIS_1;              /**< Periodic SW Timer 1: SubEvent Disable, offset: 0xA5C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_CTRL_2;                /**< Periodic SW Timer 2: Control, offset: 0xA60, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_STS_2;                 /**< Periodic SW Timer 2: Status, offset: 0xA64, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_FRST_ANCHR_2;          /**< Periodic SW Timer 2: First Anchor, offset: 0xA68, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_ANCHR_OFST_2;          /**< Periodic SW Timer 2: First Anchor Offset, offset: 0xA6C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_ANCHR_ADJ_2;           /**< Periodic SW Timer 2: Anchor Adjustment, offset: 0xA70, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_INTVL_2;               /**< Periodic SW Timer 2: ISO Interval, offset: 0xA74, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SPC_2;                 /**< Periodic SW Timer 2: Spacing, offset: 0xA78, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SEL_STRM_2;            /**< Periodic SW Timer 2: Select Stream, offset: 0xA7C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SYNC_DLY_2;            /**< Periodic SW Timer 2: Group Sync Delay, offset: 0xA80, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SE_CTRL_2;             /**< Periodic SW Timer 2: SubEvent Control, offset: 0xA84, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __IO uint32_t BLE_REG_PST_SE_INTVL_2;            /**< Periodic SW Timer 2: SubEvent Interval, offset: 0xA88, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
  __I  uint32_t BLE_REG_PST_SE_DIS_2;              /**< Periodic SW Timer 2: SubEvent Disable, offset: 0xA8C, available only on: BLE2_REG (missing on RADIO.NBU.BLE2/BLE2) */
       uint8_t RESERVED_22[880];
  __IO uint32_t BLE_REG_AHBW_FSM_MON_CNTRL;        /**< BLE AHBW FSM Monitor and Reset Control, offset: 0xE00 */
  __IO uint32_t BLE_REG_RX_FSM_MON_CNTRL;          /**< BLE Rx FSM Monitor and Reset Control, offset: 0xE04 */
  __IO uint32_t BLE_REG_TX_FSM_MON_CNTRL;          /**< BLE Tx FSM Monitor and Reset Control, offset: 0xE08 */
  __IO uint32_t BLE_REG_CCM_FSM_MON_CNTRL;         /**< BLE CCM FSM Monitor and Reset Control, offset: 0xE0C */
  __IO uint32_t BLE_REG_DEBUG_CNTRL;               /**< BLE Debug Test Bus Control, offset: 0xE10 */
  __IO uint32_t BLE_REG_DEBUG_BANK_SEL;            /**< BLE debug test bus bank selection set, offset: 0xE14 */
       uint8_t RESERVED_23[8];
  __I  uint32_t BLE_REG_IP_REVISION;               /**< BTU IP Revision, offset: 0xE20 */
       uint8_t RESERVED_24[12];
  __IO uint32_t BLE_REG_AES_MARGIN;                /**< BLE AES Margin, offset: 0xE30 */
  __IO uint32_t BLE_REG_DMA_MARGIN;                /**< BLE DMA Margin, offset: 0xE34 */
       uint8_t RESERVED_25[4];
  __IO uint32_t BLE_REG_AHB_LAT;                   /**< BLE AHB Latency Monitors, offset: 0xE3C */
       uint8_t RESERVED_26[64];
  __IO uint32_t BLE_REG_DEBUG_RVSD;                /**< Debug reserved, offset: 0xE80 */
} BLE2_REG_Type;

/* ----------------------------------------------------------------------------
   -- BLE2_REG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLE2_REG_Register_Masks BLE2_REG Register Masks
 * @{
 */

/*! @name BLE_REG_TXRX_CCM_SESSION_KEY_0 - Session Key 0 for CCM Operation */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_0_CCM_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_0_CCM_KEY_SHIFT (0U)
/*! ccm_key - CCM Session Key ([31:0] of 128-bit) */
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_0_CCM_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_0_CCM_KEY_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_0_CCM_KEY_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CCM_SESSION_KEY_1 - Session Key 1 for CCM Operation */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_1_CCM_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_1_CCM_KEY_SHIFT (0U)
/*! ccm_key - CCM Session Key ([63:32] of 128-bit) */
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_1_CCM_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_1_CCM_KEY_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_1_CCM_KEY_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CCM_SESSION_KEY_2 - Session Key 2 for CCM Operation */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_2_CCM_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_2_CCM_KEY_SHIFT (0U)
/*! ccm_key - CCM Session Key ([95:64] of 128-bit) */
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_2_CCM_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_2_CCM_KEY_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_2_CCM_KEY_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CCM_SESSION_KEY_3 - Session Key 3 for CCM Operation */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_3_CCM_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_3_CCM_KEY_SHIFT (0U)
/*! ccm_key - CCM Session Key ([127:96] of 128-bit) */
#define BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_3_CCM_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_3_CCM_KEY_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_SESSION_KEY_3_CCM_KEY_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CCM_INIT_VEC_0 - Initialization Vector 0 for CCM Operation */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_0_CCM_IV_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_0_CCM_IV_SHIFT (0U)
/*! ccm_iv - CCM Initialization Vector ([31:0] of 64-bit) */
#define BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_0_CCM_IV(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_0_CCM_IV_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_0_CCM_IV_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CCM_INIT_VEC_1 - Initialization Vector 1 for CCM Operation */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_1_CCM_IV_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_1_CCM_IV_SHIFT (0U)
/*! ccm_iv - CCM Initialization Vector ([63:32] of 64-bit) */
#define BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_1_CCM_IV(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_1_CCM_IV_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_INIT_VEC_1_CCM_IV_MASK)
/*! @} */

/*! @name BLE_REG_TX_CCM_PKT_CNT_0 - Transmit CCM Packet Count 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_0_TX_PKT_CNT_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_0_TX_PKT_CNT_SHIFT (0U)
/*! tx_pkt_cnt - Tx Packet Count ([31:0] of 39-bit) */
#define BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_0_TX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_0_TX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_0_TX_PKT_CNT_MASK)
/*! @} */

/*! @name BLE_REG_TX_CCM_PKT_CNT_1 - Transmit CCM Packet Count 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_1_TX_PKT_CNT_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_1_TX_PKT_CNT_SHIFT (0U)
/*! tx_pkt_cnt - Tx Packet Count ([38:32] of 39-bit) */
#define BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_1_TX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_1_TX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_TX_CCM_PKT_CNT_1_TX_PKT_CNT_MASK)
/*! @} */

/*! @name BLE_REG_RX_CCM_PKT_CNT_0 - Receive CCM Packet Count 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_0_RX_PKT_CNT_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_0_RX_PKT_CNT_SHIFT (0U)
/*! rx_pkt_cnt - Rx Packet Count ([31:0] of 39-bit) */
#define BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_0_RX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_0_RX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_0_RX_PKT_CNT_MASK)
/*! @} */

/*! @name BLE_REG_RX_CCM_PKT_CNT_1 - Receive CCM Packet Count 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_1_RX_PKT_CNT_MASK (0x7FU)
#define BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_1_RX_PKT_CNT_SHIFT (0U)
/*! rx_pkt_cnt - Rx Packet Count ([38:32] of 39-bit) */
#define BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_1_RX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_1_RX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_RX_CCM_PKT_CNT_1_RX_PKT_CNT_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CNTRL - Transmit/Receive Packet Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CNTRL_CONN_EVENT_ROLE_MASK (0x1U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_CONN_EVENT_ROLE_SHIFT (0U)
/*! conn_event_role - Connection event Role, 0x0: slave, 0x1: master
 *  0b0..slave
 *  0b1..master
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_CONN_EVENT_ROLE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_CONN_EVENT_ROLE_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_CONN_EVENT_ROLE_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_CHAN_PKT_MASK (0x2U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_CHAN_PKT_SHIFT (1U)
/*! data_chan_pkt - Channel to Distinguish pkt_header Fields, 0x0: advt channel, 0x1: data channel
 *  0b0..advt channel
 *  0b1..data channel
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_CHAN_PKT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_CHAN_PKT_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_CHAN_PKT_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_DATA_RATE_MASK (0x4U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_DATA_RATE_SHIFT (2U)
/*! rx_data_rate - LE Rx Packet Data Rate, 0x0: Rx packet data rate 1 Mbps, 0x1: Rx packet data rate 2 Mbps
 *  0b0..Rx packet data rate 1 Mbps
 *  0b1..Rx packet data rate 2 Mbps
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_DATA_RATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_RX_DATA_RATE_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_RX_DATA_RATE_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_DATA_RATE_MASK (0x8U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_DATA_RATE_SHIFT (3U)
/*! tx_data_rate - LE Tx Packet Data Rate, 0x0: Tx packet data rate 1 Mbps, 0x1: Tx packet data rate 2 Mbps
 *  0b0..Tx packet data rate 1 Mbps
 *  0b1..Tx packet data rate 2 Mbps
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_DATA_RATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_TX_DATA_RATE_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_TX_DATA_RATE_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_LENGTH_EXT_MASK (0x10U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_LENGTH_EXT_SHIFT (4U)
/*! data_length_ext - LE Data Length Extension. Should be 0 when iso_pdu_sel is 1, 0x0: disable;
 *    support up to 31 bytes of payload for data channel PDU, 0x1: enable; support up to 255 bytes; or
 *    251 bytes for encryption packet; of payload, for data channel PDU
 *  0b0..disable; support up to 31 bytes of payload for data channel PDU
 *  0b1..enable; support up to 255 bytes, or 251 bytes for encryption packet, of payload for data channel PDU
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_LENGTH_EXT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_LENGTH_EXT_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_DATA_LENGTH_EXT_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_ADVT_LENGTH_EXT_MASK (0x20U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_ADVT_LENGTH_EXT_SHIFT (5U)
/*! advt_length_ext - LE Advertising Length Extension. Should be 0 when iso_pdu_sel is 1, 0x0:
 *    disable; support up to 37 bytes of payload for advertising channel PDU, 0x1: enable; support up to
 *    255 bytes of payload for advertising channel PDU
 *  0b0..disable; support up to 37 bytes of payload for advertising channel PDU
 *  0b1..enable; support up to 255 bytes of payload for advertising channel PDU
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_ADVT_LENGTH_EXT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_ADVT_LENGTH_EXT_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_ADVT_LENGTH_EXT_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_ISO_PDU_SEL_MASK (0x40U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_ISO_PDU_SEL_SHIFT (6U)
/*! iso_pdu_sel - Select ISO PDU type, 0x0: data_chan_pkt=0 selects Data PDU. data_chan_pkt=1
 *    selects Adv PDU, 0x1: data_chan_pkt=0 selects BIS PDU. data_chan_pkt=1 selects CIS PDU
 *  0b0..data_chan_pkt=0 selects Data PDU. data_chan_pkt=1 selects Adv PDU
 *  0b1..data_chan_pkt=0 selects BIS PDU. data_chan_pkt=1 selects CIS PDU
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_ISO_PDU_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_ISO_PDU_SEL_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_ISO_PDU_SEL_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_DIRECT_TEST_MODE_MASK (0x80U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_DIRECT_TEST_MODE_SHIFT (7U)
/*! direct_test_mode - BLE direct test mode, 0x0: BLE in normal mode, 0x1: BLE in direct test mode
 *    (bypass Rx packet length < 6 check in adv mode)
 *  0b0..BLE in normal mode
 *  0b1..BLE in direct test mode (bypass Rx packet length < 6 check in adv mode)
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_DIRECT_TEST_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_DIRECT_TEST_MODE_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_DIRECT_TEST_MODE_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_CHANNEL_INDEX_MASK (0x3F00U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_CHANNEL_INDEX_SHIFT (8U)
/*! channel_index - Channel Index Value for Whitening Initialization */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_CHANNEL_INDEX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_CHANNEL_INDEX_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_CHANNEL_INDEX_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_EN_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_EN_SHIFT (14U)
/*! tx_extn_en - Tx Extension Packet, Tx Extension Packet, 0x0: transmit data extension; regular;
 *    non-location BLE transmit packet, 0x1: transmit data extension; transmit extension field for
 *    current packet
 *  0b0..transmit data extension; regular, non-location BLE transmit packet
 *  0b1..transmit data extension; transmit extension field for current packet
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_EN_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_EN_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_WHIT_DIS_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_WHIT_DIS_SHIFT (15U)
/*! whit_dis - Disable Whitening, 0x0: enable, 0x1: disable
 *  0b0..enable
 *  0b1..disable
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_WHIT_DIS(x)  (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_WHIT_DIS_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_WHIT_DIS_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_LENGTH_MAX_MASK (0xFF0000U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_LENGTH_MAX_SHIFT (16U)
/*! rx_length_max - Maximum Length for rx_length_err, - For Advt Channel: 37 (if advt_length_ext =
 *    0) or 255 (if advt_length_ext = 1)., - For Data Channel: 31 (if data_length_ext = 0 and
 *    ccm_en_rx = 0) or, 27 (if data_length_ext = 0 and ccm_en_rx = 1) or, 255 (if data_length_ext = 1 and
 *    ccm_en_rx = 0) or, 251 (if data_length_ext = 1 and ccm_en_rx = 1).
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_LENGTH_MAX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_RX_LENGTH_MAX_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_RX_LENGTH_MAX_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_LENGTH_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_LENGTH_SHIFT (24U)
/*! tx_extn_length - Tx Extension Length for Tx DFE Packet, Length of extension field to be
 *    transmitted. This value is in the unit of 8 usec time frame and includes the guard period (for
 *    example; spec defined 1~4 usec) between CRC and the antenna switching part of extension., This bit is
 *    valid only when tx_extn_en is set.
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_LENGTH_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_TX_EXTN_LENGTH_MASK)

#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_RF_AGC_INDEX_MASK (0xE0000000U)
#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_RF_AGC_INDEX_SHIFT (29U)
/*! rx_rf_agc_index - BRF Rx Power Control Index, BRF Rx power control setting that is programmed
 *    into the BRF_RX_PKT_STATUS[7:5] register., These index bits are taken effect only when RIF
 *    register BTU_RIF_CTL0[1] is set.
 */
#define BLE2_REG_BLE_REG_TXRX_CNTRL_RX_RF_AGC_INDEX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CNTRL_RX_RF_AGC_INDEX_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CNTRL_RX_RF_AGC_INDEX_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CRC_INIT_VAL - CRC Initialization Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CRC_INIT_VAL_CRC_INIT_VALUE_MASK (0xFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CRC_INIT_VAL_CRC_INIT_VALUE_SHIFT (0U)
/*! crc_init_value - CRC Initialization Value */
#define BLE2_REG_BLE_REG_TXRX_CRC_INIT_VAL_CRC_INIT_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CRC_INIT_VAL_CRC_INIT_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CRC_INIT_VAL_CRC_INIT_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TX_ACC_ADDR - Tx Access Address, for Advt and Data Packets */
/*! @{ */

#define BLE2_REG_BLE_REG_TX_ACC_ADDR_TX_ACCESS_ADDRESS_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TX_ACC_ADDR_TX_ACCESS_ADDRESS_SHIFT (0U)
/*! tx_access_address - Access Address for Tx Packet */
#define BLE2_REG_BLE_REG_TX_ACC_ADDR_TX_ACCESS_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_ACC_ADDR_TX_ACCESS_ADDRESS_SHIFT)) & BLE2_REG_BLE_REG_TX_ACC_ADDR_TX_ACCESS_ADDRESS_MASK)
/*! @} */

/*! @name BLE_REG_RX_PKT_STATUS - Rx Packet Status, for Advt and Data Packets */
/*! @{ */

#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PKT_HEADER_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PKT_HEADER_SHIFT (0U)
/*! rx_pkt_header - Rx Packet PDU Header */
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PKT_HEADER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PKT_HEADER_SHIFT)) & BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PKT_HEADER_MASK)

#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_EXTN_SUPPL_INFO_MASK (0xFF0000U)
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_EXTN_SUPPL_INFO_SHIFT (16U)
/*! rx_extn_suppl_info - Rx Packet Supplemental Info Byte if available */
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_EXTN_SUPPL_INFO(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_EXTN_SUPPL_INFO_SHIFT)) & BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_EXTN_SUPPL_INFO_MASK)

#define BLE2_REG_BLE_REG_RX_PKT_STATUS_SIMUL_SCAN_CODED_EN_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_SIMUL_SCAN_CODED_EN_SHIFT (24U)
/*! simul_scan_coded_en - Detected Rx Coded Packet Correlation Hit in Simultaneous Scan Mode, 0x0:
 *    Detected BLE 1M Packet Correlation Hit or no correlation at all in Simultaneous, Scan Mode,
 *    0x1: Detected Rx Coded Packet Correlation Hit in Simultaneous Scan Mode
 *  0b0..Detected BLE 1M Packet Correlation Hit or no correlation at all in Simultaneous Scan Mode
 *  0b1..Detected Rx Coded Packet Correlation Hit in Simultaneous Scan Mode
 */
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_SIMUL_SCAN_CODED_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_PKT_STATUS_SIMUL_SCAN_CODED_EN_SHIFT)) & BLE2_REG_BLE_REG_RX_PKT_STATUS_SIMUL_SCAN_CODED_EN_MASK)

#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PREAMBLE_MATCH_STS_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PREAMBLE_MATCH_STS_SHIFT (25U)
/*! rx_preamble_match_sts - Detected Rx Preamble Match during BLE Long Range RX, 0x0: Preamble has
 *    not been detected on most recent RX in long range mode., 0x1: Preamble has been detected on
 *    most recent RX in long range mode. This indication, resets at the start of next RX
 *  0b0..Preamble has not been detected on most recent RX in long range mode.
 *  0b1..Preamble has been detected on most recent RX in long range mode. This indication resets at the start of next RX
 */
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PREAMBLE_MATCH_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PREAMBLE_MATCH_STS_SHIFT)) & BLE2_REG_BLE_REG_RX_PKT_STATUS_RX_PREAMBLE_MATCH_STS_MASK)

#define BLE2_REG_BLE_REG_RX_PKT_STATUS_BLE_RX_CODED_PKT_INDIC_STS_MASK (0xC000000U)
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_BLE_RX_CODED_PKT_INDIC_STS_SHIFT (26U)
/*! ble_rx_coded_pkt_indic_sts - Coding Indicator (CI) value received during BLE Long Range RX. This
 *    field indicates the, coding rate of the FEC Block 2 of the LR Rx packet and is valid from
 *    rx_hdr_done_intr till start of next Rx packet, 0x0: FEC Block 2 coded using S=8., 0x1: FEC Block
 *    2 coded using S=2.
 */
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_BLE_RX_CODED_PKT_INDIC_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_PKT_STATUS_BLE_RX_CODED_PKT_INDIC_STS_SHIFT)) & BLE2_REG_BLE_REG_RX_PKT_STATUS_BLE_RX_CODED_PKT_INDIC_STS_MASK)

#define BLE2_REG_BLE_REG_RX_PKT_STATUS_ADV_ADDR_NOT_PRESENT_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_ADV_ADDR_NOT_PRESENT_SHIFT (28U)
/*! adv_addr_not_present - This bit indicates if advertiser address is present or absent for each
 *    advertising packet received, 0x0: Advertiser address is present in extended advertising packet
 *    received; or, received packet is a legacy advertising packet, 0x1: Advertiser address is not
 *    present in extended advertising packet received
 */
#define BLE2_REG_BLE_REG_RX_PKT_STATUS_ADV_ADDR_NOT_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_PKT_STATUS_ADV_ADDR_NOT_PRESENT_SHIFT)) & BLE2_REG_BLE_REG_RX_PKT_STATUS_ADV_ADDR_NOT_PRESENT_MASK)
/*! @} */

/*! @name BLE_REG_RX_CNTRL - Receive Packet Control */
/*! @{ */

#define BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_MASK (0xFFU)
#define BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_SHIFT (0U)
/*! rx_cntrl_length_max - Maximum Control PDU Length for rx_length_err, This is the length of max
 *    length Control PDUs., This field is used only if rx_cntrl_length_max_sel is set to 1.
 */
#define BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_SHIFT)) & BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_MASK)

#define BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_sel_MASK (0x100U)
#define BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_sel_SHIFT (8U)
/*! rx_cntrl_length_max_sel - Select Length Check Register for Control PDUs, 0x0: select
 *    rx_length_max for control PDU length check, 0x1: select rx_cntrl_length_max for control PDU length check
 */
#define BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_sel(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_sel_SHIFT)) & BLE2_REG_BLE_REG_RX_CNTRL_rx_cntrl_length_max_sel_MASK)

#define BLE2_REG_BLE_REG_RX_CNTRL_reuse_rx_adv_addr_done_intr_MASK (0x200U)
#define BLE2_REG_BLE_REG_RX_CNTRL_reuse_rx_adv_addr_done_intr_SHIFT (9U)
/*! reuse_rx_adv_addr_done_intr - Allow reuse of rx_adv_addr_done_intr for indicating the absence of
 *    advertiser address in the received advertising channel PDU, 0x0: rx_adv_addr_done_intr = 1
 *    for legacy and extended advertising channel packets, received with advertiser address
 *    rx_adv_addr_done_intr = 0 for extended, advertising channel packets received without advertiser address,
 *    0x1: rx_adv_addr_done_intr = 1 for legacy and extended advertising channel packets, with
 *    advertiser address and extended advertising channel , packets received without advertiser address
 *    (in conjunction with, adv_addr_not_present)
 */
#define BLE2_REG_BLE_REG_RX_CNTRL_reuse_rx_adv_addr_done_intr(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_CNTRL_reuse_rx_adv_addr_done_intr_SHIFT)) & BLE2_REG_BLE_REG_RX_CNTRL_reuse_rx_adv_addr_done_intr_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CCM_CNTRL - CCM Operation (encryption/authentication) Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_TX_MASK (0x1U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_TX_SHIFT (0U)
/*! ccm_en_tx - CCM (Encryption/Authentication) Enable for Tx packet */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_TX_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_TX_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_RX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_RX_SHIFT (1U)
/*! ccm_en_rx - CCM (Encryption/Authentication) Enable for Rx packet */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_RX_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_CCM_EN_RX_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_TX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_TX_SHIFT (2U)
/*! auth_disable_tx - When ccm_en_tx = 1; setting 1 for CCM Enable for Tx Packet with encryption only and no authentication. */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_TX_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_TX_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_RX_MASK (0x8U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_RX_SHIFT (3U)
/*! auth_disable_rx - When ccm_en_rx = 1; setting 1 for CCM Enable for Rx Packet with encryption only and no authentication. */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_RX_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_AUTH_DISABLE_RX_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_MASK (0x100U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_SHIFT (8U)
/*! inc_Tx_Pkt_Cnt - Increment Tx CCM Packet Count */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_MASK (0x100U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_SHIFT (8U)
/*! inc_tx_pkt_cnt - Increment Tx CCM Packet Count, For each new Tx packet; writing 1 will increment
 *    the value in BLE_REG_TX_CCM_PKT_CNT_0/1 registers by 1. This bit is self-cleared by hardware.
 */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_TX_PKT_CNT_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_SHIFT (9U)
/*! inc_Rx_Pkt_Cnt - Increment Rx CCM Packet Count */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_SHIFT (9U)
/*! inc_rx_pkt_cnt - Increment Rx CCM Packet Count, For each new Rx packet; writing 1 will increment
 *    the value in BLE_REG_RX_CCM_PKT_CNT_0/1 registers by 1. This bit is self-cleared by hardware.
 */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_INC_RX_PKT_CNT_MASK)

#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_SK_DECIP_GO_MASK (0x10000U)
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_SK_DECIP_GO_SHIFT (16U)
/*! sk_decip_go - Manually Invoke SK_Decipher Function */
#define BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_SK_DECIP_GO(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_SK_DECIP_GO_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CCM_CNTRL_SK_DECIP_GO_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CORHIT_QUS_TIMESTAMP - Quarter microsecond level timestamp */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CORHIT_QUS_TIMESTAMP_CORHIT_TIMESTAMP_QUS_MASK (0x7FFU)
#define BLE2_REG_BLE_REG_TXRX_CORHIT_QUS_TIMESTAMP_CORHIT_TIMESTAMP_QUS_SHIFT (0U)
/*! corhit_timestamp_qus - QUS level timestamp, This QUS timestamp is updated at correlation hit interrupt. */
#define BLE2_REG_BLE_REG_TXRX_CORHIT_QUS_TIMESTAMP_CORHIT_TIMESTAMP_QUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CORHIT_QUS_TIMESTAMP_CORHIT_TIMESTAMP_QUS_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CORHIT_QUS_TIMESTAMP_CORHIT_TIMESTAMP_QUS_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CORHIT_MCCLOCK_TIMESTAMP - Native clock timestamp */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CORHIT_MCCLOCK_TIMESTAMP_CORHIT_TIMESTAMP_CLOCK_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_CORHIT_MCCLOCK_TIMESTAMP_CORHIT_TIMESTAMP_CLOCK_SHIFT (0U)
/*! corhit_timestamp_clock - Native clock value timestamp, Lower 28 bits are same as BTC native
 *    clock. Upper 4 bits are carry from BTC native clock wraps. This timestamp is updated at
 *    correlation hit interrupt.
 */
#define BLE2_REG_BLE_REG_TXRX_CORHIT_MCCLOCK_TIMESTAMP_CORHIT_TIMESTAMP_CLOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CORHIT_MCCLOCK_TIMESTAMP_CORHIT_TIMESTAMP_CLOCK_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CORHIT_MCCLOCK_TIMESTAMP_CORHIT_TIMESTAMP_CLOCK_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_PKTEND_QUS_TIMESTAMP - Quarter microsecond level timestamp */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_PKTEND_QUS_TIMESTAMP_PKTEND_TIMESTAMP_QUS_MASK (0x7FFU)
#define BLE2_REG_BLE_REG_TXRX_PKTEND_QUS_TIMESTAMP_PKTEND_TIMESTAMP_QUS_SHIFT (0U)
/*! pktend_timestamp_qus - QUS level timestamp, This QUS timestamp is updated at tx or rx packet
 *    ends including normal tx/rx packet ends; hw/sw aborts and rx corrlation timeout.
 */
#define BLE2_REG_BLE_REG_TXRX_PKTEND_QUS_TIMESTAMP_PKTEND_TIMESTAMP_QUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_PKTEND_QUS_TIMESTAMP_PKTEND_TIMESTAMP_QUS_SHIFT)) & BLE2_REG_BLE_REG_TXRX_PKTEND_QUS_TIMESTAMP_PKTEND_TIMESTAMP_QUS_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_PKTEND_MCCLOCK_TIMESTAMP - Native clock timestamp */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_PKTEND_MCCLOCK_TIMESTAMP_PKTEND_TIMESTAMP_CLOCK_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TXRX_PKTEND_MCCLOCK_TIMESTAMP_PKTEND_TIMESTAMP_CLOCK_SHIFT (0U)
/*! pktend_timestamp_clock - Native clock value timestamp, Lower 28 bits are same as BTC native
 *    clock. Upper 4 bits are carry from BTC native clock wraps. This timestamp is updated at tx or rx
 *    packet ends including normal tx/rx packet ends; hw/sw aborts and rx corrlation timeout.
 */
#define BLE2_REG_BLE_REG_TXRX_PKTEND_MCCLOCK_TIMESTAMP_PKTEND_TIMESTAMP_CLOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_PKTEND_MCCLOCK_TIMESTAMP_PKTEND_TIMESTAMP_CLOCK_SHIFT)) & BLE2_REG_BLE_REG_TXRX_PKTEND_MCCLOCK_TIMESTAMP_PKTEND_TIMESTAMP_CLOCK_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_ERR_INJ_CNTRL - TxRx Error Injection Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_EN_SHIFT (0U)
/*! err_inj_en - Software error injection enable, 0x0: disable error injection, 0x1: enable error injection
 *  0b0..disable error injection
 *  0b1..enable error injection
 */
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_EN_SHIFT)) & BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_EN_MASK)

#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_DIR_MASK (0x2U)
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_DIR_SHIFT (1U)
/*! err_inj_dir - software error injection direction, 0x0: error injection on Tx side, 0x1: error injection on Rx side
 *  0b0..error injection on Tx side
 *  0b1..error injection on Rx side
 */
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_DIR_SHIFT)) & BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_DIR_MASK)

#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_TIMER_MASK (0x1FFCU)
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_TIMER_SHIFT (2U)
/*! err_inj_timer - software error injection timer, Packet bit position (1;2;..N) to start error
 *    injection if err_inj_en is set. Tx bit error can be injected from preamble to crc; so position 1
 *    is first preamble bit. Rx bit error can be injected from header to crc; so position 1 is first
 *    header bit.
 */
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_TIMER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_TIMER_SHIFT)) & BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_TIMER_MASK)

#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMEM_CRC_COR_MASK (0x2000U)
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMEM_CRC_COR_SHIFT (13U)
/*! tx_dmem_crc_cor - hardware Tx DMEM underflow CRC corruption enable, Enable CRC corruption at
 *    first 16-bit of Tx CRC if Tx DMEM underflow error interrupt is detected. Only valid when software
 *    controlled err_inj_en is zero. All the CRC bits transmitted will be inverted to cause CRC
 *    failure on the receiving device., 0x0: disable, 0x1: enable
 *  0b0..disable error injection
 *  0b1..enable error injection
 */
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMEM_CRC_COR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMEM_CRC_COR_SHIFT)) & BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMEM_CRC_COR_MASK)

#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_AES_CRC_COR_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_AES_CRC_COR_SHIFT (14U)
/*! tx_aes_crc_cor - hardware Tx AES underflow CRC corruption enable, Enable CRC corruption at first
 *    16-bit of Tx CRC if Tx AES underflow error interrupt is detected. Only valid when software
 *    controlled err_inj_en is zero. All the CRC bits transmitted will be inverted to cause CRC
 *    failure on the receiving device., 0x0: disable, 0x1: enable
 *  0b0..disable error injection
 *  0b1..enable error injection
 */
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_AES_CRC_COR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_AES_CRC_COR_SHIFT)) & BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_AES_CRC_COR_MASK)

#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMA_CRC_COR_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMA_CRC_COR_SHIFT (15U)
/*! tx_dma_crc_cor - hardware Tx DMA CRC corruption enable, Enable CRC corruption at first 16-bit of
 *    Tx CRC if Tx DMA error interrupt is detected. Only valid when software controlled err_inj_en
 *    is zero. All the CRC bits transmitted will be inverted to cause CRC failure on the receiving
 *    device., 0x0: disable, 0x1: enable
 *  0b0..disable error injection
 *  0b1..enable error injection
 */
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMA_CRC_COR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMA_CRC_COR_SHIFT)) & BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_TX_DMA_CRC_COR_MASK)

#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_PATTERN_MASK (0xFFFF0000U)
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_PATTERN_SHIFT (16U)
/*! err_inj_pattern - 16-Bit Error injection pattern, 0x0: do not flip the bit, 0x1: flip the bit
 *  0b0000000000000000..do not flip the bit
 *  0b0000000000000001..flip the bit
 */
#define BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_PATTERN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_PATTERN_SHIFT)) & BLE2_REG_BLE_REG_TXRX_ERR_INJ_CNTRL_ERR_INJ_PATTERN_MASK)
/*! @} */

/*! @name BLE_REG_TXRX_CRC_CORRUPT - TxRx CRC Corruption Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMEM_CRC_COR_MASK (0x1U)
#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMEM_CRC_COR_SHIFT (0U)
/*! rx_dmem_crc_cor - hardware Rx DMEM underflow CRC corruption enable, Set this enable to enable
 *    CRC corruption if Rx DMEM underflow error interrupt is detected. Only valid when software
 *    controlled err_inj_en is zero. The crc_success bit is flipped at the end of Rx., 0x0: disable, 0x1:
 *    enable
 *  0b0..disable error injection
 *  0b1..enable error injection
 */
#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMEM_CRC_COR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMEM_CRC_COR_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMEM_CRC_COR_MASK)

#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_AES_CRC_COR_MASK (0x2U)
#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_AES_CRC_COR_SHIFT (1U)
/*! rx_aes_crc_cor - hardware Rx AES underflow CRC corruption enable, Set this enable to enable CRC
 *    corruption if Rx AES underflow error interrupt is detected. Only valid when software
 *    controlled err_inj_en is zero. The crc_success bit is flipped at the end of Rx, 0x0: disable, 0x1:
 *    enable
 *  0b0..disable error injection
 *  0b1..enable error injection
 */
#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_AES_CRC_COR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_AES_CRC_COR_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_AES_CRC_COR_MASK)

#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMA_CRC_COR_MASK (0x4U)
#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMA_CRC_COR_SHIFT (2U)
/*! rx_dma_crc_cor - hardware Rx DMA CRC corruption enable, Set this enable to enable CRC corruption
 *    if Rx DMA error interrupt is detected. Only valid when software controlled err_inj_en is
 *    zero. The crc_success bit is flipped at the end of Rx., 0x0: disable, 0x1: enable
 *  0b0..disable error injection
 *  0b1..enable error injection
 */
#define BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMA_CRC_COR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMA_CRC_COR_SHIFT)) & BLE2_REG_BLE_REG_TXRX_CRC_CORRUPT_RX_DMA_CRC_COR_MASK)
/*! @} */

/*! @name BLE_REG_RL_DELAY - BLE Register Loader Delay Register */
/*! @{ */

#define BLE2_REG_BLE_REG_RL_DELAY_coex_lock_delay_MASK (0xFU)
#define BLE2_REG_BLE_REG_RL_DELAY_coex_lock_delay_SHIFT (0U)
/*! coex_lock_delay - Register Loader ALternate Start Address, Programmable delay in quarter
 *    microseconds after btu_bt_req assertion to MRC when Coex lock fail condition is checked in BTU. MRC
 *    samples TX power and TX/RX frequency value from BTU after sampling all bt_state serial
 *    information. This delay is used to give more time for first 8 bytes of RL.
 */
#define BLE2_REG_BLE_REG_RL_DELAY_coex_lock_delay(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_DELAY_coex_lock_delay_SHIFT)) & BLE2_REG_BLE_REG_RL_DELAY_coex_lock_delay_MASK)
/*! @} */

/*! @name BLE_REG_RL_START_ADDR_ALT - Register Loader Alternate Start Address */
/*! @{ */

#define BLE2_REG_BLE_REG_RL_START_ADDR_ALT_rl_start_address_alt_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_RL_START_ADDR_ALT_rl_start_address_alt_SHIFT (0U)
/*! rl_start_address_alt - Register Loader ALternate Start Address, This points to the alternate
 *    start address of memory structure that ble_reg_ldr should fetch from. This pointer is the only
 *    used when RL_alt is 1. In alternating mode; every alternate Register Loading is done from this
 *    pointer. Only Bits 15:0 are used from this register. The upper 16-bits are reused from
 *    BLE_REG_RL_START_ADDR
 */
#define BLE2_REG_BLE_REG_RL_START_ADDR_ALT_rl_start_address_alt(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_START_ADDR_ALT_rl_start_address_alt_SHIFT)) & BLE2_REG_BLE_REG_RL_START_ADDR_ALT_rl_start_address_alt_MASK)
/*! @} */

/*! @name BLE_REG_RL_START_ADDR - Register Loader Start Address */
/*! @{ */

#define BLE2_REG_BLE_REG_RL_START_ADDR_RL_START_ADDRESS_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_RL_START_ADDR_RL_START_ADDRESS_SHIFT (0U)
/*! rl_start_address - Register Loader Start Address, This points to the start address of memory structure that ble_reg_ldr should fetch from. */
#define BLE2_REG_BLE_REG_RL_START_ADDR_RL_START_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_START_ADDR_RL_START_ADDRESS_SHIFT)) & BLE2_REG_BLE_REG_RL_START_ADDR_RL_START_ADDRESS_MASK)
/*! @} */

/*! @name BLE_REG_RL_CNTRL_STS - Register Loader Control and Status */
/*! @{ */

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_CCM_MASK (0x1U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_CCM_SHIFT (0U)
/*! load_ccm - Load CCM related memory content, For each new Connection Event; writing 1 will
 *    trigger BLE register loader to load only CCM related memory contents (memory offset = 0x20~44) to
 *    their BLE registers. This bit should be set along with load_non_ccm bit for packet events; to
 *    enable correct DBUS programming.This bit is self-cleared by hardware.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_CCM(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_CCM_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_CCM_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_NON_CCM_MASK (0x2U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_NON_CCM_SHIFT (1U)
/*! load_non_ccm - Load non-CCM related memory content, For each new Connection Event; writing 1
 *    will trigger BLE register loader to load non-CCM related memory contents (memory offset =
 *    0x00~1C) to their BLE registers. This bit is self-cleared by hardware.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_NON_CCM(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_NON_CCM_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_LOAD_NON_CCM_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_CCM_MASK (0x4U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_CCM_SHIFT (2U)
/*! auto_load_ccm - Auto Load CCM related memory content, For each new Connection Event; writing 1
 *    will trigger BLE register loader to load only CCM related memory contents (memory offset =
 *    0x20~44) to their BLE registers at every start_rif_tx/start_rif_rx. This bit should be set along
 *    with auto_load_non_ccm bit for packet events; to enable correct DBUS programming. This bit is
 *    self-cleared by hardware.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_CCM(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_CCM_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_CCM_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_NON_CCM_MASK (0x8U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_NON_CCM_SHIFT (3U)
/*! auto_load_non_ccm - Auto Load non-CCM related memory content, For each new Connection Event;
 *    writing 1 will trigger BLE register loader to load non-CCM related memory contents (memory offset
 *    = 0x00~1C) to their BLE registers. This bit is self-cleared by hardware.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_NON_CCM(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_NON_CCM_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_AUTO_LOAD_NON_CCM_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_LOCK_MASK (0x10U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_LOCK_SHIFT (4U)
/*! rl_lock - BLE Register Loader Lock bit, For each new Connection Event; rl_lock serves as
 *    Register Loader lock bit. It should be set along with load_ccm or load_non_ccm bit or before
 *    start_rif_tx/rx time if using auto_load_ccm or auto_load_non_ccm bits. It must remain set for the
 *    duration of packets that the Register Loader values are in effect. At the end of last packet; the
 *    rl_lock bit should be cleared by firmware. This bit is used to generate rx_lock_fail_intr or
 *    tx_lock_fail_intr.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_LOCK_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_LOCK_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_EN_MASK (0x20U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_EN_SHIFT (5U)
/*! sk_decip_en - BLE SK_Decipher Mode Enable */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_EN_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_EN_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_MASK (0x40U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_SHIFT (6U)
/*! rl_alt - BLE Register Loader Alternate Mode Enable, Indicates which RL_START_ADDR is to be
 *    used., 0x0: Always use RL_START_ADDR., 0x1: Use Toggle mode where RL_START_ADDR and
 *    RL_START_ADDR_ALT are used for, alternating register loading.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT(x)  (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_RESET_MASK (0x80U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_RESET_SHIFT (7U)
/*! rl_alt_reset - BLE Register Loader Alternate Mode Reset, One-shot reset command to HW to use
 *    RL_START_ADDR pointer for the next register loading; regardless of which pointer was used in
 *    previous register loading. Self cleared by HW.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_RESET_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_ALT_RESET_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_COEX_LOCK_BYPASS_MASK (0x100U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_COEX_LOCK_BYPASS_SHIFT (8U)
/*! coex_lock_bypass - BLE Register Loader Coex Lock Bypass bit, Config bit to bypass coex lock fail
 *    detection on Register loader. Coex lock fail check can be bypassed by setting this bit to 1.
 *    This setting can be used if FW can pre-program the TX power and TX/RX frequency values in
 *    advance of a connection event without using register loader.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_COEX_LOCK_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_COEX_LOCK_BYPASS_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_COEX_LOCK_BYPASS_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_CCM_DONE_MASK (0x1FF00U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_CCM_DONE_SHIFT (8U)
/*! rl_ccm_done - Done loading CCM memory, Register Loader has done loading CCM related memory
 *    content into their BLE registers., 0x0: Not done., 0x1: Done loading.
 *  0b0..Not done.
 *  0b1..Done loading.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_CCM_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_CCM_DONE_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_CCM_DONE_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_NON_CCM_DONE_MASK (0x3FE00U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_NON_CCM_DONE_SHIFT (9U)
/*! rl_non_ccm_done - Done loading non-CCM memory, Register Loader has done loading non-CCM related
 *    memory content into their BLE registers., 0x0: Not done., 0x1: Done loading.
 *  0b0..Not done.
 *  0b1..Done loading.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_NON_CCM_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_NON_CCM_DONE_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_NON_CCM_DONE_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_BUSY_MASK (0x7FC00U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_BUSY_SHIFT (10U)
/*! rl_busy - Register Loader busy, Status indicating BLE Register Loader is busy. Asserted when
 *    fetching memory starts and de-asserted right after done writing to BLE registers., 0x0: Register
 *    Loader is idle., 0x1: Register Loader is busy.
 *  0b0..Register Loader is idle.
 *  0b1..Register Loader is busy.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_BUSY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_BUSY_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_BUSY_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DMA_ERR_MASK (0xFF800U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DMA_ERR_SHIFT (11U)
/*! rl_dma_err - Register Loader Has DMA Error, Register Loader experienced DMA error., 0x0: No
 *    error, 0x1: SoC DMA slave has replied with ERROR response during Register Loader read, transfers.
 *  0b0..No error
 *  0b1..SoC DMA slave has replied with ERROR response during Register Loader read transfers.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DMA_ERR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DMA_ERR_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DMA_ERR_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_DONE_MASK (0x1000U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_DONE_SHIFT (12U)
/*! sk_decip_done - SK_Decipher Done
 *  0b0..No done
 *  0b1..Done.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_DONE_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_SK_DECIP_DONE_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_COEX_DONE_MASK (0x200000U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_COEX_DONE_SHIFT (21U)
/*! rl_coex_done - Coex Register Loading Done, Indicating Coex related register loading is done;
 *    i.e. the first 8 bytes of register loader., 0x0: Not done., 0x1: Done.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_COEX_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_COEX_DONE_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_COEX_DONE_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DBUS_DONE_MASK (0x400000U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DBUS_DONE_SHIFT (22U)
/*! rl_dbus_done - DBUS Register Loading Done, Indicating DBUS WDATA loading is done for the first
 *    12 bytes of register loader., 0x0: Not done., 0x1: Done.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DBUS_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DBUS_DONE_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_DBUS_DONE_MASK)

#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_AT_CURR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_AT_CURR_SHIFT (23U)
/*! rl_at_curr - Register Loader Alternate Pointer, Indicates which RL pointer is currently in use.
 *    When RL_alt = 0; this bit is always 0. when RL_alt = 1; this bit toggles for every register
 *    loading to indicate the Register Loader in use.
 */
#define BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_AT_CURR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_AT_CURR_SHIFT)) & BLE2_REG_BLE_REG_RL_CNTRL_STS_RL_AT_CURR_MASK)
/*! @} */

/*! @name BLE_REG_DFE_PKT_EXTENSION_CNTRL - Tx/Rx Packet Extension Control */
/*! @{ */

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_TX_EXTN_PATTERN_MASK (0x1U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_TX_EXTN_PATTERN_SHIFT (0U)
/*! tx_extn_pattern - Tx Packet Extension Pattern, The value programmed in this bit reflects what
 *    will be sent out during the extension part of the Tx location packet. This value is also sent
 *    during the guard time at the beginning of the extension field., This bit is valid ONLY when
 *    tx_extn_en is set., 0x0: send 0000..., 0x1: send 1111...
 *  0b0..send 0000...
 *  0b1..send 1111...
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_TX_EXTN_PATTERN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_TX_EXTN_PATTERN_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_TX_EXTN_PATTERN_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_DELAY_EXTN_END_MASK (0x2U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_DELAY_EXTN_END_SHIFT (1U)
/*! delay_extn_end - Extension Packet Delay CDT, Define whether to delay CDT timer to start at
 *    packet estimated end time if extension field is corrupted due to antSwitchStatus (for example; BCA
 *    antenna is not honored) de-assertion; or due to BCA grant loss., If it is set; CDT timer needs
 *    to be delayed to the estimated end of extension filed time to line up the TIFS for next
 *    packet., If it is not set; for the same conditions; do not perform any CDT manipulation in
 *    hardware. This setting might cause BLE not to be able to Tx or Rx following the packet extension
 *    corruption., 0x0: do not perform any CDT manipulation in hardware, 0x1: delay CDT timer to the
 *    estimated end of extension
 *  0b0..do not perform any CDT manipulation in hardware
 *  0b1..delay CDT timer to the "estimated" end of extension
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_DELAY_EXTN_END(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_DELAY_EXTN_END_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_DELAY_EXTN_END_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_MASK (0xCU)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_SHIFT (2U)
/*! rx_iq_sample_rate - Rx IQ Sampling Rate, Define reception rate for IQ samples in extension
 *    field., 0x0: receive IQ sample every 4 usec, 0x1: receive IQ sample every 2 usec, 0x2: receive IQ
 *    sample every 1 usec, 0x3: not valid
 *  0b00..receive IQ sample every 4 usec
 *  0b01..receive IQ sample every 2 usec
 *  0b10..receive IQ sample every 1 usec
 *  0b11..not valid
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_GUARD_TIME_MASK (0x30U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_GUARD_TIME_SHIFT (4U)
/*! extn_guard_time - Extension Packet Guard Time, Define the guard interval between the CRC and
 *    extension supplementals in the unit of usec., 0x0: guard interval is 1 usec, 0x1: guard interval
 *    is 2 usec, 0x2: guard interval is 3 usec, 0x3: guard interval is 4 usec
 *  0b00..guard interval is 1 usec
 *  0b01..guard interval is 2 usec
 *  0b10..guard interval is 3 usec
 *  0b11..guard interval is 4 usec
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_GUARD_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_GUARD_TIME_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_GUARD_TIME_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_REF_ANT_TIME_MASK (0xC0U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_REF_ANT_TIME_SHIFT (6U)
/*! extn_ref_ant_time - Extension Reference Antenna IQ Sample Time, Define the reference antenna
 *    interval after the extension guard time and before switching antenna in the unit of usec. During
 *    this interval; IQ samples received is considered in the same of which the reference antenna is
 *    used., 0x0: reference antenna interval is 0 usec, 0x1: reference antenna interval is 2 usec,
 *    0x2: reference antenna interval is 4 usec, 0x3: reference antenna interval is 8 usec
 *  0b00..reference antenna interval is 0 usec
 *  0b01..reference antenna interval is 2 usec
 *  0b10..reference antenna interval is 4 usec
 *  0b11..reference antenna interval is 8 usec
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_REF_ANT_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_REF_ANT_TIME_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_EXTN_REF_ANT_TIME_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_EN_MASK (0x10000U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_EN_SHIFT (16U)
/*! rx_extn_en - Rx Packet Extension Enable, Enable bit of Rx extension packet., 0x0: disable to
 *    receive data extension, 0x1: enable to receive data extension
 *  0b0..disable to receive data extension
 *  0b1..enable to receive data extension
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_EN_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_EN_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_RCV_OVERRIDE_MASK (0x20000U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_RCV_OVERRIDE_SHIFT (17U)
/*! rx_iq_sample_rate_rcv_override - Rx Packet Extension IQ Sample Rate Override, When this is set
 *    and received packet is an AoD packet with extension field; IQ sample rate is derived from
 *    received supplemental type field of supplemental info byte; which is considered to override the
 *    software preset sample rate.
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_RCV_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_RCV_OVERRIDE_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_IQ_SAMPLE_RATE_RCV_OVERRIDE_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_EN_MASK (0x40000U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_EN_SHIFT (18U)
/*! rx_extn_sw_override_en - Rx Extension Packet Software Override, Software enable bit to override
 *    rx_extn_rcv and rx_extn_length from Rx PDU header., 0x0: disable software override, 0x1:
 *    enable software override
 *  0b0..disable software override
 *  0b1..enable software override
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_EN_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_EN_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_RCV_MASK (0x80000U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_RCV_SHIFT (19U)
/*! rx_extn_sw_override_rcv - Extension Packet Received Software Override, The value of rx_extn_rcv
 *    to which software overrides., This bit is used ONLY when rx_extn_sw_override_en bit is set.
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_RCV(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_RCV_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_RCV_MASK)

#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_SUPPL_INFO_MASK (0xFF000000U)
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_SUPPL_INFO_SHIFT (24U)
/*! rx_extn_sw_override_suppl_info - Rx Extension Supplemental Info Byte Software Override, The
 *    value of rx_extn_length as of rx_extn_suppl_info[4:0] to which software overrides., The value of
 *    rx_extn_suppl_type as of rx_extn_suppl_info[7:6] to which software overrides., This length is
 *    used ONLY when rx_extn_sw_override_en bit is set.
 */
#define BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_SUPPL_INFO(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_SUPPL_INFO_SHIFT)) & BLE2_REG_BLE_REG_DFE_PKT_EXTENSION_CNTRL_RX_EXTN_SW_OVERRIDE_SUPPL_INFO_MASK)
/*! @} */

/*! @name BLE_REG_RX_ADV_PDU_TYPE - Rx Advertising Packet PDU Type */
/*! @{ */

#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_MASK (0xFU)
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_SHIFT (0U)
/*! rx_extn_adv_pdu_type_0 - Extended advertising PDU type, Extended advertising PDU type defined
 *    has an advertising extension header and advData fields.
 */
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_SHIFT)) & BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_MASK)

#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_EN_MASK (0x80U)
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_EN_SHIFT (7U)
/*! rx_extn_adv_pdu_type_0_en - Extended advertising PDU type enable, Use the defined extended
 *    advertising PDU type for Rx matching., 0x0: disable the defined PDU type for matching ext
 *    advertising, 0x1: enable the defined PDU type for matching ext advertising
 *  0b0..disable the defined PDU type for matching ext advertising
 *  0b1..enable the defined PDU type for matching ext advertising
 */
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_EN_SHIFT)) & BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_0_EN_MASK)

#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_MASK (0xF00U)
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_SHIFT (8U)
/*! rx_extn_adv_pdu_type_1 - Extended advertising PDU type, Extended advertising PDU type defined
 *    has an advertising extension header and advData fields.
 */
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_SHIFT)) & BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_MASK)

#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_EN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_EN_SHIFT (15U)
/*! rx_extn_adv_pdu_type_1_en - Extended advertising PDU type enable, Use the defined extended
 *    advertising PDU type for Rx matching., 0x0: disable the defined PDU type for matching ext
 *    advertising, 0x1: enable the defined PDU type for matching ext advertising
 *  0b0..disable the defined PDU type for matching ext advertising
 *  0b1..enable the defined PDU type for matching ext advertising
 */
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_EN_SHIFT)) & BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_1_EN_MASK)

#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_MASK (0xF0000U)
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_SHIFT (16U)
/*! rx_extn_adv_pdu_type_2 - Extended advertising PDU type, Extended advertising PDU type defined
 *    has an advertising extension header and advData fields.
 */
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_SHIFT)) & BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_MASK)

#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_EN_MASK (0x800000U)
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_EN_SHIFT (23U)
/*! rx_extn_adv_pdu_type_2_en - Extended advertising PDU type enable, Use the defined extended
 *    advertising PDU type for Rx matching., 0x0: disable the defined PDU type for matching ext
 *    advertising, 0x1: enable the defined PDU type for matching ext advertising
 *  0b0..disable the defined PDU type for matching ext advertising
 *  0b1..enable the defined PDU type for matching ext advertising
 */
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_EN_SHIFT)) & BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_EXTN_ADV_PDU_TYPE_2_EN_MASK)

#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_ADV_TYPE_CHK_VAL_MASK (0xF000000U)
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_ADV_TYPE_CHK_VAL_SHIFT (24U)
/*! rx_adv_type_chk_val - Received advertising PDU type check value, Regular advertising PDU type
 *    value to be checked for Rx matching. Rx packet's PDU type <= rx_adv_type_chk_val is considered
 *    as valid regular advertising PDU.
 */
#define BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_ADV_TYPE_CHK_VAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_ADV_TYPE_CHK_VAL_SHIFT)) & BLE2_REG_BLE_REG_RX_ADV_PDU_TYPE_RX_ADV_TYPE_CHK_VAL_MASK)
/*! @} */

/*! @name BLE_REG_PRNG_CTRL_STS - PRNG Control Status */
/*! @{ */

#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_GO_MASK (0x1U)
#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_GO_SHIFT (0U)
/*! PRNG_Go - Start PRNG */
#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_GO(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_GO_SHIFT)) & BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_GO_MASK)

#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_DONE_MASK (0x2U)
#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_DONE_SHIFT (1U)
/*! PRNG_Done - PRNG done */
#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_DONE_SHIFT)) & BLE2_REG_BLE_REG_PRNG_CTRL_STS_PRNG_DONE_MASK)

#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_SUBEVENT_MODE_MASK (0x4U)
#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_SUBEVENT_MODE_SHIFT (2U)
/*! Subevent_Mode - Selects mode of operation */
#define BLE2_REG_BLE_REG_PRNG_CTRL_STS_SUBEVENT_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PRNG_CTRL_STS_SUBEVENT_MODE_SHIFT)) & BLE2_REG_BLE_REG_PRNG_CTRL_STS_SUBEVENT_MODE_MASK)
/*! @} */

/*! @name BLE_REG_PRNG_IN - PRNG Input */
/*! @{ */

#define BLE2_REG_BLE_REG_PRNG_IN_CHNL_ID_MASK    (0xFFFFU)
#define BLE2_REG_BLE_REG_PRNG_IN_CHNL_ID_SHIFT   (0U)
/*! Chnl_Id - Channel index */
#define BLE2_REG_BLE_REG_PRNG_IN_CHNL_ID(x)      (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PRNG_IN_CHNL_ID_SHIFT)) & BLE2_REG_BLE_REG_PRNG_IN_CHNL_ID_MASK)

#define BLE2_REG_BLE_REG_PRNG_IN_XOR_IN_MASK     (0xFFFF0000U)
#define BLE2_REG_BLE_REG_PRNG_IN_XOR_IN_SHIFT    (16U)
/*! XOR_In - Counter input */
#define BLE2_REG_BLE_REG_PRNG_IN_XOR_IN(x)       (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PRNG_IN_XOR_IN_SHIFT)) & BLE2_REG_BLE_REG_PRNG_IN_XOR_IN_MASK)
/*! @} */

/*! @name BLE_REG_PRNG_OUT - PRNG Output */
/*! @{ */

#define BLE2_REG_BLE_REG_PRNG_OUT_MAM_OUT_MASK   (0xFFFFU)
#define BLE2_REG_BLE_REG_PRNG_OUT_MAM_OUT_SHIFT  (0U)
/*! MAM_Out - Pseudorandom output */
#define BLE2_REG_BLE_REG_PRNG_OUT_MAM_OUT(x)     (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PRNG_OUT_MAM_OUT_SHIFT)) & BLE2_REG_BLE_REG_PRNG_OUT_MAM_OUT_MASK)

#define BLE2_REG_BLE_REG_PRNG_OUT_XOR_OUT_MASK   (0xFFFF0000U)
#define BLE2_REG_BLE_REG_PRNG_OUT_XOR_OUT_SHIFT  (16U)
/*! XOR_Out - Pseudorandom output */
#define BLE2_REG_BLE_REG_PRNG_OUT_XOR_OUT(x)     (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PRNG_OUT_XOR_OUT_SHIFT)) & BLE2_REG_BLE_REG_PRNG_OUT_XOR_OUT_MASK)
/*! @} */

/*! @name BLE_REG_CODED_PKT_CNTRL - LE Coded Packet Control */
/*! @{ */

#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_EN_SHIFT (0U)
/*! tx_coded_pkt_en - Tx Coded Packet Enable, Tx Coded Packet Enable, 0x0: regular; use non-coded
 *    PHY to transmit packet, 0x1: use LE coded PHY to transmit packet
 *  0b0..regular, use non-coded PHY to transmit packet
 *  0b1..use LE coded PHY to transmit packet
 */
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_EN_SHIFT)) & BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_EN_MASK)

#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_INDIC_MASK (0x30U)
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_INDIC_SHIFT (4U)
/*! tx_coded_pkt_indic - Tx Coded Packet Indicator, When tx_coded_pkt_en is set; indicate LE coding
 *    scheme PHY uses to transmit packet. C=2; if 2'b01; C=8; if 2'b00.
 */
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_INDIC(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_INDIC_SHIFT)) & BLE2_REG_BLE_REG_CODED_PKT_CNTRL_TX_CODED_PKT_INDIC_MASK)

#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_RX_CODED_PKT_EN_MASK (0x10000U)
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_RX_CODED_PKT_EN_SHIFT (16U)
/*! rx_coded_pkt_en - Rx Coded Packet Enable, Rx Coded Packet Enable, 0x0: regular; use non-coded
 *    PHY to receive packet, 0x1: use LE coded PHY to receive packet
 *  0b0..regular, use non-coded PHY to receive packet
 *  0b1..use LE coded PHY to receive packet
 */
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_RX_CODED_PKT_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CODED_PKT_CNTRL_RX_CODED_PKT_EN_SHIFT)) & BLE2_REG_BLE_REG_CODED_PKT_CNTRL_RX_CODED_PKT_EN_MASK)

#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_EN_MASK (0x20000U)
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_EN_SHIFT (17U)
/*! simul_scan_en - Simultaneous Scan Enable, Enable simultaneous scan mode to receive BLE 1M and
 *    coded PHY ADV packets; whichever has correlation hit first., 0x0: disable, 0x1: enable. When
 *    enabled; rx_coded_pkt_en bit must set to 0.
 *  0b0..disable
 *  0b1..enable. When enabled, rx_coded_pkt_en bit must set to 0.
 */
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_EN_SHIFT)) & BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_EN_MASK)

#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_1M_MASK (0x40000U)
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_1M_SHIFT (18U)
/*! simul_scan_1m - Simultaneous Scan Results in 1M Mode; if Concurrent Correlation Hit., When
 *    simul_scan_en is 1; if both 1M and coded PHY correlators have correlation hit at the same time;
 *    this bit decides which mode to continue Rx. This bit has no effect if only 1 of the correlator
 *    has correlation hit., 0x0: Continue Rx in coded PHY packet mode - preferred as it takes longer
 *    time to, correlate the access address., 0x1: Continue Rx in BLE 1M mode.
 *  0b0..Continue Rx in coded PHY packet mode - preferred as it takes longer time to correlate the access address.
 *  0b1..Continue Rx in BLE 1M mode.
 */
#define BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_1M(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_1M_SHIFT)) & BLE2_REG_BLE_REG_CODED_PKT_CNTRL_SIMUL_SCAN_1M_MASK)
/*! @} */

/*! @name BLE_REG_IRK_BASE_ADDR - IRK Resolution Base address */
/*! @{ */

#define BLE2_REG_BLE_REG_IRK_BASE_ADDR_IRK_BASE_ADDR_MASK (0x3FFFU)
#define BLE2_REG_BLE_REG_IRK_BASE_ADDR_IRK_BASE_ADDR_SHIFT (0U)
/*! irk_base_addr - IRK Base Address, Programmable start of IRK storage address in EBRAM. EBRAM is
 *    shared with BrEdr logic. Therefore this start address is programmable; so that different
 *    platforms may be able to use different EBRAM configurations.
 */
#define BLE2_REG_BLE_REG_IRK_BASE_ADDR_IRK_BASE_ADDR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_BASE_ADDR_IRK_BASE_ADDR_SHIFT)) & BLE2_REG_BLE_REG_IRK_BASE_ADDR_IRK_BASE_ADDR_MASK)
/*! @} */

/*! @name BLE_REG_IRK_CTRL_0 - IRK Resolution Control 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_HASH_MASK (0xFFFFFFU)
#define BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_HASH_SHIFT (0U)
/*! sw_irk_hash - Software provided hash for IRK resolution, To perform a software driven IRK
 *    resolution; software writes the lower 24 bits of RPA address into this register. This value is
 *    called hash and is compared with hardware calculated hash to conclude on whether the key can be
 *    used to resolve addresses.
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_HASH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_HASH_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_HASH_MASK)

#define BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_PRAND_MASK (0xFF000000U)
#define BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_PRAND_SHIFT (24U)
/*! sw_irk_prand - Software provided prand for IRK resolution, To perform a software driven IRK
 *    resolution; software writes part of upper 24 bits of RPA address into this register. This value is
 *    called prand[7:0] and is used to generate local hash.
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_PRAND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_PRAND_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_0_SW_IRK_PRAND_MASK)
/*! @} */

/*! @name BLE_REG_IRK_CTRL_1 - IRK Resolution Control 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_PRAND_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_PRAND_SHIFT (0U)
/*! sw_irk_prand - Software provided hash for IRK resolution, To perform a software driven IRK
 *    resolution; software writes part of upper 24 bits of RPA address into this register. This value is
 *    called prand[23:8] and is used to generate local hash.
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_PRAND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_PRAND_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_PRAND_MASK)

#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_RESOLUTION_EN_MASK (0x10000U)
#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_RESOLUTION_EN_SHIFT (16U)
/*! irk_resolution_en - IRK resolution enable, When this bit is set; hardware will parse incoming
 *    advt channel packets to attempt IRK resolution on resolvable private addresses. This bit does
 *    not affect software override/access to IRK locations in hardware EBRAM area. So; disabling this
 *    bit can be used as a backup to stop hardware driven IRK resolving; and use software provided
 *    values after packet has been fully received.
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_RESOLUTION_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_RESOLUTION_EN_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_RESOLUTION_EN_MASK)

#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_SW_LOCK_MASK (0x20000U)
#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_SW_LOCK_SHIFT (17U)
/*! irk_sw_lock - Lock bits for Software IRK queue access, This bit allows software and hardware to
 *    access the EBRAM IRK queue locations safely., 0x0: IRK queue is not in use by software, 0x1:
 *    IRK queue is in use by software
 *  0b0..IRK queue is not in use by software
 *  0b1..IRK queue is in use by software
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_SW_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_SW_LOCK_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_SW_LOCK_MASK)

#define BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_RESOLVE_CMD_MASK (0x40000U)
#define BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_RESOLVE_CMD_SHIFT (18U)
/*! sw_irk_resolve_cmd - Software IRK resolve command, This self clearing bit triggers a software
 *    requested IRK resolution process. The prand and hash values are provided in sw_irk_hash and
 *    sw_irk_prand fields. The software lock bit irk_sw_lock; should be set to 1 before the command is
 *    set. Self cleared by hardware
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_RESOLVE_CMD(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_RESOLVE_CMD_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_1_SW_IRK_RESOLVE_CMD_MASK)

#define BLE2_REG_BLE_REG_IRK_CTRL_1_KILL_IRK_RESOLVE_MASK (0x80000U)
#define BLE2_REG_BLE_REG_IRK_CTRL_1_KILL_IRK_RESOLVE_SHIFT (19U)
/*! kill_irk_resolve - Kill IRK resolve process, This bit will kill IRK resolve process and put the
 *    state machine back to idle. Software is responsible to clear this bit., 0x0: IRK resolve is
 *    not killed, 0x1: IRK resolve is killed by software
 *  0b0..IRK resolve is not killed
 *  0b1..IRK resolve is killed by software
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_1_KILL_IRK_RESOLVE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_1_KILL_IRK_RESOLVE_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_1_KILL_IRK_RESOLVE_MASK)

#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_QUEUE_LENGTH_MASK (0xFF000000U)
#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_QUEUE_LENGTH_SHIFT (24U)
/*! irk_queue_length - Length of IRK queue in EBRAM, Specifies valid IRK queue length. All values
 *    between 0 to 255 are valid. If IRK queue is empty; this value should be set to 0.
 */
#define BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_QUEUE_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_QUEUE_LENGTH_SHIFT)) & BLE2_REG_BLE_REG_IRK_CTRL_1_IRK_QUEUE_LENGTH_MASK)
/*! @} */

/*! @name BLE_REG_IRK_STATUS_0 - IRK Resolution Status 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_IRK_STATUS_0_IRK_RESOLVED_ID_ADDR_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_IRK_STATUS_0_IRK_RESOLVED_ID_ADDR_SHIFT (0U)
/*! irk_resolved_id_addr - ID address for successful IRK resolution, If IRK resolution was
 *    successful; this register holds the lower 32 bits of the 48-bit ID address of the device.
 */
#define BLE2_REG_BLE_REG_IRK_STATUS_0_IRK_RESOLVED_ID_ADDR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_STATUS_0_IRK_RESOLVED_ID_ADDR_SHIFT)) & BLE2_REG_BLE_REG_IRK_STATUS_0_IRK_RESOLVED_ID_ADDR_MASK)
/*! @} */

/*! @name BLE_REG_IRK_STATUS_1 - IRK Resolution Status 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_SHIFT (0U)
/*! irk_resolved_id_addr - ID address for successful IRK resolution, If IRK resolution was
 *    successful; this register holds the upper bits (47:32) of the 48 bit ID address of the device.
 */
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_SHIFT)) & BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_MASK)

#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_TYPE_MASK (0x10000U)
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_TYPE_SHIFT (16U)
/*! irk_resolved_id_addr_type - ID address type for successful IRK resolution, If IRK resolution was
 *    successful; this register holds the Device Type information of the device.
 */
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_TYPE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_TYPE_SHIFT)) & BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVED_ID_ADDR_TYPE_MASK)

#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLUTION_RESULT_MASK (0x60000U)
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLUTION_RESULT_SHIFT (17U)
/*! irk_resolution_result - Result of latest IRK resolution, The values indicate if IRK resolution
 *    is finished or ongoing; successful or unsuccessful., 0x0: resolution in progress, 0x1: entry
 *    was found in IRK queue, 0x2: entry was not found in IRK queue, 0x3: IRK queue search not done
 *    for this packet
 *  0b00..resolution in progress
 *  0b01..entry was found in IRK queue
 *  0b10..entry was not found in IRK queue
 *  0b11..IRK queue search not done for this packet
 */
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLUTION_RESULT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLUTION_RESULT_SHIFT)) & BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLUTION_RESULT_MASK)

#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_HW_LOCK_MASK (0x80000U)
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_HW_LOCK_SHIFT (19U)
/*! irk_hw_lock - Lock bits for Hardware IRK EBRAM access, This bit allows software and hardware to
 *    access the IRK queue locations safely., 0x0: IRK queue is not in use by hardware, 0x1: IRK
 *    queue is in use by hardware
 *  0b0..IRK queue is not in use by hardware
 *  0b1..IRK queue is in use by hardware
 */
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_HW_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_HW_LOCK_SHIFT)) & BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_HW_LOCK_MASK)

#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_FSM_STATE_MASK (0x700000U)
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_FSM_STATE_SHIFT (20U)
/*! irk_fsm_state - IRK resolve state machine status, This is the current vlaue of the IRK resolve
 *    state machine (for example irk_fsm_state).
 */
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_FSM_STATE_SHIFT)) & BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_FSM_STATE_MASK)

#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVE_POSITION_MASK (0xFF000000U)
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVE_POSITION_SHIFT (24U)
/*! irk_resolve_position - Position of last IRK queue lookup in EBRAM, This is the last offset that
 *    was searched. For successful resolutions; it is the offset where device IRK was found. For
 *    unsuccessful resolutions; this is the last offset in queue.
 */
#define BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVE_POSITION(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVE_POSITION_SHIFT)) & BLE2_REG_BLE_REG_IRK_STATUS_1_IRK_RESOLVE_POSITION_MASK)
/*! @} */

/*! @name BLE_REG_WHITELIST_BASE_ADDR - Whitelist Base address */
/*! @{ */

#define BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_MASK (0x3FFFU)
#define BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_SHIFT (0U)
/*! WHITELIST_BASE_ADDR - WHITELIST BASE ADDR */
#define BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_MASK (0x3FFFU)
#define BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_SHIFT (0U)
/*! whitelist_base_addr - WHITELIST BASE ADDR, Programmable start of Whitelist storage address in
 *    EBRAM. EBRAM is shared with BrEdr logic. Therefore this start address is programmable; so that
 *    different platforms may be able to use different EBRAM configurations.
 */
#define BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_BASE_ADDR_WHITELIST_BASE_ADDR_MASK)
/*! @} */

/*! @name BLE_REG_WHITELIST_CTRL_0 - Whitelist Search Control 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_0_SW_WL_DEVICE_ADDR_0_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_0_SW_WL_DEVICE_ADDR_0_SHIFT (0U)
/*! sw_wl_device_addr_0 - Software provided device address for whitelist search, To perform a
 *    software whitelist query; software writes the lower 32 bits of device address into this register.
 *    This value is used together with some fields in next register BLE_REG_WHITELIST_CTRL_1.
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_0_SW_WL_DEVICE_ADDR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_0_SW_WL_DEVICE_ADDR_0_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_0_SW_WL_DEVICE_ADDR_0_MASK)
/*! @} */

/*! @name BLE_REG_WHITELIST_CTRL_1 - Whitelist Search Control 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_ADDR_1_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_ADDR_1_SHIFT (0U)
/*! sw_wl_device_addr_1 - Software provided Device address for whitelist search, To perform a
 *    software whitelist query; software writes the upper 16 bits of device address into this register.
 *    Together with BLE_REG_WHITELIST_CTRL_0; this represents the 48-bit device address for software
 *    white list lookup.
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_ADDR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_ADDR_1_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_ADDR_1_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_TYPE_MASK (0x10000U)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_TYPE_SHIFT (16U)
/*! sw_wl_device_type - Software provided Device address type for whitelist search, This bit
 *    specifies the device address type to be used for software whitelist query., 0x0: public address, 0x1:
 *    random address
 *  0b0..public address
 *  0b1..random address
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_TYPE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_TYPE_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_DEVICE_TYPE_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_QUERY_CMD_MASK (0x20000U)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_QUERY_CMD_SHIFT (17U)
/*! sw_wl_query_cmd - Software whitelist query command, This self clearing bit triggers a software
 *    requested whitelist search for the device specified by sw_wl_device_type; sw_wl_device_addr_1
 *    and sw_wl_device_addr_0 fields. The lock bit wl_sw_lock; should be set to 1 before the command
 *    is set. Self cleared by hardware.
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_QUERY_CMD(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_QUERY_CMD_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_1_SW_WL_QUERY_CMD_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WL_SW_LOCK_MASK (0x40000U)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WL_SW_LOCK_SHIFT (18U)
/*! wl_sw_lock - Lock bits for software whitelist access, This bit should be set by software when it
 *    is modifying the EBRAM whitelist area, 0x0: whitelist is not in use by software, 0x1:
 *    whitelist is in use by software
 *  0b0..whitelist is not in use by software
 *  0b1..whitelist is in use by software
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WL_SW_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WL_SW_LOCK_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WL_SW_LOCK_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_HW_WL_SEARCH_EN_MASK (0x80000U)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_HW_WL_SEARCH_EN_SHIFT (19U)
/*! hw_wl_search_en - Inline White list search enable, When this bit is set; hardware will parse
 *    incoming advt channel packets to attempt white list filtering inline. This bit does not affect
 *    software override/access to the whitelist operations in hardware EBRAM area. So; disabling this
 *    bit can be used as a backup to stop hardware driven whitelist searching; and use software
 *    provided values after packet has been fully received.
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_HW_WL_SEARCH_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_1_HW_WL_SEARCH_EN_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_1_HW_WL_SEARCH_EN_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_KILL_WL_SEARCH_MASK (0x100000U)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_KILL_WL_SEARCH_SHIFT (20U)
/*! kill_wl_search - Kill whitelist search, This bit will kill whitelist search process and put the
 *    state machine back to idle. Software is responsible to clear this bit., 0x0: whitelist search
 *    is not killed, 0x1: whitelist search is killed by software
 *  0b0..whitelist search is not killed
 *  0b1..whitelist search is killed by software
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_KILL_WL_SEARCH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_1_KILL_WL_SEARCH_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_1_KILL_WL_SEARCH_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WHITELIST_LENGTH_MASK (0xFF000000U)
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WHITELIST_LENGTH_SHIFT (24U)
/*! whitelist_length - Length of whitelist in EBRAM, Specifies valid whitelist length. All values
 *    between 0 to 255 are valid. If whitelist is empty; this value should be set to 0.
 */
#define BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WHITELIST_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WHITELIST_LENGTH_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_CTRL_1_WHITELIST_LENGTH_MASK)
/*! @} */

/*! @name BLE_REG_WHITELIST_STATUS - Whitelist Search Status */
/*! @{ */

#define BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_RESULT_MASK (0x3U)
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_RESULT_SHIFT (0U)
/*! hw_wl_lookup_result - Result of latest hardware white list lookup, The values indicate if query
 *    is finished or ongoing; successful or unsuccessful., 0x0: lookup in progress, 0x1: entry was
 *    found in whitelist, 0x2: entry was not found in whitelist, 0x3: whitelist search not done for
 *    this packet
 *  0b00..lookup in progress
 *  0b01..entry was found in whitelist
 *  0b10..entry was not found in whitelist
 *  0b11..whitelist search not done for this packet
 */
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_RESULT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_RESULT_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_RESULT_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_HW_LOCK_MASK (0x4U)
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_HW_LOCK_SHIFT (2U)
/*! wl_hw_lock - Lock bits for Hardware whitelist access, This bit allows software and hardware to
 *    access the EBRAM whitelist locations safely., 0x0: whitelist is not in use by hardware, 0x1:
 *    whitelist is in use by hardware
 *  0b0..whitelist is not in use by hardware
 *  0b1..whitelist is in use by hardware
 */
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_HW_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_HW_LOCK_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_HW_LOCK_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_FSM_STATE_MASK (0xF0U)
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_FSM_STATE_SHIFT (4U)
/*! wl_fsm_state - Whitelist search state machine status, This is the whitelist state machine; e.g. wl_fsm_state; current value */
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_FSM_STATE_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_STATUS_WL_FSM_STATE_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_POSITION_MASK (0xFF00U)
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_POSITION_SHIFT (8U)
/*! hw_wl_lookup_position - Position of last hardware whitelist lookup in EBRAM, For successful
 *    lookups; it is the offset where specified address is located in the whitelist. For unsuccessful
 *    lookups; this is the offset to be asserted. For example; if specified address is between offset
 *    3 and 4; it reports 4 which is the offset software will insert for the specified address. If
 *    whitelist_length = 10; the entry position is 0 to 9; and if the specified address is bigger
 *    than the offset 9th entry; it will report 10. For the extreme case (whitelist_length = 255; and
 *    the specified address is bigger than the offset 254th entry); it reports 255.
 */
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_POSITION(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_POSITION_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_STATUS_HW_WL_LOOKUP_POSITION_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_RESULT_MASK (0x30000U)
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_RESULT_SHIFT (16U)
/*! sw_wl_lookup_result - Result of latest software white list lookup, The values indicate if query
 *    is finished or ongoing; successful or unsuccessful., 0x0: lookup in progress, 0x1: entry was
 *    found in whitelist, 0x2: entry was not found in whitelist, 0x3: whitelist search not done for
 *    this software command
 *  0b00..lookup in progress
 *  0b01..entry was found in whitelist
 *  0b10..entry was not found in whitelist
 *  0b11..whitelist search not done for this software command
 */
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_RESULT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_RESULT_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_RESULT_MASK)

#define BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_POSITION_MASK (0xFF000000U)
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_POSITION_SHIFT (24U)
/*! sw_wl_lookup_position - Position of last software whitelist lookup in EBRAM, For successful
 *    lookups; it is the offset where specified address is located in the whitelist. For unsuccessful
 *    lookups; this is the offset to be asserted. For example; if specified address is between offset
 *    3 and 4; it reports 4 which is the offset software will insert for the specified address. If
 *    whitelist_length = 10; the entry position is 0 to 9; and if the specified address is bigger
 *    than the offset 9th entry; it will report 10. For the extreme case (whitelist_length = 255; and
 *    the specified address is bigger than the offset 254th entry); it reports 255.
 */
#define BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_POSITION(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_POSITION_SHIFT)) & BLE2_REG_BLE_REG_WHITELIST_STATUS_SW_WL_LOOKUP_POSITION_MASK)
/*! @} */

/*! @name BLE_REG_TD_START_ADDR - Tx Descriptor Start Address */
/*! @{ */

#define BLE2_REG_BLE_REG_TD_START_ADDR_TD_START_ADDRESS_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TD_START_ADDR_TD_START_ADDRESS_SHIFT (0U)
/*! td_start_address - Tx Descriptor Start Address, The currently active TD (Tx Descriptor) is pointed by td_start_address. */
#define BLE2_REG_BLE_REG_TD_START_ADDR_TD_START_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TD_START_ADDR_TD_START_ADDRESS_SHIFT)) & BLE2_REG_BLE_REG_TD_START_ADDR_TD_START_ADDRESS_MASK)
/*! @} */

/*! @name BLE_REG_TD_STATUS - Tx Descriptor Status */
/*! @{ */

#define BLE2_REG_BLE_REG_TD_STATUS_TD_BUSY_MASK  (0x1U)
#define BLE2_REG_BLE_REG_TD_STATUS_TD_BUSY_SHIFT (0U)
/*! td_busy - TD busy, Status indicating the active TD is busy and being used by hardware. Asserted
 *    when fetching TD starts and de-asserted right after TD status writes back., 0x0: TD is idle,
 *    0x1: TD is busy and being used by hardware
 *  0b0..TD is idle
 *  0b1..TD is busy and being used by hardware
 */
#define BLE2_REG_BLE_REG_TD_STATUS_TD_BUSY(x)    (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TD_STATUS_TD_BUSY_SHIFT)) & BLE2_REG_BLE_REG_TD_STATUS_TD_BUSY_MASK)

#define BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ANT_SWITCH_FAIL_MASK (0x4U)
#define BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ANT_SWITCH_FAIL_SHIFT (2U)
/*! tx_extn_ant_switch_fail - Tx antenna switch status on packet extension, Status indicating the Tx
 *    antenna switch for the current transmitted extension has failed., 0x0: Tx antenna switch
 *    pattern is honored; antSwitchStatus was never de-asserted, during packet extension, 0x1: Tx
 *    antenna switch pattern is not honored
 *  0b0..Tx antenna switch pattern is honored; antSwitchStatus was never de-asserted during packet extension
 *  0b1..Tx antenna switch pattern is not honored
 */
#define BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ANT_SWITCH_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ANT_SWITCH_FAIL_SHIFT)) & BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ANT_SWITCH_FAIL_MASK)

#define BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ABORT_SHIFT (3U)
/*! tx_extn_abort - Tx extension packet hardware abort status, Status indicating the Tx extension
 *    packet is aborted by hardware., 0x0: No abort condition happened during Tx extension, 0x1:
 *    hardware abort condition was detected during Tx extension
 *  0b0..No abort condition happened during Tx extension
 *  0b1..hardware abort condition was detected during Tx extension
 */
#define BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TD_STATUS_TX_EXTN_ABORT_MASK)

#define BLE2_REG_BLE_REG_TD_STATUS_TX_HAS_ERR_MASK (0x10U)
#define BLE2_REG_BLE_REG_TD_STATUS_TX_HAS_ERR_SHIFT (4U)
/*! tx_has_err - Tx Has Error, Tx packet of using this TD experienced at least 1 of the following
 *    errors., 0x0: No error, 0x1: At least 1 of rif_abort_tx; tx_dmem_underflow_intr;
 *    tx_aes_underflow_intr and, tx_lock_fail_intr has been asserted during packet transmission
 *  0b0..No error
 *  0b1..At least 1 of rif_abort_tx, tx_dmem_underflow_intr, and tx_aes_underflow_intr has been asserted during packet transmission
 */
#define BLE2_REG_BLE_REG_TD_STATUS_TX_HAS_ERR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TD_STATUS_TX_HAS_ERR_SHIFT)) & BLE2_REG_BLE_REG_TD_STATUS_TX_HAS_ERR_MASK)

#define BLE2_REG_BLE_REG_TD_STATUS_TX_DMA_ERR_MASK (0x20U)
#define BLE2_REG_BLE_REG_TD_STATUS_TX_DMA_ERR_SHIFT (5U)
/*! tx_dma_err - Tx Has DMA Error, Tx packet of using this TD experienced DMA error., 0x0: No error,
 *    0x1: SoC DMA slave has replied with ERROR response during packet transmission
 *  0b0..No error
 *  0b1..SoC DMA slave has replied with ERROR response during packet transmission
 */
#define BLE2_REG_BLE_REG_TD_STATUS_TX_DMA_ERR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TD_STATUS_TX_DMA_ERR_SHIFT)) & BLE2_REG_BLE_REG_TD_STATUS_TX_DMA_ERR_MASK)

#define BLE2_REG_BLE_REG_TD_STATUS_TX_RL_LOCKFAIL_STS_MASK (0x40U)
#define BLE2_REG_BLE_REG_TD_STATUS_TX_RL_LOCKFAIL_STS_SHIFT (6U)
/*! tx_rl_lockfail_sts - Tx Has RL lock fail, Status indicating Tx packet has lock fail because of
 *    register loader, 0x0: No error, 0x1: Tx_lock_fail_intr has been asserted during packet
 *    transmission
 */
#define BLE2_REG_BLE_REG_TD_STATUS_TX_RL_LOCKFAIL_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TD_STATUS_TX_RL_LOCKFAIL_STS_SHIFT)) & BLE2_REG_BLE_REG_TD_STATUS_TX_RL_LOCKFAIL_STS_MASK)
/*! @} */

/*! @name BLE_REG_RD_START_ADDR - Rx Descriptor Start Address */
/*! @{ */

#define BLE2_REG_BLE_REG_RD_START_ADDR_RD_START_ADDRESS_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_RD_START_ADDR_RD_START_ADDRESS_SHIFT (0U)
/*! rd_start_address - Rx Descriptor Start Address, The currently active RD (Rx Descriptor) is pointed by rd_start_address. */
#define BLE2_REG_BLE_REG_RD_START_ADDR_RD_START_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_START_ADDR_RD_START_ADDRESS_SHIFT)) & BLE2_REG_BLE_REG_RD_START_ADDR_RD_START_ADDRESS_MASK)
/*! @} */

/*! @name BLE_REG_RD_STATUS - Rx Descriptor Status */
/*! @{ */

#define BLE2_REG_BLE_REG_RD_STATUS_RD_BUSY_MASK  (0x1U)
#define BLE2_REG_BLE_REG_RD_STATUS_RD_BUSY_SHIFT (0U)
/*! rd_busy - RD busy, Status indicating the active RD is busy and being used by hardware. Asserted
 *    when fetching RD starts and de-asserted right after RD status writes back., 0x0: RD is idle,
 *    0x1: RD is busy and being used by hardware
 *  0b0..RD is idle
 *  0b1..RD is busy and being used by hardware
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RD_BUSY(x)    (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RD_BUSY_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RD_BUSY_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_RCV_MASK (0x2U)
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_RCV_SHIFT (1U)
/*! rx_extn_rcv - Extension Packet Received, This bit is valid ONLY on received packets when CRC has
 *    passed., 0x0: regular Rx packet was received, 0x1: extension field packet was received
 *  0b0..regular Rx packet was received
 *  0b1..extension field packet was received
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_RCV(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_RCV_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_RCV_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ANT_SWITCH_FAIL_MASK (0x4U)
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ANT_SWITCH_FAIL_SHIFT (2U)
/*! rx_extn_ant_switch_fail - Rx antenna switch status on packet extension, Status indicating the Rx
 *    antenna switch for the current receiving extension has failed., 0x0: Rx antenna switch
 *    pattern is honored; antSwitchStatus was never de-asserted, during packet extension, 0x1: Rx antenna
 *    switch pattern is not honored
 *  0b0..Rx antenna switch pattern is honored; antSwitchStatus was never de-asserted during packet extension
 *  0b1..Rx antenna switch pattern is not honored
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ANT_SWITCH_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ANT_SWITCH_FAIL_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ANT_SWITCH_FAIL_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ABORT_SHIFT (3U)
/*! rx_extn_abort - Rx extension packet hardware abort status, Status indicating the Rx extension
 *    packet is aborted by hardware., 0x0: no abort condition happened during Rx extension, 0x1:
 *    hardware abort condition was detected during Rx extension
 *  0b0..no abort condition happened during Rx extension
 *  0b1..hardware abort condition was detected during Rx extension
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ABORT_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_ABORT_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RX_HAS_ERR_MASK (0x10U)
#define BLE2_REG_BLE_REG_RD_STATUS_RX_HAS_ERR_SHIFT (4U)
/*! rx_has_err - Rx Has Error, Rx packet of using this RD experienced at least 1 of the following
 *    errors., 0x0: No error, 0x1: At least 1 of rif_abort_rx; rx_dmem_overflow_intr;
 *    rx_aes_underflow_intr and, rx_lock_fail_intr has been asserted during packet reception
 *  0b0..No error
 *  0b1..At least 1 of rif_abort_rx, rx_dmem_overflow_intr, and rx_aes_underflow_intr has been asserted during packet reception
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RX_HAS_ERR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RX_HAS_ERR_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RX_HAS_ERR_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RX_DMA_ERR_MASK (0x20U)
#define BLE2_REG_BLE_REG_RD_STATUS_RX_DMA_ERR_SHIFT (5U)
/*! rx_dma_err - Rx Has DMA Error, Rx packet of using this RD experienced DMA error., 0x0: No error,
 *    0x1: SoC DMA slave has replied with ERROR response during packet reception
 *  0b0..No error
 *  0b1..SoC DMA slave has replied with ERROR response during packet reception
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RX_DMA_ERR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RX_DMA_ERR_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RX_DMA_ERR_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RX_RL_LOCKFAIL_STS_MASK (0x40U)
#define BLE2_REG_BLE_REG_RD_STATUS_RX_RL_LOCKFAIL_STS_SHIFT (6U)
/*! rx_rl_lockfail_sts - Rx Has RL lock fail, Status indicating Rx packet has lock fail because of
 *    register loader, 0x0: No error, 0x1: Rx_lock_fail_intr has been asserted during packet
 *    transmission
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RX_RL_LOCKFAIL_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RX_RL_LOCKFAIL_STS_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RX_RL_LOCKFAIL_STS_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RD_ALT_CURR_MASK (0x80U)
#define BLE2_REG_BLE_REG_RD_STATUS_RD_ALT_CURR_SHIFT (7U)
/*! rd_alt_curr - Current RD in use, This bit indicates which RD pointer is currently in use. When
 *    rd_alt is 0 this bit is always 0; when rd_alt = 1 this bit toggles for every RX to indicate the
 *    RD in use., 0x0: Normal RD is being used, 0x1: Alternate RD is being used
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RD_ALT_CURR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RD_ALT_CURR_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RD_ALT_CURR_MASK)

#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_LENGTH_MASK (0xFF00U)
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_LENGTH_SHIFT (8U)
/*! rx_extn_length - Rx Extension Length, Length of valid I/Q samples received. The value is in the
 *    unit of 8 usec time frame. BLE still sends this I/Q samples to memory for firmware and
 *    indicates the valid number of samples in this field even though Rx was aborted during the extension
 *    reception., This bit is valid ONLY when rx_extn_rcv bit is set.
 */
#define BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_LENGTH_SHIFT)) & BLE2_REG_BLE_REG_RD_STATUS_RX_EXTN_LENGTH_MASK)
/*! @} */

/*! @name BLE_REG_RSSI_ARB_CTRL - BLE RSSI ARBITRATION CONTROL */
/*! @{ */

#define BLE2_REG_BLE_REG_RSSI_ARB_CTRL_ble_arb_rssi_val_MASK (0xFFU)
#define BLE2_REG_BLE_REG_RSSI_ARB_CTRL_ble_arb_rssi_val_SHIFT (0U)
/*! ble_arb_rssi_val - Software programable RSSI value for RSSI based arbitration */
#define BLE2_REG_BLE_REG_RSSI_ARB_CTRL_ble_arb_rssi_val(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RSSI_ARB_CTRL_ble_arb_rssi_val_SHIFT)) & BLE2_REG_BLE_REG_RSSI_ARB_CTRL_ble_arb_rssi_val_MASK)
/*! @} */

/*! @name BLE_REG_RD_START_ADDR_ALT - Alternate Rx Descriptor Start Address */
/*! @{ */

#define BLE2_REG_BLE_REG_RD_START_ADDR_ALT_rd_start_address_alt_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_RD_START_ADDR_ALT_rd_start_address_alt_SHIFT (0U)
/*! rd_start_address_alt - Alternate Rx Descriptor Start Address, The Alternate RD (Rx Descriptor) is pointed by rd_start_address_alt. */
#define BLE2_REG_BLE_REG_RD_START_ADDR_ALT_rd_start_address_alt(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_START_ADDR_ALT_rd_start_address_alt_SHIFT)) & BLE2_REG_BLE_REG_RD_START_ADDR_ALT_rd_start_address_alt_MASK)
/*! @} */

/*! @name BLE_REG_RD_CTRL - Rx Descriptor Control */
/*! @{ */

#define BLE2_REG_BLE_REG_RD_CTRL_rd_alt_MASK     (0x1U)
#define BLE2_REG_BLE_REG_RD_CTRL_rd_alt_SHIFT    (0U)
/*! rd_alt - Toggle mode for RD_START_ADDRESS, This bit indicates which RD_START_ADDRESS is to be
 *    used, 0x0: always use rd_start_address, 0x1: use Toggle mode where rd_start_address and
 *    rd_start_address_alt are used for, alternating RX
 */
#define BLE2_REG_BLE_REG_RD_CTRL_rd_alt(x)       (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_CTRL_rd_alt_SHIFT)) & BLE2_REG_BLE_REG_RD_CTRL_rd_alt_MASK)

#define BLE2_REG_BLE_REG_RD_CTRL_rd_alt_reset_MASK (0x2U)
#define BLE2_REG_BLE_REG_RD_CTRL_rd_alt_reset_SHIFT (1U)
/*! rd_alt_reset - Reset bit, This bit is used to reset the alternating mode, 0x0: No reset, 0x1:
 *    reset; use the RD_START_ADDRESS for the next pkt irrespective of what was used, for the previous
 *    pkt
 */
#define BLE2_REG_BLE_REG_RD_CTRL_rd_alt_reset(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RD_CTRL_rd_alt_reset_SHIFT)) & BLE2_REG_BLE_REG_RD_CTRL_rd_alt_reset_MASK)
/*! @} */

/*! @name BLE_REG_CLK_CTRL_SLEEP_OK_TIMER - BLE sleep ok timer */
/*! @{ */

#define BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_SLEEP_OK_TIMER_MASK (0x3FFU)
#define BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_SLEEP_OK_TIMER_SHIFT (0U)
/*! sleep_ok_timer - sys_clk_sync_sleep_ok will deassert at timer expiration */
#define BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_SLEEP_OK_TIMER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_SLEEP_OK_TIMER_SHIFT)) & BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_SLEEP_OK_TIMER_MASK)

#define BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_ASLV_LAT_OPT_EN_MASK (0x10000U)
#define BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_ASLV_LAT_OPT_EN_SHIFT (16U)
/*! aslv_lat_opt_en - ahb access 4mclk domain register adaptive mechanism control bit, This bit
 *    enables or disables the adaptive mechanism inside the BLE AHB slave that is intended to improve
 *    latencies towards 4MHz domain registers. To restart the mechanism; after changing the SYS clock
 *    frequency; program it to 0 and back to 1. No r/w delays are needed. It is not necessary to
 *    restart the mechanism when switching to higher SYS clock frequency., 0x0: Disable the adaptive
 *    mechanism., 0x1: Enable the adaptive mechanism by default
 */
#define BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_ASLV_LAT_OPT_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_ASLV_LAT_OPT_EN_SHIFT)) & BLE2_REG_BLE_REG_CLK_CTRL_SLEEP_OK_TIMER_ASLV_LAT_OPT_EN_MASK)
/*! @} */

/*! @name BLE_REG_AES_CNTRL - AES Control */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_CNTRL_SW_AES_GO_DYN_MASK (0x1U)
#define BLE2_REG_BLE_REG_AES_CNTRL_SW_AES_GO_DYN_SHIFT (0U)
/*! sw_aes_go_dyn - Run AES Encryption (active high pulse) */
#define BLE2_REG_BLE_REG_AES_CNTRL_SW_AES_GO_DYN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_CNTRL_SW_AES_GO_DYN_SHIFT)) & BLE2_REG_BLE_REG_AES_CNTRL_SW_AES_GO_DYN_MASK)

#define BLE2_REG_BLE_REG_AES_CNTRL_SW_CCM_CLK_REQ_MASK (0x2U)
#define BLE2_REG_BLE_REG_AES_CNTRL_SW_CCM_CLK_REQ_SHIFT (1U)
/*! sw_ccm_clk_req - CCM/AES clock control, 0x0: disable clock for encryption, 0x1: request (enable) clock for encryption
 *  0b0..disable clock for encryption
 *  0b1..request (enable) clock for encryption
 */
#define BLE2_REG_BLE_REG_AES_CNTRL_SW_CCM_CLK_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_CNTRL_SW_CCM_CLK_REQ_SHIFT)) & BLE2_REG_BLE_REG_AES_CNTRL_SW_CCM_CLK_REQ_MASK)

#define BLE2_REG_BLE_REG_AES_CNTRL_SECURE_IRK_DECRYPT_DYN_MASK (0x4U)
#define BLE2_REG_BLE_REG_AES_CNTRL_SECURE_IRK_DECRYPT_DYN_SHIFT (2U)
/*! secure_irk_decrypt_dyn - Decrypt IRK using DKey (active high pulse), When this bit is set; BTU
 *    will descramble the IRKs using DKEY from local store. The scrambled Keys should be written in
 *    BLE_REG_AES_DIN\* registeres and the plain text IRKs will be saved in BLE_REG_AES_DOUT
 *    register. The BLE_REG_AES_KEY\* register are not used in this mode., This bit is self clearing and is
 *    cleared by HW when AES operation is done., Note: Since BTU's AES engine only supports
 *    encryption mode (as purposely chosen for CCM mode); it is agreed with MICRO team that technically the
 *    Sentinel will perform the AES decryption operation to generate the ESK while BTU will carry
 *    out the AES encryption operation to derive the plain text SK. So; at BTU side we do such: SK =
 *    AES-128 Encryp (ESK; DKey_SK) IRK = AES-128 Encryp(EIRK; DKey_IRK) At S200 side; they do such:
 *    ESK = AES-128 Decryp(SK; DKey_SK) EIRK = AES-128 Decryp(IRK; DKey_IRK) So; the functional
 *    process on BTU side is to decrypt to unwrap the SK or IRK; but the actual HW operation is
 *    encryption.
 */
#define BLE2_REG_BLE_REG_AES_CNTRL_SECURE_IRK_DECRYPT_DYN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_CNTRL_SECURE_IRK_DECRYPT_DYN_SHIFT)) & BLE2_REG_BLE_REG_AES_CNTRL_SECURE_IRK_DECRYPT_DYN_MASK)

#define BLE2_REG_BLE_REG_AES_CNTRL_LOCK_SW_AES_REGS_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_AES_CNTRL_LOCK_SW_AES_REGS_SHIFT (31U)
/*! lock_sw_aes_regs - Lock Software AES registers from write, 0x0: All 12 Software AES registers
 *    (BLE_REG_AES_KEY_0~3; BLE_REG_AES_DIN_0~3;, BLE_REG_AES_DOUT_0~3) can be written as normal.,
 *    0x1: All 12 Software AES registers are read-only. Software and hardware write to them, is
 *    disabled.
 *  0b0..All 12 Software AES registers (BLE_REG_AES_KEY_0~3, BLE_REG_AES_DIN_0~3, BLE_REG_AES_DOUT_0~3) can be written as normal.
 *  0b1..All 12 Software AES registers are read-only. Software and hardware write to them is disabled.
 */
#define BLE2_REG_BLE_REG_AES_CNTRL_LOCK_SW_AES_REGS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_CNTRL_LOCK_SW_AES_REGS_SHIFT)) & BLE2_REG_BLE_REG_AES_CNTRL_LOCK_SW_AES_REGS_MASK)
/*! @} */

/*! @name BLE_REG_AES_KEY_0 - Key 0 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_KEY_0_SW_AES_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_KEY_0_SW_AES_KEY_SHIFT (0U)
/*! sw_aes_key - AES Key ([31:0] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_KEY_0_SW_AES_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_KEY_0_SW_AES_KEY_SHIFT)) & BLE2_REG_BLE_REG_AES_KEY_0_SW_AES_KEY_MASK)
/*! @} */

/*! @name BLE_REG_AES_KEY_1 - Key 1 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_KEY_1_SW_AES_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_KEY_1_SW_AES_KEY_SHIFT (0U)
/*! sw_aes_key - AES Key ([63:32] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_KEY_1_SW_AES_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_KEY_1_SW_AES_KEY_SHIFT)) & BLE2_REG_BLE_REG_AES_KEY_1_SW_AES_KEY_MASK)
/*! @} */

/*! @name BLE_REG_AES_KEY_2 - Key 2 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_KEY_2_SW_AES_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_KEY_2_SW_AES_KEY_SHIFT (0U)
/*! sw_aes_key - AES Key ([95:64] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_KEY_2_SW_AES_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_KEY_2_SW_AES_KEY_SHIFT)) & BLE2_REG_BLE_REG_AES_KEY_2_SW_AES_KEY_MASK)
/*! @} */

/*! @name BLE_REG_AES_KEY_3 - Key 3 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_KEY_3_SW_AES_KEY_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_KEY_3_SW_AES_KEY_SHIFT (0U)
/*! sw_aes_key - AES Key ([127:96] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_KEY_3_SW_AES_KEY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_KEY_3_SW_AES_KEY_SHIFT)) & BLE2_REG_BLE_REG_AES_KEY_3_SW_AES_KEY_MASK)
/*! @} */

/*! @name BLE_REG_AES_DIN_0 - Raw Data Input 0 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DIN_0_SW_AES_DIN_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DIN_0_SW_AES_DIN_SHIFT (0U)
/*! sw_aes_din - Raw Data Input for AES Encryption ([31:0] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DIN_0_SW_AES_DIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DIN_0_SW_AES_DIN_SHIFT)) & BLE2_REG_BLE_REG_AES_DIN_0_SW_AES_DIN_MASK)
/*! @} */

/*! @name BLE_REG_AES_DIN_1 - Raw Data Input 1 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DIN_1_SW_AES_DIN_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DIN_1_SW_AES_DIN_SHIFT (0U)
/*! sw_aes_din - Raw Data Input for AES Encryption ([63:32] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DIN_1_SW_AES_DIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DIN_1_SW_AES_DIN_SHIFT)) & BLE2_REG_BLE_REG_AES_DIN_1_SW_AES_DIN_MASK)
/*! @} */

/*! @name BLE_REG_AES_DIN_2 - Raw Data Input 2 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DIN_2_SW_AES_DIN_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DIN_2_SW_AES_DIN_SHIFT (0U)
/*! sw_aes_din - Raw Data Input for AES Encryption ([95:64] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DIN_2_SW_AES_DIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DIN_2_SW_AES_DIN_SHIFT)) & BLE2_REG_BLE_REG_AES_DIN_2_SW_AES_DIN_MASK)
/*! @} */

/*! @name BLE_REG_AES_DIN_3 - Raw Data Input 3 for Software AES encryption */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DIN_3_SW_AES_DIN_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DIN_3_SW_AES_DIN_SHIFT (0U)
/*! sw_aes_din - Raw Data Input for AES Encryption ([127:96] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DIN_3_SW_AES_DIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DIN_3_SW_AES_DIN_SHIFT)) & BLE2_REG_BLE_REG_AES_DIN_3_SW_AES_DIN_MASK)
/*! @} */

/*! @name BLE_REG_AES_DOUT_0 - AES Encrypted Data Output 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DOUT_0_SW_AES_DOUT_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DOUT_0_SW_AES_DOUT_SHIFT (0U)
/*! sw_aes_dout - AES Encrypted Data Output ([31:0] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DOUT_0_SW_AES_DOUT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DOUT_0_SW_AES_DOUT_SHIFT)) & BLE2_REG_BLE_REG_AES_DOUT_0_SW_AES_DOUT_MASK)
/*! @} */

/*! @name BLE_REG_AES_DOUT_1 - AES Encrypted Data Output 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DOUT_1_SW_AES_DOUT_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DOUT_1_SW_AES_DOUT_SHIFT (0U)
/*! sw_aes_dout - AES Encrypted Data Output ([63:32] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DOUT_1_SW_AES_DOUT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DOUT_1_SW_AES_DOUT_SHIFT)) & BLE2_REG_BLE_REG_AES_DOUT_1_SW_AES_DOUT_MASK)
/*! @} */

/*! @name BLE_REG_AES_DOUT_2 - AES Encrypted Data Output 2 */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DOUT_2_SW_AES_DOUT_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DOUT_2_SW_AES_DOUT_SHIFT (0U)
/*! sw_aes_dout - AES Encrypted Data Output ([95:64] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DOUT_2_SW_AES_DOUT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DOUT_2_SW_AES_DOUT_SHIFT)) & BLE2_REG_BLE_REG_AES_DOUT_2_SW_AES_DOUT_MASK)
/*! @} */

/*! @name BLE_REG_AES_DOUT_3 - AES Encrypted Data Output 3 */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_DOUT_3_SW_AES_DOUT_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_AES_DOUT_3_SW_AES_DOUT_SHIFT (0U)
/*! sw_aes_dout - AES Encrypted Data Output ([127:96] of 128-bit) */
#define BLE2_REG_BLE_REG_AES_DOUT_3_SW_AES_DOUT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_DOUT_3_SW_AES_DOUT_SHIFT)) & BLE2_REG_BLE_REG_AES_DOUT_3_SW_AES_DOUT_MASK)
/*! @} */

/*! @name BLE_REG_INT_MASK_0 - BLE Interrupt Mask 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_MASK_0_RT_ERR_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_MASK_0_RT_ERR_INTR_SHIFT (0U)
/*! rt_err_intr - rt_err_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt. The
 *    BLE_REG_RT_ERR_MASK should also be programmed to enable, desired event bit.
 *  0b0..disable interrupt
 *  0b1..enable interrupt. The BLE_REG_RT_ERR_MASK should also be programmed to enable desired event bit.
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_RT_ERR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_RT_ERR_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_RT_ERR_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_PST_2_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_INT_MASK_0_PST_2_INTR_SHIFT (3U)
/*! pst_2_intr - pst_2_intr interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_PST_2_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_PST_2_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_PST_2_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_PST_1_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_INT_MASK_0_PST_1_INTR_SHIFT (4U)
/*! pst_1_intr - pst_2_intr interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_PST_1_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_PST_1_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_PST_1_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_PST_0_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_INT_MASK_0_PST_0_INTR_SHIFT (5U)
/*! pst_0_intr - pst_2_intr interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_PST_0_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_PST_0_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_PST_0_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_5_MASK (0x40U)
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_5_SHIFT (6U)
/*! cdt_expiry_intr_5 - cdt_expiry_intr[5] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_5(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_5_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_5_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_4_MASK (0x80U)
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_4_SHIFT (7U)
/*! cdt_expiry_intr_4 - cdt_expiry_intr[4] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_4(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_4_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_4_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_3_MASK (0x100U)
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_3_SHIFT (8U)
/*! cdt_expiry_intr_3 - cdt_expiry_intr[3] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_2_MASK (0x200U)
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_2_SHIFT (9U)
/*! cdt_expiry_intr_2 - cdt_expiry_intr[2] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_1_MASK (0x400U)
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_1_SHIFT (10U)
/*! cdt_expiry_intr_1 - cdt_expiry_intr[1] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_0_MASK (0x800U)
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_0_SHIFT (11U)
/*! cdt_expiry_intr_0 - cdt_expiry_intr[0] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_CDT_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_3_MASK (0x1000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_3_SHIFT (12U)
/*! expiry_intr_3 - expiry_intr[3] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_2_MASK (0x2000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_2_SHIFT (13U)
/*! expiry_intr_2 - expiry_intr[2] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_1_MASK (0x4000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_1_SHIFT (14U)
/*! expiry_intr_1 - expiry_intr[1] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_0_MASK (0x8000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_0_SHIFT (15U)
/*! expiry_intr_0 - expiry_intr[0] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_TMR_ABORT_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_TMR_ABORT_INTR_SHIFT (16U)
/*! tmr_abort_intr - tmr_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_TMR_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_TMR_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_TMR_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_HW_ABORT_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_HW_ABORT_INTR_SHIFT (17U)
/*! hw_abort_intr - hw_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt. The
 *    BLE_REG_HW_ABORT_MASK should also be programmed to enable, desired event bit.
 *  0b0..disable interrupt
 *  0b1..enable interrupt. The BLE_REG_HW_ABORT_MASK should also be programmed to enable desired event bit.
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_HW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_HW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_HW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_SW_ABORT_INTR_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_SW_ABORT_INTR_SHIFT (18U)
/*! sw_abort_intr - sw_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_SW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_SW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_SW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_RX_PKT_DONE_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_PKT_DONE_INTR_SHIFT (21U)
/*! rx_pkt_done_intr - rx_pkt_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_RX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_RX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_RX_DATA_DONE_INTR_MASK (0x400000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_DATA_DONE_INTR_SHIFT (22U)
/*! rx_data_done_intr - rx_data_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_RX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_RX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_EXT_HEADER_DONE_INTR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT (23U)
/*! rx_adv_ext_header_done_intr - rx_adv_ext_header_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_EXT_HEADER_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_EXT_HEADER_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_IRK_RESOLVE_DONE_INTR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_IRK_RESOLVE_DONE_INTR_SHIFT (24U)
/*! irk_resolve_done_intr - irk_resolve_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_IRK_RESOLVE_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_IRK_RESOLVE_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_IRK_RESOLVE_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_ADDR_DONE_INTR_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_ADDR_DONE_INTR_SHIFT (25U)
/*! rx_adv_addr_done_intr - rx_adv_addr_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_ADDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_ADDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_RX_ADV_ADDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_RX_HDR_DONE_INTR_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_HDR_DONE_INTR_SHIFT (26U)
/*! rx_hdr_done_intr - rx_hdr_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_RX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_RX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_RX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_COR_HIT_INTR_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_COR_HIT_INTR_SHIFT (27U)
/*! cor_hit_intr - cor_hit_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_COR_HIT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_COR_HIT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_COR_HIT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_TX_PKT_DONE_INTR_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_PKT_DONE_INTR_SHIFT (28U)
/*! tx_pkt_done_intr - tx_pkt_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_TX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_TX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_TX_DATA_DONE_INTR_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_DATA_DONE_INTR_SHIFT (29U)
/*! tx_data_done_intr - tx_data_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_TX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_TX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_TX_HDR_DONE_INTR_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_HDR_DONE_INTR_SHIFT (30U)
/*! tx_hdr_done_intr - tx_hdr_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_TX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_TX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_0_TX_ACC_DONE_INTR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_ACC_DONE_INTR_SHIFT (31U)
/*! tx_acc_done_intr - tx_acc_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_0_TX_ACC_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_0_TX_ACC_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_0_TX_ACC_DONE_INTR_MASK)
/*! @} */

/*! @name BLE_REG_INT_MASK_1 - BLE Interrupt Mask 0/1 */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_MASK_1_RT_ERR_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_MASK_1_RT_ERR_INTR_SHIFT (0U)
/*! rt_err_intr - rt_err_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt. The
 *    BLE_REG_RT_ERR_MASK should also be programmed to enable, desired event bit.
 *  0b0..disable interrupt
 *  0b1..enable interrupt. The BLE_REG_RT_ERR_MASK should also be programmed to enable desired event bit.
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_RT_ERR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_RT_ERR_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_RT_ERR_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_PST_2_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_INT_MASK_1_PST_2_INTR_SHIFT (3U)
/*! pst_2_intr - pst_2_intr interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_PST_2_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_PST_2_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_PST_2_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_PST_1_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_INT_MASK_1_PST_1_INTR_SHIFT (4U)
/*! pst_1_intr - pst_2_intr interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_PST_1_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_PST_1_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_PST_1_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_PST_0_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_INT_MASK_1_PST_0_INTR_SHIFT (5U)
/*! pst_0_intr - pst_2_intr interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_PST_0_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_PST_0_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_PST_0_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_5_MASK (0x40U)
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_5_SHIFT (6U)
/*! cdt_expiry_intr_5 - cdt_expiry_intr[5] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_5(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_5_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_5_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_4_MASK (0x80U)
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_4_SHIFT (7U)
/*! cdt_expiry_intr_4 - cdt_expiry_intr[4] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_4(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_4_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_4_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_3_MASK (0x100U)
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_3_SHIFT (8U)
/*! cdt_expiry_intr_3 - cdt_expiry_intr[3] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_2_MASK (0x200U)
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_2_SHIFT (9U)
/*! cdt_expiry_intr_2 - cdt_expiry_intr[2] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_1_MASK (0x400U)
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_1_SHIFT (10U)
/*! cdt_expiry_intr_1 - cdt_expiry_intr[1] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_0_MASK (0x800U)
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_0_SHIFT (11U)
/*! cdt_expiry_intr_0 - cdt_expiry_intr[0] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_CDT_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_3_MASK (0x1000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_3_SHIFT (12U)
/*! expiry_intr_3 - expiry_intr[3] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_2_MASK (0x2000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_2_SHIFT (13U)
/*! expiry_intr_2 - expiry_intr[2] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_1_MASK (0x4000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_1_SHIFT (14U)
/*! expiry_intr_1 - expiry_intr[1] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_0_MASK (0x8000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_0_SHIFT (15U)
/*! expiry_intr_0 - expiry_intr[0] interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_TMR_ABORT_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_TMR_ABORT_INTR_SHIFT (16U)
/*! tmr_abort_intr - tmr_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_TMR_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_TMR_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_TMR_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_HW_ABORT_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_HW_ABORT_INTR_SHIFT (17U)
/*! hw_abort_intr - hw_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt. The
 *    BLE_REG_HW_ABORT_MASK should also be programmed to enable, desired event bit.
 *  0b0..disable interrupt
 *  0b1..enable interrupt. The BLE_REG_HW_ABORT_MASK should also be programmed to enable desired event bit.
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_HW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_HW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_HW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_SW_ABORT_INTR_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_SW_ABORT_INTR_SHIFT (18U)
/*! sw_abort_intr - sw_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_SW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_SW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_SW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_RX_PKT_DONE_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_PKT_DONE_INTR_SHIFT (21U)
/*! rx_pkt_done_intr - rx_pkt_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_RX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_RX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_RX_DATA_DONE_INTR_MASK (0x400000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_DATA_DONE_INTR_SHIFT (22U)
/*! rx_data_done_intr - rx_data_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_RX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_RX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_EXT_HEADER_DONE_INTR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT (23U)
/*! rx_adv_ext_header_done_intr - rx_adv_ext_header_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_EXT_HEADER_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_EXT_HEADER_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_IRK_RESOLVE_DONE_INTR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_IRK_RESOLVE_DONE_INTR_SHIFT (24U)
/*! irk_resolve_done_intr - irk_resolve_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_IRK_RESOLVE_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_IRK_RESOLVE_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_IRK_RESOLVE_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_ADDR_DONE_INTR_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_ADDR_DONE_INTR_SHIFT (25U)
/*! rx_adv_addr_done_intr - rx_adv_addr_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_ADDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_ADDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_RX_ADV_ADDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_RX_HDR_DONE_INTR_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_HDR_DONE_INTR_SHIFT (26U)
/*! rx_hdr_done_intr - rx_hdr_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_RX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_RX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_RX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_COR_HIT_INTR_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_COR_HIT_INTR_SHIFT (27U)
/*! cor_hit_intr - cor_hit_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_COR_HIT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_COR_HIT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_COR_HIT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_TX_PKT_DONE_INTR_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_PKT_DONE_INTR_SHIFT (28U)
/*! tx_pkt_done_intr - tx_pkt_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_TX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_TX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_TX_DATA_DONE_INTR_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_DATA_DONE_INTR_SHIFT (29U)
/*! tx_data_done_intr - tx_data_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_TX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_TX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_TX_HDR_DONE_INTR_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_HDR_DONE_INTR_SHIFT (30U)
/*! tx_hdr_done_intr - tx_hdr_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_TX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_TX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_1_TX_ACC_DONE_INTR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_ACC_DONE_INTR_SHIFT (31U)
/*! tx_acc_done_intr - tx_acc_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_1_TX_ACC_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_1_TX_ACC_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_1_TX_ACC_DONE_INTR_MASK)
/*! @} */

/*! @name BLE_REG_INT_MASK_2 - BLE Interrupt Mask 2 */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_MASK_2_SW_AES_DONE_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_MASK_2_SW_AES_DONE_SHIFT (0U)
/*! sw_aes_done - sw_aes_done interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_SW_AES_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_SW_AES_DONE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_SW_AES_DONE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_SW_DBUS_DONE_INTR_MASK (0x2U)
#define BLE2_REG_BLE_REG_INT_MASK_2_SW_DBUS_DONE_INTR_SHIFT (1U)
/*! sw_dbus_done_intr - sw_dbus_done_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_SW_DBUS_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_SW_DBUS_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_SW_DBUS_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_SW_MAILBOX_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_INT_MASK_2_SW_MAILBOX_INTR_SHIFT (4U)
/*! sw_mailbox_intr - sw_mailbox_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_SW_MAILBOX_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_SW_MAILBOX_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_SW_MAILBOX_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_SHIFT (16U)
/*! MWS_Frame_Sync_Real_IE - MWS Frame Sync Interrupt Enable
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_SHIFT (16U)
/*! mws_frame_sync_real_ie - MWS Frame Sync Interrupt Enable, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_FRAME_SYNC_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_SHIFT (17U)
/*! MWS_Pattern_Real_IE - MWS Pattern Interrupt Enable
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_SHIFT (17U)
/*! mws_pattern_real_ie - MWS Pattern Interrupt Enable, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_PATTERN_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_SHIFT (18U)
/*! Frame_Sync_Update_Real_IE - MWS Frame Sync Update Interrupt Enable
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_SHIFT (18U)
/*! frame_sync_update_real_ie - MWS Frame Sync Update Interrupt Enable, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_FRAME_SYNC_UPDATE_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_MASK (0x80000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_SHIFT (19U)
/*! HARQ_Pattern_Sel_Real_IE - HARQ Pattern Sel Interrupt Enable
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_MASK (0x80000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_SHIFT (19U)
/*! harq_pattern_sel_real_ie - HARQ Pattern Sel Interrupt Enable, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_HARQ_PATTERN_SEL_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_MASK (0x100000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_SHIFT (20U)
/*! MWS_Scan_Frequency_Real_IE - MWS Scan Frequency Interrupt Enable
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_MASK (0x100000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_SHIFT (20U)
/*! mws_scan_frequency_real_ie - MWS Scan Frequency Interrupt Enable, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_SCAN_FREQUENCY_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_SHIFT (21U)
/*! MWS_Inact_Msg_Real_IE - MWS Inactivity Message Interrupt Enable
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_MASK)

#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_SHIFT (21U)
/*! mws_inact_msg_real_ie - MWS Inactivity Message Interrupt Enable, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_SHIFT)) & BLE2_REG_BLE_REG_INT_MASK_2_MWS_INACT_MSG_REAL_IE_MASK)
/*! @} */

/*! @name BLE_REG_HW_ABORT_MASK - BLE Interrupt Mask, hardware Abort */
/*! @{ */

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_DENY_STS_MASK (0x1U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_DENY_STS_SHIFT (0U)
/*! ble_deny_sts - ble_deny_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_DENY_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_DENY_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_DENY_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CUTOFF_STS_MASK (0x2U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CUTOFF_STS_SHIFT (1U)
/*! ble_cutoff_sts - ble_cutoff_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CUTOFF_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CUTOFF_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CUTOFF_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCADENY_STS_MASK (0x4U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCADENY_STS_SHIFT (2U)
/*! ble_bcadeny_sts - ble_bcadeny_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCADENY_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCADENY_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCADENY_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCACUTOFF_STS_MASK (0x8U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCACUTOFF_STS_SHIFT (3U)
/*! ble_bcacutoff_sts - ble_bcacutoff_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCACUTOFF_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCACUTOFF_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_BCACUTOFF_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_COR_TIMEOUT_INTR_STS_MASK (0x10U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_COR_TIMEOUT_INTR_STS_SHIFT (4U)
/*! cor_timeout_intr_sts - cor_timeout_intr_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_COR_TIMEOUT_INTR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_COR_TIMEOUT_INTR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_COR_TIMEOUT_INTR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_STS_MASK (0x20U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_STS_SHIFT (5U)
/*! rx_sync_pulse_timeout_intr_sts - rx_sync_pulse_timeout_intr_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_DATAVLD_TIMEOUT_INTR_STS_MASK (0x40U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_DATAVLD_TIMEOUT_INTR_STS_SHIFT (6U)
/*! rx_datavld_timeout_intr_sts - rx_datavld_timeout_intr_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_DATAVLD_TIMEOUT_INTR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_DATAVLD_TIMEOUT_INTR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_RX_DATAVLD_TIMEOUT_INTR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_TXRX_ERROR_STS_MASK (0x80U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_TXRX_ERROR_STS_SHIFT (7U)
/*! txrx_error_sts - txrx_error_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_TXRX_ERROR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_TXRX_ERROR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_TXRX_ERROR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_B4_A2_STS_MASK (0x100U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_B4_A2_STS_SHIFT (8U)
/*! sw_abort_b4_a2_sts - sw_abort_b4_a2_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_B4_A2_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_B4_A2_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_B4_A2_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_AFTER_A2_STS_MASK (0x200U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_AFTER_A2_STS_SHIFT (9U)
/*! sw_abort_after_a2_sts - sw_abort_after_a2_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_AFTER_A2_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_AFTER_A2_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_SW_ABORT_AFTER_A2_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_STS_MASK (0x400U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_STS_SHIFT (10U)
/*! ble_cca_abort_sts - ble_cca_abort_sts interrupt, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_THD_MET_STS_MASK (0x800U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_THD_MET_STS_SHIFT (11U)
/*! ble_cca_abort_thd_met_sts - ble_cca_abort_thd_met interrupt, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_THD_MET_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_THD_MET_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_ABORT_THD_MET_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_TXPKT_THD_MET_STS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_TXPKT_THD_MET_STS_SHIFT (12U)
/*! ble_cca_txpkt_thd_met_sts - ble_cca_txpkt_thd_met interrupt, 0x0: disable interrupt, 0x1: enable interrupt */
#define BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_TXPKT_THD_MET_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_TXPKT_THD_MET_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_MASK_BLE_CCA_TXPKT_THD_MET_STS_MASK)
/*! @} */

/*! @name BLE_REG_RT_ERR_MASK - BLE Interrupt Mask, Real-time Error */
/*! @{ */

#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_CUTOFF_INTR_MASK (0x2U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_CUTOFF_INTR_SHIFT (1U)
/*! ble_cutoff_intr - ble_cutoff_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_CUTOFF_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_CUTOFF_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_CUTOFF_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_EXTN_FAIL_INTR_MASK (0x4U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_EXTN_FAIL_INTR_SHIFT (2U)
/*! ble_extn_fail_intr - ble_extn_fail_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_EXTN_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_EXTN_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_EXTN_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_BCACUTOFF_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_BCACUTOFF_INTR_SHIFT (3U)
/*! ble_bcacutoff_intr - ble_bcacutoff_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_BCACUTOFF_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_BCACUTOFF_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_BLE_BCACUTOFF_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_COR_TIMEOUT_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_COR_TIMEOUT_INTR_SHIFT (4U)
/*! cor_timeout_intr - cor_timeout_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_COR_TIMEOUT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_COR_TIMEOUT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_COR_TIMEOUT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_SHIFT (5U)
/*! rx_sync_pulse_timeout_intr - rx_sync_pulse_timeout_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_SYNC_PULSE_TIMEOUT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_SYNC_PULSE_TIMEOUT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DATAVLD_TIMEOUT_INTR_MASK (0x40U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DATAVLD_TIMEOUT_INTR_SHIFT (6U)
/*! rx_datavld_timeout_intr - rx_datavld_timeout_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DATAVLD_TIMEOUT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DATAVLD_TIMEOUT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DATAVLD_TIMEOUT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ANT_SWITCH_FAIL_INTR_MASK (0x100U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ANT_SWITCH_FAIL_INTR_SHIFT (8U)
/*! tx_extn_ant_switch_fail_intr - tx_extn_ant_switch_fail_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ANT_SWITCH_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ANT_SWITCH_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ANT_SWITCH_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ABORT_INTR_MASK (0x200U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ABORT_INTR_SHIFT (9U)
/*! tx_extn_abort_intr - tx_extn_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_TX_EXTN_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ANT_SWITCH_FAIL_INTR_MASK (0x400U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ANT_SWITCH_FAIL_INTR_SHIFT (10U)
/*! rx_extn_ant_switch_fail_intr - rx_extn_ant_switch_fail_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ANT_SWITCH_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ANT_SWITCH_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ANT_SWITCH_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ABORT_INTR_MASK (0x800U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ABORT_INTR_SHIFT (11U)
/*! rx_extn_abort_intr - rx_extn_abort_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_EXTN_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_LOCK_FAIL_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_LOCK_FAIL_INTR_SHIFT (16U)
/*! tx_lock_fail_intr - tx_lock_fail_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_LOCK_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_TX_LOCK_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_TX_LOCK_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_DMEM_UNDERFLOW_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_DMEM_UNDERFLOW_INTR_SHIFT (17U)
/*! tx_dmem_underflow_intr - tx_dmem_underflow_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_DMEM_UNDERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_TX_DMEM_UNDERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_TX_DMEM_UNDERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_AES_UNDERFLOW_INTR_MASK (0x40000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_AES_UNDERFLOW_INTR_SHIFT (18U)
/*! tx_aes_underflow_intr - tx_aes_underflow_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_TX_AES_UNDERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_TX_AES_UNDERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_TX_AES_UNDERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LOCK_FAIL_INTR_MASK (0x100000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LOCK_FAIL_INTR_SHIFT (20U)
/*! rx_lock_fail_intr - rx_lock_fail_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LOCK_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LOCK_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LOCK_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DMEM_OVERFLOW_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DMEM_OVERFLOW_INTR_SHIFT (21U)
/*! rx_dmem_overflow_intr - rx_dmem_overflow_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DMEM_OVERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DMEM_OVERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_DMEM_OVERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_AES_UNDERFLOW_INTR_MASK (0x400000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_AES_UNDERFLOW_INTR_SHIFT (22U)
/*! rx_aes_underflow_intr - rx_aes_underflow_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_AES_UNDERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_AES_UNDERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_AES_UNDERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LENGTH_ERR_INTR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LENGTH_ERR_INTR_SHIFT (23U)
/*! rx_length_err_intr - rx_length_err_intr interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LENGTH_ERR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LENGTH_ERR_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_RX_LENGTH_ERR_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_AHB_ERROR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_AHB_ERROR_SHIFT (24U)
/*! ahb_error - ahb_error interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_AHB_ERROR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_AHB_ERROR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_AHB_ERROR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_MASK_DMA_ERROR_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_RT_ERR_MASK_DMA_ERROR_SHIFT (25U)
/*! dma_error - dma_error interrupt, 0x0: disable interrupt, 0x1: enable interrupt
 *  0b0..disable interrupt
 *  0b1..enable interrupt
 */
#define BLE2_REG_BLE_REG_RT_ERR_MASK_DMA_ERROR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_MASK_DMA_ERROR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_MASK_DMA_ERROR_MASK)
/*! @} */

/*! @name BLE_REG_INT_STS_0 - BLE Interrupt Status 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_STS_0_RT_ERR_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_STS_0_RT_ERR_INTR_SHIFT (0U)
/*! rt_err_intr - rt_err_intr interrupt, At least 1 of the real-time error events has been asserted. Read BLE_REG_RT_ERR_STS for details. */
#define BLE2_REG_BLE_REG_INT_STS_0_RT_ERR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_RT_ERR_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_RT_ERR_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_PST_2_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_INT_STS_0_PST_2_INTR_SHIFT (3U)
/*! pst_2_intr - Periodic SW Timer 2 interrupt */
#define BLE2_REG_BLE_REG_INT_STS_0_PST_2_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_PST_2_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_PST_2_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_PST_1_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_INT_STS_0_PST_1_INTR_SHIFT (4U)
/*! pst_1_intr - Periodic SW Timer 1 interrupt */
#define BLE2_REG_BLE_REG_INT_STS_0_PST_1_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_PST_1_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_PST_1_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_PST_0_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_INT_STS_0_PST_0_INTR_SHIFT (5U)
/*! pst_0_intr - Periodic SW Timer 0 interrupt */
#define BLE2_REG_BLE_REG_INT_STS_0_PST_0_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_PST_0_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_PST_0_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_5_MASK (0x40U)
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_5_SHIFT (6U)
/*! cdt_expiry_intr_5 - cdt_expiry_intr[5] interrupt, CDT 5 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_5(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_5_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_5_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_4_MASK (0x80U)
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_4_SHIFT (7U)
/*! cdt_expiry_intr_4 - cdt_expiry_intr[4] interrupt, CDT 4 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_4(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_4_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_4_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_3_MASK (0x100U)
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_3_SHIFT (8U)
/*! cdt_expiry_intr_3 - cdt_expiry_intr[3] interrupt, CDT 3 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_2_MASK (0x200U)
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_2_SHIFT (9U)
/*! cdt_expiry_intr_2 - cdt_expiry_intr[2] interrupt, CDT 2 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_1_MASK (0x400U)
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_1_SHIFT (10U)
/*! cdt_expiry_intr_1 - cdt_expiry_intr[1] interrupt, CDT 1 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_0_MASK (0x800U)
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_0_SHIFT (11U)
/*! cdt_expiry_intr_0 - cdt_expiry_intr[0] interrupt, CDT 0 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_CDT_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_3_MASK (0x1000U)
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_3_SHIFT (12U)
/*! expiry_intr_3 - expiry_intr[3] interrupt, SWT 3 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_2_MASK (0x2000U)
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_2_SHIFT (13U)
/*! expiry_intr_2 - expiry_intr[2] interrupt, SWT 2 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_1_MASK (0x4000U)
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_1_SHIFT (14U)
/*! expiry_intr_1 - expiry_intr[1] interrupt, SWT 1 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_0_MASK (0x8000U)
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_0_SHIFT (15U)
/*! expiry_intr_0 - expiry_intr[0] interrupt, SWT 0 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_TMR_ABORT_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_STS_0_TMR_ABORT_INTR_SHIFT (16U)
/*! tmr_abort_intr - tmr_abort_intr interrupt, SWT timer abort interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_0_TMR_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_TMR_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_TMR_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_HW_ABORT_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_STS_0_HW_ABORT_INTR_SHIFT (17U)
/*! hw_abort_intr - hw_abort_intr interrupt, At least 1 of the hardware abort events has been
 *    asserted. Read BLE_REG_HW_ABORT_STS for details.
 */
#define BLE2_REG_BLE_REG_INT_STS_0_HW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_HW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_HW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_SW_ABORT_INTR_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_STS_0_SW_ABORT_INTR_SHIFT (18U)
/*! sw_abort_intr - sw_abort_intr interrupt, Software DBUS access has been aborted. */
#define BLE2_REG_BLE_REG_INT_STS_0_SW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_SW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_SW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_RX_PKT_DONE_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_STS_0_RX_PKT_DONE_INTR_SHIFT (21U)
/*! rx_pkt_done_intr - rx_pkt_done_intr interrupt, Receive packet done. */
#define BLE2_REG_BLE_REG_INT_STS_0_RX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_RX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_RX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_RX_DATA_DONE_INTR_MASK (0x400000U)
#define BLE2_REG_BLE_REG_INT_STS_0_RX_DATA_DONE_INTR_SHIFT (22U)
/*! rx_data_done_intr - rx_data_done_intr interrupt, Receive data (payload & MIC) done. */
#define BLE2_REG_BLE_REG_INT_STS_0_RX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_RX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_RX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_EXT_HEADER_DONE_INTR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT (23U)
/*! rx_adv_ext_header_done_intr - rx_adv_ext_header_done_intr interrupt, Packet has completed advertising extension header portion. */
#define BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_EXT_HEADER_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_EXT_HEADER_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_IRK_RESOLVE_DONE_INTR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_IRK_RESOLVE_DONE_INTR_SHIFT (24U)
/*! irk_resolve_done_intr - irk_resolve_done_intr interrupt, SWT timer abort interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_0_IRK_RESOLVE_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_IRK_RESOLVE_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_IRK_RESOLVE_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_ADDR_DONE_INTR_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_ADDR_DONE_INTR_SHIFT (25U)
/*! rx_adv_addr_done_intr - rx_adv_addr_done_intr interrupt, Packet has completed first 48-bits
 *    device address portion (for adv channel only). Interrupt is also generated if
 *    reuse_rx_adv_addr_done_intr =1 and if advA bit is 0 in the extended header flag of the advertisement packet
 *    received. Interrupt is generated after reception of the extended header flag field.
 */
#define BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_ADDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_ADDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_RX_ADV_ADDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_RX_HDR_DONE_INTR_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_RX_HDR_DONE_INTR_SHIFT (26U)
/*! rx_hdr_done_intr - rx_hdr_done_intr interrupt, Receive header done. */
#define BLE2_REG_BLE_REG_INT_STS_0_RX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_RX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_RX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_COR_HIT_INTR_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_COR_HIT_INTR_SHIFT (27U)
/*! cor_hit_intr - cor_hit_intr interrupt, Correlation has been detected. */
#define BLE2_REG_BLE_REG_INT_STS_0_COR_HIT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_COR_HIT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_COR_HIT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_TX_PKT_DONE_INTR_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_TX_PKT_DONE_INTR_SHIFT (28U)
/*! tx_pkt_done_intr - tx_pkt_done_intr interrupt, Transmit packet done. */
#define BLE2_REG_BLE_REG_INT_STS_0_TX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_TX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_TX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_TX_DATA_DONE_INTR_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_TX_DATA_DONE_INTR_SHIFT (29U)
/*! tx_data_done_intr - tx_data_done_intr interrupt, Transmit data (payload & MIC) done. */
#define BLE2_REG_BLE_REG_INT_STS_0_TX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_TX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_TX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_TX_HDR_DONE_INTR_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_TX_HDR_DONE_INTR_SHIFT (30U)
/*! tx_hdr_done_intr - tx_hdr_done_intr interrupt, Transmit header done. */
#define BLE2_REG_BLE_REG_INT_STS_0_TX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_TX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_TX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_0_TX_ACC_DONE_INTR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_INT_STS_0_TX_ACC_DONE_INTR_SHIFT (31U)
/*! tx_acc_done_intr - tx_acc_done_intr interrupt, Packet has completed access code portion. */
#define BLE2_REG_BLE_REG_INT_STS_0_TX_ACC_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_0_TX_ACC_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_0_TX_ACC_DONE_INTR_MASK)
/*! @} */

/*! @name BLE_REG_INT_STS_1 - BLE Interrupt Status 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_STS_1_RT_ERR_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_STS_1_RT_ERR_INTR_SHIFT (0U)
/*! rt_err_intr - rt_err_intr interrupt, At least 1 of the real-time error events has been asserted. Read BLE_REG_RT_ERR_STS for details. */
#define BLE2_REG_BLE_REG_INT_STS_1_RT_ERR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_RT_ERR_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_RT_ERR_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_PST_2_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_INT_STS_1_PST_2_INTR_SHIFT (3U)
/*! pst_2_intr - Periodic SW Timer 2 interrupt */
#define BLE2_REG_BLE_REG_INT_STS_1_PST_2_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_PST_2_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_PST_2_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_PST_1_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_INT_STS_1_PST_1_INTR_SHIFT (4U)
/*! pst_1_intr - Periodic SW Timer 1 interrupt */
#define BLE2_REG_BLE_REG_INT_STS_1_PST_1_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_PST_1_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_PST_1_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_PST_0_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_INT_STS_1_PST_0_INTR_SHIFT (5U)
/*! pst_0_intr - Periodic SW Timer 0 interrupt */
#define BLE2_REG_BLE_REG_INT_STS_1_PST_0_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_PST_0_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_PST_0_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_5_MASK (0x40U)
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_5_SHIFT (6U)
/*! cdt_expiry_intr_5 - cdt_expiry_intr[5] interrupt, CDT 5 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_5(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_5_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_5_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_4_MASK (0x80U)
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_4_SHIFT (7U)
/*! cdt_expiry_intr_4 - cdt_expiry_intr[4] interrupt, CDT 4 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_4(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_4_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_4_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_3_MASK (0x100U)
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_3_SHIFT (8U)
/*! cdt_expiry_intr_3 - cdt_expiry_intr[3] interrupt, CDT 3 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_2_MASK (0x200U)
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_2_SHIFT (9U)
/*! cdt_expiry_intr_2 - cdt_expiry_intr[2] interrupt, CDT 2 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_1_MASK (0x400U)
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_1_SHIFT (10U)
/*! cdt_expiry_intr_1 - cdt_expiry_intr[1] interrupt, CDT 1 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_0_MASK (0x800U)
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_0_SHIFT (11U)
/*! cdt_expiry_intr_0 - cdt_expiry_intr[0] interrupt, CDT 0 trigger countdown timer. */
#define BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_CDT_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_3_MASK (0x1000U)
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_3_SHIFT (12U)
/*! expiry_intr_3 - expiry_intr[3] interrupt, SWT 3 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_2_MASK (0x2000U)
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_2_SHIFT (13U)
/*! expiry_intr_2 - expiry_intr[2] interrupt, SWT 2 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_1_MASK (0x4000U)
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_1_SHIFT (14U)
/*! expiry_intr_1 - expiry_intr[1] interrupt, SWT 1 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_0_MASK (0x8000U)
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_0_SHIFT (15U)
/*! expiry_intr_0 - expiry_intr[0] interrupt, SWT 0 expiration interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_TMR_ABORT_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_STS_1_TMR_ABORT_INTR_SHIFT (16U)
/*! tmr_abort_intr - tmr_abort_intr interrupt, SWT timer abort interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_1_TMR_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_TMR_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_TMR_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_HW_ABORT_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_STS_1_HW_ABORT_INTR_SHIFT (17U)
/*! hw_abort_intr - hw_abort_intr interrupt, At least 1 of the hardware abort events has been
 *    asserted. Read BLE_REG_HW_ABORT_STS for details.
 */
#define BLE2_REG_BLE_REG_INT_STS_1_HW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_HW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_HW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_SW_ABORT_INTR_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_STS_1_SW_ABORT_INTR_SHIFT (18U)
/*! sw_abort_intr - sw_abort_intr interrupt, Software DBUS access has been aborted. */
#define BLE2_REG_BLE_REG_INT_STS_1_SW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_SW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_SW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_RX_PKT_DONE_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_STS_1_RX_PKT_DONE_INTR_SHIFT (21U)
/*! rx_pkt_done_intr - rx_pkt_done_intr interrupt, Receive packet done. */
#define BLE2_REG_BLE_REG_INT_STS_1_RX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_RX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_RX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_RX_DATA_DONE_INTR_MASK (0x400000U)
#define BLE2_REG_BLE_REG_INT_STS_1_RX_DATA_DONE_INTR_SHIFT (22U)
/*! rx_data_done_intr - rx_data_done_intr interrupt, Receive data (payload & MIC) done. */
#define BLE2_REG_BLE_REG_INT_STS_1_RX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_RX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_RX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_EXT_HEADER_DONE_INTR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT (23U)
/*! rx_adv_ext_header_done_intr - rx_adv_ext_header_done_intr interrupt, Packet has completed advertising extension header portion. */
#define BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_EXT_HEADER_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_EXT_HEADER_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_IRK_RESOLVE_DONE_INTR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_IRK_RESOLVE_DONE_INTR_SHIFT (24U)
/*! irk_resolve_done_intr - irk_resolve_done_intr interrupt, SWT timer abort interrupt. */
#define BLE2_REG_BLE_REG_INT_STS_1_IRK_RESOLVE_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_IRK_RESOLVE_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_IRK_RESOLVE_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_ADDR_DONE_INTR_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_ADDR_DONE_INTR_SHIFT (25U)
/*! rx_adv_addr_done_intr - rx_adv_addr_done_intr interrupt, Packet has completed first 48-bits
 *    device address portion (for adv channel only). Interrupt is also generated if
 *    reuse_rx_adv_addr_done_intr =1 and if advA bit is 0 in the extended header flag of the advertisement packet
 *    received. Interrupt is generated after reception of the extended header flag field.
 */
#define BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_ADDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_ADDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_RX_ADV_ADDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_RX_HDR_DONE_INTR_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_RX_HDR_DONE_INTR_SHIFT (26U)
/*! rx_hdr_done_intr - rx_hdr_done_intr interrupt, Receive header done. */
#define BLE2_REG_BLE_REG_INT_STS_1_RX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_RX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_RX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_COR_HIT_INTR_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_COR_HIT_INTR_SHIFT (27U)
/*! cor_hit_intr - cor_hit_intr interrupt, Correlation has been detected. */
#define BLE2_REG_BLE_REG_INT_STS_1_COR_HIT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_COR_HIT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_COR_HIT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_TX_PKT_DONE_INTR_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_TX_PKT_DONE_INTR_SHIFT (28U)
/*! tx_pkt_done_intr - tx_pkt_done_intr interrupt, Transmit packet done. */
#define BLE2_REG_BLE_REG_INT_STS_1_TX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_TX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_TX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_TX_DATA_DONE_INTR_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_TX_DATA_DONE_INTR_SHIFT (29U)
/*! tx_data_done_intr - tx_data_done_intr interrupt, Transmit data (payload & MIC) done. */
#define BLE2_REG_BLE_REG_INT_STS_1_TX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_TX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_TX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_TX_HDR_DONE_INTR_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_TX_HDR_DONE_INTR_SHIFT (30U)
/*! tx_hdr_done_intr - tx_hdr_done_intr interrupt, Transmit header done. */
#define BLE2_REG_BLE_REG_INT_STS_1_TX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_TX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_TX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_1_TX_ACC_DONE_INTR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_INT_STS_1_TX_ACC_DONE_INTR_SHIFT (31U)
/*! tx_acc_done_intr - tx_acc_done_intr interrupt, Packet has completed access code portion. */
#define BLE2_REG_BLE_REG_INT_STS_1_TX_ACC_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_1_TX_ACC_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_1_TX_ACC_DONE_INTR_MASK)
/*! @} */

/*! @name BLE_REG_INT_STS_2 - BLE Interrupt Status 2 */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_STS_2_SW_AES_DONE_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_STS_2_SW_AES_DONE_SHIFT (0U)
/*! sw_aes_done - sw_aes_done interrupt, Software AES has been finished. */
#define BLE2_REG_BLE_REG_INT_STS_2_SW_AES_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_SW_AES_DONE_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_SW_AES_DONE_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_SW_DBUS_DONE_INTR_MASK (0x2U)
#define BLE2_REG_BLE_REG_INT_STS_2_SW_DBUS_DONE_INTR_SHIFT (1U)
/*! sw_dbus_done_intr - sw_dbus_done_intr interrupt, Software DBUS access has been finished. */
#define BLE2_REG_BLE_REG_INT_STS_2_SW_DBUS_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_SW_DBUS_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_SW_DBUS_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_SW_MAILBOX_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_INT_STS_2_SW_MAILBOX_INTR_SHIFT (4U)
/*! sw_mailbox_intr - sw_mailbox_intr interrupt, BLE_REG_INT_SW_MBOX register has been written. */
#define BLE2_REG_BLE_REG_INT_STS_2_SW_MAILBOX_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_SW_MAILBOX_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_SW_MAILBOX_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_SHIFT (16U)
/*! MWS_Frame_Sync_Real_Int - MWS Frame Sync Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_SHIFT (16U)
/*! mws_frame_sync_real_int - MWS Frame Sync Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_FRAME_SYNC_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_SHIFT (17U)
/*! MWS_Pattern_Real_Int - MWS Pattern Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_SHIFT (17U)
/*! mws_pattern_real_int - MWS Pattern Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_PATTERN_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_SHIFT (18U)
/*! Frame_Sync_Update_Real_Int - MWS Frame Sync Update Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_SHIFT (18U)
/*! frame_sync_update_real_int - MWS Frame Sync Update Interrupt, Indicating MWS_Frame_Sync has
 *    drastic timing change from previous one that Bluetooth firmware should consider piconet clock
 *    adjustment to re-align with MWS frame.
 */
#define BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_FRAME_SYNC_UPDATE_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_MASK (0x80000U)
#define BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_SHIFT (19U)
/*! HARQ_Pattern_Sel_Real_Int - HARQ Pattern Sel Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_MASK (0x80000U)
#define BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_SHIFT (19U)
/*! harq_pattern_sel_real_int - HARQ Pattern Sel Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_HARQ_PATTERN_SEL_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_MASK (0x100000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_SHIFT (20U)
/*! MWS_Scan_Frequency_Real_Int - MWS Scan Frequency Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_MASK (0x100000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_SHIFT (20U)
/*! mws_scan_frequency_real_int - MWS Scan Frequency Interrupt, Asserted when a new non-zero MWS_Scan_Frequency[4:0] value is received from BCA. */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_SCAN_FREQUENCY_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_SHIFT (21U)
/*! MWS_Inact_Msg_Real_Int - MWS_Inactivity_Message Interrupt */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_MASK)

#define BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_SHIFT (21U)
/*! mws_inact_msg_real_int - MWS_Inactivity_Message Interrupt, Asserted when a new MWS_Inact_Msg[4:0] value is received from BCA. */
#define BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_SHIFT)) & BLE2_REG_BLE_REG_INT_STS_2_MWS_INACT_MSG_REAL_INT_MASK)
/*! @} */

/*! @name BLE_REG_HW_ABORT_STS - BLE Interrupt Status, hardware Abort */
/*! @{ */

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_DENY_STS_MASK (0x1U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_DENY_STS_SHIFT (0U)
/*! ble_deny_sts - ble_deny_sts interrupt, RIF arbiter has denied BLE packet. */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_DENY_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_DENY_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_DENY_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CUTOFF_STS_MASK (0x2U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CUTOFF_STS_SHIFT (1U)
/*! ble_cutoff_sts - ble_cutoff_sts interrupt, RIF ARB has cut off BLE packet. */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CUTOFF_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CUTOFF_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CUTOFF_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCADENY_STS_MASK (0x4U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCADENY_STS_SHIFT (2U)
/*! ble_bcadeny_sts - ble_bcadeny_sts interrupt, BCA has denied BLE packet. */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCADENY_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCADENY_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCADENY_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCACUTOFF_STS_MASK (0x8U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCACUTOFF_STS_SHIFT (3U)
/*! ble_bcacutoff_sts - ble_bcacutoff_sts interrupt, BCA has cut off BLE packet. */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCACUTOFF_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCACUTOFF_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_BCACUTOFF_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_COR_TIMEOUT_INTR_STS_MASK (0x10U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_COR_TIMEOUT_INTR_STS_SHIFT (4U)
/*! cor_timeout_intr_sts - cor_timeout_intr_sts interrupt, Correlation timeout condition has occurred. */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_COR_TIMEOUT_INTR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_COR_TIMEOUT_INTR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_COR_TIMEOUT_INTR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_RX_SYNC_PULSE_TIMEOUT_INTR_STS_MASK (0x20U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_RX_SYNC_PULSE_TIMEOUT_INTR_STS_SHIFT (5U)
/*! rx_sync_pulse_timeout_intr_sts - rx_sync_pulse_timeout_intr_sts interrupt, Sync timeout condition has occurred. */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_RX_SYNC_PULSE_TIMEOUT_INTR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_RX_SYNC_PULSE_TIMEOUT_INTR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_RX_SYNC_PULSE_TIMEOUT_INTR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_RX_DATAVLD_TIMEOUT_INTR_STS_MASK (0x40U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_RX_DATAVLD_TIMEOUT_INTR_STS_SHIFT (6U)
/*! rx_datavld_timeout_intr_sts - rx_datavld_timeout_intr_sts interrupt, PDU Rx data valid timeout condition has occurred. Bursting Mode only. */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_RX_DATAVLD_TIMEOUT_INTR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_RX_DATAVLD_TIMEOUT_INTR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_RX_DATAVLD_TIMEOUT_INTR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_TXRX_ERROR_STS_MASK (0x80U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_TXRX_ERROR_STS_SHIFT (7U)
/*! txrx_error_sts - txrx_error_sts interrupt, one of tx_lock_fail_intr; rx_lock_fail_intr; or
 *    rx_length_err_intr interrupt has been asserted.
 */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_TXRX_ERROR_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_TXRX_ERROR_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_TXRX_ERROR_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_B4_A2_STS_MASK (0x100U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_B4_A2_STS_SHIFT (8U)
/*! ble_sw_abort_b4_a2_sts - If ble_reg_sw_abort happens during ongoing BLE packet and before dbus A2; ble_sw_abort_b4_a2_sts is issued */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_B4_A2_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_B4_A2_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_B4_A2_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_AFTER_A2_STS_MASK (0x200U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_AFTER_A2_STS_SHIFT (9U)
/*! ble_sw_abort_after_a2_sts - If ble_reg_sw_abort happens while ongoing BLE transaction and after dbus A2; ble_sw_abort_after_a2_sts is issued */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_AFTER_A2_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_AFTER_A2_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_SW_ABORT_AFTER_A2_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_STS_MASK (0x400U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_STS_SHIFT (10U)
/*! ble_cca_abort_sts - When CCA is enabled on TX; and it results in an abort indication from BRF; ble_cca_abort_sts is issued */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_THD_MET_STS_MASK (0x800U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_THD_MET_STS_SHIFT (11U)
/*! ble_cca_abort_thd_met_sts - Aborts on atleast one channel have met or exceeded the programmed threshold value in ble_cca_abort_pkt_cnt_thd */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_THD_MET_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_THD_MET_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_ABORT_THD_MET_STS_MASK)

#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_TXPKT_THD_MET_STS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_TXPKT_THD_MET_STS_SHIFT (12U)
/*! ble_cca_txpkt_thd_met_sts - Total CCA TX packets on atleast one channel have met or exceeded the
 *    programmed threshold value in ble_cca_tx_pkt_cnt_thd
 */
#define BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_TXPKT_THD_MET_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_TXPKT_THD_MET_STS_SHIFT)) & BLE2_REG_BLE_REG_HW_ABORT_STS_BLE_CCA_TXPKT_THD_MET_STS_MASK)
/*! @} */

/*! @name BLE_REG_RT_ERR_STS - BLE Interrupt Status, Real-time Error */
/*! @{ */

#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_CUTOFF_INTR_MASK (0x2U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_CUTOFF_INTR_SHIFT (1U)
/*! ble_cutoff_intr - ble_cutoff_intr real-time interrupt, RIF ARB has cut off BLE packet. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_CUTOFF_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_BLE_CUTOFF_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_BLE_CUTOFF_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_EXTN_FAIL_INTR_MASK (0x4U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_EXTN_FAIL_INTR_SHIFT (2U)
/*! ble_extn_fail_intr - ble_extn_fail_intr real-time interrupt, Interrupt indicateds extension was
 *    not sent or received as expected from the following cases:, 1. Hardware abort condition was
 *    detected during extension., 2. BCA deasserted antSwitchStatus signal; meaning it could not honor
 *    the the antenna switching pattern that BLE had requested.
 */
#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_EXTN_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_BLE_EXTN_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_BLE_EXTN_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_BCACUTOFF_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_BCACUTOFF_INTR_SHIFT (3U)
/*! ble_bcacutoff_intr - ble_bcacutoff_intr real-time interrupt, BCA has cut off BLE packet. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_BLE_BCACUTOFF_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_BLE_BCACUTOFF_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_BLE_BCACUTOFF_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_COR_TIMEOUT_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_COR_TIMEOUT_INTR_SHIFT (4U)
/*! cor_timeout_intr - cor_timeout_intr real-time interrupt, Correlation timeout condition has occurred. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_COR_TIMEOUT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_COR_TIMEOUT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_COR_TIMEOUT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_SYNC_PULSE_TIMEOUT_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_SYNC_PULSE_TIMEOUT_INTR_SHIFT (5U)
/*! rx_sync_pulse_timeout_intr - rx_sync_pulse_timeout_intr real-time interrupt, Sync timeout condition has occurred. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_SYNC_PULSE_TIMEOUT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_SYNC_PULSE_TIMEOUT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_SYNC_PULSE_TIMEOUT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_DATAVLD_TIMEOUT_INTR_MASK (0x40U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_DATAVLD_TIMEOUT_INTR_SHIFT (6U)
/*! rx_datavld_timeout_intr - rx_datavld_timeout_intr real-time interrupt, PDU Rx data valid timeout condition has occurred. Bursting Mode only. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_DATAVLD_TIMEOUT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_DATAVLD_TIMEOUT_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_DATAVLD_TIMEOUT_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ANT_SWITCH_FAIL_STS_MASK (0x100U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ANT_SWITCH_FAIL_STS_SHIFT (8U)
/*! tx_extn_ant_switch_fail_sts - tx_extn_ant_switch_sts interrupt, BCA antSwitchStatus signal deassertion was occurred during extension transmission. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ANT_SWITCH_FAIL_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ANT_SWITCH_FAIL_STS_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ANT_SWITCH_FAIL_STS_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ABORT_STS_MASK (0x200U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ABORT_STS_SHIFT (9U)
/*! tx_extn_abort_sts - tx_extn_abort_sts interrupt, Hardware abort condition other than antenna
 *    switching fail was occurred during extension transmission.
 */
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ABORT_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ABORT_STS_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_TX_EXTN_ABORT_STS_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ANT_SWITCH_FAIL_STS_MASK (0x400U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ANT_SWITCH_FAIL_STS_SHIFT (10U)
/*! rx_extn_ant_switch_fail_sts - rx_extn_ant_switch_sts interrupt, BCA antSwitchStatus signal deassertion was occurred during extension reception. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ANT_SWITCH_FAIL_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ANT_SWITCH_FAIL_STS_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ANT_SWITCH_FAIL_STS_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ABORT_STS_MASK (0x800U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ABORT_STS_SHIFT (11U)
/*! rx_extn_abort_sts - rx_extn_abort_sts interrupt, Hardware abort condition other than antenna
 *    switching fail was occurred during extension reception.
 */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ABORT_STS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ABORT_STS_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_EXTN_ABORT_STS_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_LOCK_FAIL_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_LOCK_FAIL_INTR_SHIFT (16U)
/*! tx_lock_fail_intr - tx_lock_fail_intr interrupt, Transmit lock fail condition. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_LOCK_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_TX_LOCK_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_TX_LOCK_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_DMEM_UNDERFLOW_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_DMEM_UNDERFLOW_INTR_SHIFT (17U)
/*! tx_dmem_underflow_intr - tx_dmem_underflow_intr interrupt, Tx DMA underflow error condition. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_DMEM_UNDERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_TX_DMEM_UNDERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_TX_DMEM_UNDERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_AES_UNDERFLOW_INTR_MASK (0x40000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_AES_UNDERFLOW_INTR_SHIFT (18U)
/*! tx_aes_underflow_intr - tx_aes_underflow_intr interrupt, Tx AES underflow error condition. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_TX_AES_UNDERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_TX_AES_UNDERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_TX_AES_UNDERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_LOCK_FAIL_INTR_MASK (0x100000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_LOCK_FAIL_INTR_SHIFT (20U)
/*! rx_lock_fail_intr - rx_lock_fail_intr interrupt, Receive lock fail condition */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_LOCK_FAIL_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_LOCK_FAIL_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_LOCK_FAIL_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_DMEM_OVERFLOW_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_DMEM_OVERFLOW_INTR_SHIFT (21U)
/*! rx_dmem_overflow_intr - rx_dmem_overflow_intr interrupt, Rx DMA overflow error condition. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_DMEM_OVERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_DMEM_OVERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_DMEM_OVERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_AES_UNDERFLOW_INTR_MASK (0x400000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_AES_UNDERFLOW_INTR_SHIFT (22U)
/*! rx_aes_underflow_intr - rx_aes_underflow_intr interrupt, Rx AES underflow error condition. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_AES_UNDERFLOW_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_AES_UNDERFLOW_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_AES_UNDERFLOW_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_LENGTH_ERR_INTR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_LENGTH_ERR_INTR_SHIFT (23U)
/*! rx_length_err_intr - rx_length_err_intr interrupt, Received packet length error condition. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_RX_LENGTH_ERR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_RX_LENGTH_ERR_INTR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_RX_LENGTH_ERR_INTR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_AHB_ERROR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_AHB_ERROR_SHIFT (24U)
/*! ahb_error - ahb_error interrupt, SoC AHB slave has replied ERROR response during BLE AHB master transfer. */
#define BLE2_REG_BLE_REG_RT_ERR_STS_AHB_ERROR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_AHB_ERROR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_AHB_ERROR_MASK)

#define BLE2_REG_BLE_REG_RT_ERR_STS_DMA_ERROR_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_RT_ERR_STS_DMA_ERROR_SHIFT (25U)
/*! dma_error - dma_error interrupt, BLE AHB master error condition (startDmaError; gbBeError). */
#define BLE2_REG_BLE_REG_RT_ERR_STS_DMA_ERROR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RT_ERR_STS_DMA_ERROR_SHIFT)) & BLE2_REG_BLE_REG_RT_ERR_STS_DMA_ERROR_MASK)
/*! @} */

/*! @name BLE_REG_INT_CFG_01 - BLE Interrupt Configuration */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_CFG_01_RT_ERR_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_CFG_01_RT_ERR_INTR_SHIFT (0U)
/*! rt_err_intr - rt_err_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_RT_ERR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_RT_ERR_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_RT_ERR_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_PST_2_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_INT_CFG_01_PST_2_INTR_SHIFT (3U)
/*! pst_2_intr - pst_2_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_PST_2_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_PST_2_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_PST_2_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_PST_1_INTR_MASK (0x10U)
#define BLE2_REG_BLE_REG_INT_CFG_01_PST_1_INTR_SHIFT (4U)
/*! pst_1_intr - pst_1_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_PST_1_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_PST_1_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_PST_1_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_PST_0_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_INT_CFG_01_PST_0_INTR_SHIFT (5U)
/*! pst_0_intr - pst_0_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_PST_0_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_PST_0_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_PST_0_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_5_MASK (0x40U)
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_5_SHIFT (6U)
/*! cdt_expiry_intr_5 - cdt_expiry_intr[5] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_5(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_5_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_5_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_4_MASK (0x80U)
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_4_SHIFT (7U)
/*! cdt_expiry_intr_4 - cdt_expiry_intr[4] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_4(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_4_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_4_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_3_MASK (0x100U)
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_3_SHIFT (8U)
/*! cdt_expiry_intr_3 - cdt_expiry_intr[3] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_2_MASK (0x200U)
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_2_SHIFT (9U)
/*! cdt_expiry_intr_2 - cdt_expiry_intr[2] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_1_MASK (0x400U)
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_1_SHIFT (10U)
/*! cdt_expiry_intr_1 - cdt_expiry_intr[1] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_0_MASK (0x800U)
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_0_SHIFT (11U)
/*! cdt_expiry_intr_0 - cdt_expiry_intr[0] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_CDT_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_3_MASK (0x1000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_3_SHIFT (12U)
/*! expiry_intr_3 - expiry_intr[3] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_3_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_3_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_2_MASK (0x2000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_2_SHIFT (13U)
/*! expiry_intr_2 - expiry_intr[2] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_2_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_2_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_1_MASK (0x4000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_1_SHIFT (14U)
/*! expiry_intr_1 - expiry_intr[1] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_1_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_1_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_0_MASK (0x8000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_0_SHIFT (15U)
/*! expiry_intr_0 - expiry_intr[0] interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_0_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_EXPIRY_INTR_0_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_TMR_ABORT_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_TMR_ABORT_INTR_SHIFT (16U)
/*! tmr_abort_intr - tmr_abort_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_TMR_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_TMR_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_TMR_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_HW_ABORT_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_HW_ABORT_INTR_SHIFT (17U)
/*! hw_abort_intr - hw_abort_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_HW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_HW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_HW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_SW_ABORT_INTR_MASK (0x40000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_SW_ABORT_INTR_SHIFT (18U)
/*! sw_abort_intr - sw_abort_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_SW_ABORT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_SW_ABORT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_SW_ABORT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_RX_PKT_DONE_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_PKT_DONE_INTR_SHIFT (21U)
/*! rx_pkt_done_intr - rx_pkt_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_RX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_RX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_RX_DATA_DONE_INTR_MASK (0x400000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_DATA_DONE_INTR_SHIFT (22U)
/*! rx_data_done_intr - rx_data_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_RX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_RX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_EXT_HEADER_DONE_INTR_MASK (0x800000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT (23U)
/*! rx_adv_ext_header_done_intr - rx_adv_ext_header_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_EXT_HEADER_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_EXT_HEADER_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_EXT_HEADER_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_IRK_RESOLVE_DONE_INTR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_IRK_RESOLVE_DONE_INTR_SHIFT (24U)
/*! irk_resolve_done_intr - irk_resolve_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_IRK_RESOLVE_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_IRK_RESOLVE_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_IRK_RESOLVE_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_ADDR_DONE_INTR_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_ADDR_DONE_INTR_SHIFT (25U)
/*! rx_adv_addr_done_intr - rx_adv_addr_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_ADDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_ADDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_RX_ADV_ADDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_RX_HDR_DONE_INTR_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_HDR_DONE_INTR_SHIFT (26U)
/*! rx_hdr_done_intr - rx_hdr_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_RX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_RX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_RX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_COR_HIT_INTR_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_COR_HIT_INTR_SHIFT (27U)
/*! cor_hit_intr - cor_hit_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_COR_HIT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_COR_HIT_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_COR_HIT_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_TX_PKT_DONE_INTR_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_PKT_DONE_INTR_SHIFT (28U)
/*! tx_pkt_done_intr - tx_pkt_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_TX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_TX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_TX_DATA_DONE_INTR_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_DATA_DONE_INTR_SHIFT (29U)
/*! tx_data_done_intr - tx_data_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_DATA_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_TX_DATA_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_TX_DATA_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_TX_HDR_DONE_INTR_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_HDR_DONE_INTR_SHIFT (30U)
/*! tx_hdr_done_intr - tx_hdr_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_HDR_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_TX_HDR_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_TX_HDR_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_CFG_01_TX_ACC_DONE_INTR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_ACC_DONE_INTR_SHIFT (31U)
/*! tx_acc_done_intr - tx_acc_done_intr interrupt configuration, 0x0: route to BLE_REG_INT_STS_0, 0x1: route to BLE_REG_INT_STS_1
 *  0b0..route to BLE_REG_INT_STS_0
 *  0b1..route to BLE_REG_INT_STS_1
 */
#define BLE2_REG_BLE_REG_INT_CFG_01_TX_ACC_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_CFG_01_TX_ACC_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_CFG_01_TX_ACC_DONE_INTR_MASK)
/*! @} */

/*! @name BLE_REG_INT_DELAY_CTRL_01 - BLE Interrupt Delay Control */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_RX_PKT_DONE_INTR_MASK (0x200000U)
#define BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_RX_PKT_DONE_INTR_SHIFT (21U)
/*! rx_pkt_done_intr - delay rx_pkt_done_intr interrupt assertion, 0x0: no delay, 0x1: delay
 *    interrupt assertion until DMA is done writing timestamp and status fields, into RD.
 *  0b0..no delay
 *  0b1..delay interrupt assertion until DMA is done writing timestamp and status fields into RD.
 */
#define BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_RX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_RX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_RX_PKT_DONE_INTR_MASK)

#define BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_TX_PKT_DONE_INTR_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_TX_PKT_DONE_INTR_SHIFT (28U)
/*! tx_pkt_done_intr - delay tx_pkt_done_intr interrupt assertion, 0x0: no delay, 0x1: delay
 *    interrupt assertion until DMA is done writing timestamp and status fields, into TD.
 *  0b0..no delay
 *  0b1..delay interrupt assertion until DMA is done writing timestamp and status fields into TD.
 */
#define BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_TX_PKT_DONE_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_TX_PKT_DONE_INTR_SHIFT)) & BLE2_REG_BLE_REG_INT_DELAY_CTRL_01_TX_PKT_DONE_INTR_MASK)
/*! @} */

/*! @name BLE_REG_INT_SW_MBOX - Software Mailbox Interrupt */
/*! @{ */

#define BLE2_REG_BLE_REG_INT_SW_MBOX_SW_MBOX_MASK (0x1U)
#define BLE2_REG_BLE_REG_INT_SW_MBOX_SW_MBOX_SHIFT (0U)
/*! sw_mbox - software Mailbox Interrupt, Writing 1 to cause sw_mailbox_intr interrupt to be
 *    generated. This bit is self-cleared by hardware.
 */
#define BLE2_REG_BLE_REG_INT_SW_MBOX_SW_MBOX(x)  (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_INT_SW_MBOX_SW_MBOX_SHIFT)) & BLE2_REG_BLE_REG_INT_SW_MBOX_SW_MBOX_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_CTL_0 - Software Timer 0: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_TIMER_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_TIMER_EN_SHIFT (0U)
/*! timer_en - Set Timer Enable, This bit is self clearing by hardware after timer expires., 0x0: disable timer, 0x1: enable timer
 *  0b0..disable timer
 *  0b1..enable timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_TIMER_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_TIMER_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_TIMER_EN_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_INTR_SHIFT (3U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_ABORT_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_ABORT_SHIFT (4U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for Abort, 0x0: no event, 0x1: Tx/Rx abort triggered at expiry of timer
 *  0b0..no event
 *  0b1..Tx/Rx abort triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_CS_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_CS_SHIFT (5U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY, 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_SLOT_MASK_MASK (0xC0U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_SLOT_MASK_SHIFT (6U)
/*! slot_mask - Slot Mask, This register is a 2 bit LSB mask on the clock comparator. If both bits
 *    are cleared; then the events will assert regardless of the matching state of the LSB bits.,
 *    frame,0x0: timer works on frame basis, 0x1: invalid, slot,0x2: timer works on slot basis,
 *    halfslot,0x3: timer works on half slot basis
 *  0b00..timer works on frame basis
 *  0b01..invalid
 *  0b10..timer works on slot basis
 *  0b11..timer works on half slot basis
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_SLOT_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_SLOT_MASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_SLOT_MASK_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_ALLOW_CURRENT_EXPIRY_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_ALLOW_CURRENT_EXPIRY_SHIFT (31U)
/*! allow_current_expiry - Allow current SWT expiry with chained CDT; for CDT Matching mode, SWT
 *    configuration for new CDT chaining mode. SWT programming with current native clock values would
 *    be considered valid; past expiry_status won't be set. SWT expiry events like TX; RX; HW Abort;
 *    and CS still cannot be triggered if programming time half slot is <= current native clock. SWT
 *    interrupt will also not get generated at such values (since it is too late). Added for
 *    KFOURWONE-2451, 0x0: SWT is configured in original mode where current native clock value is,
 *    considered to be in the past, 0x1: SWT is configured in new CDT matching mode where current native
 *    clock value is, allowed to trigger chained CDTs
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_0_ALLOW_CURRENT_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_0_ALLOW_CURRENT_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_0_ALLOW_CURRENT_EXPIRY_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_VALUE_0 - Software Timer 0: Expiration Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_0_EXPIRY_VALUE_MASK (0xFFFFFFFU)
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_0_EXPIRY_VALUE_SHIFT (0U)
/*! expiry_value - Expiry Value, Bluetooth native clock value for event generation. When the
 *    Bluetooth native clock equals this value; the events are triggered.
 */
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_0_EXPIRY_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_VALUE_0_EXPIRY_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_VALUE_0_EXPIRY_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_STS_0 - Software Timer 0: Expiration Status */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_EXPIRY_STATUS_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_EXPIRY_STATUS_SHIFT (0U)
/*! expiry_status - Expiry Status, This bit is updated at each expiry. Once set it remains set until
 *    this SWT expires again. For the purpose of this register; past value on SWT refers to a value
 *    up to 12 hours before the current BTC native clock value., 0x0: SWT expired at programmed
 *    value without any errors, 0x1: SWT was programmed for a value that is in the past
 *  0b0..SWT expired at programmed value without any errors
 *  0b1..SWT was programmed for a value that is in the past
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_EXPIRY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_0_EXPIRY_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_0_EXPIRY_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_SKIP_STATUS_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_SKIP_STATUS_SHIFT (1U)
/*! skip_status - Clock skipping Status, This bit is updated each time the LPO version of
 *    nativeClock skips any number of values AND a previously programmed timer expiry got skipped. This is
 *    likely to happen only when BTC is entering sleep state when the LPO version of native clock MAY
 *    be updated with the most accurate value., 0x0: SWT expired at programmed value without any
 *    skipping error, 0x1: Current timer expiry is due to clock skipping over the programmed expiration,
 *    value
 *  0b0..SWT expired at programmed value without any skipping error
 *  0b1..Current timer expiry is due to clock skipping over the programmed expiration value
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_SKIP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_0_SKIP_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_0_SKIP_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_SWT_CONF_VALID_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_SWT_CONF_VALID_SHIFT (2U)
/*! swt_conf_valid - SWT Configuration Valid Indication, Indicates when SWT configurations are
 *    registered into sleep clock domain Bit is set when configurations are registered in slow domain and
 *    reset at SWT expiry; for both successful expiry as well as past value expiry, 0x0: SWT
 *    configuration is not registered into slow clock domain yet, 0x1: SWT configuration is safely
 *    registered into slow clock domain
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_0_SWT_CONF_VALID(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_0_SWT_CONF_VALID_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_0_SWT_CONF_VALID_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_CTL_1 - Software Timer 1: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_TIMER_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_TIMER_EN_SHIFT (0U)
/*! timer_en - Set Timer Enable, This bit is self clearing by hardware after timer expires., 0x0: disable timer, 0x1: enable timer
 *  0b0..disable timer
 *  0b1..enable timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_TIMER_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_TIMER_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_TIMER_EN_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_INTR_SHIFT (3U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_ABORT_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_ABORT_SHIFT (4U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for Abort, 0x0: no event, 0x1: Tx/Rx abort triggered at expiry of timer
 *  0b0..no event
 *  0b1..Tx/Rx abort triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_CS_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_CS_SHIFT (5U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY, 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_SLOT_MASK_MASK (0xC0U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_SLOT_MASK_SHIFT (6U)
/*! slot_mask - Slot Mask, This register is a 2 bit LSB mask on the clock comparator. If both bits
 *    are cleared; then the events will assert regardless of the matching state of the LSB bits.,
 *    frame,0x0: timer works on frame basis, 0x1: invalid, slot,0x2: timer works on slot basis,
 *    halfslot,0x3: timer works on half slot basis
 *  0b00..timer works on frame basis
 *  0b01..invalid
 *  0b10..timer works on slot basis
 *  0b11..timer works on half slot basis
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_SLOT_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_SLOT_MASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_SLOT_MASK_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_ALLOW_CURRENT_EXPIRY_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_ALLOW_CURRENT_EXPIRY_SHIFT (31U)
/*! allow_current_expiry - Allow current SWT expiry with chained CDT; for CDT Matching mode, SWT
 *    configuration for new CDT chaining mode. SWT programming with current native clock values would
 *    be considered valid; past expiry_status won't be set. SWT expiry events like TX; RX; HW Abort;
 *    and CS still cannot be triggered if programming time half slot is <= current native clock. SWT
 *    interrupt will also not get generated at such values (since it is too late). Added for
 *    KFOURWONE-2451, 0x0: SWT is configured in original mode where current native clock value is,
 *    considered to be in the past, 0x1: SWT is configured in new CDT matching mode where current native
 *    clock value is, allowed to trigger chained CDTs
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_1_ALLOW_CURRENT_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_1_ALLOW_CURRENT_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_1_ALLOW_CURRENT_EXPIRY_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_VALUE_1 - Software Timer 1: Expiration Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_1_EXPIRY_VALUE_MASK (0xFFFFFFFU)
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_1_EXPIRY_VALUE_SHIFT (0U)
/*! expiry_value - Expiry Value, Bluetooth native clock value for event generation. When the
 *    Bluetooth native clock equals this value; the events are triggered.
 */
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_1_EXPIRY_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_VALUE_1_EXPIRY_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_VALUE_1_EXPIRY_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_STS_1 - Software Timer 1: Expiration Status */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_EXPIRY_STATUS_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_EXPIRY_STATUS_SHIFT (0U)
/*! expiry_status - Expiry Status, This bit is updated at each expiry. Once set it remains set until
 *    this SWT expires again. For the purpose of this register; past value on SWT refers to a value
 *    up to 12 hours before the current BTC native clock value., 0x0: SWT expired at programmed
 *    value without any errors, 0x1: SWT was programmed for a value that is in the past
 *  0b0..SWT expired at programmed value without any errors
 *  0b1..SWT was programmed for a value that is in the past
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_EXPIRY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_1_EXPIRY_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_1_EXPIRY_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_SKIP_STATUS_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_SKIP_STATUS_SHIFT (1U)
/*! skip_status - Clock skipping Status, This bit is updated each time the LPO version of
 *    nativeClock skips any number of values AND a previously programmed timer expiry got skipped. This is
 *    likely to happen only when BTC is entering sleep state when the LPO version of native clock MAY
 *    be updated with the most accurate value., 0x0: SWT expired at programmed value without any
 *    skipping error, 0x1: Current timer expiry is due to clock skipping over the programmed expiration,
 *    value
 *  0b0..SWT expired at programmed value without any skipping error
 *  0b1..Current timer expiry is due to clock skipping over the programmed expiration value
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_SKIP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_1_SKIP_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_1_SKIP_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_SWT_CONF_VALID_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_SWT_CONF_VALID_SHIFT (2U)
/*! swt_conf_valid - SWT Configuration Valid Indication, Indicates when SWT configurations are
 *    registered into sleep clock domain Bit is set when configurations are registered in slow domain and
 *    reset at SWT expiry; for both successful expiry as well as past value expiry, 0x0: SWT
 *    configuration is not registered into slow clock domain yet, 0x1: SWT configuration is safely
 *    registered into slow clock domain
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_1_SWT_CONF_VALID(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_1_SWT_CONF_VALID_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_1_SWT_CONF_VALID_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_CTL_2 - Software Timer 2: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_TIMER_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_TIMER_EN_SHIFT (0U)
/*! timer_en - Set Timer Enable, This bit is self clearing by hardware after timer expires., 0x0: disable timer, 0x1: enable timer
 *  0b0..disable timer
 *  0b1..enable timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_TIMER_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_TIMER_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_TIMER_EN_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_INTR_SHIFT (3U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_ABORT_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_ABORT_SHIFT (4U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for Abort, 0x0: no event, 0x1: Tx/Rx abort triggered at expiry of timer
 *  0b0..no event
 *  0b1..Tx/Rx abort triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_CS_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_CS_SHIFT (5U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY, 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_SLOT_MASK_MASK (0xC0U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_SLOT_MASK_SHIFT (6U)
/*! slot_mask - Slot Mask, This register is a 2 bit LSB mask on the clock comparator. If both bits
 *    are cleared; then the events will assert regardless of the matching state of the LSB bits.,
 *    frame,0x0: timer works on frame basis, 0x1: invalid, slot,0x2: timer works on slot basis,
 *    halfslot,0x3: timer works on half slot basis
 *  0b00..timer works on frame basis
 *  0b01..invalid
 *  0b10..timer works on slot basis
 *  0b11..timer works on half slot basis
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_SLOT_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_SLOT_MASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_SLOT_MASK_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_ALLOW_CURRENT_EXPIRY_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_ALLOW_CURRENT_EXPIRY_SHIFT (31U)
/*! allow_current_expiry - Allow current SWT expiry with chained CDT; for CDT Matching mode, SWT
 *    configuration for new CDT chaining mode. SWT programming with current native clock values would
 *    be considered valid; past expiry_status won't be set. SWT expiry events like TX; RX; HW Abort;
 *    and CS still cannot be triggered if programming time half slot is <= current native clock. SWT
 *    interrupt will also not get generated at such values (since it is too late). Added for
 *    KFOURWONE-2451, 0x0: SWT is configured in original mode where current native clock value is,
 *    considered to be in the past, 0x1: SWT is configured in new CDT matching mode where current native
 *    clock value is, allowed to trigger chained CDTs
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_2_ALLOW_CURRENT_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_2_ALLOW_CURRENT_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_2_ALLOW_CURRENT_EXPIRY_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_VALUE_2 - Software Timer 2: Expiration Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_2_EXPIRY_VALUE_MASK (0xFFFFFFFU)
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_2_EXPIRY_VALUE_SHIFT (0U)
/*! expiry_value - Expiry Value, Bluetooth native clock value for event generation. When the
 *    Bluetooth native clock equals this value; the events are triggered.
 */
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_2_EXPIRY_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_VALUE_2_EXPIRY_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_VALUE_2_EXPIRY_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_STS_2 - Software Timer 2: Expiration Status */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_EXPIRY_STATUS_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_EXPIRY_STATUS_SHIFT (0U)
/*! expiry_status - Expiry Status, This bit is updated at each expiry. Once set it remains set until
 *    this SWT expires again. For the purpose of this register; past value on SWT refers to a value
 *    up to 12 hours before the current BTC native clock value., 0x0: SWT expired at programmed
 *    value without any errors, 0x1: SWT was programmed for a value that is in the past
 *  0b0..SWT expired at programmed value without any errors
 *  0b1..SWT was programmed for a value that is in the past
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_EXPIRY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_2_EXPIRY_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_2_EXPIRY_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_SKIP_STATUS_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_SKIP_STATUS_SHIFT (1U)
/*! skip_status - Clock skipping Status, This bit is updated each time the LPO version of
 *    nativeClock skips any number of values AND a previously programmed timer expiry got skipped. This is
 *    likely to happen only when BTC is entering sleep state when the LPO version of native clock MAY
 *    be updated with the most accurate value., 0x0: SWT expired at programmed value without any
 *    skipping error, 0x1: Current timer expiry is due to clock skipping over the programmed expiration,
 *    value
 *  0b0..SWT expired at programmed value without any skipping error
 *  0b1..Current timer expiry is due to clock skipping over the programmed expiration value
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_SKIP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_2_SKIP_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_2_SKIP_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_SWT_CONF_VALID_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_SWT_CONF_VALID_SHIFT (2U)
/*! swt_conf_valid - SWT Configuration Valid Indication, Indicates when SWT configurations are
 *    registered into sleep clock domain Bit is set when configurations are registered in slow domain and
 *    reset at SWT expiry; for both successful expiry as well as past value expiry, 0x0: SWT
 *    configuration is not registered into slow clock domain yet, 0x1: SWT configuration is safely
 *    registered into slow clock domain
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_2_SWT_CONF_VALID(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_2_SWT_CONF_VALID_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_2_SWT_CONF_VALID_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_CTL_3 - Software Timer 3: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_TIMER_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_TIMER_EN_SHIFT (0U)
/*! timer_en - Set Timer Enable, This bit is self clearing by hardware after timer expires., 0x0: disable timer, 0x1: enable timer
 *  0b0..disable timer
 *  0b1..enable timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_TIMER_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_TIMER_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_TIMER_EN_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_INTR_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_INTR_SHIFT (3U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_ABORT_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_ABORT_SHIFT (4U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for Abort, 0x0: no event, 0x1: Tx/Rx abort triggered at expiry of timer
 *  0b0..no event
 *  0b1..Tx/Rx abort triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_CS_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_CS_SHIFT (5U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY, 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_SLOT_MASK_MASK (0xC0U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_SLOT_MASK_SHIFT (6U)
/*! slot_mask - Slot Mask, This register is a 2 bit LSB mask on the clock comparator. If both bits
 *    are cleared; then the events will assert regardless of the matching state of the LSB bits.,
 *    frame,0x0: timer works on frame basis, 0x1: invalid, slot,0x2: timer works on slot basis,
 *    halfslot,0x3: timer works on half slot basis
 *  0b00..timer works on frame basis
 *  0b01..invalid
 *  0b10..timer works on slot basis
 *  0b11..timer works on half slot basis
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_SLOT_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_SLOT_MASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_SLOT_MASK_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_ALLOW_CURRENT_EXPIRY_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_ALLOW_CURRENT_EXPIRY_SHIFT (31U)
/*! allow_current_expiry - Allow current SWT expiry with chained CDT; for CDT Matching mode, SWT
 *    configuration for new CDT chaining mode. SWT programming with current native clock values would
 *    be considered valid; past expiry_status won't be set. SWT expiry events like TX; RX; HW Abort;
 *    and CS still cannot be triggered if programming time half slot is <= current native clock. SWT
 *    interrupt will also not get generated at such values (since it is too late). Added for
 *    KFOURWONE-2451, 0x0: SWT is configured in original mode where current native clock value is,
 *    considered to be in the past, 0x1: SWT is configured in new CDT matching mode where current native
 *    clock value is, allowed to trigger chained CDTs
 */
#define BLE2_REG_BLE_REG_TMR_SWT_CTL_3_ALLOW_CURRENT_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_CTL_3_ALLOW_CURRENT_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_CTL_3_ALLOW_CURRENT_EXPIRY_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_VALUE_3 - Software Timer 3: Expiration Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_3_EXPIRY_VALUE_MASK (0xFFFFFFFU)
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_3_EXPIRY_VALUE_SHIFT (0U)
/*! expiry_value - Expiry Value, Bluetooth native clock value for event generation. When the
 *    Bluetooth native clock equals this value; the events are triggered.
 */
#define BLE2_REG_BLE_REG_TMR_SWT_VALUE_3_EXPIRY_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_VALUE_3_EXPIRY_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_VALUE_3_EXPIRY_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_SWT_STS_3 - Software Timer 3: Expiration Status */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_EXPIRY_STATUS_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_EXPIRY_STATUS_SHIFT (0U)
/*! expiry_status - Expiry Status, This bit is updated at each expiry. Once set it remains set until
 *    this SWT expires again. For the purpose of this register; past value on SWT refers to a value
 *    up to 12 hours before the current BTC native clock value., 0x0: SWT expired at programmed
 *    value without any errors, 0x1: SWT was programmed for a value that is in the past
 *  0b0..SWT expired at programmed value without any errors
 *  0b1..SWT was programmed for a value that is in the past
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_EXPIRY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_3_EXPIRY_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_3_EXPIRY_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_SKIP_STATUS_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_SKIP_STATUS_SHIFT (1U)
/*! skip_status - Clock skipping Status, This bit is updated each time the LPO version of
 *    nativeClock skips any number of values AND a previously programmed timer expiry got skipped. This is
 *    likely to happen only when BTC is entering sleep state when the LPO version of native clock MAY
 *    be updated with the most accurate value., 0x0: SWT expired at programmed value without any
 *    skipping error, 0x1: Current timer expiry is due to clock skipping over the programmed expiration,
 *    value
 *  0b0..SWT expired at programmed value without any skipping error
 *  0b1..Current timer expiry is due to clock skipping over the programmed expiration value
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_SKIP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_3_SKIP_STATUS_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_3_SKIP_STATUS_MASK)

#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_SWT_CONF_VALID_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_SWT_CONF_VALID_SHIFT (2U)
/*! swt_conf_valid - SWT Configuration Valid Indication, Indicates when SWT configurations are
 *    registered into sleep clock domain Bit is set when configurations are registered in slow domain and
 *    reset at SWT expiry; for both successful expiry as well as past value expiry, 0x0: SWT
 *    configuration is not registered into slow clock domain yet, 0x1: SWT configuration is safely
 *    registered into slow clock domain
 */
#define BLE2_REG_BLE_REG_TMR_SWT_STS_3_SWT_CONF_VALID(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_SWT_STS_3_SWT_CONF_VALID_SHIFT)) & BLE2_REG_BLE_REG_TMR_SWT_STS_3_SWT_CONF_VALID_MASK)
/*! @} */

/*! @name BLE_REG_TMR_NATIVE_QUS - Native quarter microsecond counter Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SLEEP_MASK (0x1FFFU)  /* Merged from fields with different position or width, of widths (11, 13), largest definition used */
#define BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SLEEP_SHIFT (0U)
/*! nat_clock_sleep - Native quarter microsecond counter Value, This is the quarter miscrosecond
 *    timer for FW to read back. The value normally is between 0 to 1249; but it may overflow from this
 *    range in sleep mode. This is a read-only register.
 */
#define BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SLEEP_SHIFT)) & BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SLEEP_MASK)  /* Merged from fields with different position or width, of widths (11, 13), largest definition used */

#define BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SYS_VALID_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SYS_VALID_SHIFT (31U)
/*! nat_clock_sys_valid - Status bit for Native Clock Value after wakeup , This status bit indicates
 *    that the Bluetooth native clock value in BLE_REG_TMR_NATIVE_CLOCK is a valid value after
 *    wakeup from SLEEP. SW may read this status bit to confirm that the native clock value read
 *    immediately after wakeup is not a stale value. Reset value is zero. This status is set to 0x1
 *    whenever sleep clock value is captured in sysclk. Reset to 0x0 during SLEEP entry as soon as
 *    ble_clk_req de-asserts indcating a stale value in BLE_REG_TMR_NATIVE_CLOCK.
 */
#define BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SYS_VALID(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SYS_VALID_SHIFT)) & BLE2_REG_BLE_REG_TMR_NATIVE_QUS_NAT_CLOCK_SYS_VALID_MASK)
/*! @} */

/*! @name BLE_REG_TMR_NATIVE_CLOCK - Native mcClock Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_NATIVE_CLOCK_NAT_CLOCK_SLEEP_MASK (0xFFFFFFFFU)
#define BLE2_REG_BLE_REG_TMR_NATIVE_CLOCK_NAT_CLOCK_SLEEP_SHIFT (0U)
/*! nat_clock_sleep - Native Clock Value, Bluetooth native clock value used for timer comparison.
 *    This is the sleep clock version of the Bluetooth native clock. To read-verify after a write; it
 *    takes at least 2 sleep clock cycles for the write value to return.
 */
#define BLE2_REG_BLE_REG_TMR_NATIVE_CLOCK_NAT_CLOCK_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_NATIVE_CLOCK_NAT_CLOCK_SLEEP_SHIFT)) & BLE2_REG_BLE_REG_TMR_NATIVE_CLOCK_NAT_CLOCK_SLEEP_MASK)
/*! @} */

/*! @name BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES - Wakeup delay value in LPO cycles */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES_WAKEUP_DELAY_LPO_CYCLES_MASK (0x3FU)
#define BLE2_REG_BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES_WAKEUP_DELAY_LPO_CYCLES_SHIFT (0U)
/*! wakeup_delay_lpo_cycles - Wakeup delay in LPO cycles, Number of LPO (sleep clock) cycles from
 *    btu_clk_req assertion until the clocks are stable. The minimum recommended value is 2
 */
#define BLE2_REG_BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES_WAKEUP_DELAY_LPO_CYCLES(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES_WAKEUP_DELAY_LPO_CYCLES_SHIFT)) & BLE2_REG_BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES_WAKEUP_DELAY_LPO_CYCLES_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CLOCK_SKIP - Native Clock Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CLOCK_SKIP_OLD_NATIVE_CLOCK_MASK (0xFFU)
#define BLE2_REG_BLE_REG_TMR_CLOCK_SKIP_OLD_NATIVE_CLOCK_SHIFT (0U)
/*! old_native_clock - Native Clock Value (before skip), Bluetooth native clock value before the
 *    clock skip was observed. The value after skip can be read in the BLE_REG_TMR_NATIVE_CLOCK
 *    register.
 */
#define BLE2_REG_BLE_REG_TMR_CLOCK_SKIP_OLD_NATIVE_CLOCK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CLOCK_SKIP_OLD_NATIVE_CLOCK_SHIFT)) & BLE2_REG_BLE_REG_TMR_CLOCK_SKIP_OLD_NATIVE_CLOCK_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CTL_0 - Qus Count Down Timer 0: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_INTR_SHIFT (0U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_ABORT_SHIFT (3U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for triggering an Abort from
 *    software., 0x0: no event, 0x1: Abort triggered at timer expiry
 *  0b0..no event
 *  0b1..Abort triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXSTART_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXSTART_SHIFT (4U)
/*! start_emask_ble_txstart - Event Mask: BLE Tx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Tx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXSTART_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXSTART_SHIFT (5U)
/*! start_emask_ble_rxstart - Event Mask: BLE Rx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Rx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXEND_MASK (0x40U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXEND_SHIFT (6U)
/*! start_emask_ble_txend - Event Mask: BLE Tx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Tx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_TXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXEND_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXEND_SHIFT (7U)
/*! start_emask_ble_rxend - Event Mask: BLE Rx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Rx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_RXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BTC_PKTEND_MASK (0x100U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BTC_PKTEND_SHIFT (8U)
/*! start_emask_btc_pktend - Event Mask: BTC PKT end, Start Event Mask for triggering the CDT
 *    counter. Start counting at the end of a BTC Tx or Rx transaction., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at end of next BTC packet (Tx, or Rx) transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BTC packet (Tx or Rx) transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BTC_PKTEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BTC_PKTEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BTC_PKTEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRHIT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRHIT_SHIFT (9U)
/*! start_emask_ble_corrhit - Event Mask: BLE CORR hit, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation hit., 0x0: no event, 0x1: timer starts counting down
 *    from programmed value at next BLE correlation hit
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation hit
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRHIT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRHIT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRHIT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_ASSERT_MASK (0x400U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_ASSERT_SHIFT (10U)
/*! start_emask_bca_req_assert - Event Mask: BCA request assertion, Start Event Mask for triggering
 *    the CDT counter. Start counting at BCA request assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_ASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_ASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_DEASSERT_MASK (0x800U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_DEASSERT_SHIFT (11U)
/*! start_emask_bca_req_deassert - Event Mask: BCA request deassertion, Start Event Mask for
 *    triggering the CDT counter. Start counting at BCA_req de-assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req de-assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req de-assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_DEASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_DEASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BCA_REQ_DEASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRMISS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRMISS_SHIFT (12U)
/*! start_emask_ble_corrmiss - Event Mask: BLE CORR miss, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation timeout interrupt., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BLE correlation miss
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation miss
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRMISS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRMISS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CORRMISS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_SW_TRIGGER_MASK (0x2000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_SW_TRIGGER_SHIFT (13U)
/*! start_emask_sw_trigger - Event Mask: Software trigger, Start Event Mask for triggering the CDT
 *    counter. Start counting when the firmware sets this bit. This bit is self clearing., 0x0: no
 *    event, 0x1: timer starts counting down from the programmed value as soon as this bit is set
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value as soon as this bit is set
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_SW_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_SW_TRIGGER_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_SW_TRIGGER_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_HW_ABORT_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_HW_ABORT_SHIFT (14U)
/*! start_emask_hw_abort - Event Mask: Hardware abort, Start Event Mask for triggering the CDT
 *    counter. Start counting when hardware abort occurs. The abort may be for a transmit packet or a
 *    receive packet., 0x0: no event, 0x1: timer starts counting down from the programmed value bit
 *    when hardware abort, happens
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value bit when hardware abort happens
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_HW_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_HW_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_HW_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_VALUE_RESET_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_VALUE_RESET_SHIFT (15U)
/*! cdt_value_reset - CDT value reset, This bit resets the CDT counter to 0. It will not trigger any
 *    expiry conditions (if programmed). This bit is self clearing, 0x0: no event, 0x1: Timer is
 *    reset to 0 immediately
 *  0b0..no event
 *  0b1..Timer is reset to 0 immediately
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_VALUE_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_VALUE_RESET_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_VALUE_RESET_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT0_EXPIRY_MASK (0x10000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT0_EXPIRY_SHIFT (16U)
/*! start_emask_ble_cdt0_expiry - Event Mask: Chain with CDT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT0 expires. This will chain the current CDT with CDT0., 0x0:
 *    no event, 0x1: timer starts counting down when CDT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT1_EXPIRY_MASK (0x20000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT1_EXPIRY_SHIFT (17U)
/*! start_emask_ble_cdt1_expiry - Event Mask: Chain with CDT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT1 expires. This will chain the current CDT with CDT1., 0x0:
 *    no event, 0x1: timer starts counting down when CDT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT2_EXPIRY_MASK (0x40000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT2_EXPIRY_SHIFT (18U)
/*! start_emask_ble_cdt2_expiry - Event Mask: Chain with CDT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT2 expires. This will chain the current CDT with CDT2., 0x0:
 *    no event, 0x1: timer starts counting down when CDT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT3_EXPIRY_MASK (0x80000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT3_EXPIRY_SHIFT (19U)
/*! start_emask_ble_cdt3_expiry - Event Mask: Chain with CDT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT3 expires. This will chain the current CDT with CDT3., 0x0:
 *    No event, 0x1: timer starts counting down when CDT3 expires
 *  0b0..No event
 *  0b1..timer starts counting down when CDT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT4_EXPIRY_MASK (0x100000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT4_EXPIRY_SHIFT (20U)
/*! start_emask_ble_cdt4_expiry - Event Mask: Chain with CDT4, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT4 expires. This will chain the current CDT with CDT4., 0x0:
 *    no event, 0x1: timer starts counting down when CDT4 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT4 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT4_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT4_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT4_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT5_EXPIRY_MASK (0x200000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT5_EXPIRY_SHIFT (21U)
/*! start_emask_ble_cdt5_expiry - Event Mask: Chain with CDT5, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT5 expires. This will chain the current CDT with CDT5., 0x0:
 *    no event, 0x1: timer starts counting down when CDT5 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT5 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT5_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT5_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_CDT5_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT0_EXPIRY_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT0_EXPIRY_SHIFT (24U)
/*! start_emask_ble_swt0_expiry - Event Mask: Chain with SWT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT0 expires. This will chain the current CDT with SWT0., 0x0:
 *    no event, 0x1: timer starts counting down when SWT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT1_EXPIRY_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT1_EXPIRY_SHIFT (25U)
/*! start_emask_ble_swt1_expiry - Event Mask: Chain with SWT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT1 expires. This will chain the current CDT with SWT1., 0x0:
 *    no event, 0x1: timer starts counting down when SWT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT2_EXPIRY_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT2_EXPIRY_SHIFT (26U)
/*! start_emask_ble_swt2_expiry - Event Mask: Chain with SWT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT2 expires. This will chain the current CDT with SWT2., 0x0:
 *    no event, 0x1: timer starts counting down when SWT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT3_EXPIRY_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT3_EXPIRY_SHIFT (27U)
/*! start_emask_ble_swt3_expiry - Event Mask: Chain with SWT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT3 expires. This will chain the current CDT with SWT3., 0x0:
 *    no event, 0x1: timer starts counting down when SWT3 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_START_EMASK_BLE_SWT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_MATCHING_MODE_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_MATCHING_MODE_SHIFT (29U)
/*! cdt_matching_mode - CDT Matching Mode enable, indicates CDT value is not a countdown value; but
 *    an absolute value to be matched with the timestamp_qus_cnt_4m counter. Added for
 *    KFOURWONE-2451, 0x0: CDT is configured in original Countdown Mode, 0x1: CDT is configured in Matching Mode
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_MATCHING_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_MATCHING_MODE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_MATCHING_MODE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_CS_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_CS_SHIFT (30U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY., 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_ADJ_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_ADJ_EN_SHIFT (31U)
/*! cdt_adj_en - CDT timing adjustment enable, CDT timing adjustment enable for BLE 2M and BLE LR
 *    Tx/Rx for CI = 2;8., 0x0: disable, 0x1: enable
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_ADJ_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_0_CDT_ADJ_EN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_VALUE_0 - Count Down Timer 0: Count Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_0_COUNTDOWN_VALUE_MASK (0x1FFFU)
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_0_COUNTDOWN_VALUE_SHIFT (0U)
/*! countdown_value - Count Down Value, Number of quarter microseconds to count down from. Range is 1 to 8152 qus. */
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_0_COUNTDOWN_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_VALUE_0_COUNTDOWN_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_VALUE_0_COUNTDOWN_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CTL_1 - Qus Count Down Timer 1: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_INTR_SHIFT (0U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_ABORT_SHIFT (3U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for triggering an Abort from
 *    software., 0x0: no event, 0x1: Abort triggered at timer expiry
 *  0b0..no event
 *  0b1..Abort triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXSTART_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXSTART_SHIFT (4U)
/*! start_emask_ble_txstart - Event Mask: BLE Tx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Tx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXSTART_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXSTART_SHIFT (5U)
/*! start_emask_ble_rxstart - Event Mask: BLE Rx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Rx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXEND_MASK (0x40U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXEND_SHIFT (6U)
/*! start_emask_ble_txend - Event Mask: BLE Tx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Tx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_TXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXEND_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXEND_SHIFT (7U)
/*! start_emask_ble_rxend - Event Mask: BLE Rx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Rx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_RXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BTC_PKTEND_MASK (0x100U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BTC_PKTEND_SHIFT (8U)
/*! start_emask_btc_pktend - Event Mask: BTC PKT end, Start Event Mask for triggering the CDT
 *    counter. Start counting at the end of a BTC Tx or Rx transaction., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at end of next BTC packet (Tx, or Rx) transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BTC packet (Tx or Rx) transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BTC_PKTEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BTC_PKTEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BTC_PKTEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRHIT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRHIT_SHIFT (9U)
/*! start_emask_ble_corrhit - Event Mask: BLE CORR hit, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation hit., 0x0: no event, 0x1: timer starts counting down
 *    from programmed value at next BLE correlation hit
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation hit
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRHIT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRHIT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRHIT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_ASSERT_MASK (0x400U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_ASSERT_SHIFT (10U)
/*! start_emask_bca_req_assert - Event Mask: BCA request assertion, Start Event Mask for triggering
 *    the CDT counter. Start counting at BCA request assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_ASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_ASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_DEASSERT_MASK (0x800U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_DEASSERT_SHIFT (11U)
/*! start_emask_bca_req_deassert - Event Mask: BCA request deassertion, Start Event Mask for
 *    triggering the CDT counter. Start counting at BCA_req de-assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req de-assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req de-assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_DEASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_DEASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BCA_REQ_DEASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRMISS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRMISS_SHIFT (12U)
/*! start_emask_ble_corrmiss - Event Mask: BLE CORR miss, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation timeout interrupt., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BLE correlation miss
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation miss
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRMISS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRMISS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CORRMISS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_SW_TRIGGER_MASK (0x2000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_SW_TRIGGER_SHIFT (13U)
/*! start_emask_sw_trigger - Event Mask: Software trigger, Start Event Mask for triggering the CDT
 *    counter. Start counting when the firmware sets this bit. This bit is self clearing., 0x0: no
 *    event, 0x1: timer starts counting down from the programmed value as soon as this bit is set
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value as soon as this bit is set
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_SW_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_SW_TRIGGER_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_SW_TRIGGER_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_HW_ABORT_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_HW_ABORT_SHIFT (14U)
/*! start_emask_hw_abort - Event Mask: Hardware abort, Start Event Mask for triggering the CDT
 *    counter. Start counting when hardware abort occurs. The abort may be for a transmit packet or a
 *    receive packet., 0x0: no event, 0x1: timer starts counting down from the programmed value bit
 *    when hardware abort, happens
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value bit when hardware abort happens
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_HW_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_HW_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_HW_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_VALUE_RESET_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_VALUE_RESET_SHIFT (15U)
/*! cdt_value_reset - CDT value reset, This bit resets the CDT counter to 0. It will not trigger any
 *    expiry conditions (if programmed). This bit is self clearing, 0x0: no event, 0x1: Timer is
 *    reset to 0 immediately
 *  0b0..no event
 *  0b1..Timer is reset to 0 immediately
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_VALUE_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_VALUE_RESET_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_VALUE_RESET_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT0_EXPIRY_MASK (0x10000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT0_EXPIRY_SHIFT (16U)
/*! start_emask_ble_cdt0_expiry - Event Mask: Chain with CDT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT0 expires. This will chain the current CDT with CDT0., 0x0:
 *    no event, 0x1: timer starts counting down when CDT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT1_EXPIRY_MASK (0x20000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT1_EXPIRY_SHIFT (17U)
/*! start_emask_ble_cdt1_expiry - Event Mask: Chain with CDT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT1 expires. This will chain the current CDT with CDT1., 0x0:
 *    no event, 0x1: timer starts counting down when CDT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT2_EXPIRY_MASK (0x40000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT2_EXPIRY_SHIFT (18U)
/*! start_emask_ble_cdt2_expiry - Event Mask: Chain with CDT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT2 expires. This will chain the current CDT with CDT2., 0x0:
 *    no event, 0x1: timer starts counting down when CDT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT3_EXPIRY_MASK (0x80000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT3_EXPIRY_SHIFT (19U)
/*! start_emask_ble_cdt3_expiry - Event Mask: Chain with CDT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT3 expires. This will chain the current CDT with CDT3., 0x0:
 *    No event, 0x1: timer starts counting down when CDT3 expires
 *  0b0..No event
 *  0b1..timer starts counting down when CDT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT4_EXPIRY_MASK (0x100000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT4_EXPIRY_SHIFT (20U)
/*! start_emask_ble_cdt4_expiry - Event Mask: Chain with CDT4, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT4 expires. This will chain the current CDT with CDT4., 0x0:
 *    no event, 0x1: timer starts counting down when CDT4 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT4 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT4_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT4_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT4_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT5_EXPIRY_MASK (0x200000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT5_EXPIRY_SHIFT (21U)
/*! start_emask_ble_cdt5_expiry - Event Mask: Chain with CDT5, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT5 expires. This will chain the current CDT with CDT5., 0x0:
 *    no event, 0x1: timer starts counting down when CDT5 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT5 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT5_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT5_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_CDT5_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT0_EXPIRY_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT0_EXPIRY_SHIFT (24U)
/*! start_emask_ble_swt0_expiry - Event Mask: Chain with SWT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT0 expires. This will chain the current CDT with SWT0., 0x0:
 *    no event, 0x1: timer starts counting down when SWT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT1_EXPIRY_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT1_EXPIRY_SHIFT (25U)
/*! start_emask_ble_swt1_expiry - Event Mask: Chain with SWT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT1 expires. This will chain the current CDT with SWT1., 0x0:
 *    no event, 0x1: timer starts counting down when SWT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT2_EXPIRY_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT2_EXPIRY_SHIFT (26U)
/*! start_emask_ble_swt2_expiry - Event Mask: Chain with SWT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT2 expires. This will chain the current CDT with SWT2., 0x0:
 *    no event, 0x1: timer starts counting down when SWT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT3_EXPIRY_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT3_EXPIRY_SHIFT (27U)
/*! start_emask_ble_swt3_expiry - Event Mask: Chain with SWT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT3 expires. This will chain the current CDT with SWT3., 0x0:
 *    no event, 0x1: timer starts counting down when SWT3 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_START_EMASK_BLE_SWT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_MATCHING_MODE_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_MATCHING_MODE_SHIFT (29U)
/*! cdt_matching_mode - CDT Matching Mode enable, indicates CDT value is not a countdown value; but
 *    an absolute value to be matched with the timestamp_qus_cnt_4m counter. Added for
 *    KFOURWONE-2451, 0x0: CDT is configured in original Countdown Mode, 0x1: CDT is configured in Matching Mode
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_MATCHING_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_MATCHING_MODE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_MATCHING_MODE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_CS_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_CS_SHIFT (30U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY., 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_ADJ_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_ADJ_EN_SHIFT (31U)
/*! cdt_adj_en - CDT timing adjustment enable, CDT timing adjustment enable for BLE 2M and BLE LR
 *    Tx/Rx for CI = 2;8., 0x0: disable, 0x1: enable
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_ADJ_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_1_CDT_ADJ_EN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_VALUE_1 - Count Down Timer 1: Count Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_1_COUNTDOWN_VALUE_MASK (0x1FFFU)
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_1_COUNTDOWN_VALUE_SHIFT (0U)
/*! countdown_value - Count Down Value, Number of quarter microseconds to count down from. Range is 1 to 8152 qus. */
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_1_COUNTDOWN_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_VALUE_1_COUNTDOWN_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_VALUE_1_COUNTDOWN_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CTL_2 - Qus Count Down Timer 2: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_INTR_SHIFT (0U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_ABORT_SHIFT (3U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for triggering an Abort from
 *    software., 0x0: no event, 0x1: Abort triggered at timer expiry
 *  0b0..no event
 *  0b1..Abort triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXSTART_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXSTART_SHIFT (4U)
/*! start_emask_ble_txstart - Event Mask: BLE Tx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Tx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXSTART_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXSTART_SHIFT (5U)
/*! start_emask_ble_rxstart - Event Mask: BLE Rx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Rx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXEND_MASK (0x40U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXEND_SHIFT (6U)
/*! start_emask_ble_txend - Event Mask: BLE Tx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Tx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_TXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXEND_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXEND_SHIFT (7U)
/*! start_emask_ble_rxend - Event Mask: BLE Rx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Rx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_RXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BTC_PKTEND_MASK (0x100U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BTC_PKTEND_SHIFT (8U)
/*! start_emask_btc_pktend - Event Mask: BTC PKT end, Start Event Mask for triggering the CDT
 *    counter. Start counting at the end of a BTC Tx or Rx transaction., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at end of next BTC packet (Tx, or Rx) transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BTC packet (Tx or Rx) transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BTC_PKTEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BTC_PKTEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BTC_PKTEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRHIT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRHIT_SHIFT (9U)
/*! start_emask_ble_corrhit - Event Mask: BLE CORR hit, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation hit., 0x0: no event, 0x1: timer starts counting down
 *    from programmed value at next BLE correlation hit
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation hit
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRHIT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRHIT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRHIT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_ASSERT_MASK (0x400U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_ASSERT_SHIFT (10U)
/*! start_emask_bca_req_assert - Event Mask: BCA request assertion, Start Event Mask for triggering
 *    the CDT counter. Start counting at BCA request assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_ASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_ASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_DEASSERT_MASK (0x800U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_DEASSERT_SHIFT (11U)
/*! start_emask_bca_req_deassert - Event Mask: BCA request deassertion, Start Event Mask for
 *    triggering the CDT counter. Start counting at BCA_req de-assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req de-assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req de-assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_DEASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_DEASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BCA_REQ_DEASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRMISS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRMISS_SHIFT (12U)
/*! start_emask_ble_corrmiss - Event Mask: BLE CORR miss, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation timeout interrupt., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BLE correlation miss
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation miss
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRMISS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRMISS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CORRMISS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_SW_TRIGGER_MASK (0x2000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_SW_TRIGGER_SHIFT (13U)
/*! start_emask_sw_trigger - Event Mask: Software trigger, Start Event Mask for triggering the CDT
 *    counter. Start counting when the firmware sets this bit. This bit is self clearing., 0x0: no
 *    event, 0x1: timer starts counting down from the programmed value as soon as this bit is set
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value as soon as this bit is set
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_SW_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_SW_TRIGGER_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_SW_TRIGGER_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_HW_ABORT_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_HW_ABORT_SHIFT (14U)
/*! start_emask_hw_abort - Event Mask: Hardware abort, Start Event Mask for triggering the CDT
 *    counter. Start counting when hardware abort occurs. The abort may be for a transmit packet or a
 *    receive packet., 0x0: no event, 0x1: timer starts counting down from the programmed value bit
 *    when hardware abort, happens
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value bit when hardware abort happens
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_HW_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_HW_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_HW_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_VALUE_RESET_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_VALUE_RESET_SHIFT (15U)
/*! cdt_value_reset - CDT value reset, This bit resets the CDT counter to 0. It will not trigger any
 *    expiry conditions (if programmed). This bit is self clearing, 0x0: no event, 0x1: Timer is
 *    reset to 0 immediately
 *  0b0..no event
 *  0b1..Timer is reset to 0 immediately
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_VALUE_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_VALUE_RESET_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_VALUE_RESET_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT0_EXPIRY_MASK (0x10000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT0_EXPIRY_SHIFT (16U)
/*! start_emask_ble_cdt0_expiry - Event Mask: Chain with CDT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT0 expires. This will chain the current CDT with CDT0., 0x0:
 *    no event, 0x1: timer starts counting down when CDT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT1_EXPIRY_MASK (0x20000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT1_EXPIRY_SHIFT (17U)
/*! start_emask_ble_cdt1_expiry - Event Mask: Chain with CDT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT1 expires. This will chain the current CDT with CDT1., 0x0:
 *    no event, 0x1: timer starts counting down when CDT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT2_EXPIRY_MASK (0x40000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT2_EXPIRY_SHIFT (18U)
/*! start_emask_ble_cdt2_expiry - Event Mask: Chain with CDT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT2 expires. This will chain the current CDT with CDT2., 0x0:
 *    no event, 0x1: timer starts counting down when CDT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT3_EXPIRY_MASK (0x80000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT3_EXPIRY_SHIFT (19U)
/*! start_emask_ble_cdt3_expiry - Event Mask: Chain with CDT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT3 expires. This will chain the current CDT with CDT3., 0x0:
 *    No event, 0x1: timer starts counting down when CDT3 expires
 *  0b0..No event
 *  0b1..timer starts counting down when CDT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT4_EXPIRY_MASK (0x100000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT4_EXPIRY_SHIFT (20U)
/*! start_emask_ble_cdt4_expiry - Event Mask: Chain with CDT4, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT4 expires. This will chain the current CDT with CDT4., 0x0:
 *    no event, 0x1: timer starts counting down when CDT4 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT4 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT4_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT4_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT4_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT5_EXPIRY_MASK (0x200000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT5_EXPIRY_SHIFT (21U)
/*! start_emask_ble_cdt5_expiry - Event Mask: Chain with CDT5, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT5 expires. This will chain the current CDT with CDT5., 0x0:
 *    no event, 0x1: timer starts counting down when CDT5 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT5 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT5_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT5_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_CDT5_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT0_EXPIRY_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT0_EXPIRY_SHIFT (24U)
/*! start_emask_ble_swt0_expiry - Event Mask: Chain with SWT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT0 expires. This will chain the current CDT with SWT0., 0x0:
 *    no event, 0x1: timer starts counting down when SWT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT1_EXPIRY_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT1_EXPIRY_SHIFT (25U)
/*! start_emask_ble_swt1_expiry - Event Mask: Chain with SWT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT1 expires. This will chain the current CDT with SWT1., 0x0:
 *    no event, 0x1: timer starts counting down when SWT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT2_EXPIRY_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT2_EXPIRY_SHIFT (26U)
/*! start_emask_ble_swt2_expiry - Event Mask: Chain with SWT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT2 expires. This will chain the current CDT with SWT2., 0x0:
 *    no event, 0x1: timer starts counting down when SWT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT3_EXPIRY_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT3_EXPIRY_SHIFT (27U)
/*! start_emask_ble_swt3_expiry - Event Mask: Chain with SWT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT3 expires. This will chain the current CDT with SWT3., 0x0:
 *    no event, 0x1: timer starts counting down when SWT3 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_START_EMASK_BLE_SWT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_MATCHING_MODE_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_MATCHING_MODE_SHIFT (29U)
/*! cdt_matching_mode - CDT Matching Mode enable, indicates CDT value is not a countdown value; but
 *    an absolute value to be matched with the timestamp_qus_cnt_4m counter. Added for
 *    KFOURWONE-2451, 0x0: CDT is configured in original Countdown Mode, 0x1: CDT is configured in Matching Mode
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_MATCHING_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_MATCHING_MODE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_MATCHING_MODE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_CS_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_CS_SHIFT (30U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY., 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_ADJ_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_ADJ_EN_SHIFT (31U)
/*! cdt_adj_en - CDT timing adjustment enable, CDT timing adjustment enable for BLE 2M and BLE LR
 *    Tx/Rx for CI = 2;8., 0x0: disable, 0x1: enable
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_ADJ_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_2_CDT_ADJ_EN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_VALUE_2 - Count Down Timer 2: Count Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_2_COUNTDOWN_VALUE_MASK (0x1FFFU)
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_2_COUNTDOWN_VALUE_SHIFT (0U)
/*! countdown_value - Count Down Value, Number of quarter microseconds to count down from. Range is 1 to 8152 qus. */
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_2_COUNTDOWN_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_VALUE_2_COUNTDOWN_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_VALUE_2_COUNTDOWN_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CTL_3 - Qus Count Down Timer 3: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_INTR_SHIFT (0U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_ABORT_SHIFT (3U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for triggering an Abort from
 *    software., 0x0: no event, 0x1: Abort triggered at timer expiry
 *  0b0..no event
 *  0b1..Abort triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXSTART_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXSTART_SHIFT (4U)
/*! start_emask_ble_txstart - Event Mask: BLE Tx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Tx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXSTART_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXSTART_SHIFT (5U)
/*! start_emask_ble_rxstart - Event Mask: BLE Rx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Rx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXEND_MASK (0x40U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXEND_SHIFT (6U)
/*! start_emask_ble_txend - Event Mask: BLE Tx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Tx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_TXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXEND_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXEND_SHIFT (7U)
/*! start_emask_ble_rxend - Event Mask: BLE Rx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Rx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_RXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BTC_PKTEND_MASK (0x100U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BTC_PKTEND_SHIFT (8U)
/*! start_emask_btc_pktend - Event Mask: BTC PKT end, Start Event Mask for triggering the CDT
 *    counter. Start counting at the end of a BTC Tx or Rx transaction., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at end of next BTC packet (Tx, or Rx) transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BTC packet (Tx or Rx) transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BTC_PKTEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BTC_PKTEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BTC_PKTEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRHIT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRHIT_SHIFT (9U)
/*! start_emask_ble_corrhit - Event Mask: BLE CORR hit, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation hit., 0x0: no event, 0x1: timer starts counting down
 *    from programmed value at next BLE correlation hit
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation hit
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRHIT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRHIT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRHIT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_ASSERT_MASK (0x400U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_ASSERT_SHIFT (10U)
/*! start_emask_bca_req_assert - Event Mask: BCA request assertion, Start Event Mask for triggering
 *    the CDT counter. Start counting at BCA request assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_ASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_ASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_DEASSERT_MASK (0x800U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_DEASSERT_SHIFT (11U)
/*! start_emask_bca_req_deassert - Event Mask: BCA request deassertion, Start Event Mask for
 *    triggering the CDT counter. Start counting at BCA_req de-assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req de-assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req de-assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_DEASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_DEASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BCA_REQ_DEASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRMISS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRMISS_SHIFT (12U)
/*! start_emask_ble_corrmiss - Event Mask: BLE CORR miss, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation timeout interrupt., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BLE correlation miss
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation miss
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRMISS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRMISS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CORRMISS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_SW_TRIGGER_MASK (0x2000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_SW_TRIGGER_SHIFT (13U)
/*! start_emask_sw_trigger - Event Mask: Software trigger, Start Event Mask for triggering the CDT
 *    counter. Start counting when the firmware sets this bit. This bit is self clearing., 0x0: no
 *    event, 0x1: timer starts counting down from the programmed value as soon as this bit is set
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value as soon as this bit is set
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_SW_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_SW_TRIGGER_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_SW_TRIGGER_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_HW_ABORT_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_HW_ABORT_SHIFT (14U)
/*! start_emask_hw_abort - Event Mask: Hardware abort, Start Event Mask for triggering the CDT
 *    counter. Start counting when hardware abort occurs. The abort may be for a transmit packet or a
 *    receive packet., 0x0: no event, 0x1: timer starts counting down from the programmed value bit
 *    when hardware abort, happens
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value bit when hardware abort happens
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_HW_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_HW_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_HW_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_VALUE_RESET_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_VALUE_RESET_SHIFT (15U)
/*! cdt_value_reset - CDT value reset, This bit resets the CDT counter to 0. It will not trigger any
 *    expiry conditions (if programmed). This bit is self clearing, 0x0: no event, 0x1: Timer is
 *    reset to 0 immediately
 *  0b0..no event
 *  0b1..Timer is reset to 0 immediately
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_VALUE_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_VALUE_RESET_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_VALUE_RESET_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT0_EXPIRY_MASK (0x10000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT0_EXPIRY_SHIFT (16U)
/*! start_emask_ble_cdt0_expiry - Event Mask: Chain with CDT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT0 expires. This will chain the current CDT with CDT0., 0x0:
 *    no event, 0x1: timer starts counting down when CDT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT1_EXPIRY_MASK (0x20000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT1_EXPIRY_SHIFT (17U)
/*! start_emask_ble_cdt1_expiry - Event Mask: Chain with CDT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT1 expires. This will chain the current CDT with CDT1., 0x0:
 *    no event, 0x1: timer starts counting down when CDT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT2_EXPIRY_MASK (0x40000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT2_EXPIRY_SHIFT (18U)
/*! start_emask_ble_cdt2_expiry - Event Mask: Chain with CDT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT2 expires. This will chain the current CDT with CDT2., 0x0:
 *    no event, 0x1: timer starts counting down when CDT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT3_EXPIRY_MASK (0x80000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT3_EXPIRY_SHIFT (19U)
/*! start_emask_ble_cdt3_expiry - Event Mask: Chain with CDT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT3 expires. This will chain the current CDT with CDT3., 0x0:
 *    No event, 0x1: timer starts counting down when CDT3 expires
 *  0b0..No event
 *  0b1..timer starts counting down when CDT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT4_EXPIRY_MASK (0x100000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT4_EXPIRY_SHIFT (20U)
/*! start_emask_ble_cdt4_expiry - Event Mask: Chain with CDT4, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT4 expires. This will chain the current CDT with CDT4., 0x0:
 *    no event, 0x1: timer starts counting down when CDT4 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT4 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT4_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT4_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT4_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT5_EXPIRY_MASK (0x200000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT5_EXPIRY_SHIFT (21U)
/*! start_emask_ble_cdt5_expiry - Event Mask: Chain with CDT5, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT5 expires. This will chain the current CDT with CDT5., 0x0:
 *    no event, 0x1: timer starts counting down when CDT5 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT5 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT5_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT5_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_CDT5_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT0_EXPIRY_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT0_EXPIRY_SHIFT (24U)
/*! start_emask_ble_swt0_expiry - Event Mask: Chain with SWT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT0 expires. This will chain the current CDT with SWT0., 0x0:
 *    no event, 0x1: timer starts counting down when SWT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT1_EXPIRY_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT1_EXPIRY_SHIFT (25U)
/*! start_emask_ble_swt1_expiry - Event Mask: Chain with SWT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT1 expires. This will chain the current CDT with SWT1., 0x0:
 *    no event, 0x1: timer starts counting down when SWT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT2_EXPIRY_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT2_EXPIRY_SHIFT (26U)
/*! start_emask_ble_swt2_expiry - Event Mask: Chain with SWT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT2 expires. This will chain the current CDT with SWT2., 0x0:
 *    no event, 0x1: timer starts counting down when SWT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT3_EXPIRY_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT3_EXPIRY_SHIFT (27U)
/*! start_emask_ble_swt3_expiry - Event Mask: Chain with SWT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT3 expires. This will chain the current CDT with SWT3., 0x0:
 *    no event, 0x1: timer starts counting down when SWT3 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_START_EMASK_BLE_SWT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_MATCHING_MODE_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_MATCHING_MODE_SHIFT (29U)
/*! cdt_matching_mode - CDT Matching Mode enable, indicates CDT value is not a countdown value; but
 *    an absolute value to be matched with the timestamp_qus_cnt_4m counter. Added for
 *    KFOURWONE-2451, 0x0: CDT is configured in original Countdown Mode, 0x1: CDT is configured in Matching Mode
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_MATCHING_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_MATCHING_MODE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_MATCHING_MODE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_CS_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_CS_SHIFT (30U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY., 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_ADJ_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_ADJ_EN_SHIFT (31U)
/*! cdt_adj_en - CDT timing adjustment enable, CDT timing adjustment enable for BLE 2M and BLE LR
 *    Tx/Rx for CI = 2;8., 0x0: disable, 0x1: enable
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_ADJ_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_3_CDT_ADJ_EN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_VALUE_3 - Count Down Timer 3: Count Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_3_COUNTDOWN_VALUE_MASK (0x1FFFU)
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_3_COUNTDOWN_VALUE_SHIFT (0U)
/*! countdown_value - Count Down Value, Number of quarter microseconds to count down from. Range is 1 to 8152 qus. */
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_3_COUNTDOWN_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_VALUE_3_COUNTDOWN_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_VALUE_3_COUNTDOWN_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CTL_4 - Qus Count Down Timer 4: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_INTR_SHIFT (0U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_ABORT_SHIFT (3U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for triggering an Abort from
 *    software., 0x0: no event, 0x1: Abort triggered at timer expiry
 *  0b0..no event
 *  0b1..Abort triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXSTART_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXSTART_SHIFT (4U)
/*! start_emask_ble_txstart - Event Mask: BLE Tx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Tx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXSTART_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXSTART_SHIFT (5U)
/*! start_emask_ble_rxstart - Event Mask: BLE Rx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Rx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXEND_MASK (0x40U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXEND_SHIFT (6U)
/*! start_emask_ble_txend - Event Mask: BLE Tx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Tx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_TXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXEND_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXEND_SHIFT (7U)
/*! start_emask_ble_rxend - Event Mask: BLE Rx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Rx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_RXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BTC_PKTEND_MASK (0x100U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BTC_PKTEND_SHIFT (8U)
/*! start_emask_btc_pktend - Event Mask: BTC PKT end, Start Event Mask for triggering the CDT
 *    counter. Start counting at the end of a BTC Tx or Rx transaction., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at end of next BTC packet (Tx, or Rx) transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BTC packet (Tx or Rx) transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BTC_PKTEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BTC_PKTEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BTC_PKTEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRHIT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRHIT_SHIFT (9U)
/*! start_emask_ble_corrhit - Event Mask: BLE CORR hit, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation hit., 0x0: no event, 0x1: timer starts counting down
 *    from programmed value at next BLE correlation hit
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation hit
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRHIT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRHIT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRHIT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_ASSERT_MASK (0x400U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_ASSERT_SHIFT (10U)
/*! start_emask_bca_req_assert - Event Mask: BCA request assertion, Start Event Mask for triggering
 *    the CDT counter. Start counting at BCA request assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_ASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_ASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_DEASSERT_MASK (0x800U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_DEASSERT_SHIFT (11U)
/*! start_emask_bca_req_deassert - Event Mask: BCA request deassertion, Start Event Mask for
 *    triggering the CDT counter. Start counting at BCA_req de-assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req de-assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req de-assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_DEASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_DEASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BCA_REQ_DEASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRMISS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRMISS_SHIFT (12U)
/*! start_emask_ble_corrmiss - Event Mask: BLE CORR miss, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation timeout interrupt., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BLE correlation miss
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation miss
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRMISS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRMISS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CORRMISS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_SW_TRIGGER_MASK (0x2000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_SW_TRIGGER_SHIFT (13U)
/*! start_emask_sw_trigger - Event Mask: Software trigger, Start Event Mask for triggering the CDT
 *    counter. Start counting when the firmware sets this bit. This bit is self clearing., 0x0: no
 *    event, 0x1: timer starts counting down from the programmed value as soon as this bit is set
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value as soon as this bit is set
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_SW_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_SW_TRIGGER_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_SW_TRIGGER_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_HW_ABORT_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_HW_ABORT_SHIFT (14U)
/*! start_emask_hw_abort - Event Mask: Hardware abort, Start Event Mask for triggering the CDT
 *    counter. Start counting when hardware abort occurs. The abort may be for a transmit packet or a
 *    receive packet., 0x0: no event, 0x1: timer starts counting down from the programmed value bit
 *    when hardware abort, happens
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value bit when hardware abort happens
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_HW_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_HW_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_HW_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_VALUE_RESET_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_VALUE_RESET_SHIFT (15U)
/*! cdt_value_reset - CDT value reset, This bit resets the CDT counter to 0. It will not trigger any
 *    expiry conditions (if programmed). This bit is self clearing, 0x0: no event, 0x1: Timer is
 *    reset to 0 immediately
 *  0b0..no event
 *  0b1..Timer is reset to 0 immediately
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_VALUE_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_VALUE_RESET_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_VALUE_RESET_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT0_EXPIRY_MASK (0x10000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT0_EXPIRY_SHIFT (16U)
/*! start_emask_ble_cdt0_expiry - Event Mask: Chain with CDT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT0 expires. This will chain the current CDT with CDT0., 0x0:
 *    no event, 0x1: timer starts counting down when CDT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT1_EXPIRY_MASK (0x20000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT1_EXPIRY_SHIFT (17U)
/*! start_emask_ble_cdt1_expiry - Event Mask: Chain with CDT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT1 expires. This will chain the current CDT with CDT1., 0x0:
 *    no event, 0x1: timer starts counting down when CDT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT2_EXPIRY_MASK (0x40000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT2_EXPIRY_SHIFT (18U)
/*! start_emask_ble_cdt2_expiry - Event Mask: Chain with CDT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT2 expires. This will chain the current CDT with CDT2., 0x0:
 *    no event, 0x1: timer starts counting down when CDT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT3_EXPIRY_MASK (0x80000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT3_EXPIRY_SHIFT (19U)
/*! start_emask_ble_cdt3_expiry - Event Mask: Chain with CDT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT3 expires. This will chain the current CDT with CDT3., 0x0:
 *    No event, 0x1: timer starts counting down when CDT3 expires
 *  0b0..No event
 *  0b1..timer starts counting down when CDT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT4_EXPIRY_MASK (0x100000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT4_EXPIRY_SHIFT (20U)
/*! start_emask_ble_cdt4_expiry - Event Mask: Chain with CDT4, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT4 expires. This will chain the current CDT with CDT4., 0x0:
 *    no event, 0x1: timer starts counting down when CDT4 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT4 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT4_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT4_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT4_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT5_EXPIRY_MASK (0x200000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT5_EXPIRY_SHIFT (21U)
/*! start_emask_ble_cdt5_expiry - Event Mask: Chain with CDT5, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT5 expires. This will chain the current CDT with CDT5., 0x0:
 *    no event, 0x1: timer starts counting down when CDT5 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT5 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT5_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT5_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_CDT5_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT0_EXPIRY_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT0_EXPIRY_SHIFT (24U)
/*! start_emask_ble_swt0_expiry - Event Mask: Chain with SWT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT0 expires. This will chain the current CDT with SWT0., 0x0:
 *    no event, 0x1: timer starts counting down when SWT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT1_EXPIRY_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT1_EXPIRY_SHIFT (25U)
/*! start_emask_ble_swt1_expiry - Event Mask: Chain with SWT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT1 expires. This will chain the current CDT with SWT1., 0x0:
 *    no event, 0x1: timer starts counting down when SWT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT2_EXPIRY_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT2_EXPIRY_SHIFT (26U)
/*! start_emask_ble_swt2_expiry - Event Mask: Chain with SWT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT2 expires. This will chain the current CDT with SWT2., 0x0:
 *    no event, 0x1: timer starts counting down when SWT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT3_EXPIRY_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT3_EXPIRY_SHIFT (27U)
/*! start_emask_ble_swt3_expiry - Event Mask: Chain with SWT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT3 expires. This will chain the current CDT with SWT3., 0x0:
 *    no event, 0x1: timer starts counting down when SWT3 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_START_EMASK_BLE_SWT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_MATCHING_MODE_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_MATCHING_MODE_SHIFT (29U)
/*! cdt_matching_mode - CDT Matching Mode enable, indicates CDT value is not a countdown value; but
 *    an absolute value to be matched with the timestamp_qus_cnt_4m counter. Added for
 *    KFOURWONE-2451, 0x0: CDT is configured in original Countdown Mode, 0x1: CDT is configured in Matching Mode
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_MATCHING_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_MATCHING_MODE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_MATCHING_MODE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_CS_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_CS_SHIFT (30U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY., 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_ADJ_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_ADJ_EN_SHIFT (31U)
/*! cdt_adj_en - CDT timing adjustment enable, CDT timing adjustment enable for BLE 2M and BLE LR
 *    Tx/Rx for CI = 2;8., 0x0: disable, 0x1: enable
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_ADJ_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_4_CDT_ADJ_EN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_VALUE_4 - Count Down Timer 4: Count Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_4_COUNTDOWN_VALUE_MASK (0x1FFFU)
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_4_COUNTDOWN_VALUE_SHIFT (0U)
/*! countdown_value - Count Down Value, Number of quarter microseconds to count down from. Range is 1 to 8152 qus. */
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_4_COUNTDOWN_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_VALUE_4_COUNTDOWN_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_VALUE_4_COUNTDOWN_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CTL_5 - Qus Count Down Timer 5: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_INTR_MASK (0x1U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_INTR_SHIFT (0U)
/*! expiry_emask_intr - Event Mask: Interrupt, Expiration Event Mask for Interrupt, 0x0: no event, 0x1: interrupt triggered at expiry of timer
 *  0b0..no event
 *  0b1..interrupt triggered at expiry of timer
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_INTR_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_INTR_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_TX_MASK (0x2U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_TX_SHIFT (1U)
/*! expiry_emask_tx - Event Mask: Tx, Expiration Event Mask for triggering an Tx transaction., 0x0:
 *    no event, 0x1: Tx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Tx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_TX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_TX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_TX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_RX_MASK (0x4U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_RX_SHIFT (2U)
/*! expiry_emask_rx - Event Mask: Rx, Expiration Event Mask for triggering an Rx transaction., 0x0:
 *    no event, 0x1: Rx event triggered at timer expiry
 *  0b0..no event
 *  0b1..Rx event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_RX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_RX_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_RX_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_ABORT_MASK (0x8U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_ABORT_SHIFT (3U)
/*! expiry_emask_abort - Event Mask: Abort, Expiration Event Mask for triggering an Abort from
 *    software., 0x0: no event, 0x1: Abort triggered at timer expiry
 *  0b0..no event
 *  0b1..Abort triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXSTART_MASK (0x10U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXSTART_SHIFT (4U)
/*! start_emask_ble_txstart - Event Mask: BLE Tx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Tx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXSTART_MASK (0x20U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXSTART_SHIFT (5U)
/*! start_emask_ble_rxstart - Event Mask: BLE Rx start, Start Event Mask for triggering the CDT
 *    counter. Start counting at the beginning of a BLE Rx transaction., 0x0: no event, 0x1: timer
 *    starts counting down from programmed value at start of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at start of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXSTART(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXSTART_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXSTART_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXEND_MASK (0x40U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXEND_SHIFT (6U)
/*! start_emask_ble_txend - Event Mask: BLE Tx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Tx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Tx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Tx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_TXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXEND_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXEND_SHIFT (7U)
/*! start_emask_ble_rxend - Event Mask: BLE Rx end, Start Event Mask for triggering the CDT counter.
 *    Start counting at the end of a BLE Rx transaction., 0x0: no event, 0x1: timer starts counting
 *    down from programmed value at end of next BLE Rx, transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BLE Rx transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_RXEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BTC_PKTEND_MASK (0x100U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BTC_PKTEND_SHIFT (8U)
/*! start_emask_btc_pktend - Event Mask: BTC PKT end, Start Event Mask for triggering the CDT
 *    counter. Start counting at the end of a BTC Tx or Rx transaction., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at end of next BTC packet (Tx, or Rx) transaction
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at end of next BTC packet (Tx or Rx) transaction
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BTC_PKTEND(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BTC_PKTEND_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BTC_PKTEND_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRHIT_MASK (0x200U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRHIT_SHIFT (9U)
/*! start_emask_ble_corrhit - Event Mask: BLE CORR hit, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation hit., 0x0: no event, 0x1: timer starts counting down
 *    from programmed value at next BLE correlation hit
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation hit
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRHIT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRHIT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRHIT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_ASSERT_MASK (0x400U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_ASSERT_SHIFT (10U)
/*! start_emask_bca_req_assert - Event Mask: BCA request assertion, Start Event Mask for triggering
 *    the CDT counter. Start counting at BCA request assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_ASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_ASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_DEASSERT_MASK (0x800U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_DEASSERT_SHIFT (11U)
/*! start_emask_bca_req_deassert - Event Mask: BCA request deassertion, Start Event Mask for
 *    triggering the CDT counter. Start counting at BCA_req de-assertion., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BCA_req de-assertion
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BCA_req de-assertion
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_DEASSERT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_DEASSERT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BCA_REQ_DEASSERT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRMISS_MASK (0x1000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRMISS_SHIFT (12U)
/*! start_emask_ble_corrmiss - Event Mask: BLE CORR miss, Start Event Mask for triggering the CDT
 *    counter. Start counting at BLE correlation timeout interrupt., 0x0: no event, 0x1: timer starts
 *    counting down from programmed value at next BLE correlation miss
 *  0b0..no event
 *  0b1..timer starts counting down from programmed value at next BLE correlation miss
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRMISS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRMISS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CORRMISS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_SW_TRIGGER_MASK (0x2000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_SW_TRIGGER_SHIFT (13U)
/*! start_emask_sw_trigger - Event Mask: Software trigger, Start Event Mask for triggering the CDT
 *    counter. Start counting when the firmware sets this bit. This bit is self clearing., 0x0: no
 *    event, 0x1: timer starts counting down from the programmed value as soon as this bit is set
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value as soon as this bit is set
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_SW_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_SW_TRIGGER_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_SW_TRIGGER_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_HW_ABORT_MASK (0x4000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_HW_ABORT_SHIFT (14U)
/*! start_emask_hw_abort - Event Mask: Hardware abort, Start Event Mask for triggering the CDT
 *    counter. Start counting when hardware abort occurs. The abort may be for a transmit packet or a
 *    receive packet., 0x0: no event, 0x1: timer starts counting down from the programmed value bit
 *    when hardware abort, happens
 *  0b0..no event
 *  0b1..timer starts counting down from the programmed value bit when hardware abort happens
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_HW_ABORT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_HW_ABORT_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_HW_ABORT_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_VALUE_RESET_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_VALUE_RESET_SHIFT (15U)
/*! cdt_value_reset - CDT value reset, This bit resets the CDT counter to 0. It will not trigger any
 *    expiry conditions (if programmed). This bit is self clearing, 0x0: no event, 0x1: Timer is
 *    reset to 0 immediately
 *  0b0..no event
 *  0b1..Timer is reset to 0 immediately
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_VALUE_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_VALUE_RESET_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_VALUE_RESET_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT0_EXPIRY_MASK (0x10000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT0_EXPIRY_SHIFT (16U)
/*! start_emask_ble_cdt0_expiry - Event Mask: Chain with CDT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT0 expires. This will chain the current CDT with CDT0., 0x0:
 *    no event, 0x1: timer starts counting down when CDT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT1_EXPIRY_MASK (0x20000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT1_EXPIRY_SHIFT (17U)
/*! start_emask_ble_cdt1_expiry - Event Mask: Chain with CDT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT1 expires. This will chain the current CDT with CDT1., 0x0:
 *    no event, 0x1: timer starts counting down when CDT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT2_EXPIRY_MASK (0x40000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT2_EXPIRY_SHIFT (18U)
/*! start_emask_ble_cdt2_expiry - Event Mask: Chain with CDT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT2 expires. This will chain the current CDT with CDT2., 0x0:
 *    no event, 0x1: timer starts counting down when CDT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT3_EXPIRY_MASK (0x80000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT3_EXPIRY_SHIFT (19U)
/*! start_emask_ble_cdt3_expiry - Event Mask: Chain with CDT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT3 expires. This will chain the current CDT with CDT3., 0x0:
 *    No event, 0x1: timer starts counting down when CDT3 expires
 *  0b0..No event
 *  0b1..timer starts counting down when CDT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT4_EXPIRY_MASK (0x100000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT4_EXPIRY_SHIFT (20U)
/*! start_emask_ble_cdt4_expiry - Event Mask: Chain with CDT4, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT4 expires. This will chain the current CDT with CDT4., 0x0:
 *    no event, 0x1: timer starts counting down when CDT4 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT4 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT4_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT4_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT4_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT5_EXPIRY_MASK (0x200000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT5_EXPIRY_SHIFT (21U)
/*! start_emask_ble_cdt5_expiry - Event Mask: Chain with CDT5, Start Event Mask for triggering the
 *    CDT counter. Start counting when CDT5 expires. This will chain the current CDT with CDT5., 0x0:
 *    no event, 0x1: timer starts counting down when CDT5 expires
 *  0b0..no event
 *  0b1..timer starts counting down when CDT5 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT5_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT5_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_CDT5_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT0_EXPIRY_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT0_EXPIRY_SHIFT (24U)
/*! start_emask_ble_swt0_expiry - Event Mask: Chain with SWT0, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT0 expires. This will chain the current CDT with SWT0., 0x0:
 *    no event, 0x1: timer starts counting down when SWT0 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT0 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT0_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT0_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT0_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT1_EXPIRY_MASK (0x2000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT1_EXPIRY_SHIFT (25U)
/*! start_emask_ble_swt1_expiry - Event Mask: Chain with SWT1, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT1 expires. This will chain the current CDT with SWT1., 0x0:
 *    no event, 0x1: timer starts counting down when SWT1 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT1 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT1_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT1_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT1_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT2_EXPIRY_MASK (0x4000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT2_EXPIRY_SHIFT (26U)
/*! start_emask_ble_swt2_expiry - Event Mask: Chain with SWT2, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT2 expires. This will chain the current CDT with SWT2., 0x0:
 *    no event, 0x1: timer starts counting down when SWT2 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT2 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT2_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT2_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT2_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT3_EXPIRY_MASK (0x8000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT3_EXPIRY_SHIFT (27U)
/*! start_emask_ble_swt3_expiry - Event Mask: Chain with SWT3, Start Event Mask for triggering the
 *    CDT counter. Start counting when SWT3 expires. This will chain the current CDT with SWT3., 0x0:
 *    no event, 0x1: timer starts counting down when SWT3 expires
 *  0b0..no event
 *  0b1..timer starts counting down when SWT3 expires
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT3_EXPIRY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT3_EXPIRY_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_START_EMASK_BLE_SWT3_EXPIRY_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_MATCHING_MODE_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_MATCHING_MODE_SHIFT (29U)
/*! cdt_matching_mode - CDT Matching Mode enable, indicates CDT value is not a countdown value; but
 *    an absolute value to be matched with the timestamp_qus_cnt_4m counter. Added for
 *    KFOURWONE-2451, 0x0: CDT is configured in original Countdown Mode, 0x1: CDT is configured in Matching Mode
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_MATCHING_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_MATCHING_MODE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_MATCHING_MODE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_CS_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_CS_SHIFT (30U)
/*! expiry_emask_cs - Event Mask: CS event for KW PHY, Expiration Event Mask for triggering a CS
 *    transaction to KW PHY., 0x0: no event, 0x1: CS event triggered at timer expiry
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_CS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_CS_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_EXPIRY_EMASK_CS_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_ADJ_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_ADJ_EN_SHIFT (31U)
/*! cdt_adj_en - CDT timing adjustment enable, CDT timing adjustment enable for BLE 2M and BLE LR
 *    Tx/Rx for CI = 2;8., 0x0: disable, 0x1: enable
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_ADJ_EN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CTL_5_CDT_ADJ_EN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_VALUE_5 - Count Down Timer 5: Count Value */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_5_COUNTDOWN_VALUE_MASK (0x1FFFU)
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_5_COUNTDOWN_VALUE_SHIFT (0U)
/*! countdown_value - Count Down Value, Number of quarter microseconds to count down from. Range is 1 to 8152 qus. */
#define BLE2_REG_BLE_REG_TMR_CDT_VALUE_5_COUNTDOWN_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_VALUE_5_COUNTDOWN_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_VALUE_5_COUNTDOWN_VALUE_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_2M_DATA_ADJ - Qus Count Offset Register: LE 2M */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_VALUE_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_VALUE_SHIFT (0U)
/*! rx_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_SIGN_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_SIGN_SHIFT (7U)
/*! rx_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_RX_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_VALUE_MASK (0x7F0000U)
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_VALUE_SHIFT (16U)
/*! tx_adj_value - Tx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_SIGN_MASK (0x800000U)
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_SIGN_SHIFT (23U)
/*! tx_adj_sign - Tx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_2M_DATA_ADJ_TX_ADJ_SIGN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CI_TX_DATA_ADJ - Qus Count Offset Register: LE Coded Tx */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_VALUE_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_VALUE_SHIFT (0U)
/*! tx_ci_2_adj_value - Tx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_SIGN_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_SIGN_SHIFT (7U)
/*! tx_ci_2_adj_sign - Tx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_2_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_VALUE_MASK (0x7F0000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_VALUE_SHIFT (16U)
/*! tx_ci_8_adj_value - Tx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_SIGN_MASK (0x800000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_SIGN_SHIFT (23U)
/*! tx_ci_8_adj_sign - Tx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_TX_DATA_ADJ_TX_CI_8_ADJ_SIGN_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0 - Qus Count Offset Register: LE Coded Rx 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_VALUE_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_VALUE_SHIFT (0U)
/*! rx_ci_2_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_SIGN_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_SIGN_SHIFT (7U)
/*! rx_ci_2_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_2_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_VALUE_MASK (0x7F00U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_VALUE_SHIFT (8U)
/*! rx_ci_8_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_SIGN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_SIGN_SHIFT (15U)
/*! rx_ci_8_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_8_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_ADJ_EMASK_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_ADJ_EMASK_SHIFT (24U)
/*! rx_ci_adj_emask - Adjustment Mask: Rx, Last coded bursting bit size for triggering this Rx adjustment. */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_ADJ_EMASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_ADJ_EMASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_0_RX_CI_ADJ_EMASK_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1 - Qus Count Offset Register: LE Coded Rx 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_VALUE_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_VALUE_SHIFT (0U)
/*! rx_ci_2_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_SIGN_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_SIGN_SHIFT (7U)
/*! rx_ci_2_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_2_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_VALUE_MASK (0x7F00U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_VALUE_SHIFT (8U)
/*! rx_ci_8_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_SIGN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_SIGN_SHIFT (15U)
/*! rx_ci_8_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_8_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_ADJ_EMASK_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_ADJ_EMASK_SHIFT (24U)
/*! rx_ci_adj_emask - Adjustment Mask: Rx, Last coded bursting bit size for triggering this Rx adjustment. */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_ADJ_EMASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_ADJ_EMASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_1_RX_CI_ADJ_EMASK_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2 - Qus Count Offset Register: LE Coded Rx 2 */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_VALUE_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_VALUE_SHIFT (0U)
/*! rx_ci_2_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_SIGN_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_SIGN_SHIFT (7U)
/*! rx_ci_2_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_2_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_VALUE_MASK (0x7F00U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_VALUE_SHIFT (8U)
/*! rx_ci_8_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_SIGN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_SIGN_SHIFT (15U)
/*! rx_ci_8_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_8_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_ADJ_EMASK_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_ADJ_EMASK_SHIFT (24U)
/*! rx_ci_adj_emask - Adjustment Mask: Rx, Last coded bursting bit size for triggering this Rx adjustment. */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_ADJ_EMASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_ADJ_EMASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_2_RX_CI_ADJ_EMASK_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3 - Qus Count Offset Register: LE Coded Rx 3 */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_VALUE_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_VALUE_SHIFT (0U)
/*! rx_ci_2_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_SIGN_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_SIGN_SHIFT (7U)
/*! rx_ci_2_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_2_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_VALUE_MASK (0x7F00U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_VALUE_SHIFT (8U)
/*! rx_ci_8_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_SIGN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_SIGN_SHIFT (15U)
/*! rx_ci_8_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_8_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_ADJ_EMASK_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_ADJ_EMASK_SHIFT (24U)
/*! rx_ci_adj_emask - Adjustment Mask: Rx, Last coded bursting bit size for triggering this Rx adjustment. */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_ADJ_EMASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_ADJ_EMASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_3_RX_CI_ADJ_EMASK_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4 - Qus Count Offset Register: LE Coded Rx 4 */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_VALUE_MASK (0x7FU)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_VALUE_SHIFT (0U)
/*! rx_ci_2_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_SIGN_MASK (0x80U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_SIGN_SHIFT (7U)
/*! rx_ci_2_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_2_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_VALUE_MASK (0x7F00U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_VALUE_SHIFT (8U)
/*! rx_ci_8_adj_value - Rx Count Down Value in QUS, +/- offset. Resolution: 0/25 us */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_VALUE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_VALUE_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_VALUE_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_SIGN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_SIGN_SHIFT (15U)
/*! rx_ci_8_adj_sign - Rx Operation Sign, 0x0: add, 0x1: substrate
 *  0b0..add
 *  0b1..substrate
 */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_SIGN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_SIGN_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_8_ADJ_SIGN_MASK)

#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_ADJ_EMASK_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_ADJ_EMASK_SHIFT (24U)
/*! rx_ci_adj_emask - Adjustment Mask: Rx, Last coded bursting bit size for triggering this Rx adjustment. */
#define BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_ADJ_EMASK(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_ADJ_EMASK_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_CI_RX_DATA_ADJ_4_RX_CI_ADJ_EMASK_MASK)
/*! @} */

/*! @name BLE_REG_TMR_CDT_STS - Countdown timer Status */
/*! @{ */

#define BLE2_REG_BLE_REG_TMR_CDT_STS_cdt_expiry_sts_MASK (0x3FU)
#define BLE2_REG_BLE_REG_TMR_CDT_STS_cdt_expiry_sts_SHIFT (0U)
/*! cdt_expiry_sts - CDT Expiry Status in CDT Matching mode, This bit is updated at each CDT expiry;
 *    when CDT is programmed in cdt_matching_mode. For the purpose of this register; past value on
 *    CDT refers to any value less than the half-slot+qus timestamp at which CDT was programmed.
 *    Once set it remains set until this CDT expires again in the matching mode, 0x0: CDT matching was
 *    successful, 0x1: CDT matching value was in the past at the time of programming
 */
#define BLE2_REG_BLE_REG_TMR_CDT_STS_cdt_expiry_sts(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TMR_CDT_STS_cdt_expiry_sts_SHIFT)) & BLE2_REG_BLE_REG_TMR_CDT_STS_cdt_expiry_sts_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_CNTRL - Tx Antenna Switch Control */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_1M_MASK (0xFFU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_1M_SHIFT (0U)
/*! tx_ant_switch_delay_1m - Antenna Switch Delay from end of Tx Crc, Timer delayed from end of CRC
 *    of the current Tx packet to start driving requestAntenna to signal BCA which antenna is used
 *    for the Tx extension field., - Resolution: 0.25 usec.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_1M(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_1M_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_1M_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_2M_MASK (0xFF00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_2M_SHIFT (8U)
/*! tx_ant_switch_delay_2m - Antenna Switch Delay from end of Tx Crc, Timer delayed from end of CRC
 *    of the current Tx packet to start driving requestAntenna to signal BCA which antenna is used
 *    for the Tx extension field. This delay is for BLE Tx 2 Mbps., - Resolution: 0.25 usec.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_2M(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_2M_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_DELAY_2M_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_MAP_LENGTH_MASK (0x3F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_MAP_LENGTH_SHIFT (16U)
/*! tx_ant_map_length - Antenna Switch Map Length for Tx DFE, - Valid length of Tx antenna map
 *    pattern (max: 40). After executing the antenna switching for this length; BLE will repeat the
 *    pattern from the beginning. The map is used when BLE is transmitting extension packets.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_MAP_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_MAP_LENGTH_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_MAP_LENGTH_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_RATE_MASK (0xC00000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_RATE_SHIFT (22U)
/*! tx_ant_switch_rate - Antenna Switch Rate, Define the antenna switching rate for extension
 *    packet., 0x0: switch antenna every 4 usec, 0x1: switch antenna every 2 usec, 0x2: switch antenna
 *    every 1 usec (RFU), 0x3: not valid
 *  0b00..switch antenna every 4 usec
 *  0b01..switch antenna every 2 usec
 *  0b10..switch antenna every 1 usec (RFU)
 *  0b11..not valid
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_RATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_RATE_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_RATE_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_REF_ANT_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_REF_ANT_SHIFT (24U)
/*! ref_ant - BCA reference antenna, The value of reference antenna held by the BCA. */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_REF_ANT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_REF_ANT_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_REF_ANT_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_EN_SHIFT (31U)
/*! tx_ant_switch_en - Antenna Switch Enable for Tx DFE, Switch antenna for extension when
 *    transmitting location packet., 0x0: disable antenna switch for Tx DFE, 0x1: enable antenna switch for
 *    Tx DFE
 *  0b0..disable antenna switch for Tx DFE
 *  0b1..enable antenna switch for Tx DFE
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_EN_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_CNTRL_TX_ANT_SWITCH_EN_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_0 - Tx Antenna Switch Map: Map 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_0_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_1 - Tx Antenna Switch Map: Map 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_1_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_2 - Tx Antenna Switch Map: Map 2 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_2_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_3 - Tx Antenna Switch Map: Map 3 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_3_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_4 - Tx Antenna Switch Map: Map 4 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_4_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_5 - Tx Antenna Switch Map: Map 5 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_5_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_6 - Tx Antenna Switch Map: Map 6 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_6_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_7 - Tx Antenna Switch Map: Map 7 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_7_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_8 - Tx Antenna Switch Map: Map 8 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_8_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_TX_MAP_9 - Tx Antenna Switch Map: Map 9 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! tx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! tx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! tx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! tx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_TX_MAP_0; and follows the index order
 *    of tx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_TX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_TX_MAP_1.2.to 9. The pattern length use is determined
 *    by tx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_TX_MAP_9_TX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_CNTRL - Rx Antenna Switch Control */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_1M_MASK (0xFFU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_1M_SHIFT (0U)
/*! rx_ant_switch_delay_1m - Antenna Switch Delay from start of Rx Crc, Timer delayed from start of
 *    CRC of the current Rx packet to start driving requestAntenna to signal BCA which antenna is
 *    used for the expected Rx extension field., - Resolution: 0.25 usec.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_1M(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_1M_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_1M_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_2M_MASK (0xFF00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_2M_SHIFT (8U)
/*! rx_ant_switch_delay_2m - Antenna Switch Delay from start of Rx Crc, Timer delayed from start of
 *    CRC of the current Rx packet to start driving requestAntenna to signal BCA which antenna is
 *    used for the expected Rx extension field. This delay is for BLE Rx 2 Mbps., - Resolution: 0.25
 *    usec.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_2M(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_2M_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_DELAY_2M_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_MAP_LENGTH_MASK (0x3F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_MAP_LENGTH_SHIFT (16U)
/*! rx_ant_map_length - Antenna Switch Map Length for Rx DFE, - Valid length of Rx antenna map
 *    pattern (max: 40). After executing the antenna switching for this length; BLE will repeat the
 *    pattern from the beginning. The map is used when BLE is receiving extension packets.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_MAP_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_MAP_LENGTH_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_MAP_LENGTH_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_RATE_MASK (0xC00000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_RATE_SHIFT (22U)
/*! rx_ant_switch_rate - Antenna Switch Rate, Define the antenna switching rate for extension
 *    packet., 0x0: switch antenna every 4 usec, 0x1: switch antenna every 2 usec, 0x2: switch antenna
 *    every 1 usec (RFU), 0x3: not valid
 *  0b00..switch antenna every 4 usec
 *  0b01..switch antenna every 2 usec
 *  0b10..switch antenna every 1 usec (RFU)
 *  0b11..not valid
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_RATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_RATE_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_RATE_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_REF_ANT_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_REF_ANT_SHIFT (24U)
/*! ref_ant - BCA reference antenna, The value of reference antenna held by BCA. */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_REF_ANT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_REF_ANT_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_REF_ANT_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_EN_SHIFT (31U)
/*! rx_ant_switch_en - Antenna Switch Enable for Rx DFE, Switch antenna for extension when receiving
 *    location packet., 0x0: disable antenna switch for Rx DFE, 0x1: enable antenna switch for Rx
 *    DFE
 *  0b0..disable antenna switch for Rx DFE
 *  0b1..enable antenna switch for Rx DFE
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_EN_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_CNTRL_RX_ANT_SWITCH_EN_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_0 - Rx Antenna Switch Map: Map 0 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_0_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_1 - Rx Antenna Switch Map: Map 1 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_1_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_2 - Rx Antenna Switch Map: Map 2 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_2_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_3 - Rx Antenna Switch Map: Map 3 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_3_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_4 - Rx Antenna Switch Map: Map 4 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_4_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_5 - Rx Antenna Switch Map: Map 5 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_5_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_6 - Rx Antenna Switch Map: Map 6 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_6_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_7 - Rx Antenna Switch Map: Map 7 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_7_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_8 - Rx Antenna Switch Map: Map 8 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_8_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_ANT_SWITCH_RX_MAP_9 - Rx Antenna Switch Map: Map 9 */
/*! @{ */

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_0_MASK (0x1FU)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_0_SHIFT (0U)
/*! rx_ant_switch_index_0 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_0(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_0_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_0_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_1_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_1_SHIFT (8U)
/*! rx_ant_switch_index_1 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_1_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_1_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_2_MASK (0x1F0000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_2_SHIFT (16U)
/*! rx_ant_switch_index_2 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_2_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_2_MASK)

#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_3_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_3_SHIFT (24U)
/*! rx_ant_switch_index_3 - Antenna Switch Map, Antenna switch map is programmed in a group of 10;
 *    32-bit registers; which represents 40 different values; each value being 5-bit wide for 32
 *    antennas. Switching pattern starts from BLE_REG_ANT_SWITCH_RX_MAP_0; and follows the index order
 *    of rx_ant_switch_index_0.1.2.to 3; while BLE_REG_ANT_SWITCH_RX_MAP_0 finishes; continues with
 *    the other 4 indexes in BLE_REG_ANT_SWITCH_RX_MAP_1.2.to 9. The pattern length use is determined
 *    by rx_ant_map_length.
 */
#define BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_3_SHIFT)) & BLE2_REG_BLE_REG_ANT_SWITCH_RX_MAP_9_RX_ANT_SWITCH_INDEX_3_MASK)
/*! @} */

/*! @name BLE_REG_PST_CTRL_0 - Periodic SW Timer 0: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_CTRL_0_ISO_TMR_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_ISO_TMR_EN_SHIFT (0U)
/*! iso_tmr_en - Enable Periodic SW Timer's ISO_Intvl_Tmr/BIS_Spc_Tmr
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_ISO_TMR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_ISO_TMR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_ISO_TMR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_TIMER_MODE_MASK (0x2U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_TIMER_MODE_SHIFT (1U)
/*! timer_mode - Configure Peridodic SW Timer Timer Mode
 *  0b0..configure to BIS timer mode
 *  0b1..configure to CIS timer mode
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_TIMER_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_TIMER_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_TIMER_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_SEQ_MODE_MASK (0x4U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_SEQ_MODE_SHIFT (2U)
/*! seq_mode - Configure Multiple BISes/CISes To Sequential Or Interleaved Arrangement
 *  0b0..configure to interleaved arrangement
 *  0b1..configure to sequential arrangement
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_SEQ_MODE(x)  (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_SEQ_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_SEQ_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_TX_EVT_MASK (0x10U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_TX_EVT_SHIFT (4U)
/*! trig_tx_evt - Trigger a Packet Tx Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_TX_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_TX_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_TX_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_RX_EVT_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_RX_EVT_SHIFT (5U)
/*! trig_rx_evt - Trigger a Packet Rx Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_RX_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_RX_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_RX_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_INTR_EVT_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_INTR_EVT_SHIFT (6U)
/*! trig_intr_evt - Trigger Interrupt Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. If timer_mode is BIS timer mode, bis_anchr_intr will trigger, otherwise, cis_anchr_intr will.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_INTR_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_INTR_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_TRIG_INTR_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_SYNC_DELAY_INTR_EN_MASK (0x100U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_SYNC_DELAY_INTR_EN_SHIFT (8U)
/*! sync_delay_intr_en - Trigger Interrupt Event Upon Sync_Dly_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. If timer_mode is BIS timer mode, big_sync_delay_intr will trigger, otherwise, cig_sync_delay_intr will.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_SYNC_DELAY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_SYNC_DELAY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_SYNC_DELAY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_TIME_MASK (0x1FF0000U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_TIME_SHIFT (16U)
/*! early_intr_time - Early Interrupt Assertion Time */
#define BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_EN_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_EN_SHIFT (28U)
/*! early_intr_en - Enable Early Interrupt Assertion For bis_anchr_intr or cis_anchr_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the bis_anchr_intr or cis_anchr_intr will be asserted ealier than anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_0_EARLY_INTR_EN_MASK)
/*! @} */

/*! @name BLE_REG_PST_STS_0 - Periodic SW Timer 0: Status */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_STS_0_CURR_BIS_MASK (0x1FU)
#define BLE2_REG_BLE_REG_PST_STS_0_CURR_BIS_SHIFT (0U)
/*! curr_bis - Current Active BIS/CIS Number */
#define BLE2_REG_BLE_REG_PST_STS_0_CURR_BIS(x)   (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_CURR_BIS_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_CURR_BIS_MASK)

#define BLE2_REG_BLE_REG_PST_STS_0_BIS_ANCHR_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_STS_0_BIS_ANCHR_INTR_SHIFT (5U)
/*! bis_anchr_intr - BIS Anchor Point Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_0_BIS_ANCHR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_BIS_ANCHR_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_BIS_ANCHR_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_0_CIS_ANCHR_INTR_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_STS_0_CIS_ANCHR_INTR_SHIFT (6U)
/*! cis_anchr_intr - CIS Anchor Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_0_CIS_ANCHR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_CIS_ANCHR_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_CIS_ANCHR_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_0_CURR_SUBEVT_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_PST_STS_0_CURR_SUBEVT_SHIFT (8U)
/*! curr_subevt - Current Active Subevent Number */
#define BLE2_REG_BLE_REG_PST_STS_0_CURR_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_CURR_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_CURR_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_STS_0_SUB_EVENT_INTR_MASK (0x2000U)
#define BLE2_REG_BLE_REG_PST_STS_0_SUB_EVENT_INTR_SHIFT (13U)
/*! sub_event_intr - Subevent Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_0_SUB_EVENT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_SUB_EVENT_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_SUB_EVENT_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_0_CTRL_SUBEVT_INTR_MASK (0x4000U)
#define BLE2_REG_BLE_REG_PST_STS_0_CTRL_SUBEVT_INTR_SHIFT (14U)
/*! ctrl_subevt_intr - Control Subevent Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_0_CTRL_SUBEVT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_CTRL_SUBEVT_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_CTRL_SUBEVT_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_0_BIG_SYNC_DELAY_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_PST_STS_0_BIG_SYNC_DELAY_INTR_SHIFT (16U)
/*! big_sync_delay_intr - BIG_Sync_Delay Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_0_BIG_SYNC_DELAY_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_BIG_SYNC_DELAY_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_BIG_SYNC_DELAY_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_0_CIG_SYNC_DELAY_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_PST_STS_0_CIG_SYNC_DELAY_INTR_SHIFT (17U)
/*! cig_sync_delay_intr - CIG_Sync_Delay Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_0_CIG_SYNC_DELAY_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_0_CIG_SYNC_DELAY_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_0_CIG_SYNC_DELAY_INTR_MASK)
/*! @} */

/*! @name BLE_REG_PST_FRST_ANCHR_0 - Periodic SW Timer 0: First Anchor */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_0_FRST_ANCHR_NAT_CLK_VAL_MASK (0xFFFFFFFU)
#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_0_FRST_ANCHR_NAT_CLK_VAL_SHIFT (0U)
/*! frst_anchr_nat_clk_val - First Anchor Native Clock Value */
#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_0_FRST_ANCHR_NAT_CLK_VAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_FRST_ANCHR_0_FRST_ANCHR_NAT_CLK_VAL_SHIFT)) & BLE2_REG_BLE_REG_PST_FRST_ANCHR_0_FRST_ANCHR_NAT_CLK_VAL_MASK)
/*! @} */

/*! @name BLE_REG_PST_ANCHR_OFST_0 - Periodic SW Timer 0: First Anchor Offset */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_FRST_ANCHR_START_TIME_MASK (0x1FFU)
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_FRST_ANCHR_START_TIME_SHIFT (0U)
/*! frst_anchr_start_time - First Anchor Start Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_FRST_ANCHR_START_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_FRST_ANCHR_START_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_FRST_ANCHR_START_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_CURR_ANCHR_START_TIME_MASK (0x1FF0000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_CURR_ANCHR_START_TIME_SHIFT (16U)
/*! curr_anchr_start_time - Current Anchor Start Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_CURR_ANCHR_START_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_CURR_ANCHR_START_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_OFST_0_CURR_ANCHR_START_TIME_MASK)
/*! @} */

/*! @name BLE_REG_PST_ANCHR_ADJ_0 - Periodic SW Timer 0: Anchor Adjustment */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ANCHR_CORR_TIME_MASK (0x3FFU)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ANCHR_CORR_TIME_SHIFT (0U)
/*! anchr_corr_time - Anchor Point To Correlation Hit Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ANCHR_CORR_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ANCHR_CORR_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ANCHR_CORR_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_OFST_MASK (0x3F0000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_OFST_SHIFT (16U)
/*! adj_ast_ofst - Adjusted Anchor Start Time Offset */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_OFST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_OFST_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_OFST_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_DIR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_DIR_SHIFT (24U)
/*! adj_ast_dir - Adjusted Anchor Start Time Direction
 *  0b0..Substract adj_ast_ofst from ISO_Intvl_Tmr value counting toward next BIS/CIS event, effectively moving
 *       next BIS/CIS anchor point to a earlier time. This is used when the averaged anchr_corr_time value is
 *       gradually decreasing, indicating the slave device's local clock is drifting slower.
 *  0b1..Add adj_ast_ofst to ISO_Intvl_Tmr value counting toward next BIS/CIS event, effectively delaying next
 *       BIS/CIS anchor point to a later time. This is used when the averaged anchr_corr_time value is gradually
 *       increasing, indicating the slave device's local clock is drifting faster.
 */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_DIR_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_0_ADJ_AST_DIR_MASK)
/*! @} */

/*! @name BLE_REG_PST_INTVL_0 - Periodic SW Timer 0: ISO Interval */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_INTVL_0_ISO_INTERVAL_MASK (0xFFFU)
#define BLE2_REG_BLE_REG_PST_INTVL_0_ISO_INTERVAL_SHIFT (0U)
/*! iso_interval - Configure ISO Interval Time */
#define BLE2_REG_BLE_REG_PST_INTVL_0_ISO_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_0_ISO_INTERVAL_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_0_ISO_INTERVAL_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_0_CURR_ISO_INTVL_TMR_MASK (0x3FFF0000U)
#define BLE2_REG_BLE_REG_PST_INTVL_0_CURR_ISO_INTVL_TMR_SHIFT (16U)
/*! curr_iso_intvl_tmr - Current ISO_Intvl_Tmr Timer Value */
#define BLE2_REG_BLE_REG_PST_INTVL_0_CURR_ISO_INTVL_TMR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_0_CURR_ISO_INTVL_TMR_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_0_CURR_ISO_INTVL_TMR_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_0_BIT15_0_READ_MODE_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_PST_INTVL_0_BIT15_0_READ_MODE_SHIFT (30U)
/*! bit15_0_read_mode - Bit[15:0] iso_interval field read back value
 *  0b0..iso_interval field will read back ISO_Interval time of BIS/CIS event being programmed. Unit is 1.25ms.
 *  0b1..iso_interval field will read back curr_iso_intvl_tmr_ofst[10:0] at the time of snapshot_iso_intvl_tmr
 *       command being programmed. Unit is 0.25 us.
 */
#define BLE2_REG_BLE_REG_PST_INTVL_0_BIT15_0_READ_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_0_BIT15_0_READ_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_0_BIT15_0_READ_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_0_SNAPSHOT_ISO_INTVL_TMR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_PST_INTVL_0_SNAPSHOT_ISO_INTVL_TMR_SHIFT (31U)
/*! snapshot_iso_intvl_tmr - Take a snapshot of ISO_Intvl_Tmr and offset counter value */
#define BLE2_REG_BLE_REG_PST_INTVL_0_SNAPSHOT_ISO_INTVL_TMR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_0_SNAPSHOT_ISO_INTVL_TMR_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_0_SNAPSHOT_ISO_INTVL_TMR_MASK)
/*! @} */

/*! @name BLE_REG_PST_SPC_0 - Periodic SW Timer 0: Spacing */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SPC_0_BIS_SPACING_MASK (0xFFFFFU)
#define BLE2_REG_BLE_REG_PST_SPC_0_BIS_SPACING_SHIFT (0U)
/*! bis_spacing - Configure BIS Spacing Time */
#define BLE2_REG_BLE_REG_PST_SPC_0_BIS_SPACING(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SPC_0_BIS_SPACING_SHIFT)) & BLE2_REG_BLE_REG_PST_SPC_0_BIS_SPACING_MASK)

#define BLE2_REG_BLE_REG_PST_SPC_0_NUM_BIS_MASK  (0x1F000000U)
#define BLE2_REG_BLE_REG_PST_SPC_0_NUM_BIS_SHIFT (24U)
/*! num_bis - Configure Number of BISes/CISes in BIG/CIG */
#define BLE2_REG_BLE_REG_PST_SPC_0_NUM_BIS(x)    (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SPC_0_NUM_BIS_SHIFT)) & BLE2_REG_BLE_REG_PST_SPC_0_NUM_BIS_MASK)
/*! @} */

/*! @name BLE_REG_PST_SEL_STRM_0 - Periodic SW Timer 0: Select Stream */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SEL_STRM_0_SEL_STREAM_MASK (0xFFFFFFFEU)
#define BLE2_REG_BLE_REG_PST_SEL_STRM_0_SEL_STREAM_SHIFT (1U)
/*! sel_stream - Select Active Streams */
#define BLE2_REG_BLE_REG_PST_SEL_STRM_0_SEL_STREAM(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SEL_STRM_0_SEL_STREAM_SHIFT)) & BLE2_REG_BLE_REG_PST_SEL_STRM_0_SEL_STREAM_MASK)
/*! @} */

/*! @name BLE_REG_PST_SYNC_DLY_0 - Periodic SW Timer 0: Group Sync Delay */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SYNC_DLY_0_SYNC_DELAY_MASK (0xFFFFFFU)
#define BLE2_REG_BLE_REG_PST_SYNC_DLY_0_SYNC_DELAY_SHIFT (0U)
/*! sync_delay - The BIG_Sync_Delay or CIG_Sync_Delay Time */
#define BLE2_REG_BLE_REG_PST_SYNC_DLY_0_SYNC_DELAY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SYNC_DLY_0_SYNC_DELAY_SHIFT)) & BLE2_REG_BLE_REG_PST_SYNC_DLY_0_SYNC_DELAY_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_CTRL_0 - Periodic SW Timer 0: SubEvent Control */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUB_TMR_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUB_TMR_EN_SHIFT (0U)
/*! sub_tmr_en - Enable Periodic SW Timer's Sub_Intvl_Tmr
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUB_TMR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUB_TMR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUB_TMR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_TX_SUBEVT_MASK (0x10U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_TX_SUBEVT_SHIFT (4U)
/*! trig_tx_subevt - Trigger a Packet Tx Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_TX_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_TX_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_TX_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_RX_SUBEVT_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_RX_SUBEVT_SHIFT (5U)
/*! trig_rx_subevt - Trigger a Packet Rx Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_RX_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_RX_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_RX_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_INTR_SUBEVT_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_INTR_SUBEVT_SHIFT (6U)
/*! trig_intr_subevt - Trigger Interrupt Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. Either sub_event_intr or ctrl_subevt_intr (if has_ctrl_subevt = 1) will trigger.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_INTR_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_INTR_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_0_TRIG_INTR_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUBEVT_EARLY_INTR_EN_MASK (0x100U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUBEVT_EARLY_INTR_EN_SHIFT (8U)
/*! subevt_early_intr_en - Enable Early Interrupt Assertion For sub_event_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the sub_event_intr will be asserted ealier than subevent anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUBEVT_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUBEVT_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_0_SUBEVT_EARLY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_CTRL_SUBEVT_EARLY_INTR_EN_MASK (0x200U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_CTRL_SUBEVT_EARLY_INTR_EN_SHIFT (9U)
/*! ctrl_subevt_early_intr_en - Enable Early Interrupt Assertion For ctrl_subevt_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the ctrl_subevt_intr will be asserted ealier than control subevent anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_CTRL_SUBEVT_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_0_CTRL_SUBEVT_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_0_CTRL_SUBEVT_EARLY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_HAS_CTRL_SUBEVT_MASK (0x10000U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_HAS_CTRL_SUBEVT_SHIFT (16U)
/*! has_ctrl_subevt - Configure To Have Control Subevent In BIS Event
 *  0b0..disable
 *  0b1..enable. Enalbing time must meet in order to have control subevent triggered in current BIS event. Only
 *       applicable in timer_mode = 0 (BIS timer mode).
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_0_HAS_CTRL_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_0_HAS_CTRL_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_0_HAS_CTRL_SUBEVT_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_INTVL_0 - Periodic SW Timer 0: SubEvent Interval */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_INTVL_0_SUB_INTERVAL_MASK (0xFFFFFU)
#define BLE2_REG_BLE_REG_PST_SE_INTVL_0_SUB_INTERVAL_SHIFT (0U)
/*! sub_interval - Configure Subevent Interval Time */
#define BLE2_REG_BLE_REG_PST_SE_INTVL_0_SUB_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_INTVL_0_SUB_INTERVAL_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_INTVL_0_SUB_INTERVAL_MASK)

#define BLE2_REG_BLE_REG_PST_SE_INTVL_0_NSE_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_PST_SE_INTVL_0_NSE_SHIFT (24U)
/*! nse - Configure Number of Subevents Per BIS/CIS Event */
#define BLE2_REG_BLE_REG_PST_SE_INTVL_0_NSE(x)   (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_INTVL_0_NSE_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_INTVL_0_NSE_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_DIS_0 - Periodic SW Timer 0: SubEvent Disable */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_DIS_0_DIS_REMAIN_SUBEVT_MASK (0xFFFFFFFEU)
#define BLE2_REG_BLE_REG_PST_SE_DIS_0_DIS_REMAIN_SUBEVT_SHIFT (1U)
/*! dis_remain_subevt - Disable Remaining Subevents */
#define BLE2_REG_BLE_REG_PST_SE_DIS_0_DIS_REMAIN_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_DIS_0_DIS_REMAIN_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_DIS_0_DIS_REMAIN_SUBEVT_MASK)
/*! @} */

/*! @name BLE_REG_PST_CTRL_1 - Periodic SW Timer 1: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_CTRL_1_ISO_TMR_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_ISO_TMR_EN_SHIFT (0U)
/*! iso_tmr_en - Enable Periodic SW Timer's ISO_Intvl_Tmr/BIS_Spc_Tmr
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_ISO_TMR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_ISO_TMR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_ISO_TMR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_TIMER_MODE_MASK (0x2U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_TIMER_MODE_SHIFT (1U)
/*! timer_mode - Configure Peridodic SW Timer Timer Mode
 *  0b0..configure to BIS timer mode
 *  0b1..configure to CIS timer mode
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_TIMER_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_TIMER_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_TIMER_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_SEQ_MODE_MASK (0x4U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_SEQ_MODE_SHIFT (2U)
/*! seq_mode - Configure Multiple BISes/CISes To Sequential Or Interleaved Arrangement
 *  0b0..configure to interleaved arrangement
 *  0b1..configure to sequential arrangement
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_SEQ_MODE(x)  (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_SEQ_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_SEQ_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_TX_EVT_MASK (0x10U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_TX_EVT_SHIFT (4U)
/*! trig_tx_evt - Trigger a Packet Tx Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_TX_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_TX_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_TX_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_RX_EVT_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_RX_EVT_SHIFT (5U)
/*! trig_rx_evt - Trigger a Packet Rx Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_RX_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_RX_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_RX_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_INTR_EVT_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_INTR_EVT_SHIFT (6U)
/*! trig_intr_evt - Trigger Interrupt Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. If timer_mode is BIS timer mode, bis_anchr_intr will trigger, otherwise, cis_anchr_intr will.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_INTR_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_INTR_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_TRIG_INTR_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_SYNC_DELAY_INTR_EN_MASK (0x100U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_SYNC_DELAY_INTR_EN_SHIFT (8U)
/*! sync_delay_intr_en - Trigger Interrupt Event Upon Sync_Dly_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. If timer_mode is BIS timer mode, big_sync_delay_intr will trigger, otherwise, cig_sync_delay_intr will.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_SYNC_DELAY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_SYNC_DELAY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_SYNC_DELAY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_TIME_MASK (0x1FF0000U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_TIME_SHIFT (16U)
/*! early_intr_time - Early Interrupt Assertion Time */
#define BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_EN_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_EN_SHIFT (28U)
/*! early_intr_en - Enable Early Interrupt Assertion For bis_anchr_intr or cis_anchr_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the bis_anchr_intr or cis_anchr_intr will be asserted ealier than anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_1_EARLY_INTR_EN_MASK)
/*! @} */

/*! @name BLE_REG_PST_STS_1 - Periodic SW Timer 1: Status */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_STS_1_CURR_BIS_MASK (0x1FU)
#define BLE2_REG_BLE_REG_PST_STS_1_CURR_BIS_SHIFT (0U)
/*! curr_bis - Current Active BIS/CIS Number */
#define BLE2_REG_BLE_REG_PST_STS_1_CURR_BIS(x)   (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_CURR_BIS_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_CURR_BIS_MASK)

#define BLE2_REG_BLE_REG_PST_STS_1_BIS_ANCHR_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_STS_1_BIS_ANCHR_INTR_SHIFT (5U)
/*! bis_anchr_intr - BIS Anchor Point Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_1_BIS_ANCHR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_BIS_ANCHR_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_BIS_ANCHR_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_1_CIS_ANCHR_INTR_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_STS_1_CIS_ANCHR_INTR_SHIFT (6U)
/*! cis_anchr_intr - CIS Anchor Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_1_CIS_ANCHR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_CIS_ANCHR_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_CIS_ANCHR_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_1_CURR_SUBEVT_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_PST_STS_1_CURR_SUBEVT_SHIFT (8U)
/*! curr_subevt - Current Active Subevent Number */
#define BLE2_REG_BLE_REG_PST_STS_1_CURR_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_CURR_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_CURR_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_STS_1_SUB_EVENT_INTR_MASK (0x2000U)
#define BLE2_REG_BLE_REG_PST_STS_1_SUB_EVENT_INTR_SHIFT (13U)
/*! sub_event_intr - Subevent Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_1_SUB_EVENT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_SUB_EVENT_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_SUB_EVENT_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_1_CTRL_SUBEVT_INTR_MASK (0x4000U)
#define BLE2_REG_BLE_REG_PST_STS_1_CTRL_SUBEVT_INTR_SHIFT (14U)
/*! ctrl_subevt_intr - Control Subevent Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_1_CTRL_SUBEVT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_CTRL_SUBEVT_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_CTRL_SUBEVT_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_1_BIG_SYNC_DELAY_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_PST_STS_1_BIG_SYNC_DELAY_INTR_SHIFT (16U)
/*! big_sync_delay_intr - BIG_Sync_Delay Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_1_BIG_SYNC_DELAY_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_BIG_SYNC_DELAY_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_BIG_SYNC_DELAY_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_1_CIG_SYNC_DELAY_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_PST_STS_1_CIG_SYNC_DELAY_INTR_SHIFT (17U)
/*! cig_sync_delay_intr - CIG_Sync_Delay Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_1_CIG_SYNC_DELAY_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_1_CIG_SYNC_DELAY_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_1_CIG_SYNC_DELAY_INTR_MASK)
/*! @} */

/*! @name BLE_REG_PST_FRST_ANCHR_1 - Periodic SW Timer 1: First Anchor */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_1_FRST_ANCHR_NAT_CLK_VAL_MASK (0xFFFFFFFU)
#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_1_FRST_ANCHR_NAT_CLK_VAL_SHIFT (0U)
/*! frst_anchr_nat_clk_val - First Anchor Native Clock Value */
#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_1_FRST_ANCHR_NAT_CLK_VAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_FRST_ANCHR_1_FRST_ANCHR_NAT_CLK_VAL_SHIFT)) & BLE2_REG_BLE_REG_PST_FRST_ANCHR_1_FRST_ANCHR_NAT_CLK_VAL_MASK)
/*! @} */

/*! @name BLE_REG_PST_ANCHR_OFST_1 - Periodic SW Timer 1: First Anchor Offset */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_FRST_ANCHR_START_TIME_MASK (0x1FFU)
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_FRST_ANCHR_START_TIME_SHIFT (0U)
/*! frst_anchr_start_time - First Anchor Start Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_FRST_ANCHR_START_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_FRST_ANCHR_START_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_FRST_ANCHR_START_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_CURR_ANCHR_START_TIME_MASK (0x1FF0000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_CURR_ANCHR_START_TIME_SHIFT (16U)
/*! curr_anchr_start_time - Current Anchor Start Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_CURR_ANCHR_START_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_CURR_ANCHR_START_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_OFST_1_CURR_ANCHR_START_TIME_MASK)
/*! @} */

/*! @name BLE_REG_PST_ANCHR_ADJ_1 - Periodic SW Timer 1: Anchor Adjustment */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ANCHR_CORR_TIME_MASK (0x3FFU)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ANCHR_CORR_TIME_SHIFT (0U)
/*! anchr_corr_time - Anchor Point To Correlation Hit Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ANCHR_CORR_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ANCHR_CORR_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ANCHR_CORR_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_OFST_MASK (0x3F0000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_OFST_SHIFT (16U)
/*! adj_ast_ofst - Adjusted Anchor Start Time Offset */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_OFST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_OFST_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_OFST_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_DIR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_DIR_SHIFT (24U)
/*! adj_ast_dir - Adjusted Anchor Start Time Direction
 *  0b0..Substract adj_ast_ofst from ISO_Intvl_Tmr value counting toward next BIS/CIS event, effectively moving
 *       next BIS/CIS anchor point to a earlier time. This is used when the averaged anchr_corr_time value is
 *       gradually decreasing, indicating the slave device's local clock is drifting slower.
 *  0b1..Add adj_ast_ofst to ISO_Intvl_Tmr value counting toward next BIS/CIS event, effectively delaying next
 *       BIS/CIS anchor point to a later time. This is used when the averaged anchr_corr_time value is gradually
 *       increasing, indicating the slave device's local clock is drifting faster.
 */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_DIR_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_1_ADJ_AST_DIR_MASK)
/*! @} */

/*! @name BLE_REG_PST_INTVL_1 - Periodic SW Timer 1: ISO Interval */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_INTVL_1_ISO_INTERVAL_MASK (0xFFFU)
#define BLE2_REG_BLE_REG_PST_INTVL_1_ISO_INTERVAL_SHIFT (0U)
/*! iso_interval - Configure ISO Interval Time */
#define BLE2_REG_BLE_REG_PST_INTVL_1_ISO_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_1_ISO_INTERVAL_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_1_ISO_INTERVAL_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_1_CURR_ISO_INTVL_TMR_MASK (0x3FFF0000U)
#define BLE2_REG_BLE_REG_PST_INTVL_1_CURR_ISO_INTVL_TMR_SHIFT (16U)
/*! curr_iso_intvl_tmr - Current ISO_Intvl_Tmr Timer Value */
#define BLE2_REG_BLE_REG_PST_INTVL_1_CURR_ISO_INTVL_TMR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_1_CURR_ISO_INTVL_TMR_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_1_CURR_ISO_INTVL_TMR_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_1_BIT15_0_READ_MODE_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_PST_INTVL_1_BIT15_0_READ_MODE_SHIFT (30U)
/*! bit15_0_read_mode - Bit[15:0] iso_interval field read back value
 *  0b0..iso_interval field will read back ISO_Interval time of BIS/CIS event being programmed. Unit is 1.25ms.
 *  0b1..iso_interval field will read back curr_iso_intvl_tmr_ofst[10:0] at the time of snapshot_iso_intvl_tmr
 *       command being programmed. Unit is 0.25 us.
 */
#define BLE2_REG_BLE_REG_PST_INTVL_1_BIT15_0_READ_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_1_BIT15_0_READ_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_1_BIT15_0_READ_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_1_SNAPSHOT_ISO_INTVL_TMR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_PST_INTVL_1_SNAPSHOT_ISO_INTVL_TMR_SHIFT (31U)
/*! snapshot_iso_intvl_tmr - Take a snapshot of ISO_Intvl_Tmr and offset counter value */
#define BLE2_REG_BLE_REG_PST_INTVL_1_SNAPSHOT_ISO_INTVL_TMR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_1_SNAPSHOT_ISO_INTVL_TMR_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_1_SNAPSHOT_ISO_INTVL_TMR_MASK)
/*! @} */

/*! @name BLE_REG_PST_SPC_1 - Periodic SW Timer 1: Spacing */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SPC_1_BIS_SPACING_MASK (0xFFFFFU)
#define BLE2_REG_BLE_REG_PST_SPC_1_BIS_SPACING_SHIFT (0U)
/*! bis_spacing - Configure BIS Spacing Time */
#define BLE2_REG_BLE_REG_PST_SPC_1_BIS_SPACING(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SPC_1_BIS_SPACING_SHIFT)) & BLE2_REG_BLE_REG_PST_SPC_1_BIS_SPACING_MASK)

#define BLE2_REG_BLE_REG_PST_SPC_1_NUM_BIS_MASK  (0x1F000000U)
#define BLE2_REG_BLE_REG_PST_SPC_1_NUM_BIS_SHIFT (24U)
/*! num_bis - Configure Number of BISes/CISes in BIG/CIG */
#define BLE2_REG_BLE_REG_PST_SPC_1_NUM_BIS(x)    (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SPC_1_NUM_BIS_SHIFT)) & BLE2_REG_BLE_REG_PST_SPC_1_NUM_BIS_MASK)
/*! @} */

/*! @name BLE_REG_PST_SEL_STRM_1 - Periodic SW Timer 1: Select Stream */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SEL_STRM_1_SEL_STREAM_MASK (0xFFFFFFFEU)
#define BLE2_REG_BLE_REG_PST_SEL_STRM_1_SEL_STREAM_SHIFT (1U)
/*! sel_stream - Select Active Streams */
#define BLE2_REG_BLE_REG_PST_SEL_STRM_1_SEL_STREAM(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SEL_STRM_1_SEL_STREAM_SHIFT)) & BLE2_REG_BLE_REG_PST_SEL_STRM_1_SEL_STREAM_MASK)
/*! @} */

/*! @name BLE_REG_PST_SYNC_DLY_1 - Periodic SW Timer 1: Group Sync Delay */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SYNC_DLY_1_SYNC_DELAY_MASK (0xFFFFFFU)
#define BLE2_REG_BLE_REG_PST_SYNC_DLY_1_SYNC_DELAY_SHIFT (0U)
/*! sync_delay - The BIG_Sync_Delay or CIG_Sync_Delay Time */
#define BLE2_REG_BLE_REG_PST_SYNC_DLY_1_SYNC_DELAY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SYNC_DLY_1_SYNC_DELAY_SHIFT)) & BLE2_REG_BLE_REG_PST_SYNC_DLY_1_SYNC_DELAY_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_CTRL_1 - Periodic SW Timer 1: SubEvent Control */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUB_TMR_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUB_TMR_EN_SHIFT (0U)
/*! sub_tmr_en - Enable Periodic SW Timer's Sub_Intvl_Tmr
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUB_TMR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUB_TMR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUB_TMR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_TX_SUBEVT_MASK (0x10U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_TX_SUBEVT_SHIFT (4U)
/*! trig_tx_subevt - Trigger a Packet Tx Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_TX_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_TX_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_TX_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_RX_SUBEVT_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_RX_SUBEVT_SHIFT (5U)
/*! trig_rx_subevt - Trigger a Packet Rx Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_RX_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_RX_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_RX_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_INTR_SUBEVT_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_INTR_SUBEVT_SHIFT (6U)
/*! trig_intr_subevt - Trigger Interrupt Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. Either sub_event_intr or ctrl_subevt_intr (if has_ctrl_subevt = 1) will trigger.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_INTR_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_INTR_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_1_TRIG_INTR_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUBEVT_EARLY_INTR_EN_MASK (0x100U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUBEVT_EARLY_INTR_EN_SHIFT (8U)
/*! subevt_early_intr_en - Enable Early Interrupt Assertion For sub_event_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the sub_event_intr will be asserted ealier than subevent anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUBEVT_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUBEVT_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_1_SUBEVT_EARLY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_CTRL_SUBEVT_EARLY_INTR_EN_MASK (0x200U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_CTRL_SUBEVT_EARLY_INTR_EN_SHIFT (9U)
/*! ctrl_subevt_early_intr_en - Enable Early Interrupt Assertion For ctrl_subevt_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the ctrl_subevt_intr will be asserted ealier than control subevent anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_CTRL_SUBEVT_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_1_CTRL_SUBEVT_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_1_CTRL_SUBEVT_EARLY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_HAS_CTRL_SUBEVT_MASK (0x10000U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_HAS_CTRL_SUBEVT_SHIFT (16U)
/*! has_ctrl_subevt - Configure To Have Control Subevent In BIS Event
 *  0b0..disable
 *  0b1..enable. Enalbing time must meet in order to have control subevent triggered in current BIS event. Only
 *       applicable in timer_mode = 0 (BIS timer mode).
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_1_HAS_CTRL_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_1_HAS_CTRL_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_1_HAS_CTRL_SUBEVT_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_INTVL_1 - Periodic SW Timer 1: SubEvent Interval */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_INTVL_1_SUB_INTERVAL_MASK (0xFFFFFU)
#define BLE2_REG_BLE_REG_PST_SE_INTVL_1_SUB_INTERVAL_SHIFT (0U)
/*! sub_interval - Configure Subevent Interval Time */
#define BLE2_REG_BLE_REG_PST_SE_INTVL_1_SUB_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_INTVL_1_SUB_INTERVAL_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_INTVL_1_SUB_INTERVAL_MASK)

#define BLE2_REG_BLE_REG_PST_SE_INTVL_1_NSE_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_PST_SE_INTVL_1_NSE_SHIFT (24U)
/*! nse - Configure Number of Subevents Per BIS/CIS Event */
#define BLE2_REG_BLE_REG_PST_SE_INTVL_1_NSE(x)   (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_INTVL_1_NSE_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_INTVL_1_NSE_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_DIS_1 - Periodic SW Timer 1: SubEvent Disable */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_DIS_1_DIS_REMAIN_SUBEVT_MASK (0xFFFFFFFEU)
#define BLE2_REG_BLE_REG_PST_SE_DIS_1_DIS_REMAIN_SUBEVT_SHIFT (1U)
/*! dis_remain_subevt - Disable Remaining Subevents */
#define BLE2_REG_BLE_REG_PST_SE_DIS_1_DIS_REMAIN_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_DIS_1_DIS_REMAIN_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_DIS_1_DIS_REMAIN_SUBEVT_MASK)
/*! @} */

/*! @name BLE_REG_PST_CTRL_2 - Periodic SW Timer 2: Control */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_CTRL_2_ISO_TMR_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_ISO_TMR_EN_SHIFT (0U)
/*! iso_tmr_en - Enable Periodic SW Timer's ISO_Intvl_Tmr/BIS_Spc_Tmr
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_ISO_TMR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_ISO_TMR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_ISO_TMR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_TIMER_MODE_MASK (0x2U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_TIMER_MODE_SHIFT (1U)
/*! timer_mode - Configure Peridodic SW Timer Timer Mode
 *  0b0..configure to BIS timer mode
 *  0b1..configure to CIS timer mode
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_TIMER_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_TIMER_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_TIMER_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_SEQ_MODE_MASK (0x4U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_SEQ_MODE_SHIFT (2U)
/*! seq_mode - Configure Multiple BISes/CISes To Sequential Or Interleaved Arrangement
 *  0b0..configure to interleaved arrangement
 *  0b1..configure to sequential arrangement
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_SEQ_MODE(x)  (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_SEQ_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_SEQ_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_TX_EVT_MASK (0x10U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_TX_EVT_SHIFT (4U)
/*! trig_tx_evt - Trigger a Packet Tx Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_TX_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_TX_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_TX_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_RX_EVT_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_RX_EVT_SHIFT (5U)
/*! trig_rx_evt - Trigger a Packet Rx Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_RX_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_RX_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_RX_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_INTR_EVT_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_INTR_EVT_SHIFT (6U)
/*! trig_intr_evt - Trigger Interrupt Event Upon ISO_Intvl_Tmr/BIS_Spc_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. If timer_mode is BIS timer mode, bis_anchr_intr will trigger, otherwise, cis_anchr_intr will.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_INTR_EVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_INTR_EVT_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_TRIG_INTR_EVT_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_SYNC_DELAY_INTR_EN_MASK (0x100U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_SYNC_DELAY_INTR_EN_SHIFT (8U)
/*! sync_delay_intr_en - Trigger Interrupt Event Upon Sync_Dly_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. If timer_mode is BIS timer mode, big_sync_delay_intr will trigger, otherwise, cig_sync_delay_intr will.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_SYNC_DELAY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_SYNC_DELAY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_SYNC_DELAY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_TIME_MASK (0x1FF0000U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_TIME_SHIFT (16U)
/*! early_intr_time - Early Interrupt Assertion Time */
#define BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_EN_MASK (0x10000000U)
#define BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_EN_SHIFT (28U)
/*! early_intr_en - Enable Early Interrupt Assertion For bis_anchr_intr or cis_anchr_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the bis_anchr_intr or cis_anchr_intr will be asserted ealier than anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_CTRL_2_EARLY_INTR_EN_MASK)
/*! @} */

/*! @name BLE_REG_PST_STS_2 - Periodic SW Timer 2: Status */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_STS_2_CURR_BIS_MASK (0x1FU)
#define BLE2_REG_BLE_REG_PST_STS_2_CURR_BIS_SHIFT (0U)
/*! curr_bis - Current Active BIS/CIS Number */
#define BLE2_REG_BLE_REG_PST_STS_2_CURR_BIS(x)   (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_CURR_BIS_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_CURR_BIS_MASK)

#define BLE2_REG_BLE_REG_PST_STS_2_BIS_ANCHR_INTR_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_STS_2_BIS_ANCHR_INTR_SHIFT (5U)
/*! bis_anchr_intr - BIS Anchor Point Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_2_BIS_ANCHR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_BIS_ANCHR_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_BIS_ANCHR_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_2_CIS_ANCHR_INTR_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_STS_2_CIS_ANCHR_INTR_SHIFT (6U)
/*! cis_anchr_intr - CIS Anchor Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_2_CIS_ANCHR_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_CIS_ANCHR_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_CIS_ANCHR_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_2_CURR_SUBEVT_MASK (0x1F00U)
#define BLE2_REG_BLE_REG_PST_STS_2_CURR_SUBEVT_SHIFT (8U)
/*! curr_subevt - Current Active Subevent Number */
#define BLE2_REG_BLE_REG_PST_STS_2_CURR_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_CURR_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_CURR_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_STS_2_SUB_EVENT_INTR_MASK (0x2000U)
#define BLE2_REG_BLE_REG_PST_STS_2_SUB_EVENT_INTR_SHIFT (13U)
/*! sub_event_intr - Subevent Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_2_SUB_EVENT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_SUB_EVENT_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_SUB_EVENT_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_2_CTRL_SUBEVT_INTR_MASK (0x4000U)
#define BLE2_REG_BLE_REG_PST_STS_2_CTRL_SUBEVT_INTR_SHIFT (14U)
/*! ctrl_subevt_intr - Control Subevent Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_2_CTRL_SUBEVT_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_CTRL_SUBEVT_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_CTRL_SUBEVT_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_2_BIG_SYNC_DELAY_INTR_MASK (0x10000U)
#define BLE2_REG_BLE_REG_PST_STS_2_BIG_SYNC_DELAY_INTR_SHIFT (16U)
/*! big_sync_delay_intr - BIG_Sync_Delay Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_2_BIG_SYNC_DELAY_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_BIG_SYNC_DELAY_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_BIG_SYNC_DELAY_INTR_MASK)

#define BLE2_REG_BLE_REG_PST_STS_2_CIG_SYNC_DELAY_INTR_MASK (0x20000U)
#define BLE2_REG_BLE_REG_PST_STS_2_CIG_SYNC_DELAY_INTR_SHIFT (17U)
/*! cig_sync_delay_intr - CIG_Sync_Delay Interrupt */
#define BLE2_REG_BLE_REG_PST_STS_2_CIG_SYNC_DELAY_INTR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_STS_2_CIG_SYNC_DELAY_INTR_SHIFT)) & BLE2_REG_BLE_REG_PST_STS_2_CIG_SYNC_DELAY_INTR_MASK)
/*! @} */

/*! @name BLE_REG_PST_FRST_ANCHR_2 - Periodic SW Timer 2: First Anchor */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_2_FRST_ANCHR_NAT_CLK_VAL_MASK (0xFFFFFFFU)
#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_2_FRST_ANCHR_NAT_CLK_VAL_SHIFT (0U)
/*! frst_anchr_nat_clk_val - First Anchor Native Clock Value */
#define BLE2_REG_BLE_REG_PST_FRST_ANCHR_2_FRST_ANCHR_NAT_CLK_VAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_FRST_ANCHR_2_FRST_ANCHR_NAT_CLK_VAL_SHIFT)) & BLE2_REG_BLE_REG_PST_FRST_ANCHR_2_FRST_ANCHR_NAT_CLK_VAL_MASK)
/*! @} */

/*! @name BLE_REG_PST_ANCHR_OFST_2 - Periodic SW Timer 2: First Anchor Offset */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_FRST_ANCHR_START_TIME_MASK (0x1FFU)
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_FRST_ANCHR_START_TIME_SHIFT (0U)
/*! frst_anchr_start_time - First Anchor Start Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_FRST_ANCHR_START_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_FRST_ANCHR_START_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_FRST_ANCHR_START_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_CURR_ANCHR_START_TIME_MASK (0x1FF0000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_CURR_ANCHR_START_TIME_SHIFT (16U)
/*! curr_anchr_start_time - Current Anchor Start Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_CURR_ANCHR_START_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_CURR_ANCHR_START_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_OFST_2_CURR_ANCHR_START_TIME_MASK)
/*! @} */

/*! @name BLE_REG_PST_ANCHR_ADJ_2 - Periodic SW Timer 2: Anchor Adjustment */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ANCHR_CORR_TIME_MASK (0x3FFU)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ANCHR_CORR_TIME_SHIFT (0U)
/*! anchr_corr_time - Anchor Point To Correlation Hit Time */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ANCHR_CORR_TIME(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ANCHR_CORR_TIME_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ANCHR_CORR_TIME_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_OFST_MASK (0x3F0000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_OFST_SHIFT (16U)
/*! adj_ast_ofst - Adjusted Anchor Start Time Offset */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_OFST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_OFST_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_OFST_MASK)

#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_DIR_MASK (0x1000000U)
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_DIR_SHIFT (24U)
/*! adj_ast_dir - Adjusted Anchor Start Time Direction
 *  0b0..Substract adj_ast_ofst from ISO_Intvl_Tmr value counting toward next BIS/CIS event, effectively moving
 *       next BIS/CIS anchor point to a earlier time. This is used when the averaged anchr_corr_time value is
 *       gradually decreasing, indicating the slave device's local clock is drifting slower.
 *  0b1..Add adj_ast_ofst to ISO_Intvl_Tmr value counting toward next BIS/CIS event, effectively delaying next
 *       BIS/CIS anchor point to a later time. This is used when the averaged anchr_corr_time value is gradually
 *       increasing, indicating the slave device's local clock is drifting faster.
 */
#define BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_DIR_SHIFT)) & BLE2_REG_BLE_REG_PST_ANCHR_ADJ_2_ADJ_AST_DIR_MASK)
/*! @} */

/*! @name BLE_REG_PST_INTVL_2 - Periodic SW Timer 2: ISO Interval */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_INTVL_2_ISO_INTERVAL_MASK (0xFFFU)
#define BLE2_REG_BLE_REG_PST_INTVL_2_ISO_INTERVAL_SHIFT (0U)
/*! iso_interval - Configure ISO Interval Time */
#define BLE2_REG_BLE_REG_PST_INTVL_2_ISO_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_2_ISO_INTERVAL_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_2_ISO_INTERVAL_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_2_CURR_ISO_INTVL_TMR_MASK (0x3FFF0000U)
#define BLE2_REG_BLE_REG_PST_INTVL_2_CURR_ISO_INTVL_TMR_SHIFT (16U)
/*! curr_iso_intvl_tmr - Current ISO_Intvl_Tmr Timer Value */
#define BLE2_REG_BLE_REG_PST_INTVL_2_CURR_ISO_INTVL_TMR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_2_CURR_ISO_INTVL_TMR_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_2_CURR_ISO_INTVL_TMR_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_2_BIT15_0_READ_MODE_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_PST_INTVL_2_BIT15_0_READ_MODE_SHIFT (30U)
/*! bit15_0_read_mode - Bit[15:0] iso_interval field read back value
 *  0b0..iso_interval field will read back ISO_Interval time of BIS/CIS event being programmed. Unit is 1.25ms.
 *  0b1..iso_interval field will read back curr_iso_intvl_tmr_ofst[10:0] at the time of snapshot_iso_intvl_tmr
 *       command being programmed. Unit is 0.25 us.
 */
#define BLE2_REG_BLE_REG_PST_INTVL_2_BIT15_0_READ_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_2_BIT15_0_READ_MODE_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_2_BIT15_0_READ_MODE_MASK)

#define BLE2_REG_BLE_REG_PST_INTVL_2_SNAPSHOT_ISO_INTVL_TMR_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_PST_INTVL_2_SNAPSHOT_ISO_INTVL_TMR_SHIFT (31U)
/*! snapshot_iso_intvl_tmr - Take a snapshot of ISO_Intvl_Tmr and offset counter value */
#define BLE2_REG_BLE_REG_PST_INTVL_2_SNAPSHOT_ISO_INTVL_TMR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_INTVL_2_SNAPSHOT_ISO_INTVL_TMR_SHIFT)) & BLE2_REG_BLE_REG_PST_INTVL_2_SNAPSHOT_ISO_INTVL_TMR_MASK)
/*! @} */

/*! @name BLE_REG_PST_SPC_2 - Periodic SW Timer 2: Spacing */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SPC_2_BIS_SPACING_MASK (0xFFFFFU)
#define BLE2_REG_BLE_REG_PST_SPC_2_BIS_SPACING_SHIFT (0U)
/*! bis_spacing - Configure BIS Spacing Time */
#define BLE2_REG_BLE_REG_PST_SPC_2_BIS_SPACING(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SPC_2_BIS_SPACING_SHIFT)) & BLE2_REG_BLE_REG_PST_SPC_2_BIS_SPACING_MASK)

#define BLE2_REG_BLE_REG_PST_SPC_2_NUM_BIS_MASK  (0x1F000000U)
#define BLE2_REG_BLE_REG_PST_SPC_2_NUM_BIS_SHIFT (24U)
/*! num_bis - Configure Number of BISes/CISes in BIG/CIG */
#define BLE2_REG_BLE_REG_PST_SPC_2_NUM_BIS(x)    (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SPC_2_NUM_BIS_SHIFT)) & BLE2_REG_BLE_REG_PST_SPC_2_NUM_BIS_MASK)
/*! @} */

/*! @name BLE_REG_PST_SEL_STRM_2 - Periodic SW Timer 2: Select Stream */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SEL_STRM_2_SEL_STREAM_MASK (0xFFFFFFFEU)
#define BLE2_REG_BLE_REG_PST_SEL_STRM_2_SEL_STREAM_SHIFT (1U)
/*! sel_stream - Select Active Streams */
#define BLE2_REG_BLE_REG_PST_SEL_STRM_2_SEL_STREAM(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SEL_STRM_2_SEL_STREAM_SHIFT)) & BLE2_REG_BLE_REG_PST_SEL_STRM_2_SEL_STREAM_MASK)
/*! @} */

/*! @name BLE_REG_PST_SYNC_DLY_2 - Periodic SW Timer 2: Group Sync Delay */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SYNC_DLY_2_SYNC_DELAY_MASK (0xFFFFFFU)
#define BLE2_REG_BLE_REG_PST_SYNC_DLY_2_SYNC_DELAY_SHIFT (0U)
/*! sync_delay - The BIG_Sync_Delay or CIG_Sync_Delay Time */
#define BLE2_REG_BLE_REG_PST_SYNC_DLY_2_SYNC_DELAY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SYNC_DLY_2_SYNC_DELAY_SHIFT)) & BLE2_REG_BLE_REG_PST_SYNC_DLY_2_SYNC_DELAY_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_CTRL_2 - Periodic SW Timer 2: SubEvent Control */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUB_TMR_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUB_TMR_EN_SHIFT (0U)
/*! sub_tmr_en - Enable Periodic SW Timer's Sub_Intvl_Tmr
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUB_TMR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUB_TMR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUB_TMR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_TX_SUBEVT_MASK (0x10U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_TX_SUBEVT_SHIFT (4U)
/*! trig_tx_subevt - Trigger a Packet Tx Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_TX_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_TX_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_TX_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_RX_SUBEVT_MASK (0x20U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_RX_SUBEVT_SHIFT (5U)
/*! trig_rx_subevt - Trigger a Packet Rx Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_RX_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_RX_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_RX_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_INTR_SUBEVT_MASK (0x40U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_INTR_SUBEVT_SHIFT (6U)
/*! trig_intr_subevt - Trigger Interrupt Event Upon Sub_Intvl_Tmr Timer Expiry
 *  0b0..disable
 *  0b1..enable. Either sub_event_intr or ctrl_subevt_intr (if has_ctrl_subevt = 1) will trigger.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_INTR_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_INTR_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_2_TRIG_INTR_SUBEVT_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUBEVT_EARLY_INTR_EN_MASK (0x100U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUBEVT_EARLY_INTR_EN_SHIFT (8U)
/*! subevt_early_intr_en - Enable Early Interrupt Assertion For sub_event_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the sub_event_intr will be asserted ealier than subevent anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUBEVT_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUBEVT_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_2_SUBEVT_EARLY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_CTRL_SUBEVT_EARLY_INTR_EN_MASK (0x200U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_CTRL_SUBEVT_EARLY_INTR_EN_SHIFT (9U)
/*! ctrl_subevt_early_intr_en - Enable Early Interrupt Assertion For ctrl_subevt_intr
 *  0b0..disable
 *  0b1..enable. When enabled, the ctrl_subevt_intr will be asserted ealier than control subevent anchor point by the specified early_intr_time time.
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_CTRL_SUBEVT_EARLY_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_2_CTRL_SUBEVT_EARLY_INTR_EN_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_2_CTRL_SUBEVT_EARLY_INTR_EN_MASK)

#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_HAS_CTRL_SUBEVT_MASK (0x10000U)
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_HAS_CTRL_SUBEVT_SHIFT (16U)
/*! has_ctrl_subevt - Configure To Have Control Subevent In BIS Event
 *  0b0..disable
 *  0b1..enable. Enalbing time must meet in order to have control subevent triggered in current BIS event. Only
 *       applicable in timer_mode = 0 (BIS timer mode).
 */
#define BLE2_REG_BLE_REG_PST_SE_CTRL_2_HAS_CTRL_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_CTRL_2_HAS_CTRL_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_CTRL_2_HAS_CTRL_SUBEVT_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_INTVL_2 - Periodic SW Timer 2: SubEvent Interval */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_INTVL_2_SUB_INTERVAL_MASK (0xFFFFFU)
#define BLE2_REG_BLE_REG_PST_SE_INTVL_2_SUB_INTERVAL_SHIFT (0U)
/*! sub_interval - Configure Subevent Interval Time */
#define BLE2_REG_BLE_REG_PST_SE_INTVL_2_SUB_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_INTVL_2_SUB_INTERVAL_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_INTVL_2_SUB_INTERVAL_MASK)

#define BLE2_REG_BLE_REG_PST_SE_INTVL_2_NSE_MASK (0x1F000000U)
#define BLE2_REG_BLE_REG_PST_SE_INTVL_2_NSE_SHIFT (24U)
/*! nse - Configure Number of Subevents Per BIS/CIS Event */
#define BLE2_REG_BLE_REG_PST_SE_INTVL_2_NSE(x)   (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_INTVL_2_NSE_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_INTVL_2_NSE_MASK)
/*! @} */

/*! @name BLE_REG_PST_SE_DIS_2 - Periodic SW Timer 2: SubEvent Disable */
/*! @{ */

#define BLE2_REG_BLE_REG_PST_SE_DIS_2_DIS_REMAIN_SUBEVT_MASK (0xFFFFFFFEU)
#define BLE2_REG_BLE_REG_PST_SE_DIS_2_DIS_REMAIN_SUBEVT_SHIFT (1U)
/*! dis_remain_subevt - Disable Remaining Subevents */
#define BLE2_REG_BLE_REG_PST_SE_DIS_2_DIS_REMAIN_SUBEVT(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_PST_SE_DIS_2_DIS_REMAIN_SUBEVT_SHIFT)) & BLE2_REG_BLE_REG_PST_SE_DIS_2_DIS_REMAIN_SUBEVT_MASK)
/*! @} */

/*! @name BLE_REG_AHBW_FSM_MON_CNTRL - BLE AHBW FSM Monitor and Reset Control */
/*! @{ */

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RD_ST_MASK (0x1FU)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RD_ST_SHIFT (0U)
/*! rd_st - rd_st value, Current value of ble_rd state machine rd_st. */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RD_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RD_ST_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RD_ST_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RD_ST_MASK (0x80U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RD_ST_SHIFT (7U)
/*! reset_rd_st - reset rd_st and mst_arb_st, To reset rd_st state machine back to Idle state;
 *    firmware first writes 1 and then writes 0 to this bit. If ble_ahb_arb FSM mst_arb_st is servicing
 *    ble_rd; it will be reset together.
 */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RD_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RD_ST_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RD_ST_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_TD_ST_MASK (0xF00U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_TD_ST_SHIFT (8U)
/*! td_st - td_st value, Current value of ble_td state machine td_st. */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_TD_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_TD_ST_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_TD_ST_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_TD_ST_MASK (0x8000U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_TD_ST_SHIFT (15U)
/*! reset_td_st - reset td_st and mst_arb_st, To reset td_st state machine back to Idle state;
 *    firmware first writes 1 and then writes 0 to this bit. If ble_ahb_arb FSM mst_arb_st is servicing
 *    ble_td; it will be reset together.
 */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_TD_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_TD_ST_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_TD_ST_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RL_ST_MASK (0x30000U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RL_ST_SHIFT (16U)
/*! rl_st - rl_st value, Current value of ble_reg_ldr state machine rl_st. */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RL_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RL_ST_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RL_ST_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RL_ST_MASK (0x80000U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RL_ST_SHIFT (19U)
/*! reset_rl_st - reset rl_st and mst_arb_st, To reset rl_st state machine back to Idle state;
 *    firmware first writes 1 and then writes 0 to this bit. If ble_ahb_arb FSM mst_arb_st is servicing
 *    ble_reg_ldr; it will be reset together.
 */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RL_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RL_ST_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_RL_ST_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_MST_ARB_ST_MASK (0x300000U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_MST_ARB_ST_SHIFT (20U)
/*! mst_arb_st - mst_arb_st value, Current value of ble_ahb_arb state machine mst_arb_st. */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_MST_ARB_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_MST_ARB_ST_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_MST_ARB_ST_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_STATE_MASK (0x7F000000U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_STATE_SHIFT (24U)
/*! state - state value, Current value of ble_ahb_mst state machine state. */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_STATE_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_STATE_MASK)

#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_STATE_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_STATE_SHIFT (31U)
/*! reset_state - reset state, To reset state state machine back to Idle state; firmware first writes 1 and then writes 0 to this bit. */
#define BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_STATE_SHIFT)) & BLE2_REG_BLE_REG_AHBW_FSM_MON_CNTRL_RESET_STATE_MASK)
/*! @} */

/*! @name BLE_REG_RX_FSM_MON_CNTRL - BLE Rx FSM Monitor and Reset Control */
/*! @{ */

#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_FSM_STATE_MASK (0x7U)
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_FSM_STATE_SHIFT (0U)
/*! rx_fsm_state - rx_fsm_state value, Current value of ble_rx_fsm state machine rx_fsm_state. */
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_FSM_STATE_SHIFT)) & BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_FSM_STATE_MASK)

#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_FSM_STATE_MASK (0x8U)
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_FSM_STATE_SHIFT (3U)
/*! reset_rx_fsm_state - reset rx_fsm_state, To reset rx_fsm_state state machine back to Idle state;
 *    firmware first writes 1 and then writes 0 to this bit.
 */
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_FSM_STATE_SHIFT)) & BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_FSM_STATE_MASK)

#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_CTL_STATE_MASK (0x70U)
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_CTL_STATE_SHIFT (4U)
/*! rx_ctl_state - rx_ctl_state value, Current value of ble_rx_ctl state machine rx_ctl_state. */
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_CTL_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_CTL_STATE_SHIFT)) & BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RX_CTL_STATE_MASK)

#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_CTL_STATE_MASK (0x80U)
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_CTL_STATE_SHIFT (7U)
/*! reset_rx_ctl_state - reset rx_ctl_state, To reset rx_ctl_state state machine back to Idle state;
 *    firmware first writes 1 and then writes 0 to this bit.
 */
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_CTL_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_CTL_STATE_SHIFT)) & BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_RX_CTL_STATE_MASK)

#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_MEM_CTL_STATE_MASK (0x700U)
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_MEM_CTL_STATE_SHIFT (8U)
/*! mem_ctl_state - mem_ctl_state value, Current value of ble_rx_mem_ctl state machine mem_ctl_state. */
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_MEM_CTL_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_MEM_CTL_STATE_SHIFT)) & BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_MEM_CTL_STATE_MASK)

#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_MEM_CTL_STATE_MASK (0x800U)
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_MEM_CTL_STATE_SHIFT (11U)
/*! reset_mem_ctl_state - reset mem_ctl_state, To reset mem_ctl_state state machine back to Idle
 *    state; firmware first writes 1 and then writes 0 to this bit.
 */
#define BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_MEM_CTL_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_MEM_CTL_STATE_SHIFT)) & BLE2_REG_BLE_REG_RX_FSM_MON_CNTRL_RESET_MEM_CTL_STATE_MASK)
/*! @} */

/*! @name BLE_REG_TX_FSM_MON_CNTRL - BLE Tx FSM Monitor and Reset Control */
/*! @{ */

#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_FSM_STATE_MASK (0xFU)
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_FSM_STATE_SHIFT (0U)
/*! tx_fsm_state - tx_fsm_state value, Current value of ble_tx_fsm state machine tx_fsm_state. */
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_FSM_STATE_SHIFT)) & BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_FSM_STATE_MASK)

#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_FSM_STATE_MASK (0x80U)
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_FSM_STATE_SHIFT (7U)
/*! reset_tx_fsm_state - reset tx_fsm_state, To reset tx_fsm_state state machine back to Idle state;
 *    firmware first writes 1 and then writes 0 to this bit.
 */
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_FSM_STATE_SHIFT)) & BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_FSM_STATE_MASK)

#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_CTL_ST_MASK (0x700U)
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_CTL_ST_SHIFT (8U)
/*! tx_ctl_st - tx_ctl_st value, Current value of ble_tx_ctl state machine tx_ctl_st. */
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_CTL_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_CTL_ST_SHIFT)) & BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_CTL_ST_MASK)

#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_CTL_ST_MASK (0x800U)
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_CTL_ST_SHIFT (11U)
/*! reset_tx_ctl_st - reset tx_ctl_st, To reset tx_ctl_st state machine back to Idle state; firmware
 *    first writes 1 and then writes 0 to this bit.
 */
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_CTL_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_CTL_ST_SHIFT)) & BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_CTL_ST_MASK)

#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_MEM_RD_ST_MASK (0x30000U)
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_MEM_RD_ST_SHIFT (16U)
/*! tx_mem_rd_st - tx_mem_rd_st value, Current value of ble_tx_mem_ctl state machine tx_mem_rd_st. */
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_MEM_RD_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_MEM_RD_ST_SHIFT)) & BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_MEM_RD_ST_MASK)

#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_RD_ST_MASK (0x300000U)
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_RD_ST_SHIFT (20U)
/*! tx_rd_st - tx_rd_st value, Current value of ble_tx_mem_ctl state machine tx_rd_st. */
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_RD_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_RD_ST_SHIFT)) & BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_TX_RD_ST_MASK)

#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_MEM_CTL_MASK (0x800000U)
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_MEM_CTL_SHIFT (23U)
/*! reset_tx_mem_ctl - reset the 2 state machines in ble_tx_mem_ctl, To reset both tx_rd_st and
 *    tx_mem_rd_st state machine back to Idle state; firmware first writes 1 and then writes 0 to this
 *    bit.
 */
#define BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_MEM_CTL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_MEM_CTL_SHIFT)) & BLE2_REG_BLE_REG_TX_FSM_MON_CNTRL_RESET_TX_MEM_CTL_MASK)
/*! @} */

/*! @name BLE_REG_CCM_FSM_MON_CNTRL - BLE CCM FSM Monitor and Reset Control */
/*! @{ */

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_CTL_ST_MASK (0x7U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_CTL_ST_SHIFT (0U)
/*! ccm_ctl_st - ccm_ctl_st value, Current value of ble_ccm_ctl state machine ccm_ctl_st. */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_CTL_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_CTL_ST_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_CTL_ST_MASK)

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RX_PLD_BLK_RDY_ST_MASK (0x30U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RX_PLD_BLK_RDY_ST_SHIFT (4U)
/*! rx_pld_blk_rdy_st - rx_pld_blk_rdy_st value, Current value of ble_ccm_ctl state machine rx_pld_blk_rdy_st. */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RX_PLD_BLK_RDY_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RX_PLD_BLK_RDY_ST_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RX_PLD_BLK_RDY_ST_MASK)

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_CCM_CTL_MASK (0x80U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_CCM_CTL_SHIFT (7U)
/*! reset_ccm_ctl - reset the 2 state machines in ble_ccm_ctl, To reset both rx_pld_blk_rdy_st and
 *    ccm_ctl_st state machines back to Idle state; firmware first writes 1 and then writes 0 to this
 *    bit.
 */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_CCM_CTL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_CCM_CTL_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_CCM_CTL_MASK)

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_ARB_ST_MASK (0x300U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_ARB_ST_SHIFT (8U)
/*! arb_st - arb_st value, Current value of btu_aes_arbiter state machine arb_st. */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_ARB_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_ARB_ST_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_ARB_ST_MASK)

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_ST_MASK (0x3000U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_ST_SHIFT (12U)
/*! ccm_st - ccm_st value, Current value of btu_ccm state machine ccm_st. */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_ST_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_CCM_ST_MASK)

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_BTU_CCM_AES_MASK (0x8000U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_BTU_CCM_AES_SHIFT (15U)
/*! reset_btu_ccm_aes - reset the 2 state machines in ble_ccm_aes, To reset both arb_st and ccm_st
 *    state machines back to Idle state; firmware first writes 1 and then writes 0 to this bit.
 */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_BTU_CCM_AES(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_BTU_CCM_AES_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_RESET_BTU_CCM_AES_MASK)

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES0_ARB_ST_MASK (0x30000U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES0_ARB_ST_SHIFT (16U)
/*! aes0_arb_st - aes0_arb_st, Current value of the hw aes arbiter state machine aes0_arb_st. */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES0_ARB_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES0_ARB_ST_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES0_ARB_ST_MASK)

#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES1_ARB_ST_MASK (0x300000U)
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES1_ARB_ST_SHIFT (20U)
/*! aes1_arb_st - aes1_arb_st, Current value of the sw aes arbiter state machine aes1_arb_st. */
#define BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES1_ARB_ST(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES1_ARB_ST_SHIFT)) & BLE2_REG_BLE_REG_CCM_FSM_MON_CNTRL_AES1_ARB_ST_MASK)
/*! @} */

/*! @name BLE_REG_DEBUG_CNTRL - BLE Debug Test Bus Control */
/*! @{ */

#define BLE2_REG_BLE_REG_DEBUG_CNTRL_TESTBUS_CNTRL_MASK (0xFU)
#define BLE2_REG_BLE_REG_DEBUG_CNTRL_TESTBUS_CNTRL_SHIFT (0U)
/*! testbus_cntrl - BLE debug test bus output control, BLE testbus swapping control. */
#define BLE2_REG_BLE_REG_DEBUG_CNTRL_TESTBUS_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_CNTRL_TESTBUS_CNTRL_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_CNTRL_TESTBUS_CNTRL_MASK)

#define BLE2_REG_BLE_REG_DEBUG_CNTRL_BLE_AHB_MON_SEL_MASK (0x70U)
#define BLE2_REG_BLE_REG_DEBUG_CNTRL_BLE_AHB_MON_SEL_SHIFT (4U)
/*! ble_ahb_mon_sel - BLE AHB Master Debug Signals Selection, BLE AHB Master Debug Signals
 *    Selection, Select BLE AHB Data Bus, 0x0: hRdData[7:0], 0x1: hRdData[15:8], 0x2: hRdData[23:16], 0x3:
 *    hRdData[31:24], 0x4: hWrData[7:0], 0x5: hWrData[15:8], 0x6: hWrData[23:16], 0x7: hWrData[31:24]
 */
#define BLE2_REG_BLE_REG_DEBUG_CNTRL_BLE_AHB_MON_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_CNTRL_BLE_AHB_MON_SEL_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_CNTRL_BLE_AHB_MON_SEL_MASK)
/*! @} */

/*! @name BLE_REG_DEBUG_BANK_SEL - BLE debug test bus bank selection set */
/*! @{ */

#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_1_MASK (0xFFU)
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_1_SHIFT (0U)
/*! testbus_bank_select_1 - BLE debug test bus selection [3:0] */
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_1(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_1_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_1_MASK)

#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_2_MASK (0xFF00U)
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_2_SHIFT (8U)
/*! testbus_bank_select_2 - BLE debug test bus selection [7:4] */
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_2(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_2_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_2_MASK)

#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_3_MASK (0xFF0000U)
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_3_SHIFT (16U)
/*! testbus_bank_select_3 - BLE debug test bus selection [11:8] */
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_3(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_3_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_3_MASK)

#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_4_MASK (0xFF000000U)
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_4_SHIFT (24U)
/*! testbus_bank_select_4 - BLE debug test bus selection [15:12] */
#define BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_4(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_4_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_BANK_SEL_TESTBUS_BANK_SELECT_4_MASK)
/*! @} */

/*! @name BLE_REG_IP_REVISION - BTU IP Revision */
/*! @{ */

#define BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_SHIFT (0U)
/*! BTU_IP_Rev - BLE IP Revision */
#define BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_SHIFT)) & BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_MASK)

#define BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_MASK (0xFFFFU)
#define BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_SHIFT (0U)
/*! btu_ip_rev - BLE IP Revision, Bits[15:8] = major revision number (incremented at full tapeout),
 *    Bits[7:0] = minor revision number (incremented at post tapeout ECO), 88W8787 (Robin) = 0x0800
 *    88W8790 (uBB) = 0x0800 88W8797 (Starling) = 0x900 88W8766 (Geagle) = 0x0900 88W8897 (Kfisher)
 *    = 0x1100 88W8777 (Robin2) = 0x1200 88W8887 (CardiAC) = 0x1300 8830 (Sunbird/BTHM) = 0x1400
 *    88W8977 (Robin3/BTU2) = 0x1600 88W8997 (Kfisher2/BTU2) = 0x1700 88W8987 (Cardi2/BTU2) = 0x1700
 *    88W9064 (SCBT/BTU2) = 0x2100 88W9098 (Skyhawk/BTU2) = 0x2200 88W9000 (Kestrel/BTU2) = 0x2400
 *    88W8978 (Robin3P/BTU2) = 0x2500 Firecrest/BTU2 = 0x2700 K4W1 (NBU/BTU2) = 0x2800
 *    Redfinch/BLE_only = 0x2600 Owl/BTU2 = 0x2900 Tasman/BLE_only = 0x3000 Kamet/BTU2 = 0x3100 Blackbird/BTU2 =
 *    0x3200 KW47 (NBU/BTU2) = 0x3400 Hood/BTU2 = 0x3500 Fuji (NBU/BTU2) = 0x3600 MW30 (NBU/BTU2) =
 *    0x3400
 */
#define BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_SHIFT)) & BLE2_REG_BLE_REG_IP_REVISION_BTU_IP_REV_MASK)
/*! @} */

/*! @name BLE_REG_AES_MARGIN - BLE AES Margin */
/*! @{ */

#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_MIN_MASK (0x3FFU)
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_MIN_SHIFT (0U)
/*! ble_tx_aes_mrgn_min - ble_tx_aes_mrgn_min, Minimum AES operating margin in quarter us during TX */
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_MIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_MIN_SHIFT)) & BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_MIN_MASK)

#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_UR_MASK (0x4000U)
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_UR_SHIFT (14U)
/*! ble_tx_aes_ur - ble_tx_aes_ur, BLE TX AES underrun status */
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_UR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_UR_SHIFT)) & BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_UR_MASK)

#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_EN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_EN_SHIFT (15U)
/*! ble_tx_aes_mrgn_en - ble_tx_aes_mrgn_en, Enable BLE TX AES monitoring. When disabled; the minimum AES margin resets to 'h3ff */
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_EN_SHIFT)) & BLE2_REG_BLE_REG_AES_MARGIN_BLE_TX_AES_MRGN_EN_MASK)

#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_MIN_MASK (0x3FF0000U)
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_MIN_SHIFT (16U)
/*! ble_rx_aes_mrgn_min - ble_rx_aes_mrgn_min, Minimum AES operating margin in quarter us cycles during RX */
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_MIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_MIN_SHIFT)) & BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_MIN_MASK)

#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_UR_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_UR_SHIFT (30U)
/*! ble_rx_aes_ur - ble_rx_aes_ur, BLE RX AES underrun status */
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_UR(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_UR_SHIFT)) & BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_UR_MASK)

#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_EN_SHIFT (31U)
/*! ble_rx_aes_mrgn_en - ble_rx_aes_mrgn_en, Enable BLE RX AES monitoring. When disabled; the minimum AES margin resets to 'h3ff */
#define BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_EN_SHIFT)) & BLE2_REG_BLE_REG_AES_MARGIN_BLE_RX_AES_MRGN_EN_MASK)
/*! @} */

/*! @name BLE_REG_DMA_MARGIN - BLE DMA Margin */
/*! @{ */

#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_MIN_MASK (0x3FFU)
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_MIN_SHIFT (0U)
/*! ble_tx_dma_mrgn_min - ble_tx_dma_mrgn_min, Minimum DMA operating margin in quarter us during TX */
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_MIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_MIN_SHIFT)) & BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_MIN_MASK)

#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_UF_MASK (0x4000U)
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_UF_SHIFT (14U)
/*! ble_tx_dma_uf - ble_tx_dma_uf, BLE TX DMA underflow status */
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_UF(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_UF_SHIFT)) & BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_UF_MASK)

#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_EN_MASK (0x8000U)
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_EN_SHIFT (15U)
/*! ble_tx_dma_mrgn_en - ble_tx_dma_mrgn_en, Enable BLE TX DMA monitoring. When disabled; the minimum DMA margin resets to 'h3ff */
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_EN_SHIFT)) & BLE2_REG_BLE_REG_DMA_MARGIN_BLE_TX_DMA_MRGN_EN_MASK)

#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_MIN_MASK (0x3FF0000U)
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_MIN_SHIFT (16U)
/*! ble_rx_dma_mrgn_min - ble_rx_dma_mrgn_min, Minimum DMA operating margin in quarter us during RX */
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_MIN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_MIN_SHIFT)) & BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_MIN_MASK)

#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_DFE_DMA_OF_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_DFE_DMA_OF_SHIFT (29U)
/*! ble_dfe_dma_of - ble_dfe_dma_of, BLE RX DFE DMA overflow status */
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_DFE_DMA_OF(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DMA_MARGIN_BLE_DFE_DMA_OF_SHIFT)) & BLE2_REG_BLE_REG_DMA_MARGIN_BLE_DFE_DMA_OF_MASK)

#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_OF_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_OF_SHIFT (30U)
/*! ble_rx_dma_of - ble_rx_dma_of, BLE RX DMA overflow status */
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_OF(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_OF_SHIFT)) & BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_OF_MASK)

#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_EN_SHIFT (31U)
/*! ble_rx_dma_mrgn_en - ble_rx_dma_mrgn_en, Enable BLE RX DMA monitoring. When disabled; the minimum DMA margin resets to 'h3ff */
#define BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_EN_SHIFT)) & BLE2_REG_BLE_REG_DMA_MARGIN_BLE_RX_DMA_MRGN_EN_MASK)
/*! @} */

/*! @name BLE_REG_AHB_LAT - BLE AHB Latency Monitors */
/*! @{ */

#define BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_MAX_MASK (0xFFU)
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_MAX_SHIFT (0U)
/*! ble_slv_txn_max - ble_slv_txn_max, Maximum BLE slave transaction latency in number of HCLK cycles */
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_MAX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_MAX_SHIFT)) & BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_MAX_MASK)

#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_MAX_MASK (0xFF00U)
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_MAX_SHIFT (8U)
/*! ble_mst_txn_max - ble_mst_txn_max, Maximum BLE master transaction latency in number of HCLK cycles */
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_MAX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_MAX_SHIFT)) & BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_MAX_MASK)

#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_MAX_MASK (0xFF0000U)
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_MAX_SHIFT (16U)
/*! ble_mst_arb_max - ble_mst_arb_max, Maximum BLE master arbitration latency in number of HCLK cycles */
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_MAX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_MAX_SHIFT)) & BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_MAX_MASK)

#define BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_EN_MASK (0x20000000U)
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_EN_SHIFT (29U)
/*! ble_slv_txn_en - ble_slv_txn__en, Enable BLE slave transaction latency monitor. When disabled; the maximum latency is reset to 0 */
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_EN_SHIFT)) & BLE2_REG_BLE_REG_AHB_LAT_BLE_SLV_TXN_EN_MASK)

#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_EN_MASK (0x40000000U)
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_EN_SHIFT (30U)
/*! ble_mst_txn_en - ble_mst_txn_en, Enable BLE master transaction latency monitor. When disabled; the maximum latency is reset to 0 */
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_EN_SHIFT)) & BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_TXN_EN_MASK)

#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_EN_MASK (0x80000000U)
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_EN_SHIFT (31U)
/*! ble_mst_arb_en - ble_mst_arb_en, Enable BLE master arbitration latency monitor. When disabled; the maximum latency is reset to 0 */
#define BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_EN_SHIFT)) & BLE2_REG_BLE_REG_AHB_LAT_BLE_MST_ARB_EN_MASK)
/*! @} */

/*! @name BLE_REG_DEBUG_RVSD - Debug reserved */
/*! @{ */

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CPU_GATEHCLK_SEL_MASK (0x1U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CPU_GATEHCLK_SEL_SHIFT (0U)
/*! ble_cpu_gatehclk_sel - BLE CPU Gatehclk Select
 *  0b0..gatehclk connected to GATEHCLK port from BLE CPU
 *  0b1..gatehclk connected to SLEEPING port from BLE CPU
 */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CPU_GATEHCLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CPU_GATEHCLK_SEL_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CPU_GATEHCLK_SEL_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BRF_PU_OPT_EN_MASK (0x1U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BRF_PU_OPT_EN_SHIFT (0U)
/*! brf_pu_opt_en - BRF powerup Optimization Enable, Enable BRF_PU optimization to save power in BRF-FRF cross connect mode of Firecrest A1 */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BRF_PU_OPT_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BRF_PU_OPT_EN_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BRF_PU_OPT_EN_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_NAT_CLK_SLEEP_WR_EN_MASK (0x2U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_NAT_CLK_SLEEP_WR_EN_SHIFT (1U)
/*! ble_nat_clk_sleep_wr_en - BLE Native Clock Sleep write enable, Enable CPU write to BLE Native
 *    Clock in sleep domain. FW needs to set this bit before writing to BLE_REG_TMR_NATIVE_CLOCK
 *    register; and must clear this bit after the write is done.
 */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_NAT_CLK_SLEEP_WR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_NAT_CLK_SLEEP_WR_EN_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_NAT_CLK_SLEEP_WR_EN_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SW_MBOX_CLR_EN_MASK (0x2U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SW_MBOX_CLR_EN_SHIFT (1U)
/*! ble_sw_mbox_clr_en - BLE SW_Mbox_Clr_En */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SW_MBOX_CLR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SW_MBOX_CLR_EN_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SW_MBOX_CLR_EN_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MASK_REQ_AT_SLEEP_REQ_RANGE_MASK (0x4U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MASK_REQ_AT_SLEEP_REQ_RANGE_SHIFT (2U)
/*! ble_mask_req_at_sleep_req_range - BLE Mask Request at Sleep_Req_Range */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MASK_REQ_AT_SLEEP_REQ_RANGE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MASK_REQ_AT_SLEEP_REQ_RANGE_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MASK_REQ_AT_SLEEP_REQ_RANGE_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_SWTPAST_ECO_DISABLE_MASK (0x4U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_SWTPAST_ECO_DISABLE_SHIFT (2U)
/*! swtpast_eco_disable - SWT past Intr ECO disable, Disable bit for SWT past intr WIPBTU-478 fix,
 *    0x0: WIPBTU-478 fix is enabled in Owl A1, 0x1: WIPBTU-478 fix is disabled; older logic preserved
 */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_SWTPAST_ECO_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_SWTPAST_ECO_DISABLE_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_SWTPAST_ECO_DISABLE_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MBOX_REQ_DELAY_MASK (0x8U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MBOX_REQ_DELAY_SHIFT (3U)
/*! ble_mbox_req_delay - BLE Mbox Request Delay */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MBOX_REQ_DELAY(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MBOX_REQ_DELAY_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_MBOX_REQ_DELAY_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_CCA_COEX_ECO_DIS_MASK (0x8U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_CCA_COEX_ECO_DIS_SHIFT (3U)
/*! cca_coex_eco_dis - CCA Coex ECO disable, Disable bit for CCA BTC+BLE coex TXPkt/TxAbort counters
 *    WIPBTU-546, 0x0: WIPBTU-546 fix is enabled in BB A1, 0x1: WIPBTU-546 fix is disabled; older
 *    logic preserved
 */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_CCA_COEX_ECO_DIS(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_CCA_COEX_ECO_DIS_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_CCA_COEX_ECO_DIS_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SOC_REQ_MODE_MASK (0x10U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SOC_REQ_MODE_SHIFT (4U)
/*! ble_soc_req_mode - BLE SoC Request Mode */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SOC_REQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SOC_REQ_MODE_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_SOC_REQ_MODE_MASK)

#define BLE2_REG_BLE_REG_DEBUG_RVSD_DEBUG_RVSD_MASK (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (26, 28), largest definition used */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_DEBUG_RVSD_SHIFT (4U)
/*! debug_rvsd - Debug Reserved, BLE-side reserved registers to be used for future ECO. */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_DEBUG_RVSD(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_DEBUG_RVSD_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_DEBUG_RVSD_MASK)  /* Merged from fields with different position or width, of widths (26, 28), largest definition used */

#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CLK_CTRL_SOC_REQ_CDC_FIX_MASK (0x20U)
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CLK_CTRL_SOC_REQ_CDC_FIX_SHIFT (5U)
/*! ble_clk_ctrl_soc_req_cdc_fix - BLE_SoC_Req CDC Fix
 *  0b0..BLE_SoC_Req reverts to original without CDC Fix
 *  0b1..fix for SoC_Req is new
 */
#define BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CLK_CTRL_SOC_REQ_CDC_FIX(x) (((uint32_t)(((uint32_t)(x)) << BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CLK_CTRL_SOC_REQ_CDC_FIX_SHIFT)) & BLE2_REG_BLE_REG_DEBUG_RVSD_BLE_CLK_CTRL_SOC_REQ_CDC_FIX_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLE2_REG_Register_Masks */


/*!
 * @}
 */ /* end of group BLE2_REG_Peripheral_Access_Layer */


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


#endif  /* PERI_BLE2_REG_H_ */

