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
**         CMSIS Peripheral Access Layer for CMC
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
 * @file PERI_CMC.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for CMC
 *
 * CMSIS Peripheral Access Layer for CMC
 */

#if !defined(PERI_CMC_H_)
#define PERI_CMC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_Peripheral_Access_Layer CMC Peripheral Access Layer
 * @{
 */

/** CMC - Size of Registers Arrays */
#define CMC_PMCTRL_COUNT                          3u
#define CMC_MR_COUNT                              1u
#define CMC_FM_COUNT                              1u
#define CMC_SRAMDIS_COUNT                         1u
#define CMC_SRAMRET_COUNT                         1u
#define CMC_BSR_COUNT                             4u

/** CMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CKCTRL;                            /**< Clock Control, offset: 0x10 */
  __IO uint32_t CKSTAT;                            /**< Clock Status, offset: 0x14 */
  __IO uint32_t PMPROT;                            /**< Power Mode Protection, offset: 0x18 */
  __IO uint32_t GPMCTRL;                           /**< Global Power Mode Control, offset: 0x1C */
  __IO uint32_t PMCTRL[CMC_PMCTRL_COUNT];          /**< Power Mode Control, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[84];
  __I  uint32_t SRS;                               /**< System Reset Status, offset: 0x80 */
  __IO uint32_t RPC;                               /**< Reset Pin Control, offset: 0x84 */
  __IO uint32_t SSRS;                              /**< Sticky System Reset Status, offset: 0x88 */
  __IO uint32_t SRIE;                              /**< System Reset Interrupt Enable, offset: 0x8C */
  __IO uint32_t SRIF;                              /**< System Reset Interrupt Flag, offset: 0x90 */
       uint8_t RESERVED_2[8];
  __I  uint32_t RSTCNT;                            /**< Reset Count Register, offset: 0x9C */
  __IO uint32_t MR[CMC_MR_COUNT];                  /**< Mode, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[12];
  __IO uint32_t FM[CMC_FM_COUNT];                  /**< Force Mode, array offset: 0xB0, array step: 0x4 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SRAMDIS[CMC_SRAMDIS_COUNT];        /**< SRAM Disable, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_5[12];
  __IO uint32_t SRAMRET[CMC_SRAMRET_COUNT];        /**< SRAM Retention, array offset: 0xD0, array step: 0x4 */
       uint8_t RESERVED_6[12];
  __IO uint32_t FLASHCR;                           /**< Flash Control, offset: 0xE0 */
       uint8_t RESERVED_7[12];
  __I  uint32_t DIER;                              /**< Device Initialization Error Register, offset: 0xF0 */
       uint8_t RESERVED_8[8];
  __IO uint32_t BLR;                               /**< BootROM Lock Register, offset: 0xFC */
  __IO uint32_t BSR[CMC_BSR_COUNT];                /**< BootROM Scratch Register, array offset: 0x100, array step: 0x4 */
  __IO uint32_t CORECTL;                           /**< Core Control, offset: 0x110 */
       uint8_t RESERVED_9[12];
  __IO uint32_t DBGCTL;                            /**< Debug Control, offset: 0x120 */
} CMC_Type;

/* ----------------------------------------------------------------------------
   -- CMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_Register_Masks CMC Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define CMC_VERID_FEATURE_MASK                   (0xFFFFU)
#define CMC_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number */
#define CMC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_VERID_FEATURE_SHIFT)) & CMC_VERID_FEATURE_MASK)

#define CMC_VERID_MINOR_MASK                     (0xFF0000U)
#define CMC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define CMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_VERID_MINOR_SHIFT)) & CMC_VERID_MINOR_MASK)

#define CMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define CMC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define CMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_VERID_MAJOR_SHIFT)) & CMC_VERID_MAJOR_MASK)
/*! @} */

/*! @name CKCTRL - Clock Control */
/*! @{ */

#define CMC_CKCTRL_CKMODE_MASK                   (0xFU)
#define CMC_CKCTRL_CKMODE_SHIFT                  (0U)
/*! CKMODE - Clocking Mode
 *  0b0000..Core clock is on
 *  0b0001..Core clock is off
 *  0b0011..Core and platform clocks are off
 *  0b0111..Core, platform, and peripheral clocks are off, but no change in Low-Power mode
 *  0b1111..Core, platform, and peripheral clocks are off, and core enters Low-Power mode
 */
