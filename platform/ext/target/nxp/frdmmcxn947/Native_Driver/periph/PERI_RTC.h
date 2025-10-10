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
**         CMSIS Peripheral Access Layer for RTC
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
 * @file PERI_RTC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint16_t YEARMON;                           /**< Year and Month Counters, offset: 0x0 */
  __IO uint16_t DAYS;                              /**< Days and Day-of-Week Counters, offset: 0x2 */
  __IO uint16_t HOURMIN;                           /**< Hours and Minutes Counters, offset: 0x4 */
  __IO uint16_t SECONDS;                           /**< Seconds Counters, offset: 0x6 */
  __IO uint16_t ALM_YEARMON;                       /**< Year and Months Alarm, offset: 0x8 */
  __IO uint16_t ALM_DAYS;                          /**< Days Alarm, offset: 0xA */
  __IO uint16_t ALM_HOURMIN;                       /**< Hours and Minutes Alarm, offset: 0xC */
  __IO uint16_t ALM_SECONDS;                       /**< Seconds Alarm, offset: 0xE */
  __IO uint16_t CTRL;                              /**< Control, offset: 0x10 */
  __IO uint16_t STATUS;                            /**< Status, offset: 0x12 */
  __IO uint16_t ISR;                               /**< Interrupt Status, offset: 0x14 */
  __IO uint16_t IER;                               /**< Interrupt Enable, offset: 0x16 */
       uint8_t RESERVED_0[4];
  __I  uint16_t RTC_TEST2;                         /**< Sub Second Counter, offset: 0x1C */
       uint8_t RESERVED_1[4];
  __IO uint16_t DST_HOUR;                          /**< Daylight Saving Hour, offset: 0x22 */
  __IO uint16_t DST_MONTH;                         /**< Daylight Saving Month, offset: 0x24 */
  __IO uint16_t DST_DAY;                           /**< Daylight Saving Day, offset: 0x26 */
  __IO uint16_t COMPEN;                            /**< Compensation, offset: 0x28 */
       uint8_t RESERVED_2[2006];
  __IO uint32_t SUBSECOND_CTRL;                    /**< Subsecond Control, offset: 0x800 */
  __I  uint32_t SUBSECOND_CNT;                     /**< Subsecond Counter, offset: 0x804 */
       uint8_t RESERVED_3[1016];
  __IO uint32_t WAKE_TIMER_CTRL;                   /**< Wake Timer Control, offset: 0xC00 */
       uint8_t RESERVED_4[8];
  __IO uint32_t WAKE_TIMER_CNT;                    /**< Wake Timer Counter, offset: 0xC0C */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name YEARMON - Year and Month Counters */
/*! @{ */

#define RTC_YEARMON_MON_CNT_MASK                 (0xFU)
#define RTC_YEARMON_MON_CNT_SHIFT                (0U)
/*! MON_CNT - Month Counter
 *  0b0000, 0b1101, 0b1110, 0b1111..Illegal Value
 *  0b0001..January
 *  0b0010..February
 *  0b0011..March
 *  0b0100..April
 *  0b0101..May
 *  0b0110..June
 *  0b0111..July
 *  0b1000..August
 *  0b1001..September
 *  0b1010..October
 *  0b1011..November
 *  0b1100..December
 */
#define RTC_YEARMON_MON_CNT(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_YEARMON_MON_CNT_SHIFT)) & RTC_YEARMON_MON_CNT_MASK)

#define RTC_YEARMON_YROFST_MASK                  (0xFF00U)
#define RTC_YEARMON_YROFST_SHIFT                 (8U)
/*! YROFST - Year Offset Count Value */
#define RTC_YEARMON_YROFST(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_YEARMON_YROFST_SHIFT)) & RTC_YEARMON_YROFST_MASK)
/*! @} */

/*! @name DAYS - Days and Day-of-Week Counters */
/*! @{ */

#define RTC_DAYS_DAY_CNT_MASK                    (0x1FU)
#define RTC_DAYS_DAY_CNT_SHIFT                   (0U)
/*! DAY_CNT - Days Counter Value */
#define RTC_DAYS_DAY_CNT(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_DAYS_DAY_CNT_SHIFT)) & RTC_DAYS_DAY_CNT_MASK)

