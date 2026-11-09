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
**         CMSIS Peripheral Access Layer for BTU2
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
 * @file PERI_BTU2.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for BTU2
 *
 * CMSIS Peripheral Access Layer for BTU2
 */

#if !defined(PERI_BTU2_H_)
#define PERI_BTU2_H_                             /**< Symbol preventing repeated inclusion */

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
   -- BTU2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTU2_Peripheral_Access_Layer BTU2 Peripheral Access Layer
 * @{
 */

/** BTU2 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[3072];
  __IO uint16_t BTU_RIF_CTL0;                      /**< RIF Control 0, offset: 0xC00 */
       uint8_t RESERVED_1[4];
  __IO uint16_t BTU_RIF_BRF_RSSI_ADDR;             /**< RIF BRF RSSI Address, offset: 0xC06 */
       uint8_t RESERVED_2[4];
  __IO uint16_t BTU_RIF_CTRL1;                     /**< RIF Control 1, offset: 0xC0C */
  __IO uint16_t BTU_RIF_RXON;                      /**< RIF RXON, offset: 0xC0E */
  __IO uint16_t BTU_RIF_PLLCLKEN_ON_DELAY;         /**< RIF PLL Clock Enable, offset: 0xC10 */
  __IO uint16_t BTU_RIF_TXON;                      /**< RIF Tx On, offset: 0xC12 */
  __IO uint16_t BTU_RIF_PLLCLKEN_OFF_DELAY;        /**< RIF PLL Clock Enable Off Delay, offset: 0xC14 */
  __I  uint16_t BTU_RIF_FREQ;                      /**< RIF FREQ, offset: 0xC16 */
  __IO uint16_t BTU_RIF_BRF_TX_PU;                 /**< RIF BRF Power Up for TX, brf_pu is the sideband signal used to turn on the BRF's power control., offset: 0xC18 */
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
       uint8_t RESERVED_3[4];
  __IO uint16_t BTU_RIF_SWDBUS_CTL;                /**< RIF Software dBus Control, offset: 0xC40 */
  __IO uint16_t BTU_RIF_SWDBUS_EVENT;              /**< RIF Software dBus Event, - Max burst read or write: 8 bytes., offset: 0xC42 */
  __IO uint16_t BTU_RIF_SWDBUS_DATA_1_0;           /**< RIF Software dBus Data_1_0, offset: 0xC44 */
  __IO uint16_t BTU_RIF_SWDBUS_DATA_3_2;           /**< RIF Software dBus Data_3_2, offset: 0xC46 */
  __IO uint16_t BTU_RIF_SWDBUS_DATA_5_4;           /**< RIF Software dBus Data_5_4, offset: 0xC48 */
  __IO uint16_t BTU_RIF_SWDBUS_DATA_7_6;           /**< RIF Software dBus Data_7_6, offset: 0xC4A */
  __IO uint16_t BTU_RIF_TX_FESW;                   /**< RIF Tx FESW, offset: 0xC4C */
  __IO uint16_t BTU_RIF_RX_FESW;                   /**< RIF Rx FESW, offset: 0xC4E */
  __IO uint16_t BTU_RIF_RXPAON;                    /**< RIF Rx PA On, offset: 0xC50 */
  __IO uint16_t BTU_RIF_BRF_RX_PU;                 /**< RIF BRF Power Up for RX, brf_pu is the sideband signal used to turn on the BRF's power control., offset: 0xC52 */
  __IO uint16_t BTU_RIF_BTC_DBUS_TX_PKT_END;       /**< BTC RIF dBus Tx Packet End Control, offset: 0xC54 */
  __IO uint16_t BTU_RIF_BTC_DBUS_RX_PKT_END;       /**< BTC RIF dBus Rx Packet End Control, offset: 0xC56 */
  __IO uint16_t BTU_RIF_BTC_DBUS_TX_RAMPDOWN;      /**< BTC RIF dBus Tx Rampdown Control, offset: 0xC58 */
       uint8_t RESERVED_4[40];
  __IO uint16_t BTU_RIF_DBUS_COR_CONFIG_CTRL;      /**< RIF Correlator Configuration Control, offset: 0xC82 */
  __IO uint16_t BTU_RIF_BRF_COR_CONFIG_ADDR;       /**< RIF BRF Correlator Configuration Address, Only use in MRVL Gen3 Radio Mode., offset: 0xC84 */
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
       uint8_t RESERVED_5[4];
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
  __IO uint16_t BTU_RIF_DBUS_RX_PKT_STATUS;        /**< RIF dBus Rx Packet Status, offset: 0xCBA */
  __IO uint16_t BTU_RIF_DBUS_RX_MODETYPE;          /**< RIF dBus Rx Mode Type, offset: 0xCBC */
  __IO uint16_t BTU_RIF_BRF_RX_CTE_LEN_ADDR;       /**< RIF Register, offset: 0xCBE */
       uint8_t RESERVED_6[2];
  __IO uint16_t BTU_RIF_ARB_BLE_START_TIME_CODED;  /**< RIF ARB BLE Start Time, Delay till sampled bt_grant_n is sampled., offset: 0xCC2 */
  __IO uint16_t BTU_RIF_ARB_BLE_START_TIME_1M;     /**< RIF ARB BLE Start Time, Delay till sampled bt_grant_n is sampled., offset: 0xCC4 */
  __IO uint16_t BTU_RIF_ARB_BLE_START_TIME_2M;     /**< RIF ARB BLE Start Time, Delay till sampled bt_grant_n is sampled., offset: 0xCC6 */
  __IO uint16_t BTU_RIF_ARB_CTL;                   /**< RIF ARB Control, offset: 0xCC8 */
       uint8_t RESERVED_7[2];
  __IO uint16_t BTU_RIF_CCA_GRANT_OFFSET_TIME;     /**< BTU CCA GRANT OFFSET TIME, BTU CCA Grant Offset Time, offset: 0xCCC */
  __IO uint16_t BTU_RIF_CCA_TX_FESW_OFFSET_TIME;   /**< BTU CCA TX FESW OFFSET TIME, BTU CCA TX FESW Offset Time, offset: 0xCCE */
  __IO uint16_t BTU_RIF_TESTBUS_SEL_0;             /**< RIF Testbus Select 0, offset: 0xCD0 */
  __IO uint16_t BTU_RIF_TESTBUS_SEL_1;             /**< RIF Testbus Select 1, offset: 0xCD2 */
  __IO uint16_t BTU_RIF_TESTBUS_OE;                /**< BTU Testbus Output Enable, offset: 0xCD4 */
  __IO uint16_t BTU_RIF_REG_DEBUG_SW_OUTDATA;      /**< BLE Debug Output Data, offset: 0xCD6 */
  __I  uint16_t BTU_RIF_REG_DEBUG_INDATA;          /**< BLE Debug Input Data, offset: 0xCD8 */
  __IO uint16_t BTU_RIF_REG_DEBUG_SW_MSG;          /**< BLE Debug Software Message, offset: 0xCDA */
  __I  uint16_t BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT; /**< BLE Debug Software Message FIFO Count, offset: 0xCDC */
  __IO uint16_t BTU_RIF_TESTBUS_CONTROL;           /**< RIF Testbus Control, offset: 0xCDE */
       uint8_t RESERVED_8[16];
  __IO uint16_t BTU_RIF_BT_CLK_GATING;             /**< RIF Bluetooth Clock Gating, offset: 0xCF0 */
       uint8_t RESERVED_9[2];
  __IO uint16_t BTU_RIF_CLK_SMPLD;                 /**< RIF Clock Sampled, Mux select for Sampled generation logic., offset: 0xCF4 */
       uint8_t RESERVED_10[2];
  __IO uint16_t BTU_RIF_BLE_CLK_GATING;            /**< RIF BLE Clock Gating, Clock Enable register for BLE Clocks., offset: 0xCF8 */
       uint8_t RESERVED_11[2];
  __IO uint16_t BTU_RIF_BLE_CLK_CTRL;              /**< RIF BLE Clock Control, Register for Clock Control Logic, offset: 0xCFC */
       uint8_t RESERVED_12[2];
  __IO uint16_t BTU_RIF_BLE_DBUS_TX_PKT_END;       /**< BLE RIF dBus Tx Packet End Control, offset: 0xD00 */
  __IO uint16_t BTU_RIF_BLE_DBUS_RX_PKT_END;       /**< BLE RIF dBus Rx Packet End Control, offset: 0xD02 */
  __IO uint16_t BTU_RIF_BLE_DBUS_TX_RAMPDOWN;      /**< BLE RIF dBus Tx Rampdown Control, offset: 0xD04 */
  __IO uint16_t BTU_RIF_BLE_DBUS_RSSI;             /**< BLE RIF dBus RSSI, offset: 0xD06 */
       uint8_t RESERVED_13[40];
  __IO uint16_t BTU_RIF_ADAPTIVITY_CTRL;           /**< BT Adaptivity Control, Register for BT Adaptivity Control, offset: 0xD30 */
       uint8_t RESERVED_14[8];
  __I  uint16_t BTU_RIF_BLE_CCA_ED_READBACK;       /**< BLE ED Mag readback value, BLE ED Mag readback value, offset: 0xD3A */
  __IO uint16_t BTU_RIF_DBUS_CCA_TX_PWRCTL;        /**< CCA TX PWRCTL Dbus, CCA TX PWRCTL Dbus, offset: 0xD3C */
  __IO uint16_t BTU_RIF_DBUS_CCA_TX_FSYN;          /**< CCA TX FSYN Dbus, CCA TX FSYN Dbus, offset: 0xD3E */
  __IO uint16_t BTU_RIF_DBUS_CCA_ED;               /**< CCA TX R2 Dbus, CCA TX R2 Dbus, offset: 0xD40 */
  __IO uint16_t BTU_RIF_BRF_CCA_ED_ADDR;           /**< BRF CCA ED Address, BRF CCA ED Address, offset: 0xD42 */
  __IO uint16_t BTU_RIF_BTC_CCA_CA1_2_DELAY;       /**< BTC CCA CA1 CA2 Delays, BTC CCA CA1 CA2 Delays, offset: 0xD44 */
       uint8_t RESERVED_15[2];
  __IO uint16_t BTU_RIF_BLE_CCA_EBRAM_ADDR;        /**< BLE CCA EBRAM Address Offset, BLE CCA EBRAM Address Offset, offset: 0xD48 */
  __IO uint16_t BTU_RIF_BLE_CCA_THRESHOLD;         /**< BLE CCA Counter thresholds, BLE CCA Counter thresholds, offset: 0xD4A */
       uint8_t RESERVED_16[4];
  __I  uint16_t BTU_RIF_CCA_BLE_THRESHOLD_MET_STS; /**< BLE CCA threshold met status, BLE CCA threshold met status, offset: 0xD50 */
       uint8_t RESERVED_17[4];
  __IO uint16_t BTU_RIF_CCA_BLE_RX_FESW_DELAY;     /**< BLE CCA RX FESW DELAYS, BLE CCA RX FESW DELAYS, offset: 0xD56 */
       uint8_t RESERVED_18[426];
  __IO uint16_t BTU_PTA_CTRL;                      /**< PTA Control, offset: 0xF02 */
  __IO uint16_t BTU_PTA_REQ_DELAY_TIMER;           /**< PTA Bt_Req Delay Timer, offset: 0xF04 */
       uint8_t RESERVED_19[14];
  __IO uint16_t BTU_PTA_BLE_RIF_ARB_COEX_PRI;      /**< BLE PTA Priority for BTC/BLE arbitration, BLE coex priority for BTC/BLE arbitration., offset: 0xF14 */
  __IO uint16_t BTU_PTA_BLE_BCA_COEX_PRI;          /**< BLE PTA Priority for BCA arbitration, BLE coex priority for BCA arbitration., offset: 0xF16 */
  __I  uint16_t BTU_PTA_MWS_INACTIVITY_REFCLK_0;   /**< Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt, offset: 0xF18 */
  __I  uint16_t BTU_PTA_MWS_INACTIVITY_REFCLK_1;   /**< Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt, offset: 0xF1A */
  __I  uint16_t BTU_PTA_MWS_INACTIVITY_REFPDB_CNT; /**< Bluetooth Reference pdBitCounter Snapshot on MWS_Inact_Msg_Real_Int Interrupt, offset: 0xF1C */
  __IO uint16_t BTU_PTA_INBAND_FREQ_SET_1;         /**< PTA Inband Frequency Set 0, BT_FREQ is set when (BT_In_Band_Hi >= freqNr >= BT_In_Band_Lo) in MRVL Coexistence mode and BT_In_Band1_Freq_En is enabled. 2 sets of band gaps; final BT_FREQ is OR version of 2 sets., offset: 0xF1E */
  __IO uint16_t BTU_PTA_MODE_SELECT;               /**< PTA Mode Select, offset: 0xF20 */
  __IO uint16_t BTU_PTA_INBAND_FREQ_SET_0;         /**< PTA Inband Frequency Set 1, BT_FREQ is set when (BT_In_Band_Hi >= freqNr >= BT_In_Band_Lo) in MRVL Coexistence mode. 2 sets of band gaps; final BT_FREQ is OR version of 2 sets., offset: 0xF22 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0; /**< Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt, offset: 0xF24 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1; /**< Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt, offset: 0xF26 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT; /**< Bluetooth Reference pdBitCounter Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt, offset: 0xF28 */
  __I  uint16_t BTU_PTA_HARQ_PATTERN_SEL_VAL;      /**< MWS Coex Signal HARQ_PATTERN_SEL Value, offset: 0xF2A */
  __IO uint16_t BTU_PTA_INFO_DELAY_TIMER;          /**< PTA Info Delay Timer, offset: 0xF2C */
       uint8_t RESERVED_20[4];
  __IO uint16_t BTU_PTA_BLE_SYNC_CTRL;             /**< PTA BLE Sync Control, offset: 0xF32 */
  __I  uint16_t BTU_PTA_PRI_INC_EBRAM_ADDR;        /**< EBRAM Base Address: PTA Priority Escalation, offset: 0xF34 */
  __IO uint16_t BTU_PTA_SYNC_CTRL;                 /**< PTA Voice/WLAN Sync Control, offset: 0xF36 */
  __IO uint16_t BTU_PTA_BLE_TX_PWR_THRHD;          /**< BLE Tx Power Threshold to Suppress Tx Overlap Assertion, offset: 0xF38 */
       uint8_t RESERVED_21[8];
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
       uint8_t RESERVED_22[16];
  __IO uint16_t BTU_PTA_ANT_SWITCH_CTRL;           /**< PTA Antenna Switch Control, Antenna switch control for BCA arbitration., offset: 0xF90 */
       uint8_t RESERVED_23[18];
  __IO uint16_t BTU_PTA_RSSI_ARB_CTRL;             /**< BTU RSSI Arbitration Control, RSSI Based arbitration register controls like feature enable; RSSI value from EBRAM or register selection; average RSSI orRSSI for last received packet, offset: 0xFA4 */
} BTU2_Type;

/* ----------------------------------------------------------------------------
   -- BTU2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTU2_Register_Masks BTU2 Register Masks
 * @{
 */

/*! @name BTU_RIF_CTL0 - RIF Control 0 */
/*! @{ */

#define BTU2_BTU_RIF_CTL0_brf_rd_data_turnaround_MASK (0x1U)
#define BTU2_BTU_RIF_CTL0_brf_rd_data_turnaround_SHIFT (0U)
/*! brf_rd_data_turnaround - BRF Read Data Turnaround, 0x0: BRF read data will be ready on the next
 *    clock cycle after address given, 0x1: BRF needs one more clock cycle between address and read
 *    data
 */
#define BTU2_BTU_RIF_CTL0_brf_rd_data_turnaround(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTL0_brf_rd_data_turnaround_SHIFT)) & BTU2_BTU_RIF_CTL0_brf_rd_data_turnaround_MASK)

#define BTU2_BTU_RIF_CTL0_brf_agc_counter_readback_enable_MASK (0x2U)
#define BTU2_BTU_RIF_CTL0_brf_agc_counter_readback_enable_SHIFT (1U)
/*! brf_agc_counter_readback_enable - Enable BRF readback LNA; CBPF and ADC overflow counters after
 *    AGC freeze, 0x0: BRF only readback RSSI and noise floor values at RSSI, 0x1: BRF readback
 *    extra 3 bytes (LNA; CBPF and ADC overflow counters) after RSSI read
 */
#define BTU2_BTU_RIF_CTL0_brf_agc_counter_readback_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTL0_brf_agc_counter_readback_enable_SHIFT)) & BTU2_BTU_RIF_CTL0_brf_agc_counter_readback_enable_MASK)

#define BTU2_BTU_RIF_CTL0_radio_type_MASK        (0x700U)
#define BTU2_BTU_RIF_CTL0_radio_type_SHIFT       (8U)
/*! radio_type - Radio Type, 0x0: Unknown, 0x1: Marvell Gen3 radio; dBus mode, 0x2: Marvell Gen4 radio; dBus mode */
#define BTU2_BTU_RIF_CTL0_radio_type(x)          (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTL0_radio_type_SHIFT)) & BTU2_BTU_RIF_CTL0_radio_type_MASK)

#define BTU2_BTU_RIF_CTL0_radio_mode_MASK        (0x1800U)
#define BTU2_BTU_RIF_CTL0_radio_mode_SHIFT       (11U)
/*! radio_mode - Radio Mode Selection, 0x0: Marvell Radio Mode, 0x1: KW Radio; Sideband RIF interface, 0x2: Unused, 0x3: Unused */
#define BTU2_BTU_RIF_CTL0_radio_mode(x)          (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTL0_radio_mode_SHIFT)) & BTU2_BTU_RIF_CTL0_radio_mode_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RSSI_ADDR - RIF BRF RSSI Address */
/*! @{ */

#define BTU2_BTU_RIF_BRF_RSSI_ADDR_rssi_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_RSSI_ADDR_rssi_addr_SHIFT (0U)
/*! rssi_addr - RSSI Address, Address of the RSSI register in the radio. */
#define BTU2_BTU_RIF_BRF_RSSI_ADDR_rssi_addr(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RSSI_ADDR_rssi_addr_SHIFT)) & BTU2_BTU_RIF_BRF_RSSI_ADDR_rssi_addr_MASK)
/*! @} */

/*! @name BTU_RIF_CTRL1 - RIF Control 1 */
/*! @{ */

#define BTU2_BTU_RIF_CTRL1_bt_reg_rif_bt_4m_clk_ena_MASK (0x20U)
#define BTU2_BTU_RIF_CTRL1_bt_reg_rif_bt_4m_clk_ena_SHIFT (5U)
/*! bt_reg_rif_bt_4m_clk_ena - RIF Clock Gate Enable Override, RIF Clock Gate Enable Override; if
 *    set to 1; clock gating for RIF clock is disabled = ungated clocks.
 */
#define BTU2_BTU_RIF_CTRL1_bt_reg_rif_bt_4m_clk_ena(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTRL1_bt_reg_rif_bt_4m_clk_ena_SHIFT)) & BTU2_BTU_RIF_CTRL1_bt_reg_rif_bt_4m_clk_ena_MASK)

#define BTU2_BTU_RIF_CTRL1_bd_spi_data_bidir_MASK (0x40U)
#define BTU2_BTU_RIF_CTRL1_bd_spi_data_bidir_SHIFT (6U)
/*! bd_spi_data_bidir - Uni- or Bi-directional dBus Data Line Selection, 0x0: uni-directional, 0x1: bi-directional */
#define BTU2_BTU_RIF_CTRL1_bd_spi_data_bidir(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTRL1_bd_spi_data_bidir_SHIFT)) & BTU2_BTU_RIF_CTRL1_bd_spi_data_bidir_MASK)

#define BTU2_BTU_RIF_CTRL1_bd_rxtx_data_bidir_MASK (0x80U)
#define BTU2_BTU_RIF_CTRL1_bd_rxtx_data_bidir_SHIFT (7U)
/*! bd_rxtx_data_bidir - Uni- or Bi-directional RxData and TxData Line Selection, 0x0: uni-directional, 0x1: bi-directional */
#define BTU2_BTU_RIF_CTRL1_bd_rxtx_data_bidir(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTRL1_bd_rxtx_data_bidir_SHIFT)) & BTU2_BTU_RIF_CTRL1_bd_rxtx_data_bidir_MASK)

#define BTU2_BTU_RIF_CTRL1_rssi_value_MASK       (0xFF00U)
#define BTU2_BTU_RIF_CTRL1_rssi_value_SHIFT      (8U)
/*! rssi_value - RSSI Value, The latest received RSSI value from the radio. This can be used to get
 *    RSSI values before a link is setup; for example; for FCS. To get RSSI value for an existing
 *    link use the DIAG area in EBRAM.
 */
#define BTU2_BTU_RIF_CTRL1_rssi_value(x)         (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTRL1_rssi_value_SHIFT)) & BTU2_BTU_RIF_CTRL1_rssi_value_MASK)
/*! @} */

/*! @name BTU_RIF_RXON - RIF RXON */
/*! @{ */

#define BTU2_BTU_RIF_RXON_rxon_fixed_MASK        (0x80U)
#define BTU2_BTU_RIF_RXON_rxon_fixed_SHIFT       (7U)
/*! rxon_fixed - RxOn fixed or use programmable timing, 0x0: use start and stop timing parameters, 0x1: rxOn = RxOn_Start[6] */
#define BTU2_BTU_RIF_RXON_rxon_fixed(x)          (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RXON_rxon_fixed_SHIFT)) & BTU2_BTU_RIF_RXON_rxon_fixed_MASK)

#define BTU2_BTU_RIF_RXON_rxon_stop_MASK         (0xFF00U)
#define BTU2_BTU_RIF_RXON_rxon_stop_SHIFT        (8U)
/*! rxon_stop - Delay from Rx finished (rifRx low) to rxOn falling edge, - Resolution: 0.25 us. */
#define BTU2_BTU_RIF_RXON_rxon_stop(x)           (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RXON_rxon_stop_SHIFT)) & BTU2_BTU_RIF_RXON_rxon_stop_MASK)
/*! @} */

/*! @name BTU_RIF_PLLCLKEN_ON_DELAY - RIF PLL Clock Enable */
/*! @{ */

#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_on_delay_qus_MASK (0xFFU)
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_on_delay_qus_SHIFT (0U)
/*! brf_pll_clk_en_on_delay_qus - Delay from wakeUp to turning of BRF's PLL clock, - Resolution: 0.25 us. */
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_on_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_on_delay_qus_SHIFT)) & BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_on_delay_qus_MASK)

#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_early_en_MASK (0x2000U)
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_early_en_SHIFT (13U)
/*! brf_pll_clk_early_en - Activate brf_pll_clk_en earlier along with brf_pu, 0x0: Activate
 *    brf_pll_clk_en at normal delay, 0x1: Activate brf_pll_clk_en earlier along with brf_pu
 */
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_early_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_early_en_SHIFT)) & BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_early_en_MASK)

#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_nb_MASK (0x4000U)
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_nb_SHIFT (14U)
/*! brf_pll_clk_en_nb - Activate brf_pll_clk_en during NB/MB scan packets Enable, 0x0: keep off
 *    during NB/MB scan packets, 0x1: activate brf_pll_clk_en during NB/MB scan packets
 */
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_nb(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_nb_SHIFT)) & BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_nb_MASK)

#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_fixed_MASK (0x8000U)
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_fixed_SHIFT (15U)
/*! brf_pll_clk_en_fixed - Use fixed value for brf_pll_clk_en, 0x0: on/off_delay registers control
 *    the timing, 0x1: brf_pll_clk_en is the fixed value of bit[0]
 */
#define BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_fixed(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_fixed_SHIFT)) & BTU2_BTU_RIF_PLLCLKEN_ON_DELAY_brf_pll_clk_en_fixed_MASK)
/*! @} */

/*! @name BTU_RIF_TXON - RIF Tx On */
/*! @{ */

#define BTU2_BTU_RIF_TXON_txon_fixed_MASK        (0x80U)
#define BTU2_BTU_RIF_TXON_txon_fixed_SHIFT       (7U)
/*! txon_fixed - TxOn fixed; or use programmable timing, 0x0: use start and stop timing parameters, 0x1: txOn = TxOn_Start[6] */
#define BTU2_BTU_RIF_TXON_txon_fixed(x)          (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TXON_txon_fixed_SHIFT)) & BTU2_BTU_RIF_TXON_txon_fixed_MASK)

#define BTU2_BTU_RIF_TXON_txon_stop_MASK         (0xFF00U)
#define BTU2_BTU_RIF_TXON_txon_stop_SHIFT        (8U)
/*! txon_stop - Delay from Tx finished (rifTx low) to txOn falling edge, - Resolution: 0.25 us. */
#define BTU2_BTU_RIF_TXON_txon_stop(x)           (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TXON_txon_stop_SHIFT)) & BTU2_BTU_RIF_TXON_txon_stop_MASK)
/*! @} */

/*! @name BTU_RIF_PLLCLKEN_OFF_DELAY - RIF PLL Clock Enable Off Delay */
/*! @{ */

