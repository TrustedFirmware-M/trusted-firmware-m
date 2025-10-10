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
**         CMSIS Peripheral Access Layer for SINC
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
 * @file PERI_SINC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SINC
 *
 * CMSIS Peripheral Access Layer for SINC
 */

#if !defined(PERI_SINC_H_)
#define PERI_SINC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- SINC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SINC_Peripheral_Access_Layer SINC Peripheral Access Layer
 * @{
 */

/** SINC - Size of Registers Arrays */
#define SINC_CHANNEL_COUNT                        5u

/** SINC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAMETER;                         /**< Parameters, offset: 0x4 */
  __IO uint32_t MCR;                               /**< Main Control, offset: 0x8 */
  __IO uint32_t NIE;                               /**< Normal Interrupt Enable, offset: 0xC */
  __IO uint32_t EIE;                               /**< Error Interrupt Enable, offset: 0x10 */
  __IO uint32_t FIFOIE;                            /**< FIFO And CAD Error Interrupt Enable, offset: 0x14 */
  __IO uint32_t NIS;                               /**< Normal Interrupt Status, offset: 0x18 */
  __IO uint32_t EIS;                               /**< Error Interrupt Status, offset: 0x1C */
  __IO uint32_t FIFOIS;                            /**< FIFO And CAD Error Interrupt Status, offset: 0x20 */
  __I  uint32_t SR;                                /**< Status, offset: 0x24 */
       uint8_t RESERVED_0[16];
  struct {                                         /* offset: 0x38, array step: 0x30 */
    __IO uint32_t CCR;                               /**< Channel 0 Control..Channel 4 Control, array offset: 0x38, array step: 0x30 */
    __IO uint32_t CDR;                               /**< Channel 0 Data Rate..Channel 4 Data Rate, array offset: 0x3C, array step: 0x30 */
    __IO uint32_t CCFR;                              /**< Channel 0 Configuration..Channel 4 Configuration, array offset: 0x40, array step: 0x30 */
    __IO uint32_t CPROT;                             /**< Channel 0 Protection..Channel 4 Protection, array offset: 0x44, array step: 0x30 */
    __IO uint32_t CBIAS;                             /**< Channel 0 Bias..Channel 4 Bias, array offset: 0x48, array step: 0x30 */
    __IO uint32_t CLOLMT;                            /**< Channel 0 Low Limit..Channel 4 Low Limit, array offset: 0x4C, array step: 0x30 */
    __IO uint32_t CHILMT;                            /**< Channel 0 High Limit..Channel 4 High Limit, array offset: 0x50, array step: 0x30 */
    __I  uint32_t CRDATA;                            /**< Channel 0 Result Data..Channel 4 Result Data, array offset: 0x54, array step: 0x30 */
    __IO uint32_t CMPDATA;                           /**< Channel 0 Multipurpose Data..Channel 4 Multipurpose Data, array offset: 0x58, array step: 0x30 */
    __IO uint32_t CACFR;                             /**< Channel 0 Advanced Configuration..Channel 4 Advanced Configuration, array offset: 0x5C, array step: 0x30 */
    __IO uint32_t CSR;                               /**< Channel 0 Status..Channel 4 Status, array offset: 0x60, array step: 0x30 */
    __I  uint32_t CDBGR;                             /**< Channel 0 Debug..Channel 4 Debug, array offset: 0x64, array step: 0x30 */
  } CHANNEL[SINC_CHANNEL_COUNT];
} SINC_Type;

/* ----------------------------------------------------------------------------
   -- SINC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SINC_Register_Masks SINC Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define SINC_VERID_FEATURE_MASK                  (0xFFFFU)
#define SINC_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Code */
#define SINC_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_VERID_FEATURE_SHIFT)) & SINC_VERID_FEATURE_MASK)

#define SINC_VERID_MINOR_MASK                    (0xFF0000U)
#define SINC_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number
 *  0b00000000..x.0
 */
#define SINC_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_VERID_MINOR_SHIFT)) & SINC_VERID_MINOR_MASK)

#define SINC_VERID_MAJOR_MASK                    (0xFF000000U)
#define SINC_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number
 *  0b00000001..1.x
 *  0b00000010..2.x
 */
#define SINC_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_VERID_MAJOR_SHIFT)) & SINC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAMETER - Parameters */
/*! @{ */

#define SINC_PARAMETER_FIFO_DEPTH_MASK           (0x1FU)
#define SINC_PARAMETER_FIFO_DEPTH_SHIFT          (0U)
/*! FIFO_DEPTH - FIFO Depth */
#define SINC_PARAMETER_FIFO_DEPTH(x)             (((uint32_t)(((uint32_t)(x)) << SINC_PARAMETER_FIFO_DEPTH_SHIFT)) & SINC_PARAMETER_FIFO_DEPTH_MASK)

#define SINC_PARAMETER_FLT_NUM_MASK              (0xF00U)
#define SINC_PARAMETER_FLT_NUM_SHIFT             (8U)
/*! FLT_NUM - Filter Channel Number */
#define SINC_PARAMETER_FLT_NUM(x)                (((uint32_t)(((uint32_t)(x)) << SINC_PARAMETER_FLT_NUM_SHIFT)) & SINC_PARAMETER_FLT_NUM_MASK)

#define SINC_PARAMETER_PF_ORD_SEL_MASK           (0x180000U)
#define SINC_PARAMETER_PF_ORD_SEL_SHIFT          (19U)
/*! PF_ORD_SEL - PF Order Select
 *  0b10..3
 *  0b11..2
 */
#define SINC_PARAMETER_PF_ORD_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SINC_PARAMETER_PF_ORD_SEL_SHIFT)) & SINC_PARAMETER_PF_ORD_SEL_MASK)
/*! @} */

/*! @name MCR - Main Control */
/*! @{ */

#define SINC_MCR_STRIG0_MASK                     (0x1U)
#define SINC_MCR_STRIG0_SHIFT                    (0U)
/*! STRIG0 - Software Trigger For Channel 0
 *  0b0..No effect
 *  0b1..Trigger
 */
#define SINC_MCR_STRIG0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG0_SHIFT)) & SINC_MCR_STRIG0_MASK)

#define SINC_MCR_STRIG1_MASK                     (0x2U)
#define SINC_MCR_STRIG1_SHIFT                    (1U)
/*! STRIG1 - Software Trigger For Channel 1
 *  0b0..No effect
 *  0b1..Trigger
 */
#define SINC_MCR_STRIG1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG1_SHIFT)) & SINC_MCR_STRIG1_MASK)

#define SINC_MCR_STRIG2_MASK                     (0x4U)
#define SINC_MCR_STRIG2_SHIFT                    (2U)
/*! STRIG2 - Software Trigger For Channel 2
 *  0b0..No effect
 *  0b1..Trigger
 */
#define SINC_MCR_STRIG2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG2_SHIFT)) & SINC_MCR_STRIG2_MASK)

#define SINC_MCR_STRIG3_MASK                     (0x8U)
#define SINC_MCR_STRIG3_SHIFT                    (3U)
/*! STRIG3 - Software Trigger For Channel 3
 *  0b0..No effect
 *  0b1..Trigger
 */
#define SINC_MCR_STRIG3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG3_SHIFT)) & SINC_MCR_STRIG3_MASK)

#define SINC_MCR_STRIG4_MASK                     (0x10U)
#define SINC_MCR_STRIG4_SHIFT                    (4U)
/*! STRIG4 - Software Trigger For Channel 4
 *  0b0..No effect
 *  0b1..Trigger
 */
#define SINC_MCR_STRIG4(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG4_SHIFT)) & SINC_MCR_STRIG4_MASK)

#define SINC_MCR_DOZEN_MASK                      (0x400U)
#define SINC_MCR_DOZEN_SHIFT                     (10U)
/*! DOZEN - Doze Or Stop Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define SINC_MCR_DOZEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_MCR_DOZEN_SHIFT)) & SINC_MCR_DOZEN_MASK)

#define SINC_MCR_RST_MASK                        (0x2000U)
#define SINC_MCR_RST_SHIFT                       (13U)
/*! RST - Software Reset
 *  0b0..Do not reset
 *  0b1..Reset
 */
#define SINC_MCR_RST(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_MCR_RST_SHIFT)) & SINC_MCR_RST_MASK)

#define SINC_MCR_MEN_MASK                        (0x8000U)
#define SINC_MCR_MEN_SHIFT                       (15U)
/*! MEN - Master Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_MCR_MEN(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MEN_SHIFT)) & SINC_MCR_MEN_MASK)

#define SINC_MCR_MCLKDIV_MASK                    (0xFF0000U)
#define SINC_MCR_MCLKDIV_SHIFT                   (16U)
/*! MCLKDIV - Modulator Clock Divider
 *  0b00000000..Prohibited
 *  *..Added to 1 to specify the clock divider
 */
#define SINC_MCR_MCLKDIV(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLKDIV_SHIFT)) & SINC_MCR_MCLKDIV_MASK)

#define SINC_MCR_PRESCALE_MASK                   (0x6000000U)
#define SINC_MCR_PRESCALE_SHIFT                  (25U)
/*! PRESCALE - Prescale Before Clock Divider
 *  0b00..No prescale
 *  0b01..2
 *  0b10..4
 *  0b11..8
 */
#define SINC_MCR_PRESCALE(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_PRESCALE_SHIFT)) & SINC_MCR_PRESCALE_MASK)

