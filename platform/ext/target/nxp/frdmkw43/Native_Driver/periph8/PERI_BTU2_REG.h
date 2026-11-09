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
**         CMSIS Peripheral Access Layer for BTU2_REG
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
 * @file PERI_BTU2_REG.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for BTU2_REG
 *
 * CMSIS Peripheral Access Layer for BTU2_REG
 */

#if !defined(PERI_BTU2_REG_H_)
#define PERI_BTU2_REG_H_                         /**< Symbol preventing repeated inclusion */

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
   -- BTU2_REG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTU2_REG_Peripheral_Access_Layer BTU2_REG Peripheral Access Layer
 * @{
 */

/** BTU2_REG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[3072];
  __IO uint16_t BTU_RIF_CTL0;                      /**< RIF Control 0, offset: 0xC00 */
  __IO uint16_t BTU_RIF_RX_SIGNAL_QUAL0;           /**< RIF Rx SIGNAL QUALITY 0, offset: 0xC02 */
  __IO uint16_t BTU_RIF_RX_SIGNAL_QUAL1;           /**< RIF Rx SIGNAL QUALITY 0, offset: 0xC04 */
  __IO uint16_t BTU_RIF_BRF_RSSI_ADDR;             /**< RIF BRF RSSI Address, offset: 0xC06 */
       uint8_t RESERVED_1[4];
  __IO uint16_t BTU_RIF_CTRL1;                     /**< RIF Control 1, offset: 0xC0C */
  __IO uint16_t BTU_RIF_RXON;                      /**< RIF RXON, offset: 0xC0E */
  __IO uint16_t BTU_RIF_PLLCLKEN_ON_DELAY;         /**< RIF PLL Clock Enable, offset: 0xC10 */
  __IO uint16_t BTU_RIF_TXON;                      /**< RIF Tx On, offset: 0xC12 */
  __IO uint16_t BTU_RIF_PLLCLKEN_OFF_DELAY;        /**< RIF PLL Clock Enable Off Delay, offset: 0xC14 */
  __I  uint16_t BTU_RIF_FREQ;                      /**< RIF FREQ, offset: 0xC16 */
  __IO uint16_t BTU_RIF_BRF_TX_PU;                 /**< RIF BRF Power Up for TX, offset: 0xC18 */
  __IO uint16_t BTU_RIF_CTRL2;                     /**< RIF Control 2, offset: 0xC1A */
  __IO uint16_t BTU_RIF_TX_PULSE;                  /**< RIF Tx Pulse, offset: 0xC1C */
  __IO uint16_t BTU_RIF_DBUS_TX_PWRCTL;            /**< RIF dBus Tx Power Control, offset: 0xC1E */
  __IO uint16_t BTU_RIF_DBUS_RX_PWRCTL;            /**< RIF dBus Rx Power Control, offset: 0xC20 */
  __IO uint16_t BTU_RIF_BRF_RXPWRCTL_ADDR;         /**< RIF BRF Rx Power Control Address, offset: 0xC22 */
  __IO uint16_t BTU_RIF_BRF_FSYN_ADDR;             /**< RIF BRF FSYN Address, offset: 0xC24 */
  __IO uint16_t BTU_RIF_BRF_TXPWRCTL_ADDR;         /**< RIF BRF Tx Power Control Address, offset: 0xC26 */
  __IO uint16_t BTU_RIF_BTC_DBUS_RSSI;             /**< BTC RIF dBus RSSI, offset: 0xC28 */
  __IO uint16_t BTU_RIF_DBUS_TX_FSYN;              /**< RIF Tx dBus Fsyn, offset: 0xC2A */
  __IO uint16_t BTU_RIF_DBUS_RX_FSYN;              /**< RIF Rx dBus Fsyn, offset: 0xC2C */
  __IO uint16_t BTU_RIF_DBUS_RX_PKT_LEN;           /**< RIF dBus Rx Packet Length, offset: 0xC2E */
  __IO uint16_t BTU_RIF_BLE_PULSE_RX_DELAY;        /**< RIF BLE Pulse Rx Delay, offset: 0xC30 */
  __IO uint16_t BTU_RIF_BLE_PULSE_TX_DELAY;        /**< RIF BLE Pulse Tx Delay, offset: 0xC32 */
  __IO uint16_t BTU_RIF_DBUS_RX_MODE_TYPE;         /**< RIF dBus Rx Mode Type, offset: 0xC34 */
  __IO uint16_t BTU_RIF_MODE_TYPE_TX_DELAY;        /**< RIF Mode Type Tx Delay, offset: 0xC36 */
  __IO uint16_t BTU_RIF_MODE_TYPE_RX_DELAY;        /**< RIF Mode Type Rx Delay, offset: 0xC38 */
  __IO uint16_t BTU_RIF_PKTCTL_OE_DELAY;           /**< RIF Packet Control OE Delay, offset: 0xC3A */
  __IO uint16_t BTU_RIF_TXSYNC_GUARD_DELAY;        /**< RIF Tx Sync Guard Delay, offset: 0xC3C */
  __IO uint16_t BTU_RIF_RXSYNC_TIMER;              /**< RIF Rx Sync Timer, offset: 0xC3E */
  __IO uint16_t BTU_RIF_SWDBUS_CTL;                /**< RIF Software dBus Control, offset: 0xC40 */
  __IO uint16_t BTU_RIF_SWDBUS_EVENT;              /**< RIF Software dBus Event, offset: 0xC42 */
  __I  uint16_t BTU_RIF_SWDBUS_DATA_1_0;           /**< RIF Software dBus Data_1_0, offset: 0xC44 */
  __I  uint16_t BTU_RIF_SWDBUS_DATA_3_2;           /**< RIF Software dBus Data_3_2, offset: 0xC46 */
  __IO uint16_t BTU_RIF_SWDBUS_DATA_5_4;           /**< RIF Software dBus Data_5_4, offset: 0xC48 */
  __IO uint16_t BTU_RIF_SWDBUS_DATA_7_6;           /**< RIF Software dBus Data_7_6, offset: 0xC4A */
  __IO uint16_t BTU_RIF_TX_FESW;                   /**< RIF Tx FESW, offset: 0xC4C */
  __IO uint16_t BTU_RIF_RX_FESW;                   /**< RIF Rx FESW, offset: 0xC4E */
  __IO uint16_t BTU_RIF_RXPAON;                    /**< RIF Rx PA On, offset: 0xC50 */
  __IO uint16_t BTU_RIF_BRF_RX_PU;                 /**< RIF BRF Power Up for RX, offset: 0xC52 */
  __IO uint16_t BTU_RIF_BTC_DBUS_TX_PKT_END;       /**< BTC RIF dBus Tx Packet End Control, offset: 0xC54 */
  __IO uint16_t BTU_RIF_BTC_DBUS_RX_PKT_END;       /**< BTC RIF dBus Rx Packet End Control, offset: 0xC56 */
  __IO uint16_t BTU_RIF_BTC_DBUS_TX_RAMPDOWN;      /**< BTC RIF dBus Tx Rampdown Control, offset: 0xC58 */
       uint8_t RESERVED_2[18];
  __IO uint16_t BTU_RIF_ERR_PATTERN_TX;            /**< RIF Error Pattern Tx, offset: 0xC6C */
  __IO uint16_t BTU_RIF_ERR_DELAY1_TX;             /**< RIF Error Delay 1 Tx, offset: 0xC6E */
  __IO uint16_t BTU_RIF_ERR_DELAY2_TX;             /**< RIF Error Delay 2 Tx, offset: 0xC70 */
  __IO uint16_t BTU_RIF_ERR_DELAY3_TX;             /**< RIF Error Delay 3 Tx, offset: 0xC72 */
  __IO uint16_t BTU_RIF_ERR_INJ_TX_CTRL;           /**< RIF Error Injection Tx Control, offset: 0xC74 */
  __IO uint16_t BTU_RIF_ERR_PATTERN_RX;            /**< RIF Error Pattern Rx, offset: 0xC76 */
  __IO uint16_t BTU_RIF_ERR_DELAY1_RX;             /**< RIF Error Delay 1 Rx, offset: 0xC78 */
  __IO uint16_t BTU_RIF_ERR_DELAY2_RX;             /**< RIF Error Delay 2 Rx, offset: 0xC7A */
  __IO uint16_t BTU_RIF_ERR_DELAY3_RX;             /**< RIF Error Delay 3 Rx, offset: 0xC7C */
  __IO uint16_t BTU_RIF_ERR_INJ_RX_CTRL;           /**< RIF Error Injection Rx Control, offset: 0xC7E */
       uint8_t RESERVED_3[2];
  __IO uint16_t BTU_RIF_DBUS_COR_CONFIG_CTRL;      /**< RIF Correlator Configuration Control, offset: 0xC82 */
  __IO uint16_t BTU_RIF_BRF_COR_CONFIG_ADDR;       /**< RIF BRF Correlator Configuration Address, offset: 0xC84 */
  __IO uint16_t BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL; /**< RIF Syncword and Access Code Send Control, offset: 0xC86 */
  __IO uint16_t BTU_RIF_BRF_ACC_CODE_ONE_ADDR;     /**< RIF BRF Access Code 1 Address, offset: 0xC88 */
  __IO uint16_t BTU_RIF_BRF_ACC_CODE_TWO_ADDR;     /**< RIF Access Code 2 Address, offset: 0xC8A */
  __IO uint16_t BTU_RIF_BRF_RX_MODE_TYPE_ADDR;     /**< RIF Register, offset: 0xC8C */
  __IO uint16_t BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR;   /**< RIF Register, offset: 0xC8E */
  __IO uint16_t BTU_RIF_RX_SYNC_PULSE_TIMER;       /**< RIF BRF Rx Sync Pulse Timer, offset: 0xC90 */
  __IO uint16_t BTU_RIF_RX_BTC_SAMP_PHASE_ADJ;     /**< RIF Rx Sample Phase Adjustment, offset: 0xC92 */
  __IO uint16_t BTU_RIF_RX_BLE_SAMP_PHASE_ADJ;     /**< RIF Rx Sample Phase Adjustment, offset: 0xC94 */
  __IO uint16_t BTU_RIF_RX_TONE_CANCEL_CTRL;       /**< Rx Tone Cancellation Control, offset: 0xC96 */
  __IO uint16_t BTU_RIF_RX_TONE_CANCEL_CHNL10;     /**< Rx Tone Cancellation Channel, offset: 0xC98 */
  __IO uint16_t BTU_RIF_RX_TONE_CANCEL_CHNL32;     /**< Rx Tone Cancellation Channel, offset: 0xC9A */
       uint8_t RESERVED_4[4];
  __IO uint16_t BTU_RIF_BLE_CTL;                   /**< BLE RIF Control, offset: 0xCA0 */
  __IO uint16_t BTU_RIF_BLE_COR_LENGTH_SEL;        /**< BLE Correlation Length Selection, offset: 0xCA2 */
  __IO uint16_t BTU_RIF_BLE_COR_ACCESSADDR_0;      /**< BLE AccessCode, offset: 0xCA4 */
  __IO uint16_t BTU_RIF_BLE_COR_ACCESSADDR_1;      /**< BLE AccessCode, offset: 0xCA6 */
  __IO uint16_t BTU_RIF_BLE_COR_WINDOW_0;          /**< BLE Correlation Window Size, offset: 0xCA8 */
  __IO uint16_t BTU_RIF_BLE_COR_WINDOW_1;          /**< BLE Correlation Window Size, offset: 0xCAA */
  __IO uint16_t BTU_RIF_BLE_CLK_EN_DELAY;          /**< Tx/Rx Clock Enable Signal Delay, offset: 0xCAC */
  __IO uint16_t BTU_RIF_BLE_GO_DELAY;              /**< RIF Go Signal Delay, offset: 0xCAE */
  __IO uint16_t BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA;  /**< Tx Power Control DBUS Write Data, offset: 0xCB0 */
  __IO uint16_t BTU_RIF_BLE_DBUS_TX_FSYN_WDATA;    /**< Tx Fsyn DBUS Write Data, offset: 0xCB2 */
  __IO uint16_t BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA;  /**< Rx Power Control DBUS Write Data, offset: 0xCB4 */
  __IO uint16_t BTU_RIF_BLE_DBUS_RX_FSYN_WDATA;    /**< Rx Fsyn DBUS Write Data, offset: 0xCB6 */
  __IO uint16_t BTU_RIF_BLE_RX_SYNC_DELAY;         /**< BLE Rx Sync Delay, offset: 0xCB8 */
       uint8_t RESERVED_5[4];
  __IO uint16_t BTU_RIF_BRF_RX_CTE_LEN_ADDR;       /**< RIF Register, offset: 0xCBE */
  __IO uint16_t BTU_RIF_ARB_BTC_START_TIME;        /**< RIF ARB BTC Start Time, offset: 0xCC0 */
  __IO uint16_t BTU_RIF_ARB_BLE_START_TIME_CODED;  /**< RIF ARB BLE Start Time, offset: 0xCC2 */
  __IO uint16_t BTU_RIF_ARB_BLE_START_TIME_1M;     /**< RIF ARB BLE Start Time, offset: 0xCC4 */
  __IO uint16_t BTU_RIF_ARB_BLE_START_TIME_2M;     /**< RIF ARB BLE Start Time, offset: 0xCC6 */
  __IO uint16_t BTU_RIF_ARB_CTL;                   /**< RIF ARB Control, offset: 0xCC8 */
  __IO uint16_t BTU_RIF_ARB_CTL_1;                 /**< RIF ARB Control, offset: 0xCCA */
       uint8_t RESERVED_6[4];
  __IO uint16_t BTU_RIF_TESTBUS_SEL_0;             /**< RIF Testbus Select 0, offset: 0xCD0 */
  __IO uint16_t BTU_RIF_TESTBUS_SEL_1;             /**< RIF Testbus Select 1, offset: 0xCD2 */
  __IO uint16_t BTU_RIF_TESTBUS_OE;                /**< BTU Testbus Output Enable, offset: 0xCD4 */
  __IO uint16_t BTU_RIF_REG_DEBUG_SW_OUTDATA;      /**< BLE Debug Output Data, offset: 0xCD6 */
  __I  uint16_t BTU_RIF_REG_DEBUG_INDATA;          /**< BLE Debug Input Data, offset: 0xCD8 */
  __IO uint16_t BTU_RIF_REG_DEBUG_SW_MSG;          /**< BLE Debug Software Message, offset: 0xCDA */
  __I  uint16_t BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT; /**< BLE Debug Software Message FIFO Count, offset: 0xCDC */
  __IO uint16_t BTU_RIF_TESTBUS_CONTROL;           /**< RIF Testbus Control, offset: 0xCDE */
       uint8_t RESERVED_7[16];
  __IO uint16_t BTU_RIF_BT_CLK_GATING;             /**< RIF Bluetooth Clock Gating, offset: 0xCF0 */
       uint8_t RESERVED_8[2];
  __IO uint16_t BTU_RIF_CLK_SMPLD;                 /**< RIF Clock Sampled, offset: 0xCF4 */
       uint8_t RESERVED_9[2];
  __IO uint16_t BTU_RIF_BLE_CLK_GATING;            /**< RIF BLE Clock Gating, offset: 0xCF8 */
       uint8_t RESERVED_10[2];
  __IO uint16_t BTU_RIF_BLE_CLK_CTRL;              /**< RIF BLE Clock Control, offset: 0xCFC */
       uint8_t RESERVED_11[2];
  __IO uint16_t BTU_RIF_BLE_DBUS_TX_PKT_END;       /**< BLE RIF dBus Tx Packet End Control, offset: 0xD00 */
  __IO uint16_t BTU_RIF_BLE_DBUS_RX_PKT_END;       /**< BLE RIF dBus Rx Packet End Control, offset: 0xD02 */
  __IO uint16_t BTU_RIF_BLE_DBUS_TX_RAMPDOWN;      /**< BLE RIF dBus Tx Rampdown Control, offset: 0xD04 */
  __IO uint16_t BTU_RIF_BLE_DBUS_RSSI;             /**< BLE RIF dBus RSSI, offset: 0xD06 */
       uint8_t RESERVED_12[504];
  __IO uint16_t BTU_PTA_SEL_PRI_HIGH;              /**< PTA High Priority Select for RIF_ARB Arbitration, offset: 0xF00 */
  __IO uint16_t BTU_PTA_CTRL;                      /**< PTA Control, offset: 0xF02 */
  __IO uint16_t BTU_PTA_REQ_DELAY_TIMER;           /**< PTA Bt_Req Delay Timer, offset: 0xF04 */
       uint8_t RESERVED_13[12];
  __IO uint16_t BTU_PTA_SEL_PRI_MED;               /**< PTA Medium Priority Select for RIF_ARB Arbitration, offset: 0xF12 */
  __IO uint16_t BTU_PTA_BLE_RIF_ARB_COEX_PRI;      /**< BLE PTA Priority for BTC/BLE arbitration, offset: 0xF14 */
  __IO uint16_t BTU_PTA_BLE_BCA_COEX_PRI;          /**< BLE PTA Priority for BCA arbitration, offset: 0xF16 */
  __I  uint16_t BTU_PTA_MWS_INACTIVITY_REFCLK_0;   /**< Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt, offset: 0xF18 */
  __I  uint16_t BTU_PTA_MWS_INACTIVITY_REFCLK_1;   /**< Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt, offset: 0xF1A */
  __I  uint16_t BTU_PTA_MWS_INACTIVITY_REFPDB_CNT; /**< Bluetooth Reference pdBitCounter Snapshot on MWS_Inact_Msg_Real_Int Interrupt, offset: 0xF1C */
  __IO uint16_t BTU_PTA_INBAND_FREQ_SET_1;         /**< PTA Inband Frequency Set 0, offset: 0xF1E */
  __IO uint16_t BTU_PTA_MODE_SELECT;               /**< PTA Mode Select, offset: 0xF20 */
  __IO uint16_t BTU_PTA_INBAND_FREQ_SET_0;         /**< PTA Inband Frequency Set 1, offset: 0xF22 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0; /**< Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt, offset: 0xF24 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1; /**< Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt, offset: 0xF26 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT; /**< Bluetooth Reference pdBitCounter Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt, offset: 0xF28 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_VAL;      /**< MWS Coex Signal HARQ_PATTERN_SEL Value, offset: 0xF2A */
  __IO uint16_t BTU_PTA_INFO_DELAY_TIMER;          /**< PTA Info Delay Timer, offset: 0xF2C */
       uint8_t RESERVED_14[4];
  __IO uint16_t BTU_PTA_BLE_SYNC_CTRL;             /**< PTA BLE Sync Control, offset: 0xF32 */
       uint8_t RESERVED_15[2];
  __IO uint16_t BTU_PTA_SYNC_CTRL;                 /**< PTA Voice/WLAN Sync Control, offset: 0xF36 */
  __IO uint16_t BTU_PTA_BLE_TX_PWR_THRHD;          /**< BLE Tx Power Threshold to Suppress Tx Overlap Assertion, offset: 0xF38 */
       uint8_t RESERVED_16[8];
  __IO uint16_t BTU_PTA_STATE_DELAY_TIMER;         /**< PTA Bt_State Delay Timer, offset: 0xF42 */
  __IO uint16_t BTU_PTA_SLNA_CTRL;                 /**< PTA SLNA Control, offset: 0xF44 */
  __IO uint16_t BTU_PTA_TX_POWER_THRESHOLD;        /**< Tx Power Threshold to Suppress Tx Overlap Assertion, offset: 0xF46 */
  __IO uint16_t BTU_PTA_MWS_TX_OVERLAP_RANGE;      /**< MWS Frequency Overlap Range for Bluetooth Tx Slot, offset: 0xF48 */
  __IO uint16_t BTU_PTA_MWS_RX_OVERLAP_RANGE;      /**< MWS Frequency Overlap Range for Bluetooth Rx Slot, offset: 0xF4A */
  __IO uint16_t BTU_PTA_MWS_COEX_BT_TX_ON_START;   /**< MWS Coex Signal BT_TX_ON Start Timer, offset: 0xF4C */
  __IO uint16_t BTU_PTA_MWS_COEX_BT_TX_ON_END;     /**< MWS Coex Signal BT_TX_ON End Timer, offset: 0xF4E */
  __IO uint16_t BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST; /**< MWS Coex Signal BT_RX_PRI Start Timer for Master Mode, offset: 0xF50 */
  __IO uint16_t BTU_PTA_MWS_COEX_BT_RX_PRI_END;    /**< MWS Coex Signal BT_RX_PRI End Timer, offset: 0xF52 */
  __I  uint16_t BTU_PTA_MWS_FRAMESYNC_REFCLK_0;    /**< Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt, offset: 0xF54 */
  __I  uint16_t BTU_PTA_MWS_FRAMESYNC_REFCLK_1;    /**< Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt, offset: 0xF56 */
  __I  uint16_t BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT;  /**< Bluetooth Reference pdBitCounter Snapshot on MWS Frame Sync Pulse Interrupt, offset: 0xF58 */
  __I  uint16_t BTU_PTA_MWS_PATTERN_REFCLK_0;      /**< Bluetooth Reference Clock Snapshot on MWS_Pattern_Real_Int Interrupt, offset: 0xF5A */
  __I  uint16_t BTU_PTA_MWS_PATTERN_REFCLK_1;      /**< Bluetooth Reference Clock Snapshot on MWS_Pattern_Real_Int Interrupt, offset: 0xF5C */
  __I  uint16_t BTU_PTA_MWS_PATTERN_REFPDB_CNT;    /**< Bluetooth Reference pdBitCounter Snapshot on MWS_Pattern_Real_Int Interrupt, offset: 0xF5E */
  __I  uint16_t BTU_PTA_MWS_PATTERN_VAL;           /**< MWS Coex Signal MWS_PATTERN Value, offset: 0xF60 */
  __I  uint16_t BTU_PTA_3DG_CLK_UPDATE_REFCLK_0;   /**< Bluetooth Reference Clock Snapshot on BT_3DG_CLK_UPATE Pulse Interrupt, offset: 0xF62 */
  __I  uint16_t BTU_PTA_3DG_CLK_UPDATE_REFCLK_1;   /**< Bluetooth Reference Clock Snapshot on BT_3DG_CLK_UPATE Pulse Interrupt, offset: 0xF64 */
  __I  uint16_t BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT; /**< Bluetooth Reference pdBitCounter Snapshot on BT_3DG_CLK_UPDATE Pulse Interrupt, offset: 0xF66 */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4;   /**< MWS Scan Frequency Overlap Range 1~4, offset: 0xF68 */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8;   /**< MWS Scan Frequency Overlap Range 5~8, offset: 0xF6A */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12;  /**< MWS Scan Frequency Overlap Range 9~12, offset: 0xF6C */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16; /**< MWS Scan Frequency Overlap Range 13~16, offset: 0xF6E */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20; /**< MWS Scan Frequency Overlap Range 17~20, offset: 0xF70 */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24; /**< MWS Scan Frequency Overlap Range 21~24, offset: 0xF72 */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28; /**< MWS Scan Frequency Overlap Range 25~28, offset: 0xF74 */
  __IO uint16_t BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31; /**< MWS Scan Frequency Overlap Range 29~31, offset: 0xF76 */
  __IO uint16_t BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL;  /**< MWS Coex Early BT_RX_PRI Control, offset: 0xF78 */
  __IO uint16_t BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST; /**< MWS Coex Early BT_RX_PRI Start Offset for Master Mode, offset: 0xF7A */
  __IO uint16_t BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV; /**< MWS Coex Early BT_RX_PRI Start Offset for Slave Mode, offset: 0xF7C */
  __IO uint16_t BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV; /**< MWS Coex Signal BT_RX_PRI Start Timer for Slave Mode, offset: 0xF7E */
       uint8_t RESERVED_17[16];
  __IO uint16_t BTU_PTA_ANT_SWITCH_CTRL;           /**< PTA Antenna Switch Control, offset: 0xF90 */
       uint8_t RESERVED_18[14];
  __IO uint16_t BTU_PTA_SEL_BCA_PRI_HIGH;          /**< PTA High Priority Select for BCA Arbitration, offset: 0xFA0 */
  __IO uint16_t BTU_PTA_SEL_BCA_PRI_MED;           /**< PTA Medium Priority Select for BCA Arbitration, offset: 0xFA2 */
} BTU2_REG_Type;

