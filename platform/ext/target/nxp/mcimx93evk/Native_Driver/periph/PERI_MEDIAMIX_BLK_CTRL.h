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
**         CMSIS Peripheral Access Layer for MEDIAMIX_BLK_CTRL
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
 * @file PERI_MEDIAMIX_BLK_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MEDIAMIX_BLK_CTRL
 *
 * CMSIS Peripheral Access Layer for MEDIAMIX_BLK_CTRL
 */

#if !defined(PERI_MEDIAMIX_BLK_CTRL_H_)
#define PERI_MEDIAMIX_BLK_CTRL_H_                /**< Symbol preventing repeated inclusion */

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
   -- MEDIAMIX_BLK_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEDIAMIX_BLK_CTRL_Peripheral_Access_Layer MEDIAMIX_BLK_CTRL Peripheral Access Layer
 * @{
 */

/** MEDIAMIX_BLK_CTRL - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
           uint8_t RESERVED_0[12];
      __IO uint32_t LCDIFr;                            /**< QOS and cache of LCDIF, offset: 0xC, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LCDIF' */
      __IO uint32_t PXPr;                              /**< QOS and cache of PXP, offset: 0x10, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'PXP' */
      __IO uint32_t ISI0;                              /**< Cache of ISI, offset: 0x14 */
           uint8_t RESERVED_1[4];
      __IO uint32_t ISI1;                              /**< QoS of ISI, offset: 0x1C */
      __IO uint32_t LDB_CTRL;                          /**< LDB Control Register, offset: 0x20 */
      __IO uint32_t LVDS;                              /**< LVDS Control Register, offset: 0x24 */
      __IO uint32_t LIMITER0;                          /**< Limiter Enable Control Register, offset: 0x28 */
      __IO uint32_t LIMITER1;                          /**< Limiter Threshold Control Register, offset: 0x2C */
    } BUS_CONTROL;
    struct {                                         /* offset: 0x0 */
      __IO uint32_t RESET;                             /**< RESET Control Register, offset: 0x0 */
      __IO uint32_t CLK;                               /**< CLK Control Register, offset: 0x4 */
    } CLK_RESETN;
    struct {                                         /* offset: 0x0 */
           uint8_t RESERVED_0[48];
      __IO uint32_t CAMERA_MUX;                        /**< Camera Mux Control Register, offset: 0x30 */
           uint8_t RESERVED_1[8];
      __I  uint32_t PIXEL_CTRL;                        /**< Read Pixel Control Register, offset: 0x3C */
      __I  uint32_t LINE_CNT;                          /**< Read Line Count Register, offset: 0x40 */
      __I  uint32_t PIXEL_CNT;                         /**< Read Pixel Count Register, offset: 0x44 */
           uint8_t RESERVED_2[24];
      __IO uint32_t DISPLAY_MUX;                       /**< Display Mux Control Register, offset: 0x60 */
           uint8_t RESERVED_3[12];
      __IO uint32_t IF_CTRL_REG;                       /**< Parallel Camera Interface Register, offset: 0x70 */
      __I  uint32_t INTERFACE_STATUS;                  /**< Interface Status Register, offset: 0x74 */
      __IO uint32_t INTERFACE_CTRL_REG;                /**< Interface Control Register, offset: 0x78 */
      __IO uint32_t INTERFACE_CTRL_REG1;               /**< Interface Control Register 1, offset: 0x7C */
    } GASKET;
    struct {                                         /* offset: 0x0 */
           uint8_t RESERVED_0[72];
      __IO uint32_t CSI;                               /**< CSI Register, offset: 0x48 */
      __IO uint32_t DSI;                               /**< DSI Register, offset: 0x4C */
      __IO uint32_t DSI_W0;                            /**< DSI Write Register 0, offset: 0x50 */
      __IO uint32_t DSI_W1;                            /**< DSI Write Register 1, offset: 0x54 */
      __I  uint32_t DSI_R0;                            /**< DSI Read Register 0, offset: 0x58 */
      __I  uint32_t DSI_R1;                            /**< DSI Read Register 1, offset: 0x5C */
    } MIPI;
  };
} MEDIAMIX_BLK_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- MEDIAMIX_BLK_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEDIAMIX_BLK_CTRL_Register_Masks MEDIAMIX_BLK_CTRL Register Masks
 * @{
 */

/*! @name LCDIF - QOS and cache of LCDIF */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_MASK     (0xFU)
#define MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_SHIFT    (0U)
/*! ARCACHE - ARCACHE value of LCDIF */
#define MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_SHIFT)) & MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_MASK)

#define MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_EN_MASK  (0x10U)
#define MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_EN_SHIFT (4U)
/*! ARCACHE_EN - ARCACHE enable of LCDIF
 *  0b0..Do not enable ARCACHE
 *  0b1..Enable ARCACHE
 */
#define MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_EN(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_LCDIF_ARCACHE_EN_MASK)

#define MEDIAMIX_BLK_CTRL_LCDIF_CFG_QOS_MASK     (0xF00U)
#define MEDIAMIX_BLK_CTRL_LCDIF_CFG_QOS_SHIFT    (8U)
/*! CFG_QOS - cfg_qos value of LCDIF */
#define MEDIAMIX_BLK_CTRL_LCDIF_CFG_QOS(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LCDIF_CFG_QOS_SHIFT)) & MEDIAMIX_BLK_CTRL_LCDIF_CFG_QOS_MASK)

#define MEDIAMIX_BLK_CTRL_LCDIF_DEFAULT_QOS_MASK (0xF000U)
#define MEDIAMIX_BLK_CTRL_LCDIF_DEFAULT_QOS_SHIFT (12U)
/*! DEFAULT_QOS - Default QoS value of LCDIF */
#define MEDIAMIX_BLK_CTRL_LCDIF_DEFAULT_QOS(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LCDIF_DEFAULT_QOS_SHIFT)) & MEDIAMIX_BLK_CTRL_LCDIF_DEFAULT_QOS_MASK)
/*! @} */

/*! @name PXP - QOS and cache of PXP */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_PXP_ARCACHE_MASK       (0xFU)
#define MEDIAMIX_BLK_CTRL_PXP_ARCACHE_SHIFT      (0U)
/*! ARCACHE - ARCACHE value of PXP */
#define MEDIAMIX_BLK_CTRL_PXP_ARCACHE(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_ARCACHE_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_ARCACHE_MASK)

#define MEDIAMIX_BLK_CTRL_PXP_ARCACHE_EN_MASK    (0x10U)
#define MEDIAMIX_BLK_CTRL_PXP_ARCACHE_EN_SHIFT   (4U)
/*! ARCACHE_EN - ARCACHE enable of PXP
 *  0b0..Do not enable ARCACHE
 *  0b1..Enable ARCACHE
 */
#define MEDIAMIX_BLK_CTRL_PXP_ARCACHE_EN(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_ARCACHE_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_ARCACHE_EN_MASK)

#define MEDIAMIX_BLK_CTRL_PXP_AWCACHE_MASK       (0xF00U)
#define MEDIAMIX_BLK_CTRL_PXP_AWCACHE_SHIFT      (8U)
/*! AWCACHE - AWCACHE value of PXP */
#define MEDIAMIX_BLK_CTRL_PXP_AWCACHE(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_AWCACHE_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_AWCACHE_MASK)

#define MEDIAMIX_BLK_CTRL_PXP_AWCACHE_EN_MASK    (0x1000U)
#define MEDIAMIX_BLK_CTRL_PXP_AWCACHE_EN_SHIFT   (12U)
/*! AWCACHE_EN - AWCACHE enable of PXP
 *  0b0..Do not enable AWCACHE
 *  0b1..Enable AWCACHE
 */
#define MEDIAMIX_BLK_CTRL_PXP_AWCACHE_EN(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_AWCACHE_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_AWCACHE_EN_MASK)

#define MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_W_MASK (0xF0000U)
#define MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_W_SHIFT (16U)
/*! CFG_QOS_OTHER_W - cfg_qos W value of PXP */
#define MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_W(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_W_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_W_MASK)

#define MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_W_MASK (0xF00000U)
#define MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_W_SHIFT (20U)
/*! DEFAULT_QOS_OTHER_W - Default QoS W value of PXP */
#define MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_W(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_W_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_W_MASK)

#define MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_R_MASK (0xF000000U)
#define MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_R_SHIFT (24U)
/*! CFG_QOS_OTHER_R - cfg_qos R value of PXP */
#define MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_R(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_R_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_CFG_QOS_OTHER_R_MASK)

#define MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_R_MASK (0xF0000000U)
#define MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_R_SHIFT (28U)
/*! DEFAULT_QOS_OTHER_R - Default QoS R value of PXP */
#define MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_R(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_R_SHIFT)) & MEDIAMIX_BLK_CTRL_PXP_DEFAULT_QOS_OTHER_R_MASK)
/*! @} */

/*! @name ISI0 - Cache of ISI */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_MASK    (0xFU)
#define MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_SHIFT   (0U)
/*! ARCACHE_Y - ARCACHE_Y value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_MASK)

#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_MASK    (0xF0U)
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_SHIFT   (4U)
/*! AWCACHE_Y - AWCACHE_Y value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_MASK)

#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_MASK    (0xF00U)
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_SHIFT   (8U)
/*! AWCACHE_U - AWCACHE_U value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_MASK)

#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_MASK    (0xF000U)
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_SHIFT   (12U)
/*! AWCACHE_V - AWCACHE_V value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_MASK)

#define MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_EN_MASK (0x10000U)
#define MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_EN_SHIFT (16U)
/*! ARCACHE_Y_EN - ARCACHE_Y enable of ISI
 *  0b0..Do not enable ARCACHE_Y
 *  0b1..Enable ARCACHE_Y
 */
#define MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_EN(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_ARCACHE_Y_EN_MASK)

#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_EN_MASK (0x20000U)
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_EN_SHIFT (17U)
/*! AWCACHE_Y_EN - AWCACHE_Y enable of ISI
 *  0b0..Do not enable AWCACHE_Y
 *  0b1..Enable AWCACHE_Y
 */
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_EN(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_Y_EN_MASK)

#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_EN_MASK (0x40000U)
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_EN_SHIFT (18U)
/*! AWCACHE_U_EN - AWCACHE_U enable of ISI
 *  0b0..Do not enable AWACHE_U
 *  0b1..Enable AWCACHE_U
 */
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_EN(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_U_EN_MASK)

#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_EN_MASK (0x80000U)
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_EN_SHIFT (19U)
/*! AWCACHE_V_EN - AWCACHE_V enable of ISI
 *  0b0..Do not enable AWCACHE_V
 *  0b1..Enable AWCACHE_V
 */
#define MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_EN(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI0_AWCACHE_V_EN_MASK)
/*! @} */

/*! @name ISI1 - QoS of ISI */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_W_MASK  (0xFU)
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_W_SHIFT (0U)
/*! CFG_QOS_Y_W - cfg_qos_y_w value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_W(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_W_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_W_MASK)

#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_W_MASK (0xF0U)
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_W_SHIFT (4U)
/*! DEFAULT_QOS_Y_W - Default QOS_Y_W value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_W(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_W_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_W_MASK)

#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_R_MASK  (0xF00U)
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_R_SHIFT (8U)
/*! CFG_QOS_Y_R - CFG_QOS_Y_R value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_R(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_R_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_Y_R_MASK)

#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_R_MASK (0xF000U)
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_R_SHIFT (12U)
/*! DEFAULT_QOS_Y_R - Default QOS_Y_R value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_R(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_R_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_Y_R_MASK)

#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_U_MASK    (0xF0000U)
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_U_SHIFT   (16U)
/*! CFG_QOS_U - cfg_qos_u value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_U(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_U_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_U_MASK)

#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_U_MASK (0xF00000U)
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_U_SHIFT (20U)
/*! DEFAULT_QOS_U - Default QoS value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_U(x)  (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_U_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_U_MASK)

#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_V_MASK    (0xF000000U)
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_V_SHIFT   (24U)
/*! CFG_QOS_V - CFG_QOS_V value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_V(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_V_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_CFG_QOS_V_MASK)

#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_V_MASK (0xF0000000U)
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_V_SHIFT (28U)
/*! DEFAULT_QOS_V - Default QOS_V value of ISI */
#define MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_V(x)  (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_V_SHIFT)) & MEDIAMIX_BLK_CTRL_ISI1_DEFAULT_QOS_V_MASK)
/*! @} */

/*! @name LDB_CTRL - LDB Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_ENABLE_MASK (0x1U)
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_ENABLE_SHIFT (0U)
/*! CH0_ENABLE - LVDS channel 0 enable
 *  0b0..Channel disabled
 *  0b1..Channel enabled
 */
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_ENABLE_SHIFT)) & MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_ENABLE_MASK)

