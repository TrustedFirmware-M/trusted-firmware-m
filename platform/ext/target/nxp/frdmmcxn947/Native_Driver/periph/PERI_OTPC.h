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
**         CMSIS Peripheral Access Layer for OTPC
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
 * @file PERI_OTPC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OTPC
 *
 * CMSIS Peripheral Access Layer for OTPC
 */

#if !defined(PERI_OTPC_H_)
#define PERI_OTPC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- OTPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OTPC_Peripheral_Access_Layer OTPC Peripheral Access Layer
 * @{
 */

/** OTPC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameters, offset: 0x4 */
  __IO uint32_t SR;                                /**< Status, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t RWC;                               /**< Read and Write Control, offset: 0x10 */
  __IO uint32_t RLC;                               /**< Reload Control, offset: 0x14 */
  __IO uint32_t PCR;                               /**< Power Control, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t WDATA;                             /**< Write Data, offset: 0x20 */
  __I  uint32_t RDATA;                             /**< Read Data, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t TIMING1;                           /**< Timing1, offset: 0x30 */
  __IO uint32_t TIMING2;                           /**< Timing2, offset: 0x34 */
       uint8_t RESERVED_3[456];
  __I  uint32_t LOCK;                              /**< Lock, offset: 0x200 */
  __I  uint32_t SECURE;                            /**< Secure, offset: 0x204 */
  __I  uint32_t SECURE_INV;                        /**< Inverted Secure, offset: 0x208 */
  __I  uint32_t DBG_KEY;                           /**< Debug and Key, offset: 0x20C */
  __IO uint32_t MISC_CFG;                          /**< MISC Config, offset: 0x210 */
  __IO uint32_t PHANTOM_CFG;                       /**< PHANTOM Config, offset: 0x214 */
  __IO uint32_t FLEX_CFG0;                         /**< Flexible Config 0, offset: 0x218 */
  __IO uint32_t FLEX_CFG1;                         /**< Flexible Config 1, offset: 0x21C */
} OTPC_Type;

/* ----------------------------------------------------------------------------
   -- OTPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OTPC_Register_Masks OTPC Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define OTPC_VERID_FEATURE_MASK                  (0xFFFFU)
#define OTPC_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard feature set
 */
#define OTPC_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << OTPC_VERID_FEATURE_SHIFT)) & OTPC_VERID_FEATURE_MASK)

#define OTPC_VERID_MINOR_MASK                    (0xFF0000U)
#define OTPC_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define OTPC_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_VERID_MINOR_SHIFT)) & OTPC_VERID_MINOR_MASK)

#define OTPC_VERID_MAJOR_MASK                    (0xFF000000U)
#define OTPC_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define OTPC_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_VERID_MAJOR_SHIFT)) & OTPC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameters */
/*! @{ */

#define OTPC_PARAM_NUM_FUSE_MASK                 (0xFFFFU)
#define OTPC_PARAM_NUM_FUSE_SHIFT                (0U)
/*! NUM_FUSE - Number of fuse bytes */
#define OTPC_PARAM_NUM_FUSE(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_PARAM_NUM_FUSE_SHIFT)) & OTPC_PARAM_NUM_FUSE_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define OTPC_SR_BUSY_MASK                        (0x1U)
#define OTPC_SR_BUSY_SHIFT                       (0U)
/*! BUSY - Busy status
 *  0b0..Not busy (transaction complete)
 *  0b1..Busy
 */
#define OTPC_SR_BUSY(x)                          (((uint32_t)(((uint32_t)(x)) << OTPC_SR_BUSY_SHIFT)) & OTPC_SR_BUSY_MASK)

#define OTPC_SR_ERROR_MASK                       (0x2U)
#define OTPC_SR_ERROR_SHIFT                      (1U)
/*! ERROR - Error flag
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_ERROR(x)                         (((uint32_t)(((uint32_t)(x)) << OTPC_SR_ERROR_SHIFT)) & OTPC_SR_ERROR_MASK)

#define OTPC_SR_ECC_SF_MASK                      (0x4U)
#define OTPC_SR_ECC_SF_SHIFT                     (2U)
/*! ECC_SF - ECC single fault
 *  0b0..No fault
 *  0b1..Fault
 */
