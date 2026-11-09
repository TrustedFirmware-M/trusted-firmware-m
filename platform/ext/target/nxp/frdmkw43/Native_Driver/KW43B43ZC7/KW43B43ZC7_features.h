/*
** ###################################################################
**     Version:             rev. 1.0, 2026-01-09
**     Build:               b260316
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
**     - rev. 1.0 (2026-01-09)
**         Initial version.
**
** ###################################################################
*/

#ifndef _KW43B43ZC7_FEATURES_H_
#define _KW43B43ZC7_FEATURES_H_

/* SOC module features */

/* @brief AOI availability on the SoC. */
#define FSL_FEATURE_SOC_AOI_COUNT (1)
/* @brief ATX availability on the SoC. */
#define FSL_FEATURE_SOC_ATX_COUNT (1)
/* @brief AXBS availability on the SoC. */
#define FSL_FEATURE_SOC_AXBS_COUNT (2)
/* @brief BLE2_REG availability on the SoC. */
#define FSL_FEATURE_SOC_BLE2_REG_COUNT (2)
/* @brief BRIC availability on the SoC. */
#define FSL_FEATURE_SOC_BRIC_COUNT (1)
/* @brief BTRTU1 availability on the SoC. */
#define FSL_FEATURE_SOC_BTRTU1_COUNT (1)
/* @brief BTU2_REG availability on the SoC. */
#define FSL_FEATURE_SOC_BTU2_REG_COUNT (1)
/* @brief CDOG availability on the SoC. */
#define FSL_FEATURE_SOC_CDOG_COUNT (2)
/* @brief CIU2 availability on the SoC. */
#define FSL_FEATURE_SOC_CIU2_COUNT (1)
/* @brief CMC availability on the SoC. */
#define FSL_FEATURE_SOC_CMC_COUNT (1)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (2)
/* @brief EDMA availability on the SoC. */
#define FSL_FEATURE_SOC_EDMA_COUNT (1)
/* @brief EWM availability on the SoC. */
#define FSL_FEATURE_SOC_EWM_COUNT (1)
/* @brief FLEXCAN availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXCAN_COUNT (1)
/* @brief FMC availability on the SoC. */
#define FSL_FEATURE_SOC_FMC_COUNT (2)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (4)
/* @brief SPC availability on the SoC. */
#define FSL_FEATURE_SOC_SPC_COUNT (1)
/* @brief ITRC availability on the SoC. */
#define FSL_FEATURE_SOC_ITRC_COUNT (1)
/* @brief LPADC availability on the SoC. */
#define FSL_FEATURE_SOC_LPADC_COUNT (1)
/* @brief LPCMP availability on the SoC. */
#define FSL_FEATURE_SOC_LPCMP_COUNT (1)
/* @brief LPI2C availability on the SoC. */
#define FSL_FEATURE_SOC_LPI2C_COUNT (2)
/* @brief LPIT availability on the SoC. */
#define FSL_FEATURE_SOC_LPIT_COUNT (1)
/* @brief LPSPI availability on the SoC. */
#define FSL_FEATURE_SOC_LPSPI_COUNT (3)
/* @brief LPTMR availability on the SoC. */
#define FSL_FEATURE_SOC_LPTMR_COUNT (2)
/* @brief LPUART availability on the SoC. */
#define FSL_FEATURE_SOC_LPUART_COUNT (2)
/* @brief LTC availability on the SoC. */
#define FSL_FEATURE_SOC_LTC_COUNT (1)
/* @brief MCM availability on the SoC. */
#define FSL_FEATURE_SOC_MCM_COUNT (1)
/* @brief MSCM availability on the SoC. */
#define FSL_FEATURE_SOC_MSCM_COUNT (1)
/* @brief MU availability on the SoC. */
#define FSL_FEATURE_SOC_MU_COUNT (4)
/* @brief PKC availability on the SoC. */
#define FSL_FEATURE_SOC_PKC_COUNT (1)
/* @brief PORT availability on the SoC. */
#define FSL_FEATURE_SOC_PORT_COUNT (4)
/* @brief PWM availability on the SoC. */
#define FSL_FEATURE_SOC_PWM_COUNT (1)
/* @brief RTC availability on the SoC. */
#define FSL_FEATURE_SOC_RTC_COUNT (1)
/* @brief SCG availability on the SoC. */
#define FSL_FEATURE_SOC_SCG_COUNT (1)
/* @brief SEMA42 availability on the SoC. */
#define FSL_FEATURE_SOC_SEMA42_COUNT (1)
/* @brief SFA availability on the SoC. */
#define FSL_FEATURE_SOC_SFA_COUNT (2)
/* @brief SYSPM availability on the SoC. */
#define FSL_FEATURE_SOC_SYSPM_COUNT (1)
/* @brief TPM availability on the SoC. */
#define FSL_FEATURE_SOC_TPM_COUNT (5)
/* @brief TRGMUX availability on the SoC. */
#define FSL_FEATURE_SOC_TRGMUX_COUNT (1)
/* @brief TRNG availability on the SoC. */
#define FSL_FEATURE_SOC_TRNG_COUNT (1)
/* @brief TSTMR availability on the SoC. */
#define FSL_FEATURE_SOC_TSTMR_COUNT (3)
/* @brief WDOG availability on the SoC. */
#define FSL_FEATURE_SOC_WDOG_COUNT (2)
/* @brief WUU availability on the SoC. */
#define FSL_FEATURE_SOC_WUU_COUNT (1)

