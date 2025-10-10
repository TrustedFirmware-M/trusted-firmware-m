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
**         CMSIS Peripheral Access Layer for PUF
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
 * @file PERI_PUF.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PUF
 *
 * CMSIS Peripheral Access Layer for PUF
 */

#if !defined(PERI_PUF_H_)
#define PERI_PUF_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PUF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PUF_Peripheral_Access_Layer PUF Peripheral Access Layer
 * @{
 */

/** PUF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  __I  uint32_t ORR;                               /**< Operation Result, offset: 0x4 */
  __IO uint32_t SR;                                /**< Status, offset: 0x8 */
  __I  uint32_t AR;                                /**< Allow, offset: 0xC */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x10 */
  __IO uint32_t IMR;                               /**< Interrupt Mask, offset: 0x14 */
  __IO uint32_t ISR;                               /**< Interrupt Status, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DATA_DEST;                         /**< Data Destination, offset: 0x20 */
  __IO uint32_t DATA_SRC;                          /**< Data Source, offset: 0x24 */
       uint8_t RESERVED_1[120];
  __O  uint32_t DIR;                               /**< Data Input, offset: 0xA0 */
       uint8_t RESERVED_2[4];
  __I  uint32_t DOR;                               /**< Data Output, offset: 0xA8 */
       uint8_t RESERVED_3[20];
  __IO uint32_t MISC;                              /**< Miscellaneous, offset: 0xC0 */
       uint8_t RESERVED_4[12];
  __IO uint32_t IF_SR;                             /**< Interface Status, offset: 0xD0 */
       uint8_t RESERVED_5[8];
  __I  uint32_t PSR;                               /**< PUF Score, offset: 0xDC */
  __I  uint32_t HW_RUC0;                           /**< Hardware Restrict User Context 0, offset: 0xE0 */
  __I  uint32_t HW_RUC1;                           /**< Hardware Restrict User Context 1, offset: 0xE4 */
       uint8_t RESERVED_6[12];
  __I  uint32_t HW_INFO;                           /**< Hardware Information, offset: 0xF4 */
  __I  uint32_t HW_ID;                             /**< Hardware Identifier, offset: 0xF8 */
  __I  uint32_t HW_VER;                            /**< Hardware Version, offset: 0xFC */
  __IO uint32_t CONFIG;                            /**< PUF command blocking configuration, offset: 0x100 */
  __IO uint32_t SEC_LOCK;                          /**< Security level lock, offset: 0x104 */
  __IO uint32_t APP_CTX_MASK;                      /**< Application defined context mask, offset: 0x108 */
       uint8_t RESERVED_7[500];
  __IO uint32_t SRAM_CFG;                          /**< SRAM Configuration, offset: 0x300 */
  __I  uint32_t SRAM_STATUS;                       /**< Status, offset: 0x304 */
       uint8_t RESERVED_8[208];
  __O  uint32_t SRAM_INT_CLR_ENABLE;               /**< Interrupt Enable Clear, offset: 0x3D8 */
  __O  uint32_t SRAM_INT_SET_ENABLE;               /**< Interrupt Enable Set, offset: 0x3DC */
  __I  uint32_t SRAM_INT_STATUS;                   /**< Interrupt Status, offset: 0x3E0 */
  __I  uint32_t SRAM_INT_ENABLE;                   /**< Interrupt Enable, offset: 0x3E4 */
  __O  uint32_t SRAM_INT_CLR_STATUS;               /**< Interrupt Status Clear, offset: 0x3E8 */
  __O  uint32_t SRAM_INT_SET_STATUS;               /**< Interrupt Status set, offset: 0x3EC */
} PUF_Type;

/* ----------------------------------------------------------------------------
   -- PUF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PUF_Register_Masks PUF Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define PUF_CR_ZEROIZE_MASK                      (0x1U)
#define PUF_CR_ZEROIZE_SHIFT                     (0U)
/*! ZEROIZE - Zeroize operation */
#define PUF_CR_ZEROIZE(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_CR_ZEROIZE_SHIFT)) & PUF_CR_ZEROIZE_MASK)

#define PUF_CR_ENROLL_MASK                       (0x2U)
#define PUF_CR_ENROLL_SHIFT                      (1U)
/*! ENROLL - Enroll operation */
#define PUF_CR_ENROLL(x)                         (((uint32_t)(((uint32_t)(x)) << PUF_CR_ENROLL_SHIFT)) & PUF_CR_ENROLL_MASK)

#define PUF_CR_START_MASK                        (0x4U)
#define PUF_CR_START_SHIFT                       (2U)
/*! START - Start operation */
#define PUF_CR_START(x)                          (((uint32_t)(((uint32_t)(x)) << PUF_CR_START_SHIFT)) & PUF_CR_START_MASK)

#define PUF_CR_RECONSTRUCT_MASK                  (0x8U)
#define PUF_CR_RECONSTRUCT_SHIFT                 (3U)
/*! RECONSTRUCT - Reconstruct operation */
#define PUF_CR_RECONSTRUCT(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_CR_RECONSTRUCT_SHIFT)) & PUF_CR_RECONSTRUCT_MASK)

#define PUF_CR_STOP_MASK                         (0x20U)
#define PUF_CR_STOP_SHIFT                        (5U)
/*! STOP - Stop operation */
#define PUF_CR_STOP(x)                           (((uint32_t)(((uint32_t)(x)) << PUF_CR_STOP_SHIFT)) & PUF_CR_STOP_MASK)

#define PUF_CR_GET_KEY_MASK                      (0x40U)
#define PUF_CR_GET_KEY_SHIFT                     (6U)
/*! GET_KEY - Get Key operation */
#define PUF_CR_GET_KEY(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_CR_GET_KEY_SHIFT)) & PUF_CR_GET_KEY_MASK)

#define PUF_CR_UNWRAP_MASK                       (0x80U)
#define PUF_CR_UNWRAP_SHIFT                      (7U)
/*! UNWRAP - Unwrap operation */
#define PUF_CR_UNWRAP(x)                         (((uint32_t)(((uint32_t)(x)) << PUF_CR_UNWRAP_SHIFT)) & PUF_CR_UNWRAP_MASK)

