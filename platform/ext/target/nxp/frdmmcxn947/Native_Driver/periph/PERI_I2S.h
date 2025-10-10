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
**         CMSIS Peripheral Access Layer for I2S
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
 * @file PERI_I2S.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for I2S
 *
 * CMSIS Peripheral Access Layer for I2S
 */

#if !defined(PERI_I2S_H_)
#define PERI_I2S_H_                              /**< Symbol preventing repeated inclusion */

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
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Peripheral_Access_Layer I2S Peripheral Access Layer
 * @{
 */

/** I2S - Size of Registers Arrays */
#define I2S_TDR_COUNT                             2u
#define I2S_TFR_COUNT                             2u
#define I2S_RDR_COUNT                             2u
#define I2S_RFR_COUNT                             2u

/** I2S - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t TCSR;                              /**< Transmit Control, offset: 0x8 */
  __IO uint32_t TCR1;                              /**< Transmit Configuration 1, offset: 0xC */
  __IO uint32_t TCR2;                              /**< Transmit Configuration 2, offset: 0x10 */
  __IO uint32_t TCR3;                              /**< Transmit Configuration 3, offset: 0x14 */
  __IO uint32_t TCR4;                              /**< Transmit Configuration 4, offset: 0x18 */
  __IO uint32_t TCR5;                              /**< Transmit Configuration 5, offset: 0x1C */
  __IO uint32_t TDR[I2S_TDR_COUNT];                /**< Transmit Data, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_0[24];
  __I  uint32_t TFR[I2S_TFR_COUNT];                /**< Transmit FIFO, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_1[24];
  __IO uint32_t TMR;                               /**< Transmit Mask, offset: 0x60 */
       uint8_t RESERVED_2[36];
  __IO uint32_t RCSR;                              /**< Receive Control, offset: 0x88 */
  __IO uint32_t RCR1;                              /**< Receive Configuration 1, offset: 0x8C */
  __IO uint32_t RCR2;                              /**< Receive Configuration 2, offset: 0x90 */
  __IO uint32_t RCR3;                              /**< Receive Configuration 3, offset: 0x94 */
  __IO uint32_t RCR4;                              /**< Receive Configuration 4, offset: 0x98 */
  __IO uint32_t RCR5;                              /**< Receive Configuration 5, offset: 0x9C */
  __I  uint32_t RDR[I2S_RDR_COUNT];                /**< Receive Data, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[24];
  __I  uint32_t RFR[I2S_RFR_COUNT];                /**< Receive FIFO, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_4[24];
  __IO uint32_t RMR;                               /**< Receive Mask, offset: 0xE0 */
       uint8_t RESERVED_5[28];
  __IO uint32_t MCR;                               /**< MCLK Control, offset: 0x100 */
} I2S_Type;

/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Register_Masks I2S Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define I2S_VERID_FEATURE_MASK                   (0xFFFFU)
#define I2S_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard feature set
 */
#define I2S_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << I2S_VERID_FEATURE_SHIFT)) & I2S_VERID_FEATURE_MASK)

#define I2S_VERID_MINOR_MASK                     (0xFF0000U)
#define I2S_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define I2S_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << I2S_VERID_MINOR_SHIFT)) & I2S_VERID_MINOR_MASK)

#define I2S_VERID_MAJOR_MASK                     (0xFF000000U)
#define I2S_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define I2S_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << I2S_VERID_MAJOR_SHIFT)) & I2S_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define I2S_PARAM_DATALINE_MASK                  (0xFU)
#define I2S_PARAM_DATALINE_SHIFT                 (0U)
/*! DATALINE - Number of Data Lines */
#define I2S_PARAM_DATALINE(x)                    (((uint32_t)(((uint32_t)(x)) << I2S_PARAM_DATALINE_SHIFT)) & I2S_PARAM_DATALINE_MASK)

#define I2S_PARAM_FIFO_MASK                      (0xF00U)
#define I2S_PARAM_FIFO_SHIFT                     (8U)
/*! FIFO - FIFO Size */
#define I2S_PARAM_FIFO(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_PARAM_FIFO_SHIFT)) & I2S_PARAM_FIFO_MASK)

#define I2S_PARAM_FRAME_MASK                     (0xF0000U)
#define I2S_PARAM_FRAME_SHIFT                    (16U)
/*! FRAME - Frame Size */
#define I2S_PARAM_FRAME(x)                       (((uint32_t)(((uint32_t)(x)) << I2S_PARAM_FRAME_SHIFT)) & I2S_PARAM_FRAME_MASK)
/*! @} */

/*! @name TCSR - Transmit Control */
/*! @{ */

