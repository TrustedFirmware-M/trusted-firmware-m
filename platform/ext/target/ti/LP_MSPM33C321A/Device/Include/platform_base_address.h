/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file platform_base_address.h
 * \brief MSPM33C321A peripheral base addresses for TF-M.
 *
 * All _BASE_S values are taken verbatim from:
 *   source/ti/devices/msp/m33/mspm33c321x.h
 *
 * On MSPM33C321A TrustZone address map:
 *   Secure (S) peripheral aliases:      0x5xxxxxxx
 *   Non-Secure (NS) peripheral aliases: 0x4xxxxxxx  (S - 0x10000000)
 */

#ifndef __PLATFORM_BASE_ADDRESS_H__
#define __PLATFORM_BASE_ADDRESS_H__

/* -----------------------------------------------------------------------
 * Secure peripheral base addresses (verified against mspm33c321x.h)
 * ----------------------------------------------------------------------- */

/* UC12 — backchannel UART to XDS110 debugger (PA10=TX, PA11=RX, 115200 baud) */
#define UC12_UART_BASE_S            (0x50608000UL)  /* UC12_UART_BASE_S  */
#define UART0_BASE_S                UC12_UART_BASE_S

/* Flash Controller */
#define FLASHCTL_BASE_S             (0x50042000UL)  /* FLASHCTL_BASE_S   */

/* TRNG */
#define TRNG_BASE_S                 (0x50044000UL)  /* TRNG_BASE_S       */

/* GSC (Global Security Controller) */
#define GSC_BASE_S                  (0x50046000UL)  /* GSC_BASE_S        */

/* SYSCTL */
#define SYSCTL_BASE_S               (0x500AF000UL)  /* SYSCTL_BASE_S     */

/* DEBUGSS */
#define DEBUGSS_BASE_S              (0x500C7000UL)  /* DEBUGSS_BASE_S    */

/* WWDT0 */
#define WWDT0_BASE_S                (0x500D0000UL)  /* WWDT0_BASE_S      */

/* LFSS (Low-Frequency Sub-System, includes RTC) */
#define LFSS_BASE_S                 (0x500D8000UL)  /* LFSS_BASE_S       */

/* GPIO */
#define GPIOA_BASE_S                (0x500F0000UL)  /* GPIOA_BASE_S      */
#define GPIOB_BASE_S                (0x500F2000UL)  /* GPIOB_BASE_S      */
#define GPIOC_BASE_S                (0x500F4000UL)  /* GPIOC_BASE_S      */

/* Timers — TIMA0 has two instances (0, 1) */
#define TIMA0_0_BASE_S              (0x50010000UL)  /* TIMA0_0_BASE_S    */
#define TIMA0_1_BASE_S              (0x50012000UL)  /* TIMA0_1_BASE_S    */

/* Timers — TIMG4 (4 instances) */
#define TIMG4_0_BASE_S              (0x500C0000UL)  /* TIMG4_0_BASE_S    */
#define TIMG4_1_BASE_S              (0x500C2000UL)  /* TIMG4_1_BASE_S    */
#define TIMG4_2_BASE_S              (0x50180000UL)  /* TIMG4_2_BASE_S    */
#define TIMG4_3_BASE_S              (0x50182000UL)  /* TIMG4_3_BASE_S    */

/* Timers — TIMG8 (2 instances) */
#define TIMG8_0_BASE_S              (0x50184000UL)  /* TIMG8_0_BASE_S    */
#define TIMG8_1_BASE_S              (0x50186000UL)  /* TIMG8_1_BASE_S    */

/* Timers — TIMG12 */
#define TIMG12_0_BASE_S             (0x50188000UL)  /* TIMG12_0_BASE_S   */

/* ADC */
#define ADC0_BASE_S                 (0x50000000UL)  /* ADC0_ADC_LITE_REGS_BASE_S */
#define ADC1_BASE_S                 (0x50002000UL)  /* ADC1_ADC_LITE_REGS_BASE_S */

/* CAN FD */
#define CANFD0_BASE_S               (0x50110000UL)  /* CANFD0_BASE_S     */
#define CANFD1_BASE_S               (0x50118000UL)  /* CANFD1_BASE_S     */

/* I2S */
#define I2S0_BASE_S                 (0x501A0000UL)  /* I2S0_BASE_S       */
#define I2S1_BASE_S                 (0x501A2000UL)  /* I2S1_BASE_S       */

/* QSPI */
#define QSPI_BASE_S                 (0x50032000UL)  /* QSPI_BASE_S       */

/* Security accelerators */
#define AESADV_BASE_S               (0x501B0000UL)  /* AESADV_BASE_S     */
#define SHAW_BASE_S                 (0x501B4000UL)  /* SHAW_BASE_S       */
#define PKA_BASE_S                  (0x501C0000UL)  /* PKA_BASE_S        */

/* DMA */
#define DMA0_BASE_S                 (0x50020000UL)  /* DMA0_BASE_S       */
#define DMA1_BASE_S                 (0x50022000UL)  /* DMA1_BASE_S       */

/* -----------------------------------------------------------------------
 * Non-secure peripheral aliases  (S - 0x10000000)
 * ----------------------------------------------------------------------- */
#define NS_ALIAS_OFFSET             (0x10000000UL)

#define UART0_BASE_NS               (UART0_BASE_S    - NS_ALIAS_OFFSET)
#define FLASHCTL_BASE_NS            (FLASHCTL_BASE_S - NS_ALIAS_OFFSET)
#define GPIOA_BASE_NS               (GPIOA_BASE_S    - NS_ALIAS_OFFSET)
#define GPIOB_BASE_NS               (GPIOB_BASE_S    - NS_ALIAS_OFFSET)
#define GPIOC_BASE_NS               (GPIOC_BASE_S    - NS_ALIAS_OFFSET)

#endif /* __PLATFORM_BASE_ADDRESS_H__ */
