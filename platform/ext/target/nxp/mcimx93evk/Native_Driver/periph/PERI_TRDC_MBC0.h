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
**         CMSIS Peripheral Access Layer for TRDC_MBC0
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
 * @file PERI_TRDC_MBC0.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRDC_MBC0
 *
 * CMSIS Peripheral Access Layer for TRDC_MBC0
 */

#if !defined(PERI_TRDC_MBC0_H_)
#define PERI_TRDC_MBC0_H_                        /**< Symbol preventing repeated inclusion */

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
   -- TRDC_MBC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_MBC0_Peripheral_Access_Layer TRDC_MBC0 Peripheral Access Layer
 * @{
 */

/** TRDC_MBC0 - Size of Registers Arrays */
#define TRDC_MBC0_DACFG_COUNT                     7u
#define TRDC_MBC0_DERRLOC_COUNT                   16u
#define TRDC_MBC0_MDA_Wx_y_DFMT_MDA_W_DFMT_DFMT1_MDA_Wx_DFMT1_COUNT 1u
#define TRDC_MBC0_MDA_Wx_y_DFMT_COUNT             7u

/** TRDC_MBC0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRDC_CR;                           /**< TRDC Register, offset: 0x0 */
       uint8_t RESERVED_0[236];
  __I  uint32_t TRDC_HWCFG0;                       /**< TRDC Hardware Configuration Register 0, offset: 0xF0 */
  __I  uint32_t TRDC_HWCFG1;                       /**< TRDC Hardware Configuration Register 1, offset: 0xF4 */
       uint8_t RESERVED_1[8];
  __I  uint8_t DACFG[TRDC_MBC0_DACFG_COUNT];       /**< Domain Assignment Configuration Register, array offset: 0x100, array step: 0x1, irregular array, not all indices are valid */
       uint8_t RESERVED_2[185];
  __IO uint32_t TRDC_IDAU_CR;                      /**< TRDC IDAU Control Register, offset: 0x1C0 */
       uint8_t RESERVED_3[28];
  __IO uint32_t TRDC_FLW_CTL;                      /**< TRDC FLW Control, offset: 0x1E0 */
  __I  uint32_t TRDC_FLW_PBASE;                    /**< TRDC FLW Physical Base, offset: 0x1E4 */
  __IO uint32_t TRDC_FLW_ABASE;                    /**< TRDC FLW Array Base, offset: 0x1E8 */
  __IO uint32_t TRDC_FLW_BCNT;                     /**< TRDC FLW Block Count, offset: 0x1EC */
       uint8_t RESERVED_4[12];
  __IO uint32_t TRDC_FDID;                         /**< TRDC Fault Domain ID, offset: 0x1FC */
  __I  uint32_t TRDC_DERRLOC[TRDC_MBC0_DERRLOC_COUNT]; /**< TRDC Domain Error Location Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_5[1472];
  struct {                                         /* offset: 0x800, array step: 0x20 */
    struct {                                         /* offset: 0x800, array step: index*0x20, index2*0x4 */
      __IO uint32_t MDA_W_DFMT1;                       /**< DAC Master Domain Assignment Register, array offset: 0x800, array step: index*0x20, index2*0x4, irregular array, not all indices are valid */
    } MDA_Wx_DFMT1[TRDC_MBC0_MDA_Wx_y_DFMT_MDA_W_DFMT_DFMT1_MDA_Wx_DFMT1_COUNT];
         uint8_t RESERVED_0[28];
  } MDA_Wx_y_DFMT[TRDC_MBC0_MDA_Wx_y_DFMT_COUNT];
} TRDC_MBC0_Type;

/* ----------------------------------------------------------------------------
   -- TRDC_MBC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_MBC0_Register_Masks TRDC_MBC0 Register Masks
 * @{
 */

/*! @name TRDC_CR - TRDC Register */
/*! @{ */

#define TRDC_MBC0_TRDC_CR_GVLDM_MASK             (0x1U)
#define TRDC_MBC0_TRDC_CR_GVLDM_SHIFT            (0U)
/*! GVLDM - Global Valid for Domain Assignment Controllers
 *  0b0..TRDC DACs are disabled.
 *  0b1..TRDC DACs are enabled.
 */