#define I2S_TCSR_FRDE_MASK                       (0x1U)
#define I2S_TCSR_FRDE_SHIFT                      (0U)
/*! FRDE - FIFO Request DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRDE_SHIFT)) & I2S_TCSR_FRDE_MASK)

#define I2S_TCSR_FWDE_MASK                       (0x2U)
#define I2S_TCSR_FWDE_SHIFT                      (1U)
/*! FWDE - FIFO Warning DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWDE_SHIFT)) & I2S_TCSR_FWDE_MASK)

#define I2S_TCSR_FRIE_MASK                       (0x100U)
#define I2S_TCSR_FRIE_SHIFT                      (8U)
/*! FRIE - FIFO Request Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRIE_SHIFT)) & I2S_TCSR_FRIE_MASK)

#define I2S_TCSR_FWIE_MASK                       (0x200U)
#define I2S_TCSR_FWIE_SHIFT                      (9U)
/*! FWIE - FIFO Warning Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWIE_SHIFT)) & I2S_TCSR_FWIE_MASK)

#define I2S_TCSR_FEIE_MASK                       (0x400U)
#define I2S_TCSR_FEIE_SHIFT                      (10U)
/*! FEIE - FIFO Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEIE_SHIFT)) & I2S_TCSR_FEIE_MASK)

#define I2S_TCSR_SEIE_MASK                       (0x800U)
#define I2S_TCSR_SEIE_SHIFT                      (11U)
/*! SEIE - Sync Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEIE_SHIFT)) & I2S_TCSR_SEIE_MASK)

#define I2S_TCSR_WSIE_MASK                       (0x1000U)
#define I2S_TCSR_WSIE_SHIFT                      (12U)
/*! WSIE - Word Start Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_WSIE_SHIFT)) & I2S_TCSR_WSIE_MASK)

#define I2S_TCSR_FRF_MASK                        (0x10000U)
#define I2S_TCSR_FRF_SHIFT                       (16U)
/*! FRF - FIFO Request Flag
 *  0b0..Watermark not reached
 *  0b1..Watermark reached
 */
#define I2S_TCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRF_SHIFT)) & I2S_TCSR_FRF_MASK)

#define I2S_TCSR_FWF_MASK                        (0x20000U)
#define I2S_TCSR_FWF_SHIFT                       (17U)
/*! FWF - FIFO Warning Flag
 *  0b0..Not empty
 *  0b1..Empty
 */
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWF_SHIFT)) & I2S_TCSR_FWF_MASK)

#define I2S_TCSR_FEF_MASK                        (0x40000U)
#define I2S_TCSR_FEF_SHIFT                       (18U)
/*! FEF - FIFO Error Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEF_SHIFT)) & I2S_TCSR_FEF_MASK)

#define I2S_TCSR_SEF_MASK                        (0x80000U)
#define I2S_TCSR_SEF_SHIFT                       (19U)
/*! SEF - Sync Error Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEF_SHIFT)) & I2S_TCSR_SEF_MASK)

#define I2S_TCSR_WSF_MASK                        (0x100000U)
#define I2S_TCSR_WSF_SHIFT                       (20U)
/*! WSF - Word Start Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define I2S_TCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_WSF_SHIFT)) & I2S_TCSR_WSF_MASK)

#define I2S_TCSR_SR_MASK                         (0x1000000U)
#define I2S_TCSR_SR_SHIFT                        (24U)
/*! SR - Software Reset
 *  0b0..No effect
 *  0b1..Software reset
 */
#define I2S_TCSR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SR_SHIFT)) & I2S_TCSR_SR_MASK)

#define I2S_TCSR_FR_MASK                         (0x2000000U)
#define I2S_TCSR_FR_SHIFT                        (25U)
/*! FR - FIFO Reset
 *  0b0..No effect
 *  0b1..FIFO reset
 */
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FR_SHIFT)) & I2S_TCSR_FR_MASK)

#define I2S_TCSR_BCE_MASK                        (0x10000000U)
#define I2S_TCSR_BCE_SHIFT                       (28U)
/*! BCE - Bit Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_BCE_SHIFT)) & I2S_TCSR_BCE_MASK)

#define I2S_TCSR_DBGE_MASK                       (0x20000000U)
#define I2S_TCSR_DBGE_SHIFT                      (29U)
/*! DBGE - Debug Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_DBGE_SHIFT)) & I2S_TCSR_DBGE_MASK)

#define I2S_TCSR_STOPE_MASK                      (0x40000000U)
#define I2S_TCSR_STOPE_SHIFT                     (30U)
/*! STOPE - Stop Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_STOPE_SHIFT)) & I2S_TCSR_STOPE_MASK)

#define I2S_TCSR_TE_MASK                         (0x80000000U)
#define I2S_TCSR_TE_SHIFT                        (31U)
/*! TE - Transmitter Enable
 *  0b0..Disable
 *  0b1..Enable (or transmitter has been disabled and has not yet reached the end of the frame)
 */
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_TE_SHIFT)) & I2S_TCSR_TE_MASK)
/*! @} */

/*! @name TCR1 - Transmit Configuration 1 */
/*! @{ */