#define CMC_CKCTRL_CKMODE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_CKCTRL_CKMODE_SHIFT)) & CMC_CKCTRL_CKMODE_MASK)

#define CMC_CKCTRL_LOCK_MASK                     (0x80000000U)
#define CMC_CKCTRL_LOCK_SHIFT                    (31U)
/*! LOCK - Lock
 *  0b0..Allowed
 *  0b1..Blocked
 */
#define CMC_CKCTRL_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_CKCTRL_LOCK_SHIFT)) & CMC_CKCTRL_LOCK_MASK)
/*! @} */

/*! @name CKSTAT - Clock Status */
/*! @{ */

#define CMC_CKSTAT_CKMODE_MASK                   (0xFU)
#define CMC_CKSTAT_CKMODE_SHIFT                  (0U)
/*! CKMODE - Low Power Status
 *  0b0000..Core clock is on
 *  0b0001..Core clock is off
 *  0b0011..Core and platform clocks are off
 *  0b0111..Core, platform, and peripheral clocks are off, but no change in Low-Power mode
 *  0b1111..Core, platform, and peripheral clocks are off, and core enters Low-Power mode
 */
#define CMC_CKSTAT_CKMODE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_CKSTAT_CKMODE_SHIFT)) & CMC_CKSTAT_CKMODE_MASK)

#define CMC_CKSTAT_WAKEUP_MASK                   (0x3F00U)
#define CMC_CKSTAT_WAKEUP_SHIFT                  (8U)
/*! WAKEUP - Wake-up Source */
#define CMC_CKSTAT_WAKEUP(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_CKSTAT_WAKEUP_SHIFT)) & CMC_CKSTAT_WAKEUP_MASK)

#define CMC_CKSTAT_VALID_MASK                    (0x80000000U)
#define CMC_CKSTAT_VALID_SHIFT                   (31U)
/*! VALID - Clock Status Valid
 *  0b0..Core clock not gated
 *  0b1..Core clock was gated due to Low-Power mode entry
 */
#define CMC_CKSTAT_VALID(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_CKSTAT_VALID_SHIFT)) & CMC_CKSTAT_VALID_MASK)
/*! @} */

/*! @name PMPROT - Power Mode Protection */
/*! @{ */

#define CMC_PMPROT_LPMODE_MASK                   (0xFU)
#define CMC_PMPROT_LPMODE_SHIFT                  (0U)
/*! LPMODE - Low-Power Mode
 *  0b0000..Not allowed
 *  0b0001..Allowed
 *  0b0010..Allowed
 *  0b0011..Allowed
 *  0b0100..Allowed
 *  0b0101..Allowed
 *  0b0110..Allowed
 *  0b0111..Allowed
 *  0b1000..Allowed
 *  0b1001..Allowed
 *  0b1010..Allowed
 *  0b1011..Allowed
 *  0b1100..Allowed
 *  0b1101..Allowed
 *  0b1110..Allowed
 *  0b1111..Allowed
 */
#define CMC_PMPROT_LPMODE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_PMPROT_LPMODE_SHIFT)) & CMC_PMPROT_LPMODE_MASK)

#define CMC_PMPROT_LOCK_MASK                     (0x80000000U)
#define CMC_PMPROT_LOCK_SHIFT                    (31U)
/*! LOCK - Lock Register
 *  0b0..Allowed
 *  0b1..Blocked
 */
#define CMC_PMPROT_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_PMPROT_LOCK_SHIFT)) & CMC_PMPROT_LOCK_MASK)
/*! @} */

/*! @name GPMCTRL - Global Power Mode Control */
/*! @{ */

#define CMC_GPMCTRL_LPMODE_MASK                  (0xFU)
#define CMC_GPMCTRL_LPMODE_SHIFT                 (0U)
/*! LPMODE - Low-Power Mode */
#define CMC_GPMCTRL_LPMODE(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_GPMCTRL_LPMODE_SHIFT)) & CMC_GPMCTRL_LPMODE_MASK)
/*! @} */

