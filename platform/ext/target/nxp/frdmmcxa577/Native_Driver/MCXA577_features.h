/*
** ###################################################################
**     Version:             rev. 1.0, 2024-03-26
**     Build:               b260804
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**
** ###################################################################
*/

#ifndef _MCXA577_FEATURES_H_
#define _MCXA577_FEATURES_H_

/* SOC module features */

/* @brief AOI availability on the SoC. */
#define FSL_FEATURE_SOC_AOI_COUNT (1)
/* @brief CDOG availability on the SoC. */
#define FSL_FEATURE_SOC_CDOG_COUNT (2)
/* @brief CMC availability on the SoC. */
#define FSL_FEATURE_SOC_CMC_COUNT (1)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (1)
/* @brief CTIMER availability on the SoC. */
#define FSL_FEATURE_SOC_CTIMER_COUNT (5)
/* @brief EDMA availability on the SoC. */
#define FSL_FEATURE_SOC_EDMA_COUNT (2)
/* @brief EIM availability on the SoC. */
#define FSL_FEATURE_SOC_EIM_COUNT (1)
/* @brief EWM availability on the SoC. */
#define FSL_FEATURE_SOC_EWM_COUNT (1)
/* @brief FLEXCAN availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXCAN_COUNT (2)
/* @brief FLEXIO availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXIO_COUNT (1)
/* @brief FLEXSPI availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXSPI_COUNT (1)
/* @brief FMC availability on the SoC. */
#define FSL_FEATURE_SOC_FMC_COUNT (1)
/* @brief FREQME availability on the SoC. */
#define FSL_FEATURE_SOC_FREQME_COUNT (1)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (6)
/* @brief SPC availability on the SoC. */
#define FSL_FEATURE_SOC_SPC_COUNT (1)
/* @brief I3C availability on the SoC. */
#define FSL_FEATURE_SOC_I3C_COUNT (4)
/* @brief INPUTMUX availability on the SoC. */
#define FSL_FEATURE_SOC_INPUTMUX_COUNT (1)
/* @brief ITRC availability on the SoC. */
#define FSL_FEATURE_SOC_ITRC_COUNT (1)
/* @brief LPADC availability on the SoC. */
#define FSL_FEATURE_SOC_LPADC_COUNT (2)
/* @brief LPCMP availability on the SoC. */
#define FSL_FEATURE_SOC_LPCMP_COUNT (1)
/* @brief LPDAC availability on the SoC. */
#define FSL_FEATURE_SOC_LPDAC_COUNT (2)
/* @brief LPI2C availability on the SoC. */
#define FSL_FEATURE_SOC_LPI2C_COUNT (5)
/* @brief LPSPI availability on the SoC. */
#define FSL_FEATURE_SOC_LPSPI_COUNT (6)
/* @brief LPTMR availability on the SoC. */
#define FSL_FEATURE_SOC_LPTMR_COUNT (1)
/* @brief LPUART availability on the SoC. */
#define FSL_FEATURE_SOC_LPUART_COUNT (6)
/* @brief MCX_ENET availability on the SoC. */
#define FSL_FEATURE_SOC_MCX_ENET_COUNT (1)
/* @brief MPU availability on the SoC. */
#define FSL_FEATURE_SOC_MPU_COUNT (1)
/* @brief OSTIMER availability on the SoC. */
#define FSL_FEATURE_SOC_OSTIMER_COUNT (1)
/* @brief PKC availability on the SoC. */
#define FSL_FEATURE_SOC_PKC_COUNT (1)
/* @brief PORT availability on the SoC. */
#define FSL_FEATURE_SOC_PORT_COUNT (6)
/* @brief RTC availability on the SoC. */
#define FSL_FEATURE_SOC_RTC_COUNT (1)
/* @brief SCG availability on the SoC. */
#define FSL_FEATURE_SOC_SCG_COUNT (1)
/* @brief SMARTDMA availability on the SoC. */
#define FSL_FEATURE_SOC_SMARTDMA_COUNT (1)
/* @brief SYSCON availability on the SoC. */
#define FSL_FEATURE_SOC_SYSCON_COUNT (1)
/* @brief TENBASET_PHY availability on the SoC. */
#define FSL_FEATURE_SOC_TENBASET_PHY_COUNT (1)
/* @brief TRNG availability on the SoC. */
#define FSL_FEATURE_SOC_TRNG_COUNT (1)
/* @brief TSI availability on the SoC. */
#define FSL_FEATURE_SOC_TSI_COUNT (1)
/* @brief USBHS availability on the SoC. */
#define FSL_FEATURE_SOC_USBHS_COUNT (1)
/* @brief USBHSDCD availability on the SoC. */
#define FSL_FEATURE_SOC_USBHSDCD_COUNT (1)
/* @brief USBNC availability on the SoC. */
#define FSL_FEATURE_SOC_USBNC_COUNT (1)
/* @brief USBPHY availability on the SoC. */
#define FSL_FEATURE_SOC_USBPHY_COUNT (1)
/* @brief UTICK availability on the SoC. */
#define FSL_FEATURE_SOC_UTICK_COUNT (1)
/* @brief VBAT availability on the SoC. */
#define FSL_FEATURE_SOC_VBAT_COUNT (1)
/* @brief VREF availability on the SoC. */
#define FSL_FEATURE_SOC_VREF_COUNT (1)
/* @brief WAKETIMER availability on the SoC. */
#define FSL_FEATURE_SOC_WAKETIMER_COUNT (1)
/* @brief WWDT availability on the SoC. */
#define FSL_FEATURE_SOC_WWDT_COUNT (2)
/* @brief WUU availability on the SoC. */
#define FSL_FEATURE_SOC_WUU_COUNT (1)

/* LPADC module features */