/* CCM32K module features */

/* @brief Has Amplifier gain fine adjustment bits (register bit OSC32K_CTRL[FINE_AMP_GAIN]). */
#define FSL_FEATURE_CCM32K_HAS_FINE_AMP_GAIN (0)
/* @brief Has CGC32K register. */
#define FSL_FEATURE_CCM32K_HAS_CGC32K (1)
/* @brief Has CLKMON_CTRL register. */
#define FSL_FEATURE_CCM32K_HAS_CLKMON_CTRL (1)

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
#define FSL_FEATURE_FLEXCAN_HAS_NO_SUPV_SUPPORT (1)
/* @brief Has more than 64 MBs. */
#define FSL_FEATURE_FLEXCAN_HAS_MORE_THAN_64_MB (0)
/* @brief Does not support self wake feature(bitfield MCR[SLFWAK]) */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SLFWAK_SUPPORT (0)
/* @brief Has external time tick source (bitfield CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTERNAL_TIME_TICK (1)
/* @brief Instance has external time tick source (register bit field CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTERNAL_TIME_TICKn(x) (1)
/* @brief Has Time Stamp Capture Point(bitfield CTRL2[TSTAMPCAP]). */
#define FSL_FEATURE_FLEXCAN_HAS_HIGH_RESOLUTION_TIMESTAMP (1)
/* @brief Instance has Pretended Networking option (register bit field MCR[PNET_EN]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_PN_MODEn(x) (1)
/* @brief FlexCAN maximum data rate. */
#define FSL_FEATURE_FLEXCAN_MAX_CANFD_BITRATE (8000000)
/* @brief Support payload endianness selection (bitfield CTRL2[PES]). */
#define FSL_FEATURE_FLEXCAN_HAS_ENDIANNESS_SELECTION (1)
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

/* @brief Has on chip TCMC0 */
#define FSL_FEATURE_CMC_HAS_TCMC0 (0)
/* @brief Has on chip SYSRAM0 */
#define FSL_FEATURE_CMC_HAS_SYSRAM0 (0)
/* @brief Has on chip SYSRAM1 */
#define FSL_FEATURE_CMC_HAS_SYSRAM1 (0)
/* @brief Has RSTCNT register */
#define FSL_FEATURE_CMC_HAS_RSTCNT_REGISTER (1)
/* @brief Does not have SRAMCTL register */
#define FSL_FEATURE_CMC_HAS_NO_SRAMCTL_REGISTER (1)
/* @brief Does not have BLR register */
#define FSL_FEATURE_CMC_HAS_NO_BOOTROM_LOCK_REGISTER (0)
/* @brief Has DIER register */
#define FSL_FEATURE_CMC_HAS_DIER_REG (1)
/* @brief Has system clock generation reset (register bit SCG[SRIE]) */
#define FSL_FEATURE_CMC_HAS_SRIE_SCG_BIT (0)

/* LPCMP module features */

/* @brief Has CCR1 FUNC_CLK_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR1_FUNC_CLK_SEL (0)
/* @brief Has IER RRF_IE bitfield. */
#define FSL_FEATURE_LPCMP_HAS_IER_RRF_IE (0)
/* @brief Has CSR RRF bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CSR_RRF (0)
/* @brief Has Round Robin mode (related to existence of registers RRCR0). */
#define FSL_FEATURE_LPCMP_HAS_ROUNDROBIN_MODE (0)
/* @brief Has window mode (related to existence of CCR1.WINDOW_CLS). */
#define FSL_FEATURE_LPCMP_HAS_WINDOW_CONTROL (1)
/* @brief Has no CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_NO_CCR0_CMP_STOP_EN (0)
/* @brief Has RRCR0 RR_CLK_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_CLK_SEL (0)
/* @brief Has RRCR0 RR_TRG_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_TRG_SEL (0)
/* @brief Has RRCR0 RR_SAMPLE_CNT bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_SAMPLE_CNT (0)
/* @brief Has RRCR0 RR_SAMPLE_THRESHOLD bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_SAMPLE_THRESHOLD (0)
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
#define FSL_FEATURE_LPCMP_HAS_RRCR2 (0)
/* @brief Has CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR0_CMP_STOP_EN (1)
/* @brief CMP instance support CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_INSTANCE_SUPPORT_CCR0_CMP_STOP_ENn(x) (1)

/* CRC module features */

