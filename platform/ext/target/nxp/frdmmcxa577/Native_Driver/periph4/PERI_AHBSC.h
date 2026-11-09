/*
** ###################################################################
**     Processors:          MCXA286VAPR
**                          MCXA286VASR
**                          MCXA286VLL
**                          MCXA286VLQ
**                          MCXA286VPN
**                          MCXA287VAPR
**                          MCXA287VASR
**                          MCXA287VLL
**                          MCXA287VLQ
**                          MCXA287VPN
**                          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
**                          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA566VLL
**                          MCXA566VLQ
**                          MCXA566VPN
**                          MCXA567VLL
**                          MCXA567VLQ
**                          MCXA567VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AHBSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AHBSC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHBSC
 *
 * CMSIS Peripheral Access Layer for AHBSC
 */

#if !defined(PERI_AHBSC_H_)
#define PERI_AHBSC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
#elif (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA566VLL) || defined(CPU_MCXA566VLQ) || defined(CPU_MCXA566VPN))
#include "MCXA566_COMMON.h"
#elif (defined(CPU_MCXA567VLL) || defined(CPU_MCXA567VLQ) || defined(CPU_MCXA567VPN))
#include "MCXA567_COMMON.h"
#elif (defined(CPU_MCXA577VAPR) || defined(CPU_MCXA577VLL) || defined(CPU_MCXA577VLQ) || defined(CPU_MCXA577VPN))
#include "MCXA577_COMMON.h"
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
#define AHBSC_RAMX_MEM_RULE0_COUNT                4u
#define AHBSC_RAMA_MEM_RULE_COUNT                 8u
#define AHBSC_RAMB_MEM_RULE_COUNT                 8u
#define AHBSC_FLEXSPI0_REGION0_MEM_RULE_COUNT     4u
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_COUNT   6u
#define AHBSC_SEC_VIO_ADDRN_COUNT                 8u
#define AHBSC_SEC_VIO_MISC_INFON_COUNT            8u
#define AHBSC_SEC_GP_REG_COUNT                    10u

