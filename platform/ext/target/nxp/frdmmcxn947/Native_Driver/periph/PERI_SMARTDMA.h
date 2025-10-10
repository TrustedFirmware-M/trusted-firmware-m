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
**         CMSIS Peripheral Access Layer for SMARTDMA
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
 * @file PERI_SMARTDMA.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SMARTDMA
 *
 * CMSIS Peripheral Access Layer for SMARTDMA
 */

#if !defined(PERI_SMARTDMA_H_)
#define PERI_SMARTDMA_H_                         /**< Symbol preventing repeated inclusion */

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
  __IO uint32_t BREAK_ADDR;                        /**< Breakpoint Address, offset: 0x30 */
  __IO uint32_t BREAK_VECT;                        /**< Breakpoint Vector, offset: 0x34 */
  __IO uint32_t EMER_VECT;                         /**< Emergency Vector, offset: 0x38 */
  __IO uint32_t EMER_SEL;                          /**< Emergency Select, offset: 0x3C */
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

/*! @name BREAK_ADDR - Breakpoint Address */
/*! @{ */

#define SMARTDMA_BREAK_ADDR_ADDR_MASK            (0xFFFFFFFCU)
#define SMARTDMA_BREAK_ADDR_ADDR_SHIFT           (2U)
/*! ADDR - 32-bit address to swap to EZHB_BREAK_VECT location */
#define SMARTDMA_BREAK_ADDR_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << SMARTDMA_BREAK_ADDR_ADDR_SHIFT)) & SMARTDMA_BREAK_ADDR_ADDR_MASK)
/*! @} */

/*! @name BREAK_VECT - Breakpoint Vector */
/*! @{ */

#define SMARTDMA_BREAK_VECT_VEC_MASK             (0xFFFFFFFCU)
#define SMARTDMA_BREAK_VECT_VEC_SHIFT            (2U)
/*! VEC - Vector address of user debug routine. */
#define SMARTDMA_BREAK_VECT_VEC(x)               (((uint32_t)(((uint32_t)(x)) << SMARTDMA_BREAK_VECT_VEC_SHIFT)) & SMARTDMA_BREAK_VECT_VEC_MASK)
/*! @} */

/*! @name EMER_VECT - Emergency Vector */
/*! @{ */

#define SMARTDMA_EMER_VECT_VEC_MASK              (0xFFFFFFFCU)
#define SMARTDMA_EMER_VECT_VEC_SHIFT             (2U)
/*! VEC - Vector address of emergency code routine */
#define SMARTDMA_EMER_VECT_VEC(x)                (((uint32_t)(((uint32_t)(x)) << SMARTDMA_EMER_VECT_VEC_SHIFT)) & SMARTDMA_EMER_VECT_VEC_MASK)
/*! @} */

/*! @name EMER_SEL - Emergency Select */
/*! @{ */

#define SMARTDMA_EMER_SEL_EN_MASK                (0x100U)
#define SMARTDMA_EMER_SEL_EN_SHIFT               (8U)
/*! EN - Emergency code routine */
#define SMARTDMA_EMER_SEL_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_EMER_SEL_EN_SHIFT)) & SMARTDMA_EMER_SEL_EN_MASK)

#define SMARTDMA_EMER_SEL_RQ_MASK                (0x200U)
#define SMARTDMA_EMER_SEL_RQ_SHIFT               (9U)
/*! RQ - Software emergency request */
#define SMARTDMA_EMER_SEL_RQ(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_EMER_SEL_RQ_SHIFT)) & SMARTDMA_EMER_SEL_RQ_MASK)
/*! @} */

/*! @name ARM2EZH - ARM to EZH Interrupt Control */
/*! @{ */

#define SMARTDMA_ARM2EZH_IE_MASK                 (0x3U)
#define SMARTDMA_ARM2EZH_IE_SHIFT                (0U)
/*! IE - Interrupt Enable */
#define SMARTDMA_ARM2EZH_IE(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_ARM2EZH_IE_SHIFT)) & SMARTDMA_ARM2EZH_IE_MASK)

#define SMARTDMA_ARM2EZH_GP_MASK                 (0xFFFFFFFCU)
#define SMARTDMA_ARM2EZH_GP_SHIFT                (2U)
/*! GP - General purpose register bits */
#define SMARTDMA_ARM2EZH_GP(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_ARM2EZH_GP_SHIFT)) & SMARTDMA_ARM2EZH_GP_MASK)
/*! @} */

/*! @name EZH2ARM - EZH to ARM Trigger */
/*! @{ */

#define SMARTDMA_EZH2ARM_GP_MASK                 (0xFFFFFFFFU)
#define SMARTDMA_EZH2ARM_GP_SHIFT                (0U)
/*! GP - General purpose register bits Writing to EZH2ARM triggers the ARM interrupt when ARM2EZH [1:0] == 2h */
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

