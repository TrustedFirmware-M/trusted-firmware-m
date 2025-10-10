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
**         CMSIS Peripheral Access Layer for SCG
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
 * @file PERI_SCG.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SCG
 *
 * CMSIS Peripheral Access Layer for SCG
 */

#if !defined(PERI_SCG_H_)
#define PERI_SCG_H_                              /**< Symbol preventing repeated inclusion */

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
  __IO uint32_t TRIM_LOCK;                         /**< Trim Lock register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __I  uint32_t CSR;                               /**< Clock Status Register, offset: 0x10 */
  __IO uint32_t RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
       uint8_t RESERVED_1[232];
  __IO uint32_t SOSCCSR;                           /**< SOSC Control Status Register, offset: 0x100 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SOSCCFG;                           /**< SOSC Configuration Register, offset: 0x108 */
       uint8_t RESERVED_3[244];
  __IO uint32_t SIRCCSR;                           /**< SIRC Control Status Register, offset: 0x200 */
       uint8_t RESERVED_4[8];
  __IO uint32_t SIRCTCFG;                          /**< SIRC Trim Configuration Register, offset: 0x20C */
  __IO uint32_t SIRCTRIM;                          /**< SIRC Trim Register, offset: 0x210 */
       uint8_t RESERVED_5[4];
  __IO uint32_t SIRCSTAT;                          /**< SIRC Auto-trimming Status Register, offset: 0x218 */
       uint8_t RESERVED_6[228];
  __IO uint32_t FIRCCSR;                           /**< FIRC Control Status Register, offset: 0x300 */
       uint8_t RESERVED_7[4];
  __IO uint32_t FIRCCFG;                           /**< FIRC Configuration Register, offset: 0x308 */
  __IO uint32_t FIRCTCFG;                          /**< FIRC Trim Configuration Register, offset: 0x30C */
  __IO uint32_t FIRCTRIM;                          /**< FIRC Trim Register, offset: 0x310 */
       uint8_t RESERVED_8[4];
  __IO uint32_t FIRCSTAT;                          /**< FIRC Auto-trimming Status Register, offset: 0x318 */
       uint8_t RESERVED_9[228];
  __IO uint32_t ROSCCSR;                           /**< ROSC Control Status Register, offset: 0x400 */
       uint8_t RESERVED_10[252];
  __IO uint32_t APLLCSR;                           /**< APLL Control Status Register, offset: 0x500 */
  __IO uint32_t APLLCTRL;                          /**< APLL Control Register, offset: 0x504 */
  __I  uint32_t APLLSTAT;                          /**< APLL Status Register, offset: 0x508 */
  __IO uint32_t APLLNDIV;                          /**< APLL N Divider Register, offset: 0x50C */
  __IO uint32_t APLLMDIV;                          /**< APLL M Divider Register, offset: 0x510 */
  __IO uint32_t APLLPDIV;                          /**< APLL P Divider Register, offset: 0x514 */
  __IO uint32_t APLLLOCK_CNFG;                     /**< APLL LOCK Configuration Register, offset: 0x518 */
       uint8_t RESERVED_11[4];
  __I  uint32_t APLLSSCGSTAT;                      /**< APLL SSCG Status Register, offset: 0x520 */
  __IO uint32_t APLLSSCG0;                         /**< APLL Spread Spectrum Control 0 Register, offset: 0x524 */
  __IO uint32_t APLLSSCG1;                         /**< APLL Spread Spectrum Control 1 Register, offset: 0x528 */
       uint8_t RESERVED_12[200];
  __IO uint32_t APLL_OVRD;                         /**< APLL Override Register, offset: 0x5F4 */
       uint8_t RESERVED_13[8];
  __IO uint32_t SPLLCSR;                           /**< SPLL Control Status Register, offset: 0x600 */
  __IO uint32_t SPLLCTRL;                          /**< SPLL Control Register, offset: 0x604 */
  __I  uint32_t SPLLSTAT;                          /**< SPLL Status Register, offset: 0x608 */
  __IO uint32_t SPLLNDIV;                          /**< SPLL N Divider Register, offset: 0x60C */
  __IO uint32_t SPLLMDIV;                          /**< SPLL M Divider Register, offset: 0x610 */
  __IO uint32_t SPLLPDIV;                          /**< SPLL P Divider Register, offset: 0x614 */
  __IO uint32_t SPLLLOCK_CNFG;                     /**< SPLL LOCK Configuration Register, offset: 0x618 */
       uint8_t RESERVED_14[4];
  __I  uint32_t SPLLSSCGSTAT;                      /**< SPLL SSCG Status Register, offset: 0x620 */
  __IO uint32_t SPLLSSCG0;                         /**< SPLL Spread Spectrum Control 0 Register, offset: 0x624 */
  __IO uint32_t SPLLSSCG1;                         /**< SPLL Spread Spectrum Control 1 Register, offset: 0x628 */
       uint8_t RESERVED_15[200];
  __IO uint32_t SPLL_OVRD;                         /**< SPLL Override Register, offset: 0x6F4 */
       uint8_t RESERVED_16[8];
  __IO uint32_t UPLLCSR;                           /**< UPLL Control Status Register, offset: 0x700 */
       uint8_t RESERVED_17[252];
  __IO uint32_t LDOCSR;                            /**< LDO Control and Status Register, offset: 0x800 */
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

#define SCG_PARAM_APLLCLKPRES_MASK               (0x20U)
#define SCG_PARAM_APLLCLKPRES_SHIFT              (5U)
/*! APLLCLKPRES - APLL Clock Present
 *  0b0..APLL clock source is not present
 *  0b1..APLL clock source is present
 */
#define SCG_PARAM_APLLCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_APLLCLKPRES_SHIFT)) & SCG_PARAM_APLLCLKPRES_MASK)

#define SCG_PARAM_SPLLCLKPRES_MASK               (0x40U)
#define SCG_PARAM_SPLLCLKPRES_SHIFT              (6U)
/*! SPLLCLKPRES - SPLL Clock Present
 *  0b0..SPLL clock source is not present
 *  0b1..SPLL clock source is present
 */
#define SCG_PARAM_SPLLCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_SPLLCLKPRES_SHIFT)) & SCG_PARAM_SPLLCLKPRES_MASK)

#define SCG_PARAM_UPLLCLKPRES_MASK               (0x80U)
#define SCG_PARAM_UPLLCLKPRES_SHIFT              (7U)
/*! UPLLCLKPRES - UPLL Clock Present
 *  0b0..UPLL clock source is not present
 *  0b1..UPLL clock source is present
 */
#define SCG_PARAM_UPLLCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_UPLLCLKPRES_SHIFT)) & SCG_PARAM_UPLLCLKPRES_MASK)
/*! @} */

