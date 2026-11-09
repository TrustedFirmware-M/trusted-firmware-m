/*
** ###################################################################
**     Processors:          MCXA286VAPR
**                          MCXA286VASR
**                          MCXA286VLL
**                          MCXA286VLQ
**                          MCXA286VPN
**                          MCXA287VAPR
**                          MCXA287VASR
**                          MCXA287VLL
**                          MCXA287VLQ
**                          MCXA287VPN
**                          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
**                          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA566VLL
**                          MCXA566VLQ
**                          MCXA566VPN
**                          MCXA567VLL
**                          MCXA567VLQ
**                          MCXA567VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SMARTDMA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SMARTDMA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SMARTDMA
 *
 * CMSIS Peripheral Access Layer for SMARTDMA
 */

#if !defined(PERI_SMARTDMA_H_)
#define PERI_SMARTDMA_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
#elif (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA566VLL) || defined(CPU_MCXA566VLQ) || defined(CPU_MCXA566VPN))
#include "MCXA566_COMMON.h"
#elif (defined(CPU_MCXA567VLL) || defined(CPU_MCXA567VLQ) || defined(CPU_MCXA567VPN))
#include "MCXA567_COMMON.h"
#elif (defined(CPU_MCXA577VAPR) || defined(CPU_MCXA577VLL) || defined(CPU_MCXA577VLQ) || defined(CPU_MCXA577VPN))
#include "MCXA577_COMMON.h"
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
   -- SMARTDMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMARTDMA_Peripheral_Access_Layer SMARTDMA Peripheral Access Layer
 * @{
 */

/** SMARTDMA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t BOOTADR;                           /**< Boot Address, offset: 0x20 */
  __IO uint32_t CTRL;                              /**< Control, offset: 0x24 */
  __I  uint32_t PC;                                /**< Program Counter, offset: 0x28 */
  __I  uint32_t SP;                                /**< Stack Pointer, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __IO uint32_t ARM2EZH;                           /**< ARM to EZH Interrupt Control, offset: 0x40 */
  __IO uint32_t EZH2ARM;                           /**< EZH to ARM Trigger, offset: 0x44 */
  __IO uint32_t PENDTRAP;                          /**< Pending Trap Control, offset: 0x48 */
} SMARTDMA_Type;

/* ----------------------------------------------------------------------------
   -- SMARTDMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMARTDMA_Register_Masks SMARTDMA Register Masks
 * @{
 */

/*! @name BOOTADR - Boot Address */
/*! @{ */

#define SMARTDMA_BOOTADR_ADDR_MASK               (0xFFFFFFFCU)
#define SMARTDMA_BOOTADR_ADDR_SHIFT              (2U)
/*! ADDR - 32-bit boot address, the boot address should be 4-byte aligned. */
#define SMARTDMA_BOOTADR_ADDR(x)                 (((uint32_t)(((uint32_t)(x)) << SMARTDMA_BOOTADR_ADDR_SHIFT)) & SMARTDMA_BOOTADR_ADDR_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define SMARTDMA_CTRL_START_MASK                 (0x1U)
#define SMARTDMA_CTRL_START_SHIFT                (0U)
/*! START - Start Bit Ignition */
#define SMARTDMA_CTRL_START(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_START_SHIFT)) & SMARTDMA_CTRL_START_MASK)

#define SMARTDMA_CTRL_EXF_MASK                   (0x2U)
#define SMARTDMA_CTRL_EXF_SHIFT                  (1U)
/*! EXF - External Flag */
#define SMARTDMA_CTRL_EXF(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_EXF_SHIFT)) & SMARTDMA_CTRL_EXF_MASK)

#define SMARTDMA_CTRL_ERRDIS_MASK                (0x4U)
#define SMARTDMA_CTRL_ERRDIS_SHIFT               (2U)
/*! ERRDIS - Error Disable */
#define SMARTDMA_CTRL_ERRDIS(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_ERRDIS_SHIFT)) & SMARTDMA_CTRL_ERRDIS_MASK)

#define SMARTDMA_CTRL_BUFEN_MASK                 (0x8U)
#define SMARTDMA_CTRL_BUFEN_SHIFT                (3U)
/*! BUFEN - Buffer Enable */
#define SMARTDMA_CTRL_BUFEN(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_BUFEN_SHIFT)) & SMARTDMA_CTRL_BUFEN_MASK)

