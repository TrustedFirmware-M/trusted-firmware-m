/*
** ###################################################################
**     Processors:          KW43B43ZC2MFT
**                          KW43B43ZC3MFT
**                          KW43B43ZC6MFT
**                          KW43B43ZC7MFT
**                          KW43L43Z92MFT
**                          KW43L43Z93MFT
**                          KW43L43Z96MFT
**                          KW43L43Z97MFT
**
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b260316
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SGI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_SGI.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for SGI
 *
 * CMSIS Peripheral Access Layer for SGI
 */

#if !defined(PERI_SGI_H_)
#define PERI_SGI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW43B43ZC2MFT))
#include "KW43B43ZC2_COMMON.h"
#elif (defined(CPU_KW43B43ZC3MFT))
#include "KW43B43ZC3_COMMON.h"
#elif (defined(CPU_KW43B43ZC6MFT))
#include "KW43B43ZC6_COMMON.h"
#elif (defined(CPU_KW43B43ZC7MFT))
#include "KW43B43ZC7_COMMON.h"
#elif (defined(CPU_KW43L43Z92MFT))
#include "KW43L43Z92_COMMON.h"
#elif (defined(CPU_KW43L43Z93MFT))
#include "KW43L43Z93_COMMON.h"
#elif (defined(CPU_KW43L43Z96MFT))
#include "KW43L43Z96_COMMON.h"
#elif (defined(CPU_KW43L43Z97MFT))
#include "KW43L43Z97_COMMON.h"
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
   -- SGI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SGI_Peripheral_Access_Layer SGI Peripheral Access Layer
 * @{
 */

/** SGI - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint32_t SGI_DATIN0A;                       /**< Input Data register 0 - Word-3, offset: 0x200 */
  __IO uint32_t SGI_DATIN0B;                       /**< Input Data register 0 - Word-2, offset: 0x204 */
  __IO uint32_t SGI_DATIN0C;                       /**< Input Data register 0 - Word-1, offset: 0x208 */
  __IO uint32_t SGI_DATIN0D;                       /**< Input Data register 0 - Word-0, offset: 0x20C */
  __IO uint32_t SGI_DATIN1A;                       /**< Input Data register 1 - Word-3, offset: 0x210 */
  __IO uint32_t SGI_DATIN1B;                       /**< Input Data register 1 - Word-2, offset: 0x214 */
  __IO uint32_t SGI_DATIN1C;                       /**< Input Data register 1 - Word-1, offset: 0x218 */
  __IO uint32_t SGI_DATIN1D;                       /**< Input Data register 1 - Word-0, offset: 0x21C */
  __IO uint32_t SGI_DATIN2A;                       /**< Input Data register 2 - Word-3, offset: 0x220 */
  __IO uint32_t SGI_DATIN2B;                       /**< Input Data register 2 - Word-2, offset: 0x224 */
  __IO uint32_t SGI_DATIN2C;                       /**< Input Data register 2 - Word-1, offset: 0x228 */
  __IO uint32_t SGI_DATIN2D;                       /**< Input Data register 2 - Word-0, offset: 0x22C */
  __IO uint32_t SGI_DATIN3A;                       /**< Input Data register 3 - Word-3, offset: 0x230 */
  __IO uint32_t SGI_DATIN3B;                       /**< Input Data register 3 - Word-2, offset: 0x234 */
  __IO uint32_t SGI_DATIN3C;                       /**< Input Data register 3 - Word-1, offset: 0x238 */
  __IO uint32_t SGI_DATIN3D;                       /**< Input Data register 3 - Word-0, offset: 0x23C */
  __IO uint32_t SGI_KEY0A;                         /**< Input Key register 0 - Word-3, offset: 0x240 */
  __IO uint32_t SGI_KEY0B;                         /**< Input Key register 0 - Word-2, offset: 0x244 */
  __IO uint32_t SGI_KEY0C;                         /**< Input Key register 0 - Word-1, offset: 0x248 */
  __IO uint32_t SGI_KEY0D;                         /**< Input Key register 0 - Word-0, offset: 0x24C */
  __IO uint32_t SGI_KEY1A;                         /**< Input Key register 1 - Word-3, offset: 0x250 */
  __IO uint32_t SGI_KEY1B;                         /**< Input Key register 1 - Word-2, offset: 0x254 */
  __IO uint32_t SGI_KEY1C;                         /**< Input Key register 1 - Word-1, offset: 0x258 */
  __IO uint32_t SGI_KEY1D;                         /**< Input Key register 1 - Word-0, offset: 0x25C */
  __IO uint32_t SGI_KEY2A;                         /**< Input Key register 2 - Word-3, offset: 0x260 */
  __IO uint32_t SGI_KEY2B;                         /**< Input Key register 2 - Word-2, offset: 0x264 */
  __IO uint32_t SGI_KEY2C;                         /**< Input Key register 2 - Word-1, offset: 0x268 */
  __IO uint32_t SGI_KEY2D;                         /**< Input Key register 2 - Word-0, offset: 0x26C */
  __IO uint32_t SGI_KEY3A;                         /**< Input Key register 3 - Word-3, offset: 0x270 */
  __IO uint32_t SGI_KEY3B;                         /**< Input Key register 3 - Word-2, offset: 0x274 */
  __IO uint32_t SGI_KEY3C;                         /**< Input Key register 3 - Word-1, offset: 0x278 */
  __IO uint32_t SGI_KEY3D;                         /**< Input Key register 3 - Word-0, offset: 0x27C */
  __IO uint32_t SGI_KEY4A;                         /**< Input Key register 4 - Word-3, offset: 0x280 */
  __IO uint32_t SGI_KEY4B;                         /**< Input Key register 4 - Word-2, offset: 0x284 */
  __IO uint32_t SGI_KEY4C;                         /**< Input Key register 4 - Word-1, offset: 0x288 */
  __IO uint32_t SGI_KEY4D;                         /**< Input Key register 4 - Word-0, offset: 0x28C */
  __IO uint32_t SGI_KEY5A;                         /**< Input Key register 5 - Word-3, offset: 0x290 */
  __IO uint32_t SGI_KEY5B;                         /**< Input Key register 5 - Word-2, offset: 0x294 */
  __IO uint32_t SGI_KEY5C;                         /**< Input Key register 5 - Word-1, offset: 0x298 */
  __IO uint32_t SGI_KEY5D;                         /**< Input Key register 5 - Word-0, offset: 0x29C */
  __IO uint32_t SGI_KEY6A;                         /**< Input Key register 6 - Word-3, offset: 0x2A0 */
  __IO uint32_t SGI_KEY6B;                         /**< Input Key register 6 - Word-2, offset: 0x2A4 */
  __IO uint32_t SGI_KEY6C;                         /**< Input Key register 6 - Word-1, offset: 0x2A8 */
  __IO uint32_t SGI_KEY6D;                         /**< Input Key register 6 - Word-0, offset: 0x2AC */
  __IO uint32_t SGI_KEY7A;                         /**< Input Key register 7 - Word-3, offset: 0x2B0 */
  __IO uint32_t SGI_KEY7B;                         /**< Input Key register 7 - Word-2, offset: 0x2B4 */
  __IO uint32_t SGI_KEY7C;                         /**< Input Key register 7 - Word-1, offset: 0x2B8 */
  __IO uint32_t SGI_KEY7D;                         /**< Input Key register 7 - Word-0, offset: 0x2BC */
  __IO uint32_t SGI_DATOUTA;                       /**< Output Data register - Word-3, offset: 0x2C0 */
  __IO uint32_t SGI_DATOUTB;                       /**< Output Data register - Word-2, offset: 0x2C4 */
  __IO uint32_t SGI_DATOUTC;                       /**< Output Data register - Word-1, offset: 0x2C8 */
  __IO uint32_t SGI_DATOUTD;                       /**< Output Data register - Word-0, offset: 0x2CC */
       uint8_t RESERVED_1[2352];
  __IO uint32_t SGI_STATUS;                        /**< Status register, offset: 0xC00 */
  __IO uint32_t SGI_COUNT;                         /**< Calculation counter, offset: 0xC04 */
  __IO uint32_t SGI_KEYCHK;                        /**< Key checksum register, offset: 0xC08 */
  __IO uint32_t SGI_PRNG_SW_READ;                  /**< SGI PRNG read register, offset: 0xC0C */
       uint8_t RESERVED_2[240];
  __IO uint32_t SGI_CTRL;                          /**< SGI Control register, offset: 0xD00 */
  __IO uint32_t SGI_CTRL2;                         /**< SGI Control register 2, offset: 0xD04 */
  __IO uint32_t SGI_DUMMY_CTRL;                    /**< Configuration of dummy controls, offset: 0xD08 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SGI_SFRSEED;                       /**< SFRSEED register for SFRMASK feature, offset: 0xD10 */
  __IO uint32_t SGI_SHA2_CTRL;                     /**< SHA Control Register, offset: 0xD14 */
  __IO uint32_t SGI_SHA_FIFO;                      /**< SHA FIFO lower-bank low, offset: 0xD18 */
  __I  uint32_t SGI_CONFIG;                        /**< SHA Configuration Reg, offset: 0xD1C */
  __I  uint32_t SGI_CONFIG2;                       /**< SHA Configuration 2 Reg, offset: 0xD20 */
  __IO uint32_t SGI_AUTO_MODE;                     /**< SGI Auto Mode Control register, offset: 0xD24 */
  __IO uint32_t SGI_AUTO_DMA_CTRL;                 /**< SGI Auto Mode Control register, offset: 0xD28 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SGI_PRNG_SW_SEED;                  /**< SGI internal PRNG SW seeding register, offset: 0xD30 */
       uint8_t RESERVED_5[12];
  __IO uint32_t SGI_KEY_CTRL;                      /**< SGI Key Control SFR, offset: 0xD40 */
       uint8_t RESERVED_6[12];
  __I  uint32_t SGI_KEY_WRAP;                      /**< Wrapped key read SFR, offset: 0xD50 */
       uint8_t RESERVED_7[436];
  __I  uint32_t SGI_VERSION;                       /**< SGI Version, offset: 0xF08 */
       uint8_t RESERVED_8[180];
  __IO uint32_t SGI_ACCESS_ERR;                    /**< Access Error, offset: 0xFC0 */
  __IO uint32_t SGI_ACCESS_ERR_CLR;                /**< Clear Access Error, offset: 0xFC4 */
       uint8_t RESERVED_9[24];
  __I  uint32_t SGI_INT_STATUS;                    /**< Interrupt status, offset: 0xFE0 */
  __IO uint32_t SGI_INT_ENABLE;                    /**< Interrupt enable, offset: 0xFE4 */
  __IO uint32_t SGI_INT_STATUS_CLR;                /**< Interrupt status clear, offset: 0xFE8 */
  __IO uint32_t SGI_INT_STATUS_SET;                /**< Interrupt status set, offset: 0xFEC */
       uint8_t RESERVED_10[12];
  __I  uint32_t SGI_MODULE_ID;                     /**< Module ID, offset: 0xFFC */
} SGI_Type;