#define SINC_MCR_MCLK0DIS_MASK                   (0x8000000U)
#define SINC_MCR_MCLK0DIS_SHIFT                  (27U)
/*! MCLK0DIS - Disable Modulator Clock 0 Output
 *  0b0..Enabled when MEN = 1
 *  0b1..Disabled regardless of MEN value
 */
#define SINC_MCR_MCLK0DIS(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLK0DIS_SHIFT)) & SINC_MCR_MCLK0DIS_MASK)

#define SINC_MCR_MCLK1DIS_MASK                   (0x10000000U)
#define SINC_MCR_MCLK1DIS_SHIFT                  (28U)
/*! MCLK1DIS - Disable Modulator Clock 1 Output
 *  0b0..Enabled when MEN = 1
 *  0b1..Disabled regardless of MEN value
 */
#define SINC_MCR_MCLK1DIS(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLK1DIS_SHIFT)) & SINC_MCR_MCLK1DIS_MASK)

#define SINC_MCR_MCLK2DIS_MASK                   (0x20000000U)
#define SINC_MCR_MCLK2DIS_SHIFT                  (29U)
/*! MCLK2DIS - Disable Modulator Clock 2 Output
 *  0b0..Enabled when MEN = 1
 *  0b1..Disabled regardless of MEN value
 */
#define SINC_MCR_MCLK2DIS(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLK2DIS_SHIFT)) & SINC_MCR_MCLK2DIS_MASK)
/*! @} */

/*! @name NIE - Normal Interrupt Enable */
/*! @{ */

#define SINC_NIE_COCIE0_MASK                     (0x1U)
#define SINC_NIE_COCIE0_SHIFT                    (0U)
/*! COCIE0 - Conversion Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_COCIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE0_SHIFT)) & SINC_NIE_COCIE0_MASK)

#define SINC_NIE_COCIE1_MASK                     (0x2U)
#define SINC_NIE_COCIE1_SHIFT                    (1U)
/*! COCIE1 - Conversion Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_COCIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE1_SHIFT)) & SINC_NIE_COCIE1_MASK)

#define SINC_NIE_COCIE2_MASK                     (0x4U)
#define SINC_NIE_COCIE2_SHIFT                    (2U)
/*! COCIE2 - Conversion Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_COCIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE2_SHIFT)) & SINC_NIE_COCIE2_MASK)

#define SINC_NIE_COCIE3_MASK                     (0x8U)
#define SINC_NIE_COCIE3_SHIFT                    (3U)
/*! COCIE3 - Conversion Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_COCIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE3_SHIFT)) & SINC_NIE_COCIE3_MASK)

#define SINC_NIE_COCIE4_MASK                     (0x10U)
#define SINC_NIE_COCIE4_SHIFT                    (4U)
/*! COCIE4 - Conversion Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_COCIE4(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE4_SHIFT)) & SINC_NIE_COCIE4_MASK)

#define SINC_NIE_CHFIE0_MASK                     (0x100U)
#define SINC_NIE_CHFIE0_SHIFT                    (8U)
/*! CHFIE0 - Data Output Ready Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_CHFIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE0_SHIFT)) & SINC_NIE_CHFIE0_MASK)

#define SINC_NIE_CHFIE1_MASK                     (0x200U)
#define SINC_NIE_CHFIE1_SHIFT                    (9U)
/*! CHFIE1 - Data Output Ready Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_CHFIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE1_SHIFT)) & SINC_NIE_CHFIE1_MASK)

#define SINC_NIE_CHFIE2_MASK                     (0x400U)
#define SINC_NIE_CHFIE2_SHIFT                    (10U)
/*! CHFIE2 - Data Output Ready Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_CHFIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE2_SHIFT)) & SINC_NIE_CHFIE2_MASK)

#define SINC_NIE_CHFIE3_MASK                     (0x800U)
#define SINC_NIE_CHFIE3_SHIFT                    (11U)
/*! CHFIE3 - Data Output Ready Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_CHFIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE3_SHIFT)) & SINC_NIE_CHFIE3_MASK)

#define SINC_NIE_CHFIE4_MASK                     (0x1000U)
#define SINC_NIE_CHFIE4_SHIFT                    (12U)
/*! CHFIE4 - Data Output Ready Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_CHFIE4(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE4_SHIFT)) & SINC_NIE_CHFIE4_MASK)

#define SINC_NIE_ZCDIE0_MASK                     (0x10000U)
#define SINC_NIE_ZCDIE0_SHIFT                    (16U)
/*! ZCDIE0 - Zero Cross Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_ZCDIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE0_SHIFT)) & SINC_NIE_ZCDIE0_MASK)

#define SINC_NIE_ZCDIE1_MASK                     (0x20000U)
#define SINC_NIE_ZCDIE1_SHIFT                    (17U)
/*! ZCDIE1 - Zero Cross Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_ZCDIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE1_SHIFT)) & SINC_NIE_ZCDIE1_MASK)

#define SINC_NIE_ZCDIE2_MASK                     (0x40000U)
#define SINC_NIE_ZCDIE2_SHIFT                    (18U)
/*! ZCDIE2 - Zero Cross Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_ZCDIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE2_SHIFT)) & SINC_NIE_ZCDIE2_MASK)

#define SINC_NIE_ZCDIE3_MASK                     (0x80000U)
#define SINC_NIE_ZCDIE3_SHIFT                    (19U)
/*! ZCDIE3 - Zero Cross Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_ZCDIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE3_SHIFT)) & SINC_NIE_ZCDIE3_MASK)

#define SINC_NIE_ZCDIE4_MASK                     (0x100000U)
#define SINC_NIE_ZCDIE4_SHIFT                    (20U)
/*! ZCDIE4 - Zero Cross Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_NIE_ZCDIE4(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE4_SHIFT)) & SINC_NIE_ZCDIE4_MASK)
/*! @} */

/*! @name EIE - Error Interrupt Enable */
/*! @{ */

#define SINC_EIE_SCDIE0_MASK                     (0x1U)
#define SINC_EIE_SCDIE0_SHIFT                    (0U)
/*! SCDIE0 - Short Circuit Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_SCDIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE0_SHIFT)) & SINC_EIE_SCDIE0_MASK)

#define SINC_EIE_SCDIE1_MASK                     (0x2U)
#define SINC_EIE_SCDIE1_SHIFT                    (1U)
/*! SCDIE1 - Short Circuit Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_SCDIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE1_SHIFT)) & SINC_EIE_SCDIE1_MASK)

#define SINC_EIE_SCDIE2_MASK                     (0x4U)
#define SINC_EIE_SCDIE2_SHIFT                    (2U)
/*! SCDIE2 - Short Circuit Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_SCDIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE2_SHIFT)) & SINC_EIE_SCDIE2_MASK)

#define SINC_EIE_SCDIE3_MASK                     (0x8U)
#define SINC_EIE_SCDIE3_SHIFT                    (3U)
/*! SCDIE3 - Short Circuit Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_SCDIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE3_SHIFT)) & SINC_EIE_SCDIE3_MASK)

#define SINC_EIE_SCDIE4_MASK                     (0x10U)
#define SINC_EIE_SCDIE4_SHIFT                    (4U)
/*! SCDIE4 - Short Circuit Detected Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_SCDIE4(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE4_SHIFT)) & SINC_EIE_SCDIE4_MASK)

#define SINC_EIE_WLMTIE0_MASK                    (0x100U)
#define SINC_EIE_WLMTIE0_SHIFT                   (8U)
/*! WLMTIE0 - Window Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_WLMTIE0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE0_SHIFT)) & SINC_EIE_WLMTIE0_MASK)

#define SINC_EIE_WLMTIE1_MASK                    (0x200U)
#define SINC_EIE_WLMTIE1_SHIFT                   (9U)
/*! WLMTIE1 - Window Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_WLMTIE1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE1_SHIFT)) & SINC_EIE_WLMTIE1_MASK)

#define SINC_EIE_WLMTIE2_MASK                    (0x400U)
#define SINC_EIE_WLMTIE2_SHIFT                   (10U)
/*! WLMTIE2 - Window Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_WLMTIE2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE2_SHIFT)) & SINC_EIE_WLMTIE2_MASK)

#define SINC_EIE_WLMTIE3_MASK                    (0x800U)
#define SINC_EIE_WLMTIE3_SHIFT                   (11U)
/*! WLMTIE3 - Window Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_WLMTIE3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE3_SHIFT)) & SINC_EIE_WLMTIE3_MASK)

#define SINC_EIE_WLMTIE4_MASK                    (0x1000U)
#define SINC_EIE_WLMTIE4_SHIFT                   (12U)
/*! WLMTIE4 - Window Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_WLMTIE4(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE4_SHIFT)) & SINC_EIE_WLMTIE4_MASK)

#define SINC_EIE_LLMTIE0_MASK                    (0x10000U)
#define SINC_EIE_LLMTIE0_SHIFT                   (16U)
/*! LLMTIE0 - Low Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_LLMTIE0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE0_SHIFT)) & SINC_EIE_LLMTIE0_MASK)

#define SINC_EIE_LLMTIE1_MASK                    (0x20000U)
#define SINC_EIE_LLMTIE1_SHIFT                   (17U)
/*! LLMTIE1 - Low Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_LLMTIE1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE1_SHIFT)) & SINC_EIE_LLMTIE1_MASK)

#define SINC_EIE_LLMTIE2_MASK                    (0x40000U)
#define SINC_EIE_LLMTIE2_SHIFT                   (18U)
/*! LLMTIE2 - Low Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_LLMTIE2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE2_SHIFT)) & SINC_EIE_LLMTIE2_MASK)

#define SINC_EIE_LLMTIE3_MASK                    (0x80000U)
#define SINC_EIE_LLMTIE3_SHIFT                   (19U)
/*! LLMTIE3 - Low Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_LLMTIE3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE3_SHIFT)) & SINC_EIE_LLMTIE3_MASK)

#define SINC_EIE_LLMTIE4_MASK                    (0x100000U)
#define SINC_EIE_LLMTIE4_SHIFT                   (20U)
/*! LLMTIE4 - Low Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_LLMTIE4(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE4_SHIFT)) & SINC_EIE_LLMTIE4_MASK)

#define SINC_EIE_HLMTIE0_MASK                    (0x1000000U)
#define SINC_EIE_HLMTIE0_SHIFT                   (24U)
/*! HLMTIE0 - High Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_HLMTIE0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE0_SHIFT)) & SINC_EIE_HLMTIE0_MASK)

#define SINC_EIE_HLMTIE1_MASK                    (0x2000000U)
#define SINC_EIE_HLMTIE1_SHIFT                   (25U)
/*! HLMTIE1 - High Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_HLMTIE1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE1_SHIFT)) & SINC_EIE_HLMTIE1_MASK)

#define SINC_EIE_HLMTIE2_MASK                    (0x4000000U)
#define SINC_EIE_HLMTIE2_SHIFT                   (26U)
/*! HLMTIE2 - High Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_HLMTIE2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE2_SHIFT)) & SINC_EIE_HLMTIE2_MASK)

#define SINC_EIE_HLMTIE3_MASK                    (0x8000000U)
#define SINC_EIE_HLMTIE3_SHIFT                   (27U)
/*! HLMTIE3 - High Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_HLMTIE3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE3_SHIFT)) & SINC_EIE_HLMTIE3_MASK)

#define SINC_EIE_HLMTIE4_MASK                    (0x10000000U)
#define SINC_EIE_HLMTIE4_SHIFT                   (28U)
/*! HLMTIE4 - High Limit Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_EIE_HLMTIE4(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE4_SHIFT)) & SINC_EIE_HLMTIE4_MASK)
/*! @} */

