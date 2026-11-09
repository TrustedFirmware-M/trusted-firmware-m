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
**         CMSIS Peripheral Access Layer for SECCON
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
 * @file PERI_SECCON.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for SECCON
 *
 * CMSIS Peripheral Access Layer for SECCON
 */

#if !defined(PERI_SECCON_H_)
#define PERI_SECCON_H_                           /**< Symbol preventing repeated inclusion */

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
   -- SECCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECCON_Peripheral_Access_Layer SECCON Peripheral Access Layer
 * @{
 */

/** SECCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t CPU1_RESET_CTRL;                   /**< CPU1 Reset Controller, offset: 0x0 */
  __IO uint32_t CPU1_VECTOR;                       /**< CPU1 Initial Vector Set, offset: 0x4 */
       uint8_t RESERVED_0[60];
  __IO uint32_t GENERAL_BLOCK_0_0;                 /**< GEN_BLK_0_0, offset: 0x44 */
  __IO uint32_t GENERAL_BLOCK_0_1;                 /**< GEN_BLK_0_1, offset: 0x48 */
  __IO uint32_t GENERAL_BLOCK_0_2;                 /**< GEN_BLK_0_2, offset: 0x4C */
  __IO uint32_t GENERAL_BLOCK_0_3;                 /**< GEN_BLK_0_3, offset: 0x50 */
  __IO uint32_t GENERAL_BLOCK_1_0;                 /**< GEN_BLK_1_0, offset: 0x54 */
  __IO uint32_t GENERAL_BLOCK_1_1;                 /**< GEN_BLK_1_1, offset: 0x58 */
  __IO uint32_t GENERAL_BLOCK_1_2;                 /**< GEN_BLK_1_2, offset: 0x5C */
  __IO uint32_t GENERAL_BLOCK_1_3;                 /**< GEN_BLK_1_3, offset: 0x60 */
  __IO uint32_t UDF_CTRL;                          /**< UDF_CTRL, offset: 0x64 */
  __IO uint32_t DEVICE_UID_0;                      /**< Device UID 0, offset: 0x68 */
  __IO uint32_t DEVICE_UID_1;                      /**< Device UID 1, offset: 0x6C */
  __IO uint32_t DEVICE_UID_2;                      /**< Device UID 2, offset: 0x70 */
  __IO uint32_t DEVICE_UID_3;                      /**< Device UID 3, offset: 0x74 */
  __IO uint32_t GDET0_CTRL;                        /**< GDET0 Control, offset: 0x78 */
       uint8_t RESERVED_1[4];
  __I  uint32_t LC_PROBE_STATE;                    /**< LC_PROBE_STATE, offset: 0x80 */
  __I  uint32_t LC_FT_STATE_A;                     /**< LC_FT_STATE_A, offset: 0x84 */
  __I  uint32_t LC_FT_STATE_B;                     /**< LC_FT_STATE_B, offset: 0x88 */
  __IO uint32_t CFPA_LC_STATE;                     /**< OEM Life cycle state., offset: 0x8C */
  __I  uint32_t OVP_STATE;                         /**< OVP PAD State, offset: 0x90 */
       uint8_t RESERVED_2[12];
  __I  uint32_t LIFECYCLE_STATE;                   /**< Chip LifeCycle State, offset: 0xA0 */
  __I  uint32_t INV_LIFECYCLE_STATE;               /**< Invert version of LIFECYCLE_STATE, offset: 0xA4 */
  __IO uint32_t MDAC0_INJECT_ERR;                  /**< MDAC0 Error Injection, offset: 0xA8 */
  __IO uint32_t MDAC1_INJECT_ERR;                  /**< MDAC1 Error Injection, offset: 0xAC */
  __IO uint32_t MDAC2_INJECT_ERR;                  /**< MDAC2 Error Injection, offset: 0xB0 */
  __IO uint32_t MDAC3_INJECT_ERR;                  /**< MDAC3 Error Injection, offset: 0xB4 */
  __IO uint32_t MDAC4_INJECT_ERR;                  /**< MDAC4 Error Injection, offset: 0xB8 */
  __IO uint32_t MDAC5_INJECT_ERR;                  /**< MDAC5 Error Injection, offset: 0xBC */
  __IO uint32_t MDAC6_INJECT_ERR;                  /**< MDAC6 Error Injection, offset: 0xC0 */
  __IO uint32_t MDAC7_INJECT_ERR;                  /**< MDAC7 Error Injection, offset: 0xC4 */
       uint8_t RESERVED_3[40];
  __IO uint32_t CPU0_DEBUG_EN;                     /**< Debug Feature Registers for CPU0, offset: 0xF0 */
  __IO uint32_t CPU0_DEBUG_EN_DP;                  /**< Debug Feature Registers for CPU0 (duplicate), offset: 0xF4 */
  __IO uint32_t CPU1_DEBUG_EN;                     /**< Debug Feature Registers for CPU1, offset: 0xF8 */
  __IO uint32_t CPU1_DEBUG_EN_DP;                  /**< Debug Feature Registers for CPU1 (duplicate), offset: 0xFC */
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug Authentication BEACON, offset: 0x100 */
  __IO uint32_t DEBUG_FEATURE_LOCK;                /**< Controls write access to Debug Security registers, offset: 0x104 */
       uint8_t RESERVED_4[8];
  __IO uint32_t TEST_ACCESS_EN;                    /**< Security Code to Allow Test (Design for Testability) access., offset: 0x110 */
  __IO uint32_t FLASH_ACCESS_EN;                   /**< Flash Test Access Enable Control, offset: 0x114 */
  __IO uint32_t SWD_ACCESS_CPU0;                   /**< CPU0 Software Debug Access, offset: 0x118 */
  __IO uint32_t SWD_ACCESS_CPU1;                   /**< CPU1 Software Debug Access, offset: 0x11C */
  __I  uint32_t L2_PASSWORD_MATCH;                 /**< L2 Password Has Matched, offset: 0x120 */
  __IO uint32_t L2_PASSWORD_MATCH_HIDE;            /**< Hide L2_PASSWORD_MATCH Reg, offset: 0x124 */
  __IO uint32_t SOC_ERSIEN;                        /**< Flash IFR0 Erase Enable, offset: 0x128 */
  __IO uint32_t BOOT_LOCKOUT_ADDR;                 /**< ROM Hidden XOM address offset, offset: 0x12C */
  __IO uint32_t BOOT_LOCKOUT_ADDR_DP;              /**< ROM Hidden XOM address offset duplicate, offset: 0x130 */
  __IO uint32_t BOOT_LOCKOUT_LOCK;                 /**< Control write access to BOOT_LOCKOUT_ADDR, offset: 0x134 */
       uint8_t RESERVED_5[8];
  __IO uint32_t BOOT_RETRY_CNT;                    /**< Boot Retry Counter, offset: 0x140 */
  __IO uint32_t BOOT_TEMP_STATE;                   /**< Boot Temporal State, offset: 0x144 */
       uint8_t RESERVED_6[8];
  __IO uint32_t BOOT_ATTEST_STATE_0;               /**< Store boot attest state, offset: 0x150 */
  __IO uint32_t BOOT_ATTEST_STATE_1;               /**< Store boot attest state, offset: 0x154 */
  __IO uint32_t BOOT_ATTEST_STATE_2;               /**< Store boot attest state, offset: 0x158 */
  __IO uint32_t BOOT_ATTEST_STATE_3;               /**< Store boot attest state, offset: 0x15C */
  __IO uint32_t BOOT_ATTEST_STATE_4;               /**< Store boot attest state, offset: 0x160 */
  __IO uint32_t BOOT_ATTEST_STATE_5;               /**< Store boot attest state, offset: 0x164 */
  __IO uint32_t BOOT_ATTEST_STATE_6;               /**< Store boot attest state, offset: 0x168 */
  __IO uint32_t BOOT_ATTEST_STATE_7;               /**< Store boot attest state, offset: 0x16C */
  __IO uint32_t BOOT_ATTEST_STATE_8;               /**< Store boot attest state, offset: 0x170 */
  __IO uint32_t BOOT_ATTEST_STATE_9;               /**< Store boot attest state, offset: 0x174 */
  __IO uint32_t BOOT_ATTEST_STATE_10;              /**< Store boot attest state, offset: 0x178 */
  __IO uint32_t BOOT_ATTEST_STATE_11;              /**< Store boot attest state, offset: 0x17C */
  __IO uint32_t BOOT_STATE_0;                      /**< Store boot state, offset: 0x180 */
  __IO uint32_t BOOT_STATE_1;                      /**< Store boot state, offset: 0x184 */
  __IO uint32_t BOOT_STATE_2;                      /**< Store boot state, offset: 0x188 */
  __IO uint32_t BOOT_STATE_LOCK;                   /**< Boot State Register Lock, offset: 0x18C */
  __IO uint32_t ROM_SCRATCH_PAD_0;                 /**< Scratchpad Register 0, offset: 0x190 */
  __IO uint32_t ROM_SCRATCH_PAD_1;                 /**< Scratchpad Register 1, offset: 0x194 */
  __IO uint32_t ROM_API_PARAM;                     /**< ROM API PARAM, offset: 0x198 */
  __IO uint32_t RECOVERY_IMAGE_VECTOR;             /**< RECOVERY IMAGE VECTOR, offset: 0x19C */
  __IO uint32_t LP_WAKEUP_VECTOR;                  /**< LP WAKEUP VECTOR, offset: 0x1A0 */
  __IO uint32_t NXP_PROV_FW_RUN;                   /**< NXP PROV FW RUN, offset: 0x1A4 */
  __IO uint32_t SPI_FLASH_RECOVERY;                /**< SPI FLASH RECOVERY, offset: 0x1A8 */
  __IO uint32_t SPARE;                             /**< SPARE, offset: 0x1AC */
       uint8_t RESERVED_7[140];
  __IO uint32_t CPU0_DEBUG_PRE;                    /**< CPU0 Debug Preparation, offset: 0x23C */
} SECCON_Type;

