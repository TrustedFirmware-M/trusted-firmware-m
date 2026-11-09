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
**         CMSIS Peripheral Access Layer for MRCC
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
 * @file PERI_MRCC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MRCC
 *
 * CMSIS Peripheral Access Layer for MRCC
 */

#if !defined(PERI_MRCC_H_)
#define PERI_MRCC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- MRCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Peripheral_Access_Layer MRCC Peripheral Access Layer
 * @{
 */

/** MRCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MRCC_GLB_RST0;                     /**< Peripheral Reset Control 0, offset: 0x0 */
  __O  uint32_t MRCC_GLB_RST0_SET;                 /**< Peripheral Reset Control Set 0, offset: 0x4 */
  __O  uint32_t MRCC_GLB_RST0_CLR;                 /**< Peripheral Reset Control Clear 0, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t MRCC_GLB_RST1;                     /**< Peripheral Reset Control 1, offset: 0x10 */
  __O  uint32_t MRCC_GLB_RST1_SET;                 /**< Peripheral Reset Control Set 1, offset: 0x14 */
  __O  uint32_t MRCC_GLB_RST1_CLR;                 /**< Peripheral Reset Control Clear 1, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MRCC_GLB_RST2;                     /**< Peripheral Reset Control 2, offset: 0x20 */
  __O  uint32_t MRCC_GLB_RST2_SET;                 /**< Peripheral Reset Control Set 2, offset: 0x24 */
  __O  uint32_t MRCC_GLB_RST2_CLR;                 /**< Peripheral Reset Control Clear 2, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MRCC_GLB_RST3;                     /**< Peripheral Reset Control 3, offset: 0x30 */
  __O  uint32_t MRCC_GLB_RST3_SET;                 /**< Peripheral Reset Control Set 3, offset: 0x34 */
  __O  uint32_t MRCC_GLB_RST3_CLR;                 /**< Peripheral Reset Control Clear 3, offset: 0x38 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MRCC_GLB_RST4;                     /**< Peripheral Reset Control 4, offset: 0x40 */
  __O  uint32_t MRCC_GLB_RST4_SET;                 /**< Peripheral Reset Control Set 4, offset: 0x44 */
  __O  uint32_t MRCC_GLB_RST4_CLR;                 /**< Peripheral Reset Control Clear 4, offset: 0x48 */
       uint8_t RESERVED_4[20];
  __IO uint32_t MRCC_GLB_CC0;                      /**< AHB Clock Control 0, offset: 0x60 */
  __O  uint32_t MRCC_GLB_CC0_SET;                  /**< AHB Clock Control Set 0, offset: 0x64 */
  __O  uint32_t MRCC_GLB_CC0_CLR;                  /**< AHB Clock Control Clear 0, offset: 0x68 */
       uint8_t RESERVED_5[4];
  __IO uint32_t MRCC_GLB_CC1;                      /**< AHB Clock Control 1, offset: 0x70 */
  __O  uint32_t MRCC_GLB_CC1_SET;                  /**< AHB Clock Control Set 1, offset: 0x74 */
  __O  uint32_t MRCC_GLB_CC1_CLR;                  /**< AHB Clock Control Clear 1, offset: 0x78 */
       uint8_t RESERVED_6[4];
  __IO uint32_t MRCC_GLB_CC2;                      /**< AHB Clock Control 2, offset: 0x80 */
  __O  uint32_t MRCC_GLB_CC2_SET;                  /**< AHB Clock Control Set 2, offset: 0x84 */
  __O  uint32_t MRCC_GLB_CC2_CLR;                  /**< AHB Clock Control Clear 2, offset: 0x88 */
       uint8_t RESERVED_7[4];
  __IO uint32_t MRCC_GLB_CC3;                      /**< AHB Clock Control 3, offset: 0x90 */
  __O  uint32_t MRCC_GLB_CC3_SET;                  /**< AHB Clock Control Set 3, offset: 0x94 */
  __O  uint32_t MRCC_GLB_CC3_CLR;                  /**< AHB Clock Control Clear 3, offset: 0x98 */
       uint8_t RESERVED_8[4];
  __IO uint32_t MRCC_GLB_CC4;                      /**< AHB Clock Control 4, offset: 0xA0 */
  __O  uint32_t MRCC_GLB_CC4_SET;                  /**< AHB Clock Control Set 4, offset: 0xA4 */
  __O  uint32_t MRCC_GLB_CC4_CLR;                  /**< AHB Clock Control Clear 4, offset: 0xA8 */
       uint8_t RESERVED_9[20];
  __IO uint32_t MRCC_GLB_ACC0;                     /**< Control Automatic Clock Gating 0, offset: 0xC0 */
  __IO uint32_t MRCC_GLB_ACC1;                     /**< Control Automatic Clock Gating 1, offset: 0xC4 */
  __IO uint32_t MRCC_GLB_ACC2;                     /**< Control Automatic Clock Gating 2, offset: 0xC8 */
  __IO uint32_t MRCC_GLB_ACC3;                     /**< Control Automatic Clock Gating 3, offset: 0xCC */
  __IO uint32_t MRCC_GLB_ACC4;                     /**< Control Automatic Clock Gating 4, offset: 0xD0 */
       uint8_t RESERVED_10[44];
  __IO uint32_t MRCC_I3C0_FCLK_CLKSEL;             /**< I3C0_FCLK clock selection control, offset: 0x100 */
  __IO uint32_t MRCC_I3C0_FCLK_CLKDIV;             /**< I3C0_FCLK clock divider control, offset: 0x104 */
  __IO uint32_t MRCC_I3C1_FCLK_CLKSEL;             /**< I3C1_FCLK clock selection control, offset: 0x108 */
  __IO uint32_t MRCC_I3C1_FCLK_CLKDIV;             /**< I3C1_FCLK clock divider control, offset: 0x10C */
  __IO uint32_t MRCC_CTIMER0_CLKSEL;               /**< CTIMER0 clock selection control, offset: 0x110 */
  __IO uint32_t MRCC_CTIMER0_CLKDIV;               /**< CTIMER0 clock divider control, offset: 0x114 */
  __IO uint32_t MRCC_CTIMER1_CLKSEL;               /**< CTIMER1 clock selection control, offset: 0x118 */
  __IO uint32_t MRCC_CTIMER1_CLKDIV;               /**< CTIMER1 clock divider control, offset: 0x11C */
  __IO uint32_t MRCC_CTIMER2_CLKSEL;               /**< CTIMER2 clock selection control, offset: 0x120 */
  __IO uint32_t MRCC_CTIMER2_CLKDIV;               /**< CTIMER2 clock divider control, offset: 0x124 */
  __IO uint32_t MRCC_CTIMER3_CLKSEL;               /**< CTIMER3 clock selection control, offset: 0x128 */
  __IO uint32_t MRCC_CTIMER3_CLKDIV;               /**< CTIMER3 clock divider control, offset: 0x12C */
  __IO uint32_t MRCC_CTIMER4_CLKSEL;               /**< CTIMER4 clock selection control, offset: 0x130 */
  __IO uint32_t MRCC_CTIMER4_CLKDIV;               /**< CTIMER4 clock divider control, offset: 0x134 */
       uint8_t RESERVED_11[4];
  __IO uint32_t MRCC_WWDT0_CLKDIV;                 /**< WWDT0 clock divider control, offset: 0x13C */
  __IO uint32_t MRCC_WWDT1_CLKSEL;                 /**< WWDT1 clock selection control, offset: 0x140 */
  __IO uint32_t MRCC_WWDT1_CLKDIV;                 /**< WWDT1 clock divider control, offset: 0x144 */
  __IO uint32_t MRCC_E1588_CLKSEL;                 /**< E1588 clock selection control, offset: 0x148 */
  __IO uint32_t MRCC_E1588_CLKDIV;                 /**< E1588 clock divider control, offset: 0x14C */
  __IO uint32_t MRCC_RMII_CLKSEL;                  /**< RMII clock selection control, offset: 0x150 */
  __IO uint32_t MRCC_RMII_CLKDIV;                  /**< RMII clock divider control, offset: 0x154 */
  __IO uint32_t MRCC_ESPI0_CLKSEL;                 /**< ESPI0 clock selection control, offset: 0x158 */
  __IO uint32_t MRCC_ESPI0_CLKDIV;                 /**< ESPI0 clock divider control, offset: 0x15C */
  __IO uint32_t MRCC_FLEXSPI0_CLKSEL;              /**< FLEXSPI0 clock selection control, offset: 0x160 */
  __IO uint32_t MRCC_FLEXSPI0_CLKDIV;              /**< FLEXSPI0 clock divider control, offset: 0x164 */
  __IO uint32_t MRCC_LPSPI2_CLKSEL;                /**< LPSPI2 clock selection control, offset: 0x168 */
  __IO uint32_t MRCC_LPSPI2_CLKDIV;                /**< LPSPI2 clock divider control, offset: 0x16C */
  __IO uint32_t MRCC_LPSPI3_CLKSEL;                /**< LPSPI3 clock selection control, offset: 0x170 */
  __IO uint32_t MRCC_LPSPI3_CLKDIV;                /**< LPSPI3 clock divider control, offset: 0x174 */
  __IO uint32_t MRCC_LPSPI4_CLKSEL;                /**< LPSPI4 clock selection control, offset: 0x178 */
  __IO uint32_t MRCC_LPSPI4_CLKDIV;                /**< LPSPI4 clock divider control, offset: 0x17C */
  __IO uint32_t MRCC_LPSPI5_CLKSEL;                /**< LPSPI5 clock selection control, offset: 0x180 */
  __IO uint32_t MRCC_LPSPI5_CLKDIV;                /**< LPSPI5 clock divider control, offset: 0x184 */
  __IO uint32_t MRCC_T1S0_CLKSEL;                  /**< T1S0 clock selection control, offset: 0x188 */
  __IO uint32_t MRCC_T1S0_CLKDIV;                  /**< T1S0 clock divider control, offset: 0x18C */
  __IO uint32_t MRCC_USB1_CLKSEL;                  /**< USB1 clock selection control, offset: 0x190 */
       uint8_t RESERVED_12[4];
  __IO uint32_t MRCC_USB1_PHY_CLKSEL;              /**< USB1_PHY clock selection control, offset: 0x198 */
  __IO uint32_t MRCC_USB1_PHY_CLKDIV;              /**< USB1_PHY clock divider control, offset: 0x19C */
  __IO uint32_t MRCC_FLEXIO0_CLKSEL;               /**< FLEXIO0 clock selection control, offset: 0x1A0 */
  __IO uint32_t MRCC_FLEXIO0_CLKDIV;               /**< FLEXIO0 clock divider control, offset: 0x1A4 */
  __IO uint32_t MRCC_LPI2C0_CLKSEL;                /**< LPI2C0 clock selection control, offset: 0x1A8 */
  __IO uint32_t MRCC_LPI2C0_CLKDIV;                /**< LPI2C0 clock divider control, offset: 0x1AC */
  __IO uint32_t MRCC_LPI2C1_CLKSEL;                /**< LPI2C1 clock selection control, offset: 0x1B0 */
  __IO uint32_t MRCC_LPI2C1_CLKDIV;                /**< LPI2C1 clock divider control, offset: 0x1B4 */
  __IO uint32_t MRCC_LPSPI0_CLKSEL;                /**< LPSPI0 clock selection control, offset: 0x1B8 */
  __IO uint32_t MRCC_LPSPI0_CLKDIV;                /**< LPSPI0 clock divider control, offset: 0x1BC */
  __IO uint32_t MRCC_LPSPI1_CLKSEL;                /**< LPSPI1 clock selection control, offset: 0x1C0 */
  __IO uint32_t MRCC_LPSPI1_CLKDIV;                /**< LPSPI1 clock divider control, offset: 0x1C4 */
  __IO uint32_t MRCC_I3C2_FCLK_CLKSEL;             /**< I3C2_FCLK clock selection control, offset: 0x1C8 */
  __IO uint32_t MRCC_I3C2_FCLK_CLKDIV;             /**< I3C2_FCLK clock divider control, offset: 0x1CC */
  __IO uint32_t MRCC_LPUART0_CLKSEL;               /**< LPUART0 clock selection control, offset: 0x1D0 */
  __IO uint32_t MRCC_LPUART0_CLKDIV;               /**< LPUART0 clock divider control, offset: 0x1D4 */
  __IO uint32_t MRCC_LPUART1_CLKSEL;               /**< LPUART1 clock selection control, offset: 0x1D8 */
  __IO uint32_t MRCC_LPUART1_CLKDIV;               /**< LPUART1 clock divider control, offset: 0x1DC */
  __IO uint32_t MRCC_LPUART2_CLKSEL;               /**< LPUART2 clock selection control, offset: 0x1E0 */
  __IO uint32_t MRCC_LPUART2_CLKDIV;               /**< LPUART2 clock divider control, offset: 0x1E4 */
  __IO uint32_t MRCC_LPUART3_CLKSEL;               /**< LPUART3 clock selection control, offset: 0x1E8 */
  __IO uint32_t MRCC_LPUART3_CLKDIV;               /**< LPUART3 clock divider control, offset: 0x1EC */
  __IO uint32_t MRCC_LPUART4_CLKSEL;               /**< LPUART4 clock selection control, offset: 0x1F0 */
  __IO uint32_t MRCC_LPUART4_CLKDIV;               /**< LPUART4 clock divider control, offset: 0x1F4 */
  __IO uint32_t MRCC_LPTMR0_CLKSEL;                /**< LPTMR0 clock selection control, offset: 0x1F8 */
  __IO uint32_t MRCC_LPTMR0_CLKDIV;                /**< LPTMR0 clock divider control, offset: 0x1FC */
  __IO uint32_t MRCC_OSTIMER0_CLKSEL;              /**< OSTIMER0 clock selection control, offset: 0x200 */
       uint8_t RESERVED_13[4];
  __IO uint32_t MRCC_ADC_CLKSEL;                   /**< ADCx clock selection control, offset: 0x208 */
  __IO uint32_t MRCC_ADC_CLKDIV;                   /**< ADCx clock divider control, offset: 0x20C */
       uint8_t RESERVED_14[4];
  __IO uint32_t MRCC_CMP0_FUNC_CLKDIV;             /**< CMP0_FUNC clock divider control, offset: 0x214 */
  __IO uint32_t MRCC_CMP0_RR_CLKSEL;               /**< CMP0_RR clock selection control, offset: 0x218 */
  __IO uint32_t MRCC_CMP0_RR_CLKDIV;               /**< CMP0_RR clock divider control, offset: 0x21C */
  __IO uint32_t MRCC_DAC0_CLKSEL;                  /**< DAC0 clock selection control, offset: 0x220 */
  __IO uint32_t MRCC_DAC0_CLKDIV;                  /**< DAC0 clock divider control, offset: 0x224 */
  __IO uint32_t MRCC_DAC1_CLKSEL;                  /**< DAC1 clock selection control, offset: 0x228 */
  __IO uint32_t MRCC_DAC1_CLKDIV;                  /**< DAC1 clock divider control, offset: 0x22C */
  __IO uint32_t MRCC_TSI0_CLKSEL;                  /**< TSI0 clock selection control, offset: 0x230 */
  __IO uint32_t MRCC_TSI0_CLKDIV;                  /**< TSI0 clock divider control, offset: 0x234 */
  __IO uint32_t MRCC_FLEXCAN0_CLKSEL;              /**< FLEXCAN0 clock selection control, offset: 0x238 */
  __IO uint32_t MRCC_FLEXCAN0_CLKDIV;              /**< FLEXCAN0 clock divider control, offset: 0x23C */
  __IO uint32_t MRCC_FLEXCAN1_CLKSEL;              /**< FLEXCAN1 clock selection control, offset: 0x240 */
  __IO uint32_t MRCC_FLEXCAN1_CLKDIV;              /**< FLEXCAN1 clock divider control, offset: 0x244 */
  __IO uint32_t MRCC_LPI2C2_CLKSEL;                /**< LPI2C2 clock selection control, offset: 0x248 */
  __IO uint32_t MRCC_LPI2C2_CLKDIV;                /**< LPI2C2 clock divider control, offset: 0x24C */
  __IO uint32_t MRCC_LPI2C3_CLKSEL;                /**< LPI2C3 clock selection control, offset: 0x250 */
  __IO uint32_t MRCC_LPI2C3_CLKDIV;                /**< LPI2C3 clock divider control, offset: 0x254 */
  __IO uint32_t MRCC_LPI2C4_CLKSEL;                /**< LPI2C4 clock selection control, offset: 0x258 */
  __IO uint32_t MRCC_LPI2C4_CLKDIV;                /**< LPI2C4 clock divider control, offset: 0x25C */
  __IO uint32_t MRCC_LPUART5_CLKSEL;               /**< LPUART5 clock selection control, offset: 0x260 */
  __IO uint32_t MRCC_LPUART5_CLKDIV;               /**< LPUART5 clock divider control, offset: 0x264 */
  __IO uint32_t MRCC_I3C3_FCLK_CLKSEL;             /**< I3C3_FCLK clock selection control, offset: 0x268 */
  __IO uint32_t MRCC_I3C3_FCLK_CLKDIV;             /**< I3C3_FCLK clock divider control, offset: 0x26C */
  __IO uint32_t MRCC_DBG_TRACE_CLKSEL;             /**< DBG_TRACE clock selection control, offset: 0x270 */
  __IO uint32_t MRCC_DBG_TRACE_CLKDIV;             /**< DBG_TRACE clock divider control, offset: 0x274 */
  __IO uint32_t MRCC_CLKOUT_CLKSEL;                /**< CLKOUT clock selection control, offset: 0x278 */
  __IO uint32_t MRCC_CLKOUT_CLKDIV;                /**< CLKOUT clock divider control, offset: 0x27C */
  __IO uint32_t MRCC_SYSTICK_CLKSEL;               /**< SYSTICK clock selection control, offset: 0x280 */
  __IO uint32_t MRCC_SYSTICK_CLKDIV;               /**< SYSTICK clock divider control, offset: 0x284 */
} MRCC_Type;