/*! @name FIFOIE - FIFO And CAD Error Interrupt Enable */
/*! @{ */

#define SINC_FIFOIE_FUNFIE0_MASK                 (0x1U)
#define SINC_FIFOIE_FUNFIE0_SHIFT                (0U)
/*! FUNFIE0 - FIFO Underflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FUNFIE0(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE0_SHIFT)) & SINC_FIFOIE_FUNFIE0_MASK)

#define SINC_FIFOIE_FUNFIE1_MASK                 (0x2U)
#define SINC_FIFOIE_FUNFIE1_SHIFT                (1U)
/*! FUNFIE1 - FIFO Underflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FUNFIE1(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE1_SHIFT)) & SINC_FIFOIE_FUNFIE1_MASK)

#define SINC_FIFOIE_FUNFIE2_MASK                 (0x4U)
#define SINC_FIFOIE_FUNFIE2_SHIFT                (2U)
/*! FUNFIE2 - FIFO Underflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FUNFIE2(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE2_SHIFT)) & SINC_FIFOIE_FUNFIE2_MASK)

#define SINC_FIFOIE_FUNFIE3_MASK                 (0x8U)
#define SINC_FIFOIE_FUNFIE3_SHIFT                (3U)
/*! FUNFIE3 - FIFO Underflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FUNFIE3(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE3_SHIFT)) & SINC_FIFOIE_FUNFIE3_MASK)

#define SINC_FIFOIE_FUNFIE4_MASK                 (0x10U)
#define SINC_FIFOIE_FUNFIE4_SHIFT                (4U)
/*! FUNFIE4 - FIFO Underflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FUNFIE4(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE4_SHIFT)) & SINC_FIFOIE_FUNFIE4_MASK)

#define SINC_FIFOIE_FOVFIE0_MASK                 (0x100U)
#define SINC_FIFOIE_FOVFIE0_SHIFT                (8U)
/*! FOVFIE0 - FIFO Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FOVFIE0(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE0_SHIFT)) & SINC_FIFOIE_FOVFIE0_MASK)

#define SINC_FIFOIE_FOVFIE1_MASK                 (0x200U)
#define SINC_FIFOIE_FOVFIE1_SHIFT                (9U)
/*! FOVFIE1 - FIFO Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FOVFIE1(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE1_SHIFT)) & SINC_FIFOIE_FOVFIE1_MASK)

#define SINC_FIFOIE_FOVFIE2_MASK                 (0x400U)
#define SINC_FIFOIE_FOVFIE2_SHIFT                (10U)
/*! FOVFIE2 - FIFO Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FOVFIE2(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE2_SHIFT)) & SINC_FIFOIE_FOVFIE2_MASK)

#define SINC_FIFOIE_FOVFIE3_MASK                 (0x800U)
#define SINC_FIFOIE_FOVFIE3_SHIFT                (11U)
/*! FOVFIE3 - FIFO Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FOVFIE3(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE3_SHIFT)) & SINC_FIFOIE_FOVFIE3_MASK)

#define SINC_FIFOIE_FOVFIE4_MASK                 (0x1000U)
#define SINC_FIFOIE_FOVFIE4_SHIFT                (12U)
/*! FOVFIE4 - FIFO Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_FOVFIE4(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE4_SHIFT)) & SINC_FIFOIE_FOVFIE4_MASK)

#define SINC_FIFOIE_CADIE0_MASK                  (0x10000U)
#define SINC_FIFOIE_CADIE0_SHIFT                 (16U)
/*! CADIE0 - Clock Absence Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_CADIE0(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE0_SHIFT)) & SINC_FIFOIE_CADIE0_MASK)

#define SINC_FIFOIE_CADIE1_MASK                  (0x20000U)
#define SINC_FIFOIE_CADIE1_SHIFT                 (17U)
/*! CADIE1 - Clock Absence Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_CADIE1(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE1_SHIFT)) & SINC_FIFOIE_CADIE1_MASK)

#define SINC_FIFOIE_CADIE2_MASK                  (0x40000U)
#define SINC_FIFOIE_CADIE2_SHIFT                 (18U)
/*! CADIE2 - Clock Absence Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_CADIE2(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE2_SHIFT)) & SINC_FIFOIE_CADIE2_MASK)

#define SINC_FIFOIE_CADIE3_MASK                  (0x80000U)
#define SINC_FIFOIE_CADIE3_SHIFT                 (19U)
/*! CADIE3 - Clock Absence Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_CADIE3(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE3_SHIFT)) & SINC_FIFOIE_CADIE3_MASK)

#define SINC_FIFOIE_CADIE4_MASK                  (0x100000U)
#define SINC_FIFOIE_CADIE4_SHIFT                 (20U)
/*! CADIE4 - Clock Absence Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_CADIE4(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE4_SHIFT)) & SINC_FIFOIE_CADIE4_MASK)

#define SINC_FIFOIE_SATIE0_MASK                  (0x1000000U)
#define SINC_FIFOIE_SATIE0_SHIFT                 (24U)
/*! SATIE0 - Saturation Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_SATIE0(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE0_SHIFT)) & SINC_FIFOIE_SATIE0_MASK)

#define SINC_FIFOIE_SATIE1_MASK                  (0x2000000U)
#define SINC_FIFOIE_SATIE1_SHIFT                 (25U)
/*! SATIE1 - Saturation Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_SATIE1(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE1_SHIFT)) & SINC_FIFOIE_SATIE1_MASK)

#define SINC_FIFOIE_SATIE2_MASK                  (0x4000000U)
#define SINC_FIFOIE_SATIE2_SHIFT                 (26U)
/*! SATIE2 - Saturation Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_SATIE2(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE2_SHIFT)) & SINC_FIFOIE_SATIE2_MASK)

#define SINC_FIFOIE_SATIE3_MASK                  (0x8000000U)
#define SINC_FIFOIE_SATIE3_SHIFT                 (27U)
/*! SATIE3 - Saturation Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_SATIE3(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE3_SHIFT)) & SINC_FIFOIE_SATIE3_MASK)

#define SINC_FIFOIE_SATIE4_MASK                  (0x10000000U)
#define SINC_FIFOIE_SATIE4_SHIFT                 (28U)
/*! SATIE4 - Saturation Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_FIFOIE_SATIE4(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE4_SHIFT)) & SINC_FIFOIE_SATIE4_MASK)
/*! @} */

/*! @name NIS - Normal Interrupt Status */
/*! @{ */

#define SINC_NIS_COC0_MASK                       (0x1U)
#define SINC_NIS_COC0_SHIFT                      (0U)
/*! COC0 - Conversion Complete Flag
 *  0b0..No effect
 *  0b0..Not finished; data not available
 *  0b1..Clear the flag
 *  0b1..Finished; data available
 */
#define SINC_NIS_COC0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC0_SHIFT)) & SINC_NIS_COC0_MASK)

#define SINC_NIS_COC1_MASK                       (0x2U)
#define SINC_NIS_COC1_SHIFT                      (1U)
/*! COC1 - Conversion Complete Flag
 *  0b0..No effect
 *  0b0..Not finished; data not available
 *  0b1..Clear the flag
 *  0b1..Finished; data available
 */