/*! @name PMCTRL - Power Mode Control */
/*! @{ */

#define CMC_PMCTRL_LPMODE_MASK                   (0xFU)
#define CMC_PMCTRL_LPMODE_SHIFT                  (0U)
/*! LPMODE - Low-Power Mode
 *  0b0000..Active
 *  0b0001..Sleep
 *  0b0011..Deep Sleep
 *  0b0111..Power Down
 *  0b1111..Deep-Power Down
 */
#define CMC_PMCTRL_LPMODE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_PMCTRL_LPMODE_SHIFT)) & CMC_PMCTRL_LPMODE_MASK)
/*! @} */

/*! @name SRS - System Reset Status */
/*! @{ */

#define CMC_SRS_WAKEUP_MASK                      (0x1U)
#define CMC_SRS_WAKEUP_SHIFT                     (0U)
/*! WAKEUP - Wake-up Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_WAKEUP(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WAKEUP_SHIFT)) & CMC_SRS_WAKEUP_MASK)

#define CMC_SRS_POR_MASK                         (0x2U)
#define CMC_SRS_POR_SHIFT                        (1U)
/*! POR - Power-on Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_POR(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_POR_SHIFT)) & CMC_SRS_POR_MASK)

#define CMC_SRS_LVD_MASK                         (0x4U)
#define CMC_SRS_LVD_SHIFT                        (2U)
/*! LVD - Low Voltage Detect Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_LVD(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_LVD_SHIFT)) & CMC_SRS_LVD_MASK)

#define CMC_SRS_HVD_MASK                         (0x8U)
#define CMC_SRS_HVD_SHIFT                        (3U)
/*! HVD - High Voltage Detect Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_HVD(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_HVD_SHIFT)) & CMC_SRS_HVD_MASK)

#define CMC_SRS_WARM_MASK                        (0x10U)
#define CMC_SRS_WARM_SHIFT                       (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_WARM(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WARM_SHIFT)) & CMC_SRS_WARM_MASK)

#define CMC_SRS_FATAL_MASK                       (0x20U)
#define CMC_SRS_FATAL_SHIFT                      (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated
 *  0b1..Reset was generated
 */
#define CMC_SRS_FATAL(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_FATAL_SHIFT)) & CMC_SRS_FATAL_MASK)

#define CMC_SRS_PIN_MASK                         (0x100U)
#define CMC_SRS_PIN_SHIFT                        (8U)
/*! PIN - Pin Reset
 *  0b0..Reset was not generated
 *  0b1..Reset was generated
 */
#define CMC_SRS_PIN(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_PIN_SHIFT)) & CMC_SRS_PIN_MASK)

#define CMC_SRS_DAP_MASK                         (0x200U)
#define CMC_SRS_DAP_SHIFT                        (9U)
/*! DAP - Debug Access Port Reset
 *  0b0..Reset was not generated
 *  0b1..Reset was generated
 */
#define CMC_SRS_DAP(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_DAP_SHIFT)) & CMC_SRS_DAP_MASK)

#define CMC_SRS_RSTACK_MASK                      (0x400U)
#define CMC_SRS_RSTACK_SHIFT                     (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_RSTACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_RSTACK_SHIFT)) & CMC_SRS_RSTACK_MASK)

#define CMC_SRS_LPACK_MASK                       (0x800U)
#define CMC_SRS_LPACK_SHIFT                      (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_LPACK(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_LPACK_SHIFT)) & CMC_SRS_LPACK_MASK)

