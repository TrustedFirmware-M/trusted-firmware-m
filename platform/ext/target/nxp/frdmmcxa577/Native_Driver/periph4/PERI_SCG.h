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
**         CMSIS Peripheral Access Layer for SCG
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
 * @file PERI_SCG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SCG
 *
 * CMSIS Peripheral Access Layer for SCG
 */

#if !defined(PERI_SCG_H_)
#define PERI_SCG_H_                              /**< Symbol preventing repeated inclusion */

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
   -- SCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Peripheral_Access_Layer SCG Peripheral Access Layer
 * @{
 */

/** SCG - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t TRIM_LOCK;                         /**< Trim Lock, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __I  uint32_t CSR;                               /**< Clock Status, offset: 0x10 */
  __IO uint32_t RCCR;                              /**< Run Clock Control, offset: 0x14 */
       uint8_t RESERVED_1[232];
  __IO uint32_t SOSCCSR;                           /**< SOSC Control Status, offset: 0x100 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SOSCCFG;                           /**< SOSC Configuration, offset: 0x108 */
       uint8_t RESERVED_3[244];
  __IO uint32_t SIRCCSR;                           /**< SIRC Control Status, offset: 0x200 */
       uint8_t RESERVED_4[8];
  __IO uint32_t SIRCTCFG;                          /**< SIRC Trim Configuration, offset: 0x20C */
  __IO uint32_t SIRCTRIM;                          /**< SIRC Trim, offset: 0x210 */
       uint8_t RESERVED_5[4];
  __IO uint32_t SIRCSTAT;                          /**< SIRC Auto-trimming Status, offset: 0x218 */
       uint8_t RESERVED_6[228];
  __IO uint32_t FIRCCSR;                           /**< FIRC Control Status, offset: 0x300 */
       uint8_t RESERVED_7[4];
  __IO uint32_t FIRCCFG;                           /**< FIRC Configuration, offset: 0x308 */
  __IO uint32_t FIRCTCFG;                          /**< FIRC Trim Configuration, offset: 0x30C */
  __IO uint32_t FIRCTRIM;                          /**< FIRC Trim, offset: 0x310 */
       uint8_t RESERVED_8[4];
  __IO uint32_t FIRCSTAT;                          /**< FIRC Auto-trimming Status, offset: 0x318 */
  __IO uint32_t FIRCATC1;                          /**< FIRC Auto-trimming Counter 1, offset: 0x31C */
  __IO uint32_t FIRCATC2;                          /**< FIRC Auto-trimming Counter 2, offset: 0x320 */
  __IO uint32_t FIRCATC3;                          /**< FIRC Auto-trimming Counter 3, offset: 0x324 */
  __IO uint32_t FIRCATC4;                          /**< FIRC Auto-trimming Counter 4, offset: 0x328 */
  __IO uint32_t FIRCATC5;                          /**< FIRC Auto-trimming Counter 5, offset: 0x32C */
  __IO uint32_t FIRCATC6;                          /**< FIRC Auto-trimming Counter 6, offset: 0x330 */
       uint8_t RESERVED_9[12];
  __IO uint32_t FIRCATC7;                          /**< FIRC Auto-trimming Counter 7, offset: 0x340 */
  __IO uint32_t FIRCATC8;                          /**< FIRC Auto-trimming Counter 8, offset: 0x344 */
  __IO uint32_t FIRCATC9;                          /**< FIRC Auto-trimming Counter 9, offset: 0x348 */
  __IO uint32_t FIRCATC10;                         /**< FIRC Auto-trimming Counter 10, offset: 0x34C */
  __IO uint32_t FIRCATC11;                         /**< FIRC Auto-trimming Counter 11, offset: 0x350 */
       uint8_t RESERVED_10[172];
  __IO uint32_t ROSCCSR;                           /**< ROSC Control Status, offset: 0x400 */
       uint8_t RESERVED_11[508];
  __IO uint32_t SPLLCSR;                           /**< SPLL Control Status, offset: 0x600 */
  __IO uint32_t SPLLCTRL;                          /**< SPLL Control, offset: 0x604 */
  __I  uint32_t SPLLSTAT;                          /**< SPLL Status, offset: 0x608 */
  __IO uint32_t SPLLNDIV;                          /**< SPLL N Divider, offset: 0x60C */
  __IO uint32_t SPLLMDIV;                          /**< SPLL M Divider, offset: 0x610 */
  __IO uint32_t SPLLPDIV;                          /**< SPLL P Divider, offset: 0x614 */
  __IO uint32_t SPLLLOCK_CNFG;                     /**< SPLL LOCK Configuration, offset: 0x618 */
       uint8_t RESERVED_12[4];
  __I  uint32_t SPLLSSCGSTAT;                      /**< SPLL SSCG Status, offset: 0x620 */
  __IO uint32_t SPLLSSCG0;                         /**< SPLL Spread Spectrum Control 0, offset: 0x624 */
  __IO uint32_t SPLLSSCG1;                         /**< SPLL Spread Spectrum Control 1, offset: 0x628 */
       uint8_t RESERVED_13[468];
  __IO uint32_t LDOCSR;                            /**< LDO Control and Status, offset: 0x800 */
} SCG_Type;

/* ----------------------------------------------------------------------------
   -- SCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Masks SCG Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define SCG_VERID_VERSION_MASK                   (0xFFFFFFFFU)
#define SCG_VERID_VERSION_SHIFT                  (0U)
/*! VERSION - SCG Version Number */
#define SCG_VERID_VERSION(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_VERID_VERSION_SHIFT)) & SCG_VERID_VERSION_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define SCG_PARAM_SOSCCLKPRES_MASK               (0x2U)
#define SCG_PARAM_SOSCCLKPRES_SHIFT              (1U)
/*! SOSCCLKPRES - SOSC Clock Present
 *  0b0..SOSC clock source is not present
 *  0b1..SOSC clock source is present
 */
#define SCG_PARAM_SOSCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_SOSCCLKPRES_SHIFT)) & SCG_PARAM_SOSCCLKPRES_MASK)

#define SCG_PARAM_SIRCCLKPRES_MASK               (0x4U)
#define SCG_PARAM_SIRCCLKPRES_SHIFT              (2U)
/*! SIRCCLKPRES - SIRC Clock Present
 *  0b0..SIRC clock source is not present
 *  0b1..SIRC clock source is present
 */
#define SCG_PARAM_SIRCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_SIRCCLKPRES_SHIFT)) & SCG_PARAM_SIRCCLKPRES_MASK)

#define SCG_PARAM_FIRCCLKPRES_MASK               (0x8U)
#define SCG_PARAM_FIRCCLKPRES_SHIFT              (3U)
/*! FIRCCLKPRES - FIRC Clock Present
 *  0b0..FIRC clock source is not present
 *  0b1..FIRC clock source is present
 */
#define SCG_PARAM_FIRCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_FIRCCLKPRES_SHIFT)) & SCG_PARAM_FIRCCLKPRES_MASK)

#define SCG_PARAM_ROSCCLKPRES_MASK               (0x10U)
#define SCG_PARAM_ROSCCLKPRES_SHIFT              (4U)
/*! ROSCCLKPRES - ROSC Clock Present
 *  0b0..ROSC clock source is not present
 *  0b1..ROSC clock source is present
 */
#define SCG_PARAM_ROSCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_ROSCCLKPRES_SHIFT)) & SCG_PARAM_ROSCCLKPRES_MASK)

#define SCG_PARAM_SPLLCLKPRES_MASK               (0x40U)
#define SCG_PARAM_SPLLCLKPRES_SHIFT              (6U)
/*! SPLLCLKPRES - SPLL Clock Present
 *  0b0..SPLL clock source is not present
 *  0b1..SPLL clock source is present
 */
#define SCG_PARAM_SPLLCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_SPLLCLKPRES_SHIFT)) & SCG_PARAM_SPLLCLKPRES_MASK)
/*! @} */

/*! @name TRIM_LOCK - Trim Lock */
/*! @{ */

#define SCG_TRIM_LOCK_TRIM_UNLOCK_MASK           (0x1U)
#define SCG_TRIM_LOCK_TRIM_UNLOCK_SHIFT          (0U)
/*! TRIM_UNLOCK - TRIM_UNLOCK
 *  0b0..SCG Trim Registers locked and not writable.
 *  0b1..SCG Trim registers unlocked and writable.
 */
#define SCG_TRIM_LOCK_TRIM_UNLOCK(x)             (((uint32_t)(((uint32_t)(x)) << SCG_TRIM_LOCK_TRIM_UNLOCK_SHIFT)) & SCG_TRIM_LOCK_TRIM_UNLOCK_MASK)

#define SCG_TRIM_LOCK_IFR_DISABLE_MASK           (0x2U)
#define SCG_TRIM_LOCK_IFR_DISABLE_SHIFT          (1U)
/*! IFR_DISABLE - IFR_DISABLE
 *  0b0..IFR write access to SCG trim registers not disabled. The SCG Trim registers are reprogrammed with the IFR values after any system reset.
 *  0b1..IFR write access to SCG trim registers during system reset is blocked.
 */
#define SCG_TRIM_LOCK_IFR_DISABLE(x)             (((uint32_t)(((uint32_t)(x)) << SCG_TRIM_LOCK_IFR_DISABLE_SHIFT)) & SCG_TRIM_LOCK_IFR_DISABLE_MASK)