#define PUF_CR_WRAP_GENERATED_RANDOM_MASK        (0x100U)
#define PUF_CR_WRAP_GENERATED_RANDOM_SHIFT       (8U)
/*! WRAP_GENERATED_RANDOM - Wrap Generated Random operation */
#define PUF_CR_WRAP_GENERATED_RANDOM(x)          (((uint32_t)(((uint32_t)(x)) << PUF_CR_WRAP_GENERATED_RANDOM_SHIFT)) & PUF_CR_WRAP_GENERATED_RANDOM_MASK)

#define PUF_CR_WRAP_MASK                         (0x200U)
#define PUF_CR_WRAP_SHIFT                        (9U)
/*! WRAP - Wrap operation */
#define PUF_CR_WRAP(x)                           (((uint32_t)(((uint32_t)(x)) << PUF_CR_WRAP_SHIFT)) & PUF_CR_WRAP_MASK)

#define PUF_CR_GENERATE_RANDOM_MASK              (0x8000U)
#define PUF_CR_GENERATE_RANDOM_SHIFT             (15U)
/*! GENERATE_RANDOM - Generate Random operation */
#define PUF_CR_GENERATE_RANDOM(x)                (((uint32_t)(((uint32_t)(x)) << PUF_CR_GENERATE_RANDOM_SHIFT)) & PUF_CR_GENERATE_RANDOM_MASK)

#define PUF_CR_TEST_MEMORY_MASK                  (0x40000000U)
#define PUF_CR_TEST_MEMORY_SHIFT                 (30U)
/*! TEST_MEMORY - Test memory operation */
#define PUF_CR_TEST_MEMORY(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_CR_TEST_MEMORY_SHIFT)) & PUF_CR_TEST_MEMORY_MASK)

#define PUF_CR_TEST_PUF_MASK                     (0x80000000U)
#define PUF_CR_TEST_PUF_SHIFT                    (31U)
/*! TEST_PUF - Test PUF operation */
#define PUF_CR_TEST_PUF(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CR_TEST_PUF_SHIFT)) & PUF_CR_TEST_PUF_MASK)
/*! @} */

/*! @name ORR - Operation Result */
/*! @{ */

#define PUF_ORR_RESULT_CODE_MASK                 (0xFFU)
#define PUF_ORR_RESULT_CODE_SHIFT                (0U)
/*! RESULT_CODE - Result code of last operation
 *  0b00000000..Indicates that the last operation was successful or operation is in progress.
 *  0b11110000..Indicates that the AC is not for the current product/version.
 *  0b11110001..Indicates that the AC in the second phase is not for the current product/version.
 *  0b11110010..Indicates that the AC is corrupted.
 *  0b11110011..Indicates that the AC in the second phase is corrupted.
 *  0b11110100..Indicates that the authentication of the provided AC failed.
 *  0b11110101..Indicates that the authentication of the provided AC failed in the second phase.
 *  0b11110110..Indicates that the SRAM PUF quality verification fails.
 *  0b11110111..Indicates that the incorrect or unsupported context is provided.
 *  0b11111000..Indicates that a data destination was set that is not allowed according to other settings and the current PUF state.
 *  0b11111111..Indicates that the PUF SRAM access has failed.
 */
#define PUF_ORR_RESULT_CODE(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_ORR_RESULT_CODE_SHIFT)) & PUF_ORR_RESULT_CODE_MASK)

#define PUF_ORR_LAST_OPERATION_MASK              (0xFF000000U)
#define PUF_ORR_LAST_OPERATION_SHIFT             (24U)
/*! LAST_OPERATION - Last operation type
 *  0b00000000..Indicates that the operation is in progress.
 *  0b00000001..Indicates that the last operation was Enroll.
 *  0b00000010..Indicates that the last operation was Start.
 *  0b00000011..Indicates that the last operation was Reconstruct
 *  0b00000101..Indicates that the last operation was Stop.
 *  0b00000110..Indicates that the last operation was Get Key.
 *  0b00000111..Indicates that the last operation was Unwrap.
 *  0b00001000..Indicates that the last operation was Wrap Generated Random.
 *  0b00001001..Indicates that the last operation was Wrap.
 *  0b00001111..Indicates that the last operation was Generate Random.
 *  0b00011110..Indicates that the last operation was Test Memory.
 *  0b00011111..Indicates that the last operation was Test PUF.
 *  0b00100000..Indicates that the last operation was Initialization.
 *  0b00101111..Indicates that the last operation was Zeroize.
 */
#define PUF_ORR_LAST_OPERATION(x)                (((uint32_t)(((uint32_t)(x)) << PUF_ORR_LAST_OPERATION_SHIFT)) & PUF_ORR_LAST_OPERATION_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define PUF_SR_BUSY_MASK                         (0x1U)
#define PUF_SR_BUSY_SHIFT                        (0U)
/*! BUSY - Operation in progress */
#define PUF_SR_BUSY(x)                           (((uint32_t)(((uint32_t)(x)) << PUF_SR_BUSY_SHIFT)) & PUF_SR_BUSY_MASK)

#define PUF_SR_OK_MASK                           (0x2U)
#define PUF_SR_OK_SHIFT                          (1U)
/*! OK - Last operation successful */
#define PUF_SR_OK(x)                             (((uint32_t)(((uint32_t)(x)) << PUF_SR_OK_SHIFT)) & PUF_SR_OK_MASK)

#define PUF_SR_ERROR_MASK                        (0x4U)
#define PUF_SR_ERROR_SHIFT                       (2U)
/*! ERROR - Last operation failed */
#define PUF_SR_ERROR(x)                          (((uint32_t)(((uint32_t)(x)) << PUF_SR_ERROR_SHIFT)) & PUF_SR_ERROR_MASK)

#define PUF_SR_ZEROIZED_MASK                     (0x8U)
#define PUF_SR_ZEROIZED_SHIFT                    (3U)
/*! ZEROIZED - Zeroized or Locked state */
#define PUF_SR_ZEROIZED(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_SR_ZEROIZED_SHIFT)) & PUF_SR_ZEROIZED_MASK)