#define CMC_SRS_SCG_MASK                         (0x1000U)
#define CMC_SRS_SCG_SHIFT                        (12U)
/*! SCG - System Clock Generation Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SRS_SCG(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_SCG_SHIFT)) & CMC_SRS_SCG_MASK)

#define CMC_SRS_WDOG0_MASK                       (0x2000U)
#define CMC_SRS_WDOG0_SHIFT                      (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SRS_WDOG0(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WDOG0_SHIFT)) & CMC_SRS_WDOG0_MASK)

#define CMC_SRS_SW_MASK                          (0x4000U)
#define CMC_SRS_SW_SHIFT                         (14U)
/*! SW - Software Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_SW(x)                            (((uint32_t)(((uint32_t)(x)) << CMC_SRS_SW_SHIFT)) & CMC_SRS_SW_MASK)

#define CMC_SRS_LOCKUP_MASK                      (0x8000U)
#define CMC_SRS_LOCKUP_SHIFT                     (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_LOCKUP(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_LOCKUP_SHIFT)) & CMC_SRS_LOCKUP_MASK)

#define CMC_SRS_WDOG1_MASK                       (0x2000000U)
#define CMC_SRS_WDOG1_SHIFT                      (25U)
/*! WDOG1 - Watchdog 1 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SRS_WDOG1(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WDOG1_SHIFT)) & CMC_SRS_WDOG1_MASK)

#define CMC_SRS_CDOG0_MASK                       (0x4000000U)
#define CMC_SRS_CDOG0_SHIFT                      (26U)
/*! CDOG0 - Code Watchdog 0 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SRS_CDOG0(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_CDOG0_SHIFT)) & CMC_SRS_CDOG0_MASK)

#define CMC_SRS_CDOG1_MASK                       (0x8000000U)
#define CMC_SRS_CDOG1_SHIFT                      (27U)
/*! CDOG1 - Code Watchdog 1 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SRS_CDOG1(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_CDOG1_SHIFT)) & CMC_SRS_CDOG1_MASK)

#define CMC_SRS_JTAG_MASK                        (0x10000000U)
#define CMC_SRS_JTAG_SHIFT                       (28U)
/*! JTAG - JTAG System Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_JTAG(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_JTAG_SHIFT)) & CMC_SRS_JTAG_MASK)

#define CMC_SRS_SECVIO_MASK                      (0x40000000U)
#define CMC_SRS_SECVIO_SHIFT                     (30U)
/*! SECVIO - Security Violation Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_SECVIO(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_SECVIO_SHIFT)) & CMC_SRS_SECVIO_MASK)

#define CMC_SRS_TAMPER_MASK                      (0x80000000U)
#define CMC_SRS_TAMPER_SHIFT                     (31U)
/*! TAMPER - Tamper Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_TAMPER(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_TAMPER_SHIFT)) & CMC_SRS_TAMPER_MASK)
/*! @} */

/*! @name RPC - Reset Pin Control */
/*! @{ */

#define CMC_RPC_FILTCFG_MASK                     (0x1FU)
#define CMC_RPC_FILTCFG_SHIFT                    (0U)
/*! FILTCFG - Reset Filter Configuration */
#define CMC_RPC_FILTCFG(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_RPC_FILTCFG_SHIFT)) & CMC_RPC_FILTCFG_MASK)

#define CMC_RPC_FILTEN_MASK                      (0x100U)
#define CMC_RPC_FILTEN_SHIFT                     (8U)
/*! FILTEN - Filter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define CMC_RPC_FILTEN(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_RPC_FILTEN_SHIFT)) & CMC_RPC_FILTEN_MASK)

#define CMC_RPC_LPFEN_MASK                       (0x200U)
#define CMC_RPC_LPFEN_SHIFT                      (9U)
/*! LPFEN - Low-Power Filter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define CMC_RPC_LPFEN(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_RPC_LPFEN_SHIFT)) & CMC_RPC_LPFEN_MASK)
/*! @} */

/*! @name SSRS - Sticky System Reset Status */
/*! @{ */

#define CMC_SSRS_WAKEUP_MASK                     (0x1U)
#define CMC_SSRS_WAKEUP_SHIFT                    (0U)
/*! WAKEUP - Wake-up Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_WAKEUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WAKEUP_SHIFT)) & CMC_SSRS_WAKEUP_MASK)

#define CMC_SSRS_POR_MASK                        (0x2U)
#define CMC_SSRS_POR_SHIFT                       (1U)
/*! POR - Power-on Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_POR(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_POR_SHIFT)) & CMC_SSRS_POR_MASK)

#define CMC_SSRS_LVD_MASK                        (0x4U)
#define CMC_SSRS_LVD_SHIFT                       (2U)
/*! LVD - Low Voltage Detect Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_LVD(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_LVD_SHIFT)) & CMC_SSRS_LVD_MASK)

#define CMC_SSRS_HVD_MASK                        (0x8U)
#define CMC_SSRS_HVD_SHIFT                       (3U)
/*! HVD - High Voltage Detect Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_HVD(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_HVD_SHIFT)) & CMC_SSRS_HVD_MASK)

#define CMC_SSRS_WARM_MASK                       (0x10U)
#define CMC_SSRS_WARM_SHIFT                      (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_WARM(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WARM_SHIFT)) & CMC_SSRS_WARM_MASK)

#define CMC_SSRS_FATAL_MASK                      (0x20U)
#define CMC_SSRS_FATAL_SHIFT                     (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated
 *  0b1..Reset was generated
 */
