/*
** ###################################################################
**     Processors:          MCXW70ACMFT
**                          MCXW70ACMMP
**                          MCXW70ADMFT
**                          MCXW70ADMMP
**
**     Version:             rev. 1.0, 2026-01-09
**     Build:               b260813
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
**     - rev. 1.0 (2026-01-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_SECCON.h
 * @version 1.0
 * @date 2026-01-09
 * @brief CMSIS Peripheral Access Layer for SECCON
 *
 * CMSIS Peripheral Access Layer for SECCON
 */

#if !defined(PERI_SECCON_H_)
#define PERI_SECCON_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW70ACMFT) || defined(CPU_MCXW70ACMMP))
#include "MCXW70AC_COMMON.h"
#elif (defined(CPU_MCXW70ADMFT) || defined(CPU_MCXW70ADMMP))
#include "MCXW70AD_COMMON.h"
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
       uint8_t RESERVED_1[4];
  __IO uint32_t DEVICE_UID_0;                      /**< Device UID 0, offset: 0x68 */
  __IO uint32_t DEVICE_UID_1;                      /**< Device UID 1, offset: 0x6C */
  __IO uint32_t DEVICE_UID_2;                      /**< Device UID 2, offset: 0x70 */
  __IO uint32_t DEVICE_UID_3;                      /**< Device UID 3, offset: 0x74 */
  __IO uint32_t GDET0_CTRL;                        /**< GDET0 Control, offset: 0x78 */
       uint8_t RESERVED_2[16];
  __IO uint32_t CFPA_LC_STATE;                     /**< OEM Life cycle state., offset: 0x8C */
       uint8_t RESERVED_3[16];
  __I  uint32_t LIFECYCLE_STATE;                   /**< Chip LifeCycle State, offset: 0xA0 */
  __I  uint32_t INV_LIFECYCLE_STATE;               /**< Invert version of LIFECYCLE_STATE, offset: 0xA4 */
       uint8_t RESERVED_4[72];
  __IO uint32_t CPU0_DEBUG_EN;                     /**< Debug Feature Registers for CPU0, offset: 0xF0 */
  __IO uint32_t CPU0_DEBUG_EN_DP;                  /**< Debug Feature Registers for CPU0 (duplicate), offset: 0xF4 */
  __IO uint32_t CPU1_DEBUG_EN;                     /**< Debug Feature Registers for CPU1, offset: 0xF8 */
  __IO uint32_t CPU1_DEBUG_EN_DP;                  /**< Debug Feature Registers for CPU1 (duplicate), offset: 0xFC */
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug Authentication BEACON, offset: 0x100 */
  __IO uint32_t DEBUG_FEATURE_LOCK;                /**< Controls write access to Debug Security registers, offset: 0x104 */
       uint8_t RESERVED_5[16];
  __IO uint32_t SWD_ACCESS_CPU0;                   /**< CPU0 Software Debug Access, offset: 0x118 */
  __IO uint32_t SWD_ACCESS_CPU1;                   /**< CPU1 Software Debug Access, offset: 0x11C */
       uint8_t RESERVED_6[8];
  __IO uint32_t SOC_ERSIEN;                        /**< Flash IFR0 Erase Enable, offset: 0x128 */
       uint8_t RESERVED_7[20];
  __IO uint32_t BOOT_RETRY_CNT;                    /**< Boot Retry Counter, offset: 0x140 */
  __IO uint32_t BOOT_TEMP_STATE;                   /**< Boot Temporal State, offset: 0x144 */
       uint8_t RESERVED_8[56];
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
       uint8_t RESERVED_9[140];
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

/*! @name CFPA_LC_STATE - OEM Life cycle state. */
/*! @{ */

#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE_MASK  (0xFFU)
#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE_SHIFT (0U)
/*! CFPA_LC_STATE - CFPA_LC_STATE
 *  0b00000011..Develop state
 *  0b00000111..Develop 2 state
 *  0b00001111..In-field state
 *  0b00111111..FA state
 *  0b01011010..Bricked stated
 *  0b11001111..In-field locked state
 */
#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CFPA_LC_STATE_CFPA_LC_STATE_SHIFT)) & SECCON_CFPA_LC_STATE_CFPA_LC_STATE_MASK)

#define SECCON_CFPA_LC_STATE_INV_CFPA_LC_STATE_MASK (0xFF00U)
#define SECCON_CFPA_LC_STATE_INV_CFPA_LC_STATE_SHIFT (8U)
/*! INV_CFPA_LC_STATE - INV_CFPA_LC_STATE
 *  0b00110000..In-field locked state
 *  0b10100101..Bricked stated
 *  0b11000000..FA state
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

/**
 * @brief Get the unique silicon identifier (UID) from the device
 *
 * This function reads the 128-bit unique device identifier from the SECCON
 * peripheral's DEVICE_UID registers and copies it to the provided buffer.
 * The UID is extracted directly from hardware registers without using any
 * standard library functions.
 *
 * @details The function reads four 32-bit registers (DEVICE_UID_0 through
 *          DEVICE_UID_3) and converts them to a 16-byte array in little-endian
 *          format. Each 32-bit register is broken down into 4 bytes with the
 *          least significant byte first.
 *
 * @param[out] aOutUid16B   Pointer to a buffer that will receive the 16-byte UID.
 *                          Must be at least 16 bytes in size. Caller must ensure it is not NULL.
 * @param[out] pOutLen      Pointer to a variable that will receive the length
 *                          of the UID in bytes (always 16). Caller must ensure it is not NULL.
 *
 * @return None
 */
static inline void Chip_GetUID(uint8_t *aOutUid16B, uint8_t *pOutLen)
{
    union {
        uint32_t words[4];
        uint8_t bytes[16];
    } uid;
    uint8_t i;

    /* Get the MCU uid */
    uid.words[0] = SECCON->DEVICE_UID_0;
    uid.words[1] = SECCON->DEVICE_UID_1;
    uid.words[2] = SECCON->DEVICE_UID_2;
    uid.words[3] = SECCON->DEVICE_UID_3;

    /* Copy bytes */
    for (i = 0U; i < 16U; i++)
    {
        aOutUid16B[i] = uid.bytes[i];
    }

    /* Get the uid length */
    *pOutLen = 16U;
}


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

