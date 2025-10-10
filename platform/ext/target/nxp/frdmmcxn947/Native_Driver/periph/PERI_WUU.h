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
**         CMSIS Peripheral Access Layer for WUU
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
 * @file PERI_WUU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WUU
 *
 * CMSIS Peripheral Access Layer for WUU
 */

#if !defined(PERI_WUU_H_)
#define PERI_WUU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- WUU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WUU_Peripheral_Access_Layer WUU Peripheral Access Layer
 * @{
 */

/** WUU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t PE1;                               /**< Pin Enable 1, offset: 0x8 */
  __IO uint32_t PE2;                               /**< Pin Enable 2, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t ME;                                /**< Module Interrupt Enable, offset: 0x18 */
  __IO uint32_t DE;                                /**< Module DMA/Trigger Enable, offset: 0x1C */
  __IO uint32_t PF;                                /**< Pin Flag, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FILT;                              /**< Pin Filter, offset: 0x30 */
       uint8_t RESERVED_2[4];
  __IO uint32_t PDC1;                              /**< Pin DMA/Trigger Configuration 1, offset: 0x38 */
  __IO uint32_t PDC2;                              /**< Pin DMA/Trigger Configuration 2, offset: 0x3C */
       uint8_t RESERVED_3[8];
  __IO uint32_t FDC;                               /**< Pin Filter DMA/Trigger Configuration, offset: 0x48 */
       uint8_t RESERVED_4[4];
  __IO uint32_t PMC;                               /**< Pin Mode Configuration, offset: 0x50 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FMC;                               /**< Pin Filter Mode Configuration, offset: 0x58 */
} WUU_Type;

/* ----------------------------------------------------------------------------
   -- WUU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WUU_Register_Masks WUU Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define WUU_VERID_FEATURE_MASK                   (0xFFFFU)
#define WUU_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented
 *  0b0000000000000001..Support for DMA/Trigger generation from wake-up pins and filters enabled. Support for
 *                      external pin/filter detection during all power modes enabled.
 */
#define WUU_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_VERID_FEATURE_SHIFT)) & WUU_VERID_FEATURE_MASK)

#define WUU_VERID_MINOR_MASK                     (0xFF0000U)
#define WUU_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define WUU_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_VERID_MINOR_SHIFT)) & WUU_VERID_MINOR_MASK)

#define WUU_VERID_MAJOR_MASK                     (0xFF000000U)
#define WUU_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define WUU_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_VERID_MAJOR_SHIFT)) & WUU_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define WUU_PARAM_FILTERS_MASK                   (0xFFU)
#define WUU_PARAM_FILTERS_SHIFT                  (0U)
/*! FILTERS - Filter Number */
#define WUU_PARAM_FILTERS(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_FILTERS_SHIFT)) & WUU_PARAM_FILTERS_MASK)

#define WUU_PARAM_DMAS_MASK                      (0xFF00U)
#define WUU_PARAM_DMAS_SHIFT                     (8U)
/*! DMAS - DMA Number */
#define WUU_PARAM_DMAS(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_DMAS_SHIFT)) & WUU_PARAM_DMAS_MASK)

#define WUU_PARAM_MODULES_MASK                   (0xFF0000U)
#define WUU_PARAM_MODULES_SHIFT                  (16U)
/*! MODULES - Module Number */
#define WUU_PARAM_MODULES(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_MODULES_SHIFT)) & WUU_PARAM_MODULES_MASK)

#define WUU_PARAM_PINS_MASK                      (0xFF000000U)
#define WUU_PARAM_PINS_SHIFT                     (24U)
/*! PINS - Pin Number */
#define WUU_PARAM_PINS(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_PINS_SHIFT)) & WUU_PARAM_PINS_MASK)
/*! @} */

/*! @name PE1 - Pin Enable 1 */
/*! @{ */

#define WUU_PE1_WUPE0_MASK                       (0x3U)
#define WUU_PE1_WUPE0_SHIFT                      (0U)
/*! WUPE0 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE0(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE0_SHIFT)) & WUU_PE1_WUPE0_MASK)

#define WUU_PE1_WUPE1_MASK                       (0xCU)
#define WUU_PE1_WUPE1_SHIFT                      (2U)
/*! WUPE1 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE1(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE1_SHIFT)) & WUU_PE1_WUPE1_MASK)

#define WUU_PE1_WUPE2_MASK                       (0x30U)
#define WUU_PE1_WUPE2_SHIFT                      (4U)
/*! WUPE2 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE2(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE2_SHIFT)) & WUU_PE1_WUPE2_MASK)

#define WUU_PE1_WUPE3_MASK                       (0xC0U)
#define WUU_PE1_WUPE3_SHIFT                      (6U)
/*! WUPE3 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE3(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE3_SHIFT)) & WUU_PE1_WUPE3_MASK)

#define WUU_PE1_WUPE4_MASK                       (0x300U)
#define WUU_PE1_WUPE4_SHIFT                      (8U)
/*! WUPE4 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE4(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE4_SHIFT)) & WUU_PE1_WUPE4_MASK)

#define WUU_PE1_WUPE5_MASK                       (0xC00U)
#define WUU_PE1_WUPE5_SHIFT                      (10U)
/*! WUPE5 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE5(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE5_SHIFT)) & WUU_PE1_WUPE5_MASK)

#define WUU_PE1_WUPE6_MASK                       (0x3000U)
#define WUU_PE1_WUPE6_SHIFT                      (12U)
/*! WUPE6 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE6(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE6_SHIFT)) & WUU_PE1_WUPE6_MASK)

#define WUU_PE1_WUPE7_MASK                       (0xC000U)
#define WUU_PE1_WUPE7_SHIFT                      (14U)
/*! WUPE7 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE7(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE7_SHIFT)) & WUU_PE1_WUPE7_MASK)

#define WUU_PE1_WUPE8_MASK                       (0x30000U)
#define WUU_PE1_WUPE8_SHIFT                      (16U)
/*! WUPE8 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE8(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE8_SHIFT)) & WUU_PE1_WUPE8_MASK)

#define WUU_PE1_WUPE9_MASK                       (0xC0000U)
#define WUU_PE1_WUPE9_SHIFT                      (18U)
/*! WUPE9 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE9(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE9_SHIFT)) & WUU_PE1_WUPE9_MASK)

#define WUU_PE1_WUPE10_MASK                      (0x300000U)
#define WUU_PE1_WUPE10_SHIFT                     (20U)
/*! WUPE10 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE10(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE10_SHIFT)) & WUU_PE1_WUPE10_MASK)

#define WUU_PE1_WUPE11_MASK                      (0xC00000U)
#define WUU_PE1_WUPE11_SHIFT                     (22U)
/*! WUPE11 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE11(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE11_SHIFT)) & WUU_PE1_WUPE11_MASK)

#define WUU_PE1_WUPE12_MASK                      (0x3000000U)
#define WUU_PE1_WUPE12_SHIFT                     (24U)
/*! WUPE12 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE12(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE12_SHIFT)) & WUU_PE1_WUPE12_MASK)

#define WUU_PE1_WUPE13_MASK                      (0xC000000U)
#define WUU_PE1_WUPE13_SHIFT                     (26U)
/*! WUPE13 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE13(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE13_SHIFT)) & WUU_PE1_WUPE13_MASK)

#define WUU_PE1_WUPE14_MASK                      (0x30000000U)
#define WUU_PE1_WUPE14_SHIFT                     (28U)
/*! WUPE14 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE14(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE14_SHIFT)) & WUU_PE1_WUPE14_MASK)

#define WUU_PE1_WUPE15_MASK                      (0xC0000000U)
#define WUU_PE1_WUPE15_SHIFT                     (30U)
/*! WUPE15 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE15(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE15_SHIFT)) & WUU_PE1_WUPE15_MASK)
/*! @} */