/*! @name TRIM_LOCK - Trim Lock register */
/*! @{ */

#define SCG_TRIM_LOCK_TRIM_UNLOCK_MASK           (0x1U)
#define SCG_TRIM_LOCK_TRIM_UNLOCK_SHIFT          (0U)
/*! TRIM_UNLOCK - TRIM_UNLOCK
 *  0b0..SCG Trim registers are locked and not writable.
 *  0b1..SCG Trim registers are unlocked and writable.
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

/*! @name CSR - Clock Status Register */
/*! @{ */

#define SCG_CSR_SCS_MASK                         (0xF000000U)
#define SCG_CSR_SCS_SHIFT                        (24U)
/*! SCS - System Clock Source
 *  0b0000..Reserved
 *  0b0001..SOSC
 *  0b0010..SIRC
 *  0b0011..FIRC
 *  0b0100..ROSC
 *  0b0101..APLL
 *  0b0110..SPLL
 *  0b0111..UPLL
 *  0b1000-0b1111..Reserved
 */
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x)) << SCG_CSR_SCS_SHIFT)) & SCG_CSR_SCS_MASK)
/*! @} */

/*! @name RCCR - Run Clock Control Register */
/*! @{ */

#define SCG_RCCR_SCS_MASK                        (0xF000000U)
#define SCG_RCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b0000..Reserved
 *  0b0001..SOSC
 *  0b0010..SIRC
 *  0b0011..FIRC
 *  0b0100..ROSC
 *  0b0101..APLL
 *  0b0110..SPLL
 *  0b0111..UPLL
 *  0b1000-0b1111..Reserved
 */
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_SCS_SHIFT)) & SCG_RCCR_SCS_MASK)
/*! @} */

/*! @name SOSCCSR - SOSC Control Status Register */
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
/*! LK - Lock Register
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
/*! @} */

/*! @name SOSCCFG - SOSC Configuration Register */
/*! @{ */

#define SCG_SOSCCFG_EREFS_MASK                   (0x4U)
#define SCG_SOSCCFG_EREFS_SHIFT                  (2U)
/*! EREFS - External Reference Select
 *  0b0..External reference clock selected. LDO can be disabled in this case.
 *  0b1..Internal crystal oscillator of OSC selected.
 */
#define SCG_SOSCCFG_EREFS(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_EREFS_SHIFT)) & SCG_SOSCCFG_EREFS_MASK)

#define SCG_SOSCCFG_RANGE_MASK                   (0x30U)
#define SCG_SOSCCFG_RANGE_SHIFT                  (4U)
/*! RANGE - SOSC Range Select
 *  0b00..Frequency range select of 16-20 MHz.
 *  0b01..Frequency range select of 20-30 MHz.
 *  0b10..Frequency range select of 30-50 MHz.
 *  0b11..Frequency range select of 50-66 MHz.
 */
#define SCG_SOSCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_RANGE_SHIFT)) & SCG_SOSCCFG_RANGE_MASK)
/*! @} */

/*! @name SIRCCSR - SIRC Control Status Register */
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
 *  0b0..SIRC coarse auto-trim is not bypassed
 *  0b1..SIRC coarse auto-trim is bypassed
 */
#define SCG_SIRCCSR_COARSE_TRIM_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_COARSE_TRIM_BYPASS_SHIFT)) & SCG_SIRCCSR_COARSE_TRIM_BYPASS_MASK)

#define SCG_SIRCCSR_LK_MASK                      (0x800000U)
#define SCG_SIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
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

/*! @name SIRCTCFG - SIRC Trim Configuration Register */
/*! @{ */

#define SCG_SIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_SIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..SOSC
 *  0b11..ROSC (32.768 kHz)
 */
#define SCG_SIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTCFG_TRIMSRC_SHIFT)) & SCG_SIRCTCFG_TRIMSRC_MASK)

#define SCG_SIRCTCFG_TRIMDIV_MASK                (0x7F0000U)
#define SCG_SIRCTCFG_TRIMDIV_SHIFT               (16U)
/*! TRIMDIV - SIRC Trim Predivider */
#define SCG_SIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTCFG_TRIMDIV_SHIFT)) & SCG_SIRCTCFG_TRIMDIV_MASK)
/*! @} */

/*! @name SIRCTRIM - SIRC Trim Register */
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

/*! @name SIRCSTAT - SIRC Auto-trimming Status Register */
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

/*! @name FIRCCSR - FIRC Control Status Register */
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
/*! FIRC_SCLK_PERIPH_EN - FIRC 48 MHz Clock to peripherals Enable
 *  0b0..FIRC 48 MHz to peripherals is disabled
 *  0b1..FIRC 48 MHz to peripherals is enabled
 */
#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK     (0x20U)
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT    (5U)
/*! FIRC_FCLK_PERIPH_EN - FIRC 144 MHz Clock to peripherals Enable
 *  0b0..FIRC 144 MHz to peripherals is disabled
 *  0b1..FIRC 144 MHz to peripherals is enabled
 */
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_FIRCTREN_MASK                (0x100U)
#define SCG_FIRCCSR_FIRCTREN_SHIFT               (8U)
/*! FIRCTREN - FIRC 144 MHz Trim Enable (FIRCCFG[RANGE]=1)
 *  0b0..Disables trimming FIRC to an external clock source
 *  0b1..Enables trimming FIRC to an external clock source
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
 *  0b0..FIRC coarse auto trim is not bypassed
 *  0b1..FIRC coarse auto trim is bypassed
 */
#define SCG_FIRCCSR_COARSE_TRIM_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_COARSE_TRIM_BYPASS_SHIFT)) & SCG_FIRCCSR_COARSE_TRIM_BYPASS_MASK)

#define SCG_FIRCCSR_LK_MASK                      (0x800000U)
#define SCG_FIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
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
 *  0b1..FIRC is enabled and output clock is accurate. The clock is accurate after 4096 clock cycles of 144 MHz
 *       (RANGE=1) or 1365 clock cycles of 48 MHz(RANGE=0) from the FIRC analog.
 */
#define SCG_FIRCCSR_FIRCACC(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCACC_SHIFT)) & SCG_FIRCCSR_FIRCACC_MASK)
/*! @} */

/*! @name FIRCCFG - FIRC Configuration Register */
/*! @{ */

#define SCG_FIRCCFG_RANGE_MASK                   (0x1U)
#define SCG_FIRCCFG_RANGE_SHIFT                  (0U)
/*! RANGE - Frequency Range
 *  0b0..48 MHz FIRC clock selected
 *  0b1..144 MHz FIRC clock selected
 */
#define SCG_FIRCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCFG_RANGE_SHIFT)) & SCG_FIRCCFG_RANGE_MASK)
/*! @} */