/* ----------------------------------------------------------------------------
   -- BTU2_REG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTU2_REG_Register_Masks BTU2_REG Register Masks
 * @{
 */

/*! @name BTU_RIF_CTL0 - RIF Control 0 */
/*! @{ */

#define BTU2_REG_BTU_RIF_CTL0_BRF_RD_DATA_TURNAROUND_MASK (0x1U)
#define BTU2_REG_BTU_RIF_CTL0_BRF_RD_DATA_TURNAROUND_SHIFT (0U)
/*! BRF_Rd_Data_Turnaround - BRF Read Data Turnaround
 *  0b0..BRF read data will be ready on the next clock cycle after address given
 *  0b1..BRF needs one more clock cycle between address and read data
 */
#define BTU2_REG_BTU_RIF_CTL0_BRF_RD_DATA_TURNAROUND(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTL0_BRF_RD_DATA_TURNAROUND_SHIFT)) & BTU2_REG_BTU_RIF_CTL0_BRF_RD_DATA_TURNAROUND_MASK)

#define BTU2_REG_BTU_RIF_CTL0_BRF_AGC_COUNTER_READBACK_ENABLE_MASK (0x2U)
#define BTU2_REG_BTU_RIF_CTL0_BRF_AGC_COUNTER_READBACK_ENABLE_SHIFT (1U)
/*! BRF_AGC_Counter_Readback_Enable - Enable BRF readback LNA, CBPF and ADC overflow counters after AGC freeze
 *  0b0..BRF only readback RSSI and noise floor values at RSSI
 *  0b1..BRF readback extra 3 bytes (LNA, CBPF and ADC overflow counters) after RSSI read
 */
#define BTU2_REG_BTU_RIF_CTL0_BRF_AGC_COUNTER_READBACK_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTL0_BRF_AGC_COUNTER_READBACK_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_CTL0_BRF_AGC_COUNTER_READBACK_ENABLE_MASK)

#define BTU2_REG_BTU_RIF_CTL0_RADIO_TYPE_MASK    (0x700U)
#define BTU2_REG_BTU_RIF_CTL0_RADIO_TYPE_SHIFT   (8U)
/*! Radio_Type - Radio Type
 *  0b000..Unknown
 *  0b001..Marvell Gen3 radio, dBus mode
 *  0b010..Marvell Gen4 radio, dBus mode
 */
#define BTU2_REG_BTU_RIF_CTL0_RADIO_TYPE(x)      (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTL0_RADIO_TYPE_SHIFT)) & BTU2_REG_BTU_RIF_CTL0_RADIO_TYPE_MASK)

#define BTU2_REG_BTU_RIF_CTL0_RADIO_MODE_MASK    (0x1800U)
#define BTU2_REG_BTU_RIF_CTL0_RADIO_MODE_SHIFT   (11U)
/*! Radio_Mode - Radio Mode Selection
 *  0b00..Marvell Radio Mode
 *  0b01..KW Radio, Sideband RIF interface
 *  0b10..Unused
 *  0b11..Unused
 */
#define BTU2_REG_BTU_RIF_CTL0_RADIO_MODE(x)      (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTL0_RADIO_MODE_SHIFT)) & BTU2_REG_BTU_RIF_CTL0_RADIO_MODE_MASK)
/*! @} */

/*! @name BTU_RIF_RX_SIGNAL_QUAL0 - RIF Rx SIGNAL QUALITY 0 */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_LINKBDRRXSIGNALQUALITYEN_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_LINKBDRRXSIGNALQUALITYEN_SHIFT (0U)
/*! linkBdrRxSignalQualityEn - RX signal quality enable on BDR */
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_LINKBDRRXSIGNALQUALITYEN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_LINKBDRRXSIGNALQUALITYEN_SHIFT)) & BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_LINKBDRRXSIGNALQUALITYEN_MASK)

#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_RXSIGNALQUALSAMPLEDELAY_MASK (0xFC00U)
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_RXSIGNALQUALSAMPLEDELAY_SHIFT (10U)
/*! rxSignalQualSampleDelay - RX signal qual sample time */
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_RXSIGNALQUALSAMPLEDELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_RXSIGNALQUALSAMPLEDELAY_SHIFT)) & BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL0_RXSIGNALQUALSAMPLEDELAY_MASK)
/*! @} */

/*! @name BTU_RIF_RX_SIGNAL_QUAL1 - RIF Rx SIGNAL QUALITY 0 */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_LINKEDRRXSIGNALQUALITYEN_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_LINKEDRRXSIGNALQUALITYEN_SHIFT (0U)
/*! linkEdrRxSignalQualityEn - RX signal quality enable on EDR */
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_LINKEDRRXSIGNALQUALITYEN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_LINKEDRRXSIGNALQUALITYEN_SHIFT)) & BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_LINKEDRRXSIGNALQUALITYEN_MASK)

#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_RXSIGNALQUALCNT_MASK (0x3C00U)
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_RXSIGNALQUALCNT_SHIFT (10U)
/*! rxSignalQualCnt - RX signal quality debug counter */
#define BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_RXSIGNALQUALCNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_RXSIGNALQUALCNT_SHIFT)) & BTU2_REG_BTU_RIF_RX_SIGNAL_QUAL1_RXSIGNALQUALCNT_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RSSI_ADDR - RIF BRF RSSI Address */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_RSSI_ADDR_RSSI_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_RSSI_ADDR_RSSI_ADDR_SHIFT (0U)
/*! RSSI_Addr - RSSI Address */
#define BTU2_REG_BTU_RIF_BRF_RSSI_ADDR_RSSI_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RSSI_ADDR_RSSI_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RSSI_ADDR_RSSI_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_CTRL1 - RIF Control 1 */
/*! @{ */

#define BTU2_REG_BTU_RIF_CTRL1_BD_SPI_DATA_BIDIR_MASK (0x40U)
#define BTU2_REG_BTU_RIF_CTRL1_BD_SPI_DATA_BIDIR_SHIFT (6U)
/*! Bd_SPI_Data_BiDir - Uni- or Bi-directional dBus Data Line Selection
 *  0b0..uni-directional
 *  0b1..bi-directional
 */
#define BTU2_REG_BTU_RIF_CTRL1_BD_SPI_DATA_BIDIR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTRL1_BD_SPI_DATA_BIDIR_SHIFT)) & BTU2_REG_BTU_RIF_CTRL1_BD_SPI_DATA_BIDIR_MASK)

#define BTU2_REG_BTU_RIF_CTRL1_BD_RXTX_DATA_BIDIR_MASK (0x80U)
#define BTU2_REG_BTU_RIF_CTRL1_BD_RXTX_DATA_BIDIR_SHIFT (7U)
/*! Bd_RxTx_Data_BiDir - Uni- or Bi-directional RxData and TxData Line Selection
 *  0b0..uni-directional
 *  0b1..bi-directional
 */
#define BTU2_REG_BTU_RIF_CTRL1_BD_RXTX_DATA_BIDIR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTRL1_BD_RXTX_DATA_BIDIR_SHIFT)) & BTU2_REG_BTU_RIF_CTRL1_BD_RXTX_DATA_BIDIR_MASK)

#define BTU2_REG_BTU_RIF_CTRL1_RSSI_VALUE_MASK   (0xFF00U)
#define BTU2_REG_BTU_RIF_CTRL1_RSSI_VALUE_SHIFT  (8U)
/*! RSSI_Value - RSSI Value */
#define BTU2_REG_BTU_RIF_CTRL1_RSSI_VALUE(x)     (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTRL1_RSSI_VALUE_SHIFT)) & BTU2_REG_BTU_RIF_CTRL1_RSSI_VALUE_MASK)
/*! @} */

/*! @name BTU_RIF_RXON - RIF RXON */
/*! @{ */

#define BTU2_REG_BTU_RIF_RXON_RXON_FIXED_MASK    (0x80U)
#define BTU2_REG_BTU_RIF_RXON_RXON_FIXED_SHIFT   (7U)
/*! RxOn_Fixed - RxOn fixed or use programmable timing
 *  0b0..use start and stop timing parameters
 *  0b1..rxOn = RxOn_Start[6]
 */
#define BTU2_REG_BTU_RIF_RXON_RXON_FIXED(x)      (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RXON_RXON_FIXED_SHIFT)) & BTU2_REG_BTU_RIF_RXON_RXON_FIXED_MASK)

#define BTU2_REG_BTU_RIF_RXON_RXON_STOP_MASK     (0xFF00U)
#define BTU2_REG_BTU_RIF_RXON_RXON_STOP_SHIFT    (8U)
/*! RxOn_Stop - Delay from Rx finished (rifRx low) to rxOn falling edge */
#define BTU2_REG_BTU_RIF_RXON_RXON_STOP(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RXON_RXON_STOP_SHIFT)) & BTU2_REG_BTU_RIF_RXON_RXON_STOP_MASK)
/*! @} */

/*! @name BTU_RIF_PLLCLKEN_ON_DELAY - RIF PLL Clock Enable */
/*! @{ */

#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_ON_DELAY_QUS_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_ON_DELAY_QUS_SHIFT (0U)
/*! BRF_PLL_Clk_En_On_Delay_qus - Delay from wakeUp to turning of BRF's PLL clock */
#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_ON_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_ON_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_ON_DELAY_QUS_MASK)

#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_NB_MASK (0x4000U)
#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_NB_SHIFT (14U)
/*! BRF_PLL_Clk_En_Nb - Activate brf_pll_clk_en during NB/MB scan packets Enable
 *  0b0..keep off during NB/MB scan packets
 *  0b1..activate brf_pll_clk_en during NB/MB scan packets
 */
#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_NB(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_NB_SHIFT)) & BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_NB_MASK)

#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_FIXED_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_FIXED_SHIFT (15U)
/*! BRF_PLL_Clk_En_Fixed - Use fixed value for brf_pll_clk_en
 *  0b0..on/off_delay registers control the timing
 *  0b1..brf_pll_clk_en is the fixed value of bit[0]
 */
#define BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_FIXED(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_FIXED_SHIFT)) & BTU2_REG_BTU_RIF_PLLCLKEN_ON_DELAY_BRF_PLL_CLK_EN_FIXED_MASK)
/*! @} */

/*! @name BTU_RIF_TXON - RIF Tx On */
/*! @{ */

#define BTU2_REG_BTU_RIF_TXON_TXON_FIXED_MASK    (0x80U)
#define BTU2_REG_BTU_RIF_TXON_TXON_FIXED_SHIFT   (7U)
/*! TxOn_Fixed - TxOn fixed, or use programmable timing
 *  0b0..use start and stop timing parameters
 *  0b1..txOn = TxOn_Start[6]
 */
#define BTU2_REG_BTU_RIF_TXON_TXON_FIXED(x)      (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TXON_TXON_FIXED_SHIFT)) & BTU2_REG_BTU_RIF_TXON_TXON_FIXED_MASK)

#define BTU2_REG_BTU_RIF_TXON_TXON_STOP_MASK     (0xFF00U)
#define BTU2_REG_BTU_RIF_TXON_TXON_STOP_SHIFT    (8U)
/*! TxOn_Stop - Delay from Tx finished (rifTx low) to txOn falling edge */
#define BTU2_REG_BTU_RIF_TXON_TXON_STOP(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TXON_TXON_STOP_SHIFT)) & BTU2_REG_BTU_RIF_TXON_TXON_STOP_MASK)
/*! @} */

/*! @name BTU_RIF_PLLCLKEN_OFF_DELAY - RIF PLL Clock Enable Off Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_PLLCLKEN_OFF_DELAY_BRF_PLL_CLK_EN_OFF_DELAY_MASK (0x7FU)
#define BTU2_REG_BTU_RIF_PLLCLKEN_OFF_DELAY_BRF_PLL_CLK_EN_OFF_DELAY_SHIFT (0U)
/*! BRF_PLL_Clk_En_Off_Delay - Delay from final dBus access finishing to turning off BRF PLL clock */
#define BTU2_REG_BTU_RIF_PLLCLKEN_OFF_DELAY_BRF_PLL_CLK_EN_OFF_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PLLCLKEN_OFF_DELAY_BRF_PLL_CLK_EN_OFF_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_PLLCLKEN_OFF_DELAY_BRF_PLL_CLK_EN_OFF_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_FREQ - RIF FREQ */
/*! @{ */

#define BTU2_REG_BTU_RIF_FREQ_RXTX_FREQ_MASK     (0x100U)
#define BTU2_REG_BTU_RIF_FREQ_RXTX_FREQ_SHIFT    (8U)
/*! RxTx_Freq - Rx or Tx Slot Indication
 *  0b0..Tx slot
 *  0b1..Rx slot
 */
#define BTU2_REG_BTU_RIF_FREQ_RXTX_FREQ(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_FREQ_RXTX_FREQ_SHIFT)) & BTU2_REG_BTU_RIF_FREQ_RXTX_FREQ_MASK)

#define BTU2_REG_BTU_RIF_FREQ_FREQ_MASK          (0xFE00U)
#define BTU2_REG_BTU_RIF_FREQ_FREQ_SHIFT         (9U)
/*! Freq - Channel Hop Frequency Number */
#define BTU2_REG_BTU_RIF_FREQ_FREQ(x)            (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_FREQ_FREQ_SHIFT)) & BTU2_REG_BTU_RIF_FREQ_FREQ_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_TX_PU - RIF BRF Power Up for TX */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_ON_DELAY_QUS_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_ON_DELAY_QUS_SHIFT (0U)
/*! brf_tx_pu_on_delay_qus - brf_pu on delay */
#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_ON_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_ON_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_ON_DELAY_QUS_MASK)

#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_OFF_DELAY_QUS_MASK (0x7F00U)
#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_OFF_DELAY_QUS_SHIFT (8U)
/*! brf_tx_pu_off_delay_qus - brf_pu off delay */
#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_OFF_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_OFF_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_OFF_DELAY_QUS_MASK)

#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_FIXED_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_FIXED_SHIFT (15U)
/*! brf_tx_pu_fixed - Set brf_pu to a fixed value.
 *  0b0..use programmable timers
 *  0b1..fixed, brf_pu = brf_tx_pu_on_delay_us[0]
 */
#define BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_FIXED(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_FIXED_SHIFT)) & BTU2_REG_BTU_RIF_BRF_TX_PU_BRF_TX_PU_FIXED_MASK)
/*! @} */

/*! @name BTU_RIF_CTRL2 - RIF Control 2 */
/*! @{ */

#define BTU2_REG_BTU_RIF_CTRL2_TX_DATA_INV_MASK  (0x2000U)
#define BTU2_REG_BTU_RIF_CTRL2_TX_DATA_INV_SHIFT (13U)
/*! Tx_Data_Inv - Invert Tx data
 *  0b0..normal operation
 *  0b1..transmit data inverted
 */
#define BTU2_REG_BTU_RIF_CTRL2_TX_DATA_INV(x)    (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTRL2_TX_DATA_INV_SHIFT)) & BTU2_REG_BTU_RIF_CTRL2_TX_DATA_INV_MASK)

#define BTU2_REG_BTU_RIF_CTRL2_RX_DATA_INV_MASK  (0x4000U)
#define BTU2_REG_BTU_RIF_CTRL2_RX_DATA_INV_SHIFT (14U)
/*! Rx_Data_Inv - Invert Rx data
 *  0b0..normal operation
 *  0b1..receive data inverted
 */
#define BTU2_REG_BTU_RIF_CTRL2_RX_DATA_INV(x)    (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CTRL2_RX_DATA_INV_SHIFT)) & BTU2_REG_BTU_RIF_CTRL2_RX_DATA_INV_MASK)
/*! @} */

/*! @name BTU_RIF_TX_PULSE - RIF Tx Pulse */
/*! @{ */

#define BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_DELAY_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_DELAY_SHIFT (0U)
/*! tx_Pulse_Delay - Tx Pulse Delay */
#define BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_DELAY_MASK)

#define BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_EN_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_EN_SHIFT (15U)
/*! tx_Pulse_En - Enable TxData sync pulse
 *  0b0..TxData sync pulse deactivated and pulse not generated
 *  0b1..TxData sync pulse activated and pulse generated
 */
#define BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_EN_SHIFT)) & BTU2_REG_BTU_RIF_TX_PULSE_TX_PULSE_EN_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_TX_PWRCTL - RIF dBus Tx Power Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_DELAY_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_DELAY_SHIFT (0U)
/*! DBus_Tx_Pwr_Ctrl_Wr_Delay - Delay from the trigger to start Tx Power Control Write dBus */
#define BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_DELAY_MASK)

#define BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_ENABLE_SHIFT (15U)
/*! DBus_Tx_Pwr_Ctrl_Wr_Enable - Enable Automatic Tx Power Control Write on the dBus */
#define BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_TX_PWRCTL_DBUS_TX_PWR_CTRL_WR_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_PWRCTL - RIF dBus Rx Power Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_DELAY_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_DELAY_SHIFT (0U)
/*! DBus_Rx_Pwr_Ctrl_Wr_Delay - Delay from the trigger to start Rx Power Control Write dBus */
#define BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_DELAY_MASK)

#define BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_ENABLE_SHIFT (15U)
/*! DBus_Rx_Pwr_Ctrl_Wr_Enable - Enable Automatic Rx Power Control Write on dBus */
#define BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_RX_PWRCTL_DBUS_RX_PWR_CTRL_WR_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RXPWRCTL_ADDR - RIF BRF Rx Power Control Address */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_RXPWRCTL_ADDR_RX_PWR_CTRL_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_RXPWRCTL_ADDR_RX_PWR_CTRL_ADDR_SHIFT (0U)
/*! Rx_Pwr_Ctrl_Addr - Radio Register Address for Rx Power Control */
#define BTU2_REG_BTU_RIF_BRF_RXPWRCTL_ADDR_RX_PWR_CTRL_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RXPWRCTL_ADDR_RX_PWR_CTRL_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RXPWRCTL_ADDR_RX_PWR_CTRL_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_FSYN_ADDR - RIF BRF FSYN Address */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_FSYN_ADDR_FSYN_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_FSYN_ADDR_FSYN_ADDR_SHIFT (0U)
/*! Fsyn_Addr - Radio Register Start Address for Fsyn data */
#define BTU2_REG_BTU_RIF_BRF_FSYN_ADDR_FSYN_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_FSYN_ADDR_FSYN_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_FSYN_ADDR_FSYN_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_TXPWRCTL_ADDR - RIF BRF Tx Power Control Address */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_TXPWRCTL_ADDR_TX_PWR_CTRL_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_TXPWRCTL_ADDR_TX_PWR_CTRL_ADDR_SHIFT (0U)
/*! Tx_Pwr_Ctrl_Addr - Radio Register Address for Tx Power Control */
#define BTU2_REG_BTU_RIF_BRF_TXPWRCTL_ADDR_TX_PWR_CTRL_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_TXPWRCTL_ADDR_TX_PWR_CTRL_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_TXPWRCTL_ADDR_TX_PWR_CTRL_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_RSSI - BTC RIF dBus RSSI */
/*! @{ */

#define BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_DELAY_SHIFT (0U)
/*! DBus_RSSI_Delay - Delay from RSSI trigger to start of RSSI read */
#define BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_DELAY_MASK)

#define BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_ENABLE_SHIFT (15U)
/*! DBus_RSSI_Enable - Enable Automatic Reading of RSSI on the dBus
 *  0b0..disable automatic reading of RSSI
 *  0b1..enable automatic reading of RSSI
 */
#define BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_RSSI_DBUS_RSSI_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_TX_FSYN - RIF Tx dBus Fsyn */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_DELAY_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_DELAY_SHIFT (0U)
/*! DBus_Tx_Fsyn_Delay - Tx dBus Fsyn Delay */
#define BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_DELAY_MASK)

#define BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_WR_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_WR_ENABLE_SHIFT (15U)
/*! DBus_Tx_Fsyn_Wr_Enable - Tx dBus Fsyn Enable
 *  0b0..disable automatic sending of fsync info
 *  0b1..enable automatic sending of fsync info
 */
#define BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_WR_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_WR_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_TX_FSYN_DBUS_TX_FSYN_WR_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_FSYN - RIF Rx dBus Fsyn */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_DELAY_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_DELAY_SHIFT (0U)
/*! DBus_Rx_Fsyn_Delay - Rx dBus Hop Delay */
#define BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_DELAY_MASK)

