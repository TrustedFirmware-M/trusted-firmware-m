/*
** ###################################################################
**     Processors:          MIMX9301CVVXD_ca55
**                          MIMX9301CVVXD_cm33
**                          MIMX9301DVVXD_ca55
**                          MIMX9301DVVXD_cm33
**                          MIMX9302CVVXD_ca55
**                          MIMX9302CVVXD_cm33
**                          MIMX9302DVVXD_ca55
**                          MIMX9302DVVXD_cm33
**                          MIMX9311CVXXM_ca55
**                          MIMX9311CVXXM_cm33
**                          MIMX9311DVXXM_ca55
**                          MIMX9311DVXXM_cm33
**                          MIMX9311XVXXM_ca55
**                          MIMX9311XVXXM_cm33
**                          MIMX9312CVXXM_ca55
**                          MIMX9312CVXXM_cm33
**                          MIMX9312DVXXM_ca55
**                          MIMX9312DVXXM_cm33
**                          MIMX9312XVXXM_ca55
**                          MIMX9312XVXXM_cm33
**                          MIMX9321CVXXM_ca55
**                          MIMX9321CVXXM_cm33
**                          MIMX9321DVXXM_ca55
**                          MIMX9321DVXXM_cm33
**                          MIMX9321XVXXM_ca55
**                          MIMX9321XVXXM_cm33
**                          MIMX9322CVXXM_ca55
**                          MIMX9322CVXXM_cm33
**                          MIMX9322DVXXM_ca55
**                          MIMX9322DVXXM_cm33
**                          MIMX9322XVXXM_ca55
**                          MIMX9322XVXXM_cm33
**                          MIMX9331AVTXM_ca55
**                          MIMX9331AVTXM_cm33
**                          MIMX9331CVVXM_ca55
**                          MIMX9331CVVXM_cm33
**                          MIMX9331DVVXM_ca55
**                          MIMX9331DVVXM_cm33
**                          MIMX9331XVVXM_ca55
**                          MIMX9331XVVXM_cm33
**                          MIMX9332AVTXM_ca55
**                          MIMX9332AVTXM_cm33
**                          MIMX9332CVVXM_ca55
**                          MIMX9332CVVXM_cm33
**                          MIMX9332DVVXM_ca55
**                          MIMX9332DVVXM_cm33
**                          MIMX9332XVVXM_ca55
**                          MIMX9332XVVXM_cm33
**                          MIMX9351AVTXM_ca55
**                          MIMX9351AVTXM_cm33
**                          MIMX9351CVVXM_ca55
**                          MIMX9351CVVXM_cm33
**                          MIMX9351DVVXM_ca55
**                          MIMX9351DVVXM_cm33
**                          MIMX9351XVVXM_ca55
**                          MIMX9351XVVXM_cm33
**                          MIMX9352AVTXM_ca55
**                          MIMX9352AVTXM_cm33
**                          MIMX9352CVVXM_ca55
**                          MIMX9352CVVXM_cm33
**                          MIMX9352DVVXM_ca55
**                          MIMX9352DVVXM_cm33
**                          MIMX9352XVVXM_ca55
**                          MIMX9352XVVXM_cm33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSPM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSPM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSPM
 *
 * CMSIS Peripheral Access Layer for SYSPM
 */