/* @brief Has data register with name CRC */
#define FSL_FEATURE_CRC_HAS_CRC_REG (0)

/* EDMA module features */

/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (16)
/* @brief Soc requires secure master transfer. */
#define FSL_FEATURE_EDMA_SOC_REQUIRES_SECURE_MASTER (1)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (1)
/* @brief Has register bit fields CH_SBR[SEC]. */
#define FSL_FEATURE_EDMA_HAS_CH_SBR_SEC (1)
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (0)
/* @brief Has register bit fields CH_SBR[EMI]. */
#define FSL_FEATURE_EDMA_HAS_CH_SBR_EMI (1)
/* @brief Has register access permission. */
#define FSL_FEATURE_HAVE_DMA_CONTROL_REGISTER_ACCESS_PERMISSION (1)
/* @brief If dma has common clock gate */
#define FSL_FEATURE_EDMA_HAS_COMMON_CLOCK_GATE (1)
/* @brief Number of channel for each EDMA instance, (only defined for soc with different channel numbers for difference instance) */
#define FSL_FEATURE_EDMA_INSTANCE_CHANNELn(x) (16)
/* @brief Has no EMI access bit (MP_CSR). */
#define FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EMI (0)
/* @brief Has no EBW access bit (MP_CSR). */
#define FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EBW (1)
/* @brief Has channel mux */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MUX (1)
/* @brief Has EDMA arbitration group (CHn_GRPRI). */
#define FSL_FEATURE_EDMA_HAS_ARBITRATION_GROUP (1)

/* EWM module features */

/* @brief Has clock select (register CLKCTRL). */
#define FSL_FEATURE_EWM_HAS_CLOCK_SELECT (1)
/* @brief Has clock prescaler (register CLKPRESCALER). */
#define FSL_FEATURE_EWM_HAS_PRESCALER (1)

/* PWM module features */

/* @brief If (e)FlexPWM has module A channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELA (1)
/* @brief If (e)FlexPWM has module B channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELB (1)
/* @brief If (e)FlexPWM has module X channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELX (1)
/* @brief If (e)FlexPWM has fractional feature. */
#define FSL_FEATURE_PWM_HAS_FRACTIONAL (0)
/* @brief If (e)FlexPWM has mux trigger source select bit field. */
#define FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL (1)
/* @brief Number of submodules in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_SUBMODULE_COUNT (3)
/* @brief Number of fault channel in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_FAULT_CH_COUNT (1)
/* @brief (e)FlexPWM has no WAITEN Bitfield In CTRL2 Register. */
#define FSL_FEATURE_PWM_HAS_NO_WAITEN (1)
/* @brief If (e)FlexPWM has phase delay feature. */
#define FSL_FEATURE_PWM_HAS_PHASE_DELAY (1)
/* @brief If (e)FlexPWM has input filter capture feature. */
#define FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE (1)
/* @brief If (e)FlexPWM has module capture functionality on A channels (inputs). */
#define FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA (0)
/* @brief If (e)FlexPWM has module capture functionality on B channels (inputs). */
#define FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB (0)
/* @brief If (e)FlexPWM has module capture functionality on X channels (inputs). */
#define FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX (1)
/* @brief Is affected by errata with ID 51989. */
#define FSL_FEATURE_PWM_HAS_ERRATA_51989 (0)

/* MSF1 module features */