/*! @name PE2 - Pin Enable 2 */
/*! @{ */

#define WUU_PE2_WUPE16_MASK                      (0x3U)
#define WUU_PE2_WUPE16_SHIFT                     (0U)
/*! WUPE16 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE16(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE16_SHIFT)) & WUU_PE2_WUPE16_MASK)

#define WUU_PE2_WUPE17_MASK                      (0xCU)
#define WUU_PE2_WUPE17_SHIFT                     (2U)
/*! WUPE17 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE17(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE17_SHIFT)) & WUU_PE2_WUPE17_MASK)

#define WUU_PE2_WUPE18_MASK                      (0x30U)
#define WUU_PE2_WUPE18_SHIFT                     (4U)
/*! WUPE18 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE18(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE18_SHIFT)) & WUU_PE2_WUPE18_MASK)

#define WUU_PE2_WUPE19_MASK                      (0xC0U)
#define WUU_PE2_WUPE19_SHIFT                     (6U)
/*! WUPE19 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE19(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE19_SHIFT)) & WUU_PE2_WUPE19_MASK)

#define WUU_PE2_WUPE20_MASK                      (0x300U)
#define WUU_PE2_WUPE20_SHIFT                     (8U)
/*! WUPE20 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE20(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE20_SHIFT)) & WUU_PE2_WUPE20_MASK)

#define WUU_PE2_WUPE21_MASK                      (0xC00U)
#define WUU_PE2_WUPE21_SHIFT                     (10U)
/*! WUPE21 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE21(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE21_SHIFT)) & WUU_PE2_WUPE21_MASK)

#define WUU_PE2_WUPE22_MASK                      (0x3000U)
#define WUU_PE2_WUPE22_SHIFT                     (12U)
/*! WUPE22 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE22(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE22_SHIFT)) & WUU_PE2_WUPE22_MASK)

#define WUU_PE2_WUPE23_MASK                      (0xC000U)
#define WUU_PE2_WUPE23_SHIFT                     (14U)
/*! WUPE23 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE23(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE23_SHIFT)) & WUU_PE2_WUPE23_MASK)

#define WUU_PE2_WUPE24_MASK                      (0x30000U)
#define WUU_PE2_WUPE24_SHIFT                     (16U)
/*! WUPE24 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE24(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE24_SHIFT)) & WUU_PE2_WUPE24_MASK)

#define WUU_PE2_WUPE25_MASK                      (0xC0000U)
#define WUU_PE2_WUPE25_SHIFT                     (18U)
/*! WUPE25 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE25(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE25_SHIFT)) & WUU_PE2_WUPE25_MASK)

#define WUU_PE2_WUPE26_MASK                      (0x300000U)
#define WUU_PE2_WUPE26_SHIFT                     (20U)
/*! WUPE26 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE26(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE26_SHIFT)) & WUU_PE2_WUPE26_MASK)

#define WUU_PE2_WUPE27_MASK                      (0xC00000U)
#define WUU_PE2_WUPE27_SHIFT                     (22U)
/*! WUPE27 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE27(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE27_SHIFT)) & WUU_PE2_WUPE27_MASK)

#define WUU_PE2_WUPE28_MASK                      (0x3000000U)
#define WUU_PE2_WUPE28_SHIFT                     (24U)
/*! WUPE28 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE28(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE28_SHIFT)) & WUU_PE2_WUPE28_MASK)

#define WUU_PE2_WUPE29_MASK                      (0xC000000U)
#define WUU_PE2_WUPE29_SHIFT                     (26U)
/*! WUPE29 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE29(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE29_SHIFT)) & WUU_PE2_WUPE29_MASK)

#define WUU_PE2_WUPE30_MASK                      (0x30000000U)
#define WUU_PE2_WUPE30_SHIFT                     (28U)
/*! WUPE30 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE30(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE30_SHIFT)) & WUU_PE2_WUPE30_MASK)

#define WUU_PE2_WUPE31_MASK                      (0xC0000000U)
#define WUU_PE2_WUPE31_SHIFT                     (30U)
/*! WUPE31 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE31(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE31_SHIFT)) & WUU_PE2_WUPE31_MASK)
/*! @} */