/* ----------------------------------------------------------------------------
   -- SECCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECCON_Register_Masks SECCON Register Masks
 * @{
 */

/*! @name CPU1_RESET_CTRL - CPU1 Reset Controller */
/*! @{ */

#define SECCON_CPU1_RESET_CTRL_CPU1_RESET_MASK   (0xFU)
#define SECCON_CPU1_RESET_CTRL_CPU1_RESET_SHIFT  (0U)
/*! CPU1_RESET - CPU1_RESET
 *  0b1010..Reset CPU1, any other value will clear Reset of CPU1
 */
#define SECCON_CPU1_RESET_CTRL_CPU1_RESET(x)     (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_RESET_CTRL_CPU1_RESET_SHIFT)) & SECCON_CPU1_RESET_CTRL_CPU1_RESET_MASK)

#define SECCON_CPU1_RESET_CTRL_CPU1_VECTOR_LOCK_MASK (0xF00U)
#define SECCON_CPU1_RESET_CTRL_CPU1_VECTOR_LOCK_SHIFT (8U)
/*! CPU1_VECTOR_LOCK - CPU1_VECTOR_LOCK
 *  0b1010..Unlock CPU1_VECTOR, any other value will lock CPU1_VECTOR.
 */
#define SECCON_CPU1_RESET_CTRL_CPU1_VECTOR_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_RESET_CTRL_CPU1_VECTOR_LOCK_SHIFT)) & SECCON_CPU1_RESET_CTRL_CPU1_VECTOR_LOCK_MASK)

#define SECCON_CPU1_RESET_CTRL_CPU1_RESET_CTRL_LOCK_MASK (0xF0000000U)
#define SECCON_CPU1_RESET_CTRL_CPU1_RESET_CTRL_LOCK_SHIFT (28U)
/*! CPU1_RESET_CTRL_LOCK - CPU1_RESET_CTRL_LOCK
 *  0b1010..Unlock CPU1_CTRL_RESET until next warm reset, any other value will lock CPU1_CTRL_RESET.
 */
#define SECCON_CPU1_RESET_CTRL_CPU1_RESET_CTRL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_RESET_CTRL_CPU1_RESET_CTRL_LOCK_SHIFT)) & SECCON_CPU1_RESET_CTRL_CPU1_RESET_CTRL_LOCK_MASK)
/*! @} */

/*! @name CPU1_VECTOR - CPU1 Initial Vector Set */
/*! @{ */

#define SECCON_CPU1_VECTOR_CPU1_INITVTOR_MASK    (0xFFFFFF80U)
#define SECCON_CPU1_VECTOR_CPU1_INITVTOR_SHIFT   (7U)
/*! CPU1_INITVTOR - CPU1_INITVTOR */
#define SECCON_CPU1_VECTOR_CPU1_INITVTOR(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_VECTOR_CPU1_INITVTOR_SHIFT)) & SECCON_CPU1_VECTOR_CPU1_INITVTOR_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_0_0 - GEN_BLK_0_0 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_0_0_GEN_BLK_0_0_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_0_0_GEN_BLK_0_0_SHIFT (0U)
/*! GEN_BLK_0_0 - GEN_BLK_0 Part 0 */
#define SECCON_GENERAL_BLOCK_0_0_GEN_BLK_0_0(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_0_0_GEN_BLK_0_0_SHIFT)) & SECCON_GENERAL_BLOCK_0_0_GEN_BLK_0_0_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_0_1 - GEN_BLK_0_1 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_0_1_GEN_BLK_0_1_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_0_1_GEN_BLK_0_1_SHIFT (0U)
/*! GEN_BLK_0_1 - GEN_BLK_0 Part 1 */
#define SECCON_GENERAL_BLOCK_0_1_GEN_BLK_0_1(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_0_1_GEN_BLK_0_1_SHIFT)) & SECCON_GENERAL_BLOCK_0_1_GEN_BLK_0_1_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_0_2 - GEN_BLK_0_2 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_0_2_GEN_BLK_0_2_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_0_2_GEN_BLK_0_2_SHIFT (0U)
/*! GEN_BLK_0_2 - GEN_BLK_0 Part 2 */
#define SECCON_GENERAL_BLOCK_0_2_GEN_BLK_0_2(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_0_2_GEN_BLK_0_2_SHIFT)) & SECCON_GENERAL_BLOCK_0_2_GEN_BLK_0_2_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_0_3 - GEN_BLK_0_3 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_0_3_GEN_BLK_0_3_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_0_3_GEN_BLK_0_3_SHIFT (0U)
/*! GEN_BLK_0_3 - GEN_BLK_0 Part 3 */
#define SECCON_GENERAL_BLOCK_0_3_GEN_BLK_0_3(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_0_3_GEN_BLK_0_3_SHIFT)) & SECCON_GENERAL_BLOCK_0_3_GEN_BLK_0_3_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_1_0 - GEN_BLK_1_0 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_1_0_GEN_BLK_1_0_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_1_0_GEN_BLK_1_0_SHIFT (0U)
/*! GEN_BLK_1_0 - GEN_BLK_1 Part 1 */
#define SECCON_GENERAL_BLOCK_1_0_GEN_BLK_1_0(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_1_0_GEN_BLK_1_0_SHIFT)) & SECCON_GENERAL_BLOCK_1_0_GEN_BLK_1_0_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_1_1 - GEN_BLK_1_1 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_1_1_GEN_BLK_1_1_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_1_1_GEN_BLK_1_1_SHIFT (0U)
/*! GEN_BLK_1_1 - GEN_BLK_1 Part 1 */
#define SECCON_GENERAL_BLOCK_1_1_GEN_BLK_1_1(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_1_1_GEN_BLK_1_1_SHIFT)) & SECCON_GENERAL_BLOCK_1_1_GEN_BLK_1_1_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_1_2 - GEN_BLK_1_2 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_1_2_GEN_BLK_1_2_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_1_2_GEN_BLK_1_2_SHIFT (0U)
/*! GEN_BLK_1_2 - GEN_BLK_1 Part 2 */
#define SECCON_GENERAL_BLOCK_1_2_GEN_BLK_1_2(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_1_2_GEN_BLK_1_2_SHIFT)) & SECCON_GENERAL_BLOCK_1_2_GEN_BLK_1_2_MASK)
/*! @} */

/*! @name GENERAL_BLOCK_1_3 - GEN_BLK_1_3 */
/*! @{ */

#define SECCON_GENERAL_BLOCK_1_3_GEN_BLK_1_3_MASK (0xFFFFFFFFU)
#define SECCON_GENERAL_BLOCK_1_3_GEN_BLK_1_3_SHIFT (0U)
/*! GEN_BLK_1_3 - GEN_BLK_1 Part 3 */
#define SECCON_GENERAL_BLOCK_1_3_GEN_BLK_1_3(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_GENERAL_BLOCK_1_3_GEN_BLK_1_3_SHIFT)) & SECCON_GENERAL_BLOCK_1_3_GEN_BLK_1_3_MASK)
/*! @} */

/*! @name UDF_CTRL - UDF_CTRL */
/*! @{ */

#define SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_MASK   (0x3U)
#define SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_SHIFT  (0U)
/*! UDF_CTL_CONST_SEL - UDF_CTL_CONST_SEL
 *  0b00..Select TestKey
 *  0b01..Select DUK
 *  0b10..DeviceHSM
 *  0b11..NXP_mROT
 */
#define SECCON_UDF_CTRL_UDF_CTL_CONST_SEL(x)     (((uint32_t)(((uint32_t)(x)) << SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_SHIFT)) & SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_MASK)

#define SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_LOCK_MASK (0x4U)
#define SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_LOCK_SHIFT (2U)
/*! UDF_CTL_CONST_SEL_LOCK - UDF_CTL_CONST_SEL_LOCK
 *  0b0..Disable write data to UDF_CTL_CONST_SEL bit-field
 *  0b1..Enable write data to UDF_CTL_CONST_SEL bit-field
 */
#define SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_LOCK_SHIFT)) & SECCON_UDF_CTRL_UDF_CTL_CONST_SEL_LOCK_MASK)

#define SECCON_UDF_CTRL_UDF_HIDDEN_MASK          (0xFFFF0000U)
#define SECCON_UDF_CTRL_UDF_HIDDEN_SHIFT         (16U)
/*! UDF_HIDDEN - UDF_HIDDEN
 *  0b0001001100010100..Enable the access of UDF register from APB bus. Any other value will hide UDF, disable the read/write of UDF register from UDF APB bus.
 */
#define SECCON_UDF_CTRL_UDF_HIDDEN(x)            (((uint32_t)(((uint32_t)(x)) << SECCON_UDF_CTRL_UDF_HIDDEN_SHIFT)) & SECCON_UDF_CTRL_UDF_HIDDEN_MASK)
/*! @} */

/*! @name DEVICE_UID_0 - Device UID 0 */
/*! @{ */

#define SECCON_DEVICE_UID_0_UID0_MASK            (0xFFFFFFFFU)
#define SECCON_DEVICE_UID_0_UID0_SHIFT           (0U)
/*! UID0 - Device Unique ID part 0 */
#define SECCON_DEVICE_UID_0_UID0(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_DEVICE_UID_0_UID0_SHIFT)) & SECCON_DEVICE_UID_0_UID0_MASK)
/*! @} */

/*! @name DEVICE_UID_1 - Device UID 1 */
/*! @{ */

