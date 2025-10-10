/*
** ###################################################################
**     Processors:          LPC5526JBD100
**                          LPC5526JBD64
**                          LPC5526JEV98
**                          LPC5528JBD100
**                          LPC5528JBD64
**                          LPC5528JEV59
**                          LPC5528JEV98
**                          LPC55S26JBD100
**                          LPC55S26JBD64
**                          LPC55S26JEV98
**                          LPC55S28JBD100
**                          LPC55S28JBD64
**                          LPC55S28JEV59
**                          LPC55S28JEV98
**                          LPC55S66JBD100_cm33_core0
**                          LPC55S66JBD100_cm33_core1
**                          LPC55S66JBD64_cm33_core0
**                          LPC55S66JBD64_cm33_core1
**                          LPC55S66JEV98_cm33_core0
**                          LPC55S66JEV98_cm33_core1
**                          LPC55S69JBD100_cm33_core0
**                          LPC55S69JBD100_cm33_core1
**                          LPC55S69JBD64_cm33_core0
**                          LPC55S69JBD64_cm33_core1
**                          LPC55S69JEV59_cm33_core0
**                          LPC55S69JEV59_cm33_core1
**                          LPC55S69JEV98_cm33_core0
**                          LPC55S69JEV98_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250529
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MRT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-08-22)
**         Initial version based on v0.2UM
**     - rev. 1.1 (2019-05-16)
**         Initial A1 version based on v1.3UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MRT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MRT
 *
 * CMSIS Peripheral Access Layer for MRT
 */

#if !defined(PERI_MRT_H_)
#define PERI_MRT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5526JBD100) || defined(CPU_LPC5526JBD64) || defined(CPU_LPC5526JEV98))
#include "LPC5526_COMMON.h"
#elif (defined(CPU_LPC5528JBD100) || defined(CPU_LPC5528JBD64) || defined(CPU_LPC5528JEV59) || defined(CPU_LPC5528JEV98))
#include "LPC5528_COMMON.h"
#elif (defined(CPU_LPC55S26JBD100) || defined(CPU_LPC55S26JBD64) || defined(CPU_LPC55S26JEV98))
#include "LPC55S26_COMMON.h"
#elif (defined(CPU_LPC55S28JBD100) || defined(CPU_LPC55S28JBD64) || defined(CPU_LPC55S28JEV59) || defined(CPU_LPC55S28JEV98))
#include "LPC55S28_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core0) || defined(CPU_LPC55S66JBD64_cm33_core0) || defined(CPU_LPC55S66JEV98_cm33_core0))
#include "LPC55S66_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core1) || defined(CPU_LPC55S66JBD64_cm33_core1) || defined(CPU_LPC55S66JEV98_cm33_core1))
#include "LPC55S66_cm33_core1_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core0) || defined(CPU_LPC55S69JBD64_cm33_core0) || defined(CPU_LPC55S69JEV59_cm33_core0) || defined(CPU_LPC55S69JEV98_cm33_core0))
#include "LPC55S69_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core1) || defined(CPU_LPC55S69JBD64_cm33_core1) || defined(CPU_LPC55S69JEV59_cm33_core1) || defined(CPU_LPC55S69JEV98_cm33_core1))
#include "LPC55S69_cm33_core1_COMMON.h"
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
   -- MRT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRT_Peripheral_Access_Layer MRT Peripheral Access Layer
 * @{
 */

/** MRT - Size of Registers Arrays */
#define MRT_CHANNEL_COUNT                         4u

/** MRT - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t INTVAL;                            /**< MRT Time interval value register. This value is loaded into the TIMER register., array offset: 0x0, array step: 0x10 */
    __I  uint32_t TIMER;                             /**< MRT Timer register. This register reads the value of the down-counter., array offset: 0x4, array step: 0x10 */
    __IO uint32_t CTRL;                              /**< MRT Control register. This register controls the MRT modes., array offset: 0x8, array step: 0x10 */
    __IO uint32_t STAT;                              /**< MRT Status register., array offset: 0xC, array step: 0x10 */
  } CHANNEL[MRT_CHANNEL_COUNT];
       uint8_t RESERVED_0[176];
  __IO uint32_t MODCFG;                            /**< Module Configuration register. This register provides information about this particular MRT instance, and allows choosing an overall mode for the idle channel feature., offset: 0xF0 */
  __I  uint32_t IDLE_CH;                           /**< Idle channel register. This register returns the number of the first idle channel., offset: 0xF4 */
  __IO uint32_t IRQ_FLAG;                          /**< Global interrupt flag register, offset: 0xF8 */
} MRT_Type;