#define TRDC_MBC0_TRDC_CR_GVLDM(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_CR_GVLDM_SHIFT)) & TRDC_MBC0_TRDC_CR_GVLDM_MASK)

#define TRDC_MBC0_TRDC_CR_HRL_MASK               (0x1EU)
#define TRDC_MBC0_TRDC_CR_HRL_SHIFT              (1U)
/*! HRL - Hardware Revision Level */
#define TRDC_MBC0_TRDC_CR_HRL(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_CR_HRL_SHIFT)) & TRDC_MBC0_TRDC_CR_HRL_MASK)

#define TRDC_MBC0_TRDC_CR_GVLDB_MASK             (0x4000U)
#define TRDC_MBC0_TRDC_CR_GVLDB_SHIFT            (14U)
/*! GVLDB - Global Valid for Memory Block Checkers
 *  0b0..TRDC MBCs are disabled.
 *  0b1..TRDC MBCs are enabled.
 */
#define TRDC_MBC0_TRDC_CR_GVLDB(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_CR_GVLDB_SHIFT)) & TRDC_MBC0_TRDC_CR_GVLDB_MASK)

#define TRDC_MBC0_TRDC_CR_GVLDR_MASK             (0x8000U)
#define TRDC_MBC0_TRDC_CR_GVLDR_SHIFT            (15U)
/*! GVLDR - Global Valid for Memory Region Checkers
 *  0b0..TRDC MRCs are disabled.
 *  0b1..TRDC MRCs are enabled.
 */
#define TRDC_MBC0_TRDC_CR_GVLDR(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_CR_GVLDR_SHIFT)) & TRDC_MBC0_TRDC_CR_GVLDR_MASK)

#define TRDC_MBC0_TRDC_CR_LK1_MASK               (0x40000000U)
#define TRDC_MBC0_TRDC_CR_LK1_SHIFT              (30U)
/*! LK1 - Lock Status
 *  0b0..The CR can be written by any secure privileged write.
 *  0b1..The CR is locked (read-only) until the next reset.
 */
#define TRDC_MBC0_TRDC_CR_LK1(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_CR_LK1_SHIFT)) & TRDC_MBC0_TRDC_CR_LK1_MASK)
/*! @} */

/*! @name TRDC_HWCFG0 - TRDC Hardware Configuration Register 0 */
/*! @{ */

#define TRDC_MBC0_TRDC_HWCFG0_NDID_MASK          (0x1FU)
#define TRDC_MBC0_TRDC_HWCFG0_NDID_SHIFT         (0U)
/*! NDID - Number of domains */
#define TRDC_MBC0_TRDC_HWCFG0_NDID(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_HWCFG0_NDID_SHIFT)) & TRDC_MBC0_TRDC_HWCFG0_NDID_MASK)

#define TRDC_MBC0_TRDC_HWCFG0_NMSTR_MASK         (0xFF00U)
#define TRDC_MBC0_TRDC_HWCFG0_NMSTR_SHIFT        (8U)
/*! NMSTR - Number of bus masters */
#define TRDC_MBC0_TRDC_HWCFG0_NMSTR(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_HWCFG0_NMSTR_SHIFT)) & TRDC_MBC0_TRDC_HWCFG0_NMSTR_MASK)

#define TRDC_MBC0_TRDC_HWCFG0_NMBC_MASK          (0xF0000U)
#define TRDC_MBC0_TRDC_HWCFG0_NMBC_SHIFT         (16U)
/*! NMBC - Number of MBCs */
#define TRDC_MBC0_TRDC_HWCFG0_NMBC(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_HWCFG0_NMBC_SHIFT)) & TRDC_MBC0_TRDC_HWCFG0_NMBC_MASK)

#define TRDC_MBC0_TRDC_HWCFG0_NMRC_MASK          (0x1F000000U)
#define TRDC_MBC0_TRDC_HWCFG0_NMRC_SHIFT         (24U)
/*! NMRC - Number of MRCs */
#define TRDC_MBC0_TRDC_HWCFG0_NMRC(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_HWCFG0_NMRC_SHIFT)) & TRDC_MBC0_TRDC_HWCFG0_NMRC_MASK)

