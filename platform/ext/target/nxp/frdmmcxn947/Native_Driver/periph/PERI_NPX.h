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
**         CMSIS Peripheral Access Layer for NPX
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
 * @file PERI_NPX.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NPX
 *
 * CMSIS Peripheral Access Layer for NPX
 */

#if !defined(PERI_NPX_H_)
#define PERI_NPX_H_                              /**< Symbol preventing repeated inclusion */

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
   -- NPX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPX_Peripheral_Access_Layer NPX Peripheral Access Layer
 * @{
 */

/** NPX - Size of Registers Arrays */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_COUNT 2u
#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_COUNT 2u
#define NPX_CTX_VALID_IV_ARRAY_COUNT              4u

/** NPX - Register Layout Typedef */
typedef struct {
  __IO uint32_t NPXCR;                             /**< NPX Control Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t NPXSR;                             /**< NPX Status Register, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __O  uint32_t CACMSK;                            /**< Flash Cache Obfuscation Mask, offset: 0x10 */
       uint8_t RESERVED_2[12];
  __IO uint32_t REMAP;                             /**< Data Remap, offset: 0x20 */
       uint8_t RESERVED_3[28];
  struct {                                         /* offset: 0x40, array step: 0x10 */
    __IO uint32_t VMAPCTX_WD[NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_COUNT];   /**< Bitmap of Valid Control for Memory Context 0..Bitmap of Valid Control for Memory Context 3, array offset: 0x40, array step: index*0x10, index2*0x4 */
    __O  uint32_t BIVCTX_WD[NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_COUNT];   /**< Block Initial Vector for Memory Context 0..Block Initial Vector for Memory Context 3, array offset: 0x48, array step: index*0x10, index2*0x4 */
  } CTX_VALID_IV_ARRAY[NPX_CTX_VALID_IV_ARRAY_COUNT];
} NPX_Type;

/* ----------------------------------------------------------------------------
   -- NPX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPX_Register_Masks NPX Register Masks
 * @{
 */

/*! @name NPXCR - NPX Control Register */
/*! @{ */

#define NPX_NPXCR_GEE_MASK                       (0x1U)
#define NPX_NPXCR_GEE_SHIFT                      (0U)
/*! GEE - Global Encryption Enable
 *  0b0..Global encryption disabled. NPX on-the-fly encryption is disabled. Subsequent reads return 0.
 *  0b1..Global encryption enabled. NPX on-the-fly encryption is enabled if the flash access hits in a valid
 *       memory context. Subsequent reads return 1.
 */
#define NPX_NPXCR_GEE(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GEE_SHIFT)) & NPX_NPXCR_GEE_MASK)

#define NPX_NPXCR_GDE_MASK                       (0x4U)
#define NPX_NPXCR_GDE_SHIFT                      (2U)
/*! GDE - Global Decryption Enable
 *  0b0..Global decryption disabled. NPX on-the-fly decryption is globally disabled. Subsequent reads return 0.
 *  0b1..Global decryption enabled. NPX on-the-fly decryption is globally enabled. Subsequent reads return 1.
 */
#define NPX_NPXCR_GDE(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GDE_SHIFT)) & NPX_NPXCR_GDE_MASK)

#define NPX_NPXCR_GLK_MASK                       (0x10U)
#define NPX_NPXCR_GLK_SHIFT                      (4U)
/*! GLK - Global Lock Enable
 *  0b0..Lock disabled. Subsequent reads return 0.
 *  0b1..Lock enabled: cannot write to VMAPCTXn, NPXCR, or CACMSK. Subsequent reads return 1.
 */
#define NPX_NPXCR_GLK(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GLK_SHIFT)) & NPX_NPXCR_GLK_MASK)

#define NPX_NPXCR_MLK_MASK                       (0x40U)
#define NPX_NPXCR_MLK_SHIFT                      (6U)
/*! MLK - Mask Lock Enable
 *  0b0..Lock disabled. Subsequent reads return 0.
 *  0b1..Lock enabled: cannot write to mask. Subsequent reads return 1.
 */
#define NPX_NPXCR_MLK(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_MLK_SHIFT)) & NPX_NPXCR_MLK_MASK)

#define NPX_NPXCR_CTX0LK_MASK                    (0x100U)
#define NPX_NPXCR_CTX0LK_SHIFT                   (8U)
/*! CTX0LK - Lock Enable for Context 0
 *  0b0..Lock disabled: VMAPCTX0 remains read-write
 *  0b1..Lock enabled: cannot write to VMAPCTX0 (becomes read-only)
 */
#define NPX_NPXCR_CTX0LK(x)                      (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_CTX0LK_SHIFT)) & NPX_NPXCR_CTX0LK_MASK)

#define NPX_NPXCR_CTX1LK_MASK                    (0x400U)
#define NPX_NPXCR_CTX1LK_SHIFT                   (10U)
/*! CTX1LK - Lock Enable for Context 1
 *  0b0..Lock disabled: VMAPCTX1 remains read-write
 *  0b1..Lock enabled: cannot write to VMAPCTX1 (becomes read-only)
 */
#define NPX_NPXCR_CTX1LK(x)                      (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_CTX1LK_SHIFT)) & NPX_NPXCR_CTX1LK_MASK)

#define NPX_NPXCR_CTX2LK_MASK                    (0x1000U)
#define NPX_NPXCR_CTX2LK_SHIFT                   (12U)
/*! CTX2LK - Lock Enable for Context 2
 *  0b0..Lock disabled: VMAPCTX2 remains read-write
 *  0b1..Lock enabled: cannot write to VMAPCTX2 (becomes read-only)
 */
#define NPX_NPXCR_CTX2LK(x)                      (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_CTX2LK_SHIFT)) & NPX_NPXCR_CTX2LK_MASK)

#define NPX_NPXCR_CTX3LK_MASK                    (0x4000U)
#define NPX_NPXCR_CTX3LK_SHIFT                   (14U)
/*! CTX3LK - Lock Enable for Context 3
 *  0b0..Lock disabled: VMAPCTX3 remains read-write
 *  0b1..Lock enabled: cannot write to VMAPCTX3 (becomes read-only)
 */
#define NPX_NPXCR_CTX3LK(x)                      (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_CTX3LK_SHIFT)) & NPX_NPXCR_CTX3LK_MASK)
/*! @} */

/*! @name NPXSR - NPX Status Register */
/*! @{ */

#define NPX_NPXSR_NUMCTX_MASK                    (0xFU)
#define NPX_NPXSR_NUMCTX_SHIFT                   (0U)
/*! NUMCTX - Number of implemented memory contexts
 *  0b0000..No (zero) implemented memory contexts
 *  0b0001..1 implemented memory contexts
 *  0b0010..2 implemented memory contexts
 *  0b0011..3 implemented memory contexts
 *  0b0100..4 implemented memory contexts
 */
#define NPX_NPXSR_NUMCTX(x)                      (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_NUMCTX_SHIFT)) & NPX_NPXSR_NUMCTX_MASK)

#define NPX_NPXSR_V0_MASK                        (0x100U)
#define NPX_NPXSR_V0_SHIFT                       (8U)
/*! V0 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V0(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V0_SHIFT)) & NPX_NPXSR_V0_MASK)

#define NPX_NPXSR_V1_MASK                        (0x200U)
#define NPX_NPXSR_V1_SHIFT                       (9U)
/*! V1 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V1(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V1_SHIFT)) & NPX_NPXSR_V1_MASK)

#define NPX_NPXSR_V2_MASK                        (0x400U)
#define NPX_NPXSR_V2_SHIFT                       (10U)
/*! V2 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V2(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V2_SHIFT)) & NPX_NPXSR_V2_MASK)

#define NPX_NPXSR_V3_MASK                        (0x800U)
#define NPX_NPXSR_V3_SHIFT                       (11U)
/*! V3 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V3(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V3_SHIFT)) & NPX_NPXSR_V3_MASK)
/*! @} */

/*! @name CACMSK - Flash Cache Obfuscation Mask */
/*! @{ */

#define NPX_CACMSK_OBMASK_MASK                   (0xFFFFFFFFU)
#define NPX_CACMSK_OBMASK_SHIFT                  (0U)
/*! OBMASK - Obfuscation Mask */
#define NPX_CACMSK_OBMASK(x)                     (((uint32_t)(((uint32_t)(x)) << NPX_CACMSK_OBMASK_SHIFT)) & NPX_CACMSK_OBMASK_MASK)
/*! @} */

/*! @name REMAP - Data Remap */
/*! @{ */

#define NPX_REMAP_REMAPLK_MASK                   (0x1U)
#define NPX_REMAP_REMAPLK_SHIFT                  (0U)
/*! REMAPLK - Remap Lock Enable
 *  0b0..Lock disabled: can write to REMAP
 *  0b1..Lock enabled: cannot write to REMAP
 */
#define NPX_REMAP_REMAPLK(x)                     (((uint32_t)(((uint32_t)(x)) << NPX_REMAP_REMAPLK_SHIFT)) & NPX_REMAP_REMAPLK_MASK)

#define NPX_REMAP_LIM_MASK                       (0x1F0000U)
#define NPX_REMAP_LIM_SHIFT                      (16U)
/*! LIM - LIM Remapping Address */
#define NPX_REMAP_LIM(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_REMAP_LIM_SHIFT)) & NPX_REMAP_LIM_MASK)

#define NPX_REMAP_LIMDP_MASK                     (0x1F000000U)
#define NPX_REMAP_LIMDP_SHIFT                    (24U)
/*! LIMDP - LIMDP Remapping Address */
#define NPX_REMAP_LIMDP(x)                       (((uint32_t)(((uint32_t)(x)) << NPX_REMAP_LIMDP_SHIFT)) & NPX_REMAP_LIMDP_MASK)
/*! @} */

/*! @name CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD - Bitmap of Valid Control for Memory Context 0..Bitmap of Valid Control for Memory Context 3 */
/*! @{ */

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL0_MASK (0x1U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL0_SHIFT (0U)
/*! VAL0 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL0(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL0_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL0_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL32_MASK (0x1U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL32_SHIFT (0U)
/*! VAL32 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL32(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL32_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL32_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL1_MASK (0x2U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL1_SHIFT (1U)
/*! VAL1 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL1(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL1_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL1_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL33_MASK (0x2U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL33_SHIFT (1U)
/*! VAL33 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL33(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL33_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL33_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL2_MASK (0x4U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL2_SHIFT (2U)
/*! VAL2 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL2(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL2_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL2_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL34_MASK (0x4U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL34_SHIFT (2U)
/*! VAL34 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL34(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL34_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL34_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL3_MASK (0x8U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL3_SHIFT (3U)
/*! VAL3 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL3(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL3_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL3_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL35_MASK (0x8U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL35_SHIFT (3U)
/*! VAL35 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL35(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL35_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL35_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL4_MASK (0x10U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL4_SHIFT (4U)
/*! VAL4 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL4(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL4_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL4_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL36_MASK (0x10U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL36_SHIFT (4U)
/*! VAL36 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL36(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL36_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL36_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL5_MASK (0x20U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL5_SHIFT (5U)
/*! VAL5 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL5(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL5_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL5_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL37_MASK (0x20U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL37_SHIFT (5U)
/*! VAL37 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL37(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL37_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL37_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL6_MASK (0x40U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL6_SHIFT (6U)
/*! VAL6 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL6(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL6_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL6_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL38_MASK (0x40U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL38_SHIFT (6U)
/*! VAL38 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL38(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL38_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL38_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL7_MASK (0x80U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL7_SHIFT (7U)
/*! VAL7 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL7(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL7_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL7_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL39_MASK (0x80U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL39_SHIFT (7U)
/*! VAL39 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL39(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL39_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL39_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL8_MASK (0x100U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL8_SHIFT (8U)
/*! VAL8 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL8(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL8_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL8_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL40_MASK (0x100U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL40_SHIFT (8U)
/*! VAL40 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL40(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL40_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL40_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL9_MASK (0x200U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL9_SHIFT (9U)
/*! VAL9 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL9(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL9_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL9_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL41_MASK (0x200U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL41_SHIFT (9U)
/*! VAL41 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL41(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL41_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL41_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL10_MASK (0x400U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL10_SHIFT (10U)
/*! VAL10 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL10(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL10_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL10_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL42_MASK (0x400U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL42_SHIFT (10U)
/*! VAL42 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL42(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL42_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL42_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL11_MASK (0x800U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL11_SHIFT (11U)
/*! VAL11 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL11(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL11_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL11_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL43_MASK (0x800U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL43_SHIFT (11U)
/*! VAL43 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL43(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL43_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL43_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL12_MASK (0x1000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL12_SHIFT (12U)
/*! VAL12 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL12(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL12_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL12_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL44_MASK (0x1000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL44_SHIFT (12U)
/*! VAL44 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL44(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL44_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL44_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL13_MASK (0x2000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL13_SHIFT (13U)
/*! VAL13 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL13(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL13_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL13_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL45_MASK (0x2000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL45_SHIFT (13U)
/*! VAL45 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL45(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL45_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL45_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL14_MASK (0x4000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL14_SHIFT (14U)
/*! VAL14 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL14(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL14_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL14_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL46_MASK (0x4000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL46_SHIFT (14U)
/*! VAL46 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL46(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL46_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL46_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL15_MASK (0x8000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL15_SHIFT (15U)
/*! VAL15 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL15(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL15_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL15_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL47_MASK (0x8000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL47_SHIFT (15U)
/*! VAL47 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL47(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL47_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL47_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL16_MASK (0x10000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL16_SHIFT (16U)
/*! VAL16 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL16(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL16_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL16_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL48_MASK (0x10000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL48_SHIFT (16U)
/*! VAL48 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL48(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL48_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL48_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL17_MASK (0x20000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL17_SHIFT (17U)
/*! VAL17 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL17(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL17_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL17_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL49_MASK (0x20000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL49_SHIFT (17U)
/*! VAL49 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL49(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL49_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL49_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL18_MASK (0x40000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL18_SHIFT (18U)
/*! VAL18 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL18(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL18_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL18_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL50_MASK (0x40000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL50_SHIFT (18U)
/*! VAL50 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL50(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL50_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL50_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL19_MASK (0x80000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL19_SHIFT (19U)
/*! VAL19 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL19(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL19_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL19_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL51_MASK (0x80000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL51_SHIFT (19U)
/*! VAL51 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL51(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL51_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL51_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL20_MASK (0x100000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL20_SHIFT (20U)
/*! VAL20 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL20(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL20_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL20_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL52_MASK (0x100000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL52_SHIFT (20U)
/*! VAL52 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL52(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL52_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL52_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL21_MASK (0x200000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL21_SHIFT (21U)
/*! VAL21 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL21(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL21_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL21_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL53_MASK (0x200000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL53_SHIFT (21U)
/*! VAL53 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL53(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL53_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL53_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL22_MASK (0x400000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL22_SHIFT (22U)
/*! VAL22 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL22(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL22_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL22_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL54_MASK (0x400000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL54_SHIFT (22U)
/*! VAL54 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL54(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL54_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL54_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL23_MASK (0x800000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL23_SHIFT (23U)
/*! VAL23 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL23(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL23_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL23_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL55_MASK (0x800000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL55_SHIFT (23U)
/*! VAL55 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL55(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL55_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL55_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL24_MASK (0x1000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL24_SHIFT (24U)
/*! VAL24 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL24(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL24_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL24_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL56_MASK (0x1000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL56_SHIFT (24U)
/*! VAL56 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL56(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL56_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL56_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL25_MASK (0x2000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL25_SHIFT (25U)
/*! VAL25 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL25(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL25_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL25_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL57_MASK (0x2000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL57_SHIFT (25U)
/*! VAL57 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL57(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL57_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL57_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL26_MASK (0x4000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL26_SHIFT (26U)
/*! VAL26 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL26(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL26_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL26_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL58_MASK (0x4000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL58_SHIFT (26U)
/*! VAL58 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL58(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL58_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL58_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL27_MASK (0x8000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL27_SHIFT (27U)
/*! VAL27 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL27(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL27_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL27_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL59_MASK (0x8000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL59_SHIFT (27U)
/*! VAL59 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL59(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL59_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL59_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL28_MASK (0x10000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL28_SHIFT (28U)
/*! VAL28 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL28(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL28_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL28_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL60_MASK (0x10000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL60_SHIFT (28U)
/*! VAL60 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL60(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL60_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL60_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL29_MASK (0x20000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL29_SHIFT (29U)
/*! VAL29 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL29(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL29_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL29_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL61_MASK (0x20000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL61_SHIFT (29U)
/*! VAL61 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL61(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL61_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL61_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL30_MASK (0x40000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL30_SHIFT (30U)
/*! VAL30 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL30(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL30_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL30_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL62_MASK (0x40000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL62_SHIFT (30U)
/*! VAL62 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL62(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL62_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL62_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL31_MASK (0x80000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL31_SHIFT (31U)
/*! VAL31 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL31(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL31_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL31_MASK)

#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL63_MASK (0x80000000U)
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL63_SHIFT (31U)
/*! VAL63 - Block valid enable for encryption/decryption
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL63(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL63_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_VAL63_MASK)
/*! @} */

/* The count of NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_COUNT (4U)

/* The count of NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD */
#define NPX_CTX_VALID_IV_ARRAY_VMAPCTX_ARRAY_VMAPCTX_WD_COUNT2 (2U)

/*! @name CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD - Block Initial Vector for Memory Context 0..Block Initial Vector for Memory Context 3 */
/*! @{ */

#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD0_MASK (0xFFFFFFFFU)
#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD0_SHIFT (0U)
/*! BIV_WD0 - Block Initial Vector Word0 */
#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD0(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD0_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD0_MASK)

#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD1_MASK (0xFFFFFFFFU)
#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD1_SHIFT (0U)
/*! BIV_WD1 - Block Initial Vector Word1 */
#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD1(x) (((uint32_t)(((uint32_t)(x)) << NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD1_SHIFT)) & NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_BIV_WD1_MASK)
/*! @} */

/* The count of NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD */
#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_COUNT (4U)

/* The count of NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD */
#define NPX_CTX_VALID_IV_ARRAY_BIVCTX_ARRAY_BIVCTX_WD_COUNT2 (2U)


/*!
 * @}
 */ /* end of group NPX_Register_Masks */


/*!
 * @}
 */ /* end of group NPX_Peripheral_Access_Layer */


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


#endif  /* PERI_NPX_H_ */

