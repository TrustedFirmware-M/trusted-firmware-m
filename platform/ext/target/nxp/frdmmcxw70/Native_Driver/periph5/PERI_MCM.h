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
**         CMSIS Peripheral Access Layer for MCM
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
 * @file PERI_MCM.h
 * @version 1.0
 * @date 2026-01-09
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

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
       uint8_t RESERVED_1[12];
  __I  uint32_t FADR;                              /**< Write Buffer Fault Address, offset: 0x20 */
  __I  uint32_t FATR;                              /**< Store Buffer Fault Attributes, offset: 0x24 */
  __I  uint32_t FDR;                               /**< Store Buffer Fault Data, offset: 0x28 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CPCR2;                             /**< Core Platform Control 2, offset: 0x34 */
       uint8_t RESERVED_3[976];
  __IO uint32_t LMDR2;                             /**< Local Memory Descriptor 2, offset: 0x408 */
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
/*! BEMN - Bus Error Initiator Number */
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

/*! @name CPCR2 - Core Platform Control 2 */
/*! @{ */

#define MCM_CPCR2_CCBC_MASK                      (0x1U)
#define MCM_CPCR2_CCBC_SHIFT                     (0U)
/*! CCBC - Clear Code Bus Cache
 *  0b0..No effect
 *  0b1..Clear code bus cache
 */
#define MCM_CPCR2_CCBC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CCBC_SHIFT)) & MCM_CPCR2_CCBC_MASK)

#define MCM_CPCR2_DCCWB_MASK                     (0x2U)
#define MCM_CPCR2_DCCWB_SHIFT                    (1U)
/*! DCCWB - Disable Code Cache Write Buffer
 *  0b0..Enable
 *  0b1..Disable
 */
#define MCM_CPCR2_DCCWB(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_DCCWB_SHIFT)) & MCM_CPCR2_DCCWB_MASK)

#define MCM_CPCR2_FCCNA_MASK                     (0x4U)
#define MCM_CPCR2_FCCNA_SHIFT                    (2U)
/*! FCCNA - Force Code Cache to No Allocation
 *  0b0..Allocation
 *  0b1..No allocation
 */
#define MCM_CPCR2_FCCNA(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_FCCNA_SHIFT)) & MCM_CPCR2_FCCNA_MASK)

#define MCM_CPCR2_DCBC_MASK                      (0x8U)
#define MCM_CPCR2_DCBC_SHIFT                     (3U)
/*! DCBC - Disable Code Bus Cache
 *  0b0..Enable
 *  0b1..Disable
 */
#define MCM_CPCR2_DCBC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_DCBC_SHIFT)) & MCM_CPCR2_DCBC_MASK)

#define MCM_CPCR2_CBCS_MASK                      (0xF0U)
#define MCM_CPCR2_CBCS_SHIFT                     (4U)
/*! CBCS - Code Bus Cache Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define MCM_CPCR2_CBCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CBCS_SHIFT)) & MCM_CPCR2_CBCS_MASK)

#define MCM_CPCR2_PCCMCTRL_MASK                  (0x10000U)
#define MCM_CPCR2_PCCMCTRL_SHIFT                 (16U)
/*! PCCMCTRL - Bypass Fixed Code Cache Map
 *  0b0..Do not bypass
 *  0b1..Bypass
 */
#define MCM_CPCR2_PCCMCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_PCCMCTRL_SHIFT)) & MCM_CPCR2_PCCMCTRL_MASK)

#define MCM_CPCR2_LCCPWB_MASK                    (0x20000U)
#define MCM_CPCR2_LCCPWB_SHIFT                   (17U)
/*! LCCPWB - Limit Code Cache Peripheral Write Buffering
 *  0b0..Do not limit
 *  0b1..Limit
 */
#define MCM_CPCR2_LCCPWB(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_LCCPWB_SHIFT)) & MCM_CPCR2_LCCPWB_MASK)
/*! @} */

/*! @name LMDR2 - Local Memory Descriptor 2 */
/*! @{ */

#define MCM_LMDR2_MT_MASK                        (0xE000U)
#define MCM_LMDR2_MT_SHIFT                       (13U)
/*! MT - Memory Type
 *  0b000..SRAM_Lower
 *  0b001..SRAM_Upper
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define MCM_LMDR2_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_MT_SHIFT)) & MCM_LMDR2_MT_MASK)

#define MCM_LMDR2_RO_MASK                        (0x10000U)
#define MCM_LMDR2_RO_SHIFT                       (16U)
/*! RO - Read-Only
 *  0b0..Writes allowed
 *  0b1..Writes ignored
 */
#define MCM_LMDR2_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_RO_SHIFT)) & MCM_LMDR2_RO_MASK)

#define MCM_LMDR2_DPW_MASK                       (0xE0000U)
#define MCM_LMDR2_DPW_SHIFT                      (17U)
/*! DPW - LMEM Data Path Width
 *  0b000-0b001..
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100-0b111..
 */
#define MCM_LMDR2_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_DPW_SHIFT)) & MCM_LMDR2_DPW_MASK)

#define MCM_LMDR2_WY_MASK                        (0xF00000U)
#define MCM_LMDR2_WY_SHIFT                       (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No cache
 *  0b0010..2-way set associative
 *  0b0100..4-way set associative
 *  0b1000..8-way set associative
 */
#define MCM_LMDR2_WY(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_WY_SHIFT)) & MCM_LMDR2_WY_MASK)

#define MCM_LMDR2_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR2_LMSZ_SHIFT                     (24U)
/*! LMSZ - LMEM Size
 *  0b0000..No memory
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 *  0b0111..64 KB
 *  0b1000..128 KB
 *  0b1001..256 KB
 *  0b1010..512 KB
 *  0b1011..1024 KB
 *  0b1100..2048 KB
 *  0b1101..4096 KB
 *  0b1110..8192 KB
 *  0b1111..16384 KB
 */
#define MCM_LMDR2_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZ_SHIFT)) & MCM_LMDR2_LMSZ_MASK)

#define MCM_LMDR2_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR2_LMSZH_SHIFT                    (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEM has a power-of-2 capacity
 *  0b1..LMEM has a capacity of 0.75 * LMSZ
 */
#define MCM_LMDR2_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZH_SHIFT)) & MCM_LMDR2_LMSZH_MASK)

#define MCM_LMDR2_V_MASK                         (0x80000000U)
#define MCM_LMDR2_V_SHIFT                        (31U)
/*! V - Valid
 *  0b0..Not present
 *  0b1..Present
 */
#define MCM_LMDR2_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_V_SHIFT)) & MCM_LMDR2_V_MASK)
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

