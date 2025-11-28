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
**         CMSIS Peripheral Access Layer for MCM
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
 * @file PERI_MCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control, offset: 0x10 */
  __IO uint32_t ETBCC;                             /**< ETB Counter Control, offset: 0x14 */
  __IO uint32_t ETBRR;                             /**< ETB Reload, offset: 0x18 */
  __I  uint32_t ETBCV;                             /**< ETB Counter Value, offset: 0x1C */
  __I  uint32_t FADR;                              /**< Write Buffer Fault Address, offset: 0x20 */
  __I  uint32_t FATR;                              /**< Store Buffer Fault Attributes, offset: 0x24 */
  __I  uint32_t FDR;                               /**< Store Buffer Fault Data, offset: 0x28 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name ISCR - Interrupt Status and Control */
/*! @{ */

#define MCM_ISCR_IRQ_MASK                        (0x2U)
#define MCM_ISCR_IRQ_SHIFT                       (1U)
/*! IRQ - ETB-Related Interrupt Pending
 *  0b0..No pending IRQ
 *  0b1..Pending IRQ
 */
#define MCM_ISCR_IRQ(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_IRQ_SHIFT)) & MCM_ISCR_IRQ_MASK)

#define MCM_ISCR_NMI_MASK                        (0x4U)
#define MCM_ISCR_NMI_SHIFT                       (2U)
/*! NMI - Nonmaskable Interrupt Pending
 *  0b0..No pending NMI
 *  0b1..Pending NMI
 */
#define MCM_ISCR_NMI(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_NMI_SHIFT)) & MCM_ISCR_NMI_MASK)

#define MCM_ISCR_DHREQ_MASK                      (0x8U)
#define MCM_ISCR_DHREQ_SHIFT                     (3U)
/*! DHREQ - Debug Halt Request Indicator
 *  0b0..Not initiated
 *  0b1..Initiated
 */
#define MCM_ISCR_DHREQ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_DHREQ_SHIFT)) & MCM_ISCR_DHREQ_MASK)

#define MCM_ISCR_CWBER_MASK                      (0x10U)
#define MCM_ISCR_CWBER_SHIFT                     (4U)
/*! CWBER - Cache Write Buffer Error Status
 *  0b0..No error
 *  0b1..Error occurred
 */
#define MCM_ISCR_CWBER(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBER_SHIFT)) & MCM_ISCR_CWBER_MASK)

#define MCM_ISCR_FIOC_MASK                       (0x100U)
#define MCM_ISCR_FIOC_SHIFT                      (8U)
/*! FIOC - FPU Invalid Operation Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIOC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)

#define MCM_ISCR_FDZC_MASK                       (0x200U)
#define MCM_ISCR_FDZC_SHIFT                      (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FDZC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZC_SHIFT)) & MCM_ISCR_FDZC_MASK)

#define MCM_ISCR_FOFC_MASK                       (0x400U)
#define MCM_ISCR_FOFC_SHIFT                      (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FOFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFC_SHIFT)) & MCM_ISCR_FOFC_MASK)

#define MCM_ISCR_FUFC_MASK                       (0x800U)
#define MCM_ISCR_FUFC_SHIFT                      (11U)
/*! FUFC - FPU Underflow Interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FUFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFC_SHIFT)) & MCM_ISCR_FUFC_MASK)

#define MCM_ISCR_FIXC_MASK                       (0x1000U)
#define MCM_ISCR_FIXC_SHIFT                      (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIXC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXC_SHIFT)) & MCM_ISCR_FIXC_MASK)

#define MCM_ISCR_FIDC_MASK                       (0x8000U)
#define MCM_ISCR_FIDC_SHIFT                      (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIDC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDC_SHIFT)) & MCM_ISCR_FIDC_MASK)

#define MCM_ISCR_CWBEE_MASK                      (0x100000U)
#define MCM_ISCR_CWBEE_SHIFT                     (20U)
/*! CWBEE - Cache Write Buffer Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ISCR_CWBEE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBEE_SHIFT)) & MCM_ISCR_CWBEE_MASK)

#define MCM_ISCR_FIOCE_MASK                      (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT                     (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ISCR_FIOCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)

#define MCM_ISCR_FDZCE_MASK                      (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT                     (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ISCR_FDZCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZCE_SHIFT)) & MCM_ISCR_FDZCE_MASK)

#define MCM_ISCR_FOFCE_MASK                      (0x4000000U)
#define MCM_ISCR_FOFCE_SHIFT                     (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ISCR_FOFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFCE_SHIFT)) & MCM_ISCR_FOFCE_MASK)

#define MCM_ISCR_FUFCE_MASK                      (0x8000000U)
#define MCM_ISCR_FUFCE_SHIFT                     (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ISCR_FUFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFCE_SHIFT)) & MCM_ISCR_FUFCE_MASK)

#define MCM_ISCR_FIXCE_MASK                      (0x10000000U)
#define MCM_ISCR_FIXCE_SHIFT                     (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ISCR_FIXCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXCE_SHIFT)) & MCM_ISCR_FIXCE_MASK)

#define MCM_ISCR_FIDCE_MASK                      (0x80000000U)
#define MCM_ISCR_FIDCE_SHIFT                     (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ISCR_FIDCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDCE_SHIFT)) & MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name ETBCC - ETB Counter Control */
/*! @{ */

