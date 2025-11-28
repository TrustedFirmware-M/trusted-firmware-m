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
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_I2S.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for I2S
 *
 * CMSIS Peripheral Access Layer for I2S
 */

#if !defined(PERI_I2S_H_)
#define PERI_I2S_H_                              /**< Symbol preventing repeated inclusion */

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
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Peripheral_Access_Layer I2S Peripheral Access Layer
 * @{
 */

/** I2S - Size of Registers Arrays */
#define I2S_TDR_COUNT                             4u
#define I2S_TFR_COUNT                             4u
#define I2S_RDR_COUNT                             4u
#define I2S_RFR_COUNT                             4u

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
  __IO uint32_t TDR[I2S_TDR_COUNT];                /**< Transmit Data, array offset: 0x20, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_0[16];
  __I  uint32_t TFR[I2S_TFR_COUNT];                /**< Transmit FIFO, array offset: 0x40, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_1[16];
  __IO uint32_t TMR;                               /**< Transmit Mask, offset: 0x60 */
       uint8_t RESERVED_2[12];
  __IO uint32_t TTCR;                              /**< Transmit Timestamp Control, offset: 0x70 */
  __I  uint32_t TTSR;                              /**< Transmit Timestamp, offset: 0x74 */
  __I  uint32_t TBCR;                              /**< Transmit Bit Count, offset: 0x78 */
  __I  uint32_t TBCTR;                             /**< Transmit Bit Count Timestamp, offset: 0x7C */
       uint8_t RESERVED_3[8];
  __IO uint32_t RCSR;                              /**< Receive Control, offset: 0x88 */
  __IO uint32_t RCR1;                              /**< Receive Configuration 1, offset: 0x8C */
  __IO uint32_t RCR2;                              /**< Receive Configuration 2, offset: 0x90 */
  __IO uint32_t RCR3;                              /**< Receive Configuration 3, offset: 0x94 */
  __IO uint32_t RCR4;                              /**< Receive Configuration 4, offset: 0x98 */
  __IO uint32_t RCR5;                              /**< Receive Configuration 5, offset: 0x9C */
  __I  uint32_t RDR[I2S_RDR_COUNT];                /**< Receive Data, array offset: 0xA0, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_4[16];
  __I  uint32_t RFR[I2S_RFR_COUNT];                /**< Receive FIFO, array offset: 0xC0, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_5[16];
  __IO uint32_t RMR;                               /**< Receive Mask, offset: 0xE0 */
       uint8_t RESERVED_6[12];
  __IO uint32_t RTCR;                              /**< Receive Timestamp Control, offset: 0xF0 */
  __I  uint32_t RTSR;                              /**< Receive Timestamp, offset: 0xF4 */
  __I  uint32_t RBCR;                              /**< Receive Bit Count, offset: 0xF8 */
  __I  uint32_t RBCTR;                             /**< Receive Bit Count Timestamp, offset: 0xFC */
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
 *  0b0000000000000000..Standard feature set.
 *  0b0000000000000010..Standard feature set with timestamp registers.
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
/*! DATALINE - Number of Datalinks */
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
 *  0b0..Disables the DMA request.
 *  0b1..Enables the DMA request.
 */
#define I2S_TCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRDE_SHIFT)) & I2S_TCSR_FRDE_MASK)

#define I2S_TCSR_FWDE_MASK                       (0x2U)
#define I2S_TCSR_FWDE_SHIFT                      (1U)
/*! FWDE - FIFO Warning DMA Enable
 *  0b0..Disables the DMA warning.
 *  0b1..Enables the DMA warning.
 */
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWDE_SHIFT)) & I2S_TCSR_FWDE_MASK)

#define I2S_TCSR_FRIE_MASK                       (0x100U)
#define I2S_TCSR_FRIE_SHIFT                      (8U)
/*! FRIE - FIFO Request Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_TCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRIE_SHIFT)) & I2S_TCSR_FRIE_MASK)

#define I2S_TCSR_FWIE_MASK                       (0x200U)
#define I2S_TCSR_FWIE_SHIFT                      (9U)
/*! FWIE - FIFO Warning Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWIE_SHIFT)) & I2S_TCSR_FWIE_MASK)

#define I2S_TCSR_FEIE_MASK                       (0x400U)
#define I2S_TCSR_FEIE_SHIFT                      (10U)
/*! FEIE - FIFO Error Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEIE_SHIFT)) & I2S_TCSR_FEIE_MASK)

#define I2S_TCSR_SEIE_MASK                       (0x800U)
#define I2S_TCSR_SEIE_SHIFT                      (11U)
/*! SEIE - Sync Error Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEIE_SHIFT)) & I2S_TCSR_SEIE_MASK)

#define I2S_TCSR_WSIE_MASK                       (0x1000U)
#define I2S_TCSR_WSIE_SHIFT                      (12U)
/*! WSIE - Word Start Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_WSIE_SHIFT)) & I2S_TCSR_WSIE_MASK)

#define I2S_TCSR_FRF_MASK                        (0x10000U)
#define I2S_TCSR_FRF_SHIFT                       (16U)
/*! FRF - FIFO Request Flag
 *  0b0..Transmit FIFO watermark has not been reached.
 *  0b1..Transmit FIFO watermark has been reached.
 */
#define I2S_TCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRF_SHIFT)) & I2S_TCSR_FRF_MASK)

#define I2S_TCSR_FWF_MASK                        (0x20000U)
#define I2S_TCSR_FWF_SHIFT                       (17U)
/*! FWF - FIFO Warning Flag
 *  0b0..No enabled transmit FIFO is empty.
 *  0b1..Enabled transmit FIFO is empty.
 */
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWF_SHIFT)) & I2S_TCSR_FWF_MASK)

#define I2S_TCSR_FEF_MASK                        (0x40000U)
#define I2S_TCSR_FEF_SHIFT                       (18U)
/*! FEF - FIFO Error Flag
 *  0b0..Transmit underrun not detected.
 *  0b1..Transmit underrun detected.
 */
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEF_SHIFT)) & I2S_TCSR_FEF_MASK)