#define I2S_TCR1_TFW_MASK                        (0x7U)
#define I2S_TCR1_TFW_SHIFT                       (0U)
/*! TFW - Transmit FIFO Watermark
 *  0b000..1
 *  0b001..2
 *  0b010-0b110..(TFW +1)
 *  0b111..8
 */
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR1_TFW_SHIFT)) & I2S_TCR1_TFW_MASK)
/*! @} */

/*! @name TCR2 - Transmit Configuration 2 */
/*! @{ */

#define I2S_TCR2_DIV_MASK                        (0xFFU)
#define I2S_TCR2_DIV_SHIFT                       (0U)
/*! DIV - Bit Clock Divide */
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_DIV_SHIFT)) & I2S_TCR2_DIV_MASK)

#define I2S_TCR2_BYP_MASK                        (0x800000U)
#define I2S_TCR2_BYP_SHIFT                       (23U)
/*! BYP - Bit Clock Bypass
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCR2_BYP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BYP_SHIFT)) & I2S_TCR2_BYP_MASK)

#define I2S_TCR2_BCD_MASK                        (0x1000000U)
#define I2S_TCR2_BCD_SHIFT                       (24U)
/*! BCD - Bit Clock Direction
 *  0b0..Generate externally in Target mode
 *  0b1..Generate internally in Controller mode
 */
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCD_SHIFT)) & I2S_TCR2_BCD_MASK)

#define I2S_TCR2_BCP_MASK                        (0x2000000U)
#define I2S_TCR2_BCP_SHIFT                       (25U)
/*! BCP - Bit Clock Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCP_SHIFT)) & I2S_TCR2_BCP_MASK)

#define I2S_TCR2_MSEL_MASK                       (0xC000000U)
#define I2S_TCR2_MSEL_SHIFT                      (26U)
/*! MSEL - MCLK Select
 *  0b00..Bus clock
 *  0b01..Controller clock (MCLK) option 1
 *  0b10..Controller clock (MCLK) option 2
 *  0b11..Controller clock (MCLK) option 3
 */
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_MSEL_SHIFT)) & I2S_TCR2_MSEL_MASK)

#define I2S_TCR2_BCI_MASK                        (0x10000000U)
#define I2S_TCR2_BCI_SHIFT                       (28U)
/*! BCI - Bit Clock Input
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCI_SHIFT)) & I2S_TCR2_BCI_MASK)

#define I2S_TCR2_BCS_MASK                        (0x20000000U)
#define I2S_TCR2_BCS_SHIFT                       (29U)
/*! BCS - Bit Clock Swap
 *  0b0..Use the normal bit clock source
 *  0b1..Swap the bit clock source
 */
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCS_SHIFT)) & I2S_TCR2_BCS_MASK)

#define I2S_TCR2_SYNC_MASK                       (0xC0000000U)
#define I2S_TCR2_SYNC_SHIFT                      (30U)
/*! SYNC - Synchronous Mode
 *  0b00..Asynchronous mode
 *  0b01..Synchronous with receiver
 *  0b10..Synchronous with another SAI transmitter
 *  0b11..Synchronous with another SAI receiver
 */
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_SYNC_SHIFT)) & I2S_TCR2_SYNC_MASK)
/*! @} */

/*! @name TCR3 - Transmit Configuration 3 */
/*! @{ */

#define I2S_TCR3_WDFL_MASK                       (0x1FU)
#define I2S_TCR3_WDFL_SHIFT                      (0U)
/*! WDFL - Word Flag Configuration */
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_WDFL_SHIFT)) & I2S_TCR3_WDFL_MASK)

#define I2S_TCR3_TCE_MASK                        (0x30000U)
#define I2S_TCR3_TCE_SHIFT                       (16U)
/*! TCE - Transmit Channel Enable */
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_TCE_SHIFT)) & I2S_TCR3_TCE_MASK)

#define I2S_TCR3_CFR_MASK                        (0x3000000U)
#define I2S_TCR3_CFR_SHIFT                       (24U)
/*! CFR - Channel FIFO Reset */
#define I2S_TCR3_CFR(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_CFR_SHIFT)) & I2S_TCR3_CFR_MASK)
/*! @} */

/*! @name TCR4 - Transmit Configuration 4 */
/*! @{ */

#define I2S_TCR4_FSD_MASK                        (0x1U)
#define I2S_TCR4_FSD_SHIFT                       (0U)
/*! FSD - Frame Sync Direction
 *  0b0..Generated externally in Target mode
 *  0b1..Generated internally in Controller mode
 */
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSD_SHIFT)) & I2S_TCR4_FSD_MASK)

#define I2S_TCR4_FSP_MASK                        (0x2U)
#define I2S_TCR4_FSP_SHIFT                       (1U)
/*! FSP - Frame Sync Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSP_SHIFT)) & I2S_TCR4_FSP_MASK)

#define I2S_TCR4_ONDEM_MASK                      (0x4U)
#define I2S_TCR4_ONDEM_SHIFT                     (2U)
/*! ONDEM - On-Demand Mode
 *  0b0..Generated continuously
 *  0b1..Generated after the FIFO warning flag is cleared
 */
