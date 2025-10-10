/*
** ###################################################################
**     Processors:          LPC5526JBD100
**                          LPC5526JBD64
**                          LPC5526JEV98
**                          LPC5528JBD100
**                          LPC5528JBD64
**                          LPC5528JEV59
**                          LPC5528JEV98
**                          LPC55S26JBD100
**                          LPC55S26JBD64
**                          LPC55S26JEV98
**                          LPC55S28JBD100
**                          LPC55S28JBD64
**                          LPC55S28JEV59
**                          LPC55S28JEV98
**                          LPC55S66JBD100_cm33_core0
**                          LPC55S66JBD100_cm33_core1
**                          LPC55S66JBD64_cm33_core0
**                          LPC55S66JBD64_cm33_core1
**                          LPC55S66JEV98_cm33_core0
**                          LPC55S66JEV98_cm33_core1
**                          LPC55S69JBD100_cm33_core0
**                          LPC55S69JBD100_cm33_core1
**                          LPC55S69JBD64_cm33_core0
**                          LPC55S69JBD64_cm33_core1
**                          LPC55S69JEV59_cm33_core0
**                          LPC55S69JEV59_cm33_core1
**                          LPC55S69JEV98_cm33_core0
**                          LPC55S69JEV98_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250529
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SDIF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-08-22)
**         Initial version based on v0.2UM
**     - rev. 1.1 (2019-05-16)
**         Initial A1 version based on v1.3UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SDIF.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SDIF
 *
 * CMSIS Peripheral Access Layer for SDIF
 */

#if !defined(PERI_SDIF_H_)
#define PERI_SDIF_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5526JBD100) || defined(CPU_LPC5526JBD64) || defined(CPU_LPC5526JEV98))
#include "LPC5526_COMMON.h"
#elif (defined(CPU_LPC5528JBD100) || defined(CPU_LPC5528JBD64) || defined(CPU_LPC5528JEV59) || defined(CPU_LPC5528JEV98))
#include "LPC5528_COMMON.h"
#elif (defined(CPU_LPC55S26JBD100) || defined(CPU_LPC55S26JBD64) || defined(CPU_LPC55S26JEV98))
#include "LPC55S26_COMMON.h"
#elif (defined(CPU_LPC55S28JBD100) || defined(CPU_LPC55S28JBD64) || defined(CPU_LPC55S28JEV59) || defined(CPU_LPC55S28JEV98))
#include "LPC55S28_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core0) || defined(CPU_LPC55S66JBD64_cm33_core0) || defined(CPU_LPC55S66JEV98_cm33_core0))
#include "LPC55S66_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core1) || defined(CPU_LPC55S66JBD64_cm33_core1) || defined(CPU_LPC55S66JEV98_cm33_core1))
#include "LPC55S66_cm33_core1_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core0) || defined(CPU_LPC55S69JBD64_cm33_core0) || defined(CPU_LPC55S69JEV59_cm33_core0) || defined(CPU_LPC55S69JEV98_cm33_core0))
#include "LPC55S69_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core1) || defined(CPU_LPC55S69JBD64_cm33_core1) || defined(CPU_LPC55S69JEV59_cm33_core1) || defined(CPU_LPC55S69JEV98_cm33_core1))
#include "LPC55S69_cm33_core1_COMMON.h"
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
   -- SDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDIF_Peripheral_Access_Layer SDIF Peripheral Access Layer
 * @{
 */

/** SDIF - Size of Registers Arrays */
#define SDIF_RESP_COUNT                           4u
#define SDIF_FIFO_COUNT                           64u

/** SDIF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control register, offset: 0x0 */
  __IO uint32_t PWREN;                             /**< Power Enable register, offset: 0x4 */
  __IO uint32_t CLKDIV;                            /**< Clock Divider register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t CLKENA;                            /**< Clock Enable register, offset: 0x10 */
  __IO uint32_t TMOUT;                             /**< Time-out register, offset: 0x14 */
  __IO uint32_t CTYPE;                             /**< Card Type register, offset: 0x18 */
  __IO uint32_t BLKSIZ;                            /**< Block Size register, offset: 0x1C */
  __IO uint32_t BYTCNT;                            /**< Byte Count register, offset: 0x20 */
  __IO uint32_t INTMASK;                           /**< Interrupt Mask register, offset: 0x24 */
  __IO uint32_t CMDARG;                            /**< Command Argument register, offset: 0x28 */
  __IO uint32_t CMD;                               /**< Command register, offset: 0x2C */
  __IO uint32_t RESP[SDIF_RESP_COUNT];             /**< Response register, array offset: 0x30, array step: 0x4 */
  __IO uint32_t MINTSTS;                           /**< Masked Interrupt Status register, offset: 0x40 */
  __IO uint32_t RINTSTS;                           /**< Raw Interrupt Status register, offset: 0x44 */
  __IO uint32_t STATUS;                            /**< Status register, offset: 0x48 */
  __IO uint32_t FIFOTH;                            /**< FIFO Threshold Watermark register, offset: 0x4C */
  __IO uint32_t CDETECT;                           /**< Card Detect register, offset: 0x50 */
  __IO uint32_t WRTPRT;                            /**< Write Protect register, offset: 0x54 */
       uint8_t RESERVED_1[4];
  __IO uint32_t TCBCNT;                            /**< Transferred CIU Card Byte Count register, offset: 0x5C */
  __IO uint32_t TBBCNT;                            /**< Transferred Host to BIU-FIFO Byte Count register, offset: 0x60 */
  __IO uint32_t DEBNCE;                            /**< Debounce Count register, offset: 0x64 */
       uint8_t RESERVED_2[16];
  __IO uint32_t RST_N;                             /**< Hardware Reset, offset: 0x78 */
       uint8_t RESERVED_3[4];
  __IO uint32_t BMOD;                              /**< Bus Mode register, offset: 0x80 */
  __IO uint32_t PLDMND;                            /**< Poll Demand register, offset: 0x84 */
  __IO uint32_t DBADDR;                            /**< Descriptor List Base Address register, offset: 0x88 */
  __IO uint32_t IDSTS;                             /**< Internal DMAC Status register, offset: 0x8C */
  __IO uint32_t IDINTEN;                           /**< Internal DMAC Interrupt Enable register, offset: 0x90 */
  __IO uint32_t DSCADDR;                           /**< Current Host Descriptor Address register, offset: 0x94 */
  __IO uint32_t BUFADDR;                           /**< Current Buffer Descriptor Address register, offset: 0x98 */
       uint8_t RESERVED_4[100];
  __IO uint32_t CARDTHRCTL;                        /**< Card Threshold Control, offset: 0x100 */
  __IO uint32_t BACKENDPWR;                        /**< Power control, offset: 0x104 */
       uint8_t RESERVED_5[248];
  __IO uint32_t FIFO[SDIF_FIFO_COUNT];             /**< SDIF FIFO, array offset: 0x200, array step: 0x4 */
} SDIF_Type;

/* ----------------------------------------------------------------------------
   -- SDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDIF_Register_Masks SDIF Register Masks
 * @{
 */

/*! @name CTRL - Control register */
/*! @{ */

#define SDIF_CTRL_CONTROLLER_RESET_MASK          (0x1U)
#define SDIF_CTRL_CONTROLLER_RESET_SHIFT         (0U)
/*! CONTROLLER_RESET - Controller reset. */
#define SDIF_CTRL_CONTROLLER_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_CONTROLLER_RESET_SHIFT)) & SDIF_CTRL_CONTROLLER_RESET_MASK)

#define SDIF_CTRL_FIFO_RESET_MASK                (0x2U)
#define SDIF_CTRL_FIFO_RESET_SHIFT               (1U)
/*! FIFO_RESET - Fifo reset. */
#define SDIF_CTRL_FIFO_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_FIFO_RESET_SHIFT)) & SDIF_CTRL_FIFO_RESET_MASK)

#define SDIF_CTRL_DMA_RESET_MASK                 (0x4U)
#define SDIF_CTRL_DMA_RESET_SHIFT                (2U)
/*! DMA_RESET - DMA reset. */
#define SDIF_CTRL_DMA_RESET(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_DMA_RESET_SHIFT)) & SDIF_CTRL_DMA_RESET_MASK)

#define SDIF_CTRL_INT_ENABLE_MASK                (0x10U)
#define SDIF_CTRL_INT_ENABLE_SHIFT               (4U)
/*! INT_ENABLE - Global interrupt enable/disable bit. */
#define SDIF_CTRL_INT_ENABLE(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_INT_ENABLE_SHIFT)) & SDIF_CTRL_INT_ENABLE_MASK)

#define SDIF_CTRL_READ_WAIT_MASK                 (0x40U)
#define SDIF_CTRL_READ_WAIT_SHIFT                (6U)
/*! READ_WAIT - Read/wait. */
#define SDIF_CTRL_READ_WAIT(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_READ_WAIT_SHIFT)) & SDIF_CTRL_READ_WAIT_MASK)

#define SDIF_CTRL_SEND_IRQ_RESPONSE_MASK         (0x80U)
#define SDIF_CTRL_SEND_IRQ_RESPONSE_SHIFT        (7U)
/*! SEND_IRQ_RESPONSE - Send irq response. */
#define SDIF_CTRL_SEND_IRQ_RESPONSE(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_SEND_IRQ_RESPONSE_SHIFT)) & SDIF_CTRL_SEND_IRQ_RESPONSE_MASK)