/* ----------------------------------------------------------------------------
   -- MRCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Register_Masks MRCC Register Masks
 * @{
 */

/*! @name MRCC_GLB_RST0 - Peripheral Reset Control 0 */
/*! @{ */

#define MRCC_MRCC_GLB_RST0_INPUTMUX0_MASK        (0x1U)
#define MRCC_MRCC_GLB_RST0_INPUTMUX0_SHIFT       (0U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_INPUTMUX0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_INPUTMUX0_SHIFT)) & MRCC_MRCC_GLB_RST0_INPUTMUX0_MASK)

#define MRCC_MRCC_GLB_RST0_FREQME_MASK           (0x2U)
#define MRCC_MRCC_GLB_RST0_FREQME_SHIFT          (1U)
/*! FREQME - FREQME
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_FREQME(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_FREQME_SHIFT)) & MRCC_MRCC_GLB_RST0_FREQME_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER0_MASK          (0x4U)
#define MRCC_MRCC_GLB_RST0_CTIMER0_SHIFT         (2U)
/*! CTIMER0 - CTIMER0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER0_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER0_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER1_MASK          (0x8U)
#define MRCC_MRCC_GLB_RST0_CTIMER1_SHIFT         (3U)
/*! CTIMER1 - CTIMER1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER1_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER1_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER2_MASK          (0x10U)
#define MRCC_MRCC_GLB_RST0_CTIMER2_SHIFT         (4U)
/*! CTIMER2 - CTIMER2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER2_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER2_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER3_MASK          (0x20U)
#define MRCC_MRCC_GLB_RST0_CTIMER3_SHIFT         (5U)
/*! CTIMER3 - CTIMER3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER3_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER3_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER4_MASK          (0x40U)
#define MRCC_MRCC_GLB_RST0_CTIMER4_SHIFT         (6U)
/*! CTIMER4 - CTIMER4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER4_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER4_MASK)

#define MRCC_MRCC_GLB_RST0_UTICK0_MASK           (0x80U)
#define MRCC_MRCC_GLB_RST0_UTICK0_SHIFT          (7U)
/*! UTICK0 - UTICK0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_UTICK0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_UTICK0_SHIFT)) & MRCC_MRCC_GLB_RST0_UTICK0_MASK)

#define MRCC_MRCC_GLB_RST0_DMA0_MASK             (0x400U)
#define MRCC_MRCC_GLB_RST0_DMA0_SHIFT            (10U)
/*! DMA0 - DMA0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_DMA0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_DMA0_SHIFT)) & MRCC_MRCC_GLB_RST0_DMA0_MASK)

#define MRCC_MRCC_GLB_RST0_DMA1_MASK             (0x800U)
#define MRCC_MRCC_GLB_RST0_DMA1_SHIFT            (11U)
/*! DMA1 - DMA1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_DMA1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_DMA1_SHIFT)) & MRCC_MRCC_GLB_RST0_DMA1_MASK)

#define MRCC_MRCC_GLB_RST0_AOI0_MASK             (0x1000U)
#define MRCC_MRCC_GLB_RST0_AOI0_SHIFT            (12U)
/*! AOI0 - AOI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_AOI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_AOI0_SHIFT)) & MRCC_MRCC_GLB_RST0_AOI0_MASK)

#define MRCC_MRCC_GLB_RST0_CRC0_MASK             (0x4000U)
#define MRCC_MRCC_GLB_RST0_CRC0_SHIFT            (14U)
/*! CRC0 - CRC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CRC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CRC0_SHIFT)) & MRCC_MRCC_GLB_RST0_CRC0_MASK)

#define MRCC_MRCC_GLB_RST0_EIM0_MASK             (0x8000U)
#define MRCC_MRCC_GLB_RST0_EIM0_SHIFT            (15U)
/*! EIM0 - EIM0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_EIM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_EIM0_SHIFT)) & MRCC_MRCC_GLB_RST0_EIM0_MASK)

#define MRCC_MRCC_GLB_RST0_ERM0_MASK             (0x10000U)
#define MRCC_MRCC_GLB_RST0_ERM0_SHIFT            (16U)
/*! ERM0 - ERM0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_ERM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_ERM0_SHIFT)) & MRCC_MRCC_GLB_RST0_ERM0_MASK)

#define MRCC_MRCC_GLB_RST0_FLEXIO0_MASK          (0x20000U)
#define MRCC_MRCC_GLB_RST0_FLEXIO0_SHIFT         (17U)
/*! FLEXIO0 - FLEXIO0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_FLEXIO0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_FLEXIO0_SHIFT)) & MRCC_MRCC_GLB_RST0_FLEXIO0_MASK)

#define MRCC_MRCC_GLB_RST0_LPI2C0_MASK           (0x80000U)
#define MRCC_MRCC_GLB_RST0_LPI2C0_SHIFT          (19U)
/*! LPI2C0 - LPI2C0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPI2C0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPI2C0_SHIFT)) & MRCC_MRCC_GLB_RST0_LPI2C0_MASK)

#define MRCC_MRCC_GLB_RST0_LPI2C1_MASK           (0x100000U)
#define MRCC_MRCC_GLB_RST0_LPI2C1_SHIFT          (20U)
/*! LPI2C1 - LPI2C1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPI2C1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPI2C1_SHIFT)) & MRCC_MRCC_GLB_RST0_LPI2C1_MASK)

#define MRCC_MRCC_GLB_RST0_LPI2C2_MASK           (0x200000U)
#define MRCC_MRCC_GLB_RST0_LPI2C2_SHIFT          (21U)
/*! LPI2C2 - LPI2C2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPI2C2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPI2C2_SHIFT)) & MRCC_MRCC_GLB_RST0_LPI2C2_MASK)

#define MRCC_MRCC_GLB_RST0_LPI2C3_MASK           (0x400000U)
#define MRCC_MRCC_GLB_RST0_LPI2C3_SHIFT          (22U)
/*! LPI2C3 - LPI2C3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPI2C3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPI2C3_SHIFT)) & MRCC_MRCC_GLB_RST0_LPI2C3_MASK)

#define MRCC_MRCC_GLB_RST0_LPI2C4_MASK           (0x800000U)
#define MRCC_MRCC_GLB_RST0_LPI2C4_SHIFT          (23U)
/*! LPI2C4 - LPI2C4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPI2C4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPI2C4_SHIFT)) & MRCC_MRCC_GLB_RST0_LPI2C4_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART0_MASK          (0x2000000U)
#define MRCC_MRCC_GLB_RST0_LPUART0_SHIFT         (25U)
/*! LPUART0 - LPUART0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART0_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART0_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART1_MASK          (0x4000000U)
#define MRCC_MRCC_GLB_RST0_LPUART1_SHIFT         (26U)
/*! LPUART1 - LPUART1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART1_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART1_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART2_MASK          (0x8000000U)
#define MRCC_MRCC_GLB_RST0_LPUART2_SHIFT         (27U)
/*! LPUART2 - LPUART2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART2_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART2_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART3_MASK          (0x10000000U)
#define MRCC_MRCC_GLB_RST0_LPUART3_SHIFT         (28U)
/*! LPUART3 - LPUART3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART3_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART3_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART4_MASK          (0x20000000U)
#define MRCC_MRCC_GLB_RST0_LPUART4_SHIFT         (29U)
/*! LPUART4 - LPUART4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART4_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART4_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART5_MASK          (0x40000000U)
#define MRCC_MRCC_GLB_RST0_LPUART5_SHIFT         (30U)
/*! LPUART5 - LPUART5
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART5(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART5_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART5_MASK)

#define MRCC_MRCC_GLB_RST0_OSTIMER0_MASK         (0x80000000U)
#define MRCC_MRCC_GLB_RST0_OSTIMER0_SHIFT        (31U)
/*! OSTIMER0 - OSTIMER0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_OSTIMER0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_OSTIMER0_SHIFT)) & MRCC_MRCC_GLB_RST0_OSTIMER0_MASK)
/*! @} */

/*! @name MRCC_GLB_RST0_SET - Peripheral Reset Control Set 0 */
/*! @{ */

#define MRCC_MRCC_GLB_RST0_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST0_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST0_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST0_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST0_CLR - Peripheral Reset Control Clear 0 */
/*! @{ */

#define MRCC_MRCC_GLB_RST0_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST0_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST0_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST0_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST1 - Peripheral Reset Control 1 */
/*! @{ */

#define MRCC_MRCC_GLB_RST1_LPSPI0_MASK           (0x10U)
#define MRCC_MRCC_GLB_RST1_LPSPI0_SHIFT          (4U)
/*! LPSPI0 - LPSPI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPSPI0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPSPI0_SHIFT)) & MRCC_MRCC_GLB_RST1_LPSPI0_MASK)

#define MRCC_MRCC_GLB_RST1_LPSPI1_MASK           (0x20U)
#define MRCC_MRCC_GLB_RST1_LPSPI1_SHIFT          (5U)
/*! LPSPI1 - LPSPI1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPSPI1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPSPI1_SHIFT)) & MRCC_MRCC_GLB_RST1_LPSPI1_MASK)

#define MRCC_MRCC_GLB_RST1_LPSPI2_MASK           (0x40U)
#define MRCC_MRCC_GLB_RST1_LPSPI2_SHIFT          (6U)
/*! LPSPI2 - LPSPI2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPSPI2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPSPI2_SHIFT)) & MRCC_MRCC_GLB_RST1_LPSPI2_MASK)

#define MRCC_MRCC_GLB_RST1_LPSPI3_MASK           (0x80U)
#define MRCC_MRCC_GLB_RST1_LPSPI3_SHIFT          (7U)
/*! LPSPI3 - LPSPI3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPSPI3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPSPI3_SHIFT)) & MRCC_MRCC_GLB_RST1_LPSPI3_MASK)

#define MRCC_MRCC_GLB_RST1_LPSPI4_MASK           (0x100U)
#define MRCC_MRCC_GLB_RST1_LPSPI4_SHIFT          (8U)
/*! LPSPI4 - LPSPI4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPSPI4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPSPI4_SHIFT)) & MRCC_MRCC_GLB_RST1_LPSPI4_MASK)

#define MRCC_MRCC_GLB_RST1_LPSPI5_MASK           (0x200U)
#define MRCC_MRCC_GLB_RST1_LPSPI5_SHIFT          (9U)
/*! LPSPI5 - LPSPI5
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPSPI5(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPSPI5_SHIFT)) & MRCC_MRCC_GLB_RST1_LPSPI5_MASK)

#define MRCC_MRCC_GLB_RST1_PORT0_MASK            (0x400U)
#define MRCC_MRCC_GLB_RST1_PORT0_SHIFT           (10U)
/*! PORT0 - PORT0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT0_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT0_MASK)

#define MRCC_MRCC_GLB_RST1_PORT1_MASK            (0x800U)
#define MRCC_MRCC_GLB_RST1_PORT1_SHIFT           (11U)
/*! PORT1 - PORT1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT1_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT1_MASK)

#define MRCC_MRCC_GLB_RST1_PORT2_MASK            (0x1000U)
#define MRCC_MRCC_GLB_RST1_PORT2_SHIFT           (12U)
/*! PORT2 - PORT2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT2_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT2_MASK)

#define MRCC_MRCC_GLB_RST1_PORT3_MASK            (0x2000U)
#define MRCC_MRCC_GLB_RST1_PORT3_SHIFT           (13U)
/*! PORT3 - PORT3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT3_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT3_MASK)

#define MRCC_MRCC_GLB_RST1_PORT4_MASK            (0x4000U)
#define MRCC_MRCC_GLB_RST1_PORT4_SHIFT           (14U)
/*! PORT4 - PORT4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT4_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT4_MASK)

#define MRCC_MRCC_GLB_RST1_ADC0_MASK             (0x10000U)
#define MRCC_MRCC_GLB_RST1_ADC0_SHIFT            (16U)
/*! ADC0 - ADC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_ADC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_ADC0_SHIFT)) & MRCC_MRCC_GLB_RST1_ADC0_MASK)

#define MRCC_MRCC_GLB_RST1_ADC1_MASK             (0x20000U)
#define MRCC_MRCC_GLB_RST1_ADC1_SHIFT            (17U)
/*! ADC1 - ADC1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_ADC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_ADC1_SHIFT)) & MRCC_MRCC_GLB_RST1_ADC1_MASK)

#define MRCC_MRCC_GLB_RST1_DAC0_MASK             (0x800000U)
#define MRCC_MRCC_GLB_RST1_DAC0_SHIFT            (23U)
/*! DAC0 - DAC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_DAC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_DAC0_SHIFT)) & MRCC_MRCC_GLB_RST1_DAC0_MASK)

#define MRCC_MRCC_GLB_RST1_DAC1_MASK             (0x1000000U)
#define MRCC_MRCC_GLB_RST1_DAC1_SHIFT            (24U)
/*! DAC1 - DAC1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_DAC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_DAC1_SHIFT)) & MRCC_MRCC_GLB_RST1_DAC1_MASK)

#define MRCC_MRCC_GLB_RST1_VREF0_MASK            (0x20000000U)
#define MRCC_MRCC_GLB_RST1_VREF0_SHIFT           (29U)
/*! VREF0 - VREF0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_VREF0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_VREF0_SHIFT)) & MRCC_MRCC_GLB_RST1_VREF0_MASK)
/*! @} */