#define BTU2_BTU_RIF_PLLCLKEN_OFF_DELAY_brf_pll_clk_en_off_delay_MASK (0x7FU)
#define BTU2_BTU_RIF_PLLCLKEN_OFF_DELAY_brf_pll_clk_en_off_delay_SHIFT (0U)
/*! brf_pll_clk_en_off_delay - Delay from final dBus access finishing to turning off BRF PLL clock, - Resolution: 0.25 us. */
#define BTU2_BTU_RIF_PLLCLKEN_OFF_DELAY_brf_pll_clk_en_off_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PLLCLKEN_OFF_DELAY_brf_pll_clk_en_off_delay_SHIFT)) & BTU2_BTU_RIF_PLLCLKEN_OFF_DELAY_brf_pll_clk_en_off_delay_MASK)
/*! @} */

/*! @name BTU_RIF_FREQ - RIF FREQ */
/*! @{ */

#define BTU2_BTU_RIF_FREQ_rxtx_freq_MASK         (0x100U)
#define BTU2_BTU_RIF_FREQ_rxtx_freq_SHIFT        (8U)
/*! rxtx_freq - Rx or Tx Slot Indication, 0x0: Tx slot, 0x1: Rx slot */
#define BTU2_BTU_RIF_FREQ_rxtx_freq(x)           (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_FREQ_rxtx_freq_SHIFT)) & BTU2_BTU_RIF_FREQ_rxtx_freq_MASK)

#define BTU2_BTU_RIF_FREQ_freq_MASK              (0xFE00U)
#define BTU2_BTU_RIF_FREQ_freq_SHIFT             (9U)
/*! freq - Channel Hop Frequency Number */
#define BTU2_BTU_RIF_FREQ_freq(x)                (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_FREQ_freq_SHIFT)) & BTU2_BTU_RIF_FREQ_freq_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_TX_PU - RIF BRF Power Up for TX, brf_pu is the sideband signal used to turn on the BRF's power control. */
/*! @{ */

#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_on_delay_qus_MASK (0xFFU)
#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_on_delay_qus_SHIFT (0U)
/*! brf_tx_pu_on_delay_qus - brf_pu on delay, Delay from wakeUp to turning on brf_pu. Resolution: 0.25 us. */
#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_on_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_on_delay_qus_SHIFT)) & BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_on_delay_qus_MASK)

#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_off_delay_qus_MASK (0x7F00U)
#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_off_delay_qus_SHIFT (8U)
/*! brf_tx_pu_off_delay_qus - brf_pu off delay, Delay from last dBus access to turning off brf_pu. Resolution: 0.25 us. */
#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_off_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_off_delay_qus_SHIFT)) & BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_off_delay_qus_MASK)

#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_fixed_MASK (0x8000U)
#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_fixed_SHIFT (15U)
/*! brf_tx_pu_fixed - Set brf_pu to a fixed value., BRF power up value., 0x0: use programmable
 *    timers, 0x1: fixed; brf_pu = brf_tx_pu_on_delay_us[0]
 */
#define BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_fixed(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_fixed_SHIFT)) & BTU2_BTU_RIF_BRF_TX_PU_brf_tx_pu_fixed_MASK)
/*! @} */

/*! @name BTU_RIF_CTRL2 - RIF Control 2 */
/*! @{ */

#define BTU2_BTU_RIF_CTRL2_tx_data_inv_MASK      (0x2000U)
#define BTU2_BTU_RIF_CTRL2_tx_data_inv_SHIFT     (13U)
/*! tx_data_inv - Invert Tx data, 0x0: normal operation, 0x1: transmit data inverted */
#define BTU2_BTU_RIF_CTRL2_tx_data_inv(x)        (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTRL2_tx_data_inv_SHIFT)) & BTU2_BTU_RIF_CTRL2_tx_data_inv_MASK)

#define BTU2_BTU_RIF_CTRL2_rx_data_inv_MASK      (0x4000U)
#define BTU2_BTU_RIF_CTRL2_rx_data_inv_SHIFT     (14U)
/*! rx_data_inv - Invert Rx data, 0x0: normal operation, 0x1: receive data inverted */
#define BTU2_BTU_RIF_CTRL2_rx_data_inv(x)        (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CTRL2_rx_data_inv_SHIFT)) & BTU2_BTU_RIF_CTRL2_rx_data_inv_MASK)
/*! @} */

/*! @name BTU_RIF_TX_PULSE - RIF Tx Pulse */
/*! @{ */

#define BTU2_BTU_RIF_TX_PULSE_tx_pulse_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_TX_PULSE_tx_pulse_delay_SHIFT (0U)
/*! tx_pulse_delay - Tx Pulse Delay, Delay between wakeUp and txData sync plulse for dBus radio
 *    types. Resolution 0.25 us. The following formula must be fulfilled: doTxPulse < TxOn_Start +
 *    LinkDelay.
 */
#define BTU2_BTU_RIF_TX_PULSE_tx_pulse_delay(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TX_PULSE_tx_pulse_delay_SHIFT)) & BTU2_BTU_RIF_TX_PULSE_tx_pulse_delay_MASK)

#define BTU2_BTU_RIF_TX_PULSE_tx_pulse_en_MASK   (0x8000U)
#define BTU2_BTU_RIF_TX_PULSE_tx_pulse_en_SHIFT  (15U)
/*! tx_pulse_en - Enable TxData sync pulse, 0x0: TxData sync pulse deactivated and pulse not
 *    generated, 0x1: TxData sync pulse activated and pulse generated
 */
#define BTU2_BTU_RIF_TX_PULSE_tx_pulse_en(x)     (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TX_PULSE_tx_pulse_en_SHIFT)) & BTU2_BTU_RIF_TX_PULSE_tx_pulse_en_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_TX_PWRCTL - RIF dBus Tx Power Control */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_delay_SHIFT (0U)
/*! dbus_tx_pwr_ctrl_wr_delay - Delay from the trigger to start Tx Power Control Write dBus, Delay
 *    from rif_tx_req to enable Tx power control dBus writes. Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_delay_MASK)

#define BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_enable_SHIFT (15U)
/*! dbus_tx_pwr_ctrl_wr_enable - Enable Automatic Tx Power Control Write on the dBus */
#define BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_TX_PWRCTL_dbus_tx_pwr_ctrl_wr_enable_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_PWRCTL - RIF dBus Rx Power Control */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_delay_SHIFT (0U)
/*! dbus_rx_pwr_ctrl_wr_delay - Delay from the trigger to start Rx Power Control Write dBus, Delay
 *    from rif_rx_req to enable Rx power control dBus writes. Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_delay_MASK)

#define BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_enable_SHIFT (15U)
/*! dbus_rx_pwr_ctrl_wr_enable - Enable Automatic Rx Power Control Write on dBus */
#define BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_PWRCTL_dbus_rx_pwr_ctrl_wr_enable_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RXPWRCTL_ADDR - RIF BRF Rx Power Control Address */
/*! @{ */

#define BTU2_BTU_RIF_BRF_RXPWRCTL_ADDR_rx_pwr_ctrl_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_RXPWRCTL_ADDR_rx_pwr_ctrl_addr_SHIFT (0U)
/*! rx_pwr_ctrl_addr - Radio Register Address for Rx Power Control */
#define BTU2_BTU_RIF_BRF_RXPWRCTL_ADDR_rx_pwr_ctrl_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RXPWRCTL_ADDR_rx_pwr_ctrl_addr_SHIFT)) & BTU2_BTU_RIF_BRF_RXPWRCTL_ADDR_rx_pwr_ctrl_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_FSYN_ADDR - RIF BRF FSYN Address */
/*! @{ */

#define BTU2_BTU_RIF_BRF_FSYN_ADDR_fsyn_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_FSYN_ADDR_fsyn_addr_SHIFT (0U)
/*! fsyn_addr - Radio Register Start Address for Fsyn data */
#define BTU2_BTU_RIF_BRF_FSYN_ADDR_fsyn_addr(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_FSYN_ADDR_fsyn_addr_SHIFT)) & BTU2_BTU_RIF_BRF_FSYN_ADDR_fsyn_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_TXPWRCTL_ADDR - RIF BRF Tx Power Control Address */
/*! @{ */

#define BTU2_BTU_RIF_BRF_TXPWRCTL_ADDR_tx_pwr_ctrl_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_TXPWRCTL_ADDR_tx_pwr_ctrl_addr_SHIFT (0U)
/*! tx_pwr_ctrl_addr - Radio Register Address for Tx Power Control */
#define BTU2_BTU_RIF_BRF_TXPWRCTL_ADDR_tx_pwr_ctrl_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_TXPWRCTL_ADDR_tx_pwr_ctrl_addr_SHIFT)) & BTU2_BTU_RIF_BRF_TXPWRCTL_ADDR_tx_pwr_ctrl_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_RSSI - BTC RIF dBus RSSI */
/*! @{ */

#define BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_delay_SHIFT (0U)
/*! dbus_rssi_delay - Delay from RSSI trigger to start of RSSI read, Delay from the end of
 *    rif_rx_req to enable dBus RSSI read back., Resolution 0.25 us.
 */
#define BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_delay_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_delay_MASK)

#define BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_enable_SHIFT (15U)
/*! dbus_rssi_enable - Enable Automatic Reading of RSSI on the dBus, 0x0: disable automatic reading
 *    of RSSI, 0x1: enable automatic reading of RSSI
 */
#define BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_enable_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_RSSI_dbus_rssi_enable_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_TX_FSYN - RIF Tx dBus Fsyn */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_delay_SHIFT (0U)
/*! dbus_tx_fsyn_delay - Tx dBus Fsyn Delay, Delay from start of new Tx slot (i.e.; rif_tx_req) to
 *    sending the fsync information on the dBus., Resolution 0.25 us.
 */
#define BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_delay_MASK)

#define BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_wr_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_wr_enable_SHIFT (15U)
/*! dbus_tx_fsyn_wr_enable - Tx dBus Fsyn Enable, Enables Tx automatic sending of fsync information
 *    on the dBus., 0x0: disable automatic sending of fsync info, 0x1: enable automatic sending of
 *    fsync info
 */
#define BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_wr_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_wr_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_TX_FSYN_dbus_tx_fsyn_wr_enable_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_FSYN - RIF Rx dBus Fsyn */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_delay_SHIFT (0U)
/*! dbus_rx_fsyn_delay - Rx dBus Hop Delay, Delay time after start of Rx new slot (i.e.; rif_rx_req)
 *    to sending the fsync information on the dBus., Resolution 0.25 us.
 */
#define BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_delay_MASK)

#define BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_wr_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_wr_enable_SHIFT (15U)
/*! dbus_rx_fsyn_wr_enable - Rx dBus Fsyn Enable, Enable Rx automatic sending of fsync information
 *    on the dBus., 0x0: disable automatic sending of fsync info, 0x1: enable automatic sending of
 *    fsync info
 */
#define BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_wr_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_wr_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_FSYN_dbus_rx_fsyn_wr_enable_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_PKT_LEN - RIF dBus Rx Packet Length */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_cte_len_enable_MASK (0x4000U)
#define BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_cte_len_enable_SHIFT (14U)
/*! dbus_rx_cte_len_enable - dBus Rx CTE Length Enable, Enable Automatic Sending Rx Packet CTE
 *    Length on the dBus., 0x0: disable automatic dbus sending Rx packet CTE length, 0x1: enable
 *    automatic dbus sending Rx packet CTE length
 */
#define BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_cte_len_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_cte_len_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_cte_len_enable_MASK)

#define BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_pkt_len_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_pkt_len_enable_SHIFT (15U)
/*! dbus_rx_pkt_len_enable - dBus Rx Packet Length Enable, Enable Automatic Sending Rx Packet
 *    Payload Length (including payload header; data; and crc) on the dBus., 0x0: disable automatic dbus
 *    sending Rx packet payload length, 0x1: enable automatic dbus sending Rx packet payload length
 */
#define BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_pkt_len_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_pkt_len_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_PKT_LEN_dbus_rx_pkt_len_enable_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_PULSE_RX_DELAY - RIF BLE Pulse Rx Delay */
/*! @{ */

#define BTU2_BTU_RIF_BLE_PULSE_RX_DELAY_ble_pulse_rx_delay_MASK (0x3FFU)
#define BTU2_BTU_RIF_BLE_PULSE_RX_DELAY_ble_pulse_rx_delay_SHIFT (0U)
/*! ble_pulse_rx_delay - BLE Pulse Rx Delay, Timing Variable from rif_rx_req to BLE Pulse on Rx.
 *    Only assert under BLE traffic; and must be less or equal to BTU_RIF_RXPAON[9:0] - 4., -
 *    Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_BLE_PULSE_RX_DELAY_ble_pulse_rx_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_PULSE_RX_DELAY_ble_pulse_rx_delay_SHIFT)) & BTU2_BTU_RIF_BLE_PULSE_RX_DELAY_ble_pulse_rx_delay_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_PULSE_TX_DELAY - RIF BLE Pulse Tx Delay */
/*! @{ */

#define BTU2_BTU_RIF_BLE_PULSE_TX_DELAY_ble_pulse_tx_delay_MASK (0x3FFU)
#define BTU2_BTU_RIF_BLE_PULSE_TX_DELAY_ble_pulse_tx_delay_SHIFT (0U)
/*! ble_pulse_tx_delay - BLE Pulse Tx Delay, Timing Variable from rif_rx_req to BLE Pulse on Tx.
 *    Only assert under BLE traffic; and must be less or equal to BTU_RIF_TXPAON[9:0] - 4., -
 *    Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_BLE_PULSE_TX_DELAY_ble_pulse_tx_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_PULSE_TX_DELAY_ble_pulse_tx_delay_SHIFT)) & BTU2_BTU_RIF_BLE_PULSE_TX_DELAY_ble_pulse_tx_delay_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_MODE_TYPE - RIF dBus Rx Mode Type */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_RX_MODE_TYPE_dbus_rx_mode_type_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_RX_MODE_TYPE_dbus_rx_mode_type_enable_SHIFT (15U)
/*! dbus_rx_mode_type_enable - dBus Rx Mode Type Enable, Enable Automatic Sending Rx Mode Type
 *    (decoded from packet header) on the dBus., 0x0: disable automatic dbus sending Rx mode type, 0x1:
 *    enable automatic dbus sending Rx mode type
 */
#define BTU2_BTU_RIF_DBUS_RX_MODE_TYPE_dbus_rx_mode_type_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_MODE_TYPE_dbus_rx_mode_type_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_MODE_TYPE_dbus_rx_mode_type_enable_MASK)
/*! @} */

/*! @name BTU_RIF_MODE_TYPE_TX_DELAY - RIF Mode Type Tx Delay */
/*! @{ */

#define BTU2_BTU_RIF_MODE_TYPE_TX_DELAY_mode_type_tx_delay_MASK (0x3FFU)
#define BTU2_BTU_RIF_MODE_TYPE_TX_DELAY_mode_type_tx_delay_SHIFT (0U)
/*! mode_type_tx_delay - Mode Type Tx Delay, Time from the assertion of modTypeTx to the deassertion of modTypeTx., - Resolution: 0.25 us. */
#define BTU2_BTU_RIF_MODE_TYPE_TX_DELAY_mode_type_tx_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_MODE_TYPE_TX_DELAY_mode_type_tx_delay_SHIFT)) & BTU2_BTU_RIF_MODE_TYPE_TX_DELAY_mode_type_tx_delay_MASK)
/*! @} */

/*! @name BTU_RIF_MODE_TYPE_RX_DELAY - RIF Mode Type Rx Delay */
/*! @{ */

#define BTU2_BTU_RIF_MODE_TYPE_RX_DELAY_mode_type_rx_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_MODE_TYPE_RX_DELAY_mode_type_rx_delay_SHIFT (0U)
/*! mode_type_rx_delay - Mode Type Rx Delay, Time from the assertion of modTypeRx to the deassertion
 *    of modTypeRx. For Gen4; it anchors the end of packet header for Rx sampling., - Resolution:
 *    0.25 us.
 */
#define BTU2_BTU_RIF_MODE_TYPE_RX_DELAY_mode_type_rx_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_MODE_TYPE_RX_DELAY_mode_type_rx_delay_SHIFT)) & BTU2_BTU_RIF_MODE_TYPE_RX_DELAY_mode_type_rx_delay_MASK)
/*! @} */

/*! @name BTU_RIF_PKTCTL_OE_DELAY - RIF Packet Control OE Delay */
/*! @{ */

#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_modetype_MASK (0xFU)
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_modetype_SHIFT (0U)
/*! pkt_ctl_oe_delay_modetype - Packet Control OE Delay Mode Type, Time from the Deassertion of
 *    modType to the Deassertion of pktCtl_oe., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_modetype(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_modetype_SHIFT)) & BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_modetype_MASK)

#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_ppulse_MASK (0xF0U)
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_ppulse_SHIFT (4U)
/*! pkt_ctl_oe_delay_ppulse - Packet Control OE Delay P Pulse, Time from the Deassertion of P pulse
 *    to the Deasserttion of pktCtl oe., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_ppulse(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_ppulse_SHIFT)) & BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_ppulse_MASK)

#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_hdrstart_MASK (0xF00U)
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_hdrstart_SHIFT (8U)
/*! pkt_ctl_oe_delay_hdrstart - Packet Control OE Delay Header Start, Time from the Deassertion of
 *    Header Start pulse to the Assertion of pktCtl oe., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_hdrstart(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_hdrstart_SHIFT)) & BTU2_BTU_RIF_PKTCTL_OE_DELAY_pkt_ctl_oe_delay_hdrstart_MASK)

#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_rf_bypass_MASK (0x8000U)
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_rf_bypass_SHIFT (15U)
/*! rf_bypass - Radio Bypass Mode Used for Baseband to Baseband Testing, When set; it will do two
 *    things on pktCtrl_1:, - On Rx slot; it sets output enable as input., - On Tx slot; it generates
 *    a sync pulse before payload.
 */
#define BTU2_BTU_RIF_PKTCTL_OE_DELAY_rf_bypass(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_PKTCTL_OE_DELAY_rf_bypass_SHIFT)) & BTU2_BTU_RIF_PKTCTL_OE_DELAY_rf_bypass_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_CTL - RIF Software dBus Control */
/*! @{ */

#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_addr_SHIFT (0U)
/*! sw_dbus_addr - dBus register address, BRF register offset address. */
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_addr(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_addr_SHIFT)) & BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_addr_MASK)

#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_size_bytes_MASK (0x3800U)
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_size_bytes_SHIFT (11U)
/*! sw_dbus_size_bytes - number of bytes to read or write, Burst read or write is supported; a
 *    maximum of 8 bytes at once., 0x0: 1 byte, 0x1: 2 bytes, 0x2: 3 bytes, 0x3: 4 bytes, 0x4: 5 byteS,
 *    0x5: 6 bytes, 0x6: 7 bytes, 0x7: 8 bytes
 */
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_size_bytes(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_size_bytes_SHIFT)) & BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_size_bytes_MASK)

#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_start_MASK (0x4000U)
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_start_SHIFT (14U)
/*! sw_dbus_start - Start a new dBus access, A new dBus register access is started when 1 is written
 *    to this bit (provided an access is not currently in progress). The read value is always 0.
 */
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_start(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_start_SHIFT)) & BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_start_MASK)

#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_rd_MASK  (0x8000U)
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_rd_SHIFT (15U)
/*! sw_dbus_rd - Read/write control, 0x0: write, 0x1: read */
#define BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_rd(x)    (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_rd_SHIFT)) & BTU2_BTU_RIF_SWDBUS_CTL_sw_dbus_rd_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_EVENT - RIF Software dBus Event, - Max burst read or write: 8 bytes. */
/*! @{ */

#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_count_MASK (0x7FFU)
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_count_SHIFT (0U)
/*! sw_dbus_count - Count to trigger software dBus, Count value used in conjunction with
 *    sw_dbus_event; when applicable., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_count(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_count_SHIFT)) & BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_count_MASK)

#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_rst_MASK (0x1000U)
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_rst_SHIFT (12U)
/*! sw_dbus_rst - software dBus reset, If set; software dBus FSM will reset and transition to idle
 *    state. Software dBus finish will be issued. Firmware first writes 1 and then writes 0 to this
 *    bit.
 */
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_rst(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_rst_SHIFT)) & BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_rst_MASK)

#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_finished_MASK (0x2000U)
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_finished_SHIFT (13U)
/*! sw_dbus_finished - Poll status of dBus access, When set; the dBus read or write access is
 *    finished. This bit is reset when writing to BTU_RIF_SWDBUS_CTL reg for the next access., 0x0: busy,
 *    0x1: finished
 */
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_finished(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_finished_SHIFT)) & BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_finished_MASK)

#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_event_MASK (0xC000U)
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_event_SHIFT (14U)
/*! sw_dbus_event - Event to trigger software dBus access, SWDBUS_EVENT_NONPKT,0x0:
 *    SWDBUS_EVENT_NONPKT (when there is no packet activity), SWDBUS_EVENT_PKT_ASAP,0x1: SWDBUS_EVENT_PKT_ASAP (as
 *    soon as possible during packet activity), SWDBUS_EVENT_PKT_START,0x2: SWDBUS_EVENT_PKT_START
 *    (when rif_startCount equals sw_dbus_count), SWDBUS_EVENT_PKT_END,0x3: SWDBUS_EVENT_PKT_END (when
 *    rif_endCount equals sw_dbus_count)
 */
#define BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_event(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_event_SHIFT)) & BTU2_BTU_RIF_SWDBUS_EVENT_sw_dbus_event_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_1_0 - RIF Software dBus Data_1_0 */
/*! @{ */

#define BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata0_MASK (0xFFU)
#define BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata0_SHIFT (0U)
/*! sw_dbus_wdata0 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 1st 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata0_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata0_MASK)

#define BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata1_MASK (0xFF00U)
#define BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata1_SHIFT (8U)
/*! sw_dbus_wdata1 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 2nd 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata1_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_1_0_sw_dbus_wdata1_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_3_2 - RIF Software dBus Data_3_2 */
/*! @{ */

#define BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata2_MASK (0xFFU)
#define BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata2_SHIFT (0U)
/*! sw_dbus_wdata2 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 3rd 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata2(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata2_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata2_MASK)

#define BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata3_MASK (0xFF00U)
#define BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata3_SHIFT (8U)
/*! sw_dbus_wdata3 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 4th 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata3(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata3_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_3_2_sw_dbus_wdata3_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_5_4 - RIF Software dBus Data_5_4 */
/*! @{ */

#define BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata4_MASK (0xFFU)
#define BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata4_SHIFT (0U)
/*! sw_dbus_wdata4 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 5th 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata4(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata4_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata4_MASK)

#define BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata5_MASK (0xFF00U)
#define BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata5_SHIFT (8U)
/*! sw_dbus_wdata5 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 6th 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata5(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata5_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_5_4_sw_dbus_wdata5_MASK)
/*! @} */

/*! @name BTU_RIF_SWDBUS_DATA_7_6 - RIF Software dBus Data_7_6 */
/*! @{ */

#define BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata6_MASK (0xFFU)
#define BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata6_SHIFT (0U)
/*! sw_dbus_wdata6 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 7th 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata6(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata6_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata6_MASK)

#define BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata7_MASK (0xFF00U)
#define BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata7_SHIFT (8U)
/*! sw_dbus_wdata7 - Software Access Data, Set write data (write access); or get the read data (read
 *    access)., Updated automatically during read., Bits[7:0] of 8th 8-bit word.
 */
#define BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata7(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata7_SHIFT)) & BTU2_BTU_RIF_SWDBUS_DATA_7_6_sw_dbus_wdata7_MASK)
/*! @} */

/*! @name BTU_RIF_TX_FESW - RIF Tx FESW */
/*! @{ */

#define BTU2_BTU_RIF_TX_FESW_tx_fesw_on_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_TX_FESW_tx_fesw_on_delay_SHIFT (0U)
/*! tx_fesw_on_delay - Tx FESW On Delay, Number of microseconds from wakeUp to turning on bttx_fesw for Tx packets. */
#define BTU2_BTU_RIF_TX_FESW_tx_fesw_on_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TX_FESW_tx_fesw_on_delay_SHIFT)) & BTU2_BTU_RIF_TX_FESW_tx_fesw_on_delay_MASK)

#define BTU2_BTU_RIF_TX_FESW_tx_fesw_off_delay_MASK (0x3F00U)
#define BTU2_BTU_RIF_TX_FESW_tx_fesw_off_delay_SHIFT (8U)
/*! tx_fesw_off_delay - Tx FESW Off Delay, Number of microseconds from rifTx falling to turning off bttx_fesw. */
#define BTU2_BTU_RIF_TX_FESW_tx_fesw_off_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TX_FESW_tx_fesw_off_delay_SHIFT)) & BTU2_BTU_RIF_TX_FESW_tx_fesw_off_delay_MASK)

#define BTU2_BTU_RIF_TX_FESW_tx_fesw_en_MASK     (0x8000U)
#define BTU2_BTU_RIF_TX_FESW_tx_fesw_en_SHIFT    (15U)
/*! tx_fesw_en - Tx Front-End Switch (FESW) Enable, 0x0: bttx_fesw is fixed to 0, 0x1: enable FESW during for Tx packets */
#define BTU2_BTU_RIF_TX_FESW_tx_fesw_en(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TX_FESW_tx_fesw_en_SHIFT)) & BTU2_BTU_RIF_TX_FESW_tx_fesw_en_MASK)
/*! @} */

