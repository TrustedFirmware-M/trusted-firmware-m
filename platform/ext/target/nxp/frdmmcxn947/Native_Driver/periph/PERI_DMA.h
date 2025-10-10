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
**         CMSIS Peripheral Access Layer for DMA
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
 * @file PERI_DMA.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

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
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(DMA_REQUEST_SOURCE_T_)
#define DMA_REQUEST_SOURCE_T_
/*!
 * @addtogroup dma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma_request_source
{
    kDma0RequestMuxFlexSpi0Rx       = 1U,          /**< FlexSPI0 Receive event */
    kDma1RequestMuxFlexSpi0Rx       = 1U,          /**< FlexSPI0 Receive event */
    kDma0RequestMuxFlexSpi0Tx       = 2U,          /**< FlexSPI0 Transmit event */
    kDma1RequestMuxFlexSpi0Tx       = 2U,          /**< FlexSPI0 Transmit event */
    kDma0RequestMuxPinInt0          = 3U,          /**< PINT0 INT0 */
    kDma1RequestMuxPinInt0          = 3U,          /**< PINT0 INT0 */
    kDma0RequestMuxPinInt1          = 4U,          /**< PINT0 INT1 */
    kDma1RequestMuxPinInt1          = 4U,          /**< PINT0 INT1 */
    kDma0RequestMuxPinInt2          = 5U,          /**< PINT0 INT2 */
    kDma1RequestMuxPinInt2          = 5U,          /**< PINT0 INT2 */
    kDma0RequestMuxPinInt3          = 6U,          /**< PINT0 INT3 */
    kDma1RequestMuxPinInt3          = 6U,          /**< PINT0 INT3 */
    kDma0RequestMuxCtimer0M0        = 7U,          /**< CTIMER0 Match channel 0 request */
    kDma1RequestMuxCtimer0M0        = 7U,          /**< CTIMER0 Match channel 0 request */
    kDma0RequestMuxCtimer0M1        = 8U,          /**< CTIMER0 Match channel 1 request */
    kDma1RequestMuxCtimer0M1        = 8U,          /**< CTIMER0 Match channel 1 request */
    kDma0RequestMuxCtimer1M0        = 9U,          /**< CTIMER1 Match channel 0 request */
    kDma1RequestMuxCtimer1M0        = 9U,          /**< CTIMER1 Match channel 0 request */
    kDma0RequestMuxCtimer1M1        = 10U,         /**< CTIMER1 Match channel 1 request */
    kDma1RequestMuxCtimer1M1        = 10U,         /**< CTIMER1 Match channel 1 request */
    kDma0RequestMuxCtimer2M0        = 11U,         /**< CTIMER2 Match channel 0 request */
    kDma1RequestMuxCtimer2M0        = 11U,         /**< CTIMER2 Match channel 0 request */
    kDma0RequestMuxCtimer2M1        = 12U,         /**< CTIMER2 Match channel 1 request */
    kDma1RequestMuxCtimer2M1        = 12U,         /**< CTIMER2 Match channel 1 request */
    kDma0RequestMuxCtimer3M0        = 13U,         /**< CTIMER3 Match channel 0 request */
    kDma1RequestMuxCtimer3M0        = 13U,         /**< CTIMER3 Match channel 0 request */
    kDma0RequestMuxCtimer3M1        = 14U,         /**< CTIMER3 Match channel 1 request */
    kDma1RequestMuxCtimer3M1        = 14U,         /**< CTIMER3 Match channel 1 request */
    kDma0RequestMuxCtimer4M0        = 15U,         /**< CTIMER4 Match channel 0 request */
    kDma1RequestMuxCtimer4M0        = 15U,         /**< CTIMER4 Match channel 0 request */
    kDma0RequestMuxCtimer4M1        = 16U,         /**< CTIMER4 Match channel 1 request */
    kDma1RequestMuxCtimer4M1        = 16U,         /**< CTIMER4 Match channel 1 request */
    kDma0RequestMuxWuu0             = 17U,         /**< WUU0 Wake up event */
    kDma1RequestMuxWuu0             = 17U,         /**< WUU0 Wake up event */
    kDma0RequestMuxMicfil0FifoRequest = 18U,       /**< MICFIL0 FIFO_request */
    kDma1RequestMuxMicfil0FifoRequest = 18U,       /**< MICFIL0 FIFO_request */
    kDma0RequestMuxSct0Dma0         = 19U,         /**< SCT0 DMA0 */
    kDma1RequestMuxSct0Dma0         = 19U,         /**< SCT0 DMA0 */
    kDma0RequestMuxSct0Dma1         = 20U,         /**< SCT0 DMA1 */
    kDma1RequestMuxSct0Dma1         = 20U,         /**< SCT0 DMA1 */
    kDma0RequestMuxAdc0FifoARequest = 21U,         /**< ADC0 FIFO A request */
    kDma1RequestMuxAdc0FifoARequest = 21U,         /**< ADC0 FIFO A request */
    kDma0RequestMuxAdc0FifoBRequest = 22U,         /**< ADC0 FIFO B request */
    kDma1RequestMuxAdc0FifoBRequest = 22U,         /**< ADC0 FIFO B request */
    kDma0RequestMuxAdc1FifoARequest = 23U,         /**< ADC1 FIFO A request */
    kDma1RequestMuxAdc1FifoARequest = 23U,         /**< ADC1 FIFO A request */
    kDma0RequestMuxAdc1FifoBRequest = 24U,         /**< ADC1 FIFO B request */
    kDma1RequestMuxAdc1FifoBRequest = 24U,         /**< ADC1 FIFO B request */
    kDma0RequestMuxDac0FifoRequest  = 25U,         /**< DAC0 FIFO_request */
    kDma1RequestMuxDac0FifoRequest  = 25U,         /**< DAC0 FIFO_request */
    kDma0RequestMuxDac1FifoRequest  = 26U,         /**< DAC1 FIFO_request */
    kDma1RequestMuxDac1FifoRequest  = 26U,         /**< DAC1 FIFO_request */
    kDma0RequestMuxDac2FifoRequest  = 27U,         /**< DAC2 FIFO_request */
    kDma1RequestMuxDac2FifoRequest  = 27U,         /**< DAC2 FIFO_request */
    kDma0RequestMuxHsCmp0DmaRequest = 28U,         /**< CMP0 DMA_request */
    kDma1RequestMuxHsCmp0DmaRequest = 28U,         /**< CMP0 DMA_request */
    kDma0RequestMuxHsCmp1DmaRequest = 29U,         /**< CMP1 DMA_request */
    kDma1RequestMuxHsCmp1DmaRequest = 29U,         /**< CMP1 DMA_request */
    kDma0RequestMuxEvtg0Out0A       = 31U,         /**< EVTG0 OUT0A */
    kDma1RequestMuxEvtg0Out0A       = 31U,         /**< EVTG0 OUT0A */
    kDma0RequestMuxEvtg0Out0B       = 32U,         /**< EVTG0 OUT0B */
    kDma1RequestMuxEvtg0Out0B       = 32U,         /**< EVTG0 OUT0B */
    kDma0RequestMuxEvtg0Out1A       = 33U,         /**< EVTG0 OUT1A */
    kDma1RequestMuxEvtg0Out1A       = 33U,         /**< EVTG0 OUT1A */
    kDma0RequestMuxEvtg0Out1B       = 34U,         /**< EVTG0 OUT1B */
    kDma1RequestMuxEvtg0Out1B       = 34U,         /**< EVTG0 OUT1B */
    kDma0RequestMuxEvtg0Out2A       = 35U,         /**< EVTG0 OUT2A */
    kDma1RequestMuxEvtg0Out2A       = 35U,         /**< EVTG0 OUT2A */
    kDma0RequestMuxEvtg0Out2B       = 36U,         /**< EVTG0 OUT2B */
    kDma1RequestMuxEvtg0Out2B       = 36U,         /**< EVTG0 OUT2B */
    kDma0RequestMuxEvtg0Out3A       = 37U,         /**< EVTG0 OUT3A */
    kDma1RequestMuxEvtg0Out3A       = 37U,         /**< EVTG0 OUT3A */
    kDma0RequestMuxEvtg0Out3B       = 38U,         /**< EVTG0 OUT3B */
    kDma1RequestMuxEvtg0Out3B       = 38U,         /**< EVTG0 OUT3B */
    kDma0RequestMuxFlexPwm0ReqCapt0 = 39U,         /**< PWM0 capture0 request */
    kDma1RequestMuxFlexPwm0ReqCapt0 = 39U,         /**< PWM0 capture0 request */
    kDma0RequestMuxFlexPwm0ReqCapt1 = 40U,         /**< PWM0 capture1 request */
    kDma1RequestMuxFlexPwm0ReqCapt1 = 40U,         /**< PWM0 capture1 request */
    kDma0RequestMuxFlexPwm0ReqCapt2 = 41U,         /**< PWM0 capture2 request */
    kDma1RequestMuxFlexPwm0ReqCapt2 = 41U,         /**< PWM0 capture2 request */
    kDma0RequestMuxFlexPwm0ReqCapt3 = 42U,         /**< PWM0 capture3 request */
    kDma1RequestMuxFlexPwm0ReqCapt3 = 42U,         /**< PWM0 capture3 request */
    kDma0RequestMuxFlexPwm0ReqVal0  = 43U,         /**< PWM0 value0 request */
    kDma1RequestMuxFlexPwm0ReqVal0  = 43U,         /**< PWM0 value0 request */
    kDma0RequestMuxFlexPwm0ReqVal1  = 44U,         /**< PWM0 value1 request */
    kDma1RequestMuxFlexPwm0ReqVal1  = 44U,         /**< PWM0 value1 request */
    kDma0RequestMuxFlexPwm0ReqVal2  = 45U,         /**< PWM0 value2 request */
    kDma1RequestMuxFlexPwm0ReqVal2  = 45U,         /**< PWM0 value2 request */
    kDma0RequestMuxFlexPwm0ReqVal3  = 46U,         /**< PWM0 value3 request */
    kDma1RequestMuxFlexPwm0ReqVal3  = 46U,         /**< PWM0 value3 request */
    kDma0RequestMuxFlexPwm1ReqCapt0 = 47U,         /**< PWM1 capture0 request */
    kDma1RequestMuxFlexPwm1ReqCapt0 = 47U,         /**< PWM1 capture0 request */
    kDma0RequestMuxFlexPwm1ReqCapt1 = 48U,         /**< PWM1 capture1 request */
    kDma1RequestMuxFlexPwm1ReqCapt1 = 48U,         /**< PWM1 capture1 request */
    kDma0RequestMuxFlexPwm1ReqCapt2 = 49U,         /**< PWM1 capture2 request */
    kDma1RequestMuxFlexPwm1ReqCapt2 = 49U,         /**< PWM1 capture2 request */
    kDma0RequestMuxFlexPwm1ReqCapt3 = 50U,         /**< PWM1 capture3 request */
    kDma1RequestMuxFlexPwm1ReqCapt3 = 50U,         /**< PWM1 capture3 request */
    kDma0RequestMuxFlexPwm1ReqVal0  = 51U,         /**< PWM1 value0 request */
    kDma1RequestMuxFlexPwm1ReqVal0  = 51U,         /**< PWM1 value0 request */
    kDma0RequestMuxFlexPwm1ReqVal1  = 52U,         /**< PWM1 value1 request */
    kDma1RequestMuxFlexPwm1ReqVal1  = 52U,         /**< PWM1 value1 request */
    kDma0RequestMuxFlexPwm1ReqVal2  = 53U,         /**< PWM1 value2 request */
    kDma1RequestMuxFlexPwm1ReqVal2  = 53U,         /**< PWM1 value2 request */
    kDma0RequestMuxFlexPwm1ReqVal3  = 54U,         /**< PWM0 value3 request */
    kDma1RequestMuxFlexPwm1ReqVal3  = 54U,         /**< PWM0 value3 request */
    kDma0RequestMuxLptmr0           = 57U,         /**< LPTMR0 Counter match event */
    kDma1RequestMuxLptmr0           = 57U,         /**< LPTMR0 Counter match event */
    kDma0RequestMuxLptmr1           = 58U,         /**< LPTMR1 Counter match event */
    kDma1RequestMuxLptmr1           = 58U,         /**< LPTMR1 Counter match event */
    kDma0RequestMuxFlexCan0DmaRequest = 59U,       /**< CAN0 DMA request */
    kDma1RequestMuxFlexCan0DmaRequest = 59U,       /**< CAN0 DMA request */
    kDma0RequestMuxFlexCan1DmaRequest = 60U,       /**< CAN1 DMA request */
    kDma1RequestMuxFlexCan1DmaRequest = 60U,       /**< CAN1 DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister0Request = 61U, /**< FlexIO0 Shifter0 Status DMA request OR Timer0 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister0Request = 61U, /**< FlexIO0 Shifter0 Status DMA request OR Timer0 Status DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister1Request = 62U, /**< FlexIO0 Shifter1 Status DMA request OR Timer1 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister1Request = 62U, /**< FlexIO0 Shifter1 Status DMA request OR Timer1 Status DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister2Request = 63U, /**< FlexIO0 Shifter2 Status DMA request OR Timer2 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister2Request = 63U, /**< FlexIO0 Shifter2 Status DMA request OR Timer2 Status DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister3Request = 64U, /**< FlexIO0 Shifter3 Status DMA request OR Timer3 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister3Request = 64U, /**< FlexIO0 Shifter3 Status DMA request OR Timer3 Status DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister4Request = 65U, /**< FlexIO0 Shifter4 Status DMA request OR Timer4 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister4Request = 65U, /**< FlexIO0 Shifter4 Status DMA request OR Timer4 Status DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister5Request = 66U, /**< FlexIO0 Shifter5 Status DMA request OR Timer5 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister5Request = 66U, /**< FlexIO0 Shifter5 Status DMA request OR Timer5 Status DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister6Request = 67U, /**< FlexIO0 Shifter6 Status DMA request OR Timer6 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister6Request = 67U, /**< FlexIO0 Shifter6 Status DMA request OR Timer6 Status DMA request */
    kDma0RequestMuxFlexIO0ShiftRegister7Request = 68U, /**< FlexIO0 Shifter7 Status DMA request OR Timer7 Status DMA request */
    kDma1RequestMuxFlexIO0ShiftRegister7Request = 68U, /**< FlexIO0 Shifter7 Status DMA request OR Timer7 Status DMA request */
    kDma0RequestMuxLpFlexcomm0Rx    = 69U,         /**< LP_FLEXCOMM0 Receive request */
    kDma1RequestMuxLpFlexcomm0Rx    = 69U,         /**< LP_FLEXCOMM0 Receive request */
    kDma0RequestMuxLpFlexcomm0Tx    = 70U,         /**< LP_FLEXCOMM0 Transmit request */
    kDma1RequestMuxLpFlexcomm0Tx    = 70U,         /**< LP_FLEXCOMM0 Transmit request */
    kDma0RequestMuxLpFlexcomm1Rx    = 71U,         /**< LP_FLEXCOMM1 Receive request */
    kDma1RequestMuxLpFlexcomm1Rx    = 71U,         /**< LP_FLEXCOMM1 Receive request */
    kDma0RequestMuxLpFlexcomm1Tx    = 72U,         /**< LP_FLEXCOMM1 Transmit request */
    kDma1RequestMuxLpFlexcomm1Tx    = 72U,         /**< LP_FLEXCOMM1 Transmit request */
    kDma0RequestMuxLpFlexcomm2Rx    = 73U,         /**< LP_FLEXCOMM2 Receive request */
    kDma1RequestMuxLpFlexcomm2Rx    = 73U,         /**< LP_FLEXCOMM2 Receive request */
    kDma0RequestMuxLpFlexcomm2Tx    = 74U,         /**< LP_FLEXCOMM2 Transmit request */
    kDma1RequestMuxLpFlexcomm2Tx    = 74U,         /**< LP_FLEXCOMM2 Transmit request */
    kDma0RequestMuxLpFlexcomm3Rx    = 75U,         /**< LP_FLEXCOMM3 Receive request */
    kDma1RequestMuxLpFlexcomm3Rx    = 75U,         /**< LP_FLEXCOMM3 Receive request */
    kDma0RequestMuxLpFlexcomm3Tx    = 76U,         /**< LP_FLEXCOMM3 Transmit request */
    kDma1RequestMuxLpFlexcomm3Tx    = 76U,         /**< LP_FLEXCOMM3 Transmit request */
    kDma0RequestMuxLpFlexcomm4Rx    = 77U,         /**< LP_FLEXCOMM4 Receive request */
    kDma1RequestMuxLpFlexcomm4Rx    = 77U,         /**< LP_FLEXCOMM4 Receive request */
    kDma0RequestMuxLpFlexcomm4Tx    = 78U,         /**< LP_FLEXCOMM4 Transmit request */
    kDma1RequestMuxLpFlexcomm4Tx    = 78U,         /**< LP_FLEXCOMM4 Transmit request */
    kDma0RequestMuxLpFlexcomm5Rx    = 79U,         /**< LP_FLEXCOMM5 Receive request */
    kDma1RequestMuxLpFlexcomm5Rx    = 79U,         /**< LP_FLEXCOMM5 Receive request */
    kDma0RequestMuxLpFlexcomm5Tx    = 80U,         /**< LP_FLEXCOMM5 Transmit request */
    kDma1RequestMuxLpFlexcomm5Tx    = 80U,         /**< LP_FLEXCOMM5 Transmit request */
    kDma0RequestMuxLpFlexcomm6Rx    = 81U,         /**< LP_FLEXCOMM6 Receive request */
    kDma1RequestMuxLpFlexcomm6Rx    = 81U,         /**< LP_FLEXCOMM6 Receive request */
    kDma0RequestMuxLpFlexcomm6Tx    = 82U,         /**< LP_FLEXCOMM6 Transmit request */
    kDma1RequestMuxLpFlexcomm6Tx    = 82U,         /**< LP_FLEXCOMM6 Transmit request */
    kDma0RequestMuxLpFlexcomm7Rx    = 83U,         /**< LP_FLEXCOMM7 Receive request */
    kDma1RequestMuxLpFlexcomm7Rx    = 83U,         /**< LP_FLEXCOMM7 Receive request */
    kDma0RequestMuxLpFlexcomm7Tx    = 84U,         /**< LP_FLEXCOMM7 Transmit request */
    kDma1RequestMuxLpFlexcomm7Tx    = 84U,         /**< LP_FLEXCOMM7 Transmit request */
    kDma0RequestMuxLpFlexcomm8Rx    = 85U,         /**< LP_FLEXCOMM8 Receive request */
    kDma1RequestMuxLpFlexcomm8Rx    = 85U,         /**< LP_FLEXCOMM8 Receive request */
    kDma0RequestMuxLpFlexcomm8Tx    = 86U,         /**< LP_FLEXCOMM8 Transmit request */
    kDma1RequestMuxLpFlexcomm8Tx    = 86U,         /**< LP_FLEXCOMM8 Transmit request */
    kDma0RequestMuxLpFlexcomm9Rx    = 87U,         /**< LP_FLEXCOMM9 Receive request */
    kDma1RequestMuxLpFlexcomm9Rx    = 87U,         /**< LP_FLEXCOMM9 Receive request */
    kDma0RequestMuxLpFlexcomm9Tx    = 88U,         /**< LP_FLEXCOMM9 Transmit request */
    kDma1RequestMuxLpFlexcomm9Tx    = 88U,         /**< LP_FLEXCOMM9 Transmit request */
    kDma0RequestMuxEmvSim0Rx        = 91U,         /**< EMVSIM0 Receive request */
    kDma1RequestMuxEmvSim0Rx        = 91U,         /**< EMVSIM0 Receive request */
    kDma0RequestMuxEmvSim0Tx        = 92U,         /**< EMVSIM0 Transmit request */
    kDma1RequestMuxEmvSim0Tx        = 92U,         /**< EMVSIM0 Transmit request */
    kDma0RequestMuxEmvSim1Rx        = 93U,         /**< EMVSIM1 Receive request */
    kDma1RequestMuxEmvSim1Rx        = 93U,         /**< EMVSIM1 Receive request */
    kDma0RequestMuxEmvSim1Tx        = 94U,         /**< EMVSIM1 Transmit request */
    kDma1RequestMuxEmvSim1Tx        = 94U,         /**< EMVSIM1 Transmit request */
    kDma0RequestMuxI3c0Rx           = 95U,         /**< I3C0 Receive request */
    kDma1RequestMuxI3c0Rx           = 95U,         /**< I3C0 Receive request */
    kDma0RequestMuxI3c0Tx           = 96U,         /**< I3C0 Transmit request */
    kDma1RequestMuxI3c0Tx           = 96U,         /**< I3C0 Transmit request */
    kDma0RequestMuxI3c1Rx           = 97U,         /**< I3C1 Receive request */
    kDma1RequestMuxI3c1Rx           = 97U,         /**< I3C1 Receive request */
    kDma0RequestMuxI3c1Tx           = 98U,         /**< I3C1 Transmit request */
    kDma1RequestMuxI3c1Tx           = 98U,         /**< I3C1 Transmit request */
    kDma0RequestMuxSai0Rx           = 99U,         /**< SAI0 Receive request */
    kDma1RequestMuxSai0Rx           = 99U,         /**< SAI0 Receive request */
    kDma0RequestMuxSai0Tx           = 100U,        /**< SAI0 Transmit request */
    kDma1RequestMuxSai0Tx           = 100U,        /**< SAI0 Transmit request */
    kDma0RequestMuxSai1Rx           = 101U,        /**< SAI1 Receive request */
    kDma1RequestMuxSai1Rx           = 101U,        /**< SAI1 Receive request */
    kDma0RequestMuxSai1Tx           = 102U,        /**< SAI1 Transmit request */
    kDma1RequestMuxSai1Tx           = 102U,        /**< SAI1 Transmit request */
    kDma0RequestMuxSinc0IpdReqSincAlt0 = 103U,     /**< SINC0 ipd_req_sinc[0] or ipd_req_alt [0] */
    kDma1RequestMuxSinc0IpdReqSincAlt0 = 103U,     /**< SINC0 ipd_req_sinc[0] or ipd_req_alt [0] */
    kDma0RequestMuxSinc1IpdReqSincAlt1 = 104U,     /**< SINC0 ipd_req_sinc[1] or ipd_req_alt [1] */
    kDma1RequestMuxSinc1IpdReqSincAlt1 = 104U,     /**< SINC0 ipd_req_sinc[1] or ipd_req_alt [1] */
    kDma0RequestMuxSinc2IpdReqSincAlt2 = 105U,     /**< SINC0 ipd_req_sinc[2] or ipd_req_alt [2] */
    kDma1RequestMuxSinc2IpdReqSincAlt2 = 105U,     /**< SINC0 ipd_req_sinc[2] or ipd_req_alt [2] */
    kDma0RequestMuxSinc3IpdReqSincAlt3 = 106U,     /**< SINC0 ipd_req_sinc[3] or ipd_req_alt [3] */
    kDma1RequestMuxSinc3IpdReqSincAlt3 = 106U,     /**< SINC0 ipd_req_sinc[3] or ipd_req_alt [3] */
    kDma0RequestMuxSinc4IpdReqSincAlt4 = 107U,     /**< SINC0 ipd_req_sinc[4] or ipd_req_alt [4] */
    kDma1RequestMuxSinc4IpdReqSincAlt4 = 107U,     /**< SINC0 ipd_req_sinc[4] or ipd_req_alt [4] */
    kDma0RequestMuxGpio0PinEventRequest0 = 108U,   /**< GPIO0 Pin event request 0 */
    kDma1RequestMuxGpio0PinEventRequest0 = 108U,   /**< GPIO0 Pin event request 0 */
    kDma0RequestMuxGpio0PinEventRequest1 = 109U,   /**< GPIO0 Pin event request 1 */
    kDma1RequestMuxGpio0PinEventRequest1 = 109U,   /**< GPIO0 Pin event request 1 */
    kDma0RequestMuxGpio1PinEventRequest0 = 110U,   /**< GPIO1 Pin event request 0 */
    kDma1RequestMuxGpio1PinEventRequest0 = 110U,   /**< GPIO1 Pin event request 0 */
    kDma0RequestMuxGpio1PinEventRequest1 = 111U,   /**< GPIO1 Pin event request 1 */
    kDma1RequestMuxGpio1PinEventRequest1 = 111U,   /**< GPIO1 Pin event request 1 */
    kDma0RequestMuxGpio2PinEventRequest0 = 112U,   /**< GPIO2 Pin event request 0 */
    kDma1RequestMuxGpio2PinEventRequest0 = 112U,   /**< GPIO2 Pin event request 0 */
    kDma0RequestMuxGpio2PinEventRequest1 = 113U,   /**< GPIO2 Pin event request 1 */
    kDma1RequestMuxGpio2PinEventRequest1 = 113U,   /**< GPIO2 Pin event request 1 */
    kDma0RequestMuxGpio3PinEventRequest0 = 114U,   /**< GPIO3 Pin event request 0 */
    kDma1RequestMuxGpio3PinEventRequest0 = 114U,   /**< GPIO3 Pin event request 0 */
    kDma0RequestMuxGpio3PinEventRequest1 = 115U,   /**< GPIO3 Pin event request 1 */
    kDma1RequestMuxGpio3PinEventRequest1 = 115U,   /**< GPIO3 Pin event request 1 */
    kDma0RequestMuxGpio4PinEventRequest0 = 116U,   /**< GPIO4 Pin event request 0 */
    kDma1RequestMuxGpio4PinEventRequest0 = 116U,   /**< GPIO4 Pin event request 0 */
    kDma0RequestMuxGpio4PinEventRequest1 = 117U,   /**< GPIO4 Pin event request 1 */
    kDma1RequestMuxGpio4PinEventRequest1 = 117U,   /**< GPIO4 Pin event request 1 */
    kDma0RequestMuxGpio5PinEventRequest0 = 118U,   /**< GPIO5 Pin event request 0 */
    kDma1RequestMuxGpio5PinEventRequest0 = 118U,   /**< GPIO5 Pin event request 0 */
    kDma0RequestMuxGpio5PinEventRequest1 = 119U,   /**< GPIO5 Pin event request 1 */
    kDma1RequestMuxGpio5PinEventRequest1 = 119U,   /**< GPIO5 Pin event request 1 */
    kDma0RequestMuxHsCmp2DmaRequest = 30U,         /**< CMP2 DMA_request */
    kDma1RequestMuxHsCmp2DmaRequest = 30U,         /**< CMP2 DMA_request */
    kDma0RequestMuxTsi0EndOfScan    = 120U,        /**< TSI0 End of Scan */
    kDma1RequestMuxTsi0EndOfScan    = 120U,        /**< TSI0 End of Scan */
    kDma0RequestMuxTsi0OutOfRange   = 121U,        /**< TSI0 Out of Range */
    kDma1RequestMuxTsi0OutOfRange   = 121U,        /**< TSI0 Out of Range */
} dma_request_source_t;