/* ----------------------------------------------------------------------------
   -- MRT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRT_Register_Masks MRT Register Masks
 * @{
 */

/*! @name CHANNEL_INTVAL - MRT Time interval value register. This value is loaded into the TIMER register. */
/*! @{ */

#define MRT_CHANNEL_INTVAL_IVALUE_MASK           (0xFFFFFFU)
#define MRT_CHANNEL_INTVAL_IVALUE_SHIFT          (0U)
/*! IVALUE - Time interval load value. This value is loaded into the TIMERn register and the MRT
 *    channel n starts counting down from IVALUE -1. If the timer is idle, writing a non-zero value to
 *    this bit field starts the timer immediately. If the timer is running, writing a zero to this
 *    bit field does the following: If LOAD = 1, the timer stops immediately. If LOAD = 0, the timer
 *    stops at the end of the time interval.
 */
#define MRT_CHANNEL_INTVAL_IVALUE(x)             (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_INTVAL_IVALUE_SHIFT)) & MRT_CHANNEL_INTVAL_IVALUE_MASK)

#define MRT_CHANNEL_INTVAL_LOAD_MASK             (0x80000000U)
#define MRT_CHANNEL_INTVAL_LOAD_SHIFT            (31U)
/*! LOAD - Determines how the timer interval value IVALUE -1 is loaded into the TIMERn register.
 *    This bit is write-only. Reading this bit always returns 0.
 *  0b0..No force load. The load from the INTVALn register to the TIMERn register is processed at the end of the
 *       time interval if the repeat mode is selected.
 *  0b1..Force load. The INTVALn interval value IVALUE -1 is immediately loaded into the TIMERn register while TIMERn is running.
 */
#define MRT_CHANNEL_INTVAL_LOAD(x)               (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_INTVAL_LOAD_SHIFT)) & MRT_CHANNEL_INTVAL_LOAD_MASK)
/*! @} */

/* The count of MRT_CHANNEL_INTVAL */
#define MRT_CHANNEL_INTVAL_COUNT                 (4U)

/*! @name CHANNEL_TIMER - MRT Timer register. This register reads the value of the down-counter. */
/*! @{ */

#define MRT_CHANNEL_TIMER_VALUE_MASK             (0xFFFFFFU)
#define MRT_CHANNEL_TIMER_VALUE_SHIFT            (0U)
/*! VALUE - Holds the current timer value of the down-counter. The initial value of the TIMERn
 *    register is loaded as IVALUE - 1 from the INTVALn register either at the end of the time interval
 *    or immediately in the following cases: INTVALn register is updated in the idle state. INTVALn
 *    register is updated with LOAD = 1. When the timer is in idle state, reading this bit fields
 *    returns -1 (0x00FF FFFF).
 */
#define MRT_CHANNEL_TIMER_VALUE(x)               (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_TIMER_VALUE_SHIFT)) & MRT_CHANNEL_TIMER_VALUE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_TIMER */
#define MRT_CHANNEL_TIMER_COUNT                  (4U)

/*! @name CHANNEL_CTRL - MRT Control register. This register controls the MRT modes. */
/*! @{ */

