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
**         CMSIS Peripheral Access Layer for AHBSC
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
 * @file PERI_AHBSC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHBSC
 *
 * CMSIS Peripheral Access Layer for AHBSC
 */

#if !defined(PERI_AHBSC_H_)
#define PERI_AHBSC_H_                            /**< Symbol preventing repeated inclusion */

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
   -- AHBSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC_Peripheral_Access_Layer AHBSC Peripheral Access Layer
 * @{
 */

/** AHBSC - Size of Registers Arrays */
#define AHBSC_FLASH00_MEM_RULE_COUNT              4u
#define AHBSC_FLASH01_MEM_RULE_COUNT              4u
#define AHBSC_ROM_MEM_RULE_COUNT                  4u
#define AHBSC_RAMX_MEM_RULE0_COUNT                3u
#define AHBSC_RAMC_MEM_RULE_COUNT                 2u
#define AHBSC_RAMD_MEM_RULE_COUNT                 2u
#define AHBSC_RAME_MEM_RULE_COUNT                 2u
#define AHBSC_RAMF_MEM_RULE_COUNT                 2u
#define AHBSC_RAMG_MEM_RULE_COUNT                 2u
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_COUNT     4u
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_COUNT   6u
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_COUNT     4u
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_COUNT  6u
#define AHBSC_SEC_VIO_ADDRN_COUNT                 32u
#define AHBSC_SEC_VIO_MISC_INFON_COUNT            32u
#define AHBSC_SEC_GPIO_MASKN_COUNT                2u

/** AHBSC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t FLASH00_MEM_RULE[AHBSC_FLASH00_MEM_RULE_COUNT]; /**< Flash Memory Rule, array offset: 0x10, array step: 0x4 */
  __IO uint32_t FLASH01_MEM_RULE[AHBSC_FLASH01_MEM_RULE_COUNT]; /**< Flash Memory Rule, array offset: 0x20, array step: 0x4 */
  __IO uint32_t FLASH02_MEM_RULE;                  /**< Flash Memory Rule, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FLASH03_MEM_RULE;                  /**< Flash Memory Rule, offset: 0x40 */
       uint8_t RESERVED_2[28];
  __IO uint32_t ROM_MEM_RULE[AHBSC_ROM_MEM_RULE_COUNT]; /**< ROM Memory Rule, array offset: 0x60, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t RAMX_MEM_RULE[AHBSC_RAMX_MEM_RULE0_COUNT]; /**< RAMX Memory Rule, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_4[20];
  __IO uint32_t RAMA_MEM_RULE;                     /**< RAMA Memory Rule 0, offset: 0xA0 */
       uint8_t RESERVED_5[28];
  __IO uint32_t RAMB_MEM_RULE;                     /**< RAMB Memory Rule, offset: 0xC0 */
       uint8_t RESERVED_6[28];
  __IO uint32_t RAMC_MEM_RULE[AHBSC_RAMC_MEM_RULE_COUNT]; /**< RAMC Memory Rule, array offset: 0xE0, array step: 0x4 */
       uint8_t RESERVED_7[24];
  __IO uint32_t RAMD_MEM_RULE[AHBSC_RAMD_MEM_RULE_COUNT]; /**< RAMD Memory Rule, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_8[24];
  __IO uint32_t RAME_MEM_RULE[AHBSC_RAME_MEM_RULE_COUNT]; /**< RAME Memory Rule, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_9[24];
  __IO uint32_t RAMF_MEM_RULE[AHBSC_RAMF_MEM_RULE_COUNT]; /**< RAMF Memory Rule, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_10[24];
  __IO uint32_t RAMG_MEM_RULE[AHBSC_RAMG_MEM_RULE_COUNT]; /**< RAMG Memory Rule, array offset: 0x160, array step: 0x4 */
       uint8_t RESERVED_11[24];
  __IO uint32_t RAMH_MEM_RULE;                     /**< RAMH Memory Rule, offset: 0x180 */
       uint8_t RESERVED_12[28];
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE0;   /**< APB Bridge Group 0 Memory Rule 0, offset: 0x1A0 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE1;   /**< APB Bridge Group 0 Memory Rule 1, offset: 0x1A4 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE2;   /**< APB Bridge Group 0 Rule 2, offset: 0x1A8 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE3;   /**< APB Bridge Group 0 Memory Rule 3, offset: 0x1AC */
  __IO uint32_t APB_PERIPHERAL_GROUP1_MEM_RULE0;   /**< APB Bridge Group 1 Memory Rule 0, offset: 0x1B0 */
  __IO uint32_t APB_PERIPHERAL_GROUP1_MEM_RULE1;   /**< APB Bridge Group 1 Memory Rule 1, offset: 0x1B4 */
       uint8_t RESERVED_13[4];
  __IO uint32_t APB_PERIPHERAL_GROUP1_MEM_RULE2;   /**< APB Bridge Group 1 Memory Rule 2, offset: 0x1BC */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE0;      /**< AIPS Bridge Group 0 Memory Rule 0, offset: 0x1C0 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE1;      /**< AIPS Bridge Group 0 Memory Rule 1, offset: 0x1C4 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE2;      /**< AIPS Bridge Group 0 Memory Rule 2, offset: 0x1C8 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE3;      /**< AIPS Bridge Group 0 Memory Rule 3, offset: 0x1CC */
  __IO uint32_t AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0; /**< AHB Peripheral 0 Slave Port 12 Slave Rule 0, offset: 0x1D0 */
  __IO uint32_t AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1; /**< AHB Peripheral 0 Slave Port 12 Slave Rule 1, offset: 0x1D4 */
  __IO uint32_t AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2; /**< AHB Peripheral 0 Slave Port 12 Slave Rule 2, offset: 0x1D8 */
       uint8_t RESERVED_14[4];
  __IO uint32_t AIPS_BRIDGE_GROUP1_MEM_RULE0;      /**< AIPS Bridge Group 1 Rule 0, offset: 0x1E0 */
  __IO uint32_t AIPS_BRIDGE_GROUP1_MEM_RULE1;      /**< AIPS Bridge Group 1 Rule 1, offset: 0x1E4 */
       uint8_t RESERVED_15[8];
  __IO uint32_t AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0; /**< AHB Peripheral 1 Slave Port 13 Slave Rule 0, offset: 0x1F0 */
  __IO uint32_t AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1; /**< AHB Peripheral 1 Slave Port 13 Slave Rule 1, offset: 0x1F4 */
  __IO uint32_t AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2; /**< AHB Peripheral 1 Slave Port 13 Slave Rule 2, offset: 0x1F8 */
       uint8_t RESERVED_16[4];
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE0;      /**< AIPS Bridge Group 2 Rule 0, offset: 0x200 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE1;      /**< AIPS Bridge Group 2 Memory Rule 1, offset: 0x204 */
       uint8_t RESERVED_17[24];
  __IO uint32_t AIPS_BRIDGE_GROUP3_MEM_RULE0;      /**< AIPS Bridge Group 3 Rule 0, offset: 0x220 */
  __IO uint32_t AIPS_BRIDGE_GROUP3_MEM_RULE1;      /**< AIPS Bridge Group 3 Memory Rule 1, offset: 0x224 */
  __IO uint32_t AIPS_BRIDGE_GROUP3_MEM_RULE2;      /**< AIPS Bridge Group 3 Rule 2, offset: 0x228 */
  __IO uint32_t AIPS_BRIDGE_GROUP3_MEM_RULE3;      /**< AIPS Bridge Group 3 Rule 3, offset: 0x22C */
       uint8_t RESERVED_18[16];
  __IO uint32_t AIPS_BRIDGE_GROUP4_MEM_RULE0;      /**< AIPS Bridge Group 4 Rule 0, offset: 0x240 */
  __IO uint32_t AIPS_BRIDGE_GROUP4_MEM_RULE1;      /**< AIPS Bridge Group 4 Rule 1, offset: 0x244 */
  __IO uint32_t AIPS_BRIDGE_GROUP4_MEM_RULE2;      /**< AIPS Bridge Group 4 Rule 2, offset: 0x248 */
  __IO uint32_t AIPS_BRIDGE_GROUP4_MEM_RULE3;      /**< AIPS Bridge Group 4 Rule 3, offset: 0x24C */
  __IO uint32_t AHB_SECURE_CTRL_PERIPHERAL_RULE0;  /**< AHB Secure Control Peripheral Rule 0, offset: 0x250 */
       uint8_t RESERVED_19[28];
  __IO uint32_t FLEXSPI0_REGION0_MEM_RULE[AHBSC_FLEXSPI0_REGION0_MEM_RULE_COUNT]; /**< FLEXSPI0 Region 0 Memory Rule, array offset: 0x270, array step: 0x4 */
  struct {                                         /* offset: 0x280, array step: 0x10 */
    __IO uint32_t FLEXSPI0_REGION_MEM_RULE0;         /**< FLEXSPI0 Region 1 Memory Rule 0..FLEXSPI0 Region 6 Memory Rule 0, array offset: 0x280, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } FLEXSPI0_REGION1_6_MEM_RULE[AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_COUNT];
  __IO uint32_t FLEXSPI0_REGION7_MEM_RULE[AHBSC_FLEXSPI0_REGION7_MEM_RULE_COUNT]; /**< FLEXSPI0 Region 7 Memory Rule, array offset: 0x2E0, array step: 0x4 */
  struct {                                         /* offset: 0x2F0, array step: 0x10 */
    __IO uint32_t FLEXSPI0_REGION_MEM_RULE0;         /**< FLEXSPI0 Region 8 Memory Rule 0..FLEXSPI0 Region 13 Memory Rule 0, array offset: 0x2F0, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } FLEXSPI0_REGION8_13_MEM_RULE[AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_COUNT];
       uint8_t RESERVED_20[2736];
  __I  uint32_t SEC_VIO_ADDR[AHBSC_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address, array offset: 0xE00, array step: 0x4 */
  __I  uint32_t SEC_VIO_MISC_INFO[AHBSC_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address, array offset: 0xE80, array step: 0x4 */
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address, offset: 0xF00 */
       uint8_t RESERVED_21[124];
  __IO uint32_t SEC_GPIO_MASK[AHBSC_SEC_GPIO_MASKN_COUNT]; /**< GPIO Mask for Port 0..GPIO Mask for Port 1, array offset: 0xF80, array step: 0x4 */
       uint8_t RESERVED_22[16];
  __IO uint32_t SEC_CPU1_INT_MASK0;                /**< Secure Interrupt Mask 0 for CPU1, offset: 0xF98 */
  __IO uint32_t SEC_CPU1_INT_MASK1;                /**< Secure Interrupt Mask 1 for CPU1, offset: 0xF9C */
  __IO uint32_t SEC_CPU1_INT_MASK2;                /**< Secure Interrupt Mask 2 for CPU1, offset: 0xFA0 */
  __IO uint32_t SEC_CPU1_INT_MASK3;                /**< Secure Interrupt Mask 3 for CPU1, offset: 0xFA4 */
  __IO uint32_t SEC_CPU1_INT_MASK4;                /**< Secure Interrupt Mask 4 for CPU1, offset: 0xFA8 */
       uint8_t RESERVED_23[16];
  __IO uint32_t SEC_GP_REG_LOCK;                   /**< Secure Mask Lock, offset: 0xFBC */
       uint8_t RESERVED_24[16];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level, offset: 0xFD4 */
       uint8_t RESERVED_25[20];
  __IO uint32_t CPU0_LOCK_REG;                     /**< Miscellaneous CPU0 Control Signals, offset: 0xFEC */
  __IO uint32_t CPU1_LOCK_REG;                     /**< Miscellaneous CPU1 Control Signals, offset: 0xFF0 */
       uint8_t RESERVED_26[4];
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< Secure Control Duplicate, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< Secure Control, offset: 0xFFC */
} AHBSC_Type;

/* ----------------------------------------------------------------------------
   -- AHBSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC_Register_Masks AHBSC Register Masks
 * @{
 */

/*! @name FLASH00_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define AHBSC_FLASH00_MEM_RULE_RULE0_MASK        (0x3U)
#define AHBSC_FLASH00_MEM_RULE_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE0_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE1_MASK        (0x30U)
#define AHBSC_FLASH00_MEM_RULE_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE1_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE2_MASK        (0x300U)
#define AHBSC_FLASH00_MEM_RULE_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE2_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE3_MASK        (0x3000U)
#define AHBSC_FLASH00_MEM_RULE_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE3_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE4_MASK        (0x30000U)
#define AHBSC_FLASH00_MEM_RULE_RULE4_SHIFT       (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE4(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE4_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE4_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE5_MASK        (0x300000U)
#define AHBSC_FLASH00_MEM_RULE_RULE5_SHIFT       (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE5(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE5_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE5_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE6_MASK        (0x3000000U)
#define AHBSC_FLASH00_MEM_RULE_RULE6_SHIFT       (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE6(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE6_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE6_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE7_MASK        (0x30000000U)
#define AHBSC_FLASH00_MEM_RULE_RULE7_SHIFT       (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE7(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE7_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name FLASH01_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define AHBSC_FLASH01_MEM_RULE_RULE0_MASK        (0x3U)
#define AHBSC_FLASH01_MEM_RULE_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE0_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE1_MASK        (0x30U)
#define AHBSC_FLASH01_MEM_RULE_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE1_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE2_MASK        (0x300U)
#define AHBSC_FLASH01_MEM_RULE_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE2_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE3_MASK        (0x3000U)
#define AHBSC_FLASH01_MEM_RULE_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE3_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE4_MASK        (0x30000U)
#define AHBSC_FLASH01_MEM_RULE_RULE4_SHIFT       (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE4(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE4_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE4_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE5_MASK        (0x300000U)
#define AHBSC_FLASH01_MEM_RULE_RULE5_SHIFT       (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE5(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE5_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE5_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE6_MASK        (0x3000000U)
#define AHBSC_FLASH01_MEM_RULE_RULE6_SHIFT       (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE6(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE6_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE6_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE7_MASK        (0x30000000U)
#define AHBSC_FLASH01_MEM_RULE_RULE7_SHIFT       (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE7(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE7_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name FLASH02_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define AHBSC_FLASH02_MEM_RULE_RULE0_MASK        (0x3U)
#define AHBSC_FLASH02_MEM_RULE_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE0_MASK)

#define AHBSC_FLASH02_MEM_RULE_RULE1_MASK        (0x30U)
#define AHBSC_FLASH02_MEM_RULE_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE1_MASK)

#define AHBSC_FLASH02_MEM_RULE_RULE2_MASK        (0x300U)
#define AHBSC_FLASH02_MEM_RULE_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE2_MASK)

#define AHBSC_FLASH02_MEM_RULE_RULE3_MASK        (0x3000U)
#define AHBSC_FLASH02_MEM_RULE_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE3_MASK)
/*! @} */

/*! @name FLASH03_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define AHBSC_FLASH03_MEM_RULE_RULE0_MASK        (0x3U)
#define AHBSC_FLASH03_MEM_RULE_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE0_MASK)

#define AHBSC_FLASH03_MEM_RULE_RULE1_MASK        (0x30U)
#define AHBSC_FLASH03_MEM_RULE_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE1_MASK)

#define AHBSC_FLASH03_MEM_RULE_RULE2_MASK        (0x300U)
#define AHBSC_FLASH03_MEM_RULE_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE2_MASK)

#define AHBSC_FLASH03_MEM_RULE_RULE3_MASK        (0x3000U)
#define AHBSC_FLASH03_MEM_RULE_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE3_MASK)

#define AHBSC_FLASH03_MEM_RULE_RULE4_MASK        (0x30000U)
#define AHBSC_FLASH03_MEM_RULE_RULE4_SHIFT       (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE4(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE4_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE4_MASK)

#define AHBSC_FLASH03_MEM_RULE_RULE5_MASK        (0x300000U)
#define AHBSC_FLASH03_MEM_RULE_RULE5_SHIFT       (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE5(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE5_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE5_MASK)

#define AHBSC_FLASH03_MEM_RULE_RULE6_MASK        (0x3000000U)
#define AHBSC_FLASH03_MEM_RULE_RULE6_SHIFT       (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE6(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE6_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE6_MASK)

#define AHBSC_FLASH03_MEM_RULE_RULE7_MASK        (0x30000000U)
#define AHBSC_FLASH03_MEM_RULE_RULE7_SHIFT       (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH03_MEM_RULE_RULE7(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH03_MEM_RULE_RULE7_SHIFT)) & AHBSC_FLASH03_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name ROM_MEM_RULE - ROM Memory Rule */
/*! @{ */

#define AHBSC_ROM_MEM_RULE_RULE0_MASK            (0x3U)
#define AHBSC_ROM_MEM_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE0_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE0_MASK)

#define AHBSC_ROM_MEM_RULE_RULE1_MASK            (0x30U)
#define AHBSC_ROM_MEM_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE1_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE1_MASK)

#define AHBSC_ROM_MEM_RULE_RULE2_MASK            (0x300U)
#define AHBSC_ROM_MEM_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE2_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE2_MASK)

#define AHBSC_ROM_MEM_RULE_RULE3_MASK            (0x3000U)
#define AHBSC_ROM_MEM_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE3_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE3_MASK)

#define AHBSC_ROM_MEM_RULE_RULE4_MASK            (0x30000U)
#define AHBSC_ROM_MEM_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE4_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE4_MASK)

#define AHBSC_ROM_MEM_RULE_RULE5_MASK            (0x300000U)
#define AHBSC_ROM_MEM_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE5_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE5_MASK)

#define AHBSC_ROM_MEM_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC_ROM_MEM_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE6_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE6_MASK)

#define AHBSC_ROM_MEM_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC_ROM_MEM_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE7_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMX_MEM_RULE0_RAMX_MEM_RULE - RAMX Memory Rule */
/*! @{ */

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE4_MASK (0x30000U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE5_MASK (0x300000U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE6_MASK (0x3000000U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE7_MASK (0x30000000U)
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_RULE7_MASK)
/*! @} */

/* The count of AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE */
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_COUNT (3U)

/*! @name RAMA_MEM_RULE - RAMA Memory Rule 0 */
/*! @{ */

#define AHBSC_RAMA_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMA_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMA_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMA_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMA_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMA_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMA_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMA_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMA_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMB_MEM_RULE - RAMB Memory Rule */
/*! @{ */

#define AHBSC_RAMB_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMB_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMB_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMB_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMB_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMB_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMB_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMB_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMB_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMC_MEM_RULE - RAMC Memory Rule */
/*! @{ */

#define AHBSC_RAMC_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMC_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMC_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMC_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMC_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMC_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMC_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMC_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMC_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMC_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMC_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMC_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMC_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMC_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMC_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMC_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMC_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMC_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMC_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMD_MEM_RULE - RAMD Memory Rule */
/*! @{ */

#define AHBSC_RAMD_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMD_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMD_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMD_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMD_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMD_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMD_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMD_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMD_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMD_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMD_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMD_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMD_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMD_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMD_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMD_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMD_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMD_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMD_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAME_MEM_RULE - RAME Memory Rule */
/*! @{ */

#define AHBSC_RAME_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAME_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE0_MASK)

#define AHBSC_RAME_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAME_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE1_MASK)

#define AHBSC_RAME_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAME_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE2_MASK)

#define AHBSC_RAME_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAME_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE3_MASK)

#define AHBSC_RAME_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAME_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE4_MASK)

#define AHBSC_RAME_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAME_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE5_MASK)

#define AHBSC_RAME_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAME_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE6_MASK)

#define AHBSC_RAME_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAME_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAME_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAME_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAME_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMF_MEM_RULE - RAMF Memory Rule */
/*! @{ */

#define AHBSC_RAMF_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMF_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMF_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMF_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMF_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMF_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMF_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMF_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMF_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMF_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMF_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMF_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMF_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMF_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMF_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMF_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMF_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMF_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMF_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMG_MEM_RULE - RAMG Memory Rule */
/*! @{ */

#define AHBSC_RAMG_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMG_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMG_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMG_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMG_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMG_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMG_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMG_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMG_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMG_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMG_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMG_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMG_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMG_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMG_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMG_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMG_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMG_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMG_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMH_MEM_RULE - RAMH Memory Rule */
/*! @{ */

#define AHBSC_RAMH_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMH_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMH_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMH_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMH_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMH_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMH_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMH_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMH_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMH_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMH_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMH_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMH_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMH_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMH_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMH_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMH_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMH_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMH_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE0 - APB Bridge Group 0 Memory Rule 0 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_MASK (0x3U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_SHIFT (0U)
/*! SYSCON - SYSCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_SHIFT (16U)
/*! PINT0 - PINT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_SHIFT (24U)
/*! INPUTMUX - INPUTMUX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE1 - APB Bridge Group 0 Memory Rule 1 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_SHIFT (16U)
/*! CTIMER0 - CTIMER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_MASK (0x300000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_SHIFT (20U)
/*! CTIMER1 - CTIMER1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER2_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER2_SHIFT (24U)
/*! CTIMER2 - CTIMER2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER2_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER2_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER3_MASK (0x30000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER3_SHIFT (28U)
/*! CTIMER3 - CTIMER3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER3_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER3_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE2 - APB Bridge Group 0 Rule 2 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_CTIMER4_MASK (0x3U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_CTIMER4_SHIFT (0U)
/*! CTIMER4 - CTIMER4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_CTIMER4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_CTIMER4_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_CTIMER4_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_FREQME0_MASK (0x30U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_FREQME0_SHIFT (4U)
/*! FREQME0 - FREQME0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_FREQME0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_FREQME0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_FREQME0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_UTCIK0_MASK (0x300U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_UTCIK0_SHIFT (8U)
/*! UTCIK0 - UTCIK0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_UTCIK0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_UTCIK0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_UTCIK0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_MRT0_MASK (0x3000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_MRT0_SHIFT (12U)
/*! MRT0 - MRT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_MRT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_MRT0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_MRT0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_OSTIMER0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_OSTIMER0_SHIFT (16U)
/*! OSTIMER0 - OSTIMER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_OSTIMER0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_OSTIMER0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_OSTIMER0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT0_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT0_SHIFT (24U)
/*! WWDT0 - WWDT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT1_MASK (0x30000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT1_SHIFT (28U)
/*! WWDT1 - WWDT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT1_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE3 - APB Bridge Group 0 Memory Rule 3 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE3_CACHE64_POLSEL0_MASK (0x3000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE3_CACHE64_POLSEL0_SHIFT (12U)
/*! CACHE64_POLSEL0 - CACHE64_POLSEL0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE3_CACHE64_POLSEL0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE3_CACHE64_POLSEL0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE3_CACHE64_POLSEL0_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP1_MEM_RULE0 - APB Bridge Group 1 Memory Rule 0 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C0_MASK (0x30U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C0_SHIFT (4U)
/*! I3C0 - I3C0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C1_MASK (0x300U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C1_SHIFT (8U)
/*! I3C1 - I3C1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C1_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_GDET_MASK (0x300000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_GDET_SHIFT (20U)
/*! GDET - GDET
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_GDET(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_GDET_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_GDET_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_ITRC_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_ITRC_SHIFT (24U)
/*! ITRC - ITRC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_ITRC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_ITRC_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_ITRC_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP1_MEM_RULE1 - APB Bridge Group 1 Memory Rule 1 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_MASK (0x3000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_SHIFT (12U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS0_SHIFT (16U)
/*! PUF_ALIAS0 - PUF_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS1_MASK (0x300000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS1_SHIFT (20U)
/*! PUF_ALIAS1 - PUF_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS1_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS2_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS2_SHIFT (24U)
/*! PUF_ALIAS2 - PUF_ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS2_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS2_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS3_MASK (0x30000000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS3_SHIFT (28U)
/*! PUF_ALIAS3 - PUF_ALIAS3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS3_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS3_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP1_MEM_RULE2 - APB Bridge Group 1 Memory Rule 2 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SM3_MASK (0x30U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SM3_SHIFT (4U)
/*! SM3 - SM3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SM3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SM3_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SM3_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_COOLFLUX_MASK (0x300U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_COOLFLUX_SHIFT (8U)
/*! COOLFLUX - COOLFLUX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_COOLFLUX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_COOLFLUX_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_COOLFLUX_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SMARTDMA_MASK (0x3000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SMARTDMA_SHIFT (12U)
/*! SMARTDMA - SmartDMA
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SMARTDMA(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SMARTDMA_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SMARTDMA_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_PLU_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_PLU_SHIFT (16U)
/*! PLU - PLU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_PLU(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_PLU_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_PLU_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE0 - AIPS Bridge Group 0 Memory Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS0_SHIFT (0U)
/*! GPIO5_ALIAS0 - GPIO5_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS1_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS1_SHIFT (4U)
/*! GPIO5_ALIAS1 - GPIO5_ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PORT5_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PORT5_SHIFT (8U)
/*! PORT5 - PORT5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PORT5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PORT5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PORT5_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_FMU0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_FMU0_SHIFT (12U)
/*! FMU0 - FMU0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_FMU0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_FMU0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_FMU0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SCG0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SCG0_SHIFT (16U)
/*! SCG0 - SCG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SCG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SCG0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SCG0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SPC0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SPC0_SHIFT (20U)
/*! SPC0 - SPC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SPC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SPC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SPC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_WUU0_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_WUU0_SHIFT (24U)
/*! WUU0 - WUU0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_WUU0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_WUU0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_WUU0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_TRO0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_TRO0_SHIFT (28U)
/*! TRO0 - TRO0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_TRO0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_TRO0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_TRO0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE1 - AIPS Bridge Group 0 Memory Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR0_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR0_SHIFT (8U)
/*! LPTMR0 - LPTMR0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR1_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR1_SHIFT (12U)
/*! LPTMR1 - LPTMR1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_RTC_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_RTC_SHIFT (16U)
/*! RTC - RTC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_RTC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_RTC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_RTC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_FMU_TEST_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_FMU_TEST_SHIFT (24U)
/*! FMU_TEST - FMU_TEST
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_FMU_TEST(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_FMU_TEST_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_FMU_TEST_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE2 - AIPS Bridge Group 0 Memory Rule 2 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_TSI_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_TSI_SHIFT (0U)
/*! TSI - TSI
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_TSI(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_TSI_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_TSI_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP0_SHIFT (4U)
/*! CMP0 - CMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP1_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP1_SHIFT (8U)
/*! CMP1 - CMP1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP2_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP2_SHIFT (12U)
/*! CMP2 - CMP2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_SHIFT (16U)
/*! ELS - ELS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS1_SHIFT (20U)
/*! ELS_ALIAS1 - ELS_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS2_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS2_SHIFT (24U)
/*! ELS_ALIAS2 - ELS_ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS3_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS3_SHIFT (28U)
/*! ELS_ALIAS3 - ELS_ALIAS3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE3 - AIPS Bridge Group 0 Memory Rule 3 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_DIGTMP_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_DIGTMP_SHIFT (0U)
/*! DIGTMP - DIGTMP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_DIGTMP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_DIGTMP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_DIGTMP_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_VBAT_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_VBAT_SHIFT (4U)
/*! VBAT - VBAT
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_VBAT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_VBAT_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_VBAT_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_TRNG_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_TRNG_SHIFT (8U)
/*! TRNG - TRNG
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_TRNG(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_TRNG_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_TRNG_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_EIM0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_EIM0_SHIFT (12U)
/*! EIM0 - EIM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_EIM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_EIM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_EIM0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_ERM0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_ERM0_SHIFT (16U)
/*! ERM0 - ERM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_ERM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_ERM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_ERM0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_INTM0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_INTM0_SHIFT (20U)
/*! INTM0 - INTM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_INTM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_INTM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_INTM0_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0 - AHB Peripheral 0 Slave Port 12 Slave Rule 0 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_EDMA0_CH15_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_EDMA0_CH15_SHIFT (4U)
/*! eDMA0_CH15 - eDMA0_CH15
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_EDMA0_CH15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_EDMA0_CH15_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_EDMA0_CH15_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_SCT0_MASK (0x300U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_SCT0_SHIFT (8U)
/*! SCT0 - SCT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_SCT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_SCT0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_SCT0_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM0_MASK (0x3000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM0_SHIFT (12U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM0_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM1_MASK (0x30000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM1_SHIFT (16U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM1_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM1_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM2_MASK (0x300000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM2_SHIFT (20U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM2_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM2_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM3_MASK (0x3000000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM3_SHIFT (24U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM3_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM3_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_GPIO0_ALIAS0_MASK (0x30000000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_GPIO0_ALIAS0_SHIFT (28U)
/*! GPIO0_ALIAS0 - GPIO0_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_GPIO0_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_GPIO0_ALIAS0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_GPIO0_ALIAS0_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1 - AHB Peripheral 0 Slave Port 12 Slave Rule 1 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO0_ALIAS1_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO0_ALIAS1_SHIFT (0U)
/*! GPIO0_ALIAS1 - GPIO0_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO0_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO0_ALIAS1_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO0_ALIAS1_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS0_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS0_SHIFT (4U)
/*! GPIO1_ALIAS0 - GPIO1_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS0_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS1_MASK (0x300U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS1_SHIFT (8U)
/*! GPIO1_ALIAS1 - GPIO1_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS1_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS1_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS0_MASK (0x3000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS0_SHIFT (12U)
/*! GPIO2_ALIAS0 - GPIO2_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS0_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS1_MASK (0x30000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS1_SHIFT (16U)
/*! GPIO2_ALIAS1 - GPIO2_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS1_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS1_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS0_MASK (0x300000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS0_SHIFT (20U)
/*! GPIO3_ALIAS0 - GPIO3_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS0_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS1_MASK (0x3000000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS1_SHIFT (24U)
/*! GPIO3_ALIAS1 - GPIO3_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS1_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS1_MASK)

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO4_ALIAS0_MASK (0x30000000U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO4_ALIAS0_SHIFT (28U)
/*! GPIO4_ALIAS0 - GPIO4_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO4_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO4_ALIAS0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO4_ALIAS0_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2 - AHB Peripheral 0 Slave Port 12 Slave Rule 2 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2_GPIO4_ALIAS1_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2_GPIO4_ALIAS1_SHIFT (0U)
/*! GPIO4_ALIAS1 - GPIO4_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2_GPIO4_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2_GPIO4_ALIAS1_SHIFT)) & AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2_GPIO4_ALIAS1_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP1_MEM_RULE0 - AIPS Bridge Group 1 Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_MP_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_MP_SHIFT (0U)
/*! eDMA0_MP - eDMA0_MP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_MP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_MP_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH0_SHIFT (4U)
/*! eDMA0_CH0 - eDMA0_CH0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH1_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH1_SHIFT (8U)
/*! eDMA0_CH1 - eDMA0_CH1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH2_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH2_SHIFT (12U)
/*! eDMA0_CH2 - eDMA0_CH2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH3_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH3_SHIFT (16U)
/*! eDMA0_CH3 - FLEXSPI0 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH4_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH4_SHIFT (20U)
/*! eDMA0_CH4 - eDMA0_CH4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH4_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH5_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH5_SHIFT (24U)
/*! eDMA0_CH5 - eDMA0_CH5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH5_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH6_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH6_SHIFT (28U)
/*! eDMA0_CH6 - eDMA0_CH6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH6_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH6_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP1_MEM_RULE1 - AIPS Bridge Group 1 Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH7_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH7_SHIFT (0U)
/*! eDMA0_CH7 - eDMA0_CH7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH7_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH7_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH8_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH8_SHIFT (4U)
/*! eDMA0_CH8 - eDMA0_CH8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH8_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH8_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH9_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH9_SHIFT (8U)
/*! eDMA0_CH9 - eDMA0_CH9
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH9_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH9_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH10_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH10_SHIFT (12U)
/*! eDMA0_CH10 - eDMA0_CH10
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH10_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH10_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH11_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH11_SHIFT (16U)
/*! eDMA0_CH11 - FLEXSPI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH11_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH11_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH12_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH12_SHIFT (20U)
/*! eDMA0_CH12 - eDMA0_CH12
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH12_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH12_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH13_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH13_SHIFT (24U)
/*! eDMA0_CH13 - eDMA0_CH13
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH13_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH13_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH14_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH14_SHIFT (28U)
/*! eDMA0_CH14 - eDMA0_CH14
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH14_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH14_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0 - AHB Peripheral 1 Slave Port 13 Slave Rule 0 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_EDMA1_CH15_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_EDMA1_CH15_SHIFT (4U)
/*! eDMA1_CH15 - eDMA1_CH15
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_EDMA1_CH15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_EDMA1_CH15_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_EDMA1_CH15_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_SEMA42_MASK (0x300U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_SEMA42_SHIFT (8U)
/*! SEMA42 - SEMA42
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_SEMA42(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_SEMA42_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_SEMA42_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_MAILBOX_MASK (0x3000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_MAILBOX_SHIFT (12U)
/*! MAILBOX - MAILBOX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_MAILBOX_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_MAILBOX_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_PKC_RAM_MASK (0x30000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_PKC_RAM_SHIFT (16U)
/*! PKC_RAM - PKC_RAM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_PKC_RAM(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_PKC_RAM_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_PKC_RAM_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM4_MASK (0x300000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM4_SHIFT (20U)
/*! FLEXCOMM4 - FLEXCOMM4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM4_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM4_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM5_MASK (0x3000000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM5_SHIFT (24U)
/*! FLEXCOMM5 - FLEXCOMM5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM5_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM5_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM6_MASK (0x30000000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM6_SHIFT (28U)
/*! FLEXCOMM6 - FLEXCOMM6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM6_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM6_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1 - AHB Peripheral 1 Slave Port 13 Slave Rule 1 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM7_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM7_SHIFT (0U)
/*! FLEXCOMM7 - FLEXCOMM7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM7_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM7_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM8_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM8_SHIFT (4U)
/*! FLEXCOMM8 - FLEXCOMM8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM8_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM8_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM9_MASK (0x300U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM9_SHIFT (8U)
/*! FLEXCOMM9 - FLEXCOMM9
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM9_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM9_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_USB_FS_OTG_RAM_MASK (0x3000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_USB_FS_OTG_RAM_SHIFT (12U)
/*! USB_FS_OTG_RAM - USB FS OTG RAM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_USB_FS_OTG_RAM(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_USB_FS_OTG_RAM_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_USB_FS_OTG_RAM_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG0_MASK (0x30000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG0_SHIFT (16U)
/*! CDOG0 - CDOG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG0_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG0_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG1_MASK (0x300000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG1_SHIFT (20U)
/*! CDOG1 - CDOG1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG1_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG1_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_DEBUG_MAILBOX_MASK (0x3000000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_DEBUG_MAILBOX_SHIFT (24U)
/*! DEBUG_MAILBOX - DEBUG_MAILBOX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_DEBUG_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_DEBUG_MAILBOX_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_DEBUG_MAILBOX_MASK)

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_NPU_MASK (0x30000000U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_NPU_SHIFT (28U)
/*! NPU - NPU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_NPU(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_NPU_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_NPU_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2 - AHB Peripheral 1 Slave Port 13 Slave Rule 2 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2_POWERQUAD_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2_POWERQUAD_SHIFT (0U)
/*! POWERQUAD - POWERQUAD
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2_POWERQUAD(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2_POWERQUAD_SHIFT)) & AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2_POWERQUAD_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE0 - AIPS Bridge Group 2 Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_MP_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_MP_SHIFT (0U)
/*! eDMA1_MP - eDMA1_MP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_MP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_MP_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH0_SHIFT (4U)
/*! eDMA1_CH0 - eDMA1_CH0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH1_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH1_SHIFT (8U)
/*! eDMA1_CH1 - eDMA1_CH1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH2_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH2_SHIFT (12U)
/*! eDMA1_CH2 - eDMA1_CH2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH3_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH3_SHIFT (16U)
/*! eDMA1_CH3 - eDMA1_CH3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH4_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH4_SHIFT (20U)
/*! eDMA1_CH4 - eDMA1_CH4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH4_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH5_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH5_SHIFT (24U)
/*! eDMA1_CH5 - eDMA1_CH5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH5_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH6_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH6_SHIFT (28U)
/*! eDMA1_CH6 - eDMA1_CH6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH6_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH6_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE1 - AIPS Bridge Group 2 Memory Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH7_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH7_SHIFT (0U)
/*! eDMA1_CH7 - eDMA1_CH7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH7_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH7_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH8_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH8_SHIFT (4U)
/*! eDMA1_CH8 - eDMA1_CH8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH8_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH8_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH9_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH9_SHIFT (8U)
/*! eDMA1_CH9 - eDMA1_CH9
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH9_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH9_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH10_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH10_SHIFT (12U)
/*! eDMA1_CH10 - eDMA1_CH10
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH10_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH10_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH11_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH11_SHIFT (16U)
/*! eDMA1_CH11 - eDMA1_CH11
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH11_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH11_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH12_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH12_SHIFT (20U)
/*! eDMA1_CH12 - eDMA1_CH12
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH12_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH12_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH13_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH13_SHIFT (24U)
/*! eDMA1_CH13 - eDMA1_CH13
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH13_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH13_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH14_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH14_SHIFT (28U)
/*! eDMA1_CH14 - eDMA1_CH14
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH14_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH14_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP3_MEM_RULE0 - AIPS Bridge Group 3 Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_EWM0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_EWM0_SHIFT (0U)
/*! EWM0 - EWM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_EWM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_EWM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_EWM0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_LPCAC_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_LPCAC_SHIFT (4U)
/*! LPCAC - LPCAC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_LPCAC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_LPCAC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_LPCAC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_FLEXSPI_CMX_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_FLEXSPI_CMX_SHIFT (8U)
/*! FLEXSPI_CMX - FLEXSPI_CMX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_FLEXSPI_CMX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_FLEXSPI_CMX_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_FLEXSPI_CMX_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_SFA_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_SFA_SHIFT (20U)
/*! SFA - SFA
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_SFA(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_SFA_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_SFA_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MBC_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MBC_SHIFT (28U)
/*! MBC - MBC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MBC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MBC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MBC_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP3_MEM_RULE1 - AIPS Bridge Group 3 Memory Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_FLEXSPI_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_FLEXSPI_SHIFT (0U)
/*! FLEXSPI - FLEXSPI
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_FLEXSPI(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_FLEXSPI_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_FLEXSPI_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_OTPC_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_OTPC_SHIFT (4U)
/*! OTPC - OTPC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_OTPC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_OTPC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_OTPC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_CRC_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_CRC_SHIFT (12U)
/*! CRC - CRC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_CRC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_CRC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_CRC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_NPX_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_NPX_SHIFT (16U)
/*! NPX - NPX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_NPX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_NPX_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_NPX_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_PWM_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_PWM_SHIFT (24U)
/*! PWM - PWM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_PWM(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_PWM_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_PWM_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_ENC_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_ENC_SHIFT (28U)
/*! ENC - ENC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_ENC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_ENC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_ENC_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP3_MEM_RULE2 - AIPS Bridge Group 3 Rule 2 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PWM1_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PWM1_SHIFT (0U)
/*! PWM1 - PWM1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PWM1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PWM1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PWM1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_ENC1_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_ENC1_SHIFT (4U)
/*! ENC1 - ENC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_ENC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_ENC1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_ENC1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_EVTG_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_EVTG_SHIFT (8U)
/*! EVTG - EVTG
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_EVTG(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_EVTG_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_EVTG_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE0_SHIFT (16U)
/*! CAN0_RULE0 - CAN0 RULE0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE1_SHIFT (20U)
/*! CAN0_RULE1 - CAN0 RULE1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE2_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE2_SHIFT (24U)
/*! CAN0_RULE2 - CAN0 RULE2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE3_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE3_SHIFT (28U)
/*! CAN0_RULE3 - CAN0 RULE3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP3_MEM_RULE3 - AIPS Bridge Group 3 Rule 3 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE0_SHIFT (0U)
/*! CAN1_RULE0 - CAN1 RULE0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE1_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE1_SHIFT (4U)
/*! CAN1_RULE1 - CAN1 RULE1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE2_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE2_SHIFT (8U)
/*! CAN1_RULE2 - CAN1 RULE2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE3_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE3_SHIFT (12U)
/*! CAN1_RULE3 - CAN1 RULE3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBDCD_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBDCD_SHIFT (16U)
/*! USBDCD - USBDCD
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBDCD(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBDCD_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBDCD_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBFS_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBFS_SHIFT (20U)
/*! USBFS - USBFS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBFS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBFS_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBFS_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP4_MEM_RULE0 - AIPS Bridge Group 4 Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_ENET_MASK (0xFU)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_ENET_SHIFT (0U)
/*! ENET - ENET
 *  0b0000..Non-secure and non-privilege user access allowed
 *  0b0001..Non-secure and privilege access allowed
 *  0b0010..Secure and non-privilege user access allowed
 *  0b0011..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_ENET(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_ENET_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_ENET_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM0_SHIFT (12U)
/*! EMVSIM0 - EMVSIM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM1_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM1_SHIFT (16U)
/*! EMVSIM1 - EMVSIM1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_FLEXIO_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_FLEXIO_SHIFT (20U)
/*! FLEXIO - FLEXIO
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_FLEXIO(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_FLEXIO_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_FLEXIO_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI0_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI0_SHIFT (24U)
/*! SAI0 - SAI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI1_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI1_SHIFT (28U)
/*! SAI1 - SAI1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI1_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP4_MEM_RULE1 - AIPS Bridge Group 4 Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_SINC0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_SINC0_SHIFT (0U)
/*! SINC0 - SINC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_SINC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_SINC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_SINC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USDHC0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USDHC0_SHIFT (4U)
/*! uSDHC0 - uSDHC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USDHC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USDHC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USDHC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHSPHY_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHSPHY_SHIFT (8U)
/*! USBHSPHY - USBHSPHY
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHSPHY(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHSPHY_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHSPHY_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHS_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHS_SHIFT (12U)
/*! USBHS - USBHS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHS_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHS_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_MICD_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_MICD_SHIFT (16U)
/*! MICD - MICD
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_MICD(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_MICD_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_MICD_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC0_SHIFT (20U)
/*! ADC0 - ADC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC1_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC1_SHIFT (24U)
/*! ADC1 - ADC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_DAC0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_DAC0_SHIFT (28U)
/*! DAC0 - DAC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_DAC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_DAC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_DAC0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP4_MEM_RULE2 - AIPS Bridge Group 4 Rule 2 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP0_SHIFT (0U)
/*! OPAMP0 - OPAMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_VREF_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_VREF_SHIFT (4U)
/*! VREF - VREF
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_VREF(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_VREF_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_VREF_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_DAC_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_DAC_SHIFT (8U)
/*! DAC - DAC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_DAC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_DAC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_DAC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP1_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP1_SHIFT (12U)
/*! OPAMP1 - OPAMP1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_HPDAC0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_HPDAC0_SHIFT (16U)
/*! HPDAC0 - HPDAC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_HPDAC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_HPDAC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_HPDAC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP2_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP2_SHIFT (20U)
/*! OPAMP2 - OPAMP2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT0_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT0_SHIFT (24U)
/*! PORT0 - PORT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT1_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT1_SHIFT (28U)
/*! PORT1 - PORT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT1_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP4_MEM_RULE3 - AIPS Bridge Group 4 Rule 3 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT2_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT2_SHIFT (0U)
/*! PORT2 - PORT2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT3_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT3_SHIFT (4U)
/*! PORT3 - PORT3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT4_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT4_SHIFT (8U)
/*! PORT4 - PORT4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT4_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_MTR0_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_MTR0_SHIFT (24U)
/*! MTR0 - MTR0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_MTR0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_MTR0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_MTR0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_ATX0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_ATX0_SHIFT (28U)
/*! ATX0 - ATX0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_ATX0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_ATX0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_ATX0_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_PERIPHERAL_RULE0 - AHB Secure Control Peripheral Rule 0 */
/*! @{ */

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK (0x3U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK)

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK (0x30U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK)

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK (0x300U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK)

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK (0x3000U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION0_MEM_RULE - FLEXSPI0 Region 0 Memory Rule */
/*! @{ */

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0_MASK)

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1_MASK)

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2_MASK)

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3_MASK)

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4_MASK (0x30000U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4_MASK)

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5_MASK (0x300000U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5_MASK)

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6_MASK (0x3000000U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6_MASK)

#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7_MASK (0x30000000U)
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7_SHIFT)) & AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0 - FLEXSPI0 Region 1 Memory Rule 0..FLEXSPI0 Region 6 Memory Rule 0 */
/*! @{ */

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_MASK (0x3U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_MASK (0x30U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_MASK (0x300U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_MASK (0x3000U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_MASK (0x30000U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_MASK (0x300000U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_MASK)
/*! @} */

/* The count of AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_COUNT (6U)

/*! @name FLEXSPI0_REGION7_MEM_RULE - FLEXSPI0 Region 7 Memory Rule */
/*! @{ */

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE0_MASK)

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE1_MASK)

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE2_MASK)

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE3_MASK)

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE4_MASK (0x30000U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE4_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE4_MASK)

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE5_MASK (0x300000U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE5_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE5_MASK)

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE6_MASK (0x3000000U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE6_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE6_MASK)

#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE7_MASK (0x30000000U)
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE7_SHIFT)) & AHBSC_FLEXSPI0_REGION7_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0 - FLEXSPI0 Region 8 Memory Rule 0..FLEXSPI0 Region 13 Memory Rule 0 */
/*! @{ */