#define I2S_TCSR_SEF_MASK                        (0x80000U)
#define I2S_TCSR_SEF_SHIFT                       (19U)
/*! SEF - Sync Error Flag
 *  0b0..Sync error not detected.
 *  0b1..Frame sync error detected.
 */
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEF_SHIFT)) & I2S_TCSR_SEF_MASK)

#define I2S_TCSR_WSF_MASK                        (0x100000U)
#define I2S_TCSR_WSF_SHIFT                       (20U)
/*! WSF - Word Start Flag
 *  0b0..Start of word not detected.
 *  0b1..Start of word detected.
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
 *  0b0..No effect.
 *  0b1..FIFO reset.
 */
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FR_SHIFT)) & I2S_TCSR_FR_MASK)

#define I2S_TCSR_BCE_MASK                        (0x10000000U)
#define I2S_TCSR_BCE_SHIFT                       (28U)
/*! BCE - Bit Clock Enable
 *  0b0..Transmit bit clock is disabled.
 *  0b1..Transmit bit clock is enabled.
 */
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_BCE_SHIFT)) & I2S_TCSR_BCE_MASK)

#define I2S_TCSR_DBGE_MASK                       (0x20000000U)
#define I2S_TCSR_DBGE_SHIFT                      (29U)
/*! DBGE - Debug Enable
 *  0b0..Transmitter is disabled in Debug mode, after completing the current frame.
 *  0b1..Transmitter is enabled in Debug mode.
 */
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_DBGE_SHIFT)) & I2S_TCSR_DBGE_MASK)

#define I2S_TCSR_STOPE_MASK                      (0x40000000U)
#define I2S_TCSR_STOPE_SHIFT                     (30U)
/*! STOPE - Stop Enable
 *  0b0..Transmitter disabled in Stop mode.
 *  0b1..Transmitter enabled in Stop mode.
 */
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_STOPE_SHIFT)) & I2S_TCSR_STOPE_MASK)

#define I2S_TCSR_TE_MASK                         (0x80000000U)
#define I2S_TCSR_TE_SHIFT                        (31U)
/*! TE - Transmitter Enable
 *  0b0..Transmitter is disabled.
 *  0b1..Transmitter is enabled, or transmitter has been disabled and has not yet reached end of frame.
 */
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_TE_SHIFT)) & I2S_TCSR_TE_MASK)
/*! @} */

/*! @name TCR1 - Transmit Configuration 1 */
/*! @{ */

#define I2S_TCR1_TFW_MASK                        (0x7FU)  /* Merged from fields with different position or width, of widths (5, 7), largest definition used */
#define I2S_TCR1_TFW_SHIFT                       (0U)
/*! TFW - Transmit FIFO Watermark
 *  0b0000000..1 FIFO word
 *  0b0000001..2 FIFO words
 *  0b0000010-0b1111110..(TFW +1) FIFO words
 *  0b1111111..128 FIFO words
 */
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR1_TFW_SHIFT)) & I2S_TCR1_TFW_MASK)  /* Merged from fields with different position or width, of widths (5, 7), largest definition used */
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
 *  0b0..Internal bit clock is generated from bit clock divider.
 *  0b1..Internal bit clock is divide-by-one of the audio master clock.
 */
#define I2S_TCR2_BYP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BYP_SHIFT)) & I2S_TCR2_BYP_MASK)

#define I2S_TCR2_BCD_MASK                        (0x1000000U)
#define I2S_TCR2_BCD_SHIFT                       (24U)
/*! BCD - Bit Clock Direction
 *  0b0..Bit clock is generated externally in Slave mode.
 *  0b1..Bit clock is generated internally in Master mode.
 */
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCD_SHIFT)) & I2S_TCR2_BCD_MASK)

#define I2S_TCR2_BCP_MASK                        (0x2000000U)
#define I2S_TCR2_BCP_SHIFT                       (25U)
/*! BCP - Bit Clock Polarity
 *  0b0..Bit clock is active high with drive outputs on rising edge and sample inputs on falling edge.
 *  0b1..Bit clock is active low with drive outputs on falling edge and sample inputs on rising edge.
 */
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCP_SHIFT)) & I2S_TCR2_BCP_MASK)

#define I2S_TCR2_MSEL_MASK                       (0xC000000U)
#define I2S_TCR2_MSEL_SHIFT                      (26U)
/*! MSEL - MCLK Select
 *  0b00..Bus Clock selected.
 *  0b01..Master Clock (MCLK) 1 option selected.
 *  0b10..Master Clock (MCLK) 2 option selected.
 *  0b11..Master Clock (MCLK) 3 option selected.
 */
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_MSEL_SHIFT)) & I2S_TCR2_MSEL_MASK)

#define I2S_TCR2_BCI_MASK                        (0x10000000U)
#define I2S_TCR2_BCI_SHIFT                       (28U)
/*! BCI - Bit Clock Input
 *  0b0..No effect.
 *  0b1..Internal logic is clocked as if bit clock was externally generated.
 */
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCI_SHIFT)) & I2S_TCR2_BCI_MASK)

#define I2S_TCR2_BCS_MASK                        (0x20000000U)
#define I2S_TCR2_BCS_SHIFT                       (29U)
/*! BCS - Bit Clock Swap
 *  0b0..Use the normal bit clock source.
 *  0b1..Swap the bit clock source.
 */
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCS_SHIFT)) & I2S_TCR2_BCS_MASK)

#define I2S_TCR2_SYNC_MASK                       (0x40000000U)
#define I2S_TCR2_SYNC_SHIFT                      (30U)
/*! SYNC - Synchronous Mode
 *  0b0..Asynchronous mode
 *  0b1..Synchronous with receiver
 */
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_SYNC_SHIFT)) & I2S_TCR2_SYNC_MASK)
/*! @} */

/*! @name TCR3 - Transmit Configuration 3 */
/*! @{ */