/* @brief FIFO availability on the SoC. */
#define FSL_FEATURE_LPADC_FIFO_COUNT (1)
/* @brief Does not support two simultanious single ended conversions (bitfield TCTRL[FIFO_SEL_B]). */
#define FSL_FEATURE_LPADC_HAS_NO_TCTRL_FIFO_SEL_B (1)
/* @brief Has subsequent trigger priority (bitfield CFG[TPRICTRL]). */
#define FSL_FEATURE_LPADC_HAS_CFG_SUBSEQUENT_PRIORITY (1)
/* @brief Has differential mode (bitfield CMDLn[DIFF]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_DIFF (0)
/* @brief Has channel scale (bitfield CMDLn[CSCALE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_CSCALE (0)
/* @brief Has conversion type select (bitfield CMDLn[CTYPE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_CTYPE (1)
/* @brief Has conversion resolution select  (bitfield CMDLn[MODE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_MODE (1)
/* @brief Has Wait for trigger assertion before execution (bitfield CMDHn[WAIT_TRIG]). */
#define FSL_FEATURE_LPADC_HAS_CMDH_WAIT_TRIG (1)
/* @brief Has offset calibration (bitfield CTRL[CALOFS]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CALOFS (1)
/* @brief Has gain calibration (bitfield CTRL[CAL_REQ]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CAL_REQ (1)
/* @brief Has calibration average (bitfield CTRL[CAL_AVGS]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CAL_AVGS (1)
/* @brief Has internal clock (bitfield CFG[ADCKEN]). */
#define FSL_FEATURE_LPADC_HAS_CFG_ADCKEN (0)
/* @brief Enable support for low voltage reference on option 1 reference (bitfield CFG[VREF1RNG]). */
#define FSL_FEATURE_LPADC_HAS_CFG_VREF1RNG (0)
/* @brief Has calibration (bitfield CFG[CALOFS]). */
#define FSL_FEATURE_LPADC_HAS_CFG_CALOFS (0)
/* @brief Has offset trim (register OFSTRIM). */
#define FSL_FEATURE_LPADC_HAS_OFSTRIM (1)
/* @brief Has power select (bitfield CFG[PWRSEL]). */
#define FSL_FEATURE_LPADC_HAS_CFG_PWRSEL (1)
/* @brief Has alternate channel B scale (bitfield CMDLn[ALTB_CSCALE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_ALTB_CSCALE (0)
/* @brief Has alternate channel B select enable (bitfield CMDLn[ALTBEN]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_ALTBEN (0)
/* @brief Has alternate channel input (bitfield CMDLn[ALTB_ADCH]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_ALTB_ADCH (0)
/* @brief Has offset calibration mode (bitfield CTRL[CALOFSMODE]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CALOFSMODE (0)
/* @brief Conversion averaged bitfiled width. */
#define FSL_FEATURE_LPADC_CONVERSIONS_AVERAGED_BITFIELD_WIDTH (4)
/* @brief Enable hardware trigger command selection */
#define FSL_FEATURE_LPADC_HAS_TCTRL_CMD_SEL (0)
/* @brief OFSTRIM availability on the SoC. */
#define FSL_FEATURE_LPADC_OFSTRIM_COUNT (1)
/* @brief Has Trigger status register. */
#define FSL_FEATURE_LPADC_HAS_TSTAT (1)
/* @brief Has B side channels. */
#define FSL_FEATURE_LPADC_HAS_B_SIDE_CHANNELS (0)
/* @brief Indicate whether the LPADC STAT register has trigger exception interrupt function (bitfield STAT[TEXC_INT]). */
#define FSL_FEATURE_LPADC_HAS_STAT_TEXC_INT (1)
/* @brief Indicate whether the LPADC STAT register has trigger completion interrupt function (bitfield STAT[TCOMP_INT]). */
#define FSL_FEATURE_LPADC_HAS_STAT_TCOMP_INT (1)
/* @brief Indicate whether the LPADC STAT register has calibration ready function (bitfield STAT[CAL_RDY]). */
#define FSL_FEATURE_LPADC_HAS_STAT_CAL_RDY (1)
/* @brief Indicate whether the LPADC STAT register has ADC active function (bitfield STAT[ADC_ACTIVE]). */
#define FSL_FEATURE_LPADC_HAS_STAT_ADC_ACTIVE (1)
/* @brief Indicate whether the LPADC IE register has trigger exception interrupt enable function (bitfield IE[TEXC_IE]). */
#define FSL_FEATURE_LPADC_HAS_IE_TEXC_IE (1)
/* @brief Indicate whether the LPADC IE register has trigger completion interrupt enable function (bitfield IE[TCOMP_IE]). */
#define FSL_FEATURE_LPADC_HAS_IE_TCOMP_IE (1)
/* @brief Indicate whether the LPADC CFG register has trigger resume/restart enable function (bitfield CFG[TRES]). */
#define FSL_FEATURE_LPADC_HAS_CFG_TRES (1)
/* @brief Indicate whether the LPADC CFG register has trigger command resume/restart enable function (bitfield CFG[TCMDRES]). */
#define FSL_FEATURE_LPADC_HAS_CFG_TCMDRES (1)
/* @brief Indicate whether the LPADC CFG register has high priority trigger exception disable function (bitfield CFG[HPT_EXDI]). */
#define FSL_FEATURE_LPADC_HAS_CFG_HPT_EXDI (1)
/* @brief Indicate LPADC CFG register TPRICTRL bitfield width. */
#define FSL_FEATURE_LPADC_CFG_TPRICTRL_BITFIELD_WIDTH (2)
/* @brief Has compare function enable (bitfield CMDHn[CMPEN]). */
#define FSL_FEATURE_LPADC_HAS_CMDH_CMPEN (1)
/* @brief Has High Speed Mode Trim Request (bitfield CTRL[CALHS]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CALHS (1)
/* @brief Has Justified Left Enable (bitfield CFG2[JLEFT]). */
#define FSL_FEATURE_LPADC_HAS_CFG2_JLEFT (1)
/* @brief Trigger Control Count. */
#define FSL_FEATURE_LPADC_TCTRL_COUNT (4)
/* @brief Has internal temperature sensor. */
#define FSL_FEATURE_LPADC_HAS_INTERNAL_TEMP_SENSOR (1)
/* @brief Temperature sensor parameter A (slope). */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_A (738.0f)
/* @brief Temperature sensor parameter B (offset). */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_B (287.5f)
/* @brief Temperature sensor parameter Alpha. */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_ALPHA (10.06f)
/* @brief The buffer size of temperature sensor. */
#define FSL_FEATURE_LPADC_TEMP_SENS_BUFFER_SIZE (2U)

/* AOI module features */

/* @brief Maximum value of input mux. */
#define FSL_FEATURE_AOI_MODULE_INPUTS (4)
/* @brief Number of events related to number of registers AOIx_BFCRT01n/AOIx_BFCRT23n. */
#define FSL_FEATURE_AOI_EVENT_COUNT (4)

/* FLEXCAN module features */

/* @brief Message buffer size */
#define FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) (32)
/* @brief Has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT (1)
/* @brief Insatnce has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(x) (1)
/* @brief Has a glitch filter on the receive pin (register bit field MCR[WAKSRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER (1)
/* @brief Has extended interrupt mask and flag register (register IMASK2, IFLAG2). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER (0)
/* @brief Instance has extended bit timing register (register CBT). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTENDED_TIMING_REGISTERn(x) (1)
/* @brief Has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA (1)
/* @brief Instance has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_RX_FIFO_DMAn(x) (1)
/* @brief Remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE (1)
/* @brief Instance remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_SUPPORT_ENGINE_CLK_SEL_REMOVEn(x) (1)
/* @brief Is affected by errata with ID 5641 (Module does not transmit a message that is enabled to be transmitted at a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641 (0)
/* @brief Is affected by errata with ID 5829 (FlexCAN: FlexCAN does not transmit a message that is enabled to be transmitted in a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829 (0)
/* @brief Is affected by errata with ID 6032 (FlexCAN: A frame with wrong ID or payload is transmitted into the CAN bus when the Message Buffer under transmission is either aborted or deactivated while the CAN bus is in the Bus Idle state). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032 (0)
/* @brief Is affected by errata with ID 9595 (FlexCAN: Corrupt frame possible if the Freeze Mode or the Low-Power Mode are entered during a Bus-Off state). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_9595 (0)
/* @brief Has CAN with Flexible Data rate (CAN FD) protocol. */
#define FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE (1)
/* @brief CAN instance support Flexible Data rate (CAN FD) protocol. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_FLEXIBLE_DATA_RATEn(x) (1)
/* @brief Has memory error control (register MECR). */
#define FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL (0)
/* @brief Has enhanced bit timing register (register EPRS, ENCBT, EDCBT and ETDC). */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_BIT_TIMING_REG (1)
/* @brief Has Pretended Networking mode support. */
#define FSL_FEATURE_FLEXCAN_HAS_PN_MODE (1)
/* @brief Has Enhanced Rx FIFO. */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO (1)
/* @brief Has Enhanced Rx FIFO. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_ENHANCED_RX_FIFOn(x) (1)
/* @brief Enhanced Rx FIFO size (Indicates how many CAN FD messages can be stored). */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO_SIZE (12)
/* @brief The number of enhanced Rx FIFO filter element registers. */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO_FILTER_MAX_NUMBER (32)
/* @brief Does not support Supervisor Mode (bitfield MCR[SUPV]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SUPV_SUPPORT (0)
/* @brief Has more than 64 MBs. */
#define FSL_FEATURE_FLEXCAN_HAS_MORE_THAN_64_MB (0)
/* @brief Does not support self wake feature(bitfield MCR[SLFWAK]) */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SLFWAK_SUPPORT (0)
/* @brief Has external time tick source (bitfield CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTERNAL_TIME_TICK (0)
/* @brief Instance has external time tick source (register bit field CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTERNAL_TIME_TICKn(x) (0)
/* @brief Has Time Stamp Capture Point(bitfield CTRL2[TSTAMPCAP]). */
#define FSL_FEATURE_FLEXCAN_HAS_HIGH_RESOLUTION_TIMESTAMP (0)
/* @brief Instance has Pretended Networking option (register bit field MCR[PNET_EN]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_PN_MODEn(x) (1)
/* @brief FlexCAN maximum data rate. */
#define FSL_FEATURE_FLEXCAN_MAX_CANFD_BITRATE (8000000)
/* @brief Support payload endianness selection (bitfield CTRL2[PES]). */
#define FSL_FEATURE_FLEXCAN_HAS_ENDIANNESS_SELECTION (0)
/* @brief Enter Freeze mode before entering Disable and Stop mode. */
#define FSL_FEATURE_FLEXCAN_ENTER_FREEZE_MODE (0)
/* @brief Is affected by errata with ID 8341 (FlexCAN: Entering Freeze Mode or Low Power Mode from Normal Mode can cause the FlexCAN module to stop operating). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_8341 (0)
/* @brief Is affected by errata with ID 050443 (FlexCAN: : Receive Message Buffers may have its CODE Field corrupted if the Receive FIFO function is used in Classical CAN mode). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_050443 (0)
/* @brief Support memory error interrupt (bitfield MECR[CEI_MSK]). */
#define FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_INTERRUPT (0)

/* CDOG module features */

