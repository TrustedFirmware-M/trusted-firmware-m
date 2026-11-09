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
**         CMSIS Peripheral Access Layer for USBHSDCD
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
 * @file PERI_USBHSDCD.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBHSDCD
 *
 * CMSIS Peripheral Access Layer for USBHSDCD
 */

#if !defined(PERI_USBHSDCD_H_)
#define PERI_USBHSDCD_H_                         /**< Symbol preventing repeated inclusion */

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
   -- USBHSDCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSDCD_Peripheral_Access_Layer USBHSDCD Peripheral Access Layer
 * @{
 */

/** USBHSDCD - Register Layout Typedef */
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
} USBHSDCD_Type;

/* ----------------------------------------------------------------------------
   -- USBHSDCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSDCD_Register_Masks USBHSDCD Register Masks
 * @{
 */

/*! @name CONTROL - Control */
/*! @{ */

#define USBHSDCD_CONTROL_IACK_MASK               (0x1U)
#define USBHSDCD_CONTROL_IACK_SHIFT              (0U)
/*! IACK - Interrupt Acknowledge
 *  0b0..Do not clear the interrupt.
 *  0b1..Clear the IF field (interrupt flag).
 */
#define USBHSDCD_CONTROL_IACK(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CONTROL_IACK_SHIFT)) & USBHSDCD_CONTROL_IACK_MASK)

#define USBHSDCD_CONTROL_IF_MASK                 (0x100U)
#define USBHSDCD_CONTROL_IF_SHIFT                (8U)
/*! IF - Interrupt Flag
 *  0b0..No interrupt is pending.
 *  0b1..An interrupt is pending.
 */
#define USBHSDCD_CONTROL_IF(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CONTROL_IF_SHIFT)) & USBHSDCD_CONTROL_IF_MASK)

#define USBHSDCD_CONTROL_IE_MASK                 (0x10000U)
#define USBHSDCD_CONTROL_IE_SHIFT                (16U)
/*! IE - Interrupt Enable
 *  0b0..Disable interrupts to the system.
 *  0b1..Enable interrupts to the system.
 */
#define USBHSDCD_CONTROL_IE(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CONTROL_IE_SHIFT)) & USBHSDCD_CONTROL_IE_MASK)

#define USBHSDCD_CONTROL_BC12_MASK               (0x20000U)
#define USBHSDCD_CONTROL_BC12_SHIFT              (17U)
/*! BC12 - Battery Charging Revision 1.2 Compatibility
 *  0b0..Compatible with BC1.1
 *  0b1..Compatible with BC1.2 (default)
 */
#define USBHSDCD_CONTROL_BC12(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CONTROL_BC12_SHIFT)) & USBHSDCD_CONTROL_BC12_MASK)

#define USBHSDCD_CONTROL_START_MASK              (0x1000000U)
#define USBHSDCD_CONTROL_START_SHIFT             (24U)
/*! START - Start Change Detection Sequence
 *  0b0..Do not start the sequence. Writes of this value have no effect.
 *  0b1..Initiate the charger detection sequence. If the sequence is already running, writes of this value have no effect.
 */
#define USBHSDCD_CONTROL_START(x)                (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CONTROL_START_SHIFT)) & USBHSDCD_CONTROL_START_MASK)

#define USBHSDCD_CONTROL_SR_MASK                 (0x2000000U)
#define USBHSDCD_CONTROL_SR_SHIFT                (25U)
/*! SR - Software Reset
 *  0b0..Do not perform a software reset.
 *  0b1..Perform a software reset.
 */
#define USBHSDCD_CONTROL_SR(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CONTROL_SR_SHIFT)) & USBHSDCD_CONTROL_SR_MASK)
/*! @} */

/*! @name CLOCK - Clock */
/*! @{ */

#define USBHSDCD_CLOCK_CLOCK_UNIT_MASK           (0x1U)
#define USBHSDCD_CLOCK_CLOCK_UNIT_SHIFT          (0U)
/*! CLOCK_UNIT - Unit of Measurement Encoding for Clock Speed
 *  0b0..kHz Speed (between 4 kHz and 1023 kHz)
 *  0b1..MHz Speed (between 1 MHz and 1023 MHz)
 */
#define USBHSDCD_CLOCK_CLOCK_UNIT(x)             (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CLOCK_CLOCK_UNIT_SHIFT)) & USBHSDCD_CLOCK_CLOCK_UNIT_MASK)