#define SCG_TRIM_LOCK_TRIM_LOCK_KEY_MASK         (0xFFFF0000U)
#define SCG_TRIM_LOCK_TRIM_LOCK_KEY_SHIFT        (16U)
/*! TRIM_LOCK_KEY - TRIM_LOCK_KEY */
#define SCG_TRIM_LOCK_TRIM_LOCK_KEY(x)           (((uint32_t)(((uint32_t)(x)) << SCG_TRIM_LOCK_TRIM_LOCK_KEY_SHIFT)) & SCG_TRIM_LOCK_TRIM_LOCK_KEY_MASK)
/*! @} */

/*! @name CSR - Clock Status */
/*! @{ */

#define SCG_CSR_SCS_MASK                         (0x7000000U)
#define SCG_CSR_SCS_SHIFT                        (24U)
/*! SCS - System Clock Source
 *  0b001..SOSC
 *  0b010..SIRC
 *  0b011..FIRC
 *  0b100..ROSC
 *  0b110..SPLL
 */
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x)) << SCG_CSR_SCS_SHIFT)) & SCG_CSR_SCS_MASK)
/*! @} */

/*! @name RCCR - Run Clock Control */
/*! @{ */

#define SCG_RCCR_SCS_MASK                        (0x7000000U)
#define SCG_RCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b001..SOSC
 *  0b010..SIRC
 *  0b011..FIRC
 *  0b100..ROSC
 *  0b110..SPLL
 */
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_SCS_SHIFT)) & SCG_RCCR_SCS_MASK)
/*! @} */

/*! @name SOSCCSR - SOSC Control Status */
/*! @{ */

#define SCG_SOSCCSR_SOSCEN_MASK                  (0x1U)
#define SCG_SOSCCSR_SOSCEN_SHIFT                 (0U)
/*! SOSCEN - SOSC Enable
 *  0b0..SOSC is disabled
 *  0b1..SOSC is enabled
 */
#define SCG_SOSCCSR_SOSCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCEN_SHIFT)) & SCG_SOSCCSR_SOSCEN_MASK)

#define SCG_SOSCCSR_SOSCSTEN_MASK                (0x2U)
#define SCG_SOSCCSR_SOSCSTEN_SHIFT               (1U)
/*! SOSCSTEN - SOSC Stop Enable
 *  0b0..SOSC is disabled in Deep Sleep mode
 *  0b1..SOSC is enabled in Deep Sleep mode only if SOSCEN is set
 */
#define SCG_SOSCCSR_SOSCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSTEN_SHIFT)) & SCG_SOSCCSR_SOSCSTEN_MASK)

#define SCG_SOSCCSR_SOSCCM_MASK                  (0x10000U)
#define SCG_SOSCCSR_SOSCCM_SHIFT                 (16U)
/*! SOSCCM - SOSC Clock Monitor Enable
 *  0b0..SOSC Clock Monitor is disabled
 *  0b1..SOSC Clock Monitor is enabled
 */
#define SCG_SOSCCSR_SOSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCM_SHIFT)) & SCG_SOSCCSR_SOSCCM_MASK)

#define SCG_SOSCCSR_SOSCCMRE_MASK                (0x20000U)
#define SCG_SOSCCSR_SOSCCMRE_SHIFT               (17U)
/*! SOSCCMRE - SOSC Clock Monitor Reset Enable
 *  0b0..Clock monitor generates an interrupt when an error is detected
 *  0b1..Clock monitor generates a reset when an error is detected
 */
#define SCG_SOSCCSR_SOSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCMRE_SHIFT)) & SCG_SOSCCSR_SOSCCMRE_MASK)

#define SCG_SOSCCSR_LK_MASK                      (0x800000U)
#define SCG_SOSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..This Control Status Register can be written
 *  0b1..This Control Status Register cannot be written
 */
#define SCG_SOSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_LK_SHIFT)) & SCG_SOSCCSR_LK_MASK)

#define SCG_SOSCCSR_SOSCVLD_MASK                 (0x1000000U)
#define SCG_SOSCCSR_SOSCVLD_SHIFT                (24U)
/*! SOSCVLD - SOSC Valid
 *  0b0..SOSC is not enabled or clock is not valid
 *  0b1..SOSC is enabled and output clock is valid
 */
#define SCG_SOSCCSR_SOSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCVLD_SHIFT)) & SCG_SOSCCSR_SOSCVLD_MASK)

#define SCG_SOSCCSR_SOSCSEL_MASK                 (0x2000000U)
#define SCG_SOSCCSR_SOSCSEL_SHIFT                (25U)
/*! SOSCSEL - SOSC Selected
 *  0b0..SOSC is not the system clock source
 *  0b1..SOSC is the system clock source
 */
#define SCG_SOSCCSR_SOSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSEL_SHIFT)) & SCG_SOSCCSR_SOSCSEL_MASK)

#define SCG_SOSCCSR_SOSCERR_MASK                 (0x4000000U)
#define SCG_SOSCCSR_SOSCERR_SHIFT                (26U)
/*! SOSCERR - SOSC Clock Error
 *  0b0..SOSC Clock Monitor is disabled or has not detected an error
 *  0b1..SOSC Clock Monitor is enabled and detected an error
 */
#define SCG_SOSCCSR_SOSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCERR_SHIFT)) & SCG_SOSCCSR_SOSCERR_MASK)

#define SCG_SOSCCSR_SOSCVLD_IE_MASK              (0x40000000U)
#define SCG_SOSCCSR_SOSCVLD_IE_SHIFT             (30U)
/*! SOSCVLD_IE - SOSC Valid Interrupt Enable
 *  0b0..SOSCVLD interrupt is not enabled
 *  0b1..SOSCVLD interrupt is enabled
 */
#define SCG_SOSCCSR_SOSCVLD_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCVLD_IE_SHIFT)) & SCG_SOSCCSR_SOSCVLD_IE_MASK)

#define SCG_SOSCCSR_SOSC_SAFE_EN_MASK            (0x80000000U)
#define SCG_SOSCCSR_SOSC_SAFE_EN_SHIFT           (31U)
/*! SOSC_SAFE_EN - SOSC Clock Safety Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SCG_SOSCCSR_SOSC_SAFE_EN(x)              (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSC_SAFE_EN_SHIFT)) & SCG_SOSCCSR_SOSC_SAFE_EN_MASK)
/*! @} */

/*! @name SOSCCFG - SOSC Configuration */
/*! @{ */

#define SCG_SOSCCFG_EREFS_MASK                   (0x4U)
#define SCG_SOSCCFG_EREFS_SHIFT                  (2U)
/*! EREFS - External Reference Select
 *  0b0..External reference clock selected.
 *  0b1..Internal crystal oscillator of OSC selected.
 */
#define SCG_SOSCCFG_EREFS(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_EREFS_SHIFT)) & SCG_SOSCCFG_EREFS_MASK)

#define SCG_SOSCCFG_RANGE_MASK                   (0x30U)
#define SCG_SOSCCFG_RANGE_SHIFT                  (4U)
/*! RANGE - SOSC Range Select
 *  0b00..Frequency range select of 8-16 MHz.
 *  0b01..Frequency range select of 16-25 MHz.
 *  0b10..Frequency range select of 25-40 MHz.
 *  0b11..Frequency range select of 40-50 MHz.
 */
#define SCG_SOSCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_RANGE_SHIFT)) & SCG_SOSCCFG_RANGE_MASK)
/*! @} */

/*! @name SIRCCSR - SIRC Control Status */
/*! @{ */

#define SCG_SIRCCSR_SIRCSTEN_MASK                (0x2U)
#define SCG_SIRCCSR_SIRCSTEN_SHIFT               (1U)
/*! SIRCSTEN - SIRC Stop Enable
 *  0b0..SIRC is disabled in Deep Sleep mode
 *  0b1..SIRC is enabled in Deep Sleep mode
 */
#define SCG_SIRCCSR_SIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSTEN_SHIFT)) & SCG_SIRCCSR_SIRCSTEN_MASK)

#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK      (0x20U)
#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_SHIFT     (5U)
/*! SIRC_CLK_PERIPH_EN - SIRC Clock to Peripherals Enable
 *  0b0..SIRC clock to peripherals is disabled
 *  0b1..SIRC clock to peripherals is enabled
 */
#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN(x)        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_SHIFT)) & SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK)

#define SCG_SIRCCSR_SIRCTREN_MASK                (0x100U)
#define SCG_SIRCCSR_SIRCTREN_SHIFT               (8U)
/*! SIRCTREN - SIRC 12 MHz Trim Enable (SIRCCFG[RANGE]=1)
 *  0b0..Disables trimming SIRC to an external clock source
 *  0b1..Enables trimming SIRC to an external clock source
 */
#define SCG_SIRCCSR_SIRCTREN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCTREN_SHIFT)) & SCG_SIRCCSR_SIRCTREN_MASK)

#define SCG_SIRCCSR_SIRCTRUP_MASK                (0x200U)
#define SCG_SIRCCSR_SIRCTRUP_SHIFT               (9U)
/*! SIRCTRUP - SIRC Trim Update
 *  0b0..Disables SIRC trimming updates
 *  0b1..Enables SIRC trimming updates
 */