#define MRT_CHANNEL_CTRL_INTEN_MASK              (0x1U)
#define MRT_CHANNEL_CTRL_INTEN_SHIFT             (0U)
/*! INTEN - Enable the TIMERn interrupt.
 *  0b0..Disabled. TIMERn interrupt is disabled.
 *  0b1..Enabled. TIMERn interrupt is enabled.
 */
#define MRT_CHANNEL_CTRL_INTEN(x)                (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_CTRL_INTEN_SHIFT)) & MRT_CHANNEL_CTRL_INTEN_MASK)

#define MRT_CHANNEL_CTRL_MODE_MASK               (0x6U)
#define MRT_CHANNEL_CTRL_MODE_SHIFT              (1U)
/*! MODE - Selects timer mode.
 *  0b00..Repeat interrupt mode.
 *  0b01..One-shot interrupt mode.
 *  0b10..One-shot stall mode.
 *  0b11..Reserved.
 */
#define MRT_CHANNEL_CTRL_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_CTRL_MODE_SHIFT)) & MRT_CHANNEL_CTRL_MODE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_CTRL */
#define MRT_CHANNEL_CTRL_COUNT                   (4U)

/*! @name CHANNEL_STAT - MRT Status register. */
/*! @{ */

#define MRT_CHANNEL_STAT_INTFLAG_MASK            (0x1U)
#define MRT_CHANNEL_STAT_INTFLAG_SHIFT           (0U)
/*! INTFLAG - Monitors the interrupt flag.
 *  0b0..No pending interrupt. Writing a zero is equivalent to no operation.
 *  0b1..Pending interrupt. The interrupt is pending because TIMERn has reached the end of the time interval. If
 *       the INTEN bit in the CONTROLn is also set to 1, the interrupt for timer channel n and the global interrupt
 *       are raised. Writing a 1 to this bit clears the interrupt request.
 */
#define MRT_CHANNEL_STAT_INTFLAG(x)              (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_INTFLAG_SHIFT)) & MRT_CHANNEL_STAT_INTFLAG_MASK)

#define MRT_CHANNEL_STAT_RUN_MASK                (0x2U)
#define MRT_CHANNEL_STAT_RUN_SHIFT               (1U)
/*! RUN - Indicates the state of TIMERn. This bit is read-only.
 *  0b0..Idle state. TIMERn is stopped.
 *  0b1..Running. TIMERn is running.
 */
#define MRT_CHANNEL_STAT_RUN(x)                  (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_RUN_SHIFT)) & MRT_CHANNEL_STAT_RUN_MASK)

#define MRT_CHANNEL_STAT_INUSE_MASK              (0x4U)
#define MRT_CHANNEL_STAT_INUSE_SHIFT             (2U)
/*! INUSE - Channel In Use flag. Operating details depend on the MULTITASK bit in the MODCFG
 *    register, and affects the use of IDLE_CH. See Idle channel register for details of the two operating
 *    modes.
 *  0b0..This channel is not in use.
 *  0b1..This channel is in use.
 */
#define MRT_CHANNEL_STAT_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_INUSE_SHIFT)) & MRT_CHANNEL_STAT_INUSE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_STAT */
#define MRT_CHANNEL_STAT_COUNT                   (4U)

/*! @name MODCFG - Module Configuration register. This register provides information about this particular MRT instance, and allows choosing an overall mode for the idle channel feature. */
/*! @{ */

#define MRT_MODCFG_NOC_MASK                      (0xFU)
#define MRT_MODCFG_NOC_SHIFT                     (0U)
/*! NOC - Identifies the number of channels in this MRT.(4 channels on this device.) */
#define MRT_MODCFG_NOC(x)                        (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_NOC_SHIFT)) & MRT_MODCFG_NOC_MASK)

