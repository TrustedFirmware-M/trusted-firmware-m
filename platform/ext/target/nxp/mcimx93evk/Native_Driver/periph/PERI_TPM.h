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
**         CMSIS Peripheral Access Layer for TPM
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
 * @file PERI_TPM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TPM
 *
 * CMSIS Peripheral Access Layer for TPM
 */

#if !defined(PERI_TPM_H_)
#define PERI_TPM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- TPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Peripheral_Access_Layer TPM Peripheral Access Layer
 * @{
 */

/** TPM - Size of Registers Arrays */
#define TPM_CONTROLS_COUNT                        4u

/** TPM - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t GLOBAL;                            /**< TPM Global, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SC;                                /**< Status and Control, offset: 0x10 */
  __IO uint32_t CNT;                               /**< Counter, offset: 0x14 */
  __IO uint32_t MOD;                               /**< Modulo, offset: 0x18 */
  __IO uint32_t STATUS;                            /**< Capture and Compare Status, offset: 0x1C */
  struct {                                         /* offset: 0x20, array step: 0x8 */
    __IO uint32_t CnSC;                              /**< Channel n Status and Control, array offset: 0x20, array step: 0x8 */
    __IO uint32_t CnV;                               /**< Channel n Value, array offset: 0x24, array step: 0x8 */
  } CONTROLS[TPM_CONTROLS_COUNT];
       uint8_t RESERVED_1[36];
  __IO uint32_t COMBINE;                           /**< Combine Channel, offset: 0x64 */
       uint8_t RESERVED_2[4];
  __IO uint32_t TRIG;                              /**< Channel Trigger, offset: 0x6C */
  __IO uint32_t POL;                               /**< Channel Polarity, offset: 0x70 */
       uint8_t RESERVED_3[4];
  __IO uint32_t FILTER;                            /**< Filter Control, offset: 0x78 */
       uint8_t RESERVED_4[4];
  __IO uint32_t QDCTRL;                            /**< Quadrature Decoder Control and Status, offset: 0x80 */
  __IO uint32_t CONF;                              /**< Configuration, offset: 0x84 */
} TPM_Type;

/* ----------------------------------------------------------------------------
   -- TPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Register_Masks TPM Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define TPM_VERID_FEATURE_MASK                   (0xFFFFU)
#define TPM_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Identification Number
 *  0b0000000000000001..Standard feature set
 *  0b0000000000000011..Standard feature set with the filter and combine registers implemented
 *  0b0000000000000101..Standard feature set with the quadrature register implemented
 *  0b0000000000000111..Standard feature set with the filter, combine, and quadrature registers implemented
 */
#define TPM_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_VERID_FEATURE_SHIFT)) & TPM_VERID_FEATURE_MASK)

#define TPM_VERID_MINOR_MASK                     (0xFF0000U)
#define TPM_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define TPM_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_VERID_MINOR_SHIFT)) & TPM_VERID_MINOR_MASK)

#define TPM_VERID_MAJOR_MASK                     (0xFF000000U)
#define TPM_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define TPM_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_VERID_MAJOR_SHIFT)) & TPM_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define TPM_PARAM_CHAN_MASK                      (0xFFU)
#define TPM_PARAM_CHAN_SHIFT                     (0U)
/*! CHAN - Channel Count */
#define TPM_PARAM_CHAN(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_PARAM_CHAN_SHIFT)) & TPM_PARAM_CHAN_MASK)

#define TPM_PARAM_TRIG_MASK                      (0xFF00U)
#define TPM_PARAM_TRIG_SHIFT                     (8U)
/*! TRIG - Trigger Count */
#define TPM_PARAM_TRIG(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_PARAM_TRIG_SHIFT)) & TPM_PARAM_TRIG_MASK)

#define TPM_PARAM_WIDTH_MASK                     (0xFF0000U)
#define TPM_PARAM_WIDTH_SHIFT                    (16U)
/*! WIDTH - Counter Width */
#define TPM_PARAM_WIDTH(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_PARAM_WIDTH_SHIFT)) & TPM_PARAM_WIDTH_MASK)
/*! @} */

/*! @name GLOBAL - TPM Global */
/*! @{ */