/* ----------------------------------------------------------------------------
   -- SGI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SGI_Register_Masks SGI Register Masks
 * @{
 */

/*! @name SGI_DATIN0A - Input Data register 0 - Word-3 */
/*! @{ */

#define SGI_SGI_DATIN0A_DATIN0A_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN0A_DATIN0A_SHIFT            (0U)
/*! DATIN0A - Input Data register */
#define SGI_SGI_DATIN0A_DATIN0A(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN0A_DATIN0A_SHIFT)) & SGI_SGI_DATIN0A_DATIN0A_MASK)
/*! @} */

/*! @name SGI_DATIN0B - Input Data register 0 - Word-2 */
/*! @{ */

#define SGI_SGI_DATIN0B_DATIN0B_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN0B_DATIN0B_SHIFT            (0U)
/*! DATIN0B - Input Data register */
#define SGI_SGI_DATIN0B_DATIN0B(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN0B_DATIN0B_SHIFT)) & SGI_SGI_DATIN0B_DATIN0B_MASK)
/*! @} */

/*! @name SGI_DATIN0C - Input Data register 0 - Word-1 */
/*! @{ */

#define SGI_SGI_DATIN0C_DATIN0C_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN0C_DATIN0C_SHIFT            (0U)
/*! DATIN0C - Input Data register */
#define SGI_SGI_DATIN0C_DATIN0C(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN0C_DATIN0C_SHIFT)) & SGI_SGI_DATIN0C_DATIN0C_MASK)
/*! @} */

/*! @name SGI_DATIN0D - Input Data register 0 - Word-0 */
/*! @{ */

#define SGI_SGI_DATIN0D_DATIN0D_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN0D_DATIN0D_SHIFT            (0U)
/*! DATIN0D - Input Data register */
#define SGI_SGI_DATIN0D_DATIN0D(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN0D_DATIN0D_SHIFT)) & SGI_SGI_DATIN0D_DATIN0D_MASK)
/*! @} */

/*! @name SGI_DATIN1A - Input Data register 1 - Word-3 */
/*! @{ */

#define SGI_SGI_DATIN1A_DATIN1A_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN1A_DATIN1A_SHIFT            (0U)
/*! DATIN1A - Input Data register */
#define SGI_SGI_DATIN1A_DATIN1A(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN1A_DATIN1A_SHIFT)) & SGI_SGI_DATIN1A_DATIN1A_MASK)
/*! @} */

/*! @name SGI_DATIN1B - Input Data register 1 - Word-2 */
/*! @{ */

#define SGI_SGI_DATIN1B_DATIN1B_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN1B_DATIN1B_SHIFT            (0U)
/*! DATIN1B - Input Data register */
#define SGI_SGI_DATIN1B_DATIN1B(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN1B_DATIN1B_SHIFT)) & SGI_SGI_DATIN1B_DATIN1B_MASK)
/*! @} */

/*! @name SGI_DATIN1C - Input Data register 1 - Word-1 */
/*! @{ */

#define SGI_SGI_DATIN1C_DATIN1C_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN1C_DATIN1C_SHIFT            (0U)
/*! DATIN1C - Input Data register */
#define SGI_SGI_DATIN1C_DATIN1C(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN1C_DATIN1C_SHIFT)) & SGI_SGI_DATIN1C_DATIN1C_MASK)
/*! @} */

/*! @name SGI_DATIN1D - Input Data register 1 - Word-0 */
/*! @{ */

#define SGI_SGI_DATIN1D_DATIN1D_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN1D_DATIN1D_SHIFT            (0U)
/*! DATIN1D - Input Data register */
#define SGI_SGI_DATIN1D_DATIN1D(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN1D_DATIN1D_SHIFT)) & SGI_SGI_DATIN1D_DATIN1D_MASK)
/*! @} */

/*! @name SGI_DATIN2A - Input Data register 2 - Word-3 */
/*! @{ */

#define SGI_SGI_DATIN2A_DATIN2A_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN2A_DATIN2A_SHIFT            (0U)
/*! DATIN2A - Input Data register */
#define SGI_SGI_DATIN2A_DATIN2A(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN2A_DATIN2A_SHIFT)) & SGI_SGI_DATIN2A_DATIN2A_MASK)
/*! @} */

/*! @name SGI_DATIN2B - Input Data register 2 - Word-2 */
/*! @{ */

#define SGI_SGI_DATIN2B_DATIN2B_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN2B_DATIN2B_SHIFT            (0U)
/*! DATIN2B - Input Data register */
#define SGI_SGI_DATIN2B_DATIN2B(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN2B_DATIN2B_SHIFT)) & SGI_SGI_DATIN2B_DATIN2B_MASK)
/*! @} */

/*! @name SGI_DATIN2C - Input Data register 2 - Word-1 */
/*! @{ */

#define SGI_SGI_DATIN2C_DATIN2C_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN2C_DATIN2C_SHIFT            (0U)
/*! DATIN2C - Input Data register */
#define SGI_SGI_DATIN2C_DATIN2C(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN2C_DATIN2C_SHIFT)) & SGI_SGI_DATIN2C_DATIN2C_MASK)
/*! @} */

/*! @name SGI_DATIN2D - Input Data register 2 - Word-0 */
/*! @{ */

#define SGI_SGI_DATIN2D_DATIN2D_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN2D_DATIN2D_SHIFT            (0U)
/*! DATIN2D - Input Data register */
#define SGI_SGI_DATIN2D_DATIN2D(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN2D_DATIN2D_SHIFT)) & SGI_SGI_DATIN2D_DATIN2D_MASK)
/*! @} */

/*! @name SGI_DATIN3A - Input Data register 3 - Word-3 */
/*! @{ */

#define SGI_SGI_DATIN3A_DATIN3A_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN3A_DATIN3A_SHIFT            (0U)
/*! DATIN3A - Input Data register */
#define SGI_SGI_DATIN3A_DATIN3A(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN3A_DATIN3A_SHIFT)) & SGI_SGI_DATIN3A_DATIN3A_MASK)
/*! @} */

/*! @name SGI_DATIN3B - Input Data register 3 - Word-2 */
/*! @{ */

#define SGI_SGI_DATIN3B_DATIN3B_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN3B_DATIN3B_SHIFT            (0U)
/*! DATIN3B - Input Data register */
#define SGI_SGI_DATIN3B_DATIN3B(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN3B_DATIN3B_SHIFT)) & SGI_SGI_DATIN3B_DATIN3B_MASK)
/*! @} */

/*! @name SGI_DATIN3C - Input Data register 3 - Word-1 */
/*! @{ */

#define SGI_SGI_DATIN3C_DATIN3C_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN3C_DATIN3C_SHIFT            (0U)
/*! DATIN3C - Input Data register */
#define SGI_SGI_DATIN3C_DATIN3C(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN3C_DATIN3C_SHIFT)) & SGI_SGI_DATIN3C_DATIN3C_MASK)
/*! @} */

/*! @name SGI_DATIN3D - Input Data register 3 - Word-0 */
/*! @{ */

#define SGI_SGI_DATIN3D_DATIN3D_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATIN3D_DATIN3D_SHIFT            (0U)
/*! DATIN3D - Input Data register */
#define SGI_SGI_DATIN3D_DATIN3D(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATIN3D_DATIN3D_SHIFT)) & SGI_SGI_DATIN3D_DATIN3D_MASK)
/*! @} */

/*! @name SGI_KEY0A - Input Key register 0 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY0A_KEY0A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY0A_KEY0A_SHIFT                (0U)
/*! KEY0A - Input Key register */
#define SGI_SGI_KEY0A_KEY0A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY0A_KEY0A_SHIFT)) & SGI_SGI_KEY0A_KEY0A_MASK)
/*! @} */

/*! @name SGI_KEY0B - Input Key register 0 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY0B_KEY0B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY0B_KEY0B_SHIFT                (0U)
/*! KEY0B - Input Key register */
#define SGI_SGI_KEY0B_KEY0B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY0B_KEY0B_SHIFT)) & SGI_SGI_KEY0B_KEY0B_MASK)
/*! @} */

/*! @name SGI_KEY0C - Input Key register 0 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY0C_KEY0C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY0C_KEY0C_SHIFT                (0U)
/*! KEY0C - Input Key register */
#define SGI_SGI_KEY0C_KEY0C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY0C_KEY0C_SHIFT)) & SGI_SGI_KEY0C_KEY0C_MASK)
/*! @} */

/*! @name SGI_KEY0D - Input Key register 0 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY0D_KEY0D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY0D_KEY0D_SHIFT                (0U)
/*! KEY0D - Input Key register */
#define SGI_SGI_KEY0D_KEY0D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY0D_KEY0D_SHIFT)) & SGI_SGI_KEY0D_KEY0D_MASK)
/*! @} */

/*! @name SGI_KEY1A - Input Key register 1 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY1A_KEY1A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY1A_KEY1A_SHIFT                (0U)
/*! KEY1A - Input Key register */
#define SGI_SGI_KEY1A_KEY1A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY1A_KEY1A_SHIFT)) & SGI_SGI_KEY1A_KEY1A_MASK)
/*! @} */

/*! @name SGI_KEY1B - Input Key register 1 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY1B_KEY1B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY1B_KEY1B_SHIFT                (0U)
/*! KEY1B - Input Key register */
#define SGI_SGI_KEY1B_KEY1B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY1B_KEY1B_SHIFT)) & SGI_SGI_KEY1B_KEY1B_MASK)
/*! @} */

/*! @name SGI_KEY1C - Input Key register 1 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY1C_KEY1C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY1C_KEY1C_SHIFT                (0U)
/*! KEY1C - Input Key register */
#define SGI_SGI_KEY1C_KEY1C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY1C_KEY1C_SHIFT)) & SGI_SGI_KEY1C_KEY1C_MASK)
/*! @} */

/*! @name SGI_KEY1D - Input Key register 1 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY1D_KEY1D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY1D_KEY1D_SHIFT                (0U)
/*! KEY1D - Input Key register */
#define SGI_SGI_KEY1D_KEY1D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY1D_KEY1D_SHIFT)) & SGI_SGI_KEY1D_KEY1D_MASK)
/*! @} */