/*! @name BTU_RIF_RX_FESW - RIF Rx FESW */
/*! @{ */

#define BTU2_BTU_RIF_RX_FESW_rx_fesw_on_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_RX_FESW_rx_fesw_on_delay_SHIFT (0U)
/*! rx_fesw_on_delay - Rx FESW On Delay, Number of microseconds from rif_rx_req to turning on btrx_fesw for Rx packets. */
#define BTU2_BTU_RIF_RX_FESW_rx_fesw_on_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_FESW_rx_fesw_on_delay_SHIFT)) & BTU2_BTU_RIF_RX_FESW_rx_fesw_on_delay_MASK)

#define BTU2_BTU_RIF_RX_FESW_rx_fesw_off_delay_MASK (0x3F00U)
#define BTU2_BTU_RIF_RX_FESW_rx_fesw_off_delay_SHIFT (8U)
/*! rx_fesw_off_delay - Rx FESW Off Delay, Number of microseconds from rifRx falling to turning off btrx_fesw. */
#define BTU2_BTU_RIF_RX_FESW_rx_fesw_off_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_FESW_rx_fesw_off_delay_SHIFT)) & BTU2_BTU_RIF_RX_FESW_rx_fesw_off_delay_MASK)

#define BTU2_BTU_RIF_RX_FESW_rx_fesw_en_MASK     (0x8000U)
#define BTU2_BTU_RIF_RX_FESW_rx_fesw_en_SHIFT    (15U)
/*! rx_fesw_en - Rx FESW Enable, 0x0: btrx_fesw is fixed to 0, 0x1: enable FESW during for Rx packets */
#define BTU2_BTU_RIF_RX_FESW_rx_fesw_en(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_FESW_rx_fesw_en_SHIFT)) & BTU2_BTU_RIF_RX_FESW_rx_fesw_en_MASK)
/*! @} */

/*! @name BTU_RIF_RXPAON - RIF Rx PA On */
/*! @{ */

#define BTU2_BTU_RIF_RXPAON_rx_pa_on_delay_MASK  (0x3FFU)
#define BTU2_BTU_RIF_RXPAON_rx_pa_on_delay_SHIFT (0U)
/*! rx_pa_on_delay - Rx PA on Delay, Timing Variable from Wakeup (packet boundary) to PA Assertion on Rx Pulse., - Resolution: 0.25 us. */
#define BTU2_BTU_RIF_RXPAON_rx_pa_on_delay(x)    (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RXPAON_rx_pa_on_delay_SHIFT)) & BTU2_BTU_RIF_RXPAON_rx_pa_on_delay_MASK)

#define BTU2_BTU_RIF_RXPAON_rx_pa_on_en_MASK     (0x8000U)
#define BTU2_BTU_RIF_RXPAON_rx_pa_on_en_SHIFT    (15U)
/*! rx_pa_on_en - Rx PA On Delay Enable */
#define BTU2_BTU_RIF_RXPAON_rx_pa_on_en(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RXPAON_rx_pa_on_en_SHIFT)) & BTU2_BTU_RIF_RXPAON_rx_pa_on_en_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_PU - RIF BRF Power Up for RX, brf_pu is the sideband signal used to turn on the BRF's power control. */
/*! @{ */

#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_on_delay_qus_MASK (0xFFU)
#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_on_delay_qus_SHIFT (0U)
/*! brf_rx_pu_on_delay_qus - brf_pu on delay, Delay from wakeUp to turning on brf_pu. Resolution: 0.25 us. */
#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_on_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_on_delay_qus_SHIFT)) & BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_on_delay_qus_MASK)

#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_off_delay_qus_MASK (0x7F00U)
#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_off_delay_qus_SHIFT (8U)
/*! brf_rx_pu_off_delay_qus - brf_pu off delay, Delay from last dBus access to turning off brf_pu. Resolution: 0.25 us. */
#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_off_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_off_delay_qus_SHIFT)) & BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_off_delay_qus_MASK)

#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_fixed_MASK (0x8000U)
#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_fixed_SHIFT (15U)
/*! brf_rx_pu_fixed - Set brf_pu to a fixed value., BRF power up value., 0x0: use programmable
 *    timers, 0x1: fixed; brf_pu = brf_pu_on_delay_us[0]
 */
#define BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_fixed(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_fixed_SHIFT)) & BTU2_BTU_RIF_BRF_RX_PU_brf_rx_pu_fixed_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_TX_PKT_END - BTC RIF dBus Tx Packet End Control */
/*! @{ */

#define BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_SHIFT (0U)
/*! dbus_tx_pkt_end_delay - dBus Tx Packet End Delay, Time from the end of active Tx payload to dBus
 *    command that sets the radio back to IDLE., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_MASK)

#define BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_enable_SHIFT (15U)
/*! dbus_tx_pkt_end_enable - Tx Packet End dBus Transaction Enable */
#define BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_enable_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_TX_PKT_END_dbus_tx_pkt_end_enable_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_RX_PKT_END - BTC RIF dBus Rx Packet End Control */
/*! @{ */

#define BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_SHIFT (0U)
/*! dbus_rx_pkt_end_delay - dBus Rx Packet End Delay, Time from the end of active Rx payload to dBus
 *    command that sets the radio back to IDLE., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_MASK)

#define BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_enable_SHIFT (15U)
/*! dbus_rx_pkt_end_enable - Rx Packet End dBus Transaction Enable */
#define BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_enable_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_RX_PKT_END_dbus_rx_pkt_end_enable_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_DBUS_TX_RAMPDOWN - BTC RIF dBus Tx Rampdown Control */
/*! @{ */

#define BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_SHIFT (0U)
/*! dbus_tx_rampdown_delay - dBus Tx Rampdown Delay, Delay time after the end of a Tx slot for
 *    ramping down the radio over the dBus., Resolution 0.25 us.
 */
#define BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_MASK)

#define BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_enable_SHIFT (15U)
/*! dbus_tx_rampdown_enable - Enables Automatic Rampdown radio after Tx slot on the dBus, 0x0:
 *    disable automatic ramping down the radio after Tx slot, 0x1: enable automatic ramping down the
 *    radio after Tx slot
 */
#define BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_enable_SHIFT)) & BTU2_BTU_RIF_BTC_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_enable_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_COR_CONFIG_CTRL - RIF Correlator Configuration Control */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_delay_SHIFT (0U)
/*! dbus_corcfg_wr_delay - Rx Mode dBus BRF Correlator Configuration Control Delay, Delay from
 *    rif_rx_req to trigger correlator configuration dBus writes., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_delay_MASK)

#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ant_MASK (0x800U)
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ant_SHIFT (11U)
/*! cor_prem_det_gate_syncwd_en_ant - Enable BRF to start syncword detection after preamble found for Ant Mode */
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ant(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ant_SHIFT)) & BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ant_MASK)

#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_nike_MASK (0x1000U)
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_nike_SHIFT (12U)
/*! cor_prem_det_gate_syncwd_en_nike - Enable BRF to start syncword detection after preamble found for Nike Mode */
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_nike(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_nike_SHIFT)) & BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_nike_MASK)

#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ble_MASK (0x2000U)
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ble_SHIFT (13U)
/*! cor_prem_det_gate_syncwd_en_ble - Enable BRF to start syncword detection after preamble found for BLE Mode */
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ble(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ble_SHIFT)) & BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_cor_prem_det_gate_syncwd_en_ble_MASK)

#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_enable_SHIFT (15U)
/*! dbus_corcfg_wr_enable - Rx Mode dBus BRF Correlator Configuration Transaction Enable, Enable only when using MRVL Gen3 radio. */
#define BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_COR_CONFIG_CTRL_dbus_corcfg_wr_enable_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_COR_CONFIG_ADDR - RIF BRF Correlator Configuration Address, Only use in MRVL Gen3 Radio Mode. */
/*! @{ */

#define BTU2_BTU_RIF_BRF_COR_CONFIG_ADDR_rx_cor_cfg_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_COR_CONFIG_ADDR_rx_cor_cfg_addr_SHIFT (0U)
/*! rx_cor_cfg_addr - Radio Register Address for Correlator Configuration, Only use in MRVL Gen3
 *    radio mode., The BRF register of the correlator configuration.
 */
#define BTU2_BTU_RIF_BRF_COR_CONFIG_ADDR_rx_cor_cfg_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_COR_CONFIG_ADDR_rx_cor_cfg_addr_SHIFT)) & BTU2_BTU_RIF_BRF_COR_CONFIG_ADDR_rx_cor_cfg_addr_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL - RIF Syncword and Access Code Send Control */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_delay_SHIFT (0U)
/*! dbus_syncword_wr_delay - dBus Syncword and Access Code Control Delay, Delay from rif_rx_req to
 *    trigger syncword and access code control dBus writes., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_delay_MASK)

#define BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_enable_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_enable_SHIFT (15U)
/*! dbus_syncword_wr_enable - Rx Mode dBus Syncword and Access Code Transaction Enable */
#define BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_enable(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_enable_SHIFT)) & BTU2_BTU_RIF_DBUS_SYNCWD_ACC_CODE_CTRL_dbus_syncword_wr_enable_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_ACC_CODE_ONE_ADDR - RIF BRF Access Code 1 Address */
/*! @{ */

#define BTU2_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_rx_acc_code_one_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_rx_acc_code_one_addr_SHIFT (0U)
/*! rx_acc_code_one_addr - Radio Register Address for First Access Code, The LSB BRF register of the
 *    1st access code. Since BTC sync word is 64-bit long; the consecutive 8 BRF registers (1 byte
 *    each register) are allocated. Correlation hit used this sync word will reflect a PKT_CTL_0
 *    pulse.
 */
#define BTU2_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_rx_acc_code_one_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_rx_acc_code_one_addr_SHIFT)) & BTU2_BTU_RIF_BRF_ACC_CODE_ONE_ADDR_rx_acc_code_one_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_ACC_CODE_TWO_ADDR - RIF Access Code 2 Address */
/*! @{ */

#define BTU2_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_rx_acc_code_two_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_rx_acc_code_two_addr_SHIFT (0U)
/*! rx_acc_code_two_addr - Radio Register Address for Second Access Code, The LSB BRF register of
 *    the 2nd access code. Since BTC sync word is 64-bit long; the consecutive 8 BRF registers (1 byte
 *    each register) are allocated. Correlation hit used this sync word will reflect a PKT_CTL_1
 *    pulse.
 */
#define BTU2_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_rx_acc_code_two_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_rx_acc_code_two_addr_SHIFT)) & BTU2_BTU_RIF_BRF_ACC_CODE_TWO_ADDR_rx_acc_code_two_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_MODE_TYPE_ADDR - RIF Register */
/*! @{ */

#define BTU2_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_rx_mode_type_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_rx_mode_type_addr_SHIFT (0U)
/*! rx_mode_type_addr - Radio Register Address for Rx Mode Type, The BRF register of the expected Rx BDR/EDR mode type. */
#define BTU2_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_rx_mode_type_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_rx_mode_type_addr_SHIFT)) & BTU2_BTU_RIF_BRF_RX_MODE_TYPE_ADDR_rx_mode_type_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR - RIF Register */
/*! @{ */

#define BTU2_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_rx_pkt_pld_len_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_rx_pkt_pld_len_addr_SHIFT (0U)
/*! rx_pkt_pld_len_addr - Radio Register Address for Rx Packet Payload Length, The LSB BRF register
 *    of the expected Rx Packet Payload Length. The immediate next BRF registers is also allocated
 *    for MSB length portion., - Units: micro-seconds.
 */
#define BTU2_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_rx_pkt_pld_len_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_rx_pkt_pld_len_addr_SHIFT)) & BTU2_BTU_RIF_BRF_RX_PKT_PLD_LEN_ADDR_rx_pkt_pld_len_addr_MASK)
/*! @} */

/*! @name BTU_RIF_RX_SYNC_PULSE_TIMER - RIF BRF Rx Sync Pulse Timer */
/*! @{ */

#define BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_hdr_pulse_timeout_MASK (0x1FU)
#define BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_hdr_pulse_timeout_SHIFT (0U)
/*! rx_hdr_pulse_timeout - Rx Header Pulse Timeout, After correlation hit; timeout counter for the
 *    header sync pulse from the BRF. The BRF header start pulse is received when the packet header
 *    is sent on rx_data. If the header start pulse is not detected; then the packet would be
 *    aborted. This timeout specifies how long the BTU will wait before an abort., - Resolution: 1 us.
 */
#define BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_hdr_pulse_timeout(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_hdr_pulse_timeout_SHIFT)) & BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_hdr_pulse_timeout_MASK)

#define BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_sync_pulse_timeout_MASK (0x1F00U)
#define BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_sync_pulse_timeout_SHIFT (8U)
/*! rx_sync_pulse_timeout - Rx Sync Pulse Timeout, After header start pulse; timeout counter for the
 *    payload sync pulse from the BRF. The BRF payload sync pulse is received when the packet
 *    payload is sent on rx_data. If the payload sync pulse is not detected; then the packet would be
 *    aborted. This timeout specifies how long the BTU will wait before an abort., - Resolution: 1 us.
 */
#define BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_sync_pulse_timeout(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_sync_pulse_timeout_SHIFT)) & BTU2_BTU_RIF_RX_SYNC_PULSE_TIMER_rx_sync_pulse_timeout_MASK)
/*! @} */

/*! @name BTU_RIF_RX_BTC_SAMP_PHASE_ADJ - RIF Rx Sample Phase Adjustment */
/*! @{ */

#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_pos_adj_MASK (0x3U)
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_pos_adj_SHIFT (0U)
/*! hdr_start_pos_adj - Positive Phase Adjustment after Header starts Pulse, Positive phase
 *    adjustment after header starts pulse. The sampling point is delayed by the shift amount., -
 *    Resolution: 0.25 us (Gen3); 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_pos_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_pos_adj_SHIFT)) & BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_pos_adj_MASK)

#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_neg_adj_MASK (0xCU)
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_neg_adj_SHIFT (2U)
/*! hdr_start_neg_adj - Negative Phase Adjustment after Header starts Pulse, Negative phase
 *    adjustment after header starts pulse. The sampling point is advanced by the shift amount., -
 *    Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_neg_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_neg_adj_SHIFT)) & BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_hdr_start_neg_adj_MASK)

#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_pos_adj_MASK (0x300U)
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_pos_adj_SHIFT (8U)
/*! sync_start_pos_adj - Positive Phase Adjustment after Payload Sync starts Pulse, Positive phase
 *    adjustment after payload sync starts pulse. The sampling point is delayed by the shift amount.,
 *    - Resolution: 0.25 us (Gen3); 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_pos_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_pos_adj_SHIFT)) & BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_pos_adj_MASK)

#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_neg_adj_MASK (0xC00U)
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_neg_adj_SHIFT (10U)
/*! sync_start_neg_adj - Negative Phase Adjustment after Header Starts Pulse, Negative phase
 *    adjustment after payload sync starts pulse. The sampling point is advanced by the shift amount., -
 *    Resolution: 0.25 us (Gen3); 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_neg_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_neg_adj_SHIFT)) & BTU2_BTU_RIF_RX_BTC_SAMP_PHASE_ADJ_sync_start_neg_adj_MASK)
/*! @} */

/*! @name BTU_RIF_RX_BLE_SAMP_PHASE_ADJ - RIF Rx Sample Phase Adjustment */
/*! @{ */

#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_pos_adj_MASK (0x3U)
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_pos_adj_SHIFT (0U)
/*! pdu_start_pos_adj - Positive Phase Adjustment after PDU Data starts Pulse, Positive phase
 *    adjustment after PDU data starts pulse. The sampling point is delayed by the shift amount., -
 *    Resolution: 0.25 us (Gen3); 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_pos_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_pos_adj_SHIFT)) & BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_pos_adj_MASK)

#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_neg_adj_MASK (0xCU)
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_neg_adj_SHIFT (2U)
/*! pdu_start_neg_adj - Negative Phase Adjustment after PDU Data starts Pulse, Negative phase
 *    adjustment after PDU data starts pulse. The sampling point is advanced by the shift amount., -
 *    Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_neg_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_neg_adj_SHIFT)) & BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_pdu_start_neg_adj_MASK)

#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_pos_adj_MASK (0x300U)
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_pos_adj_SHIFT (8U)
/*! dfe_1m_phase_pos_adj - Positive Phase Adjustment for DFE I/Q Samples After CRC, Positive Phase
 *    Adjustment for 1 Mbps DFE I/Q samples after CRC. The sampling point is delayed by the shift
 *    amount., - Resolution: 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_pos_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_pos_adj_SHIFT)) & BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_pos_adj_MASK)

#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_neg_adj_MASK (0xC00U)
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_neg_adj_SHIFT (10U)
/*! dfe_1m_phase_neg_adj - Negative Phase Adjustment for DFE I/Q Samples After CRC, Positive Phase
 *    Adjustment for 1 Mbps DFE I/Q samples after CRC. The sampling point is advanced by the shift
 *    amount., - Resolution: 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_neg_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_neg_adj_SHIFT)) & BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_1m_phase_neg_adj_MASK)

#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_pos_adj_MASK (0x3000U)
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_pos_adj_SHIFT (12U)
/*! dfe_2m_phase_pos_adj - Positive Phase Adjustment for DFE I/Q Samples After CRC, Positive Phase
 *    Adjustment for 2 Mbps DFE I/Q samples after CRC. The sampling point is delayed by the shift
 *    amount., - Resolution: 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_pos_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_pos_adj_SHIFT)) & BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_pos_adj_MASK)

#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_neg_adj_MASK (0xC000U)
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_neg_adj_SHIFT (14U)
/*! dfe_2m_phase_neg_adj - Negative Phase Adjustment for DFE I/Q Samples After CRC, Positive Phase
 *    Adjustment for 2 Mbps DFE I/Q samples after CRC. The sampling point is advanced by the shift
 *    amount., - Resolution: 62.5 ns (Gen4).
 */
#define BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_neg_adj(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_neg_adj_SHIFT)) & BTU2_BTU_RIF_RX_BLE_SAMP_PHASE_ADJ_dfe_2m_phase_neg_adj_MASK)
/*! @} */

/*! @name BTU_RIF_RX_TONE_CANCEL_CTRL - Rx Tone Cancellation Control */
/*! @{ */

#define BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_rx_dbus_pull_in_time_MASK (0x3FU)
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_rx_dbus_pull_in_time_SHIFT (0U)
/*! rx_dbus_pull_in_time - Rx dBUS events pull-in time, This adjusts the pull-in time of the dBUS
 *    events including SOC_BT_BRF_PU; A3; A1; A2 and P pulse before Rx packet. This setting applies to
 *    both BTC and BLE packet. Resolution: 0.25us
 */
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_rx_dbus_pull_in_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_rx_dbus_pull_in_time_SHIFT)) & BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_rx_dbus_pull_in_time_MASK)

#define BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_ble_pull_in_en_MASK (0x200U)
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_ble_pull_in_en_SHIFT (9U)
/*! ble_pull_in_en - BLE dBUS events pull-in enable, Enable BLE Rx packet dBUS events pull-in when
 *    current BLE packet's frequency matches one of the 4 TONE_CANCEL_CHNL values., 0x0: disable,
 *    0x1: enable
 */
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_ble_pull_in_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_ble_pull_in_en_SHIFT)) & BTU2_BTU_RIF_RX_TONE_CANCEL_CTRL_ble_pull_in_en_MASK)
/*! @} */

/*! @name BTU_RIF_RX_TONE_CANCEL_CHNL10 - Rx Tone Cancellation Channel */
/*! @{ */

#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl0_MASK (0x7FU)
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl0_SHIFT (0U)
/*! tone_cancel_chnl0 - Rx Tone Cancellation Channel 0, If Rx packet's channel index value sent to
 *    BRF on A2 event matches this value; the Rx packet dBUS event will be pulled-in; upon enabled.
 */
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl0_SHIFT)) & BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl0_MASK)

#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl1_MASK (0x7F00U)
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl1_SHIFT (8U)
/*! tone_cancel_chnl1 - Rx Tone Cancellation Channel 1, If Rx packet's channel index value sent to
 *    BRF on A2 event matches this value; the Rx packet dBUS event will be pulled-in; upon enabled.
 */
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl1_SHIFT)) & BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL10_tone_cancel_chnl1_MASK)
/*! @} */

/*! @name BTU_RIF_RX_TONE_CANCEL_CHNL32 - Rx Tone Cancellation Channel */
/*! @{ */

#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl2_MASK (0x7FU)
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl2_SHIFT (0U)
/*! tone_cancel_chnl2 - Rx Tone Cancellation Channel 2, If Rx packet's channel index value sent to
 *    BRF on A2 event matches this value; the Rx packet dBUS event will be pulled-in; upon enabled.
 */
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl2(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl2_SHIFT)) & BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl2_MASK)

#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl3_MASK (0x7F00U)
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl3_SHIFT (8U)
/*! tone_cancel_chnl3 - Rx Tone Cancellation Channel 3, If Rx packet's channel index value sent to
 *    BRF on A2 event matches this value; the Rx packet dBUS event will be pulled-in; upon enabled.
 */
#define BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl3(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl3_SHIFT)) & BTU2_BTU_RIF_RX_TONE_CANCEL_CHNL32_tone_cancel_chnl3_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CTL - BLE RIF Control */
/*! @{ */

#define BTU2_BTU_RIF_BLE_CTL_ble_brf_pu_MASK     (0x2U)
#define BTU2_BTU_RIF_BLE_CTL_ble_brf_pu_SHIFT    (1U)
/*! ble_brf_pu - BLE BRF Power up, This bit used by the BLE software to control the power up bit for the BRF., 0x0: disable, 0x1: enable */
#define BTU2_BTU_RIF_BLE_CTL_ble_brf_pu(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CTL_ble_brf_pu_SHIFT)) & BTU2_BTU_RIF_BLE_CTL_ble_brf_pu_MASK)

#define BTU2_BTU_RIF_BLE_CTL_ble_pll_req_MASK    (0x4U)
#define BTU2_BTU_RIF_BLE_CTL_ble_pll_req_SHIFT   (2U)
/*! ble_pll_req - BLE PLL Clock Request, This bit is used by the BLE software to control the PLL clock enable., 0x0: disable, 0x1: enable */
#define BTU2_BTU_RIF_BLE_CTL_ble_pll_req(x)      (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CTL_ble_pll_req_SHIFT)) & BTU2_BTU_RIF_BLE_CTL_ble_pll_req_MASK)

#define BTU2_BTU_RIF_BLE_CTL_data_loopback_en_MASK (0x8U)
#define BTU2_BTU_RIF_BLE_CTL_data_loopback_en_SHIFT (3U)
/*! data_loopback_en - BLE Loopback Data Enable, Setting this bit changes the source of the BLE Rx
 *    data from the Tx block instead of from the BRF., 0x0: Rx data is from BRF, 0x1: Rx data is from
 *    Tx block
 */
#define BTU2_BTU_RIF_BLE_CTL_data_loopback_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CTL_data_loopback_en_SHIFT)) & BTU2_BTU_RIF_BLE_CTL_data_loopback_en_MASK)

#define BTU2_BTU_RIF_BLE_CTL_rx_iq_sample_phase_MASK (0x30U)
#define BTU2_BTU_RIF_BLE_CTL_rx_iq_sample_phase_SHIFT (4U)
/*! rx_iq_sample_phase - BLE Rx IQ Sampling Rate Phase, To use in conjunction with
 *    rx_iq_sample_rate[1:0] in 'BLE_REG_DFE_PKT_EXTENSION_CNTRL'; define IQ sample reception phase in Rx extension
 *    field., When rx_iq_sample_rate[1:0] == 0; receiving IQ samples every 4 usec; on the phase
 *    rx_iq_sample_phase[1:0] herein specified (i.e. 0~3)., When rx_iq_sample_rate[1:0] == 1; receiving
 *    IQ samples every 2 usec; on the phase rx_iq_sample_phase[0] herein specified (i.e. 0: on even
 *    phase; 1: on odd phase)., When rx_iq_sample_rate[1:0] == 0; receiving IQ samples every 1 usec
 *    on every phase; rx_iq_sample_phase[1:0] is ignored.
 */
#define BTU2_BTU_RIF_BLE_CTL_rx_iq_sample_phase(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CTL_rx_iq_sample_phase_SHIFT)) & BTU2_BTU_RIF_BLE_CTL_rx_iq_sample_phase_MASK)

#define BTU2_BTU_RIF_BLE_CTL_ble_tx_pwr_adj_en_MASK (0x40U)
#define BTU2_BTU_RIF_BLE_CTL_ble_tx_pwr_adj_en_SHIFT (6U)
/*! ble_tx_pwr_adj_en - BLE TX power adjust enable, Global enable for BLE Tx power adjustment scheme
 *    - outputting Tx_power_level to BCA at bt_req and overwriting with Bfdbk_Tx_power if
 *    Bfdbk_Tx_power_ind., 0x0: disable, 0x1: enable
 */
