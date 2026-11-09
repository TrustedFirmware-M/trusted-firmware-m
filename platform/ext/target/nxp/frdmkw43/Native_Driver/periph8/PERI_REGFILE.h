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
**         CMSIS Peripheral Access Layer for REGFILE
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
 * @file PERI_REGFILE.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for REGFILE
 *
 * CMSIS Peripheral Access Layer for REGFILE
 */

#if !defined(PERI_REGFILE_H_)
#define PERI_REGFILE_H_                          /**< Symbol preventing repeated inclusion */

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
   -- REGFILE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REGFILE_Peripheral_Access_Layer REGFILE Peripheral Access Layer
 * @{
 */

/** REGFILE - Size of Registers Arrays */
#define REGFILE_REG_COUNT                         8u

/** REGFILE - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG[REGFILE_REG_COUNT];            /**< Register File Register 0..Register File Register 7, array offset: 0x0, array step: 0x4 */
} REGFILE_Type;

/* ----------------------------------------------------------------------------
   -- REGFILE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REGFILE_Register_Masks REGFILE Register Masks
 * @{
 */

/*! @name REG - Register File Register 0..Register File Register 7 */
/*! @{ */

#define REGFILE_REG_REG_MASK                     (0xFFFFFFFFU)
#define REGFILE_REG_REG_SHIFT                    (0U)
/*! REG - Register File */
#define REGFILE_REG_REG(x)                       (((uint32_t)(((uint32_t)(x)) << REGFILE_REG_REG_SHIFT)) & REGFILE_REG_REG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group REGFILE_Register_Masks */


/*!
 * @}
 */ /* end of group REGFILE_Peripheral_Access_Layer */


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


#endif  /* PERI_REGFILE_H_ */

