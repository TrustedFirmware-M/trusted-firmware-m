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
**         CMSIS Peripheral Access Layer for PPB_MCM2_CM4
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
 * @file PERI_PPB_MCM2_CM4.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for PPB_MCM2_CM4
 *
 * CMSIS Peripheral Access Layer for PPB_MCM2_CM4
 */

#if !defined(PERI_PPB_MCM2_CM4_H_)
#define PERI_PPB_MCM2_CM4_H_                     /**< Symbol preventing repeated inclusion */

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
   -- PPB_MCM2_CM4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PPB_MCM2_CM4_Peripheral_Access_Layer PPB_MCM2_CM4 Peripheral Access Layer
 * @{
 */

/** PPB_MCM2_CM4 - Register Layout Typedef */
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
} PPB_MCM2_CM4_Type;

/* ----------------------------------------------------------------------------
   -- PPB_MCM2_CM4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PPB_MCM2_CM4_Register_Masks PPB_MCM2_CM4 Register Masks
 * @{
 */

/*! @name ISCR - Interrupt Status and Control */
/*! @{ */

#define PPB_MCM2_CM4_ISCR_CWBER_MASK             (0x10U)
#define PPB_MCM2_CM4_ISCR_CWBER_SHIFT            (4U)
/*! CWBER - Cache Write Buffer Error Status
 *  0b0..No error
 *  0b1..Error occurred
 */
#define PPB_MCM2_CM4_ISCR_CWBER(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_CWBER_SHIFT)) & PPB_MCM2_CM4_ISCR_CWBER_MASK)

#define PPB_MCM2_CM4_ISCR_FIOC_MASK              (0x100U)
#define PPB_MCM2_CM4_ISCR_FIOC_SHIFT             (8U)
/*! FIOC - FPU Invalid Operation Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define PPB_MCM2_CM4_ISCR_FIOC(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FIOC_SHIFT)) & PPB_MCM2_CM4_ISCR_FIOC_MASK)

#define PPB_MCM2_CM4_ISCR_FDZC_MASK              (0x200U)
#define PPB_MCM2_CM4_ISCR_FDZC_SHIFT             (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define PPB_MCM2_CM4_ISCR_FDZC(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FDZC_SHIFT)) & PPB_MCM2_CM4_ISCR_FDZC_MASK)

#define PPB_MCM2_CM4_ISCR_FOFC_MASK              (0x400U)
#define PPB_MCM2_CM4_ISCR_FOFC_SHIFT             (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define PPB_MCM2_CM4_ISCR_FOFC(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FOFC_SHIFT)) & PPB_MCM2_CM4_ISCR_FOFC_MASK)

#define PPB_MCM2_CM4_ISCR_FUFC_MASK              (0x800U)
#define PPB_MCM2_CM4_ISCR_FUFC_SHIFT             (11U)
/*! FUFC - FPU Underflow Interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define PPB_MCM2_CM4_ISCR_FUFC(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FUFC_SHIFT)) & PPB_MCM2_CM4_ISCR_FUFC_MASK)

#define PPB_MCM2_CM4_ISCR_FIXC_MASK              (0x1000U)
#define PPB_MCM2_CM4_ISCR_FIXC_SHIFT             (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define PPB_MCM2_CM4_ISCR_FIXC(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FIXC_SHIFT)) & PPB_MCM2_CM4_ISCR_FIXC_MASK)

#define PPB_MCM2_CM4_ISCR_FIDC_MASK              (0x8000U)
#define PPB_MCM2_CM4_ISCR_FIDC_SHIFT             (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define PPB_MCM2_CM4_ISCR_FIDC(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FIDC_SHIFT)) & PPB_MCM2_CM4_ISCR_FIDC_MASK)

#define PPB_MCM2_CM4_ISCR_CWBEE_MASK             (0x100000U)
#define PPB_MCM2_CM4_ISCR_CWBEE_SHIFT            (20U)
/*! CWBEE - Cache Write Buffer Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PPB_MCM2_CM4_ISCR_CWBEE(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_CWBEE_SHIFT)) & PPB_MCM2_CM4_ISCR_CWBEE_MASK)

#define PPB_MCM2_CM4_ISCR_FIOCE_MASK             (0x1000000U)
#define PPB_MCM2_CM4_ISCR_FIOCE_SHIFT            (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PPB_MCM2_CM4_ISCR_FIOCE(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FIOCE_SHIFT)) & PPB_MCM2_CM4_ISCR_FIOCE_MASK)

#define PPB_MCM2_CM4_ISCR_FDZCE_MASK             (0x2000000U)
#define PPB_MCM2_CM4_ISCR_FDZCE_SHIFT            (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PPB_MCM2_CM4_ISCR_FDZCE(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FDZCE_SHIFT)) & PPB_MCM2_CM4_ISCR_FDZCE_MASK)

#define PPB_MCM2_CM4_ISCR_FOFCE_MASK             (0x4000000U)
#define PPB_MCM2_CM4_ISCR_FOFCE_SHIFT            (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PPB_MCM2_CM4_ISCR_FOFCE(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FOFCE_SHIFT)) & PPB_MCM2_CM4_ISCR_FOFCE_MASK)

#define PPB_MCM2_CM4_ISCR_FUFCE_MASK             (0x8000000U)
#define PPB_MCM2_CM4_ISCR_FUFCE_SHIFT            (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PPB_MCM2_CM4_ISCR_FUFCE(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FUFCE_SHIFT)) & PPB_MCM2_CM4_ISCR_FUFCE_MASK)

#define PPB_MCM2_CM4_ISCR_FIXCE_MASK             (0x10000000U)
#define PPB_MCM2_CM4_ISCR_FIXCE_SHIFT            (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PPB_MCM2_CM4_ISCR_FIXCE(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FIXCE_SHIFT)) & PPB_MCM2_CM4_ISCR_FIXCE_MASK)

#define PPB_MCM2_CM4_ISCR_FIDCE_MASK             (0x80000000U)
#define PPB_MCM2_CM4_ISCR_FIDCE_SHIFT            (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PPB_MCM2_CM4_ISCR_FIDCE(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_ISCR_FIDCE_SHIFT)) & PPB_MCM2_CM4_ISCR_FIDCE_MASK)
/*! @} */