#define TPM_GLOBAL_NOUPDATE_MASK                 (0x1U)
#define TPM_GLOBAL_NOUPDATE_SHIFT                (0U)
/*! NOUPDATE - No Update
 *  0b0..Internal double-buffered registers update as normal
 *  0b1..Internal double-buffered registers do not update
 */
#define TPM_GLOBAL_NOUPDATE(x)                   (((uint32_t)(((uint32_t)(x)) << TPM_GLOBAL_NOUPDATE_SHIFT)) & TPM_GLOBAL_NOUPDATE_MASK)

#define TPM_GLOBAL_RST_MASK                      (0x2U)
#define TPM_GLOBAL_RST_SHIFT                     (1U)
/*! RST - Software Reset
 *  0b0..Module is not reset
 *  0b1..Module is reset
 */
#define TPM_GLOBAL_RST(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_GLOBAL_RST_SHIFT)) & TPM_GLOBAL_RST_MASK)
/*! @} */

/*! @name SC - Status and Control */
/*! @{ */

#define TPM_SC_PS_MASK                           (0x7U)
#define TPM_SC_PS_SHIFT                          (0U)
/*! PS - Prescale Factor Selection
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 4
 *  0b011..Divide by 8
 *  0b100..Divide by 16
 *  0b101..Divide by 32
 *  0b110..Divide by 64
 *  0b111..Divide by 128
 */
#define TPM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x)) << TPM_SC_PS_SHIFT)) & TPM_SC_PS_MASK)

#define TPM_SC_CMOD_MASK                         (0x18U)
#define TPM_SC_CMOD_SHIFT                        (3U)
/*! CMOD - Clock Mode Selection
 *  0b00..TPM counter is disabled
 *  0b01..TPM counter increments on every TPM counter clock
 *  0b10..TPM counter increments on the rising edge of EXTCLK synchronized to the TPM counter clock
 *  0b11..TPM counter increments on the rising edge of the selected external input trigger
 */
#define TPM_SC_CMOD(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_SC_CMOD_SHIFT)) & TPM_SC_CMOD_MASK)

#define TPM_SC_CPWMS_MASK                        (0x20U)
#define TPM_SC_CPWMS_SHIFT                       (5U)
/*! CPWMS - Center-Aligned PWM Select
 *  0b0..Up counting mode
 *  0b1..Up-down counting mode
 */
#define TPM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_SC_CPWMS_SHIFT)) & TPM_SC_CPWMS_MASK)

#define TPM_SC_TOIE_MASK                         (0x40U)
#define TPM_SC_TOIE_SHIFT                        (6U)
/*! TOIE - Timer Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TPM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_SC_TOIE_SHIFT)) & TPM_SC_TOIE_MASK)

#define TPM_SC_TOF_MASK                          (0x80U)
#define TPM_SC_TOF_SHIFT                         (7U)
/*! TOF - Timer Overflow Flag
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define TPM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x)) << TPM_SC_TOF_SHIFT)) & TPM_SC_TOF_MASK)

#define TPM_SC_DMA_MASK                          (0x100U)
#define TPM_SC_DMA_SHIFT                         (8U)
/*! DMA - DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TPM_SC_DMA(x)                            (((uint32_t)(((uint32_t)(x)) << TPM_SC_DMA_SHIFT)) & TPM_SC_DMA_MASK)
/*! @} */

/*! @name CNT - Counter */
/*! @{ */

#define TPM_CNT_COUNT_MASK                       (0xFFFFFFFFU)
#define TPM_CNT_COUNT_SHIFT                      (0U)
/*! COUNT - Counter Value */
#define TPM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CNT_COUNT_SHIFT)) & TPM_CNT_COUNT_MASK)
/*! @} */

/*! @name MOD - Modulo */
/*! @{ */

#define TPM_MOD_MOD_MASK                         (0xFFFFFFFFU)
#define TPM_MOD_MOD_SHIFT                        (0U)
/*! MOD - Modulo Value */
#define TPM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_MOD_MOD_SHIFT)) & TPM_MOD_MOD_MASK)
/*! @} */

/*! @name STATUS - Capture and Compare Status */
/*! @{ */