#define SDIF_CTRL_ABORT_READ_DATA_MASK           (0x100U)
#define SDIF_CTRL_ABORT_READ_DATA_SHIFT          (8U)
/*! ABORT_READ_DATA - Abort read data. */
#define SDIF_CTRL_ABORT_READ_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_ABORT_READ_DATA_SHIFT)) & SDIF_CTRL_ABORT_READ_DATA_MASK)

#define SDIF_CTRL_SEND_CCSD_MASK                 (0x200U)
#define SDIF_CTRL_SEND_CCSD_SHIFT                (9U)
/*! SEND_CCSD - Send ccsd. */
#define SDIF_CTRL_SEND_CCSD(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_SEND_CCSD_SHIFT)) & SDIF_CTRL_SEND_CCSD_MASK)

#define SDIF_CTRL_SEND_AUTO_STOP_CCSD_MASK       (0x400U)
#define SDIF_CTRL_SEND_AUTO_STOP_CCSD_SHIFT      (10U)
/*! SEND_AUTO_STOP_CCSD - Send auto stop ccsd. */
#define SDIF_CTRL_SEND_AUTO_STOP_CCSD(x)         (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_SEND_AUTO_STOP_CCSD_SHIFT)) & SDIF_CTRL_SEND_AUTO_STOP_CCSD_MASK)

#define SDIF_CTRL_CEATA_DEVICE_INTERRUPT_STATUS_MASK (0x800U)
#define SDIF_CTRL_CEATA_DEVICE_INTERRUPT_STATUS_SHIFT (11U)
/*! CEATA_DEVICE_INTERRUPT_STATUS - CEATA device interrupt status. */
#define SDIF_CTRL_CEATA_DEVICE_INTERRUPT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_CEATA_DEVICE_INTERRUPT_STATUS_SHIFT)) & SDIF_CTRL_CEATA_DEVICE_INTERRUPT_STATUS_MASK)

#define SDIF_CTRL_CARD_VOLTAGE_A0_MASK           (0x10000U)
#define SDIF_CTRL_CARD_VOLTAGE_A0_SHIFT          (16U)
/*! CARD_VOLTAGE_A0 - Controls the state of the SD_VOLT0 pin. */
#define SDIF_CTRL_CARD_VOLTAGE_A0(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_CARD_VOLTAGE_A0_SHIFT)) & SDIF_CTRL_CARD_VOLTAGE_A0_MASK)

#define SDIF_CTRL_CARD_VOLTAGE_A1_MASK           (0x20000U)
#define SDIF_CTRL_CARD_VOLTAGE_A1_SHIFT          (17U)
/*! CARD_VOLTAGE_A1 - Controls the state of the SD_VOLT1 pin. */
#define SDIF_CTRL_CARD_VOLTAGE_A1(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_CARD_VOLTAGE_A1_SHIFT)) & SDIF_CTRL_CARD_VOLTAGE_A1_MASK)

#define SDIF_CTRL_CARD_VOLTAGE_A2_MASK           (0x40000U)
#define SDIF_CTRL_CARD_VOLTAGE_A2_SHIFT          (18U)
/*! CARD_VOLTAGE_A2 - Controls the state of the SD_VOLT2 pin. */
#define SDIF_CTRL_CARD_VOLTAGE_A2(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_CARD_VOLTAGE_A2_SHIFT)) & SDIF_CTRL_CARD_VOLTAGE_A2_MASK)

#define SDIF_CTRL_USE_INTERNAL_DMAC_MASK         (0x2000000U)
#define SDIF_CTRL_USE_INTERNAL_DMAC_SHIFT        (25U)
/*! USE_INTERNAL_DMAC - SD/MMC DMA use. */
#define SDIF_CTRL_USE_INTERNAL_DMAC(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_CTRL_USE_INTERNAL_DMAC_SHIFT)) & SDIF_CTRL_USE_INTERNAL_DMAC_MASK)
/*! @} */

/*! @name PWREN - Power Enable register */
/*! @{ */

#define SDIF_PWREN_POWER_ENABLE0_MASK            (0x1U)
#define SDIF_PWREN_POWER_ENABLE0_SHIFT           (0U)
/*! POWER_ENABLE0 - Power on/off switch for card 0; once power is turned on, software should wait
 *    for regulator/switch ramp-up time before trying to initialize card 0.
 */
#define SDIF_PWREN_POWER_ENABLE0(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_PWREN_POWER_ENABLE0_SHIFT)) & SDIF_PWREN_POWER_ENABLE0_MASK)

#define SDIF_PWREN_POWER_ENABLE1_MASK            (0x2U)
#define SDIF_PWREN_POWER_ENABLE1_SHIFT           (1U)
/*! POWER_ENABLE1 - Power on/off switch for card 1; once power is turned on, software should wait
 *    for regulator/switch ramp-up time before trying to initialize card 1.
 */
#define SDIF_PWREN_POWER_ENABLE1(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_PWREN_POWER_ENABLE1_SHIFT)) & SDIF_PWREN_POWER_ENABLE1_MASK)
/*! @} */

/*! @name CLKDIV - Clock Divider register */
/*! @{ */

#define SDIF_CLKDIV_CLK_DIVIDER0_MASK            (0xFFU)
#define SDIF_CLKDIV_CLK_DIVIDER0_SHIFT           (0U)
/*! CLK_DIVIDER0 - Clock divider-0 value. */
#define SDIF_CLKDIV_CLK_DIVIDER0(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_CLKDIV_CLK_DIVIDER0_SHIFT)) & SDIF_CLKDIV_CLK_DIVIDER0_MASK)
/*! @} */

/*! @name CLKENA - Clock Enable register */
/*! @{ */

#define SDIF_CLKENA_CCLK0_ENABLE_MASK            (0x1U)
#define SDIF_CLKENA_CCLK0_ENABLE_SHIFT           (0U)
/*! CCLK0_ENABLE - Clock-enable control for SD card 0 clock. */
#define SDIF_CLKENA_CCLK0_ENABLE(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_CLKENA_CCLK0_ENABLE_SHIFT)) & SDIF_CLKENA_CCLK0_ENABLE_MASK)

#define SDIF_CLKENA_CCLK1_ENABLE_MASK            (0x2U)
#define SDIF_CLKENA_CCLK1_ENABLE_SHIFT           (1U)
/*! CCLK1_ENABLE - Clock-enable control for SD card 1 clock. */
#define SDIF_CLKENA_CCLK1_ENABLE(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_CLKENA_CCLK1_ENABLE_SHIFT)) & SDIF_CLKENA_CCLK1_ENABLE_MASK)

#define SDIF_CLKENA_CCLK0_LOW_POWER_MASK         (0x10000U)
#define SDIF_CLKENA_CCLK0_LOW_POWER_SHIFT        (16U)
/*! CCLK0_LOW_POWER - Low-power control for SD card 0 clock. */
#define SDIF_CLKENA_CCLK0_LOW_POWER(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_CLKENA_CCLK0_LOW_POWER_SHIFT)) & SDIF_CLKENA_CCLK0_LOW_POWER_MASK)

#define SDIF_CLKENA_CCLK1_LOW_POWER_MASK         (0x20000U)
#define SDIF_CLKENA_CCLK1_LOW_POWER_SHIFT        (17U)
/*! CCLK1_LOW_POWER - Low-power control for SD card 1 clock. */
#define SDIF_CLKENA_CCLK1_LOW_POWER(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_CLKENA_CCLK1_LOW_POWER_SHIFT)) & SDIF_CLKENA_CCLK1_LOW_POWER_MASK)
/*! @} */

/*! @name TMOUT - Time-out register */
/*! @{ */

#define SDIF_TMOUT_RESPONSE_TIMEOUT_MASK         (0xFFU)
#define SDIF_TMOUT_RESPONSE_TIMEOUT_SHIFT        (0U)
/*! RESPONSE_TIMEOUT - Response time-out value. */
#define SDIF_TMOUT_RESPONSE_TIMEOUT(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_TMOUT_RESPONSE_TIMEOUT_SHIFT)) & SDIF_TMOUT_RESPONSE_TIMEOUT_MASK)

#define SDIF_TMOUT_DATA_TIMEOUT_MASK             (0xFFFFFF00U)
#define SDIF_TMOUT_DATA_TIMEOUT_SHIFT            (8U)
/*! DATA_TIMEOUT - Value for card Data Read time-out; same value also used for Data Starvation by Host time-out. */
#define SDIF_TMOUT_DATA_TIMEOUT(x)               (((uint32_t)(((uint32_t)(x)) << SDIF_TMOUT_DATA_TIMEOUT_SHIFT)) & SDIF_TMOUT_DATA_TIMEOUT_MASK)
/*! @} */

/*! @name CTYPE - Card Type register */
/*! @{ */

#define SDIF_CTYPE_CARD0_WIDTH0_MASK             (0x1U)
#define SDIF_CTYPE_CARD0_WIDTH0_SHIFT            (0U)
/*! CARD0_WIDTH0 - Indicates if card 0 is 1-bit or 4-bit: 0 - 1-bit mode 1 - 4-bit mode 1 and 4-bit
 *    modes only work when 8-bit mode in CARD0_WIDTH1 is not enabled (bit 16 in this register is set
 *    to 0).
 */