#define RTC_DAYS_DOW_MASK                        (0x700U)
#define RTC_DAYS_DOW_SHIFT                       (8U)
/*! DOW - Day of Week Counter Value
 *  0b000..Sunday
 *  0b001..Monday
 *  0b010..Tuesday
 *  0b011..Wednesday
 *  0b100..Thursday
 *  0b101..Friday
 *  0b110..Saturday
 *  0b111..
 */
#define RTC_DAYS_DOW(x)                          (((uint16_t)(((uint16_t)(x)) << RTC_DAYS_DOW_SHIFT)) & RTC_DAYS_DOW_MASK)
/*! @} */

/*! @name HOURMIN - Hours and Minutes Counters */
/*! @{ */

#define RTC_HOURMIN_MIN_CNT_MASK                 (0x3FU)
#define RTC_HOURMIN_MIN_CNT_SHIFT                (0U)
/*! MIN_CNT - Minutes Counter Value */
#define RTC_HOURMIN_MIN_CNT(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_HOURMIN_MIN_CNT_SHIFT)) & RTC_HOURMIN_MIN_CNT_MASK)

#define RTC_HOURMIN_HOUR_CNT_MASK                (0x1F00U)
#define RTC_HOURMIN_HOUR_CNT_SHIFT               (8U)
/*! HOUR_CNT - Hours Counter Value */
#define RTC_HOURMIN_HOUR_CNT(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_HOURMIN_HOUR_CNT_SHIFT)) & RTC_HOURMIN_HOUR_CNT_MASK)
/*! @} */

/*! @name SECONDS - Seconds Counters */
/*! @{ */

#define RTC_SECONDS_SEC_CNT_MASK                 (0x3FU)
#define RTC_SECONDS_SEC_CNT_SHIFT                (0U)
/*! SEC_CNT - Seconds Counter Value */
#define RTC_SECONDS_SEC_CNT(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_SECONDS_SEC_CNT_SHIFT)) & RTC_SECONDS_SEC_CNT_MASK)
/*! @} */

/*! @name ALM_YEARMON - Year and Months Alarm */
/*! @{ */

#define RTC_ALM_YEARMON_ALM_MON_MASK             (0xFU)
#define RTC_ALM_YEARMON_ALM_MON_SHIFT            (0U)
/*! ALM_MON - Months Value for Alarm */
#define RTC_ALM_YEARMON_ALM_MON(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_YEARMON_ALM_MON_SHIFT)) & RTC_ALM_YEARMON_ALM_MON_MASK)

#define RTC_ALM_YEARMON_ALM_YEAR_MASK            (0xFF00U)
#define RTC_ALM_YEARMON_ALM_YEAR_SHIFT           (8U)
/*! ALM_YEAR - Year Value for Alarm */
#define RTC_ALM_YEARMON_ALM_YEAR(x)              (((uint16_t)(((uint16_t)(x)) << RTC_ALM_YEARMON_ALM_YEAR_SHIFT)) & RTC_ALM_YEARMON_ALM_YEAR_MASK)
/*! @} */

/*! @name ALM_DAYS - Days Alarm */
/*! @{ */

#define RTC_ALM_DAYS_ALM_DAY_MASK                (0x1FU)
#define RTC_ALM_DAYS_ALM_DAY_SHIFT               (0U)
/*! ALM_DAY - Days Value for Alarm */
#define RTC_ALM_DAYS_ALM_DAY(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_ALM_DAYS_ALM_DAY_SHIFT)) & RTC_ALM_DAYS_ALM_DAY_MASK)
/*! @} */

/*! @name ALM_HOURMIN - Hours and Minutes Alarm */
/*! @{ */

#define RTC_ALM_HOURMIN_ALM_MIN_MASK             (0x3FU)
#define RTC_ALM_HOURMIN_ALM_MIN_SHIFT            (0U)
/*! ALM_MIN - Minutes Value for Alarm */
#define RTC_ALM_HOURMIN_ALM_MIN(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_HOURMIN_ALM_MIN_SHIFT)) & RTC_ALM_HOURMIN_ALM_MIN_MASK)

