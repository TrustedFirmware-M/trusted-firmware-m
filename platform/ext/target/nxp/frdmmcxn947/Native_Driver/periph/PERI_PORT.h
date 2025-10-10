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
**         CMSIS Peripheral Access Layer for PORT
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
 * @file PERI_PORT.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PORT
 *
 * CMSIS Peripheral Access Layer for PORT
 */

#if !defined(PERI_PORT_H_)
#define PERI_PORT_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                            32u

/** PORT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t GPCLR;                             /**< Global Pin Control Low, offset: 0x10 */
  __IO uint32_t GPCHR;                             /**< Global Pin Control High, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CONFIG;                            /**< Configuration, offset: 0x20 */
       uint8_t RESERVED_2[28];
  __I  uint32_t EDFR;                              /**< EFT Detect Flag, offset: 0x40 */
  __IO uint32_t EDIER;                             /**< EFT Detect Interrupt Enable, offset: 0x44 */
  __IO uint32_t EDCR;                              /**< EFT Detect Clear, offset: 0x48 */
       uint8_t RESERVED_3[20];
  __IO uint32_t CALIB0;                            /**< Calibration 0, offset: 0x60, available only on: PORT0, PORT1, PORT2, PORT3 (missing on PORT4, PORT5) */
  __IO uint32_t CALIB1;                            /**< Calibration 1, offset: 0x64, available only on: PORT0, PORT1, PORT2, PORT3 (missing on PORT4, PORT5) */
       uint8_t RESERVED_4[24];
  __IO uint32_t PCR[PORT_PCR_COUNT];               /**< Pin Control 0..Pin Control 31, array offset: 0x80, array step: 0x4, irregular array, not all indices are valid */
} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define PORT_VERID_FEATURE_MASK                  (0xFFFFU)
#define PORT_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Basic implementation
 */
#define PORT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << PORT_VERID_FEATURE_SHIFT)) & PORT_VERID_FEATURE_MASK)

#define PORT_VERID_MINOR_MASK                    (0xFF0000U)
#define PORT_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define PORT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_VERID_MINOR_SHIFT)) & PORT_VERID_MINOR_MASK)

#define PORT_VERID_MAJOR_MASK                    (0xFF000000U)
#define PORT_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define PORT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_VERID_MAJOR_SHIFT)) & PORT_VERID_MAJOR_MASK)
/*! @} */

/*! @name GPCLR - Global Pin Control Low */
/*! @{ */

#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCLR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWD_SHIFT)) & PORT_GPCLR_GPWD_MASK)