#define I2S_TCR3_WDFL_MASK                       (0x1FU)
#define I2S_TCR3_WDFL_SHIFT                      (0U)
/*! WDFL - Word Flag Configuration */
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_WDFL_SHIFT)) & I2S_TCR3_WDFL_MASK)

#define I2S_TCR3_TCE_MASK                        (0xF0000U)  /* Merged from fields with different position or width, of widths (1, 2, 4), largest definition used */
#define I2S_TCR3_TCE_SHIFT                       (16U)
/*! TCE - Transmit Channel Enable */
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_TCE_SHIFT)) & I2S_TCR3_TCE_MASK)  /* Merged from fields with different position or width, of widths (1, 2, 4), largest definition used */

#define I2S_TCR3_CFR_MASK                        (0xF000000U)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define I2S_TCR3_CFR_SHIFT                       (24U)
/*! CFR - Channel FIFO Reset */
#define I2S_TCR3_CFR(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_CFR_SHIFT)) & I2S_TCR3_CFR_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
/*! @} */

/*! @name TCR4 - Transmit Configuration 4 */
/*! @{ */

#define I2S_TCR4_FSD_MASK                        (0x1U)
#define I2S_TCR4_FSD_SHIFT                       (0U)
/*! FSD - Frame Sync Direction
 *  0b0..Frame sync is generated externally in Slave mode.
 *  0b1..Frame sync is generated internally in Master mode.
 */
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSD_SHIFT)) & I2S_TCR4_FSD_MASK)

#define I2S_TCR4_FSP_MASK                        (0x2U)
#define I2S_TCR4_FSP_SHIFT                       (1U)
/*! FSP - Frame Sync Polarity
 *  0b0..Frame sync is active high.
 *  0b1..Frame sync is active low.
 */
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSP_SHIFT)) & I2S_TCR4_FSP_MASK)

#define I2S_TCR4_ONDEM_MASK                      (0x4U)
#define I2S_TCR4_ONDEM_SHIFT                     (2U)
/*! ONDEM - On Demand Mode
 *  0b0..Internal frame sync is generated continuously.
 *  0b1..Internal frame sync is generated when the FIFO warning flag is 0.
 */
#define I2S_TCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_ONDEM_SHIFT)) & I2S_TCR4_ONDEM_MASK)

#define I2S_TCR4_FSE_MASK                        (0x8U)
#define I2S_TCR4_FSE_SHIFT                       (3U)
/*! FSE - Frame Sync Early
 *  0b0..Frame sync asserts with the first bit of the frame.
 *  0b1..Frame sync asserts one bit before the first bit of the frame.
 */
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSE_SHIFT)) & I2S_TCR4_FSE_MASK)

#define I2S_TCR4_MF_MASK                         (0x10U)
#define I2S_TCR4_MF_SHIFT                        (4U)
/*! MF - MSB First
 *  0b0..LSB is transmitted first.
 *  0b1..MSB is transmitted first.
 */
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_MF_SHIFT)) & I2S_TCR4_MF_MASK)

#define I2S_TCR4_CHMOD_MASK                      (0x20U)
#define I2S_TCR4_CHMOD_SHIFT                     (5U)
/*! CHMOD - Channel Mode
 *  0b0..TDM mode, transmit data pins are 3-stated when slots are masked or channels are disabled.
 *  0b1..Output mode, transmit data pins are never 3-stated and output zero when slots are masked or channels are disabled.
 */
#define I2S_TCR4_CHMOD(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_CHMOD_SHIFT)) & I2S_TCR4_CHMOD_MASK)

#define I2S_TCR4_SYWD_MASK                       (0x1F00U)
#define I2S_TCR4_SYWD_SHIFT                      (8U)
/*! SYWD - Sync Width */
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_SYWD_SHIFT)) & I2S_TCR4_SYWD_MASK)

#define I2S_TCR4_FRSZ_MASK                       (0x1F0000U)
#define I2S_TCR4_FRSZ_SHIFT                      (16U)
/*! FRSZ - Frame size */
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FRSZ_SHIFT)) & I2S_TCR4_FRSZ_MASK)

#define I2S_TCR4_FPACK_MASK                      (0x3000000U)
#define I2S_TCR4_FPACK_SHIFT                     (24U)
/*! FPACK - FIFO Packing Mode
 *  0b00..FIFO packing is disabled.
 *  0b01..Reserved
 *  0b10..8-bit FIFO packing is enabled.
 *  0b11..16-bit FIFO packing is enabled.
 */
#define I2S_TCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FPACK_SHIFT)) & I2S_TCR4_FPACK_MASK)

#define I2S_TCR4_FCOMB_MASK                      (0xC000000U)
#define I2S_TCR4_FCOMB_SHIFT                     (26U)
/*! FCOMB - FIFO Combine Mode
 *  0b00..FIFO Combine mode disabled.
 *  0b01..FIFO Combine mode enabled on FIFO reads (from transmit shift registers).
 *  0b10..FIFO Combine mode enabled on FIFO writes (by software).
 *  0b11..FIFO Combine mode enabled on FIFO reads (from transmit shift registers) and writes (by software).
 */
#define I2S_TCR4_FCOMB(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FCOMB_SHIFT)) & I2S_TCR4_FCOMB_MASK)

#define I2S_TCR4_FCONT_MASK                      (0x10000000U)
#define I2S_TCR4_FCONT_SHIFT                     (28U)
/*! FCONT - FIFO Continue on Error
 *  0b0..On FIFO error, SAI continues from the start of the next frame after the FIFO error flag has been cleared.
 *  0b1..On FIFO error, SAI continues from the same word that caused the FIFO error to become 1 after the FIFO warning flag returns to 0.
 */
#define I2S_TCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FCONT_SHIFT)) & I2S_TCR4_FCONT_MASK)
/*! @} */

/*! @name TCR5 - Transmit Configuration 5 */
/*! @{ */