#define SECCON_DEVICE_UID_1_UID1_MASK            (0xFFFFFFFFU)
#define SECCON_DEVICE_UID_1_UID1_SHIFT           (0U)
/*! UID1 - Device Unique ID part 1 */
#define SECCON_DEVICE_UID_1_UID1(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_DEVICE_UID_1_UID1_SHIFT)) & SECCON_DEVICE_UID_1_UID1_MASK)
/*! @} */

/*! @name DEVICE_UID_2 - Device UID 2 */
/*! @{ */

#define SECCON_DEVICE_UID_2_UID2_MASK            (0xFFFFFFFFU)
#define SECCON_DEVICE_UID_2_UID2_SHIFT           (0U)
/*! UID2 - Device Unique ID part 2 */
#define SECCON_DEVICE_UID_2_UID2(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_DEVICE_UID_2_UID2_SHIFT)) & SECCON_DEVICE_UID_2_UID2_MASK)
/*! @} */

/*! @name DEVICE_UID_3 - Device UID 3 */
/*! @{ */

#define SECCON_DEVICE_UID_3_UID3_MASK            (0xFFFFFFFFU)
#define SECCON_DEVICE_UID_3_UID3_SHIFT           (0U)
/*! UID3 - Device Unique ID part 3 */
#define SECCON_DEVICE_UID_3_UID3(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_DEVICE_UID_3_UID3_SHIFT)) & SECCON_DEVICE_UID_3_UID3_MASK)
/*! @} */

/*! @name GDET0_CTRL - GDET0 Control */
/*! @{ */

#define SECCON_GDET0_CTRL_GDET_EVTCNT_CLR_MASK   (0x1U)
#define SECCON_GDET0_CTRL_GDET_EVTCNT_CLR_SHIFT  (0U)
/*! GDET_EVTCNT_CLR - GDET Event Counter Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define SECCON_GDET0_CTRL_GDET_EVTCNT_CLR(x)     (((uint32_t)(((uint32_t)(x)) << SECCON_GDET0_CTRL_GDET_EVTCNT_CLR_SHIFT)) & SECCON_GDET0_CTRL_GDET_EVTCNT_CLR_MASK)

#define SECCON_GDET0_CTRL_GDET_ERR_CLR_MASK      (0x2U)
#define SECCON_GDET0_CTRL_GDET_ERR_CLR_SHIFT     (1U)
/*! GDET_ERR_CLR - GDET Error Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define SECCON_GDET0_CTRL_GDET_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_GDET0_CTRL_GDET_ERR_CLR_SHIFT)) & SECCON_GDET0_CTRL_GDET_ERR_CLR_MASK)

#define SECCON_GDET0_CTRL_GDET_ISO_CTR_MASK      (0xCU)
#define SECCON_GDET0_CTRL_GDET_ISO_CTR_SHIFT     (2U)
/*! GDET_ISO_CTR - GDET Isolation Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SECCON_GDET0_CTRL_GDET_ISO_CTR(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_GDET0_CTRL_GDET_ISO_CTR_SHIFT)) & SECCON_GDET0_CTRL_GDET_ISO_CTR_MASK)

#define SECCON_GDET0_CTRL_EVENT_CNT_MASK         (0xFF0000U)
#define SECCON_GDET0_CTRL_EVENT_CNT_SHIFT        (16U)
/*! EVENT_CNT - Event Count Value */
#define SECCON_GDET0_CTRL_EVENT_CNT(x)           (((uint32_t)(((uint32_t)(x)) << SECCON_GDET0_CTRL_EVENT_CNT_SHIFT)) & SECCON_GDET0_CTRL_EVENT_CNT_MASK)

#define SECCON_GDET0_CTRL_POS_SYNC_MASK          (0x1000000U)
#define SECCON_GDET0_CTRL_POS_SYNC_SHIFT         (24U)
/*! POS_SYNC - Positive Glitch Detection
 *  0b0..Not detected
 *  0b1..Detected
 */
#define SECCON_GDET0_CTRL_POS_SYNC(x)            (((uint32_t)(((uint32_t)(x)) << SECCON_GDET0_CTRL_POS_SYNC_SHIFT)) & SECCON_GDET0_CTRL_POS_SYNC_MASK)

#define SECCON_GDET0_CTRL_NEG_SYNC_MASK          (0x2000000U)
#define SECCON_GDET0_CTRL_NEG_SYNC_SHIFT         (25U)
/*! NEG_SYNC - Negative Glitch Detection
 *  0b0..Not detected
 *  0b1..Detected
 */
#define SECCON_GDET0_CTRL_NEG_SYNC(x)            (((uint32_t)(((uint32_t)(x)) << SECCON_GDET0_CTRL_NEG_SYNC_SHIFT)) & SECCON_GDET0_CTRL_NEG_SYNC_MASK)

#define SECCON_GDET0_CTRL_EVENT_CLR_FLAG_MASK    (0x4000000U)
#define SECCON_GDET0_CTRL_EVENT_CLR_FLAG_SHIFT   (26U)
/*! EVENT_CLR_FLAG - Event Counter Clear
 *  0b0..Not cleared
 *  0b1..Cleared
 */
#define SECCON_GDET0_CTRL_EVENT_CLR_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_GDET0_CTRL_EVENT_CLR_FLAG_SHIFT)) & SECCON_GDET0_CTRL_EVENT_CLR_FLAG_MASK)
/*! @} */

/*! @name LC_PROBE_STATE - LC_PROBE_STATE */
/*! @{ */

#define SECCON_LC_PROBE_STATE_LC_PROBE_STATE_MASK (0xFFFFFFFFU)
#define SECCON_LC_PROBE_STATE_LC_PROBE_STATE_SHIFT (0U)
/*! LC_PROBE_STATE - LC_PROBE_STATE */
#define SECCON_LC_PROBE_STATE_LC_PROBE_STATE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_LC_PROBE_STATE_LC_PROBE_STATE_SHIFT)) & SECCON_LC_PROBE_STATE_LC_PROBE_STATE_MASK)
/*! @} */

/*! @name LC_FT_STATE_A - LC_FT_STATE_A */
/*! @{ */

#define SECCON_LC_FT_STATE_A_LC_FT_STATE_A_MASK  (0xFFFFFFFFU)
#define SECCON_LC_FT_STATE_A_LC_FT_STATE_A_SHIFT (0U)
/*! LC_FT_STATE_A - LC_FT_STATE_A */
#define SECCON_LC_FT_STATE_A_LC_FT_STATE_A(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_LC_FT_STATE_A_LC_FT_STATE_A_SHIFT)) & SECCON_LC_FT_STATE_A_LC_FT_STATE_A_MASK)
/*! @} */

/*! @name LC_FT_STATE_B - LC_FT_STATE_B */
/*! @{ */

#define SECCON_LC_FT_STATE_B_LC_FT_STATE_B_MASK  (0xFFFFFFFFU)
#define SECCON_LC_FT_STATE_B_LC_FT_STATE_B_SHIFT (0U)
/*! LC_FT_STATE_B - LC_FT_STATE_B */
#define SECCON_LC_FT_STATE_B_LC_FT_STATE_B(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_LC_FT_STATE_B_LC_FT_STATE_B_SHIFT)) & SECCON_LC_FT_STATE_B_LC_FT_STATE_B_MASK)
/*! @} */

/*! @name CFPA_LC_STATE - OEM Life cycle state. */
/*! @{ */

#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE_MASK  (0xFFU)
#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE_SHIFT (0U)
/*! CFPA_LC_STATE - CFPA_LC_STATE
 *  0b00000011..Develop state
 *  0b00000111..Develop 2 state
 *  0b00001111..In-field state
 *  0b01011010..Bricked stated
 *  0b10100101..FA state
 *  0b11001111..In-field locked state
 */
#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CFPA_LC_STATE_CFPA_LC_STATE_SHIFT)) & SECCON_CFPA_LC_STATE_CFPA_LC_STATE_MASK)

#define SECCON_CFPA_LC_STATE_INV_CFPA_LC_STATE_MASK (0xFF00U)
#define SECCON_CFPA_LC_STATE_INV_CFPA_LC_STATE_SHIFT (8U)
/*! INV_CFPA_LC_STATE - INV_CFPA_LC_STATE
 *  0b00110000..In-field locked state
 *  0b01011010..FA state
 *  0b10100101..Bricked stated
 *  0b11110000..In-field state
 *  0b11111000..Develop 2 state
 *  0b11111100..Develop state
 */
#define SECCON_CFPA_LC_STATE_INV_CFPA_LC_STATE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_CFPA_LC_STATE_INV_CFPA_LC_STATE_SHIFT)) & SECCON_CFPA_LC_STATE_INV_CFPA_LC_STATE_MASK)

#define SECCON_CFPA_LC_STATE_CFPA_HEADER_MASK    (0xFFFF0000U)
#define SECCON_CFPA_LC_STATE_CFPA_HEADER_SHIFT   (16U)
/*! CFPA_HEADER - CFPA_HEADER
 *  0b1001011000110101..valid CFPA header, any other value will be invalid
 */
#define SECCON_CFPA_LC_STATE_CFPA_HEADER(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_CFPA_LC_STATE_CFPA_HEADER_SHIFT)) & SECCON_CFPA_LC_STATE_CFPA_HEADER_MASK)
/*! @} */

/*! @name OVP_STATE - OVP PAD State */
/*! @{ */

#define SECCON_OVP_STATE_OVP_PAD_STATE_MASK      (0xFFFFFFFFU)
#define SECCON_OVP_STATE_OVP_PAD_STATE_SHIFT     (0U)
/*! OVP_PAD_STATE - OVP PAD State */
#define SECCON_OVP_STATE_OVP_PAD_STATE(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_OVP_STATE_OVP_PAD_STATE_SHIFT)) & SECCON_OVP_STATE_OVP_PAD_STATE_MASK)
/*! @} */