/* @} */
#endif /* DMA_REQUEST_SOURCE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_MP_GRPRI_COUNT                        16u
#define DMA_CH_COUNT                              16u

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT;                            /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t MP_HRS;                            /**< Management Page Hardware Request Status, offset: 0xC */
       uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[DMA_MP_GRPRI_COUNT];      /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[3776];
  struct {                                         /* offset: 0x1000, array step: 0x1000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x1000, array step: 0x1000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x1004, array step: 0x1000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x1008, array step: 0x1000 */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0x100C, array step: 0x1000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x1010, array step: 0x1000 */
    __IO uint32_t CH_MUX;                            /**< Channel Multiplexor Configuration, array offset: 0x1014, array step: 0x1000 */
         uint8_t RESERVED_0[8];
    __IO uint32_t TCD_SADDR;                         /**< TCD Source Address, array offset: 0x1020, array step: 0x1000 */
    __IO uint16_t TCD_SOFF;                          /**< TCD Signed Source Address Offset, array offset: 0x1024, array step: 0x1000 */
    __IO uint16_t TCD_ATTR;                          /**< TCD Transfer Attributes, array offset: 0x1026, array step: 0x1000 */
    union {                                          /* offset: 0x1028, array step: 0x1000 */
      __IO uint32_t TCD_NBYTES_MLOFFNO;                /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x1028, array step: 0x1000 */
      __IO uint32_t TCD_NBYTES_MLOFFYES;               /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x1028, array step: 0x1000 */
    };
    __IO uint32_t TCD_SLAST_SDA;                     /**< TCD Last Source Address Adjustment / Store DADDR Address, array offset: 0x102C, array step: 0x1000 */
    __IO uint32_t TCD_DADDR;                         /**< TCD Destination Address, array offset: 0x1030, array step: 0x1000 */
    __IO uint16_t TCD_DOFF;                          /**< TCD Signed Destination Address Offset, array offset: 0x1034, array step: 0x1000 */
    union {                                          /* offset: 0x1036, array step: 0x1000 */
      __IO uint16_t TCD_CITER_ELINKNO;                 /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x1036, array step: 0x1000 */
      __IO uint16_t TCD_CITER_ELINKYES;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x1036, array step: 0x1000 */
    };
    __IO uint32_t TCD_DLAST_SGA;                     /**< TCD Last Destination Address Adjustment / Scatter Gather Address, array offset: 0x1038, array step: 0x1000 */
    __IO uint16_t TCD_CSR;                           /**< TCD Control and Status, array offset: 0x103C, array step: 0x1000 */
    union {                                          /* offset: 0x103E, array step: 0x1000 */
      __IO uint16_t TCD_BITER_ELINKNO;                 /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x103E, array step: 0x1000 */
      __IO uint16_t TCD_BITER_ELINKYES;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x103E, array step: 0x1000 */
    };
         uint8_t RESERVED_1[4032];
  } CH[DMA_CH_COUNT];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define DMA_MP_CSR_EDBG_MASK                     (0x2U)