/*! @name FIRCTCFG - FIRC Trim Configuration Register */
/*! @{ */

#define SCG_FIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_FIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..USB0 Start of Frame (1 kHz). This option does not use TRIMDIV
 *  0b01..Reserved
 *  0b10..SOSC
 *  0b11..ROSC
 */
#define SCG_FIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMSRC_SHIFT)) & SCG_FIRCTCFG_TRIMSRC_MASK)

#define SCG_FIRCTCFG_TRIMDIV_MASK                (0x7F0000U)
#define SCG_FIRCTCFG_TRIMDIV_SHIFT               (16U)
/*! TRIMDIV - FIRC Trim Predivider */
#define SCG_FIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMDIV_SHIFT)) & SCG_FIRCTCFG_TRIMDIV_MASK)
/*! @} */

/*! @name FIRCTRIM - FIRC Trim Register */
/*! @{ */

#define SCG_FIRCTRIM_TRIMFINE_MASK               (0xFFU)
#define SCG_FIRCTRIM_TRIMFINE_SHIFT              (0U)
/*! TRIMFINE - Trim Fine */
#define SCG_FIRCTRIM_TRIMFINE(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMFINE_SHIFT)) & SCG_FIRCTRIM_TRIMFINE_MASK)

#define SCG_FIRCTRIM_TRIMCOAR_MASK               (0x3F00U)
#define SCG_FIRCTRIM_TRIMCOAR_SHIFT              (8U)
/*! TRIMCOAR - Trim Coarse */
#define SCG_FIRCTRIM_TRIMCOAR(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMCOAR_SHIFT)) & SCG_FIRCTRIM_TRIMCOAR_MASK)

#define SCG_FIRCTRIM_TRIMTEMP_MASK               (0x30000U)
#define SCG_FIRCTRIM_TRIMTEMP_SHIFT              (16U)
/*! TRIMTEMP - Trim Temperature */
#define SCG_FIRCTRIM_TRIMTEMP(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMTEMP_SHIFT)) & SCG_FIRCTRIM_TRIMTEMP_MASK)

#define SCG_FIRCTRIM_TRIMSTART_MASK              (0x3F000000U)
#define SCG_FIRCTRIM_TRIMSTART_SHIFT             (24U)
/*! TRIMSTART - Trim Start */
#define SCG_FIRCTRIM_TRIMSTART(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMSTART_SHIFT)) & SCG_FIRCTRIM_TRIMSTART_MASK)
/*! @} */

/*! @name FIRCSTAT - FIRC Auto-trimming Status Register */
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

/*! @name ROSCCSR - ROSC Control Status Register */
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
/*! LK - Lock Register
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
 *  0b1..ROSC Clock Monitor is enabled and detected an RTC loss of clock error
 */
#define SCG_ROSCCSR_ROSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCERR_SHIFT)) & SCG_ROSCCSR_ROSCERR_MASK)
/*! @} */

/*! @name APLLCSR - APLL Control Status Register */
/*! @{ */

#define SCG_APLLCSR_APLLPWREN_MASK               (0x1U)
#define SCG_APLLCSR_APLLPWREN_SHIFT              (0U)
/*! APLLPWREN - APLL Power Enable
 *  0b0..APLL clock is powered off
 *  0b1..APLL clock is powered on
 */
#define SCG_APLLCSR_APLLPWREN(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLPWREN_SHIFT)) & SCG_APLLCSR_APLLPWREN_MASK)

#define SCG_APLLCSR_APLLCLKEN_MASK               (0x2U)
#define SCG_APLLCSR_APLLCLKEN_SHIFT              (1U)
/*! APLLCLKEN - APLL Clock Enable
 *  0b0..APLL clock is disabled
 *  0b1..APLL clock is enabled
 */
#define SCG_APLLCSR_APLLCLKEN(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLCLKEN_SHIFT)) & SCG_APLLCSR_APLLCLKEN_MASK)

#define SCG_APLLCSR_APLLSTEN_MASK                (0x4U)
#define SCG_APLLCSR_APLLSTEN_SHIFT               (2U)
/*! APLLSTEN - APLL Stop Enable
 *  0b0..APLL is disabled in Deep Sleep mode
 *  0b1..APLL is enabled in Deep Sleep mode
 */
#define SCG_APLLCSR_APLLSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLSTEN_SHIFT)) & SCG_APLLCSR_APLLSTEN_MASK)

#define SCG_APLLCSR_APLLCM_MASK                  (0x10000U)
#define SCG_APLLCSR_APLLCM_SHIFT                 (16U)
/*! APLLCM - APLL Clock Monitor
 *  0b0..APLL Clock Monitor is disabled
 *  0b1..APLL Clock Monitor is enabled
 */
#define SCG_APLLCSR_APLLCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLCM_SHIFT)) & SCG_APLLCSR_APLLCM_MASK)

#define SCG_APLLCSR_APLLCMRE_MASK                (0x20000U)
#define SCG_APLLCSR_APLLCMRE_SHIFT               (17U)
/*! APLLCMRE - APLL Clock Monitor Reset Enable
 *  0b0..Clock monitor generates an interrupt when an error is detected
 *  0b1..Clock monitor generates a reset when an error is detected
 */
#define SCG_APLLCSR_APLLCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLCMRE_SHIFT)) & SCG_APLLCSR_APLLCMRE_MASK)

#define SCG_APLLCSR_LK_MASK                      (0x800000U)
#define SCG_APLLCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_APLLCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_LK_SHIFT)) & SCG_APLLCSR_LK_MASK)

#define SCG_APLLCSR_APLL_LOCK_MASK               (0x1000000U)
#define SCG_APLLCSR_APLL_LOCK_SHIFT              (24U)
/*! APLL_LOCK - APLL LOCK
 *  0b0..APLL is not powered on or not locked
 *  0b1..APLL is locked
 */
#define SCG_APLLCSR_APLL_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLL_LOCK_SHIFT)) & SCG_APLLCSR_APLL_LOCK_MASK)

#define SCG_APLLCSR_APLLSEL_MASK                 (0x2000000U)
#define SCG_APLLCSR_APLLSEL_SHIFT                (25U)
/*! APLLSEL - APLL Selected
 *  0b0..APLL is not the system clock source
 *  0b1..APLL is the system clock source
 */
#define SCG_APLLCSR_APLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLSEL_SHIFT)) & SCG_APLLCSR_APLLSEL_MASK)

#define SCG_APLLCSR_APLLERR_MASK                 (0x4000000U)
#define SCG_APLLCSR_APLLERR_SHIFT                (26U)
/*! APLLERR - APLL Clock Error
 *  0b0..APLL Clock Monitor is disabled or has not detected an error
 *  0b1..APLL Clock Monitor is enabled and detected an error
 */
