/*
** ###################################################################
**     Processors:          LPC5526JBD100
**                          LPC5526JBD64
**                          LPC5526JEV98
**                          LPC5528JBD100
**                          LPC5528JBD64
**                          LPC5528JEV59
**                          LPC5528JEV98
**                          LPC55S26JBD100
**                          LPC55S26JBD64
**                          LPC55S26JEV98
**                          LPC55S28JBD100
**                          LPC55S28JBD64
**                          LPC55S28JEV59
**                          LPC55S28JEV98
**                          LPC55S66JBD100_cm33_core0
**                          LPC55S66JBD100_cm33_core1
**                          LPC55S66JBD64_cm33_core0
**                          LPC55S66JBD64_cm33_core1
**                          LPC55S66JEV98_cm33_core0
**                          LPC55S66JEV98_cm33_core1
**                          LPC55S69JBD100_cm33_core0
**                          LPC55S69JBD100_cm33_core1
**                          LPC55S69JBD64_cm33_core0
**                          LPC55S69JBD64_cm33_core1
**                          LPC55S69JEV59_cm33_core0
**                          LPC55S69JEV59_cm33_core1
**                          LPC55S69JEV98_cm33_core0
**                          LPC55S69JEV98_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250529
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLEXCOMM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-08-22)
**         Initial version based on v0.2UM
**     - rev. 1.1 (2019-05-16)
**         Initial A1 version based on v1.3UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLEXCOMM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLEXCOMM
 *
 * CMSIS Peripheral Access Layer for FLEXCOMM
 */

#if !defined(PERI_FLEXCOMM_H_)
#define PERI_FLEXCOMM_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5526JBD100) || defined(CPU_LPC5526JBD64) || defined(CPU_LPC5526JEV98))
#include "LPC5526_COMMON.h"
#elif (defined(CPU_LPC5528JBD100) || defined(CPU_LPC5528JBD64) || defined(CPU_LPC5528JEV59) || defined(CPU_LPC5528JEV98))
#include "LPC5528_COMMON.h"
#elif (defined(CPU_LPC55S26JBD100) || defined(CPU_LPC55S26JBD64) || defined(CPU_LPC55S26JEV98))
#include "LPC55S26_COMMON.h"
#elif (defined(CPU_LPC55S28JBD100) || defined(CPU_LPC55S28JBD64) || defined(CPU_LPC55S28JEV59) || defined(CPU_LPC55S28JEV98))
#include "LPC55S28_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core0) || defined(CPU_LPC55S66JBD64_cm33_core0) || defined(CPU_LPC55S66JEV98_cm33_core0))
#include "LPC55S66_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core1) || defined(CPU_LPC55S66JBD64_cm33_core1) || defined(CPU_LPC55S66JEV98_cm33_core1))
#include "LPC55S66_cm33_core1_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core0) || defined(CPU_LPC55S69JBD64_cm33_core0) || defined(CPU_LPC55S69JEV59_cm33_core0) || defined(CPU_LPC55S69JEV98_cm33_core0))
#include "LPC55S69_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core1) || defined(CPU_LPC55S69JBD64_cm33_core1) || defined(CPU_LPC55S69JEV59_cm33_core1) || defined(CPU_LPC55S69JEV98_cm33_core1))
#include "LPC55S69_cm33_core1_COMMON.h"
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
   -- FLEXCOMM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXCOMM_Peripheral_Access_Layer FLEXCOMM Peripheral Access Layer
 * @{
 */

/** FLEXCOMM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4088];
  __IO uint32_t PSELID;                            /**< Peripheral Select and Flexcomm ID register., offset: 0xFF8 */
  __I  uint32_t PID;                               /**< Peripheral identification register., offset: 0xFFC */
} FLEXCOMM_Type;

/* ----------------------------------------------------------------------------
   -- FLEXCOMM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXCOMM_Register_Masks FLEXCOMM Register Masks
 * @{
 */

/*! @name PSELID - Peripheral Select and Flexcomm ID register. */
/*! @{ */

#define FLEXCOMM_PSELID_PERSEL_MASK              (0x7U)
#define FLEXCOMM_PSELID_PERSEL_SHIFT             (0U)
/*! PERSEL - Peripheral Select. This field is writable by software.
 *  0b000..No peripheral selected.
 *  0b001..USART function selected.
 *  0b010..SPI function selected.
 *  0b011..I2C function selected.
 *  0b100..I2S transmit function selected.
 *  0b101..I2S receive function selected.
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define FLEXCOMM_PSELID_PERSEL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PSELID_PERSEL_SHIFT)) & FLEXCOMM_PSELID_PERSEL_MASK)

#define FLEXCOMM_PSELID_LOCK_MASK                (0x8U)
#define FLEXCOMM_PSELID_LOCK_SHIFT               (3U)
/*! LOCK - Lock the peripheral select. This field is writable by software.
 *  0b0..Peripheral select can be changed by software.
 *  0b1..Peripheral select is locked and cannot be changed until this Flexcomm or the entire device is reset.
 */