#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_MASK (0x20U)
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_SHIFT (5U)
/*! CH0_DATA_WIDTH - Data width for LVDS channel 0
 *  0b0..Reserved
 *  0b1..Data width is 24 bits wide.
 */
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_SHIFT)) & MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_MASK)

#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_MASK (0x40U)
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_SHIFT (6U)
/*! CH0_BIT_MAPPING - Data mapping for LVDS channel 0
 *  0b0..Use SPWG standard
 *  0b1..Use JEIDA standard
 */
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_SHIFT)) & MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_MASK)

#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_VSYNC_POLARITY_MASK (0x200U)
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_VSYNC_POLARITY_SHIFT (9U)
/*! CH0_VSYNC_POLARITY - VSYNC polarity select for LVDS channel 0
 *  0b0..VSYNC is active low
 *  0b1..VSYNC is active high
 */
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_VSYNC_POLARITY_SHIFT)) & MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_VSYNC_POLARITY_MASK)

#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_FIFO_RESET_MASK (0x800U)
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_FIFO_RESET_SHIFT (11U)
/*! CH0_FIFO_RESET - LVDS channel 0 async FIFO software reset
 *  0b0..No action
 *  0b1..Software reset
 */
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_FIFO_RESET_SHIFT)) & MEDIAMIX_BLK_CTRL_LDB_CTRL_CH0_FIFO_RESET_MASK)

#define MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_ENABLE_MASK (0x1000000U)
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_ENABLE_SHIFT (24U)
/*! ASYNC_FIFO_ENABLE - LVDS channel 0 async FIFO enable
 *  0b0..Disable
 *  0b1..Enable async FIFO to buffer RGB data
 */
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_ENABLE_SHIFT)) & MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_ENABLE_MASK)

#define MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_THRESHOLD_MASK (0xE000000U)
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_THRESHOLD_SHIFT (25U)
/*! ASYNC_FIFO_THRESHOLD - LVDS channel 0 async FIFO threshold */
#define MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_THRESHOLD_SHIFT)) & MEDIAMIX_BLK_CTRL_LDB_CTRL_ASYNC_FIFO_THRESHOLD_MASK)
/*! @} */

/*! @name LVDS - LVDS Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_LVDS_CH0_EN_MASK       (0x1U)
#define MEDIAMIX_BLK_CTRL_LVDS_CH0_EN_SHIFT      (0U)
/*! CH0_EN - Channel 0 enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MEDIAMIX_BLK_CTRL_LVDS_CH0_EN(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_CH0_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_CH0_EN_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_LVDS_EN_MASK      (0x2U)
#define MEDIAMIX_BLK_CTRL_LVDS_LVDS_EN_SHIFT     (1U)
/*! LVDS_EN - LVDS PHY enable
 *  0b0..Enable. LVDS function is normal.
 *  0b1..Disable
 */
#define MEDIAMIX_BLK_CTRL_LVDS_LVDS_EN(x)        (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_LVDS_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_LVDS_EN_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_BG_EN_MASK        (0x4U)
#define MEDIAMIX_BLK_CTRL_LVDS_BG_EN_SHIFT       (2U)
/*! BG_EN - Bandgap enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MEDIAMIX_BLK_CTRL_LVDS_BG_EN(x)          (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_BG_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_BG_EN_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_HS_EN_MASK        (0x8U)
#define MEDIAMIX_BLK_CTRL_LVDS_HS_EN_SHIFT       (3U)
/*! HS_EN - Enable 100 ohm termination in the chip enable which also doubles power dissipation.
 *  0b0..Disable
 *  0b1..Enable
 */
#define MEDIAMIX_BLK_CTRL_LVDS_HS_EN(x)          (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_HS_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_HS_EN_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_EN_MASK  (0x10U)
#define MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_EN_SHIFT (4U)
/*! PRE_EMPH_EN - Enable pre-emphasis
 *  0b0..Disable
 *  0b1..Enable
 */
