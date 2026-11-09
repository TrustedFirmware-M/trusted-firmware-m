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
**         CMSIS Peripheral Access Layer for SYSCON
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
 * @file PERI_SYSCON.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for SYSCON
 *
 * CMSIS Peripheral Access Layer for SYSCON
 */

#if !defined(PERI_SYSCON_H_)
#define PERI_SYSCON_H_                           /**< Symbol preventing repeated inclusion */

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
   -- SYSCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Peripheral_Access_Layer SYSCON Peripheral Access Layer
 * @{
 */

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t CPU1_CACHE_ISCR;                   /**< CPU1 Cache Interrupt Status and Control, offset: 0x0 */
  __I  uint32_t CPU1_CACHE_FADR;                   /**< Write Buffer Fault Address, offset: 0x4 */
  __I  uint32_t CPU1_CACHE_FATR;                   /**< Store Buffer Fault Attributes, offset: 0x8 */
  __I  uint32_t CPU1_CACHE_FDR;                    /**< Store Buffer Fault Data, offset: 0xC */
  __IO uint32_t CPU1_CACHE_CPCR2;                  /**< Core Platform Control 2, offset: 0x10 */
  __IO uint32_t CPU1_CACHE_LMDR;                   /**< CPU1_CACHE_LMDR, offset: 0x14 */
       uint8_t RESERVED_0[24];
  __IO uint32_t CPU1_WAIT;                         /**< CPU1 Wait, offset: 0x30 */
  __IO uint32_t CPU1_AHB_TIMEOUT;                  /**< CPU1 AHB Matrix TimeOut, offset: 0x34 */
  __IO uint32_t PKC_RAM_CG_CTRL;                   /**< PKC RAM clock control, offset: 0x38 */
  __IO uint32_t RAM_CG_CTRL;                       /**< System RAM clock control, offset: 0x3C */
  __IO uint32_t RAM_REMAP_CTRL;                    /**< System RAM Remap Control, offset: 0x40 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SCG_LP_ENABLE;                     /**< System Clock Generator Low Power Enable, offset: 0x48 */
  __IO uint32_t ZENV_CTRL;                         /**< ZENV CORE Initial Vector Set, offset: 0x4C */
  __IO uint32_t ZENV_RESET_CTRL;                   /**< ZENV CORE Reset Controller, offset: 0x50 */
  __I  uint32_t JTAG_ID;                           /**< JTAG Chip ID, offset: 0x54 */
  __I  uint32_t DEVICE_TYPE;                       /**< Device Type, offset: 0x58 */
  __I  uint32_t DEVICE_ID;                         /**< Device ID, offset: 0x5C */
  __I  uint32_t DIEID;                             /**< Chip Revision ID and Number, offset: 0x60 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SWD_ID;                            /**< Serial Wire Debug ID, offset: 0x68 */
  __I  uint32_t OEM_TYPE;                          /**< OEM Type, offset: 0x6C */
  __IO uint32_t PWM_SUBCTL;                        /**< PWM Sub-system Control, offset: 0x70 */
  __IO uint32_t FMC1_CTRL;                         /**< Control for Flash Memory Controller 1, offset: 0x74 */
  __IO uint32_t DMA_RF_WAKE_MAIN_0;                /**< DMA request 0-31 to wake up main domain, offset: 0x78 */
  __IO uint32_t DMA_RF_WAKE_MAIN_1;                /**< DMA request 32-63 to wake up main domain, offset: 0x7C */
  __IO uint32_t CAN_20MHZ_CLOCK_CTRL;              /**< Flexcan 20MHZ Clock Control, offset: 0x80 */
  __IO uint32_t SRAM0_ECC_CONTROL;                 /**< SRAM0 ECC Function Control, offset: 0x84 */
  __IO uint32_t SRAM0_ECC_REPORT;                  /**< SRAM0 ECC Error Report Control, offset: 0x88 */
  __IO uint32_t SRAM0_ECC_EVENT_RECORD;            /**< SRAM0 ECC Error Event Record, offset: 0x8C */
  __I  uint32_t SRAM0_ECC_FAULT_ADDR;              /**< SRAM0 Fault Address Register, offset: 0x90 */
  __I  uint32_t SRAM0_ECC_FAULT_ATTR;              /**< SRAM0 Fault Attribute Register, offset: 0x94 */
  __I  uint32_t SRAM0_ECC_FAULT_DATA;              /**< SRAM0 ECC Fault Data Low Register, offset: 0x98 */
  __IO uint32_t MATRIX_MODE_CTRL;                  /**< Matrix Mode Control, offset: 0x9C */
       uint8_t RESERVED_3[96];
  __IO uint32_t FMC_CG_CTRL;                       /**< Clock Gating Ctrl of Flash Memory Control, offset: 0x100 */
  __IO uint32_t FMC0_CTRL;                         /**< Control for Flash Memory Controller 0, offset: 0x104 */
  __IO uint32_t CPU1_ACCESS_CTRL;                  /**< CPU1 Access Control, offset: 0x108 */
       uint8_t RESERVED_4[244];
  __IO uint32_t GENERAL_REG_0;                     /**< General Register 0, offset: 0x200 */
  __IO uint32_t GENERAL_REG_1;                     /**< General Register 1, offset: 0x204 */
  __IO uint32_t GENERAL_REG_2;                     /**< General Register 2, offset: 0x208 */
  __IO uint32_t GENERAL_REG_3;                     /**< General Register 3, offset: 0x20C */
       uint8_t RESERVED_5[3312];
  __IO uint32_t AUTHENTICATE;                      /**< Protect SYSCON registers from unintentional writes, offset: 0xF00 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name CPU1_CACHE_ISCR - CPU1 Cache Interrupt Status and Control */
/*! @{ */

#define SYSCON_CPU1_CACHE_ISCR_CWBER_MASK        (0x10U)
#define SYSCON_CPU1_CACHE_ISCR_CWBER_SHIFT       (4U)
/*! CWBER - Cache Write Buffer Error Status
 *  0b0..No error
 *  0b1..Error occurred
 */
#define SYSCON_CPU1_CACHE_ISCR_CWBER(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_ISCR_CWBER_SHIFT)) & SYSCON_CPU1_CACHE_ISCR_CWBER_MASK)

#define SYSCON_CPU1_CACHE_ISCR_CWBEE_MASK        (0x100000U)
#define SYSCON_CPU1_CACHE_ISCR_CWBEE_SHIFT       (20U)
/*! CWBEE - Cache Write Buffer Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CPU1_CACHE_ISCR_CWBEE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_ISCR_CWBEE_SHIFT)) & SYSCON_CPU1_CACHE_ISCR_CWBEE_MASK)
/*! @} */

/*! @name CPU1_CACHE_FADR - Write Buffer Fault Address */
/*! @{ */

#define SYSCON_CPU1_CACHE_FADR_ADDRESS_MASK      (0xFFFFFFFFU)
#define SYSCON_CPU1_CACHE_FADR_ADDRESS_SHIFT     (0U)
/*! ADDRESS - Write Buffer Fault Address */
#define SYSCON_CPU1_CACHE_FADR_ADDRESS(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FADR_ADDRESS_SHIFT)) & SYSCON_CPU1_CACHE_FADR_ADDRESS_MASK)
/*! @} */

/*! @name CPU1_CACHE_FATR - Store Buffer Fault Attributes */
/*! @{ */

#define SYSCON_CPU1_CACHE_FATR_BEDA_MASK         (0x1U)
#define SYSCON_CPU1_CACHE_FATR_BEDA_SHIFT        (0U)
/*! BEDA - Bus Error Data Access Type
 *  0b0..Instruction
 *  0b1..Data
 */
#define SYSCON_CPU1_CACHE_FATR_BEDA(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FATR_BEDA_SHIFT)) & SYSCON_CPU1_CACHE_FATR_BEDA_MASK)

#define SYSCON_CPU1_CACHE_FATR_BEMD_MASK         (0x2U)
#define SYSCON_CPU1_CACHE_FATR_BEMD_SHIFT        (1U)
/*! BEMD - Bus Error Privilege Level
 *  0b0..User mode
 *  0b1..Supervisor or privileged mode
 */
#define SYSCON_CPU1_CACHE_FATR_BEMD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FATR_BEMD_SHIFT)) & SYSCON_CPU1_CACHE_FATR_BEMD_MASK)

#define SYSCON_CPU1_CACHE_FATR_BESZ_MASK         (0x30U)
#define SYSCON_CPU1_CACHE_FATR_BESZ_SHIFT        (4U)
/*! BESZ - Bus Error Size
 *  0b00..8-bit
 *  0b01..16-bit
 *  0b10..32-bit
 *  0b11..Reserved
 */
#define SYSCON_CPU1_CACHE_FATR_BESZ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FATR_BESZ_SHIFT)) & SYSCON_CPU1_CACHE_FATR_BESZ_MASK)

#define SYSCON_CPU1_CACHE_FATR_BEWT_MASK         (0x80U)
#define SYSCON_CPU1_CACHE_FATR_BEWT_SHIFT        (7U)
/*! BEWT - Bus Error Write
 *  0b0..Read
 *  0b1..Write
 */
#define SYSCON_CPU1_CACHE_FATR_BEWT(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FATR_BEWT_SHIFT)) & SYSCON_CPU1_CACHE_FATR_BEWT_MASK)

#define SYSCON_CPU1_CACHE_FATR_BEMN_MASK         (0xF00U)
#define SYSCON_CPU1_CACHE_FATR_BEMN_SHIFT        (8U)
/*! BEMN - Bus Error Master Number */
#define SYSCON_CPU1_CACHE_FATR_BEMN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FATR_BEMN_SHIFT)) & SYSCON_CPU1_CACHE_FATR_BEMN_MASK)

#define SYSCON_CPU1_CACHE_FATR_BEOVR_MASK        (0x80000000U)
#define SYSCON_CPU1_CACHE_FATR_BEOVR_SHIFT       (31U)
/*! BEOVR - Bus Error Overrun
 *  0b0..No overrun
 *  0b1..Overrun
 */
#define SYSCON_CPU1_CACHE_FATR_BEOVR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FATR_BEOVR_SHIFT)) & SYSCON_CPU1_CACHE_FATR_BEOVR_MASK)
/*! @} */

/*! @name CPU1_CACHE_FDR - Store Buffer Fault Data */
/*! @{ */

#define SYSCON_CPU1_CACHE_FDR_BFD_MASK           (0xFFFFFFFFU)
#define SYSCON_CPU1_CACHE_FDR_BFD_SHIFT          (0U)
/*! BFD - Fault Data */
#define SYSCON_CPU1_CACHE_FDR_BFD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_FDR_BFD_SHIFT)) & SYSCON_CPU1_CACHE_FDR_BFD_MASK)
/*! @} */

/*! @name CPU1_CACHE_CPCR2 - Core Platform Control 2 */
/*! @{ */

#define SYSCON_CPU1_CACHE_CPCR2_CCBC_MASK        (0x1U)
#define SYSCON_CPU1_CACHE_CPCR2_CCBC_SHIFT       (0U)
/*! CCBC - Clear Code Bus Cache
 *  0b0..No effect
 *  0b1..Clear code bus cache
 */
#define SYSCON_CPU1_CACHE_CPCR2_CCBC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_CPCR2_CCBC_SHIFT)) & SYSCON_CPU1_CACHE_CPCR2_CCBC_MASK)

#define SYSCON_CPU1_CACHE_CPCR2_DCCWB_MASK       (0x2U)
#define SYSCON_CPU1_CACHE_CPCR2_DCCWB_SHIFT      (1U)
/*! DCCWB - Disable Code Cache Write Buffer
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCON_CPU1_CACHE_CPCR2_DCCWB(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_CPCR2_DCCWB_SHIFT)) & SYSCON_CPU1_CACHE_CPCR2_DCCWB_MASK)

#define SYSCON_CPU1_CACHE_CPCR2_FCCNA_MASK       (0x4U)
#define SYSCON_CPU1_CACHE_CPCR2_FCCNA_SHIFT      (2U)
/*! FCCNA - Force Code Cache to No Allocation
 *  0b0..Allocation
 *  0b1..No allocation
 */
#define SYSCON_CPU1_CACHE_CPCR2_FCCNA(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_CPCR2_FCCNA_SHIFT)) & SYSCON_CPU1_CACHE_CPCR2_FCCNA_MASK)

#define SYSCON_CPU1_CACHE_CPCR2_DCBC_MASK        (0x8U)
#define SYSCON_CPU1_CACHE_CPCR2_DCBC_SHIFT       (3U)
/*! DCBC - Disable Code Bus Cache
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCON_CPU1_CACHE_CPCR2_DCBC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_CPCR2_DCBC_SHIFT)) & SYSCON_CPU1_CACHE_CPCR2_DCBC_MASK)

#define SYSCON_CPU1_CACHE_CPCR2_CBCS_MASK        (0xF0U)
#define SYSCON_CPU1_CACHE_CPCR2_CBCS_SHIFT       (4U)
/*! CBCS - Code Bus Cache Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define SYSCON_CPU1_CACHE_CPCR2_CBCS(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_CPCR2_CBCS_SHIFT)) & SYSCON_CPU1_CACHE_CPCR2_CBCS_MASK)

#define SYSCON_CPU1_CACHE_CPCR2_PCCMCTRL_MASK    (0x10000U)
#define SYSCON_CPU1_CACHE_CPCR2_PCCMCTRL_SHIFT   (16U)
/*! PCCMCTRL - Bypass Fixed Code Cache Map
 *  0b0..Do not bypass
 *  0b1..Bypass
 */
#define SYSCON_CPU1_CACHE_CPCR2_PCCMCTRL(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_CPCR2_PCCMCTRL_SHIFT)) & SYSCON_CPU1_CACHE_CPCR2_PCCMCTRL_MASK)

#define SYSCON_CPU1_CACHE_CPCR2_LCCPWB_MASK      (0x20000U)
#define SYSCON_CPU1_CACHE_CPCR2_LCCPWB_SHIFT     (17U)
/*! LCCPWB - Limit Code Cache Peripheral Write Buffering
 *  0b0..Do not limit
 *  0b1..Limit
 */
#define SYSCON_CPU1_CACHE_CPCR2_LCCPWB(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_CPCR2_LCCPWB_SHIFT)) & SYSCON_CPU1_CACHE_CPCR2_LCCPWB_MASK)
/*! @} */

/*! @name CPU1_CACHE_LMDR - CPU1_CACHE_LMDR */
/*! @{ */

#define SYSCON_CPU1_CACHE_LMDR_MT_MASK           (0xE000U)
#define SYSCON_CPU1_CACHE_LMDR_MT_SHIFT          (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define SYSCON_CPU1_CACHE_LMDR_MT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_LMDR_MT_SHIFT)) & SYSCON_CPU1_CACHE_LMDR_MT_MASK)

#define SYSCON_CPU1_CACHE_LMDR_RO_MASK           (0x10000U)
#define SYSCON_CPU1_CACHE_LMDR_RO_SHIFT          (16U)
/*! RO - Read-Only
 *  0b0..Writes allowed
 *  0b1..Writes ignored
 */
#define SYSCON_CPU1_CACHE_LMDR_RO(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_LMDR_RO_SHIFT)) & SYSCON_CPU1_CACHE_LMDR_RO_MASK)

#define SYSCON_CPU1_CACHE_LMDR_DPW_MASK          (0xE0000U)
#define SYSCON_CPU1_CACHE_LMDR_DPW_SHIFT         (17U)
/*! DPW - LMEM Data Path Width
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100..Reserved
 *  0b111..Reserved
 */
#define SYSCON_CPU1_CACHE_LMDR_DPW(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_LMDR_DPW_SHIFT)) & SYSCON_CPU1_CACHE_LMDR_DPW_MASK)

#define SYSCON_CPU1_CACHE_LMDR_WY_MASK           (0xF00000U)
#define SYSCON_CPU1_CACHE_LMDR_WY_SHIFT          (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No cache
 *  0b0010..2-way set associative
 *  0b0100..4-way set associative
 *  0b1000..8-way set associative
 */
#define SYSCON_CPU1_CACHE_LMDR_WY(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_LMDR_WY_SHIFT)) & SYSCON_CPU1_CACHE_LMDR_WY_MASK)

#define SYSCON_CPU1_CACHE_LMDR_LMSZ_MASK         (0xF000000U)
#define SYSCON_CPU1_CACHE_LMDR_LMSZ_SHIFT        (24U)
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
#define SYSCON_CPU1_CACHE_LMDR_LMSZ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_LMDR_LMSZ_SHIFT)) & SYSCON_CPU1_CACHE_LMDR_LMSZ_MASK)

#define SYSCON_CPU1_CACHE_LMDR_LMSZH_MASK        (0x10000000U)
#define SYSCON_CPU1_CACHE_LMDR_LMSZH_SHIFT       (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEM has a power-of-2 capacity
 *  0b1..LMEM has a capacity of 0.75 * LMSZ
 */
#define SYSCON_CPU1_CACHE_LMDR_LMSZH(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_LMDR_LMSZH_SHIFT)) & SYSCON_CPU1_CACHE_LMDR_LMSZH_MASK)

#define SYSCON_CPU1_CACHE_LMDR_V_MASK            (0x80000000U)
#define SYSCON_CPU1_CACHE_LMDR_V_SHIFT           (31U)
/*! V - Valid
 *  0b0..Not present
 *  0b1..Present
 */
#define SYSCON_CPU1_CACHE_LMDR_V(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_CACHE_LMDR_V_SHIFT)) & SYSCON_CPU1_CACHE_LMDR_V_MASK)
/*! @} */

/*! @name CPU1_WAIT - CPU1 Wait */
/*! @{ */

#define SYSCON_CPU1_WAIT_cpu1_wait_control_MASK  (0xFU)
#define SYSCON_CPU1_WAIT_cpu1_wait_control_SHIFT (0U)
/*! cpu1_wait_control - CPU1 Wait Control
 *  0b1010..Enable CPU1 Wait, any other value will disable CPU1 Wait
 */
#define SYSCON_CPU1_WAIT_cpu1_wait_control(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_WAIT_cpu1_wait_control_SHIFT)) & SYSCON_CPU1_WAIT_cpu1_wait_control_MASK)
/*! @} */

/*! @name CPU1_AHB_TIMEOUT - CPU1 AHB Matrix TimeOut */
/*! @{ */

#define SYSCON_CPU1_AHB_TIMEOUT_ahb_timeout_cycle_MASK (0x3U)
#define SYSCON_CPU1_AHB_TIMEOUT_ahb_timeout_cycle_SHIFT (0U)
/*! ahb_timeout_cycle - CPU1_AHB_TIMEOUT [2:0]: counter value; */
#define SYSCON_CPU1_AHB_TIMEOUT_ahb_timeout_cycle(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_AHB_TIMEOUT_ahb_timeout_cycle_SHIFT)) & SYSCON_CPU1_AHB_TIMEOUT_ahb_timeout_cycle_MASK)
/*! @} */

/*! @name PKC_RAM_CG_CTRL - PKC RAM clock control */
/*! @{ */

#define SYSCON_PKC_RAM_CG_CTRL_PKC_RAM_CG_AUTO_DIS_MASK (0x1U)
#define SYSCON_PKC_RAM_CG_CTRL_PKC_RAM_CG_AUTO_DIS_SHIFT (0U)
/*! PKC_RAM_CG_AUTO_DIS - PKC RAM clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_PKC_RAM_CG_CTRL_PKC_RAM_CG_AUTO_DIS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_PKC_RAM_CG_CTRL_PKC_RAM_CG_AUTO_DIS_SHIFT)) & SYSCON_PKC_RAM_CG_CTRL_PKC_RAM_CG_AUTO_DIS_MASK)
/*! @} */

/*! @name RAM_CG_CTRL - System RAM clock control */
/*! @{ */

#define SYSCON_RAM_CG_CTRL_RAM0_CG_AUTO_DIS_MASK (0x1U)
#define SYSCON_RAM_CG_CTRL_RAM0_CG_AUTO_DIS_SHIFT (0U)
/*! RAM0_CG_AUTO_DIS - RAM0 bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CG_CTRL_RAM0_CG_AUTO_DIS(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CG_CTRL_RAM0_CG_AUTO_DIS_SHIFT)) & SYSCON_RAM_CG_CTRL_RAM0_CG_AUTO_DIS_MASK)

#define SYSCON_RAM_CG_CTRL_RAM1_CG_AUTO_DIS_MASK (0x2U)
#define SYSCON_RAM_CG_CTRL_RAM1_CG_AUTO_DIS_SHIFT (1U)
/*! RAM1_CG_AUTO_DIS - RAM1 bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CG_CTRL_RAM1_CG_AUTO_DIS(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CG_CTRL_RAM1_CG_AUTO_DIS_SHIFT)) & SYSCON_RAM_CG_CTRL_RAM1_CG_AUTO_DIS_MASK)

#define SYSCON_RAM_CG_CTRL_RAM2_CG_AUTO_DIS_MASK (0x4U)
#define SYSCON_RAM_CG_CTRL_RAM2_CG_AUTO_DIS_SHIFT (2U)
/*! RAM2_CG_AUTO_DIS - RAM2 bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CG_CTRL_RAM2_CG_AUTO_DIS(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CG_CTRL_RAM2_CG_AUTO_DIS_SHIFT)) & SYSCON_RAM_CG_CTRL_RAM2_CG_AUTO_DIS_MASK)

#define SYSCON_RAM_CG_CTRL_RAM3_CG_AUTO_DIS_MASK (0x8U)
#define SYSCON_RAM_CG_CTRL_RAM3_CG_AUTO_DIS_SHIFT (3U)
/*! RAM3_CG_AUTO_DIS - RAM3 bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CG_CTRL_RAM3_CG_AUTO_DIS(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CG_CTRL_RAM3_CG_AUTO_DIS_SHIFT)) & SYSCON_RAM_CG_CTRL_RAM3_CG_AUTO_DIS_MASK)
/*! @} */

/*! @name RAM_REMAP_CTRL - System RAM Remap Control */
/*! @{ */

#define SYSCON_RAM_REMAP_CTRL_REMAP_ENABLE_MASK  (0x1U)
#define SYSCON_RAM_REMAP_CTRL_REMAP_ENABLE_SHIFT (0U)
/*! REMAP_ENABLE - RAM Remap Enable
 *  0b0..Disable Remap
 *  0b1..Enable Remap
 */
#define SYSCON_RAM_REMAP_CTRL_REMAP_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_REMAP_CTRL_REMAP_ENABLE_SHIFT)) & SYSCON_RAM_REMAP_CTRL_REMAP_ENABLE_MASK)

#define SYSCON_RAM_REMAP_CTRL_LOCK_ENABLE_MASK   (0x80000000U)
#define SYSCON_RAM_REMAP_CTRL_LOCK_ENABLE_SHIFT  (31U)
/*! LOCK_ENABLE - Lock Bit
 *  0b0..Unlock, this register could be wrote
 *  0b1..Locked, theis register could not be wrote
 */
#define SYSCON_RAM_REMAP_CTRL_LOCK_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_REMAP_CTRL_LOCK_ENABLE_SHIFT)) & SYSCON_RAM_REMAP_CTRL_LOCK_ENABLE_MASK)
/*! @} */

/*! @name SCG_LP_ENABLE - System Clock Generator Low Power Enable */
/*! @{ */

#define SYSCON_SCG_LP_ENABLE_lp_mode_enable_MASK (0x80000000U)
#define SYSCON_SCG_LP_ENABLE_lp_mode_enable_SHIFT (31U)
/*! lp_mode_enable - scg low auto enter pwer enable
 *  0b0..disable
 *  0b1..enbale
 */
#define SYSCON_SCG_LP_ENABLE_lp_mode_enable(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_SCG_LP_ENABLE_lp_mode_enable_SHIFT)) & SYSCON_SCG_LP_ENABLE_lp_mode_enable_MASK)
/*! @} */

/*! @name ZENV_CTRL - ZENV CORE Initial Vector Set */
/*! @{ */

#define SYSCON_ZENV_CTRL_ZENV_INITVTOR_MASK      (0xFFFFFFFFU)
#define SYSCON_ZENV_CTRL_ZENV_INITVTOR_SHIFT     (0U)
/*! ZENV_INITVTOR - ZENV_CORE_INITVTOR */
#define SYSCON_ZENV_CTRL_ZENV_INITVTOR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ZENV_CTRL_ZENV_INITVTOR_SHIFT)) & SYSCON_ZENV_CTRL_ZENV_INITVTOR_MASK)
/*! @} */

/*! @name ZENV_RESET_CTRL - ZENV CORE Reset Controller */
/*! @{ */

#define SYSCON_ZENV_RESET_CTRL_ZENV_CORE_RESET_MASK (0xFU)
#define SYSCON_ZENV_RESET_CTRL_ZENV_CORE_RESET_SHIFT (0U)
/*! ZENV_CORE_RESET - ZENV_CORE_RESET
 *  0b1010..Reset ZENV CORE, any other value will release reset of ZENV CORE
 */
#define SYSCON_ZENV_RESET_CTRL_ZENV_CORE_RESET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ZENV_RESET_CTRL_ZENV_CORE_RESET_SHIFT)) & SYSCON_ZENV_RESET_CTRL_ZENV_CORE_RESET_MASK)
/*! @} */

/*! @name JTAG_ID - JTAG Chip ID */
/*! @{ */

#define SYSCON_JTAG_ID_JTAG_ID_MASK              (0xFFFFFFFFU)
#define SYSCON_JTAG_ID_JTAG_ID_SHIFT             (0U)
/*! JTAG_ID - Indicates the device ID */
#define SYSCON_JTAG_ID_JTAG_ID(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_JTAG_ID_JTAG_ID_SHIFT)) & SYSCON_JTAG_ID_JTAG_ID_MASK)
/*! @} */

/*! @name DEVICE_TYPE - Device Type */
/*! @{ */

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK  (0xFFFFU)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT (0U)
/*! DEVICE_TYPE_NUM - Indicates the device part number */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK  (0x10000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT (16U)
/*! DEVICE_TYPE_SEC - Indicates the device type
 *  0b0..Non Secure
 *  0b1..Secure
 */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK  (0xF00000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT (20U)
/*! DEVICE_TYPE_PKG - Indicates the device package type
 *  0b0000..HLQFP
 *  0b0001..HTQFP
 *  0b0010..BGA
 *  0b0011..MAXQFP
 *  0b0100..QFN
 *  0b0101..CSP
 */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK  (0xFF000000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT (24U)
/*! DEVICE_TYPE_PIN - Indicates the device number of pins */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK)
/*! @} */

/*! @name DEVICE_ID - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID_DEVICE_ID_MASK          (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID_DEVICE_ID_SHIFT         (0U)
/*! DEVICE_ID - Device ID */
#define SYSCON_DEVICE_ID_DEVICE_ID(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID_DEVICE_ID_SHIFT)) & SYSCON_DEVICE_ID_DEVICE_ID_MASK)
/*! @} */

/*! @name DIEID - Chip Revision ID and Number */
/*! @{ */

#define SYSCON_DIEID_MINOR_REVISION_MASK         (0xFU)
#define SYSCON_DIEID_MINOR_REVISION_SHIFT        (0U)
/*! MINOR_REVISION - Chip minor revision */
#define SYSCON_DIEID_MINOR_REVISION(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_MINOR_REVISION_SHIFT)) & SYSCON_DIEID_MINOR_REVISION_MASK)

#define SYSCON_DIEID_MAJOR_REVISION_MASK         (0xF0U)
#define SYSCON_DIEID_MAJOR_REVISION_SHIFT        (4U)
/*! MAJOR_REVISION - Chip major revision */
#define SYSCON_DIEID_MAJOR_REVISION(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_MAJOR_REVISION_SHIFT)) & SYSCON_DIEID_MAJOR_REVISION_MASK)

#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_MASK      (0xFFFFF00U)
#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_SHIFT     (8U)
/*! MCO_NUM_IN_DIE_ID - Chip number */
#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_MCO_NUM_IN_DIE_ID_SHIFT)) & SYSCON_DIEID_MCO_NUM_IN_DIE_ID_MASK)
/*! @} */

/*! @name SWD_ID - Serial Wire Debug ID */
/*! @{ */

#define SYSCON_SWD_ID_SWD_INSTANCE_ID_MASK       (0xFU)
#define SYSCON_SWD_ID_SWD_INSTANCE_ID_SHIFT      (0U)
/*! SWD_INSTANCE_ID - Serial Wire Debug ID */
#define SYSCON_SWD_ID_SWD_INSTANCE_ID(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_SWD_ID_SWD_INSTANCE_ID_SHIFT)) & SYSCON_SWD_ID_SWD_INSTANCE_ID_MASK)
/*! @} */

/*! @name OEM_TYPE - OEM Type */
/*! @{ */

#define SYSCON_OEM_TYPE_OEM_SECURE_TYPE_MASK     (0xFU)
#define SYSCON_OEM_TYPE_OEM_SECURE_TYPE_SHIFT    (0U)
/*! OEM_SECURE_TYPE - OEM Type when OEMO state
 *  0b0101..Untrusted OEM
 *  0b1010..Trusted OEM
 */
#define SYSCON_OEM_TYPE_OEM_SECURE_TYPE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_OEM_TYPE_OEM_SECURE_TYPE_SHIFT)) & SYSCON_OEM_TYPE_OEM_SECURE_TYPE_MASK)
/*! @} */

/*! @name PWM_SUBCTL - PWM Sub-system Control */
/*! @{ */

#define SYSCON_PWM_SUBCTL_CLK0_EN_MASK           (0x1U)
#define SYSCON_PWM_SUBCTL_CLK0_EN_SHIFT          (0U)
/*! CLK0_EN - Enables PWM0 SUB0 Clock
 *  0b0..Disable
 *  0b1..Clock0 Enable
 */
#define SYSCON_PWM_SUBCTL_CLK0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM_SUBCTL_CLK0_EN_SHIFT)) & SYSCON_PWM_SUBCTL_CLK0_EN_MASK)

#define SYSCON_PWM_SUBCTL_CLK1_EN_MASK           (0x2U)
#define SYSCON_PWM_SUBCTL_CLK1_EN_SHIFT          (1U)
/*! CLK1_EN - Enables PWM0 SUB1 Clockn
 *  0b0..Disable
 *  0b1..Clock1 Enable
 */
#define SYSCON_PWM_SUBCTL_CLK1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM_SUBCTL_CLK1_EN_SHIFT)) & SYSCON_PWM_SUBCTL_CLK1_EN_MASK)

#define SYSCON_PWM_SUBCTL_CLK2_EN_MASK           (0x4U)
#define SYSCON_PWM_SUBCTL_CLK2_EN_SHIFT          (2U)
/*! CLK2_EN - Enables PWM0 SUB2 Clockn
 *  0b0..Disable
 *  0b1..Clock2 Enable
 */
#define SYSCON_PWM_SUBCTL_CLK2_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM_SUBCTL_CLK2_EN_SHIFT)) & SYSCON_PWM_SUBCTL_CLK2_EN_MASK)
/*! @} */

/*! @name FMC1_CTRL - Control for Flash Memory Controller 1 */
/*! @{ */

#define SYSCON_FMC1_CTRL_DNCBEI_MASK             (0x4U)
#define SYSCON_FMC1_CTRL_DNCBEI_SHIFT            (2U)
/*! DNCBEI - Disable non-correctable bus errors on flash instruction fetches
 *  0b0..Bus error for non-correctable error on instruction fetch from flash
 *  0b1..Disable bus error response for non-correctable error on instruction fetch from flash
 */
#define SYSCON_FMC1_CTRL_DNCBEI(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_DNCBEI_SHIFT)) & SYSCON_FMC1_CTRL_DNCBEI_MASK)

#define SYSCON_FMC1_CTRL_DNCBED_MASK             (0x8U)
#define SYSCON_FMC1_CTRL_DNCBED_SHIFT            (3U)
/*! DNCBED - Disable non-correctable bus errors on flash data fetches
 *  0b0..Bus error for non-correctable error on data fetch from flash
 *  0b1..Disable bus error response for non-correctable error on data fetch from flash
 */
#define SYSCON_FMC1_CTRL_DNCBED(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_DNCBED_SHIFT)) & SYSCON_FMC1_CTRL_DNCBED_MASK)

#define SYSCON_FMC1_CTRL_DDP_MASK                (0x10U)
#define SYSCON_FMC1_CTRL_DDP_SHIFT               (4U)
/*! DDP - Disable Data Prefetch
 *  0b0..Enable Data Prefetch
 *  0b1..Disable Data Prefetch
 */
#define SYSCON_FMC1_CTRL_DDP(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_DDP_SHIFT)) & SYSCON_FMC1_CTRL_DDP_MASK)

#define SYSCON_FMC1_CTRL_DFS_MASK                (0x20U)
#define SYSCON_FMC1_CTRL_DFS_SHIFT               (5U)
/*! DFS - Disable Flash Speculate
 *  0b0..Enable Flash Speculate
 *  0b1..Disable Flash Speculate
 */
#define SYSCON_FMC1_CTRL_DFS(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_DFS_SHIFT)) & SYSCON_FMC1_CTRL_DFS_MASK)

#define SYSCON_FMC1_CTRL_LKIFR1_MASK             (0x80U)
#define SYSCON_FMC1_CTRL_LKIFR1_SHIFT            (7U)
/*! LKIFR1 - Lock IFR1
 *  0b0..IFR1 space can be accessed.
 *  0b1..IFR1 space cannot be accessed. This bit is sticky. Once set, it is cleared with reset.
 */
#define SYSCON_FMC1_CTRL_LKIFR1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_LKIFR1_SHIFT)) & SYSCON_FMC1_CTRL_LKIFR1_MASK)

#define SYSCON_FMC1_CTRL_ECFC_MASK               (0x100U)
#define SYSCON_FMC1_CTRL_ECFC_SHIFT              (8U)
/*! ECFC - Execute clear the flash cache
 *  0b0..do not clear the flash cache
 *  0b1..clear the flash cache (negate all valid bits in the cache)
 */
#define SYSCON_FMC1_CTRL_ECFC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_ECFC_SHIFT)) & SYSCON_FMC1_CTRL_ECFC_MASK)

#define SYSCON_FMC1_CTRL_DFDC_MASK               (0x200U)
#define SYSCON_FMC1_CTRL_DFDC_SHIFT              (9U)
/*! DFDC - Disable flash data caching
 *  0b0..enable flash data caching
 *  0b1..disable flash data caching
 */
#define SYSCON_FMC1_CTRL_DFDC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_DFDC_SHIFT)) & SYSCON_FMC1_CTRL_DFDC_MASK)

#define SYSCON_FMC1_CTRL_DFIC_MASK               (0x400U)
#define SYSCON_FMC1_CTRL_DFIC_SHIFT              (10U)
/*! DFIC - Disable flash instruction caching
 *  0b0..enable flash instruction caching
 *  0b1..disable flash instruction caching
 */
#define SYSCON_FMC1_CTRL_DFIC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_DFIC_SHIFT)) & SYSCON_FMC1_CTRL_DFIC_MASK)

#define SYSCON_FMC1_CTRL_DFC_MASK                (0x800U)
#define SYSCON_FMC1_CTRL_DFC_SHIFT               (11U)
/*! DFC - Disable Flash Cache
 *  0b0..the flash cache is enable
 *  0b1..the flash cache is diabled
 */
#define SYSCON_FMC1_CTRL_DFC(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_DFC_SHIFT)) & SYSCON_FMC1_CTRL_DFC_MASK)

#define SYSCON_FMC1_CTRL_PFLEXSTALL_MASK         (0x10000U)
#define SYSCON_FMC1_CTRL_PFLEXSTALL_SHIFT        (16U)
/*! PFLEXSTALL - Flash Stall Enable
 *  0b0..Flash stall is disabled when flash is busy.
 *  0b1..Flash stall is enabled when flash is busy.
 */
#define SYSCON_FMC1_CTRL_PFLEXSTALL(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_PFLEXSTALL_SHIFT)) & SYSCON_FMC1_CTRL_PFLEXSTALL_MASK)

#define SYSCON_FMC1_CTRL_RO_MASK                 (0x80000000U)
#define SYSCON_FMC1_CTRL_RO_SHIFT                (31U)
/*! RO - Read-Only
 *  0b0..Writes to the FMC1_CTRL are allowed
 *  0b1..Writes to the FMC1_CTRL are ignored
 */
#define SYSCON_FMC1_CTRL_RO(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC1_CTRL_RO_SHIFT)) & SYSCON_FMC1_CTRL_RO_MASK)
/*! @} */

/*! @name DMA_RF_WAKE_MAIN_0 - DMA request 0-31 to wake up main domain */
/*! @{ */

#define SYSCON_DMA_RF_WAKE_MAIN_0_disbale_main_wake_reg0_MASK (0xFFFFFFFFU)
#define SYSCON_DMA_RF_WAKE_MAIN_0_disbale_main_wake_reg0_SHIFT (0U)
/*! disbale_main_wake_reg0 - Disable Wake Up Main by DMA request 0-31
 *  0b00000000000000000000000000000000..Keep wake up MAIN
 *  0b00000000000000000000000000000001..Not wake up MAIN
 */
#define SYSCON_DMA_RF_WAKE_MAIN_0_disbale_main_wake_reg0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DMA_RF_WAKE_MAIN_0_disbale_main_wake_reg0_SHIFT)) & SYSCON_DMA_RF_WAKE_MAIN_0_disbale_main_wake_reg0_MASK)
/*! @} */

/*! @name DMA_RF_WAKE_MAIN_1 - DMA request 32-63 to wake up main domain */
/*! @{ */

#define SYSCON_DMA_RF_WAKE_MAIN_1_disbale_main_wake_reg1_MASK (0xFFFFFFFFU)
#define SYSCON_DMA_RF_WAKE_MAIN_1_disbale_main_wake_reg1_SHIFT (0U)
/*! disbale_main_wake_reg1 - Disable Wake Up Main by DMA request 32-63
 *  0b00000000000000000000000000000000..Keep wake up MAIN
 *  0b00000000000000000000000000000001..Not wake up MAIN
 */
#define SYSCON_DMA_RF_WAKE_MAIN_1_disbale_main_wake_reg1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DMA_RF_WAKE_MAIN_1_disbale_main_wake_reg1_SHIFT)) & SYSCON_DMA_RF_WAKE_MAIN_1_disbale_main_wake_reg1_MASK)
/*! @} */

/*! @name CAN_20MHZ_CLOCK_CTRL - Flexcan 20MHZ Clock Control */
/*! @{ */

#define SYSCON_CAN_20MHZ_CLOCK_CTRL_CAN_20MHZ_EN_MASK (0xFU)
#define SYSCON_CAN_20MHZ_CLOCK_CTRL_CAN_20MHZ_EN_SHIFT (0U)
/*! CAN_20MHZ_EN - Enable 20mhz For FlexCAN
 *  0b0101..Disable 20mhz clock for CAN, any other value also disable it.
 *  0b1010..Enable 20mhz clock for CAN
 */
#define SYSCON_CAN_20MHZ_CLOCK_CTRL_CAN_20MHZ_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN_20MHZ_CLOCK_CTRL_CAN_20MHZ_EN_SHIFT)) & SYSCON_CAN_20MHZ_CLOCK_CTRL_CAN_20MHZ_EN_MASK)

#define SYSCON_CAN_20MHZ_CLOCK_CTRL_FRO_CALIBRATION_EN_MASK (0xF0000U)
#define SYSCON_CAN_20MHZ_CLOCK_CTRL_FRO_CALIBRATION_EN_SHIFT (16U)
/*! FRO_CALIBRATION_EN - Enable FRO Calibration
 *  0b0101..Disable FRO Calibration, any other value also disable it.
 *  0b1010..Enable FRO Calibration
 */
#define SYSCON_CAN_20MHZ_CLOCK_CTRL_FRO_CALIBRATION_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN_20MHZ_CLOCK_CTRL_FRO_CALIBRATION_EN_SHIFT)) & SYSCON_CAN_20MHZ_CLOCK_CTRL_FRO_CALIBRATION_EN_MASK)
/*! @} */

/*! @name SRAM0_ECC_CONTROL - SRAM0 ECC Function Control */
/*! @{ */

#define SYSCON_SRAM0_ECC_CONTROL_EERW_MASK       (0x1U)
#define SYSCON_SRAM0_ECC_CONTROL_EERW_SHIFT      (0U)
/*! EERW - Enable ECC write generation
 *  0b0..Disable ECC on reads
 *  0b1..Enable ECC on reads
 */
#define SYSCON_SRAM0_ECC_CONTROL_EERW(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_CONTROL_EERW_SHIFT)) & SYSCON_SRAM0_ECC_CONTROL_EERW_MASK)

#define SYSCON_SRAM0_ECC_CONTROL_EERC_MASK       (0x2U)
#define SYSCON_SRAM0_ECC_CONTROL_EERC_SHIFT      (1U)
/*! EERC - Enable ECC read check
 *  0b0..Disable ECC on writes
 *  0b1..Enable ECC on writes
 */
#define SYSCON_SRAM0_ECC_CONTROL_EERC(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_CONTROL_EERC_SHIFT)) & SYSCON_SRAM0_ECC_CONTROL_EERC_MASK)
/*! @} */

/*! @name SRAM0_ECC_REPORT - SRAM0 ECC Error Report Control */
/*! @{ */

#define SYSCON_SRAM0_ECC_REPORT_ENCR_MASK        (0x1U)
#define SYSCON_SRAM0_ECC_REPORT_ENCR_SHIFT       (0U)
/*! ENCR - Enable RAM ECC Non-correctable Reporting
 *  0b0..Non-correctable reporting and interrupt disabled
 *  0b1..Non-correctable reporting and interrupt enabled
 */
#define SYSCON_SRAM0_ECC_REPORT_ENCR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_REPORT_ENCR_SHIFT)) & SYSCON_SRAM0_ECC_REPORT_ENCR_MASK)

#define SYSCON_SRAM0_ECC_REPORT_E1BR_MASK        (0x100U)
#define SYSCON_SRAM0_ECC_REPORT_E1BR_SHIFT       (8U)
/*! E1BR - Enable RAM ECC 1 Bit Reporting
 *  0b0..1-bit reporting disabled
 *  0b1..1-bit reporting enabled
 */
#define SYSCON_SRAM0_ECC_REPORT_E1BR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_REPORT_E1BR_SHIFT)) & SYSCON_SRAM0_ECC_REPORT_E1BR_MASK)
/*! @} */

/*! @name SRAM0_ECC_EVENT_RECORD - SRAM0 ECC Error Event Record */
/*! @{ */

#define SYSCON_SRAM0_ECC_EVENT_RECORD_ENCERRN_MASK (0x4U)
#define SYSCON_SRAM0_ECC_EVENT_RECORD_ENCERRN_SHIFT (2U)
/*! ENCERRN - ECC Non-correctable Error */
#define SYSCON_SRAM0_ECC_EVENT_RECORD_ENCERRN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_EVENT_RECORD_ENCERRN_SHIFT)) & SYSCON_SRAM0_ECC_EVENT_RECORD_ENCERRN_MASK)

#define SYSCON_SRAM0_ECC_EVENT_RECORD_E1BERRN_MASK (0x400U)
#define SYSCON_SRAM0_ECC_EVENT_RECORD_E1BERRN_SHIFT (10U)
/*! E1BERRN - ECC 1-bit Error */
#define SYSCON_SRAM0_ECC_EVENT_RECORD_E1BERRN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_EVENT_RECORD_E1BERRN_SHIFT)) & SYSCON_SRAM0_ECC_EVENT_RECORD_E1BERRN_MASK)

#define SYSCON_SRAM0_ECC_EVENT_RECORD_EELOC_MASK (0xF000000U)
#define SYSCON_SRAM0_ECC_EVENT_RECORD_EELOC_SHIFT (24U)
/*! EELOC - ECC Error Location
 *  0b0010..non-correctable on SRAM0
 *  0b1010..1-bit correctable on SRAM0
 */
#define SYSCON_SRAM0_ECC_EVENT_RECORD_EELOC(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_EVENT_RECORD_EELOC_SHIFT)) & SYSCON_SRAM0_ECC_EVENT_RECORD_EELOC_MASK)

#define SYSCON_SRAM0_ECC_EVENT_RECORD_VALID_MASK (0x80000000U)
#define SYSCON_SRAM0_ECC_EVENT_RECORD_VALID_SHIFT (31U)
/*! VALID - Valid ECC Error Location field
 *  0b0..ECC Error Location field is not valid
 *  0b1..ECC Error Location field is valid
 */
#define SYSCON_SRAM0_ECC_EVENT_RECORD_VALID(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_EVENT_RECORD_VALID_SHIFT)) & SYSCON_SRAM0_ECC_EVENT_RECORD_VALID_MASK)
/*! @} */

/*! @name SRAM0_ECC_FAULT_ADDR - SRAM0 Fault Address Register */
/*! @{ */

#define SYSCON_SRAM0_ECC_FAULT_ADDR_EFADD_MASK   (0xFFFFFFFFU)
#define SYSCON_SRAM0_ECC_FAULT_ADDR_EFADD_SHIFT  (0U)
#define SYSCON_SRAM0_ECC_FAULT_ADDR_EFADD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_FAULT_ADDR_EFADD_SHIFT)) & SYSCON_SRAM0_ECC_FAULT_ADDR_EFADD_MASK)
/*! @} */

/*! @name SRAM0_ECC_FAULT_ATTR - SRAM0 Fault Attribute Register */
/*! @{ */

#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFPRT_MASK   (0xFU)
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFPRT_SHIFT  (0U)
/*! EFPRT - RAM0 ECC Fault Protection */
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFPRT(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_FAULT_ATTR_EFPRT_SHIFT)) & SYSCON_SRAM0_ECC_FAULT_ATTR_EFPRT_MASK)

#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFMS_MASK    (0x70U)
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFMS_SHIFT   (4U)
/*! EFMS - RAM0 ECC Fault Master Size
 *  0b000..8-bit size
 *  0b001..16-bit size
 *  0b010..32-bit size
 *  0b011..64-bit size
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFMS(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_FAULT_ATTR_EFMS_SHIFT)) & SYSCON_SRAM0_ECC_FAULT_ATTR_EFMS_MASK)

#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFW_MASK     (0x80U)
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFW_SHIFT    (7U)
/*! EFW - RAM0 ECC Fault Write
 *  0b0..Last captured ECC event was not a write bus cycle
 *  0b1..Last captured ECC event was a write bus cycle
 */
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFW(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_FAULT_ATTR_EFW_SHIFT)) & SYSCON_SRAM0_ECC_FAULT_ATTR_EFW_MASK)

