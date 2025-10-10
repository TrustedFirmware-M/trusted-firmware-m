/*
** ###################################################################
**     Processors:          MCXN247VAB
**                          MCXN247VDF
**                          MCXN247VKL
**                          MCXN247VPB
**                          MCXN526VDF_cm33_core0
**                          MCXN526VDF_cm33_core1
**                          MCXN526VKL_cm33_core0
**                          MCXN526VKL_cm33_core1
**                          MCXN527VAB_cm33_core0
**                          MCXN527VAB_cm33_core1
**                          MCXN527VDF_cm33_core0
**                          MCXN527VDF_cm33_core1
**                          MCXN527VKL_cm33_core0
**                          MCXN527VKL_cm33_core1
**                          MCXN536VAB_cm33_core0
**                          MCXN536VAB_cm33_core1
**                          MCXN536VDF_cm33_core0
**                          MCXN536VDF_cm33_core1
**                          MCXN536VKL_cm33_core0
**                          MCXN536VKL_cm33_core1
**                          MCXN536VPB_cm33_core0
**                          MCXN536VPB_cm33_core1
**                          MCXN537VAB_cm33_core0
**                          MCXN537VAB_cm33_core1
**                          MCXN537VDF_cm33_core0
**                          MCXN537VDF_cm33_core1
**                          MCXN537VKL_cm33_core0
**                          MCXN537VKL_cm33_core1
**                          MCXN537VPB_cm33_core0
**                          MCXN537VPB_cm33_core1
**                          MCXN546VAB_cm33_core0
**                          MCXN546VAB_cm33_core1
**                          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VAB_cm33_core0
**                          MCXN547VAB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN556SCDF_cm33_core0
**                          MCXN556SCDF_cm33_core1
**                          MCXN946VAB_cm33_core0
**                          MCXN946VAB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VAB_cm33_core0
**                          MCXN947VAB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250811
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPIO.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPIO
 *
 * CMSIS Peripheral Access Layer for GPIO
 */

#if !defined(PERI_GPIO_H_)
#define PERI_GPIO_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN247VAB) || defined(CPU_MCXN247VDF) || defined(CPU_MCXN247VKL) || defined(CPU_MCXN247VPB))
#include "MCXN247_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core0) || defined(CPU_MCXN526VKL_cm33_core0))
#include "MCXN526_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core1) || defined(CPU_MCXN526VKL_cm33_core1))
#include "MCXN526_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core0) || defined(CPU_MCXN527VDF_cm33_core0) || defined(CPU_MCXN527VKL_cm33_core0))
#include "MCXN527_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core1) || defined(CPU_MCXN527VDF_cm33_core1) || defined(CPU_MCXN527VKL_cm33_core1))
#include "MCXN527_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core0) || defined(CPU_MCXN536VDF_cm33_core0) || defined(CPU_MCXN536VKL_cm33_core0) || defined(CPU_MCXN536VPB_cm33_core0))
#include "MCXN536_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core1) || defined(CPU_MCXN536VDF_cm33_core1) || defined(CPU_MCXN536VKL_cm33_core1) || defined(CPU_MCXN536VPB_cm33_core1))
#include "MCXN536_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core0) || defined(CPU_MCXN537VDF_cm33_core0) || defined(CPU_MCXN537VKL_cm33_core0) || defined(CPU_MCXN537VPB_cm33_core0))
#include "MCXN537_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core1) || defined(CPU_MCXN537VDF_cm33_core1) || defined(CPU_MCXN537VKL_cm33_core1) || defined(CPU_MCXN537VPB_cm33_core1))
#include "MCXN537_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core0) || defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core1) || defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core0) || defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core1) || defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core0))
#include "MCXN556S_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core1))
#include "MCXN556S_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core0) || defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core1) || defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core0) || defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core1) || defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
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
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Size of Registers Arrays */
#define GPIO_PDR_COUNT                            32u
#define GPIO_ICR_COUNT                            32u
#define GPIO_ISFR_COUNT                           2u

/** GPIO - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t LOCK;                              /**< Lock, offset: 0xC */
  __IO uint32_t PCNS;                              /**< Pin Control Nonsecure, offset: 0x10 */
  __IO uint32_t ICNS;                              /**< Interrupt Control Nonsecure, offset: 0x14 */
  __IO uint32_t PCNP;                              /**< Pin Control Nonprivilege, offset: 0x18 */
  __IO uint32_t ICNP;                              /**< Interrupt Control Nonprivilege, offset: 0x1C */
       uint8_t RESERVED_1[32];
  __IO uint32_t PDOR;                              /**< Port Data Output, offset: 0x40 */
  __IO uint32_t PSOR;                              /**< Port Set Output, offset: 0x44 */
  __IO uint32_t PCOR;                              /**< Port Clear Output, offset: 0x48 */
  __IO uint32_t PTOR;                              /**< Port Toggle Output, offset: 0x4C */
  __I  uint32_t PDIR;                              /**< Port Data Input, offset: 0x50 */
  __IO uint32_t PDDR;                              /**< Port Data Direction, offset: 0x54 */
  __IO uint32_t PIDR;                              /**< Port Input Disable, offset: 0x58 */
       uint8_t RESERVED_2[4];
  __IO uint8_t PDR[GPIO_PDR_COUNT];                /**< Pin Data, array offset: 0x60, array step: 0x1 */
  __IO uint32_t ICR[GPIO_ICR_COUNT];               /**< Interrupt Control 0..Interrupt Control 31, array offset: 0x80, array step: 0x4 */
  __IO uint32_t GICLR;                             /**< Global Interrupt Control Low, offset: 0x100 */
  __IO uint32_t GICHR;                             /**< Global Interrupt Control High, offset: 0x104 */
       uint8_t RESERVED_3[24];
  __IO uint32_t ISFR[GPIO_ISFR_COUNT];             /**< Interrupt Status Flag, array offset: 0x120, array step: 0x4 */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define GPIO_VERID_FEATURE_MASK                  (0xFFFFU)
#define GPIO_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Basic implementation
 *  0b0000000000000001..Protection registers implemented
 */
#define GPIO_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << GPIO_VERID_FEATURE_SHIFT)) & GPIO_VERID_FEATURE_MASK)

#define GPIO_VERID_MINOR_MASK                    (0xFF0000U)
#define GPIO_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define GPIO_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_VERID_MINOR_SHIFT)) & GPIO_VERID_MINOR_MASK)

#define GPIO_VERID_MAJOR_MASK                    (0xFF000000U)
#define GPIO_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define GPIO_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_VERID_MAJOR_SHIFT)) & GPIO_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define GPIO_PARAM_IRQNUM_MASK                   (0xFU)
#define GPIO_PARAM_IRQNUM_SHIFT                  (0U)
/*! IRQNUM - Interrupt Number */
#define GPIO_PARAM_IRQNUM(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_PARAM_IRQNUM_SHIFT)) & GPIO_PARAM_IRQNUM_MASK)
/*! @} */

/*! @name LOCK - Lock */
/*! @{ */

#define GPIO_LOCK_PCNS_MASK                      (0x1U)
#define GPIO_LOCK_PCNS_SHIFT                     (0U)
/*! PCNS - Lock PCNS
 *  0b0..Writable in Secure-Privilege state
 *  0b1..Not writable until the next reset
 */
#define GPIO_LOCK_PCNS(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_LOCK_PCNS_SHIFT)) & GPIO_LOCK_PCNS_MASK)

#define GPIO_LOCK_ICNS_MASK                      (0x2U)
#define GPIO_LOCK_ICNS_SHIFT                     (1U)
/*! ICNS - Lock ICNS
 *  0b0..Writable in Secure-Privilege state
 *  0b1..Not writable until the next reset
 */
#define GPIO_LOCK_ICNS(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_LOCK_ICNS_SHIFT)) & GPIO_LOCK_ICNS_MASK)

#define GPIO_LOCK_PCNP_MASK                      (0x4U)
#define GPIO_LOCK_PCNP_SHIFT                     (2U)
/*! PCNP - Lock PCNP
 *  0b0..Writable in Secure-Privilege state
 *  0b1..Not writable until the next reset
 */
#define GPIO_LOCK_PCNP(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_LOCK_PCNP_SHIFT)) & GPIO_LOCK_PCNP_MASK)

#define GPIO_LOCK_ICNP_MASK                      (0x8U)
#define GPIO_LOCK_ICNP_SHIFT                     (3U)
/*! ICNP - Lock ICNP
 *  0b0..Writable in Secure-Privilege state
 *  0b1..Not writable until the next reset
 */
#define GPIO_LOCK_ICNP(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_LOCK_ICNP_SHIFT)) & GPIO_LOCK_ICNP_MASK)
/*! @} */

/*! @name PCNS - Pin Control Nonsecure */
/*! @{ */

#define GPIO_PCNS_NSE0_MASK                      (0x1U)
#define GPIO_PCNS_NSE0_SHIFT                     (0U)
/*! NSE0 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE0_SHIFT)) & GPIO_PCNS_NSE0_MASK)

#define GPIO_PCNS_NSE1_MASK                      (0x2U)
#define GPIO_PCNS_NSE1_SHIFT                     (1U)
/*! NSE1 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE1_SHIFT)) & GPIO_PCNS_NSE1_MASK)

#define GPIO_PCNS_NSE2_MASK                      (0x4U)
#define GPIO_PCNS_NSE2_SHIFT                     (2U)
/*! NSE2 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE2_SHIFT)) & GPIO_PCNS_NSE2_MASK)

#define GPIO_PCNS_NSE3_MASK                      (0x8U)
#define GPIO_PCNS_NSE3_SHIFT                     (3U)
/*! NSE3 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE3_SHIFT)) & GPIO_PCNS_NSE3_MASK)

#define GPIO_PCNS_NSE4_MASK                      (0x10U)
#define GPIO_PCNS_NSE4_SHIFT                     (4U)
/*! NSE4 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE4_SHIFT)) & GPIO_PCNS_NSE4_MASK)

#define GPIO_PCNS_NSE5_MASK                      (0x20U)
#define GPIO_PCNS_NSE5_SHIFT                     (5U)
/*! NSE5 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE5_SHIFT)) & GPIO_PCNS_NSE5_MASK)

#define GPIO_PCNS_NSE6_MASK                      (0x40U)
#define GPIO_PCNS_NSE6_SHIFT                     (6U)
/*! NSE6 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE6_SHIFT)) & GPIO_PCNS_NSE6_MASK)

#define GPIO_PCNS_NSE7_MASK                      (0x80U)
#define GPIO_PCNS_NSE7_SHIFT                     (7U)
/*! NSE7 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE7_SHIFT)) & GPIO_PCNS_NSE7_MASK)

#define GPIO_PCNS_NSE8_MASK                      (0x100U)
#define GPIO_PCNS_NSE8_SHIFT                     (8U)
/*! NSE8 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE8_SHIFT)) & GPIO_PCNS_NSE8_MASK)

#define GPIO_PCNS_NSE9_MASK                      (0x200U)
#define GPIO_PCNS_NSE9_SHIFT                     (9U)
/*! NSE9 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE9_SHIFT)) & GPIO_PCNS_NSE9_MASK)

#define GPIO_PCNS_NSE10_MASK                     (0x400U)
#define GPIO_PCNS_NSE10_SHIFT                    (10U)
/*! NSE10 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE10_SHIFT)) & GPIO_PCNS_NSE10_MASK)

#define GPIO_PCNS_NSE11_MASK                     (0x800U)
#define GPIO_PCNS_NSE11_SHIFT                    (11U)
/*! NSE11 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE11_SHIFT)) & GPIO_PCNS_NSE11_MASK)

#define GPIO_PCNS_NSE12_MASK                     (0x1000U)
#define GPIO_PCNS_NSE12_SHIFT                    (12U)
/*! NSE12 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE12_SHIFT)) & GPIO_PCNS_NSE12_MASK)

#define GPIO_PCNS_NSE13_MASK                     (0x2000U)
#define GPIO_PCNS_NSE13_SHIFT                    (13U)
/*! NSE13 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE13_SHIFT)) & GPIO_PCNS_NSE13_MASK)

#define GPIO_PCNS_NSE14_MASK                     (0x4000U)
#define GPIO_PCNS_NSE14_SHIFT                    (14U)
/*! NSE14 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE14_SHIFT)) & GPIO_PCNS_NSE14_MASK)

#define GPIO_PCNS_NSE15_MASK                     (0x8000U)
#define GPIO_PCNS_NSE15_SHIFT                    (15U)
/*! NSE15 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE15_SHIFT)) & GPIO_PCNS_NSE15_MASK)

#define GPIO_PCNS_NSE16_MASK                     (0x10000U)
#define GPIO_PCNS_NSE16_SHIFT                    (16U)
/*! NSE16 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE16_SHIFT)) & GPIO_PCNS_NSE16_MASK)

#define GPIO_PCNS_NSE17_MASK                     (0x20000U)
#define GPIO_PCNS_NSE17_SHIFT                    (17U)
/*! NSE17 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE17_SHIFT)) & GPIO_PCNS_NSE17_MASK)

#define GPIO_PCNS_NSE18_MASK                     (0x40000U)
#define GPIO_PCNS_NSE18_SHIFT                    (18U)
/*! NSE18 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE18_SHIFT)) & GPIO_PCNS_NSE18_MASK)

#define GPIO_PCNS_NSE19_MASK                     (0x80000U)
#define GPIO_PCNS_NSE19_SHIFT                    (19U)
/*! NSE19 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE19_SHIFT)) & GPIO_PCNS_NSE19_MASK)

#define GPIO_PCNS_NSE20_MASK                     (0x100000U)
#define GPIO_PCNS_NSE20_SHIFT                    (20U)
/*! NSE20 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE20_SHIFT)) & GPIO_PCNS_NSE20_MASK)

#define GPIO_PCNS_NSE21_MASK                     (0x200000U)
#define GPIO_PCNS_NSE21_SHIFT                    (21U)
/*! NSE21 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE21_SHIFT)) & GPIO_PCNS_NSE21_MASK)

#define GPIO_PCNS_NSE22_MASK                     (0x400000U)
#define GPIO_PCNS_NSE22_SHIFT                    (22U)
/*! NSE22 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE22_SHIFT)) & GPIO_PCNS_NSE22_MASK)

#define GPIO_PCNS_NSE23_MASK                     (0x800000U)
#define GPIO_PCNS_NSE23_SHIFT                    (23U)
/*! NSE23 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE23_SHIFT)) & GPIO_PCNS_NSE23_MASK)

#define GPIO_PCNS_NSE24_MASK                     (0x1000000U)
#define GPIO_PCNS_NSE24_SHIFT                    (24U)
/*! NSE24 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE24_SHIFT)) & GPIO_PCNS_NSE24_MASK)

#define GPIO_PCNS_NSE25_MASK                     (0x2000000U)
#define GPIO_PCNS_NSE25_SHIFT                    (25U)
/*! NSE25 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE25_SHIFT)) & GPIO_PCNS_NSE25_MASK)

#define GPIO_PCNS_NSE26_MASK                     (0x4000000U)
#define GPIO_PCNS_NSE26_SHIFT                    (26U)
/*! NSE26 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE26_SHIFT)) & GPIO_PCNS_NSE26_MASK)

#define GPIO_PCNS_NSE27_MASK                     (0x8000000U)
#define GPIO_PCNS_NSE27_SHIFT                    (27U)
/*! NSE27 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE27_SHIFT)) & GPIO_PCNS_NSE27_MASK)

#define GPIO_PCNS_NSE28_MASK                     (0x10000000U)
#define GPIO_PCNS_NSE28_SHIFT                    (28U)
/*! NSE28 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE28_SHIFT)) & GPIO_PCNS_NSE28_MASK)

#define GPIO_PCNS_NSE29_MASK                     (0x20000000U)
#define GPIO_PCNS_NSE29_SHIFT                    (29U)
/*! NSE29 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE29_SHIFT)) & GPIO_PCNS_NSE29_MASK)

#define GPIO_PCNS_NSE30_MASK                     (0x40000000U)
#define GPIO_PCNS_NSE30_SHIFT                    (30U)
/*! NSE30 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE30_SHIFT)) & GPIO_PCNS_NSE30_MASK)

#define GPIO_PCNS_NSE31_MASK                     (0x80000000U)
#define GPIO_PCNS_NSE31_SHIFT                    (31U)
/*! NSE31 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_PCNS_NSE31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNS_NSE31_SHIFT)) & GPIO_PCNS_NSE31_MASK)
/*! @} */