#define PORT_GPCLR_GPWE0_MASK                    (0x10000U)
#define PORT_GPCLR_GPWE0_SHIFT                   (16U)
/*! GPWE0 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE0_SHIFT)) & PORT_GPCLR_GPWE0_MASK)

#define PORT_GPCLR_GPWE1_MASK                    (0x20000U)
#define PORT_GPCLR_GPWE1_SHIFT                   (17U)
/*! GPWE1 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE1_SHIFT)) & PORT_GPCLR_GPWE1_MASK)

#define PORT_GPCLR_GPWE2_MASK                    (0x40000U)
#define PORT_GPCLR_GPWE2_SHIFT                   (18U)
/*! GPWE2 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE2_SHIFT)) & PORT_GPCLR_GPWE2_MASK)

#define PORT_GPCLR_GPWE3_MASK                    (0x80000U)
#define PORT_GPCLR_GPWE3_SHIFT                   (19U)
/*! GPWE3 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE3_SHIFT)) & PORT_GPCLR_GPWE3_MASK)

#define PORT_GPCLR_GPWE4_MASK                    (0x100000U)
#define PORT_GPCLR_GPWE4_SHIFT                   (20U)
/*! GPWE4 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE4_SHIFT)) & PORT_GPCLR_GPWE4_MASK)

#define PORT_GPCLR_GPWE5_MASK                    (0x200000U)
#define PORT_GPCLR_GPWE5_SHIFT                   (21U)
/*! GPWE5 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE5_SHIFT)) & PORT_GPCLR_GPWE5_MASK)

#define PORT_GPCLR_GPWE6_MASK                    (0x400000U)
#define PORT_GPCLR_GPWE6_SHIFT                   (22U)
/*! GPWE6 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE6_SHIFT)) & PORT_GPCLR_GPWE6_MASK)

#define PORT_GPCLR_GPWE7_MASK                    (0x800000U)
#define PORT_GPCLR_GPWE7_SHIFT                   (23U)
/*! GPWE7 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE7_SHIFT)) & PORT_GPCLR_GPWE7_MASK)

#define PORT_GPCLR_GPWE8_MASK                    (0x1000000U)
#define PORT_GPCLR_GPWE8_SHIFT                   (24U)
/*! GPWE8 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE8(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE8_SHIFT)) & PORT_GPCLR_GPWE8_MASK)

#define PORT_GPCLR_GPWE9_MASK                    (0x2000000U)
#define PORT_GPCLR_GPWE9_SHIFT                   (25U)
/*! GPWE9 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE9(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE9_SHIFT)) & PORT_GPCLR_GPWE9_MASK)

#define PORT_GPCLR_GPWE10_MASK                   (0x4000000U)
#define PORT_GPCLR_GPWE10_SHIFT                  (26U)
/*! GPWE10 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE10(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE10_SHIFT)) & PORT_GPCLR_GPWE10_MASK)

#define PORT_GPCLR_GPWE11_MASK                   (0x8000000U)
#define PORT_GPCLR_GPWE11_SHIFT                  (27U)
/*! GPWE11 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE11(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE11_SHIFT)) & PORT_GPCLR_GPWE11_MASK)

#define PORT_GPCLR_GPWE12_MASK                   (0x10000000U)
#define PORT_GPCLR_GPWE12_SHIFT                  (28U)
/*! GPWE12 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE12(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE12_SHIFT)) & PORT_GPCLR_GPWE12_MASK)

#define PORT_GPCLR_GPWE13_MASK                   (0x20000000U)
#define PORT_GPCLR_GPWE13_SHIFT                  (29U)
/*! GPWE13 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE13(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE13_SHIFT)) & PORT_GPCLR_GPWE13_MASK)

#define PORT_GPCLR_GPWE14_MASK                   (0x40000000U)
#define PORT_GPCLR_GPWE14_SHIFT                  (30U)
/*! GPWE14 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE14(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE14_SHIFT)) & PORT_GPCLR_GPWE14_MASK)

#define PORT_GPCLR_GPWE15_MASK                   (0x80000000U)
#define PORT_GPCLR_GPWE15_SHIFT                  (31U)
/*! GPWE15 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE15(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE15_SHIFT)) & PORT_GPCLR_GPWE15_MASK)
/*! @} */

/*! @name GPCHR - Global Pin Control High */
/*! @{ */

#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCHR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWD_SHIFT)) & PORT_GPCHR_GPWD_MASK)