/** AHBSC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t FLASH00_MEM_RULE[AHBSC_FLASH00_MEM_RULE_COUNT]; /**< Flash Memory Rule, array offset: 0x10, array step: 0x4 */
  __IO uint32_t FLASH01_MEM_RULE[AHBSC_FLASH01_MEM_RULE_COUNT]; /**< Flash Memory Rule, array offset: 0x20, array step: 0x4 */
  __IO uint32_t FLASH02_MEM_RULE;                  /**< Flash IFR0 Rule register, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FLASH03_MEM_RULE;                  /**< Flash Memory Rule, offset: 0x40 */
       uint8_t RESERVED_2[28];
  __IO uint32_t ROM_MEM_RULE[AHBSC_ROM_MEM_RULE_COUNT]; /**< ROM Memory Rule, array offset: 0x60, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t RAMX_MEM_RULE[AHBSC_RAMX_MEM_RULE0_COUNT]; /**< RAMX Memory Rule, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_4[16];
  __IO uint32_t RAMA_MEM_RULE[AHBSC_RAMA_MEM_RULE_COUNT]; /**< RAMA Memory Rule 0, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __IO uint32_t RAMB_MEM_RULE[AHBSC_RAMB_MEM_RULE_COUNT]; /**< RAMB Memory Rule 0, array offset: 0xD0, array step: 0x4 */
  __IO uint32_t AHB_SLAVE_PORT_P5_SLAVE_RULE0;     /**< AHB Slave Port 5 Rule Register, offset: 0xF0 */
       uint8_t RESERVED_6[12];
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE0;   /**< APB Bridge Group 0 Memory Rule Register 0, offset: 0x100 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE1;   /**< APB Bridge Group 0 Memory Rule Register 1, offset: 0x104 */
       uint8_t RESERVED_7[8];
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE0;      /**< AIPS Bridge Group 0 Memory Rule 0, offset: 0x110 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE1;      /**< AIPS Bridge Group 0 Memory Rule 1, offset: 0x114 */
       uint8_t RESERVED_8[8];
  __IO uint32_t AIPS_BRIDGE_GROUP1_MEM_RULE0;      /**< AIPS Bridge Group 1 Memory Rule 0, offset: 0x120 */
  __IO uint32_t AIPS_BRIDGE_GROUP1_MEM_RULE1;      /**< AIPS Bridge Group 1 Memory Rule 1, offset: 0x124 */
       uint8_t RESERVED_9[8];
  __IO uint32_t AHB_SECURE_CTRL_MEM_RULE0;         /**< AHB Secure Control Peripheral Rule, offset: 0x130 */
       uint8_t RESERVED_10[12];
  __IO uint32_t AHB_PERIPHERAL0_MEM_RULE1;         /**< AHB Peripheral 0 Memory Rule 1, offset: 0x140 */
       uint8_t RESERVED_11[12];
  __IO uint32_t AHB_PERIPHERAL0_MEM_RULE2;         /**< AHB Peripheral 0 Memory Rule 2, offset: 0x150 */
       uint8_t RESERVED_12[12];
  __IO uint32_t AHB_PERIPHERAL0_MEM_RULE3;         /**< AHB Peripheral 0 Memory Rule 3, offset: 0x160 */
       uint8_t RESERVED_13[12];
  __IO uint32_t AHB_PERIPHERAL0_MEM_RULE4;         /**< AHB Peripheral 0 Memory Rule 4, offset: 0x170 */
       uint8_t RESERVED_14[12];
  __IO uint32_t AHB_PERIPHERAL0_MEM_RULE5;         /**< AHB Peripheral 0 Memory Rule 5, offset: 0x180 */
       uint8_t RESERVED_15[28];
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE0;      /**< AIPS Bridge Group 2 Rule 0, offset: 0x1A0 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE1;      /**< AIPS Bridge Group 2 Rule 1, offset: 0x1A4 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE2;      /**< AIPS Bridge Group 2 Rule 2, offset: 0x1A8 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE3;      /**< AIPS Bridge Group 2 Rule 3, offset: 0x1AC */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE4;      /**< AIPS Bridge Group 2 Rule 4, offset: 0x1B0 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE5;      /**< AIPS Bridge Group 2 Rule 5, offset: 0x1B4 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE6;      /**< AIPS Bridge Group 2 Rule 6, offset: 0x1B8 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE7;      /**< AIPS Bridge Group 2 Rule 7, offset: 0x1BC */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE8;      /**< AIPS Bridge Group 2 Rule 8, offset: 0x1C0 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE9;      /**< AIPS Bridge Group 2 Rule 9, offset: 0x1C4 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE10;     /**< AIPS Bridge Group 2 Rule 10, offset: 0x1C8 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE11;     /**< AIPS Bridge Group 2 Rule 11, offset: 0x1CC */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE12;     /**< AIPS Bridge Group 2 Rule 12, offset: 0x1D0 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE13;     /**< AIPS Bridge Group 2 Rule 13, offset: 0x1D4 */
       uint8_t RESERVED_16[24];
  __IO uint32_t FLEXSPI0_REGION0_MEM_RULE[AHBSC_FLEXSPI0_REGION0_MEM_RULE_COUNT]; /**< FLEXSPI0 Region 0 Memory Rule, array offset: 0x1F0, array step: 0x4 */
  struct {                                         /* offset: 0x200, array step: 0x10 */
    __IO uint32_t FLEXSPI0_REGION_MEM_RULE;          /**< FLEXSPI0 Region 1 Memory Rule..FLEXSPI0 Region 6 Memory Rule, array offset: 0x200, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } FLEXSPI0_REGION1_6_MEM_RULE[AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_COUNT];
       uint8_t RESERVED_17[2976];
  __I  uint32_t SEC_VIO_ADDR[AHBSC_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address, array offset: 0xE00, array step: 0x4 */
       uint8_t RESERVED_18[96];
  __I  uint32_t SEC_VIO_MISC_INFO[AHBSC_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address, array offset: 0xE80, array step: 0x4 */
       uint8_t RESERVED_19[96];
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address, offset: 0xF00 */
       uint8_t RESERVED_20[124];
  __IO uint32_t SEC_GP_REG[AHBSC_SEC_GP_REG_COUNT]; /**< Secure general purpose registers, array offset: 0xF80, array step: 0x4 */
       uint8_t RESERVED_21[40];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level, offset: 0xFD4 */
       uint8_t RESERVED_22[20];
  __IO uint32_t CPU0_LOCK_REG;                     /**< Miscellaneous CPU0 Control Signals, offset: 0xFEC */
       uint8_t RESERVED_23[8];
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

/*! @name FLASH02_MEM_RULE - Flash IFR0 Rule register */
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
#define AHBSC_RAMX_MEM_RULE0_RAMX_MEM_RULE_COUNT (4U)

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

/*! @name RAMB_MEM_RULE - RAMB Memory Rule 0 */
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

/*! @name AHB_SLAVE_PORT_P5_SLAVE_RULE0 - AHB Slave Port 5 Rule Register */
/*! @{ */

#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_MASK (0x3000U)
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_SHIFT (12U)
/*! CDOG0 - CDOG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_SHIFT)) & AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_MASK)

#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG1_MASK (0x30000U)
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG1_SHIFT (16U)
/*! CDOG1 - CDOG1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG1_SHIFT)) & AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_CDOG1_MASK)

#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_MASK (0x300000U)
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT (20U)
/*! DEBUG_MAILBOX - DEBUG_MAILBOX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT)) & AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_MASK)

#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_MAU0_MASK (0x3000000U)
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_MAU0_SHIFT (24U)
/*! MAU0 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_MAU0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_MAU0_SHIFT)) & AHBSC_AHB_SLAVE_PORT_P5_SLAVE_RULE0_MAU0_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE0 - APB Bridge Group 0 Memory Rule Register 0 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_MASK (0x30U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_SHIFT (4U)
/*! INPUTMUX - INPUTMUX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C0_MASK (0x300U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C0_SHIFT (8U)
/*! I3C0 - I3C0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C1_MASK (0x3000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C1_SHIFT (12U)
/*! I3C1 - I3C1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C1_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_SHIFT (16U)
/*! CTIMER0 - CTIMER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_MASK (0x300000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_SHIFT (20U)
/*! CTIMER1 - CTIMER1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_SHIFT (24U)
/*! CTIMER2 - CTIMER2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER3_MASK (0x30000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER3_SHIFT (28U)
/*! CTIMER3 - CTIMER3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER3_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER3_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE1 - APB Bridge Group 0 Memory Rule Register 1 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER4_MASK (0x3U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER4_SHIFT (0U)
/*! CTIMER4 - CTIMER4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER4_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER4_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME_MASK (0x30U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME_SHIFT (4U)
/*! FREQME - FREQME
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK_MASK (0x3000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK_SHIFT (12U)
/*! UTICK - UTCIK0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_SHIFT (16U)
/*! WWDT0 - WWDT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT1_MASK (0x300000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT1_SHIFT (20U)
/*! WWDT1 - WWDT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT1_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_SMARTDMA_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_SMARTDMA_SHIFT (24U)
/*! SMARTDMA - SmartDMA
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_SMARTDMA(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_SMARTDMA_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_SMARTDMA_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE0 - AIPS Bridge Group 0 Memory Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_EWM0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_EWM0_SHIFT (0U)
/*! EWM0 - EWM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_EWM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_EWM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_EWM0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_ROMCP_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_ROMCP_SHIFT (4U)
/*! ROMCP - ROMCP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_ROMCP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_ROMCP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_ROMCP_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PKC0_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PKC0_SHIFT (8U)
/*! PKC0 - PKC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PKC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PKC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PKC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_MP_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_MP_SHIFT (12U)
/*! DMA_1_MP - DMA_1_MP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_MP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_MP_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH0_SHIFT (16U)
/*! DMA_1_CH0 - DMA_1_CH0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH1_SHIFT (20U)
/*! DMA_1_CH1 - DMA_1_CH1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH2_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH2_SHIFT (24U)
/*! DMA_1_CH2 - DMA_1_CH2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH3_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH3_SHIFT (28U)
/*! DMA_1_CH3 - DMA_1_CH3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE1 - AIPS Bridge Group 0 Memory Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_0_SHIFT (16U)
/*! ENET0_0 - ENET0_0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_1_SHIFT (20U)
/*! ENET0_1 - ENET0_1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_eSPI_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_eSPI_SHIFT (28U)
/*! eSPI - eSPI
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_eSPI(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_eSPI_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_eSPI_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP1_MEM_RULE0 - AIPS Bridge Group 1 Memory Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_FLEXSPI0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_FLEXSPI0_SHIFT (0U)
/*! FLEXSPI0 - FLEXSPI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_FLEXSPI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_FLEXSPI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_FLEXSPI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI2_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI2_SHIFT (4U)
/*! LPSPI2 - LPSPI2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI3_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI3_SHIFT (8U)
/*! LPSPI3 - LPSPI3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI4_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI4_SHIFT (12U)
/*! LPSPI4 - LPSPI4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI4_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI5_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI5_SHIFT (16U)
/*! LPSPI5 - LPSPI5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI5_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP1_MEM_RULE1 - AIPS Bridge Group 1 Memory Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_SPI_FILETER0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_SPI_FILETER0_SHIFT (16U)
/*! SPI_FILETER0 - SPI_FILETER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_SPI_FILETER0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_SPI_FILETER0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_SPI_FILETER0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_T1S0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_T1S0_SHIFT (20U)
/*! T1S0 - 10BASE_T1S0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_T1S0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_T1S0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_T1S0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_SHIFT (24U)
/*! USB1 - USB1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_PHY_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_PHY_SHIFT (28U)
/*! USB1_PHY - USB1_PHY
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_PHY(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_PHY_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_PHY_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_MEM_RULE0 - AHB Secure Control Peripheral Rule */
/*! @{ */

#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE0_MASK (0x3U)
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - AHBSC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE0_SHIFT)) & AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE0_MASK)