#define SCG_SIRCCSR_SIRCTRUP(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCTRUP_SHIFT)) & SCG_SIRCCSR_SIRCTRUP_MASK)

#define SCG_SIRCCSR_TRIM_LOCK_MASK               (0x400U)
#define SCG_SIRCCSR_TRIM_LOCK_SHIFT              (10U)
/*! TRIM_LOCK - SIRC TRIM LOCK
 *  0b0..SIRC auto trim not locked to target frequency range
 *  0b1..SIRC auto trim locked to target frequency range
 */
#define SCG_SIRCCSR_TRIM_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_TRIM_LOCK_SHIFT)) & SCG_SIRCCSR_TRIM_LOCK_MASK)

#define SCG_SIRCCSR_COARSE_TRIM_BYPASS_MASK      (0x800U)
#define SCG_SIRCCSR_COARSE_TRIM_BYPASS_SHIFT     (11U)
/*! COARSE_TRIM_BYPASS - Coarse Auto Trim Bypass
 *  0b0..SIRC Coarse Auto Trim NOT Bypassed
 *  0b1..SIRC Coarse Auto Trim Bypassed
 */
#define SCG_SIRCCSR_COARSE_TRIM_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_COARSE_TRIM_BYPASS_SHIFT)) & SCG_SIRCCSR_COARSE_TRIM_BYPASS_MASK)

#define SCG_SIRCCSR_LK_MASK                      (0x800000U)
#define SCG_SIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_SIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_LK_SHIFT)) & SCG_SIRCCSR_LK_MASK)

#define SCG_SIRCCSR_SIRCVLD_MASK                 (0x1000000U)
#define SCG_SIRCCSR_SIRCVLD_SHIFT                (24U)
/*! SIRCVLD - SIRC Valid
 *  0b0..SIRC is not enabled or clock is not valid
 *  0b1..SIRC is enabled and output clock is valid
 */
#define SCG_SIRCCSR_SIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCVLD_SHIFT)) & SCG_SIRCCSR_SIRCVLD_MASK)

#define SCG_SIRCCSR_SIRCSEL_MASK                 (0x2000000U)
#define SCG_SIRCCSR_SIRCSEL_SHIFT                (25U)
/*! SIRCSEL - SIRC Selected
 *  0b0..SIRC is not the system clock source
 *  0b1..SIRC is the system clock source
 */
#define SCG_SIRCCSR_SIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSEL_SHIFT)) & SCG_SIRCCSR_SIRCSEL_MASK)

#define SCG_SIRCCSR_SIRCERR_MASK                 (0x4000000U)
#define SCG_SIRCCSR_SIRCERR_SHIFT                (26U)
/*! SIRCERR - SIRC Clock Error
 *  0b0..Error not detected with the SIRC trimming
 *  0b1..Error detected with the SIRC trimming
 */
#define SCG_SIRCCSR_SIRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCERR_SHIFT)) & SCG_SIRCCSR_SIRCERR_MASK)

#define SCG_SIRCCSR_SIRCERR_IE_MASK              (0x8000000U)
#define SCG_SIRCCSR_SIRCERR_IE_SHIFT             (27U)
/*! SIRCERR_IE - SIRC Clock Error Interrupt Enable
 *  0b0..SIRCERR interrupt is not enabled
 *  0b1..SIRCERR interrupt is enabled
 */
#define SCG_SIRCCSR_SIRCERR_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCERR_IE_SHIFT)) & SCG_SIRCCSR_SIRCERR_IE_MASK)
/*! @} */

/*! @name SIRCTCFG - SIRC Trim Configuration */
/*! @{ */

#define SCG_SIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_SIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..SOSC. This option requires that SOSC be divided using the TRIMDIV field to get a frequency of 1 MHz.
 *  0b11..ROSC (32.768 KHz)
 */
#define SCG_SIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTCFG_TRIMSRC_SHIFT)) & SCG_SIRCTCFG_TRIMSRC_MASK)

#define SCG_SIRCTCFG_TRIMDIV_MASK                (0x7F0000U)
#define SCG_SIRCTCFG_TRIMDIV_SHIFT               (16U)
/*! TRIMDIV - SIRC Trim Pre-divider */
#define SCG_SIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTCFG_TRIMDIV_SHIFT)) & SCG_SIRCTCFG_TRIMDIV_MASK)
/*! @} */

/*! @name SIRCTRIM - SIRC Trim */
/*! @{ */

#define SCG_SIRCTRIM_CCOTRIM_MASK                (0x3FU)
#define SCG_SIRCTRIM_CCOTRIM_SHIFT               (0U)
/*! CCOTRIM - CCO Trim */
#define SCG_SIRCTRIM_CCOTRIM(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_CCOTRIM_SHIFT)) & SCG_SIRCTRIM_CCOTRIM_MASK)

#define SCG_SIRCTRIM_CLTRIM_MASK                 (0x3F00U)
#define SCG_SIRCTRIM_CLTRIM_SHIFT                (8U)
/*! CLTRIM - CL Trim */
#define SCG_SIRCTRIM_CLTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_CLTRIM_SHIFT)) & SCG_SIRCTRIM_CLTRIM_MASK)

#define SCG_SIRCTRIM_TCTRIM_MASK                 (0x1F0000U)
#define SCG_SIRCTRIM_TCTRIM_SHIFT                (16U)
/*! TCTRIM - Trim Temp */
#define SCG_SIRCTRIM_TCTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_TCTRIM_SHIFT)) & SCG_SIRCTRIM_TCTRIM_MASK)

#define SCG_SIRCTRIM_FVCHTRIM_MASK               (0x1F000000U)
#define SCG_SIRCTRIM_FVCHTRIM_SHIFT              (24U)
#define SCG_SIRCTRIM_FVCHTRIM(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_FVCHTRIM_SHIFT)) & SCG_SIRCTRIM_FVCHTRIM_MASK)
/*! @} */

/*! @name SIRCSTAT - SIRC Auto-trimming Status */
/*! @{ */

#define SCG_SIRCSTAT_CCOTRIM_MASK                (0x3FU)
#define SCG_SIRCSTAT_CCOTRIM_SHIFT               (0U)
/*! CCOTRIM - CCO Trim */
#define SCG_SIRCSTAT_CCOTRIM(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCSTAT_CCOTRIM_SHIFT)) & SCG_SIRCSTAT_CCOTRIM_MASK)

#define SCG_SIRCSTAT_CLTRIM_MASK                 (0x3F00U)
#define SCG_SIRCSTAT_CLTRIM_SHIFT                (8U)
/*! CLTRIM - CL Trim */
#define SCG_SIRCSTAT_CLTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCSTAT_CLTRIM_SHIFT)) & SCG_SIRCSTAT_CLTRIM_MASK)
/*! @} */

/*! @name FIRCCSR - FIRC Control Status */
/*! @{ */

#define SCG_FIRCCSR_FIRCEN_MASK                  (0x1U)
#define SCG_FIRCCSR_FIRCEN_SHIFT                 (0U)
/*! FIRCEN - FIRC Enable
 *  0b0..FIRC is disabled
 *  0b1..FIRC is enabled
 */
#define SCG_FIRCCSR_FIRCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCEN_SHIFT)) & SCG_FIRCCSR_FIRCEN_MASK)

#define SCG_FIRCCSR_FIRCSTEN_MASK                (0x2U)
#define SCG_FIRCCSR_FIRCSTEN_SHIFT               (1U)
/*! FIRCSTEN - FIRC Stop Enable
 *  0b0..FIRC is disabled in Deep Sleep mode
 *  0b1..FIRC is enabled in Deep Sleep mode
 */
#define SCG_FIRCCSR_FIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSTEN_SHIFT)) & SCG_FIRCCSR_FIRCSTEN_MASK)

#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK     (0x10U)
#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_SHIFT    (4U)
/*! FIRC_SCLK_PERIPH_EN - FIRC_48MHz Clock to Peripherals Enable
 *  0b0..FIRC_48MHz disabled
 *  0b1..FIRC_48MHz enabled
 */
#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK     (0x20U)
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT    (5U)
/*! FIRC_FCLK_PERIPH_EN - FRO_HF_GATED to Peripherals Enable
 *  0b0..FRO_HF_GATED disabled
 *  0b1..FRO_HF_GATED enabled
 */
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_FIRCTREN_MASK                (0x100U)
#define SCG_FIRCCSR_FIRCTREN_SHIFT               (8U)
/*! FIRCTREN - FRO_HF Trim Enable
 *  0b0..Disables trimming FRO_HF by an external clock source
 *  0b1..Enables trimming FRO_HF by an external clock source
 */
#define SCG_FIRCCSR_FIRCTREN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTREN_SHIFT)) & SCG_FIRCCSR_FIRCTREN_MASK)

#define SCG_FIRCCSR_FIRCTRUP_MASK                (0x200U)
#define SCG_FIRCCSR_FIRCTRUP_SHIFT               (9U)
/*! FIRCTRUP - FIRC Trim Update
 *  0b0..Disables FIRC trimming updates
 *  0b1..Enables FIRC trimming updates
 */
#define SCG_FIRCCSR_FIRCTRUP(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTRUP_SHIFT)) & SCG_FIRCCSR_FIRCTRUP_MASK)

