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
**         CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
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
 * @file PERI_BLK_CTRL_S_AONMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 */

#if !defined(PERI_BLK_CTRL_S_AONMIX_H_)
#define PERI_BLK_CTRL_S_AONMIX_H_                /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_S_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Peripheral_Access_Layer BLK_CTRL_S_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_S_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CM33_IRQ_MASK0;                    /**< CM33_IRQ_MASK0, offset: 0x0 */
  __IO uint32_t CM33_IRQ_MASK1;                    /**< CM33_IRQ_MASK1, offset: 0x4 */
  __IO uint32_t CM33_IRQ_MASK2;                    /**< CM33_IRQ_MASK2, offset: 0x8 */
  __IO uint32_t CM33_IRQ_MASK3;                    /**< CM33_IRQ_MASK3, offset: 0xC */
  __IO uint32_t CM33_IRQ_MASK4;                    /**< CM33_IRQ_MASK4, offset: 0x10 */
  __IO uint32_t CM33_IRQ_MASK5;                    /**< CM33_IRQ_MASK5, offset: 0x14 */
  __IO uint32_t CM33_IRQ_MASK6;                    /**< CM33_IRQ_MASK6, offset: 0x18 */
  __IO uint32_t INITNSVTOR;                        /**< M33 restart non-secure address, offset: 0x1C */
       uint8_t RESERVED_0[32];
  __IO uint32_t CA55_IRQ_MASK0;                    /**< CA55_IRQ_MASK0, offset: 0x40 */
  __IO uint32_t CA55_IRQ_MASK1;                    /**< CA55_IRQ_MASK1, offset: 0x44 */
  __IO uint32_t CA55_IRQ_MASK2;                    /**< CA55_IRQ_MASK2, offset: 0x48 */
  __IO uint32_t CA55_IRQ_MASK3;                    /**< CA55_IRQ_MASK3, offset: 0x4C */
  __IO uint32_t CA55_IRQ_MASK4;                    /**< CA55_IRQ_MASK4, offset: 0x50 */
  __IO uint32_t CA55_IRQ_MASK5;                    /**< CA55_IRQ_MASK5, offset: 0x54 */
  __IO uint32_t CA55_IRQ_MASK6;                    /**< CA55_IRQ_MASK6, offset: 0x58 */
  __IO uint32_t INITSVTOR;                         /**< M33 restart secure address, offset: 0x5C */
  __IO uint32_t M33_CFG;                           /**< M33 Configure, offset: 0x60 */
       uint8_t RESERVED_1[156];
  __IO uint32_t DAP_ACCESS_STKYBIT;                /**< DAP Access Sticky, offset: 0x100 */
       uint8_t RESERVED_2[12];
  __IO uint32_t LP_HANDSHAKE;                      /**< Low power handshake enable, offset: 0x110 */
  __IO uint32_t LP_HANDSHAKE2;                     /**< Low power handshake enable, offset: 0x114 */
  __IO uint32_t CA55_CPUWAIT;                      /**< CPUWAIT settings for CA55 CPU, offset: 0x118 */
  __IO uint32_t CA55_RVBARADDR0_L;                 /**< CA55 core0 lower boot address bits, offset: 0x11C */
  __IO uint32_t CA55_RVBARADDR0_H;                 /**< CA55 core0 higher boot address bits, offset: 0x120 */
  __IO uint32_t CA55_RVBARADDR1_L;                 /**< CA55 core1 lower boot address bits, offset: 0x124 */
  __IO uint32_t CA55_RVBARADDR1_H;                 /**< CA55 core1 higher boot address bits, offset: 0x128 */
  __IO uint32_t ELE_IRQ_MASK;                      /**< Mask bits of Edgelock interrupt, offset: 0x12C */
  __IO uint32_t ELE_RESET_REQ_MASK;                /**< Mask bits of ELE reset, offset: 0x130 */
  __IO uint32_t ELE_HALT_ST;                       /**< ELE halt status, offset: 0x134 */
  __IO uint32_t CA55_MODE;                         /**< Control the boot mode of two ca55 cores, offset: 0x138 */
  __IO uint32_t NMI_MASK;                          /**< NMI MASK bits, offset: 0x13C */
  __IO uint32_t NMI_CLR;                           /**< NMI clear, offset: 0x140 */
  __IO uint32_t WDOG_ANY_MASK;                     /**< WDOG any mask, offset: 0x144 */
  __IO uint32_t ELEV1_IPI_NOCLK_REF1;              /**< ELEV1_IPI_NOCLK_REF1 clear, offset: 0x148 */
} BLK_CTRL_S_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_S_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Register_Masks BLK_CTRL_S_AONMIX Register Masks
 * @{
 */

/*! @name CM33_IRQ_MASK0 - CM33_IRQ_MASK0 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_SHIFT (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK1 - CM33_IRQ_MASK1 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_SHIFT (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK2 - CM33_IRQ_MASK2 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_SHIFT (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK3 - CM33_IRQ_MASK3 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_SHIFT (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK4 - CM33_IRQ_MASK4 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_SHIFT (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK5 - CM33_IRQ_MASK5 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_SHIFT (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK6 - CM33_IRQ_MASK6 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_SHIFT (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_MASK)
/*! @} */

/*! @name INITNSVTOR - M33 restart non-secure address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITNSVTOR_M_MASK      (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITNSVTOR_M_SHIFT     (0U)
/*! M - INITSVTOR */
#define BLK_CTRL_S_AONMIX_INITNSVTOR_M(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITNSVTOR_M_SHIFT)) & BLK_CTRL_S_AONMIX_INITNSVTOR_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK0 - CA55_IRQ_MASK0 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_SHIFT (0U)
/*! M - CA55 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK1 - CA55_IRQ_MASK1 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_SHIFT (0U)
/*! M - CA55 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK2 - CA55_IRQ_MASK2 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_SHIFT (0U)
/*! M - CA55 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK3 - CA55_IRQ_MASK3 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_SHIFT (0U)
/*! M - CA55 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK4 - CA55_IRQ_MASK4 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_SHIFT (0U)
/*! M - CA55 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK5 - CA55_IRQ_MASK5 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_SHIFT (0U)
/*! M - CA55 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK6 - CA55_IRQ_MASK6 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_SHIFT (0U)
/*! M - CA55 IRQ MASK
 *  0b00000000000000000000000000000000..IRQ masked
 *  0b00000000000000000000000000000001..IRQ not masked
 */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_MASK)
