/*
** ###################################################################
**     Processors:          MCXA286VAPR
**                          MCXA286VASR
**                          MCXA286VLL
**                          MCXA286VLQ
**                          MCXA286VPN
**                          MCXA287VAPR
**                          MCXA287VASR
**                          MCXA287VLL
**                          MCXA287VLQ
**                          MCXA287VPN
**                          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
**                          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA566VLL
**                          MCXA566VLQ
**                          MCXA566VPN
**                          MCXA567VLL
**                          MCXA567VLQ
**                          MCXA567VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON
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
 * @file PERI_SYSCON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCON
 *
 * CMSIS Peripheral Access Layer for SYSCON
 */

#if !defined(PERI_SYSCON_H_)
#define PERI_SYSCON_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
#elif (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA566VLL) || defined(CPU_MCXA566VLQ) || defined(CPU_MCXA566VPN))
#include "MCXA566_COMMON.h"
#elif (defined(CPU_MCXA567VLL) || defined(CPU_MCXA567VLQ) || defined(CPU_MCXA567VPN))
#include "MCXA567_COMMON.h"
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
   -- SYSCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Peripheral_Access_Layer SYSCON Peripheral Access Layer
 * @{
 */

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t REMAP;                             /**< AHB Matrix Remap Control, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t AHBMATPRIO;                        /**< AHB Matrix Priority Control, offset: 0x10 */
       uint8_t RESERVED_1[52];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x48 */
  __IO uint32_t PROTLVL;                           /**< Protect Level Control, offset: 0x4C */
       uint8_t RESERVED_2[4];
  __IO uint32_t CPU0NSTCKCAL;                      /**< Non-Secure CPU0 System Tick Calibration, offset: 0x54 */
       uint8_t RESERVED_3[40];
  __IO uint32_t AHBCLKDIV;                         /**< System Clock Divider, offset: 0x80 */
  __IO uint32_t BUSCLKDIV;                         /**< BUS_CLK Clock Divider, offset: 0x84 */
  __IO uint32_t SLOWCLKDIV;                        /**< SLOW_CLK Clock Divider, offset: 0x88 */
       uint8_t RESERVED_4[4];
  __IO uint32_t FROHFDIV;                          /**< FRO_HF_DIV Clock Divider, offset: 0x90 */
  __IO uint32_t FROLFDIV;                          /**< FRO_LF_DIV Clock Divider, offset: 0x94 */
       uint8_t RESERVED_5[76];
  __IO uint32_t PLL1CLKDIV;                        /**< PLL1_CLK_DIV Clock Divider, offset: 0xE4 */
       uint8_t RESERVED_6[20];
  __IO uint32_t CLKUNLOCK;                         /**< Clock Configuration Unlock, offset: 0xFC */
       uint8_t RESERVED_7[96];
  __IO uint32_t GRAY_CODE_LSB;                     /**< Gray to Binary Converter Gray Code [31:0], offset: 0x160 */
  __IO uint32_t GRAY_CODE_MSB;                     /**< Gray to Binary Converter Gray Code [41:32], offset: 0x164 */
  __I  uint32_t BINARY_CODE_LSB;                   /**< Gray to Binary Converter Binary Code [31:0], offset: 0x168 */
  __I  uint32_t BINARY_CODE_MSB;                   /**< Gray to Binary Converter Binary Code [41:32], offset: 0x16C */
       uint8_t RESERVED_8[80];
  __IO uint32_t ENET_CTRL;                         /**< Ethernet Control, offset: 0x1C0 */
  __IO uint32_t ENET_SBD_FLOW_CTRL;                /**< Sideband Flow Control, offset: 0x1C4 */
       uint8_t RESERVED_9[56];
  __IO uint32_t NVM_CTRL;                          /**< NVM Control, offset: 0x200 */
       uint8_t RESERVED_10[16];
  __IO uint32_t SMARTDMAINT;                       /**< SmartDMA Interrupt Hijack, offset: 0x214 */
       uint8_t RESERVED_11[36];
  __I  uint32_t BOOTROM;                           /**< Immediate cessation of execution following the completion of ROM execution, offset: 0x23C */
       uint8_t RESERVED_12[48];
  __IO uint32_t RAM_CASP_CTRL;                     /**< Controls Shared RAM Integration, offset: 0x270 */
       uint8_t RESERVED_13[152];
  __I  uint32_t CPUSTAT;                           /**< CPU Status, offset: 0x30C */
       uint8_t RESERVED_14[20];
  __IO uint32_t LPCAC_CTRL;                        /**< LPCAC Control, offset: 0x324 */
  __IO uint32_t I3C_MISC_CTRL;                     /**< I3C Misc Control, offset: 0x328 */
       uint8_t RESERVED_15[276];
  __IO uint32_t CTIMERGLOBALSTARTEN;               /**< CTIMER Global Start Enable, offset: 0x440 */
  __IO uint32_t RAM_CTRL;                          /**< RAM Control, offset: 0x444 */
       uint8_t RESERVED_16[936];
  __I  uint32_t JTAG_ID;                           /**< JTAG Chip ID, offset: 0x7F0 */
  __I  uint32_t DEVICE_TYPE;                       /**< Device Type, offset: 0x7F4 */
  __I  uint32_t DEVICE_ID0;                        /**< Device ID, offset: 0x7F8 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name REMAP - AHB Matrix Remap Control */
/*! @{ */

#define SYSCON_REMAP_CPU0_SBUS_MASK              (0xCU)
#define SYSCON_REMAP_CPU0_SBUS_SHIFT             (2U)
/*! CPU0_SBUS - RAMX0 address remap for CPU System bus
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: alias space is enabled. It's linear address space from bottom of system ram. The start address is
 *        0x20000000 + (system ram size - RAMX size)*1024.
 */
#define SYSCON_REMAP_CPU0_SBUS(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_CPU0_SBUS_SHIFT)) & SYSCON_REMAP_CPU0_SBUS_MASK)

#define SYSCON_REMAP_SMARTDMA_I_MASK             (0x30U)
#define SYSCON_REMAP_SMARTDMA_I_SHIFT            (4U)
/*! SmartDMA_I - RAMX0 address remap for SmartDMA I-BUS
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_SMARTDMA_I(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_SMARTDMA_I_SHIFT)) & SYSCON_REMAP_SMARTDMA_I_MASK)

#define SYSCON_REMAP_SMARTDMA_D_MASK             (0xC0U)
#define SYSCON_REMAP_SMARTDMA_D_SHIFT            (6U)
/*! SmartDMA_D - RAMX0 address remap for SmartDMA D-BUS
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_SMARTDMA_D(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_SMARTDMA_D_SHIFT)) & SYSCON_REMAP_SMARTDMA_D_MASK)

#define SYSCON_REMAP_DMA0_MASK                   (0x300U)
#define SYSCON_REMAP_DMA0_SHIFT                  (8U)
/*! DMA0 - RAMX0 address remap for DMA0
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_DMA0(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_DMA0_SHIFT)) & SYSCON_REMAP_DMA0_MASK)

#define SYSCON_REMAP_DMA1_MASK                   (0xC00U)
#define SYSCON_REMAP_DMA1_SHIFT                  (10U)
/*! DMA1 - RAMX0 address remap for DMA1
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_DMA1(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_DMA1_SHIFT)) & SYSCON_REMAP_DMA1_MASK)

#define SYSCON_REMAP_PKC_ELS_MASK                (0x3000U)
#define SYSCON_REMAP_PKC_ELS_SHIFT               (12U)
/*! PKC_ELS - RAMX0 address remap for PKC_ELS
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_PKC_ELS(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_PKC_ELS_SHIFT)) & SYSCON_REMAP_PKC_ELS_MASK)

#define SYSCON_REMAP_COOLFLUX_Y_ESPI_MASK        (0x300000U)
#define SYSCON_REMAP_COOLFLUX_Y_ESPI_SHIFT       (20U)
/*! COOLFLUX_Y_ESPI - RAMX0 address remap for ESPI
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_COOLFLUX_Y_ESPI(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_COOLFLUX_Y_ESPI_SHIFT)) & SYSCON_REMAP_COOLFLUX_Y_ESPI_MASK)

#define SYSCON_REMAP_USB_FS_ENET_MASK            (0x3000000U)
#define SYSCON_REMAP_USB_FS_ENET_SHIFT           (24U)
/*! USB_FS_ENET - RAMX0 address remap for ENET
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_USB_FS_ENET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_USB_FS_ENET_SHIFT)) & SYSCON_REMAP_USB_FS_ENET_MASK)

#define SYSCON_REMAP_USB_HS_MASK                 (0xC000000U)
#define SYSCON_REMAP_USB_HS_SHIFT                (26U)
/*! USB_HS - RAMX0 address remap for USB-HS
 *  0b00..RAMX0: alias space is disabled.
 *  0b01..RAMX0: same alias space as CPU0_SBUS
 */
#define SYSCON_REMAP_USB_HS(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_USB_HS_SHIFT)) & SYSCON_REMAP_USB_HS_MASK)

#define SYSCON_REMAP_LOCK_MASK                   (0x80000000U)
#define SYSCON_REMAP_LOCK_SHIFT                  (31U)
/*! LOCK - This 1-bit field provides a mechanism to limit writes to this register to protect its
 *    contents. Once set, this bit remains asserted until a system reset.
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered until a system reset.
 */
#define SYSCON_REMAP_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_LOCK_SHIFT)) & SYSCON_REMAP_LOCK_MASK)
/*! @} */

/*! @name AHBMATPRIO - AHB Matrix Priority Control */
/*! @{ */

#define SYSCON_AHBMATPRIO_CPU0_CBUS_MASK         (0x3U)
#define SYSCON_AHBMATPRIO_CPU0_CBUS_SHIFT        (0U)
/*! CPU0_CBUS - CPU0 C-AHB bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_CPU0_CBUS(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_CPU0_CBUS_SHIFT)) & SYSCON_AHBMATPRIO_CPU0_CBUS_MASK)

#define SYSCON_AHBMATPRIO_CPU0_SBUS_MASK         (0xCU)
#define SYSCON_AHBMATPRIO_CPU0_SBUS_SHIFT        (2U)
/*! CPU0_SBUS - CPU0 S-AHB bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_CPU0_SBUS(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_CPU0_SBUS_SHIFT)) & SYSCON_AHBMATPRIO_CPU0_SBUS_MASK)

#define SYSCON_AHBMATPRIO_CPU1_CBUS_SMARTDMA_I_MASK (0x30U)
#define SYSCON_AHBMATPRIO_CPU1_CBUS_SMARTDMA_I_SHIFT (4U)
/*! CPU1_CBUS_SmartDMA_I - SmartDMA-I bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_CPU1_CBUS_SMARTDMA_I(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_CPU1_CBUS_SMARTDMA_I_SHIFT)) & SYSCON_AHBMATPRIO_CPU1_CBUS_SMARTDMA_I_MASK)

#define SYSCON_AHBMATPRIO_CPU1_SBUS_SMARTDMA_D_MASK (0xC0U)
#define SYSCON_AHBMATPRIO_CPU1_SBUS_SMARTDMA_D_SHIFT (6U)
/*! CPU1_SBUS_SmartDMA_D - SmartDMA-D bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_CPU1_SBUS_SMARTDMA_D(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_CPU1_SBUS_SMARTDMA_D_SHIFT)) & SYSCON_AHBMATPRIO_CPU1_SBUS_SMARTDMA_D_MASK)

#define SYSCON_AHBMATPRIO_DMA0_MASK              (0x300U)
#define SYSCON_AHBMATPRIO_DMA0_SHIFT             (8U)
/*! DMA0 - DMA0 controller bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_DMA0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_DMA0_SHIFT)) & SYSCON_AHBMATPRIO_DMA0_MASK)

#define SYSCON_AHBMATPRIO_DMA1_MASK              (0xC00U)
#define SYSCON_AHBMATPRIO_DMA1_SHIFT             (10U)
/*! DMA1 - DMA1 controller bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_DMA1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_DMA1_SHIFT)) & SYSCON_AHBMATPRIO_DMA1_MASK)

#define SYSCON_AHBMATPRIO_PKC_ELS_MASK           (0x3000U)
#define SYSCON_AHBMATPRIO_PKC_ELS_SHIFT          (12U)
/*! PKC_ELS - PKC and ELS bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PKC_ELS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PKC_ELS_SHIFT)) & SYSCON_AHBMATPRIO_PKC_ELS_MASK)

#define SYSCON_AHBMATPRIO_COOLFLUX_Y_ESPI_MASK   (0x300000U)
#define SYSCON_AHBMATPRIO_COOLFLUX_Y_ESPI_SHIFT  (20U)
/*! COOLFLUX_Y_ESPI - ESPI bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_COOLFLUX_Y_ESPI(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_COOLFLUX_Y_ESPI_SHIFT)) & SYSCON_AHBMATPRIO_COOLFLUX_Y_ESPI_MASK)

#define SYSCON_AHBMATPRIO_USB_FS_ENET_MASK       (0x3000000U)
#define SYSCON_AHBMATPRIO_USB_FS_ENET_SHIFT      (24U)
/*! USB_FS_ENET - ENET bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_USB_FS_ENET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_USB_FS_ENET_SHIFT)) & SYSCON_AHBMATPRIO_USB_FS_ENET_MASK)

#define SYSCON_AHBMATPRIO_USB_HS_MASK            (0xC000000U)
#define SYSCON_AHBMATPRIO_USB_HS_SHIFT           (26U)
/*! USB_HS - USB-HS bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_USB_HS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_USB_HS_SHIFT)) & SYSCON_AHBMATPRIO_USB_HS_MASK)
/*! @} */

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON_NMISRC_IRQCPU0_MASK               (0xFFU)
#define SYSCON_NMISRC_IRQCPU0_SHIFT              (0U)
/*! IRQCPU0 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for CPU0, if enabled by NMIENCPU0. */
#define SYSCON_NMISRC_IRQCPU0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQCPU0_SHIFT)) & SYSCON_NMISRC_IRQCPU0_MASK)

#define SYSCON_NMISRC_NMIENCPU0_MASK             (0x80000000U)
#define SYSCON_NMISRC_NMIENCPU0_SHIFT            (31U)
/*! NMIENCPU0 - Enables the Non-Maskable Interrupt (NMI) source selected by IRQCPU0.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_NMISRC_NMIENCPU0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENCPU0_SHIFT)) & SYSCON_NMISRC_NMIENCPU0_MASK)
/*! @} */

/*! @name PROTLVL - Protect Level Control */
/*! @{ */

#define SYSCON_PROTLVL_PRIV_MASK                 (0x1U)
#define SYSCON_PROTLVL_PRIV_SHIFT                (0U)
/*! PRIV - Control privileged access of EIM, ERM, Flexcan, MBC, SCG, DMA, ROMCP and Flexspi.
 *  0b0..privileged access is disabled. the peripherals could be access in user mode.
 *  0b1..privileged access is enabled. the peripherals could be access in privilege mode.
 */
#define SYSCON_PROTLVL_PRIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_PROTLVL_PRIV_SHIFT)) & SYSCON_PROTLVL_PRIV_MASK)

#define SYSCON_PROTLVL_LOCKNSMPU_MASK            (0x10000U)
#define SYSCON_PROTLVL_LOCKNSMPU_SHIFT           (16U)
/*! LOCKNSMPU - Control write access to Nonsecure MPU memory regions.
 *  0b0..Unlock these registers. privileged access to Nonsecure MPU memory regions is allowed.
 *  0b1..Disable writes to the MPU_CTRL_NS, MPU_RNR_NS, MPU_RBAR_NS, MPU_RLAR_NS, MPU_RBAR_A_NSn and
 *       MPU_RLAR_A_NSn. All writes to the registers are ignored.
 */
#define SYSCON_PROTLVL_LOCKNSMPU(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PROTLVL_LOCKNSMPU_SHIFT)) & SYSCON_PROTLVL_LOCKNSMPU_MASK)

#define SYSCON_PROTLVL_LOCK_MASK                 (0x80000000U)
#define SYSCON_PROTLVL_LOCK_SHIFT                (31U)
/*! LOCK - This 1-bit field provides a mechanism to limit writes to this register to protect its
 *    contents. Once set, this bit remains asserted until a system reset.
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered until a system reset.
 */
#define SYSCON_PROTLVL_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_PROTLVL_LOCK_SHIFT)) & SYSCON_PROTLVL_LOCK_MASK)
/*! @} */

/*! @name CPU0NSTCKCAL - Non-Secure CPU0 System Tick Calibration */
/*! @{ */

#define SYSCON_CPU0NSTCKCAL_TENMS_MASK           (0xFFFFFFU)
#define SYSCON_CPU0NSTCKCAL_TENMS_SHIFT          (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SYSCON_CPU0NSTCKCAL_TENMS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_TENMS_SHIFT)) & SYSCON_CPU0NSTCKCAL_TENMS_MASK)

#define SYSCON_CPU0NSTCKCAL_SKEW_MASK            (0x1000000U)
#define SYSCON_CPU0NSTCKCAL_SKEW_SHIFT           (24U)
/*! SKEW - Indicates whether the TENMS value is exact.
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is not exact or not given
 */
#define SYSCON_CPU0NSTCKCAL_SKEW(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_SKEW_SHIFT)) & SYSCON_CPU0NSTCKCAL_SKEW_MASK)

#define SYSCON_CPU0NSTCKCAL_NOREF_MASK           (0x2000000U)
#define SYSCON_CPU0NSTCKCAL_NOREF_SHIFT          (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor.
 *  0b0..Reference clock is provided
 *  0b1..No reference clock is provided
 */
#define SYSCON_CPU0NSTCKCAL_NOREF(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_NOREF_SHIFT)) & SYSCON_CPU0NSTCKCAL_NOREF_MASK)
/*! @} */

/*! @name AHBCLKDIV - System Clock Divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)

#define SYSCON_AHBCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_AHBCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_AHBCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_UNSTAB_SHIFT)) & SYSCON_AHBCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name BUSCLKDIV - BUS_CLK Clock Divider */
/*! @{ */

#define SYSCON_BUSCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_BUSCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value */
#define SYSCON_BUSCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_BUSCLKDIV_DIV_SHIFT)) & SYSCON_BUSCLKDIV_DIV_MASK)

#define SYSCON_BUSCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_BUSCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_BUSCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_BUSCLKDIV_RESET_SHIFT)) & SYSCON_BUSCLKDIV_RESET_MASK)

#define SYSCON_BUSCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_BUSCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_BUSCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_BUSCLKDIV_HALT_SHIFT)) & SYSCON_BUSCLKDIV_HALT_MASK)

#define SYSCON_BUSCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_BUSCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_BUSCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_BUSCLKDIV_UNSTAB_SHIFT)) & SYSCON_BUSCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name SLOWCLKDIV - SLOW_CLK Clock Divider */
/*! @{ */

#define SYSCON_SLOWCLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_SLOWCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_SLOWCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_DIV_SHIFT)) & SYSCON_SLOWCLKDIV_DIV_MASK)

#define SYSCON_SLOWCLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_SLOWCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_SLOWCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_RESET_SHIFT)) & SYSCON_SLOWCLKDIV_RESET_MASK)

#define SYSCON_SLOWCLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_SLOWCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_SLOWCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_HALT_SHIFT)) & SYSCON_SLOWCLKDIV_HALT_MASK)

#define SYSCON_SLOWCLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_SLOWCLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_SLOWCLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_UNSTAB_SHIFT)) & SYSCON_SLOWCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name FROHFDIV - FRO_HF_DIV Clock Divider */
/*! @{ */

#define SYSCON_FROHFDIV_DIV_MASK                 (0xFFU)
#define SYSCON_FROHFDIV_DIV_SHIFT                (0U)
/*! DIV - Clock divider value */
#define SYSCON_FROHFDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_DIV_SHIFT)) & SYSCON_FROHFDIV_DIV_MASK)

#define SYSCON_FROHFDIV_RESET_MASK               (0x20000000U)
#define SYSCON_FROHFDIV_RESET_SHIFT              (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FROHFDIV_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_RESET_SHIFT)) & SYSCON_FROHFDIV_RESET_MASK)

#define SYSCON_FROHFDIV_HALT_MASK                (0x40000000U)
#define SYSCON_FROHFDIV_HALT_SHIFT               (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FROHFDIV_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_HALT_SHIFT)) & SYSCON_FROHFDIV_HALT_MASK)

#define SYSCON_FROHFDIV_UNSTAB_MASK              (0x80000000U)
#define SYSCON_FROHFDIV_UNSTAB_SHIFT             (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FROHFDIV_UNSTAB(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_UNSTAB_SHIFT)) & SYSCON_FROHFDIV_UNSTAB_MASK)
/*! @} */

/*! @name FROLFDIV - FRO_LF_DIV Clock Divider */
/*! @{ */

#define SYSCON_FROLFDIV_DIV_MASK                 (0xFFU)
#define SYSCON_FROLFDIV_DIV_SHIFT                (0U)
/*! DIV - Clock divider value */
#define SYSCON_FROLFDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_DIV_SHIFT)) & SYSCON_FROLFDIV_DIV_MASK)

#define SYSCON_FROLFDIV_RESET_MASK               (0x20000000U)
#define SYSCON_FROLFDIV_RESET_SHIFT              (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FROLFDIV_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_RESET_SHIFT)) & SYSCON_FROLFDIV_RESET_MASK)

#define SYSCON_FROLFDIV_HALT_MASK                (0x40000000U)
#define SYSCON_FROLFDIV_HALT_SHIFT               (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FROLFDIV_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_HALT_SHIFT)) & SYSCON_FROLFDIV_HALT_MASK)

#define SYSCON_FROLFDIV_UNSTAB_MASK              (0x80000000U)
#define SYSCON_FROLFDIV_UNSTAB_SHIFT             (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FROLFDIV_UNSTAB(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_UNSTAB_SHIFT)) & SYSCON_FROLFDIV_UNSTAB_MASK)
/*! @} */

/*! @name PLL1CLKDIV - PLL1_CLK_DIV Clock Divider */
/*! @{ */

#define SYSCON_PLL1CLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_PLL1CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_PLL1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLKDIV_DIV_SHIFT)) & SYSCON_PLL1CLKDIV_DIV_MASK)

#define SYSCON_PLL1CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_PLL1CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_PLL1CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLKDIV_RESET_SHIFT)) & SYSCON_PLL1CLKDIV_RESET_MASK)

#define SYSCON_PLL1CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_PLL1CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_PLL1CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLKDIV_HALT_SHIFT)) & SYSCON_PLL1CLKDIV_HALT_MASK)

#define SYSCON_PLL1CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_PLL1CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_PLL1CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLKDIV_UNSTAB_SHIFT)) & SYSCON_PLL1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CLKUNLOCK - Clock Configuration Unlock */
/*! @{ */

#define SYSCON_CLKUNLOCK_UNLOCK_MASK             (0x1U)
#define SYSCON_CLKUNLOCK_UNLOCK_SHIFT            (0U)
/*! UNLOCK - Controls clock configuration registers access (for example, SLOWCLKDIV, BUSCLKDIV,
 *    AHBCLKDIV, FROHFDIV, FROLFDIV, PLLxCLKDIV, MRCC_xxx_CLKDIV, MRCC_xxx_CLKSEL, MRCC_GLB_xxx)
 *  0b0..Updates are allowed to all clock configuration registers
 *  0b1..Freezes all clock configuration registers update.
 */
#define SYSCON_CLKUNLOCK_UNLOCK(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKUNLOCK_UNLOCK_SHIFT)) & SYSCON_CLKUNLOCK_UNLOCK_MASK)
/*! @} */

/*! @name GRAY_CODE_LSB - Gray to Binary Converter Gray Code [31:0] */
/*! @{ */

#define SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK (0xFFFFFFFFU)
#define SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT (0U)
/*! code_gray_31_0 - Gray code [31:0] */
#define SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT)) & SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK)
/*! @} */

/*! @name GRAY_CODE_MSB - Gray to Binary Converter Gray Code [41:32] */
/*! @{ */

#define SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_MASK (0x3FFU)
#define SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_SHIFT (0U)
/*! code_gray_41_32 - Gray code [41:32] */
#define SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_SHIFT)) & SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_MASK)
/*! @} */

/*! @name BINARY_CODE_LSB - Gray to Binary Converter Binary Code [31:0] */
/*! @{ */

#define SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_MASK (0xFFFFFFFFU)
#define SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT (0U)
/*! code_bin_31_0 - Binary code [31:0] */
#define SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT)) & SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_MASK)
/*! @} */

/*! @name BINARY_CODE_MSB - Gray to Binary Converter Binary Code [41:32] */
/*! @{ */

#define SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_MASK (0x3FFU)
#define SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_SHIFT (0U)
/*! code_bin_41_32 - Binary code [41:32] */
#define SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_SHIFT)) & SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_MASK)
/*! @} */

/*! @name ENET_CTRL - Ethernet Control */
/*! @{ */

#define SYSCON_ENET_CTRL_PHY_INTF_MASK           (0x4U)
#define SYSCON_ENET_CTRL_PHY_INTF_SHIFT          (2U)
/*! PHY_INTF - Selects external PHY interface
 *  0b0..Selects MII PHY Interface
 *  0b1..Selects RMII PHY Interface
 */
#define SYSCON_ENET_CTRL_PHY_INTF(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_ENET_CTRL_PHY_INTF_SHIFT)) & SYSCON_ENET_CTRL_PHY_INTF_MASK)

#define SYSCON_ENET_CTRL_PHY_SEL_MASK            (0x8U)
#define SYSCON_ENET_CTRL_PHY_SEL_SHIFT           (3U)
/*! PHY_SEL - Selects external PHY or on-chip 10BASE-T1S
 *  0b0..Selects external PHY
 *  0b1..Selects on-chip 10BASE-T1S
 */
#define SYSCON_ENET_CTRL_PHY_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ENET_CTRL_PHY_SEL_SHIFT)) & SYSCON_ENET_CTRL_PHY_SEL_MASK)
/*! @} */

/*! @name ENET_SBD_FLOW_CTRL - Sideband Flow Control */
/*! @{ */

#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_CH0_MASK   (0x1U)
#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_CH0_SHIFT  (0U)
/*! SEL_ch0 - Sideband Flow Control for channel0
 *  0b0..No trigger flow control
 *  0b1..Trigger flow control
 */
#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ENET_SBD_FLOW_CTRL_SEL_CH0_SHIFT)) & SYSCON_ENET_SBD_FLOW_CTRL_SEL_CH0_MASK)
/*! @} */

/*! @name NVM_CTRL - NVM Control */
/*! @{ */

#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC_MASK      (0x1U)
#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC_SHIFT     (0U)
/*! DIS_FLASH_SPEC - Flash speculation control
 *  0b0..Enables flash speculation
 *  0b1..Disables flash speculation
 */
#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_FLASH_SPEC_SHIFT)) & SYSCON_NVM_CTRL_DIS_FLASH_SPEC_MASK)

#define SYSCON_NVM_CTRL_DIS_DATA_SPEC_MASK       (0x2U)
#define SYSCON_NVM_CTRL_DIS_DATA_SPEC_SHIFT      (1U)
/*! DIS_DATA_SPEC - Flash data speculation control
 *  0b0..Enables data speculation
 *  0b1..Disables data speculation
 */
#define SYSCON_NVM_CTRL_DIS_DATA_SPEC(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_DATA_SPEC_SHIFT)) & SYSCON_NVM_CTRL_DIS_DATA_SPEC_MASK)

#define SYSCON_NVM_CTRL_FLASH_STALL_EN_MASK      (0x400U)
#define SYSCON_NVM_CTRL_FLASH_STALL_EN_SHIFT     (10U)
/*! FLASH_STALL_EN - FLASH stall on busy control
 *  0b0..No stall on FLASH busy
 *  0b1..Stall on FLASH busy
 */
#define SYSCON_NVM_CTRL_FLASH_STALL_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_FLASH_STALL_EN_SHIFT)) & SYSCON_NVM_CTRL_FLASH_STALL_EN_MASK)

#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_MASK  (0x10000U)
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_SHIFT (16U)
/*! DIS_MBECC_ERR_INST
 *  0b0..Enables bus error on multi-bit ECC error for instruction
 *  0b1..Disables bus error on multi-bit ECC error for instruction
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_MASK)

#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK  (0x20000U)
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT (17U)
/*! DIS_MBECC_ERR_DATA
 *  0b0..Enables bus error on multi-bit ECC error for data
 *  0b1..Disables bus error on multi-bit ECC error for data
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK)
/*! @} */

/*! @name SMARTDMAINT - SmartDMA Interrupt Hijack */
/*! @{ */

#define SYSCON_SMARTDMAINT_INT0_MASK             (0x1U)
#define SYSCON_SMARTDMAINT_INT0_SHIFT            (0U)
/*! INT0 - SmartDMA hijack NVIC IRQ2
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT0_SHIFT)) & SYSCON_SMARTDMAINT_INT0_MASK)

#define SYSCON_SMARTDMAINT_INT1_MASK             (0x2U)
#define SYSCON_SMARTDMAINT_INT1_SHIFT            (1U)
/*! INT1 - SmartDMA hijack NVIC IRQ23
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT1_SHIFT)) & SYSCON_SMARTDMAINT_INT1_MASK)

#define SYSCON_SMARTDMAINT_INT2_MASK             (0x4U)
#define SYSCON_SMARTDMAINT_INT2_SHIFT            (2U)
/*! INT2 - SmartDMA hijack NVIC IRQ26
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT2_SHIFT)) & SYSCON_SMARTDMAINT_INT2_MASK)

#define SYSCON_SMARTDMAINT_INT3_MASK             (0x8U)
#define SYSCON_SMARTDMAINT_INT3_SHIFT            (3U)
/*! INT3 - SmartDMA hijack NVIC IRQ27
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT3_SHIFT)) & SYSCON_SMARTDMAINT_INT3_MASK)

#define SYSCON_SMARTDMAINT_INT4_MASK             (0x10U)
#define SYSCON_SMARTDMAINT_INT4_SHIFT            (4U)
/*! INT4 - SmartDMA hijack NVIC IRQ28
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT4(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT4_SHIFT)) & SYSCON_SMARTDMAINT_INT4_MASK)

#define SYSCON_SMARTDMAINT_INT5_MASK             (0x20U)
#define SYSCON_SMARTDMAINT_INT5_SHIFT            (5U)
/*! INT5 - SmartDMA hijack NVIC IRQ29
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT5(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT5_SHIFT)) & SYSCON_SMARTDMAINT_INT5_MASK)

#define SYSCON_SMARTDMAINT_INT6_MASK             (0x40U)
#define SYSCON_SMARTDMAINT_INT6_SHIFT            (6U)
/*! INT6 - SmartDMA hijack NVIC IRQ31
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT6(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT6_SHIFT)) & SYSCON_SMARTDMAINT_INT6_MASK)

#define SYSCON_SMARTDMAINT_INT7_MASK             (0x80U)
#define SYSCON_SMARTDMAINT_INT7_SHIFT            (7U)
/*! INT7 - SmartDMA hijack NVIC IRQ32
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT7(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT7_SHIFT)) & SYSCON_SMARTDMAINT_INT7_MASK)

#define SYSCON_SMARTDMAINT_INT8_MASK             (0x100U)
#define SYSCON_SMARTDMAINT_INT8_SHIFT            (8U)
/*! INT8 - SmartDMA hijack NVIC IRQ33
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT8(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT8_SHIFT)) & SYSCON_SMARTDMAINT_INT8_MASK)

#define SYSCON_SMARTDMAINT_INT9_MASK             (0x200U)
#define SYSCON_SMARTDMAINT_INT9_SHIFT            (9U)
/*! INT9 - SmartDMA hijack NVIC IRQ34
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT9(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT9_SHIFT)) & SYSCON_SMARTDMAINT_INT9_MASK)

#define SYSCON_SMARTDMAINT_INT11_MASK            (0x800U)
#define SYSCON_SMARTDMAINT_INT11_SHIFT           (11U)
/*! INT11 - SmartDMA hijack NVIC IRQ39
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT11(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT11_SHIFT)) & SYSCON_SMARTDMAINT_INT11_MASK)

#define SYSCON_SMARTDMAINT_INT12_MASK            (0x1000U)
#define SYSCON_SMARTDMAINT_INT12_SHIFT           (12U)
/*! INT12 - SmartDMA hijack NVIC IRQ40
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT12(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT12_SHIFT)) & SYSCON_SMARTDMAINT_INT12_MASK)

#define SYSCON_SMARTDMAINT_INT13_MASK            (0x2000U)
#define SYSCON_SMARTDMAINT_INT13_SHIFT           (13U)
/*! INT13 - SmartDMA hijack NVIC IRQ41
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT13(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT13_SHIFT)) & SYSCON_SMARTDMAINT_INT13_MASK)

#define SYSCON_SMARTDMAINT_INT14_MASK            (0x4000U)
#define SYSCON_SMARTDMAINT_INT14_SHIFT           (14U)
/*! INT14 - SmartDMA hijack NVIC IRQ59
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT14(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT14_SHIFT)) & SYSCON_SMARTDMAINT_INT14_MASK)

#define SYSCON_SMARTDMAINT_INT15_MASK            (0x8000U)
#define SYSCON_SMARTDMAINT_INT15_SHIFT           (15U)
/*! INT15 - SmartDMA hijack NVIC IRQ62
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT15(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT15_SHIFT)) & SYSCON_SMARTDMAINT_INT15_MASK)

#define SYSCON_SMARTDMAINT_INT16_MASK            (0x10000U)
#define SYSCON_SMARTDMAINT_INT16_SHIFT           (16U)
/*! INT16 - SmartDMA hijack NVIC IRQ64
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT16(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT16_SHIFT)) & SYSCON_SMARTDMAINT_INT16_MASK)

#define SYSCON_SMARTDMAINT_INT17_MASK            (0x20000U)
#define SYSCON_SMARTDMAINT_INT17_SHIFT           (17U)
/*! INT17 - SmartDMA hijack NVIC IRQ71
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT17(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT17_SHIFT)) & SYSCON_SMARTDMAINT_INT17_MASK)

#define SYSCON_SMARTDMAINT_INT18_MASK            (0x40000U)
#define SYSCON_SMARTDMAINT_INT18_SHIFT           (18U)
/*! INT18 - SmartDMA hijack NVIC IRQ72
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT18(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT18_SHIFT)) & SYSCON_SMARTDMAINT_INT18_MASK)

#define SYSCON_SMARTDMAINT_INT19_MASK            (0x80000U)
#define SYSCON_SMARTDMAINT_INT19_SHIFT           (19U)
/*! INT19 - SmartDMA hijack NVIC IRQ73
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT19(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT19_SHIFT)) & SYSCON_SMARTDMAINT_INT19_MASK)

#define SYSCON_SMARTDMAINT_INT20_MASK            (0x100000U)
#define SYSCON_SMARTDMAINT_INT20_SHIFT           (20U)
/*! INT20 - SmartDMA hijack NVIC IRQ74
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT20(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT20_SHIFT)) & SYSCON_SMARTDMAINT_INT20_MASK)

#define SYSCON_SMARTDMAINT_INT21_MASK            (0x200000U)
#define SYSCON_SMARTDMAINT_INT21_SHIFT           (21U)
/*! INT21 - SmartDMA hijack NVIC IRQ75
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT21(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT21_SHIFT)) & SYSCON_SMARTDMAINT_INT21_MASK)

#define SYSCON_SMARTDMAINT_INT22_MASK            (0x400000U)
#define SYSCON_SMARTDMAINT_INT22_SHIFT           (22U)
/*! INT22 - SmartDMA hijack NVIC IRQ103
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT22(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT22_SHIFT)) & SYSCON_SMARTDMAINT_INT22_MASK)

#define SYSCON_SMARTDMAINT_INT23_MASK            (0x800000U)
#define SYSCON_SMARTDMAINT_INT23_SHIFT           (23U)
/*! INT23 - SmartDMA hijack NVIC IRQ104
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT23(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT23_SHIFT)) & SYSCON_SMARTDMAINT_INT23_MASK)
/*! @} */

/*! @name RAM_CASP_CTRL - Controls Shared RAM Integration */
/*! @{ */

#define SYSCON_RAM_CASP_CTRL_INTERLEAVE_MASK     (0x1U)
#define SYSCON_RAM_CASP_CTRL_INTERLEAVE_SHIFT    (0U)
/*! INTERLEAVE - Controls RAM access for RAMA1 and RAMA2
 *  0b0..RAM access is consecutive.
 *  0b1..RAM access is interleaved. This setting is need for PKC L0 memory access.
 */
#define SYSCON_RAM_CASP_CTRL_INTERLEAVE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CASP_CTRL_INTERLEAVE_SHIFT)) & SYSCON_RAM_CASP_CTRL_INTERLEAVE_MASK)

#define SYSCON_RAM_CASP_CTRL_CASP_REQ_MASK       (0x10000U)
#define SYSCON_RAM_CASP_CTRL_CASP_REQ_SHIFT      (16U)
/*! CASP_REQ - Request SmartDMA memories.
 *  0b0..Configure shared memories RAMX3 as general memories.
 *  0b1..Configure shared memories RAMX3 as SmartDMA memories.
 */
#define SYSCON_RAM_CASP_CTRL_CASP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CASP_CTRL_CASP_REQ_SHIFT)) & SYSCON_RAM_CASP_CTRL_CASP_REQ_MASK)
/*! @} */

/*! @name CPUSTAT - CPU Status */
/*! @{ */

#define SYSCON_CPUSTAT_CPU0SLEEPING_MASK         (0x1U)
#define SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT        (0U)
/*! CPU0SLEEPING - CPU0 sleeping state
 *  0b0..CPU is not sleeping
 *  0b1..CPU is sleeping
 */
#define SYSCON_CPUSTAT_CPU0SLEEPING(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT)) & SYSCON_CPUSTAT_CPU0SLEEPING_MASK)

#define SYSCON_CPUSTAT_CPU0LOCKUP_MASK           (0x4U)
#define SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT          (2U)
/*! CPU0LOCKUP - CPU0 lockup state
 *  0b0..CPU is not in lockup
 *  0b1..CPU is in lockup
 */
#define SYSCON_CPUSTAT_CPU0LOCKUP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT)) & SYSCON_CPUSTAT_CPU0LOCKUP_MASK)
/*! @} */

/*! @name LPCAC_CTRL - LPCAC Control */
/*! @{ */

#define SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK         (0x1U)
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT        (0U)
/*! DIS_LPCAC - Disables/enables the cache function.
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define SYSCON_LPCAC_CTRL_DIS_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK         (0x2U)
#define SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT        (1U)
/*! CLR_LPCAC - Clears the cache function.
 *  0b0..Unclears the cache
 *  0b1..Clears the cache
 */
#define SYSCON_LPCAC_CTRL_CLR_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK      (0x4U)
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT     (2U)
/*! FRC_NO_ALLOC - Forces no allocation.
 *  0b0..Forces allocation
 *  0b1..Forces no allocation
 */
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT)) & SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK)