#define PUF_SR_REJECTED_MASK                     (0x10U)
#define PUF_SR_REJECTED_SHIFT                    (4U)
/*! REJECTED - Operation rejected */
#define PUF_SR_REJECTED(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_SR_REJECTED_SHIFT)) & PUF_SR_REJECTED_MASK)

#define PUF_SR_DI_REQUEST_MASK                   (0x20U)
#define PUF_SR_DI_REQUEST_SHIFT                  (5U)
/*! DI_REQUEST - Indicates the request for data in transfer via the DIR register */
#define PUF_SR_DI_REQUEST(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_SR_DI_REQUEST_SHIFT)) & PUF_SR_DI_REQUEST_MASK)

#define PUF_SR_DO_REQUEST_MASK                   (0x40U)
#define PUF_SR_DO_REQUEST_SHIFT                  (6U)
/*! DO_REQUEST - Indicates the request for data out transfer via the DOR register */
#define PUF_SR_DO_REQUEST(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_SR_DO_REQUEST_SHIFT)) & PUF_SR_DO_REQUEST_MASK)
/*! @} */

/*! @name AR - Allow */
/*! @{ */

#define PUF_AR_ALLOW_ENROLL_MASK                 (0x2U)
#define PUF_AR_ALLOW_ENROLL_SHIFT                (1U)
/*! ALLOW_ENROLL - Enroll operation
 *  0b0..Indicates that the Enroll operation is not allowed
 *  0b1..Indicates that the Enroll operation is allowed
 */
#define PUF_AR_ALLOW_ENROLL(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_ENROLL_SHIFT)) & PUF_AR_ALLOW_ENROLL_MASK)

#define PUF_AR_ALLOW_START_MASK                  (0x4U)
#define PUF_AR_ALLOW_START_SHIFT                 (2U)
/*! ALLOW_START - Start operation
 *  0b0..Indicates that the Start operation is not allowed
 *  0b1..Indicates that the Start operation is allowed
 */
#define PUF_AR_ALLOW_START(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_START_SHIFT)) & PUF_AR_ALLOW_START_MASK)

#define PUF_AR_ALLOW_RECONSTRUCT_MASK            (0x8U)
#define PUF_AR_ALLOW_RECONSTRUCT_SHIFT           (3U)
/*! ALLOW_RECONSTRUCT - Reconstruct operation
 *  0b0..Indicates that the Reconstruct operation is not allowed
 *  0b1..Indicates that the Reconstruct operation is allowed
 */
#define PUF_AR_ALLOW_RECONSTRUCT(x)              (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_RECONSTRUCT_SHIFT)) & PUF_AR_ALLOW_RECONSTRUCT_MASK)

#define PUF_AR_ALLOW_STOP_MASK                   (0x20U)
#define PUF_AR_ALLOW_STOP_SHIFT                  (5U)
/*! ALLOW_STOP - Stop operation
 *  0b0..Indicates that the Stop operation is not allowed
 *  0b1..Indicates that the Stop operation is allowed
 */
#define PUF_AR_ALLOW_STOP(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_STOP_SHIFT)) & PUF_AR_ALLOW_STOP_MASK)

#define PUF_AR_ALLOW_GET_KEY_MASK                (0x40U)
#define PUF_AR_ALLOW_GET_KEY_SHIFT               (6U)
/*! ALLOW_GET_KEY - Get Key operation
 *  0b0..Indicates that the Get Key operation is not allowed
 *  0b1..Indicates that the Get Key operation is allowed
 */
#define PUF_AR_ALLOW_GET_KEY(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_GET_KEY_SHIFT)) & PUF_AR_ALLOW_GET_KEY_MASK)

#define PUF_AR_ALLOW_UNWRAP_MASK                 (0x80U)
#define PUF_AR_ALLOW_UNWRAP_SHIFT                (7U)
/*! ALLOW_UNWRAP - Unwrap operation
 *  0b0..Indicates that the Unwrap operation is not allowed
 *  0b1..Indicates that the Unwrap operation is allowed
 */
#define PUF_AR_ALLOW_UNWRAP(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_UNWRAP_SHIFT)) & PUF_AR_ALLOW_UNWRAP_MASK)

#define PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_MASK  (0x100U)
#define PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_SHIFT (8U)
/*! ALLOW_WRAP_GENERATED_RANDOM - Wrap Generated Random operation
 *  0b0..Indicates that the Wrap Generated Random operation is not allowed
 *  0b1..Indicates that the Wrap Generated Random operation is allowed
 */
#define PUF_AR_ALLOW_WRAP_GENERATED_RANDOM(x)    (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_SHIFT)) & PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_MASK)

#define PUF_AR_ALLOW_WRAP_MASK                   (0x200U)
#define PUF_AR_ALLOW_WRAP_SHIFT                  (9U)
/*! ALLOW_WRAP - Wrap operation
 *  0b0..Indicates that the Wrap operation is not allowed
 *  0b1..Indicates that the Wrap operation is allowed
 */
#define PUF_AR_ALLOW_WRAP(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_WRAP_SHIFT)) & PUF_AR_ALLOW_WRAP_MASK)

#define PUF_AR_ALLOW_GENERATE_RANDOM_MASK        (0x8000U)
#define PUF_AR_ALLOW_GENERATE_RANDOM_SHIFT       (15U)
/*! ALLOW_GENERATE_RANDOM - Generate Random operation
 *  0b0..Indicates that the Generate Random operation is not allowed
 *  0b1..Indicates that the Generate Random operation is allowed
 */
#define PUF_AR_ALLOW_GENERATE_RANDOM(x)          (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_GENERATE_RANDOM_SHIFT)) & PUF_AR_ALLOW_GENERATE_RANDOM_MASK)

#define PUF_AR_ALLOW_TEST_MEMORY_MASK            (0x40000000U)
#define PUF_AR_ALLOW_TEST_MEMORY_SHIFT           (30U)
/*! ALLOW_TEST_MEMORY
 *  0b0..Indicates that the Test Memory operation is not allowed
 *  0b1..Indicates that the Test Memory operation is allowed
 */
