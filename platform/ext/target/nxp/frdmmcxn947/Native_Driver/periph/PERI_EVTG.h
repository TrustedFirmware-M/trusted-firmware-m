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
**         CMSIS Peripheral Access Layer for EVTG
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
 * @file PERI_EVTG.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EVTG
 *
 * CMSIS Peripheral Access Layer for EVTG
 */

#if !defined(PERI_EVTG_H_)
#define PERI_EVTG_H_                             /**< Symbol preventing repeated inclusion */

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
   -- EVTG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EVTG_Peripheral_Access_Layer EVTG Peripheral Access Layer
 * @{
 */

/** EVTG - Size of Registers Arrays */
#define EVTG_EVTG_INST_COUNT                      4u

/** EVTG - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint16_t EVTG_AOI0_BFT01;                   /**< AOI0 Boolean Function Term 0 and 1 Configuration, array offset: 0x0, array step: 0x10 */
    __IO uint16_t EVTG_AOI0_BFT23;                   /**< AOI0 Boolean Function Term 2 and 3 Configuration, array offset: 0x2, array step: 0x10 */
    __IO uint16_t EVTG_AOI1_BFT01;                   /**< AOI1 Boolean Function Term 0 and 1 Configuration, array offset: 0x4, array step: 0x10 */
    __IO uint16_t EVTG_AOI1_BFT23;                   /**< AOI1 Boolean Function Term 2 and 3 Configuration, array offset: 0x6, array step: 0x10 */
         uint8_t RESERVED_0[2];
    __IO uint16_t EVTG_CTRL;                         /**< Control and Status, array offset: 0xA, array step: 0x10 */
    __IO uint16_t EVTG_AOI0_FILT;                    /**< AOI0 Output Filter, array offset: 0xC, array step: 0x10 */
    __IO uint16_t EVTG_AOI1_FILT;                    /**< AOI1 Output Filter, array offset: 0xE, array step: 0x10 */
  } EVTG_INST[EVTG_EVTG_INST_COUNT];
} EVTG_Type;

/* ----------------------------------------------------------------------------
   -- EVTG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EVTG_Register_Masks EVTG Register Masks
 * @{
 */