#define TPM_STATUS_CH0F_MASK                     (0x1U)
#define TPM_STATUS_CH0F_SHIFT                    (0U)
/*! CH0F - Channel 0 Flag
 *  0b0..Event not occurred
 *  0b1..Event occurred
 */
#define TPM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH0F_SHIFT)) & TPM_STATUS_CH0F_MASK)

#define TPM_STATUS_CH1F_MASK                     (0x2U)
#define TPM_STATUS_CH1F_SHIFT                    (1U)
/*! CH1F - Channel 1 Flag
 *  0b0..Event not occurred
 *  0b1..Event occurred
 */
#define TPM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH1F_SHIFT)) & TPM_STATUS_CH1F_MASK)

#define TPM_STATUS_CH2F_MASK                     (0x4U)
#define TPM_STATUS_CH2F_SHIFT                    (2U)
/*! CH2F - Channel 2 Flag
 *  0b0..Event not occurred
 *  0b1..Event occurred
 */
#define TPM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH2F_SHIFT)) & TPM_STATUS_CH2F_MASK)

#define TPM_STATUS_CH3F_MASK                     (0x8U)
#define TPM_STATUS_CH3F_SHIFT                    (3U)
/*! CH3F - Channel 3 Flag
 *  0b0..Event not occurred
 *  0b1..Event occurred
 */
#define TPM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH3F_SHIFT)) & TPM_STATUS_CH3F_MASK)

#define TPM_STATUS_TOF_MASK                      (0x100U)
#define TPM_STATUS_TOF_SHIFT                     (8U)
/*! TOF - Timer Overflow Flag
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define TPM_STATUS_TOF(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_TOF_SHIFT)) & TPM_STATUS_TOF_MASK)
/*! @} */

/*! @name CnSC - Channel n Status and Control */
/*! @{ */

#define TPM_CnSC_DMA_MASK                        (0x1U)
#define TPM_CnSC_DMA_SHIFT                       (0U)
/*! DMA - DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TPM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_DMA_SHIFT)) & TPM_CnSC_DMA_MASK)

#define TPM_CnSC_ELSA_MASK                       (0x4U)
#define TPM_CnSC_ELSA_SHIFT                      (2U)
/*! ELSA - Edge or Level Select A */
#define TPM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_ELSA_SHIFT)) & TPM_CnSC_ELSA_MASK)

#define TPM_CnSC_ELSB_MASK                       (0x8U)
#define TPM_CnSC_ELSB_SHIFT                      (3U)
/*! ELSB - Edge or Level Select B */
#define TPM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_ELSB_SHIFT)) & TPM_CnSC_ELSB_MASK)

#define TPM_CnSC_MSA_MASK                        (0x10U)
#define TPM_CnSC_MSA_SHIFT                       (4U)
/*! MSA - Channel Mode Select A */
#define TPM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_MSA_SHIFT)) & TPM_CnSC_MSA_MASK)

#define TPM_CnSC_MSB_MASK                        (0x20U)
#define TPM_CnSC_MSB_SHIFT                       (5U)
/*! MSB - Channel Mode Select B */
#define TPM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_MSB_SHIFT)) & TPM_CnSC_MSB_MASK)

#define TPM_CnSC_CHIE_MASK                       (0x40U)
#define TPM_CnSC_CHIE_SHIFT                      (6U)
/*! CHIE - Channel Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TPM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_CHIE_SHIFT)) & TPM_CnSC_CHIE_MASK)

#define TPM_CnSC_CHF_MASK                        (0x80U)
#define TPM_CnSC_CHF_SHIFT                       (7U)
/*! CHF - Channel Flag
 *  0b0..Event not occurred
 *  0b1..Event occurred
 */
#define TPM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_CHF_SHIFT)) & TPM_CnSC_CHF_MASK)
/*! @} */

/* The count of TPM_CnSC */
#define TPM_CnSC_COUNT                           (4U)

/*! @name CnV - Channel n Value */
/*! @{ */

#define TPM_CnV_VAL_MASK                         (0xFFFFFFFFU)
#define TPM_CnV_VAL_SHIFT                        (0U)
/*! VAL - Channel Value */
#define TPM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_CnV_VAL_SHIFT)) & TPM_CnV_VAL_MASK)
/*! @} */