#define SCG_FIRCCSR_TRIM_LOCK_MASK               (0x400U)
#define SCG_FIRCCSR_TRIM_LOCK_SHIFT              (10U)
/*! TRIM_LOCK - FIRC TRIM LOCK
 *  0b0..FIRC auto trim not locked to target frequency range
 *  0b1..FIRC auto trim locked to target frequency range
 */
#define SCG_FIRCCSR_TRIM_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_TRIM_LOCK_SHIFT)) & SCG_FIRCCSR_TRIM_LOCK_MASK)

#define SCG_FIRCCSR_COARSE_TRIM_BYPASS_MASK      (0x800U)
#define SCG_FIRCCSR_COARSE_TRIM_BYPASS_SHIFT     (11U)
/*! COARSE_TRIM_BYPASS - Coarse Auto Trim Bypass
 *  0b0..FIRC Coarse Auto Trim NOT Bypassed
 *  0b1..FIRC Coarse Auto Trim Bypassed
 */
#define SCG_FIRCCSR_COARSE_TRIM_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_COARSE_TRIM_BYPASS_SHIFT)) & SCG_FIRCCSR_COARSE_TRIM_BYPASS_MASK)

#define SCG_FIRCCSR_LK_MASK                      (0x800000U)
#define SCG_FIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_FIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_LK_SHIFT)) & SCG_FIRCCSR_LK_MASK)

#define SCG_FIRCCSR_FIRCVLD_MASK                 (0x1000000U)
#define SCG_FIRCCSR_FIRCVLD_SHIFT                (24U)
/*! FIRCVLD - FIRC Valid status
 *  0b0..FIRC is not enabled or clock is not valid.
 *  0b1..FIRC is enabled and output clock is valid. The clock is valid after there is an output clock from the FIRC analog.
 */
#define SCG_FIRCCSR_FIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCVLD_SHIFT)) & SCG_FIRCCSR_FIRCVLD_MASK)

#define SCG_FIRCCSR_FIRCSEL_MASK                 (0x2000000U)
#define SCG_FIRCCSR_FIRCSEL_SHIFT                (25U)
/*! FIRCSEL - FIRC Selected
 *  0b0..FIRC is not the system clock source
 *  0b1..FIRC is the system clock source
 */
#define SCG_FIRCCSR_FIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSEL_SHIFT)) & SCG_FIRCCSR_FIRCSEL_MASK)

#define SCG_FIRCCSR_FIRCERR_MASK                 (0x4000000U)
#define SCG_FIRCCSR_FIRCERR_SHIFT                (26U)
/*! FIRCERR - FIRC Clock Error
 *  0b0..Error not detected with the FIRC trimming
 *  0b1..Error detected with the FIRC trimming
 */
#define SCG_FIRCCSR_FIRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCERR_SHIFT)) & SCG_FIRCCSR_FIRCERR_MASK)

#define SCG_FIRCCSR_FIRCERR_IE_MASK              (0x8000000U)
#define SCG_FIRCCSR_FIRCERR_IE_SHIFT             (27U)
/*! FIRCERR_IE - FIRC Clock Error Interrupt Enable
 *  0b0..FIRCERR interrupt is not enabled
 *  0b1..FIRCERR interrupt is enabled
 */
#define SCG_FIRCCSR_FIRCERR_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCERR_IE_SHIFT)) & SCG_FIRCCSR_FIRCERR_IE_MASK)

#define SCG_FIRCCSR_FIRCACC_IE_MASK              (0x40000000U)
#define SCG_FIRCCSR_FIRCACC_IE_SHIFT             (30U)
/*! FIRCACC_IE - FIRC Accurate Interrupt Enable
 *  0b0..FIRCACC interrupt is not enabled
 *  0b1..FIRCACC interrupt is enabled
 */
#define SCG_FIRCCSR_FIRCACC_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCACC_IE_SHIFT)) & SCG_FIRCCSR_FIRCACC_IE_MASK)

#define SCG_FIRCCSR_FIRCACC_MASK                 (0x80000000U)
#define SCG_FIRCCSR_FIRCACC_SHIFT                (31U)
/*! FIRCACC - FIRC Frequency Accurate
 *  0b0..FIRC is not enabled or clock is not accurate.
 *  0b1..FIRC is enabled and output clock is accurate after some preparation time which is obtained by counting FRO_HF clock.
 */
#define SCG_FIRCCSR_FIRCACC(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCACC_SHIFT)) & SCG_FIRCCSR_FIRCACC_MASK)
/*! @} */

/*! @name FIRCCFG - FIRC Configuration */
/*! @{ */

#define SCG_FIRCCFG_FREQ_SEL_MASK                (0xEU)
#define SCG_FIRCCFG_FREQ_SEL_SHIFT               (1U)
/*! FREQ_SEL - Frequency select
 *  0b001..48 MHz FIRC clock selected, divided from 192 MHz
 *  0b011..64 MHz FIRC clock selected
 *  0b101..96 MHz FIRC clock selected
 *  0b111..192 MHz FIRC clock selected
 */
#define SCG_FIRCCFG_FREQ_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCFG_FREQ_SEL_SHIFT)) & SCG_FIRCCFG_FREQ_SEL_MASK)
/*! @} */

/*! @name FIRCTCFG - FIRC Trim Configuration */
/*! @{ */

#define SCG_FIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_FIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..USB. This option provides fine trim value directly from USB, without using clock.
 *  0b01..USB Start of Frame (1 KHz). This option does not use TRIMDIV .
 *  0b10..SOSC. This option requires that SOSC be divided using the TRIMDIV field to get a frequency of 1 MHz.
 *  0b11..ROSC (32.768 KHz)
 */
#define SCG_FIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMSRC_SHIFT)) & SCG_FIRCTCFG_TRIMSRC_MASK)

#define SCG_FIRCTCFG_TRIMDIV_MASK                (0x7F0000U)
#define SCG_FIRCTCFG_TRIMDIV_SHIFT               (16U)
/*! TRIMDIV - FIRC Trim Pre-divider */
#define SCG_FIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMDIV_SHIFT)) & SCG_FIRCTCFG_TRIMDIV_MASK)
/*! @} */

/*! @name FIRCTRIM - FIRC Trim */
/*! @{ */

#define SCG_FIRCTRIM_TRIMFINE_MASK               (0xFFU)
#define SCG_FIRCTRIM_TRIMFINE_SHIFT              (0U)
/*! TRIMFINE - Trim Fine */
#define SCG_FIRCTRIM_TRIMFINE(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMFINE_SHIFT)) & SCG_FIRCTRIM_TRIMFINE_MASK)

#define SCG_FIRCTRIM_TRIMCOAR_MASK               (0x3F00U)
#define SCG_FIRCTRIM_TRIMCOAR_SHIFT              (8U)
/*! TRIMCOAR - Trim Coarse */
#define SCG_FIRCTRIM_TRIMCOAR(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMCOAR_SHIFT)) & SCG_FIRCTRIM_TRIMCOAR_MASK)

#define SCG_FIRCTRIM_TRIMTEMP_MASK               (0xF0000U)
#define SCG_FIRCTRIM_TRIMTEMP_SHIFT              (16U)
/*! TRIMTEMP - Trim Temperature */
#define SCG_FIRCTRIM_TRIMTEMP(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMTEMP_SHIFT)) & SCG_FIRCTRIM_TRIMTEMP_MASK)

#define SCG_FIRCTRIM_TRIMSTART_MASK              (0x3F000000U)
#define SCG_FIRCTRIM_TRIMSTART_SHIFT             (24U)
/*! TRIMSTART - Trim Start */
#define SCG_FIRCTRIM_TRIMSTART(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMSTART_SHIFT)) & SCG_FIRCTRIM_TRIMSTART_MASK)
/*! @} */

/*! @name FIRCSTAT - FIRC Auto-trimming Status */
/*! @{ */

#define SCG_FIRCSTAT_TRIMFINE_MASK               (0xFFU)
#define SCG_FIRCSTAT_TRIMFINE_SHIFT              (0U)
/*! TRIMFINE - Trim Fine */
#define SCG_FIRCSTAT_TRIMFINE(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCSTAT_TRIMFINE_SHIFT)) & SCG_FIRCSTAT_TRIMFINE_MASK)

#define SCG_FIRCSTAT_TRIMCOAR_MASK               (0x3F00U)
#define SCG_FIRCSTAT_TRIMCOAR_SHIFT              (8U)
/*! TRIMCOAR - Trim Coarse */
#define SCG_FIRCSTAT_TRIMCOAR(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCSTAT_TRIMCOAR_SHIFT)) & SCG_FIRCSTAT_TRIMCOAR_MASK)
/*! @} */

/*! @name FIRCATC1 - FIRC Auto-trimming Counter 1 */
/*! @{ */

#define SCG_FIRCATC1_IDEALC_SOSC_MASK            (0xFFFFU)
#define SCG_FIRCATC1_IDEALC_SOSC_SHIFT           (0U)
/*! IDEALC_SOSC - Ideal Counter SOSC */
#define SCG_FIRCATC1_IDEALC_SOSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC1_IDEALC_SOSC_SHIFT)) & SCG_FIRCATC1_IDEALC_SOSC_MASK)