/*! @name MRCC_GLB_RST1_SET - Peripheral Reset Control Set 1 */
/*! @{ */

#define MRCC_MRCC_GLB_RST1_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST1_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST1_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST1_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST1_CLR - Peripheral Reset Control Clear 1 */
/*! @{ */

#define MRCC_MRCC_GLB_RST1_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST1_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST1_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST1_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST2 - Peripheral Reset Control 2 */
/*! @{ */

#define MRCC_MRCC_GLB_RST2_I3C0_MASK             (0x1U)
#define MRCC_MRCC_GLB_RST2_I3C0_SHIFT            (0U)
/*! I3C0 - I3C0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_I3C0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_I3C0_SHIFT)) & MRCC_MRCC_GLB_RST2_I3C0_MASK)

#define MRCC_MRCC_GLB_RST2_I3C1_MASK             (0x2U)
#define MRCC_MRCC_GLB_RST2_I3C1_SHIFT            (1U)
/*! I3C1 - I3C1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_I3C1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_I3C1_SHIFT)) & MRCC_MRCC_GLB_RST2_I3C1_MASK)

#define MRCC_MRCC_GLB_RST2_I3C2_MASK             (0x4U)
#define MRCC_MRCC_GLB_RST2_I3C2_SHIFT            (2U)
/*! I3C2 - I3C2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_I3C2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_I3C2_SHIFT)) & MRCC_MRCC_GLB_RST2_I3C2_MASK)

#define MRCC_MRCC_GLB_RST2_I3C3_MASK             (0x8U)
#define MRCC_MRCC_GLB_RST2_I3C3_SHIFT            (3U)
/*! I3C3 - I3C3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_I3C3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_I3C3_SHIFT)) & MRCC_MRCC_GLB_RST2_I3C3_MASK)

#define MRCC_MRCC_GLB_RST2_FLEXCAN0_MASK         (0x10U)
#define MRCC_MRCC_GLB_RST2_FLEXCAN0_SHIFT        (4U)
/*! FLEXCAN0 - FLEXCAN0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_FLEXCAN0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_FLEXCAN0_SHIFT)) & MRCC_MRCC_GLB_RST2_FLEXCAN0_MASK)

#define MRCC_MRCC_GLB_RST2_FLEXCAN1_MASK         (0x20U)
#define MRCC_MRCC_GLB_RST2_FLEXCAN1_SHIFT        (5U)
/*! FLEXCAN1 - FLEXCAN1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_FLEXCAN1(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_FLEXCAN1_SHIFT)) & MRCC_MRCC_GLB_RST2_FLEXCAN1_MASK)

#define MRCC_MRCC_GLB_RST2_ENET0_MASK            (0x400U)
#define MRCC_MRCC_GLB_RST2_ENET0_SHIFT           (10U)
/*! ENET0 - ENET0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_ENET0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_ENET0_SHIFT)) & MRCC_MRCC_GLB_RST2_ENET0_MASK)

#define MRCC_MRCC_GLB_RST2_T1S0_MASK             (0x800U)
#define MRCC_MRCC_GLB_RST2_T1S0_SHIFT            (11U)
/*! T1S0 - T1S0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_T1S0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_T1S0_SHIFT)) & MRCC_MRCC_GLB_RST2_T1S0_MASK)

#define MRCC_MRCC_GLB_RST2_FLEXSPI0_MASK         (0x1000U)
#define MRCC_MRCC_GLB_RST2_FLEXSPI0_SHIFT        (12U)
/*! FLEXSPI0 - FLEXSPI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_FLEXSPI0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_FLEXSPI0_SHIFT)) & MRCC_MRCC_GLB_RST2_FLEXSPI0_MASK)

#define MRCC_MRCC_GLB_RST2_SPI0_FILTER_MASK      (0x2000U)
#define MRCC_MRCC_GLB_RST2_SPI0_FILTER_SHIFT     (13U)
/*! SPI0_FILTER - SPI0_FILTER
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_SPI0_FILTER(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_SPI0_FILTER_SHIFT)) & MRCC_MRCC_GLB_RST2_SPI0_FILTER_MASK)

#define MRCC_MRCC_GLB_RST2_ESPI0_MASK            (0x4000U)
#define MRCC_MRCC_GLB_RST2_ESPI0_SHIFT           (14U)
/*! ESPI0 - ESPI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_ESPI0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_ESPI0_SHIFT)) & MRCC_MRCC_GLB_RST2_ESPI0_MASK)

#define MRCC_MRCC_GLB_RST2_USB1_MASK             (0x40000U)
#define MRCC_MRCC_GLB_RST2_USB1_SHIFT            (18U)
/*! USB1 - USB1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_USB1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_USB1_SHIFT)) & MRCC_MRCC_GLB_RST2_USB1_MASK)

#define MRCC_MRCC_GLB_RST2_USB1_PHY_MASK         (0x80000U)
#define MRCC_MRCC_GLB_RST2_USB1_PHY_SHIFT        (19U)
/*! USB1_PHY - USB1_PHY
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_USB1_PHY(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_USB1_PHY_SHIFT)) & MRCC_MRCC_GLB_RST2_USB1_PHY_MASK)

#define MRCC_MRCC_GLB_RST2_EWM0_MASK             (0x100000U)
#define MRCC_MRCC_GLB_RST2_EWM0_SHIFT            (20U)
/*! EWM0 - EWM0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_EWM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_EWM0_SHIFT)) & MRCC_MRCC_GLB_RST2_EWM0_MASK)
/*! @} */

/*! @name MRCC_GLB_RST2_SET - Peripheral Reset Control Set 2 */
/*! @{ */

#define MRCC_MRCC_GLB_RST2_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST2_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST2_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST2_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST2_CLR - Peripheral Reset Control Clear 2 */
/*! @{ */

#define MRCC_MRCC_GLB_RST2_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST2_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST2_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST2_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST3 - Peripheral Reset Control 3 */
/*! @{ */

#define MRCC_MRCC_GLB_RST3_GPIO0_MASK            (0x100000U)
#define MRCC_MRCC_GLB_RST3_GPIO0_SHIFT           (20U)
/*! GPIO0 - GPIO0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST3_GPIO0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_GPIO0_SHIFT)) & MRCC_MRCC_GLB_RST3_GPIO0_MASK)

#define MRCC_MRCC_GLB_RST3_GPIO1_MASK            (0x200000U)
#define MRCC_MRCC_GLB_RST3_GPIO1_SHIFT           (21U)
/*! GPIO1 - GPIO1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST3_GPIO1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_GPIO1_SHIFT)) & MRCC_MRCC_GLB_RST3_GPIO1_MASK)

#define MRCC_MRCC_GLB_RST3_GPIO2_MASK            (0x400000U)
#define MRCC_MRCC_GLB_RST3_GPIO2_SHIFT           (22U)
/*! GPIO2 - GPIO2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST3_GPIO2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_GPIO2_SHIFT)) & MRCC_MRCC_GLB_RST3_GPIO2_MASK)

#define MRCC_MRCC_GLB_RST3_GPIO3_MASK            (0x800000U)
#define MRCC_MRCC_GLB_RST3_GPIO3_SHIFT           (23U)
/*! GPIO3 - GPIO3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST3_GPIO3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_GPIO3_SHIFT)) & MRCC_MRCC_GLB_RST3_GPIO3_MASK)

#define MRCC_MRCC_GLB_RST3_GPIO4_MASK            (0x1000000U)
#define MRCC_MRCC_GLB_RST3_GPIO4_SHIFT           (24U)
/*! GPIO4 - GPIO4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST3_GPIO4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_GPIO4_SHIFT)) & MRCC_MRCC_GLB_RST3_GPIO4_MASK)

#define MRCC_MRCC_GLB_RST3_SMARTDMA0_MASK        (0x20000000U)
#define MRCC_MRCC_GLB_RST3_SMARTDMA0_SHIFT       (29U)
/*! SMARTDMA0 - SMARTDMA0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST3_SMARTDMA0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_SMARTDMA0_SHIFT)) & MRCC_MRCC_GLB_RST3_SMARTDMA0_MASK)
/*! @} */

/*! @name MRCC_GLB_RST3_SET - Peripheral Reset Control Set 3 */
/*! @{ */

#define MRCC_MRCC_GLB_RST3_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST3_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST3_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST3_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST3_CLR - Peripheral Reset Control Clear 3 */
/*! @{ */

#define MRCC_MRCC_GLB_RST3_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST3_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST3_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST3_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST3_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST4 - Peripheral Reset Control 4 */
/*! @{ */

#define MRCC_MRCC_GLB_RST4_GLIKEY0_MASK          (0x20000U)
#define MRCC_MRCC_GLB_RST4_GLIKEY0_SHIFT         (17U)
/*! GLIKEY0 - GLIKEY0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST4_GLIKEY0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST4_GLIKEY0_SHIFT)) & MRCC_MRCC_GLB_RST4_GLIKEY0_MASK)

#define MRCC_MRCC_GLB_RST4_PKC0_MASK             (0x80000U)
#define MRCC_MRCC_GLB_RST4_PKC0_SHIFT            (19U)
/*! PKC0 - PKC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST4_PKC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST4_PKC0_SHIFT)) & MRCC_MRCC_GLB_RST4_PKC0_MASK)

#define MRCC_MRCC_GLB_RST4_TRNG0_MASK            (0x200000U)
#define MRCC_MRCC_GLB_RST4_TRNG0_SHIFT           (21U)
/*! TRNG0 - TRNG0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST4_TRNG0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST4_TRNG0_SHIFT)) & MRCC_MRCC_GLB_RST4_TRNG0_MASK)

#define MRCC_MRCC_GLB_RST4_DGDET0_MASK           (0x800000U)
#define MRCC_MRCC_GLB_RST4_DGDET0_SHIFT          (23U)
/*! DGDET0 - DGDET0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST4_DGDET0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST4_DGDET0_SHIFT)) & MRCC_MRCC_GLB_RST4_DGDET0_MASK)
/*! @} */

/*! @name MRCC_GLB_RST4_SET - Peripheral Reset Control Set 4 */
/*! @{ */

#define MRCC_MRCC_GLB_RST4_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST4_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST4_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST4_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST4_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST4_CLR - Peripheral Reset Control Clear 4 */
/*! @{ */

#define MRCC_MRCC_GLB_RST4_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST4_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST4_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST4_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST4_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC0 - AHB Clock Control 0 */
/*! @{ */

#define MRCC_MRCC_GLB_CC0_INPUTMUX0_MASK         (0x1U)
#define MRCC_MRCC_GLB_CC0_INPUTMUX0_SHIFT        (0U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_INPUTMUX0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_INPUTMUX0_SHIFT)) & MRCC_MRCC_GLB_CC0_INPUTMUX0_MASK)