#define OTPC_SR_ECC_SF(x)                        (((uint32_t)(((uint32_t)(x)) << OTPC_SR_ECC_SF_SHIFT)) & OTPC_SR_ECC_SF_MASK)

#define OTPC_SR_ECC_DF_MASK                      (0x8U)
#define OTPC_SR_ECC_DF_SHIFT                     (3U)
/*! ECC_DF - ECC double fault
 *  0b0..No fault
 *  0b1..Fault
 */
#define OTPC_SR_ECC_DF(x)                        (((uint32_t)(((uint32_t)(x)) << OTPC_SR_ECC_DF_SHIFT)) & OTPC_SR_ECC_DF_MASK)

#define OTPC_SR_TRI_F_MASK                       (0x10U)
#define OTPC_SR_TRI_F_SHIFT                      (4U)
/*! TRI_F - Triple voting fault
 *  0b0..No fault
 *  0b1..Fault
 */
#define OTPC_SR_TRI_F(x)                         (((uint32_t)(((uint32_t)(x)) << OTPC_SR_TRI_F_SHIFT)) & OTPC_SR_TRI_F_MASK)

#define OTPC_SR_RD_FUSE_LOCK_MASK                (0x100U)
#define OTPC_SR_RD_FUSE_LOCK_SHIFT               (8U)
/*! RD_FUSE_LOCK - Read fuse lock error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_RD_FUSE_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_SR_RD_FUSE_LOCK_SHIFT)) & OTPC_SR_RD_FUSE_LOCK_MASK)

#define OTPC_SR_WR_FUSE_LOCK_MASK                (0x200U)
#define OTPC_SR_WR_FUSE_LOCK_SHIFT               (9U)
/*! WR_FUSE_LOCK - Write fuse lock error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_WR_FUSE_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_SR_WR_FUSE_LOCK_SHIFT)) & OTPC_SR_WR_FUSE_LOCK_MASK)

#define OTPC_SR_RD_REG_LOCK_MASK                 (0x400U)
#define OTPC_SR_RD_REG_LOCK_SHIFT                (10U)
/*! RD_REG_LOCK - Read register lock error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_RD_REG_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_SR_RD_REG_LOCK_SHIFT)) & OTPC_SR_RD_REG_LOCK_MASK)

#define OTPC_SR_WR_REG_LOCK_MASK                 (0x800U)
#define OTPC_SR_WR_REG_LOCK_SHIFT                (11U)
/*! WR_REG_LOCK - Write register lock error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_WR_REG_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_SR_WR_REG_LOCK_SHIFT)) & OTPC_SR_WR_REG_LOCK_MASK)

#define OTPC_SR_WR_REG_BUSY_MASK                 (0x1000U)
#define OTPC_SR_WR_REG_BUSY_SHIFT                (12U)
/*! WR_REG_BUSY - Write register when busy error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_WR_REG_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_SR_WR_REG_BUSY_SHIFT)) & OTPC_SR_WR_REG_BUSY_MASK)

#define OTPC_SR_WR_POWER_OFF_MASK                (0x2000U)
#define OTPC_SR_WR_POWER_OFF_SHIFT               (13U)
/*! WR_POWER_OFF - Write when power off error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_WR_POWER_OFF(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_SR_WR_POWER_OFF_SHIFT)) & OTPC_SR_WR_POWER_OFF_MASK)

#define OTPC_SR_FSM_MASK                         (0x10000U)
#define OTPC_SR_FSM_SHIFT                        (16U)
/*! FSM - Finite-state machine error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_FSM(x)                           (((uint32_t)(((uint32_t)(x)) << OTPC_SR_FSM_SHIFT)) & OTPC_SR_FSM_MASK)

#define OTPC_SR_FLC_MASK                         (0x20000U)
#define OTPC_SR_FLC_SHIFT                        (17U)
/*! FLC - Fuse load counter error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_FLC(x)                           (((uint32_t)(((uint32_t)(x)) << OTPC_SR_FLC_SHIFT)) & OTPC_SR_FLC_MASK)

#define OTPC_SR_ADC_MASK                         (0x40000U)
#define OTPC_SR_ADC_SHIFT                        (18U)
/*! ADC - Address and data compare error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_ADC(x)                           (((uint32_t)(((uint32_t)(x)) << OTPC_SR_ADC_SHIFT)) & OTPC_SR_ADC_MASK)

#define OTPC_SR_IRC_MASK                         (0x80000U)
#define OTPC_SR_IRC_SHIFT                        (19U)
/*! IRC - Inverted register compare error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_IRC(x)                           (((uint32_t)(((uint32_t)(x)) << OTPC_SR_IRC_SHIFT)) & OTPC_SR_IRC_MASK)

#define OTPC_SR_FSC_MASK                         (0x100000U)
#define OTPC_SR_FSC_SHIFT                        (20U)
/*! FSC - Fuse and shadow register compare error
 *  0b0..No error
 *  0b1..Error
 */