/* The count of TPM_CnV */
#define TPM_CnV_COUNT                            (4U)

/*! @name COMBINE - Combine Channel */
/*! @{ */

#define TPM_COMBINE_COMBINE0_MASK                (0x1U)
#define TPM_COMBINE_COMBINE0_SHIFT               (0U)
/*! COMBINE0 - Combine Channels 0 and 1
 *  0b0..Independent
 *  0b1..Combined
 */
#define TPM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMBINE0_SHIFT)) & TPM_COMBINE_COMBINE0_MASK)

#define TPM_COMBINE_COMSWAP0_MASK                (0x2U)
#define TPM_COMBINE_COMSWAP0_SHIFT               (1U)
/*! COMSWAP0 - Combine Channel 0 and 1 Swap
 *  0b0..Even channel
 *  0b1..Odd channel
 */
#define TPM_COMBINE_COMSWAP0(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMSWAP0_SHIFT)) & TPM_COMBINE_COMSWAP0_MASK)

#define TPM_COMBINE_COMBINE1_MASK                (0x100U)
#define TPM_COMBINE_COMBINE1_SHIFT               (8U)
/*! COMBINE1 - Combine Channels 2 and 3
 *  0b0..Independent
 *  0b1..Combined
 */
#define TPM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMBINE1_SHIFT)) & TPM_COMBINE_COMBINE1_MASK)

#define TPM_COMBINE_COMSWAP1_MASK                (0x200U)
#define TPM_COMBINE_COMSWAP1_SHIFT               (9U)
/*! COMSWAP1 - Combine Channels 2 and 3 Swap
 *  0b0..Even channel
 *  0b1..Odd channel
 */
#define TPM_COMBINE_COMSWAP1(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMSWAP1_SHIFT)) & TPM_COMBINE_COMSWAP1_MASK)
/*! @} */

/*! @name TRIG - Channel Trigger */
/*! @{ */

#define TPM_TRIG_TRIG0_MASK                      (0x1U)
#define TPM_TRIG_TRIG0_SHIFT                     (0U)
/*! TRIG0 - Channel 0 Trigger
 *  0b0..No effect
 *  0b1..Configures trigger input 0 to be used by channel 0
 */
#define TPM_TRIG_TRIG0(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG0_SHIFT)) & TPM_TRIG_TRIG0_MASK)

#define TPM_TRIG_TRIG1_MASK                      (0x2U)
#define TPM_TRIG_TRIG1_SHIFT                     (1U)
/*! TRIG1 - Channel 1 Trigger
 *  0b0..No effect
 *  0b1..Configures trigger input 1 to be used by channel 1
 */
#define TPM_TRIG_TRIG1(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG1_SHIFT)) & TPM_TRIG_TRIG1_MASK)

#define TPM_TRIG_TRIG2_MASK                      (0x4U)
#define TPM_TRIG_TRIG2_SHIFT                     (2U)
/*! TRIG2 - Channel 2 Trigger
 *  0b0..No effect
 *  0b1..Configures trigger input 0 to be used by channel 2
 */
#define TPM_TRIG_TRIG2(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG2_SHIFT)) & TPM_TRIG_TRIG2_MASK)

#define TPM_TRIG_TRIG3_MASK                      (0x8U)
#define TPM_TRIG_TRIG3_SHIFT                     (3U)
/*! TRIG3 - Channel 3 Trigger
 *  0b0..No effect
 *  0b1..Configures trigger input 1 to be used by channel 3
 */
#define TPM_TRIG_TRIG3(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG3_SHIFT)) & TPM_TRIG_TRIG3_MASK)
/*! @} */

/*! @name POL - Channel Polarity */
/*! @{ */