/*! @name ME - Module Interrupt Enable */
/*! @{ */

#define WUU_ME_WUME0_MASK                        (0x1U)
#define WUU_ME_WUME0_SHIFT                       (0U)
/*! WUME0 - Module Interrupt Wake-up Enable for Module 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME0(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME0_SHIFT)) & WUU_ME_WUME0_MASK)

#define WUU_ME_WUME1_MASK                        (0x2U)
#define WUU_ME_WUME1_SHIFT                       (1U)
/*! WUME1 - Module Interrupt Wake-up Enable for Module 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME1(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME1_SHIFT)) & WUU_ME_WUME1_MASK)

#define WUU_ME_WUME2_MASK                        (0x4U)
#define WUU_ME_WUME2_SHIFT                       (2U)
/*! WUME2 - Module Interrupt Wake-up Enable for Module 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME2(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME2_SHIFT)) & WUU_ME_WUME2_MASK)

#define WUU_ME_WUME3_MASK                        (0x8U)
#define WUU_ME_WUME3_SHIFT                       (3U)
/*! WUME3 - Module Interrupt Wake-up Enable for Module 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME3(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME3_SHIFT)) & WUU_ME_WUME3_MASK)

#define WUU_ME_WUME4_MASK                        (0x10U)
#define WUU_ME_WUME4_SHIFT                       (4U)
/*! WUME4 - Module Interrupt Wake-up Enable for Module 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME4(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME4_SHIFT)) & WUU_ME_WUME4_MASK)

#define WUU_ME_WUME5_MASK                        (0x20U)
#define WUU_ME_WUME5_SHIFT                       (5U)
/*! WUME5 - Module Interrupt Wake-up Enable for Module 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME5(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME5_SHIFT)) & WUU_ME_WUME5_MASK)

#define WUU_ME_WUME6_MASK                        (0x40U)
#define WUU_ME_WUME6_SHIFT                       (6U)
/*! WUME6 - Module Interrupt Wake-up Enable for Module 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME6(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME6_SHIFT)) & WUU_ME_WUME6_MASK)

#define WUU_ME_WUME7_MASK                        (0x80U)
#define WUU_ME_WUME7_SHIFT                       (7U)
/*! WUME7 - Module Interrupt Wake-up Enable for Module 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME7(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME7_SHIFT)) & WUU_ME_WUME7_MASK)

#define WUU_ME_WUME8_MASK                        (0x100U)
#define WUU_ME_WUME8_SHIFT                       (8U)
/*! WUME8 - Module Interrupt Wake-up Enable for Module 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME8(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME8_SHIFT)) & WUU_ME_WUME8_MASK)

#define WUU_ME_WUME9_MASK                        (0x200U)
#define WUU_ME_WUME9_SHIFT                       (9U)
/*! WUME9 - Module Interrupt Wake-up Enable for Module 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_ME_WUME9(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME9_SHIFT)) & WUU_ME_WUME9_MASK)
/*! @} */

/*! @name DE - Module DMA/Trigger Enable */
/*! @{ */

#define WUU_DE_WUDE0_MASK                        (0x1U)
#define WUU_DE_WUDE0_SHIFT                       (0U)
/*! WUDE0 - DMA/Trigger Wake-up Enable for Module 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE0(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE0_SHIFT)) & WUU_DE_WUDE0_MASK)

#define WUU_DE_WUDE1_MASK                        (0x2U)
#define WUU_DE_WUDE1_SHIFT                       (1U)
/*! WUDE1 - DMA/Trigger Wake-up Enable for Module 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE1(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE1_SHIFT)) & WUU_DE_WUDE1_MASK)

#define WUU_DE_WUDE2_MASK                        (0x4U)
#define WUU_DE_WUDE2_SHIFT                       (2U)
/*! WUDE2 - DMA/Trigger Wake-up Enable for Module 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE2(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE2_SHIFT)) & WUU_DE_WUDE2_MASK)

#define WUU_DE_WUDE3_MASK                        (0x8U)
#define WUU_DE_WUDE3_SHIFT                       (3U)
/*! WUDE3 - DMA/Trigger Wake-up Enable for Module 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE3(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE3_SHIFT)) & WUU_DE_WUDE3_MASK)

#define WUU_DE_WUDE4_MASK                        (0x10U)
#define WUU_DE_WUDE4_SHIFT                       (4U)
/*! WUDE4 - DMA/Trigger Wake-up Enable for Module 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE4(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE4_SHIFT)) & WUU_DE_WUDE4_MASK)

#define WUU_DE_WUDE5_MASK                        (0x20U)
#define WUU_DE_WUDE5_SHIFT                       (5U)
/*! WUDE5 - DMA/Trigger Wake-up Enable for Module 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE5(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE5_SHIFT)) & WUU_DE_WUDE5_MASK)

#define WUU_DE_WUDE6_MASK                        (0x40U)
#define WUU_DE_WUDE6_SHIFT                       (6U)
/*! WUDE6 - DMA/Trigger Wake-up Enable for Module 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE6(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE6_SHIFT)) & WUU_DE_WUDE6_MASK)

#define WUU_DE_WUDE7_MASK                        (0x80U)
#define WUU_DE_WUDE7_SHIFT                       (7U)
/*! WUDE7 - DMA/Trigger Wake-up Enable for Module 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE7(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE7_SHIFT)) & WUU_DE_WUDE7_MASK)

#define WUU_DE_WUDE8_MASK                        (0x100U)
#define WUU_DE_WUDE8_SHIFT                       (8U)
/*! WUDE8 - DMA/Trigger Wake-up Enable for Module 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE8(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE8_SHIFT)) & WUU_DE_WUDE8_MASK)

#define WUU_DE_WUDE9_MASK                        (0x200U)
#define WUU_DE_WUDE9_SHIFT                       (9U)
/*! WUDE9 - DMA/Trigger Wake-up Enable for Module 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define WUU_DE_WUDE9(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE9_SHIFT)) & WUU_DE_WUDE9_MASK)
/*! @} */

