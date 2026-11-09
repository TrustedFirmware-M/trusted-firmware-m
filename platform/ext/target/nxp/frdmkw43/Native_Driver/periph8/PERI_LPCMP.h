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
**         CMSIS Peripheral Access Layer for LPCMP
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
 * @file PERI_LPCMP.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for LPCMP
 *
 * CMSIS Peripheral Access Layer for LPCMP
 */

#if !defined(PERI_LPCMP_H_)
#define PERI_LPCMP_H_                            /**< Symbol preventing repeated inclusion */

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
   -- LPCMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPCMP_Peripheral_Access_Layer LPCMP Peripheral Access Layer
 * @{
 */

/** LPCMP - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t CCR0;                              /**< Comparator Control Register 0, offset: 0x8 */
  __IO uint32_t CCR1;                              /**< Comparator Control Register 1, offset: 0xC */
  __IO uint32_t CCR2;                              /**< Comparator Control Register 2, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DCR;                               /**< DAC Control, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t CSR;                               /**< Comparator Status, offset: 0x20 */
} LPCMP_Type;

/* ----------------------------------------------------------------------------
   -- LPCMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPCMP_Register_Masks LPCMP Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define LPCMP_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPCMP_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000001..Round robin feature
 */
#define LPCMP_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_FEATURE_SHIFT)) & LPCMP_VERID_FEATURE_MASK)

#define LPCMP_VERID_MINOR_MASK                   (0xFF0000U)
#define LPCMP_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define LPCMP_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MINOR_SHIFT)) & LPCMP_VERID_MINOR_MASK)

#define LPCMP_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPCMP_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define LPCMP_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MAJOR_SHIFT)) & LPCMP_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPCMP_PARAM_DAC_RES_MASK                 (0xFU)
#define LPCMP_PARAM_DAC_RES_SHIFT                (0U)
/*! DAC_RES - DAC Resolution
 *  0b0000..4-bit DAC
 *  0b0001..6-bit DAC
 *  0b0010..8-bit DAC
 *  0b0011..10-bit DAC
 *  0b0100..12-bit DAC
 *  0b0101..14-bit DAC
 *  0b0110..16-bit DAC
 */
#define LPCMP_PARAM_DAC_RES(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_PARAM_DAC_RES_SHIFT)) & LPCMP_PARAM_DAC_RES_MASK)
/*! @} */

/*! @name CCR0 - Comparator Control Register 0 */
/*! @{ */

#define LPCMP_CCR0_CMP_EN_MASK                   (0x1U)
#define LPCMP_CCR0_CMP_EN_SHIFT                  (0U)
/*! CMP_EN - Comparator Enable
 *  0b0..Disable (The analog logic remains off and consumes no power.)
 *  0b1..Enable
 */
#define LPCMP_CCR0_CMP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_EN_SHIFT)) & LPCMP_CCR0_CMP_EN_MASK)

#define LPCMP_CCR0_CMP_STOP_EN_MASK              (0x2U)
#define LPCMP_CCR0_CMP_STOP_EN_SHIFT             (1U)
/*! CMP_STOP_EN - Comparator Sleep Mode Enable
 *  0b0..Disables the analog comparator regardless of CMP_EN.
 *  0b1..Allows CMP_EN to enable the analog comparator.
 */
#define LPCMP_CCR0_CMP_STOP_EN(x)                (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_STOP_EN_SHIFT)) & LPCMP_CCR0_CMP_STOP_EN_MASK)
/*! @} */

/*! @name CCR1 - Comparator Control Register 1 */
/*! @{ */