#define FLEXCOMM_PSELID_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PSELID_LOCK_SHIFT)) & FLEXCOMM_PSELID_LOCK_MASK)

#define FLEXCOMM_PSELID_USARTPRESENT_MASK        (0x10U)
#define FLEXCOMM_PSELID_USARTPRESENT_SHIFT       (4U)
/*! USARTPRESENT - USART present indicator. This field is Read-only.
 *  0b0..This Flexcomm does not include the USART function.
 *  0b1..This Flexcomm includes the USART function.
 */
#define FLEXCOMM_PSELID_USARTPRESENT(x)          (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PSELID_USARTPRESENT_SHIFT)) & FLEXCOMM_PSELID_USARTPRESENT_MASK)

#define FLEXCOMM_PSELID_SPIPRESENT_MASK          (0x20U)
#define FLEXCOMM_PSELID_SPIPRESENT_SHIFT         (5U)
/*! SPIPRESENT - SPI present indicator. This field is Read-only.
 *  0b0..This Flexcomm does not include the SPI function.
 *  0b1..This Flexcomm includes the SPI function.
 */
#define FLEXCOMM_PSELID_SPIPRESENT(x)            (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PSELID_SPIPRESENT_SHIFT)) & FLEXCOMM_PSELID_SPIPRESENT_MASK)

#define FLEXCOMM_PSELID_I2CPRESENT_MASK          (0x40U)
#define FLEXCOMM_PSELID_I2CPRESENT_SHIFT         (6U)
/*! I2CPRESENT - I2C present indicator. This field is Read-only.
 *  0b0..This Flexcomm does not include the I2C function.
 *  0b1..This Flexcomm includes the I2C function.
 */
#define FLEXCOMM_PSELID_I2CPRESENT(x)            (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PSELID_I2CPRESENT_SHIFT)) & FLEXCOMM_PSELID_I2CPRESENT_MASK)

#define FLEXCOMM_PSELID_I2SPRESENT_MASK          (0x80U)
#define FLEXCOMM_PSELID_I2SPRESENT_SHIFT         (7U)
/*! I2SPRESENT - I 2S present indicator. This field is Read-only.
 *  0b0..This Flexcomm does not include the I2S function.
 *  0b1..This Flexcomm includes the I2S function.
 */
#define FLEXCOMM_PSELID_I2SPRESENT(x)            (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PSELID_I2SPRESENT_SHIFT)) & FLEXCOMM_PSELID_I2SPRESENT_MASK)

#define FLEXCOMM_PSELID_ID_MASK                  (0xFFFFF000U)
#define FLEXCOMM_PSELID_ID_SHIFT                 (12U)
/*! ID - Flexcomm ID. */
#define FLEXCOMM_PSELID_ID(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PSELID_ID_SHIFT)) & FLEXCOMM_PSELID_ID_MASK)
/*! @} */

/*! @name PID - Peripheral identification register. */
/*! @{ */

#define FLEXCOMM_PID_APERTURE_MASK               (0xFFU)
#define FLEXCOMM_PID_APERTURE_SHIFT              (0U)
/*! APERTURE - size aperture for the register port on the bus (APB or AHB). */
#define FLEXCOMM_PID_APERTURE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PID_APERTURE_SHIFT)) & FLEXCOMM_PID_APERTURE_MASK)

#define FLEXCOMM_PID_MINOR_REV_MASK              (0xF00U)
#define FLEXCOMM_PID_MINOR_REV_SHIFT             (8U)
/*! MINOR_REV - Minor revision of module implementation. */
#define FLEXCOMM_PID_MINOR_REV(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PID_MINOR_REV_SHIFT)) & FLEXCOMM_PID_MINOR_REV_MASK)

#define FLEXCOMM_PID_MAJOR_REV_MASK              (0xF000U)
#define FLEXCOMM_PID_MAJOR_REV_SHIFT             (12U)
/*! MAJOR_REV - Major revision of module implementation. */
#define FLEXCOMM_PID_MAJOR_REV(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PID_MAJOR_REV_SHIFT)) & FLEXCOMM_PID_MAJOR_REV_MASK)

#define FLEXCOMM_PID_ID_MASK                     (0xFFFF0000U)
#define FLEXCOMM_PID_ID_SHIFT                    (16U)
/*! ID - Module identifier for the selected function. */
#define FLEXCOMM_PID_ID(x)                       (((uint32_t)(((uint32_t)(x)) << FLEXCOMM_PID_ID_SHIFT)) & FLEXCOMM_PID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLEXCOMM_Register_Masks */


/*!
 * @}
 */ /* end of group FLEXCOMM_Peripheral_Access_Layer */


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


#endif  /* PERI_FLEXCOMM_H_ */