#define SDIF_CTYPE_CARD0_WIDTH0(x)               (((uint32_t)(((uint32_t)(x)) << SDIF_CTYPE_CARD0_WIDTH0_SHIFT)) & SDIF_CTYPE_CARD0_WIDTH0_MASK)

#define SDIF_CTYPE_CARD1_WIDTH0_MASK             (0x2U)
#define SDIF_CTYPE_CARD1_WIDTH0_SHIFT            (1U)
/*! CARD1_WIDTH0 - Indicates if card 1 is 1-bit or 4-bit: 0 - 1-bit mode 1 - 4-bit mode 1 and 4-bit
 *    modes only work when 8-bit mode in CARD1_WIDTH1 is not enabled (bit 16 in this register is set
 *    to 0).
 */
#define SDIF_CTYPE_CARD1_WIDTH0(x)               (((uint32_t)(((uint32_t)(x)) << SDIF_CTYPE_CARD1_WIDTH0_SHIFT)) & SDIF_CTYPE_CARD1_WIDTH0_MASK)

#define SDIF_CTYPE_CARD0_WIDTH1_MASK             (0x10000U)
#define SDIF_CTYPE_CARD0_WIDTH1_SHIFT            (16U)
/*! CARD0_WIDTH1 - Indicates if card 0 is 8-bit: 0 - Non 8-bit mode 1 - 8-bit mode. */
#define SDIF_CTYPE_CARD0_WIDTH1(x)               (((uint32_t)(((uint32_t)(x)) << SDIF_CTYPE_CARD0_WIDTH1_SHIFT)) & SDIF_CTYPE_CARD0_WIDTH1_MASK)

#define SDIF_CTYPE_CARD1_WIDTH1_MASK             (0x20000U)
#define SDIF_CTYPE_CARD1_WIDTH1_SHIFT            (17U)
/*! CARD1_WIDTH1 - Indicates if card 1 is 8-bit: 0 - Non 8-bit mode 1 - 8-bit mode. */
#define SDIF_CTYPE_CARD1_WIDTH1(x)               (((uint32_t)(((uint32_t)(x)) << SDIF_CTYPE_CARD1_WIDTH1_SHIFT)) & SDIF_CTYPE_CARD1_WIDTH1_MASK)
/*! @} */

/*! @name BLKSIZ - Block Size register */
/*! @{ */

#define SDIF_BLKSIZ_BLOCK_SIZE_MASK              (0xFFFFU)
#define SDIF_BLKSIZ_BLOCK_SIZE_SHIFT             (0U)
/*! BLOCK_SIZE - Block size. */
#define SDIF_BLKSIZ_BLOCK_SIZE(x)                (((uint32_t)(((uint32_t)(x)) << SDIF_BLKSIZ_BLOCK_SIZE_SHIFT)) & SDIF_BLKSIZ_BLOCK_SIZE_MASK)
/*! @} */

/*! @name BYTCNT - Byte Count register */
/*! @{ */

#define SDIF_BYTCNT_BYTE_COUNT_MASK              (0xFFFFFFFFU)
#define SDIF_BYTCNT_BYTE_COUNT_SHIFT             (0U)
/*! BYTE_COUNT - Number of bytes to be transferred; should be integer multiple of Block Size for block transfers. */
#define SDIF_BYTCNT_BYTE_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << SDIF_BYTCNT_BYTE_COUNT_SHIFT)) & SDIF_BYTCNT_BYTE_COUNT_MASK)
/*! @} */

/*! @name INTMASK - Interrupt Mask register */
/*! @{ */

#define SDIF_INTMASK_CDET_MASK                   (0x1U)
#define SDIF_INTMASK_CDET_SHIFT                  (0U)
/*! CDET - Card detect. */
#define SDIF_INTMASK_CDET(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_CDET_SHIFT)) & SDIF_INTMASK_CDET_MASK)

#define SDIF_INTMASK_RE_MASK                     (0x2U)
#define SDIF_INTMASK_RE_SHIFT                    (1U)
/*! RE - Response error. */
#define SDIF_INTMASK_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_RE_SHIFT)) & SDIF_INTMASK_RE_MASK)

#define SDIF_INTMASK_CDONE_MASK                  (0x4U)
#define SDIF_INTMASK_CDONE_SHIFT                 (2U)
/*! CDONE - Command done. */
#define SDIF_INTMASK_CDONE(x)                    (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_CDONE_SHIFT)) & SDIF_INTMASK_CDONE_MASK)

#define SDIF_INTMASK_DTO_MASK                    (0x8U)
#define SDIF_INTMASK_DTO_SHIFT                   (3U)
/*! DTO - Data transfer over. */
#define SDIF_INTMASK_DTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_DTO_SHIFT)) & SDIF_INTMASK_DTO_MASK)

#define SDIF_INTMASK_TXDR_MASK                   (0x10U)
#define SDIF_INTMASK_TXDR_SHIFT                  (4U)
/*! TXDR - Transmit FIFO data request. */
#define SDIF_INTMASK_TXDR(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_TXDR_SHIFT)) & SDIF_INTMASK_TXDR_MASK)

#define SDIF_INTMASK_RXDR_MASK                   (0x20U)
#define SDIF_INTMASK_RXDR_SHIFT                  (5U)
/*! RXDR - Receive FIFO data request. */
#define SDIF_INTMASK_RXDR(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_RXDR_SHIFT)) & SDIF_INTMASK_RXDR_MASK)

#define SDIF_INTMASK_RCRC_MASK                   (0x40U)
#define SDIF_INTMASK_RCRC_SHIFT                  (6U)
/*! RCRC - Response CRC error. */
#define SDIF_INTMASK_RCRC(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_RCRC_SHIFT)) & SDIF_INTMASK_RCRC_MASK)

#define SDIF_INTMASK_DCRC_MASK                   (0x80U)
#define SDIF_INTMASK_DCRC_SHIFT                  (7U)
/*! DCRC - Data CRC error. */
#define SDIF_INTMASK_DCRC(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_DCRC_SHIFT)) & SDIF_INTMASK_DCRC_MASK)

#define SDIF_INTMASK_RTO_MASK                    (0x100U)
#define SDIF_INTMASK_RTO_SHIFT                   (8U)
/*! RTO - Response time-out. */
#define SDIF_INTMASK_RTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_RTO_SHIFT)) & SDIF_INTMASK_RTO_MASK)

#define SDIF_INTMASK_DRTO_MASK                   (0x200U)
#define SDIF_INTMASK_DRTO_SHIFT                  (9U)
/*! DRTO - Data read time-out. */
#define SDIF_INTMASK_DRTO(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_DRTO_SHIFT)) & SDIF_INTMASK_DRTO_MASK)

#define SDIF_INTMASK_HTO_MASK                    (0x400U)
#define SDIF_INTMASK_HTO_SHIFT                   (10U)
/*! HTO - Data starvation-by-host time-out (HTO). */
#define SDIF_INTMASK_HTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_HTO_SHIFT)) & SDIF_INTMASK_HTO_MASK)

#define SDIF_INTMASK_FRUN_MASK                   (0x800U)
#define SDIF_INTMASK_FRUN_SHIFT                  (11U)
/*! FRUN - FIFO underrun/overrun error. */
#define SDIF_INTMASK_FRUN(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_FRUN_SHIFT)) & SDIF_INTMASK_FRUN_MASK)

#define SDIF_INTMASK_HLE_MASK                    (0x1000U)
#define SDIF_INTMASK_HLE_SHIFT                   (12U)
/*! HLE - Hardware locked write error. */
#define SDIF_INTMASK_HLE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_HLE_SHIFT)) & SDIF_INTMASK_HLE_MASK)

#define SDIF_INTMASK_SBE_MASK                    (0x2000U)
#define SDIF_INTMASK_SBE_SHIFT                   (13U)
/*! SBE - Start-bit error. */
#define SDIF_INTMASK_SBE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_SBE_SHIFT)) & SDIF_INTMASK_SBE_MASK)

#define SDIF_INTMASK_ACD_MASK                    (0x4000U)
#define SDIF_INTMASK_ACD_SHIFT                   (14U)
/*! ACD - Auto command done. */
#define SDIF_INTMASK_ACD(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_ACD_SHIFT)) & SDIF_INTMASK_ACD_MASK)

#define SDIF_INTMASK_EBE_MASK                    (0x8000U)
#define SDIF_INTMASK_EBE_SHIFT                   (15U)
/*! EBE - End-bit error (read)/Write no CRC. */
#define SDIF_INTMASK_EBE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_EBE_SHIFT)) & SDIF_INTMASK_EBE_MASK)

#define SDIF_INTMASK_SDIO_INT_MASK_MASK          (0x10000U)
#define SDIF_INTMASK_SDIO_INT_MASK_SHIFT         (16U)
/*! SDIO_INT_MASK - Mask SDIO interrupt. */
#define SDIF_INTMASK_SDIO_INT_MASK(x)            (((uint32_t)(((uint32_t)(x)) << SDIF_INTMASK_SDIO_INT_MASK_SHIFT)) & SDIF_INTMASK_SDIO_INT_MASK_MASK)
/*! @} */

/*! @name CMDARG - Command Argument register */
/*! @{ */