#define MRCC_MRCC_GLB_CC0_FREQME_MASK            (0x2U)
#define MRCC_MRCC_GLB_CC0_FREQME_SHIFT           (1U)
/*! FREQME - FREQME
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_FREQME(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_FREQME_SHIFT)) & MRCC_MRCC_GLB_CC0_FREQME_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER0_MASK           (0x4U)
#define MRCC_MRCC_GLB_CC0_CTIMER0_SHIFT          (2U)
/*! CTIMER0 - CTIMER0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER0_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER0_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER1_MASK           (0x8U)
#define MRCC_MRCC_GLB_CC0_CTIMER1_SHIFT          (3U)
/*! CTIMER1 - CTIMER1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER1_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER1_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER2_MASK           (0x10U)
#define MRCC_MRCC_GLB_CC0_CTIMER2_SHIFT          (4U)
/*! CTIMER2 - CTIMER2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER2_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER2_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER3_MASK           (0x20U)
#define MRCC_MRCC_GLB_CC0_CTIMER3_SHIFT          (5U)
/*! CTIMER3 - CTIMER3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER3_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER3_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER4_MASK           (0x40U)
#define MRCC_MRCC_GLB_CC0_CTIMER4_SHIFT          (6U)
/*! CTIMER4 - CTIMER4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER4_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER4_MASK)

#define MRCC_MRCC_GLB_CC0_UTICK0_MASK            (0x80U)
#define MRCC_MRCC_GLB_CC0_UTICK0_SHIFT           (7U)
/*! UTICK0 - UTICK0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_UTICK0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_UTICK0_SHIFT)) & MRCC_MRCC_GLB_CC0_UTICK0_MASK)

#define MRCC_MRCC_GLB_CC0_WWDT0_MASK             (0x100U)
#define MRCC_MRCC_GLB_CC0_WWDT0_SHIFT            (8U)
/*! WWDT0 - WWDT0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_WWDT0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_WWDT0_SHIFT)) & MRCC_MRCC_GLB_CC0_WWDT0_MASK)

#define MRCC_MRCC_GLB_CC0_WWDT1_MASK             (0x200U)
#define MRCC_MRCC_GLB_CC0_WWDT1_SHIFT            (9U)
/*! WWDT1 - WWDT1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_WWDT1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_WWDT1_SHIFT)) & MRCC_MRCC_GLB_CC0_WWDT1_MASK)

#define MRCC_MRCC_GLB_CC0_DMA0_MASK              (0x400U)
#define MRCC_MRCC_GLB_CC0_DMA0_SHIFT             (10U)
/*! DMA0 - DMA0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_DMA0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_DMA0_SHIFT)) & MRCC_MRCC_GLB_CC0_DMA0_MASK)

#define MRCC_MRCC_GLB_CC0_DMA1_MASK              (0x800U)
#define MRCC_MRCC_GLB_CC0_DMA1_SHIFT             (11U)
/*! DMA1 - DMA1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_DMA1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_DMA1_SHIFT)) & MRCC_MRCC_GLB_CC0_DMA1_MASK)

#define MRCC_MRCC_GLB_CC0_AOI0_MASK              (0x1000U)
#define MRCC_MRCC_GLB_CC0_AOI0_SHIFT             (12U)
/*! AOI0 - AOI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_AOI0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_AOI0_SHIFT)) & MRCC_MRCC_GLB_CC0_AOI0_MASK)

#define MRCC_MRCC_GLB_CC0_CRC0_MASK              (0x4000U)
#define MRCC_MRCC_GLB_CC0_CRC0_SHIFT             (14U)
/*! CRC0 - CRC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CRC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CRC0_SHIFT)) & MRCC_MRCC_GLB_CC0_CRC0_MASK)

#define MRCC_MRCC_GLB_CC0_EIM0_MASK              (0x8000U)
#define MRCC_MRCC_GLB_CC0_EIM0_SHIFT             (15U)
/*! EIM0 - EIM0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_EIM0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_EIM0_SHIFT)) & MRCC_MRCC_GLB_CC0_EIM0_MASK)

#define MRCC_MRCC_GLB_CC0_ERM0_MASK              (0x10000U)
#define MRCC_MRCC_GLB_CC0_ERM0_SHIFT             (16U)
/*! ERM0 - ERM0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_ERM0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_ERM0_SHIFT)) & MRCC_MRCC_GLB_CC0_ERM0_MASK)

#define MRCC_MRCC_GLB_CC0_FLEXIO0_MASK           (0x20000U)
#define MRCC_MRCC_GLB_CC0_FLEXIO0_SHIFT          (17U)
/*! FLEXIO0 - FLEXIO0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_FLEXIO0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_FLEXIO0_SHIFT)) & MRCC_MRCC_GLB_CC0_FLEXIO0_MASK)

#define MRCC_MRCC_GLB_CC0_LPI2C0_MASK            (0x80000U)
#define MRCC_MRCC_GLB_CC0_LPI2C0_SHIFT           (19U)
/*! LPI2C0 - LPI2C0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPI2C0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPI2C0_SHIFT)) & MRCC_MRCC_GLB_CC0_LPI2C0_MASK)

#define MRCC_MRCC_GLB_CC0_LPI2C1_MASK            (0x100000U)
#define MRCC_MRCC_GLB_CC0_LPI2C1_SHIFT           (20U)
/*! LPI2C1 - LPI2C1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPI2C1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPI2C1_SHIFT)) & MRCC_MRCC_GLB_CC0_LPI2C1_MASK)

#define MRCC_MRCC_GLB_CC0_LPI2C2_MASK            (0x200000U)
#define MRCC_MRCC_GLB_CC0_LPI2C2_SHIFT           (21U)
/*! LPI2C2 - LPI2C2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPI2C2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPI2C2_SHIFT)) & MRCC_MRCC_GLB_CC0_LPI2C2_MASK)

#define MRCC_MRCC_GLB_CC0_LPI2C3_MASK            (0x400000U)
#define MRCC_MRCC_GLB_CC0_LPI2C3_SHIFT           (22U)
/*! LPI2C3 - LPI2C3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPI2C3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPI2C3_SHIFT)) & MRCC_MRCC_GLB_CC0_LPI2C3_MASK)

#define MRCC_MRCC_GLB_CC0_LPI2C4_MASK            (0x800000U)
#define MRCC_MRCC_GLB_CC0_LPI2C4_SHIFT           (23U)
/*! LPI2C4 - LPI2C4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPI2C4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPI2C4_SHIFT)) & MRCC_MRCC_GLB_CC0_LPI2C4_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART0_MASK           (0x2000000U)
#define MRCC_MRCC_GLB_CC0_LPUART0_SHIFT          (25U)
/*! LPUART0 - LPUART0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART0_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART0_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART1_MASK           (0x4000000U)
#define MRCC_MRCC_GLB_CC0_LPUART1_SHIFT          (26U)
/*! LPUART1 - LPUART1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART1_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART1_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART2_MASK           (0x8000000U)
#define MRCC_MRCC_GLB_CC0_LPUART2_SHIFT          (27U)
/*! LPUART2 - LPUART2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART2_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART2_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART3_MASK           (0x10000000U)
#define MRCC_MRCC_GLB_CC0_LPUART3_SHIFT          (28U)
/*! LPUART3 - LPUART3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART3_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART3_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART4_MASK           (0x20000000U)
#define MRCC_MRCC_GLB_CC0_LPUART4_SHIFT          (29U)
/*! LPUART4 - LPUART4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART4_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART4_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART5_MASK           (0x40000000U)
#define MRCC_MRCC_GLB_CC0_LPUART5_SHIFT          (30U)
/*! LPUART5 - LPUART5
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART5(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART5_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART5_MASK)

#define MRCC_MRCC_GLB_CC0_OSTIMER0_MASK          (0x80000000U)
#define MRCC_MRCC_GLB_CC0_OSTIMER0_SHIFT         (31U)
/*! OSTIMER0 - OSTIMER0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_OSTIMER0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_OSTIMER0_SHIFT)) & MRCC_MRCC_GLB_CC0_OSTIMER0_MASK)
/*! @} */

/*! @name MRCC_GLB_CC0_SET - AHB Clock Control Set 0 */
/*! @{ */

#define MRCC_MRCC_GLB_CC0_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC0_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC0_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC0_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC0_CLR - AHB Clock Control Clear 0 */
/*! @{ */

#define MRCC_MRCC_GLB_CC0_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC0_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC0_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC0_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC1 - AHB Clock Control 1 */
/*! @{ */

#define MRCC_MRCC_GLB_CC1_LPSPI0_MASK            (0x10U)
#define MRCC_MRCC_GLB_CC1_LPSPI0_SHIFT           (4U)
/*! LPSPI0 - LPSPI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPSPI0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPSPI0_SHIFT)) & MRCC_MRCC_GLB_CC1_LPSPI0_MASK)

#define MRCC_MRCC_GLB_CC1_LPSPI1_MASK            (0x20U)
#define MRCC_MRCC_GLB_CC1_LPSPI1_SHIFT           (5U)
/*! LPSPI1 - LPSPI1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPSPI1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPSPI1_SHIFT)) & MRCC_MRCC_GLB_CC1_LPSPI1_MASK)

#define MRCC_MRCC_GLB_CC1_LPSPI2_MASK            (0x40U)
#define MRCC_MRCC_GLB_CC1_LPSPI2_SHIFT           (6U)
/*! LPSPI2 - LPSPI2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPSPI2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPSPI2_SHIFT)) & MRCC_MRCC_GLB_CC1_LPSPI2_MASK)

#define MRCC_MRCC_GLB_CC1_LPSPI3_MASK            (0x80U)
#define MRCC_MRCC_GLB_CC1_LPSPI3_SHIFT           (7U)
/*! LPSPI3 - LPSPI3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPSPI3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPSPI3_SHIFT)) & MRCC_MRCC_GLB_CC1_LPSPI3_MASK)

#define MRCC_MRCC_GLB_CC1_LPSPI4_MASK            (0x100U)
#define MRCC_MRCC_GLB_CC1_LPSPI4_SHIFT           (8U)
/*! LPSPI4 - LPSPI4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPSPI4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPSPI4_SHIFT)) & MRCC_MRCC_GLB_CC1_LPSPI4_MASK)

#define MRCC_MRCC_GLB_CC1_LPSPI5_MASK            (0x200U)
#define MRCC_MRCC_GLB_CC1_LPSPI5_SHIFT           (9U)
/*! LPSPI5 - LPSPI5
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPSPI5(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPSPI5_SHIFT)) & MRCC_MRCC_GLB_CC1_LPSPI5_MASK)

#define MRCC_MRCC_GLB_CC1_PORT0_MASK             (0x400U)
#define MRCC_MRCC_GLB_CC1_PORT0_SHIFT            (10U)
/*! PORT0 - PORT0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT0_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT0_MASK)

#define MRCC_MRCC_GLB_CC1_PORT1_MASK             (0x800U)
#define MRCC_MRCC_GLB_CC1_PORT1_SHIFT            (11U)
/*! PORT1 - PORT1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT1_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT1_MASK)

#define MRCC_MRCC_GLB_CC1_PORT2_MASK             (0x1000U)
#define MRCC_MRCC_GLB_CC1_PORT2_SHIFT            (12U)
/*! PORT2 - PORT2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT2_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT2_MASK)

#define MRCC_MRCC_GLB_CC1_PORT3_MASK             (0x2000U)
#define MRCC_MRCC_GLB_CC1_PORT3_SHIFT            (13U)
/*! PORT3 - PORT3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT3_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT3_MASK)

#define MRCC_MRCC_GLB_CC1_PORT4_MASK             (0x4000U)
#define MRCC_MRCC_GLB_CC1_PORT4_SHIFT            (14U)
/*! PORT4 - PORT4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT4(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT4_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT4_MASK)

#define MRCC_MRCC_GLB_CC1_PORT5_MASK             (0x8000U)
#define MRCC_MRCC_GLB_CC1_PORT5_SHIFT            (15U)
/*! PORT5 - PORT5
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT5(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT5_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT5_MASK)

#define MRCC_MRCC_GLB_CC1_ADC0_MASK              (0x10000U)
#define MRCC_MRCC_GLB_CC1_ADC0_SHIFT             (16U)
/*! ADC0 - ADC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_ADC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_ADC0_SHIFT)) & MRCC_MRCC_GLB_CC1_ADC0_MASK)

#define MRCC_MRCC_GLB_CC1_ADC1_MASK              (0x20000U)
#define MRCC_MRCC_GLB_CC1_ADC1_SHIFT             (17U)
/*! ADC1 - ADC1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_ADC1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_ADC1_SHIFT)) & MRCC_MRCC_GLB_CC1_ADC1_MASK)

#define MRCC_MRCC_GLB_CC1_CMP0_MASK              (0x100000U)
#define MRCC_MRCC_GLB_CC1_CMP0_SHIFT             (20U)
/*! CMP0 - CMP0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_CMP0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_CMP0_SHIFT)) & MRCC_MRCC_GLB_CC1_CMP0_MASK)

#define MRCC_MRCC_GLB_CC1_DAC0_MASK              (0x800000U)
#define MRCC_MRCC_GLB_CC1_DAC0_SHIFT             (23U)
/*! DAC0 - DAC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_DAC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_DAC0_SHIFT)) & MRCC_MRCC_GLB_CC1_DAC0_MASK)

#define MRCC_MRCC_GLB_CC1_DAC1_MASK              (0x1000000U)
#define MRCC_MRCC_GLB_CC1_DAC1_SHIFT             (24U)
/*! DAC1 - DAC1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_DAC1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_DAC1_SHIFT)) & MRCC_MRCC_GLB_CC1_DAC1_MASK)

#define MRCC_MRCC_GLB_CC1_VREF0_MASK             (0x20000000U)
#define MRCC_MRCC_GLB_CC1_VREF0_SHIFT            (29U)
/*! VREF0 - VREF0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_VREF0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_VREF0_SHIFT)) & MRCC_MRCC_GLB_CC1_VREF0_MASK)

#define MRCC_MRCC_GLB_CC1_TSI0_MASK              (0x80000000U)
#define MRCC_MRCC_GLB_CC1_TSI0_SHIFT             (31U)
/*! TSI0 - TSI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_TSI0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_TSI0_SHIFT)) & MRCC_MRCC_GLB_CC1_TSI0_MASK)
/*! @} */

/*! @name MRCC_GLB_CC1_SET - AHB Clock Control Set 1 */
/*! @{ */

#define MRCC_MRCC_GLB_CC1_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC1_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC1_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC1_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC1_CLR - AHB Clock Control Clear 1 */
/*! @{ */

#define MRCC_MRCC_GLB_CC1_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC1_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC1_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC1_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC2 - AHB Clock Control 2 */
/*! @{ */

#define MRCC_MRCC_GLB_CC2_I3C0_MASK              (0x1U)
#define MRCC_MRCC_GLB_CC2_I3C0_SHIFT             (0U)
/*! I3C0 - I3C0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_I3C0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_I3C0_SHIFT)) & MRCC_MRCC_GLB_CC2_I3C0_MASK)

#define MRCC_MRCC_GLB_CC2_I3C1_MASK              (0x2U)
#define MRCC_MRCC_GLB_CC2_I3C1_SHIFT             (1U)
/*! I3C1 - I3C1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_I3C1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_I3C1_SHIFT)) & MRCC_MRCC_GLB_CC2_I3C1_MASK)

#define MRCC_MRCC_GLB_CC2_I3C2_MASK              (0x4U)
#define MRCC_MRCC_GLB_CC2_I3C2_SHIFT             (2U)
/*! I3C2 - I3C2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_I3C2(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_I3C2_SHIFT)) & MRCC_MRCC_GLB_CC2_I3C2_MASK)

#define MRCC_MRCC_GLB_CC2_I3C3_MASK              (0x8U)
#define MRCC_MRCC_GLB_CC2_I3C3_SHIFT             (3U)
/*! I3C3 - I3C3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_I3C3(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_I3C3_SHIFT)) & MRCC_MRCC_GLB_CC2_I3C3_MASK)

#define MRCC_MRCC_GLB_CC2_FLEXCAN0_MASK          (0x10U)
#define MRCC_MRCC_GLB_CC2_FLEXCAN0_SHIFT         (4U)
/*! FLEXCAN0 - FLEXCAN0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_FLEXCAN0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_FLEXCAN0_SHIFT)) & MRCC_MRCC_GLB_CC2_FLEXCAN0_MASK)

#define MRCC_MRCC_GLB_CC2_FLEXCAN1_MASK          (0x20U)
#define MRCC_MRCC_GLB_CC2_FLEXCAN1_SHIFT         (5U)
/*! FLEXCAN1 - FLEXCAN1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_FLEXCAN1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_FLEXCAN1_SHIFT)) & MRCC_MRCC_GLB_CC2_FLEXCAN1_MASK)

#define MRCC_MRCC_GLB_CC2_E1588_MASK             (0x100U)
#define MRCC_MRCC_GLB_CC2_E1588_SHIFT            (8U)
/*! E1588 - E1588
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_E1588(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_E1588_SHIFT)) & MRCC_MRCC_GLB_CC2_E1588_MASK)

#define MRCC_MRCC_GLB_CC2_RMII_MASK              (0x200U)
#define MRCC_MRCC_GLB_CC2_RMII_SHIFT             (9U)
/*! RMII - RMII
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_RMII(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_RMII_SHIFT)) & MRCC_MRCC_GLB_CC2_RMII_MASK)

#define MRCC_MRCC_GLB_CC2_ENET0_MASK             (0x400U)
#define MRCC_MRCC_GLB_CC2_ENET0_SHIFT            (10U)
/*! ENET0 - ENET0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_ENET0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_ENET0_SHIFT)) & MRCC_MRCC_GLB_CC2_ENET0_MASK)

#define MRCC_MRCC_GLB_CC2_T1S0_MASK              (0x800U)
#define MRCC_MRCC_GLB_CC2_T1S0_SHIFT             (11U)
/*! T1S0 - T1S0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_T1S0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_T1S0_SHIFT)) & MRCC_MRCC_GLB_CC2_T1S0_MASK)

#define MRCC_MRCC_GLB_CC2_FLEXSPI0_MASK          (0x1000U)
#define MRCC_MRCC_GLB_CC2_FLEXSPI0_SHIFT         (12U)
/*! FLEXSPI0 - FLEXSPI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_FLEXSPI0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_FLEXSPI0_SHIFT)) & MRCC_MRCC_GLB_CC2_FLEXSPI0_MASK)

#define MRCC_MRCC_GLB_CC2_SPI0_FILTER_MASK       (0x2000U)
#define MRCC_MRCC_GLB_CC2_SPI0_FILTER_SHIFT      (13U)
/*! SPI0_FILTER - SPI0_FILTER
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_SPI0_FILTER(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_SPI0_FILTER_SHIFT)) & MRCC_MRCC_GLB_CC2_SPI0_FILTER_MASK)

#define MRCC_MRCC_GLB_CC2_ESPI0_MASK             (0x4000U)
#define MRCC_MRCC_GLB_CC2_ESPI0_SHIFT            (14U)
/*! ESPI0 - ESPI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_ESPI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_ESPI0_SHIFT)) & MRCC_MRCC_GLB_CC2_ESPI0_MASK)

#define MRCC_MRCC_GLB_CC2_USB1_MASK              (0x40000U)
#define MRCC_MRCC_GLB_CC2_USB1_SHIFT             (18U)
/*! USB1 - USB1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_USB1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_USB1_SHIFT)) & MRCC_MRCC_GLB_CC2_USB1_MASK)

#define MRCC_MRCC_GLB_CC2_USB1_PHY_MASK          (0x80000U)
#define MRCC_MRCC_GLB_CC2_USB1_PHY_SHIFT         (19U)
/*! USB1_PHY - USB1_PHY
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_USB1_PHY(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_USB1_PHY_SHIFT)) & MRCC_MRCC_GLB_CC2_USB1_PHY_MASK)

#define MRCC_MRCC_GLB_CC2_EWM0_MASK              (0x100000U)
#define MRCC_MRCC_GLB_CC2_EWM0_SHIFT             (20U)
/*! EWM0 - EWM0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_EWM0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_EWM0_SHIFT)) & MRCC_MRCC_GLB_CC2_EWM0_MASK)
/*! @} */