#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE1_MASK (0x30U)
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - AHBSC ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE1_SHIFT)) & AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE1_MASK)

#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE2_MASK (0x300U)
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - AHBSC ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE2_SHIFT)) & AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE2_MASK)

#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE3_MASK (0x3000U)
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - AHBSC ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE3_SHIFT)) & AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_MEM_RULE1 - AHB Peripheral 0 Memory Rule 1 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_SHIFT (0U)
/*! GPIO0 - GPIO0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_MASK)

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_ALIAS_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_ALIAS_SHIFT (4U)
/*! GPIO0_ALIAS - GPIO0 ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_ALIAS_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_ALIAS_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_MEM_RULE2 - AHB Peripheral 0 Memory Rule 2 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_SHIFT (0U)
/*! GPIO1 - GPIO1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_MASK)

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_ALIAS_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_ALIAS_SHIFT (4U)
/*! GPIO1_ALIAS - GPIO1 ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_ALIAS_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_ALIAS_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_MEM_RULE3 - AHB Peripheral 0 Memory Rule 3 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_SHIFT (0U)
/*! GPIO2 - GPIO2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_MASK)

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_ALIAS_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_ALIAS_SHIFT (4U)
/*! GPIO2_ALIAS - GPIO2 ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_ALIAS_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_ALIAS_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_MEM_RULE4 - AHB Peripheral 0 Memory Rule 4 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_SHIFT (0U)
/*! GPIO3 - GPIO3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_MASK)

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_ALIAS_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_ALIAS_SHIFT (4U)
/*! GPIO3_ALIAS - GPIO3 ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_ALIAS_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_ALIAS_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_MEM_RULE5 - AHB Peripheral 0 Memory Rule 5 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_SHIFT (0U)
/*! GPIO4 - GPIO4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_MASK)

#define AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_ALIAS_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_ALIAS_SHIFT (4U)
/*! GPIO4_ALIAS - GPIO4 ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_ALIAS_SHIFT)) & AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_ALIAS_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE0 - AIPS Bridge Group 2 Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_MP_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_MP_SHIFT (0U)
/*! DMA_0_MP - DMA_0_MP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_MP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_MP_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH0_SHIFT (4U)
/*! DMA_0_CH0 - DMA_0_CH0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH1_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH1_SHIFT (8U)
/*! DMA_0_CH1 - DMA_0_CH1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH2_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH2_SHIFT (12U)
/*! DMA_0_CH2 - DMA_0_CH2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH3_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH3_SHIFT (16U)
/*! DMA_0_CH3 - DMA_0_CH3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH4_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH4_SHIFT (20U)
/*! DMA_0_CH4 - DMA_0_CH4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH4_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH5_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH5_SHIFT (24U)
/*! DMA_0_CH5 - DMA_0_CH5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH5_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH6_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH6_SHIFT (28U)
/*! DMA_0_CH6 - DMA_0_CH6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH6_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH6_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE1 - AIPS Bridge Group 2 Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH7_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH7_SHIFT (0U)
/*! DMA_0_CH7 - DMA_0_CH7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH7_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH7_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH8_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH8_SHIFT (4U)
/*! DMA_0_CH8 - DMA_0_CH8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH8_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH8_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH9_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH9_SHIFT (8U)
/*! DMA_0_CH9 - DMA_0_CH9
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH9_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH9_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH10_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH10_SHIFT (12U)
/*! DMA_0_CH10 - DMA_0_CH10
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH10_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH10_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH11_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH11_SHIFT (16U)
/*! DMA_0_CH11 - DMA_0_CH11
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH11_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH11_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE2 - AIPS Bridge Group 2 Rule 2 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_SYSCON_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_SYSCON_SHIFT (4U)
/*! SYSCON - SYSCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_SYSCON(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_SYSCON_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_SYSCON_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_WUU_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_WUU_SHIFT (8U)
/*! WUU - WUU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_WUU(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_WUU_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_WUU_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_VBAT_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_VBAT_SHIFT (12U)
/*! VBAT - VBAT
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_VBAT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_VBAT_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_VBAT_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMC_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMC_SHIFT (16U)
/*! FMC - FMC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMU_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMU_SHIFT (20U)
/*! FMU - FMU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMU(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMU_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMU_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE3 - AIPS Bridge Group 2 Rule 3 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_FLEXIO_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_FLEXIO_SHIFT (4U)
/*! FLEXIO - FLEXIO
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_FLEXIO(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_FLEXIO_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_FLEXIO_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C0_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C0_SHIFT (8U)
/*! LPI2C0 - LPI2C0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C1_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C1_SHIFT (12U)
/*! LPI2C1 - LPI2C1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI0_SHIFT (16U)
/*! LPSPI0 - LPSPI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI1_SHIFT (20U)
/*! LPSPI1 - LPSPI1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_I3C2_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_I3C2_SHIFT (24U)
/*! I3C2 - I3C2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_I3C2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_I3C2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_I3C2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPUART0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPUART0_SHIFT (28U)
/*! LPUART0 - LPUART0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPUART0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPUART0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPUART0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE4 - AIPS Bridge Group 2 Rule 4 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART1_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART1_SHIFT (0U)
/*! LPUART1 - LPUART1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART2_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART2_SHIFT (4U)
/*! LPUART2 - LPUART2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART3_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART3_SHIFT (8U)
/*! LPUART3 - LPUART3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART4_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART4_SHIFT (12U)
/*! LPUART4 - LPUART4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART4_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE5 - AIPS Bridge Group 2 Rule 5 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_LPTMR_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_LPTMR_SHIFT (12U)
/*! LPTMR - LPTMR
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_LPTMR(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_LPTMR_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_LPTMR_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_OSTIMER_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_OSTIMER_SHIFT (20U)
/*! OSTIMER - OSTIMER
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_OSTIMER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_OSTIMER_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_OSTIMER_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_WAKE_TIMER_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_WAKE_TIMER_SHIFT (24U)
/*! WAKE_TIMER - WAKE_TIMER
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_WAKE_TIMER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_WAKE_TIMER_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_WAKE_TIMER_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_ADC0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_ADC0_SHIFT (28U)
/*! ADC0 - ADC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_ADC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_ADC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_ADC0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE6 - AIPS Bridge Group 2 Rule 6 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_ADC1_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_ADC1_SHIFT (0U)
/*! ADC1 - ADC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_ADC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_ADC1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_ADC1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_CMP0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_CMP0_SHIFT (4U)
/*! CMP0 - CMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_CMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_CMP0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_CMP0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC0_SHIFT (16U)
/*! DAC0 - DAC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC1_SHIFT (20U)
/*! DAC1 - DAC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC1_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE7 - AIPS Bridge Group 2 Rule 7 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_VREF0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_VREF0_SHIFT (12U)
/*! VREF0 - VREF0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_VREF0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_VREF0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_VREF0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT0_SHIFT (16U)
/*! PORT0 - PORT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT1_SHIFT (20U)
/*! PORT1 - PORT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT2_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT2_SHIFT (24U)
/*! PORT2 - PORT2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT3_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT3_SHIFT (28U)
/*! PORT3 - PORT3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE8 - AIPS Bridge Group 2 Rule 8 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_PORT4_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_PORT4_SHIFT (0U)
/*! PORT4 - PORT4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_PORT4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_PORT4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_PORT4_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_TSI0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_TSI0_SHIFT (12U)
/*! TSI0 - TSI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_TSI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_TSI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_TSI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_AOI0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_AOI0_SHIFT (16U)
/*! AOI0 - AOI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_AOI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_AOI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_AOI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CRC0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CRC0_SHIFT (20U)
/*! CRC0 - CRC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CRC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CRC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CRC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CMC_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CMC_SHIFT (24U)
/*! CMC - CMC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CMC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CMC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CMC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_EIM_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_EIM_SHIFT (28U)
/*! EIM - EIM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_EIM(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_EIM_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_EIM_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE9 - AIPS Bridge Group 2 Rule 9 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_ERM_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_ERM_SHIFT (0U)
/*! ERM - ERM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_ERM(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_ERM_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_ERM_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_MBC_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_MBC_SHIFT (4U)
/*! MBC - MBC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_MBC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_MBC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_MBC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SCG_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SCG_SHIFT (8U)
/*! SCG - SCG
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SCG(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SCG_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SCG_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SPC_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SPC_SHIFT (12U)
/*! SPC - SPC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SPC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SPC_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SPC_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION0_SHIFT (16U)
/*! CAN0_REGION0 - CAN0 Region 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION1_SHIFT (20U)
/*! CAN0_REGION1 - CAN0 Region 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION2_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION2_SHIFT (24U)
/*! CAN0_REGION2 - CAN0 Region 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION3_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION3_SHIFT (28U)
/*! CAN0_REGION3 - CAN0 Region 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE10 - AIPS Bridge Group 2 Rule 10 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION0_SHIFT (0U)
/*! CAN1_REGION0 - CAN1 Region 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION1_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION1_SHIFT (4U)
/*! CAN1_REGION1 - CAN1 Region 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION2_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION2_SHIFT (8U)
/*! CAN1_REGION2 - CAN1 Region 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION3_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION3_SHIFT (12U)
/*! CAN1_REGION3 - CAN1 Region 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C2_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C2_SHIFT (16U)
/*! LPI2C2 - LPI2C2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C3_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C3_SHIFT (20U)
/*! LPI2C3 - LPI2C3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C4_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C4_SHIFT (24U)
/*! LPI2C4 - LPI2C4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C4_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C4_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE11 - AIPS Bridge Group 2 Rule 11 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_LPUART5_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_LPUART5_SHIFT (8U)
/*! LPUART5 - LPUART5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_LPUART5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_LPUART5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_LPUART5_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_I3C3_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_I3C3_SHIFT (24U)
/*! I3C3 - I3C3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_I3C3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_I3C3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_I3C3_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_GPIO5_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_GPIO5_SHIFT (28U)
/*! GPIO5 - GPIO5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_GPIO5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_GPIO5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_GPIO5_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE12 - AIPS Bridge Group 2 Rule 12 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_GPIO5_ALIAS_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_GPIO5_ALIAS_SHIFT (0U)
/*! GPIO5_ALIAS - GPIO5_ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_GPIO5_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_GPIO5_ALIAS_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_GPIO5_ALIAS_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_PORT5_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_PORT5_SHIFT (12U)
/*! PORT5 - PORT5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_PORT5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_PORT5_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_PORT5_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_DGDET0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_DGDET0_SHIFT (20U)
/*! DGDET0 - DGDET0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_DGDET0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_DGDET0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_DGDET0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_ITRC0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_ITRC0_SHIFT (28U)
/*! ITRC0 - ITRC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_ITRC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_ITRC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_ITRC0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE13 - AIPS Bridge Group 2 Rule 13 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_GLIKEY0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_GLIKEY0_SHIFT (0U)
/*! GLIKEY0 - GLIKEY0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_GLIKEY0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_GLIKEY0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_GLIKEY0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TDET0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TDET0_SHIFT (4U)
/*! TDET0 - TDET0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TDET0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TDET0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TDET0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SECCON_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SECCON_SHIFT (8U)
/*! SECCON - SECCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SECCON(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SECCON_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SECCON_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SGI0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SGI0_SHIFT (12U)
/*! SGI0 - SGI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SGI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SGI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SGI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TRNG0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TRNG0_SHIFT (16U)
/*! TRNG0 - TRNG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TRNG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TRNG0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TRNG0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_UDF0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_UDF0_SHIFT (20U)
/*! UDF0 - UDF0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_UDF0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_UDF0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_UDF0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_RTC0_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_RTC0_SHIFT (24U)
/*! RTC0 - RTC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_RTC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_RTC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_RTC0_MASK)
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

/*! @name FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE - FLEXSPI0 Region 1 Memory Rule..FLEXSPI0 Region 6 Memory Rule */
/*! @{ */

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2_MASK)

