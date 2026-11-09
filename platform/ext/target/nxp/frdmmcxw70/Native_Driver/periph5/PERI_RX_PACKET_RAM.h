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
**         CMSIS Peripheral Access Layer for RX_PACKET_RAM
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
 * @file PERI_RX_PACKET_RAM.h
 * @version 1.0
 * @date 2026-01-09
 * @brief CMSIS Peripheral Access Layer for RX_PACKET_RAM
 *
 * CMSIS Peripheral Access Layer for RX_PACKET_RAM
 */

#if !defined(PERI_RX_PACKET_RAM_H_)
#define PERI_RX_PACKET_RAM_H_                    /**< Symbol preventing repeated inclusion */

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
   -- RX_PACKET_RAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RX_PACKET_RAM_Peripheral_Access_Layer RX_PACKET_RAM Peripheral Access Layer
 * @{
 */

/** RX_PACKET_RAM - Size of Registers Arrays */
#define RX_PACKET_RAM_PACKET_RAM_COUNT            512u

/** RX_PACKET_RAM - Register Layout Typedef */
typedef struct {
  __IO uint32_t PACKET_RAM[RX_PACKET_RAM_PACKET_RAM_COUNT]; /**< Shared Packet RAM for multiple Link Layer usage., array offset: 0x0, array step: 0x4 */
} RX_PACKET_RAM_Type;

/* ----------------------------------------------------------------------------
   -- RX_PACKET_RAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RX_PACKET_RAM_Register_Masks RX_PACKET_RAM Register Masks
 * @{
 */

/*! @name PACKET_RAM - Shared Packet RAM for multiple Link Layer usage. */
/*! @{ */

#define RX_PACKET_RAM_PACKET_RAM_RAM_MASK        (0xFFFFFFFFU)
#define RX_PACKET_RAM_PACKET_RAM_RAM_SHIFT       (0U)
/*! RAM - One entry in the packet RAM */
#define RX_PACKET_RAM_PACKET_RAM_RAM(x)          (((uint32_t)(((uint32_t)(x)) << RX_PACKET_RAM_PACKET_RAM_RAM_SHIFT)) & RX_PACKET_RAM_PACKET_RAM_RAM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RX_PACKET_RAM_Register_Masks */


/*!
 * @}
 */ /* end of group RX_PACKET_RAM_Peripheral_Access_Layer */


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


#endif  /* PERI_RX_PACKET_RAM_H_ */

