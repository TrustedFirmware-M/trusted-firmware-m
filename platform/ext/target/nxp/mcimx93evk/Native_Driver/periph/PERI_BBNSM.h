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
**         CMSIS Peripheral Access Layer for BBNSM
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
 * @file PERI_BBNSM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BBNSM
 *
 * CMSIS Peripheral Access Layer for BBNSM
 */

#if !defined(PERI_BBNSM_H_)
#define PERI_BBNSM_H_                            /**< Symbol preventing repeated inclusion */

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
   -- BBNSM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BBNSM_Peripheral_Access_Layer BBNSM Peripheral Access Layer
 * @{
 */

/** BBNSM - Size of Registers Arrays */
#define BBNSM_GPR_ARRAY_COUNT                     8u

/** BBNSM - Register Layout Typedef */
typedef struct {
  __I  uint32_t BBNSM_VID;                         /**< BBNSM Version ID Register, offset: 0x0 */
  __I  uint32_t BBNSM_FEATURES;                    /**< BBNSM Features Register, offset: 0x4 */
  __IO uint32_t BBNSM_CTRL;                        /**< BBNSM Control Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t BBNSM_INT_EN;                      /**< BBNSM Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t BBNSM_EVENTS;                      /**< BBNSM Events Register, offset: 0x14 */
       uint8_t RESERVED_1[12];
  __IO uint32_t BBNSM_PAD_CTRL;                    /**< BBNSM External Pad Control Register, offset: 0x24 */
       uint8_t RESERVED_2[24];
  __IO uint32_t BBNSM_RTC_LS;                      /**< BBNSM Real-Time Counter LS Register, offset: 0x40 */
  __IO uint32_t BBNSM_RTC_MS;                      /**< BBNSM Real-Time Counter MS Register, offset: 0x44 */
       uint8_t RESERVED_3[8];
  __IO uint32_t BBNSM_TA;                          /**< BBNSM Time Alarm Register, offset: 0x50 */
       uint8_t RESERVED_4[684];
  __IO uint32_t GPR[BBNSM_GPR_ARRAY_COUNT];        /**< General Purpose Register Word 0..General Purpose Register Word 7, array offset: 0x300, array step: 0x4 */
} BBNSM_Type;

/* ----------------------------------------------------------------------------
   -- BBNSM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BBNSM_Register_Masks BBNSM Register Masks
 * @{
 */

/*! @name BBNSM_VID - BBNSM Version ID Register */
/*! @{ */

#define BBNSM_BBNSM_VID_BBNSM_IPID_MASK          (0xFFU)
#define BBNSM_BBNSM_VID_BBNSM_IPID_SHIFT         (0U)
/*! BBNSM_IPID - BBNSM IP ID */
#define BBNSM_BBNSM_VID_BBNSM_IPID(x)            (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_VID_BBNSM_IPID_SHIFT)) & BBNSM_BBNSM_VID_BBNSM_IPID_MASK)

#define BBNSM_BBNSM_VID_BBNSM_REV_MASK           (0xFF00U)
#define BBNSM_BBNSM_VID_BBNSM_REV_SHIFT          (8U)
/*! BBNSM_REV - BBNSM Revision */
#define BBNSM_BBNSM_VID_BBNSM_REV(x)             (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_VID_BBNSM_REV_SHIFT)) & BBNSM_BBNSM_VID_BBNSM_REV_MASK)

#define BBNSM_BBNSM_VID_BBNSM_VID_MASK           (0xFF0000U)
#define BBNSM_BBNSM_VID_BBNSM_VID_SHIFT          (16U)
/*! BBNSM_VID - BBNSM Version ID */
#define BBNSM_BBNSM_VID_BBNSM_VID(x)             (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_VID_BBNSM_VID_SHIFT)) & BBNSM_BBNSM_VID_BBNSM_VID_MASK)
/*! @} */

/*! @name BBNSM_FEATURES - BBNSM Features Register */
/*! @{ */

#define BBNSM_BBNSM_FEATURES_GPR_SZ_MASK         (0xFCU)
#define BBNSM_BBNSM_FEATURES_GPR_SZ_SHIFT        (2U)
/*! GPR_SZ - GPR Register Array Size
 *  0b000000..This version of BBNSM does not implement a general-purpose register array.
 *  *..The number of 32-bit words implemented in the general-purpose register array.
 */
#define BBNSM_BBNSM_FEATURES_GPR_SZ(x)           (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_FEATURES_GPR_SZ_SHIFT)) & BBNSM_BBNSM_FEATURES_GPR_SZ_MASK)
/*! @} */

/*! @name BBNSM_CTRL - BBNSM Control Register */
/*! @{ */

#define BBNSM_BBNSM_CTRL_RTC_EN_MASK             (0x3U)
#define BBNSM_BBNSM_CTRL_RTC_EN_SHIFT            (0U)
/*! RTC_EN - Real-Time Counter Enable
 *  0b01..Disable the real-time counter.
 *  0b10..Enable the real-time counter.
 */
#define BBNSM_BBNSM_CTRL_RTC_EN(x)               (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_RTC_EN_SHIFT)) & BBNSM_BBNSM_CTRL_RTC_EN_MASK)

#define BBNSM_BBNSM_CTRL_TA_EN_MASK              (0xCU)
#define BBNSM_BBNSM_CTRL_TA_EN_SHIFT             (2U)
/*! TA_EN - Time Alarm Enable
 *  0b01..Disable the time alarm.
 *  0b10..Enable the time alarm. A time alarm event occurs if the value in the real-time counter register is equal
 *        to the value in the time alarm register.
 */
#define BBNSM_BBNSM_CTRL_TA_EN(x)                (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_TA_EN_SHIFT)) & BBNSM_BBNSM_CTRL_TA_EN_MASK)

#define BBNSM_BBNSM_CTRL_CAL_EN_MASK             (0x10U)
#define BBNSM_BBNSM_CTRL_CAL_EN_SHIFT            (4U)
/*! CAL_EN - Calibration Enable
 *  0b0..RTC Time calibration is disabled.
 *  0b1..RTC Time calibration is enabled.
 */
#define BBNSM_BBNSM_CTRL_CAL_EN(x)               (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_CAL_EN_SHIFT)) & BBNSM_BBNSM_CTRL_CAL_EN_MASK)

#define BBNSM_BBNSM_CTRL_CAL_VAL_MASK            (0x1F00U)
#define BBNSM_BBNSM_CTRL_CAL_VAL_SHIFT           (8U)
/*! CAL_VAL - Calibration Value
 *  0b00000..+0 counts per each 32768 ticks of the counter clock.
 *  0b00001..+1 counts per each 32768 ticks of the counter clock.
 *  0b00010..+2 counts per each 32768 ticks of the counter clock.
 *  0b01111..+15 counts per each 32768 ticks of the counter clock.
 *  0b10000..-16 counts per each 32768 ticks of the counter clock.
 *  0b10001..-15 counts per each 32768 ticks of the counter clock.
 *  0b11110..-2 counts per each 32768 ticks of the counter clock.
 *  0b11111..-1 counts per each 32768 ticks of the counter clock.
 */
#define BBNSM_BBNSM_CTRL_CAL_VAL(x)              (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_CAL_VAL_SHIFT)) & BBNSM_BBNSM_CTRL_CAL_VAL_MASK)

#define BBNSM_BBNSM_CTRL_BTN_TIMEOUT_MASK        (0x30000U)
#define BBNSM_BBNSM_CTRL_BTN_TIMEOUT_SHIFT       (16U)
/*! BTN_TIMEOUT - Button Press Timeout
 *  0b00..5 seconds.
 *  0b01..10 seconds.
 *  0b10..15 seconds.
 *  0b11..Timeout disabled. Long button presses will not request a power down.
 */
#define BBNSM_BBNSM_CTRL_BTN_TIMEOUT(x)          (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_BTN_TIMEOUT_SHIFT)) & BBNSM_BBNSM_CTRL_BTN_TIMEOUT_MASK)

#define BBNSM_BBNSM_CTRL_DEBOUNCE_MASK           (0xC0000U)
#define BBNSM_BBNSM_CTRL_DEBOUNCE_SHIFT          (18U)
/*! DEBOUNCE - Debounce Time
 *  0b00..50 milliseconds.
 *  0b01..100 milliseconds.
 *  0b10..500 milliseconds.
 *  0b11..0 milliseconds.
 */
#define BBNSM_BBNSM_CTRL_DEBOUNCE(x)             (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_DEBOUNCE_SHIFT)) & BBNSM_BBNSM_CTRL_DEBOUNCE_MASK)

#define BBNSM_BBNSM_CTRL_TURN_ON_TIME_MASK       (0x300000U)
#define BBNSM_BBNSM_CTRL_TURN_ON_TIME_SHIFT      (20U)
/*! TURN_ON_TIME - Turn-On Time
 *  0b00..500 milliseconds.
 *  0b01..50 milliseconds.
 *  0b10..100 milliseconds.
 *  0b11..0 milliseconds.
 */
#define BBNSM_BBNSM_CTRL_TURN_ON_TIME(x)         (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_TURN_ON_TIME_SHIFT)) & BBNSM_BBNSM_CTRL_TURN_ON_TIME_MASK)

#define BBNSM_BBNSM_CTRL_PK_EN_MASK              (0x400000U)
#define BBNSM_BBNSM_CTRL_PK_EN_SHIFT             (22U)
/*! PK_EN - PMIC On Request Enable
 *  0b0..PMIC On Request is disabled.
 *  0b1..PMIC On Request is enabled.
 */
#define BBNSM_BBNSM_CTRL_PK_EN(x)                (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_PK_EN_SHIFT)) & BBNSM_BBNSM_CTRL_PK_EN_MASK)

#define BBNSM_BBNSM_CTRL_PK_OVR_MASK             (0x800000U)
#define BBNSM_BBNSM_CTRL_PK_OVR_SHIFT            (23U)
/*! PK_OVR - PMIC On Request Override
 *  0b0..PMIC On Request Override is disabled.
 *  0b1..PMIC On Request Override is enabled.
 */
#define BBNSM_BBNSM_CTRL_PK_OVR(x)               (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_PK_OVR_SHIFT)) & BBNSM_BBNSM_CTRL_PK_OVR_MASK)

#define BBNSM_BBNSM_CTRL_DP_EN_MASK              (0x1000000U)
#define BBNSM_BBNSM_CTRL_DP_EN_SHIFT             (24U)
/*! DP_EN - Dumb PMIC Enable
 *  0b0..Smart PMIC is enabled.
 *  0b1..Dumb PMIC is enabled.
 */
#define BBNSM_BBNSM_CTRL_DP_EN(x)                (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_DP_EN_SHIFT)) & BBNSM_BBNSM_CTRL_DP_EN_MASK)

#define BBNSM_BBNSM_CTRL_TOSP_MASK               (0x2000000U)
#define BBNSM_BBNSM_CTRL_TOSP_SHIFT              (25U)
/*! TOSP - Turn Off System Power
 *  0b0..Leave system power on.
 *  0b1..Turn off system power when Dumb PMIC is enabled.
 */
#define BBNSM_BBNSM_CTRL_TOSP(x)                 (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_CTRL_TOSP_SHIFT)) & BBNSM_BBNSM_CTRL_TOSP_MASK)
/*! @} */

/*! @name BBNSM_INT_EN - BBNSM Interrupt Enable Register */
/*! @{ */

#define BBNSM_BBNSM_INT_EN_RTC_INT_EN_MASK       (0x3U)
#define BBNSM_BBNSM_INT_EN_RTC_INT_EN_SHIFT      (0U)
/*! RTC_INT_EN - Real-Time Counter Rollover Interrupt Enable
 *  0b01..Do not issue an interrupt when RTC has rolled over. The interrupt is cleared when this value is written.
 *  0b10..Issue an interrupt when RTC has rolled over.
 */
#define BBNSM_BBNSM_INT_EN_RTC_INT_EN(x)         (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_INT_EN_RTC_INT_EN_SHIFT)) & BBNSM_BBNSM_INT_EN_RTC_INT_EN_MASK)

#define BBNSM_BBNSM_INT_EN_TA_INT_EN_MASK        (0xCU)
#define BBNSM_BBNSM_INT_EN_TA_INT_EN_SHIFT       (2U)
/*! TA_INT_EN - Time Alarm Interrupt Enable
 *  0b01..Do not issue an interrupt when RTC has reached alarm time. The interrupt is cleared when this value is written.
 *  0b10..Issue an interrupt when RTC has reached alarm time.
 */
#define BBNSM_BBNSM_INT_EN_TA_INT_EN(x)          (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_INT_EN_TA_INT_EN_SHIFT)) & BBNSM_BBNSM_INT_EN_TA_INT_EN_MASK)
/*! @} */

/*! @name BBNSM_EVENTS - BBNSM Events Register */
/*! @{ */

#define BBNSM_BBNSM_EVENTS_RTC_ROLL_MASK         (0x3U)
#define BBNSM_BBNSM_EVENTS_RTC_ROLL_SHIFT        (0U)
/*! RTC_ROLL - Real-Time Counter Rollover Event
 *  0b01..The real-time counter has not rolled over.
 *  0b10..The real-time counter has rolled over.
 */
#define BBNSM_BBNSM_EVENTS_RTC_ROLL(x)           (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_EVENTS_RTC_ROLL_SHIFT)) & BBNSM_BBNSM_EVENTS_RTC_ROLL_MASK)

#define BBNSM_BBNSM_EVENTS_TA_MASK               (0xCU)
#define BBNSM_BBNSM_EVENTS_TA_SHIFT              (2U)
/*! TA - Time Alarm Event
 *  0b01..The real-time counter has not reached the alarm time.
 *  0b10..The real-time counter has reached the alarm time.
 */
#define BBNSM_BBNSM_EVENTS_TA(x)                 (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_EVENTS_TA_SHIFT)) & BBNSM_BBNSM_EVENTS_TA_MASK)

#define BBNSM_BBNSM_EVENTS_EMG_OFF_MASK          (0x10U)
#define BBNSM_BBNSM_EVENTS_EMG_OFF_SHIFT         (4U)
/*! EMG_OFF - Emergency Off Event
 *  0b0..An emergency power off has not been requested.
 *  0b1..An emergency power off has been requested.
 */
#define BBNSM_BBNSM_EVENTS_EMG_OFF(x)            (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_EVENTS_EMG_OFF_SHIFT)) & BBNSM_BBNSM_EVENTS_EMG_OFF_MASK)

#define BBNSM_BBNSM_EVENTS_PWR_OFF_MASK          (0x20U)
#define BBNSM_BBNSM_EVENTS_PWR_OFF_SHIFT         (5U)
/*! PWR_OFF - Set Power Off Event
 *  0b0..The power off interrupt has not been requested.
 *  0b1..The power off interrupt has been requested.
 */
#define BBNSM_BBNSM_EVENTS_PWR_OFF(x)            (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_EVENTS_PWR_OFF_SHIFT)) & BBNSM_BBNSM_EVENTS_PWR_OFF_MASK)

#define BBNSM_BBNSM_EVENTS_PWR_ON_MASK           (0x40U)
#define BBNSM_BBNSM_EVENTS_PWR_ON_SHIFT          (6U)
/*! PWR_ON - Set Power On Event
 *  0b0..The power on interrupt has not been requested.
 *  0b1..The power on interrupt has been requested.
 */
#define BBNSM_BBNSM_EVENTS_PWR_ON(x)             (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_EVENTS_PWR_ON_SHIFT)) & BBNSM_BBNSM_EVENTS_PWR_ON_MASK)

#define BBNSM_BBNSM_EVENTS_BTN_MASK              (0x80U)
#define BBNSM_BBNSM_EVENTS_BTN_SHIFT             (7U)
/*! BTN - Button
 *  0b0..BTN not pressed
 *  0b1..BTN pressed
 */
#define BBNSM_BBNSM_EVENTS_BTN(x)                (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_EVENTS_BTN_SHIFT)) & BBNSM_BBNSM_EVENTS_BTN_MASK)
/*! @} */

/*! @name BBNSM_PAD_CTRL - BBNSM External Pad Control Register */
/*! @{ */

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL0_MASK      (0x1U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL0_SHIFT     (0U)
/*! PAD_CTRL0 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL0(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL0_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL0_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL1_MASK      (0x2U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL1_SHIFT     (1U)
/*! PAD_CTRL1 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL1(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL1_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL1_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL2_MASK      (0x4U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL2_SHIFT     (2U)
/*! PAD_CTRL2 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL2(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL2_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL2_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL3_MASK      (0x8U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL3_SHIFT     (3U)
/*! PAD_CTRL3 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL3(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL3_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL3_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL4_MASK      (0x10U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL4_SHIFT     (4U)
/*! PAD_CTRL4 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL4(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL4_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL4_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL5_MASK      (0x20U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL5_SHIFT     (5U)
/*! PAD_CTRL5 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL5(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL5_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL5_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL6_MASK      (0x40U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL6_SHIFT     (6U)
/*! PAD_CTRL6 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL6(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL6_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL6_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL7_MASK      (0x80U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL7_SHIFT     (7U)
/*! PAD_CTRL7 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL7(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL7_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL7_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL8_MASK      (0x100U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL8_SHIFT     (8U)
/*! PAD_CTRL8 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL8(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL8_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL8_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL9_MASK      (0x200U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL9_SHIFT     (9U)
/*! PAD_CTRL9 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL9(x)        (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL9_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL9_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL10_MASK     (0x400U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL10_SHIFT    (10U)
/*! PAD_CTRL10 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL10(x)       (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL10_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL10_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL11_MASK     (0x800U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL11_SHIFT    (11U)
/*! PAD_CTRL11 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL11(x)       (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL11_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL11_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL12_MASK     (0x1000U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL12_SHIFT    (12U)
/*! PAD_CTRL12 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL12(x)       (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL12_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL12_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL13_MASK     (0x2000U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL13_SHIFT    (13U)
/*! PAD_CTRL13 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL13(x)       (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL13_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL13_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL14_MASK     (0x4000U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL14_SHIFT    (14U)
/*! PAD_CTRL14 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL14(x)       (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL14_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL14_MASK)

#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL15_MASK     (0x8000U)
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL15_SHIFT    (15U)
/*! PAD_CTRL15 - Control I/O Pads
 *  0b0..Deasserts bit n in bbnsm_pad_ctrl[n]
 *  0b1..Assert bit n in bbnsm_pad_ctrl[n]
 */
#define BBNSM_BBNSM_PAD_CTRL_PAD_CTRL15(x)       (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_PAD_CTRL_PAD_CTRL15_SHIFT)) & BBNSM_BBNSM_PAD_CTRL_PAD_CTRL15_MASK)
/*! @} */

/*! @name BBNSM_RTC_LS - BBNSM Real-Time Counter LS Register */
/*! @{ */

#define BBNSM_BBNSM_RTC_LS_RTC_MASK              (0xFFFFFFFFU)
#define BBNSM_BBNSM_RTC_LS_RTC_SHIFT             (0U)
/*! RTC - Real-time Counter */
#define BBNSM_BBNSM_RTC_LS_RTC(x)                (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_RTC_LS_RTC_SHIFT)) & BBNSM_BBNSM_RTC_LS_RTC_MASK)
/*! @} */

/*! @name BBNSM_RTC_MS - BBNSM Real-Time Counter MS Register */
/*! @{ */

#define BBNSM_BBNSM_RTC_MS_RTC_MASK              (0x7FFFU)
#define BBNSM_BBNSM_RTC_MS_RTC_SHIFT             (0U)
/*! RTC - Real-Time Counter */
#define BBNSM_BBNSM_RTC_MS_RTC(x)                (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_RTC_MS_RTC_SHIFT)) & BBNSM_BBNSM_RTC_MS_RTC_MASK)
/*! @} */

/*! @name BBNSM_TA - BBNSM Time Alarm Register */
/*! @{ */

#define BBNSM_BBNSM_TA_TA_MASK                   (0xFFFFFFFFU)
#define BBNSM_BBNSM_TA_TA_SHIFT                  (0U)
/*! TA - Time Alarm Value */
#define BBNSM_BBNSM_TA_TA(x)                     (((uint32_t)(((uint32_t)(x)) << BBNSM_BBNSM_TA_TA_SHIFT)) & BBNSM_BBNSM_TA_TA_MASK)
/*! @} */

/*! @name GPR - General Purpose Register Word 0..General Purpose Register Word 7 */
/*! @{ */

#define BBNSM_GPR_GPR_MASK                       (0xFFFFFFFFU)
#define BBNSM_GPR_GPR_SHIFT                      (0U)
/*! GPR - 32 bits of the GPR. */
#define BBNSM_GPR_GPR(x)                         (((uint32_t)(((uint32_t)(x)) << BBNSM_GPR_GPR_SHIFT)) & BBNSM_GPR_GPR_MASK)
/*! @} */

/* The count of BBNSM_GPR */
#define BBNSM_GPR_COUNT                          (8U)


/*!
 * @}
 */ /* end of group BBNSM_Register_Masks */


/*!
 * @}
 */ /* end of group BBNSM_Peripheral_Access_Layer */


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


#endif  /* PERI_BBNSM_H_ */
