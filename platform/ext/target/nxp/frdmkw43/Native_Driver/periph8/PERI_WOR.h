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
**         CMSIS Peripheral Access Layer for WOR
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
 * @file PERI_WOR.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for WOR
 *
 * CMSIS Peripheral Access Layer for WOR
 */

#if !defined(PERI_WOR_H_)
#define PERI_WOR_H_                              /**< Symbol preventing repeated inclusion */

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
   -- WOR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WOR_Peripheral_Access_Layer WOR Peripheral Access Layer
 * @{
 */

/** WOR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< WAKE-ON-RADIO CONTROL, offset: 0x0 */
  __IO uint32_t TIMEOUT;                           /**< WAKE-ON-RADIO TIMEOUT, offset: 0x4 */
  __I  uint32_t TIMESTAMP1;                        /**< WAKE-ON-RADIO TIMESTAMP 1, offset: 0x8 */
  __I  uint32_t TIMESTAMP2;                        /**< WAKE-ON-RADIO TIMESTAMP 2, offset: 0xC */
  __I  uint32_t TIMESTAMP3;                        /**< WAKE-ON-RADIO TIMESTAMP 3, offset: 0x10 */
  __IO uint32_t STATUS;                            /**< WAKE-ON-RADIO STATUS, offset: 0x14 */
  __IO uint32_t WW_CTRL;                           /**< WINDOW-WIDENING CONTROL, offset: 0x18 */
  __IO uint32_t HOP_CTRL;                          /**< FREQUENCY HOP CONTROL, offset: 0x1C */
  __IO uint32_t SLOT0_DESC0;                       /**< SLOT 0 DESCRIPTOR (LSB), offset: 0x20 */
  __IO uint32_t SLOT0_DESC1;                       /**< SLOT 0 DESCRIPTOR (MSB), offset: 0x24 */
  __IO uint32_t SLOT1_DESC0;                       /**< SLOT 1 DESCRIPTOR (LSB), offset: 0x28 */
  __IO uint32_t SLOT1_DESC1;                       /**< SLOT 1 DESCRIPTOR (MSB), offset: 0x2C */
  __IO uint32_t SLOT2_DESC0;                       /**< SLOT 2 DESCRIPTOR (LSB), offset: 0x30 */
  __IO uint32_t SLOT2_DESC1;                       /**< SLOT 2 DESCRIPTOR (MSB), offset: 0x34 */
  __IO uint32_t SLOT3_DESC0;                       /**< SLOT 3 DESCRIPTOR (LSB), offset: 0x38 */
  __IO uint32_t SLOT3_DESC1;                       /**< SLOT 3 DESCRIPTOR (MSB), offset: 0x3C */
  __IO uint32_t AUTO_DRIFT1;                       /**< Auto Drift Calculation 1, offset: 0x40 */
  __IO uint32_t AUTO_DRIFT2;                       /**< Auto Drift Calculation 2, offset: 0x44 */
  __IO uint32_t AUTO_DRIFT3;                       /**< Auto Drift Calculation 3, offset: 0x48 */
  __IO uint32_t AUTO_DRIFT4;                       /**< Auto Drift Calculation 4, offset: 0x4C */
       uint8_t RESERVED_0[72];
  __I  uint32_t TIME;                              /**< Timer Count, offset: 0x98 */
  __I  uint32_t ENTER_TIME_CAPT;                   /**< MAN Low Power Entry Time Captured, offset: 0x9C */
  __I  uint32_t WKUP_TIME_CAPT;                    /**< MAN Low Power Wakeup Time Captured, offset: 0xA0 */
  __IO uint32_t ENTER_TIME;                        /**< MAN Low Power Entry Time Stamp, offset: 0xA4 */
  __IO uint32_t WKUP_TIME;                         /**< MAN Low Power Wakeup Time Stamp, offset: 0xA8 */
} WOR_Type;

/* ----------------------------------------------------------------------------
   -- WOR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WOR_Register_Masks WOR Register Masks
 * @{
 */

/*! @name CTRL - WAKE-ON-RADIO CONTROL */
/*! @{ */

#define WOR_CTRL_WOR_EN_MASK                     (0x1U)
#define WOR_CTRL_WOR_EN_SHIFT                    (0U)
/*! WOR_EN - WAKE-ON-RADIO Enable */
#define WOR_CTRL_WOR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_WOR_EN_SHIFT)) & WOR_CTRL_WOR_EN_MASK)

#define WOR_CTRL_SCHEDULING_MODE_MASK            (0x2U)
#define WOR_CTRL_SCHEDULING_MODE_SHIFT           (1U)
/*! SCHEDULING_MODE - WAKE-ON-RADIO Scheduling Mode */
#define WOR_CTRL_SCHEDULING_MODE(x)              (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_SCHEDULING_MODE_SHIFT)) & WOR_CTRL_SCHEDULING_MODE_MASK)