#define DMA_MP_CSR_EDBG_SHIFT                    (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode disabled
 *  0b1..Debug mode is enabled.
 */
#define DMA_MP_CSR_EDBG(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_EDBG_SHIFT)) & DMA_MP_CSR_EDBG_MASK)

#define DMA_MP_CSR_ERCA_MASK                     (0x4U)
#define DMA_MP_CSR_ERCA_SHIFT                    (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round-robin channel arbitration disabled
 *  0b1..Round-robin channel arbitration enabled
 */
#define DMA_MP_CSR_ERCA(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ERCA_SHIFT)) & DMA_MP_CSR_ERCA_MASK)

#define DMA_MP_CSR_HAE_MASK                      (0x10U)
#define DMA_MP_CSR_HAE_SHIFT                     (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT field to be set to 1
 */
#define DMA_MP_CSR_HAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HAE_SHIFT)) & DMA_MP_CSR_HAE_MASK)

#define DMA_MP_CSR_HALT_MASK                     (0x20U)
#define DMA_MP_CSR_HALT_SHIFT                    (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels
 */
#define DMA_MP_CSR_HALT(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HALT_SHIFT)) & DMA_MP_CSR_HALT_MASK)

#define DMA_MP_CSR_GCLC_MASK                     (0x40U)
#define DMA_MP_CSR_GCLC_SHIFT                    (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking disabled for all channels
 *  0b1..Channel linking available and controlled by each channel's link settings
 */
