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
**         CMSIS Peripheral Access Layer for GDET
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
 * @file PERI_GDET.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GDET
 *
 * CMSIS Peripheral Access Layer for GDET
 */

#if !defined(PERI_GDET_H_)
#define PERI_GDET_H_                             /**< Symbol preventing repeated inclusion */

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
   -- GDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Peripheral_Access_Layer GDET Peripheral Access Layer
 * @{
 */

/** GDET - Register Layout Typedef */
typedef struct {
  __IO uint32_t GDET_CONF_0;                       /**< GDET Configuration 0 Register, offset: 0x0 */
  __IO uint32_t GDET_CONF_1;                       /**< GDET Configuration 1 Register, offset: 0x4 */
  __IO uint32_t GDET_ENABLE1;                      /**< GDET Enable Register, offset: 0x8 */
  __IO uint32_t GDET_CONF_2;                       /**< GDET Configuration 2 Register, offset: 0xC */
  __IO uint32_t GDET_CONF_3;                       /**< GDET Configuration 3 Register, offset: 0x10 */
  __IO uint32_t GDET_CONF_4;                       /**< GDET Configuration 4 Register, offset: 0x14 */
  __IO uint32_t GDET_CONF_5;                       /**< GDET Configuration 5 Register, offset: 0x18 */
       uint8_t RESERVED_0[4004];
  __IO uint32_t GDET_RESET;                        /**< GDET Reset Register, offset: 0xFC0 */
  __IO uint32_t GDET_TEST;                         /**< GDET Test Register, offset: 0xFC4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t GDET_DLY_CTRL;                     /**< GDET Delay Control Register, offset: 0xFCC */
} GDET_Type;

/* ----------------------------------------------------------------------------
   -- GDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Register_Masks GDET Register Masks
 * @{
 */

/*! @name GDET_CONF_0 - GDET Configuration 0 Register */
/*! @{ */

#define GDET_GDET_CONF_0_FIELD_3_0_MASK          (0xFU)
#define GDET_GDET_CONF_0_FIELD_3_0_SHIFT         (0U)
/*! FIELD_3_0 - GDET Configuration 0 Field 3_0 */
#define GDET_GDET_CONF_0_FIELD_3_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_FIELD_3_0_SHIFT)) & GDET_GDET_CONF_0_FIELD_3_0_MASK)

#define GDET_GDET_CONF_0_FIELD_3_0_MASK          (0xFU)
#define GDET_GDET_CONF_0_FIELD_3_0_SHIFT         (0U)
/*! field_3_0 - GDET configuration 0 Field 3_0 */
#define GDET_GDET_CONF_0_FIELD_3_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_FIELD_3_0_SHIFT)) & GDET_GDET_CONF_0_FIELD_3_0_MASK)

#define GDET_GDET_CONF_0_SBZ_MASK                (0x10U)
#define GDET_GDET_CONF_0_SBZ_SHIFT               (4U)
/*! SBZ - Should Be Left to Zero */
#define GDET_GDET_CONF_0_SBZ(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_SBZ_SHIFT)) & GDET_GDET_CONF_0_SBZ_MASK)

#define GDET_GDET_CONF_0_SBZ_MASK                (0x10U)
#define GDET_GDET_CONF_0_SBZ_SHIFT               (4U)
/*! sbz - Should be left to zero */
#define GDET_GDET_CONF_0_SBZ(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_SBZ_SHIFT)) & GDET_GDET_CONF_0_SBZ_MASK)

#define GDET_GDET_CONF_0_RFU_MASK                (0xFFFFFFE0U)
#define GDET_GDET_CONF_0_RFU_SHIFT               (5U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_CONF_0_RFU(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_RFU_SHIFT)) & GDET_GDET_CONF_0_RFU_MASK)

#define GDET_GDET_CONF_0_RFU_MASK                (0xFFFFFFE0U)
#define GDET_GDET_CONF_0_RFU_SHIFT               (5U)
/*! rfu - Reserved for Future Use */
#define GDET_GDET_CONF_0_RFU(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_0_RFU_SHIFT)) & GDET_GDET_CONF_0_RFU_MASK)
/*! @} */

/*! @name GDET_CONF_1 - GDET Configuration 1 Register */
/*! @{ */

#define GDET_GDET_CONF_1_FIELD_1_0_MASK          (0x3U)
#define GDET_GDET_CONF_1_FIELD_1_0_SHIFT         (0U)
/*! FIELD_1_0 - GDET Configuration 1 Field 1_0 */
#define GDET_GDET_CONF_1_FIELD_1_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_1_0_SHIFT)) & GDET_GDET_CONF_1_FIELD_1_0_MASK)

#define GDET_GDET_CONF_1_FIELD_1_0_MASK          (0x3U)
#define GDET_GDET_CONF_1_FIELD_1_0_SHIFT         (0U)
/*! field_1_0 - GDET configuration 1 Field 1_0 */
#define GDET_GDET_CONF_1_FIELD_1_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_1_0_SHIFT)) & GDET_GDET_CONF_1_FIELD_1_0_MASK)

#define GDET_GDET_CONF_1_FIELD_3_2_MASK          (0xCU)
#define GDET_GDET_CONF_1_FIELD_3_2_SHIFT         (2U)
/*! FIELD_3_2 - GDET Configuration 1 Field 3_2 */
#define GDET_GDET_CONF_1_FIELD_3_2(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_3_2_SHIFT)) & GDET_GDET_CONF_1_FIELD_3_2_MASK)

#define GDET_GDET_CONF_1_FIELD_3_2_MASK          (0xCU)
#define GDET_GDET_CONF_1_FIELD_3_2_SHIFT         (2U)
/*! field_3_2 - GDET configuration 1 Field 3_2 */
#define GDET_GDET_CONF_1_FIELD_3_2(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_3_2_SHIFT)) & GDET_GDET_CONF_1_FIELD_3_2_MASK)

#define GDET_GDET_CONF_1_SBZ1_MASK               (0x10U)
#define GDET_GDET_CONF_1_SBZ1_SHIFT              (4U)
/*! SBZ1 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ1_SHIFT)) & GDET_GDET_CONF_1_SBZ1_MASK)

#define GDET_GDET_CONF_1_SBZ1_MASK               (0x10U)
#define GDET_GDET_CONF_1_SBZ1_SHIFT              (4U)
/*! sbz1 - Should be left to zero */
#define GDET_GDET_CONF_1_SBZ1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ1_SHIFT)) & GDET_GDET_CONF_1_SBZ1_MASK)

#define GDET_GDET_CONF_1_SBZ2_MASK               (0x20U)
#define GDET_GDET_CONF_1_SBZ2_SHIFT              (5U)
/*! SBZ2 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ2(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ2_SHIFT)) & GDET_GDET_CONF_1_SBZ2_MASK)

#define GDET_GDET_CONF_1_SBZ2_MASK               (0x20U)
#define GDET_GDET_CONF_1_SBZ2_SHIFT              (5U)
/*! sbz2 - Should be left to zero */
#define GDET_GDET_CONF_1_SBZ2(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ2_SHIFT)) & GDET_GDET_CONF_1_SBZ2_MASK)

#define GDET_GDET_CONF_1_SBZ3_MASK               (0x40U)
#define GDET_GDET_CONF_1_SBZ3_SHIFT              (6U)
/*! SBZ3 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ3(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ3_SHIFT)) & GDET_GDET_CONF_1_SBZ3_MASK)

#define GDET_GDET_CONF_1_SBZ3_MASK               (0x40U)
#define GDET_GDET_CONF_1_SBZ3_SHIFT              (6U)
/*! sbz3 - Should be left to zero */
#define GDET_GDET_CONF_1_SBZ3(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ3_SHIFT)) & GDET_GDET_CONF_1_SBZ3_MASK)

#define GDET_GDET_CONF_1_FIELD_7_MASK            (0x80U)
#define GDET_GDET_CONF_1_FIELD_7_SHIFT           (7U)
/*! FIELD_7 - GDET Configuration 1 Field 7 */
#define GDET_GDET_CONF_1_FIELD_7(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_7_SHIFT)) & GDET_GDET_CONF_1_FIELD_7_MASK)

#define GDET_GDET_CONF_1_FIELD_7_MASK            (0x80U)
#define GDET_GDET_CONF_1_FIELD_7_SHIFT           (7U)
/*! field_7 - GDET configuration 1 Field 7 */
#define GDET_GDET_CONF_1_FIELD_7(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_7_SHIFT)) & GDET_GDET_CONF_1_FIELD_7_MASK)

#define GDET_GDET_CONF_1_FIELD_8_MASK            (0x100U)
#define GDET_GDET_CONF_1_FIELD_8_SHIFT           (8U)
/*! FIELD_8 - GDET Configuration 1 Field 8 */
#define GDET_GDET_CONF_1_FIELD_8(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_8_SHIFT)) & GDET_GDET_CONF_1_FIELD_8_MASK)

#define GDET_GDET_CONF_1_FIELD_8_MASK            (0x100U)
#define GDET_GDET_CONF_1_FIELD_8_SHIFT           (8U)
/*! field_8 - GDET configuration 1 Field 8 */
#define GDET_GDET_CONF_1_FIELD_8(x)              (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_FIELD_8_SHIFT)) & GDET_GDET_CONF_1_FIELD_8_MASK)

#define GDET_GDET_CONF_1_SBZ4_MASK               (0x200U)
#define GDET_GDET_CONF_1_SBZ4_SHIFT              (9U)
/*! SBZ4 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ4(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ4_SHIFT)) & GDET_GDET_CONF_1_SBZ4_MASK)

#define GDET_GDET_CONF_1_SBZ4_MASK               (0x200U)
#define GDET_GDET_CONF_1_SBZ4_SHIFT              (9U)
/*! sbz4 - Should be left to zero */
#define GDET_GDET_CONF_1_SBZ4(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ4_SHIFT)) & GDET_GDET_CONF_1_SBZ4_MASK)

#define GDET_GDET_CONF_1_SBZ5_MASK               (0x400U)
#define GDET_GDET_CONF_1_SBZ5_SHIFT              (10U)
/*! SBZ5 - Should Be Left to Zero */
#define GDET_GDET_CONF_1_SBZ5(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ5_SHIFT)) & GDET_GDET_CONF_1_SBZ5_MASK)

#define GDET_GDET_CONF_1_SBZ5_MASK               (0x400U)
#define GDET_GDET_CONF_1_SBZ5_SHIFT              (10U)
/*! sbz5 - Should be left to zero */
#define GDET_GDET_CONF_1_SBZ5(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_SBZ5_SHIFT)) & GDET_GDET_CONF_1_SBZ5_MASK)

#define GDET_GDET_CONF_1_RFU_MASK                (0xFFFFF800U)
#define GDET_GDET_CONF_1_RFU_SHIFT               (11U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_CONF_1_RFU(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_RFU_SHIFT)) & GDET_GDET_CONF_1_RFU_MASK)

#define GDET_GDET_CONF_1_RFU_MASK                (0xFFFFF800U)
#define GDET_GDET_CONF_1_RFU_SHIFT               (11U)
/*! rfu - Reserved for Future Use */
#define GDET_GDET_CONF_1_RFU(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_1_RFU_SHIFT)) & GDET_GDET_CONF_1_RFU_MASK)
/*! @} */

/*! @name GDET_ENABLE1 - GDET Enable Register */
/*! @{ */

#define GDET_GDET_ENABLE1_EN1_MASK               (0x1U)
#define GDET_GDET_ENABLE1_EN1_SHIFT              (0U)
/*! EN1 - If set, the detector will be clock gated */
#define GDET_GDET_ENABLE1_EN1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_EN1_SHIFT)) & GDET_GDET_ENABLE1_EN1_MASK)

#define GDET_GDET_ENABLE1_EN1_MASK               (0x1U)
#define GDET_GDET_ENABLE1_EN1_SHIFT              (0U)
/*! en1 - If set, the detector will be clock gated */
#define GDET_GDET_ENABLE1_EN1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_EN1_SHIFT)) & GDET_GDET_ENABLE1_EN1_MASK)

#define GDET_GDET_ENABLE1_RFU_MASK               (0xFFFFFFFEU)
#define GDET_GDET_ENABLE1_RFU_SHIFT              (1U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_ENABLE1_RFU(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_RFU_SHIFT)) & GDET_GDET_ENABLE1_RFU_MASK)

#define GDET_GDET_ENABLE1_RFU_MASK               (0xFFFFFFFEU)
#define GDET_GDET_ENABLE1_RFU_SHIFT              (1U)
/*! rfu - Reserved for Future Use */
#define GDET_GDET_ENABLE1_RFU(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_RFU_SHIFT)) & GDET_GDET_ENABLE1_RFU_MASK)
/*! @} */

/*! @name GDET_CONF_2 - GDET Configuration 2 Register */
/*! @{ */

#define GDET_GDET_CONF_2_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_2_FIELD_6_0_SHIFT         (0U)
/*! FIELD_6_0 - GDET Configuration 2 Field 6_0 */
#define GDET_GDET_CONF_2_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_2_FIELD_6_0_MASK)

#define GDET_GDET_CONF_2_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_2_FIELD_6_0_SHIFT         (0U)
/*! field_6_0 - GDET configuration 2 Field 6_0 */
#define GDET_GDET_CONF_2_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_2_FIELD_6_0_MASK)

#define GDET_GDET_CONF_2_RFU1_MASK               (0xFF80U)
#define GDET_GDET_CONF_2_RFU1_SHIFT              (7U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU1_SHIFT)) & GDET_GDET_CONF_2_RFU1_MASK)

#define GDET_GDET_CONF_2_RFU1_MASK               (0xFF80U)
#define GDET_GDET_CONF_2_RFU1_SHIFT              (7U)
/*! rfu1 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU1_SHIFT)) & GDET_GDET_CONF_2_RFU1_MASK)

#define GDET_GDET_CONF_2_FIELD_21_16_MASK        (0x3F0000U)
#define GDET_GDET_CONF_2_FIELD_21_16_SHIFT       (16U)
/*! FIELD_21_16 - GDET Configuration 2 Field 21_16 */
#define GDET_GDET_CONF_2_FIELD_21_16(x)          (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_21_16_SHIFT)) & GDET_GDET_CONF_2_FIELD_21_16_MASK)

#define GDET_GDET_CONF_2_FIELD_21_16_MASK        (0x3F0000U)
#define GDET_GDET_CONF_2_FIELD_21_16_SHIFT       (16U)
/*! field_21_16 - GDET configuration 2 Field 21_16 */
#define GDET_GDET_CONF_2_FIELD_21_16(x)          (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_21_16_SHIFT)) & GDET_GDET_CONF_2_FIELD_21_16_MASK)

#define GDET_GDET_CONF_2_RFU2_MASK               (0xC00000U)
#define GDET_GDET_CONF_2_RFU2_SHIFT              (22U)
/*! RFU2 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU2(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU2_SHIFT)) & GDET_GDET_CONF_2_RFU2_MASK)

#define GDET_GDET_CONF_2_RFU2_MASK               (0xC00000U)
#define GDET_GDET_CONF_2_RFU2_SHIFT              (22U)
/*! rfu2 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU2(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU2_SHIFT)) & GDET_GDET_CONF_2_RFU2_MASK)

#define GDET_GDET_CONF_2_FIELD_29_24_MASK        (0x3F000000U)
#define GDET_GDET_CONF_2_FIELD_29_24_SHIFT       (24U)
/*! FIELD_29_24 - GDET Configuration 2 Field 29_24 */
#define GDET_GDET_CONF_2_FIELD_29_24(x)          (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_29_24_SHIFT)) & GDET_GDET_CONF_2_FIELD_29_24_MASK)

#define GDET_GDET_CONF_2_FIELD_29_24_MASK        (0x3F000000U)
#define GDET_GDET_CONF_2_FIELD_29_24_SHIFT       (24U)
/*! field_29_24 - GDET configuration 2 Field 29_24 */
#define GDET_GDET_CONF_2_FIELD_29_24(x)          (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_FIELD_29_24_SHIFT)) & GDET_GDET_CONF_2_FIELD_29_24_MASK)

#define GDET_GDET_CONF_2_RFU3_MASK               (0xC0000000U)
#define GDET_GDET_CONF_2_RFU3_SHIFT              (30U)
/*! RFU3 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU3(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU3_SHIFT)) & GDET_GDET_CONF_2_RFU3_MASK)

#define GDET_GDET_CONF_2_RFU3_MASK               (0xC0000000U)
#define GDET_GDET_CONF_2_RFU3_SHIFT              (30U)
/*! rfu3 - Reserved for Future Use */
#define GDET_GDET_CONF_2_RFU3(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_2_RFU3_SHIFT)) & GDET_GDET_CONF_2_RFU3_MASK)
/*! @} */

/*! @name GDET_CONF_3 - GDET Configuration 3 Register */
/*! @{ */

#define GDET_GDET_CONF_3_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_3_FIELD_6_0_SHIFT         (0U)
/*! FIELD_6_0 - GDET Configuration 3 Field 6_0 */
#define GDET_GDET_CONF_3_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_3_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_3_FIELD_6_0_MASK)

#define GDET_GDET_CONF_3_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_3_FIELD_6_0_SHIFT         (0U)
/*! field_6_0 - GDET configuration 3 Field 6_0 */
#define GDET_GDET_CONF_3_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_3_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_3_FIELD_6_0_MASK)

#define GDET_GDET_CONF_3_RFU1_MASK               (0xFFFFFF80U)
#define GDET_GDET_CONF_3_RFU1_SHIFT              (7U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_3_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_3_RFU1_SHIFT)) & GDET_GDET_CONF_3_RFU1_MASK)

#define GDET_GDET_CONF_3_RFU1_MASK               (0xFFFFFF80U)
#define GDET_GDET_CONF_3_RFU1_SHIFT              (7U)
/*! rfu1 - Reserved for Future Use */
#define GDET_GDET_CONF_3_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_3_RFU1_SHIFT)) & GDET_GDET_CONF_3_RFU1_MASK)
/*! @} */

/*! @name GDET_CONF_4 - GDET Configuration 4 Register */
/*! @{ */

#define GDET_GDET_CONF_4_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_4_FIELD_6_0_SHIFT         (0U)
/*! FIELD_6_0 - GDET Configuration 4 Field 6_0 */
#define GDET_GDET_CONF_4_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_4_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_4_FIELD_6_0_MASK)

#define GDET_GDET_CONF_4_FIELD_6_0_MASK          (0x7FU)
#define GDET_GDET_CONF_4_FIELD_6_0_SHIFT         (0U)
/*! field_6_0 - GDET configuration 4 Field 6_0 */
#define GDET_GDET_CONF_4_FIELD_6_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_4_FIELD_6_0_SHIFT)) & GDET_GDET_CONF_4_FIELD_6_0_MASK)

#define GDET_GDET_CONF_4_RFU1_MASK               (0xFFFFFF80U)
#define GDET_GDET_CONF_4_RFU1_SHIFT              (7U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_4_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_4_RFU1_SHIFT)) & GDET_GDET_CONF_4_RFU1_MASK)

#define GDET_GDET_CONF_4_RFU1_MASK               (0xFFFFFF80U)
#define GDET_GDET_CONF_4_RFU1_SHIFT              (7U)
/*! rfu1 - Reserved for Future Use */
#define GDET_GDET_CONF_4_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_4_RFU1_SHIFT)) & GDET_GDET_CONF_4_RFU1_MASK)
/*! @} */

/*! @name GDET_CONF_5 - GDET Configuration 5 Register */
/*! @{ */

#define GDET_GDET_CONF_5_FIELD_5_0_MASK          (0x3FU)
#define GDET_GDET_CONF_5_FIELD_5_0_SHIFT         (0U)
/*! FIELD_5_0 - GDET Configuration 5 Field 5_0 */
#define GDET_GDET_CONF_5_FIELD_5_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_FIELD_5_0_SHIFT)) & GDET_GDET_CONF_5_FIELD_5_0_MASK)

#define GDET_GDET_CONF_5_FIELD_5_0_MASK          (0x3FU)
#define GDET_GDET_CONF_5_FIELD_5_0_SHIFT         (0U)
/*! field_5_0 - GDET configuration 5 Field 5_0 */
#define GDET_GDET_CONF_5_FIELD_5_0(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_FIELD_5_0_SHIFT)) & GDET_GDET_CONF_5_FIELD_5_0_MASK)

#define GDET_GDET_CONF_5_FIELD_11_6_MASK         (0xFC0U)
#define GDET_GDET_CONF_5_FIELD_11_6_SHIFT        (6U)
/*! FIELD_11_6 - GDET Configuration 5 Field 11_6 */
#define GDET_GDET_CONF_5_FIELD_11_6(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_FIELD_11_6_SHIFT)) & GDET_GDET_CONF_5_FIELD_11_6_MASK)

#define GDET_GDET_CONF_5_FIELD_11_6_MASK         (0xFC0U)
#define GDET_GDET_CONF_5_FIELD_11_6_SHIFT        (6U)
/*! field_11_6 - GDET configuration 5 Field 11_6 */
#define GDET_GDET_CONF_5_FIELD_11_6(x)           (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_FIELD_11_6_SHIFT)) & GDET_GDET_CONF_5_FIELD_11_6_MASK)

#define GDET_GDET_CONF_5_RFU1_MASK               (0xFFFFF000U)
#define GDET_GDET_CONF_5_RFU1_SHIFT              (12U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_CONF_5_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_RFU1_SHIFT)) & GDET_GDET_CONF_5_RFU1_MASK)

#define GDET_GDET_CONF_5_RFU1_MASK               (0xFFFFF000U)
#define GDET_GDET_CONF_5_RFU1_SHIFT              (12U)
/*! rfu1 - Reserved for Future Use */
#define GDET_GDET_CONF_5_RFU1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CONF_5_RFU1_SHIFT)) & GDET_GDET_CONF_5_RFU1_MASK)
/*! @} */

/*! @name GDET_RESET - GDET Reset Register */
/*! @{ */

#define GDET_GDET_RESET_RFU1_MASK                (0x7U)
#define GDET_GDET_RESET_RFU1_SHIFT               (0U)
/*! RFU1 - Reserved for Future Use */
#define GDET_GDET_RESET_RFU1(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_RFU1_SHIFT)) & GDET_GDET_RESET_RFU1_MASK)

#define GDET_GDET_RESET_RFU1_MASK                (0x7U)
#define GDET_GDET_RESET_RFU1_SHIFT               (0U)
/*! rfu1 - Reserved for Future Use */
#define GDET_GDET_RESET_RFU1(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_RFU1_SHIFT)) & GDET_GDET_RESET_RFU1_MASK)

#define GDET_GDET_RESET_SFT_RST_MASK             (0x8U)
#define GDET_GDET_RESET_SFT_RST_SHIFT            (3U)
/*! SFT_RST - Soft Reset for the Core Reset */
#define GDET_GDET_RESET_SFT_RST(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_SFT_RST_SHIFT)) & GDET_GDET_RESET_SFT_RST_MASK)

#define GDET_GDET_RESET_SFT_RST_MASK             (0x8U)
#define GDET_GDET_RESET_SFT_RST_SHIFT            (3U)
/*! sft_rst - Soft reset for the core reset (SFR configuration will be preseved).This register reads as 0 */
#define GDET_GDET_RESET_SFT_RST(x)               (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_SFT_RST_SHIFT)) & GDET_GDET_RESET_SFT_RST_MASK)

#define GDET_GDET_RESET_RFU2_MASK                (0xFFFFFFF0U)
#define GDET_GDET_RESET_RFU2_SHIFT               (4U)
/*! RFU2 - Reserved for Future Use */
#define GDET_GDET_RESET_RFU2(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_RFU2_SHIFT)) & GDET_GDET_RESET_RFU2_MASK)

#define GDET_GDET_RESET_RFU2_MASK                (0xFFFFFFF0U)
#define GDET_GDET_RESET_RFU2_SHIFT               (4U)
/*! rfu2 - Reserved for Future Use */
#define GDET_GDET_RESET_RFU2(x)                  (((uint32_t)(((uint32_t)(x)) << GDET_GDET_RESET_RFU2_SHIFT)) & GDET_GDET_RESET_RFU2_MASK)
/*! @} */

/*! @name GDET_TEST - GDET Test Register */
/*! @{ */

#define GDET_GDET_TEST_SBZ_MASK                  (0x1U)
#define GDET_GDET_TEST_SBZ_SHIFT                 (0U)
/*! SBZ - Should Be Left to Zero */
#define GDET_GDET_TEST_SBZ(x)                    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_TEST_SBZ_SHIFT)) & GDET_GDET_TEST_SBZ_MASK)

#define GDET_GDET_TEST_SBZ_MASK                  (0x1U)
#define GDET_GDET_TEST_SBZ_SHIFT                 (0U)
/*! sbz - Should be left to zero */
#define GDET_GDET_TEST_SBZ(x)                    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_TEST_SBZ_SHIFT)) & GDET_GDET_TEST_SBZ_MASK)

#define GDET_GDET_TEST_RFU_MASK                  (0xFFFFFFFEU)
#define GDET_GDET_TEST_RFU_SHIFT                 (1U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_TEST_RFU(x)                    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_TEST_RFU_SHIFT)) & GDET_GDET_TEST_RFU_MASK)

#define GDET_GDET_TEST_RFU_MASK                  (0xFFFFFFFEU)
#define GDET_GDET_TEST_RFU_SHIFT                 (1U)
/*! rfu - Reserved for Future Use */
#define GDET_GDET_TEST_RFU(x)                    (((uint32_t)(((uint32_t)(x)) << GDET_GDET_TEST_RFU_SHIFT)) & GDET_GDET_TEST_RFU_MASK)
/*! @} */

/*! @name GDET_DLY_CTRL - GDET Delay Control Register */
/*! @{ */

#define GDET_GDET_DLY_CTRL_VOL_SEL_MASK          (0x3U)
#define GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT         (0U)
/*! VOL_SEL - GDET Delay Control of the Voltage Mode */
#define GDET_GDET_DLY_CTRL_VOL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT)) & GDET_GDET_DLY_CTRL_VOL_SEL_MASK)

#define GDET_GDET_DLY_CTRL_VOL_SEL_MASK          (0x3U)
#define GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT         (0U)
/*! vol_sel - GDET delay control of the voltage mode. Used to select the trim code appropiate to the voltage mode. */
#define GDET_GDET_DLY_CTRL_VOL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT)) & GDET_GDET_DLY_CTRL_VOL_SEL_MASK)

#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK      (0x4U)
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT     (2U)
/*! SW_VOL_CTRL - Select the Control of the Trim Code to the Delay Line */
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT)) & GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK)

#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK      (0x4U)
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT     (2U)
/*! sw_vol_ctrl - Select the control of the trim code to the delay line via HW port (0) or SW SFR (1) */
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT)) & GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK)

#define GDET_GDET_DLY_CTRL_RFU_MASK              (0xFFFFFFF8U)
#define GDET_GDET_DLY_CTRL_RFU_SHIFT             (3U)
/*! RFU - Reserved for Future Use */
#define GDET_GDET_DLY_CTRL_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_RFU_SHIFT)) & GDET_GDET_DLY_CTRL_RFU_MASK)

#define GDET_GDET_DLY_CTRL_RFU_MASK              (0xFFFFFFF8U)
#define GDET_GDET_DLY_CTRL_RFU_SHIFT             (3U)
/*! rfu - Reserved for Future Use */
#define GDET_GDET_DLY_CTRL_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_RFU_SHIFT)) & GDET_GDET_DLY_CTRL_RFU_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GDET_Register_Masks */


/*!
 * @}
 */ /* end of group GDET_Peripheral_Access_Layer */


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


#endif  /* PERI_GDET_H_ */