#define CMC_SSRS_FATAL(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_FATAL_SHIFT)) & CMC_SSRS_FATAL_MASK)

#define CMC_SSRS_PIN_MASK                        (0x100U)
#define CMC_SSRS_PIN_SHIFT                       (8U)
/*! PIN - Pin Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_PIN_SHIFT)) & CMC_SSRS_PIN_MASK)

#define CMC_SSRS_DAP_MASK                        (0x200U)
#define CMC_SSRS_DAP_SHIFT                       (9U)
/*! DAP - DAP Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_DAP(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_DAP_SHIFT)) & CMC_SSRS_DAP_MASK)

#define CMC_SSRS_RSTACK_MASK                     (0x400U)
#define CMC_SSRS_RSTACK_SHIFT                    (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_RSTACK(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_RSTACK_SHIFT)) & CMC_SSRS_RSTACK_MASK)

#define CMC_SSRS_LPACK_MASK                      (0x800U)
#define CMC_SSRS_LPACK_SHIFT                     (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_LPACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_LPACK_SHIFT)) & CMC_SSRS_LPACK_MASK)

#define CMC_SSRS_SCG_MASK                        (0x1000U)
#define CMC_SSRS_SCG_SHIFT                       (12U)
/*! SCG - System Clock Generation Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SSRS_SCG(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_SCG_SHIFT)) & CMC_SSRS_SCG_MASK)

#define CMC_SSRS_WDOG0_MASK                      (0x2000U)
#define CMC_SSRS_WDOG0_SHIFT                     (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SSRS_WDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WDOG0_SHIFT)) & CMC_SSRS_WDOG0_MASK)

#define CMC_SSRS_SW_MASK                         (0x4000U)
#define CMC_SSRS_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_SW(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_SW_SHIFT)) & CMC_SSRS_SW_MASK)

#define CMC_SSRS_LOCKUP_MASK                     (0x8000U)
#define CMC_SSRS_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_LOCKUP_SHIFT)) & CMC_SSRS_LOCKUP_MASK)

#define CMC_SSRS_WDOG1_MASK                      (0x2000000U)
#define CMC_SSRS_WDOG1_SHIFT                     (25U)
/*! WDOG1 - Watchdog 1 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SSRS_WDOG1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WDOG1_SHIFT)) & CMC_SSRS_WDOG1_MASK)

#define CMC_SSRS_CDOG0_MASK                      (0x4000000U)
#define CMC_SSRS_CDOG0_SHIFT                     (26U)
/*! CDOG0 - Code Watchdog 0 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SSRS_CDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_CDOG0_SHIFT)) & CMC_SSRS_CDOG0_MASK)

#define CMC_SSRS_CDOG1_MASK                      (0x8000000U)
#define CMC_SSRS_CDOG1_SHIFT                     (27U)
/*! CDOG1 - Code Watchdog 1 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SSRS_CDOG1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_CDOG1_SHIFT)) & CMC_SSRS_CDOG1_MASK)

#define CMC_SSRS_JTAG_MASK                       (0x10000000U)
#define CMC_SSRS_JTAG_SHIFT                      (28U)
/*! JTAG - JTAG System Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_JTAG(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_JTAG_SHIFT)) & CMC_SSRS_JTAG_MASK)

#define CMC_SSRS_SECVIO_MASK                     (0x40000000U)
#define CMC_SSRS_SECVIO_SHIFT                    (30U)
/*! SECVIO - Security Violation Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_SECVIO(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_SECVIO_SHIFT)) & CMC_SSRS_SECVIO_MASK)

#define CMC_SSRS_TAMPER_MASK                     (0x80000000U)
#define CMC_SSRS_TAMPER_SHIFT                    (31U)
/*! TAMPER - Tamper Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_TAMPER(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_TAMPER_SHIFT)) & CMC_SSRS_TAMPER_MASK)
/*! @} */

