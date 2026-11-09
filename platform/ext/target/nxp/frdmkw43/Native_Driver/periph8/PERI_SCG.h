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
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_SCG.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for SCG
 *
 * CMSIS Peripheral Access Layer for SCG
 */

#if !defined(PERI_SCG_H_)
#define PERI_SCG_H_                              /**< Symbol preventing repeated inclusion */

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
   -- SCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Peripheral_Access_Layer SCG Peripheral Access Layer
 * @{
 */

/** SCG - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __I  uint32_t CSR;                               /**< Clock Status Register, offset: 0x10 */
  __IO uint32_t RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       uint8_t RESERVED_2[220];
  __IO uint32_t SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
       uint8_t RESERVED_3[252];
  __IO uint32_t SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
       uint8_t RESERVED_4[252];
  __IO uint32_t FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
  __IO uint32_t FIRCTCFG;                          /**< Fast IRC Trim Configuration Register, offset: 0x30C */
       uint8_t RESERVED_6[8];
  __IO uint32_t FIRCSTAT;                          /**< Fast IRC Status Register, offset: 0x318 */
       uint8_t RESERVED_7[228];
  __IO uint32_t ROSCCSR;                           /**< RTC OSC Control Status Register, offset: 0x400 */
} SCG_Type;

/* ----------------------------------------------------------------------------
   -- SCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Masks SCG Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define SCG_VERID_VERSION_MASK                   (0xFFFFFFFFU)
#define SCG_VERID_VERSION_SHIFT                  (0U)
/*! VERSION - SCG Version Number */
#define SCG_VERID_VERSION(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_VERID_VERSION_SHIFT)) & SCG_VERID_VERSION_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define SCG_PARAM_CLKPRES_MASK                   (0xFFU)
#define SCG_PARAM_CLKPRES_SHIFT                  (0U)
/*! CLKPRES - Clock Present
 *  0b00000000-0b00000001..Reserved
 *  0bxxx1xxxx..RTC OSC (ROSC) is present.
 *  0bxxxx1xxx..Fast IRC (FIRC) is present.
 *  0bxxxxx1xx..Slow IRC (SIRC) is present.
 *  0bxxxxxx1x..System OSC (SOSC) is present.
 */
#define SCG_PARAM_CLKPRES(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_CLKPRES_SHIFT)) & SCG_PARAM_CLKPRES_MASK)

#define SCG_PARAM_DIVPRES_MASK                   (0xF8000000U)
#define SCG_PARAM_DIVPRES_SHIFT                  (27U)
/*! DIVPRES - Divider Present
 *  0b1xxxx..System DIVCORE is present.
 *  0bx1xxx..System DIVPLAT is present.
 *  0bxxx1x..System DIVBUS is present.
 *  0bxxxx1..System DIVSLOW is present.
 */
#define SCG_PARAM_DIVPRES(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_DIVPRES_SHIFT)) & SCG_PARAM_DIVPRES_MASK)
/*! @} */

/*! @name CSR - Clock Status Register */
/*! @{ */

#define SCG_CSR_DIVSLOW_MASK                     (0xFU)
#define SCG_CSR_DIVSLOW_SHIFT                    (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_CSR_DIVSLOW(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVSLOW_SHIFT)) & SCG_CSR_DIVSLOW_MASK)