#define SINC_NIS_COC1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC1_SHIFT)) & SINC_NIS_COC1_MASK)

#define SINC_NIS_COC2_MASK                       (0x4U)
#define SINC_NIS_COC2_SHIFT                      (2U)
/*! COC2 - Conversion Complete Flag
 *  0b0..No effect
 *  0b0..Not finished; data not available
 *  0b1..Clear the flag
 *  0b1..Finished; data available
 */
#define SINC_NIS_COC2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC2_SHIFT)) & SINC_NIS_COC2_MASK)

#define SINC_NIS_COC3_MASK                       (0x8U)
#define SINC_NIS_COC3_SHIFT                      (3U)
/*! COC3 - Conversion Complete Flag
 *  0b0..No effect
 *  0b0..Not finished; data not available
 *  0b1..Clear the flag
 *  0b1..Finished; data available
 */
#define SINC_NIS_COC3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC3_SHIFT)) & SINC_NIS_COC3_MASK)

#define SINC_NIS_COC4_MASK                       (0x10U)
#define SINC_NIS_COC4_SHIFT                      (4U)
/*! COC4 - Conversion Complete Flag
 *  0b0..No effect
 *  0b0..Not finished; data not available
 *  0b1..Clear the flag
 *  0b1..Finished; data available
 */
#define SINC_NIS_COC4(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC4_SHIFT)) & SINC_NIS_COC4_MASK)

#define SINC_NIS_CHF0_MASK                       (0x100U)
#define SINC_NIS_CHF0_SHIFT                      (8U)
/*! CHF0 - Data Output Ready Flag
 *  0b0..No effect
 *  0b0..No overflow; data not available
 *  0b1..Clear the flag
 *  0b1..Overflow; data available
 */
#define SINC_NIS_CHF0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF0_SHIFT)) & SINC_NIS_CHF0_MASK)

#define SINC_NIS_CHF1_MASK                       (0x200U)
#define SINC_NIS_CHF1_SHIFT                      (9U)
/*! CHF1 - Data Output Ready Flag
 *  0b0..No effect
 *  0b0..No overflow; data not available
 *  0b1..Clear the flag
 *  0b1..Overflow; data available
 */
#define SINC_NIS_CHF1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF1_SHIFT)) & SINC_NIS_CHF1_MASK)

#define SINC_NIS_CHF2_MASK                       (0x400U)
#define SINC_NIS_CHF2_SHIFT                      (10U)
/*! CHF2 - Data Output Ready Flag
 *  0b0..No effect
 *  0b0..No overflow; data not available
 *  0b1..Clear the flag
 *  0b1..Overflow; data available
 */
#define SINC_NIS_CHF2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF2_SHIFT)) & SINC_NIS_CHF2_MASK)

#define SINC_NIS_CHF3_MASK                       (0x800U)
#define SINC_NIS_CHF3_SHIFT                      (11U)
/*! CHF3 - Data Output Ready Flag
 *  0b0..No effect
 *  0b0..No overflow; data not available
 *  0b1..Clear the flag
 *  0b1..Overflow; data available
 */
#define SINC_NIS_CHF3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF3_SHIFT)) & SINC_NIS_CHF3_MASK)

#define SINC_NIS_CHF4_MASK                       (0x1000U)
#define SINC_NIS_CHF4_SHIFT                      (12U)
/*! CHF4 - Data Output Ready Flag
 *  0b0..No effect
 *  0b0..No overflow; data not available
 *  0b1..Clear the flag
 *  0b1..Overflow; data available
 */
#define SINC_NIS_CHF4(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF4_SHIFT)) & SINC_NIS_CHF4_MASK)

#define SINC_NIS_ZCD0_MASK                       (0x10000U)
#define SINC_NIS_ZCD0_SHIFT                      (16U)
/*! ZCD0 - Zero Cross Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_NIS_ZCD0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD0_SHIFT)) & SINC_NIS_ZCD0_MASK)

#define SINC_NIS_ZCD1_MASK                       (0x20000U)
#define SINC_NIS_ZCD1_SHIFT                      (17U)
/*! ZCD1 - Zero Cross Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_NIS_ZCD1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD1_SHIFT)) & SINC_NIS_ZCD1_MASK)

#define SINC_NIS_ZCD2_MASK                       (0x40000U)
#define SINC_NIS_ZCD2_SHIFT                      (18U)
/*! ZCD2 - Zero Cross Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_NIS_ZCD2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD2_SHIFT)) & SINC_NIS_ZCD2_MASK)

#define SINC_NIS_ZCD3_MASK                       (0x80000U)
#define SINC_NIS_ZCD3_SHIFT                      (19U)
/*! ZCD3 - Zero Cross Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_NIS_ZCD3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD3_SHIFT)) & SINC_NIS_ZCD3_MASK)

#define SINC_NIS_ZCD4_MASK                       (0x100000U)
#define SINC_NIS_ZCD4_SHIFT                      (20U)
/*! ZCD4 - Zero Cross Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_NIS_ZCD4(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD4_SHIFT)) & SINC_NIS_ZCD4_MASK)
/*! @} */

/*! @name EIS - Error Interrupt Status */
/*! @{ */

#define SINC_EIS_SCD0_MASK                       (0x1U)
#define SINC_EIS_SCD0_SHIFT                      (0U)
/*! SCD0 - Short Circuit Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_EIS_SCD0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD0_SHIFT)) & SINC_EIS_SCD0_MASK)

#define SINC_EIS_SCD1_MASK                       (0x2U)
#define SINC_EIS_SCD1_SHIFT                      (1U)
/*! SCD1 - Short Circuit Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_EIS_SCD1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD1_SHIFT)) & SINC_EIS_SCD1_MASK)

#define SINC_EIS_SCD2_MASK                       (0x4U)
#define SINC_EIS_SCD2_SHIFT                      (2U)
/*! SCD2 - Short Circuit Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_EIS_SCD2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD2_SHIFT)) & SINC_EIS_SCD2_MASK)

#define SINC_EIS_SCD3_MASK                       (0x8U)
#define SINC_EIS_SCD3_SHIFT                      (3U)
/*! SCD3 - Short Circuit Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_EIS_SCD3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD3_SHIFT)) & SINC_EIS_SCD3_MASK)

#define SINC_EIS_SCD4_MASK                       (0x10U)
#define SINC_EIS_SCD4_SHIFT                      (4U)
/*! SCD4 - Short Circuit Detected Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define SINC_EIS_SCD4(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD4_SHIFT)) & SINC_EIS_SCD4_MASK)

#define SINC_EIS_WLMT0_MASK                      (0x100U)
#define SINC_EIS_WLMT0_SHIFT                     (8U)
/*! WLMT0 - Window Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_WLMT0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT0_SHIFT)) & SINC_EIS_WLMT0_MASK)

#define SINC_EIS_WLMT1_MASK                      (0x200U)
#define SINC_EIS_WLMT1_SHIFT                     (9U)
/*! WLMT1 - Window Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_WLMT1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT1_SHIFT)) & SINC_EIS_WLMT1_MASK)

#define SINC_EIS_WLMT2_MASK                      (0x400U)
#define SINC_EIS_WLMT2_SHIFT                     (10U)
/*! WLMT2 - Window Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_WLMT2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT2_SHIFT)) & SINC_EIS_WLMT2_MASK)

#define SINC_EIS_WLMT3_MASK                      (0x800U)
#define SINC_EIS_WLMT3_SHIFT                     (11U)
/*! WLMT3 - Window Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_WLMT3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT3_SHIFT)) & SINC_EIS_WLMT3_MASK)

#define SINC_EIS_WLMT4_MASK                      (0x1000U)
#define SINC_EIS_WLMT4_SHIFT                     (12U)
/*! WLMT4 - Window Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_WLMT4(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT4_SHIFT)) & SINC_EIS_WLMT4_MASK)

#define SINC_EIS_LLMT0_MASK                      (0x10000U)
#define SINC_EIS_LLMT0_SHIFT                     (16U)
/*! LLMT0 - Low Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_LLMT0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT0_SHIFT)) & SINC_EIS_LLMT0_MASK)

#define SINC_EIS_LLMT1_MASK                      (0x20000U)
#define SINC_EIS_LLMT1_SHIFT                     (17U)
/*! LLMT1 - Low Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_LLMT1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT1_SHIFT)) & SINC_EIS_LLMT1_MASK)

#define SINC_EIS_LLMT2_MASK                      (0x40000U)
#define SINC_EIS_LLMT2_SHIFT                     (18U)
/*! LLMT2 - Low Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_LLMT2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT2_SHIFT)) & SINC_EIS_LLMT2_MASK)

#define SINC_EIS_LLMT3_MASK                      (0x80000U)
#define SINC_EIS_LLMT3_SHIFT                     (19U)
/*! LLMT3 - Low Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_LLMT3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT3_SHIFT)) & SINC_EIS_LLMT3_MASK)

#define SINC_EIS_LLMT4_MASK                      (0x100000U)
#define SINC_EIS_LLMT4_SHIFT                     (20U)
/*! LLMT4 - Low Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_LLMT4(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT4_SHIFT)) & SINC_EIS_LLMT4_MASK)

#define SINC_EIS_HLMT0_MASK                      (0x1000000U)
#define SINC_EIS_HLMT0_SHIFT                     (24U)
/*! HLMT0 - High Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_HLMT0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT0_SHIFT)) & SINC_EIS_HLMT0_MASK)

#define SINC_EIS_HLMT1_MASK                      (0x2000000U)
#define SINC_EIS_HLMT1_SHIFT                     (25U)
/*! HLMT1 - High Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_HLMT1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT1_SHIFT)) & SINC_EIS_HLMT1_MASK)

#define SINC_EIS_HLMT2_MASK                      (0x4000000U)
#define SINC_EIS_HLMT2_SHIFT                     (26U)
/*! HLMT2 - High Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_HLMT2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT2_SHIFT)) & SINC_EIS_HLMT2_MASK)

#define SINC_EIS_HLMT3_MASK                      (0x8000000U)
#define SINC_EIS_HLMT3_SHIFT                     (27U)
/*! HLMT3 - High Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_HLMT3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT3_SHIFT)) & SINC_EIS_HLMT3_MASK)

#define SINC_EIS_HLMT4_MASK                      (0x10000000U)
#define SINC_EIS_HLMT4_SHIFT                     (28U)
/*! HLMT4 - High Limit Flag
 *  0b0..No effect
 *  0b0..Not exceeded
 *  0b1..Clear the flag
 *  0b1..Exceeded
 */