#define DMA_MP_CSR_GCLC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GCLC_SHIFT)) & DMA_MP_CSR_GCLC_MASK)

#define DMA_MP_CSR_GMRC_MASK                     (0x80U)
#define DMA_MP_CSR_GMRC_SHIFT                    (7U)
/*! GMRC - Global Master ID Replication Control
 *  0b0..Master ID replication disabled for all channels
 *  0b1..Master ID replication available and controlled by each channel's CHn_SBR[EMI] setting
 */
#define DMA_MP_CSR_GMRC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GMRC_SHIFT)) & DMA_MP_CSR_GMRC_MASK)

#define DMA_MP_CSR_ECX_MASK                      (0x100U)
#define DMA_MP_CSR_ECX_SHIFT                     (8U)
/*! ECX - Cancel Transfer With Error
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_ECX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ECX_SHIFT)) & DMA_MP_CSR_ECX_MASK)

#define DMA_MP_CSR_CX_MASK                       (0x200U)
#define DMA_MP_CSR_CX_SHIFT                      (9U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_CX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_CX_SHIFT)) & DMA_MP_CSR_CX_MASK)

#define DMA_MP_CSR_ACTIVE_ID_MASK                (0xF000000U)
#define DMA_MP_CSR_ACTIVE_ID_SHIFT               (24U)
/*! ACTIVE_ID - Active Channel ID */
#define DMA_MP_CSR_ACTIVE_ID(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_ID_SHIFT)) & DMA_MP_CSR_ACTIVE_ID_MASK)