#define BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_WR_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_WR_ENABLE_SHIFT (15U)
/*! DBus_Rx_Fsyn_Wr_Enable - Rx dBus Fsyn Enable
 *  0b0..disable automatic sending of fsync info
 *  0b1..enable automatic sending of fsync info
 */
#define BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_WR_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_WR_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_RX_FSYN_DBUS_RX_FSYN_WR_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_PKT_LEN - RIF dBus Rx Packet Length */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_CTE_LEN_ENABLE_MASK (0x4000U)
#define BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_CTE_LEN_ENABLE_SHIFT (14U)
/*! DBus_Rx_Cte_Len_Enable - dBus Rx CTE Length Enable
 *  0b0..disable automatic dbus sending Rx packet CTE length
 *  0b1..enable automatic dbus sending Rx packet CTE length
 */
#define BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_CTE_LEN_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_CTE_LEN_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_CTE_LEN_ENABLE_MASK)

#define BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_PKT_LEN_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_PKT_LEN_ENABLE_SHIFT (15U)
/*! DBus_Rx_Pkt_Len_Enable - dBus Rx Packet Length Enable
 *  0b0..disable automatic dbus sending Rx packet payload length
 *  0b1..enable automatic dbus sending Rx packet payload length
 */
#define BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_PKT_LEN_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_PKT_LEN_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_RX_PKT_LEN_DBUS_RX_PKT_LEN_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_PULSE_RX_DELAY - RIF BLE Pulse Rx Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_PULSE_RX_DELAY_BLE_PULSE_RX_DELAY_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BLE_PULSE_RX_DELAY_BLE_PULSE_RX_DELAY_SHIFT (0U)
/*! ble_Pulse_Rx_Delay - BLE Pulse Rx Delay */
#define BTU2_REG_BTU_RIF_BLE_PULSE_RX_DELAY_BLE_PULSE_RX_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_PULSE_RX_DELAY_BLE_PULSE_RX_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_PULSE_RX_DELAY_BLE_PULSE_RX_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_PULSE_TX_DELAY - RIF BLE Pulse Tx Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_PULSE_TX_DELAY_BLE_PULSE_TX_DELAY_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BLE_PULSE_TX_DELAY_BLE_PULSE_TX_DELAY_SHIFT (0U)
/*! ble_Pulse_Tx_Delay - BLE Pulse Tx Delay */
#define BTU2_REG_BTU_RIF_BLE_PULSE_TX_DELAY_BLE_PULSE_TX_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_PULSE_TX_DELAY_BLE_PULSE_TX_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_PULSE_TX_DELAY_BLE_PULSE_TX_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_MODE_TYPE - RIF dBus Rx Mode Type */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_RX_MODE_TYPE_DBUS_RX_MODE_TYPE_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_RX_MODE_TYPE_DBUS_RX_MODE_TYPE_ENABLE_SHIFT (15U)
/*! DBus_Rx_Mode_Type_Enable - dBus Rx Mode Type Enable
 *  0b0..disable automatic dbus sending Rx mode type
 *  0b1..enable automatic dbus sending Rx mode type
 */
#define BTU2_REG_BTU_RIF_DBUS_RX_MODE_TYPE_DBUS_RX_MODE_TYPE_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_RX_MODE_TYPE_DBUS_RX_MODE_TYPE_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_RX_MODE_TYPE_DBUS_RX_MODE_TYPE_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_MODE_TYPE_TX_DELAY - RIF Mode Type Tx Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_MODE_TYPE_TX_DELAY_MODE_TYPE_TX_DELAY_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_MODE_TYPE_TX_DELAY_MODE_TYPE_TX_DELAY_SHIFT (0U)
/*! Mode_Type_Tx_Delay - Mode Type Tx Delay */
#define BTU2_REG_BTU_RIF_MODE_TYPE_TX_DELAY_MODE_TYPE_TX_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_MODE_TYPE_TX_DELAY_MODE_TYPE_TX_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_MODE_TYPE_TX_DELAY_MODE_TYPE_TX_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_MODE_TYPE_RX_DELAY - RIF Mode Type Rx Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_MODE_TYPE_RX_DELAY_MODE_TYPE_RX_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_MODE_TYPE_RX_DELAY_MODE_TYPE_RX_DELAY_SHIFT (0U)
/*! Mode_Type_Rx_Delay - Mode Type Rx Delay */
#define BTU2_REG_BTU_RIF_MODE_TYPE_RX_DELAY_MODE_TYPE_RX_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_MODE_TYPE_RX_DELAY_MODE_TYPE_RX_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_MODE_TYPE_RX_DELAY_MODE_TYPE_RX_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_PKTCTL_OE_DELAY - RIF Packet Control OE Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_MODETYPE_MASK (0xFU)
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_MODETYPE_SHIFT (0U)
/*! Pkt_Ctl_Oe_Delay_ModeType - Packet Control OE Delay Mode Type */
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_MODETYPE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_MODETYPE_SHIFT)) & BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_MODETYPE_MASK)

#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_PPULSE_MASK (0xF0U)
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_PPULSE_SHIFT (4U)
/*! Pkt_Ctl_Oe_Delay_PPulse - Packet Control OE Delay P Pulse */
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_PPULSE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_PPULSE_SHIFT)) & BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_PPULSE_MASK)

#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_HDRSTART_MASK (0xF00U)
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_HDRSTART_SHIFT (8U)
/*! Pkt_Ctl_Oe_Delay_HdrStart - Packet Control OE Delay Header Start */
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_HDRSTART(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_HDRSTART_SHIFT)) & BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_PKT_CTL_OE_DELAY_HDRSTART_MASK)

#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_RF_BYPASS_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_RF_BYPASS_SHIFT (15U)
/*! RF_Bypass - Radio Bypass Mode Used for Baseband to Baseband Testing */
#define BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_RF_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_RF_BYPASS_SHIFT)) & BTU2_REG_BTU_RIF_PKTCTL_OE_DELAY_RF_BYPASS_MASK)
/*! @} */

/*! @name BTU_RIF_TXSYNC_GUARD_DELAY - RIF Tx Sync Guard Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_TXSYNC_GUARD_DELAY_TX_SYNC_GUARD_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_TXSYNC_GUARD_DELAY_TX_SYNC_GUARD_DELAY_SHIFT (0U)
/*! Tx_Sync_Guard_Delay - Tx Sync Guard Delay */
#define BTU2_REG_BTU_RIF_TXSYNC_GUARD_DELAY_TX_SYNC_GUARD_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TXSYNC_GUARD_DELAY_TX_SYNC_GUARD_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_TXSYNC_GUARD_DELAY_TX_SYNC_GUARD_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_RXSYNC_TIMER - RIF Rx Sync Timer */
/*! @{ */

#define BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_DELAY_MASK (0xFU)
#define BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_DELAY_SHIFT (0U)
/*! Rx_Sync_Timer_Delay - Rx Sync Timer Delay */
#define BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_DELAY_MASK)

#define BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_TIMEOUT_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_TIMEOUT_SHIFT (8U)
/*! Rx_Sync_Timer_Timeout - Rx Sync Timer Timeout */
#define BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_TIMEOUT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_TIMEOUT_SHIFT)) & BTU2_REG_BTU_RIF_RXSYNC_TIMER_RX_SYNC_TIMER_TIMEOUT_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_CTL - RIF Software dBus Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_ADDR_SHIFT (0U)
/*! sw_dbus_addr - dBus register address */
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_ADDR_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_FINISHED_MASK (0x400U)
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_FINISHED_SHIFT (10U)
/*! sw_dbus_finished - Poll status of dBus access
 *  0b0..busy
 *  0b1..finished
 */
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_FINISHED(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_FINISHED_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_FINISHED_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_SIZE_BYTES_MASK (0x3800U)
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_SIZE_BYTES_SHIFT (11U)
/*! sw_dbus_size_bytes - number of bytes to read or write
 *  0b000..1 byte
 *  0b001..2 bytes
 *  0b010..3 bytes
 *  0b011..4 bytes
 *  0b100..5 byteS
 *  0b101..6 bytes
 *  0b110..7 bytes
 *  0b111..8 bytes
 */
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_SIZE_BYTES(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_SIZE_BYTES_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_SIZE_BYTES_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_START_MASK (0x4000U)
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_START_SHIFT (14U)
/*! sw_dbus_start - Start a new dBus access */
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_START(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_START_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_START_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_RD_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_RD_SHIFT (15U)
/*! sw_dbus_rd - Read/write control
 *  0b0..write
 *  0b1..read
 */
#define BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_RD(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_RD_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_CTL_SW_DBUS_RD_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_EVENT - RIF Software dBus Event */
/*! @{ */

#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_COUNT_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_COUNT_SHIFT (0U)
/*! sw_dbus_count - Count to trigger software dBus */
#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_COUNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_COUNT_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_COUNT_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_RST_MASK (0x1000U)
#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_RST_SHIFT (12U)
/*! sw_dbus_rst - software dBus reset */
#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_RST(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_RST_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_RST_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_EVENT_MASK (0xC000U)
#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_EVENT_SHIFT (14U)
/*! sw_dbus_event - Event to trigger software dBus access
 *  0b00..SWDBUS_EVENT_NONPKT (when there is no packet activity)
 *  0b01..SWDBUS_EVENT_PKT_ASAP (as soon as possible during packet activity)
 *  0b10..SWDBUS_EVENT_PKT_START (when rif_startCount equals sw_dbus_count)
 *  0b11..SWDBUS_EVENT_PKT_END (when rif_endCount equals sw_dbus_count)
 */
#define BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_EVENT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_EVENT_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_EVENT_SW_DBUS_EVENT_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_1_0 - RIF Software dBus Data_1_0 */
/*! @{ */

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA0_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA0_SHIFT (0U)
/*! sw_dbus_wdata0 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA0_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA0_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA1_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA1_SHIFT (8U)
/*! sw_dbus_wdata1 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA1_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_1_0_SW_DBUS_WDATA1_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_3_2 - RIF Software dBus Data_3_2 */
/*! @{ */

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA2_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA2_SHIFT (0U)
/*! sw_dbus_wdata2 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA2(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA2_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA2_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA3_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA3_SHIFT (8U)
/*! sw_dbus_wdata3 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA3(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA3_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_3_2_SW_DBUS_WDATA3_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_5_4 - RIF Software dBus Data_5_4 */
/*! @{ */

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA4_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA4_SHIFT (0U)
/*! sw_dbus_wdata4 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA4(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA4_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA4_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA5_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA5_SHIFT (8U)
/*! sw_dbus_wdata5 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA5(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA5_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_5_4_SW_DBUS_WDATA5_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_7_6 - RIF Software dBus Data_7_6 */
/*! @{ */

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA6_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA6_SHIFT (0U)
/*! sw_dbus_wdata6 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA6(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA6_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA6_MASK)

#define BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA7_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA7_SHIFT (8U)
/*! sw_dbus_wdata7 - Software Access Data */
#define BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA7(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA7_SHIFT)) & BTU2_REG_BTU_RIF_SWDBUS_DATA_7_6_SW_DBUS_WDATA7_MASK)
/*! @} */

/*! @name BTU_RIF_TX_FESW - RIF Tx FESW */
/*! @{ */

#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_ON_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_ON_DELAY_SHIFT (0U)
/*! TX_Fesw_On_Delay - Tx FESW On Delay */
#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_ON_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_ON_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_ON_DELAY_MASK)

#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_OFF_DELAY_MASK (0x3F00U)
#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_OFF_DELAY_SHIFT (8U)
/*! TX_Fesw_Off_Delay - Tx FESW Off Delay */
#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_OFF_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_OFF_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_OFF_DELAY_MASK)

#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_EN_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_EN_SHIFT (15U)
/*! TX_Fesw_En - Tx Front-End Switch (FESW) Enable
 *  0b0..bttx_fesw is fixed to 0
 *  0b1..enable FESW during for Tx packets
 */
#define BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_EN(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_EN_SHIFT)) & BTU2_REG_BTU_RIF_TX_FESW_TX_FESW_EN_MASK)
/*! @} */

/*! @name BTU_RIF_RX_FESW - RIF Rx FESW */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_ON_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_ON_DELAY_SHIFT (0U)
/*! RX_FESW_On_Delay - Rx FESW On Delay */
#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_ON_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_ON_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_ON_DELAY_MASK)

#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_OFF_DELAY_MASK (0x3F00U)
#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_OFF_DELAY_SHIFT (8U)
/*! RX_FESW_Off_Delay - Rx FESW Off Delay */
#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_OFF_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_OFF_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_OFF_DELAY_MASK)

#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_EN_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_EN_SHIFT (15U)
/*! RX_FESW_En - Rx FESW Enable
 *  0b0..btrx_fesw is fixed to 0
 *  0b1..enable FESW during for Rx packets
 */
#define BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_EN(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_EN_SHIFT)) & BTU2_REG_BTU_RIF_RX_FESW_RX_FESW_EN_MASK)
/*! @} */

/*! @name BTU_RIF_RXPAON - RIF Rx PA On */
/*! @{ */

#define BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_DELAY_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_DELAY_SHIFT (0U)
/*! Rx_PA_On_Delay - Rx PA on Delay */
#define BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_DELAY_MASK)

#define BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_EN_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_EN_SHIFT (15U)
/*! Rx_PA_On_En - Rx PA On Delay Enable */
#define BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_EN(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_EN_SHIFT)) & BTU2_REG_BTU_RIF_RXPAON_RX_PA_ON_EN_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_PU - RIF BRF Power Up for RX */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_ON_DELAY_QUS_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_ON_DELAY_QUS_SHIFT (0U)
/*! brf_rx_pu_on_delay_qus - brf_pu on delay */
#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_ON_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_ON_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_ON_DELAY_QUS_MASK)

#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_OFF_DELAY_QUS_MASK (0x7F00U)
#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_OFF_DELAY_QUS_SHIFT (8U)
/*! brf_rx_pu_off_delay_qus - brf_pu off delay */
#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_OFF_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_OFF_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_OFF_DELAY_QUS_MASK)

#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_FIXED_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_FIXED_SHIFT (15U)
/*! brf_rx_pu_fixed - Set brf_pu to a fixed value.
 *  0b0..use programmable timers
 *  0b1..fixed, brf_pu = brf_pu_on_delay_us[0]
 */
#define BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_FIXED(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_FIXED_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RX_PU_BRF_RX_PU_FIXED_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_TX_PKT_END - BTC RIF dBus Tx Packet End Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_SHIFT (0U)
/*! DBus_Tx_Pkt_End_Delay - dBus Tx Packet End Delay */
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_MASK)

#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_ENABLE_SHIFT (15U)
/*! DBus_Tx_Pkt_End_Enable - Tx Packet End dBus Transaction Enable */
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_TX_PKT_END_DBUS_TX_PKT_END_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_RX_PKT_END - BTC RIF dBus Rx Packet End Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_SHIFT (0U)
/*! DBus_Rx_Pkt_End_Delay - dBus Rx Packet End Delay */
#define BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_MASK)

#define BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_ENABLE_SHIFT (15U)
/*! DBus_Rx_Pkt_End_Enable - Rx Packet End dBus Transaction Enable */
#define BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_RX_PKT_END_DBUS_RX_PKT_END_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_TX_RAMPDOWN - BTC RIF dBus Tx Rampdown Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_SHIFT (0U)
/*! DBus_Tx_Rampdown_Delay - dBus Tx Rampdown Delay */
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_MASK)

#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_ENABLE_SHIFT (15U)
/*! DBus_Tx_Rampdown_Enable - Enables Automatic Rampdown radio after Tx slot on the dBus
 *  0b0..disable automatic ramping down the radio after Tx slot
 *  0b1..enable automatic ramping down the radio after Tx slot
 */
#define BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_PATTERN_TX - RIF Error Pattern Tx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_PATTERN_TX_ERR_PATTERN_TX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_PATTERN_TX_ERR_PATTERN_TX_SHIFT (0U)
/*! Err_Pattern_Tx - 16-bit Error Pattern for Tx Packets
 *  0b0000000000000000..no error injection
 *  0b0000000000000001..flip corresponding bit of Tx packets
 */
#define BTU2_REG_BTU_RIF_ERR_PATTERN_TX_ERR_PATTERN_TX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_PATTERN_TX_ERR_PATTERN_TX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_PATTERN_TX_ERR_PATTERN_TX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_DELAY1_TX - RIF Error Delay 1 Tx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_DELAY1_TX_ERR_DELAY1_TX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_DELAY1_TX_ERR_DELAY1_TX_SHIFT (0U)
/*! Err_Delay1_Tx - Position of Error Insertion in Tx Packet */
#define BTU2_REG_BTU_RIF_ERR_DELAY1_TX_ERR_DELAY1_TX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_DELAY1_TX_ERR_DELAY1_TX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_DELAY1_TX_ERR_DELAY1_TX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_DELAY2_TX - RIF Error Delay 2 Tx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_DELAY2_TX_ERR_DELAY2_TX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_DELAY2_TX_ERR_DELAY2_TX_SHIFT (0U)
/*! Err_Delay2_Tx - Position of Error Insertion in Tx Packet */
#define BTU2_REG_BTU_RIF_ERR_DELAY2_TX_ERR_DELAY2_TX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_DELAY2_TX_ERR_DELAY2_TX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_DELAY2_TX_ERR_DELAY2_TX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_DELAY3_TX - RIF Error Delay 3 Tx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_DELAY3_TX_ERR_DELAY3_TX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_DELAY3_TX_ERR_DELAY3_TX_SHIFT (0U)
/*! Err_Delay3_Tx - Position of Error Insertion in Tx Packet */
#define BTU2_REG_BTU_RIF_ERR_DELAY3_TX_ERR_DELAY3_TX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_DELAY3_TX_ERR_DELAY3_TX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_DELAY3_TX_ERR_DELAY3_TX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_INJ_TX_CTRL - RIF Error Injection Tx Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_EN_MASK (0x1U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_EN_SHIFT (0U)
/*! Err_Tx_En - Error Injection Logic for Tx Packets
 *  0b0..disable all error injection logic for Tx packets
 *  0b1..enable error injection logic for Tx packets
 */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_EN_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_EN_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_MODE_MASK (0x2U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_MODE_SHIFT (1U)
/*! Err_Tx_Mode - Error Injection for Tx Packets
 *  0b0..inject error on nErr_Pkts_Tx number of Tx packets
 *  0b1..inject error on all Tx packets continuously based on Err_Delay'_Tx timer selected in Frame Scheduler
 */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_MODE_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_ERR_TX_MODE_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_NERR_PKTS_TX_MASK (0xFCU)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_NERR_PKTS_TX_SHIFT (2U)
/*! nErr_Pkts_Tx - Number of Tx Error Packets
 *  0b000000..corrupt infinite number of Tx packets
 *  0b000001..n/a
 */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_NERR_PKTS_TX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_NERR_PKTS_TX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_NERR_PKTS_TX_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMA_CRC_COR_MASK (0x100U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMA_CRC_COR_SHIFT (8U)
/*! tx_acl_dma_crc_cor - TX SCO AES Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMA_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMA_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMA_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_AES_CRC_COR_MASK (0x200U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_AES_CRC_COR_SHIFT (9U)
/*! tx_acl_aes_crc_cor - TX ACL DMEM Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_AES_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_AES_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_AES_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMEM_CRC_COR_MASK (0x400U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMEM_CRC_COR_SHIFT (10U)
/*! tx_acl_dmem_crc_cor - TX ACL DMA Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMEM_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMEM_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ACL_DMEM_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMA_CRC_COR_MASK (0x800U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMA_CRC_COR_SHIFT (11U)
/*! tx_esco_dma_crc_cor - TX SCO AES Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMA_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMA_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMA_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_AES_CRC_COR_MASK (0x1000U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_AES_CRC_COR_SHIFT (12U)
/*! tx_esco_aes_crc_cor - TX eSCO DMEM Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_AES_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_AES_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_AES_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMEM_CRC_COR_MASK (0x2000U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMEM_CRC_COR_SHIFT (13U)
/*! tx_esco_dmem_crc_cor - TX eSCO DMA Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMEM_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMEM_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_ESCO_DMEM_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_CRC_COR_EN_MASK (0x4000U)
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_CRC_COR_EN_SHIFT (14U)
/*! tx_crc_cor_en - Continous CRC corruption */
#define BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_CRC_COR_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_CRC_COR_EN_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_TX_CTRL_TX_CRC_COR_EN_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_PATTERN_RX - RIF Error Pattern Rx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_PATTERN_RX_ERR_PATTERN_RX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_PATTERN_RX_ERR_PATTERN_RX_SHIFT (0U)
/*! Err_Pattern_Rx - 16-bit Error Pattern for Rx Packets
 *  0b0000000000000000..no error injection
 *  0b0000000000000001..flip corresponding bit of Rx packets
 */
#define BTU2_REG_BTU_RIF_ERR_PATTERN_RX_ERR_PATTERN_RX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_PATTERN_RX_ERR_PATTERN_RX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_PATTERN_RX_ERR_PATTERN_RX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_DELAY1_RX - RIF Error Delay 1 Rx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_DELAY1_RX_ERR_DELAY1_RX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_DELAY1_RX_ERR_DELAY1_RX_SHIFT (0U)
/*! Err_Delay1_Rx - Position of Error Insertion in Rx Packet */
#define BTU2_REG_BTU_RIF_ERR_DELAY1_RX_ERR_DELAY1_RX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_DELAY1_RX_ERR_DELAY1_RX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_DELAY1_RX_ERR_DELAY1_RX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_DELAY2_RX - RIF Error Delay 2 Rx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_DELAY2_RX_ERR_DELAY2_RX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_DELAY2_RX_ERR_DELAY2_RX_SHIFT (0U)
/*! Err_Delay2_Rx - Position of Error Insertion in Rx Packet */
#define BTU2_REG_BTU_RIF_ERR_DELAY2_RX_ERR_DELAY2_RX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_DELAY2_RX_ERR_DELAY2_RX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_DELAY2_RX_ERR_DELAY2_RX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_DELAY3_RX - RIF Error Delay 3 Rx */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_DELAY3_RX_ERR_DELAY3_RX_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_ERR_DELAY3_RX_ERR_DELAY3_RX_SHIFT (0U)
/*! Err_Delay3_Rx - Position of Error Insertion in Rx Packet */
#define BTU2_REG_BTU_RIF_ERR_DELAY3_RX_ERR_DELAY3_RX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_DELAY3_RX_ERR_DELAY3_RX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_DELAY3_RX_ERR_DELAY3_RX_MASK)
/*! @} */

/*! @name BTU_RIF_ERR_INJ_RX_CTRL - RIF Error Injection Rx Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_EN_MASK (0x1U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_EN_SHIFT (0U)
/*! Err_Rx_En - Error Injection Logic for Rx Packets
 *  0b0..disable all error injection logic for Rx packets by programming Err_Rx_Mode, nErr_Pkts_Rx, and etc. have no effect at all
 *  0b1..enable error injection logic for Rx packets
 */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_EN_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_EN_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_MODE_MASK (0x2U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_MODE_SHIFT (1U)
/*! Err_Rx_Mode - Error Injection for Rx Packets
 *  0b0..inject error on nErr_Pkts_Rx number of Rx packets
 *  0b1..inject error on all Rx packets continuously based on Err_Delay'_Rx timer selected in Frame Scheduler
 */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_MODE_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_ERR_RX_MODE_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_NERR_PKTS_RX_MASK (0xFCU)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_NERR_PKTS_RX_SHIFT (2U)
/*! nErr_Pkts_Rx - Number of Rx Error Packets
 *  0b000000..corrupt infinite number of Rx packets
 *  0b000001..n/a
 */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_NERR_PKTS_RX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_NERR_PKTS_RX_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_NERR_PKTS_RX_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMA_CRC_COR_MASK (0x100U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMA_CRC_COR_SHIFT (8U)
/*! rx_acl_dma_crc_cor - RX ACL DMA Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMA_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMA_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMA_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_AES_CRC_COR_MASK (0x200U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_AES_CRC_COR_SHIFT (9U)
/*! rx_acl_aes_crc_cor - RX SCO AES Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_AES_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_AES_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_AES_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMEM_CRC_COR_MASK (0x400U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMEM_CRC_COR_SHIFT (10U)
/*! rx_acl_dmem_crc_cor - RX ACL DMEM Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMEM_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMEM_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ACL_DMEM_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMA_CRC_COR_MASK (0x800U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMA_CRC_COR_SHIFT (11U)
/*! rx_esco_dma_crc_cor - RX eSCO DMA Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMA_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMA_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMA_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_AES_CRC_COR_MASK (0x1000U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_AES_CRC_COR_SHIFT (12U)
/*! rx_esco_aes_crc_cor - RX SCO AES Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_AES_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_AES_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_AES_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMEM_CRC_COR_MASK (0x2000U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMEM_CRC_COR_SHIFT (13U)
/*! rx_esco_dmem_crc_cor - RX eSCO DMEM Error CRC Corruption Enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMEM_CRC_COR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMEM_CRC_COR_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_ESCO_DMEM_CRC_COR_MASK)

#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_CRC_COR_EN_MASK (0x4000U)
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_CRC_COR_EN_SHIFT (14U)
/*! rx_crc_cor_en - RX CRC corruption enable */
#define BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_CRC_COR_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_CRC_COR_EN_SHIFT)) & BTU2_REG_BTU_RIF_ERR_INJ_RX_CTRL_RX_CRC_COR_EN_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_COR_CONFIG_CTRL - RIF Correlator Configuration Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_DELAY_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_DELAY_SHIFT (0U)
/*! DBus_CorCfg_Wr_Delay - Rx Mode dBus BRF Correlator Configuration Control Delay */
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_DELAY_MASK)

#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_ANT_MASK (0x800U)
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_ANT_SHIFT (11U)
/*! Cor_Prem_Det_Gate_Syncwd_En_Ant - Enable BRF to start syncword detection after preamble found for Ant Mode */
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_ANT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_ANT_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_ANT_MASK)

#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_NIKE_MASK (0x1000U)
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_NIKE_SHIFT (12U)
/*! Cor_Prem_Det_Gate_Syncwd_En_Nike - Enable BRF to start syncword detection after preamble found for Nike Mode */
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_NIKE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_NIKE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_NIKE_MASK)

#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BLE_MASK (0x2000U)
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BLE_SHIFT (13U)
/*! Cor_Prem_Det_Gate_Syncwd_En_Ble - Enable BRF to start syncword detection after preamble found for BLE Mode */
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BLE_MASK)

#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BT_MASK (0x4000U)
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BT_SHIFT (14U)
/*! Cor_Prem_Det_Gate_Syncwd_En_Bt - Enable BRF to start syncword detection after preamble found for Bluetooth Mode */
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BT_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_COR_PREM_DET_GATE_SYNCWD_EN_BT_MASK)