/* @brief Is the flash module msf1? */
#define FSL_FEATURE_FLASH_IS_MSF1 (1u)
/* @brief P-Flash start address. */
#define FSL_FEATURE_FLASH_PFLASH_START_ADDRESS (0x00000000u)
/* @brief Flash IFR0 start address. */
#define FSL_FEATURE_FLASH_IFR0_START_ADDRESS (0x01000000u)
/* @brief Flash IFR0 size. */
#define FSL_FEATURE_FLASH_IFR0_SIZE (0x8000u)
/* @brief P-Flash block count. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT (1u)
/* @brief P-Flash block size. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE (0x180000u)
/* @brief P-Flash block size. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE_512KB (0x80000u)
/* @brief Flash sector size. */
#define FSL_FEATURE_FLASH_PFLASH_SECTOR_SIZE (8192u)
/* @brief Flash page size. */
#define FSL_FEATURE_FLASH_PFLASH_PAGE_SIZE (128u)
/* @brief Flash phrase size. */
#define FSL_FEATURE_FLASH_PFLASH_PHRASE_SIZE (16u)
/* @brief RF P-Flash start address. */
#define FSL_FEATURE_RF_FLASH_PFLASH_START_ADDRESS (0x02000000u)
/* @brief RF P-Flash block count. */
#define FSL_FEATURE_RF_FLASH_PFLASH_BLOCK_COUNT (1u)
/* @brief RF P-Flash block size. */
#define FSL_FEATURE_RF_FLASH_PFLASH_BLOCK_SIZE (0x180000u)

/* GPIO module features */

/* @brief Has GPIO attribute checker register (GACR). */
#define FSL_FEATURE_GPIO_HAS_ATTRIBUTE_CHECKER (0)
/* @brief Has GPIO version ID register (VERID). */
#define FSL_FEATURE_GPIO_HAS_VERSION_INFO_REGISTER (1)
/* @brief Has secure/non-secure access protection registers (LOCK, PCNS, PCNP, ICNS, ICNP). */
#define FSL_FEATURE_GPIO_HAS_SECURE_PRIVILEGE_CONTROL (1)
/* @brief Has GPIO port input disable register (PIDR). */
#define FSL_FEATURE_GPIO_HAS_PORT_INPUT_CONTROL (1)
/* @brief Has GPIO interrupt/DMA request/trigger output selection. */
#define FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT (1)

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
/* @brief Has internal temperature sensor. */
#define FSL_FEATURE_LPADC_HAS_INTERNAL_TEMP_SENSOR (1)
/* @brief Temperature sensor parameter A (slope). */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_A (787U)
/* @brief Temperature sensor parameter B (offset). */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_B (289U)
/* @brief Temperature sensor parameter Alpha. */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_ALPHA (9.1f)
/* @brief The buffer size of temperature sensor. */
#define FSL_FEATURE_LPADC_TEMP_SENS_BUFFER_SIZE (2U)

/* INTM module features */

/* @brief Up to 4 programmable interrupt monitors */
#define FSL_FEATURE_INTM_MONITOR_COUNT (4)

/* LPI2C module features */

/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPI2C_FIFO_SIZEn(x) (4)
/* @brief Has dedicated interrupt for master and slave. */
#define FSL_FEATURE_LPI2C_HAS_ROLE_SPLIT_IRQ (0)
/* @brief Belong to LPFLEXCOMM */
#define FSL_FEATURE_LPI2C_IS_LPFLEXCOMM (0)

/* LPIT module features */

/* @brief Number of channels (related to number of registers LDVALn, CVALn, TCTRLn, TFLGn). */
#define FSL_FEATURE_LPIT_TIMER_COUNT (4)
/* @brief Has lifetime timer (related to existence of registers LTMR64L and LTMR64H). */
#define FSL_FEATURE_LPIT_HAS_LIFETIME_TIMER (0)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_LPIT_HAS_SHARED_IRQ_HANDLER (1)

/* LPSPI module features */

/* @brief Capacity (number of entries) of the transmit/receive FIFO. */
#define FSL_FEATURE_LPSPI_FIFO_SIZEn(x) (8)
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
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_0_SUPPORT (0)
/* @brief Do not has prescaler clock source 1. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_1_SUPPORT (1)
/* @brief Do not has prescaler clock source 2. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_2_SUPPORT (0)
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
#define FSL_FEATURE_LPUART_HAS_SEPARATE_DMA_RX_TX_REQn(x) (0)
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
#define FSL_FEATURE_LPUART_FIFO_SIZEn(x) (8)
/* @brief UART support receive rts configuration (has bit MODIR[RTSWATER]). */
#define FSL_FEATURE_LPUART_HAS_MODIR_RTSWATER (1)

/* LTC module features */

/* @brief LTC module supports DES algorithm. */
#define FSL_FEATURE_LTC_HAS_DES (0)
/* @brief LTC module supports PKHA algorithm. */
#define FSL_FEATURE_LTC_HAS_PKHA (0)
/* @brief LTC module supports SHA algorithm. */
#define FSL_FEATURE_LTC_HAS_SHA (0)
/* @brief LTC module supports AES GCM mode. */
#define FSL_FEATURE_LTC_HAS_GCM (0)
/* @brief LTC module supports DPAMS registers. */
#define FSL_FEATURE_LTC_HAS_DPAMS (0)
/* @brief LTC module supports AES with 24 bytes key. */
#define FSL_FEATURE_LTC_HAS_AES192 (0)
/* @brief LTC module supports AES with 32 bytes key. */
#define FSL_FEATURE_LTC_HAS_AES256 (0)
/* @brief LTC module has no clock control bit. */
#define FSL_FEATURE_LTC_HAS_NO_CLOCK_CONTROL_BIT (1)

