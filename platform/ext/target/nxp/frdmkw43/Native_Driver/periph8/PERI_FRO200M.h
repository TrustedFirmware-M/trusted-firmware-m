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
**         CMSIS Peripheral Access Layer for FRO200M
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
 * @file PERI_FRO200M.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for FRO200M
 *
 * CMSIS Peripheral Access Layer for FRO200M
 */

#if !defined(PERI_FRO200M_H_)
#define PERI_FRO200M_H_                          /**< Symbol preventing repeated inclusion */

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
   -- FRO200M Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO200M_Peripheral_Access_Layer FRO200M Peripheral Access Layer
 * @{
 */

/** FRO200M - Register Layout Typedef */
typedef struct {
  __IO uint32_t FROCCSR;                           /**< FRO192 Clock Control Status Register, offset: 0x0 */
  __IO uint32_t FRODIV;                            /**< FRO192 Divide Register, offset: 0x4 */
} FRO200M_Type;

/* ----------------------------------------------------------------------------
   -- FRO200M Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO200M_Register_Masks FRO200M Register Masks
 * @{
 */

/*! @name FROCCSR - FRO192 Clock Control Status Register */
/*! @{ */

#define FRO200M_FROCCSR_FRODIV_MASK              (0x3U)
#define FRO200M_FROCCSR_FRODIV_SHIFT             (0U)
/*! FRODIV - FRO Clock Divide
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 3
 *  0b11..Divide by 4
 */
#define FRO200M_FROCCSR_FRODIV(x)                (((uint32_t)(((uint32_t)(x)) << FRO200M_FROCCSR_FRODIV_SHIFT)) & FRO200M_FROCCSR_FRODIV_MASK)

#define FRO200M_FROCCSR_POSTDIV_SEL_MASK         (0x7000U)
#define FRO200M_FROCCSR_POSTDIV_SEL_SHIFT        (12U)
/*! POSTDIV_SEL - Post Divider Clock Select
 *  0b000..FRO 16MHz Range selected.
 *  0b001..FRO 24MHz Range selected
 *  0b010..FRO 32MHz Range selected
 *  0b011..FRO 48MHz Range selected
 *  0b100..FRO 64MHz Range selected
 *  0b101..RESERVED. Not Supported
 *  0b110..RESERVED. Not Supported
 *  0b111..FRO undivided Clock selected
 */
#define FRO200M_FROCCSR_POSTDIV_SEL(x)           (((uint32_t)(((uint32_t)(x)) << FRO200M_FROCCSR_POSTDIV_SEL_SHIFT)) & FRO200M_FROCCSR_POSTDIV_SEL_MASK)

#define FRO200M_FROCCSR_VALID_MASK               (0x1000000U)
#define FRO200M_FROCCSR_VALID_SHIFT              (24U)
/*! VALID - Clock Valid Flag
 *  0b0..FRO192 is not enabled or clock is not valid.
 *  0b1..FRO192 is enabled and output clock is valid.
 */
#define FRO200M_FROCCSR_VALID(x)                 (((uint32_t)(((uint32_t)(x)) << FRO200M_FROCCSR_VALID_SHIFT)) & FRO200M_FROCCSR_VALID_MASK)
/*! @} */

/*! @name FRODIV - FRO192 Divide Register */
/*! @{ */

#define FRO200M_FRODIV_FRODIV_MASK               (0x3U)
#define FRO200M_FRODIV_FRODIV_SHIFT              (0U)
/*! FRODIV - FRO Clock Divide
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 3
 *  0b11..Divide by 4
 */
#define FRO200M_FRODIV_FRODIV(x)                 (((uint32_t)(((uint32_t)(x)) << FRO200M_FRODIV_FRODIV_SHIFT)) & FRO200M_FRODIV_FRODIV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FRO200M_Register_Masks */


/*!
 * @}
 */ /* end of group FRO200M_Peripheral_Access_Layer */


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


#endif  /* PERI_FRO200M_H_ */