#define RTC_ALM_HOURMIN_ALM_HOUR_MASK            (0x1F00U)
#define RTC_ALM_HOURMIN_ALM_HOUR_SHIFT           (8U)
/*! ALM_HOUR - Hours Value for Alarm */
#define RTC_ALM_HOURMIN_ALM_HOUR(x)              (((uint16_t)(((uint16_t)(x)) << RTC_ALM_HOURMIN_ALM_HOUR_SHIFT)) & RTC_ALM_HOURMIN_ALM_HOUR_MASK)
/*! @} */

/*! @name ALM_SECONDS - Seconds Alarm */
/*! @{ */

#define RTC_ALM_SECONDS_ALM_SEC_MASK             (0x3FU)
#define RTC_ALM_SECONDS_ALM_SEC_SHIFT            (0U)
/*! ALM_SEC - Seconds Alarm Value */
#define RTC_ALM_SECONDS_ALM_SEC(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_SECONDS_ALM_SEC_SHIFT)) & RTC_ALM_SECONDS_ALM_SEC_MASK)

#define RTC_ALM_SECONDS_DEC_SEC_MASK             (0x100U)
#define RTC_ALM_SECONDS_DEC_SEC_SHIFT            (8U)
/*! DEC_SEC - Decrement Seconds Counter by 1. */
#define RTC_ALM_SECONDS_DEC_SEC(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_SECONDS_DEC_SEC_SHIFT)) & RTC_ALM_SECONDS_DEC_SEC_MASK)

#define RTC_ALM_SECONDS_INC_SEC_MASK             (0x200U)
#define RTC_ALM_SECONDS_INC_SEC_SHIFT            (9U)
/*! INC_SEC - Increment Seconds Counter by 1. */
#define RTC_ALM_SECONDS_INC_SEC(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_SECONDS_INC_SEC_SHIFT)) & RTC_ALM_SECONDS_INC_SEC_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define RTC_CTRL_FINEEN_MASK                     (0x1U)
#define RTC_CTRL_FINEEN_SHIFT                    (0U)
/*! FINEEN - Fine Compensation Enable
 *  0b0..Fine compensation is disabled
 *  0b1..Fine compensation is enabled.
 */
#define RTC_CTRL_FINEEN(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_FINEEN_SHIFT)) & RTC_CTRL_FINEEN_MASK)

#define RTC_CTRL_COMP_EN_MASK                    (0x2U)
#define RTC_CTRL_COMP_EN_SHIFT                   (1U)
/*! COMP_EN - Compensation Enable
 *  0b0..Coarse compensation is disabled.
 *  0b1..Coarse compensation is enabled.
 */
#define RTC_CTRL_COMP_EN(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_COMP_EN_SHIFT)) & RTC_CTRL_COMP_EN_MASK)

#define RTC_CTRL_ALM_MATCH_MASK                  (0xCU)
#define RTC_CTRL_ALM_MATCH_SHIFT                 (2U)
/*! ALM_MATCH - Alarm Match
 *  0b00..Only seconds, minutes, and hours matched.
 *  0b01..Only seconds, minutes, hours, and days matched.
 *  0b10..Only seconds, minutes, hours, days, and months matched.
 *  0b11..Only seconds, minutes, hours, days, months, and year (offset) matched.
 */
#define RTC_CTRL_ALM_MATCH(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_ALM_MATCH_SHIFT)) & RTC_CTRL_ALM_MATCH_MASK)

#define RTC_CTRL_DST_EN_MASK                     (0x40U)
#define RTC_CTRL_DST_EN_SHIFT                    (6U)
/*! DST_EN - Daylight Saving Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define RTC_CTRL_DST_EN(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_DST_EN_SHIFT)) & RTC_CTRL_DST_EN_MASK)

#define RTC_CTRL_SWR_MASK                        (0x100U)
#define RTC_CTRL_SWR_SHIFT                       (8U)
/*! SWR - Software Reset
 *  0b0..Software Reset cleared
 *  0b1..Software Reset asserted
 */