/*! @name PF - Pin Flag */
/*! @{ */

#define WUU_PF_WUF0_MASK                         (0x1U)
#define WUU_PF_WUF0_SHIFT                        (0U)
/*! WUF0 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF0(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF0_SHIFT)) & WUU_PF_WUF0_MASK)

#define WUU_PF_WUF1_MASK                         (0x2U)
#define WUU_PF_WUF1_SHIFT                        (1U)
/*! WUF1 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF1(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF1_SHIFT)) & WUU_PF_WUF1_MASK)

#define WUU_PF_WUF2_MASK                         (0x4U)
#define WUU_PF_WUF2_SHIFT                        (2U)
/*! WUF2 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF2(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF2_SHIFT)) & WUU_PF_WUF2_MASK)

#define WUU_PF_WUF3_MASK                         (0x8U)
#define WUU_PF_WUF3_SHIFT                        (3U)
/*! WUF3 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF3(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF3_SHIFT)) & WUU_PF_WUF3_MASK)

#define WUU_PF_WUF4_MASK                         (0x10U)
#define WUU_PF_WUF4_SHIFT                        (4U)
/*! WUF4 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF4(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF4_SHIFT)) & WUU_PF_WUF4_MASK)

#define WUU_PF_WUF5_MASK                         (0x20U)
#define WUU_PF_WUF5_SHIFT                        (5U)
/*! WUF5 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF5(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF5_SHIFT)) & WUU_PF_WUF5_MASK)

#define WUU_PF_WUF6_MASK                         (0x40U)
#define WUU_PF_WUF6_SHIFT                        (6U)
/*! WUF6 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF6(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF6_SHIFT)) & WUU_PF_WUF6_MASK)

#define WUU_PF_WUF7_MASK                         (0x80U)
#define WUU_PF_WUF7_SHIFT                        (7U)
/*! WUF7 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF7(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF7_SHIFT)) & WUU_PF_WUF7_MASK)

#define WUU_PF_WUF8_MASK                         (0x100U)
#define WUU_PF_WUF8_SHIFT                        (8U)
/*! WUF8 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF8(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF8_SHIFT)) & WUU_PF_WUF8_MASK)

#define WUU_PF_WUF9_MASK                         (0x200U)
#define WUU_PF_WUF9_SHIFT                        (9U)
/*! WUF9 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF9(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF9_SHIFT)) & WUU_PF_WUF9_MASK)

#define WUU_PF_WUF10_MASK                        (0x400U)
#define WUU_PF_WUF10_SHIFT                       (10U)
/*! WUF10 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF10(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF10_SHIFT)) & WUU_PF_WUF10_MASK)

#define WUU_PF_WUF11_MASK                        (0x800U)
#define WUU_PF_WUF11_SHIFT                       (11U)
/*! WUF11 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF11(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF11_SHIFT)) & WUU_PF_WUF11_MASK)

#define WUU_PF_WUF12_MASK                        (0x1000U)
#define WUU_PF_WUF12_SHIFT                       (12U)
/*! WUF12 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF12(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF12_SHIFT)) & WUU_PF_WUF12_MASK)

#define WUU_PF_WUF13_MASK                        (0x2000U)
#define WUU_PF_WUF13_SHIFT                       (13U)
/*! WUF13 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF13(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF13_SHIFT)) & WUU_PF_WUF13_MASK)

#define WUU_PF_WUF14_MASK                        (0x4000U)
#define WUU_PF_WUF14_SHIFT                       (14U)
/*! WUF14 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF14(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF14_SHIFT)) & WUU_PF_WUF14_MASK)

#define WUU_PF_WUF15_MASK                        (0x8000U)
#define WUU_PF_WUF15_SHIFT                       (15U)
/*! WUF15 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF15(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF15_SHIFT)) & WUU_PF_WUF15_MASK)

#define WUU_PF_WUF16_MASK                        (0x10000U)
#define WUU_PF_WUF16_SHIFT                       (16U)
/*! WUF16 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF16(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF16_SHIFT)) & WUU_PF_WUF16_MASK)

#define WUU_PF_WUF17_MASK                        (0x20000U)
#define WUU_PF_WUF17_SHIFT                       (17U)
/*! WUF17 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF17(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF17_SHIFT)) & WUU_PF_WUF17_MASK)

#define WUU_PF_WUF18_MASK                        (0x40000U)
#define WUU_PF_WUF18_SHIFT                       (18U)
/*! WUF18 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF18(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF18_SHIFT)) & WUU_PF_WUF18_MASK)

#define WUU_PF_WUF19_MASK                        (0x80000U)
#define WUU_PF_WUF19_SHIFT                       (19U)
/*! WUF19 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF19(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF19_SHIFT)) & WUU_PF_WUF19_MASK)

#define WUU_PF_WUF20_MASK                        (0x100000U)
#define WUU_PF_WUF20_SHIFT                       (20U)
/*! WUF20 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF20(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF20_SHIFT)) & WUU_PF_WUF20_MASK)

#define WUU_PF_WUF21_MASK                        (0x200000U)
#define WUU_PF_WUF21_SHIFT                       (21U)
/*! WUF21 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF21(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF21_SHIFT)) & WUU_PF_WUF21_MASK)

#define WUU_PF_WUF22_MASK                        (0x400000U)
#define WUU_PF_WUF22_SHIFT                       (22U)
/*! WUF22 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF22(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF22_SHIFT)) & WUU_PF_WUF22_MASK)

#define WUU_PF_WUF23_MASK                        (0x800000U)
#define WUU_PF_WUF23_SHIFT                       (23U)
/*! WUF23 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF23(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF23_SHIFT)) & WUU_PF_WUF23_MASK)

#define WUU_PF_WUF24_MASK                        (0x1000000U)
#define WUU_PF_WUF24_SHIFT                       (24U)
/*! WUF24 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF24(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF24_SHIFT)) & WUU_PF_WUF24_MASK)

#define WUU_PF_WUF25_MASK                        (0x2000000U)
#define WUU_PF_WUF25_SHIFT                       (25U)
/*! WUF25 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF25(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF25_SHIFT)) & WUU_PF_WUF25_MASK)

#define WUU_PF_WUF26_MASK                        (0x4000000U)
#define WUU_PF_WUF26_SHIFT                       (26U)
/*! WUF26 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF26(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF26_SHIFT)) & WUU_PF_WUF26_MASK)

#define WUU_PF_WUF27_MASK                        (0x8000000U)
#define WUU_PF_WUF27_SHIFT                       (27U)
/*! WUF27 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF27(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF27_SHIFT)) & WUU_PF_WUF27_MASK)

#define WUU_PF_WUF28_MASK                        (0x10000000U)
#define WUU_PF_WUF28_SHIFT                       (28U)
/*! WUF28 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF28(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF28_SHIFT)) & WUU_PF_WUF28_MASK)

#define WUU_PF_WUF29_MASK                        (0x20000000U)
#define WUU_PF_WUF29_SHIFT                       (29U)
/*! WUF29 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF29(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF29_SHIFT)) & WUU_PF_WUF29_MASK)

#define WUU_PF_WUF30_MASK                        (0x40000000U)
#define WUU_PF_WUF30_SHIFT                       (30U)
/*! WUF30 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF30(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF30_SHIFT)) & WUU_PF_WUF30_MASK)

#define WUU_PF_WUF31_MASK                        (0x80000000U)
#define WUU_PF_WUF31_SHIFT                       (31U)
/*! WUF31 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF31(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF31_SHIFT)) & WUU_PF_WUF31_MASK)
/*! @} */