#define PORT_GPCHR_GPWE16_MASK                   (0x10000U)
#define PORT_GPCHR_GPWE16_SHIFT                  (16U)
/*! GPWE16 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE16(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE16_SHIFT)) & PORT_GPCHR_GPWE16_MASK)

#define PORT_GPCHR_GPWE17_MASK                   (0x20000U)
#define PORT_GPCHR_GPWE17_SHIFT                  (17U)
/*! GPWE17 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE17(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE17_SHIFT)) & PORT_GPCHR_GPWE17_MASK)

#define PORT_GPCHR_GPWE18_MASK                   (0x40000U)
#define PORT_GPCHR_GPWE18_SHIFT                  (18U)
/*! GPWE18 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE18(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE18_SHIFT)) & PORT_GPCHR_GPWE18_MASK)

#define PORT_GPCHR_GPWE19_MASK                   (0x80000U)
#define PORT_GPCHR_GPWE19_SHIFT                  (19U)
/*! GPWE19 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE19(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE19_SHIFT)) & PORT_GPCHR_GPWE19_MASK)

#define PORT_GPCHR_GPWE20_MASK                   (0x100000U)
#define PORT_GPCHR_GPWE20_SHIFT                  (20U)
/*! GPWE20 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE20(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE20_SHIFT)) & PORT_GPCHR_GPWE20_MASK)

#define PORT_GPCHR_GPWE21_MASK                   (0x200000U)
#define PORT_GPCHR_GPWE21_SHIFT                  (21U)
/*! GPWE21 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE21(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE21_SHIFT)) & PORT_GPCHR_GPWE21_MASK)

#define PORT_GPCHR_GPWE22_MASK                   (0x400000U)
#define PORT_GPCHR_GPWE22_SHIFT                  (22U)
/*! GPWE22 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE22(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE22_SHIFT)) & PORT_GPCHR_GPWE22_MASK)

#define PORT_GPCHR_GPWE23_MASK                   (0x800000U)
#define PORT_GPCHR_GPWE23_SHIFT                  (23U)
/*! GPWE23 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE23(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE23_SHIFT)) & PORT_GPCHR_GPWE23_MASK)

#define PORT_GPCHR_GPWE24_MASK                   (0x1000000U)
#define PORT_GPCHR_GPWE24_SHIFT                  (24U)
/*! GPWE24 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE24(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE24_SHIFT)) & PORT_GPCHR_GPWE24_MASK)

#define PORT_GPCHR_GPWE25_MASK                   (0x2000000U)
#define PORT_GPCHR_GPWE25_SHIFT                  (25U)
/*! GPWE25 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE25(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE25_SHIFT)) & PORT_GPCHR_GPWE25_MASK)

#define PORT_GPCHR_GPWE26_MASK                   (0x4000000U)
#define PORT_GPCHR_GPWE26_SHIFT                  (26U)
/*! GPWE26 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE26(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE26_SHIFT)) & PORT_GPCHR_GPWE26_MASK)

#define PORT_GPCHR_GPWE27_MASK                   (0x8000000U)
#define PORT_GPCHR_GPWE27_SHIFT                  (27U)
/*! GPWE27 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE27(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE27_SHIFT)) & PORT_GPCHR_GPWE27_MASK)

#define PORT_GPCHR_GPWE28_MASK                   (0x10000000U)
#define PORT_GPCHR_GPWE28_SHIFT                  (28U)
/*! GPWE28 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE28(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE28_SHIFT)) & PORT_GPCHR_GPWE28_MASK)

#define PORT_GPCHR_GPWE29_MASK                   (0x20000000U)
#define PORT_GPCHR_GPWE29_SHIFT                  (29U)
/*! GPWE29 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE29(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE29_SHIFT)) & PORT_GPCHR_GPWE29_MASK)

#define PORT_GPCHR_GPWE30_MASK                   (0x40000000U)
#define PORT_GPCHR_GPWE30_SHIFT                  (30U)
/*! GPWE30 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE30(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE30_SHIFT)) & PORT_GPCHR_GPWE30_MASK)

#define PORT_GPCHR_GPWE31_MASK                   (0x80000000U)
#define PORT_GPCHR_GPWE31_SHIFT                  (31U)
/*! GPWE31 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE31(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE31_SHIFT)) & PORT_GPCHR_GPWE31_MASK)
/*! @} */

/*! @name CONFIG - Configuration */
/*! @{ */

#define PORT_CONFIG_RANGE_MASK                   (0x1U)
#define PORT_CONFIG_RANGE_SHIFT                  (0U)
/*! RANGE - Port Voltage Range
 *  0b0..1.71 V-3.6 V
 *  0b1..2.70 V-3.6 V
 */
#define PORT_CONFIG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_CONFIG_RANGE_SHIFT)) & PORT_CONFIG_RANGE_MASK)
/*! @} */

/*! @name EDFR - EFT Detect Flag */
/*! @{ */