#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_ENABLE_SHIFT (15U)
/*! DBus_CorCfg_Wr_Enable - Rx Mode dBus BRF Correlator Configuration Transaction Enable */
#define BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_COR_CONFIG_CTRL_DBUS_CORCFG_WR_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_COR_CONFIG_ADDR - RIF BRF Correlator Configuration Address */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_COR_CONFIG_ADDR_RX_COR_CFG_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_COR_CONFIG_ADDR_RX_COR_CFG_ADDR_SHIFT (0U)
/*! Rx_Cor_Cfg_Addr - Radio Register Address for Correlator Configuration */
#define BTU2_REG_BTU_RIF_BRF_COR_CONFIG_ADDR_RX_COR_CFG_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_COR_CONFIG_ADDR_RX_COR_CFG_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_COR_CONFIG_ADDR_RX_COR_CFG_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL - RIF Syncword and Access Code Send Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_DELAY_MASK (0x7FFU)
#define BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_DELAY_SHIFT (0U)
/*! DBus_Syncword_Wr_Delay - dBus Syncword and Access Code Control Delay */
#define BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_DELAY_MASK)

#define BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_ENABLE_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_ENABLE_SHIFT (15U)
/*! DBus_Syncword_Wr_Enable - Rx Mode dBus Syncword and Access Code Transaction Enable */
#define BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_ENABLE_SHIFT)) & BTU2_REG_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_DBUS_SYNCWORD_WR_ENABLE_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_ACC_CODE_ONE_ADDR - RIF BRF Access Code 1 Address */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_RX_ACC_CODE_ONE_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_RX_ACC_CODE_ONE_ADDR_SHIFT (0U)
/*! Rx_Acc_Code_One_Addr - Radio Register Address for First Access Code */
#define BTU2_REG_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_RX_ACC_CODE_ONE_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_RX_ACC_CODE_ONE_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_RX_ACC_CODE_ONE_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_ACC_CODE_TWO_ADDR - RIF Access Code 2 Address */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_RX_ACC_CODE_TWO_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_RX_ACC_CODE_TWO_ADDR_SHIFT (0U)
/*! Rx_Acc_Code_Two_Addr - Radio Register Address for Second Access Code */
#define BTU2_REG_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_RX_ACC_CODE_TWO_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_RX_ACC_CODE_TWO_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_RX_ACC_CODE_TWO_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_MODE_TYPE_ADDR - RIF Register */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_RX_MODE_TYPE_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_RX_MODE_TYPE_ADDR_SHIFT (0U)
/*! Rx_Mode_Type_Addr - Radio Register Address for Rx Mode Type */
#define BTU2_REG_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_RX_MODE_TYPE_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_RX_MODE_TYPE_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_RX_MODE_TYPE_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR - RIF Register */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_RX_PKT_PLD_LEN_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_RX_PKT_PLD_LEN_ADDR_SHIFT (0U)
/*! Rx_Pkt_Pld_Len_Addr - Radio Register Address for Rx Packet Payload Length */
#define BTU2_REG_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_RX_PKT_PLD_LEN_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_RX_PKT_PLD_LEN_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_RX_PKT_PLD_LEN_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_RX_SYNC_PULSE_TIMER - RIF BRF Rx Sync Pulse Timer */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_HDR_PULSE_TIMEOUT_MASK (0x1FU)
#define BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_HDR_PULSE_TIMEOUT_SHIFT (0U)
/*! Rx_Hdr_Pulse_Timeout - Rx Header Pulse Timeout */
#define BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_HDR_PULSE_TIMEOUT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_HDR_PULSE_TIMEOUT_SHIFT)) & BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_HDR_PULSE_TIMEOUT_MASK)

#define BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_SYNC_PULSE_TIMEOUT_MASK (0x1F00U)
#define BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_SYNC_PULSE_TIMEOUT_SHIFT (8U)
/*! Rx_Sync_Pulse_Timeout - Rx Sync Pulse Timeout */
#define BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_SYNC_PULSE_TIMEOUT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_SYNC_PULSE_TIMEOUT_SHIFT)) & BTU2_REG_BTU_RIF_RX_SYNC_PULSE_TIMER_RX_SYNC_PULSE_TIMEOUT_MASK)
/*! @} */

/*! @name BTU_RIF_RX_BTC_SAMP_PHASE_ADJ - RIF Rx Sample Phase Adjustment */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_POS_ADJ_MASK (0x3U)
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_POS_ADJ_SHIFT (0U)
/*! HDR_START_POS_ADJ - Positive Phase Adjustment after Header starts Pulse */
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_POS_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_POS_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_POS_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_NEG_ADJ_MASK (0xCU)
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_NEG_ADJ_SHIFT (2U)
/*! HDR_START_NEG_ADJ - Negative Phase Adjustment after Header starts Pulse */
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_NEG_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_NEG_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_HDR_START_NEG_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_POS_ADJ_MASK (0x300U)
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_POS_ADJ_SHIFT (8U)
/*! SYNC_START_POS_ADJ - Positive Phase Adjustment after Payload Sync starts Pulse */
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_POS_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_POS_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_POS_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_NEG_ADJ_MASK (0xC00U)
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_NEG_ADJ_SHIFT (10U)
/*! SYNC_START_NEG_ADJ - Negative Phase Adjustment after Header Starts Pulse */
#define BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_NEG_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_NEG_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_SYNC_START_NEG_ADJ_MASK)
/*! @} */

/*! @name BTU_RIF_RX_BLE_SAMP_PHASE_ADJ - RIF Rx Sample Phase Adjustment */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_POS_ADJ_MASK (0x3U)
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_POS_ADJ_SHIFT (0U)
/*! PDU_START_POS_ADJ - Positive Phase Adjustment after PDU Data starts Pulse */
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_POS_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_POS_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_POS_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_NEG_ADJ_MASK (0xCU)
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_NEG_ADJ_SHIFT (2U)
/*! PDU_START_NEG_ADJ - Negative Phase Adjustment after PDU Data starts Pulse */
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_NEG_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_NEG_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_PDU_START_NEG_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_POS_ADJ_MASK (0x300U)
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_POS_ADJ_SHIFT (8U)
/*! DFE_1M_PHASE_POS_ADJ - Positive Phase Adjustment for DFE I/Q Samples After CRC */
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_POS_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_POS_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_POS_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_NEG_ADJ_MASK (0xC00U)
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_NEG_ADJ_SHIFT (10U)
/*! DFE_1M_PHASE_NEG_ADJ - Negative Phase Adjustment for DFE I/Q Samples After CRC */
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_NEG_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_NEG_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_1M_PHASE_NEG_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_POS_ADJ_MASK (0x3000U)
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_POS_ADJ_SHIFT (12U)
/*! DFE_2M_PHASE_POS_ADJ - Positive Phase Adjustment for DFE I/Q Samples After CRC */
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_POS_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_POS_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_POS_ADJ_MASK)

#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_NEG_ADJ_MASK (0xC000U)
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_NEG_ADJ_SHIFT (14U)
/*! DFE_2M_PHASE_NEG_ADJ - Negative Phase Adjustment for DFE I/Q Samples After CRC */
#define BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_NEG_ADJ(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_NEG_ADJ_SHIFT)) & BTU2_REG_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_DFE_2M_PHASE_NEG_ADJ_MASK)
/*! @} */

/*! @name BTU_RIF_RX_TONE_CANCEL_CTRL - Rx Tone Cancellation Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_RX_DBUS_PULL_IN_TIME_MASK (0x3FU)
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_RX_DBUS_PULL_IN_TIME_SHIFT (0U)
/*! RX_DBUS_PULL_IN_TIME - Rx dBUS events pull-in time */
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_RX_DBUS_PULL_IN_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_RX_DBUS_PULL_IN_TIME_SHIFT)) & BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_RX_DBUS_PULL_IN_TIME_MASK)

#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BTC_PULL_IN_EN_MASK (0x100U)
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BTC_PULL_IN_EN_SHIFT (8U)
/*! BTC_PULL_IN_EN - BTC dBUS events pull-in enable
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BTC_PULL_IN_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BTC_PULL_IN_EN_SHIFT)) & BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BTC_PULL_IN_EN_MASK)

#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BLE_PULL_IN_EN_MASK (0x200U)
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BLE_PULL_IN_EN_SHIFT (9U)
/*! BLE_PULL_IN_EN - BLE dBUS events pull-in enable
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BLE_PULL_IN_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BLE_PULL_IN_EN_SHIFT)) & BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CTRL_BLE_PULL_IN_EN_MASK)
/*! @} */

/*! @name BTU_RIF_RX_TONE_CANCEL_CHNL10 - Rx Tone Cancellation Channel */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL0_MASK (0x7FU)
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL0_SHIFT (0U)
/*! TONE_CANCEL_CHNL0 - Rx Tone Cancellation Channel 0 */
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL0_SHIFT)) & BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL0_MASK)

#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL1_MASK (0x7F00U)
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL1_SHIFT (8U)
/*! TONE_CANCEL_CHNL1 - Rx Tone Cancellation Channel 1 */
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL1_SHIFT)) & BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL10_TONE_CANCEL_CHNL1_MASK)
/*! @} */

/*! @name BTU_RIF_RX_TONE_CANCEL_CHNL32 - Rx Tone Cancellation Channel */
/*! @{ */

#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL2_MASK (0x7FU)
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL2_SHIFT (0U)
/*! TONE_CANCEL_CHNL2 - Rx Tone Cancellation Channel 2 */
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL2(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL2_SHIFT)) & BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL2_MASK)

#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL3_MASK (0x7F00U)
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL3_SHIFT (8U)
/*! TONE_CANCEL_CHNL3 - Rx Tone Cancellation Channel 3 */
#define BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL3(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL3_SHIFT)) & BTU2_REG_BTU_RIF_RX_TONE_CANCEL_CHNL32_TONE_CANCEL_CHNL3_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CTL - BLE RIF Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_BRF_PU_MASK (0x2U)
#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_BRF_PU_SHIFT (1U)
/*! ble_brf_pu - BLE BRF Power up
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_BRF_PU(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CTL_BLE_BRF_PU_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CTL_BLE_BRF_PU_MASK)

#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_PLL_REQ_MASK (0x4U)
#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_PLL_REQ_SHIFT (2U)
/*! ble_pll_req - BLE PLL Clock Request
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_PLL_REQ(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CTL_BLE_PLL_REQ_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CTL_BLE_PLL_REQ_MASK)

#define BTU2_REG_BTU_RIF_BLE_CTL_DATA_LOOPBACK_EN_MASK (0x8U)
#define BTU2_REG_BTU_RIF_BLE_CTL_DATA_LOOPBACK_EN_SHIFT (3U)
/*! data_loopback_en - BLE Loopback Data Enable
 *  0b0..Rx data is from BRF
 *  0b1..Rx data is from Tx block
 */
#define BTU2_REG_BTU_RIF_BLE_CTL_DATA_LOOPBACK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CTL_DATA_LOOPBACK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CTL_DATA_LOOPBACK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CTL_RX_IQ_SAMPLE_PHASE_MASK (0x30U)
#define BTU2_REG_BTU_RIF_BLE_CTL_RX_IQ_SAMPLE_PHASE_SHIFT (4U)
/*! rx_iq_sample_phase - BLE Rx IQ Sampling Rate Phase */
#define BTU2_REG_BTU_RIF_BLE_CTL_RX_IQ_SAMPLE_PHASE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CTL_RX_IQ_SAMPLE_PHASE_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CTL_RX_IQ_SAMPLE_PHASE_MASK)

#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_FREQ_NR_MASK (0x7F00U)
#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_FREQ_NR_SHIFT (8U)
/*! ble_freq_nr - BLE Frequency Channel */
#define BTU2_REG_BTU_RIF_BLE_CTL_BLE_FREQ_NR(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CTL_BLE_FREQ_NR_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CTL_BLE_FREQ_NR_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_LENGTH_SEL - BLE Correlation Length Selection */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_LENGTH_SEL_MASK (0x3U)
#define BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_LENGTH_SEL_SHIFT (0U)
/*! ble_cor_length_sel - BLE Correlator Length Select
 *  0b00..32 bits
 *  0b01..24 bits
 *  0b10..16 bits
 *  0b11..not valid
 */
#define BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_LENGTH_SEL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_LENGTH_SEL_SHIFT)) & BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_LENGTH_SEL_MASK)

#define BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_INDICATOR_MASK (0xCU)
#define BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_INDICATOR_SHIFT (2U)
/*! ble_cor_indicator - BLE Correlator Indicator
 *  0b00..no correlator enabled
 *  0b01..correlator one enabled
 *  0b10..correlator two enabled
 *  0b11..both correlators enabled
 */
#define BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_INDICATOR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_INDICATOR_SHIFT)) & BTU2_REG_BTU_RIF_BLE_COR_LENGTH_SEL_BLE_COR_INDICATOR_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_ACCESSADDR_0 - BLE AccessCode */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_0_BLE_ACCESS_CODE_0_16_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_0_BLE_ACCESS_CODE_0_16_SHIFT (0U)
/*! ble_access_code_0_16 - BLE Access Code */
#define BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_0_BLE_ACCESS_CODE_0_16(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_0_BLE_ACCESS_CODE_0_16_SHIFT)) & BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_0_BLE_ACCESS_CODE_0_16_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_ACCESSADDR_1 - BLE AccessCode */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_1_BLE_ACCESS_CODE_17_32_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_1_BLE_ACCESS_CODE_17_32_SHIFT (0U)
/*! ble_access_code_17_32 - BLE Access Code */
#define BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_1_BLE_ACCESS_CODE_17_32(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_1_BLE_ACCESS_CODE_17_32_SHIFT)) & BTU2_REG_BTU_RIF_BLE_COR_ACCESSADDR_1_BLE_ACCESS_CODE_17_32_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_WINDOW_0 - BLE Correlation Window Size */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_COR_WINDOW_0_BLE_COR_WINDOW_0_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_BLE_COR_WINDOW_0_BLE_COR_WINDOW_0_SHIFT (0U)
/*! ble_cor_window_0 - BLE Correlation Window Size */
#define BTU2_REG_BTU_RIF_BLE_COR_WINDOW_0_BLE_COR_WINDOW_0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_COR_WINDOW_0_BLE_COR_WINDOW_0_SHIFT)) & BTU2_REG_BTU_RIF_BLE_COR_WINDOW_0_BLE_COR_WINDOW_0_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_WINDOW_1 - BLE Correlation Window Size */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_COR_WINDOW_1_BLE_COR_WINDOW_1_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BLE_COR_WINDOW_1_BLE_COR_WINDOW_1_SHIFT (0U)
/*! ble_cor_window_1 - BLE Correlation Window Size */
#define BTU2_REG_BTU_RIF_BLE_COR_WINDOW_1_BLE_COR_WINDOW_1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_COR_WINDOW_1_BLE_COR_WINDOW_1_SHIFT)) & BTU2_REG_BTU_RIF_BLE_COR_WINDOW_1_BLE_COR_WINDOW_1_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CLK_EN_DELAY - Tx/Rx Clock Enable Signal Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_TX_CLK_EN_DELAY_QUS_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_TX_CLK_EN_DELAY_QUS_SHIFT (0U)
/*! tx_clk_en_delay_qus - Tx_clk_en Delay Offset */
#define BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_TX_CLK_EN_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_TX_CLK_EN_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_TX_CLK_EN_DELAY_QUS_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_RX_CLK_EN_DELAY_QUS_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_RX_CLK_EN_DELAY_QUS_SHIFT (8U)
/*! rx_clk_en_delay_qus - Rx_clk_en Delay Offset */
#define BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_RX_CLK_EN_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_RX_CLK_EN_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_EN_DELAY_RX_CLK_EN_DELAY_QUS_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_GO_DELAY - RIF Go Signal Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_TX_GO_DELAY_QUS_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_TX_GO_DELAY_QUS_SHIFT (0U)
/*! rif_tx_go_delay_qus - RIF_TX_GO Delay Offset */
#define BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_TX_GO_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_TX_GO_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_TX_GO_DELAY_QUS_MASK)