#define SCG_APLLCSR_APLLERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLERR_SHIFT)) & SCG_APLLCSR_APLLERR_MASK)

#define SCG_APLLCSR_APLL_LOCK_IE_MASK            (0x40000000U)
#define SCG_APLLCSR_APLL_LOCK_IE_SHIFT           (30U)
/*! APLL_LOCK_IE - APLL LOCK Interrupt Enable
 *  0b0..APLL_LOCK interrupt is not enabled
 *  0b1..APLL_LOCK interrupt is enabled
 */
#define SCG_APLLCSR_APLL_LOCK_IE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLL_LOCK_IE_SHIFT)) & SCG_APLLCSR_APLL_LOCK_IE_MASK)
/*! @} */

/*! @name APLLCTRL - APLL Control Register */
/*! @{ */

#define SCG_APLLCTRL_SELR_MASK                   (0xFU)
#define SCG_APLLCTRL_SELR_SHIFT                  (0U)
/*! SELR - Bandwidth select R (resistor) value. */
#define SCG_APLLCTRL_SELR(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_SELR_SHIFT)) & SCG_APLLCTRL_SELR_MASK)

#define SCG_APLLCTRL_SELI_MASK                   (0x3F0U)
#define SCG_APLLCTRL_SELI_SHIFT                  (4U)
/*! SELI - Bandwidth select I (integration) value. */
#define SCG_APLLCTRL_SELI(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_SELI_SHIFT)) & SCG_APLLCTRL_SELI_MASK)

#define SCG_APLLCTRL_SELP_MASK                   (0x7C00U)
#define SCG_APLLCTRL_SELP_SHIFT                  (10U)
/*! SELP - Bandwidth select P (proportional) value. */
#define SCG_APLLCTRL_SELP(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_SELP_SHIFT)) & SCG_APLLCTRL_SELP_MASK)

#define SCG_APLLCTRL_BYPASSPOSTDIV2_MASK         (0x10000U)
#define SCG_APLLCTRL_BYPASSPOSTDIV2_SHIFT        (16U)
/*! BYPASSPOSTDIV2 - Bypass of Divide-by-2 Divider
 *  0b0..Use the divide-by-2 divider in the postdivider
 *  0b1..Bypass of the divide-by-2 divider in the postdivider
 */
#define SCG_APLLCTRL_BYPASSPOSTDIV2(x)           (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_BYPASSPOSTDIV2_SHIFT)) & SCG_APLLCTRL_BYPASSPOSTDIV2_MASK)

#define SCG_APLLCTRL_LIMUPOFF_MASK               (0x20000U)
#define SCG_APLLCTRL_LIMUPOFF_SHIFT              (17U)
/*! LIMUPOFF - Up Limiter
 *  0b0..Application set to non-Spectrum and Fractional applications.
 *  0b1..Application set to Spectrum and Fractional applications.
 */
#define SCG_APLLCTRL_LIMUPOFF(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_LIMUPOFF_SHIFT)) & SCG_APLLCTRL_LIMUPOFF_MASK)

#define SCG_APLLCTRL_BANDDIRECT_MASK             (0x40000U)
#define SCG_APLLCTRL_BANDDIRECT_SHIFT            (18U)
/*! BANDDIRECT - Control of the bandwidth of the PLL.
 *  0b0..The bandwidth is changed synchronously with the feedback-divider
 *  0b1..Modifies the bandwidth of the PLL directly
 */
#define SCG_APLLCTRL_BANDDIRECT(x)               (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_BANDDIRECT_SHIFT)) & SCG_APLLCTRL_BANDDIRECT_MASK)

#define SCG_APLLCTRL_BYPASSPREDIV_MASK           (0x80000U)
#define SCG_APLLCTRL_BYPASSPREDIV_SHIFT          (19U)
/*! BYPASSPREDIV - Bypass of the predivider
 *  0b0..Use the predivider.
 *  0b1..Bypass of the predivider.
 */
#define SCG_APLLCTRL_BYPASSPREDIV(x)             (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_BYPASSPREDIV_SHIFT)) & SCG_APLLCTRL_BYPASSPREDIV_MASK)

#define SCG_APLLCTRL_BYPASSPOSTDIV_MASK          (0x100000U)
#define SCG_APLLCTRL_BYPASSPOSTDIV_SHIFT         (20U)
/*! BYPASSPOSTDIV - Bypass of the postdivider
 *  0b0..Use the postdivider.
 *  0b1..Bypass of the postdivider
 */
#define SCG_APLLCTRL_BYPASSPOSTDIV(x)            (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_BYPASSPOSTDIV_SHIFT)) & SCG_APLLCTRL_BYPASSPOSTDIV_MASK)

#define SCG_APLLCTRL_SOURCE_MASK                 (0x6000000U)
#define SCG_APLLCTRL_SOURCE_SHIFT                (25U)
/*! SOURCE - Clock Source
 *  0b00..SOSC
 *  0b01..FIRC 48 MHz clock. FIRC_SCLK_PERIPH_EN must be set to use FIRC 48 MHz clock.
 *  0b10..Reserved
 *  0b11..No clock
 */
#define SCG_APLLCTRL_SOURCE(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_APLLCTRL_SOURCE_SHIFT)) & SCG_APLLCTRL_SOURCE_MASK)
/*! @} */

/*! @name APLLSTAT - APLL Status Register */
/*! @{ */

#define SCG_APLLSTAT_NDIVACK_MASK                (0x2U)
#define SCG_APLLSTAT_NDIVACK_SHIFT               (1U)
/*! NDIVACK - Predivider(N) ratio change acknowledge.
 *  0b0..The predivider (N) ratio change is not accepted by the analog PLL
 *  0b1..The predivider (N) ratio change is accepted by the analog PLL
 */
#define SCG_APLLSTAT_NDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLSTAT_NDIVACK_SHIFT)) & SCG_APLLSTAT_NDIVACK_MASK)

#define SCG_APLLSTAT_MDIVACK_MASK                (0x4U)
#define SCG_APLLSTAT_MDIVACK_SHIFT               (2U)
/*! MDIVACK - Feedback(M) divider ratio change acknowledge.
 *  0b0..The feedback (M) ratio change is not accepted by the analog PLL
 *  0b1..The feedback (M) ratio change is accepted by the analog PLL
 */
#define SCG_APLLSTAT_MDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLSTAT_MDIVACK_SHIFT)) & SCG_APLLSTAT_MDIVACK_MASK)

#define SCG_APLLSTAT_PDIVACK_MASK                (0x8U)
#define SCG_APLLSTAT_PDIVACK_SHIFT               (3U)
/*! PDIVACK - Postdivider(P) ratio change acknowledge.
 *  0b0..The postdivider (P) ratio change is not accepted by the analog PLL
 *  0b1..The postdivider (P) ratio change is accepted by the analog PLL
 */