/*! @} */

/*! @name INITSVTOR - M33 restart secure address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITSVTOR_M_MASK       (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITSVTOR_M_SHIFT      (0U)
/*! M - INITSVTOR */
#define BLK_CTRL_S_AONMIX_INITSVTOR_M(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITSVTOR_M_SHIFT)) & BLK_CTRL_S_AONMIX_INITSVTOR_M_MASK)
/*! @} */

/*! @name M33_CFG - M33 Configure */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK      (0x4U)
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT     (2U)
/*! WAIT - M33 CPU WAIT */
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK  (0x18U)
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT (3U)
/*! TCM_SIZE - M33 TCM SIZE
 *  0b00..Regular TCM, 128KB Code TCM and 128KB Sys TCM
 *  0b01..Double Code TCM, 256KB Code TCM
 *  0b10..Double Sys TCM, 256KB Sys TCM
 *  0b11..Reserved
 */
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK)
/*! @} */

/*! @name DAP_ACCESS_STKYBIT - DAP Access Sticky */
/*! @{ */

#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_SHIFT (0U)
/*! M33 - M33 DAP_ACCESS_STKY
 *  0b0..M33 core can be accessed by DAP
 *  0b1..M33 core cannot be accessed by DAPCore0 works normally
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_MASK)

#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_SHIFT (1U)
/*! A55 - A55 DAP_ACCESS_STKY
 *  0b0..A55 core can be accessed by DAP
 *  0b1..A55 core cannot be accessed by DAPCore0 works normally
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_MASK)
/*! @} */

