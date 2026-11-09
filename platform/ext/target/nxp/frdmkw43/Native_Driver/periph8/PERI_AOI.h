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
**         CMSIS Peripheral Access Layer for AOI
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
 * @file PERI_AOI.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for AOI
 *
 * CMSIS Peripheral Access Layer for AOI
 */

#if !defined(PERI_AOI_H_)
#define PERI_AOI_H_                              /**< Symbol preventing repeated inclusion */

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
   -- AOI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Peripheral_Access_Layer AOI Peripheral Access Layer
 * @{
 */

/** AOI - Size of Registers Arrays */
#define AOI_BFCRT_COUNT                           4u

/** AOI - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x4 */
    __IO uint16_t BFCRT01;                           /**< Boolean Function Term 0 and 1 Configuration for EVENT0..Boolean Function Term 0 and 1 Configuration for EVENT3, array offset: 0x0, array step: 0x4 */
    __IO uint16_t BFCRT23;                           /**< Boolean Function Term 2 and 3 Configuration for EVENT0..Boolean Function Term 2 and 3 Configuration for EVENT3, array offset: 0x2, array step: 0x4 */
  } BFCRT[AOI_BFCRT_COUNT];
} AOI_Type;

/* ----------------------------------------------------------------------------
   -- AOI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Register_Masks AOI Register Masks
 * @{
 */

/*! @name BFCRT01 - Boolean Function Term 0 and 1 Configuration for EVENT0..Boolean Function Term 0 and 1 Configuration for EVENT3 */
/*! @{ */

#define AOI_BFCRT01_PT1_DC_MASK                  (0x3U)
#define AOI_BFCRT01_PT1_DC_SHIFT                 (0U)
/*! PT1_DC - Product Term 1, Input D Configuration
 *  0b00..Force input D to become 0
 *  0b01..Pass input D
 *  0b10..Complement input D
 *  0b11..Force input D to become 1
 */
#define AOI_BFCRT01_PT1_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_DC_SHIFT)) & AOI_BFCRT01_PT1_DC_MASK)

#define AOI_BFCRT01_PT1_CC_MASK                  (0xCU)
#define AOI_BFCRT01_PT1_CC_SHIFT                 (2U)
/*! PT1_CC - Product Term 1, Input C Configuration
 *  0b00..Force input C to become 0
 *  0b01..Pass input C
 *  0b10..Complement input C
 *  0b11..Force input C to become 1
 */
#define AOI_BFCRT01_PT1_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_CC_SHIFT)) & AOI_BFCRT01_PT1_CC_MASK)

#define AOI_BFCRT01_PT1_BC_MASK                  (0x30U)
#define AOI_BFCRT01_PT1_BC_SHIFT                 (4U)
/*! PT1_BC - Product Term 1, Input B Configuration
 *  0b00..Force input B to become 0
 *  0b01..Pass input B
 *  0b10..Complement input B
 *  0b11..Force input B to become 1
 */
#define AOI_BFCRT01_PT1_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_BC_SHIFT)) & AOI_BFCRT01_PT1_BC_MASK)

#define AOI_BFCRT01_PT1_AC_MASK                  (0xC0U)
#define AOI_BFCRT01_PT1_AC_SHIFT                 (6U)
/*! PT1_AC - Product Term 1, Input A Configuration
 *  0b00..Force input A to become 0
 *  0b01..Pass input A
 *  0b10..Complement input A
 *  0b11..Force input A to become 1
 */
#define AOI_BFCRT01_PT1_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_AC_SHIFT)) & AOI_BFCRT01_PT1_AC_MASK)

#define AOI_BFCRT01_PT0_DC_MASK                  (0x300U)
#define AOI_BFCRT01_PT0_DC_SHIFT                 (8U)
/*! PT0_DC - Product Term 0, Input D Configuration
 *  0b00..Force input D to become 0
 *  0b01..Pass input D
 *  0b10..Complement input D
 *  0b11..Force input D to become 1
 */
#define AOI_BFCRT01_PT0_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_DC_SHIFT)) & AOI_BFCRT01_PT0_DC_MASK)

#define AOI_BFCRT01_PT0_CC_MASK                  (0xC00U)
#define AOI_BFCRT01_PT0_CC_SHIFT                 (10U)
/*! PT0_CC - Product Term 0, Input C Configuration
 *  0b00..Force input C to become 0
 *  0b01..Pass input C
 *  0b10..Complement input C
 *  0b11..Force input C to become 1
 */
#define AOI_BFCRT01_PT0_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_CC_SHIFT)) & AOI_BFCRT01_PT0_CC_MASK)

#define AOI_BFCRT01_PT0_BC_MASK                  (0x3000U)
#define AOI_BFCRT01_PT0_BC_SHIFT                 (12U)
/*! PT0_BC - Product Term 0, Input B Configuration
 *  0b00..Force input B to become 0
 *  0b01..Pass input B
 *  0b10..Complement input B
 *  0b11..Force input B to become 1
 */
#define AOI_BFCRT01_PT0_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_BC_SHIFT)) & AOI_BFCRT01_PT0_BC_MASK)