#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFMST_MASK   (0xFF00U)
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFMST_SHIFT  (8U)
/*! EFMST - RAM0 ECC Fault Master Number
 *  0b00000000..NBU Code
 *  0b00000001..NBU Data
 *  0b00000010..Radio
 *  0b00000011..DataStream
 *  0b00000100..CM33 Code
 *  0b00000101..CM33 Data
 *  0b00000110..ZEN-V Code
 *  0b00000111..ZEN-V Data
 *  0b00001000..DMA0
 *  0b00001001..TESTPORT
 *  0b00001010..PKC
 */
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFMST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_FAULT_ATTR_EFMST_SHIFT)) & SYSCON_SRAM0_ECC_FAULT_ATTR_EFMST_MASK)

#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFSYN_MASK   (0x7F0000U)
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFSYN_SHIFT  (16U)
/*! EFSYN - RAM0 ECC Fault Syndrome */
#define SYSCON_SRAM0_ECC_FAULT_ATTR_EFSYN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_FAULT_ATTR_EFSYN_SHIFT)) & SYSCON_SRAM0_ECC_FAULT_ATTR_EFSYN_MASK)
/*! @} */

/*! @name SRAM0_ECC_FAULT_DATA - SRAM0 ECC Fault Data Low Register */
/*! @{ */

