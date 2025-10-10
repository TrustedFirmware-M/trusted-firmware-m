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
**         CMSIS Peripheral Access Layer for USBDCD
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
 * @file PERI_USBDCD.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBDCD
 *
 * CMSIS Peripheral Access Layer for USBDCD
 */

#if !defined(PERI_USBDCD_H_)
#define PERI_USBDCD_H_                           /**< Symbol preventing repeated inclusion */

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
   -- USBDCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBDCD_Peripheral_Access_Layer USBDCD Peripheral Access Layer
 * @{
 */

/** USBDCD - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONTROL;                           /**< Control, offset: 0x0 */
  __IO uint32_t CLOCK;                             /**< Clock, offset: 0x4 */
  __I  uint32_t STATUS;                            /**< Status, offset: 0x8 */
  __IO uint32_t SIGNAL_OVERRIDE;                   /**< Signal Override, offset: 0xC */
  __IO uint32_t TIMER0;                            /**< TIMER0, offset: 0x10 */
  __IO uint32_t TIMER1;                            /**< TIMER1, offset: 0x14 */
  union {                                          /* offset: 0x18 */
    __IO uint32_t TIMER2_BC11;                       /**< TIMER2_BC11, offset: 0x18 */
    __IO uint32_t TIMER2_BC12;                       /**< TIMER2_BC12, offset: 0x18 */
  };
} USBDCD_Type;

/* ----------------------------------------------------------------------------
   -- USBDCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBDCD_Register_Masks USBDCD Register Masks
 * @{
 */

/*! @name CONTROL - Control */
/*! @{ */

#define USBDCD_CONTROL_IACK_MASK                 (0x1U)
#define USBDCD_CONTROL_IACK_SHIFT                (0U)
/*! IACK - Interrupt Acknowledge
 *  0b0..Do not clear the interrupt.
 *  0b1..Clear the IF field (interrupt flag).
 */
#define USBDCD_CONTROL_IACK(x)                   (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_IACK_SHIFT)) & USBDCD_CONTROL_IACK_MASK)

#define USBDCD_CONTROL_IF_MASK                   (0x100U)
#define USBDCD_CONTROL_IF_SHIFT                  (8U)
/*! IF - Interrupt Flag
 *  0b0..No interrupt is pending.
 *  0b1..An interrupt is pending.
 */
#define USBDCD_CONTROL_IF(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_IF_SHIFT)) & USBDCD_CONTROL_IF_MASK)

#define USBDCD_CONTROL_IE_MASK                   (0x10000U)
#define USBDCD_CONTROL_IE_SHIFT                  (16U)
/*! IE - Interrupt Enable
 *  0b0..Disable interrupts to the system.
 *  0b1..Enable interrupts to the system.
 */
#define USBDCD_CONTROL_IE(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_IE_SHIFT)) & USBDCD_CONTROL_IE_MASK)

#define USBDCD_CONTROL_BC12_MASK                 (0x20000U)
#define USBDCD_CONTROL_BC12_SHIFT                (17U)
/*! BC12 - Battery Charging Revision 1.2 Compatibility
 *  0b0..Compatible with BC1.1
 *  0b1..Compatible with BC1.2 (default)
 */
#define USBDCD_CONTROL_BC12(x)                   (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_BC12_SHIFT)) & USBDCD_CONTROL_BC12_MASK)

#define USBDCD_CONTROL_START_MASK                (0x1000000U)
#define USBDCD_CONTROL_START_SHIFT               (24U)
/*! START - Start Change Detection Sequence
 *  0b0..Do not start the sequence. Writes of this value have no effect.
 *  0b1..Initiate the charger detection sequence. If the sequence is already running, writes of this value have no effect.
 */
#define USBDCD_CONTROL_START(x)                  (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_START_SHIFT)) & USBDCD_CONTROL_START_MASK)

#define USBDCD_CONTROL_SR_MASK                   (0x2000000U)
#define USBDCD_CONTROL_SR_SHIFT                  (25U)
/*! SR - Software Reset
 *  0b0..Do not perform a software reset.
 *  0b1..Perform a software reset.
 */
#define USBDCD_CONTROL_SR(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_SR_SHIFT)) & USBDCD_CONTROL_SR_MASK)
/*! @} */

/*! @name CLOCK - Clock */
/*! @{ */

#define USBDCD_CLOCK_CLOCK_UNIT_MASK             (0x1U)
#define USBDCD_CLOCK_CLOCK_UNIT_SHIFT            (0U)
/*! CLOCK_UNIT - Unit of Measurement Encoding for Clock Speed
 *  0b0..kHz Speed (between 4 kHz and 1023 kHz)
 *  0b1..MHz Speed (between 1 MHz and 1023 MHz)
 */
