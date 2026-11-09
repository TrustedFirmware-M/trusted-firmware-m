/*
** ###################################################################
**     Processors:          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ESPI
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
 * @file PERI_ESPI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ESPI
 *
 * CMSIS Peripheral Access Layer for ESPI
 */

#if !defined(PERI_ESPI_H_)
#define PERI_ESPI_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA577VAPR) || defined(CPU_MCXA577VLL) || defined(CPU_MCXA577VLQ) || defined(CPU_MCXA577VPN))
#include "MCXA577_COMMON.h"
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
   -- ESPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ESPI_Peripheral_Access_Layer ESPI Peripheral Access Layer
 * @{
 */

/** ESPI - Size of Registers Arrays */
#define ESPI_PORT_COUNT                           5u

/** ESPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCTRL;                             /**< Master Control, offset: 0x0 */
  __IO uint32_t MSTAT;                             /**< Master Status, offset: 0x4 */
  __IO uint32_t INTENSET;                          /**< Interrupt Enable Set, offset: 0x8 */
  __IO uint32_t INTENCLR;                          /**< Interrupt Clear, offset: 0xC */
  __IO uint32_t INTSTAT;                           /**< Masked Interrupt Status, offset: 0x10 */
  __IO uint32_t DMACTRL;                           /**< DMA Control, offset: 0x14 */
  __IO uint32_t RAMBASE;                           /**< RAM Base, offset: 0x18 */
  __IO uint32_t MAPBASE;                           /**< Mapped Base, offset: 0x1C */
  __IO uint32_t IRQPUSH;                           /**< IRQ Push, offset: 0x20 */
  __IO uint32_t WIREWO;                            /**< Virtual Wire MCU-to-host, offset: 0x24 */
  __I  uint32_t WIRERO;                            /**< Virtual Wire Host-to-MCU, offset: 0x28 */
       uint8_t RESERVED_0[4];
  __IO uint32_t P80STAT;                           /**< Port 80 Status, offset: 0x30 */
  __IO uint32_t STATADDR;                          /**< Status Block Address, offset: 0x34 */
       uint8_t RESERVED_1[8];
  __IO uint32_t ESPICAP;                           /**< eSPI Capabilities, offset: 0x40 */
  __I  uint32_t ESPICFG;                           /**< eSPI Configuration, offset: 0x44 */
  __IO uint32_t ESPIMISC;                          /**< eSPI Miscellaneous, offset: 0x48 */
       uint8_t RESERVED_2[4];
  __IO uint32_t RPMC_SUPPORT1;                     /**< RPMC Support 1, offset: 0x50 */
  __IO uint32_t RPMC_SUPPORT2;                     /**< RPMC Support 2, offset: 0x54 */
  __I  uint32_t WIREIN_GPIO;                       /**< WIREIN_GPIO, offset: 0x58 */
  __I  uint32_t WIREOUT_GPIO;                      /**< WIREOUT_GPIO, offset: 0x5C */
       uint8_t RESERVED_3[160];
  struct {                                         /* offset: 0x100, array step: 0x20 */
    __IO uint32_t CFG;                               /**< Port Configuration, array offset: 0x100, array step: 0x20 */
    __IO uint32_t STAT;                              /**< Port Status, array offset: 0x104, array step: 0x20 */
    __IO uint32_t IRULESTAT;                         /**< Set Interrupt Rules and User Status, array offset: 0x108, array step: 0x20 */
    union {                                          /* offset: 0x10C, array step: 0x20 */
      __IO uint32_t ADDR;                              /**< Port Address, array offset: 0x10C, array step: 0x20 */
      __IO uint32_t OMFLEN;                            /**< Port OOB, Mastering, and Flash Length, array offset: 0x10C, array step: 0x20 */
    };
    __I  uint32_t DATAIN;                            /**< Port Data Input, array offset: 0x110, array step: 0x20 */
    union {                                          /* offset: 0x114, array step: 0x20 */
      __IO uint32_t DATAOUT;                           /**< Port Data Out, array offset: 0x114, array step: 0x20 */
      __IO uint32_t RAMUSE;                            /**< Port RAM Use, array offset: 0x114, array step: 0x20 */
    };
         uint8_t RESERVED_0[8];
  } PORT[ESPI_PORT_COUNT];
} ESPI_Type;

/* ----------------------------------------------------------------------------
   -- ESPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ESPI_Register_Masks ESPI Register Masks
 * @{
 */

/*! @name MCTRL - Master Control */
/*! @{ */

#define ESPI_MCTRL_ENABLE_MASK                   (0x3U)
#define ESPI_MCTRL_ENABLE_SHIFT                  (0U)
/*! ENABLE - Enable
 *  0b00..Disabled. Block is not operational.
 *  0b01..eSPI (Enhanced Serial Peripheral Interface)
 *  0b10..LPC (Low Pin Count)
 *  0b11..Reserved
 */
#define ESPI_MCTRL_ENABLE(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_ENABLE_SHIFT)) & ESPI_MCTRL_ENABLE_MASK)

#define ESPI_MCTRL_RTC_INT_BMC_MASK              (0x4U)
#define ESPI_MCTRL_RTC_INT_BMC_SHIFT             (2U)
/*! RTC_INT_BMC - RTC-Integrated-BMC
 *  0b0..BMC does not support an integrated RTC.
 *  0b1..BMC supports an integrated RTC to which eSPI controller can forward RTC targeting IO cycles. (**ESPI slave regs: 0x8, bit 29**).
 */
#define ESPI_MCTRL_RTC_INT_BMC(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_RTC_INT_BMC_SHIFT)) & ESPI_MCTRL_RTC_INT_BMC_MASK)

#define ESPI_MCTRL_PENA_MASK                     (0x1F00U)
#define ESPI_MCTRL_PENA_SHIFT                    (8U)
/*! PENA - Port Enable */
#define ESPI_MCTRL_PENA(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_PENA_SHIFT)) & ESPI_MCTRL_PENA_MASK)

#define ESPI_MCTRL_P80ENA_MASK                   (0x10000U)
#define ESPI_MCTRL_P80ENA_SHIFT                  (16U)
/*! P80ENA - Port 80 Enable */
#define ESPI_MCTRL_P80ENA(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_P80ENA_SHIFT)) & ESPI_MCTRL_P80ENA_MASK)

#define ESPI_MCTRL_SBLKENA_MASK                  (0x20000U)
#define ESPI_MCTRL_SBLKENA_SHIFT                 (17U)
/*! SBLKENA - Status Block Enable */
#define ESPI_MCTRL_SBLKENA(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_SBLKENA_SHIFT)) & ESPI_MCTRL_SBLKENA_MASK)

#define ESPI_MCTRL_CLK_DIV_DISABLE_MASK          (0x40000U)
#define ESPI_MCTRL_CLK_DIV_DISABLE_SHIFT         (18U)
/*! CLK_DIV_DISABLE - Clock Division Disable
 *  0b0..Clock division is enabled.
 *  0b1..Clock division is disabled.
 */
#define ESPI_MCTRL_CLK_DIV_DISABLE(x)            (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_CLK_DIV_DISABLE_SHIFT)) & ESPI_MCTRL_CLK_DIV_DISABLE_MASK)

#define ESPI_MCTRL_EARLY_SAMPLE_MASK             (0x80000U)
#define ESPI_MCTRL_EARLY_SAMPLE_SHIFT            (19U)
/*! EARLY_SAMPLE - Early Sample */
#define ESPI_MCTRL_EARLY_SAMPLE(x)               (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_EARLY_SAMPLE_SHIFT)) & ESPI_MCTRL_EARLY_SAMPLE_MASK)
/*! @} */

/*! @name MSTAT - Master Status */
/*! @{ */

#define ESPI_MSTAT_PORTINT_MASK                  (0x1FU)
#define ESPI_MSTAT_PORTINT_SHIFT                 (0U)
/*! PORTINT - Port Interrupt */
#define ESPI_MSTAT_PORTINT(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_PORTINT_SHIFT)) & ESPI_MSTAT_PORTINT_MASK)

#define ESPI_MSTAT_P80INT_MASK                   (0x100U)
#define ESPI_MSTAT_P80INT_SHIFT                  (8U)
/*! P80INT - Port80 Interrupt Request */
#define ESPI_MSTAT_P80INT(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_P80INT_SHIFT)) & ESPI_MSTAT_P80INT_MASK)

#define ESPI_MSTAT_BUSRST_MASK                   (0x200U)
#define ESPI_MSTAT_BUSRST_SHIFT                  (9U)
/*! BUSRST - Bus Reset
 *  0b0..Reserved
 *  0b1..The bit entered or exited reset. Sticky, must clear.
 */
#define ESPI_MSTAT_BUSRST(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_BUSRST_SHIFT)) & ESPI_MSTAT_BUSRST_MASK)

#define ESPI_MSTAT_IRQUPD_MASK                   (0x400U)
#define ESPI_MSTAT_IRQUPD_SHIFT                  (10U)
/*! IRQUPD - Interrupt Request Update Completion
 *  0b0..Reserved
 *  0b1..The bus had an IRQ update completion (for eSPI, IRQPush done; for LPC, SERIRQ done). Sticky, must clear.
 */
#define ESPI_MSTAT_IRQUPD(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_IRQUPD_SHIFT)) & ESPI_MSTAT_IRQUPD_MASK)

#define ESPI_MSTAT_WIRECHG_MASK                  (0x800U)
#define ESPI_MSTAT_WIRECHG_SHIFT                 (11U)
/*! WIRECHG - Wire Change
 *  0b0..Reserved
 *  0b1..For eSPI, one or more input VWires have changed since last cleared for eSPI. For LPC, SERIRQ started. Sticky, write to clear.
 */
#define ESPI_MSTAT_WIRECHG(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_WIRECHG_SHIFT)) & ESPI_MSTAT_WIRECHG_MASK)

#define ESPI_MSTAT_HSTALL_MASK                   (0x1000U)
#define ESPI_MSTAT_HSTALL_SHIFT                  (12U)
/*! HSTALL - Host Stall
 *  0b0..Reserved
 *  0b1..Host is stalled on a read from or write to a port that has the STALLRD or STALLWR bit set in the PnCFG
 *       register. The application must write 1 to this bit to clear and release the host. The stall should not
 *       allowed to persist.
 */
#define ESPI_MSTAT_HSTALL(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_HSTALL_SHIFT)) & ESPI_MSTAT_HSTALL_MASK)

#define ESPI_MSTAT_CRCERR_MASK                   (0x2000U)
#define ESPI_MSTAT_CRCERR_SHIFT                  (13U)
/*! CRCERR - Cyclic Redundancy Check (CRC) Error
 *  0b0..Reserved
 *  0b1..CRC from the master did not match the computed CRC. The state of the app may be in error (due to bad data). Write 1 to clear.
 */
#define ESPI_MSTAT_CRCERR(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_CRCERR_SHIFT)) & ESPI_MSTAT_CRCERR_MASK)

#define ESPI_MSTAT_GPIO_MASK                     (0x4000U)
#define ESPI_MSTAT_GPIO_SHIFT                    (14U)
/*! GPIO - General Purpose Input/Output (GPIO)
 *  0b0..Reserved
 *  0b1..ESPIMISC[GPIO] has had an input change. Only detected if INTENSET has configured this bit to interrupt. Write 1 to clear.
 */
#define ESPI_MSTAT_GPIO(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_GPIO_SHIFT)) & ESPI_MSTAT_GPIO_MASK)

#define ESPI_MSTAT_BUSY_MASK                     (0x10000U)
#define ESPI_MSTAT_BUSY_SHIFT                    (16U)
/*! BUSY - Bus Busy
 *  0b0..Idle
 *  0b1..Busy
 */
#define ESPI_MSTAT_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_BUSY_SHIFT)) & ESPI_MSTAT_BUSY_MASK)

#define ESPI_MSTAT_INRST_MASK                    (0x20000U)
#define ESPI_MSTAT_INRST_SHIFT                   (17U)
/*! INRST - Bus Reset
 *  0b0..Bus not in reset
 *  0b1..Bus is in reset
 */
#define ESPI_MSTAT_INRST(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_INRST_SHIFT)) & ESPI_MSTAT_INRST_MASK)

#define ESPI_MSTAT_COMPPEND_MASK                 (0x40000U)
#define ESPI_MSTAT_COMPPEND_SHIFT                (18U)
/*! COMPPEND - Completion Pending
 *  0b0..No completions pending
 *  0b1..Completions are pending for eSPI. Indicates quiet mode for LPC
 */