#define RTC_CTRL_SWR(x)                          (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_SWR_SHIFT)) & RTC_CTRL_SWR_MASK)

#define RTC_CTRL_CLK_SEL_MASK                    (0x200U)
#define RTC_CTRL_CLK_SEL_SHIFT                   (9U)
/*! CLK_SEL - RTC Clock Select
 *  0b0..16.384 kHz clock is selected
 *  0b1..32.768 kHz clock is selected
 */
#define RTC_CTRL_CLK_SEL(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_CLK_SEL_SHIFT)) & RTC_CTRL_CLK_SEL_MASK)

#define RTC_CTRL_CLKO_DIS_MASK                   (0x400U)
#define RTC_CTRL_CLKO_DIS_SHIFT                  (10U)
/*! CLKO_DIS - Clock Output Disable
 *  0b0..The selected clock is output to other peripherals.
 *  0b1..The selected clock is not output to other peripherals.
 */
#define RTC_CTRL_CLKO_DIS(x)                     (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_CLKO_DIS_SHIFT)) & RTC_CTRL_CLKO_DIS_MASK)

#define RTC_CTRL_CLKOUT_MASK                     (0x6000U)
#define RTC_CTRL_CLKOUT_SHIFT                    (13U)
/*! CLKOUT - RTC Clock Output Selection
 *  0b00..No output clock
 *  0b01..Fine 1 Hz clock with both precise edges
 *  0b10..32.768 or 16.384 kHz clock
 *  0b11..Coarse 1 Hz clock with both precise edges
 */
#define RTC_CTRL_CLKOUT(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_CLKOUT_SHIFT)) & RTC_CTRL_CLKOUT_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define RTC_STATUS_INVAL_BIT_MASK                (0x1U)
#define RTC_STATUS_INVAL_BIT_SHIFT               (0U)
/*! INVAL_BIT - Invalidate CPU Read/Write Access
 *  0b0..Time and date counters can be read or written. Time and date is valid.
 *  0b1..Time and date counter values are changing or time and date is invalid and cannot be read or written.
 */
#define RTC_STATUS_INVAL_BIT(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_INVAL_BIT_SHIFT)) & RTC_STATUS_INVAL_BIT_MASK)

#define RTC_STATUS_WRITE_PROT_EN_MASK            (0x2U)
#define RTC_STATUS_WRITE_PROT_EN_SHIFT           (1U)
/*! WRITE_PROT_EN - Write Protect Enable Status
 *  0b0..Registers are unlocked and can be accessed.
 *  0b1..Registers are locked and in read-only mode.
 */
#define RTC_STATUS_WRITE_PROT_EN(x)              (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_WRITE_PROT_EN_SHIFT)) & RTC_STATUS_WRITE_PROT_EN_MASK)

#define RTC_STATUS_CMP_INT_MASK                  (0x20U)
#define RTC_STATUS_CMP_INT_SHIFT                 (5U)
/*! CMP_INT - Compensation Interval */
#define RTC_STATUS_CMP_INT(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_CMP_INT_SHIFT)) & RTC_STATUS_CMP_INT_MASK)

#define RTC_STATUS_WE_MASK                       (0xC0U)
#define RTC_STATUS_WE_SHIFT                      (6U)
/*! WE - Write Enable
 *  0b10..Enable Write Protection - Registers are locked.
 */
#define RTC_STATUS_WE(x)                         (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_WE_SHIFT)) & RTC_STATUS_WE_MASK)

#define RTC_STATUS_BUS_ERR_MASK                  (0x100U)
#define RTC_STATUS_BUS_ERR_SHIFT                 (8U)
/*! BUS_ERR - Bus Error
 *  0b0..Read and write accesses are normal.
 *  0b1..Read or write accesses occurred when STATUS[INVAL_BIT] was asserted.
 */
#define RTC_STATUS_BUS_ERR(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_BUS_ERR_SHIFT)) & RTC_STATUS_BUS_ERR_MASK)