/*! @name SRIE - System Reset Interrupt Enable */
/*! @{ */

#define CMC_SRIE_PIN_MASK                        (0x100U)
#define CMC_SRIE_PIN_SHIFT                       (8U)
/*! PIN - Pin Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_PIN_SHIFT)) & CMC_SRIE_PIN_MASK)

#define CMC_SRIE_DAP_MASK                        (0x200U)
#define CMC_SRIE_DAP_SHIFT                       (9U)
/*! DAP - DAP Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_DAP(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_DAP_SHIFT)) & CMC_SRIE_DAP_MASK)

#define CMC_SRIE_LPACK_MASK                      (0x800U)
#define CMC_SRIE_LPACK_SHIFT                     (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_LPACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_LPACK_SHIFT)) & CMC_SRIE_LPACK_MASK)

#define CMC_SRIE_WDOG0_MASK                      (0x2000U)
#define CMC_SRIE_WDOG0_SHIFT                     (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_WDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WDOG0_SHIFT)) & CMC_SRIE_WDOG0_MASK)

#define CMC_SRIE_SW_MASK                         (0x4000U)
#define CMC_SRIE_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_SW(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_SW_SHIFT)) & CMC_SRIE_SW_MASK)

#define CMC_SRIE_LOCKUP_MASK                     (0x8000U)
#define CMC_SRIE_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_LOCKUP_SHIFT)) & CMC_SRIE_LOCKUP_MASK)

#define CMC_SRIE_WDOG1_MASK                      (0x2000000U)
#define CMC_SRIE_WDOG1_SHIFT                     (25U)
/*! WDOG1 - Watchdog 1 Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_WDOG1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WDOG1_SHIFT)) & CMC_SRIE_WDOG1_MASK)

#define CMC_SRIE_CDOG0_MASK                      (0x4000000U)
#define CMC_SRIE_CDOG0_SHIFT                     (26U)
/*! CDOG0 - Code Watchdog 0 Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_CDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_CDOG0_SHIFT)) & CMC_SRIE_CDOG0_MASK)

#define CMC_SRIE_CDOG1_MASK                      (0x8000000U)
#define CMC_SRIE_CDOG1_SHIFT                     (27U)
/*! CDOG1 - Code Watchdog 1 Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_CDOG1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_CDOG1_SHIFT)) & CMC_SRIE_CDOG1_MASK)
/*! @} */

/*! @name SRIF - System Reset Interrupt Flag */
/*! @{ */

#define CMC_SRIF_PIN_MASK                        (0x100U)
#define CMC_SRIF_PIN_SHIFT                       (8U)
/*! PIN - Pin Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_PIN_SHIFT)) & CMC_SRIF_PIN_MASK)

#define CMC_SRIF_DAP_MASK                        (0x200U)
#define CMC_SRIF_DAP_SHIFT                       (9U)
/*! DAP - DAP Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_DAP(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_DAP_SHIFT)) & CMC_SRIF_DAP_MASK)

#define CMC_SRIF_LPACK_MASK                      (0x800U)
#define CMC_SRIF_LPACK_SHIFT                     (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_LPACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_LPACK_SHIFT)) & CMC_SRIF_LPACK_MASK)

#define CMC_SRIF_WDOG0_MASK                      (0x2000U)
#define CMC_SRIF_WDOG0_SHIFT                     (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_WDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WDOG0_SHIFT)) & CMC_SRIF_WDOG0_MASK)

#define CMC_SRIF_SW_MASK                         (0x4000U)
#define CMC_SRIF_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_SW(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_SW_SHIFT)) & CMC_SRIF_SW_MASK)

#define CMC_SRIF_LOCKUP_MASK                     (0x8000U)
#define CMC_SRIF_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_LOCKUP_SHIFT)) & CMC_SRIF_LOCKUP_MASK)

#define CMC_SRIF_WDOG1_MASK                      (0x2000000U)
#define CMC_SRIF_WDOG1_SHIFT                     (25U)
/*! WDOG1 - Watchdog 1 Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_WDOG1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WDOG1_SHIFT)) & CMC_SRIF_WDOG1_MASK)

#define CMC_SRIF_CDOG0_MASK                      (0x4000000U)
#define CMC_SRIF_CDOG0_SHIFT                     (26U)
/*! CDOG0 - Code Watchdog 0 Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_CDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_CDOG0_SHIFT)) & CMC_SRIF_CDOG0_MASK)

#define CMC_SRIF_CDOG1_MASK                      (0x8000000U)
#define CMC_SRIF_CDOG1_SHIFT                     (27U)
/*! CDOG1 - Code Watchdog 1 Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_CDOG1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_CDOG1_SHIFT)) & CMC_SRIF_CDOG1_MASK)
/*! @} */