#define SYSCON_SRAM0_ECC_FAULT_DATA_EFDL_MASK    (0xFFFFFFFFU)
#define SYSCON_SRAM0_ECC_FAULT_DATA_EFDL_SHIFT   (0U)
/*! EFDL - SRAM0 ECC Fault Data Low */
#define SYSCON_SRAM0_ECC_FAULT_DATA_EFDL(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM0_ECC_FAULT_DATA_EFDL_SHIFT)) & SYSCON_SRAM0_ECC_FAULT_DATA_EFDL_MASK)
/*! @} */

/*! @name MATRIX_MODE_CTRL - Matrix Mode Control */
/*! @{ */

#define SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_RREN_MASK (0x1U)
#define SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_RREN_SHIFT (0U)
/*! INFRA_AXBS0_RREN - Infra AXBS0 Round Robin Enable
 *  0b0..AXBS0 in fixed priority arbitration mode at reset.
 *  0b1..AXBS0 in round robin arbitration mode at reset.
 */
#define SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_RREN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_RREN_SHIFT)) & SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_RREN_MASK)

#define SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_RREN_MASK (0x2U)
#define SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_RREN_SHIFT (1U)
/*! RADIO_AXBS0_RREN - Radio AXBS0 Round Robin Enable
 *  0b0..AXBS0 in fixed priority arbitration mode at reset.
 *  0b1..AXBS0 in round robin arbitration mode at reset.
 */