#define SCG_CSR_DIVBUS_MASK                      (0xF0U)
#define SCG_CSR_DIVBUS_SHIFT                     (4U)
/*! DIVBUS - Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_CSR_DIVBUS(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVBUS_SHIFT)) & SCG_CSR_DIVBUS_MASK)

#define SCG_CSR_DIVPLAT_MASK                     (0xF000U)
#define SCG_CSR_DIVPLAT_SHIFT                    (12U)
/*! DIVPLAT - Platform Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SCG_CSR_DIVPLAT(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVPLAT_SHIFT)) & SCG_CSR_DIVPLAT_MASK)

#define SCG_CSR_DIVCORE_MASK                     (0xF0000U)
#define SCG_CSR_DIVCORE_SHIFT                    (16U)
/*! DIVCORE - Core Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_CSR_DIVCORE(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVCORE_SHIFT)) & SCG_CSR_DIVCORE_MASK)

#define SCG_CSR_SCS_MASK                         (0xF000000U)
#define SCG_CSR_SCS_SHIFT                        (24U)
/*! SCS - System Clock Source
 *  0b0000..Reserved
 *  0b0001..System OSC (SOSC_CLK)
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 */
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x)) << SCG_CSR_SCS_SHIFT)) & SCG_CSR_SCS_MASK)
/*! @} */

/*! @name RCCR - Run Clock Control Register */
/*! @{ */

#define SCG_RCCR_DIVSLOW_MASK                    (0xFU)
#define SCG_RCCR_DIVSLOW_SHIFT                   (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_RCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVSLOW_SHIFT)) & SCG_RCCR_DIVSLOW_MASK)

#define SCG_RCCR_DIVBUS_MASK                     (0xF0U)
#define SCG_RCCR_DIVBUS_SHIFT                    (4U)
/*! DIVBUS - Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_RCCR_DIVBUS(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVBUS_SHIFT)) & SCG_RCCR_DIVBUS_MASK)

#define SCG_RCCR_DIVPLAT_MASK                    (0xF000U)
#define SCG_RCCR_DIVPLAT_SHIFT                   (12U)
/*! DIVPLAT - Platform Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SCG_RCCR_DIVPLAT(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVPLAT_SHIFT)) & SCG_RCCR_DIVPLAT_MASK)

#define SCG_RCCR_DIVCORE_MASK                    (0xF0000U)
#define SCG_RCCR_DIVCORE_SHIFT                   (16U)
/*! DIVCORE - Core Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_RCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVCORE_SHIFT)) & SCG_RCCR_DIVCORE_MASK)

#define SCG_RCCR_SCS_MASK                        (0x7000000U)
#define SCG_RCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b000..Reserved
 *  0b001..System OSC (SOSC_CLK)
 *  0b010..Slow IRC (SIRC_CLK)
 *  0b011..Fast IRC (FIRC_CLK)
 *  0b100..RTC OSC (ROSC_CLK)
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_SCS_SHIFT)) & SCG_RCCR_SCS_MASK)
/*! @} */

/*! @name CLKOUTCNFG - SCG CLKOUT Configuration Register */
/*! @{ */

#define SCG_CLKOUTCNFG_CLKOUTSEL_MASK            (0xF000000U)
#define SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT           (24U)
/*! CLKOUTSEL - SCG Clkout Select
 *  0b0000..SCG SLOW Clock
 *  0b0001..System OSC (SOSC_CLK)
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1111..Reserved
 */
#define SCG_CLKOUTCNFG_CLKOUTSEL(x)              (((uint32_t)(((uint32_t)(x)) << SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT)) & SCG_CLKOUTCNFG_CLKOUTSEL_MASK)
/*! @} */

/*! @name SOSCCSR - System OSC Control Status Register */
/*! @{ */

#define SCG_SOSCCSR_SOSCEN_MASK                  (0x1U)
#define SCG_SOSCCSR_SOSCEN_SHIFT                 (0U)
/*! SOSCEN - System OSC Enable
 *  0b0..System OSC is disabled
 *  0b1..System OSC is enabled
 */
#define SCG_SOSCCSR_SOSCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCEN_SHIFT)) & SCG_SOSCCSR_SOSCEN_MASK)

#define SCG_SOSCCSR_SOSCSTEN_MASK                (0x2U)
#define SCG_SOSCCSR_SOSCSTEN_SHIFT               (1U)
/*! SOSCSTEN - System OSC Stop Enable
 *  0b0..System OSC is disabled in any of the sleep modes
 *  0b1..System OSC is enabled in SLEEP mode only if SOSCEN=1. SOSCSTEN must be cleared when its power domain is
 *       going to enter Deep Sleep or Power Down mode.
 */