#define BTU2_BTU_RIF_BLE_CTL_ble_tx_pwr_adj_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CTL_ble_tx_pwr_adj_en_SHIFT)) & BTU2_BTU_RIF_BLE_CTL_ble_tx_pwr_adj_en_MASK)

#define BTU2_BTU_RIF_BLE_CTL_ble_ignore_bca_tx_pwr_MASK (0x80U)
#define BTU2_BTU_RIF_BLE_CTL_ble_ignore_bca_tx_pwr_SHIFT (7U)
/*! ble_ignore_bca_tx_pwr - BLE ignore BCA TX power, FW overide to ignore BCA's Bfdbk_Tx_power if
 *    Bfdbk_Tx_power_ind; for current BLE Tx pkt., 0x0: disable, 0x1: enable
 */
#define BTU2_BTU_RIF_BLE_CTL_ble_ignore_bca_tx_pwr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CTL_ble_ignore_bca_tx_pwr_SHIFT)) & BTU2_BTU_RIF_BLE_CTL_ble_ignore_bca_tx_pwr_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_LENGTH_SEL - BLE Correlation Length Selection */
/*! @{ */

#define BTU2_BTU_RIF_BLE_COR_LENGTH_SEL_ble_cor_indicator_MASK (0xCU)
#define BTU2_BTU_RIF_BLE_COR_LENGTH_SEL_ble_cor_indicator_SHIFT (2U)
/*! ble_cor_indicator - BLE Correlator Indicator, BLE correlator indicator to enable which
 *    correlator is used., 0x0: no correlator enabled, 0x1: correlator one enabled, 0x2: correlator two
 *    enabled, 0x3: both correlators enabled
 */
#define BTU2_BTU_RIF_BLE_COR_LENGTH_SEL_ble_cor_indicator(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_COR_LENGTH_SEL_ble_cor_indicator_SHIFT)) & BTU2_BTU_RIF_BLE_COR_LENGTH_SEL_ble_cor_indicator_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_ACCESSADDR_0 - BLE AccessCode */
/*! @{ */

#define BTU2_BTU_RIF_BLE_COR_ACCESSADDR_0_ble_access_code_0_16_MASK (0xFFFFU)
#define BTU2_BTU_RIF_BLE_COR_ACCESSADDR_0_ble_access_code_0_16_SHIFT (0U)
/*! ble_access_code_0_16 - BLE Access Code, BLE Access Code to be used in correlator for the current Rx packet (lower 16-bit). */
#define BTU2_BTU_RIF_BLE_COR_ACCESSADDR_0_ble_access_code_0_16(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_COR_ACCESSADDR_0_ble_access_code_0_16_SHIFT)) & BTU2_BTU_RIF_BLE_COR_ACCESSADDR_0_ble_access_code_0_16_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_ACCESSADDR_1 - BLE AccessCode */
/*! @{ */

#define BTU2_BTU_RIF_BLE_COR_ACCESSADDR_1_ble_access_code_17_32_MASK (0xFFFFU)
#define BTU2_BTU_RIF_BLE_COR_ACCESSADDR_1_ble_access_code_17_32_SHIFT (0U)
/*! ble_access_code_17_32 - BLE Access Code, BLE Access Code to be used in correlator for the current Rx packet(upper 16-bit). */
#define BTU2_BTU_RIF_BLE_COR_ACCESSADDR_1_ble_access_code_17_32(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_COR_ACCESSADDR_1_ble_access_code_17_32_SHIFT)) & BTU2_BTU_RIF_BLE_COR_ACCESSADDR_1_ble_access_code_17_32_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_WINDOW_0 - BLE Correlation Window Size */
/*! @{ */

#define BTU2_BTU_RIF_BLE_COR_WINDOW_0_ble_cor_window_0_MASK (0xFFFFU)
#define BTU2_BTU_RIF_BLE_COR_WINDOW_0_ble_cor_window_0_SHIFT (0U)
/*! ble_cor_window_0 - BLE Correlation Window Size, BLE correlation window size for the current Rx
 *    packet (lower 16-bit)., Correlation window in 1/4 usec. Hardware will automatically abort Rx
 *    operation up expiration of this window time. Maximum window size: 2^26/4 = 16777216 usec.
 */
#define BTU2_BTU_RIF_BLE_COR_WINDOW_0_ble_cor_window_0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_COR_WINDOW_0_ble_cor_window_0_SHIFT)) & BTU2_BTU_RIF_BLE_COR_WINDOW_0_ble_cor_window_0_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_COR_WINDOW_1 - BLE Correlation Window Size */
/*! @{ */

#define BTU2_BTU_RIF_BLE_COR_WINDOW_1_ble_cor_window_1_MASK (0x3FFU)
#define BTU2_BTU_RIF_BLE_COR_WINDOW_1_ble_cor_window_1_SHIFT (0U)
/*! ble_cor_window_1 - BLE Correlation Window Size, BLE correlation window size for the current Rx
 *    packet (Upper 10-bit)., Correlation window in 1/4 usec. Hardware will automatically abort Rx
 *    operation up expiration of this window time. Maximum window size: 2^26/4 = 16777216 usec.
 */
#define BTU2_BTU_RIF_BLE_COR_WINDOW_1_ble_cor_window_1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_COR_WINDOW_1_ble_cor_window_1_SHIFT)) & BTU2_BTU_RIF_BLE_COR_WINDOW_1_ble_cor_window_1_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CLK_EN_DELAY - Tx/Rx Clock Enable Signal Delay */
/*! @{ */

#define BTU2_BTU_RIF_BLE_CLK_EN_DELAY_tx_clk_en_delay_qus_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_CLK_EN_DELAY_tx_clk_en_delay_qus_SHIFT (0U)
/*! tx_clk_en_delay_qus - Tx_clk_en Delay Offset, This is the delay offset for the tx_clk_en signal from the Tx S pulse., - Resolution: 1/4 usec. */
#define BTU2_BTU_RIF_BLE_CLK_EN_DELAY_tx_clk_en_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_EN_DELAY_tx_clk_en_delay_qus_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_EN_DELAY_tx_clk_en_delay_qus_MASK)

#define BTU2_BTU_RIF_BLE_CLK_EN_DELAY_rx_clk_en_delay_qus_MASK (0xFF00U)
#define BTU2_BTU_RIF_BLE_CLK_EN_DELAY_rx_clk_en_delay_qus_SHIFT (8U)
/*! rx_clk_en_delay_qus - Rx_clk_en Delay Offset, This is the delay offset for the rx_clk_en signal from the Rx P pulse., - Resolution: 1/4 usec. */
#define BTU2_BTU_RIF_BLE_CLK_EN_DELAY_rx_clk_en_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_EN_DELAY_rx_clk_en_delay_qus_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_EN_DELAY_rx_clk_en_delay_qus_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_GO_DELAY - RIF Go Signal Delay */
/*! @{ */

#define BTU2_BTU_RIF_BLE_GO_DELAY_rif_tx_go_delay_qus_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_GO_DELAY_rif_tx_go_delay_qus_SHIFT (0U)
/*! rif_tx_go_delay_qus - RIF_TX_GO Delay Offset, This is the delay offset for the rif_tx_go signal from the Tx S pulse., - Res: 1/4 usec. */
#define BTU2_BTU_RIF_BLE_GO_DELAY_rif_tx_go_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_GO_DELAY_rif_tx_go_delay_qus_SHIFT)) & BTU2_BTU_RIF_BLE_GO_DELAY_rif_tx_go_delay_qus_MASK)

#define BTU2_BTU_RIF_BLE_GO_DELAY_rif_rx_go_delay_qus_MASK (0xFF00U)
#define BTU2_BTU_RIF_BLE_GO_DELAY_rif_rx_go_delay_qus_SHIFT (8U)
/*! rif_rx_go_delay_qus - RIF_RX_GO Delay Offset, This is the delay offset for the rif_rx_go signal from the Rx P pulse., - Res: 1/4 usec. */
#define BTU2_BTU_RIF_BLE_GO_DELAY_rif_rx_go_delay_qus(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_GO_DELAY_rif_rx_go_delay_qus_SHIFT)) & BTU2_BTU_RIF_BLE_GO_DELAY_rif_rx_go_delay_qus_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA - Tx Power Control DBUS Write Data */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_rif_dbus_tx_pwrctl_wdata_MASK (0xFFFFU)
#define BTU2_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_rif_dbus_tx_pwrctl_wdata_SHIFT (0U)
/*! rif_dbus_tx_pwrctl_wdata - Tx Power Control DBUS Write Data, Tx A1 pulse., - Bits[9:8]: Tx data
 *    rate, - Bits[7:0]: Tx power table index, 0x0: reserved, 0x1: BDR 1 Mbps / BLE 1 Mbps / ANT 1
 *    Mbps, 0x2: EDR 2 Mbps / BLE 2 Mbps, 0x3: EDR 3 Mbps
 */
#define BTU2_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_rif_dbus_tx_pwrctl_wdata(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_rif_dbus_tx_pwrctl_wdata_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_TX_PWRCTL_WDATA_rif_dbus_tx_pwrctl_wdata_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_FSYN_WDATA - Tx Fsyn DBUS Write Data */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_rif_dbus_tx_fsyn_wdata_MASK (0xFFFFU)
#define BTU2_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_rif_dbus_tx_fsyn_wdata_SHIFT (0U)
/*! rif_dbus_tx_fsyn_wdata - Tx Fsyn DBUS Write Data, Tx A2 pulse., - Bits[15:13]: Bluetooth mode -
 *    BTC; BLE; NIKE; ANT or LLR, - Bit[12]: Rx notch filter enable, - Bit[11]: reserved, - Bit[10]:
 *    power up BRF BG/CPREG, - Bits[9:8]: Bluetooth state - Tx; Rx, - Bit[7]: large correlation
 *    window indicator, - Bits[6:0]: Bluetooth channel from 0 to 78
 */
#define BTU2_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_rif_dbus_tx_fsyn_wdata(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_rif_dbus_tx_fsyn_wdata_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_TX_FSYN_WDATA_rif_dbus_tx_fsyn_wdata_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA - Rx Power Control DBUS Write Data */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_rif_dbus_rx_pwrctl_wdata_MASK (0xFFFFU)
#define BTU2_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_rif_dbus_rx_pwrctl_wdata_SHIFT (0U)
/*! rif_dbus_rx_pwrctl_wdata - Rx Power Control DBUS Write Data, Rx A1 pulse., - Bits[15:14]:
 *    reserved, - Bit[13]: BLE MI estimation enable, - Bit[11]: Rx link BDR/EDR packet type, - Bit[10]: Rx
 *    channel estimation using noise floor, - Bits[9:8]: indicate which syncword correlator to use,
 *    - Bits[7:4]: Rx link index from 0 to 9, - Bits[1:0]: Rx power mode (when low power scan mode
 *    is normal mode; selects from either normal or performance mode), ,Enum, - Bit[12]: BLE Rx data
 *    rate, 0x0: 1 Mbps (also for BTC; ANT), 0x1: 2 Mbps, ,Enum, - Bits[2]: BLE channel assessment
 *    mode, 0x0: Single channel, 0x1: V_1, Multiple channels (ch; ch+1; ch+2 ... ch+9)
 */
#define BTU2_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_rif_dbus_rx_pwrctl_wdata(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_rif_dbus_rx_pwrctl_wdata_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_RX_PWRCTL_WDATA_rif_dbus_rx_pwrctl_wdata_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RX_FSYN_WDATA - Rx Fsyn DBUS Write Data */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_rif_dbus_rx_fsyn_wdata_MASK (0xFFFFU)
#define BTU2_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_rif_dbus_rx_fsyn_wdata_SHIFT (0U)
/*! rif_dbus_rx_fsyn_wdata - Rx Fsyn DBUS Write Data, Rx A2 pulse., - Bits[15:13]: Bluetooth mode -
 *    BTC; BLE; NIKE; ANT or LLR, - Bit[12]: Rx notch filter enable, - Bit[11]: reserved, - Bit[10]:
 *    power up BRF BG/CPREG, - Bits[9:8]: Bluetooth state - Tx; Rx, - Bit[7]: large correlation
 *    window indicator, - Bit[6:0]: Bluetooth channel from 0 to 78
 */
#define BTU2_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_rif_dbus_rx_fsyn_wdata(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_rif_dbus_rx_fsyn_wdata_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_RX_FSYN_WDATA_rif_dbus_rx_fsyn_wdata_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_RX_SYNC_DELAY - BLE Rx Sync Delay */
/*! @{ */

#define BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_syncpulse_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_syncpulse_delay_SHIFT (0U)
/*! ble_rx_syncpulse_delay - The BLE packet PDU sync pulse max delay from correlation hit pulse.
 *    Watchdog timer value for sync pulse from BRF at the start of PDU. Hardware will automatically
 *    abort Rx operation upon expiration of the watchdog timer. Res: 1 usec.
 */
#define BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_syncpulse_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_syncpulse_delay_SHIFT)) & BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_syncpulse_delay_MASK)

#define BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_datavld_delay_MASK (0xFF00U)
#define BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_datavld_delay_SHIFT (8U)
/*! ble_rx_datavld_delay - In Rx bursting mode; the BLE packet PDU bursting data valid max delay
 *    from last end of data valid or sync pulse. Watchdog timer value for sync pulse from BRF at the
 *    start of PDU. Hardware will automatically abort Rx operation upon expiration of the watchdog
 *    timer. Res: 1 usec.
 */
#define BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_datavld_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_datavld_delay_SHIFT)) & BTU2_BTU_RIF_BLE_RX_SYNC_DELAY_ble_rx_datavld_delay_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_PKT_STATUS - RIF dBus Rx Packet Status */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_ble_tx_pwr_adjd_MASK (0x1U)
#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_ble_tx_pwr_adjd_SHIFT (0U)
/*! ble_tx_pwr_adjd - BLE Tx power adjusted status, This bit indicates that BLE TX power was
 *    adjusted by BCA feedback. This bit is cleared on read. It is valid shortly after BCA grant is
 *    received; for each BLE TX packet.
 */
#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_ble_tx_pwr_adjd(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_ble_tx_pwr_adjd_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_ble_tx_pwr_adjd_MASK)

#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_rf_bt_test_mode_en_MASK (0x8U)
#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_rf_bt_test_mode_en_SHIFT (3U)
/*! rf_bt_test_mode_en - Enable BRF Bluetooth Test Mode */
#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_rf_bt_test_mode_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_rf_bt_test_mode_en_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_rf_bt_test_mode_en_MASK)

#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_bfdbk_tx_power_4m_ble_rdbk_MASK (0xFC00U)
#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_bfdbk_tx_power_4m_ble_rdbk_SHIFT (10U)
/*! bfdbk_tx_power_4m_ble_rdbk - BCA Feedback power for BLE packet, Feedback power value received
 *    from BCA for BLE TX packet. This value is overwritten when new BLE power level override is
 *    feedback from BCA.
 */
#define BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_bfdbk_tx_power_4m_ble_rdbk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_bfdbk_tx_power_4m_ble_rdbk_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_PKT_STATUS_bfdbk_tx_power_4m_ble_rdbk_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_RX_MODETYPE - RIF dBus Rx Mode Type */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_RX_MODETYPE_rf_rx_mode_type_resrv_MASK (0xFCU)
#define BTU2_BTU_RIF_DBUS_RX_MODETYPE_rf_rx_mode_type_resrv_SHIFT (2U)
/*! rf_rx_mode_type_resrv - reserved register */
#define BTU2_BTU_RIF_DBUS_RX_MODETYPE_rf_rx_mode_type_resrv(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_RX_MODETYPE_rf_rx_mode_type_resrv_SHIFT)) & BTU2_BTU_RIF_DBUS_RX_MODETYPE_rf_rx_mode_type_resrv_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_RX_CTE_LEN_ADDR - RIF Register */
/*! @{ */

#define BTU2_BTU_RIF_BRF_RX_CTE_LEN_ADDR_rx_cte_len_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_RX_CTE_LEN_ADDR_rx_cte_len_addr_SHIFT (0U)
/*! rx_cte_len_addr - Radio Register Address for Rx CTE Length, The BRF register of the expected Rx CTE length., - Units: 8 micro-seconds. */
#define BTU2_BTU_RIF_BRF_RX_CTE_LEN_ADDR_rx_cte_len_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_RX_CTE_LEN_ADDR_rx_cte_len_addr_SHIFT)) & BTU2_BTU_RIF_BRF_RX_CTE_LEN_ADDR_rx_cte_len_addr_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_BLE_START_TIME_CODED - RIF ARB BLE Start Time, Delay till sampled bt_grant_n is sampled. */
/*! @{ */

#define BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_tx_start_time_MASK (0xFFU)
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_tx_start_time_SHIFT (0U)
/*! ble_tx_start_time - Delay when bt_grant_n is sampled and rif_tx_req will start after
 *    start_rif_tx (Tx Request from BLE to RIF-ARB for radio access) is issued from BLE., - Resolution: 1/4 us.
 */
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_tx_start_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_tx_start_time_SHIFT)) & BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_tx_start_time_MASK)

#define BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_rx_start_time_MASK (0xFF00U)
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_rx_start_time_SHIFT (8U)
/*! ble_rx_start_time - Delay when bt_grant_n is sampled and rif_rx_req will start after
 *    start_rif_rx (Rx request from BLE to RIF-ARB for Radio access) is issued., - Resolution : 1/4 us.
 */
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_rx_start_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_rx_start_time_SHIFT)) & BTU2_BTU_RIF_ARB_BLE_START_TIME_CODED_ble_rx_start_time_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_BLE_START_TIME_1M - RIF ARB BLE Start Time, Delay till sampled bt_grant_n is sampled. */
/*! @{ */

#define BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_tx_start_time_MASK (0xFFU)
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_tx_start_time_SHIFT (0U)
/*! ble_tx_start_time - Delay when bt_grant_n is sampled and rif_tx_req will start after
 *    start_rif_tx (Tx Request from BLE to RIF-ARB for radio access) is issued from BLE., - Resolution: 1/4 us.
 */
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_tx_start_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_tx_start_time_SHIFT)) & BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_tx_start_time_MASK)

#define BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_rx_start_time_MASK (0xFF00U)
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_rx_start_time_SHIFT (8U)
/*! ble_rx_start_time - Delay when bt_grant_n is sampled and rif_rx_req will start after
 *    start_rif_rx (Rx request from BLE to RIF-ARB for Radio access) is issued., - Resolution : 1/4 us.
 */
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_rx_start_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_rx_start_time_SHIFT)) & BTU2_BTU_RIF_ARB_BLE_START_TIME_1M_ble_rx_start_time_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_BLE_START_TIME_2M - RIF ARB BLE Start Time, Delay till sampled bt_grant_n is sampled. */
/*! @{ */

#define BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_tx_start_time_MASK (0xFFU)
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_tx_start_time_SHIFT (0U)
/*! ble_tx_start_time - Delay when bt_grant_n is sampled and rif_tx_req will start after
 *    start_rif_tx (Tx Request from BLE to RIF-ARB for radio access) is issued from BLE., - Resolution: 1/4 us.
 */
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_tx_start_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_tx_start_time_SHIFT)) & BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_tx_start_time_MASK)

#define BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_rx_start_time_MASK (0xFF00U)
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_rx_start_time_SHIFT (8U)
/*! ble_rx_start_time - Delay when bt_grant_n is sampled and rif_rx_req will start after
 *    start_rif_rx (Rx request from BLE to RIF-ARB for Radio access) is issued., - Resolution : 1/4 us.
 */
#define BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_rx_start_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_rx_start_time_SHIFT)) & BTU2_BTU_RIF_ARB_BLE_START_TIME_2M_ble_rx_start_time_MASK)
/*! @} */

/*! @name BTU_RIF_ARB_CTL - RIF ARB Control */
/*! @{ */

#define BTU2_BTU_RIF_ARB_CTL_ble_sw_abort_MASK   (0x2U)
#define BTU2_BTU_RIF_ARB_CTL_ble_sw_abort_SHIFT  (1U)
/*! ble_sw_abort - If set; current BLE traffic will be aborted and ble_sw_abort_intr will be
 *    issued., This bit cleared by hardware; after ble_sw_abort_intr is issued., If there is no ongoing BLE
 *    traffic; then there is no abort happening. But ble_sw_abort_intr will be issued anyway. It is
 *    software requirement to issue ble_sw_abort_intr weather there was ongoing BLE traffic got
 *    aborted or not.
 */
#define BTU2_BTU_RIF_ARB_CTL_ble_sw_abort(x)     (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_CTL_ble_sw_abort_SHIFT)) & BTU2_BTU_RIF_ARB_CTL_ble_sw_abort_MASK)

#define BTU2_BTU_RIF_ARB_CTL_rst_rif_arb_fsm_MASK (0x8U)
#define BTU2_BTU_RIF_ARB_CTL_rst_rif_arb_fsm_SHIFT (3U)
/*! rst_rif_arb_fsm - RIF-ARB Reset, If set; RIF-ARB fsm will reset and transition to idle state.
 *    Firmware first writes 1 and then writes 0 to this bit.
 */
#define BTU2_BTU_RIF_ARB_CTL_rst_rif_arb_fsm(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_CTL_rst_rif_arb_fsm_SHIFT)) & BTU2_BTU_RIF_ARB_CTL_rst_rif_arb_fsm_MASK)

#define BTU2_BTU_RIF_ARB_CTL_ble_sync_frame_en_MASK (0x200U)
#define BTU2_BTU_RIF_ARB_CTL_ble_sync_frame_en_SHIFT (9U)
/*! ble_sync_frame_en - Enable ble_sync_frame in arbitration decision, Enable considering
 *    ble_sync_frame in arbitration decision, 0x0: disable, 0x1: enable
 */
#define BTU2_BTU_RIF_ARB_CTL_ble_sync_frame_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_CTL_ble_sync_frame_en_SHIFT)) & BTU2_BTU_RIF_ARB_CTL_ble_sync_frame_en_MASK)

#define BTU2_BTU_RIF_ARB_CTL_rif_collide_MASK    (0x400U)
#define BTU2_BTU_RIF_ARB_CTL_rif_collide_SHIFT   (10U)
/*! rif_collide - KW47 Deadlock condition detection; with interrupt generation on ble_cutoff, This
 *    bit is set if there is a rising edge on rif_tx or rx during an on-going transaction. This bit
 *    gets cleared with a WtiteOne
 */
#define BTU2_BTU_RIF_ARB_CTL_rif_collide(x)      (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ARB_CTL_rif_collide_SHIFT)) & BTU2_BTU_RIF_ARB_CTL_rif_collide_MASK)
/*! @} */

/*! @name BTU_RIF_CCA_GRANT_OFFSET_TIME - BTU CCA GRANT OFFSET TIME, BTU CCA Grant Offset Time */
/*! @{ */

#define BTU2_BTU_RIF_CCA_GRANT_OFFSET_TIME_ble_cca_grant_offset_time_MASK (0xFF00U)
#define BTU2_BTU_RIF_CCA_GRANT_OFFSET_TIME_ble_cca_grant_offset_time_SHIFT (8U)
/*! ble_cca_grant_offset_time - BLE CCA Grant Offset time, Offset to the delay when bt_grant_n is
 *    sampled and rif_tx_start will start after rifTx (Tx request from BLE to RIF-ARB for radio
 *    access) is issued from BLE. This offset is only used in TX packets; and when ble_tx_cca_en is also
 *    set to 1., - Resolution: 0.25us
 */
#define BTU2_BTU_RIF_CCA_GRANT_OFFSET_TIME_ble_cca_grant_offset_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CCA_GRANT_OFFSET_TIME_ble_cca_grant_offset_time_SHIFT)) & BTU2_BTU_RIF_CCA_GRANT_OFFSET_TIME_ble_cca_grant_offset_time_MASK)
/*! @} */

/*! @name BTU_RIF_CCA_TX_FESW_OFFSET_TIME - BTU CCA TX FESW OFFSET TIME, BTU CCA TX FESW Offset Time */
/*! @{ */

#define BTU2_BTU_RIF_CCA_TX_FESW_OFFSET_TIME_ble_cca_tx_fesw_offset_time_MASK (0xFF00U)
#define BTU2_BTU_RIF_CCA_TX_FESW_OFFSET_TIME_ble_cca_tx_fesw_offset_time_SHIFT (8U)
/*! ble_cca_tx_fesw_offset_time - BLE CCA TX FESW Offset time, Offset to the delay assertion of
 *    bttx_fesw in CCA mode to curb during CCA (RX) operation is ongoing. This offset is added on to
 *    tx_fesw_on_delay. This offset is only used in BLE TX packets; and when ble_tx_cca_en is also set
 *    to 1., - Resolution: 1us
 */
#define BTU2_BTU_RIF_CCA_TX_FESW_OFFSET_TIME_ble_cca_tx_fesw_offset_time(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CCA_TX_FESW_OFFSET_TIME_ble_cca_tx_fesw_offset_time_SHIFT)) & BTU2_BTU_RIF_CCA_TX_FESW_OFFSET_TIME_ble_cca_tx_fesw_offset_time_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_SEL_0 - RIF Testbus Select 0 */
/*! @{ */