#define SINC_EIS_HLMT4(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT4_SHIFT)) & SINC_EIS_HLMT4_MASK)
/*! @} */

/*! @name FIFOIS - FIFO And CAD Error Interrupt Status */
/*! @{ */

#define SINC_FIFOIS_FUNF0_MASK                   (0x1U)
#define SINC_FIFOIS_FUNF0_SHIFT                  (0U)
/*! FUNF0 - FIFO Underflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FUNF0(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF0_SHIFT)) & SINC_FIFOIS_FUNF0_MASK)

#define SINC_FIFOIS_FUNF1_MASK                   (0x2U)
#define SINC_FIFOIS_FUNF1_SHIFT                  (1U)
/*! FUNF1 - FIFO Underflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FUNF1(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF1_SHIFT)) & SINC_FIFOIS_FUNF1_MASK)

#define SINC_FIFOIS_FUNF2_MASK                   (0x4U)
#define SINC_FIFOIS_FUNF2_SHIFT                  (2U)
/*! FUNF2 - FIFO Underflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FUNF2(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF2_SHIFT)) & SINC_FIFOIS_FUNF2_MASK)

#define SINC_FIFOIS_FUNF3_MASK                   (0x8U)
#define SINC_FIFOIS_FUNF3_SHIFT                  (3U)
/*! FUNF3 - FIFO Underflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FUNF3(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF3_SHIFT)) & SINC_FIFOIS_FUNF3_MASK)

#define SINC_FIFOIS_FUNF4_MASK                   (0x10U)
#define SINC_FIFOIS_FUNF4_SHIFT                  (4U)
/*! FUNF4 - FIFO Underflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FUNF4(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF4_SHIFT)) & SINC_FIFOIS_FUNF4_MASK)

#define SINC_FIFOIS_FOVF0_MASK                   (0x100U)
#define SINC_FIFOIS_FOVF0_SHIFT                  (8U)
/*! FOVF0 - FIFO Overflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FOVF0(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF0_SHIFT)) & SINC_FIFOIS_FOVF0_MASK)

#define SINC_FIFOIS_FOVF1_MASK                   (0x200U)
#define SINC_FIFOIS_FOVF1_SHIFT                  (9U)
/*! FOVF1 - FIFO Overflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FOVF1(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF1_SHIFT)) & SINC_FIFOIS_FOVF1_MASK)

#define SINC_FIFOIS_FOVF2_MASK                   (0x400U)
#define SINC_FIFOIS_FOVF2_SHIFT                  (10U)
/*! FOVF2 - FIFO Overflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FOVF2(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF2_SHIFT)) & SINC_FIFOIS_FOVF2_MASK)

#define SINC_FIFOIS_FOVF3_MASK                   (0x800U)
#define SINC_FIFOIS_FOVF3_SHIFT                  (11U)
/*! FOVF3 - FIFO Overflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FOVF3(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF3_SHIFT)) & SINC_FIFOIS_FOVF3_MASK)

#define SINC_FIFOIS_FOVF4_MASK                   (0x1000U)
#define SINC_FIFOIS_FOVF4_SHIFT                  (12U)
/*! FOVF4 - FIFO Overflow Flag
 *  0b0..Did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define SINC_FIFOIS_FOVF4(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF4_SHIFT)) & SINC_FIFOIS_FOVF4_MASK)

#define SINC_FIFOIS_CAD0_MASK                    (0x10000U)
#define SINC_FIFOIS_CAD0_SHIFT                   (16U)
/*! CAD0 - Clock Absence Flag
 *  0b0..Clock present
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Clock absent
 */
#define SINC_FIFOIS_CAD0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD0_SHIFT)) & SINC_FIFOIS_CAD0_MASK)

#define SINC_FIFOIS_CAD1_MASK                    (0x20000U)
#define SINC_FIFOIS_CAD1_SHIFT                   (17U)
/*! CAD1 - Clock Absence Flag
 *  0b0..Clock present
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Clock absent
 */
#define SINC_FIFOIS_CAD1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD1_SHIFT)) & SINC_FIFOIS_CAD1_MASK)

#define SINC_FIFOIS_CAD2_MASK                    (0x40000U)
#define SINC_FIFOIS_CAD2_SHIFT                   (18U)
/*! CAD2 - Clock Absence Flag
 *  0b0..Clock present
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Clock absent
 */
#define SINC_FIFOIS_CAD2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD2_SHIFT)) & SINC_FIFOIS_CAD2_MASK)

#define SINC_FIFOIS_CAD3_MASK                    (0x80000U)
#define SINC_FIFOIS_CAD3_SHIFT                   (19U)
/*! CAD3 - Clock Absence Flag
 *  0b0..Clock present
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Clock absent
 */
#define SINC_FIFOIS_CAD3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD3_SHIFT)) & SINC_FIFOIS_CAD3_MASK)

#define SINC_FIFOIS_CAD4_MASK                    (0x100000U)
#define SINC_FIFOIS_CAD4_SHIFT                   (20U)
/*! CAD4 - Clock Absence Flag
 *  0b0..Clock present
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Clock absent
 */
#define SINC_FIFOIS_CAD4(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD4_SHIFT)) & SINC_FIFOIS_CAD4_MASK)

#define SINC_FIFOIS_SAT0_MASK                    (0x1000000U)
#define SINC_FIFOIS_SAT0_SHIFT                   (24U)
/*! SAT0 - Saturation Flag
 *  0b0..No effect
 *  0b0..Not saturated
 *  0b1..Clear the flag
 *  0b1..Saturated
 */
#define SINC_FIFOIS_SAT0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT0_SHIFT)) & SINC_FIFOIS_SAT0_MASK)

#define SINC_FIFOIS_SAT1_MASK                    (0x2000000U)
#define SINC_FIFOIS_SAT1_SHIFT                   (25U)
/*! SAT1 - Saturation Flag
 *  0b0..No effect
 *  0b0..Not saturated
 *  0b1..Clear the flag
 *  0b1..Saturated
 */
#define SINC_FIFOIS_SAT1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT1_SHIFT)) & SINC_FIFOIS_SAT1_MASK)

#define SINC_FIFOIS_SAT2_MASK                    (0x4000000U)
#define SINC_FIFOIS_SAT2_SHIFT                   (26U)
/*! SAT2 - Saturation Flag
 *  0b0..No effect
 *  0b0..Not saturated
 *  0b1..Clear the flag
 *  0b1..Saturated
 */
#define SINC_FIFOIS_SAT2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT2_SHIFT)) & SINC_FIFOIS_SAT2_MASK)

#define SINC_FIFOIS_SAT3_MASK                    (0x8000000U)
#define SINC_FIFOIS_SAT3_SHIFT                   (27U)
/*! SAT3 - Saturation Flag
 *  0b0..No effect
 *  0b0..Not saturated
 *  0b1..Clear the flag
 *  0b1..Saturated
 */
#define SINC_FIFOIS_SAT3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT3_SHIFT)) & SINC_FIFOIS_SAT3_MASK)

#define SINC_FIFOIS_SAT4_MASK                    (0x10000000U)
#define SINC_FIFOIS_SAT4_SHIFT                   (28U)
/*! SAT4 - Saturation Flag
 *  0b0..No effect
 *  0b0..Not saturated
 *  0b1..Clear the flag
 *  0b1..Saturated
 */