#define PORT_EDFR_EDF0_MASK                      (0x1U)
#define PORT_EDFR_EDF0_SHIFT                     (0U)
/*! EDF0 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF0(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF0_SHIFT)) & PORT_EDFR_EDF0_MASK)

#define PORT_EDFR_EDF1_MASK                      (0x2U)
#define PORT_EDFR_EDF1_SHIFT                     (1U)
/*! EDF1 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF1(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF1_SHIFT)) & PORT_EDFR_EDF1_MASK)

#define PORT_EDFR_EDF2_MASK                      (0x4U)
#define PORT_EDFR_EDF2_SHIFT                     (2U)
/*! EDF2 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF2(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF2_SHIFT)) & PORT_EDFR_EDF2_MASK)

#define PORT_EDFR_EDF3_MASK                      (0x8U)
#define PORT_EDFR_EDF3_SHIFT                     (3U)
/*! EDF3 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF3(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF3_SHIFT)) & PORT_EDFR_EDF3_MASK)

#define PORT_EDFR_EDF4_MASK                      (0x10U)
#define PORT_EDFR_EDF4_SHIFT                     (4U)
/*! EDF4 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF4(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF4_SHIFT)) & PORT_EDFR_EDF4_MASK)

#define PORT_EDFR_EDF5_MASK                      (0x20U)
#define PORT_EDFR_EDF5_SHIFT                     (5U)
/*! EDF5 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF5(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF5_SHIFT)) & PORT_EDFR_EDF5_MASK)

#define PORT_EDFR_EDF6_MASK                      (0x40U)
#define PORT_EDFR_EDF6_SHIFT                     (6U)
/*! EDF6 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF6(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF6_SHIFT)) & PORT_EDFR_EDF6_MASK)

#define PORT_EDFR_EDF7_MASK                      (0x80U)
#define PORT_EDFR_EDF7_SHIFT                     (7U)
/*! EDF7 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF7(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF7_SHIFT)) & PORT_EDFR_EDF7_MASK)

#define PORT_EDFR_EDF8_MASK                      (0x100U)
#define PORT_EDFR_EDF8_SHIFT                     (8U)
/*! EDF8 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF8(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF8_SHIFT)) & PORT_EDFR_EDF8_MASK)

#define PORT_EDFR_EDF9_MASK                      (0x200U)
#define PORT_EDFR_EDF9_SHIFT                     (9U)
/*! EDF9 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF9(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF9_SHIFT)) & PORT_EDFR_EDF9_MASK)

#define PORT_EDFR_EDF10_MASK                     (0x400U)
#define PORT_EDFR_EDF10_SHIFT                    (10U)
/*! EDF10 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF10(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF10_SHIFT)) & PORT_EDFR_EDF10_MASK)

#define PORT_EDFR_EDF11_MASK                     (0x800U)
#define PORT_EDFR_EDF11_SHIFT                    (11U)
/*! EDF11 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF11(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF11_SHIFT)) & PORT_EDFR_EDF11_MASK)

#define PORT_EDFR_EDF12_MASK                     (0x1000U)
#define PORT_EDFR_EDF12_SHIFT                    (12U)
/*! EDF12 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF12(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF12_SHIFT)) & PORT_EDFR_EDF12_MASK)

#define PORT_EDFR_EDF13_MASK                     (0x2000U)
#define PORT_EDFR_EDF13_SHIFT                    (13U)
/*! EDF13 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF13(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF13_SHIFT)) & PORT_EDFR_EDF13_MASK)

#define PORT_EDFR_EDF14_MASK                     (0x4000U)
#define PORT_EDFR_EDF14_SHIFT                    (14U)
/*! EDF14 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF14(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF14_SHIFT)) & PORT_EDFR_EDF14_MASK)

#define PORT_EDFR_EDF15_MASK                     (0x8000U)
#define PORT_EDFR_EDF15_SHIFT                    (15U)
/*! EDF15 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF15(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF15_SHIFT)) & PORT_EDFR_EDF15_MASK)

#define PORT_EDFR_EDF16_MASK                     (0x10000U)
#define PORT_EDFR_EDF16_SHIFT                    (16U)
/*! EDF16 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF16(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF16_SHIFT)) & PORT_EDFR_EDF16_MASK)

#define PORT_EDFR_EDF17_MASK                     (0x20000U)
#define PORT_EDFR_EDF17_SHIFT                    (17U)
/*! EDF17 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF17(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF17_SHIFT)) & PORT_EDFR_EDF17_MASK)

#define PORT_EDFR_EDF18_MASK                     (0x40000U)
#define PORT_EDFR_EDF18_SHIFT                    (18U)
/*! EDF18 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF18(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF18_SHIFT)) & PORT_EDFR_EDF18_MASK)

#define PORT_EDFR_EDF19_MASK                     (0x80000U)
#define PORT_EDFR_EDF19_SHIFT                    (19U)
/*! EDF19 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF19(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF19_SHIFT)) & PORT_EDFR_EDF19_MASK)

#define PORT_EDFR_EDF20_MASK                     (0x100000U)
#define PORT_EDFR_EDF20_SHIFT                    (20U)
/*! EDF20 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF20(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF20_SHIFT)) & PORT_EDFR_EDF20_MASK)

#define PORT_EDFR_EDF21_MASK                     (0x200000U)
#define PORT_EDFR_EDF21_SHIFT                    (21U)
/*! EDF21 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF21(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF21_SHIFT)) & PORT_EDFR_EDF21_MASK)

#define PORT_EDFR_EDF22_MASK                     (0x400000U)
#define PORT_EDFR_EDF22_SHIFT                    (22U)
/*! EDF22 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF22(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF22_SHIFT)) & PORT_EDFR_EDF22_MASK)

#define PORT_EDFR_EDF23_MASK                     (0x800000U)
#define PORT_EDFR_EDF23_SHIFT                    (23U)
/*! EDF23 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF23(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF23_SHIFT)) & PORT_EDFR_EDF23_MASK)

#define PORT_EDFR_EDF24_MASK                     (0x1000000U)
#define PORT_EDFR_EDF24_SHIFT                    (24U)
/*! EDF24 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF24(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF24_SHIFT)) & PORT_EDFR_EDF24_MASK)

#define PORT_EDFR_EDF25_MASK                     (0x2000000U)
#define PORT_EDFR_EDF25_SHIFT                    (25U)
/*! EDF25 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF25(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF25_SHIFT)) & PORT_EDFR_EDF25_MASK)

#define PORT_EDFR_EDF26_MASK                     (0x4000000U)
#define PORT_EDFR_EDF26_SHIFT                    (26U)
/*! EDF26 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF26(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF26_SHIFT)) & PORT_EDFR_EDF26_MASK)

#define PORT_EDFR_EDF27_MASK                     (0x8000000U)
#define PORT_EDFR_EDF27_SHIFT                    (27U)
/*! EDF27 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF27(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF27_SHIFT)) & PORT_EDFR_EDF27_MASK)

#define PORT_EDFR_EDF28_MASK                     (0x10000000U)
#define PORT_EDFR_EDF28_SHIFT                    (28U)
/*! EDF28 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF28(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF28_SHIFT)) & PORT_EDFR_EDF28_MASK)

#define PORT_EDFR_EDF29_MASK                     (0x20000000U)
#define PORT_EDFR_EDF29_SHIFT                    (29U)
/*! EDF29 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF29(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF29_SHIFT)) & PORT_EDFR_EDF29_MASK)

#define PORT_EDFR_EDF30_MASK                     (0x40000000U)
#define PORT_EDFR_EDF30_SHIFT                    (30U)
/*! EDF30 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF30(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF30_SHIFT)) & PORT_EDFR_EDF30_MASK)

#define PORT_EDFR_EDF31_MASK                     (0x80000000U)
#define PORT_EDFR_EDF31_SHIFT                    (31U)
/*! EDF31 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF31(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF31_SHIFT)) & PORT_EDFR_EDF31_MASK)
/*! @} */