#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3_MASK)
/*! @} */

/* The count of AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE */
#define AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_COUNT (6U)

/*! @name SEC_VIO_ADDRN_SEC_VIO_ADDR - Security Violation Address */
/*! @{ */

#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK (0xFFFFFFFFU)
#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT (0U)
/*! SEC_VIO_ADDR - Security violation address for AHB layer a reset value 0 */
#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT)) & AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK)
/*! @} */

/* The count of AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR */
#define AHBSC_SEC_VIO_ADDRN_SEC_VIO_ADDR_COUNT   (8U)

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
 *  0b00000..CM33 Code
 *  0b00001..CM33 System
 *  0b00010..SMARTDMA Instruction
 *  0b00011..SMARTDMA Data
 *  0b00100..eDMA1
 *  0b00101..eDMA0
 *  0b00110..USB HS
 *  0b01010..eSPI
 *  0b01100..PKC
 *  0b01101..Ethernet
 */
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO */
#define AHBSC_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_COUNT (8U)

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
/*! @} */

/*! @name SEC_GP_REG - Secure general purpose registers */
/*! @{ */

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_MASK     (0x1U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_SHIFT    (0U)
/*! DMA0_IPD_REQ_0 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_MASK     (0x1U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_SHIFT    (0U)
/*! DMA1_IPD_REQ_0 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_MASK     (0x2U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_SHIFT    (1U)
/*! DMA0_IPD_REQ_1 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_MASK     (0x2U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_SHIFT    (1U)
/*! DMA1_IPD_REQ_1 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_MASK     (0x4U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_SHIFT    (2U)
/*! DMA0_IPD_REQ_2 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_MASK     (0x4U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_SHIFT    (2U)
/*! DMA1_IPD_REQ_2 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_MASK     (0x8U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_SHIFT    (3U)
/*! DMA0_IPD_REQ_3 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_MASK     (0x8U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_SHIFT    (3U)
/*! DMA1_IPD_REQ_3 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_MASK     (0x10U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_SHIFT    (4U)
/*! DMA0_IPD_REQ_4 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_MASK     (0x10U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_SHIFT    (4U)
/*! DMA1_IPD_REQ_4 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_MASK     (0x20U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_SHIFT    (5U)
/*! DMA0_IPD_REQ_5 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_MASK     (0x20U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_SHIFT    (5U)
/*! DMA1_IPD_REQ_5 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_MASK     (0x40U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_SHIFT    (6U)
/*! DMA0_IPD_REQ_6 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_MASK     (0x40U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_SHIFT    (6U)
/*! DMA1_IPD_REQ_6 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_MASK     (0x80U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_SHIFT    (7U)
/*! DMA0_IPD_REQ_7 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_MASK     (0x80U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_SHIFT    (7U)
/*! DMA1_IPD_REQ_7 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_MASK     (0x100U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_SHIFT    (8U)
/*! DMA0_IPD_REQ_8 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_MASK     (0x100U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_SHIFT    (8U)
/*! DMA1_IPD_REQ_8 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_MASK     (0x200U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_SHIFT    (9U)
/*! DMA0_IPD_REQ_9 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_MASK     (0x200U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_SHIFT    (9U)
/*! DMA1_IPD_REQ_9 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_MASK    (0x400U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_SHIFT   (10U)
/*! DMA0_IPD_REQ_10 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_MASK    (0x400U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_SHIFT   (10U)
/*! DMA1_IPD_REQ_10 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_MASK    (0x800U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_SHIFT   (11U)
/*! DMA0_IPD_REQ_11 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_MASK    (0x800U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_SHIFT   (11U)
/*! DMA1_IPD_REQ_11 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_MASK    (0x1000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_SHIFT   (12U)
/*! DMA0_IPD_REQ_12 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_MASK    (0x1000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_SHIFT   (12U)
/*! DMA1_IPD_REQ_12 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_MASK    (0x2000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_SHIFT   (13U)
/*! DMA0_IPD_REQ_13 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_MASK    (0x2000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_SHIFT   (13U)
/*! DMA1_IPD_REQ_13 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_MASK    (0x4000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_SHIFT   (14U)
/*! DMA0_IPD_REQ_14 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_MASK    (0x4000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_SHIFT   (14U)
/*! DMA1_IPD_REQ_14 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_MASK    (0x8000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_SHIFT   (15U)
/*! DMA0_IPD_REQ_15 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_MASK    (0x8000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_SHIFT   (15U)
/*! DMA1_IPD_REQ_15 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_MASK    (0x10000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_SHIFT   (16U)
/*! DMA0_IPD_REQ_16 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_MASK    (0x10000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_SHIFT   (16U)
/*! DMA1_IPD_REQ_16 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_MASK    (0x20000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_SHIFT   (17U)
/*! DMA0_IPD_REQ_17 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_MASK    (0x20000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_SHIFT   (17U)
/*! DMA1_IPD_REQ_17 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_MASK    (0x40000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_SHIFT   (18U)
/*! DMA0_IPD_REQ_18 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_MASK    (0x40000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_SHIFT   (18U)
/*! DMA1_IPD_REQ_18 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_MASK    (0x80000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_SHIFT   (19U)
/*! DMA0_IPD_REQ_19 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_MASK    (0x80000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_SHIFT   (19U)
/*! DMA1_IPD_REQ_19 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_MASK    (0x100000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_SHIFT   (20U)
/*! DMA0_IPD_REQ_20 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_MASK    (0x100000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_SHIFT   (20U)
/*! DMA1_IPD_REQ_20 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_MASK    (0x200000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_SHIFT   (21U)
/*! DMA0_IPD_REQ_21 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_MASK    (0x200000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_SHIFT   (21U)
/*! DMA1_IPD_REQ_21 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_MASK    (0x400000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_SHIFT   (22U)
/*! DMA0_IPD_REQ_22 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_MASK    (0x400000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_SHIFT   (22U)
/*! DMA1_IPD_REQ_22 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_MASK    (0x800000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_SHIFT   (23U)
/*! DMA0_IPD_REQ_23 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_MASK    (0x800000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_SHIFT   (23U)
/*! DMA1_IPD_REQ_23 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_MASK    (0x1000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_SHIFT   (24U)
/*! DMA0_IPD_REQ_24 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_MASK    (0x1000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_SHIFT   (24U)
/*! DMA1_IPD_REQ_24 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_MASK    (0x2000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_SHIFT   (25U)
/*! DMA0_IPD_REQ_25 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_MASK    (0x2000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_SHIFT   (25U)
/*! DMA1_IPD_REQ_25 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_MASK    (0x4000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_SHIFT   (26U)
/*! DMA0_IPD_REQ_26 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_MASK    (0x4000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_SHIFT   (26U)
/*! DMA1_IPD_REQ_26 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_MASK    (0x8000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_SHIFT   (27U)
/*! DMA0_IPD_REQ_27 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_MASK    (0x8000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_SHIFT   (27U)
/*! DMA1_IPD_REQ_27 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_MASK    (0x10000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_SHIFT   (28U)
/*! DMA0_IPD_REQ_28 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_MASK    (0x10000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_SHIFT   (28U)
/*! DMA1_IPD_REQ_28 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_MASK    (0x20000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_SHIFT   (29U)
/*! DMA0_IPD_REQ_29 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_MASK    (0x20000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_SHIFT   (29U)
/*! DMA1_IPD_REQ_29 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_MASK    (0x40000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_SHIFT   (30U)
/*! DMA0_IPD_REQ_30 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_MASK    (0x40000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_SHIFT   (30U)
/*! DMA1_IPD_REQ_30 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_MASK    (0x80000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_SHIFT   (31U)
/*! DMA0_IPD_REQ_31 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_MASK    (0x80000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_SHIFT   (31U)
/*! DMA1_IPD_REQ_31 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level */
/*! @{ */

#define AHBSC_MASTER_SEC_LEVEL_SMARTDMA_MASK     (0x30U)
#define AHBSC_MASTER_SEC_LEVEL_SMARTDMA_SHIFT    (4U)
/*! SMARTDMA - SMARTDMA Data
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_SMARTDMA(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_SMARTDMA_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_SMARTDMA_MASK)

#define AHBSC_MASTER_SEC_LEVEL_DMA0_MASK         (0xC0U)
#define AHBSC_MASTER_SEC_LEVEL_DMA0_SHIFT        (6U)
/*! DMA0 - eDMA0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_DMA0(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_DMA0_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_DMA0_MASK)

#define AHBSC_MASTER_SEC_LEVEL_DMA1_MASK         (0x300U)
#define AHBSC_MASTER_SEC_LEVEL_DMA1_SHIFT        (8U)
/*! DMA1 - eDMA1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_DMA1(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_DMA1_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_DMA1_MASK)

#define AHBSC_MASTER_SEC_LEVEL_PKC_MASK          (0xC00U)
#define AHBSC_MASTER_SEC_LEVEL_PKC_SHIFT         (10U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_PKC(x)            (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_PKC_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_PKC_MASK)

#define AHBSC_MASTER_SEC_LEVEL_ENET0_MASK        (0x3000000U)
#define AHBSC_MASTER_SEC_LEVEL_ENET0_SHIFT       (24U)
/*! ENET0 - ENET0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_ENET0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_ENET0_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_ENET0_MASK)

#define AHBSC_MASTER_SEC_LEVEL_USB1_MASK         (0xC000000U)
#define AHBSC_MASTER_SEC_LEVEL_USB1_SHIFT        (26U)
/*! USB1 - USB1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_USB1(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_USB1_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_USB1_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level */
/*! @{ */

#define AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_MASK (0x30U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_SHIFT (4U)
/*! SMARTDMA
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_MASK  (0xC0U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT (6U)
/*! DMA0 - eDMA0
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_MASK  (0x300U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT (8U)
/*! DMA1 - eDMA1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK   (0xC00U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT  (10U)
/*! PKC - PKC
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_ENET0_MASK (0x3000000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_ENET0_SHIFT (24U)
/*! ENET0 - ENET0
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_ENET0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_ENET0_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_ENET0_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB1_MASK  (0xC000000U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB1_SHIFT (26U)
/*! USB1 - USB1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_USB1(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_USB1_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_USB1_MASK)
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
 *  0b01..Master strict mode is disabled/off and can access memories and peripherals at the same level or below that level
 *  0b10..Master strict mode is enabled/on and can access memories and peripherals at same level only
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