/*! @name SGI_KEY2A - Input Key register 2 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY2A_KEY2A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY2A_KEY2A_SHIFT                (0U)
/*! KEY2A - Input Key register */
#define SGI_SGI_KEY2A_KEY2A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY2A_KEY2A_SHIFT)) & SGI_SGI_KEY2A_KEY2A_MASK)
/*! @} */

/*! @name SGI_KEY2B - Input Key register 2 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY2B_KEY2B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY2B_KEY2B_SHIFT                (0U)
/*! KEY2B - Input Key register */
#define SGI_SGI_KEY2B_KEY2B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY2B_KEY2B_SHIFT)) & SGI_SGI_KEY2B_KEY2B_MASK)
/*! @} */

/*! @name SGI_KEY2C - Input Key register 2 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY2C_KEY2C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY2C_KEY2C_SHIFT                (0U)
/*! KEY2C - Input Key register */
#define SGI_SGI_KEY2C_KEY2C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY2C_KEY2C_SHIFT)) & SGI_SGI_KEY2C_KEY2C_MASK)
/*! @} */

/*! @name SGI_KEY2D - Input Key register 2 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY2D_KEY2D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY2D_KEY2D_SHIFT                (0U)
/*! KEY2D - Input Key register */
#define SGI_SGI_KEY2D_KEY2D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY2D_KEY2D_SHIFT)) & SGI_SGI_KEY2D_KEY2D_MASK)
/*! @} */

/*! @name SGI_KEY3A - Input Key register 3 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY3A_KEY3A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY3A_KEY3A_SHIFT                (0U)
/*! KEY3A - Input Key register */
#define SGI_SGI_KEY3A_KEY3A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY3A_KEY3A_SHIFT)) & SGI_SGI_KEY3A_KEY3A_MASK)
/*! @} */

/*! @name SGI_KEY3B - Input Key register 3 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY3B_KEY3B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY3B_KEY3B_SHIFT                (0U)
/*! KEY3B - Input Key register */
#define SGI_SGI_KEY3B_KEY3B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY3B_KEY3B_SHIFT)) & SGI_SGI_KEY3B_KEY3B_MASK)
/*! @} */

/*! @name SGI_KEY3C - Input Key register 3 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY3C_KEY3C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY3C_KEY3C_SHIFT                (0U)
/*! KEY3C - Input Key register */
#define SGI_SGI_KEY3C_KEY3C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY3C_KEY3C_SHIFT)) & SGI_SGI_KEY3C_KEY3C_MASK)
/*! @} */

/*! @name SGI_KEY3D - Input Key register 3 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY3D_KEY3D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY3D_KEY3D_SHIFT                (0U)
/*! KEY3D - Input Key register */
#define SGI_SGI_KEY3D_KEY3D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY3D_KEY3D_SHIFT)) & SGI_SGI_KEY3D_KEY3D_MASK)
/*! @} */

/*! @name SGI_KEY4A - Input Key register 4 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY4A_KEY4A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY4A_KEY4A_SHIFT                (0U)
/*! KEY4A - Input Key register */
#define SGI_SGI_KEY4A_KEY4A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY4A_KEY4A_SHIFT)) & SGI_SGI_KEY4A_KEY4A_MASK)
/*! @} */

/*! @name SGI_KEY4B - Input Key register 4 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY4B_KEY4B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY4B_KEY4B_SHIFT                (0U)
/*! KEY4B - Input Key register */
#define SGI_SGI_KEY4B_KEY4B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY4B_KEY4B_SHIFT)) & SGI_SGI_KEY4B_KEY4B_MASK)
/*! @} */

/*! @name SGI_KEY4C - Input Key register 4 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY4C_KEY4C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY4C_KEY4C_SHIFT                (0U)
/*! KEY4C - Input Key register */
#define SGI_SGI_KEY4C_KEY4C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY4C_KEY4C_SHIFT)) & SGI_SGI_KEY4C_KEY4C_MASK)
/*! @} */

/*! @name SGI_KEY4D - Input Key register 4 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY4D_KEY4D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY4D_KEY4D_SHIFT                (0U)
/*! KEY4D - Input Key register */
#define SGI_SGI_KEY4D_KEY4D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY4D_KEY4D_SHIFT)) & SGI_SGI_KEY4D_KEY4D_MASK)
/*! @} */

/*! @name SGI_KEY5A - Input Key register 5 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY5A_KEY5A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY5A_KEY5A_SHIFT                (0U)
/*! KEY5A - Input Key register */
#define SGI_SGI_KEY5A_KEY5A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY5A_KEY5A_SHIFT)) & SGI_SGI_KEY5A_KEY5A_MASK)
/*! @} */

/*! @name SGI_KEY5B - Input Key register 5 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY5B_KEY5B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY5B_KEY5B_SHIFT                (0U)
/*! KEY5B - Input Key register */
#define SGI_SGI_KEY5B_KEY5B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY5B_KEY5B_SHIFT)) & SGI_SGI_KEY5B_KEY5B_MASK)
/*! @} */

/*! @name SGI_KEY5C - Input Key register 5 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY5C_KEY5C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY5C_KEY5C_SHIFT                (0U)
/*! KEY5C - Input Key register */
#define SGI_SGI_KEY5C_KEY5C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY5C_KEY5C_SHIFT)) & SGI_SGI_KEY5C_KEY5C_MASK)
/*! @} */

/*! @name SGI_KEY5D - Input Key register 5 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY5D_KEY5D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY5D_KEY5D_SHIFT                (0U)
/*! KEY5D - Input Key register */
#define SGI_SGI_KEY5D_KEY5D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY5D_KEY5D_SHIFT)) & SGI_SGI_KEY5D_KEY5D_MASK)
/*! @} */

/*! @name SGI_KEY6A - Input Key register 6 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY6A_KEY6A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY6A_KEY6A_SHIFT                (0U)
/*! KEY6A - Input Key register */
#define SGI_SGI_KEY6A_KEY6A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY6A_KEY6A_SHIFT)) & SGI_SGI_KEY6A_KEY6A_MASK)
/*! @} */

/*! @name SGI_KEY6B - Input Key register 6 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY6B_KEY6B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY6B_KEY6B_SHIFT                (0U)
/*! KEY6B - Input Key register */
#define SGI_SGI_KEY6B_KEY6B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY6B_KEY6B_SHIFT)) & SGI_SGI_KEY6B_KEY6B_MASK)
/*! @} */

/*! @name SGI_KEY6C - Input Key register 6 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY6C_KEY6C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY6C_KEY6C_SHIFT                (0U)
/*! KEY6C - Input Key register */
#define SGI_SGI_KEY6C_KEY6C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY6C_KEY6C_SHIFT)) & SGI_SGI_KEY6C_KEY6C_MASK)
/*! @} */

/*! @name SGI_KEY6D - Input Key register 6 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY6D_KEY6D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY6D_KEY6D_SHIFT                (0U)
/*! KEY6D - Input Key register */
#define SGI_SGI_KEY6D_KEY6D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY6D_KEY6D_SHIFT)) & SGI_SGI_KEY6D_KEY6D_MASK)
/*! @} */

/*! @name SGI_KEY7A - Input Key register 7 - Word-3 */
/*! @{ */

#define SGI_SGI_KEY7A_KEY7A_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY7A_KEY7A_SHIFT                (0U)
/*! KEY7A - Input Key register */
#define SGI_SGI_KEY7A_KEY7A(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY7A_KEY7A_SHIFT)) & SGI_SGI_KEY7A_KEY7A_MASK)
/*! @} */

/*! @name SGI_KEY7B - Input Key register 7 - Word-2 */
/*! @{ */

#define SGI_SGI_KEY7B_KEY7B_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY7B_KEY7B_SHIFT                (0U)
/*! KEY7B - Input Key register */
#define SGI_SGI_KEY7B_KEY7B(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY7B_KEY7B_SHIFT)) & SGI_SGI_KEY7B_KEY7B_MASK)
/*! @} */

/*! @name SGI_KEY7C - Input Key register 7 - Word-1 */
/*! @{ */

#define SGI_SGI_KEY7C_KEY7C_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY7C_KEY7C_SHIFT                (0U)
/*! KEY7C - Input Key register */
#define SGI_SGI_KEY7C_KEY7C(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY7C_KEY7C_SHIFT)) & SGI_SGI_KEY7C_KEY7C_MASK)
/*! @} */

/*! @name SGI_KEY7D - Input Key register 7 - Word-0 */
/*! @{ */

#define SGI_SGI_KEY7D_KEY7D_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_KEY7D_KEY7D_SHIFT                (0U)
/*! KEY7D - Input Key register */
#define SGI_SGI_KEY7D_KEY7D(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY7D_KEY7D_SHIFT)) & SGI_SGI_KEY7D_KEY7D_MASK)
/*! @} */

/*! @name SGI_DATOUTA - Output Data register - Word-3 */
/*! @{ */

#define SGI_SGI_DATOUTA_DATOUTA_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATOUTA_DATOUTA_SHIFT            (0U)
/*! DATOUTA - Output Data register */
#define SGI_SGI_DATOUTA_DATOUTA(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATOUTA_DATOUTA_SHIFT)) & SGI_SGI_DATOUTA_DATOUTA_MASK)
/*! @} */

/*! @name SGI_DATOUTB - Output Data register - Word-2 */
/*! @{ */

#define SGI_SGI_DATOUTB_DATOUTB_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATOUTB_DATOUTB_SHIFT            (0U)
/*! DATOUTB - Output Data register */
#define SGI_SGI_DATOUTB_DATOUTB(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATOUTB_DATOUTB_SHIFT)) & SGI_SGI_DATOUTB_DATOUTB_MASK)
/*! @} */

/*! @name SGI_DATOUTC - Output Data register - Word-1 */
/*! @{ */

#define SGI_SGI_DATOUTC_DATOUTC_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATOUTC_DATOUTC_SHIFT            (0U)
/*! DATOUTC - Output Data register */
#define SGI_SGI_DATOUTC_DATOUTC(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATOUTC_DATOUTC_SHIFT)) & SGI_SGI_DATOUTC_DATOUTC_MASK)
/*! @} */

/*! @name SGI_DATOUTD - Output Data register - Word-0 */
/*! @{ */

#define SGI_SGI_DATOUTD_DATOUTD_MASK             (0xFFFFFFFFU)
#define SGI_SGI_DATOUTD_DATOUTD_SHIFT            (0U)
/*! DATOUTD - Output Data register */
#define SGI_SGI_DATOUTD_DATOUTD(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DATOUTD_DATOUTD_SHIFT)) & SGI_SGI_DATOUTD_DATOUTD_MASK)
/*! @} */

/*! @name SGI_STATUS - Status register */
/*! @{ */

