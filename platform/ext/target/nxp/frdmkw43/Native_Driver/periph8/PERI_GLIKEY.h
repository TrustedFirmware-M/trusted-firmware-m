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
**         CMSIS Peripheral Access Layer for GLIKEY
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
 * @file PERI_GLIKEY.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for GLIKEY
 *
 * CMSIS Peripheral Access Layer for GLIKEY
 */

#if !defined(PERI_GLIKEY_H_)
#define PERI_GLIKEY_H_                           /**< Symbol preventing repeated inclusion */

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
   -- GLIKEY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GLIKEY_Peripheral_Access_Layer GLIKEY Peripheral Access Layer
 * @{
 */

/** GLIKEY - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL_0;                            /**< Control Register 0 SFR, offset: 0x0 */
  __IO uint32_t CTRL_1;                            /**< Control Register 1 SFR, offset: 0x4 */
  __IO uint32_t INTR_CTRL;                         /**< Interrupt Control, offset: 0x8 */
  __I  uint32_t STATUS;                            /**< Status, offset: 0xC */
       uint8_t RESERVED_0[236];
  __I  uint32_t VERSION;                           /**< IP Version, offset: 0xFC */
} GLIKEY_Type;

/* ----------------------------------------------------------------------------
   -- GLIKEY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GLIKEY_Register_Masks GLIKEY Register Masks
 * @{
 */

/*! @name CTRL_0 - Control Register 0 SFR */
/*! @{ */

#define GLIKEY_CTRL_0_WRITE_INDEX_MASK           (0xFFU)
#define GLIKEY_CTRL_0_WRITE_INDEX_SHIFT          (0U)
/*! WRITE_INDEX - Write Index */
#define GLIKEY_CTRL_0_WRITE_INDEX(x)             (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_0_WRITE_INDEX_SHIFT)) & GLIKEY_CTRL_0_WRITE_INDEX_MASK)

#define GLIKEY_CTRL_0_RESERVED15_MASK            (0xFF00U)
#define GLIKEY_CTRL_0_RESERVED15_SHIFT           (8U)
/*! RESERVED15 - Reserved for future use */
#define GLIKEY_CTRL_0_RESERVED15(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_0_RESERVED15_SHIFT)) & GLIKEY_CTRL_0_RESERVED15_MASK)

#define GLIKEY_CTRL_0_WR_EN_0_MASK               (0x30000U)
#define GLIKEY_CTRL_0_WR_EN_0_SHIFT              (16U)
/*! WR_EN_0 - Write enable associated to the SSR.
 *  0b00..Enable
 *  0b01..Disable
 */
#define GLIKEY_CTRL_0_WR_EN_0(x)                 (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_0_WR_EN_0_SHIFT)) & GLIKEY_CTRL_0_WR_EN_0_MASK)

#define GLIKEY_CTRL_0_SFT_RST_MASK               (0x40000U)
#define GLIKEY_CTRL_0_SFT_RST_SHIFT              (18U)
/*! SFT_RST - Soft reset for the core reset.
 *  0b0..No effect
 *  0b1..Triggers the soft reset
 */
#define GLIKEY_CTRL_0_SFT_RST(x)                 (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_0_SFT_RST_SHIFT)) & GLIKEY_CTRL_0_SFT_RST_MASK)

#define GLIKEY_CTRL_0_RESERVED31_MASK            (0xFFF80000U)
#define GLIKEY_CTRL_0_RESERVED31_SHIFT           (19U)
/*! RESERVED31 - Reserved for future use */
#define GLIKEY_CTRL_0_RESERVED31(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_0_RESERVED31_SHIFT)) & GLIKEY_CTRL_0_RESERVED31_MASK)
/*! @} */

/*! @name CTRL_1 - Control Register 1 SFR */
/*! @{ */

#define GLIKEY_CTRL_1_READ_INDEX_MASK            (0xFFU)
#define GLIKEY_CTRL_1_READ_INDEX_SHIFT           (0U)
/*! READ_INDEX - Index status, Writing an index value to this register will request the block to return the lock status of this index. */
#define GLIKEY_CTRL_1_READ_INDEX(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_1_READ_INDEX_SHIFT)) & GLIKEY_CTRL_1_READ_INDEX_MASK)

#define GLIKEY_CTRL_1_RESERVED15_MASK            (0xFF00U)
#define GLIKEY_CTRL_1_RESERVED15_SHIFT           (8U)
/*! RESERVED15 - Reserved for future use */
#define GLIKEY_CTRL_1_RESERVED15(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_1_RESERVED15_SHIFT)) & GLIKEY_CTRL_1_RESERVED15_MASK)

#define GLIKEY_CTRL_1_WR_EN_1_MASK               (0x30000U)
#define GLIKEY_CTRL_1_WR_EN_1_SHIFT              (16U)
/*! WR_EN_1 - Write Enable associated to the SSR.
 *  0b00..Disable
 *  0b01..Enable
 */