/* MEMORY module features */

/* @brief Memory map has offset between subsystems. */
#define FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET (1)

/* MSCM module features */

/* @brief Number of configuration information for processors. */
#define FSL_FEATURE_MSCM_HAS_CP_COUNT (1)
/* @brief Has data cache. */
#define FSL_FEATURE_MSCM_HAS_DATACACHE (0)

/* MU module features */

/* @brief MU side for current core */
#define FSL_FEATURE_MU_SIDE_A (1)
/* @brief MU supports reset assert interrupt. CIER0[RAIE] or CR[RAIE] or BCR[RAIE]. */
#define FSL_FEATURE_MU_HAS_RESET_ASSERT_INT (0)
/* @brief MU supports reset de-assert interrupt. CR[RDIE] or BCR[RDIE]. */
#define FSL_FEATURE_MU_HAS_RESET_DEASSERT_INT (0)
/* @brief MU does not support core status. Register CSSR0 or CSR0. */
#define FSL_FEATURE_MU_NO_CORE_STATUS (1)
/* @brief MU does not support NMI. Register bit CCR0[NMI]. */
#define FSL_FEATURE_MU_NO_NMI (1)
/* @brief MU does not support core event pending. Register bit SR[CEP]. */
#define FSL_FEATURE_MU_NO_CEP (1)
/* @brief MU supports Power-Down mode entry interrupt. CIER0[PDIE] */
#define FSL_FEATURE_MU_HAS_PD_INT (0)
/* @brief MU supports STOP mode entry interrupt. CIER0[STOPIE] */
#define FSL_FEATURE_MU_HAS_STOP_INT (0)
/* @brief MU supports WAIT mode entry interrupt. CIER0[WAITIE] */
#define FSL_FEATURE_MU_HAS_WAIT_INT (1)
/* @brief MU supports HALT mode entry interrupt. CIER0[HALTIE] */
#define FSL_FEATURE_MU_HAS_HALT_INT (0)
/* @brief MU supports RUN mode entry interrupt. CIER0[RUNIE] */
#define FSL_FEATURE_MU_HAS_RUN_INT (0)
/* @brief MU supports hardware reset interrupt. CSSR0[HRIP] or CSR0[HRIP]. */
#define FSL_FEATURE_MU_HAS_SR_HRIP (0)
/* @brief MU supports reset interrupt. Register bit SR[MURIP]. */
#define FSL_FEATURE_MU_HAS_SR_MURIP (1)
/* @brief MU does not support enable clock of the other core, CR[CLKE] or CCR[CLKE]. */
#define FSL_FEATURE_MU_NO_CLKE (1)
/* @brief MU has bit CCR0[RSTH]. */
#define FSL_FEATURE_MU_HAS_RSTH (0)
/* @brief MU has bit CCR0[RSTH] by instance. */
#define FSL_FEATURE_MU_HAS_RSTH_BY_INSTANCEn(x) (0)
/* @brief MU has bit CCR0[BOOT]. */
#define FSL_FEATURE_MU_HAS_BOOT (0)
/* @brief MU has bit CCR0[BOOT] by instance. */
#define FSL_FEATURE_MU_HAS_BOOT_BY_INSTANCEn(x) (0)
/* @brief MU supports MU reset, CR[MUR]. */
#define FSL_FEATURE_MU_HAS_MUR (1)
/* @brief MU supports hardware reset, CR[HR] or CCR0[HR]. */
#define FSL_FEATURE_MU_HAS_HR (0)
/* @brief MU supports hardware reset by instance */
#define FSL_FEATURE_MU_HAS_HR_BY_INSTANCEn(x) (0)
/* @brief The number of general purpose interrupts supported by MU. */
#define FSL_FEATURE_MU_GPI_COUNT (4)

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
#define FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH1 (0)
/* @brief Has version ID register (register VERID). */
#define FSL_FEATURE_PORT_HAS_VERSION_INFO_REGISTER (1)
/* @brief Has voltage range control (register bit CONFIG[RANGE]). */
#define FSL_FEATURE_PORT_SUPPORT_DIFFERENT_VOLTAGE_RANGE (1)
/* @brief Has EFT detect (registers EDFR, EDIER and EDCR). */
#define FSL_FEATURE_PORT_SUPPORT_EFT (0)
/* @brief Has invert input (register bit PCR[INV]). */
#define FSL_FEATURE_PORT_HAS_INVERT_INPUT (1)
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
/* @brief Defines whether PCR[IRQC] bit-field has flag states. */
#define FSL_FEATURE_PORT_HAS_IRQC_FLAG (0)
/* @brief Defines whether PCR[IRQC] bit-field has trigger states. */
#define FSL_FEATURE_PORT_HAS_IRQC_TRIGGER (0)