#define WOR_CTRL_WOR_PROTOCOL_MASK               (0xCU)
#define WOR_CTRL_WOR_PROTOCOL_SHIFT              (2U)
/*! WOR_PROTOCOL - WAKE-ON-RADIO Protocol Selector */
#define WOR_CTRL_WOR_PROTOCOL(x)                 (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_WOR_PROTOCOL_SHIFT)) & WOR_CTRL_WOR_PROTOCOL_MASK)

#define WOR_CTRL_SLOTS_USED_MASK                 (0x70U)
#define WOR_CTRL_SLOTS_USED_SHIFT                (4U)
/*! SLOTS_USED - WAKE-ON-RADIO Number Of Slots Used */
#define WOR_CTRL_SLOTS_USED(x)                   (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_SLOTS_USED_SHIFT)) & WOR_CTRL_SLOTS_USED_MASK)

#define WOR_CTRL_SKIP_FIRST_DSM_MASK             (0x80U)
#define WOR_CTRL_SKIP_FIRST_DSM_SHIFT            (7U)
/*! SKIP_FIRST_DSM - WAKE-ON-RADIO Skip DSM On First Slot */
#define WOR_CTRL_SKIP_FIRST_DSM(x)               (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_SKIP_FIRST_DSM_SHIFT)) & WOR_CTRL_SKIP_FIRST_DSM_MASK)

#define WOR_CTRL_MAN_DSM_SEL_MASK                (0x300U)
#define WOR_CTRL_MAN_DSM_SEL_SHIFT               (8U)
/*! MAN_DSM_SEL - Manual DSM Selector */
#define WOR_CTRL_MAN_DSM_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_MAN_DSM_SEL_SHIFT)) & WOR_CTRL_MAN_DSM_SEL_MASK)

#define WOR_CTRL_RX_SLOT_FAIL_THRESH_MASK        (0x7C00U)
#define WOR_CTRL_RX_SLOT_FAIL_THRESH_SHIFT       (10U)
/*! RX_SLOT_FAIL_THRESH - RX Slot Fail Thresh */
#define WOR_CTRL_RX_SLOT_FAIL_THRESH(x)          (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_RX_SLOT_FAIL_THRESH_SHIFT)) & WOR_CTRL_RX_SLOT_FAIL_THRESH_MASK)

#define WOR_CTRL_DSM_GUARDBAND_MASK              (0xF0000U)
#define WOR_CTRL_DSM_GUARDBAND_SHIFT             (16U)
/*! DSM_GUARDBAND - WAKE-ON-RADIO DSM Guardband */
#define WOR_CTRL_DSM_GUARDBAND(x)                (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_DSM_GUARDBAND_SHIFT)) & WOR_CTRL_DSM_GUARDBAND_MASK)

#define WOR_CTRL_WOR_RESUME_MASK                 (0x1000000U)
#define WOR_CTRL_WOR_RESUME_SHIFT                (24U)
/*! WOR_RESUME - WAKE-ON-RADIO Resume */
#define WOR_CTRL_WOR_RESUME(x)                   (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_WOR_RESUME_SHIFT)) & WOR_CTRL_WOR_RESUME_MASK)

#define WOR_CTRL_WOR_DEBUG_REG_MASK              (0x2000000U)
#define WOR_CTRL_WOR_DEBUG_REG_SHIFT             (25U)
/*! WOR_DEBUG_REG - WAKE-ON-RADIO Debug Register Enable */
#define WOR_CTRL_WOR_DEBUG_REG(x)                (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_WOR_DEBUG_REG_SHIFT)) & WOR_CTRL_WOR_DEBUG_REG_MASK)

#define WOR_CTRL_AUTO_CAL_MASK                   (0x10000000U)
#define WOR_CTRL_AUTO_CAL_SHIFT                  (28U)
/*! AUTO_CAL - Auto calculate and track the drift enable */
#define WOR_CTRL_AUTO_CAL(x)                     (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_AUTO_CAL_SHIFT)) & WOR_CTRL_AUTO_CAL_MASK)

#define WOR_CTRL_SW_CAL_MASK                     (0x20000000U)
#define WOR_CTRL_SW_CAL_SHIFT                    (29U)
/*! SW_CAL - Enable the WOR SW to calculate the drift. Only when AUTO_CAL is set. */
#define WOR_CTRL_SW_CAL(x)                       (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_SW_CAL_SHIFT)) & WOR_CTRL_SW_CAL_MASK)

#define WOR_CTRL_TIME_REC_MASK                   (0x40000000U)
#define WOR_CTRL_TIME_REC_SHIFT                  (30U)
/*! TIME_REC - Enable the WOR HW to record the timing information to the Packet RAM. */
#define WOR_CTRL_TIME_REC(x)                     (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_TIME_REC_SHIFT)) & WOR_CTRL_TIME_REC_MASK)