/* @brief SOC has no reset driver. */
#define FSL_FEATURE_CDOG_HAS_NO_RESET (1)
/* @brief CDOG Load default configurations during init function */
#define FSL_FEATURE_CDOG_NEED_LOAD_DEFAULT_CONF (0)

/* CMC module features */

/* @brief Has SRAM_DIS register */
#define FSL_FEATURE_MCX_CMC_HAS_SRAM_DIS_REG (1)
/* @brief Has BSR register */
#define FSL_FEATURE_MCX_CMC_HAS_BSR_REG (1)
/* @brief Has RSTCNT register */
#define FSL_FEATURE_MCX_CMC_HAS_RSTCNT_REG (0)
/* @brief Has BLR register */
#define FSL_FEATURE_MCX_CMC_HAS_BLR_REG (0)
/* @brief Has no bitfield FLASHWAKE in FLASHCR register */
#define FSL_FEATURE_MCX_CMC_HAS_NO_FLASHCR_WAKE (0)
/* @brief Has SCR bit in BSR register */
#define FSL_FEATURE_MCX_CMC_HAS_BSR_SCR_BIT (0)
/* @brief Has DBGCTL register */
#define FSL_FEATURE_MCX_CMC_HAS_DBGCTL_REG (1)

/* LPCMP module features */

/* @brief Has CCR1 FUNC_CLK_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR1_FUNC_CLK_SEL (1)
/* @brief Has IER RRF_IE bitfield. */
#define FSL_FEATURE_LPCMP_HAS_IER_RRF_IE (1)
/* @brief Has CSR RRF bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CSR_RRF (1)
/* @brief Has Round Robin mode (related to existence of registers RRCR0). */
#define FSL_FEATURE_LPCMP_HAS_ROUNDROBIN_MODE (1)
/* @brief Has window mode (related to existence of CCR1.WINDOW_CLS). */
#define FSL_FEATURE_LPCMP_HAS_WINDOW_CONTROL (1)
/* @brief Has no CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_NO_CCR0_CMP_STOP_EN (0)
/* @brief Has RRCR0 RR_CLK_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_CLK_SEL (1)
/* @brief Has RRCR0 RR_TRG_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_TRG_SEL (1)
/* @brief Has RRCR0 RR_SAMPLE_CNT bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_SAMPLE_CNT (1)
/* @brief Has RRCR0 RR_SAMPLE_THRESHOLD bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_SAMPLE_THRESHOLD (1)
/* @brief Has CCR2 INPSEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR2_INPSEL (0)
/* @brief Has CCR2 INMSEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR2_INMSEL (0)
/* @brief Has CCR2 CMP_NPMD bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR2_CMP_NPMD (1)
/* @brief Has DCR DAC_HPMD bitfield. */
#define FSL_FEATURE_LPCMP_HAS_DCR_DAC_HPMD (1)
/* @brief Has CCR0 LINKEN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR0_LINKEN (0)
/* @brief Has RRCR2 register. */
#define FSL_FEATURE_LPCMP_HAS_RRCR2 (1)
/* @brief Has CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR0_CMP_STOP_EN (1)
/* @brief CMP instance support CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_INSTANCE_SUPPORT_CCR0_CMP_STOP_ENn(x) (1)

/* CRC module features */

/* @brief Has data register with name CRC */
#define FSL_FEATURE_CRC_HAS_CRC_REG (0)

/* CTIMER module features */

/* @brief CTIMER has no capture channel. */
#define FSL_FEATURE_CTIMER_HAS_NO_INPUT_CAPTURE (0)
/* @brief CTIMER has no capture 2 interrupt. */
#define FSL_FEATURE_CTIMER_HAS_NO_IR_CR2INT (0)
/* @brief CTIMER capture 3 interrupt. */
#define FSL_FEATURE_CTIMER_HAS_IR_CR3INT (1)
/* @brief Has CTIMER CCR_CAP2 (register bits CCR[CAP2RE][CAP2FE][CAP2I]. */
#define FSL_FEATURE_CTIMER_HAS_NO_CCR_CAP2 (0)
/* @brief Has CTIMER CCR_CAP3 (register bits CCR[CAP3RE][CAP3FE][CAP3I]). */
#define FSL_FEATURE_CTIMER_HAS_CCR_CAP3 (1)
/* @brief CTIMER Has register MSR */
#define FSL_FEATURE_CTIMER_HAS_MSR (1)

/* LPDAC module features */

/* @brief FIFO size. */
#define FSL_FEATURE_LPDAC_FIFO_SIZE (16)
/* @brief Has OPAMP as buffer, speed control signal (bitfield GCR[BUF_SPD_CTRL]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_BUF_SPD_CTRL (1)
/* @brief Buffer Enable(bitfield GCR[BUF_EN]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_BUF_EN (1)
/* @brief RCLK cycles before data latch(bitfield GCR[LATCH_CYC]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_LATCH_CYC (1)
/* @brief VREF source number. */
#define FSL_FEATURE_ANALOG_NUM_OF_VREF_SRC (3)
/* @brief Has internal reference current options. */
#define FSL_FEATURE_LPDAC_HAS_INTERNAL_REFERENCE_CURRENT (1)
/* @brief Support Period trigger mode DAC (bitfield IER[PTGCOCO_IE]). */
#define FSL_FEATURE_LPDAC_HAS_PERIODIC_TRIGGER_MODE (1)
/* @brief Optional Enable(bitfield GCR[DAC_OPTION_EN]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_DAC_OPTION_EN (0)
/* @brief Has no Internal PTAT Current Reference Select (bitfield GCR[IREF_PTAT_EXT_SEL]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_IREF_PTAT_EXT_SEL (1)
/* @brief Internal Current Select (bitfield GCR[IREF_INT_SEL]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_IREF_INT_SEL (0)
/* @brief Internal Current Trim Register (bitfield GCR[IREF_INT_TRIM]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_IREF_INT_TRIM (0)

/* EDMA module features */

/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (12)
/* @brief If 8 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_8_BYTES_TRANSFER (1)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (1)
/* @brief If 16 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER (1)
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (1)
/* @brief If 64 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_64_BYTES_TRANSFER (1)
/* @brief If channel clock controlled independently */
#define FSL_FEATURE_EDMA_CHANNEL_HAS_OWN_CLOCK_GATE (1)
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_128_BYTES_TRANSFER (1)
/* @brief Number of channel for each EDMA instance, (only defined for soc with different channel numbers for difference instance) */
#define FSL_FEATURE_EDMA_INSTANCE_CHANNELn(x) \
    (((x) == DMA1) ? (4) : \
    (((x) == DMA0) ? (12) : (-1)))
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_INSTANCE_SUPPORT_128_BYTES_TRANSFERn(x) (1)
/* @brief Has no register bit fields MP_CSR[EBW]. */
#define FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EBW (1)
/* @brief Has register CH_CSR. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_CONFIG (1)
/* @brief If dma has common clock gate */
#define FSL_FEATURE_EDMA_HAS_COMMON_CLOCK_GATE (0)
/* @brief Has channel mux */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MUX (1)
/* @brief If dma channel IRQ support parameter */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL_IRQ_ENTRY_SUPPORT_PARAMETER (0)
/* @brief Instance has channel mux */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_MUXn(x) (1)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_HAS_ERRATA_51327 (0)
/* @brief Has register CH_SBR. */
#define FSL_FEATURE_EDMA_HAS_SBR (1)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_ERRATA_51327n(x) (0)
/* @brief Has no register bit fields CH_SBR[ATTR]. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_ATTR (1)
/* @brief Has register bit fields MP_CSR[GMRC]. */
#define FSL_FEATURE_EDMA_HAS_GLOBAL_MASTER_ID_REPLICATION (1)
/* @brief Has register bit field CH_CSR[SWAP]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SWAP_SIZE (0)
/* @brief Whether instance has prot register. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_PROT_REGISTERn(x) (0)
/* @brief Instance has register bit field CH_CSR[SWAP]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_SWAP_SIZEn(x) (0)
/* @brief Whether instance has MP channel mux. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_MP_CHANNEL_MUXn(x) (0)
/* @brief Has register bit field CH_SBR[INSTR]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_ACCESS_TYPE (0)
/* @brief Instance has register bit field CH_SBR[INSTR]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_ACCESS_TYPEn(x) (0)
/* @brief Has register bit fields CH_MATTR[WCACHE], CH_MATTR[RCACHE]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MEMORY_ATTRIBUTE (0)
/* @brief Instance has register CH_MATTR. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_MEMORY_ATTRIBUTEn(x) (0)
/* @brief Has register bit field CH_CSR[SIGNEXT]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SIGN_EXTENSION (0)
/* @brief Instance Has register bit field CH_CSR[SIGNEXT]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_SIGN_EXTENSIONn(x) (0)
/* @brief Has register bit field TCD_CSR[BWC]. */
#define FSL_FEATURE_EDMA_HAS_BANDWIDTH (1)
/* @brief Instance has register bit field TCD_CSR[BWC]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_BANDWIDTHn(x) (1)
/* @brief Has register bit fields TCD_CSR[TMC]. */
#define FSL_FEATURE_EDMA_HAS_TRANSFER_MODE (0)
/* @brief Instance has register bit fields TCD_CSR[TMC]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_TRANSFER_MODEn(x) (0)
/* @brief Has no register bit fields CH_SBR[SEC]. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_SEC (0)
/* @brief edma5 has different tcd type. */
#define FSL_FEATURE_EDMA_TCD_TYPEn(x) (0)
/* @brief Number of DMA channels with asynchronous request capability. */
#define FSL_FEATURE_EDMA_ASYNCHRO_REQUEST_CHANNEL_COUNT (12)