#define TRDC_MBC0_TRDC_HWCFG0_MID_MASK           (0xE0000000U)
#define TRDC_MBC0_TRDC_HWCFG0_MID_SHIFT          (29U)
/*! MID - Module ID */
#define TRDC_MBC0_TRDC_HWCFG0_MID(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_HWCFG0_MID_SHIFT)) & TRDC_MBC0_TRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name TRDC_HWCFG1 - TRDC Hardware Configuration Register 1 */
/*! @{ */

#define TRDC_MBC0_TRDC_HWCFG1_DID_MASK           (0xFU)
#define TRDC_MBC0_TRDC_HWCFG1_DID_SHIFT          (0U)
/*! DID - Domain identifier number */
#define TRDC_MBC0_TRDC_HWCFG1_DID(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_HWCFG1_DID_SHIFT)) & TRDC_MBC0_TRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name DACFG - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MBC0_DACFG_NMDAR_MASK               (0xFU)
#define TRDC_MBC0_DACFG_NMDAR_SHIFT              (0U)
/*! NMDAR - Number of master domain assignment registers for bus master m */
#define TRDC_MBC0_DACFG_NMDAR(x)                 (((uint8_t)(((uint8_t)(x)) << TRDC_MBC0_DACFG_NMDAR_SHIFT)) & TRDC_MBC0_DACFG_NMDAR_MASK)

#define TRDC_MBC0_DACFG_NCM_MASK                 (0x80U)
#define TRDC_MBC0_DACFG_NCM_SHIFT                (7U)
/*! NCM - Non-CPU Master
 *  0b0..Bus master is a processor.
 *  0b1..Bus master is a non-processor.
 */
#define TRDC_MBC0_DACFG_NCM(x)                   (((uint8_t)(((uint8_t)(x)) << TRDC_MBC0_DACFG_NCM_SHIFT)) & TRDC_MBC0_DACFG_NCM_MASK)
/*! @} */

/*! @name TRDC_IDAU_CR - TRDC IDAU Control Register */
/*! @{ */

#define TRDC_MBC0_TRDC_IDAU_CR_VLD_MASK          (0x1U)
#define TRDC_MBC0_TRDC_IDAU_CR_VLD_SHIFT         (0U)
/*! VLD - Valid */
#define TRDC_MBC0_TRDC_IDAU_CR_VLD(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_VLD_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_VLD_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_CFGSECEXT_MASK    (0x8U)
#define TRDC_MBC0_TRDC_IDAU_CR_CFGSECEXT_SHIFT   (3U)
/*! CFGSECEXT - Configure Security Extension
 *  0b0..ARMv8M Security Extension is disabled
 *  0b1..ARMv8-M Security Extension is enabled
 */
#define TRDC_MBC0_TRDC_IDAU_CR_CFGSECEXT(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_CFGSECEXT_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_CFGSECEXT_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_MPUSDIS_MASK      (0x10U)
#define TRDC_MBC0_TRDC_IDAU_CR_MPUSDIS_SHIFT     (4U)
/*! MPUSDIS - Secure Memory Protection Unit Disabled
 *  0b0..Secure MPU is enabled
 *  0b1..Secure MPU is disabled
 */
#define TRDC_MBC0_TRDC_IDAU_CR_MPUSDIS(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_MPUSDIS_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_MPUSDIS_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_MPUNSDIS_MASK     (0x20U)
#define TRDC_MBC0_TRDC_IDAU_CR_MPUNSDIS_SHIFT    (5U)
/*! MPUNSDIS - NonSecure Memory Protection Unit Disabled
 *  0b0..Nonsecure MPU is enabled
 *  0b1..Nonsecure MPU is disabled
 */
#define TRDC_MBC0_TRDC_IDAU_CR_MPUNSDIS(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_MPUNSDIS_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_MPUNSDIS_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_SAUDIS_MASK       (0x40U)
#define TRDC_MBC0_TRDC_IDAU_CR_SAUDIS_SHIFT      (6U)
/*! SAUDIS - Security Attribution Unit Disable
 *  0b0..SAU is enabled
 *  0b1..SAU is disabled
 */