/*! @name EVTG_INST_EVTG_AOI0_BFT01 - AOI0 Boolean Function Term 0 and 1 Configuration */
/*! @{ */

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_DC_MASK (0x3U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_DC_SHIFT (0U)
/*! PT1_DC - Product Term 1, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_CC_MASK (0xCU)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_CC_SHIFT (2U)
/*! PT1_CC - Product Term 1, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_BC_MASK (0x30U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_BC_SHIFT (4U)
/*! PT1_BC - Product Term 1, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_AC_MASK (0xC0U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_AC_SHIFT (6U)
/*! PT1_AC - Product Term 1, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT1_AC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_DC_MASK (0x300U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_DC_SHIFT (8U)
/*! PT0_DC - Product Term 0, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_CC_MASK (0xC00U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_CC_SHIFT (10U)
/*! PT0_CC - Product Term 0, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_BC_MASK (0x3000U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_BC_SHIFT (12U)
/*! PT0_BC - Product Term 0, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_AC_MASK (0xC000U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_AC_SHIFT (14U)
/*! PT0_AC - Product Term 0, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT01_PT0_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_INST_EVTG_AOI0_BFT01 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT01_COUNT     (4U)

/*! @name EVTG_INST_EVTG_AOI0_BFT23 - AOI0 Boolean Function Term 2 and 3 Configuration */
/*! @{ */

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_DC_MASK (0x3U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_DC_SHIFT (0U)
/*! PT3_DC - Product Term 3, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_CC_MASK (0xCU)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_CC_SHIFT (2U)
/*! PT3_CC - Product Term 3, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_BC_MASK (0x30U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_BC_SHIFT (4U)
/*! PT3_BC - Product Term 3, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_AC_MASK (0xC0U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_AC_SHIFT (6U)
/*! PT3_AC - Product Term 3, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT3_AC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_DC_MASK (0x300U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_DC_SHIFT (8U)
/*! PT2_DC - Product Term 2, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_CC_MASK (0xC00U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_CC_SHIFT (10U)
/*! PT2_CC - Product Term 2, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_BC_MASK (0x3000U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_BC_SHIFT (12U)
/*! PT2_BC - Product Term 2, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_AC_MASK (0xC000U)
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_AC_SHIFT (14U)
/*! PT2_AC - Product Term 2, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_BFT23_PT2_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_INST_EVTG_AOI0_BFT23 */
#define EVTG_EVTG_INST_EVTG_AOI0_BFT23_COUNT     (4U)

/*! @name EVTG_INST_EVTG_AOI1_BFT01 - AOI1 Boolean Function Term 0 and 1 Configuration */
/*! @{ */

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_DC_MASK (0x3U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_DC_SHIFT (0U)
/*! PT1_DC - Product Term 1, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_CC_MASK (0xCU)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_CC_SHIFT (2U)
/*! PT1_CC - Product Term 1, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_BC_MASK (0x30U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_BC_SHIFT (4U)
/*! PT1_BC - Product Term 1, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_AC_MASK (0xC0U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_AC_SHIFT (6U)
/*! PT1_AC - Product Term 1, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT1_AC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_DC_MASK (0x300U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_DC_SHIFT (8U)
/*! PT0_DC - Product Term 0, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_CC_MASK (0xC00U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_CC_SHIFT (10U)
/*! PT0_CC - Product Term 0, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_BC_MASK (0x3000U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_BC_SHIFT (12U)
/*! PT0_BC - Product Term 0, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_AC_MASK (0xC000U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_AC_SHIFT (14U)
/*! PT0_AC - Product Term 0, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT01_PT0_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_INST_EVTG_AOI1_BFT01 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT01_COUNT     (4U)

/*! @name EVTG_INST_EVTG_AOI1_BFT23 - AOI1 Boolean Function Term 2 and 3 Configuration */
/*! @{ */

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_DC_MASK (0x3U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_DC_SHIFT (0U)
/*! PT3_DC - Product Term 3, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_CC_MASK (0xCU)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_CC_SHIFT (2U)
/*! PT3_CC - Product Term 3, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_BC_MASK (0x30U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_BC_SHIFT (4U)
/*! PT3_BC - Product Term 3, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_AC_MASK (0xC0U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_AC_SHIFT (6U)
/*! PT3_AC - Product Term 3, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT3_AC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_DC_MASK (0x300U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_DC_SHIFT (8U)
/*! PT2_DC - Product Term 2, D Input Configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_DC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_DC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_DC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_CC_MASK (0xC00U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_CC_SHIFT (10U)
/*! PT2_CC - Product Term 2, C Input Configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_CC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_CC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_CC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_BC_MASK (0x3000U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_BC_SHIFT (12U)
/*! PT2_BC - Product Term 2, B Input Configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_BC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_BC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_BC_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_AC_MASK (0xC000U)
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_AC_SHIFT (14U)
/*! PT2_AC - Product Term 2, A Input Configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_AC(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_AC_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_BFT23_PT2_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_INST_EVTG_AOI1_BFT23 */
#define EVTG_EVTG_INST_EVTG_AOI1_BFT23_COUNT     (4U)

/*! @name EVTG_INST_EVTG_CTRL - Control and Status */
/*! @{ */

#define EVTG_EVTG_INST_EVTG_CTRL_FF_INIT_MASK    (0x1U)
#define EVTG_EVTG_INST_EVTG_CTRL_FF_INIT_SHIFT   (0U)
/*! FF_INIT - Flip flop Initial Value Configuration
 *  0b0..0
 *  0b1..1
 */
#define EVTG_EVTG_INST_EVTG_CTRL_FF_INIT(x)      (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_CTRL_FF_INIT_SHIFT)) & EVTG_EVTG_INST_EVTG_CTRL_FF_INIT_MASK)

#define EVTG_EVTG_INST_EVTG_CTRL_INIT_EN_MASK    (0x2U)
#define EVTG_EVTG_INST_EVTG_CTRL_INIT_EN_SHIFT   (1U)
/*! INIT_EN - Flip-Flop Initial Output Enable Control
 *  0b0..Write 0 does not generate enable pulse
 *  0b1..Write 1 generates enable pulse
 */
#define EVTG_EVTG_INST_EVTG_CTRL_INIT_EN(x)      (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_CTRL_INIT_EN_SHIFT)) & EVTG_EVTG_INST_EVTG_CTRL_INIT_EN_MASK)

#define EVTG_EVTG_INST_EVTG_CTRL_MODE_SEL_MASK   (0x1CU)
#define EVTG_EVTG_INST_EVTG_CTRL_MODE_SEL_SHIFT  (2U)
/*! MODE_SEL - Flip-Flop Mode Selection
 *  0b000..Bypass mode
 *  0b001..RS Trigger mode
 *  0b010..T-FF mode
 *  0b011..D-FF mode
 *  0b100..JK-FF mode
 *  0b101..Latch mode
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define EVTG_EVTG_INST_EVTG_CTRL_MODE_SEL(x)     (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_CTRL_MODE_SEL_SHIFT)) & EVTG_EVTG_INST_EVTG_CTRL_MODE_SEL_MASK)

#define EVTG_EVTG_INST_EVTG_CTRL_FB_OVRD_MASK    (0xC0U)
#define EVTG_EVTG_INST_EVTG_CTRL_FB_OVRD_SHIFT   (6U)
/*! FB_OVRD - EVTG Output Feedback Override Control
 *  0b00..Replace An
 *  0b01..Replace Bn
 *  0b10..Replace Cn
 *  0b11..Replace Dn
 */
#define EVTG_EVTG_INST_EVTG_CTRL_FB_OVRD(x)      (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_CTRL_FB_OVRD_SHIFT)) & EVTG_EVTG_INST_EVTG_CTRL_FB_OVRD_MASK)

#define EVTG_EVTG_INST_EVTG_CTRL_SYNC_CTRL_MASK  (0xF00U)
#define EVTG_EVTG_INST_EVTG_CTRL_SYNC_CTRL_SHIFT (8U)
/*! SYNC_CTRL - Synchronize Control
 *  0b0xxx..EVTG input "Dn" will not be synced
 *  0b1xxx..EVTG input "Dn" will be synced by two bus clk cycles
 *  0bx0xx..EVTG input "Cn" will not be synced
 *  0bx1xx..EVTG input "Cn" will be synced by two bus clk cycles
 *  0bxx0x..EVTG input "Bn" will not be synced
 *  0bxx1x..EVTG input "Bn" will be synced by two bus clk cycles
 *  0bxxx0..EVTG input "An" will not be synced
 *  0bxxx1..EVTG input "An" will be synced by two bus clk cycles
 */
#define EVTG_EVTG_INST_EVTG_CTRL_SYNC_CTRL(x)    (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_CTRL_SYNC_CTRL_SHIFT)) & EVTG_EVTG_INST_EVTG_CTRL_SYNC_CTRL_MASK)

#define EVTG_EVTG_INST_EVTG_CTRL_FORCE_BYPASS_MASK (0x3000U)
#define EVTG_EVTG_INST_EVTG_CTRL_FORCE_BYPASS_SHIFT (12U)
/*! FORCE_BYPASS - Force Bypass Control
 *  0b0x..Will not force the bypass
 *  0b1x..Whatever MODE_SEL is, will force bypass flip-flop and route the AOI_1(Filter_1) value directly to EVTG_OUTB
 *  0bx0..Will not force the bypass
 *  0bx1..Whatever MODE_SEL is, will force bypass flip-flop and route the AOI_0(Filter_0) value directly to EVTG_OUTA
 */
#define EVTG_EVTG_INST_EVTG_CTRL_FORCE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_CTRL_FORCE_BYPASS_SHIFT)) & EVTG_EVTG_INST_EVTG_CTRL_FORCE_BYPASS_MASK)
/*! @} */

/* The count of EVTG_EVTG_INST_EVTG_CTRL */
#define EVTG_EVTG_INST_EVTG_CTRL_COUNT           (4U)

/*! @name EVTG_INST_EVTG_AOI0_FILT - AOI0 Output Filter */
/*! @{ */

#define EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_PER_MASK (0xFFU)
#define EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_PER_SHIFT (0U)
/*! FILT_PER - Output Filter Sample Period */
#define EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_PER(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_PER_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_PER_MASK)

#define EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_CNT_MASK (0x700U)
#define EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_CNT_SHIFT (8U)
/*! FILT_CNT - Output Filter Sample Count */
#define EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_CNT(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_CNT_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI0_FILT_FILT_CNT_MASK)
/*! @} */

/* The count of EVTG_EVTG_INST_EVTG_AOI0_FILT */
#define EVTG_EVTG_INST_EVTG_AOI0_FILT_COUNT      (4U)

/*! @name EVTG_INST_EVTG_AOI1_FILT - AOI1 Output Filter */
/*! @{ */

#define EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_PER_MASK (0xFFU)
#define EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_PER_SHIFT (0U)
/*! FILT_PER - Output Filter Sample Period */
#define EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_PER(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_PER_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_PER_MASK)

#define EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_CNT_MASK (0x700U)
#define EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_CNT_SHIFT (8U)
/*! FILT_CNT - Output Filter Sample Count */
#define EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_CNT(x) (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_CNT_SHIFT)) & EVTG_EVTG_INST_EVTG_AOI1_FILT_FILT_CNT_MASK)
/*! @} */

/* The count of EVTG_EVTG_INST_EVTG_AOI1_FILT */
#define EVTG_EVTG_INST_EVTG_AOI1_FILT_COUNT      (4U)


/*!
 * @}
 */ /* end of group EVTG_Register_Masks */


/*!
 * @}
 */ /* end of group EVTG_Peripheral_Access_Layer */


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


#endif  /* PERI_EVTG_H_ */