/*! @name MRCC_GLB_CC2_SET - AHB Clock Control Set 2 */
/*! @{ */

#define MRCC_MRCC_GLB_CC2_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC2_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC2_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC2_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC2_CLR - AHB Clock Control Clear 2 */
/*! @{ */

#define MRCC_MRCC_GLB_CC2_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC2_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC2_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC2_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC3 - AHB Clock Control 3 */
/*! @{ */

#define MRCC_MRCC_GLB_CC3_RAMA_MASK              (0x10000U)
#define MRCC_MRCC_GLB_CC3_RAMA_SHIFT             (16U)
/*! RAMA - RAMA
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_RAMA(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_RAMA_SHIFT)) & MRCC_MRCC_GLB_CC3_RAMA_MASK)

#define MRCC_MRCC_GLB_CC3_RAMB_MASK              (0x20000U)
#define MRCC_MRCC_GLB_CC3_RAMB_SHIFT             (17U)
/*! RAMB - RAMB
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_RAMB(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_RAMB_SHIFT)) & MRCC_MRCC_GLB_CC3_RAMB_MASK)

#define MRCC_MRCC_GLB_CC3_GPIO0_MASK             (0x100000U)
#define MRCC_MRCC_GLB_CC3_GPIO0_SHIFT            (20U)
/*! GPIO0 - GPIO0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_GPIO0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_GPIO0_SHIFT)) & MRCC_MRCC_GLB_CC3_GPIO0_MASK)

#define MRCC_MRCC_GLB_CC3_GPIO1_MASK             (0x200000U)
#define MRCC_MRCC_GLB_CC3_GPIO1_SHIFT            (21U)
/*! GPIO1 - GPIO1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_GPIO1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_GPIO1_SHIFT)) & MRCC_MRCC_GLB_CC3_GPIO1_MASK)

#define MRCC_MRCC_GLB_CC3_GPIO2_MASK             (0x400000U)
#define MRCC_MRCC_GLB_CC3_GPIO2_SHIFT            (22U)
/*! GPIO2 - GPIO2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_GPIO2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_GPIO2_SHIFT)) & MRCC_MRCC_GLB_CC3_GPIO2_MASK)

#define MRCC_MRCC_GLB_CC3_GPIO3_MASK             (0x800000U)
#define MRCC_MRCC_GLB_CC3_GPIO3_SHIFT            (23U)
/*! GPIO3 - GPIO3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_GPIO3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_GPIO3_SHIFT)) & MRCC_MRCC_GLB_CC3_GPIO3_MASK)

#define MRCC_MRCC_GLB_CC3_GPIO4_MASK             (0x1000000U)
#define MRCC_MRCC_GLB_CC3_GPIO4_SHIFT            (24U)
/*! GPIO4 - GPIO4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_GPIO4(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_GPIO4_SHIFT)) & MRCC_MRCC_GLB_CC3_GPIO4_MASK)

#define MRCC_MRCC_GLB_CC3_GPIO5_MASK             (0x2000000U)
#define MRCC_MRCC_GLB_CC3_GPIO5_SHIFT            (25U)
/*! GPIO5 - GPIO5
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_GPIO5(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_GPIO5_SHIFT)) & MRCC_MRCC_GLB_CC3_GPIO5_MASK)

#define MRCC_MRCC_GLB_CC3_ROMC_MASK              (0x10000000U)
#define MRCC_MRCC_GLB_CC3_ROMC_SHIFT             (28U)
/*! ROMC - ROMC
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_ROMC(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_ROMC_SHIFT)) & MRCC_MRCC_GLB_CC3_ROMC_MASK)

#define MRCC_MRCC_GLB_CC3_SMARTDMA0_MASK         (0x20000000U)
#define MRCC_MRCC_GLB_CC3_SMARTDMA0_SHIFT        (29U)
/*! SMARTDMA0 - SMARTDMA0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC3_SMARTDMA0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_SMARTDMA0_SHIFT)) & MRCC_MRCC_GLB_CC3_SMARTDMA0_MASK)
/*! @} */

/*! @name MRCC_GLB_CC3_SET - AHB Clock Control Set 3 */
/*! @{ */

#define MRCC_MRCC_GLB_CC3_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC3_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC3_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC3_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC3_CLR - AHB Clock Control Clear 3 */
/*! @{ */

#define MRCC_MRCC_GLB_CC3_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC3_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC3_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC3_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC3_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC4 - AHB Clock Control 4 */
/*! @{ */

#define MRCC_MRCC_GLB_CC4_SECCON_MASK            (0x10000U)
#define MRCC_MRCC_GLB_CC4_SECCON_SHIFT           (16U)
/*! SECCON - SECCON
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_SECCON(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_SECCON_SHIFT)) & MRCC_MRCC_GLB_CC4_SECCON_MASK)

#define MRCC_MRCC_GLB_CC4_GLIKEY0_MASK           (0x20000U)
#define MRCC_MRCC_GLB_CC4_GLIKEY0_SHIFT          (17U)
/*! GLIKEY0 - GLIKEY0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_GLIKEY0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_GLIKEY0_SHIFT)) & MRCC_MRCC_GLB_CC4_GLIKEY0_MASK)

#define MRCC_MRCC_GLB_CC4_TDET0_MASK             (0x40000U)
#define MRCC_MRCC_GLB_CC4_TDET0_SHIFT            (18U)
/*! TDET0 - TDET0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_TDET0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_TDET0_SHIFT)) & MRCC_MRCC_GLB_CC4_TDET0_MASK)

#define MRCC_MRCC_GLB_CC4_PKC0_MASK              (0x80000U)
#define MRCC_MRCC_GLB_CC4_PKC0_SHIFT             (19U)
/*! PKC0 - PKC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_PKC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_PKC0_SHIFT)) & MRCC_MRCC_GLB_CC4_PKC0_MASK)

#define MRCC_MRCC_GLB_CC4_SGI0_MASK              (0x100000U)
#define MRCC_MRCC_GLB_CC4_SGI0_SHIFT             (20U)
/*! SGI0 - SGI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_SGI0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_SGI0_SHIFT)) & MRCC_MRCC_GLB_CC4_SGI0_MASK)

#define MRCC_MRCC_GLB_CC4_TRNG0_MASK             (0x200000U)
#define MRCC_MRCC_GLB_CC4_TRNG0_SHIFT            (21U)
/*! TRNG0 - TRNG0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_TRNG0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_TRNG0_SHIFT)) & MRCC_MRCC_GLB_CC4_TRNG0_MASK)

#define MRCC_MRCC_GLB_CC4_UDF0_MASK              (0x400000U)
#define MRCC_MRCC_GLB_CC4_UDF0_SHIFT             (22U)
/*! UDF0 - UDF0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_UDF0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_UDF0_SHIFT)) & MRCC_MRCC_GLB_CC4_UDF0_MASK)

#define MRCC_MRCC_GLB_CC4_DGDET0_MASK            (0x800000U)
#define MRCC_MRCC_GLB_CC4_DGDET0_SHIFT           (23U)
/*! DGDET0 - DGDET0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_DGDET0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_DGDET0_SHIFT)) & MRCC_MRCC_GLB_CC4_DGDET0_MASK)

#define MRCC_MRCC_GLB_CC4_ITRC0_MASK             (0x1000000U)
#define MRCC_MRCC_GLB_CC4_ITRC0_SHIFT            (24U)
/*! ITRC0 - ITRC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC4_ITRC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_ITRC0_SHIFT)) & MRCC_MRCC_GLB_CC4_ITRC0_MASK)
/*! @} */

/*! @name MRCC_GLB_CC4_SET - AHB Clock Control Set 4 */
/*! @{ */

#define MRCC_MRCC_GLB_CC4_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC4_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC4_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC4_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC4_CLR - AHB Clock Control Clear 4 */
/*! @{ */

#define MRCC_MRCC_GLB_CC4_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC4_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC4_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC4_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC4_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC0 - Control Automatic Clock Gating 0 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC0_INPUTMUX0_MASK        (0x1U)
#define MRCC_MRCC_GLB_ACC0_INPUTMUX0_SHIFT       (0U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_INPUTMUX0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_INPUTMUX0_SHIFT)) & MRCC_MRCC_GLB_ACC0_INPUTMUX0_MASK)