/* SEMA42 module features */

/* @brief Gate counts */
#define FSL_FEATURE_SEMA42_GATE_COUNT (16)

/* SFA module features */

/* @brief CTRL Has CUT_PIN_EN (bitfield CTRL[CUT_PIN_EN]). */
#define FSL_FEATURE_SFA_CTRL_HAS_CUT_PIN_ENn(x) (1)
/* @brief CTRL_EXT has CUT_PIN_EN (bitfield CTRL_EXT[CUT_PIN_EN]). */
#define FSL_FEATURE_SFA_CTRL_EXT_HAS_CUT_PIN_EN (0)
/* @brief Trigger selection is configured outside the SFA peripheral. */
#define FSL_FEATURE_SFA_TRIGGER_SELECTION_OUTSIDEn(x) (0)
/* @brief SFA instance support trigger. */
#define FSL_FEATURE_SFA_INSTANCE_HAS_TRIGGERn(x) (1)
/* @brief SFA instance support interrupt. */
#define FSL_FEATURE_SFA_INSTANCE_HAS_INTERRUPTn(x) (1)

/* SPC module features */

/* @brief Has 2P4G power domain. */
#define FSL_FEATURE_SPC_HAS_2P4G_POWER_DOMAIN (1)
/* @brief Has SPC_CFG. */
#define FSL_FEATURE_SPC_HAS_CFG_REGISTER (1)
/* @brief Has core ldo vdd driver strength (register bit ACTIVE_CFG[CORELDO_VDD_DS]). */
#define FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS (1)
/* @brief Has bias enable (register bit LP_CFG[WBIAS_EN]). */
#define FSL_FEATURE_SPC_HAS_WBIAS_EN (0)
/* @brief Set CORELDO_VDD_LVL to 0 then regulate to Under Drive Voltage (0.95v). */
#define FSL_FEATURE_SPC_LDO_VOLTAGE_LEVEL_DECREASE (0)
/* @brief Set DCDC_VDD_LVL to 0 then regulate to Low Under Voltage (1.25v). */
#define FSL_FEATURE_SPC_DCDC_VOLTAGE_LEVEL_DECREASE (0)
/* @brief Has SC REG_BUSY (register bit SC[REG_BUSY]). */
#define FSL_FEATURE_SPC_HAS_SC_REG_BUSY (1)
/* @brief Has HP_CFG register. */
#define FSL_FEATURE_SPC_HAS_HP_CFG_REG (1)
/* @brief SPC Power Mode Configuration Status Flag. */
#define FSL_FEATURE_SPC_HAS_SC_SPC_LP_REQ_BIT (1)
/* @brief Has DCDC_BURST_CFG register. */
#define FSL_FEATURE_SPC_HAS_DCDC_BURST_CFG (0)
/* @brief Has SYSLDO_CFG register. */
#define FSL_FEATURE_SPC_HAS_SYS_LDO (0)
/* @brief Has cmp bandgap buffer enable. */
#define FSL_FEATURE_SPC_HAS_LPBUFF (0)
/* @brief Has VD_SYS_CFG register. */
#define FSL_FEATURE_SPC_HAS_VDD_SYS (0)

/* RTC module features */