#define SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_RREN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_RREN_SHIFT)) & SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_RREN_MASK)

#define SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_RREN_MASK (0x4U)
#define SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_RREN_SHIFT (2U)
/*! MAIN_AXBS0_RREN - Main AXBS0 Round Robin Enable
 *  0b0..AXBS0 in fixed priority arbitration mode at reset.
 *  0b1..AXBS0 in round robin arbitration mode at reset.
 */
#define SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_RREN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_RREN_SHIFT)) & SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_RREN_MASK)

#define SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_AUTO_CG_EN_MASK (0x100U)
#define SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_AUTO_CG_EN_SHIFT (8U)
/*! INFRA_AXBS0_AUTO_CG_EN - Infra AXBS0 Auto Clock Gate Enable */
#define SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_AUTO_CG_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_AUTO_CG_EN_SHIFT)) & SYSCON_MATRIX_MODE_CTRL_INFRA_AXBS0_AUTO_CG_EN_MASK)

#define SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_AUTO_CG_EN_MASK (0x200U)
#define SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_AUTO_CG_EN_SHIFT (9U)
/*! MAIN_AXBS0_AUTO_CG_EN - Main AXBS0 Auto Clock Gate Enable */
#define SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_AUTO_CG_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_AUTO_CG_EN_SHIFT)) & SYSCON_MATRIX_MODE_CTRL_MAIN_AXBS0_AUTO_CG_EN_MASK)