#define I2S_TCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_ONDEM_SHIFT)) & I2S_TCR4_ONDEM_MASK)

#define I2S_TCR4_FSE_MASK                        (0x8U)
#define I2S_TCR4_FSE_SHIFT                       (3U)
/*! FSE - Frame Sync Early
 *  0b0..First bit of the frame
 *  0b1..One bit before the first bit of the frame
 */
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSE_SHIFT)) & I2S_TCR4_FSE_MASK)

#define I2S_TCR4_MF_MASK                         (0x10U)
#define I2S_TCR4_MF_SHIFT                        (4U)
/*! MF - MSB First
 *  0b0..LSB
 *  0b1..MSB
 */
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_MF_SHIFT)) & I2S_TCR4_MF_MASK)

#define I2S_TCR4_CHMOD_MASK                      (0x20U)
#define I2S_TCR4_CHMOD_SHIFT                     (5U)
/*! CHMOD - Channel Mode
 *  0b0..TDM mode
 *  0b1..Output mode
 */
#define I2S_TCR4_CHMOD(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_CHMOD_SHIFT)) & I2S_TCR4_CHMOD_MASK)

#define I2S_TCR4_SYWD_MASK                       (0x1F00U)
#define I2S_TCR4_SYWD_SHIFT                      (8U)
/*! SYWD - Sync Width */
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_SYWD_SHIFT)) & I2S_TCR4_SYWD_MASK)

#define I2S_TCR4_FRSZ_MASK                       (0x1F0000U)
#define I2S_TCR4_FRSZ_SHIFT                      (16U)
/*! FRSZ - Frame Size */
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FRSZ_SHIFT)) & I2S_TCR4_FRSZ_MASK)

#define I2S_TCR4_FPACK_MASK                      (0x3000000U)
#define I2S_TCR4_FPACK_SHIFT                     (24U)
/*! FPACK - FIFO Packing Mode
 *  0b00..Disable FIFO packing
 *  0b01..Reserved
 *  0b10..Enable 8-bit FIFO packing
 *  0b11..Enable 16-bit FIFO packing
 */
#define I2S_TCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FPACK_SHIFT)) & I2S_TCR4_FPACK_MASK)

#define I2S_TCR4_FCOMB_MASK                      (0xC000000U)
#define I2S_TCR4_FCOMB_SHIFT                     (26U)
/*! FCOMB - FIFO Combine Mode
 *  0b00..Disable
 *  0b01..Enable on FIFO reads (from transmit shift registers)
 *  0b10..Enable on FIFO writes (by software)
 *  0b11..Enable on FIFO reads (from transmit shift registers) and writes (by software)
 */
#define I2S_TCR4_FCOMB(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FCOMB_SHIFT)) & I2S_TCR4_FCOMB_MASK)

#define I2S_TCR4_FCONT_MASK                      (0x10000000U)
#define I2S_TCR4_FCONT_SHIFT                     (28U)
/*! FCONT - FIFO Continue on Error
 *  0b0..Continue from the start of the next frame
 *  0b1..Continue from the same word that caused the FIFO error
 */
#define I2S_TCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FCONT_SHIFT)) & I2S_TCR4_FCONT_MASK)
/*! @} */

/*! @name TCR5 - Transmit Configuration 5 */
/*! @{ */

#define I2S_TCR5_FBT_MASK                        (0x1F00U)
#define I2S_TCR5_FBT_SHIFT                       (8U)
/*! FBT - First Bit Shifted
 *  0b00000..0
 *  0b00001-0b11110..FBT
 *  0b11111..31
 */
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_FBT_SHIFT)) & I2S_TCR5_FBT_MASK)

#define I2S_TCR5_W0W_MASK                        (0x1F0000U)
#define I2S_TCR5_W0W_SHIFT                       (16U)
/*! W0W - Word 0 Width
 *  0b00111..8
 *  0b01000..9
 *  0b01001-0b11110..(W0W value + 1)
 *  0b11111..32
 */
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_W0W_SHIFT)) & I2S_TCR5_W0W_MASK)

#define I2S_TCR5_WNW_MASK                        (0x1F000000U)
#define I2S_TCR5_WNW_SHIFT                       (24U)
/*! WNW - Word N Width
 *  0b00111..8
 *  0b01000..9
 *  0b01001-0b11110..(WNW value + 1)
 *  0b11111..32
 */
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_WNW_SHIFT)) & I2S_TCR5_WNW_MASK)
/*! @} */

/*! @name TDR - Transmit Data */
/*! @{ */

#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFU)
#define I2S_TDR_TDR_SHIFT                        (0U)
/*! TDR - Transmit Data */
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TDR_TDR_SHIFT)) & I2S_TDR_TDR_MASK)
/*! @} */

/*! @name TFR - Transmit FIFO */
/*! @{ */