#define DMA_MP_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_MP_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle
 *  0b1..eDMA is executing a channel
 */
#define DMA_MP_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_SHIFT)) & DMA_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA_MP_ES_DBE_MASK                       (0x1U)
#define DMA_MP_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was a bus error on a destination write
 */
#define DMA_MP_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DBE_SHIFT)) & DMA_MP_ES_DBE_MASK)

#define DMA_MP_ES_SBE_MASK                       (0x2U)
#define DMA_MP_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was a bus error on a source read
 */
#define DMA_MP_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SBE_SHIFT)) & DMA_MP_ES_SBE_MASK)

#define DMA_MP_ES_SGE_MASK                       (0x4U)
#define DMA_MP_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_MP_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SGE_SHIFT)) & DMA_MP_ES_SGE_MASK)

#define DMA_MP_ES_NCE_MASK                       (0x8U)
#define DMA_MP_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA_MP_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_NCE_SHIFT)) & DMA_MP_ES_NCE_MASK)

#define DMA_MP_ES_DOE_MASK                       (0x10U)
#define DMA_MP_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_MP_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DOE_SHIFT)) & DMA_MP_ES_DOE_MASK)

#define DMA_MP_ES_DAE_MASK                       (0x20U)
#define DMA_MP_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_MP_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DAE_SHIFT)) & DMA_MP_ES_DAE_MASK)