#define PUF_AR_ALLOW_TEST_MEMORY(x)              (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_TEST_MEMORY_SHIFT)) & PUF_AR_ALLOW_TEST_MEMORY_MASK)

#define PUF_AR_ALLOW_TEST_PUF_MASK               (0x80000000U)
#define PUF_AR_ALLOW_TEST_PUF_SHIFT              (31U)
/*! ALLOW_TEST_PUF - Test PUF operation
 *  0b0..Test PUF operation is not allowed
 *  0b1..Test PUF operation is allowed
 */
#define PUF_AR_ALLOW_TEST_PUF(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_TEST_PUF_SHIFT)) & PUF_AR_ALLOW_TEST_PUF_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define PUF_IER_INT_EN_MASK                      (0x1U)
#define PUF_IER_INT_EN_SHIFT                     (0U)
/*! INT_EN - Interrupt enable
 *  0b0..Disables all PUF interrupts
 *  0b1..Enables all PUF interrupts that are enabled in the Interrupt Mask register
 */
#define PUF_IER_INT_EN(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_IER_INT_EN_SHIFT)) & PUF_IER_INT_EN_MASK)
/*! @} */

/*! @name IMR - Interrupt Mask */
/*! @{ */

#define PUF_IMR_INT_EN_BUSY_MASK                 (0x1U)
#define PUF_IMR_INT_EN_BUSY_SHIFT                (0U)
/*! INT_EN_BUSY - Busy interrupt */
#define PUF_IMR_INT_EN_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_BUSY_SHIFT)) & PUF_IMR_INT_EN_BUSY_MASK)

#define PUF_IMR_INT_EN_OK_MASK                   (0x2U)
#define PUF_IMR_INT_EN_OK_SHIFT                  (1U)
/*! INT_EN_OK - Ok interrupt */
#define PUF_IMR_INT_EN_OK(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_OK_SHIFT)) & PUF_IMR_INT_EN_OK_MASK)

#define PUF_IMR_INT_EN_ERROR_MASK                (0x4U)
#define PUF_IMR_INT_EN_ERROR_SHIFT               (2U)
/*! INT_EN_ERROR - Error interrupt */
#define PUF_IMR_INT_EN_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_ERROR_SHIFT)) & PUF_IMR_INT_EN_ERROR_MASK)

#define PUF_IMR_INT_EN_ZEROIZED_MASK             (0x8U)
#define PUF_IMR_INT_EN_ZEROIZED_SHIFT            (3U)
/*! INT_EN_ZEROIZED - Zeroized interrupt */
#define PUF_IMR_INT_EN_ZEROIZED(x)               (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_ZEROIZED_SHIFT)) & PUF_IMR_INT_EN_ZEROIZED_MASK)

#define PUF_IMR_INT_EN_REJECTED_MASK             (0x10U)
#define PUF_IMR_INT_EN_REJECTED_SHIFT            (4U)
/*! INT_EN_REJECTED - Rejected interrupt */
#define PUF_IMR_INT_EN_REJECTED(x)               (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_REJECTED_SHIFT)) & PUF_IMR_INT_EN_REJECTED_MASK)

#define PUF_IMR_INT_EN_DI_REQUEST_MASK           (0x20U)
#define PUF_IMR_INT_EN_DI_REQUEST_SHIFT          (5U)
/*! INT_EN_DI_REQUEST - Data in request interrupt */
#define PUF_IMR_INT_EN_DI_REQUEST(x)             (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_DI_REQUEST_SHIFT)) & PUF_IMR_INT_EN_DI_REQUEST_MASK)

#define PUF_IMR_INT_EN_DO_REQUEST_MASK           (0x40U)
#define PUF_IMR_INT_EN_DO_REQUEST_SHIFT          (6U)
/*! INT_EN_DO_REQUEST - Data out request interrupt */
#define PUF_IMR_INT_EN_DO_REQUEST(x)             (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_DO_REQUEST_SHIFT)) & PUF_IMR_INT_EN_DO_REQUEST_MASK)
/*! @} */

/*! @name ISR - Interrupt Status */
/*! @{ */

#define PUF_ISR_INT_BUSY_MASK                    (0x1U)
#define PUF_ISR_INT_BUSY_SHIFT                   (0U)
/*! INT_BUSY - Negative edge occurred on Busy */
#define PUF_ISR_INT_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_BUSY_SHIFT)) & PUF_ISR_INT_BUSY_MASK)

#define PUF_ISR_INT_OK_MASK                      (0x2U)
#define PUF_ISR_INT_OK_SHIFT                     (1U)
/*! INT_OK - Positive edge occurred on Ok */
#define PUF_ISR_INT_OK(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_OK_SHIFT)) & PUF_ISR_INT_OK_MASK)

#define PUF_ISR_INT_ERROR_MASK                   (0x4U)
#define PUF_ISR_INT_ERROR_SHIFT                  (2U)
/*! INT_ERROR - Positive edge occurred on Error */
#define PUF_ISR_INT_ERROR(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_ERROR_SHIFT)) & PUF_ISR_INT_ERROR_MASK)

#define PUF_ISR_INT_ZEROIZED_MASK                (0x8U)
#define PUF_ISR_INT_ZEROIZED_SHIFT               (3U)
/*! INT_ZEROIZED - Positive edge occurred on Zeroized */
#define PUF_ISR_INT_ZEROIZED(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_ZEROIZED_SHIFT)) & PUF_ISR_INT_ZEROIZED_MASK)

#define PUF_ISR_INT_REJECTED_MASK                (0x10U)
#define PUF_ISR_INT_REJECTED_SHIFT               (4U)
/*! INT_REJECTED - Positive edge occurred on Rejected */
#define PUF_ISR_INT_REJECTED(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_REJECTED_SHIFT)) & PUF_ISR_INT_REJECTED_MASK)

#define PUF_ISR_INT_DI_REQUEST_MASK              (0x20U)
#define PUF_ISR_INT_DI_REQUEST_SHIFT             (5U)
/*! INT_DI_REQUEST - Positive edge occurred on di_request */
#define PUF_ISR_INT_DI_REQUEST(x)                (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_DI_REQUEST_SHIFT)) & PUF_ISR_INT_DI_REQUEST_MASK)

