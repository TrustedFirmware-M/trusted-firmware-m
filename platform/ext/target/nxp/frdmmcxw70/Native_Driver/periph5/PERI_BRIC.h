/*
** ###################################################################
**     Processors:          MCXW70ACMFT
**                          MCXW70ACMMP
**                          MCXW70ADMFT
**                          MCXW70ADMMP
**
**     Version:             rev. 1.0, 2026-01-09
**     Build:               b260813
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BRIC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-01-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BRIC.h
 * @version 1.0
 * @date 2026-01-09
 * @brief CMSIS Peripheral Access Layer for BRIC
 *
 * CMSIS Peripheral Access Layer for BRIC
 */

#if !defined(PERI_BRIC_H_)
#define PERI_BRIC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW70ACMFT) || defined(CPU_MCXW70ACMMP))
#include "MCXW70AC_COMMON.h"
#elif (defined(CPU_MCXW70ADMFT) || defined(CPU_MCXW70ADMMP))
#include "MCXW70AD_COMMON.h"
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
   -- BRIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BRIC_Peripheral_Access_Layer BRIC Peripheral Access Layer
 * @{
 */

/** BRIC - Size of Registers Arrays */
#define BRIC_KEYX_I_COUNT                         4u
#define BRIC_KEYY_I_COUNT                         4u

/** BRIC - Register Layout Typedef */
typedef struct {
  __O  uint32_t KEY0[BRIC_KEYX_I_COUNT];           /**< KEY0 Registers (PKB), array offset: 0x0, array step: 0x4 */
  __O  uint32_t KEY1[BRIC_KEYY_I_COUNT];           /**< KEY1 Registers (PKB), array offset: 0x10, array step: 0x4 */
  __IO uint32_t BRIC_CONFIG;                       /**< BRIC CONFIG register, offset: 0x20 */
} BRIC_Type;

/* ----------------------------------------------------------------------------
   -- BRIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BRIC_Register_Masks BRIC Register Masks
 * @{
 */

/*! @name KEY0 - KEY0 Registers (PKB) */
/*! @{ */

#define BRIC_KEY0_KEY0_x_MASK                    (0xFFFFFFFFU)
#define BRIC_KEY0_KEY0_x_SHIFT                   (0U)
/*! KEY0_x - KEY0 written through PKB interface */
#define BRIC_KEY0_KEY0_x(x)                      (((uint32_t)(((uint32_t)(x)) << BRIC_KEY0_KEY0_x_SHIFT)) & BRIC_KEY0_KEY0_x_MASK)
/*! @} */

/* The count of BRIC_KEY0 */
#define BRIC_KEY0_COUNT                          (4U)

/*! @name KEY1 - KEY1 Registers (PKB) */
/*! @{ */

#define BRIC_KEY1_KEY1_x_MASK                    (0xFFFFFFFFU)
#define BRIC_KEY1_KEY1_x_SHIFT                   (0U)
/*! KEY1_x - KEY1 written through PKB interface */
#define BRIC_KEY1_KEY1_x(x)                      (((uint32_t)(((uint32_t)(x)) << BRIC_KEY1_KEY1_x_SHIFT)) & BRIC_KEY1_KEY1_x_MASK)
/*! @} */

/* The count of BRIC_KEY1 */
#define BRIC_KEY1_COUNT                          (4U)

/*! @name BRIC_CONFIG - BRIC CONFIG register */
/*! @{ */

#define BRIC_BRIC_CONFIG_KEY_INDEX_MASK          (0xFFU)
#define BRIC_BRIC_CONFIG_KEY_INDEX_SHIFT         (0U)
/*! KEY_INDEX - KEY INDEX */
#define BRIC_BRIC_CONFIG_KEY_INDEX(x)            (((uint32_t)(((uint32_t)(x)) << BRIC_BRIC_CONFIG_KEY_INDEX_SHIFT)) & BRIC_BRIC_CONFIG_KEY_INDEX_MASK)

#define BRIC_BRIC_CONFIG_IPS_XFR_ERR_EN_MASK     (0x100U)
#define BRIC_BRIC_CONFIG_IPS_XFR_ERR_EN_SHIFT    (8U)
#define BRIC_BRIC_CONFIG_IPS_XFR_ERR_EN(x)       (((uint32_t)(((uint32_t)(x)) << BRIC_BRIC_CONFIG_IPS_XFR_ERR_EN_SHIFT)) & BRIC_BRIC_CONFIG_IPS_XFR_ERR_EN_MASK)

#define BRIC_BRIC_CONFIG_IPS_XFR_WAIT_EN_MASK    (0x200U)
#define BRIC_BRIC_CONFIG_IPS_XFR_WAIT_EN_SHIFT   (9U)
#define BRIC_BRIC_CONFIG_IPS_XFR_WAIT_EN(x)      (((uint32_t)(((uint32_t)(x)) << BRIC_BRIC_CONFIG_IPS_XFR_WAIT_EN_SHIFT)) & BRIC_BRIC_CONFIG_IPS_XFR_WAIT_EN_MASK)

#define BRIC_BRIC_CONFIG_HI_MODE_MASK            (0x400U)
#define BRIC_BRIC_CONFIG_HI_MODE_SHIFT           (10U)
#define BRIC_BRIC_CONFIG_HI_MODE(x)              (((uint32_t)(((uint32_t)(x)) << BRIC_BRIC_CONFIG_HI_MODE_SHIFT)) & BRIC_BRIC_CONFIG_HI_MODE_MASK)

#define BRIC_BRIC_CONFIG_HI_READY_MASK           (0x800U)
#define BRIC_BRIC_CONFIG_HI_READY_SHIFT          (11U)
#define BRIC_BRIC_CONFIG_HI_READY(x)             (((uint32_t)(((uint32_t)(x)) << BRIC_BRIC_CONFIG_HI_READY_SHIFT)) & BRIC_BRIC_CONFIG_HI_READY_MASK)

#define BRIC_BRIC_CONFIG_DIS_PKB_ERR_RESP_MASK   (0x1000U)
#define BRIC_BRIC_CONFIG_DIS_PKB_ERR_RESP_SHIFT  (12U)
#define BRIC_BRIC_CONFIG_DIS_PKB_ERR_RESP(x)     (((uint32_t)(((uint32_t)(x)) << BRIC_BRIC_CONFIG_DIS_PKB_ERR_RESP_SHIFT)) & BRIC_BRIC_CONFIG_DIS_PKB_ERR_RESP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BRIC_Register_Masks */


/*!
 * @}
 */ /* end of group BRIC_Peripheral_Access_Layer */


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


#endif  /* PERI_BRIC_H_ */