#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_MASK    (0x10U)
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_SHIFT   (4U)
/*! DIS_LPCAC_WTBF - Disable LPCAC Write Through Buffer.
 *  0b0..Enables write through buffer
 *  0b1..Disables write through buffer
 */
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_SHIFT)) & SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_MASK)

#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_MASK    (0x20U)
#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_SHIFT   (5U)
/*! LIM_LPCAC_WTBF - Limit LPCAC Write Through Buffer.
 *  0b0..Write buffer enabled when transaction is bufferable.
 *  0b1..Write buffer enabled when transaction is cacheable and bufferable
 */
#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_SHIFT)) & SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_MASK)

#define SYSCON_LPCAC_CTRL_LPCAC_XOM_MASK         (0x80U)
#define SYSCON_LPCAC_CTRL_LPCAC_XOM_SHIFT        (7U)
/*! LPCAC_XOM - LPCAC XOM(eXecute-Only-Memory) attribute control
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define SYSCON_LPCAC_CTRL_LPCAC_XOM(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_LPCAC_XOM_SHIFT)) & SYSCON_LPCAC_CTRL_LPCAC_XOM_MASK)
/*! @} */

/*! @name I3C_MISC_CTRL - I3C Misc Control */
/*! @{ */

#define SYSCON_I3C_MISC_CTRL_I3C0_SCL_FILT_MASK  (0xFU)
#define SYSCON_I3C_MISC_CTRL_I3C0_SCL_FILT_SHIFT (0U)
/*! I3C0_SCL_FILT - Disables/enables the I3C0 filter function on SCL pin.
 *  0b0000..Enable Spike filter on SCL input when clear both I3C0's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SCL line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C0's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C0_SCL_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C0_SCL_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C0_SCL_FILT_MASK)

#define SYSCON_I3C_MISC_CTRL_I3C0_SDA_FILT_MASK  (0xF0U)
#define SYSCON_I3C_MISC_CTRL_I3C0_SDA_FILT_SHIFT (4U)
/*! I3C0_SDA_FILT - Disables/enables the I3C0 filter function on SDA pin.
 *  0b0000..Enable Spike filter on SDA input when clear both I3C0's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SDA line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C0's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C0_SDA_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C0_SDA_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C0_SDA_FILT_MASK)

#define SYSCON_I3C_MISC_CTRL_I3C1_SCL_FILT_MASK  (0xF00U)
#define SYSCON_I3C_MISC_CTRL_I3C1_SCL_FILT_SHIFT (8U)
/*! I3C1_SCL_FILT - Disables/enables the I3C1 filter I3C1 function on SCL pin.
 *  0b0000..Enable Spike filter on SCL input when clear both I3C1's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SCL line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C1's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C1_SCL_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C1_SCL_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C1_SCL_FILT_MASK)

#define SYSCON_I3C_MISC_CTRL_I3C1_SDA_FILT_MASK  (0xF000U)
#define SYSCON_I3C_MISC_CTRL_I3C1_SDA_FILT_SHIFT (12U)
/*! I3C1_SDA_FILT - Disables/enables the I3C1 filter function on SDA pin.
 *  0b0000..Enable Spike filter on SDA input when clear both I3C1's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SDA line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C1's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C1_SDA_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C1_SDA_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C1_SDA_FILT_MASK)

#define SYSCON_I3C_MISC_CTRL_I3C2_SCL_FILT_MASK  (0xF0000U)
#define SYSCON_I3C_MISC_CTRL_I3C2_SCL_FILT_SHIFT (16U)
/*! I3C2_SCL_FILT - Disables/enables the I3C2 filter function on SCL pin.
 *  0b0000..Enable Spike filter on SCL input when clear both I3C2's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SCL line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C2's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C2_SCL_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C2_SCL_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C2_SCL_FILT_MASK)

#define SYSCON_I3C_MISC_CTRL_I3C2_SDA_FILT_MASK  (0xF00000U)
#define SYSCON_I3C_MISC_CTRL_I3C2_SDA_FILT_SHIFT (20U)
/*! I3C2_SDA_FILT - Disables/enables the I3C2 filter function on SDA pin.
 *  0b0000..Enable Spike filter on SDA input when clear both I3C2's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SDA line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C2's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C2_SDA_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C2_SDA_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C2_SDA_FILT_MASK)

#define SYSCON_I3C_MISC_CTRL_I3C3_SCL_FILT_MASK  (0xF000000U)
#define SYSCON_I3C_MISC_CTRL_I3C3_SCL_FILT_SHIFT (24U)
/*! I3C3_SCL_FILT - Disables/enables the I3C3 filter function on SCL pin.
 *  0b0000..Enable Spike filter on SCL input when clear both I3C3's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SCL line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C3's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C3_SCL_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C3_SCL_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C3_SCL_FILT_MASK)

#define SYSCON_I3C_MISC_CTRL_I3C3_SDA_FILT_MASK  (0xF0000000U)
#define SYSCON_I3C_MISC_CTRL_I3C3_SDA_FILT_SHIFT (28U)
/*! I3C3_SDA_FILT - Disables/enables the I3C3 filter function on SDA pin.
 *  0b0000..Enable Spike filter on SDA input when clear both I3C3's SDA_FILT and SCL_FILT 0b0000. Width of Glitch on SDA line is 1 half cycle of FCLK.
 *  0b0001..Disabled filter function when set both I3C3's SDA_FILT and SCL_FILT 0b0001
 */