#define SGI_SGI_STATUS_BUSY_MASK                 (0x1U)
#define SGI_SGI_STATUS_BUSY_SHIFT                (0U)
/*! BUSY
 *  0b0..Not busy
 *  0b1..Busy
 */
#define SGI_SGI_STATUS_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_BUSY_SHIFT)) & SGI_SGI_STATUS_BUSY_MASK)

#define SGI_SGI_STATUS_OFLOW_MASK                (0x2U)
#define SGI_SGI_STATUS_OFLOW_SHIFT               (1U)
/*! OFLOW - Overflow in INCR operation flag
 *  0b0..Clear the flag
 *  0b0..No overflow
 *  0b1..No effect
 *  0b1..Overflow
 */
#define SGI_SGI_STATUS_OFLOW(x)                  (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_OFLOW_SHIFT)) & SGI_SGI_STATUS_OFLOW_MASK)

#define SGI_SGI_STATUS_PRNG_RDY_MASK             (0x4U)
#define SGI_SGI_STATUS_PRNG_RDY_SHIFT            (2U)
/*! PRNG_RDY
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SGI_SGI_STATUS_PRNG_RDY(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_PRNG_RDY_SHIFT)) & SGI_SGI_STATUS_PRNG_RDY_MASK)

#define SGI_SGI_STATUS_ERROR_MASK                (0x38U)
#define SGI_SGI_STATUS_ERROR_SHIFT               (3U)
/*! ERROR - Error detected
 *  0b000..Error (all values other than 0x05 indicate ERROR)
 *  0b101..No error
 */
#define SGI_SGI_STATUS_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_ERROR_SHIFT)) & SGI_SGI_STATUS_ERROR_MASK)

#define SGI_SGI_STATUS_SHA2_BUSY_MASK            (0x40U)
#define SGI_SGI_STATUS_SHA2_BUSY_SHIFT           (6U)
/*! SHA2_BUSY
 *  0b0..Not busy
 *  0b1..Busy
 */
#define SGI_SGI_STATUS_SHA2_BUSY(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_SHA2_BUSY_SHIFT)) & SGI_SGI_STATUS_SHA2_BUSY_MASK)

#define SGI_SGI_STATUS_IRQ_MASK                  (0x80U)
#define SGI_SGI_STATUS_IRQ_SHIFT                 (7U)
/*! IRQ
 *  0b0..Clear the flag
 *  0b0..No IRQ
 *  0b1..IRQ
 *  0b1..No effect
 */
#define SGI_SGI_STATUS_IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_IRQ_SHIFT)) & SGI_SGI_STATUS_IRQ_MASK)

#define SGI_SGI_STATUS_SHA_FIFO_FULL_MASK        (0x100U)
#define SGI_SGI_STATUS_SHA_FIFO_FULL_SHIFT       (8U)
/*! SHA_FIFO_FULL
 *  0b0..Not full
 *  0b1..Full
 */
#define SGI_SGI_STATUS_SHA_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_SHA_FIFO_FULL_SHIFT)) & SGI_SGI_STATUS_SHA_FIFO_FULL_MASK)

#define SGI_SGI_STATUS_SHA_FIFO_LEVEL_MASK       (0x7E00U)
#define SGI_SGI_STATUS_SHA_FIFO_LEVEL_SHIFT      (9U)
#define SGI_SGI_STATUS_SHA_FIFO_LEVEL(x)         (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_SHA_FIFO_LEVEL_SHIFT)) & SGI_SGI_STATUS_SHA_FIFO_LEVEL_MASK)

#define SGI_SGI_STATUS_SHA_ERROR_MASK            (0x8000U)
#define SGI_SGI_STATUS_SHA_ERROR_SHIFT           (15U)
/*! SHA_ERROR
 *  0b0..No error
 *  0b1..Error
 */
#define SGI_SGI_STATUS_SHA_ERROR(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_SHA_ERROR_SHIFT)) & SGI_SGI_STATUS_SHA_ERROR_MASK)

#define SGI_SGI_STATUS_KEY_READ_ERR_MASK         (0x10000U)
#define SGI_SGI_STATUS_KEY_READ_ERR_SHIFT        (16U)
/*! KEY_READ_ERR - KEY SFR READ ERROR, sticky, cleared only with reset or flush
 *  0b0..No error
 *  0b1..Error
 */
#define SGI_SGI_STATUS_KEY_READ_ERR(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_KEY_READ_ERR_SHIFT)) & SGI_SGI_STATUS_KEY_READ_ERR_MASK)

#define SGI_SGI_STATUS_KEY_UNWRAP_ERR_MASK       (0x20000U)
#define SGI_SGI_STATUS_KEY_UNWRAP_ERR_SHIFT      (17U)
/*! KEY_UNWRAP_ERR - KEY UNWRAP ERROR , sticky, cleared only with reset or flush
 *  0b0..No error
 *  0b1..Error
 */
#define SGI_SGI_STATUS_KEY_UNWRAP_ERR(x)         (((uint32_t)(((uint32_t)(x)) << SGI_SGI_STATUS_KEY_UNWRAP_ERR_SHIFT)) & SGI_SGI_STATUS_KEY_UNWRAP_ERR_MASK)
/*! @} */

/*! @name SGI_COUNT - Calculation counter */
/*! @{ */

#define SGI_SGI_COUNT_COUNT_MASK                 (0xFFFFFFFFU)
#define SGI_SGI_COUNT_COUNT_SHIFT                (0U)
#define SGI_SGI_COUNT_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_COUNT_COUNT_SHIFT)) & SGI_SGI_COUNT_COUNT_MASK)
/*! @} */

/*! @name SGI_KEYCHK - Key checksum register */
/*! @{ */

#define SGI_SGI_KEYCHK_KEYCHKSUM_MASK            (0xFFFFFFFFU)
#define SGI_SGI_KEYCHK_KEYCHKSUM_SHIFT           (0U)
/*! KEYCHKSUM - Key checksum (32-bit). */
#define SGI_SGI_KEYCHK_KEYCHKSUM(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEYCHK_KEYCHKSUM_SHIFT)) & SGI_SGI_KEYCHK_KEYCHKSUM_MASK)
/*! @} */

/*! @name SGI_PRNG_SW_READ - SGI PRNG read register */
/*! @{ */

#define SGI_SGI_PRNG_SW_READ_RANDOM_MASK         (0xFFFFFFFFU)
#define SGI_SGI_PRNG_SW_READ_RANDOM_SHIFT        (0U)
/*! RANDOM - 32-bit field to return random data from PRNG */
#define SGI_SGI_PRNG_SW_READ_RANDOM(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_PRNG_SW_READ_RANDOM_SHIFT)) & SGI_SGI_PRNG_SW_READ_RANDOM_MASK)
/*! @} */

/*! @name SGI_CTRL - SGI Control register */
/*! @{ */

#define SGI_SGI_CTRL_START_MASK                  (0x1U)
#define SGI_SGI_CTRL_START_SHIFT                 (0U)
/*! START - Start crypto operation
 *  0b0..Clr has no effect
 *  0b1..Set to start operation
 */
#define SGI_SGI_CTRL_START(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_START_SHIFT)) & SGI_SGI_CTRL_START_MASK)

#define SGI_SGI_CTRL_DECRYPT_MASK                (0x2U)
#define SGI_SGI_CTRL_DECRYPT_SHIFT               (1U)
/*! DECRYPT
 *  0b0..Encryption
 *  0b1..Decryption
 */
#define SGI_SGI_CTRL_DECRYPT(x)                  (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_DECRYPT_SHIFT)) & SGI_SGI_CTRL_DECRYPT_MASK)

#define SGI_SGI_CTRL_AESKEYSZ_MASK               (0xCU)
#define SGI_SGI_CTRL_AESKEYSZ_SHIFT              (2U)
/*! AESKEYSZ
 *  0b00..AES-128
 *  0b01..AES-192
 *  0b10..AES-256
 *  0b11..RFU (defaults to AES-128)
 */
#define SGI_SGI_CTRL_AESKEYSZ(x)                 (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_AESKEYSZ_SHIFT)) & SGI_SGI_CTRL_AESKEYSZ_MASK)

#define SGI_SGI_CTRL_CRYPTO_OP_MASK              (0x70U)
#define SGI_SGI_CTRL_CRYPTO_OP_SHIFT             (4U)
/*! CRYPTO_OP - Sets 'Crypto Operation' type
 *  0b000..AES
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..GFMUL(If Included)
 *  0b100..SHA2 (If Included)
 *  0b101..CMAC (If Included)
 *  0b110-0b111..others - RFU (Defaults to 1st available OP)
 */
#define SGI_SGI_CTRL_CRYPTO_OP(x)                (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_CRYPTO_OP_SHIFT)) & SGI_SGI_CTRL_CRYPTO_OP_MASK)

#define SGI_SGI_CTRL_INSEL_MASK                  (0x780U)
#define SGI_SGI_CTRL_INSEL_SHIFT                 (7U)
/*! INSEL
 *  0b0000..DATIN[0]
 *  0b0001..DATIN[1]*
 *  0b0010..DATIN[2]*
 *  0b0011..DATIN[3]*
 *  0b0100..DATIN[0] ^ DATOUT
 *  0b0101..DATIN[1] ^ DATOUT*
 *  0b0110..DATIN[2] ^ DATOUT*
 *  0b0111..DATIN[3] ^ DATOUT*
 *  0b1000..DATOUT
 *  0b1001-0b1111..others - DATIN[0] * - only if DATIN[num] exists, else [0]
 */
#define SGI_SGI_CTRL_INSEL(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_INSEL_SHIFT)) & SGI_SGI_CTRL_INSEL_MASK)

#define SGI_SGI_CTRL_OUTSEL_MASK                 (0x3800U)
#define SGI_SGI_CTRL_OUTSEL_SHIFT                (11U)
/*! OUTSEL
 *  0b000..DATOUT = 'Kernel Res'
 *  0b001..DATOUT = 'Kernel Res' ^ DATIN[0]
 *  0b010..DATOUT = 'Kernel Res' ^ DATIN[1]*
 *  0b011..DATOUT = 'Kernel Res' ^ DATIN[2]*
 *  0b100..DATOUT = 'Kernel Res' ^DATIN[3]*
 *  0b101-0b111..others - DATOUT = 'Kernel Res' * - only if DATIN[num] exists, else [0]
 */
#define SGI_SGI_CTRL_OUTSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_OUTSEL_SHIFT)) & SGI_SGI_CTRL_OUTSEL_MASK)

#define SGI_SGI_CTRL_DATOUT_RES_MASK             (0xC000U)
#define SGI_SGI_CTRL_DATOUT_RES_SHIFT            (14U)
/*! DATOUT_RES
 *  0b00..END_UP
 *  0b01..START_UP
 *  0b10..TRIGGER_UP
 *  0b11..NO_UP
 */