/*! @name LP_HANDSHAKE - Low power handshake enable */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_COLD_RST_HS_EN_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_COLD_RST_HS_EN_SHIFT (0U)
/*! CA55_CPU0_COLD_RST_HS_EN - CA55_CPU0 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_LP_HS_EN_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_LP_HS_EN_SHIFT (1U)
/*! CA55_CPU0_LP_HS_EN - CA55_CPU0 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_LP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_LP_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU0_LP_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_COLD_RST_HS_EN_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_COLD_RST_HS_EN_SHIFT (2U)
/*! CA55_CPU1_COLD_RST_HS_EN - CA55_CPU1 cold reset handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_LP_HS_EN_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_LP_HS_EN_SHIFT (3U)
/*! CA55_CPU1_LP_HS_EN - CA55_CPU1 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_LP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_LP_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_CPU1_LP_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_COLD_RST_HS_EN_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_COLD_RST_HS_EN_SHIFT (4U)
/*! CA55_PLT_COLD_RST_HS_EN - CA55 platform cold reset handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_LP_HS_EN_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_LP_HS_EN_SHIFT (5U)
/*! CA55_PLT_LP_HS_EN - CA55 platform cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_LP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_LP_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CA55_PLT_LP_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_PLT_COLD_RST_HS_EN_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_PLT_COLD_RST_HS_EN_SHIFT (6U)
/*! CM33_PLT_COLD_RST_HS_EN - CM33 platform cold reset handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_PLT_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_PLT_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_PLT_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_COLD_RST_HS_EN_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_COLD_RST_HS_EN_SHIFT (7U)
/*! AONMIX_COLD_RST_HS_EN - AONMIX cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_COLD_RST_HS_EN_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_COLD_RST_HS_EN_SHIFT (8U)
/*! WAKEUPMIX_COLD_RST_HS_EN - WAKEUPMIX cold reset handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_LP_HS_EN_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_LP_HS_EN_SHIFT (9U)
/*! WAKEUPMIX_LP_HS_EN - WAKEUPMIX low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_LP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_LP_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_LP_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_COLD_RST_HS_EN_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_COLD_RST_HS_EN_SHIFT (10U)
/*! NICMIX_COLD_RST_HS_EN - NICMIX cold reset handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_LP_HS_EN_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_LP_HS_EN_SHIFT (11U)
/*! NICMIX_LP_HS_EN - NICMIX low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_LP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_LP_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NICMIX_LP_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_COLD_RST_HS_EN_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_COLD_RST_HS_EN_SHIFT (12U)
/*! MEDIAMIX_COLD_RST_HS_EN - MEDIAMIX cold reset handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_LP_HS_EN_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_LP_HS_EN_SHIFT (13U)
/*! MEDIAMIX_LP_HS_EN - MEDIAMIX low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_LP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_LP_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEDIAMIX_LP_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_HSIOMIX_COLD_RST_HS_EN_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_HSIOMIX_COLD_RST_HS_EN_SHIFT (14U)
/*! HSIOMIX_COLD_RST_HS_EN - HSIOMIX cold reset handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_HSIOMIX_COLD_RST_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_HSIOMIX_COLD_RST_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_HSIOMIX_COLD_RST_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AON_TRDC_CLK_OFF_HS_EN_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AON_TRDC_CLK_OFF_HS_EN_SHIFT (15U)
/*! AON_TRDC_CLK_OFF_HS_EN - AON TRDC clock off handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AON_TRDC_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AON_TRDC_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AON_TRDC_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUP_TRDC_CLK_OFF_HS_EN_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUP_TRDC_CLK_OFF_HS_EN_SHIFT (16U)
/*! WAKEUP_TRDC_CLK_OFF_HS_EN - WAKEUP TRDC clock off handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUP_TRDC_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUP_TRDC_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUP_TRDC_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_OFF_HS_EN_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_OFF_HS_EN_SHIFT (17U)
/*! FLEXSPI_CLK_OFF_HS_EN - FLEXSPI clock off handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_OFF_HS_EN_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_OFF_HS_EN_SHIFT (18U)
/*! NIC_APB_CLK_OFF_HS_EN - NIC_APB clock off handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_OFF_HS_EN_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_OFF_HS_EN_SHIFT (19U)
/*! NIC_MEDIA_CLK_OFF_HS_EN - NIC_MEDIA clock off handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_OFF_HS_EN_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_OFF_HS_EN_SHIFT (20U)
/*! USB_CLK_OFF_HS_EN - USB_CLK clock off handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_SHIFT (21U)
/*! CM33_CLK_OFF_HS_EN - CM33_CLK clock off handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_OFF_HS_EN_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_OFF_HS_EN_SHIFT (22U)
/*! A55_CLK_OFF_HS_EN - A55_CLK clock off handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_OFF_HS_EN_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_OFF_HS_EN_SHIFT (23U)
/*! ELE_CLK_OFF_HS_EN - Edgelock Enclave clock off handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_ON_HS_EN_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_ON_HS_EN_SHIFT (24U)
/*! ELE_CLK_ON_HS_EN - Edgelock Enclave clock on handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_ON_HS_EN_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_ON_HS_EN_SHIFT (25U)
/*! A55_CLK_ON_HS_EN - A55 clock on handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_A55_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_SHIFT (26U)
/*! CM33_CLK_ON_HS_EN - CM33 clock on handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_ON_HS_EN_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_ON_HS_EN_SHIFT (27U)
/*! USB_CLK_ON_HS_EN - USB Controller clock on handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_USB_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_ON_HS_EN_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_ON_HS_EN_SHIFT (28U)
/*! NIC_MEDIA_CLK_ON_HS_EN - NIC_MEDIA clock on handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_MEDIA_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_ON_HS_EN_MASK (0x20000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_ON_HS_EN_SHIFT (29U)
/*! NIC_APB_CLK_ON_HS_EN - NIC_APB clock on handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_NIC_APB_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_ON_HS_EN_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_ON_HS_EN_SHIFT (30U)
/*! FLEXSPI_CLK_ON_HS_EN - FLEXSPI clock on handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_FLEXSPI_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_TRDC_CLK_ON_HS_EN_MASK (0x80000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_TRDC_CLK_ON_HS_EN_SHIFT (31U)
/*! WAKEUPMIX_TRDC_CLK_ON_HS_EN - WAKEUPMIX_TRDC clock on handshake enable */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_TRDC_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_TRDC_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_TRDC_CLK_ON_HS_EN_MASK)
/*! @} */