#define SYSCON_I3C_MISC_CTRL_I3C3_SDA_FILT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C_MISC_CTRL_I3C3_SDA_FILT_SHIFT)) & SYSCON_I3C_MISC_CTRL_I3C3_SDA_FILT_MASK)
/*! @} */

/*! @name CTIMERGLOBALSTARTEN - CTIMER Global Start Enable */
/*! @{ */

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK (0x1U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT (0U)
/*! CTIMER0_CLK_EN - Enables the CTIMER0 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK (0x2U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT (1U)
/*! CTIMER1_CLK_EN - Enables the CTIMER1 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK (0x4U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT (2U)
/*! CTIMER2_CLK_EN - Enables the CTIMER2 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK (0x8U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT (3U)
/*! CTIMER3_CLK_EN - Enables the CTIMER3 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK (0x10U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT (4U)
/*! CTIMER4_CLK_EN - Enables the CTIMER4 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK)
/*! @} */

/*! @name RAM_CTRL - RAM Control */
/*! @{ */

#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_MASK     (0x1U)
#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_SHIFT    (0U)
/*! RAMA_ECC_ENABLE - RAMA ECC enable
 *  0b0..ECC is disabled
 *  0b1..ECC is enabled
 */
#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_SHIFT)) & SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_MASK)

#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_MASK    (0x10000U)
#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_SHIFT   (16U)
/*! RAMA_CG_OVERRIDE - RAMA bank clock gating control, only avaiable when RAMA_ECC_ENABLE = 0.
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_SHIFT)) & SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_MASK)

#define SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_MASK    (0x20000U)
#define SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_SHIFT   (17U)
/*! RAMX_CG_OVERRIDE - RAMX bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_SHIFT)) & SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_MASK)

#define SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_MASK    (0x40000U)
#define SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_SHIFT   (18U)
/*! RAMB_CG_OVERRIDE - RAMB bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_SHIFT)) & SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_MASK)
/*! @} */

/*! @name JTAG_ID - JTAG Chip ID */
/*! @{ */

#define SYSCON_JTAG_ID_JTAG_ID_MASK              (0xFFFFFFFFU)
#define SYSCON_JTAG_ID_JTAG_ID_SHIFT             (0U)
/*! JTAG_ID - Indicates the device ID */
#define SYSCON_JTAG_ID_JTAG_ID(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_JTAG_ID_JTAG_ID_SHIFT)) & SYSCON_JTAG_ID_JTAG_ID_MASK)
/*! @} */

/*! @name DEVICE_TYPE - Device Type */
/*! @{ */

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK  (0xFFFFU)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT (0U)
/*! DEVICE_TYPE_NUM - Indicates the device part number */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK  (0x10000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT (16U)
/*! DEVICE_TYPE_SEC - Indicates the device type
 *  0b0..Non Secure
 *  0b1..Secure
 */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK  (0xF00000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT (20U)
/*! DEVICE_TYPE_PKG - Indicates the device's package type
 *  0b0000..HLQFP
 *  0b0001..HTQFP
 *  0b0010..BGA
 *  0b0011..HDQFP
 *  0b0100..QFN
 *  0b0101..CSP
 *  0b0110..LQFP
 */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK  (0xFF000000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT (24U)
/*! DEVICE_TYPE_PIN - Indicates the device's pin number */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK)
/*! @} */

/*! @name DEVICE_ID0 - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID0_RAM_SIZE_MASK          (0xFU)
#define SYSCON_DEVICE_ID0_RAM_SIZE_SHIFT         (0U)
/*! RAM_SIZE - Indicates the device's ram size
 *  0b0000..8KB.
 *  0b0001..16KB.
 *  0b0010..32KB.
 *  0b0011..64KB.
 *  0b0100..96KB.
 *  0b0101..128KB.
 *  0b0110..160KB.
 *  0b0111..192KB.
 *  0b1000..256KB.
 *  0b1001..288KB.
 *  0b1010..352KB.
 *  0b1011..512KB.
 *  0b1100..640KB.
 */
#define SYSCON_DEVICE_ID0_RAM_SIZE(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_RAM_SIZE_SHIFT)) & SYSCON_DEVICE_ID0_RAM_SIZE_MASK)

#define SYSCON_DEVICE_ID0_FLASH_SIZE_MASK        (0xF0U)
#define SYSCON_DEVICE_ID0_FLASH_SIZE_SHIFT       (4U)
/*! FLASH_SIZE - Indicates the device's flash size
 *  0b0000..32KB.
 *  0b0001..64KB.
 *  0b0010..128KB.
 *  0b0011..256KB.
 *  0b0100..512KB.
 *  0b0101..768KB.
 *  0b0110..1MB.
 *  0b0111..1.5MB.
 *  0b1000..2MB.
 */
#define SYSCON_DEVICE_ID0_FLASH_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_FLASH_SIZE_SHIFT)) & SYSCON_DEVICE_ID0_FLASH_SIZE_MASK)

#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK     (0xF00000U)
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT    (20U)
/*! ROM_REV_MINOR - Indicates the device's ROM revision */
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT)) & SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK)