#define LPCMP_CCR1_WINDOW_EN_MASK                (0x1U)
#define LPCMP_CCR1_WINDOW_EN_SHIFT               (0U)
/*! WINDOW_EN - Windowing Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPCMP_CCR1_WINDOW_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_WINDOW_EN_SHIFT)) & LPCMP_CCR1_WINDOW_EN_MASK)

#define LPCMP_CCR1_SAMPLE_EN_MASK                (0x2U)
#define LPCMP_CCR1_SAMPLE_EN_SHIFT               (1U)
/*! SAMPLE_EN - Sampling Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPCMP_CCR1_SAMPLE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_SAMPLE_EN_SHIFT)) & LPCMP_CCR1_SAMPLE_EN_MASK)

#define LPCMP_CCR1_DMA_EN_MASK                   (0x4U)
#define LPCMP_CCR1_DMA_EN_SHIFT                  (2U)
/*! DMA_EN - DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPCMP_CCR1_DMA_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_DMA_EN_SHIFT)) & LPCMP_CCR1_DMA_EN_MASK)

#define LPCMP_CCR1_COUT_INV_MASK                 (0x8U)
#define LPCMP_CCR1_COUT_INV_SHIFT                (3U)
/*! COUT_INV - Comparator Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define LPCMP_CCR1_COUT_INV(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_INV_SHIFT)) & LPCMP_CCR1_COUT_INV_MASK)

#define LPCMP_CCR1_COUT_SEL_MASK                 (0x10U)
#define LPCMP_CCR1_COUT_SEL_SHIFT                (4U)
/*! COUT_SEL - Comparator Output Select
 *  0b0..Use COUT (filtered)
 *  0b1..Use COUTA (unfiltered)
 */
#define LPCMP_CCR1_COUT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_SEL_SHIFT)) & LPCMP_CCR1_COUT_SEL_MASK)

#define LPCMP_CCR1_COUT_PEN_MASK                 (0x20U)
#define LPCMP_CCR1_COUT_PEN_SHIFT                (5U)
/*! COUT_PEN - Comparator Output Pin Enable
 *  0b0..Not available
 *  0b1..Available
 */
#define LPCMP_CCR1_COUT_PEN(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_PEN_SHIFT)) & LPCMP_CCR1_COUT_PEN_MASK)

#define LPCMP_CCR1_COUTA_OWEN_MASK               (0x40U)
#define LPCMP_CCR1_COUTA_OWEN_SHIFT              (6U)
/*! COUTA_OWEN - COUTA_OW Enable
 *  0b0..COUTA holds the last sampled value.
 *  0b1..Enables the COUTA signal value to be defined by COUTA_OW.
 */
#define LPCMP_CCR1_COUTA_OWEN(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUTA_OWEN_SHIFT)) & LPCMP_CCR1_COUTA_OWEN_MASK)

#define LPCMP_CCR1_COUTA_OW_MASK                 (0x80U)
#define LPCMP_CCR1_COUTA_OW_SHIFT                (7U)
/*! COUTA_OW - COUTA Output Level for Closed Window
 *  0b0..COUTA is 0
 *  0b1..COUTA is 1
 */
#define LPCMP_CCR1_COUTA_OW(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUTA_OW_SHIFT)) & LPCMP_CCR1_COUTA_OW_MASK)

#define LPCMP_CCR1_WINDOW_INV_MASK               (0x100U)
#define LPCMP_CCR1_WINDOW_INV_SHIFT              (8U)
/*! WINDOW_INV - WINDOW/SAMPLE Signal Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define LPCMP_CCR1_WINDOW_INV(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_WINDOW_INV_SHIFT)) & LPCMP_CCR1_WINDOW_INV_MASK)

#define LPCMP_CCR1_WINDOW_CLS_MASK               (0x200U)
#define LPCMP_CCR1_WINDOW_CLS_SHIFT              (9U)
/*! WINDOW_CLS - CMPO Event Window Close
 *  0b0..CMPO event cannot close the window
 *  0b1..CMPO event can close the window
 */
#define LPCMP_CCR1_WINDOW_CLS(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_WINDOW_CLS_SHIFT)) & LPCMP_CCR1_WINDOW_CLS_MASK)

#define LPCMP_CCR1_EVT_SEL_MASK                  (0xC00U)
#define LPCMP_CCR1_EVT_SEL_SHIFT                 (10U)
/*! EVT_SEL - CMPO Event Select
 *  0b00..Rising edge
 *  0b01..Falling edge
 *  0b1x..Both edges
 */