#define MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_EN(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_EN_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_ADJ_MASK (0xE0U)
#define MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_ADJ_SHIFT (5U)
/*! PRE_EMPH_ADJ - Pre-emphasis adjustment. */
#define MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_ADJ(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_ADJ_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_PRE_EMPH_ADJ_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_CM_ADJ_MASK       (0x700U)
#define MEDIAMIX_BLK_CTRL_LVDS_CM_ADJ_SHIFT      (8U)
/*! CM_ADJ - Output common mode (Vos) adjustment */
#define MEDIAMIX_BLK_CTRL_LVDS_CM_ADJ(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_CM_ADJ_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_CM_ADJ_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_CC_ADJ_MASK       (0x3800U)
#define MEDIAMIX_BLK_CTRL_LVDS_CC_ADJ_SHIFT      (11U)
/*! CC_ADJ - Output current adjustment */
#define MEDIAMIX_BLK_CTRL_LVDS_CC_ADJ(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_CC_ADJ_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_CC_ADJ_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_SLEW_ADJ_MASK     (0x1C000U)
#define MEDIAMIX_BLK_CTRL_LVDS_SLEW_ADJ_SHIFT    (14U)
/*! SLEW_ADJ - Output transition time adjustment */
#define MEDIAMIX_BLK_CTRL_LVDS_SLEW_ADJ(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_SLEW_ADJ_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_SLEW_ADJ_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_VBG_ADJ_MASK      (0xE0000U)
#define MEDIAMIX_BLK_CTRL_LVDS_VBG_ADJ_SHIFT     (17U)
/*! VBG_ADJ - Bandgap adjustment */
#define MEDIAMIX_BLK_CTRL_LVDS_VBG_ADJ(x)        (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_VBG_ADJ_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_VBG_ADJ_MASK)

#define MEDIAMIX_BLK_CTRL_LVDS_SPARE_IN_MASK     (0xE000000U)
#define MEDIAMIX_BLK_CTRL_LVDS_SPARE_IN_SHIFT    (25U)
/*! SPARE_IN - Spare ports */
#define MEDIAMIX_BLK_CTRL_LVDS_SPARE_IN(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LVDS_SPARE_IN_SHIFT)) & MEDIAMIX_BLK_CTRL_LVDS_SPARE_IN_MASK)
/*! @} */

/*! @name LIMITER0 - Limiter Enable Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_LIMITER0_EN_SF_MASK    (0x1U)
#define MEDIAMIX_BLK_CTRL_LIMITER0_EN_SF_SHIFT   (0U)
/*! EN_SF - Limiter enable of NIC_MEDIA
 *  0b0..Do not enable limiter
 *  0b1..Enable limiter
 */
#define MEDIAMIX_BLK_CTRL_LIMITER0_EN_SF(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LIMITER0_EN_SF_SHIFT)) & MEDIAMIX_BLK_CTRL_LIMITER0_EN_SF_MASK)

#define MEDIAMIX_BLK_CTRL_LIMITER0_EN_PXP_MASK   (0x2U)
#define MEDIAMIX_BLK_CTRL_LIMITER0_EN_PXP_SHIFT  (1U)
/*! EN_PXP - Limiter enable of PXP
 *  0b0..Do not enable limiter
 *  0b1..Enable limiter
 */
#define MEDIAMIX_BLK_CTRL_LIMITER0_EN_PXP(x)     (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LIMITER0_EN_PXP_SHIFT)) & MEDIAMIX_BLK_CTRL_LIMITER0_EN_PXP_MASK)
/*! @} */

/*! @name LIMITER1 - Limiter Threshold Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_PXP_MASK (0xFFFFU)
#define MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_PXP_SHIFT (0U)
/*! THRESH_PXP - PXP read threshold of outstanding beats from NIC_MEDIA. */
#define MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_PXP(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_PXP_SHIFT)) & MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_PXP_MASK)

#define MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_SF_MASK (0xFFFF0000U)
#define MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_SF_SHIFT (16U)
/*! THRESH_SF - NIC_MEDIA read threshold of outstanding beats from NIC_CENTRAL */
#define MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_SF(x)  (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_SF_SHIFT)) & MEDIAMIX_BLK_CTRL_LIMITER1_THRESH_SF_MASK)
/*! @} */

/*! @name RESET - RESET Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_RESET_bus_apb_en_MASK  (0x1U)
#define MEDIAMIX_BLK_CTRL_RESET_bus_apb_en_SHIFT (0U)
/*! bus_apb_en - Bus apb_clk reset
 *  0b0..Reset bus apb_clk related logic
 *  0b1..Do not reset bus apb_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_bus_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_bus_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_bus_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_bus_blk_en_MASK  (0x2U)
#define MEDIAMIX_BLK_CTRL_RESET_bus_blk_en_SHIFT (1U)
/*! bus_blk_en - Bus axi_clk reset
 *  0b0..Reset bus axi_clk related logic
 *  0b1..Do not reset bus axi_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_bus_blk_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_bus_blk_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_bus_blk_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_isi_apb_en_MASK  (0x4U)
#define MEDIAMIX_BLK_CTRL_RESET_isi_apb_en_SHIFT (2U)
/*! isi_apb_en - ISI apb_clk reset
 *  0b0..Reset ISI apb_clk related logic
 *  0b1..Do not reset ISI apb_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_isi_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_isi_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_isi_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_isi_proc_en_MASK (0x8U)
#define MEDIAMIX_BLK_CTRL_RESET_isi_proc_en_SHIFT (3U)
/*! isi_proc_en - ISI axi_clk reset
 *  0b0..Reset ISI axi_clk related logic
 *  0b1..Do not reset ISI axi_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_isi_proc_en(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_isi_proc_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_isi_proc_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_lcdif_apb_en_MASK (0x10U)
#define MEDIAMIX_BLK_CTRL_RESET_lcdif_apb_en_SHIFT (4U)
/*! lcdif_apb_en - LCDIF apb_clk reset
 *  0b0..Reset LCDIF apb_clk related logic
 *  0b1..Do not reset LCDIF apb_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_lcdif_apb_en(x)  (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_lcdif_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_lcdif_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_lcdif_axi_en_MASK (0x20U)
#define MEDIAMIX_BLK_CTRL_RESET_lcdif_axi_en_SHIFT (5U)
/*! lcdif_axi_en - LCDIF axi_clk reset
 *  0b0..Reset LCDIF axi_clk related logic
 *  0b1..Do not reset LCDIF axi_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_lcdif_axi_en(x)  (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_lcdif_axi_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_lcdif_axi_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_lcdif_pix_en_MASK (0x40U)
#define MEDIAMIX_BLK_CTRL_RESET_lcdif_pix_en_SHIFT (6U)
/*! lcdif_pix_en - LCDIF pix_clk reset
 *  0b0..Reset LCDIF pix_clk related logic
 *  0b1..Do not reset LCDIF pix_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_lcdif_pix_en(x)  (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_lcdif_pix_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_lcdif_pix_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_pxp_apb_en_MASK  (0x80U)
#define MEDIAMIX_BLK_CTRL_RESET_pxp_apb_en_SHIFT (7U)
/*! pxp_apb_en - PXP apb_clk reset
 *  0b0..Reset PXP apb_clk related logic
 *  0b1..Do not reset PXP apb_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_pxp_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_pxp_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_pxp_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_pxp_axi_en_MASK  (0x100U)
#define MEDIAMIX_BLK_CTRL_RESET_pxp_axi_en_SHIFT (8U)
/*! pxp_axi_en - PXP axi_clk reset
 *  0b0..Reset PXP axi_clk related logic
 *  0b1..Do not reset PXP axi_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_pxp_axi_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_pxp_axi_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_pxp_axi_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_csi_apb_en_MASK  (0x200U)
#define MEDIAMIX_BLK_CTRL_RESET_csi_apb_en_SHIFT (9U)
/*! csi_apb_en - CSI apb_clk reset
 *  0b0..Reset CSI apb_clk related logic
 *  0b1..Do not reest CSI apb_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_csi_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_csi_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_csi_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_cam_clk_en_MASK  (0x400U)
#define MEDIAMIX_BLK_CTRL_RESET_cam_clk_en_SHIFT (10U)
/*! cam_clk_en - Camera clock reset
 *  0b0..Reset camera related logic
 *  0b1..Do not reset camera clock related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_cam_clk_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_cam_clk_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_cam_clk_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_dsi_apb_en_MASK  (0x800U)
#define MEDIAMIX_BLK_CTRL_RESET_dsi_apb_en_SHIFT (11U)
/*! dsi_apb_en - DSI apb_clk reset
 *  0b0..Reset DSI apb_clk related logic
 *  0b1..Do not reset DSI apb_clk related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_dsi_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_dsi_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_dsi_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_RESET_ref_clk_en_MASK  (0x1000U)
#define MEDIAMIX_BLK_CTRL_RESET_ref_clk_en_SHIFT (12U)
/*! ref_clk_en - DSI ref_clk reset
 *  0b0..Reset DSI reference clock related logic
 *  0b1..Do not reset DSI reference clock related logic
 */