#define ESPI_MSTAT_COMPPEND(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_COMPPEND_SHIFT)) & ESPI_MSTAT_COMPPEND_MASK)

#define ESPI_MSTAT_MASTPEND_MASK                 (0x80000U)
#define ESPI_MSTAT_MASTPEND_SHIFT                (19U)
/*! MASTPEND - Master Pending
 *  0b0..No mastering pending
 *  0b1..Mastering is pending (flash or memory)
 */
#define ESPI_MSTAT_MASTPEND(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_MASTPEND_SHIFT)) & ESPI_MSTAT_MASTPEND_MASK)

#define ESPI_MSTAT_ALERTPEND_MASK                (0x100000U)
#define ESPI_MSTAT_ALERTPEND_SHIFT               (20U)
/*! ALERTPEND - Alert Pending
 *  0b0..No alert request pending
 *  0b1..Alert request pin is pending, whether a separate pin or master-in slave-out (MISO). For LPC, indicates that SERIRQ is in process.
 */
#define ESPI_MSTAT_ALERTPEND(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_ALERTPEND_SHIFT)) & ESPI_MSTAT_ALERTPEND_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Enable Set */
/*! @{ */

#define ESPI_INTENSET_PORTINT_MASK               (0x1FU)
#define ESPI_INTENSET_PORTINT_SHIFT              (0U)
/*! PORTINT - Port interrupt
 *  0b00000..Reserved
 *  0b00001..Corresponding port interrupts main processor, if it matches IRule
 */
#define ESPI_INTENSET_PORTINT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_PORTINT_SHIFT)) & ESPI_INTENSET_PORTINT_MASK)

#define ESPI_INTENSET_P80INT_MASK                (0x100U)
#define ESPI_INTENSET_P80INT_SHIFT               (8U)
/*! P80INT - Port80 Interrupt
 *  0b0..Disabled
 *  0b1..Port80 interrupts main processor on update from host
 */
#define ESPI_INTENSET_P80INT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_P80INT_SHIFT)) & ESPI_INTENSET_P80INT_MASK)

#define ESPI_INTENSET_BUSRST_MASK                (0x200U)
#define ESPI_INTENSET_BUSRST_SHIFT               (9U)
/*! BUSRST - Bus Reset
 *  0b0..Disabled
 *  0b1..A change in bus reset status interrupts CPU
 */
#define ESPI_INTENSET_BUSRST(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_BUSRST_SHIFT)) & ESPI_INTENSET_BUSRST_MASK)

#define ESPI_INTENSET_IRQUPD_MASK                (0x400U)
#define ESPI_INTENSET_IRQUPD_SHIFT               (10U)
/*! IRQUPD - IRQ Update
 *  0b0..Disabled
 *  0b1..Completion of an IRQ update interrupts CPU
 */
#define ESPI_INTENSET_IRQUPD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_IRQUPD_SHIFT)) & ESPI_INTENSET_IRQUPD_MASK)

#define ESPI_INTENSET_WIRECHG_MASK               (0x800U)
#define ESPI_INTENSET_WIRECHG_SHIFT              (11U)
/*! WIRECHG - Wire Change
 *  0b0..Disabled
 *  0b1..When one or more VWire inputs have changed, interrupts CPU
 */
#define ESPI_INTENSET_WIRECHG(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_WIRECHG_SHIFT)) & ESPI_INTENSET_WIRECHG_MASK)

#define ESPI_INTENSET_HSTALL_MASK                (0x1000U)
#define ESPI_INTENSET_HSTALL_SHIFT               (12U)
/*! HSTALL - Host Stall
 *  0b0..Disabled
 *  0b1..When the MSTAT[HSTALL] is 1, interrupt main processor
 */
#define ESPI_INTENSET_HSTALL(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_HSTALL_SHIFT)) & ESPI_INTENSET_HSTALL_MASK)

#define ESPI_INTENSET_CRCERR_MASK                (0x2000U)
#define ESPI_INTENSET_CRCERR_SHIFT               (13U)
/*! CRCERR - CRC Error
 *  0b0..Disabled
 *  0b1..When CRC error detected, interrupts CPU
 */
#define ESPI_INTENSET_CRCERR(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CRCERR_SHIFT)) & ESPI_INTENSET_CRCERR_MASK)

#define ESPI_INTENSET_GPIO_MASK                  (0x4000U)
#define ESPI_INTENSET_GPIO_SHIFT                 (14U)
/*! GPIO - GPIO
 *  0b0..Disabled
 *  0b1..When ESPICFG GPIO changes input value, interrupts CPU
 */
#define ESPI_INTENSET_GPIO(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_GPIO_SHIFT)) & ESPI_INTENSET_GPIO_MASK)

#define ESPI_INTENSET_CS_INT_MASK                (0x8000U)
#define ESPI_INTENSET_CS_INT_SHIFT               (15U)
/*! CS_INT - CS_INT
 *  0b0..Disabled
 *  0b1..When CS falls, interrupts the main processor (wake_async is asserted)
 */
#define ESPI_INTENSET_CS_INT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CS_INT_SHIFT)) & ESPI_INTENSET_CS_INT_MASK)

#define ESPI_INTENSET_CPORTINT_MASK              (0x1F0000U)
#define ESPI_INTENSET_CPORTINT_SHIFT             (16U)
/*! CPORTINT - Coprocessor Interrupt
 *  0b00000..Disabled
 *  0b00001..
 */
#define ESPI_INTENSET_CPORTINT(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CPORTINT_SHIFT)) & ESPI_INTENSET_CPORTINT_MASK)

#define ESPI_INTENSET_CP80INT_MASK               (0x1000000U)
#define ESPI_INTENSET_CP80INT_SHIFT              (24U)
/*! CP80INT - Coprocessor Port80 Interrupt
 *  0b0..Disabled
 *  0b1..Port80 interrupts coprocessor on update from host
 */
#define ESPI_INTENSET_CP80INT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CP80INT_SHIFT)) & ESPI_INTENSET_CP80INT_MASK)

#define ESPI_INTENSET_CBUSRST_MASK               (0x2000000U)
#define ESPI_INTENSET_CBUSRST_SHIFT              (25U)
/*! CBUSRST - Coprocessor Burst
 *  0b0..Disabled
 *  0b1..Change in bus reset status interrupts coprocessor
 */
#define ESPI_INTENSET_CBUSRST(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CBUSRST_SHIFT)) & ESPI_INTENSET_CBUSRST_MASK)

#define ESPI_INTENSET_CIRQUPD_MASK               (0x4000000U)
#define ESPI_INTENSET_CIRQUPD_SHIFT              (26U)
/*! CIRQUPD - Coprocessor Interrupt Update
 *  0b0..Disabled
 *  0b1..Completion of an IRQ update interrupts coprocessor
 */
#define ESPI_INTENSET_CIRQUPD(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CIRQUPD_SHIFT)) & ESPI_INTENSET_CIRQUPD_MASK)

#define ESPI_INTENSET_CWIRECHG_MASK              (0x8000000U)
#define ESPI_INTENSET_CWIRECHG_SHIFT             (27U)
/*! CWIRECHG - Coprocessor Wire Change
 *  0b0..Disabled
 *  0b1..When one one or more Vwire inputs have changed, interrupts coprocessor
 */
#define ESPI_INTENSET_CWIRECHG(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CWIRECHG_SHIFT)) & ESPI_INTENSET_CWIRECHG_MASK)

#define ESPI_INTENSET_CHSTALL_MASK               (0x10000000U)
#define ESPI_INTENSET_CHSTALL_SHIFT              (28U)
/*! CHSTALL - Coprocessor Host Stall
 *  0b0..Disabled
 *  0b1..When MSTAT[HSTALL] is 1, interrupts coprocessor
 */
#define ESPI_INTENSET_CHSTALL(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CHSTALL_SHIFT)) & ESPI_INTENSET_CHSTALL_MASK)

#define ESPI_INTENSET_CCRCERR_MASK               (0x20000000U)
#define ESPI_INTENSET_CCRCERR_SHIFT              (29U)
/*! CCRCERR - Coprocessor Error
 *  0b0..Disabled
 *  0b1..When CRC error detected, interrupts coprocessor
 */
#define ESPI_INTENSET_CCRCERR(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CCRCERR_SHIFT)) & ESPI_INTENSET_CCRCERR_MASK)

#define ESPI_INTENSET_CGPIO_MASK                 (0x40000000U)
#define ESPI_INTENSET_CGPIO_SHIFT                (30U)
/*! CGPIO - Coprocessor GPIO
 *  0b0..Disabled
 *  0b1..When ESPICFG GPIO changes input value, interrupts coprocessor
 */
#define ESPI_INTENSET_CGPIO(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CGPIO_SHIFT)) & ESPI_INTENSET_CGPIO_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Clear */
/*! @{ */

#define ESPI_INTENCLR_PORTINT_MASK               (0x1FU)
#define ESPI_INTENCLR_PORTINT_SHIFT              (0U)
/*! PORTINT - Port Interrupt
 *  0b00000..Reserved
 *  0b00001..Writes 0 to corresponding port interrupt enable
 */
#define ESPI_INTENCLR_PORTINT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_PORTINT_SHIFT)) & ESPI_INTENCLR_PORTINT_MASK)

#define ESPI_INTENCLR_P80INT_MASK                (0x100U)
#define ESPI_INTENCLR_P80INT_SHIFT               (8U)
/*! P80INT - Port80 Interrupt
 *  0b0..Reserved
 *  0b1..Writes 0 to Port80 interrupt enable
 */
#define ESPI_INTENCLR_P80INT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_P80INT_SHIFT)) & ESPI_INTENCLR_P80INT_MASK)

#define ESPI_INTENCLR_BUSRST_MASK                (0x200U)
#define ESPI_INTENCLR_BUSRST_SHIFT               (9U)
/*! BUSRST - Bus Reset
 *  0b0..Reserved
 *  0b1..Writes 0 to reset change interrupt enable
 */
#define ESPI_INTENCLR_BUSRST(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_BUSRST_SHIFT)) & ESPI_INTENCLR_BUSRST_MASK)

#define ESPI_INTENCLR_IRQUPD_MASK                (0x400U)
#define ESPI_INTENCLR_IRQUPD_SHIFT               (10U)
/*! IRQUPD - IRQ Update
 *  0b0..Reserved
 *  0b1..Writes 0 to IRQ completion interrupt enable
 */
#define ESPI_INTENCLR_IRQUPD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_IRQUPD_SHIFT)) & ESPI_INTENCLR_IRQUPD_MASK)

#define ESPI_INTENCLR_WIRECHG_MASK               (0x800U)
#define ESPI_INTENCLR_WIRECHG_SHIFT              (11U)
/*! WIRECHG - Wire Change
 *  0b0..Reserved
 *  0b1..Writes 0 to Wire Change interrupt enable
 */
#define ESPI_INTENCLR_WIRECHG(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_WIRECHG_SHIFT)) & ESPI_INTENCLR_WIRECHG_MASK)

#define ESPI_INTENCLR_HSTALL_MASK                (0x1000U)
#define ESPI_INTENCLR_HSTALL_SHIFT               (12U)
/*! HSTALL - Host Stall
 *  0b0..Reserved
 *  0b1..Writes 0 to HSTALL interrupt enable
 */
#define ESPI_INTENCLR_HSTALL(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_HSTALL_SHIFT)) & ESPI_INTENCLR_HSTALL_MASK)

#define ESPI_INTENCLR_CRCERR_MASK                (0x2000U)
#define ESPI_INTENCLR_CRCERR_SHIFT               (13U)
/*! CRCERR - CRC Error
 *  0b0..Reserved
 *  0b1..Writes 0 to CRCERR interrupt enable
 */
#define ESPI_INTENCLR_CRCERR(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CRCERR_SHIFT)) & ESPI_INTENCLR_CRCERR_MASK)

#define ESPI_INTENCLR_GPIO_MASK                  (0x4000U)
#define ESPI_INTENCLR_GPIO_SHIFT                 (14U)
/*! GPIO - GPIO
 *  0b0..Reserved
 *  0b1..Writes 0 to GPIO interrupt enable
 */
#define ESPI_INTENCLR_GPIO(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_GPIO_SHIFT)) & ESPI_INTENCLR_GPIO_MASK)

#define ESPI_INTENCLR_CS_INT_MASK                (0x8000U)
#define ESPI_INTENCLR_CS_INT_SHIFT               (15U)
/*! CS_INT - CS_INT
 *  0b0..Disabled
 *  0b1..Clear CS falls enable
 */
#define ESPI_INTENCLR_CS_INT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CS_INT_SHIFT)) & ESPI_INTENCLR_CS_INT_MASK)