/*! @name FILT - Pin Filter */
/*! @{ */

#define WUU_FILT_FILTSEL1_MASK                   (0x1FU)
#define WUU_FILT_FILTSEL1_SHIFT                  (0U)
/*! FILTSEL1 - Filter 1 Pin Select */
#define WUU_FILT_FILTSEL1(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTSEL1_SHIFT)) & WUU_FILT_FILTSEL1_MASK)

#define WUU_FILT_FILTE1_MASK                     (0x60U)
#define WUU_FILT_FILTE1_SHIFT                    (5U)
/*! FILTE1 - Filter 1 Enable
 *  0b00..Disable
 *  0b01..Enable (Detect on rising edge or high level)
 *  0b10..Enable (Detect on falling edge or low level)
 *  0b11..Enable (Detect on any edge)
 */
#define WUU_FILT_FILTE1(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTE1_SHIFT)) & WUU_FILT_FILTE1_MASK)

#define WUU_FILT_FILTF1_MASK                     (0x80U)
#define WUU_FILT_FILTF1_SHIFT                    (7U)
/*! FILTF1 - Filter 1 Flag
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_FILT_FILTF1(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTF1_SHIFT)) & WUU_FILT_FILTF1_MASK)

#define WUU_FILT_FILTSEL2_MASK                   (0x1F00U)
#define WUU_FILT_FILTSEL2_SHIFT                  (8U)
/*! FILTSEL2 - Filter 2 Pin Select */
#define WUU_FILT_FILTSEL2(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTSEL2_SHIFT)) & WUU_FILT_FILTSEL2_MASK)

#define WUU_FILT_FILTE2_MASK                     (0x6000U)
#define WUU_FILT_FILTE2_SHIFT                    (13U)
/*! FILTE2 - Filter 2 Enable
 *  0b00..Disable
 *  0b01..Enable (Detect on rising edge or high level)
 *  0b10..Enable (Detect on falling edge or low level)
 *  0b11..Enable (Detect on any edge)
 */
#define WUU_FILT_FILTE2(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTE2_SHIFT)) & WUU_FILT_FILTE2_MASK)

#define WUU_FILT_FILTF2_MASK                     (0x8000U)
#define WUU_FILT_FILTF2_SHIFT                    (15U)
/*! FILTF2 - Filter 2 Flag
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_FILT_FILTF2(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTF2_SHIFT)) & WUU_FILT_FILTF2_MASK)
/*! @} */

/*! @name PDC1 - Pin DMA/Trigger Configuration 1 */
/*! @{ */

