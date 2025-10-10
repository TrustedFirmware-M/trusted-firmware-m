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
**         CMSIS Peripheral Access Layer for LPDAC
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
 * @file PERI_LPDAC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPDAC
 *
 * CMSIS Peripheral Access Layer for LPDAC
 */

#if !defined(PERI_LPDAC_H_)
#define PERI_LPDAC_H_                            /**< Symbol preventing repeated inclusion */

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
   -- LPDAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPDAC_Peripheral_Access_Layer LPDAC Peripheral Access Layer
 * @{
 */

/** LPDAC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version Identifier, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t DATA;                              /**< Data, offset: 0x8 */
  __IO uint32_t GCR;                               /**< Global Control, offset: 0xC */
  __IO uint32_t FCR;                               /**< DAC FIFO Control, offset: 0x10 */
  __I  uint32_t FPR;                               /**< DAC FIFO Pointer, offset: 0x14 */
  __IO uint32_t FSR;                               /**< FIFO Status, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t DER;                               /**< DMA Enable, offset: 0x20 */
  __IO uint32_t RCR;                               /**< Reset Control, offset: 0x24 */
  __IO uint32_t TCR;                               /**< Trigger Control, offset: 0x28 */
  __IO uint32_t PCR;                               /**< Periodic Trigger Control, offset: 0x2C */
} LPDAC_Type;

/* ----------------------------------------------------------------------------
   -- LPDAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPDAC_Register_Masks LPDAC Register Masks
 * @{
 */

/*! @name VERID - Version Identifier */
/*! @{ */

#define LPDAC_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPDAC_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Identification Number */
#define LPDAC_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_FEATURE_SHIFT)) & LPDAC_VERID_FEATURE_MASK)

#define LPDAC_VERID_MINOR_MASK                   (0xFF0000U)
#define LPDAC_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define LPDAC_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_MINOR_SHIFT)) & LPDAC_VERID_MINOR_MASK)

#define LPDAC_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPDAC_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define LPDAC_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_MAJOR_SHIFT)) & LPDAC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPDAC_PARAM_FIFOSZ_MASK                  (0x7U)
#define LPDAC_PARAM_FIFOSZ_SHIFT                 (0U)
/*! FIFOSZ - FIFO Size
 *  0b000..Reserved
 *  0b001..FIFO depth is 4
 *  0b010..FIFO depth is 8
 *  0b011..FIFO depth is 16
 *  0b100..FIFO depth is 32
 *  0b101..FIFO depth is 64
 *  0b110..FIFO depth is 128
 *  0b111..FIFO depth is 256
 */
#define LPDAC_PARAM_FIFOSZ(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_PARAM_FIFOSZ_SHIFT)) & LPDAC_PARAM_FIFOSZ_MASK)
/*! @} */

/*! @name DATA - Data */
/*! @{ */

#define LPDAC_DATA_DATA_MASK                     (0xFFFU)
#define LPDAC_DATA_DATA_SHIFT                    (0U)
/*! DATA - FIFO Entry or Buffer Entry */
#define LPDAC_DATA_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_DATA_DATA_SHIFT)) & LPDAC_DATA_DATA_MASK)
/*! @} */

/*! @name GCR - Global Control */
/*! @{ */

#define LPDAC_GCR_DACEN_MASK                     (0x1U)
#define LPDAC_GCR_DACEN_SHIFT                    (0U)
/*! DACEN - DAC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_GCR_DACEN(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_DACEN_SHIFT)) & LPDAC_GCR_DACEN_MASK)

#define LPDAC_GCR_DACRFS_MASK                    (0x6U)
#define LPDAC_GCR_DACRFS_SHIFT                   (1U)
/*! DACRFS - DAC Reference Select
 *  0b00..Selects VREFH0 as the reference voltage.
 *  0b01..Selects VREFH1 as the reference voltage.
 *  0b10..Selects VREFH2 as the reference voltage.
 *  0b11..Reserved.
 */
#define LPDAC_GCR_DACRFS(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_DACRFS_SHIFT)) & LPDAC_GCR_DACRFS_MASK)

#define LPDAC_GCR_FIFOEN_MASK                    (0x8U)
#define LPDAC_GCR_FIFOEN_SHIFT                   (3U)
/*! FIFOEN - FIFO Enable
 *  0b0..Enables FIFO mode and disables Buffer mode. Any data written to DATA[DATA] goes to buffer then goes to conversion.
 *  0b1..Enables FIFO mode. Data will be first read from FIFO to buffer and then goes to conversion.
 */
#define LPDAC_GCR_FIFOEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_FIFOEN_SHIFT)) & LPDAC_GCR_FIFOEN_MASK)