#define I2S_TCR5_FBT_MASK                        (0x1F00U)
#define I2S_TCR5_FBT_SHIFT                       (8U)
/*! FBT - First Bit Shifted
 *  0b00000..Bit index is 0.
 *  0b00001-0b11110..Bit index is FBT value.
 *  0b11111..Bit index is 31.
 */
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_FBT_SHIFT)) & I2S_TCR5_FBT_MASK)

#define I2S_TCR5_W0W_MASK                        (0x1F0000U)
#define I2S_TCR5_W0W_SHIFT                       (16U)
/*! W0W - Word 0 Width
 *  0b00111..8 bits per word
 *  0b01000..9 bits per word
 *  0b01001-0b11110..(W0W value + 1) bits per word
 *  0b11111..32 bits per word
 */
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_W0W_SHIFT)) & I2S_TCR5_W0W_MASK)

#define I2S_TCR5_WNW_MASK                        (0x1F000000U)
#define I2S_TCR5_WNW_SHIFT                       (24U)
/*! WNW - Word N Width
 *  0b00111..8 bits per word
 *  0b01000..9 bits per word
 *  0b01001-0b11110..(WNW value + 1) bits per word
 *  0b11111..32 bits per word
 */
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_WNW_SHIFT)) & I2S_TCR5_WNW_MASK)
/*! @} */

/*! @name TDR - Transmit Data */
/*! @{ */

#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFU)
#define I2S_TDR_TDR_SHIFT                        (0U)
/*! TDR - Transmit Data Register */
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TDR_TDR_SHIFT)) & I2S_TDR_TDR_MASK)
/*! @} */

/*! @name TFR - Transmit FIFO */
/*! @{ */

#define I2S_TFR_RFP_MASK                         (0xFFU)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */
#define I2S_TFR_RFP_SHIFT                        (0U)
/*! RFP - Read FIFO Pointer */
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_RFP_SHIFT)) & I2S_TFR_RFP_MASK)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */

#define I2S_TFR_WFP_MASK                         (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */
#define I2S_TFR_WFP_SHIFT                        (16U)
/*! WFP - Write FIFO Pointer */
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_WFP_SHIFT)) & I2S_TFR_WFP_MASK)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */

#define I2S_TFR_WCP_MASK                         (0x80000000U)
#define I2S_TFR_WCP_SHIFT                        (31U)
/*! WCP - Write Channel Pointer
 *  0b0..No effect
 *  0b1..FIFO Combine mode is enabled for FIFO writes and this FIFO will be written on the next FIFO write.
 */
#define I2S_TFR_WCP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_WCP_SHIFT)) & I2S_TFR_WCP_MASK)
/*! @} */

/*! @name TMR - Transmit Mask */
/*! @{ */

#define I2S_TMR_TWM_MASK                         (0xFFFFFFFFU)
#define I2S_TMR_TWM_SHIFT                        (0U)
/*! TWM - Transmit Word Mask
 *  0b00000000000000000000000000000000..Word N is enabled.
 *  0b00000000000000000000000000000001..Word N is masked. The transmit data pins are 3-stated or drive zero when masked.
 */
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TMR_TWM_SHIFT)) & I2S_TMR_TWM_MASK)
/*! @} */

/*! @name TTCR - Transmit Timestamp Control */
/*! @{ */

#define I2S_TTCR_TSEN_MASK                       (0x1U)
#define I2S_TTCR_TSEN_SHIFT                      (0U)
/*! TSEN - Timestamp Enable
 *  0b0..Timestamp counter is disabled.
 *  0b1..Timestamp counter is enabled.
 */
#define I2S_TTCR_TSEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TTCR_TSEN_SHIFT)) & I2S_TTCR_TSEN_MASK)

#define I2S_TTCR_TSINC_MASK                      (0x2U)
#define I2S_TTCR_TSINC_SHIFT                     (1U)
/*! TSINC - Timestamp Increment
 *  0b0..Timestamp counter starts to increment when enabled and the bit counter has incremented.
 *  0b1..Timestamp counter starts to increment when enabled.
 */
#define I2S_TTCR_TSINC(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TTCR_TSINC_SHIFT)) & I2S_TTCR_TSINC_MASK)

#define I2S_TTCR_TSSEL_MASK                      (0xCU)
#define I2S_TTCR_TSSEL_SHIFT                     (2U)
/*! TSSEL - Timestamp Select
 *  0b00..Timestamp counter increments when enabled.
 *  0b01..Timestamp counter increments when the receive timestamp counter is enabled.
 *  0b10..Timestamp counter increments when the transmit timestamp counter on another instance is enabled.
 *  0b11..Timestamp counter increments when the receive timestamp counter on another instance is enabled.
 */
#define I2S_TTCR_TSSEL(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TTCR_TSSEL_SHIFT)) & I2S_TTCR_TSSEL_MASK)

#define I2S_TTCR_RTSC_MASK                       (0x100U)
#define I2S_TTCR_RTSC_SHIFT                      (8U)
/*! RTSC - Reset Timestamp Counter
 *  0b0..Timestamp counter is not reset.
 *  0b1..Timestamp counter is reset.
 */
#define I2S_TTCR_RTSC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TTCR_RTSC_SHIFT)) & I2S_TTCR_RTSC_MASK)

#define I2S_TTCR_RBC_MASK                        (0x200U)
#define I2S_TTCR_RBC_SHIFT                       (9U)
/*! RBC - Reset Bit Counter
 *  0b0..Bit counter is not reset.
 *  0b1..Bit counter is reset.
 */
#define I2S_TTCR_RBC(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TTCR_RBC_SHIFT)) & I2S_TTCR_RBC_MASK)
/*! @} */

/*! @name TTSR - Transmit Timestamp */
/*! @{ */

#define I2S_TTSR_TSC_MASK                        (0xFFFFFFFFU)
#define I2S_TTSR_TSC_SHIFT                       (0U)
/*! TSC - Timestamp Counter */
#define I2S_TTSR_TSC(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TTSR_TSC_SHIFT)) & I2S_TTSR_TSC_MASK)
/*! @} */