#define OTPC_SR_FSC(x)                           (((uint32_t)(((uint32_t)(x)) << OTPC_SR_FSC_SHIFT)) & OTPC_SR_FSC_MASK)
/*! @} */

/*! @name RWC - Read and Write Control */
/*! @{ */

#define OTPC_RWC_ADDR_MASK                       (0x7FU)
#define OTPC_RWC_ADDR_SHIFT                      (0U)
/*! ADDR - EFUSE address */
#define OTPC_RWC_ADDR(x)                         (((uint32_t)(((uint32_t)(x)) << OTPC_RWC_ADDR_SHIFT)) & OTPC_RWC_ADDR_MASK)

#define OTPC_RWC_WR_ALL1S_MASK                   (0x1000U)
#define OTPC_RWC_WR_ALL1S_SHIFT                  (12U)
/*! WR_ALL1S - Write all 1s
 *  0b0..Uses the WDATA value
 *  0b1..Writes all 1s
 */
#define OTPC_RWC_WR_ALL1S(x)                     (((uint32_t)(((uint32_t)(x)) << OTPC_RWC_WR_ALL1S_SHIFT)) & OTPC_RWC_WR_ALL1S_MASK)

#define OTPC_RWC_READ_EFUSE_MASK                 (0x2000U)
#define OTPC_RWC_READ_EFUSE_SHIFT                (13U)
/*! READ_EFUSE - Read EFUSE
 *  0b0..Starts program operation when the WR_UNLOCK value is 0x9527; otherwise, takes no action.
 *  0b1..Starts read operation
 */
#define OTPC_RWC_READ_EFUSE(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_RWC_READ_EFUSE_SHIFT)) & OTPC_RWC_READ_EFUSE_MASK)

#define OTPC_RWC_READ_UPDATE_MASK                (0x4000U)
#define OTPC_RWC_READ_UPDATE_SHIFT               (14U)
/*! READ_UPDATE - Read update
 *  0b0..Shadow register does not update
 *  0b1..Shadow register updates
 */
#define OTPC_RWC_READ_UPDATE(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_RWC_READ_UPDATE_SHIFT)) & OTPC_RWC_READ_UPDATE_MASK)

#define OTPC_RWC_WR_UNLOCK_MASK                  (0xFFFF0000U)
#define OTPC_RWC_WR_UNLOCK_SHIFT                 (16U)
/*! WR_UNLOCK - Write Unlock */
#define OTPC_RWC_WR_UNLOCK(x)                    (((uint32_t)(((uint32_t)(x)) << OTPC_RWC_WR_UNLOCK_SHIFT)) & OTPC_RWC_WR_UNLOCK_MASK)
/*! @} */

/*! @name RLC - Reload Control */
/*! @{ */

#define OTPC_RLC_RELOAD_SHADOWS_MASK             (0x1U)
#define OTPC_RLC_RELOAD_SHADOWS_SHIFT            (0U)
/*! RELOAD_SHADOWS - Reload shadow registers
 *  0b0..No action (when writing) or reload complete (when reading)
 *  0b1..Reload
 */
#define OTPC_RLC_RELOAD_SHADOWS(x)               (((uint32_t)(((uint32_t)(x)) << OTPC_RLC_RELOAD_SHADOWS_SHIFT)) & OTPC_RLC_RELOAD_SHADOWS_MASK)
/*! @} */

/*! @name PCR - Power Control */
/*! @{ */