#define DMA_MP_ES_SOE_MASK                       (0x40U)
#define DMA_MP_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_MP_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SOE_SHIFT)) & DMA_MP_ES_SOE_MASK)

#define DMA_MP_ES_SAE_MASK                       (0x80U)
#define DMA_MP_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_MP_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SAE_SHIFT)) & DMA_MP_ES_SAE_MASK)

#define DMA_MP_ES_ECX_MASK                       (0x100U)
#define DMA_MP_ES_ECX_SHIFT                      (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Last recorded entry was a canceled transfer by the error cancel transfer input
 */
#define DMA_MP_ES_ECX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ECX_SHIFT)) & DMA_MP_ES_ECX_MASK)

#define DMA_MP_ES_ERRCHN_MASK                    (0xF000000U)
#define DMA_MP_ES_ERRCHN_SHIFT                   (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA_MP_ES_ERRCHN(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ERRCHN_SHIFT)) & DMA_MP_ES_ERRCHN_MASK)

#define DMA_MP_ES_VLD_MASK                       (0x80000000U)
#define DMA_MP_ES_VLD_SHIFT                      (31U)
/*! VLD - Valid
 *  0b0..No CHn_ES[ERR] fields are set to 1
 *  0b1..At least one CHn_ES[ERR] field is set to 1, indicating a valid error exists that software has not cleared
 */
#define DMA_MP_ES_VLD(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_VLD_SHIFT)) & DMA_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_MP_INT_INT_MASK                      (0xFFFFU)
#define DMA_MP_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request Status */
#define DMA_MP_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_INT_INT_SHIFT)) & DMA_MP_INT_INT_MASK)
/*! @} */

/*! @name MP_HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_MP_HRS_HRS_MASK                      (0xFFFFFFFFU)
#define DMA_MP_HRS_HRS_SHIFT                     (0U)
/*! HRS - Hardware Request Status */
#define DMA_MP_HRS_HRS(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_HRS_HRS_SHIFT)) & DMA_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_CH_GRPRI_GRPRI_MASK                  (0x1FU)
#define DMA_CH_GRPRI_GRPRI_SHIFT                 (0U)
/*! GRPRI - Arbitration Group For Channel n */
#define DMA_CH_GRPRI_GRPRI(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CH_GRPRI_GRPRI_SHIFT)) & DMA_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA_CH_GRPRI */
#define DMA_CH_GRPRI_COUNT                       (16U)

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH_CSR_ERQ_MASK                      (0x1U)
#define DMA_CH_CSR_ERQ_SHIFT                     (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH_CSR_ERQ(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ERQ_SHIFT)) & DMA_CH_CSR_ERQ_MASK)

#define DMA_CH_CSR_EARQ_MASK                     (0x2U)
#define DMA_CH_CSR_EARQ_SHIFT                    (1U)
/*! EARQ - Enable Asynchronous DMA Request
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH_CSR_EARQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EARQ_SHIFT)) & DMA_CH_CSR_EARQ_MASK)

#define DMA_CH_CSR_EEI_MASK                      (0x4U)
#define DMA_CH_CSR_EEI_SHIFT                     (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH_CSR_EEI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EEI_SHIFT)) & DMA_CH_CSR_EEI_MASK)

#define DMA_CH_CSR_EBW_MASK                      (0x8U)
#define DMA_CH_CSR_EBW_SHIFT                     (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH_CSR_EBW(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EBW_SHIFT)) & DMA_CH_CSR_EBW_MASK)

#define DMA_CH_CSR_DONE_MASK                     (0x40000000U)
#define DMA_CH_CSR_DONE_SHIFT                    (30U)
/*! DONE - Channel Done */
#define DMA_CH_CSR_DONE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_DONE_SHIFT)) & DMA_CH_CSR_DONE_MASK)