/*! @name EDIER - EFT Detect Interrupt Enable */
/*! @{ */

#define PORT_EDIER_EDIE0_MASK                    (0x1U)
#define PORT_EDIER_EDIE0_SHIFT                   (0U)
/*! EDIE0 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE0_SHIFT)) & PORT_EDIER_EDIE0_MASK)

#define PORT_EDIER_EDIE1_MASK                    (0x2U)
#define PORT_EDIER_EDIE1_SHIFT                   (1U)
/*! EDIE1 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE1_SHIFT)) & PORT_EDIER_EDIE1_MASK)

#define PORT_EDIER_EDIE2_MASK                    (0x4U)
#define PORT_EDIER_EDIE2_SHIFT                   (2U)
/*! EDIE2 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE2_SHIFT)) & PORT_EDIER_EDIE2_MASK)

#define PORT_EDIER_EDIE3_MASK                    (0x8U)
#define PORT_EDIER_EDIE3_SHIFT                   (3U)
/*! EDIE3 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE3_SHIFT)) & PORT_EDIER_EDIE3_MASK)

#define PORT_EDIER_EDIE4_MASK                    (0x10U)
#define PORT_EDIER_EDIE4_SHIFT                   (4U)
/*! EDIE4 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE4_SHIFT)) & PORT_EDIER_EDIE4_MASK)

#define PORT_EDIER_EDIE5_MASK                    (0x20U)
#define PORT_EDIER_EDIE5_SHIFT                   (5U)
/*! EDIE5 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE5_SHIFT)) & PORT_EDIER_EDIE5_MASK)

#define PORT_EDIER_EDIE6_MASK                    (0x40U)
#define PORT_EDIER_EDIE6_SHIFT                   (6U)
/*! EDIE6 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE6_SHIFT)) & PORT_EDIER_EDIE6_MASK)

#define PORT_EDIER_EDIE7_MASK                    (0x80U)
#define PORT_EDIER_EDIE7_SHIFT                   (7U)
/*! EDIE7 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE7_SHIFT)) & PORT_EDIER_EDIE7_MASK)

#define PORT_EDIER_EDIE8_MASK                    (0x100U)
#define PORT_EDIER_EDIE8_SHIFT                   (8U)
/*! EDIE8 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE8(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE8_SHIFT)) & PORT_EDIER_EDIE8_MASK)

#define PORT_EDIER_EDIE9_MASK                    (0x200U)
#define PORT_EDIER_EDIE9_SHIFT                   (9U)
/*! EDIE9 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE9(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE9_SHIFT)) & PORT_EDIER_EDIE9_MASK)

#define PORT_EDIER_EDIE10_MASK                   (0x400U)
#define PORT_EDIER_EDIE10_SHIFT                  (10U)
/*! EDIE10 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE10(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE10_SHIFT)) & PORT_EDIER_EDIE10_MASK)

#define PORT_EDIER_EDIE11_MASK                   (0x800U)
#define PORT_EDIER_EDIE11_SHIFT                  (11U)
/*! EDIE11 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE11(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE11_SHIFT)) & PORT_EDIER_EDIE11_MASK)

#define PORT_EDIER_EDIE12_MASK                   (0x1000U)
#define PORT_EDIER_EDIE12_SHIFT                  (12U)
/*! EDIE12 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE12(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE12_SHIFT)) & PORT_EDIER_EDIE12_MASK)

#define PORT_EDIER_EDIE13_MASK                   (0x2000U)
#define PORT_EDIER_EDIE13_SHIFT                  (13U)
/*! EDIE13 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE13(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE13_SHIFT)) & PORT_EDIER_EDIE13_MASK)

#define PORT_EDIER_EDIE14_MASK                   (0x4000U)
#define PORT_EDIER_EDIE14_SHIFT                  (14U)
/*! EDIE14 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE14(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE14_SHIFT)) & PORT_EDIER_EDIE14_MASK)

#define PORT_EDIER_EDIE15_MASK                   (0x8000U)
#define PORT_EDIER_EDIE15_SHIFT                  (15U)
/*! EDIE15 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE15(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE15_SHIFT)) & PORT_EDIER_EDIE15_MASK)

#define PORT_EDIER_EDIE16_MASK                   (0x10000U)
#define PORT_EDIER_EDIE16_SHIFT                  (16U)
/*! EDIE16 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE16(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE16_SHIFT)) & PORT_EDIER_EDIE16_MASK)

#define PORT_EDIER_EDIE17_MASK                   (0x20000U)
#define PORT_EDIER_EDIE17_SHIFT                  (17U)
/*! EDIE17 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE17(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE17_SHIFT)) & PORT_EDIER_EDIE17_MASK)

#define PORT_EDIER_EDIE18_MASK                   (0x40000U)
#define PORT_EDIER_EDIE18_SHIFT                  (18U)
/*! EDIE18 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE18(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE18_SHIFT)) & PORT_EDIER_EDIE18_MASK)

#define PORT_EDIER_EDIE19_MASK                   (0x80000U)
#define PORT_EDIER_EDIE19_SHIFT                  (19U)
/*! EDIE19 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE19(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE19_SHIFT)) & PORT_EDIER_EDIE19_MASK)

#define PORT_EDIER_EDIE20_MASK                   (0x100000U)
#define PORT_EDIER_EDIE20_SHIFT                  (20U)
/*! EDIE20 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE20(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE20_SHIFT)) & PORT_EDIER_EDIE20_MASK)

#define PORT_EDIER_EDIE21_MASK                   (0x200000U)
#define PORT_EDIER_EDIE21_SHIFT                  (21U)
/*! EDIE21 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE21(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE21_SHIFT)) & PORT_EDIER_EDIE21_MASK)

#define PORT_EDIER_EDIE22_MASK                   (0x400000U)
#define PORT_EDIER_EDIE22_SHIFT                  (22U)
/*! EDIE22 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE22(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE22_SHIFT)) & PORT_EDIER_EDIE22_MASK)

#define PORT_EDIER_EDIE23_MASK                   (0x800000U)
#define PORT_EDIER_EDIE23_SHIFT                  (23U)
/*! EDIE23 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE23(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE23_SHIFT)) & PORT_EDIER_EDIE23_MASK)

#define PORT_EDIER_EDIE24_MASK                   (0x1000000U)
#define PORT_EDIER_EDIE24_SHIFT                  (24U)
/*! EDIE24 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE24(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE24_SHIFT)) & PORT_EDIER_EDIE24_MASK)

#define PORT_EDIER_EDIE25_MASK                   (0x2000000U)
#define PORT_EDIER_EDIE25_SHIFT                  (25U)
/*! EDIE25 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE25(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE25_SHIFT)) & PORT_EDIER_EDIE25_MASK)

#define PORT_EDIER_EDIE26_MASK                   (0x4000000U)
#define PORT_EDIER_EDIE26_SHIFT                  (26U)
/*! EDIE26 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE26(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE26_SHIFT)) & PORT_EDIER_EDIE26_MASK)

#define PORT_EDIER_EDIE27_MASK                   (0x8000000U)
#define PORT_EDIER_EDIE27_SHIFT                  (27U)
/*! EDIE27 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE27(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE27_SHIFT)) & PORT_EDIER_EDIE27_MASK)

#define PORT_EDIER_EDIE28_MASK                   (0x10000000U)
#define PORT_EDIER_EDIE28_SHIFT                  (28U)
/*! EDIE28 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE28(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE28_SHIFT)) & PORT_EDIER_EDIE28_MASK)

#define PORT_EDIER_EDIE29_MASK                   (0x20000000U)
#define PORT_EDIER_EDIE29_SHIFT                  (29U)
/*! EDIE29 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE29(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE29_SHIFT)) & PORT_EDIER_EDIE29_MASK)

#define PORT_EDIER_EDIE30_MASK                   (0x40000000U)
#define PORT_EDIER_EDIE30_SHIFT                  (30U)
/*! EDIE30 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE30(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE30_SHIFT)) & PORT_EDIER_EDIE30_MASK)

#define PORT_EDIER_EDIE31_MASK                   (0x80000000U)
#define PORT_EDIER_EDIE31_SHIFT                  (31U)
/*! EDIE31 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE31(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE31_SHIFT)) & PORT_EDIER_EDIE31_MASK)
/*! @} */