#define OTPC_PCR_HVREQ_MASK                      (0x1U)
#define OTPC_PCR_HVREQ_SHIFT                     (0U)
/*! HVREQ - Strong switch request
 *  0b0..Turn off
 *  0b1..Turn on
 */
#define OTPC_PCR_HVREQ(x)                        (((uint32_t)(((uint32_t)(x)) << OTPC_PCR_HVREQ_SHIFT)) & OTPC_PCR_HVREQ_MASK)

#define OTPC_PCR_LVREQ_MASK                      (0x2U)
#define OTPC_PCR_LVREQ_SHIFT                     (1U)
/*! LVREQ - Weak switch request
 *  0b0..Turn off
 *  0b1..Turn on
 */
#define OTPC_PCR_LVREQ(x)                        (((uint32_t)(((uint32_t)(x)) << OTPC_PCR_LVREQ_SHIFT)) & OTPC_PCR_LVREQ_MASK)

#define OTPC_PCR_PDREQ_MASK                      (0x4U)
#define OTPC_PCR_PDREQ_SHIFT                     (2U)
/*! PDREQ - Power down request
 *  0b0..PD pin is set to low when OTPC is in idle state. It means EFUSE hardmacro is in standby mode. Idle state
 *       means OTPC is not in read and program modes.
 *  0b1..PD pin is set to high when OTPC is in idle state. It means EFUSE hardmacro is in power down mode.
 */
#define OTPC_PCR_PDREQ(x)                        (((uint32_t)(((uint32_t)(x)) << OTPC_PCR_PDREQ_SHIFT)) & OTPC_PCR_PDREQ_MASK)
/*! @} */

/*! @name WDATA - Write Data */
/*! @{ */

#define OTPC_WDATA_DAT_MASK                      (0xFFFFFFFFU)
#define OTPC_WDATA_DAT_SHIFT                     (0U)
/*! DAT - Write data */
#define OTPC_WDATA_DAT(x)                        (((uint32_t)(((uint32_t)(x)) << OTPC_WDATA_DAT_SHIFT)) & OTPC_WDATA_DAT_MASK)
/*! @} */

/*! @name RDATA - Read Data */
/*! @{ */

#define OTPC_RDATA_DAT_MASK                      (0xFFFFFFFFU)
#define OTPC_RDATA_DAT_SHIFT                     (0U)
/*! DAT - Read data */
#define OTPC_RDATA_DAT(x)                        (((uint32_t)(((uint32_t)(x)) << OTPC_RDATA_DAT_SHIFT)) & OTPC_RDATA_DAT_MASK)
/*! @} */

/*! @name TIMING1 - Timing1 */
/*! @{ */

#define OTPC_TIMING1_TADDR_MASK                  (0xFU)
#define OTPC_TIMING1_TADDR_SHIFT                 (0U)
/*! TADDR - Address to STROBE setup and hold time */
#define OTPC_TIMING1_TADDR(x)                    (((uint32_t)(((uint32_t)(x)) << OTPC_TIMING1_TADDR_SHIFT)) & OTPC_TIMING1_TADDR_MASK)

#define OTPC_TIMING1_TRELAX_MASK                 (0xF0U)
#define OTPC_TIMING1_TRELAX_SHIFT                (4U)
/*! TRELAX - CSB, PGENB and LOAD to STROBE setup and hold time */
#define OTPC_TIMING1_TRELAX(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_TIMING1_TRELAX_SHIFT)) & OTPC_TIMING1_TRELAX_MASK)

#define OTPC_TIMING1_TRD_MASK                    (0x3F00U)
#define OTPC_TIMING1_TRD_SHIFT                   (8U)
/*! TRD - Read strobe pulse width time */
#define OTPC_TIMING1_TRD(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_TIMING1_TRD_SHIFT)) & OTPC_TIMING1_TRD_MASK)

#define OTPC_TIMING1_TPS_MASK                    (0x3F0000U)
#define OTPC_TIMING1_TPS_SHIFT                   (16U)
/*! TPS - PS to CSB setup and hold time between power switch and chip select assertion */
#define OTPC_TIMING1_TPS(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_TIMING1_TPS_SHIFT)) & OTPC_TIMING1_TPS_MASK)