#define SDIF_CMDARG_CMD_ARG_MASK                 (0xFFFFFFFFU)
#define SDIF_CMDARG_CMD_ARG_SHIFT                (0U)
/*! CMD_ARG - Value indicates command argument to be passed to card. */
#define SDIF_CMDARG_CMD_ARG(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_CMDARG_CMD_ARG_SHIFT)) & SDIF_CMDARG_CMD_ARG_MASK)
/*! @} */

/*! @name CMD - Command register */
/*! @{ */

#define SDIF_CMD_CMD_INDEX_MASK                  (0x3FU)
#define SDIF_CMD_CMD_INDEX_SHIFT                 (0U)
/*! CMD_INDEX - Command index. */
#define SDIF_CMD_CMD_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_CMD_INDEX_SHIFT)) & SDIF_CMD_CMD_INDEX_MASK)

#define SDIF_CMD_RESPONSE_EXPECT_MASK            (0x40U)
#define SDIF_CMD_RESPONSE_EXPECT_SHIFT           (6U)
/*! RESPONSE_EXPECT - Response expect. */
#define SDIF_CMD_RESPONSE_EXPECT(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_RESPONSE_EXPECT_SHIFT)) & SDIF_CMD_RESPONSE_EXPECT_MASK)

#define SDIF_CMD_RESPONSE_LENGTH_MASK            (0x80U)
#define SDIF_CMD_RESPONSE_LENGTH_SHIFT           (7U)
/*! RESPONSE_LENGTH - Response length. */
#define SDIF_CMD_RESPONSE_LENGTH(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_RESPONSE_LENGTH_SHIFT)) & SDIF_CMD_RESPONSE_LENGTH_MASK)

#define SDIF_CMD_CHECK_RESPONSE_CRC_MASK         (0x100U)
#define SDIF_CMD_CHECK_RESPONSE_CRC_SHIFT        (8U)
/*! CHECK_RESPONSE_CRC - Check response CRC. */
#define SDIF_CMD_CHECK_RESPONSE_CRC(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_CHECK_RESPONSE_CRC_SHIFT)) & SDIF_CMD_CHECK_RESPONSE_CRC_MASK)

#define SDIF_CMD_DATA_EXPECTED_MASK              (0x200U)
#define SDIF_CMD_DATA_EXPECTED_SHIFT             (9U)
/*! DATA_EXPECTED - Data expected. */
#define SDIF_CMD_DATA_EXPECTED(x)                (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_DATA_EXPECTED_SHIFT)) & SDIF_CMD_DATA_EXPECTED_MASK)

#define SDIF_CMD_READ_WRITE_MASK                 (0x400U)
#define SDIF_CMD_READ_WRITE_SHIFT                (10U)
/*! READ_WRITE - read/write. */
#define SDIF_CMD_READ_WRITE(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_READ_WRITE_SHIFT)) & SDIF_CMD_READ_WRITE_MASK)

#define SDIF_CMD_TRANSFER_MODE_MASK              (0x800U)
#define SDIF_CMD_TRANSFER_MODE_SHIFT             (11U)
/*! TRANSFER_MODE - Transfer mode. */
#define SDIF_CMD_TRANSFER_MODE(x)                (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_TRANSFER_MODE_SHIFT)) & SDIF_CMD_TRANSFER_MODE_MASK)

#define SDIF_CMD_SEND_AUTO_STOP_MASK             (0x1000U)
#define SDIF_CMD_SEND_AUTO_STOP_SHIFT            (12U)
/*! SEND_AUTO_STOP - Send auto stop. */
#define SDIF_CMD_SEND_AUTO_STOP(x)               (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_SEND_AUTO_STOP_SHIFT)) & SDIF_CMD_SEND_AUTO_STOP_MASK)

#define SDIF_CMD_WAIT_PRVDATA_COMPLETE_MASK      (0x2000U)
#define SDIF_CMD_WAIT_PRVDATA_COMPLETE_SHIFT     (13U)
/*! WAIT_PRVDATA_COMPLETE - Wait prvdata complete. */
#define SDIF_CMD_WAIT_PRVDATA_COMPLETE(x)        (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_WAIT_PRVDATA_COMPLETE_SHIFT)) & SDIF_CMD_WAIT_PRVDATA_COMPLETE_MASK)

#define SDIF_CMD_STOP_ABORT_CMD_MASK             (0x4000U)
#define SDIF_CMD_STOP_ABORT_CMD_SHIFT            (14U)
/*! STOP_ABORT_CMD - Stop abort command. */
#define SDIF_CMD_STOP_ABORT_CMD(x)               (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_STOP_ABORT_CMD_SHIFT)) & SDIF_CMD_STOP_ABORT_CMD_MASK)

#define SDIF_CMD_SEND_INITIALIZATION_MASK        (0x8000U)
#define SDIF_CMD_SEND_INITIALIZATION_SHIFT       (15U)
/*! SEND_INITIALIZATION - Send initialization. */
#define SDIF_CMD_SEND_INITIALIZATION(x)          (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_SEND_INITIALIZATION_SHIFT)) & SDIF_CMD_SEND_INITIALIZATION_MASK)

#define SDIF_CMD_CARD_NUMBER_MASK                (0x1F0000U)
#define SDIF_CMD_CARD_NUMBER_SHIFT               (16U)
/*! CARD_NUMBER - Specifies the card number of SDCARD for which the current Command is being executed
 *  0b00000..Command will be execute on SDCARD 0
 *  0b00001..Command will be execute on SDCARD 1
 */
#define SDIF_CMD_CARD_NUMBER(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_CARD_NUMBER_SHIFT)) & SDIF_CMD_CARD_NUMBER_MASK)

#define SDIF_CMD_UPDATE_CLOCK_REGISTERS_ONLY_MASK (0x200000U)
#define SDIF_CMD_UPDATE_CLOCK_REGISTERS_ONLY_SHIFT (21U)
/*! UPDATE_CLOCK_REGISTERS_ONLY - Update clock registers only. */
#define SDIF_CMD_UPDATE_CLOCK_REGISTERS_ONLY(x)  (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_UPDATE_CLOCK_REGISTERS_ONLY_SHIFT)) & SDIF_CMD_UPDATE_CLOCK_REGISTERS_ONLY_MASK)

#define SDIF_CMD_READ_CEATA_DEVICE_MASK          (0x400000U)
#define SDIF_CMD_READ_CEATA_DEVICE_SHIFT         (22U)
/*! READ_CEATA_DEVICE - Read ceata device. */
#define SDIF_CMD_READ_CEATA_DEVICE(x)            (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_READ_CEATA_DEVICE_SHIFT)) & SDIF_CMD_READ_CEATA_DEVICE_MASK)

#define SDIF_CMD_CCS_EXPECTED_MASK               (0x800000U)
#define SDIF_CMD_CCS_EXPECTED_SHIFT              (23U)
/*! CCS_EXPECTED - CCS expected. */
#define SDIF_CMD_CCS_EXPECTED(x)                 (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_CCS_EXPECTED_SHIFT)) & SDIF_CMD_CCS_EXPECTED_MASK)

#define SDIF_CMD_ENABLE_BOOT_MASK                (0x1000000U)
#define SDIF_CMD_ENABLE_BOOT_SHIFT               (24U)
/*! ENABLE_BOOT - Enable Boot - this bit should be set only for mandatory boot mode. */
#define SDIF_CMD_ENABLE_BOOT(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_ENABLE_BOOT_SHIFT)) & SDIF_CMD_ENABLE_BOOT_MASK)

#define SDIF_CMD_EXPECT_BOOT_ACK_MASK            (0x2000000U)
#define SDIF_CMD_EXPECT_BOOT_ACK_SHIFT           (25U)
/*! EXPECT_BOOT_ACK - Expect Boot Acknowledge. */
#define SDIF_CMD_EXPECT_BOOT_ACK(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_EXPECT_BOOT_ACK_SHIFT)) & SDIF_CMD_EXPECT_BOOT_ACK_MASK)

#define SDIF_CMD_DISABLE_BOOT_MASK               (0x4000000U)
#define SDIF_CMD_DISABLE_BOOT_SHIFT              (26U)
/*! DISABLE_BOOT - Disable Boot. */
#define SDIF_CMD_DISABLE_BOOT(x)                 (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_DISABLE_BOOT_SHIFT)) & SDIF_CMD_DISABLE_BOOT_MASK)

#define SDIF_CMD_BOOT_MODE_MASK                  (0x8000000U)
#define SDIF_CMD_BOOT_MODE_SHIFT                 (27U)
/*! BOOT_MODE - Boot Mode. */
#define SDIF_CMD_BOOT_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_BOOT_MODE_SHIFT)) & SDIF_CMD_BOOT_MODE_MASK)

#define SDIF_CMD_VOLT_SWITCH_MASK                (0x10000000U)
#define SDIF_CMD_VOLT_SWITCH_SHIFT               (28U)
/*! VOLT_SWITCH - Voltage switch bit. */
#define SDIF_CMD_VOLT_SWITCH(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_VOLT_SWITCH_SHIFT)) & SDIF_CMD_VOLT_SWITCH_MASK)

#define SDIF_CMD_USE_HOLD_REG_MASK               (0x20000000U)
#define SDIF_CMD_USE_HOLD_REG_SHIFT              (29U)
/*! USE_HOLD_REG - Use Hold Register. */
#define SDIF_CMD_USE_HOLD_REG(x)                 (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_USE_HOLD_REG_SHIFT)) & SDIF_CMD_USE_HOLD_REG_MASK)