#define LPDAC_GCR_SWMD_MASK                      (0x10U)
#define LPDAC_GCR_SWMD_SHIFT                     (4U)
/*! SWMD - Swing Back Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_GCR_SWMD(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_SWMD_SHIFT)) & LPDAC_GCR_SWMD_MASK)

#define LPDAC_GCR_TRGSEL_MASK                    (0x20U)
#define LPDAC_GCR_TRGSEL_SHIFT                   (5U)
/*! TRGSEL - DAC Trigger Select
 *  0b0..Hardware trigger
 *  0b1..Software trigger
 */
#define LPDAC_GCR_TRGSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_TRGSEL_SHIFT)) & LPDAC_GCR_TRGSEL_MASK)

#define LPDAC_GCR_PTGEN_MASK                     (0x40U)
#define LPDAC_GCR_PTGEN_SHIFT                    (6U)
/*! PTGEN - DAC Periodic Trigger Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_GCR_PTGEN(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_PTGEN_SHIFT)) & LPDAC_GCR_PTGEN_MASK)

#define LPDAC_GCR_LATCH_CYC_MASK                 (0xF00U)
#define LPDAC_GCR_LATCH_CYC_SHIFT                (8U)
/*! LATCH_CYC - RCLK Cycles Before Data Latch */
#define LPDAC_GCR_LATCH_CYC(x)                   (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_LATCH_CYC_SHIFT)) & LPDAC_GCR_LATCH_CYC_MASK)

#define LPDAC_GCR_BUF_EN_MASK                    (0x20000U)
#define LPDAC_GCR_BUF_EN_SHIFT                   (17U)
/*! BUF_EN - Buffer Enable
 *  0b0..Not used
 *  0b1..Used
 */
#define LPDAC_GCR_BUF_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_BUF_EN_SHIFT)) & LPDAC_GCR_BUF_EN_MASK)

#define LPDAC_GCR_IREF_PTAT_EXT_SEL_MASK         (0x100000U)
#define LPDAC_GCR_IREF_PTAT_EXT_SEL_SHIFT        (20U)
/*! IREF_PTAT_EXT_SEL - External On-Chip PTAT Current Reference Select
 *  0b0..Not selected
 *  0b1..Selected
 */
#define LPDAC_GCR_IREF_PTAT_EXT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_IREF_PTAT_EXT_SEL_SHIFT)) & LPDAC_GCR_IREF_PTAT_EXT_SEL_MASK)

#define LPDAC_GCR_IREF_ZTC_EXT_SEL_MASK          (0x200000U)
#define LPDAC_GCR_IREF_ZTC_EXT_SEL_SHIFT         (21U)
/*! IREF_ZTC_EXT_SEL - External On-Chip ZTC Current Reference Select
 *  0b0..Not selected
 *  0b1..Selected
 */
#define LPDAC_GCR_IREF_ZTC_EXT_SEL(x)            (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_IREF_ZTC_EXT_SEL_SHIFT)) & LPDAC_GCR_IREF_ZTC_EXT_SEL_MASK)

#define LPDAC_GCR_BUF_SPD_CTRL_MASK              (0x800000U)
#define LPDAC_GCR_BUF_SPD_CTRL_SHIFT             (23U)
/*! BUF_SPD_CTRL - OPAMP as Buffer, Speed Control Signal
 *  0b0..Lower Low-Power mode
 *  0b1..Low-Power mode
 */
#define LPDAC_GCR_BUF_SPD_CTRL(x)                (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_BUF_SPD_CTRL_SHIFT)) & LPDAC_GCR_BUF_SPD_CTRL_MASK)
/*! @} */

/*! @name FCR - DAC FIFO Control */
/*! @{ */

#define LPDAC_FCR_WML_MASK                       (0xFU)
#define LPDAC_FCR_WML_SHIFT                      (0U)
/*! WML - Watermark Level */
#define LPDAC_FCR_WML(x)                         (((uint32_t)(((uint32_t)(x)) << LPDAC_FCR_WML_SHIFT)) & LPDAC_FCR_WML_MASK)
/*! @} */

/*! @name FPR - DAC FIFO Pointer */
/*! @{ */

#define LPDAC_FPR_FIFO_RPT_MASK                  (0xFU)
#define LPDAC_FPR_FIFO_RPT_SHIFT                 (0U)
/*! FIFO_RPT - FIFO Read Pointer */
#define LPDAC_FPR_FIFO_RPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_FPR_FIFO_RPT_SHIFT)) & LPDAC_FPR_FIFO_RPT_MASK)