#define SCG_FIRCATC1_SAMCYC_SOSC_MASK            (0xFF0000U)
#define SCG_FIRCATC1_SAMCYC_SOSC_SHIFT           (16U)
/*! SAMCYC_SOSC - Sample Cycle SOSC */
#define SCG_FIRCATC1_SAMCYC_SOSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC1_SAMCYC_SOSC_SHIFT)) & SCG_FIRCATC1_SAMCYC_SOSC_MASK)

#define SCG_FIRCATC1_SETCYC_SOSC_MASK            (0xFF000000U)
#define SCG_FIRCATC1_SETCYC_SOSC_SHIFT           (24U)
/*! SETCYC_SOSC - Setup Cycle SOSC */
#define SCG_FIRCATC1_SETCYC_SOSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC1_SETCYC_SOSC_SHIFT)) & SCG_FIRCATC1_SETCYC_SOSC_MASK)
/*! @} */

/*! @name FIRCATC2 - FIRC Auto-trimming Counter 2 */
/*! @{ */

#define SCG_FIRCATC2_COARMINC_SOSC_MASK          (0xFFFFU)
#define SCG_FIRCATC2_COARMINC_SOSC_SHIFT         (0U)
/*! COARMINC_SOSC - Coarse Trim Minimum Counter SOSC */
#define SCG_FIRCATC2_COARMINC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC2_COARMINC_SOSC_SHIFT)) & SCG_FIRCATC2_COARMINC_SOSC_MASK)

#define SCG_FIRCATC2_COARMAXC_SOSC_MASK          (0xFFFF0000U)
#define SCG_FIRCATC2_COARMAXC_SOSC_SHIFT         (16U)
/*! COARMAXC_SOSC - Coarse Trim Maximum Counter SOSC */
#define SCG_FIRCATC2_COARMAXC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC2_COARMAXC_SOSC_SHIFT)) & SCG_FIRCATC2_COARMAXC_SOSC_MASK)
/*! @} */

/*! @name FIRCATC3 - FIRC Auto-trimming Counter 3 */
/*! @{ */

#define SCG_FIRCATC3_FINEMINC_SOSC_MASK          (0xFFFFU)
#define SCG_FIRCATC3_FINEMINC_SOSC_SHIFT         (0U)
/*! FINEMINC_SOSC - Fine Trim Minimum Counter SOSC */
#define SCG_FIRCATC3_FINEMINC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC3_FINEMINC_SOSC_SHIFT)) & SCG_FIRCATC3_FINEMINC_SOSC_MASK)

#define SCG_FIRCATC3_FINEMAXC_SOSC_MASK          (0xFFFF0000U)
#define SCG_FIRCATC3_FINEMAXC_SOSC_SHIFT         (16U)
/*! FINEMAXC_SOSC - Fine Trim Maximum Counter SOSC */
#define SCG_FIRCATC3_FINEMAXC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC3_FINEMAXC_SOSC_SHIFT)) & SCG_FIRCATC3_FINEMAXC_SOSC_MASK)
/*! @} */

/*! @name FIRCATC4 - FIRC Auto-trimming Counter 4 */
/*! @{ */

#define SCG_FIRCATC4_IDEALC_ROSC_MASK            (0xFFFFU)
#define SCG_FIRCATC4_IDEALC_ROSC_SHIFT           (0U)
/*! IDEALC_ROSC - Ideal Counter ROSC */
#define SCG_FIRCATC4_IDEALC_ROSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC4_IDEALC_ROSC_SHIFT)) & SCG_FIRCATC4_IDEALC_ROSC_MASK)

#define SCG_FIRCATC4_SETCYC_ROSC_MASK            (0xFF0000U)
#define SCG_FIRCATC4_SETCYC_ROSC_SHIFT           (16U)
/*! SETCYC_ROSC - Setup Cycle ROSC */
#define SCG_FIRCATC4_SETCYC_ROSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC4_SETCYC_ROSC_SHIFT)) & SCG_FIRCATC4_SETCYC_ROSC_MASK)

#define SCG_FIRCATC4_SAMCYC_ROSC_MASK            (0xFF000000U)
#define SCG_FIRCATC4_SAMCYC_ROSC_SHIFT           (24U)
/*! SAMCYC_ROSC - Sample Cycle ROSC */
#define SCG_FIRCATC4_SAMCYC_ROSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC4_SAMCYC_ROSC_SHIFT)) & SCG_FIRCATC4_SAMCYC_ROSC_MASK)
/*! @} */

/*! @name FIRCATC5 - FIRC Auto-trimming Counter 5 */
/*! @{ */

#define SCG_FIRCATC5_COARMINC_ROSC_MASK          (0xFFFFU)
#define SCG_FIRCATC5_COARMINC_ROSC_SHIFT         (0U)
/*! COARMINC_ROSC - Coarse Trim Minimum Counter ROSC */
#define SCG_FIRCATC5_COARMINC_ROSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC5_COARMINC_ROSC_SHIFT)) & SCG_FIRCATC5_COARMINC_ROSC_MASK)

#define SCG_FIRCATC5_COARMAXC_ROSC_MASK          (0xFFFF0000U)
#define SCG_FIRCATC5_COARMAXC_ROSC_SHIFT         (16U)
/*! COARMAXC_ROSC - Coarse Trim Maximum Counter ROSC */
#define SCG_FIRCATC5_COARMAXC_ROSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC5_COARMAXC_ROSC_SHIFT)) & SCG_FIRCATC5_COARMAXC_ROSC_MASK)
/*! @} */

/*! @name FIRCATC6 - FIRC Auto-trimming Counter 6 */
/*! @{ */

#define SCG_FIRCATC6_FINEMINC_ROSC_MASK          (0xFFFFU)
#define SCG_FIRCATC6_FINEMINC_ROSC_SHIFT         (0U)
/*! FINEMINC_ROSC - Fine Trim Minimum Counter ROSC */
#define SCG_FIRCATC6_FINEMINC_ROSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC6_FINEMINC_ROSC_SHIFT)) & SCG_FIRCATC6_FINEMINC_ROSC_MASK)

#define SCG_FIRCATC6_FINEMAXC_ROSC_MASK          (0xFFFF0000U)
#define SCG_FIRCATC6_FINEMAXC_ROSC_SHIFT         (16U)
/*! FINEMAXC_ROSC - Fine Trim Maximum Counter ROSC */
#define SCG_FIRCATC6_FINEMAXC_ROSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC6_FINEMAXC_ROSC_SHIFT)) & SCG_FIRCATC6_FINEMAXC_ROSC_MASK)
/*! @} */

/*! @name FIRCATC7 - FIRC Auto-trimming Counter 7 */
/*! @{ */

#define SCG_FIRCATC7_IDEALC_SOF_MASK             (0xFFFFFU)
#define SCG_FIRCATC7_IDEALC_SOF_SHIFT            (0U)
/*! IDEALC_SOF - Ideal Counter SOF */
#define SCG_FIRCATC7_IDEALC_SOF(x)               (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC7_IDEALC_SOF_SHIFT)) & SCG_FIRCATC7_IDEALC_SOF_MASK)

#define SCG_FIRCATC7_SETCYC_SOF_MASK             (0xF000000U)
#define SCG_FIRCATC7_SETCYC_SOF_SHIFT            (24U)
/*! SETCYC_SOF - Setup Cycle SOF */
#define SCG_FIRCATC7_SETCYC_SOF(x)               (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC7_SETCYC_SOF_SHIFT)) & SCG_FIRCATC7_SETCYC_SOF_MASK)

#define SCG_FIRCATC7_SAMCYC_SOF_MASK             (0xF0000000U)
#define SCG_FIRCATC7_SAMCYC_SOF_SHIFT            (28U)
/*! SAMCYC_SOF - Sample Cycle SOF */
#define SCG_FIRCATC7_SAMCYC_SOF(x)               (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC7_SAMCYC_SOF_SHIFT)) & SCG_FIRCATC7_SAMCYC_SOF_MASK)
/*! @} */

/*! @name FIRCATC8 - FIRC Auto-trimming Counter 8 */
/*! @{ */

#define SCG_FIRCATC8_COARMAXC_SOF_MASK           (0xFFFFFU)
#define SCG_FIRCATC8_COARMAXC_SOF_SHIFT          (0U)
/*! COARMAXC_SOF - Coarse Trim Maximum Counter SOF */
#define SCG_FIRCATC8_COARMAXC_SOF(x)             (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC8_COARMAXC_SOF_SHIFT)) & SCG_FIRCATC8_COARMAXC_SOF_MASK)
/*! @} */

/*! @name FIRCATC9 - FIRC Auto-trimming Counter 9 */
/*! @{ */

#define SCG_FIRCATC9_COARMINC_SOF_MASK           (0xFFFFFU)
#define SCG_FIRCATC9_COARMINC_SOF_SHIFT          (0U)
/*! COARMINC_SOF - Coarse Trim Minimum Counter SOF */
#define SCG_FIRCATC9_COARMINC_SOF(x)             (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC9_COARMINC_SOF_SHIFT)) & SCG_FIRCATC9_COARMINC_SOF_MASK)
/*! @} */

/*! @name FIRCATC10 - FIRC Auto-trimming Counter 10 */
/*! @{ */