#define BTU2_BTU_RIF_TESTBUS_SEL_0_btu_testbus_sel_0_MASK (0xFFFFU)
#define BTU2_BTU_RIF_TESTBUS_SEL_0_btu_testbus_sel_0_SHIFT (0U)
/*! btu_testbus_sel_0 - RIF Testbus Select; Lower Bits, Lower 15 bits of btu_testbus_sel; if,
 *    (btu_testbus_sel[i*2];btu_testbus_sel[i*2+1]) set to:, 0x0: get btc_testbus_out[i], 0x1: get
 *    ble_testbus_out[i], 0x2: get ble_debug_sw_msg_out(URAT), 0x3: get ble_test_sw_out[i]
 */
#define BTU2_BTU_RIF_TESTBUS_SEL_0_btu_testbus_sel_0(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TESTBUS_SEL_0_btu_testbus_sel_0_SHIFT)) & BTU2_BTU_RIF_TESTBUS_SEL_0_btu_testbus_sel_0_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_SEL_1 - RIF Testbus Select 1 */
/*! @{ */

#define BTU2_BTU_RIF_TESTBUS_SEL_1_btu_testbus_sel_1_MASK (0xFFFFU)
#define BTU2_BTU_RIF_TESTBUS_SEL_1_btu_testbus_sel_1_SHIFT (0U)
/*! btu_testbus_sel_1 - RIF Testbus Select; Upper Bits, Upper 15 bits of btu_testbus_sel; if,
 *    (btu_testbus_sel[i*2];btu_testbus_sel[i*2+1]) set to:, 0x0: get btc_testbus_out[i], 0x1: get
 *    ble_testbus_out[i], 0x2: get ble_debug_sw_msg_out(URAT), 0x3: get ble_test_sw_out[i]
 */
#define BTU2_BTU_RIF_TESTBUS_SEL_1_btu_testbus_sel_1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TESTBUS_SEL_1_btu_testbus_sel_1_SHIFT)) & BTU2_BTU_RIF_TESTBUS_SEL_1_btu_testbus_sel_1_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_OE - BTU Testbus Output Enable */
/*! @{ */

#define BTU2_BTU_RIF_TESTBUS_OE_btu_testbus_oe__MASK (0xFFFFU)
#define BTU2_BTU_RIF_TESTBUS_OE_btu_testbus_oe__SHIFT (0U)
/*! btu_testbus_oe_ - Debug testbus output enable, Active low BTU testbus output enables. */
#define BTU2_BTU_RIF_TESTBUS_OE_btu_testbus_oe_(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TESTBUS_OE_btu_testbus_oe__SHIFT)) & BTU2_BTU_RIF_TESTBUS_OE_btu_testbus_oe__MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_SW_OUTDATA - BLE Debug Output Data */
/*! @{ */

#define BTU2_BTU_RIF_REG_DEBUG_SW_OUTDATA_testbus_sw_out_MASK (0xFFFFU)
#define BTU2_BTU_RIF_REG_DEBUG_SW_OUTDATA_testbus_sw_out_SHIFT (0U)
/*! testbus_sw_out - BLE debug software control testbus ouput, Only when
 *    btu_testbus_overrdie_by_ble_sw = 1; this software testbus is the BLE testbus output.
 */
#define BTU2_BTU_RIF_REG_DEBUG_SW_OUTDATA_testbus_sw_out(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_REG_DEBUG_SW_OUTDATA_testbus_sw_out_SHIFT)) & BTU2_BTU_RIF_REG_DEBUG_SW_OUTDATA_testbus_sw_out_MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_INDATA - BLE Debug Input Data */
/*! @{ */

#define BTU2_BTU_RIF_REG_DEBUG_INDATA_testbus_in_MASK (0xFFFFU)
#define BTU2_BTU_RIF_REG_DEBUG_INDATA_testbus_in_SHIFT (0U)
/*! testbus_in - BLE debug testbus input */
#define BTU2_BTU_RIF_REG_DEBUG_INDATA_testbus_in(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_REG_DEBUG_INDATA_testbus_in_SHIFT)) & BTU2_BTU_RIF_REG_DEBUG_INDATA_testbus_in_MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_SW_MSG - BLE Debug Software Message */
/*! @{ */

#define BTU2_BTU_RIF_REG_DEBUG_SW_MSG_debug_sw_msg_MASK (0xFFFFU)
#define BTU2_BTU_RIF_REG_DEBUG_SW_MSG_debug_sw_msg_SHIFT (0U)
/*! debug_sw_msg - Debug message, Software message is written into this register and transfered into FIFO. */
#define BTU2_BTU_RIF_REG_DEBUG_SW_MSG_debug_sw_msg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_REG_DEBUG_SW_MSG_debug_sw_msg_SHIFT)) & BTU2_BTU_RIF_REG_DEBUG_SW_MSG_debug_sw_msg_MASK)
/*! @} */

/*! @name BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT - BLE Debug Software Message FIFO Count */
/*! @{ */

#define BTU2_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_ble_reg_debug_sw_msg_fifo_cnt_MASK (0xFFU)
#define BTU2_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_ble_reg_debug_sw_msg_fifo_cnt_SHIFT (0U)
/*! ble_reg_debug_sw_msg_fifo_cnt - Debug message FIFO count */
#define BTU2_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_ble_reg_debug_sw_msg_fifo_cnt(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_ble_reg_debug_sw_msg_fifo_cnt_SHIFT)) & BTU2_BTU_RIF_REG_DEBUG_SW_MSG_FIFO_CNT_ble_reg_debug_sw_msg_fifo_cnt_MASK)
/*! @} */

/*! @name BTU_RIF_TESTBUS_CONTROL - RIF Testbus Control */
/*! @{ */

#define BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_control_MASK (0xFU)
#define BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_control_SHIFT (0U)
/*! btu_rif_testbus_control - Testbus bank rotation */
#define BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_control(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_control_SHIFT)) & BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_control_MASK)

#define BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_en_MASK (0x8000U)
#define BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_en_SHIFT (15U)
/*! btu_rif_testbus_en - Enable debug mode to use BTU testbus */
#define BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_en_SHIFT)) & BTU2_BTU_RIF_TESTBUS_CONTROL_btu_rif_testbus_en_MASK)
/*! @} */

/*! @name BTU_RIF_BT_CLK_GATING - RIF Bluetooth Clock Gating */
/*! @{ */

#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_clk_en_MASK (0x2U)
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_clk_en_SHIFT (1U)
/*! bt_reg_aes_clk_en - AES Clock Enable, If set; Force bt_aes_clk to turn on., Otherwise; bt_aes_clk_en controls bt_aes_clk gating. */
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_clk_en_SHIFT)) & BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_clk_en_MASK)

#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_4m_clk_en_MASK (0x4U)
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_4m_clk_en_SHIFT (2U)
/*! bt_reg_rif_rx_4m_clk_en - RIF Rx 4M Clock Enable, 0x0: rif_rx_4m_clk_en controls clock gating, 0x1: forces rif_rx_4m_clk to turn on */
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_4m_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_4m_clk_en_SHIFT)) & BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_4m_clk_en_MASK)

#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_16m_clk_en_MASK (0x8U)
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_16m_clk_en_SHIFT (3U)
/*! bt_reg_rif_rx_16m_clk_en - RIF Rx 16M Clock Enable, 0x0: rif_rx_16m_clk_en controls clock gating
 *    for rif_rx_16m_clk, 0x1: forces rif_rx_16m_clk to turn on
 */
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_16m_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_16m_clk_en_SHIFT)) & BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_rif_rx_16m_clk_en_MASK)

#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_force_ebram_sysclk_en_MASK (0x40U)
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_force_ebram_sysclk_en_SHIFT (6U)
/*! bt_reg_force_ebram_sysclk_en - Force EBRAM ebSysClk enable, When set; ebSysClk to EBRAM is always ON; it is not gated. */
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_force_ebram_sysclk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_force_ebram_sysclk_en_SHIFT)) & BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_force_ebram_sysclk_en_MASK)

#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_sys_clk_en_MASK (0x80U)
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_sys_clk_en_SHIFT (7U)
/*! bt_reg_aes_sys_clk_en - Force aes sys clk enable, When set; sys clk to hw aes arbiter is always ON; it is not gated. */
#define BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BT_CLK_GATING_bt_reg_aes_sys_clk_en_MASK)
/*! @} */

/*! @name BTU_RIF_CLK_SMPLD - RIF Clock Sampled, Mux select for Sampled generation logic. */
/*! @{ */

#define BTU2_BTU_RIF_CLK_SMPLD_btu_4m_smpld_mux_MASK (0x1U)
#define BTU2_BTU_RIF_CLK_SMPLD_btu_4m_smpld_mux_SHIFT (0U)
/*! btu_4m_smpld_mux - 4M Sampled MUX, Mux select to select the sync method., First method does not
 *    require the clocks to be in phase., Second wethod requires cloks to be in phase
 *    (synchronization between 4 MHz clock and ebSysClkIn)., If this bit is set to 1; it uses first method., This
 *    signal is used for both BTC and BLE.
 */
#define BTU2_BTU_RIF_CLK_SMPLD_btu_4m_smpld_mux(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CLK_SMPLD_btu_4m_smpld_mux_SHIFT)) & BTU2_BTU_RIF_CLK_SMPLD_btu_4m_smpld_mux_MASK)

#define BTU2_BTU_RIF_CLK_SMPLD_rif_rx_4m_smpld_mux_MASK (0x2U)
#define BTU2_BTU_RIF_CLK_SMPLD_rif_rx_4m_smpld_mux_SHIFT (1U)
/*! rif_rx_4m_smpld_mux - RIF Rx 4M Sampled MUX, Mux select to select sync methods., First method
 *    does not require clocks to be in phase., Second method requires clocks to be in phase (Used in
 *    synchronization between 16 MHz and 4 MHz clock. Used for sampling Gen4 data.), If set to 1;
 *    select first method.
 */
#define BTU2_BTU_RIF_CLK_SMPLD_rif_rx_4m_smpld_mux(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CLK_SMPLD_rif_rx_4m_smpld_mux_SHIFT)) & BTU2_BTU_RIF_CLK_SMPLD_rif_rx_4m_smpld_mux_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CLK_GATING - RIF BLE Clock Gating, Clock Enable register for BLE Clocks. */
/*! @{ */

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_sleep_clk_en_MASK (0x1U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_sleep_clk_en_SHIFT (0U)
/*! bt_reg_ble_sleep_clk_en - BLE Sleep Clock Enable, If set; forces ble_sleep_clk to turn on. */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_sleep_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_sleep_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_sleep_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_force_clk_en_MASK (0x2U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_force_clk_en_SHIFT (1U)
/*! bt_reg_ble_force_clk_en - BLE Force Clock Enable, If set; forces all BLE internal clocks to turn on. */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_force_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_force_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_force_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_slv_hclk_en_MASK (0x4U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_slv_hclk_en_SHIFT (2U)
/*! bt_reg_ble_slv_hclk_en - BLE Slave HCLK Enable, 0x0: ble_slv_hclk_en controls clock gating dynamically, 0x1: forces ble_sys_td_clk_en to turn on */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_slv_hclk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_slv_hclk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_slv_hclk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_mst_hclk_en_MASK (0x8U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_mst_hclk_en_SHIFT (3U)
/*! bt_reg_ble_mst_hclk_en - BLE Master HCLK Enable, 0x0: ble_mst_hclk_en controls clock gating, 0x1: forces ble_mst_hclk to 1 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_mst_hclk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_mst_hclk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_mst_hclk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_ric_sys_clk_en_MASK (0x10U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_ric_sys_clk_en_SHIFT (4U)
/*! bt_reg_ble_ric_sys_clk_en - BLE RIC System Clock Enable, 0x0: ble_ric_sys_clk_en controls
 *    dynamic clock gating, 0x1: force ble_ric_sys_clk to turn on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_ric_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_ric_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_ric_sys_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tx_clk_en_MASK (0x20U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tx_clk_en_SHIFT (5U)
/*! bt_reg_ble_tx_clk_en - BLE Tx Clock Enable, 0x0: ble_tx_clk_en controls clock gating for
 *    ble_tx_clk, 0x1: forces ble_tx_clk; also forces ble_td_sys_clk_en to be set
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tx_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tx_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tx_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rx_clk_en_MASK (0x40U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rx_clk_en_SHIFT (6U)
/*! bt_reg_ble_rx_clk_en - BLE Rx Clock Enable, 0x0: ble_rx_clk controls clock gating dynamically,
 *    0x1: forces ble_rx_clk clocks to turn on; also forces ble_rd_sys_clk to turn on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rx_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rx_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rx_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_td_sys_clk_en_MASK (0x80U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_td_sys_clk_en_SHIFT (7U)
/*! bt_reg_ble_td_sys_clk_en - BLE TD System Clock Enable, 0x0: ble_td_sys_clk_en controls clock
 *    gating dynamically, 0x1: forces ble_td_sys_clk to turn on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_td_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_td_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_td_sys_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rd_sys_clk_en_MASK (0x100U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rd_sys_clk_en_SHIFT (8U)
/*! bt_reg_ble_rd_sys_clk_en - BLE RD System Clock Enable, 0x0: ble_rd_sys_clk_en controls dynamic clock gating, 0x1: forces ble_rd_sys_clk to turn on */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rd_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rd_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rd_sys_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rl_sys_clk_en_MASK (0x200U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rl_sys_clk_en_SHIFT (9U)
/*! bt_reg_ble_rl_sys_clk_en - BLE RD System Clock Enable, 0x0: ble_rl_sys_clk_en controls dynamic
 *    clock gating, 0x1: forces forces ble_rl_sys_clk to turn on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rl_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rl_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_rl_sys_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_wl_sys_clk_en_MASK (0x400U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_wl_sys_clk_en_SHIFT (10U)
/*! bt_reg_ble_wl_sys_clk_en - BLE Whitelist Search System Clock Enable, 0x0: ble_wl_sys_clk_en
 *    controls dynamic clock gating, 0x1: forces ble_wl_sys_clk to turn on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_wl_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_wl_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_wl_sys_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_irk_sys_clk_en_MASK (0x800U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_irk_sys_clk_en_SHIFT (11U)
/*! bt_reg_ble_irk_sys_clk_en - BLE IRK resolve System Clock Enable, 0x0: ble_irk_sys_clk_en
 *    controls dynamic clock gating, 0x1: forces ble_irk_sys_clk to turn on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_irk_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_irk_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_irk_sys_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrs_clk_en_MASK (0x1000U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrs_clk_en_SHIFT (12U)
/*! bt_reg_ble_tmrs_clk_en - BLE cdt and pst timers clock enable, 0x0: ble_tmr_4m_clk_en controls
 *    dynamic clock gating, 0x1: forces ble_tmr_4m_clk_en to turn on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrs_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrs_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrs_clk_en_MASK)

#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrreg_sys_clk_en_MASK (0x2000U)
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrreg_sys_clk_en_SHIFT (13U)
/*! bt_reg_ble_tmrreg_sys_clk_en - BLE timer registers clock enable, 0x0: BTU controls dynamic
 *    sysclk gating on SWT; CDT and PST registers, 0x1: forces SWT; CDT and PST registers sysclk to turn
 *    on
 */
#define BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrreg_sys_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrreg_sys_clk_en_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_GATING_bt_reg_ble_tmrreg_sys_clk_en_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CLK_CTRL - RIF BLE Clock Control, Register for Clock Control Logic */
/*! @{ */

#define BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_zero_MASK (0x1U)
#define BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_zero_SHIFT (0U)
/*! bt_reg_force_ble_clk_req_zero - Force BLE Clock Req Zero, ble_sp_req is set to put BLE to sleep.
 *    When a write (1 or 0) to this register is detected; BLE will set ble_clk_req to 0 and go to
 *    sleep. This will gate off all BLE clocks.
 */
#define BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_zero(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_zero_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_zero_MASK)

#define BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_one_MASK (0x2U)
#define BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_one_SHIFT (1U)
/*! bt_reg_force_ble_clk_req_one - Force BLE Clock Req One, When set; ble_clk_req will always be forced to 1. */
#define BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_one(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_one_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_CTRL_bt_reg_force_ble_clk_req_one_MASK)

#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_awake_sts_MASK (0x10U)
#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_awake_sts_SHIFT (4U)
/*! ble_awake_sts - BLE Awake Status, This bit indicates if BLE is in sleep or awake. */
#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_awake_sts(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_CTRL_ble_awake_sts_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_CTRL_ble_awake_sts_MASK)

#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_clk_req_early_assert_MASK (0x100U)
#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_clk_req_early_assert_SHIFT (8U)
/*! ble_clk_req_early_assert - ble_clk_req early assertion upon any BLE AHB access, Setting this bit
 *    will enable ble_clk_req early assertion upon any BLE AHB access; which allows bt_clk_req to
 *    be asserted earlier to APU.
 */
#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_clk_req_early_assert(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_CTRL_ble_clk_req_early_assert_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_CTRL_ble_clk_req_early_assert_MASK)

#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_sys_4m_early_ungate_MASK (0x200U)
#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_sys_4m_early_ungate_SHIFT (9U)
/*! ble_sys_4m_early_ungate - ble_sys_clk and ble_4m_clk early ungated upon any BLE AHB access,
 *    Setting this bit will allow ble_sys_clk and ble_4m_clk being ungated earlier upon any BLE AHB
 *    access during BLE sleep for faster BLE register access.
 */
#define BTU2_BTU_RIF_BLE_CLK_CTRL_ble_sys_4m_early_ungate(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CLK_CTRL_ble_sys_4m_early_ungate_SHIFT)) & BTU2_BTU_RIF_BLE_CLK_CTRL_ble_sys_4m_early_ungate_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_PKT_END - BLE RIF dBus Tx Packet End Control */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_SHIFT (0U)
/*! dbus_tx_pkt_end_delay - dBus Tx Packet End Delay, Time from the end of active Tx payload to dBus
 *    command that sets the radio back to IDLE., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_BLE_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_TX_PKT_END_dbus_tx_pkt_end_delay_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RX_PKT_END - BLE RIF dBus Rx Packet End Control */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_SHIFT (0U)
/*! dbus_rx_pkt_end_delay - dBus Rx Packet End Delay, Time from the end of active Rx payload to dBus
 *    command that sets the radio back to IDLE., - Resolution: 0.25 us.
 */
#define BTU2_BTU_RIF_BLE_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_RX_PKT_END_dbus_rx_pkt_end_delay_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_TX_RAMPDOWN - BLE RIF dBus Tx Rampdown Control */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_SHIFT (0U)
/*! dbus_tx_rampdown_delay - dBus Tx Rampdown Delay, Delay time after the end of a Tx slot for
 *    ramping down the radio over the dBus., Resolution 0.25 us.
 */
#define BTU2_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_TX_RAMPDOWN_dbus_tx_rampdown_delay_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_DBUS_RSSI - BLE RIF dBus RSSI */
/*! @{ */

#define BTU2_BTU_RIF_BLE_DBUS_RSSI_dbus_rssi_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_DBUS_RSSI_dbus_rssi_delay_SHIFT (0U)
/*! dbus_rssi_delay - Delay from RSSI trigger to start of RSSI read, Delay from the end of
 *    rif_rx_req to enable dBus RSSI read back., Resolution 0.25 us.
 */
#define BTU2_BTU_RIF_BLE_DBUS_RSSI_dbus_rssi_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_DBUS_RSSI_dbus_rssi_delay_SHIFT)) & BTU2_BTU_RIF_BLE_DBUS_RSSI_dbus_rssi_delay_MASK)
/*! @} */

/*! @name BTU_RIF_ADAPTIVITY_CTRL - BT Adaptivity Control, Register for BT Adaptivity Control */
/*! @{ */

#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_dis_MASK (0x1U)
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_dis_SHIFT (0U)
/*! ble_cca_dis - BLE CCA disable bit, FW override to disable CCA for current BLE Tx pkt. - Revert
 *    to normal Tx timing; clear A1 cca_before_tx_en bit; ignore brf_bt_cca_tx_drop; and no R2 DBUS.
 *    FW should set this bit before start_rif_tx time; and clear this bit before the next TX
 *    packet's start_rif_tx time.
 */
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_dis(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_dis_SHIFT)) & BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_dis_MASK)

#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_cca_ed_factor_MASK (0xF0U)
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_cca_ed_factor_SHIFT (4U)
/*! cca_ed_factor - Forgetfactor for CCA NF linear mean averaging, Controls how many previous NF
 *    readings in the same channel are considered for NF linear mean averaging
 */
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_cca_ed_factor(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ADAPTIVITY_CTRL_cca_ed_factor_SHIFT)) & BTU2_BTU_RIF_ADAPTIVITY_CTRL_cca_ed_factor_MASK)

#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_rst_dyn_MASK (0x100U)
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_rst_dyn_SHIFT (8U)
/*! ble_cca_ebram_rst_dyn - Reset bit for BLE CCA abort counters, Reset all BLE CCA abort counters in EBRAM. This bit is self clearing. */
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_rst_dyn(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_rst_dyn_SHIFT)) & BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_rst_dyn_MASK)

#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_stat_en_MASK (0x400U)
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_stat_en_SHIFT (10U)
/*! ble_cca_ebram_stat_en - Enable bit for BLE CCA EBRAM STATISTICS, Enable BLE CCA abort counters and NF averaging in EBRAM. */
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_stat_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_stat_en_SHIFT)) & BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_cca_ebram_stat_en_MASK)

#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_nf_en_MASK (0x1000U)
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_nf_en_SHIFT (12U)
/*! ble_tx_nf_en - BLE NF during TX enable, Reading inband power in each TX channel gives the Noise
 *    Floor in that channel. This can be used for NF measurement; replacing scheduled NF measurement
 *    slots in BLE. When this bit is set; design works in NF mode. CCA is performed and NF is read
 *    back. brf_bt_cca_tx_drop indication from BRF is ignored. This bit is meant to be used together
 *    with ble_tx_cca_en bit ble_tx_cca_en = 1; ble_tx_nf_en = x:CCA is done; NF is read back; brf
 *    abort indication aborts TX (EU regulatory mode) ble_tx_cca_en = 0; ble_tx_nf_en = 1:CCA is
 *    done; NF is read back; brf abort indication ignored (Non EU countries can use this mode)
 *    ble_tx_cca_en = 0; ble_tx_nf_en = 0:CCA is not done before TX. Old behavior (legacy)
 */
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_nf_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_nf_en_SHIFT)) & BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_nf_en_MASK)

#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_cca_en_MASK (0x2000U)
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_cca_en_SHIFT (13U)
/*! ble_tx_cca_en - BLE CCA before TX enable, Global enable for BLE CCA before Tx scheme - new CA1;
 *    CA2 to BRF; bt_pll_req; brf_pu; fesw; bca_bt_grant_n new Tx timing to BCA/BRF; CCA abort
 *    handling (to BCA); new R2 DBUS; cca abort statistic in EBRAM and NF averaged in EBRAM
 */
#define BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_cca_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_cca_en_SHIFT)) & BTU2_BTU_RIF_ADAPTIVITY_CTRL_ble_tx_cca_en_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CCA_ED_READBACK - BLE ED Mag readback value, BLE ED Mag readback value */
/*! @{ */

#define BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_mag_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_mag_SHIFT (0U)
/*! ble_cca_ed_mag - BLE CCA ED Magnitude, BLE CCA ED Magnitude readback from R2 DBUS) */
#define BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_mag(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_mag_SHIFT)) & BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_mag_MASK)

#define BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_vld_MASK (0x8000U)
#define BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_vld_SHIFT (15U)
/*! ble_cca_ed_vld - BLE CCA ED valid, BLE CCA ED valid indication. If packet is aborted before R2
 *    time; the ble_cca_ed_mag may be invalid. This bit is set to 1 when ble_cca_ed_mag is valid.
 */
#define BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_vld(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_vld_SHIFT)) & BTU2_BTU_RIF_BLE_CCA_ED_READBACK_ble_cca_ed_vld_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_CCA_TX_PWRCTL - CCA TX PWRCTL Dbus, CCA TX PWRCTL Dbus */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_delay_SHIFT (0U)
/*! dbus_cca_tx_pwr_ctrl_wr_delay - CCA TX PWRCTL Dbus Delay, Delay value to position CA1 timing. Resolution 0.25us */
#define BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_delay_MASK)

#define BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_en_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_en_SHIFT (15U)
/*! dbus_cca_tx_pwr_ctrl_wr_en - CCA TX PWRCTL Dbus Enable, Enable CA1 DBUS. CA1 is performed only
 *    when this bit is set and also BT adaptivity features is enabled for the current controller (BTC
 *    or BLE)
 */
#define BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_en_SHIFT)) & BTU2_BTU_RIF_DBUS_CCA_TX_PWRCTL_dbus_cca_tx_pwr_ctrl_wr_en_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_CCA_TX_FSYN - CCA TX FSYN Dbus, CCA TX FSYN Dbus */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_delay_SHIFT (0U)
/*! dbus_cca_tx_fsyn_wr_delay - CCA TX FSYN Dbus Delay, Delay value to position CA1 timing. Resolution 0.25us */
#define BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_delay_MASK)