#define SCG_SOSCCSR_SOSCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSTEN_SHIFT)) & SCG_SOSCCSR_SOSCSTEN_MASK)

#define SCG_SOSCCSR_SOSCLPEN_MASK                (0x4U)
#define SCG_SOSCCSR_SOSCLPEN_SHIFT               (2U)
/*! SOSCLPEN - System OSC Low Power Enable
 *  0b0..System OSC is disabled in VLP modes
 *  0b1..System OSC is enabled in VLP modes
 */
#define SCG_SOSCCSR_SOSCLPEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCLPEN_SHIFT)) & SCG_SOSCCSR_SOSCLPEN_MASK)

#define SCG_SOSCCSR_SOSCCM_MASK                  (0x10000U)
#define SCG_SOSCCSR_SOSCCM_SHIFT                 (16U)
/*! SOSCCM - System OSC Clock Monitor Enable
 *  0b0..System OSC Clock Monitor is disabled
 *  0b1..System OSC Clock Monitor is enabled
 */
#define SCG_SOSCCSR_SOSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCM_SHIFT)) & SCG_SOSCCSR_SOSCCM_MASK)

#define SCG_SOSCCSR_SOSCCMRE_MASK                (0x20000U)
#define SCG_SOSCCSR_SOSCCMRE_SHIFT               (17U)
/*! SOSCCMRE - System OSC Clock Monitor Reset Enable
 *  0b0..Clock Monitor generates interrupt when error detected
 *  0b1..Clock Monitor generates reset when error detected
 */
#define SCG_SOSCCSR_SOSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCMRE_SHIFT)) & SCG_SOSCCSR_SOSCCMRE_MASK)

#define SCG_SOSCCSR_LK_MASK                      (0x800000U)
#define SCG_SOSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..This Control Status Register can be written.
 *  0b1..This Control Status Register cannot be written.
 */
#define SCG_SOSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_LK_SHIFT)) & SCG_SOSCCSR_LK_MASK)

#define SCG_SOSCCSR_SOSCVLD_MASK                 (0x1000000U)
#define SCG_SOSCCSR_SOSCVLD_SHIFT                (24U)
/*! SOSCVLD - System OSC Valid
 *  0b0..System OSC is not enabled or clock is not valid
 *  0b1..System OSC is enabled and output clock is valid
 */
#define SCG_SOSCCSR_SOSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCVLD_SHIFT)) & SCG_SOSCCSR_SOSCVLD_MASK)

#define SCG_SOSCCSR_SOSCSEL_MASK                 (0x2000000U)
#define SCG_SOSCCSR_SOSCSEL_SHIFT                (25U)
/*! SOSCSEL - System OSC Selected
 *  0b0..System OSC is not the system clock source
 *  0b1..System OSC is the system clock source
 */
#define SCG_SOSCCSR_SOSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSEL_SHIFT)) & SCG_SOSCCSR_SOSCSEL_MASK)

#define SCG_SOSCCSR_SOSCERR_MASK                 (0x4000000U)
#define SCG_SOSCCSR_SOSCERR_SHIFT                (26U)
/*! SOSCERR - System OSC Clock Error
 *  0b0..System OSC Clock Monitor is disabled or has not detected an error
 *  0b1..System OSC Clock Monitor is enabled and detected an error
 */
#define SCG_SOSCCSR_SOSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCERR_SHIFT)) & SCG_SOSCCSR_SOSCERR_MASK)
/*! @} */

/*! @name SIRCCSR - Slow IRC Control Status Register */
/*! @{ */

#define SCG_SIRCCSR_SIRCSTEN_MASK                (0x2U)
#define SCG_SIRCCSR_SIRCSTEN_SHIFT               (1U)
/*! SIRCSTEN - Slow IRC Stop Enable
 *  0b0..Slow IRC is disabled in sleep modes
 *  0b1..Slow IRC is enabled in SLEEP mode
 */