/*! @name FADR - Write Buffer Fault Address */
/*! @{ */

#define PPB_MCM2_CM4_FADR_ADDRESS_MASK           (0xFFFFFFFFU)
#define PPB_MCM2_CM4_FADR_ADDRESS_SHIFT          (0U)
/*! ADDRESS - Fault Address */
#define PPB_MCM2_CM4_FADR_ADDRESS(x)             (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FADR_ADDRESS_SHIFT)) & PPB_MCM2_CM4_FADR_ADDRESS_MASK)
/*! @} */

/*! @name FATR - Store Buffer Fault Attributes */
/*! @{ */

#define PPB_MCM2_CM4_FATR_BEDA_MASK              (0x1U)
#define PPB_MCM2_CM4_FATR_BEDA_SHIFT             (0U)
/*! BEDA - Bus Error Data Access Type
 *  0b0..Instruction
 *  0b1..Data
 */
#define PPB_MCM2_CM4_FATR_BEDA(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FATR_BEDA_SHIFT)) & PPB_MCM2_CM4_FATR_BEDA_MASK)

#define PPB_MCM2_CM4_FATR_BEMD_MASK              (0x2U)
#define PPB_MCM2_CM4_FATR_BEMD_SHIFT             (1U)
/*! BEMD - Bus Error Privilege Level
 *  0b0..User mode
 *  0b1..Supervisor or privileged mode
 */
#define PPB_MCM2_CM4_FATR_BEMD(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FATR_BEMD_SHIFT)) & PPB_MCM2_CM4_FATR_BEMD_MASK)

#define PPB_MCM2_CM4_FATR_BESZ_MASK              (0x30U)
#define PPB_MCM2_CM4_FATR_BESZ_SHIFT             (4U)
/*! BESZ - Bus Error Size
 *  0b00..8-bit
 *  0b01..16-bit
 *  0b10..32-bit
 *  0b11..
 */
#define PPB_MCM2_CM4_FATR_BESZ(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FATR_BESZ_SHIFT)) & PPB_MCM2_CM4_FATR_BESZ_MASK)

#define PPB_MCM2_CM4_FATR_BEWT_MASK              (0x80U)
#define PPB_MCM2_CM4_FATR_BEWT_SHIFT             (7U)
/*! BEWT - Bus Error Write
 *  0b0..Read
 *  0b1..Write
 */
#define PPB_MCM2_CM4_FATR_BEWT(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FATR_BEWT_SHIFT)) & PPB_MCM2_CM4_FATR_BEWT_MASK)