#define PUF_ISR_INT_DO_REQUEST_MASK              (0x40U)
#define PUF_ISR_INT_DO_REQUEST_SHIFT             (6U)
/*! INT_DO_REQUEST - Positive edge occurred on do_request */
#define PUF_ISR_INT_DO_REQUEST(x)                (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_DO_REQUEST_SHIFT)) & PUF_ISR_INT_DO_REQUEST_MASK)
/*! @} */

/*! @name DATA_DEST - Data Destination */
/*! @{ */

#define PUF_DATA_DEST_DEST_DOR_MASK              (0x1U)
#define PUF_DATA_DEST_DEST_DOR_SHIFT             (0U)
/*! DEST_DOR - Key available via the DOR register */
#define PUF_DATA_DEST_DEST_DOR(x)                (((uint32_t)(((uint32_t)(x)) << PUF_DATA_DEST_DEST_DOR_SHIFT)) & PUF_DATA_DEST_DEST_DOR_MASK)

#define PUF_DATA_DEST_DEST_SO_MASK               (0x2U)
#define PUF_DATA_DEST_DEST_SO_SHIFT              (1U)
/*! DEST_SO - Key available to ELS */
#define PUF_DATA_DEST_DEST_SO(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_DATA_DEST_DEST_SO_SHIFT)) & PUF_DATA_DEST_DEST_SO_MASK)
/*! @} */

/*! @name DATA_SRC - Data Source */
/*! @{ */

#define PUF_DATA_SRC_SRC_DIR_MASK                (0x1U)
#define PUF_DATA_SRC_SRC_DIR_SHIFT               (0U)
/*! SRC_DIR - Data provided via the DIR register */
#define PUF_DATA_SRC_SRC_DIR(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_DATA_SRC_SRC_DIR_SHIFT)) & PUF_DATA_SRC_SRC_DIR_MASK)

#define PUF_DATA_SRC_SRC_SI_MASK                 (0x2U)
#define PUF_DATA_SRC_SRC_SI_SHIFT                (1U)
/*! SRC_SI - Data provided via the SI interface */
#define PUF_DATA_SRC_SRC_SI(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_DATA_SRC_SRC_SI_SHIFT)) & PUF_DATA_SRC_SRC_SI_MASK)
/*! @} */

/*! @name DIR - Data Input */
/*! @{ */

#define PUF_DIR_DI_MASK                          (0xFFFFFFFFU)
#define PUF_DIR_DI_SHIFT                         (0U)
/*! DI - Input data */
#define PUF_DIR_DI(x)                            (((uint32_t)(((uint32_t)(x)) << PUF_DIR_DI_SHIFT)) & PUF_DIR_DI_MASK)
/*! @} */

/*! @name DOR - Data Output */
/*! @{ */

#define PUF_DOR_DO_MASK                          (0xFFFFFFFFU)
#define PUF_DOR_DO_SHIFT                         (0U)
/*! DO - Output data */
#define PUF_DOR_DO(x)                            (((uint32_t)(((uint32_t)(x)) << PUF_DOR_DO_SHIFT)) & PUF_DOR_DO_MASK)
/*! @} */

/*! @name MISC - Miscellaneous */
/*! @{ */

#define PUF_MISC_DATA_ENDIANNESS_MASK            (0x1U)
#define PUF_MISC_DATA_ENDIANNESS_SHIFT           (0U)
/*! DATA_ENDIANNESS - Defines the endianness of data in DIR and DOR:
 *  0b0..Little endian
 *  0b1..Big endian (default)
 */
#define PUF_MISC_DATA_ENDIANNESS(x)              (((uint32_t)(((uint32_t)(x)) << PUF_MISC_DATA_ENDIANNESS_SHIFT)) & PUF_MISC_DATA_ENDIANNESS_MASK)
/*! @} */

/*! @name IF_SR - Interface Status */
/*! @{ */

#define PUF_IF_SR_APB_ERROR_MASK                 (0x1U)
#define PUF_IF_SR_APB_ERROR_SHIFT                (0U)
/*! APB_ERROR - APB error */
#define PUF_IF_SR_APB_ERROR(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_IF_SR_APB_ERROR_SHIFT)) & PUF_IF_SR_APB_ERROR_MASK)
/*! @} */

/*! @name PSR - PUF Score */
/*! @{ */

#define PUF_PSR_PUF_SCORE_MASK                   (0xFU)
#define PUF_PSR_PUF_SCORE_SHIFT                  (0U)
/*! PUF_SCORE - Provides the PUF score obtained during the last Test PUF, Enroll or Start operation. */
#define PUF_PSR_PUF_SCORE(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_PSR_PUF_SCORE_SHIFT)) & PUF_PSR_PUF_SCORE_MASK)
/*! @} */

/*! @name HW_RUC0 - Hardware Restrict User Context 0 */
/*! @{ */

#define PUF_HW_RUC0_LC_STATE_MASK                (0xFFU)
#define PUF_HW_RUC0_LC_STATE_SHIFT               (0U)
/*! LC_STATE - Life cycle state based restrictions
 *  0b00000011..OEM Develop
 *  0b00000111..OEM Develop 2
 *  0b00001111..OEM In-field
 *  0b00011111..OEM Field return
 *  0b00111111..NXP Field Return/Failure Analysis
 *  0b11001111..In-field Locked
 *  0b11111111..Bricked
 */
#define PUF_HW_RUC0_LC_STATE(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_LC_STATE_SHIFT)) & PUF_HW_RUC0_LC_STATE_MASK)

#define PUF_HW_RUC0_BOOT_STATE_MASK              (0xFFFF00U)
#define PUF_HW_RUC0_BOOT_STATE_SHIFT             (8U)
/*! BOOT_STATE - Temporal boot state */
#define PUF_HW_RUC0_BOOT_STATE(x)                (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_BOOT_STATE_SHIFT)) & PUF_HW_RUC0_BOOT_STATE_MASK)