#define SCG_SIRCCSR_SIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSTEN_SHIFT)) & SCG_SIRCCSR_SIRCSTEN_MASK)

#define SCG_SIRCCSR_SIRCLPEN_MASK                (0x4U)
#define SCG_SIRCCSR_SIRCLPEN_SHIFT               (2U)
/*! SIRCLPEN - Slow IRC Low Power Enable
 *  0b0..Slow IRC is disabled in VLP modes
 *  0b1..Slow IRC is enabled in VLP modes
 */
#define SCG_SIRCCSR_SIRCLPEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCLPEN_SHIFT)) & SCG_SIRCCSR_SIRCLPEN_MASK)

#define SCG_SIRCCSR_LK_MASK                      (0x800000U)
#define SCG_SIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_SIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_LK_SHIFT)) & SCG_SIRCCSR_LK_MASK)

#define SCG_SIRCCSR_SIRCVLD_MASK                 (0x1000000U)
#define SCG_SIRCCSR_SIRCVLD_SHIFT                (24U)
/*! SIRCVLD - Slow IRC Valid
 *  0b0..Slow IRC is not enabled or clock is not valid
 *  0b1..Slow IRC is enabled and output clock is valid
 */
#define SCG_SIRCCSR_SIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCVLD_SHIFT)) & SCG_SIRCCSR_SIRCVLD_MASK)

#define SCG_SIRCCSR_SIRCSEL_MASK                 (0x2000000U)
#define SCG_SIRCCSR_SIRCSEL_SHIFT                (25U)
/*! SIRCSEL - Slow IRC Selected
 *  0b0..Slow IRC is not the system clock source
 *  0b1..Slow IRC is the system clock source
 */
#define SCG_SIRCCSR_SIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSEL_SHIFT)) & SCG_SIRCCSR_SIRCSEL_MASK)
/*! @} */

/*! @name FIRCCSR - Fast IRC Control Status Register */
/*! @{ */

#define SCG_FIRCCSR_FIRCEN_MASK                  (0x1U)
#define SCG_FIRCCSR_FIRCEN_SHIFT                 (0U)
/*! FIRCEN - Fast IRC Enable
 *  0b0..Fast IRC is disabled
 *  0b1..Fast IRC is enabled
 */
#define SCG_FIRCCSR_FIRCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCEN_SHIFT)) & SCG_FIRCCSR_FIRCEN_MASK)

#define SCG_FIRCCSR_FIRCSTEN_MASK                (0x2U)
#define SCG_FIRCCSR_FIRCSTEN_SHIFT               (1U)
/*! FIRCSTEN - Fast IRC Stop Enable
 *  0b0..Fast IRC is disabled in sleep modes.
 *  0b1..Fast IRC is enabled in SLEEP modes
 */
#define SCG_FIRCCSR_FIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSTEN_SHIFT)) & SCG_FIRCCSR_FIRCSTEN_MASK)

#define SCG_FIRCCSR_FIRCLPEN_MASK                (0x4U)
#define SCG_FIRCCSR_FIRCLPEN_SHIFT               (2U)
/*! FIRCLPEN - Fast IRC Low Power Enable
 *  0b0..Fast IRC is disabled in VLP modes
 *  0b1..Fast IRC is enabled in VLP modes
 */
#define SCG_FIRCCSR_FIRCLPEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCLPEN_SHIFT)) & SCG_FIRCCSR_FIRCLPEN_MASK)

#define SCG_FIRCCSR_FIRCTREN_MASK                (0x100U)
#define SCG_FIRCCSR_FIRCTREN_SHIFT               (8U)
/*! FIRCTREN - Fast IRC Trim Enable
 *  0b0..Disable trimming Fast IRC to an external clock source
 *  0b1..Enable trimming Fast IRC to an external clock source
 */
#define SCG_FIRCCSR_FIRCTREN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTREN_SHIFT)) & SCG_FIRCCSR_FIRCTREN_MASK)