#define SINC_FIFOIS_SAT4(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT4_SHIFT)) & SINC_FIFOIS_SAT4_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define SINC_SR_CIP0_MASK                        (0x1U)
#define SINC_SR_CIP0_SHIFT                       (0U)
/*! CIP0 - Conversion In Progress
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define SINC_SR_CIP0(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP0_SHIFT)) & SINC_SR_CIP0_MASK)

#define SINC_SR_CIP1_MASK                        (0x2U)
#define SINC_SR_CIP1_SHIFT                       (1U)
/*! CIP1 - Conversion In Progress
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define SINC_SR_CIP1(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP1_SHIFT)) & SINC_SR_CIP1_MASK)

#define SINC_SR_CIP2_MASK                        (0x4U)
#define SINC_SR_CIP2_SHIFT                       (2U)
/*! CIP2 - Conversion In Progress
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define SINC_SR_CIP2(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP2_SHIFT)) & SINC_SR_CIP2_MASK)

#define SINC_SR_CIP3_MASK                        (0x8U)
#define SINC_SR_CIP3_SHIFT                       (3U)
/*! CIP3 - Conversion In Progress
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define SINC_SR_CIP3(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP3_SHIFT)) & SINC_SR_CIP3_MASK)

#define SINC_SR_CIP4_MASK                        (0x10U)
#define SINC_SR_CIP4_SHIFT                       (4U)
/*! CIP4 - Conversion In Progress
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define SINC_SR_CIP4(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP4_SHIFT)) & SINC_SR_CIP4_MASK)

#define SINC_SR_CHRDY0_MASK                      (0x100U)
#define SINC_SR_CHRDY0_SHIFT                     (8U)
/*! CHRDY0 - Channel Ready For Conversion
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_CHRDY0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY0_SHIFT)) & SINC_SR_CHRDY0_MASK)

#define SINC_SR_CHRDY1_MASK                      (0x200U)
#define SINC_SR_CHRDY1_SHIFT                     (9U)
/*! CHRDY1 - Channel Ready For Conversion
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_CHRDY1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY1_SHIFT)) & SINC_SR_CHRDY1_MASK)

#define SINC_SR_CHRDY2_MASK                      (0x400U)
#define SINC_SR_CHRDY2_SHIFT                     (10U)
/*! CHRDY2 - Channel Ready For Conversion
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_CHRDY2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY2_SHIFT)) & SINC_SR_CHRDY2_MASK)

#define SINC_SR_CHRDY3_MASK                      (0x800U)
#define SINC_SR_CHRDY3_SHIFT                     (11U)
/*! CHRDY3 - Channel Ready For Conversion
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_CHRDY3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY3_SHIFT)) & SINC_SR_CHRDY3_MASK)

#define SINC_SR_CHRDY4_MASK                      (0x1000U)
#define SINC_SR_CHRDY4_SHIFT                     (12U)
/*! CHRDY4 - Channel Ready For Conversion
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_CHRDY4(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY4_SHIFT)) & SINC_SR_CHRDY4_MASK)

#define SINC_SR_FIFOEMPTY0_MASK                  (0x10000U)
#define SINC_SR_FIFOEMPTY0_SHIFT                 (16U)
/*! FIFOEMPTY0 - FIFO Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define SINC_SR_FIFOEMPTY0(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY0_SHIFT)) & SINC_SR_FIFOEMPTY0_MASK)

#define SINC_SR_FIFOEMPTY1_MASK                  (0x20000U)
#define SINC_SR_FIFOEMPTY1_SHIFT                 (17U)
/*! FIFOEMPTY1 - FIFO Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define SINC_SR_FIFOEMPTY1(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY1_SHIFT)) & SINC_SR_FIFOEMPTY1_MASK)

#define SINC_SR_FIFOEMPTY2_MASK                  (0x40000U)
#define SINC_SR_FIFOEMPTY2_SHIFT                 (18U)
/*! FIFOEMPTY2 - FIFO Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define SINC_SR_FIFOEMPTY2(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY2_SHIFT)) & SINC_SR_FIFOEMPTY2_MASK)

#define SINC_SR_FIFOEMPTY3_MASK                  (0x80000U)
#define SINC_SR_FIFOEMPTY3_SHIFT                 (19U)
/*! FIFOEMPTY3 - FIFO Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define SINC_SR_FIFOEMPTY3(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY3_SHIFT)) & SINC_SR_FIFOEMPTY3_MASK)

#define SINC_SR_FIFOEMPTY4_MASK                  (0x100000U)
#define SINC_SR_FIFOEMPTY4_SHIFT                 (20U)
/*! FIFOEMPTY4 - FIFO Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define SINC_SR_FIFOEMPTY4(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY4_SHIFT)) & SINC_SR_FIFOEMPTY4_MASK)

#define SINC_SR_MCLKRDY0_MASK                    (0x1000000U)
#define SINC_SR_MCLKRDY0_SHIFT                   (24U)
/*! MCLKRDY0 - Modulator Clock 0 Ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_MCLKRDY0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_SR_MCLKRDY0_SHIFT)) & SINC_SR_MCLKRDY0_MASK)

#define SINC_SR_MCLKRDY1_MASK                    (0x2000000U)
#define SINC_SR_MCLKRDY1_SHIFT                   (25U)
/*! MCLKRDY1 - Modulator Clock 1 Ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_MCLKRDY1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_SR_MCLKRDY1_SHIFT)) & SINC_SR_MCLKRDY1_MASK)

#define SINC_SR_MCLKRDY2_MASK                    (0x4000000U)
#define SINC_SR_MCLKRDY2_SHIFT                   (26U)
/*! MCLKRDY2 - Modulator Clock 2 Ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_SR_MCLKRDY2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_SR_MCLKRDY2_SHIFT)) & SINC_SR_MCLKRDY2_MASK)
/*! @} */

/*! @name CCR - Channel 0 Control..Channel 4 Control */
/*! @{ */

#define SINC_CCR_CHEN_MASK                       (0x1U)
#define SINC_CCR_CHEN_SHIFT                      (0U)
/*! CHEN - Channel Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_CHEN(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CCR_CHEN_SHIFT)) & SINC_CCR_CHEN_MASK)

#define SINC_CCR_PFEN_MASK                       (0x2U)
#define SINC_CCR_PFEN_SHIFT                      (1U)
/*! PFEN - PF Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_PFEN(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CCR_PFEN_SHIFT)) & SINC_CCR_PFEN_MASK)

#define SINC_CCR_DMAEN_MASK                      (0x8U)
#define SINC_CCR_DMAEN_SHIFT                     (3U)
/*! DMAEN - DMA Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_DMAEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_DMAEN_SHIFT)) & SINC_CCR_DMAEN_MASK)

#define SINC_CCR_SCDEN_MASK                      (0x100U)
#define SINC_CCR_SCDEN_SHIFT                     (8U)
/*! SCDEN - Short Circuit Detect Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_SCDEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_SCDEN_SHIFT)) & SINC_CCR_SCDEN_MASK)

#define SINC_CCR_CADEN_MASK                      (0x200U)
#define SINC_CCR_CADEN_SHIFT                     (9U)
/*! CADEN - Clock Absence Detect Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_CADEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_CADEN_SHIFT)) & SINC_CCR_CADEN_MASK)

#define SINC_CCR_ZCDEN_MASK                      (0x1000U)
#define SINC_CCR_ZCDEN_SHIFT                     (12U)
/*! ZCDEN - Zero Cross Detect Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_ZCDEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_ZCDEN_SHIFT)) & SINC_CCR_ZCDEN_MASK)

#define SINC_CCR_LMTEN_MASK                      (0x2000U)
#define SINC_CCR_LMTEN_SHIFT                     (13U)
/*! LMTEN - Limit Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_LMTEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_LMTEN_SHIFT)) & SINC_CCR_LMTEN_MASK)

#define SINC_CCR_FIFOEN_MASK                     (0x4000U)
#define SINC_CCR_FIFOEN_SHIFT                    (14U)
/*! FIFOEN - FIFO Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CCR_FIFOEN(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCR_FIFOEN_SHIFT)) & SINC_CCR_FIFOEN_MASK)

#define SINC_CCR_DBGSEL_MASK                     (0xF00000U)
#define SINC_CCR_DBGSEL_SHIFT                    (20U)
/*! DBGSEL - Debug Output Selection
 *  0b0000..Final data from the PF (24 bits)
 *  0b0001..Offset data (24 bits)
 *  0b0010..Shifted data from the PF (24 bits)
 *  0b0011..DC remover (HPF) data (32 bits)
 *  0b0100..Raw data from the PF's CIC filter
 *  0b0110..Historical data from SCD
 *  0b0111..Data from the Manchester decoder
 *  0b1000..Data from CAD
 *  0b1001..Number of available entries in the FIFO
 *  0b1010..Status of the parallel or serial data converter
 */
#define SINC_CCR_DBGSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCR_DBGSEL_SHIFT)) & SINC_CCR_DBGSEL_MASK)
/*! @} */

/* The count of SINC_CCR */
#define SINC_CCR_COUNT                           (5U)

/*! @name CDR - Channel 0 Data Rate..Channel 4 Data Rate */
/*! @{ */

#define SINC_CDR_PFOSR_MASK                      (0x7FFU)
#define SINC_CDR_PFOSR_SHIFT                     (0U)
/*! PFOSR - PF OSR */
#define SINC_CDR_PFOSR(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CDR_PFOSR_SHIFT)) & SINC_CDR_PFOSR_MASK)

#define SINC_CDR_PFORD_MASK                      (0x1800U)
#define SINC_CDR_PFORD_SHIFT                     (11U)
/*! PFORD - PF Order
 *  0b00..FastSinc
 *  0b01..First order
 *  0b10..Second order
 *  0b11..Third order
 */
#define SINC_CDR_PFORD(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CDR_PFORD_SHIFT)) & SINC_CDR_PFORD_MASK)

#define SINC_CDR_PFCM_MASK                       (0xC000U)
#define SINC_CDR_PFCM_SHIFT                      (14U)
/*! PFCM - PF Conversion Mode
 *  0b00..Single
 *  0b01..Continuous
 *  0b10..Always
 *  0b11..Fixed number
 */
#define SINC_CDR_PFCM(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CDR_PFCM_SHIFT)) & SINC_CDR_PFCM_MASK)
/*! @} */