#define SCG_APLLSTAT_PDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLSTAT_PDIVACK_SHIFT)) & SCG_APLLSTAT_PDIVACK_MASK)
/*! @} */

/*! @name APLLNDIV - APLL N Divider Register */
/*! @{ */

#define SCG_APLLNDIV_NDIV_MASK                   (0xFFU)
#define SCG_APLLNDIV_NDIV_SHIFT                  (0U)
/*! NDIV - Predivider divider ratio (N-divider). */
#define SCG_APLLNDIV_NDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLNDIV_NDIV_SHIFT)) & SCG_APLLNDIV_NDIV_MASK)

#define SCG_APLLNDIV_NREQ_MASK                   (0x80000000U)
#define SCG_APLLNDIV_NREQ_SHIFT                  (31U)
/*! NREQ - Predivider ratio change request.
 *  0b0..Predivider ratio change is not requested
 *  0b1..Predivider ratio change is requested
 */
#define SCG_APLLNDIV_NREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLNDIV_NREQ_SHIFT)) & SCG_APLLNDIV_NREQ_MASK)
/*! @} */

/*! @name APLLMDIV - APLL M Divider Register */
/*! @{ */

#define SCG_APLLMDIV_MDIV_MASK                   (0xFFFFU)
#define SCG_APLLMDIV_MDIV_SHIFT                  (0U)
/*! MDIV - Feedback divider divider ratio (M-divider). */
#define SCG_APLLMDIV_MDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLMDIV_MDIV_SHIFT)) & SCG_APLLMDIV_MDIV_MASK)

#define SCG_APLLMDIV_MREQ_MASK                   (0x80000000U)
#define SCG_APLLMDIV_MREQ_SHIFT                  (31U)
/*! MREQ - Feedback ratio change request.
 *  0b0..Feedback ratio change is not requested
 *  0b1..Feedback ratio change is requested
 */
#define SCG_APLLMDIV_MREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLMDIV_MREQ_SHIFT)) & SCG_APLLMDIV_MREQ_MASK)
/*! @} */

/*! @name APLLPDIV - APLL P Divider Register */
/*! @{ */

#define SCG_APLLPDIV_PDIV_MASK                   (0x1FU)
#define SCG_APLLPDIV_PDIV_SHIFT                  (0U)
/*! PDIV - Postdivider divider ratio (P-divider) */
#define SCG_APLLPDIV_PDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLPDIV_PDIV_SHIFT)) & SCG_APLLPDIV_PDIV_MASK)

#define SCG_APLLPDIV_PREQ_MASK                   (0x80000000U)
#define SCG_APLLPDIV_PREQ_SHIFT                  (31U)
/*! PREQ - Postdivider ratio change request
 *  0b0..Postdivider ratio change is not requested
 *  0b1..Postdivider ratio change is requested
 */
#define SCG_APLLPDIV_PREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLPDIV_PREQ_SHIFT)) & SCG_APLLPDIV_PREQ_MASK)
/*! @} */

/*! @name APLLLOCK_CNFG - APLL LOCK Configuration Register */
/*! @{ */

#define SCG_APLLLOCK_CNFG_LOCK_TIME_MASK         (0x1FFFFU)
#define SCG_APLLLOCK_CNFG_LOCK_TIME_SHIFT        (0U)
/*! LOCK_TIME - Configures the number of reference clocks to count before APLL is considered locked. */
#define SCG_APLLLOCK_CNFG_LOCK_TIME(x)           (((uint32_t)(((uint32_t)(x)) << SCG_APLLLOCK_CNFG_LOCK_TIME_SHIFT)) & SCG_APLLLOCK_CNFG_LOCK_TIME_MASK)
/*! @} */

/*! @name APLLSSCGSTAT - APLL SSCG Status Register */
/*! @{ */

#define SCG_APLLSSCGSTAT_SS_MDIV_ACK_MASK        (0x1U)
#define SCG_APLLSSCGSTAT_SS_MDIV_ACK_SHIFT       (0U)
/*! SS_MDIV_ACK - SS_MDIV change acknowledge
 *  0b0..The SS_MDIV, MF, MR, and MC ratio change is not accepted by the analog PLL
 *  0b1..The SS_MDIV, MF, MR, and MC ratio change is accepted by the analog PLL
 */
#define SCG_APLLSSCGSTAT_SS_MDIV_ACK(x)          (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCGSTAT_SS_MDIV_ACK_SHIFT)) & SCG_APLLSSCGSTAT_SS_MDIV_ACK_MASK)
/*! @} */

/*! @name APLLSSCG0 - APLL Spread Spectrum Control 0 Register */
/*! @{ */

#define SCG_APLLSSCG0_SS_MDIV_LSB_MASK           (0xFFFFFFFFU)
#define SCG_APLLSSCG0_SS_MDIV_LSB_SHIFT          (0U)
/*! SS_MDIV_LSB - SS_MDIV */
#define SCG_APLLSSCG0_SS_MDIV_LSB(x)             (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG0_SS_MDIV_LSB_SHIFT)) & SCG_APLLSSCG0_SS_MDIV_LSB_MASK)
/*! @} */

/*! @name APLLSSCG1 - APLL Spread Spectrum Control 1 Register */
/*! @{ */

#define SCG_APLLSSCG1_SS_MDIV_MSB_MASK           (0x1U)
#define SCG_APLLSSCG1_SS_MDIV_MSB_SHIFT          (0U)
/*! SS_MDIV_MSB - SS_MDIV[32] */
#define SCG_APLLSSCG1_SS_MDIV_MSB(x)             (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_SS_MDIV_MSB_SHIFT)) & SCG_APLLSSCG1_SS_MDIV_MSB_MASK)

#define SCG_APLLSSCG1_SS_MDIV_REQ_MASK           (0x2U)
#define SCG_APLLSSCG1_SS_MDIV_REQ_SHIFT          (1U)
/*! SS_MDIV_REQ - SS_MDIV[32:0] change request.
 *  0b0..SS_MDIV change is not requested
 *  0b1..SS_MDIV change is requested
 */
#define SCG_APLLSSCG1_SS_MDIV_REQ(x)             (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_SS_MDIV_REQ_SHIFT)) & SCG_APLLSSCG1_SS_MDIV_REQ_MASK)

#define SCG_APLLSSCG1_MF_MASK                    (0x1CU)
#define SCG_APLLSSCG1_MF_SHIFT                   (2U)
/*! MF - Modulation Frequency Control */
#define SCG_APLLSSCG1_MF(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_MF_SHIFT)) & SCG_APLLSSCG1_MF_MASK)