/*! @name ICNS - Interrupt Control Nonsecure */
/*! @{ */

#define GPIO_ICNS_NSE0_MASK                      (0x1U)
#define GPIO_ICNS_NSE0_SHIFT                     (0U)
/*! NSE0 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_ICNS_NSE0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICNS_NSE0_SHIFT)) & GPIO_ICNS_NSE0_MASK)

#define GPIO_ICNS_NSE1_MASK                      (0x2U)
#define GPIO_ICNS_NSE1_SHIFT                     (1U)
/*! NSE1 - Nonsecure Enable
 *  0b0..Secure access
 *  0b1..Nonsecure access
 */
#define GPIO_ICNS_NSE1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICNS_NSE1_SHIFT)) & GPIO_ICNS_NSE1_MASK)
/*! @} */

/*! @name PCNP - Pin Control Nonprivilege */
/*! @{ */

#define GPIO_PCNP_NPE0_MASK                      (0x1U)
#define GPIO_PCNP_NPE0_SHIFT                     (0U)
/*! NPE0 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE0_SHIFT)) & GPIO_PCNP_NPE0_MASK)

#define GPIO_PCNP_NPE1_MASK                      (0x2U)
#define GPIO_PCNP_NPE1_SHIFT                     (1U)
/*! NPE1 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE1_SHIFT)) & GPIO_PCNP_NPE1_MASK)

#define GPIO_PCNP_NPE2_MASK                      (0x4U)
#define GPIO_PCNP_NPE2_SHIFT                     (2U)
/*! NPE2 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE2_SHIFT)) & GPIO_PCNP_NPE2_MASK)

#define GPIO_PCNP_NPE3_MASK                      (0x8U)
#define GPIO_PCNP_NPE3_SHIFT                     (3U)
/*! NPE3 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE3_SHIFT)) & GPIO_PCNP_NPE3_MASK)

#define GPIO_PCNP_NPE4_MASK                      (0x10U)
#define GPIO_PCNP_NPE4_SHIFT                     (4U)
/*! NPE4 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE4_SHIFT)) & GPIO_PCNP_NPE4_MASK)

#define GPIO_PCNP_NPE5_MASK                      (0x20U)
#define GPIO_PCNP_NPE5_SHIFT                     (5U)
/*! NPE5 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE5_SHIFT)) & GPIO_PCNP_NPE5_MASK)

#define GPIO_PCNP_NPE6_MASK                      (0x40U)
#define GPIO_PCNP_NPE6_SHIFT                     (6U)
/*! NPE6 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE6_SHIFT)) & GPIO_PCNP_NPE6_MASK)

#define GPIO_PCNP_NPE7_MASK                      (0x80U)
#define GPIO_PCNP_NPE7_SHIFT                     (7U)
/*! NPE7 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE7_SHIFT)) & GPIO_PCNP_NPE7_MASK)

#define GPIO_PCNP_NPE8_MASK                      (0x100U)
#define GPIO_PCNP_NPE8_SHIFT                     (8U)
/*! NPE8 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE8_SHIFT)) & GPIO_PCNP_NPE8_MASK)

#define GPIO_PCNP_NPE9_MASK                      (0x200U)
#define GPIO_PCNP_NPE9_SHIFT                     (9U)
/*! NPE9 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE9_SHIFT)) & GPIO_PCNP_NPE9_MASK)

#define GPIO_PCNP_NPE10_MASK                     (0x400U)
#define GPIO_PCNP_NPE10_SHIFT                    (10U)
/*! NPE10 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE10_SHIFT)) & GPIO_PCNP_NPE10_MASK)

#define GPIO_PCNP_NPE11_MASK                     (0x800U)
#define GPIO_PCNP_NPE11_SHIFT                    (11U)
/*! NPE11 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE11_SHIFT)) & GPIO_PCNP_NPE11_MASK)

#define GPIO_PCNP_NPE12_MASK                     (0x1000U)
#define GPIO_PCNP_NPE12_SHIFT                    (12U)
/*! NPE12 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE12_SHIFT)) & GPIO_PCNP_NPE12_MASK)

#define GPIO_PCNP_NPE13_MASK                     (0x2000U)
#define GPIO_PCNP_NPE13_SHIFT                    (13U)
/*! NPE13 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE13_SHIFT)) & GPIO_PCNP_NPE13_MASK)

#define GPIO_PCNP_NPE14_MASK                     (0x4000U)
#define GPIO_PCNP_NPE14_SHIFT                    (14U)
/*! NPE14 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE14_SHIFT)) & GPIO_PCNP_NPE14_MASK)

#define GPIO_PCNP_NPE15_MASK                     (0x8000U)
#define GPIO_PCNP_NPE15_SHIFT                    (15U)
/*! NPE15 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE15_SHIFT)) & GPIO_PCNP_NPE15_MASK)

#define GPIO_PCNP_NPE16_MASK                     (0x10000U)
#define GPIO_PCNP_NPE16_SHIFT                    (16U)
/*! NPE16 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE16_SHIFT)) & GPIO_PCNP_NPE16_MASK)

#define GPIO_PCNP_NPE17_MASK                     (0x20000U)
#define GPIO_PCNP_NPE17_SHIFT                    (17U)
/*! NPE17 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE17_SHIFT)) & GPIO_PCNP_NPE17_MASK)

#define GPIO_PCNP_NPE18_MASK                     (0x40000U)
#define GPIO_PCNP_NPE18_SHIFT                    (18U)
/*! NPE18 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE18_SHIFT)) & GPIO_PCNP_NPE18_MASK)

#define GPIO_PCNP_NPE19_MASK                     (0x80000U)
#define GPIO_PCNP_NPE19_SHIFT                    (19U)
/*! NPE19 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE19_SHIFT)) & GPIO_PCNP_NPE19_MASK)

#define GPIO_PCNP_NPE20_MASK                     (0x100000U)
#define GPIO_PCNP_NPE20_SHIFT                    (20U)
/*! NPE20 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE20_SHIFT)) & GPIO_PCNP_NPE20_MASK)

#define GPIO_PCNP_NPE21_MASK                     (0x200000U)
#define GPIO_PCNP_NPE21_SHIFT                    (21U)
/*! NPE21 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE21_SHIFT)) & GPIO_PCNP_NPE21_MASK)

#define GPIO_PCNP_NPE22_MASK                     (0x400000U)
#define GPIO_PCNP_NPE22_SHIFT                    (22U)
/*! NPE22 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE22_SHIFT)) & GPIO_PCNP_NPE22_MASK)

#define GPIO_PCNP_NPE23_MASK                     (0x800000U)
#define GPIO_PCNP_NPE23_SHIFT                    (23U)
/*! NPE23 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE23_SHIFT)) & GPIO_PCNP_NPE23_MASK)

#define GPIO_PCNP_NPE24_MASK                     (0x1000000U)
#define GPIO_PCNP_NPE24_SHIFT                    (24U)
/*! NPE24 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE24_SHIFT)) & GPIO_PCNP_NPE24_MASK)

#define GPIO_PCNP_NPE25_MASK                     (0x2000000U)
#define GPIO_PCNP_NPE25_SHIFT                    (25U)
/*! NPE25 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE25_SHIFT)) & GPIO_PCNP_NPE25_MASK)

#define GPIO_PCNP_NPE26_MASK                     (0x4000000U)
#define GPIO_PCNP_NPE26_SHIFT                    (26U)
/*! NPE26 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE26_SHIFT)) & GPIO_PCNP_NPE26_MASK)

#define GPIO_PCNP_NPE27_MASK                     (0x8000000U)
#define GPIO_PCNP_NPE27_SHIFT                    (27U)
/*! NPE27 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE27_SHIFT)) & GPIO_PCNP_NPE27_MASK)

#define GPIO_PCNP_NPE28_MASK                     (0x10000000U)
#define GPIO_PCNP_NPE28_SHIFT                    (28U)
/*! NPE28 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE28_SHIFT)) & GPIO_PCNP_NPE28_MASK)

#define GPIO_PCNP_NPE29_MASK                     (0x20000000U)
#define GPIO_PCNP_NPE29_SHIFT                    (29U)
/*! NPE29 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE29_SHIFT)) & GPIO_PCNP_NPE29_MASK)

#define GPIO_PCNP_NPE30_MASK                     (0x40000000U)
#define GPIO_PCNP_NPE30_SHIFT                    (30U)
/*! NPE30 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE30_SHIFT)) & GPIO_PCNP_NPE30_MASK)

#define GPIO_PCNP_NPE31_MASK                     (0x80000000U)
#define GPIO_PCNP_NPE31_SHIFT                    (31U)
/*! NPE31 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_PCNP_NPE31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCNP_NPE31_SHIFT)) & GPIO_PCNP_NPE31_MASK)
/*! @} */

/*! @name ICNP - Interrupt Control Nonprivilege */
/*! @{ */

#define GPIO_ICNP_NPE0_MASK                      (0x1U)
#define GPIO_ICNP_NPE0_SHIFT                     (0U)
/*! NPE0 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_ICNP_NPE0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICNP_NPE0_SHIFT)) & GPIO_ICNP_NPE0_MASK)

#define GPIO_ICNP_NPE1_MASK                      (0x2U)
#define GPIO_ICNP_NPE1_SHIFT                     (1U)
/*! NPE1 - Nonprivilege Enable
 *  0b0..Privilege access
 *  0b1..Nonprivilege access
 */
#define GPIO_ICNP_NPE1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICNP_NPE1_SHIFT)) & GPIO_ICNP_NPE1_MASK)
/*! @} */

/*! @name PDOR - Port Data Output */
/*! @{ */