#define SDIF_CMD_START_CMD_MASK                  (0x80000000U)
#define SDIF_CMD_START_CMD_SHIFT                 (31U)
/*! START_CMD - Start command. */
#define SDIF_CMD_START_CMD(x)                    (((uint32_t)(((uint32_t)(x)) << SDIF_CMD_START_CMD_SHIFT)) & SDIF_CMD_START_CMD_MASK)
/*! @} */

/*! @name RESP - Response register */
/*! @{ */

#define SDIF_RESP_RESPONSE_MASK                  (0xFFFFFFFFU)
#define SDIF_RESP_RESPONSE_SHIFT                 (0U)
/*! RESPONSE - Bits of response. */
#define SDIF_RESP_RESPONSE(x)                    (((uint32_t)(((uint32_t)(x)) << SDIF_RESP_RESPONSE_SHIFT)) & SDIF_RESP_RESPONSE_MASK)
/*! @} */

/*! @name MINTSTS - Masked Interrupt Status register */
/*! @{ */

#define SDIF_MINTSTS_CDET_MASK                   (0x1U)
#define SDIF_MINTSTS_CDET_SHIFT                  (0U)
/*! CDET - Card detect. */
#define SDIF_MINTSTS_CDET(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_CDET_SHIFT)) & SDIF_MINTSTS_CDET_MASK)

#define SDIF_MINTSTS_RE_MASK                     (0x2U)
#define SDIF_MINTSTS_RE_SHIFT                    (1U)
/*! RE - Response error. */
#define SDIF_MINTSTS_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_RE_SHIFT)) & SDIF_MINTSTS_RE_MASK)

#define SDIF_MINTSTS_CDONE_MASK                  (0x4U)
#define SDIF_MINTSTS_CDONE_SHIFT                 (2U)
/*! CDONE - Command done. */
#define SDIF_MINTSTS_CDONE(x)                    (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_CDONE_SHIFT)) & SDIF_MINTSTS_CDONE_MASK)

#define SDIF_MINTSTS_DTO_MASK                    (0x8U)
#define SDIF_MINTSTS_DTO_SHIFT                   (3U)
/*! DTO - Data transfer over. */
#define SDIF_MINTSTS_DTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_DTO_SHIFT)) & SDIF_MINTSTS_DTO_MASK)

#define SDIF_MINTSTS_TXDR_MASK                   (0x10U)
#define SDIF_MINTSTS_TXDR_SHIFT                  (4U)
/*! TXDR - Transmit FIFO data request. */
#define SDIF_MINTSTS_TXDR(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_TXDR_SHIFT)) & SDIF_MINTSTS_TXDR_MASK)

#define SDIF_MINTSTS_RXDR_MASK                   (0x20U)
#define SDIF_MINTSTS_RXDR_SHIFT                  (5U)
/*! RXDR - Receive FIFO data request. */
#define SDIF_MINTSTS_RXDR(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_RXDR_SHIFT)) & SDIF_MINTSTS_RXDR_MASK)

#define SDIF_MINTSTS_RCRC_MASK                   (0x40U)
#define SDIF_MINTSTS_RCRC_SHIFT                  (6U)
/*! RCRC - Response CRC error. */
#define SDIF_MINTSTS_RCRC(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_RCRC_SHIFT)) & SDIF_MINTSTS_RCRC_MASK)

#define SDIF_MINTSTS_DCRC_MASK                   (0x80U)
#define SDIF_MINTSTS_DCRC_SHIFT                  (7U)
/*! DCRC - Data CRC error. */
#define SDIF_MINTSTS_DCRC(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_DCRC_SHIFT)) & SDIF_MINTSTS_DCRC_MASK)

#define SDIF_MINTSTS_RTO_MASK                    (0x100U)
#define SDIF_MINTSTS_RTO_SHIFT                   (8U)
/*! RTO - Response time-out. */
#define SDIF_MINTSTS_RTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_RTO_SHIFT)) & SDIF_MINTSTS_RTO_MASK)

#define SDIF_MINTSTS_DRTO_MASK                   (0x200U)
#define SDIF_MINTSTS_DRTO_SHIFT                  (9U)
/*! DRTO - Data read time-out. */
#define SDIF_MINTSTS_DRTO(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_DRTO_SHIFT)) & SDIF_MINTSTS_DRTO_MASK)

#define SDIF_MINTSTS_HTO_MASK                    (0x400U)
#define SDIF_MINTSTS_HTO_SHIFT                   (10U)
/*! HTO - Data starvation-by-host time-out (HTO). */
#define SDIF_MINTSTS_HTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_HTO_SHIFT)) & SDIF_MINTSTS_HTO_MASK)

#define SDIF_MINTSTS_FRUN_MASK                   (0x800U)
#define SDIF_MINTSTS_FRUN_SHIFT                  (11U)
/*! FRUN - FIFO underrun/overrun error. */
#define SDIF_MINTSTS_FRUN(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_FRUN_SHIFT)) & SDIF_MINTSTS_FRUN_MASK)

#define SDIF_MINTSTS_HLE_MASK                    (0x1000U)
#define SDIF_MINTSTS_HLE_SHIFT                   (12U)
/*! HLE - Hardware locked write error. */
#define SDIF_MINTSTS_HLE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_HLE_SHIFT)) & SDIF_MINTSTS_HLE_MASK)

#define SDIF_MINTSTS_SBE_MASK                    (0x2000U)
#define SDIF_MINTSTS_SBE_SHIFT                   (13U)
/*! SBE - Start-bit error. */
#define SDIF_MINTSTS_SBE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_SBE_SHIFT)) & SDIF_MINTSTS_SBE_MASK)

#define SDIF_MINTSTS_ACD_MASK                    (0x4000U)
#define SDIF_MINTSTS_ACD_SHIFT                   (14U)
/*! ACD - Auto command done. */
#define SDIF_MINTSTS_ACD(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_ACD_SHIFT)) & SDIF_MINTSTS_ACD_MASK)

#define SDIF_MINTSTS_EBE_MASK                    (0x8000U)
#define SDIF_MINTSTS_EBE_SHIFT                   (15U)
/*! EBE - End-bit error (read)/write no CRC. */
#define SDIF_MINTSTS_EBE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_EBE_SHIFT)) & SDIF_MINTSTS_EBE_MASK)

#define SDIF_MINTSTS_SDIO_INTERRUPT_MASK         (0x10000U)
#define SDIF_MINTSTS_SDIO_INTERRUPT_SHIFT        (16U)
/*! SDIO_INTERRUPT - Interrupt from SDIO card. */
#define SDIF_MINTSTS_SDIO_INTERRUPT(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_MINTSTS_SDIO_INTERRUPT_SHIFT)) & SDIF_MINTSTS_SDIO_INTERRUPT_MASK)
/*! @} */

/*! @name RINTSTS - Raw Interrupt Status register */
/*! @{ */

#define SDIF_RINTSTS_CDET_MASK                   (0x1U)
#define SDIF_RINTSTS_CDET_SHIFT                  (0U)
/*! CDET - Card detect. */
#define SDIF_RINTSTS_CDET(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_CDET_SHIFT)) & SDIF_RINTSTS_CDET_MASK)

#define SDIF_RINTSTS_RE_MASK                     (0x2U)
#define SDIF_RINTSTS_RE_SHIFT                    (1U)
/*! RE - Response error. */
#define SDIF_RINTSTS_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_RE_SHIFT)) & SDIF_RINTSTS_RE_MASK)

#define SDIF_RINTSTS_CDONE_MASK                  (0x4U)
#define SDIF_RINTSTS_CDONE_SHIFT                 (2U)
/*! CDONE - Command done. */
#define SDIF_RINTSTS_CDONE(x)                    (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_CDONE_SHIFT)) & SDIF_RINTSTS_CDONE_MASK)

#define SDIF_RINTSTS_DTO_MASK                    (0x8U)
#define SDIF_RINTSTS_DTO_SHIFT                   (3U)
/*! DTO - Data transfer over. */
#define SDIF_RINTSTS_DTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_DTO_SHIFT)) & SDIF_RINTSTS_DTO_MASK)

#define SDIF_RINTSTS_TXDR_MASK                   (0x10U)
#define SDIF_RINTSTS_TXDR_SHIFT                  (4U)
/*! TXDR - Transmit FIFO data request. */
#define SDIF_RINTSTS_TXDR(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_TXDR_SHIFT)) & SDIF_RINTSTS_TXDR_MASK)

#define SDIF_RINTSTS_RXDR_MASK                   (0x20U)
#define SDIF_RINTSTS_RXDR_SHIFT                  (5U)
/*! RXDR - Receive FIFO data request. */
#define SDIF_RINTSTS_RXDR(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_RXDR_SHIFT)) & SDIF_RINTSTS_RXDR_MASK)

#define SDIF_RINTSTS_RCRC_MASK                   (0x40U)
#define SDIF_RINTSTS_RCRC_SHIFT                  (6U)
/*! RCRC - Response CRC error. */
#define SDIF_RINTSTS_RCRC(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_RCRC_SHIFT)) & SDIF_RINTSTS_RCRC_MASK)

#define SDIF_RINTSTS_DCRC_MASK                   (0x80U)
#define SDIF_RINTSTS_DCRC_SHIFT                  (7U)
/*! DCRC - Data CRC error. */
#define SDIF_RINTSTS_DCRC(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_DCRC_SHIFT)) & SDIF_RINTSTS_DCRC_MASK)