#define GLIKEY_CTRL_1_WR_EN_1(x)                 (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_1_WR_EN_1_SHIFT)) & GLIKEY_CTRL_1_WR_EN_1_MASK)

#define GLIKEY_CTRL_1_SFR_LOCK_MASK              (0x3C0000U)
#define GLIKEY_CTRL_1_SFR_LOCK_SHIFT             (18U)
/*! SFR_LOCK - SFR Lock
 *  0b0101..Locked
 *  0b1010..Unlocked
 */
#define GLIKEY_CTRL_1_SFR_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_1_SFR_LOCK_SHIFT)) & GLIKEY_CTRL_1_SFR_LOCK_MASK)

#define GLIKEY_CTRL_1_RESERVED31_MASK            (0xFFC00000U)
#define GLIKEY_CTRL_1_RESERVED31_SHIFT           (22U)
/*! RESERVED31 - Reserved for future use */
#define GLIKEY_CTRL_1_RESERVED31(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_CTRL_1_RESERVED31_SHIFT)) & GLIKEY_CTRL_1_RESERVED31_MASK)
/*! @} */

/*! @name INTR_CTRL - Interrupt Control */
/*! @{ */

#define GLIKEY_INTR_CTRL_INT_EN_MASK             (0x1U)
#define GLIKEY_INTR_CTRL_INT_EN_SHIFT            (0U)
/*! INT_EN - Interrupt Enable. Writing a 1, Interrupt asserts on Interrupt output port
 *  0b0..No effect
 *  0b1..Interrupt enabled
 */
#define GLIKEY_INTR_CTRL_INT_EN(x)               (((uint32_t)(((uint32_t)(x)) << GLIKEY_INTR_CTRL_INT_EN_SHIFT)) & GLIKEY_INTR_CTRL_INT_EN_MASK)

#define GLIKEY_INTR_CTRL_INT_CLR_MASK            (0x2U)
#define GLIKEY_INTR_CTRL_INT_CLR_SHIFT           (1U)
/*! INT_CLR - Interrupt Clear. Writing a 1 to this register creates a single interrupt clear pulse. This register reads as 0
 *  0b0..No effect
 *  0b1..Interrupt status bit cleared
 */
#define GLIKEY_INTR_CTRL_INT_CLR(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_INTR_CTRL_INT_CLR_SHIFT)) & GLIKEY_INTR_CTRL_INT_CLR_MASK)

#define GLIKEY_INTR_CTRL_INT_SET_MASK            (0x4U)
#define GLIKEY_INTR_CTRL_INT_SET_SHIFT           (2U)
/*! INT_SET - Software Interrupt Set.
 *  0b0..No effect
 *  0b1..Triggers interrupt
 */
#define GLIKEY_INTR_CTRL_INT_SET(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_INTR_CTRL_INT_SET_SHIFT)) & GLIKEY_INTR_CTRL_INT_SET_MASK)

#define GLIKEY_INTR_CTRL_RESERVED31_MASK         (0xFFFFFFF8U)
#define GLIKEY_INTR_CTRL_RESERVED31_SHIFT        (3U)
/*! RESERVED31 - Reserved for future use */
#define GLIKEY_INTR_CTRL_RESERVED31(x)           (((uint32_t)(((uint32_t)(x)) << GLIKEY_INTR_CTRL_RESERVED31_SHIFT)) & GLIKEY_INTR_CTRL_RESERVED31_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define GLIKEY_STATUS_INT_STATUS_MASK            (0x1U)
#define GLIKEY_STATUS_INT_STATUS_SHIFT           (0U)
/*! INT_STATUS - Interrupt Status.
 *  0b0..No trigger
 *  0b1..Trigger captured
 */
#define GLIKEY_STATUS_INT_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_STATUS_INT_STATUS_SHIFT)) & GLIKEY_STATUS_INT_STATUS_MASK)

#define GLIKEY_STATUS_LOCK_STATUS_MASK           (0x2U)
#define GLIKEY_STATUS_LOCK_STATUS_SHIFT          (1U)
/*! LOCK_STATUS - Provides the current lock status of indexes.
 *  0b0..Current read index is not locked
 *  0b1..Current read index is locked
 */
#define GLIKEY_STATUS_LOCK_STATUS(x)             (((uint32_t)(((uint32_t)(x)) << GLIKEY_STATUS_LOCK_STATUS_SHIFT)) & GLIKEY_STATUS_LOCK_STATUS_MASK)

