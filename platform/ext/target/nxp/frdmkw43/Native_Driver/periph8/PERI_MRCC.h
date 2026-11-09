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
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_MRCC.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for MRCC
 *
 * CMSIS Peripheral Access Layer for MRCC
 */

#if !defined(PERI_MRCC_H_)
#define PERI_MRCC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- MRCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Peripheral_Access_Layer MRCC Peripheral Access Layer
 * @{
 */

/** MRCC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[160];
  __IO uint32_t MRCC_ADC0_CLKSEL;                  /**< ADC0 clock selection control, offset: 0xA0 */
  __IO uint32_t MRCC_ADC0_CLKDIV;                  /**< ADC0 clock divider control, offset: 0xA4 */
  __IO uint32_t MRCC_AOI0_CLKSEL;                  /**< AOI0 clock selection control, offset: 0xA8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MRCC_ATX0_CLKSEL;                  /**< ATX0 clock selection control, offset: 0xB0 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MRCC_CLK_1M_CLKSEL;                /**< CLK_1M clock selection control, offset: 0xB8 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MRCC_CLK_6M_CLKSEL;                /**< CLK_6M clock selection control, offset: 0xC0 */
       uint8_t RESERVED_4[4];
  __IO uint32_t MRCC_CLK_32M_CLKSEL;               /**< CLK_32M clock selection control, offset: 0xC8 */
       uint8_t RESERVED_5[4];
  __IO uint32_t MRCC_CMP0_CLKSEL;                  /**< CMP0 clock selection control, offset: 0xD0 */
       uint8_t RESERVED_6[4];
  __IO uint32_t MRCC_CRC0_CLKSEL;                  /**< CRC0 clock selection control, offset: 0xD8 */
       uint8_t RESERVED_7[4];
  __IO uint32_t MRCC_CRC1_CLKSEL;                  /**< CRC1 clock selection control, offset: 0xE0 */
       uint8_t RESERVED_8[4];
  __IO uint32_t MRCC_DATA_STREAM_2P4_CLKSEL;       /**< DATA_STREAM_2P4 clock selection control, offset: 0xE8 */
       uint8_t RESERVED_9[4];
  __IO uint32_t MRCC_DMA_CLKSEL;                   /**< DMA clock selection control, offset: 0xF0 */
       uint8_t RESERVED_10[4];
  __IO uint32_t MRCC_DSP_RAMC0_CLKSEL;             /**< DSP_RAMC0 clock selection control, offset: 0xF8 */
       uint8_t RESERVED_11[4];
  __IO uint32_t MRCC_EDT_CC_CLKSEL;                /**< EDT_CC clock selection control, offset: 0x100 */
       uint8_t RESERVED_12[4];
  __IO uint32_t MRCC_EWM0_CLKSEL;                  /**< EWM0 clock selection control, offset: 0x108 */
  __IO uint32_t MRCC_EWM0_CLKDIV;                  /**< EWM0 clock divider control, offset: 0x10C */
  __IO uint32_t MRCC_EZRAMC_RAM0_CLKSEL;           /**< EZRAMC_RAM0 clock selection control, offset: 0x110 */
       uint8_t RESERVED_13[4];
  __IO uint32_t MRCC_EZRAMC_RAM1_CLKSEL;           /**< EZRAMC_RAM1 clock selection control, offset: 0x118 */
       uint8_t RESERVED_14[4];
  __IO uint32_t MRCC_EZRAMC_RAM2_CLKSEL;           /**< EZRAMC_RAM2 clock selection control, offset: 0x120 */
       uint8_t RESERVED_15[4];
  __IO uint32_t MRCC_EZRAMC_RAM3_CLKSEL;           /**< EZRAMC_RAM3 clock selection control, offset: 0x128 */
       uint8_t RESERVED_16[4];
  __IO uint32_t MRCC_FLEXCAN0_CLKSEL;              /**< FLEXCAN0 clock selection control, offset: 0x130 */
  __IO uint32_t MRCC_FLEXCAN0_CLKDIV;              /**< FLEXCAN0 clock divider control, offset: 0x134 */
  __IO uint32_t MRCC_FLEXPWM0_CLKSEL;              /**< FLEXPWM0 clock selection control, offset: 0x138 */
       uint8_t RESERVED_17[4];
  __IO uint32_t MRCC_FMC_CLKSEL;                   /**< FMC clock selection control, offset: 0x140 */
       uint8_t RESERVED_18[4];
  __IO uint32_t MRCC_FRO200M_CLKSEL;               /**< FRO200M clock selection control, offset: 0x148 */
       uint8_t RESERVED_19[4];
  __IO uint32_t MRCC_FRO_HF_DIV_CLKSEL;            /**< FRO_HF_DIV clock selection control, offset: 0x150 */
  __IO uint32_t MRCC_FRO_HF_DIV_CLKDIV;            /**< FRO_HF_DIV clock divider control, offset: 0x154 */
  __IO uint32_t MRCC_GDET_WRAPPER_CLKSEL;          /**< GDET_WRAPPER clock selection control, offset: 0x158 */
  __IO uint32_t MRCC_GDET_WRAPPER_CLKDIV;          /**< GDET_WRAPPER clock divider control, offset: 0x15C */
  __IO uint32_t MRCC_GPIOA_CLKSEL;                 /**< GPIOA clock selection control, offset: 0x160 */
       uint8_t RESERVED_20[4];
  __IO uint32_t MRCC_GPIOB_CLKSEL;                 /**< GPIOB clock selection control, offset: 0x168 */
       uint8_t RESERVED_21[4];
  __IO uint32_t MRCC_GPIOC_CLKSEL;                 /**< GPIOC clock selection control, offset: 0x170 */
       uint8_t RESERVED_22[4];
  __IO uint32_t MRCC_INTM_CLKSEL;                  /**< INTM clock selection control, offset: 0x178 */
       uint8_t RESERVED_23[4];
  __IO uint32_t MRCC_IPSYNC_TRNG0_CLKSEL;          /**< IPSYNC_TRNG0 clock selection control, offset: 0x180 */
       uint8_t RESERVED_24[4];
  __IO uint32_t MRCC_ITRC_WRAPPER_CLKSEL;          /**< ITRC_WRAPPER clock selection control, offset: 0x188 */
       uint8_t RESERVED_25[4];
  __IO uint32_t MRCC_LPI2C0_CLKSEL;                /**< LPI2C0 clock selection control, offset: 0x190 */
  __IO uint32_t MRCC_LPI2C0_CLKDIV;                /**< LPI2C0 clock divider control, offset: 0x194 */
  __IO uint32_t MRCC_LPI2C1_CLKSEL;                /**< LPI2C1 clock selection control, offset: 0x198 */
  __IO uint32_t MRCC_LPI2C1_CLKDIV;                /**< LPI2C1 clock divider control, offset: 0x19C */
  __IO uint32_t MRCC_LPIT0_CLKSEL;                 /**< LPIT0 clock selection control, offset: 0x1A0 */
  __IO uint32_t MRCC_LPIT0_CLKDIV;                 /**< LPIT0 clock divider control, offset: 0x1A4 */
  __IO uint32_t MRCC_LPSPI0_CLKSEL;                /**< LPSPI0 clock selection control, offset: 0x1A8 */
  __IO uint32_t MRCC_LPSPI0_CLKDIV;                /**< LPSPI0 clock divider control, offset: 0x1AC */
  __IO uint32_t MRCC_LPSPI1_CLKSEL;                /**< LPSPI1 clock selection control, offset: 0x1B0 */
  __IO uint32_t MRCC_LPSPI1_CLKDIV;                /**< LPSPI1 clock divider control, offset: 0x1B4 */
  __IO uint32_t MRCC_LPSPI2_CLKSEL;                /**< LPSPI2 clock selection control, offset: 0x1B8 */
  __IO uint32_t MRCC_LPSPI2_CLKDIV;                /**< LPSPI2 clock divider control, offset: 0x1BC */
  __IO uint32_t MRCC_LPTMR0_CLKSEL;                /**< LPTMR0 clock selection control, offset: 0x1C0 */
  __IO uint32_t MRCC_LPTMR0_CLKDIV;                /**< LPTMR0 clock divider control, offset: 0x1C4 */
  __IO uint32_t MRCC_LPTMR1_CLKSEL;                /**< LPTMR1 clock selection control, offset: 0x1C8 */
  __IO uint32_t MRCC_LPTMR1_CLKDIV;                /**< LPTMR1 clock divider control, offset: 0x1CC */
  __IO uint32_t MRCC_LPUART0_CLKSEL;               /**< LPUART0 clock selection control, offset: 0x1D0 */
  __IO uint32_t MRCC_LPUART0_CLKDIV;               /**< LPUART0 clock divider control, offset: 0x1D4 */
  __IO uint32_t MRCC_LPUART1_CLKSEL;               /**< LPUART1 clock selection control, offset: 0x1D8 */
  __IO uint32_t MRCC_LPUART1_CLKDIV;               /**< LPUART1 clock divider control, offset: 0x1DC */
  __IO uint32_t MRCC_MTR_CLKSEL;                   /**< MTR clock selection control, offset: 0x1E0 */
       uint8_t RESERVED_26[4];
  __IO uint32_t MRCC_MU0_CLKSEL;                   /**< MU0 clock selection control, offset: 0x1E8 */
       uint8_t RESERVED_27[4];
  __IO uint32_t MRCC_MU1_CLKSEL;                   /**< MU1 clock selection control, offset: 0x1F0 */
       uint8_t RESERVED_28[4];
  __IO uint32_t MRCC_PKC_RAM_CTRL_CLKSEL;          /**< PKC_RAM_CTRL clock selection control, offset: 0x1F8 */
       uint8_t RESERVED_29[4];
  __IO uint32_t MRCC_PKC_WRAPPER_CLKSEL;           /**< PKC_WRAPPER clock selection control, offset: 0x200 */
       uint8_t RESERVED_30[4];
  __IO uint32_t MRCC_PORTA_CLKSEL;                 /**< PORTA clock selection control, offset: 0x208 */
       uint8_t RESERVED_31[4];
  __IO uint32_t MRCC_PORTB_CLKSEL;                 /**< PORTB clock selection control, offset: 0x210 */
       uint8_t RESERVED_32[4];
  __IO uint32_t MRCC_PORTC_CLKSEL;                 /**< PORTC clock selection control, offset: 0x218 */
       uint8_t RESERVED_33[4];
  __IO uint32_t MRCC_ROMCP_CLKSEL;                 /**< ROMCP clock selection control, offset: 0x220 */
       uint8_t RESERVED_34[4];
  __IO uint32_t MRCC_SEMA_CLKSEL;                  /**< SEMA clock selection control, offset: 0x228 */
       uint8_t RESERVED_35[4];
  __IO uint32_t MRCC_SFA_CLKSEL;                   /**< SFA clock selection control, offset: 0x230 */
       uint8_t RESERVED_36[4];
  __IO uint32_t MRCC_SFA1_CLKSEL;                  /**< SFA1 clock selection control, offset: 0x238 */
       uint8_t RESERVED_37[4];
  __IO uint32_t MRCC_SGI0_CLKSEL;                  /**< SGI0 clock selection control, offset: 0x240 */
       uint8_t RESERVED_38[4];
  __IO uint32_t MRCC_SYSPM_CLKSEL;                 /**< SYSPM clock selection control, offset: 0x248 */
       uint8_t RESERVED_39[4];
  __IO uint32_t MRCC_TCU_CLKSEL;                   /**< TCU clock selection control, offset: 0x250 */
       uint8_t RESERVED_40[4];
  __IO uint32_t MRCC_TPM0_CLKSEL;                  /**< TPM0 clock selection control, offset: 0x258 */
  __IO uint32_t MRCC_TPM0_CLKDIV;                  /**< TPM0 clock divider control, offset: 0x25C */
  __IO uint32_t MRCC_TPM1_CLKSEL;                  /**< TPM1 clock selection control, offset: 0x260 */
  __IO uint32_t MRCC_TPM1_CLKDIV;                  /**< TPM1 clock divider control, offset: 0x264 */
  __IO uint32_t MRCC_TPM2_CLKSEL;                  /**< TPM2 clock selection control, offset: 0x268 */
  __IO uint32_t MRCC_TPM2_CLKDIV;                  /**< TPM2 clock divider control, offset: 0x26C */
  __IO uint32_t MRCC_TPM3_CLKSEL;                  /**< TPM3 clock selection control, offset: 0x270 */
  __IO uint32_t MRCC_TPM3_CLKDIV;                  /**< TPM3 clock divider control, offset: 0x274 */
  __IO uint32_t MRCC_TPM4_CLKSEL;                  /**< TPM4 clock selection control, offset: 0x278 */
  __IO uint32_t MRCC_TPM4_CLKDIV;                  /**< TPM4 clock divider control, offset: 0x27C */
  __IO uint32_t MRCC_TRGMUX0_CLKSEL;               /**< TRGMUX0 clock selection control, offset: 0x280 */
       uint8_t RESERVED_41[4];
  __IO uint32_t MRCC_TSTMR0_CLKSEL;                /**< TSTMR0 clock selection control, offset: 0x288 */
       uint8_t RESERVED_42[4];
  __IO uint32_t MRCC_UDF0_CLKSEL;                  /**< UDF0 clock selection control, offset: 0x290 */
       uint8_t RESERVED_43[4];
  __IO uint32_t MRCC_UTEAL_1_CLKSEL;               /**< UTEAL_1 clock selection control, offset: 0x298 */
       uint8_t RESERVED_44[4];
  __IO uint32_t MRCC_WDG0_CLKSEL;                  /**< WDG0 clock selection control, offset: 0x2A0 */
  __IO uint32_t MRCC_WDG0_CLKDIV;                  /**< WDG0 clock divider control, offset: 0x2A4 */
  __IO uint32_t MRCC_WDG1_CLKSEL;                  /**< WDG1 clock selection control, offset: 0x2A8 */
  __IO uint32_t MRCC_WDG1_CLKDIV;                  /**< WDG1 clock divider control, offset: 0x2AC */
  __IO uint32_t MRCC_ZENV_CORE_CLKSEL;             /**< ZENV_CORE clock selection control, offset: 0x2B0 */
} MRCC_Type;