/* EWM module features */

/* @brief Has clock select (register CLKCTRL). */
#define FSL_FEATURE_EWM_HAS_CLOCK_SELECT (1)
/* @brief Has clock prescaler (register CLKPRESCALER). */
#define FSL_FEATURE_EWM_HAS_PRESCALER (1)

/* FLEXIO module features */

/* @brief FLEXIO support reset from RSTCTL */
#define FSL_FEATURE_FLEXIO_HAS_RESET (0)
/* @brief Has Shifter Status Register (FLEXIO_SHIFTSTAT) */
#define FSL_FEATURE_FLEXIO_HAS_SHIFTER_STATUS (1)
/* @brief Has Pin Data Input Register (FLEXIO_PIN) */
#define FSL_FEATURE_FLEXIO_HAS_PIN_STATUS (1)
/* @brief Has Shifter Buffer N Nibble Byte Swapped Register (FLEXIO_SHIFTBUFNBSn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_NIBBLE_BYTE_SWAP (1)
/* @brief Has Shifter Buffer N Half Word Swapped Register (FLEXIO_SHIFTBUFHWSn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_HALF_WORD_SWAP (1)
/* @brief Has Shifter Buffer N Nibble Swapped Register (FLEXIO_SHIFTBUFNISn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_NIBBLE_SWAP (1)
/* @brief Supports Shifter State Mode (FLEXIO_SHIFTCTLn[SMOD]) */
#define FSL_FEATURE_FLEXIO_HAS_STATE_MODE (1)
/* @brief Supports Shifter Logic Mode (FLEXIO_SHIFTCTLn[SMOD]) */
#define FSL_FEATURE_FLEXIO_HAS_LOGIC_MODE (1)
/* @brief Supports paralle width (FLEXIO_SHIFTCFGn[PWIDTH]) */
#define FSL_FEATURE_FLEXIO_HAS_PARALLEL_WIDTH (1)
/* @brief Reset value of the FLEXIO_VERID register */
#define FSL_FEATURE_FLEXIO_VERID_RESET_VALUE (0x2010003)
/* @brief Reset value of the FLEXIO_PARAM register */
#define FSL_FEATURE_FLEXIO_PARAM_RESET_VALUE (0x4200404)
/* @brief Flexio DMA request base channel */
#define FSL_FEATURE_FLEXIO_DMA_REQUEST_BASE_CHANNEL (0)
/* @brief Represent the bit width of the TIMDCE field (FLEXIO_TIMCFGLn[TIMDEC]) */
#define FSL_FEATURE_FLEXIO_TIMCFG_TIMDCE_FIELD_WIDTH (3)
/* @brief Has pin input output related registers */
#define FSL_FEATURE_FLEXIO_HAS_PIN_REGISTER (1)
/* @brief Has DOZEN bit(CTRL[DOZEN]) */
#define FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT (1)

/* FLEXSPI module features */

/* @brief FlexSPI AHB buffer count */
#define FSL_FEATURE_FLEXSPI_AHB_BUFFER_COUNTn(x) (8)
/* @brief FlexSPI has no data learn. */
#define FSL_FEATURE_FLEXSPI_HAS_NO_DATA_LEARN (0)
/* @brief There is AHBBUSERROREN bit in INTEN register. */
#define FSL_FEATURE_FLEXSPI_HAS_INTEN_AHBBUSERROREN (0)
/* @brief There is CLRAHBTX_RXBUF bit in AHBCR register. */
#define FSL_FEATURE_FLEXSPI_HAS_AHBCR_CLRAHBTX_RXBUF (1)
/* @brief FLEXSPI has no IP parallel mode. */
#define FSL_FEATURE_FLEXSPI_HAS_NO_IP_PARALLEL_MODE (0)
/* @brief FLEXSPI has no AHB parallel mode. */
#define FSL_FEATURE_FLEXSPI_HAS_NO_AHB_PARALLEL_MODE (0)
/* @brief FLEXSPI support address shift. */
#define FSL_FEATURE_FLEXSPI_SUPPORT_ADDRESS_SHIFT (0)
/* @brief FlexSPI has no MCR0 ARDFEN bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_ARDFEN (1)
/* @brief FlexSPI has no MCR0 ATDFEN bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_ATDFEN (1)
/* @brief FlexSPI has no MCR0 COMBINATIONEN bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_COMBINATIONEN (0)
/* @brief FlexSPI has no FLSHCR4 WMENB bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_FLSHCR4_WMENB (0)
/* @brief FlexSPI has no STS0 DATALEARNPHASEB bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_STS0_DATALEARNPHASEB (0)
/* @brief FlexSPI has no MCR2 SCKBDIFFOPT bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_MCR2_SCKBDIFFOPT (0)
/* @brief FlexSPI AHB RX buffer size (byte) */
#define FSL_FEATURE_FLEXSPI_AHB_RX_BUFFER_SIZEn(x) (2048)
/* @brief FlexSPI Array Length */
#define FSL_FEATURE_FLEXSPI_ARRAY_LEN (1)
/* @brief FlexSPI has no STS2 BSLVLOCK bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_STS2_BSLVLOCK (0)
/* @brief FlexSPI has no STS2 BREFLOCK bit */
#define FSL_FEATURE_FLEXSPI_HAS_NO_STS2_BREFLOCK (0)
/* @brief FlexSPI supports Port A only, do not support Port B. */
#define FSL_FEATURE_FLEXSPI_NO_SUPPORT_PORTB (0)
/* @brief FlexSPI LUTKEY is read only. */
#define FSL_FEATURE_FLEXSPI_LUTKEY_IS_RO (0)
/* @brief FlexSPI0 and FlexSPI1 have shared IRQ */
#define FSL_FEATURE_FLEXSPI_HAS_SHARED_IRQ0_IRQ1 (0)
/* @brief FlexSPI DMA needs multiple DES to transfer */
#define FSL_FEATURE_FLEXSPI_DMA_MULTIPLE_DES (1)
/* @brief FlexSPI uses min DQS delay */
#define FSL_FEATURE_FLEXSPI_DQS_DELAY_MIN (0)
/* @brief FlexSPI support sample clock source selection */
#define FSL_FEATURE_FLEXSPI_SUPPORT_SEPERATE_RXCLKSRC_PORTB (0)
/* @brief FlexSPI support sample clock source or source_b selection */
#define FSL_FEATURE_FLEXSPI_SUPPORT_RXCLKSRC_DIFF (0)
/* @brief FlexSPI IPED REGION COUNT */
#define FSL_FEATURE_FLEXSPI_IPED_REGION_COUNT (7)
/* @brief FlexSPI Has ERRATA052733 */
#define FSL_FEATURE_FLEXSPI_HAS_ERRATA_052733 (0)
/* @brief FlexSPI Has ERRATA051426 */
#define FSL_FEATURE_FLEXSPI_HAS_ERRATA_051426 (0)
/* @brief FlexSPI has AHBCR RESUMEDISABLE bit */
#define FSL_FEATURE_FLEXSPI_HAS_RESUMEDISABLE_BIT_CONFIG_SUPPORT (1)

/* FMU module features */