/*! @name RSTCNT - Reset Count Register */
/*! @{ */

#define CMC_RSTCNT_COUNT_MASK                    (0xFFU)
#define CMC_RSTCNT_COUNT_SHIFT                   (0U)
/*! COUNT - Count */
#define CMC_RSTCNT_COUNT(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_RSTCNT_COUNT_SHIFT)) & CMC_RSTCNT_COUNT_MASK)
/*! @} */

/*! @name MR - Mode */
/*! @{ */

#define CMC_MR_ISPMODE_n_MASK                    (0x1U)
#define CMC_MR_ISPMODE_n_SHIFT                   (0U)
/*! ISPMODE_n - Boot Configuration */
#define CMC_MR_ISPMODE_n(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_MR_ISPMODE_n_SHIFT)) & CMC_MR_ISPMODE_n_MASK)
/*! @} */

/*! @name FM - Force Mode */
/*! @{ */

#define CMC_FM_FORCECFG_MASK                     (0x1U)
#define CMC_FM_FORCECFG_SHIFT                    (0U)
/*! FORCECFG - Boot Configuration
 *  0b0..No effect
 *  0b1..Asserts
 */
#define CMC_FM_FORCECFG(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_FM_FORCECFG_SHIFT)) & CMC_FM_FORCECFG_MASK)
/*! @} */

/*! @name SRAMDIS - SRAM Disable */
/*! @{ */

#define CMC_SRAMDIS_DIS_MASK                     (0x3FU)
#define CMC_SRAMDIS_DIS_SHIFT                    (0U)
/*! DIS - Shut Down Enable */
#define CMC_SRAMDIS_DIS(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS_SHIFT)) & CMC_SRAMDIS_DIS_MASK)
/*! @} */

/*! @name SRAMRET - SRAM Retention */
/*! @{ */

#define CMC_SRAMRET_RET_MASK                     (0x3FU)
#define CMC_SRAMRET_RET_SHIFT                    (0U)
/*! RET - Deep Sleep Enable */
#define CMC_SRAMRET_RET(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET_SHIFT)) & CMC_SRAMRET_RET_MASK)
/*! @} */

/*! @name FLASHCR - Flash Control */
/*! @{ */

#define CMC_FLASHCR_FLASHDIS_MASK                (0x1U)
#define CMC_FLASHCR_FLASHDIS_SHIFT               (0U)
/*! FLASHDIS - Flash Disable
 *  0b0..No effect
 *  0b1..Flash memory is disabled
 */
#define CMC_FLASHCR_FLASHDIS(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_FLASHCR_FLASHDIS_SHIFT)) & CMC_FLASHCR_FLASHDIS_MASK)

#define CMC_FLASHCR_FLASHDOZE_MASK               (0x2U)
#define CMC_FLASHCR_FLASHDOZE_SHIFT              (1U)
/*! FLASHDOZE - Flash Doze
 *  0b0..No effect
 *  0b1..Flash memory is disabled when core is sleeping (CKMODE > 0)
 */
#define CMC_FLASHCR_FLASHDOZE(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_FLASHCR_FLASHDOZE_SHIFT)) & CMC_FLASHCR_FLASHDOZE_MASK)