#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_MASK (0x3U)
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_SHIFT)) & AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_MASK)

#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_MASK (0x30U)
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_SHIFT)) & AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_MASK)

#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_MASK (0x300U)
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_SHIFT)) & AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_MASK)

#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_MASK (0x3000U)
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_SHIFT)) & AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_MASK)

#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_MASK (0x30000U)
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_SHIFT)) & AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE4_MASK)

#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_MASK (0x300000U)
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_SHIFT)) & AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE5_MASK)
/*! @} */

/* The count of AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0 */
#define AHBSC_FLEXSPI0_REGION8_13_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_COUNT (6U)

/*! @name SEC_VIO_ADDRN_SEC_VIO_ADDR - Security Violation Address */
/*! @{ */

#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK (0xFFFFFFFFU)
#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT (0U)
/*! SEC_VIO_ADDR - Security violation address for AHB layer a reset value 0 */
#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT)) & AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK)
/*! @} */

/* The count of AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR */
#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_COUNT   (32U)

/*! @name SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO - Security Violation Miscellaneous Information at Address */
/*! @{ */

#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator
 *  0b0..Read access
 *  0b1..Write access
 */
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - Security Violation Info Data Access
 *  0b0..Code
 *  0b1..Data
 */
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - Security Violation Info Master Security Level */
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0x1F00U)
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
/*! SEC_VIO_INFO_MASTER - Security violation master number
 *  0b00000..M33 Code
 *  0b00001..M33 System
 *  0b00010..CPU1 (Mirco-CM33) Code
 *  0b00011..SMARTDMA Instruction
 *  0b00100..CPU1 (Mirco-CM33) system
 *  0b00101..SMARTDMA Data
 *  0b00110..eDMA0
 *  0b00111..eDMA1
 *  0b01000..PKC
 *  0b01001..ELS S50
 *  0b01010..PKC M0
 *  0b01011..NPU Operands
 *  0b01100..DSP Instruction
 *  0b01101..DSPX
 *  0b01110..DSPY
 *  0b10000..NPU Data
 *  0b10001..USB FS
 *  0b10010..Ethernet
 *  0b10011..USB HS
 *  0b10100..uSDHC
 */
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO */
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_COUNT (32U)