#define MEDIAMIX_BLK_CTRL_RESET_ref_clk_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_RESET_ref_clk_en_SHIFT)) & MEDIAMIX_BLK_CTRL_RESET_ref_clk_en_MASK)
/*! @} */

/*! @name CLK - CLK Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_CLK_bus_apb_en_MASK    (0x1U)
#define MEDIAMIX_BLK_CTRL_CLK_bus_apb_en_SHIFT   (0U)
/*! bus_apb_en - Bus apb_clk gate enable
 *  0b0..Do not gate bus apb_clk root
 *  0b1..Gate bus apb_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_bus_apb_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_bus_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_bus_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_bus_blk_en_MASK    (0x2U)
#define MEDIAMIX_BLK_CTRL_CLK_bus_blk_en_SHIFT   (1U)
/*! bus_blk_en - Bus axi_clk gate enable
 *  0b0..Do not gate bus axi_clk root
 *  0b1..Gate bus axi_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_bus_blk_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_bus_blk_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_bus_blk_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_isi_apb_en_MASK    (0x4U)
#define MEDIAMIX_BLK_CTRL_CLK_isi_apb_en_SHIFT   (2U)
/*! isi_apb_en - ISI apb_clk gate enable
 *  0b0..Do not gate ISI apb_clk root
 *  0b1..Gate ISI apb_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_isi_apb_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_isi_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_isi_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_isi_proc_en_MASK   (0x8U)
#define MEDIAMIX_BLK_CTRL_CLK_isi_proc_en_SHIFT  (3U)
/*! isi_proc_en - ISI axi_clk gate enable
 *  0b0..Do not gate ISI axi_clk root
 *  0b1..Gate ISI axi_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_isi_proc_en(x)     (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_isi_proc_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_isi_proc_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_lcdif_apb_en_MASK  (0x10U)
#define MEDIAMIX_BLK_CTRL_CLK_lcdif_apb_en_SHIFT (4U)
/*! lcdif_apb_en - LCDIF apb_clk gate enable
 *  0b0..Do not gate LCDIF apb_clk root
 *  0b1..Gate LCDIF apb_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_lcdif_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_lcdif_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_lcdif_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_lcdif_axi_en_MASK  (0x20U)
#define MEDIAMIX_BLK_CTRL_CLK_lcdif_axi_en_SHIFT (5U)
/*! lcdif_axi_en - LCDIF axi_clk gate enable
 *  0b0..Do not gate LCDIF axi_clk root
 *  0b1..Gate LCDIF axi_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_lcdif_axi_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_lcdif_axi_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_lcdif_axi_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_lcdif_pix_en_MASK  (0x40U)
#define MEDIAMIX_BLK_CTRL_CLK_lcdif_pix_en_SHIFT (6U)
/*! lcdif_pix_en - LCDIF pix_clk gate enable
 *  0b0..Do not gate LCDIF pix_clk root
 *  0b1..Gate LCDIF pix_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_lcdif_pix_en(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_lcdif_pix_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_lcdif_pix_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_pxp_apb_en_MASK    (0x80U)
#define MEDIAMIX_BLK_CTRL_CLK_pxp_apb_en_SHIFT   (7U)
/*! pxp_apb_en - PXP apb_clk gate enable
 *  0b0..Do not gate PXP apb_clk root
 *  0b1..Gate PXP apb_clk gate root
 */
#define MEDIAMIX_BLK_CTRL_CLK_pxp_apb_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_pxp_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_pxp_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_pxp_axi_en_MASK    (0x100U)
#define MEDIAMIX_BLK_CTRL_CLK_pxp_axi_en_SHIFT   (8U)
/*! pxp_axi_en - PXP axi_clk gate enable
 *  0b0..Do not gate PXP axi_clk root
 *  0b1..Gate PXP axi_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_pxp_axi_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_pxp_axi_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_pxp_axi_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_csi_apb_en_MASK    (0x200U)
#define MEDIAMIX_BLK_CTRL_CLK_csi_apb_en_SHIFT   (9U)
/*! csi_apb_en - CSI apb_clk gate enable
 *  0b0..Do not gate CSI apb_clk root
 *  0b1..Gate CSI apb_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_csi_apb_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_csi_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_csi_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_cam_clk_en_MASK    (0x400U)
#define MEDIAMIX_BLK_CTRL_CLK_cam_clk_en_SHIFT   (10U)
/*! cam_clk_en - cam_clk gate enable
 *  0b0..Do not gate cam_clk root
 *  0b1..Gate cam_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_cam_clk_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_cam_clk_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_cam_clk_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_dsi_apb_en_MASK    (0x800U)
#define MEDIAMIX_BLK_CTRL_CLK_dsi_apb_en_SHIFT   (11U)
/*! dsi_apb_en - DSI apb_clk gate enable
 *  0b0..Do not gate DSI apb_clk root
 *  0b1..Gate DSI apb_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_dsi_apb_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_dsi_apb_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_dsi_apb_en_MASK)

#define MEDIAMIX_BLK_CTRL_CLK_ref_clk_en_MASK    (0x1000U)
#define MEDIAMIX_BLK_CTRL_CLK_ref_clk_en_SHIFT   (12U)
/*! ref_clk_en - DSI ref_clk gate enable
 *  0b0..Do not gate DSI ref_clk root
 *  0b1..Gate DSI ref_clk root
 */
#define MEDIAMIX_BLK_CTRL_CLK_ref_clk_en(x)      (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CLK_ref_clk_en_SHIFT)) & MEDIAMIX_BLK_CTRL_CLK_ref_clk_en_MASK)
/*! @} */

/*! @name CAMERA_MUX - Camera Mux Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_DATA_TYPE_MASK (0x1F8U)
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_DATA_TYPE_SHIFT (3U)
/*! DATA_TYPE - Data type
 *  0b011000..YUV420 8-bit
 *  0b011001..YUV420 10-bit
 *  0b011010..Legacy YUV420 (8-bit)
 *  0b011100..YUV420 8-bit (Chroma Shifted Pixel Sampling)
 *  0b011101..YUV420 10-bit (Chroma Shifted Pixel Sampling)
 *  0b011110..YUV422 8-bit
 *  0b011111..YUV422 10-bit
 *  0b100010..RGB565
 *  0b100011..RGB666
 *  0b100100..RGB888
 *  0b101000..RAW6
 *  0b101001..RAW7
 *  0b101010..RAW8
 *  0b101011..RAW10
 *  0b101100..RAW12
 *  0b101101..RAW14
 *  0b110000..User define32. Align with MIPI CSI ipi_mode[8] configure to 1'b0.
 *  0b110001..User define16. Align with MIPI CSI ipi_mode[8] configure to 1'b1.
 */
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CAMERA_MUX_DATA_TYPE_SHIFT)) & MEDIAMIX_BLK_CTRL_CAMERA_MUX_DATA_TYPE_MASK)

#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_INTERLACE_MASK (0x600U)
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_INTERLACE_SHIFT (9U)
/*! INTERLACE - Interface mode
 *  0b00..Not interlaced
 *  0b01..Interfacled left (odd frame)
 *  0b10..Interlaced right (even frame)
 *  0b11..Reserved
 */
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_INTERLACE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CAMERA_MUX_INTERLACE_SHIFT)) & MEDIAMIX_BLK_CTRL_CAMERA_MUX_INTERLACE_MASK)