#define GPIO_PDOR_PDO0_MASK                      (0x1U)
#define GPIO_PDOR_PDO0_SHIFT                     (0U)
/*! PDO0 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO0_SHIFT)) & GPIO_PDOR_PDO0_MASK)

#define GPIO_PDOR_PDO1_MASK                      (0x2U)
#define GPIO_PDOR_PDO1_SHIFT                     (1U)
/*! PDO1 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO1_SHIFT)) & GPIO_PDOR_PDO1_MASK)

#define GPIO_PDOR_PDO2_MASK                      (0x4U)
#define GPIO_PDOR_PDO2_SHIFT                     (2U)
/*! PDO2 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO2_SHIFT)) & GPIO_PDOR_PDO2_MASK)

#define GPIO_PDOR_PDO3_MASK                      (0x8U)
#define GPIO_PDOR_PDO3_SHIFT                     (3U)
/*! PDO3 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO3_SHIFT)) & GPIO_PDOR_PDO3_MASK)

#define GPIO_PDOR_PDO4_MASK                      (0x10U)
#define GPIO_PDOR_PDO4_SHIFT                     (4U)
/*! PDO4 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO4_SHIFT)) & GPIO_PDOR_PDO4_MASK)

#define GPIO_PDOR_PDO5_MASK                      (0x20U)
#define GPIO_PDOR_PDO5_SHIFT                     (5U)
/*! PDO5 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO5_SHIFT)) & GPIO_PDOR_PDO5_MASK)

#define GPIO_PDOR_PDO6_MASK                      (0x40U)
#define GPIO_PDOR_PDO6_SHIFT                     (6U)
/*! PDO6 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO6_SHIFT)) & GPIO_PDOR_PDO6_MASK)

#define GPIO_PDOR_PDO7_MASK                      (0x80U)
#define GPIO_PDOR_PDO7_SHIFT                     (7U)
/*! PDO7 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO7_SHIFT)) & GPIO_PDOR_PDO7_MASK)

#define GPIO_PDOR_PDO8_MASK                      (0x100U)
#define GPIO_PDOR_PDO8_SHIFT                     (8U)
/*! PDO8 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO8_SHIFT)) & GPIO_PDOR_PDO8_MASK)

#define GPIO_PDOR_PDO9_MASK                      (0x200U)
#define GPIO_PDOR_PDO9_SHIFT                     (9U)
/*! PDO9 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO9_SHIFT)) & GPIO_PDOR_PDO9_MASK)

#define GPIO_PDOR_PDO10_MASK                     (0x400U)
#define GPIO_PDOR_PDO10_SHIFT                    (10U)
/*! PDO10 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO10_SHIFT)) & GPIO_PDOR_PDO10_MASK)

#define GPIO_PDOR_PDO11_MASK                     (0x800U)
#define GPIO_PDOR_PDO11_SHIFT                    (11U)
/*! PDO11 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO11_SHIFT)) & GPIO_PDOR_PDO11_MASK)

#define GPIO_PDOR_PDO12_MASK                     (0x1000U)
#define GPIO_PDOR_PDO12_SHIFT                    (12U)
/*! PDO12 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO12_SHIFT)) & GPIO_PDOR_PDO12_MASK)

#define GPIO_PDOR_PDO13_MASK                     (0x2000U)
#define GPIO_PDOR_PDO13_SHIFT                    (13U)
/*! PDO13 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO13_SHIFT)) & GPIO_PDOR_PDO13_MASK)

#define GPIO_PDOR_PDO14_MASK                     (0x4000U)
#define GPIO_PDOR_PDO14_SHIFT                    (14U)
/*! PDO14 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO14_SHIFT)) & GPIO_PDOR_PDO14_MASK)

#define GPIO_PDOR_PDO15_MASK                     (0x8000U)
#define GPIO_PDOR_PDO15_SHIFT                    (15U)
/*! PDO15 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO15_SHIFT)) & GPIO_PDOR_PDO15_MASK)

#define GPIO_PDOR_PDO16_MASK                     (0x10000U)
#define GPIO_PDOR_PDO16_SHIFT                    (16U)
/*! PDO16 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO16_SHIFT)) & GPIO_PDOR_PDO16_MASK)

#define GPIO_PDOR_PDO17_MASK                     (0x20000U)
#define GPIO_PDOR_PDO17_SHIFT                    (17U)
/*! PDO17 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO17_SHIFT)) & GPIO_PDOR_PDO17_MASK)

#define GPIO_PDOR_PDO18_MASK                     (0x40000U)
#define GPIO_PDOR_PDO18_SHIFT                    (18U)
/*! PDO18 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO18_SHIFT)) & GPIO_PDOR_PDO18_MASK)

#define GPIO_PDOR_PDO19_MASK                     (0x80000U)
#define GPIO_PDOR_PDO19_SHIFT                    (19U)
/*! PDO19 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO19_SHIFT)) & GPIO_PDOR_PDO19_MASK)

#define GPIO_PDOR_PDO20_MASK                     (0x100000U)
#define GPIO_PDOR_PDO20_SHIFT                    (20U)
/*! PDO20 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO20_SHIFT)) & GPIO_PDOR_PDO20_MASK)

#define GPIO_PDOR_PDO21_MASK                     (0x200000U)
#define GPIO_PDOR_PDO21_SHIFT                    (21U)
/*! PDO21 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO21_SHIFT)) & GPIO_PDOR_PDO21_MASK)

#define GPIO_PDOR_PDO22_MASK                     (0x400000U)
#define GPIO_PDOR_PDO22_SHIFT                    (22U)
/*! PDO22 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO22_SHIFT)) & GPIO_PDOR_PDO22_MASK)

#define GPIO_PDOR_PDO23_MASK                     (0x800000U)
#define GPIO_PDOR_PDO23_SHIFT                    (23U)
/*! PDO23 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO23_SHIFT)) & GPIO_PDOR_PDO23_MASK)

#define GPIO_PDOR_PDO24_MASK                     (0x1000000U)
#define GPIO_PDOR_PDO24_SHIFT                    (24U)
/*! PDO24 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO24_SHIFT)) & GPIO_PDOR_PDO24_MASK)

#define GPIO_PDOR_PDO25_MASK                     (0x2000000U)
#define GPIO_PDOR_PDO25_SHIFT                    (25U)
/*! PDO25 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO25_SHIFT)) & GPIO_PDOR_PDO25_MASK)

#define GPIO_PDOR_PDO26_MASK                     (0x4000000U)
#define GPIO_PDOR_PDO26_SHIFT                    (26U)
/*! PDO26 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO26_SHIFT)) & GPIO_PDOR_PDO26_MASK)

#define GPIO_PDOR_PDO27_MASK                     (0x8000000U)
#define GPIO_PDOR_PDO27_SHIFT                    (27U)
/*! PDO27 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO27_SHIFT)) & GPIO_PDOR_PDO27_MASK)

#define GPIO_PDOR_PDO28_MASK                     (0x10000000U)
#define GPIO_PDOR_PDO28_SHIFT                    (28U)
/*! PDO28 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO28_SHIFT)) & GPIO_PDOR_PDO28_MASK)

#define GPIO_PDOR_PDO29_MASK                     (0x20000000U)
#define GPIO_PDOR_PDO29_SHIFT                    (29U)
/*! PDO29 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO29_SHIFT)) & GPIO_PDOR_PDO29_MASK)

#define GPIO_PDOR_PDO30_MASK                     (0x40000000U)
#define GPIO_PDOR_PDO30_SHIFT                    (30U)
/*! PDO30 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO30_SHIFT)) & GPIO_PDOR_PDO30_MASK)

#define GPIO_PDOR_PDO31_MASK                     (0x80000000U)
#define GPIO_PDOR_PDO31_SHIFT                    (31U)
/*! PDO31 - Port Data Output
 *  0b0..Logic level 0
 *  0b1..Logic level 1
 */
#define GPIO_PDOR_PDO31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO31_SHIFT)) & GPIO_PDOR_PDO31_MASK)
/*! @} */

/*! @name PSOR - Port Set Output */
/*! @{ */

#define GPIO_PSOR_PTSO0_MASK                     (0x1U)
#define GPIO_PSOR_PTSO0_SHIFT                    (0U)
/*! PTSO0 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO0(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO0_SHIFT)) & GPIO_PSOR_PTSO0_MASK)

#define GPIO_PSOR_PTSO1_MASK                     (0x2U)
#define GPIO_PSOR_PTSO1_SHIFT                    (1U)
/*! PTSO1 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO1(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO1_SHIFT)) & GPIO_PSOR_PTSO1_MASK)

#define GPIO_PSOR_PTSO2_MASK                     (0x4U)
#define GPIO_PSOR_PTSO2_SHIFT                    (2U)
/*! PTSO2 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO2(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO2_SHIFT)) & GPIO_PSOR_PTSO2_MASK)

#define GPIO_PSOR_PTSO3_MASK                     (0x8U)
#define GPIO_PSOR_PTSO3_SHIFT                    (3U)
/*! PTSO3 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO3(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO3_SHIFT)) & GPIO_PSOR_PTSO3_MASK)

#define GPIO_PSOR_PTSO4_MASK                     (0x10U)
#define GPIO_PSOR_PTSO4_SHIFT                    (4U)
/*! PTSO4 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO4(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO4_SHIFT)) & GPIO_PSOR_PTSO4_MASK)

#define GPIO_PSOR_PTSO5_MASK                     (0x20U)
#define GPIO_PSOR_PTSO5_SHIFT                    (5U)
/*! PTSO5 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO5(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO5_SHIFT)) & GPIO_PSOR_PTSO5_MASK)

#define GPIO_PSOR_PTSO6_MASK                     (0x40U)
#define GPIO_PSOR_PTSO6_SHIFT                    (6U)
/*! PTSO6 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO6(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO6_SHIFT)) & GPIO_PSOR_PTSO6_MASK)

#define GPIO_PSOR_PTSO7_MASK                     (0x80U)
#define GPIO_PSOR_PTSO7_SHIFT                    (7U)
/*! PTSO7 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO7(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO7_SHIFT)) & GPIO_PSOR_PTSO7_MASK)

#define GPIO_PSOR_PTSO8_MASK                     (0x100U)
#define GPIO_PSOR_PTSO8_SHIFT                    (8U)
/*! PTSO8 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO8(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO8_SHIFT)) & GPIO_PSOR_PTSO8_MASK)

#define GPIO_PSOR_PTSO9_MASK                     (0x200U)
#define GPIO_PSOR_PTSO9_SHIFT                    (9U)
/*! PTSO9 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO9(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO9_SHIFT)) & GPIO_PSOR_PTSO9_MASK)

#define GPIO_PSOR_PTSO10_MASK                    (0x400U)
#define GPIO_PSOR_PTSO10_SHIFT                   (10U)
/*! PTSO10 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO10(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO10_SHIFT)) & GPIO_PSOR_PTSO10_MASK)

#define GPIO_PSOR_PTSO11_MASK                    (0x800U)
#define GPIO_PSOR_PTSO11_SHIFT                   (11U)
/*! PTSO11 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO11(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO11_SHIFT)) & GPIO_PSOR_PTSO11_MASK)

#define GPIO_PSOR_PTSO12_MASK                    (0x1000U)
#define GPIO_PSOR_PTSO12_SHIFT                   (12U)
/*! PTSO12 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO12(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO12_SHIFT)) & GPIO_PSOR_PTSO12_MASK)

#define GPIO_PSOR_PTSO13_MASK                    (0x2000U)
#define GPIO_PSOR_PTSO13_SHIFT                   (13U)
/*! PTSO13 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO13(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO13_SHIFT)) & GPIO_PSOR_PTSO13_MASK)

#define GPIO_PSOR_PTSO14_MASK                    (0x4000U)
#define GPIO_PSOR_PTSO14_SHIFT                   (14U)
/*! PTSO14 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO14(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO14_SHIFT)) & GPIO_PSOR_PTSO14_MASK)

#define GPIO_PSOR_PTSO15_MASK                    (0x8000U)
#define GPIO_PSOR_PTSO15_SHIFT                   (15U)
/*! PTSO15 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO15(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO15_SHIFT)) & GPIO_PSOR_PTSO15_MASK)

#define GPIO_PSOR_PTSO16_MASK                    (0x10000U)
#define GPIO_PSOR_PTSO16_SHIFT                   (16U)
/*! PTSO16 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO16(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO16_SHIFT)) & GPIO_PSOR_PTSO16_MASK)

#define GPIO_PSOR_PTSO17_MASK                    (0x20000U)
#define GPIO_PSOR_PTSO17_SHIFT                   (17U)
/*! PTSO17 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO17(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO17_SHIFT)) & GPIO_PSOR_PTSO17_MASK)

#define GPIO_PSOR_PTSO18_MASK                    (0x40000U)
#define GPIO_PSOR_PTSO18_SHIFT                   (18U)
/*! PTSO18 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO18(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO18_SHIFT)) & GPIO_PSOR_PTSO18_MASK)

#define GPIO_PSOR_PTSO19_MASK                    (0x80000U)
#define GPIO_PSOR_PTSO19_SHIFT                   (19U)
/*! PTSO19 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO19(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO19_SHIFT)) & GPIO_PSOR_PTSO19_MASK)

#define GPIO_PSOR_PTSO20_MASK                    (0x100000U)
#define GPIO_PSOR_PTSO20_SHIFT                   (20U)
/*! PTSO20 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO20(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO20_SHIFT)) & GPIO_PSOR_PTSO20_MASK)

#define GPIO_PSOR_PTSO21_MASK                    (0x200000U)
#define GPIO_PSOR_PTSO21_SHIFT                   (21U)
/*! PTSO21 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO21(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO21_SHIFT)) & GPIO_PSOR_PTSO21_MASK)

#define GPIO_PSOR_PTSO22_MASK                    (0x400000U)
#define GPIO_PSOR_PTSO22_SHIFT                   (22U)
/*! PTSO22 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO22(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO22_SHIFT)) & GPIO_PSOR_PTSO22_MASK)

#define GPIO_PSOR_PTSO23_MASK                    (0x800000U)
#define GPIO_PSOR_PTSO23_SHIFT                   (23U)
/*! PTSO23 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO23(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO23_SHIFT)) & GPIO_PSOR_PTSO23_MASK)

#define GPIO_PSOR_PTSO24_MASK                    (0x1000000U)
#define GPIO_PSOR_PTSO24_SHIFT                   (24U)
/*! PTSO24 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO24(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO24_SHIFT)) & GPIO_PSOR_PTSO24_MASK)

#define GPIO_PSOR_PTSO25_MASK                    (0x2000000U)
#define GPIO_PSOR_PTSO25_SHIFT                   (25U)
/*! PTSO25 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO25(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO25_SHIFT)) & GPIO_PSOR_PTSO25_MASK)

#define GPIO_PSOR_PTSO26_MASK                    (0x4000000U)
#define GPIO_PSOR_PTSO26_SHIFT                   (26U)
/*! PTSO26 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO26(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO26_SHIFT)) & GPIO_PSOR_PTSO26_MASK)

#define GPIO_PSOR_PTSO27_MASK                    (0x8000000U)
#define GPIO_PSOR_PTSO27_SHIFT                   (27U)
/*! PTSO27 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO27(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO27_SHIFT)) & GPIO_PSOR_PTSO27_MASK)

#define GPIO_PSOR_PTSO28_MASK                    (0x10000000U)
#define GPIO_PSOR_PTSO28_SHIFT                   (28U)
/*! PTSO28 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO28(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO28_SHIFT)) & GPIO_PSOR_PTSO28_MASK)

#define GPIO_PSOR_PTSO29_MASK                    (0x20000000U)
#define GPIO_PSOR_PTSO29_SHIFT                   (29U)
/*! PTSO29 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO29(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO29_SHIFT)) & GPIO_PSOR_PTSO29_MASK)

#define GPIO_PSOR_PTSO30_MASK                    (0x40000000U)
#define GPIO_PSOR_PTSO30_SHIFT                   (30U)
/*! PTSO30 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO30(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO30_SHIFT)) & GPIO_PSOR_PTSO30_MASK)

#define GPIO_PSOR_PTSO31_MASK                    (0x80000000U)
#define GPIO_PSOR_PTSO31_SHIFT                   (31U)
/*! PTSO31 - Port Set Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 1
 */
