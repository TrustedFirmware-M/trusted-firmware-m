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
**         CMSIS Peripheral Access Layer for CMC
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
 * @file PERI_CMC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CMC
 *
 * CMSIS Peripheral Access Layer for CMC
 */

#if !defined(PERI_CMC_H_)
#define PERI_CMC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_Peripheral_Access_Layer CMC Peripheral Access Layer
 * @{
 */

/** CMC - Size of Registers Arrays */
#define CMC_PMCTRL_COUNT                          2u
#define CMC_MR_COUNT                              1u
#define CMC_FM_COUNT                              1u
#define CMC_SRAMDIS_COUNT                         1u
#define CMC_SRAMRET_COUNT                         1u

/** CMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CKCTRL;                            /**< Clock Control, offset: 0x10 */
  __IO uint32_t CKSTAT;                            /**< Clock Status, offset: 0x14 */
  __IO uint32_t PMPROT;                            /**< Power Mode Protection, offset: 0x18 */
  __IO uint32_t GPMCTRL;                           /**< Global Power Mode Control, offset: 0x1C */
  __IO uint32_t PMCTRL[CMC_PMCTRL_COUNT];          /**< Power Mode Control, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[88];
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
       uint8_t RESERVED_7[28];
  __IO uint32_t BSR;                               /**< BootROM Status Register, offset: 0x100 */
       uint8_t RESERVED_8[8];
  __IO uint32_t BLR;                               /**< BootROM Lock Register, offset: 0x10C */
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
 *  0b0000..No clock gating
 *  0b0001..Core clock is gated
 *  0b1111..Core, platform, and peripheral clocks are gated, and core enters Low-Power mode.
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
 *  0b0000..Core clock not gated
 *  0b0001..Core clock was gated
 *  0b1111..Core, platform, and peripheral clocks were gated, and power domain entered Low-Power mode
 */
#define CMC_CKSTAT_CKMODE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_CKSTAT_CKMODE_SHIFT)) & CMC_CKSTAT_CKMODE_MASK)

#define CMC_CKSTAT_WAKEUP_MASK                   (0xFF00U)
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
 *  0b0000..Active/Sleep
 *  0b0001..Deep Sleep
 *  0b0011..Power Down
 *  0b0111..Reserved
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

#define CMC_SRS_VD_MASK                          (0x4U)
#define CMC_SRS_VD_SHIFT                         (2U)
/*! VD - Voltage Detect Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_VD(x)                            (((uint32_t)(((uint32_t)(x)) << CMC_SRS_VD_SHIFT)) & CMC_SRS_VD_MASK)

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

#define CMC_SRS_WWDT0_MASK                       (0x2000U)
#define CMC_SRS_WWDT0_SHIFT                      (13U)
/*! WWDT0 - Windowed Watchdog 0 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SRS_WWDT0(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WWDT0_SHIFT)) & CMC_SRS_WWDT0_MASK)

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

#define CMC_SRS_CPU1_MASK                        (0x10000U)
#define CMC_SRS_CPU1_SHIFT                       (16U)
/*! CPU1 - CPU1 System Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_CPU1(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_CPU1_SHIFT)) & CMC_SRS_CPU1_MASK)

#define CMC_SRS_VBAT_MASK                        (0x1000000U)
#define CMC_SRS_VBAT_SHIFT                       (24U)
/*! VBAT - VBAT System Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SRS_VBAT(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_VBAT_SHIFT)) & CMC_SRS_VBAT_MASK)

#define CMC_SRS_WWDT1_MASK                       (0x2000000U)
#define CMC_SRS_WWDT1_SHIFT                      (25U)
/*! WWDT1 - Windowed Watchdog 1 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SRS_WWDT1(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WWDT1_SHIFT)) & CMC_SRS_WWDT1_MASK)

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

#define CMC_SSRS_VD_MASK                         (0x4U)
#define CMC_SSRS_VD_SHIFT                        (2U)
/*! VD - Voltage Detect Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_VD(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_VD_SHIFT)) & CMC_SSRS_VD_MASK)

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

#define CMC_SSRS_WWDT0_MASK                      (0x2000U)
#define CMC_SSRS_WWDT0_SHIFT                     (13U)
/*! WWDT0 - Windowed Watchdog 0 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SSRS_WWDT0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WWDT0_SHIFT)) & CMC_SSRS_WWDT0_MASK)

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

#define CMC_SSRS_CPU1_MASK                       (0x10000U)
#define CMC_SSRS_CPU1_SHIFT                      (16U)
/*! CPU1 - CPU1 Reset
 *  0b0..Reset not generated from CPU1 reset source.
 *  0b1..Reset generated from CPU1 reset source.
 */
#define CMC_SSRS_CPU1(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_CPU1_SHIFT)) & CMC_SSRS_CPU1_MASK)

#define CMC_SSRS_VBAT_MASK                       (0x1000000U)
#define CMC_SSRS_VBAT_SHIFT                      (24U)
/*! VBAT - VBAT System Reset
 *  0b0..Reset not generated
 *  0b1..Reset generated
 */
#define CMC_SSRS_VBAT(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_VBAT_SHIFT)) & CMC_SSRS_VBAT_MASK)

#define CMC_SSRS_WWDT1_MASK                      (0x2000000U)
#define CMC_SSRS_WWDT1_SHIFT                     (25U)
/*! WWDT1 - Windowed Watchdog 1 Reset
 *  0b0..Reset is not generated
 *  0b1..Reset is generated
 */
#define CMC_SSRS_WWDT1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WWDT1_SHIFT)) & CMC_SSRS_WWDT1_MASK)

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

#define CMC_SRIE_SCG_MASK                        (0x1000U)
#define CMC_SRIE_SCG_SHIFT                       (12U)
/*! SCG - System Clock Generation Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_SCG(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_SCG_SHIFT)) & CMC_SRIE_SCG_MASK)

#define CMC_SRIE_WWDT0_MASK                      (0x2000U)
#define CMC_SRIE_WWDT0_SHIFT                     (13U)
/*! WWDT0 - Windowed Watchdog 0 Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_WWDT0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WWDT0_SHIFT)) & CMC_SRIE_WWDT0_MASK)

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

#define CMC_SRIE_CPU1_MASK                       (0x10000U)
#define CMC_SRIE_CPU1_SHIFT                      (16U)
/*! CPU1 - CPU1 Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_CPU1(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_CPU1_SHIFT)) & CMC_SRIE_CPU1_MASK)

#define CMC_SRIE_VBAT_MASK                       (0x1000000U)
#define CMC_SRIE_VBAT_SHIFT                      (24U)
/*! VBAT - VBAT System Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_VBAT(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_VBAT_SHIFT)) & CMC_SRIE_VBAT_MASK)

#define CMC_SRIE_WWDT1_MASK                      (0x2000000U)
#define CMC_SRIE_WWDT1_SHIFT                     (25U)
/*! WWDT1 - Windowed Watchdog 1 Reset
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CMC_SRIE_WWDT1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WWDT1_SHIFT)) & CMC_SRIE_WWDT1_MASK)

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

#define CMC_SRIF_WWDT0_MASK                      (0x2000U)
#define CMC_SRIF_WWDT0_SHIFT                     (13U)
/*! WWDT0 - Windowed Watchdog 0 Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_WWDT0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WWDT0_SHIFT)) & CMC_SRIF_WWDT0_MASK)

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

#define CMC_SRIF_CPU1_MASK                       (0x10000U)
#define CMC_SRIF_CPU1_SHIFT                      (16U)
/*! CPU1 - CPU1 Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_CPU1(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_CPU1_SHIFT)) & CMC_SRIF_CPU1_MASK)

#define CMC_SRIF_VBAT_MASK                       (0x1000000U)
#define CMC_SRIF_VBAT_SHIFT                      (24U)
/*! VBAT - VBAT System Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_VBAT(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_VBAT_SHIFT)) & CMC_SRIF_VBAT_MASK)

#define CMC_SRIF_WWDT1_MASK                      (0x2000000U)
#define CMC_SRIF_WWDT1_SHIFT                     (25U)
/*! WWDT1 - Windowed Watchdog 1 Reset
 *  0b0..Reset source not pending
 *  0b1..Reset source pending
 */
#define CMC_SRIF_WWDT1(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WWDT1_SHIFT)) & CMC_SRIF_WWDT1_MASK)

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
/*! ISPMODE_n - In System Programming Mode */
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

#define CMC_SRAMDIS_DIS0_MASK                    (0x1U)
#define CMC_SRAMDIS_DIS0_SHIFT                   (0U)
/*! DIS0 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS0(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS0_SHIFT)) & CMC_SRAMDIS_DIS0_MASK)

#define CMC_SRAMDIS_DIS1_MASK                    (0x2U)
#define CMC_SRAMDIS_DIS1_SHIFT                   (1U)
/*! DIS1 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS1(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS1_SHIFT)) & CMC_SRAMDIS_DIS1_MASK)

#define CMC_SRAMDIS_DIS2_MASK                    (0x4U)
#define CMC_SRAMDIS_DIS2_SHIFT                   (2U)
/*! DIS2 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS2(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS2_SHIFT)) & CMC_SRAMDIS_DIS2_MASK)

#define CMC_SRAMDIS_DIS3_MASK                    (0x8U)
#define CMC_SRAMDIS_DIS3_SHIFT                   (3U)
/*! DIS3 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS3(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS3_SHIFT)) & CMC_SRAMDIS_DIS3_MASK)

#define CMC_SRAMDIS_DIS4_MASK                    (0x10U)
#define CMC_SRAMDIS_DIS4_SHIFT                   (4U)
/*! DIS4 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS4(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS4_SHIFT)) & CMC_SRAMDIS_DIS4_MASK)

#define CMC_SRAMDIS_DIS5_MASK                    (0x20U)
#define CMC_SRAMDIS_DIS5_SHIFT                   (5U)
/*! DIS5 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS5(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS5_SHIFT)) & CMC_SRAMDIS_DIS5_MASK)

#define CMC_SRAMDIS_DIS6_MASK                    (0x40U)
#define CMC_SRAMDIS_DIS6_SHIFT                   (6U)
/*! DIS6 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS6(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS6_SHIFT)) & CMC_SRAMDIS_DIS6_MASK)

#define CMC_SRAMDIS_DIS7_MASK                    (0x80U)
#define CMC_SRAMDIS_DIS7_SHIFT                   (7U)
/*! DIS7 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS7(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS7_SHIFT)) & CMC_SRAMDIS_DIS7_MASK)

#define CMC_SRAMDIS_DIS8_MASK                    (0x100U)
#define CMC_SRAMDIS_DIS8_SHIFT                   (8U)
/*! DIS8 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS8(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS8_SHIFT)) & CMC_SRAMDIS_DIS8_MASK)

#define CMC_SRAMDIS_DIS9_MASK                    (0x200U)
#define CMC_SRAMDIS_DIS9_SHIFT                   (9U)
/*! DIS9 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS9(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS9_SHIFT)) & CMC_SRAMDIS_DIS9_MASK)

#define CMC_SRAMDIS_DIS10_MASK                   (0x400U)
#define CMC_SRAMDIS_DIS10_SHIFT                  (10U)
/*! DIS10 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS10(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS10_SHIFT)) & CMC_SRAMDIS_DIS10_MASK)

#define CMC_SRAMDIS_DIS11_MASK                   (0x800U)
#define CMC_SRAMDIS_DIS11_SHIFT                  (11U)
/*! DIS11 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS11(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS11_SHIFT)) & CMC_SRAMDIS_DIS11_MASK)

#define CMC_SRAMDIS_DIS12_MASK                   (0x1000U)
#define CMC_SRAMDIS_DIS12_SHIFT                  (12U)
/*! DIS12 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS12(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS12_SHIFT)) & CMC_SRAMDIS_DIS12_MASK)

#define CMC_SRAMDIS_DIS13_MASK                   (0x2000U)
#define CMC_SRAMDIS_DIS13_SHIFT                  (13U)
/*! DIS13 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS13(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS13_SHIFT)) & CMC_SRAMDIS_DIS13_MASK)

#define CMC_SRAMDIS_DIS14_MASK                   (0x4000U)
#define CMC_SRAMDIS_DIS14_SHIFT                  (14U)
/*! DIS14 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS14(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS14_SHIFT)) & CMC_SRAMDIS_DIS14_MASK)

#define CMC_SRAMDIS_DIS15_MASK                   (0x8000U)
#define CMC_SRAMDIS_DIS15_SHIFT                  (15U)
/*! DIS15 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS15(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS15_SHIFT)) & CMC_SRAMDIS_DIS15_MASK)

#define CMC_SRAMDIS_DIS16_MASK                   (0x10000U)
#define CMC_SRAMDIS_DIS16_SHIFT                  (16U)
/*! DIS16 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS16(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS16_SHIFT)) & CMC_SRAMDIS_DIS16_MASK)

#define CMC_SRAMDIS_DIS17_MASK                   (0x20000U)
#define CMC_SRAMDIS_DIS17_SHIFT                  (17U)
/*! DIS17 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS17(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS17_SHIFT)) & CMC_SRAMDIS_DIS17_MASK)

#define CMC_SRAMDIS_DIS18_MASK                   (0x40000U)
#define CMC_SRAMDIS_DIS18_SHIFT                  (18U)
/*! DIS18 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS18(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS18_SHIFT)) & CMC_SRAMDIS_DIS18_MASK)

#define CMC_SRAMDIS_DIS19_MASK                   (0x80000U)
#define CMC_SRAMDIS_DIS19_SHIFT                  (19U)
/*! DIS19 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS19(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS19_SHIFT)) & CMC_SRAMDIS_DIS19_MASK)

#define CMC_SRAMDIS_DIS20_MASK                   (0x100000U)
#define CMC_SRAMDIS_DIS20_SHIFT                  (20U)
/*! DIS20 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS20(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS20_SHIFT)) & CMC_SRAMDIS_DIS20_MASK)

#define CMC_SRAMDIS_DIS21_MASK                   (0x200000U)
#define CMC_SRAMDIS_DIS21_SHIFT                  (21U)
/*! DIS21 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS21(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS21_SHIFT)) & CMC_SRAMDIS_DIS21_MASK)

#define CMC_SRAMDIS_DIS22_MASK                   (0x400000U)
#define CMC_SRAMDIS_DIS22_SHIFT                  (22U)
/*! DIS22 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS22(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS22_SHIFT)) & CMC_SRAMDIS_DIS22_MASK)

#define CMC_SRAMDIS_DIS23_MASK                   (0x800000U)
#define CMC_SRAMDIS_DIS23_SHIFT                  (23U)
/*! DIS23 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS23(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS23_SHIFT)) & CMC_SRAMDIS_DIS23_MASK)

#define CMC_SRAMDIS_DIS24_MASK                   (0x1000000U)
#define CMC_SRAMDIS_DIS24_SHIFT                  (24U)
/*! DIS24 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS24(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS24_SHIFT)) & CMC_SRAMDIS_DIS24_MASK)

#define CMC_SRAMDIS_DIS25_MASK                   (0x2000000U)
#define CMC_SRAMDIS_DIS25_SHIFT                  (25U)
/*! DIS25 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS25(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS25_SHIFT)) & CMC_SRAMDIS_DIS25_MASK)

#define CMC_SRAMDIS_DIS26_MASK                   (0x4000000U)
#define CMC_SRAMDIS_DIS26_SHIFT                  (26U)
/*! DIS26 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS26(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS26_SHIFT)) & CMC_SRAMDIS_DIS26_MASK)

#define CMC_SRAMDIS_DIS27_MASK                   (0x8000000U)
#define CMC_SRAMDIS_DIS27_SHIFT                  (27U)
/*! DIS27 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS27(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS27_SHIFT)) & CMC_SRAMDIS_DIS27_MASK)

#define CMC_SRAMDIS_DIS28_MASK                   (0x10000000U)
#define CMC_SRAMDIS_DIS28_SHIFT                  (28U)
/*! DIS28 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS28(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS28_SHIFT)) & CMC_SRAMDIS_DIS28_MASK)

#define CMC_SRAMDIS_DIS29_MASK                   (0x20000000U)
#define CMC_SRAMDIS_DIS29_SHIFT                  (29U)
/*! DIS29 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS29(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS29_SHIFT)) & CMC_SRAMDIS_DIS29_MASK)

#define CMC_SRAMDIS_DIS30_MASK                   (0x40000000U)
#define CMC_SRAMDIS_DIS30_SHIFT                  (30U)
/*! DIS30 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS30(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS30_SHIFT)) & CMC_SRAMDIS_DIS30_MASK)

#define CMC_SRAMDIS_DIS31_MASK                   (0x80000000U)
#define CMC_SRAMDIS_DIS31_SHIFT                  (31U)
/*! DIS31 - SRAM Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define CMC_SRAMDIS_DIS31(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS31_SHIFT)) & CMC_SRAMDIS_DIS31_MASK)
/*! @} */

/*! @name SRAMRET - SRAM Retention */
/*! @{ */

#define CMC_SRAMRET_RET0_MASK                    (0x1U)
#define CMC_SRAMRET_RET0_SHIFT                   (0U)
/*! RET0 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET0(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET0_SHIFT)) & CMC_SRAMRET_RET0_MASK)

#define CMC_SRAMRET_RET1_MASK                    (0x2U)
#define CMC_SRAMRET_RET1_SHIFT                   (1U)
/*! RET1 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET1(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET1_SHIFT)) & CMC_SRAMRET_RET1_MASK)

#define CMC_SRAMRET_RET2_MASK                    (0x4U)
#define CMC_SRAMRET_RET2_SHIFT                   (2U)
/*! RET2 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET2(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET2_SHIFT)) & CMC_SRAMRET_RET2_MASK)

#define CMC_SRAMRET_RET3_MASK                    (0x8U)
#define CMC_SRAMRET_RET3_SHIFT                   (3U)
/*! RET3 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET3(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET3_SHIFT)) & CMC_SRAMRET_RET3_MASK)

#define CMC_SRAMRET_RET4_MASK                    (0x10U)
#define CMC_SRAMRET_RET4_SHIFT                   (4U)
/*! RET4 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET4(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET4_SHIFT)) & CMC_SRAMRET_RET4_MASK)

#define CMC_SRAMRET_RET5_MASK                    (0x20U)
#define CMC_SRAMRET_RET5_SHIFT                   (5U)
/*! RET5 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET5(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET5_SHIFT)) & CMC_SRAMRET_RET5_MASK)

#define CMC_SRAMRET_RET6_MASK                    (0x40U)
#define CMC_SRAMRET_RET6_SHIFT                   (6U)
/*! RET6 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET6(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET6_SHIFT)) & CMC_SRAMRET_RET6_MASK)

#define CMC_SRAMRET_RET7_MASK                    (0x80U)
#define CMC_SRAMRET_RET7_SHIFT                   (7U)
/*! RET7 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET7(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET7_SHIFT)) & CMC_SRAMRET_RET7_MASK)

#define CMC_SRAMRET_RET8_MASK                    (0x100U)
#define CMC_SRAMRET_RET8_SHIFT                   (8U)
/*! RET8 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET8(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET8_SHIFT)) & CMC_SRAMRET_RET8_MASK)

#define CMC_SRAMRET_RET9_MASK                    (0x200U)
#define CMC_SRAMRET_RET9_SHIFT                   (9U)
/*! RET9 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET9(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET9_SHIFT)) & CMC_SRAMRET_RET9_MASK)

#define CMC_SRAMRET_RET10_MASK                   (0x400U)
#define CMC_SRAMRET_RET10_SHIFT                  (10U)
/*! RET10 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET10(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET10_SHIFT)) & CMC_SRAMRET_RET10_MASK)

#define CMC_SRAMRET_RET11_MASK                   (0x800U)
#define CMC_SRAMRET_RET11_SHIFT                  (11U)
/*! RET11 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET11(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET11_SHIFT)) & CMC_SRAMRET_RET11_MASK)

#define CMC_SRAMRET_RET12_MASK                   (0x1000U)
#define CMC_SRAMRET_RET12_SHIFT                  (12U)
/*! RET12 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET12(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET12_SHIFT)) & CMC_SRAMRET_RET12_MASK)

#define CMC_SRAMRET_RET13_MASK                   (0x2000U)
#define CMC_SRAMRET_RET13_SHIFT                  (13U)
/*! RET13 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET13(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET13_SHIFT)) & CMC_SRAMRET_RET13_MASK)

#define CMC_SRAMRET_RET14_MASK                   (0x4000U)
#define CMC_SRAMRET_RET14_SHIFT                  (14U)
/*! RET14 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET14(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET14_SHIFT)) & CMC_SRAMRET_RET14_MASK)

#define CMC_SRAMRET_RET15_MASK                   (0x8000U)
#define CMC_SRAMRET_RET15_SHIFT                  (15U)
/*! RET15 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET15(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET15_SHIFT)) & CMC_SRAMRET_RET15_MASK)

#define CMC_SRAMRET_RET16_MASK                   (0x10000U)
#define CMC_SRAMRET_RET16_SHIFT                  (16U)
/*! RET16 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET16(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET16_SHIFT)) & CMC_SRAMRET_RET16_MASK)

#define CMC_SRAMRET_RET17_MASK                   (0x20000U)
#define CMC_SRAMRET_RET17_SHIFT                  (17U)
/*! RET17 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET17(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET17_SHIFT)) & CMC_SRAMRET_RET17_MASK)

#define CMC_SRAMRET_RET18_MASK                   (0x40000U)
#define CMC_SRAMRET_RET18_SHIFT                  (18U)
/*! RET18 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET18(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET18_SHIFT)) & CMC_SRAMRET_RET18_MASK)

#define CMC_SRAMRET_RET19_MASK                   (0x80000U)
#define CMC_SRAMRET_RET19_SHIFT                  (19U)
/*! RET19 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET19(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET19_SHIFT)) & CMC_SRAMRET_RET19_MASK)

#define CMC_SRAMRET_RET20_MASK                   (0x100000U)
#define CMC_SRAMRET_RET20_SHIFT                  (20U)
/*! RET20 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET20(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET20_SHIFT)) & CMC_SRAMRET_RET20_MASK)

#define CMC_SRAMRET_RET21_MASK                   (0x200000U)
#define CMC_SRAMRET_RET21_SHIFT                  (21U)
/*! RET21 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET21(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET21_SHIFT)) & CMC_SRAMRET_RET21_MASK)

#define CMC_SRAMRET_RET22_MASK                   (0x400000U)
#define CMC_SRAMRET_RET22_SHIFT                  (22U)
/*! RET22 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET22(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET22_SHIFT)) & CMC_SRAMRET_RET22_MASK)

#define CMC_SRAMRET_RET23_MASK                   (0x800000U)
#define CMC_SRAMRET_RET23_SHIFT                  (23U)
/*! RET23 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET23(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET23_SHIFT)) & CMC_SRAMRET_RET23_MASK)

#define CMC_SRAMRET_RET24_MASK                   (0x1000000U)
#define CMC_SRAMRET_RET24_SHIFT                  (24U)
/*! RET24 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET24(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET24_SHIFT)) & CMC_SRAMRET_RET24_MASK)

#define CMC_SRAMRET_RET25_MASK                   (0x2000000U)
#define CMC_SRAMRET_RET25_SHIFT                  (25U)
/*! RET25 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET25(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET25_SHIFT)) & CMC_SRAMRET_RET25_MASK)

#define CMC_SRAMRET_RET26_MASK                   (0x4000000U)
#define CMC_SRAMRET_RET26_SHIFT                  (26U)
/*! RET26 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET26(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET26_SHIFT)) & CMC_SRAMRET_RET26_MASK)

#define CMC_SRAMRET_RET27_MASK                   (0x8000000U)
#define CMC_SRAMRET_RET27_SHIFT                  (27U)
/*! RET27 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET27(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET27_SHIFT)) & CMC_SRAMRET_RET27_MASK)

#define CMC_SRAMRET_RET28_MASK                   (0x10000000U)
#define CMC_SRAMRET_RET28_SHIFT                  (28U)
/*! RET28 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET28(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET28_SHIFT)) & CMC_SRAMRET_RET28_MASK)

#define CMC_SRAMRET_RET29_MASK                   (0x20000000U)
#define CMC_SRAMRET_RET29_SHIFT                  (29U)
/*! RET29 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET29(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET29_SHIFT)) & CMC_SRAMRET_RET29_MASK)

#define CMC_SRAMRET_RET30_MASK                   (0x40000000U)
#define CMC_SRAMRET_RET30_SHIFT                  (30U)
/*! RET30 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET30(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET30_SHIFT)) & CMC_SRAMRET_RET30_MASK)

#define CMC_SRAMRET_RET31_MASK                   (0x80000000U)
#define CMC_SRAMRET_RET31_SHIFT                  (31U)
/*! RET31 - SRAM Retention
 *  0b0..Retains
 *  0b1..Powers off
 */
#define CMC_SRAMRET_RET31(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET31_SHIFT)) & CMC_SRAMRET_RET31_MASK)
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
/*! @} */

/*! @name BSR - BootROM Status Register */
/*! @{ */

#define CMC_BSR_STAT_MASK                        (0xFFFFFFFFU)
#define CMC_BSR_STAT_SHIFT                       (0U)
/*! STAT - Provides status information written by the BootROM. */
#define CMC_BSR_STAT(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_BSR_STAT_SHIFT)) & CMC_BSR_STAT_MASK)
/*! @} */

/*! @name BLR - BootROM Lock Register */
/*! @{ */

#define CMC_BLR_LOCK_MASK                        (0x7U)
#define CMC_BLR_LOCK_SHIFT                       (0U)
/*! LOCK - Lock
 *  0b010..BootROM Status and Lock Registers can be written
 *  0b101..BootROM Status and Lock Registers cannot be written
 */
#define CMC_BLR_LOCK(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_BLR_LOCK_SHIFT)) & CMC_BLR_LOCK_MASK)
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

/* Backward compatibility for CMC */
#define CMC_SRAMDIS_DIS_MASK                     (0xFFFFFFFFU)
#define CMC_SRAMDIS_DIS_SHIFT                    (0U)
/*! DIS - SRAM Disable */
#define CMC_SRAMDIS_DIS(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRAMDIS_DIS_SHIFT)) & CMC_SRAMDIS_DIS_MASK)

#define CMC_SRAMRET_RET_MASK                     (0xFFFFFFFFU)
#define CMC_SRAMRET_RET_SHIFT                    (0U)
/*! RET - SRAM Retention */
#define CMC_SRAMRET_RET(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRAMRET_RET_SHIFT)) & CMC_SRAMRET_RET_MASK)


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