#define PUF_HW_RUC0_CPU0_DEBUG_MASK              (0x1000000U)
#define PUF_HW_RUC0_CPU0_DEBUG_SHIFT             (24U)
/*! CPU0_DEBUG - Disable key access when debugger is attached to CPU0 after power-up */
#define PUF_HW_RUC0_CPU0_DEBUG(x)                (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_CPU0_DEBUG_SHIFT)) & PUF_HW_RUC0_CPU0_DEBUG_MASK)

#define PUF_HW_RUC0_COOLFLUX_DEBUG_MASK          (0x2000000U)
#define PUF_HW_RUC0_COOLFLUX_DEBUG_SHIFT         (25U)
/*! COOLFLUX_DEBUG - Disable key access when debugger is attached to COOLFLUX after power-up */
#define PUF_HW_RUC0_COOLFLUX_DEBUG(x)            (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_COOLFLUX_DEBUG_SHIFT)) & PUF_HW_RUC0_COOLFLUX_DEBUG_MASK)

#define PUF_HW_RUC0_dsp_debug_MASK               (0x4000000U)
#define PUF_HW_RUC0_dsp_debug_SHIFT              (26U)
/*! dsp_debug - DSP debug status. */
#define PUF_HW_RUC0_dsp_debug(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_dsp_debug_SHIFT)) & PUF_HW_RUC0_dsp_debug_MASK)

#define PUF_HW_RUC0_ACCESS_LEVEL_MASK            (0xF0000000U)
#define PUF_HW_RUC0_ACCESS_LEVEL_SHIFT           (28U)
/*! ACCESS_LEVEL - Restrict the key access based on TrustZone security level */
#define PUF_HW_RUC0_ACCESS_LEVEL(x)              (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_ACCESS_LEVEL_SHIFT)) & PUF_HW_RUC0_ACCESS_LEVEL_MASK)
/*! @} */

/*! @name HW_RUC1 - Hardware Restrict User Context 1 */
/*! @{ */

#define PUF_HW_RUC1_APP_CTX_MASK                 (0xFFFFFFFFU)
#define PUF_HW_RUC1_APP_CTX_SHIFT                (0U)
/*! APP_CTX - Application customizable context */
#define PUF_HW_RUC1_APP_CTX(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC1_APP_CTX_SHIFT)) & PUF_HW_RUC1_APP_CTX_MASK)
/*! @} */

/*! @name HW_INFO - Hardware Information */
/*! @{ */

#define PUF_HW_INFO_CONFIG_WRAP_MASK             (0x1000000U)
#define PUF_HW_INFO_CONFIG_WRAP_SHIFT            (24U)
/*! CONFIG_WRAP - Wrap configuration
 *  0b0..Indicates that Wrap is not included
 *  0b1..Indicates that Wrap is included
 */
#define PUF_HW_INFO_CONFIG_WRAP(x)               (((uint32_t)(((uint32_t)(x)) << PUF_HW_INFO_CONFIG_WRAP_SHIFT)) & PUF_HW_INFO_CONFIG_WRAP_MASK)

#define PUF_HW_INFO_CONFIG_TYPE_MASK             (0xF0000000U)
#define PUF_HW_INFO_CONFIG_TYPE_SHIFT            (28U)
/*! CONFIG_TYPE - PUF configuration
 *  0b0001..Indicates that PUF configuration is Safe.
 *  0b0010..Indicates that PUF configuration is Plus.
 */
#define PUF_HW_INFO_CONFIG_TYPE(x)               (((uint32_t)(((uint32_t)(x)) << PUF_HW_INFO_CONFIG_TYPE_SHIFT)) & PUF_HW_INFO_CONFIG_TYPE_MASK)
/*! @} */

/*! @name HW_ID - Hardware Identifier */
/*! @{ */

#define PUF_HW_ID_HW_ID_MASK                     (0xFFFFFFFFU)
#define PUF_HW_ID_HW_ID_SHIFT                    (0U)
/*! HW_ID - Provides the hardware identifier */
#define PUF_HW_ID_HW_ID(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_HW_ID_HW_ID_SHIFT)) & PUF_HW_ID_HW_ID_MASK)
/*! @} */

/*! @name HW_VER - Hardware Version */
/*! @{ */

#define PUF_HW_VER_HW_REV_MASK                   (0xFFU)
#define PUF_HW_VER_HW_REV_SHIFT                  (0U)
/*! HW_REV - Provides the hardware version, patch part */
#define PUF_HW_VER_HW_REV(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_HW_VER_HW_REV_SHIFT)) & PUF_HW_VER_HW_REV_MASK)

#define PUF_HW_VER_HW_VERSION_MINOR_MASK         (0xFF00U)
#define PUF_HW_VER_HW_VERSION_MINOR_SHIFT        (8U)
/*! HW_VERSION_MINOR - Provides the hardware version, minor part */
#define PUF_HW_VER_HW_VERSION_MINOR(x)           (((uint32_t)(((uint32_t)(x)) << PUF_HW_VER_HW_VERSION_MINOR_SHIFT)) & PUF_HW_VER_HW_VERSION_MINOR_MASK)

#define PUF_HW_VER_HW_VERSION_MAJOR_MASK         (0xFF0000U)
#define PUF_HW_VER_HW_VERSION_MAJOR_SHIFT        (16U)
/*! HW_VERSION_MAJOR - Provides the hardware version, major part */
#define PUF_HW_VER_HW_VERSION_MAJOR(x)           (((uint32_t)(((uint32_t)(x)) << PUF_HW_VER_HW_VERSION_MAJOR_SHIFT)) & PUF_HW_VER_HW_VERSION_MAJOR_MASK)
/*! @} */

/*! @name CONFIG - PUF command blocking configuration */
/*! @{ */