/*! @name TBCR - Transmit Bit Count */
/*! @{ */

#define I2S_TBCR_BCNT_MASK                       (0xFFFFFFFFU)
#define I2S_TBCR_BCNT_SHIFT                      (0U)
/*! BCNT - Bit Counter */
#define I2S_TBCR_BCNT(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TBCR_BCNT_SHIFT)) & I2S_TBCR_BCNT_MASK)
/*! @} */

/*! @name TBCTR - Transmit Bit Count Timestamp */
/*! @{ */

#define I2S_TBCTR_BCTS_MASK                      (0xFFFFFFFFU)
#define I2S_TBCTR_BCTS_SHIFT                     (0U)
/*! BCTS - Bit Timestamp */
#define I2S_TBCTR_BCTS(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TBCTR_BCTS_SHIFT)) & I2S_TBCTR_BCTS_MASK)
/*! @} */

/*! @name RCSR - Receive Control */
/*! @{ */

#define I2S_RCSR_FRDE_MASK                       (0x1U)
#define I2S_RCSR_FRDE_SHIFT                      (0U)
/*! FRDE - FIFO Request DMA Enable
 *  0b0..Disables the DMA request.
 *  0b1..Enables the DMA request.
 */
#define I2S_RCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRDE_SHIFT)) & I2S_RCSR_FRDE_MASK)

#define I2S_RCSR_FWDE_MASK                       (0x2U)
#define I2S_RCSR_FWDE_SHIFT                      (1U)
/*! FWDE - FIFO Warning DMA Enable
 *  0b0..Disables DMA warnings.
 *  0b1..Enables DMA warnings.
 */
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWDE_SHIFT)) & I2S_RCSR_FWDE_MASK)

#define I2S_RCSR_FRIE_MASK                       (0x100U)
#define I2S_RCSR_FRIE_SHIFT                      (8U)
/*! FRIE - FIFO Request Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_RCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRIE_SHIFT)) & I2S_RCSR_FRIE_MASK)

#define I2S_RCSR_FWIE_MASK                       (0x200U)
#define I2S_RCSR_FWIE_SHIFT                      (9U)
/*! FWIE - FIFO Warning Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWIE_SHIFT)) & I2S_RCSR_FWIE_MASK)

#define I2S_RCSR_FEIE_MASK                       (0x400U)
#define I2S_RCSR_FEIE_SHIFT                      (10U)
/*! FEIE - FIFO Error Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEIE_SHIFT)) & I2S_RCSR_FEIE_MASK)

#define I2S_RCSR_SEIE_MASK                       (0x800U)
#define I2S_RCSR_SEIE_SHIFT                      (11U)
/*! SEIE - Sync Error Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEIE_SHIFT)) & I2S_RCSR_SEIE_MASK)

#define I2S_RCSR_WSIE_MASK                       (0x1000U)
#define I2S_RCSR_WSIE_SHIFT                      (12U)
/*! WSIE - Word Start Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSIE_SHIFT)) & I2S_RCSR_WSIE_MASK)

#define I2S_RCSR_FRF_MASK                        (0x10000U)
#define I2S_RCSR_FRF_SHIFT                       (16U)
/*! FRF - FIFO Request Flag
 *  0b0..Receive FIFO watermark not reached.
 *  0b1..Receive FIFO watermark has been reached.
 */
#define I2S_RCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRF_SHIFT)) & I2S_RCSR_FRF_MASK)

#define I2S_RCSR_FWF_MASK                        (0x20000U)
#define I2S_RCSR_FWF_SHIFT                       (17U)
/*! FWF - FIFO Warning Flag
 *  0b0..No enabled receive FIFO is full.
 *  0b1..Enabled receive FIFO is full.
 */
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWF_SHIFT)) & I2S_RCSR_FWF_MASK)

#define I2S_RCSR_FEF_MASK                        (0x40000U)
#define I2S_RCSR_FEF_SHIFT                       (18U)
/*! FEF - FIFO Error Flag
 *  0b0..Receive overflow not detected.
 *  0b1..Receive overflow detected.
 */
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEF_SHIFT)) & I2S_RCSR_FEF_MASK)

#define I2S_RCSR_SEF_MASK                        (0x80000U)
#define I2S_RCSR_SEF_SHIFT                       (19U)
/*! SEF - Sync Error Flag
 *  0b0..Sync error not detected.
 *  0b1..Frame sync error detected.
 */
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEF_SHIFT)) & I2S_RCSR_SEF_MASK)

#define I2S_RCSR_WSF_MASK                        (0x100000U)
#define I2S_RCSR_WSF_SHIFT                       (20U)
/*! WSF - Word Start Flag
 *  0b0..Start of word not detected.
 *  0b1..Start of word detected.
 */
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSF_SHIFT)) & I2S_RCSR_WSF_MASK)

#define I2S_RCSR_SR_MASK                         (0x1000000U)
#define I2S_RCSR_SR_SHIFT                        (24U)
/*! SR - Software Reset
 *  0b0..No effect.
 *  0b1..Software reset.
 */
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SR_SHIFT)) & I2S_RCSR_SR_MASK)

#define I2S_RCSR_FR_MASK                         (0x2000000U)
#define I2S_RCSR_FR_SHIFT                        (25U)
/*! FR - FIFO Reset
 *  0b0..No effect.
 *  0b1..FIFO reset.
 */
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FR_SHIFT)) & I2S_RCSR_FR_MASK)

#define I2S_RCSR_BCE_MASK                        (0x10000000U)
#define I2S_RCSR_BCE_SHIFT                       (28U)
/*! BCE - Bit Clock Enable
 *  0b0..Receive bit clock is disabled.
 *  0b1..Receive bit clock is enabled.
 */
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_BCE_SHIFT)) & I2S_RCSR_BCE_MASK)