#define AOI_BFCRT01_PT0_AC_MASK                  (0xC000U)
#define AOI_BFCRT01_PT0_AC_SHIFT                 (14U)
/*! PT0_AC - Product Term 0, Input A Configuration
 *  0b00..Force input A to become 0
 *  0b01..Pass input A
 *  0b10..Complement input A
 *  0b11..Force input A to become 1
 */
#define AOI_BFCRT01_PT0_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_AC_SHIFT)) & AOI_BFCRT01_PT0_AC_MASK)
/*! @} */

/* The count of AOI_BFCRT01 */
#define AOI_BFCRT01_COUNT                        (4U)

/*! @name BFCRT23 - Boolean Function Term 2 and 3 Configuration for EVENT0..Boolean Function Term 2 and 3 Configuration for EVENT3 */
/*! @{ */

#define AOI_BFCRT23_PT3_DC_MASK                  (0x3U)
#define AOI_BFCRT23_PT3_DC_SHIFT                 (0U)
/*! PT3_DC - Product Term 3, Input D Configuration
 *  0b00..Force input D to become 0
 *  0b01..Pass input D
 *  0b10..Complement input D
 *  0b11..Force input D to become 1
 */
#define AOI_BFCRT23_PT3_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_DC_SHIFT)) & AOI_BFCRT23_PT3_DC_MASK)

#define AOI_BFCRT23_PT3_CC_MASK                  (0xCU)
#define AOI_BFCRT23_PT3_CC_SHIFT                 (2U)
/*! PT3_CC - Product Term 3, Input C Configuration
 *  0b00..Force input C to become 0
 *  0b01..Pass input C
 *  0b10..Complement input C
 *  0b11..Force input C to become 1
 */
#define AOI_BFCRT23_PT3_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_CC_SHIFT)) & AOI_BFCRT23_PT3_CC_MASK)

#define AOI_BFCRT23_PT3_BC_MASK                  (0x30U)
#define AOI_BFCRT23_PT3_BC_SHIFT                 (4U)
/*! PT3_BC - Product Term 3, Input B Configuration
 *  0b00..Force input B to become 0
 *  0b01..Pass input B
 *  0b10..Complement input B
 *  0b11..Force input B to become 1
 */
#define AOI_BFCRT23_PT3_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_BC_SHIFT)) & AOI_BFCRT23_PT3_BC_MASK)

#define AOI_BFCRT23_PT3_AC_MASK                  (0xC0U)
#define AOI_BFCRT23_PT3_AC_SHIFT                 (6U)
/*! PT3_AC - Product Term 3, Input A Configuration
 *  0b00..Force input A to become 0
 *  0b01..Pass input A
 *  0b10..Complement input A
 *  0b11..Force input to become 1
 */
#define AOI_BFCRT23_PT3_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_AC_SHIFT)) & AOI_BFCRT23_PT3_AC_MASK)

#define AOI_BFCRT23_PT2_DC_MASK                  (0x300U)
#define AOI_BFCRT23_PT2_DC_SHIFT                 (8U)
/*! PT2_DC - Product Term 2, Input D Configuration
 *  0b00..Force input D to become 0
 *  0b01..Pass input D
 *  0b10..Complement input D
 *  0b11..Force input D to become 1
 */
#define AOI_BFCRT23_PT2_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_DC_SHIFT)) & AOI_BFCRT23_PT2_DC_MASK)

#define AOI_BFCRT23_PT2_CC_MASK                  (0xC00U)
#define AOI_BFCRT23_PT2_CC_SHIFT                 (10U)
/*! PT2_CC - Product Term 2, Input C Configuration
 *  0b00..Force input C to become 0
 *  0b01..Pass input C
 *  0b10..Complement input C
 *  0b11..Force input C to become 1
 */
#define AOI_BFCRT23_PT2_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_CC_SHIFT)) & AOI_BFCRT23_PT2_CC_MASK)

#define AOI_BFCRT23_PT2_BC_MASK                  (0x3000U)
#define AOI_BFCRT23_PT2_BC_SHIFT                 (12U)
/*! PT2_BC - Product Term 2, Input B Configuration
 *  0b00..Force input B to become 0
 *  0b01..Pass input B
 *  0b10..Complement input B
 *  0b11..Force input B to become 1
 */
#define AOI_BFCRT23_PT2_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_BC_SHIFT)) & AOI_BFCRT23_PT2_BC_MASK)

#define AOI_BFCRT23_PT2_AC_MASK                  (0xC000U)
#define AOI_BFCRT23_PT2_AC_SHIFT                 (14U)
/*! PT2_AC - Product Term 2, Input A Configuration
 *  0b00..Force input A to become 0
 *  0b01..Pass input A
 *  0b10..Complement input A
 *  0b11..Force input A to become 1
 */
#define AOI_BFCRT23_PT2_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_AC_SHIFT)) & AOI_BFCRT23_PT2_AC_MASK)
/*! @} */

/* The count of AOI_BFCRT23 */
#define AOI_BFCRT23_COUNT                        (4U)


/*!
 * @}
 */ /* end of group AOI_Register_Masks */


/*!
 * @}
 */ /* end of group AOI_Peripheral_Access_Layer */


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


#endif  /* PERI_AOI_H_ */

