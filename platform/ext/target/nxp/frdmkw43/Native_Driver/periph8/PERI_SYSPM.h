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
**         CMSIS Peripheral Access Layer for SYSPM
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
 * @file PERI_SYSPM.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for SYSPM
 *
 * CMSIS Peripheral Access Layer for SYSPM
 */

#if !defined(PERI_SYSPM_H_)
#define PERI_SYSPM_H_                            /**< Symbol preventing repeated inclusion */

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
   -- SYSPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPM_Peripheral_Access_Layer SYSPM Peripheral Access Layer
 * @{
 */

/** SYSPM - Size of Registers Arrays */
#define SYSPM_CFGSS_COUNT                         4u
#define SYSPM_PMCR_PMECTR_COUNT                   3u
#define SYSPM_PMCR_COUNT                          2u

/** SYSPM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CFGSS[SYSPM_CFGSS_COUNT];          /**< Configuration 0..Configuration 3, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[496];
  struct {                                         /* offset: 0x200, array step: 0x100 */
    __IO uint32_t PMCR;                              /**< Performance Monitor Control Register, array offset: 0x200, array step: 0x100 */
         uint8_t RESERVED_0[20];
    struct {                                         /* offset: 0x218, array step: index*0x100, index2*0x8 */
      __I  uint8_t HI;                                 /**< Performance Monitor Event Counter, array offset: 0x218, array step: index*0x100, index2*0x8 */
           uint8_t RESERVED_0[3];
      __I  uint32_t LO;                                /**< Performance Monitor Event Counter, array offset: 0x21C, array step: index*0x100, index2*0x8 */
    } PMECTR[SYSPM_PMCR_PMECTR_COUNT];
         uint8_t RESERVED_1[208];
  } PMCR[SYSPM_PMCR_COUNT];
} SYSPM_Type;

/* ----------------------------------------------------------------------------
   -- SYSPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPM_Register_Masks SYSPM Register Masks
 * @{
 */

/*! @name CFGSS - Configuration 0..Configuration 3 */
/*! @{ */

#define SYSPM_CFGSS_ID_MASK                      (0xFFU)
#define SYSPM_CFGSS_ID_SHIFT                     (0U)
/*! ID - Identifier
 *  0b00000000..CFGSS not present
 *  0b00000001..Reserved
 *  0b00000010..CFGSS PERFMON configuration
 *  0b00000011..CFGSS Configuration
 */
#define SYSPM_CFGSS_ID(x)                        (((uint32_t)(((uint32_t)(x)) << SYSPM_CFGSS_ID_SHIFT)) & SYSPM_CFGSS_ID_MASK)

#define SYSPM_CFGSS_HRL_MASK                     (0xFF00U)
#define SYSPM_CFGSS_HRL_SHIFT                    (8U)
/*! HRL - Hardware revision level */
#define SYSPM_CFGSS_HRL(x)                       (((uint32_t)(((uint32_t)(x)) << SYSPM_CFGSS_HRL_SHIFT)) & SYSPM_CFGSS_HRL_MASK)

#define SYSPM_CFGSS_NCTRS_MASK                   (0xFF0000U)
#define SYSPM_CFGSS_NCTRS_SHIFT                  (16U)
/*! NCTRS - Number of Counters */
#define SYSPM_CFGSS_NCTRS(x)                     (((uint32_t)(((uint32_t)(x)) << SYSPM_CFGSS_NCTRS_SHIFT)) & SYSPM_CFGSS_NCTRS_MASK)

#define SYSPM_CFGSS_MSC_MASK                     (0xFF000000U)
#define SYSPM_CFGSS_MSC_SHIFT                    (24U)
/*! MSC - Miscellaneous */
#define SYSPM_CFGSS_MSC(x)                       (((uint32_t)(((uint32_t)(x)) << SYSPM_CFGSS_MSC_SHIFT)) & SYSPM_CFGSS_MSC_MASK)
/*! @} */

/*! @name PMCR - Performance Monitor Control Register */
/*! @{ */

#define SYSPM_PMCR_MENB_MASK                     (0x1U)
#define SYSPM_PMCR_MENB_SHIFT                    (0U)
/*! MENB - Module is Enabled
 *  0b0..Disable the performance monitor.
 *  0b1..Enable the performance monitor.
 */
#define SYSPM_PMCR_MENB(x)                       (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_MENB_SHIFT)) & SYSPM_PMCR_MENB_MASK)

#define SYSPM_PMCR_SSC_MASK                      (0xEU)
#define SYSPM_PMCR_SSC_SHIFT                     (1U)
/*! SSC - Start/Stop Control
 *  0b000..Idle
 *  0b001..local stop
 *  0b010..local start
 *  0b011..local start
 *  0b100..
 *  0b101..
 *  0b110..
 *  0b111..
 */
#define SYSPM_PMCR_SSC(x)                        (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_SSC_SHIFT)) & SYSPM_PMCR_SSC_MASK)