#define WOR_CTRL_WOR_RX_FAIL_IRQ_EN_MASK         (0x80000000U)
#define WOR_CTRL_WOR_RX_FAIL_IRQ_EN_SHIFT        (31U)
/*! WOR_RX_FAIL_IRQ_EN - WOR_RX_FAIL_IRQ Enable */
#define WOR_CTRL_WOR_RX_FAIL_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << WOR_CTRL_WOR_RX_FAIL_IRQ_EN_SHIFT)) & WOR_CTRL_WOR_RX_FAIL_IRQ_EN_MASK)
/*! @} */

/*! @name TIMEOUT - WAKE-ON-RADIO TIMEOUT */
/*! @{ */

#define WOR_TIMEOUT_RECEIVE_TIMEOUT_MASK         (0xFFFFU)
#define WOR_TIMEOUT_RECEIVE_TIMEOUT_SHIFT        (0U)
/*! RECEIVE_TIMEOUT - WAKE-ON-RADIO Receive Timeout */
#define WOR_TIMEOUT_RECEIVE_TIMEOUT(x)           (((uint32_t)(((uint32_t)(x)) << WOR_TIMEOUT_RECEIVE_TIMEOUT_SHIFT)) & WOR_TIMEOUT_RECEIVE_TIMEOUT_MASK)

#define WOR_TIMEOUT_WAKE_ON_NTH_SLOT_MASK        (0xFF0000U)
#define WOR_TIMEOUT_WAKE_ON_NTH_SLOT_SHIFT       (16U)
/*! WAKE_ON_NTH_SLOT - WAKE-ON-RADIO Force Wake On Nth Slot */
#define WOR_TIMEOUT_WAKE_ON_NTH_SLOT(x)          (((uint32_t)(((uint32_t)(x)) << WOR_TIMEOUT_WAKE_ON_NTH_SLOT_SHIFT)) & WOR_TIMEOUT_WAKE_ON_NTH_SLOT_MASK)

#define WOR_TIMEOUT_WOR_SLOT_COUNT_MASK          (0xFF000000U)
#define WOR_TIMEOUT_WOR_SLOT_COUNT_SHIFT         (24U)
/*! WOR_SLOT_COUNT - WAKE-ON-RADIO Absolute Slot Count */
#define WOR_TIMEOUT_WOR_SLOT_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << WOR_TIMEOUT_WOR_SLOT_COUNT_SHIFT)) & WOR_TIMEOUT_WOR_SLOT_COUNT_MASK)
/*! @} */

/*! @name TIMESTAMP1 - WAKE-ON-RADIO TIMESTAMP 1 */
/*! @{ */

#define WOR_TIMESTAMP1_TIMESTAMP1_MASK           (0xFFFFFFFFU)
#define WOR_TIMESTAMP1_TIMESTAMP1_SHIFT          (0U)
/*! TIMESTAMP1 - WAKE-ON-RADIO TIMESTAMP1 */
#define WOR_TIMESTAMP1_TIMESTAMP1(x)             (((uint32_t)(((uint32_t)(x)) << WOR_TIMESTAMP1_TIMESTAMP1_SHIFT)) & WOR_TIMESTAMP1_TIMESTAMP1_MASK)
/*! @} */

/*! @name TIMESTAMP2 - WAKE-ON-RADIO TIMESTAMP 2 */
/*! @{ */

#define WOR_TIMESTAMP2_TIMESTAMP2_MASK           (0xFFFFFFFFU)
#define WOR_TIMESTAMP2_TIMESTAMP2_SHIFT          (0U)
/*! TIMESTAMP2 - WAKE-ON-RADIO TIMESTAMP2 */
#define WOR_TIMESTAMP2_TIMESTAMP2(x)             (((uint32_t)(((uint32_t)(x)) << WOR_TIMESTAMP2_TIMESTAMP2_SHIFT)) & WOR_TIMESTAMP2_TIMESTAMP2_MASK)
/*! @} */

/*! @name TIMESTAMP3 - WAKE-ON-RADIO TIMESTAMP 3 */
/*! @{ */

#define WOR_TIMESTAMP3_TIMESTAMP3_MASK           (0xFFFFFFFFU)
#define WOR_TIMESTAMP3_TIMESTAMP3_SHIFT          (0U)
/*! TIMESTAMP3 - WAKE-ON-RADIO TIMESTAMP3 */
#define WOR_TIMESTAMP3_TIMESTAMP3(x)             (((uint32_t)(((uint32_t)(x)) << WOR_TIMESTAMP3_TIMESTAMP3_SHIFT)) & WOR_TIMESTAMP3_TIMESTAMP3_MASK)
/*! @} */