#define MRCC_MRCC_GLB_ACC0_FREQME_MASK           (0x2U)
#define MRCC_MRCC_GLB_ACC0_FREQME_SHIFT          (1U)
/*! FREQME - FREQME
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_FREQME(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_FREQME_SHIFT)) & MRCC_MRCC_GLB_ACC0_FREQME_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER0_MASK          (0x4U)
#define MRCC_MRCC_GLB_ACC0_CTIMER0_SHIFT         (2U)
/*! CTIMER0 - CTIMER0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER0_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER0_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER1_MASK          (0x8U)
#define MRCC_MRCC_GLB_ACC0_CTIMER1_SHIFT         (3U)
/*! CTIMER1 - CTIMER1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER1_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER1_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER2_MASK          (0x10U)
#define MRCC_MRCC_GLB_ACC0_CTIMER2_SHIFT         (4U)
/*! CTIMER2 - CTIMER2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER2_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER2_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER3_MASK          (0x20U)
#define MRCC_MRCC_GLB_ACC0_CTIMER3_SHIFT         (5U)
/*! CTIMER3 - CTIMER3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER3_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER3_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER4_MASK          (0x40U)
#define MRCC_MRCC_GLB_ACC0_CTIMER4_SHIFT         (6U)
/*! CTIMER4 - CTIMER4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER4_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER4_MASK)

#define MRCC_MRCC_GLB_ACC0_UTICK0_MASK           (0x80U)
#define MRCC_MRCC_GLB_ACC0_UTICK0_SHIFT          (7U)
/*! UTICK0 - UTICK0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_UTICK0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_UTICK0_SHIFT)) & MRCC_MRCC_GLB_ACC0_UTICK0_MASK)

#define MRCC_MRCC_GLB_ACC0_WWDT0_MASK            (0x100U)
#define MRCC_MRCC_GLB_ACC0_WWDT0_SHIFT           (8U)
/*! WWDT0 - WWDT0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_WWDT0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_WWDT0_SHIFT)) & MRCC_MRCC_GLB_ACC0_WWDT0_MASK)

#define MRCC_MRCC_GLB_ACC0_WWDT1_MASK            (0x200U)
#define MRCC_MRCC_GLB_ACC0_WWDT1_SHIFT           (9U)
/*! WWDT1 - WWDT1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_WWDT1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_WWDT1_SHIFT)) & MRCC_MRCC_GLB_ACC0_WWDT1_MASK)

#define MRCC_MRCC_GLB_ACC0_DMA0_MASK             (0x400U)
#define MRCC_MRCC_GLB_ACC0_DMA0_SHIFT            (10U)
/*! DMA0 - DMA0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_DMA0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_DMA0_SHIFT)) & MRCC_MRCC_GLB_ACC0_DMA0_MASK)

#define MRCC_MRCC_GLB_ACC0_DMA1_MASK             (0x800U)
#define MRCC_MRCC_GLB_ACC0_DMA1_SHIFT            (11U)
/*! DMA1 - DMA1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_DMA1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_DMA1_SHIFT)) & MRCC_MRCC_GLB_ACC0_DMA1_MASK)

#define MRCC_MRCC_GLB_ACC0_AOI0_MASK             (0x1000U)
#define MRCC_MRCC_GLB_ACC0_AOI0_SHIFT            (12U)
/*! AOI0 - AOI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_AOI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_AOI0_SHIFT)) & MRCC_MRCC_GLB_ACC0_AOI0_MASK)

#define MRCC_MRCC_GLB_ACC0_CRC0_MASK             (0x4000U)
#define MRCC_MRCC_GLB_ACC0_CRC0_SHIFT            (14U)
/*! CRC0 - CRC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CRC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CRC0_SHIFT)) & MRCC_MRCC_GLB_ACC0_CRC0_MASK)

#define MRCC_MRCC_GLB_ACC0_EIM0_MASK             (0x8000U)
#define MRCC_MRCC_GLB_ACC0_EIM0_SHIFT            (15U)
/*! EIM0 - EIM0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_EIM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_EIM0_SHIFT)) & MRCC_MRCC_GLB_ACC0_EIM0_MASK)

#define MRCC_MRCC_GLB_ACC0_ERM0_MASK             (0x10000U)
#define MRCC_MRCC_GLB_ACC0_ERM0_SHIFT            (16U)
/*! ERM0 - ERM0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_ERM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_ERM0_SHIFT)) & MRCC_MRCC_GLB_ACC0_ERM0_MASK)

#define MRCC_MRCC_GLB_ACC0_FLEXIO0_MASK          (0x20000U)
#define MRCC_MRCC_GLB_ACC0_FLEXIO0_SHIFT         (17U)
/*! FLEXIO0 - FLEXIO0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_FLEXIO0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_FLEXIO0_SHIFT)) & MRCC_MRCC_GLB_ACC0_FLEXIO0_MASK)

#define MRCC_MRCC_GLB_ACC0_LPI2C0_MASK           (0x80000U)
#define MRCC_MRCC_GLB_ACC0_LPI2C0_SHIFT          (19U)
/*! LPI2C0 - LPI2C0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPI2C0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPI2C0_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPI2C0_MASK)

#define MRCC_MRCC_GLB_ACC0_LPI2C1_MASK           (0x100000U)
#define MRCC_MRCC_GLB_ACC0_LPI2C1_SHIFT          (20U)
/*! LPI2C1 - LPI2C1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPI2C1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPI2C1_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPI2C1_MASK)

#define MRCC_MRCC_GLB_ACC0_LPI2C2_MASK           (0x200000U)
#define MRCC_MRCC_GLB_ACC0_LPI2C2_SHIFT          (21U)
/*! LPI2C2 - LPI2C2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPI2C2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPI2C2_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPI2C2_MASK)

#define MRCC_MRCC_GLB_ACC0_LPI2C3_MASK           (0x400000U)
#define MRCC_MRCC_GLB_ACC0_LPI2C3_SHIFT          (22U)
/*! LPI2C3 - LPI2C3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPI2C3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPI2C3_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPI2C3_MASK)

#define MRCC_MRCC_GLB_ACC0_LPI2C4_MASK           (0x800000U)
#define MRCC_MRCC_GLB_ACC0_LPI2C4_SHIFT          (23U)
/*! LPI2C4 - LPI2C4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPI2C4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPI2C4_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPI2C4_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART0_MASK          (0x2000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART0_SHIFT         (25U)
/*! LPUART0 - LPUART0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART0_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART0_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART1_MASK          (0x4000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART1_SHIFT         (26U)
/*! LPUART1 - LPUART1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART1_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART1_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART2_MASK          (0x8000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART2_SHIFT         (27U)
/*! LPUART2 - LPUART2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART2_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART2_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART3_MASK          (0x10000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART3_SHIFT         (28U)
/*! LPUART3 - LPUART3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART3_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART3_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART4_MASK          (0x20000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART4_SHIFT         (29U)
/*! LPUART4 - LPUART4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART4_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART4_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART5_MASK          (0x40000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART5_SHIFT         (30U)
/*! LPUART5 - LPUART5
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART5(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART5_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART5_MASK)

#define MRCC_MRCC_GLB_ACC0_OSTIMER0_MASK         (0x80000000U)
#define MRCC_MRCC_GLB_ACC0_OSTIMER0_SHIFT        (31U)
/*! OSTIMER0 - OSTIMER0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_OSTIMER0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_OSTIMER0_SHIFT)) & MRCC_MRCC_GLB_ACC0_OSTIMER0_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC1 - Control Automatic Clock Gating 1 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC1_LPSPI0_MASK           (0x10U)
#define MRCC_MRCC_GLB_ACC1_LPSPI0_SHIFT          (4U)
/*! LPSPI0 - LPSPI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPSPI0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPSPI0_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPSPI0_MASK)

#define MRCC_MRCC_GLB_ACC1_LPSPI1_MASK           (0x20U)
#define MRCC_MRCC_GLB_ACC1_LPSPI1_SHIFT          (5U)
/*! LPSPI1 - LPSPI1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPSPI1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPSPI1_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPSPI1_MASK)

#define MRCC_MRCC_GLB_ACC1_LPSPI2_MASK           (0x40U)
#define MRCC_MRCC_GLB_ACC1_LPSPI2_SHIFT          (6U)
/*! LPSPI2 - LPSPI2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPSPI2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPSPI2_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPSPI2_MASK)

#define MRCC_MRCC_GLB_ACC1_LPSPI3_MASK           (0x80U)
#define MRCC_MRCC_GLB_ACC1_LPSPI3_SHIFT          (7U)
/*! LPSPI3 - LPSPI3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPSPI3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPSPI3_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPSPI3_MASK)

#define MRCC_MRCC_GLB_ACC1_LPSPI4_MASK           (0x100U)
#define MRCC_MRCC_GLB_ACC1_LPSPI4_SHIFT          (8U)
/*! LPSPI4 - LPSPI4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPSPI4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPSPI4_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPSPI4_MASK)

#define MRCC_MRCC_GLB_ACC1_LPSPI5_MASK           (0x200U)
#define MRCC_MRCC_GLB_ACC1_LPSPI5_SHIFT          (9U)
/*! LPSPI5 - LPSPI5
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPSPI5(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPSPI5_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPSPI5_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT0_MASK            (0x400U)
#define MRCC_MRCC_GLB_ACC1_PORT0_SHIFT           (10U)
/*! PORT0 - PORT0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT0_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT0_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT1_MASK            (0x800U)
#define MRCC_MRCC_GLB_ACC1_PORT1_SHIFT           (11U)
/*! PORT1 - PORT1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT1_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT1_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT2_MASK            (0x1000U)
#define MRCC_MRCC_GLB_ACC1_PORT2_SHIFT           (12U)
/*! PORT2 - PORT2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT2_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT2_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT3_MASK            (0x2000U)
#define MRCC_MRCC_GLB_ACC1_PORT3_SHIFT           (13U)
/*! PORT3 - PORT3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT3_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT3_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT4_MASK            (0x4000U)
#define MRCC_MRCC_GLB_ACC1_PORT4_SHIFT           (14U)
/*! PORT4 - PORT4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT4_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT4_MASK)

#define MRCC_MRCC_GLB_ACC1_ADC0_MASK             (0x10000U)
#define MRCC_MRCC_GLB_ACC1_ADC0_SHIFT            (16U)
/*! ADC0 - ADC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_ADC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_ADC0_SHIFT)) & MRCC_MRCC_GLB_ACC1_ADC0_MASK)

#define MRCC_MRCC_GLB_ACC1_ADC1_MASK             (0x20000U)
#define MRCC_MRCC_GLB_ACC1_ADC1_SHIFT            (17U)
/*! ADC1 - ADC1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_ADC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_ADC1_SHIFT)) & MRCC_MRCC_GLB_ACC1_ADC1_MASK)

#define MRCC_MRCC_GLB_ACC1_CMP0_MASK             (0x100000U)
#define MRCC_MRCC_GLB_ACC1_CMP0_SHIFT            (20U)
/*! CMP0 - CMP0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_CMP0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_CMP0_SHIFT)) & MRCC_MRCC_GLB_ACC1_CMP0_MASK)

#define MRCC_MRCC_GLB_ACC1_DAC0_MASK             (0x800000U)
#define MRCC_MRCC_GLB_ACC1_DAC0_SHIFT            (23U)
/*! DAC0 - DAC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_DAC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_DAC0_SHIFT)) & MRCC_MRCC_GLB_ACC1_DAC0_MASK)

#define MRCC_MRCC_GLB_ACC1_DAC1_MASK             (0x1000000U)
#define MRCC_MRCC_GLB_ACC1_DAC1_SHIFT            (24U)
/*! DAC1 - DAC1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_DAC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_DAC1_SHIFT)) & MRCC_MRCC_GLB_ACC1_DAC1_MASK)

#define MRCC_MRCC_GLB_ACC1_VREF0_MASK            (0x20000000U)
#define MRCC_MRCC_GLB_ACC1_VREF0_SHIFT           (29U)
/*! VREF0 - VREF0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_VREF0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_VREF0_SHIFT)) & MRCC_MRCC_GLB_ACC1_VREF0_MASK)

#define MRCC_MRCC_GLB_ACC1_TSI0_MASK             (0x80000000U)
#define MRCC_MRCC_GLB_ACC1_TSI0_SHIFT            (31U)
/*! TSI0 - TSI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_TSI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_TSI0_SHIFT)) & MRCC_MRCC_GLB_ACC1_TSI0_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC2 - Control Automatic Clock Gating 2 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC2_I3C0_MASK             (0x1U)
#define MRCC_MRCC_GLB_ACC2_I3C0_SHIFT            (0U)
/*! I3C0 - I3C0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_I3C0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_I3C0_SHIFT)) & MRCC_MRCC_GLB_ACC2_I3C0_MASK)

#define MRCC_MRCC_GLB_ACC2_I3C1_MASK             (0x2U)
#define MRCC_MRCC_GLB_ACC2_I3C1_SHIFT            (1U)
/*! I3C1 - I3C1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_I3C1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_I3C1_SHIFT)) & MRCC_MRCC_GLB_ACC2_I3C1_MASK)

#define MRCC_MRCC_GLB_ACC2_I3C2_MASK             (0x4U)
#define MRCC_MRCC_GLB_ACC2_I3C2_SHIFT            (2U)
/*! I3C2 - I3C2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_I3C2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_I3C2_SHIFT)) & MRCC_MRCC_GLB_ACC2_I3C2_MASK)

#define MRCC_MRCC_GLB_ACC2_I3C3_MASK             (0x8U)
#define MRCC_MRCC_GLB_ACC2_I3C3_SHIFT            (3U)
/*! I3C3 - I3C3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_I3C3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_I3C3_SHIFT)) & MRCC_MRCC_GLB_ACC2_I3C3_MASK)

#define MRCC_MRCC_GLB_ACC2_FLEXCAN0_MASK         (0x10U)
#define MRCC_MRCC_GLB_ACC2_FLEXCAN0_SHIFT        (4U)
/*! FLEXCAN0 - FLEXCAN0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_FLEXCAN0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_FLEXCAN0_SHIFT)) & MRCC_MRCC_GLB_ACC2_FLEXCAN0_MASK)

#define MRCC_MRCC_GLB_ACC2_FLEXCAN1_MASK         (0x20U)
#define MRCC_MRCC_GLB_ACC2_FLEXCAN1_SHIFT        (5U)
/*! FLEXCAN1 - FLEXCAN1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_FLEXCAN1(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_FLEXCAN1_SHIFT)) & MRCC_MRCC_GLB_ACC2_FLEXCAN1_MASK)

#define MRCC_MRCC_GLB_ACC2_E1588_MASK            (0x100U)
#define MRCC_MRCC_GLB_ACC2_E1588_SHIFT           (8U)
/*! E1588 - E1588
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_E1588(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_E1588_SHIFT)) & MRCC_MRCC_GLB_ACC2_E1588_MASK)

#define MRCC_MRCC_GLB_ACC2_RMII_MASK             (0x200U)
#define MRCC_MRCC_GLB_ACC2_RMII_SHIFT            (9U)
/*! RMII - RMII
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_RMII(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_RMII_SHIFT)) & MRCC_MRCC_GLB_ACC2_RMII_MASK)

#define MRCC_MRCC_GLB_ACC2_ENET0_MASK            (0x400U)
#define MRCC_MRCC_GLB_ACC2_ENET0_SHIFT           (10U)
/*! ENET0 - ENET0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_ENET0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_ENET0_SHIFT)) & MRCC_MRCC_GLB_ACC2_ENET0_MASK)

#define MRCC_MRCC_GLB_ACC2_T1S0_MASK             (0x800U)
#define MRCC_MRCC_GLB_ACC2_T1S0_SHIFT            (11U)
/*! T1S0 - T1S0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_T1S0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_T1S0_SHIFT)) & MRCC_MRCC_GLB_ACC2_T1S0_MASK)

#define MRCC_MRCC_GLB_ACC2_FLEXSPI0_MASK         (0x1000U)
#define MRCC_MRCC_GLB_ACC2_FLEXSPI0_SHIFT        (12U)
/*! FLEXSPI0 - FLEXSPI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_FLEXSPI0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_FLEXSPI0_SHIFT)) & MRCC_MRCC_GLB_ACC2_FLEXSPI0_MASK)

#define MRCC_MRCC_GLB_ACC2_SPI0_FILTER_MASK      (0x2000U)
#define MRCC_MRCC_GLB_ACC2_SPI0_FILTER_SHIFT     (13U)
/*! SPI0_FILTER - SPI0_FILTER
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_SPI0_FILTER(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_SPI0_FILTER_SHIFT)) & MRCC_MRCC_GLB_ACC2_SPI0_FILTER_MASK)

#define MRCC_MRCC_GLB_ACC2_ESPI0_MASK            (0x4000U)
#define MRCC_MRCC_GLB_ACC2_ESPI0_SHIFT           (14U)
/*! ESPI0 - ESPI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_ESPI0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_ESPI0_SHIFT)) & MRCC_MRCC_GLB_ACC2_ESPI0_MASK)

#define MRCC_MRCC_GLB_ACC2_USB1_MASK             (0x40000U)
#define MRCC_MRCC_GLB_ACC2_USB1_SHIFT            (18U)
/*! USB1 - USB1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_USB1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_USB1_SHIFT)) & MRCC_MRCC_GLB_ACC2_USB1_MASK)

#define MRCC_MRCC_GLB_ACC2_USB1_PHY_MASK         (0x80000U)
#define MRCC_MRCC_GLB_ACC2_USB1_PHY_SHIFT        (19U)
/*! USB1_PHY - USB1_PHY
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_USB1_PHY(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_USB1_PHY_SHIFT)) & MRCC_MRCC_GLB_ACC2_USB1_PHY_MASK)

#define MRCC_MRCC_GLB_ACC2_EWM0_MASK             (0x100000U)
#define MRCC_MRCC_GLB_ACC2_EWM0_SHIFT            (20U)
/*! EWM0 - EWM0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_EWM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_EWM0_SHIFT)) & MRCC_MRCC_GLB_ACC2_EWM0_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC3 - Control Automatic Clock Gating 3 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC3_RAMA_MASK             (0x10000U)
#define MRCC_MRCC_GLB_ACC3_RAMA_SHIFT            (16U)
/*! RAMA - RAMA
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_RAMA(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_RAMA_SHIFT)) & MRCC_MRCC_GLB_ACC3_RAMA_MASK)

#define MRCC_MRCC_GLB_ACC3_RAMB_MASK             (0x20000U)
#define MRCC_MRCC_GLB_ACC3_RAMB_SHIFT            (17U)
/*! RAMB - RAMB
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_RAMB(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_RAMB_SHIFT)) & MRCC_MRCC_GLB_ACC3_RAMB_MASK)

#define MRCC_MRCC_GLB_ACC3_GPIO0_MASK            (0x100000U)
#define MRCC_MRCC_GLB_ACC3_GPIO0_SHIFT           (20U)
/*! GPIO0 - GPIO0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_GPIO0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_GPIO0_SHIFT)) & MRCC_MRCC_GLB_ACC3_GPIO0_MASK)

#define MRCC_MRCC_GLB_ACC3_GPIO1_MASK            (0x200000U)
#define MRCC_MRCC_GLB_ACC3_GPIO1_SHIFT           (21U)
/*! GPIO1 - GPIO1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_GPIO1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_GPIO1_SHIFT)) & MRCC_MRCC_GLB_ACC3_GPIO1_MASK)

#define MRCC_MRCC_GLB_ACC3_GPIO2_MASK            (0x400000U)
#define MRCC_MRCC_GLB_ACC3_GPIO2_SHIFT           (22U)
/*! GPIO2 - GPIO2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_GPIO2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_GPIO2_SHIFT)) & MRCC_MRCC_GLB_ACC3_GPIO2_MASK)

#define MRCC_MRCC_GLB_ACC3_GPIO3_MASK            (0x800000U)
#define MRCC_MRCC_GLB_ACC3_GPIO3_SHIFT           (23U)
/*! GPIO3 - GPIO3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_GPIO3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_GPIO3_SHIFT)) & MRCC_MRCC_GLB_ACC3_GPIO3_MASK)

#define MRCC_MRCC_GLB_ACC3_GPIO4_MASK            (0x1000000U)
#define MRCC_MRCC_GLB_ACC3_GPIO4_SHIFT           (24U)
/*! GPIO4 - GPIO4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_GPIO4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_GPIO4_SHIFT)) & MRCC_MRCC_GLB_ACC3_GPIO4_MASK)

#define MRCC_MRCC_GLB_ACC3_ROMC_MASK             (0x10000000U)
#define MRCC_MRCC_GLB_ACC3_ROMC_SHIFT            (28U)
/*! ROMC - ROMC
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_ROMC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_ROMC_SHIFT)) & MRCC_MRCC_GLB_ACC3_ROMC_MASK)

#define MRCC_MRCC_GLB_ACC3_SMARTDMA0_MASK        (0x20000000U)
#define MRCC_MRCC_GLB_ACC3_SMARTDMA0_SHIFT       (29U)
/*! SMARTDMA0 - SMARTDMA0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC3_SMARTDMA0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC3_SMARTDMA0_SHIFT)) & MRCC_MRCC_GLB_ACC3_SMARTDMA0_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC4 - Control Automatic Clock Gating 4 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC4_SECCON_MASK           (0x10000U)
#define MRCC_MRCC_GLB_ACC4_SECCON_SHIFT          (16U)
/*! SECCON - SECCON
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC4_SECCON(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC4_SECCON_SHIFT)) & MRCC_MRCC_GLB_ACC4_SECCON_MASK)

#define MRCC_MRCC_GLB_ACC4_GLIKEY0_MASK          (0x20000U)
#define MRCC_MRCC_GLB_ACC4_GLIKEY0_SHIFT         (17U)
/*! GLIKEY0 - GLIKEY0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC4_GLIKEY0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC4_GLIKEY0_SHIFT)) & MRCC_MRCC_GLB_ACC4_GLIKEY0_MASK)

#define MRCC_MRCC_GLB_ACC4_PKC0_MASK             (0x80000U)
#define MRCC_MRCC_GLB_ACC4_PKC0_SHIFT            (19U)
/*! PKC0 - PKC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC4_PKC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC4_PKC0_SHIFT)) & MRCC_MRCC_GLB_ACC4_PKC0_MASK)

#define MRCC_MRCC_GLB_ACC4_SGI0_MASK             (0x100000U)
#define MRCC_MRCC_GLB_ACC4_SGI0_SHIFT            (20U)
/*! SGI0 - SGI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC4_SGI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC4_SGI0_SHIFT)) & MRCC_MRCC_GLB_ACC4_SGI0_MASK)

#define MRCC_MRCC_GLB_ACC4_TRNG0_MASK            (0x200000U)
#define MRCC_MRCC_GLB_ACC4_TRNG0_SHIFT           (21U)
/*! TRNG0 - TRNG0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC4_TRNG0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC4_TRNG0_SHIFT)) & MRCC_MRCC_GLB_ACC4_TRNG0_MASK)

#define MRCC_MRCC_GLB_ACC4_UDF0_MASK             (0x400000U)
#define MRCC_MRCC_GLB_ACC4_UDF0_SHIFT            (22U)
/*! UDF0 - UDF0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC4_UDF0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC4_UDF0_SHIFT)) & MRCC_MRCC_GLB_ACC4_UDF0_MASK)

#define MRCC_MRCC_GLB_ACC4_DGDET0_MASK           (0x800000U)
#define MRCC_MRCC_GLB_ACC4_DGDET0_SHIFT          (23U)
/*! DGDET0 - DGDET0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC4_DGDET0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC4_DGDET0_SHIFT)) & MRCC_MRCC_GLB_ACC4_DGDET0_MASK)
/*! @} */