#define CMC_FLASHCR_FLASHWAKE_MASK               (0x4U)
#define CMC_FLASHCR_FLASHWAKE_SHIFT              (2U)
/*! FLASHWAKE - Flash Wake
 *  0b0..No effect
 *  0b1..Flash memory is not disabled during flash memory accesses
 */
#define CMC_FLASHCR_FLASHWAKE(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_FLASHCR_FLASHWAKE_SHIFT)) & CMC_FLASHCR_FLASHWAKE_MASK)
/*! @} */

/*! @name DIER - Device Initialization Error Register */
/*! @{ */

#define CMC_DIER_STAT_MASK                       (0xFFFFFFFFU)
#define CMC_DIER_STAT_SHIFT                      (0U)
/*! STAT - Device initialization status flags */
#define CMC_DIER_STAT(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_DIER_STAT_SHIFT)) & CMC_DIER_STAT_MASK)
/*! @} */

/*! @name BLR - BootROM Lock Register */
/*! @{ */

#define CMC_BLR_LOCK0_MASK                       (0x7U)
#define CMC_BLR_LOCK0_SHIFT                      (0U)
/*! LOCK0 - Lock Scratch 0
 *  0b010..BootROM Scratch Register can be written
 *  0b101..BootROM Scratch Register cannot be written
 */
#define CMC_BLR_LOCK0(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_BLR_LOCK0_SHIFT)) & CMC_BLR_LOCK0_MASK)

#define CMC_BLR_LOCK1_MASK                       (0x38U)
#define CMC_BLR_LOCK1_SHIFT                      (3U)
/*! LOCK1 - Lock Scratch 1
 *  0b010..BootROM Scratch Register can be written
 *  0b101..BootROM Scratch Register cannot be written
 */
#define CMC_BLR_LOCK1(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_BLR_LOCK1_SHIFT)) & CMC_BLR_LOCK1_MASK)

#define CMC_BLR_LOCK2_MASK                       (0x1C0U)
#define CMC_BLR_LOCK2_SHIFT                      (6U)
/*! LOCK2 - Lock Scratch 2
 *  0b010..BootROM Scratch Register can be written
 *  0b101..BootROM Scratch Register cannot be written
 */
#define CMC_BLR_LOCK2(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_BLR_LOCK2_SHIFT)) & CMC_BLR_LOCK2_MASK)

#define CMC_BLR_LOCK3_MASK                       (0xE00U)
#define CMC_BLR_LOCK3_SHIFT                      (9U)
/*! LOCK3 - Lock Scratch 3
 *  0b010..BootROM Scratch Register can be written
 *  0b101..BootROM Scratch Register cannot be written
 */
#define CMC_BLR_LOCK3(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_BLR_LOCK3_SHIFT)) & CMC_BLR_LOCK3_MASK)
/*! @} */

/*! @name BSR - BootROM Scratch Register */
/*! @{ */

#define CMC_BSR_SCR_MASK                         (0xFFFFFFFFU)
#define CMC_BSR_SCR_SHIFT                        (0U)
/*! SCR - Register used by the BootROM */
#define CMC_BSR_SCR(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_BSR_SCR_SHIFT)) & CMC_BSR_SCR_MASK)
/*! @} */

/*! @name CORECTL - Core Control */
/*! @{ */

#define CMC_CORECTL_NPIE_MASK                    (0x1U)
#define CMC_CORECTL_NPIE_SHIFT                   (0U)
/*! NPIE - Non-maskable Pin Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define CMC_CORECTL_NPIE(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_CORECTL_NPIE_SHIFT)) & CMC_CORECTL_NPIE_MASK)
/*! @} */

/*! @name DBGCTL - Debug Control */
/*! @{ */

#define CMC_DBGCTL_SOD_MASK                      (0x1U)
#define CMC_DBGCTL_SOD_SHIFT                     (0U)
/*! SOD - Sleep Or Debug
 *  0b0..Remains enabled
 *  0b1..Disabled
 */
#define CMC_DBGCTL_SOD(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_DBGCTL_SOD_SHIFT)) & CMC_DBGCTL_SOD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMC_Register_Masks */


/*!
 * @}
 */ /* end of group CMC_Peripheral_Access_Layer */


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


#endif  /* PERI_CMC_H_ */