#define BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_en_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_en_SHIFT (15U)
/*! dbus_cca_tx_fsyn_wr_en - CCA TX FSYN Dbus Enable, Enable CA2 DBUS. CA2 is performed only when
 *    this bit is set and also BT adaptivity features is enabled for the current controller (BTC or
 *    BLE)
 */
#define BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_en_SHIFT)) & BTU2_BTU_RIF_DBUS_CCA_TX_FSYN_dbus_cca_tx_fsyn_wr_en_MASK)
/*! @} */

/*! @name BTU_RIF_DBUS_CCA_ED - CCA TX R2 Dbus, CCA TX R2 Dbus */
/*! @{ */

#define BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_delay_MASK (0x7FFU)
#define BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_delay_SHIFT (0U)
/*! dbus_cca_ed_delay - CCA TX R2 Dbus Delay, Delay value to position R2 timing. The delay is
 *    counted from the end of S pulse on BTU-BRF interface.
 */
#define BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_delay_SHIFT)) & BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_delay_MASK)

#define BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_en_MASK (0x8000U)
#define BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_en_SHIFT (15U)
/*! dbus_cca_ed_en - CCA TX R2 Dbus Enable, Enable R2 DBUS. R2 is performed only when this bit is
 *    set and also BT adaptivity features is enabled for the current controller (BTC or BLE)
 */
#define BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_en_SHIFT)) & BTU2_BTU_RIF_DBUS_CCA_ED_dbus_cca_ed_en_MASK)
/*! @} */

/*! @name BTU_RIF_BRF_CCA_ED_ADDR - BRF CCA ED Address, BRF CCA ED Address */
/*! @{ */

#define BTU2_BTU_RIF_BRF_CCA_ED_ADDR_dbus_cca_ed_addr_MASK (0x7FFU)
#define BTU2_BTU_RIF_BRF_CCA_ED_ADDR_dbus_cca_ed_addr_SHIFT (0U)
/*! dbus_cca_ed_addr - BRF CCA ED Address, BRF register address for Inband Power Readback via R2 DBUS. */
#define BTU2_BTU_RIF_BRF_CCA_ED_ADDR_dbus_cca_ed_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BRF_CCA_ED_ADDR_dbus_cca_ed_addr_SHIFT)) & BTU2_BTU_RIF_BRF_CCA_ED_ADDR_dbus_cca_ed_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BTC_CCA_CA1_2_DELAY - BTC CCA CA1 CA2 Delays, BTC CCA CA1 CA2 Delays */
/*! @{ */

#define BTU2_BTU_RIF_BTC_CCA_CA1_2_DELAY_rif_ca1_2_offset_for_abort_b4_cca_us_MASK (0x3F00U)
#define BTU2_BTU_RIF_BTC_CCA_CA1_2_DELAY_rif_ca1_2_offset_for_abort_b4_cca_us_SHIFT (8U)
/*! rif_ca1_2_offset_for_abort_b4_cca_us - CA1 CA2 offset for the case of abort before CCA TX,
 *    Additional offset to delay CA1 and CA2 when CCA pkt was after a bt rif abort or FFU bca abort. The
 *    default is to delay CA1;2 in these cases by 10us to allow BRF MCU to accept these DBUS timely.
 */
#define BTU2_BTU_RIF_BTC_CCA_CA1_2_DELAY_rif_ca1_2_offset_for_abort_b4_cca_us(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BTC_CCA_CA1_2_DELAY_rif_ca1_2_offset_for_abort_b4_cca_us_SHIFT)) & BTU2_BTU_RIF_BTC_CCA_CA1_2_DELAY_rif_ca1_2_offset_for_abort_b4_cca_us_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CCA_EBRAM_ADDR - BLE CCA EBRAM Address Offset, BLE CCA EBRAM Address Offset */
/*! @{ */

#define BTU2_BTU_RIF_BLE_CCA_EBRAM_ADDR_ble_cca_ebram_addr_MASK (0x3FFFU)
#define BTU2_BTU_RIF_BLE_CCA_EBRAM_ADDR_ble_cca_ebram_addr_SHIFT (0U)
/*! ble_cca_ebram_addr - BLE CCA EBRAM Address Offset, This register is the EBRAM offset value for BLE CCA statistics location. */
#define BTU2_BTU_RIF_BLE_CCA_EBRAM_ADDR_ble_cca_ebram_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CCA_EBRAM_ADDR_ble_cca_ebram_addr_SHIFT)) & BTU2_BTU_RIF_BLE_CCA_EBRAM_ADDR_ble_cca_ebram_addr_MASK)
/*! @} */

/*! @name BTU_RIF_BLE_CCA_THRESHOLD - BLE CCA Counter thresholds, BLE CCA Counter thresholds */
/*! @{ */

#define BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_abort_pkt_cnt_thd_MASK (0xFFU)
#define BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_abort_pkt_cnt_thd_SHIFT (0U)
/*! rif_ble_cca_abort_pkt_cnt_thd - BLE CCA abort packet count threshold, 8-bit value of threshold
 *    to be used along with EBRAM abort statistics. BTU will generate ble_cca_abort_thd_cnt_met
 *    interrupt to SW when the number of CCA aborted packets in any single channel have reached or
 *    exceeded this threshold value.
 */
#define BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_abort_pkt_cnt_thd(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_abort_pkt_cnt_thd_SHIFT)) & BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_abort_pkt_cnt_thd_MASK)

#define BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_tx_pkt_cnt_thd_MASK (0xFF00U)
#define BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_tx_pkt_cnt_thd_SHIFT (8U)
/*! rif_ble_cca_tx_pkt_cnt_thd - BLE CCA TX packet count threshold, 8-bit value of threshold to be
 *    used along with EBRAM abort statistics. BTU will generate ble_cca_tx_cnt_thd_met interrupt to
 *    SW when the number of total CCA TX packets in any single channel have reached or exceeded this
 *    threshold value.
 */
#define BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_tx_pkt_cnt_thd(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_tx_pkt_cnt_thd_SHIFT)) & BTU2_BTU_RIF_BLE_CCA_THRESHOLD_rif_ble_cca_tx_pkt_cnt_thd_MASK)
/*! @} */

/*! @name BTU_RIF_CCA_BLE_THRESHOLD_MET_STS - BLE CCA threshold met status, BLE CCA threshold met status */
/*! @{ */

#define BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_abort_cnt_thd_met_ch_MASK (0x7FU)
#define BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_abort_cnt_thd_met_ch_SHIFT (0U)
/*! rif_ble_cca_abort_cnt_thd_met_ch - BLE CCA abort count threshold met channel number, BLE channel
 *    read-back value; on which the CCA abort threshold was met; causing ble_cca_abort_thd_met
 *    interrupt to CPU
 */
#define BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_abort_cnt_thd_met_ch(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_abort_cnt_thd_met_ch_SHIFT)) & BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_abort_cnt_thd_met_ch_MASK)

#define BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_tx_cnt_thd_met_ch_MASK (0x7F00U)
#define BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_tx_cnt_thd_met_ch_SHIFT (8U)
/*! rif_ble_cca_tx_cnt_thd_met_ch - BLE CCA TX count threshold met channel number, BLE channel
 *    read-back value; on which the CCA total TX packet count threshold was met; causing
 *    ble_cca_txpkt_thd_met interrupt to CPU
 */
#define BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_tx_cnt_thd_met_ch(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_tx_cnt_thd_met_ch_SHIFT)) & BTU2_BTU_RIF_CCA_BLE_THRESHOLD_MET_STS_rif_ble_cca_tx_cnt_thd_met_ch_MASK)
/*! @} */

/*! @name BTU_RIF_CCA_BLE_RX_FESW_DELAY - BLE CCA RX FESW DELAYS, BLE CCA RX FESW DELAYS */
/*! @{ */

#define BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_on_delay_MASK (0xFFU)
#define BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_on_delay_SHIFT (0U)
/*! ble_btrx_fesw_during_cca_on_delay - BLE btrx_fesw ON delay for CCA TX packets, Number of
 *    microseconds from wakeUp to turning on btrx_fesw for CCA portion of BLE Tx packets
 */
#define BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_on_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_on_delay_SHIFT)) & BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_on_delay_MASK)

#define BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_off_delay_MASK (0xFF00U)
#define BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_off_delay_SHIFT (8U)
/*! ble_btrx_fesw_during_cca_off_delay - BLE btrx_fesw OFF delay for CCA TX packets, Number of
 *    microseconds from wakeUp to turning off btrx_fesw for CCA portion of BLE Tx packets
 */
#define BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_off_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_off_delay_SHIFT)) & BTU2_BTU_RIF_CCA_BLE_RX_FESW_DELAY_ble_btrx_fesw_during_cca_off_delay_MASK)
/*! @} */

/*! @name BTU_PTA_CTRL - PTA Control */
/*! @{ */

#define BTU2_BTU_PTA_CTRL_reg_bt_tx_pwr_gate_en_MASK (0x2U)
#define BTU2_BTU_PTA_CTRL_reg_bt_tx_pwr_gate_en_SHIFT (1U)
/*! reg_bt_tx_pwr_gate_en - BT tx power enable for BCA, BT tx power enable for BCA, 0x0: Bt tx power is disabled, 0x1: Bt tx power is enabled */
#define BTU2_BTU_PTA_CTRL_reg_bt_tx_pwr_gate_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_CTRL_reg_bt_tx_pwr_gate_en_SHIFT)) & BTU2_BTU_PTA_CTRL_reg_bt_tx_pwr_gate_en_MASK)

#define BTU2_BTU_PTA_CTRL_bt_reg_pta_rx_4m_clk_en_MASK (0x8U)
#define BTU2_BTU_PTA_CTRL_bt_reg_pta_rx_4m_clk_en_SHIFT (3U)
/*! bt_reg_pta_rx_4m_clk_en - PTA Clock Gate Enable Override, PTA Clock Gate Enable Override; if set
 *    to 1; clock gating for PTA clocks is disabled = ungated clocks.
 */
#define BTU2_BTU_PTA_CTRL_bt_reg_pta_rx_4m_clk_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_CTRL_bt_reg_pta_rx_4m_clk_en_SHIFT)) & BTU2_BTU_PTA_CTRL_bt_reg_pta_rx_4m_clk_en_MASK)

#define BTU2_BTU_PTA_CTRL_bt_grant_bypass_en_MASK (0x40U)
#define BTU2_BTU_PTA_CTRL_bt_grant_bypass_en_SHIFT (6U)
/*! bt_grant_bypass_en - BCA coex grant bypass enable, When bt_grant_bypass_en is set; BCA coex
 *    grant bca_bt_grant_n is controlled by bt_grant_bypass_val register., 0x0: disable bt_grant_n
 *    bypass, 0x1: enable bt_grant_n bypass
 */
#define BTU2_BTU_PTA_CTRL_bt_grant_bypass_en(x)  (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_CTRL_bt_grant_bypass_en_SHIFT)) & BTU2_BTU_PTA_CTRL_bt_grant_bypass_en_MASK)

#define BTU2_BTU_PTA_CTRL_bt_grant_bypass_val_MASK (0x80U)
#define BTU2_BTU_PTA_CTRL_bt_grant_bypass_val_SHIFT (7U)
/*! bt_grant_bypass_val - BCA coex grant bypass value, When bt_grant_bypass_en is set; BCA coex
 *    grant bca_bt_grant_n is controlled by this register., 0x0: set BCA coex grant bt_grant_n to zero,
 *    0x1: set BCA coex grant bt_grant_n to one
 */
#define BTU2_BTU_PTA_CTRL_bt_grant_bypass_val(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_CTRL_bt_grant_bypass_val_SHIFT)) & BTU2_BTU_PTA_CTRL_bt_grant_bypass_val_MASK)

#define BTU2_BTU_PTA_CTRL_clralltxcntrs_MASK     (0x100U)
#define BTU2_BTU_PTA_CTRL_clralltxcntrs_SHIFT    (8U)
/*! clralltxcntrs - Clear All Tx Counters, When set; all of the PTA diagnostic counters are reset to
 *    0:, - Tx_Req_Hi_Cnt, - Tx_Loss_Hi_Cnt, - Tx_Loss_Med_Cnt, - Tx_Req_Med_Cnt, - Tx_Req_Med_Hi;
 *    Cnt, - Tx_Loss_Med_Hi_Cnt, 0x0: do not clear counters, 0x1: clear counters
 */
#define BTU2_BTU_PTA_CTRL_clralltxcntrs(x)       (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_CTRL_clralltxcntrs_SHIFT)) & BTU2_BTU_PTA_CTRL_clralltxcntrs_MASK)

#define BTU2_BTU_PTA_CTRL_mrvlcoexexiten_MASK    (0x800U)
#define BTU2_BTU_PTA_CTRL_mrvlcoexexiten_SHIFT   (11U)
/*! mrvlcoexexiten - Marvell Coexistence Exit Enable, Enable the reset of the MRVL coexistence state
 *    machine if neither rifTx nor rifRx is active at frameTick such that BT_REQ will go low., 0x0:
 *    disable, 0x1: enable
 */
#define BTU2_BTU_PTA_CTRL_mrvlcoexexiten(x)      (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_CTRL_mrvlcoexexiten_SHIFT)) & BTU2_BTU_PTA_CTRL_mrvlcoexexiten_MASK)
/*! @} */

/*! @name BTU_PTA_REQ_DELAY_TIMER - PTA Bt_Req Delay Timer */
/*! @{ */

#define BTU2_BTU_PTA_REQ_DELAY_TIMER_pta_req_delay_MASK (0x3FFU)
#define BTU2_BTU_PTA_REQ_DELAY_TIMER_pta_req_delay_SHIFT (0U)
/*! pta_req_delay - PTA Request Delay, When BTU uses MRVL Coexistence mode; this controls the delay
 *    from pta_tx_req/pta_rx_req to the rising edge of the BT_REQ., This value should never be
 *    programmed more than 15us; otherwise unexpected behavior will occur; such as dropped packets due to
 *    BCA grant timeout., - Unit: 0.25 us.
 */
#define BTU2_BTU_PTA_REQ_DELAY_TIMER_pta_req_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_REQ_DELAY_TIMER_pta_req_delay_SHIFT)) & BTU2_BTU_PTA_REQ_DELAY_TIMER_pta_req_delay_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_RIF_ARB_COEX_PRI - BLE PTA Priority for BTC/BLE arbitration, BLE coex priority for BTC/BLE arbitration. */
/*! @{ */

#define BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_tx_pri_MASK (0x3U)
#define BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_tx_pri_SHIFT (0U)
/*! ble_tx_pri - BLE Coex Priority, The BLE Tx packet high/medium priority that is used to make RIF_ARB arbitration request. */
#define BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_tx_pri(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_tx_pri_SHIFT)) & BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_tx_pri_MASK)

#define BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_rx_pri_MASK (0x300U)
#define BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_rx_pri_SHIFT (8U)
/*! ble_rx_pri - BLE Coex Priority, The BLE Rx packet high/medium priority that is used to make RIF_ARB arbitration request. */
#define BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_rx_pri(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_rx_pri_SHIFT)) & BTU2_BTU_PTA_BLE_RIF_ARB_COEX_PRI_ble_rx_pri_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_BCA_COEX_PRI - BLE PTA Priority for BCA arbitration, BLE coex priority for BCA arbitration. */
/*! @{ */

#define BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_tx_pri_MASK (0x3U)
#define BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_tx_pri_SHIFT (0U)
/*! ble_tx_pri - BLE Coex Priority, The BLE Tx packet high/medium priority that is used to make BCA request. */
#define BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_tx_pri(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_tx_pri_SHIFT)) & BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_tx_pri_MASK)

#define BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_rx_pri_MASK (0x300U)
#define BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_rx_pri_SHIFT (8U)
/*! ble_rx_pri - BLE Coex Priority, The BLE Rx packet high/medium priority that is used to make BCA request. */
#define BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_rx_pri(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_rx_pri_SHIFT)) & BTU2_BTU_PTA_BLE_BCA_COEX_PRI_ble_rx_pri_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_INACTIVITY_REFCLK_0 - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_0_mwsinactmsg_refclk_MASK (0xFFFFU)
#define BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_0_mwsinactmsg_refclk_SHIFT (0U)
/*! mwsinactmsg_refclk - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt,
 *    Contains the lower 16-bit of the reference clock[27:2] when the MWS_Inact_Msg_Real_Int interrupt
 *    pulse is detected.
 */
#define BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_0_mwsinactmsg_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_0_mwsinactmsg_refclk_SHIFT)) & BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_0_mwsinactmsg_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_INACTIVITY_REFCLK_1 - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_1_mwsinactmsg_refclk_MASK (0x3FFU)
#define BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_1_mwsinactmsg_refclk_SHIFT (0U)
/*! mwsinactmsg_refclk - Bluetooth Reference Clock Snapshot on MWS_Inact_Msg_Real_Int Interrupt,
 *    Contains the upper 10-bit of the reference clock[27:2] when the MWS_Inact_Msg_Real_Int interrupt
 *    pulse is detected.
 */
#define BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_1_mwsinactmsg_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_1_mwsinactmsg_refclk_SHIFT)) & BTU2_BTU_PTA_MWS_INACTIVITY_REFCLK_1_mwsinactmsg_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_INACTIVITY_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on MWS_Inact_Msg_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_mwsinactmsg_pdbitcnt_MASK (0x1FFFU)
#define BTU2_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_mwsinactmsg_pdbitcnt_SHIFT (0U)
/*! mwsinactmsg_pdbitcnt - Bluetooth Reference pdBitCounter Snapshot on MWS_Inact_Msg_Real_Int
 *    Interrupt, Contains the reference pdBitCounter[12:0] when the MWS_Inact_Msg_Real_Int interrupt
 *    pulse is detected.
 */
#define BTU2_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_mwsinactmsg_pdbitcnt(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_mwsinactmsg_pdbitcnt_SHIFT)) & BTU2_BTU_PTA_MWS_INACTIVITY_REFPDB_CNT_mwsinactmsg_pdbitcnt_MASK)
/*! @} */

/*! @name BTU_PTA_INBAND_FREQ_SET_1 - PTA Inband Frequency Set 0, BT_FREQ is set when (BT_In_Band_Hi >= freqNr >= BT_In_Band_Lo) in MRVL Coexistence mode and BT_In_Band1_Freq_En is enabled. 2 sets of band gaps; final BT_FREQ is OR version of 2 sets. */
/*! @{ */

#define BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_lo_MASK (0xFFU)
#define BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_lo_SHIFT (0U)
/*! bt_in_band_lo - Bluetooth In Band Low, In MRVL Coexistence mode; this is the low bound of the frequency channel for BT_FREQ. */
#define BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_lo(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_lo_SHIFT)) & BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_lo_MASK)

#define BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_hi_MASK (0xFF00U)
#define BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_hi_SHIFT (8U)
/*! bt_in_band_hi - Bluetooth In Band High, In MRVL Coexistence mode; this is the high bound of the frequency channel for BT_FREQ. */
#define BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_hi(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_hi_SHIFT)) & BTU2_BTU_PTA_INBAND_FREQ_SET_1_bt_in_band_hi_MASK)
/*! @} */

/*! @name BTU_PTA_MODE_SELECT - PTA Mode Select */
/*! @{ */

#define BTU2_BTU_PTA_MODE_SELECT_bt_coex_mode_MASK (0x7U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_coex_mode_SHIFT (0U)
/*! bt_coex_mode - Bluetooth Coexistence Mode Select, 0x0: disable, 0x1: CSR mode, 0x2: MRVL mode, 0x3: SUSHI mode */
#define BTU2_BTU_PTA_MODE_SELECT_bt_coex_mode(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_coex_mode_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_coex_mode_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_bt_mws_coex_en_MASK (0x8U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_mws_coex_en_SHIFT (3U)
/*! bt_mws_coex_en - Bluetooth and MWS Coexistence Mode Enable */
#define BTU2_BTU_PTA_MODE_SELECT_bt_mws_coex_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_mws_coex_en_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_mws_coex_en_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_bt_ovlp_mode_MASK (0x10U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_ovlp_mode_SHIFT (4U)
/*! bt_ovlp_mode - Bluetooth Overlap Mode, Select bt_overlap assertion mode, 0x0: non-filtered; old design, 0x1: filtered mode */
#define BTU2_BTU_PTA_MODE_SELECT_bt_ovlp_mode(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_ovlp_mode_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_ovlp_mode_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_ovlp_supress_en_MASK (0x20U)
#define BTU2_BTU_PTA_MODE_SELECT_ovlp_supress_en_SHIFT (5U)
/*! ovlp_supress_en - Overlap Suppression Enable, Suppress BT_Overlap/BT_Scan_Overlap assertion if
 *    Tx power is less than the programmed threshold., 0x0: disable, 0x1: enable,
 *    BT_Overlap/BT_Scan_Overlap assertion to BCA will be suppressed if Tx_Power_Index, Value is less than the
 *    programmed BTU_PTA_TX_POWER_THRESHOLD for BR/EDR packet, type or is less than BTU_PTA_BLE_TX_PWR_THRHD
 *    for BLE packet.
 */
#define BTU2_BTU_PTA_MODE_SELECT_ovlp_supress_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_ovlp_supress_en_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_ovlp_supress_en_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_mode_MASK (0x40U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_mode_SHIFT (6U)
/*! bt_scan_ovlp_mode - Bluetooth Scan Overlap Mode, Select bt_scan_overlap assertion mode, 0x0: non-filtered; old design, 0x1: filtered mode */
#define BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_mode(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_mode_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_mode_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_rx_en_MASK (0x80U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_rx_en_SHIFT (7U)
/*! bt_scan_ovlp_rx_en - Scan Overlap for Bluetooth Rx, Enables bt_scan_overlap assertion for Bluetooth Rx., 0x0: disable, 0x1: enable */
#define BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_rx_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_rx_en_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_scan_ovlp_rx_en_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_bt_3dg_coex_en_MASK (0x100U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_3dg_coex_en_SHIFT (8U)
/*! bt_3dg_coex_en - Bluetooth and 3D-Glass Coexistence Mode Enable */
#define BTU2_BTU_PTA_MODE_SELECT_bt_3dg_coex_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_3dg_coex_en_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_3dg_coex_en_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_bt_in_band1_freq_en_MASK (0x200U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_in_band1_freq_en_SHIFT (9U)
/*! bt_in_band1_freq_en - BTU_PTA_INBAND_FREQ_SET_1 Band Gap Use Enable */
#define BTU2_BTU_PTA_MODE_SELECT_bt_in_band1_freq_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_in_band1_freq_en_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_in_band1_freq_en_MASK)

#define BTU2_BTU_PTA_MODE_SELECT_bt_tx_on_mode_MASK (0xC000U)
#define BTU2_BTU_PTA_MODE_SELECT_bt_tx_on_mode_SHIFT (14U)
/*! bt_tx_on_mode - BT_TX_ON mode selection, Selects the mode of operation for asserting the
 *    BT_TX_ON signal., - Bit[15]: Direct Mode: BT_TX_ON signal assertion is independent of MWS Rx and MWS
 *    scan operations, - Bit[14]: Filtered Mode: BT_TX_ON signal is asserted in real time by
 *    hardware by taking into account of MWS Rx overlap and MWS scan overlap conditions
 */
#define BTU2_BTU_PTA_MODE_SELECT_bt_tx_on_mode(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MODE_SELECT_bt_tx_on_mode_SHIFT)) & BTU2_BTU_PTA_MODE_SELECT_bt_tx_on_mode_MASK)
/*! @} */

/*! @name BTU_PTA_INBAND_FREQ_SET_0 - PTA Inband Frequency Set 1, BT_FREQ is set when (BT_In_Band_Hi >= freqNr >= BT_In_Band_Lo) in MRVL Coexistence mode. 2 sets of band gaps; final BT_FREQ is OR version of 2 sets. */
/*! @{ */

#define BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_lo_MASK (0xFFU)
#define BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_lo_SHIFT (0U)
/*! bt_in_band_lo - Bluetooth In Band Low, In MRVL Coexistence mode; this is the low bound of the frequency channel for BT_FREQ. */
#define BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_lo(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_lo_SHIFT)) & BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_lo_MASK)

#define BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_hi_MASK (0xFF00U)
#define BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_hi_SHIFT (8U)
/*! bt_in_band_hi - Bluetooth In Band High, In MRVL Coexistence mode; this is the high bound of the frequency channel for BT_FREQ. */
#define BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_hi(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_hi_SHIFT)) & BTU2_BTU_PTA_INBAND_FREQ_SET_0_bt_in_band_hi_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0 - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_harqpatternsel_refclk_MASK (0xFFFFU)
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_harqpatternsel_refclk_SHIFT (0U)
/*! harqpatternsel_refclk - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int
 *    Interrupt, Contains the lower 16-bit of the referenceClock[27:2] when the HARQ_Pattern_Sel_Real_Int
 *    interrupt pulse is detected.
 */
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_harqpatternsel_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_harqpatternsel_refclk_SHIFT)) & BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_0_harqpatternsel_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1 - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_harqpatternsel_refclk_MASK (0x3FFU)
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_harqpatternsel_refclk_SHIFT (0U)
/*! harqpatternsel_refclk - Bluetooth Reference Clock Snapshot on HARQ_Pattern_Sel_Real_Int
 *    Interrupt, Contains the upper 10-bit of the referenceClock[27:2] when the HARQ_Pattern_Sel_Real_Int
 *    interrupt pulse is detected.
 */
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_harqpatternsel_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_harqpatternsel_refclk_SHIFT)) & BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFCLK_1_harqpatternsel_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on HARQ_Pattern_Sel_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_harqpatternsel_pdbitcnt_MASK (0x1FFFU)
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_harqpatternsel_pdbitcnt_SHIFT (0U)
/*! harqpatternsel_pdbitcnt - Bluetooth Reference pdBitCounter Snapshot on HARQ_Pattern_Sel_Real_Int
 *    Interrupt, Contains the reference pdBitCounter[12:0] when the HARQ_Pattern_Sel_Real_Int
 *    interrupt pulse is detected.
 */
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_harqpatternsel_pdbitcnt(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_harqpatternsel_pdbitcnt_SHIFT)) & BTU2_BTU_PTA_HARQ_PATTERN_SEL_REFPDB_CNT_harqpatternsel_pdbitcnt_MASK)
/*! @} */