#define TPM_POL_POL0_MASK                        (0x1U)
#define TPM_POL_POL0_SHIFT                       (0U)
/*! POL0 - Channel 0 Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define TPM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL0_SHIFT)) & TPM_POL_POL0_MASK)

#define TPM_POL_POL1_MASK                        (0x2U)
#define TPM_POL_POL1_SHIFT                       (1U)
/*! POL1 - Channel 1 Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define TPM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL1_SHIFT)) & TPM_POL_POL1_MASK)

#define TPM_POL_POL2_MASK                        (0x4U)
#define TPM_POL_POL2_SHIFT                       (2U)
/*! POL2 - Channel 2 Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define TPM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL2_SHIFT)) & TPM_POL_POL2_MASK)

#define TPM_POL_POL3_MASK                        (0x8U)
#define TPM_POL_POL3_SHIFT                       (3U)
/*! POL3 - Channel 3 Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define TPM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL3_SHIFT)) & TPM_POL_POL3_MASK)
/*! @} */

/*! @name FILTER - Filter Control */
/*! @{ */

#define TPM_FILTER_CH0FVAL_MASK                  (0xFU)
#define TPM_FILTER_CH0FVAL_SHIFT                 (0U)
/*! CH0FVAL - Channel 0 Filter Value */
#define TPM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH0FVAL_SHIFT)) & TPM_FILTER_CH0FVAL_MASK)

#define TPM_FILTER_CH1FVAL_MASK                  (0xF0U)
#define TPM_FILTER_CH1FVAL_SHIFT                 (4U)
/*! CH1FVAL - Channel 1 Filter Value */
#define TPM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH1FVAL_SHIFT)) & TPM_FILTER_CH1FVAL_MASK)

#define TPM_FILTER_CH2FVAL_MASK                  (0xF00U)
#define TPM_FILTER_CH2FVAL_SHIFT                 (8U)
/*! CH2FVAL - Channel 2 Filter Value */
#define TPM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH2FVAL_SHIFT)) & TPM_FILTER_CH2FVAL_MASK)

#define TPM_FILTER_CH3FVAL_MASK                  (0xF000U)
#define TPM_FILTER_CH3FVAL_SHIFT                 (12U)
/*! CH3FVAL - Channel 3 Filter Value */
#define TPM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH3FVAL_SHIFT)) & TPM_FILTER_CH3FVAL_MASK)
/*! @} */

/*! @name QDCTRL - Quadrature Decoder Control and Status */
/*! @{ */

#define TPM_QDCTRL_QUADEN_MASK                   (0x1U)
#define TPM_QDCTRL_QUADEN_SHIFT                  (0U)
/*! QUADEN - Quadrature Decoder Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TPM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_QUADEN_SHIFT)) & TPM_QDCTRL_QUADEN_MASK)

#define TPM_QDCTRL_TOFDIR_MASK                   (0x2U)
#define TPM_QDCTRL_TOFDIR_SHIFT                  (1U)
/*! TOFDIR - Timer Overflow Direction
 *  0b0..Bottom of counting
 *  0b1..Top of counting
 */
#define TPM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_TOFDIR_SHIFT)) & TPM_QDCTRL_TOFDIR_MASK)

#define TPM_QDCTRL_QUADIR_MASK                   (0x4U)
#define TPM_QDCTRL_QUADIR_SHIFT                  (2U)
/*! QUADIR - Counter Direction in Quadrature Decode Mode
 *  0b0..Decreasing (counter decrement)
 *  0b1..Increasing (counter increment)
 */
#define TPM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_QUADIR_SHIFT)) & TPM_QDCTRL_QUADIR_MASK)

#define TPM_QDCTRL_QUADMODE_MASK                 (0x8U)
#define TPM_QDCTRL_QUADMODE_SHIFT                (3U)
/*! QUADMODE - Quadrature Decoder Mode
 *  0b0..Phase encoding mode
 *  0b1..Count and direction encoding mode
 */
#define TPM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_QUADMODE_SHIFT)) & TPM_QDCTRL_QUADMODE_MASK)
/*! @} */

/*! @name CONF - Configuration */
/*! @{ */

#define TPM_CONF_DOZEEN_MASK                     (0x20U)
#define TPM_CONF_DOZEEN_SHIFT                    (5U)
/*! DOZEEN - Doze Enable
 *  0b0..TPM counter continues
 *  0b1..TPM counter pauses
 */
#define TPM_CONF_DOZEEN(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_DOZEEN_SHIFT)) & TPM_CONF_DOZEEN_MASK)