#define GPIO_PSOR_PTSO31(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO31_SHIFT)) & GPIO_PSOR_PTSO31_MASK)
/*! @} */

/*! @name PCOR - Port Clear Output */
/*! @{ */

#define GPIO_PCOR_PTCO0_MASK                     (0x1U)
#define GPIO_PCOR_PTCO0_SHIFT                    (0U)
/*! PTCO0 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO0(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO0_SHIFT)) & GPIO_PCOR_PTCO0_MASK)

#define GPIO_PCOR_PTCO1_MASK                     (0x2U)
#define GPIO_PCOR_PTCO1_SHIFT                    (1U)
/*! PTCO1 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO1(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO1_SHIFT)) & GPIO_PCOR_PTCO1_MASK)

#define GPIO_PCOR_PTCO2_MASK                     (0x4U)
#define GPIO_PCOR_PTCO2_SHIFT                    (2U)
/*! PTCO2 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO2(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO2_SHIFT)) & GPIO_PCOR_PTCO2_MASK)

#define GPIO_PCOR_PTCO3_MASK                     (0x8U)
#define GPIO_PCOR_PTCO3_SHIFT                    (3U)
/*! PTCO3 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO3(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO3_SHIFT)) & GPIO_PCOR_PTCO3_MASK)

#define GPIO_PCOR_PTCO4_MASK                     (0x10U)
#define GPIO_PCOR_PTCO4_SHIFT                    (4U)
/*! PTCO4 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO4(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO4_SHIFT)) & GPIO_PCOR_PTCO4_MASK)

#define GPIO_PCOR_PTCO5_MASK                     (0x20U)
#define GPIO_PCOR_PTCO5_SHIFT                    (5U)
/*! PTCO5 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO5(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO5_SHIFT)) & GPIO_PCOR_PTCO5_MASK)

#define GPIO_PCOR_PTCO6_MASK                     (0x40U)
#define GPIO_PCOR_PTCO6_SHIFT                    (6U)
/*! PTCO6 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO6(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO6_SHIFT)) & GPIO_PCOR_PTCO6_MASK)

#define GPIO_PCOR_PTCO7_MASK                     (0x80U)
#define GPIO_PCOR_PTCO7_SHIFT                    (7U)
/*! PTCO7 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO7(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO7_SHIFT)) & GPIO_PCOR_PTCO7_MASK)

#define GPIO_PCOR_PTCO8_MASK                     (0x100U)
#define GPIO_PCOR_PTCO8_SHIFT                    (8U)
/*! PTCO8 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO8(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO8_SHIFT)) & GPIO_PCOR_PTCO8_MASK)

#define GPIO_PCOR_PTCO9_MASK                     (0x200U)
#define GPIO_PCOR_PTCO9_SHIFT                    (9U)
/*! PTCO9 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO9(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO9_SHIFT)) & GPIO_PCOR_PTCO9_MASK)

#define GPIO_PCOR_PTCO10_MASK                    (0x400U)
#define GPIO_PCOR_PTCO10_SHIFT                   (10U)
/*! PTCO10 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO10(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO10_SHIFT)) & GPIO_PCOR_PTCO10_MASK)

#define GPIO_PCOR_PTCO11_MASK                    (0x800U)
#define GPIO_PCOR_PTCO11_SHIFT                   (11U)
/*! PTCO11 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO11(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO11_SHIFT)) & GPIO_PCOR_PTCO11_MASK)

#define GPIO_PCOR_PTCO12_MASK                    (0x1000U)
#define GPIO_PCOR_PTCO12_SHIFT                   (12U)
/*! PTCO12 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO12(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO12_SHIFT)) & GPIO_PCOR_PTCO12_MASK)

#define GPIO_PCOR_PTCO13_MASK                    (0x2000U)
#define GPIO_PCOR_PTCO13_SHIFT                   (13U)
/*! PTCO13 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO13(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO13_SHIFT)) & GPIO_PCOR_PTCO13_MASK)

#define GPIO_PCOR_PTCO14_MASK                    (0x4000U)
#define GPIO_PCOR_PTCO14_SHIFT                   (14U)
/*! PTCO14 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO14(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO14_SHIFT)) & GPIO_PCOR_PTCO14_MASK)

#define GPIO_PCOR_PTCO15_MASK                    (0x8000U)
#define GPIO_PCOR_PTCO15_SHIFT                   (15U)
/*! PTCO15 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO15(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO15_SHIFT)) & GPIO_PCOR_PTCO15_MASK)

#define GPIO_PCOR_PTCO16_MASK                    (0x10000U)
#define GPIO_PCOR_PTCO16_SHIFT                   (16U)
/*! PTCO16 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO16(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO16_SHIFT)) & GPIO_PCOR_PTCO16_MASK)

#define GPIO_PCOR_PTCO17_MASK                    (0x20000U)
#define GPIO_PCOR_PTCO17_SHIFT                   (17U)
/*! PTCO17 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO17(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO17_SHIFT)) & GPIO_PCOR_PTCO17_MASK)

#define GPIO_PCOR_PTCO18_MASK                    (0x40000U)
#define GPIO_PCOR_PTCO18_SHIFT                   (18U)
/*! PTCO18 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO18(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO18_SHIFT)) & GPIO_PCOR_PTCO18_MASK)

#define GPIO_PCOR_PTCO19_MASK                    (0x80000U)
#define GPIO_PCOR_PTCO19_SHIFT                   (19U)
/*! PTCO19 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO19(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO19_SHIFT)) & GPIO_PCOR_PTCO19_MASK)

#define GPIO_PCOR_PTCO20_MASK                    (0x100000U)
#define GPIO_PCOR_PTCO20_SHIFT                   (20U)
/*! PTCO20 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO20(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO20_SHIFT)) & GPIO_PCOR_PTCO20_MASK)

#define GPIO_PCOR_PTCO21_MASK                    (0x200000U)
#define GPIO_PCOR_PTCO21_SHIFT                   (21U)
/*! PTCO21 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO21(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO21_SHIFT)) & GPIO_PCOR_PTCO21_MASK)

#define GPIO_PCOR_PTCO22_MASK                    (0x400000U)
#define GPIO_PCOR_PTCO22_SHIFT                   (22U)
/*! PTCO22 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO22(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO22_SHIFT)) & GPIO_PCOR_PTCO22_MASK)

#define GPIO_PCOR_PTCO23_MASK                    (0x800000U)
#define GPIO_PCOR_PTCO23_SHIFT                   (23U)
/*! PTCO23 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO23(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO23_SHIFT)) & GPIO_PCOR_PTCO23_MASK)

#define GPIO_PCOR_PTCO24_MASK                    (0x1000000U)
#define GPIO_PCOR_PTCO24_SHIFT                   (24U)
/*! PTCO24 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO24(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO24_SHIFT)) & GPIO_PCOR_PTCO24_MASK)

#define GPIO_PCOR_PTCO25_MASK                    (0x2000000U)
#define GPIO_PCOR_PTCO25_SHIFT                   (25U)
/*! PTCO25 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO25(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO25_SHIFT)) & GPIO_PCOR_PTCO25_MASK)

#define GPIO_PCOR_PTCO26_MASK                    (0x4000000U)
#define GPIO_PCOR_PTCO26_SHIFT                   (26U)
/*! PTCO26 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO26(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO26_SHIFT)) & GPIO_PCOR_PTCO26_MASK)

#define GPIO_PCOR_PTCO27_MASK                    (0x8000000U)
#define GPIO_PCOR_PTCO27_SHIFT                   (27U)
/*! PTCO27 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO27(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO27_SHIFT)) & GPIO_PCOR_PTCO27_MASK)

#define GPIO_PCOR_PTCO28_MASK                    (0x10000000U)
#define GPIO_PCOR_PTCO28_SHIFT                   (28U)
/*! PTCO28 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO28(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO28_SHIFT)) & GPIO_PCOR_PTCO28_MASK)

#define GPIO_PCOR_PTCO29_MASK                    (0x20000000U)
#define GPIO_PCOR_PTCO29_SHIFT                   (29U)
/*! PTCO29 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO29(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO29_SHIFT)) & GPIO_PCOR_PTCO29_MASK)

#define GPIO_PCOR_PTCO30_MASK                    (0x40000000U)
#define GPIO_PCOR_PTCO30_SHIFT                   (30U)
/*! PTCO30 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO30(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO30_SHIFT)) & GPIO_PCOR_PTCO30_MASK)

#define GPIO_PCOR_PTCO31_MASK                    (0x80000000U)
#define GPIO_PCOR_PTCO31_SHIFT                   (31U)
/*! PTCO31 - Port Clear Output
 *  0b0..No change
 *  0b1..Corresponding field in PDOR becomes 0
 */
#define GPIO_PCOR_PTCO31(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO31_SHIFT)) & GPIO_PCOR_PTCO31_MASK)
/*! @} */

/*! @name PTOR - Port Toggle Output */
/*! @{ */