/* @brief Is the flash module msf1? */
#define FSL_FEATURE_FSL_FEATURE_FLASH_IS_MSF1 (1)
/* @brief P-Flash block count. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT (1)
/* @brief P-Flash block0 start address. */
#define FSL_FEATURE_FLASH_PFLASH_START_ADDRESS (0x00000000U)
/* @brief P-Flash block0 size. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE (0x200000U)
/* @brief P-Flash sector size. */
#define FSL_FEATURE_FLASH_PFLASH_SECTOR_SIZE (0x2000U)
/* @brief P-Flash page size. */
#define FSL_FEATURE_FLASH_PFLASH_PAGE_SIZE (128)
/* @brief P-Flash phrase size. */
#define FSL_FEATURE_FLASH_PFLASH_PHRASE_SIZE (16)
/* @brief Has IFR memory. */
#define FSL_FEATURE_FLASH_HAS_IFR (1)
/* @brief flash BLOCK0 IFR0 start address. */
#define FSL_FEATURE_FLASH_IFR0_START_ADDRESS (0x01000000u)
/* @brief flash BLOCK0 IFR1 start address. */
#define FSL_FEATURE_FLASH_IFR1_START_ADDRESS (0x01100000U)
/* @brief flash block IFR0 size. */
#define FSL_FEATURE_FLASH_IFR0_SIZE (0x10000U)
/* @brief flash block IFR1 size. */
#define FSL_FEATURE_FLASH_IFR1_SIZE (0x4000U)
/* @brief IFR sector size. */
#define FSL_FEATURE_FLASH_IFR_SECTOR_SIZE (0x2000U)
/* @brief IFR page size. */
#define FSL_FEATURE_FLASH_IFR_PAGE_SIZE (128)

/* FREQME module features */

/* @brief FREQME instance support REF and TAR register. */
#define FSL_FEATURE_FREQME_HAS_CLOCK_SOURCE_SELECT (0)
/* @brief FREQME frequency calculation formula. 0: CTRL_R[RESULT] - 2; 1: CTRL_R[RESULT] + 1. */
#define FSL_FEATURE_FREQME_RESULT_CALCULATION_MODE (0)

/* GPIO module features */

/* @brief Has GPIO attribute checker register (GACR). */
#define FSL_FEATURE_GPIO_HAS_ATTRIBUTE_CHECKER (0)
/* @brief GPIO registers width */
#define FSL_FEATURE_GPIO_REGISTERS_WIDTH (32)
/* @brief Has GPIO version ID register (VERID). */
#define FSL_FEATURE_GPIO_HAS_VERSION_INFO_REGISTER (1)
/* @brief Has secure/non-secure access protection registers (LOCK, PCNS, PCNP, ICNS, ICNP). */
#define FSL_FEATURE_GPIO_HAS_SECURE_PRIVILEGE_CONTROL (1)
/* @brief Has GPIO port input disable register (PIDR). */
#define FSL_FEATURE_GPIO_HAS_PORT_INPUT_CONTROL (1)
/* @brief Has GPIO interrupt/DMA request/trigger output selection. */
#define FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT (1)

/* I3C module features */

/* @brief Has TERM bitfile in MERRWARN register. */
#define FSL_FEATURE_I3C_HAS_NO_MERRWARN_TERM (0)
/* @brief SOC has no reset driver. */
#define FSL_FEATURE_I3C_HAS_NO_RESET (0)
/* @brief Use fixed BAMATCH count, do not provide editable BAMATCH. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_BAMATCH (0)
/* @brief Register SCONFIG do not have IDRAND bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_IDRAND (1)
/* @brief Register SCONFIG has HDROK bitfield. */
#define FSL_FEATURE_I3C_HAS_HDROK (0)
/* @brief Has ERRATA_051617. */
#define FSL_FEATURE_I3C_HAS_ERRATA_051617 (0)
/* @brief SOC does not support slave IBI/MR/HJ */
#define FSL_FEATURE_I3C_HAS_NO_SLAVE_IBI_MR_HJ (0)
/* @brief Has ERRATA_052086. */
#define FSL_FEATURE_I3C_HAS_ERRATA_052086 (0)
/* @brief Has ERRATA_052123. */
#define FSL_FEATURE_I3C_HAS_ERRATA_052123 (0)
/* @brief Has IBI bytes. */
#define FSL_FEATURE_I3C_HAS_IBI_PAYLOAD_SIZE_OPTIONAL_BYTE (0)
/* @brief Has SCL delay after START. */
#define FSL_FEATURE_I3C_HAS_START_SCL_DELAY (1)
/* @brief Has no the master write data register for DMA. */
#define FSL_FEATURE_I3C_HAS_NO_MASTER_DMA_WDATA_REG (0)

/* LPI2C module features */

/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPI2C_FIFO_SIZEn(x) (4)
/* @brief Has dedicated interrupt for master and slave. */
#define FSL_FEATURE_LPI2C_HAS_ROLE_SPLIT_IRQ (0)
/* @brief Belong to LPFLEXCOMM */
#define FSL_FEATURE_LPI2C_IS_LPFLEXCOMM (0)

/* LPSPI module features */

/* @brief Capacity (number of entries) of the transmit/receive FIFO. */
#define FSL_FEATURE_LPSPI_FIFO_SIZEn(x) (4)
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPSPI_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Has CCR1 (related to existence of registers CCR1). */
#define FSL_FEATURE_LPSPI_HAS_CCR1 (1)
/* @brief Has no PCSCFG bit in CFGR1 register. */
#define FSL_FEATURE_LPSPI_HAS_NO_PCSCFG (0)
/* @brief Has no WIDTH bits in TCR register. */
#define FSL_FEATURE_LPSPI_HAS_NO_MULTI_WIDTH (0)
/* @brief Belong to LPFLEXCOMM */
#define FSL_FEATURE_LPSPI_IS_LPFLEXCOMM (0)

/* LPTMR module features */

/* @brief Has shared interrupt handler with another LPTMR module. */
#define FSL_FEATURE_LPTMR_HAS_SHARED_IRQ_HANDLER (0)
/* @brief Whether LPTMR counter is 32 bits width. */
#define FSL_FEATURE_LPTMR_CNR_WIDTH_IS_32B (1)
/* @brief Has timer DMA request enable (register bit CSR[TDRE]). */
#define FSL_FEATURE_LPTMR_HAS_CSR_TDRE (1)
/* @brief Do not has prescaler clock source 0. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_0_SUPPORT (1)
/* @brief Do not has prescaler clock source 1. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_1_SUPPORT (0)
/* @brief Do not has prescaler clock source 2. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_2_SUPPORT (1)
/* @brief Do not has prescaler clock source 3. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_3_SUPPORT (0)

/* LPUART module features */