/*! @name EDCR - EFT Detect Clear */
/*! @{ */

#define PORT_EDCR_EDHC_MASK                      (0x1U)
#define PORT_EDCR_EDHC_SHIFT                     (0U)
/*! EDHC - EFT Detect High Clear
 *  0b0..Does not clear
 *  0b1..Clears
 */
#define PORT_EDCR_EDHC(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDCR_EDHC_SHIFT)) & PORT_EDCR_EDHC_MASK)

#define PORT_EDCR_EDLC_MASK                      (0x2U)
#define PORT_EDCR_EDLC_SHIFT                     (1U)
/*! EDLC - EFT Detect Low Clear
 *  0b0..Does not clear
 *  0b1..Clears
 */
#define PORT_EDCR_EDLC(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDCR_EDLC_SHIFT)) & PORT_EDCR_EDLC_MASK)
/*! @} */

/*! @name CALIB0 - Calibration 0 */
/*! @{ */

#define PORT_CALIB0_NCAL_MASK                    (0x3FU)
#define PORT_CALIB0_NCAL_SHIFT                   (0U)
/*! NCAL - Calibration of NMOS Output Driver */
#define PORT_CALIB0_NCAL(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_CALIB0_NCAL_SHIFT)) & PORT_CALIB0_NCAL_MASK)