/*! @name STATUS - WAKE-ON-RADIO STATUS */
/*! @{ */

#define WOR_STATUS_TIMESTAMP0_STS_MASK           (0x7U)
#define WOR_STATUS_TIMESTAMP0_STS_SHIFT          (0U)
/*! TIMESTAMP0_STS - WAKE-ON-RADIO Timestamp 0 Status */
#define WOR_STATUS_TIMESTAMP0_STS(x)             (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_TIMESTAMP0_STS_SHIFT)) & WOR_STATUS_TIMESTAMP0_STS_MASK)

#define WOR_STATUS_TIMESTAMP1_STS_MASK           (0x38U)
#define WOR_STATUS_TIMESTAMP1_STS_SHIFT          (3U)
/*! TIMESTAMP1_STS - WAKE-ON-RADIO Timestamp 1 Status */
#define WOR_STATUS_TIMESTAMP1_STS(x)             (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_TIMESTAMP1_STS_SHIFT)) & WOR_STATUS_TIMESTAMP1_STS_MASK)

#define WOR_STATUS_TIMESTAMP2_STS_MASK           (0x1C0U)
#define WOR_STATUS_TIMESTAMP2_STS_SHIFT          (6U)
/*! TIMESTAMP2_STS - WAKE-ON-RADIO Timestamp 2 Status */
#define WOR_STATUS_TIMESTAMP2_STS(x)             (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_TIMESTAMP2_STS_SHIFT)) & WOR_STATUS_TIMESTAMP2_STS_MASK)

#define WOR_STATUS_TIMESTAMP3_STS_MASK           (0xE00U)
#define WOR_STATUS_TIMESTAMP3_STS_SHIFT          (9U)
/*! TIMESTAMP3_STS - WAKE-ON-RADIO Timestamp 3 Status */
#define WOR_STATUS_TIMESTAMP3_STS(x)             (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_TIMESTAMP3_STS_SHIFT)) & WOR_STATUS_TIMESTAMP3_STS_MASK)

#define WOR_STATUS_SLOT_MASK                     (0x3000U)
#define WOR_STATUS_SLOT_SHIFT                    (12U)
/*! SLOT - WAKE-ON-RADIO Current Slot */
#define WOR_STATUS_SLOT(x)                       (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_SLOT_SHIFT)) & WOR_STATUS_SLOT_MASK)

#define WOR_STATUS_WOR_NO_RF_FLAG_MASK           (0x10000U)
#define WOR_STATUS_WOR_NO_RF_FLAG_SHIFT          (16U)
/*! WOR_NO_RF_FLAG - WAKE-ON-RADIO NO_RF Slot Flag */
#define WOR_STATUS_WOR_NO_RF_FLAG(x)             (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_WOR_NO_RF_FLAG_SHIFT)) & WOR_STATUS_WOR_NO_RF_FLAG_MASK)

#define WOR_STATUS_WOR_MAX_SLOT_FLAG_MASK        (0x20000U)
#define WOR_STATUS_WOR_MAX_SLOT_FLAG_SHIFT       (17U)
/*! WOR_MAX_SLOT_FLAG - WAKE-ON-RADIO Maximum Slot Count Reached Flag */
#define WOR_STATUS_WOR_MAX_SLOT_FLAG(x)          (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_WOR_MAX_SLOT_FLAG_SHIFT)) & WOR_STATUS_WOR_MAX_SLOT_FLAG_MASK)

#define WOR_STATUS_WOR_DSM_EXIT_FLAG_MASK        (0x40000U)
#define WOR_STATUS_WOR_DSM_EXIT_FLAG_SHIFT       (18U)
/*! WOR_DSM_EXIT_FLAG - WAKE-ON-RADIO Early DSM Exit Flag */
#define WOR_STATUS_WOR_DSM_EXIT_FLAG(x)          (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_WOR_DSM_EXIT_FLAG_SHIFT)) & WOR_STATUS_WOR_DSM_EXIT_FLAG_MASK)

#define WOR_STATUS_WOR_STATE_MASK                (0xF00000U)
#define WOR_STATUS_WOR_STATE_SHIFT               (20U)
/*! WOR_STATE - WAKE-ON-RADIO Current State */
#define WOR_STATUS_WOR_STATE(x)                  (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_WOR_STATE_SHIFT)) & WOR_STATUS_WOR_STATE_MASK)

#define WOR_STATUS_WOR_RX_FAIL_IRQ_MASK          (0x80000000U)
#define WOR_STATUS_WOR_RX_FAIL_IRQ_SHIFT         (31U)
/*! WOR_RX_FAIL_IRQ - WOR RX Fail Interrupt Flag */
#define WOR_STATUS_WOR_RX_FAIL_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << WOR_STATUS_WOR_RX_FAIL_IRQ_SHIFT)) & WOR_STATUS_WOR_RX_FAIL_IRQ_MASK)
/*! @} */