#define SDIF_RINTSTS_RTO_BAR_MASK                (0x100U)
#define SDIF_RINTSTS_RTO_BAR_SHIFT               (8U)
/*! RTO_BAR - Response time-out (RTO)/Boot Ack Received (BAR). */
#define SDIF_RINTSTS_RTO_BAR(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_RTO_BAR_SHIFT)) & SDIF_RINTSTS_RTO_BAR_MASK)

#define SDIF_RINTSTS_DRTO_BDS_MASK               (0x200U)
#define SDIF_RINTSTS_DRTO_BDS_SHIFT              (9U)
/*! DRTO_BDS - Data read time-out (DRTO)/Boot Data Start (BDS). */
#define SDIF_RINTSTS_DRTO_BDS(x)                 (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_DRTO_BDS_SHIFT)) & SDIF_RINTSTS_DRTO_BDS_MASK)

#define SDIF_RINTSTS_HTO_MASK                    (0x400U)
#define SDIF_RINTSTS_HTO_SHIFT                   (10U)
/*! HTO - Data starvation-by-host time-out (HTO). */
#define SDIF_RINTSTS_HTO(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_HTO_SHIFT)) & SDIF_RINTSTS_HTO_MASK)

#define SDIF_RINTSTS_FRUN_MASK                   (0x800U)
#define SDIF_RINTSTS_FRUN_SHIFT                  (11U)
/*! FRUN - FIFO underrun/overrun error. */
#define SDIF_RINTSTS_FRUN(x)                     (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_FRUN_SHIFT)) & SDIF_RINTSTS_FRUN_MASK)

#define SDIF_RINTSTS_HLE_MASK                    (0x1000U)
#define SDIF_RINTSTS_HLE_SHIFT                   (12U)
/*! HLE - Hardware locked write error. */
#define SDIF_RINTSTS_HLE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_HLE_SHIFT)) & SDIF_RINTSTS_HLE_MASK)

#define SDIF_RINTSTS_SBE_MASK                    (0x2000U)
#define SDIF_RINTSTS_SBE_SHIFT                   (13U)
/*! SBE - Start-bit error. */
#define SDIF_RINTSTS_SBE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_SBE_SHIFT)) & SDIF_RINTSTS_SBE_MASK)

#define SDIF_RINTSTS_ACD_MASK                    (0x4000U)
#define SDIF_RINTSTS_ACD_SHIFT                   (14U)
/*! ACD - Auto command done. */
#define SDIF_RINTSTS_ACD(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_ACD_SHIFT)) & SDIF_RINTSTS_ACD_MASK)

#define SDIF_RINTSTS_EBE_MASK                    (0x8000U)
#define SDIF_RINTSTS_EBE_SHIFT                   (15U)
/*! EBE - End-bit error (read)/write no CRC. */
#define SDIF_RINTSTS_EBE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_EBE_SHIFT)) & SDIF_RINTSTS_EBE_MASK)

#define SDIF_RINTSTS_SDIO_INTERRUPT_MASK         (0x10000U)
#define SDIF_RINTSTS_SDIO_INTERRUPT_SHIFT        (16U)
/*! SDIO_INTERRUPT - Interrupt from SDIO card. */
#define SDIF_RINTSTS_SDIO_INTERRUPT(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_RINTSTS_SDIO_INTERRUPT_SHIFT)) & SDIF_RINTSTS_SDIO_INTERRUPT_MASK)
/*! @} */

/*! @name STATUS - Status register */
/*! @{ */

#define SDIF_STATUS_FIFO_RX_WATERMARK_MASK       (0x1U)
#define SDIF_STATUS_FIFO_RX_WATERMARK_SHIFT      (0U)
/*! FIFO_RX_WATERMARK - FIFO reached Receive watermark level; not qualified with data transfer. */
#define SDIF_STATUS_FIFO_RX_WATERMARK(x)         (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_FIFO_RX_WATERMARK_SHIFT)) & SDIF_STATUS_FIFO_RX_WATERMARK_MASK)

#define SDIF_STATUS_FIFO_TX_WATERMARK_MASK       (0x2U)
#define SDIF_STATUS_FIFO_TX_WATERMARK_SHIFT      (1U)
/*! FIFO_TX_WATERMARK - FIFO reached Transmit watermark level; not qualified with data transfer. */
#define SDIF_STATUS_FIFO_TX_WATERMARK(x)         (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_FIFO_TX_WATERMARK_SHIFT)) & SDIF_STATUS_FIFO_TX_WATERMARK_MASK)

#define SDIF_STATUS_FIFO_EMPTY_MASK              (0x4U)
#define SDIF_STATUS_FIFO_EMPTY_SHIFT             (2U)
/*! FIFO_EMPTY - FIFO is empty status. */
#define SDIF_STATUS_FIFO_EMPTY(x)                (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_FIFO_EMPTY_SHIFT)) & SDIF_STATUS_FIFO_EMPTY_MASK)

#define SDIF_STATUS_FIFO_FULL_MASK               (0x8U)
#define SDIF_STATUS_FIFO_FULL_SHIFT              (3U)
/*! FIFO_FULL - FIFO is full status. */
#define SDIF_STATUS_FIFO_FULL(x)                 (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_FIFO_FULL_SHIFT)) & SDIF_STATUS_FIFO_FULL_MASK)

#define SDIF_STATUS_CMDFSMSTATES_MASK            (0xF0U)
#define SDIF_STATUS_CMDFSMSTATES_SHIFT           (4U)
/*! CMDFSMSTATES - Command FSM states: 0 - Idle 1 - Send init sequence 2 - Tx cmd start bit 3 - Tx
 *    cmd tx bit 4 - Tx cmd index + arg 5 - Tx cmd crc7 6 - Tx cmd end bit 7 - Rx resp start bit 8 -
 *    Rx resp IRQ response 9 - Rx resp tx bit 10 - Rx resp cmd idx 11 - Rx resp data 12 - Rx resp
 *    crc7 13 - Rx resp end bit 14 - Cmd path wait NCC 15 - Wait; CMD-to-response turnaround NOTE: The
 *    command FSM state is represented using 19 bits.
 */
#define SDIF_STATUS_CMDFSMSTATES(x)              (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_CMDFSMSTATES_SHIFT)) & SDIF_STATUS_CMDFSMSTATES_MASK)

#define SDIF_STATUS_DATA_3_STATUS_MASK           (0x100U)
#define SDIF_STATUS_DATA_3_STATUS_SHIFT          (8U)
/*! DATA_3_STATUS - Raw selected card_data[3]; checks whether card is present 0 - card not present 1 - card present. */
#define SDIF_STATUS_DATA_3_STATUS(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_DATA_3_STATUS_SHIFT)) & SDIF_STATUS_DATA_3_STATUS_MASK)

#define SDIF_STATUS_DATA_BUSY_MASK               (0x200U)
#define SDIF_STATUS_DATA_BUSY_SHIFT              (9U)
/*! DATA_BUSY - Inverted version of raw selected card_data[0] 0 - card data not busy 1 - card data busy. */
#define SDIF_STATUS_DATA_BUSY(x)                 (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_DATA_BUSY_SHIFT)) & SDIF_STATUS_DATA_BUSY_MASK)

#define SDIF_STATUS_DATA_STATE_MC_BUSY_MASK      (0x400U)
#define SDIF_STATUS_DATA_STATE_MC_BUSY_SHIFT     (10U)
/*! DATA_STATE_MC_BUSY - Data transmit or receive state-machine is busy. */
#define SDIF_STATUS_DATA_STATE_MC_BUSY(x)        (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_DATA_STATE_MC_BUSY_SHIFT)) & SDIF_STATUS_DATA_STATE_MC_BUSY_MASK)

#define SDIF_STATUS_RESPONSE_INDEX_MASK          (0x1F800U)
#define SDIF_STATUS_RESPONSE_INDEX_SHIFT         (11U)
/*! RESPONSE_INDEX - Index of previous response, including any auto-stop sent by core. */
#define SDIF_STATUS_RESPONSE_INDEX(x)            (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_RESPONSE_INDEX_SHIFT)) & SDIF_STATUS_RESPONSE_INDEX_MASK)

#define SDIF_STATUS_FIFO_COUNT_MASK              (0x3FFE0000U)
#define SDIF_STATUS_FIFO_COUNT_SHIFT             (17U)
/*! FIFO_COUNT - FIFO count - Number of filled locations in FIFO. */
#define SDIF_STATUS_FIFO_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_FIFO_COUNT_SHIFT)) & SDIF_STATUS_FIFO_COUNT_MASK)

#define SDIF_STATUS_DMA_ACK_MASK                 (0x40000000U)
#define SDIF_STATUS_DMA_ACK_SHIFT                (30U)
/*! DMA_ACK - DMA acknowledge signal state. */
#define SDIF_STATUS_DMA_ACK(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_DMA_ACK_SHIFT)) & SDIF_STATUS_DMA_ACK_MASK)

#define SDIF_STATUS_DMA_REQ_MASK                 (0x80000000U)
#define SDIF_STATUS_DMA_REQ_SHIFT                (31U)
/*! DMA_REQ - DMA request signal state. */
#define SDIF_STATUS_DMA_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_STATUS_DMA_REQ_SHIFT)) & SDIF_STATUS_DMA_REQ_MASK)
/*! @} */