#define I2S_RCSR_DBGE_MASK                       (0x20000000U)
#define I2S_RCSR_DBGE_SHIFT                      (29U)
/*! DBGE - Debug Enable
 *  0b0..Receiver is disabled in Debug mode, after completing the current frame.
 *  0b1..Receiver is enabled in Debug mode.
 */
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_DBGE_SHIFT)) & I2S_RCSR_DBGE_MASK)

#define I2S_RCSR_STOPE_MASK                      (0x40000000U)
#define I2S_RCSR_STOPE_SHIFT                     (30U)
/*! STOPE - Stop Enable
 *  0b0..Receiver disabled in Stop mode.
 *  0b1..Receiver enabled in Stop mode.
 */
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_STOPE_SHIFT)) & I2S_RCSR_STOPE_MASK)

#define I2S_RCSR_RE_MASK                         (0x80000000U)
#define I2S_RCSR_RE_SHIFT                        (31U)
/*! RE - Receiver Enable
 *  0b0..Receiver is disabled.
 *  0b1..Receiver is enabled, or receiver has been disabled and has not yet reached end of frame.
 */
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_RE_SHIFT)) & I2S_RCSR_RE_MASK)
/*! @} */

/*! @name RCR1 - Receive Configuration 1 */
/*! @{ */

#define I2S_RCR1_RFW_MASK                        (0x7FU)  /* Merged from fields with different position or width, of widths (5, 7), largest definition used */
#define I2S_RCR1_RFW_SHIFT                       (0U)
/*! RFW - Receive FIFO Watermark
 *  0b0000000..1 FIFO word
 *  0b0000001..2 FIFO words
 *  0b0000010-0b1111110..(RFW value + 1) FIFO words
 *  0b1111111..128 FIFO words
 */
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR1_RFW_SHIFT)) & I2S_RCR1_RFW_MASK)  /* Merged from fields with different position or width, of widths (5, 7), largest definition used */
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
 *  0b0..Internal bit clock is generated from bit clock divider.
 *  0b1..Internal bit clock is divide-by-one of the audio master clock.
 */
#define I2S_RCR2_BYP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BYP_SHIFT)) & I2S_RCR2_BYP_MASK)

#define I2S_RCR2_BCD_MASK                        (0x1000000U)
#define I2S_RCR2_BCD_SHIFT                       (24U)
/*! BCD - Bit Clock Direction
 *  0b0..Bit clock is generated externally in Slave mode.
 *  0b1..Bit clock is generated internally in Master mode.
 */
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCD_SHIFT)) & I2S_RCR2_BCD_MASK)

#define I2S_RCR2_BCP_MASK                        (0x2000000U)
#define I2S_RCR2_BCP_SHIFT                       (25U)
/*! BCP - Bit Clock Polarity
 *  0b0..Bit clock is active high with drive outputs on rising edge and sample inputs on falling edge.
 *  0b1..Bit clock is active low with drive outputs on falling edge and sample inputs on rising edge.
 */
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCP_SHIFT)) & I2S_RCR2_BCP_MASK)

#define I2S_RCR2_MSEL_MASK                       (0xC000000U)
#define I2S_RCR2_MSEL_SHIFT                      (26U)
/*! MSEL - MCLK Select
 *  0b00..Bus Clock selected.
 *  0b01..Master Clock (MCLK) 1 option selected.
 *  0b10..Master Clock (MCLK) 2 option selected.
 *  0b11..Master Clock (MCLK) 3 option selected.
 */
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_MSEL_SHIFT)) & I2S_RCR2_MSEL_MASK)

#define I2S_RCR2_BCI_MASK                        (0x10000000U)
#define I2S_RCR2_BCI_SHIFT                       (28U)
/*! BCI - Bit Clock Input
 *  0b0..No effect.
 *  0b1..Internal logic is clocked as if bit clock was externally generated.
 */
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCI_SHIFT)) & I2S_RCR2_BCI_MASK)

#define I2S_RCR2_BCS_MASK                        (0x20000000U)
#define I2S_RCR2_BCS_SHIFT                       (29U)
/*! BCS - Bit Clock Swap
 *  0b0..Use the normal bit clock source.
 *  0b1..Swap the bit clock source.
 */
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCS_SHIFT)) & I2S_RCR2_BCS_MASK)

#define I2S_RCR2_SYNC_MASK                       (0x40000000U)
#define I2S_RCR2_SYNC_SHIFT                      (30U)
/*! SYNC - Synchronous Mode
 *  0b0..Asynchronous mode
 *  0b1..Synchronous with transmitter
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

#define I2S_RCR3_RCE_MASK                        (0xF0000U)  /* Merged from fields with different position or width, of widths (1, 2, 4), largest definition used */
#define I2S_RCR3_RCE_SHIFT                       (16U)
/*! RCE - Receive Channel Enable */
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_RCE_SHIFT)) & I2S_RCR3_RCE_MASK)  /* Merged from fields with different position or width, of widths (1, 2, 4), largest definition used */

#define I2S_RCR3_CFR_MASK                        (0xF000000U)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define I2S_RCR3_CFR_SHIFT                       (24U)
/*! CFR - Channel FIFO Reset */
#define I2S_RCR3_CFR(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_CFR_SHIFT)) & I2S_RCR3_CFR_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
/*! @} */

/*! @name RCR4 - Receive Configuration 4 */
/*! @{ */

#define I2S_RCR4_FSD_MASK                        (0x1U)
#define I2S_RCR4_FSD_SHIFT                       (0U)
/*! FSD - Frame Sync Direction
 *  0b0..Frame Sync is generated externally in Slave mode.
 *  0b1..Frame Sync is generated internally in Master mode.
 */
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSD_SHIFT)) & I2S_RCR4_FSD_MASK)

#define I2S_RCR4_FSP_MASK                        (0x2U)
#define I2S_RCR4_FSP_SHIFT                       (1U)
/*! FSP - Frame Sync Polarity
 *  0b0..Frame sync is active high.
 *  0b1..Frame sync is active low.
 */
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSP_SHIFT)) & I2S_RCR4_FSP_MASK)