/*! @name MRCC_I3C0_FCLK_CLKSEL - I3C0_FCLK clock selection control */
/*! @{ */

#define MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_MASK      (0x7U)
#define MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_SHIFT     (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_I3C0_FCLK_CLKDIV - I3C0_FCLK clock divider control */
/*! @{ */

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_MASK)

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_MASK)

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_MASK)

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_I3C1_FCLK_CLKSEL - I3C1_FCLK clock selection control */
/*! @{ */

#define MRCC_MRCC_I3C1_FCLK_CLKSEL_MUX_MASK      (0x7U)
#define MRCC_MRCC_I3C1_FCLK_CLKSEL_MUX_SHIFT     (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_I3C1_FCLK_CLKSEL_MUX(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C1_FCLK_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_I3C1_FCLK_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_I3C1_FCLK_CLKDIV - I3C1_FCLK clock divider control */
/*! @{ */

#define MRCC_MRCC_I3C1_FCLK_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C1_FCLK_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_I3C1_FCLK_CLKDIV_DIV_MASK)

#define MRCC_MRCC_I3C1_FCLK_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C1_FCLK_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_I3C1_FCLK_CLKDIV_RESET_MASK)

#define MRCC_MRCC_I3C1_FCLK_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C1_FCLK_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_I3C1_FCLK_CLKDIV_HALT_MASK)

#define MRCC_MRCC_I3C1_FCLK_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_I3C1_FCLK_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C1_FCLK_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_I3C1_FCLK_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER0_CLKSEL - CTIMER0 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER0_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER0_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER0_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER0_CLKDIV - CTIMER0 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER0_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER0_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER0_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER0_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER0_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER0_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER0_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER0_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER0_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER1_CLKSEL - CTIMER1 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER1_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER1_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER1_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER1_CLKDIV - CTIMER1 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER1_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER1_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER1_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER1_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER1_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER1_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER1_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER1_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER1_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER2_CLKSEL - CTIMER2 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER2_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER2_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER2_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER2_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER2_CLKDIV - CTIMER2 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER2_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER2_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER2_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER2_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER2_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER2_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER2_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER2_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER2_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER3_CLKSEL - CTIMER3 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER3_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER3_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER3_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER3_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER3_CLKDIV - CTIMER3 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER3_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER3_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER3_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER3_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER3_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER3_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER3_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER3_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER3_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER4_CLKSEL - CTIMER4 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER4_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER4_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER4_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER4_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER4_CLKDIV - CTIMER4 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER4_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER4_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER4_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER4_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER4_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER4_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER4_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER4_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER4_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_WWDT0_CLKDIV - WWDT0 clock divider control */
/*! @{ */

#define MRCC_MRCC_WWDT0_CLKDIV_DIV_MASK          (0xFU)
#define MRCC_MRCC_WWDT0_CLKDIV_DIV_SHIFT         (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_WWDT0_CLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_WWDT0_CLKDIV_RESET_MASK        (0x20000000U)
#define MRCC_MRCC_WWDT0_CLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_WWDT0_CLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_WWDT0_CLKDIV_HALT_MASK         (0x40000000U)
#define MRCC_MRCC_WWDT0_CLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_WWDT0_CLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_MASK       (0x80000000U)
#define MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_SHIFT      (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_WWDT0_CLKDIV_UNSTAB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_WWDT1_CLKSEL - WWDT1 clock selection control */
/*! @{ */

#define MRCC_MRCC_WWDT1_CLKSEL_MUX_MASK          (0x3U)
#define MRCC_MRCC_WWDT1_CLKSEL_MUX_SHIFT         (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CLK_16K
 *  0b01..FRO_HF_DIV
 *  0b10..CLK_1M
 *  0b11..CLK_1M
 */
#define MRCC_MRCC_WWDT1_CLKSEL_MUX(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_WWDT1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_WWDT1_CLKDIV - WWDT1 clock divider control */
/*! @{ */

#define MRCC_MRCC_WWDT1_CLKDIV_DIV_MASK          (0xFU)
#define MRCC_MRCC_WWDT1_CLKDIV_DIV_SHIFT         (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_WWDT1_CLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_WWDT1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_WWDT1_CLKDIV_RESET_MASK        (0x20000000U)
#define MRCC_MRCC_WWDT1_CLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_WWDT1_CLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_WWDT1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_WWDT1_CLKDIV_HALT_MASK         (0x40000000U)
#define MRCC_MRCC_WWDT1_CLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_WWDT1_CLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_WWDT1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_WWDT1_CLKDIV_UNSTAB_MASK       (0x80000000U)
#define MRCC_MRCC_WWDT1_CLKDIV_UNSTAB_SHIFT      (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_WWDT1_CLKDIV_UNSTAB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_WWDT1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_E1588_CLKSEL - E1588 clock selection control */
/*! @{ */

#define MRCC_MRCC_E1588_CLKSEL_MUX_MASK          (0x7U)
#define MRCC_MRCC_E1588_CLKSEL_MUX_SHIFT         (0U)
/*! MUX - Functional Clock Mux Select
 *  0b011..CLK_IN
 *  0b100..ENET0_TX_CLK
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_E1588_CLKSEL_MUX(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_E1588_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_E1588_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_E1588_CLKDIV - E1588 clock divider control */
/*! @{ */

#define MRCC_MRCC_E1588_CLKDIV_DIV_MASK          (0xFU)
#define MRCC_MRCC_E1588_CLKDIV_DIV_SHIFT         (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_E1588_CLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_E1588_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_E1588_CLKDIV_DIV_MASK)

#define MRCC_MRCC_E1588_CLKDIV_RESET_MASK        (0x20000000U)
#define MRCC_MRCC_E1588_CLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_E1588_CLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_E1588_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_E1588_CLKDIV_RESET_MASK)

#define MRCC_MRCC_E1588_CLKDIV_HALT_MASK         (0x40000000U)
#define MRCC_MRCC_E1588_CLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_E1588_CLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_E1588_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_E1588_CLKDIV_HALT_MASK)

#define MRCC_MRCC_E1588_CLKDIV_UNSTAB_MASK       (0x80000000U)
#define MRCC_MRCC_E1588_CLKDIV_UNSTAB_SHIFT      (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_E1588_CLKDIV_UNSTAB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_E1588_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_E1588_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_RMII_CLKSEL - RMII clock selection control */
/*! @{ */

#define MRCC_MRCC_RMII_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_RMII_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b011..CLK_IN
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_RMII_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_RMII_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_RMII_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_RMII_CLKDIV - RMII clock divider control */
/*! @{ */

#define MRCC_MRCC_RMII_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_RMII_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_RMII_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_RMII_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_RMII_CLKDIV_DIV_MASK)

#define MRCC_MRCC_RMII_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_RMII_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_RMII_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_RMII_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_RMII_CLKDIV_RESET_MASK)

#define MRCC_MRCC_RMII_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_RMII_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_RMII_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_RMII_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_RMII_CLKDIV_HALT_MASK)

#define MRCC_MRCC_RMII_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_RMII_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_RMII_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_RMII_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_RMII_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_ESPI0_CLKSEL - ESPI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_ESPI0_CLKSEL_MUX_MASK          (0x7U)
#define MRCC_MRCC_ESPI0_CLKSEL_MUX_SHIFT         (0U)
/*! MUX - Functional Clock Mux Select
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..USB_PLL_CLK
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_ESPI0_CLKSEL_MUX(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ESPI0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_ESPI0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_ESPI0_CLKDIV - ESPI0 clock divider control */
/*! @{ */

#define MRCC_MRCC_ESPI0_CLKDIV_DIV_MASK          (0xFU)
#define MRCC_MRCC_ESPI0_CLKDIV_DIV_SHIFT         (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_ESPI0_CLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ESPI0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_ESPI0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_ESPI0_CLKDIV_RESET_MASK        (0x20000000U)
#define MRCC_MRCC_ESPI0_CLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_ESPI0_CLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ESPI0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_ESPI0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_ESPI0_CLKDIV_HALT_MASK         (0x40000000U)
#define MRCC_MRCC_ESPI0_CLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_ESPI0_CLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ESPI0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_ESPI0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_ESPI0_CLKDIV_UNSTAB_MASK       (0x80000000U)
#define MRCC_MRCC_ESPI0_CLKDIV_UNSTAB_SHIFT      (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_ESPI0_CLKDIV_UNSTAB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ESPI0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_ESPI0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXSPI0_CLKSEL - FLEXSPI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXSPI0_CLKSEL_MUX_MASK       (0x7U)
#define MRCC_MRCC_FLEXSPI0_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b001..FRO_HF_GATED
 *  0b100..USB_PFD_CLK
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_FLEXSPI0_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXSPI0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXSPI0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_FLEXSPI0_CLKDIV - FLEXSPI0 clock divider control */
/*! @{ */

#define MRCC_MRCC_FLEXSPI0_CLKDIV_DIV_MASK       (0xFU)
#define MRCC_MRCC_FLEXSPI0_CLKDIV_DIV_SHIFT      (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXSPI0_CLKDIV_DIV(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXSPI0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FLEXSPI0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FLEXSPI0_CLKDIV_RESET_MASK     (0x20000000U)
#define MRCC_MRCC_FLEXSPI0_CLKDIV_RESET_SHIFT    (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FLEXSPI0_CLKDIV_RESET(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXSPI0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FLEXSPI0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FLEXSPI0_CLKDIV_HALT_MASK      (0x40000000U)
#define MRCC_MRCC_FLEXSPI0_CLKDIV_HALT_SHIFT     (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FLEXSPI0_CLKDIV_HALT(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXSPI0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FLEXSPI0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FLEXSPI0_CLKDIV_UNSTAB_MASK    (0x80000000U)
#define MRCC_MRCC_FLEXSPI0_CLKDIV_UNSTAB_SHIFT   (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXSPI0_CLKDIV_UNSTAB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXSPI0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXSPI0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI2_CLKSEL - LPSPI2 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI2_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI2_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI2_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI2_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI2_CLKDIV - LPSPI2 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI2_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI2_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI2_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI2_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI2_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI2_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI2_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI2_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI2_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI3_CLKSEL - LPSPI3 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI3_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI3_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI3_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI3_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI3_CLKDIV - LPSPI3 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI3_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI3_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI3_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI3_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI3_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI3_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI3_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI3_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI3_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI3_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI3_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI3_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI4_CLKSEL - LPSPI4 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI4_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI4_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI4_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI4_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI4_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI4_CLKDIV - LPSPI4 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI4_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI4_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI4_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI4_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI4_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI4_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI4_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI4_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI4_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI4_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI4_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI4_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI4_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI4_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI4_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI4_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI4_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI4_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI4_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI4_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI5_CLKSEL - LPSPI5 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI5_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI5_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI5_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI5_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI5_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI5_CLKDIV - LPSPI5 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI5_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI5_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI5_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI5_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI5_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI5_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI5_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI5_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI5_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI5_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI5_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI5_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI5_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI5_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI5_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI5_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI5_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI5_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI5_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI5_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_T1S0_CLKSEL - T1S0 clock selection control */
/*! @{ */

#define MRCC_MRCC_T1S0_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_T1S0_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b011..CLK_IN
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_T1S0_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_T1S0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_T1S0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_T1S0_CLKDIV - T1S0 clock divider control */
/*! @{ */

#define MRCC_MRCC_T1S0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_T1S0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_T1S0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_T1S0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_T1S0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_T1S0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_T1S0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_T1S0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_T1S0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_T1S0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_T1S0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_T1S0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_T1S0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_T1S0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_T1S0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_T1S0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_T1S0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_T1S0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_T1S0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_T1S0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_USB1_CLKSEL - USB1 clock selection control */
/*! @{ */