#define PORT_CALIB0_PCAL_MASK                    (0x3F0000U)
#define PORT_CALIB0_PCAL_SHIFT                   (16U)
/*! PCAL - Calibration of PMOS Output Driver */
#define PORT_CALIB0_PCAL(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_CALIB0_PCAL_SHIFT)) & PORT_CALIB0_PCAL_MASK)
/*! @} */

/*! @name CALIB1 - Calibration 1 */
/*! @{ */

#define PORT_CALIB1_NCAL_MASK                    (0x3FU)
#define PORT_CALIB1_NCAL_SHIFT                   (0U)
/*! NCAL - Calibration of NMOS Output Driver */
#define PORT_CALIB1_NCAL(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_CALIB1_NCAL_SHIFT)) & PORT_CALIB1_NCAL_MASK)

#define PORT_CALIB1_PCAL_MASK                    (0x3F0000U)
#define PORT_CALIB1_PCAL_SHIFT                   (16U)
/*! PCAL - Calibration of PMOS Output Driver */
#define PORT_CALIB1_PCAL(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_CALIB1_PCAL_SHIFT)) & PORT_CALIB1_PCAL_MASK)
/*! @} */

/*! @name PCR - Pin Control 0..Pin Control 31 */
/*! @{ */

#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
/*! PS - Pull Select
 *  0b0..Enables internal pulldown resistor
 *  0b1..Enables internal pullup resistor
 */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)