/*! @name FIFOTH - FIFO Threshold Watermark register */
/*! @{ */

#define SDIF_FIFOTH_TX_WMARK_MASK                (0xFFFU)
#define SDIF_FIFOTH_TX_WMARK_SHIFT               (0U)
/*! TX_WMARK - FIFO threshold watermark level when transmitting data to card. */
#define SDIF_FIFOTH_TX_WMARK(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_FIFOTH_TX_WMARK_SHIFT)) & SDIF_FIFOTH_TX_WMARK_MASK)

#define SDIF_FIFOTH_RX_WMARK_MASK                (0xFFF0000U)
#define SDIF_FIFOTH_RX_WMARK_SHIFT               (16U)
/*! RX_WMARK - FIFO threshold watermark level when receiving data to card. */
#define SDIF_FIFOTH_RX_WMARK(x)                  (((uint32_t)(((uint32_t)(x)) << SDIF_FIFOTH_RX_WMARK_SHIFT)) & SDIF_FIFOTH_RX_WMARK_MASK)

#define SDIF_FIFOTH_DMA_MTS_MASK                 (0x70000000U)
#define SDIF_FIFOTH_DMA_MTS_SHIFT                (28U)
/*! DMA_MTS - Burst size of multiple transaction; should be programmed same as DW-DMA controller
 *    multiple-transaction-size SRC/DEST_MSIZE.
 */
#define SDIF_FIFOTH_DMA_MTS(x)                   (((uint32_t)(((uint32_t)(x)) << SDIF_FIFOTH_DMA_MTS_SHIFT)) & SDIF_FIFOTH_DMA_MTS_MASK)
/*! @} */

/*! @name CDETECT - Card Detect register */
/*! @{ */

#define SDIF_CDETECT_CARD0_DETECT_MASK           (0x1U)
#define SDIF_CDETECT_CARD0_DETECT_SHIFT          (0U)
/*! CARD0_DETECT - Card 0 detect */
#define SDIF_CDETECT_CARD0_DETECT(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_CDETECT_CARD0_DETECT_SHIFT)) & SDIF_CDETECT_CARD0_DETECT_MASK)

#define SDIF_CDETECT_CARD1_DETECT_MASK           (0x2U)
#define SDIF_CDETECT_CARD1_DETECT_SHIFT          (1U)
/*! CARD1_DETECT - Card 1 detect */
#define SDIF_CDETECT_CARD1_DETECT(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_CDETECT_CARD1_DETECT_SHIFT)) & SDIF_CDETECT_CARD1_DETECT_MASK)
/*! @} */

/*! @name WRTPRT - Write Protect register */
/*! @{ */

#define SDIF_WRTPRT_WRITE_PROTECT_MASK           (0x1U)
#define SDIF_WRTPRT_WRITE_PROTECT_SHIFT          (0U)
/*! WRITE_PROTECT - Write protect. */
#define SDIF_WRTPRT_WRITE_PROTECT(x)             (((uint32_t)(((uint32_t)(x)) << SDIF_WRTPRT_WRITE_PROTECT_SHIFT)) & SDIF_WRTPRT_WRITE_PROTECT_MASK)
/*! @} */

/*! @name TCBCNT - Transferred CIU Card Byte Count register */
/*! @{ */

#define SDIF_TCBCNT_TRANS_CARD_BYTE_COUNT_MASK   (0xFFFFFFFFU)
#define SDIF_TCBCNT_TRANS_CARD_BYTE_COUNT_SHIFT  (0U)
/*! TRANS_CARD_BYTE_COUNT - Number of bytes transferred by CIU unit to card. */
#define SDIF_TCBCNT_TRANS_CARD_BYTE_COUNT(x)     (((uint32_t)(((uint32_t)(x)) << SDIF_TCBCNT_TRANS_CARD_BYTE_COUNT_SHIFT)) & SDIF_TCBCNT_TRANS_CARD_BYTE_COUNT_MASK)
/*! @} */

/*! @name TBBCNT - Transferred Host to BIU-FIFO Byte Count register */
/*! @{ */

#define SDIF_TBBCNT_TRANS_FIFO_BYTE_COUNT_MASK   (0xFFFFFFFFU)
#define SDIF_TBBCNT_TRANS_FIFO_BYTE_COUNT_SHIFT  (0U)
/*! TRANS_FIFO_BYTE_COUNT - Number of bytes transferred between Host/DMA memory and BIU FIFO. */
#define SDIF_TBBCNT_TRANS_FIFO_BYTE_COUNT(x)     (((uint32_t)(((uint32_t)(x)) << SDIF_TBBCNT_TRANS_FIFO_BYTE_COUNT_SHIFT)) & SDIF_TBBCNT_TRANS_FIFO_BYTE_COUNT_MASK)
/*! @} */

/*! @name DEBNCE - Debounce Count register */
/*! @{ */

#define SDIF_DEBNCE_DEBOUNCE_COUNT_MASK          (0xFFFFFFU)
#define SDIF_DEBNCE_DEBOUNCE_COUNT_SHIFT         (0U)
/*! DEBOUNCE_COUNT - Number of host clocks (SD_CLK) used by debounce filter logic for card detect; typical debounce time is 5-25 ms. */
#define SDIF_DEBNCE_DEBOUNCE_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << SDIF_DEBNCE_DEBOUNCE_COUNT_SHIFT)) & SDIF_DEBNCE_DEBOUNCE_COUNT_MASK)
/*! @} */

/*! @name RST_N - Hardware Reset */
/*! @{ */

#define SDIF_RST_N_CARD_RESET_MASK               (0x1U)
#define SDIF_RST_N_CARD_RESET_SHIFT              (0U)
/*! CARD_RESET - Hardware reset. */
#define SDIF_RST_N_CARD_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SDIF_RST_N_CARD_RESET_SHIFT)) & SDIF_RST_N_CARD_RESET_MASK)
/*! @} */

/*! @name BMOD - Bus Mode register */
/*! @{ */

#define SDIF_BMOD_SWR_MASK                       (0x1U)
#define SDIF_BMOD_SWR_SHIFT                      (0U)
/*! SWR - Software Reset. */
#define SDIF_BMOD_SWR(x)                         (((uint32_t)(((uint32_t)(x)) << SDIF_BMOD_SWR_SHIFT)) & SDIF_BMOD_SWR_MASK)

#define SDIF_BMOD_FB_MASK                        (0x2U)
#define SDIF_BMOD_FB_SHIFT                       (1U)
/*! FB - Fixed Burst. */
#define SDIF_BMOD_FB(x)                          (((uint32_t)(((uint32_t)(x)) << SDIF_BMOD_FB_SHIFT)) & SDIF_BMOD_FB_MASK)

#define SDIF_BMOD_DSL_MASK                       (0x7CU)
#define SDIF_BMOD_DSL_SHIFT                      (2U)
/*! DSL - Descriptor Skip Length. */
#define SDIF_BMOD_DSL(x)                         (((uint32_t)(((uint32_t)(x)) << SDIF_BMOD_DSL_SHIFT)) & SDIF_BMOD_DSL_MASK)

#define SDIF_BMOD_DE_MASK                        (0x80U)
#define SDIF_BMOD_DE_SHIFT                       (7U)
/*! DE - SD/MMC DMA Enable. */
#define SDIF_BMOD_DE(x)                          (((uint32_t)(((uint32_t)(x)) << SDIF_BMOD_DE_SHIFT)) & SDIF_BMOD_DE_MASK)

#define SDIF_BMOD_PBL_MASK                       (0x700U)
#define SDIF_BMOD_PBL_SHIFT                      (8U)
/*! PBL - Programmable Burst Length. */
#define SDIF_BMOD_PBL(x)                         (((uint32_t)(((uint32_t)(x)) << SDIF_BMOD_PBL_SHIFT)) & SDIF_BMOD_PBL_MASK)
/*! @} */

/*! @name PLDMND - Poll Demand register */
/*! @{ */

#define SDIF_PLDMND_PD_MASK                      (0xFFFFFFFFU)
#define SDIF_PLDMND_PD_SHIFT                     (0U)
/*! PD - Poll Demand. */
#define SDIF_PLDMND_PD(x)                        (((uint32_t)(((uint32_t)(x)) << SDIF_PLDMND_PD_SHIFT)) & SDIF_PLDMND_PD_MASK)
/*! @} */

/*! @name DBADDR - Descriptor List Base Address register */
/*! @{ */

#define SDIF_DBADDR_SDL_MASK                     (0xFFFFFFFFU)
#define SDIF_DBADDR_SDL_SHIFT                    (0U)
/*! SDL - Start of Descriptor List. */
#define SDIF_DBADDR_SDL(x)                       (((uint32_t)(((uint32_t)(x)) << SDIF_DBADDR_SDL_SHIFT)) & SDIF_DBADDR_SDL_MASK)
/*! @} */

/*! @name IDSTS - Internal DMAC Status register */
/*! @{ */

#define SDIF_IDSTS_TI_MASK                       (0x1U)
#define SDIF_IDSTS_TI_SHIFT                      (0U)
/*! TI - Transmit Interrupt. */
#define SDIF_IDSTS_TI(x)                         (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_TI_SHIFT)) & SDIF_IDSTS_TI_MASK)