#define LPDAC_FPR_FIFO_WPT_MASK                  (0xF0000U)
#define LPDAC_FPR_FIFO_WPT_SHIFT                 (16U)
/*! FIFO_WPT - FIFO Write Pointer */
#define LPDAC_FPR_FIFO_WPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_FPR_FIFO_WPT_SHIFT)) & LPDAC_FPR_FIFO_WPT_MASK)
/*! @} */

/*! @name FSR - FIFO Status */
/*! @{ */

#define LPDAC_FSR_FULL_MASK                      (0x1U)
#define LPDAC_FSR_FULL_SHIFT                     (0U)
/*! FULL - FIFO Full Flag
 *  0b0..Not full
 *  0b1..Full
 */
#define LPDAC_FSR_FULL(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_FULL_SHIFT)) & LPDAC_FSR_FULL_MASK)

#define LPDAC_FSR_EMPTY_MASK                     (0x2U)
#define LPDAC_FSR_EMPTY_SHIFT                    (1U)
/*! EMPTY - FIFO Empty Flag
 *  0b0..Not empty
 *  0b1..Empty
 */
#define LPDAC_FSR_EMPTY(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_EMPTY_SHIFT)) & LPDAC_FSR_EMPTY_MASK)

#define LPDAC_FSR_WM_MASK                        (0x4U)
#define LPDAC_FSR_WM_SHIFT                       (2U)
/*! WM - FIFO Watermark Status Flag
 *  0b0..Data in FIFO is more than watermark level
 *  0b1..Data in FIFO is less than or equal to watermark level
 */
#define LPDAC_FSR_WM(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_WM_SHIFT)) & LPDAC_FSR_WM_MASK)

#define LPDAC_FSR_SWBK_MASK                      (0x8U)
#define LPDAC_FSR_SWBK_SHIFT                     (3U)
/*! SWBK - Swing Back One Cycle Complete Flag
 *  0b0..No swing back cycle has completed since the last time the flag was cleared
 *  0b1..At least one swing back cycle has occurred since the last time the flag was cleared
 */
#define LPDAC_FSR_SWBK(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_SWBK_SHIFT)) & LPDAC_FSR_SWBK_MASK)

#define LPDAC_FSR_OF_MASK                        (0x40U)
#define LPDAC_FSR_OF_SHIFT                       (6U)
/*! OF - FIFO Overflow Flag
 *  0b0..No overflow has occurred since the last time the flag was cleared
 *  0b1..At least one FIFO overflow has occurred since the last time the flag was cleared
 */
#define LPDAC_FSR_OF(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_OF_SHIFT)) & LPDAC_FSR_OF_MASK)

#define LPDAC_FSR_UF_MASK                        (0x80U)
#define LPDAC_FSR_UF_SHIFT                       (7U)
/*! UF - FIFO Underflow Flag
 *  0b0..No underflow has occurred since the last time the flag was cleared
 *  0b1..At least one trigger underflow has occurred since the last time the flag was cleared
 */
#define LPDAC_FSR_UF(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_UF_SHIFT)) & LPDAC_FSR_UF_MASK)

#define LPDAC_FSR_PTGCOCO_MASK                   (0x100U)
#define LPDAC_FSR_PTGCOCO_SHIFT                  (8U)
/*! PTGCOCO - Period Trigger Mode Conversion Complete Flag
 *  0b0..Not completed or not started
 *  0b1..Completed
 */
#define LPDAC_FSR_PTGCOCO(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_PTGCOCO_SHIFT)) & LPDAC_FSR_PTGCOCO_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define LPDAC_IER_FULL_IE_MASK                   (0x1U)
#define LPDAC_IER_FULL_IE_SHIFT                  (0U)
/*! FULL_IE - FIFO Full Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_FULL_IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_FULL_IE_SHIFT)) & LPDAC_IER_FULL_IE_MASK)

#define LPDAC_IER_EMPTY_IE_MASK                  (0x2U)
#define LPDAC_IER_EMPTY_IE_SHIFT                 (1U)
/*! EMPTY_IE - FIFO Empty Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_EMPTY_IE(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_EMPTY_IE_SHIFT)) & LPDAC_IER_EMPTY_IE_MASK)

#define LPDAC_IER_WM_IE_MASK                     (0x4U)
#define LPDAC_IER_WM_IE_SHIFT                    (2U)
/*! WM_IE - FIFO Watermark Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_WM_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_WM_IE_SHIFT)) & LPDAC_IER_WM_IE_MASK)

#define LPDAC_IER_SWBK_IE_MASK                   (0x8U)
#define LPDAC_IER_SWBK_IE_SHIFT                  (3U)
/*! SWBK_IE - Swing Back One Cycle Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_SWBK_IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_SWBK_IE_SHIFT)) & LPDAC_IER_SWBK_IE_MASK)

#define LPDAC_IER_OF_IE_MASK                     (0x40U)
#define LPDAC_IER_OF_IE_SHIFT                    (6U)
/*! OF_IE - FIFO Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_OF_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_OF_IE_SHIFT)) & LPDAC_IER_OF_IE_MASK)

#define LPDAC_IER_UF_IE_MASK                     (0x80U)
#define LPDAC_IER_UF_IE_SHIFT                    (7U)
/*! UF_IE - FIFO Underflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_UF_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_UF_IE_SHIFT)) & LPDAC_IER_UF_IE_MASK)

#define LPDAC_IER_PTGCOCO_IE_MASK                (0x100U)
#define LPDAC_IER_PTGCOCO_IE_SHIFT               (8U)
/*! PTGCOCO_IE - PTG Mode Conversion Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_PTGCOCO_IE(x)                  (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_PTGCOCO_IE_SHIFT)) & LPDAC_IER_PTGCOCO_IE_MASK)
/*! @} */

