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
**         CMSIS Peripheral Access Layer for LP_FLEXCOMM
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
 * @file PERI_LP_FLEXCOMM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LP_FLEXCOMM
 *
 * CMSIS Peripheral Access Layer for LP_FLEXCOMM
 */

#if !defined(PERI_LP_FLEXCOMM_H_)
#define PERI_LP_FLEXCOMM_H_                      /**< Symbol preventing repeated inclusion */

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
   -- LP_FLEXCOMM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LP_FLEXCOMM_Peripheral_Access_Layer LP_FLEXCOMM Peripheral Access Layer
 * @{
 */

/** LP_FLEXCOMM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4084];
  __I  uint32_t ISTAT;                             /**< Interrupt Status, offset: 0xFF4 */
  __IO uint32_t PSELID;                            /**< Peripheral Select and ID, offset: 0xFF8 */
} LP_FLEXCOMM_Type;

/* ----------------------------------------------------------------------------
   -- LP_FLEXCOMM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LP_FLEXCOMM_Register_Masks LP_FLEXCOMM Register Masks
 * @{
 */

/*! @name ISTAT - Interrupt Status */
/*! @{ */

#define LP_FLEXCOMM_ISTAT_UARTTX_MASK            (0x1U)
#define LP_FLEXCOMM_ISTAT_UARTTX_SHIFT           (0U)
/*! UARTTX - UART TX Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_UARTTX(x)              (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_UARTTX_SHIFT)) & LP_FLEXCOMM_ISTAT_UARTTX_MASK)

#define LP_FLEXCOMM_ISTAT_UARTRX_MASK            (0x2U)
#define LP_FLEXCOMM_ISTAT_UARTRX_SHIFT           (1U)
/*! UARTRX - UART RX Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_UARTRX(x)              (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_UARTRX_SHIFT)) & LP_FLEXCOMM_ISTAT_UARTRX_MASK)

#define LP_FLEXCOMM_ISTAT_SPI_MASK               (0x4U)
#define LP_FLEXCOMM_ISTAT_SPI_SHIFT              (2U)
/*! SPI - SPI Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_SPI(x)                 (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_SPI_SHIFT)) & LP_FLEXCOMM_ISTAT_SPI_MASK)

#define LP_FLEXCOMM_ISTAT_I2CM_MASK              (0x10U)
#define LP_FLEXCOMM_ISTAT_I2CM_SHIFT             (4U)
/*! I2CM - I2C Controller Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_I2CM(x)                (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_I2CM_SHIFT)) & LP_FLEXCOMM_ISTAT_I2CM_MASK)

#define LP_FLEXCOMM_ISTAT_I2CS_MASK              (0x20U)
#define LP_FLEXCOMM_ISTAT_I2CS_SHIFT             (5U)
/*! I2CS - I2C Subordinate Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_I2CS(x)                (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_I2CS_SHIFT)) & LP_FLEXCOMM_ISTAT_I2CS_MASK)
/*! @} */

/*! @name PSELID - Peripheral Select and ID */
/*! @{ */

#define LP_FLEXCOMM_PSELID_PERSEL_MASK           (0x7U)
#define LP_FLEXCOMM_PSELID_PERSEL_SHIFT          (0U)
/*! PERSEL - Peripheral Select
 *  0b000..No peripheral selected
 *  0b001..UART
 *  0b010..SPI
 *  0b011..I2C
 *  0b111..UART and I2C
 */
#define LP_FLEXCOMM_PSELID_PERSEL(x)             (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_PERSEL_SHIFT)) & LP_FLEXCOMM_PSELID_PERSEL_MASK)

#define LP_FLEXCOMM_PSELID_LOCK_MASK             (0x8U)
#define LP_FLEXCOMM_PSELID_LOCK_SHIFT            (3U)
/*! LOCK - Lock
 *  0b0..PERSEL is writable
 *  0b1..PERSEL is not writable
 */
#define LP_FLEXCOMM_PSELID_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_LOCK_SHIFT)) & LP_FLEXCOMM_PSELID_LOCK_MASK)

#define LP_FLEXCOMM_PSELID_UARTPRESENT_MASK      (0x10U)
#define LP_FLEXCOMM_PSELID_UARTPRESENT_SHIFT     (4U)
/*! UARTPRESENT - UART Present
 *  0b0..Not supported
 *  0b1..Supported
 */
#define LP_FLEXCOMM_PSELID_UARTPRESENT(x)        (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_UARTPRESENT_SHIFT)) & LP_FLEXCOMM_PSELID_UARTPRESENT_MASK)

#define LP_FLEXCOMM_PSELID_SPIPRESENT_MASK       (0x20U)
#define LP_FLEXCOMM_PSELID_SPIPRESENT_SHIFT      (5U)
/*! SPIPRESENT - SPI Present
 *  0b0..Not supported
 *  0b1..Supported
 */
#define LP_FLEXCOMM_PSELID_SPIPRESENT(x)         (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_SPIPRESENT_SHIFT)) & LP_FLEXCOMM_PSELID_SPIPRESENT_MASK)

#define LP_FLEXCOMM_PSELID_I2CPRESENT_MASK       (0x40U)
#define LP_FLEXCOMM_PSELID_I2CPRESENT_SHIFT      (6U)
/*! I2CPRESENT - I2C Present
 *  0b0..Not supported
 *  0b1..Supported
 */
#define LP_FLEXCOMM_PSELID_I2CPRESENT(x)         (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_I2CPRESENT_SHIFT)) & LP_FLEXCOMM_PSELID_I2CPRESENT_MASK)

#define LP_FLEXCOMM_PSELID_ID_MASK               (0xFFFFF000U)
#define LP_FLEXCOMM_PSELID_ID_SHIFT              (12U)
/*! ID - LP_FLEXCOMM interface ID */
#define LP_FLEXCOMM_PSELID_ID(x)                 (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_ID_SHIFT)) & LP_FLEXCOMM_PSELID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LP_FLEXCOMM_Register_Masks */


/*!
 * @}
 */ /* end of group LP_FLEXCOMM_Peripheral_Access_Layer */


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


#endif  /* PERI_LP_FLEXCOMM_H_ */