/* @brief Has receive FIFO overflow detection (bit field CFIFO[RXOFE]). */
#define FSL_FEATURE_LPUART_HAS_IRQ_EXTENDED_FUNCTIONS (0)
/* @brief Has low power features (can be enabled in wait mode via register bit C1[DOZEEN] or CTRL[DOZEEN] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_LOW_POWER_UART_SUPPORT (1)
/* @brief Has extended data register ED (or extra flags in the DATA register if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_EXTENDED_DATA_REGISTER_FLAGS (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPUART_HAS_FIFO (1)
/* @brief Has 32-bit register MODIR */
#define FSL_FEATURE_LPUART_HAS_MODIR (1)
/* @brief Hardware flow control (RTS, CTS) is supported. */
#define FSL_FEATURE_LPUART_HAS_MODEM_SUPPORT (1)
/* @brief Infrared (modulation) is supported. */
#define FSL_FEATURE_LPUART_HAS_IR_SUPPORT (1)
/* @brief 2 bits long stop bit is available. */
#define FSL_FEATURE_LPUART_HAS_STOP_BIT_CONFIG_SUPPORT (1)
/* @brief If 10-bit mode is supported. */
#define FSL_FEATURE_LPUART_HAS_10BIT_DATA_SUPPORT (1)
/* @brief If 7-bit mode is supported. */
#define FSL_FEATURE_LPUART_HAS_7BIT_DATA_SUPPORT (1)
/* @brief Baud rate fine adjustment is available. */
#define FSL_FEATURE_LPUART_HAS_BAUD_RATE_FINE_ADJUST_SUPPORT (0)
/* @brief Baud rate oversampling is available (has bit fields C4[OSR], C5[BOTHEDGE], C5[RESYNCDIS] or BAUD[OSR], BAUD[BOTHEDGE], BAUD[RESYNCDIS] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_BAUD_RATE_OVER_SAMPLING_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FSL_FEATURE_LPUART_HAS_RX_RESYNC_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FSL_FEATURE_LPUART_HAS_BOTH_EDGE_SAMPLING_SUPPORT (1)
/* @brief Peripheral type. */
#define FSL_FEATURE_LPUART_IS_SCI (1)
/* @brief Supports two match addresses to filter incoming frames. */
#define FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING (1)
/* @brief Has transmitter/receiver DMA enable bits C5[TDMAE]/C5[RDMAE] (or BAUD[TDMAE]/BAUD[RDMAE] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_DMA_ENABLE (1)
/* @brief Has transmitter/receiver DMA select bits C4[TDMAS]/C4[RDMAS], resp. C5[TDMAS]/C5[RDMAS] if IS_SCI = 0. */
#define FSL_FEATURE_LPUART_HAS_DMA_SELECT (0)
/* @brief Data character bit order selection is supported (bit field S2[MSBF] or STAT[MSBF] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_BIT_ORDER_SELECT (1)
/* @brief Has smart card (ISO7816 protocol) support and no improved smart card support. */
#define FSL_FEATURE_LPUART_HAS_SMART_CARD_SUPPORT (0)
/* @brief Has improved smart card (ISO7816 protocol) support. */
#define FSL_FEATURE_LPUART_HAS_IMPROVED_SMART_CARD_SUPPORT (0)
/* @brief Has local operation network (CEA709.1-B protocol) support. */
#define FSL_FEATURE_LPUART_HAS_LOCAL_OPERATION_NETWORK_SUPPORT (0)
/* @brief Has 32-bit registers (BAUD, STAT, CTRL, DATA, MATCH, MODIR) instead of 8-bit (BDH, BDL, C1, S1, D, etc.). */
#define FSL_FEATURE_LPUART_HAS_32BIT_REGISTERS (1)
/* @brief Lin break detect available (has bit BAUD[LBKDIE]). */
#define FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT (1)
/* @brief UART stops in Wait mode available (has bit C1[UARTSWAI]). */
#define FSL_FEATURE_LPUART_HAS_WAIT_MODE_OPERATION (0)
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPUART_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Has separate RX and TX interrupts. */
#define FSL_FEATURE_LPUART_HAS_SEPARATE_RX_TX_IRQ (0)
/* @brief Has LPAURT_PARAM. */
#define FSL_FEATURE_LPUART_HAS_PARAM (1)
/* @brief Has LPUART_VERID. */
#define FSL_FEATURE_LPUART_HAS_VERID (1)
/* @brief Has LPUART_GLOBAL. */
#define FSL_FEATURE_LPUART_HAS_GLOBAL (1)
/* @brief Has LPUART_PINCFG. */
#define FSL_FEATURE_LPUART_HAS_PINCFG (1)
/* @brief Belong to LPFLEXCOMM */
#define FSL_FEATURE_LPUART_IS_LPFLEXCOMM (0)
/* @brief Has register MODEM Control. */
#define FSL_FEATURE_LPUART_HAS_MCR (0)
/* @brief Has register Half Duplex Control. */
#define FSL_FEATURE_LPUART_HAS_HDCR (0)
/* @brief Has register Timeout. */
#define FSL_FEATURE_LPUART_HAS_TIMEOUT (0)
/* @brief UART support swap TX and RX (has bit CTRL[SWAP]). */
#define FSL_FEATURE_LPUART_HAS_CTRL_SWAP (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPUART_FIFO_SIZEn(x) (4)
/* @brief UART support receive rts configuration (has bit MODIR[RTSWATER]). */
#define FSL_FEATURE_LPUART_HAS_MODIR_RTSWATER (1)

/* TRDC module features */

/* @brief Process master count. */
#define FSL_FEATURE_TRDC_PROCESSOR_MASTER_COUNT (2)
/* @brief TRDC instance has PID configuration or not. */
#define FSL_FEATURE_TRDC_INSTANCE_HAS_PID_CONFIGURATIONn(x) (0)
/* @brief TRDC instance has MBC. */
#define FSL_FEATURE_TRDC_HAS_MBC (1)
/* @brief TRDC instance has MRC. */
#define FSL_FEATURE_TRDC_HAS_MRC (0)
/* @brief TRDC instance has TRDC_CR. */
#define FSL_FEATURE_TRDC_HAS_GENERAL_CONFIG (0)
/* @brief TRDC instance has MDA_Wx_y_DFMT. */
#define FSL_FEATURE_TRDC_HAS_DOMAIN_ASSIGNMENT (0)
/* @brief TRDC instance has TRDC_FDID. */
#define FSL_FEATURE_TRDC_HAS_DOMAIN_ERROR (0)
/* @brief TRDC instance has TRDC_FLW_CTL. */
#define FSL_FEATURE_TRDC_HAS_FLW (0)
/* @brief TRDC DERRLOC.MBCINST uses flat one-bit-per-MBC-instance encoding (bit N = MBC[N]). Other devices use 4-bits-per-MBC encoding (bit 4i+j = MBC[i] SLV[j]). */
#define FSL_FEATURE_TRDC_DERRLOC_MBCINST_FLAT_ENCODING (0)

/* OSTIMER module features */

/* @brief Has binary encoded value in counter register. */
#define FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER (0)

/* PORT module features */

/* @brief Has control lock (register bit PCR[LK]). */
#define FSL_FEATURE_PORT_HAS_PIN_CONTROL_LOCK (1)
/* @brief Has open drain control (register bit PCR[ODE]). */
#define FSL_FEATURE_PORT_HAS_OPEN_DRAIN (1)
/* @brief Has digital filter (registers DFER, DFCR and DFWR). */
#define FSL_FEATURE_PORT_HAS_DIGITAL_FILTER (0)
/* @brief Has DMA request (register bit field PCR[IRQC] or ICR[IRQC] values). */
#define FSL_FEATURE_PORT_HAS_DMA_REQUEST (0)
/* @brief Has pull resistor selection available. */
#define FSL_FEATURE_PORT_HAS_PULL_SELECTION (1)
/* @brief Has pull resistor enable (register bit PCR[PE]). */
#define FSL_FEATURE_PORT_HAS_PULL_ENABLE (1)
/* @brief Has slew rate control (register bit PCR[SRE]). */
#define FSL_FEATURE_PORT_HAS_SLEW_RATE (1)
/* @brief Has passive filter (register bit field PCR[PFE]). */
#define FSL_FEATURE_PORT_HAS_PASSIVE_FILTER (1)
/* @brief Do not has interrupt control (register ISFR). */
#define FSL_FEATURE_PORT_HAS_NO_INTERRUPT (1)
/* @brief Has pull value (register bit field PCR[PV]). */
#define FSL_FEATURE_PORT_PCR_HAS_PULL_VALUE (1)
/* @brief Has drive strength1 control (register bit PCR[DSE1]). */
#define FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH1 (1)
/* @brief Has version ID register (register VERID). */
#define FSL_FEATURE_PORT_HAS_VERSION_INFO_REGISTER (1)
/* @brief Has voltage range control (register bit CONFIG[RANGE]). */
#define FSL_FEATURE_PORT_SUPPORT_DIFFERENT_VOLTAGE_RANGE (1)
/* @brief Has EFT detect (registers EDFR, EDIER and EDCR). */
#define FSL_FEATURE_PORT_SUPPORT_EFT (0)
/* @brief Function 0 is GPIO. */
#define FSL_FEATURE_PORT_PCR_MUX_GPIO (0)
/* @brief Has drive strength control (register bit PCR[DSE]). */
#define FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH (1)
/* @brief Defines width of PCR[MUX] field. */
#define FSL_FEATURE_PORT_PCR_MUX_WIDTH (4)
/* @brief Has dedicated interrupt vector. */
#define FSL_FEATURE_PORT_HAS_INTERRUPT_VECTOR (1)
/* @brief Has independent interrupt control(register ICR). */
#define FSL_FEATURE_PORT_HAS_INDEPENDENT_INTERRUPT_CONTROL (0)
/* @brief Has multiple pin IRQ configuration (register GICLR and GICHR). */
#define FSL_FEATURE_PORT_HAS_MULTIPLE_IRQ_CONFIG (0)
/* @brief Has Input Buffer Enable (register bit field PCR[IBE]). */
#define FSL_FEATURE_PORT_HAS_INPUT_BUFFER (1)
/* @brief Has Invert Input (register bit field PCR[INV]). */
#define FSL_FEATURE_PORT_HAS_INVERT_INPUT (1)
/* @brief Defines whether PCR[IRQC] bit-field has flag states. */
#define FSL_FEATURE_PORT_HAS_IRQC_FLAG (0)
/* @brief Defines whether PCR[IRQC] bit-field has trigger states. */
#define FSL_FEATURE_PORT_HAS_IRQC_TRIGGER (0)

/* RTC module features */