/*! @name LIFECYCLE_STATE - Chip LifeCycle State */
/*! @{ */

#define SECCON_LIFECYCLE_STATE_CHIP_LC_STATE_MASK (0xFFU)
#define SECCON_LIFECYCLE_STATE_CHIP_LC_STATE_SHIFT (0U)
/*! CHIP_LC_STATE - Chip LifeCycle State
 *  0b00000000..NXP_BLANK
 *  0b00000001..NXP_FAB
 *  0b00000011..DEVELOP
 *  0b00000111..DEVELOP_2
 *  0b00001111..IN_FIELD
 *  0b00011111..OEM_FIELD_RETURN
 *  0b01111111..NXP_FA
 *  0b11001111..IN_FIELD_LOCKED
 *  0b11111100..NXP_DEV
 *  0b11111111..BRICKED
 */
#define SECCON_LIFECYCLE_STATE_CHIP_LC_STATE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_LIFECYCLE_STATE_CHIP_LC_STATE_SHIFT)) & SECCON_LIFECYCLE_STATE_CHIP_LC_STATE_MASK)
/*! @} */

/*! @name INV_LIFECYCLE_STATE - Invert version of LIFECYCLE_STATE */
/*! @{ */

#define SECCON_INV_LIFECYCLE_STATE_INV_CHIP_LC_STATE_MASK (0xFFU)
#define SECCON_INV_LIFECYCLE_STATE_INV_CHIP_LC_STATE_SHIFT (0U)
#define SECCON_INV_LIFECYCLE_STATE_INV_CHIP_LC_STATE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_INV_LIFECYCLE_STATE_INV_CHIP_LC_STATE_SHIFT)) & SECCON_INV_LIFECYCLE_STATE_INV_CHIP_LC_STATE_MASK)
/*! @} */

/*! @name MDAC0_INJECT_ERR - MDAC0 Error Injection */
/*! @{ */

#define SECCON_MDAC0_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC0_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC0_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC0_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC0_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC0_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC0_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC0_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC0_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC0_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC0_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC0_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC0_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC0_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC0_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC0_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC0_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC0_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC0_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC0_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC0_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC0_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC0_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC0_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC0_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC0_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC0_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC0_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC0_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC0_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name MDAC1_INJECT_ERR - MDAC1 Error Injection */
/*! @{ */

#define SECCON_MDAC1_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC1_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC1_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC1_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC1_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC1_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC1_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC1_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC1_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC1_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC1_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC1_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC1_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC1_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC1_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC1_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC1_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC1_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC1_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC1_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC1_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC1_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC1_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC1_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC1_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC1_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC1_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC1_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC1_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC1_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name MDAC2_INJECT_ERR - MDAC2 Error Injection */
/*! @{ */

#define SECCON_MDAC2_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC2_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC2_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC2_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC2_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC2_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC2_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC2_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC2_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC2_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC2_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC2_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC2_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC2_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC2_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC2_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC2_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC2_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC2_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC2_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC2_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC2_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC2_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC2_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC2_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC2_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC2_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC2_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC2_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC2_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name MDAC3_INJECT_ERR - MDAC3 Error Injection */
/*! @{ */

#define SECCON_MDAC3_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC3_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC3_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC3_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC3_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC3_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC3_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC3_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC3_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC3_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC3_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC3_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC3_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC3_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC3_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC3_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC3_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC3_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC3_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC3_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC3_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC3_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC3_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC3_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC3_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC3_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC3_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC3_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC3_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC3_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name MDAC4_INJECT_ERR - MDAC4 Error Injection */
/*! @{ */

#define SECCON_MDAC4_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC4_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC4_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC4_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC4_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC4_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC4_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC4_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC4_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC4_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC4_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC4_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC4_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC4_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC4_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC4_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC4_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC4_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC4_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC4_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC4_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC4_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC4_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC4_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC4_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC4_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC4_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC4_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC4_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC4_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name MDAC5_INJECT_ERR - MDAC5 Error Injection */
/*! @{ */

#define SECCON_MDAC5_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC5_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC5_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC5_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC5_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC5_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC5_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC5_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC5_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC5_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC5_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC5_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC5_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC5_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC5_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC5_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC5_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC5_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC5_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC5_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC5_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC5_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC5_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC5_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC5_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC5_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC5_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC5_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC5_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC5_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name MDAC6_INJECT_ERR - MDAC6 Error Injection */
/*! @{ */

#define SECCON_MDAC6_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC6_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC6_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC6_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC6_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC6_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC6_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC6_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC6_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC6_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC6_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC6_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC6_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC6_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC6_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC6_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC6_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC6_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC6_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC6_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC6_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC6_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC6_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC6_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC6_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC6_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC6_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC6_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC6_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC6_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name MDAC7_INJECT_ERR - MDAC7 Error Injection */
/*! @{ */

#define SECCON_MDAC7_INJECT_ERR_RD_PROT1_MASK    (0x1U)
#define SECCON_MDAC7_INJECT_ERR_RD_PROT1_SHIFT   (0U)
/*! RD_PROT1 - RD_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC7_INJECT_ERR_RD_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC7_INJECT_ERR_RD_PROT1_SHIFT)) & SECCON_MDAC7_INJECT_ERR_RD_PROT1_MASK)

#define SECCON_MDAC7_INJECT_ERR_WR_PROT1_MASK    (0x2U)
#define SECCON_MDAC7_INJECT_ERR_WR_PROT1_SHIFT   (1U)
/*! WR_PROT1 - WR_PROT1 Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC7_INJECT_ERR_WR_PROT1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC7_INJECT_ERR_WR_PROT1_SHIFT)) & SECCON_MDAC7_INJECT_ERR_WR_PROT1_MASK)

#define SECCON_MDAC7_INJECT_ERR_RD_NONSECURE_MASK (0x4U)
#define SECCON_MDAC7_INJECT_ERR_RD_NONSECURE_SHIFT (2U)
/*! RD_NONSECURE - RD_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC7_INJECT_ERR_RD_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC7_INJECT_ERR_RD_NONSECURE_SHIFT)) & SECCON_MDAC7_INJECT_ERR_RD_NONSECURE_MASK)

#define SECCON_MDAC7_INJECT_ERR_WR_NONSECURE_MASK (0x8U)
#define SECCON_MDAC7_INJECT_ERR_WR_NONSECURE_SHIFT (3U)
/*! WR_NONSECURE - WR_NONSECURE Error Inject
 *  0b0..Disable Inject Error
 *  0b1..Enable Inject Error
 */
#define SECCON_MDAC7_INJECT_ERR_WR_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC7_INJECT_ERR_WR_NONSECURE_SHIFT)) & SECCON_MDAC7_INJECT_ERR_WR_NONSECURE_MASK)

#define SECCON_MDAC7_INJECT_ERR_RD_DID_MASK      (0xF0U)
#define SECCON_MDAC7_INJECT_ERR_RD_DID_SHIFT     (4U)
/*! RD_DID - RD_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC7_INJECT_ERR_RD_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC7_INJECT_ERR_RD_DID_SHIFT)) & SECCON_MDAC7_INJECT_ERR_RD_DID_MASK)

#define SECCON_MDAC7_INJECT_ERR_WR_DID_MASK      (0xF00U)
#define SECCON_MDAC7_INJECT_ERR_WR_DID_SHIFT     (8U)
/*! WR_DID - WR_DID Error Inject
 *  0b0000..Disable Inject Error
 *  0b0001..Enable Inject Error
 */
#define SECCON_MDAC7_INJECT_ERR_WR_DID(x)        (((uint32_t)(((uint32_t)(x)) << SECCON_MDAC7_INJECT_ERR_WR_DID_SHIFT)) & SECCON_MDAC7_INJECT_ERR_WR_DID_MASK)
/*! @} */

/*! @name CPU0_DEBUG_EN - Debug Feature Registers for CPU0 */
/*! @{ */

#define SECCON_CPU0_DEBUG_EN_CPU0_DBGEN_MASK     (0x3U)
#define SECCON_CPU0_DEBUG_EN_CPU0_DBGEN_SHIFT    (0U)
/*! CPU0_DBGEN - CPU0 invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_CPU0_DBGEN(x)       (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_CPU0_DBGEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_CPU0_DBGEN_MASK)

#define SECCON_CPU0_DEBUG_EN_CPU0_NIDEN_MASK     (0xCU)
#define SECCON_CPU0_DEBUG_EN_CPU0_NIDEN_SHIFT    (2U)
/*! CPU0_NIDEN - CPU0 non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_CPU0_NIDEN(x)       (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_CPU0_NIDEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_CPU0_NIDEN_MASK)

#define SECCON_CPU0_DEBUG_EN_CPU0_SPIDEN_MASK    (0x30U)
#define SECCON_CPU0_DEBUG_EN_CPU0_SPIDEN_SHIFT   (4U)
/*! CPU0_SPIDEN - CPU0 secure privileged invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_CPU0_SPIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_CPU0_SPIDEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_CPU0_SPIDEN_MASK)

#define SECCON_CPU0_DEBUG_EN_CPU0_SPNIDEN_MASK   (0xC0U)
#define SECCON_CPU0_DEBUG_EN_CPU0_SPNIDEN_SHIFT  (6U)
/*! CPU0_SPNIDEN - CPU0 secure privileged non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_CPU0_SPNIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_CPU0_SPNIDEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_CPU0_SPNIDEN_MASK)
/*! @} */

/*! @name CPU0_DEBUG_EN_DP - Debug Feature Registers for CPU0 (duplicate) */
/*! @{ */

