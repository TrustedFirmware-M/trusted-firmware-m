/*
** ###################################################################
**     Processors:          MIMX9301CVVXD_ca55
**                          MIMX9301CVVXD_cm33
**                          MIMX9301DVVXD_ca55
**                          MIMX9301DVVXD_cm33
**                          MIMX9302CVVXD_ca55
**                          MIMX9302CVVXD_cm33
**                          MIMX9302DVVXD_ca55
**                          MIMX9302DVVXD_cm33
**                          MIMX9311CVXXM_ca55
**                          MIMX9311CVXXM_cm33
**                          MIMX9311DVXXM_ca55
**                          MIMX9311DVXXM_cm33
**                          MIMX9311XVXXM_ca55
**                          MIMX9311XVXXM_cm33
**                          MIMX9312CVXXM_ca55
**                          MIMX9312CVXXM_cm33
**                          MIMX9312DVXXM_ca55
**                          MIMX9312DVXXM_cm33
**                          MIMX9312XVXXM_ca55
**                          MIMX9312XVXXM_cm33
**                          MIMX9321CVXXM_ca55
**                          MIMX9321CVXXM_cm33
**                          MIMX9321DVXXM_ca55
**                          MIMX9321DVXXM_cm33
**                          MIMX9321XVXXM_ca55
**                          MIMX9321XVXXM_cm33
**                          MIMX9322CVXXM_ca55
**                          MIMX9322CVXXM_cm33
**                          MIMX9322DVXXM_ca55
**                          MIMX9322DVXXM_cm33
**                          MIMX9322XVXXM_ca55
**                          MIMX9322XVXXM_cm33
**                          MIMX9331AVTXM_ca55
**                          MIMX9331AVTXM_cm33
**                          MIMX9331CVVXM_ca55
**                          MIMX9331CVVXM_cm33
**                          MIMX9331DVVXM_ca55
**                          MIMX9331DVVXM_cm33
**                          MIMX9331XVVXM_ca55
**                          MIMX9331XVVXM_cm33
**                          MIMX9332AVTXM_ca55
**                          MIMX9332AVTXM_cm33
**                          MIMX9332CVVXM_ca55
**                          MIMX9332CVVXM_cm33
**                          MIMX9332DVVXM_ca55
**                          MIMX9332DVVXM_cm33
**                          MIMX9332XVVXM_ca55
**                          MIMX9332XVVXM_cm33
**                          MIMX9351AVTXM_ca55
**                          MIMX9351AVTXM_cm33
**                          MIMX9351CVVXM_ca55
**                          MIMX9351CVVXM_cm33
**                          MIMX9351DVVXM_ca55
**                          MIMX9351DVVXM_cm33
**                          MIMX9351XVVXM_ca55
**                          MIMX9351XVVXM_cm33
**                          MIMX9352AVTXM_ca55
**                          MIMX9352AVTXM_cm33
**                          MIMX9352CVVXM_ca55
**                          MIMX9352CVVXM_cm33
**                          MIMX9352DVVXM_ca55
**                          MIMX9352DVVXM_cm33
**                          MIMX9352XVVXM_ca55
**                          MIMX9352XVVXM_cm33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_NICMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_NICMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_NICMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_NICMIX
 */