#define GPIO_PTOR_PTTO0_MASK                     (0x1U)
#define GPIO_PTOR_PTTO0_SHIFT                    (0U)
/*! PTTO0 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO0(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO0_SHIFT)) & GPIO_PTOR_PTTO0_MASK)

#define GPIO_PTOR_PTTO1_MASK                     (0x2U)
#define GPIO_PTOR_PTTO1_SHIFT                    (1U)
/*! PTTO1 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO1(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO1_SHIFT)) & GPIO_PTOR_PTTO1_MASK)

#define GPIO_PTOR_PTTO2_MASK                     (0x4U)
#define GPIO_PTOR_PTTO2_SHIFT                    (2U)
/*! PTTO2 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO2(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO2_SHIFT)) & GPIO_PTOR_PTTO2_MASK)

#define GPIO_PTOR_PTTO3_MASK                     (0x8U)
#define GPIO_PTOR_PTTO3_SHIFT                    (3U)
/*! PTTO3 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO3(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO3_SHIFT)) & GPIO_PTOR_PTTO3_MASK)

#define GPIO_PTOR_PTTO4_MASK                     (0x10U)
#define GPIO_PTOR_PTTO4_SHIFT                    (4U)
/*! PTTO4 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO4(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO4_SHIFT)) & GPIO_PTOR_PTTO4_MASK)

#define GPIO_PTOR_PTTO5_MASK                     (0x20U)
#define GPIO_PTOR_PTTO5_SHIFT                    (5U)
/*! PTTO5 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO5(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO5_SHIFT)) & GPIO_PTOR_PTTO5_MASK)

#define GPIO_PTOR_PTTO6_MASK                     (0x40U)
#define GPIO_PTOR_PTTO6_SHIFT                    (6U)
/*! PTTO6 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO6(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO6_SHIFT)) & GPIO_PTOR_PTTO6_MASK)

#define GPIO_PTOR_PTTO7_MASK                     (0x80U)
#define GPIO_PTOR_PTTO7_SHIFT                    (7U)
/*! PTTO7 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO7(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO7_SHIFT)) & GPIO_PTOR_PTTO7_MASK)

#define GPIO_PTOR_PTTO8_MASK                     (0x100U)
#define GPIO_PTOR_PTTO8_SHIFT                    (8U)
/*! PTTO8 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO8(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO8_SHIFT)) & GPIO_PTOR_PTTO8_MASK)

#define GPIO_PTOR_PTTO9_MASK                     (0x200U)
#define GPIO_PTOR_PTTO9_SHIFT                    (9U)
/*! PTTO9 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO9(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO9_SHIFT)) & GPIO_PTOR_PTTO9_MASK)

#define GPIO_PTOR_PTTO10_MASK                    (0x400U)
#define GPIO_PTOR_PTTO10_SHIFT                   (10U)
/*! PTTO10 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO10(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO10_SHIFT)) & GPIO_PTOR_PTTO10_MASK)

#define GPIO_PTOR_PTTO11_MASK                    (0x800U)
#define GPIO_PTOR_PTTO11_SHIFT                   (11U)
/*! PTTO11 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO11(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO11_SHIFT)) & GPIO_PTOR_PTTO11_MASK)

#define GPIO_PTOR_PTTO12_MASK                    (0x1000U)
#define GPIO_PTOR_PTTO12_SHIFT                   (12U)
/*! PTTO12 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO12(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO12_SHIFT)) & GPIO_PTOR_PTTO12_MASK)

#define GPIO_PTOR_PTTO13_MASK                    (0x2000U)
#define GPIO_PTOR_PTTO13_SHIFT                   (13U)
/*! PTTO13 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO13(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO13_SHIFT)) & GPIO_PTOR_PTTO13_MASK)

#define GPIO_PTOR_PTTO14_MASK                    (0x4000U)
#define GPIO_PTOR_PTTO14_SHIFT                   (14U)
/*! PTTO14 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO14(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO14_SHIFT)) & GPIO_PTOR_PTTO14_MASK)

#define GPIO_PTOR_PTTO15_MASK                    (0x8000U)
#define GPIO_PTOR_PTTO15_SHIFT                   (15U)
/*! PTTO15 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO15(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO15_SHIFT)) & GPIO_PTOR_PTTO15_MASK)

#define GPIO_PTOR_PTTO16_MASK                    (0x10000U)
#define GPIO_PTOR_PTTO16_SHIFT                   (16U)
/*! PTTO16 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO16(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO16_SHIFT)) & GPIO_PTOR_PTTO16_MASK)

#define GPIO_PTOR_PTTO17_MASK                    (0x20000U)
#define GPIO_PTOR_PTTO17_SHIFT                   (17U)
/*! PTTO17 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO17(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO17_SHIFT)) & GPIO_PTOR_PTTO17_MASK)

#define GPIO_PTOR_PTTO18_MASK                    (0x40000U)
#define GPIO_PTOR_PTTO18_SHIFT                   (18U)
/*! PTTO18 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO18(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO18_SHIFT)) & GPIO_PTOR_PTTO18_MASK)

#define GPIO_PTOR_PTTO19_MASK                    (0x80000U)
#define GPIO_PTOR_PTTO19_SHIFT                   (19U)
/*! PTTO19 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO19(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO19_SHIFT)) & GPIO_PTOR_PTTO19_MASK)

#define GPIO_PTOR_PTTO20_MASK                    (0x100000U)
#define GPIO_PTOR_PTTO20_SHIFT                   (20U)
/*! PTTO20 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO20(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO20_SHIFT)) & GPIO_PTOR_PTTO20_MASK)

#define GPIO_PTOR_PTTO21_MASK                    (0x200000U)
#define GPIO_PTOR_PTTO21_SHIFT                   (21U)
/*! PTTO21 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO21(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO21_SHIFT)) & GPIO_PTOR_PTTO21_MASK)

#define GPIO_PTOR_PTTO22_MASK                    (0x400000U)
#define GPIO_PTOR_PTTO22_SHIFT                   (22U)
/*! PTTO22 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO22(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO22_SHIFT)) & GPIO_PTOR_PTTO22_MASK)

#define GPIO_PTOR_PTTO23_MASK                    (0x800000U)
#define GPIO_PTOR_PTTO23_SHIFT                   (23U)
/*! PTTO23 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO23(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO23_SHIFT)) & GPIO_PTOR_PTTO23_MASK)

#define GPIO_PTOR_PTTO24_MASK                    (0x1000000U)
#define GPIO_PTOR_PTTO24_SHIFT                   (24U)
/*! PTTO24 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO24(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO24_SHIFT)) & GPIO_PTOR_PTTO24_MASK)

#define GPIO_PTOR_PTTO25_MASK                    (0x2000000U)
#define GPIO_PTOR_PTTO25_SHIFT                   (25U)
/*! PTTO25 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO25(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO25_SHIFT)) & GPIO_PTOR_PTTO25_MASK)

#define GPIO_PTOR_PTTO26_MASK                    (0x4000000U)
#define GPIO_PTOR_PTTO26_SHIFT                   (26U)
/*! PTTO26 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO26(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO26_SHIFT)) & GPIO_PTOR_PTTO26_MASK)

#define GPIO_PTOR_PTTO27_MASK                    (0x8000000U)
#define GPIO_PTOR_PTTO27_SHIFT                   (27U)
/*! PTTO27 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO27(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO27_SHIFT)) & GPIO_PTOR_PTTO27_MASK)

#define GPIO_PTOR_PTTO28_MASK                    (0x10000000U)
#define GPIO_PTOR_PTTO28_SHIFT                   (28U)
/*! PTTO28 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO28(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO28_SHIFT)) & GPIO_PTOR_PTTO28_MASK)

#define GPIO_PTOR_PTTO29_MASK                    (0x20000000U)
#define GPIO_PTOR_PTTO29_SHIFT                   (29U)
/*! PTTO29 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO29(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO29_SHIFT)) & GPIO_PTOR_PTTO29_MASK)

#define GPIO_PTOR_PTTO30_MASK                    (0x40000000U)
#define GPIO_PTOR_PTTO30_SHIFT                   (30U)
/*! PTTO30 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO30(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO30_SHIFT)) & GPIO_PTOR_PTTO30_MASK)

#define GPIO_PTOR_PTTO31_MASK                    (0x80000000U)
#define GPIO_PTOR_PTTO31_SHIFT                   (31U)
/*! PTTO31 - Port Toggle Output
 *  0b0..No change
 *  0b1..Set to the inverse of its current logic state
 */
#define GPIO_PTOR_PTTO31(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO31_SHIFT)) & GPIO_PTOR_PTTO31_MASK)
/*! @} */

/*! @name PDIR - Port Data Input */
/*! @{ */

#define GPIO_PDIR_PDI0_MASK                      (0x1U)
#define GPIO_PDIR_PDI0_SHIFT                     (0U)
/*! PDI0 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI0_SHIFT)) & GPIO_PDIR_PDI0_MASK)

#define GPIO_PDIR_PDI1_MASK                      (0x2U)
#define GPIO_PDIR_PDI1_SHIFT                     (1U)
/*! PDI1 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI1_SHIFT)) & GPIO_PDIR_PDI1_MASK)

#define GPIO_PDIR_PDI2_MASK                      (0x4U)
#define GPIO_PDIR_PDI2_SHIFT                     (2U)
/*! PDI2 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI2_SHIFT)) & GPIO_PDIR_PDI2_MASK)

#define GPIO_PDIR_PDI3_MASK                      (0x8U)
#define GPIO_PDIR_PDI3_SHIFT                     (3U)
/*! PDI3 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI3_SHIFT)) & GPIO_PDIR_PDI3_MASK)

#define GPIO_PDIR_PDI4_MASK                      (0x10U)
#define GPIO_PDIR_PDI4_SHIFT                     (4U)
/*! PDI4 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI4_SHIFT)) & GPIO_PDIR_PDI4_MASK)

#define GPIO_PDIR_PDI5_MASK                      (0x20U)
#define GPIO_PDIR_PDI5_SHIFT                     (5U)
/*! PDI5 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI5_SHIFT)) & GPIO_PDIR_PDI5_MASK)

#define GPIO_PDIR_PDI6_MASK                      (0x40U)
#define GPIO_PDIR_PDI6_SHIFT                     (6U)
/*! PDI6 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI6_SHIFT)) & GPIO_PDIR_PDI6_MASK)

#define GPIO_PDIR_PDI7_MASK                      (0x80U)
#define GPIO_PDIR_PDI7_SHIFT                     (7U)
/*! PDI7 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI7_SHIFT)) & GPIO_PDIR_PDI7_MASK)

#define GPIO_PDIR_PDI8_MASK                      (0x100U)
#define GPIO_PDIR_PDI8_SHIFT                     (8U)
/*! PDI8 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI8_SHIFT)) & GPIO_PDIR_PDI8_MASK)

#define GPIO_PDIR_PDI9_MASK                      (0x200U)
#define GPIO_PDIR_PDI9_SHIFT                     (9U)
/*! PDI9 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI9_SHIFT)) & GPIO_PDIR_PDI9_MASK)

#define GPIO_PDIR_PDI10_MASK                     (0x400U)
#define GPIO_PDIR_PDI10_SHIFT                    (10U)
/*! PDI10 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI10_SHIFT)) & GPIO_PDIR_PDI10_MASK)

#define GPIO_PDIR_PDI11_MASK                     (0x800U)
#define GPIO_PDIR_PDI11_SHIFT                    (11U)
/*! PDI11 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI11_SHIFT)) & GPIO_PDIR_PDI11_MASK)

#define GPIO_PDIR_PDI12_MASK                     (0x1000U)
#define GPIO_PDIR_PDI12_SHIFT                    (12U)
/*! PDI12 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI12_SHIFT)) & GPIO_PDIR_PDI12_MASK)

#define GPIO_PDIR_PDI13_MASK                     (0x2000U)
#define GPIO_PDIR_PDI13_SHIFT                    (13U)
/*! PDI13 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI13_SHIFT)) & GPIO_PDIR_PDI13_MASK)

#define GPIO_PDIR_PDI14_MASK                     (0x4000U)
#define GPIO_PDIR_PDI14_SHIFT                    (14U)
/*! PDI14 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI14_SHIFT)) & GPIO_PDIR_PDI14_MASK)

#define GPIO_PDIR_PDI15_MASK                     (0x8000U)
#define GPIO_PDIR_PDI15_SHIFT                    (15U)
/*! PDI15 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI15_SHIFT)) & GPIO_PDIR_PDI15_MASK)

#define GPIO_PDIR_PDI16_MASK                     (0x10000U)
#define GPIO_PDIR_PDI16_SHIFT                    (16U)
/*! PDI16 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI16_SHIFT)) & GPIO_PDIR_PDI16_MASK)

#define GPIO_PDIR_PDI17_MASK                     (0x20000U)
#define GPIO_PDIR_PDI17_SHIFT                    (17U)
/*! PDI17 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI17_SHIFT)) & GPIO_PDIR_PDI17_MASK)

#define GPIO_PDIR_PDI18_MASK                     (0x40000U)
#define GPIO_PDIR_PDI18_SHIFT                    (18U)
/*! PDI18 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI18_SHIFT)) & GPIO_PDIR_PDI18_MASK)

#define GPIO_PDIR_PDI19_MASK                     (0x80000U)
#define GPIO_PDIR_PDI19_SHIFT                    (19U)
/*! PDI19 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI19_SHIFT)) & GPIO_PDIR_PDI19_MASK)

#define GPIO_PDIR_PDI20_MASK                     (0x100000U)
#define GPIO_PDIR_PDI20_SHIFT                    (20U)
/*! PDI20 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI20_SHIFT)) & GPIO_PDIR_PDI20_MASK)

#define GPIO_PDIR_PDI21_MASK                     (0x200000U)
#define GPIO_PDIR_PDI21_SHIFT                    (21U)
/*! PDI21 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI21_SHIFT)) & GPIO_PDIR_PDI21_MASK)

#define GPIO_PDIR_PDI22_MASK                     (0x400000U)
#define GPIO_PDIR_PDI22_SHIFT                    (22U)
/*! PDI22 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI22_SHIFT)) & GPIO_PDIR_PDI22_MASK)

#define GPIO_PDIR_PDI23_MASK                     (0x800000U)
#define GPIO_PDIR_PDI23_SHIFT                    (23U)
/*! PDI23 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI23_SHIFT)) & GPIO_PDIR_PDI23_MASK)

#define GPIO_PDIR_PDI24_MASK                     (0x1000000U)
#define GPIO_PDIR_PDI24_SHIFT                    (24U)
/*! PDI24 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI24_SHIFT)) & GPIO_PDIR_PDI24_MASK)

#define GPIO_PDIR_PDI25_MASK                     (0x2000000U)
#define GPIO_PDIR_PDI25_SHIFT                    (25U)
/*! PDI25 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI25_SHIFT)) & GPIO_PDIR_PDI25_MASK)

#define GPIO_PDIR_PDI26_MASK                     (0x4000000U)
#define GPIO_PDIR_PDI26_SHIFT                    (26U)
/*! PDI26 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI26_SHIFT)) & GPIO_PDIR_PDI26_MASK)

#define GPIO_PDIR_PDI27_MASK                     (0x8000000U)
#define GPIO_PDIR_PDI27_SHIFT                    (27U)
/*! PDI27 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI27_SHIFT)) & GPIO_PDIR_PDI27_MASK)

#define GPIO_PDIR_PDI28_MASK                     (0x10000000U)
#define GPIO_PDIR_PDI28_SHIFT                    (28U)
/*! PDI28 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI28_SHIFT)) & GPIO_PDIR_PDI28_MASK)

#define GPIO_PDIR_PDI29_MASK                     (0x20000000U)
#define GPIO_PDIR_PDI29_SHIFT                    (29U)
/*! PDI29 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI29_SHIFT)) & GPIO_PDIR_PDI29_MASK)

#define GPIO_PDIR_PDI30_MASK                     (0x40000000U)
#define GPIO_PDIR_PDI30_SHIFT                    (30U)
/*! PDI30 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI30_SHIFT)) & GPIO_PDIR_PDI30_MASK)

#define GPIO_PDIR_PDI31_MASK                     (0x80000000U)
#define GPIO_PDIR_PDI31_SHIFT                    (31U)
/*! PDI31 - Port Data Input
 *  0b0..Logic 0
 *  0b1..Logic 1
 */
