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
**         CMSIS Peripheral Access Layer for FLASH_KEY_STORE
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
 * @file PERI_FLASH_KEY_STORE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH_KEY_STORE
 *
 * CMSIS Peripheral Access Layer for FLASH_KEY_STORE
 */

#if !defined(PERI_FLASH_KEY_STORE_H_)
#define PERI_FLASH_KEY_STORE_H_                  /**< Symbol preventing repeated inclusion */

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
   -- FLASH_KEY_STORE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_KEY_STORE_Peripheral_Access_Layer FLASH_KEY_STORE Peripheral Access Layer
 * @{
 */

/** FLASH_KEY_STORE - Size of Registers Arrays */
#define FLASH_KEY_STORE_ACTIVATION_CODE_COUNT     298u
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_CORE_SBKEY_BODY_COUNT 12u
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_CORE_USER_KEK_BODY_COUNT 12u
#define FLASH_KEY_STORE_UDS_KEY_CODE_UDS_KEY_CODE_UDS_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_UDS_KEY_CODE_UDS_KEY_CODE_CORE_UDS_BODY_COUNT 12u
#define FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_PRINCE_REGION0_KEY_CODE_PRINCE_REGION0_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_PRINCE_REGION0_KEY_CODE_CORE_PRINCE_REGION0_BODY_COUNT 12u
#define FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_PRINCE_REGION1_KEY_CODE_PRINCE_REGION1_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_PRINCE_REGION1_KEY_CODE_CORE_PRINCE_REGION1_BODY_COUNT 12u
#define FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_PRINCE_REGION2_KEY_CODE_PRINCE_REGION2_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_PRINCE_REGION2_KEY_CODE_CORE_PRINCE_REGION2_BODY_COUNT 12u

/** FLASH_KEY_STORE - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t HEADER;                            /**< Valid Key Sore Header : 0x95959595, offset: 0x0 */
    __IO uint32_t PUF_DISCHARGE_TIME_IN_MS;          /**< puf discharge time in ms., offset: 0x4 */
  } KEY_STORE_HEADER;
  __IO uint32_t ACTIVATION_CODE[FLASH_KEY_STORE_ACTIVATION_CODE_COUNT]; /**< ., array offset: 0x8, array step: 0x4 */
  union {                                          /* offset: 0x4B0 */
    __IO uint32_t SBKEY_KEY_CODE[FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_COUNT];   /**< ., array offset: 0x4B0, array step: 0x4 */
    struct {                                         /* offset: 0x4B0 */
      __IO uint32_t SBKEY_HEADER0;                     /**< ., offset: 0x4B0 */
      __IO uint32_t SBKEY_HEADER1;                     /**< ., offset: 0x4B4 */
      __IO uint32_t SBKEY_BODY[FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_CORE_SBKEY_BODY_COUNT];     /**< ., array offset: 0x4B8, array step: 0x4 */
    } SBKEY_KEY_CODE_CORE;
  };
  union {                                          /* offset: 0x4E8 */
    __IO uint32_t USER_KEK_KEY_CODE[FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_COUNT];   /**< ., array offset: 0x4E8, array step: 0x4 */
    struct {                                         /* offset: 0x4E8 */
      __IO uint32_t USER_KEK_HEADER0;                  /**< ., offset: 0x4E8 */
      __IO uint32_t USER_KEK_HEADER1;                  /**< ., offset: 0x4EC */
      __IO uint32_t USER_KEK_BODY[FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_CORE_USER_KEK_BODY_COUNT];     /**< ., array offset: 0x4F0, array step: 0x4 */
    } USER_KEK_KEY_CODE_CORE;
  };
  union {                                          /* offset: 0x520 */
    __IO uint32_t UDS_KEY_CODE[FLASH_KEY_STORE_UDS_KEY_CODE_UDS_KEY_CODE_UDS_KEY_CODE_COUNT];   /**< ., array offset: 0x520, array step: 0x4 */
    struct {                                         /* offset: 0x520 */
      __IO uint32_t UDS_HEADER0;                       /**< ., offset: 0x520 */
      __IO uint32_t UDS_HEADER1;                       /**< ., offset: 0x524 */
      __IO uint32_t UDS_BODY[FLASH_KEY_STORE_UDS_KEY_CODE_UDS_KEY_CODE_CORE_UDS_BODY_COUNT];     /**< ., array offset: 0x528, array step: 0x4 */
    } UDS_KEY_CODE_CORE;
  };
  union {                                          /* offset: 0x558 */
    __IO uint32_t PRINCE_REGION0_KEY_CODE[FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_PRINCE_REGION0_KEY_CODE_PRINCE_REGION0_KEY_CODE_COUNT];   /**< ., array offset: 0x558, array step: 0x4 */
    struct {                                         /* offset: 0x558 */
      __IO uint32_t PRINCE_REGION0_HEADER0;            /**< ., offset: 0x558 */
      __IO uint32_t PRINCE_REGION0_HEADER1;            /**< ., offset: 0x55C */
      __IO uint32_t PRINCE_REGION0_BODY[FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_PRINCE_REGION0_KEY_CODE_CORE_PRINCE_REGION0_BODY_COUNT];     /**< ., array offset: 0x560, array step: 0x4 */
    } PRINCE_REGION0_KEY_CODE_CORE;
  };
  union {                                          /* offset: 0x590 */
    __IO uint32_t PRINCE_REGION1_KEY_CODE[FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_PRINCE_REGION1_KEY_CODE_PRINCE_REGION1_KEY_CODE_COUNT];   /**< ., array offset: 0x590, array step: 0x4 */
    struct {                                         /* offset: 0x590 */
      __IO uint32_t PRINCE_REGION1_HEADER0;            /**< ., offset: 0x590 */
      __IO uint32_t PRINCE_REGION1_HEADER1;            /**< ., offset: 0x594 */
      __IO uint32_t PRINCE_REGION1_BODY[FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_PRINCE_REGION1_KEY_CODE_CORE_PRINCE_REGION1_BODY_COUNT];     /**< ., array offset: 0x598, array step: 0x4 */
    } PRINCE_REGION1_KEY_CODE_CORE;
  };
  union {                                          /* offset: 0x5C8 */
    __IO uint32_t PRINCE_REGION2_KEY_CODE[FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_PRINCE_REGION2_KEY_CODE_PRINCE_REGION2_KEY_CODE_COUNT];   /**< ., array offset: 0x5C8, array step: 0x4 */
    struct {                                         /* offset: 0x5C8 */
      __IO uint32_t PRINCE_REGION2_HEADER0;            /**< ., offset: 0x5C8 */
      __IO uint32_t PRINCE_REGION2_HEADER1;            /**< ., offset: 0x5CC */
      __IO uint32_t PRINCE_REGION2_BODY[FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_PRINCE_REGION2_KEY_CODE_CORE_PRINCE_REGION2_BODY_COUNT];     /**< ., array offset: 0x5D0, array step: 0x4 */
    } PRINCE_REGION2_KEY_CODE_CORE;
  };
} FLASH_KEY_STORE_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_KEY_STORE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_KEY_STORE_Register_Masks FLASH_KEY_STORE Register Masks
 * @{
 */

/*! @name HEADER - Valid Key Sore Header : 0x95959595 */
/*! @{ */

#define FLASH_KEY_STORE_HEADER_FIELD_MASK        (0xFFFFFFFFU)
#define FLASH_KEY_STORE_HEADER_FIELD_SHIFT       (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_HEADER_FIELD(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_HEADER_FIELD_SHIFT)) & FLASH_KEY_STORE_HEADER_FIELD_MASK)
/*! @} */

/*! @name PUF_DISCHARGE_TIME_IN_MS - puf discharge time in ms. */
/*! @{ */

#define FLASH_KEY_STORE_PUF_DISCHARGE_TIME_IN_MS_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PUF_DISCHARGE_TIME_IN_MS_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PUF_DISCHARGE_TIME_IN_MS_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PUF_DISCHARGE_TIME_IN_MS_FIELD_SHIFT)) & FLASH_KEY_STORE_PUF_DISCHARGE_TIME_IN_MS_FIELD_MASK)
/*! @} */

/*! @name ACTIVATION_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_ACTIVATION_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_ACTIVATION_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_ACTIVATION_CODE_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_ACTIVATION_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_ACTIVATION_CODE_FIELD_MASK)
/*! @} */

/*! @name SBKEY_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_SBKEY_KEY_CODE */
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_COUNT     (14U)

/*! @name SBKEY_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_SBKEY_HEADER0_FIELD(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_MASK)
/*! @} */

/*! @name SBKEY_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_MASK  (0x3U)
#define FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_SHIFT (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_SBKEY_HEADER1_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_MASK (0xF00U)
#define FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_SHIFT (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_SBKEY_HEADER1_INDEX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_MASK  (0x3F000000U)
#define FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_SHIFT (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_SBKEY_HEADER1_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_MASK)
/*! @} */

/*! @name SBKEY_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_BODY_FIELD_MASK    (0xFFFFFFFFU)
#define FLASH_KEY_STORE_SBKEY_BODY_FIELD_SHIFT   (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_SBKEY_BODY_FIELD(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_SBKEY_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_SBKEY_BODY */
#define FLASH_KEY_STORE_SBKEY_BODY_COUNT         (12U)

/*! @name USER_KEK_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_USER_KEK_KEY_CODE */
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_COUNT  (14U)

/*! @name USER_KEK_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_MASK)
/*! @} */

/*! @name USER_KEK_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_MASK (0x3U)
#define FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_SHIFT (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_MASK (0xF00U)
#define FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_SHIFT (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_MASK (0x3F000000U)
#define FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_SHIFT (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_MASK)
/*! @} */

/*! @name USER_KEK_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_BODY_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_USER_KEK_BODY_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_USER_KEK_BODY_FIELD(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_USER_KEK_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_USER_KEK_BODY */
#define FLASH_KEY_STORE_USER_KEK_BODY_COUNT      (12U)

/*! @name UDS_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_UDS_KEY_CODE_FIELD_MASK  (0xFFFFFFFFU)
#define FLASH_KEY_STORE_UDS_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_UDS_KEY_CODE_FIELD(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_UDS_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_UDS_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_UDS_KEY_CODE */
#define FLASH_KEY_STORE_UDS_KEY_CODE_COUNT       (14U)

/*! @name UDS_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_UDS_HEADER0_FIELD_MASK   (0xFFFFFFFFU)
#define FLASH_KEY_STORE_UDS_HEADER0_FIELD_SHIFT  (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_UDS_HEADER0_FIELD(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_UDS_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_UDS_HEADER0_FIELD_MASK)
/*! @} */

/*! @name UDS_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_UDS_HEADER1_TYPE_MASK    (0x3U)
#define FLASH_KEY_STORE_UDS_HEADER1_TYPE_SHIFT   (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_UDS_HEADER1_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_UDS_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_UDS_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_UDS_HEADER1_INDEX_MASK   (0xF00U)
#define FLASH_KEY_STORE_UDS_HEADER1_INDEX_SHIFT  (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_UDS_HEADER1_INDEX(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_UDS_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_UDS_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_UDS_HEADER1_SIZE_MASK    (0x3F000000U)
#define FLASH_KEY_STORE_UDS_HEADER1_SIZE_SHIFT   (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_UDS_HEADER1_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_UDS_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_UDS_HEADER1_SIZE_MASK)
/*! @} */

/*! @name UDS_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_UDS_BODY_FIELD_MASK      (0xFFFFFFFFU)
#define FLASH_KEY_STORE_UDS_BODY_FIELD_SHIFT     (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_UDS_BODY_FIELD(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_UDS_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_UDS_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_UDS_BODY */
#define FLASH_KEY_STORE_UDS_BODY_COUNT           (12U)

/*! @name PRINCE_REGION0_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE */
#define FLASH_KEY_STORE_PRINCE_REGION0_KEY_CODE_COUNT (14U)

/*! @name PRINCE_REGION0_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER0_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER0_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER0_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION0_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION0_HEADER0_FIELD_MASK)
/*! @} */

/*! @name PRINCE_REGION0_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_TYPE_MASK (0x3U)
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_TYPE_SHIFT (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_INDEX_MASK (0xF00U)
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_INDEX_SHIFT (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_INDEX(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_SIZE_MASK (0x3F000000U)
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_SIZE_SHIFT (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_SIZE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION0_HEADER1_SIZE_MASK)
/*! @} */

/*! @name PRINCE_REGION0_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION0_BODY_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION0_BODY_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION0_BODY_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION0_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION0_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_PRINCE_REGION0_BODY */
#define FLASH_KEY_STORE_PRINCE_REGION0_BODY_COUNT (12U)

/*! @name PRINCE_REGION1_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE */
#define FLASH_KEY_STORE_PRINCE_REGION1_KEY_CODE_COUNT (14U)

/*! @name PRINCE_REGION1_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER0_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER0_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER0_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION1_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION1_HEADER0_FIELD_MASK)
/*! @} */

/*! @name PRINCE_REGION1_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_TYPE_MASK (0x3U)
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_TYPE_SHIFT (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_INDEX_MASK (0xF00U)
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_INDEX_SHIFT (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_INDEX(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_SIZE_MASK (0x3F000000U)
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_SIZE_SHIFT (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_SIZE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION1_HEADER1_SIZE_MASK)
/*! @} */

/*! @name PRINCE_REGION1_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION1_BODY_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION1_BODY_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION1_BODY_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION1_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION1_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_PRINCE_REGION1_BODY */
#define FLASH_KEY_STORE_PRINCE_REGION1_BODY_COUNT (12U)

/*! @name PRINCE_REGION2_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE */
#define FLASH_KEY_STORE_PRINCE_REGION2_KEY_CODE_COUNT (14U)

/*! @name PRINCE_REGION2_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER0_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER0_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER0_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION2_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION2_HEADER0_FIELD_MASK)
/*! @} */

/*! @name PRINCE_REGION2_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_TYPE_MASK (0x3U)
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_TYPE_SHIFT (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_INDEX_MASK (0xF00U)
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_INDEX_SHIFT (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_INDEX(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_SIZE_MASK (0x3F000000U)
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_SIZE_SHIFT (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_SIZE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION2_HEADER1_SIZE_MASK)
/*! @} */

/*! @name PRINCE_REGION2_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_PRINCE_REGION2_BODY_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_PRINCE_REGION2_BODY_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_PRINCE_REGION2_BODY_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_PRINCE_REGION2_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_PRINCE_REGION2_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_PRINCE_REGION2_BODY */
#define FLASH_KEY_STORE_PRINCE_REGION2_BODY_COUNT (12U)


/*!
 * @}
 */ /* end of group FLASH_KEY_STORE_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_KEY_STORE_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_KEY_STORE_H_ */