#define SCG_FIRCCSR_FIRCTRUP_MASK                (0x200U)
#define SCG_FIRCCSR_FIRCTRUP_SHIFT               (9U)
/*! FIRCTRUP - Fast IRC Trim Update
 *  0b0..Disable Fast IRC trimming updates
 *  0b1..Enable Fast IRC trimming updates
 */
#define SCG_FIRCCSR_FIRCTRUP(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTRUP_SHIFT)) & SCG_FIRCCSR_FIRCTRUP_MASK)

#define SCG_FIRCCSR_TRIM_LOCK_MASK               (0x400U)
#define SCG_FIRCCSR_TRIM_LOCK_SHIFT              (10U)
/*! TRIM_LOCK - Fast IRC TRIM LOCK
 *  0b0..FIRC auto trim not locked to target frequency range.
 *  0b1..FIRC auto trim locked to target frequency range
 */
#define SCG_FIRCCSR_TRIM_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_TRIM_LOCK_SHIFT)) & SCG_FIRCCSR_TRIM_LOCK_MASK)

#define SCG_FIRCCSR_COARSE_TRIM_BYPASS_MASK      (0x800U)
#define SCG_FIRCCSR_COARSE_TRIM_BYPASS_SHIFT     (11U)
/*! COARSE_TRIM_BYPASS - Fast Coarse Auto Trim Bypass
 *  0b0..FIRC Coarse Auto Trim NOT Bypassed
 *  0b1..FIRC Coarse Auto Trim Bypassed
 */
#define SCG_FIRCCSR_COARSE_TRIM_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_COARSE_TRIM_BYPASS_SHIFT)) & SCG_FIRCCSR_COARSE_TRIM_BYPASS_MASK)

#define SCG_FIRCCSR_LK_MASK                      (0x800000U)
#define SCG_FIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_FIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_LK_SHIFT)) & SCG_FIRCCSR_LK_MASK)

#define SCG_FIRCCSR_FIRCVLD_MASK                 (0x1000000U)
#define SCG_FIRCCSR_FIRCVLD_SHIFT                (24U)
/*! FIRCVLD - Fast IRC Valid status
 *  0b0..Fast IRC is not enabled or clock is not valid.
 *  0b1..Fast IRC is enabled and output clock is valid. The clock is valid after there is an output clock from the FIRC analog.
 */
#define SCG_FIRCCSR_FIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCVLD_SHIFT)) & SCG_FIRCCSR_FIRCVLD_MASK)

#define SCG_FIRCCSR_FIRCSEL_MASK                 (0x2000000U)
#define SCG_FIRCCSR_FIRCSEL_SHIFT                (25U)
/*! FIRCSEL - Fast IRC Selected status
 *  0b0..Fast IRC is not the system clock source
 *  0b1..Fast IRC is the system clock source
 */
#define SCG_FIRCCSR_FIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSEL_SHIFT)) & SCG_FIRCCSR_FIRCSEL_MASK)

#define SCG_FIRCCSR_FIRCERR_MASK                 (0x4000000U)
#define SCG_FIRCCSR_FIRCERR_SHIFT                (26U)
/*! FIRCERR - Fast IRC Clock Error
 *  0b0..Error not detected with the Fast IRC trimming.
 *  0b1..Error detected with the Fast IRC trimming.
 */
#define SCG_FIRCCSR_FIRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCERR_SHIFT)) & SCG_FIRCCSR_FIRCERR_MASK)
/*! @} */

/*! @name FIRCCFG - Fast IRC Configuration Register */
/*! @{ */

#define SCG_FIRCCFG_RANGE_MASK                   (0x3U)
#define SCG_FIRCCFG_RANGE_SHIFT                  (0U)
/*! RANGE - Frequency Range
 *  0b00..48 MHz FIRC clock selected.
 *  0b01..64 MHz FIRC clock selected.
 *  0b10..96 MHz FIRC clock selected.
 *  0b11..192 MHz FIRC clock selected.
 */