#define GPIO_PDIR_PDI31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI31_SHIFT)) & GPIO_PDIR_PDI31_MASK)
/*! @} */

/*! @name PDDR - Port Data Direction */
/*! @{ */

#define GPIO_PDDR_PDD0_MASK                      (0x1U)
#define GPIO_PDDR_PDD0_SHIFT                     (0U)
/*! PDD0 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD0_SHIFT)) & GPIO_PDDR_PDD0_MASK)

#define GPIO_PDDR_PDD1_MASK                      (0x2U)
#define GPIO_PDDR_PDD1_SHIFT                     (1U)
/*! PDD1 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD1_SHIFT)) & GPIO_PDDR_PDD1_MASK)

#define GPIO_PDDR_PDD2_MASK                      (0x4U)
#define GPIO_PDDR_PDD2_SHIFT                     (2U)
/*! PDD2 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD2_SHIFT)) & GPIO_PDDR_PDD2_MASK)

#define GPIO_PDDR_PDD3_MASK                      (0x8U)
#define GPIO_PDDR_PDD3_SHIFT                     (3U)
/*! PDD3 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD3_SHIFT)) & GPIO_PDDR_PDD3_MASK)

#define GPIO_PDDR_PDD4_MASK                      (0x10U)
#define GPIO_PDDR_PDD4_SHIFT                     (4U)
/*! PDD4 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD4_SHIFT)) & GPIO_PDDR_PDD4_MASK)

#define GPIO_PDDR_PDD5_MASK                      (0x20U)
#define GPIO_PDDR_PDD5_SHIFT                     (5U)
/*! PDD5 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD5_SHIFT)) & GPIO_PDDR_PDD5_MASK)

#define GPIO_PDDR_PDD6_MASK                      (0x40U)
#define GPIO_PDDR_PDD6_SHIFT                     (6U)
/*! PDD6 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD6_SHIFT)) & GPIO_PDDR_PDD6_MASK)

#define GPIO_PDDR_PDD7_MASK                      (0x80U)
#define GPIO_PDDR_PDD7_SHIFT                     (7U)
/*! PDD7 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD7_SHIFT)) & GPIO_PDDR_PDD7_MASK)

#define GPIO_PDDR_PDD8_MASK                      (0x100U)
#define GPIO_PDDR_PDD8_SHIFT                     (8U)
/*! PDD8 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD8_SHIFT)) & GPIO_PDDR_PDD8_MASK)

#define GPIO_PDDR_PDD9_MASK                      (0x200U)
#define GPIO_PDDR_PDD9_SHIFT                     (9U)
/*! PDD9 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD9_SHIFT)) & GPIO_PDDR_PDD9_MASK)

#define GPIO_PDDR_PDD10_MASK                     (0x400U)
#define GPIO_PDDR_PDD10_SHIFT                    (10U)
/*! PDD10 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD10_SHIFT)) & GPIO_PDDR_PDD10_MASK)

#define GPIO_PDDR_PDD11_MASK                     (0x800U)
#define GPIO_PDDR_PDD11_SHIFT                    (11U)
/*! PDD11 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD11_SHIFT)) & GPIO_PDDR_PDD11_MASK)

#define GPIO_PDDR_PDD12_MASK                     (0x1000U)
#define GPIO_PDDR_PDD12_SHIFT                    (12U)
/*! PDD12 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD12_SHIFT)) & GPIO_PDDR_PDD12_MASK)

#define GPIO_PDDR_PDD13_MASK                     (0x2000U)
#define GPIO_PDDR_PDD13_SHIFT                    (13U)
/*! PDD13 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD13_SHIFT)) & GPIO_PDDR_PDD13_MASK)

#define GPIO_PDDR_PDD14_MASK                     (0x4000U)
#define GPIO_PDDR_PDD14_SHIFT                    (14U)
/*! PDD14 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD14_SHIFT)) & GPIO_PDDR_PDD14_MASK)

#define GPIO_PDDR_PDD15_MASK                     (0x8000U)
#define GPIO_PDDR_PDD15_SHIFT                    (15U)
/*! PDD15 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD15_SHIFT)) & GPIO_PDDR_PDD15_MASK)

#define GPIO_PDDR_PDD16_MASK                     (0x10000U)
#define GPIO_PDDR_PDD16_SHIFT                    (16U)
/*! PDD16 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD16_SHIFT)) & GPIO_PDDR_PDD16_MASK)

#define GPIO_PDDR_PDD17_MASK                     (0x20000U)
#define GPIO_PDDR_PDD17_SHIFT                    (17U)
/*! PDD17 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD17_SHIFT)) & GPIO_PDDR_PDD17_MASK)

#define GPIO_PDDR_PDD18_MASK                     (0x40000U)
#define GPIO_PDDR_PDD18_SHIFT                    (18U)
/*! PDD18 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD18_SHIFT)) & GPIO_PDDR_PDD18_MASK)

#define GPIO_PDDR_PDD19_MASK                     (0x80000U)
#define GPIO_PDDR_PDD19_SHIFT                    (19U)
/*! PDD19 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD19_SHIFT)) & GPIO_PDDR_PDD19_MASK)

#define GPIO_PDDR_PDD20_MASK                     (0x100000U)
#define GPIO_PDDR_PDD20_SHIFT                    (20U)
/*! PDD20 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD20_SHIFT)) & GPIO_PDDR_PDD20_MASK)

#define GPIO_PDDR_PDD21_MASK                     (0x200000U)
#define GPIO_PDDR_PDD21_SHIFT                    (21U)
/*! PDD21 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD21_SHIFT)) & GPIO_PDDR_PDD21_MASK)

#define GPIO_PDDR_PDD22_MASK                     (0x400000U)
#define GPIO_PDDR_PDD22_SHIFT                    (22U)
/*! PDD22 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD22_SHIFT)) & GPIO_PDDR_PDD22_MASK)

#define GPIO_PDDR_PDD23_MASK                     (0x800000U)
#define GPIO_PDDR_PDD23_SHIFT                    (23U)
/*! PDD23 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD23_SHIFT)) & GPIO_PDDR_PDD23_MASK)

#define GPIO_PDDR_PDD24_MASK                     (0x1000000U)
#define GPIO_PDDR_PDD24_SHIFT                    (24U)
/*! PDD24 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD24_SHIFT)) & GPIO_PDDR_PDD24_MASK)

#define GPIO_PDDR_PDD25_MASK                     (0x2000000U)
#define GPIO_PDDR_PDD25_SHIFT                    (25U)
/*! PDD25 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD25_SHIFT)) & GPIO_PDDR_PDD25_MASK)

#define GPIO_PDDR_PDD26_MASK                     (0x4000000U)
#define GPIO_PDDR_PDD26_SHIFT                    (26U)
/*! PDD26 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD26_SHIFT)) & GPIO_PDDR_PDD26_MASK)

#define GPIO_PDDR_PDD27_MASK                     (0x8000000U)
#define GPIO_PDDR_PDD27_SHIFT                    (27U)
/*! PDD27 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD27_SHIFT)) & GPIO_PDDR_PDD27_MASK)

#define GPIO_PDDR_PDD28_MASK                     (0x10000000U)
#define GPIO_PDDR_PDD28_SHIFT                    (28U)
/*! PDD28 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD28_SHIFT)) & GPIO_PDDR_PDD28_MASK)

#define GPIO_PDDR_PDD29_MASK                     (0x20000000U)
#define GPIO_PDDR_PDD29_SHIFT                    (29U)
/*! PDD29 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD29_SHIFT)) & GPIO_PDDR_PDD29_MASK)

#define GPIO_PDDR_PDD30_MASK                     (0x40000000U)
#define GPIO_PDDR_PDD30_SHIFT                    (30U)
/*! PDD30 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD30_SHIFT)) & GPIO_PDDR_PDD30_MASK)

#define GPIO_PDDR_PDD31_MASK                     (0x80000000U)
#define GPIO_PDDR_PDD31_SHIFT                    (31U)
/*! PDD31 - Port Data Direction
 *  0b0..Input
 *  0b1..Output
 */
#define GPIO_PDDR_PDD31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD31_SHIFT)) & GPIO_PDDR_PDD31_MASK)
/*! @} */

/*! @name PIDR - Port Input Disable */
/*! @{ */