#define PUF_CONFIG_DIS_PUF_ENROLL_MASK           (0x2U)
#define PUF_CONFIG_DIS_PUF_ENROLL_SHIFT          (1U)
/*! DIS_PUF_ENROLL - Disable PUF enroll command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_ENROLL(x)             (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_ENROLL_SHIFT)) & PUF_CONFIG_DIS_PUF_ENROLL_MASK)

#define PUF_CONFIG_DIS_PUF_START_MASK            (0x4U)
#define PUF_CONFIG_DIS_PUF_START_SHIFT           (2U)
/*! DIS_PUF_START - Disable PUF start command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_START(x)              (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_START_SHIFT)) & PUF_CONFIG_DIS_PUF_START_MASK)

#define PUF_CONFIG_DIS_PUF_STOP_MASK             (0x20U)
#define PUF_CONFIG_DIS_PUF_STOP_SHIFT            (5U)
/*! DIS_PUF_STOP - Disable PUF stop command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_STOP(x)               (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_STOP_SHIFT)) & PUF_CONFIG_DIS_PUF_STOP_MASK)

#define PUF_CONFIG_DIS_PUF_GET_KEY_MASK          (0x40U)
#define PUF_CONFIG_DIS_PUF_GET_KEY_SHIFT         (6U)
/*! DIS_PUF_GET_KEY - Disable PUF get key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_GET_KEY(x)            (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_GET_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_GET_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_UNWRAP_KEY_MASK       (0x80U)
#define PUF_CONFIG_DIS_PUF_UNWRAP_KEY_SHIFT      (7U)
/*! DIS_PUF_UNWRAP_KEY - Disable PUF unwrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_UNWRAP_KEY(x)         (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_UNWRAP_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_UNWRAP_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_MASK     (0x100U)
#define PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_SHIFT    (8U)
/*! DIS_PUF_GEN_WRAP_KEY - Disable PUF generate and wrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY(x)       (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_WRAP_KEY_MASK         (0x200U)
#define PUF_CONFIG_DIS_PUF_WRAP_KEY_SHIFT        (9U)
/*! DIS_PUF_WRAP_KEY - Disable PUF wrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_WRAP_KEY(x)           (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_WRAP_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_WRAP_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_MASK (0x8000U)
#define PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_SHIFT (15U)
/*! DIS_PUF_GEN_RANDOM_NUMBER - Disable PUF generate and wrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER(x)  (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_SHIFT)) & PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_MASK)

#define PUF_CONFIG_DIS_PUF_TEST_MASK             (0x80000000U)
#define PUF_CONFIG_DIS_PUF_TEST_SHIFT            (31U)
/*! DIS_PUF_TEST - Disable PUF test command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_TEST(x)               (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_TEST_SHIFT)) & PUF_CONFIG_DIS_PUF_TEST_MASK)
/*! @} */

/*! @name SEC_LOCK - Security level lock */
/*! @{ */

#define PUF_SEC_LOCK_SEC_LEVEL_MASK              (0x3U)
#define PUF_SEC_LOCK_SEC_LEVEL_SHIFT             (0U)
/*! SEC_LEVEL - Security Level
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define PUF_SEC_LOCK_SEC_LEVEL(x)                (((uint32_t)(((uint32_t)(x)) << PUF_SEC_LOCK_SEC_LEVEL_SHIFT)) & PUF_SEC_LOCK_SEC_LEVEL_MASK)

#define PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_MASK    (0xCU)
#define PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_SHIFT   (2U)
/*! ANTI_POLE_SEC_LEVEL - Anti-pole of security level
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL(x)      (((uint32_t)(((uint32_t)(x)) << PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_SHIFT)) & PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_MASK)

#define PUF_SEC_LOCK_PATTERN_MASK                (0xFFF0U)
#define PUF_SEC_LOCK_PATTERN_SHIFT               (4U)
/*! PATTERN - Pattern */
#define PUF_SEC_LOCK_PATTERN(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_SEC_LOCK_PATTERN_SHIFT)) & PUF_SEC_LOCK_PATTERN_MASK)
/*! @} */

/*! @name APP_CTX_MASK - Application defined context mask */
/*! @{ */

#define PUF_APP_CTX_MASK_APP_CTX_MASK_MASK       (0xFFFFFFFFU)
#define PUF_APP_CTX_MASK_APP_CTX_MASK_SHIFT      (0U)
/*! APP_CTX_MASK - Application defined context */
#define PUF_APP_CTX_MASK_APP_CTX_MASK(x)         (((uint32_t)(((uint32_t)(x)) << PUF_APP_CTX_MASK_APP_CTX_MASK_SHIFT)) & PUF_APP_CTX_MASK_APP_CTX_MASK_MASK)
/*! @} */

/*! @name SRAM_CFG - SRAM Configuration */
/*! @{ */

#define PUF_SRAM_CFG_ENABLE_MASK                 (0x1U)
#define PUF_SRAM_CFG_ENABLE_SHIFT                (0U)
/*! ENABLE - PUF SRAM Controller activation
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PUF_SRAM_CFG_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_CFG_ENABLE_SHIFT)) & PUF_SRAM_CFG_ENABLE_MASK)

#define PUF_SRAM_CFG_CKGATING_MASK               (0x4U)
#define PUF_SRAM_CFG_CKGATING_SHIFT              (2U)
/*! CKGATING - PUF SRAM Clock Gating control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PUF_SRAM_CFG_CKGATING(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_CFG_CKGATING_SHIFT)) & PUF_SRAM_CFG_CKGATING_MASK)
/*! @} */

/*! @name SRAM_STATUS - Status */
/*! @{ */

#define PUF_SRAM_STATUS_READY_MASK               (0x1U)
#define PUF_SRAM_STATUS_READY_SHIFT              (0U)
/*! READY - PUF SRAM Controller State */
#define PUF_SRAM_STATUS_READY(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_STATUS_READY_SHIFT)) & PUF_SRAM_STATUS_READY_MASK)
/*! @} */

/*! @name SRAM_INT_CLR_ENABLE - Interrupt Enable Clear */
/*! @{ */

#define PUF_SRAM_INT_CLR_ENABLE_READY_MASK       (0x1U)
#define PUF_SRAM_INT_CLR_ENABLE_READY_SHIFT      (0U)
/*! READY - READY Interrupt Enable clear */
#define PUF_SRAM_INT_CLR_ENABLE_READY(x)         (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_CLR_ENABLE_READY_SHIFT)) & PUF_SRAM_INT_CLR_ENABLE_READY_MASK)