#define TRDC_MBC0_TRDC_IDAU_CR_SAUDIS(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_SAUDIS_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_SAUDIS_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_LKSVTAIRCR_MASK   (0x100U)
#define TRDC_MBC0_TRDC_IDAU_CR_LKSVTAIRCR_SHIFT  (8U)
/*! LKSVTAIRCR - Lock Secure VTOR, Application interrupt and Reset Control Registers
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the VTOR_S, AIRCR[PRIS], and AIRCR[BFHFNMINS] registers
 */
#define TRDC_MBC0_TRDC_IDAU_CR_LKSVTAIRCR(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_LKSVTAIRCR_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_LKSVTAIRCR_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_LKNSVTOR_MASK     (0x200U)
#define TRDC_MBC0_TRDC_IDAU_CR_LKNSVTOR_SHIFT    (9U)
/*! LKNSVTOR - Lock Nonsecure Vector Table Offset Register
 *  0b0..Unlock this register
 *  0b1..Disable writes to the VTOR_NS register
 */
#define TRDC_MBC0_TRDC_IDAU_CR_LKNSVTOR(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_LKNSVTOR_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_LKNSVTOR_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_LKSMPU_MASK       (0x400U)
#define TRDC_MBC0_TRDC_IDAU_CR_LKSMPU_SHIFT      (10U)
/*! LKSMPU - Lock Secure MPU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_An and MPU_RLAR_An from software or
 *       from a debug agent connected to the processor in Secure state
 */
#define TRDC_MBC0_TRDC_IDAU_CR_LKSMPU(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_LKSMPU_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_LKSMPU_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_LKNSMPU_MASK      (0x800U)
#define TRDC_MBC0_TRDC_IDAU_CR_LKNSMPU_SHIFT     (11U)
/*! LKNSMPU - Lock Nonsecure MPU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the MPU_CTRL_NS, MPU_RNR_NS, MPU_RBAR_NS, MPU_RLAR_NS, MPU_RBAR_A_NSn and
 *       MPU_RLAR_A_NSn from software or from a debug agent connected to the processor
 */
#define TRDC_MBC0_TRDC_IDAU_CR_LKNSMPU(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_LKNSMPU_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_LKNSMPU_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_LKSAU_MASK        (0x1000U)
#define TRDC_MBC0_TRDC_IDAU_CR_LKSAU_SHIFT       (12U)
/*! LKSAU - Lock SAU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the SAU_CTRL, SAU_RNR, SAU_RBAR and SAU_RLAR registers from software or from a debug agent connected to the processor
 */
#define TRDC_MBC0_TRDC_IDAU_CR_LKSAU(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_LKSAU_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_LKSAU_MASK)

#define TRDC_MBC0_TRDC_IDAU_CR_PCURRNS_MASK      (0x80000000U)
#define TRDC_MBC0_TRDC_IDAU_CR_PCURRNS_SHIFT     (31U)
/*! PCURRNS - Processor current security
 *  0b0..Processor is in Secure state
 *  0b1..Processor is in Nonsecure state
 */
#define TRDC_MBC0_TRDC_IDAU_CR_PCURRNS(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_IDAU_CR_PCURRNS_SHIFT)) & TRDC_MBC0_TRDC_IDAU_CR_PCURRNS_MASK)
/*! @} */

/*! @name TRDC_FLW_CTL - TRDC FLW Control */
/*! @{ */

#define TRDC_MBC0_TRDC_FLW_CTL_LK_MASK           (0x40000000U)
#define TRDC_MBC0_TRDC_FLW_CTL_LK_SHIFT          (30U)
/*! LK - Lock bit
 *  0b0..FLW registers may be modified.
 *  0b1..FLW registers are locked until the next reset.
 */
#define TRDC_MBC0_TRDC_FLW_CTL_LK(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_FLW_CTL_LK_SHIFT)) & TRDC_MBC0_TRDC_FLW_CTL_LK_MASK)

#define TRDC_MBC0_TRDC_FLW_CTL_V_MASK            (0x80000000U)
#define TRDC_MBC0_TRDC_FLW_CTL_V_SHIFT           (31U)
/*! V - Valid bit
 *  0b0..FLW function is disabled.
 *  0b1..FLW function is enabled.
 */