#define SCG_APLLSSCG1_MR_MASK                    (0xE0U)
#define SCG_APLLSSCG1_MR_SHIFT                   (5U)
/*! MR - Modulation Depth Control */
#define SCG_APLLSSCG1_MR(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_MR_SHIFT)) & SCG_APLLSSCG1_MR_MASK)

#define SCG_APLLSSCG1_MC_MASK                    (0x300U)
#define SCG_APLLSSCG1_MC_SHIFT                   (8U)
/*! MC - Modulation Waveform Control
 *  0b00..MC[1:0] no compensation
 *  0b11..MC[1:0] maximum compensation
 */
#define SCG_APLLSSCG1_MC(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_MC_SHIFT)) & SCG_APLLSSCG1_MC_MASK)

#define SCG_APLLSSCG1_DITHER_MASK                (0x400U)
#define SCG_APLLSSCG1_DITHER_SHIFT               (10U)
/*! DITHER - Dither Enable
 *  0b0..Dither is not enabled
 *  0b1..Dither is enabled
 */
#define SCG_APLLSSCG1_DITHER(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_DITHER_SHIFT)) & SCG_APLLSSCG1_DITHER_MASK)

#define SCG_APLLSSCG1_SEL_SS_MDIV_MASK           (0x800U)
#define SCG_APLLSSCG1_SEL_SS_MDIV_SHIFT          (11U)
/*! SEL_SS_MDIV - SS_MDIV select.
 *  0b0..Feedback divider ratio is MDIV[15:0]
 *  0b1..Feedback divider ratio is SS_MDIV[32:0]
 */
#define SCG_APLLSSCG1_SEL_SS_MDIV(x)             (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_SEL_SS_MDIV_SHIFT)) & SCG_APLLSSCG1_SEL_SS_MDIV_MASK)

#define SCG_APLLSSCG1_SS_PD_MASK                 (0x80000000U)
#define SCG_APLLSSCG1_SS_PD_SHIFT                (31U)
/*! SS_PD - SSCG Power Down
 *  0b0..SSCG is powered on
 *  0b1..SSCG is powered off
 */
#define SCG_APLLSSCG1_SS_PD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_APLLSSCG1_SS_PD_SHIFT)) & SCG_APLLSSCG1_SS_PD_MASK)
/*! @} */

/*! @name APLL_OVRD - APLL Override Register */
/*! @{ */

#define SCG_APLL_OVRD_APLLPWREN_OVRD_MASK        (0x1U)
#define SCG_APLL_OVRD_APLLPWREN_OVRD_SHIFT       (0U)
/*! APLLPWREN_OVRD - APLL Power Enable Override if APLL_OVRD_EN=1
 *  0b0..APLL clock is powered off
 *  0b1..APLL clock is powered on
 */
#define SCG_APLL_OVRD_APLLPWREN_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << SCG_APLL_OVRD_APLLPWREN_OVRD_SHIFT)) & SCG_APLL_OVRD_APLLPWREN_OVRD_MASK)

#define SCG_APLL_OVRD_APLLCLKEN_OVRD_MASK        (0x2U)
#define SCG_APLL_OVRD_APLLCLKEN_OVRD_SHIFT       (1U)
/*! APLLCLKEN_OVRD - APLL Clock Enable Override if APLL_OVRD_EN=1
 *  0b0..APLL clock is disabled
 *  0b1..APLL clock is enabled
 */
#define SCG_APLL_OVRD_APLLCLKEN_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << SCG_APLL_OVRD_APLLCLKEN_OVRD_SHIFT)) & SCG_APLL_OVRD_APLLCLKEN_OVRD_MASK)

#define SCG_APLL_OVRD_APLL_OVRD_EN_MASK          (0x80000000U)
#define SCG_APLL_OVRD_APLL_OVRD_EN_SHIFT         (31U)
/*! APLL_OVRD_EN - APLL Override Enable
 *  0b0..APLL override is disabled
 *  0b1..APLL override is enabled
 */
#define SCG_APLL_OVRD_APLL_OVRD_EN(x)            (((uint32_t)(((uint32_t)(x)) << SCG_APLL_OVRD_APLL_OVRD_EN_SHIFT)) & SCG_APLL_OVRD_APLL_OVRD_EN_MASK)
/*! @} */

/*! @name SPLLCSR - SPLL Control Status Register */
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
/*! LK - Lock Register
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

/*! @name SPLLCTRL - SPLL Control Register */
/*! @{ */

#define SCG_SPLLCTRL_SELR_MASK                   (0xFU)
#define SCG_SPLLCTRL_SELR_SHIFT                  (0U)
/*! SELR - Bandwidth select R (resistor) value. */
#define SCG_SPLLCTRL_SELR(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SELR_SHIFT)) & SCG_SPLLCTRL_SELR_MASK)

#define SCG_SPLLCTRL_SELI_MASK                   (0x3F0U)
#define SCG_SPLLCTRL_SELI_SHIFT                  (4U)
/*! SELI - Bandwidth select I (integration) value. */
#define SCG_SPLLCTRL_SELI(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SELI_SHIFT)) & SCG_SPLLCTRL_SELI_MASK)

#define SCG_SPLLCTRL_SELP_MASK                   (0x7C00U)
#define SCG_SPLLCTRL_SELP_SHIFT                  (10U)
/*! SELP - Bandwidth select P (proportional) value. */
#define SCG_SPLLCTRL_SELP(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SELP_SHIFT)) & SCG_SPLLCTRL_SELP_MASK)

#define SCG_SPLLCTRL_BYPASSPOSTDIV2_MASK         (0x10000U)
#define SCG_SPLLCTRL_BYPASSPOSTDIV2_SHIFT        (16U)
/*! BYPASSPOSTDIV2 - Bypass of Divide-by-2 Divider
 *  0b0..Use the divide-by-2 divider in the postdivider.
 *  0b1..Bypass of the divide-by-2 divider in the postdivider
 */
#define SCG_SPLLCTRL_BYPASSPOSTDIV2(x)           (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_BYPASSPOSTDIV2_SHIFT)) & SCG_SPLLCTRL_BYPASSPOSTDIV2_MASK)

#define SCG_SPLLCTRL_LIMUPOFF_MASK               (0x20000U)
#define SCG_SPLLCTRL_LIMUPOFF_SHIFT              (17U)
/*! LIMUPOFF - Up Limiter.
 *  0b0..Application set to non-Spectrum and Fractional applications.
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
/*! BYPASSPREDIV - Bypass of the predivider.
 *  0b0..Use the predivider
 *  0b1..Bypass of the predivider
 */
#define SCG_SPLLCTRL_BYPASSPREDIV(x)             (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_BYPASSPREDIV_SHIFT)) & SCG_SPLLCTRL_BYPASSPREDIV_MASK)

