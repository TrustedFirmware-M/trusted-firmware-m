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
**         CMSIS Peripheral Access Layer for RTC
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
 * @file PERI_RTC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

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
       uint8_t RESERVED_0[6];
  __IO uint16_t ALM_SUBSECONDS;                    /**< Sub Second Alarm, offset: 0x1E */
       uint8_t RESERVED_1[2];
  __IO uint16_t DST_HOUR;                          /**< Daylight Saving Hour, offset: 0x22 */
  __IO uint16_t DST_MONTH;                         /**< Daylight Saving Month, offset: 0x24 */
  __IO uint16_t DST_DAY;                           /**< Daylight Saving Day, offset: 0x26 */
  __IO uint16_t COMPEN;                            /**< Compensation, offset: 0x28 */
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
 *  0b00..If CTRL[ALM_SUBSECS_MATCH_EN] =0, Only seconds, minutes, and hours matched. If
 *        CTRL[ALM_SUBSECS_MATCH_EN] =1, Only subseconds, seconds, minutes, and hours matched.
 *  0b01..If CTRL[ALM_SUBSECS_MATCH_EN] =0, Only seconds, minutes, hours, and days matched. If
 *        CTRL[ALM_SUBSECS_MATCH_EN] =1, Only subseconds, seconds, minutes, hours, and days matched.
 *  0b10..If CTRL[ALM_SUBSECS_MATCH_EN] =0, Only seconds, minutes, hours, days and months matched. If
 *        CTRL[ALM_SUBSECS_MATCH_EN] =1, Only subseconds, seconds, minutes, hours, days and months matched.
 *  0b11..If CTRL[ALM_SUBSECS_MATCH_EN] =0, Only seconds, minutes, hours, days, months and year (offset) matched.
 *        If CTRL[ALM_SUBSECS_MATCH_EN] =1, Only subseconds, seconds, minutes, hours, days, months and year
 *        (offset) matched.
 */
#define RTC_CTRL_ALM_MATCH(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_ALM_MATCH_SHIFT)) & RTC_CTRL_ALM_MATCH_MASK)

#define RTC_CTRL_ALM_SUBSECS_MATCH_EN_MASK       (0x20U)
#define RTC_CTRL_ALM_SUBSECS_MATCH_EN_SHIFT      (5U)
/*! ALM_SUBSECS_MATCH_EN - Alarm Subseconds Match Enable Signal
 *  0b0..Alarm Subseconds Match is Dissabled.
 *  0b1..Alarm Subseconds Match is Enabled.
 */
#define RTC_CTRL_ALM_SUBSECS_MATCH_EN(x)         (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_ALM_SUBSECS_MATCH_EN_SHIFT)) & RTC_CTRL_ALM_SUBSECS_MATCH_EN_MASK)

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

/*! @name ALM_SUBSECONDS - Sub Second Alarm */
/*! @{ */

#define RTC_ALM_SUBSECONDS_ALM_SUBSECS_MASK      (0xFFFFU)
#define RTC_ALM_SUBSECONDS_ALM_SUBSECS_SHIFT     (0U)
/*! ALM_SUBSECS - Alarm Sub Second Counter Value */
#define RTC_ALM_SUBSECONDS_ALM_SUBSECS(x)        (((uint16_t)(((uint16_t)(x)) << RTC_ALM_SUBSECONDS_ALM_SUBSECS_SHIFT)) & RTC_ALM_SUBSECONDS_ALM_SUBSECS_MASK)
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


/*!
 * @}
 */ /* end of group RTC_Register_Masks */


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