#define SECCON_CPU0_DEBUG_EN_DP_CPU0_DBGEN_MASK  (0x3U)
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_DBGEN_SHIFT (0U)
/*! CPU0_DBGEN - CPU0 invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_DP_CPU0_DBGEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_DP_CPU0_DBGEN_MASK)

#define SECCON_CPU0_DEBUG_EN_DP_CPU0_NIDEN_MASK  (0xCU)
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_NIDEN_SHIFT (2U)
/*! CPU0_NIDEN - CPU0 non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_NIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_DP_CPU0_NIDEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_DP_CPU0_NIDEN_MASK)

#define SECCON_CPU0_DEBUG_EN_DP_CPU0_SPIDEN_MASK (0x30U)
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_SPIDEN_SHIFT (4U)
/*! CPU0_SPIDEN - CPU0 secure privileged invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_SPIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_DP_CPU0_SPIDEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_DP_CPU0_SPIDEN_MASK)

#define SECCON_CPU0_DEBUG_EN_DP_CPU0_SPNIDEN_MASK (0xC0U)
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_SPNIDEN_SHIFT (6U)
/*! CPU0_SPNIDEN - CPU0 secure privileged non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU0_DEBUG_EN_DP_CPU0_SPNIDEN(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_EN_DP_CPU0_SPNIDEN_SHIFT)) & SECCON_CPU0_DEBUG_EN_DP_CPU0_SPNIDEN_MASK)
/*! @} */

/*! @name CPU1_DEBUG_EN - Debug Feature Registers for CPU1 */
/*! @{ */

#define SECCON_CPU1_DEBUG_EN_CPU1_DBGEN_MASK     (0x3U)
#define SECCON_CPU1_DEBUG_EN_CPU1_DBGEN_SHIFT    (0U)
/*! CPU1_DBGEN - CPU1 invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU1_DEBUG_EN_CPU1_DBGEN(x)       (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_DEBUG_EN_CPU1_DBGEN_SHIFT)) & SECCON_CPU1_DEBUG_EN_CPU1_DBGEN_MASK)

#define SECCON_CPU1_DEBUG_EN_CPU1_NIDEN_MASK     (0xCU)
#define SECCON_CPU1_DEBUG_EN_CPU1_NIDEN_SHIFT    (2U)
/*! CPU1_NIDEN - CPU1 non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU1_DEBUG_EN_CPU1_NIDEN(x)       (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_DEBUG_EN_CPU1_NIDEN_SHIFT)) & SECCON_CPU1_DEBUG_EN_CPU1_NIDEN_MASK)
/*! @} */

/*! @name CPU1_DEBUG_EN_DP - Debug Feature Registers for CPU1 (duplicate) */
/*! @{ */

#define SECCON_CPU1_DEBUG_EN_DP_CPU1_DBGEN_MASK  (0x3U)
#define SECCON_CPU1_DEBUG_EN_DP_CPU1_DBGEN_SHIFT (0U)
/*! CPU1_DBGEN - CPU1 invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU1_DEBUG_EN_DP_CPU1_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_DEBUG_EN_DP_CPU1_DBGEN_SHIFT)) & SECCON_CPU1_DEBUG_EN_DP_CPU1_DBGEN_MASK)

#define SECCON_CPU1_DEBUG_EN_DP_CPU1_NIDEN_MASK  (0xCU)
#define SECCON_CPU1_DEBUG_EN_DP_CPU1_NIDEN_SHIFT (2U)
/*! CPU1_NIDEN - CPU1 non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Not Allow
 */
#define SECCON_CPU1_DEBUG_EN_DP_CPU1_NIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CPU1_DEBUG_EN_DP_CPU1_NIDEN_SHIFT)) & SECCON_CPU1_DEBUG_EN_DP_CPU1_NIDEN_MASK)
/*! @} */

/*! @name DEBUG_AUTH_BEACON - Debug Authentication BEACON */
/*! @{ */

#define SECCON_DEBUG_AUTH_BEACON_BEACON_MASK     (0xFFFFFFFFU)
#define SECCON_DEBUG_AUTH_BEACON_BEACON_SHIFT    (0U)
/*! BEACON - Sets by the debug authentication code in ROM to pass the debug beacons (Credential
 *    Beacon and Authentication Beacon) to the application code.
 */
#define SECCON_DEBUG_AUTH_BEACON_BEACON(x)       (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_AUTH_BEACON_BEACON_SHIFT)) & SECCON_DEBUG_AUTH_BEACON_BEACON_MASK)
/*! @} */

/*! @name DEBUG_FEATURE_LOCK - Controls write access to Debug Security registers */
/*! @{ */

#define SECCON_DEBUG_FEATURE_LOCK_CPU0_DBGEN_LOCK_MASK (0xFU)
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_DBGEN_LOCK_SHIFT (0U)
/*! CPU0_DBGEN_LOCK - Controls write access to the CPU0 invasive debug control
 *  0b1010..Enables write access to all registers, any other value rather than 4'b1010 will disable write access
 *          to all registers. Once write value rather than 4'b1010, this bit field will be locked.
 */
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_DBGEN_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURE_LOCK_CPU0_DBGEN_LOCK_SHIFT)) & SECCON_DEBUG_FEATURE_LOCK_CPU0_DBGEN_LOCK_MASK)

#define SECCON_DEBUG_FEATURE_LOCK_CPU0_NIDEN_LOCK_MASK (0xF0U)
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_NIDEN_LOCK_SHIFT (4U)
/*! CPU0_NIDEN_LOCK - Controls write access to the CPU0 non-invasive debug control
 *  0b1010..Enables write access to all registers, any other value rather than 4'b1010 will disable write access
 *          to all registers. Once value other than 4'b1010 is written, this bit field will be locked.
 */
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_NIDEN_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURE_LOCK_CPU0_NIDEN_LOCK_SHIFT)) & SECCON_DEBUG_FEATURE_LOCK_CPU0_NIDEN_LOCK_MASK)

#define SECCON_DEBUG_FEATURE_LOCK_CPU0_SPIDEN_LOCK_MASK (0xF00U)
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_SPIDEN_LOCK_SHIFT (8U)
/*! CPU0_SPIDEN_LOCK - Controls write access to the CPU0 secure privileged invasive debug control
 *  0b1010..Enables write access to all registers, any other value rather than 4'b1010 will disable write access
 *          to all registers. Once value other than 4'b1010 is written, this bit field will be locked.
 */
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_SPIDEN_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURE_LOCK_CPU0_SPIDEN_LOCK_SHIFT)) & SECCON_DEBUG_FEATURE_LOCK_CPU0_SPIDEN_LOCK_MASK)

#define SECCON_DEBUG_FEATURE_LOCK_CPU0_SPNIDEN_LOCK_MASK (0xF000U)
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_SPNIDEN_LOCK_SHIFT (12U)
/*! CPU0_SPNIDEN_LOCK - Controls write access to the CPU0 secure privileged non-invasive debug control
 *  0b1010..Enables write access to all registers, any other value rather than 4'b1010 will disable write access
 *          to all registers. Once value other than 4'b1010 is written, this bit field will be locked.
 */
#define SECCON_DEBUG_FEATURE_LOCK_CPU0_SPNIDEN_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURE_LOCK_CPU0_SPNIDEN_LOCK_SHIFT)) & SECCON_DEBUG_FEATURE_LOCK_CPU0_SPNIDEN_LOCK_MASK)

#define SECCON_DEBUG_FEATURE_LOCK_CPU1_DBGEN_LOCK_MASK (0xF0000U)
#define SECCON_DEBUG_FEATURE_LOCK_CPU1_DBGEN_LOCK_SHIFT (16U)
/*! CPU1_DBGEN_LOCK - Controls write access to the CPU1 debug related registers
 *  0b1010..Enables write access to all registers, any other value rather than 4'b1010 will disable write access
 *          to all registers. Once value other than 4'b1010 is written, this bit field will be locked.
 */
#define SECCON_DEBUG_FEATURE_LOCK_CPU1_DBGEN_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURE_LOCK_CPU1_DBGEN_LOCK_SHIFT)) & SECCON_DEBUG_FEATURE_LOCK_CPU1_DBGEN_LOCK_MASK)

#define SECCON_DEBUG_FEATURE_LOCK_CPU1_NIDEN_LOCK_MASK (0xF00000U)
#define SECCON_DEBUG_FEATURE_LOCK_CPU1_NIDEN_LOCK_SHIFT (20U)
/*! CPU1_NIDEN_LOCK - Controls write access to the CPU1 debug related registers
 *  0b1010..Enables write access to all registers, any other value rather than 4'b1010 will disable write access
 *          to all registers. Once value other than 4'b1010 is written, this bit field will be locked.
 */
#define SECCON_DEBUG_FEATURE_LOCK_CPU1_NIDEN_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURE_LOCK_CPU1_NIDEN_LOCK_SHIFT)) & SECCON_DEBUG_FEATURE_LOCK_CPU1_NIDEN_LOCK_MASK)

#define SECCON_DEBUG_FEATURE_LOCK_DEBUG_AUTH_BEACON_LOCK_MASK (0xF0000000U)
#define SECCON_DEBUG_FEATURE_LOCK_DEBUG_AUTH_BEACON_LOCK_SHIFT (28U)
/*! DEBUG_AUTH_BEACON_LOCK - Controls write access to the DEBUG_AUTH_BEACON
 *  0b1010..Enables write access to DEBUG_AUTH_BEACON registers, any other value rather than 4'b1010 will disable
 *          write access to all registers. Once value other than 4'b1010 is written, this bit field will be locked.
 */
#define SECCON_DEBUG_FEATURE_LOCK_DEBUG_AUTH_BEACON_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURE_LOCK_DEBUG_AUTH_BEACON_LOCK_SHIFT)) & SECCON_DEBUG_FEATURE_LOCK_DEBUG_AUTH_BEACON_LOCK_MASK)
/*! @} */

/*! @name TEST_ACCESS_EN - Security Code to Allow Test (Design for Testability) access. */
/*! @{ */