#if !defined(PERI_BLK_CTRL_NICMIX_H_)
#define PERI_BLK_CTRL_NICMIX_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9301CVVXD_ca55) || defined(CPU_MIMX9301DVVXD_ca55))
#include "MIMX9301_ca55_COMMON.h"
#elif (defined(CPU_MIMX9301CVVXD_cm33) || defined(CPU_MIMX9301DVVXD_cm33))
#include "MIMX9301_cm33_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_ca55) || defined(CPU_MIMX9302DVVXD_ca55))
#include "MIMX9302_ca55_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_cm33) || defined(CPU_MIMX9302DVVXD_cm33))
#include "MIMX9302_cm33_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_ca55) || defined(CPU_MIMX9311DVXXM_ca55) || defined(CPU_MIMX9311XVXXM_ca55))
#include "MIMX9311_ca55_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_cm33) || defined(CPU_MIMX9311DVXXM_cm33) || defined(CPU_MIMX9311XVXXM_cm33))
#include "MIMX9311_cm33_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_ca55) || defined(CPU_MIMX9312DVXXM_ca55) || defined(CPU_MIMX9312XVXXM_ca55))
#include "MIMX9312_ca55_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_cm33) || defined(CPU_MIMX9312DVXXM_cm33) || defined(CPU_MIMX9312XVXXM_cm33))
#include "MIMX9312_cm33_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_ca55) || defined(CPU_MIMX9321DVXXM_ca55) || defined(CPU_MIMX9321XVXXM_ca55))
#include "MIMX9321_ca55_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_cm33) || defined(CPU_MIMX9321DVXXM_cm33) || defined(CPU_MIMX9321XVXXM_cm33))
#include "MIMX9321_cm33_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_ca55) || defined(CPU_MIMX9322DVXXM_ca55) || defined(CPU_MIMX9322XVXXM_ca55))
#include "MIMX9322_ca55_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_cm33) || defined(CPU_MIMX9322DVXXM_cm33) || defined(CPU_MIMX9322XVXXM_cm33))
#include "MIMX9322_cm33_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_ca55) || defined(CPU_MIMX9331CVVXM_ca55) || defined(CPU_MIMX9331DVVXM_ca55) || defined(CPU_MIMX9331XVVXM_ca55))
#include "MIMX9331_ca55_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_cm33) || defined(CPU_MIMX9331CVVXM_cm33) || defined(CPU_MIMX9331DVVXM_cm33) || defined(CPU_MIMX9331XVVXM_cm33))
#include "MIMX9331_cm33_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_ca55) || defined(CPU_MIMX9332CVVXM_ca55) || defined(CPU_MIMX9332DVVXM_ca55) || defined(CPU_MIMX9332XVVXM_ca55))
#include "MIMX9332_ca55_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_cm33) || defined(CPU_MIMX9332CVVXM_cm33) || defined(CPU_MIMX9332DVVXM_cm33) || defined(CPU_MIMX9332XVVXM_cm33))
#include "MIMX9332_cm33_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_ca55) || defined(CPU_MIMX9351CVVXM_ca55) || defined(CPU_MIMX9351DVVXM_ca55) || defined(CPU_MIMX9351XVVXM_ca55))
#include "MIMX9351_ca55_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_cm33) || defined(CPU_MIMX9351CVVXM_cm33) || defined(CPU_MIMX9351DVVXM_cm33) || defined(CPU_MIMX9351XVVXM_cm33))
#include "MIMX9351_cm33_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_ca55) || defined(CPU_MIMX9352CVVXM_ca55) || defined(CPU_MIMX9352DVVXM_ca55) || defined(CPU_MIMX9352XVVXM_ca55))
#include "MIMX9352_ca55_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_cm33) || defined(CPU_MIMX9352CVVXM_cm33) || defined(CPU_MIMX9352DVVXM_cm33) || defined(CPU_MIMX9352XVVXM_cm33))
#include "MIMX9352_cm33_COMMON.h"
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
   -- BLK_CTRL_NICMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NICMIX_Peripheral_Access_Layer BLK_CTRL_NICMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_NICMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t DEXSC_ERR;                         /**< DEXSC error response configuration, offset: 0x0 */
  __IO uint32_t OCRAM_RMW;                         /**< RMW configuration, offset: 0x4 */
  __IO uint32_t AXI_LIMIT_WAKEUPMIX;               /**< Configuration register for axi_limit_wakeupmix, offset: 0x8 */
  __IO uint32_t CACHE_ATTR;                        /**< Configuration register for AxCACHE[1] override, offset: 0xC */
  __IO uint32_t WAKEUPMIX_QOS;                     /**< Configuration register for QoS value from wakeupmix, offset: 0x10 */
  __IO uint32_t CACHE_QOS;                         /**< Configuration register for QoS value from A55, offset: 0x14 */
  __IO uint32_t MLMIX0_QOS;                        /**< Configuration register for QoS value from mlmix m0, offset: 0x18 */
  __IO uint32_t MLMIX1_QOS;                        /**< Configuration register for QoS value from mlmix m1, offset: 0x1C */
  __IO uint32_t HSIOMIX_QOS;                       /**< Configuration register for QoS value from hsiomix, offset: 0x20 */
  __IO uint32_t TIE_VALUE;                         /**< GPR for uncertain tie0 or tie1, offset: 0x24 */
} BLK_CTRL_NICMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NICMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NICMIX_Register_Masks BLK_CTRL_NICMIX Register Masks
 * @{
 */

/*! @name DEXSC_ERR - DEXSC error response configuration */
/*! @{ */

#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_ERR_RESP_EN_MASK (0x1U)
#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_ERR_RESP_EN_SHIFT (0U)
/*! OCRAM_ERR_RESP_EN - OCRAM DEXSC error response enable
 *  0b0..DEXSC will not respond error if there is read error on DEXSC
 *  0b1..DEXSC will respond slave error if there is read error on DEXSC
 */
#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_ERR_RESP_EN_MASK)

#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_MASK (0x2U)
#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_SHIFT (1U)
/*! OCRAM_EXC_ERR_RESP_EN - OCRAM DEXSC exclusive error response enable
 *  0b0..DEXSC will not respond error if there is exclusive error on DEXSC
 *  0b1..DEXSC will respond slave error if there is exclusive error on DEXSC
 */
#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_MASK)

#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_MASK (0x4U)
#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_SHIFT (2U)
/*! OCRAM_LOCK_ERR_RESP_EN - Lock bit of OCRAM_ERR_RESP_EN and OCRAM_EXC_ERR_RESP_EN */
#define BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NICMIX_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_MASK)

#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_ERR_RESP_EN_MASK (0x10000U)
#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_ERR_RESP_EN_SHIFT (16U)
/*! DRAM_ERR_RESP_EN - DRAM DEXSC error response enable
 *  0b0..DEXSC will not respond error if there is read error on DEXSC
 *  0b1..DEXSC will respond slave error if there is read error on DEXSC
 */
#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_ERR_RESP_EN_MASK)

#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_MASK (0x20000U)
#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_SHIFT (17U)
/*! DRAM_EXC_ERR_RESP_EN - DRAM DEXSC exclusive error response enable
 *  0b0..DEXSC will not respond error if there is exclusive error on DEXSC
 *  0b1..DEXSC will respond slave error if there is exclusive error on DEXSC
 */
#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_MASK)

#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_MASK (0x40000U)
#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_SHIFT (18U)
/*! DRAM_LOCK_ERR_RESP_EN - Lock bit of DRAM_ERR_RESP_EN and DRAM_EXC_ERR_RESP_EN */
#define BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NICMIX_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_MASK)
/*! @} */

/*! @name OCRAM_RMW - RMW configuration */
/*! @{ */

#define BLK_CTRL_NICMIX_OCRAM_RMW_RMW_WAIT_BVALID_MASK (0x1U)
#define BLK_CTRL_NICMIX_OCRAM_RMW_RMW_WAIT_BVALID_SHIFT (0U)
/*! RMW_WAIT_BVALID - Configure OCRAM RMW to wait for write response
 *  0b0..RMW will not wait for the write response and begin to work for another access
 *  0b1..RMW will not work for another access until it receives the write response of last access
 */
#define BLK_CTRL_NICMIX_OCRAM_RMW_RMW_WAIT_BVALID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_OCRAM_RMW_RMW_WAIT_BVALID_SHIFT)) & BLK_CTRL_NICMIX_OCRAM_RMW_RMW_WAIT_BVALID_MASK)
/*! @} */

/*! @name AXI_LIMIT_WAKEUPMIX - Configuration register for axi_limit_wakeupmix */
/*! @{ */

#define BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_ENABLE_MASK (0x1U)
#define BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_ENABLE_SHIFT (0U)
/*! ENABLE - Enable the beat limit on the access from wakeupmix
 *  0b0..Disable the beat limit
 *  0b1..Enable the beat limit
 */
#define BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_ENABLE_SHIFT)) & BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_ENABLE_MASK)

#define BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_MASK (0xFFFF0000U)
#define BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_SHIFT (16U)
/*! BEAT_LIMIT - Beat limit number */
#define BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_SHIFT)) & BLK_CTRL_NICMIX_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_MASK)
/*! @} */

/*! @name CACHE_ATTR - Configuration register for AxCACHE[1] override */
/*! @{ */

#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_MASK (0x1U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_SHIFT (0U)
/*! WAKEUPMIX_ARCACHE_EN - Enable ARCACHE[1] override
 *  0b0..Disable override ARCACHE[1] from ssi_slv_wakeupmix
 *  0b1..enable override ARCACHE[1] from ssi_slv_wakeupmix
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_MASK (0x2U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_SHIFT (1U)
/*! WAKEUPMIX_AWCACHE_EN - Enable AWCACHE[1] override
 *  0b0..Disable override AWCACHE[1] from ssi_slv_wakeupmix
 *  0b1..enable override AWCACHE[1] from ssi_slv_wakeupmix
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_EN_MASK (0x4U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_EN_SHIFT (2U)
/*! CACHE_ARCACHE_EN - Enable ARCACHE[1] override
 *  0b0..Disable override ARCACHE[1] from ssi_slv_cache
 *  0b1..enable override ARCACHE[1] from ssi_slv_cache
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_EN_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_EN_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_EN_MASK (0x8U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_EN_SHIFT (3U)
/*! CACHE_AWCACHE_EN - Enable AWCACHE[1] override
 *  0b0..Disable override AWCACHE[1] from ssi_slv_cache
 *  0b1..enable override AWCACHE[1] from ssi_slv_cache
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_EN_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_EN_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_EN_MASK (0x10U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_EN_SHIFT (4U)
/*! HSIOMIX_ARCACHE_EN - Enable ARCACHE[1] override
 *  0b0..Disable override ARCACHE[1] from ssi_slv_hsiomix
 *  0b1..enable override ARCACHE[1] from ssi_slv_hsiomix
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_EN_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_EN_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_EN_MASK (0x20U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_EN_SHIFT (5U)
/*! HSIOMIX_AWCACHE_EN - Enable AWCACHE[1] override
 *  0b0..Disable override AWCACHE[1] from ssi_slv_hsiomix
 *  0b1..enable override AWCACHE[1] from ssi_slv_hsiomix
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_EN_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_EN_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_MASK (0x10000U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_SHIFT (16U)
/*! WAKEUPMIX_ARCACHE - Override value
 *  0b0..Override ARCACHE[1] from ssi_slv_wakeupmix to 0
 *  0b1..Override ARCACHE[1] from ssi_slv_wakeupmix to 1
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_ARCACHE_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_MASK (0x20000U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_SHIFT (17U)
/*! WAKEUPMIX_AWCACHE - Override value
 *  0b0..Override AWCACHE[1] from ssi_slv_wakeupmix to 0
 *  0b1..Override AWCACHE[1] from ssi_slv_wakeupmix to 1
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_WAKEUPMIX_AWCACHE_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_MASK (0x40000U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_SHIFT (18U)
/*! CACHE_ARCACHE - Override value
 *  0b0..Override ARCACHE[1] from ssi_slv_cache to 0
 *  0b1..Override ARCACHE[1] from ssi_slv_cache to 1
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_ARCACHE_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_MASK (0x80000U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_SHIFT (19U)
/*! CACHE_AWCACHE - Override value
 *  0b0..Override AWCACHE[1] from ssi_slv_cache to 0
 *  0b1..Override AWCACHE[1] from ssi_slv_cache to 1
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_CACHE_AWCACHE_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_MASK (0x100000U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_SHIFT (20U)
/*! HSIOMIX_ARCACHE - Override value
 *  0b0..Override ARCACHE[1] from ssi_slv_hsiomix to 0
 *  0b1..Override ARCACHE[1] from ssi_slv_hsiomix to 1
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_ARCACHE_MASK)

#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_MASK (0x200000U)
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_SHIFT (21U)
/*! HSIOMIX_AWCACHE - Override value
 *  0b0..Override AWCACHE[1] from ssi_slv_hsiomix to 0
 *  0b1..Override AWCACHE[1] from ssi_slv_hsiomix to 1
 */
#define BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_SHIFT)) & BLK_CTRL_NICMIX_CACHE_ATTR_HSIOMIX_AWCACHE_MASK)
/*! @} */

/*! @name WAKEUPMIX_QOS - Configuration register for QoS value from wakeupmix */
/*! @{ */

#define BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AW_MASK (0xFU)
#define BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from wakeupmix */
#define BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AR_MASK (0xF0U)
#define BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from wakeupmix */
#define BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NICMIX_WAKEUPMIX_QOS_PANIC_AR_MASK)
/*! @} */

/*! @name CACHE_QOS - Configuration register for QoS value from A55 */
/*! @{ */

#define BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AW_MASK  (0xFU)
#define BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from A55 */
#define BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AW(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AR_MASK  (0xF0U)
#define BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from A55 */
#define BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AR(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NICMIX_CACHE_QOS_PANIC_AR_MASK)

#define BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AW_MASK (0xF0000U)
#define BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AW_SHIFT (16U)
/*! DEFAULT_AW - Value of aw_qos_default from A55 */
#define BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AW(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AW_SHIFT)) & BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AW_MASK)

#define BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AR_MASK (0xF00000U)
#define BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AR_SHIFT (20U)
/*! DEFAULT_AR - Value of ar_qos_default from A55 */
#define BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AR(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AR_SHIFT)) & BLK_CTRL_NICMIX_CACHE_QOS_DEFAULT_AR_MASK)
/*! @} */

/*! @name MLMIX0_QOS - Configuration register for QoS value from mlmix m0 */
/*! @{ */

#define BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AW_MASK (0xFU)
#define BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from mlmix m0 */
#define BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AW(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AR_MASK (0xF0U)
#define BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from mlmix m0 */
#define BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AR(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NICMIX_MLMIX0_QOS_PANIC_AR_MASK)

#define BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AW_MASK (0xF0000U)
#define BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AW_SHIFT (16U)
/*! DEFAULT_AW - Value of aw_qos_default from mlmix m0 */
#define BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AW_SHIFT)) & BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AW_MASK)

#define BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AR_MASK (0xF00000U)
#define BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AR_SHIFT (20U)
/*! DEFAULT_AR - Value of ar_qos_default from mlmix m0 */
#define BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AR_SHIFT)) & BLK_CTRL_NICMIX_MLMIX0_QOS_DEFAULT_AR_MASK)
/*! @} */

/*! @name MLMIX1_QOS - Configuration register for QoS value from mlmix m1 */
/*! @{ */

#define BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AW_MASK (0xFU)
#define BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from mlmix m1 */
#define BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AW(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AR_MASK (0xF0U)
#define BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from mlmix m1 */
#define BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AR(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NICMIX_MLMIX1_QOS_PANIC_AR_MASK)

#define BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AW_MASK (0xF0000U)
#define BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AW_SHIFT (16U)
/*! DEFAULT_AW - Value of aw_qos_default from mlmix m1 */
#define BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AW_SHIFT)) & BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AW_MASK)

#define BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AR_MASK (0xF00000U)
#define BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AR_SHIFT (20U)
/*! DEFAULT_AR - Value of ar_qos_default from mlmix m1 */
#define BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AR_SHIFT)) & BLK_CTRL_NICMIX_MLMIX1_QOS_DEFAULT_AR_MASK)
/*! @} */

/*! @name HSIOMIX_QOS - Configuration register for QoS value from hsiomix */
/*! @{ */

#define BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AW_MASK (0xFU)
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from hsiomix */
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AW(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AR_MASK (0xF0U)
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from hsiomix */
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AR(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NICMIX_HSIOMIX_QOS_PANIC_AR_MASK)

#define BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AW_MASK (0xF0000U)
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AW_SHIFT (16U)
/*! DEFAULT_AW - Value of aw_qos_default from hsiomix */
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AW_SHIFT)) & BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AW_MASK)