#define PPB_MCM2_CM4_FATR_BEMN_MASK              (0xF00U)
#define PPB_MCM2_CM4_FATR_BEMN_SHIFT             (8U)
/*! BEMN - Bus Error Initiator Number */
#define PPB_MCM2_CM4_FATR_BEMN(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FATR_BEMN_SHIFT)) & PPB_MCM2_CM4_FATR_BEMN_MASK)

#define PPB_MCM2_CM4_FATR_BEOVR_MASK             (0x80000000U)
#define PPB_MCM2_CM4_FATR_BEOVR_SHIFT            (31U)
/*! BEOVR - Bus Error Overrun
 *  0b0..No overrun
 *  0b1..Overrun
 */
#define PPB_MCM2_CM4_FATR_BEOVR(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FATR_BEOVR_SHIFT)) & PPB_MCM2_CM4_FATR_BEOVR_MASK)
/*! @} */

/*! @name FDR - Store Buffer Fault Data */
/*! @{ */

#define PPB_MCM2_CM4_FDR_DATA_MASK               (0xFFFFFFFFU)
#define PPB_MCM2_CM4_FDR_DATA_SHIFT              (0U)
/*! DATA - Fault Data */
#define PPB_MCM2_CM4_FDR_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_FDR_DATA_SHIFT)) & PPB_MCM2_CM4_FDR_DATA_MASK)
/*! @} */

/*! @name CPCR2 - Core Platform Control 2 */
/*! @{ */

#define PPB_MCM2_CM4_CPCR2_CCBC_MASK             (0x1U)
#define PPB_MCM2_CM4_CPCR2_CCBC_SHIFT            (0U)
/*! CCBC - Clear Code Bus Cache
 *  0b0..No effect
 *  0b1..Clear code bus cache
 */
#define PPB_MCM2_CM4_CPCR2_CCBC(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_CPCR2_CCBC_SHIFT)) & PPB_MCM2_CM4_CPCR2_CCBC_MASK)

#define PPB_MCM2_CM4_CPCR2_DCCWB_MASK            (0x2U)
#define PPB_MCM2_CM4_CPCR2_DCCWB_SHIFT           (1U)
/*! DCCWB - Disable Code Cache Write Buffer
 *  0b0..Enable
 *  0b1..Disable
 */
#define PPB_MCM2_CM4_CPCR2_DCCWB(x)              (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_CPCR2_DCCWB_SHIFT)) & PPB_MCM2_CM4_CPCR2_DCCWB_MASK)

#define PPB_MCM2_CM4_CPCR2_FCCNA_MASK            (0x4U)
#define PPB_MCM2_CM4_CPCR2_FCCNA_SHIFT           (2U)
/*! FCCNA - Force Code Cache to No Allocation
 *  0b0..Allocation
 *  0b1..No allocation
 */
#define PPB_MCM2_CM4_CPCR2_FCCNA(x)              (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_CPCR2_FCCNA_SHIFT)) & PPB_MCM2_CM4_CPCR2_FCCNA_MASK)

#define PPB_MCM2_CM4_CPCR2_DCBC_MASK             (0x8U)
#define PPB_MCM2_CM4_CPCR2_DCBC_SHIFT            (3U)
/*! DCBC - Disable Code Bus Cache
 *  0b0..Enable
 *  0b1..Disable
 */
#define PPB_MCM2_CM4_CPCR2_DCBC(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_CPCR2_DCBC_SHIFT)) & PPB_MCM2_CM4_CPCR2_DCBC_MASK)

#define PPB_MCM2_CM4_CPCR2_CBCS_MASK             (0xF0U)
#define PPB_MCM2_CM4_CPCR2_CBCS_SHIFT            (4U)
/*! CBCS - Code Bus Cache Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define PPB_MCM2_CM4_CPCR2_CBCS(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_CPCR2_CBCS_SHIFT)) & PPB_MCM2_CM4_CPCR2_CBCS_MASK)

#define PPB_MCM2_CM4_CPCR2_PCCMCTRL_MASK         (0x10000U)
#define PPB_MCM2_CM4_CPCR2_PCCMCTRL_SHIFT        (16U)
/*! PCCMCTRL - Bypass Fixed Code Cache Map
 *  0b0..Do not bypass
 *  0b1..Bypass
 */