#define SCG_FIRCATC10_FINEMAXC_SOF_MASK          (0xFFFFFU)
#define SCG_FIRCATC10_FINEMAXC_SOF_SHIFT         (0U)
/*! FINEMAXC_SOF - Fine Trim Maximum Counter SOF */
#define SCG_FIRCATC10_FINEMAXC_SOF(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC10_FINEMAXC_SOF_SHIFT)) & SCG_FIRCATC10_FINEMAXC_SOF_MASK)
/*! @} */

/*! @name FIRCATC11 - FIRC Auto-trimming Counter 11 */
/*! @{ */

#define SCG_FIRCATC11_FINEMINC_SOF_MASK          (0xFFFFFU)
#define SCG_FIRCATC11_FINEMINC_SOF_SHIFT         (0U)
/*! FINEMINC_SOF - Fine Trim Minimum Counter SOF */
#define SCG_FIRCATC11_FINEMINC_SOF(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC11_FINEMINC_SOF_SHIFT)) & SCG_FIRCATC11_FINEMINC_SOF_MASK)
/*! @} */

/*! @name ROSCCSR - ROSC Control Status */
/*! @{ */

#define SCG_ROSCCSR_ROSCCM_MASK                  (0x10000U)
#define SCG_ROSCCSR_ROSCCM_SHIFT                 (16U)
/*! ROSCCM - ROSC Clock Monitor
 *  0b0..ROSC clock monitor is disabled
 *  0b1..ROSC clock monitor is enabled
 */
#define SCG_ROSCCSR_ROSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCCM_SHIFT)) & SCG_ROSCCSR_ROSCCM_MASK)

#define SCG_ROSCCSR_ROSCCMRE_MASK                (0x20000U)
#define SCG_ROSCCSR_ROSCCMRE_SHIFT               (17U)
/*! ROSCCMRE - ROSC Clock Monitor Reset Enable
 *  0b0..Clock monitor generates an interrupt when an error is detected
 *  0b1..Clock monitor generates a reset when an error is detected
 */
#define SCG_ROSCCSR_ROSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCCMRE_SHIFT)) & SCG_ROSCCSR_ROSCCMRE_MASK)

#define SCG_ROSCCSR_LK_MASK                      (0x800000U)
#define SCG_ROSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_ROSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_LK_SHIFT)) & SCG_ROSCCSR_LK_MASK)

#define SCG_ROSCCSR_ROSCVLD_MASK                 (0x1000000U)
#define SCG_ROSCCSR_ROSCVLD_SHIFT                (24U)
/*! ROSCVLD - ROSC Valid
 *  0b0..ROSC is not enabled or clock is not valid
 *  0b1..ROSC is enabled and output clock is valid
 */
#define SCG_ROSCCSR_ROSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCVLD_SHIFT)) & SCG_ROSCCSR_ROSCVLD_MASK)

#define SCG_ROSCCSR_ROSCSEL_MASK                 (0x2000000U)
#define SCG_ROSCCSR_ROSCSEL_SHIFT                (25U)
/*! ROSCSEL - ROSC Selected
 *  0b0..ROSC is not the system clock source
 *  0b1..ROSC is the system clock source
 */
#define SCG_ROSCCSR_ROSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCSEL_SHIFT)) & SCG_ROSCCSR_ROSCSEL_MASK)

#define SCG_ROSCCSR_ROSCERR_MASK                 (0x4000000U)
#define SCG_ROSCCSR_ROSCERR_SHIFT                (26U)
/*! ROSCERR - ROSC Clock Error
 *  0b0..ROSC Clock Monitor is disabled or has not detected an error
 *  0b1..ROSC Clock Monitor is enabled and detected an RTC loss of clock error has detected an error
 */
#define SCG_ROSCCSR_ROSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCERR_SHIFT)) & SCG_ROSCCSR_ROSCERR_MASK)
/*! @} */

/*! @name SPLLCSR - SPLL Control Status */
/*! @{ */

#define SCG_SPLLCSR_SPLLPWREN_MASK               (0x1U)
#define SCG_SPLLCSR_SPLLPWREN_SHIFT              (0U)
/*! SPLLPWREN - SPLL Power Enable
 *  0b0..SPLL clock is powered off
 *  0b1..SPLL clock is powered on
 */
#define SCG_SPLLCSR_SPLLPWREN(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLPWREN_SHIFT)) & SCG_SPLLCSR_SPLLPWREN_MASK)

#define SCG_SPLLCSR_SPLLCLKEN_MASK               (0x2U)
#define SCG_SPLLCSR_SPLLCLKEN_SHIFT              (1U)
/*! SPLLCLKEN - SPLL Clock Enable
 *  0b0..SPLL clock is disabled
 *  0b1..SPLL clock is enabled
 */
#define SCG_SPLLCSR_SPLLCLKEN(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLCLKEN_SHIFT)) & SCG_SPLLCSR_SPLLCLKEN_MASK)

#define SCG_SPLLCSR_SPLLSTEN_MASK                (0x4U)
#define SCG_SPLLCSR_SPLLSTEN_SHIFT               (2U)
/*! SPLLSTEN - SPLL Stop Enable
 *  0b0..SPLL is disabled in Deep Sleep mode
 *  0b1..SPLL is enabled in Deep Sleep mode
 */
#define SCG_SPLLCSR_SPLLSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLSTEN_SHIFT)) & SCG_SPLLCSR_SPLLSTEN_MASK)

#define SCG_SPLLCSR_FRM_CLOCKSTABLE_MASK         (0x8U)
#define SCG_SPLLCSR_FRM_CLOCKSTABLE_SHIFT        (3U)
/*! FRM_CLOCKSTABLE - Free running mode clock stable
 *  0b0..Free running mode clock stable is disabled
 *  0b1..Free running mode clock stable is enabled
 */
#define SCG_SPLLCSR_FRM_CLOCKSTABLE(x)           (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_FRM_CLOCKSTABLE_SHIFT)) & SCG_SPLLCSR_FRM_CLOCKSTABLE_MASK)

#define SCG_SPLLCSR_SPLL_DIV2_EN_MASK            (0x10U)
#define SCG_SPLLCSR_SPLL_DIV2_EN_SHIFT           (4U)
/*! SPLL_DIV2_EN - SPLL Divide-by-2 Enable
 *  0b0..SPLL clock divider is disabled
 *  0b1..SPLL clock divider is enabled
 */
#define SCG_SPLLCSR_SPLL_DIV2_EN(x)              (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLL_DIV2_EN_SHIFT)) & SCG_SPLLCSR_SPLL_DIV2_EN_MASK)

#define SCG_SPLLCSR_SPLLCM_MASK                  (0x10000U)
#define SCG_SPLLCSR_SPLLCM_SHIFT                 (16U)
/*! SPLLCM - SPLL Clock Monitor
 *  0b0..SPLL Clock Monitor is disabled
 *  0b1..SPLL Clock Monitor is enabled
 */
#define SCG_SPLLCSR_SPLLCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLCM_SHIFT)) & SCG_SPLLCSR_SPLLCM_MASK)

#define SCG_SPLLCSR_SPLLCMRE_MASK                (0x20000U)
#define SCG_SPLLCSR_SPLLCMRE_SHIFT               (17U)
/*! SPLLCMRE - SPLL Clock Monitor Reset Enable
 *  0b0..Clock monitor generates an interrupt when an error is detected
 *  0b1..Clock monitor generates a reset when an error is detected
 */
#define SCG_SPLLCSR_SPLLCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLCMRE_SHIFT)) & SCG_SPLLCSR_SPLLCMRE_MASK)

#define SCG_SPLLCSR_LK_MASK                      (0x800000U)
#define SCG_SPLLCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_SPLLCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_LK_SHIFT)) & SCG_SPLLCSR_LK_MASK)

#define SCG_SPLLCSR_SPLL_LOCK_MASK               (0x1000000U)
#define SCG_SPLLCSR_SPLL_LOCK_SHIFT              (24U)
/*! SPLL_LOCK - SPLL LOCK
 *  0b0..SPLL is not powered on or not locked
 *  0b1..SPLL is locked
 */
#define SCG_SPLLCSR_SPLL_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLL_LOCK_SHIFT)) & SCG_SPLLCSR_SPLL_LOCK_MASK)

#define SCG_SPLLCSR_SPLLSEL_MASK                 (0x2000000U)
#define SCG_SPLLCSR_SPLLSEL_SHIFT                (25U)
/*! SPLLSEL - SPLL Selected
 *  0b0..SPLL is not the system clock source
 *  0b1..SPLL is the system clock source
 */
#define SCG_SPLLCSR_SPLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLSEL_SHIFT)) & SCG_SPLLCSR_SPLLSEL_MASK)

#define SCG_SPLLCSR_SPLLERR_MASK                 (0x4000000U)
#define SCG_SPLLCSR_SPLLERR_SHIFT                (26U)
/*! SPLLERR - SPLL Clock Error
 *  0b0..SPLL Clock Monitor is disabled or has not detected an error
 *  0b1..SPLL Clock Monitor is enabled and detected an error
 */
#define SCG_SPLLCSR_SPLLERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLERR_SHIFT)) & SCG_SPLLCSR_SPLLERR_MASK)

#define SCG_SPLLCSR_SPLL_LOCK_IE_MASK            (0x40000000U)
#define SCG_SPLLCSR_SPLL_LOCK_IE_SHIFT           (30U)
/*! SPLL_LOCK_IE - SPLL LOCK Interrupt Enable
 *  0b0..SPLL_LOCK interrupt is not enabled
 *  0b1..SPLL_LOCK interrupt is enabled
 */