#define RTC_STATUS_CMP_DONE_MASK                 (0x800U)
#define RTC_STATUS_CMP_DONE_SHIFT                (11U)
/*! CMP_DONE - Compensation Done
 *  0b0..Compensation busy or not enabled
 *  0b1..Compensation completed
 */
#define RTC_STATUS_CMP_DONE(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_CMP_DONE_SHIFT)) & RTC_STATUS_CMP_DONE_MASK)
/*! @} */

/*! @name ISR - Interrupt Status */
/*! @{ */

#define RTC_ISR_ALM_IS_MASK                      (0x4U)
#define RTC_ISR_ALM_IS_SHIFT                     (2U)
/*! ALM_IS - Alarm Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_ALM_IS(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_ALM_IS_SHIFT)) & RTC_ISR_ALM_IS_MASK)

#define RTC_ISR_DAY_IS_MASK                      (0x8U)
#define RTC_ISR_DAY_IS_SHIFT                     (3U)
/*! DAY_IS - Days Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_DAY_IS(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_DAY_IS_SHIFT)) & RTC_ISR_DAY_IS_MASK)

#define RTC_ISR_HOUR_IS_MASK                     (0x10U)
#define RTC_ISR_HOUR_IS_SHIFT                    (4U)
/*! HOUR_IS - Hours Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_HOUR_IS(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_HOUR_IS_SHIFT)) & RTC_ISR_HOUR_IS_MASK)

#define RTC_ISR_MIN_IS_MASK                      (0x20U)
#define RTC_ISR_MIN_IS_SHIFT                     (5U)
/*! MIN_IS - Minutes Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_MIN_IS(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_MIN_IS_SHIFT)) & RTC_ISR_MIN_IS_MASK)

#define RTC_ISR_IS_1HZ_MASK                      (0x40U)
#define RTC_ISR_IS_1HZ_SHIFT                     (6U)
/*! IS_1HZ - 1 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_1HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_1HZ_SHIFT)) & RTC_ISR_IS_1HZ_MASK)

#define RTC_ISR_IS_2HZ_MASK                      (0x80U)
#define RTC_ISR_IS_2HZ_SHIFT                     (7U)
/*! IS_2HZ - 2 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_2HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_2HZ_SHIFT)) & RTC_ISR_IS_2HZ_MASK)

#define RTC_ISR_IS_4HZ_MASK                      (0x100U)
#define RTC_ISR_IS_4HZ_SHIFT                     (8U)
/*! IS_4HZ - 4 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_4HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_4HZ_SHIFT)) & RTC_ISR_IS_4HZ_MASK)

#define RTC_ISR_IS_8HZ_MASK                      (0x200U)
#define RTC_ISR_IS_8HZ_SHIFT                     (9U)
/*! IS_8HZ - 8 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_8HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_8HZ_SHIFT)) & RTC_ISR_IS_8HZ_MASK)

#define RTC_ISR_IS_16HZ_MASK                     (0x400U)
#define RTC_ISR_IS_16HZ_SHIFT                    (10U)
/*! IS_16HZ - 16 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_16HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_16HZ_SHIFT)) & RTC_ISR_IS_16HZ_MASK)

#define RTC_ISR_IS_32HZ_MASK                     (0x800U)
#define RTC_ISR_IS_32HZ_SHIFT                    (11U)
/*! IS_32HZ - 32 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_32HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_32HZ_SHIFT)) & RTC_ISR_IS_32HZ_MASK)

#define RTC_ISR_IS_64HZ_MASK                     (0x1000U)
#define RTC_ISR_IS_64HZ_SHIFT                    (12U)
/*! IS_64HZ - 64 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_64HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_64HZ_SHIFT)) & RTC_ISR_IS_64HZ_MASK)

#define RTC_ISR_IS_128HZ_MASK                    (0x2000U)
#define RTC_ISR_IS_128HZ_SHIFT                   (13U)
/*! IS_128HZ - 128 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_128HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_128HZ_SHIFT)) & RTC_ISR_IS_128HZ_MASK)

#define RTC_ISR_IS_256HZ_MASK                    (0x4000U)
#define RTC_ISR_IS_256HZ_SHIFT                   (14U)
/*! IS_256HZ - 256 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_256HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_256HZ_SHIFT)) & RTC_ISR_IS_256HZ_MASK)

#define RTC_ISR_IS_512HZ_MASK                    (0x8000U)
#define RTC_ISR_IS_512HZ_SHIFT                   (15U)
/*! IS_512HZ - 512 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_512HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_512HZ_SHIFT)) & RTC_ISR_IS_512HZ_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define RTC_IER_ALM_IE_MASK                      (0x4U)
#define RTC_IER_ALM_IE_SHIFT                     (2U)
/*! ALM_IE - Alarm Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_ALM_IE(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_ALM_IE_SHIFT)) & RTC_IER_ALM_IE_MASK)

#define RTC_IER_DAY_IE_MASK                      (0x8U)
#define RTC_IER_DAY_IE_SHIFT                     (3U)
/*! DAY_IE - Days Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_DAY_IE(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_DAY_IE_SHIFT)) & RTC_IER_DAY_IE_MASK)

#define RTC_IER_HOUR_IE_MASK                     (0x10U)
#define RTC_IER_HOUR_IE_SHIFT                    (4U)
/*! HOUR_IE - Hours Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_HOUR_IE(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_HOUR_IE_SHIFT)) & RTC_IER_HOUR_IE_MASK)

#define RTC_IER_MIN_IE_MASK                      (0x20U)
#define RTC_IER_MIN_IE_SHIFT                     (5U)
/*! MIN_IE - Minutes Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_MIN_IE(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_MIN_IE_SHIFT)) & RTC_IER_MIN_IE_MASK)

#define RTC_IER_IE_1HZ_MASK                      (0x40U)
#define RTC_IER_IE_1HZ_SHIFT                     (6U)
/*! IE_1HZ - 1 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_1HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_1HZ_SHIFT)) & RTC_IER_IE_1HZ_MASK)

#define RTC_IER_IE_2HZ_MASK                      (0x80U)
#define RTC_IER_IE_2HZ_SHIFT                     (7U)
/*! IE_2HZ - 2 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_2HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_2HZ_SHIFT)) & RTC_IER_IE_2HZ_MASK)

#define RTC_IER_IE_4HZ_MASK                      (0x100U)
#define RTC_IER_IE_4HZ_SHIFT                     (8U)
/*! IE_4HZ - 4 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_4HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_4HZ_SHIFT)) & RTC_IER_IE_4HZ_MASK)

#define RTC_IER_IE_8HZ_MASK                      (0x200U)
#define RTC_IER_IE_8HZ_SHIFT                     (9U)
/*! IE_8HZ - 8 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_8HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_8HZ_SHIFT)) & RTC_IER_IE_8HZ_MASK)

#define RTC_IER_IE_16HZ_MASK                     (0x400U)
#define RTC_IER_IE_16HZ_SHIFT                    (10U)
/*! IE_16HZ - 16 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_16HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_16HZ_SHIFT)) & RTC_IER_IE_16HZ_MASK)

#define RTC_IER_IE_32HZ_MASK                     (0x800U)
#define RTC_IER_IE_32HZ_SHIFT                    (11U)
/*! IE_32HZ - 32 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_32HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_32HZ_SHIFT)) & RTC_IER_IE_32HZ_MASK)

#define RTC_IER_IE_64HZ_MASK                     (0x1000U)
#define RTC_IER_IE_64HZ_SHIFT                    (12U)
/*! IE_64HZ - 64 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_64HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_64HZ_SHIFT)) & RTC_IER_IE_64HZ_MASK)

#define RTC_IER_IE_128HZ_MASK                    (0x2000U)
#define RTC_IER_IE_128HZ_SHIFT                   (13U)
/*! IE_128HZ - 128 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_128HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_128HZ_SHIFT)) & RTC_IER_IE_128HZ_MASK)

#define RTC_IER_IE_256HZ_MASK                    (0x4000U)
#define RTC_IER_IE_256HZ_SHIFT                   (14U)
/*! IE_256HZ - 256 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_256HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_256HZ_SHIFT)) & RTC_IER_IE_256HZ_MASK)

#define RTC_IER_IE_512HZ_MASK                    (0x8000U)
#define RTC_IER_IE_512HZ_SHIFT                   (15U)
/*! IE_512HZ - 512 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_512HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_512HZ_SHIFT)) & RTC_IER_IE_512HZ_MASK)
/*! @} */