#define PPB_MCM2_CM4_CPCR2_PCCMCTRL(x)           (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_CPCR2_PCCMCTRL_SHIFT)) & PPB_MCM2_CM4_CPCR2_PCCMCTRL_MASK)

#define PPB_MCM2_CM4_CPCR2_LCCPWB_MASK           (0x20000U)
#define PPB_MCM2_CM4_CPCR2_LCCPWB_SHIFT          (17U)
/*! LCCPWB - Limit Code Cache Peripheral Write Buffering
 *  0b0..Do not limit
 *  0b1..Limit
 */
#define PPB_MCM2_CM4_CPCR2_LCCPWB(x)             (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_CPCR2_LCCPWB_SHIFT)) & PPB_MCM2_CM4_CPCR2_LCCPWB_MASK)
/*! @} */

/*! @name LMDR2 - Local Memory Descriptor 2 */
/*! @{ */

#define PPB_MCM2_CM4_LMDR2_MT_MASK               (0xE000U)
#define PPB_MCM2_CM4_LMDR2_MT_SHIFT              (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define PPB_MCM2_CM4_LMDR2_MT(x)                 (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_LMDR2_MT_SHIFT)) & PPB_MCM2_CM4_LMDR2_MT_MASK)

#define PPB_MCM2_CM4_LMDR2_RO_MASK               (0x10000U)
#define PPB_MCM2_CM4_LMDR2_RO_SHIFT              (16U)
/*! RO - Read-Only
 *  0b0..Writes allowed
 *  0b1..Writes ignored
 */
#define PPB_MCM2_CM4_LMDR2_RO(x)                 (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_LMDR2_RO_SHIFT)) & PPB_MCM2_CM4_LMDR2_RO_MASK)

#define PPB_MCM2_CM4_LMDR2_DPW_MASK              (0xE0000U)
#define PPB_MCM2_CM4_LMDR2_DPW_SHIFT             (17U)
/*! DPW - LMEM Data Path Width
 *  0b000-0b001..
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100-0b111..
 */
#define PPB_MCM2_CM4_LMDR2_DPW(x)                (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_LMDR2_DPW_SHIFT)) & PPB_MCM2_CM4_LMDR2_DPW_MASK)

#define PPB_MCM2_CM4_LMDR2_WY_MASK               (0xF00000U)
#define PPB_MCM2_CM4_LMDR2_WY_SHIFT              (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No cache
 *  0b0010..2-way set associative
 *  0b0100..4-way set associative
 *  0b1000..8-way set associative
 */
#define PPB_MCM2_CM4_LMDR2_WY(x)                 (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_LMDR2_WY_SHIFT)) & PPB_MCM2_CM4_LMDR2_WY_MASK)

#define PPB_MCM2_CM4_LMDR2_LMSZ_MASK             (0xF000000U)
#define PPB_MCM2_CM4_LMDR2_LMSZ_SHIFT            (24U)
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
#define PPB_MCM2_CM4_LMDR2_LMSZ(x)               (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_LMDR2_LMSZ_SHIFT)) & PPB_MCM2_CM4_LMDR2_LMSZ_MASK)

#define PPB_MCM2_CM4_LMDR2_LMSZH_MASK            (0x10000000U)
#define PPB_MCM2_CM4_LMDR2_LMSZH_SHIFT           (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEM has a power-of-2 capacity
 *  0b1..LMEM has a capacity of 0.75 * LMSZ
 */
#define PPB_MCM2_CM4_LMDR2_LMSZH(x)              (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_LMDR2_LMSZH_SHIFT)) & PPB_MCM2_CM4_LMDR2_LMSZH_MASK)

#define PPB_MCM2_CM4_LMDR2_V_MASK                (0x80000000U)
#define PPB_MCM2_CM4_LMDR2_V_SHIFT               (31U)
/*! V - Valid
 *  0b0..Not present
 *  0b1..Present
 */
#define PPB_MCM2_CM4_LMDR2_V(x)                  (((uint32_t)(((uint32_t)(x)) << PPB_MCM2_CM4_LMDR2_V_SHIFT)) & PPB_MCM2_CM4_LMDR2_V_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PPB_MCM2_CM4_Register_Masks */


/*!
 * @}
 */ /* end of group PPB_MCM2_CM4_Peripheral_Access_Layer */


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


#endif  /* PERI_PPB_MCM2_CM4_H_ */