#define DMA_CH_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_CH_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ACTIVE_SHIFT)) & DMA_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA_CH_CSR */
#define DMA_CH_CSR_COUNT                         (16U)

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA_CH_ES_DBE_MASK                       (0x1U)
#define DMA_CH_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DBE_SHIFT)) & DMA_CH_ES_DBE_MASK)

#define DMA_CH_ES_SBE_MASK                       (0x2U)
#define DMA_CH_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SBE_SHIFT)) & DMA_CH_ES_SBE_MASK)

#define DMA_CH_ES_SGE_MASK                       (0x4U)
#define DMA_CH_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SGE_SHIFT)) & DMA_CH_ES_SGE_MASK)

#define DMA_CH_ES_NCE_MASK                       (0x8U)
#define DMA_CH_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_NCE_SHIFT)) & DMA_CH_ES_NCE_MASK)

#define DMA_CH_ES_DOE_MASK                       (0x10U)
#define DMA_CH_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DOE_SHIFT)) & DMA_CH_ES_DOE_MASK)

#define DMA_CH_ES_DAE_MASK                       (0x20U)
#define DMA_CH_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DAE_SHIFT)) & DMA_CH_ES_DAE_MASK)

#define DMA_CH_ES_SOE_MASK                       (0x40U)
#define DMA_CH_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SOE_SHIFT)) & DMA_CH_ES_SOE_MASK)

#define DMA_CH_ES_SAE_MASK                       (0x80U)
#define DMA_CH_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SAE_SHIFT)) & DMA_CH_ES_SAE_MASK)

#define DMA_CH_ES_ERR_MASK                       (0x80000000U)
#define DMA_CH_ES_ERR_SHIFT                      (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH_ES_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_ERR_SHIFT)) & DMA_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA_CH_ES */
#define DMA_CH_ES_COUNT                          (16U)

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH_INT_INT_MASK                      (0x1U)
#define DMA_CH_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_INT_INT_SHIFT)) & DMA_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA_CH_INT */
#define DMA_CH_INT_COUNT                         (16U)

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH_SBR_MID_MASK                      (0x1FU)
#define DMA_CH_SBR_MID_SHIFT                     (0U)
/*! MID - Master ID */
#define DMA_CH_SBR_MID(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_MID_SHIFT)) & DMA_CH_SBR_MID_MASK)

#define DMA_CH_SBR_SEC_MASK                      (0x4000U)
#define DMA_CH_SBR_SEC_SHIFT                     (14U)
/*! SEC - Security Level
 *  0b0..Nonsecure protection level for DMA transfers
 *  0b1..Secure protection level for DMA transfers
 */
#define DMA_CH_SBR_SEC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_SEC_SHIFT)) & DMA_CH_SBR_SEC_MASK)

#define DMA_CH_SBR_PAL_MASK                      (0x8000U)
#define DMA_CH_SBR_PAL_SHIFT                     (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH_SBR_PAL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_PAL_SHIFT)) & DMA_CH_SBR_PAL_MASK)

#define DMA_CH_SBR_EMI_MASK                      (0x10000U)
#define DMA_CH_SBR_EMI_SHIFT                     (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH_SBR_EMI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_EMI_SHIFT)) & DMA_CH_SBR_EMI_MASK)
/*! @} */

/* The count of DMA_CH_SBR */
#define DMA_CH_SBR_COUNT                         (16U)

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA_CH_PRI_APL_MASK                      (0x7U)
#define DMA_CH_PRI_APL_SHIFT                     (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH_PRI_APL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_APL_SHIFT)) & DMA_CH_PRI_APL_MASK)

#define DMA_CH_PRI_DPA_MASK                      (0x40000000U)
#define DMA_CH_PRI_DPA_SHIFT                     (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH_PRI_DPA(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_DPA_SHIFT)) & DMA_CH_PRI_DPA_MASK)

#define DMA_CH_PRI_ECP_MASK                      (0x80000000U)
#define DMA_CH_PRI_ECP_SHIFT                     (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH_PRI_ECP(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_ECP_SHIFT)) & DMA_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA_CH_PRI */
#define DMA_CH_PRI_COUNT                         (16U)

/*! @name CH_MUX - Channel Multiplexor Configuration */
/*! @{ */

#define DMA_CH_MUX_SRC_MASK                      (0x7FU)
#define DMA_CH_MUX_SRC_SHIFT                     (0U)
/*! SRC - Service Request Source */
#define DMA_CH_MUX_SRC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_MUX_SRC_SHIFT)) & DMA_CH_MUX_SRC_MASK)
/*! @} */

/* The count of DMA_CH_MUX */
#define DMA_CH_MUX_COUNT                         (16U)

/*! @name TCD_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD_SADDR_SADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_SADDR_SADDR_SHIFT                (0U)
/*! SADDR - Source Address */
#define DMA_TCD_SADDR_SADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SADDR_SADDR_SHIFT)) & DMA_TCD_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA_TCD_SADDR */
#define DMA_TCD_SADDR_COUNT                      (16U)

/*! @name TCD_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD_SOFF_SOFF_MASK                   (0xFFFFU)
#define DMA_TCD_SOFF_SOFF_SHIFT                  (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD_SOFF_SOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_SOFF_SOFF_SHIFT)) & DMA_TCD_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA_TCD_SOFF */
#define DMA_TCD_SOFF_COUNT                       (16U)

/*! @name TCD_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD_ATTR_DSIZE_MASK                  (0x7U)
#define DMA_TCD_ATTR_DSIZE_SHIFT                 (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD_ATTR_DSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DSIZE_SHIFT)) & DMA_TCD_ATTR_DSIZE_MASK)

#define DMA_TCD_ATTR_DMOD_MASK                   (0xF8U)
#define DMA_TCD_ATTR_DMOD_SHIFT                  (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD_ATTR_DMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DMOD_SHIFT)) & DMA_TCD_ATTR_DMOD_MASK)

#define DMA_TCD_ATTR_SSIZE_MASK                  (0x700U)
#define DMA_TCD_ATTR_SSIZE_SHIFT                 (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..
 *  0b111..
 */