#define I2S_TFR_RFP_MASK                         (0xFU)
#define I2S_TFR_RFP_SHIFT                        (0U)
/*! RFP - Read FIFO Pointer */
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_RFP_SHIFT)) & I2S_TFR_RFP_MASK)

#define I2S_TFR_WFP_MASK                         (0xF0000U)
#define I2S_TFR_WFP_SHIFT                        (16U)
/*! WFP - Write FIFO Pointer */
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_WFP_SHIFT)) & I2S_TFR_WFP_MASK)

#define I2S_TFR_WCP_MASK                         (0x80000000U)
#define I2S_TFR_WCP_SHIFT                        (31U)
/*! WCP - Write Channel Pointer
 *  0b0..No effect
 *  0b1..Next FIFO to be written
 */
#define I2S_TFR_WCP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_WCP_SHIFT)) & I2S_TFR_WCP_MASK)
/*! @} */

/*! @name TMR - Transmit Mask */
/*! @{ */

#define I2S_TMR_TWM_MASK                         (0xFFFFFFFFU)
#define I2S_TMR_TWM_SHIFT                        (0U)
/*! TWM - Transmit Word Mask
 *  0b00000000000000000000000000000000..Enable
 *  0b00000000000000000000000000000001..Mask
 */
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TMR_TWM_SHIFT)) & I2S_TMR_TWM_MASK)
/*! @} */

/*! @name RCSR - Receive Control */
/*! @{ */

#define I2S_RCSR_FRDE_MASK                       (0x1U)
#define I2S_RCSR_FRDE_SHIFT                      (0U)
/*! FRDE - FIFO Request DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRDE_SHIFT)) & I2S_RCSR_FRDE_MASK)

#define I2S_RCSR_FWDE_MASK                       (0x2U)
#define I2S_RCSR_FWDE_SHIFT                      (1U)
/*! FWDE - FIFO Warning DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWDE_SHIFT)) & I2S_RCSR_FWDE_MASK)

#define I2S_RCSR_FRIE_MASK                       (0x100U)
#define I2S_RCSR_FRIE_SHIFT                      (8U)
/*! FRIE - FIFO Request Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRIE_SHIFT)) & I2S_RCSR_FRIE_MASK)

#define I2S_RCSR_FWIE_MASK                       (0x200U)
#define I2S_RCSR_FWIE_SHIFT                      (9U)
/*! FWIE - FIFO Warning Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWIE_SHIFT)) & I2S_RCSR_FWIE_MASK)

#define I2S_RCSR_FEIE_MASK                       (0x400U)
#define I2S_RCSR_FEIE_SHIFT                      (10U)
/*! FEIE - FIFO Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEIE_SHIFT)) & I2S_RCSR_FEIE_MASK)

#define I2S_RCSR_SEIE_MASK                       (0x800U)
#define I2S_RCSR_SEIE_SHIFT                      (11U)
/*! SEIE - Sync Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEIE_SHIFT)) & I2S_RCSR_SEIE_MASK)

#define I2S_RCSR_WSIE_MASK                       (0x1000U)
#define I2S_RCSR_WSIE_SHIFT                      (12U)
/*! WSIE - Word Start Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSIE_SHIFT)) & I2S_RCSR_WSIE_MASK)

#define I2S_RCSR_FRF_MASK                        (0x10000U)
#define I2S_RCSR_FRF_SHIFT                       (16U)
/*! FRF - FIFO Request Flag
 *  0b0..Watermark not reached
 *  0b1..Watermark reached
 */
#define I2S_RCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRF_SHIFT)) & I2S_RCSR_FRF_MASK)

#define I2S_RCSR_FWF_MASK                        (0x20000U)
#define I2S_RCSR_FWF_SHIFT                       (17U)
/*! FWF - FIFO Warning Flag
 *  0b0..Not full
 *  0b1..Full
 */
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWF_SHIFT)) & I2S_RCSR_FWF_MASK)

#define I2S_RCSR_FEF_MASK                        (0x40000U)
#define I2S_RCSR_FEF_SHIFT                       (18U)
/*! FEF - FIFO Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Receive overflow detected
 */
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEF_SHIFT)) & I2S_RCSR_FEF_MASK)

#define I2S_RCSR_SEF_MASK                        (0x80000U)
#define I2S_RCSR_SEF_SHIFT                       (19U)
/*! SEF - Sync Error Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEF_SHIFT)) & I2S_RCSR_SEF_MASK)

#define I2S_RCSR_WSF_MASK                        (0x100000U)
#define I2S_RCSR_WSF_SHIFT                       (20U)
/*! WSF - Word Start Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSF_SHIFT)) & I2S_RCSR_WSF_MASK)

#define I2S_RCSR_SR_MASK                         (0x1000000U)
#define I2S_RCSR_SR_SHIFT                        (24U)
/*! SR - Software Reset
 *  0b0..No effect
 *  0b1..Software reset
 */
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SR_SHIFT)) & I2S_RCSR_SR_MASK)