#if !defined(PERI_SYSPM_H_)
#define PERI_SYSPM_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9301CVVXD_ca55) || defined(CPU_MIMX9301DVVXD_ca55))
#include "MIMX9301_ca55_COMMON.h"
#elif (defined(CPU_MIMX9301CVVXD_cm33) || defined(CPU_MIMX9301DVVXD_cm33))
#include "MIMX9301_cm33_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_ca55) || defined(CPU_MIMX9302DVVXD_ca55))
#include "MIMX9302_ca55_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_cm33) || defined(CPU_MIMX9302DVVXD_cm33))
#include "MIMX9302_cm33_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_ca55) || defined(CPU_MIMX9311DVXXM_ca55) || defined(CPU_MIMX9311XVXXM_ca55))
#include "MIMX9311_ca55_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_cm33) || defined(CPU_MIMX9311DVXXM_cm33) || defined(CPU_MIMX9311XVXXM_cm33))
#include "MIMX9311_cm33_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_ca55) || defined(CPU_MIMX9312DVXXM_ca55) || defined(CPU_MIMX9312XVXXM_ca55))
#include "MIMX9312_ca55_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_cm33) || defined(CPU_MIMX9312DVXXM_cm33) || defined(CPU_MIMX9312XVXXM_cm33))
#include "MIMX9312_cm33_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_ca55) || defined(CPU_MIMX9321DVXXM_ca55) || defined(CPU_MIMX9321XVXXM_ca55))
#include "MIMX9321_ca55_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_cm33) || defined(CPU_MIMX9321DVXXM_cm33) || defined(CPU_MIMX9321XVXXM_cm33))
#include "MIMX9321_cm33_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_ca55) || defined(CPU_MIMX9322DVXXM_ca55) || defined(CPU_MIMX9322XVXXM_ca55))
#include "MIMX9322_ca55_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_cm33) || defined(CPU_MIMX9322DVXXM_cm33) || defined(CPU_MIMX9322XVXXM_cm33))
#include "MIMX9322_cm33_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_ca55) || defined(CPU_MIMX9331CVVXM_ca55) || defined(CPU_MIMX9331DVVXM_ca55) || defined(CPU_MIMX9331XVVXM_ca55))
#include "MIMX9331_ca55_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_cm33) || defined(CPU_MIMX9331CVVXM_cm33) || defined(CPU_MIMX9331DVVXM_cm33) || defined(CPU_MIMX9331XVVXM_cm33))
#include "MIMX9331_cm33_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_ca55) || defined(CPU_MIMX9332CVVXM_ca55) || defined(CPU_MIMX9332DVVXM_ca55) || defined(CPU_MIMX9332XVVXM_ca55))
#include "MIMX9332_ca55_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_cm33) || defined(CPU_MIMX9332CVVXM_cm33) || defined(CPU_MIMX9332DVVXM_cm33) || defined(CPU_MIMX9332XVVXM_cm33))
#include "MIMX9332_cm33_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_ca55) || defined(CPU_MIMX9351CVVXM_ca55) || defined(CPU_MIMX9351DVVXM_ca55) || defined(CPU_MIMX9351XVVXM_ca55))
#include "MIMX9351_ca55_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_cm33) || defined(CPU_MIMX9351CVVXM_cm33) || defined(CPU_MIMX9351DVVXM_cm33) || defined(CPU_MIMX9351XVVXM_cm33))
#include "MIMX9351_cm33_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_ca55) || defined(CPU_MIMX9352CVVXM_ca55) || defined(CPU_MIMX9352DVVXM_ca55) || defined(CPU_MIMX9352XVVXM_ca55))
#include "MIMX9352_ca55_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_cm33) || defined(CPU_MIMX9352CVVXM_cm33) || defined(CPU_MIMX9352DVVXM_cm33) || defined(CPU_MIMX9352XVVXM_cm33))
#include "MIMX9352_cm33_COMMON.h"
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
#define SYSPM_PMCR_PMECTR_COUNT                   3u
#define SYSPM_PMCR_COUNT                          2u

/** SYSPM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    __IO uint32_t PMCR;                              /**< Performance Monitor Control, array offset: 0x0, array step: 0x100 */
         uint8_t RESERVED_0[12];
    __I  uint8_t PMICTR_HI;                          /**< Performance Monitor Instruction Counter, array offset: 0x10, array step: 0x100 */
         uint8_t RESERVED_1[3];
    __I  uint32_t PMICTR_LO;                         /**< Performance Monitor Instruction Counter, array offset: 0x14, array step: 0x100 */
    struct {                                         /* offset: 0x18, array step: index*0x100, index2*0x8 */
      __I  uint8_t HI;                                 /**< Performance Monitor Event Counter, array offset: 0x18, array step: index*0x100, index2*0x8 */
           uint8_t RESERVED_0[3];
      __I  uint32_t LO;                                /**< Performance Monitor Event Counter, array offset: 0x1C, array step: index*0x100, index2*0x8 */
    } PMECTR[SYSPM_PMCR_PMECTR_COUNT];
         uint8_t RESERVED_2[208];
  } PMCR[SYSPM_PMCR_COUNT];
} SYSPM_Type;

/* ----------------------------------------------------------------------------
   -- SYSPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPM_Register_Masks SYSPM Register Masks
 * @{
 */

/*! @name PMCR - Performance Monitor Control */
/*! @{ */