#define OTPC_TIMING1_TPD_MASK                    (0xFF000000U)
#define OTPC_TIMING1_TPD_SHIFT                   (24U)
/*! TPD - PD to CSB setup time between power down signal deassertion and chip select signal assertion */
#define OTPC_TIMING1_TPD(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_TIMING1_TPD_SHIFT)) & OTPC_TIMING1_TPD_MASK)
/*! @} */

/*! @name TIMING2 - Timing2 */
/*! @{ */

#define OTPC_TIMING2_TPGM_MASK                   (0xFFFU)
#define OTPC_TIMING2_TPGM_SHIFT                  (0U)
/*! TPGM - Typical program strobe pulse width time */
#define OTPC_TIMING2_TPGM(x)                     (((uint32_t)(((uint32_t)(x)) << OTPC_TIMING2_TPGM_SHIFT)) & OTPC_TIMING2_TPGM_MASK)
/*! @} */

/*! @name LOCK - Lock */
/*! @{ */

#define OTPC_LOCK_NXP_PART_CFG_LOCK_MASK         (0x7U)
#define OTPC_LOCK_NXP_PART_CFG_LOCK_SHIFT        (0U)
/*! NXP_PART_CFG_LOCK - NXP Part Config Lock */
#define OTPC_LOCK_NXP_PART_CFG_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_NXP_PART_CFG_LOCK_SHIFT)) & OTPC_LOCK_NXP_PART_CFG_LOCK_MASK)

#define OTPC_LOCK_NXP_EXT_LOCK_MASK              (0x38U)
#define OTPC_LOCK_NXP_EXT_LOCK_SHIFT             (3U)
/*! NXP_EXT_LOCK - NXP EXT Lock */
#define OTPC_LOCK_NXP_EXT_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_NXP_EXT_LOCK_SHIFT)) & OTPC_LOCK_NXP_EXT_LOCK_MASK)

#define OTPC_LOCK_BOOT_CFG_LOCK_MASK             (0xE00U)
#define OTPC_LOCK_BOOT_CFG_LOCK_SHIFT            (9U)
/*! BOOT_CFG_LOCK - Boot config Lock */
#define OTPC_LOCK_BOOT_CFG_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_BOOT_CFG_LOCK_SHIFT)) & OTPC_LOCK_BOOT_CFG_LOCK_MASK)

#define OTPC_LOCK_PRINCE_CFG_LOCK_MASK           (0x7000U)
#define OTPC_LOCK_PRINCE_CFG_LOCK_SHIFT          (12U)
/*! PRINCE_CFG_LOCK - Prince Config Lock */
#define OTPC_LOCK_PRINCE_CFG_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_PRINCE_CFG_LOCK_SHIFT)) & OTPC_LOCK_PRINCE_CFG_LOCK_MASK)

#define OTPC_LOCK_OSCAA_KEY_LOCK_MASK            (0x38000U)
#define OTPC_LOCK_OSCAA_KEY_LOCK_SHIFT           (15U)
/*! OSCAA_KEY_LOCK - OSCAA Key Lock */
#define OTPC_LOCK_OSCAA_KEY_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_OSCAA_KEY_LOCK_SHIFT)) & OTPC_LOCK_OSCAA_KEY_LOCK_MASK)

#define OTPC_LOCK_CUST_LOCK0_MASK                (0x1C0000U)
#define OTPC_LOCK_CUST_LOCK0_SHIFT               (18U)
/*! CUST_LOCK0 - CUST Lock 0 */
#define OTPC_LOCK_CUST_LOCK0(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_CUST_LOCK0_SHIFT)) & OTPC_LOCK_CUST_LOCK0_MASK)

#define OTPC_LOCK_CUST_LOCK1_MASK                (0xE00000U)
#define OTPC_LOCK_CUST_LOCK1_SHIFT               (21U)
/*! CUST_LOCK1 - CUST Lock 1 */
#define OTPC_LOCK_CUST_LOCK1(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_CUST_LOCK1_SHIFT)) & OTPC_LOCK_CUST_LOCK1_MASK)

#define OTPC_LOCK_CUST_LOCK2_MASK                (0x7000000U)
#define OTPC_LOCK_CUST_LOCK2_SHIFT               (24U)
/*! CUST_LOCK2 - CUST Lock 2 */
#define OTPC_LOCK_CUST_LOCK2(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_CUST_LOCK2_SHIFT)) & OTPC_LOCK_CUST_LOCK2_MASK)