#define GPIO_PIDR_PID0_MASK                      (0x1U)
#define GPIO_PIDR_PID0_SHIFT                     (0U)
/*! PID0 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID0_SHIFT)) & GPIO_PIDR_PID0_MASK)

#define GPIO_PIDR_PID1_MASK                      (0x2U)
#define GPIO_PIDR_PID1_SHIFT                     (1U)
/*! PID1 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID1_SHIFT)) & GPIO_PIDR_PID1_MASK)

#define GPIO_PIDR_PID2_MASK                      (0x4U)
#define GPIO_PIDR_PID2_SHIFT                     (2U)
/*! PID2 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID2_SHIFT)) & GPIO_PIDR_PID2_MASK)

#define GPIO_PIDR_PID3_MASK                      (0x8U)
#define GPIO_PIDR_PID3_SHIFT                     (3U)
/*! PID3 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID3_SHIFT)) & GPIO_PIDR_PID3_MASK)

#define GPIO_PIDR_PID4_MASK                      (0x10U)
#define GPIO_PIDR_PID4_SHIFT                     (4U)
/*! PID4 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID4_SHIFT)) & GPIO_PIDR_PID4_MASK)

#define GPIO_PIDR_PID5_MASK                      (0x20U)
#define GPIO_PIDR_PID5_SHIFT                     (5U)
/*! PID5 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID5_SHIFT)) & GPIO_PIDR_PID5_MASK)

#define GPIO_PIDR_PID6_MASK                      (0x40U)
#define GPIO_PIDR_PID6_SHIFT                     (6U)
/*! PID6 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID6_SHIFT)) & GPIO_PIDR_PID6_MASK)

#define GPIO_PIDR_PID7_MASK                      (0x80U)
#define GPIO_PIDR_PID7_SHIFT                     (7U)
/*! PID7 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID7_SHIFT)) & GPIO_PIDR_PID7_MASK)

#define GPIO_PIDR_PID8_MASK                      (0x100U)
#define GPIO_PIDR_PID8_SHIFT                     (8U)
/*! PID8 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID8_SHIFT)) & GPIO_PIDR_PID8_MASK)

#define GPIO_PIDR_PID9_MASK                      (0x200U)
#define GPIO_PIDR_PID9_SHIFT                     (9U)
/*! PID9 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID9_SHIFT)) & GPIO_PIDR_PID9_MASK)

#define GPIO_PIDR_PID10_MASK                     (0x400U)
#define GPIO_PIDR_PID10_SHIFT                    (10U)
/*! PID10 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID10_SHIFT)) & GPIO_PIDR_PID10_MASK)

#define GPIO_PIDR_PID11_MASK                     (0x800U)
#define GPIO_PIDR_PID11_SHIFT                    (11U)
/*! PID11 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID11_SHIFT)) & GPIO_PIDR_PID11_MASK)

#define GPIO_PIDR_PID12_MASK                     (0x1000U)
#define GPIO_PIDR_PID12_SHIFT                    (12U)
/*! PID12 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID12_SHIFT)) & GPIO_PIDR_PID12_MASK)

#define GPIO_PIDR_PID13_MASK                     (0x2000U)
#define GPIO_PIDR_PID13_SHIFT                    (13U)
/*! PID13 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID13_SHIFT)) & GPIO_PIDR_PID13_MASK)

#define GPIO_PIDR_PID14_MASK                     (0x4000U)
#define GPIO_PIDR_PID14_SHIFT                    (14U)
/*! PID14 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID14_SHIFT)) & GPIO_PIDR_PID14_MASK)

#define GPIO_PIDR_PID15_MASK                     (0x8000U)
#define GPIO_PIDR_PID15_SHIFT                    (15U)
/*! PID15 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID15_SHIFT)) & GPIO_PIDR_PID15_MASK)

#define GPIO_PIDR_PID16_MASK                     (0x10000U)
#define GPIO_PIDR_PID16_SHIFT                    (16U)
/*! PID16 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID16_SHIFT)) & GPIO_PIDR_PID16_MASK)

#define GPIO_PIDR_PID17_MASK                     (0x20000U)
#define GPIO_PIDR_PID17_SHIFT                    (17U)
/*! PID17 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID17_SHIFT)) & GPIO_PIDR_PID17_MASK)

#define GPIO_PIDR_PID18_MASK                     (0x40000U)
#define GPIO_PIDR_PID18_SHIFT                    (18U)
/*! PID18 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID18_SHIFT)) & GPIO_PIDR_PID18_MASK)

#define GPIO_PIDR_PID19_MASK                     (0x80000U)
#define GPIO_PIDR_PID19_SHIFT                    (19U)
/*! PID19 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID19_SHIFT)) & GPIO_PIDR_PID19_MASK)

#define GPIO_PIDR_PID20_MASK                     (0x100000U)
#define GPIO_PIDR_PID20_SHIFT                    (20U)
/*! PID20 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID20_SHIFT)) & GPIO_PIDR_PID20_MASK)

#define GPIO_PIDR_PID21_MASK                     (0x200000U)
#define GPIO_PIDR_PID21_SHIFT                    (21U)
/*! PID21 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID21_SHIFT)) & GPIO_PIDR_PID21_MASK)

#define GPIO_PIDR_PID22_MASK                     (0x400000U)
#define GPIO_PIDR_PID22_SHIFT                    (22U)
/*! PID22 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID22_SHIFT)) & GPIO_PIDR_PID22_MASK)

#define GPIO_PIDR_PID23_MASK                     (0x800000U)
#define GPIO_PIDR_PID23_SHIFT                    (23U)
/*! PID23 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID23_SHIFT)) & GPIO_PIDR_PID23_MASK)

#define GPIO_PIDR_PID24_MASK                     (0x1000000U)
#define GPIO_PIDR_PID24_SHIFT                    (24U)
/*! PID24 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID24_SHIFT)) & GPIO_PIDR_PID24_MASK)

#define GPIO_PIDR_PID25_MASK                     (0x2000000U)
#define GPIO_PIDR_PID25_SHIFT                    (25U)
/*! PID25 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID25_SHIFT)) & GPIO_PIDR_PID25_MASK)

#define GPIO_PIDR_PID26_MASK                     (0x4000000U)
#define GPIO_PIDR_PID26_SHIFT                    (26U)
/*! PID26 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID26_SHIFT)) & GPIO_PIDR_PID26_MASK)

#define GPIO_PIDR_PID27_MASK                     (0x8000000U)
#define GPIO_PIDR_PID27_SHIFT                    (27U)
/*! PID27 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID27_SHIFT)) & GPIO_PIDR_PID27_MASK)

#define GPIO_PIDR_PID28_MASK                     (0x10000000U)
#define GPIO_PIDR_PID28_SHIFT                    (28U)
/*! PID28 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID28_SHIFT)) & GPIO_PIDR_PID28_MASK)

#define GPIO_PIDR_PID29_MASK                     (0x20000000U)
#define GPIO_PIDR_PID29_SHIFT                    (29U)
/*! PID29 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID29_SHIFT)) & GPIO_PIDR_PID29_MASK)

#define GPIO_PIDR_PID30_MASK                     (0x40000000U)
#define GPIO_PIDR_PID30_SHIFT                    (30U)
/*! PID30 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID30_SHIFT)) & GPIO_PIDR_PID30_MASK)

#define GPIO_PIDR_PID31_MASK                     (0x80000000U)
#define GPIO_PIDR_PID31_SHIFT                    (31U)
/*! PID31 - Port Input Disable
 *  0b0..Configured for general-purpose input
 *  0b1..Disabled for general-purpose input
 */
#define GPIO_PIDR_PID31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_PIDR_PID31_SHIFT)) & GPIO_PIDR_PID31_MASK)
/*! @} */

/*! @name PDR - Pin Data */
/*! @{ */

#define GPIO_PDR_PD_MASK                         (0x1U)
#define GPIO_PDR_PD_SHIFT                        (0U)
/*! PD - Pin Data (I/O)
 *  0b0..Logic zero
 *  0b1..Logic one
 */
#define GPIO_PDR_PD(x)                           (((uint8_t)(((uint8_t)(x)) << GPIO_PDR_PD_SHIFT)) & GPIO_PDR_PD_MASK)
/*! @} */

/*! @name ICR - Interrupt Control 0..Interrupt Control 31 */
/*! @{ */

#define GPIO_ICR_IRQC_MASK                       (0xF0000U)
#define GPIO_ICR_IRQC_SHIFT                      (16U)
/*! IRQC - Interrupt Configuration
 *  0b0000..ISF is disabled
 *  0b0001..ISF and DMA request on rising edge
 *  0b0010..ISF and DMA request on falling edge
 *  0b0011..ISF and DMA request on either edge
 *  0b0100..Reserved
 *  0b0101..ISF sets on rising edge
 *  0b0110..ISF sets on falling edge
 *  0b0111..ISF sets on either edge
 *  0b1000..ISF and interrupt when logic 0
 *  0b1001..ISF and interrupt on rising edge
 *  0b1010..ISF and interrupt on falling edge
 *  0b1011..ISF and Interrupt on either edge
 *  0b1100..ISF and interrupt when logic 1
 *  0b1101..Enable active-high trigger output; ISF on rising edge (pin state is ORed with other enabled triggers
 *          to generate the output trigger for use by other peripherals)
 *  0b1110..Enable active-low trigger output; ISF on falling edge (pin state is inverted and ORed with other
 *          enabled triggers to generate the output trigger for use by other peripherals)
 *  0b1111..Reserved
 */
#define GPIO_ICR_IRQC(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_ICR_IRQC_SHIFT)) & GPIO_ICR_IRQC_MASK)

#define GPIO_ICR_IRQS_MASK                       (0x100000U)
#define GPIO_ICR_IRQS_SHIFT                      (20U)
/*! IRQS - Interrupt Select
 *  0b0..Interrupt, trigger output, or DMA request 0
 *  0b1..Interrupt, trigger output, or DMA request 1
 */
#define GPIO_ICR_IRQS(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_ICR_IRQS_SHIFT)) & GPIO_ICR_IRQS_MASK)

#define GPIO_ICR_LK_MASK                         (0x800000U)
#define GPIO_ICR_LK_SHIFT                        (23U)
/*! LK - Lock
 *  0b0..Lock
 *  0b1..Do not lock
 */
#define GPIO_ICR_LK(x)                           (((uint32_t)(((uint32_t)(x)) << GPIO_ICR_LK_SHIFT)) & GPIO_ICR_LK_MASK)

#define GPIO_ICR_ISF_MASK                        (0x1000000U)
#define GPIO_ICR_ISF_SHIFT                       (24U)
/*! ISF - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ICR_ISF(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_ICR_ISF_SHIFT)) & GPIO_ICR_ISF_MASK)
/*! @} */

/*! @name GICLR - Global Interrupt Control Low */
/*! @{ */

#define GPIO_GICLR_GIWE0_MASK                    (0x1U)
#define GPIO_GICLR_GIWE0_SHIFT                   (0U)
/*! GIWE0 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE0(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE0_SHIFT)) & GPIO_GICLR_GIWE0_MASK)

#define GPIO_GICLR_GIWE1_MASK                    (0x2U)
#define GPIO_GICLR_GIWE1_SHIFT                   (1U)
/*! GIWE1 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE1(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE1_SHIFT)) & GPIO_GICLR_GIWE1_MASK)

#define GPIO_GICLR_GIWE2_MASK                    (0x4U)
#define GPIO_GICLR_GIWE2_SHIFT                   (2U)
/*! GIWE2 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE2(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE2_SHIFT)) & GPIO_GICLR_GIWE2_MASK)

#define GPIO_GICLR_GIWE3_MASK                    (0x8U)
#define GPIO_GICLR_GIWE3_SHIFT                   (3U)
/*! GIWE3 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE3(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE3_SHIFT)) & GPIO_GICLR_GIWE3_MASK)

#define GPIO_GICLR_GIWE4_MASK                    (0x10U)
#define GPIO_GICLR_GIWE4_SHIFT                   (4U)
/*! GIWE4 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE4(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE4_SHIFT)) & GPIO_GICLR_GIWE4_MASK)

#define GPIO_GICLR_GIWE5_MASK                    (0x20U)
#define GPIO_GICLR_GIWE5_SHIFT                   (5U)
/*! GIWE5 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE5(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE5_SHIFT)) & GPIO_GICLR_GIWE5_MASK)

#define GPIO_GICLR_GIWE6_MASK                    (0x40U)
#define GPIO_GICLR_GIWE6_SHIFT                   (6U)
/*! GIWE6 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE6(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE6_SHIFT)) & GPIO_GICLR_GIWE6_MASK)

#define GPIO_GICLR_GIWE7_MASK                    (0x80U)
#define GPIO_GICLR_GIWE7_SHIFT                   (7U)
/*! GIWE7 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE7(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE7_SHIFT)) & GPIO_GICLR_GIWE7_MASK)

#define GPIO_GICLR_GIWE8_MASK                    (0x100U)
#define GPIO_GICLR_GIWE8_SHIFT                   (8U)
/*! GIWE8 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE8(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE8_SHIFT)) & GPIO_GICLR_GIWE8_MASK)

#define GPIO_GICLR_GIWE9_MASK                    (0x200U)
#define GPIO_GICLR_GIWE9_SHIFT                   (9U)
/*! GIWE9 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE9(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE9_SHIFT)) & GPIO_GICLR_GIWE9_MASK)

#define GPIO_GICLR_GIWE10_MASK                   (0x400U)
#define GPIO_GICLR_GIWE10_SHIFT                  (10U)
/*! GIWE10 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE10(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE10_SHIFT)) & GPIO_GICLR_GIWE10_MASK)

#define GPIO_GICLR_GIWE11_MASK                   (0x800U)
#define GPIO_GICLR_GIWE11_SHIFT                  (11U)
/*! GIWE11 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE11(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE11_SHIFT)) & GPIO_GICLR_GIWE11_MASK)

#define GPIO_GICLR_GIWE12_MASK                   (0x1000U)
#define GPIO_GICLR_GIWE12_SHIFT                  (12U)
/*! GIWE12 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE12(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE12_SHIFT)) & GPIO_GICLR_GIWE12_MASK)

#define GPIO_GICLR_GIWE13_MASK                   (0x2000U)
#define GPIO_GICLR_GIWE13_SHIFT                  (13U)
/*! GIWE13 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE13(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE13_SHIFT)) & GPIO_GICLR_GIWE13_MASK)

#define GPIO_GICLR_GIWE14_MASK                   (0x4000U)
#define GPIO_GICLR_GIWE14_SHIFT                  (14U)
/*! GIWE14 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE14(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE14_SHIFT)) & GPIO_GICLR_GIWE14_MASK)

#define GPIO_GICLR_GIWE15_MASK                   (0x8000U)
#define GPIO_GICLR_GIWE15_SHIFT                  (15U)
/*! GIWE15 - Global Interrupt Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define GPIO_GICLR_GIWE15(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWE15_SHIFT)) & GPIO_GICLR_GIWE15_MASK)

#define GPIO_GICLR_GIWD_MASK                     (0xFFFF0000U)
#define GPIO_GICLR_GIWD_SHIFT                    (16U)
/*! GIWD - Global Interrupt Write Data */
#define GPIO_GICLR_GIWD(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_GICLR_GIWD_SHIFT)) & GPIO_GICLR_GIWD_MASK)
/*! @} */

/*! @name GICHR - Global Interrupt Control High */
/*! @{ */