/*! @name RTC_TEST2 - Sub Second Counter */
/*! @{ */

#define RTC_RTC_TEST2_SUB_SECOND_COUNT_MASK      (0xFFFFU)
#define RTC_RTC_TEST2_SUB_SECOND_COUNT_SHIFT     (0U)
/*! SUB_SECOND_COUNT - Sub Second Counter Value */
#define RTC_RTC_TEST2_SUB_SECOND_COUNT(x)        (((uint16_t)(((uint16_t)(x)) << RTC_RTC_TEST2_SUB_SECOND_COUNT_SHIFT)) & RTC_RTC_TEST2_SUB_SECOND_COUNT_MASK)
/*! @} */

/*! @name DST_HOUR - Daylight Saving Hour */
/*! @{ */

#define RTC_DST_HOUR_DST_END_HOUR_MASK           (0x1FU)
#define RTC_DST_HOUR_DST_END_HOUR_SHIFT          (0U)
/*! DST_END_HOUR - Daylight Saving Time (DST) Hours End Value */
#define RTC_DST_HOUR_DST_END_HOUR(x)             (((uint16_t)(((uint16_t)(x)) << RTC_DST_HOUR_DST_END_HOUR_SHIFT)) & RTC_DST_HOUR_DST_END_HOUR_MASK)