#define TPM_CONF_DBGMODE_MASK                    (0xC0U)
#define TPM_CONF_DBGMODE_SHIFT                   (6U)
/*! DBGMODE - Debug Mode
 *  0b00..TPM counter pauses
 *  0b11..TPM counter continues
 */
#define TPM_CONF_DBGMODE(x)                      (((uint32_t)(((uint32_t)(x)) << TPM_CONF_DBGMODE_SHIFT)) & TPM_CONF_DBGMODE_MASK)

#define TPM_CONF_GTBSYNC_MASK                    (0x100U)
#define TPM_CONF_GTBSYNC_SHIFT                   (8U)
/*! GTBSYNC - GTB Synchronization
 *  0b0..Disable
 *  0b1..Enable
 */
#define TPM_CONF_GTBSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << TPM_CONF_GTBSYNC_SHIFT)) & TPM_CONF_GTBSYNC_MASK)

#define TPM_CONF_GTBEEN_MASK                     (0x200U)
#define TPM_CONF_GTBEEN_SHIFT                    (9U)
/*! GTBEEN - GTB Enable
 *  0b0..Internally generated TPM counter
 *  0b1..Externally generated GTB counter
 */
#define TPM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_GTBEEN_SHIFT)) & TPM_CONF_GTBEEN_MASK)

#define TPM_CONF_CSOT_MASK                       (0x10000U)
#define TPM_CONF_CSOT_SHIFT                      (16U)
/*! CSOT - Counter Start on Trigger
 *  0b0..Counter starts immediately
 *  0b1..Counter starts after detection of a rising edge on the selected input trigger
 */
#define TPM_CONF_CSOT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CSOT_SHIFT)) & TPM_CONF_CSOT_MASK)

#define TPM_CONF_CSOO_MASK                       (0x20000U)
#define TPM_CONF_CSOO_SHIFT                      (17U)
/*! CSOO - Counter Stop on Overflow
 *  0b0..TPM counter continues
 *  0b1..TPM counter stops
 */
#define TPM_CONF_CSOO(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CSOO_SHIFT)) & TPM_CONF_CSOO_MASK)

#define TPM_CONF_CROT_MASK                       (0x40000U)
#define TPM_CONF_CROT_SHIFT                      (18U)
/*! CROT - Counter Reload on Trigger
 *  0b0..No reload
 *  0b1..Reload
 */
#define TPM_CONF_CROT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CROT_SHIFT)) & TPM_CONF_CROT_MASK)

#define TPM_CONF_CPOT_MASK                       (0x80000U)
#define TPM_CONF_CPOT_SHIFT                      (19U)
/*! CPOT - Counter Pause on Trigger
 *  0b0..TPM counter continues
 *  0b1..TPM counter pauses
 */
#define TPM_CONF_CPOT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CPOT_SHIFT)) & TPM_CONF_CPOT_MASK)

#define TPM_CONF_TRGPOL_MASK                     (0x400000U)
#define TPM_CONF_TRGPOL_SHIFT                    (22U)
/*! TRGPOL - Trigger Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define TPM_CONF_TRGPOL(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_TRGPOL_SHIFT)) & TPM_CONF_TRGPOL_MASK)

#define TPM_CONF_TRGSRC_MASK                     (0x800000U)
#define TPM_CONF_TRGSRC_SHIFT                    (23U)
/*! TRGSRC - Trigger Source
 *  0b0..External
 *  0b1..Internal (channel pin input capture)
 */
#define TPM_CONF_TRGSRC(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_TRGSRC_SHIFT)) & TPM_CONF_TRGSRC_MASK)

#define TPM_CONF_TRGSEL_MASK                     (0x3000000U)
#define TPM_CONF_TRGSEL_SHIFT                    (24U)
/*! TRGSEL - Trigger Select
 *  0b01..Channel 0 pin input capture
 *  0b10..Channel 1 pin input capture
 *  0b11..Channel 0 or channel 1 pin input capture
 */
#define TPM_CONF_TRGSEL(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_TRGSEL_SHIFT)) & TPM_CONF_TRGSEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TPM_Register_Masks */


/*!
 * @}
 */ /* end of group TPM_Peripheral_Access_Layer */


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


#endif  /* PERI_TPM_H_ */