#define GPIO_GICHR_GIWE16_MASK                   (0x1U)
#define GPIO_GICHR_GIWE16_SHIFT                  (0U)
/*! GIWE16 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE16(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE16_SHIFT)) & GPIO_GICHR_GIWE16_MASK)

#define GPIO_GICHR_GIWE17_MASK                   (0x2U)
#define GPIO_GICHR_GIWE17_SHIFT                  (1U)
/*! GIWE17 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE17(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE17_SHIFT)) & GPIO_GICHR_GIWE17_MASK)

#define GPIO_GICHR_GIWE18_MASK                   (0x4U)
#define GPIO_GICHR_GIWE18_SHIFT                  (2U)
/*! GIWE18 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE18(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE18_SHIFT)) & GPIO_GICHR_GIWE18_MASK)

#define GPIO_GICHR_GIWE19_MASK                   (0x8U)
#define GPIO_GICHR_GIWE19_SHIFT                  (3U)
/*! GIWE19 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE19(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE19_SHIFT)) & GPIO_GICHR_GIWE19_MASK)

#define GPIO_GICHR_GIWE20_MASK                   (0x10U)
#define GPIO_GICHR_GIWE20_SHIFT                  (4U)
/*! GIWE20 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE20(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE20_SHIFT)) & GPIO_GICHR_GIWE20_MASK)

#define GPIO_GICHR_GIWE21_MASK                   (0x20U)
#define GPIO_GICHR_GIWE21_SHIFT                  (5U)
/*! GIWE21 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE21(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE21_SHIFT)) & GPIO_GICHR_GIWE21_MASK)

#define GPIO_GICHR_GIWE22_MASK                   (0x40U)
#define GPIO_GICHR_GIWE22_SHIFT                  (6U)
/*! GIWE22 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE22(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE22_SHIFT)) & GPIO_GICHR_GIWE22_MASK)

#define GPIO_GICHR_GIWE23_MASK                   (0x80U)
#define GPIO_GICHR_GIWE23_SHIFT                  (7U)
/*! GIWE23 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE23(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE23_SHIFT)) & GPIO_GICHR_GIWE23_MASK)

#define GPIO_GICHR_GIWE24_MASK                   (0x100U)
#define GPIO_GICHR_GIWE24_SHIFT                  (8U)
/*! GIWE24 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE24(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE24_SHIFT)) & GPIO_GICHR_GIWE24_MASK)

#define GPIO_GICHR_GIWE25_MASK                   (0x200U)
#define GPIO_GICHR_GIWE25_SHIFT                  (9U)
/*! GIWE25 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE25(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE25_SHIFT)) & GPIO_GICHR_GIWE25_MASK)

#define GPIO_GICHR_GIWE26_MASK                   (0x400U)
#define GPIO_GICHR_GIWE26_SHIFT                  (10U)
/*! GIWE26 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE26(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE26_SHIFT)) & GPIO_GICHR_GIWE26_MASK)

#define GPIO_GICHR_GIWE27_MASK                   (0x800U)
#define GPIO_GICHR_GIWE27_SHIFT                  (11U)
/*! GIWE27 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE27(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE27_SHIFT)) & GPIO_GICHR_GIWE27_MASK)

#define GPIO_GICHR_GIWE28_MASK                   (0x1000U)
#define GPIO_GICHR_GIWE28_SHIFT                  (12U)
/*! GIWE28 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE28(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE28_SHIFT)) & GPIO_GICHR_GIWE28_MASK)

#define GPIO_GICHR_GIWE29_MASK                   (0x2000U)
#define GPIO_GICHR_GIWE29_SHIFT                  (13U)
/*! GIWE29 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE29(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE29_SHIFT)) & GPIO_GICHR_GIWE29_MASK)

#define GPIO_GICHR_GIWE30_MASK                   (0x4000U)
#define GPIO_GICHR_GIWE30_SHIFT                  (14U)
/*! GIWE30 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE30(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE30_SHIFT)) & GPIO_GICHR_GIWE30_MASK)

#define GPIO_GICHR_GIWE31_MASK                   (0x8000U)
#define GPIO_GICHR_GIWE31_SHIFT                  (15U)
/*! GIWE31 - Global Interrupt Write Enable
 *  0b0..Not updated.
 *  0b1..Updated
 */
#define GPIO_GICHR_GIWE31(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWE31_SHIFT)) & GPIO_GICHR_GIWE31_MASK)

#define GPIO_GICHR_GIWD_MASK                     (0xFFFF0000U)
#define GPIO_GICHR_GIWD_SHIFT                    (16U)
/*! GIWD - Global Interrupt Write Data */
#define GPIO_GICHR_GIWD(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_GICHR_GIWD_SHIFT)) & GPIO_GICHR_GIWD_MASK)
/*! @} */

/*! @name ISFR - Interrupt Status Flag */
/*! @{ */

#define GPIO_ISFR_ISF0_MASK                      (0x1U)
#define GPIO_ISFR_ISF0_SHIFT                     (0U)
/*! ISF0 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF0_SHIFT)) & GPIO_ISFR_ISF0_MASK)

#define GPIO_ISFR_ISF1_MASK                      (0x2U)
#define GPIO_ISFR_ISF1_SHIFT                     (1U)
/*! ISF1 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF1_SHIFT)) & GPIO_ISFR_ISF1_MASK)

#define GPIO_ISFR_ISF2_MASK                      (0x4U)
#define GPIO_ISFR_ISF2_SHIFT                     (2U)
/*! ISF2 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF2_SHIFT)) & GPIO_ISFR_ISF2_MASK)

#define GPIO_ISFR_ISF3_MASK                      (0x8U)
#define GPIO_ISFR_ISF3_SHIFT                     (3U)
/*! ISF3 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF3_SHIFT)) & GPIO_ISFR_ISF3_MASK)

#define GPIO_ISFR_ISF4_MASK                      (0x10U)
#define GPIO_ISFR_ISF4_SHIFT                     (4U)
/*! ISF4 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF4_SHIFT)) & GPIO_ISFR_ISF4_MASK)

#define GPIO_ISFR_ISF5_MASK                      (0x20U)
#define GPIO_ISFR_ISF5_SHIFT                     (5U)
/*! ISF5 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF5_SHIFT)) & GPIO_ISFR_ISF5_MASK)

#define GPIO_ISFR_ISF6_MASK                      (0x40U)
#define GPIO_ISFR_ISF6_SHIFT                     (6U)
/*! ISF6 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF6_SHIFT)) & GPIO_ISFR_ISF6_MASK)

#define GPIO_ISFR_ISF7_MASK                      (0x80U)
#define GPIO_ISFR_ISF7_SHIFT                     (7U)
/*! ISF7 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF7_SHIFT)) & GPIO_ISFR_ISF7_MASK)

#define GPIO_ISFR_ISF8_MASK                      (0x100U)
#define GPIO_ISFR_ISF8_SHIFT                     (8U)
/*! ISF8 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF8_SHIFT)) & GPIO_ISFR_ISF8_MASK)

#define GPIO_ISFR_ISF9_MASK                      (0x200U)
#define GPIO_ISFR_ISF9_SHIFT                     (9U)
/*! ISF9 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF9_SHIFT)) & GPIO_ISFR_ISF9_MASK)

#define GPIO_ISFR_ISF10_MASK                     (0x400U)
#define GPIO_ISFR_ISF10_SHIFT                    (10U)
/*! ISF10 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF10_SHIFT)) & GPIO_ISFR_ISF10_MASK)

#define GPIO_ISFR_ISF11_MASK                     (0x800U)
#define GPIO_ISFR_ISF11_SHIFT                    (11U)
/*! ISF11 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF11_SHIFT)) & GPIO_ISFR_ISF11_MASK)

#define GPIO_ISFR_ISF12_MASK                     (0x1000U)
#define GPIO_ISFR_ISF12_SHIFT                    (12U)
/*! ISF12 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF12_SHIFT)) & GPIO_ISFR_ISF12_MASK)

#define GPIO_ISFR_ISF13_MASK                     (0x2000U)
#define GPIO_ISFR_ISF13_SHIFT                    (13U)
/*! ISF13 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF13_SHIFT)) & GPIO_ISFR_ISF13_MASK)

#define GPIO_ISFR_ISF14_MASK                     (0x4000U)
#define GPIO_ISFR_ISF14_SHIFT                    (14U)
/*! ISF14 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF14_SHIFT)) & GPIO_ISFR_ISF14_MASK)

#define GPIO_ISFR_ISF15_MASK                     (0x8000U)
#define GPIO_ISFR_ISF15_SHIFT                    (15U)
/*! ISF15 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF15_SHIFT)) & GPIO_ISFR_ISF15_MASK)

#define GPIO_ISFR_ISF16_MASK                     (0x10000U)
#define GPIO_ISFR_ISF16_SHIFT                    (16U)
/*! ISF16 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF16_SHIFT)) & GPIO_ISFR_ISF16_MASK)

#define GPIO_ISFR_ISF17_MASK                     (0x20000U)
#define GPIO_ISFR_ISF17_SHIFT                    (17U)
/*! ISF17 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF17_SHIFT)) & GPIO_ISFR_ISF17_MASK)

#define GPIO_ISFR_ISF18_MASK                     (0x40000U)
#define GPIO_ISFR_ISF18_SHIFT                    (18U)
/*! ISF18 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF18_SHIFT)) & GPIO_ISFR_ISF18_MASK)

#define GPIO_ISFR_ISF19_MASK                     (0x80000U)
#define GPIO_ISFR_ISF19_SHIFT                    (19U)
/*! ISF19 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF19_SHIFT)) & GPIO_ISFR_ISF19_MASK)

#define GPIO_ISFR_ISF20_MASK                     (0x100000U)
#define GPIO_ISFR_ISF20_SHIFT                    (20U)
/*! ISF20 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF20_SHIFT)) & GPIO_ISFR_ISF20_MASK)

#define GPIO_ISFR_ISF21_MASK                     (0x200000U)
#define GPIO_ISFR_ISF21_SHIFT                    (21U)
/*! ISF21 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF21_SHIFT)) & GPIO_ISFR_ISF21_MASK)

#define GPIO_ISFR_ISF22_MASK                     (0x400000U)
#define GPIO_ISFR_ISF22_SHIFT                    (22U)
/*! ISF22 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF22_SHIFT)) & GPIO_ISFR_ISF22_MASK)

#define GPIO_ISFR_ISF23_MASK                     (0x800000U)
#define GPIO_ISFR_ISF23_SHIFT                    (23U)
/*! ISF23 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF23_SHIFT)) & GPIO_ISFR_ISF23_MASK)

#define GPIO_ISFR_ISF24_MASK                     (0x1000000U)
#define GPIO_ISFR_ISF24_SHIFT                    (24U)
/*! ISF24 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF24_SHIFT)) & GPIO_ISFR_ISF24_MASK)

#define GPIO_ISFR_ISF25_MASK                     (0x2000000U)
#define GPIO_ISFR_ISF25_SHIFT                    (25U)
/*! ISF25 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF25_SHIFT)) & GPIO_ISFR_ISF25_MASK)

#define GPIO_ISFR_ISF26_MASK                     (0x4000000U)
#define GPIO_ISFR_ISF26_SHIFT                    (26U)
/*! ISF26 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF26_SHIFT)) & GPIO_ISFR_ISF26_MASK)

#define GPIO_ISFR_ISF27_MASK                     (0x8000000U)
#define GPIO_ISFR_ISF27_SHIFT                    (27U)
/*! ISF27 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF27_SHIFT)) & GPIO_ISFR_ISF27_MASK)

#define GPIO_ISFR_ISF28_MASK                     (0x10000000U)
#define GPIO_ISFR_ISF28_SHIFT                    (28U)
/*! ISF28 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF28_SHIFT)) & GPIO_ISFR_ISF28_MASK)

#define GPIO_ISFR_ISF29_MASK                     (0x20000000U)
#define GPIO_ISFR_ISF29_SHIFT                    (29U)
/*! ISF29 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF29_SHIFT)) & GPIO_ISFR_ISF29_MASK)

#define GPIO_ISFR_ISF30_MASK                     (0x40000000U)
#define GPIO_ISFR_ISF30_SHIFT                    (30U)
/*! ISF30 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF30_SHIFT)) & GPIO_ISFR_ISF30_MASK)

#define GPIO_ISFR_ISF31_MASK                     (0x80000000U)
#define GPIO_ISFR_ISF31_SHIFT                    (31U)
/*! ISF31 - Interrupt Status Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define GPIO_ISFR_ISF31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ISFR_ISF31_SHIFT)) & GPIO_ISFR_ISF31_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */

/* Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS   {GPIO00_IRQn, GPIO10_IRQn, GPIO20_IRQn, GPIO30_IRQn,GPIO40_IRQn,GPIO50_IRQn}
#define GPIO_IRQS_1 {GPIO01_IRQn, GPIO11_IRQn, GPIO21_IRQn, GPIO31_IRQn,GPIO41_IRQn,GPIO51_IRQn}


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


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


#endif  /* PERI_GPIO_H_ */