#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_VC_IDENTIFY_MASK (0x1800U)
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_VC_IDENTIFY_SHIFT (11U)
/*! VC_IDENTIFY - Virtual channel identifier */
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_VC_IDENTIFY(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CAMERA_MUX_VC_IDENTIFY_SHIFT)) & MEDIAMIX_BLK_CTRL_CAMERA_MUX_VC_IDENTIFY_MASK)

#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_EMBED_SWAP_MASK (0x2000U)
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_EMBED_SWAP_SHIFT (13U)
/*! EMBED_SWAP - Swap for embedded data
 *  0b0..Swap for 16-bit embedded data
 *  0b1..No Swap for 16-bit embedded data
 */
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_EMBED_SWAP(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CAMERA_MUX_EMBED_SWAP_SHIFT)) & MEDIAMIX_BLK_CTRL_CAMERA_MUX_EMBED_SWAP_MASK)

#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_LEFT_JUST_MODE_MASK (0x4000U)
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_LEFT_JUST_MODE_SHIFT (14U)
/*! LEFT_JUST_MODE - Left justified mode
 *  0b0..For RGB565/RGB666/RGB888: Unused LSB equal most significant bit of valid data. For RAW: LSB aligned selection.
 *  0b1..For RGB565/RGB666/RGB888: Unused LSB equal least significant bit of valid data. For RAW: MSB aligned selection.
 */
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_LEFT_JUST_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CAMERA_MUX_LEFT_JUST_MODE_SHIFT)) & MEDIAMIX_BLK_CTRL_CAMERA_MUX_LEFT_JUST_MODE_MASK)

#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_ENABLE_MASK (0x10000U)
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_ENABLE_SHIFT (16U)
/*! ENABLE - Gasket enable
 *  0b0..Disable gasket
 *  0b1..Enable gasket
 */
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CAMERA_MUX_ENABLE_SHIFT)) & MEDIAMIX_BLK_CTRL_CAMERA_MUX_ENABLE_MASK)

#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_SOURCE_TYPE_MASK (0x20000U)
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_SOURCE_TYPE_SHIFT (17U)
/*! SOURCE_TYPE - Source type
 *  0b0..Data from MIPI CSI
 *  0b1..Data from parallel camera
 */
#define MEDIAMIX_BLK_CTRL_CAMERA_MUX_SOURCE_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CAMERA_MUX_SOURCE_TYPE_SHIFT)) & MEDIAMIX_BLK_CTRL_CAMERA_MUX_SOURCE_TYPE_MASK)
/*! @} */

/*! @name PIXEL_CTRL - Read Pixel Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_PIXEL_CTRL_PIXEL_CTRL_MASK (0xFFFU)
#define MEDIAMIX_BLK_CTRL_PIXEL_CTRL_PIXEL_CTRL_SHIFT (0U)
/*! PIXEL_CTRL - Read pixel control information status */
#define MEDIAMIX_BLK_CTRL_PIXEL_CTRL_PIXEL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PIXEL_CTRL_PIXEL_CTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_PIXEL_CTRL_PIXEL_CTRL_MASK)
/*! @} */

/*! @name LINE_CNT - Read Line Count Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_LINE_CNT_LINE_CNT_MASK (0xFFFFFFFFU)
#define MEDIAMIX_BLK_CTRL_LINE_CNT_LINE_CNT_SHIFT (0U)
/*! LINE_CNT - Read line count status from MIPI to ISI wrapper. The actual line number is counter +1. */
#define MEDIAMIX_BLK_CTRL_LINE_CNT_LINE_CNT(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_LINE_CNT_LINE_CNT_SHIFT)) & MEDIAMIX_BLK_CTRL_LINE_CNT_LINE_CNT_MASK)
/*! @} */

/*! @name PIXEL_CNT - Read Pixel Count Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_PIXEL_CNT_PIXEL_CNT_MASK (0xFFFFFFFFU)
#define MEDIAMIX_BLK_CTRL_PIXEL_CNT_PIXEL_CNT_SHIFT (0U)
/*! PIXEL_CNT - Read pixel count status from MIPI to ISI wrapper */
#define MEDIAMIX_BLK_CTRL_PIXEL_CNT_PIXEL_CNT(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_PIXEL_CNT_PIXEL_CNT_SHIFT)) & MEDIAMIX_BLK_CTRL_PIXEL_CNT_PIXEL_CNT_MASK)
/*! @} */

/*! @name DISPLAY_MUX - Display Mux Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_LCDIF_CROSS_LINE_PATTERN_MASK (0xFU)
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_LCDIF_CROSS_LINE_PATTERN_SHIFT (0U)
/*! LCDIF_CROSS_LINE_PATTERN - LCDIF pixel component bit map configuration, aligned with the cross line pattern configuration on LCDIF.
 *  0b0000..RGB888 to RGB888
 *  0b0001..RBG888 to RGB888
 *  0b0010..GBR888 to RGB888
 *  0b0011..GRB888 to RGB888
 *  0b0100..BRG888 to RGB888
 *  0b0101..BGR888 to RGB888
 *  0b0110..RGB888 to RGB666
 *  0b0111..RGB565 to RGB565
 *  0b1000..YUYV to YUYV from LCDIF[16:0]
 *  0b1001..UYVY to YUYV from LCDIF[16:0]
 *  0b1100..YUYV to YUYV from LCDIF[23:8]
 *  0b1101..UYVY to YUYV from LCDIF[23:8]
 */
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_LCDIF_CROSS_LINE_PATTERN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DISPLAY_MUX_LCDIF_CROSS_LINE_PATTERN_SHIFT)) & MEDIAMIX_BLK_CTRL_DISPLAY_MUX_LCDIF_CROSS_LINE_PATTERN_MASK)

#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB565_MAP_CFG_MASK (0x30U)
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB565_MAP_CFG_SHIFT (4U)
/*! MIPI_DSI_RGB565_MAP_CFG - MIPI DSI RGB565 bit map configuration, aligned with MIPI DSI pixel component bit map configuration
 *  0b00..Config 1
 *  0b01..Config 2
 *  0b10..Config 3
 */
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB565_MAP_CFG(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB565_MAP_CFG_SHIFT)) & MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB565_MAP_CFG_MASK)

#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB666_MAP_CFG_MASK (0xC0U)
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB666_MAP_CFG_SHIFT (6U)
/*! MIPI_DSI_RGB666_MAP_CFG - MIPI DSI RGB666 bit map configuration, aligned with MIPI DSI pixel component bit map configuration.
 *  0b00..Config 1
 *  0b01..Config 2
 */
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB666_MAP_CFG(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB666_MAP_CFG_SHIFT)) & MEDIAMIX_BLK_CTRL_DISPLAY_MUX_MIPI_DSI_RGB666_MAP_CFG_MASK)

#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_PARALLEL_DISP_FORMAT_MASK (0x700U)
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_PARALLEL_DISP_FORMAT_SHIFT (8U)
/*! PARALLEL_DISP_FORMAT - Parallel display format configuration
 *  0b000..RGB888 -> RGB888
 *  0b001..RGB888 -> RGB666. Truncate the two least significant bits of each color component (pass through the 6
 *         most significant bits of each color component.)
 *  0b010..RGB565 -> RGB565
 *  0b011..RGB555 -> RGB555
 *  0b100..YUV -> YCbCr 24 bits
 *  0b101..YUV -> YUV444
 */
#define MEDIAMIX_BLK_CTRL_DISPLAY_MUX_PARALLEL_DISP_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DISPLAY_MUX_PARALLEL_DISP_FORMAT_SHIFT)) & MEDIAMIX_BLK_CTRL_DISPLAY_MUX_PARALLEL_DISP_FORMAT_MASK)
/*! @} */

/*! @name IF_CTRL_REG - Parallel Camera Interface Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_SEL_MASK (0x100U)
#define MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_SEL_SHIFT (8U)
/*! DATA_TYPE_SEL - Pixel link data type select
 *  0b0..Pixel Link data type comes from the CSI interface
 *  0b1..Pixel Link data type comes from IF_CTRL_REG DATA_TYPE[4:0]
 */
#define MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_SEL_SHIFT)) & MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_SEL_MASK)

#define MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_MASK (0x3E00U)
#define MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_SHIFT (9U)
/*! DATA_TYPE - Date type to ISI control bus [11:7]
 *  0b00000..Null data
 *  0b00100..RGB format
 *  0b01000..YUV444 format
 *  0b10000..Reserved
 *  0b10010..Reserved
 *  0b11000..Reserved
 *  0b11010..Reserved
 *  0b11100..RAW
 */