#define SCG_FIRCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCFG_RANGE_SHIFT)) & SCG_FIRCCFG_RANGE_MASK)
/*! @} */

/*! @name FIRCTCFG - Fast IRC Trim Configuration Register */
/*! @{ */

#define SCG_FIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_FIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..System OSC. This option requires that SOSC be divided using the TRIMDIV field to get a frequency of 1 MHz.
 *  0b11..RTC OSC (32.768 kHz)
 */
#define SCG_FIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMSRC_SHIFT)) & SCG_FIRCTCFG_TRIMSRC_MASK)

#define SCG_FIRCTCFG_TRIMDIV_MASK                (0x7FF0000U)
#define SCG_FIRCTCFG_TRIMDIV_SHIFT               (16U)
/*! TRIMDIV - Fast IRC Trim Predivide */
#define SCG_FIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMDIV_SHIFT)) & SCG_FIRCTCFG_TRIMDIV_MASK)
/*! @} */

/*! @name FIRCSTAT - Fast IRC Status Register */
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

/*! @name ROSCCSR - RTC OSC Control Status Register */
/*! @{ */

#define SCG_ROSCCSR_ROSCCM_MASK                  (0x10000U)
#define SCG_ROSCCSR_ROSCCM_SHIFT                 (16U)
/*! ROSCCM - RTC OSC Clock Monitor
 *  0b0..RTC OSC Clock Monitor is disabled
 *  0b1..RTC OSC Clock Monitor is enabled
 */
#define SCG_ROSCCSR_ROSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCCM_SHIFT)) & SCG_ROSCCSR_ROSCCM_MASK)

#define SCG_ROSCCSR_ROSCCMRE_MASK                (0x20000U)
#define SCG_ROSCCSR_ROSCCMRE_SHIFT               (17U)
/*! ROSCCMRE - RTC OSC Clock Monitor Reset Enable
 *  0b0..Clock Monitor generates interrupt when error detected
 *  0b1..Clock Monitor generates reset when error detected
 */
#define SCG_ROSCCSR_ROSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCCMRE_SHIFT)) & SCG_ROSCCSR_ROSCCMRE_MASK)

#define SCG_ROSCCSR_LK_MASK                      (0x800000U)
#define SCG_ROSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_ROSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_LK_SHIFT)) & SCG_ROSCCSR_LK_MASK)

#define SCG_ROSCCSR_ROSCVLD_MASK                 (0x1000000U)
#define SCG_ROSCCSR_ROSCVLD_SHIFT                (24U)
/*! ROSCVLD - RTC OSC Valid
 *  0b0..RTC OSC is not enabled or clock is not valid
 *  0b1..RTC OSC is enabled and output clock is valid
 */
#define SCG_ROSCCSR_ROSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCVLD_SHIFT)) & SCG_ROSCCSR_ROSCVLD_MASK)

#define SCG_ROSCCSR_ROSCSEL_MASK                 (0x2000000U)
#define SCG_ROSCCSR_ROSCSEL_SHIFT                (25U)
/*! ROSCSEL - RTC OSC Selected
 *  0b0..RTC OSC is not the system clock source
 *  0b1..RTC OSC is the system clock source
 */
#define SCG_ROSCCSR_ROSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCSEL_SHIFT)) & SCG_ROSCCSR_ROSCSEL_MASK)

#define SCG_ROSCCSR_ROSCERR_MASK                 (0x4000000U)
#define SCG_ROSCCSR_ROSCERR_SHIFT                (26U)
/*! ROSCERR - RTC OSC Clock Error
 *  0b0..RTC OSC Clock Monitor is disabled or has not detected an error
 *  0b1..RTC OSC Clock Monitor is enabled and detected an RTC loss of clock error
 */
#define SCG_ROSCCSR_ROSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCERR_SHIFT)) & SCG_ROSCCSR_ROSCERR_MASK)
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