#define SECCON_TEST_ACCESS_EN_TEST_ACCESS_ENABLE_MASK (0xFFFFFFFFU)
#define SECCON_TEST_ACCESS_EN_TEST_ACCESS_ENABLE_SHIFT (0U)
/*! TEST_ACCESS_ENABLE - Test Infra Access Control
 *  0b01100001110010001000011001000110..Access to test port/infrastructure is disabled.
 *  0b10011110001101110111100110111001..Access to test port/infrastructure is enabled.
 */
#define SECCON_TEST_ACCESS_EN_TEST_ACCESS_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_TEST_ACCESS_EN_TEST_ACCESS_ENABLE_SHIFT)) & SECCON_TEST_ACCESS_EN_TEST_ACCESS_ENABLE_MASK)
/*! @} */

/*! @name FLASH_ACCESS_EN - Flash Test Access Enable Control */
/*! @{ */

#define SECCON_FLASH_ACCESS_EN_FLASH_ACCESS_ENABLE_MASK (0xFU)
#define SECCON_FLASH_ACCESS_EN_FLASH_ACCESS_ENABLE_SHIFT (0U)
/*! FLASH_ACCESS_ENABLE - Flash Test Access Control
 *  0b1010..Access Enable, any other value means access disable
 */
#define SECCON_FLASH_ACCESS_EN_FLASH_ACCESS_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_FLASH_ACCESS_EN_FLASH_ACCESS_ENABLE_SHIFT)) & SECCON_FLASH_ACCESS_EN_FLASH_ACCESS_ENABLE_MASK)

#define SECCON_FLASH_ACCESS_EN_IFR1_ACCESS_ENABLE_MASK (0xF0U)
#define SECCON_FLASH_ACCESS_EN_IFR1_ACCESS_ENABLE_SHIFT (4U)
/*! IFR1_ACCESS_ENABLE - Flash IFR1 Test Access Control
 *  0b1010..Access Enable, any other value means access disable
 */
#define SECCON_FLASH_ACCESS_EN_IFR1_ACCESS_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_FLASH_ACCESS_EN_IFR1_ACCESS_ENABLE_SHIFT)) & SECCON_FLASH_ACCESS_EN_IFR1_ACCESS_ENABLE_MASK)
/*! @} */

/*! @name SWD_ACCESS_CPU0 - CPU0 Software Debug Access */
/*! @{ */

#define SECCON_SWD_ACCESS_CPU0_CPU0_SWD_ACCESS_ENABLE_MASK (0xFU)
#define SECCON_SWD_ACCESS_CPU0_CPU0_SWD_ACCESS_ENABLE_SHIFT (0U)
/*! CPU0_SWD_ACCESS_ENABLE - CPU0 SWD AP Access Control
 *  0b1010..Access Enable, any other value means access disable
 */
#define SECCON_SWD_ACCESS_CPU0_CPU0_SWD_ACCESS_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_SWD_ACCESS_CPU0_CPU0_SWD_ACCESS_ENABLE_SHIFT)) & SECCON_SWD_ACCESS_CPU0_CPU0_SWD_ACCESS_ENABLE_MASK)
/*! @} */

/*! @name SWD_ACCESS_CPU1 - CPU1 Software Debug Access */
/*! @{ */

#define SECCON_SWD_ACCESS_CPU1_CPU1_SWD_ACCESS_ENABLE_MASK (0xFU)
#define SECCON_SWD_ACCESS_CPU1_CPU1_SWD_ACCESS_ENABLE_SHIFT (0U)
/*! CPU1_SWD_ACCESS_ENABLE - CPU1 SWD AP Access Control
 *  0b1010..Access Enable, any other value means access disable
 */
#define SECCON_SWD_ACCESS_CPU1_CPU1_SWD_ACCESS_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_SWD_ACCESS_CPU1_CPU1_SWD_ACCESS_ENABLE_SHIFT)) & SECCON_SWD_ACCESS_CPU1_CPU1_SWD_ACCESS_ENABLE_MASK)
/*! @} */

/*! @name L2_PASSWORD_MATCH - L2 Password Has Matched */
/*! @{ */

#define SECCON_L2_PASSWORD_MATCH_L2_PASSWORD_MATCHED_MASK (0xFFFFU)
#define SECCON_L2_PASSWORD_MATCH_L2_PASSWORD_MATCHED_SHIFT (0U)
/*! L2_PASSWORD_MATCHED - L2 PASSWORD HAS MATCHED
 *  0b0000000000000000..Not Match
 *  0b0101101001011010..Matched
 */
#define SECCON_L2_PASSWORD_MATCH_L2_PASSWORD_MATCHED(x) (((uint32_t)(((uint32_t)(x)) << SECCON_L2_PASSWORD_MATCH_L2_PASSWORD_MATCHED_SHIFT)) & SECCON_L2_PASSWORD_MATCH_L2_PASSWORD_MATCHED_MASK)
/*! @} */

/*! @name L2_PASSWORD_MATCH_HIDE - Hide L2_PASSWORD_MATCH Reg */
/*! @{ */

#define SECCON_L2_PASSWORD_MATCH_HIDE_MATCH_HIDE_MASK (0xFU)
#define SECCON_L2_PASSWORD_MATCH_HIDE_MATCH_HIDE_SHIFT (0U)
/*! MATCH_HIDE - Hide info of L2_PASSWORD_MATCH
 *  0b1010..Unhide the information in L2_PASSWORD_MATCH register, any other value rather than 4'b1010 will hide L2_PASSWORD_MATCH
 */
#define SECCON_L2_PASSWORD_MATCH_HIDE_MATCH_HIDE(x) (((uint32_t)(((uint32_t)(x)) << SECCON_L2_PASSWORD_MATCH_HIDE_MATCH_HIDE_SHIFT)) & SECCON_L2_PASSWORD_MATCH_HIDE_MATCH_HIDE_MASK)
/*! @} */

/*! @name SOC_ERSIEN - Flash IFR0 Erase Enable */
/*! @{ */

#define SECCON_SOC_ERSIEN_SECTOR_0_ERASE_EN_MASK (0xFU)
#define SECCON_SOC_ERSIEN_SECTOR_0_ERASE_EN_SHIFT (0U)
/*! SECTOR_0_ERASE_EN - Erase IFR Sector Enable - Block 0
 *  0b0000..Block 0 IFR Sector X is protected from erase by ERSSCR command
 *  0b0001..Block 0 IFR Sector X is not protected from erase by ERSSCR command
 */
#define SECCON_SOC_ERSIEN_SECTOR_0_ERASE_EN(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_SOC_ERSIEN_SECTOR_0_ERASE_EN_SHIFT)) & SECCON_SOC_ERSIEN_SECTOR_0_ERASE_EN_MASK)

#define SECCON_SOC_ERSIEN_SECTOR_1_ERASE_EN_MASK (0xF0U)
#define SECCON_SOC_ERSIEN_SECTOR_1_ERASE_EN_SHIFT (4U)
/*! SECTOR_1_ERASE_EN - Erase IFR Sector Enable - Block 1 (for dual block configs)
 *  0b0000..Block 1 IFR Sector X is protected from erase by ERSSCR command
 *  0b0001..Block 1 IFR Sector X is not protected from erase by ERSSCR command
 */
#define SECCON_SOC_ERSIEN_SECTOR_1_ERASE_EN(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_SOC_ERSIEN_SECTOR_1_ERASE_EN_SHIFT)) & SECCON_SOC_ERSIEN_SECTOR_1_ERASE_EN_MASK)

#define SECCON_SOC_ERSIEN_MASS_ERASE_EN_MASK     (0x100U)
#define SECCON_SOC_ERSIEN_MASS_ERASE_EN_SHIFT    (8U)
/*! MASS_ERASE_EN - Mass erase control
 *  0b0..Disables mass erase
 *  0b1..Enables mass erase
 */
#define SECCON_SOC_ERSIEN_MASS_ERASE_EN(x)       (((uint32_t)(((uint32_t)(x)) << SECCON_SOC_ERSIEN_MASS_ERASE_EN_SHIFT)) & SECCON_SOC_ERSIEN_MASS_ERASE_EN_MASK)
/*! @} */

/*! @name BOOT_LOCKOUT_ADDR - ROM Hidden XOM address offset */
/*! @{ */

#define SECCON_BOOT_LOCKOUT_ADDR_HIDDEN_ADDR_OFFSET_MASK (0xFFFFU)
#define SECCON_BOOT_LOCKOUT_ADDR_HIDDEN_ADDR_OFFSET_SHIFT (0U)
/*! HIDDEN_ADDR_OFFSET - ROM Address Range To Lock */
#define SECCON_BOOT_LOCKOUT_ADDR_HIDDEN_ADDR_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_LOCKOUT_ADDR_HIDDEN_ADDR_OFFSET_SHIFT)) & SECCON_BOOT_LOCKOUT_ADDR_HIDDEN_ADDR_OFFSET_MASK)

#define SECCON_BOOT_LOCKOUT_ADDR_XOM_ADDR_OFFSET_MASK (0xFFFF0000U)
#define SECCON_BOOT_LOCKOUT_ADDR_XOM_ADDR_OFFSET_SHIFT (16U)
/*! XOM_ADDR_OFFSET - XOM address offset */
#define SECCON_BOOT_LOCKOUT_ADDR_XOM_ADDR_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_LOCKOUT_ADDR_XOM_ADDR_OFFSET_SHIFT)) & SECCON_BOOT_LOCKOUT_ADDR_XOM_ADDR_OFFSET_MASK)
/*! @} */

/*! @name BOOT_LOCKOUT_ADDR_DP - ROM Hidden XOM address offset duplicate */
/*! @{ */