#define ESPI_INTENCLR_CPORTINT_MASK              (0x1F0000U)
#define ESPI_INTENCLR_CPORTINT_SHIFT             (16U)
/*! CPORTINT - Coprocessor Interrupt
 *  0b00000..Reserved
 *  0b00001..Writes 0 to corresponding coprocessor port interrupt enable
 */
#define ESPI_INTENCLR_CPORTINT(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CPORTINT_SHIFT)) & ESPI_INTENCLR_CPORTINT_MASK)

#define ESPI_INTENCLR_CP80INT_MASK               (0x1000000U)
#define ESPI_INTENCLR_CP80INT_SHIFT              (24U)
/*! CP80INT - Coprocesssor Port80 Interrupt
 *  0b0..Reserved
 *  0b1..Writes 0 to coprocessor Port80 interrupt enable.
 */
#define ESPI_INTENCLR_CP80INT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CP80INT_SHIFT)) & ESPI_INTENCLR_CP80INT_MASK)

#define ESPI_INTENCLR_CBUSRST_MASK               (0x2000000U)
#define ESPI_INTENCLR_CBUSRST_SHIFT              (25U)
/*! CBUSRST - Coprocessor Burst
 *  0b0..Reserved
 *  0b1..Writes 0 to coprocessor Reset change interrupt enable
 */
#define ESPI_INTENCLR_CBUSRST(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CBUSRST_SHIFT)) & ESPI_INTENCLR_CBUSRST_MASK)

#define ESPI_INTENCLR_CIRQUPD_MASK               (0x4000000U)
#define ESPI_INTENCLR_CIRQUPD_SHIFT              (26U)
/*! CIRQUPD - Coprocessor IRQ Update
 *  0b0..Reserved
 *  0b1..Writes 0 to coprocessor IRQ completion interrupt enable
 */
#define ESPI_INTENCLR_CIRQUPD(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CIRQUPD_SHIFT)) & ESPI_INTENCLR_CIRQUPD_MASK)

#define ESPI_INTENCLR_CWIRECHG_MASK              (0x8000000U)
#define ESPI_INTENCLR_CWIRECHG_SHIFT             (27U)
/*! CWIRECHG - Coprocessor Wire Change
 *  0b0..Reserved
 *  0b1..Writes 0 to coprocessor Wire Change interrupt enable
 */
#define ESPI_INTENCLR_CWIRECHG(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CWIRECHG_SHIFT)) & ESPI_INTENCLR_CWIRECHG_MASK)

#define ESPI_INTENCLR_CHSTALL_MASK               (0x10000000U)
#define ESPI_INTENCLR_CHSTALL_SHIFT              (28U)
/*! CHSTALL - Coprocessor Host Stall
 *  0b0..Reserved
 *  0b1..Writes 0 to coprocessor HSTALL interrupt enable
 */
#define ESPI_INTENCLR_CHSTALL(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CHSTALL_SHIFT)) & ESPI_INTENCLR_CHSTALL_MASK)

#define ESPI_INTENCLR_CCRCERR_MASK               (0x20000000U)
#define ESPI_INTENCLR_CCRCERR_SHIFT              (29U)
/*! CCRCERR - Coprocessor CRC Error
 *  0b0..Reserved
 *  0b1..Writes 0 to coprocessor CRCERR interrupt enable
 */
#define ESPI_INTENCLR_CCRCERR(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CCRCERR_SHIFT)) & ESPI_INTENCLR_CCRCERR_MASK)

#define ESPI_INTENCLR_CGPIO_MASK                 (0x40000000U)
#define ESPI_INTENCLR_CGPIO_SHIFT                (30U)
/*! CGPIO - Coprocessor GPIO
 *  0b0..Reserved
 *  0b1..Writes 0 to coprocessor GPIO interrupt enable
 */
#define ESPI_INTENCLR_CGPIO(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CGPIO_SHIFT)) & ESPI_INTENCLR_CGPIO_MASK)
/*! @} */

/*! @name INTSTAT - Masked Interrupt Status */
/*! @{ */

#define ESPI_INTSTAT_PORTINT_MASK                (0x1FU)
#define ESPI_INTSTAT_PORTINT_SHIFT               (0U)
/*! PORTINT - Port Interrupt
 *  0b00000..Disabled
 *  0b00001..Corresponding port interrupts main processor if it matches IRule
 */
#define ESPI_INTSTAT_PORTINT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_PORTINT_SHIFT)) & ESPI_INTSTAT_PORTINT_MASK)

#define ESPI_INTSTAT_P80INT_MASK                 (0x100U)
#define ESPI_INTSTAT_P80INT_SHIFT                (8U)
/*! P80INT - Port80 Interrupt
 *  0b0..Disabled
 *  0b1..Port80 interrupts main processor on update from host
 */
#define ESPI_INTSTAT_P80INT(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_P80INT_SHIFT)) & ESPI_INTSTAT_P80INT_MASK)

#define ESPI_INTSTAT_BUSRST_MASK                 (0x200U)
#define ESPI_INTSTAT_BUSRST_SHIFT                (9U)
/*! BUSRST - Bus Reset
 *  0b0..Disabled
 *  0b1..A change in Bus Reset status interrupts CPU
 */
#define ESPI_INTSTAT_BUSRST(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_BUSRST_SHIFT)) & ESPI_INTSTAT_BUSRST_MASK)

#define ESPI_INTSTAT_IRQUPD_MASK                 (0x400U)
#define ESPI_INTSTAT_IRQUPD_SHIFT                (10U)
/*! IRQUPD - IRQ Update
 *  0b0..Disabled
 *  0b1..Completion of an IRQ update interrupts CPU
 */
#define ESPI_INTSTAT_IRQUPD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_IRQUPD_SHIFT)) & ESPI_INTSTAT_IRQUPD_MASK)

#define ESPI_INTSTAT_WIRECHG_MASK                (0x800U)
#define ESPI_INTSTAT_WIRECHG_SHIFT               (11U)
/*! WIRECHG - Wire Change
 *  0b0..Disabled
 *  0b1..The VWire input change interrupt is enabled and pending for the CPU
 */
#define ESPI_INTSTAT_WIRECHG(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_WIRECHG_SHIFT)) & ESPI_INTSTAT_WIRECHG_MASK)

#define ESPI_INTSTAT_HSTALL_MASK                 (0x1000U)
#define ESPI_INTSTAT_HSTALL_SHIFT                (12U)
/*! HSTALL - Host Stall
 *  0b0..Disabled
 *  0b1..The HSTALL interrupt is enabled and pending for the CPU
 */
#define ESPI_INTSTAT_HSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_HSTALL_SHIFT)) & ESPI_INTSTAT_HSTALL_MASK)

#define ESPI_INTSTAT_CRCERR_MASK                 (0x2000U)
#define ESPI_INTSTAT_CRCERR_SHIFT                (13U)
/*! CRCERR - CRC Error
 *  0b0..Disabled
 *  0b1..The CRC error interrupt is enabled and pending for the CPU
 */
#define ESPI_INTSTAT_CRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CRCERR_SHIFT)) & ESPI_INTSTAT_CRCERR_MASK)

#define ESPI_INTSTAT_GPIO_MASK                   (0x4000U)
#define ESPI_INTSTAT_GPIO_SHIFT                  (14U)
/*! GPIO - GPIO
 *  0b0..Disabled
 *  0b1..The GPIO input change interrupt is enabled and pending for the CPU
 */
#define ESPI_INTSTAT_GPIO(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_GPIO_SHIFT)) & ESPI_INTSTAT_GPIO_MASK)

#define ESPI_INTSTAT_CPORTINT_MASK               (0x1F0000U)
#define ESPI_INTSTAT_CPORTINT_SHIFT              (16U)
/*! CPORTINT - Coprocessor Interrupt
 *  0b00000..Disabled
 *  0b00001..Interrupt is enabled and pending for the coprocessor
 */
#define ESPI_INTSTAT_CPORTINT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CPORTINT_SHIFT)) & ESPI_INTSTAT_CPORTINT_MASK)

#define ESPI_INTSTAT_CP80INT_MASK                (0x1000000U)
#define ESPI_INTSTAT_CP80INT_SHIFT               (24U)
/*! CP80INT - Coprocessor Port80 Interrupt
 *  0b0..Disabled
 *  0b1..Port80 interrupt is enabled and pending for the CPU. Port80 interrupts coprocessor on update from host.
 */
#define ESPI_INTSTAT_CP80INT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CP80INT_SHIFT)) & ESPI_INTSTAT_CP80INT_MASK)

#define ESPI_INTSTAT_CBUSRST_MASK                (0x2000000U)
#define ESPI_INTSTAT_CBUSRST_SHIFT               (25U)
/*! CBUSRST - Coprocessor Burst
 *  0b0..Disabled
 *  0b1..Bus reset status change interrupt is enabled and pending for the CPU. A change in bus reset status interrupts coprocessor.
 */
#define ESPI_INTSTAT_CBUSRST(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CBUSRST_SHIFT)) & ESPI_INTSTAT_CBUSRST_MASK)

#define ESPI_INTSTAT_CIRQUPD_MASK                (0x4000000U)
#define ESPI_INTSTAT_CIRQUPD_SHIFT               (26U)
/*! CIRQUPD - Coprocessor IRQ Update
 *  0b0..Disabled
 *  0b1..IRQ update interrupt is enabled and pending for the CPU.
 */
#define ESPI_INTSTAT_CIRQUPD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CIRQUPD_SHIFT)) & ESPI_INTSTAT_CIRQUPD_MASK)

#define ESPI_INTSTAT_CWIRECHG_MASK               (0x8000000U)
#define ESPI_INTSTAT_CWIRECHG_SHIFT              (27U)
/*! CWIRECHG - Coprocessor Wire Change
 *  0b0..Disabled
 *  0b1..When one one or more Vwire input has changed, interrupts coprocessor.
 */
#define ESPI_INTSTAT_CWIRECHG(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CWIRECHG_SHIFT)) & ESPI_INTSTAT_CWIRECHG_MASK)

#define ESPI_INTSTAT_CHSTALL_MASK                (0x10000000U)
#define ESPI_INTSTAT_CHSTALL_SHIFT               (28U)
/*! CHSTALL - Coprocessor Host Stall
 *  0b0..Disabled
 *  0b1..When MSTAT[HSTALL] is 1, interrupts coprocessor.
 */
#define ESPI_INTSTAT_CHSTALL(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CHSTALL_SHIFT)) & ESPI_INTSTAT_CHSTALL_MASK)

#define ESPI_INTSTAT_CCRCERR_MASK                (0x20000000U)
#define ESPI_INTSTAT_CCRCERR_SHIFT               (29U)
/*! CCRCERR - Coprocessor CRC Error
 *  0b0..Disabled
 *  0b1..When a CRC error detected, interrupts coprocessor.
 */
#define ESPI_INTSTAT_CCRCERR(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CCRCERR_SHIFT)) & ESPI_INTSTAT_CCRCERR_MASK)

#define ESPI_INTSTAT_CGPIO_MASK                  (0x40000000U)
#define ESPI_INTSTAT_CGPIO_SHIFT                 (30U)
/*! CGPIO - Coprocessor GPIO
 *  0b0..Disabled
 *  0b1..When ESPICFG GPIO changes input value, interrupts coprocessor.
 */
#define ESPI_INTSTAT_CGPIO(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CGPIO_SHIFT)) & ESPI_INTSTAT_CGPIO_MASK)
/*! @} */

/*! @name DMACTRL - DMA Control */
/*! @{ */

#define ESPI_DMACTRL_DMA0EN_MASK                 (0x3U)
#define ESPI_DMACTRL_DMA0EN_SHIFT                (0U)
/*! DMA0EN - DMA 0 Enable
 *  0b00..Disabled. The DMA channel is not used.
 *  0b01..Triggers on Host Read empty (whether endpoint and a byte or mailbox and many bytes). Allows reload of memory.
 *  0b10..Triggers on Host Write complete/ready (whether endpoint and a byte, or mailbox and many bytes).
 *  0b11..Reserved
 */
#define ESPI_DMACTRL_DMA0EN(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA0EN_SHIFT)) & ESPI_DMACTRL_DMA0EN_MASK)

#define ESPI_DMACTRL_DMA1EN_MASK                 (0xCU)
#define ESPI_DMACTRL_DMA1EN_SHIFT                (2U)
/*! DMA1EN - DMA 1 Enable
 *  0b00..Disabled. The DMA channel is not used.
 *  0b01..Triggers on Host Read empty (whether endpoint and a byte or mailbox and many bytes). Allows reload of memory.
 *  0b10..Triggers on Host Write complete/ready (whether endpoint and a byte or mailbox and many bytes).
 *  0b11..Reserved
 */