/* @brief Has wakeup pin. */
#define FSL_FEATURE_RTC_HAS_WAKEUP_PIN (1)
/* @brief Has wakeup pin selection (bit field CR[WPS]). */
#define FSL_FEATURE_RTC_HAS_WAKEUP_PIN_SELECTION (0)
/* @brief Has low power features (registers MER, MCLR and MCHR). */
#define FSL_FEATURE_RTC_HAS_MONOTONIC (0)
/* @brief Has read/write access control (registers WAR and RAR). */
#define FSL_FEATURE_RTC_HAS_ACCESS_CONTROL (0)
/* @brief Has security features (registers TTSR, MER, MCLR and MCHR). */
#define FSL_FEATURE_RTC_HAS_SECURITY (0)
/* @brief Has RTC_CLKIN available. */
#define FSL_FEATURE_RTC_HAS_RTC_CLKIN (0)
/* @brief Has prescaler adjust for LPO. */
#define FSL_FEATURE_RTC_HAS_LPO_ADJUST (0)
/* @brief Has Clock Pin Enable field. */
#define FSL_FEATURE_RTC_HAS_CPE (1)
/* @brief Has Timer Seconds Interrupt Configuration field. */
#define FSL_FEATURE_RTC_HAS_TSIC (1)
/* @brief Has OSC capacitor setting RTC_CR[SC2P ~ SC16P] */
#define FSL_FEATURE_RTC_HAS_OSC_SCXP (0)
/* @brief Has Tamper Interrupt Register (register TIR). */
#define FSL_FEATURE_RTC_HAS_TIR (0)
/* @brief Has Tamper Pin Interrupt Enable (bitfield TIR[TPIE]). */
#define FSL_FEATURE_RTC_HAS_TIR_TPIE (0)
/* @brief Has Security Interrupt Enable (bitfield TIR[SIE]). */
#define FSL_FEATURE_RTC_HAS_TIR_SIE (0)
/* @brief Has Loss of Clock Interrupt Enable (bitfield TIR[LCIE]). */
#define FSL_FEATURE_RTC_HAS_TIR_LCIE (0)
/* @brief Has Tamper Interrupt Detect Flag (bitfield SR[TIDF]). */
#define FSL_FEATURE_RTC_HAS_SR_TIDF (0)
/* @brief Has Tamper Detect Register (register TDR). */
#define FSL_FEATURE_RTC_HAS_TDR (0)
/* @brief Has Tamper Pin Flag (bitfield TDR[TPF]). */
#define FSL_FEATURE_RTC_HAS_TDR_TPF (0)
/* @brief Has Security Tamper Flag (bitfield TDR[STF]). */
#define FSL_FEATURE_RTC_HAS_TDR_STF (0)
/* @brief Has Loss of Clock Tamper Flag (bitfield TDR[LCTF]). */
#define FSL_FEATURE_RTC_HAS_TDR_LCTF (0)
/* @brief Has Tamper Time Seconds Register (register TTSR). */
#define FSL_FEATURE_RTC_HAS_TTSR (0)
/* @brief Has Pin Configuration Register (register PCR). */
#define FSL_FEATURE_RTC_HAS_PCR (0)
/* @brief Has Oscillator Enable(bitfield CR[OSCE]). */
#define FSL_FEATURE_RTC_HAS_NO_CR_OSCE (1)
/* @brief Has no supervisor access bit (CR[SUP]). */
#define FSL_FEATURE_RTC_HAS_NO_CR_SUP (1)
/* @brief Is affected by errata with ID 010716 (RTC: Timer Alarm Flag can assert erroneously). */
#define FSL_FEATURE_RTC_HAS_ERRATA_010716 (0)
/* @brief Has clock output bit (CR[CLKO]). */
#define FSL_FEATURE_RTC_HAS_CLOCK_OUTPUT (1)

/* SYSPM module features */

/* @brief SYSPM support disable counters if stopped or halted. */
#define FSL_FEATURE_SYSPM_HAS_PMCR_DCIFSH (0)
/* @brief SYSPM has reset instruction counter. */
#define FSL_FEATURE_SYSPM_HAS_PMCR_RICTR (1)
/* @brief Number of PMCR registers signals number of performance monitors available in single SYSPM instance. */
#define FSL_FEATURE_SYSPM_PMCR_COUNT (2)
/* @brief SYSPM has instruction counter. */
#define FSL_FEATURE_SYSPM_HAS_PMICTR (0)

/* SysTick module features */

/* @brief Systick has external reference clock. */
#define FSL_FEATURE_SYSTICK_HAS_EXT_REF (1)
/* @brief Systick external reference clock is core clock divided by this value. */
#define FSL_FEATURE_SYSTICK_EXT_REF_CORE_DIV (16)

/* TPM module features */

/* @brief Number of channels. */
#define FSL_FEATURE_TPM_CHANNEL_COUNTn(x) \
    (((x) == TPM_0) ? (6) : \
    (((x) == TPM_3) ? (2) : \
    (((x) == TPM_4) ? (2) : \
    (((x) == TPM_1) ? (2) : \
    (((x) == TPM_2) ? (2) : (-1))))))