#define SCG_SPLLCSR_SPLL_LOCK_IE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLL_LOCK_IE_SHIFT)) & SCG_SPLLCSR_SPLL_LOCK_IE_MASK)
/*! @} */

/*! @name SPLLCTRL - SPLL Control */
/*! @{ */

#define SCG_SPLLCTRL_SELR_MASK                   (0xFU)
#define SCG_SPLLCTRL_SELR_SHIFT                  (0U)
/*! SELR - Bandwidth select R (resistor) value. */
#define SCG_SPLLCTRL_SELR(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SELR_SHIFT)) & SCG_SPLLCTRL_SELR_MASK)

#define SCG_SPLLCTRL_SELI_MASK                   (0x3F0U)
#define SCG_SPLLCTRL_SELI_SHIFT                  (4U)
/*! SELI - Bandwidth select I (interation) value. */
#define SCG_SPLLCTRL_SELI(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SELI_SHIFT)) & SCG_SPLLCTRL_SELI_MASK)

#define SCG_SPLLCTRL_SELP_MASK                   (0x7C00U)
#define SCG_SPLLCTRL_SELP_SHIFT                  (10U)
/*! SELP - Bandwidth select P (proportional) value. */
#define SCG_SPLLCTRL_SELP(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SELP_SHIFT)) & SCG_SPLLCTRL_SELP_MASK)

#define SCG_SPLLCTRL_BYPASSPOSTDIV2_MASK         (0x10000U)
#define SCG_SPLLCTRL_BYPASSPOSTDIV2_SHIFT        (16U)
/*! BYPASSPOSTDIV2 - Bypass of the divide-by-2 divider
 *  0b0..Use the divide-by-2 divider in the post-divider.
 *  0b1..Bypass of the divide-by-2 divider in the post-divider.
 */
#define SCG_SPLLCTRL_BYPASSPOSTDIV2(x)           (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_BYPASSPOSTDIV2_SHIFT)) & SCG_SPLLCTRL_BYPASSPOSTDIV2_MASK)

#define SCG_SPLLCTRL_LIMUPOFF_MASK               (0x20000U)
#define SCG_SPLLCTRL_LIMUPOFF_SHIFT              (17U)
/*! LIMUPOFF - Up Limiter.
 *  0b0..Application set to non Spectrum and Fractional applications.
 *  0b1..Application set to Spectrum and Fractional applications.
 */
#define SCG_SPLLCTRL_LIMUPOFF(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_LIMUPOFF_SHIFT)) & SCG_SPLLCTRL_LIMUPOFF_MASK)

#define SCG_SPLLCTRL_BANDDIRECT_MASK             (0x40000U)
#define SCG_SPLLCTRL_BANDDIRECT_SHIFT            (18U)
/*! BANDDIRECT - Control of the bandwidth of the PLL.
 *  0b0..The bandwidth is changed synchronously with the feedback-divider
 *  0b1..Modifies the bandwidth of the PLL directly
 */
#define SCG_SPLLCTRL_BANDDIRECT(x)               (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_BANDDIRECT_SHIFT)) & SCG_SPLLCTRL_BANDDIRECT_MASK)

#define SCG_SPLLCTRL_BYPASSPREDIV_MASK           (0x80000U)
#define SCG_SPLLCTRL_BYPASSPREDIV_SHIFT          (19U)
/*! BYPASSPREDIV - Bypass of the pre-divider.
 *  0b0..Use the pre-divider
 *  0b1..Bypass of the pre-divider
 */
#define SCG_SPLLCTRL_BYPASSPREDIV(x)             (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_BYPASSPREDIV_SHIFT)) & SCG_SPLLCTRL_BYPASSPREDIV_MASK)

#define SCG_SPLLCTRL_BYPASSPOSTDIV_MASK          (0x100000U)
#define SCG_SPLLCTRL_BYPASSPOSTDIV_SHIFT         (20U)
/*! BYPASSPOSTDIV - Bypass of the post-divider.
 *  0b0..Use the post-divider
 *  0b1..Bypass of the post-divider
 */
#define SCG_SPLLCTRL_BYPASSPOSTDIV(x)            (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_BYPASSPOSTDIV_SHIFT)) & SCG_SPLLCTRL_BYPASSPOSTDIV_MASK)

#define SCG_SPLLCTRL_FRM_MASK                    (0x400000U)
#define SCG_SPLLCTRL_FRM_SHIFT                   (22U)
/*! FRM - Free Running Mode Enable
 *  0b0..Free running mode disabled
 *  0b1..Free running mode enabled
 */
#define SCG_SPLLCTRL_FRM(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_FRM_SHIFT)) & SCG_SPLLCTRL_FRM_MASK)

#define SCG_SPLLCTRL_SOURCE_MASK                 (0x6000000U)
#define SCG_SPLLCTRL_SOURCE_SHIFT                (25U)
/*! SOURCE - Clock Source
 *  0b00..SOSC
 *  0b01..FIRC 48 MHz clock. FIRC_SCLK_PERIPH_EN needs to be set to use FIRC 48 MHz clock.
 *  0b10..
 *  0b11..SIRC 12 MHz clock
 */
#define SCG_SPLLCTRL_SOURCE(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SOURCE_SHIFT)) & SCG_SPLLCTRL_SOURCE_MASK)
/*! @} */

/*! @name SPLLSTAT - SPLL Status */
/*! @{ */

#define SCG_SPLLSTAT_NDIVACK_MASK                (0x2U)
#define SCG_SPLLSTAT_NDIVACK_SHIFT               (1U)
/*! NDIVACK - Pre-divider (N) ratio change acknowledge
 *  0b0..The Pre-divider (N) ratio change is not accepted by the analog PLL.
 *  0b1..The Pre-divider (N) ratio change is accepted by the analog PLL.
 */
#define SCG_SPLLSTAT_NDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSTAT_NDIVACK_SHIFT)) & SCG_SPLLSTAT_NDIVACK_MASK)

#define SCG_SPLLSTAT_MDIVACK_MASK                (0x4U)
#define SCG_SPLLSTAT_MDIVACK_SHIFT               (2U)
/*! MDIVACK - Feedback (M) divider ratio change acknowledge
 *  0b0..The Feedback (M) ratio change is not accepted by the analog PLL.
 *  0b1..The Feedback (M) ratio change is accepted by the analog PLL.
 */
#define SCG_SPLLSTAT_MDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSTAT_MDIVACK_SHIFT)) & SCG_SPLLSTAT_MDIVACK_MASK)

#define SCG_SPLLSTAT_PDIVACK_MASK                (0x8U)
#define SCG_SPLLSTAT_PDIVACK_SHIFT               (3U)
/*! PDIVACK - Post-divider (P) ratio change acknowledge
 *  0b0..The Post-divider (P) ratio change is not accepted by the analog PLL
 *  0b1..The Post-divider (P) ratio change is accepted by the analog PLL
 */
#define SCG_SPLLSTAT_PDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSTAT_PDIVACK_SHIFT)) & SCG_SPLLSTAT_PDIVACK_MASK)

#define SCG_SPLLSTAT_FRMDET_MASK                 (0x10U)
#define SCG_SPLLSTAT_FRMDET_SHIFT                (4U)
/*! FRMDET - Free running detector (active high)
 *  0b0..Free running is not detected
 *  0b1..Free running is detected
 */
#define SCG_SPLLSTAT_FRMDET(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSTAT_FRMDET_SHIFT)) & SCG_SPLLSTAT_FRMDET_MASK)
/*! @} */

/*! @name SPLLNDIV - SPLL N Divider */
/*! @{ */

#define SCG_SPLLNDIV_NDIV_MASK                   (0xFFU)
#define SCG_SPLLNDIV_NDIV_SHIFT                  (0U)
/*! NDIV - Pre-divider divider ratio (N-divider). */
#define SCG_SPLLNDIV_NDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLNDIV_NDIV_SHIFT)) & SCG_SPLLNDIV_NDIV_MASK)

#define SCG_SPLLNDIV_NREQ_MASK                   (0x80000000U)
#define SCG_SPLLNDIV_NREQ_SHIFT                  (31U)
/*! NREQ - Pre-divider ratio change request.
 *  0b0..Pre-divider ratio change is not requested
 *  0b1..Pre-divider ratio change is requested
 */
#define SCG_SPLLNDIV_NREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLNDIV_NREQ_SHIFT)) & SCG_SPLLNDIV_NREQ_MASK)
/*! @} */

/*! @name SPLLMDIV - SPLL M Divider */
/*! @{ */

#define SCG_SPLLMDIV_MDIV_MASK                   (0xFFFFU)
#define SCG_SPLLMDIV_MDIV_SHIFT                  (0U)
/*! MDIV - Feedback divider ratio (M-divider). */
#define SCG_SPLLMDIV_MDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLMDIV_MDIV_SHIFT)) & SCG_SPLLMDIV_MDIV_MASK)

#define SCG_SPLLMDIV_MREQ_MASK                   (0x80000000U)
#define SCG_SPLLMDIV_MREQ_SHIFT                  (31U)
/*! MREQ - Feedback ratio change request.
 *  0b0..Feedback ratio change is not requested
 *  0b1..Feedback ratio change is requested
 */