/* @brief Has Tamper Direction Register support. */
#define FSL_FEATURE_RTC_HAS_TAMPER_DIRECTION (0)
/* @brief Has Tamper Queue Status and Control Register support. */
#define FSL_FEATURE_RTC_HAS_TAMPER_QUEUE (0)
/* @brief Has RTC Tamper 23 Filter Configuration Register support. */
#define FSL_FEATURE_RTC_HAS_FILTER23_CFG (0)
/* @brief Has WAKEUP_MODE bitfile in CTRL2 register. */
#define FSL_FEATURE_RTC_HAS_NO_CTRL2_WAKEUP_MODE (1)
/* @brief Has CLK_SEL bitfile in CTRL register. */
#define FSL_FEATURE_RTC_HAS_CLOCK_SELECT (1)
/* @brief Has CLKO_DIS bitfile in CTRL register. */
#define FSL_FEATURE_RTC_HAS_CLOCK_OUTPUT_DISABLE (1)
/* @brief Has No Tamper in RTC. */
#define FSL_FEATURE_RTC_HAS_NO_TAMPER_FEATURE (1)
/* @brief Has CPU_LOW_VOLT bitfile in STATUS register. */
#define FSL_FEATURE_RTC_HAS_NO_CPU_LOW_VOLT_FLAG (1)
/* @brief Has RST_SRC bitfile in STATUS register. */
#define FSL_FEATURE_RTC_HAS_NO_RST_SRC_FLAG (1)
/* @brief Has GP_DATA_REG register. */
#define FSL_FEATURE_RTC_HAS_NO_GP_DATA_REG (1)
/* @brief Has TIMER_STB_MASK bitfile in CTRL register. */
#define FSL_FEATURE_RTC_HAS_NO_TIMER_STB_MASK (1)
/* @brief Has RTC Tamper 45 Filter Configuration Register support */
#define FSL_FEATURE_RTC_HAS_FILTER45_CFG (0)
/* @brief Has RTC Tamper 67 Filter Configuration Register support */
#define FSL_FEATURE_RTC_HAS_FILTER67_CFG (0)
/* @brief Has RTC Minutes Count Down Timer Register support */
#define FSL_FEATURE_RTC_HAS_MINUTES_TIMER_FEATURE (0)
/* @brief Has RTC BCD mode support */
#define FSL_FEATURE_RTC_HAS_BCD_MODE (0)

/* SPC module features */

/* @brief Has DCDC. */
#define FSL_FEATURE_MCX_SPC_HAS_DCDC (0)
/* @brief Has SYS LDO. */
#define FSL_FEATURE_MCX_SPC_HAS_SYS_LDO (0)
/* @brief Has IOVDD_LVDF. */
#define FSL_FEATURE_MCX_SPC_HAS_IOVDD_VD (0)
/* @brief Has COREVDD_HVDF. */
#define FSL_FEATURE_MCX_SPC_HAS_COREVDD_HVD (1)
/* @brief Has CORELDO_VDD_DS. */
#define FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS (1)
/* @brief Has LPBUFF_EN. */
#define FSL_FEATURE_MCX_SPC_HAS_LPBUFF_EN_BIT (1)
/* @brief Has COREVDD_IVS_EN. */
#define FSL_FEATURE_MCX_SPC_HAS_COREVDD_IVS_EN_BIT (0)
/* @brief Has SWITCH_STATE. */
#define FSL_FEATURE_MCX_SPC_HAS_SWITCH_STATE_BIT (0)
/* @brief Has SRAMRETLDO. */
#define FSL_FEATURE_MCX_SPC_HAS_SRAMRETLDO_REG (0)
/* @brief Has CFG register. */
#define FSL_FEATURE_MCX_SPC_HAS_CFG_REG (0)
/* @brief Has SRAMLDO_DPD_ON. */
#define FSL_FEATURE_MCX_SPC_HAS_SRAMLDO_DPD_ON_BIT (0)
/* @brief Has CNTRL register. */
#define FSL_FEATURE_MCX_SPC_HAS_CNTRL_REG (1)
/* @brief Has DPDOWN_PULLDOWN_DISABLE. */
#define FSL_FEATURE_MCX_SPC_HAS_DPDOWN_PULLDOWN_DISABLE_BIT (1)
/* @brief Not have glitch detect. */
#define FSL_FEATURE_MCX_SPC_HAS_NO_GLITCH_DETECT (0)
/* @brief Has BLEED_EN. */
#define FSL_FEATURE_MCX_SPC_HAS_DCDC_CFG_BLEED_EN (0)
/* @brief Has Power Request Status Flag. */
#define FSL_FEATURE_MCX_SPC_HAS_PD_STATUS_PWR_REQ_STATUS_BIT (1)
/* @brief Support overdrive voltage. */
#define FSL_FEATURE_MCX_SPC_SUPPORT_OVERDRIVE_VOLTAGE (1)
/* @brief Has SPC_LP_REQ bit in SC register. */
#define FSL_FEATURE_MCX_SPC_HAS_SC_SPC_LP_REQ_BIT (1)
/* @brief Has SPC_LP_MODE bit in SC register. */
#define FSL_FEATURE_MCX_SPC_HAS_SC_SPC_LP_MODE_BIT (1)
/* @brief Has SRAMCTL register. */
#define FSL_FEATURE_MCX_SPC_HAS_SRAMCTL_REG (1)
/* @brief Has PD_STATUS register. */
#define FSL_FEATURE_MCX_SPC_HAS_PD_STATUS_REG (1)
/* @brief Has SRAMRETLDO_REFTRIM register. */
#define FSL_FEATURE_MCX_SPC_HAS_SRAMRETLDO_REFTRIM_REG (0)
/* @brief Has LVSEL bitfield in VD_IO_CFG register. */
#define FSL_FEATURE_MCX_SPC_HAS_VD_IO_CFG_LVSEL (0)
/* @brief Has high-voltage detect on IO VDD. */
#define FSL_FEATURE_MCX_SPC_HAS_IOVDD_HVD (0)

/* SYSCON module features */

/* @brief Flash page size in bytes */
#define FSL_FEATURE_SYSCON_FLASH_PAGE_SIZE_BYTES (128)
/* @brief Flash sector size in bytes */
#define FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES (8192)
/* @brief Flash size in bytes */
#define FSL_FEATURE_SYSCON_FLASH_SIZE_BYTES (2097152)
/* @brief Support ROMAPI */
#define FSL_FEATURE_SYSCON_ROMAPI (1)
/* @brief ROMAPI tree address */
#define FSL_FEATURE_ROMAPI_BASE (0x03005FE0U)
/* @brief ROMAPI support IFR function */
#define FSL_FEATURE_ROMAPI_IFR (0)
/* @brief Powerlib API is different with other series devices */
#define FSL_FEATURE_POWERLIB_EXTEND (1)
/* @brief No OSTIMER register in PMC */
#define FSL_FEATURE_PMC_HAS_NO_OSTIMER_REG (1)
/* @brief Starter register discontinuous. */
#define FSL_FEATURE_SYSCON_STARTER_DISCONTINUOUS (1)
/* @brief Has parity miss (bitfield LPCAC_CTRL[PARITY_MISS_EN]). */
#define FSL_FEATURE_SYSCON_HAS_LPCAC_CTRL_PARITY_MISS_EN_BIT (0)
/* @brief Has parity error report (bitfield LPCAC_CTRL[PARITY_FAULT_EN]). */
#define FSL_FEATURE_SYSCON_HAS_LPCAC_CTRL_PARITY_FAULT_EN_BIT (0)

/* SysTick module features */

/* @brief Systick has external reference clock. */
#define FSL_FEATURE_SYSTICK_HAS_EXT_REF (0)
/* @brief Systick external reference clock is core clock divided by this value. */
#define FSL_FEATURE_SYSTICK_EXT_REF_CORE_DIV (0)

/* TRNG module features */

/* @brief TRNG does not support SCR4L. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_SCR4L (1)
/* @brief TRNG does not support SCR5L. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_SCR5L (1)
/* @brief TRNG does not support SCR6L. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_SCR6L (1)
/* @brief TRNG does not support PKRMAX. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_PKRMAX (1)
/* @brief TRNG does not support SAMP mode. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_MCTL_SAMP_MODE (1)
/* @brief TRNG does not support ACC. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_ACC (1)
/* @brief TRNG does not support SBLIM. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_SBLIM (1)
/* @brief TRNG supports reset control. */
#define FSL_FEATURE_TRNG_HAS_RSTCTL (0)
/* @brief TRNG does not support FOR_CLK mode. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_MCTL_FOR_CLK_MODE (1)
/* @brief TRNG supports dual oscillator mode. */
#define FSL_FEATURE_TRNG_HAS_DUAL_OSCILATORS (1)
/* @brief TRNG supports control pin. */
#define FSL_FEATURE_TRNG_HAS_CTRL_PIN (0)