/* @brief Has counter reset by the selected input capture event (register bits C0SC[ICRST], C1SC[ICRST], ...). */
#define FSL_FEATURE_TPM_HAS_COUNTER_RESET_BY_CAPTURE_EVENT (0)
/* @brief Has TPM_PARAM. */
#define FSL_FEATURE_TPM_HAS_PARAM (1)
/* @brief Has TPM_VERID. */
#define FSL_FEATURE_TPM_HAS_VERID (1)
/* @brief Has TPM_GLOBAL. */
#define FSL_FEATURE_TPM_HAS_GLOBAL (1)
/* @brief Has TPM_TRIG. */
#define FSL_FEATURE_TPM_HAS_TRIG (1)
/* @brief Whether TRIG register has effect. */
#define FSL_FEATURE_TPM_TRIG_HAS_EFFECTn(x) (1)
/* @brief Has counter pause on trigger. */
#define FSL_FEATURE_TPM_HAS_PAUSE_COUNTER_ON_TRIGGER (1)
/* @brief Has external trigger selection. */
#define FSL_FEATURE_TPM_HAS_EXTERNAL_TRIGGER_SELECTION (1)
/* @brief Has TPM_COMBINE register. */
#define FSL_FEATURE_TPM_HAS_COMBINE (1)
/* @brief Whether COMBINE register has effect. */
#define FSL_FEATURE_TPM_COMBINE_HAS_EFFECTn(x) (1)
/* @brief Has TPM_POL. */
#define FSL_FEATURE_TPM_HAS_POL (1)
/* @brief Whether POL register has effect. */
#define FSL_FEATURE_TPM_POL_HAS_EFFECTn(x) (1)
/* @brief Has TPM_FILTER register. */
#define FSL_FEATURE_TPM_HAS_FILTER (1)
/* @brief Whether FILTER register has effect. */
#define FSL_FEATURE_TPM_FILTER_HAS_EFFECTn(x) (1)
/* @brief Has TPM_QDCTRL register. */
#define FSL_FEATURE_TPM_HAS_QDCTRL (1)
/* @brief Whether QDCTRL register has effect. */
#define FSL_FEATURE_TPM_QDCTRL_HAS_EFFECTn(x) (1)
/* @brief Has pause level select. */
#define FSL_FEATURE_TPM_HAS_PAUSE_LEVEL_SELECT (1)
/* @brief Whether 32 bits counter has effect. */
#define FSL_FEATURE_TPM_HAS_32BIT_COUNTERn(x) (1)
/* @brief Has global time base enable. */
#define FSL_FEATURE_TPM_HAS_GLOBAL_TIME_BASE_EN (1)
/* @brief Has global time base sync. */
#define FSL_FEATURE_TPM_HAS_GLOBAL_TIME_BASE_SYNC (1)
/* @brief Is affected by errata with ID 050050 (Incorrect duty output when EPWM mode is set to PS=0 during write 1 to CnV register). */
#define FSL_FEATURE_TPM_HAS_ERRATA_050050 (0)

/* TRDC module features */

/* @brief Process master count. */
#define FSL_FEATURE_TRDC_PROCESSOR_MASTER_COUNT (2)
/* @brief TRDC instance has PID configuration or not. */
#define FSL_FEATURE_TRDC_INSTANCE_HAS_PID_CONFIGURATIONn(x) (0)
/* @brief TRDC domain number (reset value of HWCFG0[NDID]). */
#define FSL_FEATURE_TRDC_DOMAIN_COUNT (2)
/* @brief TRDC instance has MBC. */
#define FSL_FEATURE_TRDC_HAS_MBC (1)
/* @brief TRDC instance has MRC. */
#define FSL_FEATURE_TRDC_HAS_MRC (0)
/* @brief TRDC instance has TRDC_CR. */
#define FSL_FEATURE_TRDC_HAS_GENERAL_CONFIG (1)
/* @brief TRDC instance has MDA_Wx_y_DFMT. */
#define FSL_FEATURE_TRDC_HAS_DOMAIN_ASSIGNMENT (1)
/* @brief TRDC instance has TRDC_FDID. */
#define FSL_FEATURE_TRDC_HAS_DOMAIN_ERROR (1)
/* @brief TRDC instance has TRDC_FLW_CTL. */
#define FSL_FEATURE_TRDC_HAS_FLW (1)

/* TRGMUX module features */

/* No feature definitions */

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

/* WDOG module features */

/* @brief Watchdog is available. */
#define FSL_FEATURE_WDOG_HAS_WATCHDOG (1)
/* @brief WDOG_CNT can be 32-bit written. */
#define FSL_FEATURE_WDOG_HAS_32BIT_ACCESS (1)

/* WUU module features */

/* @brief Has MF register. */
#define FSL_FEATURE_WUU_HAS_MF (0)

#endif /* _KW43B43ZC7_FEATURES_H_ */