#define WUU_PDC1_WUPDC0_MASK                     (0x3U)
#define WUU_PDC1_WUPDC0_SHIFT                    (0U)
/*! WUPDC0 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC0(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC0_SHIFT)) & WUU_PDC1_WUPDC0_MASK)

#define WUU_PDC1_WUPDC1_MASK                     (0xCU)
#define WUU_PDC1_WUPDC1_SHIFT                    (2U)
/*! WUPDC1 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC1(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC1_SHIFT)) & WUU_PDC1_WUPDC1_MASK)

#define WUU_PDC1_WUPDC2_MASK                     (0x30U)
#define WUU_PDC1_WUPDC2_SHIFT                    (4U)
/*! WUPDC2 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC2(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC2_SHIFT)) & WUU_PDC1_WUPDC2_MASK)

#define WUU_PDC1_WUPDC3_MASK                     (0xC0U)
#define WUU_PDC1_WUPDC3_SHIFT                    (6U)
/*! WUPDC3 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC3(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC3_SHIFT)) & WUU_PDC1_WUPDC3_MASK)

#define WUU_PDC1_WUPDC4_MASK                     (0x300U)
#define WUU_PDC1_WUPDC4_SHIFT                    (8U)
/*! WUPDC4 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC4(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC4_SHIFT)) & WUU_PDC1_WUPDC4_MASK)

#define WUU_PDC1_WUPDC5_MASK                     (0xC00U)
#define WUU_PDC1_WUPDC5_SHIFT                    (10U)
/*! WUPDC5 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC5(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC5_SHIFT)) & WUU_PDC1_WUPDC5_MASK)

#define WUU_PDC1_WUPDC6_MASK                     (0x3000U)
#define WUU_PDC1_WUPDC6_SHIFT                    (12U)
/*! WUPDC6 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC6(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC6_SHIFT)) & WUU_PDC1_WUPDC6_MASK)

#define WUU_PDC1_WUPDC7_MASK                     (0xC000U)
#define WUU_PDC1_WUPDC7_SHIFT                    (14U)
/*! WUPDC7 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC7(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC7_SHIFT)) & WUU_PDC1_WUPDC7_MASK)

#define WUU_PDC1_WUPDC8_MASK                     (0x30000U)
#define WUU_PDC1_WUPDC8_SHIFT                    (16U)
/*! WUPDC8 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC8(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC8_SHIFT)) & WUU_PDC1_WUPDC8_MASK)

#define WUU_PDC1_WUPDC9_MASK                     (0xC0000U)
#define WUU_PDC1_WUPDC9_SHIFT                    (18U)
/*! WUPDC9 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC9(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC9_SHIFT)) & WUU_PDC1_WUPDC9_MASK)

#define WUU_PDC1_WUPDC10_MASK                    (0x300000U)
#define WUU_PDC1_WUPDC10_SHIFT                   (20U)
/*! WUPDC10 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC10(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC10_SHIFT)) & WUU_PDC1_WUPDC10_MASK)

#define WUU_PDC1_WUPDC11_MASK                    (0xC00000U)
#define WUU_PDC1_WUPDC11_SHIFT                   (22U)
/*! WUPDC11 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC11(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC11_SHIFT)) & WUU_PDC1_WUPDC11_MASK)

#define WUU_PDC1_WUPDC12_MASK                    (0x3000000U)
#define WUU_PDC1_WUPDC12_SHIFT                   (24U)
/*! WUPDC12 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC12(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC12_SHIFT)) & WUU_PDC1_WUPDC12_MASK)

#define WUU_PDC1_WUPDC13_MASK                    (0xC000000U)
#define WUU_PDC1_WUPDC13_SHIFT                   (26U)
/*! WUPDC13 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC13(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC13_SHIFT)) & WUU_PDC1_WUPDC13_MASK)

#define WUU_PDC1_WUPDC14_MASK                    (0x30000000U)
#define WUU_PDC1_WUPDC14_SHIFT                   (28U)
/*! WUPDC14 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC14(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC14_SHIFT)) & WUU_PDC1_WUPDC14_MASK)

#define WUU_PDC1_WUPDC15_MASK                    (0xC0000000U)
#define WUU_PDC1_WUPDC15_SHIFT                   (30U)
/*! WUPDC15 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC15(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC15_SHIFT)) & WUU_PDC1_WUPDC15_MASK)
/*! @} */

/*! @name PDC2 - Pin DMA/Trigger Configuration 2 */
/*! @{ */

#define WUU_PDC2_WUPDC16_MASK                    (0x3U)
#define WUU_PDC2_WUPDC16_SHIFT                   (0U)
/*! WUPDC16 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC16(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC16_SHIFT)) & WUU_PDC2_WUPDC16_MASK)

#define WUU_PDC2_WUPDC17_MASK                    (0xCU)
#define WUU_PDC2_WUPDC17_SHIFT                   (2U)
/*! WUPDC17 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC17(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC17_SHIFT)) & WUU_PDC2_WUPDC17_MASK)

#define WUU_PDC2_WUPDC18_MASK                    (0x30U)
#define WUU_PDC2_WUPDC18_SHIFT                   (4U)
/*! WUPDC18 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC18(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC18_SHIFT)) & WUU_PDC2_WUPDC18_MASK)

#define WUU_PDC2_WUPDC19_MASK                    (0xC0U)
#define WUU_PDC2_WUPDC19_SHIFT                   (6U)
/*! WUPDC19 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC19(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC19_SHIFT)) & WUU_PDC2_WUPDC19_MASK)

#define WUU_PDC2_WUPDC20_MASK                    (0x300U)
#define WUU_PDC2_WUPDC20_SHIFT                   (8U)
/*! WUPDC20 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC20(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC20_SHIFT)) & WUU_PDC2_WUPDC20_MASK)

#define WUU_PDC2_WUPDC21_MASK                    (0xC00U)
#define WUU_PDC2_WUPDC21_SHIFT                   (10U)
/*! WUPDC21 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC21(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC21_SHIFT)) & WUU_PDC2_WUPDC21_MASK)

#define WUU_PDC2_WUPDC22_MASK                    (0x3000U)
#define WUU_PDC2_WUPDC22_SHIFT                   (12U)
/*! WUPDC22 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC22(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC22_SHIFT)) & WUU_PDC2_WUPDC22_MASK)

#define WUU_PDC2_WUPDC23_MASK                    (0xC000U)
#define WUU_PDC2_WUPDC23_SHIFT                   (14U)
/*! WUPDC23 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC23(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC23_SHIFT)) & WUU_PDC2_WUPDC23_MASK)

#define WUU_PDC2_WUPDC24_MASK                    (0x30000U)
#define WUU_PDC2_WUPDC24_SHIFT                   (16U)
/*! WUPDC24 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC24(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC24_SHIFT)) & WUU_PDC2_WUPDC24_MASK)

#define WUU_PDC2_WUPDC25_MASK                    (0xC0000U)
#define WUU_PDC2_WUPDC25_SHIFT                   (18U)
/*! WUPDC25 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC25(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC25_SHIFT)) & WUU_PDC2_WUPDC25_MASK)

#define WUU_PDC2_WUPDC26_MASK                    (0x300000U)
#define WUU_PDC2_WUPDC26_SHIFT                   (20U)
/*! WUPDC26 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC26(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC26_SHIFT)) & WUU_PDC2_WUPDC26_MASK)

#define WUU_PDC2_WUPDC27_MASK                    (0xC00000U)
#define WUU_PDC2_WUPDC27_SHIFT                   (22U)
/*! WUPDC27 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC27(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC27_SHIFT)) & WUU_PDC2_WUPDC27_MASK)

#define WUU_PDC2_WUPDC28_MASK                    (0x3000000U)
#define WUU_PDC2_WUPDC28_SHIFT                   (24U)
/*! WUPDC28 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC28(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC28_SHIFT)) & WUU_PDC2_WUPDC28_MASK)

#define WUU_PDC2_WUPDC29_MASK                    (0xC000000U)
#define WUU_PDC2_WUPDC29_SHIFT                   (26U)
/*! WUPDC29 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC29(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC29_SHIFT)) & WUU_PDC2_WUPDC29_MASK)

#define WUU_PDC2_WUPDC30_MASK                    (0x30000000U)
#define WUU_PDC2_WUPDC30_SHIFT                   (28U)
/*! WUPDC30 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC30(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC30_SHIFT)) & WUU_PDC2_WUPDC30_MASK)

#define WUU_PDC2_WUPDC31_MASK                    (0xC0000000U)
#define WUU_PDC2_WUPDC31_SHIFT                   (30U)
/*! WUPDC31 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC31(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC31_SHIFT)) & WUU_PDC2_WUPDC31_MASK)
/*! @} */