#define SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_AUTO_CG_EN_MASK (0x400U)
#define SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_AUTO_CG_EN_SHIFT (10U)
/*! RADIO_AXBS0_AUTO_CG_EN - Radio AXBS0 Auto Clock Gate Enable */
#define SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_AUTO_CG_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_AUTO_CG_EN_SHIFT)) & SYSCON_MATRIX_MODE_CTRL_RADIO_AXBS0_AUTO_CG_EN_MASK)
/*! @} */

/*! @name FMC_CG_CTRL - Clock Gating Ctrl of Flash Memory Control */
/*! @{ */

#define SYSCON_FMC_CG_CTRL_FMC0_AUTO_CG_DIS_MASK (0x1U)
#define SYSCON_FMC_CG_CTRL_FMC0_AUTO_CG_DIS_SHIFT (0U)
/*! FMC0_AUTO_CG_DIS - Flash Memory Control 0 Auto Clock Gate Disable */
#define SYSCON_FMC_CG_CTRL_FMC0_AUTO_CG_DIS(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC_CG_CTRL_FMC0_AUTO_CG_DIS_SHIFT)) & SYSCON_FMC_CG_CTRL_FMC0_AUTO_CG_DIS_MASK)

#define SYSCON_FMC_CG_CTRL_FMC1_AUTO_CG_DIS_MASK (0x2U)
#define SYSCON_FMC_CG_CTRL_FMC1_AUTO_CG_DIS_SHIFT (1U)
/*! FMC1_AUTO_CG_DIS - Flash Memory Control 1 Auto Clock Gate Disable */
#define SYSCON_FMC_CG_CTRL_FMC1_AUTO_CG_DIS(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC_CG_CTRL_FMC1_AUTO_CG_DIS_SHIFT)) & SYSCON_FMC_CG_CTRL_FMC1_AUTO_CG_DIS_MASK)
/*! @} */