#define SGI_SGI_CTRL_DATOUT_RES(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_DATOUT_RES_SHIFT)) & SGI_SGI_CTRL_DATOUT_RES_MASK)

#define SGI_SGI_CTRL_AES_EN_MASK                 (0x10000U)
#define SGI_SGI_CTRL_AES_EN_SHIFT                (16U)
/*! AES_EN
 *  0b0..AES disabled
 *  0b1..AES enabled
 */
#define SGI_SGI_CTRL_AES_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_AES_EN_SHIFT)) & SGI_SGI_CTRL_AES_EN_MASK)

#define SGI_SGI_CTRL_GCM_EN_MASK                 (0x40000U)
#define SGI_SGI_CTRL_GCM_EN_SHIFT                (18U)
/*! GCM_EN
 *  0b0..GFMUL disabled
 *  0b1..GFMUL enabled
 */
#define SGI_SGI_CTRL_GCM_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_GCM_EN_SHIFT)) & SGI_SGI_CTRL_GCM_EN_MASK)

#define SGI_SGI_CTRL_PRNG_EN_MASK                (0x80000U)
#define SGI_SGI_CTRL_PRNG_EN_SHIFT               (19U)
/*! PRNG_EN - PRNG Enable (only if SGI has internal PRNG)
 *  0b0..PRNG Disabled
 *  0b1..PRNG Enabled
 */
#define SGI_SGI_CTRL_PRNG_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_PRNG_EN_SHIFT)) & SGI_SGI_CTRL_PRNG_EN_MASK)

#define SGI_SGI_CTRL_INKEYSEL_MASK               (0x1F00000U)
#define SGI_SGI_CTRL_INKEYSEL_SHIFT              (20U)
/*! INKEYSEL - Input key selection */
#define SGI_SGI_CTRL_INKEYSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_INKEYSEL_SHIFT)) & SGI_SGI_CTRL_INKEYSEL_MASK)

#define SGI_SGI_CTRL_AES_NO_KL_MASK              (0x4000000U)
#define SGI_SGI_CTRL_AES_NO_KL_SHIFT             (26U)
/*! AES_NO_KL
 *  0b0..new AES key will be loaded
 *  0b1..No AES key will be loaded, and previously loaded key will be used.
 */
#define SGI_SGI_CTRL_AES_NO_KL(x)                (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_AES_NO_KL_SHIFT)) & SGI_SGI_CTRL_AES_NO_KL_MASK)

#define SGI_SGI_CTRL_AES_SEL_MASK                (0x8000000U)
#define SGI_SGI_CTRL_AES_SEL_SHIFT               (27U)
/*! AES_SEL
 *  0b0..First AES selected
 *  0b1..Second AES selected (when enabled)
 */
#define SGI_SGI_CTRL_AES_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL_AES_SEL_SHIFT)) & SGI_SGI_CTRL_AES_SEL_MASK)
/*! @} */

/*! @name SGI_CTRL2 - SGI Control register 2 */
/*! @{ */

#define SGI_SGI_CTRL2_FLUSH_MASK                 (0x1U)
#define SGI_SGI_CTRL2_FLUSH_SHIFT                (0U)
/*! FLUSH - Start Full SGI Flush
 *  0b0..Clr has no effect
 *  0b1..Set to start flush
 */
#define SGI_SGI_CTRL2_FLUSH(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_FLUSH_SHIFT)) & SGI_SGI_CTRL2_FLUSH_MASK)

#define SGI_SGI_CTRL2_KEY_FLUSH_MASK             (0x2U)
#define SGI_SGI_CTRL2_KEY_FLUSH_SHIFT            (1U)
/*! KEY_FLUSH - Start KEY register-bank Flush
 *  0b0..Clr has no effect
 *  0b1..Set to start flush
 */
#define SGI_SGI_CTRL2_KEY_FLUSH(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_KEY_FLUSH_SHIFT)) & SGI_SGI_CTRL2_KEY_FLUSH_MASK)

#define SGI_SGI_CTRL2_DATIN_FLUSH_MASK           (0x4U)
#define SGI_SGI_CTRL2_DATIN_FLUSH_SHIFT          (2U)
/*! DATIN_FLUSH - Start DATIN register-bank Flush
 *  0b0..Clr has no effect
 *  0b1..Set to start flush
 */
#define SGI_SGI_CTRL2_DATIN_FLUSH(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_DATIN_FLUSH_SHIFT)) & SGI_SGI_CTRL2_DATIN_FLUSH_MASK)

#define SGI_SGI_CTRL2_INCR_MASK                  (0x8U)
#define SGI_SGI_CTRL2_INCR_SHIFT                 (3U)
/*! INCR - Increment(Triggered by SFR write)
 *  0b0..INCR-On-Write disabled
 *  0b1..INCR-On-Write enabled
 */
#define SGI_SGI_CTRL2_INCR(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_INCR_SHIFT)) & SGI_SGI_CTRL2_INCR_MASK)

#define SGI_SGI_CTRL2_XORWR_MASK                 (0x10U)
#define SGI_SGI_CTRL2_XORWR_SHIFT                (4U)
/*! XORWR - Write-XOR control
 *  0b0..XOR-On-Write disabled
 *  0b1..XOR-On-Write enabled
 */
#define SGI_SGI_CTRL2_XORWR(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_XORWR_SHIFT)) & SGI_SGI_CTRL2_XORWR_MASK)

#define SGI_SGI_CTRL2_FLUSHWR_MASK               (0x20U)
#define SGI_SGI_CTRL2_FLUSHWR_SHIFT              (5U)
/*! FLUSHWR - Flush Write control
 *  0b0..Flush-Write disabled
 *  0b1..Flush-Write enabled
 */
#define SGI_SGI_CTRL2_FLUSHWR(x)                 (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_FLUSHWR_SHIFT)) & SGI_SGI_CTRL2_FLUSHWR_MASK)

#define SGI_SGI_CTRL2_INCR_CIN_MASK              (0x40U)
#define SGI_SGI_CTRL2_INCR_CIN_SHIFT             (6U)
/*! INCR_CIN - Increment Carry-In control
 *  0b0..Carry-In for INCR is 1
 *  0b1..Carry-In for INCR is overflow from previous INCR operation
 */
#define SGI_SGI_CTRL2_INCR_CIN(x)                (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_INCR_CIN_SHIFT)) & SGI_SGI_CTRL2_INCR_CIN_MASK)

#define SGI_SGI_CTRL2_SMASKEN_MASK               (0x100U)
#define SGI_SGI_CTRL2_SMASKEN_SHIFT              (8U)
/*! SMASKEN - SFRMASK Enable
 *  0b0..SFRMASK feature Disabled
 *  0b1..SFRMASK feature Enabled
 */
#define SGI_SGI_CTRL2_SMASKEN(x)                 (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_SMASKEN_SHIFT)) & SGI_SGI_CTRL2_SMASKEN_MASK)

#define SGI_SGI_CTRL2_SMASKSTEP_MASK             (0x200U)
#define SGI_SGI_CTRL2_SMASKSTEP_SHIFT            (9U)
/*! SMASKSTEP - SFRSEED increment control
 *  0b0..SFRSEED increments every regbank access
 *  0b1..SFRSEED increments every regbank access PLUS when SFRSEED in read
 */
#define SGI_SGI_CTRL2_SMASKSTEP(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_SMASKSTEP_SHIFT)) & SGI_SGI_CTRL2_SMASKSTEP_MASK)

#define SGI_SGI_CTRL2_SMASKSW_MASK               (0x400U)
#define SGI_SGI_CTRL2_SMASKSW_SHIFT              (10U)
/*! SMASKSW - SFRMASK MASK control
 *  0b0..SFR MASK output directly controlled by HW mask generator
 *  0b1..SFR MASK output directly controlled by SW
 */
#define SGI_SGI_CTRL2_SMASKSW(x)                 (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_SMASKSW_SHIFT)) & SGI_SGI_CTRL2_SMASKSW_MASK)

#define SGI_SGI_CTRL2_MOVEM_MASK                 (0xF000U)
#define SGI_SGI_CTRL2_MOVEM_SHIFT                (12U)
/*! MOVEM - 4-bit optional input for MOVEM feature */
#define SGI_SGI_CTRL2_MOVEM(x)                   (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_MOVEM_SHIFT)) & SGI_SGI_CTRL2_MOVEM_MASK)

#define SGI_SGI_CTRL2_KEYRES_MASK                (0x1F0000U)
#define SGI_SGI_CTRL2_KEYRES_SHIFT               (16U)
/*! KEYRES - Selects key registers to be updated when rkey=1 */
#define SGI_SGI_CTRL2_KEYRES(x)                  (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_KEYRES_SHIFT)) & SGI_SGI_CTRL2_KEYRES_MASK)

#define SGI_SGI_CTRL2_RKEY_MASK                  (0x200000U)
#define SGI_SGI_CTRL2_RKEY_SHIFT                 (21U)
/*! RKEY - Crypto result location
 *  0b0..DATOUT register bank
 *  0b1..KEY register bank
 */
#define SGI_SGI_CTRL2_RKEY(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_RKEY_SHIFT)) & SGI_SGI_CTRL2_RKEY_MASK)

#define SGI_SGI_CTRL2_BYTES_ORDER_MASK           (0x400000U)
#define SGI_SGI_CTRL2_BYTES_ORDER_SHIFT          (22U)
/*! BYTES_ORDER - Byte order of regbank read/write data
 *  0b0..Normal
 *  0b1..Swapped
 */
#define SGI_SGI_CTRL2_BYTES_ORDER(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_BYTES_ORDER_SHIFT)) & SGI_SGI_CTRL2_BYTES_ORDER_MASK)

#define SGI_SGI_CTRL2_GCM_INXOR_MASK             (0x800000U)
#define SGI_SGI_CTRL2_GCM_INXOR_SHIFT            (23U)
/*! GCM_INXOR - GCM INXOR
 *  0b0..GCM INXOR disabled
 *  0b1..GCM INXOR enabled
 */
#define SGI_SGI_CTRL2_GCM_INXOR(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CTRL2_GCM_INXOR_SHIFT)) & SGI_SGI_CTRL2_GCM_INXOR_MASK)
/*! @} */

/*! @name SGI_DUMMY_CTRL - Configuration of dummy controls */
/*! @{ */

#define SGI_SGI_DUMMY_CTRL_ADCTRL_MASK           (0x3FF0000U)
#define SGI_SGI_DUMMY_CTRL_ADCTRL_SHIFT          (16U)
#define SGI_SGI_DUMMY_CTRL_ADCTRL(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_DUMMY_CTRL_ADCTRL_SHIFT)) & SGI_SGI_DUMMY_CTRL_ADCTRL_MASK)
/*! @} */