#define MCM_ETBCC_CNTEN_MASK                     (0x1U)
#define MCM_ETBCC_CNTEN_SHIFT                    (0U)
/*! CNTEN - Counter Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MCM_ETBCC_CNTEN(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_ETBCC_CNTEN_SHIFT)) & MCM_ETBCC_CNTEN_MASK)

#define MCM_ETBCC_RSPT_MASK                      (0x6U)
#define MCM_ETBCC_RSPT_SHIFT                     (1U)
/*! RSPT - Response Type
 *  0b00..No response
 *  0b01..Generate a normal interrupt
 *  0b10..Generate an NMI
 *  0b11..Generate a debug halt
 */
#define MCM_ETBCC_RSPT(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ETBCC_RSPT_SHIFT)) & MCM_ETBCC_RSPT_MASK)

#define MCM_ETBCC_RLRQ_MASK                      (0x8U)
#define MCM_ETBCC_RLRQ_SHIFT                     (3U)
/*! RLRQ - Reload Request
 *  0b0..No effect
 *  0b1..Reload the counter (clear pending interrupt requests)
 */
#define MCM_ETBCC_RLRQ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ETBCC_RLRQ_SHIFT)) & MCM_ETBCC_RLRQ_MASK)
/*! @} */

/*! @name ETBRR - ETB Reload */
/*! @{ */

#define MCM_ETBRR_RELOAD_MASK                    (0x7FFU)
#define MCM_ETBRR_RELOAD_SHIFT                   (0U)
/*! RELOAD - Byte Count Reload Value */
#define MCM_ETBRR_RELOAD(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_ETBRR_RELOAD_SHIFT)) & MCM_ETBRR_RELOAD_MASK)
/*! @} */

/*! @name ETBCV - ETB Counter Value */
/*! @{ */

#define MCM_ETBCV_COUNTER_MASK                   (0x7FFU)
#define MCM_ETBCV_COUNTER_SHIFT                  (0U)
/*! COUNTER - Byte Count Counter Value */
#define MCM_ETBCV_COUNTER(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_ETBCV_COUNTER_SHIFT)) & MCM_ETBCV_COUNTER_MASK)
/*! @} */

/*! @name FADR - Write Buffer Fault Address */
/*! @{ */

#define MCM_FADR_ADDRESS_MASK                    (0xFFFFFFFFU)
#define MCM_FADR_ADDRESS_SHIFT                   (0U)
/*! ADDRESS - Fault Address */
#define MCM_FADR_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_FADR_ADDRESS_SHIFT)) & MCM_FADR_ADDRESS_MASK)
/*! @} */

/*! @name FATR - Store Buffer Fault Attributes */
/*! @{ */

#define MCM_FATR_BEDA_MASK                       (0x1U)
#define MCM_FATR_BEDA_SHIFT                      (0U)
/*! BEDA - Bus Error Data Access Type
 *  0b0..Instruction
 *  0b1..Data
 */
#define MCM_FATR_BEDA(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEDA_SHIFT)) & MCM_FATR_BEDA_MASK)

#define MCM_FATR_BEMD_MASK                       (0x2U)
#define MCM_FATR_BEMD_SHIFT                      (1U)
/*! BEMD - Bus Error Privilege Level
 *  0b0..User mode
 *  0b1..Supervisor or privileged mode
 */
#define MCM_FATR_BEMD(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMD_SHIFT)) & MCM_FATR_BEMD_MASK)

#define MCM_FATR_BESZ_MASK                       (0x30U)
#define MCM_FATR_BESZ_SHIFT                      (4U)
/*! BESZ - Bus Error Size
 *  0b00..8-bit
 *  0b01..16-bit
 *  0b10..32-bit
 *  0b11..
 */
#define MCM_FATR_BESZ(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BESZ_SHIFT)) & MCM_FATR_BESZ_MASK)

#define MCM_FATR_BEWT_MASK                       (0x80U)
#define MCM_FATR_BEWT_SHIFT                      (7U)
/*! BEWT - Bus Error Write
 *  0b0..Read
 *  0b1..Write
 */
#define MCM_FATR_BEWT(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEWT_SHIFT)) & MCM_FATR_BEWT_MASK)

#define MCM_FATR_BEMN_MASK                       (0xF00U)
#define MCM_FATR_BEMN_SHIFT                      (8U)
/*! BEMN - Bus Error Master Number */
#define MCM_FATR_BEMN(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMN_SHIFT)) & MCM_FATR_BEMN_MASK)

#define MCM_FATR_BEOVR_MASK                      (0x80000000U)
#define MCM_FATR_BEOVR_SHIFT                     (31U)
/*! BEOVR - Bus Error Overrun
 *  0b0..No overrun
 *  0b1..Overrun
 */
#define MCM_FATR_BEOVR(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEOVR_SHIFT)) & MCM_FATR_BEOVR_MASK)
/*! @} */

/*! @name FDR - Store Buffer Fault Data */
/*! @{ */

#define MCM_FDR_DATA_MASK                        (0xFFFFFFFFU)
#define MCM_FDR_DATA_SHIFT                       (0U)
/*! DATA - Fault Data */
#define MCM_FDR_DATA(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_FDR_DATA_SHIFT)) & MCM_FDR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MCM_H_ */