/*! @name FMC0_CTRL - Control for Flash Memory Controller 0 */
/*! @{ */

#define SYSCON_FMC0_CTRL_DNCBEI_MASK             (0x4U)
#define SYSCON_FMC0_CTRL_DNCBEI_SHIFT            (2U)
/*! DNCBEI - Disable non-correctable bus errors on flash instruction fetches
 *  0b0..Bus error for non-correctable error on instruction fetch from flash
 *  0b1..Disable bus error response for non-correctable error on instruction fetch from flash
 */
#define SYSCON_FMC0_CTRL_DNCBEI(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_DNCBEI_SHIFT)) & SYSCON_FMC0_CTRL_DNCBEI_MASK)

#define SYSCON_FMC0_CTRL_DNCBED_MASK             (0x8U)
#define SYSCON_FMC0_CTRL_DNCBED_SHIFT            (3U)
/*! DNCBED - Disable non-correctable bus errors on flash data fetches
 *  0b0..Bus error for non-correctable error on data fetch from flash
 *  0b1..Disable bus error response for non-correctable error on data fetch from flash
 */
#define SYSCON_FMC0_CTRL_DNCBED(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_DNCBED_SHIFT)) & SYSCON_FMC0_CTRL_DNCBED_MASK)

#define SYSCON_FMC0_CTRL_DDP_MASK                (0x10U)
#define SYSCON_FMC0_CTRL_DDP_SHIFT               (4U)
/*! DDP - Disable Data Prefetch
 *  0b0..Enable Data Prefetch
 *  0b1..Disable Data Prefetch
 */