/*! @name SGI_SFRSEED - SFRSEED register for SFRMASK feature */
/*! @{ */

#define SGI_SGI_SFRSEED_SFRSEED_MASK             (0xFFFFFFFFU)
#define SGI_SGI_SFRSEED_SFRSEED_SHIFT            (0U)
/*! SFRSEED - Seed/mask used for sw level masking */
#define SGI_SGI_SFRSEED_SFRSEED(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SFRSEED_SFRSEED_SHIFT)) & SGI_SGI_SFRSEED_SFRSEED_MASK)
/*! @} */

/*! @name SGI_SHA2_CTRL - SHA Control Register */
/*! @{ */

#define SGI_SGI_SHA2_CTRL_SHA2_EN_MASK           (0x1U)
#define SGI_SGI_SHA2_CTRL_SHA2_EN_SHIFT          (0U)
/*! SHA2_EN - SHA enable
 *  0b0..SHA disabled
 *  0b1..SHA enabled
 */
#define SGI_SGI_SHA2_CTRL_SHA2_EN(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_SHA2_EN_SHIFT)) & SGI_SGI_SHA2_CTRL_SHA2_EN_MASK)

#define SGI_SGI_SHA2_CTRL_SHA2_MODE_MASK         (0x2U)
#define SGI_SGI_SHA2_CTRL_SHA2_MODE_SHIFT        (1U)
/*! SHA2_MODE - SHA mode normal or automatic
 *  0b0..SHA NORM Mode
 *  0b1..SHA AUTO Mode
 */
#define SGI_SGI_SHA2_CTRL_SHA2_MODE(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_SHA2_MODE_SHIFT)) & SGI_SGI_SHA2_CTRL_SHA2_MODE_MASK)

#define SGI_SGI_SHA2_CTRL_SHA2_SIZE_MASK         (0xCU)
#define SGI_SGI_SHA2_CTRL_SHA2_SIZE_SHIFT        (2U)
/*! SHA2_SIZE
 *  0b00..SHA-224
 *  0b01..SHA-256
 *  0b10..SHA-384(or SHA-224 if SHA-256 only)
 *  0b11..SHA-512 (or SHA-256 if SHA-256 only)
 */
#define SGI_SGI_SHA2_CTRL_SHA2_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_SHA2_SIZE_SHIFT)) & SGI_SGI_SHA2_CTRL_SHA2_SIZE_MASK)

#define SGI_SGI_SHA2_CTRL_SHA2_LOW_LIM_MASK      (0xF0U)
#define SGI_SGI_SHA2_CTRL_SHA2_LOW_LIM_SHIFT     (4U)
/*! SHA2_LOW_LIM - SHA FIFO low limit */
#define SGI_SGI_SHA2_CTRL_SHA2_LOW_LIM(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_SHA2_LOW_LIM_SHIFT)) & SGI_SGI_SHA2_CTRL_SHA2_LOW_LIM_MASK)

#define SGI_SGI_SHA2_CTRL_SHA2_HIGH_LIM_MASK     (0xF00U)
#define SGI_SGI_SHA2_CTRL_SHA2_HIGH_LIM_SHIFT    (8U)
/*! SHA2_HIGH_LIM - SHA FIFO high limit */
#define SGI_SGI_SHA2_CTRL_SHA2_HIGH_LIM(x)       (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_SHA2_HIGH_LIM_SHIFT)) & SGI_SGI_SHA2_CTRL_SHA2_HIGH_LIM_MASK)

#define SGI_SGI_SHA2_CTRL_SHA2_COUNT_EN_MASK     (0x1000U)
#define SGI_SGI_SHA2_CTRL_SHA2_COUNT_EN_SHIFT    (12U)
/*! SHA2_COUNT_EN - SHA Calculation counter enable
 *  0b0..SHA operation DOES NOT increment COUNT
 *  0b1..SHA operation DOES increment count
 */
#define SGI_SGI_SHA2_CTRL_SHA2_COUNT_EN(x)       (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_SHA2_COUNT_EN_SHIFT)) & SGI_SGI_SHA2_CTRL_SHA2_COUNT_EN_MASK)

#define SGI_SGI_SHA2_CTRL_HASH_RELOAD_MASK       (0x2000U)
#define SGI_SGI_SHA2_CTRL_HASH_RELOAD_SHIFT      (13U)
/*! HASH_RELOAD - SHA HASH reload
 *  0b0..No HASH reload
 *  0b1..HASH reload enabled
 */
#define SGI_SGI_SHA2_CTRL_HASH_RELOAD(x)         (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_HASH_RELOAD_SHIFT)) & SGI_SGI_SHA2_CTRL_HASH_RELOAD_MASK)

#define SGI_SGI_SHA2_CTRL_SHA2_STOP_MASK         (0x4000U)
#define SGI_SGI_SHA2_CTRL_SHA2_STOP_SHIFT        (14U)
/*! SHA2_STOP - STOP SHA AUTO mode
 *  0b0..Keep running
 *  0b1..Stop auto mode
 */
#define SGI_SGI_SHA2_CTRL_SHA2_STOP(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_SHA2_STOP_SHIFT)) & SGI_SGI_SHA2_CTRL_SHA2_STOP_MASK)

#define SGI_SGI_SHA2_CTRL_NO_AUTO_INIT_MASK      (0x8000U)
#define SGI_SGI_SHA2_CTRL_NO_AUTO_INIT_SHIFT     (15U)
/*! NO_AUTO_INIT - SHA no automatic HASH initialisation
 *  0b0..SHA automatic HASH initialisation
 *  0b1..No SHA automatic HASH initialisation
 */
#define SGI_SGI_SHA2_CTRL_NO_AUTO_INIT(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA2_CTRL_NO_AUTO_INIT_SHIFT)) & SGI_SGI_SHA2_CTRL_NO_AUTO_INIT_MASK)
/*! @} */

/*! @name SGI_SHA_FIFO - SHA FIFO lower-bank low */
/*! @{ */

#define SGI_SGI_SHA_FIFO_FIFO_MASK               (0xFFFFFFFFU)
#define SGI_SGI_SHA_FIFO_FIFO_SHIFT              (0U)
/*! FIFO - SHA FIFO register */
#define SGI_SGI_SHA_FIFO_FIFO(x)                 (((uint32_t)(((uint32_t)(x)) << SGI_SGI_SHA_FIFO_FIFO_SHIFT)) & SGI_SGI_SHA_FIFO_FIFO_MASK)
/*! @} */

/*! @name SGI_CONFIG - SHA Configuration Reg */
/*! @{ */

#define SGI_SGI_CONFIG_ROW_MASK                  (0x1U)
#define SGI_SGI_CONFIG_ROW_SHIFT                 (0U)
/*! ROW - SGI Diversified for 'ROW' */
#define SGI_SGI_CONFIG_ROW(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_ROW_SHIFT)) & SGI_SGI_CONFIG_ROW_MASK)

#define SGI_SGI_CONFIG_CHINA_MASK                (0x2U)
#define SGI_SGI_CONFIG_CHINA_SHIFT               (1U)
/*! CHINA - SGI Diversified for 'CHINA' */
#define SGI_SGI_CONFIG_CHINA(x)                  (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_CHINA_SHIFT)) & SGI_SGI_CONFIG_CHINA_MASK)

#define SGI_SGI_CONFIG_CC_MASK                   (0x4U)
#define SGI_SGI_CONFIG_CC_SHIFT                  (2U)
/*! CC - SGI Diversified for 'CC' */
#define SGI_SGI_CONFIG_CC(x)                     (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_CC_SHIFT)) & SGI_SGI_CONFIG_CC_MASK)

#define SGI_SGI_CONFIG_HAS_AES_MASK              (0x8U)
#define SGI_SGI_CONFIG_HAS_AES_SHIFT             (3U)
/*! HAS_AES - HAS AES */
#define SGI_SGI_CONFIG_HAS_AES(x)                (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_HAS_AES_SHIFT)) & SGI_SGI_CONFIG_HAS_AES_MASK)

#define SGI_SGI_CONFIG_HAS_DES_MASK              (0x10U)
#define SGI_SGI_CONFIG_HAS_DES_SHIFT             (4U)
/*! HAS_DES - HAS DES */
#define SGI_SGI_CONFIG_HAS_DES(x)                (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_HAS_DES_SHIFT)) & SGI_SGI_CONFIG_HAS_DES_MASK)

#define SGI_SGI_CONFIG_HAS_SHA_MASK              (0x20U)
#define SGI_SGI_CONFIG_HAS_SHA_SHIFT             (5U)
/*! HAS_SHA - HAS SHA */
#define SGI_SGI_CONFIG_HAS_SHA(x)                (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_HAS_SHA_SHIFT)) & SGI_SGI_CONFIG_HAS_SHA_MASK)

#define SGI_SGI_CONFIG_HAS_MOVEM_MASK            (0x40U)
#define SGI_SGI_CONFIG_HAS_MOVEM_SHIFT           (6U)
/*! HAS_MOVEM - HAS MOVEM */
#define SGI_SGI_CONFIG_HAS_MOVEM(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_HAS_MOVEM_SHIFT)) & SGI_SGI_CONFIG_HAS_MOVEM_MASK)

#define SGI_SGI_CONFIG_HAS_CMAC_MASK             (0x80U)
#define SGI_SGI_CONFIG_HAS_CMAC_SHIFT            (7U)
/*! HAS_CMAC - HAS CMAC */
#define SGI_SGI_CONFIG_HAS_CMAC(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_HAS_CMAC_SHIFT)) & SGI_SGI_CONFIG_HAS_CMAC_MASK)

#define SGI_SGI_CONFIG_HAS_GFMUL_MASK            (0x100U)
#define SGI_SGI_CONFIG_HAS_GFMUL_SHIFT           (8U)
/*! HAS_GFMUL - HAS GFMUL */
#define SGI_SGI_CONFIG_HAS_GFMUL(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_HAS_GFMUL_SHIFT)) & SGI_SGI_CONFIG_HAS_GFMUL_MASK)

#define SGI_SGI_CONFIG_INTERNAL_PRNG_MASK        (0x200U)
#define SGI_SGI_CONFIG_INTERNAL_PRNG_SHIFT       (9U)
/*! INTERNAL_PRNG - HAS INTERNAL PRNG */
#define SGI_SGI_CONFIG_INTERNAL_PRNG(x)          (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_INTERNAL_PRNG_SHIFT)) & SGI_SGI_CONFIG_INTERNAL_PRNG_MASK)