#define RTC_DST_HOUR_DST_START_HOUR_MASK         (0x1F00U)
#define RTC_DST_HOUR_DST_START_HOUR_SHIFT        (8U)
/*! DST_START_HOUR - Daylight Saving Time (DST) Hours Start Value */
#define RTC_DST_HOUR_DST_START_HOUR(x)           (((uint16_t)(((uint16_t)(x)) << RTC_DST_HOUR_DST_START_HOUR_SHIFT)) & RTC_DST_HOUR_DST_START_HOUR_MASK)
/*! @} */

/*! @name DST_MONTH - Daylight Saving Month */
/*! @{ */

#define RTC_DST_MONTH_DST_END_MONTH_MASK         (0xFU)
#define RTC_DST_MONTH_DST_END_MONTH_SHIFT        (0U)
/*! DST_END_MONTH - Daylight Saving Time (DST) Month End Value */
#define RTC_DST_MONTH_DST_END_MONTH(x)           (((uint16_t)(((uint16_t)(x)) << RTC_DST_MONTH_DST_END_MONTH_SHIFT)) & RTC_DST_MONTH_DST_END_MONTH_MASK)

#define RTC_DST_MONTH_DST_START_MONTH_MASK       (0xF00U)
#define RTC_DST_MONTH_DST_START_MONTH_SHIFT      (8U)
/*! DST_START_MONTH - Daylight Saving Time (DST) Month Start Value */
#define RTC_DST_MONTH_DST_START_MONTH(x)         (((uint16_t)(((uint16_t)(x)) << RTC_DST_MONTH_DST_START_MONTH_SHIFT)) & RTC_DST_MONTH_DST_START_MONTH_MASK)
/*! @} */

/*! @name DST_DAY - Daylight Saving Day */
/*! @{ */

#define RTC_DST_DAY_DST_END_DAY_MASK             (0x1FU)
#define RTC_DST_DAY_DST_END_DAY_SHIFT            (0U)
/*! DST_END_DAY - Daylight Saving Time (DST) Day End Value */
#define RTC_DST_DAY_DST_END_DAY(x)               (((uint16_t)(((uint16_t)(x)) << RTC_DST_DAY_DST_END_DAY_SHIFT)) & RTC_DST_DAY_DST_END_DAY_MASK)

#define RTC_DST_DAY_DST_START_DAY_MASK           (0x1F00U)
#define RTC_DST_DAY_DST_START_DAY_SHIFT          (8U)
/*! DST_START_DAY - Daylight Saving Time (DST) Day Start Value */
#define RTC_DST_DAY_DST_START_DAY(x)             (((uint16_t)(((uint16_t)(x)) << RTC_DST_DAY_DST_START_DAY_SHIFT)) & RTC_DST_DAY_DST_START_DAY_MASK)
/*! @} */