/*! @name WW_CTRL - WINDOW-WIDENING CONTROL */
/*! @{ */

#define WOR_WW_CTRL_WW_EN_MASK                   (0x1U)
#define WOR_WW_CTRL_WW_EN_SHIFT                  (0U)
/*! WW_EN - Window-widening Enable */
#define WOR_WW_CTRL_WW_EN(x)                     (((uint32_t)(((uint32_t)(x)) << WOR_WW_CTRL_WW_EN_SHIFT)) & WOR_WW_CTRL_WW_EN_MASK)

#define WOR_WW_CTRL_WW_RESET_ON_RX_MASK          (0x2U)
#define WOR_WW_CTRL_WW_RESET_ON_RX_SHIFT         (1U)
/*! WW_RESET_ON_RX - Window-widening Reset on Received Good Packet */
#define WOR_WW_CTRL_WW_RESET_ON_RX(x)            (((uint32_t)(((uint32_t)(x)) << WOR_WW_CTRL_WW_RESET_ON_RX_SHIFT)) & WOR_WW_CTRL_WW_RESET_ON_RX_MASK)

#define WOR_WW_CTRL_WW_NULL_MASK                 (0x4U)
#define WOR_WW_CTRL_WW_NULL_SHIFT                (2U)
/*! WW_NULL - Window-widening Null Command */
#define WOR_WW_CTRL_WW_NULL(x)                   (((uint32_t)(((uint32_t)(x)) << WOR_WW_CTRL_WW_NULL_SHIFT)) & WOR_WW_CTRL_WW_NULL_MASK)

#define WOR_WW_CTRL_WW_ADD_MASK                  (0x8U)
#define WOR_WW_CTRL_WW_ADD_SHIFT                 (3U)
/*! WW_ADD - Window-widening Add Command */
#define WOR_WW_CTRL_WW_ADD(x)                    (((uint32_t)(((uint32_t)(x)) << WOR_WW_CTRL_WW_ADD_SHIFT)) & WOR_WW_CTRL_WW_ADD_MASK)

#define WOR_WW_CTRL_WW_DSM_FACTOR_MASK           (0x3F00U)
#define WOR_WW_CTRL_WW_DSM_FACTOR_SHIFT          (8U)
/*! WW_DSM_FACTOR - Window-widening DSM Factor */
#define WOR_WW_CTRL_WW_DSM_FACTOR(x)             (((uint32_t)(((uint32_t)(x)) << WOR_WW_CTRL_WW_DSM_FACTOR_SHIFT)) & WOR_WW_CTRL_WW_DSM_FACTOR_MASK)

#define WOR_WW_CTRL_WW_RUN_FACTOR_MASK           (0x1F0000U)
#define WOR_WW_CTRL_WW_RUN_FACTOR_SHIFT          (16U)
/*! WW_RUN_FACTOR - Window-widening Runtime Factor */
#define WOR_WW_CTRL_WW_RUN_FACTOR(x)             (((uint32_t)(((uint32_t)(x)) << WOR_WW_CTRL_WW_RUN_FACTOR_SHIFT)) & WOR_WW_CTRL_WW_RUN_FACTOR_MASK)

#define WOR_WW_CTRL_WW_INCREASE_MASK             (0xFF000000U)
#define WOR_WW_CTRL_WW_INCREASE_SHIFT            (24U)
/*! WW_INCREASE - Window-widening Manual Increase Amount */
#define WOR_WW_CTRL_WW_INCREASE(x)               (((uint32_t)(((uint32_t)(x)) << WOR_WW_CTRL_WW_INCREASE_SHIFT)) & WOR_WW_CTRL_WW_INCREASE_MASK)
/*! @} */

/*! @name HOP_CTRL - FREQUENCY HOP CONTROL */
/*! @{ */

#define WOR_HOP_CTRL_HOP_TBL_CFG_MASK            (0x7U)
#define WOR_HOP_CTRL_HOP_TBL_CFG_SHIFT           (0U)
/*! HOP_TBL_CFG - Hop Table Configuration */
#define WOR_HOP_CTRL_HOP_TBL_CFG(x)              (((uint32_t)(((uint32_t)(x)) << WOR_HOP_CTRL_HOP_TBL_CFG_SHIFT)) & WOR_HOP_CTRL_HOP_TBL_CFG_MASK)

#define WOR_HOP_CTRL_NEW_HOP_IDX_MASK            (0x7F00U)
#define WOR_HOP_CTRL_NEW_HOP_IDX_SHIFT           (8U)
/*! NEW_HOP_IDX - New Hop Table Index */
#define WOR_HOP_CTRL_NEW_HOP_IDX(x)              (((uint32_t)(((uint32_t)(x)) << WOR_HOP_CTRL_NEW_HOP_IDX_SHIFT)) & WOR_HOP_CTRL_NEW_HOP_IDX_MASK)