#define SGI_SGI_CONFIG_KEY_DIGEST_MASK           (0x400U)
#define SGI_SGI_CONFIG_KEY_DIGEST_SHIFT          (10U)
/*! KEY_DIGEST - HAS KEY DIGEST */
#define SGI_SGI_CONFIG_KEY_DIGEST(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_KEY_DIGEST_SHIFT)) & SGI_SGI_CONFIG_KEY_DIGEST_MASK)

#define SGI_SGI_CONFIG_COUNT_SIZE_MASK           (0x800U)
#define SGI_SGI_CONFIG_COUNT_SIZE_SHIFT          (11U)
/*! COUNT_SIZE - 0 - COUNT=16, 1 - COUNT=32 */
#define SGI_SGI_CONFIG_COUNT_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_COUNT_SIZE_SHIFT)) & SGI_SGI_CONFIG_COUNT_SIZE_MASK)

#define SGI_SGI_CONFIG_FA_MASK                   (0x2000U)
#define SGI_SGI_CONFIG_FA_SHIFT                  (13U)
/*! FA - HAS FA protection */
#define SGI_SGI_CONFIG_FA(x)                     (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_FA_SHIFT)) & SGI_SGI_CONFIG_FA_MASK)

#define SGI_SGI_CONFIG_BUS_WIDTH_MASK            (0x8000U)
#define SGI_SGI_CONFIG_BUS_WIDTH_SHIFT           (15U)
/*! BUS_WIDTH - 0 - BUS_WIDTH=16, 1 - BUS_WIDTH=32 */
#define SGI_SGI_CONFIG_BUS_WIDTH(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_BUS_WIDTH_SHIFT)) & SGI_SGI_CONFIG_BUS_WIDTH_MASK)

#define SGI_SGI_CONFIG_NUM_DATIN_MASK            (0x30000U)
#define SGI_SGI_CONFIG_NUM_DATIN_SHIFT           (16U)
/*! NUM_DATIN - NUMBER OF DATIN REGBANKS */
#define SGI_SGI_CONFIG_NUM_DATIN(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_NUM_DATIN_SHIFT)) & SGI_SGI_CONFIG_NUM_DATIN_MASK)

#define SGI_SGI_CONFIG_NUM_KEY_MASK              (0x1C0000U)
#define SGI_SGI_CONFIG_NUM_KEY_SHIFT             (18U)
/*! NUM_KEY - NUMBER OR KEY REGBANKS */
#define SGI_SGI_CONFIG_NUM_KEY(x)                (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_NUM_KEY_SHIFT)) & SGI_SGI_CONFIG_NUM_KEY_MASK)

#define SGI_SGI_CONFIG_EDC_MASK                  (0x200000U)
#define SGI_SGI_CONFIG_EDC_SHIFT                 (21U)
/*! EDC - DATIN to KERNEL End-to-end EDC is enabled */
#define SGI_SGI_CONFIG_EDC(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_EDC_SHIFT)) & SGI_SGI_CONFIG_EDC_MASK)

#define SGI_SGI_CONFIG_SHA_256_ONLY_MASK         (0x1000000U)
#define SGI_SGI_CONFIG_SHA_256_ONLY_SHIFT        (24U)
/*! SHA_256_ONLY - HAS SHA-256 ONLY */
#define SGI_SGI_CONFIG_SHA_256_ONLY(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_SHA_256_ONLY_SHIFT)) & SGI_SGI_CONFIG_SHA_256_ONLY_MASK)

#define SGI_SGI_CONFIG_SPB_SUPPORT_MASK          (0x2000000U)
#define SGI_SGI_CONFIG_SPB_SUPPORT_SHIFT         (25U)
/*! SPB_SUPPORT - ID_CFG_SGI_SPB_SUPPORT is set */
#define SGI_SGI_CONFIG_SPB_SUPPORT(x)            (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_SPB_SUPPORT_SHIFT)) & SGI_SGI_CONFIG_SPB_SUPPORT_MASK)

#define SGI_SGI_CONFIG_SPB_MASKING_MASK          (0x4000000U)
#define SGI_SGI_CONFIG_SPB_MASKING_SHIFT         (26U)
/*! SPB_MASKING - ID_CFG_SGI_SPB_MASKING is set */
#define SGI_SGI_CONFIG_SPB_MASKING(x)            (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_SPB_MASKING_SHIFT)) & SGI_SGI_CONFIG_SPB_MASKING_MASK)

#define SGI_SGI_CONFIG_SFR_SW_MASK_MASK          (0x8000000U)
#define SGI_SGI_CONFIG_SFR_SW_MASK_SHIFT         (27U)
/*! SFR_SW_MASK - ID_CFG_SGI_USE_SFR_SW_MASK is set */
#define SGI_SGI_CONFIG_SFR_SW_MASK(x)            (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG_SFR_SW_MASK_SHIFT)) & SGI_SGI_CONFIG_SFR_SW_MASK_MASK)
/*! @} */

/*! @name SGI_CONFIG2 - SHA Configuration 2 Reg */
/*! @{ */

#define SGI_SGI_CONFIG2_AES_USED_MASK            (0xFU)
#define SGI_SGI_CONFIG2_AES_USED_SHIFT           (0U)
/*! AES_USED
 *  0b0000..Apollo
 *  0b0001..Aegis
 *  0b0010..Ayna
 *  0b0011..Athenium
 *  0b0100..Ajax
 *  0b0101..Aegis_hs
 *  0b0110..Athenium_hs
 *  0b0111..ATE
 *  0b1000..ATOM
 *  0b1001..Asterix
 *  0b1010-0b1111..RFU
 */
#define SGI_SGI_CONFIG2_AES_USED(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG2_AES_USED_SHIFT)) & SGI_SGI_CONFIG2_AES_USED_MASK)

#define SGI_SGI_CONFIG2_AES_NUM_SBOXES_MASK      (0x1F0U)
#define SGI_SGI_CONFIG2_AES_NUM_SBOXES_SHIFT     (4U)
/*! AES_NUM_SBOXES - Number of AES sboxes */
#define SGI_SGI_CONFIG2_AES_NUM_SBOXES(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG2_AES_NUM_SBOXES_SHIFT)) & SGI_SGI_CONFIG2_AES_NUM_SBOXES_MASK)

#define SGI_SGI_CONFIG2_AES_KEYSIZE_MASK         (0x600U)
#define SGI_SGI_CONFIG2_AES_KEYSIZE_SHIFT        (9U)
/*! AES_KEYSIZE
 *  0b00..128 0nly
 *  0b01..192 only
 *  0b10..256 only
 *  0b11..All key sizes
 */
#define SGI_SGI_CONFIG2_AES_KEYSIZE(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG2_AES_KEYSIZE_SHIFT)) & SGI_SGI_CONFIG2_AES_KEYSIZE_MASK)

#define SGI_SGI_CONFIG2_DES_USED_MASK            (0xF0000U)
#define SGI_SGI_CONFIG2_DES_USED_SHIFT           (16U)
/*! DES_USED
 *  0b0000..Dakar
 *  0b0001..Danube
 *  0b0010..Depicta
 *  0b0011..Digi
 *  0b0100..Date
 *  0b0101..Desert
 *  0b0110-0b1111..RFU
 */
#define SGI_SGI_CONFIG2_DES_USED(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG2_DES_USED_SHIFT)) & SGI_SGI_CONFIG2_DES_USED_MASK)

#define SGI_SGI_CONFIG2_DES_NUM_SBOXES_MASK      (0x1F00000U)
#define SGI_SGI_CONFIG2_DES_NUM_SBOXES_SHIFT     (20U)
/*! DES_NUM_SBOXES - Number of DES sboxes */
#define SGI_SGI_CONFIG2_DES_NUM_SBOXES(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_CONFIG2_DES_NUM_SBOXES_SHIFT)) & SGI_SGI_CONFIG2_DES_NUM_SBOXES_MASK)
/*! @} */

/*! @name SGI_AUTO_MODE - SGI Auto Mode Control register */
/*! @{ */

#define SGI_SGI_AUTO_MODE_AUTO_MODE_EN_MASK      (0x1U)
#define SGI_SGI_AUTO_MODE_AUTO_MODE_EN_SHIFT     (0U)
/*! AUTO_MODE_EN - auto_start_en
 *  0b1..auto mode has been selected
 */
#define SGI_SGI_AUTO_MODE_AUTO_MODE_EN(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_AUTO_MODE_AUTO_MODE_EN_SHIFT)) & SGI_SGI_AUTO_MODE_AUTO_MODE_EN_MASK)

#define SGI_SGI_AUTO_MODE_AUTO_MODE_STOP_MASK    (0x2U)
#define SGI_SGI_AUTO_MODE_AUTO_MODE_STOP_SHIFT   (1U)
/*! AUTO_MODE_STOP - auto_mode_stop
 *  0b1..exit auto mode as soon as the data has been emptied
 */
#define SGI_SGI_AUTO_MODE_AUTO_MODE_STOP(x)      (((uint32_t)(((uint32_t)(x)) << SGI_SGI_AUTO_MODE_AUTO_MODE_STOP_SHIFT)) & SGI_SGI_AUTO_MODE_AUTO_MODE_STOP_MASK)

#define SGI_SGI_AUTO_MODE_INCR_MODE_MASK         (0x30U)
#define SGI_SGI_AUTO_MODE_INCR_MODE_SHIFT        (4U)
/*! INCR_MODE - CTR increment mode
 *  0b00..2**32 increment mode
 *  0b01..2**64 increment mode
 *  0b10..2**96 increment mode
 *  0b11..2**128 increment mode
 */
#define SGI_SGI_AUTO_MODE_INCR_MODE(x)           (((uint32_t)(((uint32_t)(x)) << SGI_SGI_AUTO_MODE_INCR_MODE_SHIFT)) & SGI_SGI_AUTO_MODE_INCR_MODE_MASK)

#define SGI_SGI_AUTO_MODE_CMD_MASK               (0xFF00U)
#define SGI_SGI_AUTO_MODE_CMD_SHIFT              (8U)
/*! CMD - Auto mode of operation
 *  0b00000000..ECB mode
 *  0b00000001..CTR mode
 *  0b00000010..CBC mode
 *  0b00000011..CBCMAC mode
 *  0b00010000..Key Wrap/Unwrap (128 bit key data)
 *  0b00010001..Key Wrap/Unwrap (256 bit key data)
 */
#define SGI_SGI_AUTO_MODE_CMD(x)                 (((uint32_t)(((uint32_t)(x)) << SGI_SGI_AUTO_MODE_CMD_SHIFT)) & SGI_SGI_AUTO_MODE_CMD_MASK)
/*! @} */

/*! @name SGI_AUTO_DMA_CTRL - SGI Auto Mode Control register */
/*! @{ */