#define MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_SHIFT)) & MEDIAMIX_BLK_CTRL_IF_CTRL_REG_DATA_TYPE_MASK)
/*! @} */

/*! @name INTERFACE_STATUS - Interface Status Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_MASK (0x1U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_SHIFT (0U)
/*! FIELD_TOGGLE_STATUS - Field toggle status
 *  0b0..VSYNC field toggle mode disabled
 *  0b1..VSYNC field toggle mode enabled
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_FIELD_TOGGLE_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_ECC_ERROR_STATUS_MASK (0x2U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_ECC_ERROR_STATUS_SHIFT (1U)
/*! ECC_ERROR_STATUS - ECC error status
 *  0b0..No ECC error detected
 *  0b1..ECC error detected
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_ECC_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_ECC_ERROR_STATUS_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_STATUS_ECC_ERROR_STATUS_MASK)
/*! @} */

/*! @name INTERFACE_CTRL_REG - Interface Control Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CSI_EN_MASK (0x1U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CSI_EN_SHIFT (0U)
/*! CSI_EN - CSI interface enable
 *  0b0..Disable CSI interface
 *  0b1..Enable CSI interface
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CSI_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CSI_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CSI_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_CLK_POL_MASK (0x2U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_CLK_POL_SHIFT (1U)
/*! PIXEL_CLK_POL - Pixel clock polarity control
 *  0b0..Pixel clcok is not inverted.
 *  0b1..Pixel clock input is inverted.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_CLK_POL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_CLK_POL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_CLK_POL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_POL_MASK (0x4U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_POL_SHIFT (2U)
/*! HSYNC_POL - HSYNC polarity control
 *  0b0..HSYNC output to Pixel Link is not inverted.
 *  0b1..HSYNC output to Pixel Link is inverted.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_POL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_POL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_POL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_POL_MASK (0x8U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_POL_SHIFT (3U)
/*! VSYNC_POL - VSYNC polarity control
 *  0b0..VSYNC output to Pixel Link is not inverted.
 *  0b1..VSYNC output to Pixel Link is inverted.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_POL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_POL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_POL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DE_POL_MASK (0x10U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DE_POL_SHIFT (4U)
/*! DE_POL - DE polarity control
 *  0b0..DE output to Pixel Link is not inverted.
 *  0b1..DE output to Pixcel Link is inverted.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DE_POL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DE_POL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DE_POL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_DATA_POL_MASK (0x20U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_DATA_POL_SHIFT (5U)
/*! PIXEL_DATA_POL - PIXEL_DATA polarity control
 *  0b0..PIXEL_DATA output to Pixel Link is not inverted.
 *  0b1..PIXEL_DATA output to Pixel Link is inverted.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_DATA_POL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_DATA_POL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_PIXEL_DATA_POL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_MASK (0x40U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_SHIFT (6U)
/*! CCIR_EXT_VSYNC_EN - External VSYNC enable */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EN_MASK (0x80U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EN_SHIFT (7U)
/*! CCIR_EN - CCIR mode enable
 *  0b0..CCIR mode disable
 *  0b1..CCIR mode enable
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_MASK (0x100U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_SHIFT (8U)
/*! CCIR_VIDEO_MODE - CCIR video mode
 *  0b0..Progressive mode
 *  0b1..Interlace
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_NTSC_EN_MASK (0x200U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_NTSC_EN_SHIFT (9U)
/*! CCIR_NTSC_EN - CCIR NTSC enable
 *  0b0..PAL
 *  0b1..NTSC
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_NTSC_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_NTSC_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_NTSC_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_MASK (0x400U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_SHIFT (10U)
/*! CCIR_VSYNC_RST_EN - CCIR_VSYNC_RESET_EN */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_MASK (0x800U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_SHIFT (11U)
/*! CCIR_ECC_CORR_EN - CCIR error correction enable
 *  0b0..ECC error correction is disabled.
 *  0b1..ECC error correction is enabled.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_MASK (0x1000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_SHIFT (12U)
/*! HSYNC_FORCE_EN - HSYNC force enable
 *  0b0..Do not override HSYNC.
 *  0b1..Override HSYNC.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_MASK (0x2000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_SHIFT (13U)
/*! VSYNC_FORCE_EN - VSYNC force enable
 *  0b0..Do not override VSYNC.
 *  0b1..Override VSYNC.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_GCLK_MODE_EN_MASK (0x4000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_GCLK_MODE_EN_SHIFT (14U)
/*! GCLK_MODE_EN - Gate clock mode enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_GCLK_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_GCLK_MODE_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_GCLK_MODE_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VALID_SEL_MASK (0x8000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VALID_SEL_SHIFT (15U)
/*! VALID_SEL - Data valid select
 *  0b0..HSYNC data valid.
 *  0b1..Data enable valid. Not supported.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VALID_SEL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_VALID_SEL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_RAW_OUT_SEL_MASK (0x10000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_RAW_OUT_SEL_SHIFT (16U)
/*! RAW_OUT_SEL - RAW output select
 *  0b0..Right justified output
 *  0b1..Left justified to 14-bit output
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_RAW_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_RAW_OUT_SEL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_RAW_OUT_SEL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_MASK (0x20000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_SHIFT (17U)
/*! HSYNC_OUT_SEL - HSYNC output select
 *  0b0..HYSNC output level
 *  0b1..HYSNC output pulse
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_PULSE_MASK (0x380000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_PULSE_SHIFT (19U)
/*! HSYNC_PULSE - HSYNC_PULSE */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_PULSE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_PULSE_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_HSYNC_PULSE_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_UV_SWAP_EN_MASK (0x400000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_UV_SWAP_EN_SHIFT (22U)
/*! UV_SWAP_EN - UV swap enable
 *  0b0..UV swap disable
 *  0b1..UV swap enable
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_UV_SWAP_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_UV_SWAP_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_UV_SWAP_EN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DATA_TYPE_IN_MASK (0x7800000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DATA_TYPE_IN_SHIFT (23U)
/*! DATA_TYPE_IN - CSI input data type
 *  0b0000..UYVY bt656 8-bit
 *  0b0001..UYVY bt656 10-bit
 *  0b0010..RGB 8-bit
 *  0b0011..BGR 8-bit
 *  0b0100..Reserved
 *  0b0101..YUV422 YVYU 8-bit
 *  0b0110..YUV444 YUV 8-bit
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Bayer 8-bit
 *  0b1010..Bayer 10-bit
 *  0b1011..Reserved
 *  0b1100..Reserved
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DATA_TYPE_IN(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DATA_TYPE_IN_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_DATA_TYPE_IN_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_MASK_VSYNC_CNTR_MASK (0x18000000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_MASK_VSYNC_CNTR_SHIFT (27U)
/*! MASK_VSYNC_CNTR - CSI mask VSYNC counter
 *  0b00..No mask
 *  0b01..Mask 1 frame
 *  0b10..Mask 2 frames
 *  0b11..Mask 3 frames
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_MASK_VSYNC_CNTR(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_MASK_VSYNC_CNTR_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_MASK_VSYNC_CNTR_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_SOFTRST_MASK (0x80000000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_SOFTRST_SHIFT (31U)
/*! SOFTRST - CSI interface software reset
 *  0b0..Assert software reset of CSI interface.
 *  0b1..Do not perform software reset of CSI interface.
 */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_SOFTRST(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_SOFTRST_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG_SOFTRST_MASK)
/*! @} */

/*! @name INTERFACE_CTRL_REG1 - Interface Control Register 1 */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_VSYNC_PULSE_MASK (0xFFFFU)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_VSYNC_PULSE_SHIFT (0U)
/*! VSYNC_PULSE - VSYNC pulse width */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_VSYNC_PULSE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_VSYNC_PULSE_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_VSYNC_PULSE_MASK)

#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_PIXEL_WIDTH_MASK (0xFFFF0000U)
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_PIXEL_WIDTH_SHIFT (16U)
/*! PIXEL_WIDTH - CSI interface pixel width */
#define MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_PIXEL_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_PIXEL_WIDTH_SHIFT)) & MEDIAMIX_BLK_CTRL_INTERFACE_CTRL_REG1_PIXEL_WIDTH_MASK)
/*! @} */

/*! @name CSI - CSI Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_CSI_CFGCLKFREQRANGE_MASK (0x3FU)
#define MEDIAMIX_BLK_CTRL_CSI_CFGCLKFREQRANGE_SHIFT (0U)
/*! CFGCLKFREQRANGE - System clock frequency configuration */
#define MEDIAMIX_BLK_CTRL_CSI_CFGCLKFREQRANGE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_CFGCLKFREQRANGE_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_CFGCLKFREQRANGE_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_HSFREQRANGE_MASK   (0x7F00U)
#define MEDIAMIX_BLK_CTRL_CSI_HSFREQRANGE_SHIFT  (8U)
/*! HSFREQRANGE - High-speed frequency range */
#define MEDIAMIX_BLK_CTRL_CSI_HSFREQRANGE(x)     (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_HSFREQRANGE_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_HSFREQRANGE_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_CONT_EN_MASK       (0x10000U)
#define MEDIAMIX_BLK_CTRL_CSI_CONT_EN_SHIFT      (16U)
/*! CONT_EN - Continuity test mode enable
 *  0b0..Disble I/O continuity test mode.
 *  0b1..Enable I/O continuity test mode.
 */
#define MEDIAMIX_BLK_CTRL_CSI_CONT_EN(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_CONT_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_CONT_EN_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_DIRECTION_0_MASK   (0x20000U)
#define MEDIAMIX_BLK_CTRL_CSI_DIRECTION_0_SHIFT  (17U)
/*! DIRECTION_0 - Transmit/receive direction
 *  0b0..The lane interconnect is in transmit mode.
 *  0b1..The lane interconnect is in receive mode.
 */
#define MEDIAMIX_BLK_CTRL_CSI_DIRECTION_0(x)     (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_DIRECTION_0_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_DIRECTION_0_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP0_0_MASK (0x40000U)
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP0_0_SHIFT (18U)
/*! ERRCONTENTIONLP0_0 - LP0 contention error
 *  0b0..No error detected.
 *  0b1..A lane module functioning as Tx, while its base direction is Rx detects a contention situation on a line while trying to drive the line low.
 */
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP0_0(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP0_0_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP0_0_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP1_0_MASK (0x80000U)
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP1_0_SHIFT (19U)
/*! ERRCONTENTIONLP1_0 - LP1 contention error
 *  0b0..No error detected.
 *  0b1..A lane module functioning as Tx, while its base direction is Rx detects a contention situation on a line while trying to drive the line low.
 */
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP1_0(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP1_0_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_ERRCONTENTIONLP1_0_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_0_MASK  (0x100000U)
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_0_SHIFT (20U)
/*! ERRCONTROL_0 - Control error lane 0
 *  0b0..No error detected.
 *  0b1..An incorrect line state sequence is detected. For example, if a turnaround request or Escape mode request
 *       is immediately followed by a Stop state instead of the required Bridge state, this signal is asserted and
 *       remains high until the line returns to Stop state.
 */
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_0(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_0_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_0_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_1_MASK  (0x200000U)
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_1_SHIFT (21U)
/*! ERRCONTROL_1 - Control error lane 1
 *  0b0..No error detected.
 *  0b1..An incorrect line state sequence is detected. For example, if a turnaround request or Escape mode request
 *       is immediately followed by a Stop state instead of the required Bridge state, this signal is asserted and
 *       remains high until the line returns to Stop state.
 */
#define MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_1(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_1_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_ERRCONTROL_1_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_0_MASK  (0x400000U)
#define MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_0_SHIFT (22U)
/*! ERRSYNCESC_0 - Low power data transmission synchronization error lane 0
 *  0b0..No error detected.
 *  0b1..The number of bits received during low-power transmission is not a mulitple of 8 when the transmission
 *       ends. This bit remains high until the line returns to Stop state.
 */
#define MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_0(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_0_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_0_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_1_MASK  (0x800000U)
#define MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_1_SHIFT (23U)
/*! ERRSYNCESC_1 - Low power data transmission synchronization error lane 1
 *  0b0..No error detected.
 *  0b1..The number of bits received during low-power transmission is not a mulitple of 8 when the transmission
 *       ends. This bit remains high until the line returns to Stop state.
 */
#define MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_1(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_1_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_ERRSYNCESC_1_MASK)

#define MEDIAMIX_BLK_CTRL_CSI_CONT_DATA_MASK     (0x7F000000U)
#define MEDIAMIX_BLK_CTRL_CSI_CONT_DATA_SHIFT    (24U)
/*! CONT_DATA - Continuity data */
#define MEDIAMIX_BLK_CTRL_CSI_CONT_DATA(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_CSI_CONT_DATA_SHIFT)) & MEDIAMIX_BLK_CTRL_CSI_CONT_DATA_MASK)
/*! @} */

/*! @name DSI - DSI Register */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_DSI_CFGCLKFREQRANGE_MASK (0x3FU)
#define MEDIAMIX_BLK_CTRL_DSI_CFGCLKFREQRANGE_SHIFT (0U)
/*! CFGCLKFREQRANGE - System clock frequency */
#define MEDIAMIX_BLK_CTRL_DSI_CFGCLKFREQRANGE(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_CFGCLKFREQRANGE_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_CFGCLKFREQRANGE_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_CLKSEL_MASK        (0xC0U)
#define MEDIAMIX_BLK_CTRL_DSI_CLKSEL_SHIFT       (6U)
/*! CLKSEL - Control of PLL clock output selection
 *  0b00..Clocks stopped
 *  0b01..Clock generation
 *  0b10..buffered clkext
 *  0b11..Forbidden
 */
#define MEDIAMIX_BLK_CTRL_DSI_CLKSEL(x)          (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_CLKSEL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_CLKSEL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_HSFREQRANGE_MASK   (0x7F00U)
#define MEDIAMIX_BLK_CTRL_DSI_HSFREQRANGE_SHIFT  (8U)
/*! HSFREQRANGE - High-speed frequency range selection */
#define MEDIAMIX_BLK_CTRL_DSI_HSFREQRANGE(x)     (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_HSFREQRANGE_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_HSFREQRANGE_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_CONT_EN_MASK       (0x10000U)
#define MEDIAMIX_BLK_CTRL_DSI_CONT_EN_SHIFT      (16U)
/*! CONT_EN - Continuity test mode enable
 *  0b0..Disable I/O continuity test mode.
 *  0b1..Enable I/O continuity test mode.
 */
#define MEDIAMIX_BLK_CTRL_DSI_CONT_EN(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_CONT_EN_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_CONT_EN_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_updatepll_MASK     (0x20000U)
#define MEDIAMIX_BLK_CTRL_DSI_updatepll_SHIFT    (17U)
/*! updatepll - Control for PLL operation frequency udpated */
#define MEDIAMIX_BLK_CTRL_DSI_updatepll(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_updatepll_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_updatepll_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_shadow_clear_MASK  (0x40000U)
#define MEDIAMIX_BLK_CTRL_DSI_shadow_clear_SHIFT (18U)
/*! shadow_clear - Shadow registers clear */
#define MEDIAMIX_BLK_CTRL_DSI_shadow_clear(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_shadow_clear_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_shadow_clear_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_gp_clk_en_MASK     (0x80000U)
#define MEDIAMIX_BLK_CTRL_DSI_gp_clk_en_SHIFT    (19U)
/*! gp_clk_en - Enable for clkout_gp clock
 *  0b0..Disable clkout_gp clock
 *  0b1..Enable clkout_gp clock
 */
#define MEDIAMIX_BLK_CTRL_DSI_gp_clk_en(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_gp_clk_en_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_gp_clk_en_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_clk_ext_MASK       (0x100000U)
#define MEDIAMIX_BLK_CTRL_DSI_clk_ext_SHIFT      (20U)
/*! clk_ext - clk_ext */
#define MEDIAMIX_BLK_CTRL_DSI_clk_ext(x)         (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_clk_ext_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_clk_ext_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_cont_data_MASK     (0xFFE00000U)
#define MEDIAMIX_BLK_CTRL_DSI_cont_data_SHIFT    (21U)
/*! cont_data - cont_data */
#define MEDIAMIX_BLK_CTRL_DSI_cont_data(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_cont_data_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_cont_data_MASK)
/*! @} */

/*! @name DSI_W0 - DSI Write Register 0 */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_DSI_W0_M_MASK          (0x3FFU)
#define MEDIAMIX_BLK_CTRL_DSI_W0_M_SHIFT         (0U)
/*! M - Control of the feedback multiplication ratio M (40 to 625) for SoC direct PLL control */
#define MEDIAMIX_BLK_CTRL_DSI_W0_M(x)            (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W0_M_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W0_M_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W0_N_MASK          (0x3C00U)
#define MEDIAMIX_BLK_CTRL_DSI_W0_N_SHIFT         (10U)
/*! N - Control of the input frequency division ratio N (1 to 16) for SoC direct PLL control */
#define MEDIAMIX_BLK_CTRL_DSI_W0_N(x)            (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W0_N_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W0_N_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W0_VCO_CNTRL_MASK  (0xFC000U)
#define MEDIAMIX_BLK_CTRL_DSI_W0_VCO_CNTRL_SHIFT (14U)
/*! VCO_CNTRL - VCO operating range for SoC direct PLL control */
#define MEDIAMIX_BLK_CTRL_DSI_W0_VCO_CNTRL(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W0_VCO_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W0_VCO_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W0_PROP_CNTRL_MASK (0x3F00000U)
#define MEDIAMIX_BLK_CTRL_DSI_W0_PROP_CNTRL_SHIFT (20U)
/*! PROP_CNTRL - Proportional charge pump control for SoC direct PLL control */
#define MEDIAMIX_BLK_CTRL_DSI_W0_PROP_CNTRL(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W0_PROP_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W0_PROP_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W0_INT_CNTRL_MASK  (0xFC000000U)
#define MEDIAMIX_BLK_CTRL_DSI_W0_INT_CNTRL_SHIFT (26U)
/*! INT_CNTRL - Integral charge pump control for SoC direct PLL control */
#define MEDIAMIX_BLK_CTRL_DSI_W0_INT_CNTRL(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W0_INT_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W0_INT_CNTRL_MASK)
/*! @} */

/*! @name DSI_W1 - DSI Write Register 1 */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_DSI_W1_GMP_CNTRL_MASK  (0x3U)
#define MEDIAMIX_BLK_CTRL_DSI_W1_GMP_CNTRL_SHIFT (0U)
/*! GMP_CNTRL - Effective loop-filter resistance (=1/gmp) control */
#define MEDIAMIX_BLK_CTRL_DSI_W1_GMP_CNTRL(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W1_GMP_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W1_GMP_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W1_CPBIAS_CNTRL_MASK (0x1FCU)
#define MEDIAMIX_BLK_CTRL_DSI_W1_CPBIAS_CNTRL_SHIFT (2U)
/*! CPBIAS_CNTRL - Charge pump bias control */
#define MEDIAMIX_BLK_CTRL_DSI_W1_CPBIAS_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W1_CPBIAS_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W1_CPBIAS_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W1_PLL_SHADOW_CONTROL_MASK (0x200U)
#define MEDIAMIX_BLK_CTRL_DSI_W1_PLL_SHADOW_CONTROL_SHIFT (9U)
/*! PLL_SHADOW_CONTROL - PLL configuration select
 *  0b0..SoC control and shadow registers
 *  0b1..D-PHY control
 */
#define MEDIAMIX_BLK_CTRL_DSI_W1_PLL_SHADOW_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W1_PLL_SHADOW_CONTROL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W1_PLL_SHADOW_CONTROL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W1_FORCE_LOCK_MASK (0x400U)
#define MEDIAMIX_BLK_CTRL_DSI_W1_FORCE_LOCK_SHIFT (10U)
/*! FORCE_LOCK - PLL force lock control
 *  0b0..According to lock detector
 *  0b1..Force PLL internal lock indication
 */
#define MEDIAMIX_BLK_CTRL_DSI_W1_FORCE_LOCK(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W1_FORCE_LOCK_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W1_FORCE_LOCK_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_W1_BISTON_MASK     (0x800U)
#define MEDIAMIX_BLK_CTRL_DSI_W1_BISTON_SHIFT    (11U)
/*! BISTON - BIST start
 *  0b0..Do not start BIST
 *  0b1..Start BIST
 */
#define MEDIAMIX_BLK_CTRL_DSI_W1_BISTON(x)       (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_W1_BISTON_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_W1_BISTON_MASK)
/*! @} */

/*! @name DSI_R0 - DSI Read Register 0 */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_DSI_R0_M_MASK          (0x3FFU)
#define MEDIAMIX_BLK_CTRL_DSI_R0_M_SHIFT         (0U)
/*! M - Feedback multiplication ratio M (40 to 625) */
#define MEDIAMIX_BLK_CTRL_DSI_R0_M(x)            (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R0_M_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R0_M_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_R0_N_MASK          (0x3C00U)
#define MEDIAMIX_BLK_CTRL_DSI_R0_N_SHIFT         (10U)
/*! N - Input frequency division ratio N (1 to 16) */
#define MEDIAMIX_BLK_CTRL_DSI_R0_N(x)            (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R0_N_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R0_N_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_R0_VCO_CNTRL_MASK  (0xFC000U)
#define MEDIAMIX_BLK_CTRL_DSI_R0_VCO_CNTRL_SHIFT (14U)
/*! VCO_CNTRL - VCO operating range */
#define MEDIAMIX_BLK_CTRL_DSI_R0_VCO_CNTRL(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R0_VCO_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R0_VCO_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_R0_PROP_CNTRL_MASK (0x3F00000U)
#define MEDIAMIX_BLK_CTRL_DSI_R0_PROP_CNTRL_SHIFT (20U)
/*! PROP_CNTRL - Proportional charge pump status */
#define MEDIAMIX_BLK_CTRL_DSI_R0_PROP_CNTRL(x)   (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R0_PROP_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R0_PROP_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_R0_INT_CNTRL_MASK  (0xFC000000U)
#define MEDIAMIX_BLK_CTRL_DSI_R0_INT_CNTRL_SHIFT (26U)
/*! INT_CNTRL - Integral charge pump status */
#define MEDIAMIX_BLK_CTRL_DSI_R0_INT_CNTRL(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R0_INT_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R0_INT_CNTRL_MASK)
/*! @} */

/*! @name DSI_R1 - DSI Read Register 1 */
/*! @{ */

#define MEDIAMIX_BLK_CTRL_DSI_R1_GMP_CNTRL_MASK  (0x3U)
#define MEDIAMIX_BLK_CTRL_DSI_R1_GMP_CNTRL_SHIFT (0U)
/*! GMP_CNTRL - Effective loop-filter resistance (=1/gmp) status */
#define MEDIAMIX_BLK_CTRL_DSI_R1_GMP_CNTRL(x)    (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R1_GMP_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R1_GMP_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_R1_CPBIAS_CNTRL_MASK (0x1FCU)
#define MEDIAMIX_BLK_CTRL_DSI_R1_CPBIAS_CNTRL_SHIFT (2U)
/*! CPBIAS_CNTRL - Charge pump bias status */
#define MEDIAMIX_BLK_CTRL_DSI_R1_CPBIAS_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R1_CPBIAS_CNTRL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R1_CPBIAS_CNTRL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_R1_PLL_SHADOW_CONTROL_MASK (0x200U)
#define MEDIAMIX_BLK_CTRL_DSI_R1_PLL_SHADOW_CONTROL_SHIFT (9U)
/*! PLL_SHADOW_CONTROL - PLL configuration select */
#define MEDIAMIX_BLK_CTRL_DSI_R1_PLL_SHADOW_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R1_PLL_SHADOW_CONTROL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R1_PLL_SHADOW_CONTROL_MASK)

#define MEDIAMIX_BLK_CTRL_DSI_R1_LOCK_PLL_MASK   (0x400U)
#define MEDIAMIX_BLK_CTRL_DSI_R1_LOCK_PLL_SHIFT  (10U)
/*! LOCK_PLL - PLL lock state
 *  0b0..PLL is not locked
 *  0b1..PLL is locked
 */
#define MEDIAMIX_BLK_CTRL_DSI_R1_LOCK_PLL(x)     (((uint32_t)(((uint32_t)(x)) << MEDIAMIX_BLK_CTRL_DSI_R1_LOCK_PLL_SHIFT)) & MEDIAMIX_BLK_CTRL_DSI_R1_LOCK_PLL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MEDIAMIX_BLK_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group MEDIAMIX_BLK_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_MEDIAMIX_BLK_CTRL_H_ */