#define SECCON_BOOT_LOCKOUT_ADDR_DP_HIDDEN_ADDR_OFFSET_DP_MASK (0xFFFFU)
#define SECCON_BOOT_LOCKOUT_ADDR_DP_HIDDEN_ADDR_OFFSET_DP_SHIFT (0U)
/*! HIDDEN_ADDR_OFFSET_DP - ROM Address Range To Lock (Duplicate) */
#define SECCON_BOOT_LOCKOUT_ADDR_DP_HIDDEN_ADDR_OFFSET_DP(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_LOCKOUT_ADDR_DP_HIDDEN_ADDR_OFFSET_DP_SHIFT)) & SECCON_BOOT_LOCKOUT_ADDR_DP_HIDDEN_ADDR_OFFSET_DP_MASK)

#define SECCON_BOOT_LOCKOUT_ADDR_DP_XOM_ADDR_OFFSET_DP_MASK (0xFFFF0000U)
#define SECCON_BOOT_LOCKOUT_ADDR_DP_XOM_ADDR_OFFSET_DP_SHIFT (16U)
/*! XOM_ADDR_OFFSET_DP - XOM address offset (Duplicate) */
#define SECCON_BOOT_LOCKOUT_ADDR_DP_XOM_ADDR_OFFSET_DP(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_LOCKOUT_ADDR_DP_XOM_ADDR_OFFSET_DP_SHIFT)) & SECCON_BOOT_LOCKOUT_ADDR_DP_XOM_ADDR_OFFSET_DP_MASK)
/*! @} */

/*! @name BOOT_LOCKOUT_LOCK - Control write access to BOOT_LOCKOUT_ADDR */
/*! @{ */

#define SECCON_BOOT_LOCKOUT_LOCK_ROM_LOCK_MASK   (0xFFFFFFFFU)
#define SECCON_BOOT_LOCKOUT_LOCK_ROM_LOCK_SHIFT  (0U)
/*! ROM_LOCK - ROM Address Lock */
#define SECCON_BOOT_LOCKOUT_LOCK_ROM_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_LOCKOUT_LOCK_ROM_LOCK_SHIFT)) & SECCON_BOOT_LOCKOUT_LOCK_ROM_LOCK_MASK)
/*! @} */

/*! @name BOOT_RETRY_CNT - Boot Retry Counter */
/*! @{ */

#define SECCON_BOOT_RETRY_CNT_BOOT_RETRY_CNT_MASK (0xFU)
#define SECCON_BOOT_RETRY_CNT_BOOT_RETRY_CNT_SHIFT (0U)
/*! BOOT_RETRY_CNT - Boot retry counter bit. */
#define SECCON_BOOT_RETRY_CNT_BOOT_RETRY_CNT(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_RETRY_CNT_BOOT_RETRY_CNT_SHIFT)) & SECCON_BOOT_RETRY_CNT_BOOT_RETRY_CNT_MASK)
/*! @} */

/*! @name BOOT_TEMP_STATE - Boot Temporal State */
/*! @{ */

#define SECCON_BOOT_TEMP_STATE_BOOT_TEMP_STATE_CNT_MASK (0xFU)
#define SECCON_BOOT_TEMP_STATE_BOOT_TEMP_STATE_CNT_SHIFT (0U)
/*! BOOT_TEMP_STATE_CNT - Temporal state counter bit. */
#define SECCON_BOOT_TEMP_STATE_BOOT_TEMP_STATE_CNT(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_TEMP_STATE_BOOT_TEMP_STATE_CNT_SHIFT)) & SECCON_BOOT_TEMP_STATE_BOOT_TEMP_STATE_CNT_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_0 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_0_BOOT_ATTEST_STATE_0_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_0_BOOT_ATTEST_STATE_0_SHIFT (0U)
/*! BOOT_ATTEST_STATE_0 - BOOT ATTEST STATE 0 */
#define SECCON_BOOT_ATTEST_STATE_0_BOOT_ATTEST_STATE_0(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_0_BOOT_ATTEST_STATE_0_SHIFT)) & SECCON_BOOT_ATTEST_STATE_0_BOOT_ATTEST_STATE_0_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_1 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_1_BOOT_ATTEST_STATE_1_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_1_BOOT_ATTEST_STATE_1_SHIFT (0U)
/*! BOOT_ATTEST_STATE_1 - BOOT ATTEST STATE 1 */
#define SECCON_BOOT_ATTEST_STATE_1_BOOT_ATTEST_STATE_1(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_1_BOOT_ATTEST_STATE_1_SHIFT)) & SECCON_BOOT_ATTEST_STATE_1_BOOT_ATTEST_STATE_1_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_2 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_2_BOOT_ATTEST_STATE_2_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_2_BOOT_ATTEST_STATE_2_SHIFT (0U)
/*! BOOT_ATTEST_STATE_2 - BOOT ATTEST STATE 2 */
#define SECCON_BOOT_ATTEST_STATE_2_BOOT_ATTEST_STATE_2(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_2_BOOT_ATTEST_STATE_2_SHIFT)) & SECCON_BOOT_ATTEST_STATE_2_BOOT_ATTEST_STATE_2_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_3 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_3_BOOT_ATTEST_STATE_3_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_3_BOOT_ATTEST_STATE_3_SHIFT (0U)
/*! BOOT_ATTEST_STATE_3 - BOOT ATTEST STATE 3 */
#define SECCON_BOOT_ATTEST_STATE_3_BOOT_ATTEST_STATE_3(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_3_BOOT_ATTEST_STATE_3_SHIFT)) & SECCON_BOOT_ATTEST_STATE_3_BOOT_ATTEST_STATE_3_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_4 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_4_BOOT_ATTEST_STATE_4_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_4_BOOT_ATTEST_STATE_4_SHIFT (0U)
/*! BOOT_ATTEST_STATE_4 - BOOT ATTEST STATE 4 */
#define SECCON_BOOT_ATTEST_STATE_4_BOOT_ATTEST_STATE_4(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_4_BOOT_ATTEST_STATE_4_SHIFT)) & SECCON_BOOT_ATTEST_STATE_4_BOOT_ATTEST_STATE_4_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_5 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_5_BOOT_ATTEST_STATE_5_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_5_BOOT_ATTEST_STATE_5_SHIFT (0U)
/*! BOOT_ATTEST_STATE_5 - BOOT ATTEST STATE 5 */
#define SECCON_BOOT_ATTEST_STATE_5_BOOT_ATTEST_STATE_5(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_5_BOOT_ATTEST_STATE_5_SHIFT)) & SECCON_BOOT_ATTEST_STATE_5_BOOT_ATTEST_STATE_5_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_6 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_6_BOOT_ATTEST_STATE_6_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_6_BOOT_ATTEST_STATE_6_SHIFT (0U)
/*! BOOT_ATTEST_STATE_6 - BOOT ATTEST STATE 6 */
#define SECCON_BOOT_ATTEST_STATE_6_BOOT_ATTEST_STATE_6(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_6_BOOT_ATTEST_STATE_6_SHIFT)) & SECCON_BOOT_ATTEST_STATE_6_BOOT_ATTEST_STATE_6_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_7 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_7_BOOT_ATTEST_STATE_7_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_7_BOOT_ATTEST_STATE_7_SHIFT (0U)
/*! BOOT_ATTEST_STATE_7 - BOOT ATTEST STATE 7 */
#define SECCON_BOOT_ATTEST_STATE_7_BOOT_ATTEST_STATE_7(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_7_BOOT_ATTEST_STATE_7_SHIFT)) & SECCON_BOOT_ATTEST_STATE_7_BOOT_ATTEST_STATE_7_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_8 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_8_BOOT_ATTEST_STATE_8_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_8_BOOT_ATTEST_STATE_8_SHIFT (0U)
/*! BOOT_ATTEST_STATE_8 - BOOT ATTEST STATE 8 */
#define SECCON_BOOT_ATTEST_STATE_8_BOOT_ATTEST_STATE_8(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_8_BOOT_ATTEST_STATE_8_SHIFT)) & SECCON_BOOT_ATTEST_STATE_8_BOOT_ATTEST_STATE_8_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_9 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_9_BOOT_ATTEST_STATE_9_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_9_BOOT_ATTEST_STATE_9_SHIFT (0U)
/*! BOOT_ATTEST_STATE_9 - BOOT ATTEST STATE 9 */
#define SECCON_BOOT_ATTEST_STATE_9_BOOT_ATTEST_STATE_9(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_9_BOOT_ATTEST_STATE_9_SHIFT)) & SECCON_BOOT_ATTEST_STATE_9_BOOT_ATTEST_STATE_9_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_10 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_10_BOOT_ATTEST_STATE_10_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_10_BOOT_ATTEST_STATE_10_SHIFT (0U)
/*! BOOT_ATTEST_STATE_10 - BOOT ATTEST STATE 10 */
#define SECCON_BOOT_ATTEST_STATE_10_BOOT_ATTEST_STATE_10(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_10_BOOT_ATTEST_STATE_10_SHIFT)) & SECCON_BOOT_ATTEST_STATE_10_BOOT_ATTEST_STATE_10_MASK)
/*! @} */

/*! @name BOOT_ATTEST_STATE_11 - Store boot attest state */
/*! @{ */

#define SECCON_BOOT_ATTEST_STATE_11_BOOT_ATTEST_STATE_11_MASK (0xFFFFFFFFU)
#define SECCON_BOOT_ATTEST_STATE_11_BOOT_ATTEST_STATE_11_SHIFT (0U)
/*! BOOT_ATTEST_STATE_11 - BOOT ATTEST STATE 11 */
#define SECCON_BOOT_ATTEST_STATE_11_BOOT_ATTEST_STATE_11(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_ATTEST_STATE_11_BOOT_ATTEST_STATE_11_SHIFT)) & SECCON_BOOT_ATTEST_STATE_11_BOOT_ATTEST_STATE_11_MASK)
/*! @} */