#define LPCMP_CCR1_EVT_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_EVT_SEL_SHIFT)) & LPCMP_CCR1_EVT_SEL_MASK)

#define LPCMP_CCR1_FILT_CNT_MASK                 (0x70000U)
#define LPCMP_CCR1_FILT_CNT_SHIFT                (16U)
/*! FILT_CNT - Filter Sample Count
 *  0b000..Filter is bypassed: COUT = COUTA
 *  0b001..1 consecutive sample (Comparator output is simply sampled.)
 *  0b010..2 consecutive samples
 *  0b011..3 consecutive samples
 *  0b100..4 consecutive samples
 *  0b101..5 consecutive samples
 *  0b110..6 consecutive samples
 *  0b111..7 consecutive samples
 */
#define LPCMP_CCR1_FILT_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_FILT_CNT_SHIFT)) & LPCMP_CCR1_FILT_CNT_MASK)

#define LPCMP_CCR1_FILT_PER_MASK                 (0xFF000000U)
#define LPCMP_CCR1_FILT_PER_SHIFT                (24U)
/*! FILT_PER - Filter Sample Period */
#define LPCMP_CCR1_FILT_PER(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_FILT_PER_SHIFT)) & LPCMP_CCR1_FILT_PER_MASK)
/*! @} */

/*! @name CCR2 - Comparator Control Register 2 */
/*! @{ */

#define LPCMP_CCR2_CMP_HPMD_MASK                 (0x1U)
#define LPCMP_CCR2_CMP_HPMD_SHIFT                (0U)
/*! CMP_HPMD - CMP High Power Mode Select
 *  0b0..Low power (speed) comparison mode
 *  0b1..High power (speed) comparison mode
 */
#define LPCMP_CCR2_CMP_HPMD(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_CMP_HPMD_SHIFT)) & LPCMP_CCR2_CMP_HPMD_MASK)

#define LPCMP_CCR2_CMP_NPMD_MASK                 (0x2U)
#define LPCMP_CCR2_CMP_NPMD_SHIFT                (1U)
/*! CMP_NPMD - CMP Nano Power Mode Select
 *  0b0..Disables CMP Nano power mode. CCR2[CMP_HPMD] determines the mode for the comparator.
 *  0b1..Enables CMP Nano power mode.
 */
#define LPCMP_CCR2_CMP_NPMD(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_CMP_NPMD_SHIFT)) & LPCMP_CCR2_CMP_NPMD_MASK)

#define LPCMP_CCR2_HYSTCTR_MASK                  (0x30U)
#define LPCMP_CCR2_HYSTCTR_SHIFT                 (4U)
/*! HYSTCTR - Comparator Hysteresis Control
 *  0b00..Level 0: Analog comparator hysteresis 0 mV.
 *  0b01..Level 1: Analog comparator hysteresis 10 mV.
 *  0b10..Level 2: Analog comparator hysteresis 20 mV.
 *  0b11..Level 3: Analog comparator hysteresis 30 mV.
 */
#define LPCMP_CCR2_HYSTCTR(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_HYSTCTR_SHIFT)) & LPCMP_CCR2_HYSTCTR_MASK)

#define LPCMP_CCR2_PSEL_MASK                     (0x70000U)
#define LPCMP_CCR2_PSEL_SHIFT                    (16U)
/*! PSEL - Plus Input MUX Select
 *  0b000..Input 0p
 *  0b001..Input 1p
 *  0b010..Input 2p
 *  0b011..Input 3p
 *  0b100..Input 4p
 *  0b101..Input 5p
 *  0b110..Reserved
 *  0b111..Internal DAC output
 */
#define LPCMP_CCR2_PSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_PSEL_SHIFT)) & LPCMP_CCR2_PSEL_MASK)

#define LPCMP_CCR2_MSEL_MASK                     (0x700000U)
#define LPCMP_CCR2_MSEL_SHIFT                    (20U)
/*! MSEL - Minus Input MUX Select
 *  0b000..Input 0m
 *  0b001..Input 1m
 *  0b010..Input 2m
 *  0b011..Input 3m
 *  0b100..Input 4m
 *  0b101..Input 5m
 *  0b110..Reserved
 *  0b111..Internal DAC output
 */