#define WOR_HOP_CTRL_UPDATE_HOP_IDX_MASK         (0x8000U)
#define WOR_HOP_CTRL_UPDATE_HOP_IDX_SHIFT        (15U)
/*! UPDATE_HOP_IDX - Update Hop Table Index */
#define WOR_HOP_CTRL_UPDATE_HOP_IDX(x)           (((uint32_t)(((uint32_t)(x)) << WOR_HOP_CTRL_UPDATE_HOP_IDX_SHIFT)) & WOR_HOP_CTRL_UPDATE_HOP_IDX_MASK)

#define WOR_HOP_CTRL_HOP_SEQ_LENGTH_MASK         (0xFF0000U)
#define WOR_HOP_CTRL_HOP_SEQ_LENGTH_SHIFT        (16U)
/*! HOP_SEQ_LENGTH - New Hop Table Index */
#define WOR_HOP_CTRL_HOP_SEQ_LENGTH(x)           (((uint32_t)(((uint32_t)(x)) << WOR_HOP_CTRL_HOP_SEQ_LENGTH_SHIFT)) & WOR_HOP_CTRL_HOP_SEQ_LENGTH_MASK)
/*! @} */

/*! @name SLOT0_DESC0 - SLOT 0 DESCRIPTOR (LSB) */
/*! @{ */

#define WOR_SLOT0_DESC0_SLOT0_DESC0_MASK         (0xFFFFFFFFU)
#define WOR_SLOT0_DESC0_SLOT0_DESC0_SHIFT        (0U)
/*! SLOT0_DESC0 - Slot 0 Descriptor (LSB's) */
#define WOR_SLOT0_DESC0_SLOT0_DESC0(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT0_DESC0_SLOT0_DESC0_SHIFT)) & WOR_SLOT0_DESC0_SLOT0_DESC0_MASK)
/*! @} */

/*! @name SLOT0_DESC1 - SLOT 0 DESCRIPTOR (MSB) */
/*! @{ */

#define WOR_SLOT0_DESC1_SLOT0_DESC1_MASK         (0x3FU)
#define WOR_SLOT0_DESC1_SLOT0_DESC1_SHIFT        (0U)
/*! SLOT0_DESC1 - Slot 0 Descriptor (MSB's) */
#define WOR_SLOT0_DESC1_SLOT0_DESC1(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT0_DESC1_SLOT0_DESC1_SHIFT)) & WOR_SLOT0_DESC1_SLOT0_DESC1_MASK)

#define WOR_SLOT0_DESC1_WOR_HOP_IDX_MASK         (0x7F00U)
#define WOR_SLOT0_DESC1_WOR_HOP_IDX_SHIFT        (8U)
/*! WOR_HOP_IDX - Current Hop Table Index */
#define WOR_SLOT0_DESC1_WOR_HOP_IDX(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT0_DESC1_WOR_HOP_IDX_SHIFT)) & WOR_SLOT0_DESC1_WOR_HOP_IDX_MASK)

#define WOR_SLOT0_DESC1_WOR_HOP_FREQ_WORD_MASK   (0xFFFF0000U)
#define WOR_SLOT0_DESC1_WOR_HOP_FREQ_WORD_SHIFT  (16U)
/*! WOR_HOP_FREQ_WORD - Current Hop Frequency Word */
#define WOR_SLOT0_DESC1_WOR_HOP_FREQ_WORD(x)     (((uint32_t)(((uint32_t)(x)) << WOR_SLOT0_DESC1_WOR_HOP_FREQ_WORD_SHIFT)) & WOR_SLOT0_DESC1_WOR_HOP_FREQ_WORD_MASK)
/*! @} */

/*! @name SLOT1_DESC0 - SLOT 1 DESCRIPTOR (LSB) */
/*! @{ */

#define WOR_SLOT1_DESC0_SLOT1_DESC0_MASK         (0xFFFFFFFFU)
#define WOR_SLOT1_DESC0_SLOT1_DESC0_SHIFT        (0U)
/*! SLOT1_DESC0 - Slot 1 Descriptor (LSB's) */
#define WOR_SLOT1_DESC0_SLOT1_DESC0(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT1_DESC0_SLOT1_DESC0_SHIFT)) & WOR_SLOT1_DESC0_SLOT1_DESC0_MASK)
/*! @} */

/*! @name SLOT1_DESC1 - SLOT 1 DESCRIPTOR (MSB) */
/*! @{ */