/*! @name SEC_VIO_INFO_VALID - Security Violation Info Validity for Address */
/*! @{ */

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - Violation information valid flag for AHB port 0
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - Violation information valid flag for AHB port 1
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - Violation information valid flag for AHB port 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - Violation information valid flag for AHB port 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - Violation information valid flag for AHB port 4
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - Violation information valid flag for AHB port 5
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - Violation information valid flag for AHB port 6
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - Violation information valid flag for AHB port 7
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK (0x100U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT (8U)
/*! VIO_INFO_VALID8 - Violation information valid flag for AHB port 8
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK (0x200U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT (9U)
/*! VIO_INFO_VALID9 - Violation information valid flag for AHB port 9
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK (0x400U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT (10U)
/*! VIO_INFO_VALID10 - Violation information valid flag for AHB port 10
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK (0x800U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT (11U)
/*! VIO_INFO_VALID11 - Violation information valid flag for AHB port 11
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK (0x1000U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT (12U)
/*! VIO_INFO_VALID12 - Violation information valid flag for AHB port 12
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK (0x2000U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT (13U)
/*! VIO_INFO_VALID13 - Violation information valid flag for AHB port 13
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK (0x4000U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT (14U)
/*! VIO_INFO_VALID14 - Violation information valid flag for AHB port 14
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK (0x8000U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT (15U)
/*! VIO_INFO_VALID15 - Violation information valid flag for AHB port 15
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK (0x10000U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT (16U)
/*! VIO_INFO_VALID16 - Violation information valid flag for AHB port 16
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID16(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK (0x20000U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT (17U)
/*! VIO_INFO_VALID17 - Violation information valid flag for AHB port 17
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID17(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK (0x40000U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT (18U)
/*! VIO_INFO_VALID18 - Violation information valid flag for AHB port 18
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID18(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK)
/*! @} */

/*! @name SEC_GPIO_MASKN_SEC_GPIO_MASK - GPIO Mask for Port 0..GPIO Mask for Port 1 */
/*! @{ */

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_MASK (0x1U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO0_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_MASK (0x1U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO1_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_MASK (0x2U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO0_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_MASK (0x2U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO1_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_MASK (0x4U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO0_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_MASK (0x4U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO1_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_MASK (0x8U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO0_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_MASK (0x8U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO1_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_MASK (0x10U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO0_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_MASK (0x10U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO1_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_MASK (0x20U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO0_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_MASK (0x20U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO1_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_MASK (0x40U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO0_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_MASK (0x40U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO1_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_MASK (0x80U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO0_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_MASK (0x80U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO1_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_MASK (0x100U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO0_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_MASK (0x100U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO1_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_MASK (0x200U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO0_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_MASK (0x200U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO1_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_MASK (0x400U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO0_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_MASK (0x400U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO1_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_MASK (0x800U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO0_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_MASK (0x800U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO1_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_MASK (0x1000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO0_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_MASK (0x1000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO1_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_MASK (0x2000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO0_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_MASK (0x2000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO1_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_MASK (0x4000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO0_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_MASK (0x4000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO1_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_MASK (0x8000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO0_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_MASK (0x8000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO1_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_MASK (0x10000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO0_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_MASK (0x10000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO1_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_MASK (0x20000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO0_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_MASK (0x20000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO1_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_MASK (0x40000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO0_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_MASK (0x40000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO1_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_MASK (0x80000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO0_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_MASK (0x80000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO1_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_MASK (0x100000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO0_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_MASK (0x100000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO1_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_MASK (0x200000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO0_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_MASK (0x200000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO1_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_MASK (0x400000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO0_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_MASK (0x400000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO1_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_MASK (0x800000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO0_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_MASK (0x800000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO1_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO0_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO1_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO0_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO1_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO0_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO1_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO0_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO1_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO0_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO1_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO0_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO1_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO0_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO1_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO0_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_MASK)

#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO1_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_SHIFT)) & AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_MASK)
/*! @} */

/* The count of AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK */
#define AHBSC_SEC_GPIO_MASKN_SEC_GPIO_MASK_COUNT (2U)

/*! @name SEC_CPU1_INT_MASK0 - Secure Interrupt Mask 0 for CPU1 */
/*! @{ */

#define AHBSC_SEC_CPU1_INT_MASK0_INT0_MASK_MASK  (0x1U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT0_MASK_SHIFT (0U)
/*! INT0_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT0_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT0_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT0_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT1_MASK_MASK  (0x2U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT1_MASK_SHIFT (1U)
/*! INT1_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT1_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT1_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT1_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT2_MASK_MASK  (0x4U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT2_MASK_SHIFT (2U)
/*! INT2_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT2_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT2_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT2_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT3_MASK_MASK  (0x8U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT3_MASK_SHIFT (3U)
/*! INT3_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT3_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT3_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT3_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT4_MASK_MASK  (0x10U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT4_MASK_SHIFT (4U)
/*! INT4_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT4_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT4_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT4_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT5_MASK_MASK  (0x20U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT5_MASK_SHIFT (5U)
/*! INT5_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT5_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT5_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT5_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT6_MASK_MASK  (0x40U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT6_MASK_SHIFT (6U)
/*! INT6_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT6_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT6_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT6_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT7_MASK_MASK  (0x80U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT7_MASK_SHIFT (7U)
/*! INT7_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT7_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT7_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT7_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT8_MASK_MASK  (0x100U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT8_MASK_SHIFT (8U)
/*! INT8_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT8_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT8_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT8_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT9_MASK_MASK  (0x200U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT9_MASK_SHIFT (9U)
/*! INT9_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT9_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT9_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT9_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT10_MASK_MASK (0x400U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT10_MASK_SHIFT (10U)
/*! INT10_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT10_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT10_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT10_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT11_MASK_MASK (0x800U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT11_MASK_SHIFT (11U)
/*! INT11_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT11_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT11_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT11_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT12_MASK_MASK (0x1000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT12_MASK_SHIFT (12U)
/*! INT12_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT12_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT12_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT12_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT13_MASK_MASK (0x2000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT13_MASK_SHIFT (13U)
/*! INT13_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT13_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT13_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT13_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT14_MASK_MASK (0x4000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT14_MASK_SHIFT (14U)
/*! INT14_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT14_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT14_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT14_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT15_MASK_MASK (0x8000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT15_MASK_SHIFT (15U)
/*! INT15_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT15_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT15_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT15_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT16_MASK_MASK (0x10000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT16_MASK_SHIFT (16U)
/*! INT16_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT16_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT16_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT16_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT17_MASK_MASK (0x20000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT17_MASK_SHIFT (17U)
/*! INT17_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT17_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT17_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT17_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT18_MASK_MASK (0x40000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT18_MASK_SHIFT (18U)
/*! INT18_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT18_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT18_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT18_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT19_MASK_MASK (0x80000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT19_MASK_SHIFT (19U)
/*! INT19_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT19_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT19_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT19_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT20_MASK_MASK (0x100000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT20_MASK_SHIFT (20U)
/*! INT20_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT20_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT20_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT20_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT21_MASK_MASK (0x200000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT21_MASK_SHIFT (21U)
/*! INT21_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT21_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT21_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT21_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT22_MASK_MASK (0x400000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT22_MASK_SHIFT (22U)
/*! INT22_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT22_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT22_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT22_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT23_MASK_MASK (0x800000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT23_MASK_SHIFT (23U)
/*! INT23_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT23_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT23_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT23_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT24_MASK_MASK (0x1000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT24_MASK_SHIFT (24U)
/*! INT24_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT24_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT24_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT24_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT25_MASK_MASK (0x2000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT25_MASK_SHIFT (25U)
/*! INT25_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT25_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT25_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT25_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT26_MASK_MASK (0x4000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT26_MASK_SHIFT (26U)
/*! INT26_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT26_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT26_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT26_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT27_MASK_MASK (0x8000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT27_MASK_SHIFT (27U)
/*! INT27_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT27_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT27_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT27_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT28_MASK_MASK (0x10000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT28_MASK_SHIFT (28U)
/*! INT28_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT28_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT28_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT28_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT29_MASK_MASK (0x20000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT29_MASK_SHIFT (29U)
/*! INT29_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT29_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT29_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT29_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT30_MASK_MASK (0x40000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT30_MASK_SHIFT (30U)
/*! INT30_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT30_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT30_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT30_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK0_INT31_MASK_MASK (0x80000000U)
#define AHBSC_SEC_CPU1_INT_MASK0_INT31_MASK_SHIFT (31U)
/*! INT31_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK0_INT31_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK0_INT31_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK0_INT31_MASK_MASK)
/*! @} */

/*! @name SEC_CPU1_INT_MASK1 - Secure Interrupt Mask 1 for CPU1 */
/*! @{ */

#define AHBSC_SEC_CPU1_INT_MASK1_INT32_MASK_MASK (0x1U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT32_MASK_SHIFT (0U)
/*! INT32_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT32_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT32_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT32_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT33_MASK_MASK (0x2U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT33_MASK_SHIFT (1U)
/*! INT33_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT33_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT33_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT33_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT34_MASK_MASK (0x4U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT34_MASK_SHIFT (2U)
/*! INT34_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT34_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT34_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT34_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT35_MASK_MASK (0x8U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT35_MASK_SHIFT (3U)
/*! INT35_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT35_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT35_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT35_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT36_MASK_MASK (0x10U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT36_MASK_SHIFT (4U)
/*! INT36_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT36_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT36_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT36_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT37_MASK_MASK (0x20U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT37_MASK_SHIFT (5U)
/*! INT37_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT37_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT37_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT37_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT38_MASK_MASK (0x40U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT38_MASK_SHIFT (6U)
/*! INT38_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT38_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT38_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT38_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT39_MASK_MASK (0x80U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT39_MASK_SHIFT (7U)
/*! INT39_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT39_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT39_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT39_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT40_MASK_MASK (0x100U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT40_MASK_SHIFT (8U)
/*! INT40_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT40_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT40_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT40_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT41_MASK_MASK (0x200U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT41_MASK_SHIFT (9U)
/*! INT41_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT41_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT41_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT41_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT42_MASK_MASK (0x400U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT42_MASK_SHIFT (10U)
/*! INT42_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT42_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT42_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT42_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT43_MASK_MASK (0x800U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT43_MASK_SHIFT (11U)
/*! INT43_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT43_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT43_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT43_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT44_MASK_MASK (0x1000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT44_MASK_SHIFT (12U)
/*! INT44_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT44_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT44_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT44_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT45_MASK_MASK (0x2000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT45_MASK_SHIFT (13U)
/*! INT45_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT45_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT45_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT45_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT46_MASK_MASK (0x4000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT46_MASK_SHIFT (14U)
/*! INT46_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT46_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT46_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT46_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT47_MASK_MASK (0x8000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT47_MASK_SHIFT (15U)
/*! INT47_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT47_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT47_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT47_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT48_MASK_MASK (0x10000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT48_MASK_SHIFT (16U)
/*! INT48_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT48_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT48_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT48_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT49_MASK_MASK (0x20000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT49_MASK_SHIFT (17U)
/*! INT49_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT49_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT49_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT49_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT50_MASK_MASK (0x40000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT50_MASK_SHIFT (18U)
/*! INT50_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT50_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT50_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT50_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT51_MASK_MASK (0x80000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT51_MASK_SHIFT (19U)
/*! INT51_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT51_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT51_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT51_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT52_MASK_MASK (0x100000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT52_MASK_SHIFT (20U)
/*! INT52_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT52_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT52_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT52_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT53_MASK_MASK (0x200000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT53_MASK_SHIFT (21U)
/*! INT53_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT53_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT53_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT53_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT54_MASK_MASK (0x400000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT54_MASK_SHIFT (22U)
/*! INT54_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT54_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT54_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT54_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT55_MASK_MASK (0x800000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT55_MASK_SHIFT (23U)
/*! INT55_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT55_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT55_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT55_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT56_MASK_MASK (0x1000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT56_MASK_SHIFT (24U)
/*! INT56_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT56_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT56_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT56_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT57_MASK_MASK (0x2000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT57_MASK_SHIFT (25U)
/*! INT57_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT57_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT57_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT57_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT58_MASK_MASK (0x4000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT58_MASK_SHIFT (26U)
/*! INT58_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT58_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT58_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT58_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT59_MASK_MASK (0x8000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT59_MASK_SHIFT (27U)
/*! INT59_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT59_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT59_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT59_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT60_MASK_MASK (0x10000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT60_MASK_SHIFT (28U)
/*! INT60_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT60_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT60_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT60_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT61_MASK_MASK (0x20000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT61_MASK_SHIFT (29U)
/*! INT61_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT61_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT61_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT61_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT62_MASK_MASK (0x40000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT62_MASK_SHIFT (30U)
/*! INT62_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT62_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT62_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT62_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK1_INT63_MASK_MASK (0x80000000U)
#define AHBSC_SEC_CPU1_INT_MASK1_INT63_MASK_SHIFT (31U)
/*! INT63_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK1_INT63_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK1_INT63_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK1_INT63_MASK_MASK)
/*! @} */

/*! @name SEC_CPU1_INT_MASK2 - Secure Interrupt Mask 2 for CPU1 */
/*! @{ */

#define AHBSC_SEC_CPU1_INT_MASK2_INT64_MASK_MASK (0x1U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT64_MASK_SHIFT (0U)
/*! INT64_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT64_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT64_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT64_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT65_MASK_MASK (0x2U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT65_MASK_SHIFT (1U)
/*! INT65_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT65_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT65_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT65_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT66_MASK_MASK (0x4U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT66_MASK_SHIFT (2U)
/*! INT66_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT66_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT66_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT66_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT67_MASK_MASK (0x8U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT67_MASK_SHIFT (3U)
/*! INT67_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT67_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT67_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT67_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT68_MASK_MASK (0x10U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT68_MASK_SHIFT (4U)
/*! INT68_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT68_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT68_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT68_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT69_MASK_MASK (0x20U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT69_MASK_SHIFT (5U)
/*! INT69_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT69_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT69_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT69_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT70_MASK_MASK (0x40U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT70_MASK_SHIFT (6U)
/*! INT70_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT70_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT70_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT70_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT71_MASK_MASK (0x80U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT71_MASK_SHIFT (7U)
/*! INT71_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT71_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT71_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT71_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT72_MASK_MASK (0x100U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT72_MASK_SHIFT (8U)
/*! INT72_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT72_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT72_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT72_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT73_MASK_MASK (0x200U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT73_MASK_SHIFT (9U)
/*! INT73_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT73_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT73_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT73_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT74_MASK_MASK (0x400U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT74_MASK_SHIFT (10U)
/*! INT74_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT74_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT74_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT74_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT75_MASK_MASK (0x800U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT75_MASK_SHIFT (11U)
/*! INT75_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT75_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT75_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT75_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT76_MASK_MASK (0x1000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT76_MASK_SHIFT (12U)
/*! INT76_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT76_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT76_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT76_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT77_MASK_MASK (0x2000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT77_MASK_SHIFT (13U)
/*! INT77_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT77_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT77_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT77_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT78_MASK_MASK (0x4000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT78_MASK_SHIFT (14U)
/*! INT78_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT78_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT78_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT78_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT79_MASK_MASK (0x8000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT79_MASK_SHIFT (15U)
/*! INT79_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT79_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT79_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT79_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT80_MASK_MASK (0x10000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT80_MASK_SHIFT (16U)
/*! INT80_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT80_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT80_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT80_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT81_MASK_MASK (0x20000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT81_MASK_SHIFT (17U)
/*! INT81_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT81_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT81_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT81_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT82_MASK_MASK (0x40000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT82_MASK_SHIFT (18U)
/*! INT82_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT82_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT82_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT82_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT83_MASK_MASK (0x80000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT83_MASK_SHIFT (19U)
/*! INT83_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT83_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT83_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT83_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT84_MASK_MASK (0x100000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT84_MASK_SHIFT (20U)
/*! INT84_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT84_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT84_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT84_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT85_MASK_MASK (0x200000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT85_MASK_SHIFT (21U)
/*! INT85_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT85_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT85_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT85_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT86_MASK_MASK (0x400000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT86_MASK_SHIFT (22U)
/*! INT86_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT86_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT86_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT86_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT87_MASK_MASK (0x800000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT87_MASK_SHIFT (23U)
/*! INT87_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT87_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT87_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT87_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT88_MASK_MASK (0x1000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT88_MASK_SHIFT (24U)
/*! INT88_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT88_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT88_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT88_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT89_MASK_MASK (0x2000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT89_MASK_SHIFT (25U)
/*! INT89_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT89_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT89_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT89_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT90_MASK_MASK (0x4000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT90_MASK_SHIFT (26U)
/*! INT90_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT90_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT90_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT90_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT91_MASK_MASK (0x8000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT91_MASK_SHIFT (27U)
/*! INT91_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT91_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT91_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT91_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT92_MASK_MASK (0x10000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT92_MASK_SHIFT (28U)
/*! INT92_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT92_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT92_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT92_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT93_MASK_MASK (0x20000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT93_MASK_SHIFT (29U)
/*! INT93_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT93_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT93_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT93_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT94_MASK_MASK (0x40000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT94_MASK_SHIFT (30U)
/*! INT94_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT94_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT94_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT94_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK2_INT95_MASK_MASK (0x80000000U)
#define AHBSC_SEC_CPU1_INT_MASK2_INT95_MASK_SHIFT (31U)
/*! INT95_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK2_INT95_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK2_INT95_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK2_INT95_MASK_MASK)
/*! @} */

/*! @name SEC_CPU1_INT_MASK3 - Secure Interrupt Mask 3 for CPU1 */
/*! @{ */

#define AHBSC_SEC_CPU1_INT_MASK3_INT96_MASK_MASK (0x1U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT96_MASK_SHIFT (0U)
/*! INT96_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT96_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT96_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT96_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT97_MASK_MASK (0x2U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT97_MASK_SHIFT (1U)
/*! INT97_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT97_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT97_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT97_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT98_MASK_MASK (0x4U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT98_MASK_SHIFT (2U)
/*! INT98_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT98_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT98_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT98_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT99_MASK_MASK (0x8U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT99_MASK_SHIFT (3U)
/*! INT99_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT99_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT99_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT99_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT100_MASK_MASK (0x10U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT100_MASK_SHIFT (4U)
/*! INT100_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT100_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT100_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT100_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT101_MASK_MASK (0x20U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT101_MASK_SHIFT (5U)
/*! INT101_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT101_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT101_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT101_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT102_MASK_MASK (0x40U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT102_MASK_SHIFT (6U)
/*! INT102_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT102_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT102_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT102_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT103_MASK_MASK (0x80U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT103_MASK_SHIFT (7U)
/*! INT103_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT103_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT103_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT103_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT104_MASK_MASK (0x100U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT104_MASK_SHIFT (8U)
/*! INT104_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT104_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT104_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT104_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT105_MASK_MASK (0x200U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT105_MASK_SHIFT (9U)
/*! INT105_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT105_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT105_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT105_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT106_MASK_MASK (0x400U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT106_MASK_SHIFT (10U)
/*! INT106_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT106_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT106_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT106_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT107_MASK_MASK (0x800U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT107_MASK_SHIFT (11U)
/*! INT107_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT107_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT107_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT107_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT108_MASK_MASK (0x1000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT108_MASK_SHIFT (12U)
/*! INT108_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT108_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT108_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT108_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT109_MASK_MASK (0x2000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT109_MASK_SHIFT (13U)
/*! INT109_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT109_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT109_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT109_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT110_MASK_MASK (0x4000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT110_MASK_SHIFT (14U)
/*! INT110_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT110_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT110_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT110_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT111_MASK_MASK (0x8000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT111_MASK_SHIFT (15U)
/*! INT111_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT111_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT111_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT111_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT112_MASK_MASK (0x10000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT112_MASK_SHIFT (16U)
/*! INT112_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT112_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT112_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT112_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT113_MASK_MASK (0x20000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT113_MASK_SHIFT (17U)
/*! INT113_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT113_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT113_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT113_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT114_MASK_MASK (0x40000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT114_MASK_SHIFT (18U)
/*! INT114_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT114_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT114_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT114_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT115_MASK_MASK (0x80000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT115_MASK_SHIFT (19U)
/*! INT115_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT115_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT115_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT115_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT116_MASK_MASK (0x100000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT116_MASK_SHIFT (20U)
/*! INT116_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT116_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT116_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT116_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT117_MASK_MASK (0x200000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT117_MASK_SHIFT (21U)
/*! INT117_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT117_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT117_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT117_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT118_MASK_MASK (0x400000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT118_MASK_SHIFT (22U)
/*! INT118_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT118_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT118_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT118_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT119_MASK_MASK (0x800000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT119_MASK_SHIFT (23U)
/*! INT119_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT119_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT119_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT119_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT120_MASK_MASK (0x1000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT120_MASK_SHIFT (24U)
/*! INT120_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT120_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT120_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT120_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT121_MASK_MASK (0x2000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT121_MASK_SHIFT (25U)
/*! INT121_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT121_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT121_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT121_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT122_MASK_MASK (0x4000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT122_MASK_SHIFT (26U)
/*! INT122_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT122_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT122_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT122_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT123_MASK_MASK (0x8000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT123_MASK_SHIFT (27U)
/*! INT123_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT123_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT123_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT123_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT124_MASK_MASK (0x10000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT124_MASK_SHIFT (28U)
/*! INT124_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT124_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT124_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT124_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT125_MASK_MASK (0x20000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT125_MASK_SHIFT (29U)
/*! INT125_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT125_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT125_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT125_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT126_MASK_MASK (0x40000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT126_MASK_SHIFT (30U)
/*! INT126_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT126_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT126_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT126_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK3_INT127_MASK_MASK (0x80000000U)
#define AHBSC_SEC_CPU1_INT_MASK3_INT127_MASK_SHIFT (31U)
/*! INT127_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK3_INT127_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK3_INT127_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK3_INT127_MASK_MASK)
/*! @} */

/*! @name SEC_CPU1_INT_MASK4 - Secure Interrupt Mask 4 for CPU1 */
/*! @{ */

#define AHBSC_SEC_CPU1_INT_MASK4_INT128_MASK_MASK (0x1U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT128_MASK_SHIFT (0U)
/*! INT128_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT128_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT128_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT128_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT129_MASK_MASK (0x2U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT129_MASK_SHIFT (1U)
/*! INT129_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT129_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT129_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT129_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT130_MASK_MASK (0x4U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT130_MASK_SHIFT (2U)
/*! INT130_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT130_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT130_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT130_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT131_MASK_MASK (0x8U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT131_MASK_SHIFT (3U)
/*! INT131_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT131_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT131_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT131_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT132_MASK_MASK (0x10U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT132_MASK_SHIFT (4U)
/*! INT132_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT132_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT132_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT132_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT133_MASK_MASK (0x20U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT133_MASK_SHIFT (5U)
/*! INT133_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT133_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT133_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT133_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT134_MASK_MASK (0x40U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT134_MASK_SHIFT (6U)
/*! INT134_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT134_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT134_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT134_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT135_MASK_MASK (0x80U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT135_MASK_SHIFT (7U)
/*! INT135_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT135_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT135_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT135_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT136_MASK_MASK (0x100U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT136_MASK_SHIFT (8U)
/*! INT136_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT136_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT136_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT136_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT137_MASK_MASK (0x200U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT137_MASK_SHIFT (9U)
/*! INT137_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT137_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT137_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT137_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT138_MASK_MASK (0x400U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT138_MASK_SHIFT (10U)
/*! INT138_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT138_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT138_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT138_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT139_MASK_MASK (0x800U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT139_MASK_SHIFT (11U)
/*! INT139_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT139_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT139_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT139_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT140_MASK_MASK (0x1000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT140_MASK_SHIFT (12U)
/*! INT140_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT140_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT140_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT140_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT141_MASK_MASK (0x2000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT141_MASK_SHIFT (13U)
/*! INT141_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT141_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT141_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT141_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT142_MASK_MASK (0x4000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT142_MASK_SHIFT (14U)
/*! INT142_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT142_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT142_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT142_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT143_MASK_MASK (0x8000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT143_MASK_SHIFT (15U)
/*! INT143_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT143_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT143_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT143_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT144_MASK_MASK (0x10000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT144_MASK_SHIFT (16U)
/*! INT144_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT144_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT144_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT144_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT145_MASK_MASK (0x20000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT145_MASK_SHIFT (17U)
/*! INT145_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT145_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT145_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT145_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT146_MASK_MASK (0x40000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT146_MASK_SHIFT (18U)
/*! INT146_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT146_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT146_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT146_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT147_MASK_MASK (0x80000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT147_MASK_SHIFT (19U)
/*! INT147_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT147_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT147_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT147_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT148_MASK_MASK (0x100000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT148_MASK_SHIFT (20U)
/*! INT148_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT148_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT148_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT148_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT149_MASK_MASK (0x200000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT149_MASK_SHIFT (21U)
/*! INT149_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT149_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT149_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT149_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT150_MASK_MASK (0x400000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT150_MASK_SHIFT (22U)
/*! INT150_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT150_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT150_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT150_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT151_MASK_MASK (0x800000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT151_MASK_SHIFT (23U)
/*! INT151_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT151_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT151_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT151_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT152_MASK_MASK (0x1000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT152_MASK_SHIFT (24U)
/*! INT152_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT152_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT152_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT152_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT153_MASK_MASK (0x2000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT153_MASK_SHIFT (25U)
/*! INT153_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT153_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT153_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT153_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT154_MASK_MASK (0x4000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT154_MASK_SHIFT (26U)
/*! INT154_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT154_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT154_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT154_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT155_MASK_MASK (0x8000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT155_MASK_SHIFT (27U)
/*! INT155_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT155_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT155_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT155_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT156_MASK_MASK (0x10000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT156_MASK_SHIFT (28U)
/*! INT156_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT156_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT156_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT156_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT157_MASK_MASK (0x20000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT157_MASK_SHIFT (29U)
/*! INT157_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT157_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT157_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT157_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT158_MASK_MASK (0x40000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT158_MASK_SHIFT (30U)
/*! INT158_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT158_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT158_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT158_MASK_MASK)

#define AHBSC_SEC_CPU1_INT_MASK4_INT159_MASK_MASK (0x80000000U)
#define AHBSC_SEC_CPU1_INT_MASK4_INT159_MASK_SHIFT (31U)
/*! INT159_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHBSC_SEC_CPU1_INT_MASK4_INT159_MASK(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_CPU1_INT_MASK4_INT159_MASK_SHIFT)) & AHBSC_SEC_CPU1_INT_MASK4_INT159_MASK_MASK)
/*! @} */

/*! @name SEC_GP_REG_LOCK - Secure Mask Lock */
/*! @{ */

#define AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_MASK (0x3U)
#define AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT (0U)
/*! SEC_GPIO_MASK0_LOCK - Secure GPIO _MASK0 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK0 cannot be written
 *  0b10..SEC_GPIO_MASK0 can be written
 *  0b11..Reserved
 */
#define AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT)) & AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_MASK)

#define AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_MASK (0xCU)
#define AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT (2U)
/*! SEC_GPIO_MASK1_LOCK - Secure GPIO _MASK1 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK1 cannot be written
 *  0b10..SEC_GPIO_MASK1 can be written
 *  0b11..Reserved
 */
#define AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT)) & AHBSC_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_MASK)

#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK0_LOCK_MASK (0x3000U)
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK0_LOCK_SHIFT (12U)
/*! SEC_CPU1_INT_MASK0_LOCK - SEC_CPU1_INT_MASK0 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK0 cannot be written
 *  0b10..SEC_GPIO_MASK0 can be written
 *  0b11..Reserved
 */
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK0_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK0_LOCK_SHIFT)) & AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK0_LOCK_MASK)

#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK1_LOCK_MASK (0xC000U)
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK1_LOCK_SHIFT (14U)
/*! SEC_CPU1_INT_MASK1_LOCK - SEC_CPU1_INT_MASK1 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK1 cannot be written
 *  0b10..SEC_GPIO_MASK1 can be written
 *  0b11..Reserved
 */
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK1_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK1_LOCK_SHIFT)) & AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK1_LOCK_MASK)

#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK2_LOCK_MASK (0x30000U)
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK2_LOCK_SHIFT (16U)
/*! SEC_CPU1_INT_MASK2_LOCK - SEC_CPU1_INT_MASK2 Lock
 *  0b00..Reserved
 *  0b01..SEC_CPU1_INT_MASK2 cannot be written
 *  0b10..SEC_CPU1_INT_MASK2 can be written
 *  0b11..Reserved
 */
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK2_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK2_LOCK_SHIFT)) & AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK2_LOCK_MASK)

#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK3_LOCK_MASK (0xC0000U)
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK3_LOCK_SHIFT (18U)
/*! SEC_CPU1_INT_MASK3_LOCK - SEC_CPU1_INT_MASK3 Lock
 *  0b00..Reserved
 *  0b01..SEC_CPU1_INT_MASK3 cannot be written
 *  0b10..SEC_CPU1_INT_MASK3 can be written
 *  0b11..Reserved
 */
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK3_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK3_LOCK_SHIFT)) & AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK3_LOCK_MASK)

#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK4_LOCK_MASK (0x300000U)
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK4_LOCK_SHIFT (20U)
/*! SEC_CPU1_INT_MASK4_LOCK - SEC_CPU1_INT_MASK4 Lock
 *  0b00..Reserved
 *  0b01..SEC_CPU1_INT_MASK4 cannot be written
 *  0b10..SEC_CPU1_INT_MASK4 can be written
 *  0b11..Reserved
 */
#define AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK4_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK4_LOCK_SHIFT)) & AHBSC_SEC_GP_REG_LOCK_SEC_CPU1_INT_MASK4_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level */
/*! @{ */

#define AHBSC_MASTER_SEC_LEVEL_CPU1_MASK         (0xCU)
#define AHBSC_MASTER_SEC_LEVEL_CPU1_SHIFT        (2U)
/*! CPU1 - CPU1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_CPU1(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_CPU1_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_CPU1_MASK)

#define AHBSC_MASTER_SEC_LEVEL_SMARTDMA_MASK     (0x30U)
#define AHBSC_MASTER_SEC_LEVEL_SMARTDMA_SHIFT    (4U)
/*! SMARTDMA - SMARTDMA Data
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_SMARTDMA(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_SMARTDMA_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_SMARTDMA_MASK)

#define AHBSC_MASTER_SEC_LEVEL_EDMA0_MASK        (0xC0U)
#define AHBSC_MASTER_SEC_LEVEL_EDMA0_SHIFT       (6U)
/*! eDMA0 - eDMA0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_EDMA0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_EDMA0_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_EDMA0_MASK)

#define AHBSC_MASTER_SEC_LEVEL_EDMA1_MASK        (0x300U)
#define AHBSC_MASTER_SEC_LEVEL_EDMA1_SHIFT       (8U)
/*! eDMA1 - eDMA1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_EDMA1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_EDMA1_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_EDMA1_MASK)

#define AHBSC_MASTER_SEC_LEVEL_PKC_MASK          (0xC00U)
#define AHBSC_MASTER_SEC_LEVEL_PKC_SHIFT         (10U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_PKC(x)            (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_PKC_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_PKC_MASK)

#define AHBSC_MASTER_SEC_LEVEL_PQ_MASK           (0xC000U)
#define AHBSC_MASTER_SEC_LEVEL_PQ_SHIFT          (14U)
/*! PQ - PowerQuad
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_PQ(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_PQ_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_PQ_MASK)

#define AHBSC_MASTER_SEC_LEVEL_NPUO_MASK         (0x30000U)
#define AHBSC_MASTER_SEC_LEVEL_NPUO_SHIFT        (16U)
/*! NPUO - NPU Operands
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_NPUO(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_NPUO_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_NPUO_MASK)

#define AHBSC_MASTER_SEC_LEVEL_COOLFLUXI_MASK    (0xC0000U)
#define AHBSC_MASTER_SEC_LEVEL_COOLFLUXI_SHIFT   (18U)
/*! COOLFLUXI - Coolflux Instruction
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_COOLFLUXI(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_COOLFLUXI_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_COOLFLUXI_MASK)

#define AHBSC_MASTER_SEC_LEVEL_USB_FS_MASK       (0xC00000U)
#define AHBSC_MASTER_SEC_LEVEL_USB_FS_SHIFT      (22U)
/*! USB_FS - USB_FS
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_USB_FS(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_USB_FS_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_USB_FS_MASK)

#define AHBSC_MASTER_SEC_LEVEL_ETHERNET_MASK     (0x3000000U)
#define AHBSC_MASTER_SEC_LEVEL_ETHERNET_SHIFT    (24U)
/*! ETHERNET - Ethernet
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_ETHERNET(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_ETHERNET_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_ETHERNET_MASK)

#define AHBSC_MASTER_SEC_LEVEL_USB_HS_MASK       (0xC000000U)
#define AHBSC_MASTER_SEC_LEVEL_USB_HS_SHIFT      (26U)
/*! USB_HS - USB HS
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_USB_HS(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_USB_HS_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_USB_HS_MASK)

#define AHBSC_MASTER_SEC_LEVEL_USDHC_MASK        (0x30000000U)
#define AHBSC_MASTER_SEC_LEVEL_USDHC_SHIFT       (28U)
/*! USDHC - uSDHC
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_USDHC(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_USDHC_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_USDHC_MASK)

#define AHBSC_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK (0xC0000000U)
#define AHBSC_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_LOCK - Master SEC Level Lock
 *  0b00..Reserved
 *  0b01..MASTER_SEC_LEVEL_LOCK cannot be written
 *  0b10..MASTER_SEC_LEVEL_LOCK can be written
 *  0b11..Reserved
 */
#define AHBSC_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level */
/*! @{ */

#define AHBSC_MASTER_SEC_ANTI_POL_REG_CPU1_MASK  (0xCU)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_CPU1_SHIFT (2U)
/*! CPU1 - CPU1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_CPU1(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_CPU1_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_CPU1_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_MASK (0x30U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_SHIFT (4U)
/*! SMARTDMA - SMARTDMA Data
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA0_MASK (0xC0U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA0_SHIFT (6U)
/*! eDMA0 - eDMA0
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA0_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA0_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA1_MASK (0x300U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA1_SHIFT (8U)
/*! eDMA1 - eDMA1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA1_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA1_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK   (0xC00U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT  (10U)
/*! PKC - PKC
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_PQ_MASK    (0xC000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PQ_SHIFT   (14U)
/*! PQ - PowerQuad
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PQ(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_PQ_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_PQ_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_NPUO_MASK  (0x30000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_NPUO_SHIFT (16U)
/*! NPUO - NPU Operands
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_NPUO(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_NPUO_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_NPUO_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_COOLFLUXI_MASK (0xC0000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_COOLFLUXI_SHIFT (18U)
/*! COOLFLUXI - Coolflux Instruction
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_COOLFLUXI(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_COOLFLUXI_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_COOLFLUXI_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB_FS_MASK (0xC00000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB_FS_SHIFT (22U)
/*! USB_FS - USB_FS
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB_FS(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_USB_FS_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_USB_FS_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_ETHERNET_MASK (0x3000000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_ETHERNET_SHIFT (24U)
/*! ETHERNET - Ethernet
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_ETHERNET(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_ETHERNET_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_ETHERNET_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB_HS_MASK (0xC000000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB_HS_SHIFT (26U)
/*! USB_HS - USB HS
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB_HS(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_USB_HS_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_USB_HS_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_USDHC_MASK (0x30000000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USDHC_SHIFT (28U)
/*! USDHC - uSDHC
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USDHC(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_USDHC_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_USDHC_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_MASK (0xC0000000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_ANTIPOL_LOCK - Master SEC Level Antipol Lock
 *  0b00..Reserved
 *  0b01..MASTER_SEC_LEVEL_LOCK cannot be written
 *  0b10..MASTER_SEC_LEVEL_LOCK can be written
 *  0b11..Reserved
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_MASK)
/*! @} */

/*! @name CPU0_LOCK_REG - Miscellaneous CPU0 Control Signals */
/*! @{ */

#define AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_MASK    (0x3U)
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_SHIFT   (0U)
/*! LOCK_NS_VTOR - LOCK_NS_VTOR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCKNSVTOR is 1
 *  0b10..CM33 (CPU0) LOCKNSVTOR is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_MASK     (0xCU)
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_SHIFT    (2U)
/*! LOCK_NS_MPU - LOCK_NS_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_NS_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_NS_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_MASK  (0x30U)
#define AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_SHIFT (4U)
/*! LOCK_S_VTAIRCR - LOCK_S_VTAIRCR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_VTAIRCR is 1
 *  0b10..CM33 (CPU0) LOCK_S_VTAIRCR is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_MASK      (0xC0U)
#define AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_SHIFT     (6U)
/*! LOCK_S_MPU - LOCK_S_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_S_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_S_MPU(x)        (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_SAU_MASK        (0x300U)
#define AHBSC_CPU0_LOCK_REG_LOCK_SAU_SHIFT       (8U)
/*! LOCK_SAU - LOCK_SAU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_SAU is 1
 *  0b10..CM33 (CPU0) LOCK_SAU is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_SAU(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_SAU_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_SAU_MASK)

#define AHBSC_CPU0_LOCK_REG_CM33_LOCK_REG_LOCK_MASK (0xC0000000U)
#define AHBSC_CPU0_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT (30U)
/*! CM33_LOCK_REG_LOCK - CM33_LOCK_REG_LOCK
 *  0b00..Reserved
 *  0b01..CM33_LOCK_REG_LOCK is 1
 *  0b10..CM33_LOCK_REG_LOCK is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_CM33_LOCK_REG_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT)) & AHBSC_CPU0_LOCK_REG_CM33_LOCK_REG_LOCK_MASK)
/*! @} */

/*! @name CPU1_LOCK_REG - Miscellaneous CPU1 Control Signals */
/*! @{ */

#define AHBSC_CPU1_LOCK_REG_LOCK_NS_VTOR_MASK    (0x3U)
#define AHBSC_CPU1_LOCK_REG_LOCK_NS_VTOR_SHIFT   (0U)
/*! LOCK_NS_VTOR - LOCK_NS_VTOR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCKNSVTOR is 1
 *  0b10..CM33 (CPU0) LOCKNSVTOR is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU1_LOCK_REG_LOCK_NS_VTOR(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU1_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & AHBSC_CPU1_LOCK_REG_LOCK_NS_VTOR_MASK)

#define AHBSC_CPU1_LOCK_REG_LOCK_NS_MPU_MASK     (0xCU)
#define AHBSC_CPU1_LOCK_REG_LOCK_NS_MPU_SHIFT    (2U)
/*! LOCK_NS_MPU - LOCK_NS_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_NS_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_NS_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU1_LOCK_REG_LOCK_NS_MPU(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU1_LOCK_REG_LOCK_NS_MPU_SHIFT)) & AHBSC_CPU1_LOCK_REG_LOCK_NS_MPU_MASK)
/*! @} */

/*! @name MISC_CTRL_DP_REG - Secure Control Duplicate */
/*! @{ */

#define AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_MASK   (0x3U)
#define AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT  (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enables secure checking. Violation can be detected when the security level of a transaction does not
 *        meet the security rule of the slave or memory to be accessed.
 *  0b10..Disables secure checking. Even if the security level of a transaction does not conform to the security
 *        rule of the slave or memory, it will not be detected as a violation.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables the privilege checking of secure mode access.
 *  0b10..Disables the privilege checking of secure mode access.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables the privilege checking of non-secure mode access.
 *  0b10..Disables the privilege checking of non-secure mode access.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..Reserved
 *  0b01..Master can access memories and peripherals at the same level or below that level.
 *  0b10..Master can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK  (0xC000U)
#define AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - Secure Control */
/*! @{ */

#define AHBSC_MISC_CTRL_REG_WRITE_LOCK_MASK      (0x3U)
#define AHBSC_MISC_CTRL_REG_WRITE_LOCK_SHIFT     (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_WRITE_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & AHBSC_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enables secure checking. Violation can be detected when the security level of a transaction does not
 *        meet the security rule of the slave or memory to be accessed.
 *  0b10..Disables secure checking. Even if the security level of a transaction does not conform to the security
 *        rule of the slave or memory, it will not be detected as a violation.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables privilege checking of secure mode access.
 *  0b10..Disables privilege checking of secure mode access.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables privilege checking of non-secure mode access.
 *  0b10..Disables privilege checking of non-secure mode access is disabled.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..Reserved
 *  0b01..Master strict mode is on and can access memories and peripherals at the same level or below that level
 *  0b10..Master strict mode is disabled and can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_MASK     (0xC000U)
#define AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT    (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_IDAU_ALL_NS(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT)) & AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHBSC_Register_Masks */


/*!
 * @}
 */ /* end of group AHBSC_Peripheral_Access_Layer */


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


#endif  /* PERI_AHBSC_H_ */