#define SGI_SGI_AUTO_DMA_CTRL_IFE_MASK           (0x1U)
#define SGI_SGI_AUTO_DMA_CTRL_IFE_SHIFT          (0U)
/*! IFE - Input FIFO DMA Enable
 *  0b0..DMA handshake disabled
 *  0b1..DMA handshake enabled
 */
#define SGI_SGI_AUTO_DMA_CTRL_IFE(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_AUTO_DMA_CTRL_IFE_SHIFT)) & SGI_SGI_AUTO_DMA_CTRL_IFE_MASK)

#define SGI_SGI_AUTO_DMA_CTRL_OFE_MASK           (0x100U)
#define SGI_SGI_AUTO_DMA_CTRL_OFE_SHIFT          (8U)
/*! OFE - Ouput FIFO DMA Enable
 *  0b0..DMA handshake disabled
 *  0b1..DMA handshake enabled
 */
#define SGI_SGI_AUTO_DMA_CTRL_OFE(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_AUTO_DMA_CTRL_OFE_SHIFT)) & SGI_SGI_AUTO_DMA_CTRL_OFE_MASK)
/*! @} */

/*! @name SGI_PRNG_SW_SEED - SGI internal PRNG SW seeding register */
/*! @{ */

#define SGI_SGI_PRNG_SW_SEED_SEED_MASK           (0xFFFFFFFFU)
#define SGI_SGI_PRNG_SW_SEED_SEED_SHIFT          (0U)
#define SGI_SGI_PRNG_SW_SEED_SEED(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_PRNG_SW_SEED_SEED_SHIFT)) & SGI_SGI_PRNG_SW_SEED_SEED_MASK)
/*! @} */

/*! @name SGI_KEY_CTRL - SGI Key Control SFR */
/*! @{ */

#define SGI_SGI_KEY_CTRL_KEY_WO_MASK             (0xFFFFFFFFU)
#define SGI_SGI_KEY_CTRL_KEY_WO_SHIFT            (0U)
#define SGI_SGI_KEY_CTRL_KEY_WO(x)               (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY_CTRL_KEY_WO_SHIFT)) & SGI_SGI_KEY_CTRL_KEY_WO_MASK)
/*! @} */

/*! @name SGI_KEY_WRAP - Wrapped key read SFR */
/*! @{ */

#define SGI_SGI_KEY_WRAP_KW_DATA_MASK            (0xFFFFFFFFU)
#define SGI_SGI_KEY_WRAP_KW_DATA_SHIFT           (0U)
/*! KW_DATA - Field contains wrapped key, auto-updated by HW for each word */
#define SGI_SGI_KEY_WRAP_KW_DATA(x)              (((uint32_t)(((uint32_t)(x)) << SGI_SGI_KEY_WRAP_KW_DATA_SHIFT)) & SGI_SGI_KEY_WRAP_KW_DATA_MASK)
/*! @} */

/*! @name SGI_VERSION - SGI Version */
/*! @{ */

#define SGI_SGI_VERSION_Z_MASK                   (0xFU)
#define SGI_SGI_VERSION_Z_SHIFT                  (0U)
/*! Z - Extended revision number in X.Y1Y2.Z, e.g. 1.20.3. */
#define SGI_SGI_VERSION_Z(x)                     (((uint32_t)(((uint32_t)(x)) << SGI_SGI_VERSION_Z_SHIFT)) & SGI_SGI_VERSION_Z_MASK)

#define SGI_SGI_VERSION_Y2_MASK                  (0xF0U)
#define SGI_SGI_VERSION_Y2_SHIFT                 (4U)
/*! Y2 - Minor revision number 2 in X.Y1Y2.Z, e.g. 1.20.3. */
#define SGI_SGI_VERSION_Y2(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_VERSION_Y2_SHIFT)) & SGI_SGI_VERSION_Y2_MASK)

#define SGI_SGI_VERSION_Y1_MASK                  (0xF00U)
#define SGI_SGI_VERSION_Y1_SHIFT                 (8U)
/*! Y1 - Minor revision number 1 in X.Y1Y2.Z, e.g. 1.20.3. */
#define SGI_SGI_VERSION_Y1(x)                    (((uint32_t)(((uint32_t)(x)) << SGI_SGI_VERSION_Y1_SHIFT)) & SGI_SGI_VERSION_Y1_MASK)

#define SGI_SGI_VERSION_X_MASK                   (0xF000U)
#define SGI_SGI_VERSION_X_SHIFT                  (12U)
/*! X - Major revision number in X.Y1Y2.Z, e.g. 1.20.3. */
#define SGI_SGI_VERSION_X(x)                     (((uint32_t)(((uint32_t)(x)) << SGI_SGI_VERSION_X_SHIFT)) & SGI_SGI_VERSION_X_MASK)

#define SGI_SGI_VERSION_MILESTONE_MASK           (0x30000U)
#define SGI_SGI_VERSION_MILESTONE_SHIFT          (16U)
/*! MILESTONE
 *  0b00..PREL
 *  0b01..BR
 *  0b10..SI
 *  0b11..GO
 */
#define SGI_SGI_VERSION_MILESTONE(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_VERSION_MILESTONE_SHIFT)) & SGI_SGI_VERSION_MILESTONE_MASK)
/*! @} */

/*! @name SGI_ACCESS_ERR - Access Error */
/*! @{ */

#define SGI_SGI_ACCESS_ERR_APB_NOTAV_MASK        (0x1U)
#define SGI_SGI_ACCESS_ERR_APB_NOTAV_SHIFT       (0U)
/*! APB_NOTAV - APB Error: address not available */
#define SGI_SGI_ACCESS_ERR_APB_NOTAV(x)          (((uint32_t)(((uint32_t)(x)) << SGI_SGI_ACCESS_ERR_APB_NOTAV_SHIFT)) & SGI_SGI_ACCESS_ERR_APB_NOTAV_MASK)

#define SGI_SGI_ACCESS_ERR_APB_WRGMD_MASK        (0x2U)
#define SGI_SGI_ACCESS_ERR_APB_WRGMD_SHIFT       (1U)
/*! APB_WRGMD - APB Error: Wrong access mode */
#define SGI_SGI_ACCESS_ERR_APB_WRGMD(x)          (((uint32_t)(((uint32_t)(x)) << SGI_SGI_ACCESS_ERR_APB_WRGMD_SHIFT)) & SGI_SGI_ACCESS_ERR_APB_WRGMD_MASK)

#define SGI_SGI_ACCESS_ERR_APB_MASTER_MASK       (0xF0U)
#define SGI_SGI_ACCESS_ERR_APB_MASTER_SHIFT      (4U)
#define SGI_SGI_ACCESS_ERR_APB_MASTER(x)         (((uint32_t)(((uint32_t)(x)) << SGI_SGI_ACCESS_ERR_APB_MASTER_SHIFT)) & SGI_SGI_ACCESS_ERR_APB_MASTER_MASK)
/*! @} */

/*! @name SGI_ACCESS_ERR_CLR - Clear Access Error */
/*! @{ */

#define SGI_SGI_ACCESS_ERR_CLR_ERR_CLR_MASK      (0x1U)
#define SGI_SGI_ACCESS_ERR_CLR_ERR_CLR_SHIFT     (0U)
/*! ERR_CLR - Write to reset SGI_ACCESS_ERR SFR. */
#define SGI_SGI_ACCESS_ERR_CLR_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_ACCESS_ERR_CLR_ERR_CLR_SHIFT)) & SGI_SGI_ACCESS_ERR_CLR_ERR_CLR_MASK)
/*! @} */

/*! @name SGI_INT_STATUS - Interrupt status */
/*! @{ */

#define SGI_SGI_INT_STATUS_INT_PDONE_MASK        (0x1U)
#define SGI_SGI_INT_STATUS_INT_PDONE_SHIFT       (0U)
#define SGI_SGI_INT_STATUS_INT_PDONE(x)          (((uint32_t)(((uint32_t)(x)) << SGI_SGI_INT_STATUS_INT_PDONE_SHIFT)) & SGI_SGI_INT_STATUS_INT_PDONE_MASK)
/*! @} */

/*! @name SGI_INT_ENABLE - Interrupt enable */
/*! @{ */

#define SGI_SGI_INT_ENABLE_INT_EN_MASK           (0x1U)
#define SGI_SGI_INT_ENABLE_INT_EN_SHIFT          (0U)
/*! INT_EN - Interrupt enable bit */
#define SGI_SGI_INT_ENABLE_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << SGI_SGI_INT_ENABLE_INT_EN_SHIFT)) & SGI_SGI_INT_ENABLE_INT_EN_MASK)
/*! @} */

/*! @name SGI_INT_STATUS_CLR - Interrupt status clear */
/*! @{ */

#define SGI_SGI_INT_STATUS_CLR_INT_CLR_MASK      (0x1U)
#define SGI_SGI_INT_STATUS_CLR_INT_CLR_SHIFT     (0U)
/*! INT_CLR - Write to clear interrupt status flag (SGI_INT_STATUS.INT_PDONE=0). */
#define SGI_SGI_INT_STATUS_CLR_INT_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_INT_STATUS_CLR_INT_CLR_SHIFT)) & SGI_SGI_INT_STATUS_CLR_INT_CLR_MASK)
/*! @} */

/*! @name SGI_INT_STATUS_SET - Interrupt status set */
/*! @{ */

#define SGI_SGI_INT_STATUS_SET_INT_SET_MASK      (0x1U)
#define SGI_SGI_INT_STATUS_SET_INT_SET_SHIFT     (0U)
/*! INT_SET - Write to set interrupt status flag (SGI_INT_STATUS.INT_PDONE=1) to trigger a SGI
 *    interrupt via software, e.g. for debug purposes.
 */
#define SGI_SGI_INT_STATUS_SET_INT_SET(x)        (((uint32_t)(((uint32_t)(x)) << SGI_SGI_INT_STATUS_SET_INT_SET_SHIFT)) & SGI_SGI_INT_STATUS_SET_INT_SET_MASK)
/*! @} */

/*! @name SGI_MODULE_ID - Module ID */
/*! @{ */

#define SGI_SGI_MODULE_ID_PLACEHOLDER_MASK       (0xFFFFFFFFU)
#define SGI_SGI_MODULE_ID_PLACEHOLDER_SHIFT      (0U)
/*! PLACEHOLDER - Module ID */
#define SGI_SGI_MODULE_ID_PLACEHOLDER(x)         (((uint32_t)(((uint32_t)(x)) << SGI_SGI_MODULE_ID_PLACEHOLDER_SHIFT)) & SGI_SGI_MODULE_ID_PLACEHOLDER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SGI_Register_Masks */


/*!
 * @}
 */ /* end of group SGI_Peripheral_Access_Layer */


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


#endif  /* PERI_SGI_H_ */

