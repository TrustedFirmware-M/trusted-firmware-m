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
**         CMSIS Peripheral Access Layer for FLASH_ARB_WRAP_SYN
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
 * @file PERI_FLASH_ARB_WRAP_SYN.h
 * @version 1.0
 * @date 2026-01-09
 * @brief CMSIS Peripheral Access Layer for FLASH_ARB_WRAP_SYN
 *
 * CMSIS Peripheral Access Layer for FLASH_ARB_WRAP_SYN
 */

#if !defined(PERI_FLASH_ARB_WRAP_SYN_H_)
#define PERI_FLASH_ARB_WRAP_SYN_H_               /**< Symbol preventing repeated inclusion */

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
   -- FLASH_ARB_WRAP_SYN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_ARB_WRAP_SYN_Peripheral_Access_Layer FLASH_ARB_WRAP_SYN Peripheral Access Layer
 * @{
 */

/** FLASH_ARB_WRAP_SYN - Register Layout Typedef */
typedef struct {
  __IO uint32_t FARBCTRL;                          /**< FLASH_ARB control, offset: 0x0 */
  __IO uint32_t FARBSTATUS;                        /**< Flash Arbiter Status, offset: 0x4 */
} FLASH_ARB_WRAP_SYN_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_ARB_WRAP_SYN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_ARB_WRAP_SYN_Register_Masks FLASH_ARB_WRAP_SYN Register Masks
 * @{
 */

/*! @name FARBCTRL - FLASH_ARB control */
/*! @{ */

#define FLASH_ARB_WRAP_SYN_FARBCTRL_WR_WR_IE_MASK (0x1U)
#define FLASH_ARB_WRAP_SYN_FARBCTRL_WR_WR_IE_SHIFT (0U)
/*! WR_WR_IE - WR_WR Interrupt Enable
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define FLASH_ARB_WRAP_SYN_FARBCTRL_WR_WR_IE(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBCTRL_WR_WR_IE_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBCTRL_WR_WR_IE_MASK)

#define FLASH_ARB_WRAP_SYN_FARBCTRL_RD_WR_IE_MASK (0x2U)
#define FLASH_ARB_WRAP_SYN_FARBCTRL_RD_WR_IE_SHIFT (1U)
/*! RD_WR_IE - RD_WR Interrupt Enable
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define FLASH_ARB_WRAP_SYN_FARBCTRL_RD_WR_IE(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBCTRL_RD_WR_IE_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBCTRL_RD_WR_IE_MASK)

#define FLASH_ARB_WRAP_SYN_FARBCTRL_RD_RD_IE_MASK (0x4U)
#define FLASH_ARB_WRAP_SYN_FARBCTRL_RD_RD_IE_SHIFT (2U)
/*! RD_RD_IE - RD_RD Interrupt Enable
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define FLASH_ARB_WRAP_SYN_FARBCTRL_RD_RD_IE(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBCTRL_RD_RD_IE_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBCTRL_RD_RD_IE_MASK)

#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RWSC_MASK (0xF0000U)
#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RWSC_SHIFT (16U)
/*! FARB_RWSC - Read Wait-State Control */
#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RWSC(x) (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RWSC_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RWSC_MASK)

#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_PRI_MASK (0x300000U)
#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_PRI_SHIFT (20U)
/*! FARB_PRI - FARB CHANNEL PRIORITY
 *  0b00..Channel-0 Read high priority, Channel-0 Write high priority.
 *  0b01..Channel-1 Read high priority, Channel-0 Write high priority.
 *  0b10..Channel-0 Read high priority, Channel-1 Write high priority.
 *  0b11..Channel-1 Read high priority, Channel-1 Write high priority.
 */
#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_PRI(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_PRI_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_PRI_MASK)

#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RST_MASK (0x8000000U)
#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RST_SHIFT (27U)
/*! FARB_RST - FARB Reset */
#define FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RST(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RST_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBCTRL_FARB_RST_MASK)
/*! @} */

/*! @name FARBSTATUS - Flash Arbiter Status */
/*! @{ */

#define FLASH_ARB_WRAP_SYN_FARBSTATUS_WR_WR_MASK (0x1U)
#define FLASH_ARB_WRAP_SYN_FARBSTATUS_WR_WR_SHIFT (0U)
/*! WR_WR - Parallel Writes Conflict
 *  0b0..Conflict of write and write happened
 *  0b1..No conflict of write and write
 */
#define FLASH_ARB_WRAP_SYN_FARBSTATUS_WR_WR(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBSTATUS_WR_WR_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBSTATUS_WR_WR_MASK)

#define FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_WR_MASK (0x2U)
#define FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_WR_SHIFT (1U)
/*! RD_WR - Read and Write Conflict
 *  0b0..Conflict of read and write happened
 *  0b1..No conflict of read and write
 */
#define FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_WR(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_WR_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_WR_MASK)

#define FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_RD_MASK (0x4U)
#define FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_RD_SHIFT (2U)
/*! RD_RD - Parallel Reads Conflict
 *  0b0..Conflict of read and read happened
 *  0b1..No conflict of read and read
 */
#define FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_RD(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_RD_SHIFT)) & FLASH_ARB_WRAP_SYN_FARBSTATUS_RD_RD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_ARB_WRAP_SYN_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_ARB_WRAP_SYN_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_ARB_WRAP_SYN_H_ */