/*! @name LP_HANDSHAKE2 - Low power handshake enable */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ENABLE_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ENABLE_SHIFT (0U)
/*! ENABLE - AONMIX TRDC clock on handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ENABLE_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ENABLE_MASK)
/*! @} */

/*! @name CA55_CPUWAIT - CPUWAIT settings for CA55 CPU */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT (0U)
/*! CPU0_WAIT - CPU0_WAIT
 *  0b0..Core0 works normally
 *  0b1..Core0 stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT (1U)
/*! CPU1_WAIT - CPU1_WAIT
 *  0b0..Core1 works normally
 *  0b1..Core1 stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK)
/*! @} */

/*! @name CA55_RVBARADDR0_L - CA55 core0 lower boot address bits */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_SHIFT (0U)
/*! ADDR0_L - Lower 32 address bits */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR0_H - CA55 core0 higher boot address bits */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_SHIFT (0U)
/*! ADDR0_H - Higher address bits */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR1_L - CA55 core1 lower boot address bits */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_SHIFT (0U)
/*! ADDR1_L - CA55_RVBARADDR1_L */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR1_H - CA55 core1 higher boot address bits */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_SHIFT (0U)
/*! ADDR1_H - CA55_RVBARADDR1_H */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_MASK)
/*! @} */

/*! @name ELE_IRQ_MASK - Mask bits of Edgelock interrupt */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF2_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF2_SHIFT (0U)
/*! NOCLK_REF2 - No Clock Reference 2
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF2_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF2_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF1_SHIFT (1U)
/*! NOCLK_REF1 - No Clock Reference 1
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF1_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_REF1_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_32K_RESET_REQ_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_32K_RESET_REQ_SHIFT (2U)
/*! LMDA_32K_RESET_REQ - Request Edgelock reset from 32 KHz clock domain, active low, interrupt request */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_32K_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_32K_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_32K_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_RESET_REQ_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_RESET_REQ_SHIFT (3U)
/*! LMDA_RESET_REQ - Request Edgelock reset, active low, interrupt request
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_32K_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_32K_SHIFT (4U)
/*! NOCLK_32K - Edgelock FDET clock not detected interrupt mask */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_32K(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_32K_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_32K_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_SYS_FAIL_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_SYS_FAIL_SHIFT (5U)
/*! LMDA_SYS_FAIL - System failure, reset chip or Edgelock
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LMDA_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_SHIFT (6U)
/*! LC_BRICKED - LMDA lifecycle is bricked state */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_SHIFT (8U)
/*! WDG_RESET - Watchdog reset request */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_MASK)
/*! @} */