#define ESPI_DMACTRL_DMA1EN(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA1EN_SHIFT)) & ESPI_DMACTRL_DMA1EN_MASK)

#define ESPI_DMACTRL_DMA0PORT_MASK               (0xF00U)
#define ESPI_DMACTRL_DMA0PORT_SHIFT              (8U)
/*! DMA0PORT - DMA 0 Port */
#define ESPI_DMACTRL_DMA0PORT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA0PORT_SHIFT)) & ESPI_DMACTRL_DMA0PORT_MASK)

#define ESPI_DMACTRL_DMA1PORT_MASK               (0xF000U)
#define ESPI_DMACTRL_DMA1PORT_SHIFT              (12U)
/*! DMA1PORT - Selects port operating DMA
 *  0b0000..Port 0
 *  0b0001..Port 1
 *  0b0010..Port 2
 *  0b0011..Port 3
 *  0b0100..Port 4
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Port80. Used to offload the Port80 bytes (only host writes apply to Port80).
 *  0b1001-0b1111..Reserved
 */
#define ESPI_DMACTRL_DMA1PORT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA1PORT_SHIFT)) & ESPI_DMACTRL_DMA1PORT_MASK)

#define ESPI_DMACTRL_CNT0_MASK                   (0x7F0000U)
#define ESPI_DMACTRL_CNT0_SHIFT                  (16U)
/*! CNT0 - Reload Count 0 */
#define ESPI_DMACTRL_CNT0(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_CNT0_SHIFT)) & ESPI_DMACTRL_CNT0_MASK)

#define ESPI_DMACTRL_CNT1_MASK                   (0x7F000000U)
#define ESPI_DMACTRL_CNT1_SHIFT                  (24U)
/*! CNT1 - Reload Count 1 */
#define ESPI_DMACTRL_CNT1(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_CNT1_SHIFT)) & ESPI_DMACTRL_CNT1_MASK)
/*! @} */

/*! @name RAMBASE - RAM Base */
/*! @{ */

#define ESPI_RAMBASE_ZERO_MASK                   (0xFFFU)
#define ESPI_RAMBASE_ZERO_SHIFT                  (0U)
/*! ZERO - Always 0 */
#define ESPI_RAMBASE_ZERO(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_RAMBASE_ZERO_SHIFT)) & ESPI_RAMBASE_ZERO_MASK)

#define ESPI_RAMBASE_RAM_MASK                    (0xFFFFF000U)
#define ESPI_RAMBASE_RAM_SHIFT                   (12U)
/*! RAM - RAM Location */
#define ESPI_RAMBASE_RAM(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_RAMBASE_RAM_SHIFT)) & ESPI_RAMBASE_RAM_MASK)
/*! @} */

/*! @name MAPBASE - Mapped Base */
/*! @{ */

#define ESPI_MAPBASE_BASE0_MASK                  (0xFFFFU)
#define ESPI_MAPBASE_BASE0_SHIFT                 (0U)
/*! BASE0 - Base 0 */
#define ESPI_MAPBASE_BASE0(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MAPBASE_BASE0_SHIFT)) & ESPI_MAPBASE_BASE0_MASK)

#define ESPI_MAPBASE_BASE1_MASK                  (0xFFFF0000U)
#define ESPI_MAPBASE_BASE1_SHIFT                 (16U)
/*! BASE1 - Base 1 */
#define ESPI_MAPBASE_BASE1(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MAPBASE_BASE1_SHIFT)) & ESPI_MAPBASE_BASE1_MASK)
/*! @} */

/*! @name IRQPUSH - IRQ Push */
/*! @{ */

#define ESPI_IRQPUSH_IRQ_MASK                    (0xFFU)
#define ESPI_IRQPUSH_IRQ_SHIFT                   (0U)
/*! IRQ - Interrupt Request Queue */
#define ESPI_IRQPUSH_IRQ(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_IRQPUSH_IRQ_SHIFT)) & ESPI_IRQPUSH_IRQ_MASK)

#define ESPI_IRQPUSH_DONE_MASK                   (0x100U)
#define ESPI_IRQPUSH_DONE_SHIFT                  (8U)
/*! DONE - IRQ Update Done */
#define ESPI_IRQPUSH_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_IRQPUSH_DONE_SHIFT)) & ESPI_IRQPUSH_DONE_MASK)
/*! @} */

/*! @name WIREWO - Virtual Wire MCU-to-host */
/*! @{ */

#define ESPI_WIREWO_OOB_RST_ACK_MASK             (0x1U)
#define ESPI_WIREWO_OOB_RST_ACK_SHIFT            (0U)
/*! OOB_RST_ACK - Out-Of-Band Reset Acknowledge */
#define ESPI_WIREWO_OOB_RST_ACK(x)               (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_OOB_RST_ACK_SHIFT)) & ESPI_WIREWO_OOB_RST_ACK_MASK)

#define ESPI_WIREWO_WAKEN_SCIN_MASK              (0x2U)
#define ESPI_WIREWO_WAKEN_SCIN_SHIFT             (1U)
/*! WAKEN_SCIN - IRQ1 */
#define ESPI_WIREWO_WAKEN_SCIN(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_WAKEN_SCIN_SHIFT)) & ESPI_WIREWO_WAKEN_SCIN_MASK)

#define ESPI_WIREWO_PMEN_MASK                    (0x4U)
#define ESPI_WIREWO_PMEN_SHIFT                   (2U)
/*! PMEN - SMIN */
#define ESPI_WIREWO_PMEN(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_PMEN_SHIFT)) & ESPI_WIREWO_PMEN_MASK)

#define ESPI_WIREWO_SCIN_MASK                    (0x8U)
#define ESPI_WIREWO_SCIN_SHIFT                   (3U)
/*! SCIN - IRQ2 */
#define ESPI_WIREWO_SCIN(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_SCIN_SHIFT)) & ESPI_WIREWO_SCIN_MASK)

#define ESPI_WIREWO_SMIN_MASK                    (0x10U)
#define ESPI_WIREWO_SMIN_SHIFT                   (4U)
/*! SMIN - IRQ3 */
#define ESPI_WIREWO_SMIN(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_SMIN_SHIFT)) & ESPI_WIREWO_SMIN_MASK)

#define ESPI_WIREWO_RCINN_MASK                   (0x20U)
#define ESPI_WIREWO_RCINN_SHIFT                  (5U)
/*! RCINN - IRQ4 */
#define ESPI_WIREWO_RCINN(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_RCINN_SHIFT)) & ESPI_WIREWO_RCINN_MASK)

#define ESPI_WIREWO_HOST_RST_ACK_MASK            (0x40U)
#define ESPI_WIREWO_HOST_RST_ACK_SHIFT           (6U)
/*! HOST_RST_ACK - IRQ5 */
#define ESPI_WIREWO_HOST_RST_ACK(x)              (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_HOST_RST_ACK_SHIFT)) & ESPI_WIREWO_HOST_RST_ACK_MASK)

#define ESPI_WIREWO_SUSACKN_MASK                 (0x80U)
#define ESPI_WIREWO_SUSACKN_SHIFT                (7U)
/*! SUSACKN - IRQ6 */
#define ESPI_WIREWO_SUSACKN(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_SUSACKN_SHIFT)) & ESPI_WIREWO_SUSACKN_MASK)

#define ESPI_WIREWO_E2P_MASK                     (0xFF00U)
#define ESPI_WIREWO_E2P_SHIFT                    (8U)
/*! E2P - IRQ7-IRQ15 */
#define ESPI_WIREWO_E2P(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_E2P_SHIFT)) & ESPI_WIREWO_E2P_MASK)

#define ESPI_WIREWO_BOOT_DONE_MASK               (0x10000U)
#define ESPI_WIREWO_BOOT_DONE_SHIFT              (16U)
/*! BOOT_DONE - Boot Load Done */
#define ESPI_WIREWO_BOOT_DONE(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_BOOT_DONE_SHIFT)) & ESPI_WIREWO_BOOT_DONE_MASK)

#define ESPI_WIREWO_BOOT_ERRN_MASK               (0x20000U)
#define ESPI_WIREWO_BOOT_ERRN_SHIFT              (17U)
/*! BOOT_ERRN - Boot Load Error
 *  0b0..Boot load error
 *  0b1..Boot load successful
 */
#define ESPI_WIREWO_BOOT_ERRN(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_BOOT_ERRN_SHIFT)) & ESPI_WIREWO_BOOT_ERRN_MASK)

#define ESPI_WIREWO_DSW_PWROK_RST_MASK           (0x40000U)
#define ESPI_WIREWO_DSW_PWROK_RST_SHIFT          (18U)
/*! DSW_PWROK_RST - Force */
#define ESPI_WIREWO_DSW_PWROK_RST(x)             (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_DSW_PWROK_RST_SHIFT)) & ESPI_WIREWO_DSW_PWROK_RST_MASK)

#define ESPI_WIREWO_DONE_MASK                    (0x80000000U)
#define ESPI_WIREWO_DONE_SHIFT                   (31U)
/*! DONE - Write Done
 *  0b0..Write not done
 *  0b1..Write done
 */
#define ESPI_WIREWO_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_DONE_SHIFT)) & ESPI_WIREWO_DONE_MASK)
/*! @} */

/*! @name WIRERO - Virtual Wire Host-to-MCU */
/*! @{ */

#define ESPI_WIRERO_SLP_S3N_MASK                 (0x1U)
#define ESPI_WIRERO_SLP_S3N_SHIFT                (0U)
/*! SLP_S3N - Sleep State 3 */
#define ESPI_WIRERO_SLP_S3N(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SLP_S3N_SHIFT)) & ESPI_WIRERO_SLP_S3N_MASK)

#define ESPI_WIRERO_SLP_S4N_MASK                 (0x2U)
#define ESPI_WIRERO_SLP_S4N_SHIFT                (1U)
/*! SLP_S4N - Sleep State 4 */
#define ESPI_WIRERO_SLP_S4N(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SLP_S4N_SHIFT)) & ESPI_WIRERO_SLP_S4N_MASK)

#define ESPI_WIRERO_SLP_S5N_MASK                 (0x4U)
#define ESPI_WIRERO_SLP_S5N_SHIFT                (2U)
/*! SLP_S5N - Sleep State 5 */
#define ESPI_WIRERO_SLP_S5N(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SLP_S5N_SHIFT)) & ESPI_WIRERO_SLP_S5N_MASK)

#define ESPI_WIRERO_SUS_STAT_MASK                (0x8U)
#define ESPI_WIRERO_SUS_STAT_SHIFT               (3U)
/*! SUS_STAT - Suspend Status */
#define ESPI_WIRERO_SUS_STAT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SUS_STAT_SHIFT)) & ESPI_WIRERO_SUS_STAT_MASK)

#define ESPI_WIRERO_PLTRSTN_MASK                 (0x10U)
#define ESPI_WIRERO_PLTRSTN_SHIFT                (4U)
/*! PLTRSTN - Reset Request */
#define ESPI_WIRERO_PLTRSTN(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_PLTRSTN_SHIFT)) & ESPI_WIRERO_PLTRSTN_MASK)

#define ESPI_WIRERO_OOB_RST_WARN_MASK            (0x20U)
#define ESPI_WIRERO_OOB_RST_WARN_SHIFT           (5U)
/*! OOB_RST_WARN - Out-Of-Band Reset Warning */
#define ESPI_WIRERO_OOB_RST_WARN(x)              (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_OOB_RST_WARN_SHIFT)) & ESPI_WIRERO_OOB_RST_WARN_MASK)

#define ESPI_WIRERO_HOST_RST_WARN_MASK           (0x40U)
#define ESPI_WIRERO_HOST_RST_WARN_SHIFT          (6U)
/*! HOST_RST_WARN - Host Reset Warning */
#define ESPI_WIRERO_HOST_RST_WARN(x)             (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_HOST_RST_WARN_SHIFT)) & ESPI_WIRERO_HOST_RST_WARN_MASK)

#define ESPI_WIRERO_SUS_WARN_MASK                (0x80U)
#define ESPI_WIRERO_SUS_WARN_SHIFT               (7U)
/*! SUS_WARN - Suspend Warning */
#define ESPI_WIRERO_SUS_WARN(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SUS_WARN_SHIFT)) & ESPI_WIRERO_SUS_WARN_MASK)