#define SCG_SPLLMDIV_MREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLMDIV_MREQ_SHIFT)) & SCG_SPLLMDIV_MREQ_MASK)
/*! @} */

/*! @name SPLLPDIV - SPLL P Divider */
/*! @{ */

#define SCG_SPLLPDIV_PDIV_MASK                   (0x1FU)
#define SCG_SPLLPDIV_PDIV_SHIFT                  (0U)
/*! PDIV - Post-divider divider ratio (P-divider) */
#define SCG_SPLLPDIV_PDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPDIV_PDIV_SHIFT)) & SCG_SPLLPDIV_PDIV_MASK)

#define SCG_SPLLPDIV_PREQ_MASK                   (0x80000000U)
#define SCG_SPLLPDIV_PREQ_SHIFT                  (31U)
/*! PREQ - Post-divider ratio change request
 *  0b0..Post-divider ratio change is not requested
 *  0b1..Post-divider ratio change is requested
 */
#define SCG_SPLLPDIV_PREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPDIV_PREQ_SHIFT)) & SCG_SPLLPDIV_PREQ_MASK)
/*! @} */

/*! @name SPLLLOCK_CNFG - SPLL LOCK Configuration */
/*! @{ */

#define SCG_SPLLLOCK_CNFG_LOCK_TIME_MASK         (0x1FFFFU)
#define SCG_SPLLLOCK_CNFG_LOCK_TIME_SHIFT        (0U)
/*! LOCK_TIME - Configures the number of reference clocks to count before SPLL is considered locked. */
#define SCG_SPLLLOCK_CNFG_LOCK_TIME(x)           (((uint32_t)(((uint32_t)(x)) << SCG_SPLLLOCK_CNFG_LOCK_TIME_SHIFT)) & SCG_SPLLLOCK_CNFG_LOCK_TIME_MASK)
/*! @} */

/*! @name SPLLSSCGSTAT - SPLL SSCG Status */
/*! @{ */

#define SCG_SPLLSSCGSTAT_SS_MDIV_ACK_MASK        (0x1U)
#define SCG_SPLLSSCGSTAT_SS_MDIV_ACK_SHIFT       (0U)
/*! SS_MDIV_ACK - SS_MDIV change acknowledge
 *  0b0..The SS_MDIV, MF, MR, MC ratio change is not accepted by the analog PLL
 *  0b1..The SS_MDIV, MF, MR, MC ratio change is accepted by the analog PLL
 */
#define SCG_SPLLSSCGSTAT_SS_MDIV_ACK(x)          (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCGSTAT_SS_MDIV_ACK_SHIFT)) & SCG_SPLLSSCGSTAT_SS_MDIV_ACK_MASK)
/*! @} */

/*! @name SPLLSSCG0 - SPLL Spread Spectrum Control 0 */
/*! @{ */

#define SCG_SPLLSSCG0_SS_MDIV_LSB_MASK           (0xFFFFFFFFU)
#define SCG_SPLLSSCG0_SS_MDIV_LSB_SHIFT          (0U)
/*! SS_MDIV_LSB - SS_MDIV[31:0] */
#define SCG_SPLLSSCG0_SS_MDIV_LSB(x)             (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG0_SS_MDIV_LSB_SHIFT)) & SCG_SPLLSSCG0_SS_MDIV_LSB_MASK)
/*! @} */

/*! @name SPLLSSCG1 - SPLL Spread Spectrum Control 1 */
/*! @{ */

#define SCG_SPLLSSCG1_SS_MDIV_MSB_MASK           (0x1U)
#define SCG_SPLLSSCG1_SS_MDIV_MSB_SHIFT          (0U)
/*! SS_MDIV_MSB - SS_MDIV[32] */
#define SCG_SPLLSSCG1_SS_MDIV_MSB(x)             (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_SS_MDIV_MSB_SHIFT)) & SCG_SPLLSSCG1_SS_MDIV_MSB_MASK)

#define SCG_SPLLSSCG1_SS_MDIV_REQ_MASK           (0x2U)
#define SCG_SPLLSSCG1_SS_MDIV_REQ_SHIFT          (1U)
/*! SS_MDIV_REQ - SS_MDIV[32:0] change request.
 *  0b0..SS_MDIV change is not requested
 *  0b1..SS_MDIV change is requested
 */
#define SCG_SPLLSSCG1_SS_MDIV_REQ(x)             (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_SS_MDIV_REQ_SHIFT)) & SCG_SPLLSSCG1_SS_MDIV_REQ_MASK)

#define SCG_SPLLSSCG1_MF_MASK                    (0x1CU)
#define SCG_SPLLSSCG1_MF_SHIFT                   (2U)
/*! MF - Modulation Frequency Control */
#define SCG_SPLLSSCG1_MF(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_MF_SHIFT)) & SCG_SPLLSSCG1_MF_MASK)

#define SCG_SPLLSSCG1_MR_MASK                    (0xE0U)
#define SCG_SPLLSSCG1_MR_SHIFT                   (5U)
/*! MR - Modulation Depth Control */
#define SCG_SPLLSSCG1_MR(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_MR_SHIFT)) & SCG_SPLLSSCG1_MR_MASK)

#define SCG_SPLLSSCG1_MC_MASK                    (0x300U)
#define SCG_SPLLSSCG1_MC_SHIFT                   (8U)
/*! MC - Modulation Waveform Control */
#define SCG_SPLLSSCG1_MC(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_MC_SHIFT)) & SCG_SPLLSSCG1_MC_MASK)

#define SCG_SPLLSSCG1_DITHER_MASK                (0x400U)
#define SCG_SPLLSSCG1_DITHER_SHIFT               (10U)
/*! DITHER - Dither Enable
 *  0b0..Dither is not enabled
 *  0b1..Dither is enabled
 */
#define SCG_SPLLSSCG1_DITHER(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_DITHER_SHIFT)) & SCG_SPLLSSCG1_DITHER_MASK)

#define SCG_SPLLSSCG1_SEL_SS_MDIV_MASK           (0x800U)
#define SCG_SPLLSSCG1_SEL_SS_MDIV_SHIFT          (11U)
/*! SEL_SS_MDIV - SS_MDIV select.
 *  0b0..Feedback divider ratio is MDIV[15:0]
 *  0b1..Feedback divider ratio is SS_MDIV[32:0]
 */
#define SCG_SPLLSSCG1_SEL_SS_MDIV(x)             (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_SEL_SS_MDIV_SHIFT)) & SCG_SPLLSSCG1_SEL_SS_MDIV_MASK)

#define SCG_SPLLSSCG1_SS_PD_MASK                 (0x80000000U)
#define SCG_SPLLSSCG1_SS_PD_SHIFT                (31U)
/*! SS_PD - SSCG Power Down
 *  0b0..SSCG is powered on
 *  0b1..SSCG is powered off
 */
#define SCG_SPLLSSCG1_SS_PD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG1_SS_PD_SHIFT)) & SCG_SPLLSSCG1_SS_PD_MASK)
/*! @} */

/*! @name LDOCSR - LDO Control and Status */
/*! @{ */

#define SCG_LDOCSR_LDOEN_MASK                    (0x1U)
#define SCG_LDOCSR_LDOEN_SHIFT                   (0U)
/*! LDOEN - LDO Enable
 *  0b0..LDO is disabled
 *  0b1..LDO is enabled
 */
#define SCG_LDOCSR_LDOEN(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_LDOEN_SHIFT)) & SCG_LDOCSR_LDOEN_MASK)

#define SCG_LDOCSR_VOUT_SEL_MASK                 (0xEU)
#define SCG_LDOCSR_VOUT_SEL_SHIFT                (1U)
/*! VOUT_SEL - LDO output voltage select
 *  0b000..VOUT = 1V
 *  0b001..VOUT = 1V
 *  0b010..VOUT = 1V
 *  0b011..VOUT = 1.05V
 *  0b100..VOUT = 1.1V
 *  0b101..VOUT = 1.15V
 *  0b110..VOUT = 1.2V
 *  0b111..VOUT = 1.25V
 */
#define SCG_LDOCSR_VOUT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_VOUT_SEL_SHIFT)) & SCG_LDOCSR_VOUT_SEL_MASK)

#define SCG_LDOCSR_LDOBYPASS_MASK                (0x10U)
#define SCG_LDOCSR_LDOBYPASS_SHIFT               (4U)
/*! LDOBYPASS - LDO Bypass
 *  0b0..LDO is not bypassed
 *  0b1..LDO is bypassed
 */
#define SCG_LDOCSR_LDOBYPASS(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_LDOBYPASS_SHIFT)) & SCG_LDOCSR_LDOBYPASS_MASK)

#define SCG_LDOCSR_VOUT_OK_MASK                  (0x80000000U)
#define SCG_LDOCSR_VOUT_OK_SHIFT                 (31U)
/*! VOUT_OK - LDO VOUT OK Inform.
 *  0b0..LDO output VOUT is not OK
 *  0b1..LDO output VOUT is OK
 */
#define SCG_LDOCSR_VOUT_OK(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_VOUT_OK_SHIFT)) & SCG_LDOCSR_VOUT_OK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SCG_Register_Masks */


/*!
 * @}
 */ /* end of group SCG_Peripheral_Access_Layer */


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


#endif  /* PERI_SCG_H_ */