/* ----------------------------------------------------------------------------
   -- MRCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Register_Masks MRCC Register Masks
 * @{
 */

/*! @name MRCC_ADC0_CLKSEL - ADC0 clock selection control */
/*! @{ */

#define MRCC_MRCC_ADC0_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_ADC0_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_ADC0_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_ADC0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_ADC0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_ADC0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_ADC0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_ADC0_CLKSEL_CC_MASK)

#define MRCC_MRCC_ADC0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_ADC0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_ADC0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_ADC0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_ADC0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_ADC0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_ADC0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_ADC0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_ADC0_CLKDIV - ADC0 clock divider control */
/*! @{ */

#define MRCC_MRCC_ADC0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_ADC0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_ADC0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_ADC0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_ADC0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_ADC0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_ADC0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_ADC0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_ADC0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_ADC0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_ADC0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_ADC0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_ADC0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_ADC0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_ADC0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_ADC0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_AOI0_CLKSEL - AOI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_AOI0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_AOI0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_AOI0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_AOI0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_AOI0_CLKSEL_CC_MASK)

#define MRCC_MRCC_AOI0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_AOI0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_AOI0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_AOI0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_AOI0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_AOI0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_AOI0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_AOI0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_AOI0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_AOI0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_ATX0_CLKSEL - ATX0 clock selection control */
/*! @{ */

#define MRCC_MRCC_ATX0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_ATX0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_ATX0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ATX0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_ATX0_CLKSEL_CC_MASK)

#define MRCC_MRCC_ATX0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_ATX0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_ATX0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ATX0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_ATX0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_ATX0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_ATX0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_ATX0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ATX0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_ATX0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_CLK_1M_CLKSEL - CLK_1M clock selection control */
/*! @{ */

#define MRCC_MRCC_CLK_1M_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_CLK_1M_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_CLK_1M_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_1M_CLKSEL_CC_SHIFT)) & MRCC_MRCC_CLK_1M_CLKSEL_CC_MASK)