#define SYSCON_FMC0_CTRL_DDP(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_DDP_SHIFT)) & SYSCON_FMC0_CTRL_DDP_MASK)

#define SYSCON_FMC0_CTRL_DFS_MASK                (0x20U)
#define SYSCON_FMC0_CTRL_DFS_SHIFT               (5U)
/*! DFS - Disable Flash Speculate
 *  0b0..Enable Flash Speculate
 *  0b1..Disable Flash Speculate
 */
#define SYSCON_FMC0_CTRL_DFS(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_DFS_SHIFT)) & SYSCON_FMC0_CTRL_DFS_MASK)

#define SYSCON_FMC0_CTRL_LKIFR1_MASK             (0x80U)
#define SYSCON_FMC0_CTRL_LKIFR1_SHIFT            (7U)
/*! LKIFR1 - Lock IFR1
 *  0b0..IFR1 space can be accessed.
 *  0b1..IFR1 space cannot be accessed. This bit is sticky. Once set, it is cleared with reset.
 */
#define SYSCON_FMC0_CTRL_LKIFR1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_LKIFR1_SHIFT)) & SYSCON_FMC0_CTRL_LKIFR1_MASK)

#define SYSCON_FMC0_CTRL_ECFC_MASK               (0x100U)
#define SYSCON_FMC0_CTRL_ECFC_SHIFT              (8U)
/*! ECFC - Execute clear the flash cache
 *  0b0..do not clear the flash cache
 *  0b1..clear the flash cache (negate all valid bits in the cache)
 */
