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
**         CMSIS Peripheral Access Layer for XCACHE
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
 * @file PERI_XCACHE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XCACHE
 *
 * CMSIS Peripheral Access Layer for XCACHE
 */

#if !defined(PERI_XCACHE_H_)
#define PERI_XCACHE_H_                           /**< Symbol preventing repeated inclusion */

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
   -- XCACHE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCACHE_Peripheral_Access_Layer XCACHE Peripheral Access Layer
 * @{
 */

/** XCACHE - Register Layout Typedef */
typedef struct {
  __IO uint32_t CCR;                               /**< Cache Control, offset: 0x0 */
  __IO uint32_t CLCR;                              /**< Cache Line Control, offset: 0x4 */
  __IO uint32_t CSAR;                              /**< Cache Search Address, offset: 0x8 */
  __IO uint32_t CCVR;                              /**< Cache Read/Write Value, offset: 0xC */
} XCACHE_Type;

/* ----------------------------------------------------------------------------
   -- XCACHE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCACHE_Register_Masks XCACHE Register Masks
 * @{
 */

/*! @name CCR - Cache Control */
/*! @{ */

#define XCACHE_CCR_ENCACHE_MASK                  (0x1U)
#define XCACHE_CCR_ENCACHE_SHIFT                 (0U)
/*! ENCACHE - Cache Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define XCACHE_CCR_ENCACHE(x)                    (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_ENCACHE_SHIFT)) & XCACHE_CCR_ENCACHE_MASK)

#define XCACHE_CCR_FRCWT_MASK                    (0x4U)
#define XCACHE_CCR_FRCWT_SHIFT                   (2U)
/*! FRCWT - Force Write Through Mode
 *  0b0..Does not force
 *  0b1..Force
 */
#define XCACHE_CCR_FRCWT(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_FRCWT_SHIFT)) & XCACHE_CCR_FRCWT_MASK)

#define XCACHE_CCR_FRCNOALLC_MASK                (0x8U)
#define XCACHE_CCR_FRCNOALLC_SHIFT               (3U)
/*! FRCNOALLC - Forces No Allocation on Cache Misses
 *  0b0..Allocation on cache misses
 *  0b1..Forces no allocation on cache misses (must also have FRCWT asserted)
 */
#define XCACHE_CCR_FRCNOALLC(x)                  (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_FRCNOALLC_SHIFT)) & XCACHE_CCR_FRCNOALLC_MASK)

#define XCACHE_CCR_INVW0_MASK                    (0x1000000U)
#define XCACHE_CCR_INVW0_SHIFT                   (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..When you write 1 to GO, invalidates all lines in way 0.
 */
#define XCACHE_CCR_INVW0(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_INVW0_SHIFT)) & XCACHE_CCR_INVW0_MASK)

#define XCACHE_CCR_PUSHW0_MASK                   (0x2000000U)
#define XCACHE_CCR_PUSHW0_SHIFT                  (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..When you write 1 to GO, push all modified lines in way 0
 */
#define XCACHE_CCR_PUSHW0(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_PUSHW0_SHIFT)) & XCACHE_CCR_PUSHW0_MASK)

#define XCACHE_CCR_INVW1_MASK                    (0x4000000U)
#define XCACHE_CCR_INVW1_SHIFT                   (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..When you write 1 to GO, invalidates all lines in way 1
 */
#define XCACHE_CCR_INVW1(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_INVW1_SHIFT)) & XCACHE_CCR_INVW1_MASK)

#define XCACHE_CCR_PUSHW1_MASK                   (0x8000000U)
#define XCACHE_CCR_PUSHW1_SHIFT                  (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..When you write 1 to GO, push all modified lines in way 1
 */
#define XCACHE_CCR_PUSHW1(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_PUSHW1_SHIFT)) & XCACHE_CCR_PUSHW1_MASK)

#define XCACHE_CCR_GO_MASK                       (0x80000000U)
#define XCACHE_CCR_GO_SHIFT                      (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect. Read: no cache command active
 *  0b1..Write: initiates command; Read: cache command active
 */
#define XCACHE_CCR_GO(x)                         (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_GO_SHIFT)) & XCACHE_CCR_GO_MASK)
/*! @} */

/*! @name CLCR - Cache Line Control */
/*! @{ */

#define XCACHE_CLCR_LGO_MASK                     (0x1U)
#define XCACHE_CLCR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command. Read: line command active.
 */
#define XCACHE_CLCR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LGO_SHIFT)) & XCACHE_CLCR_LGO_MASK)

#define XCACHE_CLCR_CACHEADDR_MASK               (0x3FFCU)
#define XCACHE_CLCR_CACHEADDR_SHIFT              (2U)
/*! CACHEADDR - Cache Address */
#define XCACHE_CLCR_CACHEADDR(x)                 (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_CACHEADDR_SHIFT)) & XCACHE_CLCR_CACHEADDR_MASK)

#define XCACHE_CLCR_WSEL_MASK                    (0x4000U)
#define XCACHE_CLCR_WSEL_SHIFT                   (14U)
/*! WSEL - Way Select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define XCACHE_CLCR_WSEL(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_WSEL_SHIFT)) & XCACHE_CLCR_WSEL_MASK)

#define XCACHE_CLCR_TDSEL_MASK                   (0x10000U)
#define XCACHE_CLCR_TDSEL_SHIFT                  (16U)
/*! TDSEL - Tag or Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define XCACHE_CLCR_TDSEL(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_TDSEL_SHIFT)) & XCACHE_CLCR_TDSEL_MASK)

#define XCACHE_CLCR_LCIVB_MASK                   (0x100000U)
#define XCACHE_CLCR_LCIVB_SHIFT                  (20U)
/*! LCIVB - Line Command Initial Valid */
#define XCACHE_CLCR_LCIVB(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCIVB_SHIFT)) & XCACHE_CLCR_LCIVB_MASK)

#define XCACHE_CLCR_LCIMB_MASK                   (0x200000U)
#define XCACHE_CLCR_LCIMB_SHIFT                  (21U)
/*! LCIMB - Line Command Initial Modified */
#define XCACHE_CLCR_LCIMB(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCIMB_SHIFT)) & XCACHE_CLCR_LCIMB_MASK)

#define XCACHE_CLCR_LCWAY_MASK                   (0x400000U)
#define XCACHE_CLCR_LCWAY_SHIFT                  (22U)
/*! LCWAY - Line Command Way */
#define XCACHE_CLCR_LCWAY(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCWAY_SHIFT)) & XCACHE_CLCR_LCWAY_MASK)

#define XCACHE_CLCR_LCMD_MASK                    (0x3000000U)
#define XCACHE_CLCR_LCMD_SHIFT                   (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define XCACHE_CLCR_LCMD(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCMD_SHIFT)) & XCACHE_CLCR_LCMD_MASK)

#define XCACHE_CLCR_LADSEL_MASK                  (0x4000000U)
#define XCACHE_CLCR_LADSEL_SHIFT                 (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address
 *  0b1..Physical address
 */
#define XCACHE_CLCR_LADSEL(x)                    (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LADSEL_SHIFT)) & XCACHE_CLCR_LADSEL_MASK)

#define XCACHE_CLCR_LACC_MASK                    (0x8000000U)
#define XCACHE_CLCR_LACC_SHIFT                   (27U)
/*! LACC - Line Access Type
 *  0b0..Read
 *  0b1..Write
 */
#define XCACHE_CLCR_LACC(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LACC_SHIFT)) & XCACHE_CLCR_LACC_MASK)
/*! @} */

/*! @name CSAR - Cache Search Address */
/*! @{ */

#define XCACHE_CSAR_LGO_MASK                     (0x1U)
#define XCACHE_CSAR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command. Read: line command active.
 */
#define XCACHE_CSAR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << XCACHE_CSAR_LGO_SHIFT)) & XCACHE_CSAR_LGO_MASK)

#define XCACHE_CSAR_PHYADDR_MASK                 (0xFFFFFFFCU)
#define XCACHE_CSAR_PHYADDR_SHIFT                (2U)
/*! PHYADDR - Physical Address */
#define XCACHE_CSAR_PHYADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XCACHE_CSAR_PHYADDR_SHIFT)) & XCACHE_CSAR_PHYADDR_MASK)
/*! @} */

/*! @name CCVR - Cache Read/Write Value */
/*! @{ */

#define XCACHE_CCVR_DATA_MASK                    (0xFFFFFFFFU)
#define XCACHE_CCVR_DATA_SHIFT                   (0U)
/*! DATA - Cache Read/Write Data */
#define XCACHE_CCVR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCVR_DATA_SHIFT)) & XCACHE_CCVR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCACHE_Register_Masks */


/*!
 * @}
 */ /* end of group XCACHE_Peripheral_Access_Layer */


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


#endif  /* PERI_XCACHE_H_ */