#define BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AR_MASK (0xF00000U)
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AR_SHIFT (20U)
/*! DEFAULT_AR - Value of ar_qos_default from hsiomix */
#define BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AR_SHIFT)) & BLK_CTRL_NICMIX_HSIOMIX_QOS_DEFAULT_AR_MASK)
/*! @} */

/*! @name TIE_VALUE - GPR for uncertain tie0 or tie1 */
/*! @{ */

#define BLK_CTRL_NICMIX_TIE_VALUE_AIPS4_HBSTRB_MASK (0xFU)
#define BLK_CTRL_NICMIX_TIE_VALUE_AIPS4_HBSTRB_SHIFT (0U)
/*! AIPS4_HBSTRB - Value of aips4.hbstrb */
#define BLK_CTRL_NICMIX_TIE_VALUE_AIPS4_HBSTRB(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_AIPS4_HBSTRB_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_AIPS4_HBSTRB_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_XCPT_RTN_MASK  (0x30U)
#define BLK_CTRL_NICMIX_TIE_VALUE_XCPT_RTN_SHIFT (4U)
/*! XCPT_RTN - Dac_cache_r.xcpt_rtn and dac_cache_w.xcpt_rtn */
#define BLK_CTRL_NICMIX_TIE_VALUE_XCPT_RTN(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_XCPT_RTN_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_XCPT_RTN_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_GICT_ALLOW_NS_MASK (0x40U)
#define BLK_CTRL_NICMIX_TIE_VALUE_GICT_ALLOW_NS_SHIFT (6U)
/*! GICT_ALLOW_NS - GIC600.gict_allow_ns */
#define BLK_CTRL_NICMIX_TIE_VALUE_GICT_ALLOW_NS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_GICT_ALLOW_NS_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_GICT_ALLOW_NS_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_GICP_ALLOW_NS_MASK (0x80U)
#define BLK_CTRL_NICMIX_TIE_VALUE_GICP_ALLOW_NS_SHIFT (7U)
/*! GICP_ALLOW_NS - GIC600.gicp_allow_ns */
#define BLK_CTRL_NICMIX_TIE_VALUE_GICP_ALLOW_NS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_GICP_ALLOW_NS_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_GICP_ALLOW_NS_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_ARBAR_S_MASK   (0x300U)
#define BLK_CTRL_NICMIX_TIE_VALUE_ARBAR_S_SHIFT  (8U)
/*! ARBAR_S - GIC600.ARBAR_S */
#define BLK_CTRL_NICMIX_TIE_VALUE_ARBAR_S(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_ARBAR_S_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_ARBAR_S_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_AWBAR_S_MASK   (0xC00U)
#define BLK_CTRL_NICMIX_TIE_VALUE_AWBAR_S_SHIFT  (10U)
/*! AWBAR_S - GIC600.AWBAR_S */
#define BLK_CTRL_NICMIX_TIE_VALUE_AWBAR_S(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_AWBAR_S_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_AWBAR_S_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_ARUSER_S_MASK  (0x7000U)
#define BLK_CTRL_NICMIX_TIE_VALUE_ARUSER_S_SHIFT (12U)
/*! ARUSER_S - GIC600.ARUSER_S */
#define BLK_CTRL_NICMIX_TIE_VALUE_ARUSER_S(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_ARUSER_S_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_ARUSER_S_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_AWUSER_S_MASK  (0x38000U)
#define BLK_CTRL_NICMIX_TIE_VALUE_AWUSER_S_SHIFT (15U)
/*! AWUSER_S - GIC600.AWUSER_S */
#define BLK_CTRL_NICMIX_TIE_VALUE_AWUSER_S(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_AWUSER_S_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_AWUSER_S_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_ARSNOOP_S_MASK (0x3C0000U)
#define BLK_CTRL_NICMIX_TIE_VALUE_ARSNOOP_S_SHIFT (18U)
/*! ARSNOOP_S - GIC600.arsnoop_s */
#define BLK_CTRL_NICMIX_TIE_VALUE_ARSNOOP_S(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_ARSNOOP_S_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_ARSNOOP_S_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_AWSNOOP_S_MASK (0x1C00000U)
#define BLK_CTRL_NICMIX_TIE_VALUE_AWSNOOP_S_SHIFT (22U)
/*! AWSNOOP_S - GIC600.awsnoop_s */
#define BLK_CTRL_NICMIX_TIE_VALUE_AWSNOOP_S(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_AWSNOOP_S_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_AWSNOOP_S_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_HPROT_GPV_CENTRAL_MASK (0x1E000000U)
#define BLK_CTRL_NICMIX_TIE_VALUE_HPROT_GPV_CENTRAL_SHIFT (25U)
/*! HPROT_GPV_CENTRAL - NIC400_central.HPROT_gpv_central */
#define BLK_CTRL_NICMIX_TIE_VALUE_HPROT_GPV_CENTRAL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_HPROT_GPV_CENTRAL_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_HPROT_GPV_CENTRAL_MASK)

#define BLK_CTRL_NICMIX_TIE_VALUE_DFTRAMHOLD_MASK (0x20000000U)
#define BLK_CTRL_NICMIX_TIE_VALUE_DFTRAMHOLD_SHIFT (29U)
/*! DFTRAMHOLD - GIC600.dftramhold */
#define BLK_CTRL_NICMIX_TIE_VALUE_DFTRAMHOLD(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NICMIX_TIE_VALUE_DFTRAMHOLD_SHIFT)) & BLK_CTRL_NICMIX_TIE_VALUE_DFTRAMHOLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_NICMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_NICMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_NICMIX_H_ */