/*! @name BTU_PTA_HARQ_PATTERN_SEL_VAL - MWS Coex Signal HARQ_PATTERN_SEL Value */
/*! @{ */

#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_harqpatternselreg_MASK (0xFU)
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_harqpatternselreg_SHIFT (0U)
/*! harqpatternselreg - MWS Coex Signal HARQ_PATTERN_SEL Value, Contains the new HARQ_PATTERN_SEL
 *    value being received. When new HARQ_PATTERN_SEL is detected; the HARQ_Pattern_Sel_Real_Int
 *    real-time interrupt will be generated and new value of HARQ_PATTERN_SEL will be saved in here.
 */
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_harqpatternselreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_harqpatternselreg_SHIFT)) & BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_harqpatternselreg_MASK)

#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_mwsinactmsgreg_MASK (0x1F00U)
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_mwsinactmsgreg_SHIFT (8U)
/*! mwsinactmsgreg - MWS Coex Signal MWS_INACT_MSG Value, Contains the new MWS_INACT_MSG value being
 *    received. When new MWS_INACT_MSG is detected; the MWS_Inact_Msg_Real_Int real-time interrupt
 *    will be generated and new value of MWS_INACT_MSG will be saved here.
 */
#define BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_mwsinactmsgreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_mwsinactmsgreg_SHIFT)) & BTU2_BTU_PTA_HARQ_PATTERN_SEL_VAL_mwsinactmsgreg_MASK)
/*! @} */

/*! @name BTU_PTA_INFO_DELAY_TIMER - PTA Info Delay Timer */
/*! @{ */

#define BTU2_BTU_PTA_INFO_DELAY_TIMER_pta_info_delay_MASK (0x7U)
#define BTU2_BTU_PTA_INFO_DELAY_TIMER_pta_info_delay_SHIFT (0U)
/*! pta_info_delay - Bluetooth Sniff Interval, When BT_Coex_Mode is set to MRVL mode; this is the
 *    time transition time for each of the PTA info bits (i.e.; priority bits) that are serially
 *    encoded on BT_STATE line., A value of 0 is invalid; and will lead to unknown results., - Unit: 0.25
 *    us
 */
#define BTU2_BTU_PTA_INFO_DELAY_TIMER_pta_info_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_INFO_DELAY_TIMER_pta_info_delay_SHIFT)) & BTU2_BTU_PTA_INFO_DELAY_TIMER_pta_info_delay_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_SYNC_CTRL - PTA BLE Sync Control */
/*! @{ */

#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_priority_MASK (0x3U)
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_priority_SHIFT (0U)
/*! ble_sync_priority - BLE Sync Priority, Sets Priority (sync_priority) for sync frame. The
 *    bt_state encodes if the current request is a sync frame or a regular frame. Each frame also has a
 *    2-bit priority. BLE firmware sync_priority value if BLE controls the radio.
 */
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_priority(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_priority_SHIFT)) & BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_priority_MASK)

#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_dir_MASK (0x4U)
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_dir_SHIFT (2U)
/*! ble_sync_dir - BLE Sync Direction, Controls the direction of the sync frame (sync_dir). BLE
 *    firmware sync_dir value if BLE controls the radio., 0x0: Rx first, 0x1: Tx first
 */
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_dir(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_dir_SHIFT)) & BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_dir_MASK)

#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_fw_val_MASK (0x8U)
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_fw_val_SHIFT (3U)
/*! ble_sync_frame_fw_val - BLE Sync Frame Firmware Value, BLE firmware sync_frame value if BLE controls the radio. */
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_fw_val(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_fw_val_SHIFT)) & BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_fw_val_MASK)

#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_extend_MASK (0x10U)
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_extend_SHIFT (4U)
/*! ble_sync_frame_extend - BLE Sync Frame Extend, BLE firmware sync_frame value will be extended
 *    (kept asserted) if BLE keeps controlling the radio. However; sync_frame value will be reset if
 *    BLE ongoing event got cutoff or abort., 0x0: sync_frame value will be de-asserted at falling
 *    edge of bt_req, 0x1: sync_frame value will be extended
 */
#define BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_extend(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_extend_SHIFT)) & BTU2_BTU_PTA_BLE_SYNC_CTRL_ble_sync_frame_extend_MASK)
/*! @} */

/*! @name BTU_PTA_PRI_INC_EBRAM_ADDR - EBRAM Base Address: PTA Priority Escalation */
/*! @{ */

#define BTU2_BTU_PTA_PRI_INC_EBRAM_ADDR_ebram_addr_MASK (0x3FFFU)
#define BTU2_BTU_PTA_PRI_INC_EBRAM_ADDR_ebram_addr_SHIFT (0U)
/*! ebram_addr - EBRAM Address */
#define BTU2_BTU_PTA_PRI_INC_EBRAM_ADDR_ebram_addr(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_PRI_INC_EBRAM_ADDR_ebram_addr_SHIFT)) & BTU2_BTU_PTA_PRI_INC_EBRAM_ADDR_ebram_addr_MASK)
/*! @} */

/*! @name BTU_PTA_SYNC_CTRL - PTA Voice/WLAN Sync Control */
/*! @{ */

#define BTU2_BTU_PTA_SYNC_CTRL_sync_mode_en_MASK (0x8U)
#define BTU2_BTU_PTA_SYNC_CTRL_sync_mode_en_SHIFT (3U)
/*! sync_mode_en - Sync Mode Enable, Enable MRVL Coexistence syncModel mode. The BT_STATE encodes if
 *    the current request is a sync frame or a regular frame. Each frame also has a 2-bit sync
 *    frame priority and a sync frame direction bit., If MRVL Coexistence syncModel mode is on; 4 more
 *    sync frame coexistence info are encoded sequentially on BT_STATE before other coexistence
 *    info:, 1. Sync Frame (sync_frame), 2. Sync Priority[0] (sync_priority[0]), 3. Sync Priority[1]
 *    (sync_priority[1]), 4. Sync Direction (sync_dir)
 */
#define BTU2_BTU_PTA_SYNC_CTRL_sync_mode_en(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_SYNC_CTRL_sync_mode_en_SHIFT)) & BTU2_BTU_PTA_SYNC_CTRL_sync_mode_en_MASK)
/*! @} */

/*! @name BTU_PTA_BLE_TX_PWR_THRHD - BLE Tx Power Threshold to Suppress Tx Overlap Assertion */
/*! @{ */

#define BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble1m_tx_pwr_thrshld_MASK (0xFFU)
#define BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble1m_tx_pwr_thrshld_SHIFT (0U)
/*! ble1m_tx_pwr_thrshld - BLE Tx power threshold for 1 Mbps packet to suppress BT_Overlap/BT_Scan_Overlap assertion */
#define BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble1m_tx_pwr_thrshld(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble1m_tx_pwr_thrshld_SHIFT)) & BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble1m_tx_pwr_thrshld_MASK)

#define BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble2m_tx_pwr_thrshld_MASK (0xFF00U)
#define BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble2m_tx_pwr_thrshld_SHIFT (8U)
/*! ble2m_tx_pwr_thrshld - BLE Tx power threshold for 2 Mbps packet to suppress BT_Overlap/BT_Scan_Overlap assertion */
#define BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble2m_tx_pwr_thrshld(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble2m_tx_pwr_thrshld_SHIFT)) & BTU2_BTU_PTA_BLE_TX_PWR_THRHD_ble2m_tx_pwr_thrshld_MASK)
/*! @} */

/*! @name BTU_PTA_STATE_DELAY_TIMER - PTA Bt_State Delay Timer */
/*! @{ */

#define BTU2_BTU_PTA_STATE_DELAY_TIMER_pta_state_delay_MASK (0x3FFU)
#define BTU2_BTU_PTA_STATE_DELAY_TIMER_pta_state_delay_SHIFT (0U)
/*! pta_state_delay - PTA State Delay, When BT_Coex_Mode is in MRVL mode; this controls the delay
 *    for the BT_STATE transition for the second transaction., This value should never be programmed
 *    less than 15us; otherwise unexpected behavior will occur; such as dropped packets., - Unit:
 *    0.25 us.
 */
#define BTU2_BTU_PTA_STATE_DELAY_TIMER_pta_state_delay(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_STATE_DELAY_TIMER_pta_state_delay_SHIFT)) & BTU2_BTU_PTA_STATE_DELAY_TIMER_pta_state_delay_MASK)
/*! @} */

/*! @name BTU_PTA_SLNA_CTRL - PTA SLNA Control */
/*! @{ */

#define BTU2_BTU_PTA_SLNA_CTRL_ble_use_slna_MASK (0x1U)
#define BTU2_BTU_PTA_SLNA_CTRL_ble_use_slna_SHIFT (0U)
/*! ble_use_slna - BLE uses SLNA based on RSSI info, Among all Bluetooth link RSSI average
 *    information; software decides which path BLE traffic will use for Rx; for example; SLNA or path 3 of
 *    Bluetooth only., 0x0: use path 3 for Bluetooth only based on BLE RSSI average, 0x1: enable SLNA
 *    path based on BLE RSSI average
 */
#define BTU2_BTU_PTA_SLNA_CTRL_ble_use_slna(x)   (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_SLNA_CTRL_ble_use_slna_SHIFT)) & BTU2_BTU_PTA_SLNA_CTRL_ble_use_slna_MASK)

#define BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_sel_MASK (0x2U)
#define BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_sel_SHIFT (1U)
/*! ble_slna_cp_en_bp_sel - BLE side enable SLNA bias/charge pump bypass for software control, By
 *    default; slna_cp_en is dynamically control by rifRx because it requires 120us in advance.
 *    However; software can bypass it to control this enable by ble_slna_cp_en_bp_val with this selection
 *    bit is set., 0x0: use hardware dynamically controlled SLNA_cp_en, 0x1: software bypass to
 *    control the SLNA_cp_en
 */
#define BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_sel(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_sel_SHIFT)) & BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_sel_MASK)

#define BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_val_MASK (0x4U)
#define BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_val_SHIFT (2U)
/*! ble_slna_cp_en_bp_val - SLNA_cp Enable, When ble_slna_cp_en_by_sel is set; this value controls
 *    if SLNA_cp is enabled., When ble_slna_cp_en_by_sel is set; software controls SLNA_cp_en to
 *    enable or disable by this bit., 0x0: eisable SLNA cp, 0x1: enable SLNA cp
 */
#define BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_val(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_val_SHIFT)) & BTU2_BTU_PTA_SLNA_CTRL_ble_slna_cp_en_bp_val_MASK)
/*! @} */

/*! @name BTU_PTA_TX_POWER_THRESHOLD - Tx Power Threshold to Suppress Tx Overlap Assertion */
/*! @{ */

#define BTU2_BTU_PTA_TX_POWER_THRESHOLD_bdr_tx_pwr_thrshld_MASK (0xFFU)
#define BTU2_BTU_PTA_TX_POWER_THRESHOLD_bdr_tx_pwr_thrshld_SHIFT (0U)
/*! bdr_tx_pwr_thrshld - Tx power threshold for BDR packet to suppress bt_overlap/bt_scan_overlap assertion */
#define BTU2_BTU_PTA_TX_POWER_THRESHOLD_bdr_tx_pwr_thrshld(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_TX_POWER_THRESHOLD_bdr_tx_pwr_thrshld_SHIFT)) & BTU2_BTU_PTA_TX_POWER_THRESHOLD_bdr_tx_pwr_thrshld_MASK)

#define BTU2_BTU_PTA_TX_POWER_THRESHOLD_edr_tx_pwr_thrshld_MASK (0xFF00U)
#define BTU2_BTU_PTA_TX_POWER_THRESHOLD_edr_tx_pwr_thrshld_SHIFT (8U)
/*! edr_tx_pwr_thrshld - Tx power threshold for EDR packet to suppress bt_overlap/bt_scan_overlap assertion */
#define BTU2_BTU_PTA_TX_POWER_THRESHOLD_edr_tx_pwr_thrshld(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_TX_POWER_THRESHOLD_edr_tx_pwr_thrshld_SHIFT)) & BTU2_BTU_PTA_TX_POWER_THRESHOLD_edr_tx_pwr_thrshld_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_TX_OVERLAP_RANGE - MWS Frequency Overlap Range for Bluetooth Tx Slot */
/*! @{ */

#define BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_tx_mws_overlap_range_MASK (0xFFU)
#define BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_tx_mws_overlap_range_SHIFT (0U)
/*! tx_mws_overlap_range - MWS frequency overlap range for BR/EDR Tx Slots, Under MWS Coex Mode; MWS
 *    frequency overlap range for BR/EDR Tx slots., Bit[7] direction bit:, - Bits[6:0] value:
 *    overlap boundary channel, The overlap boundary indexes the Bluetooth's 0~78 channels. The direction
 *    bit being 0 represents the upper boundary channel and all smaller index channels thereof are
 *    fallen in the overlap range; whereas the bit begin 1 represents the lower boundary channel and
 *    all larger index channels thereof are fallen in the overlap range., 0x0: upper boundary, 0x1:
 *    lower boundary
 */
#define BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_tx_mws_overlap_range(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_tx_mws_overlap_range_SHIFT)) & BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_tx_mws_overlap_range_MASK)

#define BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_ble_tx_mws_overlap_range_MASK (0xFF00U)
#define BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_ble_tx_mws_overlap_range_SHIFT (8U)
/*! ble_tx_mws_overlap_range - MWS frequency overlap range for BLE Tx packets, Under MWS Coex Mode;
 *    MWS frequency overlap range for BLE Tx packets., Bit[7] direction bit:, - Bits[6:0] value:
 *    overlap boundary channel, The overlap boundary indexes the Bluetooth's 0~78 channels. The
 *    direction bit being 0 represents the upper boundary channel and all smaller index channels thereof
 *    are fallen in the overlap range; whereas the bit begin 1 represents the lower boundary channel
 *    and all larger index channels thereof are fallen in the overlap range., 0x0: upper boundary,
 *    0x1: lower boundary
 */
#define BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_ble_tx_mws_overlap_range(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_ble_tx_mws_overlap_range_SHIFT)) & BTU2_BTU_PTA_MWS_TX_OVERLAP_RANGE_ble_tx_mws_overlap_range_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_RX_OVERLAP_RANGE - MWS Frequency Overlap Range for Bluetooth Rx Slot */
/*! @{ */

#define BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_rx_mws_overlap_range_MASK (0xFFU)
#define BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_rx_mws_overlap_range_SHIFT (0U)
/*! rx_mws_overlap_range - MWS frequency overlap range for BR/EDR Rx Slots, Under MWS Coex Mode; MWS
 *    frequency overlap range for BR/EDR Rx slots., Bit[7] direction bit:, - Bits[6:0] value:
 *    overlap boundary, The overlap boundary indexes the Bluetooth's 0~78 channels. The direction bit
 *    being '0' represents the upper boundary channel and all smaller index channels thereof are fallen
 *    in the overlap range; whereas the bit begin '1' represents the lower boundary channel and all
 *    larger index channels thereof are fallen in the overlap range., 0x0: upper boundary, 0x1:
 *    lower boundary
 */
#define BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_rx_mws_overlap_range(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_rx_mws_overlap_range_SHIFT)) & BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_rx_mws_overlap_range_MASK)

#define BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_ble_rx_mws_overlap_range_MASK (0xFF00U)
#define BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_ble_rx_mws_overlap_range_SHIFT (8U)
/*! ble_rx_mws_overlap_range - MWS frequency overlap range for BLE Rx Packets, Under MWS Coex Mode;
 *    MWS frequency overlap range for BLE Rx packets., Bit[7] direction bit:, - Bits[6:0] value:
 *    overlap boundary, The overlap boundary indexes the Bluetooth's 0~78 channels. The direction bit
 *    being '0' represents the upper boundary channel and all smaller index channels thereof are
 *    fallen in the overlap range; whereas the bit begin '1' represents the lower boundary channel and
 *    all larger index channels thereof are fallen in the overlap range., 0x0: upper boundary, 0x1:
 *    lower boundary
 */
#define BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_ble_rx_mws_overlap_range(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_ble_rx_mws_overlap_range_SHIFT)) & BTU2_BTU_PTA_MWS_RX_OVERLAP_RANGE_ble_rx_mws_overlap_range_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_TX_ON_START - MWS Coex Signal BT_TX_ON Start Timer */
/*! @{ */

#define BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_START_bttxonstartreg_MASK (0x3FFU)
#define BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_START_bttxonstartreg_SHIFT (0U)
/*! bttxonstartreg - BT_TX_ON Start Timer, Under MWS Coex Mode; btTxOnStartReg determines the delay
 *    from rifTx assertion to the rising edge of BT_TX_ON. The time between the rising edge of
 *    BT_TX_ON to the rifTx assertion is (btTxOnStartReg+1) unit of 0.25us., This value should never be
 *    program less than 1; other wise unexpected behavior will occur., - Resolution: 0.25 us., Since
 *    this signal can only assert on successful grant from BCA; this timing needs to be greater than
 *    the delay from rifTx to bca_grant_n.
 */
#define BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_START_bttxonstartreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_START_bttxonstartreg_SHIFT)) & BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_START_bttxonstartreg_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_TX_ON_END - MWS Coex Signal BT_TX_ON End Timer */
/*! @{ */

#define BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_END_bttxonendreg_MASK (0x3FFU)
#define BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_END_bttxonendreg_SHIFT (0U)
/*! bttxonendreg - BT_TX_ON End Timer, Under MWS Coex Mode; btTxOnEndReg determines the delay from
 *    rifTx de-assertion to the falling edge of BT_TX_ON. The time between the falling edge of
 *    BT_TX_ON to the rifTx de-assertion is (btTxOnEndReg+1) unit of 0.25us., This value should never be
 *    program less than 1; otherwise unexpected behavior will occur., - Resolution: 0.25 us.
 */
#define BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_END_bttxonendreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_END_bttxonendreg_SHIFT)) & BTU2_BTU_PTA_MWS_COEX_BT_TX_ON_END_bttxonendreg_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST - MWS Coex Signal BT_RX_PRI Start Timer for Master Mode */
/*! @{ */

#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_btrxpristartmstreg_MASK (0xFFFU)
#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_btrxpristartmstreg_SHIFT (0U)
/*! btrxpristartmstreg - BT_RX_PRI Start Timer for Master Mode, In Real Time mode;
 *    btRxPriStartMstReg determines the delay from rifRx (if
 *    bt_rx_pri_mst_tm_sel/bt_rx_pri_page_resp_tm_sel/bt_rx_pri_inq_resp_tm_sel = 0) or rifTx (if
 *    bt_rx_pri_mst_tm_sel/bt_rx_pri_page_resp_tm_sel/bt_rx_pri_inq_resp_tm_sel = 1) assertion to the rising edge of BT_RX_PRI. The time between the rising
 *    edge of BT_RX_PRI to the rifRx (or rifTx) assertion is (btRxPriStartMstReg+1) unit of 0.25us.,
 *    This value should never be program less than 1; other wise unexpected behavior will occur., -
 *    Resolution: 0.25 us., Since this signal can only assert on successful grant from BCA; this
 *    timing needs to be greater than the delay from rifRx (or rifTx) to bca_grant_n.
 */
#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_btrxpristartmstreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_btrxpristartmstreg_SHIFT)) & BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST_btrxpristartmstreg_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_RX_PRI_END - MWS Coex Signal BT_RX_PRI End Timer */
/*! @{ */

#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_END_btrxpriendreg_MASK (0x3FFU)
#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_END_btrxpriendreg_SHIFT (0U)
/*! btrxpriendreg - BT_RX_PRI End Timer, Under MWS Coex Mode; btRxPriEndReg determines the delay
 *    from rifRx de-assertion to the falling edge of BT_RX_PRI The time between the falling edge of
 *    BT_RX_PRI to the rifRx de-assertion is (btRxPriEndReg+1) unit of 0.25us., This value should never
 *    be program less than 1; otherwise unexpected behavior will occur., - Resolution: 0.25 us.
 */
#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_END_btrxpriendreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_END_btrxpriendreg_SHIFT)) & BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_END_btrxpriendreg_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_FRAMESYNC_REFCLK_0 - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_mwsframesync_refclk_MASK (0xFFFFU)
#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_mwsframesync_refclk_SHIFT (0U)
/*! mwsframesync_refclk - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt,
 *    Contains the lower 16-bit of the referenceClock[27:2] when the MWS frame sync interrupt pulse is
 *    detected.
 */
#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_mwsframesync_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_mwsframesync_refclk_SHIFT)) & BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_0_mwsframesync_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_FRAMESYNC_REFCLK_1 - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_mwsframesync_refclk_MASK (0x3FFU)
#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_mwsframesync_refclk_SHIFT (0U)
/*! mwsframesync_refclk - Bluetooth Reference Clock Snapshot on MWS Frame Sync Pulse Interrupt,
 *    Contains the upper 10-bit of the referenceClock[27:2] when the MWS frame sync interrupt pulse is
 *    detected.
 */
#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_mwsframesync_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_mwsframesync_refclk_SHIFT)) & BTU2_BTU_PTA_MWS_FRAMESYNC_REFCLK_1_mwsframesync_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on MWS Frame Sync Pulse Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_mwsframesync_pdbitcnt_MASK (0x1FFFU)
#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_mwsframesync_pdbitcnt_SHIFT (0U)
/*! mwsframesync_pdbitcnt - Bluetooth Reference pdBitCounter Snapshot on MWS Frame Sync Pulse
 *    Interrupt, Contains the reference pdBitCounter[12:0] when the MWS frame sync interrupt pulse is
 *    detected.
 */
#define BTU2_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_mwsframesync_pdbitcnt(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_mwsframesync_pdbitcnt_SHIFT)) & BTU2_BTU_PTA_MWS_FRAMESYNC_REFPDB_CNT_mwsframesync_pdbitcnt_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_REFCLK_0 - Bluetooth Reference Clock Snapshot on MWS_Pattern_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_PATTERN_REFCLK_0_mwspattern_refclk_MASK (0xFFFFU)
#define BTU2_BTU_PTA_MWS_PATTERN_REFCLK_0_mwspattern_refclk_SHIFT (0U)
/*! mwspattern_refclk - Bluetooth Reference Clock Snapshot on MWS_PATTERN Pulse Interrupt, Contains
 *    the lower 16-bit of the referenceClock[27:2] when the MWS_Pattern_Real_Int interrupt pulse is
 *    detected.
 */
#define BTU2_BTU_PTA_MWS_PATTERN_REFCLK_0_mwspattern_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_PATTERN_REFCLK_0_mwspattern_refclk_SHIFT)) & BTU2_BTU_PTA_MWS_PATTERN_REFCLK_0_mwspattern_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_REFCLK_1 - Bluetooth Reference Clock Snapshot on MWS_Pattern_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_PATTERN_REFCLK_1_mwspattern_refclk_MASK (0x3FFU)
#define BTU2_BTU_PTA_MWS_PATTERN_REFCLK_1_mwspattern_refclk_SHIFT (0U)
/*! mwspattern_refclk - Bluetooth Reference Clock Snapshot on MWS_PATTERN Pulse Interrupt, Contains
 *    the upper 10-bit of the referenceClock[27:2] when the MWS_Pattern_Real_Int interrupt pulse is
 *    detected.
 */
#define BTU2_BTU_PTA_MWS_PATTERN_REFCLK_1_mwspattern_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_PATTERN_REFCLK_1_mwspattern_refclk_SHIFT)) & BTU2_BTU_PTA_MWS_PATTERN_REFCLK_1_mwspattern_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on MWS_Pattern_Real_Int Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_MWS_PATTERN_REFPDB_CNT_mwspattern_pdbitcnt_MASK (0x1FFFU)
#define BTU2_BTU_PTA_MWS_PATTERN_REFPDB_CNT_mwspattern_pdbitcnt_SHIFT (0U)
/*! mwspattern_pdbitcnt - Bluetooth Reference pdBitCounter Snapshot on MWS_PATTERN Pulse Interrupt,
 *    Contains the reference pdBitCounter[12:0] when the MWS_Pattern_Real_Int interrupt pulse is
 *    detected.
 */