#define PUF_SRAM_INT_CLR_ENABLE_APB_ERR_MASK     (0x2U)
#define PUF_SRAM_INT_CLR_ENABLE_APB_ERR_SHIFT    (1U)
/*! APB_ERR - APB_ERR Interrupt Enable clear */
#define PUF_SRAM_INT_CLR_ENABLE_APB_ERR(x)       (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_CLR_ENABLE_APB_ERR_SHIFT)) & PUF_SRAM_INT_CLR_ENABLE_APB_ERR_MASK)
/*! @} */

/*! @name SRAM_INT_SET_ENABLE - Interrupt Enable Set */
/*! @{ */

#define PUF_SRAM_INT_SET_ENABLE_READY_MASK       (0x1U)
#define PUF_SRAM_INT_SET_ENABLE_READY_SHIFT      (0U)
/*! READY - READY Interrupt Enable set */
#define PUF_SRAM_INT_SET_ENABLE_READY(x)         (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_SET_ENABLE_READY_SHIFT)) & PUF_SRAM_INT_SET_ENABLE_READY_MASK)

#define PUF_SRAM_INT_SET_ENABLE_APB_ERR_MASK     (0x2U)
#define PUF_SRAM_INT_SET_ENABLE_APB_ERR_SHIFT    (1U)
/*! APB_ERR - APB_ERR Interrupt Enable set */
#define PUF_SRAM_INT_SET_ENABLE_APB_ERR(x)       (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_SET_ENABLE_APB_ERR_SHIFT)) & PUF_SRAM_INT_SET_ENABLE_APB_ERR_MASK)
/*! @} */

/*! @name SRAM_INT_STATUS - Interrupt Status */
/*! @{ */

#define PUF_SRAM_INT_STATUS_READY_MASK           (0x1U)
#define PUF_SRAM_INT_STATUS_READY_SHIFT          (0U)
/*! READY - READY Interrupt Status */
#define PUF_SRAM_INT_STATUS_READY(x)             (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_STATUS_READY_SHIFT)) & PUF_SRAM_INT_STATUS_READY_MASK)

#define PUF_SRAM_INT_STATUS_APB_ERR_MASK         (0x2U)
#define PUF_SRAM_INT_STATUS_APB_ERR_SHIFT        (1U)
/*! APB_ERR - APB_ERR Interrupt Status */
#define PUF_SRAM_INT_STATUS_APB_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_STATUS_APB_ERR_SHIFT)) & PUF_SRAM_INT_STATUS_APB_ERR_MASK)
/*! @} */

/*! @name SRAM_INT_ENABLE - Interrupt Enable */
/*! @{ */

#define PUF_SRAM_INT_ENABLE_READY_MASK           (0x1U)
#define PUF_SRAM_INT_ENABLE_READY_SHIFT          (0U)
/*! READY - READY Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PUF_SRAM_INT_ENABLE_READY(x)             (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_ENABLE_READY_SHIFT)) & PUF_SRAM_INT_ENABLE_READY_MASK)

#define PUF_SRAM_INT_ENABLE_SRAM_APB_ERR_MASK    (0x2U)
#define PUF_SRAM_INT_ENABLE_SRAM_APB_ERR_SHIFT   (1U)
/*! SRAM_APB_ERR - APB_ERR Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PUF_SRAM_INT_ENABLE_SRAM_APB_ERR(x)      (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_ENABLE_SRAM_APB_ERR_SHIFT)) & PUF_SRAM_INT_ENABLE_SRAM_APB_ERR_MASK)
/*! @} */

/*! @name SRAM_INT_CLR_STATUS - Interrupt Status Clear */
/*! @{ */

#define PUF_SRAM_INT_CLR_STATUS_READY_MASK       (0x1U)
#define PUF_SRAM_INT_CLR_STATUS_READY_SHIFT      (0U)
/*! READY - READY Interrupt Status clear */
#define PUF_SRAM_INT_CLR_STATUS_READY(x)         (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_CLR_STATUS_READY_SHIFT)) & PUF_SRAM_INT_CLR_STATUS_READY_MASK)

#define PUF_SRAM_INT_CLR_STATUS_APB_ERR_MASK     (0x2U)
#define PUF_SRAM_INT_CLR_STATUS_APB_ERR_SHIFT    (1U)
/*! APB_ERR - APB_ERR Interrupt Status Clear
 *  0b0..No effect
 *  0b1..Clears the APB_ERR bit field in register INT_STATUS. Automatically reset by the Hardware
 */
#define PUF_SRAM_INT_CLR_STATUS_APB_ERR(x)       (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_CLR_STATUS_APB_ERR_SHIFT)) & PUF_SRAM_INT_CLR_STATUS_APB_ERR_MASK)
/*! @} */

/*! @name SRAM_INT_SET_STATUS - Interrupt Status set */
/*! @{ */

#define PUF_SRAM_INT_SET_STATUS_READY_MASK       (0x1U)
#define PUF_SRAM_INT_SET_STATUS_READY_SHIFT      (0U)
/*! READY - READY Interrupt Status set */
#define PUF_SRAM_INT_SET_STATUS_READY(x)         (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_SET_STATUS_READY_SHIFT)) & PUF_SRAM_INT_SET_STATUS_READY_MASK)

#define PUF_SRAM_INT_SET_STATUS_APB_ERR_MASK     (0x2U)
#define PUF_SRAM_INT_SET_STATUS_APB_ERR_SHIFT    (1U)
/*! APB_ERR - APB_ERR Interrupt Status Set
 *  0b0..No effect
 *  0b1..Clears the APB_ERR bit field in register INT_STATUS. Automatically reset by the Hardware
 */
#define PUF_SRAM_INT_SET_STATUS_APB_ERR(x)       (((uint32_t)(((uint32_t)(x)) << PUF_SRAM_INT_SET_STATUS_APB_ERR_SHIFT)) & PUF_SRAM_INT_SET_STATUS_APB_ERR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PUF_Register_Masks */


/*!
 * @}
 */ /* end of group PUF_Peripheral_Access_Layer */


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


#endif  /* PERI_PUF_H_ */