#define MRT_MODCFG_NOB_MASK                      (0x1F0U)
#define MRT_MODCFG_NOB_SHIFT                     (4U)
/*! NOB - Identifies the number of timer bits in this MRT. (24 bits wide on this device.) */
#define MRT_MODCFG_NOB(x)                        (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_NOB_SHIFT)) & MRT_MODCFG_NOB_MASK)

#define MRT_MODCFG_MULTITASK_MASK                (0x80000000U)
#define MRT_MODCFG_MULTITASK_SHIFT               (31U)
/*! MULTITASK - Selects the operating mode for the INUSE flags and the IDLE_CH register.
 *  0b0..Hardware status mode. In this mode, the INUSE(n) flags for all channels are reset.
 *  0b1..Multi-task mode.
 */
#define MRT_MODCFG_MULTITASK(x)                  (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_MULTITASK_SHIFT)) & MRT_MODCFG_MULTITASK_MASK)
/*! @} */

/*! @name IDLE_CH - Idle channel register. This register returns the number of the first idle channel. */
/*! @{ */

#define MRT_IDLE_CH_CHAN_MASK                    (0xF0U)
#define MRT_IDLE_CH_CHAN_SHIFT                   (4U)
/*! CHAN - Idle channel. Reading the CHAN bits, returns the lowest idle timer channel. The number is
 *    positioned such that it can be used as an offset from the MRT base address in order to access
 *    the registers for the allocated channel. If all timer channels are running, CHAN = 0xF. See
 *    text above for more details.
 */
#define MRT_IDLE_CH_CHAN(x)                      (((uint32_t)(((uint32_t)(x)) << MRT_IDLE_CH_CHAN_SHIFT)) & MRT_IDLE_CH_CHAN_MASK)
/*! @} */

/*! @name IRQ_FLAG - Global interrupt flag register */
/*! @{ */

#define MRT_IRQ_FLAG_GFLAG0_MASK                 (0x1U)
#define MRT_IRQ_FLAG_GFLAG0_SHIFT                (0U)
/*! GFLAG0 - Monitors the interrupt flag of TIMER0.
 *  0b0..No pending interrupt. Writing a zero is equivalent to no operation.
 *  0b1..Pending interrupt. The interrupt is pending because TIMER0 has reached the end of the time interval. If
 *       the INTEN bit in the CONTROL0 register is also set to 1, the interrupt for timer channel 0 and the global
 *       interrupt are raised. Writing a 1 to this bit clears the interrupt request.
 */
#define MRT_IRQ_FLAG_GFLAG0(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG0_SHIFT)) & MRT_IRQ_FLAG_GFLAG0_MASK)

#define MRT_IRQ_FLAG_GFLAG1_MASK                 (0x2U)
#define MRT_IRQ_FLAG_GFLAG1_SHIFT                (1U)
/*! GFLAG1 - Monitors the interrupt flag of TIMER1. See description of channel 0. */
#define MRT_IRQ_FLAG_GFLAG1(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG1_SHIFT)) & MRT_IRQ_FLAG_GFLAG1_MASK)

#define MRT_IRQ_FLAG_GFLAG2_MASK                 (0x4U)
#define MRT_IRQ_FLAG_GFLAG2_SHIFT                (2U)
/*! GFLAG2 - Monitors the interrupt flag of TIMER2. See description of channel 0. */
#define MRT_IRQ_FLAG_GFLAG2(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG2_SHIFT)) & MRT_IRQ_FLAG_GFLAG2_MASK)

#define MRT_IRQ_FLAG_GFLAG3_MASK                 (0x8U)
#define MRT_IRQ_FLAG_GFLAG3_SHIFT                (3U)
/*! GFLAG3 - Monitors the interrupt flag of TIMER3. See description of channel 0. */
#define MRT_IRQ_FLAG_GFLAG3(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG3_SHIFT)) & MRT_IRQ_FLAG_GFLAG3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRT_Register_Masks */


/*!
 * @}
 */ /* end of group MRT_Peripheral_Access_Layer */


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


#endif  /* PERI_MRT_H_ */