#define MRCC_MRCC_CLK_1M_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_CLK_1M_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CLK_1M_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_1M_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_CLK_1M_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_CLK_1M_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_CLK_1M_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CLK_1M_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_1M_CLKSEL_PR_SHIFT)) & MRCC_MRCC_CLK_1M_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_CLK_6M_CLKSEL - CLK_6M clock selection control */
/*! @{ */

#define MRCC_MRCC_CLK_6M_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_CLK_6M_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_CLK_6M_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_6M_CLKSEL_CC_SHIFT)) & MRCC_MRCC_CLK_6M_CLKSEL_CC_MASK)

#define MRCC_MRCC_CLK_6M_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_CLK_6M_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CLK_6M_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_6M_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_CLK_6M_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_CLK_6M_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_CLK_6M_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CLK_6M_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_6M_CLKSEL_PR_SHIFT)) & MRCC_MRCC_CLK_6M_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_CLK_32M_CLKSEL - CLK_32M clock selection control */
/*! @{ */

#define MRCC_MRCC_CLK_32M_CLKSEL_CC_MASK         (0x30U)
#define MRCC_MRCC_CLK_32M_CLKSEL_CC_SHIFT        (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_CLK_32M_CLKSEL_CC(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_32M_CLKSEL_CC_SHIFT)) & MRCC_MRCC_CLK_32M_CLKSEL_CC_MASK)

#define MRCC_MRCC_CLK_32M_CLKSEL_RSTB_MASK       (0x40000000U)
#define MRCC_MRCC_CLK_32M_CLKSEL_RSTB_SHIFT      (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CLK_32M_CLKSEL_RSTB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_32M_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_CLK_32M_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_CLK_32M_CLKSEL_PR_MASK         (0x80000000U)
#define MRCC_MRCC_CLK_32M_CLKSEL_PR_SHIFT        (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CLK_32M_CLKSEL_PR(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLK_32M_CLKSEL_PR_SHIFT)) & MRCC_MRCC_CLK_32M_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_CMP0_CLKSEL - CMP0 clock selection control */
/*! @{ */

#define MRCC_MRCC_CMP0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_CMP0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_CMP0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_CMP0_CLKSEL_CC_MASK)

#define MRCC_MRCC_CMP0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_CMP0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CMP0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_CMP0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_CMP0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_CMP0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CMP0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_CMP0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_CRC0_CLKSEL - CRC0 clock selection control */
/*! @{ */

#define MRCC_MRCC_CRC0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_CRC0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_CRC0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_CRC0_CLKSEL_CC_MASK)

#define MRCC_MRCC_CRC0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_CRC0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CRC0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_CRC0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_CRC0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_CRC0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CRC0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_CRC0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_CRC1_CLKSEL - CRC1 clock selection control */
/*! @{ */

#define MRCC_MRCC_CRC1_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_CRC1_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_CRC1_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_CRC1_CLKSEL_CC_MASK)

#define MRCC_MRCC_CRC1_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_CRC1_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CRC1_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_CRC1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_CRC1_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_CRC1_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CRC1_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_CRC1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_DATA_STREAM_2P4_CLKSEL - DATA_STREAM_2P4 clock selection control */
/*! @{ */

#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_CC_MASK (0x30U)
#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_CC_SHIFT (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_CC(x)   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_CC_SHIFT)) & MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_CC_MASK)

#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_RSTB_MASK (0x40000000U)
#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_RSTB_SHIFT (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_RSTB(x) (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_PR_MASK (0x80000000U)
#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_PR_SHIFT (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_PR(x)   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_PR_SHIFT)) & MRCC_MRCC_DATA_STREAM_2P4_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_DMA_CLKSEL - DMA clock selection control */
/*! @{ */

#define MRCC_MRCC_DMA_CLKSEL_CC_MASK             (0x30U)
#define MRCC_MRCC_DMA_CLKSEL_CC_SHIFT            (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_DMA_CLKSEL_CC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DMA_CLKSEL_CC_SHIFT)) & MRCC_MRCC_DMA_CLKSEL_CC_MASK)

#define MRCC_MRCC_DMA_CLKSEL_RSTB_MASK           (0x40000000U)
#define MRCC_MRCC_DMA_CLKSEL_RSTB_SHIFT          (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_DMA_CLKSEL_RSTB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DMA_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_DMA_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_DMA_CLKSEL_PR_MASK             (0x80000000U)
#define MRCC_MRCC_DMA_CLKSEL_PR_SHIFT            (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_DMA_CLKSEL_PR(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DMA_CLKSEL_PR_SHIFT)) & MRCC_MRCC_DMA_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_DSP_RAMC0_CLKSEL - DSP_RAMC0 clock selection control */
/*! @{ */

#define MRCC_MRCC_DSP_RAMC0_CLKSEL_CC_MASK       (0x30U)
#define MRCC_MRCC_DSP_RAMC0_CLKSEL_CC_SHIFT      (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_DSP_RAMC0_CLKSEL_CC(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DSP_RAMC0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_DSP_RAMC0_CLKSEL_CC_MASK)

#define MRCC_MRCC_DSP_RAMC0_CLKSEL_RSTB_MASK     (0x40000000U)
#define MRCC_MRCC_DSP_RAMC0_CLKSEL_RSTB_SHIFT    (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_DSP_RAMC0_CLKSEL_RSTB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DSP_RAMC0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_DSP_RAMC0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_DSP_RAMC0_CLKSEL_PR_MASK       (0x80000000U)
#define MRCC_MRCC_DSP_RAMC0_CLKSEL_PR_SHIFT      (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_DSP_RAMC0_CLKSEL_PR(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DSP_RAMC0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_DSP_RAMC0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_EDT_CC_CLKSEL - EDT_CC clock selection control */
/*! @{ */

#define MRCC_MRCC_EDT_CC_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_EDT_CC_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_EDT_CC_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EDT_CC_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_EDT_CC_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_EDT_CC_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_EDT_CC_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_EDT_CC_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EDT_CC_CLKSEL_PR_SHIFT)) & MRCC_MRCC_EDT_CC_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_EWM0_CLKSEL - EWM0 clock selection control */
/*! @{ */

#define MRCC_MRCC_EWM0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_EWM0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_EWM0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_EWM0_CLKSEL_CC_MASK)

#define MRCC_MRCC_EWM0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_EWM0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_EWM0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_EWM0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_EWM0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_EWM0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_EWM0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_EWM0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_EWM0_CLKDIV - EWM0 clock divider control */
/*! @{ */

#define MRCC_MRCC_EWM0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_EWM0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_EWM0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_EWM0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_EWM0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_EWM0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_EWM0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_EWM0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_EWM0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_EWM0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_EWM0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_EWM0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_EWM0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_EWM0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_EWM0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_EWM0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_EZRAMC_RAM0_CLKSEL - EZRAMC_RAM0 clock selection control */
/*! @{ */

#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_CC_MASK     (0x30U)
#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_CC_SHIFT    (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_CC(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_EZRAMC_RAM0_CLKSEL_CC_MASK)

#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_RSTB_MASK   (0x40000000U)
#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_RSTB_SHIFT  (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_RSTB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_EZRAMC_RAM0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_PR_MASK     (0x80000000U)
#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_PR_SHIFT    (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_EZRAMC_RAM0_CLKSEL_PR(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_EZRAMC_RAM0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_EZRAMC_RAM1_CLKSEL - EZRAMC_RAM1 clock selection control */
/*! @{ */

#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_CC_MASK     (0x30U)
#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_CC_SHIFT    (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_CC(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_EZRAMC_RAM1_CLKSEL_CC_MASK)

#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_RSTB_MASK   (0x40000000U)
#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_RSTB_SHIFT  (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_RSTB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_EZRAMC_RAM1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_PR_MASK     (0x80000000U)
#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_PR_SHIFT    (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_EZRAMC_RAM1_CLKSEL_PR(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_EZRAMC_RAM1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_EZRAMC_RAM2_CLKSEL - EZRAMC_RAM2 clock selection control */
/*! @{ */