#define LPCMP_CCR2_MSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_MSEL_SHIFT)) & LPCMP_CCR2_MSEL_MASK)
/*! @} */

/*! @name DCR - DAC Control */
/*! @{ */

#define LPCMP_DCR_DAC_EN_MASK                    (0x1U)
#define LPCMP_DCR_DAC_EN_SHIFT                   (0U)
/*! DAC_EN - DAC Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPCMP_DCR_DAC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_EN_SHIFT)) & LPCMP_DCR_DAC_EN_MASK)

#define LPCMP_DCR_DAC_HPMD_MASK                  (0x2U)
#define LPCMP_DCR_DAC_HPMD_SHIFT                 (1U)
/*! DAC_HPMD - DAC High Power Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPCMP_DCR_DAC_HPMD(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_HPMD_SHIFT)) & LPCMP_DCR_DAC_HPMD_MASK)

#define LPCMP_DCR_VRSEL_MASK                     (0x100U)
#define LPCMP_DCR_VRSEL_SHIFT                    (8U)
/*! VRSEL - DAC Reference High Voltage Source Select
 *  0b0..VREFH0
 *  0b1..VREFH1
 */
#define LPCMP_DCR_VRSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_VRSEL_SHIFT)) & LPCMP_DCR_VRSEL_MASK)

#define LPCMP_DCR_DAC_DATA_MASK                  (0xFF0000U)
#define LPCMP_DCR_DAC_DATA_SHIFT                 (16U)
/*! DAC_DATA - DAC Output Voltage Select */
#define LPCMP_DCR_DAC_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_DATA_SHIFT)) & LPCMP_DCR_DAC_DATA_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define LPCMP_IER_CFR_IE_MASK                    (0x1U)
#define LPCMP_IER_CFR_IE_SHIFT                   (0U)
/*! CFR_IE - Comparator Flag Rising Interrupt Enable
 *  0b0..Disables the comparator flag rising interrupt.
 *  0b1..Enables the comparator flag rising interrupt when CFR is set.
 */
#define LPCMP_IER_CFR_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFR_IE_SHIFT)) & LPCMP_IER_CFR_IE_MASK)

#define LPCMP_IER_CFF_IE_MASK                    (0x2U)
#define LPCMP_IER_CFF_IE_SHIFT                   (1U)
/*! CFF_IE - Comparator Flag Falling Interrupt Enable
 *  0b0..Disables the comparator flag falling interrupt.
 *  0b1..Enables the comparator flag falling interrupt when CFF is set.
 */
#define LPCMP_IER_CFF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFF_IE_SHIFT)) & LPCMP_IER_CFF_IE_MASK)
/*! @} */

/*! @name CSR - Comparator Status */
/*! @{ */

#define LPCMP_CSR_CFR_MASK                       (0x1U)
#define LPCMP_CSR_CFR_SHIFT                      (0U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..Not detected
 *  0b1..Detected
 */
#define LPCMP_CSR_CFR(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFR_SHIFT)) & LPCMP_CSR_CFR_MASK)

#define LPCMP_CSR_CFF_MASK                       (0x2U)
#define LPCMP_CSR_CFF_SHIFT                      (1U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..Not detected
 *  0b1..Detected
 */
#define LPCMP_CSR_CFF(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFF_SHIFT)) & LPCMP_CSR_CFF_MASK)

#define LPCMP_CSR_COUT_MASK                      (0x100U)
#define LPCMP_CSR_COUT_SHIFT                     (8U)
/*! COUT - Analog Comparator Output */
#define LPCMP_CSR_COUT(x)                        (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_COUT_SHIFT)) & LPCMP_CSR_COUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPCMP_Register_Masks */


/*!
 * @}
 */ /* end of group LPCMP_Peripheral_Access_Layer */


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


#endif  /* PERI_LPCMP_H_ */