#define USBHSDCD_CLOCK_CLOCK_SPEED_MASK          (0xFFCU)
#define USBHSDCD_CLOCK_CLOCK_SPEED_SHIFT         (2U)
/*! CLOCK_SPEED - Numerical Value of Clock Speed in Binary */
#define USBHSDCD_CLOCK_CLOCK_SPEED(x)            (((uint32_t)(((uint32_t)(x)) << USBHSDCD_CLOCK_CLOCK_SPEED_SHIFT)) & USBHSDCD_CLOCK_CLOCK_SPEED_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define USBHSDCD_STATUS_SEQ_RES_MASK             (0x30000U)
#define USBHSDCD_STATUS_SEQ_RES_SHIFT            (16U)
/*! SEQ_RES - Charger Detection Sequence Results
 *  0b00..No results to report.
 *  0b01..Attached to an SDP. Must comply with USB 2.0 by drawing only 2.5 mA (max) until connected.
 *  0b10..Attached to a charging port. The exact meaning depends on the STATUS[SEQ_STAT] field (value 0: Attached
 *        to either a CDP or a DCP. The charger type detection has not completed. value 1: Attached to a CDP. The
 *        charger type detection has completed.)
 *  0b11..Attached to a DCP.
 */
#define USBHSDCD_STATUS_SEQ_RES(x)               (((uint32_t)(((uint32_t)(x)) << USBHSDCD_STATUS_SEQ_RES_SHIFT)) & USBHSDCD_STATUS_SEQ_RES_MASK)

#define USBHSDCD_STATUS_SEQ_STAT_MASK            (0xC0000U)
#define USBHSDCD_STATUS_SEQ_STAT_SHIFT           (18U)
/*! SEQ_STAT - Charger Detection Sequence Status
 *  0b00..The module is either not enabled, or the module is enabled but the data pins have not yet been detected.
 *  0b01..Data pin contact detection is complete.
 *  0b10..Charging port detection is complete.
 *  0b11..Charger type detection is complete.
 */
#define USBHSDCD_STATUS_SEQ_STAT(x)              (((uint32_t)(((uint32_t)(x)) << USBHSDCD_STATUS_SEQ_STAT_SHIFT)) & USBHSDCD_STATUS_SEQ_STAT_MASK)

#define USBHSDCD_STATUS_ERR_MASK                 (0x100000U)
#define USBHSDCD_STATUS_ERR_SHIFT                (20U)
/*! ERR - Error Flag
 *  0b0..No sequence errors.
 *  0b1..Error in the detection sequence.
 */
#define USBHSDCD_STATUS_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSDCD_STATUS_ERR_SHIFT)) & USBHSDCD_STATUS_ERR_MASK)

#define USBHSDCD_STATUS_TO_MASK                  (0x200000U)
#define USBHSDCD_STATUS_TO_SHIFT                 (21U)
/*! TO - Timeout Flag
 *  0b0..The detection sequence is not running for over 1 s.
 *  0b1..It is over 1 s since the data pin contact was detected and debounced.
 */
#define USBHSDCD_STATUS_TO(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSDCD_STATUS_TO_SHIFT)) & USBHSDCD_STATUS_TO_MASK)

#define USBHSDCD_STATUS_ACTIVE_MASK              (0x400000U)
#define USBHSDCD_STATUS_ACTIVE_SHIFT             (22U)
/*! ACTIVE - Active Status Indicator
 *  0b0..The sequence is not running.
 *  0b1..The sequence is running.
 */
#define USBHSDCD_STATUS_ACTIVE(x)                (((uint32_t)(((uint32_t)(x)) << USBHSDCD_STATUS_ACTIVE_SHIFT)) & USBHSDCD_STATUS_ACTIVE_MASK)
/*! @} */

/*! @name SIGNAL_OVERRIDE - Signal Override */
/*! @{ */

#define USBHSDCD_SIGNAL_OVERRIDE_PS_MASK         (0x7U)
#define USBHSDCD_SIGNAL_OVERRIDE_PS_SHIFT        (0U)
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
#define USBHSDCD_SIGNAL_OVERRIDE_PS(x)           (((uint32_t)(((uint32_t)(x)) << USBHSDCD_SIGNAL_OVERRIDE_PS_SHIFT)) & USBHSDCD_SIGNAL_OVERRIDE_PS_MASK)
/*! @} */

/*! @name TIMER0 - TIMER0 */
/*! @{ */

#define USBHSDCD_TIMER0_TUNITCON_MASK            (0xFFFU)
#define USBHSDCD_TIMER0_TUNITCON_SHIFT           (0U)
/*! TUNITCON - Unit Connection Timer Elapse (in ms) */
#define USBHSDCD_TIMER0_TUNITCON(x)              (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER0_TUNITCON_SHIFT)) & USBHSDCD_TIMER0_TUNITCON_MASK)