#define I2S_RCSR_FR_MASK                         (0x2000000U)
#define I2S_RCSR_FR_SHIFT                        (25U)
/*! FR - FIFO Reset
 *  0b0..No effect
 *  0b1..Reset
 */
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FR_SHIFT)) & I2S_RCSR_FR_MASK)

#define I2S_RCSR_BCE_MASK                        (0x10000000U)
#define I2S_RCSR_BCE_SHIFT                       (28U)
/*! BCE - Bit Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_BCE_SHIFT)) & I2S_RCSR_BCE_MASK)

#define I2S_RCSR_DBGE_MASK                       (0x20000000U)
#define I2S_RCSR_DBGE_SHIFT                      (29U)
/*! DBGE - Debug Enable
 *  0b0..Disable after completing the current frame
 *  0b1..Enable
 */
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_DBGE_SHIFT)) & I2S_RCSR_DBGE_MASK)

#define I2S_RCSR_STOPE_MASK                      (0x40000000U)
#define I2S_RCSR_STOPE_SHIFT                     (30U)
/*! STOPE - Stop Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_STOPE_SHIFT)) & I2S_RCSR_STOPE_MASK)

#define I2S_RCSR_RE_MASK                         (0x80000000U)
#define I2S_RCSR_RE_SHIFT                        (31U)
/*! RE - Receiver Enable
 *  0b0..Disable
 *  0b1..Enable (or receiver disabled and not yet reached end of frame)
 */
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_RE_SHIFT)) & I2S_RCSR_RE_MASK)
/*! @} */

/*! @name RCR1 - Receive Configuration 1 */
/*! @{ */

#define I2S_RCR1_RFW_MASK                        (0x7U)
#define I2S_RCR1_RFW_SHIFT                       (0U)
/*! RFW - Receive FIFO Watermark
 *  0b000..1
 *  0b001..2
 *  0b010-0b110..(RFW value + 1)
 *  0b111..8
 */
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR1_RFW_SHIFT)) & I2S_RCR1_RFW_MASK)
/*! @} */

/*! @name RCR2 - Receive Configuration 2 */
/*! @{ */

#define I2S_RCR2_DIV_MASK                        (0xFFU)
#define I2S_RCR2_DIV_SHIFT                       (0U)
/*! DIV - Bit Clock Divide */
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_DIV_SHIFT)) & I2S_RCR2_DIV_MASK)

#define I2S_RCR2_BYP_MASK                        (0x800000U)
#define I2S_RCR2_BYP_SHIFT                       (23U)
/*! BYP - Bit Clock Bypass
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCR2_BYP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BYP_SHIFT)) & I2S_RCR2_BYP_MASK)

#define I2S_RCR2_BCD_MASK                        (0x1000000U)
#define I2S_RCR2_BCD_SHIFT                       (24U)
/*! BCD - Bit Clock Direction
 *  0b0..Generated externally in Target mode
 *  0b1..Generated internally in Controller mode
 */
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCD_SHIFT)) & I2S_RCR2_BCD_MASK)

#define I2S_RCR2_BCP_MASK                        (0x2000000U)
#define I2S_RCR2_BCP_SHIFT                       (25U)
/*! BCP - Bit Clock Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCP_SHIFT)) & I2S_RCR2_BCP_MASK)

#define I2S_RCR2_MSEL_MASK                       (0xC000000U)
#define I2S_RCR2_MSEL_SHIFT                      (26U)
/*! MSEL - MCLK Select
 *  0b00..Bus clock
 *  0b01..Controller clock (MCLK) option 1
 *  0b10..Controller clock (MCLK) option 2
 *  0b11..Controller clock (MCLK) option 3
 */
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_MSEL_SHIFT)) & I2S_RCR2_MSEL_MASK)

#define I2S_RCR2_BCI_MASK                        (0x10000000U)
#define I2S_RCR2_BCI_SHIFT                       (28U)
/*! BCI - Bit Clock Input
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCI_SHIFT)) & I2S_RCR2_BCI_MASK)

#define I2S_RCR2_BCS_MASK                        (0x20000000U)
#define I2S_RCR2_BCS_SHIFT                       (29U)
/*! BCS - Bit Clock Swap
 *  0b0..Use the normal bit clock source
 *  0b1..Swap the bit clock source
 */
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCS_SHIFT)) & I2S_RCR2_BCS_MASK)

#define I2S_RCR2_SYNC_MASK                       (0xC0000000U)
#define I2S_RCR2_SYNC_SHIFT                      (30U)
/*! SYNC - Synchronous Mode
 *  0b00..Asynchronous mode
 *  0b01..Synchronous with transmitter
 *  0b10..Synchronous with another SAI receiver
 *  0b11..Synchronous with another SAI transmitter
 */
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_SYNC_SHIFT)) & I2S_RCR2_SYNC_MASK)
/*! @} */

/*! @name RCR3 - Receive Configuration 3 */
/*! @{ */