#define GLIKEY_STATUS_ERROR_STATUS_MASK          (0x1CU)
#define GLIKEY_STATUS_ERROR_STATUS_SHIFT         (2U)
/*! ERROR_STATUS - Status of the Error
 *  0b000..No error
 *  0b001..FSM error has occurred
 *  0b010..Write index out of the bound (OOB) error
 *  0b011..Write index OOB and FSM error
 *  0b100..Read index OOB error
 *  0b110..Write index and read index OOB error
 *  0b111..Read index OOB, write index OOB, and FSM error
 */
#define GLIKEY_STATUS_ERROR_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << GLIKEY_STATUS_ERROR_STATUS_SHIFT)) & GLIKEY_STATUS_ERROR_STATUS_MASK)

#define GLIKEY_STATUS_RESERVED18_MASK            (0x7FFE0U)
#define GLIKEY_STATUS_RESERVED18_SHIFT           (5U)
/*! RESERVED18 - Reserved for future use */
#define GLIKEY_STATUS_RESERVED18(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_STATUS_RESERVED18_SHIFT)) & GLIKEY_STATUS_RESERVED18_MASK)

#define GLIKEY_STATUS_FSM_STATE_MASK             (0xFFF80000U)
#define GLIKEY_STATUS_FSM_STATE_SHIFT            (19U)
/*! FSM_STATE - Status of FSM */
#define GLIKEY_STATUS_FSM_STATE(x)               (((uint32_t)(((uint32_t)(x)) << GLIKEY_STATUS_FSM_STATE_SHIFT)) & GLIKEY_STATUS_FSM_STATE_MASK)
/*! @} */

/*! @name VERSION - IP Version */
/*! @{ */

#define GLIKEY_VERSION_Reserved3_MASK            (0xFU)
#define GLIKEY_VERSION_Reserved3_SHIFT           (0U)
/*! Reserved3 - Reserved */
#define GLIKEY_VERSION_Reserved3(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_Reserved3_SHIFT)) & GLIKEY_VERSION_Reserved3_MASK)

#define GLIKEY_VERSION_Reserved7_MASK            (0xF0U)
#define GLIKEY_VERSION_Reserved7_SHIFT           (4U)
/*! Reserved7 - Reserved */
#define GLIKEY_VERSION_Reserved7(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_Reserved7_SHIFT)) & GLIKEY_VERSION_Reserved7_MASK)

#define GLIKEY_VERSION_Reserved11_MASK           (0xF00U)
#define GLIKEY_VERSION_Reserved11_SHIFT          (8U)
/*! Reserved11 - Reserved */
#define GLIKEY_VERSION_Reserved11(x)             (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_Reserved11_SHIFT)) & GLIKEY_VERSION_Reserved11_MASK)

#define GLIKEY_VERSION_Reserved15_MASK           (0xF000U)
#define GLIKEY_VERSION_Reserved15_SHIFT          (12U)
/*! Reserved15 - Reserved */
#define GLIKEY_VERSION_Reserved15(x)             (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_Reserved15_SHIFT)) & GLIKEY_VERSION_Reserved15_MASK)

#define GLIKEY_VERSION_MILESTONE_MASK            (0x30000U)
#define GLIKEY_VERSION_MILESTONE_SHIFT           (16U)
/*! MILESTONE - Release milestone. 00-PREL, 01-BR, 10-SI, 11-GO. */
#define GLIKEY_VERSION_MILESTONE(x)              (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_MILESTONE_SHIFT)) & GLIKEY_VERSION_MILESTONE_MASK)

#define GLIKEY_VERSION_FSM_CONFIG_MASK           (0x40000U)
#define GLIKEY_VERSION_FSM_CONFIG_SHIFT          (18U)
/*! FSM_CONFIG - 0:4 step, 1:8 step */
#define GLIKEY_VERSION_FSM_CONFIG(x)             (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_FSM_CONFIG_SHIFT)) & GLIKEY_VERSION_FSM_CONFIG_MASK)

#define GLIKEY_VERSION_INDEX_CONFIG_MASK         (0x7F80000U)
#define GLIKEY_VERSION_INDEX_CONFIG_SHIFT        (19U)
/*! INDEX_CONFIG - Configured number of addressable indexes */
#define GLIKEY_VERSION_INDEX_CONFIG(x)           (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_INDEX_CONFIG_SHIFT)) & GLIKEY_VERSION_INDEX_CONFIG_MASK)

#define GLIKEY_VERSION_Reserved31_MASK           (0xF8000000U)
#define GLIKEY_VERSION_Reserved31_SHIFT          (27U)
/*! Reserved31 - Reserved for future use */
#define GLIKEY_VERSION_Reserved31(x)             (((uint32_t)(((uint32_t)(x)) << GLIKEY_VERSION_Reserved31_SHIFT)) & GLIKEY_VERSION_Reserved31_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GLIKEY_Register_Masks */


/*!
 * @}
 */ /* end of group GLIKEY_Peripheral_Access_Layer */


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


#endif  /* PERI_GLIKEY_H_ */