/*! @name DER - DMA Enable */
/*! @{ */

#define LPDAC_DER_EMPTY_DMAEN_MASK               (0x2U)
#define LPDAC_DER_EMPTY_DMAEN_SHIFT              (1U)
/*! EMPTY_DMAEN - FIFO Empty DMA Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_DER_EMPTY_DMAEN(x)                 (((uint32_t)(((uint32_t)(x)) << LPDAC_DER_EMPTY_DMAEN_SHIFT)) & LPDAC_DER_EMPTY_DMAEN_MASK)

#define LPDAC_DER_WM_DMAEN_MASK                  (0x4U)
#define LPDAC_DER_WM_DMAEN_SHIFT                 (2U)
/*! WM_DMAEN - FIFO Watermark DMA Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_DER_WM_DMAEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_DER_WM_DMAEN_SHIFT)) & LPDAC_DER_WM_DMAEN_MASK)
/*! @} */

/*! @name RCR - Reset Control */
/*! @{ */

#define LPDAC_RCR_SWRST_MASK                     (0x1U)
#define LPDAC_RCR_SWRST_SHIFT                    (0U)
/*! SWRST - Software Reset
 *  0b0..No effect
 *  0b1..Software reset
 */
#define LPDAC_RCR_SWRST(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_RCR_SWRST_SHIFT)) & LPDAC_RCR_SWRST_MASK)

#define LPDAC_RCR_FIFORST_MASK                   (0x2U)
#define LPDAC_RCR_FIFORST_SHIFT                  (1U)
/*! FIFORST - FIFO Reset
 *  0b0..No effect
 *  0b1..FIFO reset
 */
#define LPDAC_RCR_FIFORST(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_RCR_FIFORST_SHIFT)) & LPDAC_RCR_FIFORST_MASK)
/*! @} */

/*! @name TCR - Trigger Control */
/*! @{ */

#define LPDAC_TCR_SWTRG_MASK                     (0x1U)
#define LPDAC_TCR_SWTRG_SHIFT                    (0U)
/*! SWTRG - Software Trigger
 *  0b0..Not valid
 *  0b1..Valid
 */
#define LPDAC_TCR_SWTRG(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_TCR_SWTRG_SHIFT)) & LPDAC_TCR_SWTRG_MASK)
/*! @} */

/*! @name PCR - Periodic Trigger Control */
/*! @{ */

#define LPDAC_PCR_PTG_NUM_MASK                   (0xFFFFU)
#define LPDAC_PCR_PTG_NUM_SHIFT                  (0U)
/*! PTG_NUM - Periodic Trigger Number */
#define LPDAC_PCR_PTG_NUM(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_PCR_PTG_NUM_SHIFT)) & LPDAC_PCR_PTG_NUM_MASK)

#define LPDAC_PCR_PTG_PERIOD_MASK                (0xFFFF0000U)
#define LPDAC_PCR_PTG_PERIOD_SHIFT               (16U)
/*! PTG_PERIOD - Periodic Trigger Period Width */
#define LPDAC_PCR_PTG_PERIOD(x)                  (((uint32_t)(((uint32_t)(x)) << LPDAC_PCR_PTG_PERIOD_SHIFT)) & LPDAC_PCR_PTG_PERIOD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPDAC_Register_Masks */


/*!
 * @}
 */ /* end of group LPDAC_Peripheral_Access_Layer */


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


#endif  /* PERI_LPDAC_H_ */