#define SYSCON_FMC0_CTRL_ECFC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_ECFC_SHIFT)) & SYSCON_FMC0_CTRL_ECFC_MASK)

#define SYSCON_FMC0_CTRL_DFDC_MASK               (0x200U)
#define SYSCON_FMC0_CTRL_DFDC_SHIFT              (9U)
/*! DFDC - Disable flash data caching
 *  0b0..enable flash data caching
 *  0b1..disable flash data caching
 */
#define SYSCON_FMC0_CTRL_DFDC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_DFDC_SHIFT)) & SYSCON_FMC0_CTRL_DFDC_MASK)

#define SYSCON_FMC0_CTRL_DFIC_MASK               (0x400U)
#define SYSCON_FMC0_CTRL_DFIC_SHIFT              (10U)
/*! DFIC - Disable flash instruction caching
 *  0b0..enable flash instruction caching
 *  0b1..disable flash instruction caching
 */
#define SYSCON_FMC0_CTRL_DFIC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_DFIC_SHIFT)) & SYSCON_FMC0_CTRL_DFIC_MASK)

#define SYSCON_FMC0_CTRL_DFC_MASK                (0x800U)
#define SYSCON_FMC0_CTRL_DFC_SHIFT               (11U)
/*! DFC - Disable Flash Cache
 *  0b0..the flash cache is enable
 *  0b1..the flash cache is diabled
 */
#define SYSCON_FMC0_CTRL_DFC(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_DFC_SHIFT)) & SYSCON_FMC0_CTRL_DFC_MASK)

#define SYSCON_FMC0_CTRL_PFLEXSTALL_MASK         (0x10000U)
#define SYSCON_FMC0_CTRL_PFLEXSTALL_SHIFT        (16U)
/*! PFLEXSTALL - Flash Stall Enable
 *  0b0..Flash stall is disabled when flash is busy.
 *  0b1..Flash stall is enabled when flash is busy.
 */
#define SYSCON_FMC0_CTRL_PFLEXSTALL(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_PFLEXSTALL_SHIFT)) & SYSCON_FMC0_CTRL_PFLEXSTALL_MASK)

#define SYSCON_FMC0_CTRL_RO_MASK                 (0x80000000U)
#define SYSCON_FMC0_CTRL_RO_SHIFT                (31U)
/*! RO - Read-Only
 *  0b0..Writes to the FMC1_CTRL are allowed
 *  0b1..Writes to the FMC1_CTRL are ignored
 */
#define SYSCON_FMC0_CTRL_RO(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FMC0_CTRL_RO_SHIFT)) & SYSCON_FMC0_CTRL_RO_MASK)
/*! @} */

/*! @name CPU1_ACCESS_CTRL - CPU1 Access Control */
/*! @{ */

#define SYSCON_CPU1_ACCESS_CTRL_C1ME_MASK        (0x1U)
#define SYSCON_CPU1_ACCESS_CTRL_C1ME_SHIFT       (0U)
/*! C1ME - CPU1 Access Main Error
 *  0b0..Enable generating responce Error
 *  0b1..Disable generating responce Error, CPU1 will be stuck.
 */
#define SYSCON_CPU1_ACCESS_CTRL_C1ME(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_ACCESS_CTRL_C1ME_SHIFT)) & SYSCON_CPU1_ACCESS_CTRL_C1ME_MASK)

#define SYSCON_CPU1_ACCESS_CTRL_C1HB_MASK        (0x2U)
#define SYSCON_CPU1_ACCESS_CTRL_C1HB_SHIFT       (1U)
/*! C1HB - CPU1 BUS Halt Bypass Mode
 *  0b0..Disable bypass mechanism of CPU1 Sync-Bridge
 *  0b1..Enable bypass mechanism of CPU1 Sync-Bridge
 */
#define SYSCON_CPU1_ACCESS_CTRL_C1HB(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1_ACCESS_CTRL_C1HB_SHIFT)) & SYSCON_CPU1_ACCESS_CTRL_C1HB_MASK)
/*! @} */

/*! @name GENERAL_REG_0 - General Register 0 */
/*! @{ */

#define SYSCON_GENERAL_REG_0_GENERAL_REG_MASK    (0xFFFFFFFFU)
#define SYSCON_GENERAL_REG_0_GENERAL_REG_SHIFT   (0U)
/*! GENERAL_REG - General Bit Field */
#define SYSCON_GENERAL_REG_0_GENERAL_REG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_GENERAL_REG_0_GENERAL_REG_SHIFT)) & SYSCON_GENERAL_REG_0_GENERAL_REG_MASK)
/*! @} */

/*! @name GENERAL_REG_1 - General Register 1 */
/*! @{ */

#define SYSCON_GENERAL_REG_1_GENERAL_REG_MASK    (0xFFFFFFFFU)
#define SYSCON_GENERAL_REG_1_GENERAL_REG_SHIFT   (0U)
/*! GENERAL_REG - General Bit Field */
#define SYSCON_GENERAL_REG_1_GENERAL_REG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_GENERAL_REG_1_GENERAL_REG_SHIFT)) & SYSCON_GENERAL_REG_1_GENERAL_REG_MASK)
/*! @} */

/*! @name GENERAL_REG_2 - General Register 2 */
/*! @{ */

#define SYSCON_GENERAL_REG_2_GENERAL_REG_MASK    (0xFFFFFFFFU)
#define SYSCON_GENERAL_REG_2_GENERAL_REG_SHIFT   (0U)
/*! GENERAL_REG - General Bit Field */
#define SYSCON_GENERAL_REG_2_GENERAL_REG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_GENERAL_REG_2_GENERAL_REG_SHIFT)) & SYSCON_GENERAL_REG_2_GENERAL_REG_MASK)
/*! @} */

/*! @name GENERAL_REG_3 - General Register 3 */
/*! @{ */

#define SYSCON_GENERAL_REG_3_GENERAL_REG_MASK    (0xFFFFFFFFU)
#define SYSCON_GENERAL_REG_3_GENERAL_REG_SHIFT   (0U)
/*! GENERAL_REG - General Bit Field */
#define SYSCON_GENERAL_REG_3_GENERAL_REG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_GENERAL_REG_3_GENERAL_REG_SHIFT)) & SYSCON_GENERAL_REG_3_GENERAL_REG_MASK)
/*! @} */

/*! @name AUTHENTICATE - Protect SYSCON registers from unintentional writes */
/*! @{ */

#define SYSCON_AUTHENTICATE_DUMMY_LOCK_MASK      (0xFFFFFFFFU)
#define SYSCON_AUTHENTICATE_DUMMY_LOCK_SHIFT     (0U)
/*! DUMMY_LOCK - SYSCON Write Access Lock
 *  0b10101010101010101010101010101010..Unlock SYSCON registers write restriction, any other value will lock SYSCON registers
 */
#define SYSCON_AUTHENTICATE_DUMMY_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTHENTICATE_DUMMY_LOCK_SHIFT)) & SYSCON_AUTHENTICATE_DUMMY_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCON_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCON_H_ */