#define WOR_SLOT1_DESC1_SLOT1_DESC1_MASK         (0x3FU)
#define WOR_SLOT1_DESC1_SLOT1_DESC1_SHIFT        (0U)
/*! SLOT1_DESC1 - Slot 1 Descriptor (MSB's) */
#define WOR_SLOT1_DESC1_SLOT1_DESC1(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT1_DESC1_SLOT1_DESC1_SHIFT)) & WOR_SLOT1_DESC1_SLOT1_DESC1_MASK)
/*! @} */

/*! @name SLOT2_DESC0 - SLOT 2 DESCRIPTOR (LSB) */
/*! @{ */

#define WOR_SLOT2_DESC0_SLOT2_DESC0_MASK         (0xFFFFFFFFU)
#define WOR_SLOT2_DESC0_SLOT2_DESC0_SHIFT        (0U)
/*! SLOT2_DESC0 - Slot 2 Descriptor (LSB's) */
#define WOR_SLOT2_DESC0_SLOT2_DESC0(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT2_DESC0_SLOT2_DESC0_SHIFT)) & WOR_SLOT2_DESC0_SLOT2_DESC0_MASK)
/*! @} */

/*! @name SLOT2_DESC1 - SLOT 2 DESCRIPTOR (MSB) */
/*! @{ */

#define WOR_SLOT2_DESC1_SLOT2_DESC1_MASK         (0x3FU)
#define WOR_SLOT2_DESC1_SLOT2_DESC1_SHIFT        (0U)
/*! SLOT2_DESC1 - Slot 2 Descriptor (MSB's) */
#define WOR_SLOT2_DESC1_SLOT2_DESC1(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT2_DESC1_SLOT2_DESC1_SHIFT)) & WOR_SLOT2_DESC1_SLOT2_DESC1_MASK)
/*! @} */

/*! @name SLOT3_DESC0 - SLOT 3 DESCRIPTOR (LSB) */
/*! @{ */

#define WOR_SLOT3_DESC0_SLOT3_DESC0_MASK         (0xFFFFFFFFU)
#define WOR_SLOT3_DESC0_SLOT3_DESC0_SHIFT        (0U)
/*! SLOT3_DESC0 - Slot 3 Descriptor (LSB's) */
#define WOR_SLOT3_DESC0_SLOT3_DESC0(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT3_DESC0_SLOT3_DESC0_SHIFT)) & WOR_SLOT3_DESC0_SLOT3_DESC0_MASK)
/*! @} */

/*! @name SLOT3_DESC1 - SLOT 3 DESCRIPTOR (MSB) */
/*! @{ */

#define WOR_SLOT3_DESC1_SLOT3_DESC1_MASK         (0x3FU)
#define WOR_SLOT3_DESC1_SLOT3_DESC1_SHIFT        (0U)
/*! SLOT3_DESC1 - Slot 3 Descriptor (MSB's) */
#define WOR_SLOT3_DESC1_SLOT3_DESC1(x)           (((uint32_t)(((uint32_t)(x)) << WOR_SLOT3_DESC1_SLOT3_DESC1_SHIFT)) & WOR_SLOT3_DESC1_SLOT3_DESC1_MASK)
/*! @} */

/*! @name AUTO_DRIFT1 - Auto Drift Calculation 1 */
/*! @{ */

#define WOR_AUTO_DRIFT1_SW_DRIFT_SET_MASK        (0x7FU)
#define WOR_AUTO_DRIFT1_SW_DRIFT_SET_SHIFT       (0U)
/*! SW_DRIFT_SET - Software calculated drift. */
#define WOR_AUTO_DRIFT1_SW_DRIFT_SET(x)          (((uint32_t)(((uint32_t)(x)) << WOR_AUTO_DRIFT1_SW_DRIFT_SET_SHIFT)) & WOR_AUTO_DRIFT1_SW_DRIFT_SET_MASK)

#define WOR_AUTO_DRIFT1_CAL_DSM_FACTOR_MASK      (0x7F0000U)
#define WOR_AUTO_DRIFT1_CAL_DSM_FACTOR_SHIFT     (16U)
/*! CAL_DSM_FACTOR - Hardware calculated drift. */
#define WOR_AUTO_DRIFT1_CAL_DSM_FACTOR(x)        (((uint32_t)(((uint32_t)(x)) << WOR_AUTO_DRIFT1_CAL_DSM_FACTOR_SHIFT)) & WOR_AUTO_DRIFT1_CAL_DSM_FACTOR_MASK)
/*! @} */

/*! @name AUTO_DRIFT2 - Auto Drift Calculation 2 */
/*! @{ */