#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_CC_MASK     (0x30U)
#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_CC_SHIFT    (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_CC(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM2_CLKSEL_CC_SHIFT)) & MRCC_MRCC_EZRAMC_RAM2_CLKSEL_CC_MASK)

#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_RSTB_MASK   (0x40000000U)
#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_RSTB_SHIFT  (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_RSTB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM2_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_EZRAMC_RAM2_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_PR_MASK     (0x80000000U)
#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_PR_SHIFT    (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_EZRAMC_RAM2_CLKSEL_PR(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM2_CLKSEL_PR_SHIFT)) & MRCC_MRCC_EZRAMC_RAM2_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_EZRAMC_RAM3_CLKSEL - EZRAMC_RAM3 clock selection control */
/*! @{ */

#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_CC_MASK     (0x30U)
#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_CC_SHIFT    (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_CC(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM3_CLKSEL_CC_SHIFT)) & MRCC_MRCC_EZRAMC_RAM3_CLKSEL_CC_MASK)

#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_RSTB_MASK   (0x40000000U)
#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_RSTB_SHIFT  (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_RSTB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM3_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_EZRAMC_RAM3_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_PR_MASK     (0x80000000U)
#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_PR_SHIFT    (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_EZRAMC_RAM3_CLKSEL_PR(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EZRAMC_RAM3_CLKSEL_PR_SHIFT)) & MRCC_MRCC_EZRAMC_RAM3_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN0_CLKSEL - FLEXCAN0 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_MASK       (0x7U)
#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b100..FRO_200M
 */
#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKSEL_CC_MASK        (0x30U)
#define MRCC_MRCC_FLEXCAN0_CLKSEL_CC_SHIFT       (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_FLEXCAN0_CLKSEL_CC(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKSEL_CC_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKSEL_RSTB_MASK      (0x40000000U)
#define MRCC_MRCC_FLEXCAN0_CLKSEL_RSTB_SHIFT     (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_FLEXCAN0_CLKSEL_RSTB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKSEL_PR_MASK        (0x80000000U)
#define MRCC_MRCC_FLEXCAN0_CLKSEL_PR_SHIFT       (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_FLEXCAN0_CLKSEL_PR(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXPWM0_CLKSEL - FLEXPWM0 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXPWM0_CLKSEL_CC_MASK        (0x30U)
#define MRCC_MRCC_FLEXPWM0_CLKSEL_CC_SHIFT       (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_FLEXPWM0_CLKSEL_CC(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXPWM0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_FLEXPWM0_CLKSEL_CC_MASK)

#define MRCC_MRCC_FLEXPWM0_CLKSEL_RSTB_MASK      (0x40000000U)
#define MRCC_MRCC_FLEXPWM0_CLKSEL_RSTB_SHIFT     (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_FLEXPWM0_CLKSEL_RSTB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXPWM0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_FLEXPWM0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_FLEXPWM0_CLKSEL_PR_MASK        (0x80000000U)
#define MRCC_MRCC_FLEXPWM0_CLKSEL_PR_SHIFT       (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_FLEXPWM0_CLKSEL_PR(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXPWM0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_FLEXPWM0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_FMC_CLKSEL - FMC clock selection control */
/*! @{ */

#define MRCC_MRCC_FMC_CLKSEL_CC_MASK             (0x30U)
#define MRCC_MRCC_FMC_CLKSEL_CC_SHIFT            (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_FMC_CLKSEL_CC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FMC_CLKSEL_CC_SHIFT)) & MRCC_MRCC_FMC_CLKSEL_CC_MASK)

#define MRCC_MRCC_FMC_CLKSEL_RSTB_MASK           (0x40000000U)
#define MRCC_MRCC_FMC_CLKSEL_RSTB_SHIFT          (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_FMC_CLKSEL_RSTB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FMC_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_FMC_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_FMC_CLKSEL_PR_MASK             (0x80000000U)
#define MRCC_MRCC_FMC_CLKSEL_PR_SHIFT            (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_FMC_CLKSEL_PR(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FMC_CLKSEL_PR_SHIFT)) & MRCC_MRCC_FMC_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_FRO200M_CLKSEL - FRO200M clock selection control */
/*! @{ */

#define MRCC_MRCC_FRO200M_CLKSEL_CC_MASK         (0x30U)
#define MRCC_MRCC_FRO200M_CLKSEL_CC_SHIFT        (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_FRO200M_CLKSEL_CC(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO200M_CLKSEL_CC_SHIFT)) & MRCC_MRCC_FRO200M_CLKSEL_CC_MASK)

#define MRCC_MRCC_FRO200M_CLKSEL_RSTB_MASK       (0x40000000U)
#define MRCC_MRCC_FRO200M_CLKSEL_RSTB_SHIFT      (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_FRO200M_CLKSEL_RSTB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO200M_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_FRO200M_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_FRO200M_CLKSEL_PR_MASK         (0x80000000U)
#define MRCC_MRCC_FRO200M_CLKSEL_PR_SHIFT        (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_FRO200M_CLKSEL_PR(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO200M_CLKSEL_PR_SHIFT)) & MRCC_MRCC_FRO200M_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_FRO_HF_DIV_CLKSEL - FRO_HF_DIV clock selection control */
/*! @{ */

#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_CC_MASK      (0x30U)
#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_CC_SHIFT     (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_CC(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO_HF_DIV_CLKSEL_CC_SHIFT)) & MRCC_MRCC_FRO_HF_DIV_CLKSEL_CC_MASK)

#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_RSTB_MASK    (0x40000000U)
#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_RSTB_SHIFT   (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_RSTB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO_HF_DIV_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_FRO_HF_DIV_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_PR_MASK      (0x80000000U)
#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_PR_SHIFT     (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_FRO_HF_DIV_CLKSEL_PR(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO_HF_DIV_CLKSEL_PR_SHIFT)) & MRCC_MRCC_FRO_HF_DIV_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_FRO_HF_DIV_CLKDIV - FRO_HF_DIV clock divider control */
/*! @{ */