#define USBDCD_CLOCK_CLOCK_UNIT(x)               (((uint32_t)(((uint32_t)(x)) << USBDCD_CLOCK_CLOCK_UNIT_SHIFT)) & USBDCD_CLOCK_CLOCK_UNIT_MASK)

#define USBDCD_CLOCK_CLOCK_SPEED_MASK            (0xFFCU)
#define USBDCD_CLOCK_CLOCK_SPEED_SHIFT           (2U)
/*! CLOCK_SPEED - Numerical Value of Clock Speed in Binary */
#define USBDCD_CLOCK_CLOCK_SPEED(x)              (((uint32_t)(((uint32_t)(x)) << USBDCD_CLOCK_CLOCK_SPEED_SHIFT)) & USBDCD_CLOCK_CLOCK_SPEED_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define USBDCD_STATUS_SEQ_RES_MASK               (0x30000U)
#define USBDCD_STATUS_SEQ_RES_SHIFT              (16U)
/*! SEQ_RES - Charger Detection Sequence Results
 *  0b00..No results to report.
 *  0b01..Attached to an SDP. Must comply with USB 2.0 by drawing only 2.5 mA (max) until connected.
 *  0b10..Attached to a charging port. The exact meaning depends on the STATUS[SEQ_STAT] field (value 0: Attached
 *        to either a CDP or a DCP. The charger type detection has not completed. value 1: Attached to a CDP. The
 *        charger type detection has completed.)
 *  0b11..Attached to a DCP.
 */
#define USBDCD_STATUS_SEQ_RES(x)                 (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_SEQ_RES_SHIFT)) & USBDCD_STATUS_SEQ_RES_MASK)

#define USBDCD_STATUS_SEQ_STAT_MASK              (0xC0000U)
#define USBDCD_STATUS_SEQ_STAT_SHIFT             (18U)
/*! SEQ_STAT - Charger Detection Sequence Status
 *  0b00..The module is either not enabled, or the module is enabled but the data pins have not yet been detected.
 *  0b01..Data pin contact detection is complete.
 *  0b10..Charging port detection is complete.
 *  0b11..Charger type detection is complete.
 */
#define USBDCD_STATUS_SEQ_STAT(x)                (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_SEQ_STAT_SHIFT)) & USBDCD_STATUS_SEQ_STAT_MASK)

#define USBDCD_STATUS_ERR_MASK                   (0x100000U)
#define USBDCD_STATUS_ERR_SHIFT                  (20U)
/*! ERR - Error Flag
 *  0b0..No sequence errors.
 *  0b1..Error in the detection sequence.
 */
#define USBDCD_STATUS_ERR(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_ERR_SHIFT)) & USBDCD_STATUS_ERR_MASK)

#define USBDCD_STATUS_TO_MASK                    (0x200000U)
#define USBDCD_STATUS_TO_SHIFT                   (21U)
/*! TO - Timeout Flag
 *  0b0..The detection sequence is not running for over 1 s.
 *  0b1..It is over 1 s since the data pin contact was detected and debounced.
 */
#define USBDCD_STATUS_TO(x)                      (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_TO_SHIFT)) & USBDCD_STATUS_TO_MASK)

#define USBDCD_STATUS_ACTIVE_MASK                (0x400000U)
#define USBDCD_STATUS_ACTIVE_SHIFT               (22U)
/*! ACTIVE - Active Status Indicator
 *  0b0..The sequence is not running.
 *  0b1..The sequence is running.
 */
#define USBDCD_STATUS_ACTIVE(x)                  (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_ACTIVE_SHIFT)) & USBDCD_STATUS_ACTIVE_MASK)
/*! @} */

/*! @name SIGNAL_OVERRIDE - Signal Override */
/*! @{ */

#define USBDCD_SIGNAL_OVERRIDE_PS_MASK           (0x7U)
#define USBDCD_SIGNAL_OVERRIDE_PS_SHIFT          (0U)
/*! PS - Phase Selection
 *  0b000..No overrides. Field must remain at this value during normal USB data communication to prevent
 *         unexpected conditions on USB_DP and USB_DM pins. (Default)
 *  0b001..Reserved, not for customer use.
 *  0b010..Enables VDP_SRC voltage source for the USB_DP pin and IDM_SINK current source for the USB_DM pin.
 *  0b011..Reserved, not for customer use.
 *  0b100..Enables VDM_SRC voltage source only.
 *  0b101..Reserved, not for customer use.
 *  0b110..Reserved, not for customer use.
 *  0b111..Reserved, not for customer use.
 */
#define USBDCD_SIGNAL_OVERRIDE_PS(x)             (((uint32_t)(((uint32_t)(x)) << USBDCD_SIGNAL_OVERRIDE_PS_SHIFT)) & USBDCD_SIGNAL_OVERRIDE_PS_MASK)
/*! @} */