/*! @name COMPEN - Compensation */
/*! @{ */

#define RTC_COMPEN_COMPEN_VAL_MASK               (0xFFFFU)
#define RTC_COMPEN_COMPEN_VAL_SHIFT              (0U)
/*! COMPEN_VAL - Compensation Value */
#define RTC_COMPEN_COMPEN_VAL(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_COMPEN_COMPEN_VAL_SHIFT)) & RTC_COMPEN_COMPEN_VAL_MASK)
/*! @} */

/*! @name SUBSECOND_CTRL - Subsecond Control */
/*! @{ */

#define RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_MASK (0x1U)
#define RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_SHIFT (0U)
/*! SUB_SECOND_CNT_EN - Subsecond Counter Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN(x)  (((uint32_t)(((uint32_t)(x)) << RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_SHIFT)) & RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_MASK)
/*! @} */

/*! @name SUBSECOND_CNT - Subsecond Counter */
/*! @{ */

#define RTC_SUBSECOND_CNT_SUBSECOND_CNT_MASK     (0xFFFFU)
#define RTC_SUBSECOND_CNT_SUBSECOND_CNT_SHIFT    (0U)
/*! SUBSECOND_CNT - Current Subsecond Counter Value */
#define RTC_SUBSECOND_CNT_SUBSECOND_CNT(x)       (((uint32_t)(((uint32_t)(x)) << RTC_SUBSECOND_CNT_SUBSECOND_CNT_SHIFT)) & RTC_SUBSECOND_CNT_SUBSECOND_CNT_MASK)
/*! @} */

/*! @name WAKE_TIMER_CTRL - Wake Timer Control */
/*! @{ */

#define RTC_WAKE_TIMER_CTRL_WAKE_FLAG_MASK       (0x2U)
#define RTC_WAKE_TIMER_CTRL_WAKE_FLAG_SHIFT      (1U)
/*! WAKE_FLAG - Wake Timer Status Flag
 *  0b0..Not timed out
 *  0b1..Timed out
 */
#define RTC_WAKE_TIMER_CTRL_WAKE_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_WAKE_FLAG_SHIFT)) & RTC_WAKE_TIMER_CTRL_WAKE_FLAG_MASK)

#define RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_MASK  (0x4U)
#define RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_SHIFT (2U)
/*! CLR_WAKE_TIMER - Clear Wake Timer
 *  0b0..No effect
 *  0b1..Clear the wake timer counter
 */
#define RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER(x)    (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_SHIFT)) & RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_MASK)

#define RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_MASK     (0x10U)
#define RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_SHIFT    (4U)
/*! OSC_DIV_ENA - OSC Divide Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA(x)       (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_SHIFT)) & RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_MASK)

#define RTC_WAKE_TIMER_CTRL_INTR_EN_MASK         (0x20U)
#define RTC_WAKE_TIMER_CTRL_INTR_EN_SHIFT        (5U)
/*! INTR_EN - Enable Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTC_WAKE_TIMER_CTRL_INTR_EN(x)           (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_INTR_EN_SHIFT)) & RTC_WAKE_TIMER_CTRL_INTR_EN_MASK)
/*! @} */

/*! @name WAKE_TIMER_CNT - Wake Timer Counter */
/*! @{ */

#define RTC_WAKE_TIMER_CNT_WAKE_CNT_MASK         (0xFFFFFFFFU)
#define RTC_WAKE_TIMER_CNT_WAKE_CNT_SHIFT        (0U)
/*! WAKE_CNT - Wake Counter */
#define RTC_WAKE_TIMER_CNT_WAKE_CNT(x)           (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CNT_WAKE_CNT_SHIFT)) & RTC_WAKE_TIMER_CNT_WAKE_CNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RTC_Register_Masks */

/* Backward compatibility for RTC */
#define RTC    RTC0


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


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


#endif  /* PERI_RTC_H_ */