#define SYSCON_DEVICE_ID0_SECURITY_MASK          (0xF000000U)
#define SYSCON_DEVICE_ID0_SECURITY_SHIFT         (24U)
/*! SECURITY
 *  0b0101..Secure version. (All values other than 1010b represent the secure version.)
 *  0b1010..Non secure version.
 */
#define SYSCON_DEVICE_ID0_SECURITY(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_SECURITY_SHIFT)) & SYSCON_DEVICE_ID0_SECURITY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_Register_Masks */

/*!
 * @brief Get the chip revision.
 *
 * Reads SYSCON offset 0x7FC. Bits[7:4] hold the major revision and bits[3:0]
 * hold the minor revision, forming a combined revision byte (e.g. 0xA0, 0xB0).
 *
 * @return Chip revision byte: 0xA0 for A0 silicon, 0xB0 for B0 silicon.
 */
static inline uint32_t Chip_GetVersion(void)
{
    /* bits[7:4] = MAJOR_REVISION, bits[3:0] = MINOR_REVISION */
    return (*((volatile uint32_t *)(SYSCON_BASE + 0x7FCU))) & 0xFFU;
}

#define CHIP_REVISION_A0 (0xA0U)
#define CHIP_REVISION_B0 (0xB0U)

#define Chip_IsA0Revision() (CHIP_REVISION_A0 == Chip_GetVersion())
#define Chip_IsB0Revision() (CHIP_REVISION_B0 == Chip_GetVersion())


/*!
 * @}
 */ /* end of group SYSCON_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCON_H_ */

