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
**         CMSIS Peripheral Access Layer for USBPHY
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
 * @file PERI_USBPHY.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBPHY
 *
 * CMSIS Peripheral Access Layer for USBPHY
 */

#if !defined(PERI_USBPHY_H_)
#define PERI_USBPHY_H_                           /**< Symbol preventing repeated inclusion */

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
   -- USBPHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBPHY_Peripheral_Access_Layer USBPHY Peripheral Access Layer
 * @{
 */

/** USBPHY - Register Layout Typedef */
typedef struct {
  __IO uint32_t PWD;                               /**< Power Down, offset: 0x0 */
  __IO uint32_t PWD_SET;                           /**< Power Down, offset: 0x4 */
  __IO uint32_t PWD_CLR;                           /**< Power Down, offset: 0x8 */
  __IO uint32_t PWD_TOG;                           /**< Power Down, offset: 0xC */
  __IO uint32_t TX;                                /**< TX Control, offset: 0x10 */
  __IO uint32_t TX_SET;                            /**< TX Control, offset: 0x14 */
  __IO uint32_t TX_CLR;                            /**< TX Control, offset: 0x18 */
  __IO uint32_t TX_TOG;                            /**< TX Control, offset: 0x1C */
  __IO uint32_t RX;                                /**< RX Control, offset: 0x20 */
  __IO uint32_t RX_SET;                            /**< RX Control, offset: 0x24 */
  __IO uint32_t RX_CLR;                            /**< RX Control, offset: 0x28 */
  __IO uint32_t RX_TOG;                            /**< RX Control, offset: 0x2C */
  __IO uint32_t CTRL;                              /**< General Purpose Control, offset: 0x30 */
  __IO uint32_t CTRL_SET;                          /**< General Purpose Control, offset: 0x34 */
  __IO uint32_t CTRL_CLR;                          /**< General Purpose Control, offset: 0x38 */
  __IO uint32_t CTRL_TOG;                          /**< General Purpose Control, offset: 0x3C */
  __IO uint32_t STATUS;                            /**< Status, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DEBUG0;                            /**< Debug 0, offset: 0x50 */
  __IO uint32_t DEBUG0_SET;                        /**< Debug 0, offset: 0x54 */
  __IO uint32_t DEBUG0_CLR;                        /**< Debug 0, offset: 0x58 */
  __IO uint32_t DEBUG0_TOG;                        /**< Debug 0, offset: 0x5C */
       uint8_t RESERVED_1[32];
  __I  uint32_t VERSION;                           /**< Version, offset: 0x80 */
       uint8_t RESERVED_2[12];
  __IO uint32_t IP;                                /**< IP Block, offset: 0x90 */
  __IO uint32_t IP_SET;                            /**< IP Block, offset: 0x94 */
  __IO uint32_t IP_CLR;                            /**< IP Block, offset: 0x98 */
  __IO uint32_t IP_TOG;                            /**< IP Block, offset: 0x9C */
  __IO uint32_t PLL_SIC;                           /**< PLL SIC, offset: 0xA0 */
  __IO uint32_t PLL_SIC_SET;                       /**< PLL SIC, offset: 0xA4 */
  __IO uint32_t PLL_SIC_CLR;                       /**< PLL SIC, offset: 0xA8 */
  __IO uint32_t PLL_SIC_TOG;                       /**< PLL SIC, offset: 0xAC */
       uint8_t RESERVED_3[16];
  __IO uint32_t USB1_VBUS_DETECT;                  /**< VBUS Detect, offset: 0xC0 */
  __IO uint32_t USB1_VBUS_DETECT_SET;              /**< VBUS Detect, offset: 0xC4 */
  __IO uint32_t USB1_VBUS_DETECT_CLR;              /**< VBUS Detect, offset: 0xC8 */
  __IO uint32_t USB1_VBUS_DETECT_TOG;              /**< VBUS Detect, offset: 0xCC */
  __I  uint32_t USB1_VBUS_DET_STAT;                /**< VBUS Detect Status, offset: 0xD0 */
  __I  uint32_t USB1_VBUS_DET_STAT_SET;            /**< VBUS Detect Status, offset: 0xD4 */
  __I  uint32_t USB1_VBUS_DET_STAT_CLR;            /**< VBUS Detect Status, offset: 0xD8 */
  __I  uint32_t USB1_VBUS_DET_STAT_TOG;            /**< VBUS Detect Status, offset: 0xDC */
  __IO uint32_t USB1_CHRG_DETECT;                  /**< Charger Detect, offset: 0xE0 */
  __IO uint32_t USB1_CHRG_DETECT_SET;              /**< Charger Detect, offset: 0xE4 */
  __IO uint32_t USB1_CHRG_DETECT_CLR;              /**< Charger Detect, offset: 0xE8 */
  __IO uint32_t USB1_CHRG_DETECT_TOG;              /**< Charger Detect, offset: 0xEC */
  __I  uint32_t USB1_CHRG_DET_STAT;                /**< Charger Detect Status, offset: 0xF0 */
  __I  uint32_t USB1_CHRG_DET_STAT_SET;            /**< Charger Detect Status, offset: 0xF4 */
  __I  uint32_t USB1_CHRG_DET_STAT_CLR;            /**< Charger Detect Status, offset: 0xF8 */
  __I  uint32_t USB1_CHRG_DET_STAT_TOG;            /**< Charger Detect Status, offset: 0xFC */
  __IO uint32_t ANACTRL;                           /**< Analog Control, offset: 0x100 */
  __IO uint32_t ANACTRL_SET;                       /**< Analog Control, offset: 0x104 */
  __IO uint32_t ANACTRL_CLR;                       /**< Analog Control, offset: 0x108 */
  __IO uint32_t ANACTRL_TOG;                       /**< Analog Control, offset: 0x10C */
       uint8_t RESERVED_4[32];
  __IO uint32_t TRIM_OVERRIDE_EN;                  /**< Trim, offset: 0x130 */
  __IO uint32_t TRIM_OVERRIDE_EN_SET;              /**< Trim, offset: 0x134 */
  __IO uint32_t TRIM_OVERRIDE_EN_CLR;              /**< Trim, offset: 0x138 */
  __IO uint32_t TRIM_OVERRIDE_EN_TOG;              /**< Trim, offset: 0x13C */
  __IO uint32_t PFDA;                              /**< PFD A, offset: 0x140 */
  __IO uint32_t PFDA_SET;                          /**< PFD A, offset: 0x144 */
  __IO uint32_t PFDA_CLR;                          /**< PFD A, offset: 0x148 */
  __IO uint32_t PFDA_TOG;                          /**< PFD A, offset: 0x14C */
} USBPHY_Type;

/* ----------------------------------------------------------------------------
   -- USBPHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBPHY_Register_Masks USBPHY Register Masks
 * @{
 */

/*! @name PWD - Power Down */
/*! @{ */

#define USBPHY_PWD_TXPWDFS_MASK                  (0x400U)
#define USBPHY_PWD_TXPWDFS_SHIFT                 (10U)
/*! TXPWDFS - Power Down USB FS TX Drivers
 *  0b0..Provide bias to enable
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_TXPWDFS(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDFS_SHIFT)) & USBPHY_PWD_TXPWDFS_MASK)

#define USBPHY_PWD_TXPWDIBIAS_MASK               (0x800U)
#define USBPHY_PWD_TXPWDIBIAS_SHIFT              (11U)
/*! TXPWDIBIAS - Power Down USBPHY TX Current Bias Block
 *  0b0..Enable
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_TXPWDIBIAS(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TXPWDV2I_MASK                 (0x1000U)
#define USBPHY_PWD_TXPWDV2I_SHIFT                (12U)
/*! TXPWDV2I - Power Down USBPHY TX V-I Converter and Current Mirror
 *  0b0..Enable
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_TXPWDV2I(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDV2I_SHIFT)) & USBPHY_PWD_TXPWDV2I_MASK)

#define USBPHY_PWD_RXPWDENV_MASK                 (0x20000U)
#define USBPHY_PWD_RXPWDENV_SHIFT                (17U)
/*! RXPWDENV - Power Down USB HS RX Envelope Detector
 *  0b0..Enable
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_RXPWDENV(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDENV_SHIFT)) & USBPHY_PWD_RXPWDENV_MASK)

#define USBPHY_PWD_RXPWD1PT1_MASK                (0x40000U)
#define USBPHY_PWD_RXPWD1PT1_SHIFT               (18U)
/*! RXPWD1PT1 - Power Down USB FS Differential Receiver
 *  0b0..Enable
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_RXPWD1PT1(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWD1PT1_SHIFT)) & USBPHY_PWD_RXPWD1PT1_MASK)

#define USBPHY_PWD_RXPWDDIFF_MASK                (0x80000U)
#define USBPHY_PWD_RXPWDDIFF_SHIFT               (19U)
/*! RXPWDDIFF - Power Down USB HS Differential Receiver
 *  0b0..Enable
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_RXPWDDIFF(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDDIFF_SHIFT)) & USBPHY_PWD_RXPWDDIFF_MASK)

#define USBPHY_PWD_RXPWDRX_MASK                  (0x100000U)
#define USBPHY_PWD_RXPWDRX_SHIFT                 (20U)
/*! RXPWDRX - Power Down USBPHY Receiver Circuits
 *  0b0..Enable
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_RXPWDRX(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDRX_SHIFT)) & USBPHY_PWD_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_SET - Power Down */
/*! @{ */

#define USBPHY_PWD_SET_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_SET_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - Power Down USB FS TX Drivers */
#define USBPHY_PWD_SET_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDFS_SHIFT)) & USBPHY_PWD_SET_TXPWDFS_MASK)

#define USBPHY_PWD_SET_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_SET_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Power Down USBPHY TX Current Bias Block */
#define USBPHY_PWD_SET_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_SET_TXPWDIBIAS_MASK)

#define USBPHY_PWD_SET_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_SET_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - Power Down USBPHY TX V-I Converter and Current Mirror */
#define USBPHY_PWD_SET_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDV2I_SHIFT)) & USBPHY_PWD_SET_TXPWDV2I_MASK)

#define USBPHY_PWD_SET_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_SET_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Power Down USB HS RX Envelope Detector */
#define USBPHY_PWD_SET_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDENV_SHIFT)) & USBPHY_PWD_SET_RXPWDENV_MASK)

#define USBPHY_PWD_SET_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_SET_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - Power Down USB FS Differential Receiver */
#define USBPHY_PWD_SET_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWD1PT1_SHIFT)) & USBPHY_PWD_SET_RXPWD1PT1_MASK)

#define USBPHY_PWD_SET_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_SET_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - Power Down USB HS Differential Receiver */
#define USBPHY_PWD_SET_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDDIFF_SHIFT)) & USBPHY_PWD_SET_RXPWDDIFF_MASK)

#define USBPHY_PWD_SET_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_SET_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Power Down USBPHY Receiver Circuits */
#define USBPHY_PWD_SET_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDRX_SHIFT)) & USBPHY_PWD_SET_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_CLR - Power Down */
/*! @{ */

#define USBPHY_PWD_CLR_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_CLR_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - Power Down USB FS TX Drivers */
#define USBPHY_PWD_CLR_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDFS_SHIFT)) & USBPHY_PWD_CLR_TXPWDFS_MASK)

#define USBPHY_PWD_CLR_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Power Down USBPHY TX Current Bias Block */
#define USBPHY_PWD_CLR_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_CLR_TXPWDIBIAS_MASK)

#define USBPHY_PWD_CLR_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_CLR_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - Power Down USBPHY TX V-I Converter and Current Mirror */
#define USBPHY_PWD_CLR_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDV2I_SHIFT)) & USBPHY_PWD_CLR_TXPWDV2I_MASK)

#define USBPHY_PWD_CLR_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_CLR_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Power Down USB HS RX Envelope Detector */
#define USBPHY_PWD_CLR_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDENV_SHIFT)) & USBPHY_PWD_CLR_RXPWDENV_MASK)

#define USBPHY_PWD_CLR_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_CLR_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - Power Down USB FS Differential Receiver */
#define USBPHY_PWD_CLR_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWD1PT1_SHIFT)) & USBPHY_PWD_CLR_RXPWD1PT1_MASK)

#define USBPHY_PWD_CLR_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_CLR_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - Power Down USB HS Differential Receiver */
#define USBPHY_PWD_CLR_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDDIFF_SHIFT)) & USBPHY_PWD_CLR_RXPWDDIFF_MASK)

#define USBPHY_PWD_CLR_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_CLR_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Power Down USBPHY Receiver Circuits */
#define USBPHY_PWD_CLR_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDRX_SHIFT)) & USBPHY_PWD_CLR_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_TOG - Power Down */
/*! @{ */

#define USBPHY_PWD_TOG_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_TOG_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - Power Down USB FS TX Drivers */
#define USBPHY_PWD_TOG_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDFS_SHIFT)) & USBPHY_PWD_TOG_TXPWDFS_MASK)

#define USBPHY_PWD_TOG_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Power Down USBPHY TX Current Bias Block */
#define USBPHY_PWD_TOG_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TOG_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TOG_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_TOG_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - Power Down USBPHY TX V-I Converter and Current Mirror */
#define USBPHY_PWD_TOG_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDV2I_SHIFT)) & USBPHY_PWD_TOG_TXPWDV2I_MASK)

#define USBPHY_PWD_TOG_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_TOG_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Power Down USB HS RX Envelope Detector */
#define USBPHY_PWD_TOG_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDENV_SHIFT)) & USBPHY_PWD_TOG_RXPWDENV_MASK)

#define USBPHY_PWD_TOG_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_TOG_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - Power Down USB FS Differential Receiver */
#define USBPHY_PWD_TOG_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWD1PT1_SHIFT)) & USBPHY_PWD_TOG_RXPWD1PT1_MASK)

#define USBPHY_PWD_TOG_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_TOG_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - Power Down USB HS Differential Receiver */
#define USBPHY_PWD_TOG_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDDIFF_SHIFT)) & USBPHY_PWD_TOG_RXPWDDIFF_MASK)

#define USBPHY_PWD_TOG_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_TOG_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Power Down USBPHY Receiver Circuits */
#define USBPHY_PWD_TOG_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDRX_SHIFT)) & USBPHY_PWD_TOG_RXPWDRX_MASK)
/*! @} */

/*! @name TX - TX Control */
/*! @{ */

#define USBPHY_TX_D_CAL_MASK                     (0xFU)
#define USBPHY_TX_D_CAL_SHIFT                    (0U)
/*! D_CAL - HS TX Output Current Trim
 *  0b0000..Maximum current, approximately 19% above nominal
 *  0b0111..Nominal
 *  0b1111..Minimum current, approximately 19% below nominal
 */
#define USBPHY_TX_D_CAL(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TX_D_CAL_MASK)

#define USBPHY_TX_TXCAL45DN_MASK                 (0xF00U)
#define USBPHY_TX_TXCAL45DN_SHIFT                (8U)
/*! TXCAL45DN - DM Series Termination Resistance Trim */
#define USBPHY_TX_TXCAL45DN(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DN_SHIFT)) & USBPHY_TX_TXCAL45DN_MASK)

#define USBPHY_TX_TXCAL45DP_MASK                 (0xF0000U)
#define USBPHY_TX_TXCAL45DP_SHIFT                (16U)
/*! TXCAL45DP - DP Series Termination Resistance Trim */
#define USBPHY_TX_TXCAL45DP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DP_SHIFT)) & USBPHY_TX_TXCAL45DP_MASK)
/*! @} */

/*! @name TX_SET - TX Control */
/*! @{ */

#define USBPHY_TX_SET_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_SET_D_CAL_SHIFT                (0U)
/*! D_CAL - HS TX Output Current Trim */
#define USBPHY_TX_SET_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_D_CAL_SHIFT)) & USBPHY_TX_SET_D_CAL_MASK)

#define USBPHY_TX_SET_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_SET_TXCAL45DN_SHIFT            (8U)
/*! TXCAL45DN - DM Series Termination Resistance Trim */
#define USBPHY_TX_SET_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXCAL45DN_SHIFT)) & USBPHY_TX_SET_TXCAL45DN_MASK)

#define USBPHY_TX_SET_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_SET_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - DP Series Termination Resistance Trim */
#define USBPHY_TX_SET_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXCAL45DP_SHIFT)) & USBPHY_TX_SET_TXCAL45DP_MASK)
/*! @} */

/*! @name TX_CLR - TX Control */
/*! @{ */

#define USBPHY_TX_CLR_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_CLR_D_CAL_SHIFT                (0U)
/*! D_CAL - HS TX Output Current Trim */
#define USBPHY_TX_CLR_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_D_CAL_SHIFT)) & USBPHY_TX_CLR_D_CAL_MASK)

#define USBPHY_TX_CLR_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_CLR_TXCAL45DN_SHIFT            (8U)
/*! TXCAL45DN - DM Series Termination Resistance Trim */
#define USBPHY_TX_CLR_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXCAL45DN_SHIFT)) & USBPHY_TX_CLR_TXCAL45DN_MASK)

#define USBPHY_TX_CLR_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_CLR_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - DP Series Termination Resistance Trim */
#define USBPHY_TX_CLR_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXCAL45DP_SHIFT)) & USBPHY_TX_CLR_TXCAL45DP_MASK)
/*! @} */

/*! @name TX_TOG - TX Control */
/*! @{ */

#define USBPHY_TX_TOG_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_TOG_D_CAL_SHIFT                (0U)
/*! D_CAL - HS TX Output Current Trim */
#define USBPHY_TX_TOG_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_D_CAL_SHIFT)) & USBPHY_TX_TOG_D_CAL_MASK)

#define USBPHY_TX_TOG_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_TOG_TXCAL45DN_SHIFT            (8U)
/*! TXCAL45DN - DM Series Termination Resistance Trim */
#define USBPHY_TX_TOG_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXCAL45DN_SHIFT)) & USBPHY_TX_TOG_TXCAL45DN_MASK)

#define USBPHY_TX_TOG_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_TOG_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - DP Series Termination Resistance Trim */
#define USBPHY_TX_TOG_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXCAL45DP_SHIFT)) & USBPHY_TX_TOG_TXCAL45DP_MASK)
/*! @} */

/*! @name RX - RX Control */
/*! @{ */

#define USBPHY_RX_ENVADJ_MASK                    (0x7U)
#define USBPHY_RX_ENVADJ_SHIFT                   (0U)
/*! ENVADJ - Envelope Detector Trip Point
 *  0b000..0.1000 V
 *  0b001..0.1125 V
 *  0b010..0.1250 V
 *  0b011..0.0875 V
 *  0b1xx..
 */
#define USBPHY_RX_ENVADJ(x)                      (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_ENVADJ_SHIFT)) & USBPHY_RX_ENVADJ_MASK)

#define USBPHY_RX_DISCONADJ_MASK                 (0x70U)
#define USBPHY_RX_DISCONADJ_SHIFT                (4U)
/*! DISCONADJ - Disconnect Detector Trip Point
 *  0b000..0.56875 V
 *  0b001..0.55000 V
 *  0b010..0.58125 V
 *  0b011..0.60000 V
 *  0b1xx..
 */
#define USBPHY_RX_DISCONADJ(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_DISCONADJ_SHIFT)) & USBPHY_RX_DISCONADJ_MASK)
/*! @} */

/*! @name RX_SET - RX Control */
/*! @{ */

#define USBPHY_RX_SET_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_SET_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope Detector Trip Point */
#define USBPHY_RX_SET_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_ENVADJ_SHIFT)) & USBPHY_RX_SET_ENVADJ_MASK)

#define USBPHY_RX_SET_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_SET_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect Detector Trip Point */
#define USBPHY_RX_SET_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_DISCONADJ_SHIFT)) & USBPHY_RX_SET_DISCONADJ_MASK)
/*! @} */

/*! @name RX_CLR - RX Control */
/*! @{ */

#define USBPHY_RX_CLR_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_CLR_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope Detector Trip Point */
#define USBPHY_RX_CLR_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_ENVADJ_SHIFT)) & USBPHY_RX_CLR_ENVADJ_MASK)

#define USBPHY_RX_CLR_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_CLR_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect Detector Trip Point */
#define USBPHY_RX_CLR_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_DISCONADJ_SHIFT)) & USBPHY_RX_CLR_DISCONADJ_MASK)
/*! @} */

/*! @name RX_TOG - RX Control */
/*! @{ */

#define USBPHY_RX_TOG_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_TOG_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope Detector Trip Point */
#define USBPHY_RX_TOG_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_ENVADJ_SHIFT)) & USBPHY_RX_TOG_ENVADJ_MASK)

#define USBPHY_RX_TOG_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_TOG_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect Detector Trip Point */
#define USBPHY_RX_TOG_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_DISCONADJ_SHIFT)) & USBPHY_RX_TOG_DISCONADJ_MASK)
/*! @} */

/*! @name CTRL - General Purpose Control */
/*! @{ */

#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ_MASK        (0x1U)
#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ_SHIFT       (0U)
/*! ENOTG_ID_CHG_IRQ - OTG ID Change Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_ENHOSTDISCONDETECT_MASK      (0x2U)
#define USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT     (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENHOSTDISCONDETECT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_ENIRQHOSTDISCON_MASK         (0x4U)
#define USBPHY_CTRL_ENIRQHOSTDISCON_SHIFT        (2U)
/*! ENIRQHOSTDISCON - Enable Interrupt for Host Disconnect
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQHOSTDISCON(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK    (0x8U)
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT   (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt
 *  0b0..Connected
 *  0b1..Disconnected
 */
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_ENDEVPLUGINDETECT_MASK       (0x10U)
#define USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT      (4U)
/*! ENDEVPLUGINDETECT - Enable Nonstandard Resistive Plugged-In Detection
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENDEVPLUGINDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_DEVPLUGIN_POLARITY_MASK      (0x20U)
#define USBPHY_CTRL_DEVPLUGIN_POLARITY_SHIFT     (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity
 *  0b0..Plugged in
 *  0b1..Unplugged
 */
#define USBPHY_CTRL_DEVPLUGIN_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_OTG_ID_CHG_IRQ_MASK          (0x40U)
#define USBPHY_CTRL_OTG_ID_CHG_IRQ_SHIFT         (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt
 *  0b0..No ID change interrupt
 *  0b1..ID change interrupt
 */
#define USBPHY_CTRL_OTG_ID_CHG_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_ENOTGIDDETECT_MASK           (0x80U)
#define USBPHY_CTRL_ENOTGIDDETECT_SHIFT          (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENOTGIDDETECT(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_RESUMEIRQSTICKY_MASK         (0x100U)
#define USBPHY_CTRL_RESUMEIRQSTICKY_SHIFT        (8U)
/*! RESUMEIRQSTICKY - Resume Interrupt Sticky
 *  0b0..During the resume or reset state signaling period
 *  0b1..Until you write 0 to it
 */
#define USBPHY_CTRL_RESUMEIRQSTICKY(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_ENIRQRESUMEDETECT_MASK       (0x200U)
#define USBPHY_CTRL_ENIRQRESUMEDETECT_SHIFT      (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQRESUMEDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_RESUME_IRQ_MASK              (0x400U)
#define USBPHY_CTRL_RESUME_IRQ_SHIFT             (10U)
/*! RESUME_IRQ - Resume Interrupt
 *  0b0..No resume interrupt
 *  0b1..Resume interrupt
 */
#define USBPHY_CTRL_RESUME_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_RESUME_IRQ_MASK)

#define USBPHY_CTRL_ENIRQDEVPLUGIN_MASK          (0x800U)
#define USBPHY_CTRL_ENIRQDEVPLUGIN_SHIFT         (11U)
/*! ENIRQDEVPLUGIN - Enable Interrupt for Nonstandard Resistive Plugged-In Detection
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQDEVPLUGIN(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_DEVPLUGIN_IRQ_MASK           (0x1000U)
#define USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT          (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt */
#define USBPHY_CTRL_DEVPLUGIN_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_DATA_ON_LRADC_MASK           (0x2000U)
#define USBPHY_CTRL_DATA_ON_LRADC_SHIFT          (13U)
/*! DATA_ON_LRADC - APB Clock Switch Option */
#define USBPHY_CTRL_DATA_ON_LRADC(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_ENUTMILEVEL2_MASK            (0x4000U)
#define USBPHY_CTRL_ENUTMILEVEL2_SHIFT           (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENUTMILEVEL2(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_ENUTMILEVEL3_MASK            (0x8000U)
#define USBPHY_CTRL_ENUTMILEVEL3_SHIFT           (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENUTMILEVEL3(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_ENIRQWAKEUP_MASK             (0x10000U)
#define USBPHY_CTRL_ENIRQWAKEUP_SHIFT            (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQWAKEUP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_WAKEUP_IRQ_MASK              (0x20000U)
#define USBPHY_CTRL_WAKEUP_IRQ_SHIFT             (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt */
#define USBPHY_CTRL_WAKEUP_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_AUTORESUME_EN_MASK           (0x40000U)
#define USBPHY_CTRL_AUTORESUME_EN_SHIFT          (18U)
/*! AUTORESUME_EN - Autoresume Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_AUTORESUME_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK       (0x80000U)
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT      (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear Clock Gate Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK       (0x100000U)
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT      (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Autoclear Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_OTG_ID_VALUE_MASK            (0x8000000U)
#define USBPHY_CTRL_OTG_ID_VALUE_SHIFT           (27U)
/*! OTG_ID_VALUE - OTG ID Value
 *  0b0..Host
 *  0b1..Device
 */
#define USBPHY_CTRL_OTG_ID_VALUE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_UTMI_SUSPENDM_MASK           (0x20000000U)
#define USBPHY_CTRL_UTMI_SUSPENDM_SHIFT          (29U)
/*! UTMI_SUSPENDM - UTMI Suspend
 *  0b0..Not suspended
 *  0b1..Suspended
 */
#define USBPHY_CTRL_UTMI_SUSPENDM(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLKGATE_MASK                 (0x40000000U)
#define USBPHY_CTRL_CLKGATE_SHIFT                (30U)
/*! CLKGATE - UTMI Clock Gate
 *  0b0..Run clocks
 *  0b1..Gate clocks
 */
#define USBPHY_CTRL_CLKGATE(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLKGATE_SHIFT)) & USBPHY_CTRL_CLKGATE_MASK)

#define USBPHY_CTRL_SFTRST_MASK                  (0x80000000U)
#define USBPHY_CTRL_SFTRST_SHIFT                 (31U)
/*! SFTRST - Software Reset
 *  0b0..Release from reset
 *  0b1..Soft-reset
 */
#define USBPHY_CTRL_SFTRST(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SFTRST_SHIFT)) & USBPHY_CTRL_SFTRST_MASK)
/*! @} */

/*! @name CTRL_SET - General Purpose Control */
/*! @{ */

#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
/*! ENOTG_ID_CHG_IRQ - OTG ID Change Interrupt Enable */
#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable */
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_SET_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_SET_ENIRQHOSTDISCON_SHIFT    (2U)
/*! ENIRQHOSTDISCON - Enable Interrupt for Host Disconnect */
#define USBPHY_CTRL_SET_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_SET_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt */
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT_SHIFT  (4U)
/*! ENDEVPLUGINDETECT - Enable Nonstandard Resistive Plugged-In Detection */
#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_SET_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_SHIFT (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity */
#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_SHIFT     (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt */
#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_SET_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_SET_ENOTGIDDETECT_SHIFT      (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector */
#define USBPHY_CTRL_SET_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_SET_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_SET_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_SET_RESUMEIRQSTICKY_SHIFT    (8U)
/*! RESUMEIRQSTICKY - Resume Interrupt Sticky */
#define USBPHY_CTRL_SET_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_SET_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT_SHIFT  (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable */
#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_SET_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_SET_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_SET_RESUME_IRQ_SHIFT         (10U)
/*! RESUME_IRQ - Resume Interrupt */
#define USBPHY_CTRL_SET_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_SET_RESUME_IRQ_MASK)

#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN_SHIFT     (11U)
/*! ENIRQDEVPLUGIN - Enable Interrupt for Nonstandard Resistive Plugged-In Detection */
#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_SET_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt */
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_SET_DATA_ON_LRADC_MASK       (0x2000U)
#define USBPHY_CTRL_SET_DATA_ON_LRADC_SHIFT      (13U)
/*! DATA_ON_LRADC - APB Clock Switch Option */
#define USBPHY_CTRL_SET_DATA_ON_LRADC(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_SET_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable */
#define USBPHY_CTRL_SET_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable */
#define USBPHY_CTRL_SET_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_SET_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_SET_ENIRQWAKEUP_SHIFT        (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable */
#define USBPHY_CTRL_SET_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_SET_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_SET_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_SET_WAKEUP_IRQ_SHIFT         (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt */
#define USBPHY_CTRL_SET_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_SET_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_SET_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_SET_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Autoresume Enable */
#define USBPHY_CTRL_SET_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_SET_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear Clock Gate Enable */
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Autoclear Enable */
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_SET_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_SET_OTG_ID_VALUE_SHIFT       (27U)
/*! OTG_ID_VALUE - OTG ID Value */
#define USBPHY_CTRL_SET_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_SET_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI Suspend */
#define USBPHY_CTRL_SET_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_SET_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_SET_CLKGATE_SHIFT            (30U)
/*! CLKGATE - UTMI Clock Gate */
#define USBPHY_CTRL_SET_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_CLKGATE_MASK)

#define USBPHY_CTRL_SET_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_SET_SFTRST_SHIFT             (31U)
/*! SFTRST - Software Reset */
#define USBPHY_CTRL_SET_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_SFTRST_SHIFT)) & USBPHY_CTRL_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL_CLR - General Purpose Control */
/*! @{ */

#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
/*! ENOTG_ID_CHG_IRQ - OTG ID Change Interrupt Enable */
#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable */
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON_SHIFT    (2U)
/*! ENIRQHOSTDISCON - Enable Interrupt for Host Disconnect */
#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_CLR_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt */
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_SHIFT  (4U)
/*! ENDEVPLUGINDETECT - Enable Nonstandard Resistive Plugged-In Detection */
#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_SHIFT (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity */
#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_SHIFT     (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt */
#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_CLR_ENOTGIDDETECT_SHIFT      (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector */
#define USBPHY_CTRL_CLR_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY_SHIFT    (8U)
/*! RESUMEIRQSTICKY - Resume Interrupt Sticky */
#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_CLR_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_SHIFT  (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable */
#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_CLR_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_CLR_RESUME_IRQ_SHIFT         (10U)
/*! RESUME_IRQ - Resume Interrupt */
#define USBPHY_CTRL_CLR_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_CLR_RESUME_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_SHIFT     (11U)
/*! ENIRQDEVPLUGIN - Enable Interrupt for Nonstandard Resistive Plugged-In Detection */
#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt */
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_CLR_DATA_ON_LRADC_MASK       (0x2000U)
#define USBPHY_CTRL_CLR_DATA_ON_LRADC_SHIFT      (13U)
/*! DATA_ON_LRADC - APB Clock Switch Option */
#define USBPHY_CTRL_CLR_DATA_ON_LRADC(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_CLR_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable */
#define USBPHY_CTRL_CLR_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable */
#define USBPHY_CTRL_CLR_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_CLR_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_CLR_ENIRQWAKEUP_SHIFT        (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable */
#define USBPHY_CTRL_CLR_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_CLR_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_CLR_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_CLR_WAKEUP_IRQ_SHIFT         (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt */
#define USBPHY_CTRL_CLR_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_CLR_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_CLR_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_CLR_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Autoresume Enable */
#define USBPHY_CTRL_CLR_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_CLR_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear Clock Gate Enable */
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Autoclear Enable */
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_CLR_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_CLR_OTG_ID_VALUE_SHIFT       (27U)
/*! OTG_ID_VALUE - OTG ID Value */
#define USBPHY_CTRL_CLR_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_CLR_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI Suspend */
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLR_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_CLR_CLKGATE_SHIFT            (30U)
/*! CLKGATE - UTMI Clock Gate */
#define USBPHY_CTRL_CLR_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_CLR_SFTRST_SHIFT             (31U)
/*! SFTRST - Software Reset */
#define USBPHY_CTRL_CLR_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_SFTRST_SHIFT)) & USBPHY_CTRL_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL_TOG - General Purpose Control */
/*! @{ */

#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
/*! ENOTG_ID_CHG_IRQ - OTG ID Change Interrupt Enable */
#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable */
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON_SHIFT    (2U)
/*! ENIRQHOSTDISCON - Enable Interrupt for Host Disconnect */
#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_TOG_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt */
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_SHIFT  (4U)
/*! ENDEVPLUGINDETECT - Enable Nonstandard Resistive Plugged-In Detection */
#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_SHIFT (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity */
#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_SHIFT     (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt */
#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_TOG_ENOTGIDDETECT_SHIFT      (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector */
#define USBPHY_CTRL_TOG_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY_SHIFT    (8U)
/*! RESUMEIRQSTICKY - Resume Interrupt Sticky */
#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_TOG_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_SHIFT  (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable */
#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_TOG_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_TOG_RESUME_IRQ_SHIFT         (10U)
/*! RESUME_IRQ - Resume Interrupt */
#define USBPHY_CTRL_TOG_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_TOG_RESUME_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_SHIFT     (11U)
/*! ENIRQDEVPLUGIN - Enable Interrupt for Nonstandard Resistive Plugged-In Detection */
#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt */
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_TOG_DATA_ON_LRADC_MASK       (0x2000U)
#define USBPHY_CTRL_TOG_DATA_ON_LRADC_SHIFT      (13U)
/*! DATA_ON_LRADC - APB Clock Switch Option */
#define USBPHY_CTRL_TOG_DATA_ON_LRADC(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_TOG_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable */
#define USBPHY_CTRL_TOG_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable */
#define USBPHY_CTRL_TOG_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_TOG_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_TOG_ENIRQWAKEUP_SHIFT        (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable */
#define USBPHY_CTRL_TOG_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_TOG_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_TOG_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_TOG_WAKEUP_IRQ_SHIFT         (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt */
#define USBPHY_CTRL_TOG_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_TOG_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_TOG_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_TOG_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Autoresume Enable */
#define USBPHY_CTRL_TOG_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_TOG_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear Clock Gate Enable */
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Autoclear Enable */
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_TOG_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_TOG_OTG_ID_VALUE_SHIFT       (27U)
/*! OTG_ID_VALUE - OTG ID Value */
#define USBPHY_CTRL_TOG_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_TOG_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI Suspend */
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_TOG_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_TOG_CLKGATE_SHIFT            (30U)
/*! CLKGATE - UTMI Clock Gate */
#define USBPHY_CTRL_TOG_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_TOG_SFTRST_SHIFT             (31U)
/*! SFTRST - Software Reset */
#define USBPHY_CTRL_TOG_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_SFTRST_SHIFT)) & USBPHY_CTRL_TOG_SFTRST_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define USBPHY_STATUS_OK_STATUS_3V_MASK          (0x1U)
#define USBPHY_STATUS_OK_STATUS_3V_SHIFT         (0U)
/*! OK_STATUS_3V - USB 3.3 V and 1.8 V Supply Status
 *  0b0..Not powered
 *  0b1..Powered
 */
#define USBPHY_STATUS_OK_STATUS_3V(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_OK_STATUS_3V_SHIFT)) & USBPHY_STATUS_OK_STATUS_3V_MASK)

#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK (0x8U)
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT (3U)
/*! HOSTDISCONDETECT_STATUS - Host Disconnect Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT)) & USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK)

#define USBPHY_STATUS_DEVPLUGIN_STATUS_MASK      (0x40U)
#define USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT     (6U)
/*! DEVPLUGIN_STATUS - Status Indicator for Nonstandard Resistive Plugged-In Detection
 *  0b0..No attachment detected
 *  0b1..Cable attachment detected
 */
#define USBPHY_STATUS_DEVPLUGIN_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT)) & USBPHY_STATUS_DEVPLUGIN_STATUS_MASK)

#define USBPHY_STATUS_OTGID_STATUS_MASK          (0x100U)
#define USBPHY_STATUS_OTGID_STATUS_SHIFT         (8U)
/*! OTGID_STATUS - OTG ID Status
 *  0b0..Host
 *  0b1..Device
 */
#define USBPHY_STATUS_OTGID_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_OTGID_STATUS_SHIFT)) & USBPHY_STATUS_OTGID_STATUS_MASK)

#define USBPHY_STATUS_RESUME_STATUS_MASK         (0x400U)
#define USBPHY_STATUS_RESUME_STATUS_SHIFT        (10U)
/*! RESUME_STATUS - Resume Status */
#define USBPHY_STATUS_RESUME_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RESUME_STATUS_SHIFT)) & USBPHY_STATUS_RESUME_STATUS_MASK)
/*! @} */

/*! @name DEBUG0 - Debug 0 */
/*! @{ */

#define USBPHY_DEBUG0_OTGIDPIOLOCK_MASK          (0x1U)
#define USBPHY_DEBUG0_OTGIDPIOLOCK_SHIFT         (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG0_OTGIDPIOLOCK(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG0_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG0_HSTPULLDOWN_MASK           (0xCU)
#define USBPHY_DEBUG0_HSTPULLDOWN_SHIFT          (2U)
/*! HSTPULLDOWN - Host Pulldown Overdrive Mode
 *  0b00..Disconnect
 *  0b01..Connect
 */
#define USBPHY_DEBUG0_HSTPULLDOWN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_ENHSTPULLDOWN_MASK         (0x30U)
#define USBPHY_DEBUG0_ENHSTPULLDOWN_SHIFT        (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode
 *  0b00..Disable
 *  0b01..Enable
 */
#define USBPHY_DEBUG0_ENHSTPULLDOWN(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_ENHSTPULLDOWN_MASK)
/*! @} */

/*! @name DEBUG0_SET - Debug 0 */
/*! @{ */

#define USBPHY_DEBUG0_SET_OTGIDPIOLOCK_MASK      (0x1U)
#define USBPHY_DEBUG0_SET_OTGIDPIOLOCK_SHIFT     (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG0_SET_OTGIDPIOLOCK(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG0_SET_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG0_SET_HSTPULLDOWN_MASK       (0xCU)
#define USBPHY_DEBUG0_SET_HSTPULLDOWN_SHIFT      (2U)
/*! HSTPULLDOWN - Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG0_SET_HSTPULLDOWN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_SET_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_SET_ENHSTPULLDOWN_MASK     (0x30U)
#define USBPHY_DEBUG0_SET_ENHSTPULLDOWN_SHIFT    (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG0_SET_ENHSTPULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_SET_ENHSTPULLDOWN_MASK)
/*! @} */

/*! @name DEBUG0_CLR - Debug 0 */
/*! @{ */

#define USBPHY_DEBUG0_CLR_OTGIDPIOLOCK_MASK      (0x1U)
#define USBPHY_DEBUG0_CLR_OTGIDPIOLOCK_SHIFT     (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG0_CLR_OTGIDPIOLOCK(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG0_CLR_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG0_CLR_HSTPULLDOWN_MASK       (0xCU)
#define USBPHY_DEBUG0_CLR_HSTPULLDOWN_SHIFT      (2U)
/*! HSTPULLDOWN - Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG0_CLR_HSTPULLDOWN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_CLR_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_MASK     (0x30U)
#define USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_SHIFT    (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG0_CLR_ENHSTPULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_MASK)
/*! @} */

/*! @name DEBUG0_TOG - Debug 0 */
/*! @{ */

#define USBPHY_DEBUG0_TOG_OTGIDPIOLOCK_MASK      (0x1U)
#define USBPHY_DEBUG0_TOG_OTGIDPIOLOCK_SHIFT     (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG0_TOG_OTGIDPIOLOCK(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG0_TOG_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG0_TOG_HSTPULLDOWN_MASK       (0xCU)
#define USBPHY_DEBUG0_TOG_HSTPULLDOWN_SHIFT      (2U)
/*! HSTPULLDOWN - Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG0_TOG_HSTPULLDOWN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_TOG_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_MASK     (0x30U)
#define USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_SHIFT    (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG0_TOG_ENHSTPULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_MASK)
/*! @} */

/*! @name VERSION - Version */
/*! @{ */

#define USBPHY_VERSION_STEP_MASK                 (0xFFFFU)
#define USBPHY_VERSION_STEP_SHIFT                (0U)
/*! STEP - Step */
#define USBPHY_VERSION_STEP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_STEP_SHIFT)) & USBPHY_VERSION_STEP_MASK)

#define USBPHY_VERSION_MINOR_MASK                (0xFF0000U)
#define USBPHY_VERSION_MINOR_SHIFT               (16U)
/*! MINOR - Minor */
#define USBPHY_VERSION_MINOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MINOR_SHIFT)) & USBPHY_VERSION_MINOR_MASK)

#define USBPHY_VERSION_MAJOR_MASK                (0xFF000000U)
#define USBPHY_VERSION_MAJOR_SHIFT               (24U)
/*! MAJOR - Major */
#define USBPHY_VERSION_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MAJOR_SHIFT)) & USBPHY_VERSION_MAJOR_MASK)
/*! @} */

/*! @name IP - IP Block */
/*! @{ */

#define USBPHY_IP_POWER_CONTROL_SUSPEND_OPTION_MASK (0x1U)
#define USBPHY_IP_POWER_CONTROL_SUSPEND_OPTION_SHIFT (0U)
/*! POWER_CONTROL_SUSPEND_OPTION - Power Control Suspend Option */
#define USBPHY_IP_POWER_CONTROL_SUSPEND_OPTION(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_IP_POWER_CONTROL_SUSPEND_OPTION_SHIFT)) & USBPHY_IP_POWER_CONTROL_SUSPEND_OPTION_MASK)
/*! @} */

/*! @name IP_SET - IP Block */
/*! @{ */

#define USBPHY_IP_SET_POWER_CONTROL_SUSPEND_OPTION_MASK (0x1U)
#define USBPHY_IP_SET_POWER_CONTROL_SUSPEND_OPTION_SHIFT (0U)
/*! POWER_CONTROL_SUSPEND_OPTION - Power Control Suspend Option */
#define USBPHY_IP_SET_POWER_CONTROL_SUSPEND_OPTION(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_IP_SET_POWER_CONTROL_SUSPEND_OPTION_SHIFT)) & USBPHY_IP_SET_POWER_CONTROL_SUSPEND_OPTION_MASK)
/*! @} */

/*! @name IP_CLR - IP Block */
/*! @{ */

#define USBPHY_IP_CLR_POWER_CONTROL_SUSPEND_OPTION_MASK (0x1U)
#define USBPHY_IP_CLR_POWER_CONTROL_SUSPEND_OPTION_SHIFT (0U)
/*! POWER_CONTROL_SUSPEND_OPTION - Power Control Suspend Option */
#define USBPHY_IP_CLR_POWER_CONTROL_SUSPEND_OPTION(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_IP_CLR_POWER_CONTROL_SUSPEND_OPTION_SHIFT)) & USBPHY_IP_CLR_POWER_CONTROL_SUSPEND_OPTION_MASK)
/*! @} */

/*! @name IP_TOG - IP Block */
/*! @{ */

#define USBPHY_IP_TOG_POWER_CONTROL_SUSPEND_OPTION_MASK (0x1U)
#define USBPHY_IP_TOG_POWER_CONTROL_SUSPEND_OPTION_SHIFT (0U)
/*! POWER_CONTROL_SUSPEND_OPTION - Power Control Suspend Option */
#define USBPHY_IP_TOG_POWER_CONTROL_SUSPEND_OPTION(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_IP_TOG_POWER_CONTROL_SUSPEND_OPTION_SHIFT)) & USBPHY_IP_TOG_POWER_CONTROL_SUSPEND_OPTION_MASK)
/*! @} */

/*! @name PLL_SIC - PLL SIC */
/*! @{ */

#define USBPHY_PLL_SIC_MISC2_CONTROL0_MASK       (0x20U)
#define USBPHY_PLL_SIC_MISC2_CONTROL0_SHIFT      (5U)
/*! MISC2_CONTROL0 - Miscellaneous Control
 *  0b0..Power up PLL
 *  0b1..Power down PLL
 */
#define USBPHY_PLL_SIC_MISC2_CONTROL0(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_MISC2_CONTROL0_SHIFT)) & USBPHY_PLL_SIC_MISC2_CONTROL0_MASK)

#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS_MASK      (0x40U)
#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS_SHIFT     (6U)
/*! PLL_EN_USB_CLKS - PLL Multi-Phase Clock Outputs Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_PLL_POWER_MASK            (0x1000U)
#define USBPHY_PLL_SIC_PLL_POWER_SHIFT           (12U)
/*! PLL_POWER - USB PLL Powerup Control
 *  0b0..Power down
 *  0b1..Allow powerup
 */
#define USBPHY_PLL_SIC_PLL_POWER(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_PLL_ENABLE_MASK           (0x2000U)
#define USBPHY_PLL_SIC_PLL_ENABLE_SHIFT          (13U)
/*! PLL_ENABLE - PLL Output Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_PLL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_PLL_BYPASS_MASK           (0x10000U)
#define USBPHY_PLL_SIC_PLL_BYPASS_SHIFT          (16U)
/*! PLL_BYPASS - Bypass USB PLL
 *  0b0..480 MHz output clock
 *  0b1..Input reference clock
 */
#define USBPHY_PLL_SIC_PLL_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL_MASK      (0x80000U)
#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL_SHIFT     (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Power Control
 *  0b0..PLL_POWER internal state signal
 *  0b1..REFBIAS_PWD
 */
#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_REFBIAS_PWD_MASK          (0x100000U)
#define USBPHY_PLL_SIC_REFBIAS_PWD_SHIFT         (20U)
/*! REFBIAS_PWD - Power Down Reference Bias
 *  0b0..Enable
 *  0b1..Disable or power down
 */
#define USBPHY_PLL_SIC_REFBIAS_PWD(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_PLL_REG_ENABLE_MASK       (0x200000U)
#define USBPHY_PLL_SIC_PLL_REG_ENABLE_SHIFT      (21U)
/*! PLL_REG_ENABLE - Enable PLL Regulator
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_PLL_REG_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_PLL_DIV_SEL_MASK          (0x1C00000U)
#define USBPHY_PLL_SIC_PLL_DIV_SEL_SHIFT         (22U)
/*! PLL_DIV_SEL - PLL Divider Value Configuration
 *  0b000..Configure for a 32 MHz input clock (divide by 15)
 *  0b001..Configure for a 30 MHz input clock (divide by 16)
 *  0b010..Configure for a 24 MHz input clock (divide by 20)
 *  0b011..Reserved, not usable for USB operation (divide by 22)
 *  0b100..Configure for a 20 MHz input clock (divide by 24)
 *  0b101..Configure for a 19.2 MHz input clock (divide by 25)
 *  0b110..Configure for a 16 MHz input clock (divide by 30)
 *  0b111..Configure for a 12 MHz input clock (divide by 40)
 */
#define USBPHY_PLL_SIC_PLL_DIV_SEL(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_PLL_LOCK_MASK             (0x80000000U)
#define USBPHY_PLL_SIC_PLL_LOCK_SHIFT            (31U)
/*! PLL_LOCK - USB PLL Lock Status Indicator
 *  0b0..Not locked
 *  0b1..Locked
 */
#define USBPHY_PLL_SIC_PLL_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_SET - PLL SIC */
/*! @{ */

#define USBPHY_PLL_SIC_SET_MISC2_CONTROL0_MASK   (0x20U)
#define USBPHY_PLL_SIC_SET_MISC2_CONTROL0_SHIFT  (5U)
/*! MISC2_CONTROL0 - Miscellaneous Control */
#define USBPHY_PLL_SIC_SET_MISC2_CONTROL0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_MISC2_CONTROL0_SHIFT)) & USBPHY_PLL_SIC_SET_MISC2_CONTROL0_MASK)

#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL Multi-Phase Clock Outputs Enable */
#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_SET_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_SET_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - USB PLL Powerup Control */
#define USBPHY_PLL_SIC_SET_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_SET_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_SET_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - PLL Output Clock Enable */
#define USBPHY_PLL_SIC_SET_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_SET_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_SET_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - Bypass USB PLL */
#define USBPHY_PLL_SIC_SET_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Power Control */
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - Power Down Reference Bias */
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_SET_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - Enable PLL Regulator */
#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL Divider Value Configuration */
#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_SET_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_SET_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - USB PLL Lock Status Indicator */
#define USBPHY_PLL_SIC_SET_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_CLR - PLL SIC */
/*! @{ */

#define USBPHY_PLL_SIC_CLR_MISC2_CONTROL0_MASK   (0x20U)
#define USBPHY_PLL_SIC_CLR_MISC2_CONTROL0_SHIFT  (5U)
/*! MISC2_CONTROL0 - Miscellaneous Control */
#define USBPHY_PLL_SIC_CLR_MISC2_CONTROL0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_MISC2_CONTROL0_SHIFT)) & USBPHY_PLL_SIC_CLR_MISC2_CONTROL0_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL Multi-Phase Clock Outputs Enable */
#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_CLR_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - USB PLL Powerup Control */
#define USBPHY_PLL_SIC_CLR_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_CLR_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - PLL Output Clock Enable */
#define USBPHY_PLL_SIC_CLR_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_CLR_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - Bypass USB PLL */
#define USBPHY_PLL_SIC_CLR_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Power Control */
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - Power Down Reference Bias */
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_CLR_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - Enable PLL Regulator */
#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL Divider Value Configuration */
#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_CLR_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - USB PLL Lock Status Indicator */
#define USBPHY_PLL_SIC_CLR_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_TOG - PLL SIC */
/*! @{ */

#define USBPHY_PLL_SIC_TOG_MISC2_CONTROL0_MASK   (0x20U)
#define USBPHY_PLL_SIC_TOG_MISC2_CONTROL0_SHIFT  (5U)
/*! MISC2_CONTROL0 - Miscellaneous Control */
#define USBPHY_PLL_SIC_TOG_MISC2_CONTROL0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_MISC2_CONTROL0_SHIFT)) & USBPHY_PLL_SIC_TOG_MISC2_CONTROL0_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL Multi-Phase Clock Outputs Enable */
#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_TOG_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - USB PLL Powerup Control */
#define USBPHY_PLL_SIC_TOG_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_TOG_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - PLL Output Clock Enable */
#define USBPHY_PLL_SIC_TOG_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_TOG_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - Bypass USB PLL */
#define USBPHY_PLL_SIC_TOG_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Power Control */
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - Power Down Reference Bias */
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_TOG_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - Enable PLL Regulator */
#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL Divider Value Configuration */
#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_TOG_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - USB PLL Lock Status Indicator */
#define USBPHY_PLL_SIC_TOG_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_LOCK_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT - VBUS Detect */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS Comparator Threshold
 *  0b000..4.0 V
 *  0b001..4.1 V
 *  0b010..4.2 V
 *  0b011..4.3 V
 *  0b100..4.4 V
 *  0b101..4.5 V
 *  0b110..4.6 V
 *  0b111..4.7 V
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Local Override Enable
 *  0b0..Results of VBUS_VALID and session valid comparators for VBUS_VALID, AVALID, BVALID, and SESSEND
 *  0b1..Override values for VBUS_VALID, AVALID, BVALID, and SESSEND
 */
#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Selection
 *  0b0..VBUS_VALID comparator result
 *  0b1..VBUS_VALID_3V comparator result
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection
 *  0b00..VBUS_VALID comparator result
 *  0b01..Session valid comparator result
 *  0b10..Session valid comparator result
 *  0b11..
 */
#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override
 *  0b0..Use ID pin detector or external override
 *  0b1..Allow local override of ID pin detection status
 */
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override */
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_EXT_ID_OVERRIDE_EN_MASK (0x2000U)
#define USBPHY_USB1_VBUS_DETECT_EXT_ID_OVERRIDE_EN_SHIFT (13U)
/*! EXT_ID_OVERRIDE_EN - External ID Override Enable
 *  0b0..Internal detector or local override
 *  0b1..External ID signal value
 */
#define USBPHY_USB1_VBUS_DETECT_EXT_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_EXT_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_EXT_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_EXT_VBUS_OVERRIDE_EN_MASK (0x4000U)
#define USBPHY_USB1_VBUS_DETECT_EXT_VBUS_OVERRIDE_EN_SHIFT (14U)
/*! EXT_VBUS_OVERRIDE_EN - External VBUS Override Enable
 *  0b0..Internal detector or local override
 *  0b1..External VBUS_VALID value
 */
#define USBPHY_USB1_VBUS_DETECT_EXT_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_EXT_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_EXT_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_B_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_B_SHIFT (18U)
/*! VBUSVALID_TO_B - VBUS_VALID Comparator Selection
 *  0b0..VBUS_VALID comparator
 *  0b1..Session valid detector
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_B(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_B_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_B_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_MASK (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
/*! VBUSVALID_PWRUP_CMPS - VBUS_VALID Comparator Enable
 *  0b0xx..Disable or power down the VBUS_VALID_3V detector
 *  0b1xx..Enable the VBUS_VALID_3V detector
 *  0bx0x..Disable or power down the session valid detector
 *  0bx1x..Enable the session valid detector
 *  0bxx0..Disable or power down the VBUS_VALID comparator
 *  0bxx1..Enable the VBUS_VALID comparator
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_SET - VBUS Detect */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS Comparator Threshold */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Local Override Enable */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Selection */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override */
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override */
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_EXT_ID_OVERRIDE_EN_MASK (0x2000U)
#define USBPHY_USB1_VBUS_DETECT_SET_EXT_ID_OVERRIDE_EN_SHIFT (13U)
/*! EXT_ID_OVERRIDE_EN - External ID Override Enable */
#define USBPHY_USB1_VBUS_DETECT_SET_EXT_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_EXT_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_EXT_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_EXT_VBUS_OVERRIDE_EN_MASK (0x4000U)
#define USBPHY_USB1_VBUS_DETECT_SET_EXT_VBUS_OVERRIDE_EN_SHIFT (14U)
/*! EXT_VBUS_OVERRIDE_EN - External VBUS Override Enable */
#define USBPHY_USB1_VBUS_DETECT_SET_EXT_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_EXT_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_EXT_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_B_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_B_SHIFT (18U)
/*! VBUSVALID_TO_B - VBUS_VALID Comparator Selection */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_B(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_B_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_B_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_MASK (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
/*! VBUSVALID_PWRUP_CMPS - VBUS_VALID Comparator Enable */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor */
#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_CLR - VBUS Detect */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS Comparator Threshold */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Local Override Enable */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Selection */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override */
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override */
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_EXT_ID_OVERRIDE_EN_MASK (0x2000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_EXT_ID_OVERRIDE_EN_SHIFT (13U)
/*! EXT_ID_OVERRIDE_EN - External ID Override Enable */
#define USBPHY_USB1_VBUS_DETECT_CLR_EXT_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_EXT_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_EXT_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_EXT_VBUS_OVERRIDE_EN_MASK (0x4000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_EXT_VBUS_OVERRIDE_EN_SHIFT (14U)
/*! EXT_VBUS_OVERRIDE_EN - External VBUS Override Enable */
#define USBPHY_USB1_VBUS_DETECT_CLR_EXT_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_EXT_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_EXT_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_B_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_B_SHIFT (18U)
/*! VBUSVALID_TO_B - VBUS_VALID Comparator Selection */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_B(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_B_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_B_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_MASK (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
/*! VBUSVALID_PWRUP_CMPS - VBUS_VALID Comparator Enable */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor */
#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_TOG - VBUS Detect */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS Comparator Threshold */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Local Override Enable */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Selection */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override */
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override */
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_EXT_ID_OVERRIDE_EN_MASK (0x2000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_EXT_ID_OVERRIDE_EN_SHIFT (13U)
/*! EXT_ID_OVERRIDE_EN - External ID Override Enable */
#define USBPHY_USB1_VBUS_DETECT_TOG_EXT_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_EXT_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_EXT_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_EXT_VBUS_OVERRIDE_EN_MASK (0x4000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_EXT_VBUS_OVERRIDE_EN_SHIFT (14U)
/*! EXT_VBUS_OVERRIDE_EN - External VBUS Override Enable */
#define USBPHY_USB1_VBUS_DETECT_TOG_EXT_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_EXT_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_EXT_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_B_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_B_SHIFT (18U)
/*! VBUSVALID_TO_B - VBUS_VALID Comparator Selection */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_B(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_B_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_B_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_MASK (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
/*! VBUSVALID_PWRUP_CMPS - VBUS_VALID Comparator Enable */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor */
#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK)
/*! @} */

/*! @name USB1_VBUS_DET_STAT - VBUS Detect Status */
/*! @{ */

#define USBPHY_USB1_VBUS_DET_STAT_SESSEND_MASK   (0x1U)
#define USBPHY_USB1_VBUS_DET_STAT_SESSEND_SHIFT  (0U)
/*! SESSEND - Session End Indicator
 *  0b0..Above threshold
 *  0b1..Below threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_SESSEND(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SESSEND_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SESSEND_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_BVALID_MASK    (0x2U)
#define USBPHY_USB1_VBUS_DET_STAT_BVALID_SHIFT   (1U)
/*! BVALID - B-Device Session Valid Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_BVALID(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_BVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_BVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_AVALID_MASK    (0x4U)
#define USBPHY_USB1_VBUS_DET_STAT_AVALID_SHIFT   (2U)
/*! AVALID - A-Device Session Valid Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_AVALID(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_AVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_AVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_MASK (0x8U)
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_SHIFT (3U)
/*! VBUS_VALID - VBUS Voltage Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_MASK (0x10U)
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_SHIFT (4U)
/*! VBUS_VALID_3V - VBUS_VALID_3V Detector Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_EXT_ID_MASK    (0x20U)
#define USBPHY_USB1_VBUS_DET_STAT_EXT_ID_SHIFT   (5U)
/*! EXT_ID - OTG ID External Override Status */
#define USBPHY_USB1_VBUS_DET_STAT_EXT_ID(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_EXT_ID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_EXT_ID_MASK)
/*! @} */

/*! @name USB1_VBUS_DET_STAT_SET - VBUS Detect Status */
/*! @{ */

#define USBPHY_USB1_VBUS_DET_STAT_SET_SESSEND_MASK (0x1U)
#define USBPHY_USB1_VBUS_DET_STAT_SET_SESSEND_SHIFT (0U)
/*! SESSEND - Session End Indicator */
#define USBPHY_USB1_VBUS_DET_STAT_SET_SESSEND(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SET_SESSEND_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SET_SESSEND_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_SET_BVALID_MASK (0x2U)
#define USBPHY_USB1_VBUS_DET_STAT_SET_BVALID_SHIFT (1U)
/*! BVALID - B-Device Session Valid Status */
#define USBPHY_USB1_VBUS_DET_STAT_SET_BVALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SET_BVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SET_BVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_SET_AVALID_MASK (0x4U)
#define USBPHY_USB1_VBUS_DET_STAT_SET_AVALID_SHIFT (2U)
/*! AVALID - A-Device Session Valid Status */
#define USBPHY_USB1_VBUS_DET_STAT_SET_AVALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SET_AVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SET_AVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_MASK (0x8U)
#define USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_SHIFT (3U)
/*! VBUS_VALID - VBUS Voltage Status */
#define USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_3V_MASK (0x10U)
#define USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_3V_SHIFT (4U)
/*! VBUS_VALID_3V - VBUS_VALID_3V Detector Status */
#define USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_3V(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_3V_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SET_VBUS_VALID_3V_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_SET_EXT_ID_MASK (0x20U)
#define USBPHY_USB1_VBUS_DET_STAT_SET_EXT_ID_SHIFT (5U)
/*! EXT_ID - OTG ID External Override Status */
#define USBPHY_USB1_VBUS_DET_STAT_SET_EXT_ID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SET_EXT_ID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SET_EXT_ID_MASK)
/*! @} */

/*! @name USB1_VBUS_DET_STAT_CLR - VBUS Detect Status */
/*! @{ */

#define USBPHY_USB1_VBUS_DET_STAT_CLR_SESSEND_MASK (0x1U)
#define USBPHY_USB1_VBUS_DET_STAT_CLR_SESSEND_SHIFT (0U)
/*! SESSEND - Session End Indicator */
#define USBPHY_USB1_VBUS_DET_STAT_CLR_SESSEND(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_CLR_SESSEND_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_CLR_SESSEND_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_CLR_BVALID_MASK (0x2U)
#define USBPHY_USB1_VBUS_DET_STAT_CLR_BVALID_SHIFT (1U)
/*! BVALID - B-Device Session Valid Status */
#define USBPHY_USB1_VBUS_DET_STAT_CLR_BVALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_CLR_BVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_CLR_BVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_CLR_AVALID_MASK (0x4U)
#define USBPHY_USB1_VBUS_DET_STAT_CLR_AVALID_SHIFT (2U)
/*! AVALID - A-Device Session Valid Status */
#define USBPHY_USB1_VBUS_DET_STAT_CLR_AVALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_CLR_AVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_CLR_AVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_MASK (0x8U)
#define USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_SHIFT (3U)
/*! VBUS_VALID - VBUS Voltage Status */
#define USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_3V_MASK (0x10U)
#define USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_3V_SHIFT (4U)
/*! VBUS_VALID_3V - VBUS_VALID_3V Detector Status */
#define USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_3V(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_3V_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_CLR_VBUS_VALID_3V_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_CLR_EXT_ID_MASK (0x20U)
#define USBPHY_USB1_VBUS_DET_STAT_CLR_EXT_ID_SHIFT (5U)
/*! EXT_ID - OTG ID External Override Status */
#define USBPHY_USB1_VBUS_DET_STAT_CLR_EXT_ID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_CLR_EXT_ID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_CLR_EXT_ID_MASK)
/*! @} */

/*! @name USB1_VBUS_DET_STAT_TOG - VBUS Detect Status */
/*! @{ */

#define USBPHY_USB1_VBUS_DET_STAT_TOG_SESSEND_MASK (0x1U)
#define USBPHY_USB1_VBUS_DET_STAT_TOG_SESSEND_SHIFT (0U)
/*! SESSEND - Session End Indicator */
#define USBPHY_USB1_VBUS_DET_STAT_TOG_SESSEND(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_TOG_SESSEND_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_TOG_SESSEND_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_TOG_BVALID_MASK (0x2U)
#define USBPHY_USB1_VBUS_DET_STAT_TOG_BVALID_SHIFT (1U)
/*! BVALID - B-Device Session Valid Status */
#define USBPHY_USB1_VBUS_DET_STAT_TOG_BVALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_TOG_BVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_TOG_BVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_TOG_AVALID_MASK (0x4U)
#define USBPHY_USB1_VBUS_DET_STAT_TOG_AVALID_SHIFT (2U)
/*! AVALID - A-Device Session Valid Status */
#define USBPHY_USB1_VBUS_DET_STAT_TOG_AVALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_TOG_AVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_TOG_AVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_MASK (0x8U)
#define USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_SHIFT (3U)
/*! VBUS_VALID - VBUS Voltage Status */
#define USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_3V_MASK (0x10U)
#define USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_3V_SHIFT (4U)
/*! VBUS_VALID_3V - VBUS_VALID_3V Detector Status */
#define USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_3V(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_3V_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_TOG_VBUS_VALID_3V_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_TOG_EXT_ID_MASK (0x20U)
#define USBPHY_USB1_VBUS_DET_STAT_TOG_EXT_ID_SHIFT (5U)
/*! EXT_ID - OTG ID External Override Status */
#define USBPHY_USB1_VBUS_DET_STAT_TOG_EXT_ID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_TOG_EXT_ID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_TOG_EXT_ID_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT - Charger Detect */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_DETECT_SEC_MASK  (0x2U)
#define USBPHY_USB1_CHRG_DETECT_DETECT_SEC_SHIFT (1U)
/*! DETECT_SEC - Secondary Detection Function Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_CHRG_DETECT_DETECT_SEC(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_DETECT_SEC_SHIFT)) & USBPHY_USB1_CHRG_DETECT_DETECT_SEC_MASK)

#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP_MASK   (0x4U)
#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP_SHIFT  (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_VDM_SRC_ENABLE_MASK (0x10U)
#define USBPHY_USB1_CHRG_DETECT_VDM_SRC_ENABLE_SHIFT (4U)
/*! VDM_SRC_ENABLE - VDM_SRC Function Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_CHRG_DETECT_VDM_SRC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_VDM_SRC_ENABLE_SHIFT)) & USBPHY_USB1_CHRG_DETECT_VDM_SRC_ENABLE_MASK)

#define USBPHY_USB1_CHRG_DETECT_CHK_CONTACT_MASK (0x40000U)
#define USBPHY_USB1_CHRG_DETECT_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - BC Data Contact Detect Function Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_CHRG_DETECT_CHK_CONTACT(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CHK_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CHK_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DETECT_CHK_CHRG_B_MASK  (0x80000U)
#define USBPHY_USB1_CHRG_DETECT_CHK_CHRG_B_SHIFT (19U)
/*! CHK_CHRG_B - BC Charger Detection Function Enable
 *  0b0..Enable
 *  0b1..Disable
 */
#define USBPHY_USB1_CHRG_DETECT_CHK_CHRG_B(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CHK_CHRG_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CHK_CHRG_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_EN_B_MASK        (0x100000U)
#define USBPHY_USB1_CHRG_DETECT_EN_B_SHIFT       (20U)
/*! EN_B - Selection of BC v1.2 Function Enable
 *  0b0..Enable
 *  0b1..Disable
 */
#define USBPHY_USB1_CHRG_DETECT_EN_B(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_EN_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_EN_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_DCDSEL_MASK      (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_DCDSEL_SHIFT     (31U)
/*! DCDSEL - DCD Selection
 *  0b0..Fields in USB1_CHRG_DETECT
 *  0b1..Fields and state machines in the USBHSDCD module
 */
#define USBPHY_USB1_CHRG_DETECT_DCDSEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_SET - Charger Detect */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_SET_DETECT_SEC_MASK (0x2U)
#define USBPHY_USB1_CHRG_DETECT_SET_DETECT_SEC_SHIFT (1U)
/*! DETECT_SEC - Secondary Detection Function Enable */
#define USBPHY_USB1_CHRG_DETECT_SET_DETECT_SEC(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_DETECT_SEC_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_DETECT_SEC_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control */
#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_VDM_SRC_ENABLE_MASK (0x10U)
#define USBPHY_USB1_CHRG_DETECT_SET_VDM_SRC_ENABLE_SHIFT (4U)
/*! VDM_SRC_ENABLE - VDM_SRC Function Enable */
#define USBPHY_USB1_CHRG_DETECT_SET_VDM_SRC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_VDM_SRC_ENABLE_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_VDM_SRC_ENABLE_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_CHK_CONTACT_MASK (0x40000U)
#define USBPHY_USB1_CHRG_DETECT_SET_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - BC Data Contact Detect Function Enable */
#define USBPHY_USB1_CHRG_DETECT_SET_CHK_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_CHK_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_CHK_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_CHK_CHRG_B_MASK (0x80000U)
#define USBPHY_USB1_CHRG_DETECT_SET_CHK_CHRG_B_SHIFT (19U)
/*! CHK_CHRG_B - BC Charger Detection Function Enable */
#define USBPHY_USB1_CHRG_DETECT_SET_CHK_CHRG_B(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_CHK_CHRG_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_CHK_CHRG_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_EN_B_MASK    (0x100000U)
#define USBPHY_USB1_CHRG_DETECT_SET_EN_B_SHIFT   (20U)
/*! EN_B - Selection of BC v1.2 Function Enable */
#define USBPHY_USB1_CHRG_DETECT_SET_EN_B(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_EN_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_EN_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_MASK  (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_SHIFT (31U)
/*! DCDSEL - DCD Selection */
#define USBPHY_USB1_CHRG_DETECT_SET_DCDSEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_CLR - Charger Detect */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_CLR_DETECT_SEC_MASK (0x2U)
#define USBPHY_USB1_CHRG_DETECT_CLR_DETECT_SEC_SHIFT (1U)
/*! DETECT_SEC - Secondary Detection Function Enable */
#define USBPHY_USB1_CHRG_DETECT_CLR_DETECT_SEC(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_DETECT_SEC_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_DETECT_SEC_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control */
#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_VDM_SRC_ENABLE_MASK (0x10U)
#define USBPHY_USB1_CHRG_DETECT_CLR_VDM_SRC_ENABLE_SHIFT (4U)
/*! VDM_SRC_ENABLE - VDM_SRC Function Enable */
#define USBPHY_USB1_CHRG_DETECT_CLR_VDM_SRC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_VDM_SRC_ENABLE_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_VDM_SRC_ENABLE_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_CHK_CONTACT_MASK (0x40000U)
#define USBPHY_USB1_CHRG_DETECT_CLR_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - BC Data Contact Detect Function Enable */
#define USBPHY_USB1_CHRG_DETECT_CLR_CHK_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_CHK_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_CHK_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_CHK_CHRG_B_MASK (0x80000U)
#define USBPHY_USB1_CHRG_DETECT_CLR_CHK_CHRG_B_SHIFT (19U)
/*! CHK_CHRG_B - BC Charger Detection Function Enable */
#define USBPHY_USB1_CHRG_DETECT_CLR_CHK_CHRG_B(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_CHK_CHRG_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_CHK_CHRG_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_EN_B_MASK    (0x100000U)
#define USBPHY_USB1_CHRG_DETECT_CLR_EN_B_SHIFT   (20U)
/*! EN_B - Selection of BC v1.2 Function Enable */
#define USBPHY_USB1_CHRG_DETECT_CLR_EN_B(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_EN_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_EN_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_MASK  (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_SHIFT (31U)
/*! DCDSEL - DCD Selection */
#define USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_TOG - Charger Detect */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_TOG_DETECT_SEC_MASK (0x2U)
#define USBPHY_USB1_CHRG_DETECT_TOG_DETECT_SEC_SHIFT (1U)
/*! DETECT_SEC - Secondary Detection Function Enable */
#define USBPHY_USB1_CHRG_DETECT_TOG_DETECT_SEC(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_DETECT_SEC_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_DETECT_SEC_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control */
#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_VDM_SRC_ENABLE_MASK (0x10U)
#define USBPHY_USB1_CHRG_DETECT_TOG_VDM_SRC_ENABLE_SHIFT (4U)
/*! VDM_SRC_ENABLE - VDM_SRC Function Enable */
#define USBPHY_USB1_CHRG_DETECT_TOG_VDM_SRC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_VDM_SRC_ENABLE_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_VDM_SRC_ENABLE_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_CHK_CONTACT_MASK (0x40000U)
#define USBPHY_USB1_CHRG_DETECT_TOG_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - BC Data Contact Detect Function Enable */
#define USBPHY_USB1_CHRG_DETECT_TOG_CHK_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_CHK_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_CHK_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_CHK_CHRG_B_MASK (0x80000U)
#define USBPHY_USB1_CHRG_DETECT_TOG_CHK_CHRG_B_SHIFT (19U)
/*! CHK_CHRG_B - BC Charger Detection Function Enable */
#define USBPHY_USB1_CHRG_DETECT_TOG_CHK_CHRG_B(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_CHK_CHRG_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_CHK_CHRG_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_EN_B_MASK    (0x100000U)
#define USBPHY_USB1_CHRG_DETECT_TOG_EN_B_SHIFT   (20U)
/*! EN_B - Selection of BC v1.2 Function Enable */
#define USBPHY_USB1_CHRG_DETECT_TOG_EN_B(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_EN_B_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_EN_B_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_MASK  (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_SHIFT (31U)
/*! DCDSEL - DCD Selection */
#define USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DET_STAT - Charger Detect Status */
/*! @{ */

#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_MASK (0x1U)
#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_SHIFT (0U)
/*! PLUG_CONTACT - Battery Charging Data Contact Detection Phase Output
 *  0b0..Not detected
 *  0b1..Detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_MASK (0x2U)
#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_SHIFT (1U)
/*! CHRG_DETECTED - Battery Charging Primary Detection Phase Output
 *  0b0..SDP detected
 *  0b1..Charging port detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_DM_STATE_MASK  (0x4U)
#define USBPHY_USB1_CHRG_DET_STAT_DM_STATE_SHIFT (2U)
/*! DM_STATE - DM Voltage
 *  0b0..USB_DM pin voltage is <= 0.8 V
 *  0b1..USB_DM pin voltage is >= 2.0 V
 */
#define USBPHY_USB1_CHRG_DET_STAT_DM_STATE(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_DM_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_DM_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE_MASK  (0x8U)
#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE_SHIFT (3U)
/*! DP_STATE - DP Voltage
 *  0b0..USB_DP pin voltage is <= 0.8 V
 *  0b1..USB_DP pin voltage is >= 2.0 V
 */
#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_DP_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_DP_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_MASK (0x10U)
#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_SHIFT (4U)
/*! SECDET_DCP - Battery Charging Secondary Detection Phase Output
 *  0b0..CDP detected
 *  0b1..DCP detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_MASK)
/*! @} */

/*! @name USB1_CHRG_DET_STAT_SET - Charger Detect Status */
/*! @{ */

#define USBPHY_USB1_CHRG_DET_STAT_SET_PLUG_CONTACT_MASK (0x1U)
#define USBPHY_USB1_CHRG_DET_STAT_SET_PLUG_CONTACT_SHIFT (0U)
/*! PLUG_CONTACT - Battery Charging Data Contact Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_SET_PLUG_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SET_PLUG_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SET_PLUG_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_SET_CHRG_DETECTED_MASK (0x2U)
#define USBPHY_USB1_CHRG_DET_STAT_SET_CHRG_DETECTED_SHIFT (1U)
/*! CHRG_DETECTED - Battery Charging Primary Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_SET_CHRG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SET_CHRG_DETECTED_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SET_CHRG_DETECTED_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_SET_DM_STATE_MASK (0x4U)
#define USBPHY_USB1_CHRG_DET_STAT_SET_DM_STATE_SHIFT (2U)
/*! DM_STATE - DM Voltage */
#define USBPHY_USB1_CHRG_DET_STAT_SET_DM_STATE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SET_DM_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SET_DM_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_SET_DP_STATE_MASK (0x8U)
#define USBPHY_USB1_CHRG_DET_STAT_SET_DP_STATE_SHIFT (3U)
/*! DP_STATE - DP Voltage */
#define USBPHY_USB1_CHRG_DET_STAT_SET_DP_STATE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SET_DP_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SET_DP_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_SET_SECDET_DCP_MASK (0x10U)
#define USBPHY_USB1_CHRG_DET_STAT_SET_SECDET_DCP_SHIFT (4U)
/*! SECDET_DCP - Battery Charging Secondary Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_SET_SECDET_DCP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SET_SECDET_DCP_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SET_SECDET_DCP_MASK)
/*! @} */

/*! @name USB1_CHRG_DET_STAT_CLR - Charger Detect Status */
/*! @{ */

#define USBPHY_USB1_CHRG_DET_STAT_CLR_PLUG_CONTACT_MASK (0x1U)
#define USBPHY_USB1_CHRG_DET_STAT_CLR_PLUG_CONTACT_SHIFT (0U)
/*! PLUG_CONTACT - Battery Charging Data Contact Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_CLR_PLUG_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CLR_PLUG_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CLR_PLUG_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_CLR_CHRG_DETECTED_MASK (0x2U)
#define USBPHY_USB1_CHRG_DET_STAT_CLR_CHRG_DETECTED_SHIFT (1U)
/*! CHRG_DETECTED - Battery Charging Primary Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_CLR_CHRG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CLR_CHRG_DETECTED_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CLR_CHRG_DETECTED_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_CLR_DM_STATE_MASK (0x4U)
#define USBPHY_USB1_CHRG_DET_STAT_CLR_DM_STATE_SHIFT (2U)
/*! DM_STATE - DM Voltage */
#define USBPHY_USB1_CHRG_DET_STAT_CLR_DM_STATE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CLR_DM_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CLR_DM_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_CLR_DP_STATE_MASK (0x8U)
#define USBPHY_USB1_CHRG_DET_STAT_CLR_DP_STATE_SHIFT (3U)
/*! DP_STATE - DP Voltage */
#define USBPHY_USB1_CHRG_DET_STAT_CLR_DP_STATE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CLR_DP_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CLR_DP_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_CLR_SECDET_DCP_MASK (0x10U)
#define USBPHY_USB1_CHRG_DET_STAT_CLR_SECDET_DCP_SHIFT (4U)
/*! SECDET_DCP - Battery Charging Secondary Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_CLR_SECDET_DCP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CLR_SECDET_DCP_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CLR_SECDET_DCP_MASK)
/*! @} */

/*! @name USB1_CHRG_DET_STAT_TOG - Charger Detect Status */
/*! @{ */

#define USBPHY_USB1_CHRG_DET_STAT_TOG_PLUG_CONTACT_MASK (0x1U)
#define USBPHY_USB1_CHRG_DET_STAT_TOG_PLUG_CONTACT_SHIFT (0U)
/*! PLUG_CONTACT - Battery Charging Data Contact Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_TOG_PLUG_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_TOG_PLUG_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_TOG_PLUG_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_TOG_CHRG_DETECTED_MASK (0x2U)
#define USBPHY_USB1_CHRG_DET_STAT_TOG_CHRG_DETECTED_SHIFT (1U)
/*! CHRG_DETECTED - Battery Charging Primary Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_TOG_CHRG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_TOG_CHRG_DETECTED_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_TOG_CHRG_DETECTED_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_TOG_DM_STATE_MASK (0x4U)
#define USBPHY_USB1_CHRG_DET_STAT_TOG_DM_STATE_SHIFT (2U)
/*! DM_STATE - DM Voltage */
#define USBPHY_USB1_CHRG_DET_STAT_TOG_DM_STATE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_TOG_DM_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_TOG_DM_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_TOG_DP_STATE_MASK (0x8U)
#define USBPHY_USB1_CHRG_DET_STAT_TOG_DP_STATE_SHIFT (3U)
/*! DP_STATE - DP Voltage */
#define USBPHY_USB1_CHRG_DET_STAT_TOG_DP_STATE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_TOG_DP_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_TOG_DP_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_TOG_SECDET_DCP_MASK (0x10U)
#define USBPHY_USB1_CHRG_DET_STAT_TOG_SECDET_DCP_SHIFT (4U)
/*! SECDET_DCP - Battery Charging Secondary Detection Phase Output */
#define USBPHY_USB1_CHRG_DET_STAT_TOG_SECDET_DCP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_TOG_SECDET_DCP_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_TOG_SECDET_DCP_MASK)
/*! @} */

/*! @name ANACTRL - Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_LVI_EN_MASK               (0x2U)
#define USBPHY_ANACTRL_LVI_EN_SHIFT              (1U)
/*! LVI_EN - Internal Low Voltage Detector Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_ANACTRL_LVI_EN(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_LVI_EN_SHIFT)) & USBPHY_ANACTRL_LVI_EN_MASK)

#define USBPHY_ANACTRL_PFD_CLK_SEL_MASK          (0xCU)
#define USBPHY_ANACTRL_PFD_CLK_SEL_SHIFT         (2U)
/*! PFD_CLK_SEL - PFD Clock Selection
 *  0b00..USB1PFDCLK = USB PLL reference clock
 *  0b01..USB1PFDCLK = pfd_clk / 4
 *  0b10..USB1PFDCLK frequency = pfd_clk / 2
 *  0b11..USB1PFDCLK = pfd_clk
 */
#define USBPHY_ANACTRL_PFD_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_PFD_CLK_SEL_SHIFT)) & USBPHY_ANACTRL_PFD_CLK_SEL_MASK)

#define USBPHY_ANACTRL_DEV_PULLDOWN_MASK         (0x400U)
#define USBPHY_ANACTRL_DEV_PULLDOWN_SHIFT        (10U)
/*! DEV_PULLDOWN - Device Pulldown Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_ANACTRL_DEV_PULLDOWN(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_SET - Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_SET_LVI_EN_MASK           (0x2U)
#define USBPHY_ANACTRL_SET_LVI_EN_SHIFT          (1U)
/*! LVI_EN - Internal Low Voltage Detector Enable */
#define USBPHY_ANACTRL_SET_LVI_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_SET_LVI_EN_SHIFT)) & USBPHY_ANACTRL_SET_LVI_EN_MASK)

#define USBPHY_ANACTRL_SET_PFD_CLK_SEL_MASK      (0xCU)
#define USBPHY_ANACTRL_SET_PFD_CLK_SEL_SHIFT     (2U)
/*! PFD_CLK_SEL - PFD Clock Selection */
#define USBPHY_ANACTRL_SET_PFD_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_SET_PFD_CLK_SEL_SHIFT)) & USBPHY_ANACTRL_SET_PFD_CLK_SEL_MASK)

#define USBPHY_ANACTRL_SET_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_SET_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pulldown Enable */
#define USBPHY_ANACTRL_SET_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_SET_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_SET_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_CLR - Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_CLR_LVI_EN_MASK           (0x2U)
#define USBPHY_ANACTRL_CLR_LVI_EN_SHIFT          (1U)
/*! LVI_EN - Internal Low Voltage Detector Enable */
#define USBPHY_ANACTRL_CLR_LVI_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_CLR_LVI_EN_SHIFT)) & USBPHY_ANACTRL_CLR_LVI_EN_MASK)

#define USBPHY_ANACTRL_CLR_PFD_CLK_SEL_MASK      (0xCU)
#define USBPHY_ANACTRL_CLR_PFD_CLK_SEL_SHIFT     (2U)
/*! PFD_CLK_SEL - PFD Clock Selection */
#define USBPHY_ANACTRL_CLR_PFD_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_CLR_PFD_CLK_SEL_SHIFT)) & USBPHY_ANACTRL_CLR_PFD_CLK_SEL_MASK)

#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pulldown Enable */
#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_CLR_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_CLR_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_TOG - Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_TOG_LVI_EN_MASK           (0x2U)
#define USBPHY_ANACTRL_TOG_LVI_EN_SHIFT          (1U)
/*! LVI_EN - Internal Low Voltage Detector Enable */
#define USBPHY_ANACTRL_TOG_LVI_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_TOG_LVI_EN_SHIFT)) & USBPHY_ANACTRL_TOG_LVI_EN_MASK)

#define USBPHY_ANACTRL_TOG_PFD_CLK_SEL_MASK      (0xCU)
#define USBPHY_ANACTRL_TOG_PFD_CLK_SEL_SHIFT     (2U)
/*! PFD_CLK_SEL - PFD Clock Selection */
#define USBPHY_ANACTRL_TOG_PFD_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_TOG_PFD_CLK_SEL_SHIFT)) & USBPHY_ANACTRL_TOG_PFD_CLK_SEL_MASK)

#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pulldown Enable */
#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_TOG_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_TOG_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN - Trim */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value
 *  0b0..TRIM_OVERRIDE_EN
 *  0b1..PLL_SIC
 */
#define USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - Override Enable for HS TX Output Current Trim
 *  0b0..TRIM_OVERRIDE_EN
 *  0b1..TX
 */
#define USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - Override Enable for USB_DP Series Termination Trim
 *  0b0..TRIM_OVERRIDE_EN
 *  0b1..TX
 */
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - Override Enable for USB_DM Series Termination Trim
 *  0b0..TRIM_OVERRIDE_EN
 *  0b1..TX
 */
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY
 *  0b0000..Maximum current, approximately 19% above nominal
 *  0b0111..Nominal
 *  0b1111..Minimum current, approximately 19% below nominal
 */
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - DM Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_SET - Trim */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value */
#define USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - Override Enable for HS TX Output Current Trim */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - Override Enable for USB_DP Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - Override Enable for USB_DM Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - DM Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_CLR - Trim */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - Override Enable for HS TX Output Current Trim */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - Override Enable for USB_DP Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - Override Enable for USB_DM Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - DM Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_TOG - Trim */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - Override Enable for HS TX Output Current Trim */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - Override Enable for USB_DP Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - Override Enable for USB_DM Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - DM Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name PFDA - PFD A */
/*! @{ */

#define USBPHY_PFDA_PFD0_CLKGATE_MASK            (0x1U)
#define USBPHY_PFDA_PFD0_CLKGATE_SHIFT           (0U)
/*! PFD0_CLKGATE - PFD0 Clock Gate
 *  0b0..Enable
 *  0b1..Disable
 */
#define USBPHY_PFDA_PFD0_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_PFD0_CLKGATE_SHIFT)) & USBPHY_PFDA_PFD0_CLKGATE_MASK)

#define USBPHY_PFDA_PFD0_FRAC_MASK               (0x7EU)
#define USBPHY_PFDA_PFD0_FRAC_SHIFT              (1U)
/*! PFD0_FRAC - PFD0 Fractional Divider */
#define USBPHY_PFDA_PFD0_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_PFD0_FRAC_SHIFT)) & USBPHY_PFDA_PFD0_FRAC_MASK)

#define USBPHY_PFDA_PFD0_STABLE_MASK             (0x80U)
#define USBPHY_PFDA_PFD0_STABLE_SHIFT            (7U)
/*! PFD0_STABLE - PFD0 Stable Signal
 *  0b0..Not stable
 *  0b1..Stable
 */
#define USBPHY_PFDA_PFD0_STABLE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_PFD0_STABLE_SHIFT)) & USBPHY_PFDA_PFD0_STABLE_MASK)
/*! @} */

/*! @name PFDA_SET - PFD A */
/*! @{ */

#define USBPHY_PFDA_SET_PFD0_CLKGATE_MASK        (0x1U)
#define USBPHY_PFDA_SET_PFD0_CLKGATE_SHIFT       (0U)
/*! PFD0_CLKGATE - PFD0 Clock Gate */
#define USBPHY_PFDA_SET_PFD0_CLKGATE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_SET_PFD0_CLKGATE_SHIFT)) & USBPHY_PFDA_SET_PFD0_CLKGATE_MASK)

#define USBPHY_PFDA_SET_PFD0_FRAC_MASK           (0x7EU)
#define USBPHY_PFDA_SET_PFD0_FRAC_SHIFT          (1U)
/*! PFD0_FRAC - PFD0 Fractional Divider */
#define USBPHY_PFDA_SET_PFD0_FRAC(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_SET_PFD0_FRAC_SHIFT)) & USBPHY_PFDA_SET_PFD0_FRAC_MASK)

#define USBPHY_PFDA_SET_PFD0_STABLE_MASK         (0x80U)
#define USBPHY_PFDA_SET_PFD0_STABLE_SHIFT        (7U)
/*! PFD0_STABLE - PFD0 Stable Signal */
#define USBPHY_PFDA_SET_PFD0_STABLE(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_SET_PFD0_STABLE_SHIFT)) & USBPHY_PFDA_SET_PFD0_STABLE_MASK)
/*! @} */

/*! @name PFDA_CLR - PFD A */
/*! @{ */

#define USBPHY_PFDA_CLR_PFD0_CLKGATE_MASK        (0x1U)
#define USBPHY_PFDA_CLR_PFD0_CLKGATE_SHIFT       (0U)
/*! PFD0_CLKGATE - PFD0 Clock Gate */
#define USBPHY_PFDA_CLR_PFD0_CLKGATE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_CLR_PFD0_CLKGATE_SHIFT)) & USBPHY_PFDA_CLR_PFD0_CLKGATE_MASK)

#define USBPHY_PFDA_CLR_PFD0_FRAC_MASK           (0x7EU)
#define USBPHY_PFDA_CLR_PFD0_FRAC_SHIFT          (1U)
/*! PFD0_FRAC - PFD0 Fractional Divider */
#define USBPHY_PFDA_CLR_PFD0_FRAC(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_CLR_PFD0_FRAC_SHIFT)) & USBPHY_PFDA_CLR_PFD0_FRAC_MASK)

#define USBPHY_PFDA_CLR_PFD0_STABLE_MASK         (0x80U)
#define USBPHY_PFDA_CLR_PFD0_STABLE_SHIFT        (7U)
/*! PFD0_STABLE - PFD0 Stable Signal */
#define USBPHY_PFDA_CLR_PFD0_STABLE(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_CLR_PFD0_STABLE_SHIFT)) & USBPHY_PFDA_CLR_PFD0_STABLE_MASK)
/*! @} */

/*! @name PFDA_TOG - PFD A */
/*! @{ */

#define USBPHY_PFDA_TOG_PFD0_CLKGATE_MASK        (0x1U)
#define USBPHY_PFDA_TOG_PFD0_CLKGATE_SHIFT       (0U)
/*! PFD0_CLKGATE - PFD0 Clock Gate */
#define USBPHY_PFDA_TOG_PFD0_CLKGATE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_TOG_PFD0_CLKGATE_SHIFT)) & USBPHY_PFDA_TOG_PFD0_CLKGATE_MASK)

#define USBPHY_PFDA_TOG_PFD0_FRAC_MASK           (0x7EU)
#define USBPHY_PFDA_TOG_PFD0_FRAC_SHIFT          (1U)
/*! PFD0_FRAC - PFD0 Fractional Divider */
#define USBPHY_PFDA_TOG_PFD0_FRAC(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_TOG_PFD0_FRAC_SHIFT)) & USBPHY_PFDA_TOG_PFD0_FRAC_MASK)

#define USBPHY_PFDA_TOG_PFD0_STABLE_MASK         (0x80U)
#define USBPHY_PFDA_TOG_PFD0_STABLE_SHIFT        (7U)
/*! PFD0_STABLE - PFD0 Stable Signal */
#define USBPHY_PFDA_TOG_PFD0_STABLE(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PFDA_TOG_PFD0_STABLE_SHIFT)) & USBPHY_PFDA_TOG_PFD0_STABLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBPHY_Register_Masks */


/*!
 * @}
 */ /* end of group USBPHY_Peripheral_Access_Layer */


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


#endif  /* PERI_USBPHY_H_ */