/*! @name TIMER0 - TIMER0 */
/*! @{ */

#define USBDCD_TIMER0_TUNITCON_MASK              (0xFFFU)
#define USBDCD_TIMER0_TUNITCON_SHIFT             (0U)
/*! TUNITCON - Unit Connection Timer Elapse (in ms) */
#define USBDCD_TIMER0_TUNITCON(x)                (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER0_TUNITCON_SHIFT)) & USBDCD_TIMER0_TUNITCON_MASK)

#define USBDCD_TIMER0_TSEQ_INIT_MASK             (0x3FF0000U)
#define USBDCD_TIMER0_TSEQ_INIT_SHIFT            (16U)
/*! TSEQ_INIT - Sequence Initiation Time
 *  0b0000000000-0b1111111111..0 ms - 1023 ms
 */
#define USBDCD_TIMER0_TSEQ_INIT(x)               (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER0_TSEQ_INIT_SHIFT)) & USBDCD_TIMER0_TSEQ_INIT_MASK)
/*! @} */

/*! @name TIMER1 - TIMER1 */
/*! @{ */

#define USBDCD_TIMER1_TVDPSRC_ON_MASK            (0x3FFU)
#define USBDCD_TIMER1_TVDPSRC_ON_SHIFT           (0U)
/*! TVDPSRC_ON - Time Period Comparator Enabled
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBDCD_TIMER1_TVDPSRC_ON(x)              (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER1_TVDPSRC_ON_SHIFT)) & USBDCD_TIMER1_TVDPSRC_ON_MASK)

#define USBDCD_TIMER1_TDCD_DBNC_MASK             (0x3FF0000U)
#define USBDCD_TIMER1_TDCD_DBNC_SHIFT            (16U)
/*! TDCD_DBNC - Time Period to Debounce D+ Signal
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBDCD_TIMER1_TDCD_DBNC(x)               (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER1_TDCD_DBNC_SHIFT)) & USBDCD_TIMER1_TDCD_DBNC_MASK)
/*! @} */

/*! @name TIMER2_BC11 - TIMER2_BC11 */
/*! @{ */

#define USBDCD_TIMER2_BC11_CHECK_DM_MASK         (0xFU)
#define USBDCD_TIMER2_BC11_CHECK_DM_SHIFT        (0U)
/*! CHECK_DM - Time Before Check of D- Line
 *  0b0001-0b1111..1 ms - 15 ms
 */
#define USBDCD_TIMER2_BC11_CHECK_DM(x)           (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER2_BC11_CHECK_DM_SHIFT)) & USBDCD_TIMER2_BC11_CHECK_DM_MASK)

#define USBDCD_TIMER2_BC11_TVDPSRC_CON_MASK      (0x3FF0000U)
#define USBDCD_TIMER2_BC11_TVDPSRC_CON_SHIFT     (16U)
/*! TVDPSRC_CON - Time Period Before Enabling D+ Pullup
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBDCD_TIMER2_BC11_TVDPSRC_CON(x)        (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER2_BC11_TVDPSRC_CON_SHIFT)) & USBDCD_TIMER2_BC11_TVDPSRC_CON_MASK)
/*! @} */

/*! @name TIMER2_BC12 - TIMER2_BC12 */
/*! @{ */

#define USBDCD_TIMER2_BC12_TVDMSRC_ON_MASK       (0x3FFU)
#define USBDCD_TIMER2_BC12_TVDMSRC_ON_SHIFT      (0U)
/*! TVDMSRC_ON - TVDMSRC_ON
 *  0b0000000000-0b0000101000..0 ms - 40 ms
 */
#define USBDCD_TIMER2_BC12_TVDMSRC_ON(x)         (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER2_BC12_TVDMSRC_ON_SHIFT)) & USBDCD_TIMER2_BC12_TVDMSRC_ON_MASK)

#define USBDCD_TIMER2_BC12_TWAIT_AFTER_PRD_MASK  (0x3FF0000U)
#define USBDCD_TIMER2_BC12_TWAIT_AFTER_PRD_SHIFT (16U)
/*! TWAIT_AFTER_PRD - TWAIT_AFTER_PRD
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBDCD_TIMER2_BC12_TWAIT_AFTER_PRD(x)    (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER2_BC12_TWAIT_AFTER_PRD_SHIFT)) & USBDCD_TIMER2_BC12_TWAIT_AFTER_PRD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBDCD_Register_Masks */


/*!
 * @}
 */ /* end of group USBDCD_Peripheral_Access_Layer */


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


#endif  /* PERI_USBDCD_H_ */