#define SYSPM_PMCR_MENB_MASK                     (0x1U)
#define SYSPM_PMCR_MENB_SHIFT                    (0U)
/*! MENB - Module Is Enabled
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSPM_PMCR_MENB(x)                       (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_MENB_SHIFT)) & SYSPM_PMCR_MENB_MASK)

#define SYSPM_PMCR_SSC_MASK                      (0xEU)
#define SYSPM_PMCR_SSC_SHIFT                     (1U)
/*! SSC - Start and Stop Control
 *  0b000..Idle or no-op
 *  0b001..Local stop
 *  0b010, 0b011..Local start
 *  0b100..
 *  0b101..
 *  0b110, 0b111..
 */
#define SYSPM_PMCR_SSC(x)                        (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_SSC_SHIFT)) & SYSPM_PMCR_SSC_MASK)

#define SYSPM_PMCR_CMODE_MASK                    (0x30U)
#define SYSPM_PMCR_CMODE_SHIFT                   (4U)
/*! CMODE - Count Mode
 *  0b00..Counted in both User and Privileged modes
 *  0b01..
 *  0b10..Counted only in User mode
 *  0b11..Counted only in Privileged mode
 */
#define SYSPM_PMCR_CMODE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_CMODE_SHIFT)) & SYSPM_PMCR_CMODE_MASK)

#define SYSPM_PMCR_DCIFSH_MASK                   (0x40U)
#define SYSPM_PMCR_DCIFSH_SHIFT                  (6U)
/*! DCIFSH - Disable Counters if Stopped or Halted
 *  0b0..Continue
 *  0b1..Stop
 */
#define SYSPM_PMCR_DCIFSH(x)                     (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_DCIFSH_SHIFT)) & SYSPM_PMCR_DCIFSH_MASK)

#define SYSPM_PMCR_RICTR_MASK                    (0x80U)
#define SYSPM_PMCR_RICTR_SHIFT                   (7U)
/*! RICTR - Reset Instruction Counter
 *  0b0..Do not reset
 *  0b1..Clear
 */
#define SYSPM_PMCR_RICTR(x)                      (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_RICTR_SHIFT)) & SYSPM_PMCR_RICTR_MASK)

#define SYSPM_PMCR_RECTR1_MASK                   (0x100U)
#define SYSPM_PMCR_RECTR1_SHIFT                  (8U)
/*! RECTR1 - Reset Event Counter 1
 *  0b0..Run normally
 *  0b1..Reset
 */
#define SYSPM_PMCR_RECTR1(x)                     (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_RECTR1_SHIFT)) & SYSPM_PMCR_RECTR1_MASK)

#define SYSPM_PMCR_RECTR2_MASK                   (0x200U)
#define SYSPM_PMCR_RECTR2_SHIFT                  (9U)
/*! RECTR2 - Reset Event Counter 2
 *  0b0..Run normally
 *  0b1..Reset
 */
#define SYSPM_PMCR_RECTR2(x)                     (((uint32_t)(((uint32_t)(x)) << SYSPM_PMCR_RECTR2_SHIFT)) & SYSPM_PMCR_RECTR2_MASK)

#define SYSPM_PMCR_RECTR3_MASK                   (0x400U)
#define SYSPM_PMCR_RECTR3_SHIFT                  (10U)
/*! RECTR3 - Reset Event Counter 3
 *  0b0..Run normally
 *  0b1..Reset
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

/*! @name PMICTR_HI - Performance Monitor Instruction Counter */
/*! @{ */

#define SYSPM_PMICTR_HI_ICTR_MASK                (0xFFU)
#define SYSPM_PMICTR_HI_ICTR_SHIFT               (0U)
/*! ICTR - Instruction Counter */
#define SYSPM_PMICTR_HI_ICTR(x)                  (((uint8_t)(((uint8_t)(x)) << SYSPM_PMICTR_HI_ICTR_SHIFT)) & SYSPM_PMICTR_HI_ICTR_MASK)
/*! @} */

/* The count of SYSPM_PMICTR_HI */
#define SYSPM_PMICTR_HI_COUNT                    (2U)

/*! @name PMICTR_LO - Performance Monitor Instruction Counter */
/*! @{ */

#define SYSPM_PMICTR_LO_ICTR_MASK                (0xFFFFFFFFU)
#define SYSPM_PMICTR_LO_ICTR_SHIFT               (0U)
/*! ICTR - Instruction Counter */
#define SYSPM_PMICTR_LO_ICTR(x)                  (((uint32_t)(((uint32_t)(x)) << SYSPM_PMICTR_LO_ICTR_SHIFT)) & SYSPM_PMICTR_LO_ICTR_MASK)
/*! @} */

/* The count of SYSPM_PMICTR_LO */
#define SYSPM_PMICTR_LO_COUNT                    (2U)

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