#define I2S_RCR3_WDFL_MASK                       (0x1FU)
#define I2S_RCR3_WDFL_SHIFT                      (0U)
/*! WDFL - Word Flag Configuration
 *  0b00000..Word 1
 *  0b00001..Word 2
 *  0b00010-0b11110..Word (WDFL value + 1)
 *  0b11111..Word 32
 */
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_WDFL_SHIFT)) & I2S_RCR3_WDFL_MASK)

#define I2S_RCR3_RCE_MASK                        (0x30000U)
#define I2S_RCR3_RCE_SHIFT                       (16U)
/*! RCE - Receive Channel Enable */
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_RCE_SHIFT)) & I2S_RCR3_RCE_MASK)

#define I2S_RCR3_CFR_MASK                        (0x3000000U)
#define I2S_RCR3_CFR_SHIFT                       (24U)
/*! CFR - Channel FIFO Reset */
#define I2S_RCR3_CFR(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_CFR_SHIFT)) & I2S_RCR3_CFR_MASK)
/*! @} */

/*! @name RCR4 - Receive Configuration 4 */
/*! @{ */

#define I2S_RCR4_FSD_MASK                        (0x1U)
#define I2S_RCR4_FSD_SHIFT                       (0U)
/*! FSD - Frame Sync Direction
 *  0b0..Generated externally in Target mode
 *  0b1..Generated internally in Controller mode
 */
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSD_SHIFT)) & I2S_RCR4_FSD_MASK)

#define I2S_RCR4_FSP_MASK                        (0x2U)
#define I2S_RCR4_FSP_SHIFT                       (1U)
/*! FSP - Frame Sync Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSP_SHIFT)) & I2S_RCR4_FSP_MASK)

#define I2S_RCR4_ONDEM_MASK                      (0x4U)
#define I2S_RCR4_ONDEM_SHIFT                     (2U)
/*! ONDEM - On-Demand Mode
 *  0b0..Generated continuously
 *  0b1..Generated when the FIFO warning flag is 0
 */
#define I2S_RCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_ONDEM_SHIFT)) & I2S_RCR4_ONDEM_MASK)

#define I2S_RCR4_FSE_MASK                        (0x8U)
#define I2S_RCR4_FSE_SHIFT                       (3U)
/*! FSE - Frame Sync Early
 *  0b0..First bit of the frame
 *  0b1..One bit before the first bit of the frame
 */
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSE_SHIFT)) & I2S_RCR4_FSE_MASK)

#define I2S_RCR4_MF_MASK                         (0x10U)
#define I2S_RCR4_MF_SHIFT                        (4U)
/*! MF - MSB First
 *  0b0..LSB
 *  0b1..MSB
 */
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_MF_SHIFT)) & I2S_RCR4_MF_MASK)

#define I2S_RCR4_SYWD_MASK                       (0x1F00U)
#define I2S_RCR4_SYWD_SHIFT                      (8U)
/*! SYWD - Sync Width
 *  0b00000..1
 *  0b00001..2
 *  0b00010-0b11110..(SYWD value + 1)
 *  0b11111..32
 */
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_SYWD_SHIFT)) & I2S_RCR4_SYWD_MASK)

#define I2S_RCR4_FRSZ_MASK                       (0x1F0000U)
#define I2S_RCR4_FRSZ_SHIFT                      (16U)
/*! FRSZ - Frame Size
 *  0b00000..1
 *  0b00001..2
 *  0b00010-0b11110..(FRSZ value + 1)
 *  0b11111..32
 */
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FRSZ_SHIFT)) & I2S_RCR4_FRSZ_MASK)

#define I2S_RCR4_FPACK_MASK                      (0x3000000U)
#define I2S_RCR4_FPACK_SHIFT                     (24U)
/*! FPACK - FIFO Packing Mode
 *  0b00..Disable
 *  0b01..Reserved
 *  0b10..Enable 8-bit FIFO packing
 *  0b11..Enable 16-bit FIFO packing
 */
#define I2S_RCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FPACK_SHIFT)) & I2S_RCR4_FPACK_MASK)

#define I2S_RCR4_FCOMB_MASK                      (0xC000000U)
#define I2S_RCR4_FCOMB_SHIFT                     (26U)
/*! FCOMB - FIFO Combine Mode
 *  0b00..Disable
 *  0b01..Enable on FIFO writes (from receive shift registers)
 *  0b10..Enable on FIFO reads (by software)
 *  0b11..Enable on FIFO writes (from receive shift registers) and reads (by software)
 */
#define I2S_RCR4_FCOMB(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FCOMB_SHIFT)) & I2S_RCR4_FCOMB_MASK)

#define I2S_RCR4_FCONT_MASK                      (0x10000000U)
#define I2S_RCR4_FCONT_SHIFT                     (28U)
/*! FCONT - FIFO Continue on Error
 *  0b0..From the start of the next frame after the FIFO error flag is cleared
 *  0b1..From the same word that caused the FIFO error to become 1 after the FIFO warning flag is cleared
 */
