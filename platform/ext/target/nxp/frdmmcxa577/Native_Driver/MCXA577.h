/*
** ###################################################################
**     Processors:          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXAP144M180FS6_RM_Rev.1_DraftC
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXA577
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
 * @file MCXA577.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCXA577
 *
 * CMSIS Peripheral Access Layer for MCXA577
 */

#if !defined(MCXA577_H_)  /* Check if memory map has not been already included */
#define MCXA577_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AHBSC.h"
#include "PERI_AOI.h"
#include "PERI_CAN.h"
#include "PERI_CDOG.h"
#include "PERI_CMC.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DEBUGMAILBOX.h"
#include "PERI_DIGTMP.h"
#include "PERI_DMA.h"
#include "PERI_EIM.h"
#include "PERI_ENET.h"
#include "PERI_ERM.h"
#include "PERI_ESPI.h"
#include "PERI_EWM.h"
#include "PERI_FLEXIO.h"
#include "PERI_FLEXSPI.h"
#include "PERI_FMC.h"
#include "PERI_FMU.h"
#include "PERI_FREQME.h"
#include "PERI_GDET.h"
#include "PERI_GLIKEY.h"
#include "PERI_GPIO.h"
#include "PERI_I3C.h"
#include "PERI_INPUTMUX.h"
#include "PERI_ITRC.h"
#include "PERI_LPCMP.h"
#include "PERI_LPDAC.h"
#include "PERI_LPI2C.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MRCC.h"
#include "PERI_OSTIMER.h"
#include "PERI_PKC.h"
#include "PERI_PORT.h"
#include "PERI_RTC.h"
#include "PERI_SCG.h"
#include "PERI_SECCON.h"
#include "PERI_SGI.h"
#include "PERI_SMARTDMA.h"
#include "PERI_SPC.h"
#include "PERI_SYSCON.h"
#include "PERI_TENBASET_PHY.h"
#include "PERI_TRDC.h"
#include "PERI_TRNG.h"
#include "PERI_TSI.h"
#include "PERI_USBHS.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_UTICK.h"
#include "PERI_VBAT.h"
#include "PERI_VREF.h"
#include "PERI_WAKETIMER.h"
#include "PERI_WUU.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(MCXA577_H_) */