#define SCG_SPLLCTRL_BYPASSPOSTDIV_MASK          (0x100000U)
#define SCG_SPLLCTRL_BYPASSPOSTDIV_SHIFT         (20U)
/*! BYPASSPOSTDIV - Bypass of the postdivider.
 *  0b0..Use the postdivider
 *  0b1..Bypass of the postdivider
 */
#define SCG_SPLLCTRL_BYPASSPOSTDIV(x)            (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_BYPASSPOSTDIV_SHIFT)) & SCG_SPLLCTRL_BYPASSPOSTDIV_MASK)

#define SCG_SPLLCTRL_SOURCE_MASK                 (0x6000000U)
#define SCG_SPLLCTRL_SOURCE_SHIFT                (25U)
/*! SOURCE - Clock Source
 *  0b00..SOSC
 *  0b01..FIRC 48 MHz clock. FIRC_SCLK_PERIPH_EN must be set to use FIRC 48 MHz clock.
 *  0b10..Reserved
 *  0b11..No clock
 */
#define SCG_SPLLCTRL_SOURCE(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCTRL_SOURCE_SHIFT)) & SCG_SPLLCTRL_SOURCE_MASK)
/*! @} */

/*! @name SPLLSTAT - SPLL Status Register */
/*! @{ */

#define SCG_SPLLSTAT_NDIVACK_MASK                (0x2U)
#define SCG_SPLLSTAT_NDIVACK_SHIFT               (1U)
/*! NDIVACK - Predivider (N) ratio change acknowledge
 *  0b0..The predivider (N) ratio change is not accepted by the analog PLL.
 *  0b1..The predivider (N) ratio change is accepted by the analog PLL.
 */
#define SCG_SPLLSTAT_NDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSTAT_NDIVACK_SHIFT)) & SCG_SPLLSTAT_NDIVACK_MASK)

#define SCG_SPLLSTAT_MDIVACK_MASK                (0x4U)
#define SCG_SPLLSTAT_MDIVACK_SHIFT               (2U)
/*! MDIVACK - Feedback (M) divider ratio change acknowledge
 *  0b0..The feedback (M) ratio change is not accepted by the analog PLL.
 *  0b1..The feedback (M) ratio change is accepted by the analog PLL.
 */
#define SCG_SPLLSTAT_MDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSTAT_MDIVACK_SHIFT)) & SCG_SPLLSTAT_MDIVACK_MASK)

#define SCG_SPLLSTAT_PDIVACK_MASK                (0x8U)
#define SCG_SPLLSTAT_PDIVACK_SHIFT               (3U)
/*! PDIVACK - Postdivider (P) ratio change acknowledge
 *  0b0..The postdivider (P) ratio change is not accepted by the analog PLL
 *  0b1..The postdivider (P) ratio change is accepted by the analog PLL
 */
#define SCG_SPLLSTAT_PDIVACK(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSTAT_PDIVACK_SHIFT)) & SCG_SPLLSTAT_PDIVACK_MASK)
/*! @} */

/*! @name SPLLNDIV - SPLL N Divider Register */
/*! @{ */

#define SCG_SPLLNDIV_NDIV_MASK                   (0xFFU)
#define SCG_SPLLNDIV_NDIV_SHIFT                  (0U)
/*! NDIV - Predivider divider ratio (N-divider). */
#define SCG_SPLLNDIV_NDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLNDIV_NDIV_SHIFT)) & SCG_SPLLNDIV_NDIV_MASK)

#define SCG_SPLLNDIV_NREQ_MASK                   (0x80000000U)
#define SCG_SPLLNDIV_NREQ_SHIFT                  (31U)
/*! NREQ - Predivider ratio change request.
 *  0b0..Predivider ratio change is not requested
 *  0b1..Predivider ratio change is requested
 */
#define SCG_SPLLNDIV_NREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLNDIV_NREQ_SHIFT)) & SCG_SPLLNDIV_NREQ_MASK)
/*! @} */

/*! @name SPLLMDIV - SPLL M Divider Register */
/*! @{ */

#define SCG_SPLLMDIV_MDIV_MASK                   (0xFFFFU)
#define SCG_SPLLMDIV_MDIV_SHIFT                  (0U)
/*! MDIV - Feedback divider divider ratio (M-divider). */
#define SCG_SPLLMDIV_MDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLMDIV_MDIV_SHIFT)) & SCG_SPLLMDIV_MDIV_MASK)

#define SCG_SPLLMDIV_MREQ_MASK                   (0x80000000U)
#define SCG_SPLLMDIV_MREQ_SHIFT                  (31U)
/*! MREQ - Feedback ratio change request.
 *  0b0..Feedback ratio change is not requested
 *  0b1..Feedback ratio change is requested
 */
#define SCG_SPLLMDIV_MREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLMDIV_MREQ_SHIFT)) & SCG_SPLLMDIV_MREQ_MASK)
/*! @} */

/*! @name SPLLPDIV - SPLL P Divider Register */
/*! @{ */

#define SCG_SPLLPDIV_PDIV_MASK                   (0x1FU)
#define SCG_SPLLPDIV_PDIV_SHIFT                  (0U)
/*! PDIV - Postdivider divider ratio (P-divider) */
#define SCG_SPLLPDIV_PDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPDIV_PDIV_SHIFT)) & SCG_SPLLPDIV_PDIV_MASK)

#define SCG_SPLLPDIV_PREQ_MASK                   (0x80000000U)
#define SCG_SPLLPDIV_PREQ_SHIFT                  (31U)
/*! PREQ - Postdivider ratio change request
 *  0b0..Postdivider ratio change is not requested
 *  0b1..Postdivider ratio change is requested
 */
#define SCG_SPLLPDIV_PREQ(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPDIV_PREQ_SHIFT)) & SCG_SPLLPDIV_PREQ_MASK)
/*! @} */

/*! @name SPLLLOCK_CNFG - SPLL LOCK Configuration Register */
/*! @{ */

#define SCG_SPLLLOCK_CNFG_LOCK_TIME_MASK         (0x1FFFFU)
#define SCG_SPLLLOCK_CNFG_LOCK_TIME_SHIFT        (0U)
/*! LOCK_TIME - Configures the number of reference clocks to count before SPLL is considered locked. */
#define SCG_SPLLLOCK_CNFG_LOCK_TIME(x)           (((uint32_t)(((uint32_t)(x)) << SCG_SPLLLOCK_CNFG_LOCK_TIME_SHIFT)) & SCG_SPLLLOCK_CNFG_LOCK_TIME_MASK)
/*! @} */

/*! @name SPLLSSCGSTAT - SPLL SSCG Status Register */
/*! @{ */