#define TRDC_MBC0_TRDC_FLW_CTL_V(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_FLW_CTL_V_SHIFT)) & TRDC_MBC0_TRDC_FLW_CTL_V_MASK)
/*! @} */

/*! @name TRDC_FLW_PBASE - TRDC FLW Physical Base */
/*! @{ */

#define TRDC_MBC0_TRDC_FLW_PBASE_PBASE_MASK      (0xFFFFFFFFU)
#define TRDC_MBC0_TRDC_FLW_PBASE_PBASE_SHIFT     (0U)
/*! PBASE - Physical base address */
#define TRDC_MBC0_TRDC_FLW_PBASE_PBASE(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_FLW_PBASE_PBASE_SHIFT)) & TRDC_MBC0_TRDC_FLW_PBASE_PBASE_MASK)
/*! @} */

/*! @name TRDC_FLW_ABASE - TRDC FLW Array Base */
/*! @{ */

#define TRDC_MBC0_TRDC_FLW_ABASE_ABASE_L_MASK    (0x3F8000U)
#define TRDC_MBC0_TRDC_FLW_ABASE_ABASE_L_SHIFT   (15U)
/*! ABASE_L - Array base address low */
#define TRDC_MBC0_TRDC_FLW_ABASE_ABASE_L(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_FLW_ABASE_ABASE_L_SHIFT)) & TRDC_MBC0_TRDC_FLW_ABASE_ABASE_L_MASK)

#define TRDC_MBC0_TRDC_FLW_ABASE_ABASE_H_MASK    (0xFFC00000U)
#define TRDC_MBC0_TRDC_FLW_ABASE_ABASE_H_SHIFT   (22U)
/*! ABASE_H - Array base address high */
#define TRDC_MBC0_TRDC_FLW_ABASE_ABASE_H(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_FLW_ABASE_ABASE_H_SHIFT)) & TRDC_MBC0_TRDC_FLW_ABASE_ABASE_H_MASK)
/*! @} */

/*! @name TRDC_FLW_BCNT - TRDC FLW Block Count */
/*! @{ */

#define TRDC_MBC0_TRDC_FLW_BCNT_BCNT_MASK        (0x7FFFU)
#define TRDC_MBC0_TRDC_FLW_BCNT_BCNT_SHIFT       (0U)
/*! BCNT - Block Count */
#define TRDC_MBC0_TRDC_FLW_BCNT_BCNT(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_FLW_BCNT_BCNT_SHIFT)) & TRDC_MBC0_TRDC_FLW_BCNT_BCNT_MASK)
/*! @} */

/*! @name TRDC_FDID - TRDC Fault Domain ID */
/*! @{ */

#define TRDC_MBC0_TRDC_FDID_FDID_MASK            (0xFU)
#define TRDC_MBC0_TRDC_FDID_FDID_SHIFT           (0U)
/*! FDID - Domain ID of Faulted Access */
#define TRDC_MBC0_TRDC_FDID_FDID(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_FDID_FDID_SHIFT)) & TRDC_MBC0_TRDC_FDID_FDID_MASK)
/*! @} */

/*! @name TRDC_DERRLOC - TRDC Domain Error Location Register */
/*! @{ */

#define TRDC_MBC0_TRDC_DERRLOC_MBCINST_MASK      (0xFFU)
#define TRDC_MBC0_TRDC_DERRLOC_MBCINST_SHIFT     (0U)
/*! MBCINST - MBC instance */
#define TRDC_MBC0_TRDC_DERRLOC_MBCINST(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_DERRLOC_MBCINST_SHIFT)) & TRDC_MBC0_TRDC_DERRLOC_MBCINST_MASK)

#define TRDC_MBC0_TRDC_DERRLOC_MRCINST_MASK      (0xFFFF0000U)
#define TRDC_MBC0_TRDC_DERRLOC_MRCINST_SHIFT     (16U)
/*! MRCINST - MRC instance */
#define TRDC_MBC0_TRDC_DERRLOC_MRCINST(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_TRDC_DERRLOC_MRCINST_SHIFT)) & TRDC_MBC0_TRDC_DERRLOC_MRCINST_MASK)
/*! @} */