#define MRCC_MRCC_USB1_CLKSEL_MUX_MASK           (0x3U)
#define MRCC_MRCC_USB1_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CLK_32K
 *  0b01..CLK_1M
 *  0b10..CLK__usbhs0_phy__clk_xtal
 *  0b11..Reserved(NO Clock)
 */
#define MRCC_MRCC_USB1_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_USB1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_USB1_PHY_CLKSEL - USB1_PHY clock selection control */
/*! @{ */

#define MRCC_MRCC_USB1_PHY_CLKSEL_MUX_MASK       (0x3U)
#define MRCC_MRCC_USB1_PHY_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b01..FRO_HF_GATED
 *  0b10..CLK_IN
 *  0b11..Reserved(NO Clock)
 */
#define MRCC_MRCC_USB1_PHY_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB1_PHY_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_USB1_PHY_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_USB1_PHY_CLKDIV - USB1_PHY clock divider control */
/*! @{ */

#define MRCC_MRCC_USB1_PHY_CLKDIV_DIV_MASK       (0xFU)
#define MRCC_MRCC_USB1_PHY_CLKDIV_DIV_SHIFT      (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_USB1_PHY_CLKDIV_DIV(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB1_PHY_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_USB1_PHY_CLKDIV_DIV_MASK)

#define MRCC_MRCC_USB1_PHY_CLKDIV_RESET_MASK     (0x20000000U)
#define MRCC_MRCC_USB1_PHY_CLKDIV_RESET_SHIFT    (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_USB1_PHY_CLKDIV_RESET(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB1_PHY_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_USB1_PHY_CLKDIV_RESET_MASK)

#define MRCC_MRCC_USB1_PHY_CLKDIV_HALT_MASK      (0x40000000U)
#define MRCC_MRCC_USB1_PHY_CLKDIV_HALT_SHIFT     (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_USB1_PHY_CLKDIV_HALT(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB1_PHY_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_USB1_PHY_CLKDIV_HALT_MASK)

#define MRCC_MRCC_USB1_PHY_CLKDIV_UNSTAB_MASK    (0x80000000U)
#define MRCC_MRCC_USB1_PHY_CLKDIV_UNSTAB_SHIFT   (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_USB1_PHY_CLKDIV_UNSTAB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB1_PHY_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_USB1_PHY_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXIO0_CLKSEL - FLEXIO0 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXIO0_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_FLEXIO0_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_FLEXIO0_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_FLEXIO0_CLKDIV - FLEXIO0 clock divider control */
/*! @{ */

#define MRCC_MRCC_FLEXIO0_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_FLEXIO0_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXIO0_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FLEXIO0_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_FLEXIO0_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FLEXIO0_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FLEXIO0_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_FLEXIO0_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FLEXIO0_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C0_CLKSEL - LPI2C0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C0_CLKDIV - LPI2C0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C0_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C0_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C0_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C0_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C0_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C0_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C0_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C0_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C0_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C1_CLKSEL - LPI2C1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C1_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C1_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C1_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C1_CLKDIV - LPI2C1 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C1_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C1_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C1_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C1_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C1_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C1_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C1_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C1_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C1_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI0_CLKSEL - LPSPI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI0_CLKDIV - LPSPI0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI0_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI0_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI0_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI0_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI0_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI0_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI0_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI0_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI0_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI1_CLKSEL - LPSPI1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI1_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI1_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI1_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI1_CLKDIV - LPSPI1 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI1_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI1_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI1_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI1_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI1_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI1_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI1_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI1_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI1_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_I3C2_FCLK_CLKSEL - I3C2_FCLK clock selection control */
/*! @{ */

#define MRCC_MRCC_I3C2_FCLK_CLKSEL_MUX_MASK      (0x7U)
#define MRCC_MRCC_I3C2_FCLK_CLKSEL_MUX_SHIFT     (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_I3C2_FCLK_CLKSEL_MUX(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C2_FCLK_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_I3C2_FCLK_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_I3C2_FCLK_CLKDIV - I3C2_FCLK clock divider control */
/*! @{ */

#define MRCC_MRCC_I3C2_FCLK_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C2_FCLK_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_I3C2_FCLK_CLKDIV_DIV_MASK)

#define MRCC_MRCC_I3C2_FCLK_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C2_FCLK_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_I3C2_FCLK_CLKDIV_RESET_MASK)

#define MRCC_MRCC_I3C2_FCLK_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C2_FCLK_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_I3C2_FCLK_CLKDIV_HALT_MASK)

#define MRCC_MRCC_I3C2_FCLK_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_I3C2_FCLK_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C2_FCLK_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_I3C2_FCLK_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART0_CLKSEL - LPUART0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART0_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART0_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART0_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART0_CLKDIV - LPUART0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART0_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART0_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART0_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART0_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART0_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART0_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART0_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART0_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART0_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART0_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART1_CLKSEL - LPUART1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART1_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART1_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART1_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART1_CLKDIV - LPUART1 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART1_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART1_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART1_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART1_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART1_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART1_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART1_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART1_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART1_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART1_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART2_CLKSEL - LPUART2 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART2_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART2_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART2_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART2_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART2_CLKDIV - LPUART2 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART2_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART2_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART2_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART2_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART2_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART2_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART2_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART2_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART2_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART2_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART3_CLKSEL - LPUART3 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART3_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART3_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART3_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART3_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART3_CLKDIV - LPUART3 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART3_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART3_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART3_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART3_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART3_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART3_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART3_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART3_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART3_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART3_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART4_CLKSEL - LPUART4 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART4_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART4_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART4_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART4_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART4_CLKDIV - LPUART4 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART4_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART4_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART4_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART4_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART4_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART4_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART4_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART4_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART4_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART4_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPTMR0_CLKSEL - LPTMR0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPTMR0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPTMR0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPTMR0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPTMR0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPTMR0_CLKDIV - LPTMR0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPTMR0_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPTMR0_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPTMR0_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPTMR0_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPTMR0_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPTMR0_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPTMR0_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPTMR0_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPTMR0_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_OSTIMER0_CLKSEL - OSTIMER0 clock selection control */
/*! @{ */

#define MRCC_MRCC_OSTIMER0_CLKSEL_MUX_MASK       (0x3U)
#define MRCC_MRCC_OSTIMER0_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CLK_16K
 *  0b01..CLK_32K
 *  0b10..CLK_1M
 *  0b11..Reserved(NO Clock)
 */
#define MRCC_MRCC_OSTIMER0_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_OSTIMER0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_OSTIMER0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_ADC_CLKSEL - ADCx clock selection control */
/*! @{ */

#define MRCC_MRCC_ADC_CLKSEL_MUX_MASK            (0x7U)
#define MRCC_MRCC_ADC_CLKSEL_MUX_SHIFT           (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..USB_PFD_CLK
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_ADC_CLKSEL_MUX(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_ADC_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_ADC_CLKDIV - ADCx clock divider control */
/*! @{ */

#define MRCC_MRCC_ADC_CLKDIV_DIV_MASK            (0xFU)
#define MRCC_MRCC_ADC_CLKDIV_DIV_SHIFT           (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_ADC_CLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_DIV_MASK)

#define MRCC_MRCC_ADC_CLKDIV_RESET_MASK          (0x20000000U)
#define MRCC_MRCC_ADC_CLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_ADC_CLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_RESET_MASK)

#define MRCC_MRCC_ADC_CLKDIV_HALT_MASK           (0x40000000U)
#define MRCC_MRCC_ADC_CLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_ADC_CLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_HALT_MASK)

#define MRCC_MRCC_ADC_CLKDIV_UNSTAB_MASK         (0x80000000U)
#define MRCC_MRCC_ADC_CLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_ADC_CLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP0_FUNC_CLKDIV - CMP0_FUNC clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP0_RR_CLKSEL - CMP0_RR clock selection control */
/*! @{ */

#define MRCC_MRCC_CMP0_RR_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CMP0_RR_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CMP0_RR_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CMP0_RR_CLKDIV - CMP0_RR clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP0_RR_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CMP0_RR_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP0_RR_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP0_RR_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CMP0_RR_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP0_RR_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP0_RR_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CMP0_RR_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP0_RR_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_DAC0_CLKSEL - DAC0 clock selection control */
/*! @{ */

#define MRCC_MRCC_DAC0_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_DAC0_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_DAC0_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_DAC0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_DAC0_CLKDIV - DAC0 clock divider control */
/*! @{ */

#define MRCC_MRCC_DAC0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_DAC0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_DAC0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_DAC0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_DAC0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_DAC0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_DAC0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_DAC0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_DAC0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_DAC0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_DAC0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_DAC0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_DAC1_CLKSEL - DAC1 clock selection control */
/*! @{ */

#define MRCC_MRCC_DAC1_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_DAC1_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_DAC1_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_DAC1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_DAC1_CLKDIV - DAC1 clock divider control */
/*! @{ */

#define MRCC_MRCC_DAC1_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_DAC1_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_DAC1_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_DAC1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_DAC1_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_DAC1_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_DAC1_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_DAC1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_DAC1_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_DAC1_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_DAC1_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_DAC1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_DAC1_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_DAC1_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_DAC1_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_DAC1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_TSI0_CLKSEL - TSI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_TSI0_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_TSI0_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_TSI0_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSI0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_TSI0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_TSI0_CLKDIV - TSI0 clock divider control */
/*! @{ */

#define MRCC_MRCC_TSI0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_TSI0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TSI0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSI0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_TSI0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_TSI0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_TSI0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_TSI0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSI0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_TSI0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_TSI0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_TSI0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_TSI0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSI0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_TSI0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_TSI0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_TSI0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_TSI0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSI0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_TSI0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN0_CLKSEL - FLEXCAN0 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_MASK       (0x7U)
#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b001..FRO_HF_GATED
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..USB_PLL_CLK
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN0_CLKDIV - FLEXCAN0 clock divider control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_MASK       (0xFU)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_SHIFT      (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_DIV(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_MASK     (0x20000000U)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_SHIFT    (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_RESET(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_MASK      (0x40000000U)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_SHIFT     (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_HALT(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_MASK    (0x80000000U)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_SHIFT   (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN1_CLKSEL - FLEXCAN1 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_MASK       (0x7U)
#define MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b001..FRO_HF_GATED
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..USB_PLL_CLK
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_FLEXCAN1_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN1_CLKDIV - FLEXCAN1 clock divider control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_MASK       (0xFU)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_SHIFT      (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_DIV(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_MASK     (0x20000000U)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_SHIFT    (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_RESET(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_MASK      (0x40000000U)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_SHIFT     (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_HALT(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_MASK    (0x80000000U)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_SHIFT   (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C2_CLKSEL - LPI2C2 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C2_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C2_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C2_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C2_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C2_CLKDIV - LPI2C2 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C2_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C2_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C2_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C2_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C2_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C2_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C2_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C2_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C2_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C3_CLKSEL - LPI2C3 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C3_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C3_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C3_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C3_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C3_CLKDIV - LPI2C3 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C3_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C3_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C3_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C3_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C3_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C3_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C3_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C3_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C3_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C4_CLKSEL - LPI2C4 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C4_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C4_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C4_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C4_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C4_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C4_CLKDIV - LPI2C4 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C4_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C4_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C4_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C4_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C4_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C4_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C4_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C4_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C4_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C4_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C4_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C4_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C4_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C4_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C4_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C4_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C4_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C4_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C4_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C4_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART5_CLKSEL - LPUART5 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART5_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART5_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..LP_OSC
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART5_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART5_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART5_CLKDIV - LPUART5 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART5_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART5_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART5_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART5_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART5_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART5_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART5_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART5_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART5_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART5_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_I3C3_FCLK_CLKSEL - I3C3_FCLK clock selection control */
/*! @{ */

#define MRCC_MRCC_I3C3_FCLK_CLKSEL_MUX_MASK      (0x7U)
#define MRCC_MRCC_I3C3_FCLK_CLKSEL_MUX_SHIFT     (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_I3C3_FCLK_CLKSEL_MUX(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C3_FCLK_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_I3C3_FCLK_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_I3C3_FCLK_CLKDIV - I3C3_FCLK clock divider control */
/*! @{ */

#define MRCC_MRCC_I3C3_FCLK_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C3_FCLK_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_I3C3_FCLK_CLKDIV_DIV_MASK)

#define MRCC_MRCC_I3C3_FCLK_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C3_FCLK_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_I3C3_FCLK_CLKDIV_RESET_MASK)

#define MRCC_MRCC_I3C3_FCLK_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C3_FCLK_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_I3C3_FCLK_CLKDIV_HALT_MASK)

#define MRCC_MRCC_I3C3_FCLK_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_I3C3_FCLK_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C3_FCLK_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_I3C3_FCLK_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_DBG_TRACE_CLKSEL - DBG_TRACE clock selection control */
/*! @{ */

#define MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_MASK      (0x3U)
#define MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_SHIFT     (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CPU_CLK
 *  0b01..CLK_1M
 *  0b10..CLK_16K
 *  0b11..Reserved(NO Clock)
 */
#define MRCC_MRCC_DBG_TRACE_CLKSEL_MUX(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_DBG_TRACE_CLKDIV - DBG_TRACE clock divider control */
/*! @{ */

#define MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_MASK)

#define MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_MASK)

#define MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_MASK)

#define MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CLKOUT_CLKSEL - CLKOUT clock selection control */
/*! @{ */

#define MRCC_MRCC_CLKOUT_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_CLKOUT_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_12M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..LP_OSC
 *  0b101..PLL1_CLK_DIV
 *  0b110..SLOW_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CLKOUT_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CLKOUT_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CLKOUT_CLKDIV - CLKOUT clock divider control */
/*! @{ */

#define MRCC_MRCC_CLKOUT_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_CLKOUT_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CLKOUT_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CLKOUT_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_CLKOUT_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CLKOUT_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CLKOUT_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_CLKOUT_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CLKOUT_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_SYSTICK_CLKSEL - SYSTICK clock selection control */
/*! @{ */

#define MRCC_MRCC_SYSTICK_CLKSEL_MUX_MASK        (0x3U)
#define MRCC_MRCC_SYSTICK_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CPU_CLK
 *  0b01..CLK_1M
 *  0b10..CLK_16K
 *  0b11..Reserved(NO Clock)
 */
#define MRCC_MRCC_SYSTICK_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_SYSTICK_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_SYSTICK_CLKDIV - SYSTICK clock divider control */
/*! @{ */

#define MRCC_MRCC_SYSTICK_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_SYSTICK_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_SYSTICK_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_DIV_MASK)

#define MRCC_MRCC_SYSTICK_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_SYSTICK_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_SYSTICK_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_RESET_MASK)

#define MRCC_MRCC_SYSTICK_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_SYSTICK_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_SYSTICK_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_HALT_MASK)

#define MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRCC_Register_Masks */


/*!
 * @}
 */ /* end of group MRCC_Peripheral_Access_Layer */


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


#endif  /* PERI_MRCC_H_ */