/*! @name BOOT_STATE_0 - Store boot state */
/*! @{ */

#define SECCON_BOOT_STATE_0_BOOT_STATE_0_MASK    (0xFFFFFFFFU)
#define SECCON_BOOT_STATE_0_BOOT_STATE_0_SHIFT   (0U)
/*! BOOT_STATE_0 - BOOT STATE 0 */
#define SECCON_BOOT_STATE_0_BOOT_STATE_0(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_STATE_0_BOOT_STATE_0_SHIFT)) & SECCON_BOOT_STATE_0_BOOT_STATE_0_MASK)
/*! @} */

/*! @name BOOT_STATE_1 - Store boot state */
/*! @{ */

#define SECCON_BOOT_STATE_1_BOOT_STATE_1_MASK    (0xFFFFFFFFU)
#define SECCON_BOOT_STATE_1_BOOT_STATE_1_SHIFT   (0U)
/*! BOOT_STATE_1 - BOOT STATE 1 */
#define SECCON_BOOT_STATE_1_BOOT_STATE_1(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_STATE_1_BOOT_STATE_1_SHIFT)) & SECCON_BOOT_STATE_1_BOOT_STATE_1_MASK)
/*! @} */

/*! @name BOOT_STATE_2 - Store boot state */
/*! @{ */

#define SECCON_BOOT_STATE_2_BOOT_STATE_2_MASK    (0xFFFFFFFFU)
#define SECCON_BOOT_STATE_2_BOOT_STATE_2_SHIFT   (0U)
/*! BOOT_STATE_2 - BOOT STATE 2 */
#define SECCON_BOOT_STATE_2_BOOT_STATE_2(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_STATE_2_BOOT_STATE_2_SHIFT)) & SECCON_BOOT_STATE_2_BOOT_STATE_2_MASK)
/*! @} */

/*! @name BOOT_STATE_LOCK - Boot State Register Lock */
/*! @{ */

#define SECCON_BOOT_STATE_LOCK_BOOT_STATE_LOCK_MASK (0xFU)
#define SECCON_BOOT_STATE_LOCK_BOOT_STATE_LOCK_SHIFT (0U)
/*! BOOT_STATE_LOCK - BOOT STATE REG LOCK
 *  0b1010..Allow write to BOOT_STATE_x, any other value locks this register as well as BOOT_STATE_x's write permission
 */
#define SECCON_BOOT_STATE_LOCK_BOOT_STATE_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECCON_BOOT_STATE_LOCK_BOOT_STATE_LOCK_SHIFT)) & SECCON_BOOT_STATE_LOCK_BOOT_STATE_LOCK_MASK)
/*! @} */

/*! @name ROM_SCRATCH_PAD_0 - Scratchpad Register 0 */
/*! @{ */

#define SECCON_ROM_SCRATCH_PAD_0_ROM_SCRATCH_PAD_0_MASK (0xFFFFFFFFU)
#define SECCON_ROM_SCRATCH_PAD_0_ROM_SCRATCH_PAD_0_SHIFT (0U)
/*! ROM_SCRATCH_PAD_0 - ROM SCRATCH PAD 0 */
#define SECCON_ROM_SCRATCH_PAD_0_ROM_SCRATCH_PAD_0(x) (((uint32_t)(((uint32_t)(x)) << SECCON_ROM_SCRATCH_PAD_0_ROM_SCRATCH_PAD_0_SHIFT)) & SECCON_ROM_SCRATCH_PAD_0_ROM_SCRATCH_PAD_0_MASK)
/*! @} */

/*! @name ROM_SCRATCH_PAD_1 - Scratchpad Register 1 */
/*! @{ */

#define SECCON_ROM_SCRATCH_PAD_1_ROM_SCRATCH_PAD_1_MASK (0xFFFFFFFFU)
#define SECCON_ROM_SCRATCH_PAD_1_ROM_SCRATCH_PAD_1_SHIFT (0U)
/*! ROM_SCRATCH_PAD_1 - ROM SCRATCH PAD 1 */
#define SECCON_ROM_SCRATCH_PAD_1_ROM_SCRATCH_PAD_1(x) (((uint32_t)(((uint32_t)(x)) << SECCON_ROM_SCRATCH_PAD_1_ROM_SCRATCH_PAD_1_SHIFT)) & SECCON_ROM_SCRATCH_PAD_1_ROM_SCRATCH_PAD_1_MASK)
/*! @} */

/*! @name ROM_API_PARAM - ROM API PARAM */
/*! @{ */

#define SECCON_ROM_API_PARAM_ROM_API_PARAM_MASK  (0xFFFFFFFFU)
#define SECCON_ROM_API_PARAM_ROM_API_PARAM_SHIFT (0U)
/*! ROM_API_PARAM - ROM API PARAM */
#define SECCON_ROM_API_PARAM_ROM_API_PARAM(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_ROM_API_PARAM_ROM_API_PARAM_SHIFT)) & SECCON_ROM_API_PARAM_ROM_API_PARAM_MASK)
/*! @} */

/*! @name RECOVERY_IMAGE_VECTOR - RECOVERY IMAGE VECTOR */
/*! @{ */

#define SECCON_RECOVERY_IMAGE_VECTOR_RECOVERY_IMAGE_VECTOR_MASK (0xFFFFFFFFU)
#define SECCON_RECOVERY_IMAGE_VECTOR_RECOVERY_IMAGE_VECTOR_SHIFT (0U)
/*! RECOVERY_IMAGE_VECTOR - RECOVERY IMAGE VECTOR */
#define SECCON_RECOVERY_IMAGE_VECTOR_RECOVERY_IMAGE_VECTOR(x) (((uint32_t)(((uint32_t)(x)) << SECCON_RECOVERY_IMAGE_VECTOR_RECOVERY_IMAGE_VECTOR_SHIFT)) & SECCON_RECOVERY_IMAGE_VECTOR_RECOVERY_IMAGE_VECTOR_MASK)
/*! @} */

/*! @name LP_WAKEUP_VECTOR - LP WAKEUP VECTOR */
/*! @{ */

#define SECCON_LP_WAKEUP_VECTOR_LP_WAKEUP_VECTOR_MASK (0xFFFFFFFFU)
#define SECCON_LP_WAKEUP_VECTOR_LP_WAKEUP_VECTOR_SHIFT (0U)
/*! LP_WAKEUP_VECTOR - LP WAKEUP VECTOR */
#define SECCON_LP_WAKEUP_VECTOR_LP_WAKEUP_VECTOR(x) (((uint32_t)(((uint32_t)(x)) << SECCON_LP_WAKEUP_VECTOR_LP_WAKEUP_VECTOR_SHIFT)) & SECCON_LP_WAKEUP_VECTOR_LP_WAKEUP_VECTOR_MASK)
/*! @} */

/*! @name NXP_PROV_FW_RUN - NXP PROV FW RUN */
/*! @{ */

#define SECCON_NXP_PROV_FW_RUN_NXP_PROV_FW_RUN_MASK (0xFFFFFFFFU)
#define SECCON_NXP_PROV_FW_RUN_NXP_PROV_FW_RUN_SHIFT (0U)
/*! NXP_PROV_FW_RUN - NXP PROV FW RUN */
#define SECCON_NXP_PROV_FW_RUN_NXP_PROV_FW_RUN(x) (((uint32_t)(((uint32_t)(x)) << SECCON_NXP_PROV_FW_RUN_NXP_PROV_FW_RUN_SHIFT)) & SECCON_NXP_PROV_FW_RUN_NXP_PROV_FW_RUN_MASK)
/*! @} */

/*! @name SPI_FLASH_RECOVERY - SPI FLASH RECOVERY */
/*! @{ */

#define SECCON_SPI_FLASH_RECOVERY_SPI_FLASH_RECOVERY_MASK (0xFFFFFFFFU)
#define SECCON_SPI_FLASH_RECOVERY_SPI_FLASH_RECOVERY_SHIFT (0U)
/*! SPI_FLASH_RECOVERY - SPI FLASH RECOVERY */
#define SECCON_SPI_FLASH_RECOVERY_SPI_FLASH_RECOVERY(x) (((uint32_t)(((uint32_t)(x)) << SECCON_SPI_FLASH_RECOVERY_SPI_FLASH_RECOVERY_SHIFT)) & SECCON_SPI_FLASH_RECOVERY_SPI_FLASH_RECOVERY_MASK)
/*! @} */

/*! @name SPARE - SPARE */
/*! @{ */

#define SECCON_SPARE_SPARE_MASK                  (0xFFFFFFFFU)
#define SECCON_SPARE_SPARE_SHIFT                 (0U)
/*! SPARE - SPARE */
#define SECCON_SPARE_SPARE(x)                    (((uint32_t)(((uint32_t)(x)) << SECCON_SPARE_SPARE_SHIFT)) & SECCON_SPARE_SPARE_MASK)
/*! @} */

/*! @name CPU0_DEBUG_PRE - CPU0 Debug Preparation */
/*! @{ */

#define SECCON_CPU0_DEBUG_PRE_CPU0_STC_REG_MASK  (0xFFFFFFFFU)
#define SECCON_CPU0_DEBUG_PRE_CPU0_STC_REG_SHIFT (0U)
/*! CPU0_STC_REG - Debug Preparation */
#define SECCON_CPU0_DEBUG_PRE_CPU0_STC_REG(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0_DEBUG_PRE_CPU0_STC_REG_SHIFT)) & SECCON_CPU0_DEBUG_PRE_CPU0_STC_REG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SECCON_Register_Masks */


/*!
 * @}
 */ /* end of group SECCON_Peripheral_Access_Layer */


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


#endif  /* PERI_SECCON_H_ */