/* The count of TRDC_MBC0_TRDC_DERRLOC */
#define TRDC_MBC0_TRDC_DERRLOC_COUNT             (16U)

/*! @name MDA_W_DFMT1 - DAC Master Domain Assignment Register */
/*! @{ */

#define TRDC_MBC0_MDA_W_DFMT1_DID_MASK           (0xFU)
#define TRDC_MBC0_MDA_W_DFMT1_DID_SHIFT          (0U)
/*! DID - Domain identifier */
#define TRDC_MBC0_MDA_W_DFMT1_DID(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_MDA_W_DFMT1_DID_SHIFT)) & TRDC_MBC0_MDA_W_DFMT1_DID_MASK)

#define TRDC_MBC0_MDA_W_DFMT1_PA_MASK            (0x30U)
#define TRDC_MBC0_MDA_W_DFMT1_PA_SHIFT           (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this master to user.
 *  0b01..Force the bus attribute for this master to privileged.
 *  0b10..Use the bus master's privileged/user attribute directly.
 *  0b11..Use the bus master's privileged/user attribute directly.
 */
#define TRDC_MBC0_MDA_W_DFMT1_PA(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_MDA_W_DFMT1_PA_SHIFT)) & TRDC_MBC0_MDA_W_DFMT1_PA_MASK)

#define TRDC_MBC0_MDA_W_DFMT1_SA_MASK            (0xC0U)
#define TRDC_MBC0_MDA_W_DFMT1_SA_SHIFT           (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this master to secure.
 *  0b01..Force the bus attribute for this master to nonsecure.
 *  0b10..Use the bus master's secure/nonsecure attribute directly.
 *  0b11..Use the bus master's secure/nonsecure attribute directly.
 */
#define TRDC_MBC0_MDA_W_DFMT1_SA(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_MDA_W_DFMT1_SA_SHIFT)) & TRDC_MBC0_MDA_W_DFMT1_SA_MASK)

#define TRDC_MBC0_MDA_W_DFMT1_DIDB_MASK          (0x100U)
#define TRDC_MBC0_MDA_W_DFMT1_DIDB_SHIFT         (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MBC0_MDA_W_DFMT1_DIDB(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_MDA_W_DFMT1_DIDB_SHIFT)) & TRDC_MBC0_MDA_W_DFMT1_DIDB_MASK)

#define TRDC_MBC0_MDA_W_DFMT1_DFMT_MASK          (0x20000000U)
#define TRDC_MBC0_MDA_W_DFMT1_DFMT_SHIFT         (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MBC0_MDA_W_DFMT1_DFMT(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_MDA_W_DFMT1_DFMT_SHIFT)) & TRDC_MBC0_MDA_W_DFMT1_DFMT_MASK)

#define TRDC_MBC0_MDA_W_DFMT1_LK1_MASK           (0x40000000U)
#define TRDC_MBC0_MDA_W_DFMT1_LK1_SHIFT          (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MBC0_MDA_W_DFMT1_LK1(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_MDA_W_DFMT1_LK1_SHIFT)) & TRDC_MBC0_MDA_W_DFMT1_LK1_MASK)

#define TRDC_MBC0_MDA_W_DFMT1_VLD_MASK           (0x80000000U)
#define TRDC_MBC0_MDA_W_DFMT1_VLD_SHIFT          (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MBC0_MDA_W_DFMT1_VLD(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC0_MDA_W_DFMT1_VLD_SHIFT)) & TRDC_MBC0_MDA_W_DFMT1_VLD_MASK)
/*! @} */

/* The count of TRDC_MBC0_MDA_W_DFMT1 */
#define TRDC_MBC0_MDA_W_DFMT1_COUNT              (7U)

/* The count of TRDC_MBC0_MDA_W_DFMT1 */
#define TRDC_MBC0_MDA_W_DFMT1_COUNT2             (1U)


/*!
 * @}
 */ /* end of group TRDC_MBC0_Register_Masks */


/*!
 * @}
 */ /* end of group TRDC_MBC0_Peripheral_Access_Layer */


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


#endif  /* PERI_TRDC_MBC0_H_ */