#define ESPI_WIRERO_SUS_PWRDN_ACKN_MASK          (0x100U)
#define ESPI_WIRERO_SUS_PWRDN_ACKN_SHIFT         (8U)
/*! SUS_PWRDN_ACKN - Suspend Power Well Acknowledge */
#define ESPI_WIRERO_SUS_PWRDN_ACKN(x)            (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SUS_PWRDN_ACKN_SHIFT)) & ESPI_WIRERO_SUS_PWRDN_ACKN_MASK)

#define ESPI_WIRERO_SLP_AN_MASK                  (0x200U)
#define ESPI_WIRERO_SLP_AN_SHIFT                 (9U)
/*! SLP_AN - Sleep AN */
#define ESPI_WIRERO_SLP_AN(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SLP_AN_SHIFT)) & ESPI_WIRERO_SLP_AN_MASK)

#define ESPI_WIRERO_SLP_LAN_MASK                 (0x400U)
#define ESPI_WIRERO_SLP_LAN_SHIFT                (10U)
/*! SLP_LAN - Wired LAN Sleep */
#define ESPI_WIRERO_SLP_LAN(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SLP_LAN_SHIFT)) & ESPI_WIRERO_SLP_LAN_MASK)

#define ESPI_WIRERO_SLP_WLAN_MASK                (0x800U)
#define ESPI_WIRERO_SLP_WLAN_SHIFT               (11U)
/*! SLP_WLAN - Wireless LAN Sleep */
#define ESPI_WIRERO_SLP_WLAN(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_SLP_WLAN_SHIFT)) & ESPI_WIRERO_SLP_WLAN_MASK)

#define ESPI_WIRERO_P2E_MASK                     (0xFF000U)
#define ESPI_WIRERO_P2E_SHIFT                    (12U)
/*! P2E - PCIe to EC */
#define ESPI_WIRERO_P2E(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_P2E_SHIFT)) & ESPI_WIRERO_P2E_MASK)

#define ESPI_WIRERO_HOST_C10N_MASK               (0x100000U)
#define ESPI_WIRERO_HOST_C10N_SHIFT              (20U)
/*! HOST_C10N - Host Entering Deep Power Down C10 State */
#define ESPI_WIRERO_HOST_C10N(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_HOST_C10N_SHIFT)) & ESPI_WIRERO_HOST_C10N_MASK)
/*! @} */

/*! @name P80STAT - Port 80 Status */
/*! @{ */

#define ESPI_P80STAT_CURR_MASK                   (0xFFU)
#define ESPI_P80STAT_CURR_SHIFT                  (0U)
/*! CURR - Current Port80 Value */
#define ESPI_P80STAT_CURR(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_CURR_SHIFT)) & ESPI_P80STAT_CURR_MASK)

#define ESPI_P80STAT_PREV_MASK                   (0xFF00U)
#define ESPI_P80STAT_PREV_SHIFT                  (8U)
/*! PREV - Previous Port80 Value */
#define ESPI_P80STAT_PREV(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_PREV_SHIFT)) & ESPI_P80STAT_PREV_MASK)

#define ESPI_P80STAT_CNT_MASK                    (0xF0000U)
#define ESPI_P80STAT_CNT_SHIFT                   (16U)
/*! CNT - Counter */
#define ESPI_P80STAT_CNT(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_CNT_SHIFT)) & ESPI_P80STAT_CNT_MASK)

#define ESPI_P80STAT_RST_MASK                    (0x100000U)
#define ESPI_P80STAT_RST_SHIFT                   (20U)
/*! RST - Counter Reset */
#define ESPI_P80STAT_RST(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_RST_SHIFT)) & ESPI_P80STAT_RST_MASK)
/*! @} */

/*! @name STATADDR - Status Block Address */
/*! @{ */

#define ESPI_STATADDR_OFF_MASK                   (0xFFF8U)
#define ESPI_STATADDR_OFF_SHIFT                  (3U)
/*! OFF - Offset */
#define ESPI_STATADDR_OFF(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_STATADDR_OFF_SHIFT)) & ESPI_STATADDR_OFF_MASK)

#define ESPI_STATADDR_BASE_MASK                  (0x30000U)
#define ESPI_STATADDR_BASE_SHIFT                 (16U)
/*! BASE - Offset Base
 *  0b00..Offset from 0 in host memory or I/O space
 *  0b01..Base1 offset in host memory
 *  0b10..Base2 offset in host memory
 *  0b11..Reserved
 */
#define ESPI_STATADDR_BASE(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_STATADDR_BASE_SHIFT)) & ESPI_STATADDR_BASE_MASK)
/*! @} */

/*! @name ESPICAP - eSPI Capabilities */
/*! @{ */

#define ESPI_ESPICAP_SPICAP_MASK                 (0x3U)
#define ESPI_ESPICAP_SPICAP_SHIFT                (0U)
/*! SPICAP - SPI mode allowed (host still has to select):
 *  0b00..SPI only
 *  0b01..BiSPI and SPI
 *  0b10..FLEXSPI and SPI
 *  0b11..Any
 */
#define ESPI_ESPICAP_SPICAP(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_SPICAP_SHIFT)) & ESPI_ESPICAP_SPICAP_MASK)

#define ESPI_ESPICAP_MAXSPD_MASK                 (0x70U)
#define ESPI_ESPICAP_MAXSPD_SHIFT                (4U)
/*! MAXSPD - Maximum SPI Clock Speed
 *  0b000..<=20 MHz
 *  0b001..<=25 MHz (24 Mhz)
 *  0b010..<=33 MHz (30 MHz)
 *  0b011..<=50 MHz (48 MHz)
 *  0b100..<=66 MHz (60 MHz)
 */
#define ESPI_ESPICAP_MAXSPD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_MAXSPD_SHIFT)) & ESPI_ESPICAP_MAXSPD_MASK)

#define ESPI_ESPICAP_ALPIN_MASK                  (0x80U)
#define ESPI_ESPICAP_ALPIN_SHIFT                 (7U)
/*! ALPIN - Alert Pin */
#define ESPI_ESPICAP_ALPIN(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_ALPIN_SHIFT)) & ESPI_ESPICAP_ALPIN_MASK)

#define ESPI_ESPICAP_OOBOK_MASK                  (0x100U)
#define ESPI_ESPICAP_OOBOK_SHIFT                 (8U)
/*! OOBOK - OOB Allow
 *  0b0..Do not allow OOB
 *  0b1..Allow OOB
 */
#define ESPI_ESPICAP_OOBOK(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_OOBOK_SHIFT)) & ESPI_ESPICAP_OOBOK_MASK)

#define ESPI_ESPICAP_FLASHMX_MASK                (0xC00U)
#define ESPI_ESPICAP_FLASHMX_SHIFT               (10U)
/*! FLASHMX - Maximum Flash Payload Size
 *  0b00..64 bytes
 *  0b01..128 bytes
 *  0b10..256 bytes
 *  0b11..512 bytes
 */
#define ESPI_ESPICAP_FLASHMX(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_FLASHMX_SHIFT)) & ESPI_ESPICAP_FLASHMX_MASK)

#define ESPI_ESPICAP_SAF_MASK                    (0x1000U)
#define ESPI_ESPICAP_SAF_SHIFT                   (12U)
/*! SAF - Slave-Attached Flash
 *  0b0..Host cannot support SAF
 *  0b1..SAF is possible with the firmware.
 */
#define ESPI_ESPICAP_SAF(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_SAF_SHIFT)) & ESPI_ESPICAP_SAF_MASK)

#define ESPI_ESPICAP_SAFERA_MASK                 (0x1E000U)
#define ESPI_ESPICAP_SAFERA_SHIFT                (13U)
/*! SAFERA - SAF Erase Sector
 *  0b0000..2 kB
 *  0b0001..4 kB
 *  0b0010..8 kB
 *  0b0011..16 kB
 */
#define ESPI_ESPICAP_SAFERA(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_SAFERA_SHIFT)) & ESPI_ESPICAP_SAFERA_MASK)

#define ESPI_ESPICAP_MAF_MASK                    (0x20000U)
#define ESPI_ESPICAP_MAF_SHIFT                   (17U)
/*! MAF - Master-Attached Flash
 *  0b0..Host cannot support MAF
 *  0b1..If 1, then Master Attached Flash is possible with this firmware
 */
#define ESPI_ESPICAP_MAF(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_MAF_SHIFT)) & ESPI_ESPICAP_MAF_MASK)

#define ESPI_ESPICAP_TRGT_REQ_SIZE_SUPP_MASK     (0x1C0000U)
#define ESPI_ESPICAP_TRGT_REQ_SIZE_SUPP_SHIFT    (18U)
/*! TRGT_REQ_SIZE_SUPP - Target Maximum Read Request Size Supported
 *  0b000..Reserved
 *  0b001..64 bytes max read request size
 *  0b010..128 bytes max read request size
 *  0b011..256 bytes max read request size
 *  0b100..512 bytes max read request size
 *  0b101..1024 bytes max read request size
 *  0b110..2048 bytes max read request size
 *  0b111..4096 bytes max read request size
 */
#define ESPI_ESPICAP_TRGT_REQ_SIZE_SUPP(x)       (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_TRGT_REQ_SIZE_SUPP_SHIFT)) & ESPI_ESPICAP_TRGT_REQ_SIZE_SUPP_MASK)

#define ESPI_ESPICAP_MEMMX_MASK                  (0x600000U)
#define ESPI_ESPICAP_MEMMX_SHIFT                 (21U)
/*! MEMMX - Peripheral Channel Maximum Payload Size Supported
 *  0b00..Reserved
 *  0b01..64 bytes address aligned max payload size
 *  0b10..128 bytes address aligned max payload size
 *  0b11..256 bytes address aligned max payload size
 */
#define ESPI_ESPICAP_MEMMX(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_MEMMX_SHIFT)) & ESPI_ESPICAP_MEMMX_MASK)

#define ESPI_ESPICAP_OOBMX_MASK                  (0x1800000U)
#define ESPI_ESPICAP_OOBMX_SHIFT                 (23U)
/*! OOBMX - OOB Message Channel Maximum Payload Size Supported
 *  0b00..Reserved
 *  0b01..64 bytes address aligned max payload size
 *  0b10..128 bytes address aligned max payload size
 *  0b11..256 bytes address aligned max payload size
 */
#define ESPI_ESPICAP_OOBMX(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_OOBMX_SHIFT)) & ESPI_ESPICAP_OOBMX_MASK)
/*! @} */

/*! @name ESPICFG - eSPI Configuration */
/*! @{ */

#define ESPI_ESPICFG_SAF_MASK                    (0x1U)
#define ESPI_ESPICFG_SAF_SHIFT                   (0U)
/*! SAF - Slave-Attached Flash Supported
 *  0b0..Host cannot support SAF
 *  0b1..Slave Attached Flash is possible with the firmware.
 */
#define ESPI_ESPICFG_SAF(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_SAF_SHIFT)) & ESPI_ESPICFG_SAF_MASK)

#define ESPI_ESPICFG_FLASHSZ_MASK                (0x6U)
#define ESPI_ESPICFG_FLASHSZ_SHIFT               (1U)
/*! FLASHSZ - Flash Size
 *  0b00..64 bytes
 *  0b01..128 bytes
 *  0b10..256 bytes
 *  0b11..512 bytes
 */
#define ESPI_ESPICFG_FLASHSZ(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_FLASHSZ_SHIFT)) & ESPI_ESPICFG_FLASHSZ_MASK)

#define ESPI_ESPICFG_SPIMOD_MASK                 (0x18U)
#define ESPI_ESPICFG_SPIMOD_SHIFT                (3U)
/*! SPIMOD - SPI Mode
 *  0b00..SPI
 *  0b01..BiSPI
 *  0b10..FLEXSPI
 */
#define ESPI_ESPICFG_SPIMOD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_SPIMOD_SHIFT)) & ESPI_ESPICFG_SPIMOD_MASK)

#define ESPI_ESPICFG_ALERT_MASK                  (0x20U)
#define ESPI_ESPICFG_ALERT_SHIFT                 (5U)
/*! ALERT - Alert Is Pin */
#define ESPI_ESPICFG_ALERT(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_ALERT_SHIFT)) & ESPI_ESPICFG_ALERT_MASK)

#define ESPI_ESPICFG_ALERTOD_MASK                (0x40U)
#define ESPI_ESPICFG_ALERTOD_SHIFT               (6U)
/*! ALERTOD - Alert Is Open Drain as Pin */
#define ESPI_ESPICFG_ALERTOD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_ALERTOD_SHIFT)) & ESPI_ESPICFG_ALERTOD_MASK)