/* The count of SINC_CDR */
#define SINC_CDR_COUNT                           (5U)

/*! @name CCFR - Channel 0 Configuration..Channel 4 Configuration */
/*! @{ */

#define SINC_CCFR_PFSFT_MASK                     (0x1FU)
#define SINC_CCFR_PFSFT_SHIFT                    (0U)
/*! PFSFT - PF Shift */
#define SINC_CCFR_PFSFT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_PFSFT_SHIFT)) & SINC_CCFR_PFSFT_MASK)

#define SINC_CCFR_RDFMT_MASK                     (0x40U)
#define SINC_CCFR_RDFMT_SHIFT                    (6U)
/*! RDFMT - Result Data Format
 *  0b0..Left justified, signed
 *  0b1..Left justified, unsigned
 */
#define SINC_CCFR_RDFMT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_RDFMT_SHIFT)) & SINC_CCFR_RDFMT_MASK)

#define SINC_CCFR_FIFOWMK_MASK                   (0x1C00U)
#define SINC_CCFR_FIFOWMK_SHIFT                  (10U)
/*! FIFOWMK - FIFO Watermark */
#define SINC_CCFR_FIFOWMK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_FIFOWMK_SHIFT)) & SINC_CCFR_FIFOWMK_MASK)

#define SINC_CCFR_IBFMT_MASK                     (0x30000U)
#define SINC_CCFR_IBFMT_SHIFT                    (16U)
/*! IBFMT - Input Bit Format
 *  0b00..External bitstream from the MBIT[n] signal
 *  0b01..External Manchester code; ICESEL selects the rise or fall decoder
 *  0b10..Internal 16-bit parallel data from MPDATA
 *  0b11..Internal 32-bit serial data from MPDATA
 */
#define SINC_CCFR_IBFMT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_IBFMT_SHIFT)) & SINC_CCFR_IBFMT_MASK)

#define SINC_CCFR_ICSEL_MASK                     (0x1C0000U)
#define SINC_CCFR_ICSEL_SHIFT                    (18U)
/*! ICSEL - Input Clock Select
 *  0b000..MCLK_OUT0 with internal routeback
 *  0b001..MCLK_OUT1 with internal routeback
 *  0b010..MCLK_OUT2 with internal routeback
 *  0b011..External modulator clock dedicated to this channel
 *  0b111..Grouped clock shared with an adjacent channel; the adjacent channel's ICSEL field determines the input clock
 */
#define SINC_CCFR_ICSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ICSEL_SHIFT)) & SINC_CCFR_ICSEL_MASK)

#define SINC_CCFR_ICESEL_MASK                    (0xE00000U)
#define SINC_CCFR_ICESEL_SHIFT                   (21U)
/*! ICESEL - Input Clock Edge Select
 *  0b001..Positive edge
 *  0b010..Negative edge
 *  0b011..Both edges
 *  0b100..Every other odd positive edge
 *  0b101..Every other even positive edge
 *  0b110..Every other odd negative edge
 *  0b111..Every other even negative edge
 */
#define SINC_CCFR_ICESEL(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ICESEL_SHIFT)) & SINC_CCFR_ICESEL_MASK)

#define SINC_CCFR_ITSEL_MASK                     (0x3000000U)
#define SINC_CCFR_ITSEL_SHIFT                    (24U)
/*! ITSEL - Input Trigger Select
 *  0b00..Software
 *  0b01..Hardware trigger dedicated to the channel
 *  0b11..Grouped trigger shared with an adjacent channel; the adjacent channel's ITSEL field determines the trigger
 */
#define SINC_CCFR_ITSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ITSEL_SHIFT)) & SINC_CCFR_ITSEL_MASK)

#define SINC_CCFR_IBSEL_MASK                     (0xC000000U)
#define SINC_CCFR_IBSEL_SHIFT                    (26U)
/*! IBSEL - Input Bit Select
 *  0b00..External bitstream from the MBIT[n] signal
 *  0b01..Alternate internal bitstream from the INP[n] signal
 *  0b11..Grouped bitstream shared with an adjacent channel; the adjacent channel's IBSEL field determines the input
 */
#define SINC_CCFR_IBSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_IBSEL_SHIFT)) & SINC_CCFR_IBSEL_MASK)

#define SINC_CCFR_ITLVL_MASK                     (0x10000000U)
#define SINC_CCFR_ITLVL_SHIFT                    (28U)
/*! ITLVL - Input Trigger Level Type
 *  0b0..Edge
 *  0b1..Level
 */
#define SINC_CCFR_ITLVL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ITLVL_SHIFT)) & SINC_CCFR_ITLVL_MASK)

#define SINC_CCFR_ZCOP_MASK                      (0xC0000000U)
#define SINC_CCFR_ZCOP_SHIFT                     (30U)
/*! ZCOP - Zero Cross Option
 *  0b00..Both rise and fall
 *  0b01..Fall
 *  0b10..Rise
 */
#define SINC_CCFR_ZCOP(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ZCOP_SHIFT)) & SINC_CCFR_ZCOP_MASK)
/*! @} */

/* The count of SINC_CCFR */
#define SINC_CCFR_COUNT                          (5U)

/*! @name CPROT - Channel 0 Protection..Channel 4 Protection */
/*! @{ */

#define SINC_CPROT_SCDLMT_MASK                   (0xFFU)
#define SINC_CPROT_SCDLMT_SHIFT                  (0U)
/*! SCDLMT - SCD Limit Threshold
 *  0b00000000-0b00000001..Disables SCD
 *  *..Threshold value
 */
#define SINC_CPROT_SCDLMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDLMT_SHIFT)) & SINC_CPROT_SCDLMT_MASK)

#define SINC_CPROT_SCDCM_MASK                    (0x800U)
#define SINC_CPROT_SCDCM_SHIFT                   (11U)
/*! SCDCM - SCD Conversion Mode
 *  0b0..Constantly when CnCR[CHEN] = MCR[MEN] = 1
 *  0b1..Only when the PF is performing a conversion
 */
#define SINC_CPROT_SCDCM(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDCM_SHIFT)) & SINC_CPROT_SCDCM_MASK)

#define SINC_CPROT_SCDOP_MASK                    (0x3000U)
#define SINC_CPROT_SCDOP_SHIFT                   (12U)
/*! SCDOP - SCD Option
 *  0b00..Both 0 and 1
 *  0b01..Only 1
 *  0b10..Only 0
 *  0b11..
 */
#define SINC_CPROT_SCDOP(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDOP_SHIFT)) & SINC_CPROT_SCDOP_MASK)

#define SINC_CPROT_LMTOP_MASK                    (0xC000U)
#define SINC_CPROT_LMTOP_SHIFT                   (14U)
/*! LMTOP - Limit Detection Option
 *  0b00..Both high and low limits
 *  0b01..High limit
 *  0b10..Low limit
 *  0b11..Windowed value
 */
#define SINC_CPROT_LMTOP(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_LMTOP_SHIFT)) & SINC_CPROT_LMTOP_MASK)

#define SINC_CPROT_CADLMT_MASK                   (0xF0000U)
#define SINC_CPROT_CADLMT_SHIFT                  (16U)
/*! CADLMT - CAD Limit Threshold
 *  0b0000..Disables CAD
 *  *..Threshold value
 */
#define SINC_CPROT_CADLMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_CADLMT_SHIFT)) & SINC_CPROT_CADLMT_MASK)

#define SINC_CPROT_CADBK_MASK                    (0x4000000U)
#define SINC_CPROT_CADBK_SHIFT                   (26U)
/*! CADBK - CAD Break Signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CPROT_CADBK(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_CADBK_SHIFT)) & SINC_CPROT_CADBK_MASK)

#define SINC_CPROT_SCDBK_MASK                    (0x8000000U)
#define SINC_CPROT_SCDBK_SHIFT                   (27U)
/*! SCDBK - SCD Break Signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CPROT_SCDBK(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDBK_SHIFT)) & SINC_CPROT_SCDBK_MASK)

#define SINC_CPROT_LLMTBK_MASK                   (0x20000000U)
#define SINC_CPROT_LLMTBK_SHIFT                  (29U)
/*! LLMTBK - Low Limit Break Signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CPROT_LLMTBK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_LLMTBK_SHIFT)) & SINC_CPROT_LLMTBK_MASK)

#define SINC_CPROT_WLMTBK_MASK                   (0x40000000U)
#define SINC_CPROT_WLMTBK_SHIFT                  (30U)
/*! WLMTBK - Window Limit Break Signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CPROT_WLMTBK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_WLMTBK_SHIFT)) & SINC_CPROT_WLMTBK_MASK)

#define SINC_CPROT_HLMTBK_MASK                   (0x80000000U)
#define SINC_CPROT_HLMTBK_SHIFT                  (31U)
/*! HLMTBK - High Limit Break Signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define SINC_CPROT_HLMTBK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_HLMTBK_SHIFT)) & SINC_CPROT_HLMTBK_MASK)
/*! @} */

/* The count of SINC_CPROT */
#define SINC_CPROT_COUNT                         (5U)

/*! @name CBIAS - Channel 0 Bias..Channel 4 Bias */
/*! @{ */