#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_DIV_MASK     (0xFU)
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_DIV_SHIFT    (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_DIV(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO_HF_DIV_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FRO_HF_DIV_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_RESET_MASK   (0x20000000U)
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_RESET_SHIFT  (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_RESET(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO_HF_DIV_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FRO_HF_DIV_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_HALT_MASK    (0x40000000U)
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_HALT_SHIFT   (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_HALT(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO_HF_DIV_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FRO_HF_DIV_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_UNSTAB_MASK  (0x80000000U)
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_UNSTAB_SHIFT (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_FRO_HF_DIV_CLKDIV_UNSTAB(x)    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FRO_HF_DIV_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FRO_HF_DIV_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_GDET_WRAPPER_CLKSEL - GDET_WRAPPER clock selection control */
/*! @{ */

#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_CC_MASK    (0x30U)
#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_CC_SHIFT   (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_CC(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GDET_WRAPPER_CLKSEL_CC_SHIFT)) & MRCC_MRCC_GDET_WRAPPER_CLKSEL_CC_MASK)

#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_RSTB_MASK  (0x40000000U)
#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_RSTB_SHIFT (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_RSTB(x)    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GDET_WRAPPER_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_GDET_WRAPPER_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_PR_MASK    (0x80000000U)
#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_PR_SHIFT   (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_GDET_WRAPPER_CLKSEL_PR(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GDET_WRAPPER_CLKSEL_PR_SHIFT)) & MRCC_MRCC_GDET_WRAPPER_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_GDET_WRAPPER_CLKDIV - GDET_WRAPPER clock divider control */
/*! @{ */

#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_DIV_MASK   (0xFU)
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_DIV_SHIFT  (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_DIV(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GDET_WRAPPER_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_GDET_WRAPPER_CLKDIV_DIV_MASK)

#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_RESET_MASK (0x20000000U)
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_RESET_SHIFT (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_RESET(x)   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GDET_WRAPPER_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_GDET_WRAPPER_CLKDIV_RESET_MASK)

#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_HALT_MASK  (0x40000000U)
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_HALT_SHIFT (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_HALT(x)    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GDET_WRAPPER_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_GDET_WRAPPER_CLKDIV_HALT_MASK)

#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_UNSTAB_MASK (0x80000000U)
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_UNSTAB_SHIFT (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_GDET_WRAPPER_CLKDIV_UNSTAB(x)  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GDET_WRAPPER_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_GDET_WRAPPER_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_GPIOA_CLKSEL - GPIOA clock selection control */
/*! @{ */

#define MRCC_MRCC_GPIOA_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_GPIOA_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_GPIOA_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOA_CLKSEL_CC_SHIFT)) & MRCC_MRCC_GPIOA_CLKSEL_CC_MASK)

#define MRCC_MRCC_GPIOA_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_GPIOA_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_GPIOA_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOA_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_GPIOA_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_GPIOA_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_GPIOA_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_GPIOA_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOA_CLKSEL_PR_SHIFT)) & MRCC_MRCC_GPIOA_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_GPIOB_CLKSEL - GPIOB clock selection control */
/*! @{ */

#define MRCC_MRCC_GPIOB_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_GPIOB_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_GPIOB_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOB_CLKSEL_CC_SHIFT)) & MRCC_MRCC_GPIOB_CLKSEL_CC_MASK)

#define MRCC_MRCC_GPIOB_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_GPIOB_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_GPIOB_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOB_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_GPIOB_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_GPIOB_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_GPIOB_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_GPIOB_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOB_CLKSEL_PR_SHIFT)) & MRCC_MRCC_GPIOB_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_GPIOC_CLKSEL - GPIOC clock selection control */
/*! @{ */

#define MRCC_MRCC_GPIOC_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_GPIOC_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_GPIOC_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOC_CLKSEL_CC_SHIFT)) & MRCC_MRCC_GPIOC_CLKSEL_CC_MASK)

#define MRCC_MRCC_GPIOC_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_GPIOC_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_GPIOC_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOC_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_GPIOC_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_GPIOC_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_GPIOC_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_GPIOC_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOC_CLKSEL_PR_SHIFT)) & MRCC_MRCC_GPIOC_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_INTM_CLKSEL - INTM clock selection control */
/*! @{ */

#define MRCC_MRCC_INTM_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_INTM_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_INTM_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_INTM_CLKSEL_CC_SHIFT)) & MRCC_MRCC_INTM_CLKSEL_CC_MASK)

#define MRCC_MRCC_INTM_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_INTM_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_INTM_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_INTM_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_INTM_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_INTM_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_INTM_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_INTM_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_INTM_CLKSEL_PR_SHIFT)) & MRCC_MRCC_INTM_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_IPSYNC_TRNG0_CLKSEL - IPSYNC_TRNG0 clock selection control */
/*! @{ */

#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_CC_MASK    (0x30U)
#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_CC_SHIFT   (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_CC(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_CC_MASK)

#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_RSTB_MASK  (0x40000000U)
#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_RSTB_SHIFT (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_RSTB(x)    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_PR_MASK    (0x80000000U)
#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_PR_SHIFT   (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_PR(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_IPSYNC_TRNG0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_ITRC_WRAPPER_CLKSEL - ITRC_WRAPPER clock selection control */
/*! @{ */

#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_CC_MASK    (0x30U)
#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_CC_SHIFT   (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_CC(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ITRC_WRAPPER_CLKSEL_CC_SHIFT)) & MRCC_MRCC_ITRC_WRAPPER_CLKSEL_CC_MASK)

#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_RSTB_MASK  (0x40000000U)
#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_RSTB_SHIFT (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_RSTB(x)    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ITRC_WRAPPER_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_ITRC_WRAPPER_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_PR_MASK    (0x80000000U)
#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_PR_SHIFT   (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_ITRC_WRAPPER_CLKSEL_PR(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ITRC_WRAPPER_CLKSEL_PR_SHIFT)) & MRCC_MRCC_ITRC_WRAPPER_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_LPI2C0_CLKSEL - LPI2C0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_LPI2C0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPI2C0_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_LPI2C0_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPI2C0_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPI2C0_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPI2C0_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C0_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPI2C0_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPI2C0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPI2C0_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_LPI2C0_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPI2C0_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPI2C0_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C1_CLKSEL - LPI2C1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C1_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C1_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_LPI2C1_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C1_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPI2C1_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_LPI2C1_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPI2C1_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPI2C1_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPI2C1_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C1_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPI2C1_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPI2C1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPI2C1_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_LPI2C1_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPI2C1_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPI2C1_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPIT0_CLKSEL - LPIT0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPIT0_CLKSEL_MUX_MASK          (0x7U)
#define MRCC_MRCC_LPIT0_CLKSEL_MUX_SHIFT         (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_LPIT0_CLKSEL_MUX(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPIT0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPIT0_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_LPIT0_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPIT0_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPIT0_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPIT0_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_LPIT0_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPIT0_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPIT0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPIT0_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_LPIT0_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPIT0_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPIT0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_LPIT0_CLKDIV - LPIT0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPIT0_CLKDIV_DIV_MASK          (0xFU)
#define MRCC_MRCC_LPIT0_CLKDIV_DIV_SHIFT         (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPIT0_CLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPIT0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPIT0_CLKDIV_RESET_MASK        (0x20000000U)
#define MRCC_MRCC_LPIT0_CLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPIT0_CLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPIT0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPIT0_CLKDIV_HALT_MASK         (0x40000000U)
#define MRCC_MRCC_LPIT0_CLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPIT0_CLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPIT0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPIT0_CLKDIV_UNSTAB_MASK       (0x80000000U)
#define MRCC_MRCC_LPIT0_CLKDIV_UNSTAB_SHIFT      (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPIT0_CLKDIV_UNSTAB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPIT0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI0_CLKSEL - LPSPI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b101..CLK_1M
 */
#define MRCC_MRCC_LPSPI0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPSPI0_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_LPSPI0_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPSPI0_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPSPI0_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPSPI0_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI0_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPSPI0_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPSPI0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPSPI0_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_LPSPI0_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPSPI0_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPSPI0_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI1_CLKSEL - LPSPI1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI1_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI1_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_LPSPI1_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI1_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPSPI1_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_LPSPI1_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPSPI1_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPSPI1_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPSPI1_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI1_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPSPI1_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPSPI1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPSPI1_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_LPSPI1_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPSPI1_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPSPI1_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI2_CLKSEL - LPSPI2 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI2_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI2_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_LPSPI2_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI2_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPSPI2_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_LPSPI2_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPSPI2_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPSPI2_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPSPI2_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI2_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPSPI2_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPSPI2_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPSPI2_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_LPSPI2_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPSPI2_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPSPI2_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPTMR0_CLKSEL - LPTMR0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPTMR0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPTMR0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_LPTMR0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPTMR0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPTMR0_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_LPTMR0_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPTMR0_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPTMR0_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPTMR0_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_LPTMR0_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPTMR0_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPTMR0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPTMR0_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_LPTMR0_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPTMR0_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPTMR0_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPTMR1_CLKSEL - LPTMR1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPTMR1_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPTMR1_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 */
#define MRCC_MRCC_LPTMR1_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPTMR1_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPTMR1_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_LPTMR1_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPTMR1_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPTMR1_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPTMR1_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_LPTMR1_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPTMR1_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPTMR1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPTMR1_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_LPTMR1_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPTMR1_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPTMR1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_LPTMR1_CLKDIV - LPTMR1 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPTMR1_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPTMR1_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPTMR1_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPTMR1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPTMR1_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPTMR1_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPTMR1_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPTMR1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPTMR1_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPTMR1_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPTMR1_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPTMR1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPTMR1_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPTMR1_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPTMR1_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPTMR1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART0_CLKSEL - LPUART0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART0_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART0_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 */
#define MRCC_MRCC_LPUART0_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPUART0_CLKSEL_CC_MASK         (0x30U)
#define MRCC_MRCC_LPUART0_CLKSEL_CC_SHIFT        (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPUART0_CLKSEL_CC(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPUART0_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPUART0_CLKSEL_RSTB_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART0_CLKSEL_RSTB_SHIFT      (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPUART0_CLKSEL_RSTB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPUART0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPUART0_CLKSEL_PR_MASK         (0x80000000U)
#define MRCC_MRCC_LPUART0_CLKSEL_PR_SHIFT        (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPUART0_CLKSEL_PR(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPUART0_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART0_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART1_CLKSEL - LPUART1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART1_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART1_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 */
#define MRCC_MRCC_LPUART1_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART1_CLKSEL_MUX_MASK)

#define MRCC_MRCC_LPUART1_CLKSEL_CC_MASK         (0x30U)
#define MRCC_MRCC_LPUART1_CLKSEL_CC_SHIFT        (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_LPUART1_CLKSEL_CC(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_LPUART1_CLKSEL_CC_MASK)

#define MRCC_MRCC_LPUART1_CLKSEL_RSTB_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART1_CLKSEL_RSTB_SHIFT      (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPUART1_CLKSEL_RSTB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_LPUART1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_LPUART1_CLKSEL_PR_MASK         (0x80000000U)
#define MRCC_MRCC_LPUART1_CLKSEL_PR_SHIFT        (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPUART1_CLKSEL_PR(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_LPUART1_CLKSEL_PR_MASK)
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
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART1_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_MTR_CLKSEL - MTR clock selection control */
/*! @{ */

#define MRCC_MRCC_MTR_CLKSEL_CC_MASK             (0x30U)
#define MRCC_MRCC_MTR_CLKSEL_CC_SHIFT            (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_MTR_CLKSEL_CC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MTR_CLKSEL_CC_SHIFT)) & MRCC_MRCC_MTR_CLKSEL_CC_MASK)

#define MRCC_MRCC_MTR_CLKSEL_RSTB_MASK           (0x40000000U)
#define MRCC_MRCC_MTR_CLKSEL_RSTB_SHIFT          (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_MTR_CLKSEL_RSTB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MTR_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_MTR_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_MTR_CLKSEL_PR_MASK             (0x80000000U)
#define MRCC_MRCC_MTR_CLKSEL_PR_SHIFT            (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_MTR_CLKSEL_PR(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MTR_CLKSEL_PR_SHIFT)) & MRCC_MRCC_MTR_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_MU0_CLKSEL - MU0 clock selection control */
/*! @{ */

#define MRCC_MRCC_MU0_CLKSEL_CC_MASK             (0x30U)
#define MRCC_MRCC_MU0_CLKSEL_CC_SHIFT            (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_MU0_CLKSEL_CC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MU0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_MU0_CLKSEL_CC_MASK)

#define MRCC_MRCC_MU0_CLKSEL_RSTB_MASK           (0x40000000U)
#define MRCC_MRCC_MU0_CLKSEL_RSTB_SHIFT          (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_MU0_CLKSEL_RSTB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MU0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_MU0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_MU0_CLKSEL_PR_MASK             (0x80000000U)
#define MRCC_MRCC_MU0_CLKSEL_PR_SHIFT            (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_MU0_CLKSEL_PR(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MU0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_MU0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_MU1_CLKSEL - MU1 clock selection control */
/*! @{ */

#define MRCC_MRCC_MU1_CLKSEL_CC_MASK             (0x30U)
#define MRCC_MRCC_MU1_CLKSEL_CC_SHIFT            (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_MU1_CLKSEL_CC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MU1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_MU1_CLKSEL_CC_MASK)

#define MRCC_MRCC_MU1_CLKSEL_RSTB_MASK           (0x40000000U)
#define MRCC_MRCC_MU1_CLKSEL_RSTB_SHIFT          (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_MU1_CLKSEL_RSTB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MU1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_MU1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_MU1_CLKSEL_PR_MASK             (0x80000000U)
#define MRCC_MRCC_MU1_CLKSEL_PR_SHIFT            (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_MU1_CLKSEL_PR(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_MU1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_MU1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_PKC_RAM_CTRL_CLKSEL - PKC_RAM_CTRL clock selection control */
/*! @{ */

#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_CC_MASK    (0x30U)
#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_CC_SHIFT   (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_CC(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_CC_SHIFT)) & MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_CC_MASK)

#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_RSTB_MASK  (0x40000000U)
#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_RSTB_SHIFT (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_RSTB(x)    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_PR_MASK    (0x80000000U)
#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_PR_SHIFT   (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_PR(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_PR_SHIFT)) & MRCC_MRCC_PKC_RAM_CTRL_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_PKC_WRAPPER_CLKSEL - PKC_WRAPPER clock selection control */
/*! @{ */

#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_CC_MASK     (0x30U)
#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_CC_SHIFT    (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_CC(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PKC_WRAPPER_CLKSEL_CC_SHIFT)) & MRCC_MRCC_PKC_WRAPPER_CLKSEL_CC_MASK)

#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_RSTB_MASK   (0x40000000U)
#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_RSTB_SHIFT  (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_RSTB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PKC_WRAPPER_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_PKC_WRAPPER_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_PR_MASK     (0x80000000U)
#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_PR_SHIFT    (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PKC_WRAPPER_CLKSEL_PR(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PKC_WRAPPER_CLKSEL_PR_SHIFT)) & MRCC_MRCC_PKC_WRAPPER_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_PORTA_CLKSEL - PORTA clock selection control */
/*! @{ */

#define MRCC_MRCC_PORTA_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_PORTA_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_PORTA_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTA_CLKSEL_CC_SHIFT)) & MRCC_MRCC_PORTA_CLKSEL_CC_MASK)

#define MRCC_MRCC_PORTA_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_PORTA_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PORTA_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTA_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_PORTA_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_PORTA_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_PORTA_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PORTA_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTA_CLKSEL_PR_SHIFT)) & MRCC_MRCC_PORTA_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_PORTB_CLKSEL - PORTB clock selection control */
/*! @{ */

#define MRCC_MRCC_PORTB_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_PORTB_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_PORTB_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTB_CLKSEL_CC_SHIFT)) & MRCC_MRCC_PORTB_CLKSEL_CC_MASK)

#define MRCC_MRCC_PORTB_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_PORTB_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PORTB_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTB_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_PORTB_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_PORTB_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_PORTB_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PORTB_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTB_CLKSEL_PR_SHIFT)) & MRCC_MRCC_PORTB_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_PORTC_CLKSEL - PORTC clock selection control */
/*! @{ */

#define MRCC_MRCC_PORTC_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_PORTC_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_PORTC_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTC_CLKSEL_CC_SHIFT)) & MRCC_MRCC_PORTC_CLKSEL_CC_MASK)

#define MRCC_MRCC_PORTC_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_PORTC_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PORTC_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTC_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_PORTC_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_PORTC_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_PORTC_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PORTC_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTC_CLKSEL_PR_SHIFT)) & MRCC_MRCC_PORTC_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_ROMCP_CLKSEL - ROMCP clock selection control */
/*! @{ */

#define MRCC_MRCC_ROMCP_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_ROMCP_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_ROMCP_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ROMCP_CLKSEL_CC_SHIFT)) & MRCC_MRCC_ROMCP_CLKSEL_CC_MASK)

#define MRCC_MRCC_ROMCP_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_ROMCP_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_ROMCP_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ROMCP_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_ROMCP_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_ROMCP_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_ROMCP_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_ROMCP_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ROMCP_CLKSEL_PR_SHIFT)) & MRCC_MRCC_ROMCP_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_SEMA_CLKSEL - SEMA clock selection control */
/*! @{ */

#define MRCC_MRCC_SEMA_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_SEMA_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_SEMA_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SEMA_CLKSEL_CC_SHIFT)) & MRCC_MRCC_SEMA_CLKSEL_CC_MASK)

#define MRCC_MRCC_SEMA_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_SEMA_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SEMA_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SEMA_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_SEMA_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_SEMA_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_SEMA_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SEMA_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SEMA_CLKSEL_PR_SHIFT)) & MRCC_MRCC_SEMA_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_SFA_CLKSEL - SFA clock selection control */
/*! @{ */

#define MRCC_MRCC_SFA_CLKSEL_CC_MASK             (0x30U)
#define MRCC_MRCC_SFA_CLKSEL_CC_SHIFT            (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_SFA_CLKSEL_CC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA_CLKSEL_CC_SHIFT)) & MRCC_MRCC_SFA_CLKSEL_CC_MASK)

#define MRCC_MRCC_SFA_CLKSEL_RSTB_MASK           (0x40000000U)
#define MRCC_MRCC_SFA_CLKSEL_RSTB_SHIFT          (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SFA_CLKSEL_RSTB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_SFA_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_SFA_CLKSEL_PR_MASK             (0x80000000U)
#define MRCC_MRCC_SFA_CLKSEL_PR_SHIFT            (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SFA_CLKSEL_PR(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA_CLKSEL_PR_SHIFT)) & MRCC_MRCC_SFA_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_SFA1_CLKSEL - SFA1 clock selection control */
/*! @{ */

#define MRCC_MRCC_SFA1_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_SFA1_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_SFA1_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_SFA1_CLKSEL_CC_MASK)

#define MRCC_MRCC_SFA1_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_SFA1_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SFA1_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_SFA1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_SFA1_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_SFA1_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SFA1_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_SFA1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_SGI0_CLKSEL - SGI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_SGI0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_SGI0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_SGI0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SGI0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_SGI0_CLKSEL_CC_MASK)

#define MRCC_MRCC_SGI0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_SGI0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SGI0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SGI0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_SGI0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_SGI0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_SGI0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SGI0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SGI0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_SGI0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_SYSPM_CLKSEL - SYSPM clock selection control */
/*! @{ */

#define MRCC_MRCC_SYSPM_CLKSEL_CC_MASK           (0x30U)
#define MRCC_MRCC_SYSPM_CLKSEL_CC_SHIFT          (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_SYSPM_CLKSEL_CC(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSPM_CLKSEL_CC_SHIFT)) & MRCC_MRCC_SYSPM_CLKSEL_CC_MASK)

#define MRCC_MRCC_SYSPM_CLKSEL_RSTB_MASK         (0x40000000U)
#define MRCC_MRCC_SYSPM_CLKSEL_RSTB_SHIFT        (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SYSPM_CLKSEL_RSTB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSPM_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_SYSPM_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_SYSPM_CLKSEL_PR_MASK           (0x80000000U)
#define MRCC_MRCC_SYSPM_CLKSEL_PR_SHIFT          (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SYSPM_CLKSEL_PR(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSPM_CLKSEL_PR_SHIFT)) & MRCC_MRCC_SYSPM_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TCU_CLKSEL - TCU clock selection control */
/*! @{ */

#define MRCC_MRCC_TCU_CLKSEL_CC_MASK             (0x30U)
#define MRCC_MRCC_TCU_CLKSEL_CC_SHIFT            (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_TCU_CLKSEL_CC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TCU_CLKSEL_CC_SHIFT)) & MRCC_MRCC_TCU_CLKSEL_CC_MASK)

#define MRCC_MRCC_TCU_CLKSEL_RSTB_MASK           (0x40000000U)
#define MRCC_MRCC_TCU_CLKSEL_RSTB_SHIFT          (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TCU_CLKSEL_RSTB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TCU_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TCU_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TCU_CLKSEL_PR_MASK             (0x80000000U)
#define MRCC_MRCC_TCU_CLKSEL_PR_SHIFT            (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TCU_CLKSEL_PR(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TCU_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TCU_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TPM0_CLKSEL - TPM0 clock selection control */
/*! @{ */

#define MRCC_MRCC_TPM0_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_TPM0_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 */
#define MRCC_MRCC_TPM0_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_TPM0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_TPM0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_TPM0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_TPM0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_TPM0_CLKSEL_CC_MASK)

#define MRCC_MRCC_TPM0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_TPM0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TPM0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TPM0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TPM0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_TPM0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TPM0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TPM0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TPM0_CLKDIV - TPM0 clock divider control */
/*! @{ */

#define MRCC_MRCC_TPM0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_TPM0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TPM0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_TPM0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_TPM0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_TPM0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_TPM0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_TPM0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_TPM0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_TPM0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_TPM0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_TPM0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_TPM0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_TPM0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_TPM0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_TPM0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_TPM1_CLKSEL - TPM1 clock selection control */
/*! @{ */

#define MRCC_MRCC_TPM1_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_TPM1_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 */
#define MRCC_MRCC_TPM1_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_TPM1_CLKSEL_MUX_MASK)

#define MRCC_MRCC_TPM1_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_TPM1_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_TPM1_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_TPM1_CLKSEL_CC_MASK)

#define MRCC_MRCC_TPM1_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_TPM1_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TPM1_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TPM1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TPM1_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_TPM1_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TPM1_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TPM1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TPM1_CLKDIV - TPM1 clock divider control */
/*! @{ */

#define MRCC_MRCC_TPM1_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_TPM1_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TPM1_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_TPM1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_TPM1_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_TPM1_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_TPM1_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_TPM1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_TPM1_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_TPM1_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_TPM1_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_TPM1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_TPM1_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_TPM1_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_TPM1_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_TPM1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_TPM2_CLKSEL - TPM2 clock selection control */
/*! @{ */

#define MRCC_MRCC_TPM2_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_TPM2_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 */
#define MRCC_MRCC_TPM2_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_TPM2_CLKSEL_MUX_MASK)

#define MRCC_MRCC_TPM2_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_TPM2_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_TPM2_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKSEL_CC_SHIFT)) & MRCC_MRCC_TPM2_CLKSEL_CC_MASK)

#define MRCC_MRCC_TPM2_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_TPM2_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TPM2_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TPM2_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TPM2_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_TPM2_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TPM2_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TPM2_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TPM2_CLKDIV - TPM2 clock divider control */
/*! @{ */

#define MRCC_MRCC_TPM2_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_TPM2_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TPM2_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_TPM2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_TPM2_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_TPM2_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_TPM2_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_TPM2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_TPM2_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_TPM2_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_TPM2_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_TPM2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_TPM2_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_TPM2_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_TPM2_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_TPM2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_TPM3_CLKSEL - TPM3 clock selection control */
/*! @{ */

#define MRCC_MRCC_TPM3_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_TPM3_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 */
#define MRCC_MRCC_TPM3_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_TPM3_CLKSEL_MUX_MASK)

#define MRCC_MRCC_TPM3_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_TPM3_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_TPM3_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKSEL_CC_SHIFT)) & MRCC_MRCC_TPM3_CLKSEL_CC_MASK)

#define MRCC_MRCC_TPM3_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_TPM3_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TPM3_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TPM3_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TPM3_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_TPM3_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TPM3_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TPM3_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TPM3_CLKDIV - TPM3 clock divider control */
/*! @{ */

#define MRCC_MRCC_TPM3_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_TPM3_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TPM3_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_TPM3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_TPM3_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_TPM3_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_TPM3_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_TPM3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_TPM3_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_TPM3_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_TPM3_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_TPM3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_TPM3_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_TPM3_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_TPM3_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_TPM3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_TPM4_CLKSEL - TPM4 clock selection control */
/*! @{ */

#define MRCC_MRCC_TPM4_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_TPM4_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 */
#define MRCC_MRCC_TPM4_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_TPM4_CLKSEL_MUX_MASK)

#define MRCC_MRCC_TPM4_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_TPM4_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_TPM4_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKSEL_CC_SHIFT)) & MRCC_MRCC_TPM4_CLKSEL_CC_MASK)

#define MRCC_MRCC_TPM4_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_TPM4_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TPM4_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TPM4_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TPM4_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_TPM4_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TPM4_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TPM4_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TPM4_CLKDIV - TPM4 clock divider control */
/*! @{ */

#define MRCC_MRCC_TPM4_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_TPM4_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TPM4_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_TPM4_CLKDIV_DIV_MASK)

#define MRCC_MRCC_TPM4_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_TPM4_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_TPM4_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_TPM4_CLKDIV_RESET_MASK)

#define MRCC_MRCC_TPM4_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_TPM4_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_TPM4_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_TPM4_CLKDIV_HALT_MASK)

#define MRCC_MRCC_TPM4_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_TPM4_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_TPM4_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM4_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_TPM4_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_TRGMUX0_CLKSEL - TRGMUX0 clock selection control */
/*! @{ */

#define MRCC_MRCC_TRGMUX0_CLKSEL_RSTB_MASK       (0x40000000U)
#define MRCC_MRCC_TRGMUX0_CLKSEL_RSTB_SHIFT      (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TRGMUX0_CLKSEL_RSTB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TRGMUX0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TRGMUX0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TRGMUX0_CLKSEL_PR_MASK         (0x80000000U)
#define MRCC_MRCC_TRGMUX0_CLKSEL_PR_SHIFT        (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TRGMUX0_CLKSEL_PR(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TRGMUX0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TRGMUX0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_TSTMR0_CLKSEL - TSTMR0 clock selection control */
/*! @{ */

#define MRCC_MRCC_TSTMR0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_TSTMR0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 *  0b101..CLK_1M
 */
#define MRCC_MRCC_TSTMR0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSTMR0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_TSTMR0_CLKSEL_MUX_MASK)

#define MRCC_MRCC_TSTMR0_CLKSEL_CC_MASK          (0x30U)
#define MRCC_MRCC_TSTMR0_CLKSEL_CC_SHIFT         (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_TSTMR0_CLKSEL_CC(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSTMR0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_TSTMR0_CLKSEL_CC_MASK)

#define MRCC_MRCC_TSTMR0_CLKSEL_RSTB_MASK        (0x40000000U)
#define MRCC_MRCC_TSTMR0_CLKSEL_RSTB_SHIFT       (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TSTMR0_CLKSEL_RSTB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSTMR0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_TSTMR0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_TSTMR0_CLKSEL_PR_MASK          (0x80000000U)
#define MRCC_MRCC_TSTMR0_CLKSEL_PR_SHIFT         (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TSTMR0_CLKSEL_PR(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSTMR0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_TSTMR0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_UDF0_CLKSEL - UDF0 clock selection control */
/*! @{ */

#define MRCC_MRCC_UDF0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_UDF0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_UDF0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_UDF0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_UDF0_CLKSEL_CC_MASK)

#define MRCC_MRCC_UDF0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_UDF0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_UDF0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_UDF0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_UDF0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_UDF0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_UDF0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_UDF0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_UDF0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_UDF0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_UTEAL_1_CLKSEL - UTEAL_1 clock selection control */
/*! @{ */

#define MRCC_MRCC_UTEAL_1_CLKSEL_CC_MASK         (0x30U)
#define MRCC_MRCC_UTEAL_1_CLKSEL_CC_SHIFT        (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_UTEAL_1_CLKSEL_CC(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_UTEAL_1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_UTEAL_1_CLKSEL_CC_MASK)

#define MRCC_MRCC_UTEAL_1_CLKSEL_RSTB_MASK       (0x40000000U)
#define MRCC_MRCC_UTEAL_1_CLKSEL_RSTB_SHIFT      (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_UTEAL_1_CLKSEL_RSTB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_UTEAL_1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_UTEAL_1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_UTEAL_1_CLKSEL_PR_MASK         (0x80000000U)
#define MRCC_MRCC_UTEAL_1_CLKSEL_PR_SHIFT        (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_UTEAL_1_CLKSEL_PR(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_UTEAL_1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_UTEAL_1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_WDG0_CLKSEL - WDG0 clock selection control */
/*! @{ */

#define MRCC_MRCC_WDG0_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_WDG0_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_WDG0_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG0_CLKSEL_CC_SHIFT)) & MRCC_MRCC_WDG0_CLKSEL_CC_MASK)

#define MRCC_MRCC_WDG0_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_WDG0_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_WDG0_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG0_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_WDG0_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_WDG0_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_WDG0_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_WDG0_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG0_CLKSEL_PR_SHIFT)) & MRCC_MRCC_WDG0_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_WDG0_CLKDIV - WDG0 clock divider control */
/*! @{ */

#define MRCC_MRCC_WDG0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_WDG0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_WDG0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_WDG0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_WDG0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_WDG0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_WDG0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_WDG0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_WDG0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_WDG0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_WDG0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_WDG0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_WDG0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_WDG0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_WDG0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_WDG0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_WDG1_CLKSEL - WDG1 clock selection control */
/*! @{ */

#define MRCC_MRCC_WDG1_CLKSEL_CC_MASK            (0x30U)
#define MRCC_MRCC_WDG1_CLKSEL_CC_SHIFT           (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_WDG1_CLKSEL_CC(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG1_CLKSEL_CC_SHIFT)) & MRCC_MRCC_WDG1_CLKSEL_CC_MASK)

#define MRCC_MRCC_WDG1_CLKSEL_RSTB_MASK          (0x40000000U)
#define MRCC_MRCC_WDG1_CLKSEL_RSTB_SHIFT         (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_WDG1_CLKSEL_RSTB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG1_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_WDG1_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_WDG1_CLKSEL_PR_MASK            (0x80000000U)
#define MRCC_MRCC_WDG1_CLKSEL_PR_SHIFT           (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_WDG1_CLKSEL_PR(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG1_CLKSEL_PR_SHIFT)) & MRCC_MRCC_WDG1_CLKSEL_PR_MASK)
/*! @} */

/*! @name MRCC_WDG1_CLKDIV - WDG1 clock divider control */
/*! @{ */

#define MRCC_MRCC_WDG1_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_WDG1_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_WDG1_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_WDG1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_WDG1_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_WDG1_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_WDG1_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_WDG1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_WDG1_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_WDG1_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_WDG1_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_WDG1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_WDG1_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_WDG1_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_MRCC_WDG1_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDG1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_WDG1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_ZENV_CORE_CLKSEL - ZENV_CORE clock selection control */
/*! @{ */

#define MRCC_MRCC_ZENV_CORE_CLKSEL_CC_MASK       (0x30U)
#define MRCC_MRCC_ZENV_CORE_CLKSEL_CC_SHIFT      (4U)
/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define MRCC_MRCC_ZENV_CORE_CLKSEL_CC(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ZENV_CORE_CLKSEL_CC_SHIFT)) & MRCC_MRCC_ZENV_CORE_CLKSEL_CC_MASK)

#define MRCC_MRCC_ZENV_CORE_CLKSEL_RSTB_MASK     (0x40000000U)
#define MRCC_MRCC_ZENV_CORE_CLKSEL_RSTB_SHIFT    (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_ZENV_CORE_CLKSEL_RSTB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ZENV_CORE_CLKSEL_RSTB_SHIFT)) & MRCC_MRCC_ZENV_CORE_CLKSEL_RSTB_MASK)

#define MRCC_MRCC_ZENV_CORE_CLKSEL_PR_MASK       (0x80000000U)
#define MRCC_MRCC_ZENV_CORE_CLKSEL_PR_SHIFT      (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_ZENV_CORE_CLKSEL_PR(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ZENV_CORE_CLKSEL_PR_SHIFT)) & MRCC_MRCC_ZENV_CORE_CLKSEL_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRCC_Register_Masks */

/* Backward compatibility */
#define MRCC_CC_MASK                              (0x30U)
#define MRCC_CC_SHIFT                             (4U)
#define MRCC_CC(x)                                (((uint32_t)(((uint32_t)(x)) << MRCC_CC_SHIFT))  & MRCC_CC_MASK)
#define MRCC_MUX_MASK                             (0x7U)
#define MRCC_MUX_SHIFT                            (0U)
#define MRCC_MUX(x)                               (((uint32_t)(((uint32_t)(x)) << MRCC_MUX_SHIFT))  & MRCC_MUX_MASK)
#define MRCC_DIV_MASK                             (0xFU)
#define MRCC_DIV_SHIFT                            (0U)
#define MRCC_DIV(x)                               (((uint32_t)(((uint32_t)(x)) << MRCC_DIV_SHIFT))  & MRCC_DIV_MASK)
#define MRCC_RSTB_MASK                            (0x40000000U)
#define MRCC_RSTB_SHIFT                           (30U)
#define MRCC_RSTB(x)                              (((uint32_t)(((uint32_t)(x)) << MRCC_RSTB_SHIFT)) & MRCC_RSTB_MASK)
#define MRCC_PR_MASK                              (0x80000000U)
#define MRCC_PR_SHIFT                             (31U)
#define MRCC_PR(x)                                (((uint32_t)(((uint32_t)(x)) << MRCC_PR_SHIFT))  & MRCC_PR_MASK)


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