#define SMARTDMA_CTRL_SYNCEN_MASK                (0x10U)
#define SMARTDMA_CTRL_SYNCEN_SHIFT               (4U)
/*! SYNCEN - Sync Enable */
#define SMARTDMA_CTRL_SYNCEN(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_SYNCEN_SHIFT)) & SMARTDMA_CTRL_SYNCEN_MASK)

#define SMARTDMA_CTRL_WKEY_MASK                  (0xFFFF0000U)
#define SMARTDMA_CTRL_WKEY_SHIFT                 (16U)
/*! WKEY - Write Key */
#define SMARTDMA_CTRL_WKEY(x)                    (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_WKEY_SHIFT)) & SMARTDMA_CTRL_WKEY_MASK)
/*! @} */

/*! @name PC - Program Counter */
/*! @{ */

#define SMARTDMA_PC_PC_MASK                      (0xFFFFFFFFU)
#define SMARTDMA_PC_PC_SHIFT                     (0U)
/*! PC - Program Counter */
#define SMARTDMA_PC_PC(x)                        (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PC_PC_SHIFT)) & SMARTDMA_PC_PC_MASK)
/*! @} */

/*! @name SP - Stack Pointer */
/*! @{ */

#define SMARTDMA_SP_SP_MASK                      (0xFFFFFFFFU)
#define SMARTDMA_SP_SP_SHIFT                     (0U)
/*! SP - Stack Pointer */
#define SMARTDMA_SP_SP(x)                        (((uint32_t)(((uint32_t)(x)) << SMARTDMA_SP_SP_SHIFT)) & SMARTDMA_SP_SP_MASK)
/*! @} */

/*! @name ARM2EZH - ARM to EZH Interrupt Control */
/*! @{ */

#define SMARTDMA_ARM2EZH_IE_MASK                 (0x3U)
#define SMARTDMA_ARM2EZH_IE_SHIFT                (0U)
/*! IE - Interrupt Enable
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..SmartDMA write to EZH2ARM triggers an interrupt to Arm core
 *  0b11..SmartDMA write to EZH2ARM, or SmartDMA write 3FFFFFFFh to GP triggers an RXEV to Arm core
 */
#define SMARTDMA_ARM2EZH_IE(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_ARM2EZH_IE_SHIFT)) & SMARTDMA_ARM2EZH_IE_MASK)

#define SMARTDMA_ARM2EZH_GP_MASK                 (0xFFFFFFFCU)
#define SMARTDMA_ARM2EZH_GP_SHIFT                (2U)
/*! GP - GPR Bits */
#define SMARTDMA_ARM2EZH_GP(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_ARM2EZH_GP_SHIFT)) & SMARTDMA_ARM2EZH_GP_MASK)
/*! @} */

/*! @name EZH2ARM - EZH to ARM Trigger */
/*! @{ */

#define SMARTDMA_EZH2ARM_GP_MASK                 (0xFFFFFFFFU)
#define SMARTDMA_EZH2ARM_GP_SHIFT                (0U)
/*! GP - GPR Bits */
#define SMARTDMA_EZH2ARM_GP(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_EZH2ARM_GP_SHIFT)) & SMARTDMA_EZH2ARM_GP_MASK)
/*! @} */

/*! @name PENDTRAP - Pending Trap Control */
/*! @{ */

#define SMARTDMA_PENDTRAP_STATUS_MASK            (0xFFU)
#define SMARTDMA_PENDTRAP_STATUS_SHIFT           (0U)
/*! STATUS - Status Flag or Pending Trap Request */
#define SMARTDMA_PENDTRAP_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PENDTRAP_STATUS_SHIFT)) & SMARTDMA_PENDTRAP_STATUS_MASK)

#define SMARTDMA_PENDTRAP_POL_MASK               (0xFF00U)
#define SMARTDMA_PENDTRAP_POL_SHIFT              (8U)
/*! POL - Polarity */
#define SMARTDMA_PENDTRAP_POL(x)                 (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PENDTRAP_POL_SHIFT)) & SMARTDMA_PENDTRAP_POL_MASK)

#define SMARTDMA_PENDTRAP_EN_MASK                (0xFF0000U)
#define SMARTDMA_PENDTRAP_EN_SHIFT               (16U)
/*! EN - Enable Pending Trap */
#define SMARTDMA_PENDTRAP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PENDTRAP_EN_SHIFT)) & SMARTDMA_PENDTRAP_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SMARTDMA_Register_Masks */


/*!
 * @}
 */ /* end of group SMARTDMA_Peripheral_Access_Layer */


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


#endif  /* PERI_SMARTDMA_H_ */