#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
/*! PE - Pull Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)

#define PORT_PCR_PV_MASK                         (0x4U)
#define PORT_PCR_PV_SHIFT                        (2U)
/*! PV - Pull Value
 *  0b0..Low
 *  0b1..High
 */
#define PORT_PCR_PV(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PV_SHIFT)) & PORT_PCR_PV_MASK)

#define PORT_PCR_SRE_MASK                        (0x8U)
#define PORT_PCR_SRE_SHIFT                       (3U)
/*! SRE - Slew Rate Enable
 *  0b0..Fast
 *  0b1..Slow
 */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_SRE_SHIFT)) & PORT_PCR_SRE_MASK)

#define PORT_PCR_PFE_MASK                        (0x10U)
#define PORT_PCR_PFE_SHIFT                       (4U)
/*! PFE - Passive Filter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PFE_SHIFT)) & PORT_PCR_PFE_MASK)

#define PORT_PCR_ODE_MASK                        (0x20U)
#define PORT_PCR_ODE_SHIFT                       (5U)
/*! ODE - Open Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ODE_SHIFT)) & PORT_PCR_ODE_MASK)

#define PORT_PCR_DSE_MASK                        (0x40U)
#define PORT_PCR_DSE_SHIFT                       (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Low
 *  0b1..High
 */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DSE_SHIFT)) & PORT_PCR_DSE_MASK)

#define PORT_PCR_MUX_MASK                        (0xF00U)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define PORT_PCR_MUX_SHIFT                       (8U)
/*! MUX - Pin Multiplex Control
 *  0b0000..Alternative 0 (GPIO)
 *  0b0001..Alternative 1 (chip-specific)
 *  0b0010..Alternative 2 (chip-specific)
 *  0b0011..Alternative 3 (chip-specific)
 *  0b0100..Alternative 4 (chip-specific)
 *  0b0101..Alternative 5 (chip-specific)
 *  0b0110..Alternative 6 (chip-specific)
 *  0b0111..Alternative 7 (chip-specific)
 *  0b1000..Alternative 8 (chip-specific)
 *  0b1001..Alternative 9 (chip-specific)
 *  0b1010..Alternative 10 (chip-specific)
 *  0b1011..Alternative 11 (chip-specific)
 *  0b1100..Alternative 12 (chip-specific)
 *  0b1101..Alternative 13 (chip-specific)
 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */

#define PORT_PCR_IBE_MASK                        (0x1000U)
#define PORT_PCR_IBE_SHIFT                       (12U)
/*! IBE - Input Buffer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PORT_PCR_IBE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IBE_SHIFT)) & PORT_PCR_IBE_MASK)

#define PORT_PCR_INV_MASK                        (0x2000U)
#define PORT_PCR_INV_SHIFT                       (13U)
/*! INV - Invert Input
 *  0b0..Does not invert
 *  0b1..Inverts
 */
#define PORT_PCR_INV(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_INV_SHIFT)) & PORT_PCR_INV_MASK)

#define PORT_PCR_LK_MASK                         (0x8000U)
#define PORT_PCR_LK_SHIFT                        (15U)
/*! LK - Lock Register
 *  0b0..Does not lock
 *  0b1..Locks
 */
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_LK_SHIFT)) & PORT_PCR_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


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


#endif  /* PERI_PORT_H_ */