#define SDIF_IDSTS_RI_MASK                       (0x2U)
#define SDIF_IDSTS_RI_SHIFT                      (1U)
/*! RI - Receive Interrupt. */
#define SDIF_IDSTS_RI(x)                         (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_RI_SHIFT)) & SDIF_IDSTS_RI_MASK)

#define SDIF_IDSTS_FBE_MASK                      (0x4U)
#define SDIF_IDSTS_FBE_SHIFT                     (2U)
/*! FBE - Fatal Bus Error Interrupt. */
#define SDIF_IDSTS_FBE(x)                        (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_FBE_SHIFT)) & SDIF_IDSTS_FBE_MASK)

#define SDIF_IDSTS_DU_MASK                       (0x10U)
#define SDIF_IDSTS_DU_SHIFT                      (4U)
/*! DU - Descriptor Unavailable Interrupt. */
#define SDIF_IDSTS_DU(x)                         (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_DU_SHIFT)) & SDIF_IDSTS_DU_MASK)

#define SDIF_IDSTS_CES_MASK                      (0x20U)
#define SDIF_IDSTS_CES_SHIFT                     (5U)
/*! CES - Card Error Summary. */
#define SDIF_IDSTS_CES(x)                        (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_CES_SHIFT)) & SDIF_IDSTS_CES_MASK)

#define SDIF_IDSTS_NIS_MASK                      (0x100U)
#define SDIF_IDSTS_NIS_SHIFT                     (8U)
/*! NIS - Normal Interrupt Summary. */
#define SDIF_IDSTS_NIS(x)                        (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_NIS_SHIFT)) & SDIF_IDSTS_NIS_MASK)

#define SDIF_IDSTS_AIS_MASK                      (0x200U)
#define SDIF_IDSTS_AIS_SHIFT                     (9U)
/*! AIS - Abnormal Interrupt Summary. */
#define SDIF_IDSTS_AIS(x)                        (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_AIS_SHIFT)) & SDIF_IDSTS_AIS_MASK)

#define SDIF_IDSTS_EB_MASK                       (0x1C00U)
#define SDIF_IDSTS_EB_SHIFT                      (10U)
/*! EB - Error Bits. */
#define SDIF_IDSTS_EB(x)                         (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_EB_SHIFT)) & SDIF_IDSTS_EB_MASK)

#define SDIF_IDSTS_FSM_MASK                      (0x1E000U)
#define SDIF_IDSTS_FSM_SHIFT                     (13U)
/*! FSM - DMAC state machine present state. */
#define SDIF_IDSTS_FSM(x)                        (((uint32_t)(((uint32_t)(x)) << SDIF_IDSTS_FSM_SHIFT)) & SDIF_IDSTS_FSM_MASK)
/*! @} */

/*! @name IDINTEN - Internal DMAC Interrupt Enable register */
/*! @{ */

#define SDIF_IDINTEN_TI_MASK                     (0x1U)
#define SDIF_IDINTEN_TI_SHIFT                    (0U)
/*! TI - Transmit Interrupt Enable. */
#define SDIF_IDINTEN_TI(x)                       (((uint32_t)(((uint32_t)(x)) << SDIF_IDINTEN_TI_SHIFT)) & SDIF_IDINTEN_TI_MASK)

#define SDIF_IDINTEN_RI_MASK                     (0x2U)
#define SDIF_IDINTEN_RI_SHIFT                    (1U)
/*! RI - Receive Interrupt Enable. */
#define SDIF_IDINTEN_RI(x)                       (((uint32_t)(((uint32_t)(x)) << SDIF_IDINTEN_RI_SHIFT)) & SDIF_IDINTEN_RI_MASK)

#define SDIF_IDINTEN_FBE_MASK                    (0x4U)
#define SDIF_IDINTEN_FBE_SHIFT                   (2U)
/*! FBE - Fatal Bus Error Enable. */
#define SDIF_IDINTEN_FBE(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_IDINTEN_FBE_SHIFT)) & SDIF_IDINTEN_FBE_MASK)

#define SDIF_IDINTEN_DU_MASK                     (0x10U)
#define SDIF_IDINTEN_DU_SHIFT                    (4U)
/*! DU - Descriptor Unavailable Interrupt. */
#define SDIF_IDINTEN_DU(x)                       (((uint32_t)(((uint32_t)(x)) << SDIF_IDINTEN_DU_SHIFT)) & SDIF_IDINTEN_DU_MASK)

#define SDIF_IDINTEN_CES_MASK                    (0x20U)
#define SDIF_IDINTEN_CES_SHIFT                   (5U)
/*! CES - Card Error summary Interrupt Enable. */
#define SDIF_IDINTEN_CES(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_IDINTEN_CES_SHIFT)) & SDIF_IDINTEN_CES_MASK)

#define SDIF_IDINTEN_NIS_MASK                    (0x100U)
#define SDIF_IDINTEN_NIS_SHIFT                   (8U)
/*! NIS - Normal Interrupt Summary Enable. */
#define SDIF_IDINTEN_NIS(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_IDINTEN_NIS_SHIFT)) & SDIF_IDINTEN_NIS_MASK)

#define SDIF_IDINTEN_AIS_MASK                    (0x200U)
#define SDIF_IDINTEN_AIS_SHIFT                   (9U)
/*! AIS - Abnormal Interrupt Summary Enable. */
#define SDIF_IDINTEN_AIS(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_IDINTEN_AIS_SHIFT)) & SDIF_IDINTEN_AIS_MASK)
/*! @} */

/*! @name DSCADDR - Current Host Descriptor Address register */
/*! @{ */

#define SDIF_DSCADDR_HDA_MASK                    (0xFFFFFFFFU)
#define SDIF_DSCADDR_HDA_SHIFT                   (0U)
/*! HDA - Host Descriptor Address Pointer. */
#define SDIF_DSCADDR_HDA(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_DSCADDR_HDA_SHIFT)) & SDIF_DSCADDR_HDA_MASK)
/*! @} */

/*! @name BUFADDR - Current Buffer Descriptor Address register */
/*! @{ */

#define SDIF_BUFADDR_HBA_MASK                    (0xFFFFFFFFU)
#define SDIF_BUFADDR_HBA_SHIFT                   (0U)
/*! HBA - Host Buffer Address Pointer. */
#define SDIF_BUFADDR_HBA(x)                      (((uint32_t)(((uint32_t)(x)) << SDIF_BUFADDR_HBA_SHIFT)) & SDIF_BUFADDR_HBA_MASK)
/*! @} */

/*! @name CARDTHRCTL - Card Threshold Control */
/*! @{ */

#define SDIF_CARDTHRCTL_CARDRDTHREN_MASK         (0x1U)
#define SDIF_CARDTHRCTL_CARDRDTHREN_SHIFT        (0U)
/*! CARDRDTHREN - Card Read Threshold Enable. */
#define SDIF_CARDTHRCTL_CARDRDTHREN(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_CARDTHRCTL_CARDRDTHREN_SHIFT)) & SDIF_CARDTHRCTL_CARDRDTHREN_MASK)

#define SDIF_CARDTHRCTL_BSYCLRINTEN_MASK         (0x2U)
#define SDIF_CARDTHRCTL_BSYCLRINTEN_SHIFT        (1U)
/*! BSYCLRINTEN - Busy Clear Interrupt Enable. */
#define SDIF_CARDTHRCTL_BSYCLRINTEN(x)           (((uint32_t)(((uint32_t)(x)) << SDIF_CARDTHRCTL_BSYCLRINTEN_SHIFT)) & SDIF_CARDTHRCTL_BSYCLRINTEN_MASK)

#define SDIF_CARDTHRCTL_CARDTHRESHOLD_MASK       (0xFF0000U)
#define SDIF_CARDTHRCTL_CARDTHRESHOLD_SHIFT      (16U)
/*! CARDTHRESHOLD - Card Threshold size. */
#define SDIF_CARDTHRCTL_CARDTHRESHOLD(x)         (((uint32_t)(((uint32_t)(x)) << SDIF_CARDTHRCTL_CARDTHRESHOLD_SHIFT)) & SDIF_CARDTHRCTL_CARDTHRESHOLD_MASK)
/*! @} */

/*! @name BACKENDPWR - Power control */
/*! @{ */

#define SDIF_BACKENDPWR_BACKENDPWR_MASK          (0x1U)
#define SDIF_BACKENDPWR_BACKENDPWR_SHIFT         (0U)
/*! BACKENDPWR - Back-end Power control for card application. */
#define SDIF_BACKENDPWR_BACKENDPWR(x)            (((uint32_t)(((uint32_t)(x)) << SDIF_BACKENDPWR_BACKENDPWR_SHIFT)) & SDIF_BACKENDPWR_BACKENDPWR_MASK)
/*! @} */

/*! @name FIFO - SDIF FIFO */
/*! @{ */

#define SDIF_FIFO_DATA_MASK                      (0xFFFFFFFFU)
#define SDIF_FIFO_DATA_SHIFT                     (0U)
/*! DATA - SDIF FIFO. */
#define SDIF_FIFO_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << SDIF_FIFO_DATA_SHIFT)) & SDIF_FIFO_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SDIF_Register_Masks */


/*!
 * @}
 */ /* end of group SDIF_Peripheral_Access_Layer */


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


#endif  /* PERI_SDIF_H_ */