/*! @name FDC - Pin Filter DMA/Trigger Configuration */
/*! @{ */

#define WUU_FDC_FILTC1_MASK                      (0x3U)
#define WUU_FDC_FILTC1_SHIFT                     (0U)
/*! FILTC1 - Filter Configuration for FILTn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_FDC_FILTC1(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FDC_FILTC1_SHIFT)) & WUU_FDC_FILTC1_MASK)

#define WUU_FDC_FILTC2_MASK                      (0xCU)
#define WUU_FDC_FILTC2_SHIFT                     (2U)
/*! FILTC2 - Filter Configuration for FILTn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_FDC_FILTC2(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FDC_FILTC2_SHIFT)) & WUU_FDC_FILTC2_MASK)
/*! @} */

/*! @name PMC - Pin Mode Configuration */
/*! @{ */

#define WUU_PMC_WUPMC0_MASK                      (0x1U)
#define WUU_PMC_WUPMC0_SHIFT                     (0U)
/*! WUPMC0 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC0(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC0_SHIFT)) & WUU_PMC_WUPMC0_MASK)

#define WUU_PMC_WUPMC1_MASK                      (0x2U)
#define WUU_PMC_WUPMC1_SHIFT                     (1U)
/*! WUPMC1 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC1(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC1_SHIFT)) & WUU_PMC_WUPMC1_MASK)

#define WUU_PMC_WUPMC2_MASK                      (0x4U)
#define WUU_PMC_WUPMC2_SHIFT                     (2U)
/*! WUPMC2 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC2(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC2_SHIFT)) & WUU_PMC_WUPMC2_MASK)

#define WUU_PMC_WUPMC3_MASK                      (0x8U)
#define WUU_PMC_WUPMC3_SHIFT                     (3U)
/*! WUPMC3 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC3(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC3_SHIFT)) & WUU_PMC_WUPMC3_MASK)

#define WUU_PMC_WUPMC4_MASK                      (0x10U)
#define WUU_PMC_WUPMC4_SHIFT                     (4U)
/*! WUPMC4 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC4(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC4_SHIFT)) & WUU_PMC_WUPMC4_MASK)

#define WUU_PMC_WUPMC5_MASK                      (0x20U)
#define WUU_PMC_WUPMC5_SHIFT                     (5U)
/*! WUPMC5 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC5(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC5_SHIFT)) & WUU_PMC_WUPMC5_MASK)

#define WUU_PMC_WUPMC6_MASK                      (0x40U)
#define WUU_PMC_WUPMC6_SHIFT                     (6U)
/*! WUPMC6 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC6(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC6_SHIFT)) & WUU_PMC_WUPMC6_MASK)

#define WUU_PMC_WUPMC7_MASK                      (0x80U)
#define WUU_PMC_WUPMC7_SHIFT                     (7U)
/*! WUPMC7 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC7(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC7_SHIFT)) & WUU_PMC_WUPMC7_MASK)

#define WUU_PMC_WUPMC8_MASK                      (0x100U)
#define WUU_PMC_WUPMC8_SHIFT                     (8U)
/*! WUPMC8 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC8(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC8_SHIFT)) & WUU_PMC_WUPMC8_MASK)

#define WUU_PMC_WUPMC9_MASK                      (0x200U)
#define WUU_PMC_WUPMC9_SHIFT                     (9U)
/*! WUPMC9 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC9(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC9_SHIFT)) & WUU_PMC_WUPMC9_MASK)

#define WUU_PMC_WUPMC10_MASK                     (0x400U)
#define WUU_PMC_WUPMC10_SHIFT                    (10U)
/*! WUPMC10 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC10(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC10_SHIFT)) & WUU_PMC_WUPMC10_MASK)

#define WUU_PMC_WUPMC11_MASK                     (0x800U)
#define WUU_PMC_WUPMC11_SHIFT                    (11U)
/*! WUPMC11 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC11(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC11_SHIFT)) & WUU_PMC_WUPMC11_MASK)

#define WUU_PMC_WUPMC12_MASK                     (0x1000U)
#define WUU_PMC_WUPMC12_SHIFT                    (12U)
/*! WUPMC12 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC12(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC12_SHIFT)) & WUU_PMC_WUPMC12_MASK)

#define WUU_PMC_WUPMC13_MASK                     (0x2000U)
#define WUU_PMC_WUPMC13_SHIFT                    (13U)
/*! WUPMC13 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC13(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC13_SHIFT)) & WUU_PMC_WUPMC13_MASK)

#define WUU_PMC_WUPMC14_MASK                     (0x4000U)
#define WUU_PMC_WUPMC14_SHIFT                    (14U)
/*! WUPMC14 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC14(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC14_SHIFT)) & WUU_PMC_WUPMC14_MASK)

#define WUU_PMC_WUPMC15_MASK                     (0x8000U)
#define WUU_PMC_WUPMC15_SHIFT                    (15U)
/*! WUPMC15 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC15(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC15_SHIFT)) & WUU_PMC_WUPMC15_MASK)

#define WUU_PMC_WUPMC16_MASK                     (0x10000U)
#define WUU_PMC_WUPMC16_SHIFT                    (16U)
/*! WUPMC16 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC16(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC16_SHIFT)) & WUU_PMC_WUPMC16_MASK)

#define WUU_PMC_WUPMC17_MASK                     (0x20000U)
#define WUU_PMC_WUPMC17_SHIFT                    (17U)
/*! WUPMC17 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC17(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC17_SHIFT)) & WUU_PMC_WUPMC17_MASK)

#define WUU_PMC_WUPMC18_MASK                     (0x40000U)
#define WUU_PMC_WUPMC18_SHIFT                    (18U)
/*! WUPMC18 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC18(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC18_SHIFT)) & WUU_PMC_WUPMC18_MASK)

#define WUU_PMC_WUPMC19_MASK                     (0x80000U)
#define WUU_PMC_WUPMC19_SHIFT                    (19U)
/*! WUPMC19 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC19(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC19_SHIFT)) & WUU_PMC_WUPMC19_MASK)

#define WUU_PMC_WUPMC20_MASK                     (0x100000U)
#define WUU_PMC_WUPMC20_SHIFT                    (20U)
/*! WUPMC20 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC20(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC20_SHIFT)) & WUU_PMC_WUPMC20_MASK)

#define WUU_PMC_WUPMC21_MASK                     (0x200000U)
#define WUU_PMC_WUPMC21_SHIFT                    (21U)
/*! WUPMC21 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC21(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC21_SHIFT)) & WUU_PMC_WUPMC21_MASK)

#define WUU_PMC_WUPMC22_MASK                     (0x400000U)
#define WUU_PMC_WUPMC22_SHIFT                    (22U)
/*! WUPMC22 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC22(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC22_SHIFT)) & WUU_PMC_WUPMC22_MASK)

#define WUU_PMC_WUPMC23_MASK                     (0x800000U)
#define WUU_PMC_WUPMC23_SHIFT                    (23U)
/*! WUPMC23 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC23(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC23_SHIFT)) & WUU_PMC_WUPMC23_MASK)

#define WUU_PMC_WUPMC24_MASK                     (0x1000000U)
#define WUU_PMC_WUPMC24_SHIFT                    (24U)
/*! WUPMC24 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC24(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC24_SHIFT)) & WUU_PMC_WUPMC24_MASK)

#define WUU_PMC_WUPMC25_MASK                     (0x2000000U)
#define WUU_PMC_WUPMC25_SHIFT                    (25U)
/*! WUPMC25 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC25(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC25_SHIFT)) & WUU_PMC_WUPMC25_MASK)

#define WUU_PMC_WUPMC26_MASK                     (0x4000000U)
#define WUU_PMC_WUPMC26_SHIFT                    (26U)
/*! WUPMC26 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC26(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC26_SHIFT)) & WUU_PMC_WUPMC26_MASK)

#define WUU_PMC_WUPMC27_MASK                     (0x8000000U)
#define WUU_PMC_WUPMC27_SHIFT                    (27U)
/*! WUPMC27 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC27(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC27_SHIFT)) & WUU_PMC_WUPMC27_MASK)

#define WUU_PMC_WUPMC28_MASK                     (0x10000000U)
#define WUU_PMC_WUPMC28_SHIFT                    (28U)
/*! WUPMC28 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC28(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC28_SHIFT)) & WUU_PMC_WUPMC28_MASK)

#define WUU_PMC_WUPMC29_MASK                     (0x20000000U)
#define WUU_PMC_WUPMC29_SHIFT                    (29U)
/*! WUPMC29 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC29(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC29_SHIFT)) & WUU_PMC_WUPMC29_MASK)

#define WUU_PMC_WUPMC30_MASK                     (0x40000000U)
#define WUU_PMC_WUPMC30_SHIFT                    (30U)
/*! WUPMC30 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC30(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC30_SHIFT)) & WUU_PMC_WUPMC30_MASK)

#define WUU_PMC_WUPMC31_MASK                     (0x80000000U)
#define WUU_PMC_WUPMC31_SHIFT                    (31U)
/*! WUPMC31 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC31(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC31_SHIFT)) & WUU_PMC_WUPMC31_MASK)
/*! @} */

/*! @name FMC - Pin Filter Mode Configuration */
/*! @{ */

#define WUU_FMC_FILTM1_MASK                      (0x1U)
#define WUU_FMC_FILTM1_SHIFT                     (0U)
/*! FILTM1 - Filter Mode for FILTn
 *  0b0..Active only during Power Down/Deep Power Down mode
 *  0b1..Active during all power modes
 */
#define WUU_FMC_FILTM1(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FMC_FILTM1_SHIFT)) & WUU_FMC_FILTM1_MASK)

#define WUU_FMC_FILTM2_MASK                      (0x2U)
#define WUU_FMC_FILTM2_SHIFT                     (1U)
/*! FILTM2 - Filter Mode for FILTn
 *  0b0..Active only during Power Down/Deep Power Down mode
 *  0b1..Active during all power modes
 */
#define WUU_FMC_FILTM2(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FMC_FILTM2_SHIFT)) & WUU_FMC_FILTM2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WUU_Register_Masks */


/*!
 * @}
 */ /* end of group WUU_Peripheral_Access_Layer */


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


#endif  /* PERI_WUU_H_ */