#define SCG_SPLLSSCGSTAT_SS_MDIV_ACK_MASK        (0x1U)
#define SCG_SPLLSSCGSTAT_SS_MDIV_ACK_SHIFT       (0U)
/*! SS_MDIV_ACK - SS_MDIV change acknowledge
 *  0b0..The SS_MDIV, MF, MR, and MC ratio change is not accepted by the analog PLL
 *  0b1..The SS_MDIV, MF, MR, and MC ratio change is accepted by the analog PLL
 */
#define SCG_SPLLSSCGSTAT_SS_MDIV_ACK(x)          (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCGSTAT_SS_MDIV_ACK_SHIFT)) & SCG_SPLLSSCGSTAT_SS_MDIV_ACK_MASK)
/*! @} */

/*! @name SPLLSSCG0 - SPLL Spread Spectrum Control 0 Register */
/*! @{ */

#define SCG_SPLLSSCG0_SS_MDIV_LSB_MASK           (0xFFFFFFFFU)
#define SCG_SPLLSSCG0_SS_MDIV_LSB_SHIFT          (0U)
/*! SS_MDIV_LSB - SS_MDIV[31:0] */
#define SCG_SPLLSSCG0_SS_MDIV_LSB(x)             (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSSCG0_SS_MDIV_LSB_SHIFT)) & SCG_SPLLSSCG0_SS_MDIV_LSB_MASK)
/*! @} */

/*! @name SPLLSSCG1 - SPLL Spread Spectrum Control 1 Register */
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
/*! MC - Modulation Waveform Control
 *  0b00..MC[1:0] no compensation
 *  0b11..MC[1:0] maximum compensation
 */
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

/*! @name SPLL_OVRD - SPLL Override Register */
/*! @{ */

#define SCG_SPLL_OVRD_SPLLPWREN_OVRD_MASK        (0x1U)
#define SCG_SPLL_OVRD_SPLLPWREN_OVRD_SHIFT       (0U)
/*! SPLLPWREN_OVRD - SPLL Power Enable Override if SPLL_OVRD_EN=1
 *  0b0..SPLL clock is powered off
 *  0b1..SPLL clock is powered on
 */
#define SCG_SPLL_OVRD_SPLLPWREN_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << SCG_SPLL_OVRD_SPLLPWREN_OVRD_SHIFT)) & SCG_SPLL_OVRD_SPLLPWREN_OVRD_MASK)

#define SCG_SPLL_OVRD_SPLLCLKEN_OVRD_MASK        (0x2U)
#define SCG_SPLL_OVRD_SPLLCLKEN_OVRD_SHIFT       (1U)
/*! SPLLCLKEN_OVRD - SPLL Clock Enable Override if SPLL_OVRD_EN=1
 *  0b0..SPLL clock is disabled
 *  0b1..SPLL clock is enabled
 */
#define SCG_SPLL_OVRD_SPLLCLKEN_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << SCG_SPLL_OVRD_SPLLCLKEN_OVRD_SHIFT)) & SCG_SPLL_OVRD_SPLLCLKEN_OVRD_MASK)

#define SCG_SPLL_OVRD_SPLL_OVRD_EN_MASK          (0x80000000U)
#define SCG_SPLL_OVRD_SPLL_OVRD_EN_SHIFT         (31U)
/*! SPLL_OVRD_EN - SPLL Override Enable
 *  0b0..SPLL override is disabled
 *  0b1..SPLL override is enabled
 */
#define SCG_SPLL_OVRD_SPLL_OVRD_EN(x)            (((uint32_t)(((uint32_t)(x)) << SCG_SPLL_OVRD_SPLL_OVRD_EN_SHIFT)) & SCG_SPLL_OVRD_SPLL_OVRD_EN_MASK)
/*! @} */

/*! @name UPLLCSR - UPLL Control Status Register */
/*! @{ */

#define SCG_UPLLCSR_UPLLCM_MASK                  (0x10000U)
#define SCG_UPLLCSR_UPLLCM_SHIFT                 (16U)
/*! UPLLCM - UPLL Clock Monitor
 *  0b0..UPLL Clock Monitor is disabled
 *  0b1..UPLL Clock Monitor is enabled
 */
#define SCG_UPLLCSR_UPLLCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_UPLLCSR_UPLLCM_SHIFT)) & SCG_UPLLCSR_UPLLCM_MASK)

#define SCG_UPLLCSR_UPLLCMRE_MASK                (0x20000U)
#define SCG_UPLLCSR_UPLLCMRE_SHIFT               (17U)
/*! UPLLCMRE - UPLL Clock Monitor Reset Enable
 *  0b0..Clock monitor generates an interrupt when an error is detected
 *  0b1..Clock monitor generates a reset when an error is detected
 */
#define SCG_UPLLCSR_UPLLCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_UPLLCSR_UPLLCMRE_SHIFT)) & SCG_UPLLCSR_UPLLCMRE_MASK)

#define SCG_UPLLCSR_LK_MASK                      (0x800000U)
#define SCG_UPLLCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_UPLLCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_UPLLCSR_LK_SHIFT)) & SCG_UPLLCSR_LK_MASK)

#define SCG_UPLLCSR_UPLLVLD_MASK                 (0x1000000U)
#define SCG_UPLLCSR_UPLLVLD_SHIFT                (24U)
/*! UPLLVLD - UPLL Valid
 *  0b0..UPLL is not enabled or clock is not valid
 *  0b1..UPLL is enabled and output clock is valid
 */
#define SCG_UPLLCSR_UPLLVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_UPLLCSR_UPLLVLD_SHIFT)) & SCG_UPLLCSR_UPLLVLD_MASK)

#define SCG_UPLLCSR_UPLLSEL_MASK                 (0x2000000U)
#define SCG_UPLLCSR_UPLLSEL_SHIFT                (25U)
/*! UPLLSEL - UPLL Selected
 *  0b0..UPLL is not the system clock source
 *  0b1..UPLL is the system clock source
 */
#define SCG_UPLLCSR_UPLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_UPLLCSR_UPLLSEL_SHIFT)) & SCG_UPLLCSR_UPLLSEL_MASK)

#define SCG_UPLLCSR_UPLLERR_MASK                 (0x4000000U)
#define SCG_UPLLCSR_UPLLERR_SHIFT                (26U)
/*! UPLLERR - UPLL Clock Error
 *  0b0..UPLL Clock Monitor is disabled or has not detected an error
 *  0b1..UPLL Clock Monitor is enabled and detected an error
 */
#define SCG_UPLLCSR_UPLLERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_UPLLCSR_UPLLERR_SHIFT)) & SCG_UPLLCSR_UPLLERR_MASK)
/*! @} */

/*! @name LDOCSR - LDO Control and Status Register */
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