#define ESPI_ESPICFG_SPISPD_MASK                 (0x380U)
#define ESPI_ESPICFG_SPISPD_SHIFT                (7U)
/*! SPISPD - SPI Speed
 *  0b000..20 MHz or less
 *  0b001..25 MHz or 24 MHz
 *  0b010..33 MHz or 30 MHz
 *  0b011..50 MHz or 48 MHz
 *  0b100..66 MHz or 60 MHz
 */
#define ESPI_ESPICFG_SPISPD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_SPISPD_SHIFT)) & ESPI_ESPICFG_SPISPD_MASK)

#define ESPI_ESPICFG_CRC_MASK                    (0x400U)
#define ESPI_ESPICFG_CRC_SHIFT                   (10U)
/*! CRC - CRC Checking Enabled */
#define ESPI_ESPICFG_CRC(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_CRC_SHIFT)) & ESPI_ESPICFG_CRC_MASK)

#define ESPI_ESPICFG_BUSMOK_MASK                 (0x800U)
#define ESPI_ESPICFG_BUSMOK_SHIFT                (11U)
/*! BUSMOK - Bus Master OK */
#define ESPI_ESPICFG_BUSMOK(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_BUSMOK_SHIFT)) & ESPI_ESPICFG_BUSMOK_MASK)

#define ESPI_ESPICFG_MEMENA_MASK                 (0x1000U)
#define ESPI_ESPICFG_MEMENA_SHIFT                (12U)
/*! MEMENA - Channel 0 (Memory) Enabled */
#define ESPI_ESPICFG_MEMENA(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_MEMENA_SHIFT)) & ESPI_ESPICFG_MEMENA_MASK)

#define ESPI_ESPICFG_VWOK_MASK                   (0x2000U)
#define ESPI_ESPICFG_VWOK_SHIFT                  (13U)
/*! VWOK - Channel 1 (VWire) Enabled */
#define ESPI_ESPICFG_VWOK(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_VWOK_SHIFT)) & ESPI_ESPICFG_VWOK_MASK)

#define ESPI_ESPICFG_OOBOK_MASK                  (0x4000U)
#define ESPI_ESPICFG_OOBOK_SHIFT                 (14U)
/*! OOBOK - Channel 2 (OOB) Enabled */
#define ESPI_ESPICFG_OOBOK(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_OOBOK_SHIFT)) & ESPI_ESPICFG_OOBOK_MASK)

#define ESPI_ESPICFG_FLSHERA_MASK                (0x38000U)
#define ESPI_ESPICFG_FLSHERA_SHIFT               (15U)
/*! FLSHERA - Flash Erase Size and Whether Enabled
 *  0b000..Flash not enabled
 *  0b001..Erase is 4 kB
 *  0b010..Erase is 64 kB
 *  0b011..Erase allows 4 kB and 64 kB
 *  0b100..Erase is 128 kB
 *  0b101..Erase is 256 kB
 */
#define ESPI_ESPICFG_FLSHERA(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_FLSHERA_SHIFT)) & ESPI_ESPICFG_FLSHERA_MASK)

#define ESPI_ESPICFG_FLSHOK_MASK                 (0x40000U)
#define ESPI_ESPICFG_FLSHOK_SHIFT                (18U)
/*! FLSHOK - Channel 3 (Flash) Enabled */
#define ESPI_ESPICFG_FLSHOK(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_FLSHOK_SHIFT)) & ESPI_ESPICFG_FLSHOK_MASK)

#define ESPI_ESPICFG_MEMSZ_MASK                  (0x180000U)
#define ESPI_ESPICFG_MEMSZ_SHIFT                 (19U)
/*! MEMSZ - Peripheral Channel Maximum Payload Size Selected
 *  0b00..Reserved
 *  0b01..64-byte payload for memory
 *  0b10..128-byte payload for memory and OOB access
 *  0b11..256-byte payload for memory and OOB access
 */
#define ESPI_ESPICFG_MEMSZ(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_MEMSZ_SHIFT)) & ESPI_ESPICFG_MEMSZ_MASK)

#define ESPI_ESPICFG_OOBSZ_MASK                  (0x600000U)
#define ESPI_ESPICFG_OOBSZ_SHIFT                 (21U)
/*! OOBSZ - OOB Message Channel Maximum Payload Size Selected
 *  0b00..Reserved
 *  0b01..64-byte payload for memory
 *  0b10..128-byte payload for memory and OOB access
 *  0b11..256-byte payload for memory and OOB access
 */
#define ESPI_ESPICFG_OOBSZ(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_OOBSZ_SHIFT)) & ESPI_ESPICFG_OOBSZ_MASK)
/*! @} */

/*! @name ESPIMISC - eSPI Miscellaneous */
/*! @{ */

#define ESPI_ESPIMISC_GPIO_OE_MASK               (0x1U)
#define ESPI_ESPIMISC_GPIO_OE_SHIFT              (0U)
/*! GPIO_OE - GPIO Output Enable
 *  0b0..Input (High-Z)
 *  0b1..Alert or reset pin is set as an output GPIO.
 */
#define ESPI_ESPIMISC_GPIO_OE(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_OE_SHIFT)) & ESPI_ESPIMISC_GPIO_OE_MASK)

#define ESPI_ESPIMISC_GPIO_OD_MASK               (0x2U)
#define ESPI_ESPIMISC_GPIO_OD_SHIFT              (1U)
/*! GPIO_OD - GPIO Open Drain
 *  0b0..Reserved
 *  0b1..Alert/Reset pin acts as open drain when ESPIMISC[GPIO_OE] = 1. This means ESPIMISC[GPIO_OUT] = 0 is low,
 *       and ESPIMISC[GPIO_OUT] = 1 is high-Z.
 */
#define ESPI_ESPIMISC_GPIO_OD(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_OD_SHIFT)) & ESPI_ESPIMISC_GPIO_OD_MASK)

#define ESPI_ESPIMISC_GPIO_OUT_MASK              (0x4U)
#define ESPI_ESPIMISC_GPIO_OUT_SHIFT             (2U)
/*! GPIO_OUT
 *  0b0..Low
 *  0b1..High, high-Z if ESPIMISC[GPIO_OD] = 1.
 */
#define ESPI_ESPIMISC_GPIO_OUT(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_OUT_SHIFT)) & ESPI_ESPIMISC_GPIO_OUT_MASK)

#define ESPI_ESPIMISC_GPIO_IN_MASK               (0x8U)
#define ESPI_ESPIMISC_GPIO_IN_SHIFT              (3U)
/*! GPIO_IN - GPIO Input */
#define ESPI_ESPIMISC_GPIO_IN(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_IN_SHIFT)) & ESPI_ESPIMISC_GPIO_IN_MASK)

#define ESPI_ESPIMISC_RISGP_MASK                 (0x10U)
#define ESPI_ESPIMISC_RISGP_SHIFT                (4U)
/*! RISGP - RSTN Pin Is GPIO
 *  0b0..Reserved
 *  0b1..In eSPI mode, if this bit is 1, RSTN pin is not used as Reset (affects behavior). It can be used as GPIO
 *       if Alert is dedicated to Alert (instead of MISO). This option does not apply in LPC mode.
 */
#define ESPI_ESPIMISC_RISGP(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_RISGP_SHIFT)) & ESPI_ESPIMISC_RISGP_MASK)

#define ESPI_ESPIMISC_PWRSAV_MASK                (0x80000000U)
#define ESPI_ESPIMISC_PWRSAV_SHIFT               (31U)
/*! PWRSAV - Power Save */
#define ESPI_ESPIMISC_PWRSAV(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_PWRSAV_SHIFT)) & ESPI_ESPIMISC_PWRSAV_MASK)
/*! @} */

/*! @name RPMC_SUPPORT1 - RPMC Support 1 */
/*! @{ */

#define ESPI_RPMC_SUPPORT1_TARGET_RPMC_SUPPORTED_MASK (0x3FU)
#define ESPI_RPMC_SUPPORT1_TARGET_RPMC_SUPPORTED_SHIFT (0U)
/*! TARGET_RPMC_SUPPORTED - Target RPMC Supported
 *  0b000000..Target does not support Replay Protected Monotonic counter
 *  0b000001..Target supports up to 1 Replay Protected Monotonic counter
 *  0b000010..Target supports up to 2 Replay Protected Monotonic counters
 *  0b000011..Target supports up to 63 Replay Protected Monotonic counters. The value of this field is the total
 *            sum of Replay Protected Monotonic counters supported by all RPMC flash devices behind the target. If
 *            RPMC is not supported by the target, this field must indicate a value of 0h.
 */
#define ESPI_RPMC_SUPPORT1_TARGET_RPMC_SUPPORTED(x) (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT1_TARGET_RPMC_SUPPORTED_SHIFT)) & ESPI_RPMC_SUPPORT1_TARGET_RPMC_SUPPORTED_MASK)

#define ESPI_RPMC_SUPPORT1_NUM_OF_TARGET_MASK    (0xC0U)
#define ESPI_RPMC_SUPPORT1_NUM_OF_TARGET_SHIFT   (6U)
/*! NUM_OF_TARGET - Number of Target Attached Flash RPMC flash devices
 *  0b00..1 RPMC flash device is supported
 *  0b01..2 RPMC flash device is supported
 *  0b10..3 RPMC flash device is supported
 *  0b11..4 RPMC flash device is supported
 */
#define ESPI_RPMC_SUPPORT1_NUM_OF_TARGET(x)      (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT1_NUM_OF_TARGET_SHIFT)) & ESPI_RPMC_SUPPORT1_NUM_OF_TARGET_MASK)

#define ESPI_RPMC_SUPPORT1_RPMC_OP1_MASK         (0xFF00U)
#define ESPI_RPMC_SUPPORT1_RPMC_OP1_SHIFT        (8U)
/*! RPMC_OP1 - RPMC OP1 Opcode on the 1st RPMC Flash device */
#define ESPI_RPMC_SUPPORT1_RPMC_OP1(x)           (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT1_RPMC_OP1_SHIFT)) & ESPI_RPMC_SUPPORT1_RPMC_OP1_MASK)

#define ESPI_RPMC_SUPPORT1_RPMC_COUNTER_MASK     (0xF0000U)
#define ESPI_RPMC_SUPPORT1_RPMC_COUNTER_SHIFT    (16U)
/*! RPMC_COUNTER - RPMC Counter on the 1st RPMC Flash device */
#define ESPI_RPMC_SUPPORT1_RPMC_COUNTER(x)       (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT1_RPMC_COUNTER_SHIFT)) & ESPI_RPMC_SUPPORT1_RPMC_COUNTER_MASK)

#define ESPI_RPMC_SUPPORT1_RPMC_OP1_2_MASK       (0xFF00000U)
#define ESPI_RPMC_SUPPORT1_RPMC_OP1_2_SHIFT      (20U)
/*! RPMC_OP1_2 - RPMC OP1 Opcode on the 2nd RPMC Flash device */
#define ESPI_RPMC_SUPPORT1_RPMC_OP1_2(x)         (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT1_RPMC_OP1_2_SHIFT)) & ESPI_RPMC_SUPPORT1_RPMC_OP1_2_MASK)

#define ESPI_RPMC_SUPPORT1_RPMC_COUNTER_2_MASK   (0xF0000000U)
#define ESPI_RPMC_SUPPORT1_RPMC_COUNTER_2_SHIFT  (28U)
/*! RPMC_COUNTER_2 - RPMC Counter on the 2nd RPMC Flash device */
#define ESPI_RPMC_SUPPORT1_RPMC_COUNTER_2(x)     (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT1_RPMC_COUNTER_2_SHIFT)) & ESPI_RPMC_SUPPORT1_RPMC_COUNTER_2_MASK)
/*! @} */

/*! @name RPMC_SUPPORT2 - RPMC Support 2 */
/*! @{ */

#define ESPI_RPMC_SUPPORT2_RPMC_COUNTER_3_MASK   (0xFU)
#define ESPI_RPMC_SUPPORT2_RPMC_COUNTER_3_SHIFT  (0U)
/*! RPMC_COUNTER_3 - RPMC Counter on the 3rd RPMC Flash device */
#define ESPI_RPMC_SUPPORT2_RPMC_COUNTER_3(x)     (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT2_RPMC_COUNTER_3_SHIFT)) & ESPI_RPMC_SUPPORT2_RPMC_COUNTER_3_MASK)

#define ESPI_RPMC_SUPPORT2_RPMC_OP1_3_MASK       (0xFF0U)
#define ESPI_RPMC_SUPPORT2_RPMC_OP1_3_SHIFT      (4U)
/*! RPMC_OP1_3 - RPMC OP1 Opcode on the 3rd RPMC Flash device */
#define ESPI_RPMC_SUPPORT2_RPMC_OP1_3(x)         (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT2_RPMC_OP1_3_SHIFT)) & ESPI_RPMC_SUPPORT2_RPMC_OP1_3_MASK)