#define SINC_CBIAS_BIAS_MASK                     (0xFFFFFF00U)
#define SINC_CBIAS_BIAS_SHIFT                    (8U)
/*! BIAS - Bias Value */
#define SINC_CBIAS_BIAS(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CBIAS_BIAS_SHIFT)) & SINC_CBIAS_BIAS_MASK)
/*! @} */

/* The count of SINC_CBIAS */
#define SINC_CBIAS_COUNT                         (5U)

/*! @name CLOLMT - Channel 0 Low Limit..Channel 4 Low Limit */
/*! @{ */

#define SINC_CLOLMT_LOLMT_MASK                   (0xFFFFFF00U)
#define SINC_CLOLMT_LOLMT_SHIFT                  (8U)
/*! LOLMT - Low Limit Threshold */
#define SINC_CLOLMT_LOLMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CLOLMT_LOLMT_SHIFT)) & SINC_CLOLMT_LOLMT_MASK)
/*! @} */

/* The count of SINC_CLOLMT */
#define SINC_CLOLMT_COUNT                        (5U)

/*! @name CHILMT - Channel 0 High Limit..Channel 4 High Limit */
/*! @{ */

#define SINC_CHILMT_HILMT_MASK                   (0xFFFFFF00U)
#define SINC_CHILMT_HILMT_SHIFT                  (8U)
/*! HILMT - High Limit Threshold */
#define SINC_CHILMT_HILMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CHILMT_HILMT_SHIFT)) & SINC_CHILMT_HILMT_MASK)
/*! @} */

/* The count of SINC_CHILMT */
#define SINC_CHILMT_COUNT                        (5U)

/*! @name CRDATA - Channel 0 Result Data..Channel 4 Result Data */
/*! @{ */

#define SINC_CRDATA_RDATA_MASK                   (0xFFFFFF00U)
#define SINC_CRDATA_RDATA_SHIFT                  (8U)
/*! RDATA - Result Data */
#define SINC_CRDATA_RDATA(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CRDATA_RDATA_SHIFT)) & SINC_CRDATA_RDATA_MASK)
/*! @} */

/* The count of SINC_CRDATA */
#define SINC_CRDATA_COUNT                        (5U)

/*! @name CMPDATA - Channel 0 Multipurpose Data..Channel 4 Multipurpose Data */
/*! @{ */

#define SINC_CMPDATA_MPDATA_MASK                 (0xFFFFFFFFU)
#define SINC_CMPDATA_MPDATA_SHIFT                (0U)
/*! MPDATA - Multipurpose Data */
#define SINC_CMPDATA_MPDATA(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_CMPDATA_MPDATA_SHIFT)) & SINC_CMPDATA_MPDATA_MASK)
/*! @} */

/* The count of SINC_CMPDATA */
#define SINC_CMPDATA_COUNT                       (5U)

/*! @name CACFR - Channel 0 Advanced Configuration..Channel 4 Advanced Configuration */
/*! @{ */

#define SINC_CACFR_ADMASEL_MASK                  (0xF000U)
#define SINC_CACFR_ADMASEL_SHIFT                 (12U)
/*! ADMASEL - Alternate DMA Source Selection
 *  0b0000..Alternate DMA disabled
 *  0b0001..PF conversion complete
 *  0b0010..PF data output ready
 *  0b0011..Zero crossing detected
 *  0b0100..Short circuit detected
 *  0b0101..Window limit detected
 *  0b0110..Low limit detected
 *  0b0111..High limit
 *  0b1000..FIFO underflow
 *  0b1001..FIFO overflow
 *  0b1010..Clock absence
 *  0b1011..Saturation
 */
#define SINC_CACFR_ADMASEL(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_CACFR_ADMASEL_SHIFT)) & SINC_CACFR_ADMASEL_MASK)

#define SINC_CACFR_HPFA_MASK                     (0xF0000U)
#define SINC_CACFR_HPFA_SHIFT                    (16U)
/*! HPFA - HPF DC Remover Alpha Coefficient */
#define SINC_CACFR_HPFA(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CACFR_HPFA_SHIFT)) & SINC_CACFR_HPFA_MASK)

#define SINC_CACFR_IBDLY_MASK                    (0xF00000U)
#define SINC_CACFR_IBDLY_SHIFT                   (20U)
/*! IBDLY - Input Modulator Bitstream Delay
 *  0b0000..Disabled
 *  *..Delay in clock cycles
 */
#define SINC_CACFR_IBDLY(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CACFR_IBDLY_SHIFT)) & SINC_CACFR_IBDLY_MASK)
/*! @} */

/* The count of SINC_CACFR */
#define SINC_CACFR_COUNT                         (5U)

/*! @name CSR - Channel 0 Status..Channel 4 Status */
/*! @{ */

#define SINC_CSR_FIFOAVIL_MASK                   (0x1FU)
#define SINC_CSR_FIFOAVIL_SHIFT                  (0U)
/*! FIFOAVIL - FIFO Available Data */
#define SINC_CSR_FIFOAVIL(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CSR_FIFOAVIL_SHIFT)) & SINC_CSR_FIFOAVIL_MASK)

#define SINC_CSR_PSRDY_MASK                      (0x80U)
#define SINC_CSR_PSRDY_SHIFT                     (7U)
/*! PSRDY - Parallel or Serial Data Ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SINC_CSR_PSRDY(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CSR_PSRDY_SHIFT)) & SINC_CSR_PSRDY_MASK)

#define SINC_CSR_PFSAT_MASK                      (0x100U)
#define SINC_CSR_PFSAT_SHIFT                     (8U)
/*! PFSAT - Primary CIC Saturation Flag
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define SINC_CSR_PFSAT(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CSR_PFSAT_SHIFT)) & SINC_CSR_PFSAT_MASK)

#define SINC_CSR_HPFSAT_MASK                     (0x200U)
#define SINC_CSR_HPFSAT_SHIFT                    (9U)
/*! HPFSAT - HPF Saturation Flag
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define SINC_CSR_HPFSAT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CSR_HPFSAT_SHIFT)) & SINC_CSR_HPFSAT_MASK)

#define SINC_CSR_SFTSAT_MASK                     (0x400U)
#define SINC_CSR_SFTSAT_SHIFT                    (10U)
/*! SFTSAT - Shift Saturation Flag
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define SINC_CSR_SFTSAT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CSR_SFTSAT_SHIFT)) & SINC_CSR_SFTSAT_MASK)

#define SINC_CSR_BIASSAT_MASK                    (0x800U)
#define SINC_CSR_BIASSAT_SHIFT                   (11U)
/*! BIASSAT - Bias Saturation Flag
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define SINC_CSR_BIASSAT(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CSR_BIASSAT_SHIFT)) & SINC_CSR_BIASSAT_MASK)

#define SINC_CSR_RDRS_MASK                       (0x1000U)
#define SINC_CSR_RDRS_SHIFT                      (12U)
/*! RDRS - Result Data Direct Read Status
 *  0b0..Valid
 *  0b1..Invalid
 */
#define SINC_CSR_RDRS(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CSR_RDRS_SHIFT)) & SINC_CSR_RDRS_MASK)

#define SINC_CSR_SRDS_MASK                       (0x2000U)
#define SINC_CSR_SRDS_SHIFT                      (13U)
/*! SRDS - Start Read Debug Data Sync
 *  0b0..Data valid
 *  0b0..No effect
 *  0b1..Procedure in progress
 *  0b1..Starts the procedure
 */
#define SINC_CSR_SRDS(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CSR_SRDS_SHIFT)) & SINC_CSR_SRDS_MASK)

#define SINC_CSR_DBGRS_MASK                      (0xC000U)
#define SINC_CSR_DBGRS_SHIFT                     (14U)
/*! DBGRS - Debug Data Read Status
 *  0b00..Valid
 *  0b01-0b11..Invalid
 */
#define SINC_CSR_DBGRS(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CSR_DBGRS_SHIFT)) & SINC_CSR_DBGRS_MASK)

#define SINC_CSR_CNUM_MASK                       (0x7F0000U)
#define SINC_CSR_CNUM_SHIFT                      (16U)
/*! CNUM - Number Of Conversions */
#define SINC_CSR_CNUM(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CSR_CNUM_SHIFT)) & SINC_CSR_CNUM_MASK)

#define SINC_CSR_CNUM_OV_MASK                    (0x800000U)
#define SINC_CSR_CNUM_OV_SHIFT                   (23U)
/*! CNUM_OV - Overflow In Number Of Conversions
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define SINC_CSR_CNUM_OV(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CSR_CNUM_OV_SHIFT)) & SINC_CSR_CNUM_OV_MASK)
/*! @} */

/* The count of SINC_CSR */
#define SINC_CSR_COUNT                           (5U)

/*! @name CDBGR - Channel 0 Debug..Channel 4 Debug */
/*! @{ */

#define SINC_CDBGR_DBGDATA_MASK                  (0xFFFFFFFFU)
#define SINC_CDBGR_DBGDATA_SHIFT                 (0U)
/*! DBGDATA - Debug Data */
#define SINC_CDBGR_DBGDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_CDBGR_DBGDATA_SHIFT)) & SINC_CDBGR_DBGDATA_MASK)
/*! @} */

/* The count of SINC_CDBGR */
#define SINC_CDBGR_COUNT                         (5U)


/*!
 * @}
 */ /* end of group SINC_Register_Masks */


/*!
 * @}
 */ /* end of group SINC_Peripheral_Access_Layer */


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


#endif  /* PERI_SINC_H_ */