/*! @name ELE_RESET_REQ_MASK - Mask bits of ELE reset */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF2_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF2_SHIFT (0U)
/*! NOCLK_REF2 - No Clock Reference 2
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF2_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF2_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF1_SHIFT (1U)
/*! NOCLK_REF1 - No Clock Reference 1 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF1_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_REF1_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_32K_RESET_REQ_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_32K_RESET_REQ_SHIFT (2U)
/*! LMDA_32K_RESET_REQ - Request Edgelock reset from 32 KHz clock domain, active low, interrupt request
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_32K_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_32K_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_32K_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_RESET_REQ_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_RESET_REQ_SHIFT (3U)
/*! LMDA_RESET_REQ - Request Edgelock reset, active low, interrupt request
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_32K_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_32K_SHIFT (4U)
/*! NOCLK_32K - Edgelock FDET clock not detected interrupt mask */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_32K(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_32K_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_32K_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_SYS_FAIL_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_SYS_FAIL_SHIFT (5U)
/*! LMDA_SYS_FAIL - System failure, reset chip or Edgelock
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LMDA_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_SHIFT (6U)
/*! LC_BRICKED - LMDA lifecycle is bricked state */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_PUF_RESET_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_PUF_RESET_SHIFT (7U)
/*! PUF_RESET - PUF reset request
 *  0b0..Mask interrupt
 *  0b1..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_PUF_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_PUF_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_PUF_RESET_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_SHIFT (8U)
/*! WDG_RESET - Watchdog reset request */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_MASK)
/*! @} */

/*! @name ELE_HALT_ST - ELE halt status */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_ACK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_ACK_SHIFT (0U)
/*! ELE_HALT_ACK - EdgeLock halt and clock status
 *  0b0..EdgeLock is not fully halted and its clocks must be enabled
 *  0b1..EdgeLock is fully halted indicating clocks may be removed
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_ACK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_ACK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_EXIT_IRQ_CLR_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_EXIT_IRQ_CLR_SHIFT (8U)
/*! ELE_HALT_EXIT_IRQ_CLR - EdgeLock halt exit interrupt clear
 *  0b0..Remove the clear signal. This bit is not self-clearing and need SW to clear.
 *  0b1..Clear EdgeLock halt exit interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_EXIT_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_EXIT_IRQ_CLR_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_ST_ELE_HALT_EXIT_IRQ_CLR_MASK)
/*! @} */

/*! @name CA55_MODE - Control the boot mode of two ca55 cores */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_MASK (0x3U)
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_SHIFT (0U)
/*! AA64NAA32 - Core0 initial mode control
 *  0b00..Mask interrupt
 *  0b01..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_MASK)
/*! @} */

/*! @name NMI_MASK - NMI MASK bits */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK     (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT    (0U)
/*! CM33 - CM33 NMI mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK)
/*! @} */

/*! @name NMI_CLR - NMI clear */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK      (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT     (0U)
/*! CM33 - NMI clear */
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK)
/*! @} */

/*! @name WDOG_ANY_MASK - WDOG any mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_SHIFT (0U)
/*! WDOG1 - WDOG1 to WDOG_ANY mask
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT (1U)
/*! WDOG2 - WDOG2 to WDOG_ANY mask
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_SHIFT (2U)
/*! WDOG3 - WDOG3 to WDOG_ANY mask
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_SHIFT (3U)
/*! WDOG4 - WDOG4 to WDOG_ANY mask
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_SHIFT (4U)
/*! WDOG5 - WDOG5 to WDOG_ANY mask
 *  0b0..DISABLE
 *  0b1..ENABLE
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_MASK)
/*! @} */

/*! @name ELEV1_IPI_NOCLK_REF1 - ELEV1_IPI_NOCLK_REF1 clear */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELEV1_IPI_NOCLK_REF1_SLOW_CLEAR_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELEV1_IPI_NOCLK_REF1_SLOW_CLEAR_SHIFT (0U)
/*! SLOW_CLEAR - Interrupt clear
 *  0b0..Interrupt not cleared
 *  0b1..Interrupt cleared
 */
#define BLK_CTRL_S_AONMIX_ELEV1_IPI_NOCLK_REF1_SLOW_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELEV1_IPI_NOCLK_REF1_SLOW_CLEAR_SHIFT)) & BLK_CTRL_S_AONMIX_ELEV1_IPI_NOCLK_REF1_SLOW_CLEAR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_S_AONMIX_H_ */