#define I2S_RCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FCONT_SHIFT)) & I2S_RCR4_FCONT_MASK)
/*! @} */

/*! @name RCR5 - Receive Configuration 5 */
/*! @{ */

#define I2S_RCR5_FBT_MASK                        (0x1F00U)
#define I2S_RCR5_FBT_SHIFT                       (8U)
/*! FBT - First Bit Shifted
 *  0b00000..0
 *  0b00001-0b11110..FBT value
 *  0b11111..31
 */
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_FBT_SHIFT)) & I2S_RCR5_FBT_MASK)

#define I2S_RCR5_W0W_MASK                        (0x1F0000U)
#define I2S_RCR5_W0W_SHIFT                       (16U)
/*! W0W - Word 0 Width
 *  0b00000..1
 *  0b00001..2
 *  0b00010-0b11110..(W0W value + 1)
 *  0b11111..32
 */
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_W0W_SHIFT)) & I2S_RCR5_W0W_MASK)

#define I2S_RCR5_WNW_MASK                        (0x1F000000U)
#define I2S_RCR5_WNW_SHIFT                       (24U)
/*! WNW - Word N Width
 *  0b00111..8
 *  0b01000..9
 *  0b01001-0b11110..(WNW value + 1)
 *  0b11111..32
 */
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_WNW_SHIFT)) & I2S_RCR5_WNW_MASK)
/*! @} */

/*! @name RDR - Receive Data */
/*! @{ */

#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFU)
#define I2S_RDR_RDR_SHIFT                        (0U)
/*! RDR - Receive Data */
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RDR_RDR_SHIFT)) & I2S_RDR_RDR_MASK)
/*! @} */

/*! @name RFR - Receive FIFO */
/*! @{ */

#define I2S_RFR_RFP_MASK                         (0xFU)
#define I2S_RFR_RFP_SHIFT                        (0U)
/*! RFP - Read FIFO Pointer */
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_RFP_SHIFT)) & I2S_RFR_RFP_MASK)

#define I2S_RFR_RCP_MASK                         (0x8000U)
#define I2S_RFR_RCP_SHIFT                        (15U)
/*! RCP - Read Channel Pointer
 *  0b0..No effect
 *  0b1..Next FIFO to be read
 */
#define I2S_RFR_RCP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_RCP_SHIFT)) & I2S_RFR_RCP_MASK)

#define I2S_RFR_WFP_MASK                         (0xF0000U)
#define I2S_RFR_WFP_SHIFT                        (16U)
/*! WFP - Write FIFO Pointer */
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_WFP_SHIFT)) & I2S_RFR_WFP_MASK)
/*! @} */

/*! @name RMR - Receive Mask */
/*! @{ */

#define I2S_RMR_RWM_MASK                         (0xFFFFFFFFU)
#define I2S_RMR_RWM_SHIFT                        (0U)
/*! RWM - Receive Word Mask
 *  0b00000000000000000000000000000000..Enable
 *  0b00000000000000000000000000000001..Mask
 */
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RMR_RWM_SHIFT)) & I2S_RMR_RWM_MASK)
/*! @} */

/*! @name MCR - MCLK Control */
/*! @{ */

#define I2S_MCR_DIV_MASK                         (0xFFU)
#define I2S_MCR_DIV_SHIFT                        (0U)
/*! DIV - MCLK Post Divide */
#define I2S_MCR_DIV(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_MCR_DIV_SHIFT)) & I2S_MCR_DIV_MASK)

#define I2S_MCR_DIVEN_MASK                       (0x800000U)
#define I2S_MCR_DIVEN_SHIFT                      (23U)
/*! DIVEN - MCLK Post Divide Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I2S_MCR_DIVEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_MCR_DIVEN_SHIFT)) & I2S_MCR_DIVEN_MASK)

#define I2S_MCR_MSEL_MASK                        (0x3000000U)
#define I2S_MCR_MSEL_SHIFT                       (24U)
/*! MSEL - MCLK Select
 *  0b00..Controller clock (MCLK) option 1
 *  0b01..Reserved
 *  0b10..Controller clock (MCLK) option 2
 *  0b11..Controller clock (MCLK) option 3
 */
#define I2S_MCR_MSEL(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_MCR_MSEL_SHIFT)) & I2S_MCR_MSEL_MASK)

#define I2S_MCR_MOE_MASK                         (0x40000000U)
#define I2S_MCR_MOE_SHIFT                        (30U)
/*! MOE - MCLK Output Enable
 *  0b0..Input
 *  0b1..Output
 */
#define I2S_MCR_MOE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_MCR_MOE_SHIFT)) & I2S_MCR_MOE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group I2S_Register_Masks */


/*!
 * @}
 */ /* end of group I2S_Peripheral_Access_Layer */


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


#endif  /* PERI_I2S_H_ */