#define OTPC_LOCK_CUST_LOCK3_MASK                (0x38000000U)
#define OTPC_LOCK_CUST_LOCK3_SHIFT               (27U)
/*! CUST_LOCK3 - CUST Lock 3 */
#define OTPC_LOCK_CUST_LOCK3(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_LOCK_CUST_LOCK3_SHIFT)) & OTPC_LOCK_CUST_LOCK3_MASK)
/*! @} */

/*! @name SECURE - Secure */
/*! @{ */

#define OTPC_SECURE_DAT_MASK                     (0xFFFFFFFFU)
#define OTPC_SECURE_DAT_SHIFT                    (0U)
/*! DAT - Data */
#define OTPC_SECURE_DAT(x)                       (((uint32_t)(((uint32_t)(x)) << OTPC_SECURE_DAT_SHIFT)) & OTPC_SECURE_DAT_MASK)
/*! @} */

/*! @name SECURE_INV - Inverted Secure */
/*! @{ */

#define OTPC_SECURE_INV_DAT_MASK                 (0xFFFFFFFFU)
#define OTPC_SECURE_INV_DAT_SHIFT                (0U)
/*! DAT - Data */
#define OTPC_SECURE_INV_DAT(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_SECURE_INV_DAT_SHIFT)) & OTPC_SECURE_INV_DAT_MASK)
/*! @} */

/*! @name DBG_KEY - Debug and Key */
/*! @{ */

#define OTPC_DBG_KEY_DAT_MASK                    (0xFFFFFFFFU)
#define OTPC_DBG_KEY_DAT_SHIFT                   (0U)
/*! DAT - Data */
#define OTPC_DBG_KEY_DAT(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_DBG_KEY_DAT_SHIFT)) & OTPC_DBG_KEY_DAT_MASK)
/*! @} */

/*! @name MISC_CFG - MISC Config */
/*! @{ */

#define OTPC_MISC_CFG_DAT_MASK                   (0xFFFFFFFFU)
#define OTPC_MISC_CFG_DAT_SHIFT                  (0U)
/*! DAT - Data */
#define OTPC_MISC_CFG_DAT(x)                     (((uint32_t)(((uint32_t)(x)) << OTPC_MISC_CFG_DAT_SHIFT)) & OTPC_MISC_CFG_DAT_MASK)
/*! @} */

/*! @name PHANTOM_CFG - PHANTOM Config */
/*! @{ */

#define OTPC_PHANTOM_CFG_DAT_MASK                (0xFFFFFFFFU)
#define OTPC_PHANTOM_CFG_DAT_SHIFT               (0U)
/*! DAT - Data */
#define OTPC_PHANTOM_CFG_DAT(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_PHANTOM_CFG_DAT_SHIFT)) & OTPC_PHANTOM_CFG_DAT_MASK)
/*! @} */

/*! @name FLEX_CFG0 - Flexible Config 0 */
/*! @{ */

#define OTPC_FLEX_CFG0_DAT_MASK                  (0xFFFFFFFFU)
#define OTPC_FLEX_CFG0_DAT_SHIFT                 (0U)
/*! DAT - Data */
#define OTPC_FLEX_CFG0_DAT(x)                    (((uint32_t)(((uint32_t)(x)) << OTPC_FLEX_CFG0_DAT_SHIFT)) & OTPC_FLEX_CFG0_DAT_MASK)
/*! @} */

/*! @name FLEX_CFG1 - Flexible Config 1 */
/*! @{ */

#define OTPC_FLEX_CFG1_DAT_MASK                  (0xFFFFFFFFU)
#define OTPC_FLEX_CFG1_DAT_SHIFT                 (0U)
/*! DAT - Data */
#define OTPC_FLEX_CFG1_DAT(x)                    (((uint32_t)(((uint32_t)(x)) << OTPC_FLEX_CFG1_DAT_SHIFT)) & OTPC_FLEX_CFG1_DAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OTPC_Register_Masks */


/*!
 * @}
 */ /* end of group OTPC_Peripheral_Access_Layer */


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


#endif  /* PERI_OTPC_H_ */