#define SYSPM_PMCR_CMODE_MASK                    (0x30U)
#define SYSPM_PMCR_CMODE_SHIFT                   (4U)
/*! CMODE - Count Mode
 *  0b00..count in both user and privileged modes
 *  0b01..Reserved
 *  0b10..count only in user mode
 *  0b11..count only in privileged mode
 */
#define SYSPM_PMCR_CMODE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_CMODE_SHIFT)) & SYSPM_PMCR_CMODE_MASK)

#define SYSPM_PMCR_RICTR_MASK                    (0x80U)
#define SYSPM_PMCR_RICTR_SHIFT                   (7U)
/*! RICTR - Resets the Instruction Counter
 *  0b0..do not reset the instruction counter
 *  0b1..clear the instruction counter
 */
#define SYSPM_PMCR_RICTR(x)                      (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_RICTR_SHIFT)) & SYSPM_PMCR_RICTR_MASK)

#define SYSPM_PMCR_RECTR1_MASK                   (0x100U)
#define SYSPM_PMCR_RECTR1_SHIFT                  (8U)
/*! RECTR1 - Reset Event Counter 1 */
#define SYSPM_PMCR_RECTR1(x)                     (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_RECTR1_SHIFT)) & SYSPM_PMCR_RECTR1_MASK)

#define SYSPM_PMCR_RECTR2_MASK                   (0x200U)
#define SYSPM_PMCR_RECTR2_SHIFT                  (9U)
/*! RECTR2 - Reset Event Counter 2 */
#define SYSPM_PMCR_RECTR2(x)                     (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_RECTR2_SHIFT)) & SYSPM_PMCR_RECTR2_MASK)

#define SYSPM_PMCR_RECTR3_MASK                   (0x400U)
#define SYSPM_PMCR_RECTR3_SHIFT                  (10U)
/*! RECTR3 - Reset Event Counter 3
 *  0b0..Counter runs normally
 *  0b1..Counter value resets at the end of the cycle
 */
#define SYSPM_PMCR_RECTR3(x)                     (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_RECTR3_SHIFT)) & SYSPM_PMCR_RECTR3_MASK)

#define SYSPM_PMCR_SELEVT1_MASK                  (0x3F800U)
#define SYSPM_PMCR_SELEVT1_SHIFT                 (11U)
/*! SELEVT1 - Select Event 1 */
#define SYSPM_PMCR_SELEVT1(x)                    (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_SELEVT1_SHIFT)) & SYSPM_PMCR_SELEVT1_MASK)

#define SYSPM_PMCR_SELEVT2_MASK                  (0x1FC0000U)
#define SYSPM_PMCR_SELEVT2_SHIFT                 (18U)
/*! SELEVT2 - Select Event 2 */
#define SYSPM_PMCR_SELEVT2(x)                    (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_SELEVT2_SHIFT)) & SYSPM_PMCR_SELEVT2_MASK)

#define SYSPM_PMCR_SELEVT3_MASK                  (0xFE000000U)
#define SYSPM_PMCR_SELEVT3_SHIFT                 (25U)
/*! SELEVT3 - Select Event 3 */
#define SYSPM_PMCR_SELEVT3(x)                    (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_SELEVT3_SHIFT)) & SYSPM_PMCR_SELEVT3_MASK)
/*! @} */

/*! @name HI - Performance Monitor Event Counter */
/*! @{ */

#define SYSPM_HI_ECTR_MASK                       (0xFFU)
#define SYSPM_HI_ECTR_SHIFT                      (0U)
/*! ECTR - Event Counter */
#define SYSPM_HI_ECTR(x)                         (((uint8_t)(((uint8_t)(x)) << SYSPM_HI_ECTR_SHIFT)) & SYSPM_HI_ECTR_MASK)
/*! @} */

/* The count of SYSPM_HI */
#define SYSPM_HI_COUNT                           (2U)

/* The count of SYSPM_HI */
#define SYSPM_HI_COUNT2                          (3U)

/*! @name LO - Performance Monitor Event Counter */
/*! @{ */

#define SYSPM_LO_ECTR_MASK                       (0xFFFFFFFFU)
#define SYSPM_LO_ECTR_SHIFT                      (0U)
/*! ECTR - Event Counter */
#define SYSPM_LO_ECTR(x)                         (((uint32_t)(((uint32_t)(x)) << SYSPM_LO_ECTR_SHIFT)) & SYSPM_LO_ECTR_MASK)
/*! @} */

/* The count of SYSPM_LO */
#define SYSPM_LO_COUNT                           (2U)

/* The count of SYSPM_LO */
#define SYSPM_LO_COUNT2                          (3U)


/*!
 * @}
 */ /* end of group SYSPM_Register_Masks */


/*!
 * @}
 */ /* end of group SYSPM_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSPM_H_ */