#define DMA_TCD_ATTR_SSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SSIZE_SHIFT)) & DMA_TCD_ATTR_SSIZE_MASK)

#define DMA_TCD_ATTR_SMOD_MASK                   (0xF800U)
#define DMA_TCD_ATTR_SMOD_SHIFT                  (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD_ATTR_SMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SMOD_SHIFT)) & DMA_TCD_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA_TCD_ATTR */
#define DMA_TCD_ATTR_COUNT                       (16U)

/*! @name TCD_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK       (0x3FFFFFFFU)
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT      (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK        (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT       (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK        (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT       (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFNO */
#define DMA_TCD_NBYTES_MLOFFNO_COUNT             (16U)

/*! @name TCD_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK      (0x3FFU)
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT     (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK       (0x3FFFFC00U)
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT      (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK       (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT      (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK       (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT      (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFYES */
#define DMA_TCD_NBYTES_MLOFFYES_COUNT            (16U)

/*! @name TCD_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD_SLAST_SDA_SLAST_SDA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT        (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD_SLAST_SDA_SLAST_SDA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA_TCD_SLAST_SDA */
#define DMA_TCD_SLAST_SDA_COUNT                  (16U)

/*! @name TCD_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD_DADDR_DADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_DADDR_DADDR_SHIFT                (0U)
/*! DADDR - Destination Address */
#define DMA_TCD_DADDR_DADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DADDR_DADDR_SHIFT)) & DMA_TCD_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA_TCD_DADDR */
#define DMA_TCD_DADDR_COUNT                      (16U)

/*! @name TCD_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD_DOFF_DOFF_MASK                   (0xFFFFU)
#define DMA_TCD_DOFF_DOFF_SHIFT                  (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD_DOFF_DOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_DOFF_DOFF_SHIFT)) & DMA_TCD_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA_TCD_DOFF */
#define DMA_TCD_DOFF_COUNT                       (16U)

/*! @name TCD_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKNO_CITER_MASK         (0x7FFFU)
#define DMA_TCD_CITER_ELINKNO_CITER_SHIFT        (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKNO_CITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD_CITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_CITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKNO */
#define DMA_TCD_CITER_ELINKNO_COUNT              (16U)

/*! @name TCD_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKYES_CITER_MASK        (0x1FFU)
#define DMA_TCD_CITER_ELINKYES_CITER_SHIFT       (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKYES_CITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD_CITER_ELINKYES_LINKCH_MASK       (0x1E00U)
#define DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_CITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_CITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKYES */
#define DMA_TCD_CITER_ELINKYES_COUNT             (16U)

/*! @name TCD_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD_DLAST_SGA_DLAST_SGA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT        (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD_DLAST_SGA_DLAST_SGA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA_TCD_DLAST_SGA */
#define DMA_TCD_DLAST_SGA_COUNT                  (16U)

/*! @name TCD_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD_CSR_START_MASK                   (0x1U)
#define DMA_TCD_CSR_START_SHIFT                  (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD_CSR_START(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_START_SHIFT)) & DMA_TCD_CSR_START_MASK)

#define DMA_TCD_CSR_INTMAJOR_MASK                (0x2U)
#define DMA_TCD_CSR_INTMAJOR_SHIFT               (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD_CSR_INTMAJOR(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTMAJOR_SHIFT)) & DMA_TCD_CSR_INTMAJOR_MASK)

#define DMA_TCD_CSR_INTHALF_MASK                 (0x4U)
#define DMA_TCD_CSR_INTHALF_SHIFT                (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD_CSR_INTHALF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTHALF_SHIFT)) & DMA_TCD_CSR_INTHALF_MASK)

#define DMA_TCD_CSR_DREQ_MASK                    (0x8U)
#define DMA_TCD_CSR_DREQ_SHIFT                   (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD_CSR_DREQ(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_DREQ_SHIFT)) & DMA_TCD_CSR_DREQ_MASK)

#define DMA_TCD_CSR_ESG_MASK                     (0x10U)
#define DMA_TCD_CSR_ESG_SHIFT                    (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD_CSR_ESG(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESG_SHIFT)) & DMA_TCD_CSR_ESG_MASK)

#define DMA_TCD_CSR_MAJORELINK_MASK              (0x20U)
#define DMA_TCD_CSR_MAJORELINK_SHIFT             (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CSR_MAJORELINK(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORELINK_SHIFT)) & DMA_TCD_CSR_MAJORELINK_MASK)

#define DMA_TCD_CSR_EEOP_MASK                    (0x40U)
#define DMA_TCD_CSR_EEOP_SHIFT                   (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD_CSR_EEOP(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_EEOP_SHIFT)) & DMA_TCD_CSR_EEOP_MASK)

#define DMA_TCD_CSR_ESDA_MASK                    (0x80U)
#define DMA_TCD_CSR_ESDA_SHIFT                   (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD_CSR_ESDA(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESDA_SHIFT)) & DMA_TCD_CSR_ESDA_MASK)

#define DMA_TCD_CSR_MAJORLINKCH_MASK             (0xF00U)
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT            (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD_CSR_MAJORLINKCH(x)               (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD_CSR_MAJORLINKCH_MASK)

#define DMA_TCD_CSR_BWC_MASK                     (0xC000U)
#define DMA_TCD_CSR_BWC_SHIFT                    (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD_CSR_BWC(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_BWC_SHIFT)) & DMA_TCD_CSR_BWC_MASK)
/*! @} */

/* The count of DMA_TCD_CSR */
#define DMA_TCD_CSR_COUNT                        (16U)

/*! @name TCD_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKNO_BITER_MASK         (0x7FFFU)
#define DMA_TCD_BITER_ELINKNO_BITER_SHIFT        (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKNO_BITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD_BITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_BITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKNO */
#define DMA_TCD_BITER_ELINKNO_COUNT              (16U)

/*! @name TCD_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKYES_BITER_MASK        (0x1FFU)
#define DMA_TCD_BITER_ELINKYES_BITER_SHIFT       (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKYES_BITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD_BITER_ELINKYES_LINKCH_MASK       (0x1E00U)
#define DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_BITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_BITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKYES */
#define DMA_TCD_BITER_ELINKYES_COUNT             (16U)


/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA_H_ */

