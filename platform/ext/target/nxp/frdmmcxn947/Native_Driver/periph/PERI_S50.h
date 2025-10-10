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
**         CMSIS Peripheral Access Layer for S50
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
 * @file PERI_S50.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for S50
 *
 * CMSIS Peripheral Access Layer for S50
 */

#if !defined(PERI_S50_H_)
#define PERI_S50_H_                              /**< Symbol preventing repeated inclusion */

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
   -- S50 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S50_Peripheral_Access_Layer S50 Peripheral Access Layer
 * @{
 */

/** S50 - Register Layout Typedef */
typedef struct {
  __I  uint32_t ELS_STATUS;                        /**< Status Register, offset: 0x0 */
  __IO uint32_t ELS_CTRL;                          /**< Control Register, offset: 0x4 */
  __IO uint32_t ELS_CMDCFG0;                       /**< Command Configuration, offset: 0x8 */
  __IO uint32_t ELS_CFG;                           /**< Configuration Register, offset: 0xC */
  __IO uint32_t ELS_KIDX0;                         /**< Keystore Index 0, offset: 0x10 */
  __IO uint32_t ELS_KIDX1;                         /**< Keystore Index 1, offset: 0x14 */
  __IO uint32_t ELS_KPROPIN;                       /**< Key Properties Request, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ELS_DMA_SRC0;                      /**< DMA Source 0, offset: 0x20 */
  __IO uint32_t ELS_DMA_SRC0_LEN;                  /**< DMA Source 0 Length, offset: 0x24 */
  __IO uint32_t ELS_DMA_SRC1;                      /**< DMA Source 1, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t ELS_DMA_SRC2;                      /**< DMA Source 2, offset: 0x30 */
  __IO uint32_t ELS_DMA_SRC2_LEN;                  /**< DMA Source 2 Length, offset: 0x34 */
  __IO uint32_t ELS_DMA_RES0;                      /**< DMA Result 0, offset: 0x38 */
  __IO uint32_t ELS_DMA_RES0_LEN;                  /**< DMA Result 0 Length, offset: 0x3C */
  __IO uint32_t ELS_INT_ENABLE;                    /**< Interrupt Enable, offset: 0x40 */
  __O  uint32_t ELS_INT_STATUS_CLR;                /**< Interrupt Status Clear, offset: 0x44 */
  __O  uint32_t ELS_INT_STATUS_SET;                /**< Interrupt Status Set, offset: 0x48 */
  __I  uint32_t ELS_ERR_STATUS;                    /**< Error Status, offset: 0x4C */
  __O  uint32_t ELS_ERR_STATUS_CLR;                /**< Error Status Clear, offset: 0x50 */
  __I  uint32_t ELS_VERSION;                       /**< Version Register, offset: 0x54 */
       uint8_t RESERVED_2[4];
  __I  uint32_t ELS_PRNG_DATOUT;                   /**< PRNG SW Read Out, offset: 0x5C */
  __IO uint32_t ELS_CMDCRC_CTRL;                   /**< CRC Configuration, offset: 0x60 */
  __I  uint32_t ELS_CMDCRC;                        /**< Command CRC Value, offset: 0x64 */
  __IO uint32_t ELS_SESSION_ID;                    /**< Session ID, offset: 0x68 */
       uint8_t RESERVED_3[4];
  __I  uint32_t ELS_DMA_FIN_ADDR;                  /**< Final DMA Address, offset: 0x70 */
  __IO uint32_t ELS_MASTER_ID;                     /**< Master ID, offset: 0x74 */
  __IO uint32_t ELS_KIDX2;                         /**< Keystore Index 2, offset: 0x78 */
       uint8_t RESERVED_4[212];
  __I  uint32_t ELS_KS0;                           /**< Status Register, offset: 0x150 */
  __I  uint32_t ELS_KS1;                           /**< Status Register, offset: 0x154 */
  __I  uint32_t ELS_KS2;                           /**< Status Register, offset: 0x158 */
  __I  uint32_t ELS_KS3;                           /**< Status Register, offset: 0x15C */
  __I  uint32_t ELS_KS4;                           /**< Status Register, offset: 0x160 */
  __I  uint32_t ELS_KS5;                           /**< Status Register, offset: 0x164 */
  __I  uint32_t ELS_KS6;                           /**< Status Register, offset: 0x168 */
  __I  uint32_t ELS_KS7;                           /**< Status Register, offset: 0x16C */
  __I  uint32_t ELS_KS8;                           /**< Status Register, offset: 0x170 */
  __I  uint32_t ELS_KS9;                           /**< Status Register, offset: 0x174 */
  __I  uint32_t ELS_KS10;                          /**< Status Register, offset: 0x178 */
  __I  uint32_t ELS_KS11;                          /**< Status Register, offset: 0x17C */
  __I  uint32_t ELS_KS12;                          /**< Status Register, offset: 0x180 */
  __I  uint32_t ELS_KS13;                          /**< Status Register, offset: 0x184 */
  __I  uint32_t ELS_KS14;                          /**< Status Register, offset: 0x188 */
  __I  uint32_t ELS_KS15;                          /**< Status Register, offset: 0x18C */
  __I  uint32_t ELS_KS16;                          /**< Status Register, offset: 0x190 */
  __I  uint32_t ELS_KS17;                          /**< Status Register, offset: 0x194 */
  __I  uint32_t ELS_KS18;                          /**< Status Register, offset: 0x198 */
  __I  uint32_t ELS_KS19;                          /**< Status Register, offset: 0x19C */
} S50_Type;

/* ----------------------------------------------------------------------------
   -- S50 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S50_Register_Masks S50 Register Masks
 * @{
 */

/*! @name ELS_STATUS - Status Register */
/*! @{ */

#define S50_ELS_STATUS_ELS_BUSY_MASK             (0x1U)
#define S50_ELS_STATUS_ELS_BUSY_SHIFT            (0U)
/*! ELS_BUSY
 *  0b0..Crypto sequence not executing
 *  0b1..Crypto sequence executing
 */
#define S50_ELS_STATUS_ELS_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ELS_BUSY_SHIFT)) & S50_ELS_STATUS_ELS_BUSY_MASK)

#define S50_ELS_STATUS_ELS_IRQ_MASK              (0x2U)
#define S50_ELS_STATUS_ELS_IRQ_SHIFT             (1U)
/*! ELS_IRQ
 *  0b0..No active interrupt
 *  0b1..Active interrupt
 */
#define S50_ELS_STATUS_ELS_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ELS_IRQ_SHIFT)) & S50_ELS_STATUS_ELS_IRQ_MASK)

#define S50_ELS_STATUS_ELS_ERR_MASK              (0x4U)
#define S50_ELS_STATUS_ELS_ERR_SHIFT             (2U)
/*! ELS_ERR
 *  0b0..Internal error not detected
 *  0b1..Internal error detected
 */
#define S50_ELS_STATUS_ELS_ERR(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ELS_ERR_SHIFT)) & S50_ELS_STATUS_ELS_ERR_MASK)

#define S50_ELS_STATUS_PRNG_RDY_MASK             (0x8U)
#define S50_ELS_STATUS_PRNG_RDY_SHIFT            (3U)
/*! PRNG_RDY
 *  0b0..Internal PRNG not ready
 *  0b1..Internal PRNG ready
 */
#define S50_ELS_STATUS_PRNG_RDY(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_PRNG_RDY_SHIFT)) & S50_ELS_STATUS_PRNG_RDY_MASK)

#define S50_ELS_STATUS_ECDSA_VFY_STATUS_MASK     (0x30U)
#define S50_ELS_STATUS_ECDSA_VFY_STATUS_SHIFT    (4U)
/*! ECDSA_VFY_STATUS
 *  0b00..No verify run
 *  0b01..Signature verify failed
 *  0b10..Signature verify passed
 *  0b11..Invalid, Error
 */
#define S50_ELS_STATUS_ECDSA_VFY_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ECDSA_VFY_STATUS_SHIFT)) & S50_ELS_STATUS_ECDSA_VFY_STATUS_MASK)

#define S50_ELS_STATUS_PPROT_MASK                (0xC0U)
#define S50_ELS_STATUS_PPROT_SHIFT               (6U)
/*! PPROT
 *  0b00..Secure, non-privileged
 *  0b01..Secure, privileged
 *  0b10..Non-secure, non-privileged
 *  0b11..Non-secure, privileged
 */
#define S50_ELS_STATUS_PPROT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_PPROT_SHIFT)) & S50_ELS_STATUS_PPROT_MASK)

#define S50_ELS_STATUS_DRBG_ENT_LVL_MASK         (0x300U)
#define S50_ELS_STATUS_DRBG_ENT_LVL_SHIFT        (8U)
/*! DRBG_ENT_LVL
 *  0b00..NONE
 *  0b01..LOW, DRBG generates random numbers of low quality entropy
 *  0b10..HIGH, DRBG generates random numbers of high quality entropy
 *  0b11..RFU, Reserved for Future Use
 */
#define S50_ELS_STATUS_DRBG_ENT_LVL(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_DRBG_ENT_LVL_SHIFT)) & S50_ELS_STATUS_DRBG_ENT_LVL_MASK)

#define S50_ELS_STATUS_DTRNG_BUSY_MASK           (0x400U)
#define S50_ELS_STATUS_DTRNG_BUSY_SHIFT          (10U)
/*! DTRNG_BUSY
 *  0b0..Not gathering entropy
 *  0b1..Gathering entropy
 */
#define S50_ELS_STATUS_DTRNG_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_DTRNG_BUSY_SHIFT)) & S50_ELS_STATUS_DTRNG_BUSY_MASK)

#define S50_ELS_STATUS_ELS_LOCKED_MASK           (0x10000U)
#define S50_ELS_STATUS_ELS_LOCKED_SHIFT          (16U)
/*! ELS_LOCKED
 *  0b0..Not locked by master
 *  0b1..Locked by master
 */
#define S50_ELS_STATUS_ELS_LOCKED(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ELS_LOCKED_SHIFT)) & S50_ELS_STATUS_ELS_LOCKED_MASK)
/*! @} */

/*! @name ELS_CTRL - Control Register */
/*! @{ */

#define S50_ELS_CTRL_ELS_EN_MASK                 (0x1U)
#define S50_ELS_CTRL_ELS_EN_SHIFT                (0U)
/*! ELS_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define S50_ELS_CTRL_ELS_EN(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_EN_SHIFT)) & S50_ELS_CTRL_ELS_EN_MASK)

#define S50_ELS_CTRL_ELS_START_MASK              (0x2U)
#define S50_ELS_CTRL_ELS_START_SHIFT             (1U)
#define S50_ELS_CTRL_ELS_START(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_START_SHIFT)) & S50_ELS_CTRL_ELS_START_MASK)

#define S50_ELS_CTRL_ELS_RESET_MASK              (0x4U)
#define S50_ELS_CTRL_ELS_RESET_SHIFT             (2U)
#define S50_ELS_CTRL_ELS_RESET(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_RESET_SHIFT)) & S50_ELS_CTRL_ELS_RESET_MASK)

#define S50_ELS_CTRL_ELS_CMD_MASK                (0xF8U)
#define S50_ELS_CTRL_ELS_CMD_SHIFT               (3U)
/*! ELS_CMD - ELS Command ID */
#define S50_ELS_CTRL_ELS_CMD(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_CMD_SHIFT)) & S50_ELS_CTRL_ELS_CMD_MASK)

#define S50_ELS_CTRL_BYTE_ORDER_MASK             (0x100U)
#define S50_ELS_CTRL_BYTE_ORDER_SHIFT            (8U)
/*! BYTE_ORDER
 *  0b0..Little endian
 *  0b1..Big endian
 */
#define S50_ELS_CTRL_BYTE_ORDER(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_BYTE_ORDER_SHIFT)) & S50_ELS_CTRL_BYTE_ORDER_MASK)
/*! @} */

/*! @name ELS_CMDCFG0 - Command Configuration */
/*! @{ */

#define S50_ELS_CMDCFG0_CMDCFG0_MASK             (0xFFFFFFFFU)
#define S50_ELS_CMDCFG0_CMDCFG0_SHIFT            (0U)
#define S50_ELS_CMDCFG0_CMDCFG0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_CMDCFG0_CMDCFG0_SHIFT)) & S50_ELS_CMDCFG0_CMDCFG0_MASK)
/*! @} */

/*! @name ELS_CFG - Configuration Register */
/*! @{ */

#define S50_ELS_CFG_ADCTRL_MASK                  (0x3FF0000U)
#define S50_ELS_CFG_ADCTRL_SHIFT                 (16U)
#define S50_ELS_CFG_ADCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << S50_ELS_CFG_ADCTRL_SHIFT)) & S50_ELS_CFG_ADCTRL_MASK)
/*! @} */

/*! @name ELS_KIDX0 - Keystore Index 0 */
/*! @{ */

#define S50_ELS_KIDX0_KIDX0_MASK                 (0x1FU)
#define S50_ELS_KIDX0_KIDX0_SHIFT                (0U)
#define S50_ELS_KIDX0_KIDX0(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KIDX0_KIDX0_SHIFT)) & S50_ELS_KIDX0_KIDX0_MASK)
/*! @} */

/*! @name ELS_KIDX1 - Keystore Index 1 */
/*! @{ */

#define S50_ELS_KIDX1_KIDX1_MASK                 (0x1FU)
#define S50_ELS_KIDX1_KIDX1_SHIFT                (0U)
#define S50_ELS_KIDX1_KIDX1(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KIDX1_KIDX1_SHIFT)) & S50_ELS_KIDX1_KIDX1_MASK)
/*! @} */

/*! @name ELS_KPROPIN - Key Properties Request */
/*! @{ */

#define S50_ELS_KPROPIN_KPROPIN_MASK             (0xFFFFFFFFU)
#define S50_ELS_KPROPIN_KPROPIN_SHIFT            (0U)
#define S50_ELS_KPROPIN_KPROPIN(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KPROPIN_KPROPIN_SHIFT)) & S50_ELS_KPROPIN_KPROPIN_MASK)
/*! @} */

/*! @name ELS_DMA_SRC0 - DMA Source 0 */
/*! @{ */

#define S50_ELS_DMA_SRC0_ADDR_SRC0_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC0_ADDR_SRC0_SHIFT         (0U)
#define S50_ELS_DMA_SRC0_ADDR_SRC0(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC0_ADDR_SRC0_SHIFT)) & S50_ELS_DMA_SRC0_ADDR_SRC0_MASK)
/*! @} */

/*! @name ELS_DMA_SRC0_LEN - DMA Source 0 Length */
/*! @{ */

#define S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_MASK  (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_SHIFT (0U)
#define S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN(x)    (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_SHIFT)) & S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_MASK)
/*! @} */

/*! @name ELS_DMA_SRC1 - DMA Source 1 */
/*! @{ */

#define S50_ELS_DMA_SRC1_ADDR_SRC1_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC1_ADDR_SRC1_SHIFT         (0U)
#define S50_ELS_DMA_SRC1_ADDR_SRC1(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC1_ADDR_SRC1_SHIFT)) & S50_ELS_DMA_SRC1_ADDR_SRC1_MASK)
/*! @} */

/*! @name ELS_DMA_SRC2 - DMA Source 2 */
/*! @{ */

#define S50_ELS_DMA_SRC2_ADDR_SRC2_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC2_ADDR_SRC2_SHIFT         (0U)
#define S50_ELS_DMA_SRC2_ADDR_SRC2(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC2_ADDR_SRC2_SHIFT)) & S50_ELS_DMA_SRC2_ADDR_SRC2_MASK)
/*! @} */

/*! @name ELS_DMA_SRC2_LEN - DMA Source 2 Length */
/*! @{ */

#define S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_MASK  (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_SHIFT (0U)
#define S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN(x)    (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_SHIFT)) & S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_MASK)
/*! @} */

/*! @name ELS_DMA_RES0 - DMA Result 0 */
/*! @{ */

#define S50_ELS_DMA_RES0_ADDR_RES0_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_RES0_ADDR_RES0_SHIFT         (0U)
#define S50_ELS_DMA_RES0_ADDR_RES0(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_RES0_ADDR_RES0_SHIFT)) & S50_ELS_DMA_RES0_ADDR_RES0_MASK)
/*! @} */

/*! @name ELS_DMA_RES0_LEN - DMA Result 0 Length */
/*! @{ */

#define S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_MASK  (0xFFFFFFFFU)
#define S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_SHIFT (0U)
#define S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN(x)    (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_SHIFT)) & S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_MASK)
/*! @} */

/*! @name ELS_INT_ENABLE - Interrupt Enable */
/*! @{ */

#define S50_ELS_INT_ENABLE_INT_EN_MASK           (0x1U)
#define S50_ELS_INT_ENABLE_INT_EN_SHIFT          (0U)
/*! INT_EN
 *  0b0..Disables
 *  0b1..Enables
 */
#define S50_ELS_INT_ENABLE_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_ENABLE_INT_EN_SHIFT)) & S50_ELS_INT_ENABLE_INT_EN_MASK)
/*! @} */

/*! @name ELS_INT_STATUS_CLR - Interrupt Status Clear */
/*! @{ */

#define S50_ELS_INT_STATUS_CLR_INT_CLR_MASK      (0x1U)
#define S50_ELS_INT_STATUS_CLR_INT_CLR_SHIFT     (0U)
#define S50_ELS_INT_STATUS_CLR_INT_CLR(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_CLR_INT_CLR_SHIFT)) & S50_ELS_INT_STATUS_CLR_INT_CLR_MASK)
/*! @} */

/*! @name ELS_INT_STATUS_SET - Interrupt Status Set */
/*! @{ */

#define S50_ELS_INT_STATUS_SET_INT_SET_MASK      (0x1U)
#define S50_ELS_INT_STATUS_SET_INT_SET_SHIFT     (0U)
#define S50_ELS_INT_STATUS_SET_INT_SET(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_SET_INT_SET_SHIFT)) & S50_ELS_INT_STATUS_SET_INT_SET_MASK)
/*! @} */

/*! @name ELS_ERR_STATUS - Error Status */
/*! @{ */

#define S50_ELS_ERR_STATUS_BUS_ERR_MASK          (0x1U)
#define S50_ELS_ERR_STATUS_BUS_ERR_SHIFT         (0U)
/*! BUS_ERR
 *  0b0..No error
 *  0b1..Error occurred
 */
#define S50_ELS_ERR_STATUS_BUS_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_BUS_ERR_SHIFT)) & S50_ELS_ERR_STATUS_BUS_ERR_MASK)

#define S50_ELS_ERR_STATUS_OPN_ERR_MASK          (0x2U)
#define S50_ELS_ERR_STATUS_OPN_ERR_SHIFT         (1U)
/*! OPN_ERR
 *  0b0..No error
 *  0b1..Error occurred
 */
#define S50_ELS_ERR_STATUS_OPN_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_OPN_ERR_SHIFT)) & S50_ELS_ERR_STATUS_OPN_ERR_MASK)

#define S50_ELS_ERR_STATUS_ALG_ERR_MASK          (0x4U)
#define S50_ELS_ERR_STATUS_ALG_ERR_SHIFT         (2U)
/*! ALG_ERR
 *  0b0..No error
 *  0b1..Error occurred
 */
#define S50_ELS_ERR_STATUS_ALG_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_ALG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_ALG_ERR_MASK)

#define S50_ELS_ERR_STATUS_ITG_ERR_MASK          (0x8U)
#define S50_ELS_ERR_STATUS_ITG_ERR_SHIFT         (3U)
/*! ITG_ERR
 *  0b0..No error
 *  0b1..Error occurred
 */
#define S50_ELS_ERR_STATUS_ITG_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_ITG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_ITG_ERR_MASK)

#define S50_ELS_ERR_STATUS_FLT_ERR_MASK          (0x10U)
#define S50_ELS_ERR_STATUS_FLT_ERR_SHIFT         (4U)
/*! FLT_ERR
 *  0b0..No error
 *  0b1..Error occurred
 */
#define S50_ELS_ERR_STATUS_FLT_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_FLT_ERR_SHIFT)) & S50_ELS_ERR_STATUS_FLT_ERR_MASK)

#define S50_ELS_ERR_STATUS_PRNG_ERR_MASK         (0x20U)
#define S50_ELS_ERR_STATUS_PRNG_ERR_SHIFT        (5U)
/*! PRNG_ERR
 *  0b0..No error
 *  0b1..Error occurred
 */
#define S50_ELS_ERR_STATUS_PRNG_ERR(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_PRNG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_PRNG_ERR_MASK)

#define S50_ELS_ERR_STATUS_ERR_LVL_MASK          (0xC0U)
#define S50_ELS_ERR_STATUS_ERR_LVL_SHIFT         (6U)
#define S50_ELS_ERR_STATUS_ERR_LVL(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_ERR_LVL_SHIFT)) & S50_ELS_ERR_STATUS_ERR_LVL_MASK)

#define S50_ELS_ERR_STATUS_DTRNG_ERR_MASK        (0x100U)
#define S50_ELS_ERR_STATUS_DTRNG_ERR_SHIFT       (8U)
/*! DTRNG_ERR
 *  0b0..No error
 *  0b1..TRNG error occurred
 */
#define S50_ELS_ERR_STATUS_DTRNG_ERR(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_DTRNG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_DTRNG_ERR_MASK)
/*! @} */

/*! @name ELS_ERR_STATUS_CLR - Error Status Clear */
/*! @{ */

#define S50_ELS_ERR_STATUS_CLR_ERR_CLR_MASK      (0x1U)
#define S50_ELS_ERR_STATUS_CLR_ERR_CLR_SHIFT     (0U)
/*! ERR_CLR
 *  0b0..Exits ELS error state
 *  0b1..Clears ELS error state
 */
#define S50_ELS_ERR_STATUS_CLR_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_CLR_ERR_CLR_SHIFT)) & S50_ELS_ERR_STATUS_CLR_ERR_CLR_MASK)
/*! @} */

/*! @name ELS_VERSION - Version Register */
/*! @{ */

#define S50_ELS_VERSION_Z_MASK                   (0xFU)
#define S50_ELS_VERSION_Z_SHIFT                  (0U)
#define S50_ELS_VERSION_Z(x)                     (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_Z_SHIFT)) & S50_ELS_VERSION_Z_MASK)

#define S50_ELS_VERSION_Y2_MASK                  (0xF0U)
#define S50_ELS_VERSION_Y2_SHIFT                 (4U)
#define S50_ELS_VERSION_Y2(x)                    (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_Y2_SHIFT)) & S50_ELS_VERSION_Y2_MASK)

#define S50_ELS_VERSION_Y1_MASK                  (0xF00U)
#define S50_ELS_VERSION_Y1_SHIFT                 (8U)
#define S50_ELS_VERSION_Y1(x)                    (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_Y1_SHIFT)) & S50_ELS_VERSION_Y1_MASK)

#define S50_ELS_VERSION_X_MASK                   (0xF000U)
#define S50_ELS_VERSION_X_SHIFT                  (12U)
#define S50_ELS_VERSION_X(x)                     (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_X_SHIFT)) & S50_ELS_VERSION_X_MASK)

#define S50_ELS_VERSION_SW_Z_MASK                (0xF0000U)
#define S50_ELS_VERSION_SW_Z_SHIFT               (16U)
#define S50_ELS_VERSION_SW_Z(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_SW_Z_SHIFT)) & S50_ELS_VERSION_SW_Z_MASK)

#define S50_ELS_VERSION_SW_Y2_MASK               (0xF00000U)
#define S50_ELS_VERSION_SW_Y2_SHIFT              (20U)
#define S50_ELS_VERSION_SW_Y2(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_SW_Y2_SHIFT)) & S50_ELS_VERSION_SW_Y2_MASK)

#define S50_ELS_VERSION_SW_Y1_MASK               (0xF000000U)
#define S50_ELS_VERSION_SW_Y1_SHIFT              (24U)
#define S50_ELS_VERSION_SW_Y1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_SW_Y1_SHIFT)) & S50_ELS_VERSION_SW_Y1_MASK)

#define S50_ELS_VERSION_SW_X_MASK                (0xF0000000U)
#define S50_ELS_VERSION_SW_X_SHIFT               (28U)
#define S50_ELS_VERSION_SW_X(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_SW_X_SHIFT)) & S50_ELS_VERSION_SW_X_MASK)
/*! @} */

/*! @name ELS_PRNG_DATOUT - PRNG SW Read Out */
/*! @{ */

#define S50_ELS_PRNG_DATOUT_PRNG_DATOUT_MASK     (0xFFFFFFFFU)
#define S50_ELS_PRNG_DATOUT_PRNG_DATOUT_SHIFT    (0U)
#define S50_ELS_PRNG_DATOUT_PRNG_DATOUT(x)       (((uint32_t)(((uint32_t)(x)) << S50_ELS_PRNG_DATOUT_PRNG_DATOUT_SHIFT)) & S50_ELS_PRNG_DATOUT_PRNG_DATOUT_MASK)
/*! @} */

/*! @name ELS_CMDCRC_CTRL - CRC Configuration */
/*! @{ */

#define S50_ELS_CMDCRC_CTRL_CMDCRC_RST_MASK      (0x1U)
#define S50_ELS_CMDCRC_CTRL_CMDCRC_RST_SHIFT     (0U)
/*! CMDCRC_RST
 *  0b0..No effect
 *  0b1..Resets the CRC command to its default value
 */
#define S50_ELS_CMDCRC_CTRL_CMDCRC_RST(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_CMDCRC_CTRL_CMDCRC_RST_SHIFT)) & S50_ELS_CMDCRC_CTRL_CMDCRC_RST_MASK)

#define S50_ELS_CMDCRC_CTRL_CMDCRC_EN_MASK       (0x2U)
#define S50_ELS_CMDCRC_CTRL_CMDCRC_EN_SHIFT      (1U)
/*! CMDCRC_EN
 *  0b0..Disables the CRC command CRC. The CRC command will not be updated on completion of each ELS command.
 *  0b1..Enables the CRC command. The CRC command will be updated on completion of each ELS command.
 */
#define S50_ELS_CMDCRC_CTRL_CMDCRC_EN(x)         (((uint32_t)(((uint32_t)(x)) << S50_ELS_CMDCRC_CTRL_CMDCRC_EN_SHIFT)) & S50_ELS_CMDCRC_CTRL_CMDCRC_EN_MASK)
/*! @} */

/*! @name ELS_CMDCRC - Command CRC Value */
/*! @{ */

#define S50_ELS_CMDCRC_CMDCRC_MASK               (0xFFFFFFFFU)
#define S50_ELS_CMDCRC_CMDCRC_SHIFT              (0U)
#define S50_ELS_CMDCRC_CMDCRC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_CMDCRC_CMDCRC_SHIFT)) & S50_ELS_CMDCRC_CMDCRC_MASK)
/*! @} */

/*! @name ELS_SESSION_ID - Session ID */
/*! @{ */

#define S50_ELS_SESSION_ID_SESSION_ID_MASK       (0xFFFFFFFFU)
#define S50_ELS_SESSION_ID_SESSION_ID_SHIFT      (0U)
#define S50_ELS_SESSION_ID_SESSION_ID(x)         (((uint32_t)(((uint32_t)(x)) << S50_ELS_SESSION_ID_SESSION_ID_SHIFT)) & S50_ELS_SESSION_ID_SESSION_ID_MASK)
/*! @} */

/*! @name ELS_DMA_FIN_ADDR - Final DMA Address */
/*! @{ */

#define S50_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_MASK   (0xFFFFFFFFU)
#define S50_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_SHIFT  (0U)
#define S50_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_SHIFT)) & S50_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_MASK)
/*! @} */

/*! @name ELS_MASTER_ID - Master ID */
/*! @{ */

#define S50_ELS_MASTER_ID_MASTER_ID_MASK         (0x1FU)
#define S50_ELS_MASTER_ID_MASTER_ID_SHIFT        (0U)
#define S50_ELS_MASTER_ID_MASTER_ID(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_MASTER_ID_MASTER_ID_SHIFT)) & S50_ELS_MASTER_ID_MASTER_ID_MASK)
/*! @} */

/*! @name ELS_KIDX2 - Keystore Index 2 */
/*! @{ */

#define S50_ELS_KIDX2_KIDX2_MASK                 (0x1FU)
#define S50_ELS_KIDX2_KIDX2_SHIFT                (0U)
#define S50_ELS_KIDX2_KIDX2(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KIDX2_KIDX2_SHIFT)) & S50_ELS_KIDX2_KIDX2_MASK)
/*! @} */

/*! @name ELS_KS0 - Status Register */
/*! @{ */

#define S50_ELS_KS0_KS0_KSIZE_MASK               (0x3U)
#define S50_ELS_KS0_KS0_KSIZE_SHIFT              (0U)
/*! KS0_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS0_KS0_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_KSIZE_SHIFT)) & S50_ELS_KS0_KS0_KSIZE_MASK)

#define S50_ELS_KS0_KS0_KACT_MASK                (0x20U)
#define S50_ELS_KS0_KS0_KACT_SHIFT               (5U)
#define S50_ELS_KS0_KS0_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_KACT_SHIFT)) & S50_ELS_KS0_KS0_KACT_MASK)

#define S50_ELS_KS0_KS0_KBASE_MASK               (0x40U)
#define S50_ELS_KS0_KS0_KBASE_SHIFT              (6U)
#define S50_ELS_KS0_KS0_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_KBASE_SHIFT)) & S50_ELS_KS0_KS0_KBASE_MASK)

#define S50_ELS_KS0_KS0_FGP_MASK                 (0x80U)
#define S50_ELS_KS0_KS0_FGP_SHIFT                (7U)
#define S50_ELS_KS0_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_FGP_SHIFT)) & S50_ELS_KS0_KS0_FGP_MASK)

#define S50_ELS_KS0_KS0_FRTN_MASK                (0x100U)
#define S50_ELS_KS0_KS0_FRTN_SHIFT               (8U)
#define S50_ELS_KS0_KS0_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_FRTN_SHIFT)) & S50_ELS_KS0_KS0_FRTN_MASK)

#define S50_ELS_KS0_KS0_FHWO_MASK                (0x200U)
#define S50_ELS_KS0_KS0_FHWO_SHIFT               (9U)
#define S50_ELS_KS0_KS0_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_FHWO_SHIFT)) & S50_ELS_KS0_KS0_FHWO_MASK)

#define S50_ELS_KS0_KS0_UKPUK_MASK               (0x800U)
#define S50_ELS_KS0_KS0_UKPUK_SHIFT              (11U)
#define S50_ELS_KS0_KS0_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKPUK_SHIFT)) & S50_ELS_KS0_KS0_UKPUK_MASK)

#define S50_ELS_KS0_KS0_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS0_KS0_UTECDH_SHIFT             (12U)
#define S50_ELS_KS0_KS0_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UTECDH_SHIFT)) & S50_ELS_KS0_KS0_UTECDH_MASK)

#define S50_ELS_KS0_KS0_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS0_KS0_UCMAC_SHIFT              (13U)
#define S50_ELS_KS0_KS0_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UCMAC_SHIFT)) & S50_ELS_KS0_KS0_UCMAC_MASK)

#define S50_ELS_KS0_KS0_UKSK_MASK                (0x4000U)
#define S50_ELS_KS0_KS0_UKSK_SHIFT               (14U)
#define S50_ELS_KS0_KS0_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKSK_SHIFT)) & S50_ELS_KS0_KS0_UKSK_MASK)

#define S50_ELS_KS0_KS0_URTF_MASK                (0x8000U)
#define S50_ELS_KS0_KS0_URTF_SHIFT               (15U)
#define S50_ELS_KS0_KS0_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_URTF_SHIFT)) & S50_ELS_KS0_KS0_URTF_MASK)

#define S50_ELS_KS0_KS0_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS0_KS0_UCKDF_SHIFT              (16U)
#define S50_ELS_KS0_KS0_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UCKDF_SHIFT)) & S50_ELS_KS0_KS0_UCKDF_MASK)

#define S50_ELS_KS0_KS0_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS0_KS0_UHKDF_SHIFT              (17U)
#define S50_ELS_KS0_KS0_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UHKDF_SHIFT)) & S50_ELS_KS0_KS0_UHKDF_MASK)

#define S50_ELS_KS0_KS0_UECSG_MASK               (0x40000U)
#define S50_ELS_KS0_KS0_UECSG_SHIFT              (18U)
#define S50_ELS_KS0_KS0_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UECSG_SHIFT)) & S50_ELS_KS0_KS0_UECSG_MASK)

#define S50_ELS_KS0_KS0_UECDH_MASK               (0x80000U)
#define S50_ELS_KS0_KS0_UECDH_SHIFT              (19U)
#define S50_ELS_KS0_KS0_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UECDH_SHIFT)) & S50_ELS_KS0_KS0_UECDH_MASK)

#define S50_ELS_KS0_KS0_UAES_MASK                (0x100000U)
#define S50_ELS_KS0_KS0_UAES_SHIFT               (20U)
#define S50_ELS_KS0_KS0_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UAES_SHIFT)) & S50_ELS_KS0_KS0_UAES_MASK)

#define S50_ELS_KS0_KS0_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS0_KS0_UHMAC_SHIFT              (21U)
#define S50_ELS_KS0_KS0_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UHMAC_SHIFT)) & S50_ELS_KS0_KS0_UHMAC_MASK)

#define S50_ELS_KS0_KS0_UKWK_MASK                (0x400000U)
#define S50_ELS_KS0_KS0_UKWK_SHIFT               (22U)
#define S50_ELS_KS0_KS0_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKWK_SHIFT)) & S50_ELS_KS0_KS0_UKWK_MASK)

#define S50_ELS_KS0_KS0_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS0_KS0_UKUOK_SHIFT              (23U)
#define S50_ELS_KS0_KS0_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKUOK_SHIFT)) & S50_ELS_KS0_KS0_UKUOK_MASK)

#define S50_ELS_KS0_KS0_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS0_KS0_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS0_KS0_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UTLSPMS_SHIFT)) & S50_ELS_KS0_KS0_UTLSPMS_MASK)

#define S50_ELS_KS0_KS0_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS0_KS0_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS0_KS0_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UTLSMS_SHIFT)) & S50_ELS_KS0_KS0_UTLSMS_MASK)

#define S50_ELS_KS0_KS0_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS0_KS0_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS0_KS0_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKGSRC_SHIFT)) & S50_ELS_KS0_KS0_UKGSRC_MASK)

#define S50_ELS_KS0_KS0_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS0_KS0_UHWO_SHIFT               (27U)
#define S50_ELS_KS0_KS0_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UHWO_SHIFT)) & S50_ELS_KS0_KS0_UHWO_MASK)

#define S50_ELS_KS0_KS0_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS0_KS0_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS0_KS0_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UWRPOK_SHIFT)) & S50_ELS_KS0_KS0_UWRPOK_MASK)

#define S50_ELS_KS0_KS0_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS0_KS0_UDUK_SHIFT               (29U)
#define S50_ELS_KS0_KS0_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UDUK_SHIFT)) & S50_ELS_KS0_KS0_UDUK_MASK)

#define S50_ELS_KS0_KS0_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS0_KS0_UPPROT_SHIFT             (30U)
#define S50_ELS_KS0_KS0_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UPPROT_SHIFT)) & S50_ELS_KS0_KS0_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS1 - Status Register */
/*! @{ */

#define S50_ELS_KS1_KS1_KSIZE_MASK               (0x3U)
#define S50_ELS_KS1_KS1_KSIZE_SHIFT              (0U)
/*! KS1_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS1_KS1_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_KSIZE_SHIFT)) & S50_ELS_KS1_KS1_KSIZE_MASK)

#define S50_ELS_KS1_KS1_KACT_MASK                (0x20U)
#define S50_ELS_KS1_KS1_KACT_SHIFT               (5U)
#define S50_ELS_KS1_KS1_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_KACT_SHIFT)) & S50_ELS_KS1_KS1_KACT_MASK)

#define S50_ELS_KS1_KS1_KBASE_MASK               (0x40U)
#define S50_ELS_KS1_KS1_KBASE_SHIFT              (6U)
#define S50_ELS_KS1_KS1_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_KBASE_SHIFT)) & S50_ELS_KS1_KS1_KBASE_MASK)

#define S50_ELS_KS1_KS1_FGP_MASK                 (0x80U)
#define S50_ELS_KS1_KS1_FGP_SHIFT                (7U)
#define S50_ELS_KS1_KS1_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_FGP_SHIFT)) & S50_ELS_KS1_KS1_FGP_MASK)

#define S50_ELS_KS1_KS1_FRTN_MASK                (0x100U)
#define S50_ELS_KS1_KS1_FRTN_SHIFT               (8U)
#define S50_ELS_KS1_KS1_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_FRTN_SHIFT)) & S50_ELS_KS1_KS1_FRTN_MASK)

#define S50_ELS_KS1_KS1_FHWO_MASK                (0x200U)
#define S50_ELS_KS1_KS1_FHWO_SHIFT               (9U)
#define S50_ELS_KS1_KS1_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_FHWO_SHIFT)) & S50_ELS_KS1_KS1_FHWO_MASK)

#define S50_ELS_KS1_KS1_UKPUK_MASK               (0x800U)
#define S50_ELS_KS1_KS1_UKPUK_SHIFT              (11U)
#define S50_ELS_KS1_KS1_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKPUK_SHIFT)) & S50_ELS_KS1_KS1_UKPUK_MASK)

#define S50_ELS_KS1_KS1_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS1_KS1_UTECDH_SHIFT             (12U)
#define S50_ELS_KS1_KS1_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UTECDH_SHIFT)) & S50_ELS_KS1_KS1_UTECDH_MASK)

#define S50_ELS_KS1_KS1_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS1_KS1_UCMAC_SHIFT              (13U)
#define S50_ELS_KS1_KS1_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UCMAC_SHIFT)) & S50_ELS_KS1_KS1_UCMAC_MASK)

#define S50_ELS_KS1_KS1_UKSK_MASK                (0x4000U)
#define S50_ELS_KS1_KS1_UKSK_SHIFT               (14U)
#define S50_ELS_KS1_KS1_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKSK_SHIFT)) & S50_ELS_KS1_KS1_UKSK_MASK)

#define S50_ELS_KS1_KS1_URTF_MASK                (0x8000U)
#define S50_ELS_KS1_KS1_URTF_SHIFT               (15U)
#define S50_ELS_KS1_KS1_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_URTF_SHIFT)) & S50_ELS_KS1_KS1_URTF_MASK)

#define S50_ELS_KS1_KS1_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS1_KS1_UCKDF_SHIFT              (16U)
#define S50_ELS_KS1_KS1_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UCKDF_SHIFT)) & S50_ELS_KS1_KS1_UCKDF_MASK)

#define S50_ELS_KS1_KS1_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS1_KS1_UHKDF_SHIFT              (17U)
#define S50_ELS_KS1_KS1_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UHKDF_SHIFT)) & S50_ELS_KS1_KS1_UHKDF_MASK)

#define S50_ELS_KS1_KS1_UECSG_MASK               (0x40000U)
#define S50_ELS_KS1_KS1_UECSG_SHIFT              (18U)
#define S50_ELS_KS1_KS1_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UECSG_SHIFT)) & S50_ELS_KS1_KS1_UECSG_MASK)

#define S50_ELS_KS1_KS1_UECDH_MASK               (0x80000U)
#define S50_ELS_KS1_KS1_UECDH_SHIFT              (19U)
#define S50_ELS_KS1_KS1_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UECDH_SHIFT)) & S50_ELS_KS1_KS1_UECDH_MASK)

#define S50_ELS_KS1_KS1_UAES_MASK                (0x100000U)
#define S50_ELS_KS1_KS1_UAES_SHIFT               (20U)
#define S50_ELS_KS1_KS1_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UAES_SHIFT)) & S50_ELS_KS1_KS1_UAES_MASK)

#define S50_ELS_KS1_KS1_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS1_KS1_UHMAC_SHIFT              (21U)
#define S50_ELS_KS1_KS1_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UHMAC_SHIFT)) & S50_ELS_KS1_KS1_UHMAC_MASK)

#define S50_ELS_KS1_KS1_UKWK_MASK                (0x400000U)
#define S50_ELS_KS1_KS1_UKWK_SHIFT               (22U)
#define S50_ELS_KS1_KS1_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKWK_SHIFT)) & S50_ELS_KS1_KS1_UKWK_MASK)

#define S50_ELS_KS1_KS1_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS1_KS1_UKUOK_SHIFT              (23U)
#define S50_ELS_KS1_KS1_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKUOK_SHIFT)) & S50_ELS_KS1_KS1_UKUOK_MASK)

#define S50_ELS_KS1_KS1_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS1_KS1_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS1_KS1_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UTLSPMS_SHIFT)) & S50_ELS_KS1_KS1_UTLSPMS_MASK)

#define S50_ELS_KS1_KS1_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS1_KS1_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS1_KS1_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UTLSMS_SHIFT)) & S50_ELS_KS1_KS1_UTLSMS_MASK)

#define S50_ELS_KS1_KS1_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS1_KS1_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS1_KS1_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKGSRC_SHIFT)) & S50_ELS_KS1_KS1_UKGSRC_MASK)

#define S50_ELS_KS1_KS1_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS1_KS1_UHWO_SHIFT               (27U)
#define S50_ELS_KS1_KS1_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UHWO_SHIFT)) & S50_ELS_KS1_KS1_UHWO_MASK)

#define S50_ELS_KS1_KS1_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS1_KS1_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS1_KS1_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UWRPOK_SHIFT)) & S50_ELS_KS1_KS1_UWRPOK_MASK)

#define S50_ELS_KS1_KS1_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS1_KS1_UDUK_SHIFT               (29U)
#define S50_ELS_KS1_KS1_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UDUK_SHIFT)) & S50_ELS_KS1_KS1_UDUK_MASK)

#define S50_ELS_KS1_KS1_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS1_KS1_UPPROT_SHIFT             (30U)
#define S50_ELS_KS1_KS1_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UPPROT_SHIFT)) & S50_ELS_KS1_KS1_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS2 - Status Register */
/*! @{ */

#define S50_ELS_KS2_KS2_KSIZE_MASK               (0x3U)
#define S50_ELS_KS2_KS2_KSIZE_SHIFT              (0U)
/*! KS2_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS2_KS2_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_KSIZE_SHIFT)) & S50_ELS_KS2_KS2_KSIZE_MASK)

#define S50_ELS_KS2_KS2_KACT_MASK                (0x20U)
#define S50_ELS_KS2_KS2_KACT_SHIFT               (5U)
#define S50_ELS_KS2_KS2_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_KACT_SHIFT)) & S50_ELS_KS2_KS2_KACT_MASK)

#define S50_ELS_KS2_KS2_KBASE_MASK               (0x40U)
#define S50_ELS_KS2_KS2_KBASE_SHIFT              (6U)
#define S50_ELS_KS2_KS2_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_KBASE_SHIFT)) & S50_ELS_KS2_KS2_KBASE_MASK)

#define S50_ELS_KS2_KS2_FGP_MASK                 (0x80U)
#define S50_ELS_KS2_KS2_FGP_SHIFT                (7U)
#define S50_ELS_KS2_KS2_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_FGP_SHIFT)) & S50_ELS_KS2_KS2_FGP_MASK)

#define S50_ELS_KS2_KS2_FRTN_MASK                (0x100U)
#define S50_ELS_KS2_KS2_FRTN_SHIFT               (8U)
#define S50_ELS_KS2_KS2_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_FRTN_SHIFT)) & S50_ELS_KS2_KS2_FRTN_MASK)

#define S50_ELS_KS2_KS2_FHWO_MASK                (0x200U)
#define S50_ELS_KS2_KS2_FHWO_SHIFT               (9U)
#define S50_ELS_KS2_KS2_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_FHWO_SHIFT)) & S50_ELS_KS2_KS2_FHWO_MASK)

#define S50_ELS_KS2_KS2_UKPUK_MASK               (0x800U)
#define S50_ELS_KS2_KS2_UKPUK_SHIFT              (11U)
#define S50_ELS_KS2_KS2_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKPUK_SHIFT)) & S50_ELS_KS2_KS2_UKPUK_MASK)

#define S50_ELS_KS2_KS2_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS2_KS2_UTECDH_SHIFT             (12U)
#define S50_ELS_KS2_KS2_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UTECDH_SHIFT)) & S50_ELS_KS2_KS2_UTECDH_MASK)

#define S50_ELS_KS2_KS2_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS2_KS2_UCMAC_SHIFT              (13U)
#define S50_ELS_KS2_KS2_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UCMAC_SHIFT)) & S50_ELS_KS2_KS2_UCMAC_MASK)

#define S50_ELS_KS2_KS2_UKSK_MASK                (0x4000U)
#define S50_ELS_KS2_KS2_UKSK_SHIFT               (14U)
#define S50_ELS_KS2_KS2_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKSK_SHIFT)) & S50_ELS_KS2_KS2_UKSK_MASK)

#define S50_ELS_KS2_KS2_URTF_MASK                (0x8000U)
#define S50_ELS_KS2_KS2_URTF_SHIFT               (15U)
#define S50_ELS_KS2_KS2_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_URTF_SHIFT)) & S50_ELS_KS2_KS2_URTF_MASK)

#define S50_ELS_KS2_KS2_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS2_KS2_UCKDF_SHIFT              (16U)
#define S50_ELS_KS2_KS2_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UCKDF_SHIFT)) & S50_ELS_KS2_KS2_UCKDF_MASK)

#define S50_ELS_KS2_KS2_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS2_KS2_UHKDF_SHIFT              (17U)
#define S50_ELS_KS2_KS2_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UHKDF_SHIFT)) & S50_ELS_KS2_KS2_UHKDF_MASK)

#define S50_ELS_KS2_KS2_UECSG_MASK               (0x40000U)
#define S50_ELS_KS2_KS2_UECSG_SHIFT              (18U)
#define S50_ELS_KS2_KS2_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UECSG_SHIFT)) & S50_ELS_KS2_KS2_UECSG_MASK)

#define S50_ELS_KS2_KS2_UECDH_MASK               (0x80000U)
#define S50_ELS_KS2_KS2_UECDH_SHIFT              (19U)
#define S50_ELS_KS2_KS2_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UECDH_SHIFT)) & S50_ELS_KS2_KS2_UECDH_MASK)

#define S50_ELS_KS2_KS2_UAES_MASK                (0x100000U)
#define S50_ELS_KS2_KS2_UAES_SHIFT               (20U)
#define S50_ELS_KS2_KS2_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UAES_SHIFT)) & S50_ELS_KS2_KS2_UAES_MASK)

#define S50_ELS_KS2_KS2_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS2_KS2_UHMAC_SHIFT              (21U)
#define S50_ELS_KS2_KS2_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UHMAC_SHIFT)) & S50_ELS_KS2_KS2_UHMAC_MASK)

#define S50_ELS_KS2_KS2_UKWK_MASK                (0x400000U)
#define S50_ELS_KS2_KS2_UKWK_SHIFT               (22U)
#define S50_ELS_KS2_KS2_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKWK_SHIFT)) & S50_ELS_KS2_KS2_UKWK_MASK)

#define S50_ELS_KS2_KS2_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS2_KS2_UKUOK_SHIFT              (23U)
#define S50_ELS_KS2_KS2_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKUOK_SHIFT)) & S50_ELS_KS2_KS2_UKUOK_MASK)

#define S50_ELS_KS2_KS2_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS2_KS2_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS2_KS2_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UTLSPMS_SHIFT)) & S50_ELS_KS2_KS2_UTLSPMS_MASK)

#define S50_ELS_KS2_KS2_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS2_KS2_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS2_KS2_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UTLSMS_SHIFT)) & S50_ELS_KS2_KS2_UTLSMS_MASK)

#define S50_ELS_KS2_KS2_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS2_KS2_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS2_KS2_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKGSRC_SHIFT)) & S50_ELS_KS2_KS2_UKGSRC_MASK)

#define S50_ELS_KS2_KS2_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS2_KS2_UHWO_SHIFT               (27U)
#define S50_ELS_KS2_KS2_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UHWO_SHIFT)) & S50_ELS_KS2_KS2_UHWO_MASK)

#define S50_ELS_KS2_KS2_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS2_KS2_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS2_KS2_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UWRPOK_SHIFT)) & S50_ELS_KS2_KS2_UWRPOK_MASK)

#define S50_ELS_KS2_KS2_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS2_KS2_UDUK_SHIFT               (29U)
#define S50_ELS_KS2_KS2_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UDUK_SHIFT)) & S50_ELS_KS2_KS2_UDUK_MASK)

#define S50_ELS_KS2_KS2_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS2_KS2_UPPROT_SHIFT             (30U)
#define S50_ELS_KS2_KS2_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UPPROT_SHIFT)) & S50_ELS_KS2_KS2_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS3 - Status Register */
/*! @{ */

#define S50_ELS_KS3_KS3_KSIZE_MASK               (0x3U)
#define S50_ELS_KS3_KS3_KSIZE_SHIFT              (0U)
/*! KS3_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS3_KS3_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_KSIZE_SHIFT)) & S50_ELS_KS3_KS3_KSIZE_MASK)

#define S50_ELS_KS3_KS3_KACT_MASK                (0x20U)
#define S50_ELS_KS3_KS3_KACT_SHIFT               (5U)
#define S50_ELS_KS3_KS3_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_KACT_SHIFT)) & S50_ELS_KS3_KS3_KACT_MASK)

#define S50_ELS_KS3_KS3_KBASE_MASK               (0x40U)
#define S50_ELS_KS3_KS3_KBASE_SHIFT              (6U)
#define S50_ELS_KS3_KS3_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_KBASE_SHIFT)) & S50_ELS_KS3_KS3_KBASE_MASK)

#define S50_ELS_KS3_KS3_FGP_MASK                 (0x80U)
#define S50_ELS_KS3_KS3_FGP_SHIFT                (7U)
#define S50_ELS_KS3_KS3_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_FGP_SHIFT)) & S50_ELS_KS3_KS3_FGP_MASK)

#define S50_ELS_KS3_KS3_FRTN_MASK                (0x100U)
#define S50_ELS_KS3_KS3_FRTN_SHIFT               (8U)
#define S50_ELS_KS3_KS3_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_FRTN_SHIFT)) & S50_ELS_KS3_KS3_FRTN_MASK)

#define S50_ELS_KS3_KS3_FHWO_MASK                (0x200U)
#define S50_ELS_KS3_KS3_FHWO_SHIFT               (9U)
#define S50_ELS_KS3_KS3_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_FHWO_SHIFT)) & S50_ELS_KS3_KS3_FHWO_MASK)

#define S50_ELS_KS3_KS3_UKPUK_MASK               (0x800U)
#define S50_ELS_KS3_KS3_UKPUK_SHIFT              (11U)
#define S50_ELS_KS3_KS3_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKPUK_SHIFT)) & S50_ELS_KS3_KS3_UKPUK_MASK)

#define S50_ELS_KS3_KS3_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS3_KS3_UTECDH_SHIFT             (12U)
#define S50_ELS_KS3_KS3_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UTECDH_SHIFT)) & S50_ELS_KS3_KS3_UTECDH_MASK)

#define S50_ELS_KS3_KS3_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS3_KS3_UCMAC_SHIFT              (13U)
#define S50_ELS_KS3_KS3_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UCMAC_SHIFT)) & S50_ELS_KS3_KS3_UCMAC_MASK)

#define S50_ELS_KS3_KS3_UKSK_MASK                (0x4000U)
#define S50_ELS_KS3_KS3_UKSK_SHIFT               (14U)
#define S50_ELS_KS3_KS3_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKSK_SHIFT)) & S50_ELS_KS3_KS3_UKSK_MASK)

#define S50_ELS_KS3_KS3_URTF_MASK                (0x8000U)
#define S50_ELS_KS3_KS3_URTF_SHIFT               (15U)
#define S50_ELS_KS3_KS3_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_URTF_SHIFT)) & S50_ELS_KS3_KS3_URTF_MASK)

#define S50_ELS_KS3_KS3_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS3_KS3_UCKDF_SHIFT              (16U)
#define S50_ELS_KS3_KS3_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UCKDF_SHIFT)) & S50_ELS_KS3_KS3_UCKDF_MASK)

#define S50_ELS_KS3_KS3_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS3_KS3_UHKDF_SHIFT              (17U)
#define S50_ELS_KS3_KS3_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UHKDF_SHIFT)) & S50_ELS_KS3_KS3_UHKDF_MASK)

#define S50_ELS_KS3_KS3_UECSG_MASK               (0x40000U)
#define S50_ELS_KS3_KS3_UECSG_SHIFT              (18U)
#define S50_ELS_KS3_KS3_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UECSG_SHIFT)) & S50_ELS_KS3_KS3_UECSG_MASK)

#define S50_ELS_KS3_KS3_UECDH_MASK               (0x80000U)
#define S50_ELS_KS3_KS3_UECDH_SHIFT              (19U)
#define S50_ELS_KS3_KS3_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UECDH_SHIFT)) & S50_ELS_KS3_KS3_UECDH_MASK)

#define S50_ELS_KS3_KS3_UAES_MASK                (0x100000U)
#define S50_ELS_KS3_KS3_UAES_SHIFT               (20U)
#define S50_ELS_KS3_KS3_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UAES_SHIFT)) & S50_ELS_KS3_KS3_UAES_MASK)

#define S50_ELS_KS3_KS3_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS3_KS3_UHMAC_SHIFT              (21U)
#define S50_ELS_KS3_KS3_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UHMAC_SHIFT)) & S50_ELS_KS3_KS3_UHMAC_MASK)

#define S50_ELS_KS3_KS3_UKWK_MASK                (0x400000U)
#define S50_ELS_KS3_KS3_UKWK_SHIFT               (22U)
#define S50_ELS_KS3_KS3_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKWK_SHIFT)) & S50_ELS_KS3_KS3_UKWK_MASK)

#define S50_ELS_KS3_KS3_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS3_KS3_UKUOK_SHIFT              (23U)
#define S50_ELS_KS3_KS3_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKUOK_SHIFT)) & S50_ELS_KS3_KS3_UKUOK_MASK)

#define S50_ELS_KS3_KS3_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS3_KS3_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS3_KS3_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UTLSPMS_SHIFT)) & S50_ELS_KS3_KS3_UTLSPMS_MASK)

#define S50_ELS_KS3_KS3_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS3_KS3_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS3_KS3_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UTLSMS_SHIFT)) & S50_ELS_KS3_KS3_UTLSMS_MASK)

#define S50_ELS_KS3_KS3_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS3_KS3_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS3_KS3_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKGSRC_SHIFT)) & S50_ELS_KS3_KS3_UKGSRC_MASK)

#define S50_ELS_KS3_KS3_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS3_KS3_UHWO_SHIFT               (27U)
#define S50_ELS_KS3_KS3_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UHWO_SHIFT)) & S50_ELS_KS3_KS3_UHWO_MASK)

#define S50_ELS_KS3_KS3_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS3_KS3_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS3_KS3_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UWRPOK_SHIFT)) & S50_ELS_KS3_KS3_UWRPOK_MASK)

#define S50_ELS_KS3_KS3_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS3_KS3_UDUK_SHIFT               (29U)
#define S50_ELS_KS3_KS3_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UDUK_SHIFT)) & S50_ELS_KS3_KS3_UDUK_MASK)

#define S50_ELS_KS3_KS3_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS3_KS3_UPPROT_SHIFT             (30U)
#define S50_ELS_KS3_KS3_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UPPROT_SHIFT)) & S50_ELS_KS3_KS3_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS4 - Status Register */
/*! @{ */

#define S50_ELS_KS4_KS4_KSIZE_MASK               (0x3U)
#define S50_ELS_KS4_KS4_KSIZE_SHIFT              (0U)
/*! KS4_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS4_KS4_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_KSIZE_SHIFT)) & S50_ELS_KS4_KS4_KSIZE_MASK)

#define S50_ELS_KS4_KS4_KACT_MASK                (0x20U)
#define S50_ELS_KS4_KS4_KACT_SHIFT               (5U)
#define S50_ELS_KS4_KS4_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_KACT_SHIFT)) & S50_ELS_KS4_KS4_KACT_MASK)

#define S50_ELS_KS4_KS4_KBASE_MASK               (0x40U)
#define S50_ELS_KS4_KS4_KBASE_SHIFT              (6U)
#define S50_ELS_KS4_KS4_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_KBASE_SHIFT)) & S50_ELS_KS4_KS4_KBASE_MASK)

#define S50_ELS_KS4_KS4_FGP_MASK                 (0x80U)
#define S50_ELS_KS4_KS4_FGP_SHIFT                (7U)
#define S50_ELS_KS4_KS4_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_FGP_SHIFT)) & S50_ELS_KS4_KS4_FGP_MASK)

#define S50_ELS_KS4_KS4_FRTN_MASK                (0x100U)
#define S50_ELS_KS4_KS4_FRTN_SHIFT               (8U)
#define S50_ELS_KS4_KS4_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_FRTN_SHIFT)) & S50_ELS_KS4_KS4_FRTN_MASK)

#define S50_ELS_KS4_KS4_FHWO_MASK                (0x200U)
#define S50_ELS_KS4_KS4_FHWO_SHIFT               (9U)
#define S50_ELS_KS4_KS4_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_FHWO_SHIFT)) & S50_ELS_KS4_KS4_FHWO_MASK)

#define S50_ELS_KS4_KS4_UKPUK_MASK               (0x800U)
#define S50_ELS_KS4_KS4_UKPUK_SHIFT              (11U)
#define S50_ELS_KS4_KS4_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKPUK_SHIFT)) & S50_ELS_KS4_KS4_UKPUK_MASK)

#define S50_ELS_KS4_KS4_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS4_KS4_UTECDH_SHIFT             (12U)
#define S50_ELS_KS4_KS4_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UTECDH_SHIFT)) & S50_ELS_KS4_KS4_UTECDH_MASK)

#define S50_ELS_KS4_KS4_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS4_KS4_UCMAC_SHIFT              (13U)
#define S50_ELS_KS4_KS4_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UCMAC_SHIFT)) & S50_ELS_KS4_KS4_UCMAC_MASK)

#define S50_ELS_KS4_KS4_UKSK_MASK                (0x4000U)
#define S50_ELS_KS4_KS4_UKSK_SHIFT               (14U)
#define S50_ELS_KS4_KS4_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKSK_SHIFT)) & S50_ELS_KS4_KS4_UKSK_MASK)

#define S50_ELS_KS4_KS4_URTF_MASK                (0x8000U)
#define S50_ELS_KS4_KS4_URTF_SHIFT               (15U)
#define S50_ELS_KS4_KS4_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_URTF_SHIFT)) & S50_ELS_KS4_KS4_URTF_MASK)

#define S50_ELS_KS4_KS4_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS4_KS4_UCKDF_SHIFT              (16U)
#define S50_ELS_KS4_KS4_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UCKDF_SHIFT)) & S50_ELS_KS4_KS4_UCKDF_MASK)

#define S50_ELS_KS4_KS4_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS4_KS4_UHKDF_SHIFT              (17U)
#define S50_ELS_KS4_KS4_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UHKDF_SHIFT)) & S50_ELS_KS4_KS4_UHKDF_MASK)

#define S50_ELS_KS4_KS4_UECSG_MASK               (0x40000U)
#define S50_ELS_KS4_KS4_UECSG_SHIFT              (18U)
#define S50_ELS_KS4_KS4_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UECSG_SHIFT)) & S50_ELS_KS4_KS4_UECSG_MASK)

#define S50_ELS_KS4_KS4_UECDH_MASK               (0x80000U)
#define S50_ELS_KS4_KS4_UECDH_SHIFT              (19U)
#define S50_ELS_KS4_KS4_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UECDH_SHIFT)) & S50_ELS_KS4_KS4_UECDH_MASK)

#define S50_ELS_KS4_KS4_UAES_MASK                (0x100000U)
#define S50_ELS_KS4_KS4_UAES_SHIFT               (20U)
#define S50_ELS_KS4_KS4_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UAES_SHIFT)) & S50_ELS_KS4_KS4_UAES_MASK)

#define S50_ELS_KS4_KS4_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS4_KS4_UHMAC_SHIFT              (21U)
#define S50_ELS_KS4_KS4_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UHMAC_SHIFT)) & S50_ELS_KS4_KS4_UHMAC_MASK)

#define S50_ELS_KS4_KS4_UKWK_MASK                (0x400000U)
#define S50_ELS_KS4_KS4_UKWK_SHIFT               (22U)
#define S50_ELS_KS4_KS4_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKWK_SHIFT)) & S50_ELS_KS4_KS4_UKWK_MASK)

#define S50_ELS_KS4_KS4_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS4_KS4_UKUOK_SHIFT              (23U)
#define S50_ELS_KS4_KS4_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKUOK_SHIFT)) & S50_ELS_KS4_KS4_UKUOK_MASK)

#define S50_ELS_KS4_KS4_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS4_KS4_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS4_KS4_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UTLSPMS_SHIFT)) & S50_ELS_KS4_KS4_UTLSPMS_MASK)

#define S50_ELS_KS4_KS4_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS4_KS4_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS4_KS4_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UTLSMS_SHIFT)) & S50_ELS_KS4_KS4_UTLSMS_MASK)

#define S50_ELS_KS4_KS4_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS4_KS4_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS4_KS4_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKGSRC_SHIFT)) & S50_ELS_KS4_KS4_UKGSRC_MASK)

#define S50_ELS_KS4_KS4_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS4_KS4_UHWO_SHIFT               (27U)
#define S50_ELS_KS4_KS4_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UHWO_SHIFT)) & S50_ELS_KS4_KS4_UHWO_MASK)

#define S50_ELS_KS4_KS4_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS4_KS4_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS4_KS4_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UWRPOK_SHIFT)) & S50_ELS_KS4_KS4_UWRPOK_MASK)

#define S50_ELS_KS4_KS4_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS4_KS4_UDUK_SHIFT               (29U)
#define S50_ELS_KS4_KS4_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UDUK_SHIFT)) & S50_ELS_KS4_KS4_UDUK_MASK)

#define S50_ELS_KS4_KS4_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS4_KS4_UPPROT_SHIFT             (30U)
#define S50_ELS_KS4_KS4_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UPPROT_SHIFT)) & S50_ELS_KS4_KS4_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS5 - Status Register */
/*! @{ */

#define S50_ELS_KS5_KS5_KSIZE_MASK               (0x3U)
#define S50_ELS_KS5_KS5_KSIZE_SHIFT              (0U)
/*! KS5_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS5_KS5_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_KSIZE_SHIFT)) & S50_ELS_KS5_KS5_KSIZE_MASK)

#define S50_ELS_KS5_KS5_KACT_MASK                (0x20U)
#define S50_ELS_KS5_KS5_KACT_SHIFT               (5U)
#define S50_ELS_KS5_KS5_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_KACT_SHIFT)) & S50_ELS_KS5_KS5_KACT_MASK)

#define S50_ELS_KS5_KS5_KBASE_MASK               (0x40U)
#define S50_ELS_KS5_KS5_KBASE_SHIFT              (6U)
#define S50_ELS_KS5_KS5_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_KBASE_SHIFT)) & S50_ELS_KS5_KS5_KBASE_MASK)

#define S50_ELS_KS5_KS5_FGP_MASK                 (0x80U)
#define S50_ELS_KS5_KS5_FGP_SHIFT                (7U)
#define S50_ELS_KS5_KS5_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_FGP_SHIFT)) & S50_ELS_KS5_KS5_FGP_MASK)

#define S50_ELS_KS5_KS5_FRTN_MASK                (0x100U)
#define S50_ELS_KS5_KS5_FRTN_SHIFT               (8U)
#define S50_ELS_KS5_KS5_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_FRTN_SHIFT)) & S50_ELS_KS5_KS5_FRTN_MASK)

#define S50_ELS_KS5_KS5_FHWO_MASK                (0x200U)
#define S50_ELS_KS5_KS5_FHWO_SHIFT               (9U)
#define S50_ELS_KS5_KS5_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_FHWO_SHIFT)) & S50_ELS_KS5_KS5_FHWO_MASK)

#define S50_ELS_KS5_KS5_UKPUK_MASK               (0x800U)
#define S50_ELS_KS5_KS5_UKPUK_SHIFT              (11U)
#define S50_ELS_KS5_KS5_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKPUK_SHIFT)) & S50_ELS_KS5_KS5_UKPUK_MASK)

#define S50_ELS_KS5_KS5_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS5_KS5_UTECDH_SHIFT             (12U)
#define S50_ELS_KS5_KS5_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UTECDH_SHIFT)) & S50_ELS_KS5_KS5_UTECDH_MASK)

#define S50_ELS_KS5_KS5_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS5_KS5_UCMAC_SHIFT              (13U)
#define S50_ELS_KS5_KS5_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UCMAC_SHIFT)) & S50_ELS_KS5_KS5_UCMAC_MASK)

#define S50_ELS_KS5_KS5_UKSK_MASK                (0x4000U)
#define S50_ELS_KS5_KS5_UKSK_SHIFT               (14U)
#define S50_ELS_KS5_KS5_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKSK_SHIFT)) & S50_ELS_KS5_KS5_UKSK_MASK)

#define S50_ELS_KS5_KS5_URTF_MASK                (0x8000U)
#define S50_ELS_KS5_KS5_URTF_SHIFT               (15U)
#define S50_ELS_KS5_KS5_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_URTF_SHIFT)) & S50_ELS_KS5_KS5_URTF_MASK)

#define S50_ELS_KS5_KS5_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS5_KS5_UCKDF_SHIFT              (16U)
#define S50_ELS_KS5_KS5_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UCKDF_SHIFT)) & S50_ELS_KS5_KS5_UCKDF_MASK)

#define S50_ELS_KS5_KS5_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS5_KS5_UHKDF_SHIFT              (17U)
#define S50_ELS_KS5_KS5_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UHKDF_SHIFT)) & S50_ELS_KS5_KS5_UHKDF_MASK)

#define S50_ELS_KS5_KS5_UECSG_MASK               (0x40000U)
#define S50_ELS_KS5_KS5_UECSG_SHIFT              (18U)
#define S50_ELS_KS5_KS5_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UECSG_SHIFT)) & S50_ELS_KS5_KS5_UECSG_MASK)

#define S50_ELS_KS5_KS5_UECDH_MASK               (0x80000U)
#define S50_ELS_KS5_KS5_UECDH_SHIFT              (19U)
#define S50_ELS_KS5_KS5_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UECDH_SHIFT)) & S50_ELS_KS5_KS5_UECDH_MASK)

#define S50_ELS_KS5_KS5_UAES_MASK                (0x100000U)
#define S50_ELS_KS5_KS5_UAES_SHIFT               (20U)
#define S50_ELS_KS5_KS5_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UAES_SHIFT)) & S50_ELS_KS5_KS5_UAES_MASK)

#define S50_ELS_KS5_KS5_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS5_KS5_UHMAC_SHIFT              (21U)
#define S50_ELS_KS5_KS5_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UHMAC_SHIFT)) & S50_ELS_KS5_KS5_UHMAC_MASK)

#define S50_ELS_KS5_KS5_UKWK_MASK                (0x400000U)
#define S50_ELS_KS5_KS5_UKWK_SHIFT               (22U)
#define S50_ELS_KS5_KS5_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKWK_SHIFT)) & S50_ELS_KS5_KS5_UKWK_MASK)

#define S50_ELS_KS5_KS5_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS5_KS5_UKUOK_SHIFT              (23U)
#define S50_ELS_KS5_KS5_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKUOK_SHIFT)) & S50_ELS_KS5_KS5_UKUOK_MASK)

#define S50_ELS_KS5_KS5_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS5_KS5_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS5_KS5_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UTLSPMS_SHIFT)) & S50_ELS_KS5_KS5_UTLSPMS_MASK)

#define S50_ELS_KS5_KS5_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS5_KS5_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS5_KS5_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UTLSMS_SHIFT)) & S50_ELS_KS5_KS5_UTLSMS_MASK)

#define S50_ELS_KS5_KS5_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS5_KS5_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS5_KS5_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKGSRC_SHIFT)) & S50_ELS_KS5_KS5_UKGSRC_MASK)

#define S50_ELS_KS5_KS5_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS5_KS5_UHWO_SHIFT               (27U)
#define S50_ELS_KS5_KS5_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UHWO_SHIFT)) & S50_ELS_KS5_KS5_UHWO_MASK)

#define S50_ELS_KS5_KS5_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS5_KS5_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS5_KS5_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UWRPOK_SHIFT)) & S50_ELS_KS5_KS5_UWRPOK_MASK)

#define S50_ELS_KS5_KS5_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS5_KS5_UDUK_SHIFT               (29U)
#define S50_ELS_KS5_KS5_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UDUK_SHIFT)) & S50_ELS_KS5_KS5_UDUK_MASK)

#define S50_ELS_KS5_KS5_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS5_KS5_UPPROT_SHIFT             (30U)
#define S50_ELS_KS5_KS5_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UPPROT_SHIFT)) & S50_ELS_KS5_KS5_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS6 - Status Register */
/*! @{ */

#define S50_ELS_KS6_KS6_KSIZE_MASK               (0x3U)
#define S50_ELS_KS6_KS6_KSIZE_SHIFT              (0U)
/*! KS6_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS6_KS6_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_KSIZE_SHIFT)) & S50_ELS_KS6_KS6_KSIZE_MASK)

#define S50_ELS_KS6_KS6_KACT_MASK                (0x20U)
#define S50_ELS_KS6_KS6_KACT_SHIFT               (5U)
#define S50_ELS_KS6_KS6_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_KACT_SHIFT)) & S50_ELS_KS6_KS6_KACT_MASK)

#define S50_ELS_KS6_KS6_KBASE_MASK               (0x40U)
#define S50_ELS_KS6_KS6_KBASE_SHIFT              (6U)
#define S50_ELS_KS6_KS6_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_KBASE_SHIFT)) & S50_ELS_KS6_KS6_KBASE_MASK)

#define S50_ELS_KS6_KS6_FGP_MASK                 (0x80U)
#define S50_ELS_KS6_KS6_FGP_SHIFT                (7U)
#define S50_ELS_KS6_KS6_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_FGP_SHIFT)) & S50_ELS_KS6_KS6_FGP_MASK)

#define S50_ELS_KS6_KS6_FRTN_MASK                (0x100U)
#define S50_ELS_KS6_KS6_FRTN_SHIFT               (8U)
#define S50_ELS_KS6_KS6_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_FRTN_SHIFT)) & S50_ELS_KS6_KS6_FRTN_MASK)

#define S50_ELS_KS6_KS6_FHWO_MASK                (0x200U)
#define S50_ELS_KS6_KS6_FHWO_SHIFT               (9U)
#define S50_ELS_KS6_KS6_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_FHWO_SHIFT)) & S50_ELS_KS6_KS6_FHWO_MASK)

#define S50_ELS_KS6_KS6_UKPUK_MASK               (0x800U)
#define S50_ELS_KS6_KS6_UKPUK_SHIFT              (11U)
#define S50_ELS_KS6_KS6_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKPUK_SHIFT)) & S50_ELS_KS6_KS6_UKPUK_MASK)

#define S50_ELS_KS6_KS6_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS6_KS6_UTECDH_SHIFT             (12U)
#define S50_ELS_KS6_KS6_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UTECDH_SHIFT)) & S50_ELS_KS6_KS6_UTECDH_MASK)

#define S50_ELS_KS6_KS6_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS6_KS6_UCMAC_SHIFT              (13U)
#define S50_ELS_KS6_KS6_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UCMAC_SHIFT)) & S50_ELS_KS6_KS6_UCMAC_MASK)

#define S50_ELS_KS6_KS6_UKSK_MASK                (0x4000U)
#define S50_ELS_KS6_KS6_UKSK_SHIFT               (14U)
#define S50_ELS_KS6_KS6_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKSK_SHIFT)) & S50_ELS_KS6_KS6_UKSK_MASK)

#define S50_ELS_KS6_KS6_URTF_MASK                (0x8000U)
#define S50_ELS_KS6_KS6_URTF_SHIFT               (15U)
#define S50_ELS_KS6_KS6_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_URTF_SHIFT)) & S50_ELS_KS6_KS6_URTF_MASK)

#define S50_ELS_KS6_KS6_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS6_KS6_UCKDF_SHIFT              (16U)
#define S50_ELS_KS6_KS6_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UCKDF_SHIFT)) & S50_ELS_KS6_KS6_UCKDF_MASK)

#define S50_ELS_KS6_KS6_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS6_KS6_UHKDF_SHIFT              (17U)
#define S50_ELS_KS6_KS6_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UHKDF_SHIFT)) & S50_ELS_KS6_KS6_UHKDF_MASK)

#define S50_ELS_KS6_KS6_UECSG_MASK               (0x40000U)
#define S50_ELS_KS6_KS6_UECSG_SHIFT              (18U)
#define S50_ELS_KS6_KS6_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UECSG_SHIFT)) & S50_ELS_KS6_KS6_UECSG_MASK)

#define S50_ELS_KS6_KS6_UECDH_MASK               (0x80000U)
#define S50_ELS_KS6_KS6_UECDH_SHIFT              (19U)
#define S50_ELS_KS6_KS6_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UECDH_SHIFT)) & S50_ELS_KS6_KS6_UECDH_MASK)

#define S50_ELS_KS6_KS6_UAES_MASK                (0x100000U)
#define S50_ELS_KS6_KS6_UAES_SHIFT               (20U)
#define S50_ELS_KS6_KS6_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UAES_SHIFT)) & S50_ELS_KS6_KS6_UAES_MASK)

#define S50_ELS_KS6_KS6_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS6_KS6_UHMAC_SHIFT              (21U)
#define S50_ELS_KS6_KS6_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UHMAC_SHIFT)) & S50_ELS_KS6_KS6_UHMAC_MASK)

#define S50_ELS_KS6_KS6_UKWK_MASK                (0x400000U)
#define S50_ELS_KS6_KS6_UKWK_SHIFT               (22U)
#define S50_ELS_KS6_KS6_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKWK_SHIFT)) & S50_ELS_KS6_KS6_UKWK_MASK)

#define S50_ELS_KS6_KS6_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS6_KS6_UKUOK_SHIFT              (23U)
#define S50_ELS_KS6_KS6_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKUOK_SHIFT)) & S50_ELS_KS6_KS6_UKUOK_MASK)

#define S50_ELS_KS6_KS6_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS6_KS6_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS6_KS6_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UTLSPMS_SHIFT)) & S50_ELS_KS6_KS6_UTLSPMS_MASK)

#define S50_ELS_KS6_KS6_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS6_KS6_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS6_KS6_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UTLSMS_SHIFT)) & S50_ELS_KS6_KS6_UTLSMS_MASK)

#define S50_ELS_KS6_KS6_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS6_KS6_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS6_KS6_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKGSRC_SHIFT)) & S50_ELS_KS6_KS6_UKGSRC_MASK)

#define S50_ELS_KS6_KS6_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS6_KS6_UHWO_SHIFT               (27U)
#define S50_ELS_KS6_KS6_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UHWO_SHIFT)) & S50_ELS_KS6_KS6_UHWO_MASK)

#define S50_ELS_KS6_KS6_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS6_KS6_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS6_KS6_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UWRPOK_SHIFT)) & S50_ELS_KS6_KS6_UWRPOK_MASK)

#define S50_ELS_KS6_KS6_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS6_KS6_UDUK_SHIFT               (29U)
#define S50_ELS_KS6_KS6_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UDUK_SHIFT)) & S50_ELS_KS6_KS6_UDUK_MASK)

#define S50_ELS_KS6_KS6_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS6_KS6_UPPROT_SHIFT             (30U)
#define S50_ELS_KS6_KS6_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UPPROT_SHIFT)) & S50_ELS_KS6_KS6_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS7 - Status Register */
/*! @{ */

#define S50_ELS_KS7_KS7_KSIZE_MASK               (0x3U)
#define S50_ELS_KS7_KS7_KSIZE_SHIFT              (0U)
/*! KS7_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS7_KS7_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_KSIZE_SHIFT)) & S50_ELS_KS7_KS7_KSIZE_MASK)

#define S50_ELS_KS7_KS7_KACT_MASK                (0x20U)
#define S50_ELS_KS7_KS7_KACT_SHIFT               (5U)
#define S50_ELS_KS7_KS7_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_KACT_SHIFT)) & S50_ELS_KS7_KS7_KACT_MASK)

#define S50_ELS_KS7_KS7_KBASE_MASK               (0x40U)
#define S50_ELS_KS7_KS7_KBASE_SHIFT              (6U)
#define S50_ELS_KS7_KS7_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_KBASE_SHIFT)) & S50_ELS_KS7_KS7_KBASE_MASK)

#define S50_ELS_KS7_KS7_FGP_MASK                 (0x80U)
#define S50_ELS_KS7_KS7_FGP_SHIFT                (7U)
#define S50_ELS_KS7_KS7_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_FGP_SHIFT)) & S50_ELS_KS7_KS7_FGP_MASK)

#define S50_ELS_KS7_KS7_FRTN_MASK                (0x100U)
#define S50_ELS_KS7_KS7_FRTN_SHIFT               (8U)
#define S50_ELS_KS7_KS7_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_FRTN_SHIFT)) & S50_ELS_KS7_KS7_FRTN_MASK)

#define S50_ELS_KS7_KS7_FHWO_MASK                (0x200U)
#define S50_ELS_KS7_KS7_FHWO_SHIFT               (9U)
#define S50_ELS_KS7_KS7_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_FHWO_SHIFT)) & S50_ELS_KS7_KS7_FHWO_MASK)

#define S50_ELS_KS7_KS7_UKPUK_MASK               (0x800U)
#define S50_ELS_KS7_KS7_UKPUK_SHIFT              (11U)
#define S50_ELS_KS7_KS7_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKPUK_SHIFT)) & S50_ELS_KS7_KS7_UKPUK_MASK)

#define S50_ELS_KS7_KS7_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS7_KS7_UTECDH_SHIFT             (12U)
#define S50_ELS_KS7_KS7_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UTECDH_SHIFT)) & S50_ELS_KS7_KS7_UTECDH_MASK)

#define S50_ELS_KS7_KS7_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS7_KS7_UCMAC_SHIFT              (13U)
#define S50_ELS_KS7_KS7_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UCMAC_SHIFT)) & S50_ELS_KS7_KS7_UCMAC_MASK)

#define S50_ELS_KS7_KS7_UKSK_MASK                (0x4000U)
#define S50_ELS_KS7_KS7_UKSK_SHIFT               (14U)
#define S50_ELS_KS7_KS7_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKSK_SHIFT)) & S50_ELS_KS7_KS7_UKSK_MASK)

#define S50_ELS_KS7_KS7_URTF_MASK                (0x8000U)
#define S50_ELS_KS7_KS7_URTF_SHIFT               (15U)
#define S50_ELS_KS7_KS7_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_URTF_SHIFT)) & S50_ELS_KS7_KS7_URTF_MASK)

#define S50_ELS_KS7_KS7_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS7_KS7_UCKDF_SHIFT              (16U)
#define S50_ELS_KS7_KS7_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UCKDF_SHIFT)) & S50_ELS_KS7_KS7_UCKDF_MASK)

#define S50_ELS_KS7_KS7_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS7_KS7_UHKDF_SHIFT              (17U)
#define S50_ELS_KS7_KS7_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UHKDF_SHIFT)) & S50_ELS_KS7_KS7_UHKDF_MASK)

#define S50_ELS_KS7_KS7_UECSG_MASK               (0x40000U)
#define S50_ELS_KS7_KS7_UECSG_SHIFT              (18U)
#define S50_ELS_KS7_KS7_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UECSG_SHIFT)) & S50_ELS_KS7_KS7_UECSG_MASK)

#define S50_ELS_KS7_KS7_UECDH_MASK               (0x80000U)
#define S50_ELS_KS7_KS7_UECDH_SHIFT              (19U)
#define S50_ELS_KS7_KS7_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UECDH_SHIFT)) & S50_ELS_KS7_KS7_UECDH_MASK)

#define S50_ELS_KS7_KS7_UAES_MASK                (0x100000U)
#define S50_ELS_KS7_KS7_UAES_SHIFT               (20U)
#define S50_ELS_KS7_KS7_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UAES_SHIFT)) & S50_ELS_KS7_KS7_UAES_MASK)

#define S50_ELS_KS7_KS7_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS7_KS7_UHMAC_SHIFT              (21U)
#define S50_ELS_KS7_KS7_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UHMAC_SHIFT)) & S50_ELS_KS7_KS7_UHMAC_MASK)

#define S50_ELS_KS7_KS7_UKWK_MASK                (0x400000U)
#define S50_ELS_KS7_KS7_UKWK_SHIFT               (22U)
#define S50_ELS_KS7_KS7_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKWK_SHIFT)) & S50_ELS_KS7_KS7_UKWK_MASK)

#define S50_ELS_KS7_KS7_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS7_KS7_UKUOK_SHIFT              (23U)
#define S50_ELS_KS7_KS7_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKUOK_SHIFT)) & S50_ELS_KS7_KS7_UKUOK_MASK)

#define S50_ELS_KS7_KS7_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS7_KS7_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS7_KS7_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UTLSPMS_SHIFT)) & S50_ELS_KS7_KS7_UTLSPMS_MASK)

#define S50_ELS_KS7_KS7_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS7_KS7_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS7_KS7_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UTLSMS_SHIFT)) & S50_ELS_KS7_KS7_UTLSMS_MASK)

#define S50_ELS_KS7_KS7_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS7_KS7_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS7_KS7_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKGSRC_SHIFT)) & S50_ELS_KS7_KS7_UKGSRC_MASK)

#define S50_ELS_KS7_KS7_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS7_KS7_UHWO_SHIFT               (27U)
#define S50_ELS_KS7_KS7_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UHWO_SHIFT)) & S50_ELS_KS7_KS7_UHWO_MASK)

#define S50_ELS_KS7_KS7_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS7_KS7_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS7_KS7_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UWRPOK_SHIFT)) & S50_ELS_KS7_KS7_UWRPOK_MASK)

#define S50_ELS_KS7_KS7_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS7_KS7_UDUK_SHIFT               (29U)
#define S50_ELS_KS7_KS7_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UDUK_SHIFT)) & S50_ELS_KS7_KS7_UDUK_MASK)

#define S50_ELS_KS7_KS7_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS7_KS7_UPPROT_SHIFT             (30U)
#define S50_ELS_KS7_KS7_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UPPROT_SHIFT)) & S50_ELS_KS7_KS7_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS8 - Status Register */
/*! @{ */

#define S50_ELS_KS8_KS8_KSIZE_MASK               (0x3U)
#define S50_ELS_KS8_KS8_KSIZE_SHIFT              (0U)
/*! KS8_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS8_KS8_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_KSIZE_SHIFT)) & S50_ELS_KS8_KS8_KSIZE_MASK)

#define S50_ELS_KS8_KS8_KACT_MASK                (0x20U)
#define S50_ELS_KS8_KS8_KACT_SHIFT               (5U)
#define S50_ELS_KS8_KS8_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_KACT_SHIFT)) & S50_ELS_KS8_KS8_KACT_MASK)

#define S50_ELS_KS8_KS8_KBASE_MASK               (0x40U)
#define S50_ELS_KS8_KS8_KBASE_SHIFT              (6U)
#define S50_ELS_KS8_KS8_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_KBASE_SHIFT)) & S50_ELS_KS8_KS8_KBASE_MASK)

#define S50_ELS_KS8_KS8_FGP_MASK                 (0x80U)
#define S50_ELS_KS8_KS8_FGP_SHIFT                (7U)
#define S50_ELS_KS8_KS8_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_FGP_SHIFT)) & S50_ELS_KS8_KS8_FGP_MASK)

#define S50_ELS_KS8_KS8_FRTN_MASK                (0x100U)
#define S50_ELS_KS8_KS8_FRTN_SHIFT               (8U)
#define S50_ELS_KS8_KS8_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_FRTN_SHIFT)) & S50_ELS_KS8_KS8_FRTN_MASK)

#define S50_ELS_KS8_KS8_FHWO_MASK                (0x200U)
#define S50_ELS_KS8_KS8_FHWO_SHIFT               (9U)
#define S50_ELS_KS8_KS8_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_FHWO_SHIFT)) & S50_ELS_KS8_KS8_FHWO_MASK)

#define S50_ELS_KS8_KS8_UKPUK_MASK               (0x800U)
#define S50_ELS_KS8_KS8_UKPUK_SHIFT              (11U)
#define S50_ELS_KS8_KS8_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKPUK_SHIFT)) & S50_ELS_KS8_KS8_UKPUK_MASK)

#define S50_ELS_KS8_KS8_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS8_KS8_UTECDH_SHIFT             (12U)
#define S50_ELS_KS8_KS8_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UTECDH_SHIFT)) & S50_ELS_KS8_KS8_UTECDH_MASK)

#define S50_ELS_KS8_KS8_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS8_KS8_UCMAC_SHIFT              (13U)
#define S50_ELS_KS8_KS8_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UCMAC_SHIFT)) & S50_ELS_KS8_KS8_UCMAC_MASK)

#define S50_ELS_KS8_KS8_UKSK_MASK                (0x4000U)
#define S50_ELS_KS8_KS8_UKSK_SHIFT               (14U)
#define S50_ELS_KS8_KS8_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKSK_SHIFT)) & S50_ELS_KS8_KS8_UKSK_MASK)

#define S50_ELS_KS8_KS8_URTF_MASK                (0x8000U)
#define S50_ELS_KS8_KS8_URTF_SHIFT               (15U)
#define S50_ELS_KS8_KS8_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_URTF_SHIFT)) & S50_ELS_KS8_KS8_URTF_MASK)

#define S50_ELS_KS8_KS8_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS8_KS8_UCKDF_SHIFT              (16U)
#define S50_ELS_KS8_KS8_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UCKDF_SHIFT)) & S50_ELS_KS8_KS8_UCKDF_MASK)

#define S50_ELS_KS8_KS8_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS8_KS8_UHKDF_SHIFT              (17U)
#define S50_ELS_KS8_KS8_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UHKDF_SHIFT)) & S50_ELS_KS8_KS8_UHKDF_MASK)

#define S50_ELS_KS8_KS8_UECSG_MASK               (0x40000U)
#define S50_ELS_KS8_KS8_UECSG_SHIFT              (18U)
#define S50_ELS_KS8_KS8_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UECSG_SHIFT)) & S50_ELS_KS8_KS8_UECSG_MASK)

#define S50_ELS_KS8_KS8_UECDH_MASK               (0x80000U)
#define S50_ELS_KS8_KS8_UECDH_SHIFT              (19U)
#define S50_ELS_KS8_KS8_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UECDH_SHIFT)) & S50_ELS_KS8_KS8_UECDH_MASK)

#define S50_ELS_KS8_KS8_UAES_MASK                (0x100000U)
#define S50_ELS_KS8_KS8_UAES_SHIFT               (20U)
#define S50_ELS_KS8_KS8_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UAES_SHIFT)) & S50_ELS_KS8_KS8_UAES_MASK)

#define S50_ELS_KS8_KS8_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS8_KS8_UHMAC_SHIFT              (21U)
#define S50_ELS_KS8_KS8_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UHMAC_SHIFT)) & S50_ELS_KS8_KS8_UHMAC_MASK)

#define S50_ELS_KS8_KS8_UKWK_MASK                (0x400000U)
#define S50_ELS_KS8_KS8_UKWK_SHIFT               (22U)
#define S50_ELS_KS8_KS8_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKWK_SHIFT)) & S50_ELS_KS8_KS8_UKWK_MASK)

#define S50_ELS_KS8_KS8_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS8_KS8_UKUOK_SHIFT              (23U)
#define S50_ELS_KS8_KS8_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKUOK_SHIFT)) & S50_ELS_KS8_KS8_UKUOK_MASK)

#define S50_ELS_KS8_KS8_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS8_KS8_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS8_KS8_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UTLSPMS_SHIFT)) & S50_ELS_KS8_KS8_UTLSPMS_MASK)

#define S50_ELS_KS8_KS8_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS8_KS8_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS8_KS8_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UTLSMS_SHIFT)) & S50_ELS_KS8_KS8_UTLSMS_MASK)

#define S50_ELS_KS8_KS8_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS8_KS8_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS8_KS8_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKGSRC_SHIFT)) & S50_ELS_KS8_KS8_UKGSRC_MASK)

#define S50_ELS_KS8_KS8_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS8_KS8_UHWO_SHIFT               (27U)
#define S50_ELS_KS8_KS8_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UHWO_SHIFT)) & S50_ELS_KS8_KS8_UHWO_MASK)

#define S50_ELS_KS8_KS8_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS8_KS8_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS8_KS8_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UWRPOK_SHIFT)) & S50_ELS_KS8_KS8_UWRPOK_MASK)

#define S50_ELS_KS8_KS8_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS8_KS8_UDUK_SHIFT               (29U)
#define S50_ELS_KS8_KS8_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UDUK_SHIFT)) & S50_ELS_KS8_KS8_UDUK_MASK)

#define S50_ELS_KS8_KS8_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS8_KS8_UPPROT_SHIFT             (30U)
#define S50_ELS_KS8_KS8_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UPPROT_SHIFT)) & S50_ELS_KS8_KS8_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS9 - Status Register */
/*! @{ */

#define S50_ELS_KS9_KS9_KSIZE_MASK               (0x3U)
#define S50_ELS_KS9_KS9_KSIZE_SHIFT              (0U)
/*! KS9_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS9_KS9_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_KSIZE_SHIFT)) & S50_ELS_KS9_KS9_KSIZE_MASK)

#define S50_ELS_KS9_KS9_KACT_MASK                (0x20U)
#define S50_ELS_KS9_KS9_KACT_SHIFT               (5U)
#define S50_ELS_KS9_KS9_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_KACT_SHIFT)) & S50_ELS_KS9_KS9_KACT_MASK)

#define S50_ELS_KS9_KS9_KBASE_MASK               (0x40U)
#define S50_ELS_KS9_KS9_KBASE_SHIFT              (6U)
#define S50_ELS_KS9_KS9_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_KBASE_SHIFT)) & S50_ELS_KS9_KS9_KBASE_MASK)

#define S50_ELS_KS9_KS9_FGP_MASK                 (0x80U)
#define S50_ELS_KS9_KS9_FGP_SHIFT                (7U)
#define S50_ELS_KS9_KS9_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_FGP_SHIFT)) & S50_ELS_KS9_KS9_FGP_MASK)

#define S50_ELS_KS9_KS9_FRTN_MASK                (0x100U)
#define S50_ELS_KS9_KS9_FRTN_SHIFT               (8U)
#define S50_ELS_KS9_KS9_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_FRTN_SHIFT)) & S50_ELS_KS9_KS9_FRTN_MASK)

#define S50_ELS_KS9_KS9_FHWO_MASK                (0x200U)
#define S50_ELS_KS9_KS9_FHWO_SHIFT               (9U)
#define S50_ELS_KS9_KS9_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_FHWO_SHIFT)) & S50_ELS_KS9_KS9_FHWO_MASK)

#define S50_ELS_KS9_KS9_UKPUK_MASK               (0x800U)
#define S50_ELS_KS9_KS9_UKPUK_SHIFT              (11U)
#define S50_ELS_KS9_KS9_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKPUK_SHIFT)) & S50_ELS_KS9_KS9_UKPUK_MASK)

#define S50_ELS_KS9_KS9_UTECDH_MASK              (0x1000U)
#define S50_ELS_KS9_KS9_UTECDH_SHIFT             (12U)
#define S50_ELS_KS9_KS9_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UTECDH_SHIFT)) & S50_ELS_KS9_KS9_UTECDH_MASK)

#define S50_ELS_KS9_KS9_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS9_KS9_UCMAC_SHIFT              (13U)
#define S50_ELS_KS9_KS9_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UCMAC_SHIFT)) & S50_ELS_KS9_KS9_UCMAC_MASK)

#define S50_ELS_KS9_KS9_UKSK_MASK                (0x4000U)
#define S50_ELS_KS9_KS9_UKSK_SHIFT               (14U)
#define S50_ELS_KS9_KS9_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKSK_SHIFT)) & S50_ELS_KS9_KS9_UKSK_MASK)

#define S50_ELS_KS9_KS9_URTF_MASK                (0x8000U)
#define S50_ELS_KS9_KS9_URTF_SHIFT               (15U)
#define S50_ELS_KS9_KS9_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_URTF_SHIFT)) & S50_ELS_KS9_KS9_URTF_MASK)

#define S50_ELS_KS9_KS9_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS9_KS9_UCKDF_SHIFT              (16U)
#define S50_ELS_KS9_KS9_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UCKDF_SHIFT)) & S50_ELS_KS9_KS9_UCKDF_MASK)

#define S50_ELS_KS9_KS9_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS9_KS9_UHKDF_SHIFT              (17U)
#define S50_ELS_KS9_KS9_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UHKDF_SHIFT)) & S50_ELS_KS9_KS9_UHKDF_MASK)

#define S50_ELS_KS9_KS9_UECSG_MASK               (0x40000U)
#define S50_ELS_KS9_KS9_UECSG_SHIFT              (18U)
#define S50_ELS_KS9_KS9_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UECSG_SHIFT)) & S50_ELS_KS9_KS9_UECSG_MASK)

#define S50_ELS_KS9_KS9_UECDH_MASK               (0x80000U)
#define S50_ELS_KS9_KS9_UECDH_SHIFT              (19U)
#define S50_ELS_KS9_KS9_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UECDH_SHIFT)) & S50_ELS_KS9_KS9_UECDH_MASK)

#define S50_ELS_KS9_KS9_UAES_MASK                (0x100000U)
#define S50_ELS_KS9_KS9_UAES_SHIFT               (20U)
#define S50_ELS_KS9_KS9_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UAES_SHIFT)) & S50_ELS_KS9_KS9_UAES_MASK)

#define S50_ELS_KS9_KS9_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS9_KS9_UHMAC_SHIFT              (21U)
#define S50_ELS_KS9_KS9_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UHMAC_SHIFT)) & S50_ELS_KS9_KS9_UHMAC_MASK)

#define S50_ELS_KS9_KS9_UKWK_MASK                (0x400000U)
#define S50_ELS_KS9_KS9_UKWK_SHIFT               (22U)
#define S50_ELS_KS9_KS9_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKWK_SHIFT)) & S50_ELS_KS9_KS9_UKWK_MASK)

#define S50_ELS_KS9_KS9_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS9_KS9_UKUOK_SHIFT              (23U)
#define S50_ELS_KS9_KS9_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKUOK_SHIFT)) & S50_ELS_KS9_KS9_UKUOK_MASK)

#define S50_ELS_KS9_KS9_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS9_KS9_UTLSPMS_SHIFT            (24U)
#define S50_ELS_KS9_KS9_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UTLSPMS_SHIFT)) & S50_ELS_KS9_KS9_UTLSPMS_MASK)

#define S50_ELS_KS9_KS9_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS9_KS9_UTLSMS_SHIFT             (25U)
#define S50_ELS_KS9_KS9_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UTLSMS_SHIFT)) & S50_ELS_KS9_KS9_UTLSMS_MASK)

#define S50_ELS_KS9_KS9_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS9_KS9_UKGSRC_SHIFT             (26U)
#define S50_ELS_KS9_KS9_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKGSRC_SHIFT)) & S50_ELS_KS9_KS9_UKGSRC_MASK)

#define S50_ELS_KS9_KS9_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS9_KS9_UHWO_SHIFT               (27U)
#define S50_ELS_KS9_KS9_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UHWO_SHIFT)) & S50_ELS_KS9_KS9_UHWO_MASK)

#define S50_ELS_KS9_KS9_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS9_KS9_UWRPOK_SHIFT             (28U)
#define S50_ELS_KS9_KS9_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UWRPOK_SHIFT)) & S50_ELS_KS9_KS9_UWRPOK_MASK)

#define S50_ELS_KS9_KS9_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS9_KS9_UDUK_SHIFT               (29U)
#define S50_ELS_KS9_KS9_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UDUK_SHIFT)) & S50_ELS_KS9_KS9_UDUK_MASK)

#define S50_ELS_KS9_KS9_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS9_KS9_UPPROT_SHIFT             (30U)
#define S50_ELS_KS9_KS9_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UPPROT_SHIFT)) & S50_ELS_KS9_KS9_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS10 - Status Register */
/*! @{ */

#define S50_ELS_KS10_KS10_KSIZE_MASK             (0x3U)
#define S50_ELS_KS10_KS10_KSIZE_SHIFT            (0U)
/*! KS10_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS10_KS10_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_KSIZE_SHIFT)) & S50_ELS_KS10_KS10_KSIZE_MASK)

#define S50_ELS_KS10_KS10_KACT_MASK              (0x20U)
#define S50_ELS_KS10_KS10_KACT_SHIFT             (5U)
#define S50_ELS_KS10_KS10_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_KACT_SHIFT)) & S50_ELS_KS10_KS10_KACT_MASK)

#define S50_ELS_KS10_KS10_KBASE_MASK             (0x40U)
#define S50_ELS_KS10_KS10_KBASE_SHIFT            (6U)
#define S50_ELS_KS10_KS10_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_KBASE_SHIFT)) & S50_ELS_KS10_KS10_KBASE_MASK)

#define S50_ELS_KS10_KS10_FGP_MASK               (0x80U)
#define S50_ELS_KS10_KS10_FGP_SHIFT              (7U)
#define S50_ELS_KS10_KS10_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_FGP_SHIFT)) & S50_ELS_KS10_KS10_FGP_MASK)

#define S50_ELS_KS10_KS10_FRTN_MASK              (0x100U)
#define S50_ELS_KS10_KS10_FRTN_SHIFT             (8U)
#define S50_ELS_KS10_KS10_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_FRTN_SHIFT)) & S50_ELS_KS10_KS10_FRTN_MASK)

#define S50_ELS_KS10_KS10_FHWO_MASK              (0x200U)
#define S50_ELS_KS10_KS10_FHWO_SHIFT             (9U)
#define S50_ELS_KS10_KS10_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_FHWO_SHIFT)) & S50_ELS_KS10_KS10_FHWO_MASK)

#define S50_ELS_KS10_KS10_UKPUK_MASK             (0x800U)
#define S50_ELS_KS10_KS10_UKPUK_SHIFT            (11U)
#define S50_ELS_KS10_KS10_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKPUK_SHIFT)) & S50_ELS_KS10_KS10_UKPUK_MASK)

#define S50_ELS_KS10_KS10_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS10_KS10_UTECDH_SHIFT           (12U)
#define S50_ELS_KS10_KS10_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UTECDH_SHIFT)) & S50_ELS_KS10_KS10_UTECDH_MASK)

#define S50_ELS_KS10_KS10_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS10_KS10_UCMAC_SHIFT            (13U)
#define S50_ELS_KS10_KS10_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UCMAC_SHIFT)) & S50_ELS_KS10_KS10_UCMAC_MASK)

#define S50_ELS_KS10_KS10_UKSK_MASK              (0x4000U)
#define S50_ELS_KS10_KS10_UKSK_SHIFT             (14U)
#define S50_ELS_KS10_KS10_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKSK_SHIFT)) & S50_ELS_KS10_KS10_UKSK_MASK)

#define S50_ELS_KS10_KS10_URTF_MASK              (0x8000U)
#define S50_ELS_KS10_KS10_URTF_SHIFT             (15U)
#define S50_ELS_KS10_KS10_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_URTF_SHIFT)) & S50_ELS_KS10_KS10_URTF_MASK)

#define S50_ELS_KS10_KS10_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS10_KS10_UCKDF_SHIFT            (16U)
#define S50_ELS_KS10_KS10_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UCKDF_SHIFT)) & S50_ELS_KS10_KS10_UCKDF_MASK)

#define S50_ELS_KS10_KS10_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS10_KS10_UHKDF_SHIFT            (17U)
#define S50_ELS_KS10_KS10_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UHKDF_SHIFT)) & S50_ELS_KS10_KS10_UHKDF_MASK)

#define S50_ELS_KS10_KS10_UECSG_MASK             (0x40000U)
#define S50_ELS_KS10_KS10_UECSG_SHIFT            (18U)
#define S50_ELS_KS10_KS10_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UECSG_SHIFT)) & S50_ELS_KS10_KS10_UECSG_MASK)

#define S50_ELS_KS10_KS10_UECDH_MASK             (0x80000U)
#define S50_ELS_KS10_KS10_UECDH_SHIFT            (19U)
#define S50_ELS_KS10_KS10_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UECDH_SHIFT)) & S50_ELS_KS10_KS10_UECDH_MASK)

#define S50_ELS_KS10_KS10_UAES_MASK              (0x100000U)
#define S50_ELS_KS10_KS10_UAES_SHIFT             (20U)
#define S50_ELS_KS10_KS10_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UAES_SHIFT)) & S50_ELS_KS10_KS10_UAES_MASK)

#define S50_ELS_KS10_KS10_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS10_KS10_UHMAC_SHIFT            (21U)
#define S50_ELS_KS10_KS10_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UHMAC_SHIFT)) & S50_ELS_KS10_KS10_UHMAC_MASK)

#define S50_ELS_KS10_KS10_UKWK_MASK              (0x400000U)
#define S50_ELS_KS10_KS10_UKWK_SHIFT             (22U)
#define S50_ELS_KS10_KS10_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKWK_SHIFT)) & S50_ELS_KS10_KS10_UKWK_MASK)

#define S50_ELS_KS10_KS10_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS10_KS10_UKUOK_SHIFT            (23U)
#define S50_ELS_KS10_KS10_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKUOK_SHIFT)) & S50_ELS_KS10_KS10_UKUOK_MASK)

#define S50_ELS_KS10_KS10_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS10_KS10_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS10_KS10_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UTLSPMS_SHIFT)) & S50_ELS_KS10_KS10_UTLSPMS_MASK)

#define S50_ELS_KS10_KS10_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS10_KS10_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS10_KS10_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UTLSMS_SHIFT)) & S50_ELS_KS10_KS10_UTLSMS_MASK)

#define S50_ELS_KS10_KS10_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS10_KS10_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS10_KS10_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKGSRC_SHIFT)) & S50_ELS_KS10_KS10_UKGSRC_MASK)

#define S50_ELS_KS10_KS10_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS10_KS10_UHWO_SHIFT             (27U)
#define S50_ELS_KS10_KS10_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UHWO_SHIFT)) & S50_ELS_KS10_KS10_UHWO_MASK)

#define S50_ELS_KS10_KS10_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS10_KS10_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS10_KS10_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UWRPOK_SHIFT)) & S50_ELS_KS10_KS10_UWRPOK_MASK)

#define S50_ELS_KS10_KS10_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS10_KS10_UDUK_SHIFT             (29U)
#define S50_ELS_KS10_KS10_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UDUK_SHIFT)) & S50_ELS_KS10_KS10_UDUK_MASK)

#define S50_ELS_KS10_KS10_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS10_KS10_UPPROT_SHIFT           (30U)
#define S50_ELS_KS10_KS10_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UPPROT_SHIFT)) & S50_ELS_KS10_KS10_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS11 - Status Register */
/*! @{ */

#define S50_ELS_KS11_KS11_KSIZE_MASK             (0x3U)
#define S50_ELS_KS11_KS11_KSIZE_SHIFT            (0U)
/*! KS11_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS11_KS11_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_KSIZE_SHIFT)) & S50_ELS_KS11_KS11_KSIZE_MASK)

#define S50_ELS_KS11_KS11_KACT_MASK              (0x20U)
#define S50_ELS_KS11_KS11_KACT_SHIFT             (5U)
#define S50_ELS_KS11_KS11_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_KACT_SHIFT)) & S50_ELS_KS11_KS11_KACT_MASK)

#define S50_ELS_KS11_KS11_KBASE_MASK             (0x40U)
#define S50_ELS_KS11_KS11_KBASE_SHIFT            (6U)
#define S50_ELS_KS11_KS11_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_KBASE_SHIFT)) & S50_ELS_KS11_KS11_KBASE_MASK)

#define S50_ELS_KS11_KS11_FGP_MASK               (0x80U)
#define S50_ELS_KS11_KS11_FGP_SHIFT              (7U)
#define S50_ELS_KS11_KS11_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_FGP_SHIFT)) & S50_ELS_KS11_KS11_FGP_MASK)

#define S50_ELS_KS11_KS11_FRTN_MASK              (0x100U)
#define S50_ELS_KS11_KS11_FRTN_SHIFT             (8U)
#define S50_ELS_KS11_KS11_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_FRTN_SHIFT)) & S50_ELS_KS11_KS11_FRTN_MASK)

#define S50_ELS_KS11_KS11_FHWO_MASK              (0x200U)
#define S50_ELS_KS11_KS11_FHWO_SHIFT             (9U)
#define S50_ELS_KS11_KS11_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_FHWO_SHIFT)) & S50_ELS_KS11_KS11_FHWO_MASK)

#define S50_ELS_KS11_KS11_UKPUK_MASK             (0x800U)
#define S50_ELS_KS11_KS11_UKPUK_SHIFT            (11U)
#define S50_ELS_KS11_KS11_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKPUK_SHIFT)) & S50_ELS_KS11_KS11_UKPUK_MASK)

#define S50_ELS_KS11_KS11_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS11_KS11_UTECDH_SHIFT           (12U)
#define S50_ELS_KS11_KS11_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UTECDH_SHIFT)) & S50_ELS_KS11_KS11_UTECDH_MASK)

#define S50_ELS_KS11_KS11_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS11_KS11_UCMAC_SHIFT            (13U)
#define S50_ELS_KS11_KS11_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UCMAC_SHIFT)) & S50_ELS_KS11_KS11_UCMAC_MASK)

#define S50_ELS_KS11_KS11_UKSK_MASK              (0x4000U)
#define S50_ELS_KS11_KS11_UKSK_SHIFT             (14U)
#define S50_ELS_KS11_KS11_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKSK_SHIFT)) & S50_ELS_KS11_KS11_UKSK_MASK)

#define S50_ELS_KS11_KS11_URTF_MASK              (0x8000U)
#define S50_ELS_KS11_KS11_URTF_SHIFT             (15U)
#define S50_ELS_KS11_KS11_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_URTF_SHIFT)) & S50_ELS_KS11_KS11_URTF_MASK)

#define S50_ELS_KS11_KS11_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS11_KS11_UCKDF_SHIFT            (16U)
#define S50_ELS_KS11_KS11_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UCKDF_SHIFT)) & S50_ELS_KS11_KS11_UCKDF_MASK)

#define S50_ELS_KS11_KS11_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS11_KS11_UHKDF_SHIFT            (17U)
#define S50_ELS_KS11_KS11_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UHKDF_SHIFT)) & S50_ELS_KS11_KS11_UHKDF_MASK)

#define S50_ELS_KS11_KS11_UECSG_MASK             (0x40000U)
#define S50_ELS_KS11_KS11_UECSG_SHIFT            (18U)
#define S50_ELS_KS11_KS11_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UECSG_SHIFT)) & S50_ELS_KS11_KS11_UECSG_MASK)

#define S50_ELS_KS11_KS11_UECDH_MASK             (0x80000U)
#define S50_ELS_KS11_KS11_UECDH_SHIFT            (19U)
#define S50_ELS_KS11_KS11_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UECDH_SHIFT)) & S50_ELS_KS11_KS11_UECDH_MASK)

#define S50_ELS_KS11_KS11_UAES_MASK              (0x100000U)
#define S50_ELS_KS11_KS11_UAES_SHIFT             (20U)
#define S50_ELS_KS11_KS11_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UAES_SHIFT)) & S50_ELS_KS11_KS11_UAES_MASK)

#define S50_ELS_KS11_KS11_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS11_KS11_UHMAC_SHIFT            (21U)
#define S50_ELS_KS11_KS11_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UHMAC_SHIFT)) & S50_ELS_KS11_KS11_UHMAC_MASK)

#define S50_ELS_KS11_KS11_UKWK_MASK              (0x400000U)
#define S50_ELS_KS11_KS11_UKWK_SHIFT             (22U)
#define S50_ELS_KS11_KS11_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKWK_SHIFT)) & S50_ELS_KS11_KS11_UKWK_MASK)

#define S50_ELS_KS11_KS11_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS11_KS11_UKUOK_SHIFT            (23U)
#define S50_ELS_KS11_KS11_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKUOK_SHIFT)) & S50_ELS_KS11_KS11_UKUOK_MASK)

#define S50_ELS_KS11_KS11_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS11_KS11_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS11_KS11_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UTLSPMS_SHIFT)) & S50_ELS_KS11_KS11_UTLSPMS_MASK)

#define S50_ELS_KS11_KS11_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS11_KS11_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS11_KS11_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UTLSMS_SHIFT)) & S50_ELS_KS11_KS11_UTLSMS_MASK)

#define S50_ELS_KS11_KS11_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS11_KS11_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS11_KS11_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKGSRC_SHIFT)) & S50_ELS_KS11_KS11_UKGSRC_MASK)

#define S50_ELS_KS11_KS11_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS11_KS11_UHWO_SHIFT             (27U)
#define S50_ELS_KS11_KS11_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UHWO_SHIFT)) & S50_ELS_KS11_KS11_UHWO_MASK)

#define S50_ELS_KS11_KS11_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS11_KS11_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS11_KS11_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UWRPOK_SHIFT)) & S50_ELS_KS11_KS11_UWRPOK_MASK)

#define S50_ELS_KS11_KS11_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS11_KS11_UDUK_SHIFT             (29U)
#define S50_ELS_KS11_KS11_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UDUK_SHIFT)) & S50_ELS_KS11_KS11_UDUK_MASK)

#define S50_ELS_KS11_KS11_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS11_KS11_UPPROT_SHIFT           (30U)
#define S50_ELS_KS11_KS11_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UPPROT_SHIFT)) & S50_ELS_KS11_KS11_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS12 - Status Register */
/*! @{ */

#define S50_ELS_KS12_KS12_KSIZE_MASK             (0x3U)
#define S50_ELS_KS12_KS12_KSIZE_SHIFT            (0U)
/*! KS12_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS12_KS12_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_KSIZE_SHIFT)) & S50_ELS_KS12_KS12_KSIZE_MASK)

#define S50_ELS_KS12_KS12_KACT_MASK              (0x20U)
#define S50_ELS_KS12_KS12_KACT_SHIFT             (5U)
#define S50_ELS_KS12_KS12_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_KACT_SHIFT)) & S50_ELS_KS12_KS12_KACT_MASK)

#define S50_ELS_KS12_KS12_KBASE_MASK             (0x40U)
#define S50_ELS_KS12_KS12_KBASE_SHIFT            (6U)
#define S50_ELS_KS12_KS12_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_KBASE_SHIFT)) & S50_ELS_KS12_KS12_KBASE_MASK)

#define S50_ELS_KS12_KS12_FGP_MASK               (0x80U)
#define S50_ELS_KS12_KS12_FGP_SHIFT              (7U)
#define S50_ELS_KS12_KS12_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_FGP_SHIFT)) & S50_ELS_KS12_KS12_FGP_MASK)

#define S50_ELS_KS12_KS12_FRTN_MASK              (0x100U)
#define S50_ELS_KS12_KS12_FRTN_SHIFT             (8U)
#define S50_ELS_KS12_KS12_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_FRTN_SHIFT)) & S50_ELS_KS12_KS12_FRTN_MASK)

#define S50_ELS_KS12_KS12_FHWO_MASK              (0x200U)
#define S50_ELS_KS12_KS12_FHWO_SHIFT             (9U)
#define S50_ELS_KS12_KS12_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_FHWO_SHIFT)) & S50_ELS_KS12_KS12_FHWO_MASK)

#define S50_ELS_KS12_KS12_UKPUK_MASK             (0x800U)
#define S50_ELS_KS12_KS12_UKPUK_SHIFT            (11U)
#define S50_ELS_KS12_KS12_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKPUK_SHIFT)) & S50_ELS_KS12_KS12_UKPUK_MASK)

#define S50_ELS_KS12_KS12_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS12_KS12_UTECDH_SHIFT           (12U)
#define S50_ELS_KS12_KS12_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UTECDH_SHIFT)) & S50_ELS_KS12_KS12_UTECDH_MASK)

#define S50_ELS_KS12_KS12_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS12_KS12_UCMAC_SHIFT            (13U)
#define S50_ELS_KS12_KS12_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UCMAC_SHIFT)) & S50_ELS_KS12_KS12_UCMAC_MASK)

#define S50_ELS_KS12_KS12_UKSK_MASK              (0x4000U)
#define S50_ELS_KS12_KS12_UKSK_SHIFT             (14U)
#define S50_ELS_KS12_KS12_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKSK_SHIFT)) & S50_ELS_KS12_KS12_UKSK_MASK)

#define S50_ELS_KS12_KS12_URTF_MASK              (0x8000U)
#define S50_ELS_KS12_KS12_URTF_SHIFT             (15U)
#define S50_ELS_KS12_KS12_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_URTF_SHIFT)) & S50_ELS_KS12_KS12_URTF_MASK)

#define S50_ELS_KS12_KS12_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS12_KS12_UCKDF_SHIFT            (16U)
#define S50_ELS_KS12_KS12_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UCKDF_SHIFT)) & S50_ELS_KS12_KS12_UCKDF_MASK)

#define S50_ELS_KS12_KS12_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS12_KS12_UHKDF_SHIFT            (17U)
#define S50_ELS_KS12_KS12_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UHKDF_SHIFT)) & S50_ELS_KS12_KS12_UHKDF_MASK)

#define S50_ELS_KS12_KS12_UECSG_MASK             (0x40000U)
#define S50_ELS_KS12_KS12_UECSG_SHIFT            (18U)
#define S50_ELS_KS12_KS12_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UECSG_SHIFT)) & S50_ELS_KS12_KS12_UECSG_MASK)

#define S50_ELS_KS12_KS12_UECDH_MASK             (0x80000U)
#define S50_ELS_KS12_KS12_UECDH_SHIFT            (19U)
#define S50_ELS_KS12_KS12_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UECDH_SHIFT)) & S50_ELS_KS12_KS12_UECDH_MASK)

#define S50_ELS_KS12_KS12_UAES_MASK              (0x100000U)
#define S50_ELS_KS12_KS12_UAES_SHIFT             (20U)
#define S50_ELS_KS12_KS12_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UAES_SHIFT)) & S50_ELS_KS12_KS12_UAES_MASK)

#define S50_ELS_KS12_KS12_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS12_KS12_UHMAC_SHIFT            (21U)
#define S50_ELS_KS12_KS12_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UHMAC_SHIFT)) & S50_ELS_KS12_KS12_UHMAC_MASK)

#define S50_ELS_KS12_KS12_UKWK_MASK              (0x400000U)
#define S50_ELS_KS12_KS12_UKWK_SHIFT             (22U)
#define S50_ELS_KS12_KS12_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKWK_SHIFT)) & S50_ELS_KS12_KS12_UKWK_MASK)

#define S50_ELS_KS12_KS12_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS12_KS12_UKUOK_SHIFT            (23U)
#define S50_ELS_KS12_KS12_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKUOK_SHIFT)) & S50_ELS_KS12_KS12_UKUOK_MASK)

#define S50_ELS_KS12_KS12_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS12_KS12_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS12_KS12_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UTLSPMS_SHIFT)) & S50_ELS_KS12_KS12_UTLSPMS_MASK)

#define S50_ELS_KS12_KS12_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS12_KS12_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS12_KS12_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UTLSMS_SHIFT)) & S50_ELS_KS12_KS12_UTLSMS_MASK)

#define S50_ELS_KS12_KS12_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS12_KS12_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS12_KS12_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKGSRC_SHIFT)) & S50_ELS_KS12_KS12_UKGSRC_MASK)

#define S50_ELS_KS12_KS12_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS12_KS12_UHWO_SHIFT             (27U)
#define S50_ELS_KS12_KS12_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UHWO_SHIFT)) & S50_ELS_KS12_KS12_UHWO_MASK)

#define S50_ELS_KS12_KS12_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS12_KS12_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS12_KS12_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UWRPOK_SHIFT)) & S50_ELS_KS12_KS12_UWRPOK_MASK)

#define S50_ELS_KS12_KS12_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS12_KS12_UDUK_SHIFT             (29U)
#define S50_ELS_KS12_KS12_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UDUK_SHIFT)) & S50_ELS_KS12_KS12_UDUK_MASK)

#define S50_ELS_KS12_KS12_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS12_KS12_UPPROT_SHIFT           (30U)
#define S50_ELS_KS12_KS12_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UPPROT_SHIFT)) & S50_ELS_KS12_KS12_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS13 - Status Register */
/*! @{ */

#define S50_ELS_KS13_KS13_KSIZE_MASK             (0x3U)
#define S50_ELS_KS13_KS13_KSIZE_SHIFT            (0U)
/*! KS13_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS13_KS13_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_KSIZE_SHIFT)) & S50_ELS_KS13_KS13_KSIZE_MASK)

#define S50_ELS_KS13_KS13_KACT_MASK              (0x20U)
#define S50_ELS_KS13_KS13_KACT_SHIFT             (5U)
#define S50_ELS_KS13_KS13_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_KACT_SHIFT)) & S50_ELS_KS13_KS13_KACT_MASK)

#define S50_ELS_KS13_KS13_KBASE_MASK             (0x40U)
#define S50_ELS_KS13_KS13_KBASE_SHIFT            (6U)
#define S50_ELS_KS13_KS13_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_KBASE_SHIFT)) & S50_ELS_KS13_KS13_KBASE_MASK)

#define S50_ELS_KS13_KS13_FGP_MASK               (0x80U)
#define S50_ELS_KS13_KS13_FGP_SHIFT              (7U)
#define S50_ELS_KS13_KS13_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_FGP_SHIFT)) & S50_ELS_KS13_KS13_FGP_MASK)

#define S50_ELS_KS13_KS13_FRTN_MASK              (0x100U)
#define S50_ELS_KS13_KS13_FRTN_SHIFT             (8U)
#define S50_ELS_KS13_KS13_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_FRTN_SHIFT)) & S50_ELS_KS13_KS13_FRTN_MASK)

#define S50_ELS_KS13_KS13_FHWO_MASK              (0x200U)
#define S50_ELS_KS13_KS13_FHWO_SHIFT             (9U)
#define S50_ELS_KS13_KS13_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_FHWO_SHIFT)) & S50_ELS_KS13_KS13_FHWO_MASK)

#define S50_ELS_KS13_KS13_UKPUK_MASK             (0x800U)
#define S50_ELS_KS13_KS13_UKPUK_SHIFT            (11U)
#define S50_ELS_KS13_KS13_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKPUK_SHIFT)) & S50_ELS_KS13_KS13_UKPUK_MASK)

#define S50_ELS_KS13_KS13_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS13_KS13_UTECDH_SHIFT           (12U)
#define S50_ELS_KS13_KS13_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UTECDH_SHIFT)) & S50_ELS_KS13_KS13_UTECDH_MASK)

#define S50_ELS_KS13_KS13_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS13_KS13_UCMAC_SHIFT            (13U)
#define S50_ELS_KS13_KS13_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UCMAC_SHIFT)) & S50_ELS_KS13_KS13_UCMAC_MASK)

#define S50_ELS_KS13_KS13_UKSK_MASK              (0x4000U)
#define S50_ELS_KS13_KS13_UKSK_SHIFT             (14U)
#define S50_ELS_KS13_KS13_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKSK_SHIFT)) & S50_ELS_KS13_KS13_UKSK_MASK)

#define S50_ELS_KS13_KS13_URTF_MASK              (0x8000U)
#define S50_ELS_KS13_KS13_URTF_SHIFT             (15U)
#define S50_ELS_KS13_KS13_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_URTF_SHIFT)) & S50_ELS_KS13_KS13_URTF_MASK)

#define S50_ELS_KS13_KS13_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS13_KS13_UCKDF_SHIFT            (16U)
#define S50_ELS_KS13_KS13_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UCKDF_SHIFT)) & S50_ELS_KS13_KS13_UCKDF_MASK)

#define S50_ELS_KS13_KS13_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS13_KS13_UHKDF_SHIFT            (17U)
#define S50_ELS_KS13_KS13_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UHKDF_SHIFT)) & S50_ELS_KS13_KS13_UHKDF_MASK)

#define S50_ELS_KS13_KS13_UECSG_MASK             (0x40000U)
#define S50_ELS_KS13_KS13_UECSG_SHIFT            (18U)
#define S50_ELS_KS13_KS13_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UECSG_SHIFT)) & S50_ELS_KS13_KS13_UECSG_MASK)

#define S50_ELS_KS13_KS13_UECDH_MASK             (0x80000U)
#define S50_ELS_KS13_KS13_UECDH_SHIFT            (19U)
#define S50_ELS_KS13_KS13_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UECDH_SHIFT)) & S50_ELS_KS13_KS13_UECDH_MASK)

#define S50_ELS_KS13_KS13_UAES_MASK              (0x100000U)
#define S50_ELS_KS13_KS13_UAES_SHIFT             (20U)
#define S50_ELS_KS13_KS13_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UAES_SHIFT)) & S50_ELS_KS13_KS13_UAES_MASK)

#define S50_ELS_KS13_KS13_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS13_KS13_UHMAC_SHIFT            (21U)
#define S50_ELS_KS13_KS13_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UHMAC_SHIFT)) & S50_ELS_KS13_KS13_UHMAC_MASK)

#define S50_ELS_KS13_KS13_UKWK_MASK              (0x400000U)
#define S50_ELS_KS13_KS13_UKWK_SHIFT             (22U)
#define S50_ELS_KS13_KS13_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKWK_SHIFT)) & S50_ELS_KS13_KS13_UKWK_MASK)

#define S50_ELS_KS13_KS13_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS13_KS13_UKUOK_SHIFT            (23U)
#define S50_ELS_KS13_KS13_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKUOK_SHIFT)) & S50_ELS_KS13_KS13_UKUOK_MASK)

#define S50_ELS_KS13_KS13_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS13_KS13_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS13_KS13_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UTLSPMS_SHIFT)) & S50_ELS_KS13_KS13_UTLSPMS_MASK)

#define S50_ELS_KS13_KS13_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS13_KS13_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS13_KS13_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UTLSMS_SHIFT)) & S50_ELS_KS13_KS13_UTLSMS_MASK)

#define S50_ELS_KS13_KS13_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS13_KS13_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS13_KS13_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKGSRC_SHIFT)) & S50_ELS_KS13_KS13_UKGSRC_MASK)

#define S50_ELS_KS13_KS13_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS13_KS13_UHWO_SHIFT             (27U)
#define S50_ELS_KS13_KS13_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UHWO_SHIFT)) & S50_ELS_KS13_KS13_UHWO_MASK)

#define S50_ELS_KS13_KS13_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS13_KS13_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS13_KS13_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UWRPOK_SHIFT)) & S50_ELS_KS13_KS13_UWRPOK_MASK)

#define S50_ELS_KS13_KS13_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS13_KS13_UDUK_SHIFT             (29U)
#define S50_ELS_KS13_KS13_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UDUK_SHIFT)) & S50_ELS_KS13_KS13_UDUK_MASK)

#define S50_ELS_KS13_KS13_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS13_KS13_UPPROT_SHIFT           (30U)
#define S50_ELS_KS13_KS13_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UPPROT_SHIFT)) & S50_ELS_KS13_KS13_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS14 - Status Register */
/*! @{ */

#define S50_ELS_KS14_KS14_KSIZE_MASK             (0x3U)
#define S50_ELS_KS14_KS14_KSIZE_SHIFT            (0U)
/*! KS14_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS14_KS14_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_KSIZE_SHIFT)) & S50_ELS_KS14_KS14_KSIZE_MASK)

#define S50_ELS_KS14_KS14_KACT_MASK              (0x20U)
#define S50_ELS_KS14_KS14_KACT_SHIFT             (5U)
#define S50_ELS_KS14_KS14_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_KACT_SHIFT)) & S50_ELS_KS14_KS14_KACT_MASK)

#define S50_ELS_KS14_KS14_KBASE_MASK             (0x40U)
#define S50_ELS_KS14_KS14_KBASE_SHIFT            (6U)
#define S50_ELS_KS14_KS14_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_KBASE_SHIFT)) & S50_ELS_KS14_KS14_KBASE_MASK)

#define S50_ELS_KS14_KS14_FGP_MASK               (0x80U)
#define S50_ELS_KS14_KS14_FGP_SHIFT              (7U)
#define S50_ELS_KS14_KS14_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_FGP_SHIFT)) & S50_ELS_KS14_KS14_FGP_MASK)

#define S50_ELS_KS14_KS14_FRTN_MASK              (0x100U)
#define S50_ELS_KS14_KS14_FRTN_SHIFT             (8U)
#define S50_ELS_KS14_KS14_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_FRTN_SHIFT)) & S50_ELS_KS14_KS14_FRTN_MASK)

#define S50_ELS_KS14_KS14_FHWO_MASK              (0x200U)
#define S50_ELS_KS14_KS14_FHWO_SHIFT             (9U)
#define S50_ELS_KS14_KS14_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_FHWO_SHIFT)) & S50_ELS_KS14_KS14_FHWO_MASK)

#define S50_ELS_KS14_KS14_UKPUK_MASK             (0x800U)
#define S50_ELS_KS14_KS14_UKPUK_SHIFT            (11U)
#define S50_ELS_KS14_KS14_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKPUK_SHIFT)) & S50_ELS_KS14_KS14_UKPUK_MASK)

#define S50_ELS_KS14_KS14_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS14_KS14_UTECDH_SHIFT           (12U)
#define S50_ELS_KS14_KS14_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UTECDH_SHIFT)) & S50_ELS_KS14_KS14_UTECDH_MASK)

#define S50_ELS_KS14_KS14_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS14_KS14_UCMAC_SHIFT            (13U)
#define S50_ELS_KS14_KS14_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UCMAC_SHIFT)) & S50_ELS_KS14_KS14_UCMAC_MASK)

#define S50_ELS_KS14_KS14_UKSK_MASK              (0x4000U)
#define S50_ELS_KS14_KS14_UKSK_SHIFT             (14U)
#define S50_ELS_KS14_KS14_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKSK_SHIFT)) & S50_ELS_KS14_KS14_UKSK_MASK)

#define S50_ELS_KS14_KS14_URTF_MASK              (0x8000U)
#define S50_ELS_KS14_KS14_URTF_SHIFT             (15U)
#define S50_ELS_KS14_KS14_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_URTF_SHIFT)) & S50_ELS_KS14_KS14_URTF_MASK)

#define S50_ELS_KS14_KS14_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS14_KS14_UCKDF_SHIFT            (16U)
#define S50_ELS_KS14_KS14_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UCKDF_SHIFT)) & S50_ELS_KS14_KS14_UCKDF_MASK)

#define S50_ELS_KS14_KS14_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS14_KS14_UHKDF_SHIFT            (17U)
#define S50_ELS_KS14_KS14_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UHKDF_SHIFT)) & S50_ELS_KS14_KS14_UHKDF_MASK)

#define S50_ELS_KS14_KS14_UECSG_MASK             (0x40000U)
#define S50_ELS_KS14_KS14_UECSG_SHIFT            (18U)
#define S50_ELS_KS14_KS14_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UECSG_SHIFT)) & S50_ELS_KS14_KS14_UECSG_MASK)

#define S50_ELS_KS14_KS14_UECDH_MASK             (0x80000U)
#define S50_ELS_KS14_KS14_UECDH_SHIFT            (19U)
#define S50_ELS_KS14_KS14_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UECDH_SHIFT)) & S50_ELS_KS14_KS14_UECDH_MASK)

#define S50_ELS_KS14_KS14_UAES_MASK              (0x100000U)
#define S50_ELS_KS14_KS14_UAES_SHIFT             (20U)
#define S50_ELS_KS14_KS14_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UAES_SHIFT)) & S50_ELS_KS14_KS14_UAES_MASK)

#define S50_ELS_KS14_KS14_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS14_KS14_UHMAC_SHIFT            (21U)
#define S50_ELS_KS14_KS14_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UHMAC_SHIFT)) & S50_ELS_KS14_KS14_UHMAC_MASK)

#define S50_ELS_KS14_KS14_UKWK_MASK              (0x400000U)
#define S50_ELS_KS14_KS14_UKWK_SHIFT             (22U)
#define S50_ELS_KS14_KS14_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKWK_SHIFT)) & S50_ELS_KS14_KS14_UKWK_MASK)

#define S50_ELS_KS14_KS14_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS14_KS14_UKUOK_SHIFT            (23U)
#define S50_ELS_KS14_KS14_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKUOK_SHIFT)) & S50_ELS_KS14_KS14_UKUOK_MASK)

#define S50_ELS_KS14_KS14_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS14_KS14_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS14_KS14_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UTLSPMS_SHIFT)) & S50_ELS_KS14_KS14_UTLSPMS_MASK)

#define S50_ELS_KS14_KS14_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS14_KS14_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS14_KS14_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UTLSMS_SHIFT)) & S50_ELS_KS14_KS14_UTLSMS_MASK)

#define S50_ELS_KS14_KS14_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS14_KS14_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS14_KS14_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKGSRC_SHIFT)) & S50_ELS_KS14_KS14_UKGSRC_MASK)

#define S50_ELS_KS14_KS14_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS14_KS14_UHWO_SHIFT             (27U)
#define S50_ELS_KS14_KS14_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UHWO_SHIFT)) & S50_ELS_KS14_KS14_UHWO_MASK)

#define S50_ELS_KS14_KS14_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS14_KS14_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS14_KS14_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UWRPOK_SHIFT)) & S50_ELS_KS14_KS14_UWRPOK_MASK)

#define S50_ELS_KS14_KS14_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS14_KS14_UDUK_SHIFT             (29U)
#define S50_ELS_KS14_KS14_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UDUK_SHIFT)) & S50_ELS_KS14_KS14_UDUK_MASK)

#define S50_ELS_KS14_KS14_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS14_KS14_UPPROT_SHIFT           (30U)
#define S50_ELS_KS14_KS14_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UPPROT_SHIFT)) & S50_ELS_KS14_KS14_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS15 - Status Register */
/*! @{ */

#define S50_ELS_KS15_KS15_KSIZE_MASK             (0x3U)
#define S50_ELS_KS15_KS15_KSIZE_SHIFT            (0U)
/*! KS15_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS15_KS15_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_KSIZE_SHIFT)) & S50_ELS_KS15_KS15_KSIZE_MASK)

#define S50_ELS_KS15_KS15_KACT_MASK              (0x20U)
#define S50_ELS_KS15_KS15_KACT_SHIFT             (5U)
#define S50_ELS_KS15_KS15_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_KACT_SHIFT)) & S50_ELS_KS15_KS15_KACT_MASK)

#define S50_ELS_KS15_KS15_KBASE_MASK             (0x40U)
#define S50_ELS_KS15_KS15_KBASE_SHIFT            (6U)
#define S50_ELS_KS15_KS15_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_KBASE_SHIFT)) & S50_ELS_KS15_KS15_KBASE_MASK)

#define S50_ELS_KS15_KS15_FGP_MASK               (0x80U)
#define S50_ELS_KS15_KS15_FGP_SHIFT              (7U)
#define S50_ELS_KS15_KS15_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_FGP_SHIFT)) & S50_ELS_KS15_KS15_FGP_MASK)

#define S50_ELS_KS15_KS15_FRTN_MASK              (0x100U)
#define S50_ELS_KS15_KS15_FRTN_SHIFT             (8U)
#define S50_ELS_KS15_KS15_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_FRTN_SHIFT)) & S50_ELS_KS15_KS15_FRTN_MASK)

#define S50_ELS_KS15_KS15_FHWO_MASK              (0x200U)
#define S50_ELS_KS15_KS15_FHWO_SHIFT             (9U)
#define S50_ELS_KS15_KS15_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_FHWO_SHIFT)) & S50_ELS_KS15_KS15_FHWO_MASK)

#define S50_ELS_KS15_KS15_UKPUK_MASK             (0x800U)
#define S50_ELS_KS15_KS15_UKPUK_SHIFT            (11U)
#define S50_ELS_KS15_KS15_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKPUK_SHIFT)) & S50_ELS_KS15_KS15_UKPUK_MASK)

#define S50_ELS_KS15_KS15_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS15_KS15_UTECDH_SHIFT           (12U)
#define S50_ELS_KS15_KS15_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UTECDH_SHIFT)) & S50_ELS_KS15_KS15_UTECDH_MASK)

#define S50_ELS_KS15_KS15_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS15_KS15_UCMAC_SHIFT            (13U)
#define S50_ELS_KS15_KS15_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UCMAC_SHIFT)) & S50_ELS_KS15_KS15_UCMAC_MASK)

#define S50_ELS_KS15_KS15_UKSK_MASK              (0x4000U)
#define S50_ELS_KS15_KS15_UKSK_SHIFT             (14U)
#define S50_ELS_KS15_KS15_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKSK_SHIFT)) & S50_ELS_KS15_KS15_UKSK_MASK)

#define S50_ELS_KS15_KS15_URTF_MASK              (0x8000U)
#define S50_ELS_KS15_KS15_URTF_SHIFT             (15U)
#define S50_ELS_KS15_KS15_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_URTF_SHIFT)) & S50_ELS_KS15_KS15_URTF_MASK)

#define S50_ELS_KS15_KS15_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS15_KS15_UCKDF_SHIFT            (16U)
#define S50_ELS_KS15_KS15_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UCKDF_SHIFT)) & S50_ELS_KS15_KS15_UCKDF_MASK)

#define S50_ELS_KS15_KS15_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS15_KS15_UHKDF_SHIFT            (17U)
#define S50_ELS_KS15_KS15_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UHKDF_SHIFT)) & S50_ELS_KS15_KS15_UHKDF_MASK)

#define S50_ELS_KS15_KS15_UECSG_MASK             (0x40000U)
#define S50_ELS_KS15_KS15_UECSG_SHIFT            (18U)
#define S50_ELS_KS15_KS15_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UECSG_SHIFT)) & S50_ELS_KS15_KS15_UECSG_MASK)

#define S50_ELS_KS15_KS15_UECDH_MASK             (0x80000U)
#define S50_ELS_KS15_KS15_UECDH_SHIFT            (19U)
#define S50_ELS_KS15_KS15_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UECDH_SHIFT)) & S50_ELS_KS15_KS15_UECDH_MASK)

#define S50_ELS_KS15_KS15_UAES_MASK              (0x100000U)
#define S50_ELS_KS15_KS15_UAES_SHIFT             (20U)
#define S50_ELS_KS15_KS15_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UAES_SHIFT)) & S50_ELS_KS15_KS15_UAES_MASK)

#define S50_ELS_KS15_KS15_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS15_KS15_UHMAC_SHIFT            (21U)
#define S50_ELS_KS15_KS15_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UHMAC_SHIFT)) & S50_ELS_KS15_KS15_UHMAC_MASK)

#define S50_ELS_KS15_KS15_UKWK_MASK              (0x400000U)
#define S50_ELS_KS15_KS15_UKWK_SHIFT             (22U)
#define S50_ELS_KS15_KS15_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKWK_SHIFT)) & S50_ELS_KS15_KS15_UKWK_MASK)

#define S50_ELS_KS15_KS15_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS15_KS15_UKUOK_SHIFT            (23U)
#define S50_ELS_KS15_KS15_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKUOK_SHIFT)) & S50_ELS_KS15_KS15_UKUOK_MASK)

#define S50_ELS_KS15_KS15_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS15_KS15_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS15_KS15_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UTLSPMS_SHIFT)) & S50_ELS_KS15_KS15_UTLSPMS_MASK)

#define S50_ELS_KS15_KS15_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS15_KS15_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS15_KS15_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UTLSMS_SHIFT)) & S50_ELS_KS15_KS15_UTLSMS_MASK)

#define S50_ELS_KS15_KS15_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS15_KS15_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS15_KS15_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKGSRC_SHIFT)) & S50_ELS_KS15_KS15_UKGSRC_MASK)

#define S50_ELS_KS15_KS15_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS15_KS15_UHWO_SHIFT             (27U)
#define S50_ELS_KS15_KS15_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UHWO_SHIFT)) & S50_ELS_KS15_KS15_UHWO_MASK)

#define S50_ELS_KS15_KS15_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS15_KS15_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS15_KS15_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UWRPOK_SHIFT)) & S50_ELS_KS15_KS15_UWRPOK_MASK)

#define S50_ELS_KS15_KS15_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS15_KS15_UDUK_SHIFT             (29U)
#define S50_ELS_KS15_KS15_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UDUK_SHIFT)) & S50_ELS_KS15_KS15_UDUK_MASK)

#define S50_ELS_KS15_KS15_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS15_KS15_UPPROT_SHIFT           (30U)
#define S50_ELS_KS15_KS15_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UPPROT_SHIFT)) & S50_ELS_KS15_KS15_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS16 - Status Register */
/*! @{ */

#define S50_ELS_KS16_KS16_KSIZE_MASK             (0x3U)
#define S50_ELS_KS16_KS16_KSIZE_SHIFT            (0U)
/*! KS16_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS16_KS16_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_KSIZE_SHIFT)) & S50_ELS_KS16_KS16_KSIZE_MASK)

#define S50_ELS_KS16_KS16_KACT_MASK              (0x20U)
#define S50_ELS_KS16_KS16_KACT_SHIFT             (5U)
#define S50_ELS_KS16_KS16_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_KACT_SHIFT)) & S50_ELS_KS16_KS16_KACT_MASK)

#define S50_ELS_KS16_KS16_KBASE_MASK             (0x40U)
#define S50_ELS_KS16_KS16_KBASE_SHIFT            (6U)
#define S50_ELS_KS16_KS16_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_KBASE_SHIFT)) & S50_ELS_KS16_KS16_KBASE_MASK)

#define S50_ELS_KS16_KS16_FGP_MASK               (0x80U)
#define S50_ELS_KS16_KS16_FGP_SHIFT              (7U)
#define S50_ELS_KS16_KS16_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_FGP_SHIFT)) & S50_ELS_KS16_KS16_FGP_MASK)

#define S50_ELS_KS16_KS16_FRTN_MASK              (0x100U)
#define S50_ELS_KS16_KS16_FRTN_SHIFT             (8U)
#define S50_ELS_KS16_KS16_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_FRTN_SHIFT)) & S50_ELS_KS16_KS16_FRTN_MASK)

#define S50_ELS_KS16_KS16_FHWO_MASK              (0x200U)
#define S50_ELS_KS16_KS16_FHWO_SHIFT             (9U)
#define S50_ELS_KS16_KS16_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_FHWO_SHIFT)) & S50_ELS_KS16_KS16_FHWO_MASK)

#define S50_ELS_KS16_KS16_UKPUK_MASK             (0x800U)
#define S50_ELS_KS16_KS16_UKPUK_SHIFT            (11U)
#define S50_ELS_KS16_KS16_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKPUK_SHIFT)) & S50_ELS_KS16_KS16_UKPUK_MASK)

#define S50_ELS_KS16_KS16_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS16_KS16_UTECDH_SHIFT           (12U)
#define S50_ELS_KS16_KS16_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UTECDH_SHIFT)) & S50_ELS_KS16_KS16_UTECDH_MASK)

#define S50_ELS_KS16_KS16_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS16_KS16_UCMAC_SHIFT            (13U)
#define S50_ELS_KS16_KS16_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UCMAC_SHIFT)) & S50_ELS_KS16_KS16_UCMAC_MASK)

#define S50_ELS_KS16_KS16_UKSK_MASK              (0x4000U)
#define S50_ELS_KS16_KS16_UKSK_SHIFT             (14U)
#define S50_ELS_KS16_KS16_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKSK_SHIFT)) & S50_ELS_KS16_KS16_UKSK_MASK)

#define S50_ELS_KS16_KS16_URTF_MASK              (0x8000U)
#define S50_ELS_KS16_KS16_URTF_SHIFT             (15U)
#define S50_ELS_KS16_KS16_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_URTF_SHIFT)) & S50_ELS_KS16_KS16_URTF_MASK)

#define S50_ELS_KS16_KS16_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS16_KS16_UCKDF_SHIFT            (16U)
#define S50_ELS_KS16_KS16_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UCKDF_SHIFT)) & S50_ELS_KS16_KS16_UCKDF_MASK)

#define S50_ELS_KS16_KS16_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS16_KS16_UHKDF_SHIFT            (17U)
#define S50_ELS_KS16_KS16_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UHKDF_SHIFT)) & S50_ELS_KS16_KS16_UHKDF_MASK)

#define S50_ELS_KS16_KS16_UECSG_MASK             (0x40000U)
#define S50_ELS_KS16_KS16_UECSG_SHIFT            (18U)
#define S50_ELS_KS16_KS16_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UECSG_SHIFT)) & S50_ELS_KS16_KS16_UECSG_MASK)

#define S50_ELS_KS16_KS16_UECDH_MASK             (0x80000U)
#define S50_ELS_KS16_KS16_UECDH_SHIFT            (19U)
#define S50_ELS_KS16_KS16_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UECDH_SHIFT)) & S50_ELS_KS16_KS16_UECDH_MASK)

#define S50_ELS_KS16_KS16_UAES_MASK              (0x100000U)
#define S50_ELS_KS16_KS16_UAES_SHIFT             (20U)
#define S50_ELS_KS16_KS16_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UAES_SHIFT)) & S50_ELS_KS16_KS16_UAES_MASK)

#define S50_ELS_KS16_KS16_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS16_KS16_UHMAC_SHIFT            (21U)
#define S50_ELS_KS16_KS16_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UHMAC_SHIFT)) & S50_ELS_KS16_KS16_UHMAC_MASK)

#define S50_ELS_KS16_KS16_UKWK_MASK              (0x400000U)
#define S50_ELS_KS16_KS16_UKWK_SHIFT             (22U)
#define S50_ELS_KS16_KS16_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKWK_SHIFT)) & S50_ELS_KS16_KS16_UKWK_MASK)

#define S50_ELS_KS16_KS16_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS16_KS16_UKUOK_SHIFT            (23U)
#define S50_ELS_KS16_KS16_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKUOK_SHIFT)) & S50_ELS_KS16_KS16_UKUOK_MASK)

#define S50_ELS_KS16_KS16_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS16_KS16_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS16_KS16_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UTLSPMS_SHIFT)) & S50_ELS_KS16_KS16_UTLSPMS_MASK)

#define S50_ELS_KS16_KS16_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS16_KS16_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS16_KS16_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UTLSMS_SHIFT)) & S50_ELS_KS16_KS16_UTLSMS_MASK)

#define S50_ELS_KS16_KS16_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS16_KS16_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS16_KS16_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKGSRC_SHIFT)) & S50_ELS_KS16_KS16_UKGSRC_MASK)

#define S50_ELS_KS16_KS16_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS16_KS16_UHWO_SHIFT             (27U)
#define S50_ELS_KS16_KS16_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UHWO_SHIFT)) & S50_ELS_KS16_KS16_UHWO_MASK)

#define S50_ELS_KS16_KS16_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS16_KS16_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS16_KS16_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UWRPOK_SHIFT)) & S50_ELS_KS16_KS16_UWRPOK_MASK)

#define S50_ELS_KS16_KS16_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS16_KS16_UDUK_SHIFT             (29U)
#define S50_ELS_KS16_KS16_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UDUK_SHIFT)) & S50_ELS_KS16_KS16_UDUK_MASK)

#define S50_ELS_KS16_KS16_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS16_KS16_UPPROT_SHIFT           (30U)
#define S50_ELS_KS16_KS16_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UPPROT_SHIFT)) & S50_ELS_KS16_KS16_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS17 - Status Register */
/*! @{ */

#define S50_ELS_KS17_KS17_KSIZE_MASK             (0x3U)
#define S50_ELS_KS17_KS17_KSIZE_SHIFT            (0U)
/*! KS17_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS17_KS17_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_KSIZE_SHIFT)) & S50_ELS_KS17_KS17_KSIZE_MASK)

#define S50_ELS_KS17_KS17_KACT_MASK              (0x20U)
#define S50_ELS_KS17_KS17_KACT_SHIFT             (5U)
#define S50_ELS_KS17_KS17_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_KACT_SHIFT)) & S50_ELS_KS17_KS17_KACT_MASK)

#define S50_ELS_KS17_KS17_KBASE_MASK             (0x40U)
#define S50_ELS_KS17_KS17_KBASE_SHIFT            (6U)
#define S50_ELS_KS17_KS17_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_KBASE_SHIFT)) & S50_ELS_KS17_KS17_KBASE_MASK)

#define S50_ELS_KS17_KS17_FGP_MASK               (0x80U)
#define S50_ELS_KS17_KS17_FGP_SHIFT              (7U)
#define S50_ELS_KS17_KS17_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_FGP_SHIFT)) & S50_ELS_KS17_KS17_FGP_MASK)

#define S50_ELS_KS17_KS17_FRTN_MASK              (0x100U)
#define S50_ELS_KS17_KS17_FRTN_SHIFT             (8U)
#define S50_ELS_KS17_KS17_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_FRTN_SHIFT)) & S50_ELS_KS17_KS17_FRTN_MASK)

#define S50_ELS_KS17_KS17_FHWO_MASK              (0x200U)
#define S50_ELS_KS17_KS17_FHWO_SHIFT             (9U)
#define S50_ELS_KS17_KS17_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_FHWO_SHIFT)) & S50_ELS_KS17_KS17_FHWO_MASK)

#define S50_ELS_KS17_KS17_UKPUK_MASK             (0x800U)
#define S50_ELS_KS17_KS17_UKPUK_SHIFT            (11U)
#define S50_ELS_KS17_KS17_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKPUK_SHIFT)) & S50_ELS_KS17_KS17_UKPUK_MASK)

#define S50_ELS_KS17_KS17_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS17_KS17_UTECDH_SHIFT           (12U)
#define S50_ELS_KS17_KS17_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UTECDH_SHIFT)) & S50_ELS_KS17_KS17_UTECDH_MASK)

#define S50_ELS_KS17_KS17_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS17_KS17_UCMAC_SHIFT            (13U)
#define S50_ELS_KS17_KS17_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UCMAC_SHIFT)) & S50_ELS_KS17_KS17_UCMAC_MASK)

#define S50_ELS_KS17_KS17_UKSK_MASK              (0x4000U)
#define S50_ELS_KS17_KS17_UKSK_SHIFT             (14U)
#define S50_ELS_KS17_KS17_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKSK_SHIFT)) & S50_ELS_KS17_KS17_UKSK_MASK)

#define S50_ELS_KS17_KS17_URTF_MASK              (0x8000U)
#define S50_ELS_KS17_KS17_URTF_SHIFT             (15U)
#define S50_ELS_KS17_KS17_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_URTF_SHIFT)) & S50_ELS_KS17_KS17_URTF_MASK)

#define S50_ELS_KS17_KS17_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS17_KS17_UCKDF_SHIFT            (16U)
#define S50_ELS_KS17_KS17_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UCKDF_SHIFT)) & S50_ELS_KS17_KS17_UCKDF_MASK)

#define S50_ELS_KS17_KS17_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS17_KS17_UHKDF_SHIFT            (17U)
#define S50_ELS_KS17_KS17_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UHKDF_SHIFT)) & S50_ELS_KS17_KS17_UHKDF_MASK)

#define S50_ELS_KS17_KS17_UECSG_MASK             (0x40000U)
#define S50_ELS_KS17_KS17_UECSG_SHIFT            (18U)
#define S50_ELS_KS17_KS17_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UECSG_SHIFT)) & S50_ELS_KS17_KS17_UECSG_MASK)

#define S50_ELS_KS17_KS17_UECDH_MASK             (0x80000U)
#define S50_ELS_KS17_KS17_UECDH_SHIFT            (19U)
#define S50_ELS_KS17_KS17_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UECDH_SHIFT)) & S50_ELS_KS17_KS17_UECDH_MASK)

#define S50_ELS_KS17_KS17_UAES_MASK              (0x100000U)
#define S50_ELS_KS17_KS17_UAES_SHIFT             (20U)
#define S50_ELS_KS17_KS17_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UAES_SHIFT)) & S50_ELS_KS17_KS17_UAES_MASK)

#define S50_ELS_KS17_KS17_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS17_KS17_UHMAC_SHIFT            (21U)
#define S50_ELS_KS17_KS17_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UHMAC_SHIFT)) & S50_ELS_KS17_KS17_UHMAC_MASK)

#define S50_ELS_KS17_KS17_UKWK_MASK              (0x400000U)
#define S50_ELS_KS17_KS17_UKWK_SHIFT             (22U)
#define S50_ELS_KS17_KS17_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKWK_SHIFT)) & S50_ELS_KS17_KS17_UKWK_MASK)

#define S50_ELS_KS17_KS17_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS17_KS17_UKUOK_SHIFT            (23U)
#define S50_ELS_KS17_KS17_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKUOK_SHIFT)) & S50_ELS_KS17_KS17_UKUOK_MASK)

#define S50_ELS_KS17_KS17_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS17_KS17_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS17_KS17_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UTLSPMS_SHIFT)) & S50_ELS_KS17_KS17_UTLSPMS_MASK)

#define S50_ELS_KS17_KS17_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS17_KS17_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS17_KS17_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UTLSMS_SHIFT)) & S50_ELS_KS17_KS17_UTLSMS_MASK)

#define S50_ELS_KS17_KS17_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS17_KS17_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS17_KS17_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKGSRC_SHIFT)) & S50_ELS_KS17_KS17_UKGSRC_MASK)

#define S50_ELS_KS17_KS17_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS17_KS17_UHWO_SHIFT             (27U)
#define S50_ELS_KS17_KS17_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UHWO_SHIFT)) & S50_ELS_KS17_KS17_UHWO_MASK)

#define S50_ELS_KS17_KS17_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS17_KS17_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS17_KS17_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UWRPOK_SHIFT)) & S50_ELS_KS17_KS17_UWRPOK_MASK)

#define S50_ELS_KS17_KS17_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS17_KS17_UDUK_SHIFT             (29U)
#define S50_ELS_KS17_KS17_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UDUK_SHIFT)) & S50_ELS_KS17_KS17_UDUK_MASK)

#define S50_ELS_KS17_KS17_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS17_KS17_UPPROT_SHIFT           (30U)
#define S50_ELS_KS17_KS17_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UPPROT_SHIFT)) & S50_ELS_KS17_KS17_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS18 - Status Register */
/*! @{ */

#define S50_ELS_KS18_KS18_KSIZE_MASK             (0x3U)
#define S50_ELS_KS18_KS18_KSIZE_SHIFT            (0U)
/*! KS18_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS18_KS18_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_KSIZE_SHIFT)) & S50_ELS_KS18_KS18_KSIZE_MASK)

#define S50_ELS_KS18_KS18_KACT_MASK              (0x20U)
#define S50_ELS_KS18_KS18_KACT_SHIFT             (5U)
#define S50_ELS_KS18_KS18_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_KACT_SHIFT)) & S50_ELS_KS18_KS18_KACT_MASK)

#define S50_ELS_KS18_KS18_KBASE_MASK             (0x40U)
#define S50_ELS_KS18_KS18_KBASE_SHIFT            (6U)
#define S50_ELS_KS18_KS18_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_KBASE_SHIFT)) & S50_ELS_KS18_KS18_KBASE_MASK)

#define S50_ELS_KS18_KS18_FGP_MASK               (0x80U)
#define S50_ELS_KS18_KS18_FGP_SHIFT              (7U)
#define S50_ELS_KS18_KS18_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_FGP_SHIFT)) & S50_ELS_KS18_KS18_FGP_MASK)

#define S50_ELS_KS18_KS18_FRTN_MASK              (0x100U)
#define S50_ELS_KS18_KS18_FRTN_SHIFT             (8U)
#define S50_ELS_KS18_KS18_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_FRTN_SHIFT)) & S50_ELS_KS18_KS18_FRTN_MASK)

#define S50_ELS_KS18_KS18_FHWO_MASK              (0x200U)
#define S50_ELS_KS18_KS18_FHWO_SHIFT             (9U)
#define S50_ELS_KS18_KS18_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_FHWO_SHIFT)) & S50_ELS_KS18_KS18_FHWO_MASK)

#define S50_ELS_KS18_KS18_UKPUK_MASK             (0x800U)
#define S50_ELS_KS18_KS18_UKPUK_SHIFT            (11U)
#define S50_ELS_KS18_KS18_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKPUK_SHIFT)) & S50_ELS_KS18_KS18_UKPUK_MASK)

#define S50_ELS_KS18_KS18_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS18_KS18_UTECDH_SHIFT           (12U)
#define S50_ELS_KS18_KS18_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UTECDH_SHIFT)) & S50_ELS_KS18_KS18_UTECDH_MASK)

#define S50_ELS_KS18_KS18_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS18_KS18_UCMAC_SHIFT            (13U)
#define S50_ELS_KS18_KS18_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UCMAC_SHIFT)) & S50_ELS_KS18_KS18_UCMAC_MASK)

#define S50_ELS_KS18_KS18_UKSK_MASK              (0x4000U)
#define S50_ELS_KS18_KS18_UKSK_SHIFT             (14U)
#define S50_ELS_KS18_KS18_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKSK_SHIFT)) & S50_ELS_KS18_KS18_UKSK_MASK)

#define S50_ELS_KS18_KS18_URTF_MASK              (0x8000U)
#define S50_ELS_KS18_KS18_URTF_SHIFT             (15U)
#define S50_ELS_KS18_KS18_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_URTF_SHIFT)) & S50_ELS_KS18_KS18_URTF_MASK)

#define S50_ELS_KS18_KS18_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS18_KS18_UCKDF_SHIFT            (16U)
#define S50_ELS_KS18_KS18_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UCKDF_SHIFT)) & S50_ELS_KS18_KS18_UCKDF_MASK)

#define S50_ELS_KS18_KS18_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS18_KS18_UHKDF_SHIFT            (17U)
#define S50_ELS_KS18_KS18_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UHKDF_SHIFT)) & S50_ELS_KS18_KS18_UHKDF_MASK)

#define S50_ELS_KS18_KS18_UECSG_MASK             (0x40000U)
#define S50_ELS_KS18_KS18_UECSG_SHIFT            (18U)
#define S50_ELS_KS18_KS18_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UECSG_SHIFT)) & S50_ELS_KS18_KS18_UECSG_MASK)

#define S50_ELS_KS18_KS18_UECDH_MASK             (0x80000U)
#define S50_ELS_KS18_KS18_UECDH_SHIFT            (19U)
#define S50_ELS_KS18_KS18_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UECDH_SHIFT)) & S50_ELS_KS18_KS18_UECDH_MASK)

#define S50_ELS_KS18_KS18_UAES_MASK              (0x100000U)
#define S50_ELS_KS18_KS18_UAES_SHIFT             (20U)
#define S50_ELS_KS18_KS18_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UAES_SHIFT)) & S50_ELS_KS18_KS18_UAES_MASK)

#define S50_ELS_KS18_KS18_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS18_KS18_UHMAC_SHIFT            (21U)
#define S50_ELS_KS18_KS18_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UHMAC_SHIFT)) & S50_ELS_KS18_KS18_UHMAC_MASK)

#define S50_ELS_KS18_KS18_UKWK_MASK              (0x400000U)
#define S50_ELS_KS18_KS18_UKWK_SHIFT             (22U)
#define S50_ELS_KS18_KS18_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKWK_SHIFT)) & S50_ELS_KS18_KS18_UKWK_MASK)

#define S50_ELS_KS18_KS18_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS18_KS18_UKUOK_SHIFT            (23U)
#define S50_ELS_KS18_KS18_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKUOK_SHIFT)) & S50_ELS_KS18_KS18_UKUOK_MASK)

#define S50_ELS_KS18_KS18_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS18_KS18_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS18_KS18_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UTLSPMS_SHIFT)) & S50_ELS_KS18_KS18_UTLSPMS_MASK)

#define S50_ELS_KS18_KS18_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS18_KS18_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS18_KS18_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UTLSMS_SHIFT)) & S50_ELS_KS18_KS18_UTLSMS_MASK)

#define S50_ELS_KS18_KS18_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS18_KS18_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS18_KS18_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKGSRC_SHIFT)) & S50_ELS_KS18_KS18_UKGSRC_MASK)

#define S50_ELS_KS18_KS18_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS18_KS18_UHWO_SHIFT             (27U)
#define S50_ELS_KS18_KS18_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UHWO_SHIFT)) & S50_ELS_KS18_KS18_UHWO_MASK)

#define S50_ELS_KS18_KS18_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS18_KS18_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS18_KS18_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UWRPOK_SHIFT)) & S50_ELS_KS18_KS18_UWRPOK_MASK)

#define S50_ELS_KS18_KS18_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS18_KS18_UDUK_SHIFT             (29U)
#define S50_ELS_KS18_KS18_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UDUK_SHIFT)) & S50_ELS_KS18_KS18_UDUK_MASK)

#define S50_ELS_KS18_KS18_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS18_KS18_UPPROT_SHIFT           (30U)
#define S50_ELS_KS18_KS18_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UPPROT_SHIFT)) & S50_ELS_KS18_KS18_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS19 - Status Register */
/*! @{ */

#define S50_ELS_KS19_KS19_KSIZE_MASK             (0x3U)
#define S50_ELS_KS19_KS19_KSIZE_SHIFT            (0U)
/*! KS19_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define S50_ELS_KS19_KS19_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_KSIZE_SHIFT)) & S50_ELS_KS19_KS19_KSIZE_MASK)

#define S50_ELS_KS19_KS19_KACT_MASK              (0x20U)
#define S50_ELS_KS19_KS19_KACT_SHIFT             (5U)
#define S50_ELS_KS19_KS19_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_KACT_SHIFT)) & S50_ELS_KS19_KS19_KACT_MASK)

#define S50_ELS_KS19_KS19_KBASE_MASK             (0x40U)
#define S50_ELS_KS19_KS19_KBASE_SHIFT            (6U)
#define S50_ELS_KS19_KS19_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_KBASE_SHIFT)) & S50_ELS_KS19_KS19_KBASE_MASK)

#define S50_ELS_KS19_KS19_FGP_MASK               (0x80U)
#define S50_ELS_KS19_KS19_FGP_SHIFT              (7U)
#define S50_ELS_KS19_KS19_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_FGP_SHIFT)) & S50_ELS_KS19_KS19_FGP_MASK)

#define S50_ELS_KS19_KS19_FRTN_MASK              (0x100U)
#define S50_ELS_KS19_KS19_FRTN_SHIFT             (8U)
#define S50_ELS_KS19_KS19_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_FRTN_SHIFT)) & S50_ELS_KS19_KS19_FRTN_MASK)

#define S50_ELS_KS19_KS19_FHWO_MASK              (0x200U)
#define S50_ELS_KS19_KS19_FHWO_SHIFT             (9U)
#define S50_ELS_KS19_KS19_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_FHWO_SHIFT)) & S50_ELS_KS19_KS19_FHWO_MASK)

#define S50_ELS_KS19_KS19_UKPUK_MASK             (0x800U)
#define S50_ELS_KS19_KS19_UKPUK_SHIFT            (11U)
#define S50_ELS_KS19_KS19_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKPUK_SHIFT)) & S50_ELS_KS19_KS19_UKPUK_MASK)

#define S50_ELS_KS19_KS19_UTECDH_MASK            (0x1000U)
#define S50_ELS_KS19_KS19_UTECDH_SHIFT           (12U)
#define S50_ELS_KS19_KS19_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UTECDH_SHIFT)) & S50_ELS_KS19_KS19_UTECDH_MASK)

#define S50_ELS_KS19_KS19_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS19_KS19_UCMAC_SHIFT            (13U)
#define S50_ELS_KS19_KS19_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UCMAC_SHIFT)) & S50_ELS_KS19_KS19_UCMAC_MASK)

#define S50_ELS_KS19_KS19_UKSK_MASK              (0x4000U)
#define S50_ELS_KS19_KS19_UKSK_SHIFT             (14U)
#define S50_ELS_KS19_KS19_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKSK_SHIFT)) & S50_ELS_KS19_KS19_UKSK_MASK)

#define S50_ELS_KS19_KS19_URTF_MASK              (0x8000U)
#define S50_ELS_KS19_KS19_URTF_SHIFT             (15U)
#define S50_ELS_KS19_KS19_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_URTF_SHIFT)) & S50_ELS_KS19_KS19_URTF_MASK)

#define S50_ELS_KS19_KS19_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS19_KS19_UCKDF_SHIFT            (16U)
#define S50_ELS_KS19_KS19_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UCKDF_SHIFT)) & S50_ELS_KS19_KS19_UCKDF_MASK)

#define S50_ELS_KS19_KS19_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS19_KS19_UHKDF_SHIFT            (17U)
#define S50_ELS_KS19_KS19_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UHKDF_SHIFT)) & S50_ELS_KS19_KS19_UHKDF_MASK)

#define S50_ELS_KS19_KS19_UECSG_MASK             (0x40000U)
#define S50_ELS_KS19_KS19_UECSG_SHIFT            (18U)
#define S50_ELS_KS19_KS19_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UECSG_SHIFT)) & S50_ELS_KS19_KS19_UECSG_MASK)

#define S50_ELS_KS19_KS19_UECDH_MASK             (0x80000U)
#define S50_ELS_KS19_KS19_UECDH_SHIFT            (19U)
#define S50_ELS_KS19_KS19_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UECDH_SHIFT)) & S50_ELS_KS19_KS19_UECDH_MASK)

#define S50_ELS_KS19_KS19_UAES_MASK              (0x100000U)
#define S50_ELS_KS19_KS19_UAES_SHIFT             (20U)
#define S50_ELS_KS19_KS19_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UAES_SHIFT)) & S50_ELS_KS19_KS19_UAES_MASK)

#define S50_ELS_KS19_KS19_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS19_KS19_UHMAC_SHIFT            (21U)
#define S50_ELS_KS19_KS19_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UHMAC_SHIFT)) & S50_ELS_KS19_KS19_UHMAC_MASK)

#define S50_ELS_KS19_KS19_UKWK_MASK              (0x400000U)
#define S50_ELS_KS19_KS19_UKWK_SHIFT             (22U)
#define S50_ELS_KS19_KS19_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKWK_SHIFT)) & S50_ELS_KS19_KS19_UKWK_MASK)

#define S50_ELS_KS19_KS19_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS19_KS19_UKUOK_SHIFT            (23U)
#define S50_ELS_KS19_KS19_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKUOK_SHIFT)) & S50_ELS_KS19_KS19_UKUOK_MASK)

#define S50_ELS_KS19_KS19_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS19_KS19_UTLSPMS_SHIFT          (24U)
#define S50_ELS_KS19_KS19_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UTLSPMS_SHIFT)) & S50_ELS_KS19_KS19_UTLSPMS_MASK)

#define S50_ELS_KS19_KS19_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS19_KS19_UTLSMS_SHIFT           (25U)
#define S50_ELS_KS19_KS19_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UTLSMS_SHIFT)) & S50_ELS_KS19_KS19_UTLSMS_MASK)

#define S50_ELS_KS19_KS19_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS19_KS19_UKGSRC_SHIFT           (26U)
#define S50_ELS_KS19_KS19_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKGSRC_SHIFT)) & S50_ELS_KS19_KS19_UKGSRC_MASK)

#define S50_ELS_KS19_KS19_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS19_KS19_UHWO_SHIFT             (27U)
#define S50_ELS_KS19_KS19_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UHWO_SHIFT)) & S50_ELS_KS19_KS19_UHWO_MASK)

#define S50_ELS_KS19_KS19_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS19_KS19_UWRPOK_SHIFT           (28U)
#define S50_ELS_KS19_KS19_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UWRPOK_SHIFT)) & S50_ELS_KS19_KS19_UWRPOK_MASK)

#define S50_ELS_KS19_KS19_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS19_KS19_UDUK_SHIFT             (29U)
#define S50_ELS_KS19_KS19_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UDUK_SHIFT)) & S50_ELS_KS19_KS19_UDUK_MASK)

#define S50_ELS_KS19_KS19_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS19_KS19_UPPROT_SHIFT           (30U)
#define S50_ELS_KS19_KS19_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UPPROT_SHIFT)) & S50_ELS_KS19_KS19_UPPROT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group S50_Register_Masks */


/*!
 * @}
 */ /* end of group S50_Peripheral_Access_Layer */


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


#endif  /* PERI_S50_H_ */