#define WOR_AUTO_DRIFT2_AA_SFD_DLY_MASK          (0xFFFFU)
#define WOR_AUTO_DRIFT2_AA_SFD_DLY_SHIFT         (0U)
/*! AA_SFD_DLY - The time duration of Preamble and Sync Address plus the RX warm up duration. */
#define WOR_AUTO_DRIFT2_AA_SFD_DLY(x)            (((uint32_t)(((uint32_t)(x)) << WOR_AUTO_DRIFT2_AA_SFD_DLY_SHIFT)) & WOR_AUTO_DRIFT2_AA_SFD_DLY_MASK)
/*! @} */

/*! @name AUTO_DRIFT3 - Auto Drift Calculation 3 */
/*! @{ */

#define WOR_AUTO_DRIFT3_TIME_MGN_MASK            (0xFFFFU)
#define WOR_AUTO_DRIFT3_TIME_MGN_SHIFT           (0U)
/*! TIME_MGN - The time margin applied to the start time and timeout. */
#define WOR_AUTO_DRIFT3_TIME_MGN(x)              (((uint32_t)(((uint32_t)(x)) << WOR_AUTO_DRIFT3_TIME_MGN_SHIFT)) & WOR_AUTO_DRIFT3_TIME_MGN_MASK)
/*! @} */

/*! @name AUTO_DRIFT4 - Auto Drift Calculation 4 */
/*! @{ */

#define WOR_AUTO_DRIFT4_TINT_DIV_MILLION_MASK    (0xFFFFFFU)
#define WOR_AUTO_DRIFT4_TINT_DIV_MILLION_SHIFT   (0U)
#define WOR_AUTO_DRIFT4_TINT_DIV_MILLION(x)      (((uint32_t)(((uint32_t)(x)) << WOR_AUTO_DRIFT4_TINT_DIV_MILLION_SHIFT)) & WOR_AUTO_DRIFT4_TINT_DIV_MILLION_MASK)
/*! @} */

/*! @name TIME - Timer Count */
/*! @{ */

#define WOR_TIME_TIME_MASK                       (0xFFFFFFU)
#define WOR_TIME_TIME_SHIFT                      (0U)
#define WOR_TIME_TIME(x)                         (((uint32_t)(((uint32_t)(x)) << WOR_TIME_TIME_SHIFT)) & WOR_TIME_TIME_MASK)
/*! @} */

/*! @name ENTER_TIME_CAPT - MAN Low Power Entry Time Captured */
/*! @{ */

#define WOR_ENTER_TIME_CAPT_ENTER_TIME_CAPT_MASK (0xFFFFFFU)
#define WOR_ENTER_TIME_CAPT_ENTER_TIME_CAPT_SHIFT (0U)
#define WOR_ENTER_TIME_CAPT_ENTER_TIME_CAPT(x)   (((uint32_t)(((uint32_t)(x)) << WOR_ENTER_TIME_CAPT_ENTER_TIME_CAPT_SHIFT)) & WOR_ENTER_TIME_CAPT_ENTER_TIME_CAPT_MASK)
/*! @} */

/*! @name WKUP_TIME_CAPT - MAN Low Power Wakeup Time Captured */
/*! @{ */

#define WOR_WKUP_TIME_CAPT_WKUP_TIME_CAPT_MASK   (0xFFFFFFU)
#define WOR_WKUP_TIME_CAPT_WKUP_TIME_CAPT_SHIFT  (0U)
#define WOR_WKUP_TIME_CAPT_WKUP_TIME_CAPT(x)     (((uint32_t)(((uint32_t)(x)) << WOR_WKUP_TIME_CAPT_WKUP_TIME_CAPT_SHIFT)) & WOR_WKUP_TIME_CAPT_WKUP_TIME_CAPT_MASK)
/*! @} */

/*! @name ENTER_TIME - MAN Low Power Entry Time Stamp */
/*! @{ */

#define WOR_ENTER_TIME_ENTER_TIME_MASK           (0xFFFFFFU)
#define WOR_ENTER_TIME_ENTER_TIME_SHIFT          (0U)
#define WOR_ENTER_TIME_ENTER_TIME(x)             (((uint32_t)(((uint32_t)(x)) << WOR_ENTER_TIME_ENTER_TIME_SHIFT)) & WOR_ENTER_TIME_ENTER_TIME_MASK)
/*! @} */

/*! @name WKUP_TIME - MAN Low Power Wakeup Time Stamp */
/*! @{ */

#define WOR_WKUP_TIME_WKUP_TIME_MASK             (0xFFFFFFU)
#define WOR_WKUP_TIME_WKUP_TIME_SHIFT            (0U)
#define WOR_WKUP_TIME_WKUP_TIME(x)               (((uint32_t)(((uint32_t)(x)) << WOR_WKUP_TIME_WKUP_TIME_SHIFT)) & WOR_WKUP_TIME_WKUP_TIME_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WOR_Register_Masks */


/*!
 * @}
 */ /* end of group WOR_Peripheral_Access_Layer */


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


#endif  /* PERI_WOR_H_ */