#define USBHSDCD_TIMER0_TSEQ_INIT_MASK           (0x3FF0000U)
#define USBHSDCD_TIMER0_TSEQ_INIT_SHIFT          (16U)
/*! TSEQ_INIT - Sequence Initiation Time
 *  0b0000000000-0b1111111111..0 ms - 1023 ms
 */
#define USBHSDCD_TIMER0_TSEQ_INIT(x)             (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER0_TSEQ_INIT_SHIFT)) & USBHSDCD_TIMER0_TSEQ_INIT_MASK)
/*! @} */

/*! @name TIMER1 - TIMER1 */
/*! @{ */

#define USBHSDCD_TIMER1_TVDPSRC_ON_MASK          (0x3FFU)
#define USBHSDCD_TIMER1_TVDPSRC_ON_SHIFT         (0U)
/*! TVDPSRC_ON - Time Period Comparator Enabled
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBHSDCD_TIMER1_TVDPSRC_ON(x)            (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER1_TVDPSRC_ON_SHIFT)) & USBHSDCD_TIMER1_TVDPSRC_ON_MASK)

#define USBHSDCD_TIMER1_TDCD_DBNC_MASK           (0x3FF0000U)
#define USBHSDCD_TIMER1_TDCD_DBNC_SHIFT          (16U)
/*! TDCD_DBNC - Time Period to Debounce D+ Signal
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBHSDCD_TIMER1_TDCD_DBNC(x)             (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER1_TDCD_DBNC_SHIFT)) & USBHSDCD_TIMER1_TDCD_DBNC_MASK)
/*! @} */

/*! @name TIMER2_BC11 - TIMER2_BC11 */
/*! @{ */

#define USBHSDCD_TIMER2_BC11_CHECK_DM_MASK       (0xFU)
#define USBHSDCD_TIMER2_BC11_CHECK_DM_SHIFT      (0U)
/*! CHECK_DM - Time Before Check of D- Line
 *  0b0001-0b1111..1 ms - 15 ms
 */
#define USBHSDCD_TIMER2_BC11_CHECK_DM(x)         (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER2_BC11_CHECK_DM_SHIFT)) & USBHSDCD_TIMER2_BC11_CHECK_DM_MASK)

#define USBHSDCD_TIMER2_BC11_TVDPSRC_CON_MASK    (0x3FF0000U)
#define USBHSDCD_TIMER2_BC11_TVDPSRC_CON_SHIFT   (16U)
/*! TVDPSRC_CON - Time Period Before Enabling D+ Pullup
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBHSDCD_TIMER2_BC11_TVDPSRC_CON(x)      (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER2_BC11_TVDPSRC_CON_SHIFT)) & USBHSDCD_TIMER2_BC11_TVDPSRC_CON_MASK)
/*! @} */

/*! @name TIMER2_BC12 - TIMER2_BC12 */
/*! @{ */

#define USBHSDCD_TIMER2_BC12_TVDMSRC_ON_MASK     (0x3FFU)
#define USBHSDCD_TIMER2_BC12_TVDMSRC_ON_SHIFT    (0U)
/*! TVDMSRC_ON - TVDMSRC_ON
 *  0b0000000000-0b0000101000..0 ms - 40 ms
 */
#define USBHSDCD_TIMER2_BC12_TVDMSRC_ON(x)       (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER2_BC12_TVDMSRC_ON_SHIFT)) & USBHSDCD_TIMER2_BC12_TVDMSRC_ON_MASK)

#define USBHSDCD_TIMER2_BC12_TWAIT_AFTER_PRD_MASK (0x3FF0000U)
#define USBHSDCD_TIMER2_BC12_TWAIT_AFTER_PRD_SHIFT (16U)
/*! TWAIT_AFTER_PRD - TWAIT_AFTER_PRD
 *  0b0000000001-0b1111111111..1 ms - 1023 ms
 */
#define USBHSDCD_TIMER2_BC12_TWAIT_AFTER_PRD(x)  (((uint32_t)(((uint32_t)(x)) << USBHSDCD_TIMER2_BC12_TWAIT_AFTER_PRD_SHIFT)) & USBHSDCD_TIMER2_BC12_TWAIT_AFTER_PRD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBHSDCD_Register_Masks */

/* Backward compatibility */
#define USBHSDCD_IRQS                            { USB1_HS_PHY_IRQn }
#define USB1_HS_PHY_IRQS                         USBPHY_IRQS


/*!
 * @}
 */ /* end of group USBHSDCD_Peripheral_Access_Layer */


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


#endif  /* PERI_USBHSDCD_H_ */