#define ESPI_RPMC_SUPPORT2_RPMC_COUNTER_4_MASK   (0xF000U)
#define ESPI_RPMC_SUPPORT2_RPMC_COUNTER_4_SHIFT  (12U)
/*! RPMC_COUNTER_4 - RPMC Counter on the 4th RPMC Flash device */
#define ESPI_RPMC_SUPPORT2_RPMC_COUNTER_4(x)     (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT2_RPMC_COUNTER_4_SHIFT)) & ESPI_RPMC_SUPPORT2_RPMC_COUNTER_4_MASK)

#define ESPI_RPMC_SUPPORT2_RPMC_OP1_4_MASK       (0xFF0000U)
#define ESPI_RPMC_SUPPORT2_RPMC_OP1_4_SHIFT      (16U)
/*! RPMC_OP1_4 - RPMC OP1 Opcode on the 4th RPMC Flash device */
#define ESPI_RPMC_SUPPORT2_RPMC_OP1_4(x)         (((uint32_t)(((uint32_t)(x)) << ESPI_RPMC_SUPPORT2_RPMC_OP1_4_SHIFT)) & ESPI_RPMC_SUPPORT2_RPMC_OP1_4_MASK)
/*! @} */

/*! @name WIREIN_GPIO - WIREIN_GPIO */
/*! @{ */

#define ESPI_WIREIN_GPIO_LEVEL_MASK              (0xFU)
#define ESPI_WIREIN_GPIO_LEVEL_SHIFT             (0U)
/*! LEVEL - Level
 *  0b0000..Low
 *  0b0001..High
 */
#define ESPI_WIREIN_GPIO_LEVEL(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_WIREIN_GPIO_LEVEL_SHIFT)) & ESPI_WIREIN_GPIO_LEVEL_MASK)

#define ESPI_WIREIN_GPIO_VALID_MASK              (0xF0U)
#define ESPI_WIREIN_GPIO_VALID_SHIFT             (4U)
/*! VALID - Valid
 *  0b0000..Not valid
 *  0b0001..Valid
 */
#define ESPI_WIREIN_GPIO_VALID(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_WIREIN_GPIO_VALID_SHIFT)) & ESPI_WIREIN_GPIO_VALID_MASK)

#define ESPI_WIREIN_GPIO_INDEX_MASK              (0xFF00U)
#define ESPI_WIREIN_GPIO_INDEX_SHIFT             (8U)
/*! INDEX - Index */
#define ESPI_WIREIN_GPIO_INDEX(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_WIREIN_GPIO_INDEX_SHIFT)) & ESPI_WIREIN_GPIO_INDEX_MASK)
/*! @} */

/*! @name WIREOUT_GPIO - WIREOUT_GPIO */
/*! @{ */

#define ESPI_WIREOUT_GPIO_LEVEL_MASK             (0xFU)
#define ESPI_WIREOUT_GPIO_LEVEL_SHIFT            (0U)
/*! LEVEL - Level
 *  0b0000..Low
 *  0b0001..High
 */
#define ESPI_WIREOUT_GPIO_LEVEL(x)               (((uint32_t)(((uint32_t)(x)) << ESPI_WIREOUT_GPIO_LEVEL_SHIFT)) & ESPI_WIREOUT_GPIO_LEVEL_MASK)

#define ESPI_WIREOUT_GPIO_VALID_MASK             (0xF0U)
#define ESPI_WIREOUT_GPIO_VALID_SHIFT            (4U)
/*! VALID - Valid
 *  0b0000..Not valid
 *  0b0001..Valid
 */
#define ESPI_WIREOUT_GPIO_VALID(x)               (((uint32_t)(((uint32_t)(x)) << ESPI_WIREOUT_GPIO_VALID_SHIFT)) & ESPI_WIREOUT_GPIO_VALID_MASK)

#define ESPI_WIREOUT_GPIO_INDEX_MASK             (0xFF00U)
#define ESPI_WIREOUT_GPIO_INDEX_SHIFT            (8U)
/*! INDEX - Index */
#define ESPI_WIREOUT_GPIO_INDEX(x)               (((uint32_t)(((uint32_t)(x)) << ESPI_WIREOUT_GPIO_INDEX_SHIFT)) & ESPI_WIREOUT_GPIO_INDEX_MASK)
/*! @} */

/*! @name CFG - Port Configuration */
/*! @{ */

#define ESPI_CFG_TYPE_MASK                       (0xFU)
#define ESPI_CFG_TYPE_SHIFT                      (0U)
/*! TYPE - Interaction Type between Port and Host
 *  0b0000..Unconfigured (reset condition)
 *  0b0001..ACPI style Endpoint
 *  0b0010..ACPI style index-and-data. Index and data byte locations. Index gives offset into implied space. Uses registers for data and index.
 *  0b0011..Reserved
 *  0b0100..Bus Master Memory Single
 *  0b0101..Bus Master Flash Single
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Mailbox Shared
 *  0b1001..Mailbox Single
 *  0b1010..Mailbox Split
 *  0b1011..Mailbox OOB Split
 *  0b1100..Mailbox OEM
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define ESPI_CFG_TYPE(x)                         (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_TYPE_SHIFT)) & ESPI_CFG_TYPE_MASK)

#define ESPI_CFG_DIRECTION_MASK                  (0x60U)
#define ESPI_CFG_DIRECTION_SHIFT                 (5U)
/*! DIRECTION - Port Direction
 *  0b00..Endpoint or index-and-data: bidirectional (normal). Mailbox Single: unenforced. Mailbox Split or Mailbox Shared: bidirectional.
 *  0b01..Endpoint or index-and-data: ignore read. Mailbox Single: write only. Mailbox Split or Mailbox Shared: ignore read.
 *  0b10..Endpoint or index-and-data: ignore write. Mailbox Single: read only. Mailbox Split or Mailbox Shared: ignore write.
 *  0b11..Endpoint or index-and-data: Ignore both. Mailbox Single: ignore both. Mailbox Split or Mailbox Shared: ignore both.
 */
#define ESPI_CFG_DIRECTION(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_DIRECTION_SHIFT)) & ESPI_CFG_DIRECTION_MASK)

#define ESPI_CFG_MBINTALL_MASK                   (0x80U)
#define ESPI_CFG_MBINTALL_SHIFT                  (7U)
/*! MBINTALL - Mailbox: map interrupt */
#define ESPI_CFG_MBINTALL(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_MBINTALL_SHIFT)) & ESPI_CFG_MBINTALL_MASK)

#define ESPI_CFG_STALLRD_MASK                    (0x100U)
#define ESPI_CFG_STALLRD_SHIFT                   (8U)
/*! STALLRD - Stall on any read */
#define ESPI_CFG_STALLRD(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_STALLRD_SHIFT)) & ESPI_CFG_STALLRD_MASK)

#define ESPI_CFG_STALLWR_MASK                    (0x200U)
#define ESPI_CFG_STALLWR_SHIFT                   (9U)
/*! STALLWR - Stall on write */
#define ESPI_CFG_STALLWR(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_STALLWR_SHIFT)) & ESPI_CFG_STALLWR_MASK)

#define ESPI_CFG_ERRORIGN_MASK                   (0x400U)
#define ESPI_CFG_ERRORIGN_SHIFT                  (10U)
/*! ERRORIGN - Error Origin
 *  0b0..The host receives an error when trying to perform a read or write that is blocked by PnCFG[DIRECTION].
 *  0b1..Ignored silently. Reads return FFh for each byte if ignored (host property). In either case,
 *       PnSTAT[INTERR] bit becomes 1, causing an interrupt if masked for it.
 */
#define ESPI_CFG_ERRORIGN(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_ERRORIGN_SHIFT)) & ESPI_CFG_ERRORIGN_MASK)
/*! @} */

/* The count of ESPI_CFG */
#define ESPI_CFG_COUNT                           (5U)

/*! @name STAT - Port Status */
/*! @{ */

#define ESPI_STAT_RDSTAT_MASK                    (0x3U)
#define ESPI_STAT_RDSTAT_SHIFT                   (0U)
/*! RDSTAT - Host Read Data Status
 *  0b00..Endpoint or index-and-data: Empty. Mailbox: Empty (host read to end). Master/Flash: No requests.
 *  0b01..Endpoint or index-and-data: Data waiting from MCU. Mailbox: Started (by MCU). Master/Flash: Started.
 *        From-host: goes to Pending next. To-host: goes to Complete next. SAF: host made request: Started.
 *  0b10..Mailbox: Complete (by MCU). Master/Flash: Complete. SAF: Complete.
 *  0b11..Mailbox: Partially read (by host). Master/Flash: From-host only, Pending (request made); goes to
 *        Complete next. SAF: MCU has setup completion.
 */
#define ESPI_STAT_RDSTAT(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_RDSTAT_SHIFT)) & ESPI_STAT_RDSTAT_MASK)

#define ESPI_STAT_WRSTAT_MASK                    (0xCU)
#define ESPI_STAT_WRSTAT_SHIFT                   (2U)
/*! WRSTAT - Status of Host Writes
 *  0b00..Endpoint: Empty. Index-and-data: Empty. Mailbox: Empty. Master/flash: Not last request.
 *  0b01..Endpoint: data waiting from host. Index-and-data: data waiting from host (index may have been written
 *        before). Mailbox: Started (by host). Master/flash: last request from-host/read-flash (writes to MCU). SAF:
 *        Request from master was or is Flash Read.
 *  0b10..Endpoint: Empty, but last was CMD. Index-and-data: wrote index. Mailbox: complete/last (host to end).
 *        Master/flash: last request to-host/write-flash (read from MCU). SAF: Request from Master was or is Flash
 *        Write.
 *  0b11..Endpoint: CMD waiting from host. Index-and-data: Wrote Data then Index. Mailbox: Partially read (by
 *        MCU). Flash: Last Requested Erase. SAF: Request from Master was or is Flash Erase.
 */
#define ESPI_STAT_WRSTAT(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_WRSTAT_SHIFT)) & ESPI_STAT_WRSTAT_MASK)

#define ESPI_STAT_INTERR_MASK                    (0x100U)
#define ESPI_STAT_INTERR_SHIFT                   (8U)
/*! INTERR - Interrupt Caused by Error */
#define ESPI_STAT_INTERR(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTERR_SHIFT)) & ESPI_STAT_INTERR_MASK)

#define ESPI_STAT_INTRD_MASK                     (0x200U)
#define ESPI_STAT_INTRD_SHIFT                    (9U)
/*! INTRD - Interrupt Caused by Read */
#define ESPI_STAT_INTRD(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTRD_SHIFT)) & ESPI_STAT_INTRD_MASK)

#define ESPI_STAT_INTWR_MASK                     (0x400U)
#define ESPI_STAT_INTWR_SHIFT                    (10U)
/*! INTWR - Interrupt Caused by Write */
#define ESPI_STAT_INTWR(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTWR_SHIFT)) & ESPI_STAT_INTWR_MASK)

#define ESPI_STAT_INTSPC0_MASK                   (0x800U)
#define ESPI_STAT_INTSPC0_SHIFT                  (11U)
/*! INTSPC0 - SPC0 Interrupt */
#define ESPI_STAT_INTSPC0(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTSPC0_SHIFT)) & ESPI_STAT_INTSPC0_MASK)

#define ESPI_STAT_INTSPC1_MASK                   (0x1000U)
#define ESPI_STAT_INTSPC1_SHIFT                  (12U)
/*! INTSPC1 - SPC1 Interrupt */
#define ESPI_STAT_INTSPC1(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTSPC1_SHIFT)) & ESPI_STAT_INTSPC1_MASK)

#define ESPI_STAT_INTSPC2_MASK                   (0x2000U)
#define ESPI_STAT_INTSPC2_SHIFT                  (13U)
/*! INTSPC2 - SPC2 Interrupt */
#define ESPI_STAT_INTSPC2(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTSPC2_SHIFT)) & ESPI_STAT_INTSPC2_MASK)

#define ESPI_STAT_INSTSPC3_MASK                  (0x4000U)
#define ESPI_STAT_INSTSPC3_SHIFT                 (14U)
/*! INSTSPC3 - SPC3 Interrupt */
#define ESPI_STAT_INSTSPC3(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INSTSPC3_SHIFT)) & ESPI_STAT_INSTSPC3_MASK)