#define BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_RX_GO_DELAY_QUS_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_RX_GO_DELAY_QUS_SHIFT (8U)
/*! rif_rx_go_delay_qus - RIF_RX_GO Delay Offset */
#define BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_RX_GO_DELAY_QUS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_RX_GO_DELAY_QUS_SHIFT)) & BTU2_REG_BTU_RIF_BLE_GO_DELAY_RIF_RX_GO_DELAY_QUS_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA - Tx Power Control DBUS Write Data */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_RIF_DBUS_TX_PWRCTL_WDATA_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_RIF_DBUS_TX_PWRCTL_WDATA_SHIFT (0U)
/*! rif_dbus_tx_pwrctl_wdata - Tx Power Control DBUS Write Data */
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_RIF_DBUS_TX_PWRCTL_WDATA(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_RIF_DBUS_TX_PWRCTL_WDATA_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_RIF_DBUS_TX_PWRCTL_WDATA_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_FSYN_WDATA - Tx Fsyn DBUS Write Data */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_RIF_DBUS_TX_FSYN_WDATA_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_RIF_DBUS_TX_FSYN_WDATA_SHIFT (0U)
/*! rif_dbus_tx_fsyn_wdata - Tx Fsyn DBUS Write Data */
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_RIF_DBUS_TX_FSYN_WDATA(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_RIF_DBUS_TX_FSYN_WDATA_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_RIF_DBUS_TX_FSYN_WDATA_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA - Rx Power Control DBUS Write Data */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_RIF_DBUS_RX_PWRCTL_WDATA_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_RIF_DBUS_RX_PWRCTL_WDATA_SHIFT (0U)
/*! rif_dbus_rx_pwrctl_wdata - Rx Power Control DBUS Write Data */
#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_RIF_DBUS_RX_PWRCTL_WDATA(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_RIF_DBUS_RX_PWRCTL_WDATA_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_RIF_DBUS_RX_PWRCTL_WDATA_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RX_FSYN_WDATA - Rx Fsyn DBUS Write Data */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_RIF_DBUS_RX_FSYN_WDATA_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_RIF_DBUS_RX_FSYN_WDATA_SHIFT (0U)
/*! rif_dbus_rx_fsyn_wdata - Rx Fsyn DBUS Write Data */
#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_RIF_DBUS_RX_FSYN_WDATA(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_RIF_DBUS_RX_FSYN_WDATA_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_RIF_DBUS_RX_FSYN_WDATA_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_RX_SYNC_DELAY - BLE Rx Sync Delay */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_SYNCPULSE_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_SYNCPULSE_DELAY_SHIFT (0U)
#define BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_SYNCPULSE_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_SYNCPULSE_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_SYNCPULSE_DELAY_MASK)

#define BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_DATAVLD_DELAY_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_DATAVLD_DELAY_SHIFT (8U)
#define BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_DATAVLD_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_DATAVLD_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_RX_SYNC_DELAY_BLE_RX_DATAVLD_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_CTE_LEN_ADDR - RIF Register */
/*! @{ */

#define BTU2_REG_BTU_RIF_BRF_RX_CTE_LEN_ADDR_RX_CTE_LEN_ADDR_MASK (0x3FFU)
#define BTU2_REG_BTU_RIF_BRF_RX_CTE_LEN_ADDR_RX_CTE_LEN_ADDR_SHIFT (0U)
/*! Rx_Cte_Len_Addr - Radio Register Address for Rx CTE Length */
#define BTU2_REG_BTU_RIF_BRF_RX_CTE_LEN_ADDR_RX_CTE_LEN_ADDR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BRF_RX_CTE_LEN_ADDR_RX_CTE_LEN_ADDR_SHIFT)) & BTU2_REG_BTU_RIF_BRF_RX_CTE_LEN_ADDR_RX_CTE_LEN_ADDR_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_BTC_START_TIME - RIF ARB BTC Start Time */
/*! @{ */

#define BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_TX_START_TIME_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_TX_START_TIME_SHIFT (0U)
#define BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_TX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_TX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_TX_START_TIME_MASK)

#define BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_RX_START_TIME_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_RX_START_TIME_SHIFT (8U)
#define BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_RX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_RX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BTC_START_TIME_BTC_RX_START_TIME_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_BLE_START_TIME_CODED - RIF ARB BLE Start Time */
/*! @{ */

#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_TX_START_TIME_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_TX_START_TIME_SHIFT (0U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_TX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_TX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_TX_START_TIME_MASK)

#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_RX_START_TIME_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_RX_START_TIME_SHIFT (8U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_RX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_RX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_CODED_BLE_RX_START_TIME_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_BLE_START_TIME_1M - RIF ARB BLE Start Time */
/*! @{ */

#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_TX_START_TIME_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_TX_START_TIME_SHIFT (0U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_TX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_TX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_TX_START_TIME_MASK)

#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_RX_START_TIME_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_RX_START_TIME_SHIFT (8U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_RX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_RX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_1M_BLE_RX_START_TIME_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_BLE_START_TIME_2M - RIF ARB BLE Start Time */
/*! @{ */

#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_TX_START_TIME_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_TX_START_TIME_SHIFT (0U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_TX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_TX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_TX_START_TIME_MASK)

#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_RX_START_TIME_MASK (0xFF00U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_RX_START_TIME_SHIFT (8U)
#define BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_RX_START_TIME(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_RX_START_TIME_SHIFT)) & BTU2_REG_BTU_RIF_ARB_BLE_START_TIME_2M_BLE_RX_START_TIME_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_CTL - RIF ARB Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_ARB_CTL_BTC_SW_ABORT_MASK (0x1U)
#define BTU2_REG_BTU_RIF_ARB_CTL_BTC_SW_ABORT_SHIFT (0U)
#define BTU2_REG_BTU_RIF_ARB_CTL_BTC_SW_ABORT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_BTC_SW_ABORT_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_BTC_SW_ABORT_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_BLE_SW_ABORT_MASK (0x2U)
#define BTU2_REG_BTU_RIF_ARB_CTL_BLE_SW_ABORT_SHIFT (1U)
#define BTU2_REG_BTU_RIF_ARB_CTL_BLE_SW_ABORT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_BLE_SW_ABORT_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_BLE_SW_ABORT_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_ANT_SW_ABORT_MASK (0x4U)
#define BTU2_REG_BTU_RIF_ARB_CTL_ANT_SW_ABORT_SHIFT (2U)
#define BTU2_REG_BTU_RIF_ARB_CTL_ANT_SW_ABORT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_ANT_SW_ABORT_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_ANT_SW_ABORT_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_RST_RIF_ARB_FSM_MASK (0x8U)
#define BTU2_REG_BTU_RIF_ARB_CTL_RST_RIF_ARB_FSM_SHIFT (3U)
/*! rst_rif_arb_fsm - RIF-ARB Reset */
#define BTU2_REG_BTU_RIF_ARB_CTL_RST_RIF_ARB_FSM(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_RST_RIF_ARB_FSM_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_RST_RIF_ARB_FSM_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_HI_PRI_CUTOFF_DIS_MASK (0x20U)
#define BTU2_REG_BTU_RIF_ARB_CTL_HI_PRI_CUTOFF_DIS_SHIFT (5U)
/*! Hi_pri_cutoff_dis - Disable Hi priority packet cutoff
 *  0b0..enable
 *  0b1..disable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_HI_PRI_CUTOFF_DIS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_HI_PRI_CUTOFF_DIS_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_HI_PRI_CUTOFF_DIS_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_MH_PRI_CUTOFF_DIS_MASK (0x40U)
#define BTU2_REG_BTU_RIF_ARB_CTL_MH_PRI_CUTOFF_DIS_SHIFT (6U)
/*! MH_pri_cutoff_dis - Disable MH priority packet cutoff
 *  0b0..enable
 *  0b1..disable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_MH_PRI_CUTOFF_DIS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_MH_PRI_CUTOFF_DIS_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_MH_PRI_CUTOFF_DIS_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_ML_PRI_CUTOFF_DIS_MASK (0x80U)
#define BTU2_REG_BTU_RIF_ARB_CTL_ML_PRI_CUTOFF_DIS_SHIFT (7U)
/*! ML_pri_cutoff_dis - Disable ML priority packet cutoff
 *  0b0..enable
 *  0b1..disable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_ML_PRI_CUTOFF_DIS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_ML_PRI_CUTOFF_DIS_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_ML_PRI_CUTOFF_DIS_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_BTC_SYNC_FRAME_EN_MASK (0x100U)
#define BTU2_REG_BTU_RIF_ARB_CTL_BTC_SYNC_FRAME_EN_SHIFT (8U)
/*! btc_sync_frame_en - Enable btc_sync_frame in arbitration decision
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_BTC_SYNC_FRAME_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_BTC_SYNC_FRAME_EN_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_BTC_SYNC_FRAME_EN_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_BLE_SYNC_FRAME_EN_MASK (0x200U)
#define BTU2_REG_BTU_RIF_ARB_CTL_BLE_SYNC_FRAME_EN_SHIFT (9U)
/*! ble_sync_frame_en - Enable ble_sync_frame in arbitration decision
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_BLE_SYNC_FRAME_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_BLE_SYNC_FRAME_EN_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_BLE_SYNC_FRAME_EN_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_CTL_1 - RIF ARB Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_HI_MASK (0x7U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_HI_SHIFT (0U)
/*! eq_pri_winner_Hi - Arbitration rule for if BTC, BLE and ANT packet are same High priority
 *  0b000..BTC > BLE > ANT
 *  0b001..BLE > BTC > ANT
 *  0b010..BTC > ANT > BLE
 *  0b011..BLE > ANT > BTC
 *  0b100..ANT > BTC > BLE
 *  0b101..ANT > BLE > BTC
 *  0b110..Simple Round Robin
 *  0b111..reserved
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_HI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_HI_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_HI_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_HI_CUTOFF_DIS_MASK (0x8U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_HI_CUTOFF_DIS_SHIFT (3U)
/*! eq_pri_Hi_cutoff_dis - Disable Hi priority packet cutoff
 *  0b0..enable
 *  0b1..disable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_HI_CUTOFF_DIS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_HI_CUTOFF_DIS_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_HI_CUTOFF_DIS_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_MH_MASK (0x70U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_MH_SHIFT (4U)
/*! eq_pri_winner_MH - Arbitration rule for if BTC, BLE and ANT packet are same MH priority
 *  0b000..BTC > BLE > ANT
 *  0b001..BLE > BTC > ANT
 *  0b010..BTC > ANT > BLE
 *  0b011..BLE > ANT > BTC
 *  0b100..ANT > BTC > BLE
 *  0b101..ANT > BLE > BTC
 *  0b110..Simple Round Robin
 *  0b111..reserved
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_MH(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_MH_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_MH_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_MH_CUTOFF_DIS_MASK (0x80U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_MH_CUTOFF_DIS_SHIFT (7U)
/*! eq_pri_MH_cutoff_dis - Disable MH priority packet cutoff
 *  0b0..enable
 *  0b1..disable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_MH_CUTOFF_DIS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_MH_CUTOFF_DIS_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_MH_CUTOFF_DIS_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_ML_MASK (0x700U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_ML_SHIFT (8U)
/*! eq_pri_winner_ML - Arbitration rule for if BTC, BLE and ANT packet are same ML priority
 *  0b000..BTC > BLE > ANT
 *  0b001..BLE > BTC > ANT
 *  0b010..BTC > ANT > BLE
 *  0b011..BLE > ANT > BTC
 *  0b100..ANT > BTC > BLE
 *  0b101..ANT > BLE > BTC
 *  0b110..Simple Round Robin
 *  0b111..reserved
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_ML(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_ML_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_ML_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_ML_CUTOFF_DIS_MASK (0x800U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_ML_CUTOFF_DIS_SHIFT (11U)
/*! eq_pri_ML_cutoff_dis - Disable ML priority packet cutoff
 *  0b0..enable
 *  0b1..disable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_ML_CUTOFF_DIS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_ML_CUTOFF_DIS_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_ML_CUTOFF_DIS_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_LO_MASK (0x7000U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_LO_SHIFT (12U)
/*! eq_pri_winner_Lo - Arbitration rule for if BTC, BLE and ANT packet are same Low priority
 *  0b000..BTC > BLE > ANT
 *  0b001..BLE > BTC > ANT
 *  0b010..BTC > ANT > BLE
 *  0b011..BLE > ANT > BTC
 *  0b100..ANT > BTC > BLE
 *  0b101..ANT > BLE > BTC
 *  0b110..Simple Round Robin
 *  0b111..reserved
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_LO(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_LO_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_WINNER_LO_MASK)

#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_LO_CUTOFF_DIS_MASK (0x8000U)
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_LO_CUTOFF_DIS_SHIFT (15U)
/*! eq_pri_Lo_cutoff_dis - Disable Lo priority packet cutoff
 *  0b0..enable
 *  0b1..disable
 */
#define BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_LO_CUTOFF_DIS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_LO_CUTOFF_DIS_SHIFT)) & BTU2_REG_BTU_RIF_ARB_CTL_1_EQ_PRI_LO_CUTOFF_DIS_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_SEL_0 - RIF Testbus Select 0 */
/*! @{ */

#define BTU2_REG_BTU_RIF_TESTBUS_SEL_0_BTU_TESTBUS_SEL_0_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_TESTBUS_SEL_0_BTU_TESTBUS_SEL_0_SHIFT (0U)
/*! btu_testbus_sel_0 - RIF Testbus Select, Lower Bits
 *  0b0000000000000000..get btc_testbus_out[i]
 *  0b0000000000000001..get ble_testbus_out[i]
 *  0b0000000000000010..get ble_debug_sw_msg_out(URAT)
 *  0b0000000000000011..get ble_test_sw_out[i]
 */
#define BTU2_REG_BTU_RIF_TESTBUS_SEL_0_BTU_TESTBUS_SEL_0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TESTBUS_SEL_0_BTU_TESTBUS_SEL_0_SHIFT)) & BTU2_REG_BTU_RIF_TESTBUS_SEL_0_BTU_TESTBUS_SEL_0_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_SEL_1 - RIF Testbus Select 1 */
/*! @{ */

#define BTU2_REG_BTU_RIF_TESTBUS_SEL_1_BTU_TESTBUS_SEL_1_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_TESTBUS_SEL_1_BTU_TESTBUS_SEL_1_SHIFT (0U)
/*! btu_testbus_sel_1 - RIF Testbus Select, Upper Bits
 *  0b0000000000000000..get btc_testbus_out[i]
 *  0b0000000000000001..get ble_testbus_out[i]
 *  0b0000000000000010..get ble_debug_sw_msg_out(URAT)
 *  0b0000000000000011..get ble_test_sw_out[i]
 */
#define BTU2_REG_BTU_RIF_TESTBUS_SEL_1_BTU_TESTBUS_SEL_1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TESTBUS_SEL_1_BTU_TESTBUS_SEL_1_SHIFT)) & BTU2_REG_BTU_RIF_TESTBUS_SEL_1_BTU_TESTBUS_SEL_1_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_OE - BTU Testbus Output Enable */
/*! @{ */

#define BTU2_REG_BTU_RIF_TESTBUS_OE_BTU_TESTBUS_OE__MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_TESTBUS_OE_BTU_TESTBUS_OE__SHIFT (0U)
/*! btu_testbus_oe_ - Debug testbus output enable */
#define BTU2_REG_BTU_RIF_TESTBUS_OE_BTU_TESTBUS_OE_(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TESTBUS_OE_BTU_TESTBUS_OE__SHIFT)) & BTU2_REG_BTU_RIF_TESTBUS_OE_BTU_TESTBUS_OE__MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_SW_OUTDATA - BLE Debug Output Data */
/*! @{ */

#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_OUTDATA_TESTBUS_SW_OUT_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_OUTDATA_TESTBUS_SW_OUT_SHIFT (0U)
/*! testbus_sw_out - BLE debug software control testbus ouput */
#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_OUTDATA_TESTBUS_SW_OUT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_REG_DEBUG_SW_OUTDATA_TESTBUS_SW_OUT_SHIFT)) & BTU2_REG_BTU_RIF_REG_DEBUG_SW_OUTDATA_TESTBUS_SW_OUT_MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_INDATA - BLE Debug Input Data */
/*! @{ */

#define BTU2_REG_BTU_RIF_REG_DEBUG_INDATA_TESTBUS_IN_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_REG_DEBUG_INDATA_TESTBUS_IN_SHIFT (0U)
/*! testbus_in - BLE debug testbus input */
#define BTU2_REG_BTU_RIF_REG_DEBUG_INDATA_TESTBUS_IN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_REG_DEBUG_INDATA_TESTBUS_IN_SHIFT)) & BTU2_REG_BTU_RIF_REG_DEBUG_INDATA_TESTBUS_IN_MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_SW_MSG - BLE Debug Software Message */
/*! @{ */

#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_DEBUG_SW_MSG_MASK (0xFFFFU)
#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_DEBUG_SW_MSG_SHIFT (0U)
/*! DEBUG_SW_MSG - Debug message */
#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_DEBUG_SW_MSG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_DEBUG_SW_MSG_SHIFT)) & BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_DEBUG_SW_MSG_MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT - BLE Debug Software Message FIFO Count */
/*! @{ */

#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_BLE_REG_DEBUG_SW_MSG_FIFO_CNT_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_BLE_REG_DEBUG_SW_MSG_FIFO_CNT_SHIFT (0U)
/*! BLE_REG_DEBUG_SW_MSG_FIFO_CNT - Debug message FIFO count */
#define BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_BLE_REG_DEBUG_SW_MSG_FIFO_CNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_BLE_REG_DEBUG_SW_MSG_FIFO_CNT_SHIFT)) & BTU2_REG_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_BLE_REG_DEBUG_SW_MSG_FIFO_CNT_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_CONTROL - RIF Testbus Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_TESTBUS_CONTROL_BTU_RIF_TESTBUS_CONTROL_MASK (0xFU)
#define BTU2_REG_BTU_RIF_TESTBUS_CONTROL_BTU_RIF_TESTBUS_CONTROL_SHIFT (0U)
/*! BTU_RIF_TESTBUS_CONTROL - Testbus bank rotation */
#define BTU2_REG_BTU_RIF_TESTBUS_CONTROL_BTU_RIF_TESTBUS_CONTROL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_TESTBUS_CONTROL_BTU_RIF_TESTBUS_CONTROL_SHIFT)) & BTU2_REG_BTU_RIF_TESTBUS_CONTROL_BTU_RIF_TESTBUS_CONTROL_MASK)
/*! @} */

/*! @name BTU_RIF_BT_CLK_GATING - RIF Bluetooth Clock Gating */
/*! @{ */

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_EN_MASK (0x1U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_EN_SHIFT (0U)
/*! bt_reg_btc_force_clk_en - BTC Force Clock Enable */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_AES_CLK_EN_MASK (0x2U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_AES_CLK_EN_SHIFT (1U)
/*! bt_reg_aes_clk_en - AES Clock Enable */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_AES_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_AES_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_AES_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_4M_CLK_EN_MASK (0x4U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_4M_CLK_EN_SHIFT (2U)
/*! bt_reg_rif_rx_4m_clk_en - RIF Rx 4M Clock Enable
 *  0b0..rif_rx_4m_clk_en controls clock gating
 *  0b1..forces rif_rx_4m_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_4M_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_4M_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_4M_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_16M_CLK_EN_MASK (0x8U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_16M_CLK_EN_SHIFT (3U)
/*! bt_reg_rif_rx_16m_clk_en - RIF Rx 16M Clock Enable
 *  0b0..rif_rx_16m_clk_en controls clock gating for rif_rx_16m_clk
 *  0b1..forces rif_rx_16m_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_16M_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_16M_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_RIF_RX_16M_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ONE_MASK (0x10U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ONE_SHIFT (4U)
/*! bt_reg_btc_force_clk_one - BTC Force Clock One */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ONE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ONE_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ONE_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ZERO_MASK (0x20U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ZERO_SHIFT (5U)
/*! bt_reg_btc_force_clk_zero - BTC Force Clock Zero */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ZERO(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ZERO_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_BTC_FORCE_CLK_ZERO_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_FORCE_EBRAM_SYSCLK_EN_MASK (0x40U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_FORCE_EBRAM_SYSCLK_EN_SHIFT (6U)
/*! bt_reg_force_ebram_sysclk_en - Force EBRAM ebSysClk enable */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_FORCE_EBRAM_SYSCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_FORCE_EBRAM_SYSCLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BT_REG_FORCE_EBRAM_SYSCLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_CLK_REQ_EARLY_ASSERT_MASK (0x100U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_CLK_REQ_EARLY_ASSERT_SHIFT (8U)
/*! btc_clk_req_early_assert - BTC_clk_req early assertion upon any BTC AHB access */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_CLK_REQ_EARLY_ASSERT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_CLK_REQ_EARLY_ASSERT_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_CLK_REQ_EARLY_ASSERT_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_LCCLKENOUT_EARLY_UNGATE_MASK (0x200U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_LCCLKENOUT_EARLY_UNGATE_SHIFT (9U)
/*! lcClkEnOut_early_ungate - lcClkEnOut early upgated upon any BTC AHB access */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_LCCLKENOUT_EARLY_UNGATE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_LCCLKENOUT_EARLY_UNGATE_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_LCCLKENOUT_EARLY_UNGATE_MASK)

#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_SYS_4M_EARLY_UNGATE_MASK (0x400U)
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_SYS_4M_EARLY_UNGATE_SHIFT (10U)
/*! btc_sys_4m_early_ungate - BTC_sys_clk and btc_4m_clk early ungated upon any BTC AHB access */
#define BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_SYS_4M_EARLY_UNGATE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_SYS_4M_EARLY_UNGATE_SHIFT)) & BTU2_REG_BTU_RIF_BT_CLK_GATING_BTC_SYS_4M_EARLY_UNGATE_MASK)
/*! @} */

/*! @name BTU_RIF_CLK_SMPLD - RIF Clock Sampled */
/*! @{ */

#define BTU2_REG_BTU_RIF_CLK_SMPLD_BTU_4M_SMPLD_MUX_MASK (0x1U)
#define BTU2_REG_BTU_RIF_CLK_SMPLD_BTU_4M_SMPLD_MUX_SHIFT (0U)
/*! btu_4m_smpld_mux - 4M Sampled MUX */
#define BTU2_REG_BTU_RIF_CLK_SMPLD_BTU_4M_SMPLD_MUX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CLK_SMPLD_BTU_4M_SMPLD_MUX_SHIFT)) & BTU2_REG_BTU_RIF_CLK_SMPLD_BTU_4M_SMPLD_MUX_MASK)

#define BTU2_REG_BTU_RIF_CLK_SMPLD_RIF_RX_4M_SMPLD_MUX_MASK (0x2U)
#define BTU2_REG_BTU_RIF_CLK_SMPLD_RIF_RX_4M_SMPLD_MUX_SHIFT (1U)
/*! rif_rx_4m_smpld_mux - RIF Rx 4M Sampled MUX */
#define BTU2_REG_BTU_RIF_CLK_SMPLD_RIF_RX_4M_SMPLD_MUX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CLK_SMPLD_RIF_RX_4M_SMPLD_MUX_SHIFT)) & BTU2_REG_BTU_RIF_CLK_SMPLD_RIF_RX_4M_SMPLD_MUX_MASK)

#define BTU2_REG_BTU_RIF_CLK_SMPLD_LPOCLK_SMPLD_MUX_MASK (0x4U)
#define BTU2_REG_BTU_RIF_CLK_SMPLD_LPOCLK_SMPLD_MUX_SHIFT (2U)
/*! lpoClk_smpld_mux - LPO Clock Sampled MUX
 *  0b0..selects old way for lpoClkSmpld signal generation
 *  0b1..selects new way for lpoClkSmpls signal generation
 */
#define BTU2_REG_BTU_RIF_CLK_SMPLD_LPOCLK_SMPLD_MUX(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_CLK_SMPLD_LPOCLK_SMPLD_MUX_SHIFT)) & BTU2_REG_BTU_RIF_CLK_SMPLD_LPOCLK_SMPLD_MUX_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CLK_GATING - RIF BLE Clock Gating */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLEEP_CLK_EN_MASK (0x1U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLEEP_CLK_EN_SHIFT (0U)
/*! bt_reg_ble_sleep_clk_en - BLE Sleep Clock Enable */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLEEP_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLEEP_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLEEP_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_FORCE_CLK_EN_MASK (0x2U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_FORCE_CLK_EN_SHIFT (1U)
/*! bt_reg_ble_force_clk_en - BLE Force Clock Enable */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_FORCE_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_FORCE_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_FORCE_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLV_HCLK_EN_MASK (0x4U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLV_HCLK_EN_SHIFT (2U)
/*! bt_reg_ble_slv_hclk_en - BLE Slave HCLK Enable
 *  0b0..ble_slv_hclk_en controls clock gating dynamically
 *  0b1..forces ble_sys_td_clk_en to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLV_HCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLV_HCLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_SLV_HCLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_MST_HCLK_EN_MASK (0x8U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_MST_HCLK_EN_SHIFT (3U)
/*! bt_reg_ble_mst_hclk_en - BLE Master HCLK Enable
 *  0b0..ble_mst_hclk_en controls clock gating
 *  0b1..forces ble_mst_hclk to 1
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_MST_HCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_MST_HCLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_MST_HCLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RIC_SYS_CLK_EN_MASK (0x10U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RIC_SYS_CLK_EN_SHIFT (4U)
/*! bt_reg_ble_ric_sys_clk_en - BLE RIC System Clock Enable
 *  0b0..ble_ric_sys_clk_en controls dynamic clock gating
 *  0b1..force ble_ric_sys_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RIC_SYS_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RIC_SYS_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RIC_SYS_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TX_CLK_EN_MASK (0x20U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TX_CLK_EN_SHIFT (5U)
/*! bt_reg_ble_tx_clk_en - BLE Tx Clock Enable
 *  0b0..ble_tx_clk_en controls clock gating for ble_tx_clk
 *  0b1..forces ble_tx_clk; also forces ble_td_sys_clk_en to be set
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TX_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TX_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RX_CLK_EN_MASK (0x40U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RX_CLK_EN_SHIFT (6U)
/*! bt_reg_ble_rx_clk_en - BLE Rx Clock Enable
 *  0b0..ble_rx_clk controls clock gating dynamically
 *  0b1..forces ble_rx_clk clocks to turn on; also forces ble_rd_sys_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RX_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RX_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TD_SYS_CLK_EN_MASK (0x80U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TD_SYS_CLK_EN_SHIFT (7U)
/*! bt_reg_ble_td_sys_clk_en - BLE TD System Clock Enable
 *  0b0..ble_td_sys_clk_en controls clock gating dynamically
 *  0b1..forces ble_td_sys_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TD_SYS_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TD_SYS_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_TD_SYS_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RD_SYS_CLK_EN_MASK (0x100U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RD_SYS_CLK_EN_SHIFT (8U)
/*! bt_reg_ble_rd_sys_clk_en - BLE RD System Clock Enable
 *  0b0..ble_rd_sys_clk_en controls dynamic clock gating
 *  0b1..forces ble_rd_sys_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RD_SYS_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RD_SYS_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RD_SYS_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RL_SYS_CLK_EN_MASK (0x200U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RL_SYS_CLK_EN_SHIFT (9U)
/*! bt_reg_ble_rl_sys_clk_en - BLE RD System Clock Enable
 *  0b0..ble_rl_sys_clk_en controls dynamic clock gating
 *  0b1..forces forces ble_rl_sys_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RL_SYS_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RL_SYS_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_RL_SYS_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_WL_SYS_CLK_EN_MASK (0x400U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_WL_SYS_CLK_EN_SHIFT (10U)
/*! bt_reg_ble_wl_sys_clk_en - BLE Whitelist Search System Clock Enable
 *  0b0..ble_wl_sys_clk_en controls dynamic clock gating
 *  0b1..forces ble_wl_sys_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_WL_SYS_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_WL_SYS_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_WL_SYS_CLK_EN_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_IRK_SYS_CLK_EN_MASK (0x800U)
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_IRK_SYS_CLK_EN_SHIFT (11U)
/*! bt_reg_ble_irk_sys_clk_en - BLE IRK resolve System Clock Enable
 *  0b0..ble_irk_sys_clk_en controls dynamic clock gating
 *  0b1..forces ble_irk_sys_clk to turn on
 */
#define BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_IRK_SYS_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_IRK_SYS_CLK_EN_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_GATING_BT_REG_BLE_IRK_SYS_CLK_EN_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CLK_CTRL - RIF BLE Clock Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ZERO_MASK (0x1U)
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ZERO_SHIFT (0U)
/*! bt_reg_force_ble_clk_req_zero - Force BLE Clock Req Zero */
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ZERO(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ZERO_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ZERO_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ONE_MASK (0x2U)
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ONE_SHIFT (1U)
/*! bt_reg_force_ble_clk_req_one - Force BLE Clock Req One */
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ONE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ONE_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BT_REG_FORCE_BLE_CLK_REQ_ONE_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_AWAKE_STS_MASK (0x10U)
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_AWAKE_STS_SHIFT (4U)
/*! ble_awake_sts - BLE Awake Status */
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_AWAKE_STS(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_AWAKE_STS_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_AWAKE_STS_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_CLK_REQ_EARLY_ASSERT_MASK (0x100U)
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_CLK_REQ_EARLY_ASSERT_SHIFT (8U)
/*! ble_clk_req_early_assert - ble_clk_req early assertion upon any BLE AHB access */
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_CLK_REQ_EARLY_ASSERT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_CLK_REQ_EARLY_ASSERT_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_CLK_REQ_EARLY_ASSERT_MASK)

#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_SYS_4M_EARLY_UNGATE_MASK (0x200U)
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_SYS_4M_EARLY_UNGATE_SHIFT (9U)
/*! ble_sys_4m_early_ungate - ble_sys_clk and ble_4m_clk early ungated upon any BLE AHB access */
#define BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_SYS_4M_EARLY_UNGATE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_SYS_4M_EARLY_UNGATE_SHIFT)) & BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_SYS_4M_EARLY_UNGATE_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_PKT_END - BLE RIF dBus Tx Packet End Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_SHIFT (0U)
/*! DBus_Tx_Pkt_End_Delay - dBus Tx Packet End Delay */
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_TX_PKT_END_DBUS_TX_PKT_END_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RX_PKT_END - BLE RIF dBus Rx Packet End Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_SHIFT (0U)
/*! DBus_Rx_Pkt_End_Delay - dBus Rx Packet End Delay */
#define BTU2_REG_BTU_RIF_BLE_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_RX_PKT_END_DBUS_RX_PKT_END_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_RAMPDOWN - BLE RIF dBus Tx Rampdown Control */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_SHIFT (0U)
/*! DBus_Tx_Rampdown_Delay - dBus Tx Rampdown Delay */
#define BTU2_REG_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_DBUS_TX_RAMPDOWN_DELAY_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RSSI - BLE RIF dBus RSSI */
/*! @{ */

#define BTU2_REG_BTU_RIF_BLE_DBUS_RSSI_DBUS_RSSI_DELAY_MASK (0xFFU)
#define BTU2_REG_BTU_RIF_BLE_DBUS_RSSI_DBUS_RSSI_DELAY_SHIFT (0U)
/*! DBus_RSSI_Delay - Delay from RSSI trigger to start of RSSI read */
#define BTU2_REG_BTU_RIF_BLE_DBUS_RSSI_DBUS_RSSI_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_RIF_BLE_DBUS_RSSI_DBUS_RSSI_DELAY_SHIFT)) & BTU2_REG_BTU_RIF_BLE_DBUS_RSSI_DBUS_RSSI_DELAY_MASK)
/*! @} */

/*! @name BTU_PTA_SEL_PRI_HIGH - PTA High Priority Select for RIF_ARB Arbitration */
/*! @{ */

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSSWITCHPRI_MASK (0x1U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSSWITCHPRI_SHIFT (0U)
/*! msSwitchPri - Master / Slave Switch */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSSWITCHPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSSWITCHPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSSWITCHPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PAGEPRI_MASK (0x2U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PAGEPRI_SHIFT (1U)
/*! pagePri - Page */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PAGEPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PAGEPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PAGEPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PSCANPRI_MASK (0x4U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PSCANPRI_SHIFT (2U)
/*! pScanPri - Page Scan */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PSCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PSCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_PSCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_INQPRI_MASK (0x8U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_INQPRI_SHIFT (3U)
/*! inqPri - Inquiry */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_INQPRI(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_INQPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_INQPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ISCANPRI_MASK (0x10U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ISCANPRI_SHIFT (4U)
/*! iScanPri - Inquiry Scan */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ISCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ISCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ISCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITTXPRI_MASK (0x20U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITTXPRI_SHIFT (5U)
/*! llrInitTxPri - LLR Initiator Tx priority */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITTXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITTXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITTXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITRXPRI_MASK (0x40U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITRXPRI_SHIFT (6U)
/*! llrInitRxPri - LLR Initiator Rx priority */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITRXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITRXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_LLRINITRXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCOINSTPRI_MASK (0x80U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCOINSTPRI_SHIFT (7U)
/*! eScoInstPri - eSCO Instant */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCOINSTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCOINSTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCOINSTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCORETRPRI_MASK (0x100U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCORETRPRI_SHIFT (8U)
/*! eScoRetrPri - eSCO Retransmission */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCORETRPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCORETRPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ESCORETRPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SCOPRI_MASK (0x200U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SCOPRI_SHIFT (9U)
/*! scoPri - SCO */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SCOPRI(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SCOPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SCOPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_BROADCASTPRI_MASK (0x400U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_BROADCASTPRI_SHIFT (10U)
/*! broadcastPri - Broadcast */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_BROADCASTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_BROADCASTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_BROADCASTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ACLPRI_MASK (0x800U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ACLPRI_SHIFT (11U)
/*! aclPri - ACL */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ACLPRI(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ACLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_ACLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_IRESPPRI_MASK (0x1000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_IRESPPRI_SHIFT (12U)
/*! iRespPri - Inquiry Response */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_IRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_IRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_IRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SLVRESPPRI_MASK (0x2000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SLVRESPPRI_SHIFT (13U)
/*! slvRespPri - Slave Page Response */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SLVRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SLVRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_SLVRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_POLLPRI_MASK (0x4000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_POLLPRI_SHIFT (14U)
/*! pollPri - Poll packet */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_POLLPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_POLLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_POLLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSTRRESPPRI_MASK (0x8000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSTRRESPPRI_SHIFT (15U)
/*! mstrRespPri - Master Page Response */
#define BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSTRRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSTRRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_HIGH_MSTRRESPPRI_MASK)
/*! @} */

/*! @name BTU_PTA_CTRL - PTA Control */
/*! @{ */

#define BTU2_REG_BTU_PTA_CTRL_BTC_PRIORITY_MODE_MASK (0x1U)
#define BTU2_REG_BTU_PTA_CTRL_BTC_PRIORITY_MODE_SHIFT (0U)
/*! btc_priority_mode - BTC BCA Coex Priority Mode
 *  0b0..BTC BCA coex priority is the same as PTA coex priority for RIF_ARB arbitration
 *  0b1..BTC BCA coex priority is from packet transaction request which falls in BTU_PTA_SEL_BCA_PRI_HIGH/BTU_PTA_SEL_BCA_PRI_MED category
 */
#define BTU2_REG_BTU_PTA_CTRL_BTC_PRIORITY_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_BTC_PRIORITY_MODE_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_BTC_PRIORITY_MODE_MASK)

#define BTU2_REG_BTU_PTA_CTRL_BTC_USE_SAM_MASK   (0x4U)
#define BTU2_REG_BTU_PTA_CTRL_BTC_USE_SAM_SHIFT  (2U)
/*! btc_use_sam - SAM Coexistence Feature Enable */
#define BTU2_REG_BTU_PTA_CTRL_BTC_USE_SAM(x)     (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_BTC_USE_SAM_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_BTC_USE_SAM_MASK)

#define BTU2_REG_BTU_PTA_CTRL_SLVNORESPABORT_MASK (0x20U)
#define BTU2_REG_BTU_PTA_CTRL_SLVNORESPABORT_SHIFT (5U)
/*! slvNoRespAbort - Slave No Response Abort Enable
 *  0b0..Deasserts after Rx-to-Tx slot change
 *  0b1..Deasserts immediately after HEC received
 */
#define BTU2_REG_BTU_PTA_CTRL_SLVNORESPABORT(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_SLVNORESPABORT_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_SLVNORESPABORT_MASK)

#define BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_EN_MASK (0x40U)
#define BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_EN_SHIFT (6U)
/*! bt_grant_bypass_en - BCA coex grant bypass enable
 *  0b0..disable bt_grant_n bypass
 *  0b1..enable bt_grant_n bypass
 */
#define BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_EN_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_EN_MASK)

#define BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_VAL_MASK (0x80U)
#define BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_VAL_SHIFT (7U)
/*! bt_grant_bypass_val - BCA coex grant bypass value
 *  0b0..set BCA coex grant bt_grant_n to zero
 *  0b1..set BCA coex grant bt_grant_n to one
 */
#define BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_VAL_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_BT_GRANT_BYPASS_VAL_MASK)

#define BTU2_REG_BTU_PTA_CTRL_CLRALLTXCNTRS_MASK (0x100U)
#define BTU2_REG_BTU_PTA_CTRL_CLRALLTXCNTRS_SHIFT (8U)
/*! clrAllTxCntrs - Clear All Tx Counters
 *  0b0..do not clear counters
 *  0b1..clear counters
 */
#define BTU2_REG_BTU_PTA_CTRL_CLRALLTXCNTRS(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_CLRALLTXCNTRS_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_CLRALLTXCNTRS_MASK)

#define BTU2_REG_BTU_PTA_CTRL_ACLPRIINCEN_MASK   (0x400U)
#define BTU2_REG_BTU_PTA_CTRL_ACLPRIINCEN_SHIFT  (10U)
/*! aclPriIncEn - ACL Priority Escalation Enable
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_PTA_CTRL_ACLPRIINCEN(x)     (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_ACLPRIINCEN_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_ACLPRIINCEN_MASK)

#define BTU2_REG_BTU_PTA_CTRL_MRVLCOEXEXITEN_MASK (0x800U)
#define BTU2_REG_BTU_PTA_CTRL_MRVLCOEXEXITEN_SHIFT (11U)
/*! mrvlCoexExitEn - Marvell Coexistence Exit Enable
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_PTA_CTRL_MRVLCOEXEXITEN(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_CTRL_MRVLCOEXEXITEN_SHIFT)) & BTU2_REG_BTU_PTA_CTRL_MRVLCOEXEXITEN_MASK)
/*! @} */

/*! @name BTU_PTA_REQ_DELAY_TIMER - PTA Bt_Req Delay Timer */
/*! @{ */

#define BTU2_REG_BTU_PTA_REQ_DELAY_TIMER_PTA_REQ_DELAY_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_REQ_DELAY_TIMER_PTA_REQ_DELAY_SHIFT (0U)
/*! pta_req_delay - PTA Request Delay */
#define BTU2_REG_BTU_PTA_REQ_DELAY_TIMER_PTA_REQ_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_REQ_DELAY_TIMER_PTA_REQ_DELAY_SHIFT)) & BTU2_REG_BTU_PTA_REQ_DELAY_TIMER_PTA_REQ_DELAY_MASK)
/*! @} */

/*! @name BTU_PTA_SEL_PRI_MED - PTA Medium Priority Select for RIF_ARB Arbitration */
/*! @{ */

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_MSSWITCHPRI_MASK (0x1U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_MSSWITCHPRI_SHIFT (0U)
/*! msSwitchPri - Master / Slave Switch */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_MSSWITCHPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_MSSWITCHPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_MSSWITCHPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_PAGEPRI_MASK (0x2U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_PAGEPRI_SHIFT (1U)
/*! pagePri - Page */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_PAGEPRI(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_PAGEPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_PAGEPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_PSCANPRI_MASK (0x4U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_PSCANPRI_SHIFT (2U)
/*! pScanPri - Page Scan */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_PSCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_PSCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_PSCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_INQPRI_MASK (0x8U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_INQPRI_SHIFT (3U)
/*! inqPri - Inquiry */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_INQPRI(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_INQPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_INQPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ISCANPRI_MASK (0x10U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ISCANPRI_SHIFT (4U)
/*! iScanPri - Inquiry Scan */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ISCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_ISCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_ISCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITTXPRI_MASK (0x20U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITTXPRI_SHIFT (5U)
/*! llrInitTxPri - LLR Initiator Tx priority */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITTXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITTXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITTXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITRXPRI_MASK (0x40U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITRXPRI_SHIFT (6U)
/*! llrInitRxPri - LLR Initiator Rx priority */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITRXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITRXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_LLRINITRXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCOINSTPRI_MASK (0x80U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCOINSTPRI_SHIFT (7U)
/*! eScoInstPri - eSCO Instant */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCOINSTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCOINSTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCOINSTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCORETRPRI_MASK (0x100U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCORETRPRI_SHIFT (8U)
/*! eScoRetrPri - eSCO Retransmission */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCORETRPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCORETRPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_ESCORETRPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_SCOPRI_MASK (0x200U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_SCOPRI_SHIFT (9U)
/*! scoPri - SCO */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_SCOPRI(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_SCOPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_SCOPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_BROADCASTPRI_MASK (0x400U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_BROADCASTPRI_SHIFT (10U)
/*! broadcastPri - Broadcast */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_BROADCASTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_BROADCASTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_BROADCASTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ACLPRI_MASK (0x800U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ACLPRI_SHIFT (11U)
/*! aclPri - ACL */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_ACLPRI(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_ACLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_ACLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_IRESPPRI_MASK (0x1000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_IRESPPRI_SHIFT (12U)
/*! iRespPri - Inquiry Response */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_IRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_IRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_IRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_SLVRESPPRI_MASK (0x2000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_SLVRESPPRI_SHIFT (13U)
/*! slvRespPri - Slave Page Response */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_SLVRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_SLVRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_SLVRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_POLLPRI_MASK (0x4000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_POLLPRI_SHIFT (14U)
/*! pollPri - Poll packet */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_POLLPRI(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_POLLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_POLLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_PRI_MED_MSTRRESPPRI_MASK (0x8000U)
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_MSTRRESPPRI_SHIFT (15U)
/*! mstrRespPri - Master Page Response */
#define BTU2_REG_BTU_PTA_SEL_PRI_MED_MSTRRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_PRI_MED_MSTRRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_PRI_MED_MSTRRESPPRI_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_RIF_ARB_COEX_PRI - BLE PTA Priority for BTC/BLE arbitration */
/*! @{ */

#define BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_TX_PRI_MASK (0x3U)
#define BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_TX_PRI_SHIFT (0U)
/*! ble_tx_pri - BLE Coex Priority */
#define BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_TX_PRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_TX_PRI_SHIFT)) & BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_TX_PRI_MASK)

#define BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_RX_PRI_MASK (0x300U)
#define BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_RX_PRI_SHIFT (8U)
/*! ble_rx_pri - BLE Coex Priority */
#define BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_RX_PRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_RX_PRI_SHIFT)) & BTU2_REG_BTU_PTA_BLE_RIF_ARB_COEX_PRI_BLE_RX_PRI_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_BCA_COEX_PRI - BLE PTA Priority for BCA arbitration */
/*! @{ */

#define BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_TX_PRI_MASK (0x3U)
#define BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_TX_PRI_SHIFT (0U)
/*! ble_tx_pri - BLE Coex Priority */
#define BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_TX_PRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_TX_PRI_SHIFT)) & BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_TX_PRI_MASK)

#define BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_RX_PRI_MASK (0x300U)
#define BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_RX_PRI_SHIFT (8U)
/*! ble_rx_pri - BLE Coex Priority */
#define BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_RX_PRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_RX_PRI_SHIFT)) & BTU2_REG_BTU_PTA_BLE_BCA_COEX_PRI_BLE_RX_PRI_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_INACTIVITY_REFCLK_0 - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_0_MWSINACTMSG_REFCLK_MASK (0xFFFFU)
#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_0_MWSINACTMSG_REFCLK_SHIFT (0U)
/*! mwsInactMsg_refClk - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_0_MWSINACTMSG_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_0_MWSINACTMSG_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_0_MWSINACTMSG_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_INACTIVITY_REFCLK_1 - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_1_MWSINACTMSG_REFCLK_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_1_MWSINACTMSG_REFCLK_SHIFT (0U)
/*! mwsInactMsg_refClk - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_1_MWSINACTMSG_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_1_MWSINACTMSG_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFCLK_1_MWSINACTMSG_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_INACTIVITY_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_MWSINACTMSG_PDBITCNT_MASK (0x1FFFU)
#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_MWSINACTMSG_PDBITCNT_SHIFT (0U)
/*! mwsInactMsg_pdBitCnt - Bluetooth Reference pdBitCounter Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
#define BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_MWSINACTMSG_PDBITCNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_MWSINACTMSG_PDBITCNT_SHIFT)) & BTU2_REG_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_MWSINACTMSG_PDBITCNT_MASK)
/*! @} */

/*! @name BTU_PTA_INBAND_FREQ_SET_1 - PTA Inband Frequency Set 0 */
/*! @{ */

#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_LO_MASK (0xFFU)
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_LO_SHIFT (0U)
/*! BT_In_Band_Lo - Bluetooth In Band Low */
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_LO(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_LO_SHIFT)) & BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_LO_MASK)

#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_HI_MASK (0xFF00U)
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_HI_SHIFT (8U)
/*! BT_In_Band_Hi - Bluetooth In Band High */
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_HI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_HI_SHIFT)) & BTU2_REG_BTU_PTA_INBAND_FREQ_SET_1_BT_IN_BAND_HI_MASK)
/*! @} */

/*! @name BTU_PTA_MODE_SELECT - PTA Mode Select */
/*! @{ */

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_COEX_MODE_MASK (0x7U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_COEX_MODE_SHIFT (0U)
/*! BT_Coex_Mode - Bluetooth Coexistence Mode Select
 *  0b000..disable
 *  0b001..CSR mode
 *  0b010..MRVL mode
 *  0b011..SUSHI mode
 */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_COEX_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_COEX_MODE_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_COEX_MODE_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_MWS_COEX_EN_MASK (0x8U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_MWS_COEX_EN_SHIFT (3U)
/*! BT_Mws_Coex_En - Bluetooth and MWS Coexistence Mode Enable */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_MWS_COEX_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_MWS_COEX_EN_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_MWS_COEX_EN_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_OVLP_MODE_MASK (0x10U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_OVLP_MODE_SHIFT (4U)
/*! bt_ovlp_mode - Bluetooth Overlap Mode
 *  0b0..non-filtered, old design
 *  0b1..filtered mode
 */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_OVLP_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_OVLP_MODE_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_OVLP_MODE_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_OVLP_SUPRESS_EN_MASK (0x20U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_OVLP_SUPRESS_EN_SHIFT (5U)
/*! ovlp_supress_en - Overlap Suppression Enable
 *  0b0..disable
 *  0b1..enable BT_Overlap/BT_Scan_Overlap assertion to BCA will be suppressed if Tx_Power_Index Value is less
 *       than the programmed BTU_PTA_TX_POWER_THRESHOLD for BR/EDR packet type or is less than
 *       BTU_PTA_BLE_TX_PWR_THRHD for BLE packet.
 */
#define BTU2_REG_BTU_PTA_MODE_SELECT_OVLP_SUPRESS_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_OVLP_SUPRESS_EN_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_OVLP_SUPRESS_EN_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_MODE_MASK (0x40U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_MODE_SHIFT (6U)
/*! bt_scan_ovlp_mode - Bluetooth Scan Overlap Mode
 *  0b0..non-filtered, old design
 *  0b1..filtered mode
 */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_MODE_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_MODE_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_RX_EN_MASK (0x80U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_RX_EN_SHIFT (7U)
/*! bt_scan_ovlp_rx_en - Scan Overlap for Bluetooth Rx
 *  0b0..disable
 *  0b1..enable
 */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_RX_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_RX_EN_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_SCAN_OVLP_RX_EN_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_3DG_COEX_EN_MASK (0x100U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_3DG_COEX_EN_SHIFT (8U)
/*! BT_3dg_Coex_En - Bluetooth and 3D-Glass Coexistence Mode Enable */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_3DG_COEX_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_3DG_COEX_EN_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_3DG_COEX_EN_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_IN_BAND1_FREQ_EN_MASK (0x200U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_IN_BAND1_FREQ_EN_SHIFT (9U)
/*! BT_In_Band1_Freq_En - BTU_PTA_INBAND_FREQ_SET_1 Band Gap Use Enable */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_IN_BAND1_FREQ_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_IN_BAND1_FREQ_EN_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_IN_BAND1_FREQ_EN_MASK)

#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_TX_ON_MODE_MASK (0xC000U)
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_TX_ON_MODE_SHIFT (14U)
/*! bt_tx_on_mode - BT_TX_ON mode selection */
#define BTU2_REG_BTU_PTA_MODE_SELECT_BT_TX_ON_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MODE_SELECT_BT_TX_ON_MODE_SHIFT)) & BTU2_REG_BTU_PTA_MODE_SELECT_BT_TX_ON_MODE_MASK)
/*! @} */

/*! @name BTU_PTA_INBAND_FREQ_SET_0 - PTA Inband Frequency Set 1 */
/*! @{ */

#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_LO_MASK (0xFFU)
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_LO_SHIFT (0U)
/*! BT_In_Band_Lo - Bluetooth In Band Low */
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_LO(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_LO_SHIFT)) & BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_LO_MASK)

#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_HI_MASK (0xFF00U)
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_HI_SHIFT (8U)
/*! BT_In_Band_Hi - Bluetooth In Band High */
#define BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_HI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_HI_SHIFT)) & BTU2_REG_BTU_PTA_INBAND_FREQ_SET_0_BT_IN_BAND_HI_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0 - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_HARQPATTERNSEL_REFCLK_MASK (0xFFFFU)
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_HARQPATTERNSEL_REFCLK_SHIFT (0U)
/*! harqPatternSel_refClk - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_HARQPATTERNSEL_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_HARQPATTERNSEL_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_HARQPATTERNSEL_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1 - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_HARQPATTERNSEL_REFCLK_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_HARQPATTERNSEL_REFCLK_SHIFT (0U)
/*! harqPatternSel_refClk - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_HARQPATTERNSEL_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_HARQPATTERNSEL_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_HARQPATTERNSEL_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_HARQPATTERNSEL_PDBITCNT_MASK (0x1FFFU)
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_HARQPATTERNSEL_PDBITCNT_SHIFT (0U)
/*! harqPatternSel_pdBitCnt - Bluetooth Reference pdBitCounter Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_HARQPATTERNSEL_PDBITCNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_HARQPATTERNSEL_PDBITCNT_SHIFT)) & BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_HARQPATTERNSEL_PDBITCNT_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_VAL - MWS Coex Signal HARQ_PATTERN_SEL Value */
/*! @{ */

#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_HARQPATTERNSELREG_MASK (0xFU)
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_HARQPATTERNSELREG_SHIFT (0U)
/*! harqPatternSelReg - MWS Coex Signal HARQ_PATTERN_SEL Value */
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_HARQPATTERNSELREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_HARQPATTERNSELREG_SHIFT)) & BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_HARQPATTERNSELREG_MASK)

#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_MWSINACTMSGREG_MASK (0x1F00U)
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_MWSINACTMSGREG_SHIFT (8U)
/*! mwsInactMsgReg - MWS Coex Signal MWS_INACT_MSG Value */
#define BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_MWSINACTMSGREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_MWSINACTMSGREG_SHIFT)) & BTU2_REG_BTU_PTA_HARQ_PATTERN_SEL_VAL_MWSINACTMSGREG_MASK)
/*! @} */

/*! @name BTU_PTA_INFO_DELAY_TIMER - PTA Info Delay Timer */
/*! @{ */

#define BTU2_REG_BTU_PTA_INFO_DELAY_TIMER_PTA_INFO_DELAY_MASK (0x7U)
#define BTU2_REG_BTU_PTA_INFO_DELAY_TIMER_PTA_INFO_DELAY_SHIFT (0U)
/*! pta_info_delay - Bluetooth Sniff Interval */
#define BTU2_REG_BTU_PTA_INFO_DELAY_TIMER_PTA_INFO_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_INFO_DELAY_TIMER_PTA_INFO_DELAY_SHIFT)) & BTU2_REG_BTU_PTA_INFO_DELAY_TIMER_PTA_INFO_DELAY_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_SYNC_CTRL - PTA BLE Sync Control */
/*! @{ */

#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_PRIORITY_MASK (0x3U)
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_PRIORITY_SHIFT (0U)
/*! ble_sync_priority - BLE Sync Priority */
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_PRIORITY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_PRIORITY_SHIFT)) & BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_PRIORITY_MASK)

#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_DIR_MASK (0x4U)
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_DIR_SHIFT (2U)
/*! ble_sync_dir - BLE Sync Direction
 *  0b0..Rx first
 *  0b1..Tx first
 */
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_DIR(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_DIR_SHIFT)) & BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_DIR_MASK)

#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_FW_VAL_MASK (0x8U)
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_FW_VAL_SHIFT (3U)
/*! ble_sync_frame_fw_val - BLE Sync Frame Firmware Value */
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_FW_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_FW_VAL_SHIFT)) & BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_FW_VAL_MASK)

#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_EXTEND_MASK (0x10U)
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_EXTEND_SHIFT (4U)
/*! ble_sync_frame_extend - BLE Sync Frame Extend
 *  0b0..sync_frame value will be de-asserted at falling edge of bt_req
 *  0b1..sync_frame value will be extended
 */
#define BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_EXTEND(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_EXTEND_SHIFT)) & BTU2_REG_BTU_PTA_BLE_SYNC_CTRL_BLE_SYNC_FRAME_EXTEND_MASK)
/*! @} */

/*! @name BTU_PTA_SYNC_CTRL - PTA Voice/WLAN Sync Control */
/*! @{ */

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_VAL_MASK (0x3U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_VAL_SHIFT (0U)
/*! sync_priority_fw_val - Sync Priority */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_VAL_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_VAL_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_VAL_MASK (0x4U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_VAL_SHIFT (2U)
/*! sync_dir_fw_val - Sync Direction
 *  0b0..Rx first
 *  0b1..Tx first
 */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_VAL_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_VAL_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_MODE_EN_MASK (0x8U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_MODE_EN_SHIFT (3U)
/*! sync_mode_en - Sync Mode Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_MODE_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_MODE_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FS_EN_MASK (0x10U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FS_EN_SHIFT (4U)
/*! sync_fs_en - Sync Frame Scheduler Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FS_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FS_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FS_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_EN_MASK (0x20U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_EN_SHIFT (5U)
/*! sync_frame_fw_en - Sync Frame Firmware Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_VAL_MASK (0x40U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_VAL_SHIFT (6U)
/*! sync_frame_fw_val - Sync Frame Firmware Value */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_VAL_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_FRAME_FW_VAL_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_SCO_EN_MASK (0x80U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_SCO_EN_SHIFT (7U)
/*! sync_sco_en - Sync SCO Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_SCO_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_SCO_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_SCO_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_INST_EN_MASK (0x100U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_INST_EN_SHIFT (8U)
/*! sync_esco_inst_en - Sync eSCO Instant Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_INST_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_INST_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_INST_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_RETR_EN_MASK (0x200U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_RETR_EN_SHIFT (9U)
/*! sync_esco_retr_en - Sync eSCO Retry Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_RETR_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_RETR_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_RETR_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_ACTIVE_EN_MASK (0x400U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_ACTIVE_EN_SHIFT (10U)
/*! sync_esco_active_en - Sync eSCO Active Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_ACTIVE_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_ACTIVE_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ESCO_ACTIVE_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_VAL_MASK (0x1000U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_VAL_SHIFT (12U)
/*! sync_active_fw_val - Sync Frame Active Firmware Value */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_VAL_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_VAL_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_EN_MASK (0x2000U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_EN_SHIFT (13U)
/*! sync_active_fw_en - Sync Frame Active Firmware Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_ACTIVE_FW_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_EN_MASK (0x4000U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_EN_SHIFT (14U)
/*! sync_priority_fw_en - Sync Frame Priority Firmware Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_PRIORITY_FW_EN_MASK)

#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_EN_MASK (0x8000U)
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_EN_SHIFT (15U)
/*! sync_dir_fw_en - Sync Frame Direction Firmware Enable */
#define BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_EN_SHIFT)) & BTU2_REG_BTU_PTA_SYNC_CTRL_SYNC_DIR_FW_EN_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_TX_PWR_THRHD - BLE Tx Power Threshold to Suppress Tx Overlap Assertion */
/*! @{ */

#define BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE1M_TX_PWR_THRSHLD_MASK (0xFFU)
#define BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE1M_TX_PWR_THRSHLD_SHIFT (0U)
/*! ble1M_tx_pwr_thrshld - BLE Tx power threshold for 1 Mbps packet to suppress BT_Overlap/BT_Scan_Overlap assertion */
#define BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE1M_TX_PWR_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE1M_TX_PWR_THRSHLD_SHIFT)) & BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE1M_TX_PWR_THRSHLD_MASK)

#define BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE2M_TX_PWR_THRSHLD_MASK (0xFF00U)
#define BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE2M_TX_PWR_THRSHLD_SHIFT (8U)
/*! ble2M_tx_pwr_thrshld - BLE Tx power threshold for 2 Mbps packet to suppress BT_Overlap/BT_Scan_Overlap assertion */
#define BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE2M_TX_PWR_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE2M_TX_PWR_THRSHLD_SHIFT)) & BTU2_REG_BTU_PTA_BLE_TX_PWR_THRHD_BLE2M_TX_PWR_THRSHLD_MASK)
/*! @} */

/*! @name BTU_PTA_STATE_DELAY_TIMER - PTA Bt_State Delay Timer */
/*! @{ */

#define BTU2_REG_BTU_PTA_STATE_DELAY_TIMER_PTA_STATE_DELAY_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_STATE_DELAY_TIMER_PTA_STATE_DELAY_SHIFT (0U)
/*! pta_state_delay - PTA State Delay */
#define BTU2_REG_BTU_PTA_STATE_DELAY_TIMER_PTA_STATE_DELAY(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_STATE_DELAY_TIMER_PTA_STATE_DELAY_SHIFT)) & BTU2_REG_BTU_PTA_STATE_DELAY_TIMER_PTA_STATE_DELAY_MASK)
/*! @} */

/*! @name BTU_PTA_SLNA_CTRL - PTA SLNA Control */
/*! @{ */

#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_USE_SLNA_MASK (0x1U)
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_USE_SLNA_SHIFT (0U)
/*! ble_use_slna - BLE uses SLNA based on RSSI info
 *  0b0..use path 3 for Bluetooth only based on BLE RSSI average
 *  0b1..enable SLNA path based on BLE RSSI average
 */
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_USE_SLNA(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_USE_SLNA_SHIFT)) & BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_USE_SLNA_MASK)

#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_SEL_MASK (0x2U)
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_SEL_SHIFT (1U)
/*! ble_slna_cp_en_bp_sel - BLE side enable SLNA bias/charge pump bypass for software control
 *  0b0..use hardware dynamically controlled SLNA_cp_en
 *  0b1..software bypass to control the SLNA_cp_en
 */
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_SEL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_SEL_SHIFT)) & BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_SEL_MASK)

#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_VAL_MASK (0x4U)
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_VAL_SHIFT (2U)
/*! ble_slna_cp_en_bp_val - SLNA_cp Enable
 *  0b0..eisable SLNA cp
 *  0b1..enable SLNA cp
 */
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_VAL_SHIFT)) & BTU2_REG_BTU_PTA_SLNA_CTRL_BLE_SLNA_CP_EN_BP_VAL_MASK)

#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_USE_SLNA_MASK (0x100U)
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_USE_SLNA_SHIFT (8U)
/*! btc_use_slna - BTC uses SLNA based on RSSI info
 *  0b0..use path 3 for Bluetooth only based on BTC RSSI average
 *  0b1..enable SLNA path based on BTC RSSI average
 */
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_USE_SLNA(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_USE_SLNA_SHIFT)) & BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_USE_SLNA_MASK)

#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_SEL_MASK (0x200U)
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_SEL_SHIFT (9U)
/*! btc_slna_cp_en_bp_sel - BTC side enable SLNA bias/charge pump bypass for software control
 *  0b0..use hardware dynamically controlled SLNA_cp_en
 *  0b1..software bypass to control the SLNA_cp_en
 */
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_SEL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_SEL_SHIFT)) & BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_SEL_MASK)

#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_VAL_MASK (0x400U)
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_VAL_SHIFT (10U)
/*! btc_slna_cp_en_bp_val - SLNA_cp Enable
 *  0b0..eisable SLNA cp
 *  0b1..enable SLNA cp
 */
#define BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_VAL_SHIFT)) & BTU2_REG_BTU_PTA_SLNA_CTRL_BTC_SLNA_CP_EN_BP_VAL_MASK)
/*! @} */

/*! @name BTU_PTA_TX_POWER_THRESHOLD - Tx Power Threshold to Suppress Tx Overlap Assertion */
/*! @{ */

#define BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_BDR_TX_PWR_THRSHLD_MASK (0xFFU)
#define BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_BDR_TX_PWR_THRSHLD_SHIFT (0U)
/*! bdr_tx_pwr_thrshld - Tx power threshold for BDR packet to suppress bt_overlap/bt_scan_overlap assertion */
#define BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_BDR_TX_PWR_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_BDR_TX_PWR_THRSHLD_SHIFT)) & BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_BDR_TX_PWR_THRSHLD_MASK)

#define BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_EDR_TX_PWR_THRSHLD_MASK (0xFF00U)
#define BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_EDR_TX_PWR_THRSHLD_SHIFT (8U)
/*! edr_tx_pwr_thrshld - Tx power threshold for EDR packet to suppress bt_overlap/bt_scan_overlap assertion */
#define BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_EDR_TX_PWR_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_EDR_TX_PWR_THRSHLD_SHIFT)) & BTU2_REG_BTU_PTA_TX_POWER_THRESHOLD_EDR_TX_PWR_THRSHLD_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_TX_OVERLAP_RANGE - MWS Frequency Overlap Range for Bluetooth Tx Slot */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_TX_MWS_OVERLAP_RANGE_MASK (0xFFU)
#define BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_TX_MWS_OVERLAP_RANGE_SHIFT (0U)
/*! tx_mws_overlap_range - MWS frequency overlap range for BR/EDR Tx Slots */
#define BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_TX_MWS_OVERLAP_RANGE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_TX_MWS_OVERLAP_RANGE_SHIFT)) & BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_TX_MWS_OVERLAP_RANGE_MASK)

#define BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_BLE_TX_MWS_OVERLAP_RANGE_MASK (0xFF00U)
#define BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_BLE_TX_MWS_OVERLAP_RANGE_SHIFT (8U)
/*! ble_tx_mws_overlap_range - MWS frequency overlap range for BLE Tx packets */
#define BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_BLE_TX_MWS_OVERLAP_RANGE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_BLE_TX_MWS_OVERLAP_RANGE_SHIFT)) & BTU2_REG_BTU_PTA_MWS_TX_OVERLAP_RANGE_BLE_TX_MWS_OVERLAP_RANGE_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_RX_OVERLAP_RANGE - MWS Frequency Overlap Range for Bluetooth Rx Slot */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_RX_MWS_OVERLAP_RANGE_MASK (0xFFU)
#define BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_RX_MWS_OVERLAP_RANGE_SHIFT (0U)
/*! rx_mws_overlap_range - MWS frequency overlap range for BR/EDR Rx Slots */
#define BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_RX_MWS_OVERLAP_RANGE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_RX_MWS_OVERLAP_RANGE_SHIFT)) & BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_RX_MWS_OVERLAP_RANGE_MASK)

#define BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_BLE_RX_MWS_OVERLAP_RANGE_MASK (0xFF00U)
#define BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_BLE_RX_MWS_OVERLAP_RANGE_SHIFT (8U)
/*! ble_rx_mws_overlap_range - MWS frequency overlap range for BLE Rx Packets */
#define BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_BLE_RX_MWS_OVERLAP_RANGE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_BLE_RX_MWS_OVERLAP_RANGE_SHIFT)) & BTU2_REG_BTU_PTA_MWS_RX_OVERLAP_RANGE_BLE_RX_MWS_OVERLAP_RANGE_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_TX_ON_START - MWS Coex Signal BT_TX_ON Start Timer */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_START_BTTXONSTARTREG_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_START_BTTXONSTARTREG_SHIFT (0U)
/*! btTxOnStartReg - BT_TX_ON Start Timer */
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_START_BTTXONSTARTREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_START_BTTXONSTARTREG_SHIFT)) & BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_START_BTTXONSTARTREG_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_TX_ON_END - MWS Coex Signal BT_TX_ON End Timer */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_END_BTTXONENDREG_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_END_BTTXONENDREG_SHIFT (0U)
/*! btTxOnEndReg - BT_TX_ON End Timer */
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_END_BTTXONENDREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_END_BTTXONENDREG_SHIFT)) & BTU2_REG_BTU_PTA_MWS_COEX_BT_TX_ON_END_BTTXONENDREG_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST - MWS Coex Signal BT_RX_PRI Start Timer for Master Mode */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_BTRXPRISTARTMSTREG_MASK (0xFFFU)
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_BTRXPRISTARTMSTREG_SHIFT (0U)
/*! btRxPriStartMstReg - BT_RX_PRI Start Timer for Master Mode */
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_BTRXPRISTARTMSTREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_BTRXPRISTARTMSTREG_SHIFT)) & BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_BTRXPRISTARTMSTREG_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_RX_PRI_END - MWS Coex Signal BT_RX_PRI End Timer */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_END_BTRXPRIENDREG_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_END_BTRXPRIENDREG_SHIFT (0U)
/*! btRxPriEndReg - BT_RX_PRI End Timer */
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_END_BTRXPRIENDREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_END_BTRXPRIENDREG_SHIFT)) & BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_END_BTRXPRIENDREG_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_FRAMESYNC_REFCLK_0 - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_MWSFRAMESYNC_REFCLK_MASK (0xFFFFU)
#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_MWSFRAMESYNC_REFCLK_SHIFT (0U)
/*! mwsFrameSync_refClk - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt */
#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_MWSFRAMESYNC_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_MWSFRAMESYNC_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_MWSFRAMESYNC_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_FRAMESYNC_REFCLK_1 - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_MWSFRAMESYNC_REFCLK_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_MWSFRAMESYNC_REFCLK_SHIFT (0U)
/*! mwsFrameSync_refClk - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt */
#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_MWSFRAMESYNC_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_MWSFRAMESYNC_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_MWSFRAMESYNC_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on MWS Frame Sync Pulse Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_MWSFRAMESYNC_PDBITCNT_MASK (0x1FFFU)
#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_MWSFRAMESYNC_PDBITCNT_SHIFT (0U)
/*! mwsFrameSync_pdBitCnt - Bluetooth Reference pdBitCounter Snapshot on MWS Frame Sync Pulse Interrupt */
#define BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_MWSFRAMESYNC_PDBITCNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_MWSFRAMESYNC_PDBITCNT_SHIFT)) & BTU2_REG_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_MWSFRAMESYNC_PDBITCNT_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_REFCLK_0 - Bluetooth Reference Clock Snapshot on MWS_Pattern_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_0_MWSPATTERN_REFCLK_MASK (0xFFFFU)
#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_0_MWSPATTERN_REFCLK_SHIFT (0U)
/*! mwsPattern_refClk - Bluetooth Reference Clock Snapshot on MWS_PATTERN Pulse Interrupt */
#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_0_MWSPATTERN_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_0_MWSPATTERN_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_0_MWSPATTERN_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_REFCLK_1 - Bluetooth Reference Clock Snapshot on MWS_Pattern_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_1_MWSPATTERN_REFCLK_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_1_MWSPATTERN_REFCLK_SHIFT (0U)
/*! mwsPattern_refClk - Bluetooth Reference Clock Snapshot on MWS_PATTERN Pulse Interrupt */
#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_1_MWSPATTERN_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_1_MWSPATTERN_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_MWS_PATTERN_REFCLK_1_MWSPATTERN_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on MWS_Pattern_Real_Int Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFPDB_CNT_MWSPATTERN_PDBITCNT_MASK (0x1FFFU)
#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFPDB_CNT_MWSPATTERN_PDBITCNT_SHIFT (0U)
/*! mwsPattern_pdBitCnt - Bluetooth Reference pdBitCounter Snapshot on MWS_PATTERN Pulse Interrupt */
#define BTU2_REG_BTU_PTA_MWS_PATTERN_REFPDB_CNT_MWSPATTERN_PDBITCNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_PATTERN_REFPDB_CNT_MWSPATTERN_PDBITCNT_SHIFT)) & BTU2_REG_BTU_PTA_MWS_PATTERN_REFPDB_CNT_MWSPATTERN_PDBITCNT_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_VAL - MWS Coex Signal MWS_PATTERN Value */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSPATTERNREG_MASK (0x3U)
#define BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSPATTERNREG_SHIFT (0U)
/*! mwsPatternReg - MWS Coex Signal MWS_PATTERN Value */
#define BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSPATTERNREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSPATTERNREG_SHIFT)) & BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSPATTERNREG_MASK)

#define BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSSCANFREQREG_MASK (0x1F00U)
#define BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSSCANFREQREG_SHIFT (8U)
/*! mwsScanFreqReg - MWS Coex Signal MWS_SCAN_FREQUENCY Value */
#define BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSSCANFREQREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSSCANFREQREG_SHIFT)) & BTU2_REG_BTU_PTA_MWS_PATTERN_VAL_MWSSCANFREQREG_MASK)
/*! @} */

/*! @name BTU_PTA_3DG_CLK_UPDATE_REFCLK_0 - Bluetooth Reference Clock Snapshot on BT_3DG_CLK_UPATE Pulse Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_BT3DGCLKUPDATE_REFCLK_MASK (0xFFFFU)
#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_BT3DGCLKUPDATE_REFCLK_SHIFT (0U)
/*! BT3dgClkUpdate_refClk - Bluetooth Reference Clock Snapshot on 3D-Glass Clock Update Pulse Interrupt */
#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_BT3DGCLKUPDATE_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_BT3DGCLKUPDATE_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_BT3DGCLKUPDATE_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_3DG_CLK_UPDATE_REFCLK_1 - Bluetooth Reference Clock Snapshot on BT_3DG_CLK_UPATE Pulse Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_BT3DGCLKUPDATE_REFCLK_MASK (0x3FFU)
#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_BT3DGCLKUPDATE_REFCLK_SHIFT (0U)
/*! BT3dgClkUpdate_refClk - Bluetooth Reference Clock Snapshot on 3D-Glass Clock Update Pulse Interrupt */
#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_BT3DGCLKUPDATE_REFCLK(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_BT3DGCLKUPDATE_REFCLK_SHIFT)) & BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_BT3DGCLKUPDATE_REFCLK_MASK)
/*! @} */

/*! @name BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on BT_3DG_CLK_UPDATE Pulse Interrupt */
/*! @{ */

#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_BT3DGCLKUPDATE_PDBITCNT_MASK (0x1FFFU)
#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_BT3DGCLKUPDATE_PDBITCNT_SHIFT (0U)
/*! BT3dgClkUpdate_pdBitCnt - Bluetooth Reference pdBitCounter Snapshot on 3D-Glass Clock Update Pulse Interrupt */
#define BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_BT3DGCLKUPDATE_PDBITCNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_BT3DGCLKUPDATE_PDBITCNT_SHIFT)) & BTU2_REG_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_BT3DGCLKUPDATE_PDBITCNT_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4 - MWS Scan Frequency Overlap Range 1~4 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_1_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_1_SHIFT (0U)
/*! mws_scan_ovlp_range_1 - MWS scan frequency overlap range 1 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_1_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_1_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_2_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_2_SHIFT (4U)
/*! mws_scan_ovlp_range_2 - MWS scan frequency overlap range 2 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_2(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_2_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_2_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_3_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_3_SHIFT (8U)
/*! mws_scan_ovlp_range_3 - MWS scan frequency overlap range 3 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_3(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_3_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_3_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_4_MASK (0xF000U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_4_SHIFT (12U)
/*! mws_scan_ovlp_range_4 - MWS scan frequency overlap range 4 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_4(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_4_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_MWS_SCAN_OVLP_RANGE_4_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8 - MWS Scan Frequency Overlap Range 5~8 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_5_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_5_SHIFT (0U)
/*! mws_scan_ovlp_range_5 - MWS scan frequency overlap range 5 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_5(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_5_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_5_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_6_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_6_SHIFT (4U)
/*! mws_scan_ovlp_range_6 - MWS scan frequency overlap range 6 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_6(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_6_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_6_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_7_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_7_SHIFT (8U)
/*! mws_scan_ovlp_range_7 - MWS scan frequency overlap range 7 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_7(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_7_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_7_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_8_MASK (0xF000U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_8_SHIFT (12U)
/*! mws_scan_ovlp_range_8 - MWS scan frequency overlap range 8 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_8(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_8_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_MWS_SCAN_OVLP_RANGE_8_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12 - MWS Scan Frequency Overlap Range 9~12 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_9_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_9_SHIFT (0U)
/*! mws_scan_ovlp_range_9 - MWS scan frequency overlap range 9 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_9(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_9_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_9_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_10_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_10_SHIFT (4U)
/*! mws_scan_ovlp_range_10 - MWS scan frequency overlap range 10 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_10(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_10_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_10_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_11_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_11_SHIFT (8U)
/*! mws_scan_ovlp_range_11 - MWS scan frequency overlap range 11 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_11(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_11_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_11_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_12_MASK (0xF000U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_12_SHIFT (12U)
/*! mws_scan_ovlp_range_12 - MWS scan frequency overlap range 12 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_12(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_12_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_MWS_SCAN_OVLP_RANGE_12_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16 - MWS Scan Frequency Overlap Range 13~16 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_13_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_13_SHIFT (0U)
/*! mws_scan_ovlp_range_13 - MWS scan frequency overlap range 13 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_13(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_13_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_13_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_14_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_14_SHIFT (4U)
/*! mws_scan_ovlp_range_14 - MWS scan frequency overlap range 14 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_14(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_14_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_14_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_15_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_15_SHIFT (8U)
/*! mws_scan_ovlp_range_15 - MWS scan frequency overlap range 15 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_15(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_15_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_15_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_16_MASK (0xF000U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_16_SHIFT (12U)
/*! mws_scan_ovlp_range_16 - MWS scan frequency overlap range 16 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_16(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_16_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_MWS_SCAN_OVLP_RANGE_16_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20 - MWS Scan Frequency Overlap Range 17~20 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_17_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_17_SHIFT (0U)
/*! mws_scan_ovlp_range_17 - MWS scan frequency overlap range 17 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_17(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_17_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_17_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_18_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_18_SHIFT (4U)
/*! mws_scan_ovlp_range_18 - MWS scan frequency overlap range 18 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_18(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_18_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_18_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_19_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_19_SHIFT (8U)
/*! mws_scan_ovlp_range_19 - MWS scan frequency overlap range 19 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_19(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_19_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_19_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_20_MASK (0xF000U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_20_SHIFT (12U)
/*! mws_scan_ovlp_range_20 - MWS scan frequency overlap range 20 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_20(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_20_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_MWS_SCAN_OVLP_RANGE_20_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24 - MWS Scan Frequency Overlap Range 21~24 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_21_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_21_SHIFT (0U)
/*! mws_scan_ovlp_range_21 - MWS scan frequency overlap range 21 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_21(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_21_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_21_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_22_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_22_SHIFT (4U)
/*! mws_scan_ovlp_range_22 - MWS scan frequency overlap range 22 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_22(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_22_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_22_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_23_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_23_SHIFT (8U)
/*! mws_scan_ovlp_range_23 - MWS scan frequency overlap range 23 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_23(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_23_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_23_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_24_MASK (0xF000U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_24_SHIFT (12U)
/*! mws_scan_ovlp_range_24 - MWS scan frequency overlap range 24 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_24(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_24_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_MWS_SCAN_OVLP_RANGE_24_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28 - MWS Scan Frequency Overlap Range 25~28 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_25_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_25_SHIFT (0U)
/*! mws_scan_ovlp_range_25 - MWS scan frequency overlap range 25 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_25(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_25_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_25_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_26_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_26_SHIFT (4U)
/*! mws_scan_ovlp_range_26 - MWS scan frequency overlap range 26 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_26(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_26_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_26_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_27_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_27_SHIFT (8U)
/*! mws_scan_ovlp_range_27 - MWS scan frequency overlap range 27 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_27(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_27_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_27_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_28_MASK (0xF000U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_28_SHIFT (12U)
/*! mws_scan_ovlp_range_28 - MWS scan frequency overlap range 28 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_28(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_28_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_MWS_SCAN_OVLP_RANGE_28_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31 - MWS Scan Frequency Overlap Range 29~31 */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_29_MASK (0xFU)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_29_SHIFT (0U)
/*! mws_scan_ovlp_range_29 - MWS scan frequency overlap range 29 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_29(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_29_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_29_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_30_MASK (0xF0U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_30_SHIFT (4U)
/*! mws_scan_ovlp_range_30 - MWS scan frequency overlap range 30 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_30(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_30_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_30_MASK)

#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_31_MASK (0xF00U)
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_31_SHIFT (8U)
/*! mws_scan_ovlp_range_31 - MWS scan frequency overlap range 31 */
#define BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_31(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_31_SHIFT)) & BTU2_REG_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_MWS_SCAN_OVLP_RANGE_31_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL - MWS Coex Early BT_RX_PRI Control */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MODE_MASK (0x3U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MODE_SHIFT (0U)
/*! bt_rx_pri_mode - BT_RX_PRI mode selection */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MODE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MODE_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MODE_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_MST_MASK (0x4U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_MST_SHIFT (2U)
/*! bt_rx_pri_page_resp_mst - BT_RX_PRI assertion during page response at master side */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_MST(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_MST_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_MST_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_MASK (0x8U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_SHIFT (3U)
/*! bt_rx_pri_inq_resp - BT_RX_PRI assertion during inquiry response */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_SLV_MASK (0x10U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_SLV_SHIFT (4U)
/*! bt_rx_pri_page_resp_slv - BT_RX_PRI assertion during page response at slave side */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_SLV(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_SLV_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_SLV_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MST_TM_SEL_MASK (0x20U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MST_TM_SEL_SHIFT (5U)
/*! bt_rx_pri_mst_tm_sel - BT_RX_PRI advance timing selection in Real Time mode for Bluetooth master mode
 *  0b0..select 100us range (BT_RX_PRI assertion is delayed by BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifRx rising edge of the Rx packet)
 *  0b1..select 600us range (BT_RX_PRI assertion is delayed by BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifTx
 *       rising edge of the preceding Tx packet)
 */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MST_TM_SEL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MST_TM_SEL_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_MST_TM_SEL_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_TM_SEL_MASK (0x40U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_TM_SEL_SHIFT (6U)
/*! bt_rx_pri_page_resp_tm_sel - BT_RX_PRI advance timing selection during master or slave page response
 *  0b0..select 100us range. For master, BT_RX_PRI assertion is delayed by BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST
 *       from rifRx rising edge of each Rx ID packet. For slave, BT_RX_PRI assertion is delayed by
 *       BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV from rifRx rising edge of the Rx FHS packet.
 *  0b1..select 600us range. For master, BT_RX_PRI assertion is delayed by BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST
 *       from rifTx rising edge of the first Tx ID packet. For slave, BT_RX_PRI assertion is delayed by
 *       BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV from correlation hit of the first or second Rx ID packet.
 */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_TM_SEL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_TM_SEL_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_PAGE_RESP_TM_SEL_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_TM_SEL_MASK (0x80U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_TM_SEL_SHIFT (7U)
/*! bt_rx_pri_inq_resp_tm_sel - BT_RX_PRI advance timing selection during inquiry response
 *  0b0..select 100us range. BT_RX_PRI assertion is delayed by BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifRx rising edge of the FHS packet.
 *  0b1..select 600us range. BT_RX_PRI assertion is delayed by BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifTx rising edge of the first Tx ID packet.
 */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_TM_SEL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_TM_SEL_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_INQ_RESP_TM_SEL_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_EARLY_BT_RX_PRI_DEASS_FRAM_CNT_MASK (0x700U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_EARLY_BT_RX_PRI_DEASS_FRAM_CNT_SHIFT (8U)
/*! early_bt_rx_pri_deass_fram_cnt - Number of frames BT_RX_PRI should be de-asserted */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_EARLY_BT_RX_PRI_DEASS_FRAM_CNT(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_EARLY_BT_RX_PRI_DEASS_FRAM_CNT_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_EARLY_BT_RX_PRI_DEASS_FRAM_CNT_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_DRIVE_MASK (0x800U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_DRIVE_SHIFT (11U)
/*! bt_rx_pri_drive - Control BT_RX_PRI logic level directly */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_DRIVE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_DRIVE_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_DRIVE_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_ASSRT_LVL_MASK (0x3000U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_ASSRT_LVL_SHIFT (12U)
/*! bt_rx_pri_assrt_lvl - Specify priority level to assert BT_RX_PRI for BR/EDR packet */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_ASSRT_LVL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_ASSRT_LVL_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BT_RX_PRI_ASSRT_LVL_MASK)

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BLE_RX_PRI_ASSRT_LVL_MASK (0xC000U)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BLE_RX_PRI_ASSRT_LVL_SHIFT (14U)
/*! ble_rx_pri_assrt_lvl - Specify priority level to assert BT_RX_PRI for BLE packet */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BLE_RX_PRI_ASSRT_LVL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BLE_RX_PRI_ASSRT_LVL_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_BLE_RX_PRI_ASSRT_LVL_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST - MWS Coex Early BT_RX_PRI Start Offset for Master Mode */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_STARTOFFSETMST_MASK (0x1FFFU)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_STARTOFFSETMST_SHIFT (0U)
/*! StartOffsetMst - Start Offset in Master Mode */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_STARTOFFSETMST(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_STARTOFFSETMST_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_STARTOFFSETMST_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV - MWS Coex Early BT_RX_PRI Start Offset for Slave Mode */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_STARTOFFSETSLV_MASK (0x1FFFU)
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_STARTOFFSETSLV_SHIFT (0U)
/*! StartOffsetSlv - Start Offset in Slave Mode */
#define BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_STARTOFFSETSLV(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_STARTOFFSETSLV_SHIFT)) & BTU2_REG_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_STARTOFFSETSLV_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV - MWS Coex Signal BT_RX_PRI Start Timer for Slave Mode */
/*! @{ */

#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_BTRXPRISTARTSLVREG_MASK (0xFFFU)
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_BTRXPRISTARTSLVREG_SHIFT (0U)
/*! btRxPriStartSlvReg - BT_RX_PRI Start Timer for Slave Mode */
#define BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_BTRXPRISTARTSLVREG(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_BTRXPRISTARTSLVREG_SHIFT)) & BTU2_REG_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_BTRXPRISTARTSLVREG_MASK)
/*! @} */

/*! @name BTU_PTA_ANT_SWITCH_CTRL - PTA Antenna Switch Control */
/*! @{ */

#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_EN_MASK (0x1U)
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_EN_SHIFT (0U)
/*! bca_ant_switch_sts_bypass_en - BCA antenna switch status bypass enable
 *  0b0..disable antSwitchStatus bypass
 *  0b1..enable antSwitchStatus bypass
 */
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_EN(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_EN_SHIFT)) & BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_EN_MASK)

#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_VAL_MASK (0x2U)
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_VAL_SHIFT (1U)
/*! bca_ant_switch_sts_bypass_val - BCA antenna switch status bypass value
 *  0b0..set BCA antSwitchStatus to zero
 *  0b1..set BCA antSwitchStatus to one
 */
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_VAL(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_VAL_SHIFT)) & BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_ANT_SWITCH_STS_BYPASS_VAL_MASK)

#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_MASK (0x1F00U)
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_SHIFT (8U)
/*! bca_ref_antenna - BCA reference antenna override value */
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_SHIFT)) & BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_MASK)

#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_OVERRIDE_MASK (0x8000U)
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_OVERRIDE_SHIFT (15U)
/*! bca_ref_antenna_override - BCA reference antenna override
 *  0b0..disable BCA refAntenna override
 *  0b1..enable BCA refAntenna override
 */
#define BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_OVERRIDE(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_OVERRIDE_SHIFT)) & BTU2_REG_BTU_PTA_ANT_SWITCH_CTRL_BCA_REF_ANTENNA_OVERRIDE_MASK)
/*! @} */

/*! @name BTU_PTA_SEL_BCA_PRI_HIGH - PTA High Priority Select for BCA Arbitration */
/*! @{ */

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSSWITCHPRI_MASK (0x1U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSSWITCHPRI_SHIFT (0U)
/*! msSwitchPri - Master / Slave Switch */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSSWITCHPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSSWITCHPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSSWITCHPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PAGEPRI_MASK (0x2U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PAGEPRI_SHIFT (1U)
/*! pagePri - Page */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PAGEPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PAGEPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PAGEPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PSCANPRI_MASK (0x4U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PSCANPRI_SHIFT (2U)
/*! pScanPri - Page Scan */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PSCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PSCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_PSCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_INQPRI_MASK (0x8U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_INQPRI_SHIFT (3U)
/*! inqPri - Inquiry */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_INQPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_INQPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_INQPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ISCANPRI_MASK (0x10U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ISCANPRI_SHIFT (4U)
/*! iScanPri - Inquiry Scan */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ISCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ISCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ISCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITTXPRI_MASK (0x20U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITTXPRI_SHIFT (5U)
/*! llrInitTxPri - LLR Initiator Tx priority */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITTXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITTXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITTXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITRXPRI_MASK (0x40U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITRXPRI_SHIFT (6U)
/*! llrInitRxPri - LLR Initiator Rx priority */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITRXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITRXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_LLRINITRXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCOINSTPRI_MASK (0x80U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCOINSTPRI_SHIFT (7U)
/*! eScoInstPri - eSCO Instant */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCOINSTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCOINSTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCOINSTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCORETRPRI_MASK (0x100U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCORETRPRI_SHIFT (8U)
/*! eScoRetrPri - eSCO Retransmission */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCORETRPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCORETRPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ESCORETRPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SCOPRI_MASK (0x200U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SCOPRI_SHIFT (9U)
/*! scoPri - SCO */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SCOPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SCOPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SCOPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_BROADCASTPRI_MASK (0x400U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_BROADCASTPRI_SHIFT (10U)
/*! broadcastPri - Broadcast */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_BROADCASTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_BROADCASTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_BROADCASTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ACLPRI_MASK (0x800U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ACLPRI_SHIFT (11U)
/*! aclPri - ACL */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ACLPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ACLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_ACLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_IRESPPRI_MASK (0x1000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_IRESPPRI_SHIFT (12U)
/*! iRespPri - Inquiry Response */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_IRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_IRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_IRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SLVRESPPRI_MASK (0x2000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SLVRESPPRI_SHIFT (13U)
/*! slvRespPri - Slave Page Response */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SLVRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SLVRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_SLVRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_POLLPRI_MASK (0x4000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_POLLPRI_SHIFT (14U)
/*! pollPri - Poll packet */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_POLLPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_POLLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_POLLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSTRRESPPRI_MASK (0x8000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSTRRESPPRI_SHIFT (15U)
/*! mstrRespPri - Master Page Response */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSTRRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSTRRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_HIGH_MSTRRESPPRI_MASK)
/*! @} */

/*! @name BTU_PTA_SEL_BCA_PRI_MED - PTA Medium Priority Select for BCA Arbitration */
/*! @{ */

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSSWITCHPRI_MASK (0x1U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSSWITCHPRI_SHIFT (0U)
/*! msSwitchPri - Master / Slave Switch */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSSWITCHPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSSWITCHPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSSWITCHPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PAGEPRI_MASK (0x2U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PAGEPRI_SHIFT (1U)
/*! pagePri - Page */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PAGEPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PAGEPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PAGEPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PSCANPRI_MASK (0x4U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PSCANPRI_SHIFT (2U)
/*! pScanPri - Page Scan */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PSCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PSCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_PSCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_INQPRI_MASK (0x8U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_INQPRI_SHIFT (3U)
/*! inqPri - Inquiry */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_INQPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_INQPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_INQPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ISCANPRI_MASK (0x10U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ISCANPRI_SHIFT (4U)
/*! iScanPri - Inquiry Scan */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ISCANPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ISCANPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ISCANPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITTXPRI_MASK (0x20U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITTXPRI_SHIFT (5U)
/*! llrInitTxPri - LLR Initiator Tx priority */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITTXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITTXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITTXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITRXPRI_MASK (0x40U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITRXPRI_SHIFT (6U)
/*! llrInitRxPri - LLR Initiator Rx priority */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITRXPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITRXPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_LLRINITRXPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCOINSTPRI_MASK (0x80U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCOINSTPRI_SHIFT (7U)
/*! eScoInstPri - eSCO Instant */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCOINSTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCOINSTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCOINSTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCORETRPRI_MASK (0x100U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCORETRPRI_SHIFT (8U)
/*! eScoRetrPri - eSCO Retransmission */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCORETRPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCORETRPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ESCORETRPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SCOPRI_MASK (0x200U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SCOPRI_SHIFT (9U)
/*! scoPri - SCO */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SCOPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SCOPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SCOPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_BROADCASTPRI_MASK (0x400U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_BROADCASTPRI_SHIFT (10U)
/*! broadcastPri - Broadcast */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_BROADCASTPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_BROADCASTPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_BROADCASTPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ACLPRI_MASK (0x800U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ACLPRI_SHIFT (11U)
/*! aclPri - ACL */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ACLPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ACLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_ACLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_IRESPPRI_MASK (0x1000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_IRESPPRI_SHIFT (12U)
/*! iRespPri - Inquiry Response */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_IRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_IRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_IRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SLVRESPPRI_MASK (0x2000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SLVRESPPRI_SHIFT (13U)
/*! slvRespPri - Slave Page Response */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SLVRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SLVRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_SLVRESPPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_POLLPRI_MASK (0x4000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_POLLPRI_SHIFT (14U)
/*! pollPri - Poll packet */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_POLLPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_POLLPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_POLLPRI_MASK)

#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSTRRESPPRI_MASK (0x8000U)
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSTRRESPPRI_SHIFT (15U)
/*! mstrRespPri - Master Page Response */
#define BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSTRRESPPRI(x) (((uint16_t)(((uint16_t)(x)) << BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSTRRESPPRI_SHIFT)) & BTU2_REG_BTU_PTA_SEL_BCA_PRI_MED_MSTRRESPPRI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BTU2_REG_Register_Masks */


/*!
 * @}
 */ /* end of group BTU2_REG_Peripheral_Access_Layer */


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


#endif  /* PERI_BTU2_REG_H_ */

