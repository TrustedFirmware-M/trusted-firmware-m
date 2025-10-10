/*
** ###################################################################
**     Processors:          MCXN947VAB_cm33_core0
**                          MCXN947VDF_cm33_core0
**                          MCXN947VKL_cm33_core0
**                          MCXN947VNL_cm33_core0
**                          MCXN947VPB_cm33_core0
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXNx4x Reference Manual
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250703
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXN947_cm33_core0
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
 * @file MCXN947_cm33_core0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCXN947_cm33_core0
 *
 * CMSIS Peripheral Access Layer for MCXN947_cm33_core0
 */

#if !defined(MCXN947_cm33_core0_H_)  /* Check if memory map has not been already included */
#define MCXN947_cm33_core0_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AHBSC.h"
#include "PERI_BSP32.h"
#include "PERI_CACHE64_CTRL.h"
#include "PERI_CACHE64_POLSEL.h"
#include "PERI_CAN.h"
#include "PERI_CDOG.h"
#include "PERI_CMC.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DIGTMP.h"
#include "PERI_DM.h"
#include "PERI_DMA.h"
#include "PERI_EIM.h"
#include "PERI_EMVSIM.h"
#include "PERI_ENET.h"
#include "PERI_ERM.h"
#include "PERI_EVTG.h"
#include "PERI_EWM.h"
#include "PERI_FLEXIO.h"
#include "PERI_FLEXSPI.h"
#include "PERI_FMU.h"
#include "PERI_FMUTEST.h"
#include "PERI_FREQME.h"
#include "PERI_GDET.h"
#include "PERI_GPIO.h"
#include "PERI_HPDAC.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_INPUTMUX.h"
#include "PERI_INTM.h"
#include "PERI_ITRC.h"
#include "PERI_LPCMP.h"
#include "PERI_LPDAC.h"
#include "PERI_LPI2C.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_LP_FLEXCOMM.h"
#include "PERI_MAILBOX.h"
#include "PERI_MRT.h"
#include "PERI_NPX.h"
#include "PERI_OPAMP.h"
#include "PERI_OSTIMER.h"
#include "PERI_OTPC.h"
#include "PERI_PDM.h"
#include "PERI_PINT.h"
#include "PERI_PKC.h"
#include "PERI_PLU.h"
#include "PERI_PORT.h"
#include "PERI_POWERQUAD.h"
#include "PERI_PUF.h"
#include "PERI_PWM.h"
#include "PERI_QDC.h"
#include "PERI_RTC.h"
#include "PERI_S50.h"
#include "PERI_SCG.h"
#include "PERI_SCT.h"
#include "PERI_SEMA42.h"
#include "PERI_SINC.h"
#include "PERI_SMARTDMA.h"
#include "PERI_SPC.h"
#include "PERI_SYSCON.h"
#include "PERI_SYSPM.h"
#include "PERI_TRDC.h"
#include "PERI_TSI.h"
#include "PERI_USB.h"
#include "PERI_USBDCD.h"
#include "PERI_USBHS.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_USDHC.h"
#include "PERI_UTICK.h"
#include "PERI_VBAT.h"
#include "PERI_VREF.h"
#include "PERI_WUU.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(MCXN947_cm33_core0_H_) */