/* TSI module features */

/* @brief TSI Version. */
#define FSL_FEATURE_TSI_VERSION (6U)
/* @brief Has channels selection reigster(Self-cap,Shield,Mutual TX or Mutual RX). */
#define FSL_FEATURE_TSI_HAS_CHANNEL_SEL (1)
/* @brief Has Self-cap mode channels selection reigster. */
#define FSL_FEATURE_TSI_HAS_SELF_SEL (1)
/* @brief Has Shield mode channels selection reigster. */
#define FSL_FEATURE_TSI_HAS_SHIELD_SEL (1)
/* @brief Has Mutual TX mode channels selection reigster. */
#define FSL_FEATURE_TSI_HAS_MUTUAL_TX_SEL (1)
/* @brief Has Mutual RX mode channels selection reigster. */
#define FSL_FEATURE_TSI_HAS_MUTUAL_RX_SEL (1)
/* @brief Has no bitfield SETCLK in GENCS register. */
#define FSL_FEATURE_TSI_HAS_NO_SETCLK (1)
/* @brief Do not has bitfield M_TX_USED in MUL register. */
#define FSL_FEATURE_TSI_HAS_NO_MUTUAL_TX_USED (1)
/* @brief Do not has bitfield S_CTRIM in CONFIG register. */
#define FSL_FEATURE_TSI_HAS_NO_S_CTRIM (1)
/* @brief Has bitfield CLK_SEL in GENCS register. */
#define FSL_FEATURE_TSI_HAS_CLK_SEL (1)
/* @brief DVOLT value option num. */
#define FSL_FEATURE_TSI_DVOLT_OPTION_NUM (15)
/* @brief Has SINC_BITFIELD in SINC register. */
#define FSL_FEATURE_TSI_HAS_SINC_SINC_BITFIELD (1)
/* @brief TSI Channel Count. */
#define FSL_FEATURE_TSI_CHANNEL_COUNT (70)

/* USBHS module features */

/* @brief EHCI module instance count */
#define FSL_FEATURE_USBHS_EHCI_COUNT (1)
/* @brief Number of endpoints supported */
#define FSL_FEATURE_USBHS_ENDPT_COUNT (8)
/* @brief If the USB controller support eUSB PHY */
#define FSL_FEATURE_USBHS_SUPPORT_EUSBn(x) (0)

/* USBPHY module features */

/* @brief USBPHY contain DCD analog module */
#define FSL_FEATURE_USBPHY_HAS_DCD_ANALOG (0)
/* @brief USBPHY has register TRIM_OVERRIDE_EN */
#define FSL_FEATURE_USBPHY_HAS_TRIM_OVERRIDE_EN (1)
/* @brief USBPHY is 28FDSOI */
#define FSL_FEATURE_USBPHY_28FDSOI (0)

/* UTICK module features */

/* @brief UTICK does not support power down configure. */
#define FSL_FEATURE_UTICK_HAS_NO_PDCFG (1)

/* VBAT module features */

/* @brief Has STATUS register */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUS_REG (1)
/* @brief Has TAMPER register */
#define FSL_FEATURE_MCX_VBAT_HAS_TAMPER_REG (0)
/* @brief Has BANDGAP register */
#define FSL_FEATURE_MCX_VBAT_HAS_BANDGAP_TIMER (1)
/* @brief Has LDOCTL register */
#define FSL_FEATURE_MCX_VBAT_HAS_LDOCTL_REG (1)
/* @brief Has OSCCTL register */
#define FSL_FEATURE_MCX_VBAT_HAS_OSCCTL_REG (1)
/* @brief Has SWICTL register */
#define FSL_FEATURE_MCX_VBAT_HAS_SWICTL_REG (1)
/* @brief Has CLKMON register */
#define FSL_FEATURE_MCX_VBAT_HAS_CLKMON_REG (0)
/* @brief Has FINE_AMP_GAIN bitfield in register OSCCTLA */
#define FSL_FEATURE_MCX_VBAT_HAS_OSCCTLA_FINE_AMP_GAIN_BIT (0)
/* @brief Has OSCCTLB register */
#define FSL_FEATURE_MCX_VBAT_HAS_B_SIDE_REG (0)
/* @brief Has OSCCTLA[MODE_EN] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_OSCCTLA_MODE_EN_BIT (1)
/* @brief Has OSCCFGA[CMP_TRIM] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_OSCCFGA_CMP_TRIM_BIT (1)
/* @brief Has OSCCFGA[DLY_TRIM] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_OSCCFGA_DLY_TRIM_BIT (1)
/* @brief Has OSCCFGA[CAP_TRIM] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_OSCCFGA_CAP_TRIM_BIT (1)
/* @brief Has STATUSA[WAKEUP_FLAG] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_WAKEUP_FLAG_BIT (1)
/* @brief Has STATUSA[TIMER0_FLAG] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_TIMER0_FLAG_BIT (1)
/* @brief Has STATUSA[TIMER1_FLAG] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_TIMER1_FLAG_BIT (1)
/* @brief Has STATUSA[LDO_RDY] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_LDO_RDY_BIT (1)
/* @brief Has STATUSA[IRQ0_DET] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_IRQ0_DET_BIT (1)
/* @brief Has STATUSA[IRQ1_DET] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_IRQ1_DET_BIT (1)
/* @brief Has STATUSA[IRQ2_DET] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_IRQ2_DET_BIT (1)
/* @brief Has STATUSA[IRQ3_DET] bitfield */
#define FSL_FEATURE_MCX_VBAT_HAS_STATUSA_IRQ3_DET_BIT (1)
/* @brief Has WAKENA register */
#define FSL_FEATURE_MCX_VBAT_HAS_WAKENA_REG (1)
/* @brief Has WAKECFG register */
#define FSL_FEATURE_MCX_VBAT_HAS_WAKECFG_REG (1)
/* @brief Has LOCKA register */
#define FSL_FEATURE_MCX_VBAT_HAS_LOCKA_REG (1)

/* VREF module features */

/* @brief Has chop oscillator (bit TRM[CHOPEN]) */
#define FSL_FEATURE_VREF_HAS_CHOP_OSC (0)
/* @brief Has second order curvature compensation (bit SC[ICOMPEN]) */
#define FSL_FEATURE_VREF_HAS_COMPENSATION (0)
/* @brief If high/low buffer mode supported */
#define FSL_FEATURE_VREF_MODE_LV_TYPE (0)
/* @brief Module has also low reference (registers VREFL/VREFH) */
#define FSL_FEATURE_VREF_HAS_LOW_REFERENCE (0)
/* @brief Has VREF_TRM4. */
#define FSL_FEATURE_VREF_HAS_TRM4 (0)
/* @brief Has bitfield LPBG_BUF_EN in CSR register. */
#define FSL_FEATURE_VREF_HAS_LOWPOWER_BUFFER (0)
/* @brief Has bitfield LPBGEN in CSR register. */
#define FSL_FEATURE_VREF_HAS_LPBGEN (0)
/* @brief Has bitfield IBIAS_EN in CSR register. */
#define FSL_FEATURE_VREF_HAS_IBIAS_EN (1)
/* @brief Has bitfield REFCHSELN_EN in CSR register. */
#define FSL_FEATURE_VREF_HAS_REFCHSELN_EN (1)
/* @brief Has bitfield REFCHSELP_EN in CSR register. */
#define FSL_FEATURE_VREF_HAS_REFCHSELP_EN (1)
/* @brief Support max voltage of 2.5V. */
#define FSL_FEATURE_VREF_SUPPORT_2V5 (1)

/* WUU module features */

/* @brief Has MF register. */
#define FSL_FEATURE_WUU_HAS_MF (0)

/* WWDT module features */

/* @brief WWDT does not support oscillator lock. */
#define FSL_FEATURE_WWDT_HAS_NO_OSCILLATOR_LOCK (0)
/* @brief soc has reset. */
#define FSL_FEATURE_WWDT_HAS_NO_RESET (1)
/* @brief Has LPOSC as clock source. */
#define FSL_FEATURE_WWDT_HAS_LPOSC_CLOCK_SOURCE (0)
/* @brief WWDT WDTOF is not set in case of WD reset - get info from PMC instead. */
#define FSL_FEATURE_WWDT_WDTRESET_FROM_PMC (0)

#endif /* _MCXA577_FEATURES_H_ */