#define ESPI_STAT_ERR0_MASK                      (0x10000U)
#define ESPI_STAT_ERR0_SHIFT                     (16U)
/*! ERR0 - Error 0 */
#define ESPI_STAT_ERR0(x)                        (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_ERR0_SHIFT)) & ESPI_STAT_ERR0_MASK)

#define ESPI_STAT_ERR1_MASK                      (0x20000U)
#define ESPI_STAT_ERR1_SHIFT                     (17U)
/*! ERR1 - Error 1 */
#define ESPI_STAT_ERR1(x)                        (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_ERR1_SHIFT)) & ESPI_STAT_ERR1_MASK)

#define ESPI_STAT_ERR2_MASK                      (0x40000U)
#define ESPI_STAT_ERR2_SHIFT                     (18U)
/*! ERR2 - Error 2 */
#define ESPI_STAT_ERR2(x)                        (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_ERR2_SHIFT)) & ESPI_STAT_ERR2_MASK)

#define ESPI_STAT_ERR3_MASK                      (0x80000U)
#define ESPI_STAT_ERR3_SHIFT                     (19U)
/*! ERR3 - Error 3 */
#define ESPI_STAT_ERR3(x)                        (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_ERR3_SHIFT)) & ESPI_STAT_ERR3_MASK)

#define ESPI_STAT_RPMC_1_OR_2_MASK               (0x100000U)
#define ESPI_STAT_RPMC_1_OR_2_SHIFT              (20U)
/*! RPMC_1_OR_2 - RPMC 1 or 2
 *  0b0..RPMC operation 1 has been chosen
 *  0b1..RPMC operation 2 has been chosen
 */
#define ESPI_STAT_RPMC_1_OR_2(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_RPMC_1_OR_2_SHIFT)) & ESPI_STAT_RPMC_1_OR_2_MASK)

#define ESPI_STAT_RPMC_FLASH_DEVICE_MASK         (0x600000U)
#define ESPI_STAT_RPMC_FLASH_DEVICE_SHIFT        (21U)
/*! RPMC_FLASH_DEVICE - RPMC Flash Device
 *  0b00..First device
 *  0b01..Second device
 *  0b10..Third device
 *  0b11..Fourth device
 */
#define ESPI_STAT_RPMC_FLASH_DEVICE(x)           (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_RPMC_FLASH_DEVICE_SHIFT)) & ESPI_STAT_RPMC_FLASH_DEVICE_MASK)
/*! @} */

/* The count of ESPI_STAT */
#define ESPI_STAT_COUNT                          (5U)

/*! @name IRULESTAT - Set Interrupt Rules and User Status */
/*! @{ */

#define ESPI_IRULESTAT_USTAT_MASK                (0x1FU)
#define ESPI_IRULESTAT_USTAT_SHIFT               (0U)
/*! USTAT - User-Defined Status Bits */
#define ESPI_IRULESTAT_USTAT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_USTAT_SHIFT)) & ESPI_IRULESTAT_USTAT_MASK)

#define ESPI_IRULESTAT_INTERR_MASK               (0x100U)
#define ESPI_IRULESTAT_INTERR_SHIFT              (8U)
/*! INTERR - Interrupt If Error Detected */
#define ESPI_IRULESTAT_INTERR(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTERR_SHIFT)) & ESPI_IRULESTAT_INTERR_MASK)

#define ESPI_IRULESTAT_INTRD_MASK                (0x200U)
#define ESPI_IRULESTAT_INTRD_SHIFT               (9U)
/*! INTRD - Interrupt If Read or First Read or Bus Master Started */
#define ESPI_IRULESTAT_INTRD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTRD_SHIFT)) & ESPI_IRULESTAT_INTRD_MASK)

#define ESPI_IRULESTAT_INTWR_MASK                (0x400U)
#define ESPI_IRULESTAT_INTWR_SHIFT               (10U)
/*! INTWR - Interrupt If Write or First Write or Bus Master Finished */
#define ESPI_IRULESTAT_INTWR(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTWR_SHIFT)) & ESPI_IRULESTAT_INTWR_MASK)

#define ESPI_IRULESTAT_INTSPC_MASK               (0x7800U)
#define ESPI_IRULESTAT_INTSPC_SHIFT              (11U)
/*! INTSPC - Select Interrupts for PnSTAT[INTSPC0] through PnSTAT[INSTSPC3] */
#define ESPI_IRULESTAT_INTSPC(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTSPC_SHIFT)) & ESPI_IRULESTAT_INTSPC_MASK)

#define ESPI_IRULESTAT_SSTCL_MASK                (0xF0000U)
#define ESPI_IRULESTAT_SSTCL_SHIFT               (16U)
/*! SSTCL - Status Set and Clear */
#define ESPI_IRULESTAT_SSTCL(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_SSTCL_SHIFT)) & ESPI_IRULESTAT_SSTCL_MASK)

#define ESPI_IRULESTAT_SRST_MASK                 (0x100000U)
#define ESPI_IRULESTAT_SRST_SHIFT                (20U)
/*! SRST - Reset PnSTAT[RDSTAT] and PnSTAT[WRSTAT] */
#define ESPI_IRULESTAT_SRST(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_SRST_SHIFT)) & ESPI_IRULESTAT_SRST_MASK)

#define ESPI_IRULESTAT_FLASH_COMPLETION_TYPE_MASK (0x600000U)
#define ESPI_IRULESTAT_FLASH_COMPLETION_TYPE_SHIFT (21U)
/*! FLASH_COMPLETION_TYPE - Flash Completion Type
 *  0b00..Indicates the middle completion of a split completion sequence
 *  0b01..Indicates the first completion of a split completion sequence
 *  0b10..Indicates the last completion of a split completion sequence
 *  0b11..Indicates the only completion for a split transaction.
 */
#define ESPI_IRULESTAT_FLASH_COMPLETION_TYPE(x)  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_FLASH_COMPLETION_TYPE_SHIFT)) & ESPI_IRULESTAT_FLASH_COMPLETION_TYPE_MASK)

#define ESPI_IRULESTAT_CPU_TAG_MASK              (0x7800000U)
#define ESPI_IRULESTAT_CPU_TAG_SHIFT             (23U)
/*! CPU_TAG - CPU Tag */
#define ESPI_IRULESTAT_CPU_TAG(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_CPU_TAG_SHIFT)) & ESPI_IRULESTAT_CPU_TAG_MASK)
/*! @} */

/* The count of ESPI_IRULESTAT */
#define ESPI_IRULESTAT_COUNT                     (5U)

/*! @name ADDR - Port Address */
/*! @{ */

#define ESPI_ADDR_OFF_MASK                       (0xFFFFU)
#define ESPI_ADDR_OFF_SHIFT                      (0U)
/*! OFF - Offset */
#define ESPI_ADDR_OFF(x)                         (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_OFF_SHIFT)) & ESPI_ADDR_OFF_MASK)

#define ESPI_ADDR_BASE_ASZ_MASK                  (0x30000U)
#define ESPI_ADDR_BASE_ASZ_SHIFT                 (16U)
/*! BASE_ASZ - The meaning is dependent on type of port:
 *  0b00..Offset from 0 in host memory or I/O space.
 *  0b01..Uses BASE0 offset in host memory
 *  0b10..Uses BASE1 offset in host memory
 *  0b11..Reserved
 */
#define ESPI_ADDR_BASE_ASZ(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_BASE_ASZ_SHIFT)) & ESPI_ADDR_BASE_ASZ_MASK)

#define ESPI_ADDR_IDXOFF_MASK                    (0xF000000U)
#define ESPI_ADDR_IDXOFF_SHIFT                   (24U)
/*! IDXOFF - Index Offset */
#define ESPI_ADDR_IDXOFF(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_IDXOFF_SHIFT)) & ESPI_ADDR_IDXOFF_MASK)

#define ESPI_ADDR_IDX1ST_MASK                    (0x10000000U)
#define ESPI_ADDR_IDX1ST_SHIFT                   (28U)
/*! IDX1ST
 *  0b0..Index is higher address than data (for example, data at OFF, index at OFF+IDXOFF)
 *  0b1..Index is lower address than data (for example, index at OFF, data at OFF+IDXOFF)
 */
#define ESPI_ADDR_IDX1ST(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_IDX1ST_SHIFT)) & ESPI_ADDR_IDX1ST_MASK)
/*! @} */

/* The count of ESPI_ADDR */
#define ESPI_ADDR_COUNT                          (5U)

/*! @name OMFLEN - Port OOB, Mastering, and Flash Length */
/*! @{ */

#define ESPI_OMFLEN_LEN_MASK                     (0x7FU)
#define ESPI_OMFLEN_LEN_SHIFT                    (0U)
/*! LEN - Length in Bytes */
#define ESPI_OMFLEN_LEN(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_OMFLEN_LEN_SHIFT)) & ESPI_OMFLEN_LEN_MASK)

#define ESPI_OMFLEN_TRANS_MASK                   (0x3000U)
#define ESPI_OMFLEN_TRANS_SHIFT                  (12U)
/*! TRANS - Transfer Request
 *  0b00..OOB: to host; Master: to host 32 (host reads with 32-bit address); SAF: Completion fail
 *  0b01..Master: to host 64 (host reads w/64-bit address); MAF: read flash (location in RAM); SAF: completion with data
 *  0b10..Master: from host 32 (host writes w/32-bit address); MAF: write flash (location in RAM); SAF: completion with no data
 *  0b11..Master: from host 64 (host writes w/64-bit address); MAF: erase flash (sector in RAM)
 */
#define ESPI_OMFLEN_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_OMFLEN_TRANS_SHIFT)) & ESPI_OMFLEN_TRANS_MASK)
/*! @} */

/* The count of ESPI_OMFLEN */
#define ESPI_OMFLEN_COUNT                        (5U)

/*! @name DATAIN - Port Data Input */
/*! @{ */

#define ESPI_DATAIN_DATA_LEN_MASK                (0xFFU)
#define ESPI_DATAIN_DATA_LEN_SHIFT               (0U)
/*! DATA_LEN - Data Length */
#define ESPI_DATAIN_DATA_LEN(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_DATAIN_DATA_LEN_SHIFT)) & ESPI_DATAIN_DATA_LEN_MASK)

#define ESPI_DATAIN_DIR_MASK                     (0x100U)
#define ESPI_DATAIN_DIR_SHIFT                    (8U)
/*! DIR - Direction of last access
 *  0b0..Read by host
 *  0b1..Write by host
 */
#define ESPI_DATAIN_DIR(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_DATAIN_DIR_SHIFT)) & ESPI_DATAIN_DIR_MASK)

#define ESPI_DATAIN_IDX_MASK                     (0x3FF0000U)
#define ESPI_DATAIN_IDX_SHIFT                    (16U)
/*! IDX - Index of Last Access */
#define ESPI_DATAIN_IDX(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_DATAIN_IDX_SHIFT)) & ESPI_DATAIN_IDX_MASK)
/*! @} */

/* The count of ESPI_DATAIN */
#define ESPI_DATAIN_COUNT                        (5U)

/*! @name DATAOUT - Port Data Out */
/*! @{ */

#define ESPI_DATAOUT_DATA_MASK                   (0xFFU)
#define ESPI_DATAOUT_DATA_SHIFT                  (0U)
/*! DATA - Data to Send to Host */
#define ESPI_DATAOUT_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_DATAOUT_DATA_SHIFT)) & ESPI_DATAOUT_DATA_MASK)
/*! @} */

/* The count of ESPI_DATAOUT */
#define ESPI_DATAOUT_COUNT                       (5U)

/*! @name RAMUSE - Port RAM Use */
/*! @{ */

#define ESPI_RAMUSE_OFF_MASK                     (0xFFFU)
#define ESPI_RAMUSE_OFF_SHIFT                    (0U)
/*! OFF - Offset into RAM */
#define ESPI_RAMUSE_OFF(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_RAMUSE_OFF_SHIFT)) & ESPI_RAMUSE_OFF_MASK)

#define ESPI_RAMUSE_LEN_MASK                     (0x70000U)
#define ESPI_RAMUSE_LEN_SHIFT                    (16U)
/*! LEN - Length */
#define ESPI_RAMUSE_LEN(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_RAMUSE_LEN_SHIFT)) & ESPI_RAMUSE_LEN_MASK)
/*! @} */

/* The count of ESPI_RAMUSE */
#define ESPI_RAMUSE_COUNT                        (5U)


/*!
 * @}
 */ /* end of group ESPI_Register_Masks */


/*!
 * @}
 */ /* end of group ESPI_Peripheral_Access_Layer */


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


#endif  /* PERI_ESPI_H_ */