#define BTU2_BTU_PTA_MWS_PATTERN_REFPDB_CNT_mwspattern_pdbitcnt(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_PATTERN_REFPDB_CNT_mwspattern_pdbitcnt_SHIFT)) & BTU2_BTU_PTA_MWS_PATTERN_REFPDB_CNT_mwspattern_pdbitcnt_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_PATTERN_VAL - MWS Coex Signal MWS_PATTERN Value */
/*! @{ */

#define BTU2_BTU_PTA_MWS_PATTERN_VAL_mwspatternreg_MASK (0x3U)
#define BTU2_BTU_PTA_MWS_PATTERN_VAL_mwspatternreg_SHIFT (0U)
/*! mwspatternreg - MWS Coex Signal MWS_PATTERN Value, Contains the new MWS_PATTERN value being
 *    received. When new MWS_PATTERN is detected; the MWS_Pattern_Real_Int real-time interrupt will be
 *    generated and new value of MWS_PATTERN will be saved in here.
 */
#define BTU2_BTU_PTA_MWS_PATTERN_VAL_mwspatternreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_PATTERN_VAL_mwspatternreg_SHIFT)) & BTU2_BTU_PTA_MWS_PATTERN_VAL_mwspatternreg_MASK)

#define BTU2_BTU_PTA_MWS_PATTERN_VAL_mwsscanfreqreg_MASK (0x1F00U)
#define BTU2_BTU_PTA_MWS_PATTERN_VAL_mwsscanfreqreg_SHIFT (8U)
/*! mwsscanfreqreg - MWS Coex Signal MWS_SCAN_FREQUENCY Value, Contains the new MWS_SCAN_FREQUENCY
 *    value being received. When new non-zero MWS_SCAN_FREQUENCY is detected; the
 *    MWS_Scan_Frequency_Real_Int real-time interrupt will be generated and new value of MWS_SCAN_FREQUENCY will be
 *    saved here.
 */
#define BTU2_BTU_PTA_MWS_PATTERN_VAL_mwsscanfreqreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_PATTERN_VAL_mwsscanfreqreg_SHIFT)) & BTU2_BTU_PTA_MWS_PATTERN_VAL_mwsscanfreqreg_MASK)
/*! @} */

/*! @name BTU_PTA_3DG_CLK_UPDATE_REFCLK_0 - Bluetooth Reference Clock Snapshot on BT_3DG_CLK_UPATE Pulse Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_bt3dgclkupdate_refclk_MASK (0xFFFFU)
#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_bt3dgclkupdate_refclk_SHIFT (0U)
/*! bt3dgclkupdate_refclk - Bluetooth Reference Clock Snapshot on 3D-Glass Clock Update Pulse
 *    Interrupt, Contrains the lower 16-bit of the referenceClock[27:2] when the 3D-Glass clock update
 *    interrupt pulse is detected.
 */
#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_bt3dgclkupdate_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_bt3dgclkupdate_refclk_SHIFT)) & BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_0_bt3dgclkupdate_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_3DG_CLK_UPDATE_REFCLK_1 - Bluetooth Reference Clock Snapshot on BT_3DG_CLK_UPATE Pulse Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_bt3dgclkupdate_refclk_MASK (0x3FFU)
#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_bt3dgclkupdate_refclk_SHIFT (0U)
/*! bt3dgclkupdate_refclk - Bluetooth Reference Clock Snapshot on 3D-Glass Clock Update Pulse
 *    Interrupt, Contrains the upper 10-bit of the referenceClock[27:2] when the 3D-Glass clock update
 *    interrupt pulse is detected.
 */
#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_bt3dgclkupdate_refclk(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_bt3dgclkupdate_refclk_SHIFT)) & BTU2_BTU_PTA_3DG_CLK_UPDATE_REFCLK_1_bt3dgclkupdate_refclk_MASK)
/*! @} */

/*! @name BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT - Bluetooth Reference pdBitCounter Snapshot on BT_3DG_CLK_UPDATE Pulse Interrupt */
/*! @{ */

#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_bt3dgclkupdate_pdbitcnt_MASK (0x1FFFU)
#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_bt3dgclkupdate_pdbitcnt_SHIFT (0U)
/*! bt3dgclkupdate_pdbitcnt - Bluetooth Reference pdBitCounter Snapshot on 3D-Glass Clock Update
 *    Pulse Interrupt, Contrains the reference pdBitCounter[12:0] when the 3D-Glass clock update
 *    interrupt pulse is detected.
 */
#define BTU2_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_bt3dgclkupdate_pdbitcnt(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_bt3dgclkupdate_pdbitcnt_SHIFT)) & BTU2_BTU_PTA_3DG_CLK_UPDATE_REFPDB_CNT_bt3dgclkupdate_pdbitcnt_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4 - MWS Scan Frequency Overlap Range 1~4 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_1_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_1_SHIFT (0U)
/*! mws_scan_ovlp_range_1 - MWS scan frequency overlap range 1, The MWS scan frequency overlap range
 *    1 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_0001 during MWS scan operation., -
 *    Bit[3] indicates the direction: 0 = represents the upper boundary; the number of subgroups being
 *    overlapped counts forward from subgroup 0. 1 = represents the lower boundary; the number of
 *    subgroups being overlapped counts backward from subgroup 7. Bits[2:0] indicate the number of
 *    Bluetooth channel subgroups that fall into the overlap range., - Pre-defined encoding: 0000: no
 *    overlapped. 1000: all channel 0~78 overlapped. 0001: channel 0~9 are overlapped with lower MWS
 *    scan frequency band; channel 10~78 are not. 0010: channel 0~19 are overlapped with lower MWS
 *    scan frequency band; channel 20~78 are not. ... 1001: channel 70~78 are overlapped with upper
 *    MWS scan frequency band; channel 0~69 are not. 1010: channel 60~78 are overlapped with upper
 *    MWS scan frequency band; channel 0~59 are not. ...
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_1(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_1_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_1_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_2_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_2_SHIFT (4U)
/*! mws_scan_ovlp_range_2 - MWS scan frequency overlap range 2, The MWS scan frequency overlap range
 *    2 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_0010 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_2(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_2_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_2_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_3_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_3_SHIFT (8U)
/*! mws_scan_ovlp_range_3 - MWS scan frequency overlap range 3, The MWS scan frequency overlap range
 *    3 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_0011 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_3(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_3_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_3_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_4_MASK (0xF000U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_4_SHIFT (12U)
/*! mws_scan_ovlp_range_4 - MWS scan frequency overlap range 4, The MWS scan frequency overlap range
 *    4 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_0100 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_4(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_4_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_1_4_mws_scan_ovlp_range_4_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8 - MWS Scan Frequency Overlap Range 5~8 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_5_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_5_SHIFT (0U)
/*! mws_scan_ovlp_range_5 - MWS scan frequency overlap range 5, The MWS scan frequency overlap range
 *    5 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_0101 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_5(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_5_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_5_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_6_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_6_SHIFT (4U)
/*! mws_scan_ovlp_range_6 - MWS scan frequency overlap range 6, The MWS scan frequency overlap range
 *    6 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_0110 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_6(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_6_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_6_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_7_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_7_SHIFT (8U)
/*! mws_scan_ovlp_range_7 - MWS scan frequency overlap range 7, The MWS scan frequency overlap range
 *    7 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_0111 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_7(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_7_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_7_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_8_MASK (0xF000U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_8_SHIFT (12U)
/*! mws_scan_ovlp_range_8 - MWS scan frequency overlap range 8, The MWS scan frequency overlap range
 *    8 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1000 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_8(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_8_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_5_8_mws_scan_ovlp_range_8_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12 - MWS Scan Frequency Overlap Range 9~12 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_9_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_9_SHIFT (0U)
/*! mws_scan_ovlp_range_9 - MWS scan frequency overlap range 9, The MWS scan frequency overlap range
 *    9 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1001 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_9(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_9_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_9_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_10_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_10_SHIFT (4U)
/*! mws_scan_ovlp_range_10 - MWS scan frequency overlap range 10, The MWS scan frequency overlap
 *    range 10 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1010 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_10(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_10_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_10_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_11_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_11_SHIFT (8U)
/*! mws_scan_ovlp_range_11 - MWS scan frequency overlap range 11, The MWS scan frequency overlap
 *    range 11 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1011 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_11(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_11_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_11_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_12_MASK (0xF000U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_12_SHIFT (12U)
/*! mws_scan_ovlp_range_12 - MWS scan frequency overlap range 12, The MWS scan frequency overlap
 *    range 12 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1100 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_12(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_12_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_9_12_mws_scan_ovlp_range_12_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16 - MWS Scan Frequency Overlap Range 13~16 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_13_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_13_SHIFT (0U)
/*! mws_scan_ovlp_range_13 - MWS scan frequency overlap range 13, The MWS scan frequency overlap
 *    range 13 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1101 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_13(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_13_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_13_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_14_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_14_SHIFT (4U)
/*! mws_scan_ovlp_range_14 - MWS scan frequency overlap range 14, The MWS scan frequency overlap
 *    range 14 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1110 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_14(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_14_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_14_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_15_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_15_SHIFT (8U)
/*! mws_scan_ovlp_range_15 - MWS scan frequency overlap range 15, The MWS scan frequency overlap
 *    range 15 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b0_1111 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_15(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_15_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_15_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_16_MASK (0xF000U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_16_SHIFT (12U)
/*! mws_scan_ovlp_range_16 - MWS scan frequency overlap range 16, The MWS scan frequency overlap
 *    range 16 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0000 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_16(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_16_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_13_16_mws_scan_ovlp_range_16_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20 - MWS Scan Frequency Overlap Range 17~20 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_17_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_17_SHIFT (0U)
/*! mws_scan_ovlp_range_17 - MWS scan frequency overlap range 17, The MWS scan frequency overlap
 *    range 17 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0001 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_17(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_17_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_17_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_18_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_18_SHIFT (4U)
/*! mws_scan_ovlp_range_18 - MWS scan frequency overlap range 18, The MWS scan frequency overlap
 *    range 18 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0010 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_18(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_18_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_18_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_19_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_19_SHIFT (8U)
/*! mws_scan_ovlp_range_19 - MWS scan frequency overlap range 19, The MWS scan frequency overlap
 *    range 19 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0011 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_19(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_19_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_19_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_20_MASK (0xF000U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_20_SHIFT (12U)
/*! mws_scan_ovlp_range_20 - MWS scan frequency overlap range 20, The MWS scan frequency overlap
 *    range 20 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0100 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_20(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_20_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_17_20_mws_scan_ovlp_range_20_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24 - MWS Scan Frequency Overlap Range 21~24 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_21_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_21_SHIFT (0U)
/*! mws_scan_ovlp_range_21 - MWS scan frequency overlap range 21, The MWS scan frequency overlap
 *    range 21 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0101 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_21(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_21_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_21_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_22_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_22_SHIFT (4U)
/*! mws_scan_ovlp_range_22 - MWS scan frequency overlap range 22, The MWS scan frequency overlap
 *    range 22 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0110 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_22(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_22_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_22_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_23_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_23_SHIFT (8U)
/*! mws_scan_ovlp_range_23 - MWS scan frequency overlap range 23, The MWS scan frequency overlap
 *    range 23 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_0111 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_23(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_23_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_23_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_24_MASK (0xF000U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_24_SHIFT (12U)
/*! mws_scan_ovlp_range_24 - MWS scan frequency overlap range 24, The MWS scan frequency overlap
 *    range 24 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1000 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_24(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_24_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_21_24_mws_scan_ovlp_range_24_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28 - MWS Scan Frequency Overlap Range 25~28 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_25_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_25_SHIFT (0U)
/*! mws_scan_ovlp_range_25 - MWS scan frequency overlap range 25, The MWS scan frequency overlap
 *    range 25 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1001 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_25(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_25_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_25_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_26_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_26_SHIFT (4U)
/*! mws_scan_ovlp_range_26 - MWS scan frequency overlap range 26, The MWS scan frequency overlap
 *    range 26 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1010 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_26(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_26_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_26_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_27_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_27_SHIFT (8U)
/*! mws_scan_ovlp_range_27 - MWS scan frequency overlap range 27, The MWS scan frequency overlap
 *    range 27 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1011 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_27(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_27_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_27_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_28_MASK (0xF000U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_28_SHIFT (12U)
/*! mws_scan_ovlp_range_28 - MWS scan frequency overlap range 28, The MWS scan frequency overlap
 *    range 28 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1100 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_28(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_28_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_25_28_mws_scan_ovlp_range_28_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31 - MWS Scan Frequency Overlap Range 29~31 */
/*! @{ */

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_29_MASK (0xFU)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_29_SHIFT (0U)
/*! mws_scan_ovlp_range_29 - MWS scan frequency overlap range 29, The MWS scan frequency overlap
 *    range 29 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1101 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_29(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_29_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_29_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_30_MASK (0xF0U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_30_SHIFT (4U)
/*! mws_scan_ovlp_range_30 - MWS scan frequency overlap range 30, The MWS scan frequency overlap
 *    range 30 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1110 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_30(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_30_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_30_MASK)

#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_31_MASK (0xF00U)
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_31_SHIFT (8U)
/*! mws_scan_ovlp_range_31 - MWS scan frequency overlap range 31, The MWS scan frequency overlap
 *    range 31 register is indexed by MWS_SCAN_FREQUENCY[4:0] = 'b1_1111 during MWS scan operation. See
 *    mws_scan_ovlp_range_1 for bit field description.
 */
#define BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_31(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_31_SHIFT)) & BTU2_BTU_PTA_MWS_SCAN_OVLP_RANGE_29_31_mws_scan_ovlp_range_31_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL - MWS Coex Early BT_RX_PRI Control */
/*! @{ */

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mode_MASK (0x3U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mode_SHIFT (0U)
/*! bt_rx_pri_mode - BT_RX_PRI mode selection, These select the mode of operation for asserting the
 *    BT_RX_PRI signal., Bit[1] selects the Advance Mode. BT_RX_PRI signal assertion is based on
 *    earlyBtRxPri bit in Frame Descriptor programmed by firmware., Bit[0] selects the Real Time Mode.
 *    BT_RX_PRI signal is asserted in real time by hardware based on Bluetooth Rx packet's priority
 *    and event types.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mode(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mode_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mode_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_mst_MASK (0x4U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_mst_SHIFT (2U)
/*! bt_rx_pri_page_resp_mst - BT_RX_PRI assertion during page response at master side, This bit
 *    enables BT_RX_PRI assertion by BTU for critical Rx during page response at master side.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_mst(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_mst_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_mst_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_MASK (0x8U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_SHIFT (3U)
/*! bt_rx_pri_inq_resp - BT_RX_PRI assertion during inquiry response, This bit enables BT_RX_PRI
 *    assertion by BTU for critical Rx during inquiry response.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_slv_MASK (0x10U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_slv_SHIFT (4U)
/*! bt_rx_pri_page_resp_slv - BT_RX_PRI assertion during page response at slave side, This bit
 *    enables BT_RX_PRI assertion by BTU for critical Rx during page response at slave side.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_slv(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_slv_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_slv_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mst_tm_sel_MASK (0x20U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mst_tm_sel_SHIFT (5U)
/*! bt_rx_pri_mst_tm_sel - BT_RX_PRI advance timing selection in Real Time mode for Bluetooth master
 *    mode, select 100us or 600us range advance timing., 0x0: select 100us range (BT_RX_PRI
 *    assertion is delayed by, BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifRx rising edge of the Rx
 *    packet), 0x1: select 600us range (BT_RX_PRI assertion is delayed by,
 *    BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifTx rising edge of the preceding Tx, packet)
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mst_tm_sel(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mst_tm_sel_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_mst_tm_sel_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_tm_sel_MASK (0x40U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_tm_sel_SHIFT (6U)
/*! bt_rx_pri_page_resp_tm_sel - BT_RX_PRI advance timing selection during master or slave page
 *    response, select 100us or 600us range advance timing, 0x0: select 100us range. For master;
 *    BT_RX_PRI assertion is delayed by, BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifRx rising edge of
 *    each Rx ID, packet. For slave; BT_RX_PRI assertion is delayed by,
 *    BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV from rifRx rising edge of the Rx FHS, packet., 0x1: select 600us range. For master;
 *    BT_RX_PRI assertion is delayed by, BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifTx rising edge of
 *    the first Tx ID, packet. For slave; BT_RX_PRI assertion is delayed by,
 *    BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV from correlation hit of the first or second, Rx ID packet.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_tm_sel(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_tm_sel_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_page_resp_tm_sel_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_tm_sel_MASK (0x80U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_tm_sel_SHIFT (7U)
/*! bt_rx_pri_inq_resp_tm_sel - BT_RX_PRI advance timing selection during inquiry response, select
 *    100us or 600us range advance timing, 0x0: select 100us range. BT_RX_PRI assertion is delayed
 *    by, BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from rifRx rising edge of the FHS packet., 0x1: select
 *    600us range. BT_RX_PRI assertion is delayed by, BTU_PTA_MWS_COEX_BT_RX_PRI_START_MST from
 *    rifTx rising edge of the first Tx ID, packet.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_tm_sel(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_tm_sel_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_inq_resp_tm_sel_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_early_bt_rx_pri_deass_fram_cnt_MASK (0x700U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_early_bt_rx_pri_deass_fram_cnt_SHIFT (8U)
/*! early_bt_rx_pri_deass_fram_cnt - Number of frames BT_RX_PRI should be de-asserted, This frame
 *    counter register is used to track how many frames in advance firmware is programming. When the
 *    earlyBtRxPri bit in frame descriptor is set; hardware will load this register value into
 *    hardware counter. BTU will de-assert BT_RX_PRI with appropriate timing on the frame that this
 *    hardware counter decrements to zero. This way firmware only will program earlyBtRxPri frame bit once
 *    for one packet.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_early_bt_rx_pri_deass_fram_cnt(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_early_bt_rx_pri_deass_fram_cnt_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_early_bt_rx_pri_deass_fram_cnt_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_drive_MASK (0x800U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_drive_SHIFT (11U)
/*! bt_rx_pri_drive - Control BT_RX_PRI logic level directly, This bit allows firmware to control
 *    the outgoing BT_RX_PRI logic level directly in real time.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_drive(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_drive_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_drive_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_assrt_lvl_MASK (0x3000U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_assrt_lvl_SHIFT (12U)
/*! bt_rx_pri_assrt_lvl - Specify priority level to assert BT_RX_PRI for BR/EDR packet, Only the
 *    coex_priority with the same or higher level than this setting will cause the assertion of
 *    BT_RX_PRI to BCA.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_assrt_lvl(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_assrt_lvl_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_bt_rx_pri_assrt_lvl_MASK)

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_ble_rx_pri_assrt_lvl_MASK (0xC000U)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_ble_rx_pri_assrt_lvl_SHIFT (14U)
/*! ble_rx_pri_assrt_lvl - Specify priority level to assert BT_RX_PRI for BLE packet, Only the
 *    coex_priority with the same or higher level than this setting will cause the assertion of BT_RX_PRI
 *    to BCA.
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_ble_rx_pri_assrt_lvl(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_ble_rx_pri_assrt_lvl_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_CTRL_ble_rx_pri_assrt_lvl_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST - MWS Coex Early BT_RX_PRI Start Offset for Master Mode */
/*! @{ */

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_startoffsetmst_MASK (0x1FFFU)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_startoffsetmst_SHIFT (0U)
/*! startoffsetmst - Start Offset in Master Mode, Early indication BT_RX_PRI assertion time offset
 *    in Advance mode of MWS Coex when operating in master mode. Time unit is 0.25us. When the
 *    earlyBtRxPri bit in frame descriptor is set in master mode; hardware will assert BT_RX_PRI at
 *    (earlyBtRxPriStartOffsetMst * 0.25) us after the start of frame. The valid range is 0x2 ~ 0x1387
 *    (1250us).
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_startoffsetmst(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_startoffsetmst_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_MST_startoffsetmst_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV - MWS Coex Early BT_RX_PRI Start Offset for Slave Mode */
/*! @{ */

#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_startoffsetslv_MASK (0x1FFFU)
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_startoffsetslv_SHIFT (0U)
/*! startoffsetslv - Start Offset in Slave Mode, Early indication BT_RX_PRI assertion time offset in
 *    Advance mode of MWS Coex when operating in slave mode. Time unit is 0.25us. When the
 *    earlyBtRxPri bit in frame descriptor is set in slave mode; hardware will assert BT_RX_PRI at
 *    (earlyBtRxPriStartOffsetSlv * 0.25) us after the start of frame. The valid range is 0x2 ~ 0x1387
 *    (1250us).
 */
#define BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_startoffsetslv(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_startoffsetslv_SHIFT)) & BTU2_BTU_PTA_MWS_EARLY_BT_RX_PRI_STAROFFST_SLV_startoffsetslv_MASK)
/*! @} */

/*! @name BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV - MWS Coex Signal BT_RX_PRI Start Timer for Slave Mode */
/*! @{ */

#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_btrxpristartslvreg_MASK (0xFFFU)
#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_btrxpristartslvreg_SHIFT (0U)
/*! btrxpristartslvreg - BT_RX_PRI Start Timer for Slave Mode, In Real Time mode; btRxPriStartSlvReg
 *    determines the delay from rifRx assertion (or correlation hit if bt_rx_pri_page_resp_tm_sel =
 *    1) to the rising edge of BT_RX_PRI. The time between the rising edge of BT_RX_PRI to the
 *    rifRx assertion is (btRxPriStartSlvReg+1) unit of 0.25us., This value should never be program less
 *    than 1; other wise unexpected behavior will occur., - Resolution: 0.25 us., Since this signal
 *    can only assert on successful grant from BCA; this timing needs to be greater than the delay
 *    from rifRx to bca_grant_n.
 */
#define BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_btrxpristartslvreg(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_btrxpristartslvreg_SHIFT)) & BTU2_BTU_PTA_MWS_COEX_BT_RX_PRI_START_SLV_btrxpristartslvreg_MASK)
/*! @} */

/*! @name BTU_PTA_ANT_SWITCH_CTRL - PTA Antenna Switch Control, Antenna switch control for BCA arbitration. */
/*! @{ */

#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_en_MASK (0x1U)
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_en_SHIFT (0U)
/*! bca_ant_switch_sts_bypass_en - BCA antenna switch status bypass enable, When
 *    bca_ant_switch_sts_bypass_en is set; BCA antSwitchStatus is controlled by bca_ant_switch_sts_bypass_val
 *    register., 0x0: disable antSwitchStatus bypass, 0x1: enable antSwitchStatus bypass
 */
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_en_SHIFT)) & BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_en_MASK)

#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_val_MASK (0x2U)
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_val_SHIFT (1U)
/*! bca_ant_switch_sts_bypass_val - BCA antenna switch status bypass value, When
 *    bca_ant_switch_sts_bypass_en is set; BCA antSwitchStatus is controlled by this register., 0x0: set BCA
 *    antSwitchStatus to zero, 0x1: set BCA antSwitchStatus to one
 */
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_val(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_val_SHIFT)) & BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ant_switch_sts_bypass_val_MASK)

#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_MASK (0x1F00U)
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_SHIFT (8U)
/*! bca_ref_antenna - BCA reference antenna override value, When bca_ref_antenna_override is set;
 *    BCA reference antenna is controlled by this register.
 */
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_SHIFT)) & BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_MASK)

#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_override_MASK (0x8000U)
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_override_SHIFT (15U)
/*! bca_ref_antenna_override - BCA reference antenna override, When bca_ref_antenna_override is set;
 *    BCA reference antenna is controlled by bca_ref_antenna register., 0x0: disable BCA refAntenna
 *    override, 0x1: enable BCA refAntenna override
 */
#define BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_override(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_override_SHIFT)) & BTU2_BTU_PTA_ANT_SWITCH_CTRL_bca_ref_antenna_override_MASK)
/*! @} */

/*! @name BTU_PTA_RSSI_ARB_CTRL - BTU RSSI Arbitration Control, RSSI Based arbitration register controls like feature enable; RSSI value from EBRAM or register selection; average RSSI orRSSI for last received packet */
/*! @{ */

#define BTU2_BTU_PTA_RSSI_ARB_CTRL_rssi_arb_en_MASK (0x1U)
#define BTU2_BTU_PTA_RSSI_ARB_CTRL_rssi_arb_en_SHIFT (0U)
/*! rssi_arb_en - RSSI based arbitration Feature enable, Software programable feature enable bit for
 *    enabling assertion of interface signals for RSSI based arbitration, 0x0: Disable interface
 *    signals used for RSSI based arbitration, 0x1: Enable interface signals used for RSSI based
 *    arbitrationEnable RSSI based, arbitration output signals
 */
#define BTU2_BTU_PTA_RSSI_ARB_CTRL_rssi_arb_en(x) (((uint16_t)(((uint16_t)(x)) << BTU2_BTU_PTA_RSSI_ARB_CTRL_rssi_arb_en_SHIFT)) & BTU2_BTU_PTA_RSSI_ARB_CTRL_rssi_arb_en_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BTU2_Register_Masks */


/*!
 * @}
 */ /* end of group BTU2_Peripheral_Access_Layer */


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


#endif  /* PERI_BTU2_H_ */