#define I2S_RCR4_ONDEM_MASK                      (0x4U)
#define I2S_RCR4_ONDEM_SHIFT                     (2U)
/*! ONDEM - On Demand Mode
 *  0b0..Internal frame sync is generated continuously.
 *  0b1..Internal frame sync is generated when the FIFO warning flag is 0.
 */
#define I2S_RCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_ONDEM_SHIFT)) & I2S_RCR4_ONDEM_MASK)

#define I2S_RCR4_FSE_MASK                        (0x8U)
#define I2S_RCR4_FSE_SHIFT                       (3U)
/*! FSE - Frame Sync Early
 *  0b0..Frame sync asserts with the first bit of the frame.
 *  0b1..Frame sync asserts one bit before the first bit of the frame.
 */
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSE_SHIFT)) & I2S_RCR4_FSE_MASK)

#define I2S_RCR4_MF_MASK                         (0x10U)
#define I2S_RCR4_MF_SHIFT                        (4U)
/*! MF - MSB First
 *  0b0..LSB is received first.
 *  0b1..MSB is received first.
 */
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_MF_SHIFT)) & I2S_RCR4_MF_MASK)

#define I2S_RCR4_SYWD_MASK                       (0x1F00U)
#define I2S_RCR4_SYWD_SHIFT                      (8U)
/*! SYWD - Sync Width
 *  0b00000..1 bit-clock cycle
 *  0b00001..2 bit-clock cycle
 *  0b00010-0b11110..(SYWD value + 1) bit-clock cycle
 *  0b11111..32 bit-clock cycle
 */
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_SYWD_SHIFT)) & I2S_RCR4_SYWD_MASK)

#define I2S_RCR4_FRSZ_MASK                       (0x1F0000U)
#define I2S_RCR4_FRSZ_SHIFT                      (16U)
/*! FRSZ - Frame Size
 *  0b00000..1 word per frame
 *  0b00001..2 words per frame
 *  0b00010-0b11110..(FRSZ value + 1) words per frame
 *  0b11111..32 words per frame
 */
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FRSZ_SHIFT)) & I2S_RCR4_FRSZ_MASK)

#define I2S_RCR4_FPACK_MASK                      (0x3000000U)
#define I2S_RCR4_FPACK_SHIFT                     (24U)
/*! FPACK - FIFO Packing Mode
 *  0b00..FIFO packing is disabled
 *  0b01..Reserved
 *  0b10..8-bit FIFO packing is enabled
 *  0b11..16-bit FIFO packing is enabled
 */
#define I2S_RCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FPACK_SHIFT)) & I2S_RCR4_FPACK_MASK)

#define I2S_RCR4_FCOMB_MASK                      (0xC000000U)
#define I2S_RCR4_FCOMB_SHIFT                     (26U)
/*! FCOMB - FIFO Combine Mode
 *  0b00..FIFO Combine mode disabled.
 *  0b01..FIFO Combine mode enabled on FIFO writes (from receive shift registers).
 *  0b10..FIFO Combine mode enabled on FIFO reads (by software).
 *  0b11..FIFO Combine mode enabled on FIFO writes (from receive shift registers) and reads (by software).
 */
#define I2S_RCR4_FCOMB(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FCOMB_SHIFT)) & I2S_RCR4_FCOMB_MASK)

#define I2S_RCR4_FCONT_MASK                      (0x10000000U)
#define I2S_RCR4_FCONT_SHIFT                     (28U)
/*! FCONT - FIFO Continue on Error
 *  0b0..On FIFO error, SAI continues from the start of the next frame after the FIFO error flag returns to 0.
 *  0b1..On FIFO error, SAI continues from the same word that caused the FIFO error to become 1 after the FIFO warning flag returns to 0.
 */
#define I2S_RCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FCONT_SHIFT)) & I2S_RCR4_FCONT_MASK)
/*! @} */

/*! @name RCR5 - Receive Configuration 5 */
/*! @{ */

#define I2S_RCR5_FBT_MASK                        (0x1F00U)
#define I2S_RCR5_FBT_SHIFT                       (8U)
/*! FBT - First Bit Shifted
 *  0b00000..Bit index is 0.
 *  0b00001-0b11110..Bit index is FBT value.
 *  0b11111..Bit index is 31.
 */
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_FBT_SHIFT)) & I2S_RCR5_FBT_MASK)

#define I2S_RCR5_W0W_MASK                        (0x1F0000U)
#define I2S_RCR5_W0W_SHIFT                       (16U)
/*! W0W - Word 0 Width
 *  0b00000..1 bit per word
 *  0b00001..2 bits per word
 *  0b00010-0b11110..(W0W value + 1) bits per word
 *  0b11111..32 bits per word
 */
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_W0W_SHIFT)) & I2S_RCR5_W0W_MASK)

#define I2S_RCR5_WNW_MASK                        (0x1F000000U)
#define I2S_RCR5_WNW_SHIFT                       (24U)
/*! WNW - Word N Width
 *  0b00111..8 bits per word
 *  0b01000..9 bits per word
 *  0b01001-0b11110..(WNW value + 1) bits per word
 *  0b11111..32 bits per word
 */
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_WNW_SHIFT)) & I2S_RCR5_WNW_MASK)
/*! @} */

/*! @name RDR - Receive Data */
/*! @{ */

#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFU)
#define I2S_RDR_RDR_SHIFT                        (0U)
/*! RDR - Receive Data Register */
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RDR_RDR_SHIFT)) & I2S_RDR_RDR_MASK)
/*! @} */

/*! @name RFR - Receive FIFO */
/*! @{ */

#define I2S_RFR_RFP_MASK                         (0xFFU)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */
#define I2S_RFR_RFP_SHIFT                        (0U)
/*! RFP - Read FIFO Pointer */
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_RFP_SHIFT)) & I2S_RFR_RFP_MASK)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */

#define I2S_RFR_RCP_MASK                         (0x8000U)
#define I2S_RFR_RCP_SHIFT                        (15U)
/*! RCP - Receive Channel Pointer
 *  0b0..No effect.
 *  0b1..FIFO Combine mode is enabled for FIFO reads and this FIFO will be read on the next FIFO read.
 */
#define I2S_RFR_RCP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_RCP_SHIFT)) & I2S_RFR_RCP_MASK)

#define I2S_RFR_WFP_MASK                         (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */
#define I2S_RFR_WFP_SHIFT                        (16U)
/*! WFP - Write FIFO Pointer */
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_WFP_SHIFT)) & I2S_RFR_WFP_MASK)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */
/*! @} */

/*! @name RMR - Receive Mask */
/*! @{ */

#define I2S_RMR_RWM_MASK                         (0xFFFFFFFFU)
#define I2S_RMR_RWM_SHIFT                        (0U)
/*! RWM - Receive Word Mask
 *  0b00000000000000000000000000000000..Word N is enabled.
 *  0b00000000000000000000000000000001..Word N is masked.
 */
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RMR_RWM_SHIFT)) & I2S_RMR_RWM_MASK)
/*! @} */

/*! @name RTCR - Receive Timestamp Control */
/*! @{ */

#define I2S_RTCR_TSEN_MASK                       (0x1U)
#define I2S_RTCR_TSEN_SHIFT                      (0U)
/*! TSEN - Timestamp Enable
 *  0b0..Timestamp counter is disabled.
 *  0b1..Timestamp counter is enabled.
 */
#define I2S_RTCR_TSEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RTCR_TSEN_SHIFT)) & I2S_RTCR_TSEN_MASK)

#define I2S_RTCR_TSINC_MASK                      (0x2U)
#define I2S_RTCR_TSINC_SHIFT                     (1U)
/*! TSINC - Timestamp Increment
 *  0b0..Timestamp counter starts to increment when enabled and the bit counter has incremented.
 *  0b1..Timestamp counter starts to increment when enabled.
 */
#define I2S_RTCR_TSINC(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RTCR_TSINC_SHIFT)) & I2S_RTCR_TSINC_MASK)

#define I2S_RTCR_TSSEL_MASK                      (0xCU)
#define I2S_RTCR_TSSEL_SHIFT                     (2U)
/*! TSSEL - Timestamp Select
 *  0b00..Timestamp counter increments when enabled.
 *  0b01..Timestamp counter increments when the transmit timestamp counter is enabled.
 *  0b10..Timestamp counter increments when the receive timestamp counter on another instance is enabled.
 *  0b11..Timestamp counter increments when the transmit timestamp counter on another instance is enabled.
 */
#define I2S_RTCR_TSSEL(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RTCR_TSSEL_SHIFT)) & I2S_RTCR_TSSEL_MASK)

#define I2S_RTCR_RTSC_MASK                       (0x100U)
#define I2S_RTCR_RTSC_SHIFT                      (8U)
/*! RTSC - Reset Timestamp Counter
 *  0b0..Timestamp counter is not reset.
 *  0b1..Timestamp counter is reset.
 */
#define I2S_RTCR_RTSC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RTCR_RTSC_SHIFT)) & I2S_RTCR_RTSC_MASK)

#define I2S_RTCR_RBC_MASK                        (0x200U)
#define I2S_RTCR_RBC_SHIFT                       (9U)
/*! RBC - Reset Bit Counter
 *  0b0..Bit counter is not reset.
 *  0b1..Bit counter is reset.
 */
#define I2S_RTCR_RBC(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RTCR_RBC_SHIFT)) & I2S_RTCR_RBC_MASK)
/*! @} */

/*! @name RTSR - Receive Timestamp */
/*! @{ */

#define I2S_RTSR_TSC_MASK                        (0xFFFFFFFFU)
#define I2S_RTSR_TSC_SHIFT                       (0U)
/*! TSC - Timestamp Counter */
#define I2S_RTSR_TSC(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RTSR_TSC_SHIFT)) & I2S_RTSR_TSC_MASK)
/*! @} */

/*! @name RBCR - Receive Bit Count */
/*! @{ */

#define I2S_RBCR_BCNT_MASK                       (0xFFFFFFFFU)
#define I2S_RBCR_BCNT_SHIFT                      (0U)
/*! BCNT - Bit Counter */
#define I2S_RBCR_BCNT(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RBCR_BCNT_SHIFT)) & I2S_RBCR_BCNT_MASK)
/*! @} */

/*! @name RBCTR - Receive Bit Count Timestamp */
/*! @{ */

#define I2S_RBCTR_BCTS_MASK                      (0xFFFFFFFFU)
#define I2S_RBCTR_BCTS_SHIFT                     (0U)
/*! BCTS - Bit Timestamp */
#define I2S_RBCTR_BCTS(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RBCTR_BCTS_SHIFT)) & I2S_RBCTR_BCTS_MASK)
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
 *  0b0..Output on MCLK signal pin is the audio master clock.
 *  0b1..Output on MCLK signal pin is a post-divided version of audio master clock.
 */
#define I2S_MCR_DIVEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_MCR_DIVEN_SHIFT)) & I2S_MCR_DIVEN_MASK)

#define I2S_MCR_MSEL_MASK                        (0x3000000U)
#define I2S_MCR_MSEL_SHIFT                       (24U)
/*! MSEL - MCLK Select
 *  0b00..Master Clock (MCLK) 1 option selected.
 *  0b01..Reserved
 *  0b10..Master Clock (MCLK) 2 option selected.
 *  0b11..Master Clock (MCLK) 3 option selected.
 */
#define I2S_MCR_MSEL(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_MCR_MSEL_SHIFT)) & I2S_MCR_MSEL_MASK)

#define I2S_MCR_MOE_MASK                         (0x40000000U)
#define I2S_MCR_MOE_SHIFT                        (30U)
/*! MOE - MCLK Output Enable
 *  0b0..MCLK signal pin is an input.
 *  0b1..MCLK signal pin is an output.
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
